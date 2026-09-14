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

#ifndef RTCCDD_H
#define RTCCDD_H

#include "RtcCdd_Types.h"
#include "RtcDrvCdd_Cfg.h"

#ifdef cRTCCDD_SUPPORT_NON_AUTOSAR                //To be defined for the projects which do not depend on RTE Files.


//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================


//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================

extern Std_ReturnType RtcCdd_SetTime(const cRTCCDD_TIME_TYPE* p_time);
extern Std_ReturnType RtcCdd_GetTime(cRTCCDD_TIME_TYPE* p_time);
#if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_TRAVEOII)
extern Std_ReturnType RtcCdd_SetDate(const cRTCCDD_DATE_TYPE* p_date);
extern Std_ReturnType RtcCdd_GetDate(cRTCCDD_DATE_TYPE* p_date);
#endif
#ifdef RTC_ALARM_FUNCTIONALITY_ENABLED 
extern Std_ReturnType RtcCdd_SetAlarm(const cRTCCDD_ALARM_TIME_TYPE* p_alarm);
extern Std_ReturnType RtcCdd_SetPeriodicAlarm(const cRTCCDD_PERIODIC_ALARM_TIME_TYPE* alarm);
extern Std_ReturnType RtcCdd_ClearAlarm(void);
extern Std_ReturnType RtcCdd_ClearPeriodicAlarm(void);
extern Std_ReturnType RtcCdd_EnableAlarmNotification(void);
extern Std_ReturnType RtcCdd_DisableAlarmNotification(void);
extern void RtcCdd_AlarmNotification(void);
#if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_TRAVEOII)
extern void RtcCdd_CenturyNotification(void);
extern void RtcCdd_CheckRtcWakeUpState(void);
extern Std_ReturnType RtcCdd_DisableCalibrationSignalOutput(void);
extern Std_ReturnType RtcCdd_DisableCenturyNotification(void);
extern Std_ReturnType RtcCdd_EnableCalibrationSignalOutput(const uint8 CalibrationSignal);
extern Std_ReturnType RtcCdd_EnableCenturyNotification(void);
extern Std_ReturnType RtcCdd_GetAlarm(Rtc_AlarmType* Alarm);
extern void RtcCdd_GetRtcWakeUpState(boolean *pIsRtcWakeUp);
#endif
#endif 
#endif
#if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_IMX8)
extern Std_ReturnType RtcCdd_GetSec1970(uint32 *RtcCdd_SecVal);
#endif
#endif

