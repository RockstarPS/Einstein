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

#ifndef RTCIFCDD_H
#define RTCIFCDD_H

#include "RtcMgrCdd_Cfg.h"
#include "RtcDrvCdd.h"
#include "RtcMgrCdd.h"
#include "RtcDrvCdd_TemperatureCompensation.h"

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

#define RtcIfCdd_Init                                           RtcDrvCdd_Init
#define RtcIfCdd_DeInit                                         RtcDrvCdd_DeInit
#define RtcIfCdd_SetTime(p_time)                                RtcDrvCdd_SetTime(p_time)
#define RtcIfCdd_GetTime(p_time)                                RtcDrvCdd_GetTime(p_time)
#if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_TRAVEOII)
#define RtcIfCdd_SetDate(p_date)                                RtcDrvCdd_SetDate(p_date)
#define RtcIfCdd_GetDate(p_date)                                RtcDrvCdd_GetDate(p_date)
#endif
#ifdef RTC_ALARM_FUNCTIONALITY_ENABLED 
#define RtcIfCdd_SetPeriodicAlarm(p_alarm)                      RtcDrvCdd_SetPeriodicAlarm(p_alarm)
#define RtcIfCdd_ClearAlarm                                     RtcDrvCdd_ClearAlarm
#define RtcIfCdd_ClearPeriodicAlarm                             RtcDrvCdd_ClearPeriodicAlarm
#define RtcIfCdd_AlarmNotification                              RtcMgrCdd_AlarmNotification
#if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_TRAVEOII)
#define RtcIfCdd_EnableAlarmNotification(Index)                 RtcDrvCdd_EnableAlarmNotification(Index)
#define RtcIfCdd_DisableAlarmNotification(Index)                RtcDrvCdd_DisableAlarmNotification(Index)
#define RtcIfCdd_SetFrequencyOffset(Offset)                     RtcDrvCdd_SetFrequencyOffset(Offset)
#define RtcIfCdd_WriteCumulatedError(Error)                     RtcDrvCdd_WriteCumulatedError(Error)
#define RtcIfCdd_GetAlarm(pAlarm, Index)                        RtcDrvCdd_GetAlarm(pAlarm, Index)
#define RtcIfCdd_SetAlarm(Alarm, Index)                         RtcDrvCdd_SetAlarm(Alarm, Index)
#define RtcIfCdd_ReadCumulatedError                             RtcDrvCdd_ReadCumulatedError
#define RtcIfCdd_CheckRtcWakeUpState                            RtcDrvCdd_CheckRtcWakeUpState
#define RtcIfCdd_DisableCalibrationSignalOutput()               RtcDrvCdd_DisableCalibrationSignalOutput()
#define RtcIfCdd_DisableCenturyNotification()                   RtcDrvCdd_DisableCenturyNotification()
#define RtcIfCdd_EnableCalibrationSignalOutput(Signal)          RtcDrvCdd_EnableCalibrationSignalOutput(Signal)
#define RtcIfCdd_EnableCenturyNotification()                    RtcDrvCdd_EnableCenturyNotification()
#define RtcIfCdd_GetAlarm(pAlarm, Index)                        RtcDrvCdd_GetAlarm(pAlarm, Index)
#define RtcIfCdd_GetRtcWakeUpState(pIsRtcWakeUp)                RtcDrvCdd_GetRtcWakeUpState(pIsRtcWakeUp)
#else
#define RtcIfCdd_EnableAlarmNotification                        RtcDrvCdd_EnableAlarmNotification
#define RtcIfCdd_DisableAlarmNotification                       RtcDrvCdd_DisableAlarmNotification
#define RtcIfCdd_SetAlarm(p_alarm)                              RtcDrvCdd_SetAlarm(p_alarm)
#endif
#endif
#if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_IMX8)
#define RtcIfCdd_GetSec1970(RtcCdd_SecVal)                      RtcDrvCdd_GetSec1970(RtcCdd_SecVal)
#endif
#endif

