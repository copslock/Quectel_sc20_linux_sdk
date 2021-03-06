/* ov5670_lib.h
 *
 * DESCRIPTION
 * Auto-Generated by Sensor Driver Generator tool
 *
 * Copyright (c) 2015 Qualcomm Technologies, Inc. All Rights Reserved.
 *
 * Qualcomm Technologies Proprietary and Confidential.
 */

#ifndef __OV5670_LIB_H__
#define __OV5670_LIB_H__

#include "sensor_lib.h"
#define SENSOR_MODEL "ov5670"

#define MIN_GAIN 1
#define MAX_ANALOG_GAIN (15.5)
#define MAX_DIGITAL_GAIN (1)
#define MAX_GAIN (MAX_ANALOG_GAIN * MAX_DIGITAL_GAIN)

#define OV5670_MAX_DGAIN_DECIMATOR  2048


#define START_REG_ARRAY \
{ \
  {0x0100, 0x01, 0x00}, \
}

#define STOP_REG_ARRAY \
{ \
  {0x0100, 0x00, 0x00}, \
}

#define GROUPON_REG_ARRAY \
{ \
  {0x3208, 0x00, 0x00}, \
}

#define GROUPOFF_REG_ARRAY \
{ \
  {0x3208, 0x10, 0x00}, \
  {0x3208, 0xa0, 0x00}, \
}

#define INIT0_REG_ARRAY \
{ \
  {0x0300, 0x04, 0x00}, \
  {0x0301, 0x00, 0x00}, \
  {0x0302, 0x69, 0x00}, \
  {0x0303, 0x00, 0x00}, \
  {0x0304, 0x03, 0x00}, \
  {0x0305, 0x01, 0x00}, \
  {0x0306, 0x01, 0x00}, \
  {0x030a, 0x00, 0x00}, \
  {0x030b, 0x00, 0x00}, \
  {0x030c, 0x00, 0x00}, \
  {0x030d, 0x1e, 0x00}, \
  {0x030e, 0x00, 0x00}, \
  {0x030f, 0x06, 0x00}, \
  {0x0312, 0x01, 0x00}, \
  {0x3000, 0x00, 0x00}, \
  {0x3002, 0x21, 0x00}, \
  {0x3005, 0xf0, 0x00}, \
  {0x3007, 0x00, 0x00}, \
  {0x3015, 0x0f, 0x00}, \
  {0x3018, 0x32, 0x00}, \
  {0x301a, 0xf0, 0x00}, \
  {0x301b, 0xf0, 0x00}, \
  {0x301c, 0xf0, 0x00}, \
  {0x301d, 0xf0, 0x00}, \
  {0x301e, 0xf0, 0x00}, \
  {0x3030, 0x00, 0x00}, \
  {0x3031, 0x0a, 0x00}, \
  {0x303c, 0xff, 0x00}, \
  {0x303e, 0xff, 0x00}, \
  {0x3040, 0xf0, 0x00}, \
  {0x3041, 0x00, 0x00}, \
  {0x3042, 0xf0, 0x00}, \
  {0x3106, 0x11, 0x00}, \
  {0x3500, 0x00, 0x00}, \
  {0x3501, 0x3d, 0x00}, \
  {0x3502, 0x00, 0x00}, \
  {0x3503, 0x04, 0x00}, \
  {0x3504, 0x03, 0x00}, \
  {0x3505, 0x83, 0x00}, \
  {0x3508, 0x07, 0x00}, \
  {0x3509, 0x80, 0x00}, \
  {0x350e, 0x04, 0x00}, \
  {0x350f, 0x00, 0x00}, \
  {0x3510, 0x00, 0x00}, \
  {0x3511, 0x02, 0x00}, \
  {0x3512, 0x00, 0x00}, \
  {0x3601, 0xc8, 0x00}, \
  {0x3610, 0x88, 0x00}, \
  {0x3612, 0x48, 0x00}, \
  {0x3614, 0x5b, 0x00}, \
  {0x3615, 0x96, 0x00}, \
  {0x3621, 0xd0, 0x00}, \
  {0x3622, 0x00, 0x00}, \
  {0x3623, 0x00, 0x00}, \
  {0x3633, 0x13, 0x00}, \
  {0x3634, 0x13, 0x00}, \
  {0x3635, 0x13, 0x00}, \
  {0x3636, 0x13, 0x00}, \
  {0x3645, 0x13, 0x00}, \
  {0x3646, 0x82, 0x00}, \
  {0x3650, 0x00, 0x00}, \
  {0x3652, 0xff, 0x00}, \
  {0x3655, 0x20, 0x00}, \
  {0x3656, 0xff, 0x00}, \
  {0x365a, 0xff, 0x00}, \
  {0x365e, 0xff, 0x00}, \
  {0x3668, 0x00, 0x00}, \
  {0x366a, 0x07, 0x00}, \
  {0x366e, 0x08, 0x00}, \
  {0x366d, 0x00, 0x00}, \
  {0x366f, 0x80, 0x00}, \
  {0x3700, 0x28, 0x00}, \
  {0x3701, 0x10, 0x00}, \
  {0x3702, 0x3a, 0x00}, \
  {0x3703, 0x19, 0x00}, \
  {0x3704, 0x10, 0x00}, \
  {0x3705, 0x00, 0x00}, \
  {0x3706, 0x66, 0x00}, \
  {0x3707, 0x08, 0x00}, \
  {0x3708, 0x34, 0x00}, \
  {0x3709, 0x40, 0x00}, \
  {0x370a, 0x01, 0x00}, \
  {0x370b, 0x1b, 0x00}, \
  {0x3714, 0x24, 0x00}, \
  {0x371a, 0x3e, 0x00}, \
  {0x3733, 0x00, 0x00}, \
  {0x3734, 0x00, 0x00}, \
  {0x373a, 0x05, 0x00}, \
  {0x373b, 0x06, 0x00}, \
  {0x373c, 0x0a, 0x00}, \
  {0x373f, 0xa0, 0x00}, \
  {0x3755, 0x00, 0x00}, \
  {0x3758, 0x00, 0x00}, \
  {0x375b, 0x0e, 0x00}, \
  {0x3766, 0x5f, 0x00}, \
  {0x3768, 0x00, 0x00}, \
  {0x3769, 0x22, 0x00}, \
  {0x3773, 0x08, 0x00}, \
  {0x3774, 0x1f, 0x00}, \
  {0x3776, 0x06, 0x00}, \
  {0x37a0, 0x88, 0x00}, \
  {0x37a1, 0x5c, 0x00}, \
  {0x37a7, 0x88, 0x00}, \
  {0x37a8, 0x70, 0x00}, \
  {0x37aa, 0x88, 0x00}, \
  {0x37ab, 0x48, 0x00}, \
  {0x37b3, 0x66, 0x00}, \
  {0x37c2, 0x04, 0x00}, \
  {0x37c5, 0x00, 0x00}, \
  {0x37c8, 0x00, 0x00}, \
  {0x3800, 0x00, 0x00}, \
  {0x3801, 0x0c, 0x00}, \
  {0x3802, 0x00, 0x00}, \
  {0x3803, 0x04, 0x00}, \
  {0x3804, 0x0a, 0x00}, \
  {0x3805, 0x33, 0x00}, \
  {0x3806, 0x07, 0x00}, \
  {0x3807, 0xa3, 0x00}, \
  {0x3808, 0x05, 0x00}, \
  {0x3809, 0x10, 0x00}, \
  {0x380a, 0x03, 0x00}, \
  {0x380b, 0xc0, 0x00}, \
  {0x380c, 0x06, 0x00}, \
  {0x380d, 0x90, 0x00}, \
  {0x380e, 0x07, 0x00}, \
  {0x380f, 0xf6, 0x00}, \
  {0x3811, 0x04, 0x00}, \
  {0x3813, 0x02, 0x00}, \
  {0x3814, 0x03, 0x00}, \
  {0x3815, 0x01, 0x00}, \
  {0x3816, 0x00, 0x00}, \
  {0x3817, 0x00, 0x00}, \
  {0x3818, 0x00, 0x00}, \
  {0x3819, 0x00, 0x00}, \
  {0x3820, 0x90, 0x00}, \
  {0x3821, 0x47, 0x00}, \
  {0x3822, 0x48, 0x00}, \
  {0x3826, 0x00, 0x00}, \
  {0x3827, 0x08, 0x00}, \
  {0x382a, 0x03, 0x00}, \
  {0x382b, 0x01, 0x00}, \
  {0x3830, 0x08, 0x00}, \
  {0x3836, 0x02, 0x00}, \
  {0x3837, 0x00, 0x00}, \
  {0x3838, 0x10, 0x00}, \
  {0x3841, 0xff, 0x00}, \
  {0x3846, 0x48, 0x00}, \
  {0x3861, 0x00, 0x00}, \
  {0x3862, 0x04, 0x00}, \
  {0x3863, 0x06, 0x00}, \
  {0x3a11, 0x01, 0x00}, \
  {0x3a12, 0x78, 0x00}, \
  {0x3b00, 0x00, 0x00}, \
  {0x3b02, 0x00, 0x00}, \
  {0x3b03, 0x00, 0x00}, \
  {0x3b04, 0x00, 0x00}, \
  {0x3b05, 0x00, 0x00}, \
  {0x3c00, 0x89, 0x00}, \
  {0x3c01, 0xab, 0x00}, \
  {0x3c02, 0x01, 0x00}, \
  {0x3c03, 0x00, 0x00}, \
  {0x3c04, 0x00, 0x00}, \
  {0x3c05, 0x03, 0x00}, \
  {0x3c06, 0x00, 0x00}, \
  {0x3c07, 0x05, 0x00}, \
  {0x3c0c, 0x00, 0x00}, \
  {0x3c0d, 0x00, 0x00}, \
  {0x3c0e, 0x00, 0x00}, \
  {0x3c0f, 0x00, 0x00}, \
  {0x3c40, 0x00, 0x00}, \
  {0x3c41, 0xa3, 0x00}, \
  {0x3c43, 0x7d, 0x00}, \
  {0x3c45, 0xd7, 0x00}, \
  {0x3c47, 0xfc, 0x00}, \
  {0x3c50, 0x05, 0x00}, \
  {0x3c52, 0xaa, 0x00}, \
  {0x3c54, 0x71, 0x00}, \
  {0x3c56, 0x80, 0x00}, \
  {0x3d85, 0x17, 0x00}, \
  {0x3f03, 0x00, 0x00}, \
  {0x3f0a, 0x00, 0x00}, \
  {0x3f0b, 0x00, 0x00}, \
  {0x4001, 0x60, 0x00}, \
  {0x4009, 0x05, 0x00}, \
  {0x4020, 0x00, 0x00}, \
  {0x4021, 0x00, 0x00}, \
  {0x4022, 0x00, 0x00}, \
  {0x4023, 0x00, 0x00}, \
  {0x4024, 0x00, 0x00}, \
  {0x4025, 0x00, 0x00}, \
  {0x4026, 0x00, 0x00}, \
  {0x4027, 0x00, 0x00}, \
  {0x4028, 0x00, 0x00}, \
  {0x4029, 0x00, 0x00}, \
  {0x402a, 0x00, 0x00}, \
  {0x402b, 0x00, 0x00}, \
  {0x402c, 0x00, 0x00}, \
  {0x402d, 0x00, 0x00}, \
  {0x402e, 0x00, 0x00}, \
  {0x402f, 0x00, 0x00}, \
  {0x4040, 0x00, 0x00}, \
  {0x4041, 0x03, 0x00}, \
  {0x4042, 0x00, 0x00}, \
  {0x4043, 0x7a, 0x00}, \
  {0x4044, 0x00, 0x00}, \
  {0x4045, 0x7a, 0x00}, \
  {0x4046, 0x00, 0x00}, \
  {0x4047, 0x7a, 0x00}, \
  {0x4048, 0x00, 0x00}, \
  {0x4049, 0x80, 0x00}, \
  {0x4303, 0x00, 0x00}, \
  {0x4307, 0x30, 0x00}, \
  {0x4500, 0x58, 0x00}, \
  {0x4501, 0x04, 0x00}, \
  {0x4502, 0x44, 0x00}, \
  {0x4503, 0x10, 0x00}, \
  {0x4508, 0x55, 0x00}, \
  {0x4509, 0x55, 0x00}, \
  {0x450a, 0x00, 0x00}, \
  {0x450b, 0x00, 0x00}, \
  {0x4600, 0x00, 0x00}, \
  {0x4601, 0x81, 0x00}, \
  {0x4700, 0xa4, 0x00}, \
  {0x4800, 0x4c, 0x00}, \
  {0x4816, 0x53, 0x00}, \
  {0x481f, 0x40, 0x00}, \
  {0x4837, 0x13, 0x00}, \
  {0x5000, 0x56, 0x00}, \
  {0x5001, 0x01, 0x00}, \
  {0x5002, 0x28, 0x00}, \
  {0x5004, 0x0c, 0x00}, \
  {0x5006, 0x0c, 0x00}, \
  {0x5007, 0xe0, 0x00}, \
  {0x5008, 0x01, 0x00}, \
  {0x5009, 0xb0, 0x00}, \
  {0x5901, 0x00, 0x00}, \
  {0x5a01, 0x00, 0x00}, \
  {0x5a03, 0x00, 0x00}, \
  {0x5a04, 0x0c, 0x00}, \
  {0x5a05, 0xe0, 0x00}, \
  {0x5a06, 0x09, 0x00}, \
  {0x5a07, 0xb0, 0x00}, \
  {0x5a08, 0x06, 0x00}, \
  {0x5e00, 0x00, 0x00}, \
  {0x3618, 0x2a, 0x00}, \
  {0x3734, 0x40, 0x00}, \
  {0x5b00, 0x01, 0x00}, \
  {0x5b01, 0x10, 0x00}, \
  {0x5b02, 0x01, 0x00}, \
  {0x5b03, 0xDB, 0x00}, \
  {0x3d8c, 0x71, 0x00}, \
  {0x3d8d, 0xEA, 0x00}, \
  {0x4017, 0x10, 0x00}, \
  {0x5780, 0x3e, 0x00}, \
  {0x5781, 0x0f, 0x00}, \
  {0x5782, 0x44, 0x00}, \
  {0x5783, 0x02, 0x00}, \
  {0x5784, 0x01, 0x00}, \
  {0x5785, 0x01, 0x00}, \
  {0x5786, 0x00, 0x00}, \
  {0x5787, 0x04, 0x00}, \
  {0x5788, 0x02, 0x00}, \
  {0x5789, 0x0f, 0x00}, \
  {0x578a, 0xfd, 0x00}, \
  {0x578b, 0xf5, 0x00}, \
  {0x578c, 0xf5, 0x00}, \
  {0x578d, 0x03, 0x00}, \
  {0x578e, 0x08, 0x00}, \
  {0x578f, 0x0c, 0x00}, \
  {0x5790, 0x08, 0x00}, \
  {0x5791, 0x04, 0x00}, \
  {0x5792, 0x00, 0x00}, \
  {0x5793, 0x52, 0x00}, \
  {0x5794, 0xa3, 0x00}, \
  {0x3503, 0x30, 0x00}, \
  {0x3d85, 0x17, 0x00}, \
  {0x3655, 0x20, 0x00}, \
  {0x3002, 0x61, 0x00}, \
  {0x3010, 0x40, 0x00}, \
  {0x300d, 0x00, 0x00}, \
  {0x5045, 0x05, 0x00}, \
  {0x5048, 0x10, 0x00}, \
}

#define RES0_REG_ARRAY \
{ \
  {0x3501, 0x7b, 0x00}, \
  {0x3623, 0x00, 0x00}, \
  {0x366e, 0x10, 0x00}, \
  {0x370b, 0x1b, 0x00}, \
  {0x3808, 0x0a, 0x00}, \
  {0x3809, 0x20, 0x00}, \
  {0x380a, 0x07, 0x00}, \
  {0x380b, 0x98, 0x00}, \
  {0x380c, 0x06, 0x00}, \
  {0x380d, 0x8c, 0x00}, \
  {0x380e, 0x07, 0x00}, \
  {0x380f, 0xfd, 0x00}, \
  {0x3814, 0x01, 0x00}, \
  {0x3820, 0x80, 0x00}, \
  {0x3821, 0x46, 0x00}, \
  {0x382a, 0x01, 0x00}, \
  {0x4009, 0x0d, 0x00}, \
  {0x400a, 0x02, 0x00}, \
  {0x400b, 0x00, 0x00}, \
  {0x4508, 0xaa, 0x00}, \
  {0x4509, 0xaa, 0x00}, \
  {0x450a, 0x00, 0x00}, \
  {0x4600, 0x01, 0x00}, \
  {0x4601, 0x03, 0x00}, \
  {0x4017, 0x08, 0x00}, \
}

#define RES1_REG_ARRAY \
{ \
  {0x3501, 0x3d, 0x00}, \
  {0x3623, 0x00, 0x00}, \
  {0x366e, 0x08, 0x00}, \
  {0x370b, 0x1b, 0x00}, \
  {0x3808, 0x05, 0x00}, \
  {0x3809, 0x10, 0x00}, \
  {0x380a, 0x03, 0x00}, \
  {0x380b, 0xcc, 0x00}, \
  {0x380c, 0x06, 0x00}, \
  {0x380d, 0x8c, 0x00}, \
  {0x380e, 0x07, 0x00}, \
  {0x380f, 0xfd, 0x00}, \
  {0x3814, 0x03, 0x00}, \
  {0x3820, 0x90, 0x00}, \
  {0x3821, 0x47, 0x00}, \
  {0x382a, 0x03, 0x00}, \
  {0x4009, 0x05, 0x00}, \
  {0x400a, 0x02, 0x00}, \
  {0x400b, 0x00, 0x00}, \
  {0x4508, 0x55, 0x00}, \
  {0x4509, 0x55, 0x00}, \
  {0x450a, 0x00, 0x00}, \
  {0x4600, 0x00, 0x00}, \
  {0x4601, 0x81, 0x00}, \
  {0x4017, 0x10, 0x00}, \
}

#define RES2_REG_ARRAY \
{ \
  {0x3501, 0x3d, 0x00}, \
  {0x3623, 0x00, 0x00}, \
  {0x366e, 0x08, 0x00}, \
  {0x370b, 0x1b, 0x00}, \
  {0x3808, 0x05, 0x00}, \
  {0x3809, 0x10, 0x00}, \
  {0x380a, 0x03, 0x00}, \
  {0x380b, 0xc0, 0x00}, \
  {0x380c, 0x06, 0x00}, \
  {0x380d, 0xc0, 0x00}, \
  {0x380e, 0x03, 0x00}, \
  {0x380f, 0xe0, 0x00}, \
  {0x3814, 0x03, 0x00}, \
  {0x3820, 0x90, 0x00}, \
  {0x3821, 0x47, 0x00}, \
  {0x382a, 0x03, 0x00}, \
  {0x4009, 0x05, 0x00}, \
  {0x400a, 0x02, 0x00}, \
  {0x400b, 0x00, 0x00}, \
  {0x4508, 0x55, 0x00}, \
  {0x4509, 0x55, 0x00}, \
  {0x450a, 0x00, 0x00}, \
  {0x4600, 0x00, 0x00}, \
  {0x4601, 0x81, 0x00}, \
  {0x4017, 0x10, 0x00}, \
}

#define RES3_REG_ARRAY \
{ \
  {0x3501, 0x1f, 0x00}, \
  {0x3623, 0x04, 0x00}, \
  {0x366e, 0x08, 0x00}, \
  {0x370b, 0x1b, 0x00}, \
  {0x3808, 0x02, 0x00}, \
  {0x3809, 0x80, 0x00}, \
  {0x380a, 0x01, 0x00}, \
  {0x380b, 0xe0, 0x00}, \
  {0x380c, 0x06, 0x00}, \
  {0x380d, 0x8c, 0x00}, \
  {0x380e, 0x02, 0x00}, \
  {0x380f, 0xa0, 0x00}, \
  {0x3814, 0x07, 0x00}, \
  {0x3820, 0x90, 0x00}, \
  {0x3821, 0xc6, 0x00}, \
  {0x382a, 0x07, 0x00}, \
  {0x4009, 0x05, 0x00}, \
  {0x400a, 0x02, 0x00}, \
  {0x400b, 0x00, 0x00}, \
  {0x4508, 0x55, 0x00}, \
  {0x4509, 0x55, 0x00}, \
  {0x450a, 0x03, 0x00}, \
  {0x4600, 0x00, 0x00}, \
  {0x4601, 0x40, 0x00}, \
  {0x4017, 0x10, 0x00}, \
}

#define RES4_REG_ARRAY \
{ \
  {0x3501, 0x1f, 0x00}, \
  {0x3623, 0x04, 0x00}, \
  {0x366e, 0x08, 0x00}, \
  {0x370b, 0x1b, 0x00}, \
  {0x3808, 0x02, 0x00}, \
  {0x3809, 0x80, 0x00}, \
  {0x380a, 0x01, 0x00}, \
  {0x380b, 0xe0, 0x00}, \
  {0x380c, 0x06, 0x00}, \
  {0x380d, 0x8c, 0x00}, \
  {0x380e, 0x02, 0x00}, \
  {0x380f, 0x00, 0x00}, \
  {0x3814, 0x07, 0x00}, \
  {0x3820, 0x90, 0x00}, \
  {0x3821, 0xc6, 0x00}, \
  {0x382a, 0x07, 0x00}, \
  {0x4009, 0x05, 0x00}, \
  {0x400a, 0x02, 0x00}, \
  {0x400b, 0x00, 0x00}, \
  {0x4508, 0x55, 0x00}, \
  {0x4509, 0x55, 0x00}, \
  {0x450a, 0x03, 0x00}, \
  {0x4600, 0x00, 0x00}, \
  {0x4601, 0x40, 0x00}, \
  {0x4017, 0x10, 0x00}, \
}

static sensor_lib_t sensor_lib_ptr =
{
  .sensor_slave_info =
  {
    .sensor_name = SENSOR_MODEL,
    .slave_addr = 0x6C,
    .i2c_freq_mode = SENSOR_I2C_MODE_FAST,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .sensor_id_info =
    {
      .sensor_id_reg_addr = 0x300b,
      .sensor_id = 0x5670,
    },
    .power_setting_array =
    {
      .power_setting_a =
      {
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VIO,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VANA,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VDIG,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_CLK,
          .seq_val = CAMERA_MCLK,
          .config_val = 24000000,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_STANDBY,
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_RESET,
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_STANDBY,
          .config_val = GPIO_OUT_HIGH,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_RESET,
          .config_val = GPIO_OUT_HIGH,
          .delay = 1,
        },
      },
      .size = 8,
      .power_down_setting_a =
      {
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_STANDBY,
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_RESET,
          .config_val = GPIO_OUT_LOW,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_CLK,
          .seq_val = CAMERA_MCLK,
          .config_val = 0,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VDIG,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VANA,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VIO,
          .config_val = 0,
          .delay = 0,
        },
      },
      .size_down = 6,
    },
  },
  .sensor_output =
  {
    .output_format = SENSOR_BAYER,
    .connection_mode = SENSOR_MIPI_CSI,
    .raw_output = SENSOR_10_BIT_DIRECT,
    .filter_arrangement = SENSOR_BGGR,
  },
  .output_reg_addr =
  {
    .x_output = 0x3808,
    .y_output = 0x380a,
    .line_length_pclk = 0x380c,
    .frame_length_lines = 0x380e,
  },
  .exp_gain_info =
  {
    .coarse_int_time_addr = 0x3500,
    .global_gain_addr = 0x3508,
    .vert_offset = 4,
  },
  .aec_info =
  {
    .min_gain = 1.0,
    .max_gain = MAX_GAIN,
    .max_analog_gain = MAX_ANALOG_GAIN,
    .max_linecount = 26880,
  },
  .sensor_num_frame_skip = 2,
  .sensor_num_HDR_frame_skip = 2,
  .sensor_max_pipeline_frame_delay = 2,
  .sensor_property =
  {
    .pix_size = 1.12,
    .sensing_method = SENSOR_SMETHOD_ONE_CHIP_COLOR_AREA_SENSOR,
    .crop_factor = 1.0,
  },
  .pixel_array_size_info =
  {
    .active_array_size =
    {
      .width = 2592,
      .height = 1944,
    },
    .left_dummy = 0,
    .right_dummy = 0,
    .top_dummy = 0,
    .bottom_dummy = 0,
  },
  .color_level_info =
  {
    .white_level = 1023,
    .r_pedestal = 64,
    .gr_pedestal = 64,
    .gb_pedestal = 64,
    .b_pedestal = 64,
  },
  .sensor_stream_info_array =
  {
    .sensor_stream_info =
    {
      {
        .vc_cfg_size = 1,
        .vc_cfg =
        {
          {
            .cid = 0,
            .dt = CSI_RAW10,
            .decode_format = CSI_DECODE_10BIT
          },
        },
        .pix_data_fmt =
        {
          SENSOR_BAYER,
        },
      },
    },
    .size = 1,
  },
  .start_settings =
  {
    .reg_setting_a = START_REG_ARRAY,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .data_type = CAMERA_I2C_BYTE_DATA,
    .delay = 0,
  },
  .stop_settings =
  {
    .reg_setting_a = STOP_REG_ARRAY,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .data_type = CAMERA_I2C_BYTE_DATA,
    .delay = 0,
  },
  .groupon_settings =
  {
    .reg_setting_a = GROUPON_REG_ARRAY,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .data_type = CAMERA_I2C_BYTE_DATA,
    .delay = 0,
  },
  .groupoff_settings =
  {
    .reg_setting_a = GROUPOFF_REG_ARRAY,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .data_type = CAMERA_I2C_BYTE_DATA,
    .delay = 0,
  },
  .embedded_data_enable_settings =
  {
    .reg_setting_a = {},
    .addr_type = 0,
    .data_type = 0,
    .delay = 0,
  },
  .embedded_data_disable_settings =
  {
    .reg_setting_a = {},
    .addr_type = 0,
    .data_type = 0,
    .delay = 0,
  },
  .test_pattern_info =
  {
    .test_pattern_settings =
    {
      {
        .mode = SENSOR_TEST_PATTERN_OFF,
        .settings =
        {
          .reg_setting_a =
           {
             {0x4303, 0x00, 0x00},
             {0x4320, 0x80, 0x00}
           },
          .addr_type = CAMERA_I2C_WORD_ADDR,
          .data_type = CAMERA_I2C_BYTE_DATA,
          .delay = 0,
        },
      },
      {
        .mode = SENSOR_TEST_PATTERN_SOLID_COLOR,
        .settings =
        {
          .reg_setting_a =
           {
             {0x4303, 0x00, 0x00},
             {0x4320, 0x82, 0x00}
           },
          .addr_type = CAMERA_I2C_WORD_ADDR,
          .data_type = CAMERA_I2C_BYTE_DATA,
          .delay = 0,
        },
      },
      {
        .mode = SENSOR_TEST_PATTERN_COLOR_BARS,
        .settings =
        {
          .reg_setting_a =
           {
             {0x4320, 0x80, 0x00},
             {0x4303, 0x08, 0x00}
           },
          .addr_type = CAMERA_I2C_WORD_ADDR,
          .data_type = CAMERA_I2C_BYTE_DATA,
          .delay = 0,
        },
      },
    },
    .size = 4,
    .solid_mode_addr =
    {
      .r_addr = 0x4327,
      .gr_addr = 0x4329,
      .gb_addr = 0x4327,
      .b_addr = 0x4323,
    },
  },
  .init_settings_array =
  {
    .reg_settings =
    {
      {
        .reg_setting_a = INIT0_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_BYTE_DATA,
        .delay = 60,
      },
    },
    .size = 1,
  },
  .res_settings_array =
  {
    .reg_settings =
    {
      /* Res 0 */
      {
        .reg_setting_a = RES0_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_BYTE_DATA,
        .delay = 0,
      },
      /* Res 1 */
      {
        .reg_setting_a = RES1_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_BYTE_DATA,
        .delay = 0,
      },
      /* Res 2 */
      {
        .reg_setting_a = RES2_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_BYTE_DATA,
        .delay = 0,
      },
      /* Res 3 */
      {
        .reg_setting_a = RES3_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_BYTE_DATA,
        .delay = 0,
      },
      /* Res 4 */
      {
        .reg_setting_a = RES4_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_BYTE_DATA,
        .delay = 0,
      },
    },
    .size = 5,
  },
  .out_info_array =
  {
    .out_info =
    {
      /* Res 0 */
      {
        .x_output = 2592,
        .y_output = 1944,
        .line_length_pclk = 1676,
        .frame_length_lines = 2045,
        .op_pixel_clk = 168000000,
        .binning_factor = 1,
        .min_fps = 7.5,
        .max_fps = 30.0,
        .mode = SENSOR_DEFAULT_MODE,
        .offset_x = 0,
        .offset_y = 0,
        .scale_factor = 0,
      },
      /* Res 1 */
      {
        .x_output = 1296,
        .y_output = 972,
        .line_length_pclk = 1676,
        .frame_length_lines = 2045,
        .op_pixel_clk = 168000000,
        .binning_factor = 1,
        .min_fps = 7.5,
        .max_fps = 30.0,
        .mode = SENSOR_DEFAULT_MODE,
        .offset_x = 0,
        .offset_y = 0,
        .scale_factor = 0,
      },
      /* Res 2 */
      {
        .x_output = 1296,
        .y_output = 960,
        .line_length_pclk = 1728,
        .frame_length_lines = 992,
        .op_pixel_clk = 168000000,
        .binning_factor = 1,
        .min_fps = 7.5,
        .max_fps = 60.0,
        .mode = SENSOR_HFR_MODE,
        .offset_x = 0,
        .offset_y = 0,
        .scale_factor = 0,
      },
      /* Res 3 */
      {
        .x_output = 640,
        .y_output = 480,
        .line_length_pclk = 1676,
        .frame_length_lines = 672,
        .op_pixel_clk = 168000000,
        .binning_factor = 1,
        .min_fps = 7.5,
        .max_fps = 90.0,
        .mode = SENSOR_HFR_MODE,
        .offset_x = 0,
        .offset_y = 0,
        .scale_factor = 0,
      },
      /* Res 4 */
      {
        .x_output = 640,
        .y_output = 480,
        .line_length_pclk = 1676,
        .frame_length_lines = 512,
        .op_pixel_clk = 168000000,
        .binning_factor = 1,
        .min_fps = 7.5,
        .max_fps = 120.0,
        .mode = SENSOR_HFR_MODE,
        .offset_x = 0,
        .offset_y = 0,
        .scale_factor = 0,
      },
    },
    .size = 5,
  },
  .csi_params =
  {
    .lane_cnt = 2,
    .settle_cnt = 0x15,
    .is_csi_3phase = 0,
  },
  .csid_lut_params_array =
  {
    .lut_params =
    {
      /* Res 0 */
      {
        .num_cid = 1,
        .vc_cfg_a =
        {
          {
            .cid = 0,
            .dt = CSI_RAW10,
            .decode_format = CSI_DECODE_10BIT
          },
        },
      },
      /* Res 1 */
      {
        .num_cid = 1,
        .vc_cfg_a =
        {
          {
            .cid = 0,
            .dt = CSI_RAW10,
            .decode_format = CSI_DECODE_10BIT
          },
        },
      },
      /* Res 2 */
      {
        .num_cid = 1,
        .vc_cfg_a =
        {
          {
            .cid = 0,
            .dt = CSI_RAW10,
            .decode_format = CSI_DECODE_10BIT
          },
        },
      },
      /* Res 3 */
      {
        .num_cid = 1,
        .vc_cfg_a =
        {
          {
            .cid = 0,
            .dt = CSI_RAW10,
            .decode_format = CSI_DECODE_10BIT
          },
        },
      },
      /* Res 4 */
      {
        .num_cid = 1,
        .vc_cfg_a =
        {
          {
            .cid = 0,
            .dt = CSI_RAW10,
            .decode_format = CSI_DECODE_10BIT
          },
        },
      },
    },
    .size = 5,
  },
  .crop_params_array =
  {
    .crop_params =
    {
      /* Res 0 */
      {
        .top_crop = 0,
        .bottom_crop = 0,
        .left_crop = 0,
        .right_crop = 0,
      },
      /* Res 1 */
      {
        .top_crop = 0,
        .bottom_crop = 0,
        .left_crop = 0,
        .right_crop = 0,
      },
      /* Res 2 */
      {
        .top_crop = 0,
        .bottom_crop = 0,
        .left_crop = 0,
        .right_crop = 0,
      },
      /* Res 3 */
      {
        .top_crop = 0,
        .bottom_crop = 0,
        .left_crop = 0,
        .right_crop = 0,
      },
      /* Res 4 */
      {
        .top_crop = 0,
        .bottom_crop = 0,
        .left_crop = 0,
        .right_crop = 0,
      },
    },
    .size = 5,
  },
  .exposure_func_table =
  {
    .sensor_calculate_exposure = sensor_calculate_exposure,
    .sensor_fill_exposure_array = sensor_fill_exposure_array,
  },
  .meta_data_out_info_array =
  {
    .meta_data_out_info =
    {
      {
        .width = 0,
        .height = 0,
        .stats_type = 0,
      },
    },
    .size = 0,
  },
  .rolloff_config =
  {
    .enable = FALSE,
    .full_size_info =
    {
      .full_size_width = 0,
      .full_size_height = 0,
      .full_size_left_crop = 0,
      .full_size_top_crop = 0,
    },
  },
  .adc_readout_time = 0,
  .app_delay = {
    [SENSOR_DELAY_ANALOG_SENSOR_GAIN] = 1,
  },
  .noise_coeff = {
    .gradient_S = 3.738032e-06,
    .offset_S = 3.651935e-04,
    .gradient_O = 4.499952e-07,
    .offset_O = -2.968624e-04,
  },
};

#endif
