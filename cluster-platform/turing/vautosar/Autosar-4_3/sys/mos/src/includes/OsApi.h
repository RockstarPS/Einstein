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
 * @file        OsApi.h
 * @details     <b> This file externs the generic APIs of the OS </b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef OS_IF_H
#define OS_IF_H

#include "OsTypes.h"
#include "OsScheduleTable.h"
#include "OsError.h"
#include "Os_Cfg.h"



extern StatusType OsApi_ActivateTask(TaskType TaskIndex);
extern StatusType OsApi_TerminateTask(void);
extern StatusType OsApi_ChainTask(TaskType TaskIndex);
extern StatusType OsApi_Schedule(void);
extern StatusType OsApi_GetTaskID(TaskRefType pTaskID);
extern StatusType OsApi_GetTaskState(TaskType TaskID, TaskStateRefType State);
extern void OsApi_DisableAllInterrupts(void);
extern void OsApi_EnableAllInterrupts(void);
extern void OsApi_SuspendAllInterrupts(void);
extern void OsApi_ResumeAllInterrupts(void);
extern void OsApi_SuspendOSInterrupts(void);
extern void OsApi_ResumeOSInterrupts(void);
extern StatusType OsApi_GetResource(ResourceType ResID);
extern StatusType OsApi_ReleaseResource(ResourceType ResID);
extern StatusType OsApi_SetEvent(TaskType TaskID,EventMaskType Mask);
extern StatusType OsApi_ClearEvent(EventMaskType Mask);
extern StatusType OsApi_GetEvent(TaskType TaskID,EventMaskRefType Mask);
extern StatusType OsApi_WaitEvent(EventMaskType Mask);
extern StatusType OsApi_GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info);
extern StatusType OsApi_GetAlarm(AlarmType AlarmID, TickRefType Tick);
extern StatusType OsApi_SetRelAlarm(AlarmType AlarmID, TickType Increment, TickType Cycle);
extern StatusType OsApi_SetAbsAlarm(AlarmType AlarmID, TickType Start, TickType Cycle);
extern StatusType OsApi_CancelAlarm(AlarmType AlarmID);
extern void OsApi_ShutdownOS(StatusType Error);

/*---+ Autosar API Wrappers--------------------------------------------------------------------*/
extern ApplicationType OsApi_GetApplicationID(void);
extern ApplicationType OsApi_GetCurrentApplicationID(void);
extern ISRType OsApi_GetISRID(void);
extern StatusType OsApi_CallTrustedFunction(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
extern ObjectAccessType OsApi_CheckObjectAccess(ApplicationType AppID, ObjectTypeType ObjType, ObjectIdType ObjID);
extern ApplicationType OsApi_CheckObjectOwnership(ObjectTypeType ObjType, ObjectIdType ObjID);
extern StatusType OsApi_StartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Offset);
extern StatusType OsApi_StartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start);
extern StatusType OsApi_StopScheduleTable(ScheduleTableType ScheduleTableID);
extern StatusType OsApi_NextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To);
extern StatusType OsApi_GetScheduleTableStatus(ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus);
extern StatusType OsApi_StartScheduleTableSynchron(ScheduleTableType ScheduleTableID);
extern StatusType OsApi_SyncScheduleTable(ScheduleTableType ScheduleTableID, TickType Value);
extern StatusType OsApi_SetScheduleTableAsync(ScheduleTableType ScheduleTableID);
extern StatusType OsApi_IncrementCounter(CounterType CounterID);
extern StatusType OsApi_GetCounterValue(CounterType CounterID, TickRefType Value); /*MISRA RULE 8.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
extern StatusType OsApi_GetElapsedValue(CounterType CounterID, TickRefType Value, TickRefType ElapsedValue); /*MISRA RULE 8.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
extern StatusType OsApi_TerminateApplication(ApplicationType Application, RestartType RestartOption);
extern StatusType OsApi_AllowAccess (void);
extern StatusType OsApi_GetApplicationState(ApplicationType Application, ApplicationStateRefType Value);
extern uint32 OsApi_GetNumberOfActivatedCores(void);
extern CoreIdType OsApi_GetCoreId (void);
extern void OsApi_StartCore (CoreIdType CoreId, StatusType* StatusRef);
extern void OsApi_StartNonAutosarCore (CoreIdType CoreId, StatusType* StatusRef);
extern StatusType OsApi_EnableInterruptSource (ISRType ISRID,boolean ClearPending);
extern StatusType OsApi_DisableInterruptSource (ISRType ISRID);
#if (MOS_VERSION_INFO_API == STD_ON)
extern void OsApi_GetVersionInfo(Std_VersionInfoType* VersionInfo);
#endif

extern AccessType OsApi_CheckISRMemoryAccess (ISRType ISRId, MemoryStartAddressType Address, MemorySizeType Size);
extern AccessType OsApi_CheckTaskMemoryAccess (TaskType TaskID, MemoryStartAddressType Address, MemorySizeType Size);


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
**   Date              : 06-Jun-2020                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 920651                                                     **
**   Change Description: OS SC3 Support - Initial Version                           **
**----------------------------------------------------------------------------------**
**----------------------------------------------------------------------------------**
**   Date              : 27-May-2022                                                **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1672091                                                    **
**   Change Description: Bsw general requirements supported                         **
**----------------------------------------------------------------------------------**/
