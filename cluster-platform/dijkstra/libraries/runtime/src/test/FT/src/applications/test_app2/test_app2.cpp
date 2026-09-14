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
#include <chrono>
#include <thread>
#include "dk_runtime_thread_pool.h"
#include "test_app2.h"
#include "test_app2_comp1.h"

using namespace dk::runtime::core;

extern test_app2_comp1 otest_app2_comp1;

bool testApp2::onInit()
{
    Application::onInit();
    LOGV(NULL, "testApp2::onInit");
    return true;
}

bool testApp2::onExit()
{
    Application::onExit();
    LOGV(NULL, "testApp2::onExit");
    return true;
}

bool testApp2::onStart()
{
    Application::onStart();
    LOGV(NULL, "testApp2::onStart");
    threads.start(TID_gApp_runDispatchQueue);
    threads.start(TID_gApp_runIpcMessagePump);
    threads.start(TID_testAppCon_runMessagePump);
    return true;
}

bool testApp2::onStop()
{
    Application::onStop();
    LOGV(NULL, "testApp2::onStop");
    threads.stop(TID_testAppCon_runMessagePump);
    threads.stop(TID_gApp_runIpcMessagePump);
    threads.stop(TID_gApp_runDispatchQueue);
    return true;
}

int32_t testApp2::onRun()
{
    Application::onRun();
    LOGV(NULL, "testApp2::onRun");
    mWdgIf.start(1000U);
    while (getIsRunning())
    {
        otest_app2_comp1.worker();

        //TODO: Make this configurable
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        mWdgIf.sendHeartbeat();
    }
    mWdgIf.stop();

    return 0;
}


void testApp2::sendDkMsgTestApp2Transmit(DkMsgTestMsg_t & msg)
{
    static uint8_t msgCnt = 0;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_DKMSGTESTAPP2TRANSMIT, COMPID_OTEST_APP2_COMP1, msgCnt);


    pMsgSerIpc->serialize(msg.var1);
    pMsgSerIpc->serialize(msg.var2);
    gApp.sendMsgToIpc(pMsgSerIpc);
}


