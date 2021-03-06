/*============================================================================

  Copyright (c) 2015 Qualcomm Technologies, Inc. All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.

============================================================================*/
#ifndef __S5K3M2XM_LIB_H__
#define __S5K3M2XM_LIB_H__

#include "sensor_lib.h"

#define SENSOR_MODEL_NO_S5K3M2XM "s5k3m2xm"
#define S5K3M2XM_LOAD_CHROMATIX(n) \
  "libchromatix_"SENSOR_MODEL_NO_S5K3M2XM"_"#n".so"

/* S5K3M2XM CONSTANTS */
#define S5K3M2XM_MAX_INTEGRATION_MARGIN   8  /* Unknown */

#define S5K3M2XM_DATA_PEDESTAL            0x40

#define S5K3M2XM_MIN_GAIN_REG_VAL         0 /* 1.0x */
#define S5K3M2XM_MAX_GAIN_REG_VAL         512 /* 16.0x */

/* S5K3M2XM FORMULAS */
#define S5K3M2XM_MIN_GAIN   (S5K3M2XM_MIN_GAIN_REG_VAL / 32)
#define S5K3M2XM_MAX_GAIN   (S5K3M2XM_MAX_GAIN_REG_VAL / 32)

#define SENSOR_PDAF_Y_OFFSET  24


static struct msm_camera_i2c_reg_array init0_reg_array[] = {
 {0x6028,0x4000},
 {0x6214,0x7971},
 {0x6218,0x0100},
 {0x6028,0x2000},
 {0x602A,0x448C},
 {0x6F12,0x0000},
 {0x6F12,0x0000},
 {0x6F12,0x0448},
 {0x6F12,0x0349},
 {0x6F12,0x0160},
 {0x6F12,0xC26A},
 {0x6F12,0x511A},
 {0x6F12,0x8180},
 {0x6F12,0x00F0},
 {0x6F12,0x2CB8},
 {0x6F12,0x2000},
 {0x6F12,0x4538},
 {0x6F12,0x2000},
 {0x6F12,0x1FA0},
 {0x6F12,0x0000},
 {0x6F12,0x0000},
 {0x6F12,0x0000},
 {0x6F12,0x0000},
 {0x6F12,0x2DE9},
 {0x6F12,0xF041},
 {0x6F12,0x0546},
 {0x6F12,0x1348},
 {0x6F12,0x134E},
 {0x6F12,0x018A},
 {0x6F12,0x4069},
 {0x6F12,0x06F1},
 {0x6F12,0x2007},
 {0x6F12,0x4143},
 {0x6F12,0x4FEA},
 {0x6F12,0x1138},
 {0x6F12,0x0024},
 {0x6F12,0x06EB},
 {0x6F12,0xC402},
 {0x6F12,0x0423},
 {0x6F12,0x3946},
 {0x6F12,0x4046},
 {0x6F12,0x00F0},
 {0x6F12,0x1EF8},
 {0x6F12,0x25F8},
 {0x6F12,0x1400},
 {0x6F12,0x641C},
 {0x6F12,0x042C},
 {0x6F12,0xF3DB},
 {0x6F12,0x0A48},
 {0x6F12,0x2988},
 {0x6F12,0x0180},
 {0x6F12,0x6988},
 {0x6F12,0x4180},
 {0x6F12,0xA988},
 {0x6F12,0x8180},
 {0x6F12,0xE988},
 {0x6F12,0xC180},
 {0x6F12,0xBDE8},
 {0x6F12,0xF081},
 {0x6F12,0x0022},
 {0x6F12,0xAFF2},
 {0x6F12,0x4B01},
 {0x6F12,0x0448},
 {0x6F12,0x00F0},
 {0x6F12,0x0DB8},
 {0x6F12,0x2000},
 {0x6F12,0x34D0},
 {0x6F12,0x2000},
 {0x6F12,0x7900},
 {0x6F12,0x4000},
 {0x6F12,0xD22E},
 {0x6F12,0x0000},
 {0x6F12,0x2941},
 {0x6F12,0x40F2},
 {0x6F12,0xFD7C},
 {0x6F12,0xC0F2},
 {0x6F12,0x000C},
 {0x6F12,0x6047},
 {0x6F12,0x4DF2},
 {0x6F12,0x474C},
 {0x6F12,0xC0F2},
 {0x6F12,0x000C},
 {0x6F12,0x6047},
 {0x6F12,0x0000},
 {0x6F12,0x0000},
 {0x6F12,0x0000},
 {0x6F12,0x0000},
 {0x6F12,0x30D2},
 {0x6F12,0x029C},
 {0x6F12,0x0000},
 {0x6F12,0x0001},
 {0x602A,0x7900},
 {0x6F12,0x4000},
 {0x6F12,0x3000},
 {0x6F12,0x2000},
 {0x6F12,0x1000},
 {0x6F12,0x4000},
 {0x6F12,0x3000},
 {0x6F12,0x2000},
 {0x6F12,0x1000},
 {0x6F12,0x4000},
 {0x6F12,0x3000},
 {0x6F12,0x2000},
 {0x6F12,0x1000},
 {0x6F12,0x4000},
 {0x6F12,0x3000},
 {0x6F12,0x2000},
 {0x6F12,0x1000},
 {0x6F12,0x0100},
 {0x6F12,0x0200},
 {0x6F12,0x0400},
 {0x6F12,0x0800},
 {0x602A,0x43F0},
 {0x6F12,0x0128},
 {0x6F12,0x00DC},
 {0x6F12,0x5590},
 {0x6F12,0x3644},
 {0x602A,0x1B50},
 {0x6F12,0x0000},
 {0x602A,0x1B54},
 {0x6F12,0x0000},
 {0x602A,0x1B64},
 {0x6F12,0x0800},
 {0x602A,0x1926},
 {0x6F12,0x0011},
 {0x602A,0x14FA},
 {0x6F12,0x0F00},
 {0x602A,0x4472},
 {0x6F12,0x0102},
 {0x6028,0x4000},
 {0x0B04,0x0000},
 {0x3B22,0x1110},
 {0xF42E,0x200C},
 {0xF49E,0x004C},
 {0xF4A6,0x00F0},
 {0x3AFA,0xFBB8},
 {0xF49C,0x0000},
 {0xF496,0x0000},
 {0xF476,0x0040},
 {0x3AAA,0x0205},
 {0x3AFE,0x07DF},
 {0xF47A,0x001B},
 {0xF462,0x0003},
 {0xF460,0x0020},
 {0x3B06,0x000E},
 {0x3AD0,0x0080},
 {0x3B02,0x0020},
 {0xF468,0x0001},
 {0xF494,0x000E},
 {0xF40C,0x2180},
 {0x3870,0x004C},
 {0x3876,0x0011},
 {0x3366,0x0128},
 {0x3852,0x00EA},
 {0x623E,0x0004},
 {0x3B5C,0x0006},
};

static struct msm_camera_i2c_reg_array res0_reg_array[] = {
 {0x6028,0x2000},
 {0x602A,0x14F0},
 {0x6F12,0x0040},
 {0x6F12,0x0040},
 {0x602A,0x192C},
 {0x6F12,0x0001},
 {0x6028,0x4000},
 {0x0344,0x0008},
 {0x0346,0x0008},
 {0x0348,0x1077},
 {0x034A,0x0C37},
 {0x034C,0x1070},
 {0x034E,0x0C30},
 {0x0900,0x0111},
 {0x0380,0x0001},
 {0x0382,0x0001},
 {0x0384,0x0001},
 {0x0386,0x0001},
 {0x0400,0x0002},
 {0x0404,0x0010},
 {0x0114,0x0300},
 {0x0110,0x0002},
 {0x112C,0x0000},
 {0x112E,0x0000},
 {0x0136,0x1800},
 {0x0304,0x0006},
 {0x0306,0x006E},
 {0x0302,0x0001},
 {0x0300,0x0004},
 {0x030C,0x0004},
 {0x030E,0x005A},
 {0x030A,0x0001},
 {0x0308,0x0008},
 {0x0342,0x11F0},
 {0x0340,0x0C74},
 {0x0202,0x0200},
 {0x0200,0x0400},
 {0x0B04,0x0000},
 {0x0B08,0x0000},
 {0x0B00,0x0080},
 {0x3B3C,0x0107},
 {0x3B34,0x3030},
 {0x3B36,0x3030},
 {0x3B38,0x3030},
 {0x3B3A,0x3030},
 {0x306A,0x0068},
 };

static struct msm_camera_i2c_reg_array res1_reg_array[] = {
 {0x6028,0x2000},
 {0x602A,0x14F0},
 {0x6F12,0x0040},
 {0x6F12,0x0040},
 {0x602A,0x192C},
 {0x6F12,0x0001},
 {0x6028,0x4000},
 {0x0344,0x0004},
 {0x0346,0x0000},
 {0x0348,0x107B},
 {0x034A,0x0C3F},
 {0x034C,0x0838},
 {0x034E,0x0618},
 {0x0900,0x0112},
 {0x0380,0x0001},
 {0x0382,0x0001},
 {0x0384,0x0001},
 {0x0386,0x0003},
 {0x0400,0x0001},
 {0x0404,0x0020},
 {0x0114,0x0300},
 {0x0110,0x0002},
 {0x112C,0x0000},
 {0x112E,0x0000},
 {0x0136,0x1800},
 {0x0304,0x0006},
 {0x0306,0x006E},
 {0x0302,0x0001},
 {0x0300,0x0004},
 {0x030C,0x0004},
 {0x030E,0x005A},
 {0x030A,0x0001},
 {0x0308,0x0008},
 {0x0342,0x11F0},
 {0x0340,0x0C74},
 {0x0202,0x0200},
 {0x0200,0x0400},
 {0x0204,0x0020},
 {0x0B04,0x0000},
 {0x0B08,0x0000},
 {0x0B00,0x0080},
 {0x3B3C,0x0107},
 {0x3B34,0x3030},
 {0x3B36,0x3030},
 {0x3B38,0x3030},
 {0x3B3A,0x3030},
 {0x306A,0x0068},
};

static struct msm_camera_i2c_reg_array res2_reg_array[] = {
 {0x6028, 0x2000},
 {0x602A, 0x14F0},
 {0x6F12, 0x0040},
 {0x6F12, 0x0040},
 {0x602A, 0x192C},
 {0x6F12, 0x0001},
 {0x6028, 0x4000},
 {0x0344, 0x00BC},
 {0x0346, 0x01E0},
 {0x0348, 0x0FC3},
 {0x034A, 0x0A5F},
 {0x034C, 0x0780},
 {0x034E, 0x0438},
 {0x0900, 0x0112},
 {0x0380, 0x0001},
 {0x0382, 0x0001},
 {0x0384, 0x0001},
 {0x0386, 0x0003},
 {0x0400, 0x0001},
 {0x0404, 0x0020},
 {0x0114, 0x0300},
 {0x0110, 0x0002},
 {0x112C, 0x0000},
 {0x112E, 0x0000},
 {0x0136, 0x1800},
 {0x0304, 0x0006},
 {0x0306, 0x006E},
 {0x0302, 0x0001},
 {0x0300, 0x0004},
 {0x030C, 0x0004},
 {0x030E, 0x005A},
 {0x030A, 0x0001},
 {0x0308, 0x0008},
 {0x0342, 0x11F0},
 {0x0340, 0x063c},
 {0x0202, 0x0200},
 {0x0200, 0x0400},
 {0x0B04, 0x0000},
 {0x0B08, 0x0000},
 {0x0B00, 0x0080},
 {0x3B3C, 0x0107},
 {0x3B34, 0x3030},
 {0x3B36, 0x3030},
 {0x3B38, 0x3030},
 {0x3B3A, 0x3030},
 {0x306A, 0x0068},
};

static struct msm_camera_i2c_reg_array res3_reg_array[] = {
 {0x6028, 0x2000},
 {0x602A, 0x14F0},
 {0x6F12, 0x0040},
 {0x6F12, 0x0040},
 {0x602A, 0x192C},
 {0x6F12, 0x0001},
 {0x6028, 0x4000},
 {0x0344, 0x00BC},
 {0x0346, 0x01DC},
 {0x0348, 0x0FC3},
 {0x034A, 0x0A63},
 {0x034C, 0x0500},
 {0x034E, 0x02D0},
 {0x0900, 0x0113},
 {0x0380, 0x0001},
 {0x0382, 0x0001},
 {0x0384, 0x0001},
 {0x0386, 0x0005},
 {0x0400, 0x0001},
 {0x0404, 0x0030},
 {0x0114, 0x0300},
 {0x0110, 0x0002},
 {0x112C, 0x0000},
 {0x112E, 0x0000},
 {0x0136, 0x1800},
 {0x0304, 0x0006},
 {0x0306, 0x006E},
 {0x0302, 0x0001},
 {0x0300, 0x0004},
 {0x030C, 0x0004},
 {0x030E, 0x005A},
 {0x030A, 0x0001},
 {0x0308, 0x0008},
 {0x0342, 0x11F0},
 {0x0340, 0x0428},
 {0x0202, 0x0200},
 {0x0200, 0x0400},
 {0x0B04, 0x0000},
 {0x0B08, 0x0000},
 {0x0B00, 0x0080},
 {0x3B3C, 0x0107},
 {0x3B34, 0x3030},
 {0x3B36, 0x3030},
 {0x3B38, 0x3030},
 {0x3B3A, 0x3030},
 {0x306A, 0x0068},
};

static struct msm_camera_i2c_reg_array res4_reg_array[] = {
 {0x6028, 0x2000},
 {0x602A, 0x14F0},
 {0x6F12, 0x0040},
 {0x6F12, 0x0040},
 {0x602A, 0x192C},
 {0x6F12, 0x0001},
 {0x6028, 0x4000},
 {0x0344, 0x00BC},
 {0x0346, 0x01DC},
 {0x0348, 0x0FC3},
 {0x034A, 0x0A63},
 {0x034C, 0x0500},
 {0x034E, 0x02D0},
 {0x0900, 0x0113},
 {0x0380, 0x0001},
 {0x0382, 0x0001},
 {0x0384, 0x0001},
 {0x0386, 0x0005},
 {0x0400, 0x0001},
 {0x0404, 0x0030},
 {0x0114, 0x0300},
 {0x0110, 0x0002},
 {0x112C, 0x0000},
 {0x112E, 0x0000},
 {0x0136, 0x1800},
 {0x0304, 0x0006},
 {0x0306, 0x006E},
 {0x0302, 0x0001},
 {0x0300, 0x0004},
 {0x030C, 0x0004},
 {0x030E, 0x005A},
 {0x030A, 0x0001},
 {0x0308, 0x0008},
 {0x0342, 0x11F0},
 {0x0340, 0x031E},
 {0x0202, 0x0200},
 {0x0200, 0x0400},
 {0x0B04, 0x0000},
 {0x0B08, 0x0000},
 {0x0B00, 0x0080},
 {0x3B3C, 0x0107},
 {0x3B34, 0x3030},
 {0x3B36, 0x3030},
 {0x3B38, 0x3030},
 {0x3B3A, 0x3030},
 {0x306A, 0x0068},
};

#endif

