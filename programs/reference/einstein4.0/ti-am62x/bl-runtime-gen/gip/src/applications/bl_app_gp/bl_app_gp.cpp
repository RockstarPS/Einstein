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
// Date: Fri May 15 11:55:46 IST 2026
// User: GSOUNDAR
// System: GIP
// Configuration: Platform_Recovery
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.9
//
//---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <chrono>
#include <thread>
#include "dk_runtime_thread_pool.h"
#include "bl_app_gp.h"
#include "bl_einstein_uds_app_component.h"
#include "bl_upd_doip_adapter_component.h"
#include "bl_upd_ucl_adapter_component.h"
#include "uds_core_component.h"
#include "doip_component.h"

using namespace dk::runtime::core;
using namespace dk::srvc::udscore;
using namespace dk::app::udsblservices;

extern BlEinsteinUdsAppComponent oBlEinsteinUdsAppComponent;
extern BlUpdDoipAdapterComponent oBlUpdDoipAdapterComponent;
extern BlUpdUclAdapterComponent oBlUpdUclAdapterComponent;
extern UdsCoreComponent oUdsCoreComponent;
extern DoipComponent oDoipComponent;

bool bl_app_gp::onInit()
{
    ( void ) Application::onInit();
    LOGV(nullptr, "bl_app_gp::onInit");
    return true;
}

bool bl_app_gp::onExit()
{
    ( void ) Application::onExit();
    LOGV(nullptr, "bl_app_gp::onExit");
    return true;
}

bool bl_app_gp::onStart()
{
    ( void ) Application::onStart();
    LOGV(nullptr, "bl_app_gp::onStart");
    threads.start(TID_gApp_runDispatchQueue);
    threads.start(TID_gApp_runIpcMessagePump);
    threads.start(TID_BlAppGpCon_runMessagePump);
    return true;
}

bool bl_app_gp::onStop()
{
    ( void ) Application::onStop();
    LOGV(nullptr, "bl_app_gp::onStop");
    threads.stop(TID_BlAppGpCon_runMessagePump);
    threads.stop(TID_gApp_runIpcMessagePump);
    threads.stop(TID_gApp_runDispatchQueue);
    return true;
}

int32_t bl_app_gp::onRun()
{
    ( void ) Application::onRun();
    LOGV(nullptr, "bl_app_gp::onRun");
    ( void ) mWdgIf.start(1000U);
    while (getIsRunning())
    {
        oBlEinsteinUdsAppComponent.worker();
        oBlUpdDoipAdapterComponent.worker();
        oBlUpdUclAdapterComponent.worker();
        oUdsCoreComponent.worker();
        oDoipComponent.worker();

        //TODO: Make this configurable
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        mWdgIf.sendHeartbeat();
    }
    ( void ) mWdgIf.stop();

    return 0;
}


void bl_app_gp::sendDoIPDownloadRequest(DoIPDownloadRequest const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;

    //Local Routing. Generated if an component inside the application is expecting this message
    MsgSerializer * const pMsgSer = new MsgSerializer(DK_MSG_DOIPDOWNLOADREQUEST, COMPID_OBLEINSTEINUDSAPPCOMPONENT, msgCnt);


    ( void ) pMsgSer->serialize(msg.serviceId);
    ( void ) pMsgSer->serialize(msg.blkaddress);
    ( void ) pMsgSer->serialize(msg.blklength);
    ( void ) pMsgSer->serialize(msg.formatId);
    ( void ) pMsgSer->serialize(msg.CompEncId);
    ( void ) pMsgSer->serialize(msg.dataLen);
    for (uint16_t i0 = 0U; i0 < 7168U; i0++)
    {
        ( void ) pMsgSer->serialize(msg.data[i0]);
    }
    gApp.sendMsgToDisplatchQueue(pMsgSer);

    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_DOIPDOWNLOADREQUEST, COMPID_OBLEINSTEINUDSAPPCOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.serviceId);
    ( void ) pMsgSerIpc->serialize(msg.blkaddress);
    ( void ) pMsgSerIpc->serialize(msg.blklength);
    ( void ) pMsgSerIpc->serialize(msg.formatId);
    ( void ) pMsgSerIpc->serialize(msg.CompEncId);
    ( void ) pMsgSerIpc->serialize(msg.dataLen);
    for (uint16_t i0 = 0U; i0 < 7168U; i0++)
    {
        ( void ) pMsgSerIpc->serialize(msg.data[i0]);
    }
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void bl_app_gp::sendDoipSetParams(DoipSetParams const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;

    //Local Routing. Generated if an component inside the application is expecting this message
    MsgSerializer * const pMsgSer = new MsgSerializer(DK_MSG_DOIPSETPARAMS, COMPID_OBLEINSTEINUDSAPPCOMPONENT, msgCnt);


    ( void ) pMsgSer->serialize(msg.isVinNumValid);
    ( void ) pMsgSer->serialize(msg.isGidNumValid);
    ( void ) pMsgSer->serialize(msg.isEidNumValid);
    for (uint16_t i0 = 0U; i0 < 17U; i0++)
    {
        ( void ) pMsgSer->serialize(msg.vinNumber[i0]);
    }
    for (uint16_t i0 = 0U; i0 < 6U; i0++)
    {
        ( void ) pMsgSer->serialize(msg.eidNumber[i0]);
    }
    for (uint16_t i0 = 0U; i0 < 6U; i0++)
    {
        ( void ) pMsgSer->serialize(msg.gidNumber[i0]);
    }
    ( void ) pMsgSer->serialize(msg.ipConfig.ipAddressNetwork1);
    ( void ) pMsgSer->serialize(msg.ipConfig.ipAddressNetwork2);
    ( void ) pMsgSer->serialize(msg.ipConfig.ipAddressHost1);
    ( void ) pMsgSer->serialize(msg.ipConfig.ipAddressHost2);
    ( void ) pMsgSer->serialize(msg.ipConfig.portNum);
    ( void ) pMsgSer->serialize(msg.isNetWorkConfigValid);
    ( void ) pMsgSer->serialize(msg.gidSyncStatus);
    ( void ) pMsgSer->serialize(msg.isGidSyncStatusValid);
    gApp.sendMsgToDisplatchQueue(pMsgSer);

}

void bl_app_gp::sendDoipDiagPowerModeStatus(DoipDiagPowerModeStatus const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;

    //Local Routing. Generated if an component inside the application is expecting this message
    MsgSerializer * const pMsgSer = new MsgSerializer(DK_MSG_DOIPDIAGPOWERMODESTATUS, COMPID_OBLEINSTEINUDSAPPCOMPONENT, msgCnt);


    ( void ) pMsgSer->serialize(msg.powerMode);
    gApp.sendMsgToDisplatchQueue(pMsgSer);

}

void bl_app_gp::sendUdsServiceResponseTransmitRequest(UdsServiceResponseTransmitRequest const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;

    //Local Routing. Generated if an component inside the application is expecting this message
    MsgSerializer * const pMsgSer = new MsgSerializer(DK_MSG_UDSSERVICERESPONSETRANSMITREQUEST, COMPID_OBLEINSTEINUDSAPPCOMPONENT, msgCnt);


    ( void ) pMsgSer->serialize(msg.serviceId);
    ( void ) pMsgSer->serialize(msg.responseType);
    ( void ) pMsgSer->serialize(msg.clientAddress);
    ( void ) pMsgSer->serialize(msg.dataLen);
    for (uint16_t i0 = 0U; i0 < 7168U; i0++)
    {
        ( void ) pMsgSer->serialize(msg.data[i0]);
    }
    gApp.sendMsgToDisplatchQueue(pMsgSer);

}

void bl_app_gp::sendUdsServiceSetTimings(UdsServiceSetTimings const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;

    //Local Routing. Generated if an component inside the application is expecting this message
    MsgSerializer * const pMsgSer = new MsgSerializer(DK_MSG_UDSSERVICESETTIMINGS, COMPID_OBLEINSTEINUDSAPPCOMPONENT, msgCnt);


    ( void ) pMsgSer->serialize(msg.p2TimeMs);
    ( void ) pMsgSer->serialize(msg.p2StarTimeMs);
    ( void ) pMsgSer->serialize(msg.p4TimeMs);
    gApp.sendMsgToDisplatchQueue(pMsgSer);

}

void bl_app_gp::sendDoIPDownloadResponse(DoIPDownloadResponse const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;

    //Local Routing. Generated if an component inside the application is expecting this message
    MsgSerializer * const pMsgSer = new MsgSerializer(DK_MSG_DOIPDOWNLOADRESPONSE, COMPID_OBLUPDDOIPADAPTERCOMPONENT, msgCnt);


    ( void ) pMsgSer->serialize(msg.serviceId);
    ( void ) pMsgSer->serialize(msg.dataLen);
    for (uint16_t i0 = 0U; i0 < 7168U; i0++)
    {
        ( void ) pMsgSer->serialize(msg.data[i0]);
    }
    ( void ) pMsgSer->serialize(msg.result);
    gApp.sendMsgToDisplatchQueue(pMsgSer);

    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_DOIPDOWNLOADRESPONSE, COMPID_OBLUPDDOIPADAPTERCOMPONENT, msgCnt);


    ( void ) pMsgSerIpc->serialize(msg.serviceId);
    ( void ) pMsgSerIpc->serialize(msg.dataLen);
    for (uint16_t i0 = 0U; i0 < 7168U; i0++)
    {
        ( void ) pMsgSerIpc->serialize(msg.data[i0]);
    }
    ( void ) pMsgSerIpc->serialize(msg.result);
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void bl_app_gp::sendUpdateShortServiceResp(UpdateShortServiceResp const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_UPDATESHORTSERVICERESP, COMPID_OBLUPDUCLADAPTERCOMPONENT, msgCnt);


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

void bl_app_gp::sendDoipDiagDataTransferRequest(DoipDiagDataTransferRequest const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;

    //Local Routing. Generated if an component inside the application is expecting this message
    MsgSerializer * const pMsgSer = new MsgSerializer(DK_MSG_DOIPDIAGDATATRANSFERREQUEST, COMPID_OUDSCORECOMPONENT, msgCnt);


    ( void ) pMsgSer->serialize(msg.sourceAddress);
    ( void ) pMsgSer->serialize(msg.targetAddress);
    ( void ) pMsgSer->serialize(msg.targetAddressType);
    ( void ) pMsgSer->serialize(msg.dataLen);
    for (uint16_t i0 = 0U; i0 < 7168U; i0++)
    {
        ( void ) pMsgSer->serialize(msg.data[i0]);
    }
    ( void ) pMsgSer->serialize(msg.result);
    gApp.sendMsgToDisplatchQueue(pMsgSer);

}

void bl_app_gp::sendUdsTimeout(UdsTimeout const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;

    //Local Routing. Generated if an component inside the application is expecting this message
    MsgSerializer * const pMsgSer = new MsgSerializer(DK_MSG_UDSTIMEOUT, COMPID_OUDSCORECOMPONENT, msgCnt);


    ( void ) pMsgSer->serialize(msg.timeoutType);
    ( void ) pMsgSer->serialize(msg.clientAddress);
    gApp.sendMsgToDisplatchQueue(pMsgSer);

}

void bl_app_gp::sendUdsServiceResponseTransmitConfirmation(UdsServiceResponseTransmitConfirmation const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;

    //Local Routing. Generated if an component inside the application is expecting this message
    MsgSerializer * const pMsgSer = new MsgSerializer(DK_MSG_UDSSERVICERESPONSETRANSMITCONFIRMATION, COMPID_OUDSCORECOMPONENT, msgCnt);


    ( void ) pMsgSer->serialize(msg.serviceId);
    ( void ) pMsgSer->serialize(msg.responseType);
    ( void ) pMsgSer->serialize(msg.clientAddress);
    gApp.sendMsgToDisplatchQueue(pMsgSer);

}

void bl_app_gp::sendUdsServiceReqIndication(UdsServiceReqIndication const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;

    //Local Routing. Generated if an component inside the application is expecting this message
    MsgSerializer * const pMsgSer = new MsgSerializer(DK_MSG_UDSSERVICEREQINDICATION, COMPID_OUDSCORECOMPONENT, msgCnt);


    ( void ) pMsgSer->serialize(msg.serviceId);
    ( void ) pMsgSer->serialize(msg.requestType);
    ( void ) pMsgSer->serialize(msg.clientAddress);
    ( void ) pMsgSer->serialize(msg.dataLen);
    for (uint16_t i0 = 0U; i0 < 7168U; i0++)
    {
        ( void ) pMsgSer->serialize(msg.data[i0]);
    }
    gApp.sendMsgToDisplatchQueue(pMsgSer);

}

void bl_app_gp::sendDoipDiagDataIndication(DoipDiagDataIndication const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;

    //Local Routing. Generated if an component inside the application is expecting this message
    MsgSerializer * const pMsgSer = new MsgSerializer(DK_MSG_DOIPDIAGDATAINDICATION, COMPID_ODOIPCOMPONENT, msgCnt);


    ( void ) pMsgSer->serialize(msg.sourceAddress);
    ( void ) pMsgSer->serialize(msg.targetAddress);
    ( void ) pMsgSer->serialize(msg.targetAddressType);
    ( void ) pMsgSer->serialize(msg.dataLen);
    for (uint16_t i0 = 0U; i0 < 7168U; i0++)
    {
        ( void ) pMsgSer->serialize(msg.data[i0]);
    }
    ( void ) pMsgSer->serialize(msg.result);
    gApp.sendMsgToDisplatchQueue(pMsgSer);

}

void bl_app_gp::sendDoipDiagDataConfirmation(DoipDiagDataConfirmation const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;

    //Local Routing. Generated if an component inside the application is expecting this message
    MsgSerializer * const pMsgSer = new MsgSerializer(DK_MSG_DOIPDIAGDATACONFIRMATION, COMPID_ODOIPCOMPONENT, msgCnt);


    ( void ) pMsgSer->serialize(msg.targetAddress);
    ( void ) pMsgSer->serialize(msg.sourceAddress);
    ( void ) pMsgSer->serialize(msg.targetAddressType);
    ( void ) pMsgSer->serialize(msg.result);
    gApp.sendMsgToDisplatchQueue(pMsgSer);

}


