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
// Date: Sun Nov 01 21:09:51 IST 2020
// User: SSINGH25
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <chrono>
#include <thread>
#include "dk_runtime_thread_pool.h"
#include "t4_app.h"
#include "t11.h"
#include "t12.h"
#include "t21.h"
#include "t22.h"

using namespace dk::runtime::core;

extern T11 oT11;
extern T12 oT12;
extern T21 oT21;
extern T22 oT22;

bool T4App::onInit()
{
    Application::onInit();
    LOGV(NULL, "T4App::onInit");
    return true;
}

bool T4App::onExit()
{
    Application::onExit();
    LOGV(NULL, "T4App::onExit");
    return true;
}

bool T4App::onStart()
{
    Application::onStart();
    LOGV(NULL, "T4App::onStart");
    threads.start(TID_gApp_runDispatchQueue);
    threads.start(TID_gApp_runIpcMessagePump);
    threads.start(TID_T4CON1_runMessagePump);
    threads.start(TID_T4CON2_runMessagePump);
    return true;
}

bool T4App::onStop()
{
    Application::onStop();
    LOGV(NULL, "T4App::onStop");
    threads.stop(TID_T4CON1_runMessagePump);
    threads.stop(TID_T4CON2_runMessagePump);
    threads.stop(TID_gApp_runIpcMessagePump);
    threads.stop(TID_gApp_runDispatchQueue);
    return true;
}

int32_t T4App::onRun()
{
    Application::onRun();
    LOGV(NULL, "T4App::onRun");
    mWdgIf.start(1000U);
    while (getIsRunning())
    {
        oT11.worker();
        oT12.worker();
        oT21.worker();
        oT22.worker();

        //TODO: Make this configurable
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        mWdgIf.sendHeartbeat();
    }
    mWdgIf.stop();

    return 0;
}


void T4App::sendDkMsgT4Con1Comp1P(DkMsg1byte_t & msg)
{
    static uint8_t msgCnt = 0;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_DKMSGT4CON1COMP1P, COMPID_OT11, msgCnt);


    pMsgSerIpc->serialize(msg.uint8_t);
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void T4App::sendDkMsgT4Con1comp1Tx(DkMsg1byte_t & msg)
{
    static uint8_t msgCnt = 0;
    msgCnt++;

    //Local Routing. Generated if an component inside the application is expecting this message
    MsgSerializer *pMsgSer = new MsgSerializer(DK_MSG_DKMSGT4CON1COMP1TX, COMPID_OT11, msgCnt);


    pMsgSer->serialize(msg.uint8_t);
    gApp.sendMsgToDisplatchQueue(pMsgSer);

}

void T4App::sendDkMsgT4Con1Comp2P(DkMsg1byte_t & msg)
{
    static uint8_t msgCnt = 0;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_DKMSGT4CON1COMP2P, COMPID_OT12, msgCnt);


    pMsgSerIpc->serialize(msg.uint8_t);
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void T4App::sendDkMsgT4Con1Comp2Tx(DkMsg1byte_t & msg)
{
    static uint8_t msgCnt = 0;
    msgCnt++;

    //Local Routing. Generated if an component inside the application is expecting this message
    MsgSerializer *pMsgSer = new MsgSerializer(DK_MSG_DKMSGT4CON1COMP2TX, COMPID_OT12, msgCnt);


    pMsgSer->serialize(msg.uint8_t);
    gApp.sendMsgToDisplatchQueue(pMsgSer);

}

void T4App::sendDkMsgT4Con2Comp1P(DkMsg1byte_t & msg)
{
    static uint8_t msgCnt = 0;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_DKMSGT4CON2COMP1P, COMPID_OT21, msgCnt);


    pMsgSerIpc->serialize(msg.uint8_t);
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void T4App::sendDkMsgT4Con2Comp2P(DkMsg1byte_t & msg)
{
    static uint8_t msgCnt = 0;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_DKMSGT4CON2COMP2P, COMPID_OT22, msgCnt);


    pMsgSerIpc->serialize(msg.uint8_t);
    gApp.sendMsgToIpc(pMsgSerIpc);
}


