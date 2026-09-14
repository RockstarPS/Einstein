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
#ifndef MEET_COMPONENT_H
#define MEET_COMPONENT_H

#include <thread>
#include "dk_runtime_meet_component.h"
#include "dk_runtime_parserif.h"
#include <cstddef>
#include <iostream>
#include "meet_application_handler.h"
#include <condition_variable>


namespace dk
{
namespace lib
{
namespace meet
{


class MeetComponent : public dk::runtime::core::Component
{
public:
    explicit MeetComponent(std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> * const pMsgMap, const char * const cmpId) : Component(pMsgMap, cmpId)
    {

        mMeetAppIsRunning = false;
        mpPthreadDiagReq = nullptr;
    }

    virtual ~MeetComponent()
    {
    }

    virtual bool onInit();
    virtual bool onExit();
    virtual bool onStart();
    virtual bool onStop();
    void worker(void);

    void onReceiveDiagRoutineRequest(DiagRoutineRequest const & msg);

    void onReceiveDiagIOCtrlRequest(DiagIOCtrlRequest const & msg);

    void onReceiveDiagDIDRequest(DiagDIDRequest const & msg);
    void onReceivePowerSystemState(PowerSystemState const & msg);
    void SendDiagReponse (  const uint16 didId, const EDiagMode_t mode, std::vector<uint8_t> data, const diagResType responseCode  );
private:

    const uint8_t DID_ID_OFFSET = 3U;
    const uint8_t MEET_COMPONENT_PERIODIC_TIMER_IN_MS =  10U;
    std::thread *mpPthreadDiagReq;         ///< Periodic Task Thread
    osal::Semaphore *mpDiagReqSem = nullptr;
    std::mutex mMeetRcvMsgMutex;
    bool mMeetAppIsRunning;
    std::unique_ptr< MeetAppHandler> mpMeetHandlerObj;
    DiagReqMsgData_t mDiagReqMsgData;

    void diagParseRequest ( void );
    void MeetPeriodicTask ( void );
};

} // meet
} // lib
} // dk

#endif //MEET_COMPONENT_H

