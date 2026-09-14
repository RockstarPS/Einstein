
#include "UPD_UCL_proxy.h"

uint8	UPD_UCL_State_Machine = UPD_UCL_STATE_IDLE;
uint32 	UPD_UCL_TotalBlockSize = 0u;
uint32 	UPD_UCL_TransferCompleteSize = 0u;
uint8  	UPD_UCL_SharedMem_ID_to_GP = 0u;
uint8	UPD_UCL_SharedMem_Index = 0u;
uint8 	UPD_UCL_GP_Response = 0u;


SUpdateShortServiceReq ShortService_Request;
SUpdateShortServiceResp ShortService_Response;

#pragma clang section bss=".SharedMemSection"
uint8 UPD_UCL_SharedMemory1[MAX_SIZE_OF_SHARED_MEMORY];
uint8 UPD_UCL_SharedMemory2[MAX_SIZE_OF_SHARED_MEMORY];
#pragma clang section bss=""

UPD_UCL_SharedMemoryObjType UPD_UCL_SharedMemoryObj[MAX_NO_OF_SHARED_MEMORY_BUFFER] = {{UPD_UCL_SharedMemory1,MAX_SIZE_OF_SHARED_MEMORY,0},
																					   {UPD_UCL_SharedMemory2,MAX_SIZE_OF_SHARED_MEMORY,0}};


Std_ReturnType UCL_IInstallation_Erase(uint8 opStatus, uint8 Rid_action, uint32 ReqLength, uint8* Buff,uint32* RespLength, uint8 *ErrorCode)
{
	Std_ReturnType RetVal = DCM_E_PENDING;

	if(Buff != NULL)
	{
		switch(UPD_UCL_State_Machine)
		{
			case UPD_UCL_STATE_IDLE:
			{
				ShortService_Request.sid = UDS_SERVICE_RID_ERASE;

				memset(ShortService_Request.data, 0, sizeof(ShortService_Request.data));

				memcpy(ShortService_Request.data, Buff, (LENGTH_OF_ADDRESS + LENGTH_OF_LENGTH));

				Rte_Send_CUpdateCdd_pp_SR_UpdateShortServiceRequest_UpdateShortServiceReqData(&ShortService_Request);

				UPD_UCL_State_Machine = UPD_UCL_STATE_SHORT_SERVICE;

				break;
			}
			case UPD_UCL_STATE_RX_CONFIRM:
			{
				UPD_UCL_State_Machine = UPD_UCL_STATE_IDLE;

				if(UPD_UCL_GP_Response == E_OK)
				{
					*RespLength = 1;

					Buff[0] = 0x10;

					*ErrorCode = 0;

					RetVal = E_OK;

				}
				else
				{
					*ErrorCode = NEGATIVE_RESPONSE_GIP;

					RetVal = E_NOT_OK;
				}

				break;
			}
			case UPD_UCL_STATE_SHORT_SERVICE:
			{
				break;
			}
			default:
			{
				UPD_UCL_State_Machine = UPD_UCL_STATE_FAILED;

				*ErrorCode = NEGATIVE_RESPONSE_GIP;

				RetVal = E_NOT_OK;

				break;
			}
		}
	}
	else
	{
		*ErrorCode = NEGATIVE_RESPONSE_GIP;

		RetVal = E_NOT_OK;
	}


	return RetVal;
}
Std_ReturnType UCL_GetTargetState(const char *TargetName,uint8 Bank)
{
    return E_OK;
}
Std_ReturnType UCL_IInstallation_TransferStart(uint8 OpStatus,  uint8 DataFormatIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint32* BlockLength, uint8* ErrorCode)
{
	Std_ReturnType RetVal = DCM_E_PENDING;

	*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;

	*BlockLength = 4096u;

	switch(UPD_UCL_State_Machine)
	{
		case UPD_UCL_STATE_IDLE:
		{
			ShortService_Request.sid = UDS_SERVICE_STARTDOWNLOAD;

			ShortService_Request.memoryCmd = DataFormatIdentifier;

			ShortService_Request.memoryType = 0u;

			ShortService_Request.length = (LENGTH_OF_ADDRESS + LENGTH_OF_LENGTH);

			memset(ShortService_Request.data, 0, sizeof(ShortService_Request.data));

			ShortService_Request.data[0] = (uint8)(MemoryAddress>>0);
			ShortService_Request.data[1] = (uint8)(MemoryAddress>>8);
			ShortService_Request.data[2] = (uint8)(MemoryAddress>>16);
			ShortService_Request.data[3] = (uint8)(MemoryAddress>>24);

			ShortService_Request.data[4] = (uint8)(MemorySize>>0);
			ShortService_Request.data[5] = (uint8)(MemorySize>>8);
			ShortService_Request.data[6] = (uint8)(MemorySize>>16);
			ShortService_Request.data[7] = (uint8)(MemorySize>>24);

			Rte_Send_CUpdateCdd_pp_SR_UpdateShortServiceRequest_UpdateShortServiceReqData(&ShortService_Request);

			UPD_UCL_State_Machine = UPD_UCL_STATE_SHORT_SERVICE;

			UPD_UCL_TotalBlockSize = MemorySize;

			UPD_UCL_TransferCompleteSize = 0u;

			break;
		}
		case UPD_UCL_STATE_RX_CONFIRM:
		{
			UPD_UCL_State_Machine = UPD_UCL_STATE_IDLE;

			if(UPD_UCL_GP_Response == E_OK)
			{
				*ErrorCode = 0x0;

				RetVal = E_OK;
			}
			else
			{
				*ErrorCode = NEGATIVE_RESPONSE_GIP;

				RetVal = E_NOT_OK;
			}
			break;
		}
		case UPD_UCL_STATE_SHORT_SERVICE:
		{
			break;
		}
		default:
		{
			UPD_UCL_State_Machine = UPD_UCL_STATE_FAILED;

			*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;

			RetVal = E_NOT_OK;

			break;
		}
	}

    return RetVal;
}
Std_ReturnType UCL_IInstallation_TransferData(uint8 OpStatus, uint8 MemoryIdentifier,uint32 MemoryAddress,uint32 MemorySize,const uint8* MemoryData,uint8* ErrorCode)
{
	Std_ReturnType RetVal = DCM_E_PENDING;

	*ErrorCode = 0x0;

	if((MemoryData != NULL) && (UPD_UCL_State_Machine != UPD_UCL_STATE_FAILED))
	{
		if(UPD_UCL_WriteToSharedMem(UPD_UCL_SharedMem_Index, MemoryData, MemorySize)  == E_OK)
		{
			// Copy to shared memory successful

			RetVal = E_OK;
		}
		else
		{

			UPD_UCL_SharedMem_Index = UPD_UCL_SharedMem_Index ^ (1<<0);

			if(UPD_UCL_WriteToSharedMem(UPD_UCL_SharedMem_Index, MemoryData, MemorySize)  == E_OK)
			{
				// Copy to next shared memory bank successful

				RetVal = E_OK;
			}
			else
			{
				*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;

				// copy to second bank also failed. Both banks are already full.
			}

		}
	}
	else
	{
		*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE; // some failure in the GP side. Should be updated with NRC from GP.

		RetVal = E_NOT_OK;
	}

    return RetVal;
}

Std_ReturnType UCL_IInstallation_TransferExit(uint8* ErrorCode)
{
	Std_ReturnType RetVal = DCM_E_PENDING;

	switch(UPD_UCL_State_Machine)
	{
		case UPD_UCL_STATE_IDLE:
		{
			ShortService_Request.sid = UDS_SERVICE_TRANSFEREXIT;

			Rte_Send_CUpdateCdd_pp_SR_UpdateShortServiceRequest_UpdateShortServiceReqData(&ShortService_Request);

			UPD_UCL_State_Machine = UPD_UCL_STATE_SHORT_SERVICE;

			break;
		}
		case UPD_UCL_STATE_RX_CONFIRM:
		{
			UPD_UCL_State_Machine = UPD_UCL_STATE_IDLE;

			if(UPD_UCL_GP_Response == E_OK)
			{
				RetVal = E_OK;

				*ErrorCode = 0x0;
			}
			else
			{
				RetVal = E_NOT_OK;

				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}

			break;
		}
		case UPD_UCL_STATE_SHORT_SERVICE:
		{
			break;
		}
		default:
		{
			UPD_UCL_State_Machine = UPD_UCL_STATE_FAILED;

			RetVal = E_NOT_OK;

			break;
		}
	}

    return RetVal;
}

Std_ReturnType 	UCL_IInstallation_Verify(uint8 opStatus, uint8 Rid_action, uint32 ReqLength, uint8* Buff,uint32* RespLength, uint8 *ErrorCode)
{
	Std_ReturnType RetVal = DCM_E_PENDING;

	if(Buff != NULL)
	{
		switch(UPD_UCL_State_Machine)
		{
			case UPD_UCL_STATE_IDLE:
			{
				ShortService_Request.sid = UDS_SERVICE_RID_VERIFY;

				ShortService_Request.memoryCmd = 0u;

				ShortService_Request.length = SIZE_OF_SIGNATURE;

				memset(ShortService_Request.data, 0, sizeof(ShortService_Request.data));

				memcpy(ShortService_Request.data, Buff, (LENGTH_OF_ADDRESS + LENGTH_OF_LENGTH));

				if(UPD_UCL_WriteToSharedMem(0u, (Buff + (LENGTH_OF_ADDRESS + LENGTH_OF_LENGTH)), SIZE_OF_SIGNATURE) == E_OK)
				{
					Rte_Send_CUpdateCdd_pp_SR_UpdateShortServiceRequest_UpdateShortServiceReqData(&ShortService_Request);

					UPD_UCL_State_Machine = UPD_UCL_STATE_SHORT_SERVICE;
				}
				else
				{
					*ErrorCode = NEGATIVE_RESPONSE_GIP;

					RetVal = E_NOT_OK;
				}

				break;
			}
			case UPD_UCL_STATE_RX_CONFIRM:
			{
				UPD_UCL_State_Machine = UPD_UCL_STATE_IDLE;

				if(UPD_UCL_GP_Response == E_OK)
				{
					RetVal = E_OK;
				}
				else
				{
					*ErrorCode = NEGATIVE_RESPONSE_GIP;

					RetVal = E_NOT_OK;
				}

				break;
			}
			case UPD_UCL_STATE_SHORT_SERVICE:
			{
				break;
			}
			default:
			{
				UPD_UCL_State_Machine = UPD_UCL_STATE_FAILED;

				*ErrorCode = NEGATIVE_RESPONSE_GIP;

				RetVal = E_NOT_OK;

				break;
			}
		}
	}
	else
	{
		*ErrorCode = NEGATIVE_RESPONSE_GIP;

		RetVal = E_NOT_OK;
	}

    return RetVal;
}

Std_ReturnType 	UCL_IInstallation_ProgSessionRequest(uint8* ErrorCode)
{
	Std_ReturnType RetVal = DCM_E_PENDING;

	*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;

	switch(UPD_UCL_State_Machine)
	{
		case UPD_UCL_STATE_IDLE:
		{
			UPD_UCL_State_Machine = UPD_UCL_STATE_SHORT_SERVICE;

			ShortService_Request.sid = UDS_SERVICE_PROGSESSION;

			Rte_Send_CUpdateCdd_pp_SR_UpdateShortServiceRequest_UpdateShortServiceReqData(&ShortService_Request);

			break;
		}
		case UPD_UCL_STATE_SHORT_SERVICE:
		{
			// Do nothing. Wait for response from GP.

			break;
		}
		case UPD_UCL_STATE_RX_CONFIRM:
		{
			// RX received from GP. Check for successful return and then trigger reset.

			if(UPD_UCL_GP_Response == E_OK)
			{
				*ErrorCode = 0x0;

				RetVal = E_OK;
			}
			else
			{
				*ErrorCode = NEGATIVE_RESPONSE_GIP;

				RetVal = E_NOT_OK;
			}

			UPD_UCL_State_Machine = UPD_UCL_STATE_IDLE;

			break;

		}
		default:
		{
			UPD_UCL_State_Machine = UPD_UCL_STATE_FAILED;

			*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;

			RetVal = E_NOT_OK;

			break;
		}
	}

	return RetVal;

}

Std_ReturnType 	UCL_IInstallation_ActivationRequest(uint8* ErrorCode)
{
	Std_ReturnType RetVal = DCM_E_PENDING;

	*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;

	switch(UPD_UCL_State_Machine)
	{
		case UPD_UCL_STATE_IDLE:
		{
			UPD_UCL_State_Machine = UPD_UCL_STATE_SHORT_SERVICE;

			ShortService_Request.sid = UDS_SERVICE_RID_ACTIVATE;

			Rte_Send_CUpdateCdd_pp_SR_UpdateShortServiceRequest_UpdateShortServiceReqData(&ShortService_Request);

			break;
		}
		case UPD_UCL_STATE_SHORT_SERVICE:
		{
			// Do nothing. Wait for response from GP.

			break;
		}
		case UPD_UCL_STATE_RX_CONFIRM:
		{
			UPD_UCL_State_Machine = UPD_UCL_STATE_IDLE;

			if(UPD_UCL_GP_Response == E_OK)
			{
				*ErrorCode = 0u;

				RetVal = E_OK;
			}
			else
			{
				*ErrorCode = NEGATIVE_RESPONSE_GIP;

				RetVal = E_NOT_OK;
			}

			break;
		}
		default:
		{
			UPD_UCL_State_Machine = UPD_UCL_STATE_FAILED;

			*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;

			RetVal = E_NOT_OK;

			break;
		}
	}

	return RetVal;
}

Std_ReturnType	UCL_IInstallation_ActivationCompleteRequest(uint8* ErrorCode)
{
	Std_ReturnType RetVal = DCM_E_PENDING;

	*ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;

	switch(UPD_UCL_State_Machine)
	{
		case UPD_UCL_STATE_IDLE:
		{
			UPD_UCL_State_Machine = UPD_UCL_STATE_SHORT_SERVICE;

			ShortService_Request.sid = UDS_SERVICE_RID_ACTIVATION_COMPLETE;

			Rte_Send_CUpdateCdd_pp_SR_UpdateShortServiceRequest_UpdateShortServiceReqData(&ShortService_Request);

			break;
		}
		case UPD_UCL_STATE_SHORT_SERVICE:
		{
			// Do nothing. Wait for response from GP.

			break;
		}
		case UPD_UCL_STATE_RX_CONFIRM:
		{
			UPD_UCL_State_Machine = UPD_UCL_STATE_IDLE;

			if(UPD_UCL_GP_Response == E_OK)
			{
				*ErrorCode = 0u;

				RetVal = E_OK;
			}
			else
			{
				*ErrorCode = NEGATIVE_RESPONSE_GIP;

				RetVal = E_NOT_OK;
			}

			break;
		}
		default:
		{
			UPD_UCL_State_Machine = UPD_UCL_STATE_FAILED;

			*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;

			RetVal = E_NOT_OK;

			break;
		}
	}

	return RetVal;
}
//---------------------------------------------------------------------------------------------------------------------
/// @name   :App_UclMsgReceivedFunc()
/// @brief  :UCL Message Receive Callback
/// @arg    :void
/// @return :void
//---------------------------------------------------------------------------------------------------------------------
void CUpdateCdd_OnDre_UpdateResponse(void)
{
	Rte_Receive_rp_SR_UpdateShortServiceResponse_UpdateShortServiceRespData(&ShortService_Response);

	UPD_UCL_GP_Response = ShortService_Response.responseCode;

	if(UPD_UCL_State_Machine == UPD_UCL_STATE_SHORT_SERVICE)
	{
		switch(ShortService_Response.sid)
		{
			case UDS_SERVICE_PROGSESSION:
			case UDS_SERVICE_RID_ERASE:
			case UDS_SERVICE_STARTDOWNLOAD:
			case UDS_SERVICE_TRANSFEREXIT:
			case UDS_SERVICE_RID_ACTIVATE:
			{
				UPD_UCL_State_Machine = UPD_UCL_STATE_RX_CONFIRM;

				break;
			}
			case UDS_SERVICE_RID_VERIFY:
			{
				UPD_UCL_State_Machine = UPD_UCL_STATE_RX_CONFIRM;

				UPD_UCL_SharedMemoryObj[0u].AvailableSize = MAX_SIZE_OF_SHARED_MEMORY;

				UPD_UCL_SharedMemoryObj[0u].BankFull = 0u;

				break;
			}
			case UDS_SERVICE_TRANSFERDATA:
			{
				UPD_UCL_State_Machine = UPD_UCL_STATE_IDLE;

				UPD_UCL_SharedMemoryObj[UPD_UCL_SharedMem_ID_to_GP].AvailableSize = MAX_SIZE_OF_SHARED_MEMORY;

				UPD_UCL_SharedMemoryObj[UPD_UCL_SharedMem_ID_to_GP].BankFull = 0u;

				break;
			}
			default:
				break;
		}
	}
	else
	{
		// Unexpected state ;

		UPD_UCL_State_Machine = UPD_UCL_STATE_FAILED;
	}
}

Std_ReturnType UPD_UCL_WriteToSharedMem(uint8 SharedMem_Index,const uint8* MemoryData,uint32 MemorySize)
{
	Std_ReturnType RetVal = E_NOT_OK;

	if(UPD_UCL_SharedMemoryObj[SharedMem_Index].AvailableSize  >= MemorySize)
	{
		memcpy((UPD_UCL_SharedMemoryObj[SharedMem_Index].MemoryPtr + (MAX_SIZE_OF_SHARED_MEMORY - UPD_UCL_SharedMemoryObj[SharedMem_Index].AvailableSize)), MemoryData, MemorySize);

		UPD_UCL_SharedMemoryObj[SharedMem_Index].AvailableSize -= MemorySize;

		UPD_UCL_TransferCompleteSize += MemorySize;

		RetVal = E_OK;
	}
	else
	{
		// Bank is full or it can't write more data. So trigger the transfer to GP.

		UPD_UCL_SharedMemoryObj[SharedMem_Index].BankFull = UPD_UCL_BANK_FULL;
	}

	return RetVal;
}

void CUpdateCdd_Impl_MainFunction(void)
{
	// Main function for below jobs
	// 1. Trigger transfer for shared memory.
	// 2. UCL retry mechanism & fault handling - Implementation Pending.

	uint8 i;

	if(UPD_UCL_State_Machine == UPD_UCL_STATE_IDLE)
	{
		for(i=0; i<MAX_NO_OF_SHARED_MEMORY_BUFFER; i++)
		{
			if(UPD_UCL_SharedMemoryObj[i].BankFull == UPD_UCL_BANK_FULL)
			{
				UPD_UCL_State_Machine = UPD_UCL_STATE_TRANSFER;

				UPD_UCL_SharedMem_ID_to_GP = i;

				break;
			}
		}

		if((UPD_UCL_TransferCompleteSize == UPD_UCL_TotalBlockSize)&&(UPD_UCL_TotalBlockSize != 0u)&&(UPD_UCL_State_Machine != UPD_UCL_STATE_TRANSFER))
		{
			UPD_UCL_TransferCompleteSize = 0u;

			UPD_UCL_State_Machine = UPD_UCL_STATE_TRANSFER;

			UPD_UCL_SharedMem_ID_to_GP = UPD_UCL_SharedMem_Index;

		}

		if(UPD_UCL_State_Machine == UPD_UCL_STATE_TRANSFER)
		{

			ShortService_Request.sid = UDS_SERVICE_TRANSFERDATA;

			ShortService_Request.length = (MAX_SIZE_OF_SHARED_MEMORY - (UPD_UCL_SharedMemoryObj[UPD_UCL_SharedMem_ID_to_GP].AvailableSize)); 		// Length of data to be transfered.

			ShortService_Request.memoryCmd = UPD_UCL_SharedMem_ID_to_GP;

			Rte_Send_CUpdateCdd_pp_SR_UpdateShortServiceRequest_UpdateShortServiceReqData(&ShortService_Request);

			UPD_UCL_State_Machine = UPD_UCL_STATE_SHORT_SERVICE;
		}
	}
}

