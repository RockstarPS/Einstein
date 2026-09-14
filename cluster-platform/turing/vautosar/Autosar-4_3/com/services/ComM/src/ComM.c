/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*    @file ComM.c
*    @ingroup ComM
*    @brief This file implements the AUTOSAR ComM module.The Communication Manager Module (COM Manager, ComM) is a
*    Resource Manager, which encapsulates the control of the underlying communication services.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComM.h"
#include "ComM_Lcfg.h"
#include "ComM_BusSM.h"
#include "ComM_Dcm.h"
#include "ComM_EcuMBswM.h"
#include "SchM_ComM.h"
#include "ComM_Nm.h"
#if(STD_ON == COMM_NM_MODULE_USED)
#include "Nm.h"
#endif
#include "BswM_ComM.h"
#if (STD_ON == COMM_DCM_MODE_INDICATION_SUPPORT)
#include "Dcm_Cbk.h"
#endif
#if(STD_ON == COMM_DEV_ERROR_DETECT)
# include "Det.h"
#endif

/********************************************************************************************************************
*  Version check                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if((COMM_SW_MAJOR_VERSION != COMM_CFG_SW_MAJOR_VERSION) || \
    (COMM_SW_MINOR_VERSION != COMM_CFG_SW_MINOR_VERSION) || \
    (COMM_SW_PATCH_VERSION != COMM_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if((COMM_AR_RELEASE_MAJOR_VERSION != COMM_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (COMM_AR_RELEASE_MINOR_VERSION != COMM_CFG_AR_RELEASE_MINOR_VERSION) || \
    (COMM_AR_RELEASE_REVISION_VERSION != COMM_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif

/********************************************************************************************************************
*  feature validation check                                                                                         *
********************************************************************************************************************/
/*! @brief To avoid invalid definition of COMM_MODE */
#if ((COMM_NO_COMMUNICATION != 0U) || (COMM_SILENT_COMMUNICATION != 1U) || (COMM_FULL_COMMUNICATION != 2U))
    #error " Invalid value for ComM Mode defined "
#endif
/* Unsupported feature */
#if (COMM_0_PNC_VECTOR_AVOIDANCE  == STD_ON)
    #error " Zero PNC vector avoidance feature is not supported in current version "
#endif 
#if (COMM_PNC_GATEWAY_ENABLED  == STD_ON)
    #error " PNC gateway feature is not supported in current version "
#endif
#if (COMM_NVM_SUPPORT  == STD_ON)
    #error " NVM storage feature is not supported in current version "
#endif 
#if (COM_FULL_COMM_REQUEST_NOTIFICATION_ENABLED  == STD_ON)
    #error " optional SenderReceiver Port of ComM_CurrentChannelRequest feature is not supported in current version "
#endif
/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
/* Macro for static and inline type */
#ifndef COMM_LOCAL 
#define COMM_LOCAL                               static
#endif

#ifndef COMM_LOCAL_INLINE
#define COMM_LOCAL_INLINE                        LOCAL_INLINE
#endif

#if (STD_ON == COMM_DEV_ERROR_DETECT)
/*! Macro for adding module Id and insatance to the Det Report error call */
#define ComM_DetReportError(ApiId,ErrorId) (void)Det_ReportError(COMM_MODULE_ID,COMM_INSTANCE_ID,ApiId,ErrorId)
#endif
/*! @brief Macro for unsused varaible */
#define COMM_IGNORE_UNUSED_PARAM(param)     ((void)(param))
/*! @brief defines the maximum number of PNC states */
#define COMM_MAX_NUM_OF_PNC_STATES	        5U
/*! @brief defines the COMM_INHIBITION max value */
#define COMM_INHIBITION_MAX_VALUE           0xFFFFU
/*! @brief defines the ComM_InhibitionStatusType max value  */
#define COMM_INHIBITIONSTATUS_MAX_VALUE     0x02U
/*! @brief Defines the timer expird value */
#define COMM_TIMER_EXPIRED                  0U
/*! @brief Defines the mask value to set the wakeup inhibition */
#define COMM_WAKEUP_INHIBITION_SET_MASK     0x01U
/*! @brief Defines the mask value to clear the wakeup inhibition */
#define COMM_WAKEUP_INHIBITION_CLEAR_MASK   0xFEU
/*! @brief Defines the mask value to set the Limit to No Com */
#define COMM_LIMIT_TO_NOCOM_SET_MASK        0x02U
/*! @brief Defines the mask value to clear the Limit to No Com */
#define COMM_LIMIT_TO_NOCOM_CLEAR_MASK      0xFDU
/*! @brief Macro utility for checking whether the wakeup inhibition is set */
#define COMM_IS_WAKEUP_INHIBITION_SET(Val)  (((Val) & (COMM_WAKEUP_INHIBITION_SET_MASK)) == \
                                                                        (COMM_WAKEUP_INHIBITION_SET_MASK))
/*! @brief Macro utility for checking whether the Limit to No COM inhibition is set */
#define COMM_IS_LIMIT_TO_NO_COM_INHIBITION_SET(Val) (((Val) & (COMM_LIMIT_TO_NOCOM_SET_MASK)) == \
                                                                        (COMM_LIMIT_TO_NOCOM_SET_MASK))

/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/
/*! @brief @brief Defines the type for the function which process the request in the current state */
typedef P2FUNC(ComM_StateType,AUTOMATIC,ComM_StateProcessorFnType) 
(
    NetworkHandleType Channel,
    ComM_StateType highestRequestedMode
);
/*! @brief @brief Defines the type for the function which handles the on entry functionality of each state */
typedef P2FUNC(void,AUTOMATIC,ComM_StateOnEntryActionFnType) 
(
    NetworkHandleType Channel,
    ComM_StateType CurrentComMState
);

#if (STD_ON == COMM_PNC_SUPPORT)
/*! @brief @brief Defines the type for the function which process the request in the current state */
typedef P2FUNC(ComM_PncModeType,AUTOMATIC,ComM_PncStateProcessorFnType)
(
    PNCHandleType PncId,
    ComM_ChannelIdType ChannelId,
    ComM_PncModeType HighestRequestedPncMode
);
/*! @brief Defines the type for the function which handles the on entry functionality of each state */
typedef P2FUNC(void,AUTOMATIC,ComM_PncStateOnEntryActionFnType)
(
    PNCHandleType PncId,
    ComM_PncModeType CurrentPncMode
);
#endif
/*! @brief Defines the configuration type for the list of ComM state processor and on entry  handler functions */
typedef struct
{
    /*! @brief Defines the function for the state request processor */
    ComM_StateProcessorFnType      StateProcessorFn;
    /*! @brief Defines the function for the on entry  handler for the state */
    ComM_StateOnEntryActionFnType  StateOnEntryActionFn;
} ComM_StateFunctionListConfigType;

#if (STD_ON == COMM_PNC_SUPPORT)
/*! @brief Defines the configuration type for the list of ComM PNC state processor and on entry  handler functions */
typedef struct
{
    /*! @brief Defines the function for the state PNc request processor */
    ComM_PncStateProcessorFnType      PncStateProcessorFn;
    /*! @brief Defines the function for the on PNC entry handler for the state */
    ComM_PncStateOnEntryActionFnType  PncStateOnEntryActionFn;
} ComM_PncStateFunctionListConfigType;
#endif
/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
#define COMM_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief      This method checks the Com Inhibition state and returns the ComMMode supported.
*   @param[in]  Channel  requested Channel Id.
*   @return     ComM_StateType Returns the ComM Mode
*               - COMM_NO_COMMUNICATION
*               - COMM_FULL_COMMUNICATION
*
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_ModeType,COMM_CODE) ComM_GetUserModeWithInhibitionCheck(NetworkHandleType Channel);

/*!******************************************************************************************************************
*   @brief      This method checks and process the request in the No com No Pending request state.
*   @param[in]  Channel  requested Channel Id.
*   @return     ComM_StateType Returns the new ComM state to be transitioned.
*               - COMM_NO_COM_NO_PENDING_REQUEST : No new requested
*               - COMM_FULL_COM_NETWORK_REQUESTED - Full Com requested ,user or DCM request ,Bus NM request,
*                 ECU Wake-up Indication.
*
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_StateType,COMM_CODE) ComM_NoComNoPendingRequestProcessor
(
    NetworkHandleType Channel,
    ComM_StateType highestRequestedMode
);

/*!******************************************************************************************************************
*   @brief      This method checks and process the request in the Full comm network request state.
*   @param[in]  Channel  requested Channel Id.
*   @return     ComM_StateType Returns the new ComM state to be transitioned.
*               - COMM_FULL_COM_NETWORK_REQUESTED : No new requested.
*               - COMM_FULL_COM_READY_SLEEP - User or DCM request released.
*               - COMM_NO_COM_NO_PENDING_REQUEST - Bus sleep request
*               - COMM_SILENT_COM - Bus Network Prepare sleep request .
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_StateType,COMM_CODE) ComM_FullComNetworkRequestProcessor
(
    NetworkHandleType Channel,
    ComM_StateType highestRequestedMode
);

/*!******************************************************************************************************************
*   @brief      This method checks and process the request in the Full comm ready sleep state.
*   @param[in]  Channel  requested Channel Id.
*   @return     ComM_StateType Returns the new ComM state to be transitioned.
*               - COMM_FULL_COM_READY_SLEEP : No new requested
*               - COMM_FULL_COM_NETWORK_REQUESTED - Full Com requested ,user or DCM request
*               - COMM_NO_COM_NO_PENDING_REQUEST - Bus sleep request,Bus type internal or Light timer expired.
*               - COMM_SILENT_COM - Bus Network Prepare sleep request .
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_StateType,COMM_CODE) ComM_FullComReadySleepProcessor
(
    NetworkHandleType Channel,
    ComM_StateType highestRequestedMode
);

/*!******************************************************************************************************************
*   @brief      This method checks and process the request in the silent communication state.
*   @param[in]  Channel  requested Channel Id.
*   @return     ComM_StateType Returns the new ComM state to be transitioned.
*               - COMM_SILENT_COM : No new requested
*               - COMM_FULL_COM_NETWORK_REQUESTED - Full Com requested ,user or DCM request
*               - COMM_NO_COM_NO_PENDING_REQUEST - Bus sleep request
*               - COMM_FULL_COM_READY_SLEEP - Bus Network request .
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_StateType,COMM_CODE) ComM_SilentCommunicationProcessor
(
    NetworkHandleType Channel,
    ComM_StateType highestRequestedMode
);
/*!******************************************************************************************************************
*   @brief      This method implements the on entry action for the No Com No request pending state.
*   @param[in]  Channel  requested Channel in which the transition to be occurred.
*   @param[in]  CurrentComMState  Current ComM state
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_NoComNoPendingRequestOnEntry
(
    NetworkHandleType Channel,
    ComM_StateType CurrentComMState
);
/*!******************************************************************************************************************
*   @brief      This method implements the on entry action for the silent communication state.
*   @param[in]  Channel  requested Channel in which the transition to be occurred.
*   @param[in]  CurrentComMState  Current ComM state
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_SilentCommunicationOnEntry
(
    NetworkHandleType Channel,
    ComM_StateType CurrentComMState
);
/*!******************************************************************************************************************
*   @brief      This method implements the on entry action for the Full COM Network Request state.
*   @param[in]  Channel  requested Channel in which the transition to be occurred.
*   @param[in]  CurrentComMState  Current ComM state
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_FullComNetworkRequestOnEntry
(
    NetworkHandleType Channel,
    ComM_StateType CurrentComMState
);
/*!******************************************************************************************************************
*   @brief      This method implements the on entry action for the Full COM Ready sleep state.
*   @param[in]  Channel  requested Channel in which the transition to be occurred.
*   @param[in]  CurrentComMState  Current ComM state
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_FullComReadySleepOnEntry
(
    NetworkHandleType Channel,
    ComM_StateType CurrentComMState
);
#if (STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT )
/*!******************************************************************************************************************
*   @brief      This method is used to validate the BusSM mode change and notify to the user about the changes.
*   @param[in] Channel Network channel for which BusSM mode change processing should be done.
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_BusSMSateChangeNotificationToUser(NetworkHandleType Channel);
#endif
#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)
/*!******************************************************************************************************************
*   @brief      This method is used to check if the Limit to No Com is enabled or not
*   @param[in]  Channel Network channel for which the status is checked
*   @return     boolean returns the status of the request
*               - TRUE  :Limit to No Com is enabled.
*               - FALSE : Limit to No Com is not enabled.
********************************************************************************************************************/
COMM_LOCAL FUNC(boolean,COMM_CODE) ComM_IsChannelNoComLimitationEnabled(NetworkHandleType Channel);
#endif
#if (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
/*!******************************************************************************************************************
*   @brief      This method is used to check if the wake-up Inhibition is enabled or not
*   @param[in]  Channel Network channel for which the status is checked
*   @return     boolean returns the status of the request
*               - TRUE  : wake-up Inhibition  is enabled.
*               - FALSE : wake-up Inhibition  is not enabled.
********************************************************************************************************************/
COMM_LOCAL FUNC(boolean,COMM_CODE) ComM_IsChannelWakeupInhibitionEnabled(NetworkHandleType Channel);
#endif
#if ((STD_ON == COMM_MODE_LIMITATION_ENABLED) || (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED))
/*!*****************************************************************************************************************
*   @brief      This method is used to check if the Inhibition is enabled for the channel
*   @param[in]  Channel Network channel for which the status is checked
*   @return     boolean returns the status of the request
*               - TRUE  : Inhibition status is enabled.
*               - FALSE : Inhibition status is not enabled.
********************************************************************************************************************/
COMM_LOCAL FUNC(boolean,COMM_CODE) ComM_IsChannelInhibitionEnabled(NetworkHandleType Channel);
#endif

/*!******************************************************************************************************************
*   @brief      This method is used to get whether any user request COMM_FULL_COMMUNICATION.
*   @param[in]  Channel Network channel for which the status is checked
*   @return     boolean returns the status of the request
*               - TRUE  : COMM_FULL_COMMUNICATION requested by an user.
*               - FALSE : COMM_FULL_COMMUNICATION requested by none of the user.
********************************************************************************************************************/
COMM_LOCAL FUNC(boolean,COMM_CODE) ComM_IsFullComRequestByUser(NetworkHandleType Channel);
/*!******************************************************************************************************************
*   @brief      This method is used to get the highest requested ComM State for the Channel
*   @param[in]  Channel ComM channel id to get the highest mode .
*   @return     ComM_StateType returns the highest ComM State
*               - TRUE  : wake-up Inhibition  is enabled.
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_StateType,COMM_CODE) ComM_GetHighestRequestMode(NetworkHandleType Channel);
#if (STD_ON == COMM_PNC_SUPPORT)
/*!******************************************************************************************************************
*   @brief      This method is used to process the PNC state when the current state is COMM_PNC_REQUESTED.
*   @param[in]  PncId PNC Id of the requested channel.
*   @param[in]  ChannelId Channel Id of the request .
*   @param[in]  HighestRequestedPncMode Highest requested PNC mode for the channel
*   @return     ComM_PncModeType returns the next PNC mode
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_PncModeType,COMM_CODE) ComM_PncRequestProcessor
(
    PNCHandleType PncId,
    ComM_ChannelIdType ChannelId,
    ComM_PncModeType HighestRequestedPncMode
);
/*!******************************************************************************************************************
*   @brief      This method is used to process the PNC state when the current state is COMM_PNC_READY_SLEEP.
*   @param[in]  PncId PNC Id of the requested channel.
*   @param[in]  ChannelId Channel Id of the request .
*   @param[in]  HighestRequestedPncMode Highest requested PNC mode for the channel
*   @return     ComM_PncModeType returns the next PNC mode
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_PncModeType,COMM_CODE) ComM_PncReadySleepProcessor
(
    PNCHandleType PncId,
    ComM_ChannelIdType ChannelId,
    ComM_PncModeType HighestRequestedPncMode
);
/*!******************************************************************************************************************
*   @brief      This method is used to process the PNC state when the current state is COMM_PNC_PREPARE_SLEEP.
*   @param[in]  PncId PNC Id of the requested channel.
*   @param[in]  ChannelId Channel Id of the request .
*   @param[in]  HighestRequestedPncMode Highest requested PNC mode for the channel
*   @return     ComM_PncModeType returns the next PNC mode
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_PncModeType,COMM_CODE) ComM_PncPrepareSleepProcessor
(
    PNCHandleType PncId,
    ComM_ChannelIdType ChannelId,
    ComM_PncModeType HighestRequestedPncMode
);
/*!******************************************************************************************************************
*   @brief      This method is used to process the PNC state when the current state is COMM_PNC_NO_COMMUNICATION
*   @param[in]  PncId PNC Id of the requested channel.
*   @param[in]  ChannelId Channel Id of the request .
*   @param[in]  HighestRequestedPncMode Highest requested PNC mode for the channel
*   @return     ComM_PncModeType returns the next PNC mode
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_PncModeType,COMM_CODE) ComM_PncNoCommunicationProcessor
(
    PNCHandleType PncId,
    ComM_ChannelIdType ChannelId,
    ComM_PncModeType HighestRequestedPncMode
);
/*!******************************************************************************************************************
*   @brief      This method is used to handle the actions when entering into the PNC state COMM_PNC_REQUESTED.
*   @param[in]  PncId PNC Id of the requested channel.
*   @param[in]  CurrentPncMode Current mode of the PNC state.
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_PncRequestOnEntry (PNCHandleType PncId,ComM_PncModeType CurrentPncMode);
/*!******************************************************************************************************************
*   @brief      This method is used to handle the actions when entering into the PNC state COMM_PNC_READY_SLEEP.
*   @param[in]  PncId PNC Id of the requested channel.
*   @param[in]  CurrentPncMode Current mode of the PNC state.
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_PncReadySleepOnEntry (PNCHandleType PncId,ComM_PncModeType CurrentPncMode);
/*!******************************************************************************************************************
*   @brief      This method is used to handle the actions when entering into the PNC state COMM_PNC_PREPARE_SLEEP.
*   @param[in]  PncId PNC Id of the requested channel.
*   @param[in]  CurrentPncMode Current mode of the PNC state.
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_PncPrepareSleepOnEntry (PNCHandleType PncId,ComM_PncModeType CurrentPncMode);
/*!******************************************************************************************************************
*   @brief      This method is used to handle the actions when entering into the PNC state COMM_PNC_NO_COMMUNICATION.
*   @param[in]  PncId PNC Id of the requested channel.
*   @param[in]  CurrentPncMode Current mode of the PNC state.
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE)ComM_PncNoCommunicationOnEntry (PNCHandleType PncId,ComM_PncModeType CurrentPncMode);
#ifdef COMM_ENABLE_PNC_GET_USER_REQUEST_MODE
/*!******************************************************************************************************************
*   @brief      This method is used to get the user request ComM mode for the requested PNC Id.
*   @param[in]  PncId PNC Id of the requested channel.
*   @return     ComM_PncModeType returns the user requested ComM Mode
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_ModeType,COMM_CODE)  ComM_PncGetUserRequestMode(ComM_PncIdType PncId);
#endif
/*!******************************************************************************************************************
*   @brief      This method is used to send the PNC byte to CanNM .
*   @param[in]  PncId PNC Id of the requested channel.
*   @param[in]  IsSet indicates whether the PNC bit is set or not.
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_PncModeSendSignal(ComM_PncIdType PncId,boolean IsSet);
/*!******************************************************************************************************************
*   @brief      This method is used to process the PNC state of the channel.
*   @param[in]  Channel PNC ComM channel id for processing PNC
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_PncStateProcessing(NetworkHandleType Channel);
/*!******************************************************************************************************************
*   @brief      This method is used to get the highest requested ComM PNC mode for the PncId
*   @param[in]  PncId PNC index to get the highest PNC mode .
*   @return     ComM_PncModeType returns the highest ComM State
*               - TRUE  : wake-up Inhibition  is enabled.
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_PncModeType,COMM_CODE) ComM_PncGetHighestRequestedMode(ComM_PncIdType PncId);
#endif

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
#define COMM_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "MemMap.h"
/*! @brief Module Init Status */
COMM_LOCAL VAR(ComM_InitStatusType,COMM_VAR_INIT) ComM_InitStatus = COMM_UNINIT;
#define COMM_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "MemMap.h"

#define COMM_START_SEC_VAR_INIT_LOCAL_BOOLEAN
#include "MemMap.h"

#if (STD_ON == COMM_PNC_SUPPORT)
/*! @brief Defines the status for notifying the PNC state change to the Users*/
COMM_LOCAL VAR(boolean,COMM_VAR_INIT)  ComM_PncNotifyStateChange = FALSE;
#endif

#define COMM_STOP_SEC_VAR_INIT_LOCAL_BOOLEAN
#include "MemMap.h"

#define COMM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*! @brief It contains the functions for the ComM state On Entry handler and processor */
COMM_LOCAL CONST(ComM_StateFunctionListConfigType,COMM_CONST) ComM_StateFunctionListConfig[COMM_MAX_NUMBER_OF_STATES] =
{
    {&ComM_NoComNoPendingRequestProcessor,  &ComM_NoComNoPendingRequestOnEntry    },
    {NULL_PTR,                              NULL_PTR                              },
    {&ComM_FullComNetworkRequestProcessor,  &ComM_FullComNetworkRequestOnEntry    },
    {&ComM_FullComReadySleepProcessor,      &ComM_FullComReadySleepOnEntry        },
    {&ComM_SilentCommunicationProcessor,    &ComM_SilentCommunicationOnEntry      }
};

#if (STD_ON == COMM_PNC_SUPPORT)
/*! @brief It contains the functions for the ComM PNC state processor and  On Entry handler function configuration  */
COMM_LOCAL CONST(ComM_PncStateFunctionListConfigType,COMM_CONST) ComM_PncStateFunctionListConfig[COMM_MAX_NUM_OF_PNC_STATES] =
{
    {&ComM_PncRequestProcessor,         &ComM_PncRequestOnEntry             },
    {&ComM_PncReadySleepProcessor,      &ComM_PncReadySleepOnEntry          },
    {&ComM_PncPrepareSleepProcessor,    &ComM_PncPrepareSleepOnEntry        },
    {&ComM_PncNoCommunicationProcessor, &ComM_PncNoCommunicationOnEntry     }
};
#endif

#define COMM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define COMM_START_SEC_CONST_8
#include "MemMap.h"

#if (STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT )
/*! @brief It defines the Rte mode mapping for Rte notification */
COMM_LOCAL CONST(uint8,COMM_CONST) ComM_RteComMTypeMap[COMM_FULL_COMMUNICATION+1U]=
{
    RTE_MODE_ComMMode_COMM_NO_COMMUNICATION,
    RTE_MODE_ComMMode_COMM_SILENT_COMMUNICATION,
    RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION
};
#endif

#define COMM_STOP_SEC_CONST_8
#include "MemMap.h"


#define COMM_START_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC FUNCTION IMPLEMENTATION			                                                                        *
********************************************************************************************************************/
/********************************************************************************************************************
*   @brief      This method is used to initialize module init status (SRS_BSW_00406).
********************************************************************************************************************/
FUNC(void,COMM_CODE) ComM_InitMemory(void)
{
    /* Set ComM Init Status to COMM_UNINIT */
    ComM_InitStatus = COMM_UNINIT;
}

/********************************************************************************************************************
*   @brief      This method initializes the AUTOSAR Communication Manager and restarts the internal state machines.
*   @param[in]  ConfigPtr  Pointer to the ComM post-build configuration data.
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
*   @note       The ComM_Init should be called before using the ComM module for further processing.
********************************************************************************************************************/
FUNC(void,COMM_CODE) ComM_Init(P2CONST(ComM_ConfigType,AUTOMATIC,COMM_APPL_CONST) ConfigPtr)
{
    NetworkHandleType ChannelId;
    ComM_UserHandleType UserId;
    uint8 ErrorId = COMM_E_NO_ERROR;
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;

    if (COMM_UNINIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_INIT_FAILED;
    }
    else
    {

        /* Initialize Channel Property */
        for (ChannelId = 0U; ChannelId < COMM_NUM_OF_CHANNELS; ChannelId++)
        {
            ChannelConfigPtr = &ComM_ChannelConfig[ChannelId];
            /* Initialize the user requested state to No Com No Pending Request  */
            ComM_ChannelUserRequestedMode[ChannelId]  = COMM_NO_COMMUNICATION;
            /* Initialize Bus SM State */
            ComM_BusSmMode[ChannelId] = COMM_NO_COMMUNICATION;
            /* Initialize the DCM request to false */
            ComM_DcmFullComRequest[ChannelId] = FALSE;
            /* Initialize BusNm requested state to invalid state*/
            ComM_BusNmRequestedState[ChannelId] = COMM_MAX_NUMBER_OF_STATES;
            /* Initialize Current Channel state to No Com No Pending Request state*/
            ComM_CurrentState[ChannelId] = COMM_NO_COM_NO_PENDING_REQUEST;
            /* Initialize communication Allowed Status to FALSE */
            ComM_CommunicationAllowedStatus[ChannelId] = FALSE;
            /* Initialize the EcuM Wake-up Indication to false */
            ComM_EcuMWakeupIndicationStatus[ChannelId] = FALSE;
#if (STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT)
            /* Set the user mode changed flag to false */
            ComM_IsBusSmModeChanged[ChannelId] = FALSE;
#endif
            /* Initialize the timers */
            ComM_Timer[ChannelId] = COMM_TIMER_EXPIRED;
            /* Initialize channel Inhibition status */
            ComM_Inhibition.ChannelInhibitionStatus[ChannelId]  = (uint8)ChannelConfigPtr->NoCom;
            ComM_Inhibition.ChannelInhibitionStatus[ChannelId] |= (uint8)((uint8)ChannelConfigPtr->NoWakeup << 1U);
        }

        /* Initialize User Property */
        for (UserId = 0U; UserId < COMM_NUM_OF_USERS; UserId++)
        {
            /* Initialize User Requested Mode */
            ComM_UserRequestedMode[UserId] = COMM_NO_COMMUNICATION;
#if (STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT)
            ComM_OldBusSmMode[UserId] = COMM_NO_COMMUNICATION;
#endif
        }

#if (STD_ON == COMM_PNC_SUPPORT)

#endif

        /* set Ecu Inhibition status and Inhibition count*/
        ComM_Inhibition.EcuInhibitionStatus = COMM_ECU_GROUP_CLASSIFICATION;
        ComM_Inhibition.InhibitionCount = 0U;

        /* Update ComM Init Status */
        ComM_InitStatus = COMM_INIT;
    }

    COMM_IGNORE_UNUSED_PARAM(ConfigPtr);
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR  != ErrorId)
    {
        ComM_DetReportError(COMM_SID_INIT, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This method de-initializes the AUTOSAR Communication Manager.
*   @ServiceID  0x02
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(void,COMM_CODE) ComM_DeInit(void)
{
    uint8 ErrorId = COMM_E_NO_ERROR;
    NetworkHandleType ChannelId = 0U;
    boolean FullComActiveSts = FALSE;

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_INIT_FAILED;
    }
    else
    {
        for (ChannelId = 0U; ChannelId < COMM_NUM_OF_CHANNELS; ChannelId++)
        {
            /* Check if all Channels are in No Communication Mode */
            if (COMM_NO_COM_NO_PENDING_REQUEST != ComM_CurrentState[ChannelId])
            {
                FullComActiveSts = TRUE;
            }
        }

        if (FALSE == FullComActiveSts)
        {
            /* Enter Critical section */
            ComM_EnterCriticalSection();
            /* Update ComM Init Status */
            ComM_InitStatus = COMM_UNINIT;
            /* Exit Critical section */
            ComM_ExitCriticalSection();
        } /* else Not all channels are in No com state */
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(ErrorId != COMM_E_NO_ERROR)
    {
        ComM_DetReportError(COMM_SID_DEINIT, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This method returns current state, including sub-state, of the ComM channel state machine.
*   @param[in]  Channel  The Network Channel for the requested state of ComM state machine.
*   @param[out] State  State of the ComM channel state machine:
*               - COMM_NO_COM_NO_PENDING_REQUEST
*               - COMM_NO_COM_REQUEST_PENDING
*               - COMM_FULL_COM_NETWORK_REQUESTED
*               - COMM_FULL_COM_READY_SLEEP
*               - COMM_SILENT_COM
*   @return     status of the request
*               - E_OK: Successfully return current state of ComM state machine
*               - E_NOT_OK: Return of current state of ComM state machine failed
*   @ServiceID  0x34
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
*   @note Usage of function only valid if EcuM/Fixed is used: To leave RUN: state/sub-state need to be
*   COMM_NO_COM_NO_PENDING_REQUEST (No communication and no pending request to start communication)
*   In POST RUN to return to RUN: state/sub-state need to be in COMM_NO_COM_REQUEST_PENDING
*   (No communication, but a pending request to start communication) If EcuM/Flex and BswM is used,
*   BswM instead use received mode indications from ComM (BswM_ComM_RequestedMode(..))
********************************************************************************************************************/
FUNC(Std_ReturnType,COMM_CODE) ComM_GetState
(
    NetworkHandleType Channel,
    P2VAR(ComM_StateType,AUTOMATIC,COMM_APPL_DATA) State
)
{
    uint8 ErrorId = COMM_E_NO_ERROR;
    Std_ReturnType ReturnValue = E_NOT_OK;
    ComM_StateType ComMState= COMM_NO_COM_NO_PENDING_REQUEST;

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (COMM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
    else if (NULL_PTR == State)
    {
        ErrorId = COMM_E_PARAM_POINTER;
    }
#endif
    else
    {
        /* Get Current sub state of the Channel */
        if (COMM_NO_COM_NO_PENDING_REQUEST != ComM_CurrentState[Channel])
        {
            ComMState = ComM_CurrentState[Channel];
        }
        else
        {
            /* check for any Bus Nm request and ECU wakeup request  */
            if (((COMM_NO_COM_NO_PENDING_REQUEST != ComM_BusNmRequestedState[Channel]) &&
                    (COMM_MAX_NUMBER_OF_STATES != ComM_BusNmRequestedState[Channel]))      ||
                    (FALSE != ComM_EcuMWakeupIndicationStatus[Channel]))
            {
                ComMState = COMM_NO_COM_REQUEST_PENDING;
            }
            /* Check if any user request is pending */
            if ((COMM_NO_COMMUNICATION != ComM_GetUserModeWithInhibitionCheck(Channel)) ||
                    (FALSE != ComM_DcmFullComRequest[Channel]))
            {
                ComMState = COMM_NO_COM_REQUEST_PENDING;
            }
        }
        *State = ComMState;
        ReturnValue = E_OK;
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_GETSTATE, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      This method returns the initialization status of the AUTOSAR Communication Manager. After a call to
*   ComM_DeInit() ComM should have status COMM_UNINIT, and a new call to ComM_Init needed to make sure ComM restart
*   internal state machines to defailt values.
*   @param[out] Status  status of ComM module.
*               - COMM_UNINIT: The ComM is not initialized or not usable. Default value after startup or after
*               ComM_DeInit() is called.
*               - COMM_INIT: The ComM is initialized and usable.
*   @return     status of the request
*               - E_OK: Successfully return of initialization status
*               - E_NOT_OK: Return of initialization status failed
*   @ServiceID  0x03
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType,COMM_CODE) ComM_GetStatus(P2VAR(ComM_InitStatusType,AUTOMATIC,COMM_APPL_DATA) Status)
{
    uint8 ErrorId = COMM_E_NO_ERROR;
    Std_ReturnType ReturnValue = E_NOT_OK;

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (NULL_PTR == Status)
    {
        ErrorId = COMM_E_PARAM_POINTER;
    }
#endif
    else
    {
        ComM_EnterCriticalSection();
        /* Get Init Status of ComM Module */
        *Status = ComM_InitStatus;
        ComM_ExitCriticalSection();
        ReturnValue = E_OK;
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_GETSTATUS, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      This method returns the inhibition status of a ComM channel.
*   @param[in]  Channel The Network Channel for the requested state of ComM state machine.
*   @param[out] Status  Inhibition status of ComM.
*               -Bit 0(LSB): Wake Up inhibition active
*               -Bit 1: Limit to COMM_NO_COMMUNICATION mode
*   @return     status of the request
*               - E_OK: Successfully returned Inhibition Status
*               - E_NOT_OK: Return of Inhibition Status failed
*   @ServiceID  0x04
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType,COMM_CODE) ComM_GetInhibitionStatus
(
    NetworkHandleType Channel,
    P2VAR(ComM_InhibitionStatusType,AUTOMATIC,COMM_APPL_DATA) Status
)
{
    Std_ReturnType ReturnValue = E_NOT_OK;
    uint8 ErrorId = COMM_E_NO_ERROR;

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (COMM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
    else if (NULL_PTR == Status)
    {
        ErrorId = COMM_E_PARAM_POINTER;
    }
#endif
    else
    {
        /* Get Inhibition status */
        *Status = ComM_Inhibition.ChannelInhibitionStatus[Channel];
        ReturnValue = E_OK;
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_GETINHIBITIONSTATUS, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      This method is used for requesting of a Communication Mode by a user.
*   @param[in]  User Handle of the user who requests a mode.
*   @param[in]  ComMode ComM mode requested by the user.
*               COMM_FULL_COMMUNICATION  - channel shall have both transmission and reception capability
*               COMM_NO_COMMUNICATION - channel shall stop both transmission and reception capability
*   @return     status of the request
*               - E_OK: Successfully changed to the new mode.
*               - E_NOT_OK: Changing to the new mode failed.
*               - COMM_E_MODE_LIMITATION: Mode can not be granted because of mode inhibition.
*   @ServiceID  0x05
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
*   @note Internally mode COMM_SILENT_COMMUNICATION is not a valid request for a user, mode used for synchronization
*   at shutdown. Valid modes are COMM_NO_COMMUNICATION and COMM_FULL_COMMUNICATION.
********************************************************************************************************************/
FUNC(Std_ReturnType,COMM_CODE) ComM_RequestComMode(ComM_UserHandleType User, ComM_ModeType ComMode)
{
    uint8 UserMask = 0U;
    uint8 UserBitOffset = 0U;
    uint8 ErrorId = COMM_E_NO_ERROR;
    NetworkHandleType ChannelId = 0U;
    ComM_UserHandleType UserByteOffset = 0U;
    Std_ReturnType ReturnValue = E_NOT_OK;
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (((COMM_NO_COMMUNICATION != ComMode) && (COMM_FULL_COMMUNICATION != ComMode)) ||
             (COMM_NUM_OF_USERS <= User))
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
#endif
    else
    {
        ReturnValue = E_OK;
        /* Enter Critical section */
        ComM_EnterCriticalSection();
        /* Update Requested User Mode */
        ComM_UserRequestedMode[User] = ComMode;
        /* Exit Critical section */
        ComM_ExitCriticalSection();
        /* Get User Byte and Bit offset of the requested user */
        UserByteOffset = User/8U;
        UserBitOffset = User%8U;
        /* Loop through Channels assigned to the requested User */
        for(ChannelId = 0U; (ChannelId < COMM_NUM_OF_CHANNELS); ChannelId++)
        {
            ChannelConfigPtr = &ComM_ChannelConfig[ChannelId];
            /* Get User mask */
            UserMask = ChannelConfigPtr->UsersToChannelMap[UserByteOffset];
            /* Check whether channel associated with this group */
            if (0U != ((UserMask) & ((uint8)(1U << UserBitOffset))))
            {
                if (ComMode == COMM_FULL_COMMUNICATION)
                {
#if ((STD_ON == COMM_MODE_LIMITATION_ENABLED) || (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED))
                    if ( FALSE != ComM_IsChannelInhibitionEnabled(ChannelId))
                    {
                        ReturnValue = COMM_E_MODE_LIMITATION;
                    }
                    else
                    {
                        ComM_ChannelUserRequestedMode[ChannelId] = ComMode;
                    }
#else
                    ComM_ChannelUserRequestedMode[ChannelId] = ComMode;
#endif
                }
                else
                {
                    ComM_ChannelUserRequestedMode[ChannelId] = ComMode;
                }
            }
        }
    }
#if ((STD_ON == COMM_MODE_LIMITATION_ENABLED) || (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED))
    if (COMM_E_MODE_LIMITATION == ReturnValue)
    {
        /* SWS_ComM_00141 SWS_ComM_00142 */
        if (COMM_INHIBITION_MAX_VALUE > ComM_Inhibition.InhibitionCount)
        {
            ComM_Inhibition.InhibitionCount++;
        }
    }
#endif
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_REQUESTCOMMODE, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return ReturnValue;
}


/********************************************************************************************************************
*   @brief      This method is used to query the maximum allowed Communication Mode of the corresponding user.
*   @param[in]  User Handle of the user who requests a mode.
*   @param[out] ComMode maximum allowed ComM mode.
*               COMM_FULL_COMMUNICATION - channel shall have both transmission and reception capability
*               COMM_NO_COMMUNICATION - channel shall stop both transmission and reception capability
*   @return     status of the request
*               - E_OK: Successfully returned maximum allowed Communication Mode.
*               - E_NOT_OK: Return of maximum allowed Communication Mode failed.
*   @ServiceID  0x06
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType,COMM_CODE) ComM_GetMaxComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) ComMode
)
{
    /* Local Variables */
    uint8 ErrorId = COMM_E_NO_ERROR;
    Std_ReturnType ReturnValue = E_NOT_OK;
#if ((STD_ON == COMM_MODE_LIMITATION_ENABLED) || (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED))
    uint8 UserMask = 0U;
    uint8 UserBitOffset = 0U;
    NetworkHandleType ChannelId = 0U;
    ComM_UserHandleType UserByteOffset = 0U;
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;
#endif

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (COMM_NUM_OF_USERS <= User)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
    else if (NULL_PTR == ComMode)
    {
        ErrorId = COMM_E_PARAM_POINTER;
    }
#endif
    else
    {
        /* Initialize Com Mode */
        *ComMode = (ComM_ModeType)COMM_FULL_COMMUNICATION;
        /* Set ReturnValue to E_OK */
        ReturnValue = E_OK;
#if ((STD_ON == COMM_MODE_LIMITATION_ENABLED) || (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED))
        /* Get Byte and Bit offset */
        UserByteOffset = User/8U;
        UserBitOffset = User%8U;
        for(ChannelId = 0U; ((ChannelId < COMM_NUM_OF_CHANNELS) && (COMM_FULL_COMMUNICATION == *ComMode)); ChannelId++)
        {
            ChannelConfigPtr = &ComM_ChannelConfig[ChannelId];
            /* Get User mask */
            UserMask = ChannelConfigPtr->UsersToChannelMap[UserByteOffset];
            if (0U != ((UserMask) & ((uint8)(1U << UserBitOffset))))
            {
                /* Get Channel Inhibition Status .*/
                if (FALSE != ComM_IsChannelInhibitionEnabled(ChannelId))
                {
                    /* Update Com Mode */
                    *ComMode = (ComM_ModeType)COMM_NO_COMMUNICATION;
                }
            }
        }
#endif
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_GETMAXCOMMODE, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      This method is used to query the currently requested Communication Mode of the corresponding user.
*   @param[in]  User Handle of the user who requests a mode.
*   @param[out] ComMode ComM mode which is already requested by the user.
*               COMM_FULL_COMMUNICATION - channel shall have both transmission and reception capability
*               COMM_NO_COMMUNICATION - channel shall stop both transmission and reception capability
*   @return     status of the request
*               - E_OK: Successfully returned requested Communication Mode.
*               - E_NOT_OK: Return of requested Communication Mode failed.
*   @ServiceID  0x07
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType,COMM_CODE) ComM_GetRequestedComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) ComMode
)
{
    /* Local Variables */
    uint8 ErrorId = COMM_E_NO_ERROR;
    Std_ReturnType ReturnValue = E_NOT_OK;

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (COMM_NUM_OF_USERS <= User)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
    else if (NULL_PTR == ComMode)
    {
        ErrorId = COMM_E_PARAM_POINTER;
    }
#endif
    else
    {
        /* Update Requested User Mode */
        *ComMode = ComM_UserRequestedMode[User];
        /* Update return value */
        ReturnValue = E_OK;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_GETREQUESTEDCOMMODE, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      This method is used to query  to query the current Communication Mode. ComM shall use the
*   corresponding interfaces of the Bus State Managers to get the current Communication Mode of the network.
*   @param[in]  User Handle of the user who requests a mode.
*   @param[out] ComMode current ComM mode.
*               COMM_FULL_COMMUNICATION - channel shall have both transmission and reception capability
*               COMM_NO_COMMUNICATION - channel shall stop both transmission and reception capability
*               COMM_SILENT_COMMUNICATION : channel shall have only reception capability and stop both transmission.capability
*   @return     status of the request
*               - E_OK: Successfully returned Communication Mode from Bus State Manager.
*               - E_NOT_OK: Return of Communication Mode from Bus State Manager failed.
*   @ServiceID  0x08
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
*   @note COMM_SILENT_COMMUNICATION should not be used by the user.
********************************************************************************************************************/
FUNC(Std_ReturnType,COMM_CODE) ComM_GetCurrentComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType,AUTOMATIC,COMM_APPL_DATA) ComMode
)
{
    /* Local Variables */
    uint8 UserMask = 0U;
    uint8 UserBitOffset = 0U;
    uint8 ErrorId = COMM_E_NO_ERROR;
    NetworkHandleType ChannelId = 0U;
    Std_ReturnType ReturnValue = E_NOT_OK;
    ComM_UserHandleType UserByteOffset = 0U;
    ComM_ModeType Mode = COMM_NO_COMMUNICATION;
    P2CONST(ComM_BusSMComMModeFnConfigType,AUTOMATIC,COMM_APPL_CONST) BusSMComMModeFnConfigPtr;
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (COMM_NUM_OF_USERS <= User)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
    else if (NULL_PTR == ComMode)
    {
        ErrorId = COMM_E_PARAM_POINTER;
    }
#endif
    else
    {
        ReturnValue = E_OK;
        /* Get Byte and Bit offset */
        UserByteOffset = User/8U;
        UserBitOffset = User%8U;
        ComM_EnterCriticalSection();
        /* Initialize Com Mode */
        *ComMode = (ComM_ModeType)COMM_FULL_COMMUNICATION;
        for(ChannelId = 0U; (ChannelId < COMM_NUM_OF_CHANNELS) ; ChannelId++)
        {
            ChannelConfigPtr = &ComM_ChannelConfig[ChannelId];
            /* Get Channel mask */
            UserMask = ChannelConfigPtr->UsersToChannelMap[UserByteOffset];
            if (0U != ((UserMask) & ((uint8)(1U << UserBitOffset))))
            {
                if (COMM_NUM_OF_SUPPORTED_BUS > ChannelConfigPtr->BusSMFnConfigId)
                {
                    /* request bus SM com mode */
                    BusSMComMModeFnConfigPtr = &ComM_BusSMComMModeFnConfig[ChannelConfigPtr->BusSMFnConfigId];
                    if (NULL_PTR != BusSMComMModeFnConfigPtr->BusSMGetCurrentComModeFn)
                    {
                        /* SWS_ComM_00073 , set the lowest mode for the user*/
                        (void)BusSMComMModeFnConfigPtr->BusSMGetCurrentComModeFn(ChannelId,&Mode);
                        if (Mode < *ComMode)
                        {
                            *ComMode = Mode;
                        }
                    }
                }
            }
        }
        ComM_ExitCriticalSection();
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_GETCURRENTCOMMODE, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      This method is used to change the inhibition status COMM_NO_WAKEUP for the corresponding channel.
*   @param[in]  Channel The Network Channel for the requested state of ComM state machine.
*   @param[in]  Status Wake up inhibition status.
*               - FALSE: Wake up inhibition is switched off
*               - TRUE: Wake up inhibition is switched on Parameters
*   @return     status of the request
*               - E_OK: Successfully changed wake up status for the channel
*               - E_NOT_OK: Changed of wake up status for the channel failed
*   @ServiceID  0x09
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType,COMM_CODE) ComM_PreventWakeUp(NetworkHandleType Channel, boolean Status)
{
    uint8 ErrorId = COMM_E_NO_ERROR;
    Std_ReturnType ReturnValue = E_NOT_OK;

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (COMM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
    else
#endif
    {
        ComM_EnterCriticalSection();
        if (TRUE == Status)
        {
            /* Check if ECU support Wake-up inhibition  */
            if (FALSE !=COMM_IS_WAKEUP_INHIBITION_SET(ComM_Inhibition.EcuInhibitionStatus))
            {
                ComM_Inhibition.ChannelInhibitionStatus[Channel] |= COMM_WAKEUP_INHIBITION_SET_MASK;
                ReturnValue = E_OK;
            }
        }
        else
        {
            ComM_Inhibition.ChannelInhibitionStatus[Channel] &= COMM_WAKEUP_INHIBITION_CLEAR_MASK;
            ReturnValue = E_OK;
        }
        ComM_ExitCriticalSection();
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_PREVENTWAKEUP, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif

    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      This method is used to changes the inhibition status for the channel for changing from
*   COMM_NO_COMMUNICATION to a higher Communication Mode.
*   @param[in]  Channel The Network Channel for the requested state of ComM state machine.
*   @param[in]  Status channel limit status.
*               - FALSE: Limit channel to COMM_NO_COMMUNICATION disabled
*               - TRUE: Limit channel to COMM_NO_COMMUNICATION enabled
*   @return     status of the request
*               - E_OK: Successfully changed inhibition status for the channel
*               - E_NOT_OK: Changed of inhibition status for the channel failed
*   @ServiceID  0x0b
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType,COMM_CODE) ComM_LimitChannelToNoComMode(NetworkHandleType Channel, boolean Status)
{
    uint8 ErrorId = COMM_E_NO_ERROR;
    Std_ReturnType ReturnValue = E_NOT_OK;
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;
    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (COMM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
#endif
    else
    {
        ChannelConfigPtr = &ComM_ChannelConfig[Channel];
        if (TRUE == Status)
        {
            /* set if the channel is in full com network request state .SWS_ComM_00841*/
            if ((COMM_FULL_COM_NETWORK_REQUESTED == ComM_CurrentState[Channel]) &&
                    (FALSE != COMM_IS_LIMIT_TO_NO_COM_INHIBITION_SET(ComM_Inhibition.EcuInhibitionStatus)) &&
                    (COMM_NM_VARIANT_TYPE_NONE != ChannelConfigPtr->NmVariantType))
            {
                ComM_Inhibition.ChannelInhibitionStatus[Channel] |= COMM_LIMIT_TO_NOCOM_SET_MASK;
                ReturnValue = E_OK;
            }
        }
        else
        {
            /* SWS_ComM_00066 */
            if (COMM_NM_VARIANT_TYPE_PASSIVE != ChannelConfigPtr->NmVariantType)
            {
                ComM_Inhibition.ChannelInhibitionStatus[Channel] &= COMM_LIMIT_TO_NOCOM_CLEAR_MASK;
                ReturnValue = E_OK;
            }
        }
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_PREVENTWAKEUP, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif

    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      This method is used to Changes the inhibition status for the ECU (=all channels) for changing from
*   COMM_NO_COMMUNICATION to a higher Communication Mode.
*   @param[in]  Status channel limit status.
*               - FALSE: Limit ECU to COMM_NO_COMMUNICATION disabled.
*               - TRUE: Limit ECU to COMM_NO_COMMUNICATION enabled.
*   @return     status of the request
*               - E_OK: Successfully changed inhibition status for the ECU
*               - E_NOT_OK: Changed of inhibition status for the ECU failed
*   @ServiceID  0x0C
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType,COMM_CODE) ComM_LimitECUToNoComMode(boolean Status)
{
    uint8 ChannelId = 0U;
    uint8 ErrorId = COMM_E_NO_ERROR;
    Std_ReturnType ReturnValue = E_NOT_OK;

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
    else
    {
        ReturnValue = E_OK;
        ComM_EnterCriticalSection();
        for (ChannelId = 0U; ChannelId < COMM_NUM_OF_CHANNELS; ChannelId++)
        {
            /* return E_NOT_OK if any channel request returns E_NOT_OK */
            if (((uint8)E_OK) != ComM_LimitChannelToNoComMode(ChannelId,Status))
            {
                ReturnValue = E_NOT_OK;
                break;
            }
        }
        ComM_ExitCriticalSection();
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_LIMITECUTONOCOMMODE, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      This method returns the amount of rejected COMM_FULL_COMMUNICATION user requests.
*   @param[out] CounterValue Amount of rejected COMM_FULL_COMMUNICATION user requests.
*   @return     status of the request
*               - E_OK: Successfully returned Inhibition Counter
*               - E_NOT_OK: Return of Inhibition Counter failed
*   @ServiceID  0x0D
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType,COMM_CODE) ComM_ReadInhibitCounter(P2VAR(uint16,AUTOMATIC,COMM_APPL_DATA) CounterValue)
{
    uint8 ErrorId = COMM_E_NO_ERROR;
    Std_ReturnType ReturnValue = E_NOT_OK;

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (NULL_PTR == CounterValue)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
#endif
    else
    {
        ComM_EnterCriticalSection();
        *CounterValue = ComM_Inhibition.InhibitionCount;
        ReturnValue = E_OK;
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_READINHIBITCOUNTER, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif

    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      This method resets the Inhibited COMM_FULL_COMMUNICATION request Counter.
*   @return     status of the request
*               - E_OK: Successfully reset of Inhibit COMM_FULL_COMMUNICATION Counter
*               - E_NOT_OK: Reset of Inhibit COMM_FULL_COMMUNICATION Counter failed
*   @ServiceID  0x0E
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType,COMM_CODE) ComM_ResetInhibitCounter(void)
{
    uint8 ErrorId = COMM_E_NO_ERROR;
    Std_ReturnType ReturnValue = E_NOT_OK;

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
    else
    {
        ComM_EnterCriticalSection();
        /* Set  inhibition counter to zero */
        ComM_Inhibition.InhibitionCount = 0U;
        ComM_ExitCriticalSection();
        ReturnValue = E_OK;
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(ErrorId != COMM_E_NO_ERROR)
    {
        ComM_DetReportError(COMM_SID_RESETINHIBITCOUNTER, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      This method changes the ECU Group Classification status.
*   @param[in]  Status Inhibition status of ComM.
*               - Bit 0(LSB): Wake Up inhibition active
*               - Bit 1: Limit to COMM_NO_COMMUNICATION mode
*   @return     status of the request
*               - E_OK: Successfully change the ECU Group Classification Status
*               - E_NOT_OK: Change of the ECU Group Classification Status failed
*   @ServiceID  0x0F
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType,COMM_CODE) ComM_SetECUGroupClassification(ComM_InhibitionStatusType Status)
{
    uint8 ErrorId = COMM_E_NO_ERROR;
    Std_ReturnType ReturnValue = E_NOT_OK;

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if(COMM_INHIBITIONSTATUS_MAX_VALUE < Status)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
#endif
    else
    {
        ComM_EnterCriticalSection();
        /* update the Ecu Inhibition status */
        ComM_Inhibition.EcuInhibitionStatus = Status;
        ComM_ExitCriticalSection();
        ReturnValue = E_OK;
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_SETECUGROUPCLASSIFICATION, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      This method returns the published information.
*   @param[out] Versioninfo Version information of ComM module.
*   @ServiceID  0x10
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(void,COMM_CODE) ComM_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,COMM_APPL_DATA) Versioninfo)
{
    /* Local Variables */
    uint8 ErrorId = COMM_E_NO_ERROR;

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    /* Check if parameter VersionInfo is valid */
    if (NULL_PTR == Versioninfo)
    {
        ErrorId = COMM_E_PARAM_POINTER;
    }
    else
#endif
    {
        Versioninfo->vendorID         = COMM_VENDOR_ID;
        Versioninfo->moduleID         = COMM_MODULE_ID;
        Versioninfo->sw_major_version = COMM_SW_MAJOR_VERSION;
        Versioninfo->sw_minor_version = COMM_SW_MINOR_VERSION;
        Versioninfo->sw_patch_version = COMM_SW_PATCH_VERSION;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if (COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_GETVERSIONINFO, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This method perform the processing of the AUTOSAR ComM activities that are not directly initiated by
*   the calls e.g. from the RTE. Each channel has separate main function which will call this method.
*   @param[in] Channel Network channel for which the main function processing should be done.
*   @ServiceID  0x60
********************************************************************************************************************/
FUNC(void,COMM_CODE) ComM_MainFunction(NetworkHandleType Channel)
{
    /* Local Variables */
    uint8 ErrorId = COMM_E_NO_ERROR;
    ComM_StateType NewComMState = COMM_NO_COM_NO_PENDING_REQUEST;
    ComM_StateType CurrentComMState = COMM_NO_COM_NO_PENDING_REQUEST;
    ComM_StateType highestRequestedMode = COMM_NO_COM_NO_PENDING_REQUEST;
    P2CONST(ComM_StateFunctionListConfigType,AUTOMATIC,COMM_APPL_CONST) StateFunctionListConfigPtr;

    if (COMM_INIT != ComM_InitStatus)
    {
        /* Module is not Initialized */
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (COMM_NUM_OF_CHANNELS <= Channel)
    {
        /* Channel is not enabled */
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
#endif
    else
    {
    	/* get the highest requested mode for the channel */
        highestRequestedMode = ComM_GetHighestRequestMode(Channel);
        CurrentComMState = ComM_CurrentState[Channel];
        if (COMM_MAX_NUMBER_OF_STATES > CurrentComMState )
        {
            StateFunctionListConfigPtr = &ComM_StateFunctionListConfig[CurrentComMState];
            if (NULL_PTR != StateFunctionListConfigPtr->StateProcessorFn)
            {
                /* process the ComM state */
                ComM_EnterCriticalSection();
                NewComMState = StateFunctionListConfigPtr->StateProcessorFn(Channel,highestRequestedMode);
                if((NewComMState != CurrentComMState) && (COMM_MAX_NUMBER_OF_STATES > NewComMState))
                {
                    StateFunctionListConfigPtr = &ComM_StateFunctionListConfig[NewComMState];
                    if (NULL_PTR != StateFunctionListConfigPtr->StateOnEntryActionFn)
                    {
                        StateFunctionListConfigPtr->StateOnEntryActionFn(Channel,CurrentComMState);
                    }
                    ComM_CurrentState[Channel] = NewComMState;
                }
                ComM_ExitCriticalSection();
            }
        }
#if (STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT)
		/* update user about change notification */
		if (TRUE == ComM_IsBusSmModeChanged[Channel])
		{
			ComM_EnterCriticalSection();
			ComM_IsBusSmModeChanged[Channel] = FALSE;
			ComM_ExitCriticalSection();
			/* Notify to user - RTE*/
			ComM_BusSMSateChangeNotificationToUser(Channel);
		}
#endif
#if (STD_ON == COMM_PNC_SUPPORT)
        ComM_PncStateProcessing(Channel);
#endif
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_MAINFUNCTION, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
}

#if (STD_ON == COMM_PNC_SUPPORT)
/********************************************************************************************************************
*   @brief      This method is used to udpate the ERA and EIRA changes. This method is called by the ComM_COMCbk_<sn>
*   from the ComM configuration source file.
*   @param[in] Channel Network channel for which the ERA and EIRA update.
*   @param[in] SiganalDataPtr pointer to the ERA and EIRA data
*   @param[in] SignalDataLength ERA and EIRA data length.
*
********************************************************************************************************************/
FUNC(void,COMM_CODE) ComM_UpdateEiraEraData
(
    NetworkHandleType Channel,
    P2CONST(uint8,AUTOMATIC,COMM_APPL_CONST)SiganalDataPtr,
    uint32 SignalDataLength
)
{
    /* PN Not implemented */
    COMM_IGNORE_UNUSED_PARAM(SiganalDataPtr);
    COMM_IGNORE_UNUSED_PARAM(SignalDataLength);
    COMM_IGNORE_UNUSED_PARAM(Channel);
}
#endif
/********************************************************************************************************************
*   @brief      This method called by Nm to indicate that a NM-message has been received in the Bus Sleep Mode,
*   what indicates that some nodes in the network have already entered the Network Mode.
*   @param[in]  Channel The Network Channel for which this indication is called.
*   @ServiceID  0x15
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(void,COMM_CODE) ComM_Nm_NetworkStartIndication(NetworkHandleType Channel)
{
    uint8 ErrorId = COMM_E_NO_ERROR;
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;
#if (STD_ON == COMM_SYNCHRONOUS_WAKEUP)
    NetworkHandleType ChannelId;
#endif

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (COMM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
#endif
    else
    {
        ChannelConfigPtr = &ComM_ChannelConfig[Channel];
        if ((COMM_NM_VARIANT_TYPE_FULL == ChannelConfigPtr->NmVariantType) ||
                (COMM_NM_VARIANT_TYPE_PASSIVE == ChannelConfigPtr->NmVariantType))
        {
            /* check whether the channel has Nm */
            /* SWS_ComM_00583 The ComM module shall switch channel X to COMM_FULL_COMMUNICATION if NM indicates
               ComM_Nm_NetworkStartIndication(<channel X>)*/
            ComM_EnterCriticalSection();
#if (STD_ON == COMM_SYNCHRONOUS_WAKEUP)
            /* if synchronous wakeup is enabled , then wakeup all channels */
            for (ChannelId = 0U; ChannelId < COMM_NUM_OF_CHANNELS; ChannelId++)
            {
                ComM_BusNmRequestedState[Channel] = COMM_FULL_COM_NETWORK_REQUESTED;
            }
#else
            /* set state to NoCom Request to full com request */
            ComM_BusNmRequestedState[Channel] = COMM_FULL_COM_NETWORK_REQUESTED;
#endif
            ComM_ExitCriticalSection();
        }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
        else
        {
            ErrorId = COMM_E_WRONG_PARAMETERS;
        }
#endif
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_NM_NETWORKSTARTINDICATION,ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This method called by Nm to notify the network management has entered Network Mode.
*   @param[in]  Channel The Network Channel for which this notification is called.
*   @ServiceID  0x18
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(void,COMM_CODE) ComM_Nm_NetworkMode(NetworkHandleType Channel)
{
    uint8 ErrorId = COMM_E_NO_ERROR;
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;
    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (COMM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
#endif
    else
    {
        ChannelConfigPtr = &ComM_ChannelConfig[Channel];
        /* [SWS_ComM_00296] In state COMM_SILENT_COMMUNICATION and the Network Manager module indicates
            ComM_Nm_NetworkMode() , the ComM channel state machine shall switch to state
            COMM_FULL_COMMUNICATION and sub-state COMM_FULL_COM_READY_SLEEP.*/
        if ((COMM_NM_VARIANT_TYPE_FULL == ChannelConfigPtr->NmVariantType) ||
                (COMM_NM_VARIANT_TYPE_PASSIVE == ChannelConfigPtr->NmVariantType))
        {
            /* if ((COMM_FULL_COM_READY_SLEEP == COMM_SILENT_COM == ComM_CurrentState[Channel]) ||
                (COMM_SILENT_COM == ComM_CurrentState[Channel]) ||) */
            {
                ComM_EnterCriticalSection();
                /* set state to NoCom Request to full com request */
                ComM_BusNmRequestedState[Channel] = COMM_FULL_COM_NETWORK_REQUESTED ;
                ComM_ExitCriticalSection();
            }
        }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
        else
        {
            ErrorId = COMM_E_WRONG_PARAMETERS;
        }
#endif
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_NM_NETWORKMODE,ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This method called by Nm to notify the network management has entered Prepare Bus-Sleep Mode.
*   @param[in]  Channel The Network Channel for which this notification is called.
*   @ServiceID  0x19
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant (but not for the same NM-Channel)
********************************************************************************************************************/
FUNC(void,COMM_CODE) ComM_Nm_PrepareBusSleepMode(NetworkHandleType Channel)
{
    uint8 ErrorId = COMM_E_NO_ERROR;
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;
    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (COMM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
#endif
    else
    {
        ChannelConfigPtr = &ComM_ChannelConfig[Channel];
        if ((COMM_NM_VARIANT_TYPE_FULL == ChannelConfigPtr->NmVariantType) ||
                (COMM_NM_VARIANT_TYPE_PASSIVE == ChannelConfigPtr->NmVariantType))
        {
            /* SWS_ComM_00826 In COMM_FULL_COMMUNICATION and configuration parameter ComMNmVariant=FULL|PASSIVE and the
               Network Manager module indicates ComM_Nm_PrepareBusSleepMode() , the ComM state machine shall switch to
               state COMM_SILENT_COMMUNICATION */
            ComM_EnterCriticalSection();
            /* update the requested mode. */
            ComM_BusNmRequestedState[Channel] = COMM_SILENT_COM;
            ComM_ExitCriticalSection();
        }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
        else
        {
            ErrorId = COMM_E_WRONG_PARAMETERS;
        }
#endif
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_NM_PREPAREBUSSLEEPMODE,ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This method called by Nm to notify that the network management has entered Bus-Sleep Mode.
*   This callback function should perform a transition of the hardware and transceiver to bus-sleep mode.
*   @param[in]  Channel The Network Channel for which this notification is called.
*   @ServiceID  0x1a
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(void,COMM_CODE) ComM_Nm_BusSleepMode(NetworkHandleType Channel)
{
    uint8 ErrorId = COMM_E_NO_ERROR;
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;
    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (COMM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
#endif
    else
    {
        ChannelConfigPtr = &ComM_ChannelConfig[Channel];
        if ((COMM_NM_VARIANT_TYPE_FULL == ChannelConfigPtr->NmVariantType) ||
                (COMM_NM_VARIANT_TYPE_PASSIVE == ChannelConfigPtr->NmVariantType))
        {
            /* SWS_ComM_00295 In state COMM_SILENT_COMMUNICATION and the Network Manager module indicates
               ComM_Nm_BusSleepMode(), the ComM channel state machine shall switch to state COMM_NO_COMMUNICATION */
            /* SWS_ComM_00637 In state COMM_FULL_COMMUNICATION and the Network Manager module indicates ,
               ComM_Nm_BusSleepMode() the ComM channel state machine shall switch to state COMM_NO_COMMUNICATION */
            ComM_EnterCriticalSection();
            /* update the requested mode. */
            ComM_BusNmRequestedState[Channel] = COMM_NO_COM_NO_PENDING_REQUEST;
            ComM_ExitCriticalSection();
        }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
        else
        {
            ErrorId = COMM_E_WRONG_PARAMETERS;
        }
#endif
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_NM_BUSSLEEPMODE,ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This method called by Nm to notify that not all coordinated busses have indicated bus sleep state and
*   on at least on one of the coordinated busses NM is restarted when the Network management interface has started to
*   shut down the coordinated busses.
*   @param[in]  Channel The Network Channel for which this notification is called.
*   @ServiceID  0x1b
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(void,COMM_CODE) ComM_Nm_RestartIndication(NetworkHandleType Channel)
{
    uint8 ErrorId = COMM_E_NO_ERROR;
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;
#if (STD_ON == COMM_SYNCHRONOUS_WAKEUP)
    NetworkHandleType ChannelId = 0U;
#endif

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (COMM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
#endif
    else
    {
        ChannelConfigPtr = &ComM_ChannelConfig[Channel];
        if ((COMM_NM_VARIANT_TYPE_FULL == ChannelConfigPtr->NmVariantType) ||
                (COMM_NM_VARIANT_TYPE_PASSIVE == ChannelConfigPtr->NmVariantType))
        {
            /* SWS_ComM_00894 In sub-state COMM_NO_COM_NO_PENDING_REQUEST and the NM module indicates a restart,
               ComM_Nm_RestartIndication(), the ComM channel state machine shall immediately switch to
               sub-state COMM_NO_COM_REQUEST_PENDING */
            ComM_EnterCriticalSection();
#if (STD_ON == COMM_SYNCHRONOUS_WAKEUP)
            /* if synchronous wakeup is enabled , then wakeup all channels */
            for (ChannelId = 0U; ChannelId < COMM_NUM_OF_CHANNELS; ChannelId++)
            {
                ComM_BusNmRequestedState[Channel] = COMM_FULL_COM_NETWORK_REQUESTED;
            }
#else
            /* set state to NoCom Request to full com request */
            ComM_BusNmRequestedState[Channel] = COMM_FULL_COM_NETWORK_REQUESTED;
#endif
            ComM_ExitCriticalSection();
        }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
        else
        {
            ErrorId = COMM_E_WRONG_PARAMETERS;
        }
#endif
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_NM_RESTARTINDICATION,ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This method called by DCM to indicate active diagnostic.
*   @param[in]  Channel The Network Channel for which is needed for Diagnostic communication
*   @ServiceID  0x1F
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(void,COMM_CODE) ComM_DCM_ActiveDiagnostic(NetworkHandleType Channel)
{
    uint8 ErrorId = COMM_E_NO_ERROR;
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (COMM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
#endif
    else
    {
        ChannelConfigPtr = &ComM_ChannelConfig[Channel];
        /* SWS_ComM_00866 If configuration parameter ComMNmVariant=FULL|LIGHT|NONE , an DCM_ActiveDiagnostic
        indication shall be treated as a COMM_FULL_COMMUNICATION request for the specified communication channel
        */
        if (COMM_NM_VARIANT_TYPE_PASSIVE != ChannelConfigPtr->NmVariantType)
        {
            ComM_EnterCriticalSection();
            /* set diag active request to true . It will be processed in the main function  */
            ComM_DcmFullComRequest[Channel] = TRUE;
            ComM_ExitCriticalSection();
        }
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_DCM_ACTIVEDIAGNOSTIC,ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This method called by DCM to indicate inactive diagnostic.
*   @param[in]  Channel The Network Channel for which doesnt needed for Diagnostic communication
*   @ServiceID  0x20
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(void,COMM_CODE) ComM_DCM_InactiveDiagnostic(NetworkHandleType Channel)
{
    uint8 ErrorId = COMM_E_NO_ERROR;

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (COMM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
#endif
    else
    {
        ComM_EnterCriticalSection();
        /* set diag active request to false . It will be processed in the main function  */
        ComM_DcmFullComRequest[Channel] = FALSE;
        ComM_ExitCriticalSection();
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_DCM_INACTIVEDIAGNOSTIC,ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This method called by EcuM to notify wake up on the corresponding channel.
*   @param[in]  Channel The Network Channel for which wakeup notification is called.
*   @ServiceID  0x2A
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(void,COMM_CODE) ComM_EcuM_WakeUpIndication(NetworkHandleType Channel)
{
    uint8 ErrorId = COMM_E_NO_ERROR;
#if (STD_ON == COMM_SYNCHRONOUS_WAKEUP)
    NetworkHandleType ChannelId = 0U;
#endif
    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (COMM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
#endif
    else
    {
        /*  SWS_ComM_00893 In sub-state COMM_NO_COM_NO_PENDING_REQUEST and a wake-up-indication is indicated by the
            EcuM module, ComM_EcuM_WakeUpIndication() SWS_ComM_00275, the ComM channel state machine shall immediately
            switch to sub-state COMM_NO_COM_REQUEST_PENDING
        */
        ComM_EnterCriticalSection();
#if (STD_ON == COMM_SYNCHRONOUS_WAKEUP)
        /* if synchronous wakeup is enabled , then wakeup all channels */
        for (ChannelId = 0U; ChannelId < COMM_NUM_OF_CHANNELS; ChannelId++)
        {
            ComM_EcuMWakeupIndicationStatus[ChannelId] = TRUE;
        }
#else
        /* set state to NoCom Reqeust to full com request */
        ComM_EcuMWakeupIndicationStatus[Channel] = TRUE;
#endif
        ComM_ExitCriticalSection();
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_ECUM_WAKEUPINDICATION,ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
}

#if (STD_ON == COMM_PNC_SUPPORT)
/********************************************************************************************************************
*   @brief      This method called by EcuM to notify wake up on the corresponding PNC .
*   @param[in]  PncId Identifier of the partial network cluster
*   @ServiceID  0x37
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(void,COMM_CODE) ComM_EcuM_PNCWakeUpIndication( PNCHandleType PncId )
{
    ComM_PncIdType PncIndex;
    uint8 ErrorId = COMM_E_NO_ERROR;
    NetworkHandleType ChannelId = 0U;
    ComM_PncToChannelMapIdType PncToChannelMapId;
    P2CONST(ComM_PncConfigType,AUTOMATIC,COMM_APPL_CONST) pPncConfig;

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
    else
    {
        /* find if the PNC Id exists */
        for (PncIndex = 0; PncIndex < COMM_NUM_OF_PNC; PncIndex++)
        {
            pPncConfig  = &ComM_PncConfig[PncIndex];
            if (PncId == pPncConfig->PncHandle )
            {
                break;
            }
        }
        /* Process if the Valid Handle Exists */
        if (PncIndex < COMM_NUM_OF_PNC)
        {
            /* Set the wakeup indication flag */
            if (COMM_PNC_NO_COMMUNICATION == ComM_PncCurrentMode[PncIndex])
            {
            	ComM_EcuMPncWakeupIndicationStatus[PncIndex] = TRUE;
            }

            #if (STD_ON == COMM_SYNCHRONOUS_WAKEUP)
            /* if synchronous wakeup is enabled , then wakeup all channels */
            for (ChannelId = 0U; ChannelId < COMM_NUM_OF_CHANNELS; ChannelId++)
            {
                ComM_EcuMWakeupIndicationStatus[ChannelId] = TRUE;
            }
            #else
            /* wake all the channel of the PNC */
            for(PncToChannelMapId = pPncConfig->PncChannelStartId;
                ((PncToChannelMapId <= pPncConfig->PncChannelEndId) && \
                (PncToChannelMapId < COMM_NUM_OF_PNC_TO_CHANNEL_MAP));
                PncToChannelMapId++)
            {
            	ChannelId = ComM_PncToChannelMapConfig[PncToChannelMapId];
            	if (COMM_NUM_OF_CHANNELS > ChannelId)
            	{
            		ComM_EcuMWakeupIndicationStatus[ChannelId] = TRUE;
            	}
            }
            #endif
        }
        else
        {
            /* PNC id not found */
            ErrorId = COMM_E_WRONG_PARAMETERS;
        }
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_ECUM_PNCWAKEUPINDICATION,ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif

}
#endif
/********************************************************************************************************************
*   @brief      This method called by EcuM or BswM to indicate when communication is allowed.
*   If EcuM/Fixed is used then this method is called by EcuM.
*   If EcuM/Flex is used then this method is called by BswM.
*   @param[in]  Channel The Network Channel for which communication request is called.
*   @param[in]  Allowed value of communication request.
*               - TRUE: Communication is allowed.
*               - FALSE: Communication is not allowed.
*   @ServiceID  0x35
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(void,COMM_CODE) ComM_CommunicationAllowed(NetworkHandleType Channel, boolean Allowed)
{
    /* Local Variables */
    uint8 ErrorId = COMM_E_NO_ERROR;

    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (COMM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
#endif
    else
    {
        /* Enter Critical section */
        ComM_EnterCriticalSection();
        /* Update Channel Allowed Status */
        ComM_CommunicationAllowedStatus[Channel] = Allowed;
        /* Exit Critical section */
        ComM_ExitCriticalSection();
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_COMMUNICATIONALLOWED, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This method called by <Bus>SM module to indicate the actual bus mode by the corresponding Bus State
*   Manager.ComM shall propagate the indicated state to the users with means of the RTE and BswM.
*   @param[in]  Channel The Network Channel for which indication request is called.
*   @param[in]  ComMode ComM mode requested by the user.
*               - COMM_NO_COMMUNICATION : channel shall stop both transmission and reception capability
*               - COMM_SILENT_COMMUNICATION : channel shall have only reception capability and stop both transmission
*               - COMM_FULL_COMMUNICATION : channel shall have both transmission and reception capability
*   @ServiceID  0x33
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(void,COMM_CODE) ComM_BusSM_ModeIndication(NetworkHandleType Channel, ComM_ModeType* ComMode)
{
    /* Local Variables */
    uint8 ErrorId = COMM_E_NO_ERROR;
#if ((COMM_RESET_AFTER_FORCING_NO_COMM == STD_ON) && (STD_ON == COMM_MODE_LIMITATION_ENABLED))
    NetworkHandleType ChannelId = 0U;
    boolean IsChannelsInNoCom = TRUE;
    boolean IsChannelNoComLimitationEnabled = FALSE;
#endif
    if (COMM_INIT != ComM_InitStatus)
    {
        ErrorId = COMM_E_NOT_INITED;
    }
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    else if (COMM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
    else if (NULL_PTR == ComMode)
    {
        ErrorId = COMM_E_PARAM_POINTER;
    }
    else if (COMM_FULL_COMMUNICATION < *ComMode)
    {
        ErrorId = COMM_E_WRONG_PARAMETERS;
    }
#endif
    else
    {
        if (*ComMode != ComM_BusSmMode[Channel])
        {
            ComM_EnterCriticalSection();
            /* Update Channel Mode */
            ComM_BusSmMode[Channel] = *ComMode;
#if (STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT)
            /* Other user change notification */
            ComM_IsBusSmModeChanged[Channel] = TRUE;
#endif
            ComM_ExitCriticalSection();
            /* Indicate State change to BswM */
            BswM_ComM_CurrentMode(Channel, *ComMode );

            /* Notify Dcm about the new ComM mode change. */
#if (STD_ON == COMM_DCM_MODE_INDICATION_SUPPORT)
            switch (*ComMode)
            {
            case COMM_FULL_COMMUNICATION:
                Dcm_ComM_FullComModeEntered(Channel);
                break;

            case COMM_SILENT_COMMUNICATION:
                Dcm_ComM_SilentComModeEntered(Channel);
                break;

            default:
                /* COMM_NO_COMMUNICATION */
                Dcm_ComM_NoComModeEntered(Channel);
                break;
            }
#endif

            /* SWS_ComM_00355 handle BswM_ComM_InitiateReset because of ComMResetAfterForcingNoComm is true */
#if ((COMM_RESET_AFTER_FORCING_NO_COMM == STD_ON) && (STD_ON == COMM_MODE_LIMITATION_ENABLED))
            if (COMM_NO_COMMUNICATION == ComM_BusSmMode[Channel])
            {
                for (ChannelId = 0U; ChannelId<COMM_NUM_OF_CHANNELS; ChannelId++)
                {
                    /* Check if all the channels are in NoCom */
                    if ((ComM_BusSmMode[Channel] != COMM_NO_COMMUNICATION) &&
                            (ComM_CurrentState[Channel] != COMM_NO_COM_NO_PENDING_REQUEST))
                    {
                        IsChannelsInNoCom = FALSE;
                        /* exit check for other channels as one of the channels is not in sleep */
                        break;
                    }

                    /* if atleast one channel is in set to NO COM because of channel limitation call
                       BswM_ComM_InitiateReset */
                    if (FALSE != ComM_IsChannelNoComLimitationEnabled(ChannelId))
                    {
                        IsChannelNoComLimitationEnabled = TRUE;
                    }
                }

                if((FALSE != IsChannelsInNoCom ) && (FALSE != IsChannelNoComLimitationEnabled))
                {
                    BswM_ComM_InitiateReset();
                }
            }
#endif
        }
    }

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if(COMM_E_NO_ERROR != ErrorId)
    {
        ComM_DetReportError(COMM_SID_BUSSM_MODEINDICATION, ErrorId);
    }
#else
    COMM_IGNORE_UNUSED_PARAM(ErrorId);
#endif
}

/********************************************************************************************************************
*  PRIVATE FUNCTION IMPLEMENTATION			                                                                        *
********************************************************************************************************************/
/********************************************************************************************************************
*   @brief      This method checks the Com Inhibition state and returns the ComMMode supported.
*   @param[in]  Channel  requested Channel Id.
*   @return     ComM_StateType Returns the ComM Mode
*               - COMM_NO_COMMUNICATION
*               - COMM_FULL_COMMUNICATION
*
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_ModeType,COMM_CODE) ComM_GetUserModeWithInhibitionCheck(NetworkHandleType Channel)
{
    ComM_ModeType UserMode = COMM_NO_COMMUNICATION;

    if (COMM_NUM_OF_CHANNELS > Channel)
    {
#if ((STD_ON == COMM_MODE_LIMITATION_ENABLED) || (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED))
        if (TRUE != ComM_IsChannelInhibitionEnabled(Channel))
#endif
        {
            /* If limitation not enabled get the current Mode else return No Com */
            UserMode = ComM_ChannelUserRequestedMode[Channel];
        }
    }

    return UserMode;
}

/********************************************************************************************************************
*   @brief      This method checks and process the request in the No com No Pending request state.
*   @param[in]  Channel  requested Channel Id.
*   @return     ComM_StateType Returns the new ComM state to be transitioned.
*               - COMM_NO_COM_NO_PENDING_REQUEST : No new requested
*               - COMM_FULL_COM_NETWORK_REQUESTED - Full Com requested ,user or DCM request ,Bus NM request,
*                 ECU Wake-up Indication.
*
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_StateType,COMM_CODE) ComM_NoComNoPendingRequestProcessor
(
    NetworkHandleType Channel,
    ComM_StateType highestRequestedMode
)
{
    ComM_StateType NewComMState = COMM_NO_COM_NO_PENDING_REQUEST;
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;

    if (COMM_NUM_OF_CHANNELS > Channel)
    {
        ChannelConfigPtr = &ComM_ChannelConfig[Channel];

        /*  SWS_ComM_00875  , SWS_ComM_00876 */
        if ((COMM_FULL_COMMUNICATION == ComM_GetUserModeWithInhibitionCheck(Channel)) ||
                (FALSE != ComM_DcmFullComRequest[Channel]))
        {
            NewComMState = COMM_NO_COM_REQUEST_PENDING;
        }

        if ((COMM_NO_COM_REQUEST_PENDING != NewComMState) &&
                (FALSE != ComM_EcuMWakeupIndicationStatus[Channel]))
        {
            /* SWS_ComM_00893 */
            NewComMState = COMM_NO_COM_REQUEST_PENDING;
        }

        if ((COMM_NO_COM_REQUEST_PENDING != NewComMState) &&
                ((COMM_NM_VARIANT_TYPE_FULL == ChannelConfigPtr->NmVariantType) ||
                 (COMM_NM_VARIANT_TYPE_PASSIVE == ChannelConfigPtr->NmVariantType)))
        {
            /* SWS_ComM_00894 */
            if (COMM_FULL_COM_NETWORK_REQUESTED == ComM_BusNmRequestedState[Channel])
            {
                NewComMState = COMM_NO_COM_REQUEST_PENDING;
            }
        }
    }

    if (COMM_NO_COM_REQUEST_PENDING == NewComMState)
    {
        /* SWS_ComM_00895 */
        if (FALSE != ComM_CommunicationAllowedStatus[Channel])
        {
            NewComMState = COMM_FULL_COM_NETWORK_REQUESTED;
        }
        else
        {
            NewComMState = COMM_NO_COM_NO_PENDING_REQUEST;
        }
    }

    return NewComMState;
}

/********************************************************************************************************************
*   @brief      This method checks and process the request in the Full comm network request state.
*   @param[in]  Channel  requested Channel Id.
*   @return     ComM_StateType Returns the new ComM state to be transitioned.
*               - COMM_FULL_COM_NETWORK_REQUESTED : No new requested.
*               - COMM_FULL_COM_READY_SLEEP - User or DCM request released.
*               - COMM_NO_COM_NO_PENDING_REQUEST - Bus sleep request
*               - COMM_SILENT_COM - Bus Network Prepare sleep request .
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_StateType,COMM_CODE) ComM_FullComNetworkRequestProcessor
(
    NetworkHandleType Channel,
    ComM_StateType highestRequestedMode
)
{
    ComM_StateType NewComMState = COMM_FULL_COM_NETWORK_REQUESTED;
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;

    if (COMM_NUM_OF_CHANNELS > Channel)
    {
        ChannelConfigPtr = &ComM_ChannelConfig[Channel];

        if ((COMM_NM_VARIANT_TYPE_FULL == ChannelConfigPtr->NmVariantType) ||
                (COMM_NM_VARIANT_TYPE_PASSIVE == ChannelConfigPtr->NmVariantType))
        {
            /* SWS_ComM_00888, SWS_ComM_00890*/
            if ((COMM_NO_COMMUNICATION == ComM_GetUserModeWithInhibitionCheck(Channel)) &&
                    (TRUE != ComM_DcmFullComRequest[Channel]))
            {
                NewComMState = COMM_FULL_COM_READY_SLEEP;
            }
            else
            {
                if (COMM_NO_COM_NO_PENDING_REQUEST == ComM_BusNmRequestedState[Channel])
                {
                    /* SWS_ComM_00637 */
                    NewComMState = COMM_NO_COM_NO_PENDING_REQUEST;
                }
                else if (COMM_SILENT_COM == ComM_BusNmRequestedState[Channel])
                {
                    /* SWS_ComM_00826 */
                    NewComMState = COMM_SILENT_COM;
                }
                else
                {
                    /* Do Nothing */
                }
            }
        }
        else
        {
            if (COMM_TIMER_EXPIRED != ComM_Timer[Channel])
            {
                ComM_Timer[Channel]--;
            }
            /* SWS_ComM_00889 */
            if((COMM_TIMER_EXPIRED == ComM_Timer[Channel]) &&
                    (COMM_NO_COMMUNICATION == ComM_GetUserModeWithInhibitionCheck(Channel))  &&
                    (TRUE != ComM_DcmFullComRequest[Channel]))
            {
                NewComMState = COMM_FULL_COM_READY_SLEEP;
            }
        }

        if ((COMM_FULL_COM_NETWORK_REQUESTED == NewComMState) &&
                (COMM_FULL_COMMUNICATION != ComM_BusSmMode[Channel]))
        {
            ComM_FullComNetworkRequestOnEntry(Channel, NewComMState);
        }
    }

    return NewComMState;
}

/********************************************************************************************************************
*   @brief      This method checks and process the request in the Full comm ready sleep state.
*   @param[in]  Channel  requested Channel Id.
*   @return     ComM_StateType Returns the new ComM state to be transitioned.
*               - COMM_FULL_COM_READY_SLEEP : No new requested
*               - COMM_FULL_COM_NETWORK_REQUESTED - Full Com requested ,user or DCM request
*               - COMM_NO_COM_NO_PENDING_REQUEST - Bus sleep request,Bus type internal or Light timer expired.
*               - COMM_SILENT_COM - Bus Network Prepare sleep request .
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_StateType,COMM_CODE) ComM_FullComReadySleepProcessor
(
    NetworkHandleType Channel,
    ComM_StateType highestRequestedMode
)
{
    ComM_StateType NewComMState = COMM_FULL_COM_READY_SLEEP;
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;

    if (COMM_NUM_OF_CHANNELS > Channel)
    {
        ChannelConfigPtr = &ComM_ChannelConfig[Channel];
        /* SWS_ComM_00671 , SWS_ComM_00892*/
        if ((COMM_FULL_COMMUNICATION == ComM_GetUserModeWithInhibitionCheck(Channel)) ||
                (FALSE != ComM_DcmFullComRequest[Channel]))
        {
            NewComMState = COMM_FULL_COM_NETWORK_REQUESTED;
            ComM_Timer[Channel] = 0U;
        }

        if (COMM_FULL_COM_READY_SLEEP == NewComMState)
        {
            if ((COMM_BUS_TYPE_INTERNAL != ChannelConfigPtr->BusType))
            {
                if ((COMM_NM_VARIANT_TYPE_FULL == ChannelConfigPtr->NmVariantType) ||
                        (COMM_NM_VARIANT_TYPE_PASSIVE == ChannelConfigPtr->NmVariantType))
                {
                    if ((COMM_NO_COM_NO_PENDING_REQUEST == ComM_BusNmRequestedState[Channel])/* ||
                        (COMM_MAX_NUMBER_OF_STATES == ComM_BusNmRequestedState[Channel])*/)
                    {
                        /* SWS_ComM_00637 */
                        NewComMState = COMM_NO_COM_NO_PENDING_REQUEST;
                    }
                    else if (COMM_SILENT_COM == ComM_BusNmRequestedState[Channel])
                    {
                        /* SWS_ComM_00826 */
                        NewComMState = COMM_SILENT_COM;
                    }
                    else
                    {
                        /* Do Nothing */
                    }
                }
                else
                {
                    if(COMM_NM_VARIANT_TYPE_LIGHT == ChannelConfigPtr->NmVariantType)
                    {
                        /* SWS_ComM_00610 */
                        if (COMM_TIMER_EXPIRED != ComM_Timer[Channel])
                        {
                            ComM_Timer[Channel]--;
                            if (0U == ComM_Timer[Channel])
                            {
                                NewComMState = COMM_NO_COM_NO_PENDING_REQUEST;
                            }
                        }
                        else
                        {
                            NewComMState = COMM_NO_COM_NO_PENDING_REQUEST;
                        }
                    }
                    else
                    {
                        NewComMState = COMM_NO_COM_NO_PENDING_REQUEST;
                    }
                }
            }
            else
            {
                NewComMState = COMM_NO_COM_NO_PENDING_REQUEST;
            }
        }
    }

    return NewComMState;
}

/********************************************************************************************************************
*   @brief      This method checks and process the request in the silent communication state.
*   @param[in]  Channel  requested Channel Id.
*   @return     ComM_StateType Returns the new ComM state to be transitioned.
*               - COMM_SILENT_COM : No new requested
*               - COMM_FULL_COM_NETWORK_REQUESTED - Full Com requested ,user or DCM request
*               - COMM_NO_COM_NO_PENDING_REQUEST - Bus sleep request
*               - COMM_FULL_COM_READY_SLEEP - Bus Network request .
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_StateType,COMM_CODE) ComM_SilentCommunicationProcessor
(
    NetworkHandleType Channel,
    ComM_StateType highestRequestedMode
)
{

    ComM_StateType NewComMState = COMM_SILENT_COM;
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;

    if (COMM_NUM_OF_CHANNELS > Channel)
    {
        ChannelConfigPtr = &ComM_ChannelConfig[Channel];
        /* SWS_ComM_00877 ,SWS_ComM_00878 */
        if ((COMM_FULL_COMMUNICATION == ComM_GetUserModeWithInhibitionCheck(Channel)) ||
                (FALSE != ComM_DcmFullComRequest[Channel]))
        {
            NewComMState = COMM_FULL_COM_NETWORK_REQUESTED;
            ComM_Timer[Channel] =0U;
        }

        if (COMM_SILENT_COM == NewComMState)
        {
            if ((COMM_NM_VARIANT_TYPE_FULL == ChannelConfigPtr->NmVariantType) ||
                    (COMM_NM_VARIANT_TYPE_PASSIVE == ChannelConfigPtr->NmVariantType))
            {
                /* SWS_ComM_00295 */
                if ((COMM_NO_COM_NO_PENDING_REQUEST == ComM_BusNmRequestedState[Channel]) ||
                        (COMM_MAX_NUMBER_OF_STATES == ComM_BusNmRequestedState[Channel]))
                {
                    NewComMState = COMM_NO_COM_NO_PENDING_REQUEST;
                }
                else if(COMM_FULL_COM_READY_SLEEP == ComM_BusNmRequestedState[Channel])
                {
                    /* SWS_ComM_00296 */
                    NewComMState = COMM_FULL_COM_READY_SLEEP;
                }
                else if(COMM_FULL_COM_NETWORK_REQUESTED == ComM_BusNmRequestedState[Channel])
                {
                    NewComMState = COMM_FULL_COM_NETWORK_REQUESTED;
                }
                else
                {
                    /* Do Nothing*/
                }
            }
        }
    }
    return NewComMState;
}

/********************************************************************************************************************
*   @brief      This method implements the on entry action for the No Com No request pending state.
*   @param[in]  Channel  requested Channel in which the transition to be occurred.
*   @param[in]  CurrentComMState  Current ComM state
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_NoComNoPendingRequestOnEntry
(
    NetworkHandleType Channel,
    ComM_StateType CurrentComMState
)
{
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;
    P2CONST(ComM_BusSMComMModeFnConfigType,AUTOMATIC,COMM_APPL_CONST) BusSMComMModeFnConfigPtr;

    if (COMM_NUM_OF_CHANNELS > Channel)
    {
        ChannelConfigPtr = &ComM_ChannelConfig[Channel];
        if (COMM_NUM_OF_SUPPORTED_BUS > ChannelConfigPtr->BusSMFnConfigId)
        {
            BusSMComMModeFnConfigPtr = &ComM_BusSMComMModeFnConfig[ChannelConfigPtr->BusSMFnConfigId];
            if (NULL_PTR != BusSMComMModeFnConfigPtr->CanSM_RequestComModeFn)
            {
                /* SWS_ComM_00073 */
                (void)BusSMComMModeFnConfigPtr->CanSM_RequestComModeFn(Channel,COMM_NO_COMMUNICATION);
            }
#if (STD_ON == COMM_NM_MODULE_USED)
            if (COMM_NM_VARIANT_TYPE_FULL == ChannelConfigPtr->NmVariantType)
            {
                /* SWS_ComM_00288 */
                /* (void)Nm_NetworkRelease(Channel); */
            }
#endif
            ComM_BusNmRequestedState[Channel] = COMM_MAX_NUMBER_OF_STATES;
#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)
            if (TRUE == ComM_IsChannelNoComLimitationEnabled(TRUE))
            {
                ComM_ChannelUserRequestedMode[Channel] = COMM_NO_COMMUNICATION;
            }
#endif
        }

    }
    COMM_IGNORE_UNUSED_PARAM(CurrentComMState);
}

/********************************************************************************************************************
*   @brief      This method implements the on entry action for the silent communication state.
*   @param[in]  Channel  requested Channel in which the transition to be occurred.
*   @param[in]  CurrentComMState  Current ComM state
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE)ComM_SilentCommunicationOnEntry
(
    NetworkHandleType Channel,
    ComM_StateType CurrentComMState
)
{
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;
    P2CONST(ComM_BusSMComMModeFnConfigType,AUTOMATIC,COMM_APPL_CONST) BusSMComMModeFnConfigPtr;

    if (COMM_NUM_OF_CHANNELS > Channel)
    {
        ChannelConfigPtr = &ComM_ChannelConfig[Channel];
        if (COMM_NUM_OF_SUPPORTED_BUS > ChannelConfigPtr->BusSMFnConfigId)
        {
            BusSMComMModeFnConfigPtr = &ComM_BusSMComMModeFnConfig[ChannelConfigPtr->BusSMFnConfigId];
            if (NULL_PTR != BusSMComMModeFnConfigPtr->CanSM_RequestComModeFn)
            {
                /* SWS_ComM_00071 */
                (void)BusSMComMModeFnConfigPtr->CanSM_RequestComModeFn(Channel,COMM_SILENT_COMMUNICATION);
            }
        }
    }

    COMM_IGNORE_UNUSED_PARAM(CurrentComMState);
}

/********************************************************************************************************************
*   @brief      This method implements the on entry action for the Full COM Network Request state.
*   @param[in]  Channel  requested Channel in which the transition to be occurred.
*   @param[in]  CurrentComMState  Current ComM state
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_FullComNetworkRequestOnEntry
(
    NetworkHandleType Channel,
    ComM_StateType CurrentComMState
)
{
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;
    P2CONST(ComM_BusSMComMModeFnConfigType,AUTOMATIC,COMM_APPL_CONST) BusSMComMModeFnConfigPtr;

    if (COMM_NUM_OF_CHANNELS > Channel)
    {
        ChannelConfigPtr = &ComM_ChannelConfig[Channel];
        if (COMM_NUM_OF_SUPPORTED_BUS > ChannelConfigPtr->BusSMFnConfigId)
        {
            BusSMComMModeFnConfigPtr = &ComM_BusSMComMModeFnConfig[ChannelConfigPtr->BusSMFnConfigId];
            if (NULL_PTR != BusSMComMModeFnConfigPtr->CanSM_RequestComModeFn)
            {
                /* SWS_ComM_00069 */
                (void)BusSMComMModeFnConfigPtr->CanSM_RequestComModeFn(Channel,COMM_FULL_COMMUNICATION);
            }

            if ((COMM_NM_VARIANT_TYPE_LIGHT == ChannelConfigPtr->NmVariantType) ||
                    (COMM_NM_VARIANT_TYPE_NONE == ChannelConfigPtr->NmVariantType))
            {
                /* SWS_ComM_00886 */
                ComM_Timer[Channel] = ChannelConfigPtr->NmFullComTimeout;
            }
            else
            {
                /* Check for user request or Dcm request */
#if (STD_ON == COMM_NM_MODULE_USED)
                if ((COMM_FULL_COMMUNICATION == ComM_ChannelUserRequestedMode[Channel]) ||
                        (FALSE != ComM_DcmFullComRequest[Channel]))
                {
                    if (COMM_NM_VARIANT_TYPE_FULL == ChannelConfigPtr->NmVariantType)
                    {
                        /* SWS_ComM_00869 , SWS_ComM_00870 */
                        (void)Nm_NetworkRequest(Channel);
                    }
                    else
                    {
                        (void)Nm_PassiveStartUp(Channel);
                    }
                }
                else
                {
                    if ((FALSE != ComM_EcuMWakeupIndicationStatus[Channel]) ||
                            (COMM_FULL_COMMUNICATION == ComM_BusNmRequestedState[Channel]))
                    {
                        /* SWS_ComM_00665 ,SWS_ComM_00902 ,SWS_ComM_00903 */
                        (void)Nm_PassiveStartUp(Channel);
                    }
                }
#endif
            }
            ComM_EcuMWakeupIndicationStatus[Channel] = FALSE;
        }
    }
    COMM_IGNORE_UNUSED_PARAM(CurrentComMState);
}

/********************************************************************************************************************
*   @brief      This method implements the on entry action for the Full COM Ready sleep state.
*   @param[in]  Channel  requested Channel in which the transition to be occurred.
*   @param[in]  CurrentComMState  Current ComM state
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_FullComReadySleepOnEntry(NetworkHandleType Channel,ComM_StateType CurrentComMState)
{
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;
    P2CONST(ComM_BusSMComMModeFnConfigType,AUTOMATIC,COMM_APPL_CONST) BusSMComMModeFnConfigPtr;

    if (COMM_NUM_OF_CHANNELS > Channel)
    {
        ChannelConfigPtr = &ComM_ChannelConfig[Channel];
        if (COMM_NUM_OF_SUPPORTED_BUS > ChannelConfigPtr->BusSMFnConfigId)
        {
            if ((COMM_SILENT_COM == CurrentComMState) ||
                    (COMM_NO_COM_NO_PENDING_REQUEST == CurrentComMState))
            {
                BusSMComMModeFnConfigPtr = &ComM_BusSMComMModeFnConfig[ChannelConfigPtr->BusSMFnConfigId];
                if (NULL_PTR != BusSMComMModeFnConfigPtr->CanSM_RequestComModeFn)
                {
                    /* SWS_ComM_00069 */
                    (void)BusSMComMModeFnConfigPtr->CanSM_RequestComModeFn(Channel,COMM_FULL_COMMUNICATION);
                }
#if (STD_ON == COMM_NM_MODULE_USED)
                if (COMM_FULL_COMMUNICATION == ComM_BusNmRequestedState[Channel])
                {
                    /* SWS_ComM_00902 ,SWS_ComM_00903 */
                    (void)Nm_PassiveStartUp(Channel);
                }
#endif
            }
            else
            {
                if (COMM_NM_VARIANT_TYPE_LIGHT == ChannelConfigPtr->NmVariantType)
                {
                    /* SWS_ComM_00891 */
                    ComM_Timer[Channel]= ChannelConfigPtr->NmLightTimeout;
                }
#if (STD_ON == COMM_NM_MODULE_USED)
                else if (COMM_NM_VARIANT_TYPE_FULL == ChannelConfigPtr->NmVariantType)
                {
                    /* SWS_ComM_00133 */
                    (void)Nm_NetworkRelease(Channel);
                }
#endif
                else
                {
                    /*  Hanlded in processor function */
                }
            }
        }
    }
}

#if(STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT )
/********************************************************************************************************************
*   @brief      This method is used to validate the BusSM mode change and notify to the user about the changes.
*   @param[in] Channel Network channel for which BusSM mode change processing should be done.
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_BusSMSateChangeNotificationToUser(NetworkHandleType Channel)
{
    uint8 BitOffset = 0U;
    uint8 Mask = 0U;
    ComM_UserHandleType ByteOffset = 0U;
    ComM_UserHandleType UserId = 0U;
    NetworkHandleType ChannelId = 0U;
    ComM_ModeType NewMode = 0U;
    P2CONST(ComM_UserConfigType,AUTOMATIC,COMM_APPL_CONST) UserConfigPtr;
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST)ChannelConfigPtr;

    if (COMM_NUM_OF_CHANNELS > Channel)
    {
        NewMode = ComM_BusSmMode[Channel];
        for(UserId = 0U; UserId < COMM_NUM_OF_USERS ; UserId++)
        {
            UserConfigPtr = &ComM_UserConfig[UserId];
            /* Get Channel mask */
            ByteOffset = Channel/8U;
            BitOffset = Channel%8U;
            if (UserConfigPtr->UserNotificationFn != NULL_PTR)
            {
                Mask = UserConfigPtr->ChannelsToUserMap[ByteOffset];
                if (0U != ((Mask) & ((uint8)(1U << BitOffset))))
                {
                    /* if user is supported for this channel , get the minimum state from other channels
                       supported by the user */
                    ByteOffset = UserId/8U;
                    BitOffset  = UserId%8U;
                    for (ChannelId =0U ; ChannelId < COMM_NUM_OF_CHANNELS; ChannelId++)
                    {
                        ChannelConfigPtr = &ComM_ChannelConfig[ChannelId];
                        Mask = ChannelConfigPtr->UsersToChannelMap[ByteOffset];
                        if (0U != ((Mask) & ((uint8)(1U << BitOffset))))
                        {
                            if(ComM_BusSmMode[ChannelId] < NewMode)
                            {
                                /* get if any other channel has less state */
                                NewMode = ComM_BusSmMode[ChannelId];
                            }
                        }
                    }
                    /* Check if the state is changed  */
                    if((NewMode != ComM_OldBusSmMode[UserId]) && (COMM_FULL_COMMUNICATION >= NewMode))
                    {
                        ComM_OldBusSmMode[UserId] = NewMode;
                        (void)UserConfigPtr->UserNotificationFn(ComM_RteComMTypeMap[NewMode]);
                    }
                }
            } /* else User notification not enabled */
        }
    }
}
#endif

#if ((STD_ON == COMM_MODE_LIMITATION_ENABLED) || (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED))
/********************************************************************************************************************
*   @brief      This method is used to check if the Inhibition is enabled for the channel
*   @param[in]  Channel Network channel for which the status is checked
*   @return     boolean returns the status of the request
*               - TRUE  : Inhibition status is enabled.
*               - FALSE : Inhibition status is not enabled.
********************************************************************************************************************/
COMM_LOCAL FUNC(boolean,COMM_CODE) ComM_IsChannelInhibitionEnabled(NetworkHandleType Channel)
{
    boolean ReturnValue = FALSE;
    if (COMM_NUM_OF_CHANNELS > Channel)
    {
        /* check for the wakeup inhibition and limit no com inhibition */
        if(
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
            (FALSE != ComM_IsChannelNoComLimitationEnabled(Channel))
#if (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
            ||
#endif
#endif
#if (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
            (FALSE != ComM_IsChannelWakeupInhibitionEnabled(Channel))
#endif
        )
        {
            ReturnValue = TRUE;
        }
    }
    return ReturnValue;
}
#endif

#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)
/********************************************************************************************************************
*   @brief      This method is used to check if the Limit to No Com is enabled or not
*   @param[in]  Channel Network channel for which the status is checked
*   @return     boolean returns the status of the request
*               - TRUE  :Limit to No Com is enabled.
*               - FALSE : Limit to No Com is not enabled.
********************************************************************************************************************/
COMM_LOCAL FUNC(boolean,COMM_CODE) ComM_IsChannelNoComLimitationEnabled(NetworkHandleType Channel)
{
    boolean ReturnValue = FALSE;
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) ChannelConfigPtr;
    if (COMM_NUM_OF_CHANNELS > Channel)
    {
        ChannelConfigPtr = &ComM_ChannelConfig[Channel];
        if (COMM_NM_VARIANT_TYPE_PASSIVE == ChannelConfigPtr->NmVariantType)
        {
            /* Return true if the nm type is passive */
            ReturnValue = TRUE;
        }
        else
        {
            /* Return True if the limit no com set in EcuInhibitionStatus and channel status */
            if ((TRUE == COMM_IS_LIMIT_TO_NO_COM_INHIBITION_SET(ComM_Inhibition.EcuInhibitionStatus)) &&
                    (TRUE == COMM_IS_LIMIT_TO_NO_COM_INHIBITION_SET(ComM_Inhibition.ChannelInhibitionStatus[Channel])))
            {
                ReturnValue = TRUE;
            }
        }

    }
    return ReturnValue;
}
#endif

#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
/********************************************************************************************************************
*   @brief      This method is used to check if the wake-up Inhibition is enabled or not
*   @param[in]  Channel Network channel for which the status is checked
*   @return     boolean returns the status of the request
*               - TRUE  : wake-up Inhibition  is enabled.
*               - FALSE : wake-up Inhibition  is not enabled.
********************************************************************************************************************/
COMM_LOCAL FUNC(boolean,COMM_CODE) ComM_IsChannelWakeupInhibitionEnabled(NetworkHandleType Channel)
{
    boolean ReturnValue = FALSE;

    if (COMM_NUM_OF_CHANNELS > Channel)
    {
        /* Return True if the wake-up inhibition set in EcuInhibitionStatus and channel status */
        if ((TRUE == COMM_IS_WAKEUP_INHIBITION_SET(ComM_Inhibition.EcuInhibitionStatus)) &&
                (TRUE == COMM_IS_WAKEUP_INHIBITION_SET(ComM_Inhibition.ChannelInhibitionStatus[Channel])))
        {
            if ((COMM_FULL_COM_NETWORK_REQUESTED != ComM_CurrentState[Channel]) &&
                    (COMM_FULL_COM_READY_SLEEP != ComM_CurrentState[Channel]))
            {
                ReturnValue = TRUE;
            }
        }
    }
    return ReturnValue;
}
#endif

/********************************************************************************************************************
*   @brief      This method is used to get whether any user request COMM_FULL_COMMUNICATION.
*   @param[in]  Channel Network channel for which the status is checked
*   @return     boolean returns the status of the request
*               - TRUE  : COMM_FULL_COMMUNICATION requested by an user.
*               - FALSE : COMM_FULL_COMMUNICATION requested by none of the user.
********************************************************************************************************************/
COMM_LOCAL FUNC(boolean,COMM_CODE) ComM_IsFullComRequestByUser(NetworkHandleType Channel)
{
    uint8 Mask;
    uint8 BitOffset;
    ComM_UserHandleType UserId = 0U;
    boolean FullComRequestStatus = FALSE;
    ComM_UserHandleType ByteOffset = 0U;
    P2CONST(ComM_UserConfigType,AUTOMATIC,COMM_APPL_CONST) UserConfigPtr;

    for(UserId = 0U; ((UserId < COMM_NUM_OF_USERS) && (Channel < COMM_NUM_OF_CHANNELS)) ; UserId++)
    {
        UserConfigPtr = &ComM_UserConfig[UserId];
        /* Get Channel mask */
        ByteOffset = Channel/8U;
        BitOffset = Channel%8U;
        Mask = UserConfigPtr->ChannelsToUserMap[ByteOffset];

        if (0U != ((Mask) & ((uint8)(1U << BitOffset))))
        {
            /* if user is supported for this channel , get the minimum state from other channels
            supported by the user */
            if (COMM_FULL_COMMUNICATION == ComM_UserRequestedMode[UserId])
            {
                FullComRequestStatus = TRUE;
                break;
            }
        }
    }

    return FullComRequestStatus;
}

/********************************************************************************************************************
*   @brief      This method is used to get the highest requested ComM State for the Channel
*   @param[in]  Channel ComM channel id to get the highest mode .
*   @return     ComM_StateType returns the highest ComM State
*               - TRUE  : wake-up Inhibition  is enabled.
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_StateType,COMM_CODE) ComM_GetHighestRequestMode(NetworkHandleType Channel)
{
	ComM_StateType HighestRequestMode = COMM_NO_COM_NO_PENDING_REQUEST;
    #if (COMM_PNC_SUPPORT == STD_ON)
	ComM_PncModeType HighestPncRequestMode,TempPncRequestedMode;
	P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) pChannelConfig;
	ComM_PncIdType	PncId;
    #endif

#if ((STD_ON == COMM_MODE_LIMITATION_ENABLED) || (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED))
	if (TRUE != ComM_IsChannelInhibitionEnabled(Channel))
#endif
	{
		if (FALSE != ComM_IsFullComRequestByUser(Channel))
		{
			HighestRequestMode = COMM_FULL_COM_NETWORK_REQUESTED;
		}
	}

	if (FALSE != ComM_DcmFullComRequest[Channel])
	{
		HighestRequestMode = COMM_FULL_COM_NETWORK_REQUESTED;
	}

#if (COMM_PNC_SUPPORT == STD_ON)
	if (COMM_NO_COM_NO_PENDING_REQUEST == HighestRequestMode)
	{
		/* ComM_PncGetGwChannelRequest */
		HighestPncRequestMode = COMM_PNC_NO_COMMUNICATION;
		pChannelConfig = &ComM_ChannelConfig[Channel];
		for (PncId = pChannelConfig->PncStartId;
		((PncId<=pChannelConfig->PncEndId) && (COMM_NUM_OF_PNC > PncId)
		&& (COMM_PNC_REQUESTED != HighestPncRequestMode));PncId++)
		{
			/* ComM_CalculateHighestPNComMode pncIndex		 */
			TempPncRequestedMode = ComM_PncGetHighestRequestedMode(PncId);
			if (TempPncRequestedMode >= COMM_PNC_REQUESTED)
			{
				HighestPncRequestMode =TempPncRequestedMode;
			}
		}

		/* ComM_PncGetGwChannelState */
		if (HighestPncRequestMode == COMM_PNC_REQUESTED)
		{
			HighestRequestMode = COMM_FULL_COM_NETWORK_REQUESTED;
		} /* COMM_PNC_PASSIVE_GW_SUPPORT */
		else
		{
			HighestRequestMode = COMM_NO_COM_NO_PENDING_REQUEST;
		}
	}
#endif
	if ((HighestRequestMode == COMM_NO_COM_NO_PENDING_REQUEST) ||
		(COMM_FULL_COM_NETWORK_REQUESTED == ComM_BusComModeReq[Channel]))
	{
		HighestRequestMode = ComM_BusComModeReq[Channel];
	}

	return HighestRequestMode;
}

#if (STD_ON == COMM_PNC_SUPPORT)
/********************************************************************************************************************
*   @brief      This method is used to get the highest requested ComM PNC mode for the PncId
*   @param[in]  PncId PNC index to get the highest PNC mode .
*   @return     ComM_PncModeType returns the highest ComM State
*               - TRUE  : wake-up Inhibition  is enabled.
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_PncModeType,COMM_CODE) ComM_PncGetHighestRequestedMode(ComM_PncIdType PncId)
{
	ComM_PncToUserMapIdType PncToUserId;
	ComM_PncToChannelMapIdType PncToChannelId;
	ComM_PncModeType HighestPncRequest = COMM_PNC_NO_COMMUNICATION;
	P2CONST(ComM_PncConfigType,AUTOMATIC,COMM_APPL_CONST) pPncConfig;

	if (COMM_NUM_OF_PNC > PncId )
	{
		pPncConfig = &ComM_PncConfig[PncId];
		/* Iterate over the users configured for the PNC Id */
		for(PncToUserId = pPncConfig->PncUserStartId;
		((PncToUserId <= pPncConfig->PncUserEndId)&&(COMM_NUM_OF_PNC_TO_USER_MAP > PncToUserId));PncToUserId++)
		{
            if (COMM_NO_COMMUNICATION != ComM_PncUserRequestComMode[ComM_PncToUserMapConfig[PncToUserId]])
            {
                HighestPncRequest = COMM_PNC_REQUESTED;
                break;
            }
		}

		/* Check for channel Limitation */
		#if ((STD_ON == COMM_MODE_LIMITATION_ENABLED) || (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED))
		/* Iterate over the channel and check for the inhibition and limitation status */
		for(PncToChannelId = pPncConfig->PncChannelStartId;
			((PncToChannelId <= pPncConfig->PncChannelEndId)&&(COMM_NUM_OF_CHANNELS > PncToChannelId));
			PncToChannelId++)
		{
			if (COMM_NUM_OF_PNC_TO_CHANNEL_MAP>PncToChannelId)
			{
				if (FALSE != ComM_IsChannelInhibitionEnabled(ComM_PncToChannelMapConfig[PncToChannelId]))
				{
					HighestPncRequest = COMM_PNC_NO_COMMUNICATION;
					break;
				}
			}
		}
		#endif
		/* Requested mode via Eira */
		if (ComM_PncBusRequestedMode[PncId] > HighestPncRequest)
		{
			HighestPncRequest = ComM_PncBusRequestedMode[PncId];
		}
	}
	return HighestPncRequest;
}

/********************************************************************************************************************
*   @brief      This method is used to process the PNC state for the requested channel
*   @param[in]  Channel Channel id for the PNC state processing
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_PncStateProcessing(NetworkHandleType Channel)
{
	ComM_PncIdType	PncId;
	ComM_PncModeType CurrentComMPncMode;
	ComM_PncModeType HighestRequestedPncMode;
	ComM_PncModeType NewComMPncMode;
	P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST)pChannelConfig;
	P2CONST(ComM_PncStateFunctionListConfigType,AUTOMATIC,COMM_APPL_CONST) pPncStateFunctionListConfig;
#if (STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT)
	ComM_UserIdType UserId;
	ComM_ModeType lowestUserMode;
	P2CONST(ComM_UserConfigType,AUTOMATIC,COMM_APPL_CONST) pUserConfig;
#endif

	//ComM_PncModeArbitration
	if (COMM_NUM_OF_CHANNELS > Channel)
	{
		pChannelConfig = &ComM_ChannelConfig[Channel];
		/* Iterate over the PncId associated with the channel.
		Check for any request and then update the states accordingly. */
		for (PncId = pChannelConfig->PncStartId;
			((PncId<=pChannelConfig->PncEndId) && (COMM_NUM_OF_PNC > PncId));PncId++)
		{
			CurrentComMPncMode = ComM_PncCurrentMode[PncId];
			HighestRequestedPncMode = ComM_PncGetHighestRequestedMode(PncId);
			if (COMM_MAX_NUM_OF_PNC_STATES > CurrentComMPncMode)
			{
				pPncStateFunctionListConfig = &ComM_PncStateFunctionListConfig[CurrentComMPncMode];
				if (NULL_PTR != pPncStateFunctionListConfig->PncStateProcessorFn)
				{
					/* process the ComM state */
					ComM_EnterCriticalSection();
					NewComMPncMode = pPncStateFunctionListConfig->PncStateProcessorFn(PncId,Channel,HighestRequestedPncMode);
					if((NewComMPncMode != CurrentComMPncMode) && (COMM_MAX_NUMBER_OF_STATES > NewComMPncMode))
					{
						pPncStateFunctionListConfig = &ComM_PncStateFunctionListConfig[NewComMPncMode];
						if (NULL_PTR != pPncStateFunctionListConfig->PncStateOnEntryActionFn)
						{
							pPncStateFunctionListConfig->PncStateOnEntryActionFn(Channel,CurrentComMPncMode);
						}
						ComM_PncCurrentMode[PncId] = NewComMPncMode;
					}
					ComM_ExitCriticalSection();
				} /* (NULL_PTR != pPncStateFunctionListConfig->StateProcessorFn)*/
			} /* (COMM_MAX_NUMBER_OF_PNC_STATES > CurrentComMPncState ) */
        } /* for loop , iterate over the pnc of the channels */
    } /* (COMM_NUM_OF_CHANNELS > Channel) */

// COMM_USERMODENOTIFUNC
#if (STD_ON == COMM_USER_MODE_NOTIFICATION_SUPPORT)
    /* Notify user about the PNC mode change */
    if (FALSE != ComM_PncNotifyStateChange)
    {
    	ComM_PncNotifyStateChange = FALSE;
    	/* Iterate over the users and check if the user notification is configured , if configured then iterate
           over the PNC id connected to the user and check for the lowest communication mode . Notify the
           lowest communication mode to the user */
        for ( UserId = 0; UserId < COMM_NUM_OF_USERS ; UserId++)
        {
        	pUserConfig = &ComM_UserConfig[UserId];
            if (NULL_PTR != pUserConfig->UserNotificationFn)
            {

                lowestUserMode = COMM_FULL_COMMUNICATION;
                for (PncId = pUserConfig->PncStartId;
                	((PncId <= pUserConfig->PncEndId) &&(COMM_NUM_OF_PNC>PncId));PncId++)
                {
                    if (COMM_PNC_NO_COMMUNICATION == ComM_PncCurrentMode[PncId])
                    {
                       lowestUserMode = COMM_NO_COMMUNICATION;
                       break;
                    }
                }

                /* If old state is different than the current user state then notify the User */
                if ((lowestUserMode != ComM_PncUserOldState[UserId]) &&
					(COMM_FULL_COMMUNICATION >= lowestUserMode))
                {
                	if (RTE_E_OK == pUserConfig->UserNotificationFn(ComM_RteComMTypeMap[lowestUserMode]))
                	{
                		ComM_PncUserOldState[UserId] = lowestUserMode;
                	}
                	else
                	{
                		ComM_PncNotifyStateChange = TRUE;
                	}
                }
            } /* NULL_PTR != ComM_GetUserNotifFunc(UserId) */
        } /* for ( UserId = 0; UserId < COMM_NUM_OF_USERs ; UserId++) */
    } /* if (FALSE != ComM_PncNotifyStateChange) */
#endif
}

/*!*******************************************************************************************************************
*   @brief      This method is used to process the PNC state when the current state is COMM_PNC_NO_COMMUNICATION
*   @param[in]  PncId PNC Id of the requested channel.
*   @param[in]  ChannelId Channel Id of the request .
*   @param[in]  HighestRequestedPncMode Highest requested PNC mode for the channel
*   @return     ComM_PncModeType returns the next PNC mode
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_PncModeType,COMM_CODE) ComM_PncNoCommunicationProcessor 
( 
    PNCHandleType PncId, 
    ComM_ChannelIdType ChannelId, 
    ComM_PncModeType HighestRequestedPncMode
)
{
	ComM_PncModeType PncMode = COMM_PNC_NO_COMMUNICATION;

	/* SWS_ComM_00931 ,SWS_ComM_00964 */
	if (COMM_PNC_REQUESTED == HighestRequestedPncMode )
	{
		PncMode = COMM_PNC_REQUESTED;
	}
	else if (FALSE != ComM_EcuMPncWakeupIndicationStatus[PncId])
	{
		/* set the state to COMM_PNC_PREPARE_SLEEP  SWS_ComM_00932 */
		ComM_PncPrepareSleepTimer[PncId] = COMM_PNC_PREPARE_SLEEP_TIMER;
		PncMode = COMM_PNC_PREPARE_SLEEP;
	}
	else if (FALSE != ComM_PncEiraRequestStatus[PncId]) /* SWS_ComM_00933 */
	{
		PncMode = COMM_PNC_READY_SLEEP;
	}
	else
	{
		if (PncMode != HighestRequestedPncMode)
		{
			PncMode = HighestRequestedPncMode;
		}
	}
	return PncMode;
}

/*!******************************************************************************************************************
*   @brief      This method is used to process the PNC state when the current state is COMM_PNC_REQUESTED.
*   @param[in]  PncId PNC Id of the requested channel.
*   @param[in]  ChannelId Channel Id of the request .
*   @param[in]  HighestRequestedPncMode Highest requested PNC mode for the channel
*   @return     ComM_PncModeType returns the next PNC mode
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_PncModeType,COMM_CODE) ComM_PncRequestProcessor
(
    PNCHandleType PncId,
    ComM_ChannelIdType ChannelId,
    ComM_PncModeType HighestRequestedPncMode
)
{
	/* SWS_ComM_00959 , SWS_ComM_00966 , SWS_ComM_00938 , SWS_ComM_00991 */
	ComM_PncModeType PncMode = COMM_PNC_REQUESTED;
	if(HighestRequestedPncMode != COMM_PNC_REQUESTED )
	{
		PncMode = COMM_PNC_READY_SLEEP;
	}
	return PncMode;
}


/*!******************************************************************************************************************
*   @brief      This method is used to process the PNC state when the current state is COMM_PNC_READY_SLEEP.
*   @param[in]  PncId PNC Id of the requested channel.
*   @param[in]  ChannelId Channel Id of the request .
*   @param[in]  HighestRequestedPncMode Highest requested PNC mode for the channel
*   @return     ComM_PncModeType returns the next PNC mode
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_PncModeType,COMM_CODE) ComM_PncReadySleepProcessor
(
    PNCHandleType PncId,
    ComM_ChannelIdType ChannelId,
    ComM_PncModeType HighestRequestedPncMode
)
{
	/* SWS_ComM_00940 ,SWS_ComM_00165 */

	ComM_PncModeType PncMode = COMM_PNC_READY_SLEEP;
	if (COMM_PNC_REQUESTED == HighestRequestedPncMode)
	{
		PncMode = COMM_PNC_REQUESTED;
	}
	else if (FALSE == ComM_PncEiraRequestStatus[PncId])
	{
		ComM_PncPrepareSleepTimer[PncId] = COMM_PNC_PREPARE_SLEEP_TIMER;
		PncMode = COMM_PNC_PREPARE_SLEEP;
	}
	else
	{
		if (HighestRequestedPncMode!=COMM_PNC_READY_SLEEP)
		{
			PncMode = HighestRequestedPncMode;
		}
	}

	return PncMode;
}

/*!******************************************************************************************************************
*   @brief      This method is used to process the PNC state when the current state is COMM_PNC_PREPARE_SLEEP.
*   @param[in]  PncId PNC Id of the requested channel.
*   @param[in]  ChannelId Channel Id of the request .
*   @param[in]  HighestRequestedPncMode Highest requested PNC mode for the channel
*   @return     ComM_PncModeType returns the next PNC mode
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_PncModeType,COMM_CODE) ComM_PncPrepareSleepProcessor
(
    PNCHandleType PncId,
    ComM_ChannelIdType ChannelId,
    ComM_PncModeType HighestRequestedPncMode
)
{
	/* SWS_ComM_00947, SWS_ComM_00948, SWS_ComM_00950, SWS_ComM_00951*/
	ComM_PncModeType PncMode = COMM_PNC_READY_SLEEP;
    
	if (COMM_PNC_REQUESTED == HighestRequestedPncMode)
	{
		PncMode = COMM_PNC_REQUESTED;
	}
	else if (FALSE != ComM_PncEiraRequestStatus[PncId])
	{
		PncMode = COMM_PNC_READY_SLEEP;
	}
	else
	{
		if (ComM_PncPrepareSleepTimer[PncId] > 0U)
		{
			ComM_PncPrepareSleepTimer[PncId]--;
			if (ComM_PncPrepareSleepTimer[PncId] == 0U)
			{
				PncMode = COMM_PNC_NO_COMMUNICATION;
			}
		}
	}

	return PncMode;
}

/*!******************************************************************************************************************
*   @brief      This method is used to handle the actions when entering into the PNC state COMM_PNC_NO_COMMUNICATION.
*   @param[in]  PncId PNC Id of the requested channel.
*   @param[in]  CurrentPncMode Current mode of the PNC state.
*   @return     ComM_PncModeType returns the next PNC mode
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_PncNoCommunicationOnEntry (PNCHandleType PncId,ComM_PncModeType CurrentPncMode)
{
	/* SWS_ComM_00927 After switching on the power supply, main state COMM_PNC_NO_COMMUNICATION
		shall be entered from PowerOff */
	if (COMM_NUM_OF_PNC > PncId)
	{
		ComM_PncPrepareSleepTimer[PncId]=0U;
		/* Notify the BswM about the current ComM Pnc Com Mode */
		BswM_ComM_CurrentPNCMode(ComM_PncConfig[PncId].PncHandle,COMM_PNC_NO_COMMUNICATION);
		/* set this flag to notify to the user */
		ComM_PncNotifyStateChange = TRUE;
		COMM_IGNORE_UNUSED_PARAM(CurrentPncMode);
	}
}

/*!******************************************************************************************************************
*   @brief      This method is used to handle the actions when entering into the PNC state COMM_PNC_REQUESTED.
*   @param[in]  PncId PNC Id of the requested channel.
*   @param[in]  CurrentPncMode Current mode of the PNC state.
*   @return     ComM_PncModeType returns the next PNC mode
*   @TODO       PncNmRequest If this parameter equals true then every time a FULL Communication is requested due to a  
*               changein the PNC state machine to PNC_REQUESTED Nm shall be called using the API Nm_NetworkRequest
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_PncRequestOnEntry (PNCHandleType PncId,ComM_PncModeType CurrentPncMode)
{
	/* SWS_ComM_00930, SWS_ComM_00992, SWS_ComM_00993 */
	if (COMM_NUM_OF_PNC > PncId)
	{
		/* COMM_PNC_NO_COMMUNICATION -> COMM_PNC_REQUESTED */
		# if (COMM_EIRA_TX_TYPE_OF_PNC_SIGNAL == STD_ON)
		ComM_PncModeSendSignal(PncId, TRUE);
		# endif
		BswM_ComM_CurrentPNCMode(ComM_PncConfig[PncId].PncHandle, COMM_PNC_REQUESTED);
#if ( COMM_USER_MODE_NOTIFICATION_SUPPORT == STD_ON )
		if ( COMM_PNC_NO_COMMUNICATION == CurrentPncMode)
		{
			ComM_PncNotifyStateChange = TRUE;
		}
#else
		COMM_IGNORE_UNUSED_PARAM(CurrentPncMode);
#endif
	}
}

/*!******************************************************************************************************************
*   @brief      This method is used to handle the actions when entering into the PNC state COMM_PNC_READY_SLEEP.
*   @param[in]  PncId PNC Id of the requested channel.
*   @param[in]  CurrentPncMode Current mode of the PNC state.
*   @return     ComM_PncModeType returns the next PNC mode
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_PncReadySleepOnEntry (PNCHandleType PncId,ComM_PncModeType CurrentPncMode)
{
	/* SWS_ComM_00960,SWS_ComM_00961 */

	if (COMM_NUM_OF_PNC > PncId)
	{
		BswM_ComM_CurrentPNCMode(ComM_PncConfig[PncId].PncHandle, COMM_PNC_READY_SLEEP);
		if (COMM_PNC_REQUESTED == CurrentPncMode)
		{
#if (COMM_EIRA_TX_TYPE_OF_PNC_SIGNAL == STD_ON)
			ComM_PncModeSendSignal(PncId, FALSE);
#endif
		}
#if ( COMM_USER_MODE_NOTIFICATION_SUPPORT == STD_ON )
		else if (COMM_PNC_NO_COMMUNICATION == CurrentPncMode)
		{
		  	ComM_PncNotifyStateChange = TRUE;
		}
#endif
		else
		{
			/* Do Nothing */
		}
	}
}

/*!******************************************************************************************************************
*   @brief      This method is used to handle the actions when entering into the PNC state COMM_PNC_PREPARE_SLEEP.
*   @param[in]  PncId PNC Id of the requested channel.
*   @param[in]  CurrentPncMode Current mode of the PNC state.
*   @return     ComM_PncModeType returns the next PNC mode
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_PncPrepareSleepOnEntry (PNCHandleType PncId,ComM_PncModeType CurrentPncMode)
{
	/* SWS_ComM_00952 If the sub state COMM_PNC_PREPARE_SLEEP is entered, the timer
		ComMPncPrepareSleepTimer (see ECUC_ComM_00841) shall be started with the configured
		initial value */
	if (COMM_NUM_OF_PNC > PncId)
	{
		ComM_PncPrepareSleepTimer[PncId] = COMM_PNC_PREPARE_SLEEP_TIMER;
		BswM_ComM_CurrentPNCMode(ComM_PncConfig[PncId].PncHandle, COMM_PNC_PREPARE_SLEEP);
#if ( COMM_USER_MODE_NOTIFICATION_SUPPORT == STD_ON )
		if (COMM_PNC_NO_COMMUNICATION == CurrentPncMode)
		{
			ComM_PncNotifyStateChange = TRUE;
		}
#else
		COMM_IGNORE_UNUSED_PARAM(CurrentPncMode);
#endif

	}
}

#ifdef COMM_ENABLE_PNC_GET_USER_REQUEST_MODE
/*!******************************************************************************************************************
*   @brief      This method is used to get the user request ComM mode for the requested PNC Id.
*   @param[in]  PncId PNC Id of the requested channel.
*   @return     ComM_PncModeType returns the user requested ComM Mode
********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_ModeType,COMM_CODE) ComM_PncGetUserRequestMode(ComM_PncIdType PncId)
{
	ComM_UserIdType UserId;
	ComM_PncToUserMapIdType  PncToUserMapId;
	ComM_ModeType UserRequestMode=COMM_NO_COMMUNICATION;
	P2CONST(ComM_PncConfigType,AUTOMATIC,COMM_APPL_CONST) pPncConfig;

	if(COMM_NUM_OF_PNC > PncId)
	{
		pPncConfig = &ComM_PncConfig[PncId];
		/* Iterate over the users of the PNC and get the highest communication mode */
		for(PncToUserMapId = pPncConfig->PncUserStartId;((PncToUserMapId <= pPncConfig->PncUserEndId) && \
		(COMM_NUM_OF_PNC_TO_USER_MAP > PncToUserMapId)); PncToUserMapId++)
		{
			UserId = ComM_PncToUserMapConfig[PncToUserMapId];
			if (COMM_NUM_OF_USERS > UserId)
			{
				if (COMM_NO_COMMUNICATION != ComM_PncUserRequestComMode[UserId])
				{
					UserRequestMode = COMM_FULL_COMMUNICATION;
					break;
				}
			}
		}
	}

	return UserRequestMode;
}
#endif
/*!******************************************************************************************************************
*   @brief      This method is used to send the PNC byte to CanNM .
*   @param[in]  PncId PNC Id of the requested channel.
*   @param[in]  IsSet indicates whether the PNC bit is set or not.
*   @return     ComM_PncModeType returns the user requested ComM Mode
********************************************************************************************************************/
COMM_LOCAL FUNC(void,COMM_CODE) ComM_PncModeSendSignal(ComM_PncIdType PncId,boolean IsSet)
{
	ComM_PncToComSignalMapIdType PncToComSignalMapId;
	ComM_PncComSignalBufferIdType PncComSignalBufferId;
	P2CONST(ComM_PncConfigType,AUTOMATIC,COMM_APPL_CONST) pPncConfig;
    #if (STD_ON == COMM_NM_MODULE_USED)
    P2CONST(ComM_ChannelConfigType,AUTOMATIC,COMM_APPL_CONST) pChannelConfig;
    #endif
	P2CONST(ComM_PncComSignalConfigType,AUTOMATIC,COMM_APPL_CONST) pPncComSignalConfig;

	if (COMM_NUM_OF_PNC > PncId)
	{
		pPncConfig = &ComM_PncConfig[PncId];
		/* Iterate over the signals of the PncId */
		for (PncToComSignalMapId= pPncConfig-> PncComSignalStartId ;
			((PncToComSignalMapId<= pPncConfig-> PncComSignalEndId) && \
			 (COMM_NUM_OF_PNC_TO_COM_SIGNAL_MAP>PncToComSignalMapId));PncToComSignalMapId++)
		{
			pPncComSignalConfig = &ComM_PncComSignalConfig[PncToComSignalMapId];

			if (COMM_PNC_COM_SIGNAL_DIRECTION_TYPE_TX == pPncComSignalConfig->PncComSignalDirectionType)
			{
				PncComSignalBufferId = pPncComSignalConfig->PncComSignalBufferStartId+pPncConfig->PncByteOffset;
				if(COMM_NUM_OF_PNC_COM_SIGNAL_BUFFER > PncComSignalBufferId )
				{
					if (IsSet == TRUE)
					{
						ComM_PncComSignalBuffer[PncComSignalBufferId] |=  pPncConfig->PncBitMask;
					}
					else
					{
						ComM_PncComSignalBuffer[PncComSignalBufferId] &= (uint8)(~pPncConfig->PncBitMask);
					}
					Com_SendSignal(pPncComSignalConfig->PncComSignalId,
                                   &ComM_PncComSignalBuffer[pPncComSignalConfig->PncComSignalBufferStartId]);
				}
			} /* (COMM_PNC_COM_SIGNAL_DIRECTION_TYPE_TX == pPncComSignalConfig->PncComSignalDirectionType) */
            
            #if (STD_ON == COMM_NM_MODULE_USED)
			// Request Nm
			if (COMM_NUM_OF_CHANNELS > pPncComSignalConfig->PncComSignalChanneId)
			{
				pChannelConfig = &ComM_ChannelConfig[pPncComSignalConfig->PncComSignalChanneId];
				if (COMM_NM_VARIANT_TYPE_FULL == pChannelConfig->NmVariantType)
				{
					/* SWS_ComM_00869 , SWS_ComM_00870 */
					(void)Nm_NetworkRequest(pPncComSignalConfig->PncComSignalChanneId);
				}
			} /* (COMM_NUM_OF_CHANNELS > pPncComSignalConfig->PncComSignalChanneId) */
            #endif
		} /*  Iterate over the signals of the PncId */
	} /* (COMM_NUM_OF_PNC > PncId) */
}
#endif

#define COMM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
/*******************************************************************************************************************
*   For each change to this file, be sure to record:                                                               *
*      1.  who made the change and when the change was made                                                        *
*      2.  why the change was made and the intended result                                                         *
*   Following block needs to be repeated for each change                                                           *
*******************************************************************************************************************/
/*!*****************************************************************************************************************
*  @date    14-Jul-2023
*  @version 1.0.0
*  @author  pchinnat
*  @brief   Traceability - AUTOSAR 4.3 version initial implementation 
*******************************************************************************************************************/
