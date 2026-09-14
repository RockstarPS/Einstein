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
 * @file        OsEvent.c
 * @details     <b>Implements the Events concepts of Autosar 4.2.1</b>
 * @note
 *              Compiler    : Independent \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */

#ifndef OS_EVENT_C
#define OS_EVENT_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "OsMain.h"
#include "OsPrivate.h"
#include "AssertLib.h"

#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"

#if (CC_TYPE == ECC1 || CC_TYPE == ECC2)


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

/**
 * @brief SetEvent - The service may be called from an interrupt service routine and from the task level, but not from hook routines.
 *
 * @param TaskIndex
 * @param EventMask
 * @return StatusType
 */

StatusType osSetEvent ( TaskType TaskIndex, EventMaskType EventMask )
{
    StatusType Status = E_NOT_OK;
    if(TaskIndex < OsNumberOfTasks)
    {
    osuint8 CurrentTasksType = TcbTaskRefConfig[TaskIndex]->TasksType;

    if (CurrentTasksType != (uint8)TASK_EXTENDED)
    {
        OsErr_osApplicationErrorHook(OsDlt_OsSetEvent,&Status, E_OS_ACCESS);
    }
    else
    {
        OsPrvEnterCriticalSection();

        OsTaskParamRefType const pTaskParam = TcbTaskRefConfig[TaskIndex]->TaskParamRef;

        pTaskParam->SetEventMask    |= EventMask;

        if(pTaskParam->State == WAITING)
        {
            if(0U != (pTaskParam->SetEventMask & pTaskParam->WaitEventMask))
            {
                pTaskParam->State = READY;

                osSchedInsertTask(TaskIndex);

                if(0 != (Os_GetContext() & osdEventAllowedContext))
                {
                    if(0U != OsCtrlParam.RequestScheduler)
                    {
                        if(0U == OsCtrlParam.LockDispatcher)
                        {
                            OsPrvExitCriticalSection();
                            osDispatch();
                        }
                    }
                }
                
            }
            Status = E_OK;
        }
        else if(pTaskParam->State == SUSPENDED)
        {
            OsErr_osApplicationErrorHook(OsDlt_OsSetEvent, &Status, E_OS_STATE);
        }
        else
        {
            Status = E_OK;
            //Log this as we didnt do anything here
            //todo
        }

        OsPrvExitCriticalSection();
    }
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsSetEvent, &Status, E_OS_ID);
    }
    return Status;
}

/**
 * @brief SysSetEvent - Internal Function
 *
 * @param TaskIndex
 * @param EventMask
 * @return StatusType
 */

StatusType osSysSetEvent ( TaskType TaskIndex, EventMaskType EventMask )
{
    StatusType Status = E_NOT_OK;
    if(TaskIndex < OsNumberOfTasks)
    {
    osuint8 CurrentTasksType = TcbTaskRefConfig[TaskIndex]->TasksType;
    
    if (CurrentTasksType != (uint8)TASK_EXTENDED)
    {
        OsErr_osApplicationErrorHook(OsDlt_OsSetEvent,&Status, E_OS_ACCESS);
    }
    else
    {
        OsPrvEnterCriticalSection();
        OsTaskParamRefType const pTaskParam = TcbTaskRefConfig[TaskIndex]->TaskParamRef;
        pTaskParam->SetEventMask    |= EventMask;
        if(pTaskParam->State == WAITING)
        {
            if(0U != (pTaskParam->SetEventMask & pTaskParam->WaitEventMask))
            {
                pTaskParam->State = READY;
                osSchedInsertTask(TaskIndex);
            }
            Status = E_OK;
        }
        else if(pTaskParam->State == SUSPENDED)
        {
            OsErr_osApplicationErrorHook(OsDlt_OsSetEvent, &Status, E_OS_STATE);
        }
        else
        {
            Status = E_OK;
            /*Log this as we didnt do anything here*/
            /*todo*/
        }
        OsPrvExitCriticalSection();
    }
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsSetEvent,&Status, E_OS_ID);
    }
    /*todo: api fail status to be updated*/
    return Status;
}

/**
 * @brief ClearEvent - The events of the extended task calling ClearEvent are cleared according to the event mask <Mask>.
 *
 * @param EventMask
 * @return StatusType
 */

StatusType osClearEvent ( EventMaskType EventMask )
{
    StatusType Status = E_NOT_OK;
    TaskType TaskIndex = 0;
    if(OsCtrlParam.ActiveTaskIndex < OsNumberOfTasks)
    {
    osuint8 CurrentTasksType = TcbTaskRefConfig[OsCtrlParam.ActiveTaskIndex]->TasksType;

    OsPrvEnterCriticalSection();

    if(OsCtrlParam.CurrentContext == (uint16)osdCtxISRCat2)
    {
        OsErr_osApplicationErrorHook(OsDlt_OsClearEvent, &Status, E_OS_CALLEVEL);
    }
    else if (CurrentTasksType != (uint8)TASK_EXTENDED)
    {
        OsErr_osApplicationErrorHook(OsDlt_OsClearEvent,&Status, E_OS_ACCESS);
    }
    else
    {
        TaskIndex = OsCtrlParam.ActiveTaskIndex;
        if(TaskIndex < OsNumberOfTasks)
        {
            TcbTaskRefConfig[TaskIndex]->TaskParamRef->SetEventMask &= (EventMaskType)(~EventMask);
        }
        else
        {
        DEBUG_ASSERT( FALSE );
        }
        Status = E_OK;
    }
    OsPrvExitCriticalSection();
    }
    return Status;

}

/**
 * @brief GetEvent - This service returns the current state of all event bits of the task <TaskID>, not the events that the task is waiting for
 *
 * @param TaskIndex
 * @param EventMask
 * @return StatusType
 */

StatusType osGetEvent ( TaskType TaskIndex, EventMaskRefType Event )
{
    StatusType Status = E_NOT_OK;
    if(TaskIndex < OsNumberOfTasks)
    {
    osuint8 CurrentTasksType = TcbTaskRefConfig[TaskIndex]->TasksType;

    if(NULL_PTR == Event)
    {
        Status = E_OS_ILLEGAL_ADDRESS;
        OsErr_osApplicationErrorHook(OsDlt_OsGetEvent, &Status, E_OS_ILLEGAL_ADDRESS);
    }
    else if (CurrentTasksType != (uint8)TASK_EXTENDED)
    {
        OsErr_osApplicationErrorHook(OsDlt_OsGetEvent,&Status, E_OS_ACCESS);
    }
    else
    {
        OsTaskParamRefType const pTaskParam = TcbTaskRefConfig[TaskIndex]->TaskParamRef; /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
        if(pTaskParam->State == SUSPENDED)
        {
            OsErr_osApplicationErrorHook(OsDlt_OsGetEvent, &Status, E_OS_STATE);
        }
        else
        {
            *Event = pTaskParam->SetEventMask;
            Status = E_OK;
        }
    }
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsGetEvent, &Status, E_OS_ID);
    }
    return Status;
}

/**
 * @brief WaitEvent - The state of the calling task is set to waiting, unless at least one of the events specified in <Mask> has already been set.
 *
 * @param EventMask
 * @return StatusType
 */

StatusType osWaitEvent ( EventMaskType EventMask )
{
    StatusType Status = E_NOT_OK;
    TaskType TaskIndex = 0;
    TaskIndex = OsCtrlParam.ActiveTaskIndex;
    if((TaskIndex < OsNumberOfTasks) && (OsCtrlParam.ActiveTaskIndex < OsNumberOfTasks))
    {
    osuint8 CurrentTasksType = TcbTaskRefConfig[TaskIndex]->TasksType;
    OsTaskParamRefType const pTaskPrm = TcbTaskRefConfig[OsCtrlParam.ActiveTaskIndex]->TaskParamRef; /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

    if(FALSE == osCheckInterruptsEnabled())
    {
        OsDlt_LogMessage(OsDlt_OsWaitEvent,E_OS_DISABLEDINT);
        /*SWS_Os_00239
        Enable Interrupts*/
        osEnableAllInterrupts();
        OsErr_osApplicationErrorHook(OsDlt_OsWaitEvent, &Status, E_OS_DISABLEDINT);
    }

    OsPrvEnterCriticalSection();
    
    if(OsCtrlParam.CurrentContext == (uint16)osdCtxISRCat2)
    {
        OsErr_osApplicationErrorHook(OsDlt_OsWaitEvent, &Status, E_OS_CALLEVEL);
    }
    else if(pTaskPrm->ResCnt > 0U)
    {
        OsErr_osApplicationErrorHook(OsDlt_OsWaitEvent,&Status, E_OS_RESOURCE);
    }
    else if (CurrentTasksType != (uint8)TASK_EXTENDED)
    {
        OsErr_osApplicationErrorHook(OsDlt_OsWaitEvent,&Status, E_OS_ACCESS);
    }
    else
    {
        /* WaitEvent Implementation Here */
        OsTaskParamRefType const pTaskParam = TcbTaskRefConfig[TaskIndex]->TaskParamRef;
        pTaskParam->WaitEventMask = EventMask;

        if( 0U == (pTaskParam->SetEventMask & EventMask ))
        {
            pTaskParam->State = WAITING;
            osTaskStopHook();
            osSchedRemoveTask();
            OsPrvExitCriticalSection();
            osDispatch();
        }
        Status = E_OK;
    }
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
    OsPrvExitCriticalSection();
    return Status;
}

/**
 * @brief osSysWaitEvent - The state of the calling task is set to waiting, unless at least one of the events specified in <Mask> has already been set.
 *
 * @param EventMask
 * @return StatusType
 */

StatusType osSysWaitEvent ( EventMaskType EventMask )
{
    StatusType Status = E_NOT_OK;
    TaskType TaskIndex = 0;
    TaskIndex = OsCtrlParam.ActiveTaskIndex;
    if((TaskIndex < OsNumberOfTasks) && (OsCtrlParam.ActiveTaskIndex < OsNumberOfTasks))
    {
        osuint8 CurrentTasksType = TcbTaskRefConfig[TaskIndex]->TasksType;
        OsTaskParamRefType const pTaskPrm = TcbTaskRefConfig[OsCtrlParam.ActiveTaskIndex]->TaskParamRef; /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
        OsPrvEnterCriticalSection();
        if(OsCtrlParam.CurrentContext == (uint16)osdCtxISRCat2)
        {
            OsErr_osApplicationErrorHook(OsDlt_OsWaitEvent, &Status, E_OS_CALLEVEL);
        }
        else if(pTaskPrm->ResCnt > 0U)
        {
            OsErr_osApplicationErrorHook(OsDlt_OsWaitEvent,&Status, E_OS_RESOURCE);
        }
        else if (CurrentTasksType != (uint8)TASK_EXTENDED)
        {
            OsErr_osApplicationErrorHook(OsDlt_OsWaitEvent,&Status, E_OS_ACCESS);
        }
        else
        {
            /* WaitEvent Implementation Here */
            OsTaskParamRefType const pTaskParam = TcbTaskRefConfig[TaskIndex]->TaskParamRef;
            pTaskParam->WaitEventMask = EventMask;

            if( 0U == (pTaskParam->SetEventMask & EventMask ))
            {
                pTaskParam->State = WAITING;
                osTaskStopHook();
                osSchedRemoveTask();
                OsCtrlParam.LockDispatcher = 0U;
            }
            Status = E_OK;
        }
        OsPrvExitCriticalSection();
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
    return Status;
}

#endif /*ECC1_TYPE*/
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
Date               : 12-Sep-16
CDSID              : vbalakr3
Traceability       : 
Change Description : Initial version
-----------------------------------------------------------------------------*/

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
**   ------------------------------------------------------------------------------ **
**   Date              : 12-Sep-2016                                                **
**   CDSID             : vbalakr3                                                   **
**   RTC Id            : ------                                                     **
**   Change Description: Initial Version                                            **
**----------------------------------------------------------------------------------**
**   Date              : 18-Aug-2020                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 1005188                                                    **
**   Change Description: Os Extended Error Support                                  **
**   ------------------------------------------------------------------------------ **
**----------------------------------------------------------------------------------**
**   Date              : 13-May-2022                                                **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1648619                                                    **
**   Change Description: Coverity & Misra Medium Warning Fix                        **
**----------------------------------------------------------------------------------**
**   Date              : 09-June-2022                                               **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1679233                                                    **
**   Change Description: Coverity & Misra Low Warning Fix                           **
**----------------------------------------------------------------------------------**/

/* end of file =============================================================*/

