/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2026 by Visteon Corporation.       All rights reserved.         
*                                                                                                                    
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                   
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve              
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States     
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,             
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its       
* rights under all copyright laws to protect this work as a published work, when appropriate.                        
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it   
* without the written authorization of Visteon Corporation.                                                          
********************************************************************************************************************/

/*******************************************************************************************************************
*    @file WdgM_Cfg.h
*    @ingroup WdgM Configuration
*    @brief This is WdgM Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the WdgM module.
*    Auto generated code in vAUTOSAR TOOL by ABASAVAR at 2026-08-04 14:40:34.219642200
********************************************************************************************************************/

#ifndef WDGM_CFG_H
#define WDGM_CFG_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "WdgIf_Cfg.h"
#include "Stubs.h"
#include "Std_Types.h"
#include "Os.h"
#include "Wdg.h"

/*****************************************************************************
*  						 	 Version Information                             *
******************************************************************************/
/* Software Version */
#define WDGM_CFG_SW_MAJOR_VERSION                                     1U
#define WDGM_CFG_SW_MINOR_VERSION                                     0U
#define WDGM_CFG_SW_PATCH_VERSION                                     0U
/* Autosar Release */
#define WDGM_CFG_AR_RELEASE_MAJOR_VERSION                             4U
#define WDGM_CFG_AR_RELEASE_MINOR_VERSION                             3U
#define WDGM_CFG_AR_RELEASE_REVISION_VERSION                          1U
/*****************************************************************************
*                            Macro Definitions                          	 *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/* Pre-Condition Macro to support Immediate Micro Reset */
#define WDGM_IMMEDIATE_RESET                                          STD_ON
#define WDGM_VERSION_INFO_API                                         STD_OFF
#define WDGM_POSTUBILD_VARIANT_SUPPORT                                STD_OFF
/* Pre-Condition Macro to Enable OFF MODE */
#define WDGM_OFF_MODE_ENABLED                                         STD_ON
/* Macro defining the periodicity of WdgM_MainFunction */
#define WDGM_NO_OF_DEADLINE_TRANSITIONS                               1U
#define WDGM_NO_OF_DEADLINE_ENTITIES                                  1U
#define WDGM_NO_OF_ALIVE_ENTITIES                                     4U
#define WDGM_NO_OF_WDG_DEVICES                                        1U
#define WDGM_NO_OF_SUPERVISION_ENTITIES                               1U
#define WDGM_NO_OF_CONFIGURATION_VARIANTS                             1U
#define WDGM_DEV_ERROR_DETECT                                         STD_ON
/* Maximum Timeout value in mS to be given for Watchdog while deinit */
typedef uint16 WdgM_CheckpointIdType;
typedef uint16 WdgM_SupervisedEntityIdType;
typedef uint8 WdgM_ModeType;
typedef uint8 WdgM_LocalStatusType;
typedef uint8 WdgM_GlobalStatusType;
#define WDGM_CHECKPOINT_ERROR_HOOK(X)                                 

/*****************************************************************************
*                            Type Declarations                          	 *
******************************************************************************/

/* Alive Supervision Configuration Parameters */
typedef struct 
{
    /* Expected Alive Indication Counts */
    uint16      ExpectedAliveIndications;
    /* Maximum Allowed Margin for Alive indication */
    uint8      MaxMargin;
    /* Minimum Allowed Margin for Alive indication */
    uint8      MinMargin;
    /* Count at which the Alive Examination shall be performed */
    uint16      SupervisionReferenceCycle;

}WdgMAliveSupervisionType;

/* Deadline Transition Configuration Parameters */
typedef struct 
{
    /* No of Transitions. 0 if no transisions for this CP */
    uint8      NrOfTransitions;
    /* Transition Index */
    uint8      TransitionIndex;

}WdgMDeadlineTransitionType;

/* Deadline Supervision Configuration Parameters */
typedef struct 
{
    /* Maximum Deadline Time */
    uint32      DeadlineMax;
    /* Minimum Deadline Time */
    uint32      DeadlineMin;
    /* Source CPID for this transition */
    WdgM_CheckpointIdType SourceCPID;

}WdgMDeadlineSupervisionType;

/* Watchdog Tigger Parameters */
typedef struct 
{
    /* Watchdog timeout value to be loaded while servicing*/
    uint16      TriggerConditionValue;

}WdgMTriggerType;

/* Supervised Entity Configuration Parameters */
typedef struct 
{
    /* Mode in which this entity shall work */
    WdgM_ModeType                   ModeId;
    /* Number of Failed Alive SEs for the status to be moved to FAILED */
    uint8                          FailedAliveSupervisionRefCycleTol;
    /* Number of Failed Deadline SEs for the status to be moved to FAILED */
    uint8                          FailedDeadlineSupervisionRefCycleTol;
    /* Number of Supervised Entities configured for Alive Supervision */
    uint16                          NrOfAliveSupervisionEntities;
    /* Number of Supervised Entities configured for Deadline Supervision */
    uint16                          NrOfDeadlineSupervisionEntities;
    /* Index of Alive Supervision for this Supervision Entity*/
    uint8                           AliveSupervisionIndex;
    /* Index of Deadline Supervision for this Supervision Entity*/
    uint8                           DeadlineSupervisionIndex;
    /* Callback function for Local state change indication */
    void                            (*LocalStateChangeCbk)(void);

}WdgMSupervisedEntityType;

/* Watchdog Configuration Parameters */
typedef struct 
{
    /* Initial mode for the Watchdog to start with */
    WdgM_ModeType               InitialMode;
    /* Function pointer of the OS Counter to get the timestamp */
    uint16                      (*OSCounter)(void);
    /* Callback function for Global State Change indication */
    void                        (*GlobalStateChangeCbk)(void);
    /* Total Number of Supervised Entities configured for this Watchdog Device*/
    WdgM_SupervisedEntityIdType NrOfSupervisedEntities;
    /* Number of Watchdog Devices Configured */
    uint8                       NrOfWatchdogDevices;
    /* Number of Global Expired SEs for the status to be moved to EXPIRED */
    uint16                      ExpiredSupervisionCycleTol;
    /* Supervised Entity Parameter Reference */
    const WdgMSupervisedEntityType   * SupervisedEntityRef;
    /* Watchdog Trigger Parameter Reference */
    const WdgMTriggerType            * TriggerRef;

}WdgM_ConfigType;

/* Maximum Timeout value in mS to be given for Watchdog while deinit */		
typedef struct
{
	uint16 Wdgm_Timeout_Value ;
} Wdgm_Timeout_Type;

extern const WdgMDeadlineTransitionType    WdgMDeadlineTransition[WDGM_NO_OF_DEADLINE_TRANSITIONS];
extern const WdgMDeadlineSupervisionType   WdgMDeadlineSupervision[WDGM_NO_OF_DEADLINE_ENTITIES];
extern const WdgMAliveSupervisionType      WdgMAliveSupervision[WDGM_NO_OF_ALIVE_ENTITIES];
extern const WdgMTriggerType               WdgMTrigger[WDGM_NO_OF_WDG_DEVICES];
extern const WdgMSupervisedEntityType      WdgMSupervisedEntity[WDGM_NO_OF_SUPERVISION_ENTITIES];
extern const WdgM_ConfigType               WdgM_ConfigParam[WDGM_NO_OF_CONFIGURATION_VARIANTS];
extern const Wdgm_Timeout_Type 			   Wdgm_Timeout[WDGM_NO_OF_WDG_DEVICES];

extern void WdgM_EnterCriticalSection(void);
extern void WdgM_ExitCriticalSection(void);

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info	 *
* about the variable.                                                        *
* Purpose, critical section, unit, and resolution                            *
******************************************************************************/

#endif

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

