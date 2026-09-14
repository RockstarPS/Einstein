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
// Date: Fri Oct 01 07:04:51 IST 2021
// User: IRAJENDR
// System: GIP
//
//---------------------------------------------------------------------------------------------------------------------
#include "system_state_component.h"

/// Start of user code : Header user code for file system_state_component.cpp
LOG_DECLARE_CONTEXT(gSSMLogContext);
/// End of user code



bool SystemStateComponent::onInit()
{
    bool ret = Component::onInit();

/// Start of user code : User code for function onInit in file system_state_component.cpp
    LOG_REGISTER_CONTEXT(gSSMLogContext, "SYSM", "System State Manager Component", DLT_LOG_VERBOSE);
    LOGV(&gSSMLogContext, "Enter");

    ret = mSystemStateObj.onInit();
    (void)registerTask([=]() { periodicTask_100ms(); }, mSystemStatePeriodicTimerMs);
/// End of user code

    return ret;
}

bool SystemStateComponent::onExit()
{
    bool ret = Component::onExit();

/// Start of user code : User code for function onExit in file system_state_component.cpp
    LOGV(&gSSMLogContext, "Enter");
    ret = mSystemStateObj.onExit();

    LOG_UNREGISTER_CONTEXT(gSSMLogContext);
/// End of user code

    return ret;
}

bool SystemStateComponent::onStart()
{
    bool ret = Component::onStart();

/// Start of user code : User code for function onStart in file system_state_component.cpp
    LOGV(&gSSMLogContext, "Enter");
    ret = mSystemStateObj.onStart();
/// End of user code

    return ret;
}

bool SystemStateComponent::onStop()
{
    bool ret = Component::onStop();

/// Start of user code : User code for function onStop in file system_state_component.cpp
    LOGV(&gSSMLogContext, "Enter");
    ret = mSystemStateObj.onStop();
/// End of user code

    return ret;
}

void SystemStateComponent::worker()
{
/// Start of user code : User code for function worker in file system_state_component.cpp

/// End of user code
}

void SystemStateComponent::onReceivePowerSystemStateReqChange(PowerSystemStateReqChange const  & msg)
{
/// Start of user code : User code for function onReceivePowerSystemStateReqChange in file system_state_component.cpp
    LOGV(&gSSMLogContext, "Enter");
    if( msg.domainId == mSystemStateObj.getDomainId() )
    {
        mSystemStateObj.requestStateChange(msg.state);
    }
/// End of user code
}

void SystemStateComponent::onReceivePowerReportCompState(PowerReportCompState const  & msg)
{
/// Start of user code : User code for function onReceivePowerReportCompState in file system_state_component.cpp
    LOGV(&gSSMLogContext, "Enter");
    mSystemStateObj.setCompState(msg.base.compId, msg.state);
/// End of user code
}

void SystemStateComponent::onReceiveUclErrorNotify(UCL_ERROR_NOTIFY const  & msg)
{
/// Start of user code : User code for function onReceiveUclErrorNotify in file system_state_component.cpp
    /*Touch unused variable*/
    (void)msg;
/// End of user code
}

void SystemStateComponent::onReceiveUclLinkStatus(UCL_LINK_STATUS const  & msg)
{
/// Start of user code : User code for function onReceiveUclLinkStatus in file system_state_component.cpp
    LOGV(&gSSMLogContext, "Enter");
    mSystemStateObj.setCommLinkStatus(msg.status);
/// End of user code
}

void SystemStateComponent::onReceivePowerSystemStateReqWakeLock(PowerSystemStateReqWakeLock const  & msg)
{
/// Start of user code : User code for function onReceivePowerSystemStateReqWakeLock in file system_state_component.cpp
    LOGV(&gSSMLogContext, "Enter");
    mSystemStateObj.requestWakeLock(msg.base.compId, msg.enable, msg.requiredTimeMs);
/// End of user code
}

void SystemStateComponent::onReceiveRTC(RTC const  & msg)
{
/// Start of user code : User code for function onReceiveRTC in file system_state_component.cpp
    /*Touch unused variable*/
    (void)msg;
/// End of user code
}

void SystemStateComponent::onReceiveHealthGetStatus(HealthGetStatus const  & msg)
{
/// Start of user code : User code for function onReceiveHealthGetStatus in file system_state_component.cpp
    /*Touch unused argument*/
    (void)msg;
    LOGV(&gSSMLogContext, "Enter");
    mSystemStateObj.sendStatusReport();
/// End of user code
}



/// Start of user code : Footer user code for file system_state_component.cpp
void SystemStateComponent::periodicTask_100ms(void)
{
    mSystemStateObj.periodicTask(static_cast<uint16_t>(mSystemStatePeriodicTimerMs));
}
/// End of user code

