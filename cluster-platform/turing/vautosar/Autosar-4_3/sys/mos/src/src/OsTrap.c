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
 * @file        OsTrap.c
 * @details     <b>This file contains implementations of the OsTrap
 *                 functionality </b>
 * @note
 *              Compiler    : IAR \n
 *              Target Hw   : Independents
 *
 * @copyright   Visteon (c) 2021
 *
 */
#ifndef OS_TRAP_C
#define OS_TRAP_C
#ifdef OS_PRIVILEGE_USER_ENABLE
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "OsTrap.h"
#include "OsApi.h"
#include "OsHal_CpuCore.h"
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
*                                 static function Declarations               *
******************************************************************************/
static FUNC(void, OS_CODE) OsTrap_EnableInterruptSource(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_DisableInterruptSource(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_ActivateTask(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_TerminateTask(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_SuspendAllInterrupts(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_ResumeAllInterrupts(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_SuspendOSInterrupts(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_ResumeOSInterrupts(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_GetResource(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_ReleaseResource(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_SetEvent(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_ClearEvent(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_GetEvent(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_WaitEvent(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_SetRelAlarm(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_CancelAlarm(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_ShutdownOS(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_Schedule(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_GetAlarm(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_SetAbsAlarm(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_CheckISRMemoryAccess (OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_CheckTaskMemoryAccess (OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_CheckObjectAccess(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_CheckObjectOwnership(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_StartScheduleTableRel(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_StartScheduleTableAbs(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_StopScheduleTable(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_NextScheduleTable(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_IncrementCounter(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_TerminateApplication(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_AllowAccess(OsTrapParameterRefType FnParam);
static FUNC(void, OS_CODE) OsTrap_CallTrustedFunction(OsTrapParameterRefType FnParam);


/**
 * @brief Defines the trap function table used by the OS trap handler in user mode.
 * 
 * This table maps trap function indices to the corresponding trap function implementations
 * between user-mode code and privileged OS functionality.
 */
const OsTrapTableType OsTrapTable[OS_TRAP_TABLE_SIZE] = {
    {OsTrap_ActivateTask},
    {OsTrap_TerminateTask},
    {OsTrap_SetRelAlarm},
    {OsTrap_SetAbsAlarm},
    {OsTrap_Schedule},
    {OsTrap_SuspendAllInterrupts},
    {OsTrap_ResumeAllInterrupts},
    {OsTrap_SuspendOSInterrupts},
    {OsTrap_ResumeOSInterrupts},
    {OsTrap_GetResource},
    {OsTrap_ReleaseResource},
    {OsTrap_SetEvent},
    {OsTrap_ClearEvent},
    {OsTrap_WaitEvent},
    {OsTrap_CancelAlarm},
    {OsTrap_ShutdownOS},
    {OsTrap_CheckISRMemoryAccess},
    {OsTrap_CheckTaskMemoryAccess},
    {OsTrap_CheckObjectAccess},
    {OsTrap_CheckObjectOwnership},
    {OsTrap_StartScheduleTableRel},
    {OsTrap_StartScheduleTableAbs},
    {OsTrap_StopScheduleTable},
    {OsTrap_NextScheduleTable},
    {OsTrap_IncrementCounter},
    {OsTrap_TerminateApplication},
    {OsTrap_AllowAccess},
    {OsTrap_EnableInterruptSource},
    {OsTrap_DisableInterruptSource},
    {OsTrap_GetEvent},
    {OsTrap_GetAlarm},
    {OsTrap_CallTrustedFunction}   
};

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/**
 * @brief Handles the trap function call from the OS.
 * @param FnIndex The index of the trap function to call.
 * @param FnParam The parameters for the trap function.
 * @return void
 */
FUNC(void, OS_CODE) OsHal_TrapHandler( OsTrapFuncIndexType FnIndex, OsTrapParameterRefType FnParam)
{
    if(OS_TRAP_TABLE_SIZE > FnIndex)
    {
        const OsTrapTableType* pTrapTable = &OsTrapTable[FnIndex];
        if(NULL_PTR != pTrapTable)
        {
            pTrapTable->TrapFunc(FnParam);
        }
    }
    else
    {
        DEBUG_ASSERT(FALSE);
    }
}

/*MISRA RULE 4.9 VIOLATION: Function like macro -This warning is triaged for all functions below*/
/*MISRA RULE 8.7 VIOLATION: Function has external linkage -This warning is triaged for all functions below*/
/**
 * @brief   Called for task activation
 * @param TaskIndex 
 * @return StatusType 
 */
FUNC(StatusType, OS_CODE) ActivateTask(TaskType TaskIndex) 
{
    StatusType RetStatus = (StatusType)E_OS_CALLEVEL;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &RetStatus;
        TrapData.Arg1.taskIndex = TaskIndex;
        OsHal_CpuTrap(ACTIVATE_TASK_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        RetStatus = OsApi_ActivateTask(TaskIndex);
    }
    return RetStatus;
}

/**
 * @brief Service Called for task termination
 * @note    Refer @ref OsApi_TerminateTask() for more details
 * @return StatusType 
 * @callgraph
 */
FUNC(StatusType, OS_CODE) TerminateTask(void)
{
    StatusType status = (StatusType)E_OS_INVALID;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &status;
        OsHal_CpuTrap(TERMINATE_TASK_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        status = OsApi_TerminateTask();
    }
    return status;
}

/**
 * @brief API details unavailable
 * @warning This API is not supported in the current version of vAutosar mOS
 * @param TaskIndex 
 * @return StatusType 
 */
FUNC(StatusType, OS_CODE) ChainTask(TaskType TaskIndex)
{
    StatusType status = (StatusType)E_OS_INVALID;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        status = E_NOT_OK;
    }
    else
    {
        status = OsApi_ChainTask(TaskIndex);
    }
    return status;
}

/**
 * @brief Service used to Schedule a task
 * @note  Refer @ref OsApi_Schedule() for more details
 * @return StatusType 
 * @callgraph
 */
FUNC(StatusType, OS_CODE) Schedule(void)
{
    StatusType status = (StatusType)E_OS_INVALID;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &status;
        OsHal_CpuTrap(SCHEDULE_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        status = OsApi_Schedule();
    }
    return status;
}

/**
 * @brief Service called to get task id
 * @note  Refer @ref OsApi_GetTaskID() for more details
 *
 */
FUNC(StatusType, OS_CODE) GetTaskID(TaskRefType pTaskID)
{
    StatusType status = (StatusType)E_OS_INVALID;
    //PrivilegeCheck() not required as this is a Read Service
    status = OsApi_GetTaskID(pTaskID);
    return status;
}

/**
 * @brief Service called to get task state
 * @note  Refer @ref OsApi_GetTaskState() for more details

 */
FUNC(StatusType, OS_CODE) GetTaskState(TaskType TaskID, TaskStateRefType State)
{
    StatusType status = (StatusType)E_OS_INVALID;
    //PrivilegeCheck() not required as this is a Read Service
    status = OsApi_GetTaskState(TaskID,State);
    return status;
}

/**
 * @brief Service Abstraction for DisableAllInterrupts() API
 * @note  Refer @ref osDisableAllInterrupts() for more details
 */
FUNC(void, OS_CODE) DisableAllInterrupts(void)
{
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsHal_CpuTrap(SUSPEND_ALL_INTERRUPTS_TRAP_ID, NULL_PTR);
    }
    else
    {
        OsApi_SuspendAllInterrupts();
    }
}

/**
 * @brief Service Abstraction for EnableAllInterrupts() API
 * @note  Refer @ref osEnableAllInterrupts() for more details
 */
FUNC(void, OS_CODE) EnableAllInterrupts(void)
{
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsHal_CpuTrap(RESUME_ALL_INTERRUPTS_TRAP_ID, NULL_PTR);
    }
    else
    {
        OsApi_ResumeAllInterrupts();
    }
}

/**
 * @brief Service Abstraction for SuspendAllInterrupts() API
 * @note  Refer @ref osSuspendAllInterrupts for more details on usage
 */
FUNC(void, OS_CODE) SuspendAllInterrupts(void)
{
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsHal_CpuTrap(SUSPEND_ALL_INTERRUPTS_TRAP_ID, NULL_PTR);
    }
    else
    {
        OsApi_SuspendAllInterrupts();
    }
}

/**
 * @brief Service Abstraction for ResumeAllInterrupts() API
 * @note  Refer @ref osResumeAllInterrupts() for more details
 */
FUNC(void, OS_CODE) ResumeAllInterrupts(void)
{
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsHal_CpuTrap(RESUME_ALL_INTERRUPTS_TRAP_ID, NULL_PTR);
    }
    else
    {
        OsApi_ResumeAllInterrupts();
    }
}

/**
 * @brief Service Abstraction for SuspendOSInterrupts() API
 * @note Refer @ref osSuspendOsInterrupts() for more details
 */
FUNC(void, OS_CODE) SuspendOSInterrupts(void)
{
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsHal_CpuTrap(SUSPEND_OS_INTERRUPTS_TRAP_ID, NULL_PTR);
    }
    else
    {
        OsApi_SuspendOSInterrupts();
    }
}

/**
 * @brief Service Abstraction for ResumeOSInterrupts() API
 * @note Refer @ref osResumeOsInterrupts() for more details
 */
FUNC(void, OS_CODE) ResumeOSInterrupts(void)
{
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsHal_CpuTrap(RESUME_OS_INTERRUPTS_TRAP_ID, NULL_PTR);
    }
    else
    {
        OsApi_ResumeOSInterrupts();
    }
}

/**
 * @brief Service Geting Resource
 * @note  Refer @ref osGetResource() for more details
 * @param ResID
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) GetResource(ResourceType ResID)
{
    StatusType status = (StatusType)E_OS_INVALID;

    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &status;
        TrapData.Arg1.ResId = ResID; 
        OsHal_CpuTrap(GET_RESOURCE_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        status = OsApi_GetResource(ResID);
    }
    return status;
}

/**
 * @brief Service for releasing Resource
 * @note  Refer @ref osReleaseResource() for more details
 * @param ResID
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) ReleaseResource(ResourceType ResID)
{
    StatusType status = (StatusType)E_OS_INVALID;

    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &status;
        TrapData.Arg1.ResId = ResID; 
        OsHal_CpuTrap(RELEASE_RESOURCE_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        status = OsApi_ReleaseResource(ResID);
    }
    return status;
}

/**
 * @brief Service for SetEvent()
 * @note  Refer @ref osSetEvent() API for more details
 * @param TaskID
 * @param Mask
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) SetEvent(TaskType TaskID,EventMaskType Mask)
{
    StatusType status = (StatusType)E_OS_INVALID;

    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &status;
        TrapData.Arg1.taskIndex = TaskID;
        TrapData.Arg2.eventmask = Mask;
        OsHal_CpuTrap(SET_EVENT_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        status = OsApi_SetEvent(TaskID,Mask);
    }
    return status;
}

/**
 * @brief Service ClearEvent()
 * @note  Refer @ref osClearEvent() API for more details
 * @param Mask
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) ClearEvent(EventMaskType Mask)
{
    StatusType status = (StatusType)E_OS_INVALID;

    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &status;
        TrapData.Arg1.eventmask = Mask;
        OsHal_CpuTrap(CLEAR_EVENT_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        status = OsApi_ClearEvent(Mask);
    }
    return status;
}

/**
 * @brief Service or GetEvent()
 * @note  Refer @ref osGetEvent() API for more details
 * @param TaskID
 * @param pMask
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) GetEvent(TaskType TaskID,EventMaskRefType Mask)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &Status;
        TrapData.Arg1.taskIndex = TaskID;
        TrapData.Arg2.MaskRef = Mask;
        OsHal_CpuTrap(GET_EVENT_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        Status = OsApi_GetEvent(TaskID,Mask);
    }
    return Status;
}

/**
 * @brief Service for WaitEvent()
 * @note  Refer @ref osWaitEvent() for more details
 * @param Mask
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) WaitEvent(EventMaskType Mask)
{
    StatusType Status = (StatusType)E_OS_INVALID;

    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &Status;
        TrapData.Arg1.eventmask = Mask;
        OsHal_CpuTrap(WAIT_EVENT_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        Status = OsApi_WaitEvent(Mask);

    }


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
FUNC(StatusType, OS_CODE) GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    //Privilege check not required as this is a Read Service
    Status = OsApi_GetAlarmBase(AlarmID, Info);
    return Status;
}

/**
 * @brief Service for GetAlarm()
 * @note  Refer @ref osGetAlarm() for more deails
 * @param AlarmID
 * @param Tick
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) GetAlarm(AlarmType AlarmID, TickRefType Tick)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &Status;
        TrapData.Arg1.alarmid = AlarmID;
        TrapData.Arg2.TickRef = Tick;
        OsHal_CpuTrap(GET_ALARM_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        Status = OsApi_GetAlarm(AlarmID,Tick);
    }
    return Status;
}

/**
 * @brief Service for SetRelAlarm()
 * @note  Refer @ref @osSetRelAlarm() for more details
 * @param AlarmID
 * @param Increment
 * @param Cycle
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) SetRelAlarm(AlarmType AlarmID, TickType Increment, TickType Cycle)
{
    StatusType status = (StatusType)E_OS_CALLEVEL;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &status;
        TrapData.Arg1.alarmid = AlarmID;
        TrapData.Arg2.increment = Increment;
        TrapData.Arg3.tickcycle = Cycle;
        OsHal_CpuTrap(SET_REL_ALARM_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        status = OsApi_SetRelAlarm(AlarmID,Increment,Cycle);
    }
    return status;
}

/**
 * @brief Unsupported API
 * @warning This API is not supported in the current version of vAutosar mOS
 * @param AlarmID
 * @param Start
 * @param Cycle
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) SetAbsAlarm(AlarmType AlarmID, TickType Start, TickType Cycle)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &Status;
        TrapData.Arg1.alarmid = AlarmID; 
        TrapData.Arg2.start = Start;
        TrapData.Arg3.tickcycle = Cycle;
        OsHal_CpuTrap(SET_ABS_ALARM_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        Status = OsApi_SetAbsAlarm(AlarmID, Start, Cycle);
    }
    return Status;
}

/**
 * @brief Sevice for CancelAlarm()
 * @note  Refer @ref osCancelAlarm() for more details
 * @param AlarmID
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) CancelAlarm(AlarmType AlarmID)
{
    StatusType status = (StatusType)E_OS_CALLEVEL;

    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &status;
        TrapData.Arg1.alarmid = AlarmID; 
        OsHal_CpuTrap(CANCEL_ALARM_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        status = OsApi_CancelAlarm(AlarmID);
    }
    return status;
}

/**
 * @brief Service for ShutdownOS()
 * @note  Refer @ref osShutdownOS() for more details
 * @param Error
 */
FUNC(void, OS_CODE) ShutdownOS(StatusType Error)
{
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.Arg1.ErrStatus = Error; 
        OsHal_CpuTrap(SHUTDOWN_OS_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        OsApi_ShutdownOS(Error);
    }
}

/**
 * @brief Service for GetApplicationID()
 * @note  Refer @ref osGetApplicationId() for more details
 * @return ApplicationType
 */
FUNC(ApplicationType, OS_CODE) GetApplicationID(void)
{
    ApplicationType CurrAppId = OS_CFG_APPLICATION_INVALID;
    //Privilege check not required as this is a Read Service
    CurrAppId = OsApi_GetApplicationID();

    return CurrAppId;
}

/**
 * @brief Service for GetCurrentApplicationID() 
 * @note  Reer @ref OsGetCurrentApplicationID() for more details
 * @return ApplicationType
 */
FUNC(ApplicationType, OS_CODE) GetCurrentApplicationID(void)
{
    ApplicationType CurrAppId = OS_CFG_APPLICATION_INVALID;

    //Privilege check not required as this is a Read Service
    CurrAppId = OsApi_GetCurrentApplicationID();

    return CurrAppId;
}

/**
 * @brief Service for GetISRID()
 * @note  Refer @ref osGetISRID() for more details
 * @return ISRType
 */
FUNC(ISRType, OS_CODE) GetISRID(void)
{
    ISRType IsrId = 0;

    IsrId = OsApi_GetISRID();

    return IsrId;
}

/**
 * @brief Service for CallTrustedFunction()
 * @note  Refer @ref OsCallTrustedFunction()
 * @param FunctionIndex
 * @param FunctionParams
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) CallTrustedFunction(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &Status;
        TrapData.Arg1.TrustedFuncId = FunctionIndex;
        TrapData.Arg2.TrustedFuncParamRef = FunctionParams;
        OsHal_CpuTrap(TRUSTED_CALL_FUNCTION_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        Status = OsApi_CallTrustedFunction(FunctionIndex,FunctionParams);
    }
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
FUNC(AccessType, OS_CODE) CheckISRMemoryAccess (ISRType ISRId, MemoryStartAddressType Address, MemorySizeType Size)
{
    AccessType Result = OS_ACCESS_TYPE_NON;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Access = &Result;
        TrapData.Arg1.ISRId = ISRId;
        TrapData.Arg2.MemStartAddr = Address;
        TrapData.Arg3.MemSize = Size;
        OsHal_CpuTrap(CHECK_ISR_MEMORY_ACCESS_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        Result = OsApi_CheckISRMemoryAccess(ISRId, Address, Size);
    }
    return Result;
}

/**
 * @brief Service for checking Task memory access rights
 * @note  Refer @ref OsCheckTaskMemoryAccess()
 * @param TaskID
 * @param Address
 * @param Size
 * @return AccessType
 */
FUNC(AccessType, OS_CODE) CheckTaskMemoryAccess (TaskType TaskID, MemoryStartAddressType Address, MemorySizeType Size)
{
    AccessType Result = OS_ACCESS_TYPE_NON;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Access = &Result;
        TrapData.Arg1.taskIndex = TaskID;
        TrapData.Arg2.MemStartAddr = Address;
        TrapData.Arg3.MemSize = Size;
        OsHal_CpuTrap(CHECK_TASK_MEMORY_ACCESS_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        Result = OsApi_CheckTaskMemoryAccess(TaskID, Address, Size);
    }
    return Result;
}

/**
 * @brief Service for CheckObjectAccess()
 * @note  Refer @ref OsCheckObjectAccess() for more details
 * @param AppID
 * @param ObjType
 * @param ObjID
 * @return ObjectAccessType
 */
FUNC(ObjectAccessType, OS_CODE) CheckObjectAccess(ApplicationType AppID, ObjectTypeType ObjType, ObjectIdType ObjID)
{
    ObjectAccessType Status = OS_OBJECT_NO_ACCESS;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.ObjAccess = &Status;
        TrapData.Arg1.AppID = AppID;
        TrapData.Arg2.ObjType = ObjType;
        TrapData.Arg3.ObjID = ObjID;
        OsHal_CpuTrap(CHECK_OBJECT_ACCESS_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        Status = OsApi_CheckObjectAccess(AppID,ObjType,ObjID);
    }
    return Status;
}

/**
 * @brief Service for CheckObjectOwnership()
 * @note  Refer @ref OsCheckObjectOwnership() for more details
 * @param ObjType
 * @param ObjID
 * @return ApplicationType
 */
FUNC(ApplicationType, OS_CODE) CheckObjectOwnership(ObjectTypeType ObjType, ObjectIdType ObjID)
{
    ApplicationType AppId = OS_CFG_APPLICATION_INVALID;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.AppId = &AppId;
        TrapData.Arg1.ObjType = ObjType;
        TrapData.Arg2.ObjID = ObjID;
        OsHal_CpuTrap(CHECK_OBJECT_OWNERSHIP_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        AppId = OsApi_CheckObjectOwnership(ObjType,ObjID);
    }
    return AppId;
}

/**
 * @brief Service for StartScheduleTableRel() API
 * @note  Refer @ref OsStartScheduleTableRel
 * @param ScheduleTableID
 * @param Offset
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) StartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Offset)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &Status;
        TrapData.Arg1.ScheduleTblId1 = ScheduleTableID;
        TrapData.Arg2.Offset = Offset;
        OsHal_CpuTrap(START_SCHEDULE_TABLE_REL_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        Status = OsApi_StartScheduleTableRel(ScheduleTableID,Offset);
    }
    return Status;
}

/**
 * @brief Service for StartScheduleTableAbs() API
 * @note  Refer @ref OsStartScheduleTableAbs()
 * @param ScheduleTableID
 * @param Offset
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) StartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &Status;
        TrapData.Arg1.ScheduleTblId1 = ScheduleTableID;
        TrapData.Arg2.Offset = Start;
        OsHal_CpuTrap(START_SCHEDULE_TABLE_ABS_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        Status = OsApi_StartScheduleTableAbs(ScheduleTableID,Start);
    }
    return Status;
}

/**
 * @brief Service Abstraction for StopScheduleTable() API
 * @note  Refer @ref OsApi_StopScheduleTable()
 * @param ScheduleTableID
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) StopScheduleTable(ScheduleTableType ScheduleTableID)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &Status;
        TrapData.Arg1.ScheduleTblId1 = ScheduleTableID;
        OsHal_CpuTrap(STOP_SCHEDULE_TABLE_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        Status = OsApi_StopScheduleTable(ScheduleTableID);
    }
    return Status;
}

/**
 * @brief Service Abstraction for NextScheduleTable() API
 * @note  Refer @ref OsApi_NextScheduleTable()
 * @param ScheduleTableID_From
 * @param ScheduleTableID_To
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) NextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &Status;
        TrapData.Arg1.ScheduleTblId1 = ScheduleTableID_From;
        TrapData.Arg2.ScheduleTblId2 = ScheduleTableID_To;
        OsHal_CpuTrap(NEXT_SCHEDULE_TABLE_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        Status = OsApi_NextScheduleTable(ScheduleTableID_From,ScheduleTableID_To);
    }
    return Status;
}

/**
 * @brief Service Abstraction for GetScheduleTableStatus() API
 * @note  Refer @ref OsApi_GetScheduleTableStatus()
 * @param ScheduleTableID
 * @param ScheduleStatus
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) GetScheduleTableStatus(ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    //privileged API, no need to trap
    Status = OsApi_GetScheduleTableStatus(ScheduleTableID,ScheduleStatus);

    return Status;
}

/**
 * @brief Service Abstraction for StartScheduleTableSynchron() API
 * @note  Refer @ref OsApi_StartScheduleTableSynchron()
 * @param ScheduleTableID
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) StartScheduleTableSynchron(ScheduleTableType ScheduleTableID)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    //privileged API, no need to trap as there is no implementation support from Os
    Status = OsApi_StartScheduleTableSynchron(ScheduleTableID);
    return Status;
}

/**
 * @brief Service Abstraction for SyncScheduleTable() API
 * @note  Refer @ref OsApi_SyncScheduleTable()
 * @param ScheduleTableID
 * @param Value
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) SyncScheduleTable(ScheduleTableType ScheduleTableID, TickType Value)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    //privileged API, no need to trap as there is no implementation support from Os
    Status = OsApi_SyncScheduleTable(ScheduleTableID, Value);
    return Status;
}

/**
 * @brief Service Abstraction for SetScheduleTableAsync() API
 * @note  Refer @ref OsApi_SetScheduleTableAsync()
 * @param ScheduleTableID
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) SetScheduleTableAsync(ScheduleTableType ScheduleTableID)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    //privileged API, no need to trap as there is no implementation support from Os
    Status = OsApi_SetScheduleTableAsync(ScheduleTableID);
    return Status;
}

/**
 * @brief Service Abstraction for IncrementCounter() API
 * @note  Refer @ref OsApi_IncrementCounter()
 * @param CounterID
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) IncrementCounter(CounterType CounterID)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &Status;
        TrapData.Arg1.CounterId = CounterID;
        OsHal_CpuTrap(INCREMENT_COUNTER_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        Status = OsApi_IncrementCounter(CounterID);
    }
    return Status;
}

/**
 * @brief Service for GetCounterValue() API
 * @note  Refer @ref OsApi_GetCounterValue()
 * @param CounterID
 * @param Value
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) GetCounterValue(CounterType CounterID, TickRefType Value)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    //privileged API, no need to trap as this is a Read Service
    Status = OsApi_GetCounterValue(CounterID,Value);

    return Status;
}

/**
 * @brief Service for GetElapsedValue() API
 * @note  Refer @ref OsApi_GetElapsedValue()
 * @param CounterID
 * @param Value
 * @param ElapsedValue
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) GetElapsedValue(CounterType CounterID, TickRefType Value, TickRefType ElapsedValue)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    //privileged API, no need to trap as this is a Read Service
    Status = OsApi_GetElapsedValue(CounterID,Value,ElapsedValue);

    return Status;
}

/**
 * @brief Service for TerminateApplication() API
 * @note  Refer @ref OsApi_TerminateApplication()
 * @param Application
 * @param RestartOption
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) TerminateApplication(ApplicationType Application, RestartType RestartOption)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &Status;
        TrapData.Arg1.AppID = Application;
        TrapData.Arg2.RestartOpt = RestartOption;
        OsHal_CpuTrap(TERMINATE_APPLICATION_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        Status = OsApi_TerminateApplication(Application,RestartOption);
    }
    return Status;
}

/**
 * @brief Service for AllowAccess() API
 * @note  Refer @ref OsApi_AllowAccess()
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) AllowAccess (void)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &Status;
        OsHal_CpuTrap(ALLOW_ACCESS_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        Status = OsApi_AllowAccess();
    }
    return Status;
}

/**
 * @brief Service for GetApplicationState() API
 * @note  Refer @ref OsApi_GetApplicationState()
 * @param Application
 * @param Value
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) GetApplicationState(ApplicationType Application, ApplicationStateRefType Value)
{
    StatusType Status = (StatusType)E_OS_INVALID;
    //privileged API, no need to trap as this is a Read Service
    Status = OsApi_GetApplicationState(Application,Value);

    return Status;
}

/**
 * @brief Service for GetNumberOfActivatedCores() API
 * @note  Refer @ref OsApi_GetNumberOfActivatedCores()
 * @return uint32
 */
FUNC(uint32, OS_CODE) GetNumberOfActivatedCores(void)
{
    //privileged API, no need to trap as this is a Read Service
    return OsApi_GetNumberOfActivatedCores();
}

/**
 * @brief Service for GetCoreId() API
 * @note  Refer @ref OsApi_GetCoreId()
 * @return CoreIdType
 */
FUNC(CoreIdType, OS_CODE) GetCoreId (void)
{
    //privileged API, no need to trap as this is a Read Service
    return OsApi_GetCoreId();
}

/**
 * @brief Service for StartCore() API
 * @note  Refer @ref OsApi_StartCore()
 * @param CoreId
 * @param StatusRef
 * @return void
 */
FUNC(void, OS_CODE) StartCore (CoreIdType CoreId, StatusType* StatusRef)
{
    //expected to be in privilge mode to start the core
    OsApi_StartCore(CoreId,StatusRef);
}

/**
 * @brief Service for StartNonAutosarCore() API
 * @note  Refer @ref OsApi_StartNonAutosarCore()
 * @param CoreId
 * @param StatusRef
 * @return void
 */
FUNC(void, OS_CODE) StartNonAutosarCore (CoreIdType CoreId, StatusType* StatusRef)
{
    OsApi_StartNonAutosarCore(CoreId,StatusRef);
}

/**
 * @brief Service for EnableInterruptSource() API
 * @note  Refer @ref OsApi_EnableInterruptSource()
 * @param ISRID
 * @param ClearPending
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) EnableInterruptSource (ISRType ISRID,boolean ClearPending)
{

    StatusType status = (StatusType)E_OS_CALLEVEL;

    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &status;
        TrapData.Arg1.ISRId = ISRID;
        TrapData.Arg2.ClrPending = ClearPending;
        OsHal_CpuTrap(ENABLE_INTERRUPT_SOURCE_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        //call microcontroller specific function in OsHalCpu.c
        status = OsApi_EnableInterruptSource(ISRID, ClearPending);
    }
    return status;
    
    
}

/**
 * @brief Service for DisableInterruptSource() API
 * @note  Refer @ref OsApi_DisableInterruptSource()
 * @param ISRID
 * @return StatusType
 */
FUNC(StatusType, OS_CODE) DisableInterruptSource (ISRType ISRID)
{
    StatusType status = (StatusType)E_OS_CALLEVEL;

    if(FALSE != OsCpuHal_IsOsTrapRequired()) //condition true only if we are in user mode now
    {
        OsTrapArgType TrapData;
        TrapData.RetVal.Status = &status;
        TrapData.Arg1.ISRId = ISRID;
        OsHal_CpuTrap(DISABLE_INTERRUPT_SOURCE_TRAP_ID, (OsTrapParameterRefType)&TrapData);
    }
    else
    {
        //call microcontroller specific function in OsHalCpu.c
        status = OsApi_DisableInterruptSource(ISRID);
    }
    return status;
    
}


#if (MOS_VERSION_INFO_API == STD_ON)
/**
 * @brief Service for GetVersionInfo() API
 * @note  Refer @ref OsApi_GetVersionInfo()
 * @param VersionInfo
 * @return StatusType
 */
FUNC(void, OS_CODE) GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
    OsApi_GetVersionInfo(VersionInfo);
}
#endif

/****************************************************************************************************************************
 *                                              Static Function definitions                                                 *
 ****************************************************************************************************************************/

/**
 * Activates the task specified by the provided task index in user mode.
 *
 * @param FnIndex The index of the trap function being called.
 * @param FnParam A pointer to the trap function parameters.
 */
static FUNC(void, OS_CODE) OsTrap_ActivateTask( OsTrapParameterRefType FnParam)
{ 
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = osSysActivateTask(pPkg->Arg1.taskIndex);
}


/**
 * Terminates the currently running task in user mode.
 *
 * @param FnIndex The index of the trap function being called.
 * @param FnParam A pointer to the trap function parameters.
 */
static FUNC(void, OS_CODE) OsTrap_TerminateTask(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = osSysTerminateTask();
}

/**
 * Schedules the OS to run the next task in user mode.
 *
 * @param FnIndex The index of the trap function being called.
 * @param FnParam A pointer to the trap function parameters.
 */
static FUNC(void, OS_CODE) OsTrap_Schedule(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = osSysSchedule();
}

/**
 * Suspends all interrupts in user mode.
 *
 * @param FnIndex The index of the trap function being called.
 * @param FnParam A pointer to the trap function parameters.
 */
static FUNC(void, OS_CODE) OsTrap_SuspendAllInterrupts(OsTrapParameterRefType FnParam)
{
    (void)FnParam;
    OsApi_SuspendAllInterrupts();
}

/**
 * Resumes all interrupts that were previously suspended in user mode.
 *
 * @param FnIndex The index of the trap function being called.
 * @param FnParam A pointer to the trap function parameters.
 */
static FUNC(void, OS_CODE) OsTrap_ResumeAllInterrupts(OsTrapParameterRefType FnParam)
{
    (void)FnParam;
    OsApi_ResumeAllInterrupts();
}

/**
 * Suspends all OS interrupts in user mode.
 *
 * @param FnIndex The index of the trap function being called.
 * @param FnParam A pointer to the trap function parameters.
 */
static FUNC(void, OS_CODE) OsTrap_SuspendOSInterrupts(OsTrapParameterRefType FnParam)
{
    (void)FnParam;
    OsApi_SuspendOSInterrupts();
}

/**
 * Resumes all OS interrupts that were previously suspended in user mode.
 *
 * @param FnIndex The index of the trap function being called.
 * @param FnParam A pointer to the trap function parameters.
 */
static FUNC(void, OS_CODE) OsTrap_ResumeOSInterrupts(OsTrapParameterRefType FnParam)
{
    (void)FnParam;
    OsApi_ResumeOSInterrupts();
}

/**
 * Gets a resource in user mode.
 *
 * @param FnIndex The index of the trap function being called.
 * @param FnParam A pointer to the trap function parameters, which contains the resource ID to get.
 * @return The status of the resource get operation.
 */
static FUNC(void, OS_CODE) OsTrap_GetResource(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = OsApi_GetResource(pPkg->Arg1.ResId);
}

/**
 * Releases a previously acquired resource in user mode.
 *
 * @param FnIndex The index of the trap function being called.
 * @param FnParam A pointer to the trap function parameters, which contains the resource ID to release.
 * @return The status of the resource release operation.
 */
static FUNC(void, OS_CODE) OsTrap_ReleaseResource(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = osSysReleaseResource(pPkg->Arg1.ResId);
}

/**
 * Sets an event for a task in user mode.
 *
 * @param FnIndex The index of the trap function being called.
 * @param FnParam A pointer to the trap function parameters, which contains the task index and the event mask to set.
 * @return The status of the event set operation.
 */
static FUNC(void, OS_CODE) OsTrap_SetEvent(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = osSysSetEvent(pPkg->Arg1.taskIndex,pPkg->Arg2.eventmask);
}

/**
 * Clears the specified event mask for the current task in user mode.
 *
 * @param FnIndex The index of the trap function being called.
 * @param FnParam A pointer to the trap function parameters, which contains the event mask to clear.
 * @return The status of the event clear operation.
 */
static FUNC(void, OS_CODE) OsTrap_ClearEvent(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = OsApi_ClearEvent(pPkg->Arg1.eventmask);
}

/**
 * Waits for the specified event mask to be set for the current task in user mode.
 *
 * @param FnIndex The index of the trap function being called.
 * @param FnParam A pointer to the trap function parameters, which contains the event mask to wait for.
 * @return The status of the event wait operation.
 */
static FUNC(void, OS_CODE) OsTrap_WaitEvent(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = osSysWaitEvent(pPkg->Arg1.eventmask);
}

/**
 * Sets a relative alarm in user mode.
 *
 * @param FnIndex The index of the trap function being called.
 * @param FnParam A pointer to the trap function parameters, which contains the ID of the alarm to set, the increment time, and the tick cycle.
 * @return The status of the alarm set operation.
 */
static FUNC(void, OS_CODE) OsTrap_SetRelAlarm(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = OsApi_SetRelAlarm(pPkg->Arg1.alarmid,pPkg->Arg2.increment,pPkg->Arg3.tickcycle);
}

/**
 * Sets an absolute alarm in user mode.
 *
 * @param FnIndex The index of the trap function being called.
 * @param FnParam A pointer to the trap function parameters, which contains the ID of the alarm to set, the start time, and the tick cycle.
 * @return The status of the alarm set operation.
 */
static FUNC(void, OS_CODE) OsTrap_SetAbsAlarm(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = OsApi_SetAbsAlarm(pPkg->Arg1.alarmid,pPkg->Arg2.start,pPkg->Arg3.tickcycle);
}

/**
 * Cancels the specified alarm in user mode.
 *
 * @param FnIndex The index of the trap function being called.
 * @param FnParam A pointer to the trap function parameters, which contains the ID of the alarm to cancel.
 * @return The status of the alarm cancel operation.
 */
static FUNC(void, OS_CODE) OsTrap_CancelAlarm(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = OsApi_CancelAlarm(pPkg->Arg1.alarmid);
}

/**
 * @brief Shuts down the operating system with the specified error status in user mode.
 * @param FnIndex The index of the trap function to call.
 * @param FnParam The parameters for the trap function, including the error status.
 * @return void
 */
static FUNC(void, OS_CODE) OsTrap_ShutdownOS(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    OsApi_ShutdownOS(pPkg->Arg1.ErrStatus);
}

/**
 * @brief Checks the access permissions for the specified ISR's memory region in user mode.
 * @param FnIndex The index of the trap function to call.
 * @param FnParam The parameters for the trap function, including the ISR ID, memory start address, and memory size.
 * @return The access permissions for the specified memory region.
 */
static FUNC(void, OS_CODE) OsTrap_CheckISRMemoryAccess(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Access) = OsApi_CheckISRMemoryAccess(pPkg->Arg1.ISRId,pPkg->Arg2.MemStartAddr,pPkg->Arg3.MemSize);
}

/**
 * @brief Checks the access permissions for the specified task's memory region in user mode.
 * @param FnIndex The index of the trap function to call.
 * @param FnParam The parameters for the trap function, including the task index, memory start address, and memory size.
 * @return The access permissions for the specified memory region.
 */
static FUNC(void, OS_CODE) OsTrap_CheckTaskMemoryAccess(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Access) = OsApi_CheckTaskMemoryAccess(pPkg->Arg1.taskIndex,pPkg->Arg2.MemStartAddr,pPkg->Arg3.MemSize);
}

/**
 * @brief Checks the access permissions for the specified object in user mode.
 * @param FnIndex The index of the trap function to call.
 * @param FnParam The parameters for the trap function, including the application ID, object type, and object ID.
 * @return void
 */
static FUNC(void, OS_CODE) OsTrap_CheckObjectAccess(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.ObjAccess) = OsApi_CheckObjectAccess(pPkg->Arg1.AppID,pPkg->Arg2.ObjType,pPkg->Arg3.ObjID);
}

/**
 * @brief Checks the ownership of the specified object in user mode.
 * @param FnIndex The index of the trap function to call.
 * @param FnParam The parameters for the trap function, including the object type and object ID.
 * @return The application ID that owns the specified object.
 */
static FUNC(void, OS_CODE) OsTrap_CheckObjectOwnership(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.AppId) = OsApi_CheckObjectOwnership(pPkg->Arg1.ObjType,pPkg->Arg2.ObjID);
}

/**
 * @brief Starts the specified schedule table with a relative offset in user mode.
 * @param FnIndex The index of the trap function to call.
 * @param FnParam The parameters for the trap function, including the schedule table ID and the relative offset.
 * @return void
 */
static FUNC(void, OS_CODE) OsTrap_StartScheduleTableRel(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = OsApi_StartScheduleTableRel(pPkg->Arg1.ScheduleTblId1,pPkg->Arg2.Offset);
}

/**
 * @brief Starts the specified schedule table at an absolute time in user mode.
 * @param FnIndex The index of the trap function to call.
 * @param FnParam The parameters for the trap function, including the schedule table ID and the absolute start time.
 * @return void
 */
static FUNC(void, OS_CODE) OsTrap_StartScheduleTableAbs(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = OsApi_StartScheduleTableAbs(pPkg->Arg1.ScheduleTblId1,pPkg->Arg2.start);
}

/**
 * @brief Stops the specified schedule table in user mode.
 * @param FnIndex The index of the trap function to call.
 * @param FnParam The parameters for the trap function, including the schedule table ID.
 * @return void
 */
static FUNC(void, OS_CODE) OsTrap_StopScheduleTable(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = OsApi_StopScheduleTable(pPkg->Arg1.ScheduleTblId1);
}

/**
 * @brief Switches to the next schedule table in user mode.
 * @param FnIndex The index of the trap function to call.
 * @param FnParam The parameters for the trap function, including the current and next schedule table IDs.
 * @return void
 */
static FUNC(void, OS_CODE) OsTrap_NextScheduleTable(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = OsApi_NextScheduleTable(pPkg->Arg1.ScheduleTblId1,pPkg->Arg2.ScheduleTblId2);
}

/**
 * @brief Increments the specified counter in user mode.
 * @param FnIndex The index of the trap function to call.
 * @param FnParam The parameters for the trap function, including the counter ID.
 * @return void
 */
static FUNC(void, OS_CODE) OsTrap_IncrementCounter(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = OsApi_IncrementCounter(pPkg->Arg1.CounterId);
}

/**
 * @brief Terminates the specified application with the given restart option in user mode.
 * @param FnIndex The index of the trap function to call.
 * @param FnParam The parameters for the trap function, including the application ID and restart option.
 * @return void
 */
static FUNC(void, OS_CODE) OsTrap_TerminateApplication(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = OsApi_TerminateApplication(pPkg->Arg1.AppID, pPkg->Arg2.RestartOpt);
}

/**
 * @brief Allows access to a protected resource in user mode.
 * @param FnIndex The index of the trap function to call.
 * @param FnParam The parameters for the trap function.
 * @return void
 */
static FUNC(void, OS_CODE) OsTrap_AllowAccess(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = OsApi_AllowAccess();
}

/**
 * @brief Enables the specified interrupt source in user mode.
 * @param FnIndex The index of the trap function to call.
 * @param FnParam The parameters for the trap function.
 * @return void
 */
static FUNC(void, OS_CODE) OsTrap_EnableInterruptSource(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = OsApi_EnableInterruptSource(pPkg->Arg1.ISRId,pPkg->Arg2.ClrPending);
}

/**
 * @brief Disables the specified interrupt source in user mode.
 * @param FnIndex The index of the trap function to call.
 * @param FnParam The parameters for the trap function.
 * @return void
 */
static FUNC(void, OS_CODE) OsTrap_DisableInterruptSource(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = OsApi_DisableInterruptSource(pPkg->Arg1.ISRId);
}

/**
 * @brief Gets the event mask for the specified task in user mode.
 * @param FnIndex The index of the trap function to call.
 * @param FnParam The parameters for the trap function.
 * @return void
 */
static FUNC(void, OS_CODE) OsTrap_GetEvent(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = OsApi_GetEvent(pPkg->Arg1.taskIndex,pPkg->Arg2.MaskRef);
}

/**
 * @brief Gets the current value of an alarm in user mode.
 * @param FnIndex The index of the trap function to call.
 * @param FnParam The parameters for the trap function.
 * @return void
 */
static FUNC(void, OS_CODE) OsTrap_GetAlarm(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = OsApi_GetAlarm(pPkg->Arg1.alarmid,pPkg->Arg2.TickRef);
}

/**
 * @brief Calls a trusted function in user mode.
 * @param FnIndex The index of the trap function to call.
 * @param FnParam The parameters for the trap function.
 * @return void
 */
static FUNC(void, OS_CODE) OsTrap_CallTrustedFunction(OsTrapParameterRefType FnParam)
{
    OsTrapArgType *pPkg;
    pPkg = (OsTrapArgType*)FnParam;
    *(pPkg->RetVal.Status) = OsApi_CallTrustedFunction(pPkg->Arg1.TrustedFuncId,pPkg->Arg2.TrustedFuncParamRef);
}

#define OS_CORE_CODE_SEC_END
#define OS_CORE_CONST_SEC_END
#define OS_CORE_DATA_SEC_END
#define OS_CORE_BSS_SEC_END
#include "Os_IntMemMap.h"
#endif /* MOS_PRIVILEGE_USER_ENABLE */

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
**   ------------------------------------------------------------------------------ **
**   Date              : 23-June-2022                                               **
**   CDSID             : rsivaku4                                                   **
**   RTC Id            : 1667509                                                    **
**   Change Description: OsHal related functions need to be removed from OsError.c  **
**----------------------------------------------------------------------------------
**   ------------------------------------------------------------------------------ **
**   Date              : 27-June-2022                                               **
**   CDSID             : pmathew                                                    **
**   RTC Id            : 1586146                                                    **
**   Change Description: mOS updations for supporting user mode                     **
**----------------------------------------------------------------------------------**/

/* end of file =============================================================*/

