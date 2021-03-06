#ifndef CSR_APP_MAIN_TRANSPORT_H__
#define CSR_APP_MAIN_TRANSPORT_H__

#include "csr_synergy.h"
/*****************************************************************************

Copyright (c) 2010-2016 Qualcomm Technologies International, Ltd.
All Rights Reserved. 
Qualcomm Technologies International, Ltd. Confidential and Proprietary.

*****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

CsrResult CsrAppMainTransportInitialise(void);
void CsrAppMainTransportDeinitialise(void);
void CsrAppMainTransportUsage(void);

#ifdef __cplusplus
}
#endif

#endif
