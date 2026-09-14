/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2017. Visteon Corporation owns all rights to           *
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
*  File Name         :  WdgM_Cfg.h                                           *
*  Module Short Name :  WdgM_Cfg_H                                           *
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
#ifndef WDGM_CFG_H
#define WDGM_CFG_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "Std_Types.h"
#include "Wdg.h"
#include "Stubs.h"
#include "Os.h"
//#include "Wdg_43_Instance1.h"
//#include "Rte_WdgM_OsApplication_Type.h" //temporary inclusion

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/* Pre-Condition Macro to support Immediate Micro Reset */
#ifndef MY_TRUE
#define MY_TRUE  1
#endif
#define WDGM_IMMEDIATE_RESET    STD_ON

/* Pre-Condition Macro to Enable OFF MODE */
#define WDGM_OFF_MODE_ENABLED   STD_ON

/* Macro defining the periodicity of WdgM_MainFunction */
#define WDGM_SUPERVISION_CYCLE  10

#define WDGM_NO_OF_DEADLINE_TRANSITIONS     1
#define WDGM_NO_OF_DEADLINE_ENTITIES        1
#define WDGM_NO_OF_ALIVE_ENTITIES           1
#define WDGM_NO_OF_WDG_DEVICES              1
#define WDGM_NO_OF_SUPERVISION_ENTITIES     1
#define WDGM_NO_OF_CONFIGURATION_VARIANTS   1

/* Maximum Timeout value in mS to be given for Watchdog while deinit */
typedef uint16 WdgM_CheckpointIdType;
typedef uint16 WdgM_SupervisedEntityIdType;
typedef uint8 WdgM_ModeType;
typedef uint8 WdgM_LocalStatusType;
typedef uint8 WdgM_GlobalStatusType;


typedef struct
{
    uint16 Wdgm_Timeout_Value ;
} Wdgm_Timeout_Type;

extern const Wdgm_Timeout_Type Wdgm_Timeout[WDGM_NO_OF_WDG_DEVICES];

#define WDGM_DET_REPORT_ERROR(x)
#define WDGM_CHECKPOINT_ERROR_HOOK(X)


/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

#define WDGM_OFF_MODE      0 /*OFF Mode */
#define WDGM_SLOW_MODE     1 /* SLOW Mode */
#define WDGM_FAST_MODE     2 /* FAST Mode */

/* OK */
#  ifndef WDGM_LOCAL_STATUS_OK
#   define WDGM_LOCAL_STATUS_OK (0U)
#  endif
/* FAILED */
#  ifndef WDGM_LOCAL_STATUS_FAILED
#   define WDGM_LOCAL_STATUS_FAILED (1U)
#  endif
/* EXPIRED */
#  ifndef WDGM_LOCAL_STATUS_EXPIRED
#   define WDGM_LOCAL_STATUS_EXPIRED (2U)
#  endif
/* DEACTIVATED */
#  ifndef WDGM_LOCAL_STATUS_DEACTIVATED
#   define WDGM_LOCAL_STATUS_DEACTIVATED (4U)
#  endif

#define WDGM_CORRECT            0u /* CORRECT */
#define WDGM_INCORRECT          1u /* INCORRECT */

/* OK */
#  ifndef WDGM_GLOBAL_STATUS_OK
#   define WDGM_GLOBAL_STATUS_OK (0U)
#  endif
/* FAILED */
#  ifndef WDGM_GLOBAL_STATUS_FAILED
#   define WDGM_GLOBAL_STATUS_FAILED (1U)
#  endif
/* EXPIRED */
#  ifndef WDGM_GLOBAL_STATUS_EXPIRED
#   define WDGM_GLOBAL_STATUS_EXPIRED (2U)
#  endif
/* STOPEED */
#  ifndef WDGM_GLOBAL_STATUS_STOPPED
#   define WDGM_GLOBAL_STATUS_STOPPED (3U)
#  endif
/* DEACTIVATED */
#  ifndef WDGM_GLOBAL_STATUS_DEACTIVATED
#   define WDGM_GLOBAL_STATUS_DEACTIVATED (4U)
#  endif
#define LLD_WKUP_PADCFG_CTRL0_CFG0_BASE                                                            (0x4080000UL)
#define WDGM_E_NO_INIT						0x10
#define WDGM_E_PARAM_CONFIG					0x11
#define WDGM_E_PARAM_MODE					0x12
#define WDGM_E_PARAM_SEID					0x13
#define WDGM_E_INV_POINTER					0x14
#define WDGM_E_DISABLE_NOT_ALLOWED			0x15
#define WDGM_E_CPID							0x16
#define WDGM_E_DEPRECATED					0x17
#define WDGM_E_AMBIGIOUS					0x18
#define WDGM_E_SEDEACTIVATED				0x19


/* Alive Supervision Configuration Parameters */
typedef struct 
{
    /* Expected Alive Indication Counts */
    uint32      ExpectedAliveIndications;
    /* Maximum Allowed Margin for Alive indication */
    uint16      MaxMargin;
    /* Minimum Allowed Margin for Alive indication */
    uint16      MinMargin;
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
    uint16                          FailedAliveSupervisionRefCycleTol;
    /* Number of Failed Deadline SEs for the status to be moved to FAILED */
    uint16                          FailedDeadlineSupervisionRefCycleTol;
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



extern const WdgMDeadlineTransitionType    WdgMDeadlineTransition[WDGM_NO_OF_DEADLINE_TRANSITIONS];
extern const WdgMDeadlineSupervisionType   WdgMDeadlineSupervision[WDGM_NO_OF_DEADLINE_ENTITIES];
extern const WdgMAliveSupervisionType      WdgMAliveSupervision[WDGM_NO_OF_ALIVE_ENTITIES];
extern const WdgMTriggerType               WdgMTrigger[WDGM_NO_OF_WDG_DEVICES];
extern const WdgMSupervisedEntityType      WdgMSupervisedEntity[WDGM_NO_OF_SUPERVISION_ENTITIES];
extern const WdgM_ConfigType               WdgM_ConfigParam[WDGM_NO_OF_CONFIGURATION_VARIANTS];

extern void WdgM_EnterCriticalSection(void);
extern void WdgM_ExitCriticalSection(void);

# define SchM_Enter_WdgM_WDGM_EXCLUSIVE_AREA_0() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_WdgM_WDGM_EXCLUSIVE_AREA_0() ResumeAllInterrupts() 

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/


#endif

