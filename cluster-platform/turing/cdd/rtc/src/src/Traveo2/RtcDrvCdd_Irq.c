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

#ifndef RTCDRVCDD_IRQ_C
#define RTCDRVCDD_IRQ_C

#include "RtcCdd_Types.h"
#include "RtcIfCdd_Cbk.h"
#include "RtcDrvCdd_Cfg.h"
#include "RtcMgrCdd.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

// Definitions for RTC interrupt sources
#define RTC_INTR_ALARM1                         BACKUP_INTR_ALARM1_Msk      // Alarm 1 Mask
#define RTC_INTR_ALARM2                         BACKUP_INTR_ALARM2_Msk      // Alarm 2Mask
#define RTC_INTR_CENTURY                       BACKUP_INTR_CENTURY_Msk     // This interrupt will occur when the year is reached to 2100
                                                                            // over the year field value from 99 to 0

//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

static uint32 Rtc_GetInterruptStatusMasked(void);
static void Rtc_SetInterruptMask(uint32 InterruptMask);
static void Rtc_ClearInterruptMask(uint32 InterruptMask);
static void Rtc_ClearInterruptRequest(uint32 InterruptMask);
static boolean IsRtcWakeUp;
//=====================================================================================================================
//  PRIVATE
//=====================================================================================================================

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Returns an interrupt request register masked by the interrupt mask. Returns a result of the bitwise AND
///         operation between the corresponding interrupt requestand mask bits.
///
/// @param  NA
///
/// @return Bit mapping information.
//---------------------------------------------------------------------------------------------------------------------
static uint32 Rtc_GetInterruptStatusMasked(void)
{
    // The RTC interrupt registers must be read twice to guarantee accuracy and only the second 
    // read contains valid data. The first read data cannot be guaranteed as valid.

    (void)(BACKUP->unINTR_MASKED.u32Register);
    return(BACKUP->unINTR_MASKED.u32Register);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Enable interrupt event.
///
/// @param  NA
///
/// @return Bit mapping information.
//---------------------------------------------------------------------------------------------------------------------
static void Rtc_SetInterruptMask(uint32 InterruptMask)
{
    BACKUP->unINTR_MASK.u32Register |= InterruptMask;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Disable interrupt event.
///
/// @param  NA
///
/// @return Bit mapping information.
//---------------------------------------------------------------------------------------------------------------------
static void Rtc_ClearInterruptMask(uint32 InterruptMask)
{
    BACKUP->unINTR_MASK.u32Register &= (uint32)(~InterruptMask);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Clears RTC interrupts by setting each bit.
///
/// @param  InterruptMask The bit mask of interrupts to set
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
static void Rtc_ClearInterruptRequest(uint32 InterruptMask)
{
    BACKUP->unINTR.u32Register |= InterruptMask;
    (void)BACKUP->unINTR.u32Register;
}

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================
//---------------------------------------------------------------------------------------------------------------------
/// @brief
//---------------------------------------------------------------------------------------------------------------------
void RtcDrvCdd_CheckRtcWakeUpState(void)
{
    uint32 InterruptStatus;
    IsRtcWakeUp = FALSE;
    
    InterruptStatus = Rtc_GetInterruptStatusMasked();

    if (0uL != (RTC_INTR_ALARM2 & InterruptStatus))
    {
        IsRtcWakeUp = TRUE;
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief
//---------------------------------------------------------------------------------------------------------------------
void RtcDrvCdd_GetRtcWakeUpState(boolean *pIsRtcWakeUp)
{
    if(NULL_PTR != pIsRtcWakeUp)
    {
        *pIsRtcWakeUp = IsRtcWakeUp;
    }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Enable Alarm notification
///
/// @param: AlarmIndex
///
///  @return E_OK: Alarm Notification is enabled successfuly; E_NOT_OK: Alarm Notification is not enabled
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_EnableAlarmNotification(const uint8 AlarmIndex)
{
    Std_ReturnType RetValue = E_NOT_OK;
    uint32 InterruptMask = 0uL;

    if (AlarmIndex < RTC_ALARM_MAX)
    {
        InterruptMask = (uint32)(1u << AlarmIndex);
        Rtc_ClearInterruptRequest(InterruptMask);
        Rtc_SetInterruptMask(InterruptMask);
        RetValue = E_OK;
    }
    return RetValue;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Disable Alarm notification
///
/// @param: AlarmIndex
///
///  @return E_OK: Alarm Notification is disable successfuly; E_NOT_OK: Alarm Notification is not disabled
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_DisableAlarmNotification(const uint8 AlarmIndex)
{
    Std_ReturnType RetValue = E_NOT_OK;
    uint32 InterruptMask = 0uL;

    if (AlarmIndex < RTC_ALARM_MAX)
    {
        InterruptMask = (uint32)(1u << AlarmIndex);
        Rtc_ClearInterruptRequest(InterruptMask);
        Rtc_ClearInterruptMask(InterruptMask);
        RetValue = E_OK;
    }
    return RetValue;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Enable Century notification
///
/// @param: NA
///
///  @return E_OK: Century Notification is enabled successfuly
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_EnableCenturyNotification(void)
{
    uint32 InterruptMask = (uint32)(1 << BACKUP_INTR_CENTURY_Pos);

    Rtc_ClearInterruptRequest(InterruptMask);
    Rtc_SetInterruptMask(InterruptMask);
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  RTC Disable Century notification
///
/// @param: NA
///
///  @return E_OK: Century Notification is disabled successfuly
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType RtcDrvCdd_DisableCenturyNotification(void)
{
    uint32 InterruptMask = (uint32)(1 << BACKUP_INTR_CENTURY_Pos);

    Rtc_ClearInterruptRequest(InterruptMask);
    Rtc_ClearInterruptMask(InterruptMask);
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief The interrupt handler function which should be called in user provided RTC interrupt function.
///
/// @param  NA
///
/// @return NA
//---------------------------------------------------------------------------------------------------------------------
void RtcDrvCdd_AlarmInterruptHandler(void)
{
    uint32 InterruptStatus;

    InterruptStatus = Rtc_GetInterruptStatusMasked();
    Rtc_ClearInterruptRequest(InterruptStatus);

    if (0uL != (RTC_INTR_ALARM1 & InterruptStatus))
    {
        RtcIf_AlarmNotification(RTC_ALARM_1);
    }

    if (0uL != (RTC_INTR_ALARM2 & InterruptStatus))
    {
        RtcIf_AlarmNotification(RTC_ALARM_2);
    }

    if (0uL != (RTC_INTR_CENTURY & InterruptStatus))
    {
        RtcIf_CenturyNotification();
    }
}
void Os_Isr_RtcDrvCdd_AlarmInterruptHandler(void)
{
    RtcDrvCdd_AlarmInterruptHandler();
}
#endif

