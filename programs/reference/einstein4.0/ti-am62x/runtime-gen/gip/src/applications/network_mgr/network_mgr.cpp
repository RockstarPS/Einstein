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
// Date: Fri Jul 17 16:58:23 IST 2026
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
#include "network_mgr.h"
#include "network_manager_component.h"

using namespace dk::runtime::core;
using namespace dk::srvc::platform;
extern NetworkManagerComponent oNetworkManagerComponent;

bool NetworkMgr::onInit()
{
    ( void ) Application::onInit();
    LOGV(nullptr, "NetworkMgr::onInit");
    return true;
}

bool NetworkMgr::onExit()
{
    ( void ) Application::onExit();
    LOGV(nullptr, "NetworkMgr::onExit");
    return true;
}

bool NetworkMgr::onStart()
{
    ( void ) Application::onStart();
    LOGV(nullptr, "NetworkMgr::onStart");
    threads.start(TID_gApp_runDispatchQueue);
    threads.start(TID_gApp_runIpcMessagePump);
    threads.start(TID_NetworkMgrCon_runMessagePump);
    return true;
}

bool NetworkMgr::onStop()
{
    ( void ) Application::onStop();
    LOGV(nullptr, "NetworkMgr::onStop");
    threads.stop(TID_NetworkMgrCon_runMessagePump);
    threads.stop(TID_gApp_runIpcMessagePump);
    threads.stop(TID_gApp_runDispatchQueue);
    return true;
}

int32_t NetworkMgr::onRun()
{
    ( void ) Application::onRun();
    LOGV(nullptr, "NetworkMgr::onRun");
    ( void ) mWdgIf.start(1000U);
    while (getIsRunning())
    {
        oNetworkManagerComponent.worker();

        //TODO: Make this configurable
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        mWdgIf.sendHeartbeat();
    }
    ( void ) mWdgIf.stop();

    return 0;
}


void NetworkMgr::sendNetworkInterfaceStatus(NetworkInterfaceStatus const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_NETWORKINTERFACESTATUS, COMPID_ONETWORKMANAGERCOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.interfaceNameLength);
    for (uint16_t i0 = 0U; i0 < 256U; i0++)
    {
        ( void ) pMsgSerIpc->serialize(msg.interfaceName[i0]);
    }
    ( void ) pMsgSerIpc->serialize(msg.linkStatus);
    ( void ) pMsgSerIpc->serialize(msg.ipAddressLength);
    for (uint16_t i0 = 0U; i0 < 256U; i0++)
    {
        ( void ) pMsgSerIpc->serialize(msg.ipAddress[i0]);
    }
    gApp.sendMsgToIpc(pMsgSerIpc);
}


