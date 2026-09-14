
/**
 * @brief
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
 * @file        OsApi.c
 * @author      sivasujith.sukumaran@visteon.com
 * @details     <b>Implements the Service Abstraction Layers of OS API</b>
 * @exception   Only limited APIs needed for the system are supported
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */


// \cond
#ifndef OS_API_C
#define OS_API_C
// \endcond
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "OsApi.h"
#include "Os.h"
#include "OsPrivate.h"
#include "Os_Cfg.h"
#include "AssertLib.h"
#include "OsMemProtection.h"
#include "OsHal_CpuDerivative_Common.h"

// \cond
#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
// \endcond
#include "Os_IntMemMap.h"

static osbool OsApiPrv_IsAllowedAccess (TaskType TaskId);
/**
 * @brief Internal API to check if access is permitted
 *
 * @param TaskId
 * @return TRUE: If current OsApp is TRUSTED or if the referred object belongs to same OsApp \n
 *         FALSE: It is a violation for a lower level OsApp to access a higher level ASIL OsApp
 */
OS_LOCAL FUNC(osbool, OS_CODE) OsApiPrv_IsAllowedAccess(TaskType TaskId)
{
    osbool Ret = FALSE;
    if(TaskId < OsNumberOfTasks)
    {
        const OsObjConfigRefType pThisTaskObj = TcbTaskRefConfig[TaskId]->pObjRef; /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
        const OsCtrlParamType* pOsCtrlParam = &OsCtrlParam;

        if((pOsCtrlParam->pActiveObjRef->pAppRef->AppId == OS_CFG_OSAPPLICATION_TRUSTEDSYSTEM) || (pThisTaskObj->pAppRef == pOsCtrlParam->pActiveObjRef->pAppRef))
        {
            Ret = TRUE;
        }
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
    return Ret;
}

/**
 * @brief   Abstraction of ActivateTask
 * @note    Refer @ref osActivateTask() \n
 * @param TaskIndex 
 * @return StatusType 
 */
FUNC(StatusType, OS_CODE) OsApi_ActivateTask (TaskType TaskIndex)
{
    StatusType Status = E_OS_CALLEVEL;
    if (FALSE != OsApiPrv_IsAllowedAccess(TaskIndex))
    {
        Status = osActivateTask(TaskIndex);
    }
    else
    {
        OsErr_osFatalErrorHook(OsDlt_OsActivateTask, &Status, Status);
    }
    return Status;
}


/**
 * @brief Service Abstraction of TerminateTask()
 * @note    Refer @ref osTerminateTask() for more details
 * @return StatusType 
 * @callgraph
 */
FUNC(StatusType, OS_CODE) OsApi_TerminateTask (void)
{
    StatusType Status = E_OS_INVALID;
    Status = osTerminateTask();
    return Status;
}

/**
 * @brief API details unavailable
 * @warning This API is not supported in the current version of vAutosar mOS
 * @param TaskIndex 
 * @return StatusType 
 */
StatusType OsApi_ChainTask (TaskType TaskIndex)
{
    (void)TaskIndex;
    StatusType Status = E_OS_INVALID;
    return Status;
}

/**
 * @brief Service Abstraction of Schedule() API
 * @note  Refer @ref OsSchedule() for more details
 * @return StatusType 
 * @callgraph
 */
FUNC(StatusType, OS_CODE) OsApi_Schedule (void)
{
    StatusType Status = E_OS_INVALID;
    Status = OsSchedule();
    return Status;
}

/**
 * @brief Service Abstraction of GetTaskID() API
 * @note  Refer @ref osGetTaskID() for more details
 *
 */
FUNC(StatusType, OS_CODE) OsApi_GetTaskID (TaskRefType pTaskID)
{
    StatusType Status = E_OS_INVALID;
    Status = osGetTaskID(pTaskID);
    return Status;
}

/**
 * @brief Service Abstraction for GetTaskState() API
 * @note  Refer @ref osGetTaskState() for more details

 */
FUNC(StatusType, OS_CODE) OsApi_GetTaskState(TaskType TaskID, TaskStateRefType State)
{
    StatusType Status = E_OS_INVALID;
    Status = osGetTaskState(TaskID,State);
    return Status;
}


/**
 * @brief Service Abstraction for DisableAllInterrupts() API
 * @note  Refer @ref osDisableAllInterrupts() for more details
 */
FUNC(void, OS_CODE) OsApi_DisableAllInterrupts(void)
{
    osDisableAllInterrupts();
}

/**
 * @brief Service Abstraction for EnableAllInterrupts() API
 * @note  Refer @ref osEnableAllInterrupts() for more details
 */
FUNC(void, OS_CODE) OsApi_EnableAllInterrupts(void)
{
    osEnableAllInterrupts();
}

/**
 * @brief Service Abstraction for SuspendAllInterrupts() API
 * @note  Refer @ref osSuspendAllInterrupts for more details on usage
 */
FUNC(void, OS_CODE) OsApi_SuspendAllInterrupts(void)
{
    osSuspendAllInterrupts();
}


/**
 * @brief Service Abstraction for ResumeAllInterrupts() API
 * @note  Refer @ref osResumeAllInterrupts() for more details
 */
FUNC(void, OS_CODE) OsApi_ResumeAllInterrupts(void)
{
    osResumeAllInterrupts();
}

/**
 * @brief Service Abstraction for SuspendOSInterrupts() API
 * @note Refer @ref osSuspendAllInterrupts() for more details
 */
FUNC(void, OS_CODE) OsApi_SuspendOSInterrupts(void)
{
    osSuspendAllInterrupts();
}

/**
 * @brief Service Abstraction for ResumeOSInterrupts() API
 * @note Refer @ref osResumeAllInterrupts() for more details
 */
FUNC(void, OS_CODE) OsApi_ResumeOSInterrupts(void)
{
    osResumeAllInterrupts();
}

/**
 * @brief Service Abstraction for GetResource() API
 * @note  Refer @ref osGetResource() for more details
 * @param ResID
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_GetResource(ResourceType ResID)
{
    StatusType Status = E_OS_INVALID;
    Status = osGetResource(ResID);
    return Status;
}

/**
 * @brief Service Abstraction for ReleaseResource() API
 * @note  Refer @ref osReleaseResource() for more details
 * @param ResID
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_ReleaseResource(ResourceType ResID)
{
    StatusType Status = E_OS_INVALID;
    Status = osReleaseResource(ResID);
    return Status;
}

/**
 * @brief Service Abstraction for SetEvent() API
 * @note  Refer @ref osSetEvent() API for more details
 * @param TaskID
 * @param Mask
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_SetEvent(TaskType TaskID,EventMaskType Mask)
{
    StatusType Status = E_OS_INVALID;
    Status = osSetEvent(TaskID,Mask);
    return Status;
}

/**
 * @brief Service Abstraction for ClearEvent() API
 * @note  Refer @ref osClearEvent() API for more details
 * @param Mask
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_ClearEvent(EventMaskType Mask)
{
    StatusType Status = E_OS_INVALID;
    Status = osClearEvent(Mask);
    return Status;
}

/**
 * @brief Service Abstraction for GetEvent() API
 * @note  Refer @ref osGetEvent() API for more details
 * @param TaskID
 * @param pMask
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_GetEvent(TaskType TaskID,EventMaskRefType Mask)
{
    StatusType Status = E_OS_INVALID;
    Status = osGetEvent(TaskID,Mask);
    return Status;
}

/**
 * @brief Service Abstraction for WaitEvent() API
 * @note  Refer @ref osWaitEvent() for more details
 * @param Mask
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_WaitEvent(EventMaskType Mask)
{
    StatusType Status = E_OS_INVALID;
    Status = osWaitEvent(Mask);
    return Status;
}

/**
 * @brief Service Abstraction for GetAlarm() API
 * @note  Refer @ref Os_GetAlarm() for more deails
 * @param AlarmID
 * @param Tick
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_GetAlarm(AlarmType AlarmID, TickRefType Tick)
{
    StatusType Status = E_OS_INVALID;
    Status = Os_GetAlarm(AlarmID,Tick);
    return Status;
}

/**
 * @brief Un supported API
 *
 * @param AlarmID - Unused
 * @param Info  - Unused
 * @return StatusType
 * @note   This API is not supported in the current version of vAutosar 1.1
 */
FUNC(StatusType, OS_CODE) OsApi_GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info) /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
{
    (void)AlarmID;
    (void)Info;
    StatusType Status = E_OS_INVALID;
    return Status;
}



/**
 * @brief Service Abstraction for SetRelAlarm()
 * @note  Refer @ref @Os_SetRelAlarm() for more details
 * @param AlarmID
 * @param Increment
 * @param Cycle
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_SetRelAlarm(AlarmType AlarmID, TickType Increment, TickType Cycle)
{
    StatusType Status = E_OS_CALLEVEL;
    if(AlarmID < OsNumberOfAlarms)
    {
        const AlarmConfigRefType pAlarmConfig = AlarmRefConfig[AlarmID];
        TaskType pTaskId = INVALID_TASK;
        if(ALARM_SET_EVENT_ACTION == pAlarmConfig->OsAlarmAction)
        {
            pTaskId = pAlarmConfig->OsAlarmTask;
        }
        else if(ALARM_ACTIVATE_TASK_ACTION == pAlarmConfig->OsAlarmAction)
        {
            pTaskId = pAlarmConfig->OsAlarmActivateTaskRef->TasksID;
        }
        if(FALSE != OsApiPrv_IsAllowedAccess(pTaskId))
        {
            Status = Os_SetRelAlarm(AlarmID,Increment,Cycle);
        }
        else
        {
            OsErr_osFatalErrorHook(OsDlt_osSetRelAlarm, &Status, Status);
        }
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
    return Status;
}


/**
 * @brief Unsupported API
 * @warning This API is not supported in the current version of vAutosar mOS
 * @param AlarmID
 * @param Start
 * @param Cycle
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_SetAbsAlarm(AlarmType AlarmID, TickType Start, TickType Cycle)
{
    (void)AlarmID;
    (void)Start;
    (void)Cycle;
    StatusType Status = E_OS_INVALID;
    return Status;
}



/**
 * @brief Sevice Abstraction for CancelAlarm() API
 * @note  Refer @ref Os_CancelAlarm() for more details
 * @param AlarmID
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_CancelAlarm(AlarmType AlarmID)
{
    StatusType Status = E_OS_CALLEVEL;
    if(AlarmID < OsNumberOfAlarms)
    {
        const AlarmConfigRefType pAlarmConfig = AlarmRefConfig[AlarmID];
        TaskType pTaskId = INVALID_TASK;
        if(ALARM_SET_EVENT_ACTION == pAlarmConfig->OsAlarmAction)
        {
            pTaskId = pAlarmConfig->OsAlarmTask;
        }
        else if(ALARM_ACTIVATE_TASK_ACTION == pAlarmConfig->OsAlarmAction)
        {
            pTaskId = pAlarmConfig->OsAlarmActivateTaskRef->TasksID;
        }
        if(FALSE != OsApiPrv_IsAllowedAccess(pTaskId))
        {
            Status = Os_CancelAlarm(AlarmID);
        }
        else
        {
            OsErr_osFatalErrorHook(OsDlt_osCancelAlarm, &Status, Status);
        }
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
    return Status;
}

/**
 * @brief Service Abstraction for ShutdownOS() API
 * @note  Refer @ref osShutdownOS() for more details
 * @param Error
 */
FUNC(void, OS_CODE) OsApi_ShutdownOS(StatusType Error)
{
    if(FALSE != OsApiPrv_IsAllowedAccess(OsCtrlParam.ActiveTaskIndex))
    {
        osShutdownOS(Error);
    }
    else
    {
        OsErr_osFatalErrorHook(OsDlt_osShutdownOS, NULL, E_OS_CALLEVEL);
    }
}

/*---+ Autosar API Wrappers--------------------------------------------------------------------*/
/**
 * @brief Service Abstraction for GetApplicationID()
 * @note  Refer @ref osGetApplicationId() for more details
 * @return ApplicationType
 */
FUNC(ApplicationType, OS_CODE) OsApi_GetApplicationID(void)
{
    ApplicationType CurrAppId = OS_CFG_APPLICATION_INVALID;
    CurrAppId = OsGetApplicationId();
    return CurrAppId;
}

/**
 * @brief Service Abstraction layer for GetCurrentApplicationID() API
 * @note  Reer @ref OsGetCurrentApplicationID() for more details
 * @return ApplicationType
 */
FUNC(ApplicationType, OS_CODE) OsApi_GetCurrentApplicationID(void)
{
    ApplicationType CurrAppId = OS_CFG_APPLICATION_INVALID;
    CurrAppId = OsGetCurrentApplicationID();
    return CurrAppId;
}


/**
 * @brief Service Abstraction layer for GetISRID()
 * @note  Refer @ref osGetISRID() for more details
 * @return ISRType
 */
FUNC(ISRType, OS_CODE) OsApi_GetISRID(void)
{
    ISRType IsrId = 0;
    IsrId = osGetISRID();
    return IsrId;
}

/**
 * @brief Service Abstraction layer for CallTrustedFunction()
 * @note  Refer @ref OsCallTrustedFunction()
 * @param FunctionIndex
 * @param FunctionParams
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_CallTrustedFunction(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
    StatusType Status = E_OS_INVALID;
    #if (OS_CFG_MEMORY_PROTECTION == STD_ON) && (OsNumberOfTrustedFns > 0U)
    Status = OsCallTrustedFunction(FunctionIndex,FunctionParams);
    #else
    /* Static Warning fix for unused arguments */
    (void)FunctionIndex;
    (void)FunctionParams;
    #endif
    return Status;
}


/**
 * @brief Service for checking ISR memory access rights
 * @note  Refer @ref OsCheckISRMemoryAccess()
 * @param FunctionIndex
 * @param ISRId
 * @param Size
 * @return AccessType
 */
FUNC(AccessType, OS_CODE) OsApi_CheckISRMemoryAccess (ISRType ISRId, MemoryStartAddressType Address, MemorySizeType Size)
{
    AccessType Result = OS_ACCESS_TYPE_NON;
    #if (OS_CFG_MEMORY_PROTECTION == STD_ON)
    Result = OsCheckISRMemoryAccess(ISRId, Address, Size);
    #endif
    return Result;
}

/**
 * @brief Service for checking ISR memory access rights
 * @note  Refer @ref OsCheckTaskMemoryAccess()
 * @param TaskID
 * @param Address
 * @param Size
 * @return AccessType
 */
FUNC(AccessType, OS_CODE) OsApi_CheckTaskMemoryAccess (TaskType TaskID, MemoryStartAddressType Address, MemorySizeType Size)
{
    AccessType Result = OS_ACCESS_TYPE_NON;
    #if (OS_CFG_MEMORY_PROTECTION == STD_ON)
    Result = OsCheckTaskMemoryAccess(TaskID, Address, Size);
    #endif
    return Result;
}

/**
 * @brief Service Abstraction for CheckObjectAccess()
 * @note  Refer @ref OsCheckObjectAccess() for more details
 * @param AppID
 * @param ObjType
 * @param ObjID
 * @return ObjectAccessType
 */
FUNC(ObjectAccessType, OS_CODE) OsApi_CheckObjectAccess(ApplicationType AppID, ObjectTypeType ObjType, ObjectIdType ObjID)
{
    ObjectAccessType Status = OS_OBJECT_NO_ACCESS;
    Status = OsCheckObjectAccess(AppID,ObjType,ObjID);
    return Status;
}


/**
 * @brief Service Abstraction for CheckObjectOwnership() API
 * @note  Refer @ref OsCheckObjectOwnership() for more details
 * @param ObjType
 * @param ObjID
 * @return ApplicationType
 */
FUNC(ApplicationType, OS_CODE) OsApi_CheckObjectOwnership(ObjectTypeType ObjType, ObjectIdType ObjID)
{
    ApplicationType AppId = OS_CFG_APPLICATION_INVALID;
    AppId = OsCheckObjectOwnership(ObjType,ObjID);
    return AppId;
}


/**
 * @brief Service Abstraction for StartScheduleTableRel() API
 * @note  Refer @ref OsStartScheduleTableRel
 * @param ScheduleTableID
 * @param Offset
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_StartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Offset)
{
    StatusType Status = E_OS_INVALID;
    #if (OS_CFG_SCHEDULE_TABLE == STD_ON)
    Status = OsStartScheduleTableRel(ScheduleTableID,Offset);
    #else
    /* Static Warning fix for unused arguments */
    (void)ScheduleTableID;
    (void)Offset;
    #endif
    return Status;
}

/**
 * @brief Service Abstraction for StartScheduleTableAbs() API
 * @note  Refer @ref OsStartScheduleTableAbs()
 * @param ScheduleTableID
 * @param Offset
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_StartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start)
{
    StatusType Status = E_OS_INVALID;
    #if (OS_CFG_SCHEDULE_TABLE == STD_ON)
    Status = OsStartScheduleTableAbs(ScheduleTableID,Start);
    #else
    /* Static Warning fix for unused arguments */
    (void)ScheduleTableID;
    (void)Start;
    #endif
    return Status;
}

/**
 * @brief Service Abstraction for StopScheduleTable() API
 * @note  Refer @ref OsStopScheduleTable
 * @param ScheduleTableID
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_StopScheduleTable(ScheduleTableType ScheduleTableID)
{
    StatusType Status = E_OS_INVALID;
    #if (OS_CFG_SCHEDULE_TABLE == STD_ON)
    Status = OsStopScheduleTable(ScheduleTableID);
    #else
    /* Static Warning fix for unused arguments */
    (void)ScheduleTableID;
    #endif
    return Status;
}

/**
 * @brief Service Abstraction for NextScheduleTable() API
 * @note  Refer @ref OsNextScheduleTable
 * @param ScheduleTableID_From
 * @param ScheduleTableID_To
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_NextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To)
{
    StatusType Status = E_OS_INVALID;
    #if (OS_CFG_SCHEDULE_TABLE == STD_ON)
    Status = OsNextScheduleTable(ScheduleTableID_From,ScheduleTableID_To);
    #else
    /* Static Warning fix for unused arguments */
    (void)ScheduleTableID_From;
    (void)ScheduleTableID_To;
    #endif
    return Status;
}

/**
 * @brief Service Abstraction for GetScheduleTableStatus() API
 * @note  Refer @ref OsGetScheduleTableStatus
 * @param ScheduleTableID
 * @param ScheduleStatus
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_GetScheduleTableStatus(ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus)
{
    StatusType Status = E_OS_INVALID;
    #if (OS_CFG_SCHEDULE_TABLE == STD_ON) 
    Status = OsGetScheduleTableStatus(ScheduleTableID,ScheduleStatus);
    #else
    /* Static Warning fix for unused arguments */
    (void)ScheduleTableID;
    (void)ScheduleStatus;
    #endif
    return Status;
}

/**
 * @brief Service Abstraction for StartScheduleTableSynchron() API
 * @note  Refer @ref OsStartScheduleTableSynchron
 * @param ScheduleTableID
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_StartScheduleTableSynchron(ScheduleTableType ScheduleTableID)
{
    (void)ScheduleTableID;
    StatusType Status = E_OS_INVALID;
    return Status;
}

/**
 * @brief Service Abstraction for SyncScheduleTable() API
 * @note  Refer @ref OsSyncScheduleTable
 * @param ScheduleTableID
 * @param Value
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_SyncScheduleTable(ScheduleTableType ScheduleTableID, TickType Value)
{
    (void)ScheduleTableID;
    (void)Value;
    StatusType Status = E_OS_INVALID;
    return Status;
}

/**
 * @brief Service Abstraction for SetScheduleTableAsyn() API
 * @note  Refer @ref OsSetScheduleTableAsyn
 * @param ScheduleTableID
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_SetScheduleTableAsync(ScheduleTableType ScheduleTableID)
{
    (void)ScheduleTableID;
    StatusType Status = E_OS_INVALID;
    return Status;
}

/**
 * @brief Service Abstraction for IncrementCounter() API
 * @note  Refer @ref OsIncrementCounter
 * @param CounterID
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_IncrementCounter(CounterType CounterID)
{
    StatusType Status = E_OS_INVALID;
    Status = OsIncrementCounter(CounterID);
    return Status;
}

/**
 * @brief Service Abstraction for GetCounterValue() API
 * @note  Refer @ref OsGetCounterValue
 * @param CounterID
 * @param Value
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_GetCounterValue(CounterType CounterID, TickRefType Value)
{
    StatusType Status = E_OS_INVALID;
    Status = OsGetCounterValue(CounterID,Value);
    return Status;
}

/**
 * @brief Service Abstraction for GetElapsedValue() API
 * @note  Refer @ref OsGetElapsedValue
 * @param CounterID
 * @param Value
 * @param ElapsedValue
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_GetElapsedValue(CounterType CounterID, TickRefType Value, TickRefType ElapsedValue)
{
    StatusType Status = E_OS_INVALID;
    Status = OsGetElapsedValue(CounterID,Value,ElapsedValue);
    return Status;
}

/**
 * @brief Service Abstraction for TerminateApplication() API
 * @note  Refer @ref OsTerminateApplication
 * @param Application
 * @param RestartOption
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_TerminateApplication(ApplicationType Application, RestartType RestartOption)
{
    StatusType Status = E_OS_INVALID;
    Status = OsTerminateApplication(Application,RestartOption);
    return Status;
}

/**
 * @brief Service Abstraction for AllowAccess() API
 * @note  Refer @ref OsAllowAccess
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_AllowAccess (void)
{
    StatusType Status = E_OS_INVALID;
    Status = OsAllowAccess();
    return Status;
}

/**
 * @brief Service Abstraction for GetApplicationState() API
 * @note  Refer @ref OsGetApplicationState
 * @param Application
 * @param Value
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) OsApi_GetApplicationState(ApplicationType Application, ApplicationStateRefType Value)
{
    StatusType Status = E_OS_INVALID;
    Status = OsGetApplicationState(Application,Value);
    return Status;
}

/**
 * @brief Service Abstraction for GetNumberOfActivatedCores() API
 * @note  Refer @ref OsGetNumberOfActivatedCores
 * @return uint32
 */
FUNC(uint32, OS_CODE) OsApi_GetNumberOfActivatedCores(void)
{
    return OsGetNumberOfActivatedCores();
}

/**
 * @brief Service Abstraction for GetCoreId() API
 * @note  Refer @ref OsGetCoreId
 * @return CoreIdType
 */
FUNC(CoreIdType, OS_CODE) OsApi_GetCoreId (void)
{
    return OsGetCoreId();
}

/**
 * @brief Service Abstraction for StartCore() API
 * @note  Refer @ref OsStartCore
 * @param  CoreId
 * @param  StatusRef
 * @return void
 */
FUNC(void, OS_CODE) OsApi_StartCore (CoreIdType CoreId, StatusType* StatusRef)
{
    OsStartCore(CoreId,StatusRef);
}

/**
 * @brief Service Abstraction for StartNonAutosarCore() API
 * @note  Refer @ref OsStartNonAutosarCore
 * @param  CoreId
 * @param  StatusRef
 * @return void
 */
FUNC(void, OS_CODE) OsApi_StartNonAutosarCore (CoreIdType CoreId, StatusType* StatusRef)
{
    OsStartNonAutosarCore(CoreId,StatusRef);
}

/**
 * @brief Service Abstraction for EnableInterruptSource() API
 * @note  Refer @ref OsEnableInterruptSource
 * @param  ISRID
 * @param  ClearPending
 * @return void
 */
FUNC(StatusType, OS_CODE) OsApi_EnableInterruptSource (ISRType ISRID,boolean ClearPending)
{
    //call microcontroller specific function in OsHalCpu.c
    return OsHal_EnableInterruptSource(ISRID, ClearPending);
}

/**
 * @brief Service Abstraction for DisableInterruptSource() API
 * @note  Refer @ref OsDisableInterruptSource
 * @param  ISRID
 * @return void
 */
FUNC(StatusType, OS_CODE) OsApi_DisableInterruptSource (ISRType ISRID)
{
    StatusType Ret = E_NOT_OK;
    if(ISRID > OsNumberOfIsr)
    {
        OsErr_osApplicationErrorHook(OsDlt_DisableInterruptSource, NULL_PTR, E_OS_ID);
    }
    else
    {
        //call microcontroller specific function in OsHalCpu.c
        Ret = OsHal_DisableInterruptSource(ISRID);
    }
    return Ret;
}

#if (MOS_VERSION_INFO_API == STD_ON)
/**
 * @brief Service to return version info of the module
 * @note  Refer @ref Os_GetVersionInfo()
 * @param VersionInfo
 * @return void
 */
FUNC(void, OS_CODE) OsApi_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
    if(NULL_PTR != VersionInfo)
    {
        Os_GetVersionInfo(VersionInfo);
    }
}
#endif

// @cond
#define OS_CORE_CODE_SEC_END
#define OS_CORE_CONST_SEC_END
#define OS_CORE_DATA_SEC_END
#define OS_CORE_DATA_NOCACHE_SEC_END
#define OS_CORE_BSS_SEC_END
// @endcond
#include "Os_IntMemMap.h"


#endif      /* EOF */

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
**   Date              : 06-Jun-2020                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 929151                                                     **
**   Change Description: OS ASIL B Support - Initial Version                        **
**----------------------------------------------------------------------------------**
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
**   Date              : 09-Apr-2024                                                **
**   CDSID             : ssukuma1                                                   **
**   Traceability      : PE4TI29141-2219                                            **
**   Change Description: Compiler Abstraction & BSW General Requirements            **
**----------------------------------------------------------------------------------**/
