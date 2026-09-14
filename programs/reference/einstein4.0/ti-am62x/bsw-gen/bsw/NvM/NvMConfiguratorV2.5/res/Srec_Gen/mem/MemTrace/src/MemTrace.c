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
*  File Name         :  MemTrace.c                                           *
*  Module Short Name :  MemTrace                                             *
*  VOBName           :                                                       *
*  Author            :                                                       *
*  Description       :                                                       *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/
#ifndef MEM_TRACE_C
#define MEM_TRACE_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "MemTrace.h"
#include "NvM.h"
#include "Fee.h"
#ifdef MEM_TRACE_ENABLED

/*****************************************************************************
*                    Locally used Variable Declarations                      *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

static MemTrace_NvmBlockMeasurementType         MemTrace_NvmBlockMeasurement[TOTAL_NVM_BLOCKS];

static MemTrace_NvmMultiBlockMeasurementType    MemTrace_NvmMultiBlockMeasurement;

static MemTrace_JobMeasurementType              MemTrace_FeeSectorSwitchMeasurement[TOTAL_FEE_PARTITION];

static MemTraceStatusType                       MemTraceStatus = TRACE_UNINIT;

static boolean                                  MemTrace_FeeMeasurementFlag;


/*****************************************************************************
*                   Functions                                                *
******************************************************************************/
/**************************************************************************
Function name   : void MemTrace_Init(void)
Arguments       : void
Return type     : void
Description     : 
**************************************************************************/
void MemTrace_Init (void)
{
    uint8 fl_iteration; 

    for (fl_iteration = 0; fl_iteration < TOTAL_NVM_BLOCKS; fl_iteration++)
    {
        MemTrace_NvmBlockMeasurement[fl_iteration].NvmJobRead.StartTimeStamp = 0u;
        MemTrace_NvmBlockMeasurement[fl_iteration].NvmJobRead.CollectedTime = 0u;
        MemTrace_NvmBlockMeasurement[fl_iteration].NvmJobRead.MinJobTime = 0xFFFFFFFFUL;
        MemTrace_NvmBlockMeasurement[fl_iteration].NvmJobRead.MaxJobTime = 0u;
        MemTrace_NvmBlockMeasurement[fl_iteration].NvmJobRead.TotalJobTime = 0u;
        MemTrace_NvmBlockMeasurement[fl_iteration].NvmJobRead.JobCount =0u;

        MemTrace_NvmBlockMeasurement[fl_iteration].NvmJobWrite.StartTimeStamp = 0u;
        MemTrace_NvmBlockMeasurement[fl_iteration].NvmJobWrite.CollectedTime = 0u;
        MemTrace_NvmBlockMeasurement[fl_iteration].NvmJobWrite.MinJobTime = 0xFFFFFFFFUL;
        MemTrace_NvmBlockMeasurement[fl_iteration].NvmJobWrite.MaxJobTime = 0u;
        MemTrace_NvmBlockMeasurement[fl_iteration].NvmJobWrite.TotalJobTime = 0u;
        MemTrace_NvmBlockMeasurement[fl_iteration].NvmJobWrite.JobCount =0u;
    }

    MemTrace_NvmMultiBlockMeasurement.NvmJob_ReadAll.StartTimeStamp = 0u;
    MemTrace_NvmMultiBlockMeasurement.NvmJob_ReadAll.CollectedTime = 0u;
    MemTrace_NvmMultiBlockMeasurement.NvmJob_ReadAll.MinJobTime = 0xFFFFFFFFUL;
    MemTrace_NvmMultiBlockMeasurement.NvmJob_ReadAll.MaxJobTime = 0u;
    MemTrace_NvmMultiBlockMeasurement.NvmJob_ReadAll.TotalJobTime = 0u;
    MemTrace_NvmMultiBlockMeasurement.NvmJob_ReadAll.JobCount =0u;

    MemTrace_NvmMultiBlockMeasurement.NvmJob_WriteAll.StartTimeStamp = 0u;
    MemTrace_NvmMultiBlockMeasurement.NvmJob_WriteAll.CollectedTime = 0u;
    MemTrace_NvmMultiBlockMeasurement.NvmJob_WriteAll.MinJobTime = 0xFFFFFFFFUL;
    MemTrace_NvmMultiBlockMeasurement.NvmJob_WriteAll.MaxJobTime = 0u;
    MemTrace_NvmMultiBlockMeasurement.NvmJob_WriteAll.TotalJobTime = 0u;
    MemTrace_NvmMultiBlockMeasurement.NvmJob_WriteAll.JobCount =0u;

    for (fl_iteration = 0; fl_iteration < TOTAL_FEE_PARTITION; fl_iteration++)
    {
        MemTrace_FeeSectorSwitchMeasurement[fl_iteration].StartTimeStamp = 0u;
        MemTrace_FeeSectorSwitchMeasurement[fl_iteration].CollectedTime = 0u;
        MemTrace_FeeSectorSwitchMeasurement[fl_iteration].MinJobTime = 0xFFFFFFFFUL;
        MemTrace_FeeSectorSwitchMeasurement[fl_iteration].MaxJobTime = 0u;
        MemTrace_FeeSectorSwitchMeasurement[fl_iteration].TotalJobTime = 0u;
        MemTrace_FeeSectorSwitchMeasurement[fl_iteration].JobCount =0u;
    }
    MemTrace_FeeMeasurementFlag = FALSE;
    MemTraceStatus = TRACE_RUNNING;
}

/**************************************************************************
Function name   : void MemTrace_NvmJobStartHook(uint8 JobId, uint16 BlockId)
Arguments       : void
Return type     : void
Description     : 
**************************************************************************/
void MemTrace_NvmJobStartHook (uint8 JobId, uint16 BlockId)
{
    MemTrace_TimeType fl_currentTime;
    GET_CURRENT_TIME(&fl_currentTime);
    if (TRACE_UNINIT == MemTraceStatus)
    {
        MemTrace_Init();
    }
    switch (JobId)
    {
        case NVM_READ_BLOCK:
            MemTrace_NvmBlockMeasurement[BlockId].NvmJobRead.StartTimeStamp = fl_currentTime;
            MemTrace_NvmBlockMeasurement[BlockId].NvmJobRead.CollectedTime = 0u;
        break;

        case NVM_WRITE_BLOCK:
            MemTrace_NvmBlockMeasurement[BlockId].NvmJobWrite.StartTimeStamp = fl_currentTime;
            MemTrace_NvmBlockMeasurement[BlockId].NvmJobWrite.CollectedTime = 0u;
        break;

        case NVM_READ_ALL:
            MemTrace_NvmMultiBlockMeasurement.NvmJob_ReadAll.StartTimeStamp = fl_currentTime;
            MemTrace_NvmMultiBlockMeasurement.NvmJob_ReadAll.CollectedTime = 0u;
        break;

        case NVM_WRITE_ALL:
            MemTrace_NvmMultiBlockMeasurement.NvmJob_WriteAll.StartTimeStamp = fl_currentTime;
            MemTrace_NvmMultiBlockMeasurement.NvmJob_WriteAll.CollectedTime = 0u;
        break;

        default: 
            //Do Nothing
        break;
    }
}

/**************************************************************************
Function name   : void MemTrace_NvmJobEndHook(uint8 JobId, uint16 BlockId)
Arguments       : void
Return type     : void
Description     : 
**************************************************************************/
void MemTrace_NvmJobEndHook (uint8 JobId, uint16 BlockId)
{
    MemTrace_JobMeasurementType *fl_MemTrace_JobMeasurementPtr;
    fl_MemTrace_JobMeasurementPtr = NULL;
    MemTrace_TimeType fl_currentTime;
    GET_CURRENT_TIME(&fl_currentTime);
    if (TRACE_UNINIT == MemTraceStatus)
    {
        MemTrace_Init();
    }
    switch (JobId)
    {
        case NVM_READ_BLOCK:
            fl_MemTrace_JobMeasurementPtr = &MemTrace_NvmBlockMeasurement[BlockId].NvmJobRead; 
        break;

        case NVM_WRITE_BLOCK:
            fl_MemTrace_JobMeasurementPtr = &MemTrace_NvmBlockMeasurement[BlockId].NvmJobWrite;
        break;

        case NVM_READ_ALL:
            fl_MemTrace_JobMeasurementPtr = &MemTrace_NvmMultiBlockMeasurement.NvmJob_ReadAll;
        break;

        case NVM_WRITE_ALL:
            fl_MemTrace_JobMeasurementPtr = &MemTrace_NvmMultiBlockMeasurement.NvmJob_WriteAll;
        break;

        default: //Do Nothing
        break;
    }
    if (NULL != fl_MemTrace_JobMeasurementPtr)
    {
        (*fl_MemTrace_JobMeasurementPtr).CollectedTime += fl_currentTime - (*fl_MemTrace_JobMeasurementPtr).StartTimeStamp;
        (*fl_MemTrace_JobMeasurementPtr).TotalJobTime += (*fl_MemTrace_JobMeasurementPtr).CollectedTime;
        (*fl_MemTrace_JobMeasurementPtr).JobCount += 1u;
        if ((*fl_MemTrace_JobMeasurementPtr).CollectedTime > (*fl_MemTrace_JobMeasurementPtr).MaxJobTime)
        {
            (*fl_MemTrace_JobMeasurementPtr).MaxJobTime = (*fl_MemTrace_JobMeasurementPtr).CollectedTime;
        }
        if ((*fl_MemTrace_JobMeasurementPtr).CollectedTime < (*fl_MemTrace_JobMeasurementPtr).MinJobTime)
        {
            (*fl_MemTrace_JobMeasurementPtr).MinJobTime = (*fl_MemTrace_JobMeasurementPtr).CollectedTime;
        }
    }
}

/**************************************************************************
Function name   : void MemTrace_FeeJobHook(uint8 JobId, uint8 PartitionId)
Arguments       : void
Return type     : void
Description     : 
**************************************************************************/
void MemTrace_FeeJobHook (uint8 JobId, uint8 PartitionId)
{
    MemTrace_TimeType fl_currentTime;
    GET_CURRENT_TIME(&fl_currentTime);
    if (TRACE_UNINIT == MemTraceStatus)
    {
        MemTrace_Init();
    }
    switch (JobId)
    {
        case FEE_START_INTERNAL_JOB:
            if (!MemTrace_FeeMeasurementFlag)
            {
                MemTrace_FeeSectorSwitchMeasurement[PartitionId].StartTimeStamp = fl_currentTime;
                MemTrace_FeeSectorSwitchMeasurement[PartitionId].CollectedTime = 0u;
                MemTrace_FeeMeasurementFlag = TRUE;
            }
        break;

        case FEE_END_INTERNAL_JOB:
            if (MemTrace_FeeMeasurementFlag)
            {
                MemTrace_FeeSectorSwitchMeasurement[PartitionId].CollectedTime += \
                    fl_currentTime - MemTrace_FeeSectorSwitchMeasurement[PartitionId].StartTimeStamp;
                MemTrace_FeeSectorSwitchMeasurement[PartitionId].TotalJobTime += MemTrace_FeeSectorSwitchMeasurement[PartitionId].CollectedTime;
                MemTrace_FeeSectorSwitchMeasurement[PartitionId].JobCount += 1u;
                if(MemTrace_FeeSectorSwitchMeasurement[PartitionId].CollectedTime > MemTrace_FeeSectorSwitchMeasurement[PartitionId].MaxJobTime)
                {
                    MemTrace_FeeSectorSwitchMeasurement[PartitionId].MaxJobTime = MemTrace_FeeSectorSwitchMeasurement[PartitionId].CollectedTime;
                }
                if(MemTrace_FeeSectorSwitchMeasurement[PartitionId].CollectedTime < MemTrace_FeeSectorSwitchMeasurement[PartitionId].MinJobTime)
                {
                    MemTrace_FeeSectorSwitchMeasurement[PartitionId].MinJobTime = MemTrace_FeeSectorSwitchMeasurement[PartitionId].CollectedTime;
                }
                MemTrace_FeeMeasurementFlag = FALSE;
            }
        break;

        case FEE_SUSPEND_INTERNAL_JOB:
            if (MemTrace_FeeMeasurementFlag)
            {
                MemTrace_FeeSectorSwitchMeasurement[PartitionId].CollectedTime += \
                    fl_currentTime - MemTrace_FeeSectorSwitchMeasurement[PartitionId].StartTimeStamp;
                MemTrace_FeeMeasurementFlag = FALSE;
            }
        break;

        case FEE_RESUME_INTERNAL_JOB:
            if (!MemTrace_FeeMeasurementFlag)
            {
                MemTrace_FeeSectorSwitchMeasurement[PartitionId].StartTimeStamp = fl_currentTime;
                MemTrace_FeeMeasurementFlag = TRUE;
            }
        break;

        default: //Do Nothing
        break;
    }
}

#endif /* MEM_TRACE_ENABLED */

#endif /* MEM_TRACE_C */
/*****************************************************************************
*     End of File
*
*******************************************************************************/
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
/*Traceability      : 1701335                                               */
/*Change Description: Initial Version                                       */
/*--------------------------------------------------------------------------*/