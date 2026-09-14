//---------------------------------------------------------------------------------------------------------------------
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
// File generated automatically using Visteon VMF & Dijkstra Runtime configuration generator 1.2.1
// Date: Thu Aug 29 18:01:58 IST 2024
// User: KRAMESH5
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <iterator>     ///< std::back_inserter
#include <algorithm>    ///< (void) std::copy
#include "meet_component.h"

LOG_DECLARE_CONTEXT ( gMEETLogContext );

namespace dk
{
namespace lib
{
namespace meet
{

bool MeetComponent::onInit()
{
    int32_t taskReg;

    bool ret = Component::onInit();;

    /// Start of user code : User code for function onInit in file meet_component.cpp
    LOG_REGISTER_CONTEXT ( gMEETLogContext, "MEET",  "MEET Comp", DLT_LOG_VERBOSE );

    LOGI ( &gMEETLogContext, "MEET::onInit" );

    taskReg = registerTask ( [ = ]()
    {
        MeetPeriodicTask();
    }, static_cast<uint32_t>(MEET_COMPONENT_PERIODIC_TIMER_IN_MS));

    if(taskReg < 0)
    {
        LOGE ( &gMEETLogContext, "task not registered","MeetPeriodicTask " );
    }

    return ret;
}

bool MeetComponent::onExit()
{
    bool ret = Component::onExit();

    /// Start of user code : User code for function onExit in file meet_component.cpp
    LOGI ( &gMEETLogContext, "MEET::onExit" );
    /// End of user code

    return ret;
}

bool MeetComponent::onStart()
{

    bool ret = Component::onStart();

    /// Start of user code : User code for function onStart in file meet_component.cpp
    LOGI ( &gMEETLogContext, "MEET::onStart" );
    /// End of user code
    mpDiagReqSem = new osal::Semaphore ( 0U );
    mMeetAppIsRunning = true;
    mpMeetHandlerObj.reset ( new MeetAppHandler(*this) );
    mpMeetHandlerObj->Init();

    mpPthreadDiagReq = new std::thread ( [this]()
    {
        this->diagParseRequest();
    } );

    return ret;
}

bool MeetComponent::onStop()
{
    bool ret = Component::onStop();

    /// Start of user code : User code for function onStart in file meet_component.cpp
    LOGI ( &gMEETLogContext, "MEET::onStop" );

    mpMeetHandlerObj->Stop();
    /// End of user code
    mMeetAppIsRunning = false;
    ///<wait for thread to join
    mpPthreadDiagReq->join();
    delete mpPthreadDiagReq;
    LOGI ( &gMEETLogContext, "DiagParseRequest Thread is Cleared" );
    mpPthreadDiagReq = nullptr;
    ///< Delete semaphore
    delete mpDiagReqSem;

    return ret;
}

void MeetComponent::worker()
{
    /// Start of user code : User code for function worker in file meet_component.cpp

    /// End of user code
}


void MeetComponent::onReceiveDiagIOCtrlRequest ( DiagIOCtrlRequest const &msg )
{
    std::lock_guard<std::mutex> guard ( mMeetRcvMsgMutex );
    SDiagReqMsg lDiagReqMsg;

    lDiagReqMsg.didId = msg.did;
    lDiagReqMsg.mode = EDiagMode_IOCtrl;
    lDiagReqMsg.controlMode = msg.optionCtrl;

    LOGI ( &gMEETLogContext, " IO Control DID  Received:  ", msg.did, "Length of Did is", msg.dataLen, "the value is", msg.data[0] );

    if ( msg.dataLen <= sizeof ( msg.data ) )
    {
        (void) std::copy ( &msg.data[0], &msg.data[msg.dataLen], std::back_inserter ( lDiagReqMsg.data ) );
        mDiagReqMsgData.push_back ( lDiagReqMsg );
        mpDiagReqSem->post();
    }
    else
    {
        LOGE ( &gMEETLogContext, "Invalid Length received  for IOCtrl DID : ", msg.did, "DID length", msg.dataLen );
    }

}

void MeetComponent::onReceiveDiagRoutineRequest(DiagRoutineRequest const  & msg)
{
    std::lock_guard<std::mutex> guard ( mMeetRcvMsgMutex );
    SDiagReqMsg lDiagReqMsg;

    lDiagReqMsg.didId = msg.routineId;
    lDiagReqMsg.mode = EDiagMode_RC;
    lDiagReqMsg.controlMode = msg.routineType;

    if ( msg.dataLen <= sizeof ( msg.data ) )
    {
        LOGI ( &gMEETLogContext, " Routine Control DID  Received:  ", msg.routineId, "Length of Did is", msg.dataLen );
        (void) std::copy ( &msg.data[0],  &msg.data[msg.dataLen], std::back_inserter ( lDiagReqMsg.data ) );

        mDiagReqMsgData.push_back ( lDiagReqMsg);
        mpDiagReqSem->post();
    }
    else
    {
        LOGE ( &gMEETLogContext, "Invalid length received for Routine Control DID : ", msg.routineId, "DID length", msg.dataLen );
    }
}

void MeetComponent::onReceiveDiagDIDRequest ( DiagDIDRequest const &msg )
{
    std::lock_guard<std::mutex> guard ( mMeetRcvMsgMutex );
    MeetRetType lStatus = 0;
    SDiagReqMsg lDiagReqMsg = {0U};
    lDiagReqMsg.didId = msg.did;

    if ( msg.didType == EDidType_Read   )
    {
        lDiagReqMsg.mode = EDiagMode_RW_Read;
        LOGI ( &gMEETLogContext, " Read DID received " );

    }
    else if ( msg.didType == EDidType_Write )
    {
        lDiagReqMsg.mode = EDiagMode_RW_Write;
    }
    else
    {
        lStatus = -1;
        LOGE ( &gMEETLogContext, "Invalid R-W Mode" );
    }

    if ( 0  == lStatus )
    {
        if ( msg.dataLen <= sizeof ( msg.data ) )
        {
            LOGI ( &gMEETLogContext, " Read Write  DID  Received:  ", msg.did, "Length of Did is", msg.dataLen );
            (void) std::copy ( &msg.data[0], &msg.data[ msg.dataLen], std::back_inserter ( lDiagReqMsg.data ) );
            mDiagReqMsgData.push_back ( lDiagReqMsg );
            mpDiagReqSem->post();
        }
    }

}


void MeetComponent::MeetPeriodicTask ( void )
{
    if(mpMeetHandlerObj)
    {
        mpMeetHandlerObj->periodicTask( );
    }
    else
    {
        LOGE ( &gMEETLogContext, "MEET Handler object not created : ");
    }
}


void MeetComponent::diagParseRequest()
{
    while ( mMeetAppIsRunning == true )
    {
        ///< Semaphore timeout set at 200mS
        if ( mpDiagReqSem->timedWaitMS ( 200U ) )
        {
            LOGI ( &gMEETLogContext, "semaphore unblocked");
            if ( mDiagReqMsgData.size() > 0U )
            {

                DiagReqMsgData_t lDiagReqMsgData;
                {
                    std::lock_guard<std::mutex> guard ( mMeetRcvMsgMutex );
                    lDiagReqMsgData = mDiagReqMsgData;
                    // clear the map files
                    LOGI ( &gMEETLogContext, "requests handled in diag parse request: ");
                    mDiagReqMsgData.clear();

                }

                if(mpMeetHandlerObj)
                {
                    mpMeetHandlerObj->processDiagRcv(lDiagReqMsgData);
                    LOGI ( &gMEETLogContext, "sent data to meet handler");
                }
                else
                {
                    LOGE ( &gMEETLogContext, "MEET Handler object not created : ");
                }
            }
            else
            {
                LOGI ( &gMEETLogContext, "No Data available : ");
            }
        }
    }
}

void MeetComponent::SendDiagReponse ( const uint16 didId, const EDiagMode_t mode, std::vector<uint8_t> data, const diagResType responseCode )
{
    DiagResponse lRespMsg = {0x0U};

    // Send Routine Activation
    switch ( mode )
    {
    case  EDiagMode_RW_Read:
    case  EDiagMode_RW_Write:

        lRespMsg.responseCode = static_cast<uint8>(responseCode);
        lRespMsg.data[0] = mode;
        lRespMsg.data[1] = static_cast<uint8>( didId   & 0xffU );
        lRespMsg.data[2] = static_cast<uint8> ( (didId >> 8U )  & 0xffU);
        lRespMsg.dataLen = static_cast<uint16>(data.size())  + DID_ID_OFFSET;

        if ( lRespMsg.dataLen <= ( sizeof ( data_u8_256 ) - DID_ID_OFFSET ) )
        {
            (void) std::copy ( data.begin(), data.end(), &lRespMsg.data[DID_ID_OFFSET] ); // first three bytes allocated for UDS MODE & DID ID
            DK_RTE_Send_DiagResponse ( lRespMsg );
        }

        break;


    case  EDiagMode_RC:

        lRespMsg.responseCode = static_cast<uint8>(responseCode);
        lRespMsg.data[0] = mode;
        lRespMsg.data[1] = static_cast<uint8>( didId   & 0xffU );
        lRespMsg.data[2] = static_cast<uint8> ( (didId >> 8U )  & 0xffU);
        lRespMsg.dataLen = static_cast<uint16>(data.size())+ DID_ID_OFFSET;

        if ( lRespMsg.dataLen <= ( sizeof ( data_u8_256 ) - DID_ID_OFFSET ) )
        {
            (void) std::copy ( data.begin(), data.end(), &lRespMsg.data[DID_ID_OFFSET] ); // first three bytes allocated for UDS MODE & DID ID
            DK_RTE_Send_DiagResponse ( lRespMsg );
        }

        break;

    case EDiagMode_IOCtrl:

        lRespMsg.responseCode = static_cast<uint8>(responseCode);
        lRespMsg.data[0] = mode;
        lRespMsg.data[1] = static_cast<uint8>( didId   & 0xffU );
        lRespMsg.data[2] = static_cast<uint8>( (didId >> 8U )  & 0xffU);
        lRespMsg.dataLen = static_cast<uint16>(data.size()) + DID_ID_OFFSET;

        if ( lRespMsg.dataLen <= ( sizeof ( data_u8_256 ) - DID_ID_OFFSET ) )
        {
            (void) std::copy ( data.begin(), data.end(), &lRespMsg.data[DID_ID_OFFSET] ); // first three bytes allocated for UDS MODE & DID ID
            DK_RTE_Send_DiagResponse ( lRespMsg );
        }

        break;

    default:
        break;

    }

    LOGI ( &gMEETLogContext, "Response Send for DId Id", didId );

}

void MeetComponent::onReceivePowerSystemState(PowerSystemState const  & msg)
{
/// Start of user code : User code for function onReceivePowerSystemState in file meet_component.cpp

    if(msg.state == ESystemState_Meet)
    {
        mpMeetHandlerObj -> stopHmi();
    }
/// End of user code
}

} // meet
} // lib
} // dk

/// Start of user code : Footer user code for file meet_component.cpp

/// End of user code

