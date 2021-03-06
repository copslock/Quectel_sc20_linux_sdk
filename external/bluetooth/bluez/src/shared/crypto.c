/*
 *
 *  BlueZ - Bluetooth protocol stack for Linux
 *
 *  Copyright (C) 2012-2014  Intel Corporation. All rights reserved.
 *
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>

#include "src/shared/util.h"
#include "src/shared/crypto.h"

#ifndef PF_ALG
#include <linux/types.h>

struct sockaddr_alg {
	__u16   salg_family;
	__u8    salg_type[14];
	__u32   salg_feat;
	__u32   salg_mask;
	__u8    salg_name[64];
};

struct af_alg_iv {
	__u32   ivlen;
	__u8    iv[0];
};

#define ALG_SET_KEY                     1
#define ALG_SET_IV                      2
#define ALG_SET_OP                      3

#define ALG_OP_DECRYPT                  0
#define ALG_OP_ENCRYPT                  1

#define PF_ALG		38	/* Algorithm sockets.  */
#define AF_ALG		PF_ALG
#else
#include <linux/if_alg.h>
#endif

#ifndef SOL_ALG
#define SOL_ALG		279
#endif

struct bt_crypto {
	int ref_count;
	int ecb_aes;
	int urandom;
};

static int urandom_setup(void)
{
	int fd;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		return -1;

	return fd;
}

static int ecb_aes_setup(void)
{
	struct sockaddr_alg salg;
	int fd;

	fd = socket(PF_ALG, SOCK_SEQPACKET | SOCK_CLOEXEC, 0);
	if (fd < 0)
		return -1;

	memset(&salg, 0, sizeof(salg));
	salg.salg_family = AF_ALG;
	strcpy((char *) salg.salg_type, "skcipher");
	strcpy((char *) salg.salg_name, "ecb(aes)");

	if (bind(fd, (struct sockaddr *) &salg, sizeof(salg)) < 0) {
		close(fd);
		return -1;
	}

	return fd;
}

struct bt_crypto *bt_crypto_new(void)
{
	struct bt_crypto *crypto;

	crypto = new0(struct bt_crypto, 1);
	if (!crypto)
		return NULL;

	crypto->ecb_aes = ecb_aes_setup();
	if (crypto->ecb_aes < 0) {
		free(crypto);
		return NULL;
	}

	crypto->urandom = urandom_setup();
	if (crypto->urandom < 0) {
		close(crypto->ecb_aes);
		free(crypto);
		return NULL;
	}

	return bt_crypto_ref(crypto);
}

struct bt_crypto *bt_crypto_ref(struct bt_crypto *crypto)
{
	if (!crypto)
		return NULL;

	__sync_fetch_and_add(&crypto->ref_count, 1);

	return crypto;
}

void bt_crypto_unref(struct bt_crypto *crypto)
{
	if (!crypto)
		return;

	if (__sync_sub_and_fetch(&crypto->ref_count, 1))
		return;

	close(crypto->urandom);
	close(crypto->ecb_aes);

	free(crypto);
}

bool bt_crypto_random_bytes(struct bt_crypto *crypto,
					uint8_t *buf, uint8_t num_bytes)
{
	ssize_t len;

	if (!crypto)
		return false;

	len = read(crypto->urandom, buf, num_bytes);
	if (len < num_bytes)
		return false;

	return true;
}

static int alg_new(int fd, const void *keyval, socklen_t keylen)
{
	if (setsockopt(fd, SOL_ALG, ALG_SET_KEY, keyval, keylen) < 0)
		return -1;

	/* FIXME: This should use accept4() with SOCK_CLOEXEC */
	return accept(fd, NULL, 0);
}

static bool alg_encrypt(int fd, const void *inbuf, size_t inlen,
						void *outbuf, size_t outlen)
{
	__u32 alg_op = ALG_OP_ENCRYPT;
	char cbuf[CMSG_SPACE(sizeof(alg_op))];
	struct cmsghdr *cmsg;
	struct msghdr msg;
	struct iovec iov;
	ssize_t len;

	memset(cbuf, 0, sizeof(cbuf));
	memset(&msg, 0, sizeof(msg));

	msg.msg_control = cbuf;
	msg.msg_controllen = sizeof(cbuf);

	cmsg = CMSG_FIRSTHDR(&msg);
	cmsg->cmsg_level = SOL_ALG;
	cmsg->cmsg_type = ALG_SET_OP;
	cmsg->cmsg_len = CMSG_LEN(sizeof(alg_op));
	memcpy(CMSG_DATA(cmsg), &alg_op, sizeof(alg_op));

	iov.iov_base = (void *) inbuf;
	iov.iov_len = inlen;

	msg.msg_iov = &iov;
	msg.msg_iovlen = 1;

	len = sendmsg(fd, &msg, 0);
	if (len < 0)
		return false;

	len = read(fd, outbuf, outlen);
	if (len < 0)
		return false;

	return true;
}

static inline void swap128(const uint8_t src[16], uint8_t dst[16])
{
	int i;

	for (i = 0; i < 16; i++)
		dst[15 - i] = src[i];
}

/*
 * Security function e
 *
 * Security function e generates 128-bit encryptedData from a 128-bit key
 * and 128-bit plaintextData using the AES-128-bit block cypher:
 *
 *   encryptedData = e(key, plaintextData)
 *
 * The most significant octet of key corresponds to key[0], the most
 * significant octet of plaintextData corresponds to in[0] and the
 * most significant octet of encryptedData corresponds to out[0].
 *
 */
bool bt_crypto_e(struct bt_crypto *crypto, const uint8_t key[16],
			const uint8_t plaintext[16], uint8_t encrypted[16])
{
	uint8_t tmp[16], in[16], out[16];
	int fd;

	if (!crypto)
		return false;

	/* The most significant octet of key corresponds to key[0] */
	swap128(key, tmp);

	fd = alg_new(crypto->ecb_aes, tmp, 16);
	if (fd < 0)
		return false;


	/* Most significant octet of plaintextData corresponds to in[0] */
	swap128(plaintext, in);

	if (!alg_encrypt(fd, in, 16, out, 16)) {
		close(fd);
		return false;
	}

	/* Most significant octet of encryptedData corresponds to out[0] */
	swap128(out, encrypted);

	close(fd);

	return true;
}

/*
 * Random Address Hash function ah
 *
 * The random address hash function ah is used to generate a hash value
 * that is used in resolvable private addresses.
 *
 * The following are inputs to the random address hash function ah:
 *
 *   k is 128 bits
 *   r is 24 bits
 *   padding is 104 bits
 *
 * r is concatenated with padding to generate r' which is used as the
 * 128-bit input parameter plaintextData to security function e:
 *
 *   r' = padding || r
 *
 * The least significant octet of r becomes the least significant octet
 * of r??? and the most significant octet of padding becomes the most
 * significant octet of r'.
 *
 * For example, if the 24-bit value r is 0x423456 then r' is
 * 0x00000000000000000000000000423456.
 *
 * The output of the random address function ah is:
 *
 *   ah(k, r) = e(k, r') mod 2^24
 *
 * The output of the security function e is then truncated to 24 bits by
 * taking the least significant 24 bits of the output of e as the result
 * of ah.
 */
bool bt_crypto_ah(struct bt_crypto *crypto, const uint8_t k[16],
					const uint8_t r[3], uint8_t hash[3])
{
	uint8_t rp[16];
	uint8_t encrypted[16];

	if (!crypto)
		return false;

	/* r' = padding || r */
	memcpy(rp, r, 3);
	memset(rp + 3, 0, 13);

	/* e(k, r') */
	if (!bt_crypto_e(crypto, k, rp, encrypted))
		return false;

	/* ah(k, r) = e(k, r') mod 2^24 */
	memcpy(hash, encrypted, 3);

	return true;
}

typedef struct {
	uint64_t a, b;
} u128;

static inline void u128_xor(const uint8_t p[16], const uint8_t q[16],
								uint8_t r[16])
{
	u128 pp, qq, rr;

	memcpy(&pp, p, 16);
	memcpy(&qq, q, 16);

	rr.a = pp.a ^ qq.a;
	rr.b = pp.b ^ qq.b;

	memcpy(r, &rr, 16);
}

/*
 * Confirm value generation function c1
 *
 * During the pairing process confirm values are exchanged. This confirm
 * value generation function c1 is used to generate the confirm values.
 *
 * The following are inputs to the confirm value generation function c1:
 *
 *   k is 128 bits
 *   r is 128 bits
 *   pres is 56 bits
 *   preq is 56 bits
 *   iat is 1 bit
 *   ia is 48 bits
 *   rat is 1 bit
 *   ra is 48 bits
 *   padding is 32 bits of 0
 *
 * iat is concatenated with 7-bits of 0 to create iat' which is 8 bits
 * in length. iat is the least significant bit of iat'
 *
 * rat is concatenated with 7-bits of 0 to create rat' which is 8 bits
 * in length. rat is the least significant bit of rat'
 *
 * pres, preq, rat' and iat' are concatenated to generate p1 which is
 * XORed with r and used as 128-bit input parameter plaintextData to
 * security function e:
 *
 *   p1 = pres || preq || rat' || iat'
 *
 * The octet of iat' becomes the least significant octet of p1 and the
 * most significant octet of pres becomes the most significant octet of
 * p1.
 *
 * ra is concatenated with ia and padding to generate p2 which is XORed
 * with the result of the security function e using p1 as the input
 * paremter plaintextData and is then used as the 128-bit input
 * parameter plaintextData to security function e:
 *
 *   p2 = padding || ia || ra
 *
 * The least significant octet of ra becomes the least significant octet
 * of p2 and the most significant octet of padding becomes the most
 * significant octet of p2.
 *
 * The output of the confirm value generation function c1 is:
 *
 *   c1(k, r, preq, pres, iat, rat, ia, ra) = e(k, e(k, r XOR p1) XOR p2)
 *
 * The 128-bit output of the security function e is used as the result
 * of confirm value generation function c1.
 */
bool bt_crypto_c1(struct bt_crypto *crypto, const uint8_t k[16],
			const uint8_t r[16], const uint8_t pres[7],
			const uint8_t preq[7], uint8_t iat,
			const uint8_t ia[6], uint8_t rat,
			const uint8_t ra[6], uint8_t res[16])
{
	uint8_t p1[16], p2[16];

	/* p1 = pres || preq || _rat || _iat */
	p1[0] = iat;
	p1[1] = rat;
	memcpy(p1 + 2, preq, 7);
	memcpy(p1 + 9, pres, 7);

	/* p2 = padding || ia || ra */
	memcpy(p2, ra, 6);
	memcpy(p2 + 6, ia, 6);
	memset(p2 + 12, 0, 4);

	/* res = r XOR p1 */
	u128_xor(r, p1, res);

	/* res = e(k, res) */
	if (!bt_crypto_e(crypto, k, res, res))
		return false;

	/* res = res XOR p2 */
	u128_xor(res, p2, res);

	/* res = e(k, res) */
	return bt_crypto_e(crypto, k, res, res);
}

/*
 * Key generation function s1
 *
 * The key generation function s1 is used to generate the STK during the
 * pairing process.
 *
 * The following are inputs to the key generation function s1:
 *
 *   k is 128 bits
 *   r1 is 128 bits
 *   r2 is 128 bits
 *
 * The most significant 64-bits of r1 are discarded to generate r1' and
 * the most significant 64-bits of r2 are discarded to generate r2'.
 *
 * r1' is concatenated with r2' to generate r' which is used as the
 * 128-bit input parameter plaintextData to security function e:
 *
 *   r' = r1' || r2'
 *
 * The least significant octet of r2' becomes the least significant
 * octet of r' and the most significant octet of r1' becomes the most
 * significant octet of r'.
 *
 * The output of the key generation function s1 is:
 *
 *   s1(k, r1, r2) = e(k, r')
 *
 * The 128-bit output of the security function e is used as the result
 * of key generation function s1.
 */
bool bt_crypto_s1(struct bt_crypto *crypto, const uint8_t k[16],
			const uint8_t r1[16], const uint8_t r2[16],
			uint8_t res[16])
{
	memcpy(res, r2, 8);
	memcpy(res + 8, r1, 8);

	return bt_crypto_e(crypto, k, res, res);
}
