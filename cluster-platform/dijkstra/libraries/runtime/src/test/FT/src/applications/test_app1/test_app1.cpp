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
// Date: Wed Oct 21 19:36:46 IST 2020
// User: SSINGH25
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <chrono>
#include <thread>
#include "dk_runtime_thread_pool.h"
#include "test_app1.h"
#include "test_app1_comp1.h"
#include "test_app1_comp2.h"

using namespace dk::runtime::core;

extern test_app1_comp1 otest_app1_comp1;
extern test_app1_comp2 otest_app1_comp2;

bool testApp1::onInit()
{
    Application::onInit();
    LOGV(NULL, "testApp1::onInit");
    return true;
}

bool testApp1::onExit()
{
    Application::onExit();
    LOGV(NULL, "testApp1::onExit");
    return true;
}

bool testApp1::onStart()
{
    Application::onStart();
    LOGV(NULL, "testApp1::onStart");
    threads.start(TID_gApp_runDispatchQueue);
    threads.start(TID_gApp_runIpcMessagePump);
    threads.start(TID_test1AppCon_runMessagePump);
    threads.start(TID_test2AppCon_runMessagePump);
    return true;
}

bool testApp1::onStop()
{
    Application::onStop();
    LOGV(NULL, "testApp1::onStop");
    threads.stop(TID_test1AppCon_runMessagePump);
    threads.stop(TID_test2AppCon_runMessagePump);
    threads.stop(TID_gApp_runIpcMessagePump);
    threads.stop(TID_gApp_runDispatchQueue);
    return true;
}

int32_t testApp1::onRun()
{
    Application::onRun();
    LOGV(NULL, "testApp1::onRun");
    mWdgIf.start(1000U);
    while (getIsRunning())
    {
        otest_app1_comp1.worker();
        otest_app1_comp2.worker();

        //TODO: Make this configurable
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        mWdgIf.sendHeartbeat();
    }
    mWdgIf.stop();

    return 0;
}


void testApp1::sendDkMsgTestTransmitF64(DkMsgTestTransmitF64_t & msg)
{
    static uint8_t msgCnt = 0;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_DKMSGTESTTRANSMITF64, COMPID_OTEST_APP1_COMP1, msgCnt);


    pMsgSerIpc->serialize(msg.var_f64);
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void testApp1::sendDkMsgTestMsgTransmit(DkMsgTestTransmit_t & msg)
{
    static uint8_t msgCnt = 0;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_DKMSGTESTMSGTRANSMIT, COMPID_OTEST_APP1_COMP1, msgCnt);


    pMsgSerIpc->serialize(msg.var_uint8);
    pMsgSerIpc->serialize(msg.var_uint16);
    pMsgSerIpc->serialize(msg.var_bool);
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void testApp1::sendDkMsgTestTransmitU32(DkMsgTestTransmitU32_t & msg)
{
    static uint8_t msgCnt = 0;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_DKMSGTESTTRANSMITU32, COMPID_OTEST_APP1_COMP1, msgCnt);


    pMsgSerIpc->serialize(msg.var_u32);
    gApp.sendMsgToIpc(pMsgSerIpc);
}

void testApp1::sendDkMsgTest2Receive(DkMsgTest2Rcv_t & msg)
{
    static uint8_t msgCnt = 0;
    msgCnt++;

    //Local Routing. Generated if an component inside the application is expecting this message
    MsgSerializer *pMsgSer = new MsgSerializer(DK_MSG_DKMSGTEST2RECEIVE, COMPID_OTEST_APP1_COMP1, msgCnt);


    pMsgSer->serialize(msg.var_ru8);
    pMsgSer->serialize(msg.var_ru16);
    gApp.sendMsgToDisplatchQueue(pMsgSer);

}

void testApp1::sendDkMsgTestApp2Receive(DkMsgTestTransmit_t & msg)
{
    static uint8_t msgCnt = 0;
    msgCnt++;


    //IPC Routing. Generated if an component outside the application is expecting this message
    std::shared_ptr<MsgSerializer> pMsgSerIpc = std::make_shared<MsgSerializer>(DK_MSG_DKMSGTESTAPP2RECEIVE, COMPID_OTEST_APP1_COMP2, msgCnt);


    pMsgSerIpc->serialize(msg.var_uint8);
    pMsgSerIpc->serialize(msg.var_uint16);
    pMsgSerIpc->serialize(msg.var_bool);
    gApp.sendMsgToIpc(pMsgSerIpc);
}


