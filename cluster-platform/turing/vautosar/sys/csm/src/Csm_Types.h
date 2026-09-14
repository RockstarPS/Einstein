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
* @brief  This file contains declations of the Autosar Crypto Service Manager
* ****************************************************************************/
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/

#ifndef CSM_TYPES_H
#define CSM_TYPES_H

/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "Std_Types.h"
#include "Rte_Type.h"
/*****************************************************************************
* GLOBAL CONSTANT MACROS                                                     *
******************************************************************************/

#define ZEROLENGTH   0U
/* Crypto Stack Error Codes [SWS_Csm_01069] [SWS_Crypto_00042] */
#define CRYPTO_E_BUSY                                0x2U
#define CRYPTO_E_SMALL_BUFFER                        0x3U
#define CRYPTO_E_ENTROPY_EXHAUSTION                  0x4U
#define CRYPTO_E_QUEUE_FULL                          0x5U
#define CRYPTO_E_KEY_READ_FAIL                       0x6U
#define CRYPTO_E_KEY_WRITE_FAIL                      0x7U
#define CRYPTO_E_KEY_NOT_AVAILABLE                   0x8U
#define CRYPTO_E_KEY_NOT_VALID                       0x9U
#define CRYPTO_E_KEY_SIZE_MISMATCH                   0xAU
#define CRYPTO_E_COUNTER_OVERFLOW                    0xBU
#define CRYPTO_E_JOB_CANCELED                        0xCU
# define CRYPTO_E_KEY_EMPTY                           0xDU
/** \brief SHE ram key slot **/
#define CRY_SHE_RAM_KEY                              0x0EUL
#define SINGLE_CALLMODE_SET                        (uint8)1       //!<  Macro contains the single call mode status
#define SINGLE_CALLMODE_NOT_SET                    (uint8)0       //!<  Macro contains the single call mode status
/*****************************************************************************
*  Type Declarations                                              			 *
******************************************************************************/
/* [SWS_Csm_01028] Crypto_JobStateType */
typedef enum eCrypto_JobStateType
{
    CRYPTO_JOBSTATE_IDLE = 0x0,
    CRYPTO_JOBSTATE_ACTIVE = 0x01
}Crypto_JobStateType;

/* [SWS_Csm_01028] Crypto_ServiceInfoType  */
typedef enum eCrypto_ServiceInfoType
{
  CRYPTO_HASH =0,
  CRYPTO_MACGENERATE =1,
  CRYPTO_MACVERIFY =2,
  CRYPTO_ENCRYPT =3,
  CRYPTO_DECRYPT =4,
  CRYPTO_27Service_ENCRYPT =5,
  CRYPTO_27Service_DECRYPT =6,
  CRYPTO_SIGNATUREGENERATE =7,
  CRYPTO_SIGNATUREVERIFY =8,
  CRYPTO_SECCOUNTERINCREMENT =9,
  CRYPTO_SECCOUNTERREAD =10,
  CRYPTO_RANDOMGENERATE =11,
  CRYPTO_AEADENCRYPT =12,
  CRYPTO_AEADDECRYPT =13,
}Crypto_ServiceInfoType;

/* [SWS_Csm_01047] Crypto_AlgorithmFamilyType */
typedef enum
{
    CRYPTO_ALGOFAM_NOT_SET  = 0x00,
    CRYPTO_ALGOFAM_SHA1 = 0x01,
    CRYPTO_ALGOFAM_SHA2_224 = 0x02,
    CRYPTO_ALGOFAM_SHA2_256 = 0x03,
    CRYPTO_ALGOFAM_SHA2_384 = 0x04,
    CRYPTO_ALGOFAM_SHA2_512 = 0x05,
    CRYPTO_ALGOFAM_SHA2_512_224 = 0x06,
    CRYPTO_ALGOFAM_SHA2_512_256 = 0x07,
    CRYPTO_ALGOFAM_SHA3_224 = 0x08,
    CRYPTO_ALGOFAM_SHA3_256 = 0x09,
    CRYPTO_ALGOFAM_SHA3_384 = 0x0A,
    CRYPTO_ALGOFAM_SHA3_512 = 0x0B,
    CRYPTO_ALGOFAM_SHAKE128 = 0x0C,
    CRYPTO_ALGOFAM_SHAKE256 = 0x0D,
    CRYPTO_ALGOFAM_RIPEMD160  = 0x0E,
    CRYPTO_ALGOFAM_BLAKE_1_256  = 0x0F,
    CRYPTO_ALGOFAM_BLAKE_1_512  = 0x10,
    CRYPTO_ALGOFAM_BLAKE_2s_256 = 0x11,
    CRYPTO_ALGOFAM_BLAKE_2s_512 = 0x12,
    CRYPTO_ALGOFAM_3DES = 0x13,
    CRYPTO_ALGOFAM_AES = 0x14,
    CRYPTO_ALGOFAM_CHACHA = 0x15,
    CRYPTO_ALGOFAM_RSA = 0x16,
    CRYPTO_ALGOFAM_ED25519 = 0x17,
    CRYPTO_ALGOFAM_BRAINPOOL = 0x18,
    CRYPTO_ALGOFAM_ECCNIST = 0x19,
    CRYPTO_ALGOFAM_SECURECOUNTER = 0x1A,
    CRYPTO_ALGOFAM_RNG = 0x1B,
    CRYPTO_ALGOFAM_SIPHASH = 0x1C,
    CRYPTO_ALGOFAM_ECIES = 0x1D,
    CRYPTO_ALGOFAM_CUSTOM = 0xFF,
} Crypto_AlgorithmFamilyType;

/* [SWS_Csm_01048] Crypto_AlgorithmModeType */
typedef enum 
{
    CRYPTO_ALGOMODE_NOT_SET          =0x00,
    CRYPTO_ALGOMODE_ECB              =0x01,
    CRYPTO_ALGOMODE_CBC              =0x02,
    CRYPTO_ALGOMODE_CFB              =0x03,
    CRYPTO_ALGOMODE_OFB              =0x04,
    CRYPTO_ALGOMODE_CTR              =0x05,
    CRYPTO_ALGOMODE_XTS              =0x06,
    CRYPTO_ALGOMODE_GCM              =0x07,
    CRYPTO_ALGOMODE_RSAES_OAEP       =0x08,
    CRYPTO_ALGOMODE_RSAES_PKCS1_v1_5 =0x09,
    CRYPTO_ALGOMODE_RSASSA_PSS       =0x0A,
    CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5=0x0B,
    CRYPTO_ALGOMODE_8ROUNDS          =0x0C,
    CRYPTO_ALGOMODE_12ROUNDS         =0x0D,
    CRYPTO_ALGOMODE_20ROUNDS         =0x0E,
    CRYPTO_ALGOMODE_HMAC             =0x0F,
    CRYPTO_ALGOMODE_CMAC             =0x10,
    CRYPTO_ALGOMODE_GMAC             =0x11,
    CRYPTO_ALGOMODE_CTRDRBG          =0x12,
    CRYPTO_ALGOMODE_SIPHASH_2_4      =0x13,
    CRYPTO_ALGOMODE_SIPHASH_4_8      =0x14,
    CRYPTO_ALGOMODE_CUSTOM           =0xFF,
}Crypto_AlgorithmModeType;

/* [SWS_Csm_01008] Crypto_AlgorithmInfoType */
typedef struct
{
  Crypto_AlgorithmFamilyType family;
  uint32 keyLength;
  Crypto_AlgorithmModeType mode;
  Crypto_AlgorithmFamilyType secondaryFamily;
} Crypto_AlgorithmInfoType;

#ifndef Rte_TypeDef_Crypto_OperationModeType
typedef enum 
{
    CRYPTO_OPERATIONMODE_START = 0x1,
    CRYPTO_OPERATIONMODE_UPDATE = 0x2,
    CRYPTO_OPERATIONMODE_STREAMSTART = 0x3,
    CRYPTO_OPERATIONMODE_FINISH = 0x4,
    CRYPTO_OPERATIONMODE_SINGLECALL =0x7,
}Crypto_OperationModeType;
#else
#define  CRYPTO_OPERATIONMODE_START        0x1
#define  CRYPTO_OPERATIONMODE_UPDATE       0x2
#define  CRYPTO_OPERATIONMODE_STREAMSTART  0x3
#define  CRYPTO_OPERATIONMODE_FINISH       0x4
#define  CRYPTO_OPERATIONMODE_SINGLECALL   0x7
#endif

/* [SWS_Csm_01049] Crypto_ProcessingType */
typedef enum
{
    CRYPTO_PROCESSING_ASYNC = 0x0,
    CRYPTO_PROCESSING_SYNC = 0x1,
} Crypto_ProcessingType;

#ifndef Rte_TypeDef_Crypto_VerifyResultType 
typedef enum
{
    CRYPTO_E_VER_OK     = 0x0,
    CRYPTO_E_VER_NOT_OK = 0x1   
} Crypto_ResultType;

typedef Crypto_ResultType Crypto_VerifyResultType;
#else
# define CRYPTO_E_VER_OK 0x0
# define CRYPTO_E_VER_NOT_OK  0x1     
#endif
/* [SWS_Csm_00930] Each crypto primitive configuration shall be realized as a constant structure of type Crypto_PrimitiveInfoType. */
/* [SWS_Csm_01011] */
typedef struct
{
  const uint32 resultLength;
  const Crypto_ServiceInfoType service;
  const Crypto_AlgorithmInfoType algorithm;
} Crypto_PrimitiveInfoType;

/* [SWS_Csm_00932] Each user primitive configuration shall be realized as a constant structure of type Crypto_JobPrimitiveInfoType. */
/* [SWS_Csm_01012] */
typedef struct
{
  const uint32 callbackId;
  const Crypto_PrimitiveInfoType * primitiveInfo;
  const uint32 secureCounterId;
  const uint32 cryIfKeyId;
  const Crypto_ProcessingType processingType;
  const boolean callbackUpdateNotification;
} Crypto_JobPrimitiveInfoType;


/* [SWS_Csm_01009] Crypto_JobPrimitiveInputOutputType */
typedef struct
{
  const uint8* inputPtr;
  uint32 inputLength;
  const uint8* secondaryInputPtr;
  uint32 secondaryInputLength;
  const uint8* tertiaryInputPtr;
  uint32 tertiaryInputLength;

  uint8* outputPtr;
  uint32* outputLengthPtr;
  uint8* secondaryOutputPtr;
  uint32* secondaryOutputLengthPtr;

  Crypto_VerifyResultType* verifyPtr;
  uint64* output64Ptr;
  Crypto_OperationModeType mode;
} Crypto_JobPrimitiveInputOutputType;

typedef struct
{
  const uint32 jobId;
  const uint32 jobPriority;
} Crypto_JobInfoType; 

/* [SWS_Csm_01013] Crypto_JobType  */
typedef struct
{
  uint32 jobId;
  Crypto_JobStateType state;
  Crypto_JobPrimitiveInputOutputType jobPrimitiveInputOutput;
  const Crypto_JobPrimitiveInfoType* jobPrimitiveInfo;
  const Crypto_JobInfoType * jobInfo;
  uint32 cryptoKeyId;
} Crypto_JobType;

typedef struct
{
  void (* callbackFunction)( const Std_ReturnType result);
} Csm_CallbackStackType;


typedef enum
{
    CRYPTO_KEY_STATUS_INVALID = 0,
    CRYPTO_KEY_STATUS_VALID,
    CRYPTO_KEY_STATUS_UNKNOWN
} Crypto_KeyStatusEnumType;

typedef struct
{
    Crypto_KeyStatusEnumType status;    
    uint32 keyId;                                        
} Crypto_KeyStatusType;


#endif /* CSM_TYPES_H */
/*******************************************************************************
 *  END OF FILE: CSM_TYPES.H
*******************************************************************************/

