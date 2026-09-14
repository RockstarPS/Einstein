/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  RtcDrvCdd.h                                          *
*  Module Short Name :  RTC                                                  *
*  Description       :  This file contains implementations of the Rtc Driver *
*                       for AM62PX series microcontrollers.                  *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Clang Compiler                                         *
* Target Hardware  :  AM62PX micro based Hardware Platform                   *
*                                                                            *
******************************************************************************/

#ifndef RTCDRVCDD_H
#define RTCDRVCDD_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "RtcDrvCdd_I2c.h"
#include "RtcMgrCdd_Cfg.h"

/*****************************************************************************
*                            Functions Declarations                         *
******************************************************************************/

/*============================================================================
** Function Name    :   RtcDrvCdd_Init
**
** Visibility       :   Public
**
** Description      :   Initializes the RTC driver.
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType - E_OK if initialization is successful
**
** Critical Section :   No
**==========================================================================*/

extern Std_ReturnType RtcDrvCdd_Init(void);

/*============================================================================
** Function Name    :   RtcDrvCdd_DeInit
**
** Visibility       :   Public
**
** Description      :   De-initializes the RTC driver.
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType - E_OK if de-initialization is successful
**
** Critical Section :   No
**==========================================================================*/

extern Std_ReturnType RtcDrvCdd_DeInit(void);

/*============================================================================
** Function Name    :   RtcDrvCdd_SetTime
**
** Visibility       :   Public
**
** Description      :   Sets the current time in the RA8900CE registers from
**                      the provided time/date structure.
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType - E_OK if  successful
**
** Critical Section :   No
**==========================================================================*/

extern Std_ReturnType RtcDrvCdd_SetTime(const cRTCCDD_TIME_TYPE* pTimeDate);

/*============================================================================
** Function Name    :   RtcDrvCddGetTime
**
** Visibility       :   Public
**
** Description      :   Gets the current time from the RA8900CE registers from
**                      the provided time/date structure.
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType - E_OK if successful
**
** Critical Section :   No
**==========================================================================*/

extern Std_ReturnType RtcDrvCdd_GetTime(cRTCCDD_TIME_TYPE* pTimeDate);

/*============================================================================
** Function Name    :   RtcDrvCdd_MainFunction
**
** Visibility       :   Public
**
** Description      :   Main function for RTC driver, to be called periodically
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**==========================================================================*/

extern void RtcDrvCdd_MainFunction(void);

/*============================================================================
** Function Name    :   RtcDrvCdd_Activate
**
** Visibility       :   Public
**
** Description      :   Activation for RTC driver
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**==========================================================================*/

extern Std_ReturnType RtcDrvCdd_Activate(void);

#ifdef RTC_ALARM_FUNCTIONALITY_ENABLED 
/*============================================================================
** Function Name    :   RtcDrvCdd_SetAlarm
**
** Visibility       :   Public
**
** Description      :   Sets the alarm settings provided in the alarm structure
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   Pointer to alarm configuration structure
**
** Outputs          :   Std_ReturnType E_OK if successful, E_NOT_OK otherwise
**
** Critical Section :   No
**==========================================================================*/

extern Std_ReturnType RtcDrvCdd_SetAlarm(const cRTCCDD_ALARM_TIME_TYPE* Alarm);

/*============================================================================
** Function Name    :   RtcDrvCdd_ClearAlarm
**
** Visibility       :   Public
**
** Description      :    Disables alarm interrupt function
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   Pointer to alarm configuration structure
**
** Outputs          :   Std_ReturnType - E_OK if successful, E_NOT_OK otherwise
**
** Critical Section :   No
**==========================================================================*/

extern Std_ReturnType RtcDrvCdd_ClearAlarm(void);

/*============================================================================
** Function Name    :   RtcDrvCdd_SetPeriodicAlarm
**
** Visibility       :   Public
**
** Description      :   Sets Fixed-cycle Timer for provided amount of time.
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   Pointer to alarm configuration structure
**
** Outputs          :   Std_ReturnType - E_OK if successful, E_NOT_OK otherwise
**
** Critical Section :   No
**==========================================================================*/

extern Std_ReturnType RtcDrvCdd_SetPeriodicAlarm(const cRTCCDD_PERIODIC_ALARM_TIME_TYPE* p_alarm);

/*============================================================================
** Function Name    :   RtcDrvCdd_ClearPeriodicAlarm
**
** Visibility       :   Public
**
** Description      :   Stops fixed-cycle timer interrupt function.
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   Pointer to alarm configuration structure
**
** Outputs          :   Std_ReturnType - E_OK if successful, E_NOT_OK otherwise
**
** Critical Section :   No
**==========================================================================*/

extern Std_ReturnType RtcDrvCdd_ClearPeriodicAlarm(void);

/*============================================================================
** Function Name    :   RtcDrvCdd_EnableAlarmNotification
**
** Visibility       :   Public
**
** Description      :   Enables alarm notifications.
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType - E_OK if successful, E_NOT_OK otherwise
**
** Critical Section :   No
**==========================================================================*/

extern Std_ReturnType RtcDrvCdd_EnableAlarmNotification(void);

/*============================================================================
** Function Name    :   RtcDrvCdd_DisableAlarmNotification
**
** Visibility       :   Public
**
** Description      :   Disables alarm notifications.
**
** Invocation       :   RtcIfCdd
**
** Inputs           :   None
**
** Outputs          :   Std_ReturnType - E_OK if successful, E_NOT_OK otherwise
**
** Critical Section :   No
**==========================================================================*/

extern Std_ReturnType RtcDrvCdd_DisableAlarmNotification(void);

#endif

#endif /* RTCDRVCDD_H */


/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 20-05-2025                                            */
/*Version           :                                                       */
/*By                : kporkodi                                              */
/*Traceability      :                                                       */
/*Change Description: Proveout, Initial Version                             */
/*--------------------------------------------------------------------------*/

