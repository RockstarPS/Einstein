/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2019. Visteon Corporation owns all rights to           *
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
*  File Name         :  OsScheduleTable_Cfg.h                                *
*  Module Short Name :  OsScheduleTable_Cfg                                  *
*  Description       :  This file contains the configuration parameters of   *
*                       Os Schedule Table                                    *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "OsMain.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#ifndef OSSCHEDULETABLE_CFG_H
#define OSSCHEDULETABLE_CFG_H


#define ST_NUMBER_OF_SCHEDULE_TABLES	1
#define ST0_NUMBER_OF_EXPIRY_POINTS		1
#define ST1_NUMBER_OF_EXPIRY_POINTS		0
#define ST2_NUMBER_OF_EXPIRY_POINTS		0

#define SCHEDULETABLE_RESET_OSCOUNTER(x)     (void)osResetCounter(x)
#define OS_DET_REPORT_ERROR()

#define MainScheduleTable_SampleApplicationTask_10ms  0
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef struct
{
	TaskType							TaskId;
}ExpiryPointTaskListType;

typedef struct
{
	TaskType							TaskId;
	EventMaskType						EventMask;
}ExpiryPointEventListType;

typedef struct
{
	osuint32							NumberOfTasks;
	osuint32 							NumberOfEvents;
	const ExpiryPointTaskListType*			ExpiryPointTaskList;
	ExpiryPointEventListType*			ExpiryPointEventList;
	TickType							Offset;

}ExpiryPointConfigType;

typedef enum
{
	SCHEDULETABLE_SINGLESHOT = 0,
	SCHEDULETABLE_CONTINOUS
}ScheduleTableKindType;

/* EXPLICIT SYNC not supported */
typedef enum
{
	SCHEDULETABLE_NOSYNC = 0,
	SCHEDULETABLE_SYNC_IMPLICIT,
    SCHEDULETABLE_SYNC_EXPLICIT
}ScheduleTableSyncType;

typedef struct
{
    osuint8     						AutoStartEnabled;
    const ExpiryPointConfigType*     	ExpiryPointListRef;
	ScheduleTableKindType				Kind;
	CounterType							Counter;
	osuint32							NumberOfExpiryPoints;
	TickType							FinalDelay;
    ScheduleTableSyncType               Sync;
}ScheduleTableConfigType;


/*****************************************************************************
*                                 External Variables                         *
*---------------------------------------------------------------------------*/
extern const ExpiryPointTaskListType		ExpiryPoint0_TaskList[1];

extern const ExpiryPointConfigType       	ExpiryPointConfigParam_ST0[ST0_NUMBER_OF_EXPIRY_POINTS];

extern const ScheduleTableConfigType        ScheduleTableConfigParam[ST_NUMBER_OF_SCHEDULE_TABLES];

/*****************************************************************************
*                                 External APIs                              *
******************************************************************************/
#endif /* OSSCHEDULETABLE_H */

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
**   Date              : 26-Jul-19  												**
**   CDSID             : ssebast1                                                   **
**   Traceability      :------------                                                **
**   RTC Version       : ------                                                     **
**   Change Description: Initial version.                                           **
**   ------------------------------------------------------------------------------ **
**----------------------------------------------------------------------------------*/
