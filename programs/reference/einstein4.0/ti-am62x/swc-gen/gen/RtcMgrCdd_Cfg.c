/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2025. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/

/******************************************************************************

File Name        :  RtcDrvCdd_Cfg.h
Module Short Name:  Rtc
VOBName          :  
Author           :  kporkodi
Description      :  This file contains configurations needed for Rtc module
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef RTCMGRCDD_CFG_C
#define RTCMGRCDD_CFG_C

#include "RtcMgrCdd_Cfg.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

#define DISABLED                            (255u)

#define RTC_MAX_DAYS_PER_MONTH              (31u)            // Days per week definition
#define RTC_MONTHS_PER_YEAR                 (12u)           // Month per year definition
#define RTC_MAX_SEC_OR_MIN                  (59u)           // Maximum value of seconds and minutes
#define RTC_MAX_HOURS_24H                   (23u)           // Biggest seconds or minutes definition
#define RTC_MAX_YEAR                        (99u)           // Maximum value of year definition
#define RTC_FEBRUARY						(2u)

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

#define RTC_TWO_THOUSAND_YEARS              (2000u)         // Two thousand years definition

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

//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

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

    if((Month == 0u) || (Month > RTC_MONTHS_PER_YEAR))
    {
        return 0u;
    }
    
    RetVal = Rtc_DaysInMonthTable[Month - 1ul];

    if (RTC_FEBRUARY == Month)
    {
        if (Rtc_IsLeapYear(Year))
        {
            RetVal++;
        }
    }
    return RetVal;
}

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================
//----------------------------------------------------------------------
/// @brief  Sets the current time from the RA8900CE registers from pointer to Rtc_TimeDateType structure.
///
/// @param  pTimeDate: The pointer to the structure of time and date.
///
/// @return E_OK
///         E_NOT_OK
//----------------------------------------------------------------------
Std_ReturnType RtcDrvCddWrp_SetTime(const cRTCCDD_TIME_TYPE* pTimeDate)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 tmpDaysInMonth;

    if ((0u < pTimeDate->month) && (RTC_MONTHS_PER_YEAR >= pTimeDate->month) && (RTC_MAX_YEAR >= pTimeDate->year))
    {
        tmpDaysInMonth = Rtc_DaysInMonth(pTimeDate->month, (pTimeDate->year + RTC_TWO_THOUSAND_YEARS));
        if ((0u < pTimeDate->day) && (pTimeDate->day <= tmpDaysInMonth))
        {
            if ((pTimeDate->hour <= RTC_MAX_HOURS_24H) && (pTimeDate->minute <= RTC_MAX_SEC_OR_MIN) &&
                (pTimeDate->second <= RTC_MAX_SEC_OR_MIN))
            {
                RetVal = RtcDrvCdd_SetTime(pTimeDate);
            }
        }
    }

    return RetVal;
}

//----------------------------------------------------------------------
/// @brief  Sets the alarm settings provided as cRTCCDD_ALARM_TIME_TYPE structure to the RA8900CE registers
///
/// @param  pAlarm: The structure for alarm configuration:
///
/// @return E_INVALID_ARG
/// 		E_OK
///         E_NOT_OK
//----------------------------------------------------------------------
Std_ReturnType RtcDrvCddWrp_SetAlarm(const cRTCCDD_ALARM_TIME_TYPE* Alarm)
{
    Std_ReturnType RetVal = E_NOT_OK;

    if (((Alarm->minute == DISABLED) || (Alarm->minute <= RTC_MAX_SEC_OR_MIN)) &&
        ((Alarm->hour == DISABLED) || (Alarm->hour <= RTC_MAX_HOURS_24H)) &&
        ((Alarm->day == DISABLED) || ((0u < Alarm->day) && (Alarm->day <= RTC_MAX_DAYS_PER_MONTH))))
    {
        RetVal = RtcDrvCdd_SetAlarm(Alarm);
    }
    return RetVal;
}

#endif


/*****************************************************************************
*     End of File
*
******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
