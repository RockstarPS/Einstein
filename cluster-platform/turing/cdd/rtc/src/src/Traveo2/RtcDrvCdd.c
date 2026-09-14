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

#ifndef RTCDRVCDD_C
#define RTCDRVCDD_C

#include "RtcDrvCdd.h"
#include "RtcDrvCdd_Cfg.h"
#include "RtcMgrCdd_Cfg.h"
#include "Mcu.h"
#include "McuExt.h"
#include "Port.h"
#include "MathLib.h"
#include "RtcDrvCdd_TemperatureCompensation.h"
#include "RtcDrvCdd_TemperatureCompensation_Cfg.h"
#include "EcuM.h"
#include "EcuMExt.h"
#include "RtcMgrCdd.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

#define RTC_WRITE_DISABLED                  (0u)           // Writing the RTC is disabled
#define RTC_WRITE_ENABLED                   (1u)           // Writing the RTC is enabled

#define RTC_BUSY                            (1u)           // RTC Busy bit is set, RTC is pending
#define RTC_AVAILABLE                       (0u)           // RTC Busy bit is cleared, RTC is available

#define RTC_12HRS_PM_BIT                    (0x20uL)         // RTC AM/PM bit for 12H hour mode
#define RTC_BACKUP_RTC_TIME_RTC_PM          ((uint32) (RTC_12HRS_PM_BIT << BACKUP_RTC_TIME_RTC_HOUR_Pos)) // Mask for reading RTC AM/PM bit for 12H mode
#define RTC_BACKUP_RTC_TIME_RTC_12HOUR      (0x1F0000uL)   // Mask for reading RTC hour for 12H mode

#define RTC_DELAY_WRITE_US                  (62u)           // Definition of 2 WCO clocks in microseconds
#define RTC_DELAY_WHILE_READING_US          (183u)          // Definition of 6 WCO clocks in microseconds

// Clock source for the RTC block
#define RTC_CLK_SRC_WCO                     (0u)            // WCO is the clock source
#define RTC_CLK_SRC_ALTBAK                  (1u)            // ALTBAK is the clock source
#define RTC_CLK_SRC_ILO_0                   (2u)            // ILO_0 is the clock source

#define RTC_DAYS_PER_WEEK                   (7u)            // Days per week definition
#define RTC_MONTHS_PER_YEAR                 (12u)           // Month per year definition
#define RTC_MAX_SEC_OR_MIN                  (59u)           // Maximum value of seconds and minutes
#define RTC_MAX_HOURS_24H                   (23u)           // Biggest seconds or minutes definition
#define RTC_MAX_YEAR                        (99u)           // Maximum value of year definition

// Definition of days in current month
#define RTC_DAYS_IN_JANUARY                 (31u)           // Number of days in January
#define RTC_DAYS_IN_FEBRUARY                (28u)           // Number of days in February
#define RTC_DAYS_IN_MARCH                   (31u)           // Number of days in March
#define RTC_DAYS_IN_APRIL                   (30u)           // Number of days in April
#define RTC_DAYS_IN_MAY                     (31u)           // Number of days in May
#define RTC_DAYS_IN_JUNE                    (30u)           // Number of days in June
#define RTC_DAYS_IN_JULY                    (31u)           // Number of days in July
#define RTC_DAYS_IN_AUGUST                  (31u)           // Number of days in August
#define RTC_DAYS_IN_SEPTEMBER               (30u)           // Number of days in September
#define RTC_DAYS_IN_OCTOBER                 (31u)           // Number of days in October
#define RTC_DAYS_IN_NOVEMBER                (30u)           // Number of days in November
#define RTC_DAYS_IN_DECEMBER                (31u)           // Number of days in December

#define RTC_HOURS_PER_HALF_DAY              (12u)           // Half day hours definition

#define RTC_TWO_THOUSAND_YEARS              (2000u)         // Two thousand years definition

#define RTC_CALIB_VAL_OFFSET                   (60u)           // Max value of CALIB_VAL

#define RTC_CHECK_STATUS_TIMEOUT            (1000u)         // Check status protection timeout

// Mask and shift a bit field value for use in a register bit range
#define VAL2FLD(field, value)                (((uint32)(value) << field ## _Pos) & field ## _Msk)

// Mask and shift a register value to extract a bit filed value.
#define FLD2VAL(field, value)                (((uint32)(value) & field ## _Msk) >> field ## _Pos)

#define FLD2BOOL(field, value)               (((value) & (field ## _Msk)) != 0UL)

typedef enum
{
    eRtcDriverNotInitialized = 0,
    eRtcDriverInitialized = 1
}ERtcDriverStatus;

typedef enum
{
    eRtcCheckResetReason = 0,
    eRtcWaitWcoStabilization = 1,
    eRtcInitialized = 2
} ERtcInitState;

typedef enum
{
    eRtcSetFreqOffsetSubState = 0,
    eRtcActivateTempCompSubState = 1,
    eRtcActivateTempComp = 2
} ERtcTaskState;

// RTC days in months table
uint8 const Rtc_DaysInMonthTable[RTC_MONTHS_PER_YEAR] =
{
    RTC_DAYS_IN_JANUARY,
    RTC_DAYS_IN_FEBRUARY,
    RTC_DAYS_IN_MARCH,
    RTC_DAYS_IN_APRIL,
    RTC_DAYS_IN_MAY,
    RTC_DAYS_IN_JUNE,
    RTC_DAYS_IN_JULY,
    RTC_DAYS_IN_AUGUST,
    RTC_DAYS_IN_SEPTEMBER,
    RTC_DAYS_IN_OCTOBER,
    RTC_DAYS_IN_NOVEMBER,
    RTC_DAYS_IN_DECEMBER
};

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

static boolean Rtc_IsLeapYear(const uint16 Year);
static uint8 Rtc_DaysInMonth(const uint8 Month, const uint16 Year);
static void Rtc_ConstructTime(const cRTCCDD_TIME_TYPE* Time, uint32* p_Time);
static void Rtc_ConstructDate(const cRTCCDD_DATE_TYPE* Date, uint32* p_Date);
static uint8 Rtc_GetSyncStatus(void);
static Std_ReturnType Rtc_WriteEnable(const uint8 WriteEnable);
static Std_ReturnType Rtc_SyncRegisters(void);
#if (RTC_INIT_CLOCK == STD_ON)
static void Rtc_SetClockSource(const uint8 ClockSource);
#endif
static Std_ReturnType Rtc_ConstructAlarmTimeDate(const Rtc_AlarmType* Alarm, uint32* pAlarmTime, uint32* pAlarmDate);
static uint8 Rtc_GetHoursFormat(void);
#if ((RTC_CLOCK_SOURCE == RTC_CLK_SRC_WCO) && (RTC_INIT_CLOCK == STD_ON))
static void Rtc_EnableWco(void);
#endif
#if (RTC_CLOCK_SOURCE == RTC_CLK_SRC_WCO)
static boolean Rtc_IsWcoOk(void);
static void Rtc_DisableWco(void);
#endif

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

static ERtcDriverStatus RtcDriverStatus = eRtcDriverNotInitialized;
static ERtcTaskState RtcTaskState = eRtcSetFreqOffsetSubState;

//TODO: put RtcInitState in BuRam
static ERtcInitState RtcInitState = eRtcCheckResetReason;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Checks whether the year passed through the parameter is leap or not
///
/// @param  year : The year to be checked
///
/// @return FALSE: The year is not leap; TRUE: The year is leap.
//---------------------------------------------------------------------------------------------------------------------
static boolean Rtc_IsLeapYear(const uint16 Year)
{
    return (0u != (((0u == (Year % 4uL)) && (0u != (Year % 100uL))) || (0u == (Year % 400uL))));
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Returns a number of days in a month passed through the parameters
///
/// @param  Month : The month of the year,
///         Year  : A year value.
///
/// @return FALSE: A number of days in a month in the year passed through the parameters.
//---------------------------------------------------------------------------------------------------------------------
static uint8 Rtc_DaysInMonth(const uint8 Month, const uint16 Year)
{
    uint8 RetVal;

    RetVal = Rtc_DaysInMonthTable[Month - 1uL];

    if (RTC_FEBRUARY == Month)
    {
        if (Rtc_IsLeapYear(Year))
        {
            RetVal++;
        }
    }
    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Converted Integer time(*Time) and Integer date(*date) are matched with RTC_TIME andRTC_DATE bit fields format.
///
/// @param  Time: The structure of time and date
///         p_Time: The Integer formatted time variable which is the same bit masks of the RTC_TIME register:
///                 [0:6] - Calendar seconds in Integer, range 0 - 59.
///                 [14:8] - Calendar minutes in Integer, range 0 - 59.
///                 [21:16] - Calendar hours in Integer, value depending on the 12 / 24 - hour mode.
///                 12HR : [21] : 0 = AM, 1 = PM, [20:16] = 1 - 12;
///                 24HR: [21:16] = 0 - 23;
///                 [22] - Selects the 12 / 24 - hour mode : 1 - 12 - hour, 0 - 24 - hour.
///                 [26:24] - A calendar day of the week, range 1 - 7, where 1 - Sunday.
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
static void Rtc_ConstructTime(const cRTCCDD_TIME_TYPE* Time, uint32* p_Time)
{
    uint32 tmpTime;

    // Prepare the RTC TIME value based on the structure obtained
    tmpTime  = VAL2FLD(BACKUP_RTC_TIME_RTC_SEC, Time->Second);
    tmpTime |= VAL2FLD(BACKUP_RTC_TIME_RTC_MIN, Time->Minute);

    // Read the current hour mode to know how many hour bits to convert.
    // In the 24-hour mode, the hour value is presented in [21:16] bits in the Integer format.
    // In the 12-hour mode, the hour value is presented in [20:16] bits in the Integer format and
    // bit [21] is present: 0 - AM; 1 - PM.

    if (RTC_24_HOURS != Time->HourMode)
    {
        if (RTC_AM != Time->AmPm)
        {
            // Set the PM bit
            tmpTime |= RTC_BACKUP_RTC_TIME_RTC_PM;
        }
        else
        {
            // Set the AM bit
            tmpTime &= ((uint32)~RTC_BACKUP_RTC_TIME_RTC_PM);
        }
        tmpTime |= BACKUP_RTC_TIME_CTRL_12HR_Msk;
        tmpTime |= VAL2FLD(BACKUP_RTC_TIME_RTC_HOUR, (Time->Hour & ((uint32)~RTC_12HRS_PM_BIT)));
    }
    else
    {
        tmpTime &= ((uint32)~BACKUP_RTC_TIME_CTRL_12HR_Msk);
        tmpTime |= VAL2FLD(BACKUP_RTC_TIME_RTC_HOUR, Time->Hour);
    }
    tmpTime |= VAL2FLD(BACKUP_RTC_TIME_RTC_DAY, Time->DayOfWeek);


    // Update the parameter values with prepared values
    *p_Time = tmpTime;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Converted Integer time(*Time) and Integer date(*date) are matched with RTC_TIME andRTC_DATE bit fields format.
///
/// @param  Date: The structure of date
///         p_Date: The Integer formatted date variable which is the same bit masks of the RTC_DATE register.
///                 [5:0] - A calendar day of a month in Integer, range 1 - 31.
///                 [12:8] - A calendar month in Integer, range 1 - 12.
///                 [23:16] - A calendar year in Integer, range 0 - 99.
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
static void Rtc_ConstructDate(const cRTCCDD_DATE_TYPE* Date, uint32* p_Date)
{
    uint32 tmpDate;

    // Prepare the RTC Date value based on the structure obtained
    tmpDate  = VAL2FLD(BACKUP_RTC_DATE_RTC_DATE, Date->Date);
    tmpDate |= VAL2FLD(BACKUP_RTC_DATE_RTC_MON,  Date->Month);
    tmpDate |= VAL2FLD(BACKUP_RTC_DATE_RTC_YEAR, Date->Year);

    *p_Date = tmpDate;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Return current status of RTC_BUSY. The status indicates
///         synchronization between RTC user registerand the actual RTC register.
///
/// @param  NA
///
/// @return  The status of RTC user register synchronization
//---------------------------------------------------------------------------------------------------------------------
static uint8 Rtc_GetSyncStatus(void)
{
    return (FLD2BOOL(BACKUP_STATUS_RTC_BUSY, BACKUP->unSTATUS.u32Register) ? RTC_BUSY : RTC_AVAILABLE);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Set/Clear writeable option for RTC user registers. When the Write bit is set,
///         data can be written into the RTC user registersAfter all the RTC writes are
///         done, the firmware must clear(call Rtc_WriteEnable(RTC_WRITE_DISABLED))
///         the Write bit for the RTC update to take effect.
///
/// @param  WriteEnable
///
/// @return  E_OK - Set/Clear Write bit was successful;
///          E_NOT_READY - RTC is busy with a previous update.
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType Rtc_WriteEnable(const uint8 WriteEnable)
{
    Std_ReturnType RetVal = E_NOT_READY;
    uint16 u16CounterL = RTC_CHECK_STATUS_TIMEOUT;

    if (RTC_WRITE_ENABLED == WriteEnable)
    {
        while ((E_OK != RetVal) && (u16CounterL--))
        {
            // RTC Write bit set is possible only in condition that RTC_BUSY bit = 0 or RTC Read bit is not set
            if ((RTC_BUSY != Rtc_GetSyncStatus()) && (!FLD2BOOL(BACKUP_RTC_RW_READ, BACKUP->unRTC_RW.u32Register)))
            {
                RetVal = E_OK;
            }
        }

        if (E_OK == RetVal)
        {
            BACKUP->unRTC_RW.u32Register |= BACKUP_RTC_RW_WRITE_Msk;
        }
    }
    else
    {
        // Clearing Write Bit to complete write procedure
        BACKUP->unRTC_RW.u32Register &= ((uint32)~BACKUP_RTC_RW_WRITE_Msk);
        // Delay to guarantee data write after clearing write bit
        Rtc_DelayUs(RTC_DELAY_WRITE_US);
        RetVal = E_OK;
    }
    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  The Synchronizer updates RTC values into AHB RTC user registers from the actual RTC.
///
/// @param  NA
///
/// @return  E_OK - Read RTC registers is possible
///          E_NOK_OK - Read RTC registers is impossible
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType Rtc_SyncRegisters(void)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint16 u16CounterL = RTC_CHECK_STATUS_TIMEOUT;

    Rtc_EnterCriticalSection();
    while ((E_OK != RetVal) && (u16CounterL--))
    {
        // RTC Read is possible only in the condition that RTC_BUSY bit = 0 or RTC Write bit is not set.
        if ((RTC_BUSY != Rtc_GetSyncStatus()) && (!FLD2BOOL(BACKUP_RTC_RW_WRITE, BACKUP->unRTC_RW.u32Register)))
        {
            RetVal = E_OK;
        }
    }

    if (E_OK == RetVal)
    {
        // Setting RTC Read bit
        BACKUP->unRTC_RW.u32Register = BACKUP_RTC_RW_READ_Msk;

        // Delay to guarantee RTC data reading
        Rtc_DelayUs(RTC_DELAY_WHILE_READING_US);

        // Clearing RTC Read bit
        BACKUP->unRTC_RW.u32Register = 0uL;
    }
    Rtc_ExitCriticalSection();

    return RetVal;
}

#if (RTC_INIT_CLOCK == STD_ON)
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Sets the clock source for the RTC block
///
/// @param  The clock source to be set
///
/// @return  NA
//---------------------------------------------------------------------------------------------------------------------
static void Rtc_SetClockSource(const uint8 ClockSource)
{
    BACKUP->unCTL.stcField.u1WCO_BYPASS = 0u;       // Watch crystal. Connect a 32.768 kHz watch crystal between WCO input and output pins.
    BACKUP->unCTL.stcField.u2CLK_SEL = ClockSource;
}
#endif

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Returns the Integer time and Integer date in the format used in APIs from individual
///         elements passed for alarm.
///
/// @param Alarm config structure
///
///        pTimeDate  Integer formatted time variable which is same bit masks of ALMx_TIME register time fields :
///        [0:6] - Alarm seconds in Integer, range 0 - 59.
///        [7] - Alarm seconds Enable : 0 - ignore, 1 - match.
///        [14:8] - Alarm minutes in Integer, range 0 - 59.
///        [15] - Alarm minutes Enable : 0 - ignore, 1 - match.
///        [21:16] - Alarm hours in Integer, value depending on the 12 / 24 - hour mode (RTC_CTRL_12HR)
///        12HR : [21] : 0 = AM, 1 = PM, [20:16] = 1 - 12;
///        24HR: [21:16] = 0 - 23;
///        [23] - Alarm hours Enable : 0 - ignore, 1 - match;
///        [26:24] - An alarm day of the week, range 1 - 7, where 1 - Monday.
///        [31] - An alarm day of the week Enable : 0 - ignore, 1 - match.
///
///        AlarmDate The Integer formatted date variable which is the same bit masks of the ALMx_DATE register date fields :
///        [5:0] - An alarm day of a month in Integer, range 1 - 31.
///        [7] - An alarm day of a month Enable : 0 - ignore, 1 - match.
///        [12:8] - An alarm month in Integer, range 1 - 12.
///        [15] - An alarm month Enable : 0 - ignore, 1 - match.
///        [31] - The Enable alarm : 0 - Alarm is disabled, 1 - Alarm is enabled.
///
/// @return  NA
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType Rtc_ConstructAlarmTimeDate(const Rtc_AlarmType* Alarm, uint32* pAlarmTime, uint32* pAlarmDate)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32 tmpAlarmTime;
    uint32 tmpAlarmDate;
    uint32 tmpHourValue;

    // Prepare the RTC ALARM value based on the structure obtained
    tmpAlarmTime  = VAL2FLD(BACKUP_ALM1_TIME_ALM_SEC, Alarm->Second);
    tmpAlarmTime |= VAL2FLD(BACKUP_ALM1_TIME_ALM_SEC_EN, Alarm->Second_En);
    tmpAlarmTime |= VAL2FLD(BACKUP_ALM1_TIME_ALM_MIN, Alarm->Minute);
    tmpAlarmTime |= VAL2FLD(BACKUP_ALM1_TIME_ALM_MIN_EN, Alarm->Minute_En);

    // Read the current hour mode to know how many hour bits to convert.
    // In the 24-hour mode, the hour value is presented in [21:16] bits in the Integer format.
    // In the 12-hour mode, the hour value is presented in [20:16] bits in the Integer format and bit [21] is present: 0 - AM; 1 - PM
    RetVal = Rtc_SyncRegisters();
    if (E_OK == RetVal)
    {
        if (RTC_24_HOURS != Rtc_GetHoursFormat())
        {
            // Convert the hour from the 24-hour mode into the 12-hour mode
            if (RTC_HOURS_PER_HALF_DAY <= Alarm->Hour)
            {
                // The current hour is more than 12 in the 24-hour mode. Set the PM bit and converting hour: hour = hour - 12
                tmpHourValue = (uint32)Alarm->Hour - RTC_HOURS_PER_HALF_DAY;
                tmpHourValue = ((0uL != tmpHourValue) ? tmpHourValue : RTC_HOURS_PER_HALF_DAY);
                tmpAlarmTime |= RTC_BACKUP_RTC_TIME_RTC_PM | VAL2FLD(BACKUP_ALM1_TIME_ALM_HOUR, tmpHourValue);
            }
            else if (1uL > Alarm->Hour)
            {
                // The current hour in the 24-hour mode is 0 which is equal to 12:00 AM
                tmpAlarmTime = (tmpAlarmTime & ((uint32)~RTC_BACKUP_RTC_TIME_RTC_PM)) | VAL2FLD(BACKUP_ALM1_TIME_ALM_HOUR, RTC_HOURS_PER_HALF_DAY);
            }
            else
            {
                // The current hour is less than 12. Set the AM bit
                tmpAlarmTime = (tmpAlarmTime & ((uint32)~RTC_BACKUP_RTC_TIME_RTC_PM)) | VAL2FLD(BACKUP_ALM1_TIME_ALM_HOUR, Alarm->Hour);
            }
            tmpAlarmTime |= BACKUP_RTC_TIME_CTRL_12HR_Msk;
        }
        else
        {
            tmpAlarmTime |= VAL2FLD(BACKUP_ALM1_TIME_ALM_HOUR, Alarm->Hour);
            tmpAlarmTime &= ((uint32)~BACKUP_RTC_TIME_CTRL_12HR_Msk);
        }
        tmpAlarmTime |= VAL2FLD(BACKUP_ALM1_TIME_ALM_HOUR_EN, Alarm->Hour_En);
        tmpAlarmTime |= VAL2FLD(BACKUP_ALM1_TIME_ALM_DAY, Alarm->DayOfWeek);
        tmpAlarmTime |= VAL2FLD(BACKUP_ALM1_TIME_ALM_DAY_EN, Alarm->DayOfWeek_En);

        // Prepare the RTC ALARM DATE value based on the obtained structure
        tmpAlarmDate  = VAL2FLD(BACKUP_ALM1_DATE_ALM_DATE, Alarm->Date);
        tmpAlarmDate |= VAL2FLD(BACKUP_ALM1_DATE_ALM_DATE_EN, Alarm->Date_En);
        tmpAlarmDate |= VAL2FLD(BACKUP_ALM1_DATE_ALM_MON, Alarm->Month);
        tmpAlarmDate |= VAL2FLD(BACKUP_ALM1_DATE_ALM_MON_EN, Alarm->Month_En);
        tmpAlarmDate |= VAL2FLD(BACKUP_ALM1_DATE_ALM_EN, Alarm->Alarm_En);

        // Update the parameter values with prepared values
        *pAlarmTime = tmpAlarmTime;
        *pAlarmDate = tmpAlarmDate;
    }
    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Returns current 12/24 hours mode.
///
/// @param  NA
///
/// @return The current RTC hour format
//---------------------------------------------------------------------------------------------------------------------
static uint8 Rtc_GetHoursFormat(void)
{
    return (uint8)(FLD2BOOL(BACKUP_RTC_TIME_CTRL_12HR, BACKUP->unRTC_TIME.u32Register) ? RTC_12_HOURS : RTC_24_HOURS);
}

#if ((RTC_CLOCK_SOURCE == RTC_CLK_SRC_WCO) && (RTC_INIT_CLOCK == STD_ON))
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Enables the WCO.
///
/// @param  NA
///
/// @return  NA
//---------------------------------------------------------------------------------------------------------------------
static void Rtc_EnableWco(void)
{
    BACKUP->unCTL.stcField.u1WCO_EN = 1u;
}
#endif

#if (RTC_CLOCK_SOURCE == RTC_CLK_SRC_WCO)
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Returns the status of WCO.
///
/// @param  NA
///
/// @return  TRUE - if WCO is ready,
///          FALSE - if WCO in not ready
//---------------------------------------------------------------------------------------------------------------------
static boolean Rtc_IsWcoOk(void)
{
    return (boolean)(BACKUP->unSTATUS.stcField.u1WCO_OK);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Disable the WCO.
///
/// @param  NA
///
/// @return  NA
//---------------------------------------------------------------------------------------------------------------------
static void Rtc_DisableWco(void)
{
    BACKUP->unCTL.stcField.u1WCO_EN = 0u;
}
#endif

void RtcDrvCdd_DelayUs(uint16 microseconds)
{
	RtcDrvCdd_DelayCycles((uint32) microseconds * SYSTEM_CORE_CLOCK);
}

__asm(
		"RtcDrvCdd_DelayCycles: \n"
			"ADDS r0, r0, #2 \n"
			"LSRS r0, r0, #2 \n"
			"BEQ RtcDrvCdd_DelayCycles_done \n"
		"RtcDrvCdd_DelayCycles_loop: \n"
			"ADDS r0, r0, #1 \n"
			"SUBS r0, r0, #2 \n"
			"BNE RtcDrvCdd_DelayCycles_loop \n"
			"NOP \n"
		"RtcDrvCdd_DelayCycles_done: \n"
			"BX lr \n"
			".endf RtcDrvCdd_DelayCycles \n"
	);


//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================
//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Initialization operations
///
/// @return E_NOT_READY - Driver is not initialized
///         E_OK - Driver is initialized
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_Init(void)
{
    Std_ReturnType RetVal = E_NOT_READY;
    Mcu_ResetType McuResetL;
#if (SW_COMPENSATION_TYPE == TEMP_COMPENSATION)
    Rtc_AlarmType RtcAlarmL = { 0 };
    cRTCCDD_TIME_TYPE RtcTimeL = { 0 };
#endif

    switch(RtcInitState)
    {
        case eRtcCheckResetReason:
            McuResetL = Mcu_GetResetReason();
            if((MCU_POWER_ON_RESET == McuResetL) || (MCU_XRES_RESET == McuResetL))
            {
                #if (RTC_INIT_CLOCK == STD_ON)
                    Rtc_SetClockSource(RTC_CLOCK_SOURCE);
                    #if (RTC_CLOCK_SOURCE == RTC_CLK_SRC_WCO)
                        Rtc_EnableWco();                           // Enable Watch-crystal oscillator (WCO)
                    #endif
                #endif
                RtcInitState = eRtcWaitWcoStabilization;
            }
            else
            {
                RtcDriverStatus = eRtcDriverInitialized;
                RtcInitState = eRtcInitialized;
				RetVal = E_OK;
            }
            break;

        case eRtcWaitWcoStabilization:
            #if (RTC_CLOCK_SOURCE == RTC_CLK_SRC_WCO)
                if (TRUE == Rtc_IsWcoOk())            // Check Watch-crystal oscillator (WCO) status
            #endif
                {
                    RtcDriverStatus = eRtcDriverInitialized;
                #if (SW_COMPENSATION_TYPE == TEMP_COMPENSATION)
                    // Set the first alarm for temp compensation 5min 30sec after Power on Reset or External Reset
                    RtcDrvCdd_TemperatureCompensation_Timeperiod_Init();
                    RetVal = RtcDrvCdd_GetTime(&RtcTimeL);
                    RetVal |= RtcDrvCdd_GetAlarm(&RtcAlarmL, RTC_ALARM_2);
                    if(E_OK == RetVal)
                    {
                        RtcAlarmL.Second = 30u;
                        RtcAlarmL.Second_En = 1u;
                        RtcAlarmL.Minute = RtcTimeL.Minute + cRtcDrvCdd_TempCpmpensationPeriod_RunMode;
                        if (RTC_MAX_SEC_OR_MIN < RtcAlarmL.Minute)
                        {
                            RtcAlarmL.Minute = RtcAlarmL.Minute - (RTC_MAX_SEC_OR_MIN + cRtcDrvCdd_TempCpmpensationPeriod_RunMode);
                        }
                        RtcAlarmL.Minute_En = 1u;
                        RtcAlarmL.Alarm_En = 1u;
                        RetVal = RtcDrvCdd_SetAlarm(&RtcAlarmL, RTC_ALARM_2);
                        if (E_OK == RetVal)
                        {
                            RetVal = RtcDrvCdd_EnableAlarmNotification(RTC_ALARM_2);
                            if (E_OK == RetVal)
                            {
                                RtcInitState = eRtcInitialized;
                            }
                        }
                    }
                #else
                    RtcInitState = eRtcInitialized;
                #endif
                }
            break;
    
        case eRtcInitialized:
            RetVal = E_OK;
            break;

        default:
            RtcInitState = eRtcCheckResetReason;
            break;
    }
    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC DeInitialization operations
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_DeInit(void)
{

#if (RTC_CLOCK_SOURCE == RTC_CLK_SRC_WCO)
    Rtc_DisableWco();
#endif
    RtcDriverStatus = eRtcDriverNotInitialized;

    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Activation operations
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_Activate(void)
{
    RtcTaskState = eRtcSetFreqOffsetSubState;
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Main operations
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------

void RtcDrvCdd_MainFunction(void)
{
#if (SW_COMPENSATION_TYPE == TEMP_COMPENSATION)
    uint8 u8FreqOffsetL;

    if (eRtcDriverInitialized == RtcDriverStatus)
	{
        switch (RtcTaskState)
        {	
			case eRtcSetFreqOffsetSubState:
                if (FALSE != RtcDrvCdd_GetNvmReadall())
                {
                    (void)RtcMgrCdd_ReadFrequencyOffset(&u8FreqOffsetL);
                    if (E_OK == RtcMgrCdd_SetFrequencyOffset(u8FreqOffsetL))
                    {
                        RtcTaskState = eRtcActivateTempCompSubState;
                    }
                }
                break;
            case eRtcActivateTempCompSubState:
                RtcDrvCdd_TemperatureCompensation_Init();
                RtcTaskState = eRtcActivateTempComp;
                break;	
			case eRtcActivateTempComp:
				RtcDrvCdd_TemperatureCompensation_MainFunction();
                RtcTaskState = eRtcActivateTempComp;
				break;
			default:
                RtcTaskState = eRtcSetFreqOffsetSubState;
				break;
		}
    }
#endif
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Sets the time and date values into the RTC_TIME and RTC_DATE registers.
///
/// @param  TimeDate structure
///
/// @return E_OK: Set the time and date are successful,
///         E_NOT_OK: Set the time and date failed.
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_SetTime(const cRTCCDD_TIME_TYPE* p_time)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32 tmpTime;

    if (eRtcDriverInitialized == RtcDriverStatus)
    {
            Rtc_ConstructTime(p_time, &tmpTime);
    
            // The RTC AHB register can be updated only under condition that the
            // Write bit is set and the RTC busy bit is cleared (RTC_BUSY = 0).

            Rtc_EnterCriticalSection();
            RetVal = Rtc_WriteEnable(RTC_WRITE_ENABLED);
            if (E_OK == RetVal)
            {
                BACKUP->unRTC_TIME.u32Register = tmpTime;

                // Clear the RTC Write bit to finish RTC register update
                RetVal = Rtc_WriteEnable(RTC_WRITE_DISABLED);
            }
            Rtc_ExitCriticalSection();

    }
    return RetVal;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Sets the time and date values into the RTC_TIME and RTC_DATE registers.
///
/// @param  TimeDate structure
///
/// @return E_OK: Set the time and date are successful,
///         E_NOT_OK: Set the time and date failed.
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_SetDate(const cRTCCDD_DATE_TYPE* p_date)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 tmpDaysInMonth;
    uint32 tmpDate;

    if (eRtcDriverInitialized == RtcDriverStatus)
    {
        // Check the input parameters valid ranges
        if ((0uL < p_date->Month) && ( RTC_MONTHS_PER_YEAR >= p_date->Month) && (RTC_MAX_YEAR >= p_date->Year))
        {
            tmpDaysInMonth = Rtc_DaysInMonth(p_date->Month, (p_date->Year + RTC_TWO_THOUSAND_YEARS));

            // Check if the date is in the valid range
            if ((0uL < p_date->Date) && (p_date->Date <= tmpDaysInMonth))
            {
                Rtc_ConstructDate(p_date, &tmpDate);

                // The RTC AHB register can be updated only under condition that the
                // Write bit is set and the RTC busy bit is cleared (RTC_BUSY = 0).

                Rtc_EnterCriticalSection();
                RetVal = Rtc_WriteEnable(RTC_WRITE_ENABLED);
                if (E_OK == RetVal)
                {
                    BACKUP->unRTC_DATE.u32Register = tmpDate;

                    // Clear the RTC Write bit to finish RTC register update
                    RetVal = Rtc_WriteEnable(RTC_WRITE_DISABLED);
                }
                Rtc_ExitCriticalSection();
            }
            else
            {
                RetVal = E_INVALID_ARG;
            }
        }
        else
        {
            RetVal = E_INVALID_ARG;
        }
    }
    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Gets the current RTC time. The AHB RTC Time and Date register values
///         are stored into the Rtc_TimeType structure.
///
/// @param  The pointer to the RTC Time structure
///
/// @return E_OK: Time Read Sucess, E_NOT_OK: Time Read Failure
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_GetTime(cRTCCDD_TIME_TYPE* p_time)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32 tmpTime;

    if (NULL == p_time)
    {
        RetVal = E_INVALID_ARG;
    }
    else
    {
        if (eRtcDriverInitialized == RtcDriverStatus)
        {
            // Read the current RTC time and date to validate the input parameters
            RetVal = Rtc_SyncRegisters();
            if (E_OK == RetVal)
            {
                // Write the AHB RTC registers date and time into the local variables and
                // updating the TimeDate structure elements

                tmpTime = BACKUP->unRTC_TIME.u32Register;

                p_time->Second   = (uint8)FLD2VAL(BACKUP_RTC_TIME_RTC_SEC,   tmpTime);
                p_time->Minute   = (uint8)FLD2VAL(BACKUP_RTC_TIME_RTC_MIN,   tmpTime);
                p_time->HourMode = (uint8)FLD2VAL(BACKUP_RTC_TIME_CTRL_12HR, tmpTime);

                // Read the current hour mode to know how many hour bits should be converted
                // In the 24-hour mode, the hour value is presented in [21:16] bits in the Integer format.
                // In the 12-hour mode the hour value is presented in [20:16] bits in the Integer
                // format and bit [21] is present: 0 - AM; 1 - PM.

                if (RTC_24_HOURS != p_time->HourMode)
                {
                    p_time->Hour = (uint8)((tmpTime & RTC_BACKUP_RTC_TIME_RTC_12HOUR) >> BACKUP_RTC_TIME_RTC_HOUR_Pos);
                    p_time->AmPm = (uint8)((0uL != (tmpTime & RTC_BACKUP_RTC_TIME_RTC_PM)) ? RTC_PM : RTC_AM);
                }
                else
                {
                    p_time->Hour = (uint8)FLD2VAL(BACKUP_RTC_TIME_RTC_HOUR, tmpTime);
                }
                p_time->DayOfWeek = (uint8)FLD2VAL(BACKUP_RTC_TIME_RTC_DAY,  tmpTime);
            }
        }
    }
    return RetVal;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Gets the current RTC time and date. The AHB RTC Time and Date register values
///         are stored into the cRTCCDD_DATE_TYPE structure.
///
/// @param  The pointer to the RTC TimeDate structure
///
/// @return E_OK: Time Read Sucess, E_NOT_OK: Time Read Failure
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_GetDate(cRTCCDD_DATE_TYPE* p_date)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32 tmpDate;

    if (NULL == p_date)
    {
        RetVal = E_INVALID_ARG;
    }
    else
    {
        if (eRtcDriverInitialized == RtcDriverStatus)
        {
            // Read the current RTC time and date to validate the input parameters
            RetVal = Rtc_SyncRegisters();
            if (E_OK == RetVal)
            {
                // Write the AHB RTC registers date and time into the local variables and
                // updating the TimeDate structure elements

                tmpDate = BACKUP->unRTC_DATE.u32Register;

                p_date->Date      = (uint8)FLD2VAL(BACKUP_RTC_DATE_RTC_DATE, tmpDate);
                p_date->Month     = (uint8)FLD2VAL(BACKUP_RTC_DATE_RTC_MON,  tmpDate);
                p_date->Year      = (uint8)FLD2VAL(BACKUP_RTC_DATE_RTC_YEAR, tmpDate);
            }
        }
    }
    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Sets alarm time and date values into the ALMx_TIME and ALMx_DATE registers.
///
/// @param  Alarm:      The alarm configuration structure
///         AlarmIndex: The alarm index to be configured
///
/// @return E_OK: Set alarm is successful,
///         E_NOT_OK: Set the alarm failed.
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_SetAlarm(const Rtc_AlarmType* Alarm, const uint8 AlarmIndex)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32 tmpAlarmTime;
    uint32 tmpAlarmDate;
    uint16 tmpYear;
    uint8 tmpDaysInMonth;

    if (RTC_ALARM_MAX <= AlarmIndex)
    {
        RetVal = E_INVALID_ARG;
    }
    else
    {
        if (eRtcDriverInitialized == RtcDriverStatus)
        {
            // Read the current RTC time and date to validate the input parameters
            RetVal = Rtc_SyncRegisters();
            if(E_OK == RetVal)
            {
                tmpYear = RTC_TWO_THOUSAND_YEARS + (uint16)FLD2VAL(BACKUP_RTC_DATE_RTC_YEAR, BACKUP->unRTC_DATE.u32Register);

                // Parameters validation
                if ((0uL < Alarm->Month) && (RTC_MONTHS_PER_YEAR >= Alarm->Month))
                {
                    tmpDaysInMonth = Rtc_DaysInMonth(Alarm->Month, tmpYear);

                    if ((0uL < Alarm->Date) && (Alarm->Date <= tmpDaysInMonth))
                    {
                        RetVal = Rtc_ConstructAlarmTimeDate(Alarm, &tmpAlarmTime, &tmpAlarmDate);
                        if (E_OK == RetVal)
                        {
                            // The RTC AHB register can be updated only under condition that the
                            //  Write bit is set and the RTC busy bit is cleared (RTC_BUSY = 0).
                            Rtc_EnterCriticalSection();
                            RetVal = Rtc_WriteEnable(RTC_WRITE_ENABLED);
                            if (E_OK == RetVal)
                            {
                                // Update the AHB RTC registers with formed values
                                if (RTC_ALARM_1 == AlarmIndex)
                                {
                                    BACKUP->unALM1_TIME.u32Register = tmpAlarmTime;
                                    BACKUP->unALM1_DATE.u32Register = tmpAlarmDate;
                                }
                                else
                                {
                                    BACKUP->unALM2_TIME.u32Register = tmpAlarmTime;
                                    BACKUP->unALM2_DATE.u32Register = tmpAlarmDate;
                                }
                                // Clear the RTC Write bit to finish RTC update
                                RetVal = Rtc_WriteEnable(RTC_WRITE_DISABLED);
                            }
                            Rtc_ExitCriticalSection();
                        }
                    }
                    else
                    {
                        RetVal = E_INVALID_ARG;
                    }
                }
                else
                {
                    RetVal = E_INVALID_ARG;
                }
            }
        }
    }
    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief Returns the current alarm time and date values from the ALMx_TIME and ALMx_DATE registers.
///
/// @param  Alarm structure
///         AlarmIndex - The alarm index to be read
///
/// @return E_OK: Alarm Read Sucess, E_NOT_OK: Alarm Read Failure
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_GetAlarm(Rtc_AlarmType* Alarm, const uint8 AlarmIndex)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32 tmpAlarmTime;
    uint32 tmpAlarmDate;
    uint8 tmpHourMode;

    if ((NULL == Alarm) || (RTC_ALARM_MAX <= AlarmIndex))
    {
        RetVal = E_INVALID_ARG;
    }
    else
    {
        if (eRtcDriverInitialized == RtcDriverStatus)
        {
            // Read the current RTC time and date to validate the input parameters
            if (E_OK == Rtc_SyncRegisters())
            {
                // Write the AHB RTC registers into the local variables and update the Alarm structure elements
                if (RTC_ALARM_1 == AlarmIndex)
                {
                    tmpAlarmTime = BACKUP->unALM1_TIME.u32Register;
                    tmpAlarmDate = BACKUP->unALM1_DATE.u32Register;
                    tmpHourMode  = (uint8)FLD2VAL(BACKUP_RTC_TIME_CTRL_12HR, BACKUP->unRTC_TIME.u32Register);

                    Alarm->Second = (uint8)FLD2VAL(BACKUP_ALM1_TIME_ALM_SEC, tmpAlarmTime);
                    Alarm->Second_En = (uint8)FLD2VAL(BACKUP_ALM1_TIME_ALM_SEC_EN, tmpAlarmTime);

                    Alarm->Minute = (uint8)FLD2VAL(BACKUP_ALM1_TIME_ALM_MIN, tmpAlarmTime);
                    Alarm->Minute_En = (uint8)FLD2VAL(BACKUP_ALM1_TIME_ALM_MIN_EN, tmpAlarmTime);

                    // Read the current hour mode to know how many hour bits to convert.
                    // In the 24-hour mode, the hour value is presented in [21:16] bits in the Integer format.
                    // In the 12-hour mode, the hour value is presented in [20:16] bits in the Integer format and bit [21] is present: 0 - AM; 1 - PM.

                    if (RTC_24_HOURS != tmpHourMode)
                    {
                        Alarm->Hour = (uint8)((tmpAlarmTime & RTC_BACKUP_RTC_TIME_RTC_12HOUR) >> BACKUP_ALM1_TIME_ALM_HOUR_Pos);

                        // In the structure, the hour value should be presented in the 24-hour mode. In
                        // that condition the firmware checks the AM/PM status and adds 12 hours to
                        // the converted hour value if the PM bit is set.

                        if ((RTC_HOURS_PER_HALF_DAY > Alarm->Hour) && (0uL != (BACKUP->unALM1_TIME.u32Register & RTC_BACKUP_RTC_TIME_RTC_PM)))
                        {
                            Alarm->Hour += RTC_HOURS_PER_HALF_DAY;
                        }

                        // Set zero hour, as the 12 A hour is zero hour in 24-hour format
                        if ((RTC_HOURS_PER_HALF_DAY == Alarm->Hour) && (0uL == (BACKUP->unALM1_TIME.u32Register & RTC_BACKUP_RTC_TIME_RTC_PM)))
                        {
                            Alarm->Hour = 0u;
                        }
                    }
                    else
                    {
                        Alarm->Hour = (uint8)FLD2VAL(BACKUP_ALM1_TIME_ALM_HOUR, tmpAlarmTime);
                    }
                    Alarm->Hour_En = (uint8)FLD2VAL(BACKUP_ALM1_TIME_ALM_HOUR_EN, tmpAlarmTime);

                    Alarm->DayOfWeek = (uint8)FLD2VAL(BACKUP_ALM1_TIME_ALM_DAY, tmpAlarmTime);
                    Alarm->DayOfWeek_En = (uint8)FLD2VAL(BACKUP_ALM1_TIME_ALM_DAY_EN, tmpAlarmTime);

                    Alarm->Date = (uint8)FLD2VAL(BACKUP_ALM1_DATE_ALM_DATE, tmpAlarmDate);
                    Alarm->Date_En = (uint8)FLD2VAL(BACKUP_ALM1_DATE_ALM_DATE_EN, tmpAlarmDate);

                    Alarm->Month = (uint8)FLD2VAL(BACKUP_ALM1_DATE_ALM_MON, tmpAlarmDate);
                    Alarm->Month_En = (uint8)FLD2VAL(BACKUP_ALM1_DATE_ALM_MON_EN, tmpAlarmDate);

                    Alarm->Alarm_En = (uint8)FLD2VAL(BACKUP_ALM1_DATE_ALM_EN, tmpAlarmDate);
                }
                else
                {
                    tmpAlarmTime = BACKUP->unALM2_TIME.u32Register;
                    tmpAlarmDate = BACKUP->unALM2_DATE.u32Register;
                    tmpHourMode = (uint8)FLD2VAL(BACKUP_RTC_TIME_CTRL_12HR, BACKUP->unRTC_TIME.u32Register);

                    Alarm->Second = (uint8)FLD2VAL(BACKUP_ALM2_TIME_ALM_SEC, tmpAlarmTime);
                    Alarm->Second_En = (uint8)FLD2VAL(BACKUP_ALM2_TIME_ALM_SEC_EN, tmpAlarmTime);

                    Alarm->Minute = (uint8)FLD2VAL(BACKUP_ALM2_TIME_ALM_MIN, tmpAlarmTime);
                    Alarm->Minute_En = (uint8)FLD2VAL(BACKUP_ALM2_TIME_ALM_MIN_EN, tmpAlarmTime);

                    // Read the current hour mode to know how many hour bits to convert.
                    // In the 24-hour mode, the hour value is presented in [21:16] bits in the Integer format.
                    // In the 12-hour mode the hour value is presented in [20:16] bits in the Integer format and bit [21] is present: 0 - AM; 1 - PM.

                    if (RTC_24_HOURS != tmpHourMode)
                    {
                        Alarm->Hour = (uint8)((tmpAlarmTime & RTC_BACKUP_RTC_TIME_RTC_12HOUR) >> BACKUP_ALM2_TIME_ALM_HOUR_Pos);

                        // In the structure, the hour value should be presented in the 24-hour mode. In
                        // that condition the firmware checks the AM/PM status and adds 12 hours to
                        // the converted hour value if the PM bit is set.

                        if ((RTC_HOURS_PER_HALF_DAY > Alarm->Hour) && (0uL != (BACKUP->unALM2_TIME.u32Register & RTC_BACKUP_RTC_TIME_RTC_PM)))
                        {
                            Alarm->Hour += RTC_HOURS_PER_HALF_DAY;
                        }
                        // Set zero hour, as the 12 am hour is zero hour in 24-hour format
                        else if ((RTC_HOURS_PER_HALF_DAY == Alarm->Hour) && (0uL == (BACKUP->unALM2_TIME.u32Register & RTC_BACKUP_RTC_TIME_RTC_PM)))
                        {
                            Alarm->Hour = 0u;
                        }
                        else
                        {
                            // No corrections are required
                        }
                    }
                    else
                    {
                        Alarm->Hour = (uint8)FLD2VAL(BACKUP_ALM2_TIME_ALM_HOUR, tmpAlarmTime);
                    }
                    Alarm->Hour_En = (uint8)FLD2VAL(BACKUP_ALM2_TIME_ALM_HOUR_EN, tmpAlarmTime);

                    Alarm->DayOfWeek = (uint8)FLD2VAL(BACKUP_ALM2_TIME_ALM_DAY, tmpAlarmTime);
                    Alarm->DayOfWeek_En = (uint8)FLD2VAL(BACKUP_ALM2_TIME_ALM_DAY_EN, tmpAlarmTime);

                    Alarm->Date = (uint8)FLD2VAL(BACKUP_ALM2_DATE_ALM_DATE, tmpAlarmDate);
                    Alarm->Date_En = (uint8)FLD2VAL(BACKUP_ALM2_DATE_ALM_DATE_EN, tmpAlarmDate);

                    Alarm->Month = (uint8)FLD2VAL(BACKUP_ALM2_DATE_ALM_MON, tmpAlarmDate);
                    Alarm->Month_En = (uint8)FLD2VAL(BACKUP_ALM2_DATE_ALM_MON_EN, tmpAlarmDate);

                    Alarm->Alarm_En = (uint8)FLD2VAL(BACKUP_ALM2_DATE_ALM_EN, tmpAlarmDate);
                }
                RetVal = E_OK;
            }
        }
    }
    return RetVal;
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
Std_ReturnType RtcDrvCdd_EnableCalibrationSignalOutput(const uint8 CalibrationSignal)
{
    Std_ReturnType RetVal = E_NOT_OK;

    switch (CalibrationSignal)
    {
        case RTC_CAL_512Hz:
        case RTC_CAL_2Hz:
        case RTC_CAL_1Hz:
            Rtc_EnterCriticalSection();
            RetVal = Rtc_WriteEnable(RTC_WRITE_ENABLED);
            if (E_OK == RetVal)
            {
                BACKUP->unCAL_CTL.stcField.u2CAL_SEL = CalibrationSignal;
                BACKUP->unCAL_CTL.stcField.u1CAL_OUT = 1u;
                // Clear the RTC Write bit to finish RTC register update
                RetVal = Rtc_WriteEnable(RTC_WRITE_DISABLED);
            }
            Rtc_ExitCriticalSection();
            PORT_SETPINMODE_TO_CALIBRATION();
            break;

        default:
            RetVal = E_INVALID_ARG;
            break;
    }
    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Disable calibration wave output signal
///
/// @param  NA
///
/// @return E_OK: Disable calibration wave output signal is successful
///         E_NOT_OK: Disable calibration wave output signal failed
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_DisableCalibrationSignalOutput(void)
{
    Std_ReturnType RetVal = E_NOT_OK;
    

    Rtc_EnterCriticalSection();
    RetVal = Rtc_WriteEnable(RTC_WRITE_ENABLED);
    if (E_OK == RetVal)
    {
        BACKUP->unCAL_CTL.stcField.u2CAL_SEL = 0u;
        // Clear the RTC Write bit to finish RTC register update
        RetVal = Rtc_WriteEnable(RTC_WRITE_DISABLED);
    }
    Rtc_ExitCriticalSection();
    PORT_SETPINMODE_TO_GPIO();

    return RetVal;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Read cumulated error
///
/// @param  NA
///
/// @return Cumulated error
//---------------------------------------------------------------------------------------------------------------------
uint32 RtcDrvCdd_ReadCumulatedError(void)
{
    return (BACKUP->unBREG[0].stcField.u32BREG);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Write cumulated error
///
/// @param  CumulatedError
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
void RtcDrvCdd_WriteCumulatedError(const uint32 CumulatedError)
{
    BACKUP->unBREG[0].stcField.u32BREG = CumulatedError;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Set frequency offset at 25C. This offset is compensated by the embedded HW mechanism in RTC
///
/// @param  s8FreqOffsetP - The fequency offset in PPMs
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_SetFrequencyOffset(const uint8 u8FreqOffsetPpm)
{
    uint8 u8FreqOffsetPpmL;
    Std_ReturnType RetVal = E_NOT_OK;

    u8FreqOffsetPpmL = (uint8)MathLib_AbsDelta((uint32)u8FreqOffsetPpm , (uint32)RTC_CALIB_VAL_OFFSET);

    Rtc_EnterCriticalSection();
    RetVal = Rtc_WriteEnable(RTC_WRITE_ENABLED);                // Set the RTC Write bit to start RTC register update

    if (E_OK == RetVal)
    {
        if (u8FreqOffsetPpm <= (uint8)60)
        {                                                       // The WCO frequency is faster then nominal
            BACKUP->unCAL_CTL.stcField.u1CALIB_SIGN = 0u;       // Remove pulses (it takes more clock ticks to count one second)
        }
        else
        {                                                       // The WCO frequency is slower then nominal																// The WCO frequency is slower then nominal		
			BACKUP->unCAL_CTL.stcField.u1CALIB_SIGN = 1u;       // Add pulses so it takes less clock ticks to count one second
        }
        BACKUP->unCAL_CTL.stcField.u6CALIB_VAL = u8FreqOffsetPpmL;
        RetVal = Rtc_WriteEnable(RTC_WRITE_DISABLED);           // Clear the RTC Write bit to finish RTC register update
    }
    Rtc_ExitCriticalSection();

    return RetVal;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Sets SCU RTC periodic alarm
///
/// @param  sec:      periodicity in seconds
///
/// @return E_OK: Setting the periodic alarm is successful,
///         E_NOT_OK: Setting the periodic alarm failed.
//---------------------------------------------------------------------------------------------------------------------

Std_ReturnType RtcDrvCdd_SetPeriodicAlarm(const cRTCCDD_PERIODIC_ALARM_TIME_TYPE* p_alarm)
{
	return E_NOT_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief Disables alarm interrupt function
///
/// @return E_OK
/// 		E_NOT_OK   
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_ClearAlarm(void)
{
    return E_OK;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief Stops fixed-cycle timer interrupt function
///
/// @return E_OK
/// 		E_NOT_OK   
//---------------------------------------------------------------------------------------------------------------------

Std_ReturnType RtcDrvCdd_ClearPeriodicAlarm(void)
{
	return E_NOT_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Notification function from Gpt module on timeout expiry.
//<br>      Call happnes in interrupt context!
/// @param  NA
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
void RtcDrvCdd_AlarmNotification(void)
{

}

#endif


