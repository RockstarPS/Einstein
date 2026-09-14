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
#ifndef CSM_H
#define CSM_H

#include "Csm_Cfg.h"
#include "Csm_Types.h"

/*****************************************************************************
 *  GLOBAL CONSTANT MACROS
******************************************************************************/
/* Vendor and module identification */

#define CSM_INSTANCE_ID                         (0u)
/* ----- API service IDs ----- */
/* Service ID: Csm_Init() */
#define CSM_INIT_ID                             (0x00u)
/* Service ID: Csm_MainFunction() */
#define CSM_MAINFUNCTION_ID                     (0x01u)
/* Service ID: Csm_KeyElementSet() */
#define CSM_KEYELEMENTSET_ID                    (0x78u)
/* Service ID: Csm_KeySetValid() */
#define CSM_KEYSETVALID_ID                      (0x67u)
/* Service ID: Csm_KeyElementGet() */
#define CSM_KEYELEMENTGET_ID                    (0x68u)
/* Service ID: Csm_Hash() */
#define CSM_HASH_ID                             (0x5Du)
/* Service ID: Csm_MacGenerate() */
#define CSM_MACGENERATE_ID                      (0x60u)
/* Service ID: Csm_MacVerify() */
#define CSM_MACVERIFY_ID                        (0x61u)
/* Service ID: Csm_Encrypt() */
#define CSM_ENCRYPT_ID                          (0x5Eu)
/* Service ID: Csm_Decrypt() */
#define CSM_DECRYPT_ID                          (0x5Fu)
/* Service ID: Csm_SignatureGenerate() */
#define CSM_SIGNATUREGENERATE_ID                (0x76u)
/* Service ID: Csm_SignatureVerify() */
#define CSM_SIGNATUREVERIFY_ID                  (0x64u)
/* Service ID: Csm_AEADEncrypt() */
#define CSM_AEADENCRYPT_ID                      (0x62u)
/* Service ID: Csm_AEADDecrypt() */
#define CSM_AEADDECRYPT_ID                      (0x63u)
/* Service ID: Csm_RandomGenerate() */
#define CSM_RANDOMGENERATE_ID                   (0x72u)
/* Service ID: Csm_CancelJob() */
#define CSM_CANCELJOB_ID                        (0x6Fu)
/* Service ID: Csm_CallbackNotification() */
#define CSM_CALLBACKNOTIFICATION_ID             (0x70u)
/* Service ID: Csm_KeyDerive() */
# define CSM_KEYDERIVE_ID                       (0x6Bu)
/* Service ID: Csm_CertificateParse() */
# define CSM_CERTIFICATEPARSE_ID                (0x6Eu)
/* Service ID: Csm_CertificateVerify() */
# define CSM_CERTIFICATEVERIFY_ID               (0x74u)
/* Service ID: Csm_KeyGenerate() */
# define CSM_KEYGENERATE_ID                     (0x6Au)
/* Service ID: Csm_KeyExchangeCalcPubVal() */
# define CSM_KEYEXCHANGECALCPUBVAL_ID           (0x6Cu)
/* Service ID: Csm_KeyExchangeCalcSecret() */
# define CSM_KEYEXCHANGECALCSECRET_ID           (0x6Du)
/* Service ID: Csm_KeyElementCopy() */
# define CSM_KEYELEMENTCOPY_ID                  (0x71u)
/* Service ID: Csm_KeyElementCopyPartial() */
# define CSM_KEYELEMENTCOPYPARTIAL_ID           (0x79u)
/* Service ID: Csm_KeyCopy() */
# define CSM_KEYCOPY_ID                         (0x73u)

/* ----- Error codes ----- */
/* Error Code: Used to check if no error occurred */
#define CSM_E_NO_ERROR                          (0x00u)
/* Error Code: API request called with invalid parameter (Nullpointer) */
#define CSM_E_PARAM_POINTER                     (0x01u)
/* Error Code: API request called before initialization of CSM module */
#define CSM_E_UNINIT                            (0x05u)
/* Error Code: Initialization of CSM module failed */
#define CSM_E_INIT_FAILED                       (0x07u)
/* Error Code: Requested service is not initialized */
#define CSM_E_SERVICE_NOT_STARTED               (0x09u)
/* Error Code: API request called with invalid parameter (invalid method for selected service) */
#define CSM_E_PARAM_METHOD_INVALID              (0x03u)
/* Error code: The service Csm_Init() is called while the module is already initialized */
#define CSM_E_ALREADY_INITIALIZED               (0x11u)

#define CSM_VENDOR_ID                    0x0033U
#define CSM_MODULE_ID                    110U
#define CSM_SW_MAJOR_VERSION             1U
#define CSM_SW_MINOR_VERSION             0U
#define CSM_SW_PATCH_VERSION             0U
/*****************************************************************************
 *  GLOBAL FUNCTION MACROS
******************************************************************************/

/*****************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
******************************************************************************/

/*****************************************************************************
 *  GLOBAL DATA PROTOTYPES
******************************************************************************/

/*****************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
******************************************************************************/

#define CSM_START_SEC_CODE
#include "Csm_MemMap.h"

/* General Function Prototypes */

void  Csm_Init( void );

/* CSM Service Function Prototypes */

void Csm_MainFunction(void);

void Csm_CallbackNotification(Crypto_JobType * job, Std_ReturnType result);

Std_ReturnType Csm_CancelJob(uint32 jobId,Crypto_OperationModeType mode);
											 
Std_ReturnType Csm_Hash(uint32 jobId, Crypto_OperationModeType mode,
                            const uint8 * dataPtr, uint32 dataLength,
                            uint8 * resultPtr, uint32 * resultLengthPtr);
Std_ReturnType Csm_Encrypt(uint32 jobId, Crypto_OperationModeType mode,
                            const uint8 * dataPtr, uint32 dataLength,
                            uint8 * resultPtr, uint32 * resultLengthPtr);											 
Std_ReturnType Csm_Decrypt(uint32 jobId, Crypto_OperationModeType mode,
							const uint8 * dataPtr, uint32 dataLength,
                            uint8 * resultPtr, uint32 * resultLengthPtr);											 
Std_ReturnType Csm_MacGenerate(uint32 jobId, Crypto_OperationModeType mode,
							const uint8 * dataPtr, uint32 dataLength, uint8 * macPtr, uint32 * macLengthPtr);
											 
Std_ReturnType Csm_MacVerify(uint32 jobId, Crypto_OperationModeType mode,
							const uint8 * dataPtr, uint32 dataLength, const uint8 * macPtr, uint32 macLength,
                            Crypto_VerifyResultType * verifyPtr);		
							
Std_ReturnType Csm_SignatureGenerate(uint32 jobId, Crypto_OperationModeType mode,
							const uint8 * dataPtr, uint32 dataLength, uint8 * resultPtr, 
							uint32 * resultLengthPtr);
							
Std_ReturnType Csm_SignatureVerify(uint32 jobId, Crypto_OperationModeType mode,
							const uint8 * dataPtr, uint32 dataLength, const uint8 * signaturePtr, 
							uint32 signatureLength, Crypto_VerifyResultType * verifyPtr);
							
Std_ReturnType Csm_KeySetValid(uint32 keyId);

Std_ReturnType Csm_KeyElementSet(uint32 keyId, uint32 keyElementId,
                                  const uint8 * keyPtr, uint32 keyLength);
								  
Std_ReturnType Csm_KeyElementGet(uint32 keyId, uint32 keyElementId, uint8 * keyPtr,
                                            uint32 * keyLengthPtr);											 
Std_ReturnType Csm_RandomGenerate(uint32 jobId, uint8 * resultPtr,
			uint32 * resultLengthPtr);
Std_ReturnType Csm_AEADEncrypt(uint32 jobId,Crypto_OperationModeType mode,
                const uint8 * plaintextPtr,uint32 plaintextLength,
                const uint8 * associatedDataPtr,uint32 associatedDataLength,
                uint8 * ciphertextPtr,uint32 * ciphertextLengthPtr,uint8 * tagPtr,
                uint32 * tagLengthPtr);
Std_ReturnType Csm_AEADDecrypt(uint32 jobId,Crypto_OperationModeType mode,const uint8 * ciphertextPtr,uint32 ciphertextLength,
            const uint8 * associatedDataPtr,uint32 associatedDataLength,const uint8 * tagPtr,uint32 tagLength,uint8 * plaintextPtr,
            uint32 * plaintextLengthPtr,Crypto_VerifyResultType * verifyPtr);
Std_ReturnType Csm_CertificateParse(uint32 keyId);
Std_ReturnType Csm_CertificateVerify(uint32 keyId,uint32 verifyKeyId,Crypto_VerifyResultType * verifyPtr);
Std_ReturnType Csm_KeyGenerate(uint32 keyId);
Std_ReturnType Csm_KeyElementCopy(uint32 keyId,uint32 keyElementId,uint32 targetKeyId,uint32 targetKeyElementId);
Std_ReturnType Csm_KeyCopy(uint32 keyId,uint32 targetKeyId);
Std_ReturnType Csm_KeyDerive(uint32 keyId,uint32 targetKeyId);
Std_ReturnType Csm_KeyExchangeCalcSecret(uint32 keyId,const uint8* partnerPublicValuePtr,uint32 partnerPublicValueLength);
Std_ReturnType Csm_KeyExchangeCalcPubVal(uint32 keyId,uint8* publicValuePtr,uint32* publicValueLengthPtr);

#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"

#endif /* CSM_H */
/*****************************************************************************
*  END OF FILE: CSM.H
******************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 28-06-2022                                            */
/*Version           : turing_bsw_csm_0.0.4                                  */
/*By                : jkanikal                                              */
/*Traceability      : RTC#1564070                                           */
/*Change Description: Coverity and Misra analysis and fix	                */
/*                                                                          */
/*--------------------------------------------------------------------------*/


