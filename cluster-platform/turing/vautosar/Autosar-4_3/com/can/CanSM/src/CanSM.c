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
*    @file CanSM.c
*    @ingroup CanSM
*    @brief This file implements the AUTOSAR CanSM module.The CanSM module is responsible for the control flow
*           abstraction of the configured CAN Controllers and CAN Transceivers.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "CanSM.h"
#include "CanSM_Lcfg.h"
#include "CanSM_ComM.h"
#include "CanSM_BswM.h"
#include "CanSM_TxTimeoutException.h"
#include "CanSM_Cbk.h"
#include "CanIf.h"
#include "ComM_BusSM.h"
#include "BswM_CanSM.h"
#include "SchM_CanSM.h"
#if (CANSM_PNC_SUPPORT == STD_ON)
#include "CanNm_Cbk.h"
#endif
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
# include "Det.h"
#endif
#if (CANSM_DEM_ERROR_REPORT == STD_ON)
#include "Dem.h"
#endif

/*******************************************************************************************************************/
/*  Version check                                                                                                  */
/*******************************************************************************************************************/
/* Software Version Check */
#if((CANSM_SW_MAJOR_VERSION != CANSM_CFG_SW_MAJOR_VERSION) || \
    (CANSM_SW_MINOR_VERSION != CANSM_CFG_SW_MINOR_VERSION) || \
    (CANSM_SW_PATCH_VERSION != CANSM_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if((CANSM_AR_RELEASE_MAJOR_VERSION != CANSM_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (CANSM_AR_RELEASE_MINOR_VERSION != CANSM_CFG_AR_RELEASE_MINOR_VERSION) || \
    (CANSM_AR_RELEASE_REVISION_VERSION != CANSM_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif
/********************************************************************************************************************
*  feature validation check                                                                                         *
********************************************************************************************************************/
/* Unsupported feature */
#if (CANSM_PNC_SUPPORT  == STD_ON)
    #error " CanSM PNC feature is not supported in current version "
#endif 
/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
/* Macro for static and inline type */
#ifndef CANSM_LOCAL 
#define CANSM_LOCAL                               static
#endif

#ifndef CANSM_LOCAL_INLINE
#define CANSM_LOCAL_INLINE                        LOCAL_INLINE
#endif
/*! @brief Defines the reset timer value */
#define CANSM_RESET_TIMER                                   0x0000u
/*! @brief Defines the PRE_FULLCOM state */
/*! @brief Defines the start up state Trcv normal  */
#define CANSM_SU_TRCV_NORMAL                                0x01u
/*! @brief Defines the start up state controller stopped */
#define CANSM_SU_CC_STOPPED                                 0x02u
/*! @brief Defines the start up state controller started */
#define CANSM_SU_CC_STARTED                                 0x03u
/*! @brief Defines the FULLCOM state */
/*! @brief Defines the Bus off check state */
#define CANSM_BO_BUS_OFF_CHECK                              0x11u
/*! @brief Defines the no Bus off state */
#define CANSM_S_NO_BUS_OFF                                  0x10u
/*! @brief Defines the full com ensured state */
#define CANSM_S_FULLCOM_ENSURED                             0x10u
/*! @brief Defines the tx offline state */
#define CANSM_BO_TX_OFFLINE                                 0x14u
/*! @brief Defines the SILENT state */
#define CANSM_S_SILENTCOM                                   0x20u
/*! @brief Defines the S_PRE_NOCOM state */
/*! @brief Defines the shutdown PN clear wakeup flag state */
#define CANSM_SD_PN_CLEAR_WUF                               0x21u
/*! @brief Defines the shutdown contoller stopped state */
#define CANSM_SD_CC_STOPPED                                 0x22u
/*! @brief Defines the shutdown contoller sleep state */
#define CANSM_SD_CC_SLEEP                                   0x23u
/*! @brief Defines the shutdown transceiver normal state */
#define CANSM_SD_TRCV_NORMAL                                0x24u
/*! @brief Defines the shutdown transceiver standby state */
#define CANSM_SD_TRCV_STANDBY                               0x25u
/*! @brief Defines the shutdown controller PN sleep state */
#define CANSM_SD_CC_SLEEP_PN                                0x26u
/*! @brief Defines the check wakeup flag  required sleep state */
#define CANSM_SD_CHK_WUF_CC_SLEEP                           0x27u
/*! @brief Defines the check wakeup flag sleep not required state */
#define CANSM_SD_CHK_WUF_NOT_CC_SLEEP                       0x28u
/*! @brief Defines the No Com  state */
#define CANSM_S_NOCOM                                       0x40u
/*! @brief Defines the start wakeup source state */
#define CANSM_STARTWAKEUPSOURCES_OK                         0x50u
/*! @brief Defines the interim state mask filter */
#define CANSM_S_INTERIM_STATE_FILTER                        0x0Fu
/*! @brief Defines the flag for interim state deteced   */
#define CANSM_S_INTERIM_STATE_DETECTED                      0x01u
/*! @brief Defines the network timer max value   */
#define CANSM_NETWORK_TIMER_MAX                             (0xFFFFFFFFU)
/*! @brief Defines the network L1ToL2Counter max value   */
#define CANSM_L1_TO_L2_COUNTER_MAX                          (0xFFU)
/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
#define CANSM_START_SEC_CODE
#include "MemMap.h"

/*!******************************************************************************************************************
*   @brief      This method check whether Ctrl Id is configured or not
*   @param[in]  CtrlId  requested Controller Id.
*   @param[out] Network pointer to get the Network Id.
*   @return     boolean Returns the whether the request controller id is valid.
*               TRUE    - valid controller id, Network parameter is updated and can be used 
*               FALSE   - invalid controller id, Network parameter is not updated and cannot be used
********************************************************************************************************************/
CANSM_LOCAL FUNC(boolean,CANSM_CODE) CanSM_CheckCtrlConfigStatus
(
    uint8 CtrlId,
    P2VAR(NetworkHandleType,AUTOMATIC,CANSM_APPL_DATA) Network
);
#if (CANSM_TRCV_HANDLING == STD_ON)
/*!******************************************************************************************************************
*   @brief      This method check whether TRCV Id is configured or not
*   @param[in]  TransceiverId  requested transceiver Id.
*   @param[out] Network pointer to get the Network Id.
*   @return     boolean Returns the whether the request controller id is valid.
*               TRUE    - valid controller id, Network parameter is updated and can be used 
*               FALSE   - invalid controller id, Network parameter is not updated and cannot be used
********************************************************************************************************************/
CANSM_LOCAL FUNC(boolean,CANSM_CODE) CanSM_CheckTrcvConfigStatus
(
    uint8 TransceiverId, 
    P2VAR(NetworkHandleType,AUTOMATIC,CANSM_APPL_DATA) Network
);
#endif
/*!******************************************************************************************************************
*   @brief      This method to get Updated Com Mode 
*   @param[in]  ControllerMode  Controller mode
*   @return     ComM_ModeType Returns the ComM mode
********************************************************************************************************************/
CANSM_LOCAL FUNC(ComM_ModeType,CANSM_CODE) CanSM_GetUpdatedMode(Can_ControllerStateType ControllerMode);
/*!******************************************************************************************************************
*   @brief      This method process the CanSM state machine
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_Statemachine(NetworkHandleType Network);
/*!******************************************************************************************************************
*   @brief      This method process the ComM Mode request
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_ProcessComModeRequest(NetworkHandleType Network);
/*!******************************************************************************************************************
*   @brief      This method intiate and processs the Shutdown 
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_InitiateShutdownProcess(NetworkHandleType Network);
/*!******************************************************************************************************************
*   @brief      This method is used to evaluvate the max mode request 
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_EvaluateMaxModeReq(NetworkHandleType Network);
/*!******************************************************************************************************************
*   @brief      This method is used to handle the CanSM timer
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_TimerHandling(NetworkHandleType Network);
/*!******************************************************************************************************************
*   @brief      This method is used to check the mode change and indicate to upper layer
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_CheckModeChangeIndication(NetworkHandleType Network);
/*!******************************************************************************************************************
*   @brief      This method is used to handle the Busoff Event
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_ProcessBusoffEvent(NetworkHandleType Network);
/*!******************************************************************************************************************
*   @brief      This method is used to handle the Busoff recovery
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_HandleBusOffRecovery(NetworkHandleType Network);
/*!******************************************************************************************************************
*   @brief      This method is used to get the Busoff configuration id
*   @param[in]  Network  network id 
*   @return     CanSM_BusOffIdType  returns the busoff configuration id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(CanSM_BusOffIdType,CANSM_CODE) CanSM_GetBusOffConfigId(NetworkHandleType Network);
/*!******************************************************************************************************************
*   @brief      This method is used to validate the Busoff recovery
*   @param[in]  Network  network id 
*   @param[in]  BusoffRecoveryPassCount  busoff recovery pass count 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_ValidateBusoffRecovery
(
    NetworkHandleType Network,
    uint32 BusoffRecoveryPassCount
);
/*!******************************************************************************************************************
*   @brief      This method is used to handle the Busoff recovery state NoBufoff
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_BusoffRecoveryNoBusOff(NetworkHandleType Network);
/*!******************************************************************************************************************
*   @brief      This method is used to handle the Busoff recovery state L1TxOff
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_BusoffRecoveryL1TxOff(NetworkHandleType Network);
/*!******************************************************************************************************************
*   @brief      This method is used to handle the Busoff recovery state L1Check
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_BusoffRecoveryL1Check(NetworkHandleType Network);
/*!******************************************************************************************************************
*   @brief      This method is used to handle the Busoff recovery state L2TxOff
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_BusoffRecoveryL2TxOff(NetworkHandleType Network);
/*!******************************************************************************************************************
*   @brief      This method is used to handle the Busoff recovery state L2Check
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_BusoffRecoveryL2Check(NetworkHandleType Network);
/*!******************************************************************************************************************
*   @brief      This method is used to get CanSM channel from the ComM channel
*   @param[in]  nmChannelHandle  ComM channel Id
*   @param[in]  NetworkHandleType returns the CanSM network Id
********************************************************************************************************************/
CANSM_LOCAL FUNC(NetworkHandleType,CANSM_CODE) CanSM_GetChIndexFromComMIndex(NetworkHandleType nmChannelHandle);
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This method is used to notify DET module about errors
*   @param[in]  nmChannelHandle  ApiId that caused the Error
*   @param[in]  nmChannelHandle  error id
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_Det_ReportError(uint8 ApiId, uint8 ErrorId);
#endif

#define CANSM_STOP_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
#define CANSM_START_SEC_VAR_INIT_LOCAL_8
#include "MemMap.h"

/*! @brief Initialize CanSM Module Init Status */
CANSM_LOCAL VAR(uint8,COMM_VAR_INIT) CanSM_InitStatus = CANSM_UNINITED;

#define CANSM_STOP_SEC_VAR_INIT_LOCAL_8
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC FUNCTION IMPLEMENTATION                                                                                   *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @brief      This service initializes the CanSM module
*   @param[in]  ConfigPtr  Pointer to init structure for the post build parameters of the CanSM
*   @ServiceID  0x00
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
*   @note       The CanSM_Init should be called before using the CanSM module for further processing.
********************************************************************************************************************/
FUNC(void,CANSM_CODE) CanSM_Init(P2CONST(CanSM_ConfigType,AUTOMATIC,CANSM_APPL_CONST) ConfigPtr)
{
    /* Local Variables */
    NetworkHandleType NetworkId;

    /* Check if module is already Initialized */
    if (CANSM_INITED != CanSM_InitStatus)
    {
        /* Initialize all Configured Network */
        for (NetworkId = 0; NetworkId < CANSM_NUM_OF_NETWORKS; NetworkId++)
        {
            /* Initialize Network Current mode to No Communication */
            CanSM_NetworkInfo[NetworkId].CurrentComMode = COMM_NO_COMMUNICATION;
            /* Initialize Network requested mode to No Communication */
            CanSM_NetworkInfo[NetworkId].RequestedComMode = COMM_NO_COMMUNICATION;
            /* Initialize Network requested mode to No Communication */
            CanSM_NetworkInfo[NetworkId].IndicatedComMode = COMM_NO_COMMUNICATION;
            /* Initialize Network Current state to CANSM_S_NOCOM */
            CanSM_NetworkInfo[NetworkId].CurrentState = CANSM_S_NOCOM;
            /* Initialize Bus off Recovery state */
            CanSM_NetworkInfo[NetworkId].BusoffRecoveryState = CANSM_BOR_NO_BUS_OFF;
            /* Initialize Network timer */
            CanSM_NetworkInfo[NetworkId].NetworkTimer = 0;
            /* Initialize L1 to L2 counter */
            CanSM_NetworkInfo[NetworkId].L1ToL2Counter = 0;
            /* Initialize Network Request Repetition time */
            CanSM_NetworkInfo[NetworkId].ModeReqRepetitionCounter = 0;
            /* Initialize Network Mode Request Repeat count */
            CanSM_NetworkInfo[NetworkId].ModeReqRepetitionTimer = CANSM_RESET_TIMER;
            /* Initialize Bus off Event report status */
            CanSM_NetworkInfo[NetworkId].BusOffEventReported = FALSE;
            #if (CANSM_GET_BUS_OFF_DELAY_FUNCTION == STD_ON)
            CanSM_UserBusOffDelay[NetworkId]=0U;    
            #endif
        }
        /* Update CanSM Module Init Status */
        CanSM_InitStatus = CANSM_INITED;
    }
    CANSM_DUMMY_STATEMENT(ConfigPtr);
}

/********************************************************************************************************************
*   @brief      This service de-initializes the CanSM module.
*   @ServiceID  0x14
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(void,CANSM_CODE) CanSM_DeInit(void)
{
    uint8 ErrorId = CANSM_E_NO_ERROR;
    
    /* Check If module is Initialized */
    if (CANSM_INITED != CanSM_InitStatus)
    {
        ErrorId = CANSM_E_UNINIT;
    }
    else
    {
        CanSM_InitStatus = CANSM_UNINITED;
    }
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    if (CANSM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanSM_Det_ReportError(CANSM_DEINIT_API, ErrorId);
    }
#else
    CANSM_DUMMY_STATEMENT(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This service shall change the communication mode of a CAN network to the requested one.
*   @param[in]  network Handle of destined communication network for request
*   @param[in]  ComM_Mode Requested communication mode
*   @return     Std_ReturnType E_OK: Service accepted E_NOT_OK: Service denied
*   @ServiceID  0x02
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant (only for different network handles)
********************************************************************************************************************/
FUNC(Std_ReturnType,COMM_CODE) CanSM_RequestComMode(NetworkHandleType network, ComM_ModeType ComM_Mode)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANSM_E_NO_ERROR;
    /* Get CanSM Channel index */
    NetworkHandleType Channel = CanSM_GetChIndexFromComMIndex(network);

    /* Check If module is Initialized */
    if (CANSM_INITED != CanSM_InitStatus)
    {
        ErrorId = CANSM_E_UNINIT;
    }
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    /* Check If requested Channel is valid */
    else if (CANSM_NUM_OF_NETWORKS <= Channel)
    {
        ErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
    /* Check If requested Mode is valid */
    else if (COMM_FULL_COMMUNICATION < ComM_Mode)
    {
        ErrorId = CANSM_E_INVALID_COMM_REQUEST;
    }
#endif
    else
    {
        /* Enter Critical section */
        CanSM_EnterCriticalSection();
        /* Update Channel requested state */
        CanSM_NetworkInfo[Channel].RequestedComMode = ComM_Mode;
        /* If requested mode is full com and current mode is silent com request Pdu mode online */
        if (ComM_Mode == COMM_FULL_COMMUNICATION)
        {
            (void)CanIf_SetPduMode(CanSM_NetworkConfig[Channel].ControllerId,CANIF_ONLINE);
        }
        else if (ComM_Mode == COMM_SILENT_COMMUNICATION)
        {
            /* If request mode is silent comm  */
            (void)CanIf_SetPduMode(CanSM_NetworkConfig[Channel].ControllerId,CANIF_TX_OFFLINE);
        }
        else
        {
            /* If request mode is No is  comm  */
            (void)CanIf_SetPduMode(CanSM_NetworkConfig[Channel].ControllerId,CANIF_OFFLINE);
        }
        /* Exit Critical section */
        CanSM_ExitCriticalSection();
        /* Update Return Value */
        RetVal = E_OK;
    }
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    if (CANSM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanSM_Det_ReportError(CANSM_REQUESTCOMMODE_API, ErrorId);
    }
#else
    CANSM_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}

/********************************************************************************************************************
*   @brief      This service shall put out the current communication mode of a CAN network
*   @param[in]  network Network handle, whose current communication mode shall be put outHandle of destined 
                communication network for request
*   @param[out] ComM_ModePtr Pointer, where to put out the current communication mode
*   @return     Std_ReturnType E_OK: Service accepted E_NOT_OK: Service denied
*   @ServiceID  0x03
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
FUNC(Std_ReturnType,COMM_CODE) CanSM_GetCurrentComMode
(
    NetworkHandleType network,
    P2VAR(ComM_ModeType,AUTOMATIC,CANSM_APPL_DATA) ComM_ModePtr
)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANSM_E_NO_ERROR;
    /* Get CanSM Channel index */
    NetworkHandleType Channel = CanSM_GetChIndexFromComMIndex(network);

    /* Check If module is Initialized */
    if (CANSM_INITED != CanSM_InitStatus)
    {
        ErrorId = CANSM_E_UNINIT;
    }
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    /* Check If requested Channel is valid */
    else if (CANSM_NUM_OF_NETWORKS <= Channel)
    {
        ErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
    /* Check If ComM_ModePtr is not NULL */
    else if (NULL_PTR == ComM_ModePtr)
    {
        ErrorId = CANSM_E_PARAM_POINTER;
    }
#endif
    else
    {
        /* Enter Critical section */
        CanSM_EnterCriticalSection();
        /* Update Channel requested state */
        *ComM_ModePtr = CanSM_NetworkInfo[Channel].CurrentComMode;
        /* Exit Critical section */
        CanSM_ExitCriticalSection();
        /* Update Return value */
        RetVal = E_OK;
    }
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    if (CANSM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanSM_Det_ReportError(CANSM_GETCURRENTCOMMODE_API, ErrorId);
    }
#else
    CANSM_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      This callback function notifies the CanSM about a bus-off event on a certain CAN controller, which 
*               needs to be considered with the specified bus-off recovery handling for the impacted CAN network.
*   @param[in]  ControllerId CAN controller, which detected a bus-off event
*   @ServiceID  0x04
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant (only for different CanControllers)
********************************************************************************************************************/
FUNC(void,CANSM_CODE) CanSM_ControllerBusOff(uint8 ControllerId)
{
    /* Local Variables */
    NetworkHandleType NetworkId = 0;
    uint8 ErrorId = CANSM_E_NO_ERROR;

    /* Check If module is Initialized */
    if (CANSM_INITED != CanSM_InitStatus)
    {
        ErrorId = CANSM_E_UNINIT;
    }
    else
    {
        /* Check if requested Controller Id is configured */
        if (TRUE == CanSM_CheckCtrlConfigStatus(ControllerId, &NetworkId))
        {
            /* Check added to resolve coverity Out of bound Warning */
            if (CANSM_NUM_OF_NETWORKS > NetworkId)
            {
                /* Enter Critical section */
                CanSM_EnterCriticalSection();
                /* Update Bufoff Event Status */
                CanSM_NetworkInfo[NetworkId].BusOffEventReported = TRUE;
                /* Exit Critical section */
                CanSM_ExitCriticalSection();
            }
        }
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
        else
        {
            ErrorId = CANSM_E_PARAM_CONTROLLER;
        }
#endif
    }
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    if (CANSM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanSM_Det_ReportError(CANSM_CONTROLLERBUSOFF_API, ErrorId);
    }
#else
    CANSM_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      This callback shall notify the CanSM module about a CAN controller mode change.
*   @param[in]  ControllerId CAN controller, whose mode has changed
*   @param[in]  ControllerMode Notified CAN controller mode
*   @ServiceID  0x07
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant (only for different CanControllers)
********************************************************************************************************************/
FUNC(void,CANSM_CODE) CanSM_ControllerModeIndication(uint8 ControllerId,Can_ControllerStateType ControllerMode)
{
    /* Local Variables */
    NetworkHandleType NetworkId = 0;
    ComM_ModeType UpdatedMode = COMM_NO_COMMUNICATION;
    uint8 ErrorId = CANSM_E_NO_ERROR;

    /* Check If module is Initialized */
    if (CANSM_INITED != CanSM_InitStatus)
    {
        ErrorId = CANSM_E_UNINIT;
    }
    else
    {
        /* Check if requested Controller Id is configured */
        if (TRUE == CanSM_CheckCtrlConfigStatus(ControllerId, &NetworkId))
        {
            /* Check added to resolve coverity Out of bound Warning */
            if (CANSM_NUM_OF_NETWORKS > NetworkId)
            {
                /* Get ComM Mode */
                UpdatedMode = CanSM_GetUpdatedMode(ControllerMode);
                /* Enter Critical section */
                CanSM_EnterCriticalSection();
                /* Update Current Network Mode */
                CanSM_NetworkInfo[NetworkId].CurrentComMode = UpdatedMode;
                /* Exit Critical section */
                CanSM_ExitCriticalSection();
                /* Check whether indicated mode is CAN_CS_STOPPED */
                if (CAN_CS_STOPPED == ControllerMode)
                {
                    /* Check whether Current state  is CANSM_SU_CC_STOPPED */
                    if (CANSM_SU_CC_STOPPED == (CanSM_NetworkInfo[NetworkId].CurrentState))
                    {
                        /* Update CurrentState as CANSM_SU_CC_STARTED */
                        CanSM_NetworkInfo[NetworkId].CurrentState = CANSM_SU_CC_STARTED;
                        /* Reset timer */
                        CanSM_NetworkInfo[NetworkId].ModeReqRepetitionTimer = CANSM_RESET_TIMER;
                    }
                    /* Check whether Current state  is CANSM_SD_CC_STOPPED */
                    else if(CANSM_SD_CC_STOPPED == (CanSM_NetworkInfo[NetworkId].CurrentState))
                    {
                        /* Update CurrentState as CANSM_SD_CC_SLEEP */
                        CanSM_NetworkInfo[NetworkId].CurrentState = CANSM_SD_CC_SLEEP;
                        /* Reset timer */
                        CanSM_NetworkInfo[NetworkId].ModeReqRepetitionTimer = CANSM_RESET_TIMER;
                    }
                    else
                    {
                        /* Do Nothing */
                    }
                }
                /* Check whether indicated mode is CAN_CS_SLEEP */
                else if (CAN_CS_SLEEP == ControllerMode)
                {
                    if (CANSM_SD_CC_SLEEP == (CanSM_NetworkInfo[NetworkId].CurrentState))
                    {
                        #if (CANSM_TRCV_HANDLING == STD_ON)
                        /* Update CurrentState as CANSM_SD_TRCV_NORMAL */
                        CanSM_NetworkInfo[NetworkId].CurrentState = CANSM_SD_TRCV_NORMAL;
                        /* Reset timer */
                        CanSM_NetworkInfo[NetworkId].ModeReqRepetitionTimer = CANSM_RESET_TIMER;
                        #else
                        /* Update current state to CANSM_S_NOCOM */
                        CanSM_NetworkInfo[NetworkId].CurrentState = CANSM_S_NOCOM;
                        /* Update New Com Mode */
                        CanSM_NetworkInfo[NetworkId].CurrentComMode = COMM_NO_COMMUNICATION;
                        /* Initialize Mode Request Repetation counter */
                        CanSM_NetworkInfo[NetworkId].ModeReqRepetitionCounter = 0;
                        /* Reset timer */
                        CanSM_NetworkInfo[NetworkId].ModeReqRepetitionTimer = CANSM_RESET_TIMER;
                        #endif
                        
                    }
                }
                /* Check whether indicated mode is CAN_CS_STARTED */
                else if ((CAN_CS_STARTED == ControllerMode) &&
                        (CANSM_SU_CC_STARTED == (CanSM_NetworkInfo[NetworkId].CurrentState)))
                {
                    /* Check if the requested mode is COMM_NO_COMMUNICATION */
                    if (COMM_NO_COMMUNICATION == CanSM_NetworkInfo[NetworkId].RequestedComMode)
                    {
                        /* Update current state as CANSM_STARTWAKEUPSOURCES_OK */
                        CanSM_NetworkInfo[NetworkId].CurrentState = CANSM_STARTWAKEUPSOURCES_OK;
                    }
                }
                else
                {
                    /* Do Nothing */
                }
            }
        }
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
        else
        {
            ErrorId = CANSM_E_PARAM_CONTROLLER;
        }
#endif
    }
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    if (CANSM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanSM_Det_ReportError(CANSM_REQUESTCOMMODE_API, ErrorId);
    }
#else
    CANSM_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief  Scheduled function of the CanSM
*   @ServiceID  0x07
********************************************************************************************************************/
FUNC(void,CANSM_CODE) CanSM_MainFunction(void)
{
    /* Local Variables */
    NetworkHandleType NetworkId;
    uint8 ErrorId = CANSM_E_NO_ERROR;

    /* Check If module is Initialized */
    if (CANSM_INITED != CanSM_InitStatus)
    {
        ErrorId = CANSM_E_UNINIT;
    }
    else
    {
        /* Check Mode Change request for all configured Network Channels */
        for(NetworkId = 0; NetworkId < CANSM_NUM_OF_NETWORKS; NetworkId++)
        {
            /* Check if busoff Notification is received */
            if (TRUE == CanSM_NetworkInfo[NetworkId].BusOffEventReported)
            {
                /* Handle Busoff Event */
                CanSM_ProcessBusoffEvent(NetworkId);
            }
            else
            {
                /* Process Com Mode Request */
                CanSM_ProcessComModeRequest(NetworkId);
                /* Evaluate Max Mode Request */
                CanSM_EvaluateMaxModeReq(NetworkId);
                /* Handle Mode Repitation timer */
                CanSM_TimerHandling(NetworkId);
                /* Check whether timer is running or any current state is equal to Interim state */
                if ((CANSM_RESET_TIMER == CanSM_NetworkInfo[NetworkId].ModeReqRepetitionTimer) &&
                    (((CanSM_NetworkInfo[NetworkId].CurrentState) & CANSM_S_INTERIM_STATE_FILTER) >= CANSM_S_INTERIM_STATE_DETECTED))
                {
                    /* Invoke State Machine */
                    CanSM_Statemachine(NetworkId);
                }
            }
            /* Handle Mode change Indication */
            CanSM_CheckModeChangeIndication(NetworkId);
            /* Handle busoff Recovery */
            CanSM_HandleBusOffRecovery(NetworkId);
        }
    }
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    if (CANSM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanSM_Det_ReportError(CANSM_MAINFUNCTION_API, ErrorId);
    }
#else
    CANSM_DUMMY_STATEMENT(ErrorId);
#endif
}
#if (CANSM_VERSION_INFO_API == STD_ON)
/********************************************************************************************************************
*   @brief      This service puts out the version information of this module
*   @param[in]  VersionInfo  Pointer to where to store the version information of this module.
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(void,CANSM_CODE) CanSM_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,CANSM_APPL_DATA) VersionInfo)
{
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    /* Local Variables */
    uint8 ErrorId = CANSM_E_NO_ERROR;
#endif

#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    /* Check if parameter VersionInfo is valid */
    if (NULL_PTR == VersionInfo)
    {
        ErrorId = CANSM_E_PARAM_POINTER;
    }
    else
#endif
    {
        VersionInfo->vendorID         = CANSM_VENDOR_ID;
        VersionInfo->moduleID         = CANSM_MODULE_ID;
        VersionInfo->sw_major_version = CANSM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = CANSM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = CANSM_SW_PATCH_VERSION;
    }
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != CANSM_E_NO_ERROR)
    {
      CanSM_Det_ReportError(CANSM_GETVERSIONINFO_API, ErrorId);
    }
#endif
}
#endif
/********************************************************************************************************************
*   @brief      This function shall be called by EcuM when a wakeup source shall be started
*   @param[in]  network  Affected CAN network
*   @return     Std_ReturnType E_OK: Service accepted E_NOT_OK: Service denied
*   @ServiceID  0x11
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType,CANSM_CODE) CanSM_StartWakeupSource(NetworkHandleType Network)
{
    /* Local Variables */
    uint8 ErrorId = CANSM_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;

    /* Check If module is Initialized */
    if (CANSM_INITED != CanSM_InitStatus)
    {
        ErrorId = CANSM_E_UNINIT;
    }
    /* Check whether Network Id is valid */
    else if (CANSM_NUM_OF_NETWORKS <= Network)
    {
        ErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
    else
    {
        if (COMM_NO_COMMUNICATION == CanSM_NetworkInfo[Network].RequestedComMode)
        {
            #if (CANSM_TRCV_HANDLING == STD_ON)
            CanSM_NetworkInfo[Network].CurrentState = CANSM_SU_TRCV_NORMAL;
            #else
            CanSM_NetworkInfo[Network].CurrentState = CANSM_SU_CC_STOPPED;
            #endif
            /* Invoke State Machine */
            CanSM_Statemachine(Network);
            /* Check whether start wakeup source request is processed */
            if (CANSM_STARTWAKEUPSOURCES_OK == CanSM_NetworkInfo[Network].CurrentState)
            {
                /* Update Ret Val */
                RetVal = E_OK;
            }
            /* Initialize Current State */
            CanSM_NetworkInfo[Network].CurrentState = CANSM_S_NOCOM;
        }
    }
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    if (CANSM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanSM_Det_ReportError(CANSM_STARTWAKEUPSOURCE_API, ErrorId);
    }
#else
    CANSM_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}

/********************************************************************************************************************
*   @brief      This function shall be called by EcuM when a wakeup source shall be stopped
*   @param[in]  network  Affected CAN network
*   @return     Std_ReturnType E_OK: Service accepted E_NOT_OK: Service denied
*   @ServiceID  0x12
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType,CANSM_CODE) CanSM_StopWakeupSource(NetworkHandleType Network)
{
    /* Local Variables */
    uint8 ErrorId = CANSM_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;

    /* Check If module is Initialized */
    if (CANSM_INITED != CanSM_InitStatus)
    {
        ErrorId = CANSM_E_UNINIT;
    }
    /* Check whether Network Id is valid */
    else if (CANSM_NUM_OF_NETWORKS <= Network)
    {
        ErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
    else
    {
        if (COMM_NO_COMMUNICATION == CanSM_NetworkInfo[Network].RequestedComMode)
        {
            /* Update current state as CANSM_SU_CC_STOPPED */
            CanSM_NetworkInfo[Network].CurrentState = CANSM_SD_CC_STOPPED;
            /* Invoke State Machine */
            CanSM_Statemachine(Network);
        }
        if (CANSM_S_NOCOM == CanSM_NetworkInfo[Network].CurrentState)
        {
            /* Update Ret Val */
            RetVal = E_OK;
        }
    }
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    if (CANSM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanSM_Det_ReportError(CANSM_STOPWAKEUPSOURCE_API, ErrorId);
    }
#else
    CANSM_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
#if (CANSM_SET_BAUD_RATE_API == STD_ON)
/********************************************************************************************************************
*   @brief      This service shall start an asynchronous process to change the baud rate for the configured CAN 
*               controllers of a certain CAN network. Depending on necessary baud rate modifications the controllers 
*               might have to reset.
*   @param[in]  Network  Handle of the addressed CAN network for the baud rate change
*   @param[in]  BaudRateConfigID  references a baud rate configuration by ID
*   @return     Std_ReturnType E_OK: Service request accepted, setting of (new) baud rate started 
*               E_NOT_OK: Service request not accepted
*   @ServiceID  0x0d
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different Networks. Non reentrant for the same Network.
********************************************************************************************************************/
FUNC(Std_ReturnType,CANSM_CODE) CanSM_SetBaudrate(NetworkHandleType Network, uint16 BaudRateConfigID)
{
    /* Local Variables */
    uint8 CtrlId;
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANSM_E_NO_ERROR;

    /* Check If module is Initialized */
    if (CANSM_INITED != CanSM_InitStatus)
    {
        ErrorId = CANSM_E_UNINIT;
    }
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    /* Check If requested Network is valid */
    else if (CANSM_NUM_OF_NETWORKS <= Network)
    {
        ErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
#endif
    else
    {
        /* Check whether requested network is in COMM_FULL_COMMUNICATION */
        if (COMM_FULL_COMMUNICATION == (CanSM_NetworkInfo[Network].CurrentComMode))
        {
            /* Get Ctrl Id */
            CtrlId = CanSM_NetworkConfig[Network].ControllerId;
            /* Invoke CanIf_SetBaudrate API */
            RetVal = CanIf_SetBaudrate(CtrlId, BaudRateConfigID);
        }
    }
    #if (CANSM_DEV_ERROR_DETECT == STD_ON)
    if (CANSM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanSM_Det_ReportError(CANSM_SETBAUDRATE_API, ErrorId);
    }
    #else
    CANSM_DUMMY_STATEMENT(ErrorId);
    #endif
    return RetVal;
}
#endif
#if (CANSM_ICOM_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief      This service shall change the Icom Configuration of a CAN network to the requested one.
*   @param[in]  Network  Handle of destined communication network for request
*   @param[in]  ConfigurationId  Requested Configuration
*   @return     Std_ReturnType E_OK: Request accepted E_NOT_OK: Request denied
*   @ServiceID  0x0f
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant only for different network handles
********************************************************************************************************************/
extern FUNC(Std_ReturnType,CANSM_CODE) CanSM_SetIcomConfiguration
(
    NetworkHandleType Network,
    IcomConfigIdType ConfigurationId
)
{
    /* Local Variables */
    uint8 CtrlId;
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANSM_E_NO_ERROR;

    /* Check If module is Initialized */
    if (CANSM_INITED != CanSM_InitStatus)
    {
        ErrorId = CANSM_E_UNINIT;
    }
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    /* Check If requested Network is valid */
    else if (CANSM_NUM_OF_NETWORKS <= Network)
    {
        ErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
#endif
    else
    {
        /* Get Ctrl Id */
        CtrlId = CanSM_NetworkConfig[Network].ControllerId;
        /* Invoke CanIf_SetIcomConfiguration API */
        RetVal = CanIf_SetIcomConfiguration(CtrlId, ConfigurationId);
    }
    #if (CANSM_DEV_ERROR_DETECT == STD_ON)
    if (CANSM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanSM_Det_ReportError(CANSM_SETICOMCONFIGURATION_API, ErrorId);
    }
    #else
    CANSM_DUMMY_STATEMENT(ErrorId);
    #endif
    return RetVal;
}
#endif
#if (CANSM_TX_OFFLINE_ACTIVE_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This function can be used to set all CanSM channels of the ECU to a receive only mode. This mode will 
*               be kept either until it is set back, or the ECU is reset.
*   @param[in]  CanSM_Passive  TRUE: set all CanSM channels to passive, i.e. receive only 
*               FALSE: set all CanSM channels back to non-passive
*   @return     Std_ReturnType E_OK: Request accepted E_NOT_OK: Request denied
*   @ServiceID  0x13
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType,CANSM_CODE) CanSM_SetEcuPassive(boolean CanSM_Passive)
{
    /* Local Variables */
    uint8 NetworkId;
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANSM_E_NO_ERROR;

    /* Check If module is Initialized */
    if (CANSM_INITED != CanSM_InitStatus)
    {
        ErrorId = CANSM_E_UNINIT;
    }
    else
    {
        /* Loop all the networks */
        for (NetworkId = 0; NetworkId < CANSM_NUM_OF_NETWORKS; NetworkId++)
        {
            /* Invoke CanIf_SetPduMode to set Pdu mode to CANIF_TX_OFFLINE */
            RetVal = CanIf_SetPduMode((CanSM_NetworkConfig[NetworkId].ControllerId), CANIF_TX_OFFLINE);
        }
    }
    #if (CANSM_DEV_ERROR_DETECT == STD_ON)
    if (CANSM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanSM_Det_ReportError(CANSM_SETECUPASSIVE_API, ErrorId);
    }
    #else
    CANSM_DUMMY_STATEMENT(ErrorId);
    #endif
    return RetVal;
}
#endif
#if (CANSM_TRCV_HANDLING == STD_ON)
/********************************************************************************************************************
*   @brief      This callback shall notify the CanSM module about a CAN transceiver mode change.
*   @param[in]  TransceiverId CAN transceiver, whose mode has changed
*   @param[in]  TransceiverMode Notified CAN transceiver mode
*   @ServiceID  0x09
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different CAN Transceivers
********************************************************************************************************************/
FUNC(void,CANSM_CODE) CanSM_TransceiverModeIndication(uint8 TransceiverId,CanTrcv_TrcvModeType TransceiverMode)
{
    /* Local Variables */
    NetworkHandleType NetworkId = 0;
    uint8 ErrorId = CANSM_E_NO_ERROR;

    /* Check If module is Initialized */
    if (CANSM_INITED != CanSM_InitStatus)
    {
        ErrorId = CANSM_E_UNINIT;
    }
    else
    {
        /* Check if requested Controller Id is configured */
        if (TRUE == CanSM_CheckTrcvConfigStatus(TransceiverId, &NetworkId))
        {
            /* Check added to resolve coverity Out of bound Warning */
            if (CANSM_NUM_OF_NETWORKS > NetworkId)
            {
                /* Check whether TRCV mode is Normal */
                if (CANTRCV_TRCVMODE_NORMAL == TransceiverMode)
                {
                    /* Check whether TRCV Normal state is requested */
                    if (CANSM_SU_TRCV_NORMAL == (CanSM_NetworkInfo[NetworkId].CurrentState))
                    {
                        /* Update current state to CANSM_SU_CC_STOPPED */
                        CanSM_NetworkInfo[NetworkId].CurrentState = CANSM_SU_CC_STOPPED;
                        /* Reset timer */
                        CanSM_NetworkInfo[NetworkId].ModeReqRepetitionTimer = CANSM_RESET_TIMER;
                    }
                    else if(CANSM_SD_TRCV_NORMAL == (CanSM_NetworkInfo[NetworkId].CurrentState))
                    {
                        /* Update current state to CANSM_SD_TRCV_STANDBY */
                        CanSM_NetworkInfo[NetworkId].CurrentState = CANSM_SD_TRCV_STANDBY;
                        /* Reset timer */
                        CanSM_NetworkInfo[NetworkId].ModeReqRepetitionTimer = CANSM_RESET_TIMER;
                    }
                }
                /* check whether TRCV mode is Standby */
                else if ((CANTRCV_TRCVMODE_STANDBY == TransceiverMode) &&
                        (CANSM_SD_TRCV_STANDBY == (CanSM_NetworkInfo[NetworkId].CurrentState)))
                {
                    /* Update current state to CANSM_S_NOCOM */
                    CanSM_NetworkInfo[NetworkId].CurrentState = CANSM_S_NOCOM;
                    /* Update New Com Mode */
                    CanSM_NetworkInfo[NetworkId].CurrentComMode = COMM_NO_COMMUNICATION;
                    /* Initialize Mode Request Repetation counter */
                    CanSM_NetworkInfo[NetworkId].ModeReqRepetitionCounter = 0;
                    /* Reset timer */
                    CanSM_NetworkInfo[NetworkId].ModeReqRepetitionTimer = CANSM_RESET_TIMER;
                }
                else
                {
                    /* Do Nothing */
                }
            }
        }
        #if (CANSM_DEV_ERROR_DETECT == STD_ON)
        else
        {
            ErrorId = CANSM_E_PARAM_TRANSCEIVER;
        }
        #endif
    }

#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    if (CANSM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanSM_Det_ReportError(CANSM_TRANSCEIVERMODEINDICATION_API, ErrorId);
    }
#else
    CANSM_DUMMY_STATEMENT(ErrorId);
#endif
}
#if (CANSM_PNC_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief      This callback function shall indicate the CanIf_ClearTrcvWufFlag API process end for the notified 
*               CAN Transceiver.
*   @param[in]  Transceiver Affected CAN network
*   @ServiceID  0x08
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different CAN Transceivers
********************************************************************************************************************/
FUNC(void,CANSM_CODE) CanSM_ClearTrcvWufFlagIndication(uint8 Transceiver)
{
    NetworkHandleType NetworkId = 0;
    uint8 ErrorId = CANSM_E_NO_ERROR;

    /* Check If module is Initialized */
    if (CANSM_INITED != CanSM_InitStatus)
    {
        ErrorId = CANSM_E_UNINIT;
    }
    else
    {
        /* Check if requested Controller Id is configured */
        if (TRUE == CanSM_CheckTrcvConfigStatus(Transceiver, &NetworkId))
        {
            /* Check added to resolve coverity Out of bound Warning */
            if (CANSM_NUM_OF_NETWORKS > NetworkId)
            {
                /* Check whether current state of requested Network is CANSM_SD_PN_CLEAR_WUF */
                if (CANSM_SD_PN_CLEAR_WUF == (CanSM_NetworkInfo[NetworkId].CurrentState))
                {
                    /* Update current state to CANSM_SU_CC_STOPPED */
                    CanSM_NetworkInfo[NetworkId].CurrentState = CANSM_SD_CC_STOPPED;
                    /* Reset timer */
                    CanSM_NetworkInfo[NetworkId].ModeReqRepetitionTimer = CANSM_RESET_TIMER;
                }
            }
        }
        #if (CANSM_DEV_ERROR_DETECT == STD_ON)
        else
        {
            ErrorId = CANSM_E_PARAM_TRANSCEIVER;
        }
        #endif
    }

#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    if (CANSM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanSM_Det_ReportError(CANSM_CLEARTRCVWUFFLAGINDICATION_API, ErrorId);
    }
#else
    CANSM_DUMMY_STATEMENT(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This callback function indicates the CanIf_CheckTrcvWakeFlag API process end for the notified CAN 
*               Transceiver.
*   @param[in]  Transceiver Requested Transceiver
*   @ServiceID  0x0a
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different CAN Transceivers
********************************************************************************************************************/
FUNC(void,CANSM_CODE) CanSM_CheckTransceiverWakeFlagIndication(uint8 Transceiver)
{
    NetworkHandleType NetworkId = 0;
    uint8 ErrorId = CANSM_E_NO_ERROR;

    /* Check If module is Initialized */
    if (CANSM_INITED != CanSM_InitStatus)
    {
        ErrorId = CANSM_E_UNINIT;
    }
    else
    {
        /* Check if requested Controller Id is configured */
        if (TRUE == CanSM_CheckTrcvConfigStatus(Transceiver, &NetworkId))
        {
            /* Check added to resolve coverity Out of bound Warning */
            if (CANSM_NUM_OF_NETWORKS > NetworkId)
            {
                /* Check whether current state of requested Network is CANSM_SD_CHK_WUF_CC_SLEEP */
                if (CANSM_SD_CHK_WUF_CC_SLEEP == (CanSM_NetworkInfo[NetworkId].CurrentState))
                {
                    /* Update CurrentState to CANSM_SU_CC_STOPPED */
                    CanSM_NetworkInfo[NetworkId].CurrentState = CANSM_S_NOCOM;
                    /* Update CurrentComMode to COMM_NO_COMMUNICATION */
                    CanSM_NetworkInfo[NetworkId].CurrentComMode = COMM_NO_COMMUNICATION;
                    /* Reset timer */
                    CanSM_NetworkInfo[NetworkId].ModeReqRepetitionTimer = CANSM_RESET_TIMER;
                }
                /* Check whether current state of requested Network is CANSM_SD_CHK_WUF_NOT_CC_SLEEP */
                else if (CANSM_SD_CHK_WUF_NOT_CC_SLEEP == (CanSM_NetworkInfo[NetworkId].CurrentState))
                {
                    /* Update current state to CANSM_SU_CC_STOPPED */
                    CanSM_NetworkInfo[NetworkId].CurrentState = CANSM_SD_PN_CLEAR_WUF;
                    /* Reset timer */
                    CanSM_NetworkInfo[NetworkId].ModeReqRepetitionTimer = CANSM_RESET_TIMER;
                }
                else
                {
                    /* Do Nothing */
                }
            }
        }
        #if (CANSM_DEV_ERROR_DETECT == STD_ON)
        else
        {
            ErrorId = CANSM_E_PARAM_TRANSCEIVER;
        }
        #endif
    }

#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    if (CANSM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanSM_Det_ReportError(CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_API, ErrorId);
    }
#else
    CANSM_DUMMY_STATEMENT(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This callback function indicates that the transceiver is running in PN communication mode.
*   @param[in]  Transceiver CAN transceiver, which was checked for PN availability
*   @ServiceID  0x06
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different CAN Transceivers
********************************************************************************************************************/
FUNC(void,CANSM_CODE) CanSM_ConfirmPnAvailability(uint8 TransceiverId)

{
    NetworkHandleType NetworkId = 0;
    uint8 ErrorId = CANSM_E_NO_ERROR;

    /* Check If module is Initialized */
    if (CANSM_INITED != CanSM_InitStatus)
    {
        ErrorId = CANSM_E_UNINIT;
    }
    else
    {
        /* Check if requested Controller Id is configured */
        if (TRUE == CanSM_CheckTrcvConfigStatus(TransceiverId, &NetworkId))
        {
            /* Check added to resolve coverity Out of bound Warning */
            if (CANSM_NUM_OF_NETWORKS > NetworkId)
            {
                /* Intimate Pn Availability to NM */
                CanNm_ConfirmPnAvailability(NetworkId);
            }
        }
        #if (CANSM_DEV_ERROR_DETECT == STD_ON)
        else
        {
            ErrorId = CANSM_E_PARAM_TRANSCEIVER;
        }
        #endif
    }
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    if (CANSM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanSM_Det_ReportError(CANSM_CONFIRMPNAVAILABILITY_API, ErrorId);
    }
#else
    CANSM_DUMMY_STATEMENT(ErrorId);
#endif
}
#endif
#endif
#if (CANSM_PNC_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This function shall notify the CanSM module, that the CanNm has detected for the affected partial
*               CAN network a tx timeout exception, which shall be recovered within the respective network state 
*               machine of the CanSM module.
*   @param[in]  Channel Affected CAN network
*   @ServiceID  0x0b
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(void,CANSM_CODE) CanSM_TxTimeoutException(NetworkHandleType Channel)
{
    /* Local Variables */
    uint8 ErrorId = CANSM_E_NO_ERROR;

    /* Check If module is Initialized */
    if (CANSM_INITED != CanSM_InitStatus)
    {
        ErrorId = CANSM_E_UNINIT;
    }
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
    /* Check If requested Network is valid */
    else if (CANSM_NUM_OF_NETWORKS <= Channel)
    {
        ErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
#endif
    else
    {
        /* Update current state to CANSM_SU_CC_STOPPED */
        CanSM_NetworkInfo[Channel].CurrentState = CANSM_SU_CC_STOPPED;
        /* Reset timer */
        CanSM_NetworkInfo[Channel].ModeReqRepetitionTimer = CANSM_RESET_TIMER;
        /* Update Current Com Mode as COMM_SILENT_COMMUNICATION */
        CanSM_NetworkInfo[Channel].CurrentComMode = COMM_SILENT_COMMUNICATION;
    }
    #if (CANSM_DEV_ERROR_DETECT == STD_ON)
    if (CANSM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanSM_Det_ReportError(CANSM_TXTIMEOUTEXCEPTION_API, ErrorId);
    }
    #else
    CANSM_DUMMY_STATEMENT(ErrorId);
    #endif
}
#endif

#if (CANSM_ICOM_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service shall inform about the change of the Icom Configuration of a CAN network.
*   @param[in]  ControllerId CAN Controller Id, whose configuration has changed.
*   @param[in]  ConfigurationId Changed Configuration Id
*   @param[in]  Error ICOM_SWITCH_E_OK: No Error 
*               ICOM_SWITCH_E_FAILED: Switch to requested Configuration failed. Severe Error.
*   @ServiceID  0x10
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant only for different network handles
********************************************************************************************************************/
extern FUNC(void,CANSM_CODE) CanSM_CurrentIcomConfiguration
(
    uint8 ControllerId, 
    IcomConfigIdType ConfigurationId,
    IcomSwitch_ErrorType Error
)
{
    NetworkHandleType NetworkId;
    boolean CtrlIdConfigSts = FALSE;
    uint8 ErrorId = CANSM_E_NO_ERROR;

    /* Check If module is Initialized */
    if (CANSM_INITED != CanSM_InitStatus)
    {
        ErrorId = CANSM_E_UNINIT;
    }
    else
    {
        /* find the Network Id */
        for (NetworkId = 0; NetworkId < CANSM_NUM_OF_NETWORKS; NetworkId++)
        {
            if (ControllerId == CanSM_NetworkConfig[NetworkId].ControllerId)
            {
                CtrlIdConfigSts = TRUE;
                break;
            }
        }
        if (TRUE == CtrlIdConfigSts)
        {
            /* Indicate to BswM about CurrentIcomConfiguration */
            /* To DO, call back implementation is not implemented in BswM */
            // BswM_CanSM_CurrentIcomConfiguration(NetworkId, ConfigurationId, Error);
        }
        #if (CANSM_DEV_ERROR_DETECT == STD_ON)
        else
        {
            ErrorId = CANSM_E_PARAM_CONTROLLER;
        }
        #endif
    }
    #if (CANSM_DEV_ERROR_DETECT == STD_ON)
    if (CANSM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanSM_Det_ReportError(CANSM_CURRENTICOMCONFIGURATION_API, ErrorId);
    }
    #else
    CANSM_DUMMY_STATEMENT(ErrorId);
    #endif
}
#endif

/********************************************************************************************************************
*  PRIVATE FUNCTION IMPLEMENTATION                                                                                  *
********************************************************************************************************************/
/********************************************************************************************************************
*   @brief      This method check whether Ctrl Id is configured or not
*   @param[in]  CtrlId  requested Controller Id.
*   @param[out] Network pointer to get the Network Id.
*   @return     boolean Returns the whether the request controller id is valid.
*               TRUE    - valid controller id, Network parameter is updated and can be used 
*               FALSE   - invalid controller id, Network parameter is not updated and cannot be used
********************************************************************************************************************/
CANSM_LOCAL FUNC(boolean,CANSM_CODE) CanSM_CheckCtrlConfigStatus
(
    uint8 CtrlId,
    P2VAR(NetworkHandleType,AUTOMATIC,CANSM_APPL_DATA) Network
)
{
    /* Local Variables */
    /* Network Configuration */
    P2CONST(CanSM_NetworkConfigType,AUTOMATIC,CANSM_APPL_CONST) pCanSMNetworkConfig;
    /* Network Id */
    NetworkHandleType NetworkId;
    /* Controller configuration status */
    boolean CtrlCfgStatus = FALSE;

    /* Check if requsted Controller Id is configured */
    for (NetworkId = 0; ((NetworkId < CANSM_NUM_OF_NETWORKS) && (FALSE == CtrlCfgStatus)); NetworkId++)
    {
        /* Get Network Configuration */
        pCanSMNetworkConfig = &CanSM_NetworkConfig[NetworkId];
        if (CtrlId == pCanSMNetworkConfig -> ControllerId)
        {
            /* Copy Network Id */
            *Network = NetworkId;
            /* Set True as Ctrl Configuration Status */
            CtrlCfgStatus = TRUE;
        }
    }
    return CtrlCfgStatus;
}
#if (CANSM_TRCV_HANDLING == STD_ON)
/********************************************************************************************************************
*   @brief      This method check whether TRCV Id is configured or not
*   @param[in]  TransceiverId  requested transceiver Id.
*   @param[out] Network pointer to get the Network Id.
*   @return     boolean Returns the whether the request controller id is valid.
*               TRUE    - valid controller id, Network parameter is updated and can be used 
*               FALSE   - invalid controller id, Network parameter is not updated and cannot be used
********************************************************************************************************************/
CANSM_LOCAL FUNC(boolean,CANSM_CODE) CanSM_CheckTrcvConfigStatus
(
    uint8 TransceiverId, 
    P2VAR(NetworkHandleType,AUTOMATIC,CANSM_APPL_DATA) Network
)
{
    /* Local Variables */
    /* Network Configuration */
    P2CONST(CanSM_NetworkConfigType,AUTOMATIC,CANSM_APPL_CONST) pCanSMNetworkConfig;
    /* Network Id */
    NetworkHandleType NetworkId;
    /* Controller configuration status */
    boolean TrcvCfgStatus = FALSE;

    /* Check if requsted Controller Id is configured */
    for (NetworkId = 0; NetworkId < CANSM_NUM_OF_NETWORKS; NetworkId++)
    {
        /* Get Network Configuration */
        pCanSMNetworkConfig = &CanSM_NetworkConfig[NetworkId];
        if (TransceiverId == pCanSMNetworkConfig -> TransceiverId)
        {
            /* Copy Network Id */
            *Network = NetworkId;
            /* Set True as Ctrl Configuration Status */
            TrcvCfgStatus = TRUE;
        }
    }
    return TrcvCfgStatus;
}
#endif
/********************************************************************************************************************
*   @brief      This method to get Updated Com Mode 
*   @param[in]  ControllerMode  Controller mode
*   @return     ComM_ModeType Returns the ComM mode
********************************************************************************************************************/
CANSM_LOCAL FUNC(ComM_ModeType,CANSM_CODE) CanSM_GetUpdatedMode(Can_ControllerStateType ControllerMode)
{
    /* Local Variables */
    ComM_ModeType NewComMode = COMM_NO_COMMUNICATION;

    /* check if ctrl mode is equal to started */
    if (CAN_CS_STARTED == ControllerMode)
    {
        /* Update current mode to Full Communication */
        NewComMode = COMM_FULL_COMMUNICATION;
    }
    /* check if ctrl mode is equal to Stopped */
    else if (CAN_CS_STOPPED == ControllerMode)
    {
        /* Update current mode to No Communication */
        NewComMode = COMM_NO_COMMUNICATION;
    }
    /* check if ctrl mode is equal to Sleep */
    else if (CAN_CS_SLEEP == ControllerMode)
    {
        /* Update current mode to Silent Communication */
        NewComMode = COMM_SILENT_COMMUNICATION;
    }
    else
    {
        /* Do Nothing */
    }
    /* return New Mode */
    return NewComMode;
}

/********************************************************************************************************************
*   @brief      This method process the CanSM state machine
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_Statemachine(NetworkHandleType Network)
{
    uint8 CanSM_OldState;
    uint8 CtrlId;
    #if (CANSM_TRCV_HANDLING == STD_ON)
    uint8 TrcvId;
    #endif
    uint8 RetVal = E_NOT_OK;

    /* Check added to resolve coverity Out of bound Warning */
    if (CANSM_NUM_OF_NETWORKS > Network)
    {
        do
        {
            /* Get the requested state */
            CanSM_OldState = CanSM_NetworkInfo[Network].CurrentState;
            /* Get Ctrl Id */
            CtrlId = CanSM_NetworkConfig[Network].ControllerId;
            #if (CANSM_TRCV_HANDLING == STD_ON)
            TrcvId = CanSM_NetworkConfig[Network].TransceiverId;
            #endif
            /* Initialize Mode Request ModeReqRepetitionTimer */
            CanSM_NetworkInfo[Network].ModeReqRepetitionTimer = CANSM_MODE_REQUEST_REPETITION_MAX;
            /* Process requested state */
            switch(CanSM_NetworkInfo[Network].CurrentState)
            {
                #if (CANSM_TRCV_HANDLING == STD_ON)
                case CANSM_SU_TRCV_NORMAL:
                    if (CANSM_NO_TRCV_CONFIG != TrcvId)
                    {
                        /* Invoke TRCV set mode API */
                        RetVal = CanIf_SetTrcvMode(TrcvId, CANTRCV_TRCVMODE_NORMAL);
                    }
                    else
                    {
                        /* TRCV not configured for this channel, Update Controller state */
                        CanSM_NetworkInfo[Network].CurrentState = CANSM_SU_CC_STOPPED;
                    }
                break;
                #endif
                case CANSM_SU_CC_STARTED:
                    /* Invoke API to stop controller Mode */
                    RetVal = CanIf_SetControllerMode(CtrlId, CAN_CS_STARTED);
                break;
                case CANSM_SU_CC_STOPPED:
                case CANSM_SD_CC_STOPPED:
                    /* Invoke API to start controller Mode */
                    RetVal = CanIf_SetControllerMode(CtrlId, CAN_CS_STOPPED);
                break;
                case CANSM_SD_CC_SLEEP:
                    /* Invoke API to start controller Mode */
                    RetVal = CanIf_SetControllerMode(CtrlId, CAN_CS_SLEEP);
                break;
                #if (CANSM_TRCV_HANDLING == STD_ON)
                case CANSM_SD_TRCV_NORMAL:
                    /* Invoke TRCV set mode API */
                    RetVal = CanIf_SetTrcvMode(TrcvId, CANTRCV_TRCVMODE_NORMAL);
                break;
                case CANSM_SD_TRCV_STANDBY:
                    /* Invoke TRCV set mode API */
                    RetVal = CanIf_SetTrcvMode(TrcvId, CANTRCV_TRCVMODE_STANDBY);
                break;
                #endif
                default:
                break;
            }
            /* Check Whether RetVal is E_OK */
            if (E_OK != RetVal)
            {
                /* Reset ModeReqRepetitionTimer */
                CanSM_NetworkInfo[Network].ModeReqRepetitionTimer = CANSM_RESET_TIMER;
                /* Increment ModeReqRepetitionCounter */
                if(CANSM_MODE_REQUEST_REPETITION_MAX >= CanSM_NetworkInfo[Network].ModeReqRepetitionCounter) /*Cert-c Fix*/
                {
                    /* If CANSM_MODE_REQUEST_REPETITION_MAX is 255, NM_COM will not be set on reaching MAX value */
                    CanSM_NetworkInfo[Network].ModeReqRepetitionCounter++;
                }
            }
        }while(CanSM_OldState != (CanSM_NetworkInfo[Network].CurrentState));
    }
}
/********************************************************************************************************************
*   @brief      This method process the ComM Mode request
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_ProcessComModeRequest(NetworkHandleType Network)
{
    /* Check added to resolve coverity Out of bound Warning */
    if (CANSM_NUM_OF_NETWORKS > Network)
    {
        if ((COMM_FULL_COMMUNICATION == (CanSM_NetworkInfo[Network].RequestedComMode)) &&
            (CANSM_S_SILENTCOM < CanSM_NetworkInfo[Network].CurrentState))
        {
            CanSM_NetworkInfo[Network].ModeReqRepetitionTimer = CANSM_RESET_TIMER;
            #if (CANSM_TRCV_HANDLING == STD_ON)
            /* Update required state as CANSM_SU_TRCV_NORMAL */
            CanSM_NetworkInfo[Network].CurrentState = CANSM_SU_TRCV_NORMAL;
            #else
            /* Update required state as CANSM_SU_CC_STOPPED */
            CanSM_NetworkInfo[Network].CurrentState = CANSM_SU_CC_STOPPED;
            #endif
        }
        else if ((COMM_NO_COMMUNICATION == (CanSM_NetworkInfo[Network].RequestedComMode)) &&
                 (CANSM_S_SILENTCOM >= CanSM_NetworkInfo[Network].CurrentState))
        {
            CanSM_InitiateShutdownProcess(Network);
        }
        else
        {
            /* Do Nothing */
        }
    }
}
/********************************************************************************************************************
*   @brief      This method intiate and processs the Shutdown 
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_InitiateShutdownProcess(NetworkHandleType Network)
{
    /* Check added to resolve coverity Out of bound Warning */
    if (CANSM_NUM_OF_NETWORKS > Network)
    {
        /* Update required state as CANSM_SD_CC_STOPPED */
        CanSM_NetworkInfo[Network].CurrentState = CANSM_SD_CC_STOPPED;
        /* Reset ModeReqRepetitionTimer */
        CanSM_NetworkInfo[Network].ModeReqRepetitionTimer = CANSM_RESET_TIMER;
    }
}
/********************************************************************************************************************
*   @brief      This method is used to evaluvate the max mode request 
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_EvaluateMaxModeReq(NetworkHandleType Network)
{
    /* Check added to resolve coverity Out of bound Warning */
    if (CANSM_NUM_OF_NETWORKS > Network)
    {
        /* check whether ModeReqRepetitionCounter is overflow */
        if (CanSM_NetworkInfo[Network].ModeReqRepetitionCounter > CANSM_MODE_REQUEST_REPETITION_MAX)
        {
            #if (CANSM_DEV_ERROR_DETECT == STD_ON)
            /* Report DET Error TODO Check and update*/
            /* CanSM_Det_ReportError(CANSM_MAINFUNCTION_API, CANSM_E_MODE_REQUEST_TIMEOUT); */
            #endif
            /* Reset ModeReqRepetitionCounter counter */
            CanSM_NetworkInfo[Network].ModeReqRepetitionCounter = 0;
            /* Initiate shutdown process */
            CanSM_InitiateShutdownProcess(Network);
            /* Update requested mode */
            CanSM_NetworkInfo[Network].RequestedComMode = COMM_NO_COMMUNICATION;
        }
    }
}
/********************************************************************************************************************
*   @brief      This method is used to handle the CanSM timer
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_TimerHandling(NetworkHandleType Network)
{
    /* Check added to resolve coverity Out of bound Warning */
    if (CANSM_NUM_OF_NETWORKS > Network)
    {
        /* Check whether timer is expired */
        if (CANSM_RESET_TIMER < CanSM_NetworkInfo[Network].ModeReqRepetitionTimer)
        {
            /* Decrement ModeReqRepetitionTimer */
            CanSM_NetworkInfo[Network].ModeReqRepetitionTimer--;
        }
    }
}
/********************************************************************************************************************
*   @brief      This method is used to check the mode change and indicate to upper layer
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_CheckModeChangeIndication(NetworkHandleType Network)
{
    /* Local Variables */
    ComM_ModeType CurrentMode;
    ComM_ModeType IndicatedMode;

    /* Check added to resolve coverity Out of bound Warning */
    if (CANSM_NUM_OF_NETWORKS > Network)
    {
        /* Get Current Com Mode */
        CurrentMode = CanSM_NetworkInfo[Network].CurrentComMode;
        /* Get last Indicated Com Mode */
        IndicatedMode = CanSM_NetworkInfo[Network].IndicatedComMode;

        /* Check whether current Com Mode is not equal to Indicated Com Mode. */
        if (CurrentMode != IndicatedMode)
        {
            if (COMM_NO_COMMUNICATION == CurrentMode)
            {
                /* Notify state change to BswM */
                BswM_CanSM_CurrentState (Network, CANSM_BSWM_NO_COMMUNICATION);
            }
            else if (COMM_FULL_COMMUNICATION == CurrentMode)
            {
                /* Notify state change to BswM */
                BswM_CanSM_CurrentState (Network, CANSM_BSWM_FULL_COMMUNICATION);
            }
            else if (COMM_SILENT_COMMUNICATION == CurrentMode)
            {
                if (TRUE == CanSM_NetworkInfo[Network].BusOffEventReported)
                {
                    /* Notify state change to BswM */
                    BswM_CanSM_CurrentState (Network, CANSM_BSWM_BUS_OFF);
                }
                else
                {
                    /* Notify state change to BswM */
                    BswM_CanSM_CurrentState (Network, CANSM_BSWM_SILENT_COMMUNICATION);
                }
            }
            else
            {
                /* Do Nothing */
            }
            /* Notify state change to ComM */
            ComM_BusSM_ModeIndication(Network, &CurrentMode);
            /* Update Indicated Mode */
            CanSM_NetworkInfo[Network].IndicatedComMode = CurrentMode;
        }
    }
}
/********************************************************************************************************************
*   @brief      This method is used to handle the Busoff Event
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_ProcessBusoffEvent(NetworkHandleType Network)
{
    #if (CANSM_GET_BUS_OFF_DELAY_FUNCTION == STD_ON)
    CanSM_BusOffIdType BusoffConfigId = 0;
    P2CONST(CanSM_BusOffConfigType,AUTOMATIC,CANSM_APPL_CONST) BusOffConfigPtr;
    uint8 DelayInCyles=0;
    #endif
    /* Check added to resolve coverity Out of bound Warning */
    if (CANSM_NUM_OF_NETWORKS > Network)
    {
        CanSM_NetworkInfo[Network].CurrentComMode = COMM_SILENT_COMMUNICATION;
        #if (CANSM_GET_BUS_OFF_DELAY_FUNCTION == STD_ON)
        /* Get Busoff Configuration Id */
        BusoffConfigId = CanSM_GetBusOffConfigId(Network);
        if (CANSM_NUM_OF_BUS_OFF_CONFIGURATIONS > BusoffConfigId)
        {
            BusOffConfigPtr = &CanSM_BusOffConfig[BusoffConfigId];
            if ((TRUE == BusOffConfigPtr->EnableBusOffDelay) &&
                (NULL_PTR != BusOffConfigPtr->UserGetBusOffDelayFunctPtr))
            {
                BusOffConfigPtr->UserGetBusOffDelayFunctPtr(Network,&DelayInCyles);
                CanSM_UserBusOffDelay[Network]=DelayInCyles;
            }
        }
        #endif
        #if (CANSM_DEM_ERROR_REPORT == STD_ON)
        /* Report DEM Error */
        Dem_ReportErrorStatus(CANSM_E_BUS_OFF, DEM_EVENT_STATUS_PRE_FAILED);
        #endif
    }
}
/********************************************************************************************************************
*   @brief      This method is used to handle the Busoff recovery
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_HandleBusOffRecovery(NetworkHandleType Network)
{
    /* Check added to resolve coverity Out of bound Warning */
    if (CANSM_NUM_OF_NETWORKS > Network)
    {
        /* Handle bus off recovery state machine */
        switch(CanSM_NetworkInfo[Network].BusoffRecoveryState)
        {
            case CANSM_BOR_NO_BUS_OFF:
                CanSM_BusoffRecoveryNoBusOff(Network);
                break;
            case CANSM_BOR_TXOFF_L1:
                CanSM_BusoffRecoveryL1TxOff(Network);
                break;
            case CANSM_BOR_CHECK_L1:
                CanSM_BusoffRecoveryL1Check(Network);
                break;
            case CANSM_BOR_TXOFF_L2:
                CanSM_BusoffRecoveryL2TxOff(Network);
                break;
            case CANSM_BOR_CHECK_L2:
                CanSM_BusoffRecoveryL2Check(Network);
                break;
            default:
                break;
        }
    }
}
/********************************************************************************************************************
*   @brief      This method is used to get the Busoff configuration id
*   @param[in]  Network  network id 
*   @return     CanSM_BusOffIdType  returns the busoff configuration id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(CanSM_BusOffIdType,CANSM_CODE) CanSM_GetBusOffConfigId(NetworkHandleType Network)
{
    /* Local Variables */
    P2CONST(CanSM_NetworkConfigType,AUTOMATIC,CANSM_APPL_CONST) pCanSMNetworkConfig;
    CanSM_BusOffIdType BusoffConfigId = 0;

    /* Check added to resolve coverity Out of bound Warning */
    if (CANSM_NUM_OF_NETWORKS > Network)
    {
        /* Get Network configuration */
        pCanSMNetworkConfig = &CanSM_NetworkConfig[Network];
        /* Get Busoff Configuration Id */
        BusoffConfigId = pCanSMNetworkConfig -> BusOffId;
    }
    return BusoffConfigId;
}
/********************************************************************************************************************
*   @brief      This method is used to validate the Busoff recovery
*   @param[in]  Network  network id 
*   @param[in]  BusoffRecoveryPassCount  busoff recovery pass count 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_ValidateBusoffRecovery
(
    NetworkHandleType Network,
    uint32 BusoffRecoveryPassCount
)
{
    #if (CANSM_GET_BUS_OFF_DELAY_FUNCTION == STD_ON)
    CanSM_BusOffIdType BusoffConfigId = 0;
    P2CONST(CanSM_BusOffConfigType,AUTOMATIC,CANSM_APPL_CONST) BusOffConfigPtr;
    #endif
    /* Check added to resolve coverity Out of bound Warning */
    if (CANSM_NUM_OF_NETWORKS > Network)
    {
        /* Check whether Busoff recovey is achieved */
        if (CanSM_NetworkInfo[Network].NetworkTimer == BusoffRecoveryPassCount)
        {
            /* Update recovery state */
            CanSM_NetworkInfo[Network].BusoffRecoveryState = CANSM_BOR_NO_BUS_OFF;
            /* Initialize L1 to L2 counter */
            CanSM_NetworkInfo[Network].L1ToL2Counter = 0;
            /* Reset Mode Request Repetition Timer */
            CanSM_NetworkInfo[Network].ModeReqRepetitionTimer = CANSM_RESET_TIMER;
            #if (CANSM_TRCV_HANDLING == STD_ON)
            /* Update required state as CANSM_SU_TRCV_NORMAL */
            CanSM_NetworkInfo[Network].CurrentState = CANSM_SU_TRCV_NORMAL;
            #else
            /* Update required state as CANSM_SU_CC_STOPPED */
            CanSM_NetworkInfo[Network].CurrentState = CANSM_SU_CC_STOPPED;
            #endif
            #if (CANSM_GET_BUS_OFF_DELAY_FUNCTION == STD_ON)
            /* Get Busoff Configuration Id */
            BusoffConfigId = CanSM_GetBusOffConfigId(Network);
            if (CANSM_NUM_OF_BUS_OFF_CONFIGURATIONS > BusoffConfigId)
            {
                BusOffConfigPtr = &CanSM_BusOffConfig[BusoffConfigId];
                if ((TRUE == BusOffConfigPtr->EnableBusOffDelay) &&
                    (NULL_PTR != BusOffConfigPtr->UserGetBusOffEndFunctPtr))
                {
                    BusOffConfigPtr->UserGetBusOffEndFunctPtr(Network);
                    CanSM_UserBusOffDelay[Network]=0U;
                }
            }
            #endif
            #if (CANSM_DEM_ERROR_REPORT == STD_ON)
            /* Report DEM Error */
            Dem_ReportErrorStatus(CANSM_E_BUS_OFF, DEM_EVENT_STATUS_PASSED);
            #endif
        }
    }
}
/********************************************************************************************************************
*   @brief      This method is used to handle the Busoff recovery state NoBufoff
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_BusoffRecoveryNoBusOff(NetworkHandleType Network)
{
    /* Local Variables */
    uint8 CtrlId;

    /* Check added to resolve coverity Out of bound Warning */
    if (CANSM_NUM_OF_NETWORKS > Network)
    {
        /* Check whether busoff event is reported */
        if (TRUE == CanSM_NetworkInfo[Network].BusOffEventReported)
        {
            /* Reset Network timer */
            CanSM_NetworkInfo[Network].NetworkTimer = 0;
            /* Get Ctrl Id */
            CtrlId = CanSM_NetworkConfig[Network].ControllerId;
            /* Clear busoff event flag */
            CanSM_NetworkInfo[Network].BusOffEventReported = FALSE;
            /* Update recovery state */
            CanSM_NetworkInfo[Network].BusoffRecoveryState = CANSM_BOR_TXOFF_L1;
            /* Restart Controller */
            (void) CanIf_SetControllerMode(CtrlId, CAN_CS_STARTED);
            /* Set Tx Offline */
            (void) CanIf_SetPduMode(CtrlId, CANIF_TX_OFFLINE);
        }
    }
}
/********************************************************************************************************************
*   @brief      This method is used to handle the Busoff recovery state L1TxOff
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_BusoffRecoveryL1TxOff(NetworkHandleType Network)
{
    /* Local Variables */
    CanSM_BusOffIdType BusoffConfigId = 0;
    uint32 BorL1Time;
    uint8 CtrlId;

   /* Check added to resolve coverity Out of bound Warning */
    if (CANSM_NUM_OF_NETWORKS > Network)
    {
        /* Get Ctrl Id */
        CtrlId = CanSM_NetworkConfig[Network].ControllerId;
        /* Get Busoff Configuration Id */
        BusoffConfigId = CanSM_GetBusOffConfigId(Network);
        /* Check added to resolve coverity Out of bound Warning */
        if (CANSM_NUM_OF_BUS_OFF_CONFIGURATIONS > BusoffConfigId)
        {
            #if (CANSM_GET_BUS_OFF_DELAY_FUNCTION == STD_ON)
            /* Get BorTimeTxEnsured */
            BorL1Time = CanSM_BusOffConfig[BusoffConfigId].BorTimeL1+ CanSM_UserBusOffDelay[Network];
            #else
            BorL1Time = CanSM_BusOffConfig[BusoffConfigId].BorTimeL1;
            #endif
            /* Increment Network Timer */
            if(CANSM_NETWORK_TIMER_MAX > CanSM_NetworkInfo[Network].NetworkTimer) /*Cert-c Fix*/
            {
                CanSM_NetworkInfo[Network].NetworkTimer++;
            }

            /* Check whether L1 time is expired */
            if (CanSM_NetworkInfo[Network].NetworkTimer == BorL1Time)
            {
                /* Reset Network timer */
                CanSM_NetworkInfo[Network].NetworkTimer = 0;
                /* Increment L1 Counter */
                if(CANSM_L1_TO_L2_COUNTER_MAX > CanSM_NetworkInfo[Network].L1ToL2Counter) /*Cert-c Fix*/
                {
                    CanSM_NetworkInfo[Network].L1ToL2Counter++;
                }
                /* Update recovery state */
                CanSM_NetworkInfo[Network].BusoffRecoveryState = CANSM_BOR_CHECK_L1;
                /* Set Tx Online */
                (void) CanIf_SetPduMode(CtrlId, CANIF_ONLINE);
            }
        }
    }
}
/********************************************************************************************************************
*   @brief      This method is used to handle the Busoff recovery state L1Check
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_BusoffRecoveryL1Check(NetworkHandleType Network)
{
    /* Local Variables */
    CanSM_BusOffIdType BusoffConfigId = 0;
    uint32 BusoffRecoveryPassCount;
    uint8 BorL1ToL2Counter;
    uint8 CtrlId;

    /* Check added to resolve coverity Out of bound Warning */
    if (CANSM_NUM_OF_NETWORKS > Network)
    {
        /* Increment Network Timer */
        if(CANSM_NETWORK_TIMER_MAX > CanSM_NetworkInfo[Network].NetworkTimer) /*Cert-c Fix*/
        {
            CanSM_NetworkInfo[Network].NetworkTimer++;
        }

        /* Get Ctrl Id */
        CtrlId = CanSM_NetworkConfig[Network].ControllerId;
        /* Get Busoff Configuration Id */
        BusoffConfigId = CanSM_GetBusOffConfigId(Network);
        /* Check added to resolve coverity Out of bound Warning */
        if (CANSM_NUM_OF_BUS_OFF_CONFIGURATIONS > BusoffConfigId)
        {
            /* Check whether busoff event is reported */
            if (TRUE == CanSM_NetworkInfo[Network].BusOffEventReported)
            {
                /* Reset Network timer */
                CanSM_NetworkInfo[Network].NetworkTimer = 0;
                /* Clear busoff event flag */
                CanSM_NetworkInfo[Network].BusOffEventReported = FALSE;
                /* Get BorL1ToL2Counter */
                BorL1ToL2Counter = CanSM_BusOffConfig[BusoffConfigId].BorCounterL1ToL2;
                /* Check whether L1 to L2 counter reached to upper value */
                if (BorL1ToL2Counter > CanSM_NetworkInfo[Network].L1ToL2Counter)
                {
                    /* Continue Busoff recovery with L1 Counter */
                    CanSM_NetworkInfo[Network].BusoffRecoveryState = CANSM_BOR_TXOFF_L1;
                }
                else
                {
                    /* Switch Bus off recovery to L2 Counter */
                    CanSM_NetworkInfo[Network].BusoffRecoveryState = CANSM_BOR_TXOFF_L2;
                }
                /* Restart Controller */
                (void) CanIf_SetControllerMode(CtrlId, CAN_CS_STARTED);
                /* Set Tx Offline */
                (void) CanIf_SetPduMode(CtrlId, CANIF_TX_OFFLINE);
            }
            else
            {
                /* Get Busoff recovery pass count */
                BusoffRecoveryPassCount = CanSM_BusOffConfig[BusoffConfigId].BorTimeTxEnsured;
                /* Validate Busoff Recovery */
                CanSM_ValidateBusoffRecovery(Network, BusoffRecoveryPassCount);
            }
        }
    }
}
/********************************************************************************************************************
*   @brief      This method is used to handle the Busoff recovery state L2TxOff
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_BusoffRecoveryL2TxOff(NetworkHandleType Network)
{
    /* Local Variables */
    CanSM_BusOffIdType BusoffConfigId = 0;
    uint32 BorL2Time;
    uint8 CtrlId;

    /* Check added to resolve coverity Out of bound Warning */
    if (CANSM_NUM_OF_NETWORKS > Network)
    {
        /* Increment Network Timer */
        if(CANSM_NETWORK_TIMER_MAX > CanSM_NetworkInfo[Network].NetworkTimer) /*Cert-c Fix*/
        {
            CanSM_NetworkInfo[Network].NetworkTimer++;
        }

        /* Get Ctrl Id */
        CtrlId = CanSM_NetworkConfig[Network].ControllerId;
        /* Get Busoff Configuration Id */
        BusoffConfigId = CanSM_GetBusOffConfigId(Network);
        /* Check added to resolve coverity Out of bound Warning */
        if (CANSM_NUM_OF_BUS_OFF_CONFIGURATIONS > BusoffConfigId)
        {
            #if (CANSM_GET_BUS_OFF_DELAY_FUNCTION == STD_ON)
            /* Get BorTimeTxEnsured */
            BorL2Time = CanSM_BusOffConfig[BusoffConfigId].BorTimeL2+ CanSM_UserBusOffDelay[Network];
            #else
            BorL2Time = CanSM_BusOffConfig[BusoffConfigId].BorTimeL2;
            #endif
            /* Check Whether L2 recovery counter is expired */
            if (CanSM_NetworkInfo[Network].NetworkTimer == BorL2Time)
            {
                /* Reset Network timer */
                CanSM_NetworkInfo[Network].NetworkTimer = 0;
                /* Update recovery state */
                CanSM_NetworkInfo[Network].BusoffRecoveryState = CANSM_BOR_CHECK_L2;
                /* Set Tx Online */
                (void) CanIf_SetPduMode(CtrlId, CANIF_ONLINE);
            }
        }
    }
}
/********************************************************************************************************************
*   @brief      This method is used to handle the Busoff recovery state L2Check
*   @param[in]  Network  network id 
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_BusoffRecoveryL2Check(NetworkHandleType Network)
{
    /* Local Variables */
    CanSM_BusOffIdType BusoffConfigId = 0;
    uint32 BusoffRecoveryPassCount;
    uint8 CtrlId;

    /* Check added to resolve coverity Out of bound Warning */
    if (CANSM_NUM_OF_NETWORKS > Network)
    {
        /* Increment Network Timer */
        if(CANSM_NETWORK_TIMER_MAX > CanSM_NetworkInfo[Network].NetworkTimer ) /*Cert-c Fix*/
        {
            CanSM_NetworkInfo[Network].NetworkTimer++;
        }
        /* Get Busoff Configuration Id */
        BusoffConfigId = CanSM_GetBusOffConfigId(Network);
        /* Check added to resolve coverity Out of bound Warning */
        if (CANSM_NUM_OF_BUS_OFF_CONFIGURATIONS > BusoffConfigId)
        {
            /* Check whether busoff event is reported */
            if (TRUE == CanSM_NetworkInfo[Network].BusOffEventReported)
            {
                /* Reset Network timer */
                CanSM_NetworkInfo[Network].NetworkTimer = 0;
                /* Get Ctrl Id */
                CtrlId = CanSM_NetworkConfig[Network].ControllerId;
                /* Clear busoff event flag */
                CanSM_NetworkInfo[Network].BusOffEventReported = FALSE;
                /* Update recovery state */
                CanSM_NetworkInfo[Network].BusoffRecoveryState = CANSM_BOR_TXOFF_L2;
                /* Restart Controller */
                (void) CanIf_SetControllerMode(CtrlId, CAN_CS_STARTED);
                /* Set Tx Offline */
                (void) CanIf_SetPduMode(CtrlId, CANIF_TX_OFFLINE);
                #if (CANSM_DEM_ERROR_REPORT == STD_ON)
                /* Report DEM Error */
                Dem_ReportErrorStatus(CANSM_E_BUS_OFF, DEM_EVENT_STATUS_FAILED);
                #endif
            }
            else
            {    /* Get Busoff recovery pass count */
                BusoffRecoveryPassCount = CanSM_BusOffConfig[BusoffConfigId].BorTimeTxEnsured;
                /* Validate Busoff Recovery */
                CanSM_ValidateBusoffRecovery(Network, BusoffRecoveryPassCount);
            }
        }
    }
}
/********************************************************************************************************************
*   @brief      This method is used to get CanSM channel from the ComM channel
*   @param[in]  nmChannelHandle  ComM channel Id
*   @param[in]  NetworkHandleType returns the CanSM network Id
********************************************************************************************************************/
CANSM_LOCAL FUNC(NetworkHandleType,CANSM_CODE) CanSM_GetChIndexFromComMIndex(NetworkHandleType nmChannelHandle)
{
    /* Local Variables */
    NetworkHandleType Channel = (NetworkHandleType)CANSM_INVALID_CHANNEL;

    if (CANSM_COMM_NUM_OF_NETWORKS > nmChannelHandle)
    {
        Channel = CanSM_ComMToCanSMChannelMapping[nmChannelHandle];
    }
    return Channel;
}
#if (CANSM_DEV_ERROR_DETECT == STD_ON)
/********************************************************************************************************************
*   @brief      This method is used to notify DET module about errors
*   @param[in]  nmChannelHandle  ApiId that caused the Error
*   @param[in]  nmChannelHandle  error id
********************************************************************************************************************/
CANSM_LOCAL FUNC(void,CANSM_CODE) CanSM_Det_ReportError(uint8 ApiId, uint8 ErrorId)
{
    /* Development Error Report */
    (void) Det_ReportError(CANSM_MODULE_ID, CANSM_INSTANCE_ID, ApiId, ErrorId);
}
#endif

#define CANSM_STOP_SEC_CODE
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

