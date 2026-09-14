/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
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
*  File Name         :  WdgM.c                                               *
*  Module Short Name :  WdgM                                                 *
*  Description       :  This file contains implementations of the Watchdog   *
*                       Manager                                              *
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
#ifndef WDGM_C
#define WDGM_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "WdgM.h"
#include "WdgIf.h"
#include "Platform_Types.h"
#include "AssertLib.h"
#include "Det.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define WDGM_INVALID_SEID           0xFFFFu
#define WDGM_INVALID_CHECKPOINT     0xFFFFu
#define WDGM_END_COUNTER            0xFFu
#define WDGM_UNINIT					0u
#define WDGM_INIT					1u
#define WDGM_IGNORE_UNREF_PARAM(param)                  ((void)(param))
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
#define WDGMGR_DATA_SEC_START
#include "MemMap.h"

typedef struct
{ 
    /* Alive Counter. */
    uint16                  AliveCounter;
    /* Counter to maintain Alive Examination Period. */
    uint16                  SupervisionAliveCounter;

} WdgM_AliveDataType;

static WdgM_AliveDataType   WdgM_AliveData[WDGM_NO_OF_ALIVE_ENTITIES];

/* Deadline SE Data Structure */
typedef struct
{
    /* Previous Timestamp for Deadline Supervision. */
    uint32                  PreviousTimestamp;
    /* Deadline Status*/
    uint8                   Deadline_Status;
} WdgM_DeadlineDataType;
#if WDGM_NO_OF_DEADLINE_ENTITIES > 0U
static WdgM_DeadlineDataType   WdgM_DeadlineData[WDGM_NO_OF_DEADLINE_ENTITIES];
#endif
/* Local Supervised Entity Data Structure */
typedef struct
{
    /* Number of Alive Supervised entities Failed. */
    uint8                  FailedAliveSupervisionCounter;
    /* Number of Deadline Supervised entities Failed. */
    uint8                  FailedDeadlineSupervisionCounter;
    /* Previous Checkpoint ID */
    WdgM_CheckpointIdType   RememberedCheckpoint;
    /* Reference for Alive Supervision Data */
    WdgM_AliveDataType      *AliveDataRef;
    /* Reference for Deadline Supervision Data */
    WdgM_DeadlineDataType   *DeadlineDataRef;
    /* Local Supervised Entity Status. */
    WdgM_LocalStatusType    LocalMonitoringStatus;

} WdgM_SupervisedEntityDataType;

/* Global Data Structure */
typedef struct
{
    /* Number of Expired Supervision Entities */
    uint16                  ExpiredCycleCounter;
    /* First Expired SEID */
    uint16                  FirstExpiredSEID;
    /* Global Wacthdog Status */
    WdgM_GlobalStatusType   GlobalMonitoringStatus;
    /* Current Mode */
    WdgM_ModeType           CurrentMode;
    /* Flag to indicated the Main Function has started */
    uint8                   MainStarted;
    uint8 					InitStatus;

} WdgM_GlobalDataType;


/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

static WdgM_GlobalDataType              WdgM_GlobalData;

static WdgM_GlobalStatusType            global_status = WDGM_GLOBAL_STATUS_DEACTIVATED;

static WdgM_SupervisedEntityDataType    WdgM_SupervisedEntityData[WDGM_NO_OF_SUPERVISION_ENTITIES];

#define WDGMGR_DATA_SEC_END
#include "MemMap.h"

#define WDGMGR_CODE_SEC_START
#include "MemMap.h"

static FUNC(void, WDGMGR_CODE_SEC_START) WdgM_ProcessSupervisionEntities(uint8* local_failed_status);
static FUNC(uint8, WDGMGR_CODE_SEC_START) WdgM_PerformAliveExamination(uint16 supervised_entity, uint8 *performed_status);
#if WDGM_NO_OF_DEADLINE_ENTITIES > 0U
static FUNC(uint8, WDGMGR_CODE_SEC_START) WdgM_PerformDeadlineExamination(uint16 supervised_entity);
#endif
static FUNC(void, WDGMGR_CODE_SEC_START) WdgM_Det_ReportError(uint8 ApiId, uint8 ErrorId);

#if (WDGM_VERSION_INFO_API == TRUE)
/*============================================================================
**
** Function Name    :   WdgM_GetVersionInfo
**
** Visibility       :   Public
**
** Description      :   Returns the version information
**
** Invocation       :
**
** Inputs           :   Std_VersionInfoType * VersionInfo - Pointer to a VErsion Info type.
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, WDGMGR_CODE_SEC_START)WdgM_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
    if (NULL_PTR != VersionInfo)
    {
        VersionInfo->vendorID         = (uint16)WDGM_VENDOR_ID;
        VersionInfo->moduleID         = (uint16)WDGM_MODULE_ID;
        VersionInfo->sw_major_version = (uint8)WDGM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)WDGM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)WDGM_SW_PATCH_VERSION;
    }
    else
    {
        WdgM_Det_ReportError(WDGM_VERSIONINFO_API,WDGM_E_INV_POINTER);
    }

}
#endif

/*============================================================================
**
** Function Name    :   WdgM_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global
**                      and Static variables of this module.
**
** Invocation       :
**
** Inputs           :   WdgM_ConfigType * ConfigPtr - Pointer to a configuration type.
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, WDGMGR_CODE_SEC_START)WdgM_Init (const WdgM_ConfigType* ConfigPtr)
{
    uint16 supervised_entity = 0u;
#if WDGM_NO_OF_DEADLINE_ENTITIES > 0U
    uint16 deadline_entity = 0u;
#endif
    uint16 alive_entity = 0u;
    Std_ReturnType Ret = E_NOT_OK;
    uint8 Device = 0u;

    WdgM_EnterCriticalSection();
    WdgM_GlobalData.InitStatus = WDGM_UNINIT;
    WdgM_ExitCriticalSection();

    #if(FALSE == WDGM_POSTUBILD_VARIANT_SUPPORT)
    if(ConfigPtr != NULL)
    {
        WdgM_EnterCriticalSection();
        WdgM_GlobalData.ExpiredCycleCounter = 0u;
        WdgM_GlobalData.FirstExpiredSEID = WDGM_INVALID_SEID;
        WdgM_GlobalData.CurrentMode = ConfigPtr->InitialMode;
        WdgM_GlobalData.MainStarted = 0u;
        WdgM_ExitCriticalSection();
        #if(FALSE == WDGM_OFF_MODE_ENABLED)
        if(WDGM_OFF_MODE == WdgM_GlobalData.CurrentMode)
        {
            WdgM_Det_ReportError(WDGM_INIT_API,WDGM_E_DISABLE_NOT_ALLOWED);
            WdgM_GlobalData.InitStatus = WDGM_UNINIT;
        }
        else
        #endif
        {
            for (Device = 0u; Device < WDGIF_NUMBER_OF_DEVICES_SUPPORTED; Device++)
            {
                Ret = WdgIf_SetMode(Device, (WdgIf_ModeType)ConfigPtr->InitialMode);

                /* Set mode is not successful, No need to continue with other devices, End the Loop*/
                if(Ret != E_OK)
                {
                    break;
                }
            }
            WdgM_EnterCriticalSection();
            if(Ret == E_OK)
            {
                WdgM_GlobalData.GlobalMonitoringStatus = WDGM_GLOBAL_STATUS_OK;
            }
            else
            {
                WdgM_GlobalData.GlobalMonitoringStatus = WDGM_GLOBAL_STATUS_STOPPED;
            }
            global_status = WdgM_GlobalData.GlobalMonitoringStatus;
            WdgM_ExitCriticalSection();

            if(Ret == E_OK)
            {
                for(supervised_entity = 0u; supervised_entity < ConfigPtr->NrOfSupervisedEntities; supervised_entity++)
                {
                    WdgM_SupervisedEntityData[supervised_entity].FailedAliveSupervisionCounter = 0u;
                    WdgM_SupervisedEntityData[supervised_entity].FailedDeadlineSupervisionCounter = 0u;
                    WdgM_EnterCriticalSection();
                    WdgM_SupervisedEntityData[supervised_entity].LocalMonitoringStatus = WDGM_LOCAL_STATUS_OK;
                    WdgM_ExitCriticalSection();
                    WdgM_SupervisedEntityData[supervised_entity].RememberedCheckpoint = WDGM_INVALID_CHECKPOINT;

                    if((ConfigPtr->SupervisedEntityRef[supervised_entity].NrOfAliveSupervisionEntities != 0u)&&
                            (ConfigPtr->SupervisedEntityRef[supervised_entity].AliveSupervisionIndex < WDGM_NO_OF_ALIVE_ENTITIES) )
                    {
                        WdgM_SupervisedEntityData[supervised_entity].AliveDataRef = \
                                &WdgM_AliveData[ConfigPtr->SupervisedEntityRef[supervised_entity].AliveSupervisionIndex];
                    }
                    else
                    {
                        WdgM_SupervisedEntityData[supervised_entity].AliveDataRef = NULL;
                    }
#if WDGM_NO_OF_DEADLINE_ENTITIES > 0U
                    if((ConfigPtr->SupervisedEntityRef[supervised_entity].NrOfDeadlineSupervisionEntities != 0u) &&
                            (ConfigPtr->SupervisedEntityRef[supervised_entity].DeadlineSupervisionIndex < WDGM_NO_OF_DEADLINE_ENTITIES))
                    {
                        WdgM_SupervisedEntityData[supervised_entity].DeadlineDataRef = \
                                &WdgM_DeadlineData[ConfigPtr->SupervisedEntityRef[supervised_entity].DeadlineSupervisionIndex];
                    }
                    else
                    {
                        WdgM_SupervisedEntityData[supervised_entity].DeadlineDataRef = NULL;
                    }
#endif
                    for(alive_entity= 0; alive_entity< ConfigPtr->SupervisedEntityRef[supervised_entity].NrOfAliveSupervisionEntities ; alive_entity++)
                    {
                        WdgM_EnterCriticalSection();
                        WdgM_SupervisedEntityData[supervised_entity].AliveDataRef[alive_entity].SupervisionAliveCounter = 0u;
                        WdgM_SupervisedEntityData[supervised_entity].AliveDataRef[alive_entity].AliveCounter = 0u;
                        WdgM_ExitCriticalSection();
                    }
#if WDGM_NO_OF_DEADLINE_ENTITIES > 0U
                    for(deadline_entity= 0; deadline_entity<ConfigPtr->SupervisedEntityRef[supervised_entity].NrOfDeadlineSupervisionEntities; deadline_entity++)
                    {
                        WdgM_SupervisedEntityData[supervised_entity].DeadlineDataRef[deadline_entity].PreviousTimestamp = 0u;
                        WdgM_EnterCriticalSection();
                        WdgM_SupervisedEntityData[supervised_entity].DeadlineDataRef[deadline_entity].Deadline_Status = TRUE;
                        WdgM_ExitCriticalSection();
                    }
#endif
                }
                WdgM_EnterCriticalSection();
                WdgM_GlobalData.InitStatus = WDGM_INIT;
                WdgM_ExitCriticalSection();
            }
        }

    }
    else
    {
        if(WDGM_GLOBAL_STATUS_DEACTIVATED == global_status)
        {
            WdgM_Det_ReportError(WDGM_INIT_API,WDGM_E_NO_INIT);
        }
        else
        {
            /* do nothing */
        }
        
    }
    #else
        /* To Do POSTBUILD SUPPORT */
        WdgM_GlobalData.InitStatus = WDGM_UNINIT;
    #endif
}

/*============================================================================
**
** Function Name    :   WdgM_DeInit
**
** Visibility       :   Public
**
** Description      :   The DeInit function is called to initialise the Global
**                      and Static variables  of this module to initial/ default values.
**
** Invocation       :   Function could be called from interrupt level or from task level
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, WDGMGR_CODE_SEC_START) WdgM_DeInit(void)
{
    uint8 Device = 0u;

    if(WDGM_GLOBAL_STATUS_DEACTIVATED != global_status)
    {
        /* Wdg Trigerring*/
        for (Device = 0; Device < WDGIF_NUMBER_OF_DEVICES_SUPPORTED; Device++)
        {
            WdgIf_SetTriggerCondition (Device, Wdgm_Timeout[Device].Wdgm_Timeout_Value);
        }
        WdgM_EnterCriticalSection();
        WdgM_GlobalData.GlobalMonitoringStatus = WDGM_GLOBAL_STATUS_DEACTIVATED;
        global_status = WdgM_GlobalData.GlobalMonitoringStatus;
        WdgM_ExitCriticalSection();
        if(WdgM_ConfigParam[0].GlobalStateChangeCbk != NULL)
        {
            WdgM_ConfigParam[0].GlobalStateChangeCbk();
        }
        WdgM_GlobalData.InitStatus = WDGM_UNINIT;
    }
    else
    {
        WdgM_Det_ReportError(WDGM_DEINIT_API,WDGM_E_NO_INIT);
    }
}

/*============================================================================
**
** Function Name    :   WdgM_SetMode
**
** Visibility       :    Public
**
** Description      :   This function sets the Watchdog mode to the requested
**                      mode which is passed as parameter.
**
** Invocation       :
**
** Inputs           :   WdgM_ModeType Mode: The mode to be set to.
**                      uint16 CallerID: ID of the caller who invokes.
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
FUNC(Std_ReturnType, WDGMGR_CODE_SEC_START)  WdgM_SetMode(WdgM_ModeType Mode, uint16 CallerID)
{
    Std_ReturnType Ret = E_NOT_OK;
    uint8 supervised_entities = 0u;
    WdgM_LocalStatusType local_status = 0u;
    uint8 Device = 0u;

    if(WDGM_GLOBAL_STATUS_DEACTIVATED != global_status)
    {
        if(WDGM_NUMOF_MODES > Mode)
        {
            if((FALSE != WDGM_OFF_MODE_ENABLED) || (Mode != WDGM_OFF_MODE))
            {
                /* SWS_WdgM_00316 */
                WdgM_EnterCriticalSection();
                global_status = WdgM_GlobalData.GlobalMonitoringStatus;
                WdgM_ExitCriticalSection();

                if((global_status == WDGM_GLOBAL_STATUS_OK) || \
                        (global_status == WDGM_GLOBAL_STATUS_FAILED))
                {
                    for (Device = 0; Device < WDGIF_NUMBER_OF_DEVICES_SUPPORTED; Device++)
                    {
                        Ret = WdgIf_SetMode(Device, (WdgIf_ModeType)Mode);

                        /* Set mode is not successful, No need to continue with other devices, End the Loop*/
                        if(Ret != E_OK)
                        {
                            break;
                        }
                    }
                    if(Ret == E_OK)
                    {
                        WdgM_EnterCriticalSection();
                        WdgM_GlobalData.CurrentMode = Mode;
                        WdgM_ExitCriticalSection();
                    }
                    else
                    {
                        /* Mode setting was not success */
                        WdgM_EnterCriticalSection();
                        WdgM_GlobalData.GlobalMonitoringStatus = WDGM_GLOBAL_STATUS_STOPPED;
                        global_status = WdgM_GlobalData.GlobalMonitoringStatus;
                        WdgM_ExitCriticalSection();
                        for (supervised_entities = 0u; supervised_entities < WDGM_NO_OF_SUPERVISION_ENTITIES; supervised_entities++)
                        {
                            WdgM_EnterCriticalSection();
                            local_status = WdgM_SupervisedEntityData[supervised_entities].LocalMonitoringStatus;
                            WdgM_ExitCriticalSection();
                            if(local_status != WDGM_LOCAL_STATUS_EXPIRED)
                            {
                                if(local_status != WDGM_LOCAL_STATUS_DEACTIVATED)
                                {
                                    WdgM_EnterCriticalSection();
                                    WdgM_SupervisedEntityData[supervised_entities].LocalMonitoringStatus = WDGM_LOCAL_STATUS_DEACTIVATED;
                                    WdgM_ExitCriticalSection();
                                    if(WdgM_ConfigParam[0].SupervisedEntityRef[supervised_entities].LocalStateChangeCbk != NULL)
                                    {
                                        WdgM_ConfigParam[0].SupervisedEntityRef[supervised_entities].LocalStateChangeCbk();
                                    }

                                }
                            }
                        }
                    }
                    /* Modewise SE Deactivation and Status/variable changes to be implemented. SWS_WdgM_00315 */
                }
                else
                {
                    /* do nothing */
                }
            }
            else
            {
                WdgM_Det_ReportError(WDGM_SETMODE_API,WDGM_E_DISABLE_NOT_ALLOWED);      
            }
        }
        else
        {
            WdgM_Det_ReportError(WDGM_SETMODE_API,WDGM_E_PARAM_MODE);
        }
    }
    else
    {
        WdgM_Det_ReportError(WDGM_SETMODE_API,WDGM_E_NO_INIT);
    }
    WDGM_IGNORE_UNREF_PARAM(CallerID);
    return Ret;
}

/*============================================================================
**
** Function Name    :   WdgM_GetMode
**
** Visibility       :   Public
**
** Description      :   This function returns the current mode of the watchdog.
**
** Invocation       :
**
** Inputs           :   WdgM_ModeType* Mode: The pointer to get the mode type.
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
FUNC(Std_ReturnType, WDGMGR_CODE_SEC_START) WdgM_GetMode(WdgM_ModeType* Mode)
{
    Std_ReturnType Ret = E_NOT_OK;
    WdgM_ModeType current_mode = 0u;

    if(WDGM_GLOBAL_STATUS_DEACTIVATED != global_status)
    {
        if( Mode != NULL)
        {
            WdgM_EnterCriticalSection();
            current_mode = WdgM_GlobalData.CurrentMode;
            WdgM_ExitCriticalSection();
            if((current_mode == WDGM_OFF_MODE)|| \
                    (current_mode == WDGM_SLOW_MODE)|| \
                    (current_mode == WDGM_FAST_MODE))
            {
                *Mode = current_mode;
                Ret = E_OK;
            }
        }
        else
        {
            WdgM_Det_ReportError(WDGM_GETMODE_API,WDGM_E_INV_POINTER);
        }        
    }
    else
    {
        WdgM_Det_ReportError(WDGM_GETMODE_API,WDGM_E_NO_INIT); 
    }
    return Ret;
}

/*============================================================================
**
** Function Name    :   WdgM_CheckpointReached
**
** Visibility       :   Public
**
** Description      :   This function shall be invoked by the application on
**                      reaching its checkpoints. This function will then keep
**                      the count of the requested checkpoint, which will be
**                      later used to examine the supervision.
**
** Invocation       :
**
** Inputs           :   WdgM_SupervisedEntityIdType SEID: Supervised Entity ID
**                      WdgM_CheckpointIdType CheckpointID: Chcekpoint ID
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
FUNC(Std_ReturnType, WDGMGR_CODE_SEC_START) WdgM_CheckpointReached(WdgM_SupervisedEntityIdType SEID, WdgM_CheckpointIdType CheckpointID)
{
    Std_ReturnType Ret = E_NOT_OK;
    #if WDGM_NO_OF_DEADLINE_ENTITIES > 0U
    WdgM_CheckpointIdType deadline_checkpoint = 0u;
    WdgM_CheckpointIdType last_checkpoint = 0u;
    uint32 current_time = 0u;
    uint32 time_diff = 0u;
    uint8 transition_index = 0u;
    uint8 deadline_transitions = 0u; /*Coverity warning fix, CID 16327297*/
    uint16 DeadlineSupervisoryIndex = 0u;
    #endif 
    uint16 AliveSupervisoryIndex = 0u; 

    if(WDGM_GLOBAL_STATUS_DEACTIVATED != global_status)
    {
        if(WDGM_NO_OF_SUPERVISION_ENTITIES > SEID)
        {
            if(CheckpointID < WdgMSupervisedEntity[SEID].NrOfAliveSupervisionEntities)
            {
                /* Alive Checkpoint */
                WdgM_EnterCriticalSection();
                AliveSupervisoryIndex = (WdgMSupervisedEntity[SEID].AliveSupervisionIndex+CheckpointID);
                if(AliveSupervisoryIndex < WDGM_NO_OF_ALIVE_ENTITIES)
                {
                    if(WdgM_AliveData[AliveSupervisoryIndex].AliveCounter < 0xFFFFu)
                    {
                        WdgM_AliveData[AliveSupervisoryIndex].AliveCounter++;
                        Ret = E_OK;
                    }
                    else
                    {
                        DEBUG_ASSERT( FALSE );
                    }
                }
                else
                {
                    DEBUG_ASSERT( FALSE );
                }
                WdgM_ExitCriticalSection();
            }
            else
            {
#if WDGM_NO_OF_DEADLINE_ENTITIES > 0U
                /* Deadline Checkpoint */

                deadline_checkpoint = CheckpointID - WdgMSupervisedEntity[SEID].NrOfAliveSupervisionEntities;

                if(deadline_checkpoint < WdgMSupervisedEntity[SEID].NrOfDeadlineSupervisionEntities)
                {
                    last_checkpoint = WdgM_SupervisedEntityData[SEID].RememberedCheckpoint;
                    WdgM_SupervisedEntityData[SEID].RememberedCheckpoint = deadline_checkpoint;

                    if(WdgM_ConfigParam[0].OSCounter != NULL)
                    {
                        current_time = WdgM_ConfigParam[0].OSCounter();
                    }
                    else
                    {
                        current_time = 0u;
                    }
                    /* Check if Previous Checkpoint available or not. If not, deadline examination cannot be done */

                    if(last_checkpoint != WDGM_INVALID_CHECKPOINT)
                    {
                        DeadlineSupervisoryIndex = (WdgMSupervisedEntity[SEID].DeadlineSupervisionIndex + deadline_checkpoint);
                        if(DeadlineSupervisoryIndex < WDGM_NO_OF_DEADLINE_ENTITIES)
                        {
                        deadline_transitions = WdgMDeadlineTransition[DeadlineSupervisoryIndex].NrOfTransitions;
                        }
                        else
                        {
                            DEBUG_ASSERT( FALSE );
                        }
                    }


                    /* Traverse through the transitions of this checkpoint, to check whether any one has source CPID */
                    /* same as the previous one */
                    while(deadline_transitions > 0u)
                    {
                    transition_index = WdgMDeadlineTransition[deadline_checkpoint].TransitionIndex + deadline_transitions;
                        if(transition_index < WDGM_NO_OF_DEADLINE_TRANSITIONS)
                        {
                        if(last_checkpoint == WdgMDeadlineSupervision[transition_index].SourceCPID)
                            {
                                /*Transition Found! Source ID matches with the previous CPID. Examine the Deadline */
                                time_diff = current_time - WdgM_DeadlineData[last_checkpoint].PreviousTimestamp;
                                WdgM_EnterCriticalSection();
                            if((time_diff < WdgMDeadlineSupervision[transition_index].DeadlineMin) || \
                                    (time_diff > WdgMDeadlineSupervision[transition_index].DeadlineMax))
                                {
                                    WdgM_DeadlineData[deadline_checkpoint].Deadline_Status = 0u;
                                }
                                else
                                {
                                    WdgM_DeadlineData[deadline_checkpoint].Deadline_Status = 1u;
                                }
                                WdgM_ExitCriticalSection();
                                break;
                            }
                        }
                        else
                        {
                            DEBUG_ASSERT( FALSE );
                        }
                        deadline_transitions--;
                    }
                    WdgM_DeadlineData[deadline_checkpoint].PreviousTimestamp = current_time;
                    Ret = E_OK;
                }
                else
                {
                    /* Error: Neither an alive nor a deadline checkpoint */
                    WdgM_Det_ReportError(WDGM_CHECKPOINTREACHED_API,WDGM_E_CPID);
                }
#endif
            }
        }
        else
        {
            WdgM_Det_ReportError(WDGM_CHECKPOINTREACHED_API,WDGM_E_PARAM_SEID);
        }
    }
    else
    {
        WdgM_Det_ReportError(WDGM_CHECKPOINTREACHED_API,WDGM_E_NO_INIT);     
    }

    return Ret;
}

/*============================================================================
**
** Function Name    :   WdgM_GetLocalStatus
**
** Visibility       :   Public
**
** Description      :   This function returns the local status of the requested SE.
**
** Invocation       :
**
** Inputs           :   Supervised Entity ID: Requesting for Which SE.
**                      Local Status Type Pointer: Status to be loaded in.
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
FUNC(Std_ReturnType, WDGMGR_CODE_SEC_START) WdgM_GetLocalStatus(WdgM_SupervisedEntityIdType SEID, WdgM_LocalStatusType* Status)
{
    Std_ReturnType Ret = E_NOT_OK;
    WdgM_LocalStatusType local_status = 0u;

    if(WDGM_GLOBAL_STATUS_DEACTIVATED != global_status)
    {
        if(WDGM_NO_OF_SUPERVISION_ENTITIES > SEID)
        {
            if(Status != NULL)
            {
                WdgM_EnterCriticalSection();
                local_status = WdgM_SupervisedEntityData[SEID].LocalMonitoringStatus;
                WdgM_ExitCriticalSection();
                if(local_status <= WDGM_LOCAL_STATUS_DEACTIVATED)
                {
                    *Status = local_status;
                    Ret = E_OK;
                }
            }
            else
            {
                WdgM_Det_ReportError(WDGM_GETLOCALSTATUS_API,WDGM_E_INV_POINTER);
            }
        }
        else
        {
            WdgM_Det_ReportError(WDGM_GETLOCALSTATUS_API,WDGM_E_PARAM_SEID);
        }
    }
    else
    {
        WdgM_Det_ReportError(WDGM_GETLOCALSTATUS_API,WDGM_E_NO_INIT);    
    }
    return (Ret);
}

/*============================================================================
**
** Function Name    :   WdgM_GetGlobalStatus
**
** Visibility       :   Public
**
** Description      :   This function returns the Global Status.
**
** Invocation       :
**
** Inputs           :   Global Status Type Pointer: Status to be loaded in.
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
FUNC(Std_ReturnType, WDGMGR_CODE_SEC_START) WdgM_GetGlobalStatus(WdgM_GlobalStatusType* Status)
{
    Std_ReturnType Ret = E_NOT_OK;

    if(WDGM_UNINIT != WdgM_GlobalData.InitStatus)
    {
        if( Status != NULL)
        {
            WdgM_EnterCriticalSection();
            global_status = WdgM_GlobalData.GlobalMonitoringStatus;
            WdgM_ExitCriticalSection();

            if(global_status <= WDGM_GLOBAL_STATUS_DEACTIVATED)
            {
                *Status = global_status;
                Ret = E_OK;
            }
        }
        else
        {
            WdgM_Det_ReportError(WDGM_GETGLOBALSTATUS_API,WDGM_E_INV_POINTER);
        }
    }
    else
    {
        WdgM_Det_ReportError(WDGM_GETGLOBALSTATUS_API,WDGM_E_NO_INIT);
    }
    return (Ret);
}

/*============================================================================
**
** Function Name    :   WdgM_PerformReset
**
** Visibility       :   Public
**
** Description      :   This function shall intimate the immediate watchdog reset
**                      by triggering the Watchdog driver with parameter (timeout) as 0.
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, WDGMGR_CODE_SEC_START) WdgM_PerformReset(void )
{
    uint8 Device = 0u;
    if(WDGM_GLOBAL_STATUS_DEACTIVATED != global_status)
    {
        for (Device = 0; Device < WDGIF_NUMBER_OF_DEVICES_SUPPORTED; Device++)
        {
            WdgIf_SetTriggerCondition (Device, 0);
        }
    }
    else
    {
        WdgM_Det_ReportError(WDGM_PERFORMRESET_API,WDGM_E_NO_INIT);
    }

}

/*============================================================================
**
** Function Name    :   WdgM_GetFirstExpiredSEID
**
** Visibility       :   Public
**
** Description      :   The consequence of a call to this service is that the
**                      shutdown sequence will be initiated. Use this function with care.
**                      Side affects may occur in the Applications.
**
** Invocation       :
**
** Inputs           :   WdgM_SupervisedEntityIdType * SEID: ID of the First Expired SE will be loaded.
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
FUNC(Std_ReturnType, WDGMGR_CODE_SEC_START) WdgM_GetFirstExpiredSEID(WdgM_SupervisedEntityIdType* SEID)
{
    Std_ReturnType Ret = E_NOT_OK;
    uint16 first_expired = 0u;

    if(WDGM_INIT != WdgM_GlobalData.InitStatus)
    {
        if(SEID != NULL)
        {
            WdgM_EnterCriticalSection();
            first_expired = WdgM_GlobalData.FirstExpiredSEID;
            WdgM_ExitCriticalSection();

            if(first_expired != WDGM_INVALID_SEID)
            {
                *SEID = first_expired;
                Ret = E_OK;
            }

        }
        else
        {
            WdgM_Det_ReportError(WDGM_GETFIRSTEXPIREDSEID_API,WDGM_E_INV_POINTER);
        }
    }
    else
    {
        WdgM_Det_ReportError(WDGM_GETFIRSTEXPIREDSEID_API,WDGM_E_NO_INIT);
    }


    return Ret;
}

/*============================================================================
**
** Function Name    :   WdgM_MainFunction
**
** Visibility       :   Public
**
** Description      :   This function is invoked periodically by the Os.
**                      This function examines the Alive and Deadline Supervisions
**                      and sets the status accordingly.
**
** Invocation       :   Os Scheduling.
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
FUNC(void, WDGMGR_CODE_SEC_START) WdgM_MainFunction(void)
{
    uint16 trigger_value = 0U;
    uint8 local_sts_failed = 0U;
    WdgM_GlobalStatusType current_global_status = 0u;
    WdgM_GlobalStatusType wdgm_global_status = 0u;
    WdgM_ModeType current_mode = 0u;
    uint8 Device = 0U;

    if(WDGM_UNINIT != WdgM_GlobalData.InitStatus)
    {
        WdgM_EnterCriticalSection();
        current_mode = WdgM_GlobalData.CurrentMode;
        WdgM_ExitCriticalSection();
        if(current_mode != WDGM_OFF_MODE)
        {
            WdgM_EnterCriticalSection();
            current_global_status = WdgM_GlobalData.GlobalMonitoringStatus;
            WdgM_ExitCriticalSection();
            if(current_global_status != WDGM_GLOBAL_STATUS_STOPPED)
            {
                WdgM_ProcessSupervisionEntities(&local_sts_failed);
                WdgM_EnterCriticalSection();
                if(WdgM_GlobalData.ExpiredCycleCounter != 0u)
                {
                    if(WdgM_GlobalData.ExpiredCycleCounter <= WdgM_ConfigParam[0].ExpiredSupervisionCycleTol)
                    {
                        wdgm_global_status = WDGM_GLOBAL_STATUS_EXPIRED;
                    }
                    else
                    {
                        wdgm_global_status = WDGM_GLOBAL_STATUS_STOPPED;
                    }
                    WdgM_ExitCriticalSection();
                }
                else
                {
                    WdgM_ExitCriticalSection();
                    if(local_sts_failed != 0u)
                    {
                        wdgm_global_status = WDGM_GLOBAL_STATUS_FAILED;
                    }
                    else
                    {
                        wdgm_global_status = WDGM_GLOBAL_STATUS_OK;
                    }
                }
                if(current_global_status != wdgm_global_status)
                {
                    WdgM_EnterCriticalSection();
                    WdgM_GlobalData.GlobalMonitoringStatus = wdgm_global_status;
                    global_status = WdgM_GlobalData.GlobalMonitoringStatus;
                    WdgM_ExitCriticalSection();
                    if(WdgM_ConfigParam[0].GlobalStateChangeCbk != NULL)
                    {
                        WdgM_ConfigParam[0].GlobalStateChangeCbk();
                    }
                }

                for (Device = 0; Device < WDGIF_NUMBER_OF_DEVICES_SUPPORTED; Device++)
                {
                    trigger_value = WdgM_ConfigParam[0].TriggerRef[Device].TriggerConditionValue;
                    if ((wdgm_global_status==WDGM_GLOBAL_STATUS_OK)
                            ||(wdgm_global_status==WDGM_GLOBAL_STATUS_EXPIRED)
                            ||(wdgm_global_status==WDGM_GLOBAL_STATUS_FAILED))
                    {
                        WdgIf_SetTriggerCondition(Device, trigger_value);
                    }
                    else
                    {
                        WDGM_CHECKPOINT_ERROR_HOOK(Device);
                        /* Make the trigger condition value to 0, so that the watchdog reset happens. */
                        WdgIf_SetTriggerCondition(Device, 0U);
                    }

                }
            }
            else
            {
    #if (WDGM_IMMEDIATE_RESET == TRUE)
                WdgM_PerformReset();
    #endif
            }
        }
        WdgM_EnterCriticalSection();
        WdgM_GlobalData.MainStarted = 1u;
        WdgM_ExitCriticalSection();
    }
    else
    {
        WdgM_Det_ReportError(WDGM_MAINFUNCTION_API,WDGM_E_NO_INIT);
    }
}

/*============================================================================
**
** Function Name    :   WdgM_ProcessSupervisionEntities
**
** Visibility       :   Private
**
** Description      :   This function Process the Supervised Entities, and
**                      determines the local status.
**
** Invocation       :   WdgM_MainFunction.
**
** Inputs           :   uint8* local_failed_status: Pointer to which the
**                      the failed status to be returned.
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
static FUNC(void, WDGMGR_CODE_SEC_START) WdgM_ProcessSupervisionEntities(uint8* local_failed_status)
{
    uint16 supervised_entity = 0u;
    uint8  alive_failed_sts = 0u;
    #if WDGM_NO_OF_DEADLINE_ENTITIES > 0U
    uint8  deadline_failed_sts = 0u;
    #endif
    uint8  alive_perform_status = 0u;
    WdgM_LocalStatusType current_local_status = 0u;
    WdgM_LocalStatusType local_status = 0u;

    *local_failed_status = 0u;

    for(supervised_entity = 0u; supervised_entity < WDGM_NO_OF_SUPERVISION_ENTITIES; supervised_entity++)
    {
        WdgM_EnterCriticalSection();
        current_local_status = WdgM_SupervisedEntityData[supervised_entity].LocalMonitoringStatus;
        WdgM_ExitCriticalSection();
        if(current_local_status != WDGM_LOCAL_STATUS_EXPIRED)
        {
            alive_failed_sts = WdgM_PerformAliveExamination(supervised_entity, &alive_perform_status);
#if WDGM_NO_OF_DEADLINE_ENTITIES > 0U
            deadline_failed_sts = WdgM_PerformDeadlineExamination(supervised_entity);
#endif
            /* If any of the alive is incorrect, increment the failed counter.*/
            if(alive_failed_sts != 0u)
            {
                if( WdgM_SupervisedEntityData[supervised_entity].FailedAliveSupervisionCounter < WDGM_END_COUNTER)
                {
                    WdgM_SupervisedEntityData[supervised_entity].FailedAliveSupervisionCounter++;
                }
                else
                {
                    DEBUG_ASSERT( FALSE );
                }
            }
            else
            {
                if(alive_perform_status != 0u)
                {
                    /* If all alive indicators are correct, decrement the failed counter */
                    if(WdgM_SupervisedEntityData[supervised_entity].FailedAliveSupervisionCounter > 0u)
                    {
                        WdgM_SupervisedEntityData[supervised_entity].FailedAliveSupervisionCounter--;
                    }

                }
            }

#if WDGM_NO_OF_DEADLINE_ENTITIES > 0U
            /* If any of the Deadline is incorrect, increment the failed counter.*/
            if(deadline_failed_sts != 0u)
            {
                if(WdgM_SupervisedEntityData[supervised_entity].FailedDeadlineSupervisionCounter < WDGM_END_COUNTER)
                {
                    WdgM_SupervisedEntityData[supervised_entity].FailedDeadlineSupervisionCounter++;
                }
                else
                {
                    DEBUG_ASSERT( FALSE );
                }
            }
            else
            {
                /* If all alive indicators are correct, decrement the failed counter */
                if(WdgM_SupervisedEntityData[supervised_entity].FailedDeadlineSupervisionCounter > 0u)
                {
                    WdgM_SupervisedEntityData[supervised_entity].FailedDeadlineSupervisionCounter--;
                }
            }
#endif
            /* If failed counter is 0, then the SE local status is OK */
            if((WdgM_SupervisedEntityData[supervised_entity].FailedAliveSupervisionCounter == 0u) && \
                    (WdgM_SupervisedEntityData[supervised_entity].FailedDeadlineSupervisionCounter == 0u))
            {
                local_status = WDGM_LOCAL_STATUS_OK;
            }
            else
            {
                /* If failed counter is < failed tolerance, then SE local status is FAILED */
                if((WdgM_SupervisedEntityData[supervised_entity].FailedAliveSupervisionCounter > \
                        WdgM_ConfigParam[0].SupervisedEntityRef[supervised_entity].FailedAliveSupervisionRefCycleTol) || \
                        (WdgM_SupervisedEntityData[supervised_entity].FailedDeadlineSupervisionCounter > \
                         WdgM_ConfigParam[0].SupervisedEntityRef[supervised_entity].FailedDeadlineSupervisionRefCycleTol))
                {
                    /* If failed counter > failed tolernace, then the SE local status is EXPIRED */
                    local_status = WDGM_LOCAL_STATUS_EXPIRED;

                    /* Store the SEID if this is the first one to be EXPIRED */

                    WdgM_EnterCriticalSection();
                    if(WdgM_GlobalData.FirstExpiredSEID == WDGM_INVALID_SEID)
                    {
                        /* Initial value of this will be 0xFFFF */
                        WdgM_GlobalData.FirstExpiredSEID = supervised_entity;
                    }

                    if( WdgM_GlobalData.ExpiredCycleCounter < 0xFFFFu )
                    {
                        WdgM_GlobalData.ExpiredCycleCounter++;
                    }
                    else
                    {
                        DEBUG_ASSERT( FALSE );
                    }
                    WdgM_ExitCriticalSection();
                }
                else
                    /* If failed counter < failed tolernace, then the SE local status is FAILED */
                {
                    local_status = WDGM_LOCAL_STATUS_FAILED;
                    *local_failed_status = 1u;
                }
            }
            if(current_local_status != local_status)
            {
                WdgM_EnterCriticalSection();
                WdgM_SupervisedEntityData[supervised_entity].LocalMonitoringStatus = local_status;
                WdgM_ExitCriticalSection();
                if(WdgM_ConfigParam[0].SupervisedEntityRef[supervised_entity].LocalStateChangeCbk != NULL)
                {
                    WdgM_ConfigParam[0].SupervisedEntityRef[supervised_entity].LocalStateChangeCbk();
                }
            }
        }
    }
}

/*============================================================================
**
** Function Name    :   WdgM_PerformAliveExamination
**
** Visibility       :   Private
**
** Description      :   This function Performs the Alive Examination.
**
** Invocation       :   WdgM_ProcessSupervisionEntities.
**
** Inputs           :   Supervised Entity ID
**
** Outputs          :   Returns the status. TRUE if any of alive supervision
**                      is incorrect. Else FALSE.
**
** Critical Section :
**
**==========================================================================*/
static FUNC(uint8, WDGMGR_CODE_SEC_START) WdgM_PerformAliveExamination(uint16 supervised_entity, uint8 *performed_status)
{
    uint32 minimum_count = 0u;
    uint32 maximum_count = 0u;
    uint16 alive_counter = 0u;
    uint16 alive_supervision = 0u; 
    uint16 alive_index = 0u;
    uint8  Ret = 0u;
    *performed_status = 0u;
    WdgM_EnterCriticalSection();
    if(WdgM_GlobalData.MainStarted != 0u)
    {
        WdgM_ExitCriticalSection();
        if(supervised_entity < WDGM_NO_OF_SUPERVISION_ENTITIES)
        {
            for(alive_supervision = 0u;
                    alive_supervision < WdgMSupervisedEntity[supervised_entity].NrOfAliveSupervisionEntities; \
                    alive_supervision++)
            {
                alive_index = WdgMSupervisedEntity[supervised_entity].AliveSupervisionIndex+alive_supervision;
                if(alive_index < WDGM_NO_OF_ALIVE_ENTITIES)
                {
                    /* Traverse through all Alive Supervsion for this Supervised Entity */
                    WdgM_EnterCriticalSection();
                    if(WdgM_AliveData[alive_index].SupervisionAliveCounter > \
                            WdgMAliveSupervision[alive_index].SupervisionReferenceCycle)
                    {
                        WdgM_ExitCriticalSection();
                        *performed_status = 1u;
                        if(WdgMAliveSupervision[alive_index].ExpectedAliveIndications > (0xFFFFu - WdgMAliveSupervision[alive_index].MaxMargin))
                        {
                            /* Error - This configuration has something wrong... Please revisit the configuration. */
                            DEBUG_ASSERT( FALSE );
                        }
                        else
                        {
                            maximum_count = WdgMAliveSupervision[alive_index].ExpectedAliveIndications + \
                                            WdgMAliveSupervision[alive_index].MaxMargin;
                        }
                        if(WdgMAliveSupervision[alive_index].MinMargin > WdgMAliveSupervision[alive_index].ExpectedAliveIndications)
                        {
                            /* Error - This configuration has something wrong... Please revisit the configuration. */
                            DEBUG_ASSERT( FALSE );
                        }
                        else
                        {
                            minimum_count = WdgMAliveSupervision[alive_index].ExpectedAliveIndications - \
                                            WdgMAliveSupervision[alive_index].MinMargin;
                        }

                        WdgM_EnterCriticalSection();
                        alive_counter = WdgM_AliveData[alive_index].AliveCounter;

                        if((minimum_count > alive_counter) || \
                                (maximum_count < alive_counter))
                        {
                            /* INCORRECT */
                            Ret = 1u;
                        }

                        WdgM_AliveData[alive_index].AliveCounter = 0u;
                        WdgM_AliveData[alive_index].SupervisionAliveCounter = 0u;
                        WdgM_ExitCriticalSection();
                    }
                    else
                    {
                        WdgM_AliveData[alive_index].SupervisionAliveCounter ++;
                        WdgM_ExitCriticalSection();
                    }
                }
                else
                {
                    DEBUG_ASSERT( FALSE );
                }
            }
        }
        else
        {
            DEBUG_ASSERT( FALSE );
        }
    }
    else
    {
        /* Main function invoked for first time. Clear the counter */

        if(supervised_entity <	WDGM_NO_OF_SUPERVISION_ENTITIES)
        {
            if(WdgMSupervisedEntity[supervised_entity].AliveSupervisionIndex < WDGM_NO_OF_ALIVE_ENTITIES)
            {
                WdgM_AliveData[WdgMSupervisedEntity[supervised_entity].AliveSupervisionIndex].AliveCounter = 0u;
            }
            else
            {
                DEBUG_ASSERT( FALSE );
            }
        }
        else
        {
            DEBUG_ASSERT( FALSE );
        }
        WdgM_ExitCriticalSection();

    }
    return(Ret);
}
#if WDGM_NO_OF_DEADLINE_ENTITIES > 0U
/*============================================================================
**
** Function Name    :   WdgM_PerformDeadlineExamination
**
** Visibility       :   Private
**
** Description      :   This function Performs the Deadline Examination.
**
** Invocation       :   WdgM_ProcessSupervisionEntities.
**
** Inputs           :   Supervised Entity ID
**
** Outputs          :   Returns the status. TRUE if any of deadline supervision
**                      is incorrect. Else FALSE.
**
** Critical Section :
**
**==========================================================================*/
static FUNC(uint8, WDGMGR_CODE_SEC_START) WdgM_PerformDeadlineExamination(uint16 supervised_entity)
{
    uint8 Ret = 0u;
    uint16 deadline_entities = 0u; 

    if(supervised_entity < WDGM_NO_OF_SUPERVISION_ENTITIES)
    {
        for(deadline_entities = 0u; deadline_entities < WdgMSupervisedEntity[supervised_entity].NrOfDeadlineSupervisionEntities; \
                deadline_entities++)
        {
            WdgM_EnterCriticalSection();
            if(WdgM_DeadlineData[(WdgMSupervisedEntity[supervised_entity].DeadlineSupervisionIndex)+deadline_entities]. \
                    Deadline_Status == 0u)
            {
                Ret = 1u;
                break;
            }
            WdgM_ExitCriticalSection();
        }
    }
    return(Ret);
}
#endif

static FUNC(void, WDGMGR_CODE_SEC_START) WdgM_Det_ReportError(uint8 ApiId, uint8 ErrorId)
{
    #if(WDGM_DEV_ERROR_DETECT == TRUE)
    (void)Det_ReportError(WDGM_MODULE_ID,WDGM_INSTANCE_ID,ApiId, ErrorId);
    #endif
    WDGM_IGNORE_UNREF_PARAM(ApiId);
    WDGM_IGNORE_UNREF_PARAM(ErrorId);
}


#define WDGMGR_CODE_SEC_END
#include "MemMap.h"

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
Date               : 21-Aug-2015
CDSID              : ssebast1
Traceability       : RTC #396019
Change Description : Initial Framework version of WdgM
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 20-Oct-2015
CDSID              : ssebast1
Traceability       : RTC #398219
Change Description : Implementation of Supervision Entities, Alive and Deadline Supervisions.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 1-Oct-2021
CDSID              : praj1
Traceability       : RTC #1407725
Change Description : wdg two device set trigger update.
-----------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------
Date              : 27/March/2022
By                : gthanapp
Traceability      : RTC #1564070
Change Description: Cert-C warning analysis and fix
----------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------
Date              : 25/May/2022
By                : rsankar
Traceability      : RTC #1564070
Change Description: Audit comment fix
----------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------
Date              : 27/May/2022
By                : eganesan
Traceability      : RTC #1671485
Change Description: Bsw general requirement
----------------------------------------------------------------------------------------------------------------------*/
/* end of file =============================================================*/



