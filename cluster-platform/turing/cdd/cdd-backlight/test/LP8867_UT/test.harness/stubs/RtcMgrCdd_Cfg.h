//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2020] Visteon Corporation
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

#ifndef RTCMGRCDD_CFG_H
#define RTCMGRCDD_CFG_H

#include "Std_Types.h"
#include "RtcDrvCdd_Cfg.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

//Temp compensation enable flag
#define TEMP_COMPENSATION			(STD_ON)

#define RTCCDD_IMX8QXP

#define cRTCCDD_TIME_TYPE Rtc_TimeType
#define cRTCCDD_ALARM_TIME_TYPE Rtc_AlarmType
#define cRTCCDD_PERIODIC_ALARM_TIME_TYPE Rtc_PeriodicAlarmType

#define RTC_ALARM_FUNCTIONALITY_ENABLED

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================

#endif /* RTCMGRCDD_CFG_H */

