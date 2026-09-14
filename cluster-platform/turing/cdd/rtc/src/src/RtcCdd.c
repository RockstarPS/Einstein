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

#ifndef RTCCDD_C
#define RTCCDD_C

#include "RtcDrvCdd_Cfg.h"
#include "RtcCdd.h"
#include "RtcMgrCdd.h"
#include "CmpLib.h"

/// @brief  Instance of life-cycle state-machine
CMPLIB_INSTANCE (RtcCdd)

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================
/*
** This flag is used to block RTC APIs when component is deactivated.
*/
static boolean RtcCdd_ActivationDone;

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional initialization state
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpInit(void)
{
    RtcCdd_ActivationDone = (boolean)FALSE;
    return RtcMgrCdd_Init();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-initialization state
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeInit(void)
{
    RtcCdd_ActivationDone = (boolean)FALSE;
    return RtcMgrCdd_DeInit();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional activation state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress. Keeps the component in this state.
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActivation(void)
{
    RtcCdd_ActivationDone = (boolean)TRUE;
    RtcDrvCdd_Activate();
    return E_OK;
	
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional de-activation state
///
/// @return E_OK:           Succeed
///<br>     E_NOT_READY:    In progress
///<br>     E_NOT_OK:       Failed
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDeActivation( void )
{
	Std_ReturnType RetVal = E_NOT_OK;
	RetVal = RtcMgrCdd_DeActivation();
    RtcCdd_ActivationDone = (boolean)FALSE;
	return RetVal;
	
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  State for normal operations
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpActive(void)
{
    RtcMgrCdd_MainFunction();
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Diagnostic state
///
/// @return E_OK:           Diagnostic has completed. Go to DiagReturn state.
///<br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiag( void )
{
    return E_NOT_OK; /// No diag support for now
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Transitional state to clean up after diagnostic state. Component behaviour to be restored.
///
/// @return E_OK:           Diagnostic clean-up has completed. Return to the previous state (Active or Inactive).
///<br>     E_NOT_READY:    Keeps the component in this state.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType CmpDiagReturn( void )
{
    return E_NOT_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcCdd_SetTime(const cRTCCDD_TIME_TYPE* p_time)
{
    Std_ReturnType RetVal = E_NOT_OK;

    if((boolean)FALSE != RtcCdd_ActivationDone)
    {
       RetVal = RtcMgrCdd_SetTime(p_time);
    }
    return RetVal;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcCdd_GetTime(cRTCCDD_TIME_TYPE* p_time)
{
    Std_ReturnType RetVal = E_NOT_OK;

    if((boolean)FALSE != RtcCdd_ActivationDone)
    {
    	RetVal = RtcMgrCdd_GetTime(p_time);
	}
	return RetVal;
}
#if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_TRAVEOII)
//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcCdd_SetDate(const cRTCCDD_DATE_TYPE* p_date)
{
    Std_ReturnType RetVal = E_NOT_OK;

    if((boolean)FALSE != RtcCdd_ActivationDone)
    {
    	RetVal = RtcMgrCdd_SetDate(p_date);
	}
	return RetVal;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcCdd_GetDate(cRTCCDD_DATE_TYPE* p_date)
{
	Std_ReturnType RetVal = E_NOT_OK;

    if((boolean)FALSE != RtcCdd_ActivationDone)
    {
    	RetVal = RtcMgrCdd_GetDate(p_date);
	}
	return RetVal;
}
#endif

#ifdef RTC_ALARM_FUNCTIONALITY_ENABLED 
//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcCdd_SetAlarm(const cRTCCDD_ALARM_TIME_TYPE* p_alarm)
{
	Std_ReturnType RetVal = E_NOT_OK;

    if((boolean)FALSE != RtcCdd_ActivationDone)
    {
    	RetVal = RtcMgrCdd_SetAlarm(p_alarm);
	}
	return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcCdd_SetPeriodicAlarm(const cRTCCDD_PERIODIC_ALARM_TIME_TYPE* p_alarm)
{
    return RtcMgrCdd_SetPeriodicAlarm(p_alarm);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcCdd_ClearAlarm(void)
{
    return RtcMgrCdd_ClearAlarm();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcCdd_ClearPeriodicAlarm(void)
{
    return RtcMgrCdd_ClearPeriodicAlarm();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcCdd_EnableAlarmNotification(void)
{
    return RtcMgrCdd_EnableAlarmNotification();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcCdd_DisableAlarmNotification(void)
{
    return RtcMgrCdd_DisableAlarmNotification();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
void RtcCdd_AlarmNotification(void)
{
    //TODO: Not clear what should be the behaviour when this notification comes?
}
#if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_TRAVEOII)
//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
void RtcCdd_CenturyNotification(void)
{
    //TODO: Not clear what should be the behaviour when this notification come?
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
void RtcCdd_CheckRtcWakeUpState(void)
{
    RtcMgrCdd_CheckRtcWakeUpState();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcCdd_DisableCalibrationSignalOutput(void)
{
    return RtcMgrCdd_DisableCalibrationSignalOutput();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcCdd_DisableCenturyNotification(void)
{
    return RtcMgrCdd_DisableCenturyNotification();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcCdd_EnableCalibrationSignalOutput(const uint8 CalibrationSignal)
{
    return RtcMgrCdd_EnableCalibrationSignalOutput(CalibrationSignal);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcCdd_EnableCenturyNotification(void)
{
    return RtcMgrCdd_EnableCenturyNotification();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcCdd_GetAlarm(Rtc_AlarmType* Alarm)
{
	Std_ReturnType RetVal = E_NOT_OK;

    if((boolean)FALSE != RtcCdd_ActivationDone)
    {
    	RetVal = RtcMgrCdd_GetAlarm(Alarm);
	}
    return RetVal;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
void RtcCdd_GetRtcWakeUpState(boolean *pIsRtcWakeUp)
{
    RtcMgrCdd_GetRtcWakeUpState(pIsRtcWakeUp);
}
#endif

#endif

#if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_IMX8)
//---------------------------------------------------------------------------------------------------------------------
/// @brief  See RtcMgrCdd
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcCdd_GetSec1970(uint32 *RtcCdd_SecVal)
{
    Std_ReturnType RetVal = E_NOT_OK;
	if(NULL_PTR != RtcCdd_SecVal)
	{
		if((boolean)FALSE != RtcCdd_ActivationDone)
		{
			RetVal = RtcMgrCdd_GetSec1970(RtcCdd_SecVal);
		}
	}
	return RetVal;
}
#endif
#endif
/*---------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 21/Dec/2023
By                : rbalamur
Traceability      : Jira T38XD29284-61199 In Meet Mode cluster is resetting for every half an hour.
Change Description: When CmpActivation , call RtcDrvCdd_Activate() to invoke RtcDrvCdd_TemperatureCompensation_Init
-----------------------------------------------------------------------------------------*/
