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
 * @file        OsMain.h
 * @details     <b>file externs the generic APIs of the OS</b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef OS_MAIN_H
#define OS_MAIN_H

#include "OsPrvTypes.h"
#include "OsError.h"
#include "Os_Cfg.h"
#include "Os_Lcfg.h"
#include "OsApi.h"
#include "OsHal_CpuCore.h"
#include "OsHal_CpuDerivative.h"
#include "OsDlt.h"
#include "OsScheduleTable.h"
#include "OsTrap.h"
#include "OsMetrics.h"


#define OS_MODULE_ID		(0x01) /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_INSTANCE_ID		(0x00) /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

/**** Os Service Identification ************************************************************************************/
# define OS_SYSACTIVATETASK_ID		(0x00u) /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/


/**** Error Codes in Development-Mode ******************************************************************************/
/* AUTOSAR 4 development error codes */ 

/* Module Specific Error Codes */
# define OS_ACTIVATION_COUNT_LIMIT       (0x00u) /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

#define MOS_TEST /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

#define ECC1            1
#define ECC2            2

/* All errors of API services (inherited from OSEK spec) */
#ifndef E_OK
#define E_OK            0 
#endif
#define E_OS_ACCESS     1
#define E_OS_CALLEVEL   2
#define E_OS_ID         3
#define E_OS_LIMIT      4
#define E_OS_NOFUNC     5
#define E_OS_RESOURCE   6
#define E_OS_STATE      7
#define E_OS_VALUE      8

#define E_OS_SERVICEID            9
#define E_OS_ILLEGAL_ADDRESS      10
#define E_OS_MISSINGEND           11
#define E_OS_DISABLEDINT          12
#define E_OS_STACKFAULT           13
#define E_OS_PROTECTION_MEMORY    14U
#define E_OS_PROTECTION_TIME      15
#define E_OS_PROTECTION_ARRIVAL   16
#define E_OS_PROTECTION_LOCKED    17
#define E_OS_PROTECTION_EXCEPTION 18U

#define E_OS_SERVICE_NOT_SUPPORTED 19U



/* state of tasks */
#define PRE_READY       0
#define RUNNING         1
#define WAITING         2U
#define READY           3
#define SUSPENDED       4U

/* Os Contexts */
#define osdCtxTask                        0x0001
#define osdCtxISRCat2                     0x0002
#define osdCtxPreTaskHook                 0x0004
#define osdCtxPostTaskHook                0x0008
#define osdCtxErrorHook                   0x0010
#define osdCtxApplErrorHook               0x0020
#define osdCtxEachErrorHook               0x0030
#define osdCtxStartupHook                 0x0040
#define osdCtxShutdownHook                0x0080
#define osdCtxProtectionHook              0x0100
#define osdCtxCOMErrorHook                0x0200
#define osdCtxCOMCallback                 0x0400
#define osdCtxStartComExtens              0x0800
#define osdCtxErrorHookFromStartupHook    0x1000

//Invalid ISR 
#define INVALID_ISR     0xFFFFFFFFUL

/* CoreId Type */
//To be generated in Os_Cfg

//Resource Types
#define OS_RES_TYPE_STD                   0x00U

/* Application Type */
//To be generated in Os_Cfg

/* Application State Type */
#define OS_APPLICATION_TERMINATED           0x00U /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_APPLICATION_RESTARTING           0x01U
#define OS_APPLICATION_ACCESSIBLE           0x02U


/* ObjectTypeType Defintions */
#define OS_OBJECT_TASK                      0x00U
#define OS_OBJECT_ISR                       0x01U
#define OS_OBJECT_ALARM                     0x02U /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_OBJECT_RESOURCE                  0x03U /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_OBJECT_COUNTER                   0x04U /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_OBJECT_SCHEDULETABLE             0x05U /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_OBJECT_KERNEL                    0x06U
#define OS_OBJECT_INVALID                   0xFFU

/* ObjectAccessType Definitions */
#define OS_OBJECT_NO_ACCESS                 0x00U
#define OS_OBJECT_ACCESS                    0x01U

/* AccessType Definitions */
//todo: define the memory attributes
#define OS_ACCESS_TYPE_NON      0  /* No access rights are granted                                             */
#define OS_ACCESS_TYPE_READ     1  /* Read access right is granted                                             */ /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_ACCESS_TYPE_WRITE    2  /* Write access right is granted                                            */ /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_ACCESS_TYPE_RW       3U /* Read/Write access rights are granted                                     */
#define OS_ACCESS_TYPE_EXECUTE  4  /* Execution right is granted                                               */ /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_ACCESS_TYPE_RX       5  /* Read access and Execution rights are granted                             */ /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_ACCESS_TYPE_WX       6  /* Write access and execution rights are granted                            */ /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_ACCESS_TYPE_RWX      7  /* Read/Write access and execution rights are granted                       */
#define OS_ACCESS_TYPE_STACK    8  /* This is stack region                                                     */ /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_ACCESS_TYPE_RS       9  /* Read access right is granted, this is stack region                       */ /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_ACCESS_TYPE_WS       10 /* Write access right is granted, this is stack region                      */ /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_ACCESS_TYPE_RWS      11 /* Read/Write access rights are granted, this is stack region               */ /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_ACCESS_TYPE_XS       12 /* Execution right is granted, this is stack region                         */ /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_ACCESS_TYPE_RXS      13 /* Read access and Execution rights are granted, this is stack region       */ /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_ACCESS_TYPE_WXS      14 /* Write access and execution rights are granted, this is stack region      */ /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_ACCESS_TYPE_RWXS     15  /* Read/Write access and execution rights are granted, this is stack region */ /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

/* App Access Levels */
#define OS_ACCESS_PRIVILEGED       0U
#define OS_ACCESS_UNPRIVILEGED     1U

/* Invalid Task */
#define INVALID_TASK        0xFF
/* Invalid Priority */
#define INVALID_PRIORITY    0xFF

/* Task Category */
#define TASK_NONPREEMPTIVE      0
#define TASK_PREEMPTIVE         1

/* Alarm Expiry Actions */
#define ALARM_CALLBACK_ACTION              1
#define ALARM_ACTIVATE_TASK_ACTION         2
#define ALARM_SET_EVENT_ACTION             3
#define ALARM_INCREMENT_COUNTER_ACTION     4

/* TaskType */
#define TASK_BASIC      0
#define TASK_EXTENDED   1

/* Os Stacks Initialize Pattern */
#define osdStackCheckPattern                0xaaaaaaaaUL

/* RestartType Definitions */
#define OS_APPLICATION_RESTART          0U /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_APPLICATION_NO_RESTART       1U /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_APPLICATION_RESTART_MAX_TYPE 2U /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/



#define osdEventAllowedContext      ((uint16)osdCtxTask | (uint16)osdCtxISRCat2)
#define osdScheduleAllowedContext   (osdCtxTask)
#define osdGetResourceAllowedContext        ((uint16)osdCtxTask | (uint16)osdCtxISRCat2)











/*ROM*/
extern const OsStackType OsSystemStack; /*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
extern const OsStackType OsIRQStack;
extern const OsStackType OsFIQStack;

/*----------------------------**
** protoypes of OsCore Api s  **
**----------------------------*/
extern void OsCore_InitMem(void);
extern CoreIdType OsCore_GetCurrentCore(void);
extern uint32 OsGetNumberOfActivatedCores(void);
extern CoreIdType OsGetCoreId(void);
extern void OsStartCore(CoreIdType CoreId, StatusType* StatusRef);
extern void OsStartNonAutosarCore(CoreIdType CoreId, StatusType* StatusRef);


/*----------------------------**
** protoypes of OsApp Api s  **
**----------------------------*/
extern OsAppParamType* OsGetAppParam(ApplicationType AppId);
extern ApplicationType OsGetApplicationId(void);
extern ApplicationType OsGetCurrentApplicationID(void);
extern ObjectIdType OsGetCurrentObjectID(void);
extern OsObjConfigRefType OsGetCurrentObj(void);
extern OsAppConfigRefType OsGetCurrentApplication(void);
extern StatusType OsTerminateApplication(ApplicationType Application, RestartType RestartOption);
extern StatusType OsAllowAccess(void);
extern StatusType OsGetApplicationState(ApplicationType Application, ApplicationStateRefType Value);
extern ObjectAccessType OsCheckObjectAccess(ApplicationType AppID, ObjectTypeType ObjType, ObjectIdType ObjID);
extern ApplicationType OsCheckObjectOwnership(ObjectTypeType ObjType, ObjectIdType ObjID);

/*----------------------------**
** protoypes of OsTask Api s  **
**----------------------------*/
extern StatusType osActivateTask(TaskType TaskIndex);
extern StatusType osTerminateTask(void);
extern StatusType OsSchedule(void);

/*---------------------------**
** Prototypes of OsSched Api **
**---------------------------*/
extern void osSchedInsertTask(TaskType TaskIndex);
extern void osSchedRemoveTask(void);
extern void osSchedGetResource(const OsResConfigType* pResConfig);
extern void osSchedReleaseResource(const OsResConfigType* pResConfig);
extern osuint8 OsSchedIsTaskSwitchReqd (OsCtrlParamType* pOsCtrlParam);
extern void OsSchedGetNextHighPrioTask (OsCtrlParamType* pOsCtrlParam);

/*---------------------------**
** Prototypes of OsAlarm Api **
**---------------------------*/
extern StatusType Os_GetAlarm(AlarmType AlarmID, TickRefType Tick);
extern StatusType Os_SetRelAlarm(AlarmType AlarmID, TickType Increment, TickType Cycle);
extern Std_ReturnType Os_SetAbsAlarm(AlarmType AlarmID, TickType Time, TickType Cycle);
extern StatusType Os_CancelAlarm(AlarmType AlarmID);

/*---------------------------**
** Prototypes of OsEvent Api **
**---------------------------*/
extern StatusType osSetEvent(TaskType TaskIndex, EventMaskType EventMask );
extern StatusType osClearEvent(EventMaskType EventMask );
extern StatusType osGetEvent(TaskType TaskIndex, EventMaskRefType Event );
extern StatusType osWaitEvent(EventMaskType EventMask );
extern ISRType  OsGetISRId(void);
extern ISRType  osGetISRID(void);/*MISRA RULE 4.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

/*-------------------------**
** Prototypes of OsRes Api **
**-------------------------*/
extern StatusType osGetResource(ResourceType Res);
extern StatusType osReleaseResource(ResourceType Res);
extern void OsRes_InitMemory(void);

/*--------------------------**
** Prototypes of OsMain Api **
**--------------------------*/
extern void osStartOS(void);
extern void osEnableAllInterrupts(void);
extern void osDisableAllInterrupts(void);
extern void osSuspendAllInterrupts(void);
extern void osResumeAllInterrupts(void);
extern void osSuspendOsInterrupts(void);
extern void osResumeOsInterrupts(void);
extern osbool osCheckInterruptsEnabled(void);
extern void osShutdownOS(StatusType Error);
extern StatusType osGetTaskID(TaskRefType TaskIdRef);
extern StatusType osGetTaskState(TaskType TaskID, TaskStateType* TaskState);
extern osStackUsageType osGetTaskStackUsage(TaskType TaskId);
extern osStackUsageType osGetISRStackUsage(ISRType ISRId);
extern void osCheckTaskStackOverflow(TaskType TaskId);
extern void osCheckISRStackOverflow(ISRType ISRId);
extern void OsPrvSetTaskActiveParam(void);
extern void OsPrvSetIsrActiveParam(void);
extern OsAppConfigRefType OsPrvGetDynApp(void);
extern void OsPrvSetDynApp (OsAppConfigRefType pDynApp);
extern void OsPrvEnterCriticalSection(void);
extern void OsPrvExitCriticalSection(void);
extern AccessLevelType OsPrvGetCurrAppAccessLevel(void);
extern void OsPrvSetActiveParam(OsObjConfigRefType pCurrObjRef);
extern void HardFault_ErrorHandler(void);
#if (MOS_VERSION_INFO_API == STD_ON)
extern void Os_GetVersionInfo(Std_VersionInfoType* VersionInfo);
#endif

#if(OS_CFG_MEMORY_PROTECTION == STD_ON)
extern StatusType OsCallTrustedFunction(TrustedFunctionIndexType FnIndex, TrustedFunctionParameterRefType FnParam);
extern AccessType OsCheckISRMemoryAccess(ISRType ISRId, MemoryStartAddressType Address, MemorySizeType Size);
extern AccessType OsCheckTaskMemoryAccess(TaskType TaskID, MemoryStartAddressType Address, MemorySizeType Size);
#endif
/*--------------------------**
** Prototypes of OsCounter Api **
**--------------------------*/
extern StatusType OsIncrementCounter(CounterType CounterId);
extern StatusType OsGetCounterValue(CounterType CounterID, TickRefType Value);
extern StatusType OsGetElapsedValue(CounterType CounterID, TickRefType Value, TickRefType ElapsedValue);

/*--------------------------**
** Prototypes of OsScheduleTable Api **
**--------------------------*/


extern StatusType OsStartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start);
extern StatusType OsStartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Start);
extern StatusType OsStopScheduleTable(ScheduleTableType ScheduleTableID);
extern StatusType OsNextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To);
extern StatusType OsGetScheduleTableStatus(ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus);


/*--------------------------**
** Prototypes of OsMain Api **
**--------------------------*/
extern void osInitialize(void);
extern void OsMainInitObjRef(OsObjConfigRefType pObj);
/*-----------------------------**
** Assembly Routine Prototypes **
**-----------------------------*/
extern void osDispatchAsm(void); /*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
extern void osSysTimerIsrAsm(void); /*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
extern void osStartOSasmArm(void); /*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
extern void osStartOSasm(void); /*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
/*---------------------------**
** Prototypes of OsError Api **
**---------------------------*/
extern void OsErr_osFatalErrorHook(OsServiceIdType ServiceId, StatusType* pStatus, StatusType Status);
extern void osMissingTerminateError(void);
extern void OsErr_osApplicationErrorHook (OsServiceIdType ServiceId, StatusType* pStatus, StatusType Status);
extern void OsErr_osProtectionHook(ProtectionErrType ErrorInfo);
extern void osSysErrAssert(void);
extern void osSysInternalErrAssert (void);
extern void OsErr_LogExtendedStatus(StatusType* pStatus, StatusType Status);
extern void OsErr_InvalidSvcCallHook(void);

extern void osTaskStartHook (void);
extern void osTaskStopHook (void);
extern void osTaskResumeHook(void);
extern void osCriticalSectionStartHook(void);
extern void osCriticalSectionStopHook(void);

extern osuint16 Os_GetContext(void);
extern StatusType Os_SetContext(osuint16 Context);



/*----------------------------------------**
** Abstraction Macros to external modules **
**----------------------------------------*/


#define osDispatch()                 OsStartDispatchMetric(); \
                                    osDispatchAsm()





#define ApiError(x,y) /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

#define StartOS(x)                  OsHal_CpuStartOS(x)

#define TASK(x)                         void x##func(void)
#define ISR(x)                          void x##func(void)
#define ALARMCALLBACK(x)                void x(void) /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_SERVICEID_SCHEDULE		0x0A /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
/*---------------------------**
**                           **
** Debug or Tracing Macros   **
** users to terminate with ; **
**---------------------------*/

#define OS_START_ENTRY()

/* ** To indicate that the OS startup is complete. ** */
/* ** Post execution of this macro the             ** */
/* ** OsTimer gets started by osekstart            ** */
#define OS_STARTUP_HOOK()                    OsCfgStartUpHook()

#define OS_UNRECOVERABLE_ERROR_HOOK()        OsCfgShutdownHook()



#define OS_TASK_START_HOOK()                 OsCfgPreTaskHook()
#define OS_TASK_RESUME_HOOK()                OsCfgPreTaskHook()
#define OS_TASK_STOP_HOOK()                  OsCfgPostTaskHook()
#define OS_ERROR_HOOK(x)                     OsCfgErrorHook(x)
#define OS_PROTECTION_HOOK(x)                OsCfgProtectionHook(x)
#define OS_ENTER_CRITICAL_SECTION_HOOK()     OsCfgCriticalSectionStartHook()
#define OS_EXIT_CRITICAL_SECTION_HOOK()      OsCfgCriticalSectionStoptHook()
#define OS_IS_SELFTEST_ACTIVE()              OsCfgCheckSelfTest()

#ifndef OS_PRIVILEGE_USER_ENABLE
/* Routing Of Api's */
#define ActivateTask(x)             osActivateTask(x)

#define ShutdownOS(x)               osShutdownOS(x)

#define GetApplicationID()          OsGetApplicationId()

#define GetCurrentApplicationID()   OsGetCurrentApplicationID()

#define GetISRID()                  OsGetISRId()

#define CallTrustedFunction(x,y)        OsCallTrustedFunction((x),(y))

#define CheckISRMemoryAccess(x,y,z)     OsCheckISRMemoryAccess((x),(y),(z))

#define CheckTaskMemoryAccess(x,y,z)    OsCheckTaskMemoryAccess((x),(y),(z))

#define CheckObjectOwnership(x,y)       OsCheckObjectOwnership((x),(y))

#define StartScheduleTableAbs(x,y)      OsStartScheduleTableAbs(x,y)

#define StartScheduleTableRel(x,y)      OsStartScheduleTableRel(x,y)

#define StopScheduleTable(x)            OsStopScheduleTable(x)

#define NextScheduleTable(x,y)          OsNextScheduleTable(x,y)

#define GetScheduleTableStatus(x,y)     OsGetScheduleTableStatus(x,y)

#define IncrementCounter(x)             OsIncrementCounter(x)

#define GetCounterValue(x,y)            OsGetCounterValue(x,y)

#define GetElapsedValue(x,y,z)          OsGetElapsedValue(x,y,z)

#define TerminateApplication(x,y)       OsTerminateApplication(x,y)

#define AllowAccess()                   OsAppAllowAccess()

#define GetApplicationState(x,y)        OsAppGetApplicationState((x),(y))

#define ClearEvent(x)               osClearEvent(x)

#define GetEvent(x, y)              osGetEvent(x,y)

#define WaitEvent(x)                osWaitEvent(x)

#define SetEvent(x, y)              osSetEvent(x, y)

#define DisableAllInterrupts()      osDisableAllInterrupts()

#define EnableAllInterrupts()       osEnableAllInterrupts()

#define GetEvent(x, y)              osGetEvent(x,y)

#define GetResource(x)              osGetResource(x)

#define GetTaskID(x)                osGetTaskID(x)

#define GetTaskState(x,y)			osGetTaskState(x,y)

#define ReleaseResource(x)          osReleaseResource(x)

#define SuspendAllInterrupts()      osSuspendAllInterrupts()

#define ResumeAllInterrupts()       osResumeAllInterrupts()

#define ResumeOSInterrupts()        osResumeAllInterrupts()

#define SuspendOSInterrupts()       osSuspendAllInterrupts()

#define SetRelAlarm(x,y,z)          Os_SetRelAlarm(x,y,z)

#define TerminateTask()            	osTerminateTask()

#define CancelAlarm(x)              Os_CancelAlarm(x)

#define SetAbsAlarm(x,y,z)          Os_SetAbsAlarm(x,y,z)
#endif /* OS_PRIVILEGE_USER_ENABLE */
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
**   Date              : 16-Oct-2019                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 629102                                                     **
**   Change Description: Updated EventMaskType to support 64 bit                    **
**   ------------------------------------------------------------------------------ **
**   Date              : 09-Dec-2019                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 1393561                                                    **
**   Change Description: Added element ActivationCnt to TaskParam Datastructure     **
**   ------------------------------------------------------------------------------ **
**   Date              : 16-Jan-2020                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 718479                                                     **
**   Change Description: mOS - Update Counter to support 32 bit timers              **
**   ------------------------------------------------------------------------------ **
**   Date              : 27-Feb-2020                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 788958                                                     **
**   Change Description: mOS - Remove tight linkage to user hooks                   **
**   ------------------------------------------------------------------------------ **
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
