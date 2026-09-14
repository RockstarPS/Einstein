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
// Date: Tue Nov 04 12:31:47 IST 2025
// User: PSIVAKU7
// System: GIP
// Configuration: Platform
// Project: Einstein4_Platform_imported
// Message Catalogue version : 1.0.5
//
//---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <csignal>
#include "dk_runtime_thread_pool.h"
#include "dk_runtime_msgcmn.h"
#include "uds_swc_diag.h"
#include "uds_swc_diag_component.h"

LOG_DECLARE_CONTEXT ( gRTELogContext );

using namespace dk::runtime::core;

//Forward declare message maps for the Components
extern std::map<mid_t, func_t> oUdsSWCDiagComponentMessageMap;

//Instantiate Software Components
UdsSWCDiagComponent oUdsSWCDiagComponent(&oUdsSWCDiagComponentMessageMap, COMPID_OUDSSWCDIAGCOMPONENT_STR);

//Define Messages
static const uint16_t oUdsSWCDiagComponentMessageArraySize = 1U;
const MsgCmn oUdsSWCDiagComponentMessageArray[oUdsSWCDiagComponentMessageArraySize] =
{
    {
        DK_MSG_GIPDIAGREQUEST,
         [](dk::runtime::core::MsgDeserializer &msgDes) {
            GipDiagRequest msg = {0};
            msg.base.compId = msgDes.mSenderId;
            msg.base.msgCnt = msgDes.mMsgCnt;


            ( void ) msgDes.deserialize(msg.serviceId);
            ( void ) msgDes.deserialize(msg.didId);
            ( void ) msgDes.deserialize(msg.controlOpLen);
            for (uint16_t i0 = 0U; i0 < 8U; i0++)
            {
                ( void ) msgDes.deserialize(msg.controlOp[i0]);
            }
            ( void ) msgDes.deserialize(msg.dataLen);
            for (uint16_t i0 = 0U; i0 < 256U; i0++)
            {
                ( void ) msgDes.deserialize(msg.data[i0]);
            }
            oUdsSWCDiagComponent.onReceiveGipDiagRequest(msg);
        }
    }
};

//Define Message Map for Components
std::map<mid_t, func_t> oUdsSWCDiagComponentMessageMap = createMap(oUdsSWCDiagComponentMessageArraySize, oUdsSWCDiagComponentMessageArray);

//Instantiate Containter
Container UdsTestCon(&oUdsSWCDiagComponent);

//Instantiate Application
UdsSWCDiag gApp("UdsSWCDiag", &UdsTestCon);

//Instantiate Threads
#define PTH_BODY
#include "uds_swc_diag_threads.h"
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
         LOG_REGISTER_APP_SLOG2("UDS", "uds swc diag");
         LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO );
        #else
         LOG_REGISTER_APP_DLT("UDS", "uds swc diag");
         LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO );
        #endif
        /// End of user code

        // Register Threads
#define PTH_REG
#include "uds_swc_diag_threads.h"
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
