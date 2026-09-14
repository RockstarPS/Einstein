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

#include "RtcDrvCdd_TemperatureCompensation.h"
#include "misc_api.h"
#include "timer_api.h"

//=====================================================================================================================
//  SNVS LPGPR 2 and 3 structure:
//  
//  LPGPR2 shall store only ErAc which is sint32
//  LPGPR3 shall store Temp_0 (sint16, but only 12 used) in its MS 12 bits,
//  TimeStamp_0 (uint16, but only 12 used) in its next 12 bits and
//  SleepCompensationCounter in its LS 8 bits
//=====================================================================================================================

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

#define LPGPR2 2u
#define LPGPR3 3u

#define BOARD_CTL_SNVS_WRITE_GPR    (0xeU)
#define BOARD_CTL_SNVS_READ_GPR     (0xfU)
#define BOARD_CTL_SRTC_GET_CALIB    (0x10U)

#define LPGPR3_TEMP_SHIFT              20u
#define LPGPR3_TIMESTAMP_SHIFT          8u
#define LPGPR3_TIMESTAMP_MASK      (0xFFFU)
#define LPGPR3_COMP_COUNTER_MASK    (0xFFU)

#define HOUR_IN_SECONDS              3600u

#define RTC_CALIB_VAL_MAX              15
#define RTC_CALIB_VAL_MIN             -16

#define RTCDRVCDD_BOARD_TEMP_MIN      -40
#define RTCDRVCDD_BOARD_TEMP_MAX      215

#define RTCDRVCDD_CALIB_VAL_SIGN_MASK      0x10
#define RTCDRVCDD_CALIB_VAL_SIGN_EXTENSION 0xF0


static RtcNvmCalibParams_t rtcNvm;

typedef struct
{
    SFP25_6 erAc;
    SFP11_4 temp_0 : 12;
    uint16 timeStamp_0 : 12;
    uint8 compCounter  : 8;
} RtcSnvsCalibParams_t;

static volatile RtcSnvsCalibParams_t rtcSnvs;

static SFP11_4 currentTemp = 0;
static volatile uint16 currentTimeStamp = 0;

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

static Std_ReturnType UpdateSnvs(void);
static boolean isInColdState(void);
static SFP7_8 Multiply_K_By_Set(SFP7_8, SFP23_8);
static Std_ReturnType StoreCurrentRtcTimeModHour(void);
static void InterpretCalibVal(sint8*);

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

static uint32 rtc_ipc;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Multiplies K coefficient with SET value, while avoiding overflow, as described in RTC temp comp POC
///         and returns the result converted back in SFP7_8
///
/// @param  k quartz temp coefficient
/// @param  set Square Equivalent Temperature      
///
/// @return Result of multiplication in SFP7_8
///
//---------------------------------------------------------------------------------------------------------------------
static SFP7_8 Multiply_K_By_Set(SFP7_8 k, SFP23_8 set)
{
    SFP47_16 expanded = (SFP47_16)((SFP47_16)k * (SFP47_16)set);

    return (SFP7_8)((expanded / 4096) >> 8);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Sign extends the calibration value received from the SRTC if needed
///
/// @param  calib pointer to calibration value
//---------------------------------------------------------------------------------------------------------------------
static void InterpretCalibVal(sint8 *calib)
{
    if((*calib & RTCDRVCDD_CALIB_VAL_SIGN_MASK) == RTCDRVCDD_CALIB_VAL_SIGN_MASK)
    {
        *calib |= RTCDRVCDD_CALIB_VAL_SIGN_EXTENSION;
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Updates SNVS LPGPR2 and LPGPR3 with the persistent compensation params
///
/// @param  NA
///
/// @return E_NOT_OK - Update failed
///             E_OK - Update successful
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType UpdateSnvs(void)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32_t board_cmd = BOARD_CTL_SNVS_WRITE_GPR;
    uint32_t reg = LPGPR2;
    uint32_t reg_val = 0;

    reg_val = rtcSnvs.erAc;

    // write to LPGPR2
    if(SC_ERR_NONE == sc_misc_board_ioctl(rtc_ipc, &board_cmd, &reg, &reg_val))
    {
        reg = LPGPR3;
        reg_val = 0;

        if(rtcSnvs.temp_0 < RTCDRVCDD_BOARD_TEMP_MIN*RTCDRVCDD_TEMP_SCALE_FACTOR)
        {
            rtcSnvs.temp_0 = RTCDRVCDD_BOARD_TEMP_MIN*RTCDRVCDD_TEMP_SCALE_FACTOR;
        }
        if(rtcSnvs.temp_0 > RTCDRVCDD_BOARD_TEMP_MAX*RTCDRVCDD_TEMP_SCALE_FACTOR)
        {
            rtcSnvs.temp_0 = RTCDRVCDD_BOARD_TEMP_MAX*RTCDRVCDD_TEMP_SCALE_FACTOR;
        }
        rtcSnvs.temp_0 += (SFP11_4)(RTCDRVCDD_TEMP_OFFSET*RTCDRVCDD_TEMP_SCALE_FACTOR);

        reg_val |= rtcSnvs.temp_0 << LPGPR3_TEMP_SHIFT;
        reg_val |= (rtcSnvs.timeStamp_0 & LPGPR3_TIMESTAMP_MASK) << LPGPR3_TIMESTAMP_SHIFT;
        reg_val |= rtcSnvs.compCounter;
        
        // write to LPGPR3
        if(SC_ERR_NONE == sc_misc_board_ioctl(rtc_ipc, &board_cmd, &reg, &reg_val))
        {
            RetVal = E_OK;
        }
    }

    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Calculates and returns whether the cluster is in "Cold" state or not
///
/// @param  NA
///
/// @return Whether the cluster is in "Cold" state or not
//---------------------------------------------------------------------------------------------------------------------
static boolean isInColdState(void)
{
    return (rtcSnvs.compCounter*rtcNvm.fastRtcSamplingPeriod > rtcNvm.rtcCoolingDelay);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Retrieves and stores current RTC time modulo 1 hour (so only the minutes and seconds, in seconds)
///
/// @param  NA
///
/// @return E_NOT_OK - RTC time retrieval failed
///             E_OK - RTC time retrieval successful
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType StoreCurrentRtcTimeModHour(void)
{
    Std_ReturnType RetVal = E_NOT_OK;
    Rtc_TimeType time;

    if(SC_ERR_NONE == sc_timer_get_rtc_time(rtc_ipc, &(time.year), &(time.month), &(time.day), &(time.hour), &(time.minute), &(time.second)))
    {
        currentTimeStamp = time.minute*60 + time.second;
        RetVal = E_OK;
    }

    return RetVal;
}

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Initialization function for compensation.
///         Should be called only on POR from RtcDrvCdd_Activate
///
/// @param  NA
///
/// @return E_NOT_OK - Init failed
///             E_OK - Init successful
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_TemperatureCompensation_Init (void)
{
    Std_ReturnType RetVal = E_NOT_OK;

    if(E_OK == StoreCurrentRtcTimeModHour())
    {
        // Set TimeStamp_0 to current SRTC time mod hour (in seconds)
        rtcSnvs.timeStamp_0 = currentTimeStamp;

        // Set Temp_0 to current temp
        rtcSnvs.temp_0 = currentTemp;

        // Set Sleep Compensation Counter to 0
        rtcSnvs.compCounter = 0;

        // Set ErAc to 0
        rtcSnvs.erAc = 0;

        RetVal = E_OK;
    }

    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Updates SNVS contents and sets alarm for next wakeup
///
/// @param  NA
///
/// @return E_NOT_OK - DeInit failed
///             E_OK - DeInit successful
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_TemperatureCompensation_DeInit (void)
{
    Std_ReturnType RetVal = E_NOT_OK;

    if(E_OK == UpdateSnvs())
    {
        uint16 period = (isInColdState()) ? rtcNvm.slowRtcSamplingPeriod : rtcNvm.fastRtcSamplingPeriod;
        if(SC_ERR_NONE == sc_timer_set_rtc_periodic_alarm(rtc_ipc, period))
        {
            RetVal = E_OK;
        }
    }

    return RetVal;
}

void RtcDrvCdd_TemperatureCompensation_ConfigureNvmParams(RtcNvmCalibParams_t params)
{
    rtcNvm = params;
}

void RtcDrvCdd_TemperatureCompensation_ConfigureTemp(sint16 temp)
{
    currentTemp = temp;
}

void RtcDrvCdd_TemperatureCompensation_ConfigureIpc(uint32 ipc)
{
    rtc_ipc = ipc;
}

void RtcDrvCdd_TemperatureCompensation_IncrementSleepCompCounter(void)
{
    rtcSnvs.compCounter++;
}

void RtcDrvCdd_TemperatureCompensation_ResetSleepCompCounter(void)
{
    rtcSnvs.compCounter = 0;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Performs the temp comp algo and sets the new calibration value
///
/// @param  NA
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
void RtcDrvCdd_TemperatureCompensation_Compensate(void)
{
    // Error compensation:
    // --- 1st step --- //
    SFP23_8 set = (SFP23_8)((SFP23_8)(rtcSnvs.temp_0 - rtcNvm.rtcCalib_Tc)*(SFP23_8)(currentTemp - rtcNvm.rtcCalib_Tc) 
                    + (SFP23_8)(currentTemp - rtcSnvs.temp_0)*(SFP23_8)(currentTemp - rtcSnvs.temp_0)/3);
    uint16 timeDiff = ((currentTimeStamp - rtcSnvs.timeStamp_0) + HOUR_IN_SECONDS) % HOUR_IN_SECONDS;
    SFP25_6 quartzError = (timeDiff * (Multiply_K_By_Set(rtcNvm.rtcCalib_K, set) + rtcNvm.rtcCalib_E_R_FC)) >> 2;

    // --- 2nd step --- //
    uint32_t rtcCalib = 0;
    uint32_t dummyParam = 0;
    uint32_t board_cmd = BOARD_CTL_SRTC_GET_CALIB;
    sc_misc_board_ioctl(rtc_ipc, &board_cmd, &rtcCalib, &dummyParam);
    InterpretCalibVal((sint8 *)&rtcCalib);
    SFP25_6 rtcCompensated = (SFP25_6)((timeDiff * (sint8)rtcCalib) << 6);

    // --- 3rd step --- //
    rtcSnvs.erAc += quartzError - rtcCompensated;
    SFP25_6 tempCalib = rtcSnvs.erAc / rtcNvm.rtcCompensationDelay;
    int8_t newRtcCalib = ((tempCalib > -64) && (tempCalib < 0)) ? 0 : tempCalib >> 6;

    if(newRtcCalib < RTC_CALIB_VAL_MIN)
    {
        newRtcCalib = RTC_CALIB_VAL_MIN;
    }
    if(newRtcCalib > RTC_CALIB_VAL_MAX)
    {
        newRtcCalib = RTC_CALIB_VAL_MAX;
    }

    sc_timer_set_rtc_calb(rtc_ipc, newRtcCalib);
    rtcSnvs.temp_0 = currentTemp;
    rtcSnvs.timeStamp_0 = currentTimeStamp;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Checks if the sampling period has been reached and if so, executes the temp comp
///
/// @param  temp temperature at the time of calling this function
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
void RtcDrvCdd_TemperatureCompensation_CheckCompensation(sint16 temp)
{
    // checks whether it is time for executing the temp comp algorithm
    if((E_OK == StoreCurrentRtcTimeModHour()) 
        && (((currentTimeStamp - rtcSnvs.timeStamp_0) + HOUR_IN_SECONDS) % HOUR_IN_SECONDS >= rtcNvm.fastRtcSamplingPeriod))
    {
        RtcDrvCdd_TemperatureCompensation_ConfigureTemp(temp);
        RtcDrvCdd_TemperatureCompensation_Compensate();
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Stores SNVS LPGPR2 and LPGPR3 contents into static vars for further use
///
/// @param  NA
///
/// @return E_NOT_OK - Reading SNVS regs failed
///             E_OK - Reading SNVS regs successful
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_TemperatureCompensation_ReadSnvs(void)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32_t board_cmd = BOARD_CTL_SNVS_READ_GPR;
    uint32_t reg = LPGPR2;
    uint32_t reg_val = 0;

    // read from LPGPR2
    if(SC_ERR_NONE == sc_misc_board_ioctl(rtc_ipc, &board_cmd, &reg, &reg_val))
    {
        rtcSnvs.erAc = (SFP25_6)reg_val;

        reg = LPGPR3;
        reg_val = 0;
        
        // read from LPGPR3
        if(SC_ERR_NONE == sc_misc_board_ioctl(rtc_ipc, &board_cmd, &reg, &reg_val))
        {
            rtcSnvs.temp_0 = (SFP11_4)((SFP11_4)(reg_val >> LPGPR3_TEMP_SHIFT) - (SFP11_4)(RTCDRVCDD_TEMP_OFFSET*RTCDRVCDD_TEMP_SCALE_FACTOR));
            rtcSnvs.timeStamp_0 = (uint16)((reg_val >> LPGPR3_TIMESTAMP_SHIFT) & LPGPR3_TIMESTAMP_MASK);
            rtcSnvs.compCounter = (uint8)(reg_val & LPGPR3_COMP_COUNTER_MASK);

            RetVal = E_OK;
        }
    }

    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  
///
/// @param  NA
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
void RtcDrvCdd_TemperatureCompensation_SetTime (void)
{
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  
///
/// @param  NA
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
void RtcDrvCdd_TemperatureCompensation_MainFunction (void)
{
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  
/// @param  NA
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
void RtcDrvCdd_TemperatureCompensation_AlarmNotification(void)
{
}
