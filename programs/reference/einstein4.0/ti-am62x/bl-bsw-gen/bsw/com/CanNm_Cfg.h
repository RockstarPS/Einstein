/********************************************************************************************************************
|   File Name   : CanNm_Cfg.h
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
| 2020-03-17  00.00.02  EA     Basic Funcitionality Realisation
| 2019-12-05  00.00.01  MA     Initial Version
|*******************************************************************************************************************/
#ifndef CANNM_CFG_H
#define CANNM_CFG_H

#include "SchM_CanNm.h"
/*******************************************************************************************************************/
/*  Version Information                                                                                            */
/*******************************************************************************************************************/
/* Software Version */
#define CANNM_CFG_SW_MAJOR_VERSION                      0u
#define CANNM_CFG_SW_MINOR_VERSION                      0u
#define CANNM_CFG_SW_PATCH_VERSION                      1u
/* Autosar Release */
#define CANNM_CFG_AR_RELEASE_MAJOR_VERSION              4u
#define CANNM_CFG_AR_RELEASE_MINOR_VERSION              3u
#define CANNM_CFG_AR_RELEASE_REVISION_VERSION           1u
/* Global config */
/*! @brief Enables / disables the Busload reduction support. */
#define CANNM_BUS_LOAD_REDUCTION_ENABLED                STD_ON
/*! @brief Enables / disables the Bus synchronization support. This feature is required for gateway nodes only. */
#define CANNM_BUS_SYNCHRONIZATION_ENABLED               STD_OFF
/*! @brief Enables / disables the Communication Control support. */
#define CANNM_COM_CONTROL_ENABLED                       STD_ON
/*! @brief Enables / disables the Com User Data support. */
#define CANNM_COM_USER_DATA_SUPPORT                     STD_OFF
/*! @brief Enables / disables the Tx Confirmation Callback execution support. */
#define CANNM_NM_TXCONFIRMATION_SUPPORT                  STD_OFF
/*! @brief Enables / disables the coordinator synchronisation support. */
#define CANNM_COORDINATOR_SYNC_SUPPORT                  STD_OFF
/*! @brief Enables / disables the Default Error Tracer (Det) detection and notification ON or OFF. */
#define CANNM_DEV_ERROR_DETECT                          STD_ON
/*! @brief Enables / disables the asynchronous transmission of a NM PDU upon bus-communication request in
    Prepare-Bus-Sleep mode. */
#define CANNM_IMMEDIATE_RESTART_ENABLED                 STD_OFF
/*! @brief Enables / disables the immediate TX confirmation. */
#define CANNM_IMMEDIATE_TX_CONF_ENABLED                 STD_OFF
/*! @brief Enables / disables the node detection feature. */
#define CANNM_NODE_DETECTION_ENABLED                    STD_OFF
/*! @brief Enables / disables the source node identifier. */
#define CANNM_NODE_ID_ENABLED                           STD_ON
/*! @brief Enables / disables support of the Passive Mode. */
#define CANNM_PASSIVE_MODE_ENABLED                      STD_OFF
/*! @brief Enables / disables the PDU Rx Indication. */
#define CANNM_PDU_RX_INDICATION_ENABLED                 STD_ON
/*! @brief Specifies if CanNm calculates the PN request information for internal an external requests. (EIRA) */
#define CANNM_PN_EIRA_CALC_ENABLED                      STD_OFF
/*! @brief Enables / disables the remote sleep indication support. This feature is required for gateway nodes only. */
#define CANNM_REMOTE_SLEEP_IND_ENABLED                  STD_ON
/*! @brief Enables / disables the notification that a RepeatMessageRequest bit has been received. */
#define CANNM_REPEAT_MSG_IND_ENABLED                    STD_OFF
/*! @brief Enables / disables the CAN NM state change notification. */
#define CANNM_STATE_CHANGE_IND_ENABLED                  STD_OFF
/*! @brief Enables / disables the user data support. */
#define CANNM_USER_DATA_ENABLED                         STD_OFF
/*! @brief Enables / disables the version info API support. */
#define CANNM_VERSION_INFO_API                          STD_ON
/*! @brief Defines the Call cycle in milliseconds of CanNm_MainFunction. */
#define CANNM_MAIN_FUNCTION_PERIOD                      10U

/* Channel config */
/*! @brief Enables or disables support of partial networking . This should be enabled if at least one channel supports
    partial networking.*/
#define CANNM_PN_ENABLED                                STD_OFF
/*! @brief Enables or disables support of CarWakeUp bit evaluation in received NM PDUs. This should be enabled if at
    least one channel
    supports partial networking. */
#define CANNM_CAR_WAKEUP_RX_ENABLED                     STD_OFF

#if (CANNM_PN_ENABLED == STD_ON )
/*! @brief Specifies the runtime of the reset timer in milliseconds. This reset time is valid for the reset of PN
    requests in the EIRA and in the ERA. The value shall be the same for every channel. Thus it is a global config
    parameter. */
#define CANNM_PN_RESET_TIME                             10U
#endif
#if (CANNM_PN_EIRA_CALC_ENABLED == STD_ON)
/*! @brief Reference to a PDU in the COM-Stack.Only one SduRef is required for CanNm because the EIRA is the
    aggregation over all Can Channels. */
#define CANNM_PN_EIRA_RX_NSDU_REF                       COM_PDU_EIRA
#endif

/*! @brief Defines the number of channels supported */
#define CANNM_NUM_OF_CHANNELS                           1U
/*! @brief Defines the invalid CAN NM channel id supported */
#define CANNM_INVALID_CHANNEL                           0xFFU
/*! @brief Defines the Number of NM channels supported */
#define CANNM_NM_NUM_OF_CHANNELS                        2U
/*! @brief Defines the CANNM PduId of NM transmit message */
#define CANNM_TX_PDU_NMID_400                           0U  //index of CanNm in CanIf_TxPduConfig
/*! @brief Defines the CANNM PduId of NM receive message */
#define CANNM_RX_PDU_NMID_412                           1U  //index of CanNm in CanIf_RxPduConfig
/*! @brief Defines the CANNM Invalid PDU ID */
#define CANNM_NO_PDU_ID                                 0xFFFFU
/*! @brief Defines the CANNM MAX PDU Length */
#define CANNM_MAX_PDU_LENGTH                            0x8U

/*! @brief Defines the position of the control bit vector within the NM PDU as Byte 0. */
#define CANNM_PDU_BYTE_0                                0U
/*! @brief Defines the position of the control bit vector within the NM PDU as Byte 1. */
#define CANNM_PDU_BYTE_1                                1U
/*! @brief Defines the control bit vector within the NM PDU is not used. */
#define CANNM_PDU_OFF                                   0xFFU

#ifndef CANNM_UNUSED_PARAM
#define CANNM_UNUSED_PARAM(param) ((void)(param))
#endif

#define CanNm_EnterCriticalSection()    SchM_Enter_CanNm_CANNM_EXCLUSIVE_AREA_0()
#define CanNm_ExitCriticalSection()     SchM_Exit_CanNm_CANNM_EXCLUSIVE_AREA_0()

/*! @brief Defines the position of the control bit vector within the NM PDU . */
typedef uint8 CanNm_PduPositionType;

/*! @brief Function pointer to notify the Nm Message Tx confirmation */
typedef void (*CanNmTxConfirmation)(void);
/*! @brief Defines the channel specific configuration type of the CanNm. */
typedef struct
{
    /*! @brief It defines the NM channel reference of a CanNM channel */
    NetworkHandleType NmChannelRef;
    /*! @brief Timeout for Repeat Message State. It defines the time in millisecondsmilliseconds how long the NM shall stay in the
        Repeat Message State. */
    uint32 RepeatMessageTime;
    /*! @brief Network Timeout for NM PDUs.It denotes the time in milliseconds how long the NM shall stay in the Ready Sleep
        State before transition into the Prepare Bus-Sleep Mode is initiated */
    uint32 TimeoutTime;
    /*! @brief It denotes the time in milliseconds how long the NM shall stay in the Prepare Bus-Sleep Mode before
        transition into Bus-Sleep Mode shall take place.*/
    uint32 WaitBusSleepTime;
    #if (CANNM_IMMEDIATE_RESTART_ENABLED == STD_OFF)
    /*! @brief Defines the immediate NM PDU cycle time in milliseconds which is used for CanNmImmediateNmTransmissions
        NM PDU transmissions. */
    uint32 ImmediateNmCycleTime;
    /*! @brief Defines the number of immediate NM PDUs which shall be transmitted.
        If the value is zero no immediate NM PDUs are transmitted */
    uint8 ImmediateNmTransmissionsCount;
    #endif
    /*! @brief Specifies if first message request in CanNm is repeated until accepted by CanIf. */
    boolean RetryFirstMessageRequest;
    /*! @brief Defines the position of the control bit vector within the NM PDU.
        The value of the parameter represents the location of the Control Bit Vector in the NM PDU
        (CanNmPduByte0 means byte 0, CanNmPduByte1 means byte 1, CanNmPduOff means source node identifier is not
        part of the NM PDU) */
    CanNm_PduPositionType PduCbvPosition;
    /*! @brief Defines the position of the source node identifier within the NM PDU.
        The value of the parameter represents the location of the source node identifier in the NM PDU
        (CanNMPduByte0 means byte 0, CanNmPduByte1 means byte 1, CanNmPduOff means source node identifier is not part
        of the NM PDU) */
    CanNm_PduPositionType PduNidPosition;
    /*! @brief Defines the unused value used for filling unused bytes in the CAN NM Transmit PDUs*/
    uint8 UnusedDataByteVal;
    #if ((CANNM_USER_DATA_ENABLED == STD_ON)|| (CANNM_COM_USER_DATA_SUPPORT == STD_ON))
    /*! @brief Defines the user data length in bytes*/
    uint8 UserDataLength;
    #endif
    #if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
    /*! Enables/Disables the handling of the Active Wakeup Bit in the CanNm module */
    boolean ActiveWakeupBitEnabled;
    /*! @brief Time offset in the periodic transmission node.
        It determines the start delay of the transmission. Specified in milliseconds. */
    uint32 MsgCycleOffset;
    /*! @brief Period of a NM PDU in milliseconds. It determines the periodic rate in the "periodic transmission mode with
    bus load reduction" and is the basis for transmit scheduling in the "periodic transmission mode without bus load
    reduction" */
    uint32 MsgCycleTime;
    /*! @brief Transmission Timeout of NM PDU. If there is no transmission confirmation by the CAN Interface
        within this timeout, the CANNM module shall give an error notification. */
    uint32 MsgTimeoutTime;
    #if (CANNM_BUS_LOAD_REDUCTION_ENABLED == STD_ON)
    /*! @brief Node specific bus cycle time in the periodic transmission mode with bus load reduction. Specified in
        milliseconds. */
    uint32 MsgReducedTime;
    /*! @brief This parameter defines if bus load reduction for the respective NM channel is active or not. */
    boolean BusLoadReductionActive;
    #endif
    #endif
    #if (CANNM_NODE_ID_ENABLED == STD_ON)
    /*! @brief Defines the Node identifier of local node. */
    uint8 NodeId;
    #endif
    #if(CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
    /*! @brief Timeout for Remote Sleep Indication.
        It defines the time in milliseconds how long it shall take to recognize that all other nodes are ready to sleep. */
    uint32 RemoteSleepIndTime;
    #endif
    #if(CANNM_NM_TXCONFIRMATION_SUPPORT == STD_ON)
    /*! @Callback for Tx confirmation for Nm messages*/
    CanNmTxConfirmation CanNmTxConfirmationFunctPtr;
    #endif
    #if (CANNM_PN_ENABLED == STD_ON)
    /*! @brief Enables or disables support of partial networking. */
    boolean PnEnabled;
    /*! @brief Specifies if CanNm calculates the PN request information for external requests. (ERA)
        false: PN request are not calculated true: PN request are calculated */
    boolean PnEraCalcEnabled;
    /*! @brief Specifies if CanNm performs an additional transition from Network Mode to Repeat Message State (true)
        or not (false). */
    boolean PnHandleMultipleNetworkRequests;
    /*! @brief Specifies if CanNm drops irrelevant NM PDUs.
        false: Only NM PDUs with a PNI bit = true and containing a PN request for this ECU triggers the standard RX
        indication handling true: Every NM PDU triggers the standard RX indication handling */
    boolean AllNmMessagesKeepAwake;
    /*! @brief Reference to a Pdu in the COM-Stack. The SduRef is required for every CanNm Channel, because ERA is
        reported per channel. */
    PduIdType PnEraRxNSduRef;
    #endif
    #if (CANNM_CAR_WAKEUP_RX_ENABLED == STD_ON)
    /*! @brief Enables or disables support of CarWakeUp bit evaluation in received NM PDUs. */
    boolean CarWakeUpRxEnabled;
    /*! @brief Enables / Disables the CAR wakeup filter feature support .If CWU filtering is supported, only the CWU
        bit within the NM PDU with source node identifier CanNmCarWakeUpFilterNodeId is considered as CWU request.*/
    boolean CarWakeUpFilterEnabled;
    /*! @brief Specifies the Bit position of the CWU within the NM PDU. */
    uint8 CarWakeUpBitPosition;
    /*! @brief Specifies the Byte position of the CWU within the NM PDU. */
    uint8 CarWakeUpBytePosition;
    /*! @brief Source node identifier for CWU filtering. If CWU filtering is supported, only the CWU bit within the NM
        PDU with source node identifier CanNmCarWakeUpFilterNodeId is considered as CWU request. */
    uint8 CarWakeUpFilterNodeId;
    #endif
}CanNm_ChannelConfigType;

/*! @brief Defines the PDU configuration type of the channel */
typedef struct
{
    #if (CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
    /*! @brief Defines the CANNM Transmit message PDU length of this channel */
    PduLengthType   CanNmTransmitMsgLength;
    /*! @brief Defines the CANNM Transmit message PduId of this channel*/
    PduIdType       CanNmTransmitMsgId;
    /*! @brief Defines the CANNM Transmit message lower layer PduId of this channel*/
    PduIdType       CanNmTransmitMsgLowerLayerId;
    #endif
    /*! @brief Defines the CANNM Receive message PDU length of this channel */
    PduLengthType   CanNmReceiveMsgLength;
    /*! @brief Defines the CANNM Receive message start PduId of this channel*/
    PduIdType       CanNmReceiveMsgStartId;
    /*! @brief Defines the CANNM Receive message end PduId of this channel*/
    PduIdType       CanNmReceiveMsgEndId;
    #if (CANNM_COM_USER_DATA_SUPPORT == STD_ON)
    /*! @brief Defines the CanNmFiatB Transmit message COM user data PduId*/
    PduIdType       CanNmTxUserDataPduId;
    #endif
}CanNM_ChannelPduConfigType;

/*! @brief It defines the mapping between the NM channel and CanNM channel */
extern const NetworkHandleType CanNM_NmToCanNmChannelMapping[CANNM_NM_NUM_OF_CHANNELS];
/*! @brief Defines the PDU configuration for the CANNM channel */
extern const CanNM_ChannelPduConfigType CanNM_ChannelPduConfig[CANNM_NUM_OF_CHANNELS];
/*! @brief Defines the channel specific configuration parameter of the CanNm. */
extern const CanNm_ChannelConfigType CanNm_ChannelConfig[CANNM_NUM_OF_CHANNELS];

#endif /* CANNM_CFG_H */
