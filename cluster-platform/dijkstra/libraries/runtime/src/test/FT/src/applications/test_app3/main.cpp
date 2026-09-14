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
// Date: Wed Oct 21 19:36:47 IST 2020
// User: SSINGH25
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <csignal>
#include "dk_runtime_thread_pool.h"
#include "dk_runtime_msgcmn.h"
#include "test_app3.h"
#include "test_app3_com1.h"

LOG_DECLARE_CONTEXT ( gRTELogContext );

using namespace dk::runtime::core;

//Forward declare message maps for the Components
extern std::map<mid_t, func_t> otest_app3_com1MessageMap;

//Instantiate Software Components
test_app3_com1 otest_app3_com1(&otest_app3_com1MessageMap, COMPID_OTEST_APP3_COM1_STR);

//Define Messages
static const int otest_app3_com1MessageArraySize = 0;
const MsgCmn otest_app3_com1MessageArray[otest_app3_com1MessageArraySize] =
{

};

//Define Message Map for Components
std::map<mid_t, func_t> otest_app3_com1MessageMap = createMap(otest_app3_com1MessageArraySize, otest_app3_com1MessageArray);

//Instantiate Containter
Container testApp3Con(&otest_app3_com1);

//Instantiate Application
testApp3 gApp("testApp3", &testApp3Con);

//Instantiate Threads
#define PTH_BODY
#include "test_app3_threads.h"
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
    std::signal(SIGABRT, signalHandler);

    /// Start of user code : User code for function main in file main.cpp
    LOG_REGISTER_APP_CONSOLE ( "test_app3", "test_app3" );
    gApp.setWatchdogEnabled(true);
    LOG_REGISTER_CONTEXT ( gRTELogContext, "RTE", "Runtime Context", DLT_LOG_VERBOSE );
    /// End of user code

    // Register Threads
#define PTH_REG
#include "test_app3_threads.h"
#undef PTH_REG

    int32_t l_gApp_ret_S32 = gApp.run();
    LOG_UNREGISTER_CONTEXT ( gRTELogContext );

    return l_gApp_ret_S32;
}
