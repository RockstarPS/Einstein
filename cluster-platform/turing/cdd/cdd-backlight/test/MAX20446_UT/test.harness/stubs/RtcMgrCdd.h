//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2016] Visteon Corporation
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

#ifndef RTCMGRCDD_H
#define RTCMGRCDD_H

#include "RtcCdd_Types.h"
#include "RtcDrvCdd.h"
#include "RtcCdd.h"

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

extern Std_ReturnType RtcMgrCdd_Init(void);
extern Std_ReturnType RtcMgrCdd_DeInit(void);
extern Std_ReturnType RtcMgrCdd_DeActivation(void);
extern Std_ReturnType RtcMgrCdd_SetTime(const cRTCCDD_TIME_TYPE* p_time);
extern Std_ReturnType RtcMgrCdd_GetTime(cRTCCDD_TIME_TYPE* p_time);
#if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_TRAVEOII)
extern Std_ReturnType RtcMgrCdd_SetDate(const cRTCCDD_DATE_TYPE* p_date);
extern Std_ReturnType RtcMgrCdd_GetDate(cRTCCDD_DATE_TYPE* p_date);
#endif
extern void RtcMgrCdd_MainFunction(void);
#ifdef RTC_ALARM_FUNCTIONALITY_ENABLED 
extern Std_ReturnType RtcMgrCdd_SetAlarm(const cRTCCDD_ALARM_TIME_TYPE* p_alarm);
extern Std_ReturnType RtcMgrCdd_SetPeriodicAlarm(const cRTCCDD_PERIODIC_ALARM_TIME_TYPE* p_alarm);
extern Std_ReturnType RtcMgrCdd_ClearAlarm(void);
extern Std_ReturnType RtcMgrCdd_ClearPeriodicAlarm(void);
extern Std_ReturnType RtcMgrCdd_EnableAlarmNotification(void);
extern Std_ReturnType RtcMgrCdd_DisableAlarmNotification(void);
#if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_TRAVEOII)
extern void RtcMgrCdd_AlarmNotification(const uint8 AlarmIndex);
extern Std_ReturnType RtcMgrCdd_SetFrequencyOffset(const uint8 u8FreqOffsetP);
extern void RtcMgrCdd_CheckRtcWakeUpState(void);
extern Std_ReturnType RtcMgrCdd_DisableCalibrationSignalOutput(void);
extern Std_ReturnType RtcMgrCdd_DisableCenturyNotification(void);
extern Std_ReturnType RtcMgrCdd_EnableCalibrationSignalOutput(const uint8 CalibrationSignal);
extern Std_ReturnType RtcMgrCdd_EnableCenturyNotification(void);
extern Std_ReturnType RtcMgrCdd_GetAlarm(Rtc_AlarmType* pAlarm);
extern void RtcMgrCdd_GetRtcWakeUpState(boolean *pIsRtcWakeUp);
void RtcMgrCdd_CenturyNotification(void);
#else
extern void RtcMgrCdd_AlarmNotification(void);
#endif

#endif
#if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_IMX8)
extern Std_ReturnType RtcMgrCdd_GetSec1970(uint32 *RtcCdd_SecVal);
#endif
#endif

