/**
 * @file        OsMetrics.c
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
 * @details     <b>mOs  file for calculating os metrics</b>
 * @note
 *              Compiler    : IAR \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef OS_METRICS_C
#define OS_METRICS_C

#include "OsMetrics.h"
#include "OsPrivate.h"
#include "Gpt.h"

#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define OS_METRICS_ARRAY_SIZE_ONE        1
#define OS_METRICS_ARRAY_SIZE_TWO        2
#define OS_METRICS_ARRAY_SIZE_THREE      3


osMetricType osMetrics[osMetricsMaxCount];
osMetricsType osMetricsData; 

/**
 * @brief OsGetTimerCount - Function to get the timer count
 *
 * @param  None
 * @return osuint32
 */

osuint32  OsGetTimerCount(void)
{
	osuint32  time=0;
        #ifdef mOS_SUPPORT_INTERNAL_METRICS
        time = Gpt_GetTimeElapsed(OsMetricsTimer);
        time=time/OsMetricsTimerFrequency;
        #endif
        return time;
   
}

/**
 * @brief OsGetStartTaskMetrics - Function to get the time required for starting the task
 *
 * @param  None
 * @return void
 */

void OsGetStartTaskMetrics(void)
{
    OsGetContextSwitchMetrics();    
    if (osMetrics[0].ValFlag != FALSE)
    {
        osMetrics[0].EndTime = OsGetTimerCount();
        osMetrics[0].ValFlag = FALSE;
        osMetricsData.StartTaskMetrics=osMetrics[0].EndTime-osMetrics[0].StartTime;
    }
}

/**
 * @brief OsGetResumeTaskMetrics - Function to get the time required for resuming a task
 *
 * @param  None
 * @return void
 */

void OsGetResumeTaskMetrics(void)
{
    OsGetContextSwitchMetrics();  
    if (osMetrics[OS_METRICS_ARRAY_SIZE_ONE].ValFlag != FALSE)
    {
        osMetrics[OS_METRICS_ARRAY_SIZE_ONE].EndTime = OsGetTimerCount();
        osMetrics[OS_METRICS_ARRAY_SIZE_ONE].ValFlag = FALSE;
        osMetricsData.ResumeTaskMetrics=osMetrics[OS_METRICS_ARRAY_SIZE_ONE].EndTime-osMetrics[OS_METRICS_ARRAY_SIZE_ONE].StartTime;
    }
}

/**
 * @brief OsGetContextSwitchMetrics - Function to get the time required for context switching
 *
 * @param  None
 * @return void
 */

void OsGetContextSwitchMetrics(void)
{
    if (osMetrics[OS_METRICS_ARRAY_SIZE_TWO].ValFlag != FALSE)
    {
        osMetrics[OS_METRICS_ARRAY_SIZE_TWO].EndTime = OsGetTimerCount();
        osMetrics[OS_METRICS_ARRAY_SIZE_TWO].ValFlag = FALSE;
        osMetricsData.TaskContextSwitchingMetrics=osMetrics[OS_METRICS_ARRAY_SIZE_TWO].EndTime-osMetrics[OS_METRICS_ARRAY_SIZE_TWO].StartTime;
    }
}

/**
 * @brief OsGetOsInitMetrics - Function to get the time required for os initialisation
 *
 * @param  None
 * @return void
 */

void OsGetOsInitMetrics(void)
{
    if (osMetrics[OS_METRICS_ARRAY_SIZE_THREE].ValFlag != FALSE)
    {
        osMetrics[OS_METRICS_ARRAY_SIZE_THREE].EndTime = OsGetTimerCount();
        osMetrics[OS_METRICS_ARRAY_SIZE_THREE].ValFlag = FALSE;
        osMetricsData.OsInitMetrics=osMetrics[OS_METRICS_ARRAY_SIZE_THREE].EndTime-osMetrics[OS_METRICS_ARRAY_SIZE_THREE].StartTime;
    }
}

/**
 * @brief OsStartDispatchMetric - Function to dispatch metric
 *
 * @param  None
 * @return void
 */

void OsStartDispatchMetric(void)
{
    
    #ifdef mOS_SUPPORT_INTERNAL_METRICS
    TaskType ReqTask = OsCtrlParam.RequestedTaskIndex;
    //start measurement for task resuming
    //skip if we are going to idle task
    if (ReqTask != INVALID_TASK)
    {
        if(PRE_READY != TcbTaskRefConfig[ReqTask]->TaskParamRef->State)
        {
            osMetrics[OS_METRICS_ARRAY_SIZE_ONE].StartTime =OsGetTimerCount(); 
            osMetrics[OS_METRICS_ARRAY_SIZE_ONE].ValFlag = TRUE;
        }
        //context switching time
        osMetrics[OS_METRICS_ARRAY_SIZE_TWO].StartTime = OsGetTimerCount();
        osMetrics[OS_METRICS_ARRAY_SIZE_TWO].ValFlag = TRUE;
    }
    #endif
}

#define OS_CORE_CODE_SEC_END
#define OS_CORE_CONST_SEC_END
#define OS_CORE_DATA_SEC_END
#define OS_CORE_BSS_SEC_END
#include "Os_IntMemMap.h"

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
**   Date              : 27-June-2022                                               **
**   CDSID             : pmathew                                                    **
**   RTC Id            : 1586146                                                    **
**   Change Description: Change Description: mOS updations for supporting user mode **
**----------------------------------------------------------------------------------**/
