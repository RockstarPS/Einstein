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
// Message Catalogue version : 1.0.6
//
//---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <csignal>
#include "dk_runtime_thread_pool.h"
#include "dk_runtime_msgcmn.h"
#include "power_mgr.h"
#include "system_state_component.h"
#include "health_mgr_component.h"

LOG_DECLARE_CONTEXT ( gRTELogContext );

using namespace dk::runtime::core;

//Forward declare message maps for the Components
extern std::map<mid_t, func_t> oSystemStateComponentMessageMap;
extern std::map<mid_t, func_t> oHealthMgrComponentMessageMap;

//Instantiate Software Components
SystemStateComponent oSystemStateComponent(&oSystemStateComponentMessageMap, COMPID_OSYSTEMSTATECOMPONENT_STR);
HealthMgrComponent oHealthMgrComponent(&oHealthMgrComponentMessageMap, COMPID_OHEALTHMGRCOMPONENT_STR);

//Define Messages
static const uint16_t oSystemStateComponentMessageArraySize = 7U;
const MsgCmn oSystemStateComponentMessageArray[oSystemStateComponentMessageArraySize] =
{
    {
        DK_MSG_POWERSYSTEMSTATEREQCHANGE,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            PowerSystemStateReqChange msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.domainId);
            ( void ) msgDes.deserialize(msg.state);
            oSystemStateComponent.onReceivePowerSystemStateReqChange(msg);
        }
    },
    {
        DK_MSG_RTC,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            RTC msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.dateTime.year);
            ( void ) msgDes.deserialize(msg.dateTime.month);
            ( void ) msgDes.deserialize(msg.dateTime.day);
            ( void ) msgDes.deserialize(msg.dateTime.hour);
            ( void ) msgDes.deserialize(msg.dateTime.min);
            ( void ) msgDes.deserialize(msg.dateTime.sec);
            oSystemStateComponent.onReceiveRTC(msg);
        }
    },
    {
        DK_MSG_POWERSYSTEMSTATEREQWAKELOCK,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            PowerSystemStateReqWakeLock msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.enable);
            ( void ) msgDes.deserialize(msg.requiredTimeMs);
            oSystemStateComponent.onReceivePowerSystemStateReqWakeLock(msg);
        }
    },
    {
        DK_MSG_POWERREPORTCOMPSTATE,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            PowerReportCompState msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.state);
            oSystemStateComponent.onReceivePowerReportCompState(msg);
        }
    },
    {
        DK_MSG_UCLERRORNOTIFY,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            UCL_ERROR_NOTIFY msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.errorCode);
            oSystemStateComponent.onReceiveUclErrorNotify(msg);
        }
    },
    {
        DK_MSG_UCLLINKSTATUS,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            UCL_LINK_STATUS msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.status);
            oSystemStateComponent.onReceiveUclLinkStatus(msg);
        }
    },
    {
        DK_MSG_HEALTHGETSTATUS,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            HealthGetStatus msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.compIdx);
            oSystemStateComponent.onReceiveHealthGetStatus(msg);
        }
    }
};

static const uint16_t oHealthMgrComponentMessageArraySize = 1U;
const MsgCmn oHealthMgrComponentMessageArray[oHealthMgrComponentMessageArraySize] =
{
    {
        DK_MSG_HEALTHSTATUSREPORT,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            HealthStatusReport msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.timestamp);
            ( void ) msgDes.deserialize(msg.dataLen);
            for (uint16_t i0 = 0U; i0 < 256U; i0++)
            {
                ( void ) msgDes.deserialize(msg.data[i0]);
            }
            oHealthMgrComponent.onReceiveHealthStatusReport(msg);
        }
    }
};

//Define Message Map for Components
std::map<mid_t, func_t> oSystemStateComponentMessageMap = createMap(oSystemStateComponentMessageArraySize, oSystemStateComponentMessageArray);
std::map<mid_t, func_t> oHealthMgrComponentMessageMap = createMap(oHealthMgrComponentMessageArraySize, oHealthMgrComponentMessageArray);

//Instantiate Containter
Container SSContainter(&oSystemStateComponent, &oHealthMgrComponent);

//Instantiate Application
PowerMgr gApp("PowerMgr", &SSContainter);

//Instantiate Threads
#define PTH_BODY
#include "power_mgr_threads.h"
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
         gApp.setWatchdogEnabled(true);
         LOG_REGISTER_APP_SLOG2("PWRM", "Power Manager");
         LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO );
        #else
         LOG_REGISTER_APP_DLT("PWRM", "Power Manager");
         LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO );
        #endif

        /// End of user code

        // Register Threads
#define PTH_REG
#include "power_mgr_threads.h"
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
