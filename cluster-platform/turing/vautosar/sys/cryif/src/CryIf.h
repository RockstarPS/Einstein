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

#ifndef CRYIF_H
#define CRYIF_H

/*****************************************************************************
 *  INCLUDES
******************************************************************************/
#include "CryIf_Cfg.h"
//#include "vwCsm_MemMap.h"
//#include "vwCsm_Types.h"

#define CRYIF_STOP_SEC_CODE
/*****************************************************************************
 *  GLOBAL CONSTANT MACROS
******************************************************************************/

/* Vendor and module identification */

#define CRYIF_MODULE_ID                           (112u)
#define CRYIF_INSTANCE_ID_DET                     (0x00u)

/* ----- API service IDs ----- */
#define CRYIF_SID_INIT                            (0x00u)
#define CRYIF_SID_GET_VERSION_INFO                (0x01u)
#define CRYIF_SID_PROCESS_JOB                     (0x03u)
#define CRYIF_SID_CANCEL_JOB                      (0x0Eu)
#define CRYIF_SID_KEY_ELEMENT_SET                 (0x04u)
#define CRYIF_SID_KEY_SET_VALID                   (0x05u)
#define CRYIF_SID_KEY_ELEMENT_GET                 (0x06u)
#define CRYIF_SID_KEY_ELEMENT_COPY                (0x0Fu)
#define CRYIF_SID_KEY_ELEMENT_COPY_PARTIAL        (0x12u)
#define CRYIF_SID_KEY_COPY                        (0x10u)
#define CRYIF_SID_RANDOM_SEED                     (0x07u)
#define CRYIF_SID_KEY_GENERATE                    (0x08u)
#define CRYIF_SID_KEY_DERIVE                      (0x09u)
#define CRYIF_SID_KEY_EXCHANGE_CALCPUBVAL         (0x0Au)
#define CRYIF_SID_KEY_EXCHANGE_CALCSECRET         (0x0Bu)
#define CRYIF_SID_CERTFICATE_PARSE                (0x0Cu)
#define CRYIF_SID_CERTFICATE_VERIFY               (0x11u)
#define CRYIF_SID_CALLBACK_NOTIFICATION           (0x0Du)

/* ----- Error codes ----- */
#define CRYIF_E_UNINIT                            (0x00u) /* API request called before initialisation of CRYIF module. */
#define CRYIF_E_INIT_FAILED                       (0x01u) /* API request called with invalid parameter (null pointer) */
#define CRYIF_E_PARAM_POINTER                     (0x02u) /* API request called with invalid parameter (null pointer) */
#define CRYIF_E_PARAM_HANDLE                      (0x03u) /* API request called with invalid parameter (out of range). */
#define CRYIF_E_PARAM_VALUE                       (0x04u) /* API request called with invalid parameter (invalid value) */
#define CRYIF_E_KEY_SIZE_MISMATCH                 (0x05u) /* Source key element size does not match the target key elements size.  */
#define CRYIF_E_ALREADY_INITIALIZED               (0x11u) /* The service CryIf4dot4_Init() is called while the module is already initialized */
#define CRYIF_E_NO_ERROR                          (0xFFu) /* used to check if no error occurred - use a value unequal to any error code */

#define CRYPTO_VERSION_INFO_MODULE_ID           ((uint8)0)
#define CRYPTO_VERSION_INFO_VENDOR_ID           ((uint8)0)
#define CRYPTO_VERSION_INFO_MAJOR_VERSION       ((uint8)0)
#define CRYPTO_VERSION_INFO_MINOR_VERSION       ((uint8)0)
#define CRYPTO_VERSION_INFO_PATCH_VERSION       ((uint8)0)

//#define CRYIF_INIT                                (0xFFu) /* Crypto Interface Initialized  */
/*****************************************************************************
 *  STRUCTURES
******************************************************************************/
typedef struct
{
    void * cryIf_config_Ptr;
} CryIf_ConfigType;


/*****************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
******************************************************************************/
#define CRYIF_START_SEC_CODE
//#include "vwCsm_MemMap.h" 

/*============================================================================
** Function Name    :   CryIf_GetVersionInfo
** Visibility       :   public
** Description      :   This function used for fetching the version info
** Invocation       :
** Inputs           :  pointer to Std_VersionInfoType
** Outputs          :  void
** Critical Section :  none
**==========================================================================*/
void CryIf_GetVersionInfo (Std_VersionInfoType * const versionInfoPtr);

/*============================================================================
** Function Name    :   CryIf_Init
** Visibility       :   public
** Description      :   This function initializes the module CryIf
** Invocation       :   
** Inputs           :  configPtr - pointer to CryIf_ConfigType
**                     It's kept null as it's not supported currently
**                     as per AUTOSAR 4.4
** Outputs          :  void
** Critical Section :  none
**==========================================================================*/
void CryIf_Init(const CryIf_ConfigType* configPtr);

/*============================================================================
** Function Name    :   CryIf_ProcessJob
** Visibility       :   public
** Description      :   This interface dispatches the received jobs to the 
**                      configured crypto driver object.
** Invocation       :
** Inputs           :  channel Id, pointer to Crypto_JobType 
** Outputs          :  Std_ReturnType
** Critical Section :  none
**==========================================================================*/
Std_ReturnType CryIf_ProcessJob(uint32 channelId, Crypto_JobType * job);

/*============================================================================
** Function Name    :   CryIf_CancelJob
** Visibility       :   public
** Description      :   This interface dispatches the job cancellation function to the
**                      configured crypto driver object.
** Invocation       :
** Inputs           :  channel Id, pointer to Crypto_JobType 
** Outputs          :  Std_ReturnType
** Critical Section :  none
**==========================================================================*/
Std_ReturnType CryIf_CancelJob(uint32 channelId, Crypto_JobType * job);

/*============================================================================
** Function Name    :   CryIf_KeyElementSet
** Visibility       :   public
** Description      :   This function shall dispatch the set key element function 
**                      to the configured crypto driver object.
** Invocation       :
** Inputs           :  cryIfKeyId, keyElementId, pointer to keyPtr, keyLength
** Outputs          :  Std_ReturnType
** Critical Section :  none
**==========================================================================*/
Std_ReturnType CryIf_KeyElementSet(uint32 cryIfKeyId, uint32 keyElementId, 
                    const uint8 * keyPtr, uint32 keyLength);

/*============================================================================
** Function Name    :   CryIf_KeyElementGet
** Visibility       :   public
** Description      :   This function shall dispatch the get key element function 
**                      to the configured crypto driver object..
** Invocation       :
** Inputs           :  cryIfKeyId, keyElementId, pointer to resultPtr, pointer to resultLengthPtr
** Outputs          :  Std_ReturnType
** Critical Section :  none
**==========================================================================*/
Std_ReturnType CryIf_KeyElementGet(uint32 cryIfKeyId, uint32 keyElementId, 
                    uint8 * resultPtr, uint32 * resultLengthPtr);

/*============================================================================
** Function Name    :   CryIf_KeySetValid
** Visibility       :   public
** Description      :   This function shall dispatch the set key valid function 
**                      to the configured crypto driver object.
** Invocation       :
** Inputs           :  cryIfKeyId - Holds the identifier of the key whose key elements shall be set to valid.
** Outputs          :  Std_ReturnType
** Critical Section :  none
**==========================================================================*/
Std_ReturnType CryIf_KeySetValid(uint32 cryIfKeyId);

/*============================================================================
** Function Name    :   CryIf_CallbackNotification
** Visibility       :   public
** Description      :   Notifies the CRYIF about the completion of the request with the 
**                      result of the cryptographic operation
** Invocation       :
** Inputs           :  pointer to job, result
** Outputs          :  none
** Critical Section :  none
**==========================================================================*/
void CryIf_CallbackNotification(Crypto_JobType* job, Std_ReturnType result);

/*============================================================================
** Function Name    :   CryIf_KeyElementCopy
** Visibility       :   public
** Description      :   This function shall copy a key elements from one key to a target key.
** Invocation       :
** Inputs           :  cryIfKeyId, keyElementId, targetCryIfKeyId, targetKeyElementId
** Outputs          :  Std_ReturnType
** Critical Section :  none
**==========================================================================*/
Std_ReturnType CryIf_KeyElementCopy(uint32 cryIfKeyId,uint32 keyElementId, 
                    uint32 targetCryIfKeyId, uint32 targetKeyElementId);

/*============================================================================
** Function Name    :   CryIf_KeyElementCopyPartial
** Visibility       :   public
** Description      :   Copies a key element to another key element. 
**                      The keyElementOffsets and keyElementCopyLength allows to copy just parts of the 
**                      source key element into the destination key element.
** Invocation       :
** Inputs           :   cryIfKeyId, keyElementId, keyElementSourceOffset, 
**                      keyElementTargetOffset, keyElementCopyLength, 
**                      targetCryIfKeyId, targetKeyElementId
** Outputs          :  Std_ReturnType
** Critical Section :  none
**==========================================================================*/
/*Std_ReturnType CryIf_KeyElementCopyPartial(uint32 cryIfKeyId, uint32 keyElementId, 
                    uint32 keyElementSourceOffset, uint32 keyElementTargetOffset, 
                    uint32 keyElementCopyLength,  uint32 targetCryIfKeyId, 
                    uint32 targetKeyElementId);*/

/*============================================================================
** Function Name    :   CryIf_KeyCopy
** Visibility       :   public
** Description      :   This function shall copy all key elements from the source key to a target key..
** Invocation       :
** Inputs           :  cryIfKeyId, targetCryIfKeyId
** Outputs          :  Std_ReturnType
** Critical Section :  none
**==========================================================================*/
Std_ReturnType CryIf_KeyCopy(uint32 cryIfKeyId, uint32 targetCryIfKeyId);

/*============================================================================
** Function Name    :   CryIf_RandomSeed
** Visibility       :   public
** Description      :   This function shall dispatch the random seed function to the configured crypto driver object.
** Invocation       :
** Inputs           :  cryIfKeyId, pointer to seedPtr, seedLength
** Outputs          :  Std_ReturnType
** Critical Section :  none
**==========================================================================*/
//Std_ReturnType CryIf_RandomSeed(uint32 cryIfKeyId, const uint8* seedPtr, uint32 seedLength);

/*============================================================================
** Function Name    :   CryIf_KeyGenerate
** Visibility       :   public
** Description      :   This function shall dispatch the key generate function to the configured crypto driver object..
** Invocation       :
** Inputs           :  cryIfKeyId - Holds the identifier of the key which is to be updated with the generated value.
** Outputs          :  Std_ReturnType
** Critical Section :  none
**==========================================================================*/
Std_ReturnType CryIf_KeyGenerate(uint32 cryIfKeyId);

/*============================================================================
** Function Name    :   CryIf_KeyDerive
** Visibility       :   public
** Description      :   This function shall dispatch the key derive function to the configured crypto driver object.
** Invocation       :
** Inputs           :  cryIfKeyId - Holds the identifier of the key which is to be updated with the generated value.
**                     targetCryIfKeyId - Holds the identifier of the key which is used to store the derived key.
** Outputs          :  Std_ReturnType
** Critical Section :  none
**==========================================================================*/
Std_ReturnType CryIf_KeyDerive(uint32 cryIfKeyId, uint32 targetCryIfKeyId);

/*============================================================================
** Function Name    :   CryIf_KeyExchangeCalcPubVal
** Visibility       :   public
** Description      :   This function shall dispatch the key exchange public value calculation 
**                      function to the configured crypto driver object.
** Invocation       :
** Inputs           :  cryIfKeyId, publicValuePtr, publicValueLengthPtr
** Outputs          :  Std_ReturnType
** Critical Section :  none
**==========================================================================*/
Std_ReturnType CryIf_KeyExchangeCalcPubVal(uint32 cryIfKeyId, uint8* publicValuePtr, uint32* publicValueLengthPtr);

/*============================================================================
** Function Name    :   CryIf_KeyExchangeCalcSecret
** Visibility       :   public
** Description      :   This function shall dispatch the key exchange common shared 
**                      secret calculation function to the configured crypto driver object.
** Invocation       :
** Inputs           :  cryIfKeyId, partnerPublicValuePtr, partnerPublicValueLength
** Outputs          :  Std_ReturnType
** Critical Section :  none
**==========================================================================*/
Std_ReturnType CryIf_KeyExchangeCalcSecret(uint32 cryIfKeyId, const uint8* partnerPublicValuePtr, uint32 partnerPublicValueLength);


/*============================================================================
** Function Name    :   CryIf_CertificateParse
** Visibility       :   public
** Description      :   This function shall dispatch the certificate parse function 
**                      to the configured crypto driver object.
** Invocation       :
** Inputs           :  cryIfKeyId
** Outputs          :  Std_ReturnType
** Critical Section :  none
**==========================================================================*/
Std_ReturnType CryIf_CertificateParse(uint32 cryIfKeyId);

/*============================================================================
** Function Name    :   CryIf_CertificateVerify
** Visibility       :   public
** Description      :   This function shall dispatch the certificate parse function 
**                      to the configured crypto driver object.
** Invocation       :
** Inputs           :  cryIfKeyId, verifyCryIfKeyId, pointer to verifyPtr;
** Outputs          :  Std_ReturnType
** Critical Section :  none
**==========================================================================*/
Std_ReturnType CryIf_CertificateVerify(uint32 cryIfKeyId,uint32 verifyCryIfKeyId,Crypto_VerifyResultType* verifyPtr);

#endif /* CRYIF_H */

/*****************************************************************************
 *  END OF FILE: CryIf.h
******************************************************************************/
/*****************************************************************************
 *  for each change to this file, be sure to record:                         *
 *     1.  who made the change and when the change was made                  *
 *     2.  why the change was made and the intended result                   *
 *  Following block needs to be repeated for each change
 ******************************************************************************
 *  Note: In the trace-ability column we need to trace back to the Design Doc.*
 *  For the initial version it is traced to the Design Document section.     *
 *  For further changes it shall trace to the source of the change which may *
 *  be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
 *  other reason                                                            *
 ******************************************************************************/
/*****************************************************************************
 Date              :__/__/____
 By                :bgeorge2
 Traceability      :RTC #1820017
 Change Description:Initial Development of Crypto-Interface 4.4
 ******************************************************************************/
