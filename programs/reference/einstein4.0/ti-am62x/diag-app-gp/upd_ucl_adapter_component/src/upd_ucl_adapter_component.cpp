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
// Date: Thu Apr 17 12:47:36 IST 2025
// User: GSOUNDAR
// System: GIP
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.4
//
//---------------------------------------------------------------------------------------------------------------------
#include "upd_ucl_adapter_component.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/ioctl.h>
#include <mtd/mtd-user.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

/// Start of user code : Header user code for file upd_ucl_adapter_component.cpp

#include "SharedMem.h"
#include "UpdateHandler.hpp"

CSharedMemCtrl ObjSharedMemory;
UpdateHandler ObjUpdateHandler;

UpdateShortServiceReq RecvdMsg;
bool UclMsgRxFlag = false;

#define INDEX_OF_LENGTH 	(4u)

LOG_DECLARE_CONTEXT(BlAppGpLogContext);

/// End of user code
UpdateShortServiceResp response;

bool UpdUclAdapterComponent::onInit()
{
	bool ret = Component::onInit();

/// Start of user code : User code for function onInit in file upd_ucl_adapter_component.cpp
	LOG_REGISTER_CONTEXT(BlAppGpLogContext, "BL INSTALLER APPC", "BL APP GP INSTALLER", DLT_LOG_INFO);

	LOGI(&BlAppGpLogContext, "Starting bl-app-gp...");

	ObjSharedMemory.CreateSharedMemInstance();

	(void)registerTask([=]()
					   { periodicTask(); }, 10);

	/// End of user code

	return ret;
}

bool UpdUclAdapterComponent::onExit()
{
	bool ret = Component::onExit();

/// Start of user code : User code for function onExit in file upd_ucl_adapter_component.cpp

	ObjSharedMemory.ReleaseSharedMemInstance();

	LOG_UNREGISTER_CONTEXT(BlAppGpLogContext);

/// End of user code

	return ret;
}

bool UpdUclAdapterComponent::onStart()
{
	bool ret = Component::onStart();

/// Start of user code : User code for function onStart in file upd_ucl_adapter_component.cpp

/// End of user code

	return ret;
}

bool UpdUclAdapterComponent::onStop()
{
	bool ret = Component::onStop();

/// Start of user code : User code for function onStop in file upd_ucl_adapter_component.cpp

/// End of user code

	return ret;
}

void UpdUclAdapterComponent::worker()
{
/// Start of user code : User code for function worker in file upd_ucl_adapter_component.cpp

/// End of user code
}

void UpdUclAdapterComponent::onReceiveUpdateShortServiceReq(UpdateShortServiceReq const  & msg)
{
/// Start of user code : User code for function onReceiveUpdateShortServiceReq in file upd_ucl_adapter_component.cpp
	uint8 *DataPtr;

	LOGI(&BlAppGpLogContext,"\n Msg Id = ",   	msg.msgId);
	LOGI(&BlAppGpLogContext,"\n size = " ,		msg.msgSize);
	LOGI(&BlAppGpLogContext,"\n Memory Type = ",msg.memoryType);
	LOGI(&BlAppGpLogContext,"\n Memory Cmd = ",	msg.memoryCmd);
	LOGI(&BlAppGpLogContext,"\n SID = ",		msg.sid);
	LOGI(&BlAppGpLogContext,"\n Length = ", 	msg.length);

	RecvdMsg = msg;

	UclMsgRxFlag = true;
/// End of user code
}

void UpdUclAdapterComponent::onReceiveUpdateLongServiceReq(UpdateLongServiceReq const  & msg)
{
/// Start of user code : User code for function onReceiveUpdateLongServiceReq in file upd_ucl_adapter_component.cpp

/// End of user code
}


void UpdUclAdapterComponent::periodicTask()
{

/// Start of user code : Footer user code for file upd_ucl_adapter_component.cpp
	UclTransferHandlingTask();
}
void UpdUclAdapterComponent::UclTransferHandlingTask(void)
{
	uint8 status = E_NOT_OK;
	uint32 blkAddress;
	uint32 blkLength;
	uint8 *DataPtr;

	if(UclMsgRxFlag == true)
	{
		UclMsgRxFlag = false;
		printf("UDS request src %x received \n", RecvdMsg.sid);
		switch (RecvdMsg.sid)
		{
			case Ucl_ProgSession:
			{
				status = ObjUpdateHandler.ProgSession();

				ucl_sendResponse(RecvdMsg.sid, status, 0x00, NULL);

				break;
			}
			case Ucl_Reset:
			{
				status = ObjUpdateHandler.Reset();

				ucl_sendResponse(RecvdMsg.sid, status, 0x00, NULL);

				break;
			}
			case Ucl_eraseRoutine:
			{
				arrayTo32BitValue(RecvdMsg.data, blkAddress);

				arrayTo32BitValue((RecvdMsg.data + INDEX_OF_LENGTH), blkLength);

				status = ObjUpdateHandler.EraseRoutine(blkAddress, blkLength);

				ucl_sendResponse(RecvdMsg.sid, status, 0x00, NULL);

				break;
			}
			case Ucl_downloadService:
			{
				printf("34 service request \n");

				arrayTo32BitValue(RecvdMsg.data, blkAddress);

				arrayTo32BitValue((RecvdMsg.data + INDEX_OF_LENGTH), blkLength);

				status = ObjUpdateHandler.RequestDownload(blkAddress, blkLength, RecvdMsg.memoryCmd);

				ucl_sendResponse(RecvdMsg.sid, status, 0x00, NULL);

				printf("34 service service response \n");

				break;
			}
			case Ucl_TransferService:
			{
				printf("Transfer Data Start\n");

				DataPtr = ObjSharedMemory.GetShmMemDataPtr(RecvdMsg.memoryCmd, RecvdMsg.length, (0u));

				status = ObjUpdateHandler.TransferData(RecvdMsg.length, DataPtr);

				ucl_sendResponse(RecvdMsg.sid, status, 0x00, NULL);

				printf("Transfer Data Response\n");

				break;
		    }
			case ucl_TransferExitService:
			{
				printf("Transfer Exit Request\n");

				status = ObjUpdateHandler.TransferExit();

				ucl_sendResponse(RecvdMsg.sid, status, 0x00, NULL);

				printf("Transfer Exit Response\n");

				break;
		    }
			case ucl_SelfCheck:
			{
				arrayTo32BitValue(RecvdMsg.data, blkAddress);

				arrayTo32BitValue((RecvdMsg.data + INDEX_OF_LENGTH), blkLength);

				DataPtr = ObjSharedMemory.GetShmMemDataPtr(RecvdMsg.memoryCmd, RecvdMsg.length, (0u));

				status = ObjUpdateHandler.SignatureVerification(blkAddress, blkLength, DataPtr, RecvdMsg.length);

				ucl_sendResponse(RecvdMsg.sid, status, 0x00, NULL);

				break;
			}
			case ucl_Activation:
			{
				status = ObjUpdateHandler.Activation();

				ucl_sendResponse(RecvdMsg.sid, status, 0x00, NULL);

				break;
			}
			case ucl_Partitionsync:
			{
				boolean SyncStatus = false;

				status = ObjUpdateHandler.PrimaryPartitionSynchronization(&SyncStatus);

				ucl_sendResponse(RecvdMsg.sid, status, 0x00, NULL);

				break;
			}
			default:
			{
				break;
			}
		}
	}
}

void UpdUclAdapterComponent::ucl_sendResponse(uint8 Sid, uint8 ErrorCode, uint16 RespLength, uint8* data )
{
	UpdateShortServiceResp RespUclMsg;

	RespUclMsg.base.compId = 0x00;
	RespUclMsg.base.msgCnt = 0x01;
	RespUclMsg.msgId = 0x0102;
	RespUclMsg.msgSize = 0x0004;
	RespUclMsg.sid = Sid;
	RespUclMsg.length = RespLength;
	RespUclMsg.responseCode = ErrorCode;
	RespUclMsg.NRC = ErrorCode;

	if(ErrorCode != E_OK)
	{
		printf("\n Negative response from GP\n ");
	}

	RespUclMsg.data[0] = 0x09;
	RespUclMsg.data[1] = 0x0a;
	RespUclMsg.data[2] = 0x0b;

	if(data != NULL)
	{
		for (uint16 i = 0; i < RespLength; i++)
		{
			RespUclMsg.data[i] = data[i];
		}
	}
	DK_RTE_Send_UpdateShortServiceResp(RespUclMsg);
	printf("UCL Response sent to VIP\n");

}


uint8 UpdUclAdapterComponent::arrayTo32BitValue(const uint8_t* arr, uint32 &value)
{
    // Ensure the array has at least 4 bytes
    if (arr == nullptr) {
        return 0xFF;
    }

    // Combine bytes into a 32-bit value (little-endian)
    value = 0;
    value |= (static_cast<uint32_t>(arr[0])) << 0;
    value |= (static_cast<uint32_t>(arr[1])) << 8;
    value |= (static_cast<uint32_t>(arr[2])) << 16;
    value |= (static_cast<uint32_t>(arr[3])) << 24;

    return 0x0;
}

/// End of user code

