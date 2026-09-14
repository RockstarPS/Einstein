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
 * @file        OsSched.c
 * @details     <b>Implements the oseksched functionality the operating system Autosar 4.2.1</b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef OS_SCHED_C
#define OS_SCHED_C

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
#define OSSCHED_4BIT_MAX_VALUE                0xFU
#define OSSCHED_8BIT_MAX_VALUE                0xFFU
#define OSSCHED_16BIT_MAX_VALUE               0xFFFFU
#define OSSCHED_VALUE_UNSIGNED_ONE            1U
#define OSSCHED_VALUE_ONE                     1
#define OSSCHED_SHIFT_BY_16                   16
#define OSSCHED_VALUE_16U                     16U
#define OSSCHED_SHIFT_BY_8                    8
#define OSSCHED_VALUE_8U                      8U
#define OSSCHED_SHIFT_BY_4                    4
#define OSSCHED_VALUE_4U                      4U
#define OSSCHED_SHIFT_BY_2                    2
#define OSSCHED_VALUE_2U                      2U
#define OSSCHED_VALUE_TWO                     2
#define OSSCHED_VALUE_THREE                   3
#define OSSCHED_HEXVALUE_THREE                0x3U
#define OSSCHED_HEXVALUE_ONE                  0x1U
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
#if (MOS_USE_SCHED_LOG == STD_ON)
typedef struct
{
    TaskPriorityBitType PrioBits;
    osuint8 CallType;
    osuint8 ResId;
    osuint8 ResCnt;
    TaskPriorityType ActPrio;
    TaskPriorityType ReqPrio;    
    TaskType ActIndex;
    TaskType ReqIndex;
    TaskType InsertedTask;
    osuint8 LockDispatcher;
    osuint8 Head;
    osuint8 Tail;
}SchedLogType;

#define LOG_SIZE        400
static volatile SchedLogType SchedLog[LOG_SIZE] = {0xFF};
static volatile osuint32 SchedLogIx = 0;
#endif

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
#define OS_IGNORE_UNREF_PARAM(param)                  ((void)(param))

/**
 * @brief OsSchedInsertTask - Sets TaskPriority bits specific to the TaskIndex. Inserts the task to the activation list
 *
 * @param TaskIndex
 *
 * @return void
 */

void osSchedInsertTask (TaskType TaskIndex)
{
    TaskPriorityType taskpriority = 0;
    if(TaskIndex < OsNumberOfTasks)
    {
    taskpriority = TcbTaskRefConfig[TaskIndex]->TaskPriority;
    OsCtrlParam.TaskPriorityBits |= (OSSCHED_VALUE_UNSIGNED_ONE << taskpriority);
    if(taskpriority < OsMaxPriorityLevel)
    {
    OsprioQueueType * const pThisPrioQ = &OsPriorityQueueDyn[taskpriority];

    pThisPrioQ->pQueue[pThisPrioQ->Tail] = TaskIndex;
	if( pThisPrioQ->Tail < OSSCHED_8BIT_MAX_VALUE) 
	{          
		pThisPrioQ->Tail++;
    }
	else
	{
        DEBUG_ASSERT( FALSE );
    }

    if(pThisPrioQ->Tail > OsMaxPrioQueueCount[taskpriority])
    {
        //Handle overflow of Queue here 
        pThisPrioQ->Tail = 0;
    }

    /* Check if the Inserted Task priority is of higher priority ever */
    if(taskpriority < OsCtrlParam.RequestedTaskPriority)
    {
        OsCtrlParam.RequestedTaskIndex = TaskIndex;
        OsCtrlParam.RequestedTaskPriority = taskpriority;
        OsCtrlParam.RequestScheduler = OSSCHED_VALUE_UNSIGNED_ONE;
    }
    }
#if (MOS_USE_SCHED_LOG == STD_ON)
    volatile SchedLogType* pLog = &SchedLog[SchedLogIx];
    pLog->CallType = 0;
    pLog->InsertedTask = TaskIndex;
    pLog->PrioBits = OsCtrlParam.TaskPriorityBits;
    pLog->ResId = pThisPrioQ->pQueue[pThisPrioQ->Head];
    pLog->ResCnt = pThisPrioQ->pQueue[pThisPrioQ->Head + OSSCHED_VALUE_ONE];
    pLog->ActPrio = OsCtrlParam.ActiveTaskPriority;
    pLog->ReqPrio = OsCtrlParam.RequestedTaskPriority;
    pLog->ActIndex = OsCtrlParam.ActiveTaskIndex;
    pLog->ReqIndex = OsCtrlParam.RequestedTaskIndex;
    pLog->LockDispatcher = OsCtrlParam.LockDispatcher;
    pLog->Head = pThisPrioQ->Head;
    pLog->Tail = pThisPrioQ->Tail;
    SchedLogIx++;
    if(SchedLogIx > (LOG_SIZE-OSSCHED_VALUE_ONE))
    {
        SchedLogIx = 0;
    }
#endif
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
}

/**
 * @brief OsSchedGetNextHighPrioTask - Internal service to return the NextHighPrio Task
 *
 * @param pOsCtrlParam
 *
 * @return void
 */

void OsSchedGetNextHighPrioTask (OsCtrlParamType* pOsCtrlParam)
{
    TaskPriorityBitType taskprioritybit = pOsCtrlParam->TaskPriorityBits;
    osuint8 bitposition = 0;
    boolean validtask = FALSE;
    if(0U != taskprioritybit)
    {
        bitposition = 0;
        if ((taskprioritybit & OSSCHED_16BIT_MAX_VALUE) == 0U)
        {
            bitposition += OSSCHED_VALUE_16U;
            taskprioritybit >>= OSSCHED_SHIFT_BY_16;
        }
        if ((taskprioritybit & OSSCHED_8BIT_MAX_VALUE) == 0U)
        {
            bitposition += OSSCHED_VALUE_8U;
            taskprioritybit >>= OSSCHED_SHIFT_BY_8;
        }
        if ((taskprioritybit & OSSCHED_4BIT_MAX_VALUE) == 0U)
        {
            bitposition += OSSCHED_VALUE_4U;
            taskprioritybit >>= OSSCHED_SHIFT_BY_4;
        }
        if ((taskprioritybit & OSSCHED_HEXVALUE_THREE) == 0u)
        {
            bitposition += OSSCHED_VALUE_2U;
            taskprioritybit >>= OSSCHED_SHIFT_BY_2;
        }
        if ((taskprioritybit & OSSCHED_HEXVALUE_ONE) == 0U)
        {   
            bitposition += OSSCHED_VALUE_UNSIGNED_ONE;
        }
        /* check index is valid */
        if ( OsMaxPriorityLevel > bitposition   )
        {
            validtask = TRUE;
        }
    }
    else
    {
        validtask = FALSE;
    }
    if( FALSE != validtask )
    {
        OsprioQueueType * const pThisPrioQ = &OsPriorityQueueDyn[bitposition]; /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
        pOsCtrlParam->RequestedTaskIndex = pThisPrioQ->pQueue[pThisPrioQ->Head];
        pOsCtrlParam->RequestedTaskPriority = bitposition;
    }
    else
    {
        pOsCtrlParam->RequestedTaskIndex = INVALID_TASK;
        pOsCtrlParam->RequestedTaskPriority = INVALID_PRIORITY;
    }
}


/**
 * @brief OsSchedIsTaskSwitchReqd - Internal service to check if a Task switch is reqd
 *
 * @param pOsCtrlParam
 *
 * @return osuint8
 */

osuint8 OsSchedIsTaskSwitchReqd (OsCtrlParamType* pOsCtrlParam) /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
{
    osuint8 Ret = 0;        //Switch Not needed now
    if (pOsCtrlParam->ActiveTaskIndex != pOsCtrlParam->RequestedTaskIndex)
    {
        Ret = OSSCHED_8BIT_MAX_VALUE;
    }
    return Ret;
}

/**
 * @brief OsSchedRemoveTask - Removes the priority bit from TaskPriorityBits. Determines the highest priority Task and moves this to RequestedTaskPriority
 *
 * @param 
 *
 * @return void
 */
void osSchedRemoveTask (void)
{
    TaskType taskindex = 0;
    TaskPriorityType taskpriority = 0;
    taskindex = OsCtrlParam.ActiveTaskIndex;
    if(taskindex < OsNumberOfTasks)
    {
        taskpriority = TcbTaskRefConfig[taskindex]->TaskPriority;
        if(taskpriority < OsMaxPriorityLevel)
        {
            OsprioQueueType * const pThisPrioQ = &OsPriorityQueueDyn[taskpriority];
            
            if(TcbTaskRefConfig[taskindex]->TaskParamRef->ResCnt != 0U)
            {
                OsErr_osApplicationErrorHook(OsDlt_OsGetResource, NULL, E_NOT_OK);
            }

            //Remove this task from the Priority Queue
            if( pThisPrioQ->Head < OSSCHED_8BIT_MAX_VALUE) 
            {   
                pThisPrioQ->Head++;
            }
            else
            {
                DEBUG_ASSERT( FALSE );
            }
            //Handle overflow of queue here
            if (pThisPrioQ->Head > OsMaxPrioQueueCount[taskpriority])
            {
                //Clear the Head
                pThisPrioQ->Head = 0;
            }

            if(pThisPrioQ->Head == pThisPrioQ->Tail)
            {
                /* Queue is empty now, Remove the priority from the TaskPriorityBits */
                OsCtrlParam.TaskPriorityBits &= (~(OSSCHED_VALUE_UNSIGNED_ONE << taskpriority));
            }
        
            OsSchedGetNextHighPrioTask(&OsCtrlParam);

            OsCtrlParam.RequestScheduler = OSSCHED_VALUE_UNSIGNED_ONE;

#if (MOS_USE_SCHED_LOG == STD_ON)
            volatile SchedLogType* pLog = &SchedLog[SchedLogIx];
            pLog->CallType = OSSCHED_VALUE_ONE;
            pLog->InsertedTask = OSSCHED_8BIT_MAX_VALUE;
            pLog->PrioBits = OsCtrlParam.TaskPriorityBits;
            pLog->ResId = pThisPrioQ->pQueue[pThisPrioQ->Head];
            pLog->ResCnt = pThisPrioQ->pQueue[pThisPrioQ->Head + OSSCHED_VALUE_ONE];
            pLog->ActPrio = OsCtrlParam.ActiveTaskPriority;
            pLog->ReqPrio = OsCtrlParam.RequestedTaskPriority;
            pLog->ActIndex = OsCtrlParam.ActiveTaskIndex;
            pLog->ReqIndex = OsCtrlParam.RequestedTaskIndex;
            pLog->LockDispatcher = OsCtrlParam.LockDispatcher;
            pLog->Head = pThisPrioQ->Head;
            pLog->Tail = pThisPrioQ->Tail;

            SchedLogIx++;
            if(SchedLogIx > (LOG_SIZE - OSSCHED_VALUE_ONE))
            {
                SchedLogIx = 0;
            }
#endif
        }
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
}

/**
 * @brief OsSchedGetResource - Schedule handling for GetResource
 *
 * @param ResConfig
 *
 * @return void
 */

void osSchedGetResource(const OsResConfigType* pResConfig)
{
    OsCtrlParamType * const pOsCtrl = &(OsCtrlParam);

    //If Task is Preemptive, Set ActiveTaskPriority as CeilingPrio or ActiveTaskPriority whichever is high prio
    //Else Use HomePriority Q
    if((pResConfig->CeilingPrio < pOsCtrl->ActiveTaskPriority) && (pOsCtrl->LockDispatcher == 0U))
    {
        pOsCtrl->RequestedTaskPriority = pResConfig->CeilingPrio;
        pOsCtrl->ActiveTaskPriority = pResConfig->CeilingPrio;
        pOsCtrl->TaskPriorityBits |= (OSSCHED_VALUE_UNSIGNED_ONE << pResConfig->CeilingPrio);
        pOsCtrl->RequestedTaskIndex = pOsCtrl->ActiveTaskIndex;
    }

    OsprioQueueType * const pThisPrioTaskQ = &OsPriorityQueueDyn[pOsCtrl->ActiveTaskPriority];
    if(pOsCtrl->ActiveTaskIndex < OsNumberOfTasks)
    {
    OsTaskParamRefType const pThisTaskParam = TcbTaskRefConfig[pOsCtrl->ActiveTaskIndex]->TaskParamRef;

    //Insert the Resource into Priority Queue
    if(pThisPrioTaskQ->Head > 0U)
    {
        pThisPrioTaskQ->Head--;
    }
    else
    {
        pThisPrioTaskQ->Head =  OsMaxPrioQueueCount[pOsCtrl->ActiveTaskPriority];
    }

    pThisPrioTaskQ->pQueue[pThisPrioTaskQ->Head] = pOsCtrl->ActiveTaskIndex;
	if( pThisTaskParam->ResCnt < OSSCHED_8BIT_MAX_VALUE) 
	{   
		pThisTaskParam->ResCnt++;
	}
	else
	{
        DEBUG_ASSERT( FALSE );
    }

#if (MOS_USE_SCHED_LOG == STD_ON)
    volatile SchedLogType* pLog = &SchedLog[SchedLogIx];

    SchedLogIx++;
    if(SchedLogIx > (LOG_SIZE- OSSCHED_VALUE_ONE))
    {
        SchedLogIx = 0;
    }

    pLog->CallType = OSSCHED_VALUE_TWO;
    pLog->PrioBits = pOsCtrl->TaskPriorityBits;
    pLog->ResId = pResConfig->ResId;
    pLog->ResCnt = pThisTaskParam->ResCnt;
    pLog->ActPrio = pOsCtrl->ActiveTaskPriority;
    pLog->ReqPrio = pOsCtrl->RequestedTaskPriority;
    pLog->ActIndex = pOsCtrl->ActiveTaskIndex;
    pLog->ReqIndex = pOsCtrl->RequestedTaskIndex;
    pLog->LockDispatcher = pOsCtrl->LockDispatcher;
    pLog->Head = pThisPrioTaskQ->Head;
    pLog->Tail = pThisPrioTaskQ->Tail;

#endif

}
}

/**
 * @brief OsSchedReleaseResource - Schedule handling for ReleaseResource
 *
 * @param ResConfig
 *
 * @return void
 */

/*MISRA RULE 2.7 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
void osSchedReleaseResource(const OsResConfigType* pResConfig)
{
    OsCtrlParamType * const pOsCtrl = &(OsCtrlParam);
    if(pOsCtrl->ActiveTaskPriority < OsMaxPriorityLevel)
    {
    OsprioQueueType * const pThisPrioTaskQ = &OsPriorityQueueDyn[pOsCtrl->ActiveTaskPriority];
    if(pOsCtrl->ActiveTaskIndex < OsNumberOfTasks)
    {
    OsTaskParamRefType const pTaskParam = TcbTaskRefConfig[pOsCtrl->ActiveTaskIndex]->TaskParamRef;

	if( pThisPrioTaskQ->Head < OSSCHED_8BIT_MAX_VALUE ) 
	{           
		pThisPrioTaskQ->Head++;
	}
	else
	{
        DEBUG_ASSERT( FALSE );
    }

    if(pThisPrioTaskQ->Head > OsMaxPrioQueueCount[pOsCtrl->ActiveTaskPriority])
    {
        pThisPrioTaskQ->Head = 0;
    }

    if(pTaskParam->ResCnt > 0U)
    {
        pTaskParam->ResCnt--;
    }

    if(pThisPrioTaskQ->Head == pThisPrioTaskQ->Tail)
    {
        if(pOsCtrl->LockDispatcher == 0U)
        {
            /* Queue is empty now, Remove the priority from the TaskPriorityBits */
            pOsCtrl->TaskPriorityBits &= (~(OSSCHED_VALUE_UNSIGNED_ONE << (pOsCtrl->ActiveTaskPriority)));
        }
        else
        {
            //Error, NP Task priority should be cleared by RemoveTask
            OsErr_osApplicationErrorHook(OsDlt_OsReleaseResource, NULL, E_NOT_OK);
        }
        
        
    }

    if(pOsCtrl->LockDispatcher == 0U)
    {
        /* This is a rescheduling point now, get the next high priority task */
        OsSchedGetNextHighPrioTask(pOsCtrl);
        pOsCtrl->RequestScheduler = OSSCHED_VALUE_UNSIGNED_ONE;
    }
    else
    {
        /* Non Premptive Task */
        //For Non Preemptive Task, the Ceiling priority will not be changed
        //No Action here
    }

#if (MOS_USE_SCHED_LOG == STD_ON)
    volatile SchedLogType* pLog = &SchedLog[SchedLogIx];

    SchedLogIx++;
    if(SchedLogIx > (LOG_SIZE - OSSCHED_VALUE_ONE))
    {
        SchedLogIx = 0;
    }
    pLog->CallType = OSSCHED_VALUE_THREE;
    pLog->ResId = pResConfig->ResId;
    pLog->PrioBits = pOsCtrl->TaskPriorityBits;
    pLog->ResCnt = pTaskParam->ResCnt;
    pLog->ActPrio = pOsCtrl->ActiveTaskPriority;
    pLog->ReqPrio = pOsCtrl->RequestedTaskPriority;
    pLog->ActIndex = pOsCtrl->ActiveTaskIndex;
    pLog->ReqIndex = pOsCtrl->RequestedTaskIndex;
    pLog->LockDispatcher = pOsCtrl->LockDispatcher;
    pLog->Head = pThisPrioTaskQ->Head;
    pLog->Tail = pThisPrioTaskQ->Tail;
#endif
}
}
OS_IGNORE_UNREF_PARAM(pResConfig);
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
Date               : 20-Sep-16
CDSID              : ssukuma1
Traceability       : 
Change Description : INitial version
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 26-Aug-19
CDSID              : ssukuma1
Traceability       : RTC #582097
Change Description : Support for multiple auto start tasks
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 20-May-21
CDSID              : ssebast1
Traceability       : RTC #1251632
Change Description : Nested Os Resource support as part of defect fix.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 04-07-2021
CDSID              : ssukuma1
Traceability       : RTC #1251632
Change Description : Defect Fix - Os Resource redesign
-----------------------------------------------------------------------------*/
/**   Date             : 8-Oct-2021                                         **
**   CDSID             : vrusstar                                           **
**   RTC Id            : 1464024                                            **
**   Change Description: Review and fix of high Coverity issues             **
**   ---------------------------------------------------------------------- **/
/*--------------------------------------------------------------------------------------------------------------------
Date              : 27/March/2022
By                : gthanapp
Traceability      : RTC #1564070
Change Description: Cert-C warning analysis and fix
----------------------------------------------------------------------------------------------------------------------*/
/**   Date              : 13-May-2022                                                **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1648619                                                    **
**   Change Description: Coverity & Misra Medium Warning Fix                        **
**----------------------------------------------------------------------------------**
**----------------------------------------------------------------------------------**
**   Date              : 27-May-2022                                                **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1672091                                                    **
**   Change Description: Bsw general requirements supported                         **
**----------------------------------------------------------------------------------**
**   Date              : 09-June-2022                                               **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1679233                                                    **
**   Change Description: Coverity & Misra Low Warning Fix                           **
**----------------------------------------------------------------------------------**/

/* end of file =============================================================*/

