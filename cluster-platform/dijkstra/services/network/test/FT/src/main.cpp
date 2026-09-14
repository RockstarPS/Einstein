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
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.1.4
// Date: Tue Oct 05 14:20:19 IST 2021
// User: SSHANKA8
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <csignal>
#include "dk_runtime_thread_pool.h"
#include "dk_runtime_msgcmn.h"
#include "network_test.h"
#include "network_test_component.h"

#define COMPID_ONETWORKIFAPPCOMPONENTTEST_STR ("OTEST_NET")

#define COMPID_ONETWORKIFAPPCOMPONENTTEST         ((uint8_t)0x24U)

#define COMPID_ONETWORKIFAPPCOMPONENTTEST_DESC    ("")

LOG_DECLARE_CONTEXT(gRTELogContext);

using namespace dk::runtime::core;

// Forward declare message maps for the Components
extern std::map<mid_t, func_t> oNetworkifAppComponentMessageMap;

// Instantiate Software Components
NetworkifAppComponent oNetworkifAppComponent(&oNetworkifAppComponentMessageMap, COMPID_ONETWORKIFAPPCOMPONENTTEST_STR);

// Define Messages
static const uint16_t oNetworkifAppComponentMessageArraySize = 1U;
const MsgCmn oNetworkifAppComponentMessageArray[oNetworkifAppComponentMessageArraySize] =
    {

        DK_MSG_NETWORKINTERFACESTATUS,

        [](dk::runtime::core::MsgDeserializer &msgDes)
        {
            NetworkInterfaceStatus msg;

            msg.base.compId = msgDes.mSenderId;

            msg.base.msgCnt = msgDes.mMsgCnt;

            (void)msgDes.deserialize(msg.interfaceNameLength);

            for (uint16_t i0 = 0U; i0 < 256U; i0++)

            {

                (void)msgDes.deserialize(msg.interfaceName[i0]);
            }

            (void)msgDes.deserialize(msg.linkStatus);

            (void)msgDes.deserialize(msg.ipAddressLength);

            for (uint16_t i0 = 0U; i0 < 256U; i0++)

            {

                (void)msgDes.deserialize(msg.ipAddress[i0]);
            }

            oNetworkifAppComponent.onReceiveNetworkInterfaceStatus(msg);
        }

};
// Define Message Map for Components
std::map<mid_t, func_t> oNetworkifAppComponentMessageMap = createMap(oNetworkifAppComponentMessageArraySize, oNetworkifAppComponentMessageArray);

// Instantiate Containter
Container networkIfContainer(&oNetworkifAppComponent);

// Instantiate Application
networkif gApp("networkif", &networkIfContainer);

// Instantiate Threads
#define PTH_BODY
#include "network_test_threads.h"
#undef PTH_BODY

void signalHandler(const int32_t signum)
{
    std::cout << "Interrupt signal (" << signum << ") received.\n";

    // cleanup and close up stuff here
    // terminate program
    (void)gApp.stop();

    std::exit(signum);
}

/// Start of user code : User code for file main.cpp

/// End of user code

int main(int argc, char *argv[])
{
    int32_t l_gApp_ret_S32;
    gApp.test_case = atoi(argv[1]);

    try
    {
        if (SIG_ERR == std::signal(SIGINT, &signalHandler))
        {
            LOGI(&gRTELogContext, "Failed to create signal handler");
        }

        /// Start of user code : User code for function main in file main.cpp
        gApp.setWatchdogEnabled(true);
        LOG_REGISTER_APP_SLOG2("NETTEST", "NETWORKTEST Application");
        LOG_REGISTER_CONTEXT(gRTELogContext, "RTE", "Runtime Context", DLT_LOG_INFO);
        /// End of user code

        // Register Threads
#define PTH_REG
#include "network_test_threads.h"
#undef PTH_REG
        l_gApp_ret_S32 = gApp.run();
        LOG_UNREGISTER_CONTEXT(gRTELogContext);
    }
    catch (...)
    {
        l_gApp_ret_S32 = -1;
        // Handle the exceptions.
    }

    return l_gApp_ret_S32;
}
