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
#include <cstring>
#include "UclVmfProxy.hpp"
#include "UclVmfConfig.hpp"
#include "UclALDebug.h"
#include "UclILSched.h"
#include "UclSys.h"
#include "UclALOs.h"
#include "Ucl_Version.h"

#define VMF_MSG_OFFSET_BYTES (2U)

CUclVmfProxy::CUclVmfProxy()
{
    bRequestExit = false;
}

CUclVmfProxy::~CUclVmfProxy()
{
}

Ucl_ReturnType CUclVmfProxy::start()
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    const uint8 *GroupList = nullptr;
    uint16 NumGroups = 0U;
    //std::vector<uint8> GroupsVector;
    std::thread txThread;
    std::thread rxThread;
    std::thread dispatchThread;

    std::cout << "ucl_proxy_vmf: UCL VERSION : " << UCL_VERSION << std::endl;

    // Initialize the VMF System
    (void) CUclVmfConfig::getVmfGroupList( &GroupList, NumGroups );

    if ((nullptr != GroupList) && (0 < NumGroups))
    {
        Ret = vmfIf.connectToVmf( GroupList, NumGroups );
    }
    else
    {
        LOGE(0, "UclProxyVmf", "GetVmfGroupList Failed %d", NumGroups);
    }
    
    if (UCL_E_OK == Ret)
    {	
		// Initialize the UCL System
        Ret = UclSys_Initialize( 0U );
		
		if (UCL_E_OK == Ret)
		{
			Ret = UclALOs_MutexCreate( 0, &VmfUclMsgQMutexId);
		}
			
        if(UCL_E_OK == Ret)
		{
			txThread = std::thread( &CUclVmfProxy::vmfRxThread, this );
			rxThread = std::thread( &CUclVmfProxy::vmfTxThread, this );
			dispatchThread = std::thread( &CUclVmfProxy::uclDispatchThread, this );
		}       
    }

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclProxyVmf", "%s", "UclSys_Initialize Success");
        txThread.detach();
        rxThread.detach();
        dispatchThread.detach();
    }
    else
    {
        LOGE(0, "UclProxyVmf", "UclSys_Initialize Failed %ld", Ret);
    }
	
    return Ret;
}

Ucl_ReturnType CUclVmfProxy::stop()
{
    Ucl_ReturnType Ret;
    bRequestExit = true;
	const uint8 *GroupList = nullptr;
    uint16 NumGroups = 0U;
	
	(void) CUclVmfConfig::getVmfGroupList( &GroupList, NumGroups );

    if ((nullptr != GroupList) && (0U < NumGroups))
    {
        Ret = vmfIf.disConnectFromVmf( GroupList, NumGroups );
    }
    else
    {
        LOGE(0, "UclProxyVmf_Stop", "GetVmfGroupList Failed %d", NumGroups);
    }
	
	Ret = UclALOs_MutexDestroy( 0U, VmfUclMsgQMutexId);
    Ret = UclSys_Shutdown( 0U );
    return Ret;
}

void CUclVmfProxy::vmfRxThread()
{
    Ucl_ReturnType Ret;

    LOGI(0, "UclProxyVmf", "%s", "VmfRxThread Started");

    while (!bRequestExit)
    {
        // Get a buffer from the pool
        CUclVmfInterface::SVmfMsg *const VmfMsg = vmfMsgBufferPool.GetBuffer();
        if (nullptr != VmfMsg)
        {
            Ret = vmfIf.receiveFromVmf( VmfMsg );
            if (UCL_E_OK == Ret)
            {
                // Push the message to Receive Queue
                rxQueue.push( VmfMsg );
                // Let the dispatcher process the message
                std::this_thread::yield();
            }
            else
            {
                LOGE(0, "UclProxyVmf", "ReceiveFromVmf Failed %ld", Ret);
            }
        }
        else
        {
            LOGE(0, "UclProxyVmf", "%s", "VmfRxThread no buffer available");
        }
    }
    LOGI(0, "UclProxyVmf", "%s", "VmfRxThread Exited");
}

void CUclVmfProxy::vmfTxThread()
{
    CUclVmfInterface::SVmfMsg *VmfMsg = nullptr;
    Ucl_ReturnType Ret;

    LOGI(0, "UclProxyVmf", "%s", "VmfTxThread Started");

    while (!bRequestExit)
    {
        //int i;

        txQueue.waitAndPop( VmfMsg );

        //LOGI(0, "UclProxyVmf", "SendToVmf Gx:%d Ex:%d Size:%d", VmfMsg->Gx, VmfMsg->Ex, VmfMsg->PayloadSize);
        //printf("%02x %02x", VmfMsg->Gx, VmfMsg->Ex);
        //for(i = 0; i < VmfMsg->PayloadSize; i++)
        //{
        //    printf(" %02x", VmfMsg->Payload[i]);
        //}
        //printf("\n");

        if (nullptr != VmfMsg)
        {
            Ret = vmfIf.sendToVmf( VmfMsg );

            if (UCL_E_OK != Ret)
            {
                LOGI(0, "UclProxyVmf", "sendToVmf Failed %ld", Ret);
            }

            vmfMsgBufferPool.PutBuffer( &VmfMsg );

            VmfMsg = nullptr;
        }
    }

    LOGI(0, "UclProxyVmf", "%s", "VmfTxThread Exited");
}

void CUclVmfProxy::uclDispatchThread()
{
    CUclVmfInterface::SVmfMsg *VmfMsg;
    std::pair<uint8, uint8> IdxDux; //Msg Index, DU Index
    Ucl_ReturnType Ret;

    LOGI(0, "UclProxyVmf", "%s", "UclDispatchThread Started");

    while (!bRequestExit)
    {
        rxQueue.waitAndPop( VmfMsg );

        Ret = CUclVmfConfig::lookup( std::make_pair( VmfMsg->Gx, VmfMsg->Ex ), IdxDux );

        if (UCL_E_OK == Ret)
        {
            //LOGI(0, "UclProxyVmf", "UclDispatchThread %d %d %d %d %d", VmfMsg->Gx, VmfMsg->Ex, IdxDux.first, IdxDux.second, VmfMsg->PayloadSize);
            (void)UclGen_NotifyNewMessageReceived( IdxDux.first, IdxDux.second,
                            &(VmfMsg->Payload[VMF_MSG_OFFSET_BYTES]), (VmfMsg->PayloadSize - VMF_MSG_OFFSET_BYTES));
        }
        else
        {
            LOGE(0, "UclProxyVmf", "UclDispatchThread Unknown GxEx Received %d %d", VmfMsg->Gx, VmfMsg->Ex);
        }
        vmfMsgBufferPool.PutBuffer( &VmfMsg );
    }

    LOGI(0, "UclProxyVmf", "%s", "UclDispatchThread Exited");
}

Ucl_ReturnType CUclVmfProxy::addVmfMsgToTxQueue( const uint8 Gx, const uint8 Ex, const uint8 *const Payload, const uint16 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    //LOGI(0, "UclProxyVmf", "AddVmfMsgToTxQueue Gx:%d Ex:%d Size:%d", Gx, Ex, Size);

    if ((Size + VMF_MSG_OFFSET_BYTES)> MAX_VMF_DATA_LEN)
    {
        LOGE(0, "UclProxyVmf", "AddVmfMsgToTxQueue Size Error Gx:%d Ex:%d Size:%d", Gx, Ex, Size);
    }
    else
    {
        // Get a buffer from the pool
        CUclVmfInterface::SVmfMsg *const VmfMsg = vmfMsgBufferPool.GetBuffer();
        if (nullptr != VmfMsg)
        {
            // Populate Message
            VmfMsg->Gx = Gx;
            VmfMsg->Ex = Ex;
            VmfMsg->Payload[0U] = 0U;
            VmfMsg->Payload[1U] = 0U;
            (void)std::memcpy( &(VmfMsg->Payload[VMF_MSG_OFFSET_BYTES]), Payload, static_cast<uint64>(Size) );
            VmfMsg->PayloadSize = (Size + VMF_MSG_OFFSET_BYTES);
            // Push the message to Transmit Queue
            txQueue.push( VmfMsg );
            // Let the tx thread process the message
			//std::this_thread::yield(); //This is removed because yielding thread after 
										// Pushing every DU results is more time to process the
										//received Message
            Ret = UCL_E_OK;
        }
        else
        {
            LOGE(0, "UclProxyVmf", "AddVmfMsgToTxQueue no buffer available Gx:%d Ex:%d Size:%d", Gx, Ex, Size);
        }
    }

    return Ret;
}

extern "C" uint8 UclVmfProxy_AddVmfMsgToTxQueue( const uint8 Gx, const uint8 Ex, const uint8 *const pPayload, const uint16 Size )
{
    uint8 Ret = FALSE;

    if (UCL_E_OK == CUclVmfProxy::getInstance().addVmfMsgToTxQueue( Gx, Ex, pPayload, Size ))
    {
        Ret = TRUE;
    }
    return Ret;
}
