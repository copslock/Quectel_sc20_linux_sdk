/* Copyright (c) 2018, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation, nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <grp.h>
#include <unistd.h>
#include <sys/prctl.h>
#include <sys/capability.h>
#include <loc_pla.h>
#include <loc_cfg.h>
#include <gps_extended_c.h>
#include <loc_misc_utils.h>
#include "LocationApiService.h"

#define HAL_DAEMON_VERSION "1.0.4"

static uint32_t gAutoStartGnss = 0;
static uint32_t gGnssSessionTbfMs = 100;

static const loc_param_s_type gConfigTable[] =
{
    {"AUTO_START_GNSS", &gAutoStartGnss, NULL, 'n'},
    {"GNSS_SESSION_TBF_MS", &gGnssSessionTbfMs, NULL, 'n'}
};

int main(int argc, char *argv[])
{
    // read configuration file
    UTIL_READ_CONF(LOC_PATH_GPS_CONF, gConfigTable);

    LOC_LOGi("location hal daemon - ver %s", HAL_DAEMON_VERSION);

    // wait for parent direcoty to be created...
    struct stat buf_stat;
    while (1) {
        LOC_LOGd("waiting for %s...", SOCKET_DIR_LOCATION);
        int rc = stat(SOCKET_DIR_LOCATION, &buf_stat);
        if (!rc) {
            break;
        }
        usleep(100000); //100ms
    }
    LOC_LOGd("done");
    while (1) {
        LOC_LOGd("waiting for %s...", SOCKET_DIR_TO_CLIENT);
        int rc = stat(SOCKET_DIR_TO_CLIENT, &buf_stat);
        if (!rc) {
            break;
        }
        usleep(100000); //100ms
    }
    LOC_LOGd("done");
    while (1) {
        LOC_LOGd("waiting for %s...", SOCKET_DIR_EHUB);
        int rc = stat(SOCKET_DIR_EHUB, &buf_stat);
        if (!rc) {
            break;
        }
        usleep(100000); //100ms
    }
    LOC_LOGd("starting loc_hal_daemon");

    // check if this process started by root
    if (0 == getuid()) {

        // Set capabilities
        struct __user_cap_header_struct cap_hdr = {};
        cap_hdr.version = _LINUX_CAPABILITY_VERSION;
        cap_hdr.pid = getpid();
        if(prctl(PR_SET_KEEPCAPS, 1) < 0) {
            LOC_LOGe("Error: prctl failed. %s", strerror(errno));
        }

        // groups
#ifdef POWERMANAGER_ENABLED
        char groupNames[LOC_MAX_PARAM_NAME] = "gps diag powermgr locclient";
#else
        char groupNames[LOC_MAX_PARAM_NAME] = "gps diag locclient";
#endif
        gid_t groupIds[LOC_PROCESS_MAX_NUM_GROUPS] = {};
        char *splitGrpString[LOC_PROCESS_MAX_NUM_GROUPS];
        int numGrps = loc_util_split_string(groupNames, splitGrpString,
                LOC_PROCESS_MAX_NUM_GROUPS, ' ');

        int numGrpIds=0;
        for(int i=0; i<numGrps; i++) {
            struct group* grp = getgrnam(splitGrpString[i]);
            if (grp) {
                groupIds[numGrpIds] = grp->gr_gid;
                LOC_LOGv("Group %s = %d", splitGrpString[i], groupIds[numGrpIds]);
                numGrpIds++;
            }
        }
        if (0 != numGrpIds) {
            if(-1 == setgroups(numGrpIds, groupIds)) {
                LOC_LOGe("Error: setgroups failed %s", strerror(errno));
            }
        }

        // Set the group id first and then set the effective userid, to gps.
        if(-1 == setgid(GID_GPS)) {
            LOC_LOGe("Error: setgid failed. %s", strerror(errno));
        }
        // Set user id
        if(-1 == setuid(UID_GPS)) {
            LOC_LOGe("Error: setuid failed. %s", strerror(errno));
        }

        // Set access to netmgr (QCMAP)
        struct __user_cap_data_struct cap_data = {};
        cap_data.permitted = (1 << CAP_NET_BIND_SERVICE) | (1 << CAP_NET_ADMIN);
        cap_data.effective = cap_data.permitted;
        LOC_LOGv("cap_data.permitted: %d", (int)cap_data.permitted);
        if(capset(&cap_hdr, &cap_data)) {
            LOC_LOGe("Error: capset failed. %s", strerror(errno));
        }
    }

    // move to root dir
    chdir("/");

    // start listening for client events - will not return
    if (!LocationApiService::getInstance(gAutoStartGnss, gGnssSessionTbfMs)) {
        LOC_LOGd("Failed to start LocationApiService.");
    }

    // should not reach here...
    LOC_LOGd("done");
    exit(0);
}

