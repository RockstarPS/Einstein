/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2018. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
* @ingroup Crypto Service Manager
* @file Csm.c
* @brief Main header file for Csm
* ****************************************************************************/


/*****************************************************************************
 *  INCLUDES
******************************************************************************/
#include "Csm_Cfg.h"
#include "Csm_Types.h"
#include "CryIf_Cfg.h"

/*****************************************************************************
 *  GLOBAL DATA
******************************************************************************/
#define CSM_START_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h"
const Crypto_JobInfoType Csm_JobInfo[TOTAL_NO_CSMJOB] = {
    /* Job reference                                   jobId                                       jobPriority */
    /* CsmJobID_ECDSA_P384_SignGenerate_SHA2_256   */ {CsmJobID_EcbEncrypt,          1UL } ,
    /* CsmJobID_ECDSA_P384_SignGenerate_SHA2_512   */ {CsmJobID_RNG,                 1UL }
};

const Crypto_JobPrimitiveInfoType Csm_JobPrimitiveInfo[TOTAL_NO_CSMJOB] = {
    /* Job reference                                  callbackId  primitiveInfo           secureCounterId   cryIfKeyId                                          processingType            callbackUpdateNotification*/
    /* CsmJobID_ECDSA_P384_SignGenerate_SHA2_256   */ {      0UL, &Csm_PrimitiveInfo[0],             0xFF,  CryIfChannelKeyID_EcbEncrypt, CRYPTO_PROCESSING_SYNC,                        FALSE },
    /* CsmJobID_ECDSA_P384_SignGenerate_SHA2_512   */ {      1UL, &Csm_PrimitiveInfo[1],             0xFF,  CryIfChannelKeyID_RNG,        CRYPTO_PROCESSING_SYNC,                        FALSE }
};


const Crypto_PrimitiveInfoType Csm_PrimitiveInfo[TOTAL_NO_CSMJOB] = {
    /* Job reference                                     resultLength   PrimitiveInfo                AlgorithmFamilyType      keyLength    ModeType                            secondaryAlgorithmFamilyType*/
    /* CsmJobID_ECDSA_P384_SignGenerate_SHA2_256   */ {          32UL,  CRYPTO_ENCRYPT,              {CRYPTO_ALGOFAM_AES,       16UL,   CRYPTO_ALGOMODE_ECB,                CRYPTO_ALGOFAM_NOT_SET}},
    /* CsmJobID_ECDSA_P384_SignGenerate_SHA2_512   */ {          16UL,  CRYPTO_RANDOMGENERATE,       {CRYPTO_ALGOFAM_RNG,       16UL,   CRYPTO_ALGOMODE_NOT_SET,            CRYPTO_ALGOFAM_NOT_SET}},
};

const Csm_JobTableType Csm_JobTable[TOTAL_NO_CSMJOB] = {
    /* Job reference                                  CsmKeyIdIdx                                JobInfoIdx  JobPrimitiveInfoIdx   Priority(same asCsm_JobInfo.jobPriority)   QueueRefIdx  */
    { /* CsmJobID_ECDSA_P384_SignGenerate_SHA2_256 */ CsmKeyID_EcbEncrypt,                           0U,                  0U,                                       1U,            0UL, },
    { /* CsmJobID_ECDSA_P384_SignGenerate_SHA2_512 */ CsmKeyID_RNG,                                  1U,                  1U,                                       1U,            0UL, },
};

const Csm_QueueInfoType Csm_QueueInfo[TOTAL_NO_CSMQUEUE] = {
    /* Job reference                                   ChannelId                                          QueueEndIdx  QueueLength  QueueStartIdx  */
    { /* CsmJobID_ECDSA_P384_SignGenerate_SHA2_256 */  CryIfChannelJobID_EcbEncrypt,                           1U,          1U,            0U },
    { /* CsmJobID_ECDSA_P384_SignGenerate_SHA2_512 */  CryIfChannelJobID_RNG,                                  2U,          1U,            1U }
};

const Csm_KeyType Csm_Key[TOTAL_NO_KEY] = {
    /* Job reference                                  CryIfKeyId   */
    { /* CsmJobID_ECDSA_P384_SignGenerate_SHA2_256 */ CryIfChannelKeyID_EcbEncrypt },
    { /* CsmJobID_ECDSA_P384_SignGenerate_SHA2_512 */ CryIfChannelKeyID_RNG }
};

const Csm_NotificationFuncType Csm_CallbackFunc[TOTAL_NO_CSMJOB] = {
    /* Job reference                                  callback function name  */
    /* CsmJobID_ECDSA_P384_SignGenerate_SHA2_256   */ 0UL,
    /* CsmJobID_ECDSA_P384_SignGenerate_SHA2_512   */ 0UL
};

#define CSM_START_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h"

#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Csm_MemMap.h"
Crypto_JobType Csm_Queue[TOTAL_NO_CSMJOB];

Csm_QueueStateType Csm_QueueState[TOTAL_NO_CSMJOB];

Crypto_JobType Csm_Job[TOTAL_NO_CSMJOB];

#define VWCSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Csm_MemMap.h"

/*****************************************************************************
 *  END OF FILE: Csm_Cfg.c
******************************************************************************/
