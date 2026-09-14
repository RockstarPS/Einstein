//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2018] Visteon Corporation
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
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.1.3
// Date: Sun Nov 01 21:09:51 IST 2020
// User: SSINGH25
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <csignal>
#include "dk_runtime_thread_pool.h"
#include "dk_runtime_msgcmn.h"
#include "t4_app.h"
#include "t11.h"
#include "t12.h"
#include "t21.h"
#include "t22.h"

LOG_DECLARE_CONTEXT ( gRTELogContext );
using namespace dk::runtime::core;

//Forward declare message maps for the Components
extern std::map<mid_t, func_t> oT11MessageMap;
extern std::map<mid_t, func_t> oT12MessageMap;
extern std::map<mid_t, func_t> oT21MessageMap;
extern std::map<mid_t, func_t> oT22MessageMap;

//Instantiate Software Components
T11 oT11(&oT11MessageMap, COMPID_OT11_STR);
T12 oT12(&oT12MessageMap, COMPID_OT12_STR);
T21 oT21(&oT21MessageMap, COMPID_OT21_STR);
T22 oT22(&oT22MessageMap, COMPID_OT22_STR);

//Define Messages
static const int oT11MessageArraySize = 1;
const MsgCmn oT11MessageArray[oT11MessageArraySize] =
{
    {
        DK_MSG_DKMSGT4CON1COMP1RX,
         [&](dk::runtime::core::MsgDeserializer &msgDes) {
            DkMsg1byte_t msg;
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            msgDes.deserialize(msg.uint8_t);
            oT11.onReceiveDkMsgT4Con1Comp1Rx(msg);
        }
    }
};

static const int oT12MessageArraySize = 1;
const MsgCmn oT12MessageArray[oT12MessageArraySize] =
{
    {
        DK_MSG_DKMSGT4CON1COMP1TX,
         [&](dk::runtime::core::MsgDeserializer &msgDes) {
            DkMsg1byte_t msg;
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            msgDes.deserialize(msg.uint8_t);
            oT12.onReceiveDkMsgT4Con1comp1Tx(msg);
        }
    }
};

static const int oT21MessageArraySize = 1;
const MsgCmn oT21MessageArray[oT21MessageArraySize] =
{
    {
        DK_MSG_DKMSGT4CON1COMP2TX,
         [&](dk::runtime::core::MsgDeserializer &msgDes) {
            DkMsg1byte_t msg;
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            msgDes.deserialize(msg.uint8_t);
            oT21.onReceiveDkMsgT4Con1Comp2Tx(msg);
        }
    }
};

static const int oT22MessageArraySize = 1;
const MsgCmn oT22MessageArray[oT22MessageArraySize] =
{
    {
        DK_MSG_DKMSGT4CON2COMP2RX,
         [&](dk::runtime::core::MsgDeserializer &msgDes) {
            DkMsg1byte_t msg;
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            msgDes.deserialize(msg.uint8_t);
            oT22.onReceiveDkMsgT4Con2Comp2Rx(msg);
        }
    }
};

//Define Message Map for Components
std::map<mid_t, func_t> oT11MessageMap = createMap(oT11MessageArraySize, oT11MessageArray);
std::map<mid_t, func_t> oT12MessageMap = createMap(oT12MessageArraySize, oT12MessageArray);
std::map<mid_t, func_t> oT21MessageMap = createMap(oT21MessageArraySize, oT21MessageArray);
std::map<mid_t, func_t> oT22MessageMap = createMap(oT22MessageArraySize, oT22MessageArray);

//Instantiate Containter
Container T4CON1(&oT11, &oT12);
Container T4CON2(&oT21, &oT22);

//Instantiate Application
T4App gApp("T4App", &T4CON1, &T4CON2);

//Instantiate Threads
#define PTH_BODY
#include "t4_app_threads.h"
#undef PTH_BODY

void signalHandler(int signum)
{
    std::cout << "Interrupt signal (" << signum << ") received.\n";

    // cleanup and close up stuff here
    // terminate program
    gApp.stop();

    std::exit(signum);
}

/// Start of user code : User code for file main.cpp

/// End of user code

int main()
{
    std::signal(SIGINT, signalHandler);

    /// Start of user code : User code for function main in file main.cpp
    LOG_REGISTER_APP_CONSOLE ( "test_app4", "test_app4" );
    LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_VERBOSE );
    /// End of user code

    // Register Threads
#define PTH_REG
#include "t4_app_threads.h"
#undef PTH_REG

    int32_t l_gApp_ret_S32 = gApp.run();
    LOG_UNREGISTER_CONTEXT ( gRTELogContext );

    return l_gApp_ret_S32;
}
