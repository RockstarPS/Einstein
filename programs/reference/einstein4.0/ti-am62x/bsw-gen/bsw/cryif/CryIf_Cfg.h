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
* @ingroup Crypto Service Interface
* @file CryIf.h
* @brief CRYIF main layer which handles the Init, Mainfunctions and APIs for SWCs
* ****************************************************************************/
#ifndef CRYIF_CFG_H
#define CRYIF_CFG_H

/*****************************************************************************
 *  INCLUDES
******************************************************************************/
#include "Csm_Types.h"


/*****************************************************************************
 *  GLOBAL CONSTANT MACROS
******************************************************************************/
/*Total no of Job configured */
#define TotalnoCryIfChannel 				                         3U
/* CryIf Job ID */
#define CryIfChannelJobID_EcbEncrypt                        0x00UL
#define CryIfChannelJobID_RNG            			       	      0x01UL
#define CryIfChannelJobID_SIGNATUREVERIFY			       	      0x02UL

/*Total no of key configured */
#define TotalnoCryIfKey 					                           3U
/* CryIf Key ID */

#define CryIfChannelKeyID_EcbEncrypt                        0x00UL
#define CryIfChannelKeyID_RNG            			       	      0x01UL
#define CryIfChannelKeyID_SIGNATUREVERIFY			       	      0x02UL

/*Total no of key configured */
#define TotalnoDriver 					                             1U

/* DEV  Error Enable/Disable */
#define CRYIF_DEV_ERROR_REPORT                 STD_ON
#define CRYIF_DET_REPORTERROR(CRYIF_SID_INIT, errorId)
/*****************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
******************************************************************************/
/* typedef used in CryIf_Key */
typedef struct sCryIf_KeyType
{
  uint32 RefOfKey;
} CryIf_KeyType;

/* typedef used in CryIf_CryptodriverTypee */
typedef struct sCryIf_CryptodriverType
{
	uint8 CryptoFunctionsIdx;  /* pointing to CryIf_CryptoFunctions */
}CryIf_CryptodriverType;

typedef Std_ReturnType (* CryIf_ProcessJobFuncType)(uint32 objectId, Crypto_JobType* job);
typedef Std_ReturnType (* CryIf_CancelJobFuncType)(uint32 objectId, Crypto_JobType* job);
typedef Std_ReturnType (* CryIf_KeyElementGetFuncType)(uint32 cryptoKeyId, uint32 keyElementId, uint8* resultPtr, uint32* resultLengthPtr);
typedef Std_ReturnType (* CryIf_KeyElementSetFuncType)(uint32 cryptoKeyId, uint32 keyElementId, const uint8* keyPtr, uint32 keyLength);
typedef Std_ReturnType (* CryIf_KeyValidSetFuncType)(uint32 cryptoKeyId);
typedef Std_ReturnType (* CryIf_KeyGenerateFuncType)(uint32 cryptoKeyId);
typedef Std_ReturnType (* CryIf_CertificateParseFuncType)(uint32 cryptoKeyId);
typedef Std_ReturnType (* CryIf_KeyDeriveFuncType)(uint32 cryptoKeyId,uint32 targetCryptoKeyId);
typedef Std_ReturnType (* CryIf_KeyElementCopyFuncType)(uint32 cryptoKeyId,uint32 keyElementId,uint32 targetCryptoKeyId,uint32 targetKeyElementId);
typedef Std_ReturnType (* CryIf_KeyCopyFuncType)(uint32 cryptoKeyId,uint32 targetCryptoKeyId);
typedef Std_ReturnType (* CryIf_KeyExchangeCalcSecretFuncType)(uint32 cryptoKeyId,const uint8 * partnerPublicValuePtr,uint32 partnerPublicValueLength);
typedef Std_ReturnType (* CryIf_KeyExchangeCalcPubValFuncType)(uint32 cryptoKeyId,uint8 * publicValuePtr,uint32* publicValueLengthPtr);
typedef Std_ReturnType (* CryIf_CertificateVerifyFuncType)(uint32 cryptoKeyId,uint32 certificateId,uint8 * verptr);


/** typedef used in CryIf_CryptoFunctions */
typedef struct sCryIf_CryptoFunctionsType
{
  CryIf_CancelJobFuncType CancelJobOfCryptoFunctions;
  CryIf_ProcessJobFuncType ProcessJobOfCryptoFunctions;
  CryIf_KeyElementGetFuncType KeyElementGetOfCryptoFunctions;
  CryIf_KeyElementSetFuncType KeyElementSetOfCryptoFunctions;
  CryIf_KeyValidSetFuncType KeyValidSetOfCryptoFunctions;
  CryIf_KeyGenerateFuncType KeyGenerateOfCryptoFunctions;
  CryIf_CertificateParseFuncType CertificateParseOfCryptoFunctions;
  CryIf_CertificateVerifyFuncType CertificateVerifyOfCryptoFunctions;
  CryIf_KeyDeriveFuncType KeyDeriveOfCryptoFunctions;
  CryIf_KeyElementCopyFuncType KeyElementOfCryptoFunctions;
  CryIf_KeyCopyFuncType KeyCopyOfCryptoFunctions;
  CryIf_KeyExchangeCalcSecretFuncType KeyExchangeCalcSecretOfCryptoFunctions;
  CryIf_KeyExchangeCalcPubValFuncType KeyExchangeCalcPubValOfCryptoFunctions;
} CryIf_CryptoFunctionsType;

/*****************************************************************************
 *  GLOBAL DATA PROTOTYPES
******************************************************************************/
#define CRYIF_START_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h"
extern const CryIf_CryptoFunctionsType CryIf_CryptoFunctions[TotalnoDriver];
extern const CryIf_KeyType CryIf_Key[TotalnoCryIfKey];
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
#include "Csm_MemMap.h"

#endif /* CRYIF_CFG_H */

/*****************************************************************************
 *  END OF FILE: CryIf_Cfg.h
******************************************************************************/

