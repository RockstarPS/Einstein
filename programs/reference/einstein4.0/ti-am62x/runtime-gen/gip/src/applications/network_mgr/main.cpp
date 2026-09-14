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
// Date: Fri Jul 17 16:58:23 IST 2026
// User: GSOUNDAR
// System: GIP
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.10
//
//---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <csignal>
#include "dk_runtime_thread_pool.h"
#include "dk_runtime_msgcmn.h"
#include "network_mgr.h"
#include "network_manager_component.h"

LOG_DECLARE_CONTEXT ( gRTELogContext );

using namespace dk::runtime::core;
using namespace dk::srvc::platform;

//Forward declare message maps for the Components
extern std::map<mid_t, func_t> oNetworkManagerComponentMessageMap;

//Instantiate Software Components
NetworkManagerComponent oNetworkManagerComponent(&oNetworkManagerComponentMessageMap, COMPID_ONETWORKMANAGERCOMPONENT_STR);

//Define Messages
static const uint16_t oNetworkManagerComponentMessageArraySize = 5U;
const MsgCmn oNetworkManagerComponentMessageArray[oNetworkManagerComponentMessageArraySize] =
{
    {
        DK_MSG_NETWORKMODIFYFIREWALLSTATUS,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            NetworkModifyFirewallStatus msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.networkFirewallStatus);
            oNetworkManagerComponent.onReceiveNetworkModifyFirewallStatus(msg);
        }
    },
    {
        DK_MSG_NETWORKMODIFYLINKSTATUS,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            NetworkModifyLinkStatus msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.interfaceRequestType);
            ( void ) msgDes.deserialize(msg.interfaceNameLength);
            for (uint16_t i0 = 0U; i0 < 256U; i0++)
            {
                ( void ) msgDes.deserialize(msg.interfaceName[i0]);
            }
            oNetworkManagerComponent.onReceiveNetworkModifyLinkStatus(msg);
        }
    },
    {
        DK_MSG_NETWORKMODIFYVLANINTERFACE,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            NetworkModifyVlanInterface msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.requestType);
            ( void ) msgDes.deserialize(msg.vlanNameLength);
            for (uint16_t i0 = 0U; i0 < 256U; i0++)
            {
                ( void ) msgDes.deserialize(msg.vlanName[i0]);
            }
            ( void ) msgDes.deserialize(msg.vlanTag);
            ( void ) msgDes.deserialize(msg.interfaceNameLength);
            for (uint16_t i0 = 0U; i0 < 256U; i0++)
            {
                ( void ) msgDes.deserialize(msg.interfaceName[i0]);
            }
            ( void ) msgDes.deserialize(msg.vlanPriority);
            oNetworkManagerComponent.onReceiveNetworkModifyVlanInterface(msg);
        }
    },
    {
        DK_MSG_NETWORKMODIFYINTERFACE,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            NetworkModifyInterface msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.requestType);
            ( void ) msgDes.deserialize(msg.interfaceNameLength);
            for (uint16_t i0 = 0U; i0 < 256U; i0++)
            {
                ( void ) msgDes.deserialize(msg.interfaceName[i0]);
            }
            ( void ) msgDes.deserialize(msg.linkStatus);
            ( void ) msgDes.deserialize(msg.ipAddressLength);
            for (uint16_t i0 = 0U; i0 < 256U; i0++)
            {
                ( void ) msgDes.deserialize(msg.ipAddress[i0]);
            }
            ( void ) msgDes.deserialize(msg.netMaskLength);
            for (uint16_t i0 = 0U; i0 < 256U; i0++)
            {
                ( void ) msgDes.deserialize(msg.netMask[i0]);
            }
            ( void ) msgDes.deserialize(msg.broadcastAddressLength);
            for (uint16_t i0 = 0U; i0 < 256U; i0++)
            {
                ( void ) msgDes.deserialize(msg.broadcastAddress[i0]);
            }
            oNetworkManagerComponent.onReceiveNetworkModifyInterface(msg);
        }
    },
    {
        DK_MSG_ENETREGREQ,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            EnetRegReq msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.cmd);
            ( void ) msgDes.deserialize(msg.mode);
            ( void ) msgDes.deserialize(msg.dataLen);
            for (uint16_t i0 = 0U; i0 < 32U; i0++)
            {
                ( void ) msgDes.deserialize(msg.data[i0]);
            }
            oNetworkManagerComponent.onReceiveEnetRegReq(msg);
        }
    }
};

//Define Message Map for Components
std::map<mid_t, func_t> oNetworkManagerComponentMessageMap = createMap(oNetworkManagerComponentMessageArraySize, oNetworkManagerComponentMessageArray);

//Instantiate Containter
Container NetworkMgrCon(&oNetworkManagerComponent);

//Instantiate Application
NetworkMgr gApp("NetworkMgr", &NetworkMgrCon);

//Instantiate Threads
#define PTH_BODY
#include "network_mgr_threads.h"
#undef PTH_BODY

void signalHandler(const int32_t signum)
{
    std::cout << "Interrupt signal (" << signum << ") received.\n";

    // cleanup and close up stuff here
    // terminate program
    ( void ) gApp.stop();

    std::exit(signum);
}

/// Start of user code : User code for file main.cpp

/// End of user code

int main()
{
    int32_t l_gApp_ret_S32;
    try
    {
        if (SIG_ERR == std::signal(SIGINT, &signalHandler))
        {
            std::cout << "Failed to create signal handler";
        }

        /// Start of user code : User code for function main in file main.cpp
        #ifdef __QNX__
         LOG_REGISTER_APP_SLOG2("NMGR", "Network Mgr Application");
         LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO );
        #else
         LOG_REGISTER_APP_DLT("NMGR", "Network Mgr Application");
         LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO );
        #endif
        /// End of user code

        // Register Threads
#define PTH_REG
#include "network_mgr_threads.h"
#undef PTH_REG

        l_gApp_ret_S32 = gApp.run();
        LOG_UNREGISTER_CONTEXT ( gRTELogContext );
    }
    catch (...)
    {
        l_gApp_ret_S32 = -1;
        // Handle the exceptions.
    }

    return l_gApp_ret_S32;
}
