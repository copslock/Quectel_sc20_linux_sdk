/*
 * Copyright (c) 2015, 2017 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
*/

/*============================================================================
 *                      INCLUDE FILES
 *===========================================================================*/
#include "chromatix.h"

static chromatix_parms_type chromatix_imx377_parms = {
#include "chromatix_imx377_video.h"
};

/*============================================================================
 * FUNCTION    - load_chromatix -
 *
 * DESCRIPTION:
 *==========================================================================*/
void *load_chromatix(void)
{
  return &chromatix_imx377_parms;
}
