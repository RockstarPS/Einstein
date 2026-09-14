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

#ifndef CRYIF_C
#define CRYIF_C

/*****************************************************************************
* @ingroup Crypto Service Interface
* @file CryIf.h
* @brief CRYIF main layer which handles the Init, Mainfunctions and APIs for SWCs
* ****************************************************************************/

/*****************************************************************************
 *  INCLUDES
******************************************************************************/
#include "CryIf.h"
#include "Csm_Types.h"
#include "CryIf_Cfg.h"
#include "CryIf_Cbk.h"

/*******************************************************************************
*  Private Macros Definitions                                                 **
*******************************************************************************/
# define CRYIF_INIT                                (0xCDu) //From CryIf4.3 Macro 
/*****************************************************************************
 *  GLOBAL DATA
******************************************************************************/
/** Initialization state of the module */
uint8 CryIf4dot4_Initialized = CRYIF_E_UNINIT;
/******************************************************************************
*  Public Function Definitions                                                *
*******************************************************************************/

/*============================================================================
** Function Name    :   CryIf_GetVersionInfo
** Visibility       :   public
** Description      :   This function used for fetching the version info
** Invocation       :
** Inputs           :  pointer to Std_VersionInfoType
** Outputs          :  void
** Critical Section :  none
**==========================================================================*/
void CryIf_GetVersionInfo (Std_VersionInfoType * const versionInfoPtr)
{
    versionInfoPtr->moduleID          = CRYPTO_VERSION_INFO_MODULE_ID;
    versionInfoPtr->vendorID          = CRYPTO_VERSION_INFO_VENDOR_ID;
    versionInfoPtr->sw_major_version  = CRYPTO_VERSION_INFO_MAJOR_VERSION;
    versionInfoPtr->sw_minor_version  = CRYPTO_VERSION_INFO_MINOR_VERSION;
    versionInfoPtr->sw_patch_version  = CRYPTO_VERSION_INFO_PATCH_VERSION;
}

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
void CryIf_Init(const CryIf_ConfigType * const cryIf_config_Ptr)
{
    /* Check component init Status */
	if (CryIf4dot4_Initialized == (uint8)CRYIF_INIT)
	{
		#if (CRYIF_DEV_ERROR_REPORT == STD_ON)
			CRYIF_DET_REPORTERROR(CRYIF_SID_INIT, CRYIF_E_ALREADY_INITIALIZED);
		#endif
	}
	else
	{
		CryIf4dot4_Initialized = (uint8)CRYIF_INIT;
	}
}

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
Std_ReturnType CryIf_ProcessJob(uint32 channelId, Crypto_JobType * job)
{
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CRYIF_E_NO_ERROR;
	uint32 Index = 0ul;

	/* Check component init Status  */
	if ((uint8)CRYIF_E_UNINIT == CryIf4dot4_Initialized)
	{
		errorId = CRYIF_E_UNINIT;
	}
	/* Check for null pointer */
	else if (NULL_PTR == job )
	{
		errorId = CRYIF_E_PARAM_POINTER;
	}
	/* Check parameter 'channelId' */
	else if (TotalnoCryIfChannel <= channelId)
	{
		errorId = CRYIF_E_PARAM_HANDLE;
	}
	else
	{
		Status = CryIf_CryptoFunctions[Index].ProcessJobOfCryptoFunctions\
		(channelId, job);
	}
	#if (CRYIF_DEV_ERROR_REPORT == STD_ON)
		if (CRYIF_E_NO_ERROR != errorId)
		{
			CRYIF_DET_REPORTERROR(CRYIF_SID_PROCESS_JOB, errorId);  
		}
	#else
		(void)errorId;
	#endif /*CRYIF_DEV_ERROR_REPORT == STD_ON*/
	return Status;
}/* CryIf_ProcessJob */

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
Std_ReturnType CryIf_CancelJob(uint32 channelId, Crypto_JobType * job)
{ 
	Std_ReturnType Status = E_NOT_OK;
	uint8 errorId = CRYIF_E_NO_ERROR;
	uint32 Index = 0ul;
	/* Check component init Status */
	if ((uint8)CRYIF_E_UNINIT == CryIf4dot4_Initialized)
	{
		errorId = CRYIF_E_UNINIT;
	}
	/* Check for null pointer */
	else if (NULL_PTR == job )
	{
		errorId = CRYIF_E_PARAM_POINTER;
	}
	/* Check parameter 'channelId' */
	else if (TotalnoCryIfChannel <= channelId)
	{
		errorId = CRYIF_E_PARAM_HANDLE;
	}
	else
	{
		Status = (CryIf_CryptoFunctions[Index].CancelJobOfCryptoFunctions)\
				(channelId, job);
	}

	#if (CRYIF_DEV_ERROR_REPORT == STD_ON)
		if (CRYIF_E_NO_ERROR != errorId)
		{
			CRYIF_DET_REPORTERROR(CRYIF_SID_CANCEL_JOB, errorId);
		}
	#else
		(void)errorId;
	#endif /*CRYIF_DEV_ERROR_REPORT == STD_ON*/

	return Status;
} /* CryIf_CancelJob() */

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
                    const uint8 * keyPtr, uint32 keyLength)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 errorId = CRYIF_E_NO_ERROR;
	uint32 Index = 0ul;
	/* Check component init Status */
	if ((uint8)CRYIF_E_UNINIT == CryIf4dot4_Initialized)
	{
		errorId = CRYIF_E_UNINIT;
	}
	/* Check for null pointer */
	else if (NULL_PTR == keyPtr)
	{
		errorId = CRYIF_E_PARAM_POINTER;
	}
	/* Check parameter 'keyLength' */
	else if (ZEROLENGTH == keyLength)
	{
		errorId = CRYIF_E_PARAM_VALUE;
	}
	/* Check parameter 'cryIfKeyId' */
	else if (TotalnoCryIfKey <= cryIfKeyId)
	{
		errorId = CRYIF_E_PARAM_HANDLE;
	}
	else
	{
		ret =  (CryIf_CryptoFunctions[Index].KeyElementSetOfCryptoFunctions)\
		(CryIf_Key[cryIfKeyId].RefOfKey, keyElementId, keyPtr, keyLength);
	}

	#if (CRYIF_DEV_ERROR_REPORT == STD_ON)
		if (CRYIF_E_NO_ERROR != errorId)
		{
			CRYIF_DET_REPORTERROR(CRYIF_SID_KEY_ELEMENT_SET, errorId);
		}
	#else
		(void)errorId;
	#endif /*CRYIF_DEV_ERROR_REPORT == STD_ON*/

	return ret;
} /* CryIf_KeyElementSet() */

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
                    uint8 * resultPtr, uint32 * resultLengthPtr)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 errorId = CRYIF_E_NO_ERROR;
	uint32 Index = 0ul;
	/* Check component init Status */
	if ((uint8)CRYIF_E_UNINIT == CryIf4dot4_Initialized)
	{
		errorId = CRYIF_E_UNINIT;
	}
	/* Check for null pointer */
	else if ((NULL_PTR == resultPtr) || (NULL_PTR == resultLengthPtr))
	{
		errorId = CRYIF_E_PARAM_POINTER;
	}
	/* Check parameter 'resultLengthPtr' */
	else if (ZEROLENGTH == *(resultLengthPtr))
	{
		errorId = CRYIF_E_PARAM_VALUE;
	}
	/* Check parameter 'cryIfKeyId' */
	else if (TotalnoCryIfKey <= cryIfKeyId)
	{
		errorId = CRYIF_E_PARAM_HANDLE;
	}
	else
	{
		ret = (CryIf_CryptoFunctions[Index].KeyElementGetOfCryptoFunctions) \
		(CryIf_Key[cryIfKeyId].RefOfKey, keyElementId, resultPtr, resultLengthPtr);
	}

	#if (CRYIF_DEV_ERROR_REPORT == STD_ON)
		if (CRYIF_E_NO_ERROR != errorId)
		{
			CRYIF_DET_REPORTERROR(CRYIF_SID_KEY_ELEMENT_GET, errorId);
		}
	#else
		(void)errorId;
	#endif /*CRYIF_DEV_ERROR_REPORT == STD_ON*/

	return ret;
} /* CryIf_KeyElementGet() */

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
Std_ReturnType CryIf_KeySetValid(uint32 cryIfKeyId)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 errorId = CRYIF_E_NO_ERROR;
	uint32 Index = 0ul;
	/* Check component init Status */
	if ((uint8)CRYIF_E_UNINIT == CryIf4dot4_Initialized)
	{
		errorId = CRYIF_E_UNINIT;
	}
	/* Check parameter 'cryIfKeyId' */
	else if (TotalnoCryIfKey <= cryIfKeyId)
	{
		errorId = CRYIF_E_PARAM_HANDLE;
	}
	else
	{
		ret = ((CryIf_CryptoFunctions[Index].KeyValidSetOfCryptoFunctions)\
		(CryIf_Key[cryIfKeyId].RefOfKey));
	}

	#if (CRYIF_DEV_ERROR_REPORT == STD_ON)
		if (CRYIF_E_NO_ERROR != errorId)
		{
			CRYIF_DET_REPORTERROR(CRYIF_SID_KEY_SET_VALID,errorId );
		}
	#else
		(void)errorId;
	#endif /*CRYIF_DEV_ERROR_REPORT == STD_ON*/

	return ret;
}/* CryIf_KeySetValid */

Std_ReturnType CryIf_KeyGenerate(uint32 cryIfKeyId)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 errorId = CRYIF_E_NO_ERROR;
	uint32 Index = 0ul;
	/* Check component init Status */
	if ((uint8)CRYIF_E_UNINIT == CryIf4dot4_Initialized)
	{
		errorId = CRYIF_E_UNINIT;
	}
	/* Check parameter 'cryIfKeyId' */
	else if (TotalnoCryIfKey <= cryIfKeyId)
	{
		errorId = CRYIF_E_PARAM_HANDLE;
	}
	else
	{
		ret = ((CryIf_CryptoFunctions[Index].KeyGenerateOfCryptoFunctions)\
		(CryIf_Key[cryIfKeyId].RefOfKey));
	}

	#if (CRYIF_DEV_ERROR_REPORT == STD_ON)
		if (CRYIF_E_NO_ERROR != errorId)
		{
			CRYIF_DET_REPORTERROR(CRYIF_SID_KEY_GENERATE,errorId );
		}
	#else
		(void)errorId;
	#endif /*CRYIF_DEV_ERROR_REPORT == STD_ON*/

	return ret;
}

Std_ReturnType CryIf_CertificateParse(uint32 cryIfKeyId)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 errorId = CRYIF_E_NO_ERROR;
	uint32 Index = 0ul;
	/* Check component init Status */
	if ((uint8)CRYIF_E_UNINIT == CryIf4dot4_Initialized)
	{
		errorId = CRYIF_E_UNINIT;
	}
	/* Check parameter 'cryIfKeyId' */
	else if (TotalnoCryIfKey <= cryIfKeyId)
	{
		errorId = CRYIF_E_PARAM_HANDLE;
	}
	else
	{
		ret = ((CryIf_CryptoFunctions[Index].CertificateParseOfCryptoFunctions)\
		(CryIf_Key[cryIfKeyId].RefOfKey));
	}

	#if (CRYIF_DEV_ERROR_REPORT == STD_ON)
		if (CRYIF_E_NO_ERROR != errorId)
		{
			CRYIF_DET_REPORTERROR(CRYIF_SID_CERTFICATE_PARSE,errorId );
		}
	#else
		(void)errorId;
	#endif /*CRYIF_DEV_ERROR_REPORT == STD_ON*/

	return ret;
}

Std_ReturnType CryIf_CertificateVerify(uint32 cryIfKeyId,uint32 verifyCryIfKeyId,Crypto_VerifyResultType* verifyPtr)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 errorId = CRYIF_E_NO_ERROR;
	uint32 Index = 0ul;
	/* Check component init Status */
	if ((uint8)CRYIF_E_UNINIT == CryIf4dot4_Initialized)
	{
		errorId = CRYIF_E_UNINIT;
	}
	/* Check parameter 'cryIfKeyId' */
	else if ((TotalnoCryIfKey <= cryIfKeyId) || (TotalnoCryIfKey <= verifyCryIfKeyId))
	{
		errorId = CRYIF_E_PARAM_HANDLE;
	}
	else if(NULL_PTR == verifyPtr)
	{
		errorId = CRYIF_E_PARAM_POINTER;
	}
	else
	{
		ret = ((CryIf_CryptoFunctions[Index].CertificateVerifyOfCryptoFunctions)\
		(CryIf_Key[cryIfKeyId].RefOfKey,CryIf_Key[verifyCryIfKeyId].RefOfKey,verifyPtr));
	}
	#if (CRYIF_DEV_ERROR_REPORT == STD_ON)
		if (CRYIF_E_NO_ERROR != errorId)
		{
			CRYIF_DET_REPORTERROR(CRYIF_SID_CERTFICATE_VERIFY,errorId );
		}
	#else
		(void)errorId;
	#endif /*CRYIF_DEV_ERROR_REPORT == STD_ON*/
	return ret;
}

Std_ReturnType CryIf_KeyElementCopy(uint32 cryIfKeyId,uint32 keyElementId,uint32 targetCryIfKeyId,uint32 targetKeyElementId)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 errorId = CRYIF_E_NO_ERROR;
	uint32 Index = 0ul;
	/* Check component init Status */
	if ((uint8)CRYIF_E_UNINIT == CryIf4dot4_Initialized)
	{
		errorId = CRYIF_E_UNINIT;
	}
	/* Check parameter 'cryIfKeyId' */
	else if ((TotalnoCryIfKey <= cryIfKeyId) || (TotalnoCryIfKey <= targetCryIfKeyId))
	{
		errorId = CRYIF_E_PARAM_HANDLE;
	}
	else
	{
		ret = ((CryIf_CryptoFunctions[Index].KeyElementOfCryptoFunctions)\
		(CryIf_Key[cryIfKeyId].RefOfKey,keyElementId,CryIf_Key[targetCryIfKeyId].RefOfKey,targetKeyElementId));
	}
	#if (CRYIF_DEV_ERROR_REPORT == STD_ON)
		if (CRYIF_E_NO_ERROR != errorId)
		{
			CRYIF_DET_REPORTERROR(CRYIF_SID_KEY_ELEMENT_COPY,errorId );
		}
	#else
		(void)errorId;
	#endif /*CRYIF_DEV_ERROR_REPORT == STD_ON*/
	return ret;
}

Std_ReturnType CryIf_KeyCopy(uint32 cryIfKeyId, uint32 targetCryIfKeyId)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 errorId = CRYIF_E_NO_ERROR;
	uint32 Index = 0ul;
	/* Check component init Status */
	if ((uint8)CRYIF_E_UNINIT == CryIf4dot4_Initialized)
	{
		errorId = CRYIF_E_UNINIT;
	}
	/* Check parameter 'cryIfKeyId' */
	else if ((TotalnoCryIfKey <= cryIfKeyId) || (TotalnoCryIfKey <= targetCryIfKeyId))
	{
		errorId = CRYIF_E_PARAM_HANDLE;
	}
	else
	{
		ret = ((CryIf_CryptoFunctions[Index].KeyCopyOfCryptoFunctions)\
		(CryIf_Key[cryIfKeyId].RefOfKey,CryIf_Key[targetCryIfKeyId].RefOfKey));
	}
	#if (CRYIF_DEV_ERROR_REPORT == STD_ON)
		if (CRYIF_E_NO_ERROR != errorId)
		{
			CRYIF_DET_REPORTERROR(CRYIF_SID_KEY_COPY,errorId );
		}
	#else
		(void)errorId;
	#endif /*CRYIF_DEV_ERROR_REPORT == STD_ON*/
	return ret;
}

Std_ReturnType CryIf_KeyDerive(uint32 cryIfKeyId,uint32 targetCryIfKeyId)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 errorId = CRYIF_E_NO_ERROR;
	uint32 Index = 0ul;
	/* Check component init Status */
	if ((uint8)CRYIF_E_UNINIT == CryIf4dot4_Initialized)
	{
		errorId = CRYIF_E_UNINIT;
	}
	/* Check parameter 'cryIfKeyId' */
	else if ((TotalnoCryIfKey <= cryIfKeyId) || (TotalnoCryIfKey <= targetCryIfKeyId))
	{
		errorId = CRYIF_E_PARAM_HANDLE;
	}
	else
	{
		ret = ((CryIf_CryptoFunctions[Index].KeyDeriveOfCryptoFunctions)\
		(CryIf_Key[cryIfKeyId].RefOfKey,CryIf_Key[targetCryIfKeyId].RefOfKey));
	}
	#if (CRYIF_DEV_ERROR_REPORT == STD_ON)
		if (CRYIF_E_NO_ERROR != errorId)
		{
			CRYIF_DET_REPORTERROR(CRYIF_SID_KEY_DERIVE,errorId );
		}
	#else
		(void)errorId;
	#endif /*CRYIF_DEV_ERROR_REPORT == STD_ON*/
	return ret;
}

Std_ReturnType CryIf_KeyExchangeCalcSecret(uint32 cryIfKeyId,const uint8* partnerPublicValuePtr,uint32 partnerPublicValueLength)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 errorId = CRYIF_E_NO_ERROR;
	uint32 Index = 0ul;
	/* Check component init Status */
	if ((uint8)CRYIF_E_UNINIT == CryIf4dot4_Initialized)
	{
		errorId = CRYIF_E_UNINIT;
	}
	/* Check parameter 'cryIfKeyId' */
	else if ((TotalnoCryIfKey <= cryIfKeyId))
	{
		errorId = CRYIF_E_PARAM_HANDLE;
	}
	else if(NULL_PTR == partnerPublicValuePtr)
	{
		errorId = CRYIF_E_PARAM_POINTER;
	}
	else
	{
		ret = ((CryIf_CryptoFunctions[Index].KeyExchangeCalcSecretOfCryptoFunctions)\
		(CryIf_Key[cryIfKeyId].RefOfKey,partnerPublicValuePtr,partnerPublicValueLength));
	}
	#if (CRYIF_DEV_ERROR_REPORT == STD_ON)
		if (CRYIF_E_NO_ERROR != errorId)
		{
			CRYIF_DET_REPORTERROR(CRYIF_SID_KEY_EXCHANGE_CALCSECRET,errorId );
		}
	#else
		(void)errorId;
	#endif /*CRYIF_DEV_ERROR_REPORT == STD_ON*/
	return ret;
}

Std_ReturnType CryIf_KeyExchangeCalcPubVal(uint32 cryIfKeyId, uint8* publicValuePtr, uint32* publicValueLengthPtr)
{
	Std_ReturnType ret = E_NOT_OK;
	uint8 errorId = CRYIF_E_NO_ERROR;
	uint32 Index = 0ul;
	/* Check component init Status */
	if ((uint8)CRYIF_E_UNINIT == CryIf4dot4_Initialized)
	{
		errorId = CRYIF_E_UNINIT;
	}
	/* Check parameter 'cryIfKeyId' */
	else if ((TotalnoCryIfKey <= cryIfKeyId))
	{
		errorId = CRYIF_E_PARAM_HANDLE;
	}
	else if((NULL_PTR == publicValuePtr) || ((NULL_PTR == publicValueLengthPtr)))
	{
		errorId = CRYIF_E_PARAM_POINTER;
	}
	else
	{
		ret = ((CryIf_CryptoFunctions[Index].KeyExchangeCalcPubValOfCryptoFunctions)\
		(CryIf_Key[cryIfKeyId].RefOfKey,publicValuePtr,publicValueLengthPtr));
	}
	#if (CRYIF_DEV_ERROR_REPORT == STD_ON)
		if (CRYIF_E_NO_ERROR != errorId)
		{
			CRYIF_DET_REPORTERROR(CRYIF_SID_KEY_EXCHANGE_CALCPUBVAL,errorId );
		}
	#else
		(void)errorId;
	#endif /*CRYIF_DEV_ERROR_REPORT == STD_ON*/
	return ret;
}

//extern void Cry_She_CryIfCallbackNotification ( Crypto_JobType * job , Crypto_ResultType result );
/*============================================================================
** Function Name    :   CryIf_CallbackNotification
** Visibility       :   public
** Description      :   Notifies the CRYIF about the completion of the request with the result of the
**						cryptographic operation
** Invocation       :
** Inputs           :  job - Points to the completed job's information structure. 
**						It contains a callbackID to identify which job is finished.
**						result - Contains the result of the cryptographic operation.
** Outputs          :  none
** Critical Section :  none
**==========================================================================*/
void CryIf_CallbackNotification(Crypto_JobType * job, Std_ReturnType result)
{
} /* CryIf_CallbackNotification*/


#define CRYIF_STOP_SEC_CODE
#include "Csm_MemMap.h" 
#endif /* #ifndef CRYIF_C */
/*****************************************************************************
 *  END OF FILE: CryIf.c
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
