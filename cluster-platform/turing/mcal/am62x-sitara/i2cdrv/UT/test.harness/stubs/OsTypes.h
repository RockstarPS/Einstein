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
 * @file        OsTypes.h 
 * @details     <b>Defines the Os specific Types</b>
 * @note
 *              Compiler    : Independent \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef OS_TYPES_H
#define OS_TYPES_H

#include "Std_Types.h"
#include "Os_CfgTypes.h"

#define OS_STATUS_STANDARD          0U /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_STATUS_EXTENDED          1U


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

/* Boolean definition */

typedef osuint8 osbool;


#endif

# ifndef STATUSTYPEDEFINED
#  define STATUSTYPEDEFINED
typedef osuint8 StatusType;
#endif


typedef osuint16                    osStackUsageType;
typedef osuint8                     TaskType;
typedef TaskType*                   TaskRefType;
typedef osuint8                     TaskStateType;
typedef TaskStateType*              TaskStateRefType;
typedef osCpuTaskAddressType        osTaskAddressType;
typedef osTaskAddressType*          osTaskAddressRefType; /*MISRA RULE 2.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
typedef osuint8                     ResourceType;
typedef osuint64                    EventMaskType;
typedef EventMaskType*              EventMaskRefType;
typedef osuint8                     AlarmType;
typedef AlarmType*                  AlarmRefType; /*MISRA RULE 2.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
typedef osuint32                    TickType;
typedef TickType*                   TickRefType;
typedef osuint16                    CounterType;
typedef osuint8                     TaskPriorityType;
typedef TaskPriorityType*           TaskPriorityRefType; /*MISRA RULE 2.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
typedef osCpuTaskPriorityBitType    TaskPriorityBitType;
typedef osuint16                    ErrReasonType;
typedef ErrReasonType*              ErrReasonRefType;
typedef osCpuIntGlobalType          osIntGlobaltype;
typedef osuint32                    PhysicalTimeType; /*MISRA RULE 2.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
typedef osuint32                    ISRType;
typedef osuint8                     AppModeType;
typedef osuint8                     ProtectionReturnType; /*MISRA RULE 2.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
typedef osuint8                     osActivationCntType;
typedef osuint16                    CoreIdType;
typedef osuint8                     CoreStateType;
typedef osuint8                     CoreTypeType; /*MISRA RULE 2.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
typedef osuint8                     ApplicationType;
typedef osuint8                     ApplicationStateType;
typedef ApplicationStateType*       ApplicationStateRefType;
typedef osuint8                     ObjectTypeType;
typedef osuint8                     ObjectAccessType;
typedef osuint8                     AccessType;
typedef osuint8                     AccessLevelType;   // Privileged or Un-Privileged
typedef osuint32                    ObjectIdType;           //mos defined type to index the objects
typedef osuint32                    AccessRightsIdType;
typedef osuint16                    TrustedFunctionIndexType;
typedef void *                      TrustedFunctionParameterRefType;
typedef osuint16                    IRQSourceType;
typedef osuint16                    IRQPrioLevelType;
typedef osCpuMemoryAddressType      MemoryStartAddressType;
typedef osCpuMemoryAddressType      MemorySizeType;
typedef osuint8                     RestartType;
typedef osuint32                    OsServiceIdType;

typedef void                        (*osTaskFuncRefType)(void);
typedef void                        (*osVoidFunctionType)(void);
typedef void                        (*TrustedFunctionType)(TrustedFunctionIndexType FnIndex, TrustedFunctionParameterRefType FnParam);

typedef struct
{
    TickType            MaxAllowedVal;
    TickType            TicksPerBase;
    TickType            MinCycle;
}AlarmBaseType;

typedef AlarmBaseType*  AlarmBaseRefType;


typedef struct
{
    TaskType            CallingTask;
    StatusType          LastErrReason;
    StatusType          ErrReason;
    osuint32            ExceptionDetails;
    OsServiceIdType     OsServiceId;
}osErrParamType;

#define osdCtxTask                        0x0001
#define osdCtxISRCat2                     0x0002
#define osdCtxPreTaskHook                 0x0004 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define osdCtxPostTaskHook                0x0008 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define osdCtxErrorHook                   0x0010 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define osdCtxApplErrorHook               0x0020 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define osdCtxEachErrorHook               0x0030 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define osdCtxStartupHook                 0x0040 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define osdCtxShutdownHook                0x0080 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define osdCtxProtectionHook              0x0100 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define osdCtxCOMErrorHook                0x0200 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define osdCtxCOMCallback                 0x0400 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define osdCtxStartComExtens              0x0800 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define osdCtxErrorHookFromStartupHook    0x1000 /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/



#define CORE_NOT_STARTED        0U
#define CORE_STARTED            1U
#define CORE_INVALID_STATE      0xFFU /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

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
