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

#ifndef RTCDRVCDD_IMX8QXP_C
#define RTCDRVCDD_IMX8QXP_C

#include "Turing_Types.h"
#include "RtcDrvCdd.h"
#include "Port.h"
#include "irq_api.h"
#include "timer_api.h"
#include "misc_api.h"
#include "MathLib.h"
#include "ipc.h"
#if (TEMP_COMPENSATION == STD_ON)
#include "RtcDrvCdd_TemperatureCompensation.h"
#endif
#include "RtcIfCdd_Cbk.h"
#include "RtcDrvCdd_Cfg.h"
#include "Rte_RtcCdd_Type.h"
#include "RtcCdd_Types.h"
#include "Rte_RtcCdd.h"
#include "RtcIfCdd.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

#ifdef RTC_ALARM_FUNCTIONALITY_ENABLED
extern tResetReason ResetReason_GlobalVar(void);
static Std_ReturnType ReadBoardTemp(sint16 *pTemp);
static void RtcDrvCdd_AlarmInterruptHandler(void);
#endif

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

static sc_ipc_t rtc_ipc;

#if (TEMP_COMPENSATION == STD_ON)
static uint8 RtcDrvCdd_TempCompCnter;
#endif

//---------------------------------------------------------------------------------------------------------------------
/// @brief  reads and interpolates board temperature
///
/// @return E_OK - read and interpolation successful
///         E_NOT_OK - something went wrong with read/interpolation
//---------------------------------------------------------------------------------------------------------------------

#ifdef RTC_ALARM_FUNCTIONALITY_ENABLED
static Std_ReturnType ReadBoardTemp(sint16 *pTemp)
{
    Std_ReturnType RetVal = E_NOT_OK;
    IoHwAb_ErrorType status = IOHWAB_E_NO_ERROR;
    uint16 adcVal = 0;

    if((uint8)E_OK == cRTCCDD_IoHwAB_GetAsyncRawAdc(eIO_ADC_MAI_TEMP_SENSOR, &adcVal, &status) && (IOHWAB_E_NO_ERROR == status))
    {
        *pTemp = MathLib_InterpolateLinearU16_S16(u16AdcValues, s16TempDegrees, RTCDRVCDD_INTERPOLATION_POINTS, adcVal);
        RetVal = E_OK;
    }
    
    return RetVal;
}

#endif
//---------------------------------------------------------------------------------------------------------------------
/// @brief The interrupt polling function.
///
/// @param  NA
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
#ifdef RTC_ALARM_FUNCTIONALITY_ENABLED
static void RtcDrvCdd_AlarmInterruptHandler(void)
{
    uint32_t status = 0, status2 = 0;
	RTCCDD_ENTER_CRITICAL_SECTION();
    if(SC_ERR_NONE == sc_ipc_open(&rtc_ipc, PORT_IPC_CHANNEL_ID))
    {
        if(SC_ERR_NONE == sc_irq_status(rtc_ipc, SC_R_M4_0_MU_1A, SC_IRQ_GROUP_RTC, &status))
        {
            if((status & SC_IRQ_RTC) != 0u)
            {
                RtcIfCdd_AlarmNotification();
            }
            // Second read is here just in case first read did not properly clear irq status
            (void)sc_irq_status(rtc_ipc, SC_R_M4_0_MU_1A, SC_IRQ_GROUP_RTC, &status2);
        }
    }
    sc_ipc_close(rtc_ipc);
	RTCCDD_EXIT_CRITICAL_SECTION();
} 
#endif
//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Initialization operations
///
/// @return E_NOT_OK - Driver is not initialized
///         E_OK - Driver is initialized
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_Init(void)
{
    Std_ReturnType RetVal = E_NOT_OK;
    RetVal = E_OK;
	#if (TEMP_COMPENSATION == STD_ON)
    RtcDrvCdd_TempCompCnter = 0;
   #endif

    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC DeInitialization operations
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_DeInit(void)
{
	#if (TEMP_COMPENSATION == STD_ON)
    RtcDrvCdd_TempCompCnter = 0;
	#endif

    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Activation operations
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_Activate(void)
{

#ifdef RTC_ALARM_FUNCTIONALITY_ENABLED
    Std_ReturnType RetVal = E_NOT_OK;
    #if (TEMP_COMPENSATION == STD_ON)
    RtcDrvCdd_TempCompCnter = 0;
    #endif
    // read and send NvM params to temp compensation mgr
    RtcNvmCalibParams_t nvmParams;
    uint16 rtcCalib_E_R_FC, rtcCalib_K, rtcCalib_Tc;
    (void)cRTCCDD_MemAbstract_GetFastRTCSamplingPeriod(&nvmParams.fastRtcSamplingPeriod);
    (void)cRTCCDD_MemAbstract_GetSlowRTCSamplingPeriod(&nvmParams.slowRtcSamplingPeriod);
    (void)cRTCCDD_MemAbstract_GetRTCCoolingDelay(&nvmParams.rtcCoolingDelay);
    (void)cRTCCDD_MemAbstract_GetRTCCompensationDelay(&nvmParams.rtcCompensationDelay);
    (void)cRTCCDD_MemAbstract_GetRtcCalibration_K(&rtcCalib_K);
    (void)cRTCCDD_MemAbstract_GetRtcCalibration_E_R_FC(&rtcCalib_E_R_FC);
    (void)cRTCCDD_MemAbstract_GetRtcCalibration_Tc(&rtcCalib_Tc);

    nvmParams.rtcCalib_E_R_FC = (SFP7_8)rtcCalib_E_R_FC;
    nvmParams.rtcCalib_K = (SFP7_8)rtcCalib_K;
    nvmParams.rtcCalib_Tc = (SFP7_8)rtcCalib_Tc;
    RtcDrvCdd_TemperatureCompensation_ConfigureNvmParams(nvmParams);

    // Clear periodic alarm when back in normal running state
    (void)RtcDrvCdd_ClearPeriodicAlarm();

        // Pass RTC IPC channel to temp comp module
        RtcDrvCdd_TemperatureCompensation_ConfigureIpc(rtc_ipc);

        // Reset sleep comp counter when waking up from CAN and continuing normal operation
        RtcDrvCdd_TemperatureCompensation_ResetSleepCompCounter();

        tResetReason resetReason = ResetReason_GlobalVar();

        if(eResetReason_BatteryConnect == resetReason)
        {
            // read and send current temp to temp compensation module
            sint16 temp = 0;
            if((uint8)E_OK == ReadBoardTemp(&temp))
            {
                RtcDrvCdd_TemperatureCompensation_ConfigureTemp(temp);
                RetVal = RtcDrvCdd_TemperatureCompensation_Init();
            }
        }
        else
        {
            RetVal = RtcDrvCdd_TemperatureCompensation_ReadSnvs();
        }
		
	return RetVal;
 
#else
	return E_OK;

#endif
    }
  

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC DeActivation operations
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_DeActivate(void)
{
	#if (TEMP_COMPENSATION == STD_ON)
    Std_ReturnType RetVal = E_NOT_OK;

    RetVal = RtcDrvCdd_TemperatureCompensation_DeInit();

    RtcDrvCdd_TempCompCnter = 0;

    return RetVal; 
	
    #else
	return E_OK;

    #endif
}

void RtcDrvCdd_MainFunction(void)
{

#if (TEMP_COMPENSATION == STD_ON)
    sint16 boardTemp = 0;
    RtcDrvCdd_TempCompCnter++;
    if(RtcDrvCdd_TempCompCnter >= RTCDRVCDD_TEMP_READ_DELAY)
    {
        if((uint8)E_OK == ReadBoardTemp(&boardTemp))
        {
            RtcDrvCdd_TemperatureCompensation_CheckCompensation(boardTemp);
        }
        RtcDrvCdd_TempCompCnter = 0;
    }

    RtcDrvCdd_AlarmInterruptHandler();
#endif
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Sets the time value in the SCU RTC
///
/// @param  time structure
///
/// @return E_OK: Set the time and date are successful,
///         E_NOT_OK: Set the time and date failed.
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_SetTime(const cRTCCDD_TIME_TYPE* p_time)
{
    Std_ReturnType RetVal = E_NOT_OK;
RTCCDD_ENTER_CRITICAL_SECTION();
    if(SC_ERR_NONE == sc_ipc_open(&rtc_ipc, PORT_IPC_CHANNEL_ID))
    {
        if(SC_ERR_NONE == sc_timer_set_rtc_time(rtc_ipc, p_time->year, p_time->month, p_time->day, p_time->hour, p_time->minute, p_time->second))
        {
            RetVal = E_OK;
        }
    }
    sc_ipc_close(rtc_ipc);
RTCCDD_EXIT_CRITICAL_SECTION();
    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Gets the current SCU RTC time.
///
/// @param  p_time The pointer to the RTC Time structure
///
/// @return E_OK: Time Read Sucess, E_NOT_OK: Time Read Failure
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_GetTime(cRTCCDD_TIME_TYPE* p_time)
{
    Std_ReturnType RetVal = E_NOT_OK;
RTCCDD_ENTER_CRITICAL_SECTION();
    if(SC_ERR_NONE == sc_ipc_open(&rtc_ipc, PORT_IPC_CHANNEL_ID))
    {
        if(SC_ERR_NONE == sc_timer_get_rtc_time(rtc_ipc, &(p_time->year), &(p_time->month), &(p_time->day), &(p_time->hour), &(p_time->minute), &(p_time->second)))
        {
            RetVal = E_OK;
        }
    }
    sc_ipc_close(rtc_ipc);
RTCCDD_EXIT_CRITICAL_SECTION();
    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Sets SCU RTC alarm
///
/// @param  alarm:      The alarm configuration structure
///
/// @return E_OK: Setting alarm is successful,
///         E_NOT_OK: Setting the alarm failed.
//---------------------------------------------------------------------------------------------------------------------
#ifdef RTC_ALARM_FUNCTIONALITY_ENABLED
Std_ReturnType RtcDrvCdd_SetAlarm(const cRTCCDD_ALARM_TIME_TYPE* p_alarm)
{
    Std_ReturnType RetVal = E_NOT_OK;

    if((uint8)E_OK == RtcDrvCdd_EnableAlarmNotification())
    {
        RTCCDD_ENTER_CRITICAL_SECTION();
        if(SC_ERR_NONE == sc_ipc_open(&rtc_ipc, PORT_IPC_CHANNEL_ID))
        {    
		    if(SC_ERR_NONE == sc_timer_set_rtc_alarm(rtc_ipc, p_alarm->year, p_alarm->month, p_alarm->day, p_alarm->hour, p_alarm->minute, p_alarm->second))
            {
                RetVal = E_OK;
            }
        }
        sc_ipc_close(rtc_ipc);
		RTCCDD_EXIT_CRITICAL_SECTION();
    }

    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Sets SCU RTC periodic alarm
///
/// @param  p_alarm: pointer to periodicity in seconds
///
/// @return E_OK: Setting the periodic alarm is successful,
///         E_NOT_OK: Setting the periodic alarm failed.
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_SetPeriodicAlarm(const cRTCCDD_PERIODIC_ALARM_TIME_TYPE* p_alarm)
{
    Std_ReturnType RetVal = E_NOT_OK;

    if((uint8)E_OK == RtcDrvCdd_EnableAlarmNotification())
    {
        RTCCDD_ENTER_CRITICAL_SECTION();
        if(SC_ERR_NONE == sc_ipc_open(&rtc_ipc, PORT_IPC_CHANNEL_ID))
        {        
			if(SC_ERR_NONE == sc_timer_set_rtc_periodic_alarm(rtc_ipc,(uint32_t)*p_alarm))
        	{
            	RetVal = E_OK;
            }
        }
        sc_ipc_close(rtc_ipc);
		RTCCDD_EXIT_CRITICAL_SECTION();
    }

    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Clears the SCU RTC alarm
///
/// @return E_OK: Clearing alarm is successful,
///         E_NOT_OK: Clearing the alarm failed.
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_ClearAlarm(void)
{
    Std_ReturnType RetVal = E_NOT_OK;
RTCCDD_ENTER_CRITICAL_SECTION();
    if(SC_ERR_NONE == sc_ipc_open(&rtc_ipc, PORT_IPC_CHANNEL_ID))
    {
        if(SC_ERR_NONE == sc_timer_cancel_rtc_alarm(rtc_ipc))
        {
            RetVal = E_OK;
        }
    }
    sc_ipc_close(rtc_ipc);
RTCCDD_EXIT_CRITICAL_SECTION();
    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Clears the periodic SCU RTC alarm
///
/// @return E_OK: Clearing alarm is successful,
///         E_NOT_OK: Clearing the alarm failed.
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_ClearPeriodicAlarm(void)
{
    return RtcDrvCdd_ClearAlarm();
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Enable Alarm notification
///
///  @return E_OK: Alarm Notification is enabled successfully; E_NOT_OK: Alarm Notification is not enabled
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_EnableAlarmNotification(void)
{
    Std_ReturnType RetVal =  E_NOT_OK;
RTCCDD_ENTER_CRITICAL_SECTION();
    if(SC_ERR_NONE == sc_ipc_open(&rtc_ipc, PORT_IPC_CHANNEL_ID))
    {
        if(SC_ERR_NONE == sc_irq_enable(rtc_ipc, SC_R_M4_0_MU_1A, SC_IRQ_GROUP_RTC, SC_IRQ_RTC, TRUE))
        {
            RetVal = E_OK;
        }
    }
    sc_ipc_close(rtc_ipc);
 RTCCDD_EXIT_CRITICAL_SECTION();   
    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Disable Alarm notification
///
///  @return E_OK: Alarm Notification is disabled successfully; E_NOT_OK: Alarm Notification is not disabled
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_DisableAlarmNotification(void)
{
    Std_ReturnType RetVal =  E_NOT_OK;
RTCCDD_ENTER_CRITICAL_SECTION();    
    if(SC_ERR_NONE == sc_ipc_open(&rtc_ipc, PORT_IPC_CHANNEL_ID))
    {    
        if(SC_ERR_NONE == sc_irq_enable(rtc_ipc, SC_R_M4_0_MU_1A, SC_IRQ_GROUP_RTC, SC_IRQ_RTC, FALSE))
        {
            RetVal = E_OK;
        }
    }
    sc_ipc_close(rtc_ipc);
RTCCDD_EXIT_CRITICAL_SECTION();
    return RetVal;
} 
#endif

#if (RTCCDD_HW_DERIVATIVE == RTCCDD_HW_DERIVATIVE_IMX8)
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Gets the seconds since 1/1/1970
///
/// @param  RtcCdd_SecVal The pointer to get the seconds
///
/// @return E_OK: Seconds Sucess, E_NOT_OK: Seconds Failure
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_GetSec1970(uint32 *RtcCdd_SecVal)
{
    Std_ReturnType RetVal = E_NOT_OK;
	uint32_t RtcCdd_SecTemp = 0U;
RTCCDD_ENTER_CRITICAL_SECTION();
    if(SC_ERR_NONE == sc_ipc_open(&rtc_ipc, PORT_IPC_CHANNEL_ID))
    {
        if(SC_ERR_NONE == sc_timer_get_rtc_sec1970(rtc_ipc, &RtcCdd_SecTemp))
        {
            RetVal = E_OK;
        }
    }
    sc_ipc_close(rtc_ipc);
    
	*RtcCdd_SecVal = RtcCdd_SecTemp;
RTCCDD_EXIT_CRITICAL_SECTION();
    return RetVal;
}
#endif

#endif /* RTCDRVCDD_IMX8QXP_C */

