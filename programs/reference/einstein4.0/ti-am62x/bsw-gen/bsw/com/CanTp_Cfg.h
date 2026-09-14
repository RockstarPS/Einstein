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
*    @file CanTp_Cfg.h
*    @ingroup CanTp Configuration
*    @brief This is CanTp Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the CanTp module.
*    Auto generated code in GARUMUG1 at 2023-02-03 22:46:37.113321
********************************************************************************************************************/
#ifndef CANTP_CFG_H
#define CANTP_CFG_H

#include "SchM_CanTp.h"


#define CANTP_CHANGE_PARAMETER_API                     STD_OFF
#define CANTP_DEV_ERROR_DETECT                         STD_OFF
#define CANTP_DYN_ID_SUPPORT                           STD_OFF
#define CANTP_FLEXIBLE_DATA_RATE_SUPPORT               STD_ON
#define CANTP_GENERIC_CONNECTION_SUPPORT               STD_OFF
#define CANTP_READ_PARAMETER_API                       STD_OFF
#define CANTP_VERSION_INFO_API                         STD_ON
#define CANTP_MIXED_SUPPORT                            STD_OFF
#define CANTP_MIXED_29BIT_SUPPORT                      STD_OFF
#define CANTP_EXTENDED_SUPPORT                         STD_OFF
#define CANTP_NORMAL_FIXED_SUPPORT                     STD_OFF
#define CANTP_PADDING_BYTE                             0xAA
#define CANTP_MAIN_FUNCTION_PERIOD                     5U
#define CANTP_JITTER_VAL                               1U
#define CANTP_META_DATA_RX_SUPPORT          STD_OFF
#define CANTP_META_DATA_TX_SUPPORT          STD_OFF

/*! @brief Defines the CAN TP configuration software Major version */
#define CANTP_CFG_SW_MAJOR_VERSION              0U         
/*! @brief Defines the CAN TP configuration software Minor version */
#define CANTP_CFG_SW_MINOR_VERSION              0U
/*! @brief Defines the CAN TP configuration software Patch version */
#define CANTP_CFG_SW_PATCH_VERSION              1U
/*! @brief Defines the AUTOSAR Release Major version supported by CAN TP configuration  */
#define CANTP_CFG_AR_RELEASE_MAJOR_VERSION      4U        
/*! @brief Defines the AUTOSAR Release Minor version supported by CAN TP configuration  */
#define CANTP_CFG_AR_RELEASE_MINOR_VERSION      2U
/*! @brief Defines the AUTOSAR Release Patch version supported by CAN TP configuration  */
#define CANTP_CFG_AR_RELEASE_REVISION_VERSION   1U

/*! Below are the list of CAN TP layer transmit NSDU ID . Used by CanTp */ 
#define CANTP_TXNSU_DIAG_RESP_USDT             0U
#define CANTP_TXNSDU_DIAG_RESP_UUDT            1U
#define CANTP_NUM_OF_TX_NSDU                   2U


/*! Below are the list of CAN TP layer transmit PDU ID.It is called by CanIf for Tx confirmation and byPduR for transmit request*/ 
#define CANTP_PDU_DIAG_RESP_USDT             0U
#define CANTP_PDU_DIAG_RESP_UUDT             1U
#define CANTP_TXNSDU_PDUID_NUM_OF_PDUID      2U

//removed signals
#define CANTP_PDU_ISO_MDK_MKENTGO_REQ CANTP_TXNSDU_PDUID_NUM_OF_PDUID
#define CANTP_PDU_ISO_MKENTGO_MDK_RESP CANTP_TXNSDU_PDUID_NUM_OF_PDUID

/*! Below are the list of CAN TP layer receive NSDU ID . Used by CanTp */ 
#define CANTP_RXNSDU_DIAG_REQ_PHYSICAL            0U
#define CANTP_RXNSDU_DIAG_REQ_FUNCTIONAL          1U
#define CANTP_NUM_OF_RX_NSDU                      2U

/*! Below are the list of CAN TP layer receive PDU ID.It is called by CanIf for Rx indication and Pdur for Rx connection cancel and property update*/ 
#define CANTP_PDU_DIAG_REQ_PHYSICAL               0U
#define CANTP_PDU_DIAG_REQ_FUNCTIONAL             1U
#define CANTP_RXNSDU_PDUID_NUM_OF_PDUID           2U

/*! Defines the supported channel Id*/
#define CANTP_CHANNEL_CANTPCHANNEL0             0U
#define CANTP_CHANNEL_CANTPCHANNEL1             1U
#define CANTP_NUM_OF_CHANNELS                   2U

/*!@brief Defines the Full duplex channel mode.*/
#define CANTP_MODE_FULL_DUPLEX              0U
/*! @brief Defines the Half duplex channel mode.*/
#define CANTP_MODE_HALF_DUPLEX              1U
/*! @brief This defines the Channel mode of CAN TP channel.*/
typedef uint8 CanTp_ChannelModeType;


/*! @brief This defines the Invalid NSDU value.*/
#define CANTP_INVALID_NSDU   0xFF
/*! @brief This defines the type for the N-SDU Config Id. This type changes based on number of Rx/Tx NSDUs*/
typedef uint8 CanTp_NSduIdType;

/*! @brief Defines the channel ID type. This type changes based on number of channels supported. */
typedef uint8 CanTp_ChannelIdType;

/*! @brief Defines the communication addressing mode as Normal addressing format.*/
#define CANTP_STANDARD                      0U
/*! @brief Defines the communication addressing mode as Normal fixed addressing format.*/
#define CANTP_NORMAL_FIXED                  1U
/*! @brief Defines the communication addressing mode as Extended addressing format.*/
#define CANTP_EXTENDED                      2U
/*! @brief Defines the communication addressing mode as Mixed 11 bit addressing format.*/
#define CANTP_MIXED                         3U
/*! @brief Defines the communication addressing mode as Mixed 29 bit addressing format.*/
#define CANTP_MIXED_29BIT                   4U
/*! @brief Defines the communication addressing mode supported by RxNSdu and TxNSDU */
typedef uint8 CanTp_NsduAddressingFormatType;

/*! @brief Defines the type Tx/Rx frame Padding is not support */
#define CANTP_OFF                           0U
/*! @brief Defines the type Tx/Rx frame Padding is support */
#define CANTP_ON                            1U
/*! @brief Defines the type of Tx/Rx frame Padding support*/
typedef uint8 CanTpPaddingActivationType;

/*! @brief Defines the target address type as classic CAN Physical request type */
#define CANTP_PHYSICAL                      0U
/*! @brief Defines the target address type as classic CAN Functional request type */
#define CANTP_FUNCTIONAL                    1U
/*! @brief Defines the target address type as CAN-FD Physical request type */
#define CANTP_CANFD_PHYSICAL                2U
/*! @brief Defines the target address type as CAN-FDFunctional request type */
#define CANTP_CANFD_FUNCTIONAL              3U
/*! @brief Defines the target address type. */
typedef uint8 CanTp_TaType;

typedef struct 
{
    /*! @brief Defines the channel mode type of CAN TP channel */
    CanTp_ChannelModeType   ChannelMode;
    /*! @brief Defines the configuration id of CAN N-SDU that the CanTp module receives via the CanTpChannel. */
    CanTp_NSduIdType        CanTp_RxNSduIdStart;
    CanTp_NSduIdType        CanTp_RxNSduIdEnd;
    /*! @brief Defines the configuration id of CAN N-SDU that the CanTp module transmit via the CanTpChannel. */
    CanTp_NSduIdType        CanTp_TxNSduIdStart;
    CanTp_NSduIdType        CanTp_TxNSduIdEnd;
}CanTp_ChannelConfigType;

/*! @brief Defines the configuration type for each CAN N-SDU that the CanTp module receives via the CanTpChannel .
    For Timing description refer ISO 15765-2:2016(E)  section 9.8 Network layer timing */
typedef struct 
{
    /*! @brief N_Ar is the time for transmission of a CAN frame (any N_PDU) on the receiver side. Value in milliseconds
    of the N_Ar timeout. Flow Control confirmation timeout*/
    uint32                          Nar;
    /*! @brief N_Br is the elapsed time between the receiving indication of a FF or CF or the transmit confirmation 
        of a FC, until the transmit request of the next FC.Value in milliseconds of the N_Br timeout. 
        Transmit request wait time of FC .*/
    uint32                          Nbr;
    /*! @brief N_Cr is the time until reception of the next Consecutive Frame N_PDU.
        Value in milliseconds of the N_Cr timeout. Consecutive frame wait timeout.*/
    uint32                          Ncr;
    /*! @brief This parameter indicates how many Flow Control wait N-PDUs can be consecutively transmitted by the 
        receiver. It is local to the node and is not transmitted inside the FC protocol data unit. */
    uint32                          RxWftMax;
    /*! @brief Sets the duration of the minimum time the CanTp sender shall wait between the transmissions of 
        two CF N-PDUs. This value is set in the Flow control. */
    uint8                           TpSTmin;
    /*! @brief Defines the block size .Sets the number of N-PDUs the CanTp receiver allows the sender to send, 
        before waiting for an authorization to continue transmission of the following N-PDUs. */
    uint8                           BlockSize;
    /*! @brief Defines the communication addressing format supported by this RxNSdu.*/
    CanTp_NsduAddressingFormatType  RxNsduAddressingFormatType;
    /*! @brief Defines if the receive frame uses padding or not.*/
    CanTpPaddingActivationType      RxPaddingActivation;
    /*! @brief Defines the target address type. */
    CanTp_TaType                    RxTaType;
    /*! @brief Defines the channel Id for this PDU processing. */
    CanTp_ChannelIdType             ChannelId;
    /*! @brief Defines the Id of the RxNSdu . It is used by the by the upper layer to call CanTp_CancelReceive, 
        CanTp_ChangeParameter and CanTp_ReadParameter */
    PduIdType                       UpperLayerPduId;    
    /*! @brief Defines the N-PDU identifier attached to the RxNsdu is identified by CanTpRxNSduId.
        Each RxNsdu identifier is linked to only one SF/FF/CF N-PDU identifier. */
    PduIdType                       FlowControlTxNPduId;
    /*! @brief Defines the Handle Id to be used by the CanIf to confirm the transmission of the CanTpTxFcNPdu 
        to the CanIf module. */
    PduIdType                       FlowControlTxLowerLayerPduId; 
    #if ((CANTP_MIXED_SUPPORT == STD_ON) || (CANTP_MIXED_29BIT_SUPPORT == STD_ON))
    /*! @brief This parameter defines the transport protocol address extension value. */
    uint8                           RxNAe;
    #endif
    #if ((CANTP_EXTENDED_SUPPORT == STD_ON) || \
         ((CANTP_DYN_ID_SUPPORT == STD_ON) && (CANTP_GENERIC_CONNECTION_SUPPORT == STD_OFF) &&  \
         ((CANTP_NORMAL_FIXED_SUPPORT == STD_ON) || (CANTP_MIXED_29BIT_SUPPORT == STD_ON))))
    /*! @brief Defines the transport protocol source address value. */
    uint8                           RxNSa;
    #endif
    #if ((CANTP_EXTENDED_SUPPORT == STD_ON) || \
         ((CANTP_DYN_ID_SUPPORT == STD_ON) && \
         ((CANTP_NORMAL_FIXED_SUPPORT == STD_ON) || (CANTP_MIXED_29BIT_SUPPORT == STD_ON))))
    /*! @brief Defines the transport protocol target address value.*/
    uint8                           RxNTa;
    #endif
    /*! @brief Defines if the Start of Reception would pass Data */
    boolean                         IsDataInStartOfReception;
	#if(STD_ON == CANTP_META_DATA_RX_SUPPORT)
    uint8                           RxMetaDataLength;
    #endif
}CanTp_RxNSduConfigType;

/*! @brief Defines the configuration type for each CAN N-SDU that the CanTp module transmit via the CanTpChannel 
    For Timing description refer ISO 15765-2:2016(E)  section 9.8 Network layer timing */
typedef struct
{
    /*! @brief Value in milliseconds of the N_As timeout. N_As is the time for transmission of a CAN frame (any N_PDU) 
        on the part of the sender. i.e Transmit confirmation timeout */
    uint32                          Nas;
    /*! @brief Value in milliseconds of the N_Bs timeout. N_Bs is the time of transmission until reception of the next 
        Flow Control N_PDU. i.e Flow control wait timeout*/
    uint32                          Nbs;
    /*! @brief Value in milliseconds of the performance requirement of (N_Cs + N_As). N_Cs is the time which elapses 
        between the transmit request of a CF N-PDU until the transmit request of the next CF N-PDU. i,e STmin*/
    uint32                          Ncs;
    /*! @brief Enables / Disables the support of enabling Transmit Cancellation and Receive Cancellation */
    boolean                         TransmitCancellation;
    /*! @brief Defines the communication addressing format supported by this TxNSdu.*/
    CanTp_NsduAddressingFormatType  RxNsduAddressingFormatType;
    /*! @brief Defines if the transmit frame uses padding or not.*/
    CanTpPaddingActivationType      TxPaddingActivation;
    /*! @brief Defines the target address type. */
    CanTp_TaType                    TxTaType;
    /*! @brief Defines the channel Id for this PDU processing. */
    CanTp_ChannelIdType             ChannelId;
    /*! @brief Defines the maximum data length supported by the lower layer */
    PduLengthType                   MaxLowerLayerDataLength;
    /*! @brief Reference to a PDUR PDU Id in the COM-Stack. */
    PduIdType                       UpperLayerPduId;
    /*! @brief  Reference to a PDU Id of the CAN If in the COM-Stack. */
    PduIdType                       LowerLayerId;
    /* CanTpRxFcNPdu config - Used for grouping of the ID of a PDU and the Reference to a PDU*/
    /*! @brief N-PDU identifier attached to the FC N-PDU of this TxNsdu identified by CanTpTxNSduId. 
        Each TxNsdu identifier is linked to one Rx FC N-PDU identifier only.
        However, in the case of extended addressing format, the same FC N-PDU identifier can be used for several 
        N-SDU identifiers. The distinction is made by means of the N_TA value*/
    PduIdType                       CanTpRxFlowContorlNSduId;
    #if ((CANTP_MIXED_SUPPORT == STD_ON) || (CANTP_MIXED_29BIT_SUPPORT == STD_ON))
    /*! @brief This parameter defines the transport protocol address extension value. */
    uint8                           TxNAe;
    #endif
    #if ((CANTP_EXTENDED_SUPPORT == STD_ON) || \
         ((CANTP_DYN_ID_SUPPORT == STD_ON) && \
         ((CANTP_NORMAL_FIXED_SUPPORT == STD_ON) || (CANTP_MIXED_29BIT_SUPPORT == STD_ON))))
    /*! @brief Defines the transport protocol source address value. */
    uint8                           RxNSa;
    #endif
    #if ((CANTP_EXTENDED_SUPPORT == STD_ON) || \
         ((CANTP_DYN_ID_SUPPORT == STD_ON) && (CANTP_GENERIC_CONNECTION_SUPPORT == STD_OFF) &&  \
         ((CANTP_NORMAL_FIXED_SUPPORT == STD_ON) || (CANTP_MIXED_29BIT_SUPPORT == STD_ON))))
    /*! @brief Defines the transport protocol target address value. */
    uint8                           RxNTa;
    #endif 
	#if(STD_ON == CANTP_META_DATA_TX_SUPPORT)
    uint8                           TxMetaDataLength;
    #endif
}CanTp_TxNSduConfigType;

/*!
 *  @brief  This type contains the implementation-specific post build configuration structure of CanNm . 
            Dummy config is used as post build not supported
 */
typedef struct
{
    uint8 Dummy;
}CanTp_ConfigType;

/*******************************************************************************************************************
*  LINK TIME CONFIGURATION GLOBAL CONSTANT                                                                         *
********************************************************************************************************************/

/*! @brief pointer to the CanTp configuration used in CanTp_Init . No PB config , hence the value is NULL_PTR  */
extern const CanTp_ConfigType  * CanTp_ConfigPtr; 
/* @brief The Lookup table for the CanTp Tx PDU Id to CanTp Tx NSDU Map */
extern const CanTp_NSduIdType CanTp_TxPduToNsduMap[CANTP_TXNSDU_PDUID_NUM_OF_PDUID];
/*! @brief The Lookup table for the CanTp Rx PDU Id to CanTp Rx NSDU Map */
extern const CanTp_NSduIdType CanTp_RxPduToNsduMap[CANTP_RXNSDU_PDUID_NUM_OF_PDUID];
/*! @brief The configuration table for each CAN N-SDU that the CanTp module transmit via the CanTpChannel 
    For Timing description refer ISO 15765-2:2016(E)  section 9.8 Network layer timing */
extern const CanTp_TxNSduConfigType CanTp_TxNSduConfig[CANTP_NUM_OF_TX_NSDU];
/*! @brief The configuration table for each CAN N-SDU that the CanTp module receives via the CanTpChannel .
    For Timing description refer ISO 15765-2:2016(E)  section 9.8 Network layer timing */
extern const CanTp_RxNSduConfigType CanTp_RxNSduConfig[CANTP_NUM_OF_RX_NSDU];
/*! @brief The configuration table for the supported channels */
extern const CanTp_ChannelConfigType CanTp_ChannelConfig[CANTP_NUM_OF_CHANNELS];

#endif /* CANTP_CFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


