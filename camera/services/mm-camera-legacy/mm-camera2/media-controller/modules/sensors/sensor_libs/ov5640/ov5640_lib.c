/*============================================================================

  Copyright (c) 2017-2018 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.

============================================================================*/
#include <stdio.h>
#include "sensor_lib.h"
#include <utils/Log.h>

static sensor_lib_t sensor_lib_ptr;

#define SNAPSHOT_PARAM    1
#define PREVIEW_PARAM     1
#define VIDEO_1080P_PARAM 1
#define USE_VGA_PARAM     1


#define LOG_TAG "ov5640"

static struct msm_sensor_power_setting ov5640_power_setting[] = {
 {
    .seq_type = SENSOR_GPIO,
    .seq_val = SENSOR_GPIO_RESET,
    .config_val = GPIO_OUT_LOW,
    .delay = 1,
 },
  {
    .seq_type = SENSOR_GPIO,
    .seq_val = SENSOR_GPIO_STANDBY,
    .config_val = GPIO_OUT_HIGH,
    .delay = 1,
  },
  {
    .seq_type = SENSOR_VREG,
    .seq_val = CAM_VDIG,
    .config_val = 1200000,
    .delay = 2,
  },
  {
    .seq_type = SENSOR_VREG,
    .seq_val = CAM_VIO,
    .config_val = 1800000,
    .delay = 1,
  },
  {
    .seq_type = SENSOR_VREG,
    .seq_val = CAM_VANA,
    .config_val = 2850000,
    .delay = 5,
  },
  {
    .seq_type = SENSOR_GPIO,
    .seq_val = SENSOR_GPIO_STANDBY,
    .config_val = GPIO_OUT_LOW,
    .delay = 1,
  },
  {
    .seq_type = SENSOR_GPIO,
    .seq_val = SENSOR_GPIO_RESET,
    .config_val = GPIO_OUT_HIGH,
    .delay = 20,
  },
  {
    .seq_type = SENSOR_CLK,
    .seq_val = SENSOR_CAM_MCLK,
    .config_val = 24000000,
    .delay = 10,
  },
  {
    .seq_type = SENSOR_I2C_MUX,
    .seq_val = 0,
    .config_val = 0,
    .delay = 0,
  },
};

static struct msm_sensor_power_setting ov5640_power_down_setting[] = {
 {
    .seq_type = SENSOR_VREG,
    .seq_val = CAM_VDIG,
    .config_val = 0,
    .delay = 2,
  },
  {
    .seq_type = SENSOR_VREG,
    .seq_val = CAM_VANA,
    .config_val = 0,
    .delay = 1,
  },
  {
    .seq_type = SENSOR_VREG,
    .seq_val = CAM_VIO,
    .config_val = 0,
    .delay = 1,
  },
  {
    .seq_type = SENSOR_GPIO,
    .seq_val = SENSOR_GPIO_STANDBY,
    .config_val = GPIO_OUT_LOW,
    .delay = 1,
  },
  {
    .seq_type = SENSOR_GPIO,
    .seq_val = SENSOR_GPIO_RESET,
    .config_val = GPIO_OUT_LOW,
    .delay = 1,
  },
  {
    .seq_type = SENSOR_CLK,
    .seq_val = SENSOR_CAM_MCLK,
    .config_val = 24000000,
    .delay = 10,
  },
  {
    .seq_type = SENSOR_I2C_MUX,
    .seq_val = 0,
    .config_val = 0,
    .delay = 0,
  },
};


static struct msm_camera_sensor_slave_info sensor_slave_info = {
  /* Camera slot where this camera is mounted */
  .sensor_name = "ov5640",
  .camera_id = CAMERA_0,
  /* sensor slave address */
  .slave_addr = 0x78,
  /* sensor address type */
  .addr_type = MSM_CAMERA_I2C_WORD_ADDR,
  /* sensor id info*/
  .sensor_id_info = {
    /* sensor id register address */
    .sensor_id_reg_addr = 0x300A,
    /* sensor id */
    .sensor_id = 0x5640,
  },
  /* power up / down setting */
  .power_setting_array = {
    .power_setting = ov5640_power_setting,
    .size = ARRAY_SIZE(ov5640_power_setting),
    .power_down_setting = ov5640_power_down_setting,
    .size_down = ARRAY_SIZE(ov5640_power_down_setting),
  },
};

static struct msm_sensor_init_params sensor_init_params = {
  .modes_supported = CAMERA_MODE_2D_B,
  .position = BACK_CAMERA_B,
  .sensor_mount_angle = SENSOR_MOUNTANGLE_90,
};

static sensor_output_t sensor_output = {
  .output_format = SENSOR_YCBCR,
  .connection_mode = SENSOR_MIPI_CSI,
  .raw_output = SENSOR_8_BIT_DIRECT,
};

static struct msm_sensor_output_reg_addr_t output_reg_addr = {
  .x_output = 0x3808,
  .y_output = 0x380a,
  .line_length_pclk = 0x380c,
  .frame_length_lines = 0x380e,
};

static sensor_lens_info_t default_lens_info = {
  .focal_length = 4.6,
  .pix_size = 1.4,
  .f_number = 2.65,
  .total_f_dist = 1.97,
  .hor_view_angle = 54.8,
  .ver_view_angle = 42.5,
};

#ifndef VFE_40
static struct csi_lane_params_t csi_lane_params = {
  .csi_lane_assign = 0x4320,
  .csi_lane_mask = 0x7,
  .csi_if = 1,
  .csid_core = {0},
  .csi_phy_sel = 0,
};
#else
static struct csi_lane_params_t csi_lane_params = {
  .csi_lane_assign = 0x4320,
  .csi_lane_mask = 0x7,
  .csi_if = 1,
  .csid_core = {0},
  .csi_phy_sel = 0,
};
#endif

static struct msm_camera_i2c_reg_array init_reg_array1[] = {
    {0x3103, 0x11},
    {0x3008, 0x82},
    {0x3008, 0x42},
    {0x3103, 0x03},
    {0x3017, 0x00},
    {0x3018, 0x00},
    {0x3034, 0x18},
    {0x3035, 0x11},
    {0x3036, 0x54},
    {0x3037, 0x13},
    {0x3108, 0x01},
    {0x3630, 0x36},
    {0x3631, 0x0e},
    {0x3632, 0xe2},
    {0x3633, 0x12},
    {0x3621, 0xe0},
    {0x3704, 0xa0},
    {0x3703, 0x5a},
    {0x3715, 0x78},
    {0x3717, 0x01},
    {0x370b, 0x60},
    {0x3705, 0x1a},
    {0x3905, 0x02},
    {0x3906, 0x10},
    {0x3901, 0x0a},
    {0x3731, 0x12},
    {0x3600, 0x08},
    {0x3601, 0x33},
    {0x302d, 0x60},
    {0x3620, 0x52},
    {0x371b, 0x20},
    {0x471c, 0x50},
    {0x3a13, 0x43},
    {0x3a18, 0x00},
    {0x3a19, 0xf8},
    {0x3635, 0x13},
    {0x3636, 0x03},
    {0x3634, 0x40},
    {0x3622, 0x01},
    {0x3c01, 0x34},
    {0x3c04, 0x28},
    {0x3c05, 0x98},
    {0x3c06, 0x00},
    {0x3c07, 0x07},
    {0x3c08, 0x00},
    {0x3c09, 0x1c},
    {0x3c0a, 0x9c},
    {0x3c0b, 0x40},
    {0x3820, 0x40},
    {0x3821, 0x06},
    {0x3814, 0x11},
    {0x3815, 0x11},
    {0x3800, 0x00},
    {0x3801, 0x00},
    {0x3802, 0x00},
    {0x3803, 0x00},
    {0x3804, 0x0a},
    {0x3805, 0x3f},
    {0x3806, 0x07},
    {0x3807, 0x9f},
    {0x3808, 0x0a},
    {0x3809, 0x20},
    {0x380a, 0x07},
    {0x380b, 0x98},
    {0x380c, 0x0b},
    {0x380d, 0x1c},
    {0x380e, 0x07},
    {0x380f, 0xb0},
    {0x3810, 0x00},
    {0x3811, 0x10},
    {0x3812, 0x00},
    {0x3813, 0x04},
    {0x3618, 0x04},
    {0x3612, 0x2b},
    {0x3708, 0x64},
    {0x3709, 0x12},
    {0x370c, 0x00},
    {0x3a02, 0x07},
    {0x3a03, 0xb0},
    {0x3a08, 0x01},
    {0x3a09, 0x27},
    {0x3a0a, 0x00},
    {0x3a0b, 0xf6},
    {0x3a0e, 0x06},
    {0x3a0d, 0x08},
    {0x3a14, 0x07},
    {0x3a15, 0xb0},
    {0x4001, 0x02},
    {0x4004, 0x06},
    {0x3000, 0x00},
    {0x3002, 0x1c},
    {0x3004, 0xff},
    {0x3006, 0xc3},
    {0x300e, 0x45},
    {0x302e, 0x08},
    {0x4300, 0x30},
    {0x501f, 0x00},
    {0x440e, 0x00},
    {0x4837, 0x0a},
    {0x5000, 0xa7},
    {0x5001, 0x83},
    {0x5180, 0xff},
    {0x5181, 0xf2},
    {0x5182, 0x00},
    {0x5183, 0x14},
    {0x5184, 0x25},
    {0x5185, 0x24},
    {0x5186, 0x09},
    {0x5187, 0x09},
    {0x5188, 0x09},
    {0x5189, 0x75},
    {0x518a, 0x54},
    {0x518b, 0xe0},
    {0x518c, 0xb2},
    {0x518d, 0x42},
    {0x518e, 0x3d},
    {0x518f, 0x56},
    {0x5190, 0x46},
    {0x5191, 0xf8},
    {0x5192, 0x04},
    {0x5193, 0x70},
    {0x5194, 0xf0},
    {0x5195, 0xf0},
    {0x5196, 0x03},
    {0x5197, 0x01},
    {0x5198, 0x04},
    {0x5199, 0x12},
    {0x519a, 0x04},
    {0x519b, 0x00},
    {0x519c, 0x06},
    {0x519d, 0x82},
    {0x519e, 0x38},
    {0x5381, 0x1e},
    {0x5382, 0x5b},
    {0x5383, 0x08},
    {0x5384, 0x0a},
    {0x5385, 0x7e},
    {0x5386, 0x88},
    {0x5387, 0x7c},
    {0x5388, 0x6c},
    {0x5389, 0x10},
    {0x538a, 0x01},
    {0x538b, 0x98},
    {0x5300, 0x08},
    {0x5301, 0x30},
    {0x5302, 0x10},
    {0x5303, 0x00},
    {0x5304, 0x08},
    {0x5305, 0x30},
    {0x5306, 0x08},
    {0x5307, 0x16},
    {0x5309, 0x08},
    {0x530a, 0x30},
    {0x530b, 0x04},
    {0x530c, 0x06},
    {0x5480, 0x01},
    {0x5481, 0x08},
    {0x5482, 0x14},
    {0x5483, 0x28},
    {0x5484, 0x51},
    {0x5485, 0x65},
    {0x5486, 0x71},
    {0x5487, 0x7d},
    {0x5488, 0x87},
    {0x5489, 0x91},
    {0x548a, 0x9a},
    {0x548b, 0xaa},
    {0x548c, 0xb8},
    {0x548d, 0xcd},
    {0x548e, 0xdd},
    {0x548f, 0xea},
    {0x5490, 0x1d},
    {0x5580, 0x02},
    {0x5583, 0x40},
    {0x5584, 0x10},
    {0x5589, 0x10},
    {0x558a, 0x00},
    {0x558b, 0xf8},
    {0x5800, 0x23},
    {0x5801, 0x14},
    {0x5802, 0x0f},
    {0x5803, 0x0f},
    {0x5804, 0x12},
    {0x5805, 0x26},
    {0x5806, 0x0c},
    {0x5807, 0x08},
    {0x5808, 0x05},
    {0x5809, 0x05},
    {0x580a, 0x08},
    {0x580b, 0x0d},
    {0x580c, 0x08},
    {0x580d, 0x03},
    {0x580e, 0x00},
    {0x580f, 0x00},
    {0x5810, 0x03},
    {0x5811, 0x09},
    {0x5812, 0x07},
    {0x5813, 0x03},
    {0x5814, 0x00},
    {0x5815, 0x01},
    {0x5816, 0x03},
    {0x5817, 0x08},
    {0x5818, 0x0d},
    {0x5819, 0x08},
    {0x581a, 0x05},
    {0x581b, 0x06},
    {0x581c, 0x08},
    {0x581d, 0x0e},
    {0x581e, 0x29},
    {0x581f, 0x17},
    {0x5820, 0x11},
    {0x5821, 0x11},
    {0x5822, 0x15},
    {0x5823, 0x28},
    {0x5824, 0x46},
    {0x5825, 0x26},
    {0x5826, 0x08},
    {0x5827, 0x26},
    {0x5828, 0x64},
    {0x5829, 0x26},
    {0x582a, 0x24},
    {0x582b, 0x22},
    {0x582c, 0x24},
    {0x582d, 0x24},
    {0x582e, 0x06},
    {0x582f, 0x22},
    {0x5830, 0x40},
    {0x5831, 0x42},
    {0x5832, 0x24},
    {0x5833, 0x26},
    {0x5834, 0x24},
    {0x5835, 0x22},
    {0x5836, 0x22},
    {0x5837, 0x26},
    {0x5838, 0x44},
    {0x5839, 0x24},
    {0x583a, 0x26},
    {0x583b, 0x28},
    {0x583c, 0x42},
    {0x583d, 0xce},
    {0x5025, 0x00},
    {0x3a0f, 0x30},
    {0x3a10, 0x28},
    {0x3a1b, 0x30},
    {0x3a1e, 0x26},
    {0x3a11, 0x60},
    {0x3a1f, 0x14},
    {0x302c, 0xc2},
    {0x3008, 0x02},
};

static struct msm_camera_i2c_reg_setting init_reg_setting[] = {
  {
    .reg_setting = init_reg_array1,
    .size = ARRAY_SIZE(init_reg_array1),
    .addr_type = MSM_CAMERA_I2C_WORD_ADDR,
    .data_type = MSM_CAMERA_I2C_BYTE_DATA,
    .delay = 1,
  },
};

static struct sensor_lib_reg_settings_array init_settings_array = {
  .reg_settings = init_reg_setting,
  .size = 1,
};

static struct msm_camera_i2c_reg_array start_reg_array[] = {
  {0x4202, 0x00},
};

static  struct msm_camera_i2c_reg_setting start_settings = {
  .reg_setting = start_reg_array,
  .size = ARRAY_SIZE(start_reg_array),
  .addr_type = MSM_CAMERA_I2C_WORD_ADDR,
  .data_type = MSM_CAMERA_I2C_BYTE_DATA,
  .delay = 1,
};

static struct msm_camera_i2c_reg_array stop_reg_array[] = {
  {0x4202, 0x0f},
};

static struct msm_camera_i2c_reg_setting stop_settings = {
  .reg_setting = stop_reg_array,
  .size = ARRAY_SIZE(stop_reg_array),
  .addr_type = MSM_CAMERA_I2C_WORD_ADDR,
  .data_type = MSM_CAMERA_I2C_BYTE_DATA,
  .delay = 1,
};


static struct msm_camera_csid_vc_cfg ov5640_cid_cfg[] = {
  {0, CSI_YUV422_8, CSI_DECODE_8BIT},
  {1, CSI_EMBED_DATA, CSI_DECODE_8BIT},
};

static struct msm_camera_csi2_params ov5640_csi_params = {
  .csid_params = {
    .lane_cnt = 2,
    .lut_params = {
      .num_cid = ARRAY_SIZE(ov5640_cid_cfg),
      .vc_cfg = {
         &ov5640_cid_cfg[0],
         &ov5640_cid_cfg[1],
      },
    },
  },
  .csiphy_params = {
    .lane_cnt = 2,
    .settle_cnt = 0x1b,
#ifndef VFE_40
    .combo_mode = 1,
#endif
  },
};

static struct sensor_pix_fmt_info_t ov5640_pix_fmt0_fourcc[] = {
  { V4L2_MBUS_FMT_YUYV8_2X8 },
};

static struct sensor_pix_fmt_info_t ov5640_pix_fmt1_fourcc[] = {
  { MSM_V4L2_PIX_FMT_META },
};

static sensor_stream_info_t ov5640_stream_info[] = {
  {1, &ov5640_cid_cfg[0], ov5640_pix_fmt0_fourcc},
  {1, &ov5640_cid_cfg[1], ov5640_pix_fmt1_fourcc},
};

static sensor_stream_info_array_t ov5640_stream_info_array = {
  .sensor_stream_info = ov5640_stream_info,
  .size = ARRAY_SIZE(ov5640_stream_info),
};

#ifdef SNAPSHOT_PARAM
static struct msm_camera_i2c_reg_array res0_reg_array[] = {
//Capture 2592x1944 30fps 24M MCLK 2lane 960Mbps/lane
    {0x3008, 0x42},
    {0x3035, 0x11},
    {0x3036, 0x54},
    {0x3c07, 0x07},
    {0x3820, 0x40},
    {0x3821, 0x06},
    {0x3814, 0x11},
    {0x3815, 0x11},
    {0x3800, 0x00},
    {0x3801, 0x00},
    {0x3802, 0x00},
    {0x3803, 0x00},
    {0x3804, 0x0a},
    {0x3805, 0x3f},
    {0x3806, 0x07},
    {0x3807, 0x9f},
    {0x3808, 0x0a},
    {0x3809, 0x20},
    {0x380a, 0x07},
    {0x380b, 0x98},
    {0x380c, 0x0b},
    {0x380d, 0x1c},
    {0x380e, 0x07},
    {0x380f, 0xb0},
    {0x3813, 0x04},
    {0x3618, 0x04},
    {0x3612, 0x2b},
    {0x3709, 0x12},
    {0x370c, 0x00},
    {0x3a02, 0x07},
    {0x3a03, 0xb0},
    {0x3a09, 0x27},
    {0x3a0a, 0x00},
    {0x3a0b, 0xf6},
    {0x3a0e, 0x06},
    {0x3a0d, 0x08},
    {0x3a14, 0x07},
    {0x3a15, 0xb0},
    {0x4004, 0x06},
    {0x4837, 0x0a},
    {0x5001, 0x83},
    {0x3008, 0x02},
};
#endif

#ifdef PREVIEW_PARAM
static struct msm_camera_i2c_reg_array res1_reg_array[] = {
//Preview 1296x972 30fps 24M MCLK 2lane 960Mbps/lane
    {0x3008, 0x42},
    {0x3035, 0x21},
    {0x3036, 0x70},
    {0x3c07, 0x07},
    {0x3820, 0x41},
    {0x3821, 0x07},
    {0x3814, 0x31},
    {0x3815, 0x31},
    {0x3800, 0x00},
    {0x3801, 0x00},
    {0x3802, 0x00},
    {0x3803, 0x04},
    {0x3804, 0x0a},
    {0x3805, 0x3f},
    {0x3806, 0x07},
    {0x3807, 0x9b},
    {0x3808, 0x05},
    {0x3809, 0x00},
    {0x380a, 0x03},
    {0x380b, 0xc0},
    {0x380c, 0x07},
    {0x380d, 0x68},
    {0x380e, 0x03},
    {0x380f, 0xd8},
    {0x3813, 0x06},
    {0x3618, 0x00},
    {0x3612, 0x29},
    {0x3709, 0x52},
    {0x370c, 0x03},
    {0x3a02, 0x03},
    {0x3a03, 0xd8},
    {0x3a09, 0x27},
    {0x3a0a, 0x00},
    {0x3a0b, 0xf6},
    {0x3a0e, 0x03},
    {0x3a0d, 0x04},
    {0x3a14, 0x03},
    {0x3a15, 0xd8},
    {0x4004, 0x02},
    {0x4837, 0x10},
    {0x5001, 0x83},
    {0x3008, 0x02},
};
#endif

#ifdef VIDEO_1080P_PARAM
static struct msm_camera_i2c_reg_array res2_reg_array[] = {
//Video 1080p crop 30fps 24M MCLK 2lane 960Mbps/lane
    {0x3008, 0x42},
    {0x3035, 0x11},
    {0x3036, 0x54},
    {0x3c07, 0x07},
    {0x3820, 0x40},
    {0x3821, 0x06},
    {0x3814, 0x11},
    {0x3815, 0x11},
    {0x3800, 0x01},
    {0x3801, 0x50},
    {0x3802, 0x01},
    {0x3803, 0xb2},
    {0x3804, 0x08},
    {0x3805, 0xef},
    {0x3806, 0x05},
    {0x3807, 0xf1},
    {0x3808, 0x07},
    {0x3809, 0x80},
    {0x380a, 0x04},
    {0x380b, 0x38},
    {0x380c, 0x09},
    {0x380d, 0xc4},
    {0x380e, 0x04},
    {0x380f, 0x60},
    {0x3813, 0x04},
    {0x3618, 0x04},
    {0x3612, 0x2b},
    {0x3709, 0x12},
    {0x370c, 0x00},
    {0x3a02, 0x04},
    {0x3a03, 0x60},
    {0x3a09, 0x50},
    {0x3a0a, 0x01},
    {0x3a0b, 0x18},
    {0x3a0e, 0x03},
    {0x3a0d, 0x04},
    {0x3a14, 0x04},
    {0x3a15, 0x60},
    {0x4004, 0x06},
    {0x4837, 0x0a},
    {0x5001, 0x83},
    {0x3008, 0x02},
};

#ifdef USE_VGA_PARAM
static struct msm_camera_i2c_reg_array res3_reg_array[] = {
//@@ preview_vga_30fps
//line_length=1896   framelength=984
    {0x3008, 0x42},
    {0x3035, 0x14},
    {0x3036, 0x38},
    {0x3c07, 0x08},
    {0x3820, 0x41},
    {0x3821, 0x07},
    {0x3814, 0x31},
    {0x3815, 0x31},
    {0x3800, 0x00},
    {0x3801, 0x00},
    {0x3802, 0x00},
    {0x3803, 0x04},
    {0x3804, 0x0a},
    {0x3805, 0x3f},
    {0x3806, 0x07},
    {0x3807, 0x9b},
    {0x3808, 0x02},
    {0x3809, 0x80},
    {0x380a, 0x01},
    {0x380b, 0xe0},
    {0x380c, 0x07},
    {0x380d, 0x68},
    {0x380e, 0x03},
    {0x380f, 0xd8},
    {0x3813, 0x06},
    {0x3618, 0x00},
    {0x3612, 0x29},
    {0x3709, 0x52},
    {0x370c, 0x03},
    {0x3a02, 0x03},
    {0x3a03, 0xd8},
    {0x3a09, 0x27},
    {0x3a0a, 0x00},
    {0x3a0b, 0xf6},
    {0x3a0e, 0x03},
    {0x3a0d, 0x04},
    {0x3a14, 0x03},
    {0x3a15, 0xd8},
    {0x4004, 0x02},
    {0x4837, 0x44},
    {0x5001, 0xa3},
    {0x3008, 0x02},
};
#endif

#endif
static struct msm_camera_i2c_reg_setting res_settings[] = {
#if SNAPSHOT_PARAM
  {
    .reg_setting = res0_reg_array,
    .size = ARRAY_SIZE(res0_reg_array),
    .addr_type = MSM_CAMERA_I2C_WORD_ADDR,
    .data_type = MSM_CAMERA_I2C_BYTE_DATA,
    .delay = 1,
  },
#endif
#if PREVIEW_PARAM
  {
    .reg_setting = res1_reg_array,
    .size = ARRAY_SIZE(res1_reg_array),
    .addr_type = MSM_CAMERA_I2C_WORD_ADDR,
    .data_type = MSM_CAMERA_I2C_BYTE_DATA,
    .delay = 1,
  },
#endif
#if VIDEO_1080P_PARAM
  {
    .reg_setting = res2_reg_array,
    .size = ARRAY_SIZE(res2_reg_array),
    .addr_type = MSM_CAMERA_I2C_WORD_ADDR,
    .data_type = MSM_CAMERA_I2C_BYTE_DATA,
    .delay = 1,
  },
#endif
#ifdef USE_VGA_PARAM
  {
    .reg_setting = res3_reg_array,
    .size = ARRAY_SIZE(res3_reg_array),
    .addr_type = MSM_CAMERA_I2C_WORD_ADDR,
    .data_type = MSM_CAMERA_I2C_BYTE_DATA,
    .delay = 1,
  },
#endif
};

static struct sensor_lib_reg_settings_array res_settings_array = {
  .reg_settings = res_settings,
  .size = ARRAY_SIZE(res_settings),
};

static struct msm_camera_csi2_params *csi_params[] = {
#if SNAPSHOT_PARAM
  &ov5640_csi_params, /* RES 0*/
#endif
#if PREVIEW_PARAM
  &ov5640_csi_params, /* RES 1*/
#endif
#if VIDEO_1080P_PARAM
  &ov5640_csi_params, /* RES 2*/
#endif
#ifdef USE_VGA_PARAM
  &ov5640_csi_params, /* RES 3*/
#endif
};

static struct sensor_lib_csi_params_array csi_params_array = {
  .csi2_params = &csi_params[0],
  .size = ARRAY_SIZE(csi_params),
};

static struct sensor_crop_parms_t crop_params[] = {
#if SNAPSHOT_PARAM
  {0, 0, 0, 0}, /* RES 0 */
#endif
#if PREVIEW_PARAM
  {0, 0, 0, 0}, /* RES 1 */
#endif
#if VIDEO_1080P_PARAM
  {0, 0, 0, 0}, /* RES 2 */
#endif
#ifdef USE_VGA_PARAM
  {0, 0, 0, 0}, /* RES 3 */
#endif
};

static struct sensor_lib_crop_params_array crop_params_array = {
  .crop_params = crop_params,
  .size = ARRAY_SIZE(crop_params),
};

static struct sensor_lib_out_info_t sensor_out_info[] = {
#if SNAPSHOT_PARAM
{
    .x_output = 2592*2,
    .y_output = 1944,
    .line_length_pclk = 2844, /* 2844 */
    .frame_length_lines = 1968, /* 1968 */
    .vt_pixel_clk = 168000000,
    .op_pixel_clk = 168000000,
    .binning_factor = 1,
    .max_fps = 30.0,
    .min_fps = 7.5,
    .mode = SENSOR_DEFAULT_MODE,
},
#endif
#if PREVIEW_PARAM
{
    .x_output = 1280*2,
    .y_output = 960,
    .line_length_pclk = 1896, /* 1896 */
    .frame_length_lines = 984, /* 984 */
    .vt_pixel_clk = 112000000,
    .op_pixel_clk = 112000000,
    .binning_factor = 1,
    .max_fps = 30.0,
    .min_fps = 7.5,
    .mode = SENSOR_DEFAULT_MODE,
},
#endif
#if VIDEO_1080P_PARAM
{
    .x_output = 1920*2,
    .y_output = 1080,
    .line_length_pclk = 2500, /* 2500 */
    .frame_length_lines = 1120, /* 1120 */
    .vt_pixel_clk = 168000000,
    .op_pixel_clk = 168000000,
    .binning_factor = 1,
    .max_fps = 30.0,
    .min_fps = 7.5,
    .mode = SENSOR_DEFAULT_MODE,
},
#endif
#ifdef USE_VGA_PARAM
{
    .x_output = 640*2,
    .y_output = 480,
    .line_length_pclk = 1896, /* 2500 */
    .frame_length_lines = 984, /* 1120 */
    .vt_pixel_clk = 112000000,
    .op_pixel_clk = 112000000,
    .binning_factor = 1,
    .max_fps = 30.0,
    .min_fps = 7.5,
    .mode = SENSOR_DEFAULT_MODE,
},
#endif
};

static struct sensor_lib_out_info_array out_info_array = {
  .out_info = sensor_out_info,
  .size = ARRAY_SIZE(sensor_out_info),
};

static sensor_res_cfg_type_t ov5640_res_cfg[] = {
  SENSOR_SET_STOP_STREAM,
  SENSOR_SET_NEW_RESOLUTION, /* set stream config */
  SENSOR_SET_CSIPHY_CFG,
  SENSOR_SET_CSID_CFG,
  SENSOR_SEND_EVENT, /* send event */
  SENSOR_SET_START_STREAM,
};

static struct sensor_res_cfg_table_t ov5640_res_table = {
  .res_cfg_type = ov5640_res_cfg,
  .size = ARRAY_SIZE(ov5640_res_cfg),
};

static sensor_lib_t sensor_lib_ptr = {
  /* sensor slave info */
  .sensor_slave_info = &sensor_slave_info,
  /* sensor init params */
  .sensor_init_params = &sensor_init_params,
  /* sensor output settings */
  .sensor_output = &sensor_output,
  /* number of frames to skip after start stream */
  .sensor_num_frame_skip = 5,
  /* number of frames to skip after start HDR stream */
  .sensor_num_HDR_frame_skip = 2,
  /* sensor pipeline immediate delay */
  .sensor_max_pipeline_frame_delay = 2,
  /* sensor lens info */
  .default_lens_info = &default_lens_info,
  /* csi lane params */
  .csi_lane_params = &csi_lane_params,
  /* csi cid params */
  .csi_cid_params = ov5640_cid_cfg,
  /* csi csid params array size */
  .csi_cid_params_size = ARRAY_SIZE(ov5640_cid_cfg),
  /* init settings */
  .init_settings_array = &init_settings_array,
  /* start settings */
  .start_settings = &start_settings,
  /* stop settings */
  .stop_settings = &stop_settings,
  /* resolution cfg table */
  .sensor_res_cfg_table = &ov5640_res_table,
  /* res settings */
  .res_settings_array = &res_settings_array,
  /* out info array */
  .out_info_array = &out_info_array,
  /* crop params array */
  .crop_params_array = &crop_params_array,
  /* csi params array */
  .csi_params_array = &csi_params_array,
  /* sensor port info array */
  .sensor_stream_info_array = &ov5640_stream_info_array,
  /* sensor pipeline immediate delay */
  .sensor_max_immediate_frame_delay = 2,
  .need_reinit_before_snapshot = 1,
};

/*===========================================================================
 * FUNCTION    - ov5640_open_lib -
 *
 * DESCRIPTION:
 *==========================================================================*/
void *ov5640_open_lib(void)
{
  return &sensor_lib_ptr;
}
