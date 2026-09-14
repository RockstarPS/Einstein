/*
 * udsmgr_security.h
 *
 *  Created on: May 15, 2020
 *      Author: MMK
 */

#ifndef UDSMGR_DOIP_SECURITY_H
#define UDSMGR_DOIP_SECURITY_H

#include "system.h"

/* Security Seed-Key Length */
#define FBL_SEC_SEED_LEN						(256u) /*Seed Length for CMFB*/
#define FBL_SEC_KEY_LEN							(32u) /*Key value for CMFB*/

#define FBL_SECURITY_SUCCESS					(0u)
#define FBL_SECURITY_PENDING					(1u)
#define FBL_SECURITY_REQ_SEED_FAILED			(2u)
#define FBL_SECURITY_KEY_FAILED					(3u)
#define FBL_SECURITY_NOT_DONE					(0xFFu)
#define FBLSEC_CONSTA                           ((UINT32) 0x0343FD)
#define FBLSEC_CONSTB                           ((UINT32) 0x269EC3)
#define FBLSEC_CONST1                           16u

#define DOIP_DWLRSAUDSP_PUNSIZE 8
#define cDATNvmFingerprintRealSize 16
UINT8 DoIPSec_RequestSeed(UINT8 *pSeedBuffer, UINT32 len);
UINT8 DoIPSec_VerifyKey(const UINT8 *pKeyBuffer, UINT32 len, UINT8 *pFingerPrint);
UINT16 FblSec_GetSeedInitialValue(void);
void FblSec_SetSeedValue(UINT16 value);
UINT8 FblSec_VerifySecurityAccess(void);
UINT8 FblSec_Init(void);
UINT8 FblSec_ClearSecurityAccess(void);

#endif /* UDSMGR_DOIP_SECURITY_H */
