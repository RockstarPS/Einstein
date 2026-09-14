/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2020 by Visteon Corporation.       All rights reserved.                                             *
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
*    @file IpduM.c
*    @ingroup IpduM
*    @brief This file implements the AUTOSAR IpduM module.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "IpduM.h"
#include "PduR_IpduM.h"
#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
/********************************************************************************************************************
*  Version check                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if((IPDUM_SW_MAJOR_VERSION != IPDUM_CFG_SW_MAJOR_VERSION) || \
    (IPDUM_SW_MINOR_VERSION != IPDUM_CFG_SW_MINOR_VERSION) || \
    (IPDUM_SW_PATCH_VERSION != IPDUM_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if((IPDUM_AR_RELEASE_MAJOR_VERSION != IPDUM_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (IPDUM_AR_RELEASE_MINOR_VERSION != IPDUM_CFG_AR_RELEASE_MINOR_VERSION) || \
    (IPDUM_AR_RELEASE_REVISION_VERSION != IPDUM_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif
/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
typedef struct
{
    PduIdType IpduMPduId;
    PduLengthType  IpduMSduLength;
    uint8 IpduMBufferIndex;
} IpduM_ContainerRxBufferConfigType;
typedef struct
{
    uint8 IpduTxMBufferIndex;
    uint8 IpduMTxBufferSize;
} IpduM_ContainerTxBufferConfigType;
static boolean IpduM_InitStatus = FALSE;
static uint8 IpduM_TxBuffer[IPDUM_TX_BUFFER_SIZE];
/*! @brief utility lookuop for bit width mask  */
/* misra_c_2012_rule_8_9_violation : Not an Functional Impact */
static uint8 const IpduM_UtilBitWidthMasks[9] =
{
    0x00U,  /* 0 Bits Wide  */
    0x01u,  /* 1 Bits Wide */
    0x03u,  /* 2 Bits Wide  */
    0x07u,  /* 3 Bits Wide  */
    0x0Fu,  /* 4 Bits Wide  */
    0x1Fu,  /* 5 Bits Wide  */
    0x3Fu,  /* 6 Bits Wide  */
    0x7Fu,  /* 7 Bits Wide  */
    0xFFu   /* 8 Bits Wide  */
};
static boolean IpduM_ContainerRxPduProcessPendingSts[IPDUM_NUM_OF_RX_CONTAINER_IPDU];
static uint8 IpduM_ContainerRxQueueIndex[IPDUM_NUM_OF_RX_CONTAINER_IPDU];
static uint8 IpduM_ContainerTxQueueIndex[IPDUM_NUM_OF_TX_CONTAINER_IPDU];/* misra_c_2012_rule_8_9_violation: Not an functional impact*/
static IpduM_ContainerRxBufferConfigType IpduM_ContainerRxBufferConfig[IPDUM_NUM_OF_RX_CONTAINER_IPDU][IPDUM_MAX_CONTAINER_QUEUE_SIZE];
static IpduM_ContainerTxBufferConfigType IpduM_ContainerTxBufferConfig[IPDUM_NUM_OF_TX_CONTAINER_IPDU][IPDUM_MAX_CONTAINER_QUEUE_SIZE];
static uint8 IpduM_ContainerTxConfirmationTimeout[IPDUM_NUM_OF_TX_CONTAINER_IPDU];
static uint8 IpduM_ContainerRxBuffer[IPDUM_NUM_OF_RX_CONTAINER_IPDU][IPDUM_MAX_CONTAINER_BUFFER];
static uint8 IpduM_ContainerTxBuffer[IPDUM_NUM_OF_TX_CONTAINER_IPDU][IPDUM_MAX_CONTAINER_BUFFER];
static PduInfoType IpduM_PduInfo;
static uint8 IpduM_PduInfoBuffer[IPDUM_MAX_CONTAINER_BUFFER];
#if (STD_ON == IPDUM_DEV_ERROR_DETECT)
/*! Macro for adding module Id and insatance to the Det Report error call */
#define IpduM_DetReportError(ApiId,ErrorId) (void)Det_ReportError(IPDUM_MODULE_ID,IPDUM_INSTANCE_ID,ApiId,ErrorId)
#endif
/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/
static uint32 IpduMTxConfirmationTimeoutVal[IPDUM_NUM_OF_TX_MESSAGE];
static PduIdType IpduMLastTransmitTxPart[IPDUM_NUM_OF_TX_MESSAGE];
/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
static void IpduM_CopySegmentstoTxBuffer(PduIdType PdumTxPduId, const PduInfoType* PduInfoPtr);
static void IpduM_UtilBitCopy(IpduM_UtilBitCopyPropsType * UtilBitCopyPropsPtr,
                              uint8 const *const SrcBufferPtr,uint8 * const DestBufferPtr);
static void IpduM_UtilSetClearBitMask (uint8 *const DataPtr, uint8 const BitMask, boolean SetMode);
static void IpduM_ProcessImmediateContainerRxPdu(PduIdType PduId, const PduInfoType* PduInfoPtr);
static void IpduM_StoreToContainerBuffer(PduIdType PduId, const PduInfoType* PduInfoPtr);
static void IpduM_ProcessDeferredContainerRxPdu(PduIdType PduId);
static void IpduM_ProcessContainerTxPdu(PduIdType DestIpduMId, const PduInfoType* PduInfoPtr);
/* Local utility Function for mem copy */
static void IpduM_UtilMemCpy(uint8 *DestPtr,const uint8 * const SrcPtr,PduLengthType Length);
/* Local utility Function for mem set */
static void IpduM_UtilMemSet(uint8 *DestPtr,uint8 Value,PduLengthType Length);
/********************************************************************************************************************
*   @brief      Initializes the I-PDU Multiplexer.
*   @param[in]  config  Implementation specific structure with configuration parameters.
*   @ServiceID  0x00
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
*   @note
********************************************************************************************************************/
void IpduM_Init(const IpduM_ConfigType* config)
{
    PduIdType PduId = 0U;
    uint8 BufferId = 0U;
    uint8 IpduMQueueIndex = 0U;
    uint8 ErrorId = IPDUM_E_NO_ERROR;

    IPDUM_IGNORE_UNUSED_PARAM(config);

    /* Check whether Module is initialized or not */
    if (TRUE == IpduM_InitStatus)
    {
        ErrorId = IPDUM_E_ALREADY_INITIALIZED;
    }
    else
    {
        for (PduId = 0U; PduId < IPDUM_NUM_OF_TX_MESSAGE; PduId++)
        {
            /* Initialize Tx Confirmation Timeout Value */
            IpduMTxConfirmationTimeoutVal[PduId] = 0;
            /* Initialize IpduMLastTransmitTxPart */
            IpduMLastTransmitTxPart[PduId] = 0;
        }
        for (BufferId = 0U; BufferId < IPDUM_TX_BUFFER_SIZE; BufferId++)
        {
            /* Initialize Tx Buffer */
            IpduM_TxBuffer[BufferId] = IpduM_TxBufferInitValues[BufferId];
        }
        
        for (PduId = 0; PduId < IPDUM_NUM_OF_TX_CONTAINER_IPDU; PduId++)
        {
            /* Initialize Memory */
            IpduM_UtilMemSet((&IpduM_ContainerTxBuffer[PduId][0]), 0x00, IPDUM_MAX_CONTAINER_BUFFER);
            for (IpduMQueueIndex = 0; IpduMQueueIndex < IPDUM_MAX_CONTAINER_QUEUE_SIZE;IpduMQueueIndex++)
            {
                /* Initialize IpduTxMBufferIndex */
                IpduM_ContainerTxBufferConfig[PduId][IpduMQueueIndex].IpduTxMBufferIndex = 0;
                /* Initialize IpduMTxBufferSize */
                IpduM_ContainerTxBufferConfig[PduId][IpduMQueueIndex].IpduMTxBufferSize = 0;
            }
        }
        
        for (PduId = 0U; PduId < IPDUM_NUM_OF_RX_CONTAINER_IPDU; PduId++)
        {
            /* Initialize IpduM_ContainerRxQueueIndex */
            IpduM_ContainerRxQueueIndex[PduId] = 0;
            /* Initialize IpduM_ContainerRxPduProcessPendingSts */
            IpduM_ContainerRxPduProcessPendingSts[PduId] = FALSE;
            /* Initialize Memory */
            IpduM_UtilMemSet((&IpduM_ContainerRxBuffer[PduId][0]), 0x00, IPDUM_MAX_CONTAINER_BUFFER);
            
            /* Initialize Rx Container Buffer */
            for (IpduMQueueIndex = 0; IpduMQueueIndex < IPDUM_MAX_CONTAINER_QUEUE_SIZE; IpduMQueueIndex++)
            {
                /* Initialize IpduMPduId */
                IpduM_ContainerRxBufferConfig[PduId][IpduMQueueIndex].IpduMPduId = 0;
                /* Initialize IpduMSduLength */
                IpduM_ContainerRxBufferConfig[PduId][IpduMQueueIndex].IpduMSduLength = 0;
                /* Initialize IpduMBufferIndex */
                IpduM_ContainerRxBufferConfig[PduId][IpduMQueueIndex].IpduMBufferIndex = 0;
            }
        }
        /* Initialize Memory */
        IpduM_UtilMemSet((&IpduM_PduInfoBuffer[0]), 0x00, IPDUM_MAX_CONTAINER_BUFFER);
        /* update Init status */
        IpduM_InitStatus = TRUE;
    }
#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
    if(IPDUM_E_NO_ERROR != ErrorId)
    {
        IpduM_DetReportError(IPDUM_INIT_API, ErrorId);
    }
#else
    IPDUM_DUMMY_STATEMENT(ErrorId);
#endif
}
#if (IPDUM_VERSION_INFO_API == STD_ON)
/********************************************************************************************************************
*   @brief      Pointer to where to store the version information of this module.
*   @param[in]  None.
*   @param[out] versioninfo Pointer to where to store the version information of this module.
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
*   @note
********************************************************************************************************************/
/* misra_c_2012_rule_8_7_violation : The declaration IpduM_GetVersionInfo will be used by other components in future*/
void IpduM_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
    /* Local Variables */
    uint8 ErrorId = IPDUM_E_NO_ERROR;
#endif

#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
    /* Check if Parameter VersionInfo is valid */
    if (NULL_PTR == VersionInfo)
    {
        ErrorId = IPDUM_E_PARAM_POINTER;
    }
    else
#endif
    {
        VersionInfo->vendorID         = IPDUM_VENDOR_ID;
        VersionInfo->moduleID         = IPDUM_MODULE_ID;
        VersionInfo->sw_major_version = IPDUM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = IPDUM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = IPDUM_SW_PATCH_VERSION;
    }
#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
    if(IPDUM_E_NO_ERROR != ErrorId)
    {
        IpduM_DetReportError(IPDUM_GETVERSIONINFO_API, ErrorId);
    }
#endif
}
#endif
/********************************************************************************************************************
*   @brief      Service is called by the PDU-Router to request a transmission.
*   @param[in]  PdumTxPduId  ID of I-PDU to be transmitted.
*   @param[in]  PduInfoPtr  A pointer to a structure with I-PDU related data that shall be transmitted:
*               data length and pointer to I-SDU buffer.
*   @ServiceID  0x03
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
*   @note
********************************************************************************************************************/
Std_ReturnType IpduM_Transmit(PduIdType PdumTxPduId, const PduInfoType* PduInfoPtr)
{
    IpduM_PduMapConfigType const *pIpduM_PduMapConfig;
    IpduM_TxPartConfigType const *pIpduM_TxPartConfig;
    IpduM_TxPduConfigType const *pIpduM_TxPduConfig;
    PduIdType DestIpduMId = 0U;
    PduInfoType IpdmTxPduInfo;
    PduIdType TxIpduId = 0U;
    uint32 TxBufferStartIndex = 0u;
    Std_ReturnType RetVal =  E_NOT_OK;
    uint8 ErrorId = IPDUM_E_NO_ERROR;

    /* Check whether Module is initialized or not */
    if (TRUE != IpduM_InitStatus)
    {
        ErrorId = IPDUM_E_UNINIT;
    }
#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
    else if (IPDUM_PDU_TX_NUM_OF_PARTS <= PdumTxPduId)
    {
        ErrorId = IPDUM_E_PARAM;
    }
    else if ((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr))
    {
        ErrorId = IPDUM_E_PARAM_POINTER;
    }
#endif
    else
    {
        /* Get pIpduM_PduMapConfig */
        pIpduM_PduMapConfig = &IpduM_TxPduMapConfig[PdumTxPduId];
        /* Get DestIpduMId */
        DestIpduMId = pIpduM_PduMapConfig -> DestIpduMId;
        /* Check IpduMPduIdType */
        if (IPDUM_ID_TYPE_MULTIPLEX == pIpduM_PduMapConfig -> IpduMPduIdType)
        {
            if(IPDUM_PDU_TX_NUM_OF_PARTS > DestIpduMId ) /*Cert-c Fix*/
            {
                /* Get IpduM_TxPartConfig */
                pIpduM_TxPartConfig = &IpduM_TxPartConfig[DestIpduMId];

                /* Get Tx Pdu Id */
                TxIpduId = pIpduM_TxPartConfig -> TxIpduId;
                /* Check added to resolve Coverity Out of bound Warning */
                if (IPDUM_NUM_OF_TX_MESSAGE > TxIpduId)
                {
                    /* Get pIpduM_TxPduConfig */
                    pIpduM_TxPduConfig = &IpduM_TxPduConfig[TxIpduId];
#if(IPDUM_STATIC_PART_EXISTS != STD_ON)
                    /* Don't care Static Part */
                    if (IPDUM_PART_TYPE_STATIC != pIpduM_TxPartConfig -> PartType)
#endif
                    {
                        /* Check whether Tx confirmation is enable or not */
                        if ((FALSE == pIpduM_TxPartConfig -> IsTxConfirmationEnabled) ||
                                (0U == IpduMTxConfirmationTimeoutVal[TxIpduId]))
                        {
                            /* Get IpduMTxConfirmationTimeoutVal */
                            IpduMTxConfirmationTimeoutVal[TxIpduId] = pIpduM_TxPduConfig -> TxConfirmationTimeout;
                            /* Assemble IpdmTxPduInfo */
                            /* Get SduLength */
                            IpdmTxPduInfo.SduLength = PduInfoPtr -> SduLength;
                            /* Get SduDataPtr */
                            IpdmTxPduInfo.SduDataPtr = PduInfoPtr -> SduDataPtr;
                            TxBufferStartIndex = IpduM_TxBufferConfig[TxIpduId].BufferStartIdx;
                            /* Check whether JIT update is enabled */
                            if (TRUE == pIpduM_TxPartConfig -> IsJitUpdateSupported)
                            {
                                IpdmTxPduInfo.SduDataPtr = &IpduM_TxBuffer[TxBufferStartIndex];
                                /* Get latest signal Info */
                                (void) PduR_IpduMTriggerTransmit(DestIpduMId, &IpdmTxPduInfo);
                            }
                            else
                            {
                                /* Copy segments */
                                IpduM_CopySegmentstoTxBuffer(DestIpduMId, &IpdmTxPduInfo);
                            }
                            #if(IPDUM_STATIC_PART_EXISTS == STD_ON)
                            /* Copy static segments if the requested part is dynamic */
                            if ((TRUE == pIpduM_TxPduConfig -> IsStaticPartExist) &&
                                (IPDUM_PART_TYPE_STATIC != pIpduM_TxPartConfig -> PartType) &&(IPDUM_NUM_OF_TX_IPDU_ID > pIpduM_TxPduConfig->StaticPartPduRef ))
                            {
                                pIpduM_PduMapConfig = &IpduM_TxPduMapConfig[pIpduM_TxPduConfig->StaticPartPduRef];
                                /* Copy segments of static part */
                                IpduM_CopySegmentstoTxBuffer(pIpduM_PduMapConfig->DestIpduMId, &IpdmTxPduInfo);
                            }
                            #endif
                            /* Get SduDataPtr */
                            IpdmTxPduInfo.SduDataPtr = &IpduM_TxBuffer[TxBufferStartIndex];
                            /* Initiate Transmission */
                            if (((IPDUM_TX_TRIGGER_MODE_STATIC_PART_TRIGGER == pIpduM_TxPduConfig -> TxTriggerMode) && (IPDUM_PART_TYPE_STATIC == pIpduM_TxPartConfig -> PartType)) ||
                                ((IPDUM_TX_TRIGGER_MODE_DYNAMIC_PART_TRIGGER == pIpduM_TxPduConfig -> TxTriggerMode) && (IPDUM_PART_TYPE_DYNAMIC == pIpduM_TxPartConfig -> PartType)) ||
                                (IPDUM_TX_TRIGGER_MODE_STATIC_OR_DYNAMIC_PART_TRIGGER == pIpduM_TxPduConfig -> TxTriggerMode))
                            {
                                /* Invoke PduR_IpduMTransmit */
                                RetVal = PduR_IpduMTransmit(pIpduM_TxPduConfig->TxLowerPduId, &IpdmTxPduInfo);
                                /* Update IpduMLastTransmitTxPart */
                                IpduMLastTransmitTxPart[TxIpduId] = PdumTxPduId;
                            }
                        }
                    }
                }
            }  /* Coverity Fix Story 164900 */
        }
        else
        {
            /* Process Container Pdu */
            IpduM_ProcessContainerTxPdu(DestIpduMId, PduInfoPtr);
        }
    }
#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
    if(IPDUM_E_NO_ERROR != ErrorId)
    {
        IpduM_DetReportError(IPDUM_TRANSMIT_API, ErrorId);
    }
#else
    IPDUM_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      Indication of a received I-PDU from a lower layer communication interface module.
*   @param[in]  RxPduId  ID of the received I-PDU.
*   @param[in]  PduInfoPtr  Contains the length (SduLength) of the received I-PDU
*               and a pointer to a buffer (SduDataPtr) containing the I-PDU.
*   @ServiceID  0x42
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
*   @note
********************************************************************************************************************/
void IpduM_RxIndication(PduIdType RxPduId, const PduInfoType* PduInfoPtr)
{
    IpduM_PduMapConfigType const *pIpduM_PduMapConfigType;
    IpduM_RxPduConfigType const *pIpduM_RxPduConfig;
    IpduM_BufferConfigType const *pIpduM_BufferConfig;
    IpduM_ContainerRxPduConfigType const *pIpduM_ContainerRxPduConfig;
    void* SignalDataPtr = NULL_PTR;
    uint16 SignalData = 0U;
    IpduM_UtilBitCopyPropsType UtilBitCopyProps;
    uint8 DynamicPartId = 0U;
    PduIdType DestIpduMId = 0U;
    boolean DynamicPartConfigStatus = FALSE;
    uint8 ErrorId = IPDUM_E_NO_ERROR;

    /* Check whether Module is initialized or not */
    if (TRUE != IpduM_InitStatus)
    {
        ErrorId = IPDUM_E_UNINIT;
    }
#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
    else if (IPDUM_RX_NUM_OF_MSG <= RxPduId)
    {
        ErrorId = IPDUM_E_PARAM;
    }
    else if ((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr))
    {
        ErrorId = IPDUM_E_PARAM_POINTER;
    }
#endif
    else
    {
        /* Get pIpduM_PduMapConfigType */
        pIpduM_PduMapConfigType = &IpduM_RxPduMapConfig[RxPduId];
        /* Get DestIpduMId */
        DestIpduMId = pIpduM_PduMapConfigType -> DestIpduMId;
        /* Check IpduMPduIdType */
        if (IPDUM_ID_TYPE_MULTIPLEX == pIpduM_PduMapConfigType -> IpduMPduIdType)
        {
            /* Get pIpduM_RxPduConfig */
            pIpduM_RxPduConfig = &IpduM_RxPduConfig[DestIpduMId];
            /* Get pIpduM_BufferConfig */
            pIpduM_BufferConfig = &IpduM_RxBufferConfig[DestIpduMId];
            /* Get buffer for the Pdu */
            UtilBitCopyProps.SignalLengthInBits  = pIpduM_RxPduConfig->SelectorFieldBitLength;
            UtilBitCopyProps.SingalLengthInBytes = pIpduM_RxPduConfig->SelectorFieldByteLength;
            /* Update the bit copy details */
            UtilBitCopyProps.SrcLsBit = pIpduM_RxPduConfig->SelectorFieldLsBitIdx;
            UtilBitCopyProps.SrcLsByte = pIpduM_RxPduConfig->SelectorFieldLsByteIdx;
            if (IPDUM_BIG_ENDIAN == pIpduM_RxPduConfig->ByteOrder)
            {
                UtilBitCopyProps.SrcBufferEndianess = IPDUM_BIG_ENDIAN;
            }
            else
            {
                /* Opaque uint8[n] is for same as Little Endian , bit 0 in byte 0*/
                UtilBitCopyProps.SrcBufferEndianess = IPDUM_LITTLE_ENDIAN;
            }
            UtilBitCopyProps.MaxSrcBufferSize = PduInfoPtr->SduLength;
            #if(IPDUM_HEADER_BYTE_ORDER == IPDUM_LITTLE_ENDIAN)
            UtilBitCopyProps.DestLsBit = 0U;
            UtilBitCopyProps.DestLsByte = 0U;
            UtilBitCopyProps.DestBufferEndianess = IPDUM_LITTLE_ENDIAN;
            #else
            UtilBitCopyProps.DestLsBit = 0U;
            UtilBitCopyProps.DestLsByte = pIpduM_RxPduConfig->SelectorFieldByteLength;
            UtilBitCopyProps.DestBufferEndianess = IPDUM_BIG_ENDIAN;
            #endif
            UtilBitCopyProps.MaxDestBufferSize = pIpduM_BufferConfig->BufferSize;
            /* Initialize SignalDataPtr */
            SignalDataPtr = &SignalData;

            if (IPDUM_RX_BUFFER_SIZE > pIpduM_BufferConfig->BufferStartIdx)
            {
                /* copy the data from TxIpdu buffer to SignalDataPtr */
                IpduM_UtilBitCopy(&UtilBitCopyProps, (PduInfoPtr -> SduDataPtr),(uint8*)SignalDataPtr);
            }
            for (DynamicPartId = pIpduM_RxPduConfig->RxDynPartStartIdx;
                (DynamicPartId <= pIpduM_RxPduConfig->RxDynPartEndIdx)&&(DynamicPartId < IPDUM_NUM_OF_RX_DYNAMIC_PARTS);
                 DynamicPartId++)
            {
                /* Check whether the received selector field is valid */
                if (*((uint16*)SignalDataPtr) == IpduM_RxDynPartConfig[DynamicPartId].SelectorFieldValue)
                {
                    DynamicPartConfigStatus = TRUE;
                    break;
                }
            }
            if (TRUE == DynamicPartConfigStatus)
            {
                /* Invoke PduR_IpduMRxIndication for Dynamic Part */
                PduR_IpduMRxIndication((IpduM_RxDynPartConfig[DynamicPartId].DynPartUpperPduId), PduInfoPtr);
            }
            #if(IPDUM_STATIC_PART_EXISTS == STD_ON)
            if (TRUE == pIpduM_RxPduConfig -> IsStaticPartExist)
            {
                /* Invoke PduR_IpduMRxIndication for Dynamic Part */
                PduR_IpduMRxIndication((pIpduM_RxPduConfig -> StaticPartUpperPduId), PduInfoPtr);
            }
            #endif
        }
        else
        {
            /* Get pIpduM_ContainerRxPduConfig */
            pIpduM_ContainerRxPduConfig = &IpduM_ContainerRxPduConfig[DestIpduMId];
            /* Check ContainerPduProcessingType */
            if (IPDUM_PROCESSING_IMMEDIATE == pIpduM_ContainerRxPduConfig -> ContainerPduProcessingType)
            {
                /* Process IpduM_ProcessImmediateContainerRxPdu */
                IpduM_ProcessImmediateContainerRxPdu(DestIpduMId, PduInfoPtr);
            }
            else
            {
                /* Store to Container Buffer */
                IpduM_StoreToContainerBuffer(DestIpduMId, PduInfoPtr);
                /* Update IpduM_ContainerRxPduProcessPendingSts and process in main function */
                IpduM_ContainerRxPduProcessPendingSts[DestIpduMId] = TRUE;
            }
        }
    }
#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
    if(IPDUM_E_NO_ERROR != ErrorId)
    {
        IpduM_DetReportError(IPDUM_RXINDICATION_API, ErrorId);
    }
#else
    IPDUM_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      The lower layer communication interface module confirms the transmission of an I-PDU.
*   @param[in]  TxPduId ID of the I-PDU that has been transmitted.
*   @ServiceID  0x40
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
*   @note
********************************************************************************************************************/
void IpduM_TxConfirmation(PduIdType TxPduId, Std_ReturnType Result)
{
    IpduM_PduMapConfigType const *pIpduM_PduMapConfig;
    IpduM_TxPartConfigType const *pIpduM_TxPartConfig;
    IpduM_ContainerTxPduConfigType const *pIpduM_ContainerTxPduConfig;
    IpduM_ContainedTxPduConfigType const *pIpduM_ContainedTxPduConfig;
    PduIdType DestIpduMId = 0U;
    PduIdType LastTranmitTxPart = 0U;
    PduIdType UpperLayerNotifyPduId = 0U;
    uint8 PduIndex = 0U;
    uint8 ErrorId = IPDUM_E_NO_ERROR;

    IPDUM_IGNORE_UNUSED_PARAM(Result);

    /* Check whether Module is initialized or not */
    if (TRUE != IpduM_InitStatus)
    {
        ErrorId = IPDUM_E_UNINIT;
    }
#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
    else if (IPDUM_NUM_OF_TX_MESSAGE <= TxPduId)
    {
        ErrorId = IPDUM_E_PARAM;
    }
#endif
    else
    {
        /* Get pIpduM_PduMapConfig */
        pIpduM_PduMapConfig = &IpduM_TxPduMapConfig[TxPduId];
        /* Get DestIpduMId */
        DestIpduMId = pIpduM_PduMapConfig -> DestIpduMId;
        /* Check IpduMPduIdType */
        if (IPDUM_ID_TYPE_MULTIPLEX == pIpduM_PduMapConfig ->  IpduMPduIdType)
        {
            /* Check Tx confimation value */
            /* Skip Tx confirmation if timeout is reached */
            if (0U != IpduMTxConfirmationTimeoutVal[DestIpduMId])
            {
                /* Get LastTranmitTxPart */
                LastTranmitTxPart = IpduMLastTransmitTxPart[DestIpduMId];
                /* Check added to resolve Coverity Out of bound Warning */
                if (IPDUM_PDU_TX_NUM_OF_PARTS > LastTranmitTxPart)
                {
                    /* Get IpduM_TxPartConfig */
                    pIpduM_TxPartConfig = &IpduM_TxPartConfig[LastTranmitTxPart];
                    /* Invoke PduR_IpduMTxConfirmation */
                    PduR_IpduMTxConfirmation(pIpduM_TxPartConfig-> TxUpperConfirmationPduId);
                    /* Initialize Timeout Val */
                    IpduMTxConfirmationTimeoutVal[DestIpduMId] = 0;
                    /* Initialize IpduMLastTransmitTxPart */
                    IpduMLastTransmitTxPart[DestIpduMId] = 0;
                }
            }
        }
        else
        {
            if (0U != IpduM_ContainerTxConfirmationTimeout[DestIpduMId])
            {
                /* Get pIpduM_ContainerTxPduConfig */
                pIpduM_ContainerTxPduConfig = &IpduM_ContainerTxPduConfig[DestIpduMId];
                /* Loop configured Contained Ipdu */
                for (PduIndex = pIpduM_ContainerTxPduConfig -> ContainedIpduStartIdx;
                     PduIndex < pIpduM_ContainerTxPduConfig -> ContainedIpduEndIdx; PduIndex++)
                {
                    /* Get pIpduM_ContainedTxPduConfig */
                    pIpduM_ContainedTxPduConfig = &IpduM_ContainedTxPduConfig[PduIndex];
                    /* Get UpperLayerNotifyPduId */
                    UpperLayerNotifyPduId =  pIpduM_ContainedTxPduConfig -> UpperLayerNotifyPduId;
                    /* Invoke PduR_IpduMTxConfirmation */
                    PduR_IpduMTxConfirmation(UpperLayerNotifyPduId);
                }
                /* Update IpduM_ContainerTxConfirmationTimeout */
                IpduM_ContainerTxConfirmationTimeout[DestIpduMId] = 0;
            }
        }
    }
#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
    if(IPDUM_E_NO_ERROR != ErrorId)
    {
        IpduM_DetReportError(IPDUM_TXCONFIRMATION_API, ErrorId);
    }
#else
    IPDUM_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      Within this API, the upper layer module (called module) shall check whether the available data
*               fits into the buffer size reported by PduInfoPtr->SduLength. If it fits, it shall copy its data into
*               the buffer provided by PduInfoPtr->SduDataPtr and update the length of the actual copied data in
*               PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing PduInfoPtr.
*   @param[in]  TxPduId  ID of the SDU that is requested to be transmitted.
*   @ServiceID  0x41
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
*   @note
********************************************************************************************************************/
Std_ReturnType IpduM_TriggerTransmit(PduIdType TxPduId, PduInfoType* PduInfoPtr)
{
    Std_ReturnType RetVal =  E_NOT_OK;
    uint8 ErrorId = IPDUM_E_NO_ERROR;

    /* Check whether Module is initialized or not */
    if (TRUE != IpduM_InitStatus)
    {
        ErrorId = IPDUM_E_UNINIT;
    }
#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
    else if (IPDUM_NUM_OF_TX_MESSAGE <= TxPduId)
    {
        ErrorId = IPDUM_E_PARAM;
    }
    else if ((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr))
    {
        ErrorId = IPDUM_E_PARAM_POINTER;
    }
#endif
    else
    {
        /* Invoke PduR_IpduMTriggerTransmit */
        RetVal = PduR_IpduMTriggerTransmit(TxPduId, PduInfoPtr);
    }
#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
    if(IPDUM_E_NO_ERROR != ErrorId)
    {
        IpduM_DetReportError(IPDUM_TRIGGERTRANSMIT_API, ErrorId);
    }
#else
    IPDUM_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      Performs the processes of the activities that are not directly initiated by the calls from PDU-R.
*   @ServiceID  0x10
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
*   @note
********************************************************************************************************************/
/* misra_c_2012_rule_8_7_violation : The declaration IpduM_MainFunction will be used by other components in future */
void IpduM_MainFunction(void)
{
    PduIdType PduId = 0U;
    uint8 ErrorId = IPDUM_E_NO_ERROR;

    /* Check whether Module is initialized or not */
    if (TRUE != IpduM_InitStatus)
    {
        ErrorId = IPDUM_E_UNINIT;
    }
    else
    {
        for (PduId = 0U; PduId < IPDUM_NUM_OF_TX_MESSAGE; PduId++)
        {
            /* Check Tx confimation value */
            if (0U != IpduMTxConfirmationTimeoutVal[PduId])
            {
                /* Decrement Timeout Val */
                IpduMTxConfirmationTimeoutVal[PduId]--;
            }
        }
        for (PduId = 0U; PduId < IPDUM_NUM_OF_RX_CONTAINER_IPDU; PduId++)
        {
            if (TRUE == IpduM_ContainerRxPduProcessPendingSts[PduId])
            {
                /* Process Deferred Container Rx Pdu */
                IpduM_ProcessDeferredContainerRxPdu(PduId);
            }
        }
        for (PduId = 0U; PduId < IPDUM_NUM_OF_TX_CONTAINER_IPDU; PduId++)
        {
            if (0U != IpduM_ContainerTxConfirmationTimeout[PduId])
            {
                IpduM_ContainerTxConfirmationTimeout[PduId]--;
            }
        }
    }
#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
    if(ErrorId != IPDUM_E_NO_ERROR)
    {
        IpduM_DetReportError(IPDUM_MAINFUNCTION_API, ErrorId);
    }
#else
    IPDUM_DUMMY_STATEMENT(ErrorId);
#endif
}
/*******************************************************************************************************************/
/*  Private APIs                                                                                                   */
/*******************************************************************************************************************/
/********************************************************************************************************************
*   @brief      Performs the processes of copying Ipdum Segments to TxBuffer
********************************************************************************************************************/
static void IpduM_CopySegmentstoTxBuffer(PduIdType PdumTxPduId, const PduInfoType* PduInfoPtr)
{
    IpduM_TxPartConfigType const *pIpduM_TxPartConfig;
    IpduM_TxPduConfigType const *pIpduM_TxPduConfig;
    IpduM_TxSegmentConfigType const *pIpduM_TxSegmentConfig;
    IpduM_BufferConfigType const *pIpduM_TxBufferConfig;
    IpduM_UtilBitCopyPropsType UtilBitCopyProps;
    IpduM_TxSegmentIdxType TxSegmentId;
    PduIdType TxIpduId = 0U;

    /* Check added to resolve Coverity Out of bound Warning */
    if (IPDUM_PDU_TX_NUM_OF_PARTS > PdumTxPduId)
    {
        /* Get IpduM_TxPartConfig */
        pIpduM_TxPartConfig = &IpduM_TxPartConfig[PdumTxPduId];
        /* Get Tx Pdu Id */
        TxIpduId = pIpduM_TxPartConfig -> TxIpduId;
        /* Check added to resolve Coverity Out of bound Warning */
        if (IPDUM_NUM_OF_TX_MESSAGE > TxIpduId)
        {
            /* Get pIpduM_TxPduConfig */
            pIpduM_TxPduConfig = &IpduM_TxPduConfig[TxIpduId];
            /* Get pIpduM_TxBufferConfig */
            pIpduM_TxBufferConfig = &IpduM_TxBufferConfig[TxIpduId];
            /* Copy all segments */
            for (TxSegmentId = pIpduM_TxPartConfig -> SegmentStartIdx;
                    TxSegmentId <= pIpduM_TxPartConfig -> SegmentEndIdx; TxSegmentId++)
            {
                /* Check added to resolve Coverity Out of bound Warning */
                if (IPDUM_NUM_OF_TX_SEGMENTS > TxSegmentId)
                {
                    /* Get IpduM_TxSegmentConfig */
                    pIpduM_TxSegmentConfig = &IpduM_TxSegmentConfig[TxSegmentId];
                    /* Get buffer for the Pdu */
                    UtilBitCopyProps.SignalLengthInBits  = pIpduM_TxSegmentConfig->SegmentBitLength;
                    UtilBitCopyProps.SingalLengthInBytes = pIpduM_TxSegmentConfig->SegmentByteLength;
                    /* Update the bit copy details */
                    UtilBitCopyProps.SrcLsBit = pIpduM_TxSegmentConfig->SegmentLsBitIdx;
                    UtilBitCopyProps.SrcLsByte = pIpduM_TxSegmentConfig->SegmentLsByteIdx;
                    /* Get Byte Order */
                    if (IPDUM_BIG_ENDIAN == pIpduM_TxPduConfig->ByteOrder)
                    {
                        UtilBitCopyProps.SrcBufferEndianess = IPDUM_BIG_ENDIAN;
                    }
                    else
                    {
                        /* Opaque uint8[n] is for same as Little Endian , bit 0 in byte 0*/
                        UtilBitCopyProps.SrcBufferEndianess = IPDUM_LITTLE_ENDIAN;
                    }
                    UtilBitCopyProps.MaxSrcBufferSize = PduInfoPtr->SduLength;
#if(IPDUM_HEADER_BYTE_ORDER == IPDUM_LITTLE_ENDIAN)
                    UtilBitCopyProps.DestLsBit = pIpduM_TxSegmentConfig->SegmentLsBitIdx;
                    UtilBitCopyProps.DestLsByte = pIpduM_TxSegmentConfig->SegmentLsByteIdx;
                    UtilBitCopyProps.DestBufferEndianess = IPDUM_LITTLE_ENDIAN;
#else
                    UtilBitCopyProps.DestLsBit = 0U;
                    UtilBitCopyProps.DestLsByte = pIpduM_TxSegmentConfig->SegmentByteLength;
                    UtilBitCopyProps.DestBufferEndianess = IPDUM_BIG_ENDIAN;
#endif
                    UtilBitCopyProps.MaxDestBufferSize = pIpduM_TxBufferConfig->BufferSize;
                    if (IPDUM_TX_BUFFER_SIZE > pIpduM_TxBufferConfig->BufferStartIdx)
                    {
                        /* copy the data from SignalDataPtr to TxIpdu buffer */
                        IpduM_UtilBitCopy(&UtilBitCopyProps,(uint8*)PduInfoPtr->SduDataPtr,
                                          &IpduM_TxBuffer[pIpduM_TxBufferConfig->BufferStartIdx]);
                    }
                }
            }
        }
    }
}
/********************************************************************************************************************
*   Service Name     : IpduM_UtilBitCopy
*   @brief      Performs the processes of copying Ipdum UtilBit
********************************************************************************************************************/
static void IpduM_UtilBitCopy(IpduM_UtilBitCopyPropsType * UtilBitCopyPropsPtr,
                              uint8 const *const SrcBufferPtr,uint8 * const DestBufferPtr) /* misra_c_2012_rule_8_13_violation : Not an Functional impact*/
{
    uint8 destBufferByteIndex = 0U;
    uint8 destBufferBitOffset = 0U;
    uint8 srcBufferBitOffset = 0U;
    uint8 srcBufferByteIndex = 0U;
    uint8 copyBitPosition = 0U;
    uint32 remainingSignalLength = 0U;
    uint8 noOfBitsToCopy = 0U;
    uint8 tempSrcValue = 0U;

    /* Set the initial position of destination buffer byte index */
    destBufferByteIndex = UtilBitCopyPropsPtr->DestLsByte;
    /* Set the initial position of destination buffer bit index */
    destBufferBitOffset = UtilBitCopyPropsPtr->DestLsBit;
    /* Set the initial position of source buffer bit index */
    srcBufferBitOffset = UtilBitCopyPropsPtr->SrcLsBit;
    /* Set the initial position of source buffer Byte index */
    srcBufferByteIndex = UtilBitCopyPropsPtr->SrcLsByte;
    /* Set the initial position of copy bit */
    copyBitPosition = 0;
    /* set remaining signal length */
    remainingSignalLength = UtilBitCopyPropsPtr->SignalLengthInBits;
    /* Coverity Fix */
    if ((8U > destBufferBitOffset) && (8U > srcBufferBitOffset))
    {
        /* Copy to destination data buffer , should be in critical section */
        IpduM_EnterCriticalSection();
        while((remainingSignalLength!=0U) &&
            (UtilBitCopyPropsPtr->MaxDestBufferSize > destBufferByteIndex)  &&
            (UtilBitCopyPropsPtr->MaxSrcBufferSize > srcBufferByteIndex))
        {
            /* find bits position for copy in current iteration*/
            if ((0U == destBufferBitOffset) && (0U != srcBufferBitOffset))
            {
                copyBitPosition = 8U-srcBufferBitOffset;
            }
            else if((0U == srcBufferBitOffset) && (0U != destBufferBitOffset))
            {
                copyBitPosition = 8U-destBufferBitOffset;
            }
            else
            {
                copyBitPosition = 8U-destBufferBitOffset;
            }
            /* Get the number of bits to be copied in the current iteration , select the minimum*/
            if (remainingSignalLength<copyBitPosition)
            {
                noOfBitsToCopy = remainingSignalLength;
            }
            else
            {
                noOfBitsToCopy = copyBitPosition;
            }
            /* Get the source byte to be copied for current iteration*/
            tempSrcValue = SrcBufferPtr[srcBufferByteIndex] >> srcBufferBitOffset;
            tempSrcValue &= IpduM_UtilBitWidthMasks[noOfBitsToCopy];
            tempSrcValue = (tempSrcValue << destBufferBitOffset);
            /* Copy it to the destination */
            /* First Clear the Signal Bits in the MSByte */
            IpduM_UtilSetClearBitMask(&DestBufferPtr[destBufferByteIndex],
                                    (IpduM_UtilBitWidthMasks[noOfBitsToCopy] << destBufferBitOffset), FALSE);
            DestBufferPtr[destBufferByteIndex] |= tempSrcValue;

            /* Update source buffer offset and index */
            if (IPDUM_LITTLE_ENDIAN == UtilBitCopyPropsPtr->SrcBufferEndianess)
            {
                srcBufferByteIndex += (srcBufferBitOffset+copyBitPosition)/8U;
            }
            else
            {
                srcBufferByteIndex -= (srcBufferBitOffset+copyBitPosition)/8U;
            }
            srcBufferBitOffset = (srcBufferBitOffset+copyBitPosition) % 8U;
            /* Update destination buffer offset and index */
            if (IPDUM_LITTLE_ENDIAN == UtilBitCopyPropsPtr->DestBufferEndianess)
            {
                /* for Intel format */
                destBufferByteIndex +=((destBufferBitOffset+copyBitPosition)/8U);
            }
            else
            {
                /* for Motorola format */
                destBufferByteIndex -=((destBufferBitOffset+copyBitPosition)/8U);
            }
            destBufferBitOffset = ((destBufferBitOffset+copyBitPosition) % 8U);
            /* Update the remaining signal length */
            remainingSignalLength -= noOfBitsToCopy;
        }
    IpduM_ExitCriticalSection();
    }
}
/********************************************************************************************************************
*   Service Name     : IpduM_UtilSetClearBitMask
*   @brief      Performs the processes of clearing Ipdum UtilSetBitMask
********************************************************************************************************************/
static void IpduM_UtilSetClearBitMask (uint8 *const DataPtr, uint8 const BitMask, boolean SetMode)
{
    IpduM_EnterCriticalSection();
    if(TRUE == SetMode)
    {
        (*(DataPtr)) |= BitMask;
    }
    else
    {
        (*(DataPtr)) &= ((0xFFU) ^ (BitMask));
    }
    IpduM_ExitCriticalSection();
}
/********************************************************************************************************************
*   Service Name     : IpduM_ProcessImmediateContainerRxPdu
*   @brief             Performs the processes of clearing Ipdum UtilSetBitMask
********************************************************************************************************************/
static void IpduM_ProcessImmediateContainerRxPdu(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    IpduM_ContainerRxPduConfigType const *pIpduM_ContainerRxPduConfig;
    IpduM_ContainedRxPduConfigType const *pIpduM_ContainedRxPduConfig;
    uint8 PduIndex;

    if(IPDUM_NUM_OF_RX_CONTAINER_IPDU > PduId) /*Cert-c Fix*/
    {
        /* Get IpduM_ContainerRxPduConfig */
        pIpduM_ContainerRxPduConfig = &IpduM_ContainerRxPduConfig[PduId];
        /* Process all Contained Pdu */
        for (PduIndex = pIpduM_ContainerRxPduConfig -> ContainedIpduStartIdx;
             PduIndex <= pIpduM_ContainerRxPduConfig -> ContainedIpduEndIdx; PduIndex++)
        {
            /* Get pIpduM_ContainedRxPduConfig */
            pIpduM_ContainedRxPduConfig = &IpduM_ContainedRxPduConfig[PduIndex];
            /* Invoke PduR_IpduMRxIndication for Dynamic Part */
            PduR_IpduMRxIndication((pIpduM_ContainedRxPduConfig -> UpperLayerNotifyPduId), PduInfoPtr);
        }
    }
}
/********************************************************************************************************************
*   Service Name     : IpduM_StoreToContainerBuffer
********************************************************************************************************************/
static void IpduM_StoreToContainerBuffer(PduIdType PduId, const PduInfoType* PduInfoPtr)
{
    uint32 IpduM_RemainingBufferLength = 0U;
    uint32 IpduM_BufferStartIndex = 0U;
    uint8 IpduMQueueIndex = 0U;

    /* Get Queue Index */
    IpduMQueueIndex = IpduM_ContainerRxQueueIndex[PduId];
    /* Get Buffer start Index */
    IpduM_BufferStartIndex = IpduM_ContainerRxBufferConfig[PduId][IpduMQueueIndex].IpduMBufferIndex;
    /* Get buffer available length */
    IpduM_RemainingBufferLength = IPDUM_MAX_CONTAINER_BUFFER - IpduM_BufferStartIndex;
    /* Check whether Queue count is valid */
    if ((IPDUM_MAX_CONTAINER_QUEUE_SIZE > IpduMQueueIndex) &&
        (IpduM_RemainingBufferLength > PduInfoPtr -> SduLength))
    {
        /* Store IpduMPduId */
        IpduM_ContainerRxBufferConfig[PduId][IpduMQueueIndex].IpduMPduId = PduId;
        /* Store IpduMSduLength */
        IpduM_ContainerRxBufferConfig[PduId][IpduMQueueIndex].IpduMSduLength = PduInfoPtr -> SduLength;
        /* Store Memory */
        IpduM_UtilMemCpy((&IpduM_ContainerRxBuffer[PduId][IpduM_BufferStartIndex]), PduInfoPtr -> SduDataPtr,
                           PduInfoPtr -> SduLength);
        /* Store IpduMBufferIndex */
        IpduM_ContainerRxBufferConfig[PduId][IpduMQueueIndex].IpduMBufferIndex += PduInfoPtr -> SduLength;
        /* Increment Queue Index */
        IpduMQueueIndex++;
        /* Update queue Index */
        IpduM_ContainerRxQueueIndex[PduId] = IpduMQueueIndex;
    }
}
/********************************************************************************************************************
*   Service Name     : IpduM_ProcessDeferredContainerRxPdu
*   @brief   Performs Process dereferred container for RxPdu
********************************************************************************************************************/
static void IpduM_ProcessDeferredContainerRxPdu(PduIdType PduId)
{
    IpduM_ContainerRxPduConfigType const *pIpduM_ContainerRxPduConfig;
    IpduM_ContainedRxPduConfigType const *pIpduM_ContainedRxPduConfig;
    uint8 IpduM_BufferStartIndex = 0U;
    uint8 IpduMQueueIndex = 0U;
    uint8 IpduMQueueCount = 0U;
    uint8 PduIndex = 0U;


    /* Get IpduMQueueIndex */
    if(IPDUM_NUM_OF_RX_CONTAINER_IPDU > PduId ) /*Cert-c Fix*/
    {
        IpduMQueueIndex = IpduM_ContainerRxQueueIndex[PduId];

        for (IpduMQueueCount = 0; IpduMQueueCount < IpduMQueueIndex; IpduMQueueCount++)
        {
            /* Get IpduM_BufferStartIndex */
            IpduM_BufferStartIndex = IpduM_ContainerRxBufferConfig[PduId][IpduMQueueCount].IpduMBufferIndex;
            /* Get SduLength */
            IpduM_PduInfo.SduLength = IpduM_ContainerRxBufferConfig[PduId][IpduMQueueCount].IpduMSduLength;
            /* Get SduDataPtr */
            IpduM_UtilMemCpy((IpduM_PduInfoBuffer),(&IpduM_ContainerRxBuffer[PduId][IpduM_BufferStartIndex]),
                                IpduM_PduInfo.SduLength);
            IpduM_PduInfo.SduDataPtr = IpduM_PduInfoBuffer;
            /* Get IpduM_ContainerRxPduConfig */
            pIpduM_ContainerRxPduConfig = &IpduM_ContainerRxPduConfig[PduId];
            /* Process all Contained Pdu */
            for (PduIndex = pIpduM_ContainerRxPduConfig -> ContainedIpduStartIdx; PduIndex <= pIpduM_ContainerRxPduConfig -> ContainedIpduEndIdx; PduIndex++)
            {
                /* Get pIpduM_ContainedRxPduConfig */
                pIpduM_ContainedRxPduConfig = &IpduM_ContainedRxPduConfig[PduIndex];
                /* Invoke PduR_IpduMRxIndication for Dynamic Part */
                PduR_IpduMRxIndication((pIpduM_ContainedRxPduConfig -> UpperLayerNotifyPduId), &IpduM_PduInfo);
            }
        }

        /* ReInitialize RxQueueIndex */
        IpduM_ContainerRxQueueIndex[PduId] = 0;
        /* Update IpduM_ContainerRxPduProcessPendingSts */
        IpduM_ContainerRxPduProcessPendingSts[PduId] = FALSE;
    } /* Coverity Fix Story 164900 */
}
/********************************************************************************************************************
*   Service Name     : IpduM_ProcessContainerTxPdu
*   @brief   Performs process container fo TxPdu
********************************************************************************************************************/
static void IpduM_ProcessContainerTxPdu(PduIdType DestIpduMId, const PduInfoType* PduInfoPtr)
{
    IpduM_ContainedTxPduConfigType const *pIpduM_ContainedTxPduConfig;
    IpduM_ContainerTxPduConfigType const *pIpduM_ContainerTxPduConfig;
    PduIdType TxInContainerPduId = 0U;
    uint32 TxPduHeaderId = 0U;
    uint32 TxBufferIndex = 0U;
    uint32 TxRemainingBufferSize = 0U;
    uint8 IpduMQueueIndex = 0U;

    /* Get pIpduM_ContainedTxPduConfig */
    if(IPDUM_NUM_OF_TX_CONTAINED_IPDU > DestIpduMId) /*Cert-c Fix*/
    {
        pIpduM_ContainedTxPduConfig = &IpduM_ContainedTxPduConfig[DestIpduMId];
        /* Get TxInContainerPduId */
        TxInContainerPduId = pIpduM_ContainedTxPduConfig -> TxInContainerPduId;
        /* Get pIpduM_ContainerTxPduConfig */
        pIpduM_ContainerTxPduConfig = &IpduM_ContainerTxPduConfig[TxInContainerPduId];
        /* Check IpduM_ContainerTxConfirmationTimeout */
        if (0U == IpduM_ContainerTxConfirmationTimeout[TxInContainerPduId])
        {

            /* Get Queue Index */
            IpduMQueueIndex = IpduM_ContainerTxQueueIndex[TxInContainerPduId];
            /* Get remaing buffer length */
            TxRemainingBufferSize = ((uint32)(IPDUM_MAX_CONTAINER_BUFFER -
                                                    IpduM_ContainerTxBufferConfig[TxInContainerPduId][IpduMQueueIndex].IpduTxMBufferIndex));            /* Check whether TxRemainingBufferSize is valid */
            if ((TxRemainingBufferSize > PduInfoPtr->SduLength) && (IPDUM_MAX_CONTAINER_QUEUE_SIZE > IpduMQueueIndex))
            {
                /* Update IpduMTxBufferSize */
                IpduM_ContainerTxBufferConfig[TxInContainerPduId][IpduMQueueIndex].IpduMTxBufferSize=((uint8)PduInfoPtr->SduLength);
                /* Get TxBufferIndex */
                TxBufferIndex = IpduM_ContainerTxBufferConfig[TxInContainerPduId][IpduMQueueIndex].IpduTxMBufferIndex;
                /* copy header to Tx Buffer */
                if (IPDUM_HEADER_SIZE_TYPE_LONG == pIpduM_ContainerTxPduConfig -> ContainerHeaderSize)
                {
                    /* Get Header Id */
                    TxPduHeaderId = (IPDUM_FULL_HEADER_MASK & (pIpduM_ContainedTxPduConfig -> TxPduHeaderId));
                    /* Copy TxPduHeaderId */
                    IpduM_ContainerTxBuffer[TxInContainerPduId][TxBufferIndex] = TxPduHeaderId;
                    /* Increment TxBufferIndex */
                    TxBufferIndex += 0x08U;
                    /* Update IpduTxMBufferIndex */
                    IpduM_ContainerTxBufferConfig[TxInContainerPduId][IpduMQueueIndex].IpduTxMBufferIndex = TxBufferIndex;
                }
                else
                {
                    /* Get Header Id */
                    TxPduHeaderId = (IPDUM_SHORT_HEADER_MASK & (pIpduM_ContainedTxPduConfig -> TxPduHeaderId));
                    /* Copy TxPduHeaderId */
                    IpduM_ContainerTxBuffer[TxInContainerPduId][TxBufferIndex] = TxPduHeaderId;
                    /* Increment TxBufferIndex */
                    TxBufferIndex += 0x04U;
                    /* Update IpduTxMBufferIndex */
                    IpduM_ContainerTxBufferConfig[TxInContainerPduId][IpduMQueueIndex].IpduTxMBufferIndex = TxBufferIndex;
                }
                /* Copy SduDataPtr */
                IpduM_UtilMemCpy((&IpduM_ContainerTxBuffer[TxInContainerPduId][TxBufferIndex]), (PduInfoPtr->SduDataPtr),
                                PduInfoPtr->SduLength);
                /* Increment TxBufferIndex */
                TxBufferIndex += PduInfoPtr->SduLength;
                /* Update IpduTxMBufferIndex */
                IpduM_ContainerTxBufferConfig[TxInContainerPduId][IpduMQueueIndex].IpduTxMBufferIndex = TxBufferIndex;
                /* Update IpduM_ContainerTxQueueIndex */
                IpduM_ContainerTxQueueIndex[TxInContainerPduId]++;
                /* Check ContainerTxTriggerModeType */
                if (((IPDUM_TX_TRIGGER_MODE_TYPE_DIRECT == pIpduM_ContainerTxPduConfig -> ContainerTxTriggerModeType) &&
                    (TxBufferIndex > pIpduM_ContainerTxPduConfig -> ContainerTxSizeThreshold)) ||
                    (IPDUM_TRIGGER_ALWAYS == pIpduM_ContainedTxPduConfig -> TxPduTrigger))
                {
                    /* Get SduLength */
                    IpduM_PduInfo.SduLength = TxBufferIndex;
                    /* Copy SduDataPtr */
                    IpduM_UtilMemCpy((IpduM_PduInfoBuffer),(&IpduM_ContainerTxBuffer[TxInContainerPduId][0]),
                                    TxBufferIndex);
                    IpduM_PduInfo.SduDataPtr = IpduM_PduInfoBuffer;
                    /* Update ContainerTxConfirmationTimeout */
                    IpduM_ContainerTxConfirmationTimeout[TxInContainerPduId] = pIpduM_ContainerTxPduConfig->ContainerTxConfirmationTimeout;
                    /* Invoke PduR_IpduMTransmit */
                    (void) PduR_IpduMTransmit(pIpduM_ContainerTxPduConfig -> LowerLayerTransmitId, &IpduM_PduInfo);
                    /* Update IpduTxMBufferIndex */
                    IpduM_ContainerTxBufferConfig[TxInContainerPduId][IpduMQueueIndex].IpduTxMBufferIndex = 0;
                    /* Update IpduM_ContainerTxQueueIndex */
                    IpduM_ContainerTxQueueIndex[TxInContainerPduId] = 0;
                }
            }
        }
    }  /* Coverity Fix Story 164900 */
}
/********************************************************************************************************************
*   Service Name     : IpduM_UtilMemCpy
*   @brief      Performs the processes of copying Data from SrcPtr to DestPtr
********************************************************************************************************************/
static void IpduM_UtilMemCpy(uint8 *DestPtr,const uint8 * const SrcPtr,PduLengthType Length)
{
    PduLengthType Idx = 0U;
    /* copy number of bytes from [pSrc] to [pDest]. */
    for (Idx = 0U; Idx < Length; Idx++)
    {
        DestPtr[Idx] = SrcPtr[Idx];
    }
}
/********************************************************************************************************************
*   Service Name     : IpduM_ProcessDeferredContainerRxPdu
*   @brief      Performs the processes of copying value to DestPtr
********************************************************************************************************************/
static void IpduM_UtilMemSet(uint8 *DestPtr,uint8 Value,PduLengthType Length)
{
    PduLengthType Idx = 0U;
    /* copy number of bytes from [pSrc] to [pDest]. */
    for (Idx = 0U; Idx < Length; Idx++)
    {
        DestPtr[Idx] = Value;
    }
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
/*!*****************************************************************************************************************
*  @date 19-Jun-2020
*  @version 0.0.1
*  @author  mjesuraj
*  @brief Initial Version
*
*******************************************************************************************************************/
/*!*****************************************************************************************************************
*  @date 1-Feb-2021
*  @version 0.0.2
*  @author  pmanoj2
*  @brief Traceability - 1206950: [hondabev] CERTC New rules(COM)
*
*******************************************************************************************************************/
