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
#include <chrono>
#include <thread>
#include "dk_runtime_thread_pool.h"
#include "meet_app.h"
#include "meet_component.h"

using namespace dk::runtime::core;
using namespace dk::lib::meet;

extern MeetComponent oMeetComponent;

bool MeetApp::onInit()
{
    ( void ) Application::onInit();
    LOGV(nullptr, "MeetApp::onInit");
    return true;
}

bool MeetApp::onExit()
{
    ( void ) Application::onExit();
    LOGV(nullptr, "MeetApp::onExit");
    return true;
}

bool MeetApp::onStart()
{
    ( void ) Application::onStart();
    LOGV(nullptr, "MeetApp::onStart");
    threads.start(TID_gApp_runDispatchQueue);
    threads.start(TID_gApp_runIpcMessagePump);
    threads.start(TID_MeetCon_runMessagePump);
    return true;
}

bool MeetApp::onStop()
{
    ( void ) Application::onStop();
    LOGV(nullptr, "MeetApp::onStop");
    threads.stop(TID_MeetCon_runMessagePump);
    threads.stop(TID_gApp_runIpcMessagePump);
    threads.stop(TID_gApp_runDispatchQueue);
    return true;
}

int32_t MeetApp::onRun()
{
    ( void ) Application::onRun();
    LOGV(nullptr, "MeetApp::onRun");
    ( void ) mWdgIf.start(1000U);
    while (getIsRunning())
    {
        oMeetComponent.worker();

        //TODO: Make this configurable
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        mWdgIf.sendHeartbeat();
    }
    ( void ) mWdgIf.stop();

    return 0;
}


void MeetApp::sendDiagResponse(DiagResponse const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_DIAGRESPONSE, COMPID_OMEETCOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.responseCode);
    ( void ) pMsgSerIpc->serialize(msg.dataLen);
    for (uint16_t i0 = 0U; i0 < 256U; i0++)
    {
        ( void ) pMsgSerIpc->serialize(msg.data[i0]);
    }
    gApp.sendMsgToIpc(pMsgSerIpc);
}


