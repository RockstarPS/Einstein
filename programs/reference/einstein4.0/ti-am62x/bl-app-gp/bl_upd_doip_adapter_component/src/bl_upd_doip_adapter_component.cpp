//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2022] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
//
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.2.1
// Date: Wed Apr 29 19:27:11 IST 2026
// User: SRAI3
// System: GIP
// Configuration: Platform_Recovery
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.9
//
//---------------------------------------------------------------------------------------------------------------------
#include "bl_upd_doip_adapter_component.h"
#include "UpdateHandler.hpp"

/// Start of user code : Header user code for file bl_upd_doip_adapter_component.cpp
LOG_IMPORT_CONTEXT(BlAppGpLogContext);

UpdateHandler ObjDoIPUpdateHandler;
DoIPDownloadRequest DoIPRecvdMsg;
bool DoIPMsgRxFlag = false;
/// End of user code


bool BlUpdDoipAdapterComponent::onInit()
{
	bool ret = Component::onInit();;

/// Start of user code : User code for function onInit in file bl_upd_doip_adapter_component.cpp

	(void)registerTask([=](){ periodicTask(); }, 10);

/// End of user code

	return ret;
}

bool BlUpdDoipAdapterComponent::onExit()
{
	bool ret = Component::onExit();

/// Start of user code : User code for function onExit in file bl_upd_doip_adapter_component.cpp

/// End of user code

	return ret;
}

bool BlUpdDoipAdapterComponent::onStart()
{
	bool ret = Component::onStart();

/// Start of user code : User code for function onStart in file bl_upd_doip_adapter_component.cpp

/// End of user code

	return ret;
}

bool BlUpdDoipAdapterComponent::onStop()
{
	bool ret = Component::onStop();

/// Start of user code : User code for function onStop in file bl_upd_doip_adapter_component.cpp

/// End of user code

	return ret;
}

void BlUpdDoipAdapterComponent::worker()
{
/// Start of user code : User code for function worker in file bl_upd_doip_adapter_component.cpp

/// End of user code
}

void BlUpdDoipAdapterComponent::onReceiveDoIPDownloadRequest(DoIPDownloadRequest const  & msg)
{
/// Start of user code : User code for function onReceiveDoIPDownloadRequest in file bl_upd_doip_adapter_component.cpp

	LOGI(&BlAppGpLogContext,"\n Service Id = ",   	msg.serviceId);
	LOGI(&BlAppGpLogContext,"\n Address = " ,		msg.blkaddress);
	LOGI(&BlAppGpLogContext,"\n Block Length = ",	msg.blklength);
	LOGI(&BlAppGpLogContext,"\n Format ID = ",		msg.formatId);
	LOGI(&BlAppGpLogContext,"\n Data Length = ",	msg.dataLen);

	DoIPRecvdMsg = msg;

	DoIPMsgRxFlag = true;

/// End of user code
}

void BlUpdDoipAdapterComponent::periodicTask()
{
	DoIPTransferHandlingTask();
}

void BlUpdDoipAdapterComponent::DoIPTransferHandlingTask(void)
{
	uint8 status = E_NOT_OK;
	uint32 blkAddress;
	uint32 blkLength;
	uint8 *DataPtr;

	if(DoIPMsgRxFlag == true)
	{
		DoIPMsgRxFlag = false;
		
		printf("UDS Request %x received \n", DoIPRecvdMsg.serviceId);
		
		switch (DoIPRecvdMsg.serviceId)
		{
			case DoIP_ProgSession:
			{
				status = ObjDoIPUpdateHandler.ProgSession();

				DoIP_sendResponse(DoIPRecvdMsg.serviceId, status, 0x00, NULL);

				break;
			}
			case DoIP_Reset:
			{
				status = ObjDoIPUpdateHandler.Reset();

				DoIP_sendResponse(DoIPRecvdMsg.serviceId, status, 0x00, NULL);

				break;
			}
			case DoIP_eraseRoutine:
			{
				status = ObjDoIPUpdateHandler.EraseRoutine(DoIPRecvdMsg.blkaddress, DoIPRecvdMsg.blklength);

				DoIP_sendResponse(DoIPRecvdMsg.serviceId, status, 0x00, NULL);

				break;
			}
			case DoIP_downloadService:
			{
				printf("34 service request \n");

				status = ObjDoIPUpdateHandler.RequestDownload(DoIPRecvdMsg.blkaddress, DoIPRecvdMsg.blklength, DoIPRecvdMsg.CompEncId);

				DoIP_sendResponse(DoIPRecvdMsg.serviceId, status, 0x00, NULL);

				printf("34 service service response \n");

				break;
			}
			case DoIP_TransferService:
			{
				printf("Transfer Data Start\n");

				status = ObjDoIPUpdateHandler.TransferData(DoIPRecvdMsg.dataLen, DoIPRecvdMsg.data);

				DoIP_sendResponse(DoIPRecvdMsg.serviceId, status, 0x00, NULL);

				printf("Transfer Data Response\n");

				break;
		    }
			case DoIP_TransferExitService:
			{
				printf("Transfer Exit Request\n");

				status = ObjDoIPUpdateHandler.TransferExit();

				DoIP_sendResponse(DoIPRecvdMsg.serviceId, status, 0x00, NULL);

				printf("Transfer Exit Response\n");

				break;
		    }
			case DoIP_SelfCheck:
			{
				status = ObjDoIPUpdateHandler.SignatureVerification(DoIPRecvdMsg.blkaddress, DoIPRecvdMsg.blklength, DoIPRecvdMsg.data, DoIPRecvdMsg.dataLen);

				DoIP_sendResponse(DoIPRecvdMsg.serviceId, status, 0x00, NULL);

				break;
			}
			case DoIP_Activation:
			case DoIP_Rollback:
			{
				status = ObjDoIPUpdateHandler.Activation();

				DoIP_sendResponse(DoIPRecvdMsg.serviceId, status, 0x00, NULL);

				break;
			}
			case DoIP_Partitionsync:
			{
				boolean SyncStatus = false;

				status = ObjDoIPUpdateHandler.PrimaryPartitionSynchronization(&SyncStatus);

				DoIP_sendResponse(DoIPRecvdMsg.serviceId, status, 0x00, NULL);

				break;
			}
			default:
			{
				break;
			}
		}
	}
}

void BlUpdDoipAdapterComponent::DoIP_sendResponse(uint32 Sid, uint8 ErrorCode, uint32 RespLength, uint8* data )
{
	DoIPDownloadResponse RespDoIPMsg;

	RespDoIPMsg.serviceId = Sid;
	RespDoIPMsg.result = ErrorCode;
	RespDoIPMsg.dataLen = RespLength;

	if(ErrorCode != E_OK)
	{
		printf("\n Negative response from GP\n ");
	}

	if(data != NULL)
	{
		for (uint16 i = 0; i < RespLength; i++)
		{
			RespDoIPMsg.data[i] = data[i];
		}
	}
	
	DK_RTE_Send_DoIPDownloadResponse(RespDoIPMsg);
	
	printf("DoIP Response sent\n");
}

/// Start of user code : Footer user code for file bl_upd_doip_adapter_component.cpp

/// End of user code

