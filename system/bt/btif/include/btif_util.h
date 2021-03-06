/******************************************************************************
 *
 *  Copyright (c) 2014 The Android Open Source Project
 *  Copyright (C) 2009-2012 Broadcom Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

#ifndef BTIF_UTIL_H
#define BTIF_UTIL_H

#include <hardware/bluetooth.h>
#include <hardware/bt_hf.h>
#include <stdbool.h>
#include <sys/time.h>

#include "bt_types.h"
#include "bt_utils.h"

/*******************************************************************************
**  Constants & Macros
********************************************************************************/

#define CASE_RETURN_STR(const) case const: return #const;


/*******************************************************************************
**  Type definitions for callback functions
********************************************************************************/
typedef char bdstr_t[18];

/*******************************************************************************
**  Functions
********************************************************************************/

const char* dump_bt_status(bt_status_t status);
const char* dump_dm_search_event(UINT16 event);
const char* dump_dm_event(UINT16 event);
const char* dump_hf_event(UINT16 event);
const char* dump_hf_client_event(UINT16 event);
const char* dump_hh_event(UINT16 event);
const char* dump_hf_conn_state(UINT16 event);
const char* dump_hf_call_state(bthf_call_state_t call_state);
const char* dump_property_type(bt_property_type_t type);
const char* dump_hf_audio_state(UINT16 event);
const char* dump_adapter_scan_mode(bt_scan_mode_t mode);
const char* dump_thread_evt(bt_cb_thread_evt evt);
const char* dump_av_conn_state(UINT16 event);
const char* dump_av_audio_state(UINT16 event);
const char* dump_rc_event(UINT8 event);
const char* dump_rc_notification_event_id(UINT8 event_id);
const char* dump_rc_pdu(UINT8 pdu);

UINT32 devclass2uint(DEV_CLASS dev_class);
void uint2devclass(UINT32 dev, DEV_CLASS dev_class);
void uuid16_to_uuid128(uint16_t uuid16, bt_uuid_t* uuid128);

// Takes a |str| containing a 128-bit GUID formatted UUID and stores the
// result in |p_uuid|. |str| must be formatted in this format:
//   "12345678-1234-1234-1234-123456789012"
// |p_uuid| cannot be null. Returns true if parsing was successful, false
// otherwise. Returns false if |str| is null.
bool string_to_uuid(const char *str, bt_uuid_t *p_uuid);

void uuid_to_string_legacy(bt_uuid_t *p_uuid, char *str);
int ascii_2_hex (const char *p_ascii, int len, UINT8 *p_hex);

#endif /* BTIF_UTIL_H */
