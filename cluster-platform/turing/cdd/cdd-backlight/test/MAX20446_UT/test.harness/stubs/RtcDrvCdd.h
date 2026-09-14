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


#ifndef RTCDRVCDD_H
#define RTCDRVCDD_H

#include "RtcCdd_Types.h"

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
extern Std_ReturnType RtcDrvCdd_Init(void);
extern Std_ReturnType RtcDrvCdd_DeInit(void);
extern Std_ReturnType RtcDrvCdd_Activate(void);
extern Std_ReturnType RtcDrvCdd_DeActivate(void);
extern Std_ReturnType RtcDrvCdd_SetTime(const cRTCCDD_TIME_TYPE* p_time);
extern Std_ReturnType RtcDrvCdd_GetTime(cRTCCDD_TIME_TYPE* p_time);
extern void RtcDrvCdd_MainFunction(void);
#ifdef RTC_ALARM_FUNCTIONALITY_ENABLED 
extern Std_ReturnType RtcDrvCdd_SetAlarm(const cRTCCDD_ALARM_TIME_TYPE* p_alarm);
extern Std_ReturnType RtcDrvCdd_SetPeriodicAlarm(const cRTCCDD_PERIODIC_ALARM_TIME_TYPE* p_alarm);
extern Std_ReturnType RtcDrvCdd_ClearAlarm(void);
extern Std_ReturnType RtcDrvCdd_ClearPeriodicAlarm(void);
extern Std_ReturnType RtcDrvCdd_EnableAlarmNotification(void);
extern Std_ReturnType RtcDrvCdd_DisableAlarmNotification(void);
#endif
#endif

