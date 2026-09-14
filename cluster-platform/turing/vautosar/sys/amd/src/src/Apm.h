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
*  File Name         :  APM.h                                                *
*  Module Short Name :  APM_H                                                *
*  Description       :                                                       *
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
#ifndef APM_H
#define APM_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
#include "Apm_Types.h"
#include "Apm_PrivateCfg.h"
#include "Apm_Cfg.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#ifdef APM_ENABLED
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                               Functions                                    *
******************************************************************************/

/*============================================================================
**
** Function Name    :   Apm_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global
**                      and Static variables of this module.
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

extern void Apm_Init (void);

/*============================================================================
**
** Function Name    :   Apm_PreTaskProcess
**
** Visibility       :   Public
**
** Description      :   This function signals the start of a Task.
**
** Invocation       :
**
** Inputs           :   TaskId - Id of the Task that is strating
**                      TaskState - State of the Task that is starting
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

extern void Apm_PreTaskProcess (TaskType TaskId,  TaskStateType TaskState);

/*============================================================================
**
** Function Name    :   Apm_PostTaskProcess
**
** Visibility       :   Public
**
** Description      :   This function signals the end of a Task.
**
** Invocation       :
**
** Inputs           :   TaskId - Id of the Task that is ending
**                      TaskState - State of the Task that is ending
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

extern void Apm_PostTaskProcess (TaskType TaskId, TaskStateType TaskState);

/*============================================================================
**
** Function Name    :   Apm_PreIsrProcess
**
** Visibility       :   Public
**
** Description      :   This function signals the start of an ISR.
**
** Invocation       :
**
** Inputs           :   x - Id of the ISR that is starting
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

extern void Apm_PreIsrProcess (ISRType x);

/*============================================================================
**
** Function Name    :   Apm_PostIsrProcess
**
** Visibility       :   Public
**
** Description      :   This function signals the end of an ISR.
**
** Invocation       :
**
** Inputs           :   x - Id of the ISR that is ending
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

extern void Apm_PostIsrProcess (ISRType x);

/*============================================================================
**
** Function Name    :   Apm_PreRunnableProcess
**
** Visibility       :   Public
**
** Description      :   This function signals the start of a Runnable.
**
** Invocation       :
**
** Inputs           :   RunnableId - Id of the Runnable that is starting
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

extern void Apm_PreRunnableProcess (uint8 RunnableId);

/*============================================================================
**
** Function Name    :   Apm_PostRunnableProcess
**
** Visibility       :   Public
**
** Description      :   This function signals the end of a Runnable.
**
** Invocation       :
**
** Inputs           :   RunnableId - Id of the Runnable that is ending
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

extern void Apm_PostRunnableProcess (uint8 RunnableId);

/*============================================================================
**
** Function Name    :   Apm_PreCheckpointProcess
**
** Visibility       :   Public
**
** Description      :   This function signals the start of a Cyclic Checkpoint.
**
** Invocation       :
**
** Inputs           :   CheckpointId - Id of the Checkpoint that is starting
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

extern void Apm_PreCheckpointProcess (uint8 CheckpointId);

/*============================================================================
**
** Function Name    :   Apm_PostCheckpointProcess
**
** Visibility       :   Public
**
** Description      :   This function signals the end of a Cyclic Checkpoint.
**
** Invocation       :
**
** Inputs           :   CheckpointId - Id of the Checkpoint that is ending
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

extern void Apm_PostCheckpointProcess (uint8 CheckpointId);

/*============================================================================
**
** Function Name    :   Apm_MainFunction
**
** Visibility       :   Public
**
** Description      :   This function periodically calculates the CPU load.
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

extern void Apm_MainFunction (void);

/*============================================================================
**
** Function Name    :   Apm_StartMeasurement
**
** Visibility       :   Public
**
** Description      :   Function that allows the measurement data to be
**                      processed.
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

extern void Apm_StartMeasurement (void);

/*============================================================================
**
** Function Name    :   Apm_StopMeasurement
**
** Visibility       :   Public
**
** Description      :   Function that denies the measurement data to be
**                      processed.
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

extern void Apm_StopMeasurement (void);

/*============================================================================
**
** Function Name    :   Apm_SaveStartupMarker
**
** Visibility       :   Public
**
** Description      :   This function signals the reaching of a Marker.
**
** Invocation       :
**
** Inputs           :   MarkerId - Id of the Marker that is being reached
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/

extern void Apm_SaveStartupMarker (uint8 MarkerId);

/**
 ** @brief Stores the TimeStamp on Entering the Critical Section
 ** 
 */
extern void Apm_StartCSMeasurement(void);

/**
 ** @brief  Updates the Task Measurement Object with Max and Min time spent in CS section 
 ** 
 */
extern void Apm_EndCSMeasurement(void);

#endif /* APM_ENABLED */
#endif
/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*---------------------------------------------------------------------------
Date               : 23-Feb-2016
CDSID              : ssebast1
Traceability       : RTC #527207
Change Description : Initial Framework version of Apm
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
