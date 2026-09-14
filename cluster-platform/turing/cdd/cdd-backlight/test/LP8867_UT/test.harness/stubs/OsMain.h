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
*  File Name         :  osek.h                                               *
*  Module Short Name :  osek header                                          *
*  Description       :  This file externs the generic APIs of the OS         *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  IAR                                                    *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef OS_MAIN_H
#define OS_MAIN_H

#include "OsError.h"
#include "Os_Cfg.h"

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

/* state of tasks */
#define PRE_READY       0
#define RUNNING         1
#define WAITING         2
#define READY           3
#define SUSPENDED       4

/* Os Contexts */
#define osdNormalContext        0
#define osdCat2IsrContext       1

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

#define osdEventAllowedContext  	(osdCtxTask | osdCtxISRCat2)
#define osdScheduleAllowedContext   (osdCtxTask)

/* OS type definitions */
/* Begin osTypeDefinitions (default) */
#ifndef osTypesDefined
#define osTypesDefined
typedef unsigned char  osuint8;
typedef unsigned short osuint16;
typedef unsigned long  osuint32;
typedef unsigned long long osuint64;
typedef signed   char  osint8;
typedef signed   short osint16;
typedef signed   long  osint32;
typedef signed long long osint64;
/* End osTypeDefinitions */
#endif

/* Boolean definition */
/* Begin osekBooleanDef (default) */
#ifndef osbool
#define osbool osuint8
#endif
/* End osekBooleanDef */

# ifndef STATUSTYPEDEFINED
#  define STATUSTYPEDEFINED
typedef osuint8 StatusType;
#endif

typedef osCpuStackType              osStackDataType;
typedef osStackDataType*            osStackPtrType;
typedef osStackDataType const *     osStackPtrToConstType;
typedef osuint16                    osStackUsageType;
typedef osStackDataType             osStackSizeType;
typedef osuint8                     TaskType;
typedef TaskType*                   TaskRefType;
typedef osuint8                     TaskStateType;
typedef TaskStateType*              TaskStateRefType;
typedef osCpuTaskAddressType        osTaskAddressType;
typedef osTaskAddressType*          osTaskAddressRefType;
typedef osuint8                     ResourceType;
typedef osuint64                    EventMaskType;
typedef EventMaskType*              EventMaskRefType;
typedef osuint8                     AlarmType;
typedef AlarmType*                  AlarmRefType;
typedef osuint32                    TickType;
typedef TickType*                   TickRefType;
typedef osuint16                    CounterType;
typedef osuint8                     TaskPriorityType;
typedef TaskPriorityType*           TaskPriorityRefType;
typedef osCpuTaskPriorityBitType    TaskPriorityBitType;
typedef osuint16                    ErrReasonType;
typedef ErrReasonType*              ErrReasonRefType;
typedef osCpuIntGlobalType          osIntGlobaltype;
typedef osuint32                    PhysicalTimeType;
typedef osuint32                    ISRType;
typedef osuint8                     AppModeType;
typedef osuint8                     ProtectionReturnType;
typedef osuint8                     osActivationCntType;


typedef void                        (*osTaskFuncRefType)(void);
typedef void                        (*osVoidFunctionType)(void);

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*ROM*/
typedef struct
{
    osTaskFuncRefType TaskStartAddress;
    osStackPtrType TaskStackStartAddress;
    osStackSizeType TaskStackSize;
    TaskPriorityType TaskPriority;
	osuint8	  TaskMaxActivationCount;
    osuint8   TaskCategory;
}TcbConfigType;


typedef struct
{
    osStackPtrType startAddr;
    osStackPtrType endAddr;
}OsStackType;

/*RAM*/
typedef struct
{
    TaskType            ActiveTaskIndex;
	TaskType            RequestedTaskIndex;
	TaskPriorityType    ActiveTaskPriority;
	TaskPriorityType    RequestedTaskPriority;
	TaskPriorityBitType TaskPriorityBits;
	osuint8             RequestScheduler;
	osuint8             LockDispatcher;
    osuint8             IntSaveDisableRequestCounter;
    osIntGlobaltype     IntSaveStatus;
    osIntGlobaltype     IntSaveGlobal;
    osuint16            CurrentContext;
}OsCtrlParamType;


typedef struct
{    
    #if (CC_TYPE == ECC1)
    EventMaskType   WaitEventMask;
    EventMaskType   SetEventMask;
    #endif
    osStackPtrType StackAddress;
    osuint8 State;
    osActivationCntType ActivationCnt;
}TaskParamType;

typedef struct
{
    void (*OsAlarmCallback)(void);
    TaskType OsAlarmTask;
    osuint8 OsAlarmAction;
    #if (CC_TYPE == ECC1)
    EventMaskType OsAlarmEvent;
    #endif
}AlarmConfigType;


typedef enum
{
    HARDWARE,
    SOFTWARE
}OsCounterListType;


typedef struct
{
    TickType            MinValue;
    TickType            MaxValue;
    OsCounterListType   OsCounterType;
}CounterConfigType;


typedef struct
{
	TickType AlarmCyclicTime;
	TickType AlarmTime;
	osuint8    AlarmActivated;
}AlarmParamType;


typedef struct
{
    OsCtrlParamType*    PtrToOsCtrl;
    ErrReasonType       LastErrReason;
    ErrReasonType       ErrReason;
    osuint32            ExceptionDetails;
}osErrParamType;


#include "OsInternal.h"

/*ROM*/


extern const TcbConfigType      TcbTaskConfig[OsNumberOfTasks]; 

extern const OsStackType OsSystemStack;
extern const OsStackType OsIRQStack;
extern const OsStackType OsFIQStack;

extern const AlarmConfigType    AlarmConfig[OsNumberOfAlarms];
extern const CounterConfigType  CounterConfig[osMaxCounterId];


#if (OsNumberOfAutoStartTasks > 0)
extern const TaskType           AutoStartTaskList[OsNumberOfAutoStartTasks];
#endif

/*----------------------------**
** protoypes of OsTask Api s  **
**----------------------------*/
extern StatusType osActivateTask (TaskType TaskIndex);
extern StatusType osTerminateTask (void);
extern StatusType OsSchedule (void);

/*---------------------------**
** Prototypes of OsSched Api **
**---------------------------*/
extern void osSchedInsertTask (TaskType TaskIndex);
extern void osSchedRemoveTask (void);
extern void osSchedGetResource (ResourceType ResId);
extern void osSchedReleaseResource (ResourceType ResId);
extern osuint8 OsSchedIsTaskSwitchReqd (OsCtrlParamType* pOsCtrlParam);
extern void OsSchedGetNextHighPrioTask (OsCtrlParamType* pOsCtrlParam);

/*---------------------------**
** Prototypes of OsAlarm Api **
**---------------------------*/
extern StatusType osGetAlarm (AlarmType AlarmID, TickRefType Tick);
extern StatusType osSetRelAlarm (AlarmType AlarmID, TickType Increment, TickType Cycle);
extern StatusType osCancelAlarm (AlarmType AlarmID);

/*---------------------------**
** Prototypes of OsEvent Api **
**---------------------------*/
extern StatusType osSetEvent ( TaskType TaskIndex, EventMaskType EventMask );
extern StatusType osClearEvent ( EventMaskType EventMask );
extern StatusType osGetEvent ( TaskType TaskIndex, EventMaskRefType Event );
extern StatusType osWaitEvent ( EventMaskType EventMask );
extern ISRType  osGetISRID(void);

/*-------------------------**
** Prototypes of OsRes Api **
**-------------------------*/
extern StatusType osGetResource (ResourceType res);
extern StatusType osReleaseResource (ResourceType res);

/*--------------------------**
** Prototypes of OsMain Api **
**--------------------------*/
extern void osStartOS (void);
extern void osEnableAllInterrupts (void);
extern void osDisableAllInterrupts (void);
extern void osSuspendAllInterrupts (void);
extern void osResumeAllInterrupts (void);
extern osbool osCheckInterruptsEnabled (void);
extern void osShutdownOS (StatusType Error);
extern StatusType osGetTaskID (TaskRefType TaskIdRef);
extern StatusType osGetTaskState (TaskType TaskID, TaskStateType* TaskState);
extern osStackUsageType osGetTaskStackUsage (TaskType TaskId);
extern osStackUsageType osGetISRStackUsage (ISRType ISRId);
extern void osCheckTaskStackOverflow (TaskType TaskId);
extern void osCheckISRStackOverflow (ISRType ISRId);
extern StatusType osGetCounterValue(CounterType CounterID, TickRefType Value);
extern StatusType osGetElapsedValue(CounterType CounterID, TickRefType Value, TickRefType ElapsedValue);

/*--------------------------**
** Prototypes of OsScheduleTable Api **
**--------------------------*/
#include "OsScheduleTable.h"

extern StatusType StartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start);
extern StatusType StartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Start);
extern StatusType StopScheduleTable(ScheduleTableType ScheduleTableID);
extern StatusType NextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To);

/*--------------------------**
** Prototypes of OsMain Api **
**--------------------------*/
extern void osInitialize (void);

/*-----------------------------**
** Assembly Routine Prototypes **
**-----------------------------*/
extern void osDispatchAsm(void);
extern void osSysTimerIsrAsm (void);
extern void osStartOSasmArm (void);
extern void osStartOSasm (void);
/*---------------------------**
** Prototypes of OsError Api **
**---------------------------*/
extern void osApiError (ErrReasonType Reason);
extern void osMissingTerminateError (void);
extern void osErrorHook (ErrReasonType Reason);
extern void osSysErrAssert (void);


extern void osTaskStartHook (void);
extern void osTaskStopHook (void);
extern void osTaskResumeHook(void);

/*----------------------------------------**
** Abstraction Macros to external modules **
**----------------------------------------*/

#define osDispatch()                osDispatchAsm()


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

#define IncrementCounter(x)         osIncrementCounter(x)

#define GetCounterValue(x,y)        osGetCounterValue(x,y)

#define GetElapsedValue(x,y,z)      osGetElapsedValue(x,y,z)

#define ApiError(x)                 osApiError(x)

#define osGetSystemCounter()        osCounter[SystemTimer]

#define OsSetContext(x)             (OsCtrlParam.CurrentContext = x)

#define OsGetContext()              (OsCtrlParam.CurrentContext)

#define StartOS(x)                  osIntStartOS(x)

#define ShutdownOS(x)               osShutdownOS(x)


#define TASK(x)  void x##func(void)
#define ISR(x) void x##func(void)
#define ALARMCALLBACK(x) void x(void)



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
#define OS_STARTUP_HOOK()           OsCfgStartUpHook()

#define OS_UNRECOVERABLE_ERROR_HOOK()

extern void PreTaskHook( void );
extern void PostTaskHook( void );

#define OS_TASK_START_HOOK()        OsCfgPreTaskHook()
#define OS_TASK_RESUME_HOOK()       OsCfgPreTaskHook()
#define OS_TASK_STOP_HOOK()         OsCfgPostTaskHook()

#define OS_INT_START_CRITICAL()
#define OS_INT_END_CRITICAL()

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
