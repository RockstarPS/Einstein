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
// Date: Wed Sep 17 12:31:01 IST 2025
// User: SSRINI28
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
#include "display_mgr.h"
#include "display_manager_component.h"

LOG_DECLARE_CONTEXT ( gRTELogContext );

using namespace dk::runtime::core;

//Forward declare message maps for the Components
extern std::map<mid_t, func_t> oDisplayManagerComponentMessageMap;

//Instantiate Software Components
DisplayManagerComponent oDisplayManagerComponent(&oDisplayManagerComponentMessageMap, COMPID_ODISPLAYMANAGERCOMPONENT_STR);

//Define Messages
static const uint16_t oDisplayManagerComponentMessageArraySize = 3U;
const MsgCmn oDisplayManagerComponentMessageArray[oDisplayManagerComponentMessageArraySize] =
{
    {
        DK_MSG_DISPLAYSETPOWER,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            DisplaySetPower msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.displayId);
            ( void ) msgDes.deserialize(msg.state);
            oDisplayManagerComponent.onReceiveDisplaySetPower(msg);
        }
    },
    {
        DK_MSG_DISPLAYGETSTATE,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            DisplayGetState msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.displayId);
            oDisplayManagerComponent.onReceiveDisplayGetState(msg);
        }
    },
    {
        DK_MSG_POWERSYSTEMSTATE,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            PowerSystemState msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.domainId);
            ( void ) msgDes.deserialize(msg.state);
            oDisplayManagerComponent.onReceivePowerSystemState(msg);
        }
    }
};

//Define Message Map for Components
std::map<mid_t, func_t> oDisplayManagerComponentMessageMap = createMap(oDisplayManagerComponentMessageArraySize, oDisplayManagerComponentMessageArray);

//Instantiate Containter
Container DisplayMgrCon(&oDisplayManagerComponent);

//Instantiate Application
DisplayMgr gApp("DisplayMgr", &DisplayMgrCon);

//Instantiate Threads
#define PTH_BODY
#include "display_mgr_threads.h"
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
         LOG_REGISTER_APP_SLOG2("DMGR", "Display Manager");
         LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO );
        #else
         LOG_REGISTER_APP_DLT("DMGR", "Display Manager");
         LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO );
        #endif
        /// End of user code

        // Register Threads
#define PTH_REG
#include "display_mgr_threads.h"
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
