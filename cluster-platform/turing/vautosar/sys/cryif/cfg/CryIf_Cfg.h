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
#define TotalnoCryIfChannel 				                    8U
/* CryIf Job ID */
#define CryIfChannelJobID_RSA_Hash             				    0x0UL 
#define CryIfChannelJobID_RSA_SignatureGen        				0x1UL 
#define CryIfChannelJobID_RSA_SignatureVerify        			0x2UL 
#define CryIfChannelJobID_AES128_CMACGEN            			0x3UL 
#define CryIfChannelJobID_AES128_CMACVerify            		0x4UL 
#define CryIfChannelJobID_AES128_RNG            				  0x5UL 
#define CryIfChannelJobID_AES128_CBC_DEC            			0x6UL 
#define CryIfChannelJobID_AES128_CBC_ENC            			0x7UL

/*Total no of key configured */
#define TotalnoCryIfKey 					                    13U
/* CryIf Key ID */
#if 0
#define CryIfChannelKeyID_RSA_Hash             				    0x0UL 
#define CryIfChannelKeyID_RSA_SignatureGen        				0x1UL 
#define CryIfChannelKeyID_RSA_SignatureVerify        			0x2UL 
#define CryIfChannelKeyID_AES128_CMACGEN            			0x3UL 
#define CryIfChannelKeyID_AES128_CMACVerify            		0x4UL 
#define CryIfChannelKeyID_AES128_RNG            				  0x5UL 
#define CryIfChannelKeyID_AES128_CBC_DEC            			0x6UL 
#define CryIfChannelKeyID_AES128_CBC_ENC            			0x7UL
#endif

#define CryIfConf_CryIfKey_CryIfKey_She_MasterEcuKey              0U
#define CryIfConf_CryIfKey_CryIfKey_SecureBootProtectedKey        1U
#define CryIfConf_CryIfKey_CryIfKey_She_Key1                      2U
#define CryIfConf_CryIfKey_CryIfKey_She_Key2                      3U
#define CryIfConf_CryIfKey_CryIfKey_She_Key3                      4U
#define CryIfConf_CryIfKey_CryIfKey_She_Key4                      5U
#define CryIfConf_CryIfKey_CryIfKey_She_Key5                      6U
#define CryIfConf_CryIfKey_CryIfKey_She_Key6                      7U
#define CryIfConf_CryIfKey_CryIfKey_She_Key7                      8U
#define CryIfConf_CryIfKey_CryIfKey_She_Key8                      9U
#define CryIfConf_CryIfKey_CryIfKey_She_Key9                      10U
#define CryIfConf_CryIfKey_CryIfKey_She_Key10                     11U
#define CryIfConf_CryIfKey_CryIfKey_She_Key_Ram                   12U

/*Total no of key configured */
#define TotalnoDriver 					       1U

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


/** typedef used in CryIf_CryptoFunctions */
typedef struct sCryIf_CryptoFunctionsType
{
  CryIf_CancelJobFuncType CancelJobOfCryptoFunctions;
  CryIf_ProcessJobFuncType ProcessJobOfCryptoFunctions;
  CryIf_KeyElementGetFuncType KeyElementGetOfCryptoFunctions;
  CryIf_KeyElementSetFuncType KeyElementSetOfCryptoFunctions;
  CryIf_KeyValidSetFuncType KeyValidSetOfCryptoFunctions;
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

