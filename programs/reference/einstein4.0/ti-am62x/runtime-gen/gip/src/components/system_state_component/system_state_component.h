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
#ifndef SYSTEM_STATE_COMPONENT_H
#define SYSTEM_STATE_COMPONENT_H

#include <thread>
#include <map>
#include "dk_logger.h"
#include "dk_runtime_system_state_component.h"



using namespace dk::runtime;

class SystemStateComponent : public dk::runtime::core::Component
{
public:
    explicit SystemStateComponent(std::map<dk::runtime::core::mid_t, dk::runtime::core::func_t> * const pMsgMap, const char * const cmpId) : Component(pMsgMap, cmpId)
    {
    }

    virtual ~SystemStateComponent()
    {
    }

    virtual bool onInit();
    virtual bool onExit();
    virtual bool onStart();
    virtual bool onStop();
    void worker(void);

    void onReceivePowerSystemStateReqChange(PowerSystemStateReqChange const & msg);

    void onReceiveRTC(RTC const & msg);
    void onReceivePowerSystemStateReqWakeLock(PowerSystemStateReqWakeLock const & msg);

    void onReceivePowerReportCompState(PowerReportCompState const & msg);

    void onReceiveUclErrorNotify(UclErrorNotify const & msg);

    void onReceiveUclLinkStatus(UclLinkStatus const & msg);

    void onReceiveHealthGetStatus(HealthGetStatus const & msg);

private:
/// Start of user code : User code for file system_state_component.h

/// End of user code
};



#endif //SYSTEM_STATE_COMPONENT_H

