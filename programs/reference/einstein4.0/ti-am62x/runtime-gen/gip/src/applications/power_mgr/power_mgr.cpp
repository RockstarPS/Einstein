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
// Date: Wed Sep 17 12:31:01 IST 2025
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
#include "power_mgr.h"
#include "system_state_component.h"
#include "health_mgr_component.h"

using namespace dk::runtime::core;

extern SystemStateComponent oSystemStateComponent;
extern HealthMgrComponent oHealthMgrComponent;

bool PowerMgr::onInit()
{
    ( void ) Application::onInit();
    LOGV(nullptr, "PowerMgr::onInit");
    return true;
}

bool PowerMgr::onExit()
{
    ( void ) Application::onExit();
    LOGV(nullptr, "PowerMgr::onExit");
    return true;
}

bool PowerMgr::onStart()
{
    ( void ) Application::onStart();
    LOGV(nullptr, "PowerMgr::onStart");
    threads.start(TID_gApp_runDispatchQueue);
    threads.start(TID_gApp_runIpcMessagePump);
    threads.start(TID_SSContainter_runMessagePump);
    return true;
}

bool PowerMgr::onStop()
{
    ( void ) Application::onStop();
    LOGV(nullptr, "PowerMgr::onStop");
    threads.stop(TID_SSContainter_runMessagePump);
    threads.stop(TID_gApp_runIpcMessagePump);
    threads.stop(TID_gApp_runDispatchQueue);
    return true;
}

int32_t PowerMgr::onRun()
{
    ( void ) Application::onRun();
    LOGV(nullptr, "PowerMgr::onRun");
    ( void ) mWdgIf.start(1000U);
    while (getIsRunning())
    {
        oSystemStateComponent.worker();
        oHealthMgrComponent.worker();

        //TODO: Make this configurable
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        mWdgIf.sendHeartbeat();
    }
    ( void ) mWdgIf.stop();

    return 0;
}


void PowerMgr::sendPowerSystemState(PowerSystemState const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_POWERSYSTEMSTATE, COMPID_OSYSTEMSTATECOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.domainId);
    ( void ) pMsgSerIpc->serialize(msg.state);
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void PowerMgr::sendPowerExtendShutdownTime(PowerExtendShutdownTime const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_POWEREXTENDSHUTDOWNTIME, COMPID_OSYSTEMSTATECOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.domainId);
    ( void ) pMsgSerIpc->serialize(msg.timeoutMs);
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void PowerMgr::sendPowerKeepSystemAwake(PowerKeepSystemAwake const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_POWERKEEPSYSTEMAWAKE, COMPID_OSYSTEMSTATECOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.domainId);
    ( void ) pMsgSerIpc->serialize(msg.timeoutMs);
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void PowerMgr::sendHealthStatusReport(HealthStatusReport const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;

    //Local Routing. Generated if an component inside the application is expecting this message
    MsgSerializer * const pMsgSer = new MsgSerializer(DK_MSG_HEALTHSTATUSREPORT, COMPID_OSYSTEMSTATECOMPONENT, msgCnt);


    ( void ) pMsgSer->serialize(msg.timestamp);
    ( void ) pMsgSer->serialize(msg.dataLen);
    for (uint16_t i0 = 0U; i0 < 256U; i0++)
    {
        ( void ) pMsgSer->serialize(msg.data[i0]);
    }
    gApp.sendMsgToDisplatchQueue(pMsgSer);

    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_HEALTHSTATUSREPORT, COMPID_OSYSTEMSTATECOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.timestamp);
    ( void ) pMsgSerIpc->serialize(msg.dataLen);
    for (uint16_t i0 = 0U; i0 < 256U; i0++)
    {
        ( void ) pMsgSerIpc->serialize(msg.data[i0]);
    }
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void PowerMgr::sendHealthGetStatus(HealthGetStatus const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;

    //Local Routing. Generated if an component inside the application is expecting this message
    MsgSerializer * const pMsgSer = new MsgSerializer(DK_MSG_HEALTHGETSTATUS, COMPID_OHEALTHMGRCOMPONENT, msgCnt);


    ( void ) pMsgSer->serialize(msg.compIdx);
    gApp.sendMsgToDisplatchQueue(pMsgSer);

    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_HEALTHGETSTATUS, COMPID_OHEALTHMGRCOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.compIdx);
    gApp.sendMsgToIpc(pMsgSerIpc);
}


