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
 * @file        OsTime.c
 * @details     <b>Implements the Os time functionality for Autosar 4.2.1</b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef OS_TIME_C
#define OS_TIME_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "OsPrivate.h"
#include "AssertLib.h"

#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/



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

static void osProcessAlarms (void);

/**
 * @brief osTimerInterrupt - ISR for processing counter, schedule table and alarms
 *
 * @param 
 *
 * @return 
 */
ISR(osTimerInterrupt)
{
    osIntIsrCallHook();
    
    osIncrementHardwareCounters();
    #if (OS_CFG_SCHEDULE_TABLE == STD_ON)     
    OsProcessScheduleTable();
    #endif
    osProcessAlarms();
    OsHal_CheckIntrPending();
}

/**
 * @brief osInitAlarms - Function to initialize alarms
 *
 * @param 
 *
 * @return void
 */

void osInitAlarms (void)
{
    AlarmType AlarmID = 0;
    for(AlarmID = 0; AlarmID < OsNumberOfAlarms; AlarmID++)
    {
        OsAlarmParamRefType const pAlarmParam = AlarmRefConfig[AlarmID]->OsAlarmParamRef;
        pAlarmParam->AlarmCyclicTime = 0U;
        pAlarmParam->AlarmTime = 0U;
        pAlarmParam->AlarmActivated = 0U;
        pAlarmParam->AlarmAutostartType = 0U;
    }
}

/**
 * @brief osInitTimer - Function to initialize timer
 *
 * @param 
 *
 * @return void
 */

void osInitTimer (void)
{
    OsStartTimer();
}


/**
 * @brief osProcessAlarms - Function to process alarms
 *
 * @param 
 *
 * @return void
 */

static void osProcessAlarms (void)
{
    AlarmType AlarmID = 0;

    for(AlarmID = 0; AlarmID < OsNumberOfAlarms; AlarmID++ )
    {
        const AlarmConfigRefType pAlarmConfig = AlarmRefConfig[AlarmID];
        OsAlarmParamRefType const pAlarmParam = pAlarmConfig->OsAlarmParamRef;

        if(0U != pAlarmParam->AlarmActivated)
        {
			if( pAlarmParam->AlarmTime > 0U) 
			{
				pAlarmParam->AlarmTime--;
			}
			else
			{
				DEBUG_ASSERT( FALSE );
			}

            if(0U == pAlarmParam->AlarmTime)
            {
                /* TODO - Callback/ActivateTask calling */
                switch(pAlarmConfig->OsAlarmAction)
                {
                    case ALARM_CALLBACK_ACTION:
                    {
                        pAlarmConfig->OsAlarmCallback();
                        break;
                    }
                    #if (CC_TYPE == ECC1 || CC_TYPE == ECC2)
                    case ALARM_SET_EVENT_ACTION:
                    {
                        (void)osSysSetEvent(pAlarmConfig->OsAlarmTask, pAlarmConfig->OsAlarmEvent);
                        break;
                    }
                    #endif
                    case ALARM_ACTIVATE_TASK_ACTION:
                    {
                        (void)osSysActivateTask(pAlarmConfig->OsAlarmActivateTaskRef->TasksID); /*MISRA RULE 17.7 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
                        break;
                    }
                    default:
                    {
                        /* this default case defends against a fatal internal error only */
                        osSysErrAssert();
                        break;
                    }
                }
                if(0U != pAlarmParam->AlarmCyclicTime)
                {
                    pAlarmParam->AlarmTime = pAlarmParam->AlarmCyclicTime;
                }
                else
                {
                    pAlarmParam->AlarmActivated = 0U;
                }
            }
        }
    }
}

#define OS_CORE_CODE_SEC_END
#define OS_CORE_CONST_SEC_END
#define OS_CORE_DATA_SEC_END
#define OS_CORE_DATA_NOCACHE_SEC_END
#define OS_CORE_BSS_SEC_END
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
Date               : 09-Sep-16
CDSID              : ssukuma1
Traceability       : 
Change Description : Initial version
-----------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------
Date              : 27/March/2022
By                : gthanapp
Traceability      : RTC #1564070
Change Description: Cert-C warning analysis and fix
----------------------------------------------------------------------------------------------------------------------*/
/**   Date              : 09-June-2022                                               **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1679233                                                    **
**   Change Description: Coverity & Misra Low Warning Fix                           **
**----------------------------------------------------------------------------------**/
/* end of file =============================================================*/

