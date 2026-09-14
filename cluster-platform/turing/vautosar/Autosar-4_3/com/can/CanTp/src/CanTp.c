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
/*******************************************************************************************************************
*    @file CanTp.c
*    @defgroup CanTp
*    @ingroup CanTp
*    @brief This file implements the AUTOSAR CanTP module.CanTp is the module between the PDU Router and the CAN 
*    Interface module.The main purpose of the CAN TP module is to segment and reassemble CAN I-PDUs longer than 8 bytes
*    or longer than 64 bytes in case of CAN FD.
*    CanTp provides services for:
*       - Segmentation of data in transmit direction;
*       - Reassembling of data in receive direction;
*       - Control of data flow;
*       - Detection of errors in segmentation sessions.
*       - Transmit cancellation
*       - Receive cancellation
********************************************************************************************************************/

/*******************************************************************************************************************
*  HEADER INCLUDES                                                                                                 *
********************************************************************************************************************/
#include "CanTp.h"
#include "CanTp_Cbk.h"
#include "CanTp_Types.h"
#include "PduR_CanTp.h"
#include "CanIf.h"
#include "SchM_CanTp.h"

#if (CANTP_DEV_ERROR_DETECT == STD_ON)
# include "Det.h"
#endif
/********************************************************************************************************************
*  Version check                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if((CANTP_SW_MAJOR_VERSION != CANTP_CFG_SW_MAJOR_VERSION) || \
    (CANTP_SW_MINOR_VERSION != CANTP_CFG_SW_MINOR_VERSION) || \
    (CANTP_SW_PATCH_VERSION != CANTP_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if((CANTP_AR_RELEASE_MAJOR_VERSION != CANTP_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (CANTP_AR_RELEASE_MINOR_VERSION != CANTP_CFG_AR_RELEASE_MINOR_VERSION) || \
    (CANTP_AR_RELEASE_REVISION_VERSION != CANTP_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif

#if((CANTP_META_DATA_TX_SUPPORT == STD_ON) && (CANTP_META_DATA_SUPPORT == STD_OFF))
    #error "Invalid configuration : CANTP_META_DATA_SUPPORT should be STD_ON "
#endif

#if((CANTP_META_DATA_RX_SUPPORT == STD_ON) && (CANTP_META_DATA_SUPPORT == STD_OFF))
    #error "Invalid configuration : CANTP_META_DATA_SUPPORT should be STD_ON "
#endif

#if (CANTP_DEV_ERROR_DETECT == STD_ON)
#define CanTp_DetReportError(ApiId,ErrorId) Det_ReportError(CANTP_MODULE_ID,CANTP_INSTANCE_ID,ApiId,ErrorId)
#endif

/*******************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                       *
********************************************************************************************************************/
/* utility macro to check the valid PCI type */
#define CANTP_UTIL_IS_PCI_TYPE_VALID(pciType)   (((pciType) < (CANTP_NUM_OF_PCI_TYPE))? TRUE : FALSE)

/* utility macro to check if the request type is physical request*/
#define CANTP_UTIL_IS_REQTYPE_PHYSICAL(type)    (((type) == (CANTP_FUNCTIONAL)) || \
                                                 ((type) == (CANTP_CANFD_FUNCTIONAL)) ? FALSE:TRUE)
                                                 
/* utility macro to check if the request type is CAN FD request type*/
#define CANTP_UTIL_IS_NSDU_TYPE_CANFD(type)     (((type) == (CANTP_CANFD_PHYSICAL) ) || \
                                                 ((type) == (CANTP_CANFD_FUNCTIONAL)) ? FALSE:TRUE)                                                  
                                                 
/* utility to get the PCI buffer procesor function . For valid type returns the function else Null pointer */
#define CANTP_UTIL_GET_PCI_BUFFER_PROCESSOR_FUNCTION(pciType) (((pciType) < CANTP_NUM_OF_PCI_TYPE) ? \
                                         (CanTp_FrameProcessorConfig[(pciType)].RxPciBufferProcessorFn): NULL_PTR)

#define CANTP_IGNORE_UNREF_PARAM(param)                  ((void)(param))

/*******************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                        *
********************************************************************************************************************/

/*******************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                     *
********************************************************************************************************************/

/*!*****************************************************************************************************************
*   @brief      This function initializes the CanTp connection channels. 
********************************************************************************************************************/
static void CanTp_InitChannels(void);

/*!***************************************************************************************************************** 
*   @brief      This function initializes the CanTp channel Rx connection.
*   @param[in]  ChannelStatePtr  Pointer to the CanTP Channel.
*   @param[in]  ConnectionNotificationType  notification status type for the upper layer.
*               CANTP_NOTIFY_OK - notify upper layer with E_OK
*               CANTP_NOTIFY_NOT_OK - notify upper layer with E_NOT_OK
*               CANTP_NOTIFY_NONE - donot notify upper layer 
********************************************************************************************************************/
static void CanTp_InitRxConnection(CanTp_ChannelStatePtrType ChannelStatePtr,
                                        CanTp_TransmitRequestType ConnectionNotificationType);
                                        
/*!***************************************************************************************************************** 
*   @brief      This method is used to process receive request and Timeout handling for the CanTp channel connection.
*   @param[in]  ChannelId  CanTP Channel ID value.
********************************************************************************************************************/
static void CanTp_RxChannelProcessing(CanTp_ChannelIdType ChannelId);

/*!***************************************************************************************************************** 
*   @brief      This method is used to get the padded length for CAN/CANFD for the received data length.
*   @param[in]  Length  Received data length.
*   @return     PduLengthType returns the padded data length.
********************************************************************************************************************/
static PduLengthType CanTp_UtilGetPaddingLength(PduLengthType Length);

/*!*****************************************************************************************************************
*   @brief      This method is used to decode and validate the data length received in the PCI frame.
*   @param[in]  PaddingActivationType  padding support enabled/disabled.
*               CANTP_OFF - Padding is supported. 
*               CANTP_ON  - Padding is not supported.
*   @param[in]  PciType  value for the PCI type.
*               CANTP_PCI_TYPE_SF - PCI type is Single frame. 
*               CANTP_PCI_TYPE_FF - PCI type is First frame.
*               CANTP_PCI_TYPE_CF - PCI type is Consecutive frame. 
*               CANTP_PCI_TYPE_FC - PCI type is Flow control frame. 
*   @param[in]  PduInfoPtr  pdu info of the received data.
*   @param[out] ReceivedNsduLengthPtr  pdu info of the received data.
*   @return     Std_ReturnType returns whether the data received is valid or not.
*               E_OK        - valid data is received and \ReceivedNsduLengthPtr contains the Nsdu total length if the
*                             Single/First frame else \ReceivedNsduLengthPtr is 0.
*               E_NOT_OK    - Not a valid data length for the PCI request.
********************************************************************************************************************/
static Std_ReturnType CanTp_CheckAndDecodeRxDl(CanTp_RxNSduConfigType const *  RxNSduConfigPtr,
                                               CanTp_PciType PciType, const PduInfoType* PduInfoPtr,
                                               PduLengthType * ReceivedNsduLengthPtr);

/*!***************************************************************************************************************** 
*   @brief      This method is used to process the received single frame.
*   @param[in]  RxNsduId  received NSdu id value.
*   @param[in]  PduInfoPtr Contains the length (SduLength) of the received I-PDU and a pointer to a 
*                          buffer (SduDataPtr) containing the I-PDU.
********************************************************************************************************************/
static void CanTp_RxSingleFrameProcessor(CanTp_NSduIdType RxNsduId, const PduInfoType* DataInfoPtr, const PduInfoType* MetaInfoPtr);

/*!***************************************************************************************************************** 
*   @brief      This method is used to process the upper layer buffer request and notification for single frame.
*   @param[in]  ChannelStatePtr pointer to channel connection.
*   @param[in]  RxUpperLayerId  PDU Id value of upper layer.
********************************************************************************************************************/
static void CanTp_RxSingleFrameBufferProcessor(CanTp_ChannelStatePtrType ChannelStatePtr,PduIdType UpperlayerId);

/*!***************************************************************************************************************** 
*   @brief      This method is used to process the received first frame.
*   @param[in]  RxNsduId  received NSdu id value.
*   @param[in]  PduInfoPtr Contains the length (SduLength) of the received I-PDU and a pointer to a 
*                          buffer (SduDataPtr) containing the I-PDU.
********************************************************************************************************************/
static void CanTp_RxFirstFrameProcessor(CanTp_NSduIdType RxNsduId, const PduInfoType* DataInfoPtr, const PduInfoType* MetaInfoPtr);

/*!***************************************************************************************************************** 
*   @brief      This method is used to process the upper layer buffer request and notification for first frame.
*   @param[in]  ChannelStatePtr pointer to channel connection.
*   @param[in]  RxUpperLayerId  PDU Id value of upper layer.
********************************************************************************************************************/
static void CanTp_RxFirstFrameBufferProcessor(CanTp_ChannelStatePtrType ChannelStatePtr,PduIdType RxUpperLayerId);

/*!***************************************************************************************************************** 
*   @brief      This method is used to process the received consecutive frame.
*   @param[in]  RxNsduId  received NSdu id value.
*   @param[in]  PduInfoPtr Contains the length (SduLength) of the received I-PDU and a pointer to a 
*                          buffer (SduDataPtr) containing the I-PDU.
********************************************************************************************************************/
static void CanTp_RxConsecutiveFrameProcessor(CanTp_NSduIdType RxNsduId, const PduInfoType* DataInfoPtr, const PduInfoType* MetaInfoPtr);

/*!***************************************************************************************************************** 
*   @brief      This method is used to process the upper layer buffer request and notification for consecutive frame.
*   @param[in]  ChannelStatePtr pointer to channel connection.
*   @param[in]  RxUpperLayerId  PDU Id value of upper layer.
********************************************************************************************************************/
static void CanTp_RxConsecutiveFrameBufferProcessor(CanTp_ChannelStatePtrType ChannelStatePtr,
                                                        PduIdType RxUpperLayerId);

/*!***************************************************************************************************************** 
*   @brief      This method is used to form the Flow control frame and request Flow control transmission.
*   @param[in]  ChannelStatePtr  pointer to channel connection.
********************************************************************************************************************/
static void CanTp_SendFlowControl(CanTp_ChannelStatePtrType ChannelStatePtr);

/*!**************************************************************************************************************** 
*   @brief      This method is used to validate transmission request and request lower layer for transmission.
*   @param[in]  PduInfoPtr Contains the length (SduLength) of the received I-PDU and a pointer to a 
*                          buffer (SduDataPtr) containing the I-PDU.
*   @param[in]  TxPduId PduId for the CanIf layer
*   @param[in]  TransmitConnection connection type that requested transmission
*   @param[in]  paddingSupport padding support enabled or not.
*   @param[in]  paddededLength maximum padded length.
*   @param[in]  ChId PduId Channel Id of the connection.
*   @return     CanTp_TransmitStatusType returns the transmission status.
*               -CANTP_TRANSMIT_OK      - Transmission is successful 
*               -CANTP_TRANSMIT_NOT_OK  - Transmission is not successful
*               -CANTP_TRANSMIT_BUSY    - Already transmit request for Tx/Rx connection exist , Retry the transmission
*                                         request later
********************************************************************************************************************/
static CanTp_TransmitStatusType CanTp_CanIfTransmitData(PduInfoType* PduInfoPtr,
                                        PduIdType TxPduId,CanTp_TransmitRequestType TransmitConnection,
                                        CanTpPaddingActivationType PaddingSupport,
                                        PduLengthType PaddededLength,CanTp_ChannelIdType ChId);

/*!***************************************************************************************************************** 
*   @brief      This method is used to get the number of bytes in a CF block.
*   @param[in]  RxConnectionPtr pointer to the receive connection.
********************************************************************************************************************/
static PduLengthType CanTp_UtilGetBlockSizeInBytes(CanTp_RxConnectionPtrType RxConnectionPtr);

/*!***************************************************************************************************************** 
*   @brief      This method is used to process the flow control transmit confirmation.
*   @param[in]  ChannelStatePtr  pointer to the channel connection.
********************************************************************************************************************/
static void CanTp_ProcessFlowControlConfirmation(CanTp_ChannelStatePtrType ChannelStatePtr);


/*!***************************************************************************************************************** 
*   @brief  This method is the utility for copying data from src to destination pointer with the requested length.
*   @param[in]  pDest   pointer to the destination buffer.
*   @param[in]  pSrc    pointer to the source buffer.
*   @param[in]  length  number of bytes to be copied.
********************************************************************************************************************/
static void CanTp_UtilMemCpy(uint8 *DestPtr,const uint8 * const SrcPtr,PduLengthType Length);

/*!***************************************************************************************************************** 
*   @brief  This method is the utility for setting data to destination pointer with the requested data.
*   @param[in]  pDest   pointer to the destination buffer.
*   @param[in]  Value   Value to be set.
*   @param[in]  Length  number of bytes to be set.
********************************************************************************************************************/
static void CanTp_UtilMemSet(uint8 *DestPtr,uint8 Value,PduLengthType Length);

/*!***************************************************************************************************************** 
*   @brief      This function initializes the CanTp channel Tx connection.
*   @param[in]  ChannelStatePtr  Pointer to the CanTP Channel.
*   @param[in]  ConnectionNotificationType  notification status type for the upper layer.
*               CANTP_NOTIFY_OK - notify upper layer with E_OK
*               CANTP_NOTIFY_NOT_OK - notify upper layer with E_NOT_OK
*               CANTP_NOTIFY_NONE - donot notify upper layer 
********************************************************************************************************************/
static void CanTp_InitTxConnection(CanTp_ChannelStatePtrType ChannelStatePtr,
                                        CanTp_TransmitRequestType ConnectionNotificationType);
                                        
/*!***************************************************************************************************************** 
*   @brief  This method is used to process transmit request and Timeout handling for the CanTp channel connection.
*   @param[in]  ChannelId  CanTP Channel ID value.
********************************************************************************************************************/
static void CanTp_TxChannelProcessing(CanTp_ChannelIdType ChannelId);

/*!***************************************************************************************************************** 
*   @brief  This method is used to process buffer request for frame transmission.
*   @param[in]  ChannelStatePtr  pointer to the channel connection.
*   @return Returns the request status
*           E_OK - Buffer request successful or waiting to get buffer.
*           E_NOT_OK - Buffer request is declined by the upper layer.
********************************************************************************************************************/
static Std_ReturnType CanTp_TxFrameBufferProcessing(CanTp_ChannelStatePtrType ChannelStatePtr);

/*!***************************************************************************************************************** 
*   @brief  This method is used to update the PCI info , data and request transmission to lower layer.
*   @param[in]  ChannelStatePtr  pointer to the channel connection.
*   @return Returns the request status
*           E_OK - Transmit successful or Transmit connection is already in progress (process in main function).
*           E_NOT_OK - Transmit request is declined by the lower layer.
********************************************************************************************************************/
static Std_ReturnType CanTp_TxUpdateAndTransmitPci(CanTp_ChannelStatePtrType ChannelStatePtr);

/******************************************************************************************************************* 
*   @brief  This method is used to process transmit confirmation received for the CanTp channel connection.
*   @param[in] ChannelStatePtr  pointer to the channel connection.
********************************************************************************************************************/
static void CanTp_ProcessTxConfirmation(CanTp_ChannelStatePtrType ChannelStatePtr);

/*!**************************************************************************************************************** 
*   @brief      This method is used to process the received Flow control frame.
*   @param[in]  RxNsduId  received NSdu id value.
*   @param[in]  PduInfoPtr Contains the length (SduLength) of the received I-PDU and a pointer to a 
*                          buffer (SduDataPtr) containing the I-PDU.
********************************************************************************************************************/
static void CanTp_RxFlowControlFrameProcessor(CanTp_NSduIdType RxNsduId, const PduInfoType* DataInfoPtr, const PduInfoType* MetaInfoPtr);

/*!**************************************************************************************************************** 
*   @brief      This method is used to get STMin timer value.
*   @param[in]  StMinValue  received STMin value.
********************************************************************************************************************/
static uint32 CanTp_UtilGetTimeInCyclicPeriod(uint8 StMinValue);

/*******************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                       *
********************************************************************************************************************/
/*! @brief The internal state of the CanTP Module. 
    CANTP_OFF   - This state represents that CAN TP is not initialized.
    CANTP_ON    - This state represents that CAN TP is initialized.
*/
static CanTp_InternalStateType  CanTp_InternalState = CANTP_OFF;
/*! @brief The channel connection state for the supported channels */
static CanTp_ChannelStateType   CanTp_ChannelState[CANTP_NUM_OF_CHANNELS];
/*! @brief The function lookup table for the frame processor */
static const CanTp_FrameProcessorConfigType CanTp_FrameProcessorConfig[CANTP_NUM_OF_PCI_TYPE]=
{
    {&CanTp_RxSingleFrameProcessor      ,&CanTp_RxSingleFrameBufferProcessor        }, /*  Single frame processors  */
    {&CanTp_RxFirstFrameProcessor       ,&CanTp_RxFirstFrameBufferProcessor         }, /* First frame processors */
    {&CanTp_RxConsecutiveFrameProcessor ,&CanTp_RxConsecutiveFrameBufferProcessor   }, /* Consecutive frame processors*/
    {&CanTp_RxFlowControlFrameProcessor ,NULL_PTR   }  /* Flow control frame processors  */
};

/*! @brief lookup table for the PCI min ,max range for each PCI frame. */
static const CanTp_PciLengthConfigType CanTp_PciLengthConfig[CANTP_NUM_OF_PCI_TYPE]=
{
    {2U ,8U ,3U  ,64U }, 
    {8U ,8U ,8U  ,64U },
    {2U ,8U ,2U  ,64U },
    {3U ,8U ,3U  ,8U  }
};

/*! @brief lookup table for the supported padded data length range. */
static const CanTp_PaddedDataLengthRangeConfig CanTp_PaddedDataLengthRange[CANTP_NUM_OF_PADDED_DATA_LENGTH_RANGE]=
{
    {1U     ,8U     ,8U  },
    {9U     ,12U    ,12U },
    {13U    ,16U    ,16U },
    {17U    ,20U    ,20U },
    {21U    ,24U    ,24U },
    {25U    ,32U    ,32U },
    {33U    ,48U    ,48U },
    {49U    ,64U    ,64U }
};

#if (CANTP_CHANGE_PARAMETER_API == STD_ON)
static CanTp_DynamicTpParameterType CanTp_DynamicTpParameter[CANTP_NUM_OF_RX_NSDU];
#endif

/* Public function implementation */
/****************************************************************************************************************** 
*   @brief      This function initializes the CanTp module.
*   @param[in]  CfgPtr  Pointer to the CanTp post-build configuration data.
*   @ServiceID  0x01
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
*   @note       The CanTp module’s environment shall call CanTp_Init before using the CanTp module for further
*               processing
********************************************************************************************************************/
void CanTp_Init(const CanTp_ConfigType* CfgPtr)
{
    CanTp_InitChannels();
    /* set internal state to CANTP_ON */
    CanTp_InternalState = CANTP_ON;
    CANTP_IGNORE_UNREF_PARAM(CfgPtr);
}

/******************************************************************************************************************* 
*   @brief      This function returns the version information of the CanTp module.
*   @param[out] VersionInfo  Indicator as to where to store the version information of this module
*   @ServiceID  0x07
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
void CanTp_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
    #if (CANTP_DEV_ERROR_DETECT == STD_ON)
    uint8 ErrorId = CANTP_E_NO_ERROR;

    /* Check if parameter VersionInfo is valid */
    if (NULL_PTR == VersionInfo)
    {
        ErrorId = CANTP_E_PARAM_POINTER;
    }
    else
    #endif
    {
        VersionInfo->vendorID         = CANTP_VENDOR_ID;
        VersionInfo->moduleID         = CANTP_MODULE_ID;
        VersionInfo->sw_major_version = CANTP_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = CANTP_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = CANTP_SW_PATCH_VERSION;
    }
    #if (CANTP_DEV_ERROR_DETECT == STD_ON)
    if (CANTP_E_NO_ERROR != ErrorId)
    {
        (void)CanTp_DetReportError(CANTP_SID_GETVERSIONINFO, ErrorId);
    }
    #endif
} 

/******************************************************************************************************************* 
*   @brief      This function is called to shutdown the CanTp module.
*   @ServiceID  0x02
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
void CanTp_Shutdown(void)
{
    #if (CANTP_DEV_ERROR_DETECT == STD_ON)
    uint8 ErrorId = CANTP_E_NO_ERROR;
    
    if(CANTP_ON != CanTp_InternalState)
    {
        ErrorId = CANTP_E_UNINIT;
    }
    else
    #endif
    {
        CanTp_InitChannels();
        CanTp_InternalState = CANTP_OFF;
    }    
    #if (CANTP_DEV_ERROR_DETECT == STD_ON)
    if (CANTP_E_NO_ERROR != ErrorId)
    {
        (void)CanTp_DetReportError(CANTP_SID_SHUTDOWN, ErrorId);
    }
    #endif
}
 
/******************************************************************************************************************* 
*   @brief      This service is used to request the transfer of segmented data.
*   @param[in]  CanTpTxSduId    This parameter contains the unique CanTp module identifier of the CAN N-SDU to be 
*               transmitted.
*   @param[in]  CanTpTxInfoPtr  A pointer to a structure with CAN N-SDU related data: the length of the N-SDU that 
*               shall be transmitted, and a pointer to SDU data, which contains the addressing information for N-SDUs 
*               with MetaData (generic connections), and NULL otherwise.
*   @return     Std_ReturnType
*               E_OK: The request can be started successfully 
*               E_NOT_OK: The request cannot be started (e.g. a transmit request is in progress with the same 
*                         N-SDU identifier)
*   @ServiceID  0x03
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant
********************************************************************************************************************/
Std_ReturnType CanTp_Transmit(PduIdType CanTpTxSduId, const PduInfoType* CanTpTxInfoPtr)
{
    uint8 ErrorId = CANTP_E_NO_ERROR;
    uint32 SfMaxLength;
    CanTp_NSduIdType TxNsduId;
    CanTp_TxNSduConfigType const * TxNSduConfigPtr;
    CanTp_ChannelModeType  ChMode;
    CanTp_ChannelIdType  ChId;
    CanTp_TxConnectionPtrType  TxConnectionPtr;
    CanTp_RxConnectionPtrType  RxConnectionPtr;
    CanTp_ChannelStatePtrType ChannelStatePtr;
    Std_ReturnType Status=E_NOT_OK;
    uint8 Addr_Offset = 0u;
    
    if ( CANTP_ON != CanTp_InternalState)
    {
        ErrorId = CANTP_E_UNINIT;
    }
#if (CANTP_DEV_ERROR_DETECT == STD_ON)                                                                                 
    else if (CANTP_TXNSDU_PDUID_NUM_OF_PDUID <= CanTpTxSduId)
    {
        ErrorId = CANTP_E_INVALID_TX_ID;
    }
    else if (NULL_PTR == CanTpTxInfoPtr)
    {
        ErrorId = CANTP_E_PARAM_POINTER;
    }
#endif
    else
    {
        /* Get the NSDU Id from the CanTpTxSduId */
        TxNsduId = CanTp_TxPduToNsduMap[CanTpTxSduId];
        if (CANTP_NUM_OF_TX_NSDU > TxNsduId )
        {
            /* Get NSdu configuration. */
            TxNSduConfigPtr = &CanTp_TxNSduConfig[TxNsduId];
            /* Get channel mode */
            ChId = TxNSduConfigPtr->ChannelId;
            if(CANTP_NUM_OF_CHANNELS > ChId )
            {
                /* Get Channel mode from the channel configuration. */
                ChMode = CanTp_ChannelConfig[ChId].ChannelMode;
                /* Get the channel  */
                ChannelStatePtr = &CanTp_ChannelState[ChId];
                TxConnectionPtr = &ChannelStatePtr->TxConnection;
                RxConnectionPtr = &ChannelStatePtr->RxConnection;
    
                if((TxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_STANDARD) &&
                      (TxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_NORMAL_FIXED))
                {
                    Addr_Offset = 0x01u;
                }
                else 
                {
                    Addr_Offset = 0x00u;              
                }
                
                /* Check for valid data length  */
                if (0U != CanTpTxInfoPtr->SduLength)
                {
                    /* check for the connection to be free. */
                    if (((CANTP_MODE_HALF_DUPLEX == ChMode ) && \
                        (CANTP_RX_WAIT == RxConnectionPtr->ConnectionState)) || \
                        (CANTP_MODE_FULL_DUPLEX == ChMode ))
                     {
                         CanTp_EnterCriticalSection();
                         /* Init Connection */
                         CanTp_InitTxConnection(ChannelStatePtr,CANTP_NOTIFY_NONE);
                        if (TxNSduConfigPtr->MaxLowerLayerDataLength <= 8U)
                        {
                            SfMaxLength = TxNSduConfigPtr->MaxLowerLayerDataLength-1U;
                        }
                        else
                        {
                            SfMaxLength = TxNSduConfigPtr->MaxLowerLayerDataLength-2U;
                        }
                         /* If connection is ready for new transmission. */
                        /* SWS_CanTp_00225 - Determine PCI Type based on SduLength instead of metadata */
                        if ((CanTpTxInfoPtr->SduLength + Addr_Offset) > SfMaxLength)
                        {
                             TxConnectionPtr->FramePciType = CANTP_PCI_TYPE_FF;
                             
                         }
                         else
                         {
                             TxConnectionPtr->FramePciType = CANTP_PCI_TYPE_SF;
                         }
                         TxConnectionPtr->ConnectionState = CANTP_TX_PROCESSING_BUFFER_WAIT;
                         TxConnectionPtr->BufferState = BUFREQ_E_BUSY;
                         TxConnectionPtr->NsduId = TxNsduId;
                         TxConnectionPtr->TotalNsduLength = CanTpTxInfoPtr->SduLength;
                         TxConnectionPtr->RemainingNsduLength=CanTpTxInfoPtr->SduLength;
                         /* SWS_CanTp_00167 : Start the N_Cs Timer*/
                         TxConnectionPtr->Timer = TxNSduConfigPtr->Ncs;
                         Status = CanTp_TxFrameBufferProcessing(ChannelStatePtr);
                         CanTp_ExitCriticalSection();
                     }
                } /* CanTpTxInfoPtr->SduLength > 0U */
            } /* ChId < CANTP_NUM_OF_CHANNELS */
        }/*  TxNsduId < CANTP_NUM_OF_TX_NSDU */
    }
    
    #if (CANTP_DEV_ERROR_DETECT == STD_ON)
    if (CANTP_E_NO_ERROR != ErrorId)
    {
       (void)CanTp_DetReportError(CANTP_SID_TRANSMIT, ErrorId);
    }
    #else
    {
        CANTP_IGNORE_UNREF_PARAM(ErrorId);
    }
    #endif

    return Status;
} 

/******************************************************************************************************************* 
*   @brief      This service primitive is used to cancel the transfer of a pending CAN N-SDU. When the function returns,
*               no transmission is in progress anymore with the given N-SDU identifier.
*   @param[in]  CanTpTxSduId This parameter contains the unique CanTp module identifier of the N-SDU to be canceled 
*               for transmission.
*   @return     Std_ReturnType
*               E_OK: Cancellation request of the specified N-SDU is accepted.
*               E_NOT_OK: Cancellation request is rejected; the reason can be that request is issued for an N-SDU that 
*               is not segmented, request is issued after the last CF has been requested for transmission or 
*               cancellation is not possible for the related N-SDU due to configuration.
*   @ServiceID  0x08
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
Std_ReturnType CanTp_CancelTransmit(PduIdType CanTpTxSduId)
{
    uint8 ErrorId = CANTP_E_NO_ERROR;
    CanTp_TxNSduConfigType const * TxNSduConfigPtr;
    CanTp_TxConnectionPtrType  TxConnectionPtr;
    CanTp_ChannelStatePtrType ChannelStatePtr;
    CanTp_NSduIdType TxNsduId;
    CanTp_ChannelIdType  ChId;
    Std_ReturnType Status=E_NOT_OK;
    
    if ( CANTP_ON != CanTp_InternalState)
    {
        ErrorId = CANTP_E_UNINIT;
    }
    #if (CANTP_DEV_ERROR_DETECT == STD_ON)                                                                                 
    else if (CANTP_TXNSDU_PDUID_NUM_OF_PDUID <= CanTpTxSduId)
    {
        ErrorId = CANTP_E_INVALID_TX_ID;
    }
    #endif
    else
    {
        /* Get channel Id and get TxConnection. */
        TxNsduId = CanTp_TxPduToNsduMap[CanTpTxSduId];
        if(CANTP_NUM_OF_TX_NSDU >TxNsduId)
        {
            /* Get NSdu configuration. */
            TxNSduConfigPtr = &CanTp_TxNSduConfig[TxNsduId];
            /* Get channel mode */
            ChId = TxNSduConfigPtr->ChannelId;
            if (CANTP_NUM_OF_CHANNELS > ChId)
            {
                ChannelStatePtr = &CanTp_ChannelState[ChId];
                TxConnectionPtr = &ChannelStatePtr->TxConnection;
                /* check for cancellation support */
                if (TRUE == TxNSduConfigPtr->TransmitCancellation)
                {
                    CanTp_EnterCriticalSection();
                    if(TxConnectionPtr->ConnectionState != CANTP_TX_WAIT)
                    {
                        if ((TxConnectionPtr->FramePciType == CANTP_PCI_TYPE_FF ) ||
                            (TxConnectionPtr->FramePciType == CANTP_PCI_TYPE_CF))
                        {
                            /* Cancel transmission only if segment message transmission in progress */
                            CanTp_InitTxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
                            Status = E_OK;
                        }
                    }
                    CanTp_ExitCriticalSection();
                }
            }
        }
    }
    
    #if (CANTP_DEV_ERROR_DETECT == STD_ON)
    if (CANTP_E_NO_ERROR != ErrorId)
    {
        (void)CanTp_DetReportError(CANTP_SID_CANCELTRANSMIT, ErrorId);
    }
    #else
    {
        CANTP_IGNORE_UNREF_PARAM(ErrorId);
    }
    #endif
    return Status;
} 

/******************************************************************************************************************* 
*   @brief      This service is used to cancel the reception of an ongoing N-SDU.
*   @param[in]  CanTpRxSduId Identifier of the received N-SDU.
*   @return     Std_ReturnType
*               E_OK: Cancellation request of the specified N-SDU is accepted.
*               E_NOT_OK: Cancellation request is rejected; the reason can be that request is issued for an N-SDU that 
*               is not segmented or request is issued for an N-SDU that is not in the reception process.
*   @ServiceID  0x09
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
Std_ReturnType CanTp_CancelReceive(PduIdType CanTpRxSduId)
{
    uint8 ErrorId = CANTP_E_NO_ERROR;
    CanTp_RxNSduConfigType const * RxNSduConfigPtr;
    CanTp_RxConnectionPtrType  RxConnectionPtr;
    CanTp_ChannelStatePtrType ChannelStatePtr;
    CanTp_TxNSduConfigType const * TxNSduConfigPtr;
    CanTp_NSduIdType RxNsduId;
    CanTp_ChannelIdType  ChId;
    Std_ReturnType Status=E_NOT_OK;
    
    if ( CANTP_ON != CanTp_InternalState)
    {
        ErrorId = CANTP_E_UNINIT;
    }
    #if (CANTP_DEV_ERROR_DETECT == STD_ON)                                                                                 
    else if (CANTP_RXNSDU_PDUID_NUM_OF_PDUID <= CanTpRxSduId)
    {
        ErrorId = CANTP_E_INVALID_RX_ID;
    }
    #endif
    else
    {
        /* Get channel Id and get TxConnection. */
        /* Get the NSDU Id from the CanTpTxSduId */
        RxNsduId = CanTp_RxPduToNsduMap[CanTpRxSduId];
        /* Get NSdu configuration. */
        if (CANTP_NUM_OF_RX_NSDU > RxNsduId)
        {
            RxNSduConfigPtr = &CanTp_RxNSduConfig[RxNsduId];
            /* Get channel mode */
            ChId = RxNSduConfigPtr->ChannelId;
            if ((CANTP_NUM_OF_CHANNELS > ChId) && 
                (CANTP_NUM_OF_TX_NSDU > RxNSduConfigPtr->FlowControlTxNPduId))
            {
                ChannelStatePtr = &CanTp_ChannelState[ChId];
                RxConnectionPtr = &ChannelStatePtr->RxConnection;
                /* Get the transmit cancellation feature from the Tx pdu  */
                /* SWS Item ECUC_CanTp_00282 */
                TxNSduConfigPtr = &CanTp_TxNSduConfig[RxNSduConfigPtr->FlowControlTxNPduId];
                if (TRUE == TxNSduConfigPtr->TransmitCancellation)
                {
                    CanTp_EnterCriticalSection();
                    if(CANTP_RX_WAIT != RxConnectionPtr->ConnectionState)
                    {
                        /* SWS_CanTp_00262] */
                        if ((CANTP_PCI_TYPE_FF == RxConnectionPtr->FramePciType) ||
                            ((CANTP_PCI_TYPE_CF == RxConnectionPtr->FramePciType) && 
                            (RxConnectionPtr->DataBufferLength > RxConnectionPtr->RemainingNsduLength)))
                        {
                            /* Cancel reception only if the segmented reception in progress and it should not be the last CF */
                            CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
                            Status = E_OK;
                        }
                    }
                    CanTp_ExitCriticalSection();
                }
            }
        }
    }
    #if (CANTP_DEV_ERROR_DETECT == STD_ON)
    if (CANTP_E_NO_ERROR != ErrorId)
    {
        (void)CanTp_DetReportError(CANTP_SID_CANCELRECEIVE, ErrorId);
    }
    #else
    {
        CANTP_IGNORE_UNREF_PARAM(ErrorId);
    }
    #endif
    return Status;
}

#if(CANTP_CHANGE_PARAMETER_API == STD_ON)
/******************************************************************************************************************* 
*   @brief      This service is used to request the change of reception parameters BS and STmin for a specified N-SDU.
*   @param[in]  Id Identifier of the received N-SDU on which the reception parameter has to be changed.
*   @param[in]  Parameter Specify the parameter to which the value has to be changed (BS or STmin).
*   @param[in]  Value The new value of the parameter.
*   @return     Std_ReturnType
*               E_OK: request is accepted
*               E_NOT_OK: request is not accepted
*   @ServiceID  0x0a
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
Std_ReturnType CanTp_ChangeParameter(PduIdType Id,TPParameterType Parameter,uint16 Value)
{
    uint8 ErrorId = CANTP_E_NO_ERROR;
    CanTp_RxNSduConfigType const * RxNSduConfigPtr;
    CanTp_RxConnectionPtrType  RxConnectionPtr;
    Std_ReturnType Status=E_NOT_OK;
    CanTp_NSduIdType RxNsduId;
    CanTp_ChannelIdType  ChId;
    CanTp_ChannelStatePtrType ChannelStatePtr;
    
    if ( CANTP_ON != CanTp_InternalState)
    {
        ErrorId = CANTP_E_UNINIT;
    }
    else
    {
        /* check for the received Id */
        for(RxNsduId = 0;RxNsduId< CANTP_NUM_OF_RX_NSDU ; RxNsduId++)
        {
            if (Id == CanTp_RxNSduConfig[RxNsduId].UpperLayerPduId)
            {
                break;
            }
        }
        
        if(CANTP_NUM_OF_RX_NSDU > RxNsduId)
        {
            RxNSduConfigPtr = &CanTp_RxNSduConfig[RxNsduId];
            /* Get channel mode */
            ChId = RxNSduConfigPtr->ChannelId;
            ChannelStatePtr = &CanTp_ChannelState[ChId];
            RxConnectionPtr = &ChannelStatePtr->RxConnection;
            
            CanTp_EnterCriticalSection();
            if(CANTP_RX_WAIT == RxConnectionPtr->ConnectionState)
            {
                if (TP_STMIN == Parameter)
                {
                    /* check the value range . */
                    if ((Value <= CANTP_STMIN_MILLISEC_MAX) || ((Value >= CANTP_STMIN_MICROSEC_MIN) && \
                        (Value <= CANTP_STMIN_MICROSEC_MAX)))
                    {
                        CanTp_DynamicTpParameter[RxNsduId].StMin = Value;
                        Status = E_OK;
                    }
                    else
                    {
                        /* SWS_CanTp_00305 */
                        ErrorId = CANTP_E_PARAM_ID;
                    }
                }
                else if((TP_BS == Parameter ) && (Value <= 255U))
                {
                   CanTp_DynamicTpParameter[RxNsduId].BlockSize = Value;
                   Status = E_OK;
                }
                else
                {
                    /* SWS_CanTp_00305 */
                    ErrorId = CANTP_E_PARAM_ID;
                }
            }                
            CanTp_ExitCriticalSection();
        }
        else
        {
            /* SWS_CanTp_00305 */
            ErrorId = CANTP_E_PARAM_ID;
        }
    }
    
    #if (CANTP_DEV_ERROR_DETECT == STD_ON)
    if (CANTP_E_NO_ERROR != ErrorId)
    {
        (void)CanTp_DetReportError(CANTP_SID_CHANGEPARAMETER, ErrorId);
    }
    #else
    {
        CANTP_IGNORE_UNREF_PARAM(ErrorId);
    }
    #endif
    return Status;
}
#endif

#if ( CANTP_READ_PARAMETER_API == STD_ON)
/******************************************************************************************************************* 
*   @brief      This service is used to read the current value of reception parameters BS and STmin for a specified 
*               N-SDU.
*   @param[in]  Id Identifier of the received N-SDU on which the reception parameter are read.
*   @param[in]  Parameter Specify the parameter to which the value has to be read (BS or STmin).
*   @param[out] Value Pointer where the parameter value will be provided.
*   @return     Std_ReturnType
*               E_OK: request is accepted
*               E_NOT_OK: request is not accepted
*   @ServiceID  0x0b
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
Std_ReturnType CanTp_ReadParameter(PduIdType Id,TPParameterType Parameter,uint16* Value)
{
    uint8 ErrorId = CANTP_E_NO_ERROR;
    CanTp_RxNSduConfigType const * RxNSduConfigPtr;
    CanTp_RxConnectionPtrType  RxConnectionPtr;
    Std_ReturnType Status=E_NOT_OK;
    CanTp_NSduIdType RxNsduId;
    CanTp_ChannelIdType  ChId;
    CanTp_ChannelStatePtrType ChannelStatePtr;
    
    if ( CANTP_ON != CanTp_InternalState)
    {
        ErrorId = CANTP_E_UNINIT;
    }
    else
    {
        /* check for the received Id */
        for(RxNsduId = 0U;RxNsduId< CANTP_NUM_OF_RX_NSDU ; RxNsduId++)
        {
            if (Id == CanTp_RxNSduConfig[RxNsduId].UpperLayerPduId)
            {
                break;
            }
        }
        
        if(CANTP_NUM_OF_RX_NSDU > RxNsduId)
        {
            RxNSduConfigPtr = &CanTp_RxNSduConfig[RxNsduId];
            /* Get channel mode */
            ChId = RxNSduConfigPtr->ChannelId;
            ChannelStatePtr = &CanTp_ChannelState[ChId];
            RxConnectionPtr = &ChannelStatePtr->RxConnection;
            
            CanTp_EnterCriticalSection();
            if(CANTP_RX_WAIT == RxConnectionPtr->ConnectionState)
            {
                /* Update the request parameter */
                if (TP_STMIN == Parameter)
                {
                    #if(CANTP_CHANGE_PARAMETER_API == STD_ON)
                    (* Value) = (uint16)CanTp_DynamicTpParameter[RxNsduId].StMin;
                    #else
                    (* Value) = (uint16)CanTp_RxNSduConfig[RxNsduId].TpSTmin;
                    #endif    
                    Status = E_OK;
                }
                else if(TP_BS == Parameter)
                {
                    #if(CANTP_CHANGE_PARAMETER_API == STD_ON)
                    (* Value) = (uint16)CanTp_DynamicTpParameter[RxNsduId].BlockSize;
                    #else
                    (* Value) = (uint16)CanTp_RxNSduConfig[RxNsduId].BlockSize;
                    #endif
                    Status = E_OK;
                }
                else
                {
                    /* SWS_CanTp_00324 */
                    ErrorId = CANTP_E_PARAM_ID;
                }
            }                
            CanTp_ExitCriticalSection();
        }
        else
        {
            /* SWS_CanTp_00324 */
            ErrorId = CANTP_E_PARAM_ID;
        }
    }
    
    #if (CANTP_DEV_ERROR_DETECT == STD_ON)
    if (CANTP_E_NO_ERROR != ErrorId)
    {
        (void)CanTp_DetReportError(CANTP_SID_READPARAMETER, ErrorId);
    }
    #else
    {
        CANTP_IGNORE_UNREF_PARAM(ErrorId);
    }
    #endif
    return Status;
}
#endif

/****************************************************************************************************************** 
*   @brief      The main function for scheduling the CAN TP.
*   @ServiceID  0x06
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
*   @note       CanTp_MainFunction is involved in handling of CAN TP timeouts N_As, N_Bs, N_Cs, N_Ar, N_Br,
*               N_Cr and STMmin.The function CanTp_MainFunction is affected by configuration parameter 
*               CanTpMainFunctionPeriod
********************************************************************************************************************/
void CanTp_MainFunction(void)
{
    uint8 ErrorId = CANTP_E_NO_ERROR;
    CanTp_ChannelIdType Idx;
    
    if(CANTP_ON != CanTp_InternalState)
    {
        ErrorId = CANTP_E_UNINIT;
    }
    else
    {
        for (Idx = 0U; Idx < CANTP_NUM_OF_CHANNELS; Idx++)
        {
            CanTp_RxChannelProcessing(Idx);
            (void)CanTp_TxChannelProcessing(Idx);
        }
    }
    
    #if (CANTP_DEV_ERROR_DETECT == STD_ON)
    if (CANTP_E_NO_ERROR != ErrorId)
    {
        (void)CanTp_DetReportError(CANTP_SID_MAINFUNCTION, ErrorId);
    }
    #else
    {
        CANTP_IGNORE_UNREF_PARAM(ErrorId);
    }
    #endif
}

/******************************************************************************************************************
*   @brief      Indication of a received I-PDU from a lower layer communication interface module
*   @param[in]  RxPduId     ID of the received I-PDU.
*   @param[in]  PduInfoPtr  Contains the length (SduLength) of the received I-PDU and a pointer to a 
*                           buffer (SduDataPtr) containing the I-PDU.
*   @ServiceID  0x42
*   @Sync/Async Synchronous 
*   @note       The function CanTp_RxIndication shall be callable in interrupt context 
*   @Reentrancy Reentrant for different PduIds. Non Reentrant for the same PduId.
********************************************************************************************************************/
void CanTp_RxIndication(PduIdType RxPduId, const PduInfoType* PduInfoPtr)
{
    CanTp_RxNSduConfigType const *  RxNSduConfigPtr;
    CanTp_TxConnectionPtrType TxConnectionPtr;
    uint8 ErrorId = CANTP_E_NO_ERROR;
    CanTp_NSduIdType RxNsduId;
    CanTp_PciType PciType;
    CanTp_ChannelModeType  ChMode;
    CanTp_ChannelIdType  ChId;
    CanTp_RxPciProcessorFnType PciProcessorFn;
    PduInfoType DataInfoPtr;
    PduInfoType MetaInfoPtr;
    
    if ( CANTP_ON != CanTp_InternalState)
    {
        ErrorId = CANTP_E_UNINIT;
    }
    #if (CANTP_DEV_ERROR_DETECT == STD_ON)                                                                                 
    else if (CANTP_RXNSDU_PDUID_NUM_OF_PDUID <= RxPduId )
    {
        ErrorId = CANTP_E_INVALID_RX_ID;
    }
    else if ((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr))
    {
        ErrorId = CANTP_E_PARAM_POINTER;
    }
    #endif
    else
    {
        /* Get NSdu Id from the RxPduId */
        RxNsduId = CanTp_RxPduToNsduMap[RxPduId];
        /* Get NSdu configuration. */
        if (CANTP_NUM_OF_RX_NSDU > RxNsduId )
        {
            RxNSduConfigPtr = &CanTp_RxNSduConfig[RxNsduId];
            if (CANTP_NUM_OF_CHANNELS > RxNSduConfigPtr->ChannelId )
            {
                /* Get channel mode */
                ChId = RxNSduConfigPtr->ChannelId;
                ChMode = CanTp_ChannelConfig[ChId].ChannelMode;

#if(STD_ON == CANTP_META_DATA_RX_SUPPORT)
                if (CanTp_RxNSduConfig->RxMetaDataLength > 0u) 
                {
                  DataInfoPtr.SduDataPtr = PduInfoPtr->SduDataPtr;
                  DataInfoPtr.SduLength = PduInfoPtr->SduLength - CanTp_RxNSduConfig->RxMetaDataLength;
                  
                  MetaInfoPtr.SduDataPtr = &PduInfoPtr->SduDataPtr[PduInfoPtr->SduLength - CanTp_RxNSduConfig->RxMetaDataLength];
                  MetaInfoPtr.SduLength = CanTp_RxNSduConfig->RxMetaDataLength;
                }
                else
                #endif
                {
                  DataInfoPtr.SduDataPtr = PduInfoPtr->SduDataPtr;
                  DataInfoPtr.SduLength = PduInfoPtr->SduLength;
                }

                if((RxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_STANDARD) &&
                         (RxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_NORMAL_FIXED))
                {
                  /* cert 17225528 - Taking only 4 bits in the first byte. So int to
                   * unsigned int conversion will not cause any issue */
                  PciType = (DataInfoPtr.SduDataPtr[1] >> 4U) & CANTP_PCI_MASK;
                }
                else
                {
                  PciType = (DataInfoPtr.SduDataPtr[0] >> 4U) & CANTP_PCI_MASK;
                }
                
                /* check for valid PCI Type */
                if (PciType < CANTP_NUM_OF_PCI_TYPE)
                {
                    TxConnectionPtr = &CanTp_ChannelState[ChId].TxConnection; 
                    /* process the received SF , FF and CF   */
                    /* Discard the frame if the mode is half duplex and channel transmission in progress else process 
                       the Frame*/
                    if (((CANTP_MODE_HALF_DUPLEX == ChMode ) && \
                        (CANTP_TX_WAIT == TxConnectionPtr->ConnectionState)) || \
                        (CANTP_PCI_TYPE_FC == PciType) || \
                        (CANTP_MODE_FULL_DUPLEX == ChMode ))
                    {
                          /* Invoke PCI Frame processor. */
                          PciProcessorFn = CanTp_FrameProcessorConfig[PciType].RxPciProcessorFn;
                          if (PciProcessorFn != NULL_PTR)
                          {
                              CanTp_EnterCriticalSection();
                              PciProcessorFn(RxNsduId,&DataInfoPtr,&MetaInfoPtr);
                              CanTp_ExitCriticalSection();
                          }
                    }
                }
            } /* RxNSduConfigPtr->ChannelId < CANTP_NUM_OF_CHANNELS */
        } /* RxNsduId < CANTP_NUM_OF_RX_NSDU */
    }
    
    #if (CANTP_DEV_ERROR_DETECT == STD_ON)
    if (CANTP_E_NO_ERROR != ErrorId)
    {
        (void)CanTp_DetReportError(CANTP_SID_RXINDICATION, ErrorId);
    }
    #else
    {
        CANTP_IGNORE_UNREF_PARAM(ErrorId);
    }
    #endif
}

/****************************************************************************************************************** 
*   @brief      The lower layer communication interface module confirms the transmission of an I-PDU.
*   @param[in]  TxPduId     ID of the I-PDU that has been transmitted.
*   @ServiceID  0x40
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
*   @note       The function CanTp_TxConfirmation shall be callable in interrupt context 
********************************************************************************************************************/
void CanTp_TxConfirmation(PduIdType TxPduId, Std_ReturnType result)
{
    uint8 ErrorId = CANTP_E_NO_ERROR;
    CanTp_ChannelIdType  ChId;
    CanTp_NSduIdType NsduId;
    CanTp_TxNSduConfigType const *TxNSduConfigPtr;
    CanTp_ChannelStatePtrType ChannelStatePtr;
    CanTp_TransmitRequestType TransmitRequestType;
    
    if ( CANTP_ON != CanTp_InternalState)
    {
        ErrorId = CANTP_E_UNINIT;
    }
    #if (CANTP_DEV_ERROR_DETECT == STD_ON)                                                                                 
    else if (CANTP_TXNSDU_PDUID_NUM_OF_PDUID <= TxPduId )
    {
        ErrorId = CANTP_E_INVALID_TX_ID;
    }
    #endif
    else
    {
        NsduId = CanTp_TxPduToNsduMap[TxPduId];
        if (CANTP_NUM_OF_TX_NSDU > NsduId)
        {
            TxNSduConfigPtr = &CanTp_TxNSduConfig[NsduId];
            ChId = TxNSduConfigPtr->ChannelId;
            if (CANTP_NUM_OF_CHANNELS > ChId )
            {
                ChannelStatePtr = &CanTp_ChannelState[ChId];
                
                CanTp_EnterCriticalSection();
                TransmitRequestType = ChannelStatePtr->TxRequestType;
                if (CANTP_TRANSMIT_BY_RX_CONNECTION == TransmitRequestType)
                {
                    CanTp_ProcessFlowControlConfirmation(ChannelStatePtr);
                }
                else
                {
                    CanTp_ProcessTxConfirmation(ChannelStatePtr);
                }
                ChannelStatePtr->TxRequestType = CANTP_TRANSMIT_CONNECTION_NONE;
                CanTp_ExitCriticalSection();
            }
        }
    }
    
    #if (CANTP_DEV_ERROR_DETECT == STD_ON)
    if (CANTP_E_NO_ERROR != ErrorId)
    {
        (void)CanTp_DetReportError(CANTP_SID_TXCONFIRMATION, ErrorId);
    }
    #else
    {
        CANTP_IGNORE_UNREF_PARAM(ErrorId);
    }
#endif
    CANTP_IGNORE_UNREF_PARAM(result);
}

/* local function implementations. */
/****************************************************************************************************************** 
*   @brief      This function initializes the CanTp connection channels. 
********************************************************************************************************************/
static void CanTp_InitChannels(void)
{
    CanTp_ChannelIdType Idx;
    CanTp_ChannelStatePtrType ChannelStatePtr;
    
    for (Idx = 0U; Idx < CANTP_NUM_OF_CHANNELS; Idx++)
    {
        ChannelStatePtr = &CanTp_ChannelState[Idx];
        /* Initialize Tx connection of the channel. */
        CanTp_InitTxConnection(ChannelStatePtr,CANTP_NOTIFY_NONE);
        /* Initialize Rx connection of the channel. */
        CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NONE);
    }
    /* upadte the initial value for the dynami TP parameter config */
    #if (CANTP_CHANGE_PARAMETER_API == STD_ON)
    for(Idx = 0; Idx<CANTP_NUM_OF_RX_NSDU;Idx++)
    {
        CanTp_DynamicTpParameter[Idx].StMin = CanTp_RxNSduConfig[Idx].TpSTmin;
        CanTp_DynamicTpParameter[Idx].BlockSize = CanTp_RxNSduConfig[Idx].BlockSize;
        
    }
    #endif
}

/****************************************************************************************************************** 
*   @brief      This function initializes the CanTp channel Rx connection.
*   @param[in]  ChannelStatePtr  Pointer to the CanTP Channel.
*   @param[in]  ConnectionNotificationType  notification status type for the upper layer.
*               CANTP_NOTIFY_OK - notify upper layer with E_OK
*               CANTP_NOTIFY_NOT_OK - notify upper layer with E_NOT_OK
*               CANTP_NOTIFY_NONE - donot notify upper layer 
********************************************************************************************************************/
static void CanTp_InitRxConnection(CanTp_ChannelStatePtrType ChannelStatePtr,
                                    CanTp_TransmitRequestType ConnectionNotificationType)
{
    CanTp_RxConnectionPtrType RxConnectionPtr;
    CanTp_RxNSduConfigType const * RxNSduConfigPtr;
    
    RxConnectionPtr = &ChannelStatePtr->RxConnection;
    /* Initialize the connection properties */
    RxConnectionPtr->ConnectionState        = CANTP_RX_WAIT;
    RxConnectionPtr->BufferState            = BUFREQ_OK;
    RxConnectionPtr->FlowControlStatus      = CANTP_FC_STATUS_NONE;
    RxConnectionPtr->FramePciType           = CANTP_PCI_TYPE_INVALID;
    RxConnectionPtr->Timer                  = 0U;
    RxConnectionPtr->STminValue             = 0U;
    RxConnectionPtr->BlockSizeCounter       = 0U;
    RxConnectionPtr->FlowControlWaitCounter = 0U;
    RxConnectionPtr->SequenceNumber         = 0U;
    RxConnectionPtr->RemainingNsduLength    = 0U;
    RxConnectionPtr->FirstFrameDataLength   = 0U;
    RxConnectionPtr->TotalNsduLength        = 0U;
    RxConnectionPtr->AvailableBuffer        = 0U;
    RxConnectionPtr->DataBufferLength       = 0U;
#if(STD_ON == CANTP_META_DATA_RX_SUPPORT)
    RxConnectionPtr->MetaDataBufferLength   = 0U;
    CanTp_UtilMemSet(&RxConnectionPtr->MetaDataBuffer[0],0U,CANTP_METADATA_MAX_BUFFER_LENGTH);
#endif
    CanTp_UtilMemSet(&RxConnectionPtr->DataBuffer[0],0U,CANTP_MAX_BUFFER_LENGTH);
    
    if ((CANTP_NOTIFY_NONE > ConnectionNotificationType) &&
        (CANTP_NUM_OF_RX_NSDU> RxConnectionPtr->NsduId ))  
    {
        /* get upper layer pdu id */
        RxNSduConfigPtr = &CanTp_RxNSduConfig[RxConnectionPtr->NsduId];
        /* Notify upper layer about the connection status. */
        PduR_CanTpRxIndication(RxNSduConfigPtr->UpperLayerPduId,ConnectionNotificationType);
    }
    
    RxConnectionPtr->NsduId                 = CANTP_INVALID_NSDU;
    /* cert 17225103 - Need only uint8 part */
    /* clear the transmit request */ 
    ChannelStatePtr->TxRequestType &= (CanTp_TransmitRequestType)(~(CANTP_TRANSMIT_BY_RX_CONNECTION));
}

/****************************************************************************************************************** 
*   @brief      This method is used to process receive request and Timeout handling for the CanTp channel connection.
*   @param[in]  ChannelId  CanTP Channel ID value.
********************************************************************************************************************/
static void CanTp_RxChannelProcessing(CanTp_ChannelIdType ChannelId)
{
    CanTp_ChannelStatePtrType ChannelStatePtr;
    CanTp_RxConnectionPtrType RxConnectionPtr;
    CanTp_RxPciBufferProcessorFnType PciBufferProcessorFn;
    CanTp_RxNSduConfigType const * RxNSduConfigPtr;
    
    if (CANTP_NUM_OF_CHANNELS > ChannelId )
    {
        ChannelStatePtr = &CanTp_ChannelState[ChannelId];
        RxConnectionPtr = &ChannelStatePtr->RxConnection;
        
        CanTp_EnterCriticalSection();
        /* check for active channel connection */
        if(CANTP_RX_WAIT != RxConnectionPtr->ConnectionState)
        {   
            if ( 0U != RxConnectionPtr->Timer)
            {
                RxConnectionPtr->Timer--;
                /* Check for timer expiry
                N_Ar - Flow control confirmation timer expiy.
                N_Br - Flow Control transmit wait timer. 
                       1. FF or CF to Flow control 
                       2. FC wait to next Fc transmit
                N_Cs - Consecutive frame wait timeout. */
                if (0U == RxConnectionPtr->Timer)
                {
                    if (( 0U != RxConnectionPtr->FlowControlWaitCounter) &&
                        (CANTP_FC_STATUS_WAIT == RxConnectionPtr->FlowControlStatus))
                    {
                        /* Request Flow control transmission with FC status WAIT. */
                        CanTp_SendFlowControl(ChannelStatePtr);
                    }
                    else
                    {
                        /* Reset connection because of timer expiry. */
                        CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
                    }
                }
                else
                {
                    /* Retry buffer connection */
                    if (CANTP_RX_PROCESSING_FRAME_BUFFER_WAIT == RxConnectionPtr->ConnectionState)
                    {
                       PciBufferProcessorFn = CANTP_UTIL_GET_PCI_BUFFER_PROCESSOR_FUNCTION(
                                                                                    RxConnectionPtr->FramePciType);
                        if (NULL_PTR != PciBufferProcessorFn)
                        {
                            if (CANTP_NUM_OF_RX_NSDU > RxConnectionPtr->NsduId)
                            {
                                /* get upper layer pdu id */
                                RxNSduConfigPtr = &CanTp_RxNSduConfig[RxConnectionPtr->NsduId];
                                /* Invoke PCI frame processor. */
                                PciBufferProcessorFn(ChannelStatePtr,RxNSduConfigPtr->UpperLayerPduId);
                            }
                        }
                    }    
                    else if (CANTP_RX_PROCESSING_FC_TRANSMIT == RxConnectionPtr->ConnectionState)
                    {
                        /* Retry Flow control transmission.*/
                        CanTp_SendFlowControl(ChannelStatePtr);
                    }
                    else 
                    {
                        /* Do Nothing */
                    }
                }
            }
        }
        CanTp_ExitCriticalSection();
    }
}

/****************************************************************************************************************** 
*   @brief      This method is used to get the padded length for CAN/CANFD for the received data length.
*   @param[in]  Length  Received data length.
*   @return     PduLengthType returns the padded data length.
********************************************************************************************************************/
static PduLengthType CanTp_UtilGetPaddingLength(PduLengthType Length)
{
    PduLengthType PaddedLength = 0U;
    uint8   Idx;
    
    /* lookup for the padded length  */
    for (Idx = 0U; Idx < CANTP_NUM_OF_PADDED_DATA_LENGTH_RANGE; Idx++)
    {
        if ((Length >= CanTp_PaddedDataLengthRange[Idx].MinDataLength ) &&
            (Length <= CanTp_PaddedDataLengthRange[Idx].MaxDataLength))
        {
            PaddedLength = CanTp_PaddedDataLengthRange[Idx].PaddedDataLength;
            break;
        }
    }
    
    return PaddedLength;
}

/****************************************************************************************************************** 
*   @brief      This method is used to decode and validate the data length received in the PCI frame.
*   @param[in]  PaddingActivationType  padding support enabled/disabled.
*               CANTP_OFF - Padding is supported. 
*               CANTP_ON  - Padding is not supported.
*   @param[in]  PciType  value for the PCI type.
*               CANTP_PCI_TYPE_SF - PCI type is Single frame. 
*               CANTP_PCI_TYPE_FF - PCI type is First frame.
*               CANTP_PCI_TYPE_CF - PCI type is Consecutive frame. 
*               CANTP_PCI_TYPE_FC - PCI type is Flow control frame. 
*   @param[in]  PduInfoPtr  pdu info of the received data.
*   @param[out] ReceivedNsduLengthPtr  pdu info of the received data.
*   @return     Std_ReturnType returns whether the data received is valid or not.
*               E_OK        - valid data is received and \ReceivedNsduLengthPtr contains the Nsdu total length if the
*                             Single/First frame else \ReceivedNsduLengthPtr is 0.
*               E_NOT_OK    - Not a valid data length for the PCI request.
********************************************************************************************************************/
static Std_ReturnType CanTp_CheckAndDecodeRxDl(CanTp_RxNSduConfigType const *  RxNSduConfigPtr,
                                               CanTp_PciType PciType, const PduInfoType* PduInfoPtr,
                                               PduLengthType * ReceivedNsduLengthPtr)
{
    Std_ReturnType  Result = (uint8)E_NOT_OK;
    PduLengthType   MinLength = 0U;    
    PduLengthType   PaddedLength;
    PduLengthType   AllowedMaxNsduLength=0;
    PduLengthType   AllowedMinNsduLength=0;
    PduLengthType   ReceivedDataLength;
    #if(CANTP_FLEXIBLE_DATA_RATE_SUPPORT == STD_ON)
    uint8           Index = 0U;    
    #endif
    #if (CANTP_DEV_ERROR_DETECT == STD_ON)  
    uint8 ErrorId = CANTP_E_NO_ERROR;
    #endif
    uint8 Addr_Offset = 0U;
    
    if((RxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_STANDARD) &&
          (RxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_NORMAL_FIXED))
    {
      Addr_Offset = 0x01u;
    }
    else 
    {
      Addr_Offset = 0x00u;              
    }   
    
    ReceivedDataLength = PduInfoPtr->SduLength;
    PaddedLength = CanTp_UtilGetPaddingLength(ReceivedDataLength);
    
    /* Get the minimum length supported by the PCI */
    if (PciType < CANTP_NUM_OF_PCI_TYPE)
    {
        #if(CANTP_FLEXIBLE_DATA_RATE_SUPPORT == STD_ON)
        if ( 8U < ReceivedDataLength)
        {
            MinLength = CanTp_PciLengthConfig[PciType].PciCanFdMinLength;
        }
        else
        #endif
        {
            MinLength = CanTp_PciLengthConfig[PciType].PciCanMinLength;
        }
        /* check if padding is supported. */
        if (CANTP_ON == RxNSduConfigPtr->RxPaddingActivation)
        {
            /* If padding enabled and length mismatch discard the frame. */
            if (PaddedLength == ReceivedDataLength)
            {
                Result = (uint8)E_OK;
            }
            #if (CANTP_DEV_ERROR_DETECT == STD_ON)    
            else
            {
                ErrorId = CANTP_E_PADDING;
            }
            #endif
        }
        else
        {                       
            /* If padding not supported , check if the received data length is a valid data length for processing the 
            frame. */
            if (ReceivedDataLength >= MinLength)
            {
                Result = (uint8)E_OK;
            }
        }
    }
    
    if ((uint8)E_NOT_OK != Result)
    {
        Result = (uint8)E_NOT_OK; /* set to E_NOT_OK to handle false case in below check */
        #if(CANTP_FLEXIBLE_DATA_RATE_SUPPORT == STD_ON)
        if (8U < ReceivedDataLength)
        {              
            if(CANTP_PCI_TYPE_SF == PciType)
            {
                /* Get the received Nsdu data length if the CAN FD Single frame format is valid. */
                if (0U == PduInfoPtr->SduDataPtr[Addr_Offset]) 
                {
                    /* get array index of the padded range for CANFD SF frame*/
                    /* lookup for the padded length Index */
                    for (Index = 0U; Index < CANTP_NUM_OF_PADDED_DATA_LENGTH_RANGE; Index++)
                    {
                        if ((PaddedLength == CanTp_PaddedDataLengthRange[Index].PaddedDataLength) &&
                            (PaddedLength >8U))
                        {
                            AllowedMinNsduLength = CanTp_PaddedDataLengthRange[Index].MinDataLength;
                            break;
                        }
                    }
                    /* Allowed SF_DL length for Normal addressing mode
                        12 - 8 ≤ SF_DL ≤ 10  ; 16 - 11 ≤ SF_DL ≤ 14 ; 20 - 15 ≤ SF_DL ≤ 18 ; 24 - 19 ≤ SF_DL ≤ 22 ;
                        32 - 23 ≤ SF_DL ≤ 30 ; 48 - 31 ≤ SF_DL ≤ 46 ; 64 - 47 ≤ SF_DL ≤ 62
                       Allowed SF_DL length for mixed or extended addressing mode
                       12 - 7 ≤ SF_DL ≤ 9  ; 16 - 10 ≤ SF_DL ≤ 13 ; 20 - 14 ≤ SF_DL ≤ 17 ; 24 - 18 ≤ SF_DL ≤ 21 ;
                       32 - 22 ≤ SF_DL ≤ 29 ; 48 - 30 ≤ SF_DL ≤ 45 ; 64 - 46 ≤ SF_DL ≤ 61
                    */
                    if (Index < CANTP_NUM_OF_PADDED_DATA_LENGTH_RANGE)
                    {
                        if ((CANTP_STANDARD != RxNSduConfigPtr->RxNsduAddressingFormatType) && 
                            (CANTP_NORMAL_FIXED != RxNSduConfigPtr->RxNsduAddressingFormatType))
                        {
                            if (PaddedLength == 12U)
                            {
                                AllowedMinNsduLength = AllowedMinNsduLength - 2U;
                            }
                            else
                            {
                                AllowedMinNsduLength = AllowedMinNsduLength - 3U;
                            }
                            AllowedMaxNsduLength = PaddedLength-3U; /* mixed or extended addressing mode */
                        }
                        else
                        {
                            if (PaddedLength == 12U)
                            {
                                AllowedMinNsduLength = AllowedMinNsduLength - 1U;
                            }
                            else
                            {
                                AllowedMinNsduLength = AllowedMinNsduLength - 2U;
                            }
                            AllowedMaxNsduLength = PaddedLength-2U; /* normal addressing mode */
                        }
                        
                        (*ReceivedNsduLengthPtr) = (PduLengthType)PduInfoPtr->SduDataPtr[Addr_Offset+1];
                            
                        if (((*ReceivedNsduLengthPtr) >= AllowedMinNsduLength) &&
                            ((*ReceivedNsduLengthPtr) <= AllowedMaxNsduLength))
                        {
                            Result = (uint8)E_OK;
                        }
                    }
                }
            }
            else if(CANTP_PCI_TYPE_FF == PciType)
            {
                if ((FALSE != CANTP_UTIL_IS_REQTYPE_PHYSICAL(RxNSduConfigPtr->RxTaType)))
                {
                    /* Get the received Nsdu data length if the CAN FD First frame format is valid. */
                    if ((0U == (PduInfoPtr->SduDataPtr[Addr_Offset] & CANTP_FF_DL_BYTE0_MASK)) && 
                         (0U == PduInfoPtr->SduDataPtr[Addr_Offset+1]))
                    {
                        (*ReceivedNsduLengthPtr)  = (PduLengthType)(((PduLengthType)PduInfoPtr->SduDataPtr[Addr_Offset+2])<<24U);
                        (*ReceivedNsduLengthPtr)  |= (PduLengthType)(((PduLengthType)PduInfoPtr->SduDataPtr[Addr_Offset+3])<<16U);
                        (*ReceivedNsduLengthPtr)  |= (PduLengthType)(((PduLengthType)PduInfoPtr->SduDataPtr[Addr_Offset+4])<<8U);
                        (*ReceivedNsduLengthPtr)  |= (PduLengthType)((PduLengthType)PduInfoPtr->SduDataPtr[Addr_Offset+5]);
                        AllowedMinNsduLength = PaddedLength - 6U;
                        if((*ReceivedNsduLengthPtr) <= 4095U)
                        {
                            Result = (uint8)E_NOT_OK;
                        }
                        else
                        {
                            Result = (uint8)E_OK;
                        }
                    }
                    else
                    {
                        /* received byte is less than the or equal to 4095 */
                        (*ReceivedNsduLengthPtr)  = (PduLengthType)(((PduLengthType)PduInfoPtr->SduDataPtr[Addr_Offset+1]) & \
                                                                        CANTP_FF_DL_BYTE1_MASK);
                        (*ReceivedNsduLengthPtr) |= (PduLengthType)((((PduLengthType)PduInfoPtr->SduDataPtr[Addr_Offset]) & \
                                                        CANTP_FF_DL_BYTE0_MASK) << 8U);
                        AllowedMinNsduLength = PaddedLength - 2U;
                        Result = (uint8)E_OK;
                    }
                    /* CAN FD first frame should be of full length 8,12,16,20,24,32,48,64 else it is not a valid FF. */
                    if ((PaddedLength == ReceivedDataLength ) && (E_NOT_OK != Result))
                    {   
                        if ((CANTP_STANDARD != RxNSduConfigPtr->RxNsduAddressingFormatType) && 
                                (CANTP_NORMAL_FIXED != RxNSduConfigPtr->RxNsduAddressingFormatType))
                        {
                            AllowedMinNsduLength = AllowedMinNsduLength - 1U; /* mixed or extended addressing mode */
                        }
                        
                        if ((*ReceivedNsduLengthPtr) > AllowedMinNsduLength )
                        {
                            Result = (uint8)E_OK;
                        }
                    }
                    #if (CANTP_DEV_ERROR_DETECT == STD_ON)    
                    else
                    {
                        ErrorId = CANTP_E_PADDING;
                    }
                    #endif
                }
                else
                {
                    /* Check for functional addressing - SWS_CanTp_00383 */
                    Result = E_NOT_OK;
                }
            }
            else
            {
                (*ReceivedNsduLengthPtr) = ReceivedDataLength;
                Result = (uint8)E_OK;
            }
        }
        else
        #endif
        {            
            if (CANTP_PCI_TYPE_SF == PciType)
            {
                (*ReceivedNsduLengthPtr) = (PduLengthType)((PduLengthType)PduInfoPtr->SduDataPtr[Addr_Offset]) & CANTP_SF_DL_MASK;
                if ((CANTP_STANDARD != RxNSduConfigPtr->RxNsduAddressingFormatType) && 
                    (CANTP_NORMAL_FIXED != RxNSduConfigPtr->RxNsduAddressingFormatType))
                {
                    AllowedMaxNsduLength = PaddedLength - 2U; /* mixed or extended addressing mode */
                }
                else
                {
                    AllowedMaxNsduLength = PaddedLength- 1U; /* normal addressing mode */
                }
                if (((*ReceivedNsduLengthPtr)>0U) && ((*ReceivedNsduLengthPtr) <= AllowedMaxNsduLength))
                {
                    Result = (uint8)E_OK;
                }
            }
            else if(CANTP_PCI_TYPE_FF == PciType)
            {
                if ((FALSE != CANTP_UTIL_IS_REQTYPE_PHYSICAL(RxNSduConfigPtr->RxTaType)))
                {
                    (*ReceivedNsduLengthPtr)  = (PduLengthType)(((PduLengthType)PduInfoPtr->SduDataPtr[Addr_Offset+1U]) & \
                                                    CANTP_FF_DL_BYTE1_MASK);
                    (*ReceivedNsduLengthPtr) |= (PduLengthType)((((PduLengthType)PduInfoPtr->SduDataPtr[Addr_Offset]) & \
                                                    CANTP_FF_DL_BYTE0_MASK) << 8U);
                    /* received FF length must be eight. */
                    if (PaddedLength == ReceivedDataLength)
                    {   
                        if ((CANTP_STANDARD != RxNSduConfigPtr->RxNsduAddressingFormatType) &&
                            (CANTP_NORMAL_FIXED != RxNSduConfigPtr->RxNsduAddressingFormatType))
                        {
                            AllowedMinNsduLength = PaddedLength-3U; /* mixed or extended addressing mode */
                        }
                        else
                        {
                            AllowedMinNsduLength = PaddedLength-2U; /* normal addressing mode */
                        }
                        /* SRAJAGO6:Ln: 1502 corrected for 1545072: J32V:NW layer test using CAN Stress tool and Canoe software tool V2.8.91
                           Flow Control should not be sent by Cluster for a frame 10 07 xx xx xx xx xx xx
                           */
                        if ((*ReceivedNsduLengthPtr) > (AllowedMinNsduLength + 1U) )
                        {
                            Result = (uint8)E_OK;
                        }
                    }
                }
                else
                {
                    /* Check for functional addressing - SWS_CanTp_00383 */
                    Result = E_NOT_OK;
                }
            }
            else
            {
                (*ReceivedNsduLengthPtr) = ReceivedDataLength;
                Result = (uint8)E_OK;
            }
        }
    }
    
    #if (CANTP_DEV_ERROR_DETECT == STD_ON)
    if (CANTP_E_NO_ERROR != ErrorId)
    {
        (void)CanTp_DetReportError(CANTP_SID_RXINDICATION, ErrorId);
    }
    #endif
    
    return Result;
}

/****************************************************************************************************************** 
*   @brief      This method is used to process the received single frame.
*   @param[in]  RxNsduId  received NSdu id value.
*   @param[in]  PduInfoPtr Contains the length (SduLength) of the received I-PDU and a pointer to a 
*                          buffer (SduDataPtr) containing the I-PDU.
********************************************************************************************************************/
static void CanTp_RxSingleFrameProcessor(CanTp_NSduIdType RxNsduId, const PduInfoType* DataInfoPtr, const PduInfoType* MetaInfoPtr)
{
    CanTp_RxNSduConfigType const *RxNSduConfigPtr;
    CanTp_RxConnectionPtrType RxConnectionPtr;
    CanTp_ChannelStatePtrType ChannelStatePtr;
    BufReq_ReturnType ReturnType;
    PduInfoType PduInfo;
    PduLengthType NSduLength=0U;
    uint8 Addr_Offset = 0u;
    
    if (CANTP_NUM_OF_RX_NSDU > RxNsduId)
    {
         /* Get NSdu configuration. */
        RxNSduConfigPtr = &CanTp_RxNSduConfig[RxNsduId];
        if (CANTP_NUM_OF_CHANNELS > RxNSduConfigPtr->ChannelId )
        {
            ChannelStatePtr = &CanTp_ChannelState[RxNSduConfigPtr->ChannelId];
            RxConnectionPtr = &ChannelStatePtr->RxConnection;
            
            if((RxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_STANDARD) &&
                  (RxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_NORMAL_FIXED))
            {
                Addr_Offset = 0x01u;
            }
            else 
            {
                Addr_Offset = 0x00u;              
            }              

            if( CANTP_RX_WAIT != RxConnectionPtr->ConnectionState )
            {
                /* If Segmented Receive in progress and SF N-PDU is received , then Terminate the current reception, 
                   report an indication, with parameter Result set to E_NOT_OK, to the upper layer, and process the 
                   SF N-PDU as the start of a new reception. */
                 /* Init Receive connection */
                CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
            }
         
            if ((uint8)E_OK == CanTp_CheckAndDecodeRxDl(RxNSduConfigPtr,CANTP_PCI_TYPE_SF,DataInfoPtr,&NSduLength))
            {
                /* Reinitialize connection. */
                CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NONE);
                /* set connection properties for the single frame */
                RxConnectionPtr = &ChannelStatePtr->RxConnection;
                RxConnectionPtr->ConnectionState  = CANTP_RX_PROCESSING_FRAME;
                RxConnectionPtr->FramePciType     = CANTP_PCI_TYPE_SF;
                RxConnectionPtr->NsduId = RxNsduId;
                RxConnectionPtr->AvailableBuffer = 0U;
                RxConnectionPtr->TotalNsduLength  = NSduLength;
                RxConnectionPtr->DataBufferLength = NSduLength;
                
                #if (CANTP_FLEXIBLE_DATA_RATE_SUPPORT == STD_ON)
                if (DataInfoPtr->SduLength > 8U)
                {
                    CanTp_UtilMemCpy(&RxConnectionPtr->DataBuffer[0],&DataInfoPtr->SduDataPtr[Addr_Offset+0x02u],
                                        RxConnectionPtr->DataBufferLength);
                }
                else
                #endif
                {
                    CanTp_UtilMemCpy(&RxConnectionPtr->DataBuffer[0],&DataInfoPtr->SduDataPtr[Addr_Offset+0x01u],
                                        RxConnectionPtr->DataBufferLength);
                }

#if(STD_ON == CANTP_META_DATA_RX_SUPPORT)
                if(RxNSduConfigPtr->RxMetaDataLength != 0)
                {
                    RxConnectionPtr->MetaDataBufferLength = RxNSduConfigPtr->RxMetaDataLength;
                    CanTp_UtilMemCpy(&RxConnectionPtr->MetaDataBuffer[0],&MetaInfoPtr->SduDataPtr[0],
                                            RxConnectionPtr->MetaDataBufferLength);                 
                    CanTp_UtilMemCpy(&RxConnectionPtr->DataBuffer[RxConnectionPtr->DataBufferLength],&MetaInfoPtr->SduDataPtr[0],
                                            MetaInfoPtr->SduLength);
                                        
                    /* set pdu info */
                    PduInfo.SduLength = RxConnectionPtr->DataBufferLength + MetaInfoPtr->SduLength;
                    PduInfo.SduDataPtr = &RxConnectionPtr->DataBuffer[0];   

                    if(TRUE == RxNSduConfigPtr->IsDataInStartOfReception)
                    {
                        ReturnType = PduR_CanTpStartOfReception(RxNSduConfigPtr->UpperLayerPduId,&PduInfo,
                                                                PduInfo.SduLength,&RxConnectionPtr->AvailableBuffer);
                    }
                    else
                    {
                        ReturnType = PduR_CanTpStartOfReception(RxNSduConfigPtr->UpperLayerPduId,MetaInfoPtr,
                                                                MetaInfoPtr->SduLength,&RxConnectionPtr->AvailableBuffer);
                    }                                       
                }
                else
#endif
                {
                    /* set pdu info */
                    PduInfo.SduLength = RxConnectionPtr->DataBufferLength;
                    PduInfo.SduDataPtr = &RxConnectionPtr->DataBuffer[0];
                        RxConnectionPtr->AvailableBuffer = 0U;
                    if(TRUE == RxNSduConfigPtr->IsDataInStartOfReception)
                    {
                        ReturnType = PduR_CanTpStartOfReception(RxNSduConfigPtr->UpperLayerPduId,&PduInfo,
                                                                PduInfo.SduLength,&RxConnectionPtr->AvailableBuffer);
                    }
                    else
                    {
                        ReturnType = PduR_CanTpStartOfReception(RxNSduConfigPtr->UpperLayerPduId,NULL_PTR,
                                                                PduInfo.SduLength,&RxConnectionPtr->AvailableBuffer);
                    }                                       
                }

                if ((BUFREQ_OK == ReturnType) || (BUFREQ_E_BUSY == ReturnType))
                {
                    RxConnectionPtr->Timer = 2U; /*  Update timer to retry at task level once for BUFREQ_E_BUSY. */
                    RxConnectionPtr->ConnectionState = CANTP_RX_PROCESSING_FRAME_BUFFER_WAIT;
                    CanTp_FrameProcessorConfig[CANTP_PCI_TYPE_SF].RxPciBufferProcessorFn(ChannelStatePtr,
                                                                                 RxNSduConfigPtr->UpperLayerPduId);
                }
                else
                {
                     /* Init Receive connection but no upper layer notification required.
                     \ SWS_CanTp_00081 */
                    CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NONE);
                }
            }
            else
            {
                /* Discard requested frame for invalid length*/
            }
        }
    }
}

/******************************************************************************************************************* 
*   @brief      This method is used to process the upper layer buffer request and notification for single frame.
*   @param[in]  ChannelStatePtr pointer to channel connection.
*   @param[in]  RxUpperLayerId  PDU Id value of upper layer.
********************************************************************************************************************/
static void CanTp_RxSingleFrameBufferProcessor(CanTp_ChannelStatePtrType ChannelStatePtr,PduIdType UpperlayerId)
{
    PduInfoType                 PduInfo;
    CanTp_RxConnectionPtrType   RxConnectionPtr;
    
    RxConnectionPtr = &ChannelStatePtr->RxConnection;
    if (BUFREQ_E_BUSY == RxConnectionPtr->BufferState)
    {
        PduInfo.SduLength = 0U;
        PduInfo.SduDataPtr = NULL_PTR;
        RxConnectionPtr->AvailableBuffer = 0U;
        /* if buffer is busy get available buffer from the upper layer. */
        RxConnectionPtr->BufferState = PduR_CanTpCopyRxData(UpperlayerId,
                                                            &PduInfo,
                                                            &RxConnectionPtr->AvailableBuffer);
    }
    
    if ((BUFREQ_OK == RxConnectionPtr->BufferState) && \
        ((RxConnectionPtr->AvailableBuffer)>= RxConnectionPtr->DataBufferLength ))
    {
        /* if the available buffer is enough for the received message then, call copy data. */
        PduInfo.SduLength = RxConnectionPtr->DataBufferLength;    
        PduInfo.SduDataPtr = RxConnectionPtr->DataBuffer;
        RxConnectionPtr->BufferState = PduR_CanTpCopyRxData(UpperlayerId,
                                                            &PduInfo,
                                                            &RxConnectionPtr->AvailableBuffer);
         
        if (BUFREQ_OK == RxConnectionPtr->BufferState)
        {
            /* if data copied successfully , then notify upper layer about successful reception. */
            CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_OK);
        }
        else
        {
            if (BUFREQ_E_BUSY != RxConnectionPtr->BufferState)
            {
                /* if data copied successfully , then notify upper layer about successful reception. */
                CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
            }
        }
        
    }
    else if(BUFREQ_E_BUSY == RxConnectionPtr->BufferState)
    {
        /* Retry request */
    }
    else
    {
        /* Init Receive connection and notify the upper layer with result E_NOT_OK.
        SWS_CanTp_00339 */
        CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
    }
}

/****************************************************************************************************************** 
*   @brief      This method is used to process the received first frame.
*   @param[in]  RxNsduId  received NSdu id value.
*   @param[in]  PduInfoPtr Contains the length (SduLength) of the received I-PDU and a pointer to a 
*                          buffer (SduDataPtr) containing the I-PDU.
********************************************************************************************************************/
static void CanTp_RxFirstFrameProcessor(CanTp_NSduIdType RxNsduId, const PduInfoType* DataInfoPtr, const PduInfoType* MetaInfoPtr)
{
    
    CanTp_RxNSduConfigType const * RxNSduConfigPtr;
    CanTp_RxConnectionPtrType RxConnectionPtr;
    CanTp_ChannelStatePtrType ChannelStatePtr;
    PduInfoType PduInfo;
    PduLengthType NSduLength=0U;
    uint8 Addr_Offset=0u;
    
    if (CANTP_NUM_OF_RX_NSDU > RxNsduId)
    {
         /* Get NSdu configuration. */
        RxNSduConfigPtr = &CanTp_RxNSduConfig[RxNsduId];
        if (CANTP_NUM_OF_CHANNELS > RxNSduConfigPtr->ChannelId)
        {
            ChannelStatePtr = &CanTp_ChannelState[RxNSduConfigPtr->ChannelId];
            RxConnectionPtr = &ChannelStatePtr->RxConnection;
            
            if((RxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_STANDARD) &&
                  (RxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_NORMAL_FIXED))
            {
                Addr_Offset = 0x01u;
            }
            else 
            {
                Addr_Offset = 0x00u;              
            }
            
            if( CANTP_RX_WAIT != RxConnectionPtr->ConnectionState )
            {
                /* If Segmented Receive in progress and SF N-PDU is received , then Terminate the current reception, 
                   report an indication, with parameter Result set to E_NOT_OK, to the upper layer, and process the 
                   SF N-PDU as the start of a new reception. */
                 /* Init Receive connection */
                CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
            }

            if ((uint8)E_OK == CanTp_CheckAndDecodeRxDl(RxNSduConfigPtr,CANTP_PCI_TYPE_FF,DataInfoPtr,&NSduLength))
            {
                 /* Reinitialize connection. */
                CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NONE);
                 /* set connection properties for First frame. */
                RxConnectionPtr->ConnectionState      = CANTP_RX_PROCESSING_FRAME;
                RxConnectionPtr->FramePciType         = CANTP_PCI_TYPE_FF;
                RxConnectionPtr->SequenceNumber       = CANTP_CF_FIRST_SN;
                RxConnectionPtr->TotalNsduLength      = NSduLength;
                RxConnectionPtr->RemainingNsduLength  = NSduLength;
                RxConnectionPtr->FirstFrameDataLength = DataInfoPtr->SduLength;
                RxConnectionPtr->BlockSizeCounter = RxNSduConfigPtr->BlockSize;
                RxConnectionPtr->NsduId = RxNsduId;
                /* set timer for buffer retry/Flow control retry .On this timer expiry either FC should be sent or 
                connection must be reset. */
                RxConnectionPtr->Timer             = RxNSduConfigPtr->Nbr;
                /* trigger start of reception */
                RxConnectionPtr->AvailableBuffer = 0U;
                #if (CANTP_FLEXIBLE_DATA_RATE_SUPPORT == STD_ON)
                if (8U < DataInfoPtr->SduLength )
                {
                    if (RxConnectionPtr->TotalNsduLength > 4095U)
                    {
                        RxConnectionPtr->DataBufferLength = (DataInfoPtr->SduLength) - 6U;
                        CanTp_UtilMemCpy(&RxConnectionPtr->DataBuffer[0], &DataInfoPtr->SduDataPtr[Addr_Offset+0x06u],
                            RxConnectionPtr->DataBufferLength);
                    }
                    else
                    {
                        RxConnectionPtr->DataBufferLength = DataInfoPtr->SduLength - 2U;
                        CanTp_UtilMemCpy(&RxConnectionPtr->DataBuffer[0], &DataInfoPtr->SduDataPtr[Addr_Offset+0x02u],
                            RxConnectionPtr->DataBufferLength);
                    }
                    
                }
                else
                #endif
                {
                    RxConnectionPtr->DataBufferLength     = DataInfoPtr->SduLength-2U;
                    CanTp_UtilMemCpy(&RxConnectionPtr->DataBuffer[0],&DataInfoPtr->SduDataPtr[Addr_Offset+0x02u],
                                                                        RxConnectionPtr->DataBufferLength);
                }
                
#if(STD_ON == CANTP_META_DATA_RX_SUPPORT)
                if(RxNSduConfigPtr->RxMetaDataLength != 0)
                {
                    RxConnectionPtr->MetaDataBufferLength = RxNSduConfigPtr->RxMetaDataLength;
                    CanTp_UtilMemCpy(&RxConnectionPtr->MetaDataBuffer[0],&MetaInfoPtr->SduDataPtr[0],
                                            RxConnectionPtr->MetaDataBufferLength); 
                    CanTp_UtilMemCpy(&RxConnectionPtr->DataBuffer[RxConnectionPtr->DataBufferLength],&MetaInfoPtr->SduDataPtr[0],
                                            MetaInfoPtr->SduLength);
                                        
                    /* set pdu info */
                    PduInfo.SduLength = RxConnectionPtr->DataBufferLength + MetaInfoPtr->SduLength;
                    PduInfo.SduDataPtr = &RxConnectionPtr->DataBuffer[0];   
                    
                    if(TRUE == RxNSduConfigPtr->IsDataInStartOfReception)
                    {
                        RxConnectionPtr->BufferState = PduR_CanTpStartOfReception(RxNSduConfigPtr->UpperLayerPduId,&PduInfo,
                                                                RxConnectionPtr->TotalNsduLength + MetaInfoPtr->SduLength,&RxConnectionPtr->AvailableBuffer);
                    }
                    else
                    {
                        RxConnectionPtr->BufferState = PduR_CanTpStartOfReception(RxNSduConfigPtr->UpperLayerPduId,MetaInfoPtr,
                                                                MetaInfoPtr->SduLength,&RxConnectionPtr->AvailableBuffer);
                    }
                }               
                else
#endif
                {
                    /* update the pduInfo for the request */
                    PduInfo.SduLength  = RxConnectionPtr->DataBufferLength;
                    PduInfo.SduDataPtr = &RxConnectionPtr->DataBuffer[0];
                    
                    if(TRUE == RxNSduConfigPtr->IsDataInStartOfReception)
                    {
                        RxConnectionPtr->BufferState = PduR_CanTpStartOfReception(RxNSduConfigPtr->UpperLayerPduId,&PduInfo,
                                                                RxConnectionPtr->TotalNsduLength,&RxConnectionPtr->AvailableBuffer);
                    }
                    else
                    {
                        RxConnectionPtr->BufferState = PduR_CanTpStartOfReception(RxNSduConfigPtr->UpperLayerPduId,NULL_PTR,
                                                                RxConnectionPtr->TotalNsduLength,&RxConnectionPtr->AvailableBuffer);
                    }
                }
 
                if (BUFREQ_OK == RxConnectionPtr->BufferState)
                {
                    RxConnectionPtr->ConnectionState = CANTP_RX_PROCESSING_FRAME_BUFFER_WAIT;
                    /* process the frame buffer request */
                    CanTp_FrameProcessorConfig[CANTP_PCI_TYPE_FF].RxPciBufferProcessorFn(ChannelStatePtr,
                                                                                RxNSduConfigPtr->UpperLayerPduId);
                }
                else if(BUFREQ_E_OVFL == RxConnectionPtr->BufferState)
                {
                    /* Buffer overflow occured trigger FC with OVERFLOW status */
                    RxConnectionPtr->ConnectionState  = CANTP_RX_PROCESSING_FC_TRANSMIT;
                    RxConnectionPtr->FlowControlStatus = CANTP_FC_STATUS_OVERFLOW;
                    CanTp_SendFlowControl(ChannelStatePtr);
                }
                else if ( BUFREQ_E_BUSY == RxConnectionPtr->BufferState)
                {
                    RxConnectionPtr->ConnectionState   = CANTP_RX_PROCESSING_FC_TRANSMIT;
                    RxConnectionPtr->FlowControlStatus = CANTP_FC_STATUS_WAIT;
                    RxConnectionPtr->FlowControlWaitCounter = RxNSduConfigPtr->RxWftMax;
                    CanTp_SendFlowControl(ChannelStatePtr);
                }
                else/* BUFREQ_E_NOT_OK */
                {
                     /* Init Receive connection but no upper layer notification required.
                     SWS_CanTp_00081 */
                    CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NONE);
                }
            } /* else Discard the frame */
        }
    }
}

/******************************************************************************************************************* 
*   @brief      This method is used to process the upper layer buffer request and notification for first frame.
*   @param[in]  ChannelStatePtr pointer to channel connection.
*   @param[in]  RxUpperLayerId  PDU Id value of upper layer.
********************************************************************************************************************/
static void CanTp_RxFirstFrameBufferProcessor(CanTp_ChannelStatePtrType ChannelStatePtr,PduIdType RxUpperLayerId)
{
    PduInfoType             PduInfo;
    CanTp_RxConnectionPtrType RxConnectionPtr;
    PduLengthType BlockSizeInBytes;
    
    RxConnectionPtr = &ChannelStatePtr->RxConnection;
    RxConnectionPtr->FlowControlStatus  = CANTP_FC_STATUS_NONE; 
    if (BUFREQ_E_BUSY == RxConnectionPtr->BufferState)
    {
        PduInfo.SduLength = 0U;
        PduInfo.SduDataPtr = NULL_PTR;
        RxConnectionPtr->AvailableBuffer = 0U;
         /* if buffer is busy get available buffer from the upper layer. */
        RxConnectionPtr->BufferState = PduR_CanTpCopyRxData(RxUpperLayerId,
                                                            &PduInfo,
                                                            &RxConnectionPtr->AvailableBuffer);
    }
    
    if ((BUFREQ_OK == RxConnectionPtr->BufferState) && \
        ((RxConnectionPtr->AvailableBuffer) >= RxConnectionPtr->DataBufferLength ))
    {
        PduInfo.SduLength = RxConnectionPtr->DataBufferLength;    
        PduInfo.SduDataPtr = RxConnectionPtr->DataBuffer;
        RxConnectionPtr->BufferState = PduR_CanTpCopyRxData(RxUpperLayerId,
                                                            &PduInfo,
                                                            &RxConnectionPtr->AvailableBuffer);
        
        if (BUFREQ_OK == RxConnectionPtr->BufferState)
        {
            RxConnectionPtr->RemainingNsduLength -= RxConnectionPtr->DataBufferLength;
            BlockSizeInBytes = CanTp_UtilGetBlockSizeInBytes(RxConnectionPtr);
            /* if buffer available for the block size send FC with CTS else send FC with WAIT */
            if ((RxConnectionPtr->AvailableBuffer >= BlockSizeInBytes) ||
                (RxConnectionPtr->AvailableBuffer >= RxConnectionPtr->RemainingNsduLength))
            {
                RxConnectionPtr->FlowControlStatus = CANTP_FC_STATUS_CTS;
            }
            else
            {
                /* TODO : check Initialization of flow control wait count */
                RxConnectionPtr->FlowControlStatus = CANTP_FC_STATUS_WAIT;
            }
        }
        
    }
    if (BUFREQ_E_BUSY == RxConnectionPtr->BufferState)
    {
        /* if overflow detected, send with FC wait response. */
        RxConnectionPtr->FlowControlStatus = CANTP_FC_STATUS_WAIT;
    }
    else if(BUFREQ_E_OVFL == RxConnectionPtr->BufferState)
    {
        /* if overflow detected, send with buffer overflow response. */
        RxConnectionPtr->FlowControlStatus = CANTP_FC_STATUS_OVERFLOW;
    }
    else /*  BUFREQ_E_NOT_OK or RxConnectionPtr->AvailableBuffer less than FF data length */
    {
        if (BUFREQ_OK != RxConnectionPtr->BufferState )
        {
            /* Init Receive connection and notify the uppper layer with result E_NOT_OK.
            SWS_CanTp_00339 */
            CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
        }
    }
    
    if (CANTP_FC_STATUS_NONE != RxConnectionPtr->FlowControlStatus)
    { 
        /* If flow control transmit requested , update connection state and transmit message. */
        RxConnectionPtr->ConnectionState = CANTP_RX_PROCESSING_FC_TRANSMIT;
        CanTp_SendFlowControl(ChannelStatePtr);
    }
}

/******************************************************************************************************************* 
*   @brief      This method is used to process the received consecutive frame.
*   @param[in]  RxNsduId  received NSdu id value.
*   @param[in]  PduInfoPtr Contains the length (SduLength) of the received I-PDU and a pointer to a 
*                          buffer (SduDataPtr) containing the I-PDU.
********************************************************************************************************************/
static void CanTp_RxConsecutiveFrameProcessor(CanTp_NSduIdType RxNsduId, const PduInfoType* DataInfoPtr, const PduInfoType* MetaInfoPtr)
{
    
    CanTp_RxNSduConfigType const * RxNSduConfigPtr;
    CanTp_RxConnectionPtrType RxConnectionPtr;
    CanTp_ChannelStatePtrType ChannelStatePtr;
    PduLengthType ReceivedDataLength;
    boolean IsRxLengthValid = FALSE;
    uint8 SeqNum;
    uint8 Addr_Offset=0u;    
    
    if (CANTP_NUM_OF_RX_NSDU > RxNsduId)
    {
        /* Get NSdu configuration. */
        RxNSduConfigPtr = &CanTp_RxNSduConfig[RxNsduId];
        if (CANTP_NUM_OF_CHANNELS > RxNSduConfigPtr->ChannelId)
        {
            ChannelStatePtr = &CanTp_ChannelState[RxNSduConfigPtr->ChannelId];
            RxConnectionPtr = &ChannelStatePtr->RxConnection;
            ReceivedDataLength = DataInfoPtr->SduLength;
            
            if((RxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_STANDARD) &&
                  (RxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_NORMAL_FIXED))
            {
                Addr_Offset = 0x01u;
            }
            else 
            {
                Addr_Offset = 0x00u;              
            }
            
            if(CANTP_RX_PROCESSING_FRAME == RxConnectionPtr->ConnectionState)
            {
                /* check if the receive frame is greater than the remaining buffer length and not  last frame received */
                if (ReceivedDataLength != RxConnectionPtr->FirstFrameDataLength)
                {
                    if (ReceivedDataLength > RxConnectionPtr->RemainingNsduLength)
                    {
                        IsRxLengthValid = TRUE;
                    }                        
                }
                else
                {
                    IsRxLengthValid = TRUE;
                }
                
                if (TRUE == IsRxLengthValid)
                {
                    SeqNum = DataInfoPtr->SduDataPtr[Addr_Offset] & CANTP_CF_SEQ_NUM_MASK;
                    if (SeqNum == RxConnectionPtr->SequenceNumber)
                    {
                        /* Update the connection properties */
                        RxConnectionPtr->SequenceNumber = ((RxConnectionPtr->SequenceNumber+1U) & CANTP_CF_SEQ_NUM_MASK);
                        if (RxConnectionPtr->RemainingNsduLength > (ReceivedDataLength - 1U))
                        {
                            RxConnectionPtr->DataBufferLength = ReceivedDataLength - 1U;
                            //Defect Fix - FPK 149365 - ssaikapi
                            //RxConnectionPtr->BlockSizeCounter = RxNSduConfigPtr->BlockSize;
                        }
                        else
                        {
                            RxConnectionPtr->DataBufferLength = RxConnectionPtr->RemainingNsduLength;
                        }
                        RxConnectionPtr->FramePciType      = CANTP_PCI_TYPE_CF;
                         /* copy the data to the buffer */
                        CanTp_UtilMemCpy(&RxConnectionPtr->DataBuffer[0],&DataInfoPtr->SduDataPtr[Addr_Offset+0x01u],
                                            RxConnectionPtr->DataBufferLength);
                        if (RxConnectionPtr->AvailableBuffer >= RxConnectionPtr->DataBufferLength)
                        {
                            /* buffer available, request to copy data */
                            RxConnectionPtr->BufferState = BUFREQ_OK;
                        }
                        else
                        {
                            /* a new buffer must be requested */
                            RxConnectionPtr->BufferState = BUFREQ_E_BUSY;
                        }
                        RxConnectionPtr->ConnectionState = CANTP_RX_PROCESSING_FRAME_BUFFER_WAIT;
                        CanTp_FrameProcessorConfig[CANTP_PCI_TYPE_CF].RxPciBufferProcessorFn(ChannelStatePtr,
                                                                                    RxNSduConfigPtr->UpperLayerPduId);
                    }
                    else
                    {
                        /* SWS_CanTp_00314 wrong SN received the CanTp module shall abort reception and notify the 
                        upper layer*/
                        CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
                    }
                }
            }/* Consecutive frame received when state not in a valid state ,so discard the frame.*/  
        }
    }
}


/******************************************************************************************************************* 
*   @brief      This method is used to process the upper layer buffer request and notification for consecutive frame.
*   @param[in]  ChannelStatePtr pointer to channel connection.
*   @param[in]  RxUpperLayerId  PDU Id value of upper layer.
********************************************************************************************************************/
static void CanTp_RxConsecutiveFrameBufferProcessor(CanTp_ChannelStatePtrType ChannelStatePtr,PduIdType RxUpperLayerId)
{
    PduInfoType PduInfo;
    CanTp_RxConnectionPtrType RxConnectionPtr;
    CanTp_RxNSduConfigType const * RxNSduConfigPtr;
    PduLengthType BlockSizeInBytes;
    
    RxConnectionPtr = &ChannelStatePtr->RxConnection;
    if (CANTP_NUM_OF_RX_NSDU > RxConnectionPtr->NsduId)
    {
        RxNSduConfigPtr = &CanTp_RxNSduConfig[RxConnectionPtr->NsduId];
        RxConnectionPtr->FlowControlStatus = CANTP_FC_STATUS_NONE;
        if (BUFREQ_E_BUSY == RxConnectionPtr->BufferState)
        {
            /* get buffer size for the data copy. */
            PduInfo.SduLength = 0U;
            PduInfo.SduDataPtr = NULL_PTR;
            RxConnectionPtr->AvailableBuffer = 0U;
            RxConnectionPtr->BufferState = PduR_CanTpCopyRxData(RxUpperLayerId,
                                                                &PduInfo,
                                                                &RxConnectionPtr->AvailableBuffer);
        }
        
        if (BUFREQ_OK == RxConnectionPtr->BufferState)
        {
            /* if received buffer size it not enough to copy the data reset connection,else copy the data. */
            if(RxConnectionPtr->AvailableBuffer >= RxConnectionPtr->DataBufferLength)
            {
                PduInfo.SduDataPtr = &RxConnectionPtr->DataBuffer[0];
                PduInfo.SduLength = RxConnectionPtr->DataBufferLength;
                RxConnectionPtr->BufferState = PduR_CanTpCopyRxData(RxUpperLayerId,
                                                                    &PduInfo,
                                                                    &RxConnectionPtr->AvailableBuffer);
                
            }
            else
            {
                RxConnectionPtr->BufferState = BUFREQ_E_NOT_OK;
            }
        }
        
        if (BUFREQ_OK == RxConnectionPtr->BufferState)
        {
            RxConnectionPtr->RemainingNsduLength -= RxConnectionPtr->DataBufferLength;
            
            /* Check if the current CF is the last frame */
            if (0U == RxConnectionPtr->RemainingNsduLength)
            {
                CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_OK);
            }
            else
            {
                /* update the consecutive frame wait timer. */
                RxConnectionPtr->Timer = RxNSduConfigPtr->Ncr;
                RxConnectionPtr->ConnectionState = CANTP_RX_PROCESSING_FRAME;
                /* Check if Block counter is used. */
                if (0U != RxConnectionPtr->BlockSizeCounter)
                {
                    RxConnectionPtr->BlockSizeCounter--;
                    if (0U == RxConnectionPtr->BlockSizeCounter)
                    {
                        //Defect Fix - FPK 149365 - ssaikapi
                        RxConnectionPtr->BlockSizeCounter = RxNSduConfigPtr->BlockSize;
                        /* update the flow control frame wait timer. */
                        RxConnectionPtr->Timer = RxNSduConfigPtr->Nbr;
                        BlockSizeInBytes = CanTp_UtilGetBlockSizeInBytes(RxConnectionPtr);
                        /* request buffer size. */
                        PduInfo.SduLength = 0U;
                        PduInfo.SduDataPtr = NULL_PTR;
                        RxConnectionPtr->BufferState = PduR_CanTpCopyRxData(RxUpperLayerId,
                                                                &PduInfo,
                                                                &RxConnectionPtr->AvailableBuffer);
                                                                
                        if (BUFREQ_OK == RxConnectionPtr->BufferState)
                        {
                            if((RxConnectionPtr->AvailableBuffer >= BlockSizeInBytes) ||
                               (RxConnectionPtr->AvailableBuffer >= RxConnectionPtr->RemainingNsduLength))
                            {
                                /* Send Flow control with CTS */
                                RxConnectionPtr->FlowControlStatus = CANTP_FC_STATUS_CTS;
                            }
                            else
                            {
                                /* Send Flow control with status FC WAIT */
                                RxConnectionPtr->FlowControlStatus = CANTP_FC_STATUS_WAIT;
                            }
                        }
                        else
                        {
                            if (BUFREQ_E_BUSY == RxConnectionPtr->BufferState) 
                            {
                                /* if buffer state is busy ,retry in the main function and also send flow control with
                                WAIT */
                                RxConnectionPtr->FlowControlStatus = CANTP_FC_STATUS_WAIT;
                            }
                            else
                            {
                                 /* reset the connection if BUFREQ_E_NOT_OK */
                                CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
                            }
                        }
                    }/* block counter used but not all blocks received ,wait for the remaining block */
                } /* no block counter is used . wait for the next CF. */
            }
        }
        else if(BUFREQ_E_BUSY == RxConnectionPtr->BufferState)
        {
            /* If its not the last cf frame  and the block counter indicating
               retry of last buffer then send FC wait else reset the connection. */
            if ((1U == RxConnectionPtr->BlockSizeCounter) && 
                (RxConnectionPtr->RemainingNsduLength > RxConnectionPtr->DataBufferLength))
            {
                RxConnectionPtr->FlowControlWaitCounter = RxNSduConfigPtr->RxWftMax;
                RxConnectionPtr->FlowControlStatus = CANTP_FC_STATUS_WAIT;
            }
            else
            {
                 /* reset the connection  */
                CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
            }
        }
        else
        {
            /* reset the connection if BUFREQ_E_NOT_OK */
            CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
        }
        
        if (CANTP_FC_STATUS_NONE != RxConnectionPtr->FlowControlStatus)
        { 
            /* If flow control transmit requested , update connection state and transmit message. */
            RxConnectionPtr->ConnectionState = CANTP_RX_PROCESSING_FC_TRANSMIT;
            CanTp_SendFlowControl(ChannelStatePtr);
        }
    }
    
}

/******************************************************************************************************************* 
*   @brief      This method is used to process the received Flow control frame.
*   @param[in]  RxNsduId  received NSdu id value.
*   @param[in]  PduInfoPtr Contains the length (SduLength) of the received I-PDU and a pointer to a 
*                          buffer (SduDataPtr) containing the I-PDU.
********************************************************************************************************************/
static void CanTp_RxFlowControlFrameProcessor(CanTp_NSduIdType RxNsduId, const PduInfoType* DataInfoPtr, const PduInfoType* MetaInfoPtr)
{
    CanTp_TxNSduConfigType const *  TxNSduConfigPtr;
    CanTp_RxNSduConfigType const *  RxNSduConfigPtr;
    CanTp_TxConnectionPtrType TxConnectionPtr;
    CanTp_ChannelStatePtrType ChannelStatePtr;
    PduLengthType NSduLength=0U;
    uint8 FlowStatus;
    uint8 StMinValue;
    uint8 Addr_Offset = 0U;
    
    if (CANTP_NUM_OF_RX_NSDU > RxNsduId)
    {
        /* Get NSdu configuration. */
        RxNSduConfigPtr = &CanTp_RxNSduConfig[RxNsduId];
        if ((CANTP_NUM_OF_CHANNELS > RxNSduConfigPtr->ChannelId ) && 
            (CANTP_NUM_OF_TX_NSDU > RxNSduConfigPtr->FlowControlTxNPduId))
        {
            ChannelStatePtr = &CanTp_ChannelState[RxNSduConfigPtr->ChannelId];
            TxConnectionPtr = &ChannelStatePtr->TxConnection;
            TxNSduConfigPtr = &CanTp_TxNSduConfig[RxNSduConfigPtr->FlowControlTxNPduId];
            
            if((RxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_STANDARD) &&
                  (RxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_NORMAL_FIXED))
            {
                Addr_Offset = 0x01u;
            }
            else 
            {
                Addr_Offset = 0x00u;              
            }

            /* Process FC frame only if the state is CANTP_TX_PROCESSING_FLOW_CONTROL_WAIT and the requested type  
            is functional request .  */
            /* TODO: Need to check for cases if FC received before confirmation. */
            if (((CANTP_TX_PROCESSING_FLOW_CONTROL_WAIT == TxConnectionPtr->ConnectionState) ||
                (CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT == TxConnectionPtr->ConnectionState)) &&
                (TRUE == CANTP_UTIL_IS_REQTYPE_PHYSICAL(RxNSduConfigPtr->RxTaType)))
            {
                /* TODO : FC MIN LENTH CHECK */
                if ((uint8)E_OK == CanTp_CheckAndDecodeRxDl(RxNSduConfigPtr,CANTP_PCI_TYPE_FC,DataInfoPtr,&NSduLength))
                {
                    FlowStatus=(DataInfoPtr->SduDataPtr[Addr_Offset] & 0xFU);  
                    if (CANTP_FC_STATUS_CTS == FlowStatus)
                    {
                        /* get the stmin and block size value */
                        TxConnectionPtr->BlockSizeCounter = DataInfoPtr->SduDataPtr[Addr_Offset+0x01u];
                        StMinValue = DataInfoPtr->SduDataPtr[Addr_Offset+0x02u];
                        /* check stmin range. */
                        if (CANTP_STMIN_MILLISEC_MAX >= StMinValue)
                        {
                            TxConnectionPtr->StMinValue = StMinValue;   
                        }
                        else if((CANTP_STMIN_MICROSEC_MIN <= StMinValue ) && (CANTP_STMIN_MICROSEC_MAX>= StMinValue))
                        {
                            /* SRAJAGO6: As Per RENAULT NISSAN DESIGN SPECIFICATION (RNDS) Vehicle generic specifications 
                               Design Test Plan RNDS-00023 v2.0 
                               
                               6.3.2.9. [Diag 3_2_9] Flow Control Frame Reception: checking Stmin (0xF1-0xF9 = 127ms)
                               
                               This Change is only applicable for NISSAN J32V*/
                            TxConnectionPtr->StMinValue = 0x7FU; /* micro seconds not supported, hence STMIN is set to 0x7F as per Renault Nissan Design Specification*/
                        }
                        else
                        {
                            /* If an FC is received with a reserved STmin parameter value, then the longest STmin value
                            0x7F = 127 ms should be used instead of the value received */
                            TxConnectionPtr->StMinValue = 0x7FU;
                        }
                            
                        TxConnectionPtr->FramePciType = CANTP_PCI_TYPE_CF;
                        
                        /* Stmin update. Stmin value is updated by the Flow control message   */
                        if (0U == TxConnectionPtr->StMinValue)
                        {
                             /* if received stmin value is zero, update the state to CF wait frame and start cs 
                             timer*/
                             TxConnectionPtr->ConnectionState = CANTP_TX_PROCESSING_BUFFER_WAIT;
                             TxConnectionPtr->StMinTimer = 0U;
                             TxConnectionPtr->Timer = TxNSduConfigPtr->Ncs;
                             (void) CanTp_TxFrameBufferProcessing(ChannelStatePtr);
                        }
                        else
                        {
                            TxConnectionPtr->StMinTimer = (uint32)1U;
                            TxConnectionPtr->ConnectionState = CANTP_TX_PROCESSING_STMIN_WAIT;
                        }
                    }
                    else if (CANTP_FC_STATUS_WAIT == FlowStatus)
                    {
                        /* Wait for next flow control and update NbsTimer */
                        TxConnectionPtr->Timer = TxNSduConfigPtr->Nbs;
                    }
                    else
                    {
                        CanTp_InitTxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
                    }                
                } /* Invalid length */
            } /* state check */
        }/* No of channel */
    }/* No of RXNSDU */
}

/******************************************************************************************************************* 
*   @brief      This method is used to form the Flow control frame and request Flow control transmission.
*   @param[in]  ChannelStatePtr  pointer to channel connection.
********************************************************************************************************************/
static void CanTp_SendFlowControl(CanTp_ChannelStatePtrType ChannelStatePtr)
{
    PduInfoType PduInfo;
    boolean TxStatus = TRUE;
    CanTp_RxNSduConfigType const * RxNSduConfigPtr;
    CanTp_TxNSduConfigType const * TxNSduConfigPtr;
    CanTp_RxConnectionPtrType RxConnectionPtr;
    CanTp_TransmitStatusType TransmitStatus = CANTP_TRANSMIT_NOT_OK;
    uint8 FlowControlData[CANTP_FC_MAX_DATA_LENGTH]={0U,0U,0U,0U,0U,0U,0U,0U};
    uint8 Addr_Offset;
    
    RxConnectionPtr =  &ChannelStatePtr->RxConnection;
    
    if (CANTP_NUM_OF_RX_NSDU > RxConnectionPtr->NsduId )
    {
        RxNSduConfigPtr = &CanTp_RxNSduConfig[RxConnectionPtr->NsduId];
        
        if((RxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_STANDARD) &&
              (RxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_NORMAL_FIXED))
        {
          Addr_Offset = 0x01u;
        }
        else 
        {
          Addr_Offset = 0x00u;              
        }
        
        /* cert 17225742 - RxConnectionPtr->FlowControlStatus is uint8 so the resulting value will be uint8 */
        FlowControlData[Addr_Offset] = (CANTP_PCI_TYPE_FC << 4U)| (RxConnectionPtr->FlowControlStatus);
    
        if(CANTP_FC_STATUS_CTS == RxConnectionPtr->FlowControlStatus )
        {
            #if(CANTP_CHANGE_PARAMETER_API == STD_ON)
            FlowControlData[Addr_Offset+0x01u] = CanTp_DynamicTpParameter[RxConnectionPtr->NsduId].StMin;
            FlowControlData[Addr_Offset+0x02u] = CanTp_DynamicTpParameter[RxConnectionPtr->NsduId].BlockSize;
            #else
            FlowControlData[Addr_Offset+0x01u] = RxNSduConfigPtr->BlockSize;
            FlowControlData[Addr_Offset+0x02u] = RxNSduConfigPtr->TpSTmin;
            #endif
        }
        else if(CANTP_FC_STATUS_WAIT == RxConnectionPtr->FlowControlStatus)
        {
            if (0U == RxConnectionPtr->FlowControlWaitCounter)
            {
                /* Reset connection */
                TxStatus = FALSE;
                CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
            }
        }
        else /* CANTP_FC_STATUS_OVERFLOW */
        {
            /* Do nothing */
            RxConnectionPtr->FlowControlWaitCounter = 0U;
        }
        
        if(FALSE !=TxStatus )
        {
            if (CANTP_NUM_OF_TX_NSDU > RxNSduConfigPtr->FlowControlTxNPduId)
            {
                PduInfo.SduLength = 3U;
                PduInfo.SduDataPtr = &FlowControlData[0];
                /* Request transmission */
                TxNSduConfigPtr = &CanTp_TxNSduConfig[RxNSduConfigPtr->FlowControlTxNPduId];
                if((TxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_STANDARD) &&
                          (TxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_NORMAL_FIXED))
                {
#if ((CANTP_EXTENDED_SUPPORT == STD_ON) || (CANTP_MIXED_29BIT_SUPPORT == STD_ON) || \
    (CANTP_MIXED_SUPPORT == STD_ON) || (CANTP_NORMAL_FIXED_SUPPORT == STD_ON))
                    if(TxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_EXTENDED)
                    {
                        FlowControlData[0] = TxNSduConfigPtr->TxNAe;
                    }
                    else
                    {
                        FlowControlData[0] = TxNSduConfigPtr->RxNTa;
                    }
#endif
                }
                TransmitStatus = CanTp_CanIfTransmitData(&PduInfo,RxNSduConfigPtr->FlowControlTxLowerLayerPduId,
                                                  CANTP_TRANSMIT_BY_RX_CONNECTION,TxNSduConfigPtr->TxPaddingActivation,
                                                  CANTP_FC_MAX_DATA_LENGTH,RxNSduConfigPtr->ChannelId);
                if (CANTP_TRANSMIT_OK == TransmitStatus)
                {
                    RxConnectionPtr->ConnectionState = CANTP_RX_PROCESSING_FC_CONF_WAIT;
                    RxConnectionPtr->Timer = RxNSduConfigPtr->Nar;
                }
                else
                {
                    if ( CANTP_TRANSMIT_NOT_OK == TransmitStatus)
                    {
                        CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
                    } /* else if transmit returns busy retry in main function */
                }
            }
        }
    }
}

/****************************************************************************************************************** 
*   @brief      This method is used to validate transmission request and request lower layer for transmission.
*   @param[in]  PduInfoPtr Contains the length (SduLength) of the received I-PDU and a pointer to a 
*                          buffer (SduDataPtr) containing the I-PDU.SduDataPtr should be called with buffer with padded 
*                          length.
*   @param[in]  TxPduId PduId for the CanIf layer
*   @param[in]  TransmitConnection connection type that requested transmission
*   @param[in]  paddingSupport padding support enabled or not.
*   @param[in]  paddededLength maximum padded length.
*   @param[in]  ChId PduId Channel Id of the connection.
*   @return     CanTp_TransmitStatusType returns the transmission status.
*               -CANTP_TRANSMIT_OK      - Transmission is successful 
*               -CANTP_TRANSMIT_NOT_OK  - Transmission is not successful
*               -CANTP_TRANSMIT_BUSY    - Already transmit request for Tx/Rx connection exist , Retry the transmission
*                                         request later
********************************************************************************************************************/
static CanTp_TransmitStatusType CanTp_CanIfTransmitData(PduInfoType* PduInfoPtr,
                                        PduIdType TxPduId,
                                        CanTp_TransmitRequestType TransmitConnection, 
                                        CanTpPaddingActivationType PaddingSupport,
                                        PduLengthType PaddededLength,
                                        CanTp_ChannelIdType ChId)
{
    CanTp_TransmitRequestType CurrentTxRequest = CANTP_TRANSMIT_CONNECTION_NONE;
    CanTp_TransmitStatusType TransmitStatus = CANTP_TRANSMIT_NOT_OK;
    CanTp_ChannelStatePtrType ChannelStatePtr;
    PduLengthType Length;
    
    if (CANTP_NUM_OF_CHANNELS > ChId )
    {
        ChannelStatePtr = &CanTp_ChannelState[ChId];
        CurrentTxRequest = ChannelStatePtr->TxRequestType;
        Length = PduInfoPtr->SduLength;
        
        if ((CANTP_TRANSMIT_CONNECTION_NONE == CurrentTxRequest) ||
            (TransmitConnection == CurrentTxRequest))
        {
            /* Check for padding support */
            if (CANTP_ON == PaddingSupport)    
            {
                /* add the padding bytes */
                while(Length < PaddededLength)
                {
                    PduInfoPtr->SduDataPtr[Length] = CANTP_PADDING_BYTE;
                    Length++;
                }
            }
            PduInfoPtr->SduLength = Length;
            
            /* Send transmit request . */
            if ((uint8)E_OK == CanIf_Transmit(TxPduId,PduInfoPtr))
            {
                /* if successfully transmitted , update the channel transmit direction. */
                ChannelStatePtr->TxRequestType = TransmitConnection;
                TransmitStatus = CANTP_TRANSMIT_OK;
            }
            else
            {
                TransmitStatus = CANTP_TRANSMIT_NOT_OK;
            }
            
        }
        else
        {
            /* if already transmission in progress, wait and retry. */
            TransmitStatus = CANTP_TRANSMIT_BUSY;
        }
    }   
    return TransmitStatus;
}

/******************************************************************************************************************* 
*   @brief      This method is used to process the flow control transmit confirmation.
*   @param[in]  ChannelStatePtr  pointer to the channel connection.
********************************************************************************************************************/
static void CanTp_ProcessFlowControlConfirmation(CanTp_ChannelStatePtrType ChannelStatePtr)
{
    CanTp_RxConnectionPtrType RxConnectionPtr;
    CanTp_RxNSduConfigType const * RxNSduConfigPtr;
    
    RxConnectionPtr = &ChannelStatePtr->RxConnection;
    if (CANTP_NUM_OF_RX_NSDU > RxConnectionPtr->NsduId)
    {
        RxNSduConfigPtr = &CanTp_RxNSduConfig[RxConnectionPtr->NsduId];

        if (CANTP_RX_PROCESSING_FC_CONF_WAIT == RxConnectionPtr->ConnectionState)
        {
             /* if last transmitted frame is overflow , trigger reset else set rxstate to 
             to be in receive CF wait or send FC again */
            if (CANTP_FC_STATUS_OVERFLOW != RxConnectionPtr->FlowControlStatus)
            {
                if (0U != RxConnectionPtr->FlowControlWaitCounter)
                {
                    RxConnectionPtr->FlowControlWaitCounter--;
                    if (0U == RxConnectionPtr->FlowControlWaitCounter)
                    {
                        /* Reset connection */
                        CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
                    }
                }
                
                if (CANTP_FC_STATUS_CTS == RxConnectionPtr->FlowControlStatus)
                {
                    /* Load the consecutive wait timer. */
                    RxConnectionPtr->Timer = RxNSduConfigPtr->Ncr;
                    /* Set state to process consecutive frame. */
                    RxConnectionPtr->ConnectionState = CANTP_RX_PROCESSING_FRAME;
                }
            }
            else /* CANTP_OVERFLOW */
            {
                /* Reset connection */
                CanTp_InitRxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
            }
        }
    }
}

/****************************************************************************************************************** 
*   @brief      This function initializes the CanTp channel Tx connection.
*   @param[in]  ChannelStatePtr  Pointer to the CanTP Channel.
********************************************************************************************************************/
static void CanTp_InitTxConnection(CanTp_ChannelStatePtrType ChannelStatePtr,
                                        CanTp_TransmitRequestType ConnectionNotificationType)
{
    CanTp_TxConnectionPtrType TxConnectionPtr;
    CanTp_TxNSduConfigType const * TxNSduConfigPtr;
    
    TxConnectionPtr = &ChannelStatePtr->TxConnection;
    /* Initialize the connection properties */
    TxConnectionPtr->ConnectionState        = CANTP_TX_WAIT;
    TxConnectionPtr->BufferState            = BUFREQ_OK;
    TxConnectionPtr->FramePciType           = CANTP_PCI_TYPE_INVALID;
    TxConnectionPtr->BlockSizeCounter       = 0U;
    TxConnectionPtr->StMinValue             = 0U;
    TxConnectionPtr->Timer                  = 0U;
    TxConnectionPtr->StMinTimer             = 0U;
    TxConnectionPtr->SequenceNumber         = 0U;
    TxConnectionPtr->RemainingNsduLength    = 0U;
    TxConnectionPtr->TotalNsduLength        = 0U;
    TxConnectionPtr->AvailableBuffer        = 0U;
    TxConnectionPtr->DataBufferLength       = 0U;
    
    CanTp_UtilMemSet(&TxConnectionPtr->DataBuffer[0],0U,CANTP_MAX_BUFFER_LENGTH);
    
    if ((CANTP_NOTIFY_NONE > ConnectionNotificationType) &&
        (CANTP_NUM_OF_TX_NSDU > TxConnectionPtr->NsduId))  
    {
        /* get upper layer pdu id */
        TxNSduConfigPtr = &CanTp_TxNSduConfig[TxConnectionPtr->NsduId];
        /* Notify upper layer about the connection status. */
        PduR_CanTpTxConfirmation(TxNSduConfigPtr->UpperLayerPduId,ConnectionNotificationType);
    }
    TxConnectionPtr->NsduId                 = CANTP_INVALID_NSDU;
    /* cert 17225214 - Need only uint8 part */
    /* clear the transmit request  */
    ChannelStatePtr->TxRequestType &=(CanTp_TransmitRequestType) (~(CANTP_TRANSMIT_BY_TX_CONNECTION));
}

/******************************************************************************************************************* 
*   @brief  This method is used to process buffer request for frame transmission.
*   @param[in]  ChannelStatePtr  pointer to the channel connection.
*   @return Returns the request status
*           E_OK - Buffer request successful or waiting to get buffer.
*           E_NOT_OK - Buffer request is declined by the upper layer.
********************************************************************************************************************/
static Std_ReturnType CanTp_TxFrameBufferProcessing(CanTp_ChannelStatePtrType ChannelStatePtr)
{
    CanTp_TxNSduConfigType const * TxNSduConfigPtr;
    CanTp_TxConnectionPtrType  TxConnectionPtr;
    PduInfoType PduInfo;
    Std_ReturnType Status = E_OK;

    TxConnectionPtr = &ChannelStatePtr->TxConnection;
    if (CANTP_NUM_OF_TX_NSDU > TxConnectionPtr->NsduId)
    {
        TxNSduConfigPtr = &CanTp_TxNSduConfig[TxConnectionPtr->NsduId];
        TxConnectionPtr->BufferState = BUFREQ_E_BUSY;
        /* update data length to be copied  */
        if (CANTP_PCI_TYPE_SF == TxConnectionPtr->FramePciType)
        {
            TxConnectionPtr->DataBufferLength = TxConnectionPtr->TotalNsduLength;
        }
        else if(CANTP_PCI_TYPE_FF == TxConnectionPtr->FramePciType)
        {
            if (8U < TxNSduConfigPtr->MaxLowerLayerDataLength) /* can fd frame */
                {
                if (TxConnectionPtr->TotalNsduLength > 4095U)
                {
                    TxConnectionPtr->DataBufferLength = (TxNSduConfigPtr->MaxLowerLayerDataLength - 6U);
                }
                else
                {
                    TxConnectionPtr->DataBufferLength = (TxNSduConfigPtr->MaxLowerLayerDataLength - 2U);
                }
                }
                else
                {
                    TxConnectionPtr->DataBufferLength = (TxNSduConfigPtr->MaxLowerLayerDataLength-2U);
                }
        }
        else if((CANTP_PCI_TYPE_CF == TxConnectionPtr->FramePciType) &&(TxNSduConfigPtr->MaxLowerLayerDataLength != 0U))
        {
            /* check stmin value. */
            if (TxConnectionPtr->RemainingNsduLength > (TxNSduConfigPtr->MaxLowerLayerDataLength-1U))
            {
                TxConnectionPtr->DataBufferLength = (TxNSduConfigPtr->MaxLowerLayerDataLength-1U);
            }
            else
            {
                TxConnectionPtr->DataBufferLength = TxConnectionPtr->RemainingNsduLength;/* last CF Frame */
                TxConnectionPtr->RemainingNsduLength = 0;
            }
        }
        else
        {
            Status = E_NOT_OK;
        }
        
        if ((uint8)E_OK == Status)
        {
            PduInfo.SduDataPtr = &TxConnectionPtr->DataBuffer[0];
            PduInfo.SduLength = TxConnectionPtr->DataBufferLength;
            TxConnectionPtr->BufferState = PduR_CanTpCopyTxData(TxNSduConfigPtr->UpperLayerPduId,
                                                                &PduInfo,
                                                                NULL_PTR,
                                                                &TxConnectionPtr->AvailableBuffer);
            
            if ( BUFREQ_OK == TxConnectionPtr->BufferState)
            {
                Status = CanTp_TxUpdateAndTransmitPci(ChannelStatePtr);
            }
            else
            {
                if ( BUFREQ_E_BUSY != TxConnectionPtr->BufferState) 
                {
                    /*  SWS_CanTp_00087 If PduR_CanTpCopyTxData() returns BUFREQ_E_NOT_OK, the CanTp module shall abort
                     the transmit request and notify the upper layer of this failure. */
                    CanTp_InitTxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
                    Status = E_NOT_OK;
                }  
            }
        }
    }
    else
    {
        Status = E_NOT_OK;
    }
    
    return Status;
}

/******************************************************************************************************************* 
*   @brief  This method is used to update the PCI info , data and request transmission to lower layer.
*   @param[in]  ChannelStatePtr  pointer to the channel connection.
*   @return Returns the request status
*           E_OK - Transmit successful or Transmit connection is already in progress (process in main function).
*           E_NOT_OK - Transmit request is declined by the lower layer.
********************************************************************************************************************/
static Std_ReturnType CanTp_TxUpdateAndTransmitPci(CanTp_ChannelStatePtrType ChannelStatePtr)
{
    CanTp_TxNSduConfigType const * TxNSduConfigPtr;
    CanTp_TxConnectionPtrType  TxConnectionPtr;
    uint8 TransmitBuffer[CANTP_MAX_BUFFER_LENGTH];
    uint8 Addr_Offset = 0u;
    PduInfoType PduInfo;
    PduLengthType MaximumPaddedLength;
    CanTp_TransmitStatusType TransmitStatus = CANTP_TRANSMIT_OK;
    Std_ReturnType Status = E_OK;
    
    TxConnectionPtr = &ChannelStatePtr->TxConnection;
    if (CANTP_NUM_OF_TX_NSDU > TxConnectionPtr->NsduId )
    {
        TxNSduConfigPtr = &CanTp_TxNSduConfig[TxConnectionPtr->NsduId];
        PduInfo.SduLength = 0U;
        CanTp_UtilMemSet(&TransmitBuffer[0],0U,CANTP_MAX_BUFFER_LENGTH);
        if((TxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_STANDARD) &&
           (TxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_NORMAL_FIXED))
        {
            Addr_Offset = 0x01u;
#if ((CANTP_EXTENDED_SUPPORT == STD_ON) || (CANTP_MIXED_29BIT_SUPPORT == STD_ON) || \
                        (CANTP_MIXED_SUPPORT == STD_ON) || (CANTP_NORMAL_FIXED_SUPPORT == STD_ON))
                if (TxNSduConfigPtr->RxNsduAddressingFormatType != CANTP_EXTENDED)
            {
              TransmitBuffer[0] = TxNSduConfigPtr->TxNAe;
            }
            else
            {
              TransmitBuffer[0] = TxNSduConfigPtr->RxNTa;
            }
#endif
        }
        else 
        {
          Addr_Offset = 0x00u;              
        }       
        
        /* data copied successfully,request transmission prepare frame and request transmit */
        if (CANTP_PCI_TYPE_SF == TxConnectionPtr->FramePciType)
        {
            TransmitBuffer[Addr_Offset] = CANTP_PCI_SF_VALUE;
            /* CANFD frame check is done in CanTp_Transmit(), here SF frame format is updated according to Data length*/
            if (8U <= TxConnectionPtr->DataBufferLength) 
            {
                TransmitBuffer[Addr_Offset + 1U] = (uint8)TxConnectionPtr->DataBufferLength;
                PduInfo.SduLength = Addr_Offset + 2U;
            }
            else
            {
                /* cert 17224489 - Taking lower 4 bits to update in buffer */
                TransmitBuffer[Addr_Offset] |=  (uint8)(((uint8)TxConnectionPtr->DataBufferLength)&0x0FU);
                PduInfo.SduLength = Addr_Offset + 1U;
            }
        }
        else if(CANTP_PCI_TYPE_FF == TxConnectionPtr->FramePciType)
        {
            TransmitBuffer[Addr_Offset] = CANTP_PCI_FF_VALUE;
            TxConnectionPtr->SequenceNumber = 1U;
            if (8U < TxNSduConfigPtr->MaxLowerLayerDataLength) /*  can fd frame */
            {
                if (TxConnectionPtr->TotalNsduLength > 4095U)
                {
                    TransmitBuffer[Addr_Offset+1U] |= 0U;
                    TransmitBuffer[Addr_Offset+2U] |= (uint8)(TxConnectionPtr->TotalNsduLength >> 24U);
                    TransmitBuffer[Addr_Offset+3U] |= (uint8)(TxConnectionPtr->TotalNsduLength >> 16U);
                    TransmitBuffer[Addr_Offset+4U] |= (uint8)(TxConnectionPtr->TotalNsduLength >> 8U);
                    TransmitBuffer[Addr_Offset+5U] |= (uint8)(TxConnectionPtr->TotalNsduLength);
                    PduInfo.SduLength = Addr_Offset + 6;
                }
                else
                {
                    TransmitBuffer[Addr_Offset] |= (uint8)((uint8)(TxConnectionPtr->TotalNsduLength >> 8U) & 0x0FU);
                    TransmitBuffer[Addr_Offset+1U] |= (uint8)(TxConnectionPtr->TotalNsduLength);
                    PduInfo.SduLength = Addr_Offset + 2U;
                }
                
            }
            else
            {
                TransmitBuffer[Addr_Offset] |= (uint8)((uint8)(TxConnectionPtr->TotalNsduLength >> 8U) & 0x0FU);
                /* cert 17224505 - Taking lower 8 bits to update in buffer */
                TransmitBuffer[Addr_Offset+1U] |= (uint8)(TxConnectionPtr->TotalNsduLength);
                PduInfo.SduLength = Addr_Offset + 2U;
            }
        }
        else if(CANTP_PCI_TYPE_CF == TxConnectionPtr->FramePciType)
        {
            TransmitBuffer[Addr_Offset] = CANTP_PCI_CF_VALUE;
            TransmitBuffer[Addr_Offset] |= (uint8)(TxConnectionPtr->SequenceNumber & 0x0FU);
            TxConnectionPtr->SequenceNumber++;
            PduInfo.SduLength = Addr_Offset + 1U;
        }
        else
        {
            Status = E_NOT_OK;
        }
        
        if ((uint8)E_NOT_OK != Status)
        {
            /* Copy data to transmit buffer */
            CanTp_UtilMemCpy(&TransmitBuffer[PduInfo.SduLength],
                             &TxConnectionPtr->DataBuffer[0],
                             TxConnectionPtr->DataBufferLength);
                             
            /* Update the transmit data length and connection properties */
            PduInfo.SduLength += TxConnectionPtr->DataBufferLength;
            PduInfo.SduDataPtr = &TransmitBuffer[0];
            TxConnectionPtr->ConnectionState = CANTP_TX_PROCESSING_TRANSMIT;
            MaximumPaddedLength = CanTp_UtilGetPaddingLength(PduInfo.SduLength);
            
            TransmitStatus = CanTp_CanIfTransmitData(&PduInfo,TxNSduConfigPtr->LowerLayerId,
                                    CANTP_TRANSMIT_BY_TX_CONNECTION,TxNSduConfigPtr->TxPaddingActivation,
                                    MaximumPaddedLength,
                                    TxNSduConfigPtr->ChannelId);
                                    
            if (CANTP_TRANSMIT_OK == TransmitStatus)
            {
                /* start confirmation timer, update confirmation state and remaining length. */
                TxConnectionPtr->Timer = TxNSduConfigPtr->Nas;
                #if(CANTP_META_DATA_TX_SUPPORT == STD_ON)
                if (TxConnectionPtr->RemainingNsduLength > TxConnectionPtr->DataBufferLength+TxNSduConfigPtr->TxMetaDataLength)
                {
                    TxConnectionPtr->RemainingNsduLength -= TxConnectionPtr->DataBufferLength+TxNSduConfigPtr->TxMetaDataLength;
                }
                #else
                if (TxConnectionPtr->RemainingNsduLength > TxConnectionPtr->DataBufferLength)
                {
                    TxConnectionPtr->RemainingNsduLength -= TxConnectionPtr->DataBufferLength;
                }
                #endif              
                TxConnectionPtr->ConnectionState = CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT;
            }
            else
            {
                if ( CANTP_TRANSMIT_NOT_OK == TransmitStatus)
                {
                     CanTp_InitTxConnection(ChannelStatePtr,CANTP_NOTIFY_NOT_OK);
                     Status = E_NOT_OK;
                }
            }
        }
    }
    else
    {
        Status = E_NOT_OK;
    }
    
    return Status;
}

/******************************************************************************************************************* 
*   @brief  This method is used to process transmit confirmation received for the CanTp channel connection.
*   @param[in] ChannelStatePtr  pointer to the channel connection.
********************************************************************************************************************/
static void CanTp_ProcessTxConfirmation(CanTp_ChannelStatePtrType ChannelStatePtr)
{
    CanTp_TxNSduConfigType const * TxNSduConfigPtr;
    CanTp_TxConnectionPtrType  TxConnectionPtr;
    
    TxConnectionPtr = &ChannelStatePtr->TxConnection;
    if (CANTP_NUM_OF_TX_NSDU > TxConnectionPtr->NsduId )
    {
        TxNSduConfigPtr = &CanTp_TxNSduConfig[TxConnectionPtr->NsduId];
    
        if (CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT == TxConnectionPtr->ConnectionState )
        {
            if(CANTP_PCI_TYPE_SF == TxConnectionPtr->FramePciType)
            {
                CanTp_InitTxConnection(ChannelStatePtr,CANTP_NOTIFY_OK);
            }
            else if(CANTP_PCI_TYPE_FF == TxConnectionPtr->FramePciType )
            {
                /* start flow control wait timer */
                TxConnectionPtr->Timer = TxNSduConfigPtr->Nbs;
                TxConnectionPtr->ConnectionState = CANTP_TX_PROCESSING_FLOW_CONTROL_WAIT;
            }
            else if(CANTP_PCI_TYPE_CF == TxConnectionPtr->FramePciType)
            {
                if ( 0U == TxConnectionPtr->RemainingNsduLength)
                {
                    CanTp_InitTxConnection(ChannelStatePtr,CANTP_NOTIFY_OK);
                }
                else
                {
                    if (0U != TxConnectionPtr->BlockSizeCounter )
                    {
                        TxConnectionPtr->BlockSizeCounter--;
                        if (0U == TxConnectionPtr->BlockSizeCounter)
                        {
                            /* set state to wait for flow control and timer Nbs */
                            TxConnectionPtr->ConnectionState = CANTP_TX_PROCESSING_FLOW_CONTROL_WAIT;
                            TxConnectionPtr->Timer = TxNSduConfigPtr->Nbs;
                        }
                    }
                    
                    if (TxConnectionPtr->ConnectionState != CANTP_TX_PROCESSING_FLOW_CONTROL_WAIT)
                    {
                        /* Stmin update. Stmin value is updated by the Flow control message   */
                        if (0U == TxConnectionPtr->StMinValue)
                        {
                             /* if received stmin value is zero, update the state to CF wait frame and start cs timer*/
                             TxConnectionPtr->ConnectionState = CANTP_TX_PROCESSING_BUFFER_WAIT;
                             TxConnectionPtr->StMinTimer = 0U;
                             TxConnectionPtr->Timer = TxNSduConfigPtr->Ncs;
                             (void)CanTp_TxFrameBufferProcessing(ChannelStatePtr);
                        }
                        else
                        {
                            TxConnectionPtr->StMinTimer = CanTp_UtilGetTimeInCyclicPeriod(TxConnectionPtr->StMinValue);
                            TxConnectionPtr->ConnectionState = CANTP_TX_PROCESSING_STMIN_WAIT;
                        }
                    }
                }
            }
            else
            {
               /* Do Nothing */ 
            }
        }
    }     
}

/******************************************************************************************************************* 
*   @brief  This method is used to process transmit request and Timeout handling for the CanTp channel connection.
*   @param[in]  ChannelId  CanTP Channel ID value.
********************************************************************************************************************/
static void CanTp_TxChannelProcessing(CanTp_ChannelIdType ChannelId)
{
    CanTp_TxNSduConfigType const * TxNSduConfigPtr;
    CanTp_ChannelStatePtrType ChannelStatePtr;
    CanTp_TxConnectionPtrType TxConnectionPtr;
    
    if (CANTP_NUM_OF_CHANNELS > ChannelId )
    {
        ChannelStatePtr = &CanTp_ChannelState[ChannelId];
        TxConnectionPtr = &ChannelStatePtr->TxConnection;
        if (CANTP_NUM_OF_TX_NSDU > TxConnectionPtr->NsduId) 
        {
            TxNSduConfigPtr = &CanTp_TxNSduConfig[TxConnectionPtr->NsduId];
            
            CanTp_EnterCriticalSection();
            if (CANTP_TX_WAIT != TxConnectionPtr->ConnectionState)
            {
                if ((CANTP_TX_PROCESSING_STMIN_WAIT == TxConnectionPtr->ConnectionState) &&
                    (0U != TxConnectionPtr->StMinTimer ))
                {
                    TxConnectionPtr->StMinTimer--;
                    if (0U == TxConnectionPtr->StMinTimer)
                    {
                        /* if received stmin value is zero, update the state to CF wait frame and start cs timer*/
                         TxConnectionPtr->ConnectionState = CANTP_TX_PROCESSING_BUFFER_WAIT;
                         TxConnectionPtr->Timer = TxNSduConfigPtr->Ncs;
                         (void)CanTp_TxFrameBufferProcessing(ChannelStatePtr);
                    }
                }
                else
                {
                    if(0U != TxConnectionPtr->Timer)
                    {
                        TxConnectionPtr->Timer--;
                         /* Timer NAs,Nbs and Ncs */
                        if(0U == TxConnectionPtr->Timer)
                        {
                           /* Indicate E_OK  */
                           CanTp_InitTxConnection(ChannelStatePtr,E_NOT_OK);
                        }
                        else
                        {
                            /* process pending request  */
                            if ((TxConnectionPtr->ConnectionState == CANTP_TX_PROCESSING_BUFFER_WAIT) ||
                                (TxConnectionPtr->ConnectionState == CANTP_TX_PROCESSING_TRANSMIT))
                            {
                                (void)CanTp_TxFrameBufferProcessing(ChannelStatePtr);
                            }
                           
                        }
                    }
                }       
            }
            CanTp_ExitCriticalSection();
        }
    }
}

/****************************************************************************************************************** 
*   @brief      This method is used to get the number of bytes in a CF block.
*   @param[in]  RxNsduId  received NSdu id value.
*   @param[in]  PduInfoPtr Contains the length (SduLength) of the received I-PDU and a pointer to a 
*                          buffer (SduDataPtr) containing the I-PDU.
********************************************************************************************************************/
static PduLengthType CanTp_UtilGetBlockSizeInBytes(CanTp_RxConnectionPtrType RxConnectionPtr)
{
    CanTp_RxNSduConfigType const * RxNSduConfigPtr;
    PduLengthType BlockSizeInBytes = 0U;
    
    if (CANTP_NUM_OF_RX_NSDU > RxConnectionPtr->NsduId )
    {
        RxNSduConfigPtr = &CanTp_RxNSduConfig[RxConnectionPtr->NsduId];
        /* To determine the RX_DL from a received FirstFrame N_PDU, the payload length in bytes (CAN_DL) is used.
            — For CAN_DL values less than 8 bytes, the RX_DL value is invalid.3)
            — For CAN_DL values equal to 8 bytes, the RX_DL value shall be 8.
            — For CAN_DL values greater than 8 bytes, the RX_DL value equals the CAN_DL value */
            
        if (0U != RxNSduConfigPtr->BlockSize)
        {
            if(CANTP_UINT_16_MAX >= ((RxConnectionPtr->FirstFrameDataLength-1U) * RxNSduConfigPtr->BlockSize)  ) /*Cert-c Fix*/
            {
                BlockSizeInBytes = (RxConnectionPtr->FirstFrameDataLength-1U) * RxNSduConfigPtr->BlockSize;
            }
        }
        else
        {
            BlockSizeInBytes = RxConnectionPtr->RemainingNsduLength;
        }
        
    }
    return BlockSizeInBytes;
}

/******************************************************************************************************************* 
*   @brief  This method is the utility for copying data from src to destination pointer with the requested length.
*   @param[in]  pDest   pointer to the destination buffer.
*   @param[in]  pSrc    pointer to the source buffer.
*   @param[in]  Length  number of bytes to be copied.
********************************************************************************************************************/
static void CanTp_UtilMemCpy(uint8 *DestPtr,const uint8 * const SrcPtr,PduLengthType Length)
{
    PduLengthType Idx;
    /* copy number of bytes from [pSrc] to [pDest]. */
    for (Idx = 0U; Idx < Length; Idx++)
    {
        DestPtr[Idx] = SrcPtr[Idx]; 
    }
}


/******************************************************************************************************************* 
*   @brief  This method is the utility for setting data to destination pointer with the requested data.
*   @param[in]  pDest   pointer to the destination buffer.
*   @param[in]  Value   Value to be set.
*   @param[in]  Length  number of bytes to be set.
********************************************************************************************************************/
static void CanTp_UtilMemSet(uint8 *DestPtr,uint8 Value,PduLengthType Length)
{
    PduLengthType Idx;
    /* copy number of bytes from [pSrc] to [pDest]. */
    for (Idx = 0U; Idx < Length; Idx++)
    {
        DestPtr[Idx] = Value; 
    }
}

/*!**************************************************************************************************************** 
*   @brief      This method is used to get STMin timer value.
*   @param[in]  StMinValue  received STMin value.
********************************************************************************************************************/
static uint32 CanTp_UtilGetTimeInCyclicPeriod(uint8 StMinValue)
{
    uint32 CanTp_STminTimer = 0U;
    uint8 CanTp_ModVal = (uint8)((StMinValue)%(CANTP_MAIN_FUNCTION_PERIOD));
    uint8 CanTp_DivVal = (uint8)((StMinValue)/(CANTP_MAIN_FUNCTION_PERIOD));
    
    if(CanTp_DivVal > 0U)
    {
        if(CanTp_ModVal == 0U)
        {
            /*STMin is multiple of MainFunctionPeriod*/
            CanTp_STminTimer = (uint32)(CanTp_DivVal+CANTP_JITTER_VAL);
        }
        else
        {
            /*STMin is not a multiple of MainFunctionPeriod*/
            CanTp_STminTimer = (uint32)(CanTp_DivVal+CANTP_JITTER_VAL+1U);
        }
    }
    else
    {
        if(CanTp_ModVal == 0U)
        {
            /*STMin is 0*/
            CanTp_STminTimer = 1;
        }
        else
        {
            /*STMin < MainFunctionPeriod and not equal to 0*/
            CanTp_STminTimer = CANTP_JITTER_VAL+1U;
        }
    }
    return CanTp_STminTimer;
}
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
/******************************************************************************************************************* 
*   For each change to this file, be sure to record:                                                               *
*      1.  who made the change and when the change was made                                                        *
*      2.  why the change was made and the intended result                                                         *
*   Following block needs to be repeated for each change                                                           *
*******************************************************************************************************************/
/*!****************************************************************************************************************
 *  @date 12-Mar-2020
 *  @version 0.0.1
 *  @author  pchinnat
 *  @note Traceability - RTC# 80445 - Initial version
 ******************************************************************************************************************/
/*!*****************************************************************************************************************
*  @date 3-Feb-2021
*  @author  pmanoj2
*  @brief Traceability - 1206950: 1206951: [hondabev] CERTC New rules(CAN)
*
*******************************************************************************************************************/


