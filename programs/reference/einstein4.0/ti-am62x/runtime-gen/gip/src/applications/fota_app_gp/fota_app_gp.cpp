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
// Date: Tue Nov 04 11:44:23 IST 2025
// User: PSIVAKU7
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
#include "fota_app_gp.h"
#include "upd_ucl_adapter_component.h"
#include "upd_doip_adapter_component.h"

using namespace dk::runtime::core;

extern UpdUclAdapterComponent oUpdUclAdapterComponent;
extern UpdDoipAdapterComponent oUpdDoipAdapterComponent;

bool fota_app_gp::onInit()
{
    ( void ) Application::onInit();
    LOGV(nullptr, "fota_app_gp::onInit");
    return true;
}

bool fota_app_gp::onExit()
{
    ( void ) Application::onExit();
    LOGV(nullptr, "fota_app_gp::onExit");
    return true;
}

bool fota_app_gp::onStart()
{
    ( void ) Application::onStart();
    LOGV(nullptr, "fota_app_gp::onStart");
    threads.start(TID_gApp_runDispatchQueue);
    threads.start(TID_gApp_runIpcMessagePump);
    threads.start(TID_FotaAppGpCon_runMessagePump);
    return true;
}

bool fota_app_gp::onStop()
{
    ( void ) Application::onStop();
    LOGV(nullptr, "fota_app_gp::onStop");
    threads.stop(TID_FotaAppGpCon_runMessagePump);
    threads.stop(TID_gApp_runIpcMessagePump);
    threads.stop(TID_gApp_runDispatchQueue);
    return true;
}

int32_t fota_app_gp::onRun()
{
    ( void ) Application::onRun();
    LOGV(nullptr, "fota_app_gp::onRun");
    ( void ) mWdgIf.start(1000U);
    while (getIsRunning())
    {
        oUpdUclAdapterComponent.worker();
        oUpdDoipAdapterComponent.worker();

        //TODO: Make this configurable
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        mWdgIf.sendHeartbeat();
    }
    ( void ) mWdgIf.stop();

    return 0;
}


void fota_app_gp::sendUpdateShortServiceResp(UpdateShortServiceResp const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_UPDATESHORTSERVICERESP, COMPID_OUPDUCLADAPTERCOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.msgId);
    ( void ) pMsgSerIpc->serialize(msg.msgSize);
    ( void ) pMsgSerIpc->serialize(msg.sid);
    ( void ) pMsgSerIpc->serialize(msg.length);
    ( void ) pMsgSerIpc->serialize(msg.responseCode);
    ( void ) pMsgSerIpc->serialize(msg.NRC);
    for (uint16_t i0 = 0U; i0 < 64U; i0++)
    {
        ( void ) pMsgSerIpc->serialize(msg.data[i0]);
    }
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void fota_app_gp::sendDoIPDownloadResponse(DoIPDownloadResponse const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_DOIPDOWNLOADRESPONSE, COMPID_OUPDDOIPADAPTERCOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.serviceId);
    ( void ) pMsgSerIpc->serialize(msg.dataLen);
    for (uint16_t i0 = 0U; i0 < 7168U; i0++)
    {
        ( void ) pMsgSerIpc->serialize(msg.data[i0]);
    }
    ( void ) pMsgSerIpc->serialize(msg.result);
    gApp.sendMsgToIpc(pMsgSerIpc);
}


