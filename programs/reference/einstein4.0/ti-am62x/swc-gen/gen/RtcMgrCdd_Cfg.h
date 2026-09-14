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

File Name        :  RtcMgrCdd_Cfg.h
Module Short Name:  Rtc
VOBName          :  
Author           :  kporkodi
Description      :  This file contains configurations needed for Rtc module
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef RTCMGRCDD_CFG_H
#define RTCMGRCDD_CFG_H

#include "Std_Types.h"
#include "Rte_Type.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================


#define cRTCCDD_TIME_TYPE Rtc_TimeType
#define cRTCCDD_ALARM_TIME_TYPE Rtc_AlarmType
#define cRTCCDD_PERIODIC_ALARM_TIME_TYPE void

#define RTC_ALARM_FUNCTIONALITY_ENABLED

#include "RtcDrvCdd.h"
#include "RtcIfCdd.h"
//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================`
#ifdef RTCMGRCDD_C
#ifdef RtcIfCdd_SetTime
#undef RtcIfCdd_SetTime
#define RtcIfCdd_SetTime    RtcDrvCddWrp_SetTime
#endif
#ifdef RtcIfCdd_SetAlarm
#undef RtcIfCdd_SetAlarm
#define RtcIfCdd_SetAlarm   RtcDrvCddWrp_SetAlarm
#endif
#endif

Std_ReturnType RtcDrvCddWrp_SetTime(const cRTCCDD_TIME_TYPE* pTimeDate);
Std_ReturnType RtcDrvCddWrp_SetAlarm(const cRTCCDD_ALARM_TIME_TYPE* Alarm);

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

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
