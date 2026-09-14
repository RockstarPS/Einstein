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

#ifndef RTCMGRCDD_TEMPERATURECOMPENSATION_C
#define RTCMGRCDD_TEMPERATURECOMPENSATION_C

#include "RtcMgrCdd_Cfg.h"
#include "RtcDrvCdd_TemperatureCompensation.h"
#include "RtcDrvCdd_TemperatureCompensation_Cfg.h"
#include "RtcDrvCdd.h"
#include "RtcIfCdd.h"
#include "MathLib.h"
#include "AssertLib.h"
#include "EcuM.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

#define cConst1                         (uint8)1
#define cConst25                        (uint8)25
#define cConst59                        (uint8)59
#define cMinInHour                      (uint8)60


#define cRtcDeviationLimit               (uint32)16666666    // deviation limit for 1s compensation
#define RTC_MAX_SEC_OR_MIN                  (59u) 

// Substates for compensation algorithm
typedef enum
{
    CompensationState_Step1,
    CompensationState_Step2,
    CompensationState_Step3,
    CompensationState_Step4
} CompensationState_Type;

//compensation mode
typedef enum 
{
    RTC_SLEEP_MODE,
    RTC_NORMAL_MODE
} CompensationMode_Type;

// Flag for RTC Alarm notification
static boolean bRtcIrqPresent = FALSE;

// Current compensation state
static CompensationState_Type CompensationState = CompensationState_Step1;
//compensation mode
static CompensationMode_Type CompensationMode = RTC_SLEEP_MODE;

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

static void ApplyCorrection(uint32* u32CumulatedErrorP);
static uint32 CalculateRtcDeviation(const uint16 u16AdcValueP, const uint8 u8RtcTempCoeffP);
static boolean IsRtcIrqPresent(void);

static uint8 cRtcDrvCdd_TempCpmpensationPeriod;
//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Applies the correction of the RTC
///
/// @param  u32CumulatedErrorP - Pointer to Cumulated error
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
static void ApplyCorrection(uint32* u32CumulatedErrorP)
{
    Rtc_TimeType CurrTimeL;
    uint32 u32CumulatedErrorL = *u32CumulatedErrorP;

    if (E_OK == RtcIfCdd_GetTime(&CurrTimeL))        // Read the current time
    {
        // This is an additional check to prevent seconds compensation when the minutes are changed.
        // The changing of the seconds should not occurs when the minuteis changedd due to
        // additional calculations need to be implemented to correct min, hour, date, month and year.
        // Normally this will not happen due to the RTC alarm is set to be at XXmin and 30sec.

        if ((CurrTimeL.Second > cConst1) && (CurrTimeL.Second < cConst59))
        {
            // For temperatures above and below 25C the WCO frequesncy is decreased and to compensate this
            // deviation we need always  to add second(s) when the cumulated error corresponds to 1 sec. delay.
            CurrTimeL.Second ++;

            if (E_OK == RtcIfCdd_SetTime(&CurrTimeL)) // Update the current time
            {
                // Decrease deviation
                u32CumulatedErrorL = u32CumulatedErrorL - cRtcDeviationLimit;
                *u32CumulatedErrorP = u32CumulatedErrorL;
            }
        }
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Calculates the deviation of the clock regarding measured temperature in PPM
///
/// @param  u16AdcValueP : Measured raw Adc Value
///         u8RtcCalib_Kp: Temperature coefficient
///
/// @return The calculated clock deviation PPMs toward the current temperature
//---------------------------------------------------------------------------------------------------------------------
static uint32 CalculateRtcDeviation (const uint16 u16AdcValueP, const uint8 u8RtcTempCoeffP)
{
    sint8 s8CurrTempL;
    uint32 u32TempDeviationL;

    s8CurrTempL = MathLib_InterpolateLinearU16_S8(u16AdcValues, s8TempDegrees, cRtcDrvCdd_InterpolationPoints, u16AdcValueP);

    // Calculate deviation per minute
    u32TempDeviationL = (uint32)(u8RtcTempCoeffP * (s8CurrTempL - cConst25) * (s8CurrTempL - cConst25));

    // Calculate devialtion per compersation period
    u32TempDeviationL = u32TempDeviationL * cRtcDrvCdd_TempCpmpensationPeriod;

    return u32TempDeviationL;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Reads and clears Rtc interrupt flag
///
/// @param  u32CumulatedErrorP - Cumulated error
///
/// @return TRUE: IRQ is occured ; FALSE: IRQ is not occured
//---------------------------------------------------------------------------------------------------------------------
static boolean IsRtcIrqPresent(void)
{
    boolean RetValue;

    // Enter critical section
    RtcDrvCdd_EnterExclusiveArea();

    RetValue = bRtcIrqPresent;
    bRtcIrqPresent = FALSE;

    // Leave critical section
    RtcDrvCdd_ExitExclusiveArea();

    return RetValue;
}

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Initialization function for compensation.
///
/// @param  NA
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
void RtcDrvCdd_TemperatureCompensation_Init (void)
{
    EcuM_WakeupSourceType WakeupEvents;
	
	if (CompensationMode == RTC_SLEEP_MODE)
    {
		CompensationMode = RTC_NORMAL_MODE;
        RtcDrvCdd_TemperatureCompensation_RunMode();
		
		WakeupEvents = RtcDrvCdd_GetValidatedWakeupEvents();
		
		// In case of POR
		if ((WakeupEvents & RtcDrvCdd_WakeUpSourcePower) != (EcuM_WakeupSourceType)0)
		{	
			RtcIfCdd_WriteCumulatedError(0);        // clear cumulated error in case of Power On Reset
			
			
		}
		
		//in case of wakeup for calibration, compensation algorithm shall be run
		if ((WakeupEvents & RtcDrvCdd_WakeUpSourceRtc) != (EcuM_WakeupSourceType)0)
		{
			RtcDrvCdd_TemperatureCompensation_AlarmNotification();	
			RtcDrvCdd_TemperatureCompensation_SleepModeTimeperiod_Init();
		}

		// Init internal state machine
		CompensationState = CompensationState_Step1;
	}
}

void RtcDrvCdd_TemperatureCompensation_Timeperiod_Init(void)
{
	cRtcDrvCdd_TempCpmpensationPeriod = cRtcDrvCdd_TempCpmpensationPeriod_RunMode;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Temperature time period compensation will be set for 30mins in sleep mode compensation.
///
/// @param  NA
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
void RtcDrvCdd_TemperatureCompensation_SleepModeTimeperiod_Init(void)
{
	cRtcDrvCdd_TempCpmpensationPeriod = cRtcDrvCdd_TempCpmpensationPeriod_SleepMode;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Temperature time period compensation will be set for 5mins in Run mode compensation.
///
/// @param  NA
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------

void RtcDrvCdd_TemperatureCompensation_RunModeTimeperiod_Init(void)
{
	cRtcDrvCdd_TempCpmpensationPeriod = cRtcDrvCdd_TempCpmpensationPeriod_RunMode;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  DeInitialization function for compensation
///
/// @param  NA
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_TemperatureCompensation_DeInit (void)
{
	// Enter critical section
    RtcDrvCdd_EnterExclusiveArea();

    CompensationMode = RTC_SLEEP_MODE;
    RtcDrvCdd_TemperatureCompensation_SleepMode();

    // Leave critical section
    RtcDrvCdd_ExitExclusiveArea();
	
	return E_OK;

}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Notification function when new Time is set in RTC.
///         Compensation strategy shall be reinitialized.
///
/// @param  NA
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
void RtcDrvCdd_TemperatureCompensation_SetTime (void)
{
    boolean bPendingCalibrationL = FALSE;

    // Clear Cumulated Error
    RtcIfCdd_WriteCumulatedError(0u);

    //Initialize state machine
    bPendingCalibrationL = IsRtcIrqPresent();
    if ((CompensationState > CompensationState_Step1) || (bPendingCalibrationL == TRUE))
    {
        // Reset state mashine
        CompensationState = CompensationState_Step1;
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Periodic function for Compensation strategy
///
/// @param  NA
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
void RtcDrvCdd_TemperatureCompensation_MainFunction (void)
{
    boolean bContinueSM = FALSE;
    boolean bIsIrqPresentL = FALSE;
    Std_ReturnType RetVal;
    uint8  u8RtcTempCoeffL;
    uint8  u8MunuteL;
    uint16 u16RawAdcValueL;
    uint32 u32CumulatedErrorL;
    Rtc_AlarmType RtcAlarmL = { 0 };
    IoHwAb_ErrorType AdcErrorL;

    do
    {
        bContinueSM = FALSE;
        switch (CompensationState)
        {
        case CompensationState_Step1:               // Check if RTC compensation alarm occured
            bIsIrqPresentL = IsRtcIrqPresent();
            if (bIsIrqPresentL == TRUE)
            {
                CompensationState = CompensationState_Step2;
                bContinueSM = TRUE;
            }
			else
			{
				RtcDrvCdd_RtcCalibstatus(eRtcCddCalibSts_idle);
			}
            break;

        case CompensationState_Step2:               // Set alram for the next compensation period
            if (E_OK == RtcIfCdd_GetAlarm(&RtcAlarmL, RTC_ALARM_2))
            {
                u8MunuteL = RtcAlarmL.Minute + cRtcDrvCdd_TempCpmpensationPeriod;
                if (cMinInHour <= u8MunuteL)
                {
                    u8MunuteL = u8MunuteL - cMinInHour;
                }
                RtcAlarmL.Minute = u8MunuteL;
                if (E_OK == RtcIfCdd_SetAlarm(&RtcAlarmL, RTC_ALARM_2))
                {
                    CompensationState = CompensationState_Step3;
                    bContinueSM = TRUE;
                }
            }
            break;

        case CompensationState_Step3:               // Check if there is at least single available ADC measurement
            RetVal = RtcDrvCdd_ReadAdcRawTemperature(&u16RawAdcValueL, &AdcErrorL);
            if ((E_OK == RetVal) && (IOHWAB_E_NO_ERROR == AdcErrorL))
            {
				RtcDrvCdd_RtcCalibstatus(eRtcCddCalibSts_Started);
                CompensationState = CompensationState_Step4;
                bContinueSM = TRUE;
            }
            break;

        case CompensationState_Step4:               // Perform the RTC compensation algorithm
            (void)RtcDrvCdd_ReadTempCoefficient(&u8RtcTempCoeffL);       // Read temperature coefficient
			RtcDrvCdd_RtcCalibstatus(eRtcCddCalibSts_InProgress);

            if ((cRtcTempCoeffValueMin > u8RtcTempCoeffL) || (cRtcTempCoeffValueMax < u8RtcTempCoeffL))
            {
                u8RtcTempCoeffL = cRtcTempCoeffValueDefault;
            }

            u32CumulatedErrorL = RtcIfCdd_ReadCumulatedError();
            u32CumulatedErrorL += CalculateRtcDeviation(u16RawAdcValueL, u8RtcTempCoeffL);

            if(u32CumulatedErrorL >= cRtcDeviationLimit)
            {
                ApplyCorrection(&u32CumulatedErrorL);
            }

            RtcIfCdd_WriteCumulatedError(u32CumulatedErrorL);                                                                
			RtcDrvCdd_RtcCalibstatus(eRtcCddCalibSts_Completed);
            CompensationState = CompensationState_Step1;
            break;

        default:
            DEBUG_ASSERT(FALSE);
            break;
        }
    } while (bContinueSM == TRUE);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Notification function from Gpt module on timeout expiry.
//<br>      Call happnes in interrupt context!
/// @param  NA
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
void RtcDrvCdd_TemperatureCompensation_AlarmNotification(void)
{
	if (CompensationMode == RTC_NORMAL_MODE)
    {
        bRtcIrqPresent = TRUE;
    }
    else
    {
		RtcDrvCdd_WakeupIndication((uint32)cRtcDrvCdd_WakeupEvent_Flag);
    }
}

void RtcDrvCdd_TemperatureCompensation_SleepMode(void)
 {
	 Std_ReturnType RetVal = E_NOT_READY;
	 Rtc_AlarmType RtcAlarmL = { 0 };
    Rtc_TimeType RtcTimeL = { 0 };

	//initial alarm is set for 30mins while going to sleep for temperature compensation
	RetVal = RtcIfCdd_GetTime(&RtcTimeL);
	RetVal |= RtcIfCdd_GetAlarm(&RtcAlarmL, RTC_ALARM_2);
	if(E_OK == RetVal)
	{
		RtcAlarmL.Minute = RtcTimeL.Minute + cRtcDrvCdd_TempCpmpensationPeriod_SleepMode; 
		if (RTC_MAX_SEC_OR_MIN < RtcAlarmL.Minute)
		{
			RtcAlarmL.Minute = RtcAlarmL.Minute - cMinInHour; 
		}
		RtcAlarmL.Minute_En = 1u;
		RtcAlarmL.Alarm_En = 1u;
		RetVal = RtcIfCdd_SetAlarm(&RtcAlarmL, RTC_ALARM_2);
		if (E_OK == RetVal)
		{
			RetVal = RtcDrvCdd_EnableAlarmNotification(RTC_ALARM_2);
		}
	}
	if(RetVal == E_OK)
	{
			//sets the compensation period of 30mins for consecutive triggers
		RtcDrvCdd_TemperatureCompensation_SleepModeTimeperiod_Init();
	}
	
 }
 
 //---------------------------------------------------------------------------------------------------------------------
/// @brief  Sets the First Alarm trigger for Initial compensation and also sets time period compensation for consecutive triggers
///			for run mode
//
/// @param  NA
///
/// @return NA
//--------------------------------------------------------------------------------------------------------------------
 
 void RtcDrvCdd_TemperatureCompensation_RunMode(void)
 {
	 Std_ReturnType RetVal = E_NOT_READY;
	 Rtc_AlarmType RtcAlarmL = { 0 };
     Rtc_TimeType RtcTimeL = { 0 };
	
	
	boolean WakeupFromRtc = FALSE;
	RtcCdd_CheckRtcWakeUpState();
	RtcCdd_GetRtcWakeUpState(&WakeupFromRtc);
	if(WakeupFromRtc == FALSE)
	{
					
		//initial alarm is set for 5mins while going to Operating mode for temperature compensation 
		RetVal = RtcIfCdd_GetTime(&RtcTimeL);	
		RetVal |= RtcIfCdd_GetAlarm(&RtcAlarmL, RTC_ALARM_2);
		if(E_OK == RetVal)
	    {
			RtcAlarmL.Minute = RtcTimeL.Minute + cRtcDrvCdd_TempCpmpensationPeriod_RunMode; 
			if (RTC_MAX_SEC_OR_MIN < RtcAlarmL.Minute)
			{
				RtcAlarmL.Minute = RtcAlarmL.Minute - (RTC_MAX_SEC_OR_MIN + cRtcDrvCdd_TempCpmpensationPeriod_RunMode); 
			}
			RtcAlarmL.Minute_En = 1u;
			RtcAlarmL.Alarm_En = 1u;
			RetVal = RtcIfCdd_SetAlarm(&RtcAlarmL, RTC_ALARM_2);
			if (E_OK == RetVal)
			{
				RetVal = RtcDrvCdd_EnableAlarmNotification(RTC_ALARM_2);
			}
		}
		if(RetVal == E_OK)
		{
			//sets the compensation period of 5mins for consecutive triggers
			RtcDrvCdd_TemperatureCompensation_RunModeTimeperiod_Init();	
		}
			
	}
	 
 }

#endif
