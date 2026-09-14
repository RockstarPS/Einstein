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
#ifndef CSM_CFG_H
#define CSM_CFG_H

/*****************************************************************************
 *  INCLUDES
******************************************************************************/
#include "Csm_Types.h"

/*****************************************************************************
 *  GLOBAL CONSTANT MACROS
******************************************************************************/
#define CSM_CALLBACK_START_NOTIFICATION            STD_OFF 
																    
#define TOTAL_NO_CSMJOB                            3U
//#define TOTAL_NO_CSMPRIMITIVE								     10U
#define TOTAL_NO_CSMQUEUE                          TOTAL_NO_CSMJOB
#define TOTAL_NO_KEY												       TOTAL_NO_CSMJOB


#define CsmJobID_EcbEncrypt                        0x00UL
#define CsmJobID_RNG            			       	     0x01UL
#define CsmJobID_SignatureVerify            	     0x02UL

#define CsmKeyID_EcbEncrypt                        0x00UL
#define CsmKeyID_RNG            			       	     0x01UL
#define CsmKeyID_SignatureVerify 			       	     0x02UL

/*Enable the Function API */
#define CSM_DEV_ERROR_REPORT 									   STD_ON
#define CSM_DECRYPT_API                          STD_OFF
#define CSM_HASH_API                             STD_OFF
#define CSM_MACVERIFY_API                        STD_OFF
#define CSM_SIGNATUREVERIFY_API                  STD_ON
#define CSM_RANDOMGENERATE_API                   STD_ON
#define CSM_CANCELJOB_API			                   STD_OFF
#define CSM_MACGENERATE_API                      STD_OFF
#define CSM_KEY_API                              STD_ON
#define CSM_ENCRYPT_API                          STD_ON

/*Macro for det function */
#define CSM_DET_REPORTERROR(API_ID, ERRORID)

/*****************************************************************************
*  Type Declarations                                              			 *
******************************************************************************/
/*  typedef used in Csm_JobTable */
typedef struct sCsm_JobTableType
{
  uint8 CsmKeyIdIdxOfJobTable;           /*index of Csm_Key */
  uint8 JobInfoIdxOfJobTable;            /* index Csm_JobInfo */
  uint8 JobPrimitiveInfoIdxOfJobTable;   /* index Csm_JobPrimitiveInfo */
  uint8 PriorityOfJobTable;              /* Contains CsmJobPriority. */
  uint8 QueueRefIdxOfJobTable;           /* index of  Csm_QueueInfo */
} Csm_JobTableType;

/**   typedef used in Csm_QueueState */
typedef struct sCsm_QueueStateType
{
  uint8 PauseProcessingOfQueueState;
  uint8 QueueIdxOfQueueState;            /* index in Csm_Queue */
  uint8 ReservedIndexesOfQueueState;
  uint8 SortNeededOfQueueState;
} Csm_QueueStateType;

/**   typedef used in Csm_QueueInfo */
typedef struct sCsm_QueueInfoType
{
  uint32 ChannelIdOfQueueInfo;           /* CsmChannelRef */
  uint8 QueueEndIdxOfQueueInfo;          /* the end index in Csm_Queue */
  uint8 QueueLengthOfQueueInfo;          /* the total number of Job in  Csm_Queue */
  uint8 QueueStartIdxOfQueueInfo;        /* the start index in Csm_Queue */
} Csm_QueueInfoType;

/*   type used in Csm_Key */
typedef struct sCsm_KeyType
{
  uint32 CryIfKeyIdOfKey;                /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmKeys/CsmKey/CsmKeyRef. */
} Csm_KeyType;

/*typedef for Notification function*/
typedef void (* Csm_NotificationFuncType)(Crypto_JobType *job, Std_ReturnType result);

/*****************************************************************************
 *  GLOBAL DATA PROTOTYPES
******************************************************************************/

#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Csm_MemMap.h"
extern Crypto_JobType Csm_Queue[TOTAL_NO_CSMJOB];

extern Csm_QueueStateType Csm_QueueState[TOTAL_NO_CSMJOB];
#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Csm_MemMap.h" 

#define CSM_START_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h"
extern const Csm_QueueInfoType Csm_QueueInfo[TOTAL_NO_CSMQUEUE];

extern const Crypto_PrimitiveInfoType Csm_PrimitiveInfo[TOTAL_NO_CSMJOB];

extern const Crypto_JobInfoType Csm_JobInfo[TOTAL_NO_CSMJOB];

extern const Crypto_JobPrimitiveInfoType Csm_JobPrimitiveInfo[TOTAL_NO_CSMJOB];

extern const Csm_JobTableType Csm_JobTable[TOTAL_NO_CSMJOB];

extern Crypto_JobType Csm_Job[TOTAL_NO_CSMJOB];

extern const Csm_KeyType Csm_Key[TOTAL_NO_KEY];

extern const Csm_NotificationFuncType Csm_CallbackFunc[TOTAL_NO_CSMJOB];

#define CSM_STOP_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h"

#endif /* CSM_CFG_H */

/*****************************************************************************
 *  END OF FILE: Csm_Cfg.h
******************************************************************************/

