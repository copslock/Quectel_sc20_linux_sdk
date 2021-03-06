/***************************************************************************
* Copyright (c) 2017 Qualcomm Technologies, Inc.                           *
* All Rights Reserved.                                                     *
* Confidential and Proprietary - Qualcomm Technologies, Inc.               *
***************************************************************************/
#ifndef __MODULE_RTB_H__
#define __MODULE_RTB_H__

/** g_rtb_caps:
 *
 *  Set the capabilities for RTB module
*/
static img_caps_t g_rtb_caps = {
  .num_input = 1,
  .num_output = 1,
  .num_meta = 1,
  .inplace_algo = 0,
  .num_release_buf = 0,
  .preload_mode = IMG_PRELOAD_COMMON_STREAM_CFG_MODE,
  .use_internal_bufs = 1,
  .internal_buf_cnt = 4,
  .before_cpp = true,
  .will_dim_change = true,
};

/** img_rtb_cfg_t:
 *
 *   @af_status: AF Status
 *   @frame_rate: Frame Rate
 *   @fov_cf : Spatial transform fov cfg data
 *
 *   Session based parameters for SAC module
 */
typedef struct {
  cam_af_state_t af_state;
  float frame_rate;
  img_fov_t fov_cf[IMG_MAX_FOV];
} img_rtb_cfg_t;

/** img_rtb_result_t:
 *
 *   @frameid: Frameid of the result
 *   @chosen_frame: chosen frame
 *
 *   RTB client private structure
 */
typedef struct {
  uint32_t frameid;
  img_camera_role_t chosen_frame;
} img_rtb_result_t;

#endif
