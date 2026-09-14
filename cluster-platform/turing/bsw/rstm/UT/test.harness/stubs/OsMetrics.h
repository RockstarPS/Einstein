/**
 * @file        OsMetrics.h
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
 * @details     <b>This file externs the generic APIs of the OS</b>
 * @note
 *              Compiler    : Independent \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */
#ifndef OS_METRICS_H
#define OS_METRICS_H


#include "OsPrvTypes.h"

#define osMetricsMaxCount 4U


extern osuint32 OsGetTimerCount(void);
extern void OsStartDispatchMetric(void);
extern void OsGetStartTaskMetrics(void);
extern void OsGetResumeTaskMetrics(void);
extern void OsGetContextSwitchMetrics(void);
extern void OsGetOsInitMetrics(void);

typedef struct
{
    osuint32            StartTime;
    osuint32            EndTime;
    osbool              ValFlag;
}osMetricType;

typedef struct
{
    osuint32    StartTaskMetrics;
    osuint32    OsInitMetrics;
    osuint32    ResumeTaskMetrics;
    osuint32    TaskContextSwitchingMetrics;
    
}osMetricsType;


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
**   Change Description: mOS updations for supporting user mode                     **
**----------------------------------------------------------------------------------**/


#endif
