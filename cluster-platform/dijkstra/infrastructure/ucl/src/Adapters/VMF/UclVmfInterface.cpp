///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///
///---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <cstring>
#include<thread>
#include "UclVmfInterface.hpp"
#include "UclALDebug.h"

CUclVmfInterface::CUclVmfInterface()
{
    vmfConnId = -1;
}

CUclVmfInterface::~CUclVmfInterface()
{
    (void)nw_vmf_disconnect(vmfConnId);
}

Ucl_ReturnType CUclVmfInterface::connectToVmf(const uint8 *const groupsListPtr, const  uint16 numGroups)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    vmf_ret_t vmf_ret;
	VMF_VAR_BASIC_MSG_TYP(MAX_VMF_DATA_LEN)     msg;

	vmfConnId = nw_vmf_connect("UclVmfProxy", NULL, 0, 250, static_cast<uint16>(sizeof(msg)));

    if (vmfConnId < 0)
    {
        LOGE(0, "UclVmfInterface", "%s", "nw_vmf_connect Failed");
    }
    else
    {
        Ret = UCL_E_OK;
        if (nullptr != groupsListPtr)
        {
            vmf_ret = nw_vmf_register_msg_group(vmfConnId, numGroups, (unsigned8 *)groupsListPtr);
            if (vmf_ret < 0)
            {
                LOGE(0, "UclVmfInterface", "%s", "nw_vmf_register_msg_group Failed");
                Ret = UCL_E_NOK;
            }
			std::this_thread::sleep_for(std::chrono::milliseconds(100U));
        }
    }

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclVmfInterface", "%s", "ConnectToVmf Success");
    }
    else
    {
        LOGE(0, "UclVmfInterface", "%s", "ConnectToVmf Failed");
    }

    return Ret;
}

Ucl_ReturnType CUclVmfInterface::sendToVmf( const SVmfMsg *const vmfMsgPtr) const
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    vmf_ret_t vmf_result;
    VMF_VAR_BASIC_MSG_TYP(MAX_VMF_DATA_LEN)
    msg;

    VMF_BASIC_MSG_GROUP_ID(&msg) = vmfMsgPtr->Gx;
    VMF_BASIC_MSG_EVENT_ID(&msg) = vmfMsgPtr->Ex;
    VMF_BASIC_MSG_SET_FAR_DATA_LENGTH(&msg, vmfMsgPtr->PayloadSize);
    (void)std::memcpy(static_cast<unsigned8 *>(VMF_BASIC_MSG_PTR_TO_FAR_DATA(&msg)), vmfMsgPtr->Payload, static_cast<uint64>(vmfMsgPtr->PayloadSize)); //MISRA C++-2008 Rule 0-1-7, CID - 12253964

    vmf_result = nw_vmf_send_basic(vmfConnId, (vmf_basic_msg_t *)&msg);

    if (VMF_OK == vmf_result)
    {
        Ret = UCL_E_OK;
    }
    else
    {
        LOGE(0, "UclVmfInterface", "%s", "nw_vmf_send_basic Failed");
    }

    if (UCL_E_OK != Ret)
    {
        LOGE(0, "UclVmfInterface", "%s", "SendToVmf Failed");
    }

    return Ret;
}

Ucl_ReturnType CUclVmfInterface::receiveFromVmf(SVmfMsg * const vmfMsgPtr) const
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    sint16 RxLen;
    VMF_VAR_BASIC_MSG_TYP(MAX_VMF_DATA_LEN)
    msg = {0};

    RxLen = nw_vmf_receive(vmfConnId, (vmf_msg_t *)&msg, static_cast<uint16>(sizeof(msg)));

    if (0 < RxLen)
    {
        vmfMsgPtr->Gx = VMF_BASIC_MSG_GROUP_ID(&msg);
        vmfMsgPtr->Ex = VMF_BASIC_MSG_EVENT_ID(&msg);
        VMF_BASIC_MSG_RX_GET_FAR_DATA_LENGTH(vmfMsgPtr->PayloadSize, &msg);
        if (MAX_VMF_DATA_LEN > vmfMsgPtr->PayloadSize)
        {
            (void)std::memcpy(vmfMsgPtr->Payload, (unsigned8 *)msg.data.pl, static_cast<uint64>(vmfMsgPtr->PayloadSize)); //MISRA C++-2008 Rule 0-1-7, CID - 12247180
        }
        else
        {
            LOGE(0, "UclVmfInterface", "%s", "Larger data received, truncated");
            (void)std::memcpy(vmfMsgPtr->Payload, (unsigned8 *)msg.data.pl, MAX_VMF_DATA_LEN); //MISRA C++-2008 Rule 0-1-7, CID - 12247180
        }
        Ret = UCL_E_OK;
    }
	else
	{
		LOGE(0, "UclVmfInterface", "nw_vmf_receive Error %d", RxLen);
	}

    return Ret;
}

Ucl_ReturnType CUclVmfInterface::disConnectFromVmf(const uint8 *const groupsListPtr, const uint16 numGroups) const
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    vmf_ret_t vmf_ret;

	vmf_ret = nw_vmf_de_register_msg_group( vmfConnId, numGroups, (unsigned8 *)groupsListPtr );
	if (vmf_ret < 0)
	{
		LOGE(0, "UclVmfInterface", "nw_vmf_de_register_msg_group Failed %d ", vmf_ret);		
	}
	else
	{
		vmf_ret = nw_vmf_disconnect( vmfConnId );

		if (VMF_OK == vmf_ret)
		{
			LOGI(0, "UclVmfInterface", "%s", "nw_vmf_disconnect Success");
			Ret = UCL_E_OK;
		}
		else
		{
			LOGE(0, "UclVmfInterface", "nw_vmf_disconnect Failed %d", vmf_ret);
		}
	}
	
	return Ret;
}
