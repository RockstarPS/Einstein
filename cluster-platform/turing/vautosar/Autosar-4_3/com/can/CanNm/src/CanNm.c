/********************************************************************************************************************
|   File Name   : CanNm.c
|
|   Description : This header provides the pre-compile time configurable parameters
|--------------------------------------------------------------------------------------------------------------------
|               C O P Y R I G H T
|--------------------------------------------------------------------------------------------------------------------
| Copyright (c) 2019 by Visteon Corporation.       All rights reserved.
|
| NOTICE: This is an unpublished work of authorship, which contains trade secrets.
| Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
| its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
| or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
| in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
| under all copyright laws to protect this work as a published work, when appropriate.
| Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
| without the written authorization of Visteon Corporation.
|--------------------------------------------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|--------------------------------------------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| EA            Ashok Elavarasu          Visteon Corporation
|--------------------------------------------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|--------------------------------------------------------------------------------------------------------------------
| Date        Version   Author  Description
| ----------  --------  ------  -------------------------------------------------------------------------------------
| 2020-03-18  00.00.01  EA     Initial Version
|*******************************************************************************************************************/
/*******************************************************************************************************************/
/*  Include files                                                                                                  */
/*******************************************************************************************************************/
#include "CanNm.h"
#include "Nm_Cbk.h"
#include "CanNm_Cbk.h"
#include "SchM_CanNm.h"
#include "PduR_CanNm.h"
#include "CanIf.h"

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
/*******************************************************************************************************************/
/*  Version check                                                                                                  */
/*******************************************************************************************************************/
/* Software Version Check */
#if((CANNM_SW_MAJOR_VERSION != CANNM_CFG_SW_MAJOR_VERSION) || \
    (CANNM_SW_MINOR_VERSION != CANNM_CFG_SW_MINOR_VERSION) || \
    (CANNM_SW_PATCH_VERSION != CANNM_CFG_SW_PATCH_VERSION))
#error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if((CANNM_AR_RELEASE_MAJOR_VERSION != CANNM_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (CANNM_AR_RELEASE_MINOR_VERSION != CANNM_CFG_AR_RELEASE_MINOR_VERSION) || \
    (CANNM_AR_RELEASE_REVISION_VERSION != CANNM_CFG_AR_RELEASE_REVISION_VERSION))
#error "Autosar version is inconsistent between source files and Configuration files!"
#endif
/*******************************************************************************************************************/
/*  TypeDef                                                                                                        */
/*******************************************************************************************************************/
/* CanNm module Timers type */
typedef uint16 CanNm_TimerCounterType;
/* Active wake up bit masks */
#if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
#define CANNM_ACT_WU_BIT_MASK                       ((uint8)0x10U)
#define CANNM_ACT_WU_BIT_INV_MASK                   ((uint8)0xEFU)
#endif
/* Repeat Message Bit masks */
#define CANNM_REPEAT_MSG_BIT_MASK                   ((uint8)0x01U)
#define CANNM_REPEAT_MSG_BIT_INV_MASK               ((uint8)0xFEu)
/* TX message communication status */
#define CANNM_MSG_TX_DISABLED                       ((boolean)0)
#define CANNM_MSG_TX_ENABLED                        ((boolean)1)
/* Communication request types */
#define CANNM_NO_RESTART                            ((uint8)0U)
#define CANNM_PASSIVE_RESTART                       ((uint8)1U)
#define CANNM_ACTIVE_RESTART                        ((uint8)2U)
/* The application has no communication need and is ready to sleep */
#define CANNM_COMM_READY_SLEEP                      ((boolean)0)
/* The application needs communication */
#define CANNM_COMM_NORMAL_OPERATION                 ((boolean)1)
/* Asynchronous transmission request types */
#define CANNM_NO_TRANSMIT_REQUEST                   ((boolean)0)
#define CANNM_TRANSMIT_REQUEST                      ((boolean)1)
/* Convert timers to counters */
#define CANNM_MSG_CYCLE_OFFSET(CHANNEL)             \
        ((uint16)(CanNm_ChannelConfig[CHANNEL].MsgCycleOffset/ CANNM_MAIN_FUNCTION_PERIOD))
#define CANNM_MSG_CYCLETIME(CHANNEL)                \
        ((uint16)(CanNm_ChannelConfig[CHANNEL].MsgCycleTime / CANNM_MAIN_FUNCTION_PERIOD))
#define CANNM_TIMEOUTTIME(CHANNEL)                  \
        ((uint16)(CanNm_ChannelConfig[CHANNEL].TimeoutTime / CANNM_MAIN_FUNCTION_PERIOD))
#define CANNM_WAITBUS_SLEEPTIME(CHANNEL)            \
        ((uint16)(CanNm_ChannelConfig[CHANNEL].WaitBusSleepTime / CANNM_MAIN_FUNCTION_PERIOD))
#define CANNM_REPEAT_MSGTIME(CHANNEL)               \
        ((uint16)(CanNm_ChannelConfig[CHANNEL].RepeatMessageTime / CANNM_MAIN_FUNCTION_PERIOD))
#define CANNM_MSG_TIMEOUTTIME(CHANNEL)              \
        ((uint16)(CanNm_ChannelConfig[CHANNEL].MsgTimeoutTime / CANNM_MAIN_FUNCTION_PERIOD))
#define CANNM_IMMEDIATE_NM_CYCLETIME(CHANNEL)       \
        ((uint16)(CanNm_ChannelConfig[CHANNEL].ImmediateNmCycleTime / CANNM_MAIN_FUNCTION_PERIOD))
#define CANNM_MSG_REDUCEDTIME(CHANNEL)              \
        ((uint16)(CanNm_ChannelConfig[CHANNEL].MsgReducedTime / CANNM_MAIN_FUNCTION_PERIOD))
#define CANNM_REMOTE_SLEEP_INDICATIONTIME(CHANNEL)  \
        ((uint16)(CanNm_ChannelConfig[CHANNEL].RemoteSleepIndTime / CANNM_MAIN_FUNCTION_PERIOD))
/*******************************************************************************************************************/
/*  Static Functions                                                                                               */
/*******************************************************************************************************************/
/* Local Function to intialize CanNm global variables */
static void CanNm_LocalInit(const NetworkHandleType Channel);
/* Local Main function based on Channel index */
static void CanNm_LocalMainFunction(const NetworkHandleType Channel);
/* Local Function to handle CanNm state transitions */
static void CanNm_StateTransition(const NetworkHandleType Channel,const Nm_StateType NextNmState);
/* Local Function to process received NM message */
static void CanNm_RxMsgProcessing(const NetworkHandleType Channel);
/* Local Function to process communication control state */
static void CanNm_ComControlProcessing(const NetworkHandleType Channel);
/* Local Function to trigger transmission of NM message */
static Std_ReturnType CanNm_TriggerTransmission( const NetworkHandleType Channel);
#if ( CANNM_CAR_WAKEUP_RX_ENABLED == STD_ON )
static void CanNm_CarWakeupIndication(const NetworkHandleType Channel, const PduInfoType *PduInfoPtr);
#endif
/* Local Function returns the CanNm Channel index from Tx PDU ID */
static NetworkHandleType CanNm_GetChIndexFromTxPduId(PduIdType TxPduId);
/* Local Function returns the CanNm Channel index from received PDU ID */
static NetworkHandleType CanNm_GetChIndexFromRxPduId(PduIdType RxPduId);
/* Local Function returns the CanNm Channel index from NM module index */
static NetworkHandleType CanNm_GetChIndexFromNmIndex(NetworkHandleType nmChannelHandle);
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
/* Local Function to report DET error */
static void CanNm_Det_ReportError(uint8 ApiId, uint8 ErrorId);
#endif
/*******************************************************************************************************************/
/*  Declarations                                                                                                   */
/*******************************************************************************************************************/
/* CanNm Module Init Status */
static boolean CanNm_InitStatus = FALSE;
/* Internal communication status */
static boolean CanNm_CommState[CANNM_NUM_OF_CHANNELS];
/* Network restart flag */
static uint8 CanNm_NetworkRestartFlag[CANNM_NUM_OF_CHANNELS];
/* CanNm RX message indication status */
static boolean CanNm_MsgIndicationFlag[CANNM_NUM_OF_CHANNELS];
/* Timeout timer counter */
static CanNm_TimerCounterType CanNm_TimeoutTimer[CANNM_NUM_OF_CHANNELS];
/* wait bus sleep timer counter */
static CanNm_TimerCounterType CanNm_WaitBusSleepTimer[CANNM_NUM_OF_CHANNELS];
/* Repeat message timer counter */
static CanNm_TimerCounterType CanNm_RepeatMsgTimer[CANNM_NUM_OF_CHANNELS];
#if ((CANNM_USER_DATA_ENABLED == STD_ON) || (CANNM_COM_USER_DATA_SUPPORT == STD_ON))
/* User data start position */
static uint8 CanNm_UserDataPosition[CANNM_NUM_OF_CHANNELS];
#endif
/* CanNm RX message data buffer */
static uint8 CanNm_RxMessageData[CANNM_NUM_OF_CHANNELS][CANNM_MAX_PDU_LENGTH];
/* CanNm module current network management state */
static Nm_StateType CanNm_NmState[CANNM_NUM_OF_CHANNELS];
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_IMMEDIATE_RESTART_ENABLED == STD_OFF))
/* Immediate NM message transmit count */
static uint8 CanNm_ImmediateNmMsgCount[CANNM_NUM_OF_CHANNELS];
#endif
#if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
/* Transmit message confirmation Status */
static boolean CanNm_MsgConfirmationFlag[CANNM_NUM_OF_CHANNELS];
/* Transmit message timer */
static CanNm_TimerCounterType CanNm_MsgTimer[CANNM_NUM_OF_CHANNELS];
/* CanNm TX message data buffer */
static uint8 CanNm_TxMessageData[CANNM_NUM_OF_CHANNELS][CANNM_MAX_PDU_LENGTH];
#endif
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_NODE_DETECTION_ENABLED == STD_ON))
/* Repeat message request indication flag */
static boolean CanNm_RepeatMsgBitIndFlag[CANNM_NUM_OF_CHANNELS];
/* Repeat message request Status */
static boolean CanNm_RepeatMsgReqFlag[CANNM_NUM_OF_CHANNELS];
# endif
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON))
/* Remote sleep indication timer counter */
static CanNm_TimerCounterType CanNm_RemoteSleepTimer[CANNM_NUM_OF_CHANNELS];
/* Remote sleep indication Status */
static boolean CanNm_RemoteSleepIndState[CANNM_NUM_OF_CHANNELS];
#endif
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_IMMEDIATE_TX_CONF_ENABLED == STD_OFF))
/* CanNm TX message timeout counter */
static CanNm_TimerCounterType CanNm_MsgTimeoutTimer[CANNM_NUM_OF_CHANNELS];
#endif
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_COM_USER_DATA_SUPPORT == STD_ON))
/* NM Message trasmit request from upper layer (COM) */
static boolean CanNm_MsgRequest[CANNM_NUM_OF_CHANNELS];
#endif
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_COM_CONTROL_ENABLED == STD_ON))
/* Current CanNm TX message communication status */
static boolean CanNm_TxControlState[CANNM_NUM_OF_CHANNELS];
/* Requested CanNm TX message communication status */
static boolean CanNm_TxControlStateRequest[CANNM_NUM_OF_CHANNELS];
#endif
/*****************************************************************************************************************
** Service Name     : CanNm_InitMemory
** Service ID       : None
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : None
** Parameters [out] : None
** Return value     : None
** Description      : This service initializes the global variables
*****************************************************************************************************************/
void CanNm_InitMemory(void)
{
    /* Local Variables */
    NetworkHandleType ChIndex = CANNM_INVALID_CHANNEL;

    /* Set CanNm module network management state to UNINIT */
    for (ChIndex=0U; ChIndex<CANNM_NUM_OF_CHANNELS; ChIndex++)
    {
        CanNm_NmState[ChIndex] = NM_STATE_UNINIT;
    }
    CanNm_InitStatus = FALSE;
}
/*****************************************************************************************************************
** Service Name     : CanNm_Init
** Service ID       : 0x00
** Sync/Async       : Synchronous
** Reentrancy       : Non Reentrant
** Parameters [in]  : cannmConfigPtr
** Parameters [out] : None
** Return value     : None
** Description      : This service initializes the CanNm module
*****************************************************************************************************************/
void CanNm_Init(const CanNm_ConfigType * const CannmConfigPtr)
{
    /* Local Variables */
    NetworkHandleType ChIndex = CANNM_INVALID_CHANNEL;

    /* CannmConfigPtr not used */
    CANNM_UNUSED_PARAM(CannmConfigPtr);
    for (ChIndex=0U; ChIndex<CANNM_NUM_OF_CHANNELS; ChIndex++)
    {
        CanNm_LocalInit(ChIndex);
    }
    /* Update CanNm Module Init Status */
    CanNm_InitStatus = TRUE;
}
/*****************************************************************************************************************
** Service Name     : CanNm_PassiveStartUp
** Service ID       : 0x01
** Sync/Async       : Asynchronous
** Reentrancy       : Reentrant (but not for the same NM-Channel)
** Parameters [in]  : nmChannelHandle
** Parameters [out] : None
** Return value     : Std_ReturnType
** Description      : Passive startup of the AUTOSAR CAN NM
*****************************************************************************************************************/
Std_ReturnType CanNm_PassiveStartUp(NetworkHandleType nmChannelHandle)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANNM_E_NO_ERROR;
    /* Get CanNm Channel index */
    NetworkHandleType Channel = CanNm_GetChIndexFromNmIndex(nmChannelHandle);

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If module is Initialized */
    if (TRUE != CanNm_InitStatus)
    {
        ErrorId = CANNM_E_NO_INIT;
    }
    /* Check If requested Network is valid */
    else if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    else
#endif
    {
        /* restart possible in Prepare Bus Sleep Mode and Bus sleep mode only */
        if ((NM_STATE_BUS_SLEEP == CanNm_NmState[Channel]) || (NM_STATE_PREPARE_BUS_SLEEP == CanNm_NmState[Channel]))
        {
            if (CANNM_NO_RESTART == CanNm_NetworkRestartFlag[Channel])
            {
                CanNm_NetworkRestartFlag[Channel] = CANNM_PASSIVE_RESTART;
            }
            RetVal = E_OK;
        }
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_PASSIVESTARTUP_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
/*****************************************************************************************************************
** Service Name     : CanNm_NetworkRequest
** Service ID       : 0x02
** Sync/Async       : Asynchronous
** Reentrancy       : Reentrant (but not for the same NM-Channel)
** Parameters [in]  : nmChannelHandle
** Parameters [out] : None
** Return value     : Std_ReturnType
** Description      : Requests the network
*****************************************************************************************************************/
Std_ReturnType CanNm_NetworkRequest(NetworkHandleType nmChannelHandle)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANNM_E_NO_ERROR;
    /* Get CanNm Channel index */
    NetworkHandleType Channel = CanNm_GetChIndexFromNmIndex(nmChannelHandle);

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If module is Initialized */
    if (TRUE != CanNm_InitStatus)
    {
        ErrorId = CANNM_E_NO_INIT;
    }
    /* Check If requested Network is valid */
    else if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    else
#endif
    {
        /* SWS_CanNm_00104 - Request network */
        CanNm_CommState[Channel] = CANNM_COMM_NORMAL_OPERATION;
        /* Ensure Start-Up */
        if ((CANNM_NO_RESTART == CanNm_NetworkRestartFlag[Channel]) && (NM_STATE_READY_SLEEP > CanNm_NmState[Channel]))
        {
                CanNm_NetworkRestartFlag[Channel] = CANNM_ACTIVE_RESTART;
        }
        RetVal = E_OK;
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_NETWORKREQUEST_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
/*****************************************************************************************************************
** Service Name     : CanNm_NetworkRelease
** Service ID       : 0x03
** Sync/Async       : Asynchronous
** Reentrancy       : Reentrant (but not for the same NM-Channel)
** Parameters [in]  : nmChannelHandle
** Parameters [out] : None
** Return value     : Std_ReturnType
** Description      : Releases the network
*****************************************************************************************************************/
Std_ReturnType CanNm_NetworkRelease(NetworkHandleType nmChannelHandle)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANNM_E_NO_ERROR;
    /* Get CanNm Channel index */
    NetworkHandleType Channel = CanNm_GetChIndexFromNmIndex(nmChannelHandle);

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If module is Initialized */
    if (TRUE != CanNm_InitStatus)
    {
        ErrorId = CANNM_E_NO_INIT;
    }
    /* Check If requested Network is valid */
    else if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    else
#endif
    {
        /* Release network */
        CanNm_CommState[Channel] = CANNM_COMM_READY_SLEEP;
        RetVal = E_OK;
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_NETWORKRELEASE_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#endif
/*****************************************************************************************************************
** Service Name     : CanNm_GetState
** Service ID       : 0x0b
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmChannelHandle
** Parameters [out] : nmStatePtr, nmModePtr
** Return value     : Std_ReturnType
** Description      : Returns the state and the mode of the network management
*****************************************************************************************************************/
Std_ReturnType CanNm_GetState(NetworkHandleType nmChannelHandle, Nm_StateType* nmStatePtr,
                                     Nm_ModeType* nmModePtr)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANNM_E_NO_ERROR;
    /* Get CanNm Channel index */
    NetworkHandleType Channel = CanNm_GetChIndexFromNmIndex(nmChannelHandle);

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If module is Initialized */
    if (TRUE != CanNm_InitStatus)
    {
        ErrorId = CANNM_E_NO_INIT;
    }
    /* Check If requested Network is valid */
    else if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    /* Check If state and mode pointer is valid */
    else if ((NULL_PTR == nmStatePtr) || (NULL_PTR == nmModePtr))
    {
        ErrorId = CANNM_E_PARAM_POINTER;
    }
    else
#endif
    {
        /* Set state */
        *nmStatePtr = CanNm_NmState[Channel];
        /* Set mode respective to the state */
        if (NM_STATE_BUS_SLEEP == CanNm_NmState[Channel])
        {
            *nmModePtr = NM_MODE_BUS_SLEEP;
        }
        else if (NM_STATE_PREPARE_BUS_SLEEP == CanNm_NmState[Channel])
        {
            *nmModePtr = NM_MODE_PREPARE_BUS_SLEEP;
        }
        else
        {
            /* Ready Sleep, Normal Operation, Repeat Message */
            *nmModePtr = NM_MODE_NETWORK;
        }
        RetVal = E_OK;
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_GETSTATE_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#if (CANNM_USER_DATA_ENABLED == STD_ON)
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_COM_USER_DATA_SUPPORT == STD_OFF))
/*****************************************************************************************************************
** Service Name     : CanNm_SetUserData
** Service ID       : 0x04
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant (but not for the same NM-Channel)
** Parameters [in]  : nmChannelHandle, nmUserDataPtr
** Parameters [out] : None
** Return value     : Std_ReturnType
** Description      : Sets user data for NM PDUs transmitted next on the bus
*****************************************************************************************************************/
Std_ReturnType CanNm_SetUserData(NetworkHandleType nmChannelHandle, const uint8* nmUserDataPtr)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANNM_E_NO_ERROR;
    PduLengthType ByteIndex = 0xFFU;
    /* Get CanNm Channel index */
    NetworkHandleType Channel = CanNm_GetChIndexFromNmIndex(nmChannelHandle);

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If module is Initialized */
    if (TRUE != CanNm_InitStatus)
    {
        ErrorId = CANNM_E_NO_INIT;
    }
    /* Check If requested Network is valid */
    else if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    /* Check If data pointer is valid */
    else if (NULL_PTR == nmUserDataPtr)
    {
        ErrorId = CANNM_E_PARAM_POINTER;
    }
    else
#endif
    {
        /*  Write user data into Tx Message Data buffer. Content is transmitted in the next Nm message */
        CanNm_EnterCriticalSection();
        for (ByteIndex=CanNm_UserDataPosition[Channel];
             ByteIndex<CanNM_ChannelPduConfig[Channel].CanNmTransmitMsgLength; ByteIndex++)
        {
            CanNm_TxMessageData[Channel][ByteIndex] = nmUserDataPtr[ByteIndex-CanNm_UserDataPosition[Channel]];
        }
        CanNm_ExitCriticalSection();
        RetVal = E_OK;
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_SETUSERDATA_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#endif
/*****************************************************************************************************************
** Service Name     : CanNm_GetUserData
** Service ID       : 0x04
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmChannelHandle
** Parameters [out] : nmUserDataPtr
** Return value     : Std_ReturnType
** Description      : Gets user data out of the most recently received NM PDU
*****************************************************************************************************************/
Std_ReturnType CanNm_GetUserData(NetworkHandleType nmChannelHandle, uint8* const nmUserDataPtr)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANNM_E_NO_ERROR;
    uint32 UserDataPosition = 0xFFU;
    PduLengthType ByteIndex = 0xFFU;
    /* Get CanNm Channel index */
    NetworkHandleType Channel = CanNm_GetChIndexFromNmIndex(nmChannelHandle);

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If module is Initialized */
    if (TRUE != CanNm_InitStatus)
    {
        ErrorId = CANNM_E_NO_INIT;
    }
    /* Check If requested Network is valid */
    else if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    /* Check If data pointer is valid */
    else if (NULL_PTR == nmUserDataPtr)
    {
        ErrorId = CANNM_E_PARAM_POINTER;
    }
    else
#endif
    {
        /*  Return user data from last received Nm message */
        if(CanNm_UserDataPosition[Channel] >= CanNM_ChannelPduConfig[Channel].CanNmReceiveMsgLength)
        {
            ErrorId = CANNM_E_INIT_FAILED;
        }
        else
        {
            CanNm_EnterCriticalSection();
            for (ByteIndex=0U; ByteIndex<CanNm_ChannelConfig[Channel].UserDataLength; ByteIndex++)
            {
                UserDataPosition = ByteIndex+CanNm_UserDataPosition[Channel];
                if(CANNM_MAX_PDU_LENGTH > UserDataPosition)
                {
                    nmUserDataPtr[ByteIndex] = CanNm_RxMessageData[Channel][UserDataPosition];
                }
            }
            CanNm_ExitCriticalSection();
            RetVal = E_OK;
        }
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_GETUSERDATA_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#endif
#if (CANNM_NODE_ID_ENABLED == STD_ON)
/*****************************************************************************************************************
** Service Name     : CanNm_GetNodeIdentifier
** Service ID       : 0x06
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmChannelHandle
** Parameters [out] : nmNodeIdPtr
** Return value     : Std_ReturnType
** Description      : Gets node identifier out of the most recently received NM PDU
*****************************************************************************************************************/
Std_ReturnType CanNm_GetNodeIdentifier(NetworkHandleType nmChannelHandle, uint8* nmNodeIdPtr)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANNM_E_NO_ERROR;
    /* Get CanNm Channel index */
    NetworkHandleType Channel = CanNm_GetChIndexFromNmIndex(nmChannelHandle);

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If module is Initialized */
    if (TRUE != CanNm_InitStatus)
    {
        ErrorId = CANNM_E_NO_INIT;
    }
    /* Check If requested Network is valid */
    else if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    /* Check If data pointer is valid */
    else if (NULL_PTR == nmNodeIdPtr)
    {
        ErrorId = CANNM_E_PARAM_POINTER;
    }
    else
#endif
    {
        /* Check for PDU Position set to STD_OFF */
        if ((CANNM_PDU_OFF != CanNm_ChannelConfig[Channel].PduNidPosition) &&
            (CanNM_ChannelPduConfig[Channel].CanNmReceiveMsgLength > CanNm_ChannelConfig[Channel].PduNidPosition))
        {
            /* Return the current Node Identifier from the last received NM message */
            *nmNodeIdPtr = CanNm_RxMessageData[Channel][CanNm_ChannelConfig[Channel].PduNidPosition];
            RetVal = E_OK;
        }
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_GETNODEIDENTIFIER_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
/*****************************************************************************************************************
** Service Name     : CanNm_GetLocalNodeIdentifier
** Service ID       : 0x07
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmChannelHandle
** Parameters [out] : nmNodeIdPtr
** Return value     : Std_ReturnType
** Description      : Gets node identifier configured for the local node
*****************************************************************************************************************/
Std_ReturnType CanNm_GetLocalNodeIdentifier(NetworkHandleType nmChannelHandle, uint8* nmNodeIdPtr)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANNM_E_NO_ERROR;
    /* Get CanNm Channel index */
    NetworkHandleType Channel = CanNm_GetChIndexFromNmIndex(nmChannelHandle);

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If module is Initialized */
    if (TRUE != CanNm_InitStatus)
    {
        ErrorId = CANNM_E_NO_INIT;
    }
    /* Check If requested Network is valid */
    else if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    /* Check If data pointer is valid */
    else if (NULL_PTR == nmNodeIdPtr)
    {
        ErrorId = CANNM_E_PARAM_POINTER;
    }
    else
#endif
    {
        /* Return Node ID from configuration */
        *nmNodeIdPtr = CanNm_ChannelConfig[Channel].NodeId;
        RetVal = E_OK;
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_GETLOCALNODEIDENTIFIER_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#endif
#if (CANNM_NODE_DETECTION_ENABLED == STD_ON)
/*****************************************************************************************************************
** Service Name     : CanNm_RepeatMessageRequest
** Service ID       : 0x08
** Sync/Async       : Asynchronous
** Reentrancy       : Reentrant (but not for the same NM-Channel)
** Parameters [in]  : nmChannelHandle
** Parameters [out] : None
** Return value     : Std_ReturnType
** Description      : Sets Repeat Message Request Bit for NM PDUs transmitted next on the bus
*****************************************************************************************************************/
Std_ReturnType CanNm_RepeatMessageRequest(NetworkHandleType nmChannelHandle)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANNM_E_NO_ERROR;
    /* Get CanNm Channel index */
    NetworkHandleType Channel = CanNm_GetChIndexFromNmIndex(nmChannelHandle);

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If module is Initialized */
    if (TRUE != CanNm_InitStatus)
    {
        ErrorId = CANNM_E_NO_INIT;
    }
    /* Check If requested Network is valid */
    else if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    else
#endif
    {
        /* SWS_CanNm_00137 - Repeat Message Request only in Ready Sleep and Normal Operation */
        if ((NM_STATE_READY_SLEEP == CanNm_NmState[Channel]) ||
            (NM_STATE_NORMAL_OPERATION == CanNm_NmState[Channel]))
        {
            /* SWS_CanNm_00120, SWS_CanNm_00112 - Request Transition to Repeat Message State */
            CanNm_RepeatMsgReqFlag[Channel] = TRUE;
            RetVal = E_OK;
        }
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_REPEATMESSAGEREQUEST_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#endif
#if ((CANNM_NODE_DETECTION_ENABLED == STD_ON) || (CANNM_USER_DATA_ENABLED == STD_ON) || \
     (CANNM_NODE_ID_ENABLED == STD_ON))
/*****************************************************************************************************************
** Service Name     : CanNm_GetPduData
** Service ID       : 0x0a
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmChannelHandle
** Parameters [out] : nmPduDataPtr
** Return value     : Std_ReturnType
** Description      : Gets the whole PDU data out of the most recently received NM PDU
*****************************************************************************************************************/
Std_ReturnType CanNm_GetPduData(NetworkHandleType nmChannelHandle, uint8* nmPduDataPtr)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANNM_E_NO_ERROR;
    PduLengthType ByteIndex = 0xFFU;
    /* Get CanNm Channel index */
    NetworkHandleType Channel = CanNm_GetChIndexFromNmIndex(nmChannelHandle);

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If module is Initialized */
    if (TRUE != CanNm_InitStatus)
    {
        ErrorId = CANNM_E_NO_INIT;
    }
    /* Check If requested Network is valid */
    else if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    /* Check If data pointer is valid */
    else if (NULL_PTR == nmPduDataPtr)
    {
        ErrorId = CANNM_E_PARAM_POINTER;
    }
    else
#endif
    {
        /*  Return user data from last received Nm message */
        CanNm_EnterCriticalSection();
        /* Copy Data from Buffer */
        for (ByteIndex=0U; ByteIndex<CanNM_ChannelPduConfig[Channel].CanNmReceiveMsgLength; ByteIndex++)
        {
            nmPduDataPtr[ByteIndex] = CanNm_RxMessageData[Channel][ByteIndex];
        }
        CanNm_ExitCriticalSection();
        RetVal = E_OK;
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_GETPDUDATA_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#endif
#if (CANNM_BUS_SYNCHRONIZATION_ENABLED == STD_ON)
/*****************************************************************************************************************
** Service Name     : CanNm_RequestBusSynchronization
** Service ID       : 0xc0
** Sync/Async       : Synchronous
** Reentrancy       : Non Reentrant
** Parameters [in]  : nmChannelHandle
** Parameters [out] : None
** Return value     : Std_ReturnType
** Description      : Requests bus synchronization
*****************************************************************************************************************/
Std_ReturnType CanNm_RequestBusSynchronization(NetworkHandleType nmChannelHandle)
{
    CANNM_UNUSED_PARAM(nmChannelHandle);
}
#endif
#if (CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
/*****************************************************************************************************************
** Service Name     : CanNm_CheckRemoteSleepIndication
** Service ID       : 0xd0
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmChannelHandle
** Parameters [out] : nmRemoteSleepIndPtr
** Return value     : Std_ReturnType
** Description      : Checks if remote sleep indication takes place or not
*****************************************************************************************************************/
Std_ReturnType CanNm_CheckRemoteSleepIndication(NetworkHandleType nmChannelHandle, boolean* nmRemoteSleepIndPtr)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANNM_E_NO_ERROR;
    /* Get CanNm Channel index */
    NetworkHandleType Channel = CanNm_GetChIndexFromNmIndex(nmChannelHandle);

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If module is Initialized */
    if (TRUE != CanNm_InitStatus)
    {
        ErrorId = CANNM_E_NO_INIT;
    }
    /* Check If requested Network is valid */
    else if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    /* Check If data pointer is valid */
    else if (NULL_PTR == nmRemoteSleepIndPtr)
    {
        ErrorId = CANNM_E_PARAM_POINTER;
    }
    else
#endif
    {
        /* SWS_CanNm_00154 - Check Remote Sleep Indication may only be requested in Ready Sleep and Normal state */
        if ((NM_STATE_READY_SLEEP == CanNm_NmState[Channel]) ||
            (NM_STATE_NORMAL_OPERATION == CanNm_NmState[Channel]))
        {
            /* Provide information about current status of remote sleep indication */
            *nmRemoteSleepIndPtr = (boolean)CanNm_RemoteSleepIndState[Channel];
            RetVal = E_OK;
        }
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_CHECKREMOTESLEEPIND_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#endif
#if (CANNM_VERSION_INFO_API == STD_ON)
/*****************************************************************************************************************
** Service Name     : CanNm_GetVersionInfo
** Service ID       : 0xf1
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : None
** Parameters [out] : versioninfo
** Return value     : None
** Description      : This service returns the version information of this module
*****************************************************************************************************************/
void CanNm_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
    /* Local Variables */
    uint8 ErrorId = CANNM_E_NO_ERROR;

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If data pointer is valid */
    if (NULL_PTR == versioninfo)
    {
        ErrorId = CANNM_E_PARAM_POINTER;
    }
    else
#endif
    {
        /* Return vendor ID, module ID and version data */
        versioninfo->vendorID = CANNM_VENDOR_ID;
        versioninfo->moduleID = CANNM_MODULE_ID;
        versioninfo->sw_major_version = CANNM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = CANNM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = CANNM_SW_PATCH_VERSION;
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_GETVERSIONINFO_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
}
#endif
#if (CANNM_COM_CONTROL_ENABLED == STD_ON)
/*****************************************************************************************************************
** Service Name     : CanNm_EnableCommunication
** Service ID       : 0x0d
** Sync/Async       : Asynchronous
** Reentrancy       : Reentrant (but not for the same NM-Channel)
** Parameters [in]  : nmChannelHandle
** Parameters [out] : None
** Return value     : Std_ReturnType
** Description      : Enables the NM PDU transmission ability
*****************************************************************************************************************/
Std_ReturnType CanNm_EnableCommunication(NetworkHandleType nmChannelHandle)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANNM_E_NO_ERROR;
    /* Get CanNm Channel index */
    NetworkHandleType Channel = CanNm_GetChIndexFromNmIndex(nmChannelHandle);

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If module is Initialized */
    if (TRUE != CanNm_InitStatus)
    {
        ErrorId = CANNM_E_NO_INIT;
    }
    /* Check If requested Network is valid */
    else if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    else
#endif
    {
#if (CANNM_PASSIVE_MODE_ENABLED == STD_ON) /* SWS_CanNm_00297 */
        RetVal = E_NOT_OK;
#else
        /* SWS_CanNm_00295 - Disable Nm PDU transmission ability in Network Mode */
        if (NM_STATE_PREPARE_BUS_SLEEP < CanNm_NmState[Channel])
        {
            /* SWS_CanNm_00177, SWS_CanNm_00176 - Enable NM PDU transmission ability only if disabled */
            if (CANNM_MSG_TX_DISABLED == CanNm_TxControlState[Channel])
            {
                /* Enable NM PDU transmission ability */
                CanNm_TxControlStateRequest[Channel] = CANNM_MSG_TX_ENABLED;
                RetVal = E_OK;
            }
        }
#endif
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_ENABLECOMMUNICATION_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
/*****************************************************************************************************************
** Service Name     : CanNm_DisableCommunication
** Service ID       : 0x0c
** Sync/Async       : Asynchronous
** Reentrancy       : Reentrant (but not for the same NM-Channel)
** Parameters [in]  : nmChannelHandle
** Parameters [out] : None
** Return value     : Std_ReturnType
** Description      : Disables the NM PDU transmission ability
*****************************************************************************************************************/
Std_ReturnType CanNm_DisableCommunication(NetworkHandleType nmChannelHandle)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANNM_E_NO_ERROR;
    /* Get CanNm Channel index */
    NetworkHandleType Channel = CanNm_GetChIndexFromNmIndex(nmChannelHandle);

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If module is Initialized */
    if (TRUE != CanNm_InitStatus)
    {
        ErrorId = CANNM_E_NO_INIT;
    }
    /* Check If requested Network is valid */
    else if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    else
#endif
    {
#if (CANNM_PASSIVE_MODE_ENABLED == STD_ON) /* SWS_CanNm_00298 */
        RetVal = E_NOT_OK;
#else
        /* SWS_CanNm_00172 - Disable Nm PDU transmission ability in Network Mode */
        if (NM_STATE_PREPARE_BUS_SLEEP < CanNm_NmState[Channel])
        {
            /* Request to disable Tx Message transmission ability. Further handling is done in CanNm_MainFunction */
            CanNm_TxControlStateRequest[Channel] = CANNM_MSG_TX_DISABLED;
            RetVal = E_OK;
        }
#endif
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_DISABLECOMMUNICATION_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#endif
#if (CANNM_COORDINATOR_SYNC_SUPPORT == STD_ON)
/*****************************************************************************************************************
** Service Name     : CanNm_SetSleepReadyBit
** Service ID       : 0x17
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant (but not for the same NM-Channel)
** Parameters [in]  : nmChannelHandle, nmSleepReadyBit
** Parameters [out] : None
** Return value     : Std_ReturnType
** Description      : Sets the NM Coordinator Sleep Ready bit in the Control Bit Vector
*****************************************************************************************************************/
Std_ReturnType CanNm_SetSleepReadyBit(NetworkHandleType nmChannelHandle, const boolean nmSleepReadyBit)
{
    CANNM_UNUSED_PARAM(nmChannelHandle);
    CANNM_UNUSED_PARAM(nmSleepReadyBit);
}
#endif
#if ((CANNM_COM_USER_DATA_SUPPORT == STD_ON) || defined (CANNM_PN_CALC_FEATURE_ENABLED))
/*****************************************************************************************************************
** Service Name     : CanNm_Transmit
** Service ID       : 0x14
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : CanNmTxPduId, PduInfoPtr
** Parameters [out] : None
** Return value     : Std_ReturnType
** Description      : This function is used by the PduR to trigger a spontaneous transmission of an NM PDU with
                      the provided NM User Data
*****************************************************************************************************************/
Std_ReturnType CanNm_Transmit(PduIdType CanNmTxPduId, const PduInfoType* PduInfoPtr)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANNM_E_NO_ERROR;
    /* Get CanNm Channel index */
    NetworkHandleType Channel = CanNm_GetChIndexFromTxPduId(CanNmTxPduId);

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If module is Initialized */
    if (TRUE != CanNm_InitStatus)
    {
        ErrorId = CANNM_E_NO_INIT;
    }
    /* Check If requested Network is obtained from TxPduId is valid */
    else if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_PDUID;
    }
    /* Check If data pointer is valid */
    else if ((NULL_PTR == PduInfoPtr) || (NULL_PTR == (PduInfoPtr->SduDataPtr)))
    {
        ErrorId = CANNM_E_PARAM_POINTER;
    }
    else
#endif
    {
        CANNM_UNUSED_PARAM(PduInfoPtr);
#if (CANNM_CAR_WAKEUP_RX_ENABLED == STD_ON)
        if(
          (TRUE == CanNm_ChannelConfig[Channel].CarWakeUpRxEnabled)
        )
#endif
        {
            /* SWS_CanNm_00333 - Normal Operation / Repeat Message - trigger transmission in next main function call */
            if (((NM_STATE_NORMAL_OPERATION == CanNm_NmState[Channel]) ||
                (NM_STATE_REPEAT_MESSAGE == CanNm_NmState[Channel]))
#if (CANNM_COM_CONTROL_ENABLED == STD_ON)
                && (CANNM_MSG_TX_DISABLED != CanNm_TxControlState[Channel])
#endif
                )
            {
                CanNm_MsgRequest[Channel] = CANNM_TRANSMIT_REQUEST;
                RetVal = E_OK;
            }
        }
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_TRANSMIT_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#endif
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_IMMEDIATE_TX_CONF_ENABLED == STD_OFF))
/*****************************************************************************************************************
** Service Name     : CanNm_TxConfirmation
** Service ID       : 0x40
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant for different PduIds. Non reentrant for the same PduId.
** Parameters [in]  : TxPduId, Result
** Parameters [out] : None
** Return value     : None
** Description      : This confirms the transmission of an I-PDU from a lower layer communication interface module
*****************************************************************************************************************/
void CanNm_TxConfirmation(PduIdType TxPduId, Std_ReturnType result)
{
    /* Local Variables */
    uint8 ErrorId = CANNM_E_NO_ERROR;
    /* Get CanNm Channel index */
    NetworkHandleType Channel = CanNm_GetChIndexFromTxPduId(TxPduId);

    CANNM_UNUSED_PARAM(result);

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If module is Initialized */
    if (TRUE != CanNm_InitStatus)
    {
        ErrorId = CANNM_E_NO_INIT;
    }
    /* Check If requested Network is obtained from TxPduId is valid */
    else if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_PDUID;
    }
    else
#endif
    {
        /* Set the indication flag. Timers will be timers and state switch processed in CanNm_MainFunction. */
        CanNm_MsgConfirmationFlag[Channel] = TRUE;
        /* SWS_CanNm_00329 - Forward user Data transmission confirmation */
        #if (CANNM_COM_USER_DATA_SUPPORT == STD_ON)
        PduR_CanNmTxConfirmation(CanNM_ChannelPduConfig[Channel].CanNmTxUserDataPduId);
        #endif
        #if (CANNM_TXCONFIRMATION_CBK_SUPPORT == STD_ON)
        if(NULL_PTR != CanNm_ChannelConfig[Channel].CanNmTxConfCbkFunctPtr)
        {
            (CanNm_ChannelConfig[Channel].CanNmTxConfCbkFunctPtr)();
        }
        else
        {
            ErrorId = CANNM_E_PARAM_POINTER;
        }
        #endif
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_TXCONFIRMATION_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
}
#endif
/*****************************************************************************************************************
** Service Name     : CanNm_RxIndication
** Service ID       : 0x42
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant for different PduIds. Non reentrant for the same PduId.
** Parameters [in]  : RxPduId, PduInfoPtr
** Parameters [out] : None
** Return value     : None
** Description      : Indication of a received I-PDU from a lower layer communication interface module
*****************************************************************************************************************/
void CanNm_RxIndication(PduIdType RxPduId, const PduInfoType* PduInfoPtr)
{
    /* Local Variables */
    uint8 ErrorId = CANNM_E_NO_ERROR;
    /* Get CanNm Channel index */
    NetworkHandleType Channel = CanNm_GetChIndexFromRxPduId(RxPduId);
#if ((CANNM_NODE_ID_ENABLED == STD_ON) || (CANNM_USER_DATA_ENABLED == STD_ON) || \
     (CANNM_CAR_WAKEUP_RX_ENABLED == STD_ON) || defined(CANNM_ENABLE_COORD_SYNC_SUPPORT) || \
     ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_NODE_DETECTION_ENABLED == STD_ON)))
    PduLengthType ByteIndex = 0xFFU;
#endif

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If module is Initialized */
    if (TRUE != CanNm_InitStatus)
    {
        ErrorId = CANNM_E_NO_INIT;
    }
    /* Check If requested Network is obtained from RxPduId is valid */
    else if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_PDUID;
    }
    /* Check If data pointer is valid */
    else if ((NULL_PTR == PduInfoPtr) || (NULL_PTR == (PduInfoPtr->SduDataPtr)))
    {
        ErrorId = CANNM_E_PARAM_POINTER;
    }
    else
#endif
    {
        /* SWS_CanNm_00035 - Copy the NM message data to the Rx Message Data Buffer. */
#if ((CANNM_NODE_ID_ENABLED == STD_ON) || (CANNM_USER_DATA_ENABLED == STD_ON) || \
     (CANNM_CAR_WAKEUP_RX_ENABLED == STD_ON))
        for (ByteIndex=0U; ByteIndex<CanNM_ChannelPduConfig[Channel].CanNmReceiveMsgLength; ByteIndex++)
        {
            /* Copy received bytes. Set byte that has not been received to zero */
            if (ByteIndex >=  PduInfoPtr->SduLength)
            {
                CanNm_RxMessageData[Channel][ByteIndex] = 0U;
            }
            else
            {
                CanNm_RxMessageData[Channel][ByteIndex] = PduInfoPtr->SduDataPtr[ByteIndex];
            }
        }
#endif
#if (defined(CANNM_ENABLE_COORD_SYNC_SUPPORT) || ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && \
           (CANNM_NODE_DETECTION_ENABLED == STD_ON)))
        /* Check PDU Position not set to PDU_OFF */
        if ((CANNM_PDU_OFF != CanNm_ChannelConfig[Channel].PduCbvPosition) &&
            /* Check whether CBV Byte can be found inside RX PDU buffer */
            (PduInfoPtr->SduLength  > CanNm_ChannelConfig[Channel].PduCbvPosition))
        {
            ByteIndex = (PduInfoPtr->SduDataPtr[CanNm_ChannelConfig[Channel].PduCbvPosition]);
#if (CANNM_NODE_DETECTION_ENABLED == STD_ON)
            /* Check for state not Repeat Message */
            if ((NM_STATE_REPEAT_MESSAGE != CanNm_NmState[Channel]) && (FALSE == CanNm_RepeatMsgBitIndFlag[Channel]))
            {
                /* Set the Repeat Message Indication */
                CanNm_RepeatMsgBitIndFlag[Channel] = (boolean)(ByteIndex & CANNM_REPEAT_MSG_BIT_MASK);
            }
#endif
        }
#endif

#if (CANNM_CAR_WAKEUP_RX_ENABLED == STD_ON)
        /* Car Wakeup Indication Handing */
        CanNm_CarWakeupIndication(Channel,PduInfoPtr);
#endif
        /* Set the indication flag. Timers will be timers and state switch processed in CanNm_MainFunction */
        CanNm_MsgIndicationFlag[Channel] = TRUE;
        /* PDU Rx Indication is configurable */
#if (CANNM_PDU_RX_INDICATION_ENABLED == STD_ON)
        /* SWS_CanNm_00037 - Notify NM Interface that a Nm message has been received */
        Nm_PduRxIndication(CanNm_ChannelConfig[Channel].NmChannelRef);
#endif
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_RXINDICATION_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
}
#if (CANNM_PN_ENABLED == STD_ON)
/*****************************************************************************************************************
** Service Name     : CanNm_ConfirmPnAvailability
** Service ID       : 0x16
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant (but not for the same NM-Channel)
** Parameters [in]  : nmChannelHandle
** Parameters [out] : None
** Return value     : None
** Description      : Enables the PN filter functionality on the indicated NM Channel
*****************************************************************************************************************/
void CanNm_ConfirmPnAvailability(NetworkHandleType nmChannelHandle)
{
    CANNM_UNUSED_PARAM(nmChannelHandle);
}
#endif
/*****************************************************************************************************************
** Service Name     : CanNm_MainFunction
** Service ID       : 0x13
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : None
** Parameters [out] : None
** Return value     : None
** Description      : Main function of the CanNm Module
*****************************************************************************************************************/
void CanNm_MainFunction(void)
{
    /* Local Variables */
    uint8 ErrorId = CANNM_E_NO_ERROR;
    NetworkHandleType ChIndex = CANNM_INVALID_CHANNEL;

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If module is Initialized */
    if (TRUE != CanNm_InitStatus)
    {
        ErrorId = CANNM_E_NO_INIT;
    }
    else
#endif
    {
        for (ChIndex=0U; ChIndex<CANNM_NUM_OF_CHANNELS; ChIndex++)
        {
            CanNm_LocalMainFunction(ChIndex);
        }
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_MAINFUNCTION_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
}
/*******************************************************************************************************************/
/*  Private APIs                                                                                                   */
/*******************************************************************************************************************/
/*****************************************************************************************************************
** Service Name     : CanNm_LocalInit
** Service ID       : Local_Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : Channel
** Parameters [out] : None
** Return value     : None
** Description      : This function intializes the CanNm modeule global variables
*****************************************************************************************************************/
static void CanNm_LocalInit(const NetworkHandleType Channel)
{
    /* Local Variables */
    uint8 ErrorId = CANNM_E_NO_ERROR;
    PduLengthType ByteIndex = 0xFFU;
    CanNm_PduPositionType NidPosition = CANNM_PDU_OFF;

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If requested Network is valid */
    if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    else
    {
#endif
        CanNm_CommState[Channel]           = CANNM_COMM_READY_SLEEP;
        CanNm_NetworkRestartFlag[Channel]  = CANNM_NO_RESTART;
        CanNm_MsgIndicationFlag[Channel]   = FALSE;
        /* Reset Timers. */
        /* All timers have to be initialized since they are processed in every state. */
        CanNm_TimeoutTimer[Channel]      = (CanNm_TimerCounterType)0U;
        CanNm_WaitBusSleepTimer[Channel] = (CanNm_TimerCounterType)0U;
        CanNm_RepeatMsgTimer[Channel]    = (CanNm_TimerCounterType)0U;
        #if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_IMMEDIATE_RESTART_ENABLED == STD_OFF))
        CanNm_ImmediateNmMsgCount[Channel] = 0U;
        #endif
        #if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_NODE_DETECTION_ENABLED == STD_ON))
        CanNm_RepeatMsgBitIndFlag[Channel] = FALSE;
        CanNm_RepeatMsgReqFlag[Channel] = FALSE;
        #endif
        /* Reset Remote Sleep Timer and state. */
        #if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON))
        CanNm_RemoteSleepTimer[Channel] = (CanNm_TimerCounterType)0U;
        CanNm_RemoteSleepIndState[Channel] = FALSE;
        #endif
        /*Timeout Timer is initially stopped */
        #if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_IMMEDIATE_TX_CONF_ENABLED == STD_OFF))
        CanNm_MsgTimeoutTimer[Channel] = (CanNm_TimerCounterType)0U;
        #endif
        #if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_COM_USER_DATA_SUPPORT == STD_ON))
        CanNm_MsgRequest[Channel] = ((boolean)0);
        #endif
        #if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_COM_CONTROL_ENABLED == STD_ON))
        /* Per default the transmission control status is enabled. */
        CanNm_TxControlState[Channel]        = CANNM_MSG_TX_ENABLED;
        CanNm_TxControlStateRequest[Channel] = CANNM_MSG_TX_ENABLED;
        #endif
        #if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
        CanNm_MsgConfirmationFlag[Channel] = FALSE;
        /*The transmission of NM messages is initially stopped. */
        CanNm_MsgTimer[Channel] = (CanNm_TimerCounterType)0U;
        /* Initialize NM message data. */
        for (ByteIndex=0U; ByteIndex<CanNM_ChannelPduConfig[Channel].CanNmTransmitMsgLength; ByteIndex++)
        {
            CanNm_TxMessageData[Channel][ByteIndex] = CanNm_ChannelConfig[Channel].UnusedDataByteVal;
        }
        NidPosition = CanNm_ChannelConfig[Channel].PduNidPosition;
        /* The reserved bits are set to 0 */
        if ((CANNM_PDU_OFF != NidPosition) &&
            (CanNM_ChannelPduConfig[Channel].CanNmTransmitMsgLength > NidPosition) &&
            (NidPosition < CANNM_MAX_PDU_LENGTH))
        {
            /* Source Node Identifier */
            #if (CANNM_NODE_ID_ENABLED == STD_ON)
            CanNm_TxMessageData[Channel][NidPosition] = CanNm_ChannelConfig[Channel].NodeId;
            #else
            CanNm_TxMessageData[Channel][NidPosition] = 0x00U;
            #endif
        }
        /* Set ControlBitVector to 0x00 */
        if ((CANNM_PDU_OFF != CanNm_ChannelConfig[Channel].PduCbvPosition) &&
            (CanNM_ChannelPduConfig[Channel].CanNmTransmitMsgLength > CanNm_ChannelConfig[Channel].PduCbvPosition))
        {
            CanNm_TxMessageData[Channel][CanNm_ChannelConfig[Channel].PduCbvPosition] = 0x00U;
        }
        #endif
        #if ((CANNM_USER_DATA_ENABLED == STD_ON) || (CANNM_COM_USER_DATA_SUPPORT == STD_ON))
        /* Ensure valid User Data Index */
        if (CanNM_ChannelPduConfig[Channel].CanNmReceiveMsgLength > CanNm_ChannelConfig[Channel].UserDataLength)
        {
            CanNm_UserDataPosition[Channel] = (uint8)(CanNM_ChannelPduConfig[Channel].CanNmReceiveMsgLength -
                                                    CanNm_ChannelConfig[Channel].UserDataLength);
        }
        else
        {
            CanNm_UserDataPosition[Channel] = 0U;
        }
        #endif
        for (ByteIndex=0U; ByteIndex<CanNM_ChannelPduConfig[Channel].CanNmReceiveMsgLength; ByteIndex++)
        {
            CanNm_RxMessageData[Channel][ByteIndex] = CanNm_ChannelConfig[Channel].UnusedDataByteVal;
        }
        /*State machine initialization without notification. */
        CanNm_NmState[Channel] = NM_STATE_BUS_SLEEP;
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_INIT_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
}
/*****************************************************************************************************************
** Service Name     : CanNm_LocalMainFunction
** Service ID       : Local_Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : Channel
** Parameters [out] : None
** Return value     : None
** Description      : Local Main function based on Channel index
*****************************************************************************************************************/
static void CanNm_LocalMainFunction(const NetworkHandleType Channel)
{
    /* Local Variables */
    uint8 ErrorId = CANNM_E_NO_ERROR;
#if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
    Nm_StateType NmReqState = NM_STATE_UNINIT;
#endif
#if (CANNM_IMMEDIATE_RESTART_ENABLED == STD_OFF)
    boolean TxStatus = 0U;
#endif

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If requested Network is valid */
    if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    else
#endif
    {
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_COM_CONTROL_ENABLED == STD_ON))
        CanNm_ComControlProcessing(Channel);
#endif
#if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
        /* Processing of event: Tx Confirmation (#1) */
        if (TRUE == CanNm_MsgConfirmationFlag[Channel])
        {
            CanNm_MsgConfirmationFlag[Channel] = FALSE;
#if (CANNM_COM_CONTROL_ENABLED == STD_ON)
            if (CANNM_MSG_TX_ENABLED == CanNm_TxControlState[Channel])
#endif
            {
                /* SWS_CanNm_00099 - Reset the Network timeout timer (in Network Mode only) */
                /* +1 added since the CanNm_TimeoutTimer decremented in consecutive steps itself */
                CanNm_TimeoutTimer[Channel] = CANNM_TIMEOUTTIME(Channel) + (CanNm_TimerCounterType)1U;
#if (CANNM_IMMEDIATE_TX_CONF_ENABLED == STD_OFF)
                /* SWS_CanNm_00065 - Stop Transmission Timeout Timer */
                CanNm_MsgTimeoutTimer[Channel] = 0U;
#endif
            }
        }
#endif
        CanNm_RxMsgProcessing(Channel);
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_NODE_DETECTION_ENABLED == STD_ON))
        /* Processing of event: Repeat Message Indication. (#3) */
        if (TRUE == CanNm_RepeatMsgReqFlag[Channel])
        {
            CanNm_RepeatMsgBitIndFlag[Channel] = TRUE;
            /* Check for valid PDU Position */
            if ((CANNM_PDU_OFF != CanNm_ChannelConfig[Channel].PduCbvPosition) &&
                (CanNM_ChannelPduConfig[Channel].CanNmTransmitMsgLength > CanNm_ChannelConfig[Channel].PduCbvPosition))
            {
                /* SWS_CanNm_00121, SWS_CanNm_00113 - Set Repeat Message Bit */
                CanNm_TxMessageData[Channel][CanNm_ChannelConfig[Channel].PduCbvPosition] |= CANNM_REPEAT_MSG_BIT_MASK;
            }
        }
        if (TRUE == CanNm_RepeatMsgBitIndFlag[Channel])
        {
            /* SWS_CanNm_00119, SWS_CanNm_00120, SWS_CanNm_00111, SWS_CanNm_00112 - Perform a State Transition to
               Repeat Message State. */
            CanNm_StateTransition(Channel, NM_STATE_REPEAT_MESSAGE);
            CanNm_RepeatMsgReqFlag[Channel] = FALSE;
        }
#endif
        /* Processing of event: Network Restart since active or passive wakeup requested (#4). */
        if (CANNM_NO_RESTART != CanNm_NetworkRestartFlag[Channel])
        {
            /* Perform a state transition to Network Mode. */
            CanNm_StateTransition(Channel, NM_STATE_REPEAT_MESSAGE);
        }
#if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
        /* Processing of event: Request / Release bus communication (#5). */
        if (CANNM_COMM_NORMAL_OPERATION == CanNm_CommState[Channel])
        {
            /* Check current NM mode is Network Mode */
            if (NM_STATE_READY_SLEEP == CanNm_NmState[Channel])
            {
                /* Perform a state transition because bus-communication has been requested. */
                CanNm_StateTransition(Channel, NM_STATE_NORMAL_OPERATION);
            }
        }
        else
        {
            if (NM_STATE_NORMAL_OPERATION == CanNm_NmState[Channel])
            {
                /* Perform a state transition because bus-communication has been released. */
                CanNm_StateTransition(Channel, NM_STATE_READY_SLEEP);
            }
        }
#endif
        /* Handling of NM Timeout Timer (#6) */
        if ((CanNm_TimerCounterType)0U != CanNm_TimeoutTimer[Channel])
        {
            CanNm_TimeoutTimer[Channel]--;
            if ((CanNm_TimerCounterType)0U == CanNm_TimeoutTimer[Channel])
            {
#if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
                if (NM_STATE_READY_SLEEP != CanNm_NmState[Channel])
                {
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
                    /* SWS_CanNm_00316 - Report error if the timeout timer expires out of Ready Sleep State.*/
                    //ErrorId = CANNM_E_NETWORK_TIMEOUT;
#endif
                    /* SWS_CanNm_00206 - Restart the NM Timeout Timer. */
                    CanNm_TimeoutTimer[Channel] = CANNM_TIMEOUTTIME(Channel);
                }
                else
#endif
                {
                    /* SWS_CanNm_00109 - Leave Ready Sleep State, when the Timeout Timer has expired. */
                    CanNm_StateTransition(Channel, NM_STATE_PREPARE_BUS_SLEEP);
                }
            }
        }
        /* Handling of Repeat Message Timer (#7) */
        if ((CanNm_TimerCounterType)0U != CanNm_RepeatMsgTimer[Channel])
        {
            CanNm_RepeatMsgTimer[Channel]--;
            if ((CanNm_TimerCounterType)0U == CanNm_RepeatMsgTimer[Channel])
            {
                /* SWS_CanNm_00102 - Repeat Message State is left upon Repeat Message Timer timeout. */
#if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
                if(CANNM_COMM_NORMAL_OPERATION == CanNm_CommState[Channel])
                {
                    NmReqState = NM_STATE_NORMAL_OPERATION;
                }
                else
                {
                    NmReqState = NM_STATE_READY_SLEEP;
                }
                CanNm_StateTransition( Channel, NmReqState);
#else
                /* Switch to Ready Sleep State directly if passive mode enabled. */
                CanNm_StateTransition( Channel, NM_STATE_READY_SLEEP );
#endif
            }
        }
        /* Handling of Wait Bus Sleep Timer (#8) */
        if ((CanNm_TimerCounterType)0U != CanNm_WaitBusSleepTimer[Channel])
        {
            CanNm_WaitBusSleepTimer[Channel]--;
            if ((CanNm_TimerCounterType)0U == CanNm_WaitBusSleepTimer[Channel])
            {
                /* SWS_CanNm_00115 - Prepare Bus-Sleep Mode is left upon Wait Bus-Sleep Timer timeout. */
                CanNm_StateTransition( Channel,NM_STATE_BUS_SLEEP );
            }
        }
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON))
        /* SWS_CanNm_00150 - Handling of Remote Sleep Indication Timer */
        if ((CanNm_TimerCounterType)0U != CanNm_RemoteSleepTimer[Channel])
        {
            CanNm_RemoteSleepTimer[Channel]--;
            if ((CanNm_TimerCounterType)0U == CanNm_RemoteSleepTimer[Channel])
            {
                /* Remote Sleep Indication (Normal Operation State only). */
                CanNm_RemoteSleepIndState[Channel] = TRUE;
                /* Notification that all other nodes are ready to sleep. */
                Nm_RemoteSleepIndication(CanNm_ChannelConfig[Channel].NmChannelRef);
            }
        }
#endif
#if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
        /* Handling of Tx Message Timer (#10) */
        if ((CanNm_TimerCounterType)0U != CanNm_MsgTimer[Channel])
        {
            CanNm_MsgTimer[Channel]--;
            if (((CanNm_TimerCounterType)0U == CanNm_MsgTimer[Channel])
#if (CANNM_COM_USER_DATA_SUPPORT == STD_ON)
            || (((boolean)0U) != CanNm_MsgRequest[Channel])
#endif
               )
            {
#if (CANNM_IMMEDIATE_RESTART_ENABLED == STD_OFF)
                /* Transmit a NM message. */
                TxStatus = CanNm_TriggerTransmission(Channel);
#else
                /* Transmit a NM message. */
                (void)CanNm_TriggerTransmission(Channel);
#endif
#if (CANNM_IMMEDIATE_RESTART_ENABLED == STD_OFF)
                if (0U != CanNm_ImmediateNmMsgCount[Channel])
                {
                    /* Immediate Transmissions */
                    if (E_OK == TxStatus)
                    {
                        CanNm_ImmediateNmMsgCount[Channel]--;
                    }
                    CanNm_MsgTimer[Channel] = CANNM_IMMEDIATE_NM_CYCLETIME(Channel);
                }
                else
#endif
                {
                    /* Reset Timer */
                    CanNm_MsgTimer[Channel] = CANNM_MSG_CYCLETIME(Channel);
                }
            }
        }
        /* SWS_CanNm_00073 - Handling of Tx Message Timeout Timer (#11) */
#if (CANNM_IMMEDIATE_TX_CONF_ENABLED == STD_OFF)
        if ((CanNm_TimerCounterType)0U != CanNm_MsgTimeoutTimer[Channel])
        {
            /* Decrement NM message timeout timer. */
            CanNm_MsgTimeoutTimer[Channel]--;
            if ((CanNm_TimerCounterType)0U == CanNm_MsgTimeoutTimer[Channel])
            {
                /* SWS_CanNm_00066 - notify timeout exception */
                Nm_TxTimeoutException(CanNm_ChannelConfig[Channel].NmChannelRef);
            }
        }
#endif
#endif
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_MAINFUNCTION_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
}
/*****************************************************************************************************************
** Service Name     : CanNm_StateTransition
** Service ID       : Local_Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : Channel
** Parameters [out] : None
** Return value     : None
** Description      : Local Function to handle CanNm state transitions
*****************************************************************************************************************/
static void CanNm_StateTransition(const NetworkHandleType Channel,const Nm_StateType NextNmState)
{
    /* Local Variables */
    uint8 ErrorId = CANNM_E_NO_ERROR;
    Nm_StateType LastNmState = NM_STATE_UNINIT;
    CanNm_PduPositionType CbvPosition = CANNM_PDU_OFF;
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_IMMEDIATE_RESTART_ENABLED == STD_ON))
    uint8 AdditionalTxnRequired = 0U;
#endif

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If requested Network is valid */
    if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    else
    {
#endif
        /* Store the last state of state machine. */
        LastNmState = CanNm_NmState[Channel];
        /* Acquire the new state. */
        CanNm_NmState[Channel] = NextNmState;
        /* Perform action on transition */
        switch (NextNmState)
        {
            /* -------------------- transition to Bus Sleep -------------------- */
            case NM_STATE_BUS_SLEEP:
                /* SWS_CanNm_00126 - Notify Nm Interface that Bus Sleep State is entered. */
                Nm_BusSleepMode(CanNm_ChannelConfig[Channel].NmChannelRef);
                break;
            /* -------------------- transition to Prepare Bus Sleep -------------------- */
            case NM_STATE_PREPARE_BUS_SLEEP:
                /* SWS_CanNm_00114 - Notify Nm Interface that Prepare Bus Sleep State is entered. */
                Nm_PrepareBusSleepMode(CanNm_ChannelConfig[Channel].NmChannelRef);
                /* Reset the Bus Sleep Time timer. */
                /* +1 added since the CanNm_TimeoutTimer decremented in consecutive steps itself */
                CanNm_WaitBusSleepTimer[Channel] = CANNM_WAITBUS_SLEEPTIME(Channel) + (CanNm_TimerCounterType)1U;
                /* SWS_CanNm_00402 - Clear Active Wake-up Bit in CBV */
#if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
                if (TRUE == CanNm_ChannelConfig[Channel].ActiveWakeupBitEnabled)
                {
                    CbvPosition = CanNm_ChannelConfig[Channel].PduCbvPosition;
                    if ((CANNM_PDU_OFF != CbvPosition) &&
                        (CanNM_ChannelPduConfig[Channel].CanNmTransmitMsgLength > CbvPosition) &&
                        (CbvPosition < CANNM_MAX_PDU_LENGTH))
                    {
                        CanNm_TxMessageData[Channel][CbvPosition] &= CANNM_ACT_WU_BIT_INV_MASK;
                    }
                }
#endif
                break;
            /* -------------------- transition to Ready Sleep -------------------- */
            case NM_STATE_READY_SLEEP:
#if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
                /* SWS_CanNm_00108 - Stop NM message timer. */
                CanNm_MsgTimer[Channel] = (CanNm_TimerCounterType)0U;
#if (CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
                /* Reset Remote Sleep Timer (Normal to Ready Only) */
                CanNm_RemoteSleepTimer[Channel] = (CanNm_TimerCounterType)0u;
#endif
                /*  SWS_CanNm_00107 - Clear the repeat message bit (Repeat to Ready only). */
#if (CANNM_NODE_DETECTION_ENABLED == STD_ON)
                /* Check for PDU Position set to PDU_OFF */
                CbvPosition = CanNm_ChannelConfig[Channel].PduCbvPosition;
                if ((CANNM_PDU_OFF != CbvPosition) &&
                    (CanNM_ChannelPduConfig[Channel].CanNmTransmitMsgLength > CbvPosition))
                {
                    CanNm_TxMessageData[Channel][CbvPosition] &= CANNM_REPEAT_MSG_BIT_INV_MASK;
                }
#endif
#if (CANNM_IMMEDIATE_RESTART_ENABLED == STD_OFF)
                CanNm_ImmediateNmMsgCount[Channel] = 0U;
#endif
#endif
                break;
#if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
            /* -------------------- transition to Normal Operation -------------------- */
            case NM_STATE_NORMAL_OPERATION:
#if (CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
#if (CANNM_COM_CONTROL_ENABLED == STD_ON)
                if (CANNM_MSG_TX_ENABLED == CanNm_TxControlState[Channel])
#endif
                {
                    /* Restart remote Sleep Timer. */
                    CanNm_RemoteSleepTimer[Channel] = CANNM_REMOTE_SLEEP_INDICATIONTIME(Channel) +
                                                    (CanNm_TimerCounterType)1U;
                    CanNm_RemoteSleepIndState[Channel] = FALSE;
                }
#endif
                /* SWS_CanNm_00116 - Start NM message timer. */
                if (NM_STATE_READY_SLEEP == LastNmState)
                {
#if (CANNM_COM_CONTROL_ENABLED == STD_ON)
                    if (CANNM_MSG_TX_ENABLED == CanNm_TxControlState[Channel])
#endif
                    {
                        CanNm_MsgTimer[Channel] = CANNM_MSG_CYCLE_OFFSET(Channel) + (CanNm_TimerCounterType)1U;
                    }
                }
                else
                {
                    /* Clear the repeat message bit. */
#if (CANNM_NODE_DETECTION_ENABLED == STD_ON)
                    /* Check for PDU Position set to PDU_OFF */
                    CbvPosition = CanNm_ChannelConfig[Channel].PduCbvPosition;
                    if ((CANNM_PDU_OFF != CbvPosition) &&
                        (CanNM_ChannelPduConfig[Channel].CanNmTransmitMsgLength > CbvPosition))
                    {
                        CanNm_TxMessageData[Channel][CbvPosition] &= CANNM_REPEAT_MSG_BIT_INV_MASK;
                    }
#endif
                }
                break;
#endif
            /* -------------------- transition to Repeat Message -------------------- */
            default:
                /* Reset the Repeat Message Timer. */
                CanNm_RepeatMsgTimer[Channel] = CANNM_REPEAT_MSGTIME(Channel) + (CanNm_TimerCounterType)1U;
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON))
                /* Stop Remote Sleep Timer and clear Flag */
                CanNm_RemoteSleepTimer[Channel] = (CanNm_TimerCounterType)0u;
                CanNm_RemoteSleepIndState[Channel] = FALSE;
#endif
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_NODE_DETECTION_ENABLED == STD_ON))
                /* Processing of event: Repeat Message Indication. */
                if (TRUE == CanNm_RepeatMsgBitIndFlag[Channel])
                {
                    CanNm_RepeatMsgBitIndFlag[Channel] = FALSE;
#if (CANNM_REPEAT_MSG_IND_ENABLED == STD_ON)
                    /* SWS_CanNm_00014 - Notify NM Interface about Repeat Message Indication */
                    Nm_RepeatMessageIndication( CanNm_ChannelConfig[Channel].NmChannelRef );
#endif
                }
#endif
#if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
#if (CANNM_COM_CONTROL_ENABLED == STD_ON)
                if (CANNM_MSG_TX_ENABLED == CanNm_TxControlState[Channel])
#endif
                {
#if (CANNM_IMMEDIATE_RESTART_ENABLED == STD_OFF)
                    if ((0U < CanNm_ChannelConfig[Channel].ImmediateNmTransmissionsCount) &&
                        (CANNM_ACTIVE_RESTART == CanNm_NetworkRestartFlag[Channel]))
                    {
                        /* Set the message timer to 1 to trigger transmission of the NM message in the same cycle. */
                        CanNm_MsgTimer[Channel] = (CanNm_TimerCounterType)1U;
                        CanNm_ImmediateNmMsgCount[Channel] = CanNm_ChannelConfig[Channel].
                                                             ImmediateNmTransmissionsCount - 1U;
                    }
                    else
#endif
                    {
                        /* Start NM message timer. */
                        CanNm_MsgTimer[Channel] = CANNM_MSG_CYCLE_OFFSET(Channel) + (CanNm_TimerCounterType)1U;
                    }
                }
#endif
                /* Additional actions when entering Network Mode */
                if (NM_STATE_READY_SLEEP > LastNmState)
                {
                    /* Reset Wait Bus Sleep Timer */
                    CanNm_WaitBusSleepTimer[Channel] = (CanNm_TimerCounterType)0U;
                    /* SWS_CanNm_00096 - Restart the Timeout Time timer whenever Network Mode is entered. */
                    CanNm_TimeoutTimer[Channel] = CANNM_TIMEOUTTIME(Channel) + (CanNm_TimerCounterType)1U;
                    /* SWS_CanNm_00097 - Notify Nm Interface that the network mode is started. */
                    Nm_NetworkMode( CanNm_ChannelConfig[Channel].NmChannelRef );
                    /* SWS_CanNm_00401 - Set Active Wake-up Bit in CBV */
#if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
                    if ((TRUE == CanNm_ChannelConfig[Channel].ActiveWakeupBitEnabled) &&
                        (CANNM_ACTIVE_RESTART == CanNm_NetworkRestartFlag[Channel]))
                    {
                        CbvPosition = CanNm_ChannelConfig[Channel].PduCbvPosition;
                        if ((CANNM_PDU_OFF != CbvPosition) &&
                            (CanNM_ChannelPduConfig[Channel].CanNmTransmitMsgLength > CbvPosition) &&
                            ( CbvPosition < CANNM_MAX_PDU_LENGTH))
                        {
                            CanNm_TxMessageData[Channel][CbvPosition] |= CANNM_ACT_WU_BIT_MASK;
                        }
                    }
#endif
                }
                /* SWS_CanNm_00122 - If Network Mode has been entered from Prepare Bus-Sleep Mode due to a network
                request, an asynchronous NM message transmission is requested as soon as Network Mode entered */
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_IMMEDIATE_RESTART_ENABLED == STD_ON))
                if ((NM_STATE_PREPARE_BUS_SLEEP == LastNmState) &&
                    ((CanNm_TimerCounterType)1U < CanNm_MsgTimer[Channel]) &&
                    (CANNM_ACTIVE_RESTART == CanNm_NetworkRestartFlag[Channel]))
                {
                    AdditionalTxnRequired = 1U;
                }
#endif
                /* Reset Restart Flag */
                CanNm_NetworkRestartFlag[Channel] = CANNM_NO_RESTART;
            break;
        }
        /* State Change Notification is configurable */
#if (CANNM_STATE_CHANGE_IND_ENABLED == STD_ON)
        /* SWS_CanNm_00166 - Notify Nm Interface upon every state switch */
        Nm_StateChangeNotification(CanNm_ChannelConfig[Channel].NmChannelRef, LastNmState, NextNmState);
#endif
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_IMMEDIATE_RESTART_ENABLED == STD_ON))
        if (AdditionalTxnRequired != 0U)
        {
            /* Request the transmission of the asynchronous NM message in Network Mode. */
            /* Call CanNm_TriggerTransmission after Nm_StateChangeNotification because the user data might have been
            changed inside the Nm_StateChangeNotification call */
            /* NM Msg Tx due to Immediate Restart after State Change Notification */
            (void)CanNm_TriggerTransmission(Channel);
        }
#endif
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_MAINFUNCTION_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
}
/*****************************************************************************************************************
** Service Name     : CanNm_RxMsgProcessing
** Service ID       : Local_Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : Channel
** Parameters [out] : None
** Return value     : None
** Description      : Local Function to process received NM message
*****************************************************************************************************************/
static void CanNm_RxMsgProcessing(const NetworkHandleType Channel)
{
    /* Local Variables */
    uint8 ErrorId = CANNM_E_NO_ERROR;

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If requested Network is valid */
    if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    else
#endif
    {
        if (TRUE == CanNm_MsgIndicationFlag[Channel])
        {
            CanNm_MsgIndicationFlag[Channel] = FALSE;
            if (NM_STATE_BUS_SLEEP == CanNm_NmState[Channel])
            {
                /* SWS_CanNm_00336 - Report CANNM_E_NET_START_IND error if NM PDU in the Bus-Sleep Mode */
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
                ErrorId = CANNM_E_NET_START_IND;
#endif
                /* SWS_CanNm_00127 - Request to restart the network if a NM PDU received in Bus-Sleep Mode. */
                Nm_NetworkStartIndication(CanNm_ChannelConfig[Channel].NmChannelRef);
            }
            else if (NM_STATE_PREPARE_BUS_SLEEP == CanNm_NmState[Channel])
            {
                /* SWS_CanNm_00124 - Perform state transition. */
                CanNm_StateTransition(Channel, NM_STATE_REPEAT_MESSAGE);
            }
            else
            {
                /* Current NM mode is Network Mode */
#if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
#if ((CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON) || (CANNM_BUS_LOAD_REDUCTION_ENABLED == STD_ON))
                if(NM_STATE_NORMAL_OPERATION == CanNm_NmState[Channel])
                {
#if (CANNM_COM_CONTROL_ENABLED == STD_ON)
                    if (CANNM_MSG_TX_ENABLED == CanNm_TxControlState[Channel])
#endif
                    {
#if (CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
                        /* SWS_CanNm_00151 - Restart Remote Sleep Indication Timer (Normal Operation) */
                        CanNm_RemoteSleepTimer[Channel] = CANNM_REMOTE_SLEEP_INDICATIONTIME(Channel) +
                                                          (CanNm_TimerCounterType)1u;
#endif
                        /* SWS_CanNm_00157 - Busload Reduction can only be active in normal operation state */
#if (CANNM_BUS_LOAD_REDUCTION_ENABLED == STD_ON)
                        if (TRUE == CanNm_ChannelConfig[Channel].BusLoadReductionActive)
                        {
                            /* SWS_CanNm_00069 - Reload the NM Message Transmission Timer with reduced timing */
                            CanNm_MsgTimer[Channel] = CANNM_MSG_REDUCEDTIME(Channel) + (CanNm_TimerCounterType)1U;
                        }
#endif
                    }
                }
#if (CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
                /* SWS_CanNm_00151 - Reset Remote Sleep in Normal Operation or Ready Sleep */
                if (TRUE == CanNm_RemoteSleepIndState[Channel])
                {
                    CanNm_RemoteSleepIndState[Channel] = FALSE;
                    /* Notification that some nodes in the network are not ready to sleep. */
                    Nm_RemoteSleepCancellation(CanNm_ChannelConfig[Channel].NmChannelRef);
                }
#endif
#endif
#endif
                /* SWS_CanNm_00098 - Reset the Network timeout timer (in Network Mode only). */
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && ( CANNM_COM_CONTROL_ENABLED == STD_ON))
                if (CANNM_MSG_TX_ENABLED == CanNm_TxControlState[Channel])
#endif
                {
                    CanNm_TimeoutTimer[Channel] = CANNM_TIMEOUTTIME(Channel) + (CanNm_TimerCounterType)1U;
                }
            }
        }
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_MAINFUNCTION_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
}
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_COM_CONTROL_ENABLED == STD_ON))
/*****************************************************************************************************************
** Service Name     : CanNm_ComControlProcessing
** Service ID       : Local_Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : Channel
** Parameters [out] : None
** Return value     : None
** Description      : Local Function to process communication control state
*****************************************************************************************************************/
static void CanNm_ComControlProcessing(const NetworkHandleType Channel)
{
    /* Local Variables */
    uint8 ErrorId = CANNM_E_NO_ERROR;
    boolean  TxControlStateReq = CANNM_MSG_TX_DISABLED;

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If requested Network is valid */
    if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    else
#endif
    {
        TxControlStateReq = CanNm_TxControlStateRequest[Channel];
        if (CanNm_TxControlState[Channel] != TxControlStateReq)
        {
            CanNm_TxControlState[Channel] = TxControlStateReq;
            if (CANNM_MSG_TX_DISABLED == TxControlStateReq)
            {
                /* SWS_CanNm_00174 - Stop Nm Timeout Timer */
                CanNm_TimeoutTimer[Channel] = (CanNm_TimerCounterType)0U;
                /* SWS_CanNm_00173 - Stop NM message timer. */
                CanNm_MsgTimer[Channel] = (CanNm_TimerCounterType)0U;
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON))
                /* SWS_CanNm_00175 - Reset Remote Sleep Timer and state. */
                CanNm_RemoteSleepTimer[Channel]    = (CanNm_TimerCounterType)0u;
                CanNm_RemoteSleepIndState[Channel] = FALSE;
#endif
            }
            else
            {
                /* SWS_CanNm_00179 - Restart Nm Timeout Timer */
                CanNm_TimeoutTimer[Channel] = CANNM_TIMEOUTTIME(Channel) + (CanNm_TimerCounterType)1U;
                if ((NM_STATE_NORMAL_OPERATION == CanNm_NmState[Channel]) ||
                    (NM_STATE_REPEAT_MESSAGE == CanNm_NmState[Channel]))
                {
                    /* SWS_CanNm_00178 - Start NM message timer. */
                    CanNm_MsgTimer[Channel] = CANNM_MSG_CYCLE_OFFSET(Channel) + (CanNm_TimerCounterType)1U;
                }
#if ((CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON))
                /* SWS_CanNm_00180 - Resume Remote Sleep Indication in Normal state */
                if (NM_STATE_NORMAL_OPERATION == CanNm_NmState[Channel])
                {
                    CanNm_RemoteSleepTimer[Channel] = CANNM_REMOTE_SLEEP_INDICATIONTIME(Channel) + (CanNm_TimerCounterType)1u;
                }
#endif
            }
        }
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_MAINFUNCTION_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
}
#endif
#if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
/*****************************************************************************************************************
** Service Name     : CanNm_TriggerTransmission
** Service ID       : Local_Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : Channel
** Parameters [out] : None
** Return value     : None
** Description      : Local Function to trigger transmission of NM message
*****************************************************************************************************************/
static Std_ReturnType CanNm_TriggerTransmission( const NetworkHandleType Channel)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANNM_E_NO_ERROR;
    PduInfoType NmTxPduInfo;

#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    /* Check If requested Network is valid */
    if (CANNM_NUM_OF_CHANNELS <= Channel)
    {
        ErrorId = CANNM_E_INVALID_CHANNEL;
    }
    else
#endif
    {
#if (CANNM_COM_USER_DATA_SUPPORT == STD_ON)
        if(CanNM_ChannelPduConfig[Channel].CanNmTransmitMsgLength > CanNm_UserDataPosition[Channel])
        {
            /* Get User Data via PduR / COM */
            NmTxPduInfo.SduDataPtr = (uint8 *)&(CanNm_TxMessageData[Channel][CanNm_UserDataPosition[Channel]]);
            /* SDU Length is set by the upper layer to the number of copied bytes */
            NmTxPduInfo.SduLength = CanNm_ChannelConfig[Channel].UserDataLength;
            /* SWS_CanNm_00332 - The number of available user data bytes and the length of the referenced COM I-PDU
            should be validated at generation time*/
            (void)PduR_CanNmTriggerTransmit(CanNM_ChannelPduConfig[Channel].CanNmTxUserDataPduId, &NmTxPduInfo);
        }
        else
        {
            ErrorId = CANNM_E_INIT_FAILED;
        }
        if(CANNM_E_NO_ERROR == ErrorId)
#endif
        {
            /* SWS_CanNm_00450 - If PduR_CanNmTriggerTransmit() returns E_NOT_OK, use the last transmitted value
            for NmUserData. Since User data not changed when PduR_CanNmTriggerTransmit() returns E_NOT_OK, same
            buffer can be used */
            /* Note: The transmission of outdated NM data can be avoided by configuring unique COM IPDU Group for
            NmUserData COM IPDU */
            CanNm_EnterCriticalSection();
            NmTxPduInfo.SduDataPtr =  (uint8 *)(&CanNm_TxMessageData[Channel]);
            NmTxPduInfo.SduLength = (PduLengthType)CanNM_ChannelPduConfig[Channel].CanNmTransmitMsgLength;
#if (CANNM_COM_USER_DATA_SUPPORT == STD_ON)
            /* Clear Request shortly before a transmission is requested */
            CanNm_MsgRequest[Channel] = ((boolean)0);
#endif
            /* Transmit a NM message. */
            RetVal = CanIf_Transmit(CanNM_ChannelPduConfig[Channel].CanNmTransmitMsgLowerLayerId, &NmTxPduInfo);
            CanNm_ExitCriticalSection();
            if (((uint8)E_OK) == RetVal)
            {
#if (CANNM_IMMEDIATE_TX_CONF_ENABLED == STD_ON)
                /* SWS_CanNm_00071 - Set immediate confirmation flag. */
                CanNm_MsgConfirmationFlag[Channel] = TRUE;
#else
                /* SWS_CanNm_00064 - Start Tx message Timeout Timer */
                CanNm_MsgTimeoutTimer[Channel] = CANNM_MSG_TIMEOUTTIME(Channel) + (CanNm_TimerCounterType)1U;
#endif
            }
        }
    }
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
    if (CANNM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        CanNm_Det_ReportError(CANNM_SID_MAINFUNCTION_API, ErrorId);
    }
#else
    CANNM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#endif

#if ( CANNM_CAR_WAKEUP_RX_ENABLED == STD_ON )
/*****************************************************************************************************************
** Service Name     : CanNm_CarWakeupIndication
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant for different Channels
** Parameters [in]  : Channel, PduInfoPtr
** Parameters [out] : None
** Return value     : None
** Description      : This function indicates NM module about CAR Wakeup indication for the given CanNm Channel
*****************************************************************************************************************/
static void CanNm_CarWakeupIndication(const NetworkHandleType Channel, const PduInfoType *PduInfoPtr)
{
    uint8 NidIndex = CANNM_PDU_OFF;
    uint8 CwByteIndex = CANNM_PDU_OFF;

    /* Input parameters Channel and PduInfoPtr validated in invoking function */
    if ((CANNM_NUM_OF_CHANNELS > Channel) && (NULL_PTR != PduInfoPtr))
    {
        NidIndex = CanNm_ChannelConfig[Channel].PduNidPosition;
        CwByteIndex = CanNm_ChannelConfig[Channel].CarWakeUpBytePosition;
        /* Check whether Car Wake Up Byte can be found inside RX PDU buffer */
        if ((TRUE == CanNm_ChannelConfig[Channel].CarWakeUpRxEnabled) && (PduInfoPtr->SduLength > CwByteIndex))
        {
            /* Check whether Car Wake Up Bit is set */
            if (0U !=
               (CanNm_RxMessageData[Channel][CwByteIndex] & (1U<<CanNm_ChannelConfig[Channel].CarWakeUpBitPosition)))
            {
                if( (FALSE == CanNm_ChannelConfig[Channel].CarWakeUpFilterEnabled) ||
                    ((CANNM_PDU_OFF != NidIndex) &&
                    (CanNm_RxMessageData[Channel][NidIndex] == CanNm_ChannelConfig[Channel].CarWakeUpFilterNodeId)) )
                {
                    Nm_CarWakeUpIndication(CanNm_ChannelConfig[Channel].NmChannelRef);
                }
            }
        }
    }
}
#endif
/*****************************************************************************************************************
** Service Name     : CanNm_GetChIndexFromTxPduId
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : RxPduId
** Parameters [out] : None
** Return value     : NetworkHandleType
** Description      : This function returns the CanNm Channel index from Tx PDU ID
*****************************************************************************************************************/
static NetworkHandleType CanNm_GetChIndexFromTxPduId(PduIdType TxPduId)
{
    /* Local Variables */
    NetworkHandleType CanNmChannel = (NetworkHandleType)CANNM_INVALID_CHANNEL;
    NetworkHandleType Channel = (NetworkHandleType)CANNM_INVALID_CHANNEL;

    for (Channel=0U; Channel<CANNM_NUM_OF_CHANNELS; Channel++)
    {
        if (TxPduId == CanNM_ChannelPduConfig[Channel].CanNmTransmitMsgId)
        {
            CanNmChannel = Channel;
            break;
        }
    }
    return CanNmChannel;
}
/*****************************************************************************************************************
** Service Name     : CanNm_GetChIndexFromRxPduId
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : RxPduId
** Parameters [out] : None
** Return value     : NetworkHandleType
** Description      : This function returns the CanNm Channel index from received PDU ID
*****************************************************************************************************************/
static NetworkHandleType CanNm_GetChIndexFromRxPduId(PduIdType RxPduId)
{
    /* Local Variables */
    NetworkHandleType CanNmChannel = (NetworkHandleType)CANNM_INVALID_CHANNEL;
    NetworkHandleType Channel = (NetworkHandleType)CANNM_INVALID_CHANNEL;

    for (Channel=0U; Channel<CANNM_NUM_OF_CHANNELS; Channel++)
    {
        if ((RxPduId >= CanNM_ChannelPduConfig[Channel].CanNmReceiveMsgStartId) &&
            (RxPduId <= CanNM_ChannelPduConfig[Channel].CanNmReceiveMsgEndId))
        {
            CanNmChannel = Channel;
            break;
        }
    }
    return CanNmChannel;
}
/*****************************************************************************************************************
** Service Name     : CanNm_GetChIndexFromNmIndex
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmChannelHandle
** Parameters [out] : None
** Return value     : NetworkHandleType
** Description      : This function returns the CanNm Channel index from NM module index
*****************************************************************************************************************/
static NetworkHandleType CanNm_GetChIndexFromNmIndex(NetworkHandleType nmChannelHandle)
{
    /* Local Variables */
    NetworkHandleType CanNmChannel = (NetworkHandleType)CANNM_INVALID_CHANNEL;

    if (CANNM_NM_NUM_OF_CHANNELS > nmChannelHandle)
    {
        CanNmChannel = CanNM_NmToCanNmChannelMapping[nmChannelHandle];
    }
    return CanNmChannel;
}
#if (CANNM_DEV_ERROR_DETECT == STD_ON)
/*****************************************************************************************************************
** Service Name     : CanNm_Det_ReportError
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : ApiId, ErrorId
** Parameters [out] : None
** Return value     : None
** Description      : This function will Report Develpment Error to DET.
*****************************************************************************************************************/
static void CanNm_Det_ReportError(uint8 ApiId, uint8 ErrorId)
{
    /* Development Error Report */
    (void)Det_ReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, ApiId, ErrorId);
}
#endif
