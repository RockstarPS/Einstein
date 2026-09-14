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
 * @file        OsStart.c
 * @details     <b>Implements the Os startup and stack filling for Autosar 4.2.1</b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef OS_START_C
#define OS_START_C

#include "OsMetrics.h"
#include "OsPrivate.h"
#include "Os_HooksCfg.h"
#include "OsMemProtection.h"
#include "AssertLib.h"


#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"


extern osMetricType osMetrics[osMetricsMaxCount];
static void osFillTaskStack (TaskType TaskId);
static void osFillISRStacks (ISRType ISRId);
static void OsInitMemory(void);
/**
 * @brief OsFillStack - Internal Function for FillStack
 *
 * @param stackTop
 * @param stackBot
 *
 * @return void
 */

void osFillStack (osStackPtrType stackTop, osStackPtrType stackBot) /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
{
    osStackPtrType stackPtr = stackBot;
    
    while (stackPtr < stackTop)
    {
      *stackPtr = (osStackDataType)osdStackCheckPattern;
      stackPtr++;
    }
}

/**
 * @brief OsFillTaskStacks - Internal Function for FillTaskStacks
 *
 * @param TaskId
 *
 * @return void
 */

static void osFillTaskStack (TaskType TaskId)
{
    osStackPtrType stackStart = NULL;
    osStackPtrType stackEnd = NULL;
    osStackSizeType stackSize = 0;
    if(TaskId < OsNumberOfTasks)
    {
    stackStart  = TcbTaskRefConfig[TaskId]->TaskStackStartAddress;
    stackSize   = TcbTaskRefConfig[TaskId]->TaskStackSize;
    stackEnd = (osStackPtrType)((osStackDataType)stackStart - stackSize); /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    osFillStack(stackStart,stackEnd);
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }

}

/**
 * @brief OsFillISRStacks - Internal Function for FillISRStacks
 *
 * @param ISRId
 *
 * @return void
 */

static void osFillISRStacks (ISRType ISRId)
{
    osStackPtrType stackStart = NULL;
    osStackPtrType stackEnd = NULL;
    osStackSizeType stackSize = 0;
    
    if(ISRId < osdNumberOfCat2ISRs)
    {
    stackStart  = IsrStackConfig[ISRId];
    stackSize   = (osStackSizeType)IsrStackSize[ISRId];
    stackEnd = (osStackPtrType)((osStackDataType)stackStart - stackSize); /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    osFillStack(stackStart,stackEnd);
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
}

/**
 * @brief OsInitMemory - Internal Function for Initializing Memory
 *
 * @param 
 *
 * @return void
 */

static void OsInitMemory(void)
{
    const CoreIdType CoreId = 0;
    const OsCoreConfigRefType pThisCore = (OsCoreRefConfig[CoreId]);
    
    OsCtrlParam.ActiveTaskIndex                     =   INVALID_TASK;
    OsCtrlParam.RequestedTaskIndex                  =   INVALID_TASK;
    OsCtrlParam.ActiveTaskPriority                  =   INVALID_PRIORITY;
    OsCtrlParam.RequestedTaskPriority               =   INVALID_PRIORITY;
    OsCtrlParam.ResOccVirtualPrioBits				=	0;
    OsCtrlParam.TaskPriorityBits                    =   0;
    OsCtrlParam.RequestScheduler                    =   0U;
    OsCtrlParam.LockDispatcher                      =   0U;
    OsCtrlParam.IntSaveDisableRequestCounter        =   0;
    OsCtrlParam.IntSaveStatus                       =   0;
    OsCtrlParam.OsIntSaveDisableRequestCounter      =   0;
    OsCtrlParam.IntSaveGlobal                       =   0;
    OsCtrlParam.CurrentContext                      =   osdCtxTask;
    
    OsMainInitObjRef(pThisCore->pOsCoreObjRef);
}

/**
 * @brief OsInitialize - Internal Function to Initialize Os
 *
 * @param 
 *
 * @return void
 */

void osInitialize (void)
{
    osuint8 i = 0;
    
    /* Architecture specific initializations goes here */
    OsHal_Initialize();
    
    OsInitMemory();
    
    for (i=0;i<OsNumberOfTasks;i++)
    {
        OsTaskParamRefType const pTaskParam = TcbTaskRefConfig[i]->TaskParamRef;
        pTaskParam->ActivationCnt   = 0;
        pTaskParam->State           = SUSPENDED;
        pTaskParam->StackAddress    = TcbTaskRefConfig[i]->TaskStackStartAddress;
        pTaskParam->ResCnt = 0;
        #if (CC_TYPE == ECC1 || CC_TYPE == ECC2)
            pTaskParam->WaitEventMask = 0;
            pTaskParam->SetEventMask = 0;
        #endif
        
        osFillTaskStack(i);
    }
    
    /* Fill ISR Stacks */
	for (i=0;i<osdNumberOfCat2ISRs;i++)
	{
		osFillISRStacks(i);
	}
    //Fill the common stack used by Non Preemptive tasks
    
    
    for (i=0;i<OsMaxPriorityLevel;i++)
    {

        OsprioQueueType * const pThisQ = &OsPriorityQueueDyn[i];
        pThisQ->Head = 0;
        pThisQ->Tail = 0;
        //pThisQ->pQueue is defined during declarations
    }
   
    OsError_InitMemory();
    
    for(i=0;i<osMaxCounterId;i++)
    {
        CounterRefConfig[i]->OsCounterParam->TickCount = 0U;
    }
    
    OsRes_InitMemory();

}

/**
 * @brief osStartOS - Function to StartOs
 *
 * @param 
 *
 * @return void
 */
void osStartOS (void)
{
    TaskType Index = 0;
    TaskType AutoStartTaskId = 0;
    #ifdef mOS_SUPPORT_INTERNAL_METRICS
    osMetrics[3].StartTime  = OsGetTimerCount();
    osMetrics[3].ValFlag    = TRUE;
    #endif
    OS_START_ENTRY();
    
    //validate configuration
    
    //Fill Stack if reqd

    osInitialize();
    
    OS_ARCH_SETUP_INTERRUPTS();
    
    osInitAlarms();
    
    #if OsNumberOfAutoStartTasks > 0
    for (Index=0;Index < (uint8)OsNumberOfAutoStartTasks;Index++)
    {
        AutoStartTaskId = AutoStartTaskList[Index];
        
        if (AutoStartTaskId != INVALID_TASK)
        {
            (void)osSysActivateTask(AutoStartTaskId);
        }
    }
    #endif
	/* Autostart Schedule Tables */
#if (OS_CFG_SCHEDULE_TABLE == STD_ON) 
    ScheduleTableType ScheduleTblIdx = 0U;
	for (ScheduleTblIdx = 0; ScheduleTblIdx < OsNumberOfScheduleTables; ScheduleTblIdx++)
    {
        if (OsScheduleTableRefConfig[ScheduleTblIdx]->AutoStartRef->AutoStartType == SCHEDULETABLE_RELATIVE)
        { 
            (void)StartScheduleTableRel(ScheduleTblIdx, OsScheduleTableRefConfig[ScheduleTblIdx]->AutoStartRef->AbsRelTickValue); /*MISRA RULE 17.7 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
        }
        else if(OsScheduleTableRefConfig[ScheduleTblIdx]->AutoStartRef->AutoStartType == SCHEDULETABLE_ABSOLUTE)
        {
            (void)StartScheduleTableAbs(ScheduleTblIdx, OsScheduleTableRefConfig[ScheduleTblIdx]->AutoStartRef->AbsRelTickValue);
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif /* #if (OS_CFG_SCHEDULE_TABLE == STD_ON) */
    OS_STARTUP_HOOK();
    
    osInitTimer();
    
    #if OsMaxAccessGroupIds > 0
    OsMemProtect_Init();
    #endif
    #ifdef mOS_SUPPORT_INTERNAL_METRICS
    OsGetOsInitMetrics();
    #endif
    osEnableAllInterrupts();
    osDispatch();
    #if (OS_TESTING_LOCAL == STD_ON)
    EnableAllInterrupts();
    while (1)
    {
       Task0();
       Task1();
       Task2();
    }
    #endif
    //not expected to reach here.. if reached unrecoverable error
    OS_UNRECOVERABLE_ERROR_HOOK(); /*MISRA RULE 4.9 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
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
**   Date              : 20-Jun-2016                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : ------                                                     **
**   Change Description: Initial version.                                           **
**   ------------------------------------------------------------------------------ **
**  ------------------------------------------------------------------------------- **
**   Date              : 09-Dec-2019                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 1393561                                                    **
**   Change Description: Initialization of ActivationCnt parameter                  **
**   ------------------------------------------------------------------------------ **
**  ------------------------------------------------------------------------------- **
**   Date              : 16-Jan-2020                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 718485                                                     **
**   Change Description: MISRA Warning fix                                          **
**   ------------------------------------------------------------------------------ **
**   Date              : 13-May-2022                                                **
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
**----------------------------------------------------------------------------------**
**----------------------------------------------------------------------------------*/

