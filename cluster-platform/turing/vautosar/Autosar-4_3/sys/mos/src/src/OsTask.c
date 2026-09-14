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
 * @file        OsTask.c
 * @details     <b>Implements the Os task functionality for Autosar 4.2.1</b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef OS_TASK_C
#define OS_TASK_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "OsMetrics.h"
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

#define OS_TASK_UNSIGNED_VALUE_ONE           1U

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
extern osMetricType osMetrics[osMetricsMaxCount];

/**
 * @brief osActivateTask - The task is transferred from the suspended state into the ready state
 *
 * @param TaskIndex
 *
 * @return StatusType
 */

StatusType osActivateTask (TaskType TaskIndex)
{
    #ifdef mOS_SUPPORT_INTERNAL_METRICS
    osMetrics[0].StartTime  = OsGetTimerCount();
    osMetrics[0].ValFlag    = TRUE;
    #endif
    StatusType Ret = E_OK;
    Ret = osSysActivateTask(TaskIndex);
    //todo: Needs critical section for below block
    if(0U != OsCtrlParam.RequestScheduler)
    {
        if(0U == OsCtrlParam.LockDispatcher)
        {
            osDispatch();
        }
    }

    return Ret;

}

/**
 * @brief osSysActivateTask - The task is transferred from the suspended state into the ready state
 *
 * @param TaskIndex
 *
 * @return StatusType
 */

StatusType osSysActivateTask (TaskType TaskIndex)
{
    StatusType    Ret = E_OS_ID;
    
    if(TaskIndex < OsNumberOfTasks)
    {    
        OsTaskParamRefType const pTaskParam = TcbTaskRefConfig[TaskIndex]->TaskParamRef;

        OsPrvEnterCriticalSection();
        #if (CC_TYPE == ECC1 || CC_TYPE == ECC2)
            pTaskParam->SetEventMask = 0;
        #endif
        
        /* todo: Check for the Activation Count Threshold here */
        if(TcbTaskRefConfig[TaskIndex]->TaskMaxActivationCount <= pTaskParam->ActivationCnt)
        {
                /* OS Task Activation Limit Reached */
                OsErr_osApplicationErrorHook(OsDlt_OsActivateTask, &Ret, E_OS_LIMIT);
                //Not expected to reach here
        }
        else
        {
            if(pTaskParam->ActivationCnt == 0U)
            {
                pTaskParam->State = PRE_READY;
            }

            pTaskParam->ActivationCnt++;        //Increment the Activation Count

            /* Removed checking State(TaskIndex) READY or RUNNING as this is controlled 
             * by ActivationCnt now.
             * ActivationCnt can become zero only if the task gets terminated for BT.
             * Whereas ET are not supposed to call AcvitateTask more than once.         */

            osSchedInsertTask(TaskIndex);
        }

        OsPrvExitCriticalSection();

        Ret = E_OK;

    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsActivateTask, &Ret, E_OS_ID);
    }
    return Ret;
}

/**
 * @brief osTerminateTask - This service causes the termination of the calling task. The calling task is transferred from the running state into the suspended state
 *
 * @param void
 *
 * @return StatusType
 */

StatusType osTerminateTask (void)
{
    StatusType Ret = E_OK;
    if(OsCtrlParam.ActiveTaskIndex < OsNumberOfTasks)
    {
        OsTaskParamRefType const pTaskParam = TcbTaskRefConfig[OsCtrlParam.ActiveTaskIndex]->TaskParamRef;
        if(OsCtrlParam.CurrentContext == (uint16)osdCtxISRCat2)
        {
            Ret = E_OS_CALLEVEL;
        }
        if(pTaskParam->ResCnt > 0U)
        {
            Ret = E_OS_RESOURCE;
        }

        if (Ret != (uint8)E_OK)
        {
            OsErr_osApplicationErrorHook(OsDlt_OsTerminateTask, &Ret, Ret);
        }
        else
        {
            if(FALSE == osCheckInterruptsEnabled())
            {
                //SWS_Os_00239
                //Enable Interrupts
                osEnableAllInterrupts();
            OsErr_osApplicationErrorHook(OsDlt_OsTerminateTask, &Ret, E_OS_DISABLEDINT);
            }

            OsPrvEnterCriticalSection();
            if( pTaskParam->ActivationCnt > 0U) 
            {
            pTaskParam->ActivationCnt--;
            }
            else
            {
                DEBUG_ASSERT( FALSE );
            }

            if(pTaskParam->ActivationCnt != 0U)
            {
                pTaskParam->State = PRE_READY;
            }
            else
            {
                pTaskParam->State = SUSPENDED;
            }
            //todo: call this hook in ChainTask also once implemented
            #ifdef OS_ENABLE_STACK_MONITORING
            osCheckTaskStackOverflow(OsCtrlParam.ActiveTaskIndex);
            #endif
            osTaskStopHook();

            osSchedRemoveTask();

            OsCtrlParam.ActiveTaskIndex = INVALID_TASK;
            OsCtrlParam.ActiveTaskPriority = INVALID_PRIORITY;

            OsPrvExitCriticalSection();

            osDispatch();
        }
    }
    return Ret;
}

/**
 * @brief osSysTerminateTask - This service causes the termination of the calling task. The calling task is transferred from the running state into the suspended state
 *
 * @param void
 *
 * @return StatusType
 */

StatusType osSysTerminateTask (void)
{
    StatusType Ret = E_OK;
    if(OsCtrlParam.ActiveTaskIndex < OsNumberOfTasks)
    {
        OsTaskParamRefType const pTaskParam = TcbTaskRefConfig[OsCtrlParam.ActiveTaskIndex]->TaskParamRef;
        if(OsCtrlParam.CurrentContext == (uint16)osdCtxISRCat2)
        {
            Ret = E_OS_CALLEVEL;
        }
        if(pTaskParam->ResCnt > 0U)
        {
            Ret = E_OS_RESOURCE;
        }

        if (Ret != (uint8)E_OK)
        {
            OsErr_osApplicationErrorHook(OsDlt_OsTerminateTask, &Ret, Ret);
        }
        else
        {
            OsPrvEnterCriticalSection();
            if( pTaskParam->ActivationCnt > 0U) 
            {
            pTaskParam->ActivationCnt--;
            }
            else
            {
                DEBUG_ASSERT( FALSE );
            }

            if(pTaskParam->ActivationCnt != 0U)
            {
                pTaskParam->State = PRE_READY;
            }
            else
            {
                pTaskParam->State = SUSPENDED;
            }
            //todo: call this hook in ChainTask also once implemented
            osTaskStopHook();
            osSchedRemoveTask();
            OsCtrlParam.LockDispatcher = 0U;
            OsCtrlParam.ActiveTaskIndex = INVALID_TASK;
            OsCtrlParam.ActiveTaskPriority = INVALID_PRIORITY;
            OsPrvExitCriticalSection();
        }
    }
    return Ret;
}


/**
 * @brief OsSchedule - If a higher-priority task is ready, the internal resource of the task is released, the current task is put into the ready state, its context is saved and the higher-priority task is executed.
 *
 * @param void
 *
 * @return StatusType
 */

StatusType OsSchedule (void)
{
    StatusType Ret = E_OK;
    if(OsCtrlParam.ActiveTaskIndex < OsNumberOfTasks)
    {
        OsTaskParamRefType const pTaskParam = TcbTaskRefConfig[OsCtrlParam.ActiveTaskIndex]->TaskParamRef; /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
        
        OsPrvEnterCriticalSection();

        if(OsCtrlParam.CurrentContext != (uint16)osdScheduleAllowedContext)
        {
            Ret = E_OS_CALLEVEL;
        }

        OsPrvExitCriticalSection();
        
        if (FALSE == osCheckInterruptsEnabled())
        {
            Ret = E_OS_DISABLEDINT;     //todo: Check if we need to throw error or just enable interrupt and continue.
            osEnableAllInterrupts();
            OsDlt_LogMessage(OsDlt_OsSchedule,E_OS_DISABLEDINT);
        }

        if(pTaskParam->ResCnt > 0U)
        {
            Ret = E_OS_RESOURCE;
        }

        if(Ret != (StatusType)E_OK)
        {
            OsErr_osApplicationErrorHook(OsDlt_OsSchedule, &Ret, Ret);
        }
        else
        {
            /*Implementation starts here
            Start of Critial Section*/
            /*It is safe to disable interrupts as we have checked that we didnt enter here from a
            critical section*/
            OsPrvEnterCriticalSection();


            /************************************************************************
            If a higher-priority task is ready, the internal resource of the task
            is released, the current task is put into the ready state, its
            context is saved and the higher-priority task is executed.
            Otherwise the calling task is continued.*/

            OsSchedGetNextHighPrioTask(&OsCtrlParam);
            /*We will now have determined which is the Next Task to Run
            Check if we need a Task Switch*/

            if(OsSchedIsTaskSwitchReqd(&OsCtrlParam) != 0U)
            {
                /*We reach here to perform a TaskSwitch
                Set the RequestScheduler as TRUE before terminating the Critical Section*/
                OsCtrlParam.RequestScheduler = OS_TASK_UNSIGNED_VALUE_ONE;
                /* We reach here with interrupts disabled. Call exit critical section before dispatch */
                /* osEnableAllInterrupts called if global interrupts are disabled in osCheckInterruptsEnabled */
                OsPrvExitCriticalSection();

                /* Call the Dispatcher here as we have set the RequestScheduler*/
                osDispatch();
            }
        else
        {
            /* Exit critical section if task switch not required and return back */
            OsPrvExitCriticalSection();
        }

        }
    }
    return Ret;
}

/**
 * @brief osSysSchedule - If a higher-priority task is ready, the internal resource of the task is released, the current task is put into the ready state, its context is saved and the higher-priority task is executed.
 *
 * @param void
 *
 * @return StatusType
 */

StatusType osSysSchedule (void)
{
    StatusType Ret = E_OK;
    if(OsCtrlParam.ActiveTaskIndex < OsNumberOfTasks)
    {
        OsTaskParamRefType const pTaskParam = TcbTaskRefConfig[OsCtrlParam.ActiveTaskIndex]->TaskParamRef; /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
        OsPrvEnterCriticalSection();
        if(OsCtrlParam.CurrentContext != (uint16)osdScheduleAllowedContext)
        {
            Ret = E_OS_CALLEVEL;
        }
        OsPrvExitCriticalSection();
        if(pTaskParam->ResCnt > 0U)
        {
            Ret = E_OS_RESOURCE;
        }

        if(Ret != (StatusType)E_OK)
        {
            OsErr_osApplicationErrorHook(OsDlt_OsSchedule, &Ret, Ret);
        }
        else
        {
            /*Implementation starts here */
            /************************************************************************
            If a higher-priority task is ready, the internal resource of the task
            is released, the current task is put into the ready state, its
            context is saved and the higher-priority task is executed.
            Otherwise the calling task is continued.*/
            OsPrvEnterCriticalSection();
            OsSchedGetNextHighPrioTask(&OsCtrlParam);
            /*We will now have determined which is the Next Task to Run
            Check if we need a Task Switch*/

            if(OsSchedIsTaskSwitchReqd(&OsCtrlParam) != 0U)
            {
                /*We reach here to perform a TaskSwitch
                Set the RequestScheduler as TRUE before terminating the Critical Section*/
                OsCtrlParam.LockDispatcher = 0U;
                OsCtrlParam.RequestScheduler = OS_TASK_UNSIGNED_VALUE_ONE;
            }
            OsPrvExitCriticalSection();
        }
    }
    return Ret;
}

/**
 * @brief osGetTaskID - GetTaskID returns the information about the TaskID of the task which is currently running.
 *
 * @param TaskIdRef
 *
 * @return StatusType
 */

StatusType osGetTaskID (TaskRefType TaskIdRef)
{
    StatusType Ret = E_NOT_OK;

    if(NULL_PTR == TaskIdRef)
    {
        Ret = E_NOT_OK;
    }
    else
    {
        SuspendAllInterrupts();
        *TaskIdRef = OsCtrlParam.ActiveTaskIndex;
        ResumeAllInterrupts();
        Ret = E_OK;
    }
    return Ret;
}

/**
 * @brief osGetTaskState - Returns the state of a task (running, ready, waiting, suspended) at the time of calling GetTaskState
 *
 * @param TaskID
 * @param TaskState
 *
 * @return StatusType
 */

StatusType osGetTaskState (TaskType TaskID, TaskStateType* TaskState)
{
    StatusType RetVal = E_NOT_OK;

    if ((TaskID < OsNumberOfTasks) && (TaskState != NULL))
    {
        SuspendAllInterrupts();
        *TaskState = TcbTaskRefConfig[TaskID]->TaskParamRef->State;
        ResumeAllInterrupts();
        RetVal = E_OK;
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsGetTaskState, &RetVal, E_OS_ID);
    }
    return RetVal;
}


#define OS_CORE_CODE_SEC_END
#define OS_CORE_CONST_SEC_END
#define OS_CORE_DATA_SEC_END
#define OS_CORE_DATA_NOCACHE_SEC_END
#define OS_CORE_BSS_SEC_END
#include "Os_IntMemMap.h"

#endif
/*----------------------------------------------------------------------------------**
**  ------------------------------------------------------------------------------- **
**   ****************************************************************************   **
**      for each change to this file, be sure to record:                            **
**         1.  who made the change and when the change was made                     **
**         2.  why the change was made and the intended result                      **
**      Following block needs to be repeated for each change                        **
**   ****************************************************************************   **
**      Note: In the traceability column we need to trace back to the Design Doc.   **
**      For the initial version it is traced to the Design Document section.        **
**      For further changes it shall trace to the source of the change which may    **
**      be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any     **
**      other reason                                                                **
**   ****************************************************************************   **
**  ------------------------------------------------------------------------------- **
**                                                                                  **
**  ------------------------------------------------------------------------------- **
**   Date              : 09-Sep-2016                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : ------                                                     **
**   Change Description: Initial version.                                           **
**   ------------------------------------------------------------------------------ **
**  ------------------------------------------------------------------------------- **
**   Date              : 09-Dec-2019                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 1393561                                                    **
**   Change Description: Multiple task activation to be supported in mOS as per     **
**                       OSEK & Autosar Specification (BCC2*)                       **
**                       Added Failsafe mechanisms to ActivateTask and              **
**                       TerminateTask()
**   ------------------------------------------------------------------------------ **
**   Date              : 07-Mar-2020                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 785616                                                     **
**   Change Description: Remove Det Error and use Internal Error for multiple       **
**                       Activation Limit                                           **
**   ------------------------------------------------------------------------------ **
**   Date              : 17-Aug-2020                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 785616                                                     **
**   Change Description: Extended Error support for mOS                             **
**   ------------------------------------------------------------------------------ **
**   Date              : 13-May-2022                                                **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1648619                                                    **
**   Change Description: Coverity & Misra Medium Warning Fix                        **
**----------------------------------------------------------------------------------**
**   Date              : 09-June-2022                                               **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1679233                                                    **
**   Change Description: Coverity & Misra Low Warning Fix                           **
**----------------------------------------------------------------------------------**
**----------------------------------------------------------------------------------*/

