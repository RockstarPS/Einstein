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
// Date: Thu Apr 17 12:47:36 IST 2025
// User: GSOUNDAR
// System: GIP
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.4
//
//---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <chrono>
#include <thread>
#include "dk_runtime_thread_pool.h"
#include "hmi_app.h"
#include "hmi_gauges_component.h"
#include "hmi_warnings_component.h"
#include "hmi_gear_component.h"
#include "hmi_illumination_component.h"
#include "hmi_component.h"

using namespace dk::runtime::core;

extern HMIGaugesComponent oHMIGaugesComponent;
extern HMIWarningsComponent oHMIWarningsComponent;
extern HMIGearComponent oHMIGearComponent;
extern HMIIlluminationComponent oHMIIlluminationComponent;
extern HMIComponent oHMIComponent;

bool HMIApp::onInit()
{
    ( void ) Application::onInit();
    LOGV(nullptr, "HMIApp::onInit");
    return true;
}

bool HMIApp::onExit()
{
    ( void ) Application::onExit();
    LOGV(nullptr, "HMIApp::onExit");
    return true;
}

bool HMIApp::onStart()
{
    ( void ) Application::onStart();
    LOGV(nullptr, "HMIApp::onStart");
    threads.start(TID_gApp_runDispatchQueue);
    threads.start(TID_gApp_runIpcMessagePump);
    threads.start(TID_HmiAppCon_runMessagePump);
    return true;
}

bool HMIApp::onStop()
{
    ( void ) Application::onStop();
    LOGV(nullptr, "HMIApp::onStop");
    threads.stop(TID_HmiAppCon_runMessagePump);
    threads.stop(TID_gApp_runIpcMessagePump);
    threads.stop(TID_gApp_runDispatchQueue);
    return true;
}

int32_t HMIApp::onRun()
{
    ( void ) Application::onRun();
    LOGV(nullptr, "HMIApp::onRun");
    ( void ) mWdgIf.start(1000U);
    while (getIsRunning())
    {
        sendMHmiReady(MHMI_READY);
        oHMIGaugesComponent.worker();
        oHMIWarningsComponent.worker();
        oHMIGearComponent.worker();
        oHMIIlluminationComponent.worker();
        oHMIComponent.worker();

        //TODO: Make this configurable
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        mWdgIf.sendHeartbeat();
    }
    ( void ) mWdgIf.stop();

    return 0;
}


void HMIApp::sendWarningStatus(WarningStatus const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_WARNINGSTATUS, COMPID_OHMIWARNINGSCOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.visible);
    ( void ) pMsgSerIpc->serialize(msg.warningId);
    for (uint16_t i0 = 0U; i0 < 10U; i0++)
    {
        ( void ) pMsgSerIpc->serialize(msg.dynData[i0]);
    }
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void HMIApp::sendWarningDisplayAvailable(WarningDisplayAvailable const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_WARNINGDISPLAYAVAILABLE, COMPID_OHMIWARNINGSCOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.status);
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void HMIApp::sendDisplaySetPower(DisplaySetPower const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_DISPLAYSETPOWER, COMPID_OHMICOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.displayId);
    ( void ) pMsgSerIpc->serialize(msg.state);
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void HMIApp::sendDisplayGetState(DisplayGetState const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_DISPLAYGETSTATE, COMPID_OHMICOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.displayId);
    gApp.sendMsgToIpc(pMsgSerIpc);
}



void sendMHmiReady(const MHmiReadyStateType mhmiReadyState)
{
	MainHMIReadyStatus MHmiReadyStatus;
	MHmiReadyStatus.status = mhmiReadyState;
	gApp.sendMainHMIReadyStatus(MHmiReadyStatus);
}
void HMIApp::sendMainHMIReadyStatus(MainHMIReadyStatus const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_MAINHMIREADYSTATUS, COMPID_OHMICOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.status);
    gApp.sendMsgToIpc(pMsgSerIpc);
}


