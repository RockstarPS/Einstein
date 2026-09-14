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
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.1.4
// Date: Tue Oct 05 14:20:19 IST 2021
// User: SSHANKA8
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <chrono>
#include <thread>
#include "dk_runtime_thread_pool.h"
#include "network_test.h"
#include "network_test_component.h"

using namespace dk::runtime::core;

extern NetworkifAppComponent oNetworkifAppComponent;

bool networkif::onInit()
{
    ( void ) Application::onInit();
    LOGV(nullptr, "networkif::onInit");
    return true;
}

bool networkif::onExit()
{
    ( void ) Application::onExit();
    LOGV(nullptr, "networkif::onExit");
    return true;
}

bool networkif::onStart()
{
    ( void ) Application::onStart();
    LOGV(nullptr, "networkif::onStart");
    threads.start(TID_gApp_runDispatchQueue);
    threads.start(TID_gApp_runIpcMessagePump);
    threads.start(TID_networkIfContainer_runMessagePump);
    return true;
}

bool networkif::onStop()
{
    ( void ) Application::onStop();
    LOGV(nullptr, "networkif::onStop");
    threads.stop(TID_networkIfContainer_runMessagePump);
    threads.stop(TID_gApp_runIpcMessagePump);
    threads.stop(TID_gApp_runDispatchQueue);
    return true;
}

int32_t networkif::onRun()
{
    ( void ) Application::onRun();
    LOGV(nullptr, "networkif::onRun");
    ( void ) mWdgIf.start(1000U);
    while (getIsRunning())
    {
        oNetworkifAppComponent.worker();

        //TODO: Make this configurable
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        mWdgIf.sendHeartbeat();
    }
    ( void ) mWdgIf.stop();

    return 0;
}

void networkif::sendNetworkModifyInterface(NetworkModifyInterface const &msg)

{

    static uint8_t msgCnt = 0U;

    msgCnt++;

    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_NETWORKMODIFYINTERFACE, COMPID_ONETWORKIFAPPCOMPONENTTEST, msgCnt);

    ( void ) pMsgSerIpc->serialize(msg.requestType);

    ( void ) pMsgSerIpc->serialize(msg.interfaceNameLength);

    for (uint16_t i = 0; i < 256; i++)

    {

        (void)pMsgSerIpc->serialize(msg.interfaceName[i]);

    }

    ( void ) pMsgSerIpc->serialize(msg.linkStatus);

    ( void ) pMsgSerIpc->serialize(msg.ipAddressLength);

    for (uint16_t i = 0; i < 256; i++)

    {

        (void) pMsgSerIpc->serialize(msg.ipAddress[i]);

    }

    ( void ) pMsgSerIpc->serialize(msg.netMaskLength);

    for (uint16_t i = 0; i < 256; i++)

    {

        (void) pMsgSerIpc->serialize(msg.netMask[i]);

    }

    ( void ) pMsgSerIpc->serialize(msg.broadcastAddressLength);

    for (uint16_t i = 0; i < 256; i++)

    {

        (void) pMsgSerIpc->serialize(msg.broadcastAddress[i]);

    }

    gApp.sendMsgToIpc(pMsgSerIpc);

}



void networkif::sendNetworkModifyVlanInterface(NetworkModifyVlanInterface const & msg)
{
    static uint8_t msgCnt = 0U;
    msgCnt++;

    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_NETWORKMODIFYVLANINTERFACE, COMPID_ONETWORKIFAPPCOMPONENTTEST, msgCnt);

    ( void ) pMsgSerIpc->serialize(msg.requestType);
    ( void ) pMsgSerIpc->serialize(msg.vlanNameLength);
    for (uint16_t i0 = 0U; i0 < 256U; i0++)
    {
        ( void ) pMsgSerIpc->serialize(msg.vlanName[i0]);
    }
    ( void ) pMsgSerIpc->serialize(msg.vlanTag);
    ( void ) pMsgSerIpc->serialize(msg.interfaceNameLength);
    for (uint16_t i0 = 0U; i0 < 256U; i0++)
    {
        ( void ) pMsgSerIpc->serialize(msg.interfaceName[i0]);
    }
    ( void ) pMsgSerIpc->serialize(msg.vlanPriority);
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void networkif::sendNetworkModifyLinkStatus(NetworkModifyLinkStatus const &msg)
{
    static uint8_t msgCnt = 0U;

    msgCnt++;

    //IPC Routing. Generated if an component outside the application is expecting this message

    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_NETWORKMODIFYLINKSTATUS, COMPID_ONETWORKIFAPPCOMPONENTTEST, msgCnt);

    ( void ) pMsgSerIpc->serialize(msg.interfaceRequestType);

    ( void ) pMsgSerIpc->serialize(msg.interfaceNameLength);

    for (uint16_t i0 = 0U; i0 < 256U; i0++)
    {
        ( void ) pMsgSerIpc->serialize(msg.interfaceName[i0]);
    }

    gApp.sendMsgToIpc(pMsgSerIpc);
    

}




void networkif::sendEnetRegReq(EnetRegReq const &msg)

{

    static uint8_t msgCnt = 0U;

    msgCnt++;

    //IPC Routing. Generated if an component outside the application is expecting this message

    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_ENETREGREQ, COMPID_ONETWORKIFAPPCOMPONENTTEST, msgCnt);

    ( void ) pMsgSerIpc->serialize(msg.cmd);

    ( void ) pMsgSerIpc->serialize(msg.mode);

    ( void ) pMsgSerIpc->serialize(msg.dataLen);

    ( void ) pMsgSerIpc->serialize(msg.data[32]);


    gApp.sendMsgToIpc(pMsgSerIpc);

}




