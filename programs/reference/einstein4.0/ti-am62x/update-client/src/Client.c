/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2023. Visteon Corporation owns all rights to           *
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
#include "Client.h"
#include "ClientUpdateMan.h"
#include "Dcm.h"
//=======================================================================================================================

# define DNLD_TRANSFER_DATA_SEQ_OK						(0x00u)
# define DNLD_TRANSFER_DATA_SEQ_SAME					(0x01u)
# define DNLD_TRANSFER_DATA_SEQ_NOT_OK					(0x02u)

uint32 ProgrammedDataLength_U32;
uint8 Processed_RID;
uint32 DownloadLength_U32;

static uint8 UpdateCdd_TransferDataSequenceCheck(uint8 pExptdSeqCount, uint8 pRcvdSeqCount);
/*===========================================================================================================================================
* Std_ReturnType UpdateCdd_ClientInit(void)
* Function description : This function shall initialize the static variables
* Input arguments : void
* Return type : E_OK 	  - Initialzation done by client module
*            	E_NOT_OK  - Initialzation not done by client module
* Function scope : Public function
*============================================================================================================================================*/
Std_ReturnType UpdateCdd_ClientInit(void)
{
  return E_OK;
}

/*===========================================================================================================================================
* Std_ReturnType UpdateCdd_GenericRequestEraseHandler(Dcm_OpStatusType opStatus,uint8* pMsgContext,Dcm_NegativeResponseCodeType *ErrorCode)
* Function description : This function shall receive the erase request from tool and forward the request to Update Cdd component for processing
* Input arguments : opStatus,pMsgContext,ErrorCode
* Return type : E_OK 	  - Erase request accepted by client module
*            	E_NOT_OK  - Erase request not accepted by client module
* Function scope : Public function
*============================================================================================================================================*/
Std_ReturnType CUpdateCdd_UpdateCdd_GenericRIDRequestHandler(Dcm_OpStatusType opStatus, uint8 Rid_action, uint16 Rid, Dcm_MsgLenType ReqLength, Dcm_MsgType Buff,Dcm_MsgLenType* RespLength, Dcm_NegativeResponseCodeType *ErrorCode)
{
	Std_ReturnType ret = E_NOT_OK;

	ret = CUpdtMan_IInstallation_RIDHandler(opStatus, Rid_action, Rid, ReqLength, Buff, RespLength, ErrorCode);

	return ret;
}

/*===========================================================================================================================================
* Std_ReturnType UpdateCdd_GenericRequestDownloadHandler(Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier,uint32 MemoryAddress, uint32 MemorySize, uint32* BlockLength, uint8 ErrorCode)
* Function description : This function shall receive the transfer start request from tool and forward this request to Update Cdd Or UCL request
* Input arguments : request message from tool
* Return type : E_OK 	  - Start download request from tool is accepted
*            	E_NOT_OK  - Start download request from tool is not accepted
* Function scope : Private function
*============================================================================================================================================*/
Std_ReturnType CUpdateCdd_UpdateCdd_GenericRequestDownloadHandler(Dcm_OpStatusType OpStatus, uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint32* BlockLength, uint8* ErrorCode)
{
  	Std_ReturnType ret = E_NOT_OK;

    /*unused parameter*/

	ret = CUpdtMan_IInstallation_TransferStart(OpStatus, DataFormatIdentifier, MemoryAddress, MemorySize, BlockLength, ErrorCode);

	return ret;
}

static uint8 UpdateCdd_TransferDataSequenceCheck(uint8 pExptdSeqCount, uint8 pRcvdSeqCount)
{
	uint8 Ret_Val = DNLD_TRANSFER_DATA_SEQ_OK;

	if ((SID_TRANSFERSTART == Processed_RID) && (0x01u != pRcvdSeqCount))
	{
		Ret_Val = DNLD_TRANSFER_DATA_SEQ_NOT_OK;
	}
	else if (SID_TRANSFERDATA == Processed_RID)
	{
		if (pExptdSeqCount != pRcvdSeqCount)
		{
			if (pRcvdSeqCount != (pExptdSeqCount - 1u))
			{
				Ret_Val = DNLD_TRANSFER_DATA_SEQ_NOT_OK;
			}
			else
			{
				Ret_Val = DNLD_TRANSFER_DATA_SEQ_SAME;
			}
		}
	}
	else
	{
		/* Do Nothing */
	}

	return Ret_Val;
}

/*===========================================================================================================================================
* Std_ReturnType UpdateCdd_GenericTransferDataHandler(Dcm_OpStatusType OpStatus,uint8 MemoryIdentifier,uint32 MemoryAddress,uint32 MemorySize,const uint8* MemoryData,uint8* ErrorCode)
* Function description : This function shall receive the transfer data request from tool and forward this request to Update Cdd component
* Input arguments : request message from tool
* Return type : E_OK 	  - Request from tool is accepted
*            	E_NOT_OK  - Request from tool is not accepted
* Function scope : Private function
*============================================================================================================================================*/
Std_ReturnType CUpdateCdd_UpdateCdd_GenericTransferDataHandler(Dcm_OpStatusType OpStatus, uint8 MemoryIdentifier,uint32 MemoryAddress,uint32 MemorySize, uint8* MemoryData,uint8* ErrorCode)
{
	Std_ReturnType ret = DCM_E_NOT_OK;

	ret = CUpdtMan_IInstallation_TransferData(OpStatus, MemoryIdentifier, MemoryAddress, MemorySize, MemoryData, ErrorCode);

	return ret;
}

/*===========================================================================================================================================
* Std_ReturnType UpdateCdd_GenericRequestTransferExit(Dcm_OpStatusType opStatus, Dcm_MsgContextType *msgContext, uint8* errCode)
* Function description : This function shall receive the transfer exit request from tool and forward this request to Update Cdd component
* Input arguments : request message from tool
* Return type : E_OK 	  - Request from tool is accepted
*            	E_NOT_OK  - Request from tool is not accepted
* Function scope : Private function
*============================================================================================================================================*/
Std_ReturnType CUpdateCdd_UpdateCdd_GenericTransferExitHandler(Dcm_OpStatusType opStatus, uint8 RequestfParameterRecord, uint32 RequestParameterRecordSize, uint8* ResponseParameterRecord, uint32* ResponseParameterRecordSize, uint8* errCode)
{
	Std_ReturnType  ret = DCM_E_NOT_OK;

	ret = CUpdtMan_IInstallation_TransferExit(errCode);

  	return ret;
}

/*===========================================================================================================================================
* Std_ReturnType UpdateCdd_GenericRequest_Verify_RSA_SignatureValue (Dcm_OpStatusType opStatus, uint8 *pMsgContext, Dcm_NegativeResponseCodeType *ErrorCode)
* Function description : This function shall perform RSA verification
* Input arguments : request message from tool
* Return type : E_OK 	  - Request for RSA verification accepted
*            	E_NOT_OK  - Request from tool is not accepted
* Function scope : Private function
*============================================================================================================================================*/
Std_ReturnType UpdateCdd_GenericRequest_Verify_RSA_SignatureValue (Dcm_OpStatusType opStatus, uint8 *pMsgContext, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return E_OK;
}

Std_ReturnType CUpdateCdd_UpdateCdd_GenericProgSessionRequest(Dcm_NegativeResponseCodeType *ErrorCode)
{
	Std_ReturnType ret = DCM_E_NOT_OK;

	ret = CUpdtMan_IInstallation_ProgSessionRequest(ErrorCode);

	return ret;
}

