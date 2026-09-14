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
#include "RtcDrvCdd_Cfg.h"
#include "RtcDrvCdd_TemperatureCompensation.h"
//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
#define RTC_ALARM_1                     (0u)    // Alarm 1
#define RTC_ALARM_2                     (1u)    // Alarm 2 - used for RTC temperature compensation
#define RTC_ALARM_MAX                   (2u)

#define RTC_CAL_512Hz                   (0u)    // 512Hz wave output signal for calibration
#define RTC_CAL_2Hz                     (2u)    // 2Hz wave output signal for calibration
#define RTC_CAL_1Hz                     (3u)    // 1Hz wave output signal for calibration
//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================
void RtcDrvCdd_DelayUs(uint16 microseconds);
void RtcDrvCdd_DelayCycles(uint32 delaycycles);
extern Std_ReturnType RtcDrvCdd_Init(void);
extern Std_ReturnType RtcDrvCdd_DeInit(void);
extern Std_ReturnType RtcDrvCdd_Activate(void);
extern Std_ReturnType RtcDrvCdd_SetTime(const cRTCCDD_TIME_TYPE* p_time);
extern Std_ReturnType RtcDrvCdd_GetTime(cRTCCDD_TIME_TYPE* p_time);
extern Std_ReturnType RtcDrvCdd_SetDate(const cRTCCDD_DATE_TYPE* p_date);
extern Std_ReturnType RtcDrvCdd_GetDate(cRTCCDD_DATE_TYPE* p_date);
extern Std_ReturnType RtcDrvCdd_SetAlarm(const Rtc_AlarmType* Alarm, const uint8 AlarmIndex);
extern Std_ReturnType RtcDrvCdd_GetAlarm(Rtc_AlarmType* Alarm, const uint8 AlarmIndex);
extern Std_ReturnType RtcDrvCdd_EnableAlarmNotification(const uint8 AlarmIndex);
extern Std_ReturnType RtcDrvCdd_DisableAlarmNotification(const uint8 AlarmIndex);
extern Std_ReturnType RtcDrvCdd_EnableCenturyNotification(void);
extern Std_ReturnType RtcDrvCdd_DisableCenturyNotification(void);
extern Std_ReturnType RtcDrvCdd_EnableCalibrationSignalOutput(const uint8 CalibrationSignal);
extern Std_ReturnType RtcDrvCdd_DisableCalibrationSignalOutput(void);
extern uint32 RtcDrvCdd_ReadCumulatedError(void);
extern void RtcDrvCdd_WriteCumulatedError(const uint32 CumulatedError);
extern Std_ReturnType RtcDrvCdd_SetFrequencyOffset(const uint8 u8FreqOffsetPpm);
extern void RtcDrvCdd_CheckRtcWakeUpState(void);
extern void RtcDrvCdd_GetRtcWakeUpState(boolean *pIsRtcWakeUp);
extern void RtcDrvCdd_MainFunction(void);
extern Std_ReturnType RtcDrvCdd_SetPeriodicAlarm(const cRTCCDD_PERIODIC_ALARM_TIME_TYPE* p_alarm);
extern Std_ReturnType RtcDrvCdd_ClearAlarm(void);
extern Std_ReturnType RtcDrvCdd_ClearPeriodicAlarm(void);
extern void RtcDrvCdd_AlarmNotification(void);
extern void RtcDrvCdd_AlarmInterruptHandler(void);

#endif



