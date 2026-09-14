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
*  File Name         :  Apm_Cfg.h                                            *
*  Module Short Name :  Apm_Cfg_H                                            *
*  Description       :  This is a generated file.                            *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef APM_CFG_H
#define APM_CFG_H

/* APM_ENABLED: Define this macro if you need to take measurement */
#ifdef APM_ENABLED
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Stubs.h"
#include "Os.h"
#include "Gpt.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define APM_NUMBER_OF_TASKS                                     OsNumberOfTasks
#define APM_TASK_MEASUREMENT_ENTRY_COUNT                        (10000u)

#define APM_NUMBER_OF_ISRS                                      OsNumberOfIsr
#define APM_ISR_MEASUREMENT_ENTRY_COUNT                         (10000u)

#define APM_NUMBER_OF_RUNNABLES                                 (0) // eRunnable_Count from DbgExt_Runnables.h
#define APM_RUNNABLES_MEASUREMENT_ENTRY_COUNT                   (50u)

#define APM_NUMBER_OF_CHECKPOINTS                               (0)  // eCustomPeriodicActionCount from DbgExt.h
#define APM_CHECKPOINTS_MEASUREMENT_ENTRY_COUNT                 (50u)

#define APM_NUMBER_OF_STARTUP_MARKERS                           (0)  // eMarkerIdCount from DbgExt.h

#define APM_MEASUREMENT_COLLECTION_ALLOCATION_START
#define APM_MEASUREMENT_COLLECTION_ALLOCATION_END

#define APM_TASK_ID                                             (TaskName_1)

#define APM_GPT_FREQ_IN_MHZ					                    (25u)
#define APM_GPT_SRC                                             GptConf_GptChannelConfiguration_MCU_TIMER1
#define APM_GET_CURRENT_TIME()                                  Gpt_GetTimeElapsed(APM_GPT_SRC)

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                     Externally used Variable Declarations                  *
******************************************************************************/

/*****************************************************************************
*                          Limited Scope Prototypes                          *
******************************************************************************/

/*****************************************************************************
*                               Functions                                    *
******************************************************************************/
void Apm_EnterCriticalSection(void);

void Apm_ExitCriticalSection(void);

#endif /* APM_ENABLED*/
#endif
