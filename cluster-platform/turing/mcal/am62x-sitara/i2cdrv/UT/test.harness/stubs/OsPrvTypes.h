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
 * @file        OsPrvTypes.h
 * @details     <b> Defines the Os specific Types </b>
 * @note
 *              Compiler    : Independent \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef OS_PRVTYPES_H
#define OS_PRVTYPES_H

#include "OsTypes.h"
#include "OsHal_CpuCore.h"



/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef osuint32                    osResCounterType;
typedef osCpuStackType              osStackDataType;
typedef osStackDataType*            osStackPtrType;
typedef osStackDataType const *     osStackPtrToConstType; /*MISRA RULE 2.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
typedef osStackDataType             osStackSizeType;
typedef osuint8                     osPrioQueueType; /*MISRA RULE 4.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
typedef void                        (*StartHookRefType)(void);
typedef void                        (*PreHookRefType)(void);
typedef void                        (*PostHookRefType)(void);
typedef void                        (*ShutdownHookRefType)(void);
typedef void                        (*ErrorHookRefType)(ErrReasonRefType ErrRef);
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef struct
{
    StartHookRefType    StartHook;
    PreHookRefType      PreHook;
    PostHookRefType     PostHook;
    ShutdownHookRefType ShutdownHook;
    ErrorHookRefType    ErrorHook;
}OsHookConfigType;

typedef OsHookConfigType*   OsHookConfigRefType;




/*+----------------------------- ROM ----------------------------------------------*/

typedef struct
{
    AccessRightsIdType AppAccessId;
    AccessRightsIdType ObjAccessId;
}OsMPUAccessRightsIdType;

typedef OsMPUAccessRightsIdType* OsMPUAccessRightsIdRefType;



/*******************************************************************************/


struct OsAppConfigType_T;

//OsObjConfigType
/*******************************************************************************/
typedef struct
{
    ObjectIdType        ObjId;
    CoreIdType          CoreId;
    ObjectTypeType      ObjType;
    AccessRightsIdType  AccessId;
    struct OsAppConfigType_T*    pAppRef;         //added due to fwd declaration of OsAppConfigType
    osStackPtrType      StackStartAddress;
    osStackSizeType     StackSize;
    osuint32            StackRegAttribute;
}OsObjConfigType;

typedef const OsObjConfigType*    OsObjConfigRefType;
/*******************************************************************************/

typedef struct
{
    IRQSourceType       IrqNum;
    IRQPrioLevelType    PrioLevel;
    osVoidFunctionType  ServiceRoutine;
    OsObjConfigRefType  pObjRef;
}OsIsrConfigType;

typedef OsIsrConfigType*    OsIsrConfigRefType; /*MISRA RULE 2.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
/*******************************************************************************/

//TcbConfigType
/*******************************************************************************/
typedef struct
{
    osTaskFuncRefType   TaskStartAddress;
    osStackPtrType      TaskStackStartAddress;
    osStackSizeType     TaskStackSize;
    TaskPriorityType    TaskPriority;
    osuint8	            TaskMaxActivationCount;
    osuint8             TaskCategory;
    OsObjConfigRefType  pObjRef;
    osuint8             TasksType;
}TcbConfigType;
/*******************************************************************************/

typedef struct OsprioQueueTypeT /*MISRA RULE 2.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
{
    osuint8 Head;
    osuint8 Tail;
    TaskType * const pQueue;
}OsprioQueueType;
/*******************************************************************************/

//OsStackType
/*******************************************************************************/
typedef struct
{
    osStackPtrType startAddr;
    osStackPtrType endAddr;
}OsStackType;
/*******************************************************************************/

//OsAppConfigType
/*******************************************************************************/
struct OsCoreConfigType_T;

typedef struct OsAppConfigType_T
{
    ApplicationType     AppId;
    AccessRightsIdType  AccessId;
    AccessLevelType     AccessLevel;
    struct OsCoreConfigType_T* pCoreRef;      //Fwd declaration
    OsObjConfigRefType  pObjListRef;
    OsHookConfigRefType pHookRef;
}OsAppConfigType;

typedef const OsAppConfigType*    OsAppConfigRefType;
/*******************************************************************************/

//OsCoreConfigType
/*******************************************************************************/
typedef struct OsCoreConfigType_T
{
    CoreIdType          CoreId;
    osbool              IsAsrCore;
    osuint8             NumOfApp;
    OsAppConfigRefType  pAppListRef;
    OsAppConfigRefType  pOsCoreAppRef;
    OsObjConfigRefType  pOsCoreObjRef;
    OsHookConfigRefType pHookRef;
}OsCoreConfigType;

typedef OsCoreConfigType *  OsCoreConfigRefType;

typedef struct
{
    TrustedFunctionType Service;
    OsAppConfigRefType  pOwnerAppRef;
    osuint16            Context;
}OsTrustedCallConfigType;

typedef OsTrustedCallConfigType * OsTrustedCallConfigRefType;

typedef struct
{
    OsAppConfigRefType pAppRef;
    OsObjConfigRefType pObjRef;
}OsAppOwnerParamType;

typedef OsAppOwnerParamType* OsAppOwnerParamRefType; /*MISRA RULE 2.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

/*******************************************************************************/
/*RAM*/

typedef struct
{
    ApplicationStateType        State;
    AccessRightsIdType          AccessId;
}OsAppParamType;

typedef struct
{
    CoreStateType   State;
}OsCoreParamType;


typedef struct
{
    OsCoreParamType             CoreParam;
    OsAppParamType              AppParam;
    ISRType                     ActiveISRId;
    OsObjConfigRefType          pLastObjRef;
    OsObjConfigRefType          pActiveObjRef;
    TaskType                    ActiveTaskIndex;
    TaskType                    RequestedTaskIndex;
    TaskPriorityType            ActiveTaskPriority;
    TaskPriorityType            RequestedTaskPriority;
    TaskPriorityType			ResOccVirtualPrioBits;
    TaskPriorityBitType         TaskPriorityBits;
    osuint8                     RequestScheduler;
    osuint8                     LockDispatcher;
    osuint8                     IntSaveDisableRequestCounter;
    osIntGlobaltype             IntSaveStatus;
    osIntGlobaltype             IntSaveGlobal;
    osuint16                    CurrentContext;
    osuint8                     OsIntSaveDisableRequestCounter;
}OsCtrlParamType;


typedef struct
{    
    EventMaskType   WaitEventMask;
    EventMaskType   SetEventMask;
    osStackPtrType StackAddress;
    osuint8 State;
    osActivationCntType ActivationCnt;
	osuint8 ResCnt;
}TaskParamType;


typedef struct
{    
	osuint8 		ResIndex;
	osuint8*		pResList;
}TaskResPrioType;	 /*MISRA RULE 2.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
	
typedef struct
{
    void (*OsAlarmCallback)(void);
    TaskType OsAlarmTask;
    osuint8 OsAlarmAction;
    EventMaskType OsAlarmEvent;
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



extern osErrParamType  osErrParam;



typedef struct
{
    osuint32            RegionCount;
    OsIntMpuConfigType* pMpuConfig;
}OsMPUAccessGroupConfigType;

typedef OsMPUAccessGroupConfigType* OsMpuAccessGroupConfigRefType;

//describes differences between 2 MPU access groups
typedef struct
{
    const uint8 DiffCount;            //differences count
    const osuint32* DiffRegions;      //ptr to array with different mpu region IDs
} OsMpuAccessGroupDiffType;


typedef struct
{
    ResourceType        ResId;
    uint8               Type;
    TaskPriorityType    CeilingPrio;
    OsAppConfigRefType*  pAppRef;
    osuint8             NumofpAppRef;
}OsResConfigType;

typedef struct
{
    osuint8             ProtectionError;
    TaskType            CallingTask;
    osuint16            ErrorContext;
    TickType            ErrorSystemTimer;
    ProtErrorInfoType   os_faultFrame;
}ProtectionErrType;


#include "OsInternal.h"


#endif /* EOF */
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
**   RTC Id            : 951142                                                     **
**   Change Description: OS ASIL B Support - Initial Version                        **
**----------------------------------------------------------------------------------*/

