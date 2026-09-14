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

#ifndef RTCMGRCDD_C
#define RTCMGRCDD_C

#include "RtcMgrCdd.h"
#include "RtcCdd.h"
#include "RtcIfCdd.h"
#include "RtcMgrCdd_Cfg.h"
#include "RtcDrvCdd.h"

#include "RtcIfCdd_Cbk.h"

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
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional initialization state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_Init(void)
{
    return RtcIfCdd_Init();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-initialization state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_DeInit(void)
{
    return RtcIfCdd_DeInit();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-activation state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------

Std_ReturnType RtcMgrCdd_DeActivation(void)
{
    Std_ReturnType RetVal = E_NOT_OK;
	#if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_TRAVEOII)
	RetVal = RtcDrvCdd_TemperatureCompensation_DeInit();
	#else
	RetVal = E_OK;
	#endif
	
    return RetVal;	
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Main periodic function
//---------------------------------------------------------------------------------------------------------------------
void RtcMgrCdd_MainFunction(void)
{
    RtcDrvCdd_MainFunction();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Update Time and Date operations
///
/// @return E_OK: Update Sucessful; E_NOT_OK: Update Failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_SetTime(const cRTCCDD_TIME_TYPE* p_time)
{
    return RtcIfCdd_SetTime(p_time);
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Get Time and Date operations
///
/// @return E_OK: Time and Date Read Sucessful; E_NOT_OK: Time and Date Read Failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_GetTime(cRTCCDD_TIME_TYPE* p_time)
{
    return RtcIfCdd_GetTime(p_time);
}

#if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_TRAVEOII)
//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Update Time and Date operations
///
/// @return E_OK: Update Sucessful; E_NOT_OK: Update Failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_SetDate(const cRTCCDD_DATE_TYPE* p_date)
{
    return RtcIfCdd_SetDate(p_date);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Get Time and Date operations
///
/// @return E_OK: Time and Date Read Sucessful; E_NOT_OK: Time and Date Read Failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_GetDate(cRTCCDD_DATE_TYPE* p_date)
{
    return RtcIfCdd_GetDate(p_date);
}
#endif

#ifdef RTC_ALARM_FUNCTIONALITY_ENABLED 
//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC set Alarm operations
///
/// @return E_OK: Update Sucessful; E_NOT_OK: Update Failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_SetAlarm(const cRTCCDD_ALARM_TIME_TYPE* p_alarm)
{
    #if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_TRAVEOII)
        return RtcIfCdd_SetAlarm(p_alarm, RTC_ALARM_1);
    #else
        return RtcIfCdd_SetAlarm(p_alarm);
    #endif
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC set Alarm operations
///
/// @return E_OK: Update Sucessful; E_NOT_OK: Update Failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_SetPeriodicAlarm(const cRTCCDD_PERIODIC_ALARM_TIME_TYPE* p_alarm)
{
    return RtcIfCdd_SetPeriodicAlarm(p_alarm);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC clear Alarm operations
///
/// @return E_OK: Update Sucessful; E_NOT_OK: Update Failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_ClearAlarm(void)
{
    return RtcIfCdd_ClearAlarm();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC clear periodic Alarm operations
///
/// @return E_OK: Update Sucessful; E_NOT_OK: Update Failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_ClearPeriodicAlarm(void)
{
    return RtcIfCdd_ClearPeriodicAlarm();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Enable Alarm notification
///
/// @param: NA
///
///  @return E_OK: Alarm Notification is enabled successfuly; E_NOT_OK: Alarm Notification is not enabled
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_EnableAlarmNotification(void)
{
    #if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_TRAVEOII)
        return RtcIfCdd_EnableAlarmNotification(RTC_ALARM_1);
    #else
        return RtcIfCdd_EnableAlarmNotification();
    #endif
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Disable Alarm notification
///
/// @param: NA
///
///  @return E_OK: Alarm Notification is disable successfuly; E_NOT_OK: Alarm Notification is not disabled
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_DisableAlarmNotification(void)
{
    #if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_TRAVEOII)
        return RtcIfCdd_DisableAlarmNotification(RTC_ALARM_1);
    #else
        return RtcIfCdd_DisableAlarmNotification();
    #endif
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Alarm Notification
///
/// @param: AlarmIndex
///
///  @return NA
//---------------------------------------------------------------------------------------------------------------------
#if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_TRAVEOII)
void RtcMgrCdd_AlarmNotification(const uint8 AlarmIndex)
{
    if (RTC_ALARM_1 == AlarmIndex)
    {
        RtcDrvCdd_AlarmNotification();
    }
    else
    {
        RtcDrvCdd_TemperatureCompensation_AlarmNotification();
    }
}
#else
void RtcMgrCdd_AlarmNotification(void)
{
    RtcCdd_AlarmNotification();
}
#endif
#if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_TRAVEOII)
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Set frequency offset at 25C. This offset is compensated by the embedded HW mechanism in RTC
///
/// @param  s8FreqOffsetP - The fequency offset in PPMs
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_SetFrequencyOffset(const uint8 u8FreqOffsetP)
{
    return RtcIfCdd_SetFrequencyOffset(u8FreqOffsetP);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
//---------------------------------------------------------------------------------------------------------------------
void RtcMgrCdd_CheckRtcWakeUpState(void)
{
    RtcIfCdd_CheckRtcWakeUpState();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Disable calibration wave output signal
///
/// @param  NA
///
/// @return E_OK: Disable calibration wave output signal is successful
///         E_NOT_OK: Disable calibration wave output signal failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_DisableCalibrationSignalOutput(void)
{
    return RtcIfCdd_DisableCalibrationSignalOutput();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Disable Century notification
///
/// @param: NA
///
///  @return E_OK: Century Notification is disabled successfuly; E_NOT_OK: Century Notification is not disabled
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_DisableCenturyNotification(void)
{
    return RtcIfCdd_DisableCenturyNotification();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Enable calibration wave output signal
///
/// @param  Calibration wave output signal
///         0x0 - 512Hz wave; 0x1 - Reserved; 0x2 - 2Hz wave; 0x3 - 1Hz wave
///
/// @return E_OK: Enable calibration wave output signal is successful
///         E_NOT_OK: Enable calibration wave output signal failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_EnableCalibrationSignalOutput(const uint8 CalibrationSignal)
{
    return RtcIfCdd_EnableCalibrationSignalOutput(CalibrationSignal);
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Enable Century notification
///
/// @param: NA
///
///  @return E_OK: Century Notification is enabled successfuly; E_NOT_OK: Century Notification is not enabled
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_EnableCenturyNotification(void)
{
    return RtcIfCdd_EnableCenturyNotification();
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC get Alarm operations
///
/// @return E_OK: Alarm Read Sucessful; E_NOT_OK: Alarm Read Failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_GetAlarm(Rtc_AlarmType* pAlarm)
{
    Std_ReturnType RetVal;

    RetVal = RtcIfCdd_GetAlarm(pAlarm, RTC_ALARM_1);
    return RetVal;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief
//---------------------------------------------------------------------------------------------------------------------
void RtcMgrCdd_GetRtcWakeUpState(boolean *pIsRtcWakeUp)
{
    RtcIfCdd_GetRtcWakeUpState(pIsRtcWakeUp);
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Century Alarm Notification
///
/// @param: NA
///
///  @return NA
//---------------------------------------------------------------------------------------------------------------------
void RtcMgrCdd_CenturyNotification(void)
{
    RtcCdd_CenturyNotification();
}
#endif
#endif

#if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_IMX8)
//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Get Seconds operations
///
/// @return E_OK: Seconds Read Sucessful; E_NOT_OK: Seconds Read Failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcMgrCdd_GetSec1970(uint32 *RtcCdd_SecVal)
{
    return RtcIfCdd_GetSec1970(RtcCdd_SecVal);
}
#endif
#endif
