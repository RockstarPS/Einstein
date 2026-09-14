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
// Date: Wed Sep 17 12:31:02 IST 2025
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
#include "meet_app.h"
#include "meet_component.h"

LOG_DECLARE_CONTEXT ( gRTELogContext );

using namespace dk::runtime::core;
using namespace dk::lib::meet;

//Forward declare message maps for the Components
extern std::map<mid_t, func_t> oMeetComponentMessageMap;

//Instantiate Software Components
MeetComponent oMeetComponent(&oMeetComponentMessageMap, COMPID_OMEETCOMPONENT_STR);

//Define Messages
static const uint16_t oMeetComponentMessageArraySize = 4U;
const MsgCmn oMeetComponentMessageArray[oMeetComponentMessageArraySize] =
{
    {
        DK_MSG_DIAGROUTINEREQUEST,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            DiagRoutineRequest msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.routineId);
            ( void ) msgDes.deserialize(msg.routineType);
            ( void ) msgDes.deserialize(msg.dataLen);
            for (uint16_t i0 = 0U; i0 < 256U; i0++)
            {
                ( void ) msgDes.deserialize(msg.data[i0]);
            }
            oMeetComponent.onReceiveDiagRoutineRequest(msg);
        }
    },
    {
        DK_MSG_DIAGIOCTRLREQUEST,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            DiagIOCtrlRequest msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.did);
            ( void ) msgDes.deserialize(msg.optionCtrl);
            ( void ) msgDes.deserialize(msg.dataLen);
            for (uint16_t i0 = 0U; i0 < 256U; i0++)
            {
                ( void ) msgDes.deserialize(msg.data[i0]);
            }
            oMeetComponent.onReceiveDiagIOCtrlRequest(msg);
        }
    },
    {
        DK_MSG_DIAGDIDREQUEST,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            DiagDIDRequest msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.did);
            ( void ) msgDes.deserialize(msg.didType);
            ( void ) msgDes.deserialize(msg.dataLen);
            for (uint16_t i0 = 0U; i0 < 256U; i0++)
            {
                ( void ) msgDes.deserialize(msg.data[i0]);
            }
            oMeetComponent.onReceiveDiagDIDRequest(msg);
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
            oMeetComponent.onReceivePowerSystemState(msg);
        }
    }
};

//Define Message Map for Components
std::map<mid_t, func_t> oMeetComponentMessageMap = createMap(oMeetComponentMessageArraySize, oMeetComponentMessageArray);

//Instantiate Containter
Container MeetCon(&oMeetComponent);

//Instantiate Application
MeetApp gApp("MeetApp", &MeetCon);

//Instantiate Threads
#define PTH_BODY
#include "meet_app_threads.h"
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
         LOG_REGISTER_APP_SLOG2("MEETA", "MEET APP Application");
         LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO );
        #else
         LOG_REGISTER_APP_DLT("MEETA", "MEET APP Application");
         LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO );
        #endif

        /// End of user code

        // Register Threads
#define PTH_REG
#include "meet_app_threads.h"
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
