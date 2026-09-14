/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2012. Visteon Corporation owns all rights to           *
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
*  File Name         :  MemTrace.h                                           *
*  Module Short Name :  MemTrace                                             *
*  VOBName           :                                                       *
*  Author            :                                                       *
*  Description       :                                                       *
*                                                                            *
*  Organization      :  Driver Information Software Section,                 *
*                       Visteon Software Operation                           *
*                       Visteon Corporation                                  *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/
#ifndef MEM_TRACE_H
#define MEM_TRACE_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "NvM_Cfg.h"
#include "Fee_Cfg.h"
#include "MemTrace_Cfg.h"

#define MEM_TRACE_ENABLED // Shuold be disabled in base
#ifdef MEM_TRACE_ENABLED


/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define TOTAL_NVM_BLOCKS                        NVM_NUM_OF_BLOCKS+1

#define TOTAL_FEE_PARTITION                     FEE_NUM_PARTITIONS

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef uint32 MemTrace_TimeType;

typedef struct 
{
    MemTrace_TimeType    	StartTimeStamp;
    MemTrace_TimeType       CollectedTime;
    MemTrace_TimeType       MinJobTime;
    MemTrace_TimeType       MaxJobTime;
    MemTrace_TimeType       TotalJobTime;
    uint32                  JobCount;
}MemTrace_JobMeasurementType;

typedef struct 
{
    MemTrace_JobMeasurementType       NvmJobRead;
    MemTrace_JobMeasurementType       NvmJobWrite;
}MemTrace_NvmBlockMeasurementType;

typedef struct 
{
    MemTrace_JobMeasurementType     NvmJob_ReadAll;
    MemTrace_JobMeasurementType     NvmJob_WriteAll;
}MemTrace_NvmMultiBlockMeasurementType;

typedef enum
{
    TRACE_UNINIT,
    TRACE_RUNNING,
} MemTraceStatusType;

// typedef struct 
// {
    
// }

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/
/**************************************************************************
Function name   : void MemTrace_Init(void)
Arguments       : void
Return type     : void
Description     : 
**************************************************************************/
extern void MemTrace_Init (void);

/**************************************************************************
Function name   : void MemTrace_NvmJobStartHook(uint8 JobId, uint16 BlockId)
Arguments       : void
Return type     : void
Description     : 
**************************************************************************/
extern void MemTrace_NvmJobStartHook (uint8 JobId, uint16 BlockId);

/**************************************************************************
Function name   : void MemTrace_NvmJobEndHook(uint8 JobId, uint16 BlockId)
Arguments       : void
Return type     : void
Description     : 
**************************************************************************/
extern void MemTrace_NvmJobEndHook (uint8 JobId, uint16 BlockId);

/**************************************************************************
Function name   : void MemTrace_FeeJobHook(uint8 JobId, uint8 PartitionId)
Arguments       : void
Return type     : void
Description     : 
**************************************************************************/
extern void MemTrace_FeeJobHook (uint8 JobId, uint8 PartitionId);

#endif /* MEM_TRACE_ENABLED */

#endif /* MEM_TRACE_H */
/****************************************************************************
*     End of File
*
****************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 21-02-2022                                            */
/*Version           :                                                       */
/*By                : jponsing                                              */
/*Traceability      :                                                       */
/*Change Description: Initial Version                                       */
/*--------------------------------------------------------------------------*/