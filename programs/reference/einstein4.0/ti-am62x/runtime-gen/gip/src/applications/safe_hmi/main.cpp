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
// Date: Thu Dec 04 14:35:27 IST 2025
// User: HCHITTUR
// System: GIP
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.7
//
//---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <csignal>
#include "dk_runtime_thread_pool.h"
#include "dk_runtime_msgcmn.h"
#include "safe_hmi.h"
#include "shmi_component.h"

LOG_DECLARE_CONTEXT ( gRTELogContext );

using namespace dk::runtime::core;

//Forward declare message maps for the Components
extern std::map<mid_t, func_t> oSHMIComponentMessageMap;

//Instantiate Software Components
SHMIComponent oSHMIComponent(&oSHMIComponentMessageMap, COMPID_OSHMICOMPONENT_STR);

//Define Messages
static const uint16_t oSHMIComponentMessageArraySize = 8U;
const MsgCmn oSHMIComponentMessageArray[oSHMIComponentMessageArraySize] =
{
    {
        DK_MSG_TT_STATUS,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            TT_Status msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            for (uint16_t i0 = 0U; i0 < 15U; i0++)
            {
                ( void ) msgDes.deserialize(msg.mask[i0]);
            }
            oSHMIComponent.onReceiveTT_Status(msg);
        }
    },
    {
        DK_MSG_RTT_STATUS,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            RTT_Status msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            for (uint16_t i0 = 0U; i0 < 2U; i0++)
            {
                ( void ) msgDes.deserialize(msg.mask[i0]);
            }
            oSHMIComponent.onReceiveRTT_Status(msg);
        }
    },
    {
        DK_MSG_FRTT_STATUS,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            FRTT_Status msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            for (uint16_t i0 = 0U; i0 < 2U; i0++)
            {
                ( void ) msgDes.deserialize(msg.mask[i0]);
            }
            oSHMIComponent.onReceiveFRTT_Status(msg);
        }
    },
    {
        DK_MSG_RTT_TOGGLE,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            RTT_Toggle msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.positions);
            ( void ) msgDes.deserialize(msg.display);
            oSHMIComponent.onReceiveRTT_Toggle(msg);
        }
    },
    {
        DK_MSG_RTT_ICON,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            RTT_Icon msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            for (uint16_t i0 = 0U; i0 < 2U; i0++)
            {
                ( void ) msgDes.deserialize(msg.icon[i0]);
            }
            oSHMIComponent.onReceiveRTT_Icon(msg);
        }
    },
    {
        DK_MSG_WARNINGDISPLAY,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            WarningDisplay msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.show);
            ( void ) msgDes.deserialize(msg.warningId);
            for (uint16_t i0 = 0U; i0 < 8U; i0++)
            {
                ( void ) msgDes.deserialize(msg.dynData[i0]);
            }
            oSHMIComponent.onReceiveWarningDisplay(msg);
        }
    },
    {
        DK_MSG_WARNINGEXTDISPLAY,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            WarningExtDisplay msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.show);
            ( void ) msgDes.deserialize(msg.warningId);
            for (uint16_t i0 = 0U; i0 < 8U; i0++)
            {
                ( void ) msgDes.deserialize(msg.dynData[i0]);
            }
            oSHMIComponent.onReceiveWarningExtDisplay(msg);
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
            oSHMIComponent.onReceivePowerSystemState(msg);
        }
    }
};

//Define Message Map for Components
std::map<mid_t, func_t> oSHMIComponentMessageMap = createMap(oSHMIComponentMessageArraySize, oSHMIComponentMessageArray);

//Instantiate Containter
Container SafeHMICon(&oSHMIComponent);

//Instantiate Application
SafeHMI gApp("SafeHMI", &SafeHMICon);

//Instantiate Threads
#define PTH_BODY
#include "safe_hmi_threads.h"
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
         LOG_REGISTER_APP_SLOG2("SHMI", "Safe HMI");
         LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO );
        #else
         LOG_REGISTER_APP_DLT("SHMI", "Safe HMI");
         LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO );
        #endif
        /// End of user code

        // Register Threads
#define PTH_REG
#include "safe_hmi_threads.h"
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
