/* Kernbauer Version: 2.16 Konfiguration: ArmCortexR Erzeugungsgangnummer: 59 Zweig: 1 */

/*****************************************************************************
| Project Name: MICROSAR OS
|    File Name: osek.h
|
|
|
|                   !!! THIS IS A BETA VERSION ONLY !!!
|
|
|  General code: @Version: 9.01.06@
|  Module version: $vv$=2.27
|
|  Description: contains osek prototypes and defines
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2000-2015 Vector Informatik GmbH          All rights reserved.
|****************************************************************************/

/* CovComment 0:  file: osek.h */
















/* MISRA RULE 19.15 VIOLATION: The QAC-Tool states a violation of rule 19.15 with 
 * message 0883 below. Anyhow, there is a double include prevention and therefore,
 * the message is considered to be wrong. */
/* double include preventer */
#ifndef _OSEK_H      /* PRQA S 0883 EOF */ /* see MISRA comment above */
#define _OSEK_H

/*lint -save Messages inhibited in this file, will be re-enabled at the end of file */
/*lint -e539 Did not expect positive indentation */

/* Vector release management */
#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif
/* KB begin vrmReleaseNumber (overwritten) */
/* Source release number */
#define osdVrmMajRelNum 7
#define osdVrmMinRelNum 0
/* KB end vrmReleaseNumber */
#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif

/* autosar conformant information publishing */
#define OS_VENDOR_ID 30        /*Autosar/HIS vendor ID Vector-Informatik*/
#define OS_MODULE_ID 0x01

#define OS_AR_RELEASE_MAJOR_VERSION 4
#define OS_AR_RELEASE_MINOR_VERSION 0
#define OS_AR_RELEASE_REVISION_VERSION 3
/* KB begin vrmReleaseNumber (overwritten) */
/* Source release number */
#define osdVrmMajRelNum 7
#define osdVrmMinRelNum 0
/* KB end vrmReleaseNumber */
#define OS_SW_MAJOR_VERSION osdVrmMajRelNumRef
#define OS_SW_MINOR_VERSION osdVrmMinRelNumRef
/* KB begin AutosarPatchVersion (default) */
#define OS_SW_PATCH_VERSION 0
/* KB end AutosarPatchVersion */

/* KB begin osekDefaultConstants (default) */
/* defines for all conformance classes */
#define BCC1   1U
#define BCC2   2U
#define ECC1   3U
#define ECC2   4U

/* and for all scalability classes */
#define SC1    1U
#define SC2    2U
#define SC3    3U
#define SC4    4U

#define STANDARD_STATUS 0U
#define EXTENDED_STATUS 1U

#define osdFALSE 0U
#define osdTRUE  1U

#define osdNULL ((osqPROM1 osqPROM2 void osqPROM3 *)0)

/* state of tasks */
#define PRE_READY       0
#define RUNNING         1
#define WAITING         2
#define READY           3
#define SUSPENDED       4

/* return codes for protection hook */
#ifndef OS_SUPPRESS_PROTHOOK_OLD_RET_VALS
#define PRO_KILLTASKISR           1U
#define PRO_KILLAPPL              2U
#define PRO_KILLAPPL_RESTART      3U
#endif /*OS_SUPPRESS_PROTHOOK_OLD_RET_VALS*/
#define PRO_TERMINATETASKISR      1U
#define PRO_TERMINATEAPPL         2U
#define PRO_TERMINATEAPPL_RESTART 3U
#define PRO_SHUTDOWN              4U
#define PRO_IGNORE                5U

/* KB end osekDefaultConstants */

/* OS type definitions */
/* KB begin osTypeDefinitions (default) */
typedef unsigned char  osuint8;
typedef unsigned short osuint16;
typedef unsigned long  osuint32;
typedef signed   char  osint8;
typedef signed   short osint16;
typedef signed   long  osint32;
/* KB end osTypeDefinitions */

/* Boolean definition */
/* KB begin osekBooleanDef (default) */
#ifndef osbool
#define osbool osuint8
#endif
/* KB end osekBooleanDef */

/* Type for boolean arrays */
/* KB begin osekBooleanArrayBaseTypeDef (default) */
typedef osbool osBoolArrayBaseType;
/* KB end osekBooleanArrayBaseTypeDef */


/* Are we in a PRQA/QAC/MISRA-check? */
#ifdef PRQA_PTRDIFF_T
 /* YES: Perform some adaptations to the OS */
 /* First the general adaptations: */
 #pragma PRQA_NO_RETURN osAbortSystem
 #pragma PRQA_NO_RETURN osAssertFailed
 #pragma PRQA_NO_RETURN osSysShutdownOS

 /* Then possible plattform specific adaptations: */
 /* KB begin osekHWosPrqaAdaptation (default) */
 /* no platform specific adaptations for PRQA/QAC */
 /* KB end osekHWosPrqaAdaptation */
#endif

/* Known Compilers */
/* KB begin osekCompilerDefines (overwritten) */
#define osdCompilerGreenhillsArmCortexR     1
#define osdMB9DF126               0
#define osdMB9DF125               1
#define osdMB9EF226               2
#define osdS6J32xx                3
#define osdS6J33xx                4
#define osdS6J34xx                5
/* KB end osekCompilerDefines */


   #if defined USE_QUOTE_INCLUDES
    #include "tcb.h"  /* include before */
   #else
    #include <tcb.h>  /* include before */
   #endif



/* KB begin osekStartOfHModule (default) */
/* KB end osekStartOfHModule */

/* KB begin osekHwMemoryQualifierDefines (default) */
/* define to nothing in the default case */


/* osqROM0 extern osqROM1 const osqROM2 osVersionVariantCodingType osqROM3 oskVersionVariant;  */
/* osqROM0 osqROM1 const osqROM2 osVersionVariantCodingType osqROM3 oskVersionVariant; */
#define osqROM0
#define osqROM1
#define osqROM2
#define osqROM3

/* extern osqPROM1 const osqPROM2 char osqPROM3 * osqROM1 const osqROM2 osqROM3 oskTcbTaskName[osdNumberOfAllTasks]; */
#define osqPROM1
#define osqPROM2
#define osqPROM3

/* osqRAM0 osqRAM1 volatile osqRAM2 TickType osqRAM3 osSystemCounter; */
/* osqRAM0 osqRAM1 osqRAM2 osDispatcherLockType osqRAM3 osLockDispatcher; */
#define osqRAM0 
#define osqRAM1 
#define osqRAM2 
#define osqRAM3 

/* osqRAM0 extern osqPRAM1 osTPTimeType osqPRAM2 osqPRAM3 * osqRAM1 <volatile> osqRAM2 osqRAM3 osOwnCcb->LockIsNotNeeded.ossAPIParam4; */
#define osqPRAM1
#define osqPRAM2
#define osqPRAM3

/*
 * osqFunc1 void osqFunc2 osSchedOnHomePrio(void)
 * {
 *    osqLPRAM1 volatile osqLPRAM2 osPrioFlagType osqLPRAM3 *ptr;
 *    ...
 * }
 */
#define osqLPRAM1
#define osqLPRAM2
#define osqLPRAM3


/* osqBOOL1 volatile osqBOOL2 osbool osqBOOL3 ptrToCcb->ossStartDispatcher; */
#define osqBOOL1 
#define osqBOOL2 
#define osqBOOL3 

/* osqTcbRAM1 volatile osqTcbRAM2 TickType osqTcbRAM3 osCounter[5]; */
/* extern osqTcbRAM1 osqTcbRAM2 osQEntryCountType osqTcbRAM3 ptrToCcb->ossQReadyTaskHead[osdNumberOfPriorities]; */
#define osqTcbRAM1 
#define osqTcbRAM2 
#define osqTcbRAM3 

/* extern (osqPTcbRAM1 osqPTcbRAM2 TaskType osqPTcbRAM3 *) osqROM1 const osqROM2 osqROM3 oskQActivationQueues[osdNumberOfPriorities]; */
#define osqPTcbRAM1 
#define osqPTcbRAM2 
#define osqPTcbRAM3 

/* osqStack1 osqStack2 osStackDataType osqStack3 osTaskStack1[80]; */
#define osqStack1
#define osqStack2
#define osqStack3

/* osqFunc1 void osqFunc2 Function1(void); */
#define osqFunc1
#define osqFunc2 

/* qualifiers for inline functions (one qualifier for each function) */
#define osqInlineGetHighPrioBit
/* KB end osekHwMemoryQualifierDefines */

/* include hardware specific header files before OSEK Typedefinitions */
/* KB begin osekHWincludeHwHeaderPreTypes (overwritten) */
/* KB end osekHWincludeHwHeaderPreTypes */

#if defined USE_QUOTE_INCLUDES
 #include "osekcov.h"
 #include "osekasrt.h" /* posix types must be defined      */
 #include "osekerr.h"  /* definitions of all error numbers */
#else
 #include <osekcov.h>
 #include <osekasrt.h> /* posix types must be defined      */
 #include <osekerr.h>  /* definitions of all error numbers */
#endif

/* KB begin osekTypedDefaultConstants (default) */
#define INVALID_ISR           ((ISRType)(0xFFFFFFFFUL))
#define INVALID_TASK          ((TaskType)(0xFFFFFFFFUL))
#define INVALID_OSAPPLICATION ((ApplicationType)0xFFU)
#define INVALID_SCHEDULETABLE ((ScheduleTableType)(0xFFFFFFFFUL))
#define INVALID_PROCESS       (((osProcessType)(0xFFFFFFFFUL)))

/* TR:SASR40:6011 Start */
#define APPLICATION_ACCESSIBLE ((ApplicationStateType)1)
#define APPLICATION_RESTARTING ((ApplicationStateType)2)
#define APPLICATION_TERMINATED ((ApplicationStateType)3)
/* TR:SASR40:6011 End */

/* idle definition for task */
#define osdNoActiveTask       INVALID_TASK
/* idle definition for prio */
#define osdNoActivePrio       ((osPrioType)(0xFFFFFFFFUL))
/* idle definition for resource list */
#define osdNoResource         ((ResourceType)(0xFFFFFFFFUL))


/* KB end osekTypedDefaultConstants */
/* access rights */
#define NO_ACCESS 0U
#define ACCESS 1U


/* Schedule Table status confirms to AS 3.0 */

#define SCHEDULETABLE_STOPPED                 0U
#define SCHEDULETABLE_NEXT                    1U
#define SCHEDULETABLE_WAITING                 2U
#define SCHEDULETABLE_RUNNING                 3U
#define SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS 4U

/* values for AccessType */
#define oskAccess_None 0x0U
#define oskAccess_Read 0x1U
#define oskAccess_Write 0x2U
#define oskAccess_Execute 0x4U
#define oskAccess_Stack 0x8U

/* macros for AccessType */
#define OSMEMORY_IS_READABLE(x) (((x) & oskAccess_Read)? 1 : 0)
#define OSMEMORY_IS_WRITEABLE(x) (((x) & oskAccess_Write)? 1 : 0)
#define OSMEMORY_IS_EXECUTABLE(x) (((x) & oskAccess_Execute)? 1 : 0)
#define OSMEMORY_IS_STACKSPACE(x) (((x) & oskAccess_Stack)? 1 : 0)

/* values for RestartType */
#define RESTART    1
#define NO_RESTART 2

/* SCHEDULETABLE AUTOSTART TYPE */
#define osdScheduleTableAutostartNO                  0U
#define osdScheduleTableAutostartABSOLUT             1U
#define osdScheduleTableAutostartRELATIVE            2U
#define osdScheduleTableAutostartSYNCHRON            3U

/* ALARM AUTOSTART TYPE */
#define osdAlarmAutostartNO                          0U
#define osdAlarmAutostartABSOLUTE                    1U
#define osdAlarmAutostartRELATIVE                    2U

#define OSINVALIDAPPMODE                             0U

/* KB begin osekHwTASKmacro (default) */
/* OSEK-conform task-function-macro */
#define TASK(x)  void x##func(void)
/* KB end osekHwTASKmacro */
/* KB begin osekHWISRmacro (default) */
/* OSEK-conform interrupt-function-macro */
#define ISR(x) void x##func(void)
/* KB end osekHWISRmacro */
/* KB begin osekHWAlrmCallbckmacro (default) */
/* OSEK-conform function-macro for alarm callbacks */
#define ALARMCALLBACK(x) void x(void)
/* KB end osekHWAlrmCallbckmacro */
/* Default application mode is generated (OSEK 2.2) */

/* KB begin osekContextConstants (default) */



/* context constants */
#define osdCtxTask           ((osuint16)0x0001)
#define osdCtxISRCat2        ((osuint16)0x0002)
#define osdCtxPreTaskHook    ((osuint16)0x0004)
#define osdCtxPostTaskHook   ((osuint16)0x0008)
#define osdCtxErrorHook      ((osuint16)0x0010)
#define osdCtxApplErrorHook  ((osuint16)0x0020)
#define osdCtxEachErrorHook  ((osuint16)0x0030)  /* system and appl spec. ErrorHook */
#define osdCtxStartupHook    ((osuint16)0x0040)
#define osdCtxShutdownHook   ((osuint16)0x0080)
#define osdCtxProtectionHook ((osuint16)0x0100)
/* additional flag for ErrorHook called from StartupHook */
#define osdCtxErrorHookFromStartupHook ((osuint16)0x1000)

/* PATCH */
#define osDisableGlobal()       __asm("   cpsid i ; globally disable interrupts"); \
                                __asm("   isb     ; instruction synchronization barrier")
#define osEnableGlobal()        __asm("   cpsie i ; globally enable interrupts")

#define osDisableLevel()        osDisableGlobal()
#define osEnableLevel()         osEnableGlobal() 
/*  Due to communication with Vector -amihayl1 */
/* allowed call context for each API function */
#define osdValidCtx_ActivateTask             (  osdCtxTask           | osdCtxISRCat2        )
#define osdValidCtx_GetResource              (  osdCtxTask           | osdCtxISRCat2        )
#define osdValidCtx_ReleaseResource          (  osdCtxTask           | osdCtxISRCat2        )
#define osdValidCtx_SetEvent                 (  osdCtxTask           | osdCtxISRCat2        )
#define osdValidCtx_SetRelAlarm              (  osdCtxTask           | osdCtxISRCat2        )
#define osdValidCtx_SetAbsAlarm              (  osdCtxTask           | osdCtxISRCat2        )
#define osdValidCtx_CancelAlarm              (  osdCtxTask           | osdCtxISRCat2        )
#define osdValidCtx_CallTrustedFunction      (  osdCtxTask           | osdCtxISRCat2        )
#define osdValidCtx_CallNonTrustedFunction   (  osdCtxTask           | osdCtxISRCat2        )
#define osdValidCtx_StartScheduleTableRel    (  osdCtxTask           | osdCtxISRCat2        )
#define osdValidCtx_StartScheduleTableAbs    (  osdCtxTask           | osdCtxISRCat2        )
#define osdValidCtx_StopScheduleTable        (  osdCtxTask           | osdCtxISRCat2        )
#define osdValidCtx_NextScheduleTable        (  osdCtxTask           | osdCtxISRCat2        )
#define osdValidCtx_SyncScheduleTable        (  osdCtxTask           | osdCtxISRCat2        )
#define osdValidCtx_GetScheduleTableStatus   (  osdCtxTask           | osdCtxISRCat2        )
#define osdValidCtx_SetScheduleTableAsync    (  osdCtxTask           | osdCtxISRCat2        )
#define osdValidCtx_IncrementCounter         (  osdCtxTask           | osdCtxISRCat2        )
#define osdValidCtx_TerminateTask            (  osdCtxTask                                  )
#define osdValidCtx_ChainTask                (  osdCtxTask                                  )
#define osdValidCtx_Schedule                 (  osdCtxTask                                  )
#define osdValidCtx_ClearEvent               (  osdCtxTask                                  )
#define osdValidCtx_WaitEvent                (  osdCtxTask                                  )
#define osdValidCtx_GetTaskID                (  osdCtxTask           | osdCtxISRCat2            \
                                              | osdCtxEachErrorHook  | osdCtxPreTaskHook        \
                                              | osdCtxPostTaskHook   | osdCtxProtectionHook )
#define osdValidCtx_GetTaskState             (  osdCtxTask           | osdCtxISRCat2            \
                                              | osdCtxEachErrorHook  | osdCtxPreTaskHook        \
                                              | osdCtxPostTaskHook                          )
#define osdValidCtx_GetEvent                 (  osdCtxTask           | osdCtxISRCat2            \
                                              | osdCtxEachErrorHook  | osdCtxPreTaskHook        \
                                              | osdCtxPostTaskHook                          )
#define osdValidCtx_GetAlarmBase             (  osdCtxTask           | osdCtxISRCat2            \
                                              | osdCtxEachErrorHook  | osdCtxPreTaskHook        \
                                              | osdCtxPostTaskHook                          )
#define osdValidCtx_GetAlarm                 (  osdCtxTask           | osdCtxISRCat2            \
                                              | osdCtxEachErrorHook  | osdCtxPreTaskHook        \
                                              | osdCtxPostTaskHook                          )   
#define osdValidCtx_GetActiveApplicationMode (  osdCtxTask           | osdCtxISRCat2            \
                                              | osdCtxEachErrorHook  | osdCtxPreTaskHook        \
                                              | osdCtxPostTaskHook   | osdCtxStartupHook        \
                                              | osdCtxShutdownHook                          )
#define osdValidCtx_ShutdownOS               (  osdCtxTask           | osdCtxISRCat2            \
                                              | osdCtxEachErrorHook  | osdCtxStartupHook    )
#define osdValidCtx_GetISRID                 (  osdCtxTask           | osdCtxISRCat2            \
                                              | osdCtxEachErrorHook  | osdCtxProtectionHook )
#define osdValidCtx_CheckISRMemoryAccess     (  osdCtxTask           | osdCtxISRCat2            \
                                              | osdCtxEachErrorHook  | osdCtxProtectionHook )
#define osdValidCtx_CheckTaskMemoryAccess    (  osdCtxTask           | osdCtxISRCat2            \
                                              | osdCtxEachErrorHook  | osdCtxProtectionHook )
#define osdValidCtx_CheckObjectAccess        (  osdCtxTask           | osdCtxISRCat2            \
                                              | osdCtxEachErrorHook  | osdCtxProtectionHook )
#define osdValidCtx_CheckObjectOwnership     (  osdCtxTask           | osdCtxISRCat2            \
                                              | osdCtxEachErrorHook  | osdCtxProtectionHook )
#define osdValidCtx_TerminateApplication     (  osdCtxTask           | osdCtxISRCat2            \
                                              | osdCtxApplErrorHook                         )
#define osdValidCtx_StartScheduleTableSynchron (  osdCtxTask           | osdCtxISRCat2      )

#define osdValidCtx_GetApplicationState      (  osdCtxTask           | osdCtxISRCat2            \
                                              | osdCtxPreTaskHook    | osdCtxPostTaskHook       \
                                              | osdCtxEachErrorHook  | osdCtxProtectionHook     \
                                              | osdCtxStartupHook    | osdCtxShutdownHook   )

#define osdValidCtx_GetCounterValue          (  osdCtxTask           | osdCtxISRCat2        )
#define osdValidCtx_GetElapsedValue          (  osdCtxTask           | osdCtxISRCat2        )



/* 
   Remarks:  
   - No checks for interrupt enable/disable functions because these functions
     can be called inside Cat1 ISRs (which can occur inside each context)
   - No context mask for StartOS, because StartOS is only allowed outside
     the defined call contexts
*/
/* KB end osekContextConstants */

/* implementation specific constants */
/* KB begin osekConstants (overwritten) */
#define osSysGetCoreID() 0

#define osdPrioBitsPerWord 32
/* KB end osekConstants */



/* KB begin osekTickTypeDef (default) */
typedef osuint32             TickType;
typedef osint32              osTickTimeDiffType;
/* KB end osekTickTypeDef */

/* KB begin osekAditionalTypeDef (default) */

    
/* implementation specific types (OSEK types) */
/* KB begin osekTypes (overwritten) */
/*
    !!! Max priorities: Min(2^(sizeof(osPrioType)*8), 2^(sizeof(osPrioOffsetType)*8) * sizeof(osPrioFlagType)*8)

*/
typedef osuint32       osPrioType;         /* has to be unsigned (invalid is higher than others) */
typedef osuint8        osPrioOffsetType;
typedef osuint32       osPrioFlagType;
typedef osuint32       osResAccessMaskType;

typedef osuint32       osStartFlagType;
typedef osuint8        osContextOverlayType;
typedef osuint8        osTaskPreemptionType;
typedef osuint8        osTaskFlagType;
typedef osuint8        osQEntryCountType;
typedef osuint8        osActivationCountType;
typedef osuint32       osTaskIndexType;
typedef osuint16       osResourceIndexType;
typedef osuint32       osAlarmIndexType;

typedef osuint8        osIntLevelType;
typedef osuint32       osIntGlobalType;
typedef osAlarmIndexType     AlarmType;
typedef osAlarmIndexType     *osAlarmIndexRefType;
typedef AlarmType      osTIPType;
typedef osuint32       osStdFlagType;

typedef osuint32       osStackDataType;
typedef osuint32       osStackSizeType;
typedef osuint32       osStackPatternType;

typedef osuint8        osIntGlobalFlagType;
/* KB end osekTypes */

/* Autosar types */
/* KB begin atosTypes (overwritten) */
typedef osuint32                 osProcessType;
typedef osuint32                 ISRType;              /* TR:SASR30:0360 */
typedef osuint16                 ScheduleTableType;    /* TR:SASR30:0344 *//* TR:SASR30:0345 *//* TR:SASR30:0361 */
typedef osuint8                  ScheduleTableStatusType;                  /* TR:SASR30:0362 */
typedef ScheduleTableStatusType* ScheduleTableStatusRefType;               /* TR:SASR30:0363 */
typedef osuint8                  RestartType;          /* TR:SASR30:0366 */
typedef osuint16                 CounterType;          /* TR:SPMF81:0003 *//* TR:SASR30:0347 *//* TR:SASR30:0364 */
typedef osuint8                  ProtectionReturnType; /* TR:SASR30:0365 */
typedef osuint16                 TrustedFunctionIndexType;                 /* TR:SASR30:0353 */
typedef void*                    TrustedFunctionParameterRefType;          /* TR:SASR30:0354 */
typedef void (*TrustedFunctionType)(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
typedef osuint16                 NonTrustedFunctionIndexType;
typedef void*                    NonTrustedFunctionParameterRefType;
typedef void (*NonTrustedFunctionType)(NonTrustedFunctionIndexType FunctionIndex, NonTrustedFunctionParameterRefType FunctionParams);
typedef osuint8                  AccessType;              /* TR:SASR30:0355 */
typedef osuint32                 ApplAccessMaskType;
typedef osuint8                  ObjectAccessType;        /* TR:SASR30:0356 */
typedef osuint8                  ObjectTypeType;          /* TR:SASR30:0357 */
typedef osuint16                 ObjectIDType;
typedef osuint8*                 MemoryAddressType;
typedef void*                    MemoryStartAddressType;  /* TR:SASR30:0358 */
typedef osuint32                 MemorySizeType;          /* TR:SASR30:0359 */
typedef osuint32                 PhysicalTimeType;


/* This is included into the generator source where the type unsigned long long or prefices like ULL are not yet known */
#if (defined _MSC_VER)
#define osdMaxExeTimeValue               0x1FFFffffFFFFffff
#define osdMaxBlockTimeValue             0x1FFFffffFFFFffff
#define osdMaxAllowedTimeStamp           0x7FFFffffFFFFffff
typedef unsigned __int64                 osTPTimeStampType;
typedef __int64                          osTPTimeType;
#else
#define osdMaxExeTimeValue               0x1FFFffffFFFFffffLL
#define osdMaxBlockTimeValue             0x1FFFffffFFFFffffLL
#define osdMaxAllowedTimeStamp           0x7FFFffffFFFFffffULL
typedef unsigned long long               osTPTimeStampType;
typedef long long                        osTPTimeType;
typedef osTPTimeStampType*               osTPTimeStampRefType;
typedef osTPTimeType*                    osTPTimeRefType;
#endif

typedef osuint16                     SpinlockIdType;
typedef osuint8                      TryToGetSpinlockType;
typedef osuint32                     CoreIdType;
typedef osuint32                     osMiniLockType;
typedef double                       osTimeComputationType;/* used in macros for conversion between time and ticks to avoid usage of basic type */


#if ((osdSC== SC3) || (osdSC== SC4))
typedef void (*osAPIFuncType)();  /* PRQA S 1303 */
typedef osuint16 osAPIType; 
#endif

/* KB end atosTypes */

/* KB begin applicationTypeDef (overwritten) */
typedef osuint8                          ApplicationType;
/* KB end applicationTypeDef */

/* KB begin osekOSEKTypes (overwritten) */
typedef osTaskIndexType      TaskType;
typedef osResourceIndexType  ResourceType;
typedef void                (*osIsrFctType)(void);
/* KB end osekOSEKTypes */
/* KB begin osekDispatcherLockType (default) */
typedef osuint8               osDispatcherLockType;
/* KB end osekDispatcherLockType */

#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
typedef osuint8               StatusType;
#define E_OK 0
#endif

typedef osuint8              TaskStateType;
typedef osuint8              AppModeType;
typedef TaskType            *TaskRefType;
typedef TaskStateType       *TaskStateRefType;
typedef TickType            *TickRefType;
typedef osuint32             EventMaskType;
typedef EventMaskType       *EventMaskRefType;
typedef ISRType             *ISRRefType;

/* Schedule Table related */
typedef TickType osSTOffsetType;
typedef TickType GlobalTimeTickType;
typedef osuint16 osSTIndexType;

typedef osuint8               ApplicationStateType;    /* TR:SASR40:6010 */
typedef ApplicationStateType *ApplicationStateRefType; /* TR:SASR40:6012 */

typedef struct {
   void* start;
   void* end;
   osuint32 applAccessRights;
} osPeripheralRegionType;

typedef struct {
   TrustedFunctionType start;
   ApplicationType ownerApplication;
} osTrustedFunctionType;

typedef struct {
   NonTrustedFunctionType start;
   ApplicationType ownerApplication;
} osNonTrustedFunctionType;

/* KB end osekAditionalTypeDef */

/* KB begin osekDefaultTypes (default) */
/* KB begin osekHWosTaskFctType (default) */
typedef void                (*osTaskFctType)(void);
/* KB end osekHWosTaskFctType */

typedef osuint16              osStackUsageType;
typedef osuint8               osTaskStateType;
/* KB begin osekHWosStackPtrType (overwritten) */
typedef struct {
   osuint32 osMPURIndex;
   void*    osMPURStart;
   osuint32 osMPURRights;
   osuint32 osMPURSize;
} osMPURegionType;

typedef osStackDataType*        osStackPtrType;
typedef osStackDataType const * osStackPtrToConstType;

typedef struct {
   osStackPtrType start;
   osStackPtrType end;
#if ((osdSC== SC3) || (osdSC== SC4))
   osuint32       osMPURSize;
#endif /* ((osdSC== SC3) || (osdSC== SC4)) */
} osStackType;
/* KB end osekHWosStackPtrType */
typedef osuint8               osResCounterType;
/* KB end osekDefaultTypes */

/* possible values of ObjectTypeType */
#define OBJECT_TASK 0
#define OBJECT_ISR 1
#define OBJECT_ALARM 2
#define OBJECT_RESOURCE 3
#define OBJECT_COUNTER 4
#define OBJECT_SCHEDULETABLE 5
#define osdNumberOfObjectTypes 6


/* KB begin osekHWosStartupHookType (default) */
typedef void                (*osStartupHookType)(void);
/* KB end osekHWosStartupHookType */
/* KB begin osekHWosShutdownHookType (default) */
typedef void                (*osShutdownHookType)(StatusType Error);
/* KB end osekHWosShutdownHookType */
/* KB begin osekHWosErrorHookType (default) */
typedef void                (*osErrorHookType)(StatusType Error);
/* KB end osekHWosErrorHookType */

/* KB begin osekOSEKdeclarations (default) */
#define DeclareTask(TaskId)     osqRAM0 extern osqRAM1 osqRAM2 TaskType osqRAM3 osNotUsed1##TaskId
#define DeclareResource(ResId)  osqRAM0 extern osqRAM1 osqRAM2 TaskType osqRAM3 osNotUsed2##ResId
#define DeclareEvent(Event)     osqRAM0 extern osqRAM1 osqRAM2 TaskType osqRAM3 osNotUsed3##Event
#define DeclareAlarm(AlarmId)   osqRAM0 extern osqRAM1 osqRAM2 TaskType osqRAM3 osNotUsed4##AlarmId
/* KB end osekOSEKdeclarations */    /* DeclareTask, DeclareAlarm,... */

/* structure for AlarmBase */
typedef struct
{
   TickType maxallowedvalue;/* Maximum possible allowed count value (for example */
                            /* in ticks or angle degrees) */
   TickType ticksperbase;   /* Number of ticks required to reach a counter-specific */
                            /* (significant) unit. */
   TickType mincycle;       /* Minimum allowed number of ticks for a cyclic alarm */
                            /* (only for systems with Extended Status). */
} AlarmBaseType;

typedef AlarmBaseType     *AlarmBaseRefType;

typedef osTIPType         osHeapElementType;
typedef osHeapElementType *osHeapElementRefType;
typedef struct
{
   osHeapElementRefType heap;
   osAlarmIndexRefType  count;
} osHeapType;
typedef osHeapType const * osHeapRefType;

typedef osuint16          OSServiceIdType;
typedef void              (*osAlarmCallbackType)(void);
typedef osuint8           BlockTypeType;





#if (osdClearTIPAbsIdx != -1)
 osqFunc1 void osqFunc2 osClearTimerInterruptPointAbs(CounterType CounterID);
#endif
#if (osdClearTIPRelIdx != -1)
 osqFunc1 void osqFunc2 osClearTimerInterruptPointRel(CounterType CounterID);
#endif
#if (osdSetTIPAbsMaxGtSemiCountIdx != -1)
 osqFunc1 osbool osqFunc2 osSetTIPAbsMaxGtSemiCount(CounterType CounterID, TickType timeToSet);
#endif
#if (osdSetTIPRelMaxGtSemiCountIdx != -1)
 osqFunc1 osbool osqFunc2 osSetTIPRelMaxGtSemiCount(CounterType CounterID, TickType timeToSet);
#endif
#if (osdSetTIPAbsMaxLeSemiCountIdx != -1)
 osqFunc1 osbool osqFunc2 osSetTIPAbsMaxLeSemiCount(CounterType CounterID, TickType timeToSet);
#endif
#if (osdSetTIPRelMaxLeSemiCountIdx != -1)
 osqFunc1 osbool osqFunc2 osSetTIPRelMaxLeSemiCount(CounterType CounterID, TickType timeToSet);
#endif
#if (osdGetCurrentTimeHighResHybridIdx != -1)
 osqFunc1 TickType osqFunc2 osGetCurrentTimeHiResHybrid(CounterType CounterID);
#endif
#if (osdGetCurrentTimeHighResMonoIdx != -1)
 osqFunc1 TickType osqFunc2 osGetCurrentTimeHiResMono(CounterType CounterID);
#endif
#if (osdGetCurrentTimeStdIdx != -1)
 osqFunc1 TickType osqFunc2 osGetCurrentTimeStd(CounterType CounterID);
#endif
#if (osdHandleCounterInterruptStdIdx != -1)
 osqFunc1 void osqFunc2 osHandleCounterInterruptStd(CounterType CounterID);
#endif
#if (osdHandleCounterInterruptHiResIdx != -1)
 osqFunc1 void osqFunc2 osHandleCounterInterruptHiRes(CounterType CounterID);
#endif

#define osdCounterId2HiResCounterId(x)    ((x) -  osdNumberOfSWAndSRCounters)
#define osdIsHiResCounter(x)              ((osdNumberOfSWAndSRCounters == 0) || ((x) >= osdNumberOfSWAndSRCounters))
#define osdCounterId2HwCounterId(x)       ((x) -  osdNumberOfSWCounters)
#define osdIsHwCounter(x)                 ((x) >= osdNumberOfSWCounters)

typedef void (*osClearTimerInterruptPointOpType)(CounterType);
typedef osbool (*osSetTimerInterruptPointOpType)(CounterType, TickType);
typedef TickType (*osGetCurrentTimeOpType)(CounterType);
typedef void (*osHandleCounterInterruptsOpType)(CounterType);
typedef osqFunc1 void osqFunc2 (*osInsertMinHeapOpType)(osHeapElementType newItem, osHeapType const * const h, CounterType ctr);


typedef TickType  osHWTimerCompType;


typedef union
{
   TaskType          osTaskType;
   TaskRefType       osTaskRefType;
   ResourceType      osResourceType;
   EventMaskType     osEventMaskType;
   osTIPType         osAlarmType;
   CounterType       osCounterType;
   ScheduleTableType osScheduleTableType;
   ISRType           osISRType;
   TrustedFunctionIndexType osFunctionIndexType;
   ApplicationType   osApplicationType;
} osAPIParam1Type;

typedef union
{
   TaskStateRefType           osTaskStateRefType;
   EventMaskType              osEventMaskType;
   EventMaskRefType           osEventMaskRefType;
   AlarmBaseRefType           osAlarmBaseRefType;
   TickType                   osTickType;
   TickRefType                osTickRefType;
   ScheduleTableType          osScheduleTableType;
   ScheduleTableStatusRefType osScheduleTableStatusRefType;
   ApplicationStateRefType    osApplicationStateRefType;
   RestartType       osRestartType;
   TrustedFunctionParameterRefType osTrustedFunctionParameterRefType;
   BlockTypeType              osBlockType;
} osAPIParam2Type;

typedef union
{
   TickType     osTickType;
   ResourceType osResourceType;
   TickRefType  osTickRefType;
} osAPIParam3Type;



/* KB begin osHWCtrlVarStruct (overwritten) */

typedef struct
{
   TaskType   ossHighReadyTaskIndex; /* ready task with highest priority */
   osPrioType ossHighReadyTaskPrio;  /* Priority of ready task with highest priority */
   osbool ossStartDispatcher;
      osQEntryCountType ossQReadyTaskHead[osdNumberOfPriorities];
      osQEntryCountType ossQReadyTaskTail[osdNumberOfPriorities];
   osPrioFlagType ossQReadyPrios[osdRTSize];
}osCtrlVarsLockNeededType;

typedef struct
{
   /* KB begin osekHwSctxCtrlVarsCandidates (overwritten) */
   osuint8 ossIntNestingDepth;
   TaskType ossActiveTaskIndex;    /* indicates the currently running task */
   ISRType ossActiveISRID;     /* Id of the currently running (cat2) ISR */
   osuint8 ossIntSaveDisableCounter;
   volatile osuint8 ossIntAPIStatus;
   ApplicationType ossActiveApplicationID;
   
   /* KB begin osekHwAdditionalSctxCtrlVarsCandidates (overwritten) */
   /* KB end osekHwAdditionalSctxCtrlVarsCandidates */
   /* KB end osekHwSctxCtrlVarsCandidates */
   
   osPrioType ossActiveTaskPrio;     /* Priority of actually active task */
   osbool ossStarted;
  
   /* KB begin osCtrlVarStructVariablesForGlobalDisable (overwritten) */
   osIntGlobalType ossSavedIntNested;
   osIntGlobalType ossSavedIntGlobal;
   
   #if (osdSC== SC3) || (osdSC== SC4)
   osuint32* osHookStackRestore;
   osuint32* osErrorHookStackRestore;
   #endif
   /* KB end osCtrlVarStructVariablesForGlobalDisable */

   volatile osDispatcherLockType ossLockDispatcher;
#if osdExceptionDetails
   osint16 ossUnhandledExceptionDetail;
#endif
   osuint16 ossCurrentContext;

   osResCounterType ossResGlobalOccupationCounter;

   TaskType ossLastActiveTaskIndex;

   volatile osuint8 ossORTICurrentServiceId;

      StatusType ossLastErrorCode;
   volatile osuint16 ossLastError;
   osbool ossErrorFlag;
   /* KB begin osCtrlVarsNoLockNeededAdditionalHWVariables (overwritten) */
   #if (osdSC== SC3) || (osdSC== SC4)
   #if ( (STATUS_LEVEL == EXTENDED_STATUS) && (osdEnableAssertions==1) )
   osuint32 ossMemoryProtectionFaultIndicator;
   osuint32 ossMemoryProtectionFaultAddress;
   #endif
   #endif
   /* KB end osCtrlVarsNoLockNeededAdditionalHWVariables */
}osCtrlVarsNoLockNeededType;

typedef struct
{ 
   volatile osCtrlVarsLockNeededType    LockIsNeeded;
   osCtrlVarsNoLockNeededType  LockIsNotNeeded;
} osCtrlVarType;

#define ptrToCcb (&osOwnCcb->LockIsNeeded)
/* KB end osHWCtrlVarStruct */

/* KB begin osOwnCcbDefine (overwritten) */
#define osOwnCcb (&osCtrlVarsCore0)
/* KB end osOwnCcbDefine */

/* KB begin osekHWConfigBlock (default) */
typedef struct {

   /* Frame */
   osuint8  aucMagicNumber[4];   /* 130 42 12 196  = 0x82 2A 0C C4 */
   osuint16 uiLength;
   osuint16 uiHardwareID;        /* Hardware Identification */
   osuint8  ucMajorVersion;
   osuint8  ucMinorVersion;
   osuint16 uiConfigVersion;     /* Version number of configuration block format*/
   osuint16 uiUserConfigVersion; /* Version number of configuration assigned by user*/

   /* cargo --------------------------------------------------------------- */

   /* start address of config block */
   const void*                      uiStartAddressConfigBlock;
   /* start addresses of sub-containers (fixed number) */
   const void*                      uiStartAddressSubCont0;                /* Sub-container 0 */
   const osTaskFctType*             uiStartAddressTaskStartAddress;        /* Sub-container 1 */
   const osuint8*                   uiStartAddressTaskPreemptive;          /* Sub-container 2 */
   const osuint8*                   uiStartAddressTaskTrusted;             /* Sub-container 3 */
   const osStackPtrType*            uiStartAddressTaskStackStartAddress;   /* Sub-container 4 */
   const osStackPtrType*            uiStartAddressTaskStackEndAddress;     /* Sub-container 5 */
   const osuint8*                   uiStartAddressTaskToAppl;              /* Sub-container 6 */
   const osuint8*                   uiStartAddressIsrTrusted;              /* Sub-container 7 */
   const osuint8*                   uiStartAddressIsrToAppl;               /* Sub-container 8 */
   const osuint8*                   StartAddressApplTrusted;               /* Sub-container 9 */
   const osTrustedFunctionType*     StartAddressTrustedFunctions;          /* Sub-container 10 */
   const osNonTrustedFunctionType*  StartAddressNonTrustedFunctions;       /* Sub-container 11 */
   const osIsrFctType*              StartAddresscat2IsrStartAddress;       /* Sub-container 12 */
   const osuint8*                   StartAddressIsrNestable;               /* Sub-container 13 */
   const CoreIdType*                StartAddressProcessToCore;             /* Sub-container 14 */
   const CoreIdType*                StartAddressAlarmToCore;               /* Sub-container 15 */
   const CoreIdType*                StartAddressResourceToCore;            /* Sub-container 16 */
   const CoreIdType*                StartAddressCounterToCore;             /* Sub-container 17 */
   const CoreIdType*                StartAddressScheduleTableToCore;       /* Sub-container 18 */
   const CoreIdType*                StartAddressApplicationToCore;         /* Sub-container 19 */
   const CoreIdType*                StartAddressTrustedFunctionToCore;     /* Sub-container 20 */
   const CoreIdType*                StartAddressNonTrustedFunctionToCore;  /* Sub-container 21 */
   osCtrlVarType* const *           StartAddressCcbAddress;                /* Sub-container 22 */
   const osPeripheralRegionType*    StartAddressPeripheralRegions;         /* Sub-container 23 */
   const osuint8*                   StartAddressSpinlockLockMethods;       /* Sub-container 24 */
   const osuint8*                   StartAddressSpinlockLockTypes;         /* Sub-container 25 */
   osMiniLockType*const*            StartAddressOptimizedSpinlockVars;     /* Sub-container 26 */


/* KB begin osekHWConfigBlockStartAddrSpecific (overwritten) */
#if ((osdSC== SC3) || (osdSC== SC4))
   const osStackType* const *       StartAddressCat2IsrStacksPointers;     /* Sub-container 24 */
   const osStackType*               StartAddressCat2IsrStacks;             /* Sub-container 25 */
#endif /* ((osdSC== SC3) || (osdSC== SC4)) */
   const osStackType*               StartAddressSystemStacks;              /* Sub-container 26 */
   const osStackType*               StartAddressIRQCat1Stacks;             /* Sub-container 27 */
   const osStackType*               StartAddressFIQStacks;                 /* Sub-container 28 */
#if ((osdSC== SC3) || (osdSC== SC4))
   const osuint32*                  StartAddressTaskStackMPURSize;         /* Sub-Container 29 */
   const osMPURegionType*           StartAddressglobalMPURegions;          /* Sub-Container 30 */
   const osMPURegionType* const *   StartAddressapplMPURegionPointer;      /* Sub-Container 31 */
   const osMPURegionType*           StartAddressapplMPURegions;            /* Sub-Container 32 */
#endif /* ((osdSC== SC3) || (osdSC== SC4)) */
/* KB end osekHWConfigBlockStartAddrSpecific */  

   /* Sub-Container 0 */
   osuint16 uiNumberOfTasks;               /* = osdNumberOfAllTasks            */
   osuint16 uiNumberOfCat2ISRs;            /* = osdNumberOfCat2ISRs            */
   osuint16 uiNumberOfTrustedFunctions;    /* = osdNumberOfTrustedFunctions    */
   osuint16 uiNumberOfNonTrustedFunctions; /* = osdNumberOfNonTrustedFunctions */
   osuint16 uiNumberOfApplications;        /* = osdNumberOfApplications        */
   osuint16 uiNumberOfPeripheralRegions;   /* = osdNumberOfPeripheralRegions   */
   osuint8  ucStackUsageMeasurement;       /* = osdStackUsageMeasurement       */
   osuint16 NumberOfAlarms;                /* = osdNumberOfAlarms              */
   osuint16 NumberOfAllResources;          /* = osdNumberOfAllResources        */
   osuint16 NumberOfAvailableCores;        /* = osdNumberOfAvailableCores      */
   osuint16 NumberOfCounters;              /* = osdNumberOfCounters            */
   osuint16 NumberOfProcesses;             /* = osdNumberOfProcesses           */
   osuint16 NumberOfScheduleTables;        /* = osdNumberOfScheduleTables      */
   osuint16 NumberOfSpinlocks;             /* = osdNumberOfSpinlocks           */

   /* KB begin osekHWConfigBlockSubCont0Specific (overwritten) */
   osuint8  ucNumberOfGlobalMPURegions;    /* = osdNumberOfGlobalMPURegions    */
   osuint8  ucNumberOfApplMPURegions;      /* = osdNumberOfApplMPURegions      */
   /* KB end osekHWConfigBlockSubCont0Specific */ 

   /* Sub-Container 1 */
   osTaskFctType              aulTaskStartAddress[osdNumberOfAllTasks+1];
   /* Sub-Container 2 */
   osuint8                    aucTaskPreemptive[osdNumberOfAllTasks+1];
   /* Sub-Container 3 */
   osuint8                    aucTaskTrusted[osdNumberOfAllTasks+1];
   /* Sub-Container 4 */
   osStackPtrType             aulTaskStackStartAddress[osdNumberOfAllTasks+1]; /* TR:SPMF07:0003 */
   /* Sub-Container 5 */
   const osStackPtrType       aulTaskStackEndAddress[osdNumberOfAllTasks+1]; /* TR:SPMF08:0004 */
   /* Sub-Container 6 */
   osuint8                    acTaskToAppl[osdNumberOfAllTasks+1]; 
   /* Sub-Container 7 */
   osuint8                    aucIsrTrusted[osdNumberOfCat2ISRs+1];
   /* Sub-Container 8 */
   osuint8                    acIsrToAppl[osdNumberOfCat2ISRs+1];
   /* Sub-Container 9 */
   osuint8                    applTrusted[osdNumberOfApplications+1];
   /* Sub-Container 10 */
   osTrustedFunctionType      trustedFunctions[osdNumberOfTrustedFunctions+1];
   /* Sub-Container 11 */
   osNonTrustedFunctionType   nonTrustedFunctions[osdNumberOfNonTrustedFunctions+1];
   /* Sub-Container 12 */
   osIsrFctType               cat2IsrStartAddress[osdNumberOfCat2ISRs+1];
   /* Sub-Container 13 */
   osuint8                    IsrNestable[osdNumberOfCat2ISRs+1];
   /* Sub-Container 14 */
   CoreIdType                 ProcessToCore[osdNumberOfProcesses+1];
   /* Sub-Container 15 */
   CoreIdType                 AlarmToCore[osdNumberOfAlarms+1];
   /* Sub-Container 16 */
   CoreIdType                 ResourceToCore[osdNumberOfAllResources+1];
   /* Sub-Container 17 */
   CoreIdType                 CounterToCore[osdNumberOfCounters+1];
   /* Sub-Container 18 */
   CoreIdType                 ScheduleTableToCore[osdNumberOfScheduleTables+1];
   /* Sub-Container 19 */
   CoreIdType                 ApplicationToCore[osdNumberOfApplications+1];
   /* Sub-Container 20 */
   CoreIdType                 TrustedFunctionToCore[osdNumberOfTrustedFunctions+1];
   /* Sub-Container 21 */
   CoreIdType                 NonTrustedFunctionToCore[osdNumberOfNonTrustedFunctions+1];
   /* Sub-Container 22 */
   osCtrlVarType* const       CcbAddress[osdNumberOfAvailableCores+1];
   /* Sub-Container 23 */
   osPeripheralRegionType     peripheralRegions[osdNumberOfPeripheralRegions+1];
   /* Sub-Container 24 */
   osuint8                    SpinlockLockMethods[1];
   /* Sub-Container 25 */
   osuint8                    SpinlockLockTypes[1];
   /* Sub-Container 26 */
   osMiniLockType*            OptimizedSpinlockVars[1];



/* KB begin osekHWConfigBlockSubContainersSpecific (overwritten) */
#if ((osdSC== SC3) || (osdSC== SC4))
   /* Sub-Container 24 */
   const osStackType *cat2IsrStacksPointers[osdNumberOfCat2ISRs+1];
   /* Sub-Container 25 */
   osStackType     cat2IsrStacks[osdNumberOfCat2ISRs+1];
#endif /* ((osdSC== SC3) || (osdSC== SC4)) */
   /* Sub-Container 26 */
   osStackType     SystemStacks[osdNumberOfAvailableCores];
   /* Sub-Container 27 */
   osStackType     IRQCat1Stacks[osdNumberOfAvailableCores];
   /* Sub-Container 28 */
   osStackType     FIQStacks[osdNumberOfAvailableCores];
#if ((osdSC== SC3) || (osdSC== SC4))
   /* Sub-Container 29 */
   osuint32        TaskStackMPURSize[osdNumberOfAllTasks+1];
   /* Sub-Container 30 */
   osMPURegionType globalMPURegions[osdNumberOfAvailableCores][osdNumberOfGlobalMPURegions+1];
   /* Sub-Container 31 */
   const osMPURegionType *applMPURegionPointer[osdNumberOfApplications];
   /* Sub-Container 32 */
   osMPURegionType applMPURegions[osdNumberOfApplications][osdNumberOfApplMPURegions+1];
#endif /* ((osdSC== SC3) || (osdSC== SC4)) */
/* KB end osekHWConfigBlockSubContainersSpecific */

   /* Frame End ---------------------------------------------------------- */
   osuint32 uiCheckSum;

} tsConfigBlock;
/* KB end osekHWConfigBlock */
/* KB begin osekHWexternConfigBlock (default) */
/* MISRA RULE 8.8 not violated: the external declaration is defined more than once in the vector testsuite.
                                it is declared only once in the OS code
 */ 
extern const tsConfigBlock osConfigBlock; /* PRQA S 3451 */ 
/* KB end osekHWexternConfigBlock */

/* Parameter values for MICROSAR OS Timing Hooks */
#define OS_VTHP_TASK_TERMINATION 0x01
#define OS_VTHP_ISR_END          0x02
#define OS_VTHP_TASK_WAITEVENT   0x04
#define OS_VTHP_TASK_WAITSEMA    0x08
#define OS_VTHP_THREAD_PREEMPT   0x10
#define OS_VTHP_TASK_ACTIVATION  0x21
#define OS_VTHP_ISR_START        0x22
#define OS_VTHP_TASK_SETEVENT    0x24
#define OS_VTHP_TASK_GOTSEMA     0x28
#define OS_VTHP_THREAD_RESUME    0x30

/* Bit to be set in order to change a 'from thread reason' into a 'to thread reason' */
#define OS_VTHP_MODIFY_FROM_TO_REASON 0x20

#define OS_VTHP_CAT2INTERRUPTS 1
#define OS_VTHP_ALLINTERRUPTS 2

#ifndef osdCallTimingHooks
#error "The generator has not defined osdCallTimingHooks (should always be defined)"
#endif

#if osdCallTimingHooks
#include osdTimingHooksFileName
osqRAM0 extern osqRAM1 osqRAM2 osuint8 osqRAM3  osNextRunReason[osdNumberOfAllTasks];
#endif

/*
 *  MICROSAR OS timing hooks call macros, used by interrupt API functions and macros
 *  (may be expanded into the application)
 */
/* CovComment 4:  Macro: OS_VTH_CALL_DISABLEDINT_HOOK */
#if osdCallTimingHooks
#define OS_VTH_CALL_DISABLEDINT_HOOK(IntLockId)                         \
   COVER(0x0000)                                                              \
   OS_VTH_DISABLEDINT((IntLockId), 0)
#else
#define OS_VTH_CALL_DISABLEDINT_HOOK(IntLockId)                         \
   COVER(0x0001)
#endif

/* CovComment 4:  Macro: OS_VTH_CALL_ENABLEDINT_HOOK */
#if osdCallTimingHooks
#define OS_VTH_CALL_ENABLEDINT_HOOK(IntLockId)                          \
   COVER(0x0002)                                                              \
   OS_VTH_ENABLEDINT((IntLockId), 0)
#else
#define OS_VTH_CALL_ENABLEDINT_HOOK(IntLockId)                          \
   COVER(0x0003)
#endif

 #define osdTestMacros 1

#ifndef osdTestMacros
 #if defined USE_QUOTE_INCLUDES
  #include "emptymac.h"
 #else
  #include <emptymac.h>
 #endif
#else                           
 #if (osdTestMacros == 1)
  #if defined USE_QUOTE_INCLUDES
   #include "testmac1.h"
  #else
   #include <testmac1.h>
  #endif
 #endif
 #if (osdTestMacros == 3)
  #if defined USE_QUOTE_INCLUDES
   #include "testmac3.h"
  #else
   #include <testmac3.h>
  #endif
 #endif
 #if (osdTestMacros == 4)
  #if defined USE_QUOTE_INCLUDES
   #include "testmac4.h"
  #else
   #include <testmac4.h>
  #endif
 #endif
#endif /*osdTestMacros*/

/* KB begin osekHWVariableSectionStartHeader (default) */
/* KB end osekHWVariableSectionStartHeader */

/* KB begin osekHWDefineNegateTick (default) */
/* KB end osekHWDefineNegateTick */

/* KB begin osekHWDefineDummyRead (default) */
#define osdDummyRead(x) ((x) = (x));         /* to avoid compiler warning */
/* KB end osekHWDefineDummyRead */

osqRAM0 extern osqRAM1 volatile osqRAM2 AppModeType osqRAM3 osActiveAppMode;


/* KB begin osekHWVariableSectionEndHeader (default) */
/* KB end osekHWVariableSectionEndHeader */

/* KB begin osekOsAbortSystemPrototype (default) */
osqFunc1 void osqFunc2 osAbortSystem(osuint16 uiError);
/* KB end osekOsAbortSystemPrototype */
/* KB begin osekOsUnrecoverableErrorPrototype (default) */
osqFunc1 void osqFunc2 osUnrecoverableError(StatusType StdErrorCode, osuint16 osOsekErrorCode);
/* KB end osekOsUnrecoverableErrorPrototype */

/* necessary for task/ISR-kill and to handle a missing TerminateTask in SC3/4 */
  osqFunc1 void osqFunc2 osSysKillResourceList(ResourceType ResId);



/* KB begin osekHwDeclareApiWrapperPrototypes (default) */

#define osdApiCall(ParamApiCall) osPsys##ParamApiCall
/* MISRA RULE 19.10 VIOLATION: (4 times) The macros osdParamsX are only used build function declarations and definitions 
 * within further macros. The parameters may be formal parameters of a function consisting of type and name where 
 * parentheses could not be used. (3410) */
#define osdParams1(a) a                      /* PRQA S 3410 */
#define osdParams2(a, b) a, b               /* PRQA S 3410 */
#define osdParams3(a, b, c) a, b, c        /* PRQA S 3410 */
#define osdParams4(a, b, c, d) a, b, c, d /* PRQA S 3410 */

/* MISRA RULE 19.10 VIOLATION: The macro osdDeclareApiWrappers uses macro parameters 
 * outside of '(' and ')'. This is unavoidable as it uses the parameters as return type 
 * in a function definition (3410) */
#define osdDeclareApiWrappers(RetType, ApiName, FormalParams)  \
   osqFunc1 RetType osqFunc2 osPsys##ApiName(FormalParams);/* PRQA S 3410 */

/* KB end osekHwDeclareApiWrapperPrototypes */

/* fullfills [SR:001] of $\AutosarOS\general\Generation5\_doc\12_SystemRequirements\RequirementsSpec_MicrosarOS.doc */
/* OSEK-Prototypes */
/* system services */

/* QAC-message below can be accepted as osdApiCall uses the parameter just with token merging (##) (3443) (6 times)*/
#define ActivateTask(x) osdApiCall(ActivateTask(x)) /* PRQA S 3443 */

#define TerminateTask() osdApiCall(TerminateTask()) /* PRQA S 3443 */

#define ChainTask(x) (osdApiCall(ChainTask(x))) /* PRQA S 3443 */

#define Schedule() osdApiCall(Schedule()) /* PRQA S 3443 */

#define GetTaskID(x) (osdApiCall(GetTaskID(x))) /* PRQA S 3443 */

#define GetTaskState(x, y) (osdApiCall(GetTaskState((x), (y)))) /* PRQA S 3443 */

/* QAC-message below can be accepted as osdApiCall uses the parameter just with token merging (##) (3443) (9 times)*/
#define osReadPeripheral8(x, y)          (osdApiCall(osReadPeripheral8((x), (y))))              /* PRQA S 3443 */
#define osReadPeripheral16(x, y)         (osdApiCall(osReadPeripheral16((x), (y))))             /* PRQA S 3443 */
#define osReadPeripheral32(x, y)         (osdApiCall(osReadPeripheral32((x), (y))))             /* PRQA S 3443 */
                                  
#define osWritePeripheral8(x, y, z)      (osdApiCall(osWritePeripheral8((x), (y), (z))))        /* PRQA S 3443 */
#define osWritePeripheral16(x, y, z)     (osdApiCall(osWritePeripheral16((x), (y), (z))))       /* PRQA S 3443 */
#define osWritePeripheral32(x, y, z)     (osdApiCall(osWritePeripheral32((x), (y), (z))))       /* PRQA S 3443 */

#define osModifyPeripheral8(w, x, y, z)  (osdApiCall(osModifyPeripheral8((w), (x), (y), (z))))  /* PRQA S 3443 */
#define osModifyPeripheral16(w, x, y, z) (osdApiCall(osModifyPeripheral16((w), (x), (y), (z)))) /* PRQA S 3443 */
#define osModifyPeripheral32(w, x, y, z) (osdApiCall(osModifyPeripheral32((w), (x), (y), (z)))) /* PRQA S 3443 */

/* (3 times) osXxxPeripheral16 are part of the OS API. The characters 'l' and '1'
 * do not cause confusion here, because the semantics give a clear distinguishment.
 * This is no MISRA error (4152).
 */
osuint8  ososReadPeripheral8   ( osuint16 area, osuint32 address );
osuint16 ososReadPeripheral16  ( osuint16 area, osuint32 address ); /* PRQA S 4152 */
osuint32 ososReadPeripheral32  ( osuint16 area, osuint32 address );

void     ososWritePeripheral8  ( osuint16 area, osuint32 address, osuint8  value );
void     ososWritePeripheral16 ( osuint16 area, osuint32 address, osuint16 value ); /* PRQA S 4152 */
void     ososWritePeripheral32 ( osuint16 area, osuint32 address, osuint32 value );

void     ososModifyPeripheral8 ( osuint16 area, osuint32 address, osuint8  clearmask, osuint8  setmask );
void     ososModifyPeripheral16( osuint16 area, osuint32 address, osuint16 clearmask, osuint16 setmask ); /* PRQA S 4152 */
void     ososModifyPeripheral32( osuint16 area, osuint32 address, osuint32 clearmask, osuint32 setmask );

osqFunc1 StatusType osqFunc2 osActivateTask( TaskType taskIndex);
osqFunc1 StatusType osqFunc2 osTerminateTask ( void );
osqFunc1 StatusType osqFunc2 osChainTask ( TaskType taskIndex );
osqFunc1 StatusType osqFunc2 osSchedule ( void );              
osqFunc1 StatusType osqFunc2 osGetTaskID ( TaskRefType TaskId); 
osqFunc1 StatusType osqFunc2 osGetTaskState(TaskType TaskId, TaskStateRefType State);


/* KB begin osekOsAssertFailedPrototype (default) */
osqFunc1 void osqFunc2 osAssertFailed(void);
/* KB end osekOsAssertFailedPrototype */
/* KB begin osekHwOsekGlobalPrototypes (overwritten) */
/* implementation specific prototypes */
void osIntNestingOverflow(void);    /* Interrupt nesting error handler */

void osInitISRs(void);

/* osCheckInterruptsEnabled: returns true if at least one cat2 interrupt is enabled */
osbool osCheckInterruptsEnabled(void);
/* osCheckInterruptsDisabled: returns true if ALL cat2 interrupts are disabled */
osbool osCheckInterruptsDisabled(void); 


osqFunc1 osuint16 osqFunc2 osGetConfigBlockVersion(void);
osqFunc1 osuint8 osqFunc2 osCheckMPUAccess(osuint8* DestinationAddress);

/* KB end osekHwOsekGlobalPrototypes */ 

#ifndef osdGetCoreIDNotUsed
/* KB begin GetCoreIDFunctionPrototype (default) */
 #define GetCoreID() (osSysGetCoreID())
/* KB end GetCoreIDFunctionPrototype */
#endif

/* KB begin osekHwRTEInterruptMacros (default) */
/* Message 3459: (no MISRA rule related to this) The macros below use the do{...}while(0) construct to implement
                 function like macros which always accept a ';' after their usage. There is no risk in this.
 */
/* CovComment 4:  Macro: osDisableLevelKM */
#define osDisableLevelKM()                               \
do{                                                      \
   osDisableLevel();                                     \
   OS_VTH_CALL_DISABLEDINT_HOOK(OS_VTHP_CAT2INTERRUPTS)  \
   COVER(0x0004)                                               \
}while(0) /* PRQA S 3459 */ 

/* CovComment 4:  Macro: osEnableLevelKM */
#define osEnableLevelKM()                                \
do{                                                      \
   OS_VTH_CALL_ENABLEDINT_HOOK(OS_VTHP_CAT2INTERRUPTS)   \
   osEnableLevel();                                      \
   COVER(0x0005)                                               \
}while(0) /* PRQA S 3459 */ 

/* CovComment 4:  Macro: osDisableGlobalKM */
#define osDisableGlobalKM()                              \
do{                                                      \
   osDisableGlobal();                                    \
   OS_VTH_CALL_DISABLEDINT_HOOK(OS_VTHP_ALLINTERRUPTS)   \
   COVER(0x0006)                                               \
}while(0) /* PRQA S 3459 */ 

/* CovComment 4:  Macro: osEnableGlobalKM */
#define osEnableGlobalKM()                               \
do{                                                      \
   OS_VTH_CALL_ENABLEDINT_HOOK(OS_VTHP_ALLINTERRUPTS)    \
   osEnableGlobal();                                     \
   COVER(0x0007)                                               \
}while(0) /* PRQA S 3459 */ 




osqFunc1 void osqFunc2 osPsysDisableLevelUM(void);
osqFunc1 void osqFunc2 osPsysEnableLevelUM(void);

/* CovComment 4:  Macro: osDisableLevelUM */
#define osDisableLevelUM()                      \
do{                                             \
   osPsysDisableLevelUM();                      \
   COVER(0x0008)                                      \
}while(0) /* PRQA S 3459 */ 

/* CovComment 4:  Macro: osEnableLevelUM */
#define osEnableLevelUM()                       \
do{                                             \
   osPsysEnableLevelUM();                       \
   COVER(0x0009)                                      \
}while(0) /* PRQA S 3459 */ 





osqFunc1 void osqFunc2 osPsysDisableGlobalUM(void);
osqFunc1 void osqFunc2 osPsysEnableGlobalUM(void);

/* CovComment 4:  Macro: osDisableGlobalUM */
#define osDisableGlobalUM()                     \
do{                                             \
   osPsysDisableGlobalUM();                     \
   COVER(0x000A)                                      \
}while(0) /* PRQA S 3459 */ 

/* CovComment 4:  Macro: osEnableGlobalUM */
#define osEnableGlobalUM()                      \
do{                                             \
   osPsysEnableGlobalUM();                      \
   COVER(0x000B)                                      \
}while(0) /* PRQA S 3459 */ 




/* CovComment 4:  Macro: osDisableLevelAM */
#define osDisableLevelAM()                      \
do{                                             \
   osDisableLevelUM();                          \
   COVER(0x000C)                                      \
}while(0) /* PRQA S 3459 */ 


/* CovComment 4:  Macro: osEnableLevelAM */
#define osEnableLevelAM()                       \
do{                                             \
   osEnableLevelUM();                           \
   COVER(0x000D)                                      \
}while(0) /* PRQA S 3459 */ 




/* CovComment 4:  Macro: osDisableGlobalAM */
#define osDisableGlobalAM()                     \
do{                                             \
   osDisableGlobalUM();                         \
   COVER(0x000E)                                      \
}while(0) /* PRQA S 3459 */ 


/* CovComment 4:  Macro: osEnableGlobalAM */
#define osEnableGlobalAM()                      \
do{                                             \
   osEnableGlobalUM();                          \
   COVER(0x000F)                                      \
}while(0) /* PRQA S 3459 */ 






/* KB end osekHwRTEInterruptMacros */

/* interrupt handling */
osqFunc1 void osqFunc2 osEnableAllInterrupts(void);

osqFunc1 void osqFunc2 osDisableAllInterrupts(void);

osqFunc1 void osqFunc2 osResumeOSInterrupts(void);

osqFunc1 void osqFunc2 osSuspendOSInterrupts(void);

osqFunc1 void osqFunc2 osResumeAllInterrupts(void);

osqFunc1 void osqFunc2 osSuspendAllInterrupts(void);

/* KB begin osekHwPsysWrapperPrototypes (default) */
osdDeclareApiWrappers(StatusType, ActivateTask, osdParams1(TaskType Param0_taskIndex))

osdDeclareApiWrappers(StatusType, ChainTask, osdParams1(TaskType Param0_taskIndex))

osdDeclareApiWrappers(StatusType, GetTaskID, osdParams1(TaskRefType Param0_TaskId))

osdDeclareApiWrappers(StatusType, GetTaskState, osdParams2(TaskType Param0_TaskId, TaskStateRefType Param1_State))

osdDeclareApiWrappers(StatusType, GetResource, osdParams1(ResourceType Param0_ResId))

osdDeclareApiWrappers(StatusType, ReleaseResource, osdParams1(ResourceType Param0_ResId))

osdDeclareApiWrappers(StatusType, SetEvent, osdParams2(TaskType Param0_taskIndex, EventMaskType Param1_setMask))

osdDeclareApiWrappers(StatusType, ClearEvent, osdParams1(EventMaskType Param0_Mask))

osdDeclareApiWrappers(StatusType, GetEvent, osdParams2(TaskType Param0_taskIndex, EventMaskRefType Param1_Event))

osdDeclareApiWrappers(StatusType, WaitEvent, osdParams1(EventMaskType Param0_Mask))


osdDeclareApiWrappers(StatusType, GetAlarm, osdParams2(AlarmType Param0_alarmID, TickRefType Param1_diffTickTime))

osdDeclareApiWrappers(StatusType, SetRelAlarm, osdParams3(AlarmType Param0_alarmID, 
                                                          TickType Param1_deltaTicks, 
                                                          TickType Param2_cycle      )
                     )

osdDeclareApiWrappers(StatusType, SetAbsAlarm, osdParams3(AlarmType Param0_alarmID, 
                                                          TickType Param1_start, 
                                                          TickType Param2_cycle    )
                     )

osdDeclareApiWrappers(StatusType, CancelAlarm, osdParams1(AlarmType Param0_alarmID))

osdDeclareApiWrappers(void, ShutdownOS, osdParams1(StatusType Param0_Error))

osdDeclareApiWrappers(StatusType, StartScheduleTableRel, osdParams2(ScheduleTableType Param0_ScheduleTableID,
                                                                    TickType Param1_Offset                   )
                     )

osdDeclareApiWrappers(StatusType, StartScheduleTableAbs, osdParams2(ScheduleTableType Param0_ScheduleTableID,
                                                                    TickType Param1_Offset                   )
                     )

osdDeclareApiWrappers(StatusType, NextScheduleTable, osdParams2(ScheduleTableType Param0_ScheduleTableID_current, 
                                                                ScheduleTableType Param1_ScheduleTableID_next    )
                     )

osdDeclareApiWrappers(StatusType, StopScheduleTable, osdParams1(ScheduleTableType Param0_ScheduleTableID))


osdDeclareApiWrappers(StatusType, GetScheduleTableStatus, osdParams2(ScheduleTableType Param0_ScheduleTableID, 
                                                                     ScheduleTableStatusRefType Param1_ScheduleStatus)
                     )

osdDeclareApiWrappers(StatusType, IncrementCounter, osdParams1(CounterType Param0_CounterID))

osdDeclareApiWrappers(StatusType, GetCounterValue, osdParams2(CounterType Param0_CounterID, TickRefType Param1_Value))


osdDeclareApiWrappers(StatusType, GetElapsedValue, osdParams3(CounterType Param0_CounterID, 
                                                              TickRefType Param1_Value, 
                                                              TickRefType Param2_ElapsedValue)
                     )


osdDeclareApiWrappers(StatusType, GetApplicationState, osdParams2(ApplicationType Param0_Application, 
                                                                  ApplicationStateRefType Param1_Value)
                     )

osdDeclareApiWrappers(StatusType, CallTrustedFunction, osdParams2(TrustedFunctionIndexType Param0_FunctionIndex, 
                                                       TrustedFunctionParameterRefType Param1_FunctionParams    )
                     )

osdDeclareApiWrappers(StatusType, CallNonTrustedFunction, osdParams2(NonTrustedFunctionIndexType Param0_FunctionIndex, 
                                                          NonTrustedFunctionParameterRefType Param1_FunctionParams    )
                     )

osdDeclareApiWrappers(AccessType, CheckISRMemoryAccess, osdParams3(ISRType Param0_ISRID, 
                                                                   MemoryStartAddressType Param1_Address, 
                                                                   MemorySizeType Param2_Size            )
                     )

osdDeclareApiWrappers(AccessType, CheckTaskMemoryAccess, osdParams3(TaskType Param0_TaskID, 
                                                                    MemoryStartAddressType Param1_Address, 
                                                                    MemorySizeType Param2_Size            )
                     )

osdDeclareApiWrappers(ObjectAccessType, CheckObjectAccess, osdParams3(ApplicationType Param0_ApplID, 
                                                                      ObjectTypeType Param1_ObjectType, 
                                                                      ObjectIDType Param2_ObjectID     )
                     )

osdDeclareApiWrappers(ApplicationType, CheckObjectOwnership, osdParams2(ObjectTypeType Param0_ObjectType, 
                                                                        ObjectIDType Param1_ObjectID     )
                     )

osdDeclareApiWrappers(StatusType, osGetTaskMaxExecutionTime, osdParams2(TaskType Param0_TaskID, 
                                                                        osTPTimeRefType Param1_MaxTime)
                     )

osdDeclareApiWrappers(StatusType, osGetISRMaxExecutionTime, osdParams2(ISRType Param0_ISRID, 
                                                                       osTPTimeRefType Param1_MaxTime)
                     )

osdDeclareApiWrappers(StatusType, osGetTaskMaxBlockingTime, osdParams4(TaskType Param0_TaskID, 
                                                                       BlockTypeType Param1_BlockType, 
                                                                       ResourceType Param2_ResourceID, 
                                                                       osTPTimeRefType Param3_MaxTime )
                     )

osdDeclareApiWrappers(StatusType, osGetISRMaxBlockingTime, osdParams4(ISRType Param0_ISRID, 
                                                                      BlockTypeType Param1_BlockType, 
                                                                      ResourceType Param2_ResourceID, 
                                                                      osTPTimeRefType Param3_MaxTime)
                     )

osdDeclareApiWrappers(StatusType, osGetTaskMinInterArrivalTime, osdParams2(TaskType Param0_TaskID, 
                                                                           osTPTimeStampRefType Param1_MinTime)
                     )

osdDeclareApiWrappers(StatusType, osGetISRMinInterArrivalTime, osdParams2(ISRType Param0_ISRID, 
                                                                          osTPTimeStampRefType Param1_MinTime)
                     )

osdDeclareApiWrappers(StatusType, TerminateTask, void)

osdDeclareApiWrappers(StatusType, Schedule, void)

osdDeclareApiWrappers(AppModeType, GetActiveApplicationMode, void)

osdDeclareApiWrappers(ISRType, GetISRID, void)

osdDeclareApiWrappers(void, DisableAllInterrupts, void)

osdDeclareApiWrappers(void, EnableAllInterrupts, void)

osdDeclareApiWrappers(void, SuspendAllInterrupts, void)

osdDeclareApiWrappers(void, ResumeAllInterrupts, void)

osdDeclareApiWrappers(void, SuspendOSInterrupts, void)

osdDeclareApiWrappers(void, ResumeOSInterrupts, void)






osdDeclareApiWrappers(osuint8, osReadPeripheral8, osdParams2(osuint16 Param0_area, osuint32 Param1_address))
/* QAC Message about 'l' and '1' together in a name is acceped below. As the 'l' is part of a full word there is only 
 * small risk for confusion (4152) (no MISRA rule for this QAC message) */
osqFunc1 osuint16 osqFunc2 osPsysosReadPeripheral16     (osuint16 Param0_area, osuint32 Param1_address); /* PRQA S 4152 */
osdDeclareApiWrappers(osuint32, osReadPeripheral32, osdParams2(osuint16 Param0_area, osuint32 Param1_address))

osdDeclareApiWrappers(void, osWritePeripheral8, osdParams3(osuint16 Param0_area, osuint32 Param1_address, osuint8  Param2_value))
/* QAC Message about 'l' and '1' together in a name is acceped below. As the 'l' is part of a full word there is only 
 * small risk for confusion (4152) (no MISRA rule for this QAC message) */
osqFunc1 void osqFunc2 osPsysosWritePeripheral16     (osuint16 Param0_area, osuint32 Param1_address, osuint16 Param2_value);/* PRQA S 4152 */
osdDeclareApiWrappers(void, osWritePeripheral32, osdParams3(osuint16 Param0_area, osuint32 Param1_address, osuint32 Param2_value))

osdDeclareApiWrappers(void, osModifyPeripheral8 , osdParams4(osuint16 Param0_area, 
                                                             osuint32 Param1_address, 
                                                             osuint8  Param2_clearmask, 
                                                             osuint8  Param3_setmask   )
                     )
/* QAC Message about 'l' and '1' together in a name is acceped below. As the 'l' is part of a full word there is only 
 * small risk for confusion (4152) (no MISRA rule for this QAC message) */
osqFunc1 void osqFunc2 osPsysosModifyPeripheral16( osuint16 Param0_area, 
                                                   osuint32 Param1_address, 
                                                   osuint16 Param2_clearmask, 
                                                   osuint16 Param3_setmask ); /* PRQA S 4152 */
osdDeclareApiWrappers(void, osModifyPeripheral32, osdParams4(osuint16 Param0_area, 
                                                             osuint32 Param1_address, 
                                                             osuint32 Param2_clearmask, 
                                                             osuint32 Param3_setmask   )
                      )
/* KB end osekHwPsysWrapperPrototypes */

#define osdIntAPIDisableAll 0x80U

   #define osSetIntAPIStatus(x) (osOwnCcb->LockIsNotNeeded.ossIntAPIStatus = (x))
   #define osIncIntAPIStatus() (osOwnCcb->LockIsNotNeeded.ossIntAPIStatus++)
   #define osDecIntAPIStatus() (osOwnCcb->LockIsNotNeeded.ossIntAPIStatus--)


/* QAC-message below can be accepted as osdApiCall uses the parameter just with token merging (##) (3443) (8 times)*/
#define EnableAllInterrupts() (osdApiCall(EnableAllInterrupts())) /* PRQA S 3443 */

#define DisableAllInterrupts() (osdApiCall(DisableAllInterrupts())) /* PRQA S 3443 */

#define ResumeOSInterrupts() (osdApiCall(ResumeOSInterrupts())) /* PRQA S 3443 */

#define SuspendOSInterrupts() (osdApiCall(SuspendOSInterrupts())) /* PRQA S 3443 */

#define ResumeAllInterrupts() (osdApiCall(ResumeAllInterrupts())) /* PRQA S 3443 */

#define SuspendAllInterrupts() (osdApiCall(SuspendAllInterrupts())) /* PRQA S 3443 */


/* resource management */

#define GetResource(x) (osdApiCall(GetResource(x))) /* PRQA S 3443 */


#define ReleaseResource(x) (osdApiCall(ReleaseResource(x))) /* PRQA S 3443 */


osqFunc1 StatusType osqFunc2 osGetResource(ResourceType ResId);

osqFunc1 StatusType osqFunc2 osReleaseResource(ResourceType ResId); 

/* KB begin osekSemaphores (default) */
/* KB end osekSemaphores */

/* event control */
/* QAC-message below can be accepted as osdApiCall uses the parameter just with token merging (##) (3443) (4 times)*/
#define SetEvent(x, y) (osdApiCall(SetEvent((x), (y)))) /* PRQA S 3443 */

#define GetEvent(x, y) (osdApiCall(GetEvent((x), (y)))) /* PRQA S 3443 */

#define ClearEvent(x) (osdApiCall(ClearEvent(x))) /* PRQA S 3443 */

#define WaitEvent(x) (osdApiCall(WaitEvent(x))) /* PRQA S 3443 */

osqFunc1 StatusType osqFunc2 osSetEvent(TaskType taskIndex, EventMaskType setMask);

osqFunc1 StatusType osqFunc2 osClearEvent (EventMaskType Mask );                  

osqFunc1 StatusType osqFunc2 osGetEvent(TaskType taskIndex, EventMaskRefType Event); 

osqFunc1 StatusType osqFunc2 osWaitEvent(EventMaskType mask);                    



/* alarms        */
/* QAC-message below can be accepted as osdApiCall uses the parameter just with token merging (##) (3443) */

/* KB begin osekHwSetRelAlarmDefine2 (default) */
/* QAC-message below can be accepted as osdApiCall uses the parameter just with token merging (##) (3443)*/
#define SetRelAlarm(x, y, z) (osdApiCall(SetRelAlarm((x), (y), (z)))) /* PRQA S 3443 */
/* KB end osekHwSetRelAlarmDefine2 */

/* KB begin osekHwSetAbsAlarmDefine2 (default) */
/* QAC-message below can be accepted as osdApiCall uses the parameter just with token merging (##) (3443)*/
#define SetAbsAlarm(x, y, z) (osdApiCall(SetAbsAlarm((x), (y), (z)))) /* PRQA S 3443 */
/* KB end osekHwSetAbsAlarmDefine2 */

/* QAC-message below can be accepted as osdApiCall uses the parameter just with token merging (##) (3443) (3 times)*/
#define CancelAlarm(x) (osdApiCall(CancelAlarm(x))) /* PRQA S 3443 */
 
#define IncrementCounter(x) (osdApiCall(IncrementCounter(x))) /* PRQA S 3443 */


  #define GetCounterValue(x, y) (osdApiCall(GetCounterValue((x), (y)))) /* PRQA S 3443 */

/* QAC-message below can be accepted as osdApiCall uses the parameter just with token merging (##) (3443)*/
  #define GetElapsedCounterValue(x,y,z) GetElapsedValue((x),(y),(z)) /* compatibility ASR3/ASR4 */
  #define GetElapsedValue(x, y, z) (osdApiCall(GetElapsedValue((x), (y), (z)))) /* PRQA S 3443 */


/* QAC-message below can be accepted as osdApiCall uses the parameter just with token merging (##) (3443) (6 times)*/
#define GetAlarm(x, y) (osdApiCall(GetAlarm((x), (y)))) /* PRQA S 3443 */

#define StartScheduleTableRel(x, y) osdApiCall(StartScheduleTableRel((x), (y))) /* PRQA S 3443 */

#define StartScheduleTableAbs(x, y) osdApiCall(StartScheduleTableAbs((x), (y))) /* PRQA S 3443 */

#define StopScheduleTable(x) osdApiCall(StopScheduleTable((x))) /* PRQA S 3443 */

#define NextScheduleTable(x, y) osdApiCall(NextScheduleTable((x), (y))) /* PRQA S 3443 */

#define GetScheduleTableStatus(x, y) osdApiCall(GetScheduleTableStatus((x), (y))) /* PRQA S 3443 */




/* KB begin osekHWosSetRelAlarmPrototype (default) */
osqFunc1 StatusType osqFunc2 osSetRelAlarm(AlarmType alarmID, 
                                           TickType deltaTicks,
                                           TickType cycle);
/* KB end osekHWosSetRelAlarmPrototype */

/* KB begin osekHWosSetAbsAlarmPrototype (default) */
osqFunc1 StatusType osqFunc2 osSetAbsAlarm(AlarmType alarmID, 
                                           TickType start,
                                           TickType cycle);
/* KB end osekHWosSetAbsAlarmPrototype */

osqFunc1 StatusType osqFunc2 osCancelAlarm(AlarmType alarmID);

/* fullfills [SR:315] of $\AutosarOS\general\Generation5\_doc\12_SystemRequirements\RequirementsSpec_MicrosarOS.doc */
osqFunc1 StatusType osqFunc2 osIncrementCounter(CounterType CounterID);

osqFunc1 StatusType osqFunc2 osGetCounterValue(CounterType CounterID, TickRefType Value); /* TR:SASR30:5108 */

osqFunc1 StatusType osqFunc2 osGetElapsedValue(CounterType CounterID, TickRefType Value, TickRefType ElapsedValue); /* TR:SASR30:5109 */

osqFunc1 StatusType osqFunc2 osGetAlarm(AlarmType alarmID, TickRefType diffTickTime);


osqFunc1 StatusType osqFunc2 osStartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Offset);
osqFunc1 StatusType osqFunc2 osStartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Tickvalue);

osqFunc1 StatusType osqFunc2 osNextScheduleTable(ScheduleTableType ScheduleTableID_current, ScheduleTableType ScheduleTableID_next);
osqFunc1 StatusType osqFunc2 osGetScheduleTableStatus(ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus);
osqFunc1 StatusType osqFunc2 osStopScheduleTable(ScheduleTableType ScheduleTableID);




/* QAC-message below can be accepted as osdApiCall uses the parameter just with token merging (##) (3443) (5 times)*/


#define CheckObjectOwnership(x, y) (osdApiCall(CheckObjectOwnership((x), (y)))) /* PRQA S 3443 */

#define CheckObjectAccess(x, y, z) (osdApiCall(CheckObjectAccess((x), (y), (z)))) /* PRQA S 3443 */

#define CallTrustedFunction(x, y) (osdApiCall(CallTrustedFunction((x), (y)))) /* PRQA S 3443 */

/* QAC-message below can be accepted as osdApiCall uses the parameter just with token merging (##) (3443) */
#define CallNonTrustedFunction(x, y) (osdApiCall(CallNonTrustedFunction((x), (y)))) /* PRQA S 3443 */

/* QAC-message below can be accepted as osdApiCall uses the parameter just with token merging (##) (3443) */
#define GetApplicationState(x, y) (osdApiCall(GetApplicationState((x), (y))) /* TR:SASR40:0499 */) /* PRQA S 3443 */




osqFunc1 ApplicationType osqFunc2 osCheckObjectOwnership(ObjectTypeType ObjectType,
                                                         ObjectIDType ObjectID);
osqFunc1 ObjectAccessType osqFunc2 osCheckObjectAccess(ApplicationType   ApplID,
                                                     ObjectTypeType    ObjectType,
                                                     ObjectIDType      ObjectId);
osqFunc1 StatusType osqFunc2 osCallTrustedFunction(TrustedFunctionIndexType FunctionIndex,
                                                         TrustedFunctionParameterRefType FunctionParams);
osqFunc1 StatusType osqFunc2 osCallNonTrustedFunction(NonTrustedFunctionIndexType        FunctionIndex  ,
                                                      NonTrustedFunctionParameterRefType FunctionParams  );

osqFunc1 StatusType osqFunc2 osGetApplicationState(ApplicationType Application, ApplicationStateRefType Value); /* TR:SASR40:6039 */



/* TR:SPMF20:0013 Start */
/* definitions for static alarms */
/* these macros should be used as parameters for SetRelAlarm/SetAbsAlarm in case of static alarms */
#define OS_STATIC_ALARM_TIME 0
#define OS_STATIC_CYCLE_TIME 0
/* TR:SPMF20:0013 End */

/* Operating system execution control */
osqFunc1 void osqFunc2 osErrorHook(StatusType ErrorCode);
osqFunc1 void osqFunc2 osShutdownOS(StatusType Error);
/* QAC-message below can be accepted as osdApiCall uses the parameter just with token merging (##) (3443)*/
#define ShutdownOS(x) (osdApiCall(ShutdownOS(x))) /* PRQA S 3443 */

osqFunc1 void osqFunc2 osStartOSasm(void); /* TR:SPMF05:0001 */

/* Definition of StartOS(). */
/* Error-Checking is done is osStartOSc */
/* TR:SPMF05:0001 Start */
#define StartOS(x)                              \
   osActiveAppMode=(x);                         \
   osStartOSasm()
/* TR:SPMF05:0001 End */

/* fullfills [SR:006] of $\AutosarOS\general\Generation5\_doc\12_SystemRequirements\RequirementsSpec_MicrosarOS.doc */
osqFunc1 void osqFunc2 osInitialize(void); /* TR:SPMF05:0001 */


osqFunc1 ApplicationType osqFunc2 osGetApplicationID(void);
/* KB begin osekGetApplicationIDDef (overwritten) */
  #define GetApplicationID() (osOwnCcb->LockIsNotNeeded.ossActiveApplicationID)
/* KB end osekGetApplicationIDDef */

osqFunc1 AppModeType osqFunc2 osGetActiveApplicationMode(void);
/* KB begin osekGetActiveApplicationModeDef (overwritten) */
 #define GetActiveApplicationMode() (osGetActiveApplicationMode())
/* KB end osekGetActiveApplicationModeDef */

osqFunc1 ISRType osqFunc2 osGetISRID(void);
/* KB begin osekGetISRIDDef (overwritten) */
 #define GetISRID() (osGetISRID())
/* KB end osekGetISRIDDef */

/* KB begin osekCallBackSectionStart (default) */
/* KB end osekCallBackSectionStart */

/* hook routines */
osqFunc1 void osqFunc2 ErrorHook (StatusType Error);
osqFunc1 void osqFunc2 StartupHook (void);
osqFunc1 void osqFunc2 ShutdownHook (StatusType Error);

#if osdPreTaskHook
osqFunc1 void osqFunc2 PreTaskHook (void);
#endif
#if osdPostTaskHook
osqFunc1 void osqFunc2 PostTaskHook (void);
#endif

ProtectionReturnType ProtectionHook(StatusType Fatalerror);

/* KB begin osekCallBackSectionEnd (default) */
/* KB end osekCallBackSectionEnd */

  osqFunc1 osStackUsageType osqFunc2 osGetStackUsage(TaskType taskId); /* TR:SPMF08:0007 */
  /* KB begin osekStackUsagePrototypes (overwritten) */
  /* implementation specific prototypes for stack usage calculation */
  osStackUsageType osCountStackUsage(osStackDataType const * const stackStart, osStackDataType const * const stackEnd);
  #define osGetSystemStackUsage()   osCountStackUsage(osConfigBlock.SystemStacks[osSysGetCoreID()].start, osConfigBlock.SystemStacks[osSysGetCoreID()].end)
  #define osGetFIQStackUsage()      osCountStackUsage(osConfigBlock.FIQStacks[osSysGetCoreID()].start, osConfigBlock.FIQStacks[osSysGetCoreID()].end)
  #define osGetIRQCat1StackUsage()  osCountStackUsage(osConfigBlock.IRQCat1Stacks[osSysGetCoreID()].start, osConfigBlock.IRQCat1Stacks[osSysGetCoreID()].end)
  #define osGetIntStackUsage(isr)   (((isr) < osdNumberOfCat2ISRs)?(osCountStackUsage(osConfigBlock.cat2IsrStacks[isr].start, osConfigBlock.cat2IsrStacks[isr].end)):((osStackUsageType)0))
  /* KB end osekStackUsagePrototypes */


#if !defined osdProvideTimeStamp
#define osdProvideTimeStamp 0
#endif

/* KB begin osekHWosVersionVariant (default) */
/* TR:SPMF29:0001 Start */
/* structure for version and variant coding */
typedef struct
{
   osuint8 ucMagicNumber1;     /* magic number (e.g. for identification in hex files) */
   osuint8 ucMagicNumber2;     /* defined as osuint8 for independancy of byte order   */
   osuint8 ucMagicNumber3;     /*                                                     */
   osuint8 ucMagicNumber4;     /*                                                     */
   osuint8 ucSysVersionMaj;    /* version of operating system, Major                  */
   osuint8 ucSysVersionMin;    /* version of operating system, Minor                  */
   osuint8 ucGenVersionMaj;    /* version of code generator                           */
   osuint8 ucGenVersionMin;    /* version of code generator                           */
   osuint8 ucSysVariant1;      /* general variant coding 1                            */
   osuint8 ucSysVariant2;      /* general variant coding 2                            */
   osuint8 ucOrtiVariant;      /* ORTI version and variant       TR:SPMF14:0011  TR:SPMF29:0003      */ 
   /* KB begin osekTypeSpecVersionVariant (overwritten) */
   /* typedef of implementation specific variant coding */
   osuint32 ucSpecVariant;
   /* KB end osekTypeSpecVersionVariant */
} osVersionVariantCodingType;
/* TR:SPMF29:0001 End */

/* KB begin osekConstSectionHeaderStart (default) */
/* KB end osekConstSectionHeaderStart */
osqROM0 extern osqROM1 const osqROM2 osVersionVariantCodingType osqROM3 oskVersionVariant;
/* KB begin osekConstSectionHeaderEnd (default) */
/* KB end osekConstSectionHeaderEnd */
/* KB end osekHWosVersionVariant */

/* setup defines for filling up the variant coding structure */
   #define osdVariantCC 3U

   #define osdVariantStatus 1U

   #define osdVariantSchedule 2U


   #define osdVariantStackcheck 1U


/* TR:SPMF12:0005 Start */
   #define osdVariantAssertionsEnabled 1U
/* TR:SPMF12:0005 End */
   #define osdVariantSC 2U

   #define osdVariantFeaturesUsed_ST 1U
   #define osdVariantFeaturesUsed_HRST 1U
   #define osdVariantFeaturesUsed_Sync 0U
   #define osdVariantFeaturesUsed_TP   0U

/* osdORTIStdVersion is decimal coded, osdVariantORTIVersion shall be BCD coded */
#define osdVariantORTIVersion ((((osdORTIStdVersion)/100)<<4)|(((osdORTIStdVersion)%100)/10))
#define osdVariantORTIDebug 1

/* KB begin osekDefineSpecVersionVariant (overwritten) */
/* KB end osekDefineSpecVersionVariant */



/* KB begin osekSpecificHeaderInclude (default) */
/* KB end osekSpecificHeaderInclude */


 #if defined USE_QUOTE_INCLUDES
  #include "tcbpost.h"
 #else
  #include <tcbpost.h>
 #endif


/* include hardware specific header files after OSEK Typedefinitions */
/* KB begin osekHWincludeHwHeaderPostTypes (overwritten) */
/* KB end osekHWincludeHwHeaderPostTypes */

/* KB begin osekEndOfHModule (default) */
/* KB end osekEndOfHModule */

/*lint -restore re-enable messages*/

#endif/* double include preventer */

/* END OF HEADER osek.h */

