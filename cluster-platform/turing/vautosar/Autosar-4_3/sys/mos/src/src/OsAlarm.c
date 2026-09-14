/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2013. Visteon Corporation owns all rights to
 this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right,
 under the copyright laws of the United States or those of any
 other country that may have jurisdiction, to protect this work
 as an unpublished work, in the event of an inadvertent or
 deliberate unauthorized publication. Visteon Corporation also
 reserves its rights under all copyright laws to protect this
 work as a published work, when appropriate. Those having access
 to this work may not copy it, use it, modify it or disclose the
 information contained in it without the written authorization
 of Visteon Corporation.
 * @endverbatim
 * @author      vbalakr3
 * @file        OsAlarm.c
 * @details     <b>Implements the Alarm concepts of Autosar 4.2.1</b>
 * @exception   Only limited APIs needed for the system are supported
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 * @date        19 July, 2016
 *
 * @copyright   Visteon (c) 2021
 *
 */


#ifndef OS_ALARM_C
#define OS_ALARM_C


/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "OsMain.h"
#include "OsPrivate.h"

//@cond
#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
//@endcond
#include "Os_IntMemMap.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define ALARMID_ACTIVATED                   1U

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/




/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/**
 * @brief The system service GetAlarm returns the relative value in ticks
            before the alarm <AlarmID> expires.
 *
 * @param AlarmID - Reference to an Alarm
 * @param Tick - Relative values in tick before the alarm <AlarmID> expires
 * @return STANDARD: <br>
 *          E_OK if prerequisites are satisfied <br>
 *          Alarm <AlarmID> is not used, E_OS_NOFUNC <br>
 *         EXTENDED:<br>
 *          Alarm <AlarmID> is invalid, E_OS_ID
 * @warning Cannot be called from a CAT1 context
 * @callgraph
 */
FUNC(StatusType, OS_CODE) Os_GetAlarm(AlarmType AlarmID, TickRefType Tick)
{
    VAR(StatusType, OS_VAR_MEMCLASS) Ret = E_NOT_OK;
    
    //Enter Critical Section
    SuspendAllInterrupts();
    if (AlarmID >= OsNumberOfAlarms)
    {
        OsErr_osApplicationErrorHook(OsDlt_osGetAlarm, &Ret, E_OS_ID);
    }
    else
    {
        OsAlarmParamRefType const pAlarmParam = AlarmRefConfig[AlarmID]->OsAlarmParamRef;
        if(ALARMID_ACTIVATED != pAlarmParam->AlarmActivated)
        {
            OsErr_osApplicationErrorHook(OsDlt_osGetAlarm, &Ret, E_OS_NOFUNC);
        }
        else
        {
            *Tick = pAlarmParam->AlarmTime;
            Ret = E_OK;
        }
    }
    //Leave Critical Section
    ResumeAllInterrupts();
    return Ret;
}


/**
 * @brief The system service occupies the alarm <AlarmID> element.
 * After <increment> ticks have elapsed, the task assigned to the
 * alarm <AlarmID> is activated or the assigned event (only for
 * extended tasks) is set or the alarm-callback routine is called.
 *
 * @param AlarmID - Reference to the alarm element
 * @param Increment - Relative value in ticks
 * @param Cycle - Cycle value in case of cyclic alarm. In case of single alarms,
 *        cycle shall be zero.
 * @return Standard:\n
 *              � No error, E_OK\n
 *              � Alarm <AlarmID> is already in use, E_OS_STATE\n
 *         Extended:\n
 *              � Alarm <AlarmID> is invalid, E_OS_ID\n
 *              � Value of <increment> outside of the admissible limits (lower
 *                  than zero or greater than maxallowedvalue), E_OS_VALUE\n
 *              � Value of <cycle> unequal to 0 and outside of the admissible
 *                  counter limits (less than mincycle or greater than maxallowedvalue), E_OS_VALUE\n
 * @warning Allowed on Task and ISR levels, but not in hook routines
 */
FUNC(StatusType, OS_CODE) Os_SetRelAlarm(AlarmType AlarmID, TickType Increment, TickType Cycle)
{
    VAR(StatusType, OS_VAR_MEMCLASS) Ret = E_NOT_OK;

    //Enter Critical Section
    SuspendAllInterrupts();
    if (AlarmID >= OsNumberOfAlarms)
    {
        OsErr_osApplicationErrorHook(OsDlt_osSetRelAlarm, &Ret, E_OS_ID);
    }
    else
    {
        OsAlarmParamRefType const pAlarmParam = AlarmRefConfig[AlarmID]->OsAlarmParamRef;
        if(ALARMID_ACTIVATED != pAlarmParam->AlarmActivated)
        {
            pAlarmParam->AlarmTime = Increment;
            pAlarmParam->AlarmCyclicTime = Cycle;
            pAlarmParam->AlarmActivated = ALARMID_ACTIVATED;
            Ret = E_OK;
        }
        else
        {
            OsErr_osApplicationErrorHook(OsDlt_osSetRelAlarm, &Ret, E_OS_STATE);
        }
    }
    
    //Leave Critical Section
    ResumeAllInterrupts();
    return Ret;
}


/**
 * @brief   <b>The system service cancels the alarm <AlarmID>.</b>
 *
 * @param   AlarmID - Reference to the alarm element
 * @return  Standard: \n
 *              � No error, E_OK \n
 *              � Alarm <AlarmID> not in use, E_OS_NOFUNC \n
 *          Extended: \n
 *              � Alarm <AlarmID> is invalid, E_OS_ID \n
 *          Conformance: \n
 *              BCC1, BCC2, ECC1, ECC2
 */
FUNC(StatusType, OS_CODE) Os_CancelAlarm(AlarmType AlarmID)
{
    VAR(StatusType, OS_VAR_MEMCLASS) Ret = E_NOT_OK;
    
    //Enter Critical Section
    SuspendAllInterrupts();

    if (AlarmID >= OsNumberOfAlarms)
    {
        OsErr_osApplicationErrorHook(OsDlt_osCancelAlarm, &Ret, E_OS_ID);
    }
    else
    {
        OsAlarmParamRefType const pAlarmParam = AlarmRefConfig[AlarmID]->OsAlarmParamRef;
        if (ALARMID_ACTIVATED != pAlarmParam->AlarmActivated)
        {
            OsErr_osApplicationErrorHook(OsDlt_osCancelAlarm, &Ret, E_OS_NOFUNC);
        }
        else
        {
            pAlarmParam->AlarmActivated = 0U;
            Ret = E_OK;
        }
    }
    
    //Leave Critical Section
    ResumeAllInterrupts();
    return Ret;
}


FUNC(Std_ReturnType, OS_CODE) Os_SetAbsAlarm(AlarmType AlarmID, TickType Time, TickType Cycle)
{
    VAR(Std_ReturnType, OS_VAR_MEMCLASS) Ret = E_NOT_OK;
    
    //Enter Critical Section
    SuspendAllInterrupts();

    if (AlarmID >= OsNumberOfAlarms)
    {
        OsErr_osApplicationErrorHook(OsDlt_osSetAbsAlarm, &Ret, E_OS_ID);
    }
    else
    {
        OsAlarmParamRefType const pAlarmParam = AlarmRefConfig[AlarmID]->OsAlarmParamRef;
        if(ALARMID_ACTIVATED != pAlarmParam->AlarmActivated)
        {
            pAlarmParam->AlarmTime = Time;
            pAlarmParam->AlarmCyclicTime = Cycle;
            pAlarmParam->AlarmActivated = ALARMID_ACTIVATED;
            Ret = E_OK;
        }
        else
        {
            OsErr_osApplicationErrorHook(OsDlt_osSetAbsAlarm, &Ret, E_OS_STATE);
        }
    }
    return Ret;
}

//@cond
#define OS_CORE_CODE_SEC_END
#define OS_CORE_CONST_SEC_END
#define OS_CORE_DATA_SEC_END
#define OS_CORE_DATA_NOCACHE_SEC_END
#define OS_CORE_BSS_SEC_END
//@endcond
#include "Os_IntMemMap.h"


#endif
/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*---------------------------------------------------------------------------
Date               : 19-Jul-2016
CDSID              : vbalakr3
Traceability       :
Change Description : Initial version
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 9-Sep-2016
CDSID              : ssukuma1
Traceability       :
Change Description : Review comments fixed in osProcessAlarms()
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 03-Sep-2019
CDSID              : ssebast1
Traceability       : RTC #559985, #589988, #589993, #589994
Change Description : Return values handling of Os_SetRelAlarm, Os_GetAlarm
                     and Os_CancelAlarm Updated.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 13-May-2022                                             
CDSID             : eganesan                                                 
RTC Id            : 1648619                                                   
Change Description: Coverity & Misra Medium Warning Fix                        
**----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 09-June-2022                                             
CDSID             : eganesan                                                 
RTC Id            : 1679233                                                   
Change Description: Coverity & Misra Low Warning Fix                        
**----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 15-Mar-2024                                             
CDSID             : ssukuma1                                                
RTC Id            : PE4TI29141-1159                                         
Change Description: Bsw General & Compiler Abstraction changes
**----------------------------------------------------------------------------*/
/* end of file =============================================================*/

