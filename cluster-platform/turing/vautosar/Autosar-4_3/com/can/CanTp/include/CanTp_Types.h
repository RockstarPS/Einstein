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
*    @file CanTp_Types.h
*    @ingroup CanTp
*    @brief This file provides the private types for the CanTp module. This header file should be included only by  
*    the CanTp module.
********************************************************************************************************************/
#ifndef CANTP_TYPES_H
#define CANTP_TYPES_H

/*******************************************************************************************************************
*   MACRO AND DATA TYPES                                                                                           *
********************************************************************************************************************/
/*! @brief Defines the mask for the single frame data length information. */
#define CANTP_SF_DL_MASK                        0xFU
/*! @brief Defines the mask for the First frame data length information in byte 1. */
#define CANTP_FF_DL_BYTE1_MASK                  0xFFU
/*! @brief Defines the mask for the First frame data length information in byte 0. */
#define CANTP_FF_DL_BYTE0_MASK                  0xFU    
/*! @brief Defines the sequence number value to received after the First frame */
#define CANTP_CF_FIRST_SN                       1U
/*! @brief Defines the mask for sequence number value information in byte 0. */
#define CANTP_CF_SEQ_NUM_MASK                   0xFU
/*! @brief Defines the maximum value for the Flow control frame. */
#define CANTP_FC_MAX_DATA_LENGTH                8U
/*! @brief Defines the maximum value for the Flow control frame. */
#define CANTP_PCI_MASK                          0xFU
/*! @brief Defines the number of padded data length range supported. */
#define CANTP_NUM_OF_PADDED_DATA_LENGTH_RANGE   8U
/*! @brief Defines the minimum value of the STMIN for supported millisecond range. */
#define CANTP_STMIN_MILLISEC_MIN                0x00U
/*! @brief Defines the maximum value of the STMIN for supported millisecond range. */
#define CANTP_STMIN_MILLISEC_MAX                0x7FU
/*! @brief Defines the minimum value of the STMIN for supported microsecond range. */
#define CANTP_STMIN_MICROSEC_MIN                0xF1U
/*! @brief Defines the maximum value of the STMIN for supported microsecond range. */
#define CANTP_STMIN_MICROSEC_MAX                0xF9U

/*! @brief Defines the maximum for Tx and Rx data buffer size .*/
#if(CANTP_FLEXIBLE_DATA_RATE_SUPPORT == STD_OFF)
#define CANTP_MAX_BUFFER_LENGTH                 8U
#else
#define CANTP_MAX_BUFFER_LENGTH                 64U
#endif

#define CANTP_METADATA_MAX_BUFFER_LENGTH        5U

/*! @brief Defines the internal state of CAN TP . This state represents that CAN TP is not initialized.
           The CAN TP module is in CANTP_OFF after power up.*/
#define CANTP_OFF                               0U
/*! @brief Defines the internal state of CAN TP . This state represents that CAN TP is initialized. */
#define CANTP_ON                                1U
/*! @brief Defines the type for internal state of the CanTP Module.*/
typedef uint8   CanTp_InternalStateType;

/*! @brief Defines the Rx state value as RX_WAIT - No Rx processing */
#define CANTP_RX_WAIT                           0U
/*! @brief Defines the Rx sub state of state RX_PROCESSING -  SF,FF or CF frame is processed */
#define CANTP_RX_PROCESSING_FRAME               1U
/*! @brief Defines the Rx sub state of state RX_PROCESSING -  Waiting for the upper layer to provide buffer for 
    SF,FF or CF frame.*/
#define CANTP_RX_PROCESSING_FRAME_BUFFER_WAIT   2U
/*! @brief Defines the Rx sub state of state RX_PROCESSING -  Flow control transmission request is processed */
#define CANTP_RX_PROCESSING_FC_TRANSMIT         3U
/*! @brief Defines the Rx sub state of state RX_PROCESSING -  waiting for Flow control transmission confirmation */
#define CANTP_RX_PROCESSING_FC_CONF_WAIT        4U
/*! @brief The type for the Rx connection state */
typedef uint8 CanTp_RxConnectionStateType;

/*! @brief Defines the Tx connection state as TX_WAIT - No Tx processing */
#define CANTP_TX_WAIT                           0U
/*! @brief Defines the Tx sub state of state TX_PROCESSING -  Waiting for the upper layer to copy data for 
    SF,FF or CF frame.*/
#define CANTP_TX_PROCESSING_BUFFER_WAIT                 1U
/*! @brief Defines the Tx sub state of state TX_PROCESSING -  processing the transmit request.*/
#define CANTP_TX_PROCESSING_TRANSMIT                    2U
/*! @brief Defines the Tx sub state of state TX_PROCESSING -  waiting for the transmit confirmation.*/
#define CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT  3U
/*! @brief Defines the Tx sub state of state TX_PROCESSING - waiting for the transmit confirmation.*/
#define CANTP_TX_PROCESSING_FLOW_CONTROL_WAIT           4U
/*! @brief Defines the Tx sub state of state TX_PROCESSING - CF transmit wait till stmin is zero.*/
#define CANTP_TX_PROCESSING_STMIN_WAIT                  5U
/*! @brief The type for the Tx connection state */
typedef uint8 CanTp_TxConnectionStateType;

/*! @brief Defines the flow control status as Continue to send indicating that CF can be received */
#define CANTP_FC_STATUS_CTS                     0x0U
/*! @brief Defines the invalid flow control status as Wait indicating sender to wait for further CF transmission*/
#define CANTP_FC_STATUS_WAIT                    0x1U
/*! @brief Defines the invalid flow control status as Overflow indicating requested length is not supported*/
#define CANTP_FC_STATUS_OVERFLOW                0x2U
/*! @brief Defines the invalid flow control status*/
#define CANTP_FC_STATUS_NONE                    0xFFU
/*! @brief Type for the flow control status */
typedef uint8 CanTp_FlowControlStatusType;

/*! @brief Defines the transmission satus as successful.*/
#define CANTP_TRANSMIT_OK                       (0U)
/*! @brief Defines the Transmission status as not successful.*/
#define CANTP_TRANSMIT_NOT_OK                   (1U)
/*! @brief Defines the Transmission status as Busy ie, already transmit request for Tx/Rx connection exist, 
    Retry the transmission request later.*/
#define CANTP_TRANSMIT_BUSY                     (2U)
/*! @brief Type for the transmission status */
typedef uint8 CanTp_TransmitStatusType;
 
/*! @brief Defines the bit mask type for no transmit request. */
#define CANTP_TRANSMIT_CONNECTION_NONE          0U    
/*! @brief Defines the bit mask type for transmit request by transmit connection when single frame,first frame and 
    Consecutive frame are transmitted. */
#define CANTP_TRANSMIT_BY_TX_CONNECTION         1U    
/*! @brief Defines the bit mask type for transmit request by receive connection when Flow control frame is 
    transmitted. */
#define CANTP_TRANSMIT_BY_RX_CONNECTION         2U    
/*! @brief Defines the bit mask type of transmit request connection type . */
typedef uint8 CanTp_TransmitRequestType; 

/*! @brief Defines the type for notification of connection status E_OK to upper layer.*/
#define CANTP_NOTIFY_OK                         0U
/*! @brief Defines the type for notification of connection status E_NOT_OK to upper layer.*/
#define CANTP_NOTIFY_NOT_OK                     1U
/*! @brief Defines the type for no notification of connection status to upper layer.*/
#define CANTP_NOTIFY_NONE                       2U
/*! @brief Defines the type for notification of connection status to upper layer.*/
typedef uint8 CanTp_ConnectionNotificationType;

/*! @brief Defines the CANTP PCI frame as Single frame */
#define CANTP_PCI_TYPE_SF                       0U
/*! @brief Defines the CANTP PCI frame as First frame */
#define CANTP_PCI_TYPE_FF                       1U
/*! @brief Defines the CANTP PCI frame as Consecutive frame */
#define CANTP_PCI_TYPE_CF                       2U
/*! @brief Defines the CANTP PCI frame as Flow control frame */
#define CANTP_PCI_TYPE_FC                       3U
/*! @brief Defines the total CANTP PCI frame supported. */
#define CANTP_NUM_OF_PCI_TYPE                   4U
/*! @brief Defines the CANTP PCI frame invalid type. */
#define CANTP_PCI_TYPE_INVALID                  0xFFU
/*! @brief Defines the type for the CANTP PCI frame . */
typedef uint8 CanTp_PciType;

/*! @brief Defines the single frame PCI value in payload */
#define CANTP_PCI_SF_VALUE                     0x00U
/*! @brief Defines the first frame PCI value in payload */
#define CANTP_PCI_FF_VALUE                     0x10U
/*! @brief Defines the consecutive frame PCI value in payload */
#define CANTP_PCI_CF_VALUE                     0x20U
/*! @brief Defines the Flow control frame PCI value in payload */
#define CANTP_PCI_FC_VALUE                     0x30U

typedef struct
{
    /*! @brief connection state for the current channel connection. */
    CanTp_TxConnectionStateType ConnectionState;
    /*! @brief the upper layer buffer state for the current channel connection.*/
    BufReq_ReturnType           BufferState;
    /*! @brief NsduId of current channel connection.*/
    CanTp_NSduIdType            NsduId;
    /*! @brief Frame PCI type which is currently processed.*/
    CanTp_PciType               FramePciType;
    /*! @brief the Block Size counter used for controlling the no of consecutive blocks to be received
    for current channel connection. */
    uint8                       BlockSizeCounter;
    /*! @brief the STMIN value received from the flow control frame */
    uint8                       StMinValue;
    /*! @brief the current sequence counter used for checking the order for consecutive frame sequence counter for
       current channel connection.*/
    uint8                       SequenceNumber;
    /*! @brief Timer for monitoring the N_Ar ,N_Br and N_Cr the current channel connection.*/
    uint32                      Timer;
    /*! @brief the timer for the STMIN */
    uint32                      StMinTimer;
    /*! @brief the total data length to be transmitted in the current channel connection.*/
    PduLengthType               TotalNsduLength;
    /*! @brief the remaining data length to be received in the consecutive frame for the current channel connection.*/
    PduLengthType               RemainingNsduLength;
    /*! @brief Indicates the remaining number of bytes that are available in the upper layer module's Tx buffer for
     the current channel connection.*/
    PduLengthType               AvailableBuffer;
    /*! @brief the length of the data to be transmitted to the lower layer.*/
    PduLengthType               DataBufferLength;
    /*! @brief Contains the data received from the lower layer without the PCI information.*/
    uint8                       DataBuffer[CANTP_MAX_BUFFER_LENGTH];
}CanTp_TxConnectionType;

/*! @brief Defines the type of the Receive connection properties of the channel*/ 
typedef struct
{
    /*! @brief connection state for the current channel connection. */
    CanTp_RxConnectionStateType ConnectionState;
    /*! @brief the upper layer buffer state for the current channel connection.*/
    BufReq_ReturnType           BufferState;
    /*! @brief NsduId of current channel connection.*/
    CanTp_NSduIdType            NsduId;
    /*! @brief Flow control status of the current channel connection.*/
    CanTp_FlowControlStatusType FlowControlStatus;
    /*! @brief Frame PCI type which is currently processed.*/
    CanTp_PciType               FramePciType;
    /*! @brief the STMin value for the current channel connection.*/
    uint8                       STminValue;
    /*! @brief the Block Size counter used for controlling the no of consecutive blocks to be received
        for current channel connection. */
    uint8                       BlockSizeCounter;
    /*! @brief the Flow control wait counter used for sending the number of Flow control frame with WAIT status
        for current channel connection. */
    uint8                       FlowControlWaitCounter;
    /*! @brief the current sequence counter used for checking the order for consecutive frame sequence counter for
       current channel connection.*/
    uint8                       SequenceNumber;
    /*! @brief Timer for monitoring the N_Ar ,N_Br and N_Cr the current channel connection.*/
    uint32                      Timer;
    /*! @brief the remaining data length to be received in the consecutive frame for the current channel connection.*/
    PduLengthType               RemainingNsduLength;
    /*! @brief the data length received in the first frame. This data length should be followed in the consecutive  
        frame reception*/
    PduLengthType               FirstFrameDataLength;
    /*! @brief the total data length to be received in the current channel connection.*/
    PduLengthType               TotalNsduLength;
    /*! @brief the length of the data buffer provided by upper layer in the current channel connection.*/
    PduLengthType               AvailableBuffer;
    /*! @brief the length of the data received from the lower layer without the PCI information.*/
    PduLengthType               DataBufferLength;
    /*! @brief Contains the data received from the lower layer without the PCI information.*/
    uint8                       DataBuffer[CANTP_MAX_BUFFER_LENGTH];
	#if(CANTP_META_DATA_RX_SUPPORT == STD_ON)
    /*! @brief Contains the data received from the lower layer without the PCI information.*/
    uint8                       MetaDataBuffer[CANTP_METADATA_MAX_BUFFER_LENGTH];
    /*! @brief the length of the data received from the lower layer without the PCI information.*/
    PduLengthType               MetaDataBufferLength;
	#endif
}CanTp_RxConnectionType;

/*! @brief Defines the type for the TP parameters which can be changed dynamically */
typedef struct
{
    /*! Defines the stmin value */
    uint8   StMin;   
    /*! Defines the Block size */
    uint8   BlockSize;
}CanTp_DynamicTpParameterType;
            
/*! @brief Type for the Channel connection properties */
typedef struct
{
    /*! the Tx connection properties of this channel. */
    CanTp_TxConnectionType      TxConnection;
    /*! the Rx connection properties of this channel. */
    CanTp_RxConnectionType      RxConnection;
    /*! the current transmit request of this channel. This is a shared variable between the Tx and Rx connection. */
    CanTp_TransmitRequestType   TxRequestType;
}CanTp_ChannelStateType;

/*! @brief Defines the pointer type to the Channel state type */
typedef CanTp_ChannelStateType  * CanTp_ChannelStatePtrType;
/*! @brief Defines the pointer type to the Tx Connection type */
typedef CanTp_TxConnectionType  * CanTp_TxConnectionPtrType;
/*! @brief Defines the pointer type to the Rx Connection type */
typedef CanTp_RxConnectionType  * CanTp_RxConnectionPtrType;

/*! @brief Defines the type for the length lookup for each PCI types */
typedef struct
{
    /*! @brief the minimum length for the PCI */
    PduLengthType   PciCanMinLength;
    /*! @brief the minimum length for the PCI */
    PduLengthType   PciCanMaxLength;
    /*! @brief the minimum length for the CANFD PCI */
    PduLengthType   PciCanFdMinLength;
    /*! @brief the maximum length for the CANFD PCI */
    PduLengthType   PciCanFdMaxLength;
}CanTp_PciLengthConfigType;

/*! @brief Defines the type for the padding data length range */
typedef struct 
{
   /*! @brief the minimum data length in the padding range */
   PduLengthType    MinDataLength; 
   /*! @brief the maximum data length in the padding range */
   PduLengthType    MaxDataLength; 
   /*! @brief the padded data length for the padding range */
   PduLengthType    PaddedDataLength; 
}CanTp_PaddedDataLengthRangeConfig;

/*! 
*   @brief  Defines the function type for the CanTp receive frame processing.This method is used to process the 
*           the receive frame and validate the request for Single frame,First frame , Consecutive frame and 
*           Flow control frames.
*   @param[in] RxNsduId NsduId of the received frame.
*   @param[in] PduInfoPtr received pdu Info.
*           SduDataPtr - pointer to the data buffer
*           SduLength  - length of the data buffer
*/
typedef void (*CanTp_RxPciProcessorFnType)(CanTp_NSduIdType RxNsduId, const PduInfoType* DataInfoPtr, const PduInfoType* MetaInfoPtr);
                                            
/*! 
*   @brief    Defines the function type for the receive frame buffer processing. This method is used to request the 
*           upper layer for the buffer and process the buffer state.
*   @param[in]  ChannelStatePtr pointer to channel connection.
*   @param[in]  RxUpperLayerId  PDU Id value of upper layer.
*/
typedef void (*CanTp_RxPciBufferProcessorFnType)(CanTp_ChannelStatePtrType ChannelStatePtr,PduIdType UpperlayerId);
                                        
/*! @brief Defines the type for function which processing and validate the received frames. */
typedef struct
{
    /*! @brief Defines the function for the CanTp receive frame processing.This method is used to process the 
        the receive frame and validate the request for Single frame,First frame , Consecutive frame and 
        Flow control frames. */
    CanTp_RxPciProcessorFnType          RxPciProcessorFn;
    /*! @brief Defines the function type for the receive frame buffer processing. This method is used to request the 
      upper layer for the buffer and process the buffer state. */
    CanTp_RxPciBufferProcessorFnType    RxPciBufferProcessorFn;
}CanTp_FrameProcessorConfigType;

#endif /* CANTP_TYPES_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/



