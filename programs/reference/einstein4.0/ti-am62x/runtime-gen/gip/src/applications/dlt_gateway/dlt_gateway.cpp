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
// Date: Tue May 26 14:49:30 IST 2026
// User: GSOUNDAR
// System: GIP
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.10
//
//---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <chrono>
#include <thread>
#include "dk_runtime_thread_pool.h"
#include "dlt_gateway.h"
#include "dlt_gateway_component.h"

using namespace dk::runtime::core;

extern DltGatewayComponent oDltGatewayComponent;

bool DltGateway::onInit()
{
    ( void ) Application::onInit();
    LOGV(nullptr, "DltGateway::onInit");
    return true;
}

bool DltGateway::onExit()
{
    ( void ) Application::onExit();
    LOGV(nullptr, "DltGateway::onExit");
    return true;
}

bool DltGateway::onStart()
{
    ( void ) Application::onStart();
    LOGV(nullptr, "DltGateway::onStart");
    threads.start(TID_gApp_runDispatchQueue);
    threads.start(TID_gApp_runIpcMessagePump);
    threads.start(TID_DltGatewayCon_runMessagePump);
    return true;
}

bool DltGateway::onStop()
{
    ( void ) Application::onStop();
    LOGV(nullptr, "DltGateway::onStop");
    threads.stop(TID_DltGatewayCon_runMessagePump);
    threads.stop(TID_gApp_runIpcMessagePump);
    threads.stop(TID_gApp_runDispatchQueue);
    return true;
}

int32_t DltGateway::onRun()
{
    ( void ) Application::onRun();
    LOGV(nullptr, "DltGateway::onRun");
    ( void ) mWdgIf.start(1000U);
    while (getIsRunning())
    {
        oDltGatewayComponent.worker();

        //TODO: Make this configurable
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        mWdgIf.sendHeartbeat();
    }
    ( void ) mWdgIf.stop();

    return 0;
}


void DltGateway::sendDLTMessageReadAck(DLTMessageReadAck const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_DLTMESSAGEREADACK, COMPID_ODLTGATEWAYCOMPONENT, msgCnt);


    for (uint16_t i0 = 0U; i0 < 2U; i0++)
    {
        ( void ) pMsgSerIpc->serialize(msg.status[i0]);
    }
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void DltGateway::sendDLTControlMessageRequest(DLTControlMessageRequest const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_DLTCONTROLMESSAGEREQUEST, COMPID_ODLTGATEWAYCOMPONENT, msgCnt);


    for (uint16_t i0 = 0U; i0 < 2U; i0++)
    {
        ( void ) pMsgSerIpc->serialize(msg.status[i0]);
    }
    gApp.sendMsgToIpc(pMsgSerIpc);
}


