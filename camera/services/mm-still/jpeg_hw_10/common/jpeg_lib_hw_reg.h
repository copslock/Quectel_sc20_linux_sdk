/*============================================================================

   Copyright (c) 2012-2015 Qualcomm Technologies, Inc.  All Rights Reserved.
   Qualcomm Technologies Proprietary and Confidential.

============================================================================*/

#ifndef JPEG_HW_REG_H
#define JPEG_HW_REG_H


#define JPEG_BASE                                                                                      (0x00000000)

#define JPEG_HW_VERSION_ADDR                                                                              (0x00000000)
#define   JPEG_HW_VERSION___RWC                                                                           QCSR_REG_RO
#define   JPEG_HW_VERSION___POR                                                                        0x10000000
#define   JPEG_HW_VERSION__MAJOR_BMSK                                                                   0xF0000000
#define   JPEG_HW_VERSION__MAJOR_SHFT                                                                               28
#define   JPEG_HW_VERSION__MINOR_BMSK                                                                   0x0FFF0000
#define   JPEG_HW_VERSION__MINOR_SHFT                                                                               16
#define   JPEG_HW_VERSION__STEP_BMSK                                                                    0x0000FFFF
#define   JPEG_HW_VERSION__STEP_SHFT                                                                                 0
#define   JPEG_HW_VERSION_BMSK                                                                          0xFFFFFFFF
#define   JPEG_HW_VERSION_SHFT                                                                                       0

#define JPEG_JPEG_HW_CAPABILITY_ADDR                                                                           (0x00000004)
#define   JPEG_HW_CAPABILITY___RWC                                                                        QCSR_REG_RO
#define   JPEG_HW_CAPABILITY___POR                                                                     0x00000001
#define   JPEG_HW_CAPABILITY__DOWNSCALE_BMSK                                                            0x00000700
#define   JPEG_HW_CAPABILITY__DOWNSCALE_SHFT                                                                         8
#define   JPEG_HW_CAPABILITY__UPSCALE_BMSK                                                              0x00000070
#define   JPEG_HW_CAPABILITY__UPSCALE_SHFT                                                                           4
#define   JPEG_HW_CAPABILITY__DECODE_BMSK                                                               0x00000002
#define   JPEG_HW_CAPABILITY__DECODE_SHFT                                                                            1
#define   JPEG_HW_CAPABILITY__ENCODE_BMSK                                                               0x00000001
#define   JPEG_HW_CAPABILITY__ENCODE_SHFT                                                                            0
#define   JPEG_HW_CAPABILITY_BMSK                                                                       0x000007FF
#define   JPEG_HW_CAPABILITY_SHFT                                                                                    0

#define  JPEG_RESET_CMD_ADDR                                                                               (0x00000008)
#define  JPEG_RESET_CMD_RMSK                                                                            (0xA00320F7)
#define   JPEG_RESET_CMD___RWC                                                                            QCSR_REG_WO
#define   JPEG_RESET_CMD___POR                                                                         0x00000000
#define   JPEG_RESET_CMD__RESET_BYPASS_BMSK                                                             0x80000000
#define   JPEG_RESET_CMD__RESET_BYPASS_SHFT                                                                         31
#define   JPEG_RESET_CMD__JPEG_DOMAIN_RESET_BMSK                                                        0x20000000
#define   JPEG_RESET_CMD__JPEG_DOMAIN_RESET_SHFT                                                                    29
#define   JPEG_RESET_CMD__CORE_RESET_BMSK                                                               0x00020000
#define   JPEG_RESET_CMD__CORE_RESET_SHFT                                                                           17
#define   JPEG_RESET_CMD__MISR_RESET_BMSK                                                               0x00010000
#define   JPEG_RESET_CMD__MISR_RESET_SHFT                                                                           16
#define   JPEG_RESET_CMD__REGISTER_RESET_BMSK                                                           0x00002000
#define   JPEG_RESET_CMD__REGISTER_RESET_SHFT                                                                       13
#define   JPEG_RESET_CMD__SCALE_RESET_BMSK                                                              0x00000080
#define   JPEG_RESET_CMD__SCALE_RESET_SHFT                                                                           7
#define   JPEG_RESET_CMD__BLOCK_FORMATTER_RESET_BMSK                                                    0x00000040
#define   JPEG_RESET_CMD__BLOCK_FORMATTER_RESET_SHFT                                                                 6
#define   JPEG_RESET_CMD__DECODER_RESET_BMSK                                                            0x00000020
#define   JPEG_RESET_CMD__DECODER_RESET_SHFT                                                                         5
#define   JPEG_RESET_CMD__ENCODER_RESET_BMSK                                                            0x00000010
#define   JPEG_RESET_CMD__ENCODER_RESET_SHFT                                                                         4
#define   JPEG_RESET_CMD__INLINE_INTERFACE_RESET_BMSK                                                   0x00000004
#define   JPEG_RESET_CMD__INLINE_INTERFACE_RESET_SHFT                                                                2
#define   JPEG_RESET_CMD__WE_RESET_BMSK                                                                 0x00000002
#define   JPEG_RESET_CMD__WE_RESET_SHFT                                                                              1
#define   JPEG_RESET_CMD__FE_RESET_BMSK                                                                 0x00000001
#define   JPEG_RESET_CMD__FE_RESET_SHFT                                                                              0
#define   JPEG_RESET_CMD_BMSK                                                                           0xFFFFFFFF
#define   JPEG_RESET_CMD_SHFT                                                                                        0

#define JPEG_JPEG_CORE_CFG_ADDR                                                                                (0x0000000C)
#define   JPEG_CORE_CFG___RWC                                                                             QCSR_REG_RW
#define   JPEG_CORE_CFG___POR                                                                          0x00000000
#define   JPEG_CORE_CFG__MODE_BMSK                                                                      0x07000000
#define   JPEG_CORE_CFG__MODE_SHFT                                                                                  24
#define   JPEG_CORE_CFG__MODE__IN_LINE_JPEG_ENCODE                                                                0x0
#define   JPEG_CORE_CFG__MODE__OFFLINE_JPEG_ENCODE                                                                0x1
#define   JPEG_CORE_CFG__MODE__JPEG_DECODE                                                                        0x2
#define   JPEG_CORE_CFG__INLINE_AUTO_RESYNC_EN_BMSK                                              0x00100000
#define   JPEG_CORE_CFG__INLINE_AUTO_RESYNC_EN_SHFT                                              20
#define   JPEG_CORE_CFG__INLINE_AUTO_RESYNC_EN__NO_RESYNC_ON_SOF                                0x0
#define   JPEG_CORE_CFG__INLINE_AUTO_RESYNC_EN__RESYNC_ON_SOF                                   0x1
#define   JPEG_CORE_CFG__TESTBUS_ENABLE_BMSK                                                            0x00080000
#define   JPEG_CORE_CFG__TESTBUS_ENABLE_SHFT                                                                        19
#define   JPEG_CORE_CFG__TESTBUS_ENABLE__TESTBUS_DISABLED                                                         0x0
#define   JPEG_CORE_CFG__TESTBUS_ENABLE__TESTBUS_ENABLED                                                          0x1
#define   JPEG_CORE_CFG__BLOCK_FORMATTER_OUTPUT_BMSK                                                    0x00020000
#define   JPEG_CORE_CFG__BLOCK_FORMATTER_OUTPUT_SHFT                                                                17
#define   JPEG_CORE_CFG__BLOCK_FORMATTER_OUTPUT_DISABLED                                                          0x0
#define   JPEG_CORE_CFG__BLOCK_FORMATTER_OUTPUT_ENABLED                                                           0x1
#define   JPEG_CORE_CFG__SCALE_INPUT_SEL_BMSK                                                           0x00010000
#define   JPEG_CORE_CFG__SCALE_INPUT_SEL_SHFT                                                                       16
#define   JPEG_CORE_CFG__SCALE_ENABLE_BMSK                                                              0x00000080
#define   JPEG_CORE_CFG__SCALE_ENABLE_SHFT                                                                           7
#define   JPEG_CORE_CFG__SCALE_ENABLE__SCALE_DISABLED                                                             0x0
#define   JPEG_CORE_CFG__SCALE_ENABLE__SCALE_ENABLED                                                              0x1
#define   JPEG_CORE_CFG__BLOCK_FORMATTER_ENABLE_BMSK                                                    0x00000040
#define   JPEG_CORE_CFG__BLOCK_FORMATTER_ENABLE_SHFT                                                                 6
#define   JPEG_CORE_CFG__BLOCK_FORMATTER_ENABLE__BF_DISABLED                                                      0x0
#define   JPEG_CORE_CFG__BLOCK_FORMATTER_ENABLE__BF_ENABLED                                                       0x1
#define   JPEG_CORE_CFG__JPEG_DECODE_ENABLE_BMSK                                                        0x00000020
#define   JPEG_CORE_CFG__JPEG_DECODE_ENABLE_SHFT                                                                     5
#define   JPEG_CORE_CFG__JPEG_DECODE_ENABLE__JPEG_DECODE_DISABLED                                                 0x0
#define   JPEG_CORE_CFG__JPEG_DECODE_ENABLE__JPEG_DECODE_ENABLED                                                  0x1
#define   JPEG_CORE_CFG__JPEG_ENCODE_ENABLE_BMSK                                                        0x00000010
#define   JPEG_CORE_CFG__JPEG_ENCODE_ENABLE_SHFT                                                                     4
#define   JPEG_CORE_CFG__JPEG_ENCODE_ENABLE__JPEG_ENCODE_DISABLED                                                 0x0
#define   JPEG_CORE_CFG__JPEG_ENCODE_ENABLE__JPEG_ENCODE_ENABLED                                                  0x1
#define   JPEG_CORE_CFG__BRIDGE_ENABLE_BMSK                                                             0x00000008
#define   JPEG_CORE_CFG__BRIDGE_ENABLE_SHFT                                                                          3
#define   JPEG_CORE_CFG__BRIDGE_ENABLE__BRIDGE_INTERFACE_DISABLED                                                 0x0
#define   JPEG_CORE_CFG__BRIDGE_ENABLE__BRIDGE_INTERFACE_ENABLED                                                  0x1
#define   JPEG_CORE_CFG__INLINE_INTERFACE_ENABLE_BMSK                                                   0x00000004
#define   JPEG_CORE_CFG__INLINE_INTERFACE_ENABLE_SHFT                                                                2
#define   JPEG_CORE_CFG__INLINE_INTERFACE_ENABLE__VFE_INTERFACE_DISABLED                                          0x0
#define   JPEG_CORE_CFG__INLINE_INTERFACE_ENABLE__VFE_INTERFACE_ENABLED                                           0x1
#define   JPEG_CORE_CFG__WE_ENABLE_BMSK                                                                 0x00000002
#define   JPEG_CORE_CFG__WE_ENABLE_SHFT                                                                              1
#define   JPEG_CORE_CFG__WE_ENABLE__WRITE_ENGINE_DISABLED                                                         0x0
#define   JPEG_CORE_CFG__WE_ENABLE__WRITE_ENGINE_ENABLED                                                          0x1
#define   JPEG_CORE_CFG__FE_ENABLE_BMSK                                                                 0x00000001
#define   JPEG_CORE_CFG__FE_ENABLE_SHFT                                                                              0
#define   JPEG_CORE_CFG__FE_ENABLE__FETCH_ENGINE_DISABLED                                                         0x0
#define   JPEG_CORE_CFG__FE_ENABLE__FETCH_ENGINE_ENABLED                                                          0x1
#define   JPEG_CORE_CFG_BMSK                                                                            0x07FFFFFF
#define   JPEG_CORE_CFG_SHFT                                                                                         0

#define JPEG_CMD_ADDR                                                                                     (0x00000010)
#define   JPEG_CMD___RWC                                                                                  QCSR_REG_WO
#define   JPEG_CMD___POR                                                                               0x00000000
#define   JPEG_CMD__APPLY_SWC_RD_PARAMS_BMSK                                                            0x00000800
#define   JPEG_CMD__APPLY_SWC_RD_PARAMS_SHFT                                                                        11
#define   JPEG_CMD__CLEAR_WR_PLN2_QUEUE_BMSK                                                            0x00000400
#define   JPEG_CMD__CLEAR_WR_PLN2_QUEUE_SHFT                                                                        10
#define   JPEG_CMD__CLEAR_WR_PLN1_QUEUE_BMSK                                                            0x00000200
#define   JPEG_CMD__CLEAR_WR_PLN1_QUEUE_SHFT                                                                         9
#define   JPEG_CMD__CLEAR_WR_PLN0_QUEUE_BMSK                                                            0x00000100
#define   JPEG_CMD__CLEAR_WR_PLN0_QUEUE_SHFT                                                                         8
#define   JPEG_CMD__CLEAR_RD_PLN2_QUEUE_BMSK                                                            0x00000040
#define   JPEG_CMD__CLEAR_RD_PLN2_QUEUE_SHFT                                                                         6
#define   JPEG_CMD__CLEAR_RD_PLN1_QUEUE_BMSK                                                            0x00000020
#define   JPEG_CMD__CLEAR_RD_PLN1_QUEUE_SHFT                                                                         5
#define   JPEG_CMD__CLEAR_RD_PLN0_QUEUE_BMSK                                                            0x00000010
#define   JPEG_CMD__CLEAR_RD_PLN0_QUEUE_SHFT                                                                         4
#define   JPEG_CMD__INLINE_STOP_BMSK                                                                    0x00000008
#define   JPEG_CMD__INLINE_STOP_SHFT                                                                                 3
#define   JPEG_CMD__INLINE_START_BMSK                                                                   0x00000004
#define   JPEG_CMD__INLINE_START_SHFT                                                                                2
#define   JPEG_CMD__HW_STOP_BMSK                                                                        0x00000002
#define   JPEG_CMD__HW_STOP_SHFT                                                                                     1
#define   JPEG_CMD__HW_START_BMSK                                                                       0x00000001
#define   JPEG_CMD__HW_START_SHFT                                                                                    0
#define   JPEG_CMD_BMSK                                                                                 0xFFFFFFFF
#define   JPEG_CMD_SHFT                                                                                              0

#define JPEG_CORE_STATE_STATUS_ADDR                                                                       (0x00000014)
#define   JPEG_CORE_STATE_STATUS___RWC                                                                    QCSR_REG_RO
#define   JPEG_CORE_STATE_STATUS___POR                                                                 0x00000000
#define   JPEG_CORE_STATE_STATUS__BUS_STATE_BMSK                                                        0x00000100
#define   JPEG_CORE_STATE_STATUS__BUS_STATE_SHFT                                                                     8
#define   JPEG_CORE_STATE_STATUS__REALTIME_STATE_BMSK                                                   0x00000010
#define   JPEG_CORE_STATE_STATUS__REALTIME_STATE_SHFT                                                                4
#define   JPEG_CORE_STATE_STATUS__SCALE_STATE_BMSK                                                      0x00000004
#define   JPEG_CORE_STATE_STATUS__SCALE_STATE_SHFT                                                                   2
#define   JPEG_CORE_STATE_STATUS__DECODE_STATE_BMSK                                                     0x00000002
#define   JPEG_CORE_STATE_STATUS__DECODE_STATE_SHFT                                                                  1
#define   JPEG_CORE_STATE_STATUS__ENCODE_STATE_BMSK                                                     0x00000001
#define   JPEG_CORE_STATE_STATUS__ENCODE_STATE_SHFT                                                                  0
#define   JPEG_CORE_STATE_STATUS_BMSK                                                                   0x000001FF
#define   JPEG_CORE_STATE_STATUS_SHFT                                                                                0

#define JPEG_IRQ_MASK_ADDR                                                                               (0x00000018)
#define   JPEG_IRQ_MASK___RWC                                                                             QCSR_REG_RW
#define   JPEG_IRQ_MASK___POR                                                                          0x00000200
#define   JPEG_IRQ_MASK__MASK_BMSK                                                                      0xFFFFFFFF
#define   JPEG_IRQ_MASK__MASK_SHFT                                                                                   0
#define   JPEG_IRQ_MASK_BMSK                                                                            0xFFFFFFFF
#define   JPEG_IRQ_MASK_SHFT                                                                                         0
#define   JPEG_IRQ_ALLSOURCES_ENABLE                                                                    0x3FFFFFFF

#define JPEG_IRQ_CLEAR_ADDR                                                                               (0x0000001C)
#define   JPEG_IRQ_CLEAR___RWC                                                                            QCSR_REG_WO
#define   JPEG_IRQ_CLEAR___POR                                                                         0x00000000
#define   JPEG_IRQ_CLEAR__CLEAR_BMSK                                                                    0xFFFFFFFF
#define   JPEG_IRQ_CLEAR__CLEAR_SHFT                                                                                 0
#define   JPEG_IRQ_CLEAR_BMSK                                                                           0xFFFFFFFF
#define   JPEG_IRQ_CLEAR_SHFT                                                                                        0

#define JPEG_IRQ_STATUS_ADDR                                                                              (0x00000020)
#define   JPEG_IRQ_STATUS___RWC                                                                           QCSR_REG_RO
#define   JPEG_IRQ_STATUS___POR                                                                        0x00000000
#define   JPEG_IRQ_STATUS__STATUS_BMSK                                                                  0xFFFFFFFF
#define   JPEG_IRQ_STATUS__STATUS_SHFT                                                                               0
#define   JPEG_IRQ_STATUS_BMSK                                                                          0xFFFFFFFF
#define   JPEG_IRQ_STATUS_SHFT                                                                                       0

#define JPEG_FE_CFG_ADDR                                                                                  (0x00000024)
#define   JPEG_FE_CFG___RWC                                                                               QCSR_REG_RW
#define   JPEG_FE_CFG___POR                                                                            0x00000000
#define   JPEG_FE_CFG__H_FLIP_BMSK                                                                      0x80000000
#define   JPEG_FE_CFG__H_FLIP_SHFT                                                                                  31
#define   JPEG_FE_CFG__ROTATION_BMSK                                                                    0x60000000
#define   JPEG_FE_CFG__ROTATION_SHFT                                                                                29
#define   JPEG_FE_CFG__ROTATION__ROT_0_DEGREE                                                                     0x0
#define   JPEG_FE_CFG__ROTATION__ROT_90_DEGREE                                                                    0x1
#define   JPEG_FE_CFG__ROTATION__ROT_180_DEGREE                                                                   0x2
#define   JPEG_FE_CFG__ROTATION__ROT_270_DEGREE                                                                   0x3
#define   JPEG_FE_CFG__MAL_EN_BMSK                                                                      0x08000000
#define   JPEG_FE_CFG__MAL_EN_SHFT                                                                                  27
#define   JPEG_FE_CFG__MAL_BOUNDARY_BMSK                                                                0x07000000
#define   JPEG_FE_CFG__MAL_BOUNDARY_SHFT                                                                            24
#define   JPEG_FE_CFG__MAL_BOUNDARY__MAL_32_BYTES                                                                 0x0
#define   JPEG_FE_CFG__MAL_BOUNDARY__MAL_64_BYTES                                                                 0x1
#define   JPEG_FE_CFG__MAL_BOUNDARY__MAL_128_BYTES                                                                0x2
#define   JPEG_FE_CFG__MAL_BOUNDARY__MAL_256_BYTES                                                                0x3
#define   JPEG_FE_CFG__MAL_BOUNDARY__MAL_512_BYTES                                                                0x4
#define   JPEG_FE_CFG__MAL_BOUNDARY__MAL_1024_BYTES                                                               0x5
#define   JPEG_FE_CFG__MAL_BOUNDARY__MAL_2048_BYTES                                                               0x6
#define   JPEG_FE_CFG__MAL_BOUNDARY__MAL_4096_BYTES                                                               0x7
#define   JPEG_FE_CFG__MCU_BOUNDARY_BMSK                                                                0x00C00000
#define   JPEG_FE_CFG__MCU_BOUNDARY_SHFT                                                                            22
#define   JPEG_FE_CFG__PLN2_EN_BMSK                                                                     0x00040000
#define   JPEG_FE_CFG__PLN2_EN_SHFT                                                                                 18
#define   JPEG_FE_CFG__PLN1_EN_BMSK                                                                     0x00020000
#define   JPEG_FE_CFG__PLN1_EN_SHFT                                                                                 17
#define   JPEG_FE_CFG__PLN0_EN_BMSK                                                                     0x00010000
#define   JPEG_FE_CFG__PLN0_EN_SHFT                                                                                 16
#define   JPEG_FE_CFG__RD_SRC_BMSK                                                                      0x00008000
#define   JPEG_FE_CFG__RD_SRC_SHFT                                                                                  15
#define   JPEG_FE_CFG__SWC_JPEG_FETCH_EN_BMSK                                                                0x00004000
#define   JPEG_FE_CFG__SWC_JPEG_FETCH_EN_SHFT                                                                            14
#define   JPEG_FE_CFG__BOTTOM_VPAD_EN_BMSK                                                              0x00002000
#define   JPEG_FE_CFG__BOTTOM_VPAD_EN_SHFT                                                                          13
#define   JPEG_FE_CFG__CBCR_ORDER_BMSK                                                                  0x00001000
#define   JPEG_FE_CFG__CBCR_ORDER_SHFT                                                                              12
#define   JPEG_FE_CFG__MEMORY_FORMAT_BMSK                                                               0x00000300
#define   JPEG_FE_CFG__MEMORY_FORMAT_SHFT                                                                            8
#define   JPEG_FE_CFG__MEMORY_FORMAT__PLANAR                                                                      0x0
#define   JPEG_FE_CFG__MEMORY_FORMAT__PSEUDO_PLANAR                                                               0x1
#define   JPEG_FE_CFG__MEMORY_FORMAT__MONOCHROME                                                                  0x2
#define   JPEG_FE_CFG__MEMORY_FORMAT__CO_EFFICIENT                                                                0x3
#define   JPEG_FE_CFG__BURST_LENGTH_MAX_BMSK                                                            0x000000F0
#define   JPEG_FE_CFG__BURST_LENGTH_MAX_SHFT                                                                         4
#define   JPEG_FE_CFG__BYTE_ORDERING_BMSK                                                               0x0000000F
#define   JPEG_FE_CFG__BYTE_ORDERING_SHFT                                                                            0
#define   JPEG_FE_CFG_BMSK                                                                              0xFFFFFFFF
#define   JPEG_FE_CFG_SHFT                                                                                           0

#define JPEG_FE_QOS_CFG_ADDR                                                                              (0x00000028)
#define   JPEG_FE_QOS_CFG___RWC                                                                           QCSR_REG_RW
#define   JPEG_FE_QOS_CFG___POR                                                                        0x00000000
#define   JPEG_FE_QOS_CFG__PRIORITY_11_BMSK                                                             0x0000C000
#define   JPEG_FE_QOS_CFG__PRIORITY_11_SHFT                                                                         14
#define   JPEG_FE_QOS_CFG__PRIORITY_10_BMSK                                                             0x00003000
#define   JPEG_FE_QOS_CFG__PRIORITY_10_SHFT                                                                         12
#define   JPEG_FE_QOS_CFG__PRIORITY_01_BMSK                                                             0x00000C00
#define   JPEG_FE_QOS_CFG__PRIORITY_01_SHFT                                                                         10
#define   JPEG_FE_QOS_CFG__PRIORITY_00_BMSK                                                             0x00000300
#define   JPEG_FE_QOS_CFG__PRIORITY_00_SHFT                                                                          8
#define   JPEG_FE_QOS_CFG__QOS_WINDOW_SIZE_BMSK                                                         0x0000000F
#define   JPEG_FE_QOS_CFG__QOS_WINDOW_SIZE_SHFT                                                                      0
#define   JPEG_FE_QOS_CFG_BMSK                                                                          0x0000FFFF
#define   JPEG_FE_QOS_CFG_SHFT                                                                                       0

#define JPEG_FE_QOS_LAT_HIGH_ADDR                                                                         (0x0000002C)
#define   JPEG_FE_QOS_LAT_HIGH___RWC                                                                      QCSR_REG_RW
#define   JPEG_FE_QOS_LAT_HIGH___POR                                                                   0x00000000
#define   JPEG_FE_QOS_LAT_HIGH__LEVEL_BMSK                                                              0x0000FFFF
#define   JPEG_FE_QOS_LAT_HIGH__LEVEL_SHFT                                                                           0
#define   JPEG_FE_QOS_LAT_HIGH_BMSK                                                                     0x0000FFFF
#define   JPEG_FE_QOS_LAT_HIGH_SHFT                                                                                  0

#define JPEG_FE_QOS_LAT_MID_ADDR                                                                          (0x00000030)
#define   JPEG_FE_QOS_LAT_MID___RWC                                                                       QCSR_REG_RW
#define   JPEG_FE_QOS_LAT_MID___POR                                                                    0x00000000
#define   JPEG_FE_QOS_LAT_MID__LEVEL_BMSK                                                               0x0000FFFF
#define   JPEG_FE_QOS_LAT_MID__LEVEL_SHFT                                                                            0
#define   JPEG_FE_QOS_LAT_MID_BMSK                                                                      0x0000FFFF
#define   JPEG_FE_QOS_LAT_MID_SHFT                                                                                   0

#define JPEG_FE_QOS_LAT_LOW_ADDR                                                                         (0x00000034)
#define   JPEG_FE_QOS_LAT_LOW___RWC                                                                       QCSR_REG_RW
#define   JPEG_FE_QOS_LAT_LOW___POR                                                                    0x00000000
#define   JPEG_FE_QOS_LAT_LOW__LEVEL_BMSK                                                               0x0000FFFF
#define   JPEG_FE_QOS_LAT_LOW__LEVEL_SHFT                                                                            0
#define   JPEG_FE_QOS_LAT_LOW_BMSK                                                                      0x0000FFFF
#define   JPEG_FE_QOS_LAT_LOW_SHFT                                                                                   0

#define JPEG_PLN0_RD_PNTR_ADDR                                                                           (0x00000038)
#define   JPEG_PLN0_RD_PNTR___RWC                                                                         QCSR_REG_WO
#define   JPEG_PLN0_RD_PNTR___POR                                                                      0x00000000
#define   JPEG_PLN0_RD_PNTR__PNTR_BMSK                                                                  0xFFFFFFFF
#define   JPEG_PLN0_RD_PNTR__PNTR_SHFT                                                                               0
#define   JPEG_PLN0_RD_PNTR_BMSK                                                                        0xFFFFFFFF
#define   JPEG_PLN0_RD_PNTR_SHFT                                                                                     0

#define JPEG_PLN0_RD_OFFSET_ADDR                                                                          (0x0000003C)
#define   JPEG_PLN0_RD_OFFSET___RWC                                                                       QCSR_REG_WO
#define   JPEG_PLN0_RD_OFFSET___POR                                                                    0x00000000
#define   JPEG_PLN0_RD_OFFSET__OFFSET_BMSK                                                              0x1FFFFFFF
#define   JPEG_PLN0_RD_OFFSET__OFFSET_SHFT                                                                           0
#define   JPEG_PLN0_RD_OFFSET_BMSK                                                                      0xFFFFFFFF
#define   JPEG_PLN0_RD_OFFSET_SHFT                                                                                   0

#define JPEG_PLN0_RD_PNTR_CNSMD_ADDR                                                                      (0x00000040)
#define   JPEG_PLN0_RD_PNTR_CNSMD___RWC                                                                   QCSR_REG_RO
#define   JPEG_PLN0_RD_PNTR_CNSMD___POR                                                                0x00000000
#define   JPEG_PLN0_RD_PNTR_CNSMD__PNTR_CNSMD_BMSK                                                      0xFFFFFFFF
#define   JPEG_PLN0_RD_PNTR_CNSMD__PNTR_CNSMD_SHFT                                                                   0
#define   JPEG_PLN0_RD_PNTR_CNSMD_BMSK                                                                  0xFFFFFFFF
#define   JPEG_PLN0_RD_PNTR_CNSMD_SHFT                                                                               0

#define JPEG_PLN1_RD_PNTR_ADDR                                                                           (0x00000044)
#define   JPEG_PLN1_RD_PNTR___RWC                                                                         QCSR_REG_WO
#define   JPEG_PLN1_RD_PNTR___POR                                                                      0x00000000
#define   JPEG_PLN1_RD_PNTR__PNTR_BMSK                                                                  0xFFFFFFFF
#define   JPEG_PLN1_RD_PNTR__PNTR_SHFT                                                                               0
#define   JPEG_PLN1_RD_PNTR_BMSK                                                                        0xFFFFFFFF
#define   JPEG_PLN1_RD_PNTR_SHFT                                                                                     0

#define JPEG_PLN1_RD_OFFSET_ADDR                                                                          (0x00000048)
#define   JPEG_PLN1_RD_OFFSET___RWC                                                                       QCSR_REG_WO
#define   JPEG_PLN1_RD_OFFSET___POR                                                                    0x00000000
#define   JPEG_PLN1_RD_OFFSET__OFFSET_BMSK                                                              0x1FFFFFFF
#define   JPEG_PLN1_RD_OFFSET__OFFSET_SHFT                                                                           0
#define   JPEG_PLN1_RD_OFFSET_BMSK                                                                      0xFFFFFFFF
#define   JPEG_PLN1_RD_OFFSET_SHFT                                                                                   0

#define JPEG_PLN1_RD_PNTR_CNSMD_ADDR                                                                      (0x0000004C)
#define   JPEG_PLN1_RD_PNTR_CNSMD___RWC                                                                   QCSR_REG_RO
#define   JPEG_PLN1_RD_PNTR_CNSMD___POR                                                                0x00000000
#define   JPEG_PLN1_RD_PNTR_CNSMD__PNTR_CNSMD_BMSK                                                      0xFFFFFFFF
#define   JPEG_PLN1_RD_PNTR_CNSMD__PNTR_CNSMD_SHFT                                                                   0
#define   JPEG_PLN1_RD_PNTR_CNSMD_BMSK                                                                  0xFFFFFFFF
#define   JPEG_PLN1_RD_PNTR_CNSMD_SHFT                                                                               0

#define JPEG_PLN2_RD_PNTR_ADDR                                                                            (0x00000050)
#define   JPEG_PLN2_RD_PNTR___RWC                                                                         QCSR_REG_WO
#define   JPEG_PLN2_RD_PNTR___POR                                                                      0x00000000
#define   JPEG_PLN2_RD_PNTR__PNTR_BMSK                                                                  0xFFFFFFFF
#define   JPEG_PLN2_RD_PNTR__PNTR_SHFT                                                                               0
#define   JPEG_PLN2_RD_PNTR_BMSK                                                                        0xFFFFFFFF
#define   JPEG_PLN2_RD_PNTR_SHFT                                                                                     0

#define JPEG_PLN2_RD_OFFSET_ADDR                                                                          (0x00000054)
#define   JPEG_PLN2_RD_OFFSET___RWC                                                                       QCSR_REG_WO
#define   JPEG_PLN2_RD_OFFSET___POR                                                                    0x00000000
#define   JPEG_PLN2_RD_OFFSET__OFFSET_BMSK                                                              0x1FFFFFFF
#define   JPEG_PLN2_RD_OFFSET__OFFSET_SHFT                                                                           0
#define   JPEG_PLN2_RD_OFFSET_BMSK                                                                      0xFFFFFFFF
#define   JPEG_PLN2_RD_OFFSET_SHFT                                                                                   0

#define JPEG_PLN2_RD_PNTR_CNSMD_ADDR                                                                      (0x00000058)
#define   JPEG_PLN2_RD_PNTR_CNSMD___RWC                                                                   QCSR_REG_RO
#define   JPEG_PLN2_RD_PNTR_CNSMD___POR                                                                0x00000000
#define   JPEG_PLN2_RD_PNTR_CNSMD__PNTR_CNSMD_BMSK                                                      0xFFFFFFFF
#define   JPEG_PLN2_RD_PNTR_CNSMD__PNTR_CNSMD_SHFT                                                                   0
#define   JPEG_PLN2_RD_PNTR_CNSMD_BMSK                                                                  0xFFFFFFFF
#define   JPEG_PLN2_RD_PNTR_CNSMD_SHFT                                                                               0

#define JPEG_RD_PNTR_CNT_ADDR                                                                             (0x0000005C)
#define   JPEG_RD_PNTR_CNT___RWC                                                                          QCSR_REG_RO
#define   JPEG_RD_PNTR_CNT___POR                                                                       0x00000000
#define   JPEG_RD_PNTR_CNT__PLN2_PNTR_CNT_BMSK                                                          0x00000700
#define   JPEG_RD_PNTR_CNT__PLN2_PNTR_CNT_SHFT                                                                       8
#define   JPEG_RD_PNTR_CNT__PLN1_PNTR_CNT_BMSK                                                          0x00000070
#define   JPEG_RD_PNTR_CNT__PLN1_PNTR_CNT_SHFT                                                                       4
#define   JPEG_RD_PNTR_CNT__PLN0_PNTR_CNT_BMSK                                                          0x00000007
#define   JPEG_RD_PNTR_CNT__PLN0_PNTR_CNT_SHFT                                                                       0
#define   JPEG_RD_PNTR_CNT_BMSK                                                                         0x000007FF
#define   JPEG_RD_PNTR_CNT_SHFT                                                                                      0

#define JPEG_PLN0_RD_BUFFER_SIZE_ADDR                                                                     (0x00000060)
#define  JPEG_PLN0_RD_BUFFER_SIZE_RMSK                                                                   0xFFFFFFFF
#define   JPEG_PLN0_RD_BUFFER_SIZE___RWC                                                                  QCSR_REG_RW
#define   JPEG_PLN0_RD_BUFFER_SIZE___POR                                                               0x00000000
#define   JPEG_PLN0_RD_BUFFER_SIZE__HEIGHT_BMSK                                                         0xFFFF0000
#define   JPEG_PLN0_RD_BUFFER_SIZE__HEIGHT_SHFT                                                                     16
#define   JPEG_PLN0_RD_BUFFER_SIZE__WIDTH_BMSK                                                          0x0000FFFF
#define   JPEG_PLN0_RD_BUFFER_SIZE__WIDTH_SHFT                                                                       0
#define   JPEG_PLN0_RD_BUFFER_SIZE_BMSK                                                                 0xFFFFFFFF
#define   JPEG_PLN0_RD_BUFFER_SIZE_SHFT                                                                              0

#define JPEG_PLN0_RD_STRIDE_ADDR                                                                          (0x00000064)
#define   JPEG_PLN0_RD_STRIDE___RWC                                                                       QCSR_REG_RW
#define   JPEG_PLN0_RD_STRIDE___POR                                                                    0x00000000
#define   JPEG_PLN0_RD_STRIDE__STRIDE_BMSK                                                              0x0000FFFF
#define   JPEG_PLN0_RD_STRIDE__STRIDE_SHFT                                                                           0
#define   JPEG_PLN0_RD_STRIDE_BMSK                                                                      0x0000FFFF
#define   JPEG_PLN0_RD_STRIDE_SHFT                                                                                   0

#define JPEG_PLN1_RD_BUFFER_SIZE_AADR                                                                     (0x00000068)
#define   JPEG_PLN1_RD_BUFFER_SIZE___RWC                                                                  QCSR_REG_RW
#define   JPEG_PLN1_RD_BUFFER_SIZE___POR                                                               0x00000000
#define   JPEG_PLN1_RD_BUFFER_SIZE__HEIGHT_BMSK                                                         0xFFFF0000
#define   JPEG_PLN1_RD_BUFFER_SIZE__HEIGHT_SHFT                                                                     16
#define   JPEG_PLN1_RD_BUFFER_SIZE__WIDTH_BMSK                                                          0x0000FFFF
#define   JPEG_PLN1_RD_BUFFER_SIZE__WIDTH_SHFT                                                                       0
#define   JPEG_PLN1_RD_BUFFER_SIZE_BMSK                                                                 0xFFFFFFFF
#define   JPEG_PLN1_RD_BUFFER_SIZE_SHFT                                                                              0

#define JPEG_PLN1_RD_STRIDE_ADDR                                                                          (0x0000006C)
#define   JPEG_PLN1_RD_STRIDE___RWC                                                                       QCSR_REG_RW
#define   JPEG_PLN1_RD_STRIDE___POR                                                                    0x00000000
#define   JPEG_PLN1_RD_STRIDE__STRIDE_BMSK                                                              0x0000FFFF
#define   JPEG_PLN1_RD_STRIDE__STRIDE_SHFT                                                                           0
#define   JPEG_PLN1_RD_STRIDE_BMSK                                                                      0x0000FFFF
#define   JPEG_PLN1_RD_STRIDE_SHFT                                                                                   0

#define JPEG_PLN2_RD_BUFFER_SIZE_ADDR                                                                     (0x00000070)
#define   JPEG_PLN2_RD_BUFFER_SIZE___RWC                                                                  QCSR_REG_RW
#define   JPEG_PLN2_RD_BUFFER_SIZE___POR                                                               0x00000000
#define   JPEG_PLN2_RD_BUFFER_SIZE__HEIGHT_BMSK                                                         0xFFFF0000
#define   JPEG_PLN2_RD_BUFFER_SIZE__HEIGHT_SHFT                                                                     16
#define   JPEG_PLN2_RD_BUFFER_SIZE__WIDTH_BMSK                                                          0x0000FFFF
#define   JPEG_PLN2_RD_BUFFER_SIZE__WIDTH_SHFT                                                                       0
#define   JPEG_PLN2_RD_BUFFER_SIZE_BMSK                                                                 0xFFFFFFFF
#define   JPEG_PLN2_RD_BUFFER_SIZE_SHFT                                                                              0

#define JPEG_PLN0_RD_HINIT_ADDR                                                                           (0x00000074)
#define   JPEG_PLN0_RD_HINIT___RWC                                                                        QCSR_REG_RW
#define   JPEG_PLN0_RD_HINIT___POR                                                                     0x00000000
#define   JPEG_PLN0_RD_HINIT__FRACTIONAL_BMSK                                                           0x001FFFFF
#define   JPEG_PLN0_RD_HINIT__FRACTIONAL_SHFT                                                                        0
#define   JPEG_PLN0_RD_HINIT_BMSK                                                                       0x001FFFFF
#define   JPEG_PLN0_RD_HINIT_SHFT                                                                                    0

#define JPEG_PLN1_RD_HINIT_ADDR                                                                           (0x00000078)
#define   JPEG_PLN1_RD_HINIT___RWC                                                                        QCSR_REG_RW
#define   JPEG_PLN1_RD_HINIT___POR                                                                     0x00000000
#define   JPEG_PLN1_RD_HINIT__FRACTIONAL_BMSK                                                           0x001FFFFF
#define   JPEG_PLN1_RD_HINIT__FRACTIONAL_SHFT                                                                        0
#define   JPEG_PLN1_RD_HINIT_BMSK                                                                       0x001FFFFF
#define   JPEG_PLN1_RD_HINIT_SHFT                                                                                    0

#define JPEG_PLN2_RD_HINIT_ADDR                                                                           (0x0000007C)
#define   JPEG_PLN2_RD_HINIT___RWC                                                                        QCSR_REG_RW
#define   JPEG_PLN2_RD_HINIT___POR                                                                     0x00000000
#define   JPEG_PLN2_RD_HINIT__FRACTIONAL_BMSK                                                           0x001FFFFF
#define   JPEG_PLN2_RD_HINIT__FRACTIONAL_SHFT                                                                        0
#define   JPEG_PLN2_RD_HINIT_BMSK                                                                       0x001FFFFF
#define   JPEG_PLN2_RD_HINIT_SHFT                                                                                    0

#define JPEG_PLN0_RD_VINIT_ADDR                                                                           (0x00000080)
#define   JPEG_PLN0_RD_VINIT___RWC                                                                        QCSR_REG_RW
#define   JPEG_PLN0_RD_VINIT___POR                                                                     0x00000000
#define   JPEG_PLN0_RD_VINIT__FRACTIONAL_BMSK                                                           0x001FFFFF
#define   JPEG_PLN0_RD_VINIT__FRACTIONAL_SHFT                                                                        0
#define   JPEG_PLN0_RD_VINIT_BMSK                                                                       0x001FFFFF
#define   JPEG_PLN0_RD_VINIT_SHFT                                                                                    0

#define JPEG_PLN1_RD_VINIT_ADDR                                                                           (0x00000084)
#define   JPEG_PLN1_RD_VINIT___RWC                                                                        QCSR_REG_RW
#define   JPEG_PLN1_RD_VINIT___POR                                                                     0x00000000
#define   JPEG_PLN1_RD_VINIT__FRACTIONAL_BMSK                                                           0x001FFFFF
#define   JPEG_PLN1_RD_VINIT__FRACTIONAL_SHFT                                                                        0
#define   JPEG_PLN1_RD_VINIT_BMSK                                                                       0x001FFFFF
#define   JPEG_PLN1_RD_VINIT_SHFT                                                                                    0

#define JPEG_PLN2_RD_VINIT_ADDR                                                                           (0x00000088)
#define   JPEG_PLN2_RD_VINIT___RWC                                                                        QCSR_REG_RW
#define   JPEG_PLN2_RD_VINIT___POR                                                                     0x00000000
#define   JPEG_PLN2_RD_VINIT__FRACTIONAL_BMSK                                                           0x001FFFFF
#define   JPEG_PLN2_RD_VINIT__FRACTIONAL_SHFT                                                                        0
#define   JPEG_PLN2_RD_VINIT_BMSK                                                                       0x001FFFFF
#define   JPEG_PLN2_RD_VINIT_SHFT                                                                                    0

#define JPEG_PLN2_RD_STRIDE_ADDR                                                                         (0x0000008C)
#define   JPEG_PLN2_RD_STRIDE___RWC                                                                       QCSR_REG_RW
#define   JPEG_PLN2_RD_STRIDE___POR                                                                    0x00000000
#define   JPEG_PLN2_RD_STRIDE__STRIDE_BMSK                                                              0x0000FFFF
#define   JPEG_PLN2_RD_STRIDE__STRIDE_SHFT                                                                           0
#define   JPEG_PLN2_RD_STRIDE_BMSK                                                                      0x0000FFFF
#define   JPEG_PLN2_RD_STRIDE_SHFT                                                                                   0

#define JPEG_SWC_PLN0_RD_BLOCK_ADDR                                                                  (0x00000090)
#define   JPEG_SWC_PLN0_RD_BLOCK_ADDR___RWC                                                               QCSR_REG_RW
#define   JPEG_SWC_PLN0_RD_BLOCK_ADDR___POR                                                            0x00000000
#define   JPEG_SWC_PLN0_RD_BLOCK_ADDR__ADDR_BMSK                                                        0xFFFFFFFF
#define   JPEG_SWC_PLN0_RD_BLOCK_ADDR__ADDR_SHFT                                                                     0
#define   JPEG_SWC_PLN0_RD_BLOCK_ADDR_BMSK                                                              0xFFFFFFFF
#define   JPEG_SWC_PLN0_RD_BLOCK_ADDR_SHFT                                                                           0

#define JPEG_SWC_PLN0_RD_BLOCK_DIMENSION_ADDR                                                             (0x00000094)
#define   JPEG_SWC_PLN0_RD_BLOCK_DIMENSION___RWC                                                          QCSR_REG_RW
#define   JPEG_SWC_PLN0_RD_BLOCK_DIMENSION___POR                                                       0x00000000
#define   JPEG_SWC_PLN0_RD_BLOCK_DIMENSION__HEIGHT_BMSK                                                 0x00FF0000
#define   JPEG_SWC_PLN0_RD_BLOCK_DIMENSION__HEIGHT_SHFT                                                             16
#define   JPEG_SWC_PLN0_RD_BLOCK_DIMENSION__WIDTH_BMSK                                                  0x000000FF
#define   JPEG_SWC_PLN0_RD_BLOCK_DIMENSION__WIDTH_SHFT                                                               0
#define   JPEG_SWC_PLN0_RD_BLOCK_DIMENSION_BMSK                                                         0x00FFFFFF
#define   JPEG_SWC_PLN0_RD_BLOCK_DIMENSION_SHFT                                                                      0

#define JPEG_SWC_PLN0_RD_BLOCK_H_ADDR                                                                     (0x00000098)
#define   JPEG_SWC_PLN0_RD_BLOCK_H___RWC                                                                  QCSR_REG_RW
#define   JPEG_SWC_PLN0_RD_BLOCK_H___POR                                                               0x00000000
#define   JPEG_SWC_PLN0_RD_BLOCK_H__INTEGER_BMSK                                                        0x7FE00000
#define   JPEG_SWC_PLN0_RD_BLOCK_H__INTEGER_SHFT                                                                    21
#define   JPEG_SWC_PLN0_RD_BLOCK_H__FRACTIONAL_BMSK                                                     0x001FFFFF
#define   JPEG_SWC_PLN0_RD_BLOCK_H__FRACTIONAL_SHFT                                                                  0
#define   JPEG_SWC_PLN0_RD_BLOCK_H_BMSK                                                                 0x7FFFFFFF
#define   JPEG_SWC_PLN0_RD_BLOCK_H_SHFT                                                                              0

#define JPEG_SWC_PLN0_RD_BLOCK_V_ADDR                                                                     (0x0000009C)
#define   JPEG_SWC_PLN0_RD_BLOCK_V___RWC                                                                  QCSR_REG_RW
#define   JPEG_SWC_PLN0_RD_BLOCK_V___POR                                                               0x00000000
#define   JPEG_SWC_PLN0_RD_BLOCK_V__INTEGER_BMSK                                                        0x7FE00000
#define   JPEG_SWC_PLN0_RD_BLOCK_V__INTEGER_SHFT                                                                    21
#define   JPEG_SWC_PLN0_RD_BLOCK_V__FRACTIONAL_BMSK                                                     0x001FFFFF
#define   JPEG_SWC_PLN0_RD_BLOCK_V__FRACTIONAL_SHFT                                                                  0
#define   JPEG_SWC_PLN0_RD_BLOCK_V_BMSK                                                                 0x7FFFFFFF
#define   JPEG_SWC_PLN0_RD_BLOCK_V_SHFT                                                                              0

#define JPEG_SWC_PLN1_RD_BLOCK_ADDR                                                                  (0x000000A0)
#define   JPEG_SWC_PLN1_RD_BLOCK_ADDR___RWC                                                               QCSR_REG_RW
#define   JPEG_SWC_PLN1_RD_BLOCK_ADDR___POR                                                            0x00000000
#define   JPEG_SWC_PLN1_RD_BLOCK_ADDR__ADDR_BMSK                                                        0xFFFFFFFF
#define   JPEG_SWC_PLN1_RD_BLOCK_ADDR__ADDR_SHFT                                                                     0
#define   JPEG_SWC_PLN1_RD_BLOCK_ADDR_BMSK                                                              0xFFFFFFFF
#define   JPEG_SWC_PLN1_RD_BLOCK_ADDR_SHFT                                                                           0

#define JPEG_SWC_PLN1_RD_BLOCK_DIMENSION_ADDR                                                             (0x000000A4)
#define   JPEG_SWC_PLN1_RD_BLOCK_DIMENSION___RWC                                                          QCSR_REG_RW
#define   JPEG_SWC_PLN1_RD_BLOCK_DIMENSION___POR                                                       0x00000000
#define   JPEG_SWC_PLN1_RD_BLOCK_DIMENSION__HEIGHT_BMSK                                                 0x00FF0000
#define   JPEG_SWC_PLN1_RD_BLOCK_DIMENSION__HEIGHT_SHFT                                                             16
#define   JPEG_SWC_PLN1_RD_BLOCK_DIMENSION__WIDTH_BMSK                                                  0x000000FF
#define   JPEG_SWC_PLN1_RD_BLOCK_DIMENSION__WIDTH_SHFT                                                               0
#define   JPEG_SWC_PLN1_RD_BLOCK_DIMENSION_BMSK                                                         0x00FFFFFF
#define   JPEG_SWC_PLN1_RD_BLOCK_DIMENSION_SHFT                                                                      0

#define JPEG_SWC_PLN1_RD_BLOCK_H_ADDR                                                                     (0x000000A8)
#define   JPEG_SWC_PLN1_RD_BLOCK_H___RWC                                                                  QCSR_REG_RW
#define   JPEG_SWC_PLN1_RD_BLOCK_H___POR                                                               0x00000000
#define   JPEG_SWC_PLN1_RD_BLOCK_H__INTEGER_BMSK                                                        0x7FE00000
#define   JPEG_SWC_PLN1_RD_BLOCK_H__INTEGER_SHFT                                                                    21
#define   JPEG_SWC_PLN1_RD_BLOCK_H__FRACTIONAL_BMSK                                                     0x001FFFFF
#define   JPEG_SWC_PLN1_RD_BLOCK_H__FRACTIONAL_SHFT                                                                  0
#define   JPEG_SWC_PLN1_RD_BLOCK_H_BMSK                                                                 0x7FFFFFFF
#define   JPEG_SWC_PLN1_RD_BLOCK_H_SHFT                                                                              0

#define JPEG_SWC_PLN1_RD_BLOCK_V_ADDR                                                                     (0x000000AC)
#define   JPEG_SWC_PLN1_RD_BLOCK_V___RWC                                                                  QCSR_REG_RW
#define   JPEG_SWC_PLN1_RD_BLOCK_V___POR                                                               0x00000000
#define   JPEG_SWC_PLN1_RD_BLOCK_V__INTEGER_BMSK                                                        0x7FE00000
#define   JPEG_SWC_PLN1_RD_BLOCK_V__INTEGER_SHFT                                                                    21
#define   JPEG_SWC_PLN1_RD_BLOCK_V__FRACTIONAL_BMSK                                                     0x001FFFFF
#define   JPEG_SWC_PLN1_RD_BLOCK_V__FRACTIONAL_SHFT                                                                  0
#define   JPEG_SWC_PLN1_RD_BLOCK_V_BMSK                                                                 0x7FFFFFFF
#define   JPEG_SWC_PLN1_RD_BLOCK_V_SHFT                                                                              0

#define JPEG_SWC_PLN2_RD_BLOCK_ADDR                                                                  (0x000000B0)
#define   JPEG_SWC_PLN2_RD_BLOCK_ADDR___RWC                                                               QCSR_REG_RW
#define   JPEG_SWC_PLN2_RD_BLOCK_ADDR___POR                                                            0x00000000
#define   JPEG_SWC_PLN2_RD_BLOCK_ADDR__ADDR_BMSK                                                        0xFFFFFFFF
#define   JPEG_SWC_PLN2_RD_BLOCK_ADDR__ADDR_SHFT                                                                     0
#define   JPEG_SWC_PLN2_RD_BLOCK_ADDR_BMSK                                                              0xFFFFFFFF
#define   JPEG_SWC_PLN2_RD_BLOCK_ADDR_SHFT                                                                           0

#define JPEG_SWC_PLN2_RD_BLOCK_DIMENSION_ADDR                                                             (0x000000B4)
#define   JPEG_SWC_PLN2_RD_BLOCK_DIMENSION___RWC                                                          QCSR_REG_RW
#define   JPEG_SWC_PLN2_RD_BLOCK_DIMENSION___POR                                                       0x00000000
#define   JPEG_SWC_PLN2_RD_BLOCK_DIMENSION__HEIGHT_BMSK                                                 0x00FF0000
#define   JPEG_SWC_PLN2_RD_BLOCK_DIMENSION__HEIGHT_SHFT                                                             16
#define   JPEG_SWC_PLN2_RD_BLOCK_DIMENSION__WIDTH_BMSK                                                  0x000000FF
#define   JPEG_SWC_PLN2_RD_BLOCK_DIMENSION__WIDTH_SHFT                                                               0
#define   JPEG_SWC_PLN2_RD_BLOCK_DIMENSION_BMSK                                                         0x00FFFFFF
#define   JPEG_SWC_PLN2_RD_BLOCK_DIMENSION_SHFT                                                                      0

#define JPEG_JPEG_SWC_PLN2_RD_BLOCK_H_ADDR                                                                     (0x000000B8)
#define   JPEG_SWC_PLN2_RD_BLOCK_H___RWC                                                                  QCSR_REG_RW
#define   JPEG_SWC_PLN2_RD_BLOCK_H___POR                                                               0x00000000
#define   JPEG_SWC_PLN2_RD_BLOCK_H__INTEGER_BMSK                                                        0x7FE00000
#define   JPEG_SWC_PLN2_RD_BLOCK_H__INTEGER_SHFT                                                                    21
#define   JPEG_SWC_PLN2_RD_BLOCK_H__FRACTIONAL_BMSK                                                     0x001FFFFF
#define   JPEG_SWC_PLN2_RD_BLOCK_H__FRACTIONAL_SHFT                                                                  0
#define   JPEG_SWC_PLN2_RD_BLOCK_H_BMSK                                                                 0x7FFFFFFF
#define   JPEG_SWC_PLN2_RD_BLOCK_H_SHFT                                                                              0

#define JPEG_JPEG_SWC_PLN2_RD_BLOCK_V_ADDR                                                                     (0x000000BC)
#define   JPEG_SWC_PLN2_RD_BLOCK_V___RWC                                                                  QCSR_REG_RW
#define   JPEG_SWC_PLN2_RD_BLOCK_V___POR                                                               0x00000000
#define   JPEG_SWC_PLN2_RD_BLOCK_V__INTEGER_BMSK                                                        0x7FE00000
#define   JPEG_SWC_PLN2_RD_BLOCK_V__INTEGER_SHFT                                                                    21
#define   JPEG_SWC_PLN2_RD_BLOCK_V__FRACTIONAL_BMSK                                                     0x001FFFFF
#define   JPEG_SWC_PLN2_RD_BLOCK_V__FRACTIONAL_SHFT                                                                  0
#define   JPEG_SWC_PLN2_RD_BLOCK_V_BMSK                                                                 0x7FFFFFFF
#define   JPEG_SWC_PLN2_RD_BLOCK_V_SHFT                                                                              0

#define JPEG_WE_CFG_ADDR                                                                                  (0x000000C0)
#define   JPEG_WE_CFG___RWC                                                                               QCSR_REG_RW
#define   JPEG_WE_CFG___POR                                                                            0x00000000
#define   JPEG_WE_CFG__H_FLIP_BMSK                                                                      0x80000000
#define   JPEG_WE_CFG__H_FLIP_SHFT                                                                                  31
#define   JPEG_WE_CFG__ROTATION_BMSK                                                                    0x60000000
#define   JPEG_WE_CFG__ROTATION_SHFT                                                                                29
#define   JPEG_WE_CFG__ROTATION__ROT_0_DEGREE                                                                     0x0
#define   JPEG_WE_CFG__ROTATION__ROT_90_DEGREE                                                                    0x1
#define   JPEG_WE_CFG__ROTATION__ROT_180_DEGREE                                                                   0x2
#define   JPEG_WE_CFG__ROTATION__ROT_270_DEGREE                                                                   0x3
#define   JPEG_WE_CFG__POP_BUFF_ON_EOS_BMSK                                                             0x10000000
#define   JPEG_WE_CFG__POP_BUFF_ON_EOS_SHFT                                                                         28
#define   JPEG_WE_CFG__MAL_EN_BMSK                                                                      0x08000000
#define   JPEG_WE_CFG__MAL_EN_SHFT                                                                                  27
#define   JPEG_WE_CFG__MAL_BOUNDARY_BMSK                                                                0x07000000
#define   JPEG_WE_CFG__MAL_BOUNDARY_SHFT                                                                            24
#define   JPEG_WE_CFG__MAL_BOUNDARY__MAL_32_BYTES                                                                 0x0
#define   JPEG_WE_CFG__MAL_BOUNDARY__MAL_64_BYTES                                                                 0x1
#define   JPEG_WE_CFG__MAL_BOUNDARY__MAL_128_BYTES                                                                0x2
#define   JPEG_WE_CFG__MAL_BOUNDARY__MAL_256_BYTES                                                                0x3
#define   JPEG_WE_CFG__MAL_BOUNDARY__MAL_512_BYTES                                                                0x4
#define   JPEG_WE_CFG__MAL_BOUNDARY__MAL_1024_BYTES                                                               0x5
#define   JPEG_WE_CFG__MAL_BOUNDARY__MAL_2048_BYTES                                                               0x6
#define   JPEG_WE_CFG__MAL_BOUNDARY__MAL_4096_BYTES                                                               0x7
#define   JPEG_WE_CFG__PLN2_EN_BMSK                                                                     0x00040000
#define   JPEG_WE_CFG__PLN2_EN_SHFT                                                                                 18
#define   JPEG_WE_CFG__PLN1_EN_BMSK                                                                     0x00020000
#define   JPEG_WE_CFG__PLN1_EN_SHFT                                                                                 17
#define   JPEG_WE_CFG__PLN0_EN_BMSK                                                                     0x00010000
#define   JPEG_WE_CFG__PLN0_EN_SHFT                                                                                 16
#define   JPEG_WE_CFG__CBCR_ORDER_BMSK                                                                  0x00001000
#define   JPEG_WE_CFG__CBCR_ORDER_SHFT                                                                              12
#define   JPEG_WE_CFG__MEMORY_FORMAT_BMSK                                                               0x00000300
#define   JPEG_WE_CFG__MEMORY_FORMAT_SHFT                                                                            8
#define   JPEG_WE_CFG__MEMORY_FORMAT__PLANAR                                                                      0x0
#define   JPEG_WE_CFG__MEMORY_FORMAT__PSEUDO_PLANAR                                                               0x1
#define   JPEG_WE_CFG__MEMORY_FORMAT__MONOCHROME                                                                  0x2
#define   JPEG_WE_CFG__BURST_LENGTH_MAX_BMSK                                                            0x000000F0
#define   JPEG_WE_CFG__BURST_LENGTH_MAX_SHFT                                                                         4
#define   JPEG_WE_CFG__BYTE_ORDERING_BMSK                                                               0x0000000F
#define   JPEG_WE_CFG__BYTE_ORDERING_SHFT                                                                            0
#define   JPEG_WE_CFG_BMSK                                                                              0xFFFFFFFF
#define   JPEG_WE_CFG_SHFT                                                                                           0

#define JPEG_WE_PATH_CFG_ADDR                                                                             (0x000000C4)
#define   JPEG_WE_PATH_CFG___RWC                                                                          QCSR_REG_RW
#define   JPEG_WE_PATH_CFG___POR                                                                       0x00000000
#define   JPEG_WE_PATH_CFG__PLN2_XBAR_SEL_BMSK                                                          0x00000030
#define   JPEG_WE_PATH_CFG__PLN2_XBAR_SEL_SHFT                                                                       4
#define   JPEG_WE_PATH_CFG__PLN1_XBAR_SEL_BMSK                                                          0x0000000C
#define   JPEG_WE_PATH_CFG__PLN1_XBAR_SEL_SHFT                                                                       2
#define   JPEG_WE_PATH_CFG__PLN0_XBAR_SEL_BMSK                                                          0x00000003
#define   JPEG_WE_PATH_CFG__PLN0_XBAR_SEL_SHFT                                                                       0
#define   JPEG_WE_PATH_CFG_BMSK                                                                         0x0000003F
#define   JPEG_WE_PATH_CFG_SHFT                                                                                      0

#define JPEG_WE_QOS_CFG_ADDR                                                                              (0x000000C8)
#define   JPEG_WE_QOS_CFG___RWC                                                                           QCSR_REG_RW
#define   JPEG_WE_QOS_CFG___POR                                                                        0x00000000
#define   JPEG_WE_QOS_CFG__PRIORITY_111_BMSK                                                            0x0000C000
#define   JPEG_WE_QOS_CFG__PRIORITY_111_SHFT                                                                        14
#define   JPEG_WE_QOS_CFG__PRIORITY_110_BMSK                                                            0x00003000
#define   JPEG_WE_QOS_CFG__PRIORITY_110_SHFT                                                                        12
#define   JPEG_WE_QOS_CFG__PRIORITY_101_BMSK                                                            0x00000C00
#define   JPEG_WE_QOS_CFG__PRIORITY_101_SHFT                                                                        10
#define   JPEG_WE_QOS_CFG__PRIORITY_100_BMSK                                                            0x00000300
#define   JPEG_WE_QOS_CFG__PRIORITY_100_SHFT                                                                         8
#define   JPEG_WE_QOS_CFG__PRIORITY_011_BMSK                                                            0x000000C0
#define   JPEG_WE_QOS_CFG__PRIORITY_011_SHFT                                                                         6
#define   JPEG_WE_QOS_CFG__PRIORITY_010_BMSK                                                            0x00000030
#define   JPEG_WE_QOS_CFG__PRIORITY_010_SHFT                                                                         4
#define   JPEG_WE_QOS_CFG__PRIORITY_001_BMSK                                                            0x0000000C
#define   JPEG_WE_QOS_CFG__PRIORITY_001_SHFT                                                                         2
#define   JPEG_WE_QOS_CFG__PRIORITY_000_BMSK                                                            0x00000003
#define   JPEG_WE_QOS_CFG__PRIORITY_000_SHFT                                                                         0
#define   JPEG_WE_QOS_CFG_BMSK                                                                          0x0000FFFF
#define   JPEG_WE_QOS_CFG_SHFT                                                                                       0

#define JPEG_PLN0_WR_PNTR_ADDR                                                                            (0x000000CC)
#define   JPEG_PLN0_WR_PNTR___RWC                                                                         QCSR_REG_WO
#define   JPEG_PLN0_WR_PNTR___POR                                                                      0x00000000
#define   JPEG_PLN0_WR_PNTR__PNTR_BMSK                                                                  0xFFFFFFFF
#define   JPEG_PLN0_WR_PNTR__PNTR_SHFT                                                                               0
#define   JPEG_PLN0_WR_PNTR_BMSK                                                                        0xFFFFFFFF
#define   JPEG_PLN0_WR_PNTR_SHFT                                                                                     0

#define JPEG_PLN1_WR_PNTR_ADDR                                                                            (0x000000D0)
#define   JPEG_PLN1_WR_PNTR___RWC                                                                         QCSR_REG_WO
#define   JPEG_PLN1_WR_PNTR___POR                                                                      0x00000000
#define   JPEG_PLN1_WR_PNTR__PNTR_BMSK                                                                  0xFFFFFFFF
#define   JPEG_PLN1_WR_PNTR__PNTR_SHFT                                                                               0
#define   JPEG_PLN1_WR_PNTR_BMSK                                                                        0xFFFFFFFF
#define   JPEG_PLN1_WR_PNTR_SHFT                                                                                     0

#define JPEG_PLN2_WR_PNTR_ADDR                                                                            (0x000000D4)
#define   JPEG_PLN2_WR_PNTR___RWC                                                                         QCSR_REG_WO
#define   JPEG_PLN2_WR_PNTR___POR                                                                      0x00000000
#define   JPEG_PLN2_WR_PNTR__PNTR_BMSK                                                                  0xFFFFFFFF
#define   JPEG_PLN2_WR_PNTR__PNTR_SHFT                                                                               0
#define   JPEG_PLN2_WR_PNTR_BMSK                                                                        0xFFFFFFFF
#define   JPEG_PLN2_WR_PNTR_SHFT                                                                                     0

#define JPEG_PLN0_WR_PNTR_CNSMD                                                                      (0x000000D8)
#define   JPEG_PLN0_WR_PNTR_CNSMD___RWC                                                                   QCSR_REG_RO
#define   JPEG_PLN0_WR_PNTR_CNSMD___POR                                                                0x00000000
#define   JPEG_PLN0_WR_PNTR_CNSMD__PNTR_CNSMD_BMSK                                                      0xFFFFFFFF
#define   JPEG_PLN0_WR_PNTR_CNSMD__PNTR_CNSMD_SHFT                                                                   0
#define   JPEG_PLN0_WR_PNTR_CNSMD_BMSK                                                                  0xFFFFFFFF
#define   JPEG_PLN0_WR_PNTR_CNSMD_SHFT                                                                               0

#define JPEG_PLN1_WR_PNTR_CNSMD                                                                      (0x000000DC)
#define   JPEG_PLN1_WR_PNTR_CNSMD___RWC                                                                   QCSR_REG_RO
#define   JPEG_PLN1_WR_PNTR_CNSMD___POR                                                                0x00000000
#define   JPEG_PLN1_WR_PNTR_CNSMD__PNTR_CNSMD_BMSK                                                      0xFFFFFFFF
#define   JPEG_PLN1_WR_PNTR_CNSMD__PNTR_CNSMD_SHFT                                                                   0
#define   JPEG_PLN1_WR_PNTR_CNSMD_BMSK                                                                  0xFFFFFFFF
#define   JPEG_PLN1_WR_PNTR_CNSMD_SHFT                                                                               0

#define JPEG_PLN2_WR_PNTR_CNSMD                                                                      (0x000000E0)
#define   JPEG_PLN2_WR_PNTR_CNSMD___RWC                                                                   QCSR_REG_RO
#define   JPEG_PLN2_WR_PNTR_CNSMD___POR                                                                0x00000000
#define   JPEG_PLN2_WR_PNTR_CNSMD__PNTR_CNSMD_BMSK                                                      0xFFFFFFFF
#define   JPEG_PLN2_WR_PNTR_CNSMD__PNTR_CNSMD_SHFT                                                                   0
#define   JPEG_PLN2_WR_PNTR_CNSMD_BMSK                                                                  0xFFFFFFFF
#define   JPEG_PLN2_WR_PNTR_CNSMD_SHFT                                                                               0

#define JPEG_WR_PNTR_CNT_ADDR                                                                             (0x000000E4)
#define   JPEG_WR_PNTR_CNT___RWC                                                                          QCSR_REG_RO
#define   JPEG_WR_PNTR_CNT___POR                                                                       0x00000000
#define   JPEG_WR_PNTR_CNT__PLN2_PNTR_CNT_BMSK                                                          0x00000F00
#define   JPEG_WR_PNTR_CNT__PLN2_PNTR_CNT_SHFT                                                                       8
#define   JPEG_WR_PNTR_CNT__PLN1_PNTR_CNT_BMSK                                                          0x000000F0
#define   JPEG_WR_PNTR_CNT__PLN1_PNTR_CNT_SHFT                                                                       4
#define   JPEG_WR_PNTR_CNT__PLN0_PNTR_CNT_BMSK                                                          0x0000000F
#define   JPEG_WR_PNTR_CNT__PLN0_PNTR_CNT_SHFT                                                                       0
#define   JPEG_WR_PNTR_CNT_BMSK                                                                         0x00000FFF
#define   JPEG_WR_PNTR_CNT_SHFT                                                                                      0

#define JPEG_PLN0_WR_BUFFER_SIZE_ADDR                                                                     (0x000000E8)
#define   JPEG_PLN0_WR_BUFFER_SIZE___RWC                                                                  QCSR_REG_RW
#define   JPEG_PLN0_WR_BUFFER_SIZE___POR                                                               0x00000000
#define   JPEG_PLN0_WR_BUFFER_SIZE__HEIGHT_BMSK                                                         0xFFFF0000
#define   JPEG_PLN0_WR_BUFFER_SIZE__HEIGHT_SHFT                                                                     16
#define   JPEG_PLN0_WR_BUFFER_SIZE__WIDTH_BMSK                                                          0x0000FFFF
#define   JPEG_PLN0_WR_BUFFER_SIZE__WIDTH_SHFT                                                                       0
#define   JPEG_PLN0_WR_BUFFER_SIZE_BMSK                                                                 0xFFFFFFFF
#define   JPEG_PLN0_WR_BUFFER_SIZE_SHFT                                                                              0

#define JPEG_PLN1_WR_BUFFER_SIZE_ADDR                                                                     (0x000000EC)
#define   JPEG_PLN1_WR_BUFFER_SIZE___RWC                                                                  QCSR_REG_RW
#define   JPEG_PLN1_WR_BUFFER_SIZE___POR                                                               0x00000000
#define   JPEG_PLN1_WR_BUFFER_SIZE__HEIGHT_BMSK                                                         0xFFFF0000
#define   JPEG_PLN1_WR_BUFFER_SIZE__HEIGHT_SHFT                                                                     16
#define   JPEG_PLN1_WR_BUFFER_SIZE__WIDTH_BMSK                                                          0x0000FFFF
#define   JPEG_PLN1_WR_BUFFER_SIZE__WIDTH_SHFT                                                                       0
#define   JPEG_PLN1_WR_BUFFER_SIZE_BMSK                                                                 0xFFFFFFFF
#define   JPEG_PLN1_WR_BUFFER_SIZE_SHFT                                                                              0

#define JPEG_PLN2_WR_BUFFER_SIZE_ADDR                                                                     (0x000000F0)
#define   JPEG_PLN2_WR_BUFFER_SIZE___RWC                                                                  QCSR_REG_RW
#define   JPEG_PLN2_WR_BUFFER_SIZE___POR                                                               0x00000000
#define   JPEG_PLN2_WR_BUFFER_SIZE__HEIGHT_BMSK                                                         0xFFFF0000
#define   JPEG_PLN2_WR_BUFFER_SIZE__HEIGHT_SHFT                                                                     16
#define   JPEG_PLN2_WR_BUFFER_SIZE__WIDTH_BMSK                                                          0x0000FFFF
#define   JPEG_PLN2_WR_BUFFER_SIZE__WIDTH_SHFT                                                                       0
#define   JPEG_PLN2_WR_BUFFER_SIZE_BMSK                                                                 0xFFFFFFFF
#define   JPEG_PLN2_WR_BUFFER_SIZE_SHFT                                                                              0

#define JPEG_PLN0_WR_STRIDE_ADDR                                                                          (0x000000F4)
#define   JPEG_PLN0_WR_STRIDE___RWC                                                                       QCSR_REG_RW
#define   JPEG_PLN0_WR_STRIDE___POR                                                                    0x00000000
#define   JPEG_PLN0_WR_STRIDE__STRIDE_BMSK                                                              0x0000FFFF
#define   JPEG_PLN0_WR_STRIDE__STRIDE_SHFT                                                                           0
#define   JPEG_PLN0_WR_STRIDE_BMSK                                                                      0x0000FFFF
#define   JPEG_PLN0_WR_STRIDE_SHFT                                                                                   0

#define JPEG_PLN1_WR_STRIDE_ADDR                                                                          (0x000000F8)
#define   JPEG_PLN1_WR_STRIDE___RWC                                                                       QCSR_REG_RW
#define   JPEG_PLN1_WR_STRIDE___POR                                                                    0x00000000
#define   JPEG_PLN1_WR_STRIDE__STRIDE_BMSK                                                              0x0000FFFF
#define   JPEG_PLN1_WR_STRIDE__STRIDE_SHFT                                                                           0
#define   JPEG_PLN1_WR_STRIDE_BMSK                                                                      0x0000FFFF
#define   JPEG_PLN1_WR_STRIDE_SHFT                                                                                   0

#define JPEG_PLN2_WR_STRIDE_ADDR                                                                          (0x000000FC)
#define   JPEG_PLN2_WR_STRIDE___RWC                                                                       QCSR_REG_RW
#define   JPEG_PLN2_WR_STRIDE___POR                                                                    0x00000000
#define   JPEG_PLN2_WR_STRIDE__STRIDE_BMSK                                                              0x0000FFFF
#define   JPEG_PLN2_WR_STRIDE__STRIDE_SHFT                                                                           0
#define   JPEG_PLN2_WR_STRIDE_BMSK                                                                      0x0000FFFF
#define   JPEG_PLN2_WR_STRIDE_SHFT                                                                                   0

#define JPEG_PLN0_WR_HINIT_ADDR                                                                           (0x00000100)
#define   JPEG_PLN0_WR_HINIT___RWC                                                                        QCSR_REG_RW
#define   JPEG_PLN0_WR_HINIT___POR                                                                     0x00000000
#define   JPEG_PLN0_WR_HINIT__INTEGER_BMSK                                                              0x0000FFFF
#define   JPEG_PLN0_WR_HINIT__INTEGER_SHFT                                                                           0
#define   JPEG_PLN0_WR_HINIT_BMSK                                                                       0x0000FFFF
#define   JPEG_PLN0_WR_HINIT_SHFT                                                                                    0

#define JPEG_PLN1_WR_HINIT_ADDR                                                                           (0x00000104)
#define   JPEG_PLN1_WR_HINIT___RWC                                                                        QCSR_REG_RW
#define   JPEG_PLN1_WR_HINIT___POR                                                                     0x00000000
#define   JPEG_PLN1_WR_HINIT__INTEGER_BMSK                                                              0x0000FFFF
#define   JPEG_PLN1_WR_HINIT__INTEGER_SHFT                                                                           0
#define   JPEG_PLN1_WR_HINIT_BMSK                                                                       0x0000FFFF
#define   JPEG_PLN1_WR_HINIT_SHFT                                                                                    0

#define JPEG_PLN2_WR_HINIT_ADDR                                                                           (0x00000108)
#define   JPEG_PLN2_WR_HINIT___RWC                                                                        QCSR_REG_RW
#define   JPEG_PLN2_WR_HINIT___POR                                                                     0x00000000
#define   JPEG_PLN2_WR_HINIT__INTEGER_BMSK                                                              0x0000FFFF
#define   JPEG_PLN2_WR_HINIT__INTEGER_SHFT                                                                           0
#define   JPEG_PLN2_WR_HINIT_BMSK                                                                       0x0000FFFF
#define   JPEG_PLN2_WR_HINIT_SHFT                                                                                    0

#define JPEG_PLN0_WR_VINIT_ADDR                                                                           (0x0000010C)
#define   JPEG_PLN0_WR_VINIT___RWC                                                                        QCSR_REG_RW
#define   JPEG_PLN0_WR_VINIT___POR                                                                     0x00000000
#define   JPEG_PLN0_WR_VINIT__INTEGER_BMSK                                                              0x0000FFFF
#define   JPEG_PLN0_WR_VINIT__INTEGER_SHFT                                                                           0
#define   JPEG_PLN0_WR_VINIT_BMSK                                                                       0x0000FFFF
#define   JPEG_PLN0_WR_VINIT_SHFT                                                                                    0

#define JPEG_PLN1_WR_VINIT_ADDR                                                                           (0x00000110)
#define   JPEG_PLN1_WR_VINIT___RWC                                                                        QCSR_REG_RW
#define   JPEG_PLN1_WR_VINIT___POR                                                                     0x00000000
#define   JPEG_PLN1_WR_VINIT__INTEGER_BMSK                                                              0x0000FFFF
#define   JPEG_PLN1_WR_VINIT__INTEGER_SHFT                                                                           0
#define   JPEG_PLN1_WR_VINIT_BMSK                                                                       0x0000FFFF
#define   JPEG_PLN1_WR_VINIT_SHFT                                                                                    0

#define JPEG_PLN2_WR_VINIT_ADDR                                                                           (0x00000114)
#define   JPEG_PLN2_WR_VINIT___RWC                                                                        QCSR_REG_RW
#define   JPEG_PLN2_WR_VINIT___POR                                                                     0x00000000
#define   JPEG_PLN2_WR_VINIT__INTEGER_BMSK                                                              0x0000FFFF
#define   JPEG_PLN2_WR_VINIT__INTEGER_SHFT                                                                           0
#define   JPEG_PLN2_WR_VINIT_BMSK                                                                       0x0000FFFF
#define   JPEG_PLN2_WR_VINIT_SHFT                                                                                    0

#define JPEG_PLN0_WR_HSTEP_ADDR                                                                           (0x00000118)
#define   JPEG_PLN0_WR_HSTEP___RWC                                                                        QCSR_REG_RW
#define   JPEG_PLN0_WR_HSTEP___POR                                                                     0x00000000
#define   JPEG_PLN0_WR_HSTEP__INTEGER_BMSK                                                              0x0001FFFF
#define   JPEG_PLN0_WR_HSTEP__INTEGER_SHFT                                                                           0
#define   JPEG_PLN0_WR_HSTEP_BMSK                                                                       0x0001FFFF
#define   JPEG_PLN0_WR_HSTEP_SHFT                                                                                    0

#define JPEG_PLN1_WR_HSTEP_ADDR                                                                           (0x0000011C)
#define   JPEG_PLN1_WR_HSTEP___RWC                                                                        QCSR_REG_RW
#define   JPEG_PLN1_WR_HSTEP___POR                                                                     0x00000000
#define   JPEG_PLN1_WR_HSTEP__INTEGER_BMSK                                                              0x0001FFFF
#define   JPEG_PLN1_WR_HSTEP__INTEGER_SHFT                                                                           0
#define   JPEG_PLN1_WR_HSTEP_BMSK                                                                       0x0001FFFF
#define   JPEG_PLN1_WR_HSTEP_SHFT                                                                                    0

#define JPEG_PLN2_WR_HSTEP_ADDR                                                                           (0x00000120)
#define   JPEG_PLN2_WR_HSTEP___RWC                                                                        QCSR_REG_RW
#define   JPEG_PLN2_WR_HSTEP___POR                                                                     0x00000000
#define   JPEG_PLN2_WR_HSTEP__INTEGER_BMSK                                                              0x0001FFFF
#define   JPEG_PLN2_WR_HSTEP__INTEGER_SHFT                                                                           0
#define   JPEG_PLN2_WR_HSTEP_BMSK                                                                       0x0001FFFF
#define   JPEG_PLN2_WR_HSTEP_SHFT                                                                                    0

#define JPEG_PLN0_WR_VSTEP_ADDR                                                                           (0x00000124)
#define   JPEG_PLN0_WR_VSTEP___RWC                                                                        QCSR_REG_RW
#define   JPEG_PLN0_WR_VSTEP___POR                                                                     0x00000000
#define   JPEG_PLN0_WR_VSTEP__INTEGER_BMSK                                                              0x0001FFFF
#define   JPEG_PLN0_WR_VSTEP__INTEGER_SHFT                                                                           0
#define   JPEG_PLN0_WR_VSTEP_BMSK                                                                       0x0001FFFF
#define   JPEG_PLN0_WR_VSTEP_SHFT                                                                                    0

#define JPEG_PLN1_WR_VSTEP_ADDR                                                                           (0x00000128)
#define   JPEG_PLN1_WR_VSTEP___RWC                                                                        QCSR_REG_RW
#define   JPEG_PLN1_WR_VSTEP___POR                                                                     0x00000000
#define   JPEG_PLN1_WR_VSTEP__INTEGER_BMSK                                                              0x0001FFFF
#define   JPEG_PLN1_WR_VSTEP__INTEGER_SHFT                                                                           0
#define   JPEG_PLN1_WR_VSTEP_BMSK                                                                       0x0001FFFF
#define   JPEG_PLN1_WR_VSTEP_SHFT                                                                                    0

#define JPEG_PLN2_WR_VSTEP_ADDR                                                                           (0x0000012C)
#define   JPEG_PLN2_WR_VSTEP___RWC                                                                        QCSR_REG_RW
#define   JPEG_PLN2_WR_VSTEP___POR                                                                     0x00000000
#define   JPEG_PLN2_WR_VSTEP__INTEGER_BMSK                                                              0x0001FFFF
#define   JPEG_PLN2_WR_VSTEP__INTEGER_SHFT                                                                           0
#define   JPEG_PLN2_WR_VSTEP_BMSK                                                                       0x0001FFFF
#define   JPEG_PLN2_WR_VSTEP_SHFT                                                                                    0

#define JPEG_PLN0_WR_BLOCK_CFG_ADDR                                                                       (0x00000130)
#define   JPEG_PLN0_WR_BLOCK_CFG___RWC                                                                    QCSR_REG_RW
#define   JPEG_PLN0_WR_BLOCK_CFG___POR                                                                 0x00000000
#define   JPEG_PLN0_WR_BLOCK_CFG__BLOCKS_PER_ROW_BMSK                                                   0xFFFF0000
#define   JPEG_PLN0_WR_BLOCK_CFG__BLOCKS_PER_ROW_SHFT                                                               16
#define   JPEG_PLN0_WR_BLOCK_CFG__BLOCKS_PER_COL_BMSK                                                   0x0000FFFF
#define   JPEG_PLN0_WR_BLOCK_CFG__BLOCKS_PER_COL_SHFT                                                                0
#define   JPEG_PLN0_WR_BLOCK_CFG_BMSK                                                                   0xFFFFFFFF
#define   JPEG_PLN0_WR_BLOCK_CFG_SHFT                                                                                0

#define JPEG_PLN1_WR_BLOCK_CFG_ADDR                                                                       (0x00000134)
#define   JPEG_PLN1_WR_BLOCK_CFG___RWC                                                                    QCSR_REG_RW
#define   JPEG_PLN1_WR_BLOCK_CFG___POR                                                                 0x00000000
#define   JPEG_PLN1_WR_BLOCK_CFG__BLOCKS_PER_ROW_BMSK                                                   0xFFFF0000
#define   JPEG_PLN1_WR_BLOCK_CFG__BLOCKS_PER_ROW_SHFT                                                               16
#define   JPEG_PLN1_WR_BLOCK_CFG__BLOCKS_PER_COL_BMSK                                                   0x0000FFFF
#define   JPEG_PLN1_WR_BLOCK_CFG__BLOCKS_PER_COL_SHFT                                                                0
#define   JPEG_PLN1_WR_BLOCK_CFG_BMSK                                                                   0xFFFFFFFF
#define   JPEG_PLN1_WR_BLOCK_CFG_SHFT                                                                                0

#define JPEG_PLN2_WR_BLOCK_CFG_ADDR                                                                       (0x00000138)
#define   JPEG_PLN2_WR_BLOCK_CFG___RWC                                                                    QCSR_REG_RW
#define   JPEG_PLN2_WR_BLOCK_CFG___POR                                                                 0x00000000
#define   JPEG_PLN2_WR_BLOCK_CFG__BLOCKS_PER_ROW_BMSK                                                   0xFFFF0000
#define   JPEG_PLN2_WR_BLOCK_CFG__BLOCKS_PER_ROW_SHFT                                                               16
#define   JPEG_PLN2_WR_BLOCK_CFG__BLOCKS_PER_COL_BMSK                                                   0x0000FFFF
#define   JPEG_PLN2_WR_BLOCK_CFG__BLOCKS_PER_COL_SHFT                                                                0
#define   JPEG_PLN2_WR_BLOCK_CFG_BMSK                                                                   0xFFFFFFFF
#define   JPEG_PLN2_WR_BLOCK_CFG_SHFT                                                                                0

#define JPEG_ENCODE_CFG_ADDR                                                                              (0x0000013C)
#define   JPEG_ENCODE_CFG___RWC                                                                           QCSR_REG_RW
#define   JPEG_ENCODE_CFG___POR                                                                        0x00000000
#define   JPEG_ENCODE_CFG__RST_MARKER_PERIOD_BMSK                                                       0xFFFF0000
#define   JPEG_ENCODE_CFG__RST_MARKER_PERIOD_SHFT                                                                   16
#define   JPEG_ENCODE_CFG__OUTPUT_DISABLE_BMSK                                                          0x00008000
#define   JPEG_ENCODE_CFG__OUTPUT_DISABLE_SHFT                                                                      15
#define   JPEG_ENCODE_CFG__OUTPUT_DISABLE__ENCODER_OUTPUT_ENABLED                                                 0x0
#define   JPEG_ENCODE_CFG__OUTPUT_DISABLE__ENCODER_OUTPUT_DIASBLED                                                0x1
#define   JPEG_ENCODE_CFG__FSC_ENABLE_BMSK                                                              0x00000800
#define   JPEG_ENCODE_CFG__FSC_ENABLE_SHFT                                                                          11
#define   JPEG_ENCODE_CFG__FSC_ENABLE__FSC_DISABLED                                                               0x0
#define   JPEG_ENCODE_CFG__FSC_ENABLE__FSC_ENABLED                                                                0x1
#define   JPEG_ENCODE_CFG__STATS_ENABLE_BMSK                                                            0x00000400
#define   JPEG_ENCODE_CFG__STATS_ENABLE_SHFT                                                                        10
#define   JPEG_ENCODE_CFG__STATS_ENABLE__STATS_DISABLED                                                           0x0
#define   JPEG_ENCODE_CFG__STATS_ENABLE__STATS_ENABLED                                                            0x1
#define   JPEG_ENCODE_CFG__INDEX_TABLE_ENABLE_BMSK                                                      0x00000200
#define   JPEG_ENCODE_CFG__INDEX_TABLE_ENABLE_SHFT                                                                   9
#define   JPEG_ENCODE_CFG__INDEX_TABLE_ENABLE__INDEX_TABLE_DISABLED                                               0x0
#define   JPEG_ENCODE_CFG__INDEX_TABLE_ENABLE__INDEX_TABLE_ENABLED                                                0x1
#define   JPEG_ENCODE_CFG__HUFFMAN_SEL_BMSK                                                             0x00000100
#define   JPEG_ENCODE_CFG__HUFFMAN_SEL_SHFT                                                                          8
#define   JPEG_ENCODE_CFG__APPLY_EOI_BMSK                                                               0x00000080
#define   JPEG_ENCODE_CFG__APPLY_EOI_SHFT                                                                            7
#define   JPEG_ENCODE_CFG__APPLY_EOI_DISABLED                                                                     0x0
#define   JPEG_ENCODE_CFG__APPLY_EOI_ENABLED                                                                      0x1
#define   JPEG_ENCODE_CFG__H_FLIP_BMSK                                                                  0x00000040
#define   JPEG_ENCODE_CFG__H_FLIP_SHFT                                                                               6
#define   JPEG_ENCODE_CFG__ROTATION_BMSK                                                                0x00000030
#define   JPEG_ENCODE_CFG__ROTATION_SHFT                                                                             4
#define   JPEG_ENCODE_CFG__ROTATION__ROT_0_DEGREE                                                                 0x0
#define   JPEG_ENCODE_CFG__ROTATION__ROT_90_DEGREE                                                                0x1
#define   JPEG_ENCODE_CFG__ROTATION__ROT_180_DEGREE                                                               0x2
#define   JPEG_ENCODE_CFG__ROTATION__ROT_270_DEGREE                                                               0x3
#define   JPEG_ENCODE_CFG__IMAGE_FORMAT_BMSK                                                            0x00000007
#define   JPEG_ENCODE_CFG__IMAGE_FORMAT_SHFT                                                                         0
#define   JPEG_ENCODE_CFG__IMAGE_FORMAT__H1V1                                                                     0x0
#define   JPEG_ENCODE_CFG__IMAGE_FORMAT__H1V2                                                                     0x1
#define   JPEG_ENCODE_CFG__IMAGE_FORMAT__H2V1                                                                     0x2
#define   JPEG_ENCODE_CFG__IMAGE_FORMAT__H2V2                                                                     0x3
#define   JPEG_ENCODE_CFG__IMAGE_FORMAT__MONOCHROME                                                               0x4
#define   JPEG_ENCODE_CFG_BMSK                                                                          0xFFFFFFFF
#define   JPEG_ENCODE_CFG_SHFT                                                                                       0

#define JPEG_ENCODE_IMAGE_SIZE_ADDR                                                                       (0x00000140)
#define   JPEG_ENCODE_IMAGE_SIZE___RWC                                                                    QCSR_REG_RW
#define   JPEG_ENCODE_IMAGE_SIZE___POR                                                                 0x00000000
#define   JPEG_ENCODE_IMAGE_SIZE__ENCODE_IMAGE_HEIGHT_BMSK                                              0x1FFF0000
#define   JPEG_ENCODE_IMAGE_SIZE__ENCODE_IMAGE_HEIGHT_SHFT                                                          16
#define   JPEG_ENCODE_IMAGE_SIZE__ENCODE_IMAGE_WIDTH_BMSK                                               0x00001FFF
#define   JPEG_ENCODE_IMAGE_SIZE__ENCODE_IMAGE_WIDTH_SHFT                                                            0
#define   JPEG_ENCODE_IMAGE_SIZE_BMSK                                                                   0x1FFFFFFF
#define   JPEG_ENCODE_IMAGE_SIZE_SHFT                                                                                0

#define JPEG_ENCODE_STATS_CFG_ADDR                                                                        (0x00000144)
#define   JPEG_ENCODE_STATS_CFG___RWC                                                                     QCSR_REG_RW
#define   JPEG_ENCODE_STATS_CFG___POR                                                                  0x00000000
#define   JPEG_ENCODE_STATS_CFG__STATS_SUM_OFFSET_BMSK                                                  0x0000000F
#define   JPEG_ENCODE_STATS_CFG__STATS_SUM_OFFSET_SHFT                                                               0
#define   JPEG_ENCODE_STATS_CFG_BMSK                                                                    0x0000000F
#define   JPEG_ENCODE_STATS_CFG_SHFT                                                                                 0

#define JPEG_ENCODE_INDEX_TABLE_CFG_ADDR                                                                  (0x00000148)
#define   JPEG_ENCODE_INDEX_TABLE_CFG___RWC                                                               QCSR_REG_RW
#define   JPEG_ENCODE_INDEX_TABLE_CFG___POR                                                            0x00000000
#define   JPEG_ENCODE_INDEX_TABLE_CFG__DC_VALUE_REPORT_EN_BMSK                                          0x00000010
#define   JPEG_ENCODE_INDEX_TABLE_CFG__DC_VALUE_REPORT_EN_SHFT                                                       4
#define   JPEG_ENCODE_INDEX_TABLE_CFG__REGION_GRANULARITY_BMSK                                          0x00000001
#define   JPEG_ENCODE_INDEX_TABLE_CFG__REGION_GRANULARITY_SHFT                                                       0
#define   JPEG_ENCODE_INDEX_TABLE_CFG_BMSK                                                              0x0000001F
#define   JPEG_ENCODE_INDEX_TABLE_CFG_SHFT                                                                           0

#define JPEG_ENCODE_FSC_REGION_SIZE_ADDR                                                                  (0x0000014C)
#define   JPEG_ENCODE__FSC_REGION_SIZE___RWC                                                               QCSR_REG_RW
#define   JPEG_ENCODE__FSC_REGION_SIZE___POR                                                            0x00000000
#define   JPEG_ENCODE__FSC_REGION_SIZE__HV_REGION_BMSK                                                   0x00000100
#define   JPEG_ENCODE__FSC_REGION_SIZE__HV_REGION_SHFT                                                                8
#define   JPEG_ENCODE__FSC_REGION_SIZE__REGION_SIZE_BMSK                                                 0x0000001F
#define   JPEG_ENCODE__FSC_REGION_SIZE__REGION_SIZE_SHFT                                                              0
#define   JPEG_ENCODE_FSC_REGION_SIZE_BMSK                                                              0x000001FF
#define   JPEG_ENCODE_FSC_REGION_SIZE_SHFT                                                                           0

#define JPEG_ENCODE_FSC_BUDGET_0_ADDR                                                                     (0x00000150)
#define   JPEG_ENCODE_FSC_BUDGET_0___RWC                                                                  QCSR_REG_RW
#define   JPEG_ENCODE_FSC_BUDGET_0___POR                                                               0x00000000
#define   JPEG_ENCODE_FSC_BUDGET_0__BUDGET_REGION3_BMSK                                                 0xFF000000
#define   JPEG_ENCODE_FSC_BUDGET_0__BUDGET_REGION3_SHFT                                                             24
#define   JPEG_ENCODE_FSC_BUDGET_0__BUDGET_REGION2_BMSK                                                 0x00FF0000
#define   JPEG_ENCODE_FSC_BUDGET_0__BUDGET_REGION2_SHFT                                                             16
#define   JPEG_ENCODE_FSC_BUDGET_0__BUDGET_REGION1_BMSK                                                 0x0000FF00
#define   JPEG_ENCODE_FSC_BUDGET_0__BUDGET_REGION1_SHFT                                                              8
#define   JPEG_ENCODE_FSC_BUDGET_0__BUDGET_REGION0_BMSK                                                 0x000000FF
#define   JPEG_ENCODE_FSC_BUDGET_0__BUDGET_REGION0_SHFT                                                              0
#define   JPEG_ENCODE_FSC_BUDGET_0_BMSK                                                                 0xFFFFFFFF
#define   JPEG_ENCODE_FSC_BUDGET_0_SHFT                                                                              0

#define JPEG_ENCODE_FSC_BUDGET_1_ADDR                                                                     (0x00000154)
#define   JPEG_ENCODE_FSC_BUDGET_1___RWC                                                                  QCSR_REG_RW
#define   JPEG_ENCODE_FSC_BUDGET_1___POR                                                               0x00000000
#define   JPEG_ENCODE_FSC_BUDGET_1__BUDGET_REGION7_BMSK                                                 0xFF000000
#define   JPEG_ENCODE_FSC_BUDGET_1__BUDGET_REGION7_SHFT                                                             24
#define   JPEG_ENCODE_FSC_BUDGET_1__BUDGET_REGION6_BMSK                                                 0x00FF0000
#define   JPEG_ENCODE_FSC_BUDGET_1__BUDGET_REGION6_SHFT                                                             16
#define   JPEG_ENCODE_FSC_BUDGET_1__BUDGET_REGION5_BMSK                                                 0x0000FF00
#define   JPEG_ENCODE_FSC_BUDGET_1__BUDGET_REGION5_SHFT                                                              8
#define   JPEG_ENCODE_FSC_BUDGET_1__BUDGET_REGION4_BMSK                                                 0x000000FF
#define   JPEG_ENCODE_FSC_BUDGET_1__BUDGET_REGION4_SHFT                                                              0
#define   JPEG_ENCODE_FSC_BUDGET_1_BMSK                                                                 0xFFFFFFFF
#define   JPEG_ENCODE_FSC_BUDGET_1_SHFT                                                                              0

#define JPEG_ENCODE_FSC_BUDGET_2_ADDR                                                                     (0x00000158)
#define   JPEG_ENCODE_FSC_BUDGET_2___RWC                                                                  QCSR_REG_RW
#define   JPEG_ENCODE_FSC_BUDGET_2___POR                                                               0x00000000
#define   JPEG_ENCODE_FSC_BUDGET_2__BUDGET_REGION11_BMSK                                                0xFF000000
#define   JPEG_ENCODE_FSC_BUDGET_2__BUDGET_REGION11_SHFT                                                            24
#define   JPEG_ENCODE_FSC_BUDGET_2__BUDGET_REGION10_BMSK                                                0x00FF0000
#define   JPEG_ENCODE_FSC_BUDGET_2__BUDGET_REGION10_SHFT                                                            16
#define   JPEG_ENCODE_FSC_BUDGET_2__BUDGET_REGION9_BMSK                                                 0x0000FF00
#define   JPEG_ENCODE_FSC_BUDGET_2__BUDGET_REGION9_SHFT                                                              8
#define   JPEG_ENCODE_FSC_BUDGET_2__BUDGET_REGION8_BMSK                                                 0x000000FF
#define   JPEG_ENCODE_FSC_BUDGET_2__BUDGET_REGION8_SHFT                                                              0
#define   JPEG_ENCODE_FSC_BUDGET_2_BMSK                                                                 0xFFFFFFFF
#define   JPEG_ENCODE_FSC_BUDGET_2_SHFT                                                                              0

#define JPEG_ENCODE_FSC_BUDGET_3_ADDR                                                                     (0x0000015C)
#define   JPEG_ENCODE_FSC_BUDGET_3___RWC                                                                  QCSR_REG_RW
#define   JPEG_ENCODE_FSC_BUDGET_3___POR                                                               0x00000000
#define   JPEG_ENCODE_FSC_BUDGET_3__BUDGET_REGION15_BMSK                                                0xFF000000
#define   JPEG_ENCODE_FSC_BUDGET_3__BUDGET_REGION15_SHFT                                                            24
#define   JPEG_ENCODE_FSC_BUDGET_3__BUDGET_REGION14_BMSK                                                0x00FF0000
#define   JPEG_ENCODE_FSC_BUDGET_3__BUDGET_REGION14_SHFT                                                            16
#define   JPEG_ENCODE_FSC_BUDGET_3__BUDGET_REGION13_BMSK                                                0x0000FF00
#define   JPEG_ENCODE_FSC_BUDGET_3__BUDGET_REGION13_SHFT                                                             8
#define   JPEG_ENCODE_FSC_BUDGET_3__BUDGET_REGION12_BMSK                                                0x000000FF
#define   JPEG_ENCODE_FSC_BUDGET_3__BUDGET_REGION12_SHFT                                                             0
#define   JPEG_ENCODE_FSC_BUDGET_3_BMSK                                                                 0xFFFFFFFF
#define   JPEG_ENCODE_FSC_BUDGET_3_SHFT                                                                              0

#define JPEG_ENCODE_PREDICTION_Y_STATE_ADDR                                                               (0x00000160)
#define   JPEG_ENCODE_PREDICTION_Y_STATE___RWC                                                            QCSR_REG_RW
#define   JPEG_ENCODE_PREDICTION_Y_STATE___POR                                                         0x00000000
#define   JPEG_ENCODE_PREDICTION_Y_STATE__PREDICTION_Y_STATE_BMSK                                       0x000007FF
#define   JPEG_ENCODE_PREDICTION_Y_STATE__PREDICTION_Y_STATE_SHFT                                                    0
#define   JPEG_ENCODE_PREDICTION_Y_STATE_BMSK                                                           0x000007FF
#define   JPEG_ENCODE_PREDICTION_Y_STATE_SHFT                                                                        0

#define JPEG__ENCODE_PREDICTION_C_STATE_ADDR                                                               (0x00000164)
#define   JPEG_ENCODE_PREDICTION_C_STATE___RWC                                                            QCSR_REG_RW
#define   JPEG_ENCODE_PREDICTION_C_STATE___POR                                                         0x00000000
#define   JPEG_ENCODE_PREDICTION_C_STATE__PREDICTION_CR_STATE_BMSK                                      0x07FF0000
#define   JPEG_ENCODE_PREDICTION_C_STATE__PREDICTION_CR_STATE_SHFT                                                  16
#define   JPEG_ENCODE_PREDICTION_C_STATE__PREDICTION_CB_STATE_BMSK                                      0x000007FF
#define   JPEG_ENCODE_PREDICTION_C_STATE__PREDICTION_CB_STATE_SHFT                                                   0
#define   JPEG_ENCODE_PREDICTION_C_STATE_BMSK                                                           0x07FFFFFF
#define   JPEG_ENCODE_PREDICTION_C_STATE_SHFT                                                                        0

#define JPEG_ENCODE_RSM_STATE_ADDR                                                                        (0x00000168)
#define   JPEG_ENCODE_RSM_STATE___RWC                                                                     QCSR_REG_RW
#define   JPEG_ENCODE_RSM_STATE___POR                                                                  0x00000000
#define   JPEG_ENCODE_RSM_STATE__RST_MARKER_VALUE_BMSK                                                  0x00070000
#define   JPEG_ENCODE_RSM_STATE__RST_MARKER_VALUE_SHFT                                                              16
#define   JPEG_ENCODE_RSM_STATE__RST_MARKER_MCU_COUNT_BMSK                                              0x0000FFFF
#define   JPEG_ENCODE_RSM_STATE__RST_MARKER_MCU_COUNT_SHFT                                                           0
#define   JPEG_ENCODE_RSM_STATE_BMSK                                                                    0x0007FFFF
#define   JPEG_ENCODE_RSM_STATE_SHFT                                                                                 0

#define JPEG_ENCODE_PACKER_STATE_ADDR                                                                     (0x0000016C)
#define   JPEG_ENCODE_PACKER_STATE___RWC                                                                  QCSR_REG_RW
#define   JPEG_ENCODE_PACKER_STATE___POR                                                               0x00000000
#define   JPEG_ENCODE_PACKER_STATE__BYTE_PACKER_LENGTH_BMSK                                             0x000007F0
#define   JPEG_ENCODE_PACKER_STATE__BYTE_PACKER_LENGTH_SHFT                                                          4
#define   JPEG_ENCODE_PACKER_STATE__BIT_COUNT_BMSK                                                      0x00000007
#define   JPEG_ENCODE_PACKER_STATE__BIT_COUNT_SHFT                                                                   0
#define   JPEG_ENCODE_PACKER_STATE_BMSK                                                                 0x000007FF
#define   JPEG_ENCODE_PACKER_STATE_SHFT                                                                              0

#define JPEG_ENCODE_BYTE_PACKER_WORD0_STATE_ADDR                                                          (0x00000170)
#define   JPEG_ENCODE_BYTE_PACKER_WORD0_STATE___RWC                                                       QCSR_REG_RW
#define   JPEG_ENCODE_BYTE_PACKER_WORD0_STATE___POR                                                    0x00000000
#define   JPEG_ENCODE_BYTE_PACKER_WORD0_STATE__BYTE_PACKER_WORD0_BMSK                                   0xFFFFFFFF
#define   JPEG_ENCODE_BYTE_PACKER_WORD0_STATE__BYTE_PACKER_WORD0_SHFT                                                0
#define   JPEG_ENCODE_BYTE_PACKER_WORD0_STATE_BMSK                                                      0xFFFFFFFF
#define   JPEG_ENCODE_BYTE_PACKER_WORD0_STATE_SHFT                                                                   0

#define JPEG_ENCODE_BYTE_PACKER_WORD1_STATE_ADDR                                                          (0x00000174)
#define   JPEG_ENCODE_BYTE_PACKER_WORD1_STATE___RWC                                                       QCSR_REG_RW
#define   JPEG_ENCODE_BYTE_PACKER_WORD1_STATE___POR                                                    0x00000000
#define   JPEG_ENCODE_BYTE_PACKER_WORD1_STATE__BYTE_PACKER_WORD1_BMSK                                   0xFFFFFFFF
#define   JPEG_ENCODE_BYTE_PACKER_WORD1_STATE__BYTE_PACKER_WORD1_SHFT                                                0
#define   JPEG_ENCODE_BYTE_PACKER_WORD1_STATE_BMSK                                                      0xFFFFFFFF
#define   JPEG_ENCODE_BYTE_PACKER_WORD1_STATE_SHFT                                                                   0

#define JPEG_ENCODE_BYTE_PACKER_WORD2_STATE_ADDR                                                          (0x00000178)
#define   JPEG_ENCODE_BYTE_PACKER_WORD2_STATE___RWC                                                       QCSR_REG_RW
#define   JPEG_ENCODE_BYTE_PACKER_WORD2_STATE___POR                                                    0x00000000
#define   JPEG_ENCODE_BYTE_PACKER_WORD2_STATE__BYTE_PACKER_WORD2_BMSK                                   0xFFFFFFFF
#define   JPEG_ENCODE_BYTE_PACKER_WORD2_STATE__BYTE_PACKER_WORD2_SHFT                                                0
#define   JPEG_ENCODE_BYTE_PACKER_WORD2_STATE_BMSK                                                      0xFFFFFFFF
#define   JPEG_ENCODE_BYTE_PACKER_WORD2_STATE_SHFT                                                                   0

#define JPEG_ENCODE_BYTE_PACKER_WORD3_STATE_ADDR                                                          (0x0000017C)
#define   JPEG_ENCODE_BYTE_PACKER_WORD3_STATE___RWC                                                       QCSR_REG_RW
#define   JPEG_ENCODE_BYTE_PACKER_WORD3_STATE___POR                                                    0x00000000
#define   JPEG_ENCODE_BYTE_PACKER_WORD3_STATE__BYTE_PACKER_WORD3_BMSK                                   0xFFFFFFFF
#define   JPEG_ENCODE_BYTE_PACKER_WORD3_STATE__BYTE_PACKER_WORD3_SHFT                                                0
#define   JPEG_ENCODE_BYTE_PACKER_WORD3_STATE_BMSK                                                      0xFFFFFFFF
#define   JPEG_ENCODE_BYTE_PACKER_WORD3_STATE_SHFT                                                                   0

#define JPEG_ENCODE_OUTPUT_SIZE_STATUS_ADDR                                                               (0x00000180)
#define   JPEG_ENCODE_OUTPUT_SIZE_STATUS___RWC                                                            QCSR_REG_RO
#define   JPEG_ENCODE_OUTPUT_SIZE_STATUS___POR                                                         0x00000000
#define   JPEG_ENCODE_OUTPUT_SIZE_STATUS__OUTPUT_SIZE_BYTES_BMSK                                        0x1FFFFFFF
#define   JPEG_ENCODE_OUTPUT_SIZE_STATUS__OUTPUT_SIZE_BYTES_SHFT                                                     0
#define   JPEG_ENCODE_OUTPUT_SIZE_STATUS_BMSK                                                           0x1FFFFFFF
#define   JPEG_ENCODE_OUTPUT_SIZE_STATUS_SHFT                                                                        0

#define JPEG_DECODE_CFG_ADDR                                                                              (0x00000184)
#define   JPEG_DECODE_CFG___RWC                                                                           QCSR_REG_RW
#define   JPEG_DECODE_CFG___POR                                                                        0x00000000
#define   JPEG_DECODE_CFG__RST_MARKER_PERIOD_BMSK                                                       0xFFFF0000
#define   JPEG_DECODE_CFG__RST_MARKER_PERIOD_SHFT                                                                   16
#define   JPEG_DECODE_CFG__DECODE_MODE_BMSK                                                             0x00000010
#define   JPEG_DECODE_CFG__DECODE_MODE_SHFT                                                                          4
#define   JPEG_DECODE_CFG__DECODE_MODE__BASELINE_DECODE                                                           0x0
#define   JPEG_DECODE_CFG__DECODE_MODE__PROGRESSIVE_DECODE                                                        0x1
#define   JPEG_DECODE_CFG__IMAGE_FORMAT_BMSK                                                            0x00000007
#define   JPEG_DECODE_CFG__IMAGE_FORMAT_SHFT                                                                         0
#define   JPEG_DECODE_CFG__IMAGE_FORMAT__H1V1                                                                     0x0
#define   JPEG_DECODE_CFG__IMAGE_FORMAT__H1V2                                                                     0x1
#define   JPEG_DECODE_CFG__IMAGE_FORMAT__H2V1                                                                     0x2
#define   JPEG_DECODE_CFG__IMAGE_FORMAT__H2V2                                                                     0x3
#define   JPEG_DECODE_CFG__IMAGE_FORMAT__MONOCHROME                                                               0x4
#define   JPEG_DECODE_CFG_BMSK                                                                          0xFFFFFFFF
#define   JPEG_DECODE_CFG_SHFT                                                                                       0

#define JPEG_DECODE_IMAGE_SIZE_ADDR                                                                       (0x00000188)
#define   JPEG_DECODE_IMAGE_SIZE___RWC                                                                    QCSR_REG_RW
#define   JPEG_DECODE_IMAGE_SIZE___POR                                                                 0x00000000
#define   JPEG_DECODE_IMAGE_SIZE__DECODE_IMAGE_HEIGHT_BMSK                                              0x1FFF0000
#define   JPEG_DECODE_IMAGE_SIZE__DECODE_IMAGE_HEIGHT_SHFT                                                          16
#define   JPEG_DECODE_IMAGE_SIZE__DECODE_IMAGE_WIDTH_BMSK                                               0x00001FFF
#define   JPEG_DECODE_IMAGE_SIZE__DECODE_IMAGE_WIDTH_SHFT                                                            0
#define   JPEG_DECODE_IMAGE_SIZE_BMSK                                                                   0x1FFFFFFF
#define   JPEG_DECODE_IMAGE_SIZE_SHFT                                                                                0

#define JPEG_DECODE_CROP_START_ADDR                                                                       (0x0000018C)
#define   JPEG_DECODE_CROP_START___RWC                                                                    QCSR_REG_RW
#define   JPEG_DECODE_CROP_START___POR                                                                 0x00000000
#define   JPEG_DECODE_CROP_START__DECODE_CROP_START_V_BMSK                                              0x1FFF0000
#define   JPEG_DECODE_CROP_START__DECODE_CROP_START_V_SHFT                                                          16
#define   JPEG_DECODE_CROP_START__DECODE_CROP_START_H_BMSK                                              0x00001FFF
#define   JPEG_DECODE_CROP_START__DECODE_CROP_START_H_SHFT                                                           0
#define   JPEG_DECODE_CROP_START_BMSK                                                                   0x1FFFFFFF
#define   JPEG_DECODE_CROP_START_SHFT                                                                                0

#define JPEG_DECODE_CROP_STOP_ADDR                                                                        (0x00000190)
#define   JPEG_DECODE_CROP_STOP___RWC                                                                     QCSR_REG_RW
#define   JPEG_DECODE_CROP_STOP___POR                                                                  0x00000000
#define   JPEG_DECODE_CROP_STOP__DECODE_CROP_STOP_V_BMSK                                                0x1FFF0000
#define   JPEG_DECODE_CROP_STOP__DECODE_CROP_STOP_V_SHFT                                                            16
#define   JPEG_DECODE_CROP_STOP__DECODE_CROP_STOP_H_BMSK                                                0x00001FFF
#define   JPEG_DECODE_CROP_STOP__DECODE_CROP_STOP_H_SHFT                                                             0
#define   JPEG_DECODE_CROP_STOP_BMSK                                                                    0x1FFFFFFF
#define   JPEG_DECODE_CROP_STOP_SHFT                                                                                 0

#define JPEG_DECODE_STOP_ADDR                                                                             (0x00000194)
#define   JPEG_DECODE_STOP___RWC                                                                          QCSR_REG_RW
#define   JPEG_DECODE_STOP___POR                                                                       0x00000000
#define   JPEG_DECODE_STOP__DECODE_STOP_V_BMSK                                                          0x1FFF0000
#define   JPEG_DECODE_STOP__DECODE_STOP_V_SHFT                                                                      16
#define   JPEG_DECODE_STOP__DECODE_STOP_H_BMSK                                                          0x00001FFF
#define   JPEG_DECODE_STOP__DECODE_STOP_H_SHFT                                                                       0
#define   JPEG_DECODE_STOP_BMSK                                                                         0x1FFFFFFF
#define   JPEG_DECODE_STOP_SHFT                                                                                      0

#define JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_0_ADDR                                                     (0x00000198)
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_0___RWC                                                  QCSR_REG_RW
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_0___POR                                               0x00000000
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH3_BMSK                                    0xFF000000
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH3_SHFT                                                24
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH2_BMSK                                    0x00FF0000
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH2_SHFT                                                16
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH1_BMSK                                    0x0000FF00
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH1_SHFT                                                 8
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH0_BMSK                                    0x000000FF
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH0_SHFT                                                 0
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_0_BMSK                                                 0xFFFFFFFF
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_0_SHFT                                                              0

#define JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_1_ADDR                                                     (0x0000019C)
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_1___RWC                                                  QCSR_REG_RW
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_1___POR                                               0x00000000
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH7_BMSK                                    0xFF000000
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH7_SHFT                                                24
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH6_BMSK                                    0x00FF0000
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH6_SHFT                                                16
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH5_BMSK                                    0x0000FF00
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH5_SHFT                                                 8
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH4_BMSK                                    0x000000FF
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH4_SHFT                                                 0
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_1_BMSK                                                 0xFFFFFFFF
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_1_SHFT                                                              0

#define JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_2_ADDR                                                     (0x000001A0)
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_2___RWC                                                  QCSR_REG_RW
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_2___POR                                               0x00000000
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH11_BMSK                                   0xFF000000
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH11_SHFT                                               24
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH10_BMSK                                   0x00FF0000
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH10_SHFT                                               16
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH9_BMSK                                    0x0000FF00
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH9_SHFT                                                 8
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH8_BMSK                                    0x000000FF
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH8_SHFT                                                 0
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_2_BMSK                                                 0xFFFFFFFF
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_2_SHFT                                                              0

#define JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_3_ADDR                                                     (0x000001A4)
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_3___RWC                                                  QCSR_REG_RW
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_3___POR                                               0x00000000
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH15_BMSK                                   0xFF000000
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH15_SHFT                                               24
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH14_BMSK                                   0x00FF0000
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH14_SHFT                                               16
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH13_BMSK                                   0x0000FF00
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH13_SHFT                                                8
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH12_BMSK                                   0x000000FF
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH12_SHFT                                                0
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_3_BMSK                                                 0xFFFFFFFF
#define   JPEG_DECODE_DC_Y_CUMULATIVE_CODE_COUNT_3_SHFT                                                              0

#define JPEG_DECODE_DC_Y_MIN_CODE_WORD_0_ADDR                                                             (0x000001A8)
#define   JPEG_DECODE_DC_Y_MIN_CODE_WORD_0___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_DC_Y_MIN_CODE_WORD_0___POR                                                       0x00000000
#define   JPEG_DECODE_DC_Y_MIN_CODE_WORD_0__MIN_CODE_WORD_LENGTH1_BMSK                                  0xFFFF0000
#define   JPEG_DECODE_DC_Y_MIN_CODE_WORD_0__MIN_CODE_WORD_LENGTH1_SHFT                                              16
#define   JPEG_DECODE_DC_Y_MIN_CODE_WORD_0__MIN_CODE_WORD_LENGTH0_BMSK                                  0x0000FFFF
#define   JPEG_DECODE_DC_Y_MIN_CODE_WORD_0__MIN_CODE_WORD_LENGTH0_SHFT                                               0
#define   JPEG_DECODE_DC_Y_MIN_CODE_WORD_0_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_DC_Y_MIN_CODE_WORD_0_SHFT                                                                      0

#define JPEG_DECODE_DC_Y_MIN_CODE_WORD_1_ADDR                                                             (0x000001AC)
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_1___RWC                                                          QCSR_REG_RW
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_1___POR                                                       0x00000000
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_1__MIN_CODE_WORD_LENGTH3_BMSK                                  0xFFFF0000
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_1__MIN_CODE_WORD_LENGTH3_SHFT                                              16
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_1__MIN_CODE_WORD_LENGTH2_BMSK                                  0x0000FFFF
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_1__MIN_CODE_WORD_LENGTH2_SHFT                                               0
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_1_BMSK                                                         0xFFFFFFFF
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_1_SHFT                                                                      0

#define JPEG_DECODE_DC_Y_MIN_CODE_WORD_2                                                             (0x000001B0)
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_2___RWC                                                          QCSR_REG_RW
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_2___POR                                                       0x00000000
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_2__MIN_CODE_WORD_LENGTH5_BMSK                                  0xFFFF0000
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_2__MIN_CODE_WORD_LENGTH5_SHFT                                              16
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_2__MIN_CODE_WORD_LENGTH4_BMSK                                  0x0000FFFF
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_2__MIN_CODE_WORD_LENGTH4_SHFT                                               0
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_2_BMSK                                                         0xFFFFFFFF
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_2_SHFT                                                                      0

#define JPEG_DECODE_DC_Y_MIN_CODE_WORD_3_ADDR                                                             (0x000001B4)
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_3___RWC                                                          QCSR_REG_RW
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_3___POR                                                       0x00000000
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_3__MIN_CODE_WORD_LENGTH7_BMSK                                  0xFFFF0000
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_3__MIN_CODE_WORD_LENGTH7_SHFT                                              16
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_3__MIN_CODE_WORD_LENGTH6_BMSK                                  0x0000FFFF
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_3__MIN_CODE_WORD_LENGTH6_SHFT                                               0
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_3_BMSK                                                         0xFFFFFFFF
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_3_SHFT                                                                      0

#define JPEG_DECODE_DC_Y_MIN_CODE_WORD_4_ADDR                                                             (0x000001B8)
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_4___RWC                                                          QCSR_REG_RW
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_4___POR                                                       0x00000000
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_4__MIN_CODE_WORD_LENGTH9_BMSK                                  0xFFFF0000
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_4__MIN_CODE_WORD_LENGTH9_SHFT                                              16
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_4__MIN_CODE_WORD_LENGTH8_BMSK                                  0x0000FFFF
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_4__MIN_CODE_WORD_LENGTH8_SHFT                                               0
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_4_BMSK                                                         0xFFFFFFFF
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_4_SHFT                                                                      0

#define JPEG_DECODE_DC_Y_MIN_CODE_WORD_5_ADDR                                                             (0x000001BC)
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_5___RWC                                                          QCSR_REG_RW
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_5___POR                                                       0x00000000
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_5__MIN_CODE_WORD_LENGTH11_BMSK                                 0xFFFF0000
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_5__MIN_CODE_WORD_LENGTH11_SHFT                                             16
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_5__MIN_CODE_WORD_LENGTH10_BMSK                                 0x0000FFFF
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_5__MIN_CODE_WORD_LENGTH10_SHFT                                              0
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_5_BMSK                                                         0xFFFFFFFF
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_5_SHFT                                                                      0

#define JPEG_DECODE_DC_Y_MIN_CODE_WORD_6_ADDR                                                             (0x000001C0)
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_6___RWC                                                          QCSR_REG_RW
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_6___POR                                                       0x00000000
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_6__MIN_CODE_WORD_LENGTH13_BMSK                                 0xFFFF0000
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_6__MIN_CODE_WORD_LENGTH13_SHFT                                             16
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_6__MIN_CODE_WORD_LENGTH12_BMSK                                 0x0000FFFF
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_6__MIN_CODE_WORD_LENGTH12_SHFT                                              0
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_6_BMSK                                                         0xFFFFFFFF
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_6_SHFT                                                                      0

#define JPEG_DECODE_DC_Y_MIN_CODE_WORD_7_ADDR                                                             (0x000001C4)
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_7___RWC                                                          QCSR_REG_RW
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_7___POR                                                       0x00000000
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_7__MIN_CODE_WORD_LENGTH15_BMSK                                 0xFFFF0000
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_7__MIN_CODE_WORD_LENGTH15_SHFT                                             16
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_7__MIN_CODE_WORD_LENGTH14_BMSK                                 0x0000FFFF
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_7__MIN_CODE_WORD_LENGTH14_SHFT                                              0
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_7_BMSK                                                         0xFFFFFFFF
#define    JPEG_DECODE_DC_Y_MIN_CODE_WORD_7_SHFT                                                                      0

#define JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_0_ADDR                                                     (0x000001C8)
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_0___RWC                                                  QCSR_REG_RW
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_0___POR                                               0x00000000
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH3_BMSK                                    0xFF000000
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH3_SHFT                                                24
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH2_BMSK                                    0x00FF0000
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH2_SHFT                                                16
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH1_BMSK                                    0x0000FF00
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH1_SHFT                                                 8
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH0_BMSK                                    0x000000FF
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH0_SHFT                                                 0
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_0_BMSK                                                 0xFFFFFFFF
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_0_SHFT                                                              0

#define JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_1_ADDR                                                     (0x000001CC)
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_1___RWC                                                  QCSR_REG_RW
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_1___POR                                               0x00000000
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH7_BMSK                                    0xFF000000
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH7_SHFT                                                24
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH6_BMSK                                    0x00FF0000
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH6_SHFT                                                16
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH5_BMSK                                    0x0000FF00
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH5_SHFT                                                 8
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH4_BMSK                                    0x000000FF
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH4_SHFT                                                 0
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_1_BMSK                                                 0xFFFFFFFF
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_1_SHFT                                                              0

#define JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_2_ADDR                                                     (0x000001D0)
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_2___RWC                                                  QCSR_REG_RW
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_2___POR                                               0x00000000
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH11_BMSK                                   0xFF000000
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH11_SHFT                                               24
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH10_BMSK                                   0x00FF0000
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH10_SHFT                                               16
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH9_BMSK                                    0x0000FF00
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH9_SHFT                                                 8
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH8_BMSK                                    0x000000FF
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH8_SHFT                                                 0
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_2_BMSK                                                 0xFFFFFFFF
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_2_SHFT                                                              0

#define JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_3_ADDR                                                     (0x000001D4)
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_3___RWC                                                  QCSR_REG_RW
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_3___POR                                               0x00000000
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH15_BMSK                                   0xFF000000
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH15_SHFT                                               24
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH14_BMSK                                   0x00FF0000
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH14_SHFT                                               16
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH13_BMSK                                   0x0000FF00
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH13_SHFT                                                8
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH12_BMSK                                   0x000000FF
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH12_SHFT                                                0
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_3_BMSK                                                 0xFFFFFFFF
#define   JPEG_DECODE_DC_C_CUMULATIVE_CODE_COUNT_3_SHFT                                                              0

#define JPEG_DECODE_DC_C_MIN_CODE_WORD_0_ADDR                                                             (0x000001D8)
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_0___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_0___POR                                                       0x00000000
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_0__MIN_CODE_WORD_LENGTH1_BMSK                                  0xFFFF0000
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_0__MIN_CODE_WORD_LENGTH1_SHFT                                              16
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_0__MIN_CODE_WORD_LENGTH0_BMSK                                  0x0000FFFF
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_0__MIN_CODE_WORD_LENGTH0_SHFT                                               0
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_0_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_0_SHFT                                                                      0

#define JPEG_DECODE_DC_C_MIN_CODE_WORD_1_ADDR                                                             (0x000001DC)
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_1___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_1___POR                                                       0x00000000
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_1__MIN_CODE_WORD_LENGTH3_BMSK                                  0xFFFF0000
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_1__MIN_CODE_WORD_LENGTH3_SHFT                                              16
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_1__MIN_CODE_WORD_LENGTH2_BMSK                                  0x0000FFFF
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_1__MIN_CODE_WORD_LENGTH2_SHFT                                               0
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_1_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_1_SHFT                                                                      0

#define JPEG_DECODE_DC_C_MIN_CODE_WORD_2_ADDR                                                             (0x000001E0)
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_2___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_2___POR                                                       0x00000000
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_2__MIN_CODE_WORD_LENGTH5_BMSK                                  0xFFFF0000
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_2__MIN_CODE_WORD_LENGTH5_SHFT                                              16
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_2__MIN_CODE_WORD_LENGTH4_BMSK                                  0x0000FFFF
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_2__MIN_CODE_WORD_LENGTH4_SHFT                                               0
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_2_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_2_SHFT                                                                      0

#define JPEG_DECODE_DC_C_MIN_CODE_WORD_3_ADDR                                                             (0x000001E4)
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_3___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_3___POR                                                       0x00000000
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_3__MIN_CODE_WORD_LENGTH7_BMSK                                  0xFFFF0000
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_3__MIN_CODE_WORD_LENGTH7_SHFT                                              16
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_3__MIN_CODE_WORD_LENGTH6_BMSK                                  0x0000FFFF
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_3__MIN_CODE_WORD_LENGTH6_SHFT                                               0
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_3_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_3_SHFT                                                                      0

#define JPEG_DECODE_DC_C_MIN_CODE_WORD_4_ADDR                                                             (0x000001E8)
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_4___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_4___POR                                                       0x00000000
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_4__MIN_CODE_WORD_LENGTH9_BMSK                                  0xFFFF0000
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_4__MIN_CODE_WORD_LENGTH9_SHFT                                              16
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_4__MIN_CODE_WORD_LENGTH8_BMSK                                  0x0000FFFF
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_4__MIN_CODE_WORD_LENGTH8_SHFT                                               0
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_4_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_4_SHFT                                                                      0

#define JPEG_DECODE_DC_C_MIN_CODE_WORD_5_ADDR                                                             (0x000001EC)
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_5___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_5___POR                                                       0x00000000
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_5__MIN_CODE_WORD_LENGTH11_BMSK                                 0xFFFF0000
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_5__MIN_CODE_WORD_LENGTH11_SHFT                                             16
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_5__MIN_CODE_WORD_LENGTH10_BMSK                                 0x0000FFFF
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_5__MIN_CODE_WORD_LENGTH10_SHFT                                              0
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_5_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_5_SHFT                                                                      0

#define JPEG_DECODE_DC_C_MIN_CODE_WORD_6_ADDR                                                             (0x000001F0)
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_6___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_6___POR                                                       0x00000000
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_6__MIN_CODE_WORD_LENGTH13_BMSK                                 0xFFFF0000
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_6__MIN_CODE_WORD_LENGTH13_SHFT                                             16
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_6__MIN_CODE_WORD_LENGTH12_BMSK                                 0x0000FFFF
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_6__MIN_CODE_WORD_LENGTH12_SHFT                                              0
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_6_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_6_SHFT                                                                      0

#define JPEG_DECODE_DC_C_MIN_CODE_WORD_7_ADDR                                                             (0x000001F4)
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_7___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_7___POR                                                       0x00000000
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_7__MIN_CODE_WORD_LENGTH15_BMSK                                 0xFFFF0000
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_7__MIN_CODE_WORD_LENGTH15_SHFT                                             16
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_7__MIN_CODE_WORD_LENGTH14_BMSK                                 0x0000FFFF
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_7__MIN_CODE_WORD_LENGTH14_SHFT                                              0
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_7_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_DC_C_MIN_CODE_WORD_7_SHFT                                                                      0

#define JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_0_ADDR                                                     (0x000001F8)
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_0___RWC                                                  QCSR_REG_RW
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_0___POR                                               0x00000000
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH3_BMSK                                    0xFF000000
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH3_SHFT                                                24
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH2_BMSK                                    0x00FF0000
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH2_SHFT                                                16
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH1_BMSK                                    0x0000FF00
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH1_SHFT                                                 8
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH0_BMSK                                    0x000000FF
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH0_SHFT                                                 0
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_0_BMSK                                                 0xFFFFFFFF
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_0_SHFT                                                              0

#define JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_1_ADDR                                                     (0x000001FC)
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_1___RWC                                                  QCSR_REG_RW
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_1___POR                                               0x00000000
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH7_BMSK                                    0xFF000000
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH7_SHFT                                                24
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH6_BMSK                                    0x00FF0000
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH6_SHFT                                                16
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH5_BMSK                                    0x0000FF00
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH5_SHFT                                                 8
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH4_BMSK                                    0x000000FF
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH4_SHFT                                                 0
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_1_BMSK                                                 0xFFFFFFFF
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_1_SHFT                                                              0

#define JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_2_ADDR                                                     (0x00000200)
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_2___RWC                                                  QCSR_REG_RW
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_2___POR                                               0x00000000
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH11_BMSK                                   0xFF000000
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH11_SHFT                                               24
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH10_BMSK                                   0x00FF0000
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH10_SHFT                                               16
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH9_BMSK                                    0x0000FF00
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH9_SHFT                                                 8
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH8_BMSK                                    0x000000FF
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH8_SHFT                                                 0
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_2_BMSK                                                 0xFFFFFFFF
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_2_SHFT                                                              0

#define JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_3_ADDR                                                     (0x00000204)
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_3___RWC                                                  QCSR_REG_RW
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_3___POR                                               0x00000000
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH15_BMSK                                   0xFF000000
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH15_SHFT                                               24
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH14_BMSK                                   0x00FF0000
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH14_SHFT                                               16
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH13_BMSK                                   0x0000FF00
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH13_SHFT                                                8
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH12_BMSK                                   0x000000FF
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH12_SHFT                                                0
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_3_BMSK                                                 0xFFFFFFFF
#define   JPEG_DECODE_AC_Y_CUMULATIVE_CODE_COUNT_3_SHFT                                                              0

#define JPEG_DECODE_AC_Y_MIN_CODE_WORD_0_ADDR                                                             (0x00000208)
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_0___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_0___POR                                                       0x00000000
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_0__MIN_CODE_WORD_LENGTH1_BMSK                                  0xFFFF0000
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_0__MIN_CODE_WORD_LENGTH1_SHFT                                              16
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_0__MIN_CODE_WORD_LENGTH0_BMSK                                  0x0000FFFF
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_0__MIN_CODE_WORD_LENGTH0_SHFT                                               0
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_0_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_0_SHFT                                                                      0

#define JPEG_DECODE_AC_Y_MIN_CODE_WORD_1                                                             (0x0000020C)
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_1___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_1___POR                                                       0x00000000
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_1__MIN_CODE_WORD_LENGTH3_BMSK                                  0xFFFF0000
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_1__MIN_CODE_WORD_LENGTH3_SHFT                                              16
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_1__MIN_CODE_WORD_LENGTH2_BMSK                                  0x0000FFFF
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_1__MIN_CODE_WORD_LENGTH2_SHFT                                               0
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_1_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_1_SHFT                                                                      0

#define JPEG_DECODE_AC_Y_MIN_CODE_WORD_2                                                             (0x00000210)
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_2___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_2___POR                                                       0x00000000
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_2__MIN_CODE_WORD_LENGTH5_BMSK                                  0xFFFF0000
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_2__MIN_CODE_WORD_LENGTH5_SHFT                                              16
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_2__MIN_CODE_WORD_LENGTH4_BMSK                                  0x0000FFFF
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_2__MIN_CODE_WORD_LENGTH4_SHFT                                               0
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_2_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_2_SHFT                                                                      0

#define JPEG_DECODE_AC_Y_MIN_CODE_WORD_3_ADDR                                                             (0x00000214)
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_3___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_3___POR                                                       0x00000000
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_3__MIN_CODE_WORD_LENGTH7_BMSK                                  0xFFFF0000
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_3__MIN_CODE_WORD_LENGTH7_SHFT                                              16
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_3__MIN_CODE_WORD_LENGTH6_BMSK                                  0x0000FFFF
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_3__MIN_CODE_WORD_LENGTH6_SHFT                                               0
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_3_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_3_SHFT                                                                      0

#define JPEG_DECODE_AC_Y_MIN_CODE_WORD_4_ADDR                                                             (0x00000218)
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_4___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_4___POR                                                       0x00000000
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_4__MIN_CODE_WORD_LENGTH9_BMSK                                  0xFFFF0000
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_4__MIN_CODE_WORD_LENGTH9_SHFT                                              16
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_4__MIN_CODE_WORD_LENGTH8_BMSK                                  0x0000FFFF
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_4__MIN_CODE_WORD_LENGTH8_SHFT                                               0
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_4_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_4_SHFT                                                                      0

#define JPEG_DECODE_AC_Y_MIN_CODE_WORD_5_ADDR                                                             (0x0000021C)
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_5___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_5___POR                                                       0x00000000
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_5__MIN_CODE_WORD_LENGTH11_BMSK                                 0xFFFF0000
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_5__MIN_CODE_WORD_LENGTH11_SHFT                                             16
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_5__MIN_CODE_WORD_LENGTH10_BMSK                                 0x0000FFFF
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_5__MIN_CODE_WORD_LENGTH10_SHFT                                              0
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_5_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_5_SHFT                                                                      0

#define JPEG_DECODE_AC_Y_MIN_CODE_WORD_6_ADDR                                                             (0x00000220)
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_6___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_6___POR                                                       0x00000000
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_6__MIN_CODE_WORD_LENGTH13_BMSK                                 0xFFFF0000
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_6__MIN_CODE_WORD_LENGTH13_SHFT                                             16
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_6__MIN_CODE_WORD_LENGTH12_BMSK                                 0x0000FFFF
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_6__MIN_CODE_WORD_LENGTH12_SHFT                                              0
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_6_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_6_SHFT                                                                      0

#define JPEG_DECODE_AC_Y_MIN_CODE_WORD_7_ADDR                                                             (0x00000224)
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_7___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_7___POR                                                       0x00000000
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_7__MIN_CODE_WORD_LENGTH15_BMSK                                 0xFFFF0000
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_7__MIN_CODE_WORD_LENGTH15_SHFT                                             16
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_7__MIN_CODE_WORD_LENGTH14_BMSK                                 0x0000FFFF
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_7__MIN_CODE_WORD_LENGTH14_SHFT                                              0
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_7_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_AC_Y_MIN_CODE_WORD_7_SHFT                                                                      0

#define JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_0_ADDR                                                     (0x00000228)
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_0___RWC                                                  QCSR_REG_RW
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_0___POR                                               0x00000000
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH3_BMSK                                    0xFF000000
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH3_SHFT                                                24
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH2_BMSK                                    0x00FF0000
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH2_SHFT                                                16
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH1_BMSK                                    0x0000FF00
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH1_SHFT                                                 8
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH0_BMSK                                    0x000000FF
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_0__CCC_LENGTH0_SHFT                                                 0
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_0_BMSK                                                 0xFFFFFFFF
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_0_SHFT                                                              0

#define JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_1_ADDR                                                     (0x0000022C)
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_1___RWC                                                  QCSR_REG_RW
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_1___POR                                               0x00000000
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH7_BMSK                                    0xFF000000
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH7_SHFT                                                24
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH6_BMSK                                    0x00FF0000
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH6_SHFT                                                16
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH5_BMSK                                    0x0000FF00
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH5_SHFT                                                 8
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH4_BMSK                                    0x000000FF
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_1__CCC_LENGTH4_SHFT                                                 0
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_1_BMSK                                                 0xFFFFFFFF
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_1_SHFT                                                              0

#define JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_2_ADDR                                                     (0x00000230)
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_2___RWC                                                  QCSR_REG_RW
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_2___POR                                               0x00000000
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH11_BMSK                                   0xFF000000
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH11_SHFT                                               24
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH10_BMSK                                   0x00FF0000
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH10_SHFT                                               16
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH9_BMSK                                    0x0000FF00
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH9_SHFT                                                 8
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH8_BMSK                                    0x000000FF
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_2__CCC_LENGTH8_SHFT                                                 0
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_2_BMSK                                                 0xFFFFFFFF
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_2_SHFT                                                              0

#define JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_3_ADDR                                                     (0x00000234)
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_3___RWC                                                  QCSR_REG_RW
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_3___POR                                               0x00000000
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH15_BMSK                                   0xFF000000
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH15_SHFT                                               24
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH14_BMSK                                   0x00FF0000
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH14_SHFT                                               16
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH13_BMSK                                   0x0000FF00
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH13_SHFT                                                8
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH12_BMSK                                   0x000000FF
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_3__CCC_LENGTH12_SHFT                                                0
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_3_BMSK                                                 0xFFFFFFFF
#define   JPEG_DECODE_AC_C_CUMULATIVE_CODE_COUNT_3_SHFT                                                              0

#define JPEG_DECODE_AC_C_MIN_CODE_WORD_0_ADDR                                                             (0x00000238)
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_0___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_0___POR                                                       0x00000000
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_0__MIN_CODE_WORD_LENGTH1_BMSK                                  0xFFFF0000
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_0__MIN_CODE_WORD_LENGTH1_SHFT                                              16
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_0__MIN_CODE_WORD_LENGTH0_BMSK                                  0x0000FFFF
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_0__MIN_CODE_WORD_LENGTH0_SHFT                                               0
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_0_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_0_SHFT                                                                      0

#define JPEG_DECODE_AC_C_MIN_CODE_WORD_1_ADDR                                                             (0x0000023C)
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_1___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_1___POR                                                       0x00000000
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_1__MIN_CODE_WORD_LENGTH3_BMSK                                  0xFFFF0000
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_1__MIN_CODE_WORD_LENGTH3_SHFT                                              16
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_1__MIN_CODE_WORD_LENGTH2_BMSK                                  0x0000FFFF
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_1__MIN_CODE_WORD_LENGTH2_SHFT                                               0
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_1_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_1_SHFT                                                                      0

#define JPEG_DECODE_AC_C_MIN_CODE_WORD_2_ADDR                                                             (0x00000240)
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_2___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_2___POR                                                       0x00000000
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_2__MIN_CODE_WORD_LENGTH5_BMSK                                  0xFFFF0000
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_2__MIN_CODE_WORD_LENGTH5_SHFT                                              16
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_2__MIN_CODE_WORD_LENGTH4_BMSK                                  0x0000FFFF
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_2__MIN_CODE_WORD_LENGTH4_SHFT                                               0
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_2_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_2_SHFT                                                                      0

#define JPEG_DECODE_AC_C_MIN_CODE_WORD_3_ADDR                                                              (0x00000244)
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_3___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_3___POR                                                       0x00000000
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_3__MIN_CODE_WORD_LENGTH7_BMSK                                  0xFFFF0000
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_3__MIN_CODE_WORD_LENGTH7_SHFT                                              16
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_3__MIN_CODE_WORD_LENGTH6_BMSK                                  0x0000FFFF
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_3__MIN_CODE_WORD_LENGTH6_SHFT                                               0
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_3_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_3_SHFT                                                                      0

#define JPEG_DECODE_AC_C_MIN_CODE_WORD_4_ADDR                                                              (0x00000248)
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_4___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_4___POR                                                       0x00000000
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_4__MIN_CODE_WORD_LENGTH9_BMSK                                  0xFFFF0000
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_4__MIN_CODE_WORD_LENGTH9_SHFT                                              16
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_4__MIN_CODE_WORD_LENGTH8_BMSK                                  0x0000FFFF
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_4__MIN_CODE_WORD_LENGTH8_SHFT                                               0
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_4_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_4_SHFT                                                                      0

#define JPEG_DECODE_AC_C_MIN_CODE_WORD_5_ADDR                                                              (0x0000024C)
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_5___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_5___POR                                                       0x00000000
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_5__MIN_CODE_WORD_LENGTH11_BMSK                                 0xFFFF0000
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_5__MIN_CODE_WORD_LENGTH11_SHFT                                             16
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_5__MIN_CODE_WORD_LENGTH10_BMSK                                 0x0000FFFF
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_5__MIN_CODE_WORD_LENGTH10_SHFT                                              0
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_5_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_5_SHFT                                                                      0

#define JPEG_DECODE_AC_C_MIN_CODE_WORD_6_ADDR                                                              (0x00000250)
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_6___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_6___POR                                                       0x00000000
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_6__MIN_CODE_WORD_LENGTH13_BMSK                                 0xFFFF0000
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_6__MIN_CODE_WORD_LENGTH13_SHFT                                             16
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_6__MIN_CODE_WORD_LENGTH12_BMSK                                 0x0000FFFF
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_6__MIN_CODE_WORD_LENGTH12_SHFT                                              0
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_6_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_6_SHFT                                                                      0

#define JPEG_DECODE_AC_C_MIN_CODE_WORD_7_ADDR                                                              (0x00000254)
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_7___RWC                                                          QCSR_REG_RW
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_7___POR                                                       0x00000000
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_7__MIN_CODE_WORD_LENGTH15_BMSK                                 0xFFFF0000
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_7__MIN_CODE_WORD_LENGTH15_SHFT                                             16
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_7__MIN_CODE_WORD_LENGTH14_BMSK                                 0x0000FFFF
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_7__MIN_CODE_WORD_LENGTH14_SHFT                                              0
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_7_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_AC_C_MIN_CODE_WORD_7_SHFT                                                                      0

#define JPEG_DECODE_MCUS_DECODED_STATUS_ADDR                                                               (0x00000258)
#define   JPEG_DECODE_MCUS_DECODED_STATUS___RWC                                                           QCSR_REG_RO
#define   JPEG_DECODE_MCUS_DECODED_STATUS___POR                                                        0x00000000
#define   JPEG_DECODE_MCUS_DECODED_STATUS__MCUS_DECODED_BMSK                                            0x1FFFFFFF
#define   JPEG_DECODE_MCUS_DECODED_STATUS__MCUS_DECODED_SHFT                                                         0
#define   JPEG_DECODE_MCUS_DECODED_STATUS_BMSK                                                          0x1FFFFFFF
#define   JPEG_DECODE_MCUS_DECODED_STATUS_SHFT                                                                       0

#define JPEG_DECODE_BITS_CONSUMED_STATUS_ADDR                                                              (0x0000025C)
#define   JPEG_DECODE_BITS_CONSUMED_STATUS___RWC                                                          QCSR_REG_RO
#define   JPEG_DECODE_BITS_CONSUMED_STATUS___POR                                                       0x00000000
#define   JPEG_DECODE_BITS_CONSUMED_STATUS__BITS_CONSUMED_BMSK                                          0xFFFFFFFF
#define   JPEG_DECODE_BITS_CONSUMED_STATUS__BITS_CONSUMED_SHFT                                                       0
#define   JPEG_DECODE_BITS_CONSUMED_STATUS_BMSK                                                         0xFFFFFFFF
#define   JPEG_DECODE_BITS_CONSUMED_STATUS_SHFT                                                                      0

#define JPEG_DECODE_PREDICTION_Y_STATE_ADDR                                                                (0x00000260)
#define   JPEG_DECODE_PREDICTION_Y_STATE___RWC                                                            QCSR_REG_RW
#define   JPEG_DECODE_PREDICTION_Y_STATE___POR                                                         0x00000000
#define   JPEG_DECODE_PREDICTION_Y_STATE__PREDICTION_Y_STATE_BMSK                                       0x000007FF
#define   JPEG_DECODE_PREDICTION_Y_STATE__PREDICTION_Y_STATE_SHFT                                                    0
#define   JPEG_DECODE_PREDICTION_Y_STATE_BMSK                                                           0x000007FF
#define   JPEG_DECODE_PREDICTION_Y_STATE_SHFT                                                                        0

#define JPEG_DECODE_PREDICTION_C_STATE_ADDR                                                                (0x00000264)
#define   JPEG_DECODE_PREDICTION_C_STATE___RWC                                                            QCSR_REG_RW
#define   JPEG_DECODE_PREDICTION_C_STATE___POR                                                         0x00000000
#define   JPEG_DECODE_PREDICTION_C_STATE__PREDICTION_CR_STATE_BMSK                                      0x07FF0000
#define   JPEG_DECODE_PREDICTION_C_STATE__PREDICTION_CR_STATE_SHFT                                                  16
#define   JPEG_DECODE_PREDICTION_C_STATE__PREDICTION_CB_STATE_BMSK                                      0x000007FF
#define   JPEG_DECODE_PREDICTION_C_STATE__PREDICTION_CB_STATE_SHFT                                                   0
#define   JPEG_DECODE_PREDICTION_C_STATE_BMSK                                                           0x07FFFFFF
#define   JPEG_DECODE_PREDICTION_C_STATE_SHFT                                                                        0

#define JPEG_DECODE_RSM_STATE_ADDR                                                                         (0x00000268)
#define   JPEG_DECODE_RSM_STATE___RWC                                                                     QCSR_REG_RW
#define   JPEG_DECODE_RSM_STATE___POR                                                                  0x00000000
#define   JPEG_DECODE_RSM_STATE__RST_MARKER_VALUE_BMSK                                                  0x00070000
#define   JPEG_DECODE_RSM_STATE__RST_MARKER_VALUE_SHFT                                                              16
#define   JPEG_DECODE_RSM_STATE__RST_MARKER_MCU_COUNT_BMSK                                              0x0000FFFF
#define   JPEG_DECODE_RSM_STATE__RST_MARKER_MCU_COUNT_SHFT                                                           0
#define   JPEG_DECODE_RSM_STATE_BMSK                                                                    0x0007FFFF
#define   JPEG_DECODE_RSM_STATE_SHFT                                                                                 0

#define JPEG_SCALE_CFG_ADDR                                                                                (0x0000026C)
#define   JPEG_SCALE_CFG___RWC                                                                            QCSR_REG_RW
#define   JPEG_SCALE_CFG___POR                                                                         0x00000000
#define   JPEG_SCALE_CFG__V_SCALE_FIR_ALGORITHM_BMSK                                                    0x00030000
#define   JPEG_SCALE_CFG__V_SCALE_FIR_ALGORITHM_SHFT                                                                16
#define   JPEG_SCALE_CFG__V_SCALE_FIR_ALGORITHM__BI_LINEAR                                                        0x0
#define   JPEG_SCALE_CFG__V_SCALE_FIR_ALGORITHM__BI_CUBIC                                                         0x1
#define   JPEG_SCALE_CFG__V_SCALE_FIR_ALGORITHM__NEAREST_NEIGHBORHOOD                                             0x2
#define   JPEG_SCALE_CFG__H_SCALE_FIR_ALGORITHM_BMSK                                                    0x00003000
#define   JPEG_SCALE_CFG__H_SCALE_FIR_ALGORITHM_SHFT                                                                12
#define   JPEG_SCALE_CFG__H_SCALE_FIR_ALGORITHM__BI_LINEAR                                                        0x0
#define   JPEG_SCALE_CFG__H_SCALE_FIR_ALGORITHM__BI_CUBIC                                                         0x1
#define   JPEG_SCALE_CFG__H_SCALE_FIR_ALGORITHM__NEAREST_NEIGHBORHOOD                                             0x2
#define   JPEG_SCALE_CFG__VSCALE_ALGORITHM_BMSK                                                         0x00000200
#define   JPEG_SCALE_CFG__VSCALE_ALGORITHM_SHFT                                                                      9
#define   JPEG_SCALE_CFG__VSCALE_ALGORITHM__MN_DOWNSCALE                                                          0x0
#define   JPEG_SCALE_CFG__VSCALE_ALGORITHM__FIR_UPSCALE                                                           0x1
#define   JPEG_SCALE_CFG__HSCALE_ALGORITHM_BMSK                                                         0x00000100
#define   JPEG_SCALE_CFG__HSCALE_ALGORITHM_SHFT                                                                      8
#define   JPEG_SCALE_CFG__HSCALE_ALGORITHM__MN_DOWNSCALE                                                          0x0
#define   JPEG_SCALE_CFG__HSCALE_ALGORITHM__FIR_UPSCALE                                                           0x1
#define   JPEG_SCALE_CFG__SUBSAMPLE_EN_BMSK                                                             0x00000080
#define   JPEG_SCALE_CFG__SUBSAMPLE_EN_SHFT                                                                          7
#define   JPEG_SCALE_CFG__SUBSAMPLE_EN__SUBSAMPLE_DISABLED                                                        0x0
#define   JPEG_SCALE_CFG__SUBSAMPLE_EN__SUBSAMPLE_ENABLED                                                         0x1
#define   JPEG_SCALE_CFG__UPSAMPLE_EN_BMSK                                                              0x00000040
#define   JPEG_SCALE_CFG__UPSAMPLE_EN_SHFT                                                                           6
#define   JPEG_SCALE_CFG__UPSAMPLE_EN__UPSAMPLE_DISABLED                                                          0x0
#define   JPEG_SCALE_CFG__UPSAMPLE_EN__UPSAMPLE_ENABLED                                                           0x1
#define   JPEG_SCALE_CFG__VSCALE_ENABLE_BMSK                                                            0x00000020
#define   JPEG_SCALE_CFG__VSCALE_ENABLE_SHFT                                                                         5
#define   JPEG_SCALE_CFG__VSCALE_ENABLED                                                                          0x1
#define   JPEG_SCALE_CFG__HSCALE_ENABLE_BMSK                                                            0x00000010
#define   JPEG_SCALE_CFG__HSCALE_ENABLE_SHFT                                                                         4
#define   JPEG_SCALE_CFG__HSCALE_ENABLED                                                                           0x1
#define   JPEG_SCALE_CFG_BMSK                                                                           0x0003FFF0
#define   JPEG_SCALE_CFG_SHFT                                                                                        4

#define JPEG_SCALE_PLN0_OUTPUT_CFG_ADDR                                                                    (0x00000270)
#define   JPEG_SCALE_PLN0_OUTPUT_CFG___RWC                                                                QCSR_REG_RW
#define   JPEG_SCALE_PLN0_OUTPUT_CFG___POR                                                             0x00000000
#define   JPEG_SCALE_PLN0_OUTPUT_CFG__BLOCK_HEIGHT_BMSK                                                 0x000F0000
#define   JPEG_SCALE_PLN0_OUTPUT_CFG__BLOCK_HEIGHT_SHFT                                                             16
#define   JPEG_SCALE_PLN0_OUTPUT_CFG__BLOCK_WIDTH_BMSK                                                  0x0000000F
#define   JPEG_SCALE_PLN0_OUTPUT_CFG__BLOCK_WIDTH_SHFT                                                               0
#define   JPEG_SCALE_PLN0_OUTPUT_CFG_BMSK                                                               0x000FFFFF
#define   JPEG_SCALE_PLN0_OUTPUT_CFG_SHFT                                                                            0

#define JPEG_SCALE_PLN1_OUTPUT_CFG_ADDR                                                                    (0x00000274)
#define   JPEG_SCALE_PLN1_OUTPUT_CFG___RWC                                                                QCSR_REG_RW
#define   JPEG_SCALE_PLN1_OUTPUT_CFG___POR                                                             0x00000000
#define   JPEG_SCALE_PLN1_OUTPUT_CFG__BLOCK_HEIGHT_BMSK                                                 0x000F0000
#define   JPEG_SCALE_PLN1_OUTPUT_CFG__BLOCK_HEIGHT_SHFT                                                             16
#define   JPEG_SCALE_PLN1_OUTPUT_CFG__BLOCK_WIDTH_BMSK                                                  0x0000000F
#define   JPEG_SCALE_PLN1_OUTPUT_CFG__BLOCK_WIDTH_SHFT                                                               0
#define   JPEG_SCALE_PLN1_OUTPUT_CFG_BMSK                                                               0x000FFFFF
#define   JPEG_SCALE_PLN1_OUTPUT_CFG_SHFT                                                                            0

#define JPEG_SCALE_PLN2_OUTPUT_CFG_ADDR                                                                    (0x00000278)
#define   JPEG_SCALE_PLN2_OUTPUT_CFG___RWC                                                                QCSR_REG_RW
#define   JPEG_SCALE_PLN2_OUTPUT_CFG___POR                                                             0x00000000
#define   JPEG_SCALE_PLN2_OUTPUT_CFG__BLOCK_HEIGHT_BMSK                                                 0x000F0000
#define   JPEG_SCALE_PLN2_OUTPUT_CFG__BLOCK_HEIGHT_SHFT                                                             16
#define   JPEG_SCALE_PLN2_OUTPUT_CFG__BLOCK_WIDTH_BMSK                                                  0x0000000F
#define   JPEG_SCALE_PLN2_OUTPUT_CFG__BLOCK_WIDTH_SHFT                                                               0
#define   JPEG_SCALE_PLN2_OUTPUT_CFG_BMSK                                                               0x000FFFFF
#define   JPEG_SCALE_PLN2_OUTPUT_CFG_SHFT                                                                            0

#define JPEG_SCALE_PLN0_HSTEP_ADDR                                                                         (0x0000027C)
#define   JPEG_SCALE_PLN0_HSTEP___RWC                                                                     QCSR_REG_RW
#define   JPEG_SCALE_PLN0_HSTEP___POR                                                                  0x00000000
#define   JPEG_SCALE_PLN0_HSTEP__INTEGER_BMSK                                                           0x03E00000
#define   JPEG_SCALE_PLN0_HSTEP__INTEGER_SHFT                                                                       21
#define   JPEG_SCALE_PLN0_HSTEP__FRACTIONAL_BMSK                                                        0x001FFFFF
#define   JPEG_SCALE_PLN0_HSTEP__FRACTIONAL_SHFT                                                                     0
#define   JPEG_SCALE_PLN0_HSTEP_BMSK                                                                    0x03FFFFFF
#define   JPEG_SCALE_PLN0_HSTEP_SHFT                                                                                 0

#define JPEG_SCALE_PLN1_HSTEP_ADDR                                                                         (0x00000280)
#define   JPEG_SCALE_PLN1_HSTEP___RWC                                                                     QCSR_REG_RW
#define   JPEG_SCALE_PLN1_HSTEP___POR                                                                  0x00000000
#define   JPEG_SCALE_PLN1_HSTEP__INTEGER_BMSK                                                           0x03E00000
#define   JPEG_SCALE_PLN1_HSTEP__INTEGER_SHFT                                                                       21
#define   JPEG_SCALE_PLN1_HSTEP__FRACTIONAL_BMSK                                                        0x001FFFFF
#define   JPEG_SCALE_PLN1_HSTEP__FRACTIONAL_SHFT                                                                     0
#define   JPEG_SCALE_PLN1_HSTEP_BMSK                                                                    0x03FFFFFF
#define   JPEG_SCALE_PLN1_HSTEP_SHFT                                                                                 0

#define JPEG_SCALE_PLN2_HSTEP_ADDR                                                                         (0x00000284)
#define   JPEG_SCALE_PLN2_HSTEP___RWC                                                                     QCSR_REG_RW
#define   JPEG_SCALE_PLN2_HSTEP___POR                                                                  0x00000000
#define   JPEG_SCALE_PLN2_HSTEP__INTEGER_BMSK                                                           0x03E00000
#define   JPEG_SCALE_PLN2_HSTEP__INTEGER_SHFT                                                                       21
#define   JPEG_SCALE_PLN2_HSTEP__FRACTIONAL_BMSK                                                        0x001FFFFF
#define   JPEG_SCALE_PLN2_HSTEP__FRACTIONAL_SHFT                                                                     0
#define   JPEG_SCALE_PLN2_HSTEP_BMSK                                                                    0x03FFFFFF
#define   JPEG_SCALE_PLN2_HSTEP_SHFT                                                                                 0

#define JPEG_SCALE_PLN0_VSTEP_ADDR                                                                         (0x0000028C)
#define   JPEG_SCALE_PLN0_VSTEP___RWC                                                                     QCSR_REG_RW
#define   JPEG_SCALE_PLN0_VSTEP___POR                                                                  0x00000000
#define   JPEG_SCALE_PLN0_VSTEP__INTEGER_BMSK                                                           0x03E00000
#define   JPEG_SCALE_PLN0_VSTEP__INTEGER_SHFT                                                                       21
#define   JPEG_SCALE_PLN0_VSTEP__FRACTIONAL_BMSK                                                        0x001FFFFF
#define   JPEG_SCALE_PLN0_VSTEP__FRACTIONAL_SHFT                                                                     0
#define   JPEG_SCALE_PLN0_VSTEP_BMSK                                                                    0x03FFFFFF
#define   JPEG_SCALE_PLN0_VSTEP_SHFT                                                                                 0

#define JPEG_SCALE_PLN1_VSTEP_ADDR                                                                         (0x00000290)
#define   JPEG_SCALE_PLN1_VSTEP___RWC                                                                     QCSR_REG_RW
#define   JPEG_SCALE_PLN1_VSTEP___POR                                                                  0x00000000
#define   JPEG_SCALE_PLN1_VSTEP__INTEGER_BMSK                                                           0x03E00000
#define   JPEG_SCALE_PLN1_VSTEP__INTEGER_SHFT                                                                       21
#define   JPEG_SCALE_PLN1_VSTEP__FRACTIONAL_BMSK                                                        0x001FFFFF
#define   JPEG_SCALE_PLN1_VSTEP__FRACTIONAL_SHFT                                                                     0
#define   JPEG_SCALE_PLN1_VSTEP_BMSK                                                                    0x03FFFFFF
#define   JPEG_SCALE_PLN1_VSTEP_SHFT                                                                                 0

#define JPEG_SCALE_PLN2_VSTEP_ADDR                                                                         (0x00000294)
#define   JPEG_SCALE_PLN2_VSTEP___RWC                                                                     QCSR_REG_RW
#define   JPEG_SCALE_PLN2_VSTEP___POR                                                                  0x00000000
#define   JPEG_SCALE_PLN2_VSTEP__INTEGER_BMSK                                                           0x03E00000
#define   JPEG_SCALE_PLN2_VSTEP__INTEGER_SHFT                                                                       21
#define   JPEG_SCALE_PLN2_VSTEP__FRACTIONAL_BMSK                                                        0x001FFFFF
#define   JPEG_SCALE_PLN2_VSTEP__FRACTIONAL_SHFT                                                                     0
#define   JPEG_SCALE_PLN2_VSTEP_BMSK                                                                    0x03FFFFFF
#define   JPEG_SCALE_PLN2_VSTEP_SHFT                                                                                 0

#define JPEG_DMI_CFG_ADDR                                                                                  (0x00000298)
#define   JPEG_DMI_CFG___RWC                                                                              QCSR_REG_RW
#define   JPEG_DMI_CFG___POR                                                                           0x00000000
#define   JPEG_DMI_CFG__AUTO_INC_EN_BMSK                                                                0x00000010
#define   JPEG_DMI_CFG__AUTO_INC_EN_SHFT                                                                             4
#define   JPEG_DMI_CFG__DMI_MEM_SEL_BMSK                                                                0x00000007
#define   JPEG_DMI_CFG__DMI_MEM_SEL_SHFT                                                                             0
#define   JPEG_DMI_CFG__DMI_MEM_SEL__NO_MEMORY_SELECTED                                                           0x0
#define   JPEG_DMI_CFG__DMI_MEM_SEL__QUANTIZATION_LUT                                                             0x1
#define   JPEG_DMI_CFG__DMI_MEM_SEL__HUFFMAN_LUT                                                                  0x2
#define   JPEG_DMI_CFG_BMSK                                                                             0x0000001F
#define   JPEG_DMI_CFG_SHFT                                                                                          0

#define JPEG_DMI_ADDR_ADDR                                                                                 (0x0000029C)
#define   JPEG_DMI_ADDR___RWC                                                                             QCSR_REG_RW
#define   JPEG_DMI_ADDR___POR                                                                          0x00000000
#define   JPEG_DMI_ADDR__DMI_ADDR_BMSK                                                                  0x000003FF
#define   JPEG_DMI_ADDR__DMI_ADDR_SHFT                                                                               0
#define   JPEG_DMI_ADDR_BMSK                                                                            0x000003FF
#define   JPEG_DMI_ADDR_SHFT                                                                                         0

#define JPEG_DMI_DATA_ADDR                                                                                 (0x000002A0)
#define   JPEG_DMI_DATA___RWC                                                                             QCSR_REG_RW
#define   JPEG_DMI_DATA___POR                                                                          0x00000000
#define   JPEG_DMI_DATA__DMI_DATA_BMSK                                                                  0xFFFFFFFF
#define   JPEG_DMI_DATA__DMI_DATA_SHFT                                                                               0
#define   JPEG_DMI_DATA_BMSK                                                                            0xFFFFFFFF
#define   JPEG_DMI_DATA_SHFT                                                                                         0

#define JPEG_DEBUG_CFG_ADDR                                                                                (0x000002A4)
#define   JPEG_DEBUG_CFG___RWC                                                                            QCSR_REG_RW
#define   JPEG_DEBUG_CFG___POR                                                                         0x00000000
#define   JPEG_DEBUG_CFG__DEBUG_SEL_BMSK                                                                0xFFFFFFFF
#define   JPEG_DEBUG_CFG__DEBUG_SEL_SHFT                                                                             0
#define   JPEG_DEBUG_CFG__DEBUG_SEL__WE_PEAK_BUFFER_LEVEL                                                      0x0000
#define   JPEG_DEBUG_CFG_BMSK                                                                           0xFFFFFFFF
#define   JPEG_DEBUG_CFG_SHFT                                                                                        0

#define JPEG_DEBUG_RD_ADDR                                                                                 (0x000002A8)
#define   JPEG_DEBUG_RD___RWC                                                                             QCSR_REG_RO
#define   JPEG_DEBUG_RD___POR                                                                          0x00000000
#define   JPEG_DEBUG_RD__DEBUG_DATA_BMSK                                                                0xFFFFFFFF
#define   JPEG_DEBUG_RD__DEBUG_DATA_SHFT                                                                             0
#define   JPEG_DEBUG_RD_BMSK                                                                            0xFFFFFFFF
#define   JPEG_DEBUG_RD_SHFT                                                                                         0

#define JPEG_ATB_CFG_ADDR                                                                                  (0x000002AC)
#define   JPEG_ATB_CFG___RWC                                                                              QCSR_REG_RW
#define   JPEG_ATB_CFG___POR                                                                           0x00000000
#define   JPEG_ATB_CFG__ATB_EN_BMSK                                                                     0x80000000
#define   JPEG_ATB_CFG__ATB_EN_SHFT                                                                                 31
#define   JPEG_ATB_CFG__ATID_BMSK                                                                       0x00007F00
#define   JPEG_ATB_CFG__ATID_SHFT                                                                                    8
#define   JPEG_ATB_CFG__BUS_SEL_BMSK                                                                    0x0000001F
#define   JPEG_ATB_CFG__BUS_SEL_SHFT                                                                                 0
#define   JPEG_ATB_CFG_BMSK                                                                             0xFFFFFFFF
#define   JPEG_ATB_CFG_SHFT                                                                                          0

#define JPEG_TESTBUS_CFG_ADDR                                                                              (0x000002B0)
#define   JPEG_TESTBUS_CFG___RWC                                                                          QCSR_REG_RW
#define   JPEG_TESTBUS_CFG___POR                                                                       0x00000000
#define   JPEG_TESTBUS_CFG__BUS_SEL_BMSK                                                                0x0000003F
#define   JPEG_TESTBUS_CFG__BUS_SEL_SHFT                                                                             0
#define   JPEG_TESTBUS_CFG_BMSK                                                                         0x0000003F
#define   JPEG_TESTBUS_CFG_SHFT                                                                                      0

#define JPEG_MISR_CFG_ADDR                                                                                 (0x000002B4)
#define   JPEG_MISR_CFG___RWC                                                                             QCSR_REG_RW
#define   JPEG_MISR_CFG___POR                                                                          0x00000000
#define   JPEG_MISR_CFG__MISR2_EN_BMSK                                                                  0x00000004
#define   JPEG_MISR_CFG__MISR2_EN_SHFT                                                                               2
#define   JPEG_MISR_CFG__MISR1_EN_BMSK                                                                  0x00000002
#define   JPEG_MISR_CFG__MISR1_EN_SHFT                                                                               1
#define   JPEG_MISR_CFG__MISR0_EN_BMSK                                                                  0x00000001
#define   JPEG_MISR_CFG__MISR0_EN_SHFT                                                                               0
#define   JPEG_MISR_CFG_BMSK                                                                            0x00000007
#define   JPEG_MISR_CFG_SHFT                                                                                         0

#define JPEG_MISR0_RD0_ADDR                                                                                (0x000002B8)
#define   JPEG_MISR0_RD0___RWC                                                                            QCSR_REG_RO
#define   JPEG_MISR0_RD0___POR                                                                         0x00000000
#define   JPEG_MISR0_RD0__VALUE_BMSK                                                                    0xFFFFFFFF
#define   JPEG_MISR0_RD0__VALUE_SHFT                                                                                 0
#define   JPEG_MISR0_RD0_BMSK                                                                           0xFFFFFFFF
#define   JPEG_MISR0_RD0_SHFT                                                                                        0

#define JPEG_MISR0_RD1_ADDR                                                                                (0x000002BC)
#define   JPEG_MISR0_RD1___RWC                                                                            QCSR_REG_RO
#define   JPEG_MISR0_RD1___POR                                                                         0x00000000
#define   JPEG_MISR0_RD1__VALUE_BMSK                                                                    0xFFFFFFFF
#define   JPEG_MISR0_RD1__VALUE_SHFT                                                                                 0
#define   JPEG_MISR0_RD1_BMSK                                                                           0xFFFFFFFF
#define   JPEG_MISR0_RD1_SHFT                                                                                        0

#define JPEG_MISR0_RD2_ADDR                                                                                (0x000002C0)
#define   JPEG_MISR0_RD2___RWC                                                                            QCSR_REG_RO
#define   JPEG_MISR0_RD2___POR                                                                         0x00000000
#define   JPEG_MISR0_RD2__VALUE_BMSK                                                                    0xFFFFFFFF
#define   JPEG_MISR0_RD2__VALUE_SHFT                                                                                 0
#define   JPEG_MISR0_RD2_BMSK                                                                           0xFFFFFFFF
#define   JPEG_MISR0_RD2_SHFT                                                                                        0

#define JPEG_MISR0_RD3_ADDR                                                                                (0x000002C4)
#define   JPEG_MISR0_RD3___RWC                                                                            QCSR_REG_RO
#define   JPEG_MISR0_RD3___POR                                                                         0x00000000
#define   JPEG_MISR0_RD3__VALUE_BMSK                                                                    0xFFFFFFFF
#define   JPEG_MISR0_RD3__VALUE_SHFT                                                                                 0
#define   JPEG_MISR0_RD3_BMSK                                                                           0xFFFFFFFF
#define   JPEG_MISR0_RD3_SHFT                                                                                        0

#define JPEG_MISR1_RD0_ADDR                                                                                (0x000002C8)
#define   JPEG_MISR1_RD0___RWC                                                                            QCSR_REG_RO
#define   JPEG_MISR1_RD0___POR                                                                         0x00000000
#define   JPEG_MISR1_RD0__VALUE_BMSK                                                                    0xFFFFFFFF
#define   JPEG_MISR1_RD0__VALUE_SHFT                                                                                 0
#define   JPEG_MISR1_RD0_BMSK                                                                           0xFFFFFFFF
#define   JPEG_MISR1_RD0_SHFT                                                                                        0

#define JPEG_MISR1_RD1_ADDR                                                                                (0x000002CC)
#define   JPEG_MISR1_RD1___RWC                                                                            QCSR_REG_RO
#define   JPEG_MISR1_RD1___POR                                                                         0x00000000
#define   JPEG_MISR1_RD1__VALUE_BMSK                                                                    0xFFFFFFFF
#define   JPEG_MISR1_RD1__VALUE_SHFT                                                                                 0
#define   JPEG_MISR1_RD1_BMSK                                                                           0xFFFFFFFF
#define   JPEG_MISR1_RD1_SHFT                                                                                        0

#define JPEG_MISR1_RD2_ADDR                                                                                (0x000002D0)
#define   JPEG_MISR1_RD2___RWC                                                                            QCSR_REG_RO
#define   JPEG_MISR1_RD2___POR                                                                         0x00000000
#define   JPEG_MISR1_RD2__VALUE_BMSK                                                                    0xFFFFFFFF
#define   JPEG_MISR1_RD2__VALUE_SHFT                                                                                 0
#define   JPEG_MISR1_RD2_BMSK                                                                           0xFFFFFFFF
#define   JPEG_MISR1_RD2_SHFT                                                                                        0

#define JPEG_MISR1_RD3_ADDR                                                                                (0x000002D4)
#define   JPEG_MISR1_RD3___RWC                                                                            QCSR_REG_RO
#define   JPEG_MISR1_RD3___POR                                                                         0x00000000
#define   JPEG_MISR1_RD3__VALUE_BMSK                                                                    0xFFFFFFFF
#define   JPEG_MISR1_RD3__VALUE_SHFT                                                                                 0
#define   JPEG_MISR1_RD3_BMSK                                                                           0xFFFFFFFF
#define   JPEG_MISR1_RD3_SHFT                                                                                        0

#define JPEG_MISR2_RD0_ADDR                                                                                (0x000002D8)
#define   JPEG_MISR2_RD0___RWC                                                                            QCSR_REG_RO
#define   JPEG_MISR2_RD0___POR                                                                         0x00000000
#define   JPEG_MISR2_RD0__VALUE_BMSK                                                                    0xFFFFFFFF
#define   JPEG_MISR2_RD0__VALUE_SHFT                                                                                 0
#define   JPEG_MISR2_RD0_BMSK                                                                           0xFFFFFFFF
#define   JPEG_MISR2_RD0_SHFT                                                                                        0

#define JPEG_MISR2_RD1_ADDR                                                                                (0x000002DC)
#define   JPEG_MISR2_RD1___RWC                                                                            QCSR_REG_RO
#define   JPEG_MISR2_RD1___POR                                                                         0x00000000
#define   JPEG_MISR2_RD1__VALUE_BMSK                                                                    0xFFFFFFFF
#define   JPEG_MISR2_RD1__VALUE_SHFT                                                                                 0
#define   JPEG_MISR2_RD1_BMSK                                                                           0xFFFFFFFF
#define   JPEG_MISR2_RD1_SHFT                                                                                        0

#define JPEG_MISR2_RD2_ADDR                                                                                (0x000002E0)
#define   JPEG_MISR2_RD2___RWC                                                                            QCSR_REG_RO
#define   JPEG_MISR2_RD2___POR                                                                         0x00000000
#define   JPEG_MISR2_RD2__VALUE_BMSK                                                                    0xFFFFFFFF
#define   JPEG_MISR2_RD2__VALUE_SHFT                                                                                 0
#define   JPEG_MISR2_RD2_BMSK                                                                           0xFFFFFFFF
#define   JPEG_MISR2_RD2_SHFT                                                                                        0

#define   JPEG_MISR2_RD3_ADDR                                                                                (0x000002E4)
#define   JPEG_MISR2_RD3___RWC                                                                            QCSR_REG_RO
#define   JPEG_MISR2_RD3___POR                                                                         0x00000000
#define   JPEG_MISR2_RD3__VALUE_BMSK                                                                    0xFFFFFFFF
#define   JPEG_MISR2_RD3__VALUE_SHFT                                                                                 0
#define   JPEG_MISR2_RD3_BMSK                                                                           0xFFFFFFFF
#define   JPEG_MISR2_RD3_SHFT                                                                                        0

#define JPEG_FE_VBPAD_CFG_ADDR                                                                             (0x000002E8)
#define   JPEG_FE_VBPAD_CFG___RWC                                                                         QCSR_REG_RW
#define   JPEG_FE_VBPAD_CFG___POR                                                                      0x00000000
#define   JPEG_FE_VBPAD_CFG__BLOCK_ROW_BMSK                                                             0x00001FFF
#define   JPEG_FE_VBPAD_CFG__BLOCK_ROW_SHFT                                                                          0
#define   JPEG_FE_VBPAD_CFG_BMSK                                                                        0x00001FFF
#define   JPEG_FE_VBPAD_CFG_SHFT                                                                                     0

#define JPEG_PLN0_RD_HINIT_INT_ADDR                                                                        (0x000002EC)
#define   JPEG_PLN0_RD_HINIT_INT___RWC                                                                    QCSR_REG_RW
#define   JPEG_PLN0_RD_HINIT_INT___POR                                                                 0x00000000
#define   JPEG_PLN0_RD_HINIT_INT__INTEGER_BMSK                                                          0x0001FFFF
#define   JPEG_PLN0_RD_HINIT_INT__INTEGER_SHFT                                                                       0
#define   JPEG_PLN0_RD_HINIT_INT_BMSK                                                                   0x0001FFFF
#define   JPEG_PLN0_RD_HINIT_INT_SHFT                                                                                0

#define JPEG_PLN1_RD_HINIT_INT_ADDR                                                                        (0x000002F0)
#define   JPEG_PLN1_RD_HINIT_INT___RWC                                                                    QCSR_REG_RW
#define   JPEG_PLN1_RD_HINIT_INT___POR                                                                 0x00000000
#define   JPEG_PLN1_RD_HINIT_INT__INTEGER_BMSK                                                          0x0001FFFF
#define   JPEG_PLN1_RD_HINIT_INT__INTEGER_SHFT                                                                       0
#define   JPEG_PLN1_RD_HINIT_INT_BMSK                                                                   0x0001FFFF
#define   JPEG_PLN1_RD_HINIT_INT_SHFT                                                                                0

#define JPEG_PLN2_RD_HINIT_INT_ADDR                                                                        (0x000002F4)
#define   JPEG_PLN2_RD_HINIT_INT___RWC                                                                    QCSR_REG_RW
#define   JPEG_PLN2_RD_HINIT_INT___POR                                                                 0x00000000
#define   JPEG_PLN2_RD_HINIT_INT__INTEGER_BMSK                                                          0x0001FFFF
#define   JPEG_PLN2_RD_HINIT_INT__INTEGER_SHFT                                                                       0
#define   JPEG_PLN2_RD_HINIT_INT_BMSK                                                                   0x0001FFFF
#define   JPEG_PLN2_RD_HINIT_INT_SHFT                                                                                0

#define JPEG_PLN0_RD_VINIT_INT_ADDR                                                                        (0x000002F8)
#define   JPEG_PLN0_RD_VINIT_INT___RWC                                                                    QCSR_REG_RW
#define   JPEG_PLN0_RD_VINIT_INT___POR                                                                 0x00000000
#define   JPEG_PLN0_RD_VINIT_INT__INTEGER_BMSK                                                          0x0001FFFF
#define   JPEG_PLN0_RD_VINIT_INT__INTEGER_SHFT                                                                       0
#define   JPEG_PLN0_RD_VINIT_INT_BMSK                                                                   0x0001FFFF
#define   JPEG_PLN0_RD_VINIT_INT_SHFT                                                                                0

#define JPEG_PLN1_RD_VINIT_INT_ADDR                                                                        (0x000002FC)
#define   JPEG_PLN1_RD_VINIT_INT___RWC                                                                    QCSR_REG_RW
#define   JPEG_PLN1_RD_VINIT_INT___POR                                                                 0x00000000
#define   JPEG_PLN1_RD_VINIT_INT__INTEGER_BMSK                                                          0x0001FFFF
#define   JPEG_PLN1_RD_VINIT_INT__INTEGER_SHFT                                                                       0
#define   JPEG_PLN1_RD_VINIT_INT_BMSK                                                                   0x0001FFFF
#define   JPEG_PLN1_RD_VINIT_INT_SHFT                                                                                0

#define JPEG_PLN2_RD_VINIT_INT_ADDR                                                                        (0x00000300)
#define   JPEG_PLN2_RD_VINIT_INT___RWC                                                                    QCSR_REG_RW
#define   JPEG_PLN2_RD_VINIT_INT___POR                                                                 0x00000000
#define   JPEG_PLN2_RD_VINIT_INT__INTEGER_BMSK                                                          0x0001FFFF
#define   JPEG_PLN2_RD_VINIT_INT__INTEGER_SHFT                                                                       0
#define   JPEG_PLN2_RD_VINIT_INT_BMSK                                                                   0x0001FFFF
#define   JPEG_PLN2_RD_VINIT_INT_SHFT                                                                                0

#define JPEG_MMU_CLIENT_PREDICTION_CTL_ADDR                                                                (0x00000304)
#define   JPEG_MMU_CLIENT_PREDICTION_CTL___RWC                                                            QCSR_REG_RW
#define   JPEG_MMU_CLIENT_PREDICTION_CTL___POR                                                         0x00000000
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__WR_SSID_PLN2_CLIENT_PREDICT_BMSK                              0x00000020
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__WR_SSID_PLN2_CLIENT_PREDICT_SHFT                                           5
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__WR_SSID_PLN2_CLIENT_PREDICT__HINT_IS_FORWARD                            0x0
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__WR_SSID_PLN2_CLIENT_PREDICT__HINT_IS_BACKWARD                           0x1
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__WR_SSID_PLN1_CLIENT_PREDICT_BMSK                              0x00000010
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__WR_SSID_PLN1_CLIENT_PREDICT_SHFT                                           4
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__WR_SSID_PLN1_CLIENT_PREDICT__HINT_IS_FORWARD                            0x0
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__WR_SSID_PLN1_CLIENT_PREDICT__HINT_IS_BACKWARD                           0x1
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__WR_SSID_PLN0_CLIENT_PREDICT_BMSK                              0x00000008
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__WR_SSID_PLN0_CLIENT_PREDICT_SHFT                                           3
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__WR_SSID_PLN0_CLIENT_PREDICT__HINT_IS_FORWARD                            0x0
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__WR_SSID_PLN0_CLIENT_PREDICT__HINT_IS_BACKWARD                           0x1
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__RD_SSID_PLN2_CLIENT_PREDICT_BMSK                              0x00000004
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__RD_SSID_PLN2_CLIENT_PREDICT_SHFT                                           2
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__RD_SSID_PLN2_CLIENT_PREDICT__HINT_IS_FORWARD                            0x0
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__RD_SSID_PLN2_CLIENT_PREDICT__HINT_IS_BACKWARD                           0x1
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__RD_SSID_PLN1_CLIENT_PREDICT_BMSK                              0x00000002
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__RD_SSID_PLN1_CLIENT_PREDICT_SHFT                                           1
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__RD_SSID_PLN1_CLIENT_PREDICT__HINT_IS_FORWARD                            0x0
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__RD_SSID_PLN1_CLIENT_PREDICT__HINT_IS_BACKWARD                           0x1
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__RD_SSID_PLN0_CLIENT_PREDICT_BMSK                              0x00000001
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__RD_SSID_PLN0_CLIENT_PREDICT_SHFT                                           0
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__RD_SSID_PLN0_CLIENT_PREDICT__HINT_IS_FORWARD                            0x0
#define   JPEG_MMU_CLIENT_PREDICTION_CTL__RD_SSID_PLN0_CLIENT_PREDICT__HINT_IS_BACKWARD                           0x1
#define   JPEG_MMU_CLIENT_PREDICTION_CTL_BMSK                                                           0x0000003F
#define   JPEG_MMU_CLIENT_PREDICTION_CTL_SHFT                                                                        0

#define JPEG_SPARE_ADDR                                                                                    (0x00000308)
#define   JPEG_SPARE___RWC                                                                                QCSR_REG_RW
#define   JPEG_SPARE___POR                                                                             0x00000000
#define   JPEG_SPARE__VALUE_BMSK                                                                        0xFFFFFFFF
#define   JPEG_SPARE__VALUE_SHFT                                                                                     0
#define   JPEG_SPARE_BMSK                                                                               0xFFFFFFFF
#define   JPEG_SPARE_SHFT                                                                                            0

#define   JPEG_OFFLINE_CMD_START                                                                        0x00000001
#define   JPEG_DMI_ADDR_START                                                                           0x00000000
#define   JPEG_DMI_CFG_QUANTIZATION                                                                     0x00000011
#define   JPEG_DMI_CFG_DISABLE                                                                          0x00000000
#define   JPEG_DMI_DATA_MAX                                                                             0x0000ffff
#define   JPEG_SCALE_DEFAULT_HSTEP_VSTEP                                                                0x200000
#define   JPEG_FE_QOS_CFG_ADDR_VALUE                                                                    0x00005508
#define   JPEG_WE_QOS_CFG_ADDR_VALUE                                                                    0x00005555

#define   JPEGDMA_HW_CAPABILITY_ADDR                                                                          (0x00000004)
#define   JPEGDMA_HW_CAPABILITY__NUM_PROCESSING_PIPES_BMSK                                                     0x00000006
#define   JPEGDMA_HW_CAPABILITY__NUM_PROCESSING_PIPES_SHFT                                                              1
#define   JPEGDMA_HW_CAPABILITY__SCALE_BMSK                                                                    0x00000001
#define   JPEGDMA_HW_CAPABILITY__SCALE_SHFT                                                                             0
#define   JPEGDMA_HW_CAPABILITY_BMSK                                                                           0x00000007
#define   JPEGDMA_HW_CAPABILITY_SHFT                                                                                    0

#define   JPEGDMA_IRQ_MASK_ADDR                                                                               (0x0000000C)
#define   JPEGDMA_IRQ_MASK___RWC                                                                             QCSR_REG_RW
#define   JPEGDMA_IRQ_MASK___POR                                                                          0x00000200
#define   JPEGDMA_IRQ_MASK__MASK_BMSK                                                                      0xFFFFFFFF
#define   JPEGDMA_IRQ_MASK__MASK_SHFT                                                                                   0
#define   JPEGDMA_IRQ_MASK_BMSK                                                                            0x00001FFF
#define   JPEGDMA_IRQ_MASK_SHFT                                                                                         0
#define   JPEGDMA_IRQ_ALLSOURCES_ENABLE                                                                    0x00001FFF

#define   JPEGDMA_IRQ_STATUS_ADDR                                                                              (0x00000010)
#define   JPEGDMA_IRQ_STATUS___RWC                                                                           QCSR_REG_RO
#define   JPEGDMA_IRQ_STATUS___POR                                                                        0x00000000
#define   JPEGDMA_IRQ_STATUS__STATUS_BMSK                                                                  0xFFFFFFFF
#define   JPEGDMA_IRQ_STATUS__STATUS_SHFT                                                                               0
#define   JPEGDMA_IRQ_STATUS_BMSK                                                                          0xFFFFFFFF
#define   JPEGDMA_IRQ_STATUS_SHFT                                                                                       0

#define   JPEGDMA_IRQ_CLEAR_ADDR                                                                               (0x00000014)
#define   JPEGDMA_IRQ_CLEAR___RWC                                                                            QCSR_REG_WO
#define   JPEGDMA_IRQ_CLEAR___POR                                                                         0x00000000
#define   JPEGDMA_IRQ_CLEAR__CLEAR_BMSK                                                                    0xFFFFFFFF
#define   JPEGDMA_IRQ_CLEAR__CLEAR_SHFT                                                                                 0
#define   JPEGDMA_IRQ_CLEAR_BMSK                                                                           0xFFFFFFFF
#define   JPEGDMA_IRQ_CLEAR_SHFT                                                                                        0

#define   JPEGDMA_CORE_CFG_ADDR                                                                                (0x00000018)
#define   JPEGDMA_CORE_CFG___RWC                                                                        QCSR_REG_WO
#define   JPEGDMA_CORE_CFG___POR                                                                        0x00000000

#define   JPEGDMA_CORE_CFG__TEST_BUS_ENABLE_BMSK                                                        0x00080000
#define   JPEGDMA_CORE_CFG__TEST_BUS_ENABLE_SHFT                                                                     19
#define   JPEGDMA_CORE_CFG__TEST_BUS_ENABLE__TEST_BUS_DISABLED                                                 0x0
#define   JPEGDMA_CORE_CFG__TEST_BUS_ENABLE__TEST_BUS_ENABLED                                                  0x1

#define   JPEGDMA_CORE_CFG__BUS_MISR_BMSK                                                        0x00000080
#define   JPEGDMA_CORE_CFG__BUS_MISR_SHFT                                                                     7
#define   JPEGDMA_CORE_CFG__BUS_MISR__BUS_MISR_DISABLED                                                 0x0
#define   JPEGDMA_CORE_CFG__BUS_MISR__BUS_MISR_ENABLED                                                  0x1

#define   JPEGDMA_CORE_CFG__BRIDGE_ENABLE_BMSK                                                             0x00000040
#define   JPEGDMA_CORE_CFG__BRIDGE_ENABLE_SHFT                                                                          6
#define   JPEGDMA_CORE_CFG__BRIDGE_ENABLE__BRIDGE_INTERFACE_DISABLED                                                 0x0
#define   JPEGDMA_CORE_CFG__BRIDGE_ENABLE__BRIDGE_INTERFACE_ENABLED                                                  0x1

#define   JPEGDMA_CORE_CFG__SCALE_1_ENABLE_BMSK                                                   0x00000020
#define   JPEGDMA_CORE_CFG__SCALE_1_ENABLE_SHFT                                                                5
#define   JPEGDMA_CORE_CFG__SCALE_1_ENABLE__SCALE_DISABLED                                          0x0
#define   JPEGDMA_CORE_CFG__SCALE_1_ENABLE__SCALE_ENABLED                                           0x1

#define   JPEGDMA_CORE_CFG__SCALE_0_ENABLE_BMSK                                                   0x00000010
#define   JPEGDMA_CORE_CFG__SCALE_0_ENABLE_SHFT                                                                4
#define   JPEGDMA_CORE_CFG__SCALE_0_ENABLE__SCALE_DISABLED                                          0x0
#define   JPEGDMA_CORE_CFG__SCALE_0_ENABLE__SCALE_ENABLED                                           0x1

#define   JPEGDMA_CORE_CFG__WE_1_ENABLE_BMSK                                                                 0x00000008
#define   JPEGDMA_CORE_CFG__WE_1_ENABLE_SHFT                                                                              3
#define   JPEGDMA_CORE_CFG__WE_1_ENABLE__WRITE_ENGINE_DISABLED                                                         0x0
#define   JPEGDMA_CORE_CFG__WE_1_ENABLE__WRITE_ENGINE_ENABLED                                                          0x1

#define   JPEGDMA_CORE_CFG__WE_0_ENABLE_BMSK                                                                 0x00000004
#define   JPEGDMA_CORE_CFG__WE_0_ENABLE_SHFT                                                                              2
#define   JPEGDMA_CORE_CFG__WE_0_ENABLE__WRITE_ENGINE_DISABLED                                                         0x0
#define   JPEGDMA_CORE_CFG__WE_0_ENABLE__WRITE_ENGINE_ENABLED                                                          0x1

#define   JPEGDMA_CORE_CFG__FE_1_ENABLE_BMSK                                                                 0x00000002
#define   JPEGDMA_CORE_CFG__FE_1_ENABLE_SHFT                                                                              1
#define   JPEGDMA_CORE_CFG__FE_1_ENABLE__FETCH_ENGINE_DISABLED                                                         0x0
#define   JPEGDMA_CORE_CFG__FE_1_ENABLE__FETCH_ENGINE_ENABLED                                                          0x1
#define   JPEGDMA_CORE_CFG_BMSK                                                                            0x07FFFFFF
#define   JPEGDMA_CORE_CFG_SHFT                                                                                         0

#define   JPEGDMA_CORE_CFG__FE_0_ENABLE_BMSK                                                                 0x00000001
#define   JPEGDMA_CORE_CFG__FE_0_ENABLE_SHFT                                                                              0
#define   JPEGDMA_CORE_CFG__FE_0_ENABLE__FETCH_ENGINE_DISABLED                                                         0x0
#define   JPEGDMA_CORE_CFG__FE_0_ENABLE__FETCH_ENGINE_ENABLED                                                          0x1
#define   JPEGDMA_CORE_CFG_BMSK                                                                            0x07FFFFFF
#define   JPEGDMA_CORE_CFG_SHFT                                                                                         0

#define   JPEGDMA_CMD_ADDR                                                                                     (0x0000001C)
#define   JPEGDMA_CMD___RWC                                                                                  QCSR_REG_WO
#define   JPEGDMA_CMD___POR                                                                               0x00000000

#define   JPEGDMA_CMD__CLEAR_WE_1_QUEUE_BMSK                                                            0x00000200
#define   JPEGDMA_CMD__CLEAR_WE_1_QUEUE_SHFT                                                                         9
#define   JPEGDMA_CMD__CLEAR_WE_0_QUEUE_BMSK                                                            0x00000100
#define   JPEGDMA_CMD__CLEAR_WE_0_QUEUE_SHFT                                                                         8

#define   JPEGDMA_CMD__CLEAR_FE_1_QUEUE_BMSK                                                            0x00000020
#define   JPEGDMA_CMD__CLEAR_FE_1_QUEUE_SHFT                                                                         5
#define   JPEGDMA_CMD__CLEAR_FE_0_QUEUE_BMSK                                                            0x00000010
#define   JPEGDMA_CMD__CLEAR_FE_0_QUEUE_SHFT                                                                         4

#define   JPEGDMA_CMD__HW_STOP_BMSK                                                                        0x00000004
#define   JPEGDMA_CMD__HW_STOP_SHFT                                                                                     2
#define   JPEGDMA_CMD__HW_START_BMSK                                                                       0x00000001
#define   JPEGDMA_CMD__HW_START_SHFT                                                                                    0
#define   JPEGDMA_CMD_BMSK                                                                                 0x000003FF
#define   JPEGDMA_CMD_SHFT                                                                                              0

#define   JPEGDMA_FE_0_CFG_ADDR                                                                                  (0x0000002C)
#define   JPEGDMA_FE_1_CFG_ADDR                                                                                  (0x00000070)

#define   JPEGDMA_FE_CFG_ADDR                                                                                  (0x0000002C)
#define   JPEGDMA_FE_CFG___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_FE_CFG___POR                                                                            0x00000000

#define   JPEGDMA_FE_CFG__MAL_BOUNDARY_BMSK                                                                0x0E000000
#define   JPEGDMA_FE_CFG__MAL_BOUNDARY_SHFT                                                                            25
#define   JPEGDMA_FE_CFG__MAL_BOUNDARY__MAL_32_BYTES                                                                 0x0
#define   JPEGDMA_FE_CFG__MAL_BOUNDARY__MAL_64_BYTES                                                                 0x1
#define   JPEGDMA_FE_CFG__MAL_BOUNDARY__MAL_128_BYTES                                                                0x2
#define   JPEGDMA_FE_CFG__MAL_BOUNDARY__MAL_256_BYTES                                                                0x3
#define   JPEGDMA_FE_CFG__MAL_BOUNDARY__MAL_512_BYTES                                                                0x4
#define   JPEGDMA_FE_CFG__MAL_BOUNDARY__MAL_1024_BYTES                                                               0x5
#define   JPEGDMA_FE_CFG__MAL_BOUNDARY__MAL_2048_BYTES                                                               0x6
#define   JPEGDMA_FE_CFG__MAL_EN_BMSK                                                                      0x00200000
#define   JPEGDMA_FE_CFG__MAL_EN_SHFT                                                                                  21

#define   JPEGDMA_FE_CFG__PLN_BLOCK_TYPE_CBCR                                                                 0x3
#define   JPEGDMA_FE_CFG__PLN_BLOCK_TYPE_CR                                                                   0x2
#define   JPEGDMA_FE_CFG__PLN_BLOCK_TYPE_CB                                                                   0x1
#define   JPEGDMA_FE_CFG__PLN_BLOCK_TYPE_Y                                                                    0x0
#define   JPEGDMA_FE_CFG__PLN_BLOCK_TYPE_BMSK                                                                   0x00180000
#define   JPEGDMA_FE_CFG__PLN_BLOCK_TYPE_SHFT                                                                           19
#define   JPEGDMA_FE_CFG__CBCR_ORDER_BMSK                                                                  0x00001000
#define   JPEGDMA_FE_CFG__CBCR_ORDER_SHFT                                                                               12
#define   JPEGDMA_FE_CFG__BOTTOM_VPAD_EN_BMSK                                                              0x00000100
#define   JPEGDMA_FE_CFG__BOTTOM_VPAD_EN_SHFT                                                                           8
#define   JPEGDMA_FE_CFG__BLOCK_WIDTH_BMSK                                                                 0x00000030
#define   JPEGDMA_FE_CFG__BLOCK_WIDTH_SHFT                                                                              4
#define   JPEGDMA_FE_CFG__BURST_LENGTH_MAX_BMSK                                                            0x0000000F
#define   JPEGDMA_FE_CFG__BURST_LENGTH_MAX_SHFT                                                                         0
#define   JPEGDMA_FE_CFG_BMSK                                                                              0xFFFFFFFF
#define   JPEGDMA_FE_CFG_SHFT                                                                                           0

#define   JPEGDMA_FE_RD_0_PNTR_ADDR                                                                                  (0x00000034)
#define   JPEGDMA_FE_RD_1_PNTR_ADDR                                                                                  (0x00000078)
#define   JPEGDMA_FE_RD_PNTR_ADDR                                                                                  (0x00000034)
#define   JPEGDMA_FE_RD_PNTR___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_FE_RD_PNTR___POR                                                                            0x00000000
#define   JPEGDMA_FE_RD_PNTR_BMSK                                                                             0xFFFFFFFF
#define   JPEGDMA_FE_RD_PNTR_SHFT                                                                                        0

#define   JPEGDMA_FE_RD_0_PNTR_CNSMD_ADDR                                                                                  (0x0000003C)
#define   JPEGDMA_FE_RD_1_PNTR_CNSMD_ADDR                                                                                  (0x00000080)
#define   JPEGDMA_FE_RD_PNTR_CNSMD_ADDR                                                                                  (0x0000003C)
#define   JPEGDMA_FE_RD_PNTR_CNSMD___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_FE_RD_PNTR_CNSMD___POR                                                                            0x00000000
#define   JPEGDMA_FE_RD_PNTR_CNSMD_BMSK                                                                             0xFFFFFFFF
#define   JPEGDMA_FE_RD_PNTR_CNSMD_SHFT                                                                                        0

#define   JPEGDMA_FE_RD_BUFFER_SIZE_0_ADDR                                                                       (0x00000044)
#define   JPEGDMA_FE_RD_BUFFER_SIZE_1_ADDR                                                                       (0x00000088)
#define   JPEGDMA_FE_RD_BUFFER_SIZE_ADDR                                                                                  (0x00000040)
#define   JPEGDMA_FE_RD_BUFFER_SIZE___RWC                                                                               QCSR_REG_RO
#define   JPEGDMA_FE_RD_BUFFER_SIZE___POR                                                                            0x00000000
#define   JPEGDMA_FE_RD_BUFFER_SIZE___HEIGHT_BMSK                                                                    0xFFFF0000
#define   JPEGDMA_FE_RD_BUFFER_SIZE___HEIGHT_SHFT                                                                    16
#define   JPEGDMA_FE_RD_BUFFER_SIZE___WIDTH_BMSK                                                                     0x0000FFFF
#define   JPEGDMA_FE_RD_BUFFER_SIZE___WIDTH_SHFT                                                                     0
#define   JPEGDMA_FE_RD_BUFFER_SIZE_BMSK                                                                             0xFFFFFFFF
#define   JPEGDMA_FE_RD_BUFFER_SIZE_SHFT                                                                             0

#define   JPEGDMA_FE_RD_0_STRIDE_ADDR                                                                                  (0x00000048)
#define   JPEGDMA_FE_RD_1_STRIDE_ADDR                                                                                  (0x0000008C)
#define   JPEGDMA_FE_RD_STRIDE_ADDR                                                                                  (0x00000048)
#define   JPEGDMA_FE_RD_STRIDE___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_FE_RD_STRIDE___POR                                                                            0x00000000
#define   JPEGDMA_FE_RD_STRIDE_BMSK                                                                             0x0000FFFF
#define   JPEGDMA_FE_RD_STRIDE_SHFT                                                                                        0



#define   JPEGDMA_FE_RD_0_HINIT_ADDR                                                                                  (0x0000004C)
#define   JPEGDMA_FE_RD_1_HINIT_ADDR                                                                                  (0x00000090)
#define   JPEGDMA_FE_RD_HINIT_ADDR                                                                                  (0x0000004C)
#define   JPEGDMA_FE_RD_HINIT___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_FE_RD_HINIT___POR                                                                            0x00000000
#define   JPEGDMA_FE_RD_HINIT_BMSK                                                                             0x001FFFFF
#define   JPEGDMA_FE_RD_HINIT_SHFT                                                                                        0

#define   JPEGDMA_FE_RD_0_HINIT_INT_ADDR                                                                                  (0x00000050)
#define   JPEGDMA_FE_RD_1_HINIT_INT_ADDR                                                                                  (0x00000094)
#define   JPEGDMA_FE_RD_HINIT_INT__ADDR                                                                                  (0x00000050)
#define   JPEGDMA_FE_RD_HINIT_INT____RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_FE_RD_HINIT_INT____POR                                                                            0x00000000
#define   JPEGDMA_FE_RD_HINIT_INT_BMSK                                                                             0x001FFFFF
#define   JPEGDMA_FE_RD_HINIT_INT_SHFT                                                                                        0

#define   JPEGDMA_FE_RD_0_VINIT_ADDR                                                                                  (0x00000054)
#define   JPEGDMA_FE_RD_1_VINIT_ADDR                                                                                  (0x00000098)
#define   JPEGDMA_FE_RD_VINIT_ADDR                                                                                  (0x00000054)
#define   JPEGDMA_FE_RD_VINIT___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_FE_RD_VINIT___POR                                                                            0x00000000
#define   JPEGDMA_FE_RD_VINIT_BMSK                                                                             0x001FFFFF
#define   JPEGDMA_FE_RD_VINIT_SHFT                                                                                        0

#define   JPEGDMA_FE_RD_0_VINIT_INT_ADDR                                                                                  (0x00000058)
#define   JPEGDMA_FE_RD_1_VINIT_INT_ADDR                                                                                  (0x0000009C)
#define   JPEGDMA_FE_RD_VINIT_INT__ADDR                                                                                  (0x00000058)
#define   JPEGDMA_FE_RD_VINIT_INT____RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_FE_RD_VINIT_INT____POR                                                                            0x00000000
#define   JPEGDMA_FE_RD_VINIT_INT_BMSK                                                                             0x001FFFFF
#define   JPEGDMA_FE_RD_VINIT_INT_SHFT                                                                                        0

#define   JPEGDMA_FE_RD_0_VBPAD_ADDR                                                                                  (0x0000005C)
#define   JPEGDMA_FE_RD_1_VBPAD_ADDR                                                                                  (0x000000A0)
#define   JPEGDMA_FE_RD_VBPAD__ADDR                                                                                  (0x00000058)
#define   JPEGDMA_FE_RD_VBPAD____RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_FE_RD_VBPAD____POR                                                                            0x00000000
#define   JPEGDMA_FE_RD_VBPAD_BMSK                                                                             0x00001FFF
#define   JPEGDMA_FE_RD_VBPAD_SHFT                                                                                        0


#define   JPEGDMA_FE_QOS_CFG_ADDR                                                                                  (0x00000060)
#define   JPEGDMA_FE_QOS_CFG___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_FE_QOS_CFG___POR                                                                            0x00000000
#define   JPEGDMA_FE_QOS_CFG___QOS_PRIORITY_11_BMSK                                                          0x0000C000
#define   JPEGDMA_FE_QOS_CFG___QOS_PRIORITY_11_SHFT                                                                     14
#define   JPEGDMA_FE_QOS_CFG___QOS_PRIORITY_10_BMSK                                                          0x0000C000
#define   JPEGDMA_FE_QOS_CFG___QOS_PRIORITY_10_SHFT                                                                     12
#define   JPEGDMA_FE_QOS_CFG___QOS_PRIORITY_01_BMSK                                                          0x00000C00
#define   JPEGDMA_FE_QOS_CFG___QOS_PRIORITY_01_SHFT                                                                     10
#define   JPEGDMA_FE_QOS_CFG___QOS_PRIORITY_00_BMSK                                                          0x00000300
#define   JPEGDMA_FE_QOS_CFG___QOS_PRIORITY_00_SHFT                                                                     8
#define   JPEGDMA_FE_QOS_CFG___QOS_WINDOW_SIZE_BMSK                                                          0x0000000F
#define   JPEGDMA_FE_QOS_CFG___QOS_WINDOW_SIZE_SHFT                                                                     0
#define   JPEGDMA_FE_QOS_CFG_BMSK                                                                             0x0000FFFF
#define   JPEGDMA_FE_QOS_CFG_SHFT                                                                                        0

#define   JPEGDMA_FE_QOS_LAT_HIGH__ADDR                                                                             (0x00000064)
#define   JPEGDMA_FE_QOS_LAT_HIGH____RWC                                                                            QCSR_REG_RW
#define   JPEGDMA_FE_QOS_LAT_HIGH____POR                                                                            0x00000000
#define   JPEGDMA_FE_QOS_LAT_HIGH_BMSK                                                                             0x0000FFFF
#define   JPEGDMA_FE_QOS_LAT_HIGH_SHFT                                                                                        0

#define   JPEGDMA_FE_QOS_LAT_MID__ADDR                                                                             (0x00000068)
#define   JPEGDMA_FE_QOS_LAT_MID____RWC                                                                            QCSR_REG_RW
#define   JPEGDMA_FE_QOS_LAT_MID____POR                                                                            0x00000000
#define   JPEGDMA_FE_QOS_LAT_MID_BMSK                                                                             0x0000FFFF
#define   JPEGDMA_FE_QOS_LAT_MID_SHFT                                                                                        0

#define   JPEGDMA_FE_QOS_LAT_LOW__ADDR                                                                             (0x0000006C)
#define   JPEGDMA_FE_QOS_LAT_LOW____RWC                                                                            QCSR_REG_RW
#define   JPEGDMA_FE_QOS_LAT_LOW____POR                                                                            0x00000000
#define   JPEGDMA_FE_QOS_LAT_LOW_BMSK                                                                             0x0000FFFF
#define   JPEGDMA_FE_QOS_LAT_LOW_SHFT                                                                                        0

#define   JPEGDMA_WE_CFG_ADDR                                                                                  (0x000000B8)
#define   JPEGDMA_WE_CFG___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_WE_CFG___POR                                                                            0x00000000

#define   JPEGDMA_WE_CFG__MMU_PREDICTION_BMSK                                                                  0x00002000
#define   JPEGDMA_WE_CFG__MMU_PREDICTION_SHFT                                                                               13
#define   JPEGDMA_WE_CFG__CBCR_ORDER_BMSK                                                                  0x00001000
#define   JPEGDMA_WE_CFG__CBCR_ORDER_SHFT                                                                               12
#define   JPEGDMA_WE_CFG__MAL_BOUNDARY_BMSK                                                                0x00000700
#define   JPEGDMA_WE_CFG__MAL_BOUNDARY_SHFT                                                                            8
#define   JPEGDMA_WE_CFG__MAL_BOUNDARY__MAL_32_BYTES                                                                 0x0
#define   JPEGDMA_WE_CFG__MAL_BOUNDARY__MAL_64_BYTES                                                                 0x1
#define   JPEGDMA_WE_CFG__MAL_BOUNDARY__MAL_128_BYTES                                                                0x2
#define   JPEGDMA_WE_CFG__MAL_BOUNDARY__MAL_256_BYTES                                                                0x3
#define   JPEGDMA_WE_CFG__MAL_BOUNDARY__MAL_512_BYTES                                                                0x4
#define   JPEGDMA_WE_CFG__MAL_BOUNDARY__MAL_1024_BYTES                                                               0x5
#define   JPEGDMA_WE_CFG__MAL_BOUNDARY__MAL_2048_BYTES                                                               0x6



#define   JPEGDMA_WE_CFG__MAL_EN_BMSK                                                                      0x00000080
#define   JPEGDMA_WE_CFG__MAL_EN_SHFT                                                                                  7
#define   JPEGDMA_WE_CFG__BURST_LENGTH_MAX_BMSK                                                            0x0000000F
#define   JPEGDMA_WE_CFG__BURST_LENGTH_MAX_SHFT                                                                         0
#define   JPEGDMA_WE_CFG_BMSK                                                                              0xFFFFFFFF
#define   JPEGDMA_WE_CFG_SHFT                                                                                           0

#define   JPEGDMA_WE_PLN_0_WR_PNTR_ADDR                                                                                  (0x000000BC)
#define   JPEGDMA_WE_PLN_1_WR_PNTR_ADDR                                                                                  (0x000000EC)
#define   JPEGDMA_WE_PLN_WR_PNTR_ADDR                                                                                  (0x000000BC)
#define   JPEGDMA_WE_PLN_WR_PNTR___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_WE_PLN_WR_PNTR___POR                                                                            0x00000000
#define   JPEGDMA_WE_PLN_WR_PNTR_BMSK                                                                             0xFFFFFFFF
#define   JPEGDMA_WE_PLN_WR_PNTR_SHFT                                                                                        0

#define   JPEGDMA_WE_PLN_0_WR_PNTR_CNSMD_ADDR                                                                                  (0x000000C0)
#define   JPEGDMA_WE_PLN_1_WR_PNTR_CNSMD_ADDR                                                                                  (0x000000F0)
#define   JPEGDMA_WE_PLN_WR_PNTR_CNSMD_ADDR                                                                                  (0x000000C0)
#define   JPEGDMA_WE_PLN_WR_PNTR_CNSMD___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_WE_PLN_WR_PNTR_CNSMD___POR                                                                            0x00000000
#define   JPEGDMA_WE_PLN_WR_PNTR_CNSMD_BMSK                                                                             0xFFFFFFFF
#define   JPEGDMA_WE_PLN_WR_PNTR_CNSMD_SHFT                                                                                        0

#define   JPEGDMA_WE_PLN_WR_BUFFER_SIZE_0_ADDR                                                                       (0x000000C4)
#define   JPEGDMA_WE_PLN_WR_BUFFER_SIZE_1_ADDR                                                                       (0x000000F4)
#define   JPEGDMA_WE_PLN_WR_BUFFER_SIZE_ADDR                                                                                  (0x000000C4)
#define   JPEGDMA_WE_PLN_WR_BUFFER_SIZE___RWC                                                                               QCSR_REG_RO
#define   JPEGDMA_WE_PLN_WR_BUFFER_SIZE___POR                                                                            0x00000000
#define   JPEGDMA_WE_PLN_WR_BUFFER_SIZE___HEIGHT_BMSK                                                                    0xFFFF0000
#define   JPEGDMA_WE_PLN_WR_BUFFER_SIZE___HEIGHT_SHFT                                                                    16
#define   JPEGDMA_WE_PLN_WR_BUFFER_SIZE___WIDTH_BMSK                                                                     0x0000FFFF
#define   JPEGDMA_WE_PLN_WR_BUFFER_SIZE___WIDTH_SHFT                                                                     0
#define   JPEGDMA_WE_PLN_WR_BUFFER_SIZE_BMSK                                                                             0xFFFFFFFF
#define   JPEGDMA_WE_PLN_WR_BUFFER_SIZE_SHFT                                                                             0

#define   JPEGDMA_WE_PLN_0_WR_STRIDE_ADDR                                                                                  (0x000000C8)
#define   JPEGDMA_WE_PLN_1_WR_STRIDE_ADDR                                                                                  (0x000000F8)
#define   JPEGDMA_WE_PLN_WR_STRIDE_ADDR                                                                                  (0x000000C8)
#define   JPEGDMA_WE_PLN_WR_STRIDE___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_WE_PLN_WR_STRIDE___POR                                                                            0x00000000
#define   JPEGDMA_WE_PLN_WR_STRIDE_BMSK                                                                             0x0000FFFF
#define   JPEGDMA_WE_PLN_WR_STRIDE_SHFT                                                                                        0

#define   JPEGDMA_WE_PLN_0_WR_CFG_0_ADDR                                                                                  (0x000000CC)
#define   JPEGDMA_WE_PLN_1_WR_CFG_0_ADDR                                                                                  (0x000000FC)
#define   JPEGDMA_WE_PLN_WR_CFG_0_ADDR                                                                                  (0x000000CC)
#define   JPEGDMA_WE_PLN_WR_CFG_0___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_WE_PLN_WR_CFG_0___POR                                                                            0x00000000
#define   JPEGDMA_WE_PLN_WR_CFG_0___BLOCKS_PER_ROW_BMSK                                                            0xFFFF0000
#define   JPEGDMA_WE_PLN_WR_CFG_0___BLOCKS_PER_ROW_SHFT                                                            16
#define   JPEGDMA_WE_PLN_WR_CFG_0___BLOCKS_PER_COL_BMSK                                                            0x0000FFFF
#define   JPEGDMA_WE_PLN_WR_CFG_0___BLOCKS_PER_COL_SHFT                                                            0
#define   JPEGDMA_WE_PLN_WR_CFG_0_BMSK                                                                             0xFFFFFFFF
#define   JPEGDMA_WE_PLN_WR_CFG_0_SHFT                                                                                        0

#define   JPEGDMA_WE_PLN_0_WR_CFG_1_ADDR                                                                                  (0x000000D0)
#define   JPEGDMA_WE_PLN_1_WR_CFG_1_ADDR                                                                                  (0x00000100)
#define   JPEGDMA_WE_PLN_WR_CFG_1_ADDR                                                                                  (0x000000D0)
#define   JPEGDMA_WE_PLN_WR_CFG_1___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_WE_PLN_WR_CFG_1___POR                                                                            0x00000000
#define   JPEGDMA_WE_PLN_WR_CFG_1___LAST_H_STEP_BMSK                                                            0xFFFF0000
#define   JPEGDMA_WE_PLN_WR_CFG_1___LAST_H_STEP_SHFT                                                            16
#define   JPEGDMA_WE_PLN_WR_CFG_1___H_STEP_BMSK                                                            0x0000FFFF
#define   JPEGDMA_WE_PLN_WR_CFG_1___H_STEP_SHFT                                                            0
#define   JPEGDMA_WE_PLN_WR_CFG_1_BMSK                                                                             0xFFFFFFFF
#define   JPEGDMA_WE_PLN_WR_CFG_1_SHFT                                                                                        0

#define   JPEGDMA_WE_PLN_0_WR_CFG_2_ADDR                                                                                  (0x000000D4)
#define   JPEGDMA_WE_PLN_1_WR_CFG_2_ADDR                                                                                  (0x00000104)
#define   JPEGDMA_WE_PLN_WR_CFG_2_ADDR                                                                                  (0x000000D4)
#define   JPEGDMA_WE_PLN_WR_CFG_2___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_WE_PLN_WR_CFG_2___POR                                                                            0x00000000
#define   JPEGDMA_WE_PLN_WR_CFG_2___LAST_V_STEP_BMSK                                                            0xFFFF0000
#define   JPEGDMA_WE_PLN_WR_CFG_2___LAST_V_STEP_SHFT                                                            16
#define   JPEGDMA_WE_PLN_WR_CFG_2___V_STEP_BMSK                                                            0x0000FFFF
#define   JPEGDMA_WE_PLN_WR_CFG_2___V_STEP_SHFT                                                            0
#define   JPEGDMA_WE_PLN_WR_CFG_2_BMSK                                                                             0xFFFFFFFF
#define   JPEGDMA_WE_PLN_WR_CFG_2_SHFT                                                                                        0

#define   JPEGDMA_WE_PLN_0_WR_CFG_3_ADDR                                                                                  (0x000000D8)
#define   JPEGDMA_WE_PLN_1_WR_CFG_3_ADDR                                                                                  (0x00000108)
#define   JPEGDMA_WE_PLN_WR_CFG_3_ADDR                                                                                  (0x000000D8)
#define   JPEGDMA_WE_PLN_WR_CFG_3___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_WE_PLN_WR_CFG_3___POR                                                                            0x00000000
#define   JPEGDMA_WE_PLN_WR_CFG_3___H_INIT_BMSK                                                            0xFFFF0000
#define   JPEGDMA_WE_PLN_WR_CFG_3___H_INIT_SHFT                                                            16
#define   JPEGDMA_WE_PLN_WR_CFG_3___V_INIT_BMSK                                                            0x0000FFFF
#define   JPEGDMA_WE_PLN_WR_CFG_3___V_INIT_SHFT                                                            0
#define   JPEGDMA_WE_PLN_WR_CFG_3_BMSK                                                                             0xFFFFFFFF
#define   JPEGDMA_WE_PLN_WR_CFG_3_SHFT                                                                                        0


#define   JPEGDMA_WE_QOS_CFG_ADDR                                                                                  (0x00000144)
#define   JPEGDMA_WE_QOS_CFG___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_WE_QOS_CFG___POR                                                                            0x00000000
#define   JPEGDMA_WE_QOS_CFG_BMSK                                                                             0x0000FFFF
#define   JPEGDMA_WE_QOS_CFG_SHFT                                                                                        0

#define   JPEGDMA_WE_PLN_0_WR_PNTR_CNT_ADDR                                                                                  (0x00000148)
#define   JPEGDMA_WE_PLN_1_WR_PNTR_CNT_ADDR                                                                                  (0x00000178)
#define   JPEGDMA_WE_PLN_WR_PNTR_CNT_ADDR                                                                                  (0x00000148)
#define   JPEGDMA_WE_PLN_WR_PNTR_CNT___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_WE_PLN_WR_PNTR_CNT___POR                                                                            0x00000000
#define   JPEGDMA_WE_PLN_WR_PNTR_CNT_BMSK                                                                             0x00000003
#define   JPEGDMA_WE_PLN_WR_PNTR_CNT_SHFT                                                                                        0


#define   JPEGDMA_PP_0_SCALE_PHASEV_STEP_ADDR                                                                        (0x0000019C)
#define   JPEGDMA_PP_1_SCALE_PHASEV_STEP_ADDR                                                                        (0x000001BC)
#define   JPEGDMA_PP_SCALE_PHASEV_ADDR                                                                             (0x0000019C)
#define   JPEGDMA_PP_SCALE_PHASEV_STEP__FRACTIONAL_BMSK                                                            (0x03E00000)
#define   JPEGDMA_PP_SCALE_PHASEV_STEP__FRACTIONAL_SHFT                                                            (0x15)
#define   JPEGDMA_PP_SCALE_PHASEV_STEP__INTEGER_BMSK                                                            (0x001FFFFF)
#define   JPEGDMA_PP_SCALE_PHASEV_STEP__INTEGER_SHFT                                                            (0x0)


#define   JPEGDMA_PP_0_SCALE_PHASEH_STEP_ADDR                                                                        (0x00000194)
#define   JPEGDMA_PP_1_SCALE_PHASEH_STEP_ADDR                                                                        (0x000001B4)
#define   JPEGDMA_PP_SCALE_PHASEH_ADDR                                                                             (0x00000194)
#define   JPEGDMA_PP_SCALE_PHASEH_STEP__FRACTIONAL_BMSK                                                            (0x03E00000)
#define   JPEGDMA_PP_SCALE_PHASEH_STEP__FRACTIONAL_SHFT                                                            (0x15)
#define   JPEGDMA_PP_SCALE_PHASEH_STEP__INTEGER_BMSK                                                            (0x001FFFFF)
#define   JPEGDMA_PP_SCALE_PHASEH_STEP__INTEGER_SHFT                                                            (0x0)


#define   JPEGDMA_PP_SCALE_CFG___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_PP_SCALE_CFG___POR                                                                            0x00000000


#define   JPEGDMA_PP_0_SCALE_CFG_ADDR                                                                                  (0x00000188)
#define   JPEGDMA_PP_1_SCALE_CFG_ADDR                                                                                  (0x000001A8)
#define   JPEGDMA_PP_SCALE_CFG_ADDR                                                                                  (0x00000188)
#define   JPEGDMA_PP_SCALE_CFG___RWC                                                                               QCSR_REG_RW
#define   JPEGDMA_PP_SCALE_CFG___POR                                                                            0x00000000

#define   JPEGDMA_PP_SCALE_CFG___VSCALE_FIR_ALGORITHM__BI_NEAREST_NEIGHBOUR                                            0x2
#define   JPEGDMA_PP_SCALE_CFG___VSCALE_FIR_ALGORITHM__BI_CUBIC                                                        0x1
#define   JPEGDMA_PP_SCALE_CFG___VSCALE_FIR_ALGORITHM__BI_LINEAR                                                       0x0
#define   JPEGDMA_PP_SCALE_CFG___VSCALE_FIR_ALGORITHM_BMSK                                                             0x00030000
#define   JPEGDMA_PP_SCALE_CFG___VSCALE_FIR_ALGORITHM_SHFT                                                             0x00000010
#define   JPEGDMA_PP_SCALE_CFG___HSCALE_FIR_ALGORITHM_BMSK                                                             0x00003000
#define   JPEGDMA_PP_SCALE_CFG___HSCALE_FIR_ALGORITHM__BI_NEAREST_NEIGHBOUR                                            0x2
#define   JPEGDMA_PP_SCALE_CFG___HSCALE_FIR_ALGORITHM__BI_CUBIC                                                        0x1
#define   JPEGDMA_PP_SCALE_CFG___HSCALE_FIR_ALGORITHM__BI_LINEAR                                                       0x0
#define   JPEGDMA_PP_SCALE_CFG___HSCALE_FIR_ALGORITHM_SHFT                                                             0x0000000C
#define   JPEGDMA_PP_SCALE_CFG___VSCALE_ALGORITHM__FIR_UPSCALE                                                         0x1
#define   JPEGDMA_PP_SCALE_CFG___VSCALE_ALGORITHM__MN_DOWNSCALE                                                        0x0
#define   JPEGDMA_PP_SCALE_CFG___VSCALE_ALGORITHM_BMSK                                                             0x00000200
#define   JPEGDMA_PP_SCALE_CFG___VSCALE_ALGORITHM_SHFT                                                             0x00000009
#define   JPEGDMA_PP_SCALE_CFG___HSCALE_ALGORITHM__FIR_UPSCALE                                                         0x1
#define   JPEGDMA_PP_SCALE_CFG___HSCALE_ALGORITHM__MN_DOWNSCALE                                                        0x0
#define   JPEGDMA_PP_SCALE_CFG___HSCALE_ALGORITHM_BMSK                                                             0x00000100
#define   JPEGDMA_PP_SCALE_CFG___HSCALE_ALGORITHM_SHFT                                                             0x00000008
#define   JPEGDMA_PP_SCALE_CFG___SUBSAMPLE_ENABLE__ENABLE                                                          0x1
#define   JPEGDMA_PP_SCALE_CFG___SUBSAMPLE_ENABLE__DISABLE                                                         0x0
#define   JPEGDMA_PP_SCALE_CFG___SUBSAMPLE_ENABLE_BMSK                                                             0x00000080
#define   JPEGDMA_PP_SCALE_CFG___SUBSAMPLE_ENABLE_SHFT                                                             0x00000007
#define   JPEGDMA_PP_SCALE_CFG___UPSAMPLE_ENABLE__ENABLE                                                          0x1
#define   JPEGDMA_PP_SCALE_CFG___UPSAMPLE_ENABLE__DISABLE                                                         0x0
#define   JPEGDMA_PP_SCALE_CFG___UPSAMPLE_ENABLE_BMSK                                                             0x00000040
#define   JPEGDMA_PP_SCALE_CFG___UPSAMPLE_ENABLE_SHFT                                                             0x00000006
#define   JPEGDMA_PP_SCALE_CFG___VSCALE_ENABLE__ENABLE                                                          0x1
#define   JPEGDMA_PP_SCALE_CFG___VSCALE_ENABLE__DISABLE                                                         0x0
#define   JPEGDMA_PP_SCALE_CFG___VSCALE_ENABLE_BMSK                                                             0x00000020
#define   JPEGDMA_PP_SCALE_CFG___VSCALE_ENABLE_SHFT                                                             0x00000005
#define   JPEGDMA_PP_SCALE_CFG___HSCALE_ENABLE__ENABLE                                                          0x1
#define   JPEGDMA_PP_SCALE_CFG___HSCALE_ENABLE__DISABLE                                                         0x0
#define   JPEGDMA_PP_SCALE_CFG___HSCALE_ENABLE_BMSK                                                             0x00000010
#define   JPEGDMA_PP_SCALE_CFG___HSCALE_ENABLE_SHFT                                                             0x00000004
#define   JPEGDMA_PP_SCALE_CFG_BMSK                                                                             0xFFFFFFFF
#define   JPEGDMA_PP_SCALE_CFG_SHFT                                                                                        0

#define   JPEGDMA_RESET_CMD_ADDR                                                                               (0x00000008)
#define   JPEGDMA_RESET_CMD_RMSK                                                                            (0xA0032083)
#define   JPEGDMA_RESET_CMD___RWC                                                                            QCSR_REG_WO
#define   JPEGDMA_RESET_CMD___POR                                                                         0x00000000
#define   JPEGDMA_RESET_CMD__RESET_BYPASS_BMSK                                                             0x80000000
#define   JPEGDMA_RESET_CMD__RESET_BYPASS_SHFT                                                                         31
#define   JPEGDMA_RESET_CMD__JPEG_DOMAIN_RESET_BMSK                                                        0x20000000
#define   JPEGDMA_RESET_CMD__JPEG_DOMAIN_RESET_SHFT                                                                    29
#define   JPEGDMA_RESET_CMD__CORE_RESET_BMSK                                                               0x00020000
#define   JPEGDMA_RESET_CMD__CORE_RESET_SHFT                                                                           17
#define   JPEGDMA_RESET_CMD__MISR_RESET_BMSK                                                               0x00010000
#define   JPEGDMA_RESET_CMD__MISR_RESET_SHFT                                                                           16
#define   JPEGDMA_RESET_CMD__REGISTER_RESET_BMSK                                                           0x00002000
#define   JPEGDMA_RESET_CMD__REGISTER_RESET_SHFT                                                                       13
#define   JPEGDMA_RESET_CMD__SCALE_RESET_BMSK                                                              0x00000080
#define   JPEGDMA_RESET_CMD__SCALE_RESET_SHFT                                                                           7

#define   JPEGDMA_RESET_CMD__WE_RESET_BMSK                                                                 0x00000002
#define   JPEGDMA_RESET_CMD__WE_RESET_SHFT                                                                              1
#define   JPEGDMA_RESET_CMD__FE_RESET_BMSK                                                                 0x00000001
#define   JPEGDMA_RESET_CMD__FE_RESET_SHFT                                                                              0
#define   JPEGDMA_RESET_CMD_BMSK                                                                           0xFFFFFFFF
#define   JPEGDMA_RESET_CMD_SHFT                                                                                        0

#define   JPEGDMA_START_TRANSFER                                                                           0x00000001

#endif /* JPEGD_HW_REG_H */
