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
 * @file        OsTrap.h
 * @details     <b>This file externs the generic APIs of the OS </b>
 * @note
 *              Compiler    : IAR \n
 *              Target Hw   : Independents
 *
 * @copyright   Visteon (c) 2021
 *
 */
#ifndef OS_TRAP_H
#define OS_TRAP_H

#include "Os.h"
#include "OsTypes.h"

#define ACTIVATE_TASK_TRAP_ID 0U
#define TERMINATE_TASK_TRAP_ID 1U
#define SET_REL_ALARM_TRAP_ID 2U
#define SET_ABS_ALARM_TRAP_ID 3U
#define SCHEDULE_TRAP_ID 4U
#define SUSPEND_ALL_INTERRUPTS_TRAP_ID 5U
#define RESUME_ALL_INTERRUPTS_TRAP_ID 6U
#define SUSPEND_OS_INTERRUPTS_TRAP_ID 7U
#define RESUME_OS_INTERRUPTS_TRAP_ID 8U
#define GET_RESOURCE_TRAP_ID 9U
#define RELEASE_RESOURCE_TRAP_ID 10U
#define SET_EVENT_TRAP_ID 11U
#define CLEAR_EVENT_TRAP_ID 12U
#define WAIT_EVENT_TRAP_ID 13U
#define CANCEL_ALARM_TRAP_ID 14U
#define SHUTDOWN_OS_TRAP_ID 15U
#define CHECK_ISR_MEMORY_ACCESS_TRAP_ID 16U
#define CHECK_TASK_MEMORY_ACCESS_TRAP_ID 17U
#define CHECK_OBJECT_ACCESS_TRAP_ID 18U
#define CHECK_OBJECT_OWNERSHIP_TRAP_ID 19U
#define START_SCHEDULE_TABLE_REL_TRAP_ID 20U
#define START_SCHEDULE_TABLE_ABS_TRAP_ID 21U
#define STOP_SCHEDULE_TABLE_TRAP_ID 22U
#define NEXT_SCHEDULE_TABLE_TRAP_ID 23U
#define INCREMENT_COUNTER_TRAP_ID 24U
#define TERMINATE_APPLICATION_TRAP_ID 25U
#define ALLOW_ACCESS_TRAP_ID 26U
#define ENABLE_INTERRUPT_SOURCE_TRAP_ID 27U
#define DISABLE_INTERRUPT_SOURCE_TRAP_ID 28U
#define GET_EVENT_TRAP_ID 29U
#define GET_ALARM_TRAP_ID 30U
#define TRUSTED_CALL_FUNCTION_TRAP_ID 31U

#define OS_TRAP_TABLE_SIZE 32U

/*MISRA RULE 4.9 VIOLATION: Function like macro -This warning is triaged for all functions below*/

extern FUNC(StatusType, OS_CODE) ActivateTask(TaskType TaskIndex);
extern FUNC(StatusType, OS_CODE) TerminateTask(void);
extern FUNC(StatusType, OS_CODE) ChainTask(TaskType TaskIndex);
extern FUNC(StatusType, OS_CODE) Schedule(void);
extern FUNC(StatusType, OS_CODE) GetTaskID(TaskRefType pTaskID);
extern FUNC(StatusType, OS_CODE) GetTaskState(TaskType TaskID, TaskStateRefType State);
extern FUNC(void, OS_CODE) DisableAllInterrupts(void);
extern FUNC(void, OS_CODE) EnableAllInterrupts(void);
extern FUNC(void, OS_CODE) SuspendAllInterrupts(void);
extern FUNC(void, OS_CODE) ResumeAllInterrupts(void);
extern FUNC(void, OS_CODE) SuspendOSInterrupts(void);
extern FUNC(void, OS_CODE) ResumeOSInterrupts(void);
extern FUNC(StatusType, OS_CODE) GetResource(ResourceType ResID);
extern FUNC(StatusType, OS_CODE) ReleaseResource(ResourceType ResID);
extern FUNC(StatusType, OS_CODE) SetEvent(TaskType TaskID,EventMaskType Mask);
extern FUNC(StatusType, OS_CODE) ClearEvent(EventMaskType Mask);
extern FUNC(StatusType, OS_CODE) GetEvent(TaskType TaskID,EventMaskRefType Mask);
extern FUNC(StatusType, OS_CODE) WaitEvent(EventMaskType Mask);
extern FUNC(StatusType, OS_CODE) GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info);
extern FUNC(StatusType, OS_CODE) GetAlarm(AlarmType AlarmID, TickRefType Tick);
extern FUNC(StatusType, OS_CODE) SetRelAlarm(AlarmType AlarmID, TickType Increment, TickType Cycle);
extern FUNC(StatusType, OS_CODE) SetAbsAlarm(AlarmType AlarmID, TickType Start, TickType Cycle);
extern FUNC(StatusType, OS_CODE) CancelAlarm(AlarmType AlarmID);
extern FUNC(void, OS_CODE) ShutdownOS(StatusType Error);
extern FUNC(ApplicationType, OS_CODE) GetApplicationID(void);
extern FUNC(ApplicationType, OS_CODE) GetCurrentApplicationID(void);
extern FUNC(ISRType, OS_CODE) GetISRID(void);
extern FUNC(StatusType, OS_CODE) CallTrustedFunction(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern FUNC(ObjectAccessType, OS_CODE) CheckObjectAccess(ApplicationType AppID, ObjectTypeType ObjType, ObjectIdType ObjID);
extern FUNC(ApplicationType, OS_CODE) CheckObjectOwnership(ObjectTypeType ObjType, ObjectIdType ObjID);
extern FUNC(StatusType, OS_CODE) StartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Offset);
extern FUNC(StatusType, OS_CODE) StartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start);
extern FUNC(StatusType, OS_CODE) StopScheduleTable(ScheduleTableType ScheduleTableID);
extern FUNC(StatusType, OS_CODE) NextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To);
extern FUNC(StatusType, OS_CODE) GetScheduleTableStatus(ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus);
extern FUNC(StatusType, OS_CODE) StartScheduleTableSynchron(ScheduleTableType ScheduleTableID);
extern FUNC(StatusType, OS_CODE) SyncScheduleTable(ScheduleTableType ScheduleTableID, TickType Value);
extern FUNC(StatusType, OS_CODE) SetScheduleTableAsync(ScheduleTableType ScheduleTableID);
extern FUNC(StatusType, OS_CODE) IncrementCounter(CounterType CounterID);
extern FUNC(StatusType, OS_CODE) GetCounterValue(CounterType CounterID, TickRefType Value);
extern FUNC(StatusType, OS_CODE) GetElapsedValue(CounterType CounterID, TickRefType Value, TickRefType ElapsedValue);
extern FUNC(StatusType, OS_CODE) TerminateApplication(ApplicationType Application, RestartType RestartOption);
extern FUNC(StatusType, OS_CODE) AllowAccess (void);
extern FUNC(StatusType, OS_CODE) GetApplicationState(ApplicationType Application, ApplicationStateRefType Value);
extern FUNC(uint32, OS_CODE) GetNumberOfActivatedCores(void);
extern FUNC(CoreIdType, OS_CODE) GetCoreId (void);
extern FUNC(void, OS_CODE) StartCore (CoreIdType CoreId, StatusType* StatusRef);
extern FUNC(void, OS_CODE) StartNonAutosarCore (CoreIdType CoreId, StatusType* StatusRef);
extern FUNC(StatusType, OS_CODE) EnableInterruptSource (ISRType ISRID,boolean ClearPending);
extern FUNC(StatusType, OS_CODE) DisableInterruptSource (ISRType ISRID);

#if (MOS_VERSION_INFO_API == STD_ON)
FUNC(void, OS_CODE) GetVersionInfo(Std_VersionInfoType* VersionInfo);
#endif

extern FUNC(AccessType, OS_CODE) CheckISRMemoryAccess (ISRType ISRId, MemoryStartAddressType Address, MemorySizeType Size);
extern FUNC(AccessType, OS_CODE) CheckTaskMemoryAccess (TaskType TaskID, MemoryStartAddressType Address, MemorySizeType Size);
extern FUNC(void, OS_CODE) OsHal_TrapHandler(OsTrapFuncIndexType FnIndex, OsTrapParameterRefType FnParam);

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
**----------------------------------------------------------------------------------**/

/* end of file =============================================================*/
/* end of file =============================================================*/
