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
*  File Name         :  osek_private.h                                       *
*  Module Short Name :  osek header                                          *
*  Description       :  This file externs the private APIs of the OS         *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  INDEPENDENT                                            *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

#include "Os.h"
#include "OsInternal.h"
#include "MemLib.h"

#define OS_Privilegemode 0U
#define OS_Usermode      1U 

#define OffsetOf(structure, member) ((osuint16) &(((structure *) 0)->member))/*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define osdSizeof(x)                        sizeof(x)           /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

#define osdMaxAllowedCriticalSectionNesting         50uL


#define OsStartTimer()                              osStartArchTimer()



extern const osStackPtrType IsrStackConfig[osdNumberOfCat2ISRs];
extern const osuint32 IsrStackSize[osdNumberOfCat2ISRs];
extern osStackPtrType osIntSP; 

extern osErrParamType  osErrParam;
extern OsCtrlParamType OsCtrlParam;
extern TaskType TaskActivation[OsMaxPriorityLevel];
extern void osFillStack (osStackPtrType stackTop, osStackPtrType stackBot);
extern void osInitAlarms (void);
extern void osInitTimer (void);
extern StatusType osSysActivateTask (TaskType TaskIndex);
extern StatusType osSysSetEvent ( TaskType TaskIndex, EventMaskType EventMask );
extern StatusType osSysWaitEvent ( EventMaskType EventMask );
extern StatusType osSysReleaseResource (ResourceType Res);
extern StatusType osSysTerminateTask (void);
extern StatusType osSysSchedule (void);
extern void osSysErrAssert (void);

extern void osISRUnhandledException (void);
extern void osUnhandledException (void);
extern void osUndefinedInstructionException (void);
extern void osMemProtectionFault (void);
extern void osDataAbortHandler (void);

extern void osIncrementHardwareCounters (void);
extern StatusType osIncrementCounter (CounterType CounterId);/*MISRA RULE 4.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
extern StatusType osResetCounter (CounterType CounterId);
extern osuint32 osGetPRIMASK(void);
extern void OsProcessScheduleTable(void);

extern osIntGlobaltype osSuspendInterruptsAsm (void); /*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
extern void osResumeInterruptsAsm (osIntGlobaltype intStatus);/*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
extern void osDisableGlobalInterruptAsm(void);/*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
extern void osEnableGlobalInterruptAsm(void);/*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
extern void osSVCHandlerAsm (void);/*MISRA RULE 8.6 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#endif
