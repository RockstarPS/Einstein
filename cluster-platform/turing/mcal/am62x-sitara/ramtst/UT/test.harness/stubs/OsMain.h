/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  OsMain.h                                             *
*  Module Short Name :  OsMainHeader                                         *
*  Description       :  This file externs the generic APIs of the OS         *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Independent                                            *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef OS_MAIN_H
#define OS_MAIN_H

#include "OsPrvTypes.h"
#include "OsError.h"
#include "Os_Cfg.h"
#include "OsApi.h"
#include "OsHalCpu.h"
#include "OsDlt.h"

#define OS_MODULE_ID		(0x01)
#define OS_INSTANCE_ID		(0x00)

/**** Os Service Identification ************************************************************************************/
# define OS_SYSACTIVATETASK_ID		(0x00u)


/**** Error Codes in Development-Mode ******************************************************************************/
/* AUTOSAR 4 development error codes */ 

/* Module Specific Error Codes */
# define OS_ACTIVATION_COUNT_LIMIT       (0x00u)


#define MOS_TEST

#define ECC1            1

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
#define E_OS_PROTECTION_MEMORY    14
#define E_OS_PROTECTION_TIME      15
#define E_OS_PROTECTION_ARRIVAL   16
#define E_OS_PROTECTION_LOCKED    17
#define E_OS_PROTECTION_EXCEPTION 18

#define E_OS_SERVICE_NOT_SUPPORTED 19U




/* state of tasks */
#define PRE_READY       0
#define RUNNING         1
#define WAITING         2
#define READY           3
#define SUSPENDED       4

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
#define RES_SCHEDULER                     0x00U

#define OS_RES_TYPE_STD                   0x00U

/* Application Type */
//To be generated in Os_Cfg

/* Application State Type */
#define OS_APPLICATION_TERMINATED           0x00U
#define OS_APPLICATION_RESTARTING           0x01U
#define OS_APPLICATION_ACCESSIBLE           0x02U


/* ObjectTypeType Defintions */
#define OS_OBJECT_TASK                      0x00U
#define OS_OBJECT_ISR                       0x01U
#define OS_OBJECT_ALARM                     0x02U
#define OS_OBJECT_RESOURCE                  0x03U
#define OS_OBJECT_COUNTER                   0x04U
#define OS_OBJECT_SCHEDULETABLE             0x05U
#define OS_OBJECT_INVALID                   0xFFU

/* ObjectAccessType Definitions */
#define OS_OBJECT_NO_ACCESS                 0x00U
#define OS_OBJECT_ACCESS                    0x01U

/* AccessType Definitions */
//todo: define the memory attributes
#define OS_ACCESS_TYPE_NON      0  /* No access rights are granted                                             */
#define OS_ACCESS_TYPE_READ     1  /* Read access right is granted                                             */
#define OS_ACCESS_TYPE_WRITE    2  /* Write access right is granted                                            */
#define OS_ACCESS_TYPE_RW       3  /* Read/Write access rights are granted                                     */
#define OS_ACCESS_TYPE_EXECUTE  4  /* Execution right is granted                                               */
#define OS_ACCESS_TYPE_RX       5  /* Read access and Execution rights are granted                             */
#define OS_ACCESS_TYPE_WX       6  /* Write access and execution rights are granted                            */
#define OS_ACCESS_TYPE_RWX      7  /* Read/Write access and execution rights are granted                       */
#define OS_ACCESS_TYPE_STACK    8  /* This is stack region                                                     */
#define OS_ACCESS_TYPE_RS       9  /* Read access right is granted, this is stack region                       */
#define OS_ACCESS_TYPE_WS       10 /* Write access right is granted, this is stack region                      */
#define OS_ACCESS_TYPE_RWS      11 /* Read/Write access rights are granted, this is stack region               */
#define OS_ACCESS_TYPE_XS       12 /* Execution right is granted, this is stack region                         */
#define OS_ACCESS_TYPE_RXS      13 /* Read access and Execution rights are granted, this is stack region       */
#define OS_ACCESS_TYPE_WXS      14 /* Write access and execution rights are granted, this is stack region      */
#define OS_ACCESS_TYPE_RWXS     15  /* Read/Write access and execution rights are granted, this is stack region */


/* RestartType Definitions */
#define OS_APPLICATION_RESTART          0U
#define OS_APPLICATION_NO_RESTART       1U
#define OS_APPLICATION_RESTART_MAX_TYPE 2U



#define osdEventAllowedContext      (osdCtxTask | osdCtxISRCat2)
#define osdScheduleAllowedContext   (osdCtxTask)
#define osdGetResourceAllowedContext        (osdCtxTask | osdCtxISRCat2)











/*ROM*/


extern const TcbConfigType      TcbTaskConfig[OsNumberOfTasks];
extern const OsIsrConfigType    OsIsrConfig[OsNumberOfIsr];

extern const OsStackType OsSystemStack;
extern const OsStackType OsIRQStack;
extern const OsStackType OsFIQStack;

extern const AlarmConfigType    AlarmConfig[OsNumberOfAlarms];
extern const CounterConfigType  CounterConfig[osMaxCounterId];




#if (OsNumberOfAutoStartTasks > 0)
extern const TaskType           AutoStartTaskList[OsNumberOfAutoStartTasks];
#endif


extern void OsInitMemory(void);
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
extern StatusType osGetAlarm(AlarmType AlarmID, TickRefType Tick);
extern StatusType osSetRelAlarm(AlarmType AlarmID, TickType Increment, TickType Cycle);
extern StatusType osCancelAlarm(AlarmType AlarmID);

/*---------------------------**
** Prototypes of OsEvent Api **
**---------------------------*/
extern StatusType osSetEvent(TaskType TaskIndex, EventMaskType EventMask );
extern StatusType osClearEvent(EventMaskType EventMask );
extern StatusType osGetEvent(TaskType TaskIndex, EventMaskRefType Event );
extern StatusType osWaitEvent(EventMaskType EventMask );
extern ISRType  osGetISRID(void);

/*-------------------------**
** Prototypes of OsRes Api **
**-------------------------*/
extern StatusType osGetResource(ResourceType res);
extern StatusType osReleaseResource(ResourceType res);
extern void OsRes_InitMemory(void);

/*--------------------------**
** Prototypes of OsMain Api **
**--------------------------*/
extern void osStartOS(void);
extern void osEnableAllInterrupts(void);
extern void osDisableAllInterrupts(void);
extern void osSuspendAllInterrupts(void);
extern void osResumeAllInterrupts(void);
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
extern void OsPrvSetActiveParam(OsObjConfigRefType pCurrObjRef);

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
#include "OsScheduleTable.h"

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
extern void osDispatchAsm(void);
extern void osSysTimerIsrAsm(void);
extern void osStartOSasmArm(void);
extern void osStartOSasm(void);
/*---------------------------**
** Prototypes of OsError Api **
**---------------------------*/
extern void OsErr_osFatalErrorHook(OsServiceIdType ServiceId, StatusType* pStatus, StatusType Status);
extern void osMissingTerminateError(void);
extern void OsErr_osApplicationErrorHook (OsServiceIdType ServiceId, StatusType* pStatus, StatusType Status);
extern void OsErr_osProtectionHook(ProtectionErrType ErrorInfo);
extern void osSysErrAssert(void);
extern void OsErr_LogExtendedStatus(StatusType* pStatus, StatusType Status);


extern void osTaskStartHook (void);
extern void osTaskStopHook (void);
extern void osTaskResumeHook(void);
extern void osCriticalSectionStartHook(void);
extern void osCriticalSectionStopHook(void);
/*----------------------------------------**
** Abstraction Macros to external modules **
**----------------------------------------*/

#define osDispatch()                osDispatchAsm()






#define ApiError(x,y)

#define osGetSystemCounter()        osCounter[SystemTimer]

#define OsSetContext(x)             (OsCtrlParam.CurrentContext = x)

#define OsGetContext()              (OsCtrlParam.CurrentContext)

#define StartOS(x)                  osIntStartOS(x)



#if (OS_CFG_MEMORY_PROTECTION == STD_ON)
/************* OSEK APIs ************/
#define ActivateTask(x)             OsApi_ActivateTask(x)

#define TerminateTask()            	OsApi_TerminateTask()

#define ChainTask(x)                OsApi_ChainTask(x)

#define Schedule()                  OsApi_Schedule()

#define GetTaskID(x)                OsApi_GetTaskID(x)

#define GetTaskState(x,y)			OsApi_GetTaskState(x,y)

#define DisableAllInterrupts()      OsApi_SuspendAllInterrupts() //osDisableAllInterrupts()

#define EnableAllInterrupts()       OsApi_ResumeAllInterrupts() //osEnableAllInterrupts()

#define SuspendAllInterrupts()      OsApi_SuspendAllInterrupts()

#define ResumeAllInterrupts()       OsApi_ResumeAllInterrupts()

#define SuspendOSInterrupts()       OsApi_SuspendAllInterrupts()

#define ResumeOSInterrupts()        OsApi_ResumeAllInterrupts()  //todo: update the below two macros for Os resume/suspend interrupts

#define GetResource(x)              OsApi_GetResource(x)

#define ReleaseResource(x)          OsApi_ReleaseResource(x)

#define SetEvent(x, y)              OsApi_SetEvent(x,y)

#define ClearEvent(x)               OsApi_ClearEvent(x)

#define GetEvent(x, y)              OsApi_GetEvent(x,y)

#define WaitEvent(x)                OsApi_WaitEvent(x)

#define GetAlarmBase(x,y)           OsApi_GetAlarmBase(x,y)

#define GetAlarm(x, y)              OsApi_GetAlarm(x,y)

#define SetRelAlarm(x,y,z)          OsApi_SetRelAlarm(x,y,z)

#define SetAbsAlarm(x,y,z)          OsApi_SetAbsAlarm(x,y,z)

#define CancelAlarm(x)              OsApi_CancelAlarm(x)

#define ShutdownOS(x)               OsApi_ShutdownOS(x)

/***** Autosar OS Public APIs *******/

#define GetApplicationID()              OsApi_GetApplicationID()

#define GetCurrentApplicationID()       OsApi_GetCurrentApplicationID()

#define GetISRID()                      OsApi_GetISRID()

#define CallTrustedFunction(x,y)        OsApi_CallTrustedFunction((x),(y))

#define CheckISRMemoryAccess(x,y,z)     OsCheckISRMemoryAccess((x),(y),(z)) //todo: Use OsApi for Mpu

#define CheckTaskMemoryAccess(x,y,z)    OsCheckTaskMemoryAccess((x),(y),(z)) //todo: Use OsApi for Mpu

#define CheckObjectAccess(x,y,z)        OsApi_CheckObjectAccess(x,y,z)

#define CheckObjectOwnership(x,y)       OsApi_CheckObjectOwnership(x,y)

#define StartScheduleTableRel(x,y)      OsApi_StartScheduleTableRel(x,y)

#define StartScheduleTableAbs(x,y)      OsApi_StartScheduleTableAbs(x,y)

#define StopScheduleTable(x)            OsApi_StopScheduleTable(x)

#define NextScheduleTable(x,y)          OsApi_NextScheduleTable(x,y)

#define GetScheduleTableStatus(x,y)     OsApi_GetScheduleTableStatus(x,y)

#define StartScheduleTableSynchron(x)   OsApi_StartScheduleTableSynchron()

#define SyncScheduleTable(x,y)          OsApi_SyncScheduleTable(x,y)

#define SetScheduleTableAsync(x)        OsApi_SetScheduleTableAsync(x)

#define IncrementCounter(x)             OsApi_IncrementCounter(x)

#define GetCounterValue(x,y)            OsApi_GetCounterValue(x,y)

#define GetElapsedValue(x,y,z)          OsApi_GetElapsedValue(x,y,z)

#define TerminateApplication(x,y)       OsApi_TerminateApplication(x,y)

#define AllowAccess()                   OsApi_AllowAccess()

#define GetApplicationState(x,y)        OsApi_GetApplicationState((x),(y))

#define GetNumberOfActivatedCores()     OsApi_GetNumberOfActivatedCores()

#define GetCoreId()                     OsApi_GetCoreId()

#define StartCore(x,y)                  OsApi_StartCore(x,y)

#define StartNonAutosarCore(x,y)        OsApi_StartNonAutosarCore(x,y)

#define EnableInterruptSource(x,y)      OsApi_EnableInterruptSource(x,y)

#define DisableInterruptSource(x)       OsApi_DisableInterruptSource(x)

/*--------- End of Supported APIs --------------------------------------------*/

#else  /* Call OS Api directly if MPU is not used */

/************* OSEK APIs ************/
#define ActivateTask(x)             osActivateTask(x)


#define TerminateTask()            	osTerminateTask()

#define ChainTask(x)                

#define Schedule()                  OsSchedule()

#define GetTaskID(x)                osGetTaskID(x)

#define GetTaskState(x,y)			osGetTaskState(x,y)

#define EnableAllInterrupts()       osResumeAllInterrupts() //osEnableAllInterrupts()

#define DisableAllInterrupts()      osSuspendAllInterrupts() //osDisableAllInterrupts()

//todo: update the below two macros for Os resume/suspend interrupts
#define ResumeOSInterrupts()        osResumeAllInterrupts()

#define SuspendOSInterrupts()       osSuspendAllInterrupts()

#define ResumeAllInterrupts()       osResumeAllInterrupts()

#define SuspendAllInterrupts()      osSuspendAllInterrupts()

#define GetResource(x)              osGetResource(x)

#define ReleaseResource(x)          osReleaseResource(x)

#define SetEvent(x, y)              osSetEvent(x,y)

#define GetEvent(x, y)              osGetEvent(x,y)

#define ClearEvent(x)               osClearEvent(x)

#define WaitEvent(x)                osWaitEvent(x)

#define GetAlarm(x, y)              osGetAlarm(x,y)

#define SetRelAlarm(x,y,z)          osSetRelAlarm(x,y,z)

#define SetAbsAlarm(x,y,z)

#define CancelAlarm(x)              osCancelAlarm(x)

#define GetISRID()                  osGetISRID()

#define ShutdownOS(x)               osShutdownOS(x)

/***** Autosar OS Public APIs *******/

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
#endif

#define TASK(x)                         void x##func(void)
#define ISR(x)                          void x##func(void)
#define ALARMCALLBACK(x)                void x(void)
#define OS_SERVICEID_SCHEDULE		0x0A
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

#include "Os_HooksCfg.h"

#define OS_TASK_START_HOOK()                 OsCfgPreTaskHook()
#define OS_TASK_RESUME_HOOK()                OsCfgPreTaskHook()
#define OS_TASK_STOP_HOOK()                  OsCfgPostTaskHook()
#define OS_ERROR_HOOK(x)                     OsCfgErrorHook(x)
#define OS_PROTECTION_HOOK(x)                OsCfgProtectionHook(x)
#define OS_ENTER_CRITICAL_SECTION_HOOK()     OsCfgCriticalSectionStartHook()
#define OS_EXIT_CRITICAL_SECTION_HOOK()      OsCfgCriticalSectionStoptHook()
#define OS_IS_SELFTEST_ACTIVE()              OsCfgCheckSelfTest()

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
**----------------------------------------------------------------------------------*/
