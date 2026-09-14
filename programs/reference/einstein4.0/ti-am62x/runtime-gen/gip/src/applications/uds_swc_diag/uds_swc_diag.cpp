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
#include <chrono>
#include <thread>
#include "dk_runtime_thread_pool.h"
#include "uds_swc_diag.h"
#include "uds_swc_diag_component.h"

using namespace dk::runtime::core;

extern UdsSWCDiagComponent oUdsSWCDiagComponent;

bool UdsSWCDiag::onInit()
{
    ( void ) Application::onInit();
    LOGV(nullptr, "UdsSWCDiag::onInit");
    return true;
}

bool UdsSWCDiag::onExit()
{
    ( void ) Application::onExit();
    LOGV(nullptr, "UdsSWCDiag::onExit");
    return true;
}

bool UdsSWCDiag::onStart()
{
    ( void ) Application::onStart();
    LOGV(nullptr, "UdsSWCDiag::onStart");
    threads.start(TID_gApp_runDispatchQueue);
    threads.start(TID_gApp_runIpcMessagePump);
    threads.start(TID_UdsTestCon_runMessagePump);
    return true;
}

bool UdsSWCDiag::onStop()
{
    ( void ) Application::onStop();
    LOGV(nullptr, "UdsSWCDiag::onStop");
    threads.stop(TID_UdsTestCon_runMessagePump);
    threads.stop(TID_gApp_runIpcMessagePump);
    threads.stop(TID_gApp_runDispatchQueue);
    return true;
}

int32_t UdsSWCDiag::onRun()
{
    ( void ) Application::onRun();
    LOGV(nullptr, "UdsSWCDiag::onRun");
    ( void ) mWdgIf.start(1000U);
    while (getIsRunning())
    {
        oUdsSWCDiagComponent.worker();

        //TODO: Make this configurable
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        mWdgIf.sendHeartbeat();
    }
    ( void ) mWdgIf.stop();

    return 0;
}


void UdsSWCDiag::sendGipDiagResponse(GipDiagResponse const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_GIPDIAGRESPONSE, COMPID_OUDSSWCDIAGCOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.sid);
    ( void ) pMsgSerIpc->serialize(msg.didId);
    ( void ) pMsgSerIpc->serialize(msg.responseCode);
    ( void ) pMsgSerIpc->serialize(msg.controlOpLen);
    for (uint16_t i0 = 0U; i0 < 8U; i0++)
    {
        ( void ) pMsgSerIpc->serialize(msg.controlOp[i0]);
    }
    ( void ) pMsgSerIpc->serialize(msg.responseLen);
    for (uint16_t i0 = 0U; i0 < 256U; i0++)
    {
        ( void ) pMsgSerIpc->serialize(msg.response[i0]);
    }
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void UdsSWCDiag::sendNetworkModifyFirewallStatus(NetworkModifyFirewallStatus const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_NETWORKMODIFYFIREWALLSTATUS, COMPID_OUDSSWCDIAGCOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.networkFirewallStatus);
    gApp.sendMsgToIpc(pMsgSerIpc);
}
