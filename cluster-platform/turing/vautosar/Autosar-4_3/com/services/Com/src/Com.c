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
*    @file Com.c
*    @ingroup Com
*    @brief This file implements the AUTOSAR Com module.The COM Module provides signal oriented data interface
*    for the RTE.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "Com.h"
#include "Com_Lcfg.h"
#include "SchM_Com.h"
#include "PduR.h"
#include "PduR_Com.h"
#if (COM_DEV_ERROR_DETECT == STD_ON)
# include "Det.h"
#endif

#if !defined (COM_LOCAL) 
# define COM_LOCAL                                static
#endif

#if !defined (COM_LOCAL_INLINE)
# define COM_LOCAL_INLINE                         LOCAL_INLINE
#endif

/********************************************************************************************************************
*  Version check                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if ((COM_SW_MAJOR_VERSION != COM_CFG_SW_MAJOR_VERSION) || \
    (COM_SW_MINOR_VERSION != COM_CFG_SW_MINOR_VERSION) || \
    (COM_SW_PATCH_VERSION != COM_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if ((COM_AR_RELEASE_MAJOR_VERSION != COM_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (COM_AR_RELEASE_MINOR_VERSION != COM_CFG_AR_RELEASE_MINOR_VERSION) || \
    (COM_AR_RELEASE_REVISION_VERSION != COM_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif
/********************************************************************************************************************
*  feature validation check                                                                                         *
********************************************************************************************************************/
#if ((COM_CANCELLATION_SUPPORT == STD_OFF) && (COM_TX_IPDU_CANCELLATION_SUPPORT == STD_ON))
    #error "Invalid configuration : COM_CANCELLATION_SUPPORT should be STD_ON"
#endif

#if ((COM_CANCELLATION_SUPPORT == STD_OFF) && (COM_RX_IPDU_CANCELLATION_SUPPORT == STD_ON))
    #error "Invalid configuration : COM_CANCELLATION_SUPPORT should be STD_ON"
#endif

#if ((COM_ENABLE_SIGNAL_GROUP_ARRAY_API  == STD_OFF) && (COM_TX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON))
    #error "Invalid configuration : COM_ENABLE_SIGNAL_GROUP_ARRAY_API should be STD_ON"
#endif

#if ((COM_ENABLE_SIGNAL_GROUP_ARRAY_API  == STD_OFF) && (COM_RX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON))
    #error "Invalid configuration : COM_ENABLE_SIGNAL_GROUP_ARRAY_API should be STD_ON"
#endif

#if ((COM_META_DATA_SUPPORT  == STD_OFF) && (COM_TX_IPDU_META_DATA_SUPPORT == STD_ON))
    #error "Invalid configuration : COM_ENABLE_SIGNAL_GROUP_ARRAY_API should be STD_ON"
#endif

#if ((COM_META_DATA_SUPPORT  == STD_OFF) && (COM_RX_IPDU_META_DATA_SUPPORT == STD_ON))
    #error "Invalid configuration : COM_ENABLE_SIGNAL_GROUP_ARRAY_API should be STD_ON"
#endif

#if(((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_OFF)&&(COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_OFF)) && \
    (COM_TX_SIGNAL_INVALID_BOOLEAN_SUPPORT == STD_ON))
    #error " Invalid configuration : COM_TX_SIGNAL_INVALIDATE_SUPPORT or \
            COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT should be STD_ON"
#endif

#if(((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_OFF)&&(COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_OFF)) && \
    (COM_TX_SIGNAL_INVALID_UINT8_SUPPORT == STD_ON))
    #error " Invalid configuration : COM_TX_SIGNAL_INVALIDATE_SUPPORT or \
            COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT should be STD_ON"
#endif

#if(((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_OFF)&&(COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_OFF)) && \
    (COM_TX_SIGNAL_INVALID_SINT8_SUPPORT == STD_ON))
    #error " Invalid configuration : COM_TX_SIGNAL_INVALIDATE_SUPPORT or \
            COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT should be STD_ON"
#endif

#if(((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_OFF)&&(COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_OFF)) && \
    (COM_TX_SIGNAL_INVALID_UINT16_SUPPORT == STD_ON))
    #error " Invalid configuration : COM_TX_SIGNAL_INVALIDATE_SUPPORT or \
            COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT should be STD_ON"
#endif

#if(((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_OFF)&&(COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_OFF)) && \
    (COM_TX_SIGNAL_INVALID_SINT16_SUPPORT == STD_ON))
    #error " Invalid configuration : COM_TX_SIGNAL_INVALIDATE_SUPPORT or \
            COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT should be STD_ON"
#endif

#if(((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_OFF)&&(COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_OFF)) && \
    (COM_TX_SIGNAL_INVALID_UINT32_SUPPORT == STD_ON))
    #error " Invalid configuration : COM_TX_SIGNAL_INVALIDATE_SUPPORT or \
            COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT should be STD_ON"
#endif

#if(((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_OFF)&&(COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_OFF)) && \
    (COM_TX_SIGNAL_INVALID_SINT32_SUPPORT == STD_ON))
    #error " Invalid configuration : COM_TX_SIGNAL_INVALIDATE_SUPPORT or \
            COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT should be STD_ON"
#endif

#if(((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_OFF)&&(COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_OFF)) && \
    (COM_TX_SIGNAL_INVALID_UINT64_SUPPORT == STD_ON))
    #error " Invalid configuration : COM_TX_SIGNAL_INVALIDATE_SUPPORT or \
            COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT should be STD_ON"
#endif

#if(((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_OFF)&&(COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_OFF)) && \
    (COM_TX_SIGNAL_INVALID_SINT64_SUPPORT == STD_ON))
    #error " Invalid configuration : COM_TX_SIGNAL_INVALIDATE_SUPPORT or \
            COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT should be STD_ON"
#endif

#if(((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_OFF)&&(COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_OFF)) && \
    (COM_TX_SIGNAL_INVALID_FLOAT32_SUPPORT == STD_ON))
    #error " Invalid configuration : COM_TX_SIGNAL_INVALIDATE_SUPPORT or \
            COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT should be STD_ON"
#endif

#if(((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_OFF)&&(COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_OFF)) && \
    (COM_TX_SIGNAL_INVALID_FLOAT64_SUPPORT == STD_ON))
    #error " Invalid configuration : COM_TX_SIGNAL_INVALIDATE_SUPPORT or \
            COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT should be STD_ON"
#endif

#if(((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_OFF)&&(COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_OFF)) && \
    (COM_TX_SIGNAL_INVALID_UINT64_SUPPORT == STD_ON))
    #error " Invalid configuration : COM_TX_SIGNAL_INVALIDATE_SUPPORT or \
            COM_TX_SIGNAL_INVALID_UINT8ARR_SUPPORT should be STD_ON"
#endif

#if ((COM_TX_TIMEOUT_COUNTER_SUPPORT  == STD_OFF) && (COM_TX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT == STD_ON))
    #error " Invalid configuration : COM_TX_TIMEOUT_COUNTER_SUPPORT should be STD_ON "
#endif

#if ((COM_TX_TIMEOUT_COUNTER_SUPPORT  == STD_OFF) && (COM_TX_IPDU_CANCELLATION_SUPPORT == STD_ON))
    #error " Invalid configuration : COM_TX_TIMEOUT_COUNTER_SUPPORT should be STD_ON "
#endif

#if ((COM_TX_SIGNAL_GROUP_SUPPORT  == STD_OFF) && \
     ((COM_TX_SIGNAL_GROUP_UB_SUPPORT == STD_ON) || (COM_TX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON) || \
     (COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_ON)))
    #error " Invalid configuration : COM_TX_SIGNAL_GROUP_SUPPORT should be STD_ON "
#endif

#if ((COM_RX_SIGNAL_GROUP_SUPPORT  == STD_OFF) && \
    ((COM_RX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON) || (COM_RX_SIGNAL_GROUP_UB_SUPPORT == STD_ON) || \
    (COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON) ))
    #error " Invalid configuration : COM_RX_SIGNAL_GROUP_SUPPORT should be STD_ON "
#endif

/* Unsupported feature */
#if (COM_TX_SIGNAL_ERROR_CALLBACK_SUPPORT  == STD_ON)
    #error " Error callback feature is not supported in current version "
#endif

#if (COM_SIGNAL_GATEWAY_SUPPORT  == STD_ON)
    #error " Signal Gateway feature is not supported in current version "
#endif

#if (COM_TX_IPDU_COUNTER_SUPPORT  == STD_ON)
    #error " Tx Ipdu counter feature is not supported in current version "
#endif

#if (COM_TX_SIGNAL_GROUP_UB_SUPPORT  == STD_ON)
    #error " Tx signal group with update bit feature is not supported in current version "
#endif

#if (COM_RX_IPDU_COUNTER_SUPPORT  == STD_ON)
    #error " Rx Ipdu counter feature is not supported in current version "
#endif

/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
#if (COM_CONFIGURATION_USE_DET == STD_ON)
#define Com_DetReportError(ApiId,ErrorId) (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID,ApiId,ErrorId)
#else
#define Com_DetReportError(ApiId,ErrorId)  COM_DUMMY_STATEMENT(ErrorId)
#endif

/* utility to get signal length in bytes */
#define Com_UtilSignalLengthInBytes(LenInBits) ((((LenInBits) % 8U) == 0U) ? ((LenInBits)/8U) : (((LenInBits)/8U)+1U))
/* utility to check the bits */
#define Com_UtilIsBitSet(data,Bit) ((((data) & (1U << (Bit))) != 0U) ? TRUE : FALSE)
/* Signal group trigger values */
#define COM_SIGNAL_GROUP_TX_TRIGGER_NONE                    0U
#define COM_SIGNAL_GROUP_TX_TRIGGER_WITH_REPITITION         1U
#define COM_SIGNAL_GROUP_TX_TRIGGER_WITHOUT_REPITITION      2U
/* Com Tx TP Connection states */
#define COM_TXTP_CONN_STATE_IDLE                            0U
#define COM_TXTP_CONN_STATE_TRANSMIT_REQUEST                1U
#define COM_TXTP_CONN_STATE_TRANSMIT_COPYDATA               2U
#define COM_TXTP_CONN_STATE_WAIT_FOR_CONFIRMATION           4U
/* Com Rx TP Connection state */
#define COM_RXTP_CONN_STATE_IDLE                            0U
#define COM_RXTP_CONN_STATE_RECEPTION_COPYDATA              1U
#define COM_RXTP_CONN_STATE_WAIT_FOR_INDICATION             2U
#define COM_RXTP_CONN_STATE_RECEPTION_DEFERRED_NOTIFICATION 3U
/* Set Utility Macros - Tx IPDU */
#define Com_SetTxIpduRepetitionCount(TxPduId,Val)           (Com_TxIpduRepetitionCount[(TxPduId)] = (Val))
#define Com_SetTxIpduRepetitionPeriod(TxPduId,Val)          (Com_TxIpduRepetitionCycleCounter[(TxPduId)] = (Val))
#define Com_SetTxIpduMinimumDelay(TxPduId,Val)              (Com_TxIpduMinimumDelayCounter[(TxPduId)] = (Val))
#define Com_SetTxIpduPeriod(TxPduId,Val)                    (Com_TxIpduPeriodicCounter[(TxPduId)] = (Val))
#define Com_SetTxIpduPeriodicTransmitRequest(TxPduId,Val)   (Com_TxIpduPeriodicTransmitRequest[(TxPduId)] = (Val))
#define Com_SetTxIpduTransmitRequest(TxPduId,Val)           (Com_TxIpduTransmitRequest[(TxPduId)] = (Val))
#define Com_SetTxIpduGroupActive(TxPduId,Val)               (Com_TxIpduGroupActiveState[(TxPduId)] = (Val))
#define Com_SetTxIpduConfirmationWait(TxPduId,Val)          (Com_TxIpduConfirmationWaitStatus[(TxPduId)] = (Val))
#define Com_SetTxIpduDefferedNotification(TxPduId,Val)      (Com_TxIpduDefferedNotificationStatus[(TxPduId)] = (Val))
#define Com_SetTxIpduBufferLength(TxPduId,Val)              (Com_TxIpduBufferLength[(TxPduId)] = (Val))
#define Com_SetTxIpduTxMode(TxPduId,Val)                    (Com_TxIpduTxMode[(TxPduId)] = (Val))
#if (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON)
#define Com_SetTxIpduTxTimeoutCount(Id,Val)                 (Com_TxIpduTxTimeoutCounter[(Id)] = (Val))
#endif
#if(COM_TX_SIGNAL_GROUP_SUPPORT == STD_ON)
#define Com_SetTxSignalGroupTriggerStatus(SigGroupId,Val)   (Com_TxSignalGroupTxTriggerStatus[(SigGroupId)] = (Val))
#endif
#if(COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON)
#define Com_SetTxSignalFilterState(FilterId,Val)            (Com_TxSignalFilterState[(FilterId)] = (Val))
#endif
/* Check Macros - Tx IPDU */
#define Com_IsTxIpduModeTypePeriodic(Val) ((((Val) == COM_TX_MODE_MODE_TYPE_PERIODIC) || \
                                           ((Val) == COM_TX_MODE_MODE_TYPE_MIXED)) ? TRUE : FALSE)

/* Get Macros - Tx IPDU */
#define Com_GetTxIpduBufferLength(TxPduId)                  (Com_TxIpduBufferLength[(TxPduId)])
#define Com_GetTxIpduTxMode(TxPduId)                        (Com_TxIpduTxMode[(TxPduId)])
#define Com_GetTxIpduGroupActive(TxPduId)                   (Com_TxIpduGroupActiveState[(TxPduId)])
#if (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON)
#define Com_GetTxIpduTxTimeoutCount(Id)                     (Com_TxIpduTxTimeoutCounter[(Id)])
#endif
#define Com_GetTxIpduDefferedNotification(TxPduId)          (Com_TxIpduDefferedNotificationStatus[(TxPduId)])
#define Com_GetTxIpduTransmitRequest(TxPduId)               (Com_TxIpduTransmitRequest[(TxPduId)])
#define Com_GetTxIpduPeriodicTransmitRequest(TxPduId)       (Com_TxIpduPeriodicTransmitRequest[(TxPduId)])
#if(COM_TX_SIGNAL_GROUP_SUPPORT == STD_ON)
#define Com_GetSignalGroupTriggerStatus(SigGroupId)         (Com_TxSignalGroupTxTriggerStatus[(SigGroupId)])
#endif
#if(COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON)
#define Com_GetTxSignalFilterState(FilterId)                (Com_TxSignalFilterState[(FilterId)])
#endif
#define Com_GetTxIpduConfirmationWait(TxPduId)              (Com_TxIpduConfirmationWaitStatus[(TxPduId)])
/* Set Utility Macros - Rx IPDU */
#define Com_SetRxIpduGroupActive(RxIpduId,Val)              (Com_RxIpduGroupActiveState[(RxIpduId)] = (Val))
#define Com_SetRxIpduBufferLength(RxIpduId,Val)             (Com_RxIpduBufferLength[(RxIpduId)] = (Val))
#define Com_SetRxIpduDeferredProcessing(RxIpduId,Val)       (Com_RxIpduDeferredProcessingState[(RxIpduId)] = (Val))
#if(COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT == STD_ON)
#define Com_SetRxIpduDeadlineMonitoringState(ToutId,Val)    (Com_RxIpduDeadlineMonitoringState[(ToutId)] = (Val))
#define Com_SetRxIpduDeadlineCount(ToutId,Val)              (Com_RxIpduDeadlineCounter[(ToutId)] = (Val))
#endif
#if(COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON)
#define Com_SetRxSigDeadlineMonitoringState(ToutId,Val)     (Com_RxSigDeadlineMonitoringState[(ToutId)] = (Val))
#define Com_SetRxSigDeadlineCount(ToutId,Val)               (Com_RxSigDeadlineCounter[(ToutId)] = (Val))
#endif
#if(COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON)
#define Com_SetRxSigGroupDeadlineMonitoringState(ToutId,Val) (Com_RxSigGroupDeadlineMonitoringState[(ToutId)] = (Val))
#define Com_SetRxSigGroupDeadlineCount(ToutId,Val)          (Com_RxSigGroupDeadlineCounter[(ToutId)] = (Val))
#endif
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
#define Com_SetRxTpIpduConnectionState(RxTpId,Val)          (Com_RxTpIpduBufferState[(RxTpId)]= (Val))
#define Com_SetRxTpIpduBytesCopied(RxTpId,Val)              (Com_RxTpIpduBytesCopied[(RxTpId)]= (Val))
#endif
/* Get Utility Macros - Rx IPDU */
#define Com_GetRxIpduGroupActive(RxIpduId)                  (Com_RxIpduGroupActiveState[(RxIpduId)])
#define Com_GetRxIpduBufferLength(RxIpduId)                 (Com_RxIpduBufferLength[(RxIpduId)])
#define Com_GetRxIpduDeferredProcessing(RxIpduId)           (Com_RxIpduDeferredProcessingState[(RxIpduId)])
#if(COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT == STD_ON)
#define Com_GetRxIpduDeadlineMonitoringState(ToutId)        (Com_RxIpduDeadlineMonitoringState[(ToutId)])
#define Com_GetRxIpduDeadlineCount(ToutId,Val)              (Com_RxIpduDeadlineCounter[(ToutId)])
#endif
#if(COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON)
#define Com_GetRxSigDeadlineMonitoringState(ToutId)         (Com_RxSigDeadlineMonitoringState[(ToutId)])
#define Com_GetRxSigDeadlineCount(ToutId,Val)               (Com_RxSigDeadlineCounter[(ToutId)])
#endif
#if(COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON)
#define Com_GetRxSigGroupDeadlineMonitoringState(ToutId)    (Com_RxSigGroupDeadlineMonitoringState[(ToutId)])
#define Com_GetRxSigGroupDeadlineCount(ToutId,Val)          (Com_RxSigGroupDeadlineCounter[(ToutId)])
#endif
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
#define Com_GetRxTpIpduConnectionState(RxTpId)               (Com_RxTpIpduBufferState[(RxTpId)])
#define Com_GetRxTpIpduBytesCopied(RxTpId)                   (Com_RxTpIpduBytesCopied[(RxTpId)])
#endif
/*! Defines the Rx signal notification state as Invalid */
#define COM_SIGNAL_NOTIFY_INVALID           0U
/*! Defines the Rx signal notification state as Invalid replace */
#define COM_SIGNAL_NOTIFY_INVALID_REPLACE   1U
/*! Defines the Rx signal notification state as Invalid None */
#define COM_SIGNAL_NOTIFY_INVALID_NONE      2U
/*! Defines the Rx signal notification state as Ack */
#define COM_SIGNAL_NOTIFY_ACK               3U
/*! Defines the Rx signal notification state as Timeout */
#define COM_SIGNAL_NOTIFY_TOUT              4U
/*! Defines the Rx signal notification state as None */
#define COM_SIGNAL_NOTIFY_NONE              5U
/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/
/*! @brief Defines the Rx notification state */
typedef uint8 Com_NotifyStatusType;

/*! Defines the copy util type */
typedef struct
{
    /*! @brief Defines the source buffer Least Significant bit position */
    uint8                       SrcLsBit;
    /*! @brief Defines the destination buffer Least Significant bit position */
    uint8                       DestLsBit;
    /*! @brief Defines the source buffer Least Significant byte position */
    Com_BufferSizeType          SrcLsByte;
    /*! @brief Defines the destination buffer Least Significant byte position */
    Com_BufferSizeType          DestLsByte;
    /*! @brief Defines the source buffer size */
    Com_BufferSizeType          MaxSrcBufferSize;
    /*! @brief Defines the destination buffer size */
    Com_BufferSizeType          MaxDestBufferSize;
    /*! @brief Defines the source buffer endianess type */
    Com_EndianessType           SrcBufferEndianess;
    /*! @brief Defines the destination buffer endianess type */
    Com_EndianessType           DestBufferEndianess;
    /*! @brief Defines the source signal length in bits */
    Com_BitLengthSizeType       SignalLengthInBits;
    /*! @brief Defines the destination signal length in bits */
    PduLengthType               SingalLengthInBytes;
}Com_UtilBitCopyPropsType;
/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
#define COM_START_SEC_VAR_INIT_LOCAL_8
#include "MemMap.h"
/*! @brief  COM Module Init Status */
COM_LOCAL VAR(Com_StatusType,COM_VAR_INIT) COM_InitStatus = COM_UNINIT;
#define COM_STOP_SEC_VAR_INIT_LOCAL_8
#include "MemMap.h"

#define COM_START_SEC_CONST_8
#include "MemMap.h"
/*! @brief utility lookup for bit width mask  */
COM_LOCAL CONST(uint8,COM_CONST)Com_UtilBitWidthMasks[9] =
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
#define COM_STOP_SEC_CONST_8
#include "MemMap.h" 

#define COM_START_SEC_CODE
#include "MemMap.h"
/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
#if(COM_TX_TP_IPDU_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief     This service initializes Com Tx Tp connection properties
*   @param[in] TxIpduId TP Tx ID value
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_TxTpIpduResetConnection(PduIdType TxTpIpduId);
#endif
/*!******************************************************************************************************************
*   @brief     This service is used to copy the data bits from source buffer to destination buffer
*   @param[in] UtilBitCopyPropsPtr Pointer to the copy properties
*   @param[in] SrcBufferPtr pointer to source buffer
*   @param[in] SrcBufferPtr pointer to destination buffer
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UtilBitCopy
(
    P2VAR(Com_UtilBitCopyPropsType,AUTOMATIC,COM_APPL_DATA) UtilBitCopyPropsPtr,
    CONSTP2CONST(uint8,AUTOMATIC,COM_APPL_CONST) SrcBufferPtr , 
    CONSTP2VAR(uint8,AUTOMATIC,COM_APPL_DATA) DestBufferPtr
);

/*!******************************************************************************************************************
*   @brief     This service is used to initialize all Transmit IPDUs
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_InitTxIpdu(void);
#if (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief     This service initialize all Transmit IPDU Deadline monitoring properties
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_InitTxDeadlineMonitoring(void);
#endif
/*!******************************************************************************************************************
*   @brief     This service initialize all Transmit IPDU properties
*   @param[in] TxIpduId Tx ID value
*   @param[in] IsInitTxMode flag to set the TxModeModeType to True if IsInitTxMode is TRUE else current 
*              TxModeModeType to be used.
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_InitTxIpduProperties(PduIdType TxIpduId , boolean IsInitTxMode);
/*!******************************************************************************************************************
*   @brief     This service initialize all Transmit IPDU properties with the current mode.
*   @param[in] TxIpduId Tx Pdu ID value
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_InitTxIpduTxModeProperties(PduIdType TxIpduId);
/*!******************************************************************************************************************
*   @brief     This service activate the IPDU.
*   @param[in] TxIpduId Tx Pdu ID value
*   @param[in] Initialize status for the Ipdu initialization
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_ActivateTxIpdu(PduIdType TxIpduId , boolean Initialize);
/*!******************************************************************************************************************
*   @brief     This service deactivate the IPDU.
*   @param[in] TxIpduId Tx Pdu ID value
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_DeactivateTxIpdu(PduIdType TxIpduId);
/*!******************************************************************************************************************
*   @brief     This service initialize the Tx Ipdu buffer
*   @param[in] TxIpduId Tx Pdu ID value
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_InitTxIpduBuffer(PduIdType TxIpduId);
/*!******************************************************************************************************************
*   @brief     This service used to process the Send signal request.
*   @param[in] SignalId Tx  Singal ID value
*   @param[in] SignalDataPtr pointer to signal data
*   @param[in] SignalDataPtr signal data length
*   @return uint8 status of the request
********************************************************************************************************************/
COM_LOCAL FUNC(uint8,COM_CODE) Com_ProcessSendSignal
(
    Com_SignalIdType SignalId , 
    P2CONST(void,AUTOMATIC,COM_APPL_CONST) SignalDataPtr ,
    uint16 Length
);
#if(COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief     This service used to update the Transmit mode selection state.
*   @param[in] TxIpduId Tx Pdu ID value
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UpdateTMS(PduIdType TxIpduId);
#endif
/*!******************************************************************************************************************
*   @brief     This service used to process the trigger transmission request.
*   @param[in] TxIpduId Tx Pdu ID value
*   @param[in] IsRequestWithoutRepetition status of repetition request
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_TriggerDirectTransmission(PduIdType TxIpduId , boolean IsRequestWithoutRepetition);
/*!******************************************************************************************************************
*   @brief     This service used to check if the signal data is changed.
*   @param[in] SignalId signal ID value
*   @param[in] SignalDataPtr pointer to new signal data
*   @return boolean staus of the request .
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_IsTxSignalDataChanged
(
    Com_SignalIdType SignalId , 
    P2CONST(void,AUTOMATIC,COM_APPL_CONST) SignalDataPtr
);
/*!******************************************************************************************************************
*   @brief     This service used to write the data into the Ipdu buffer.
*   @param[in] SignalId signal ID value
*   @param[in] SignalDataPtr pointer to new signal data
*   @param[in] Length signal length in Bytes
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_WriteTxSignalToIpdu
(
    Com_SignalIdType SignalId , 
    P2CONST(void,AUTOMATIC,COM_APPL_CONST) SignalDataPtr ,
    uint16 Length
);
/*!******************************************************************************************************************
*   @brief     This service used to read the data into the Ipdu buffer.
*   @param[in] SignalId signal ID value
*   @param[out] SignalDataPtr pointer to get the signal data
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_ReadTxSignalFromIpdu
(
    Com_SignalIdType SignalId , 
    P2VAR(void,AUTOMATIC,COM_APPL_DATA) SignalDataPtr
);
#if(COM_TX_SIGNAL_GROUP_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief     This service used to process sending request of signal group.
*   @param[in] SignalGroupId signal group ID value
*   @return    status of request
********************************************************************************************************************/
COM_LOCAL FUNC(uint8,COM_CODE) Com_ProcessSendSignalGroup(Com_SignalGroupIdType SignalGroupId);
#endif
/*!******************************************************************************************************************
*   @brief     This service used to process Ipdu confirmation.
*   @param[in] TxPduId Ipdu Tx ID value
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_ProcessTxConfirmation(PduIdType TxPduId);
/*!******************************************************************************************************************
*   @brief     This service used to process Ipdu confirmation notification to upper layer.
*   @param[in] TxPduId Ipdu Tx ID value
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_ProcessConfirmationNotification(PduIdType TxPduId);
#if(COM_TX_SIGNAL_UB_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief     This service used to clear the Update bits configured for this Ipdu .
*   @param[in] TxPduId Ipdu Tx ID value
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_ClearUpdateBits(PduIdType TxPduId);
#endif
/*!******************************************************************************************************************
*   @brief     This service used to validate the transmit request of the IPDUs .
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_ProcessTransmitRequest(void);
/*!******************************************************************************************************************
*   @brief     This service used to transmit IPDUs to lower layer.
*   @param[in] TxPduId Ipdu Tx ID value
*   @return    status of the request
********************************************************************************************************************/
COM_LOCAL FUNC(uint8,COM_CODE) Com_IpduTxTransmit(PduIdType TxPduId);
/*!******************************************************************************************************************
*   @brief     This service used to set/clear the mask value to the data buffer
*   @param[in,out] DataPtr pointer to buffer to which mask needs to be set/cleared
*   @param[in] BitMask bit mask value
*   @param[in] SetMode status to set the mask
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UtilSetClearBitMask
(
    CONSTP2VAR(uint8,AUTOMATIC,COM_APPL_DATA) DataPtr , 
    uint8 BitMask ,
    boolean SetMode
);
/*!******************************************************************************************************************
*   @brief     This service used to set/clear the bit value to the data buffer
*   @param[in,out] DataPtr pointer to buffer to which bit needs to be set/cleared
*   @param[in] BitPosition bit position value
*   @param[in] SetMode status to set the bit
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UtilSetClearBit
(
    CONSTP2VAR(uint8,AUTOMATIC,COM_APPL_DATA) DataPtr , 
    uint8 BitPosition ,
    boolean SetMode
);
#if(COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief     This service used to process the signal filter states.
*   @param[in] TxSignalFilterId Filter configuration index value
*   @param[in] SignalId signal Id value
*   @param[in] SignalDataPtr pointer to new signal data.
*   @return boolean filter state value
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessTxSignalFilterState
(
    Com_TxSignalFilterIdType TxSignalFilterId , 
    Com_SignalIdType SignalId ,
    P2CONST(void,AUTOMATIC,COM_APPL_CONST) SignalDataPtr
);
#endif
#if((COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON) || (COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON))
/*!******************************************************************************************************************
*   @brief     This service used to process the boolean signal filter states.
*   @param[in] SignalOldValue old signal data value
*   @param[in] SignalDataPtr pointer to new signal data
*   @param[in] FilterConfigPtr pointer to filter configuration
*   @return boolean filter state value
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessBooleanSignalFilter
(
    boolean SignalOldValue , 
    P2CONST(boolean,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr
);

/*!******************************************************************************************************************
*   @brief     This service used to process the uint8 signal filter states.
*   @param[in] SignalOldValue old signal data value
*   @param[in] SignalDataPtr pointer to new signal data
*   @param[in] FilterConfigPtr pointer to filter configuration
*   @return boolean filter state value
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessUint8SignalFilter
(
    uint8 SignalOldValue , 
    P2CONST(uint8,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr
);
/*!******************************************************************************************************************
*   @brief     This service used to process the sint8 signal filter states.
*   @param[in] SignalOldValue old signal data value
*   @param[in] SignalDataPtr pointer to new signal data
*   @param[in] FilterConfigPtr pointer to filter configuration
*   @return boolean filter state value
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessSint8SignalFilter
(
    sint8 SignalOldValue , 
    P2CONST(sint8,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr
);
/*!******************************************************************************************************************
*   @brief     This service used to process the uint16 signal filter states.
*   @param[in] SignalOldValue old signal data value
*   @param[in] SignalDataPtr pointer to new signal data
*   @param[in] FilterConfigPtr pointer to filter configuration
*   @return boolean filter state value
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessUint16SignalFilter
(
    uint16 SignalOldValue , 
    P2CONST(uint16,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr
);
/*!******************************************************************************************************************
*   @brief     This service used to process the sint16 signal filter states.
*   @param[in] SignalOldValue old signal data value
*   @param[in] SignalDataPtr pointer to new signal data
*   @param[in] FilterConfigPtr pointer to filter configuration
*   @return boolean filter state value
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessSint16SignalFilter
(
    sint16 SignalOldValue , 
    P2CONST(sint16,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr
);
/*!******************************************************************************************************************
*   @brief     This service used to process the uint32 signal filter states.
*   @param[in] SignalOldValue old signal data value
*   @param[in] SignalDataPtr pointer to new signal data
*   @param[in] FilterConfigPtr pointer to filter configuration
*   @return boolean filter state value
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessUint32SignalFilter
(
    uint32 SignalOldValue , 
    P2CONST(uint32,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr
);
/*!******************************************************************************************************************
*   @brief     This service used to process the sint32 signal filter states.
*   @param[in] SignalOldValue old signal data value
*   @param[in] SignalDataPtr pointer to new signal data
*   @param[in] FilterConfigPtr pointer to filter configuration
*   @return boolean filter state value
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessSint32SignalFilter
(
    sint32 SignalOldValue , 
    P2CONST(sint32,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr
);
/*!******************************************************************************************************************
*   @brief     This service used to process the uint64 signal filter states.
*   @param[in] SignalOldValue old signal data value
*   @param[in] SignalDataPtr pointer to new signal data
*   @param[in] FilterConfigPtr pointer to filter configuration
*   @return boolean filter state value
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessUint64SignalFilter
(
    uint64 SignalOldValue , 
    P2CONST(uint64,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr
);
/*!******************************************************************************************************************
*   @brief     This service used to process the sint64 signal filter states.
*   @param[in] SignalOldValue old signal data value
*   @param[in] SignalDataPtr pointer to new signal data
*   @param[in] FilterConfigPtr pointer to filter configuration
*   @return boolean filter state value
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessSint64SignalFilter
(
    sint64 SignalOldValue , 
    P2CONST(sint64,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr
);
#endif
/*!******************************************************************************************************************
*   @brief     This service used to process the sign extension for the 8 bit data
*   @param[in,out] DataPtr pointer to data for sign conversion
*   @Param[in] BitSize length in bits
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UtilGetSignExtended8BitData
(
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) DataPtr , 
    uint32 BitSize
);
/*!******************************************************************************************************************
*   @brief     This service used to process the sign extension for the 16 bit data
*   @param[in,out] DataPtr pointer to data for sign conversion
*   @Param[in] BitSize length in bits
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UtilGetSignExtended16BitData
(
    P2VAR(uint16,AUTOMATIC,COM_APPL_DATA) DataPtr , 
    uint32 BitSize
);
/*!******************************************************************************************************************
*   @brief     This service used to process the sign extension for the 32 bit data
*   @param[in,out] DataPtr pointer to data for sign conversion
*   @Param[in] BitSize length in bits
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UtilGetSignExtended32BitData
(
    P2VAR(uint32,AUTOMATIC,COM_APPL_DATA) DataPtr ,
    uint32 BitSize
);
/*!******************************************************************************************************************
*   @brief     This service used to process the sign extension for the 64 bit data
*   @param[in,out] DataPtr pointer to data for sign conversion
*   @Param[in] BitSize length in bits
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UtilGetSignExtended64BitData
(
    P2VAR(uint64,AUTOMATIC,COM_APPL_DATA) DataPtr ,
    uint32 BitSize
);
/*!******************************************************************************************************************
*   @brief     This service used to copy data from source buffer to destination buffer
*   @param[in] DestPtr pointer to destination buffer data
*   @param[in] DestPtr pointer to source buffer data
*   @param[in] Length byte size to be copied
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UtilMemCopy
(
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) DestPtr , 
    CONSTP2CONST(uint8,AUTOMATIC,COM_APPL_CONST) SrcPtr ,
    PduLengthType Length
);
/*!******************************************************************************************************************
*   @brief     This service used to set data destination buffer
*   @param[in] DestPtr pointer to destination buffer data
*   @param[in] Value value to be set
*   @param[in] Length byte size to be set
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UtilMemSet
(
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) DestPtr ,
    uint8 Value ,
    PduLengthType Length
);
#if((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_ON) || (COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_ON))
/*!******************************************************************************************************************
*   @brief     This service used to process the Invalid signal request
*   @param[in] SignalId signal Id value
********************************************************************************************************************/
COM_LOCAL FUNC(uint8,COM_CODE) Com_ProcessInvalidateSignal(Com_SignalIdType SignalId);
#endif
#if (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief     This service used to process the deadline monitoring for Tx Ipdu
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_ProcessDeadlineMoitoring(void);
#endif
/*!******************************************************************************************************************
*   @brief     This service used to initialize the RxIPdu
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE)Com_InitRxIpdu(void);
/*!******************************************************************************************************************
*   @brief     This service used to initialize the RxIPdu properties
*   @param[in] RxIpduId Value of the Rx IPdu Id
*   @param[in] InitBuffer if TRUE it will intialize the buffer
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_InitRxIPduProperties(PduIdType RxIpduId , boolean InitBuffer);
/*!******************************************************************************************************************
*   @brief     This service used to deactivate the RxIPdu
*   @param[in] RxIpduId value of the Rx IPdu Id
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_DeactivateRxIpdu(PduIdType RxIpduId);
/*!******************************************************************************************************************
*   @brief     This service used to activate the Rx Ipdu
*   @param[in] RxIpduId value of the Rx IPdu Id
*   @param[in] Initialize flag to initialize the Rx Ipdu properties
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_ActivateRxIpdu(PduIdType RxIpduId , boolean Initialize);
/*!******************************************************************************************************************
*   @brief     This service used to process the receive signal request
*   @param[in] SignalId value of the Rx signal Id
*   @param[out] SignalDataPtr pointer to data buffer
*   @return uint8 status of the request
********************************************************************************************************************/
COM_LOCAL_INLINE FUNC(uint8,COM_CODE) Com_ReceiveSignalProcessing
(
    Com_SignalIdType SignalId , 
    P2CONST(void,AUTOMATIC,COM_APPL_CONST) SignalDataPtr
);
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief     This service used to initialize the RxTP connection properties
*   @param[in] RxTpIpduId value of the Rx Tp Ipdu Id
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_RxTpIpduResetConnection(PduIdType RxTpIpduId);
#endif
/*!******************************************************************************************************************
*   @brief     This service used to process new Ipdu reception request
*   @param[in] RxTpIpduId value of the Rx Tp Ipdu Id
*   @param[in] PduInfoPtr pointer to the Rx IPdu Info
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_RxIndicationProcessing
(
    PduIdType RxIpduId , 
    P2CONST(PduInfoType,AUTOMATIC,COM_APPL_CONST) PduInfoPtr
);
/*!******************************************************************************************************************
*   @brief     This service used to process signals from the received Ipdu
*   @param[in] RxIPduId value of the Rx Ipdu Id
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_RxIpduSignalProcessing(PduIdType RxIpduId);
/*!******************************************************************************************************************
*   @brief     This service used to process signal group from the received Ipdu
*   @param[in] RxIPduId value of the Rx Ipdu Id
********************************************************************************************************************/
#if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
COM_LOCAL FUNC(void,COM_CODE) Com_RxIpduSignalGroupProcessing(PduIdType RxIpduId);
#endif
/*!******************************************************************************************************************
*   @brief     This service used to process the received Ipdu
*   @param[in] RxIPduId value of the Rx Ipdu Id
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_RxIpduProcessing(PduIdType RxIpduId);
/*!******************************************************************************************************************
*   @brief     This service used to process signal invalidation , filtering and notification to upper layer for
*   the boolean type Rx signal
*   @param[in] RxSignalConfigPtr pointer to the signal properties
*   @param[in] RxIpduBufferOffset buffer offset for the signal's IPDU
*   @param[in] BufferLength length of the signal's IPDU
*   @param[in] IpduType type of signal's Ipdu - Normal/Tp
*   @param[in] BufferUpdateStatus status for updating the received signal to the rte buffer
*   @return Com_NotifyStatusType status for the notification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxBooleanSignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
);

/*!******************************************************************************************************************
*   @brief     This service used to process signal invalidation , filtering and notification to upper layer for
*   the uint8 type Rx signal
*   @param[in] RxSignalConfigPtr pointer to the signal properties
*   @param[in] RxIpduBufferOffset buffer offset for the signal's IPDU
*   @param[in] BufferLength length of the signal's IPDU
*   @param[in] IpduType type of signal's Ipdu - Normal/Tp
*   @param[in] BufferUpdateStatus status for updating the received signal to the rte buffer
*   @return Com_NotifyStatusType status for the notification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxUint8SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
);
/*!******************************************************************************************************************
*   @brief     This service used to process signal invalidation , filtering and notification to upper layer for
*   the sint8 type Rx signal
*   @param[in] RxSignalConfigPtr pointer to the signal properties
*   @param[in] RxIpduBufferOffset buffer offset for the signal's IPDU
*   @param[in] BufferLength length of the signal's IPDU
*   @param[in] IpduType type of signal's Ipdu - Normal/Tp
*   @param[in] BufferUpdateStatus status for updating the received signal to the rte buffer
*   @return Com_NotifyStatusType status for the notification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxSint8SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
);
/*!******************************************************************************************************************
*   @brief     This service used to process signal invalidation , filtering and notification to upper layer for
*   the uint16 type Rx signal
*   @param[in] RxSignalConfigPtr pointer to the signal properties
*   @param[in] RxIpduBufferOffset buffer offset for the signal's IPDU
*   @param[in] BufferLength length of the signal's IPDU
*   @param[in] IpduType type of signal's Ipdu - Normal/Tp
*   @param[in] BufferUpdateStatus status for updating the received signal to the rte buffer
*   @return Com_NotifyStatusType status for the notification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxUint16SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
);
/*!******************************************************************************************************************
*   @brief     This service used to process signal invalidation , filtering and notification to upper layer for
*   the sint16 type Rx signal
*   @param[in] RxSignalConfigPtr pointer to the signal properties
*   @param[in] RxIpduBufferOffset buffer offset for the signal's IPDU
*   @param[in] BufferLength length of the signal's IPDU
*   @param[in] IpduType type of signal's Ipdu - Normal/Tp
*   @param[in] BufferUpdateStatus status for updating the received signal to the rte buffer
*   @return Com_NotifyStatusType status for the notification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxSint16SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
);
/*!******************************************************************************************************************
*   @brief     This service used to process signal invalidation , filtering and notification to upper layer for
*   the uint32 type Rx signal
*   @param[in] RxSignalConfigPtr pointer to the signal properties
*   @param[in] RxIpduBufferOffset buffer offset for the signal's IPDU
*   @param[in] BufferLength length of the signal's IPDU
*   @param[in] IpduType type of signal's Ipdu - Normal/Tp
*   @param[in] BufferUpdateStatus status for updating the received signal to the rte buffer
*   @return Com_NotifyStatusType status for the notification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxUint32SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
);
/*!******************************************************************************************************************
*   @brief     This service used to process signal invalidation , filtering and notification to upper layer for
*   the sint32 type Rx signal
*   @param[in] RxSignalConfigPtr pointer to the signal properties
*   @param[in] RxIpduBufferOffset buffer offset for the signal's IPDU
*   @param[in] BufferLength length of the signal's IPDU
*   @param[in] IpduType type of signal's Ipdu - Normal/Tp
*   @param[in] BufferUpdateStatus status for updating the received signal to the rte buffer
*   @return Com_NotifyStatusType status for the notification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxSint32SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
);
/*!******************************************************************************************************************
*   @brief     This service used to process signal invalidation , filtering and notification to upper layer for
*   the uint64 type Rx signal
*   @param[in] RxSignalConfigPtr pointer to the signal properties
*   @param[in] RxIpduBufferOffset buffer offset for the signal's IPDU
*   @param[in] BufferLength length of the signal's IPDU
*   @param[in] IpduType type of signal's Ipdu - Normal/Tp
*   @param[in] BufferUpdateStatus status for updating the received signal to the rte buffer
*   @return Com_NotifyStatusType status for the notification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxUint64SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
);
/*!******************************************************************************************************************
*   @brief     This service used to process signal invalidation , filtering and notification to upper layer for
*   the sint64 type Rx signal
*   @param[in] RxSignalConfigPtr pointer to the signal properties
*   @param[in] RxIpduBufferOffset buffer offset for the signal's IPDU
*   @param[in] BufferLength length of the signal's IPDU
*   @param[in] IpduType type of signal's Ipdu - Normal/Tp
*   @param[in] BufferUpdateStatus status for updating the received signal to the rte buffer
*   @return Com_NotifyStatusType status for the notification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxSint64SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
);
/*!******************************************************************************************************************
*   @brief     This service used to process signal invalidation , filtering and notification to upper layer for
*   the uint_8, uint_n type Rx signal
*   @param[in] RxSignalConfigPtr pointer to the signal properties
*   @param[in] RxIpduBufferOffset buffer offset for the signal's IPDU
*   @param[in] BufferLength length of the signal's IPDU
*   @param[in] IpduType type of signal's Ipdu - Normal/Tp
*   @param[in] BufferUpdateStatus status for updating the received signal to the rte buffer
*   @return Com_NotifyStatusType status for the notification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxUint8ArrSignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
);
#if(COM_SIGNAL_TYPE_FLOAT32_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief     This service used to process signal invalidation , filtering and notification to upper layer for
*   the float32 type Rx signal
*   @param[in] RxSignalConfigPtr pointer to the signal properties
*   @param[in] RxIpduBufferOffset buffer offset for the signal's IPDU
*   @param[in] BufferLength length of the signal's IPDU
*   @param[in] IpduType type of signal's Ipdu - Normal/Tp
*   @param[in] BufferUpdateStatus status for updating the received signal to the rte buffer
*   @return Com_NotifyStatusType status for the notification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxFloat32SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
);
#endif
#if(COM_SIGNAL_TYPE_FLOAT64_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief     This service used to process signal invalidation , filtering and notification to upper layer for
*   the float64 type Rx signal
*   @param[in] RxSignalConfigPtr pointer to the signal properties
*   @param[in] RxIpduBufferOffset buffer offset for the signal's IPDU
*   @param[in] BufferLength length of the signal's IPDU
*   @param[in] IpduType type of signal's Ipdu - Normal/Tp
*   @param[in] BufferUpdateStatus status for updating the received signal to the rte buffer
*   @return Com_NotifyStatusType status for the notification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxFloat64SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
);
#endif
/*!******************************************************************************************************************
*   @brief     This service used to process signal invalidation , filtering and notification to upper layer for
*   the  Rx signal
*   @param[in] RxSignalConfigPtr pointer to the signal properties
*   @param[in] RxIpduBufferOffset buffer offset for the signal's IPDU
*   @param[in] BufferLength length of the signal's IPDU
*   @param[in] IpduType type of signal's Ipdu - Normal/Tp
*   @param[in] BufferUpdateStatus status for updating the received signal to the rte buffer
*   @return Com_NotifyStatusType status for the notification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxSignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
);
/*!******************************************************************************************************************
*   @brief     This service used to read signal data form Ipdu buffer
*   @param[out] SignalDataPtr pointer to the signal buffer
*   @param[in] RxSignalConfigPtr pointer to signal properties
*   @param[in] RxIpduBufferPtr pointer to IPDU source buffer
*   @param[in] MaximumLength length of the IPDU buffer
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_ReadRxSignalFromBuffer
(
    P2CONST(void,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    P2CONST(uint8,AUTOMATIC,COM_APPL_CONST) RxIpduBufferPtr ,
    PduLengthType MaximumLength
);
#ifdef COM_RX_SIGNAL_WRITE_API_SUPPORT
/*!******************************************************************************************************************
*   @brief     This service used to write signal data form IPDU buffer
*   @param[out] SignalDataPtr pointer to the signal buffer
*   @param[in] RxSignalConfigPtr pointer to signal properties
*   @param[in] RxIpduBufferPtr pointer to IPDU Destination buffer
*   @param[in] MaximumLength length of the IPDU buffer
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_WriteRxSignalToBuffer
(
    P2CONST(void,AUTOMATIC,COM_APPL_CONST) SignalDataPtr ,
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) RxIpduBufferPtr , 
    PduLengthType MaximumLength
);
#endif
/*!******************************************************************************************************************
*   @brief     This service used to write signal init value to the Rte Ipdu buffer
*   @param[in] RxSignalConfigPtr pointer to signal properties
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_SetRxSignalInitValue
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr
);
#if (COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief     This service is used to update the shadow buffer data with the received data
*   @param[in] RxSignalConfigPtr pointer to signal properties
*   @param[in] RxIpduSrcBufferPtr pointer to the source buffer
*   @param[in] BufferLength length of the source buffer
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_RxSignalGroupShadowBufferUpdate
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    CONSTP2CONST(uint8,AUTOMATIC,COM_APPL_CONST) RxIpduSrcBufferPtr , 
    PduLengthType BufferLength
);
#endif
/********************************************************************************************************************
*   @brief     This service is used to update the shadow buffer data with the received data
*   @param[in] RxIpduId Rx Ipdu id 
*   @param[in] InitTimeout intialize the timeout value
*   @param[in] StateCheck flag to enable the previous state check
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_RxDeadlineMonitoringControl
(
    PduIdType RxIpduId,
    boolean InitTimeout,
    boolean StateCheck
);
/********************************************************************************************************************
*                                 #!Public Function Implementation                                                  *
*                                 #!Start-Up and Control Services                                                   *
********************************************************************************************************************/   
/********************************************************************************************************************
*   @brief      This service initializes internal and external interfaces and variables of the AUTOSAR COM module 
*   layer for the further processing. After calling this function the inter-ECU communication is still disabled.
*   @param[in]  config  Pointer to the Com post-build configuration data.
*   @ServiceID  0x01
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
*   @note       The Com module's environment shall call Com_Init before using the Com module for further
*               processing
********************************************************************************************************************/   
FUNC(void,COM_CODE) Com_Init(P2CONST(Com_ConfigType,AUTOMATIC,COM_APPL_CONST) config)
{
    uint8 ErrorId = COM_E_NO_ERROR;

    if (COM_UNINIT != COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
    else
    {
        /* Initialize Tx Pdu */
        Com_InitTxIpdu();
        /* Initialize Rx Pdu */
        Com_InitRxIpdu();
        /* Update Init Status */
        COM_InitStatus = COM_INIT;
    }
    COM_DUMMY_STATEMENT(config);
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (COM_E_NO_ERROR != ErrorId)
    {
        Com_DetReportError(COM_SID_INIT, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This service stops the inter-ECU communication. All started I-PDU groups are stopped and have
*   to be started again, if needed, after Com_Init is called. By a call to Com_DeInit the AUTOSAR COM module
*   is put into an not initialized state.
*   @ServiceID  0x02
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(void,COM_CODE) Com_DeInit(void)
{
    /* Local Variables */
    PduIdType TxIpduId;
    PduIdType RxIpduId;
    uint8 ErrorId = COM_E_NO_ERROR;

    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
    else
    {
        /* Stop all Tx Pdus */
        for(TxIpduId = 0;TxIpduId< COM_NUM_OF_TX_IPDU_ID;TxIpduId++)
        {
            if (Com_GetTxIpduGroupActive(TxIpduId) == TRUE)
            {
               Com_DeactivateTxIpdu(TxIpduId);
            }
        }
        /* Stop all Rx Pdus */
        for(RxIpduId = 0U;RxIpduId<COM_NUM_OF_RX_IPDU_ID;RxIpduId++)
        {
            if (Com_GetRxIpduGroupActive(RxIpduId) == TRUE)
            {
                Com_DeactivateRxIpdu(RxIpduId);
            }
        }
        /* Update Init Status */
        COM_InitStatus = COM_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_DEINIT, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This service starts a preconfigured I-PDU group. For example, cyclic I-PDUs will be sent out 
*               cyclically after the call of Com_IpduGroupStart(). If Initialize is true all I-PDUs of the 
*               I-PDU group shall be (re-)initialized before the I-PDU group is started. That is they shall behave
*               like after a start-up of COM, for example the old_value of the filter objects and shadow buffers of 
*               signal groups have to be (re-)initialized
*   @param[in]  IpduGroupId Id of I-PDU group to be started.
*   @param[in]  initialize  flag to request initialization of the data in the I-PDUs of this I-PDU group.
*   @ServiceID  0x03
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different I-PDU groups. Non reentrant for the same I-PDU group.
********************************************************************************************************************/
FUNC(void,COM_CODE) Com_IpduGroupStart( Com_IpduGroupIdType IpduGroupId, boolean initialize )
{
    PduIdType IpduId;
    uint8 IpduGroupBitIndex=0U;
    uint8 IpduGroupMapValue=0U;
    uint8 ErrorId = COM_E_NO_ERROR;
    Com_IpduGroupByteIdType IpduGroupByteIndex=0U;
    
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
    else if (COM_SUPPORTED_IPDU_GROUPS <= IpduGroupId)
    {
        ErrorId = COM_E_PARAM;
    }
    else
    {       
        /* Get Byte and Bit Index for the IpduGroupId */
        IpduGroupByteIndex = IpduGroupId/8U;
        IpduGroupBitIndex = IpduGroupId%8U;
        
        /* loop through all the TxIpduId and check if the Tx IpduId is supported by the requested IpduGroupId */
        for (IpduId = 0U ;IpduId < COM_NUM_OF_TX_IPDU_ID ;IpduId++)
        {
            /* Start Tx IpduId if it was previously stopped */
            if (FALSE == Com_GetTxIpduGroupActive(IpduId))
            {
                /* Get IpduGroupMap for the Tx Ipdu */
                IpduGroupMapValue = Com_IpduToIpduGroupMapTxConfig[IpduId].IpduGroupVectorMap[IpduGroupByteIndex];
                /* Check if the Tx Ipdu is supported for this GroupId, then activate the Tx Ipdu and intialize 
                   Tx Ipdu based on the Initialize flag */
                if (FALSE != Com_UtilIsBitSet(IpduGroupMapValue,IpduGroupBitIndex))
                {
                    Com_ActivateTxIpdu(IpduId, initialize);
                }
            }
        }
        
        /* loop through all the Rx IpduId and check if the Rx IpduId is supported by the requested IpduGroupId */
        for (IpduId = 0U ;IpduId < COM_NUM_OF_RX_IPDU_ID ;IpduId++)
        {
            /* Start Rx IpduId if it was previously stopped */
            if (FALSE == Com_GetRxIpduGroupActive(IpduId))
            {
                /* Get IpduGroupMap for the Rx Ipdu */
                IpduGroupMapValue = Com_IpduToIpduGroupMapRxConfig[IpduId].IpduGroupVectorMap[IpduGroupByteIndex];
                /* Check if the Rx Ipdu is supported for this GroupId, then activate the Rx Ipdu and intialize 
                   Rx Ipdu based on the Initialize flag */
                if (FALSE != Com_UtilIsBitSet(IpduGroupMapValue,IpduGroupBitIndex))
                {
                    Com_ActivateRxIpdu(IpduId, initialize);
                }
            }
        }
        Com_UtilSetClearBit(&Com_IpduGroupMapValue[IpduGroupByteIndex],IpduGroupBitIndex,TRUE);
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_IPDUGROUPSTART, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      Stops a preconfigured I-PDU group. For example, cyclic I-PDUs will be stopped after the call of 
*               Com_IpduGroupStop().
*   @param[in]  IpduGroupId Id of I-PDU group to be stopped
*   @ServiceID  0x04
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different I-PDU groups. Non reentrant for the same I-PDU group.
********************************************************************************************************************/
FUNC(void,COM_CODE) Com_IpduGroupStop(Com_IpduGroupIdType IpduGroupId)
{
    PduIdType IpduId;
    uint8 IpduGroupBitIndex=0U;
    uint8 IpduGroupMapValue=0U;
    uint8 ErrorId = COM_E_NO_ERROR;
    Com_IpduGroupByteIdType IpduGroupByteIndex=0U;
    
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
    else if (COM_SUPPORTED_IPDU_GROUPS <= IpduGroupId)
    {
        ErrorId = COM_E_PARAM;
    }
    else
    {     
        /* Get Byte and Bit Index for the IpduGroupId */
        IpduGroupByteIndex = IpduGroupId/8U;
        IpduGroupBitIndex = IpduGroupId%8U;
        
        /* loop through all the TxIpduId and check if the Tx IpduId is supported by the requested IpduGroupId */
        for (IpduId = 0U; IpduId < COM_NUM_OF_TX_IPDU_ID; IpduId++)
        {
            /* Start Tx IpduId if it was previously started */
            if (TRUE == Com_GetTxIpduGroupActive(IpduId))
            {
                /* Get IpduGroupMap for the Tx Ipdu */
                IpduGroupMapValue = Com_IpduToIpduGroupMapTxConfig[IpduId].IpduGroupVectorMap[IpduGroupByteIndex];
                /* Check if the Tx Ipdu is supported for this GroupId, then deactivate the Tx Ipdu */
                if (FALSE != Com_UtilIsBitSet(IpduGroupMapValue,IpduGroupBitIndex))
                {
                    Com_DeactivateTxIpdu(IpduId);
                }
            }
            /*! TODO Error nofitication Com_CbkTxErrFunct */
        }
        
        /* loop through all the Rx IpduId and check if the Rx IpduId is supported by the requested IpduGroupId */
        for (IpduId = 0U; IpduId < COM_NUM_OF_RX_IPDU_ID; IpduId++)
        {
            /* Start Rx IpduId if it was previously started */
            if (TRUE == Com_GetRxIpduGroupActive(IpduId))
            {
                /* Get IpduGroupMap for the Rx Ipdu */
                IpduGroupMapValue = Com_IpduToIpduGroupMapRxConfig[IpduId].IpduGroupVectorMap[IpduGroupByteIndex];
                /* Check if the Rx Ipdu is supported for this GroupId, then deactivate the Rx Ipdu */
                if (FALSE != Com_UtilIsBitSet(IpduGroupMapValue,IpduGroupBitIndex))
                {
                    Com_DeactivateRxIpdu(IpduId);
                }
            }
        }
        Com_UtilSetClearBit(&Com_IpduGroupMapValue[IpduGroupByteIndex],IpduGroupBitIndex,FALSE);
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_IPDUGROUPSTOP, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      Enables the reception deadline monitoring for the I-PDUs within the given I-PDU group.
*   @param[in]  Id of I-PDU group where reception DM shall be enabled.
*   @ServiceID  0x06
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different I-PDU groups. Non reentrant for the same I-PDU group.
********************************************************************************************************************/
FUNC(void,COM_CODE) Com_EnableReceptionDM( Com_IpduGroupIdType IpduGroupId )
{
    PduIdType IpduId;
    uint8 IpduGroupBitIndex=0U;
    uint8 IpduGroupMapValue=0U;
    uint8 ErrorId = COM_E_NO_ERROR;
    Com_IpduGroupByteIdType IpduGroupByteIndex=0U;
    
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
    else if (COM_SUPPORTED_IPDU_GROUPS <= IpduGroupId)
    {
        ErrorId = COM_E_PARAM;
    }
    else
    {     
        /* Get Byte and Bit Index for the IpduGroupId */
        IpduGroupByteIndex = IpduGroupId/8U;
        IpduGroupBitIndex = IpduGroupId%8U;
        
        /* loop through all the Rx IpduId and check if the Rx IpduId is supported by the requested IpduGroupId */
        for (IpduId = 0U; IpduId < COM_NUM_OF_RX_IPDU_ID; IpduId++)
        {
            /* Get IpduGroupMap for the Rx Ipdu */
            IpduGroupMapValue = Com_IpduToIpduGroupMapRxConfig[IpduId].IpduGroupVectorMap[IpduGroupByteIndex];
            /* Check if the Rx Ipdu is supported for this GroupId, then deactivate the Rx Ipdu */
            if (FALSE != Com_UtilIsBitSet(IpduGroupMapValue,IpduGroupBitIndex))
            {
                Com_RxDeadlineMonitoringControl(IpduId,TRUE,TRUE);
            }
        }
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_ENABLERECEPTIONDM, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      Disables the reception deadline monitoring for the I-PDUs within the given I-PDU group.
*   @param[in]  Id of I-PDU group where reception DM shall be enabled.
*   @ServiceID  0x05
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different I-PDU groups. Non reentrant for the same I-PDU group.
********************************************************************************************************************/
FUNC(void,COM_CODE) Com_DisableReceptionDM( Com_IpduGroupIdType IpduGroupId )
{
    PduIdType IpduId;
    uint8 IpduGroupBitIndex=0U;
    uint8 IpduGroupMapValue=0U;
    uint8 ErrorId = COM_E_NO_ERROR;
    Com_IpduGroupByteIdType IpduGroupByteIndex=0U;
    
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
    else if (COM_SUPPORTED_IPDU_GROUPS <= IpduGroupId)
    {
        ErrorId = COM_E_PARAM;
    }
    else
    {     
        /* Get Byte and Bit Index for the IpduGroupId */
        IpduGroupByteIndex = IpduGroupId/8U;
        IpduGroupBitIndex = IpduGroupId%8U;
        
        /* loop through all the Rx IpduId and check if the Rx IpduId is supported by the requested IpduGroupId */
        for (IpduId = 0U; IpduId < COM_NUM_OF_RX_IPDU_ID; IpduId++)
        {
            /* Get IpduGroupMap for the Rx Ipdu */
            IpduGroupMapValue = Com_IpduToIpduGroupMapRxConfig[IpduId].IpduGroupVectorMap[IpduGroupByteIndex];
            /* Check if the Rx Ipdu is supported for this GroupId, then deactivate the Rx Ipdu */
            if (FALSE != Com_UtilIsBitSet(IpduGroupMapValue,IpduGroupBitIndex))
            {
                Com_RxDeadlineMonitoringControl(IpduId,FALSE,FALSE);
            }
        }
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_DISABLERECEPTIONDM, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif    
}

/********************************************************************************************************************
*   @brief      This service returns the status of the AUTOSAR COM module
*   @Return     Com_StatusType status of COM module
*               - COM_UNINIT : the AUTOSAR COM module is not initialized and not usable 
*               - COM_INIT   : the AUTOSAR COM module is initialized and usable
*   @ServiceID  0x07
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(Com_StatusType,COM_CODE) Com_GetStatus(void)
{
    Com_StatusType ComCurrentState;
    /* Enter Critical section */
    Com_EnterCriticalSection();
    /* Get Current Com Init State */
    ComCurrentState = COM_InitStatus;
    /* Exit Critical section */
    Com_ExitCriticalSection();
    /* return the current com state */
    return ComCurrentState;
}

#if (COM_VERSION_INFO_API == STD_ON)
/********************************************************************************************************************
*   @brief      This service returns the version information of this module.
*   @param[in]  VersionInfo Pointer to where to store the version information of this module. 
*   @ServiceID  0x09
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/    
FUNC(void,COM_CODE) Com_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,COM_APPL_DATA) VersionInfo)
{
#if (COM_DEV_ERROR_DETECT == STD_ON)
    /* Local Variables */
    uint8 ErrorId = COM_E_NO_ERROR;

    /* Check if parameter VersionInfo is valid */
    if (VersionInfo == NULL_PTR)
    {
        ErrorId = COM_E_PARAM_POINTER;
    }
    else
#endif
    {
        VersionInfo->vendorID         = COM_VENDOR_ID;
        VersionInfo->moduleID         = COM_MODULE_ID;
        VersionInfo->sw_major_version = COM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = COM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = COM_SW_PATCH_VERSION;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_GETVERSIONINFO, ErrorId);
    }
#endif
}
#endif

/********************************************************************************************************************
*                                  #!Communication Services                                                         *
********************************************************************************************************************/
/********************************************************************************************************************
*   @brief      The service Com_SendSignal updates the signal object identified by SignalId with the signal 
*   referenced by the SignalDataPtr parameter.
*   @param[in]  SignalId Id of signal to be sent.
*   @param[in]  SignalDataPtr Reference to the signal data to be transmitted.
*   @return     uint8 status of the request 
*               - E_OK: service has been accepted.
*               - COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to 
*               development error).
*               - COM_BUSY: in case the TP-Buffer is locked for large data types handling
*   @ServiceID  0x0A
*   @Sync/Async Asynchronous 
*   @Reentrancy Non Reentrant for the same signal. Reentrant for different signals.
********************************************************************************************************************/
FUNC(uint8,COM_CODE) Com_SendSignal(Com_SignalIdType SignalId, P2CONST(void,AUTOMATIC,COM_APPL_CONST) SignalDataPtr)
{
    /* Local Variables */
    uint8 ErrorId = COM_E_NO_ERROR;
    uint8 ReturnValue = COM_SERVICE_NOT_AVAILABLE;

    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    /* Check whether signal Id is valid */
    else if (COM_NUM_OF_TX_SIGNAL_ID <= SignalId)
    {
        ErrorId = COM_E_PARAM;
    }
    /* Check whether signal Information is valid */
    else if (NULL_PTR == SignalDataPtr)
    {
        ErrorId = COM_E_PARAM_POINTER;
    }
#endif
    else
    {
        /* Update signal Information to IPDU */
        ReturnValue = Com_ProcessSendSignal(SignalId, SignalDataPtr,0U);
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_SENDSIGNAL, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      The service Com_SendDynSignal shall update the signal ob-ject identified by SignalId with the signal 
*   referenced by the SignalDataPtr parameter.
*   @param[in]  SignalId Id of signal to be sent.
*   @param[in]  SignalDataPtr Reference to the signal data to be transmitted.
*   @param[in]  Length Length of the dynamic length signal
*   @return     uint8 status of the request 
*               - E_OK: service has been accepted.
*               - E_NOT_OK: in case the Length is greater than the configured ComSignalLength of this sent signal
*               - COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to 
*               development error).
*               - COM_BUSY: in case the TP-Buffer is locked for large data types handling
*   @ServiceID  0x21
*   @Sync/Async Asynchronous 
*   @Reentrancy Non Reentrant for the same signal. Reentrant for different signals.
********************************************************************************************************************/
FUNC(uint8,COM_CODE) Com_SendDynSignal
(
    Com_SignalIdType SignalId,
    P2CONST(void,AUTOMATIC,COM_APPL_CONST) SignalDataPtr,
    uint16 Length
)
{
    uint8 ReturnValue = COM_SERVICE_NOT_AVAILABLE;
    uint8 ErrorId = COM_E_NO_ERROR;
    
    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    /* Check whether signal Id is valid */
    else if (COM_NUM_OF_TX_SIGNAL_ID <= SignalId)
    {
        ErrorId = COM_E_PARAM;
    }
    /* Check whether signal Information is valid */
    else if (NULL_PTR == SignalDataPtr)
    {
        ErrorId = COM_E_PARAM_POINTER;
    }
#endif
    else
    {
#if(COM_TX_SIGNAL_DYN_SUPPORT == STD_ON)
        ReturnValue = Com_ProcessSendSignal(SignalId,SignalDataPtr,Length);
#endif
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_SENDDYNSIGNAL, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      The service Com_ReceiveSignal shall copy the data of the signal object identified by SignalId to the 
*   position referenced by SignalDataPtr.
*   @param[in]  SignalId Id of signal to be received
*   @param[out]  SignalDataPtr Reference to the location where the received signal data shall be stored
*   @return     uint8 status of the request 
*               - E_OK: service has been accepted.
*               - COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to 
*               development error).
*               - COM_BUSY: in case the TP-Buffer is locked for large data types handling
*   @ServiceID  0x0B
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant for the same signal. Reentrant for different signals.
*   @Note The AUTOSAR COM module relies on the fact the SignalDataPtr is properly aligned with respect to the data 
*   type of the signal with the given SignalId. The caller of Com_ReceiveSignal has to ensure this.
********************************************************************************************************************/
FUNC(uint8,COM_CODE) Com_ReceiveSignal(Com_SignalIdType SignalId, P2VAR(void,AUTOMATIC,COM_APPL_DATA) SignalDataPtr)
{
    uint8 ErrorId = COM_E_NO_ERROR;
    uint8 ReturnValue = COM_SERVICE_NOT_AVAILABLE;
    
    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    /* Check whether signal Id is valid */
    else if (COM_NUM_OF_RX_SIGNAL_ID <= SignalId)
    {
        ErrorId = COM_E_PARAM;
    }
    /* Check whether signal Information is valid */
    else if (NULL_PTR == SignalDataPtr)
    {
        ErrorId = COM_E_PARAM_POINTER;
    }
#endif
    else
    {
        /* Update signal Information to IPDU */
        ReturnValue = Com_ReceiveSignalProcessing(SignalId, SignalDataPtr);
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_RECEIVESIGNAL, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      The service  Com_ReceiveDynSignal copies the data of the signal identified by SignalId to the location
*   specified by SignalDataPtr and stores the length of the dynamical length signal at the position given by the Length 
*   parameter.
*   @param[in]  SignalId Id of signal to be received
*   @param[in,out]  Length length of the signal
*                   - in: maximum length that could be received 
*                   - out: length of the dynamic length signal
*   @param[out] SignalDataPtr Reference to the location where the received signal data shall be stored
*   @return     uint8 status of the request 
*               - E_OK: service has been accepted.
*               - E_NOT_OK: in case the Length (as in-parameter) is smaller than the received length of the dynamic 
*               length signal
*               - COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to 
*               development error).
*               - COM_BUSY: in case the TP-Buffer is locked for large data types handling
*   @ServiceID  0x22
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant for the same signal. Reentrant for different signals.
********************************************************************************************************************/
FUNC(uint8,COM_CODE) Com_ReceiveDynSignal
(
    Com_SignalIdType SignalId, 
    P2VAR(void,AUTOMATIC,COM_APPL_DATA) SignalDataPtr,
    P2VAR(uint16,AUTOMATIC,COM_APPL_DATA) Length
)
{
    uint8 ErrorId = COM_E_NO_ERROR;
    uint8 ReturnValue = COM_SERVICE_NOT_AVAILABLE;
#if(COM_RX_SIGNAL_DYN_SUPPORT == STD_ON)
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr;
    PduLengthType ReceivedLength;
    Com_RxRteBufferIdType RteBufferIndex;
#endif
    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    /* Check whether signal Id is valid */
    else if (COM_NUM_OF_RX_SIGNAL_ID <= SignalId)
    {
        ErrorId = COM_E_PARAM;
    }
    /* Check whether signal Information is valid */
    else if ((NULL_PTR == SignalDataPtr) || (NULL_PTR == Length))
    {
        ErrorId = COM_E_PARAM_POINTER;
    }
#endif
    else
    {
#if(COM_RX_SIGNAL_DYN_SUPPORT == STD_ON)
        /* Get Signal Configuration */
        RxSignalConfigPtr = &Com_RxSignalConfig[SignalId];
        if (RxSignalConfigPtr->SignalType == COM_SIGNALTYPE_UINT8_DYN)
        {
            RteBufferIndex = RxSignalConfigPtr->RteBufferIdx ;
            ReceivedLength = Com_GetRxIpduBufferLength(RxSignalConfigPtr->ComPduId) - RxSignalConfigPtr->LsBytePosition;
            /* COM_SIGNALTYPE_UINT8_N */
            if ((COM_RX_SIGNAL_RTE_ARRBUFFER_SIZE > RteBufferIndex ) &&
                (COM_RX_SIGNAL_RTE_ARRBUFFER_SIZE >= (ReceivedLength+RteBufferIndex)) &&
                (*Length >= ReceivedLength))
            {
                Com_UtilMemCopy((uint8*)SignalDataPtr,&Com_RxSignalRteArrBuffer[RteBufferIndex],ReceivedLength);
                *Length = ReceivedLength;
                if(Com_GetRxIpduGroupActive(RxSignalConfigPtr->ComPduId)== TRUE)
                {
                    ReturnValue = E_OK;
                }
            }
            else
            {
                *Length = ReceivedLength;
                ReturnValue = E_NOT_OK;
            }
        }
#endif
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_RECEIVEDYNSIGNAL, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
    #endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      The service Com_SendSignalGroup shall copy the content of the shadow buffer referenced by parameter 
*   SignalGroupId to the associated I-PDU
*   @param[in]  SignalGroupId Id of signal group to be sent.
*   @Return     uint8 status of the request .
*               - E_OK: service has been accepted. 
*               - COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to 
*                 development error). 
*               - COM_BUSY: in case the TP-Buffer is locked for large data types handling.
*   @ServiceID  0x0D
*   @Sync/Async Asynchronous 
*   @Reentrancy Non Reentrant for the same group signal. Reentrant for different group signals.
********************************************************************************************************************/
FUNC(uint8,COM_CODE) Com_SendSignalGroup(Com_SignalGroupIdType SignalGroupId)
{
    /* Local Variables */
    uint8 ErrorId = COM_E_NO_ERROR;
    uint8 ReturnValue = COM_SERVICE_NOT_AVAILABLE;
    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    /* Check whether signal Id is valid */
    else if (COM_NUM_OF_TX_SIGNAL_GROUP_ID <= SignalGroupId)
    {
        ErrorId = COM_E_PARAM;
    }
#endif
    else
    {
#if(COM_TX_SIGNAL_GROUP_SUPPORT == STD_ON)
        ReturnValue = Com_ProcessSendSignalGroup(SignalGroupId);
#endif
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_SENDSIGNALGROUP, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      The service Com_ReceiveSignalGroup shall copy the received signal group from the I-PDU to the shadow 
*   buffer.
*   @param[in]  SignalGroupId Id of signal group to be received
*   @Return     uint8 status of the request .
*               - E_OK: service has been accepted. 
*               - COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to 
*                 development error). 
*               - COM_BUSY: in case the TP-Buffer is locked for large data types handling.
*   @ServiceID  0x0E
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant for the same group signal. Reentrant for different group signals.
*   @Note After this call, the group signals could be copied from the shadow buffer to the RTE by calling 
*   Com_ReceiveSignal.
********************************************************************************************************************/
FUNC(uint8,COM_CODE) Com_ReceiveSignalGroup(Com_SignalGroupIdType SignalGroupId)
{
    uint8 ErrorId = COM_E_NO_ERROR;
    uint8 ReturnValue = COM_SERVICE_NOT_AVAILABLE;
#if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
    P2CONST(Com_RxSignalGroupConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalGroupConfigPtr;
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr;
    Com_SignalIdType RxSignalIdx;
    Com_RxRteShadowBufferIdType SrcRteBufferIndex;
    Com_RxRteShadowBufferIdType DestRteBufferIndex;
#endif
    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    /* Check whether signal Id is valid */
    else if (COM_NUM_OF_RX_SIGNAL_GROUP_ID <= SignalGroupId)
    {
        ErrorId = COM_E_PARAM;
    }
#endif
    else
    {
#if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
        RxSignalGroupConfigPtr = &Com_RxSignalGroupConfig[SignalGroupId];
        #ifdef COM_ENABLE_EXTENDED_COV_CHECK
        if (COM_NUM_OF_RX_IPDU_ID > RxSignalGroupConfigPtr->ComPduId)
        #endif
        {
            for(RxSignalIdx = RxSignalGroupConfigPtr->GroupSignalStartId;
                RxSignalIdx <= RxSignalGroupConfigPtr->GroupSignalEndId;RxSignalIdx++)
            {
                RxSignalConfigPtr = &Com_RxSignalConfig[RxSignalIdx];
                SrcRteBufferIndex = RxSignalConfigPtr->RteShadowBufferIdx;
                DestRteBufferIndex = RxSignalConfigPtr->RteBufferIdx;
                Com_EnterCriticalSection();
                /* Copy data from the Rte signal buffer */
                switch(RxSignalConfigPtr->SignalType)
                {
                    case COM_SIGNALTYPE_BOOLEAN:
                    case COM_SIGNALTYPE_UINT8:
                    case COM_SIGNALTYPE_SINT8:
                        #ifdef COM_ENABLE_EXTENDED_COV_CHECK
                        if ((COM_RX_SIGNAL_RTE_U8BUFFER_SIZE > DestRteBufferIndex ) &&
                            (COM_RX_SIGNAL_SHADOW_RTE_U8BUFFER_SIZE > SrcRteBufferIndex))
                        #endif
                        {
                            Com_RxSignalRteU8Buffer[DestRteBufferIndex] = Com_RxSignalShadowRteU8Buffer[SrcRteBufferIndex];
                            ReturnValue = E_OK;
                        }
                        break;
                    case COM_SIGNALTYPE_UINT16:
                    case COM_SIGNALTYPE_SINT16:
                        #ifdef COM_ENABLE_EXTENDED_COV_CHECK
                        if ((COM_RX_SIGNAL_RTE_U16BUFFER_SIZE > DestRteBufferIndex ) &&
                            (COM_RX_SIGNAL_SHADOW_RTE_U16BUFFER_SIZE > SrcRteBufferIndex))
                        #endif
                        {
                            Com_RxSignalRteU16Buffer[DestRteBufferIndex] = Com_RxSignalShadowRteU16Buffer[SrcRteBufferIndex];
                            ReturnValue = E_OK;
                        }
                        break;
                    case COM_SIGNALTYPE_UINT32:
                    case COM_SIGNALTYPE_SINT32:
                    case COM_SIGNALTYPE_FLOAT32:
                        #ifdef COM_ENABLE_EXTENDED_COV_CHECK
                        if ((COM_RX_SIGNAL_RTE_U32BUFFER_SIZE > DestRteBufferIndex ) &&
                            (COM_RX_SIGNAL_SHADOW_RTE_U32BUFFER_SIZE > SrcRteBufferIndex))
                        #endif
                        {
                            Com_RxSignalRteU32Buffer[DestRteBufferIndex] = Com_RxSignalShadowRteU32Buffer[SrcRteBufferIndex];
                            ReturnValue = E_OK;
                        }
                        break;
                    case COM_SIGNALTYPE_UINT64:
                    case COM_SIGNALTYPE_SINT64:
                    case COM_SIGNALTYPE_FLOAT64:
                        #ifdef COM_ENABLE_EXTENDED_COV_CHECK
                        if ((COM_RX_SIGNAL_RTE_U64BUFFER_SIZE > DestRteBufferIndex ) &&
                            (COM_RX_SIGNAL_SHADOW_RTE_U64BUFFER_SIZE > SrcRteBufferIndex))
                        #endif
                        {
                            Com_RxSignalRteU64Buffer[DestRteBufferIndex] = Com_RxSignalShadowRteU64Buffer[SrcRteBufferIndex];
                            ReturnValue = E_OK;
                        }
                        break;
                    case COM_SIGNALTYPE_UINT8_N:    
                        #ifdef COM_ENABLE_EXTENDED_COV_CHECK
                        /* COM_SIGNALTYPE_UINT8_N */
                        if ((COM_RX_SIGNAL_RTE_ARRBUFFER_SIZE >= (RxSignalConfigPtr->ByteLength+DestRteBufferIndex)) &&
                            (COM_RX_SIGNAL_SHADOW_RTE_ARRBUFFER_SIZE >= (RxSignalConfigPtr->ByteLength+SrcRteBufferIndex)))
                        #endif
                        {
                            Com_UtilMemCopy(&Com_RxSignalRteArrBuffer[DestRteBufferIndex],
                                            &Com_RxSignalShadowRteArrBuffer[SrcRteBufferIndex],RxSignalConfigPtr->ByteLength);
                            ReturnValue = E_OK;
                        }
                        break;
                    default:
                        /* Do Nothing*/
                        break;
                } 
                Com_ExitCriticalSection();
            }
                
            if (Com_GetRxIpduGroupActive(RxSignalGroupConfigPtr->ComPduId) != TRUE)
            {
                ReturnValue = COM_SERVICE_NOT_AVAILABLE;
            }
        }
#endif
    }
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_RECEIVESIGNALGROUP, ErrorId);
    }
    #else
    COM_DUMMY_STATEMENT(ErrorId);
    #endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      The service Com_SendSignalGroupArray copies the content of the provided SignalGroupArrayPtr to the 
*   associated I-PDU. The provided data shall correspond to the array representation of the signal group
*   @param[in]  SignalGroupId Id of group signal to be received
*   @param[in]  SignalGroupArrayPtr Reference to the signal group array.
*   @return     uint8 status of the request.
*               - E_OK: service has been accepted 
*               - COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to 
*               development error) 
*               - COM_BUSY: in case the TP-Buffer is locked for large data types handling
*   @ServiceID  0x23
*   @Sync/Async Asynchronous 
*   @Reentrancy Non Reentrant for the same signal group. Reentrant for different signal groups.
********************************************************************************************************************/
FUNC(uint8,COM_CODE) Com_SendSignalGroupArray
(
    Com_SignalGroupIdType SignalGroupId, 
    P2CONST(uint8,AUTOMATIC,COM_APPL_CONST) SignalGroupArrayPtr
)
{
    /* Check if the group ID supports signal group array*/
    uint8 ErrorId = COM_E_NO_ERROR;
    uint8 ReturnValue = COM_SERVICE_NOT_AVAILABLE;
#if(COM_TX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON)
    PduLengthType Idx;
    boolean IsSignalGroupDataChanged = FALSE;
    Com_UtilBitCopyPropsType UtilBitCopyProps;
    P2CONST(Com_TxSignalGroupConfigType,AUTOMATIC,COM_APPL_CONST) TxSignalGroupConfigPtr;
    P2CONST(Com_TxIpduBufferConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduBufferConfigPtr;
    P2CONST(uint8,AUTOMATIC,COM_APPL_CONST) OnChangeMaskPtr;
    P2CONST(uint8,AUTOMATIC,COM_APPL_CONST) NewDataPtr;
    P2CONST(uint8,AUTOMATIC,COM_APPL_CONST) OldDataPtr;
#if (COM_TX_SIGNAL_GROUP_UB_SUPPORT == STD_ON)
    Com_RxSignalGroupArrayBufferIdType ByteOffset;
#endif
#endif
    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    /* Check whether signal Id is valid */
    else if (COM_NUM_OF_TX_SIGNAL_GROUP_ID <= SignalGroupId)
    {
        ErrorId = COM_E_PARAM;
    }
    else if (NULL_PTR == SignalGroupArrayPtr)
    {
        ErrorId = COM_E_PARAM_POINTER;
    }
#endif
    else
    {
#if(COM_TX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON)
        TxSignalGroupConfigPtr = &Com_TxSignalGroupConfig[SignalGroupId];
        if (TxSignalGroupConfigPtr->SignalGroupArrayAccess == TRUE)
        {
            /* TODO : Filter update */
            /* get the data buffer index of the signal */
            /* get trigger on change Mask buffer , for trigger on change check signals with on change properties*/
            TxIpduBufferConfigPtr = &Com_TxIpduBufferConfig[TxSignalGroupConfigPtr->ComPduId];
            OnChangeMaskPtr = &Com_SignalArrayOnChageMask[TxSignalGroupConfigPtr->OnChangeBufferStartId];
            NewDataPtr = SignalGroupArrayPtr;
            OldDataPtr = &Com_TxIpduBuffer[TxIpduBufferConfigPtr->BufferStartId+TxSignalGroupConfigPtr->LsBytePosition];
            for(Idx=0;Idx< TxSignalGroupConfigPtr->ByteLength;Idx++)
            {
                if (((NewDataPtr[Idx]) & OnChangeMaskPtr[Idx])!=  (OldDataPtr[Idx] & OnChangeMaskPtr[Idx]))
                {
                    IsSignalGroupDataChanged = TRUE;
                    break;
                }
            }
            /* Copy the data to the original buffer */
            /* Update the bit copy details */
            UtilBitCopyProps.SignalLengthInBits  = TxSignalGroupConfigPtr->BitSize;
            UtilBitCopyProps.SingalLengthInBytes = TxSignalGroupConfigPtr->ByteLength;
            #if(COM_MICRO_ENDIANESS == COM_ENDIANESS_LITTLE)
            UtilBitCopyProps.SrcLsBit = 0U;  
            UtilBitCopyProps.SrcLsByte = 0U;
            UtilBitCopyProps.SrcBufferEndianess = COM_ENDIANESS_LITTLE;
            #else
            UtilBitCopyProps.SrcLsBit = 0U;  
            UtilBitCopyProps.SrcLsByte = TxSignalGroupConfigPtr->ByteLength;
            UtilBitCopyProps.SrcBufferEndianess = COM_ENDIANESS_BIG;
            #endif
            UtilBitCopyProps.MaxSrcBufferSize = TxSignalGroupConfigPtr->ByteLength;
            UtilBitCopyProps.DestLsBit = TxSignalGroupConfigPtr->LsBitPosition;
            UtilBitCopyProps.DestLsByte = TxSignalGroupConfigPtr->LsBytePosition; 
            UtilBitCopyProps.MaxDestBufferSize = TxIpduBufferConfigPtr->MaximumLength;
            /* Opaque uint8[n] is for same as Little Endian , bit 0 in byte 0*/
            UtilBitCopyProps.DestBufferEndianess = COM_ENDIANESS_LITTLE;
            /* copy the data from shadow to TxIpdu buffer */
            if (COM_TX_IPDU_BUFFER_SIZE > TxIpduBufferConfigPtr->BufferStartId)
            {
                Com_UtilBitCopy(&UtilBitCopyProps,SignalGroupArrayPtr,
                                    &Com_TxIpduBuffer[TxIpduBufferConfigPtr->BufferStartId]);
            }
            
            #if (COM_TX_SIGNAL_GROUP_UB_SUPPORT == STD_ON)
            /* Update the UB */
            ByteOffset = TxIpduBufferConfigPtr->BufferStartId+TxSignalGroupConfigPtr->UBBytePosition;
            if (COM_TX_IPDU_BUFFER_SIZE > ByteOffset)
            {
                Com_UtilSetClearBit(&Com_TxIpduBuffer[ByteOffset],TxSignalGroupConfigPtr->UBBitPosition,TRUE);
            }    
            #endif
            
            /* evaluate transfer property */
            switch (TxSignalGroupConfigPtr->TransferPropertyType)
            {
                case COM_SIGNAL_TRANSFER_PROPERTY_TYPE_TRIGGERED:
                    Com_TriggerDirectTransmission(TxSignalGroupConfigPtr->ComPduId,FALSE);
                    break;
                case COM_SIGNAL_TRANSFER_PROPERTY_TYPE_TRIGGERED_WITHOUT_REPETITION:
                    Com_TriggerDirectTransmission(TxSignalGroupConfigPtr->ComPduId,TRUE);
                    break;
                case COM_SIGNAL_TRANSFER_PROPERTY_TYPE_TRIGGERED_ON_CHANGE:
                    if (IsSignalGroupDataChanged == TRUE)
                    {
                        Com_TriggerDirectTransmission(TxSignalGroupConfigPtr->ComPduId,FALSE);
                    }
                    break;
                case COM_SIGNAL_TRANSFER_PROPERTY_TYPE_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION:
                    if (IsSignalGroupDataChanged == TRUE)
                    {
                        Com_TriggerDirectTransmission(TxSignalGroupConfigPtr->ComPduId,TRUE);
                    }
                    break;
                default: /* COM_SIGNAL_TRANSFER_PROPERTY_TYPE_PENDING */
                    break;
            }
            ReturnValue = E_OK;
        }
#endif
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_SENDSIGNALGROUPARRAY, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      The service Com_ReceiveSignalGroupArray copies the received signal group array representation from 
*               the PDU to the location designated by SignalGroupArrayPtr.
*   @param[in]  SignalGroupId Id of signal group to be received.
*   @param[out] SignalGroupArrayPtr reference to the location where the received signal group array shall be stored
*   @return     uint8 status of the request.
*               - E_OK: service has been accepted 
*               - COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to 
*               development error) 
*               - COM_BUSY: in case the TP-Buffer is locked for large data types handling
*   @ServiceID  0x24
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant for the same signal group. Reentrant for different signal groups.
********************************************************************************************************************/
FUNC(uint8,COM_CODE) Com_ReceiveSignalGroupArray
(
    Com_SignalGroupIdType SignalGroupId,
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) SignalGroupArrayPtr
)
{
    uint8 ErrorId = COM_E_NO_ERROR;
    uint8 ReturnValue = COM_SERVICE_NOT_AVAILABLE;
#if(COM_RX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON)
    P2CONST(Com_RxSignalGroupConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalGroupConfigPtr;
    Com_RxSignalGroupArrayBufferIdType ByteOffset;
#endif
    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    /* Check whether signal Id is valid */
    else if (COM_NUM_OF_RX_SIGNAL_GROUP_ID <= SignalGroupId)
    {
        ErrorId = COM_E_PARAM;
    }
    else if (NULL_PTR == SignalGroupArrayPtr)
    {
        ErrorId = COM_E_PARAM_POINTER;
    }
#endif
    else
    {
#if(COM_RX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON)
        RxSignalGroupConfigPtr = &Com_RxSignalGroupConfig[SignalGroupId];
        #ifdef COM_ENABLE_EXTENDED_COV_CHECK
        if (COM_NUM_OF_RX_IPDU_ID >RxSignalGroupConfigPtr->ComPduId)
        #endif
        {
            if (RxSignalGroupConfigPtr->SignalGroupArrayAccess == TRUE)
            {
                ByteOffset = RxSignalGroupConfigPtr->SignalGroupArrayBufferIdx;
                if (COM_RX_SIGNAL_GROUP_RTE_ARRAY_BUFFER_SIZE >= (ByteOffset+RxSignalGroupConfigPtr->ByteLength))
                {
                    Com_EnterCriticalSection();
                    Com_UtilMemCopy(SignalGroupArrayPtr,&Com_RxSignalGroupRteArrayBuffer[ByteOffset],RxSignalGroupConfigPtr->ByteLength);
                    Com_ExitCriticalSection();
                
                    if(Com_GetRxIpduGroupActive(RxSignalGroupConfigPtr->ComPduId) == TRUE)
                    {
                        ReturnValue = E_OK;
                    }
                }
            }
        }
#endif
    }
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_RECEIVESIGNALGROUPARRAY, ErrorId);
    }
    #else
    COM_DUMMY_STATEMENT(ErrorId);
    #endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      The service Com_InvalidateSignal invalidates the signal with the given SignalId by setting its value 
*   to its configured ComSignalDataInvalidValue.
*   @param[in]  SignalId Id of signal to be invalidated..
*   @return     uint8 status of the request.
*               - E_OK: service has been accepted 
*               - COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group is stopped, no ComSignalDataInvalidValue is 
*               configured for the given signalId or service fails due to development error
*               - COM_BUSY: in case the TP-Buffer is locked for large data types handling
*   @ServiceID  0x10
*   @Sync/Async Asynchronous 
*   @Reentrancy Non Reentrant for the same signal. Reentrant for different signals.
********************************************************************************************************************/
FUNC(uint8,COM_CODE) Com_InvalidateSignal(Com_SignalIdType SignalId)
{
    /* Local Variables */
    uint8 ErrorId = COM_E_NO_ERROR;
    uint8 ReturnValue = COM_SERVICE_NOT_AVAILABLE;

    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    /* Check whether signal Id is valid */
    else if (COM_NUM_OF_TX_SIGNAL_ID <= SignalId)
    {
        ErrorId = COM_E_PARAM;
    }
#endif
    else
    {
#if(COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_ON)
        ReturnValue = Com_ProcessInvalidateSignal(SignalId);
#endif
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_INVALIDATESIGNAL, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      The service Com_InvalidateSignalGroup invalidates all group signals of the signal group with the 
*   given SignalGroupId by setting their values to their configured ComSignalDataInvalidValues.
*   @param[in]  SignalGroupId Id of signal group to be invalidated.
*   @ServiceID  0x1B
*   @Sync/Async Asynchronous 
*   @Reentrancy Non Reentrant for the same signal group. Reentrant for different signal groups.
********************************************************************************************************************/
FUNC(uint8,COM_CODE) Com_InvalidateSignalGroup(Com_SignalGroupIdType SignalGroupId)
{
    /* Local Variables */
    uint8 ErrorId = COM_E_NO_ERROR;
    uint8 ReturnValue = COM_SERVICE_NOT_AVAILABLE;
#if(COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_ON)
    P2CONST(Com_TxSignalGroupConfigType,AUTOMATIC,COM_APPL_CONST) TxSignalGroupConfigPtr;
    Com_SignalIdType Idx;
#endif
    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    /* Check whether signal Id is valid */
    else if (COM_NUM_OF_TX_SIGNAL_GROUP_ID <= SignalGroupId)
    {
        ErrorId = COM_E_PARAM;
    }
#endif
    else
    {
#if(COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_ON)
        TxSignalGroupConfigPtr = &Com_TxSignalGroupConfig[SignalGroupId];
        /* Invalid all the signals supported in the group */
        for (Idx = TxSignalGroupConfigPtr->GroupSignalIdStart; Idx<=TxSignalGroupConfigPtr->GroupSignalIdStop ;Idx++)
        {
            (void)Com_ProcessInvalidateSignal(Idx);
        }
        ReturnValue = Com_ProcessSendSignalGroup(SignalGroupId);
#endif
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_INVALIDATESIGNALGROUP, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      The service shall trigger the I-PDU with the given ID for transmission only if the I-PDU is started
*   @param[in]  PduId The I-PDU-ID of the I-PDU that shall be triggered for sending.
*   @return     Std_ReturnType status of the request.
*               - E_OK: I-PDU was triggered for transmission 
*               - E_NOT_OK: I-PDU is stopped, the transmission could not be triggered
*   @ServiceID  0x17
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType,COM_CODE) Com_TriggerIPDUSend(PduIdType PduId)
{
    Std_ReturnType ReturnValue = E_NOT_OK;
    uint8 ErrorId = COM_E_NO_ERROR;
    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    /* Check whether signal Id is valid */
    else if (COM_NUM_OF_TX_IPDU_ID <= PduId)
    {
        ErrorId = COM_E_PARAM;
    }
#endif
    else
    {
#if(COM_TX_IPDU_TRIGGER_TRANSMIT_SUPPORT == STD_ON)
        if (Com_GetTxIpduGroupActive(PduId) == TRUE)
        {
            /* set transmit status . Frame not send in this call to follow Minumum delay Time .*/ 
            Com_SetTxIpduTransmitRequest(PduId,TRUE);
            ReturnValue = E_OK;
        }
#endif
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_TRIGGERIPDUSEND, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      The service updates its internal metadata for the I-PDU with the given ID by copying the meta-data 
*   from the given position and with respect to the globally configured metadata length of the I-PDU.
*   Then the I-PDU is triggered for transmission.
*   @param[in]  PduId The I-PDU-ID of the I-PDU that shall be triggered for sending
*   @param[in]  MetaData A pointer to the metadata for the triggered send-request
*   @return     Std_ReturnType status of the request.
*               - E_OK: I-PDU was triggered for transmission 
*               - E_NOT_OK: I-PDU is stopped, the transmission could not be triggered
*   @ServiceID  0x28
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType,COM_CODE) Com_TriggerIPDUSendWithMetaData
(
    PduIdType PduId, 
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) MetaData
)
{
    Std_ReturnType ReturnValue = E_NOT_OK;
    uint8 ErrorId = COM_E_NO_ERROR;
#if((COM_TX_IPDU_TRIGGER_TRANSMIT_SUPPORT == STD_ON) && (COM_TX_IPDU_META_DATA_SUPPORT == STD_ON))
    PduLengthType Idx;
    PduLengthType ByteOffset;
    P2CONST(Com_TxIpduBufferConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduBufferConfigPtr;
#endif
    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    /* Check whether signal Id is valid */
    else if (COM_NUM_OF_TX_IPDU_ID <= PduId)
    {
        ErrorId = COM_E_PARAM;
    }
    else if (NULL_PTR == MetaData)
    {
        ErrorId = COM_E_PARAM_POINTER;
    }
#endif
    else
    {
#if((COM_TX_IPDU_TRIGGER_TRANSMIT_SUPPORT == STD_ON) && (COM_TX_IPDU_META_DATA_SUPPORT == STD_ON))
        if (Com_GetTxIpduGroupActive(PduId) == TRUE)
        {
            /* Copy the metaData */
            TxIpduBufferConfigPtr = &Com_TxIpduBufferConfig[PduId];
            ByteOffset = TxIpduBufferConfigPtr->BufferEndId + 1U;
            for(Idx = 0;Idx <TxIpduBufferConfigPtr->MetaDataLength ;Idx++)
            {
                Com_TxIpduBuffer[ByteOffset+Idx] = MetaData[Idx];
            }
            Com_SetTxIpduTransmitRequest(PduId,TRUE);
            ReturnValue = E_OK;
        }
#endif
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_TRIGGERIPDUSENDWITHMETADATA, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
    return ReturnValue;
}

/********************************************************************************************************************
*   @brief      The service Com_SwitchIpduTxMode sets the transmission mode of the I-PDU referenced by PduId to Mode. 
*   In case the transmission mode changes, the new mode shall immediately be effective . 
*   In case the requested transmission mode was already active for this I-PDU, the call will have no effect.
*   @param[in]  PduId Id of the I-PDU of which the transmission mode shall be changed
*   @param[in]  Mode the transmission mode that shall be set
*   @ServiceID  0x27
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different PduIds. Non Reentrant for the same PduId.
********************************************************************************************************************/
FUNC(void,COM_CODE) Com_SwitchIpduTxMode(PduIdType PduId, boolean Mode)
{
    Com_TxIpduTxModeType TxIpduTxMode = COM_IPDU_TX_MODE_TYPE_FALSE;
    uint8 ErrorId = COM_E_NO_ERROR;
    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    /* Check whether signal Id is valid */
    else if (COM_NUM_OF_TX_IPDU_ID <= PduId)
    {
        ErrorId = COM_E_PARAM;
    }
#endif
    else
    {
        if (Mode == TRUE)
        {
            TxIpduTxMode = COM_IPDU_TX_MODE_TYPE_TRUE;
        }
        
        if(Com_GetTxIpduTxMode(PduId) != TxIpduTxMode)
        {
            /* Update new mode */
            Com_SetTxIpduTxMode(PduId,TxIpduTxMode);
            /* Reset the mode properties */
            Com_InitTxIpduProperties(PduId,FALSE);
            /* Set the transmit request if the changed state is Direct/Mixed */
            Com_TriggerDirectTransmission(PduId,FALSE);
        }
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_SWITCHIPDUTXMODE, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
}

/********************************************************************************************************************
*                                  #!Callback Functions and Notifications                                           *
********************************************************************************************************************/
/********************************************************************************************************************
*   @brief      This service shall check whether the available data fits into the buffer size reported by 
*   PduInfoPtr->SduLength. If it fits, it shall copy its data into the buffer provided by PduInfoPtr->SduDataPtr and 
*   update the length of the actual copied data in PduInfoPtr->SduLength. If not, it returns E_NOT_OK without 
*   changing PduInfoPtr.
*   @param[in]  TxPduId ID of the SDU that is requested to be transmitted.
*   @param[in]  PduInfoPtr Contains a pointer to a buffer (SduDataPtr) to where the SDU data shall be copied, and
*               the available buffer size in SduLength. On return, the service will indicate the length of the copied
*               SDU data in SduLength.
*   @return     Std_ReturnType - status of the request.
*               - E_OK: SDU has been copied and SduLength indicates the number of copied bytes.
*               - E_NOT_OK: No SDU data has been copied. PduInfoPtr must not be used since it may contain a 
*                 NULL pointer or point to invalid data.
*   @ServiceID  0x41
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different PduIds. Non Reentrant for the same PduId.
********************************************************************************************************************/
FUNC(Std_ReturnType,COM_CODE) Com_TriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType,AUTOMATIC,COM_APPL_DATA) PduInfoPtr
)
{
    uint8 ErrorId = COM_E_NO_ERROR;
    Std_ReturnType ReturnValue = E_NOT_OK;
#if(COM_TX_IPDU_TRIGGER_TRANSMIT_SUPPORT == STD_ON)
    P2CONST(Com_TxIpduBufferConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduBufferConfigPtr;
#if(COM_TX_IPDU_TRIGGER_TRANSMIT_CALLOUT_SUPPORT == STD_ON)
    Com_TxIpduTriggerTxCalloutFunctType TxTriggerCalloutFunctPtr;
#endif
#if ((COM_TX_SIGNAL_UB_SUPPORT == STD_ON) || (COM_TX_IPDU_TRIGGER_TRANSMIT_CALLOUT_SUPPORT == STD_ON))
    P2CONST(Com_TxIpduConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduConfigPtr;
#endif
    PduInfoType PduInfo;
#endif
    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    else if (COM_NUM_OF_TX_IPDU_ID <= TxPduId)
    {
        ErrorId = COM_E_PARAM;
    }
    else if (NULL_PTR == PduInfoPtr)
    {
        ErrorId = COM_E_PARAM_POINTER;
    }
#endif
    else
    {
#if(COM_TX_IPDU_TRIGGER_TRANSMIT_SUPPORT == STD_ON)
        if (Com_GetTxIpduGroupActive(TxPduId) == TRUE)
        {
#if ((COM_TX_SIGNAL_UB_SUPPORT == STD_ON) || (COM_TX_IPDU_TRIGGER_TRANSMIT_CALLOUT_SUPPORT == STD_ON))
            TxIpduConfigPtr = &Com_TxIpduConfig[TxPduId];
#endif          
            TxIpduBufferConfigPtr = &Com_TxIpduBufferConfig[TxPduId];
            if (PduInfoPtr->SduLength <= TxIpduBufferConfigPtr->MaximumLength)
            {
                /* Check for Pdu length */
                if(PduInfoPtr->SduLength >= TxIpduBufferConfigPtr->MinimumLength)
                {
                    PduInfo.SduLength = PduInfoPtr->SduLength;
                }
                else
                {
                    PduInfo.SduLength = TxIpduBufferConfigPtr->MinimumLength;
                    PduInfoPtr->SduLength = PduInfo.SduLength;
                }
                
                if (COM_TX_IPDU_BUFFER_SIZE > TxIpduBufferConfigPtr->BufferStartId)
                {
                    PduInfo.SduDataPtr = &Com_TxIpduBuffer[TxIpduBufferConfigPtr->BufferStartId];    

                    /* Trigger Callout functions */
                    #if(COM_TX_IPDU_TRIGGER_TRANSMIT_CALLOUT_SUPPORT == STD_ON)
                    if (COM_NUM_OF_TX_IPDU_TRIGGER_TX_CALLOUT_FUNC_ID > TxIpduConfigPtr->TriggerTxCalloutFunctId)
                    {
                        TxTriggerCalloutFunctPtr =
                                        Com_TxIpduTriggerTxCalloutFunctConfig[TxIpduConfigPtr->TriggerTxCalloutFunctId];
                        if (NULL_PTR != TxTriggerCalloutFunctPtr)
                        {
                            (void)(*TxTriggerCalloutFunctPtr)(TxPduId,& PduInfo);
                        }
                    }
                    #endif
                    /* Copy the PDU buffer data  */
                    Com_UtilMemCopy(PduInfoPtr->SduDataPtr,PduInfo.SduDataPtr,PduInfo.SduLength);
                    #if(COM_TX_SIGNAL_UB_SUPPORT == STD_ON)
                    /* Clear update bits */
                    if (TxIpduConfigPtr->TxIpduClearUpdateBitType == COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_TRIGGER_TRANSMIT)
                    {
                        Com_ClearUpdateBits(TxPduId);
                    }
                    #endif
                }
            }
        }
        ReturnValue = E_OK;
#endif
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_TRIGGERTRANSMIT, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
    return ReturnValue;
}


/********************************************************************************************************************
*   @brief      The service is used to indicate of a received I-PDU from a lower layer communication interface
*   module.
*   @param[in]  RxPduId ID of the received I-PDU.
*   @param[in]  PduInfoPtr Contains the length (SduLength) of the received I-PDU and a pointer to a buffer 
*   (SduDataPtr) containing the I-PDU.
*   @ServiceID  0x42
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different PduIds. Non Reentrant for the same PduId.
********************************************************************************************************************/
FUNC(void,COM_CODE) Com_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType,AUTOMATIC,COM_APPL_CONST) PduInfoPtr)
{
    uint8 ErrorId = COM_E_NO_ERROR;

    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    else if (COM_NUM_OF_RX_IPDU_ID <= RxPduId)
    {
        ErrorId = COM_E_PARAM;
    }
    else if ((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr))
    {
        ErrorId = COM_E_PARAM_POINTER;
    }
#endif
    else
    {
        Com_RxIndicationProcessing(RxPduId, PduInfoPtr);
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_RXINDICATION, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This service shall be Called after an I-PDU has been received via the TP API, the result indicates 
*   whether the reception was successful or not.
*   @param[in]  id Identification of the received I-PDU.
*   @param[in]  result Result of the reception.
*               E_OK - Successfully received
*               E_NOT_OK - Failure in reception
*   @ServiceID  0x45
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(void,COM_CODE) Com_TpRxIndication(PduIdType id, Std_ReturnType result)
{
    uint8 ErrorId = COM_E_NO_ERROR;
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
    P2CONST(Com_RxIpduConfigType,AUTOMATIC,COM_APPL_CONST) RxIpduConfigPtr;
    P2CONST(Com_RxTpIpduConfigType,AUTOMATIC,COM_APPL_CONST) RxTpIpduConfigPtr;
    #if(COM_RX_TP_APPL_CBK_SUPPORT == STD_OFF)
    PduInfoType PduInfo;
    #endif
#endif
    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    /* Check whether signal Id is valid */
    else if (COM_NUM_OF_RX_IPDU_ID <= id)
    {
        ErrorId = COM_E_PARAM;
    }
#endif
    else
    {
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
        RxIpduConfigPtr = &Com_RxIpduConfig[id];
        if(RxIpduConfigPtr->RxTpId < COM_NUM_OF_RX_TP_IPDU_ID)  /* Coverity Fix - Com Tp*/
        {
            RxTpIpduConfigPtr = &Com_RxTpIpduConfig[RxIpduConfigPtr->RxTpId];
            if ((RxIpduConfigPtr->IpduType == COM_IPDU_TYPE_TP) && 
                (Com_GetRxIpduGroupActive(id) == TRUE) && 
                (COM_NUM_OF_RX_TP_IPDU_ID > RxIpduConfigPtr->RxTpId))
            {
                if (Com_GetRxTpIpduConnectionState(RxIpduConfigPtr->RxTpId) == COM_RXTP_CONN_STATE_WAIT_FOR_INDICATION)
                {
                    if (result == E_OK)
                    {
                        /* Rx state update for tata - pchinnat */
                        #if(COM_RX_TP_APPL_CBK_SUPPORT == STD_OFF)
                        if(RxIpduConfigPtr->IpduSignalProcessingType == COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED)
                        {
                            Com_SetRxIpduDeferredProcessing(id,TRUE);
                            Com_SetRxTpIpduConnectionState(RxIpduConfigPtr->RxTpId,
                                COM_RXTP_CONN_STATE_RECEPTION_DEFERRED_NOTIFICATION);
                            Com_RxTpIpduResetConnection(RxIpduConfigPtr->RxTpId);
                        }
                        else
                        {
                            RxTpIpduConfigPtr = &Com_RxTpIpduConfig[RxIpduConfigPtr->RxTpId];
                            PduInfo.SduLength = Com_GetRxIpduBufferLength(id);
                            PduInfo.SduDataPtr = &Com_RxTpIpduBuffer[RxTpIpduConfigPtr->BufferStartId];
                            Com_RxIndicationProcessing(id,&PduInfo);
                            Com_RxTpIpduResetConnection(RxIpduConfigPtr->RxTpId);
                        }
                        #else
                        Com_RxTpcbkFuncConfigType CbkRxTpFunctPtr;
                        CbkRxTpFunctPtr = Com_RxTpcbkFuncConfig[RxIpduConfigPtr->RxTpId];
                        if (CbkRxTpFunctPtr != NULL_PTR)
                        {
                            if(RxTpIpduConfigPtr->BufferStartId < COM_RX_TP_BUFFER_SIZE)
                            {
                                /* notify */
                                (*CbkRxTpFunctPtr)(&Com_RxTpIpduBuffer[RxTpIpduConfigPtr->BufferStartId],
                                                    Com_GetRxTpIpduBytesCopied(RxIpduConfigPtr->RxTpId));
                            }
                        }
                        Com_RxTpIpduResetConnection(RxIpduConfigPtr->RxTpId);
                        #endif   /*COM_RX_TP_APPL_CBK_SUPPORT*/
                    }
                    else
                    {
                        Com_RxTpIpduResetConnection(RxIpduConfigPtr->RxTpId);
                    }
                }
                else
                {
                    Com_RxTpIpduResetConnection(RxIpduConfigPtr->RxTpId);
                }
            }
            else
            {
                ErrorId = COM_E_PARAM;
            }
        } /* Coverity Fix - Can Tp*/
#endif
    }
    #if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_TPRXINDICATION, ErrorId);
    }
    #else
    COM_DUMMY_STATEMENT(ErrorId);
    #endif
}

/********************************************************************************************************************
*   @brief      The service is used to notify the confirmation the transmission of an I-PDU from a lower layer 
*   communication interface module.
*   @param[in]  TxPduId ID of the I-PDU that has been transmitted.
*   @param[in]  result result of Transmission.E_OK: The PDU was transmitted. E_NOT_OK: Transmission of the PDU failed. 
*   @ServiceID  0x40
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different PduIds. Non Reentrant for the same PduId.
********************************************************************************************************************/
FUNC(void,COM_CODE) Com_TxConfirmation(PduIdType TxPduId,Std_ReturnType result)
{
    /* Local Variables */
    uint8 ErrorId = COM_E_NO_ERROR;

    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    else if (COM_NUM_OF_TX_IPDU_ID <= TxPduId)
    {
        ErrorId = COM_E_PARAM;
    }
#endif
    else
    {
        if ( E_OK == result)
        {
            Com_ProcessTxConfirmation(TxPduId);
        }
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_TXCONFIRMATION, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This service is called after the I-PDU has been transmitted on its network, the result indicates 
*   whether the transmission was successful or not.
*   @param[in]  id Identification of the transmitted I-PDU.
*   @param[in]  result Result of the transmission of the I-PDU.
*               E_OK - Successfully transmitted
*               E_NOT_OK - Failure in transmission
*   @ServiceID  0x48
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(void,COM_CODE) Com_TpTxConfirmation(PduIdType id, Std_ReturnType result)
{
    uint8 ErrorId = COM_E_NO_ERROR;
#if(COM_TX_TP_IPDU_SUPPORT == STD_ON)
    P2CONST(Com_TxIpduConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduConfigPtr;
#endif
    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    else if (COM_NUM_OF_TX_IPDU_ID <= id)
    {
        ErrorId = COM_E_PARAM;
    }
#endif
    else
    {
#if(COM_TX_TP_IPDU_SUPPORT == STD_ON)
        TxIpduConfigPtr = &Com_TxIpduConfig[id];
        if (TxIpduConfigPtr->IpduType == COM_IPDU_TYPE_TP)
        {
            if (COM_NUM_OF_TX_TP_IPDU_ID > TxIpduConfigPtr->TpConfigId)
            {
                /* Check for valid status and Tp connection state */
                if ((result == E_OK) &&
                    (Com_TxTpIpduBufferState[TxIpduConfigPtr->TpConfigId] == COM_TXTP_CONN_STATE_WAIT_FOR_CONFIRMATION))
                {
                    /* Process Confirmation */
                    Com_ProcessTxConfirmation(id);
                }
                /* Reset Connection */
                Com_TxTpIpduResetConnection(TxIpduConfigPtr->TpConfigId);
            }
        }
        #if (COM_DEV_ERROR_DETECT == STD_ON)
        else
        {
            ErrorId = COM_E_PARAM;
        }
        #endif
#endif
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_TPTXCONFIRMATION, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
    
}

/********************************************************************************************************************
*   @brief      This service is called at the start of receiving an N-SDU. The N-SDU might be fragmented into  
*   multiple N-PDUs (FF with one or more following CFs) or might consist of a single N-PDU (SF).
*   @param[in]  id Identification of the I-PDU.
*   @param[in]  info Pointer to a PduInfoType structure containing the payload data (without protocol information)  
*   and payload length of the first frame or single frame of a transport protocol I-PDU reception. Depending on the 
*   global parameter MetaDataLength, additional bytes containing MetaData (e.g. the CAN ID) are appended after the  
*   payload data, increasing the length accordingly. If neither first/single frame data nor MetaData are available, 
*   this parameter is set to NULL_PTR.
*   @param[in]  TpSduLength Total length of the N-SDU to be received.
*   @param[out] bufferSizePtr Available receive buffer in the receiving module. This para-meter will be used to 
*   compute the Block Size (BS) in the transport protocol module.
*   @return BufReq_ReturnType status of the request.
*           - BUFREQ_OK: Connection has been accepted. bufferSizePtr indicates the available receive buffer; 
*             reception is continued. If no buffer of the requested size is available, a receive buffer size of 0  
*             shall be indicated by bufferSizePtr. 
*           - BUFREQ_E_NOT_OK: Connection has been rejected; reception is aborted. bufferSizePtr remains unchanged. 
*           - BUFREQ_E_OVFL: No buffer of the required length can be provided; reception is aborted. bufferSizePtr 
*           remains unchanged.
*   @ServiceID  0x46
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(BufReq_ReturnType,COM_CODE) Com_StartOfReception
(
    PduIdType id, 
    P2CONST(PduInfoType,AUTOMATIC,COM_APPL_CONST) info, 
    PduLengthType TpSduLength, 
    P2VAR(PduLengthType,AUTOMATIC,COM_APPL_DATA) bufferSizePtr
)
{
    uint8 ErrorId = COM_E_NO_ERROR;
    BufReq_ReturnType BufferStatus = BUFREQ_E_NOT_OK;
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
    P2CONST(Com_RxIpduConfigType,AUTOMATIC,COM_APPL_CONST) RxIpduConfigPtr;
    P2CONST(Com_RxTpIpduConfigType,AUTOMATIC,COM_APPL_CONST) RxTpIpduConfigPtr;
#endif
    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    /* Check whether signal Id is valid */
    else if (COM_NUM_OF_RX_IPDU_ID <= id)
    {
        ErrorId = COM_E_PARAM;
    }
    else if (NULL_PTR == bufferSizePtr)
    {
        ErrorId = COM_E_PARAM_POINTER;
    }
#endif
    else
    {
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
        RxIpduConfigPtr = &Com_RxIpduConfig[id];
        if ((RxIpduConfigPtr->IpduType == COM_IPDU_TYPE_TP) && 
            (Com_GetRxIpduGroupActive(id) == TRUE) && 
            (COM_NUM_OF_RX_TP_IPDU_ID > RxIpduConfigPtr->RxTpId))
        {
            if (Com_GetRxTpIpduConnectionState(RxIpduConfigPtr->RxTpId) == COM_RXTP_CONN_STATE_IDLE)
            {
                RxTpIpduConfigPtr = &Com_RxTpIpduConfig[RxIpduConfigPtr->RxTpId];
                /* check for length */
                *bufferSizePtr = RxTpIpduConfigPtr->MaximumLength;
                if (RxTpIpduConfigPtr->MaximumLength >= TpSduLength)
                {
                    Com_SetRxIpduBufferLength(id,TpSduLength);
                    Com_SetRxTpIpduBytesCopied(RxIpduConfigPtr->RxTpId,0U);
                    if (TpSduLength!=0U)
                    {
                        Com_SetRxTpIpduConnectionState(RxIpduConfigPtr->RxTpId,
                                                            COM_RXTP_CONN_STATE_RECEPTION_COPYDATA);
                    }
                    else
                    {
                        Com_SetRxTpIpduConnectionState(RxIpduConfigPtr->RxTpId,
                                                            COM_RXTP_CONN_STATE_WAIT_FOR_INDICATION);
                    }
                    BufferStatus = BUFREQ_OK;
                }
                else
                {
                    BufferStatus = BUFREQ_E_OVFL;
                }
            }
            else if (Com_GetRxTpIpduConnectionState(RxIpduConfigPtr->RxTpId) == 
                                        COM_RXTP_CONN_STATE_RECEPTION_DEFERRED_NOTIFICATION)
            {
                /* wait for deferrred notification */
                BufferStatus = BUFREQ_E_NOT_OK;
            }
            else
            {
                BufferStatus = BUFREQ_E_NOT_OK;
                Com_RxTpIpduResetConnection(RxIpduConfigPtr->RxTpId);
            }
        }
#endif
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_STARTOFRECEPTION, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
    COM_DUMMY_STATEMENT(info);
    return BufferStatus;
}

/********************************************************************************************************************
*   @brief      This service is called to provide the received data of an I-PDU segment (N-PDU) to the upper layer. 
*   Each call to this function provides the next part of the I-PDU data. The size of the remaining data is written to
*   the position indicated by bufferSizePtr.
*   @param[in]  id Identification of the received I-PDU
*   @param[in]  info Provides the source buffer (SduDataPtr) and the number of bytes to be copied (SduLength).
*   An SduLength of 0 can be used to query the current amount of available buffer in the upper layer module. 
*   In this case, the SduDataPtr may be a NULL_PTR..
*   @param[out] bufferSizePtr Available receive buffer after data has been copied.
*   @return BufReq_ReturnType status of the request.
*           - BUFREQ_OK: Data copied successfully 
*           - BUFREQ_E_NOT_OK: Data was not copied because an error occurred.
*   @ServiceID  0x44
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(BufReq_ReturnType,COM_CODE) Com_CopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,COM_APPL_CONST) info,
    P2VAR(PduLengthType,AUTOMATIC,COM_APPL_DATA) bufferSizePtr
)
{
    uint8 ErrorId = COM_E_NO_ERROR;
    BufReq_ReturnType BufferStatus = BUFREQ_E_NOT_OK;
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
    P2CONST(Com_RxIpduConfigType,AUTOMATIC,COM_APPL_CONST) RxIpduConfigPtr;
    P2CONST(Com_RxTpIpduConfigType,AUTOMATIC,COM_APPL_CONST) RxTpIpduConfigPtr;
    PduLengthType NumOfBytesCopied;
    PduLengthType RemainingBuffer;
#endif
    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    /* Check whether signal Id is valid */
    else if (COM_NUM_OF_RX_IPDU_ID <= id)
    {
        ErrorId = COM_E_PARAM;
    }
    else if ((NULL_PTR == info) || (bufferSizePtr == NULL_PTR) ||
             ((info->SduLength > 0U) && (info->SduDataPtr == NULL_PTR)))
    {
        ErrorId = COM_E_PARAM_POINTER;
    }
#endif
    else
    {
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
        RxIpduConfigPtr = &Com_RxIpduConfig[id];
        if ((RxIpduConfigPtr->IpduType == COM_IPDU_TYPE_TP) && 
            (Com_GetRxIpduGroupActive(id) == TRUE) && 
            (COM_NUM_OF_RX_TP_IPDU_ID > RxIpduConfigPtr->RxTpId))
        {
            if (Com_GetRxTpIpduConnectionState(RxIpduConfigPtr->RxTpId) == COM_RXTP_CONN_STATE_RECEPTION_COPYDATA)
            {
                RxTpIpduConfigPtr = &Com_RxTpIpduConfig[RxIpduConfigPtr->RxTpId];
                NumOfBytesCopied = Com_GetRxTpIpduBytesCopied(RxIpduConfigPtr->RxTpId);
                RemainingBuffer = RxTpIpduConfigPtr->MaximumLength-NumOfBytesCopied;
                if (info->SduLength > 0U)
                {
                    if (RemainingBuffer >= info->SduLength)
                    {
                        /* Copy Data */
                        Com_UtilMemCopy(&Com_RxTpIpduBuffer[RxTpIpduConfigPtr->BufferStartId+NumOfBytesCopied],
                                        info->SduDataPtr,info->SduLength);
                        NumOfBytesCopied+=info->SduLength;
                        * bufferSizePtr =  RxTpIpduConfigPtr->MaximumLength-NumOfBytesCopied;
                        Com_SetRxTpIpduBytesCopied(RxIpduConfigPtr->RxTpId,NumOfBytesCopied);
                        if (Com_GetRxIpduBufferLength(id) == NumOfBytesCopied)
                        {
                            /* all data copied , wait for Indication */
                            Com_SetRxTpIpduConnectionState(RxIpduConfigPtr->RxTpId,
                                                            COM_RXTP_CONN_STATE_WAIT_FOR_INDICATION);
                        }
                    }
                }
                else
                {
                    /* set the remaing length available */
                    * bufferSizePtr = RemainingBuffer;
                }
                BufferStatus = BUFREQ_OK;
            }
            else if (Com_GetRxTpIpduConnectionState(RxIpduConfigPtr->RxTpId) == 
                                                COM_RXTP_CONN_STATE_RECEPTION_DEFERRED_NOTIFICATION)
            {
                if(info->SduLength == 0u)
                {
                    *bufferSizePtr = 0u;
                    BufferStatus = BUFREQ_OK;
                }
                else
                {
                    Com_RxTpIpduResetConnection(RxIpduConfigPtr->RxTpId);
                }
            }
            else
            {
                
            }
        }
#endif
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_COPYRXDATA, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
    return BufferStatus;
}

/********************************************************************************************************************
*   @brief      This function is called to acquire the transmit data of an I-PDU segment (N-PDU). Each call to this 
*   function provides the next part of the I-PDU data unless retry->TpDataState is TP_DATARETRY. In this case the 
*   function restarts to copy the data beginning at the offset from the current position indicated by 
*   retry->TxTpDataCnt. The size of the remaining data is written to the position indicated by availableDataPtr.
*   @param[in]  id Identification of the transmitted I-PDU
*   @param[in]  info Provides the destination buffer (SduDataPtr) and the number of bytes to be copied (SduLength).
*   If not enough transmit data is available, no data is copied by the upper layer module and BUFREQ_E_BUSY is 
*   returned. The lower layer module may retry the call. An SduLength of 0 can be used to indicate state changes 
*   in the retry parameter or to query the current amount of available data in the upper layer module. 
*   In this case, the SduDataPtr may be a NULL_PTR.
*   @param[in]  retry This parameter is used to acknowledge transmitted data or to re transmit data after 
*   transmission problems.If the retry parameter is a NULL_PTR, it indicates that the transmit data can be removed 
*   from the buffer immediately after it has been copied. Otherwise, the retry parameter must point to a valid 
*   RetryInfoType element. 
*   - TP_CONFPENDING, the previously copied data must remain in the TP buffer to be available for error recovery.
*   - TP_DATACONF indicates that all data that has been copied before this call is confirmed and can be removed from 
*   the TP buffer. Data copied by this API call is excluded and will be confirmed later. 
*   - TP_DATARETRY indicates that this API call shall copy previously copied data in order to recover from an error.
*   In this case TxTpDataCnt specifies the offset in bytes from the current data copy position.
*   @param[out] availableDataPtr Indicates the remaining number of bytes that are available in the upper layer  
*   module's Tx buffer. availableDataPtr can be used by TP modules that support dynamic payload lengths 
*   (e.g. FrIsoTp) to determine the size of the following CFs
*   @return BufReq_ReturnType status of the request.
*           - BUFREQ_OK: Data has been copied to the transmit buffer completely as requested. 
*           - BUFREQ_E_BUSY: Request could not be fulfilled, because the required amount of Tx data is not available.
*             The lower layer module may retry this call later on. No data has been copied. 
*           - BUFREQ_E_NOT_OK: Data has not been copied. Request failed.
*   @ServiceID  0x43
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(BufReq_ReturnType,COM_CODE) Com_CopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,COM_APPL_CONST)   info,
    P2CONST(RetryInfoType,AUTOMATIC,COM_APPL_CONST) retry, 
    P2VAR(PduLengthType,AUTOMATIC,COM_APPL_DATA)    availableDataPtr
)
{
    uint8 ErrorId = COM_E_NO_ERROR;
    BufReq_ReturnType BufferStatus = BUFREQ_E_NOT_OK;
#if(COM_TX_TP_IPDU_SUPPORT == STD_ON)
    P2CONST(Com_TxIpduConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduConfigPtr;
    P2CONST(Com_TxTpIpduBufferConfigType,AUTOMATIC,COM_APPL_CONST) TxTpIpduBufferConfigPtr;
    PduLengthType RemainingBytes;
    PduLengthType CurrenPostition;
#endif
    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    else if (COM_NUM_OF_TX_IPDU_ID <= id)
    {
        ErrorId = COM_E_PARAM;
    }
#endif
    else if((info == NULL_PTR) || ((info->SduDataPtr == NULL_PTR) && (info->SduLength > 0u)) || 
            (availableDataPtr == NULL_PTR))
    {
        ErrorId = COM_E_PARAM_POINTER;
    }
    else
    {
#if(COM_TX_TP_IPDU_SUPPORT == STD_ON)
        if(Com_GetTxIpduGroupActive(id) == TRUE)
        {
            TxIpduConfigPtr = &Com_TxIpduConfig[id];
            if(TxIpduConfigPtr->TpConfigId < COM_NUM_OF_TX_TP_IPDU_ID)  /* Coverity Fix - Com Tp*/
            {
                TxTpIpduBufferConfigPtr = &Com_TxTpIpduBufferConfig[TxIpduConfigPtr->TpConfigId];
            
                if((retry == NULL_PTR) || (retry->TpDataState != TP_DATARETRY))
                {
                    if(COM_TXTP_CONN_STATE_TRANSMIT_REQUEST == Com_TxTpIpduBufferState[TxIpduConfigPtr->TpConfigId])
                    {
                        Com_TxTpIpduBufferState[TxIpduConfigPtr->TpConfigId] = COM_TXTP_CONN_STATE_TRANSMIT_COPYDATA;
                    }
                    if(Com_TxTpIpduBufferState[TxIpduConfigPtr->TpConfigId] == COM_TXTP_CONN_STATE_TRANSMIT_COPYDATA)
                    {
                        CurrenPostition = TxTpIpduBufferConfigPtr->BufferStartId+Com_TxTpIpduCurrentPosition[TxIpduConfigPtr->TpConfigId];
                        RemainingBytes =  (TxTpIpduBufferConfigPtr->BufferStartId + Com_GetTxIpduBufferLength(id)) - CurrenPostition;
                        *availableDataPtr = RemainingBytes;
                        if(info->SduLength <= RemainingBytes)
                        {
                            /* Copy data */
                            Com_UtilMemCopy(info->SduDataPtr, &Com_TxTpIpduBuffer[CurrenPostition],info->SduLength);
                            Com_TxTpIpduCurrentPosition[TxIpduConfigPtr->TpConfigId] +=info->SduLength;
                        
                            /* All data copied change , then set state to Wait for confirmation*/ 
                            if (*availableDataPtr == 0U)
                            {
                                Com_TxTpIpduBufferState[TxIpduConfigPtr->TpConfigId] = COM_TXTP_CONN_STATE_WAIT_FOR_CONFIRMATION;
                            }
                            BufferStatus = BUFREQ_OK;
                        }
                        else
                        {
                            BufferStatus = BUFREQ_E_BUSY;
                        }
                    }
                    else if(Com_TxTpIpduBufferState[TxIpduConfigPtr->TpConfigId] == COM_TXTP_CONN_STATE_WAIT_FOR_CONFIRMATION)
                    {
                        if (info->SduLength == 0)
                        {
                            *availableDataPtr = 0U;
                            BufferStatus = BUFREQ_OK;
                        }
                        else
                        {
                            /* Reset Connection */
                            Com_TxTpIpduResetConnection(TxIpduConfigPtr->TpConfigId);
                        }
                    }
                    else
                    {
                    }
                }
            } /* Coverity Fix - Com Tp*/
        }
#endif
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_COPYTXDATA, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
    return BufferStatus;
}

/********************************************************************************************************************
*                                  #!Scheduled Functions                                                            *
********************************************************************************************************************/
/********************************************************************************************************************
*   @brief   This service performs the processing of the AUTOSAR COM module's receive processing that are not
*   directly handled within the COM's functions invoked by the PDU-R,for example Com_RxIndication.
*   @ServiceID  0x18
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
*   TODO :  move timeout handling to inline funcion , implement COM_RX_DATA_TIMEOUT_ACTION_TYPE_SUBSTITUTE
********************************************************************************************************************/
FUNC(void,COM_CODE) Com_MainFunctionRx(void)
{
    PduIdType RxPduIdx;
    uint8 ErrorId = COM_E_NO_ERROR;
#if((COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT == STD_ON) || (COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON) || \
    (COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON))
    P2CONST(Com_RxIpduConfigType,AUTOMATIC,COM_APPL_CONST) RxIpduConfigPtr;
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr;
#endif
#if((COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT == STD_ON) || (COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON))
    Com_SignalIdType SigIdx;
#endif
#if(COM_RX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT == STD_ON)
    Com_CbkRxToutFunctType CbkRxToutFunctPtr;
#endif
#if(COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON)
    P2CONST(Com_RxSigTimeoutCounterConfigType,AUTOMATIC,COM_APPL_CONST) RxSigTimeoutCounterConfigPtr;
    Com_RxSigToutIdType RxSigToutId;
#endif
#if(COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON)
    P2CONST(Com_RxSigGroupTimeoutCounterConfigType,AUTOMATIC,COM_APPL_CONST) RxSigGroupTimeoutCounterConfigPtr;
    P2CONST(Com_RxSignalGroupConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalGroupConfigPtr;
#endif
#if (COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON)
    Com_RxSigGroupToutIdType RxSigGroupToutId;
#endif
    /* Check whether module is Initialized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
    else
    {
        for (RxPduIdx = 0U;RxPduIdx<COM_NUM_OF_RX_IPDU_ID ;RxPduIdx++)
        {
            /* Process Differed Notification */
            if(Com_GetRxIpduDeferredProcessing(RxPduIdx) == TRUE)
            {
                Com_RxIpduProcessing(RxPduIdx);
                Com_SetRxIpduDeferredProcessing(RxPduIdx,FALSE);
            }
#if((COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT == STD_ON) || (COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON) || \
    (COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON))
            RxIpduConfigPtr = &Com_RxIpduConfig[RxPduIdx];
#endif
#if(COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT == STD_ON)
            if (COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID > RxIpduConfigPtr->IpduTimeoutCounterId)
            {
                if (Com_RxIpduDeadlineCounter[RxIpduConfigPtr->IpduTimeoutCounterId] > 0U)
                {
                    Com_RxIpduDeadlineCounter[RxIpduConfigPtr->IpduTimeoutCounterId]--;
                    if (Com_RxIpduDeadlineCounter[RxIpduConfigPtr->IpduTimeoutCounterId] == 0U)
                    {
                        /* Timeout occurred TODO Update Timeout action for signals/Signal groups*/
                        for(SigIdx =RxIpduConfigPtr->SignalStartId;SigIdx<=RxIpduConfigPtr->SignalEndId; SigIdx++)
                        {
                            RxSignalConfigPtr = &Com_RxSignalConfig[SigIdx];
#if(COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON)
                            if (COM_NUM_OF_RX_SIGNAL_TIMEOUT_COUNTER_ID == RxSignalConfigPtr->RxSignalTimeoutCounterId )
#endif
                            {
                                /* Update Initial value if the timeout action is replace */
                                if( COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE == RxSignalConfigPtr->RxDataTimeoutActionType)
                                {
                                    Com_SetRxSignalInitValue(RxSignalConfigPtr);

                                }
#if(COM_RX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT == STD_ON)
                                if(COM_NUM_OF_RX_TOUT_FUNCT_ID > RxSignalConfigPtr->RxToutFunctId )
                                {
                                    CbkRxToutFunctPtr = Com_CbkRxToutFunctConfig[RxSignalConfigPtr->RxToutFunctId];
                                    if(CbkRxToutFunctPtr != NULL_PTR)
                                    {
                                        (*CbkRxToutFunctPtr)();
                                    }
                                }
#endif
                            }
                        }
                    }
                }
            }
#endif
#if(COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON)
            if(COM_NUM_OF_RX_SIGNAL_TIMEOUT_COUNTER_ID > RxIpduConfigPtr->SigTimeoutCounterStartId)
            {
                for(RxSigToutId = RxIpduConfigPtr->SigTimeoutCounterStartId;
                    ((RxSigToutId <= RxIpduConfigPtr->SigTimeoutCounterEndId) && 
                    (COM_NUM_OF_RX_SIGNAL_TIMEOUT_COUNTER_ID > RxSigToutId));RxSigToutId++)
                {
                    if (Com_RxSigDeadlineCounter[RxSigToutId] >0)
                    {
                        Com_RxSigDeadlineCounter[RxSigToutId]--;
                        if(Com_RxSigDeadlineCounter[RxSigToutId] == 0U)
                        {
                            RxSigTimeoutCounterConfigPtr = &Com_RxSigTimeoutCounterConfig[RxSigToutId];
                            if (COM_NUM_OF_RX_SIGNAL_ID > RxSigTimeoutCounterConfigPtr->SignalId)
                            {
                                RxSignalConfigPtr = &Com_RxSignalConfig[RxSigTimeoutCounterConfigPtr->SignalId];
                                /* Update Initial value if the timeout action is replace */
                                if( COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE == RxSignalConfigPtr->RxDataTimeoutActionType)
                                {
                                    Com_SetRxSignalInitValue(RxSignalConfigPtr);
                                }
#if(COM_RX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT == STD_ON)
                                if(COM_NUM_OF_RX_TOUT_FUNCT_ID > RxSignalConfigPtr->RxToutFunctId )
                                {
                                    CbkRxToutFunctPtr = Com_CbkRxToutFunctConfig[RxSignalConfigPtr->RxToutFunctId];
                                    if(CbkRxToutFunctPtr != NULL_PTR)
                                    {
                                        (*CbkRxToutFunctPtr)();
                                    }
                                }
                            }   
#endif
                        }
                    }
                }
            }
#endif
#if(COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON)
            if(COM_NUM_OF_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_ID > RxIpduConfigPtr->SigGroupTimeoutCounterStartId)
            {
                for(RxSigGroupToutId = RxIpduConfigPtr->SigGroupTimeoutCounterStartId;
                    ((RxSigGroupToutId <= RxIpduConfigPtr->SigGroupTimeoutCounterEndId) &&
                    (COM_NUM_OF_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_ID > RxSigGroupToutId));RxSigGroupToutId++)
                {
                    if (Com_RxSigGroupDeadlineCounter[RxSigGroupToutId] >0)
                    {
                        Com_RxSigGroupDeadlineCounter[RxSigGroupToutId]--;
                        if(Com_RxSigGroupDeadlineCounter[RxSigGroupToutId] == 0U)
                        {
                            RxSigGroupTimeoutCounterConfigPtr = &Com_RxSigGroupTimeoutCounterConfig[RxSigGroupToutId];
                            if ( COM_NUM_OF_RX_SIGNAL_GROUP_ID > RxSigGroupTimeoutCounterConfigPtr->SignalGroupId )
                            {
                                RxSignalGroupConfigPtr = &Com_RxSignalGroupConfig[RxSigGroupTimeoutCounterConfigPtr->SignalGroupId];
                                /* Update Initial value if the timeout action is replace */
                                if (COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE == RxSignalGroupConfigPtr->RxDataTimeoutActionType)
                                {
                                    for(SigIdx = RxSignalGroupConfigPtr->GroupSignalStartId;SigIdx <= RxSignalGroupConfigPtr->GroupSignalEndId;SigIdx++)
                                    {
                                        RxSignalConfigPtr = &Com_RxSignalConfig[SigIdx];
                                        Com_SetRxSignalInitValue(RxSignalConfigPtr);
                                    }
                                }
#if(COM_RX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT == STD_ON)
                                if(COM_NUM_OF_RX_TOUT_FUNCT_ID > RxSignalGroupConfigPtr->RxToutFunctId )
                                {
                                    CbkRxToutFunctPtr = Com_CbkRxToutFunctConfig[RxSignalGroupConfigPtr->RxToutFunctId];
                                    if(CbkRxToutFunctPtr != NULL_PTR)
                                    {
                                        (*CbkRxToutFunctPtr)();
                                    }
                                }
#endif
                            }
                        }
                    }
                }
            }
#endif
        }
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_MAINFUNCTIONRX, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This service performs the processing of the AUTOSAR COM module's transmission activities that are 
*   not directly handled within the COM's function invoked by the RTE, for example Com_SendSignal.
*   @ServiceID  0x19
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(void,COM_CODE) Com_MainFunctionTx(void)
{
    /* Local Variables */
    uint8 ErrorId = COM_E_NO_ERROR;
    PduIdType Idx;

    /* Check whether module is Initilized */
    if (COM_UNINIT == COM_InitStatus)
    {
        ErrorId = COM_E_UNINIT;
    }
    else
    {
        #if (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON)
        /* Deadling processing */
        Com_ProcessDeadlineMoitoring();
        #endif
        /* Process the Ipdu transmit request */
        Com_ProcessTransmitRequest();
        /* Process the Deffered Confirmation */
        for(Idx = 0;Idx<COM_NUM_OF_TX_IPDU_ID;Idx++)
        {
            if(Com_GetTxIpduDefferedNotification(Idx) == TRUE)
            {
                Com_ProcessConfirmationNotification(Idx);
                Com_SetTxIpduDefferedNotification(Idx,FALSE);
            }
        }
    }
#if (COM_DEV_ERROR_DETECT == STD_ON)
    if (ErrorId != COM_E_NO_ERROR)
    {
        Com_DetReportError(COM_SID_MAINFUNCTIONTX, ErrorId);
    }
#else
    COM_DUMMY_STATEMENT(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      This service performs signal gateway part of the AUTOSAR COM module to forward received signals to 
*   be routed.
*   @ServiceID  0x1A
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(void,COM_CODE) Com_MainFunctionRouteSignals(void)
{
    /*! TODO : Gateway feature support  */
}

/********************************************************************************************************************
*                                  #!Private Function Implementation                                                *
********************************************************************************************************************/
/* Private function implementation */
/********************************************************************************************************************
*   Service Name     : Com_InitTxIpdu
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_InitTxIpdu(void)
{
    PduIdType TxIpduId;
#if (COM_TX_PDU_NO_GROUP_SUPPORT == STD_ON)
    P2CONST(Com_TxIpduConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduConfigPtr;
#endif
    
    for (TxIpduId = 0; TxIpduId < COM_NUM_OF_TX_IPDU_ID; TxIpduId++)
    {
        /* Init the Ipdu buffer , shadow buffer */
        Com_InitTxIpduBuffer(TxIpduId);
        /* initialize Com Ipdu properties */
        Com_InitTxIpduProperties(TxIpduId,TRUE);
        #if (COM_TX_PDU_NO_GROUP_SUPPORT == STD_ON)
        TxIpduConfigPtr = &Com_TxIpduConfig[TxIpduId];
        if (FALSE != TxIpduConfigPtr->NoIpduGroupSupported)
        {
            /* Set the pduGroupActive to FALSE */
            Com_SetTxIpduGroupActive(TxIpduId,TRUE);
        }
        #endif
        {
            /* Set the pduGroupActive to FALSE */
            Com_SetTxIpduGroupActive(TxIpduId,FALSE);
        }
    }
    
#if (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON)
    /* Initialize Deadline Monitoring */
    Com_InitTxDeadlineMonitoring();
#endif
    
}

#if (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/********************************************************************************************************************
*   Service Name     : Com_InitTxDeadlineMonitoring
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_InitTxDeadlineMonitoring(void)
{
    Com_TxIpduToutIdType Idx;
    for(Idx = 0; Idx<COM_NUM_OF_TX_IPDU_TIMEOUT_COUNTER_ID ; Idx++)
    {
        Com_SetTxIpduTxTimeoutCount(Idx,0U);
    }
}
#endif

/********************************************************************************************************************
*   Service Name     : Com_InitTxIpduProperties
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_InitTxIpduProperties(PduIdType TxIpduId , boolean IsInitTxMode)
{
#if(COM_TX_TP_IPDU_SUPPORT == STD_ON)
    P2CONST(Com_TxIpduConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduConfigPtr;
#endif
    if(COM_NUM_OF_TX_IPDU_ID > TxIpduId)
    {
#if (COM_TX_TP_IPDU_SUPPORT == STD_ON)
        TxIpduConfigPtr = &Com_TxIpduConfig[TxIpduId];
        /* Reset Tp Connection */
        if (COM_IPDU_TYPE_TP == TxIpduConfigPtr->IpduType)
        {
            Com_TxTpIpduResetConnection(TxIpduId);
        }
#endif
        if(FALSE != IsInitTxMode)
        {
            Com_SetTxIpduTxMode(TxIpduId,COM_IPDU_TX_MODE_TYPE_TRUE);
        }

        /* Initilaize TxIPdu properties*/
        Com_InitTxIpduTxModeProperties(TxIpduId);
        /* Initialize Deffered handle and wait for confirmation */
        Com_SetTxIpduConfirmationWait(TxIpduId,FALSE);
        Com_SetTxIpduDefferedNotification(TxIpduId,FALSE);
    }
}

/********************************************************************************************************************
*   Service Name     : Com_InitTxIpduTxModeProperties
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_InitTxIpduTxModeProperties(PduIdType TxIpduId)
{
    P2CONST(Com_TxIpduConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduConfigPtr;
    P2CONST(Com_TxIpduTxModeConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduTxModeConfigPtr;

    if(COM_NUM_OF_TX_IPDU_ID > TxIpduId)
    {
        TxIpduConfigPtr = &Com_TxIpduConfig[TxIpduId];
        /* Get the Mode configuration */
        if (Com_GetTxIpduTxMode(TxIpduId) == COM_IPDU_TX_MODE_TYPE_TRUE)
        {
            TxIpduTxModeConfigPtr = &Com_TxIpduTxModeTrueConfig[TxIpduId];
        }
        else
        {
            TxIpduTxModeConfigPtr = &Com_TxIpduTxModeFalseConfig[TxIpduId];
        }
        #if (COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION == STD_ON)
        /* SWS_Com_00787 1) ComMinimumDelayTime of I-PDUs in transmission mode DIRECT or MIXED */
        if ((COM_TX_MODE_MODE_TYPE_MIXED == TxIpduTxModeConfigPtr->TxModeModeType) ||
            (COM_TX_MODE_MODE_TYPE_DIRECT == TxIpduTxModeConfigPtr->TxModeModeType))
        {
            Com_SetTxIpduMinimumDelay(TxIpduId,TxIpduConfigPtr->MinimumDelayTime);
        }
        #endif

        if (TRUE == Com_IsTxIpduModeTypePeriodic(TxIpduTxModeConfigPtr->TxModeModeType) )
        {
            /* set periodic counter to TimeOffset */
            if (TxIpduTxModeConfigPtr->TimeOffset != 0U)
            {
                Com_SetTxIpduPeriod(TxIpduId,TxIpduTxModeConfigPtr->TimeOffset);
            }
            else
            {
                Com_SetTxIpduPeriod(TxIpduId,1U);
            }
            /* set the tansmit request and the cyclic transmit request */
            Com_SetTxIpduPeriodicTransmitRequest(TxIpduId,TRUE);
            Com_SetTxIpduTransmitRequest(TxIpduId,TRUE);
        }
        else
        {
            /* set the tansmit request and the cyclic transmit request */
            Com_SetTxIpduPeriodicTransmitRequest(TxIpduId,FALSE);
            Com_SetTxIpduTransmitRequest(TxIpduId,FALSE);
        }
        /* Set the Reptioion counter & periodicity to zero , on new request the 
           repetition count and period will be updated */
        Com_SetTxIpduRepetitionCount(TxIpduId,0U);
        Com_SetTxIpduRepetitionPeriod(TxIpduId,0U);
        #if (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON)
        /* Reset the TimeoutCounter due to change in the current mode as none */
        if (COM_NUM_OF_TX_IPDU_TIMEOUT_COUNTER_ID > TxIpduConfigPtr->TxTimeoutCounterId)
        {
            Com_SetTxIpduTxTimeoutCount(TxIpduConfigPtr->TxTimeoutCounterId,TxIpduConfigPtr->FirstTimeout);
        }
        #endif
    }
}

#if(COM_TX_TP_IPDU_SUPPORT == STD_ON)
/********************************************************************************************************************
*   Service Name     : Com_TxTpIpduResetConnection
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_TxTpIpduResetConnection(PduIdType TxTpIpduId)
{
    /* Reset connection properties */
    if(COM_NUM_OF_TX_TP_IPDU_ID > TxTpIpduId)
    {
        Com_TxTpIpduBufferState[TxTpIpduId] = COM_TXTP_CONN_STATE_IDLE;
        Com_TxTpIpduCurrentPosition[TxTpIpduId]=0U;
    }
}
#endif

/********************************************************************************************************************
*   Service Name     : Com_TxActivateTxIPdu
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_ActivateTxIpdu(PduIdType TxIpduId , boolean Initialize)
{
    if(COM_NUM_OF_TX_IPDU_ID > TxIpduId)
    {
        if (FALSE != Initialize)
        {
            Com_InitTxIpduBuffer(TxIpduId);
        }
        /* Initialize buffers and the tx properties */
        Com_InitTxIpduProperties(TxIpduId,Initialize);       
        
#if(COM_TX_SIGNAL_UB_SUPPORT == STD_ON)
        /*  SWS_Com_00787 4. all included update-bits shall be cleared */
        Com_ClearUpdateBits(TxIpduId);
#endif
        /*  \TODO SWS_Com_00787 5. reset OCCURRENCE of filters with ComFilterAlgorithm ONE_EVERY_N */
        /*  \TODO SWS_Com_00787 6. set the I-PDU counter to 0 for I-PDUs with ComIPduDirection configured to SEND */
        /* set the pduGroup active to True*/
        Com_SetTxIpduGroupActive(TxIpduId,TRUE);
    }
}

/********************************************************************************************************************
*   Service Name     : Com_DeactivateTxIpdu
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_DeactivateTxIpdu(PduIdType TxIpduId)
{
#if((COM_TX_TP_IPDU_SUPPORT == STD_ON) || (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON))
    P2CONST(Com_TxIpduConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduConfigPtr;
#endif
    if(COM_NUM_OF_TX_IPDU_ID > TxIpduId)
    {
        /* Clear all TxIpdu flags */
        Com_SetTxIpduPeriodicTransmitRequest(TxIpduId,FALSE);
        Com_SetTxIpduConfirmationWait(TxIpduId,FALSE);
        Com_SetTxIpduDefferedNotification(TxIpduId,FALSE);
        Com_SetTxIpduTransmitRequest(TxIpduId,FALSE);
        
        /* Reset all TxIpdu Counters */
        Com_SetTxIpduRepetitionCount(TxIpduId,0U);
        Com_SetTxIpduRepetitionPeriod(TxIpduId,0U);
        Com_SetTxIpduPeriod(TxIpduId,0U);
        Com_SetTxIpduMinimumDelay(TxIpduId,0U);
        Com_SetTxIpduMinimumDelay(TxIpduId,0U);
#if((COM_TX_TP_IPDU_SUPPORT == STD_ON) || (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON))
        TxIpduConfigPtr = &Com_TxIpduConfig[TxIpduId];
#endif
#if (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON)
        /* Reset the deadline monitor */
        if (COM_NUM_OF_TX_IPDU_TIMEOUT_COUNTER_ID > TxIpduConfigPtr->TxTimeoutCounterId)
        {
            Com_SetTxIpduTxTimeoutCount(TxIpduConfigPtr->TxTimeoutCounterId,0U);
        }
#endif
        /* Reset Tp Connection */
#if(COM_TX_TP_IPDU_SUPPORT == STD_ON)
        if (COM_IPDU_TYPE_TP == TxIpduConfigPtr->IpduType)
        {
            Com_TxTpIpduResetConnection(TxIpduId);
        }
#endif
        /* Set the groupactive mode to false */
        Com_SetTxIpduGroupActive(TxIpduId,FALSE);
    }
}

/********************************************************************************************************************
*   Service Name     : Com_InitTxIpduBuffer
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_InitTxIpduBuffer(PduIdType TxIpduId)
{
    P2CONST(Com_TxIpduBufferConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduBufferConfigPtr;
    #if (COM_TX_TP_IPDU_SUPPORT == STD_ON)
    P2CONST(Com_TxTpIpduBufferConfigType,AUTOMATIC,COM_APPL_CONST) TxTpIpduBufferConfigPtr;
    #endif
    #if (COM_TX_SIGNAL_GROUP_SUPPORT == STD_ON)
    P2CONST(Com_TxShadowBufferConfigType,AUTOMATIC,COM_APPL_CONST) TxShadowBufferConfigPtr;
    Com_SignalGroupIdType TxSignalGroupId;
    #endif
    #if ((COM_TX_TP_IPDU_SUPPORT == STD_ON) || (COM_TX_SIGNAL_GROUP_SUPPORT == STD_ON))
    P2CONST(Com_TxIpduConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduConfigPtr;
    #endif
    
    if(COM_NUM_OF_TX_IPDU_ID > TxIpduId)
    {
#if ((COM_TX_TP_IPDU_SUPPORT == STD_ON) || (COM_TX_SIGNAL_GROUP_SUPPORT == STD_ON))
        TxIpduConfigPtr = &Com_TxIpduConfig[TxIpduId];
#endif
#if (COM_TX_TP_IPDU_SUPPORT == STD_ON)
        if(COM_IPDU_TYPE_TP == TxIpduConfigPtr->IpduType)
        {
            /* Initialize TP Buffer with Init values*/
            if (COM_NUM_OF_TX_TP_IPDU_ID > TxIpduConfigPtr->TpConfigId)
            {
                TxTpIpduBufferConfigPtr = &Com_TxTpIpduBufferConfig[TxIpduConfigPtr->TpConfigId];
                Com_SetTxIpduBufferLength(TxIpduId,TxTpIpduBufferConfigPtr->MinimumLength);
                Com_UtilMemCopy(&Com_TxTpIpduBuffer[TxTpIpduBufferConfigPtr->BufferStartId],
                                &Com_TxTpIpduBufferInitValues[TxTpIpduBufferConfigPtr->BufferStartId],
                                TxTpIpduBufferConfigPtr->MinimumLength);
            }
        }
        else
#endif
        {
            /* Initialize Normal buffer with Init values */
            TxIpduBufferConfigPtr = &Com_TxIpduBufferConfig[TxIpduId];
            Com_SetTxIpduBufferLength(TxIpduId,TxIpduBufferConfigPtr->MinimumLength);
            Com_UtilMemCopy(&Com_TxIpduBuffer[TxIpduBufferConfigPtr->BufferStartId],
                            &Com_TxIpduBufferInitValues[TxIpduBufferConfigPtr->BufferStartId],
                            TxIpduBufferConfigPtr->MinimumLength);
        }
#if (COM_TX_SIGNAL_GROUP_SUPPORT == STD_ON)
        /* Initilaize the signal groups ,shadow buffers and the signal group triggered events */
        if ((TxIpduConfigPtr->SignalGroupStartId < COM_NUM_OF_TX_SIGNAL_GROUP_ID)  &&
            (TxIpduConfigPtr->SignalGroupEndId < COM_NUM_OF_TX_SIGNAL_GROUP_ID))
        {
            for(TxSignalGroupId = TxIpduConfigPtr->SignalGroupStartId;
                    TxSignalGroupId <= TxIpduConfigPtr->SignalGroupEndId;TxSignalGroupId++)
            {
                /* Initialize the shadow buffer */
                TxShadowBufferConfigPtr = &Com_TxShadowBufferConfig[TxSignalGroupId];
                Com_UtilMemCopy(&Com_TxIpduShadowBuffer[TxShadowBufferConfigPtr->BufferStartId],
                                &Com_TxIpduShadowBufferInitValues[TxShadowBufferConfigPtr->BufferStartId],
                                TxShadowBufferConfigPtr->BufferEndId);
                Com_SetTxSignalGroupTriggerStatus(TxSignalGroupId,COM_SIGNAL_GROUP_TX_TRIGGER_NONE);
            }
        }
#endif
    }
}

/********************************************************************************************************************
*   Service Name     : Com_ProcessSendSignal
********************************************************************************************************************/
COM_LOCAL FUNC(uint8,COM_CODE) Com_ProcessSendSignal
(
    Com_SignalIdType SignalId , 
    P2CONST(void,AUTOMATIC,COM_APPL_CONST) SignalDataPtr ,
    uint16 Length
)
{
#if(COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON)
    boolean NewFilterState;
    boolean OldFilterState;
#endif
    boolean IsTxSignalDataChanged;
    uint8 ReturnValue=E_OK;
    P2CONST(Com_TxSignalConfigType,AUTOMATIC,COM_APPL_CONST) TxSignalConfigPtr;
#if(COM_TX_TP_IPDU_SUPPORT == STD_ON)
    P2CONST(Com_TxIpduConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduConfigPtr;
#endif

    if ((COM_NUM_OF_TX_SIGNAL_ID > SignalId) && (SignalDataPtr != NULL_PTR))
    {
        TxSignalConfigPtr = &Com_TxSignalConfig[SignalId];
        /* Check if the signal is an TP signal */
#if(COM_TX_TP_IPDU_SUPPORT == STD_ON)
        if (COM_NUM_OF_TX_IPDU_ID > TxSignalConfigPtr->ComPduId)
        {
            TxIpduConfigPtr = &Com_TxIpduConfig[TxSignalConfigPtr->ComPduId];
            if((COM_IPDU_TYPE_TP == TxIpduConfigPtr->IpduType) &&
               (COM_NUM_OF_TX_TP_IPDU_ID > TxIpduConfigPtr->TpConfigId))
            {
                /* Check buffer is idle to accept new transmission */
                if (COM_TXTP_CONN_STATE_IDLE != Com_TxTpIpduBufferState[TxIpduConfigPtr->TpConfigId])
                {
                    ReturnValue = COM_BUSY;
                }
            }
        }
        if (ReturnValue == E_OK)
#endif
        {
#if(COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON)
            /*  Check and Update the TMS based on the Filter state */
            if (COM_NUM_OF_TX_SIGNAL_FILTER_ID > TxSignalConfigPtr->TxFilterId)
            {
                NewFilterState = Com_ProcessTxSignalFilterState(TxSignalConfigPtr->TxFilterId,SignalId,SignalDataPtr);
                OldFilterState = Com_GetTxSignalFilterState(TxSignalConfigPtr->TxFilterId);
                if (NewFilterState != OldFilterState)
                {
                    /* Update Filter status */
                    Com_SetTxSignalFilterState(TxSignalConfigPtr->TxFilterId,NewFilterState);
                    Com_UpdateTMS(TxSignalConfigPtr->ComPduId);
                }
            }
#endif
            /* Check for Data change */
            IsTxSignalDataChanged = Com_IsTxSignalDataChanged(SignalId,SignalDataPtr);
            Com_EnterCriticalSection();
            /* Update the data in the IPDU buffer */
            Com_WriteTxSignalToIpdu(SignalId,SignalDataPtr,Length);
            Com_ExitCriticalSection();
#if(COM_TX_SIGNAL_UB_SUPPORT == STD_ON)
            /* TODO Set Update Bit */
#endif
            /* Evaluate the trigger conditions and update the transferProperty */
            switch (TxSignalConfigPtr->TransferPropertyType)
            {
                case COM_SIGNAL_TRANSFER_PROPERTY_TYPE_TRIGGERED:
                    Com_TriggerDirectTransmission(TxSignalConfigPtr->ComPduId,FALSE);
                    break;
                case COM_SIGNAL_TRANSFER_PROPERTY_TYPE_TRIGGERED_WITHOUT_REPETITION:
                    Com_TriggerDirectTransmission(TxSignalConfigPtr->ComPduId,TRUE);
                    break;
                case COM_SIGNAL_TRANSFER_PROPERTY_TYPE_TRIGGERED_ON_CHANGE:
                    if (IsTxSignalDataChanged == TRUE)
                    {
                        Com_TriggerDirectTransmission(TxSignalConfigPtr->ComPduId,FALSE);
                    }
                    break;
                case COM_SIGNAL_TRANSFER_PROPERTY_TYPE_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION:
                    if (IsTxSignalDataChanged == TRUE)
                    {
                        Com_TriggerDirectTransmission(TxSignalConfigPtr->ComPduId,TRUE);
                    }
                    break;
                default: /* COM_SIGNAL_TRANSFER_PROPERTY_TYPE_PENDING */
                    break;
            }
        }
    }
    else
    {
        ReturnValue = COM_SERVICE_NOT_AVAILABLE;
    }
    return ReturnValue;
}

#if(COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON)
/********************************************************************************************************************
*   Service Name     : Com_UpdateTMS
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UpdateTMS(PduIdType TxIpduId)
{
    Com_TxIpduTxModeType TxIpduTxMode = COM_IPDU_TX_MODE_TYPE_FALSE;
    P2CONST(Com_TxIpduConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduConfigPtr;
    Com_TxSignalFilterIdType Id;
    
    if(COM_NUM_OF_TX_IPDU_ID > TxIpduId)
    {
        TxIpduConfigPtr = &Com_TxIpduConfig[TxIpduId];
        /* Check all filter status supported by the Ipdu */
        if (COM_NUM_OF_TX_SIGNAL_FILTER_ID > TxIpduConfigPtr->SignalFilterStartId)
        {
            for (Id = TxIpduConfigPtr->SignalFilterStartId ; Id<= TxIpduConfigPtr->SignalFilterEndId;Id++)
            {
                /*  Get the filter state for the signal */
                if (TRUE == Com_GetTxSignalFilterState(Id))
                {
                    TxIpduTxMode = COM_IPDU_TX_MODE_TYPE_TRUE;
                    break;
                }
            }
        }
        /* Init TMS if current Mode is different */
        if (TxIpduTxMode != Com_GetTxIpduTxMode(TxIpduId))
        {
            /* Update new mode */
            Com_SetTxIpduTxMode(TxIpduId,TxIpduTxMode);
            /* Reset the mode properties */
            Com_InitTxIpduTxModeProperties(TxIpduId);
            /* Set the transmit request if the changed state is Direct/Mixed */
            Com_TriggerDirectTransmission(TxIpduId,FALSE);
        }
    }
}
#endif
/********************************************************************************************************************
*   Service Name     : Com_TriggerDirectTransmission
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_TriggerDirectTransmission(PduIdType TxIpduId , boolean IsRequestWithoutRepetition)
{
    P2CONST(Com_TxIpduTxModeConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduTxModeConfigPtr;
    if(COM_NUM_OF_TX_IPDU_ID > TxIpduId)
    {
        /* Get the Mode configuration */
        if (Com_GetTxIpduTxMode(TxIpduId) == COM_IPDU_TX_MODE_TYPE_TRUE)
        {
            TxIpduTxModeConfigPtr = &Com_TxIpduTxModeTrueConfig[TxIpduId];
        }
        else
        {
            TxIpduTxModeConfigPtr = &Com_TxIpduTxModeFalseConfig[TxIpduId];
        }
        /* Check for direct transmission mode */
        if((COM_TX_MODE_MODE_TYPE_MIXED ==  TxIpduTxModeConfigPtr->TxModeModeType) ||
           (COM_TX_MODE_MODE_TYPE_DIRECT == TxIpduTxModeConfigPtr->TxModeModeType))
        {
            if(IsRequestWithoutRepetition == TRUE)
            {
                Com_SetTxIpduTransmitRequest(TxIpduId,TRUE); /* transmit once */
            }
            else
            {
                Com_SetTxIpduRepetitionCount(TxIpduId,TxIpduTxModeConfigPtr->RepetitionCount);
                /* Get Repetition count from the current mode */
                if (0U != TxIpduTxModeConfigPtr->RepetitionCount)
                {
                    Com_SetTxIpduRepetitionPeriod(TxIpduId,1U);
                }
                else
                {
                    Com_SetTxIpduTransmitRequest(TxIpduId,TRUE); /* transmit once */
                }
            }
        }
    }
}

/********************************************************************************************************************
*   Service Name     : Com_IsTxSignalDataChanged
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_IsTxSignalDataChanged
(
    Com_SignalIdType SignalId ,
    P2CONST(void,AUTOMATIC,AUTOMATIC) SignalDataPtr
)
{
    boolean IsDataChanged=FALSE;
    uint32  SignalOldDataU32 = 0U;
    uint64  SignalOldDataU64 = 0U;
#if(COM_SIGNAL_TYPE_FLOAT32_SUPPORT == STD_ON)  
    float32 SignalOldDataF32 = 0U;
#endif
#if(COM_SIGNAL_TYPE_FLOAT64_SUPPORT == STD_ON)  
    float64 SignalOldDataF64 = 0U;
#endif  
    uint32 Mask=0U;
    PduLengthType ByteOffset;
    PduLengthType Idx;
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) BufferPtr;
    P2CONST(Com_TxSignalConfigType,AUTOMATIC,COM_APPL_CONST) TxSignalConfigPtr = NULL_PTR;
    P2CONST(Com_TxIpduBufferConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduBufferConfigPtr = NULL_PTR;

    /* Get the Buffer configuration */
    if ((COM_NUM_OF_TX_SIGNAL_ID > SignalId) && (SignalDataPtr != NULL_PTR))
    {
        TxSignalConfigPtr = &Com_TxSignalConfig[SignalId];
        if (COM_NUM_OF_TX_IPDU_ID > TxSignalConfigPtr->ComPduId)
        {
            TxIpduBufferConfigPtr = &Com_TxIpduBufferConfig[TxSignalConfigPtr->ComPduId];
        }
    }

    if (TxIpduBufferConfigPtr != NULL_PTR)
    {
        switch(TxSignalConfigPtr->SignalType)
        {
            case COM_SIGNALTYPE_BOOLEAN:
                Mask = (boolean)0x01U;
                Com_ReadTxSignalFromIpdu(SignalId,(void *)&SignalOldDataU32);
                if ((boolean)SignalOldDataU32 != (boolean)((*(boolean *)SignalDataPtr) & ((boolean)Mask)))
                {
                    IsDataChanged = TRUE;
                }
                break;
            case COM_SIGNALTYPE_UINT8:
            case COM_SIGNALTYPE_SINT8:
                Mask = (uint8)((1U << TxSignalConfigPtr->BitSize)-1U);
                Com_ReadTxSignalFromIpdu(SignalId,(void *)&SignalOldDataU32);
                if ((uint8)SignalOldDataU32 != ((*(uint8 *)SignalDataPtr) & Mask))
                {
                    IsDataChanged = TRUE;
                }
                break;
            case COM_SIGNALTYPE_UINT16:
            case COM_SIGNALTYPE_SINT16:
                Mask = (uint16)((1U << TxSignalConfigPtr->BitSize)-1U);
                Com_ReadTxSignalFromIpdu(SignalId,(void *)&SignalOldDataU32);
                if ((uint16)SignalOldDataU32 != ((*(uint16 *)SignalDataPtr)&Mask))
                {
                    IsDataChanged = TRUE;
                }
                break;

            case COM_SIGNALTYPE_UINT32:
            case COM_SIGNALTYPE_SINT32:
                if(TxSignalConfigPtr->BitSize == 32U)
                {
                    Mask = 0xFFFFFFFFU; 
                }
                else
                {
                    Mask = (uint32)((1U << TxSignalConfigPtr->BitSize)-1U);
                }
                Com_ReadTxSignalFromIpdu(SignalId,(void *)&SignalOldDataU32);
                if ((uint32)SignalOldDataU32 != ((*(uint32 *)SignalDataPtr) & Mask))
                {
                    IsDataChanged = TRUE;
                }
                break;

            case COM_SIGNALTYPE_UINT64:
            case COM_SIGNALTYPE_SINT64:
                Com_ReadTxSignalFromIpdu(SignalId,(void *)&SignalOldDataU64);
                if ((uint64)SignalOldDataU64 != (*(uint64 *)SignalDataPtr))
                {
                    IsDataChanged = TRUE;
                }
                break;
#if(COM_SIGNAL_TYPE_FLOAT32_SUPPORT == STD_ON)
            case COM_SIGNALTYPE_FLOAT32:
                Com_ReadTxSignalFromIpdu(SignalId,(void *)&SignalOldDataF32);
                if ((float32)SignalOldDataU32 != (*(float32 *)SignalDataPtr))
                {
                    IsDataChanged = TRUE;
                }
                break;
#endif
#if(COM_SIGNAL_TYPE_FLOAT64_SUPPORT == STD_ON)              
            case COM_SIGNALTYPE_FLOAT64:
                Com_ReadTxSignalFromIpdu(SignalId,(void *)&SignalOldDataF64);
                if ((float64)SignalOldDataU32 != (*(float64 *)SignalDataPtr))
                {
                    IsDataChanged = TRUE;
                }
                break;
#endif
            case COM_SIGNALTYPE_UINT8_N:
                /* get the data buffer index of the signal */
                ByteOffset = TxIpduBufferConfigPtr->BufferStartId + TxSignalConfigPtr->LsBytePosition;
                BufferPtr = (uint8* )SignalDataPtr;
                if (COM_TX_IPDU_BUFFER_SIZE > (ByteOffset+TxSignalConfigPtr->ByteLength))
                {
                    for(Idx=0;Idx< TxSignalConfigPtr->ByteLength ;Idx++)
                    {
                        if (BufferPtr[Idx] != Com_TxIpduBuffer[ByteOffset+Idx])
                        {
                            IsDataChanged = TRUE;
                            break;
                        }
                    }
                }
                /* loop through the signal and compare */
                break;
            default:
                IsDataChanged = FALSE;
                break;
        }
    }
    return IsDataChanged;
}

/********************************************************************************************************************
*   Service Name     : Com_WriteTxSignalToIpdu
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_WriteTxSignalToIpdu
(
    Com_SignalIdType SignalId ,
    P2CONST(void,AUTOMATIC,COM_APPL_CONST) SignalDataPtr ,
    uint16 Length
)
{
    /* Get PduId  */
    P2CONST(Com_TxSignalConfigType,AUTOMATIC,COM_APPL_CONST) TxSignalConfigPtr = NULL_PTR;
    P2CONST(Com_TxIpduBufferConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduBufferConfigPtr = NULL_PTR;
    #if(COM_TX_TP_IPDU_SUPPORT == STD_ON)
    P2CONST(Com_TxIpduConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduConfigPtr = NULL_PTR;
    P2CONST(Com_TxTpIpduBufferConfigType,AUTOMATIC,COM_APPL_CONST) TxTpIpduBufferConfigPtr = NULL_PTR;
    #endif
    Com_UtilBitCopyPropsType UtilBitCopyProps;
    /* Get the Buffer configuration */
    if ((COM_NUM_OF_TX_SIGNAL_ID > SignalId) && (SignalDataPtr != NULL_PTR))
    {
        TxSignalConfigPtr = &Com_TxSignalConfig[SignalId];
        if (COM_NUM_OF_TX_IPDU_ID > TxSignalConfigPtr->ComPduId)
        {
            TxIpduBufferConfigPtr = &Com_TxIpduBufferConfig[TxSignalConfigPtr->ComPduId];
        }
    }

    if (TxIpduBufferConfigPtr != NULL_PTR)
    {
        /* Get buffer for the Pdu */
        UtilBitCopyProps.SignalLengthInBits  = TxSignalConfigPtr->BitSize;
        if (TxSignalConfigPtr->SignalType == COM_SIGNALTYPE_UINT8_DYN)
        {
            if (Length > 0U)
            {
                if ((Length <= TxSignalConfigPtr->ByteLength))
                {
                    if (COM_NUM_OF_TX_IPDU_ID > TxSignalConfigPtr->ComPduId)
                    {
                        UtilBitCopyProps.SingalLengthInBytes = Length;
                        Com_SetTxIpduBufferLength(TxSignalConfigPtr->ComPduId,Length);
                    }
                }
                else
                {
                    if (COM_NUM_OF_TX_IPDU_ID > TxSignalConfigPtr->ComPduId)
                    {
                        /* invalid signal length */
                        UtilBitCopyProps.SingalLengthInBytes = TxSignalConfigPtr->ByteLength;
                        Com_SetTxIpduBufferLength(TxSignalConfigPtr->ComPduId,TxSignalConfigPtr->ByteLength);
                    }
                }

            }
            else
            {
                UtilBitCopyProps.SingalLengthInBytes = Length;
            }
            if( (Length * 8U) <= TxSignalConfigPtr->BitSize )
            {
                UtilBitCopyProps.SignalLengthInBits  = Length * 8U;
            }
            else
            {
                /* Signal bit length should be capped at configured BitSize. Now already assigned at line 3636 */
            }
        }
        else
        {
            UtilBitCopyProps.SingalLengthInBytes = TxSignalConfigPtr->ByteLength;
        }

        /* Update the bit copy details */
        #if(COM_MICRO_ENDIANESS == COM_ENDIANESS_LITTLE)
        UtilBitCopyProps.SrcLsBit = 0U;
        UtilBitCopyProps.SrcLsByte = 0U;
        UtilBitCopyProps.SrcBufferEndianess = COM_ENDIANESS_LITTLE;
        #else
        UtilBitCopyProps.SrcLsBit = 0U;
        UtilBitCopyProps.SrcLsByte = UtilBitCopyProps.SingalLengthInBytes;
        UtilBitCopyProps.SrcBufferEndianess = COM_ENDIANESS_BIG;
        #endif
        if(TxSignalConfigPtr->SignalType == COM_SIGNALTYPE_UINT8_DYN)
        {
            if ((Length <= TxSignalConfigPtr->ByteLength))
            {
                UtilBitCopyProps.MaxSrcBufferSize = Length;
                UtilBitCopyProps.MaxDestBufferSize = Length;
            }
            else
            {
                UtilBitCopyProps.MaxSrcBufferSize = TxSignalConfigPtr->ByteLength;
                UtilBitCopyProps.MaxDestBufferSize = TxSignalConfigPtr->ByteLength;
            }
        }
        else
        {
            UtilBitCopyProps.MaxSrcBufferSize = TxSignalConfigPtr->ByteLength;
            UtilBitCopyProps.MaxDestBufferSize = TxIpduBufferConfigPtr->MaximumLength;
        }
        UtilBitCopyProps.DestLsBit = TxSignalConfigPtr->LsBitPosition;
        UtilBitCopyProps.DestLsByte = TxSignalConfigPtr->LsBytePosition;
        if (TxSignalConfigPtr->SignalEndiannessType == COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN)
        {
            UtilBitCopyProps.DestBufferEndianess = COM_ENDIANESS_BIG;
        }
        else
        {
            /* Opaque uint8[n] is for same as Little Endian , bit 0 in byte 0*/
            UtilBitCopyProps.DestBufferEndianess = COM_ENDIANESS_LITTLE;
        }

        #if(COM_TX_TP_IPDU_SUPPORT == STD_ON)
        TxIpduConfigPtr = &Com_TxIpduConfig[TxSignalConfigPtr->ComPduId];
        if(TxIpduConfigPtr->IpduType == COM_IPDU_TYPE_TP)
        {
            if(TxIpduConfigPtr->TpConfigId < COM_NUM_OF_TX_TP_IPDU_ID)  /* Coverity Fix - Com Tp*/
            {
                TxTpIpduBufferConfigPtr = &Com_TxTpIpduBufferConfig[TxIpduConfigPtr->TpConfigId];
            }
            if(TxTpIpduBufferConfigPtr != NULL_PTR)   /* Coverity Fix - Com Tp*/
            {
                if (COM_TX_TP_TOTAL_BUFFERS > TxTpIpduBufferConfigPtr->BufferStartId)
                { 
                    /* copy the data from SignalDataPtr to TxIpdu buffer */
                    Com_UtilBitCopy(&UtilBitCopyProps,(uint8*)SignalDataPtr,
                                    &Com_TxTpIpduBuffer[TxTpIpduBufferConfigPtr->BufferStartId]);
                }
            }
        }
        else  //COM_IPDU_TYPE_NORMAL
        #endif
        {
            if (COM_TX_IPDU_BUFFER_SIZE > TxIpduBufferConfigPtr->BufferStartId)
            {
                /* copy the data from SignalDataPtr to TxIpdu buffer */
                Com_UtilBitCopy(&UtilBitCopyProps,(uint8*)SignalDataPtr,
                                &Com_TxIpduBuffer[TxIpduBufferConfigPtr->BufferStartId]); 
            }
        }
    }
}

/********************************************************************************************************************
*   Service Name     : Com_ReadTxSignalFromIpdu
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_ReadTxSignalFromIpdu
(
    Com_SignalIdType SignalId ,
    P2VAR(void,AUTOMATIC,COM_APPL_DATA) SignalDataPtr
)
{
    P2CONST(Com_TxSignalConfigType,AUTOMATIC,COM_APPL_CONST) TxSignalConfigPtr = NULL_PTR;
    P2CONST(Com_TxIpduBufferConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduBufferConfigPtr = NULL_PTR;
    Com_UtilBitCopyPropsType UtilBitCopyProps;
    /* Get the Buffer configuration */
    if ((COM_NUM_OF_TX_SIGNAL_ID > SignalId) && (SignalDataPtr != NULL_PTR))
    {
        TxSignalConfigPtr = &Com_TxSignalConfig[SignalId];
        if (COM_NUM_OF_TX_IPDU_ID > TxSignalConfigPtr->ComPduId)
        {
            TxIpduBufferConfigPtr = &Com_TxIpduBufferConfig[TxSignalConfigPtr->ComPduId];
        }
    }

    if (TxIpduBufferConfigPtr != NULL_PTR)
    {
        /* Get buffer for the Pdu */
        UtilBitCopyProps.SignalLengthInBits  = TxSignalConfigPtr->BitSize;
        UtilBitCopyProps.SingalLengthInBytes = TxSignalConfigPtr->ByteLength;
        /* Update the bit copy details */
        UtilBitCopyProps.SrcLsBit = TxSignalConfigPtr->LsBitPosition;
        UtilBitCopyProps.SrcLsByte = TxSignalConfigPtr->LsBytePosition;
        if (TxSignalConfigPtr->SignalEndiannessType == COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN)
        {
            UtilBitCopyProps.SrcBufferEndianess = COM_ENDIANESS_BIG;
        }
        else
        {
            /* Opaque uint8[n] is for same as Little Endian , bit 0 in byte 0*/
            UtilBitCopyProps.SrcBufferEndianess = COM_ENDIANESS_LITTLE;
        }
        UtilBitCopyProps.MaxSrcBufferSize = TxIpduBufferConfigPtr->MaximumLength;

        #if(COM_MICRO_ENDIANESS == COM_ENDIANESS_LITTLE)
        UtilBitCopyProps.DestLsBit = 0U;
        UtilBitCopyProps.DestLsByte = 0U;
        UtilBitCopyProps.DestBufferEndianess = COM_ENDIANESS_LITTLE;
        #else
        UtilBitCopyProps.DestLsBit = 0U;
        UtilBitCopyProps.DestLsBit = TxSignalConfigPtr->ByteLength;
        UtilBitCopyProps.DestBufferEndianess = COM_ENDIANESS_BIG;
        #endif
        UtilBitCopyProps.MaxDestBufferSize = TxSignalConfigPtr->ByteLength;
        /* Clear source buffer */
        Com_UtilMemSet((uint8*)SignalDataPtr,0U,TxSignalConfigPtr->ByteLength);
        if (COM_TX_IPDU_BUFFER_SIZE > TxIpduBufferConfigPtr->BufferStartId)
        {
            /* copy the data from TxIpdu buffer to SignalDataPtr */
            Com_UtilBitCopy(&UtilBitCopyProps,
                            &Com_TxIpduBuffer[TxIpduBufferConfigPtr->BufferStartId],(uint8*)SignalDataPtr);
        }

        /* Extend sign */
        switch(TxSignalConfigPtr->SignalType)
        {
            case COM_SIGNALTYPE_SINT8:
                Com_UtilGetSignExtended8BitData((uint8*)SignalDataPtr,TxSignalConfigPtr->BitSize);
                break;
            case COM_SIGNALTYPE_SINT16:
                Com_UtilGetSignExtended16BitData((uint16*)SignalDataPtr,TxSignalConfigPtr->BitSize);
                break;
            case COM_SIGNALTYPE_SINT32:
                Com_UtilGetSignExtended32BitData((uint32*)SignalDataPtr,TxSignalConfigPtr->BitSize);
                break;
            case COM_SIGNALTYPE_SINT64:
                Com_UtilGetSignExtended64BitData((uint64*)SignalDataPtr,TxSignalConfigPtr->BitSize);
                break;
            default:
                break;
        }
    }
}

#if(COM_TX_SIGNAL_GROUP_SUPPORT == STD_ON)
/********************************************************************************************************************
*   Service Name     : Com_ProcessSendSignalGroup
********************************************************************************************************************/
COM_LOCAL FUNC(uint8,COM_CODE) Com_ProcessSendSignalGroup(Com_SignalGroupIdType SignalGroupId)
{
    uint8 ReturnValue = COM_SERVICE_NOT_AVAILABLE;
    #if (COM_TX_SIGNAL_GROUP_UB_SUPPORT == STD_ON)
    Com_TxIpduShadowBufferIdType ByteOffset;
    #endif
    Com_UtilBitCopyPropsType UtilBitCopyProps;
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) ShadowBufferPtr;
    P2CONST(Com_TxSignalGroupConfigType,AUTOMATIC,COM_APPL_CONST) TxSignalGroupConfigPtr;
    P2CONST(Com_TxIpduBufferConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduBufferConfigPtr;
    P2CONST(Com_TxShadowBufferConfigType,AUTOMATIC,COM_APPL_CONST) TxShadowBufferConfigPtr;

    if (COM_NUM_OF_TX_SIGNAL_GROUP_ID > SignalGroupId)
    {
        TxSignalGroupConfigPtr = &Com_TxSignalGroupConfig[SignalGroupId];
        if (COM_NUM_OF_TX_SIGNAL_GROUP_ID > TxSignalGroupConfigPtr->ShadowBufferConfigId)
        {
            TxShadowBufferConfigPtr = &Com_TxShadowBufferConfig[TxSignalGroupConfigPtr->ShadowBufferConfigId];
            if ((COM_TX_SHADOW_BUFFER_SIZE > TxShadowBufferConfigPtr->BufferStartId) &&
                (COM_NUM_OF_TX_IPDU_ID > TxSignalGroupConfigPtr->ComPduId))
            {
               TxIpduBufferConfigPtr = &Com_TxIpduBufferConfig[TxSignalGroupConfigPtr->ComPduId];
               ReturnValue = E_OK;
            }
        }
    }

    if (ReturnValue ==E_OK)
    {
        /* get shadow buffer */
        ShadowBufferPtr = &Com_TxIpduShadowBuffer[TxShadowBufferConfigPtr->BufferStartId];
        /* Update Filter state */
        //if (TxSignalGroupConfigPtr->FilterId != COM_NO_FILTER_ID)
        {
#if(COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON)
            Com_UpdateTMS(TxSignalGroupConfigPtr->ComPduId);
#endif
        }

        /* Copy the data to the original buffer */
        /* Update the bit copy details */
        UtilBitCopyProps.SignalLengthInBits  = TxSignalGroupConfigPtr->BitSize;
        UtilBitCopyProps.SingalLengthInBytes = TxSignalGroupConfigPtr->ByteLength;
        #if(COM_MICRO_ENDIANESS == COM_ENDIANESS_LITTLE)
        UtilBitCopyProps.SrcLsBit = 0U;
        UtilBitCopyProps.SrcLsByte = 0U;
        UtilBitCopyProps.SrcBufferEndianess = COM_ENDIANESS_LITTLE;
        #else
        UtilBitCopyProps.SrcLsBit = 0U;
        UtilBitCopyProps.SrcLsByte = TxSignalConfigPtr->ByteLength;
        UtilBitCopyProps.SrcBufferEndianess = COM_ENDIANESS_BIG;
        #endif
        UtilBitCopyProps.MaxSrcBufferSize = TxSignalGroupConfigPtr->ByteLength;
        UtilBitCopyProps.DestLsBit = TxSignalGroupConfigPtr->LsBitPosition;
        UtilBitCopyProps.DestLsByte = TxSignalGroupConfigPtr->LsBytePosition;
        UtilBitCopyProps.MaxDestBufferSize = TxIpduBufferConfigPtr->MaximumLength;

        /* Opaque uint8[n] is for same as Little Endian , bit 0 in byte 0*/
        UtilBitCopyProps.DestBufferEndianess = COM_ENDIANESS_LITTLE;
        /* copy the data from shadow to TxIpdu buffer */
        if (COM_TX_IPDU_BUFFER_SIZE > TxIpduBufferConfigPtr->BufferStartId)
        {
            /* copy the data from SignalDataPtr to TxIpdu buffer */
            Com_UtilBitCopy(&UtilBitCopyProps,ShadowBufferPtr,
                                &Com_TxIpduBuffer[TxIpduBufferConfigPtr->BufferStartId]);
        }
        #if (COM_TX_SIGNAL_GROUP_UB_SUPPORT == STD_ON)
        ByteOffset = TxIpduBufferConfigPtr->BufferStartId + TxSignalGroupConfigPtr->UBBytePosition;
        /* Update the UB */
        if (COM_TX_IPDU_BUFFER_SIZE > ByteOffset )
        {
            Com_UtilSetClearBit(&Com_TxIpduBuffer[ByteOffset],TxSignalGroupConfigPtr->UBBitPosition,TRUE);
        }
        #endif

        /* Trigger Event processing */

        if (Com_GetSignalGroupTriggerStatus(SignalGroupId) != COM_SIGNAL_GROUP_TX_TRIGGER_NONE)
        {
            if (Com_GetSignalGroupTriggerStatus(SignalGroupId) ==  COM_SIGNAL_GROUP_TX_TRIGGER_WITH_REPITITION)
            {
                Com_TriggerDirectTransmission(TxSignalGroupConfigPtr->ComPduId,FALSE);
            }
            else
            {
                Com_TriggerDirectTransmission(TxSignalGroupConfigPtr->ComPduId,TRUE);
            }
            Com_SetTxSignalGroupTriggerStatus(SignalGroupId,COM_SIGNAL_GROUP_TX_TRIGGER_NONE);
        }
        ReturnValue = E_OK;
    }
    return ReturnValue;
}
#endif

#if((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_ON) || (COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_ON))
/********************************************************************************************************************
*   Service Name     : Com_ProcessInvalidateSignal
********************************************************************************************************************/
COM_LOCAL FUNC(uint8,COM_CODE) Com_ProcessInvalidateSignal(Com_SignalIdType SignalId)
{
    uint8 ReturnValue = COM_SERVICE_NOT_AVAILABLE;
    P2CONST(Com_TxSignalConfigType,AUTOMATIC,COM_APPL_CONST) TxSignalConfigPtr;
    Com_TxInvalidDataBufferIdType BufferId;

    if (COM_NUM_OF_TX_SIGNAL_ID > SignalId)
    {
        TxSignalConfigPtr = &Com_TxSignalConfig[SignalId];
        BufferId = TxSignalConfigPtr->InvalidDataBufferStartId;
        ReturnValue = E_OK;
    }

    if (ReturnValue == E_OK)
    {
        ReturnValue = COM_SERVICE_NOT_AVAILABLE;
        switch(TxSignalConfigPtr->SignalType)
        {
#if(COM_TX_SIGNAL_INVALID_BOOLEAN_SUPPORT == STD_ON)
            case COM_SIGNALTYPE_BOOLEAN:
                if (COM_BOOL_SIGNAL_INVALID_DATA_BUFFER_SIZE > BufferId)
                {
                    ReturnValue = Com_ProcessSendSignal(SignalId,(void *)&Com_BooleanSignalInvalidData[BufferId],0U);
                }
                break;
#endif
#if(COM_TX_SIGNAL_INVALID_UINT8_SUPPORT == STD_ON)
            case COM_SIGNALTYPE_UINT8:
                if (COM_UINT8_SIGNAL_INVALID_DATA_BUFFER_SIZE > BufferId)
                {
                    ReturnValue = Com_ProcessSendSignal(SignalId,(void *)&Com_Uint8SignalInvalidData[BufferId],0U);
                }
                break;
#endif
#if(COM_TX_SIGNAL_INVALID_SINT8_SUPPORT == STD_ON)
            case COM_SIGNALTYPE_SINT8:
                if (COM_SINT8_SIGNAL_INVALID_DATA_BUFFER_SIZE > BufferId)
                {
                    ReturnValue = Com_ProcessSendSignal(SignalId,(void *)&Com_Sint8SignalInvalidData[BufferId],0U);
                }
                break;
#endif
#if(COM_TX_SIGNAL_INVALID_UINT16_SUPPORT == STD_ON)
            case COM_SIGNALTYPE_UINT16:
                if (COM_UINT16_SIGNAL_INVALID_DATA_BUFFER_SIZE > BufferId)
                {
                    ReturnValue = Com_ProcessSendSignal(SignalId,(void *)&Com_Uint16SignalInvalidData[BufferId],0U);
                }
                break;
#endif
#if(COM_TX_SIGNAL_INVALID_SINT16_SUPPORT == STD_ON)
            case COM_SIGNALTYPE_SINT16:
                if (COM_SINT16_SIGNAL_INVALID_DATA_BUFFER_SIZE > BufferId)
                {
                    ReturnValue = Com_ProcessSendSignal(SignalId,(void *)&Com_Sint16SignalInvalidData[BufferId],0U);
                }
                break;
#endif
#if(COM_TX_SIGNAL_INVALID_UINT32_SUPPORT == STD_ON)
            case COM_SIGNALTYPE_UINT32:
                if (COM_UINT32_SIGNAL_INVALID_DATA_BUFFER_SIZE > BufferId)
                {
                    ReturnValue = Com_ProcessSendSignal(SignalId,(void *)&Com_Uint32SignalInvalidData[BufferId],0U);
                }
                break;
#endif
#if(COM_TX_SIGNAL_INVALID_SINT32_SUPPORT == STD_ON)
            case COM_SIGNALTYPE_SINT32:
                if (COM_SINT32_SIGNAL_INVALID_DATA_BUFFER_SIZE > BufferId)
                {
                    ReturnValue = Com_ProcessSendSignal(SignalId,(void *)&Com_Sint32SignalInvalidData[BufferId],0U);
                }
                break;
#endif
#if(COM_TX_SIGNAL_INVALID_UINT64_SUPPORT == STD_ON)
            case COM_SIGNALTYPE_UINT64:
                if (COM_UINT64_SIGNAL_INVALID_DATA_BUFFER_SIZE > BufferId)
                {
                    ReturnValue = Com_ProcessSendSignal(SignalId,(void *)&Com_Uint64SignalInvalidData[BufferId],0U);
                }
                break;
#endif
#if(COM_TX_SIGNAL_INVALID_SINT64_SUPPORT == STD_ON)
            case COM_SIGNALTYPE_SINT64:
                if (COM_SINT64_SIGNAL_INVALID_DATA_BUFFER_SIZE > BufferId)
                {
                    ReturnValue = Com_ProcessSendSignal(SignalId,(void *)&Com_Sint64SignalInvalidData[BufferId],0U);
                }
                break;
#endif
#if(COM_TX_SIGNAL_INVALID_FLOAT32_SUPPORT == STD_ON)
            case COM_SIGNALTYPE_FLOAT32:
                if (COM_FLOAT32_SIGNAL_INVALID_DATA_BUFFER_SIZE > BufferId)
                {
                    ReturnValue = Com_ProcessSendSignal(SignalId,(void *)&Com_Float32SignalInvalidData[BufferId],0U);
                }
                break;
#endif
#if(COM_TX_SIGNAL_INVALID_FLOAT64_SUPPORT == STD_ON)
            case COM_SIGNALTYPE_FLOAT64:
                if (COM_FLOAT64_SIGNAL_INVALID_DATA_BUFFER_SIZE > BufferId)
                {
                    ReturnValue = Com_ProcessSendSignal(SignalId,(void *)&Com_Float64SignalInvalidData[BufferId],0U);
                }
                break;
#endif
#if(COM_TX_SIGNAL_INVALID_UINT8ARR_SUPPORT == STD_ON)
            case COM_SIGNALTYPE_UINT8_DYN:
            case COM_SIGNALTYPE_UINT8_N:
                if (COM_UINT8ARR_SIGNAL_INVALID_DATA_BUFFER_SIZE > BufferId)
                {
                    ReturnValue = Com_ProcessSendSignal(SignalId,(void *)&Com_Uint8ArrSignalInvalidData[BufferId],
                                                        TxSignalConfigPtr->ByteLength);
                }
                break;
#endif
            default:
                break;
        }
    }
    else
    {
        ReturnValue = COM_SERVICE_NOT_AVAILABLE;
    }
    return ReturnValue;
}
#endif

/********************************************************************************************************************
*   Service Name     : Com_ProcessTxConfirmation
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_ProcessTxConfirmation(PduIdType TxPduId)
{
    P2CONST(Com_TxIpduConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduConfigPtr;
    P2CONST(Com_TxIpduTxModeConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduTxModeConfigPtr;

    if (COM_NUM_OF_TX_IPDU_ID > TxPduId )
    {
        TxIpduConfigPtr = &Com_TxIpduConfig[TxPduId];
        if (Com_GetTxIpduConfirmationWait(TxPduId) == TRUE)
        {
            /* Get the Mode configuration */
            if (Com_GetTxIpduTxMode(TxPduId) == COM_IPDU_TX_MODE_TYPE_TRUE)
            {
                TxIpduTxModeConfigPtr = &Com_TxIpduTxModeTrueConfig[TxPduId];
            }
            else
            {
                TxIpduTxModeConfigPtr = &Com_TxIpduTxModeFalseConfig[TxPduId];
            }
            
            // clear update bits
#if(COM_TX_SIGNAL_UB_SUPPORT == STD_ON)
            if (TxIpduConfigPtr->TxIpduClearUpdateBitType == COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_CONFIRMATION)
            {
                Com_ClearUpdateBits(TxPduId);
            }
#endif
            // check repition count
            if (0u != Com_TxIpduRepetitionCount[TxPduId])
            {
                Com_TxIpduRepetitionCount[TxPduId]--;
                Com_SetTxIpduRepetitionPeriod(TxPduId,TxIpduTxModeConfigPtr->RepetitionPeriod);
            }
            if (Com_TxIpduRepetitionCount[TxPduId] == 0U)
            {
                Com_SetTxIpduRepetitionPeriod(TxPduId,0U);
                if (TxIpduConfigPtr->IpduSignalProcessingType == COM_IPDU_SIGNAL_PROCESSING_TYPE_IMMEDIATE)
                {
                    Com_ProcessConfirmationNotification(TxPduId);
                }
                else
                {
                    Com_SetTxIpduDefferedNotification(TxPduId,TRUE);
                }
            }
            Com_SetTxIpduConfirmationWait(TxPduId,FALSE);
        }
        #if (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON)
        /* Clear Tx timeout couner. */
        if (COM_NUM_OF_TX_IPDU_TIMEOUT_COUNTER_ID > TxIpduConfigPtr->TxTimeoutCounterId)
        {
            Com_SetTxIpduTxTimeoutCount(TxIpduConfigPtr->TxTimeoutCounterId,0U);
        }
        #endif
    }
}
/********************************************************************************************************************
*   Service Name     : Com_ProcessConfirmationNotification
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_ProcessConfirmationNotification(PduIdType TxPduId)
{
    #if (COM_TX_SIGNAL_ACK_CALLBACK_SUPPORT == STD_ON)
    /* Local Variables */
    P2CONST(Com_TxIpduConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduConfigPtr;
    P2CONST(Com_TxSignalConfigType,AUTOMATIC,COM_APPL_CONST) TxSignalConfigPtr;
    Com_CbkTxAckFunctType TxAckFunctPtr;
    Com_SignalIdType SigIdx;
    #endif

    #if (COM_TX_SIGNAL_ACK_CALLBACK_SUPPORT == STD_ON)
    /* Check added to resolve coverity Out of bound Warning */
    if (COM_NUM_OF_TX_IPDU_ID > TxPduId)
    {
        /* Get Pdu Configuration */
        TxIpduConfigPtr = &Com_TxIpduConfig[TxPduId];
        /* process all signals in a message */
        for(SigIdx = TxIpduConfigPtr->SignalStartId; ((SigIdx <= TxIpduConfigPtr->SignalEndId) && (COM_NUM_OF_TX_SIGNAL_ID > SigIdx)); SigIdx++)
        {
            /* Get Signal Configuration */
            TxSignalConfigPtr = &Com_TxSignalConfig[SigIdx];
            
            /* if the Callback function is configured , invoke the function to notify message reception */
            if (COM_NUM_OF_TX_ACK_FUNCTION > TxSignalConfigPtr->TxAckFunctId)
            {
                TxAckFunctPtr = Com_CbkTxAckFunctConfig[TxSignalConfigPtr->TxAckFunctId];
                if (NULL_PTR != TxAckFunctPtr)
                {
                    (*TxAckFunctPtr)();
                }
            }
            
        }
        /* Clear Tx Request */
        #endif
        /*! TODO Signal Group confirmation callback addition */
        /*Com_SetTxIpduTransmitRequest(TxPduId,FALSE);*/
        Com_SetTxIpduDefferedNotification(TxPduId,FALSE);
    }
}

#if(COM_TX_SIGNAL_UB_SUPPORT == STD_ON)
/********************************************************************************************************************
*   Service Name     : Com_ClearUpdateBits
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_ClearUpdateBits(PduIdType TxPduId)
{
    Com_SignalIdType Idx;
    Com_TxIpduBufferIdType ByteOffset;
    P2CONST(Com_TxSignalConfigType,AUTOMATIC,COM_APPL_CONST) TxSignalConfigPtr;
    P2CONST(Com_TxIpduBufferConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduBufferConfigPtr;
    P2CONST(Com_TxIpduConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduConfigPtr;
    P2CONST(Com_UBPropsType,AUTOMATIC,COM_APPL_CONST) TxSignalUBPropsPtr;

    TxIpduConfigPtr = &Com_TxIpduConfig[TxPduId];
    TxIpduBufferConfigPtr = &Com_TxIpduBufferConfig[TxPduId];
    for(Idx = TxIpduConfigPtr->SignalStartId;Idx <= TxIpduConfigPtr->SignalEndId; Idx++)
    {
        TxSignalConfigPtr = &Com_TxSignalConfig[Idx];
        if ( COM_NUM_OF_TX_SIGNAL_UB_ID > TxSignalConfigPtr->UBConfigId )
        {
            TxSignalUBPropsPtr = &Com_TxSignalUBConfig[TxSignalConfigPtr->UBConfigId];
            ByteOffset = TxIpduBufferConfigPtr->BufferStartId+TxSignalUBPropsPtr->UBBytePosition;
            Com_UtilSetClearBit(&Com_TxIpduBuffer[ByteOffset],TxSignalUBPropsPtr->UBBitPosition,FALSE);
        }
    }
}
#endif

#if (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/********************************************************************************************************************
*   Service Name     : Com_ProcessDeadlineMoitoring
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_ProcessDeadlineMoitoring(void)
{
    boolean IsTimeoutOccured ;
    PduIdType PduId;
    Com_SignalIdType SignalId;
    Com_TxIpduToutIdType CounterId;
    P2CONST(Com_TxIpduConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduConfigPtr;
    P2CONST(Com_TxSignalConfigType,AUTOMATIC,COM_APPL_CONST) TxSignalConfigPtr;
    Com_CbkTxToutFunctType TxToutFunctPtr;
    for (CounterId = 0; CounterId<COM_NUM_OF_TX_IPDU_TIMEOUT_COUNTER_ID ; CounterId++)
    {
        IsTimeoutOccured = FALSE;
        /* Check for timeout */
        if (Com_TxIpduTxTimeoutCounter[CounterId] != 0U)
        {
            Com_TxIpduTxTimeoutCounter[CounterId]--;
            if (Com_TxIpduTxTimeoutCounter[CounterId] == 0U)
            {
                IsTimeoutOccured = TRUE;
            }
        }

        if(IsTimeoutOccured == TRUE)
        {
            PduId = Com_TxIpduTimeoutCounterConfig[CounterId].TxIpduId;
            if(COM_NUM_OF_TX_IPDU_ID >PduId )
            {
                TxIpduConfigPtr = &Com_TxIpduConfig[PduId];
                /* Set the Repetition count & Minimum Delay counter to zero */
                Com_SetTxIpduRepetitionCount(PduId,0U);
                Com_SetTxIpduMinimumDelay(PduId,0U);
                /* Set the transmit request to FALSE */
                Com_SetTxIpduTransmitRequest(PduId,FALSE);
                /* Cancel lower layer transmit request if supported */
#if(COM_TX_IPDU_CANCELLATION_SUPPORT == STD_ON)
                if(TxIpduConfigPtr->IpduCancellationSupport == TRUE)
                {
                    (void) PduR_ComCancelTransmit(TxIpduConfigPtr->TargetIpduId);
                }
#endif
#if (COM_TX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT == STD_ON)
                /* Notify err function if any timeout is configured */
                for(SignalId=TxIpduConfigPtr->SignalStartId; SignalId<=TxIpduConfigPtr->SignalEndId; SignalId++)
                {
                    TxSignalConfigPtr = &Com_TxSignalConfig[SignalId];
                    if (COM_NUM_OF_TX_TOUT_FUNCTION > TxSignalConfigPtr->TxToutFunctId)
                    {
                        TxToutFunctPtr = Com_CbkTxToutFunctConfig[TxSignalConfigPtr->TxToutFunctId ];
                        if (TxToutFunctPtr != NULL_PTR)
                        {
                            (*TxToutFunctPtr)();
                        }
                    }
                }
#endif
            }
        }
    }
}
#endif

/********************************************************************************************************************
*   Service Name     : Com_ProcessTransmitRequest
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_ProcessTransmitRequest(void)
{
    PduIdType PduId;
    P2CONST(Com_TxIpduTxModeConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduTxModeConfigPtr;

    for(PduId = 0;PduId<COM_NUM_OF_TX_IPDU_ID;PduId++)
    {
        if (Com_GetTxIpduGroupActive(PduId) == TRUE)
        {
            /* Get the Mode configuration */
            if (Com_GetTxIpduTxMode(PduId) == COM_IPDU_TX_MODE_TYPE_TRUE)
            {
                TxIpduTxModeConfigPtr = &Com_TxIpduTxModeTrueConfig[PduId];
            }
            else
            {
                TxIpduTxModeConfigPtr = &Com_TxIpduTxModeFalseConfig[PduId];
            }

            /* process minimum Delay timer */
            if (Com_TxIpduMinimumDelayCounter[PduId] != 0U)
            {
                Com_TxIpduMinimumDelayCounter[PduId]--;
            }
            /* Process Cyclic timer */
            if (Com_GetTxIpduPeriodicTransmitRequest(PduId) != FALSE)
            {
                if (Com_TxIpduPeriodicCounter[PduId] != 0U)
                {
                    Com_TxIpduPeriodicCounter[PduId]--;
                    if(Com_TxIpduPeriodicCounter[PduId] == 0U)
                    {
                        Com_SetTxIpduPeriod(PduId,TxIpduTxModeConfigPtr->TimePeriod);
                        Com_SetTxIpduTransmitRequest(PduId,TRUE);
                    }
                }
            }

            /* Process Reption Cyclic timer */
            if (Com_TxIpduRepetitionCycleCounter[PduId] != 0U)
            {
                Com_TxIpduRepetitionCycleCounter[PduId]--;
                if (Com_TxIpduRepetitionCycleCounter[PduId] == 0U)
                {
                    Com_SetTxIpduRepetitionPeriod(PduId,TxIpduTxModeConfigPtr->RepetitionPeriod);
                    Com_SetTxIpduPeriod(PduId,TxIpduTxModeConfigPtr->TimePeriod);
                    Com_SetTxIpduTransmitRequest(PduId,TRUE);
                }
            }

            if ((Com_TxIpduMinimumDelayCounter[PduId] == 0U) && (Com_GetTxIpduTransmitRequest(PduId) == TRUE))
            {
                Com_EnterCriticalSection();
                if (E_OK == Com_IpduTxTransmit(PduId))
                {
                    Com_SetTxIpduTransmitRequest(PduId,FALSE);
                }
                Com_ExitCriticalSection();
            }
        }
    }
}

/********************************************************************************************************************
*   Service Name     : Com_IpduTxTransmit
********************************************************************************************************************/
COM_LOCAL FUNC(uint8,COM_CODE) Com_IpduTxTransmit(PduIdType TxPduId)
{
    uint8 TxResult = E_OK;
    PduInfoType PduInfo;
    P2CONST(Com_TxIpduConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduConfigPtr;
    P2CONST(Com_TxIpduBufferConfigType,AUTOMATIC,COM_APPL_CONST) TxIpduBufferConfigPtr;
    uint8 IpduData[1]={0};
#if(COM_TX_TP_IPDU_SUPPORT == STD_ON)
    P2CONST(Com_TxTpIpduBufferConfigType,AUTOMATIC,COM_APPL_CONST) TxTpIpduBufferConfigPtr;
#endif
#if(COM_TX_IPDU_CALLOUT_SUPPORT == STD_ON)
    Com_TxIpduCalloutFunctType IpduCalloutFunctPtr;
    boolean CalloutStatus = TRUE;
#endif
#if(COM_TX_IPDU_META_DATA_SUPPORT == STD_ON)
    Com_TxIpduBufferIdType Idx;
#endif
    if(COM_NUM_OF_TX_IPDU_ID > TxPduId )
    {
        TxIpduBufferConfigPtr = &Com_TxIpduBufferConfig[TxPduId];
        TxIpduConfigPtr = &Com_TxIpduConfig[TxPduId];
         /* set sdu data buffer */
        if (Com_GetTxIpduBufferLength(TxPduId)>0U)
        {
#if(COM_TX_TP_IPDU_SUPPORT == STD_ON)
            
            if(TxIpduConfigPtr->IpduType == COM_IPDU_TYPE_TP)
            {
                if(COM_NUM_OF_TX_TP_IPDU_ID > TxIpduConfigPtr->TpConfigId)
                {
                    TxTpIpduBufferConfigPtr = &Com_TxTpIpduBufferConfig[TxIpduConfigPtr->TpConfigId];
                    PduInfo.SduDataPtr = &Com_TxTpIpduBuffer[TxTpIpduBufferConfigPtr->BufferStartId];
                    Com_TxTpIpduBufferState[TxIpduConfigPtr->TpConfigId] = COM_TXTP_CONN_STATE_TRANSMIT_REQUEST;
                }
                else
                {
                    TxResult = E_NOT_OK;
                }
            }
            else
#endif
            {
                if (COM_TX_IPDU_BUFFER_SIZE > TxIpduBufferConfigPtr->BufferStartId)
                {
                    PduInfo.SduDataPtr = &Com_TxIpduBuffer[TxIpduBufferConfigPtr->BufferStartId];
                }
                else
                {
                    TxResult = E_NOT_OK;
                }
            }
        }
        else
        {
          /* added dummy data for coverity fix */
            PduInfo.SduDataPtr = &IpduData[0];
        }
        
        if(TxResult == E_OK)
        {
#if(COM_TX_IPDU_META_DATA_SUPPORT == STD_ON )
            /* set data length */
            if(TxIpduConfigPtr->IpduType == COM_IPDU_TYPE_NORMAL)
            {
                PduInfo.SduLength = Com_GetTxIpduBufferLength(TxPduId)+TxIpduBufferConfigPtr->MetaDataLength;
            }
            else
            {
                PduInfo.SduLength = Com_GetTxIpduBufferLength(TxPduId);
            }
#else
            PduInfo.SduLength = Com_GetTxIpduBufferLength(TxPduId);
#endif

#if(COM_TX_IPDU_CALLOUT_SUPPORT == STD_ON)
            if (COM_NUM_OF_TX_IPDU_CALLOUT_FUNC_ID > TxIpduConfigPtr->IpduCalloutFunctId)
            {
                IpduCalloutFunctPtr = Com_TxIpduCalloutFuncConfig[TxIpduConfigPtr->IpduCalloutFunctId];
                if (IpduCalloutFunctPtr!= NULL_PTR)
                {
                    CalloutStatus = (*IpduCalloutFunctPtr)(TxPduId, &PduInfo);
                }
            }
            if (CalloutStatus == TRUE)
#endif
            {
                /* Request transmit */
                TxResult = PduR_ComTransmit(TxIpduConfigPtr->TargetIpduId, &PduInfo);
                if (TxResult == E_OK)
                {
#if(COM_TX_SIGNAL_UB_SUPPORT == STD_ON)
                    /* Clear UpdateBit */
                    if (TxIpduConfigPtr->TxIpduClearUpdateBitType == COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_TRANSMIT)
                    {
                        Com_ClearUpdateBits(TxPduId);
                    }
#endif
                    #if (COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION == STD_ON)
                    /* Reload Minimum delay Timer and set wait for confirmation flag */
                    Com_SetTxIpduMinimumDelay(TxPduId,TxIpduConfigPtr->MinimumDelayTime);
                    #endif
                    Com_SetTxIpduConfirmationWait(TxPduId,TRUE);
                }
                else
                {
#if(COM_RETRY_FAILED_TRANSMIT_REQUESTS == STD_OFF)
                    #if (COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION == STD_ON)
                    /* Reload Minimum delay Timer and set wait for confirmation flag */
                    Com_SetTxIpduMinimumDelay(TxPduId,TxIpduConfigPtr->MinimumDelayTime);
                    #endif
                    Com_SetTxIpduTransmitRequest(TxPduId,FALSE);
#endif
                    Com_SetTxIpduConfirmationWait(TxPduId, FALSE);
                }
                #if (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON)
                /* The AUTOSAR COM shall start a configured transmission deadline monitoring timer 
                    if it is sent (within an I-PDU) to the lower layer, unless the timer is already running. */
                if ((COM_NUM_OF_TX_IPDU_TIMEOUT_COUNTER_ID > TxIpduConfigPtr->TxTimeoutCounterId) && 
                    (Com_GetTxIpduTxTimeoutCount(TxIpduConfigPtr->TxTimeoutCounterId) != 0U))
                {
                    Com_SetTxIpduTxTimeoutCount(TxIpduConfigPtr->TxTimeoutCounterId,TxIpduConfigPtr->TxTimeoutValue);
                }
                #endif
            }
#if(COM_TX_IPDU_META_DATA_SUPPORT == STD_ON)
            if(TxIpduConfigPtr->IpduType == COM_IPDU_TYPE_NORMAL)
            {
                for(Idx = TxIpduBufferConfigPtr->BufferEndId+1U;
                  ((Idx<=(TxIpduBufferConfigPtr->BufferEndId+TxIpduBufferConfigPtr->MetaDataLength)) && 
                  (COM_TX_IPDU_BUFFER_SIZE >(TxIpduBufferConfigPtr->BufferEndId+TxIpduBufferConfigPtr->MetaDataLength)));
                  Idx++)
                {
                    /* Set the Meta data default value */
                    Com_TxIpduBuffer[Idx] = Com_TxIpduBufferInitValues[Idx];
                }
            }
#endif
        }
    }
    else
    {
        TxResult = E_NOT_OK;
    }

    return TxResult;
}

/********************************************************************************************************************
*   Service Name     : Com_InitRxIpdu
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_InitRxIpdu(void)
{
    PduIdType RxIpduId;
#if (COM_RX_PDU_NO_GROUP_SUPPORT == STD_ON)
    P2CONST(Com_RxIpduConfigType,AUTOMATIC,COM_APPL_CONST) RxIpduConfigPtr;
#endif
    
    /* Initialize the Buffer properties */
    for (RxIpduId = 0U;RxIpduId < COM_NUM_OF_RX_IPDU_ID; RxIpduId++)
    {
        Com_InitRxIPduProperties(RxIpduId,TRUE);
        #if (COM_TX_PDU_NO_GROUP_SUPPORT == STD_ON)
        RxIpduConfigPtr = & Com_RxIpduConfig[RxIpduId];
        if (FALSE != RxIpduConfigPtr->NoIpduGroupSupported)
        {
            Com_RxDeadlineMonitoringControl(RxIpduId,TRUE,FALSE);
            /* Set the pduGroupActive to TRUE */
            Com_SetRxIpduGroupActive(RxIpduId,TRUE);
        }
        #endif
        {
            Com_RxDeadlineMonitoringControl(RxIpduId,FALSE,FALSE);
            /* Set the pduGroupActive to FALSE */
            Com_SetRxIpduGroupActive(RxIpduId,FALSE);
        }
    }
}

/********************************************************************************************************************
*   Service Name     : Com_InitRxIPduProperties
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_InitRxIPduProperties(PduIdType RxIpduId , boolean InitBuffer)
{
    Com_RxIpduBufferIdType BufferIdx;
    P2CONST(Com_RxIpduBufferConfigType,AUTOMATIC,COM_APPL_CONST) RxIpduBufferConfigPtr;
    P2CONST(Com_RxIpduConfigType,AUTOMATIC,COM_APPL_CONST) RxIpduConfigPtr;
    #if (COM_RX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON)
    Com_SignalGroupIdType SignalGroupIdx;
    P2CONST(Com_RxSignalGroupConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalGroupConfigPtr;
    #endif
    Com_SignalIdType SignalIdx;
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr;

    if(COM_NUM_OF_RX_IPDU_ID > RxIpduId)
    {
        RxIpduConfigPtr = &Com_RxIpduConfig[RxIpduId];
        if (FALSE != InitBuffer)
        {
            RxIpduBufferConfigPtr = &Com_RxIpduBufferConfig[RxIpduId];
            Com_SetRxIpduBufferLength(RxIpduId,RxIpduBufferConfigPtr->MinimumLength);
            for (BufferIdx = RxIpduBufferConfigPtr->BufferStartId;
                    ((BufferIdx <= RxIpduBufferConfigPtr->BufferEndId) && (COM_RX_IPDU_BUFFER_SIZE > BufferIdx));BufferIdx++)
            {
                Com_RxIpduBuffer[BufferIdx] = Com_RxIpduBufferInitValues[BufferIdx];
            }
            #if(COM_RX_IPDU_META_DATA_SUPPORT == STD_ON)
            /* Initialize MetaData */
            for(;BufferIdx<(RxIpduBufferConfigPtr->BufferEndId+RxIpduBufferConfigPtr->MetaDataLength);BufferIdx++)
            {
                Com_RxIpduBuffer[BufferIdx] = Com_RxIpduBufferInitValues[BufferIdx];
            }
            #endif
            
            for (SignalIdx = RxIpduConfigPtr->SignalStartId; ((SignalIdx <= RxIpduConfigPtr->SignalEndId) &&  (COM_NUM_OF_RX_SIGNAL_ID > SignalIdx));SignalIdx++)
            {
                RxSignalConfigPtr = &Com_RxSignalConfig[SignalIdx];
                Com_SetRxSignalInitValue(RxSignalConfigPtr);
            }
                
            /*! Initialize signal group array */
            #if (COM_RX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON)
            for (SignalGroupIdx = RxIpduConfigPtr->SignalGroupStartId;
                 SignalGroupIdx <= RxIpduConfigPtr->SignalGroupEndId;SignalGroupIdx++)
            {
                RxSignalGroupConfigPtr = &Com_RxSignalGroupConfig[SignalGroupIdx];
                BufferIdx = RxSignalGroupConfigPtr->SignalGroupArrayBufferIdx;
                if (COM_RX_SIGNAL_GROUP_RTE_ARRAY_BUFFER_SIZE > BufferIdx)
                {
                    Com_UtilMemCopy(&Com_RxSignalGroupRteArrayBuffer[BufferIdx],
                            &Com_RxSignalGroupRteArrayInitBuffer[BufferIdx],
                            RxSignalGroupConfigPtr->ByteLength);
                }
            }
            #endif
        }
        Com_SetRxIpduDeferredProcessing(RxIpduId,FALSE);
        #if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
        if (COM_NUM_OF_RX_TP_IPDU_ID > RxIpduConfigPtr->RxTpId)
        {
            Com_RxTpIpduResetConnection(RxIpduConfigPtr->RxTpId);
        }
        #endif
    }
}

/********************************************************************************************************************
*   Service Name     : Com_DeactivateRxIpdu
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_DeactivateRxIpdu(PduIdType RxIpduId)
{
        Com_RxDeadlineMonitoringControl(RxIpduId,FALSE,FALSE);
        Com_SetRxIpduDeferredProcessing(RxIpduId,FALSE);
        Com_SetRxIpduGroupActive(RxIpduId,FALSE);
}

/********************************************************************************************************************
*   Service Name     : Com_ActivateRxIpdu
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_ActivateRxIpdu(PduIdType RxIpduId , boolean Initialize)
{
    if(COM_NUM_OF_RX_IPDU_ID > RxIpduId)
    {
        /* Initialize the Rx buffers and enable the timeouts and the DM state */
        Com_InitRxIPduProperties(RxIpduId,Initialize);
        /* Intialize the Deadline monitoring */
        Com_RxDeadlineMonitoringControl(RxIpduId,TRUE,FALSE);
        /*clear deferred processing flag */
        Com_SetRxIpduDeferredProcessing(RxIpduId,FALSE);
        /* Activate the Ipdu group */
        Com_SetRxIpduGroupActive(RxIpduId,TRUE);
    }
}


#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
/********************************************************************************************************************
*   Service Name     : Com_RxTpIpduResetConnection
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_RxTpIpduResetConnection(PduIdType RxTpIpduId)
{
    if(COM_NUM_OF_RX_TP_IPDU_ID > RxTpIpduId)
    {
        Com_SetRxTpIpduConnectionState(RxTpIpduId,COM_RXTP_CONN_STATE_IDLE);
        Com_SetRxTpIpduBytesCopied(RxTpIpduId,0);
    }

}
#endif

/********************************************************************************************************************
*   Service Name     : Com_RxIndicationProcessing
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_RxIndicationProcessing
(
    PduIdType RxIpduId , 
    P2CONST(PduInfoType,AUTOMATIC,COM_APPL_CONST) PduInfoPtr
)
{
    PduLengthType BufferLength;
    P2CONST(Com_RxIpduConfigType,AUTOMATIC,COM_APPL_CONST) RxIpduConfigPtr;
    P2CONST(Com_RxIpduBufferConfigType,AUTOMATIC,COM_APPL_CONST) RxIpduBufferConfigPtr;
#if(COM_RX_IPDU_CALLOUT_SUPPORT == STD_ON)
    Com_RxIpduCalloutFunctType Com_RxIpduCalloutFunctPtr;
    boolean CalloutStatus=TRUE;
#endif
    if ((COM_NUM_OF_RX_IPDU_ID>RxIpduId) && (PduInfoPtr != NULL_PTR))
    {
        RxIpduConfigPtr = &Com_RxIpduConfig[RxIpduId];
        if(Com_GetRxIpduGroupActive(RxIpduId) == TRUE)
        {
#if(COM_RX_IPDU_CALLOUT_SUPPORT == STD_ON)
            /* Invoke IpduCallout if configured */
            if (COM_NUM_OF_RX_IPDU_CALLOUT_FUNC_ID > RxIpduConfigPtr->IpduCalloutFunctId)
            {
                Com_RxIpduCalloutFunctPtr = Com_RxIpduCalloutFunctConfig[RxIpduConfigPtr->IpduCalloutFunctId];
                if (NULL_PTR != Com_RxIpduCalloutFunctPtr)
                {
                    CalloutStatus = (*Com_RxIpduCalloutFunctPtr)(RxIpduId,PduInfoPtr);
                }
            }
            if (CalloutStatus == TRUE)
#endif
            {

                /* Copy data to buffer  */
                if (RxIpduConfigPtr->IpduType == COM_IPDU_TYPE_NORMAL)
                {
                    RxIpduBufferConfigPtr = &Com_RxIpduBufferConfig[RxIpduId];
                    if(PduInfoPtr->SduLength > Com_RxIpduBufferConfig[RxIpduId].MaximumLength)
                    {
                        BufferLength =  Com_RxIpduBufferConfig[RxIpduId].MaximumLength;                                         
                    }
                    else
                    {
                        BufferLength = PduInfoPtr->SduLength;
                    }
                    if ((PduInfoPtr->SduDataPtr != NULL_PTR) && 
                        ( COM_RX_IPDU_BUFFER_SIZE > (RxIpduBufferConfigPtr->BufferStartId+BufferLength-1U)))
                    {
                        Com_UtilMemCopy(&Com_RxIpduBuffer[RxIpduBufferConfigPtr->BufferStartId],
                                        PduInfoPtr->SduDataPtr,BufferLength);
                    }
                    Com_SetRxIpduBufferLength(RxIpduId,BufferLength);
                } /* For Tp the data buffer is already copied in Copy data*/

                if (RxIpduConfigPtr->IpduSignalProcessingType == COM_IPDU_SIGNAL_PROCESSING_TYPE_IMMEDIATE )
                {
                    Com_RxIpduProcessing(RxIpduId);
                }
                else
                {
                    Com_SetRxIpduDeferredProcessing(RxIpduId,TRUE);
                }
            }
        }
    }
}

/*****************************************************************************************************************
* Service Name     : Com_ReceiveSignalProcessing
*****************************************************************************************************************/
COM_LOCAL_INLINE FUNC(uint8,COM_CODE) Com_ReceiveSignalProcessing
(
    Com_SignalIdType SignalId ,
    P2CONST(void,AUTOMATIC,COM_APPL_CONST) SignalDataPtr
)
{
    uint8 ReturnValue = COM_SERVICE_NOT_AVAILABLE;
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr;
    Com_RxRteBufferIdType RteBufferIndex = COM_RX_SIGNAL_RTE_INVALID_BUFFER_IDX;

    #ifdef COM_ENABLE_EXTENDED_COV_CHECK
    /* Check added to resolve coverity Out of bound Warning */
    if (COM_NUM_OF_RX_SIGNAL_ID > SignalId)
    #endif
    {
        /* Get Signal Configuration */
        RxSignalConfigPtr = &Com_RxSignalConfig[SignalId];
        #ifdef COM_ENABLE_EXTENDED_COV_CHECK
        /* Check added to resolve coverity Out of bound Warning */
        if (COM_NUM_OF_RX_IPDU_ID > RxSignalConfigPtr->ComPduId)            
        #endif
        {
            RteBufferIndex = RxSignalConfigPtr->RteBufferIdx ;
            Com_EnterCriticalSection();
            /* Copy data from the Rte signal buffer */
            switch(RxSignalConfigPtr->SignalType)
            {
                case COM_SIGNALTYPE_BOOLEAN:
                case COM_SIGNALTYPE_UINT8:
                case COM_SIGNALTYPE_SINT8:
                    #ifdef COM_ENABLE_EXTENDED_COV_CHECK
                    if (COM_RX_SIGNAL_RTE_U8BUFFER_SIZE > RteBufferIndex )
                    #endif
                    {
                        *(uint8 *)SignalDataPtr = Com_RxSignalRteU8Buffer[RteBufferIndex];
                        ReturnValue = E_OK;
                    }
                    break;
                case COM_SIGNALTYPE_UINT16:
                case COM_SIGNALTYPE_SINT16:
                    #ifdef COM_ENABLE_EXTENDED_COV_CHECK
                    if (COM_RX_SIGNAL_RTE_U16BUFFER_SIZE > RteBufferIndex )
                    #endif
                    {
                        *(uint16 *)SignalDataPtr = Com_RxSignalRteU16Buffer[RteBufferIndex];
                        ReturnValue = E_OK;
                    }
                    break;
                case COM_SIGNALTYPE_UINT32:
                case COM_SIGNALTYPE_SINT32:
                case COM_SIGNALTYPE_FLOAT32:
                    #ifdef COM_ENABLE_EXTENDED_COV_CHECK
                    if (COM_RX_SIGNAL_RTE_U32BUFFER_SIZE > RteBufferIndex )
                    #endif
                    {
                        *(uint32 *)SignalDataPtr = Com_RxSignalRteU32Buffer[RteBufferIndex];
                        ReturnValue = E_OK;
                    }
                    break;
                case COM_SIGNALTYPE_UINT64:
                case COM_SIGNALTYPE_SINT64:
                case COM_SIGNALTYPE_FLOAT64:
                    #ifdef COM_ENABLE_EXTENDED_COV_CHECK
                    if (COM_RX_SIGNAL_RTE_U64BUFFER_SIZE > RteBufferIndex )
                    #endif
                    {
                        *(uint64 *)SignalDataPtr = Com_RxSignalRteU64Buffer[RteBufferIndex];
                        ReturnValue = E_OK;
                    }
                    break;
                case COM_SIGNALTYPE_UINT8_N:    
                    /* COM_SIGNALTYPE_UINT8_N */
                    #ifdef COM_ENABLE_EXTENDED_COV_CHECK
                    if ((COM_RX_SIGNAL_RTE_ARRBUFFER_SIZE > RteBufferIndex ) &&
                        (COM_RX_SIGNAL_RTE_ARRBUFFER_SIZE >= (RxSignalConfigPtr->ByteLength+RteBufferIndex)))
                    #endif
                    {
                        Com_UtilMemCopy((uint8*)SignalDataPtr,&Com_RxSignalRteArrBuffer[RteBufferIndex],RxSignalConfigPtr->ByteLength);
                        ReturnValue = E_OK;
                    }
                    break;
                default:
                    /* Do Nothing*/
                    break;
            } 
            Com_ExitCriticalSection();
            if (Com_GetRxIpduGroupActive(RxSignalConfigPtr->ComPduId) != TRUE)
            {
                ReturnValue = COM_SERVICE_NOT_AVAILABLE;
            }
        }
    }
    return ReturnValue;
}

#if(COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON)
/********************************************************************************************************************
*   Service Name     : Com_ProcessTxSignalFilterState
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessTxSignalFilterState
(
    Com_TxSignalFilterIdType TxSignalFilterId , 
    Com_SignalIdType SignalId , 
    P2CONST(void,AUTOMATIC,COM_APPL_CONST) SignalDataPtr)
{
    boolean FilterResult=TRUE;
    boolean oldDataBool=FALSE;
    uint8 oldData8=0U;
    uint16 oldData16=0U;
    uint32 oldData32=0U;
    uint64 oldData64=0U;
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr;
    P2CONST(Com_TxSignalConfigType,AUTOMATIC,COM_APPL_CONST) TxSignalConfigPtr;

    TxSignalConfigPtr = &Com_TxSignalConfig[SignalId];
    if (COM_NUM_OF_TX_SIGNAL_FILTER_ID > TxSignalFilterId)
    {
        FilterConfigPtr = &Com_TxSignalFilterConfig[TxSignalFilterId];
        switch(TxSignalConfigPtr->SignalType)
        {
            case COM_SIGNALTYPE_BOOLEAN:
                Com_ReadTxSignalFromIpdu(SignalId,(void *)&oldDataBool);
                FilterResult = Com_ProcessBooleanSignalFilter(oldDataBool,(boolean *)SignalDataPtr,FilterConfigPtr);
                break;
            case COM_SIGNALTYPE_UINT8:
                Com_ReadTxSignalFromIpdu(SignalId,(void *)&oldData8);
                FilterResult = Com_ProcessUint8SignalFilter(oldData8,(uint8 *)SignalDataPtr,FilterConfigPtr);
                break;
            case COM_SIGNALTYPE_SINT8:
                Com_ReadTxSignalFromIpdu(SignalId,(void *)&oldData8);
                FilterResult = Com_ProcessSint8SignalFilter((sint8)oldData8,(sint8 *)SignalDataPtr,FilterConfigPtr);
                break;
            case COM_SIGNALTYPE_UINT16:
                Com_ReadTxSignalFromIpdu(SignalId,(void *)&oldData16);
                FilterResult = Com_ProcessUint16SignalFilter(oldData16,(uint16 *)SignalDataPtr,FilterConfigPtr);
                break;
            case COM_SIGNALTYPE_SINT16:
                Com_ReadTxSignalFromIpdu(SignalId,(void *)&oldData16);
                FilterResult = Com_ProcessSint16SignalFilter((sint16)oldData16,(sint16 *)SignalDataPtr,FilterConfigPtr);
                break;
            case COM_SIGNALTYPE_UINT32:
                Com_ReadTxSignalFromIpdu(SignalId,(void *)&oldData32);
                FilterResult = Com_ProcessUint32SignalFilter(oldData32,(uint32 *)SignalDataPtr,FilterConfigPtr);
                break;
            case COM_SIGNALTYPE_SINT32:
                Com_ReadTxSignalFromIpdu(SignalId,(void *)&oldData32);
                FilterResult = Com_ProcessSint32SignalFilter((sint32)oldData32,(sint32 *)SignalDataPtr,FilterConfigPtr);
                break;
            case COM_SIGNALTYPE_UINT64:
                Com_ReadTxSignalFromIpdu(SignalId,(void *)&oldData64);
                FilterResult = Com_ProcessUint64SignalFilter(oldData64,(uint64 *)SignalDataPtr,FilterConfigPtr);
                break;
            case COM_SIGNALTYPE_SINT64:
                Com_ReadTxSignalFromIpdu(SignalId,(void *)&oldData64);
                FilterResult = Com_ProcessSint64SignalFilter((sint64)oldData64,(sint64 *)SignalDataPtr,FilterConfigPtr);
                break;
#if(COM_SIGNAL_TYPE_FLOAT32_SUPPORT == STD_ON)
            case COM_SIGNALTYPE_FLOAT32:
                if (COM_FILTER_ALGORITHM_TYPE_ALWAYS !=  FilterConfigPtr->FilterAlgorithmType)
                {
                    FilterResult = FALSE;
                }
                break;
#endif
#if(COM_SIGNAL_TYPE_FLOAT64_SUPPORT == STD_ON)
            case COM_SIGNALTYPE_FLOAT64:
                if (COM_FILTER_ALGORITHM_TYPE_ALWAYS !=  FilterConfigPtr->FilterAlgorithmType)
                {
                    FilterResult = FALSE;
                }
                break;
#endif
            case COM_SIGNALTYPE_UINT8_DYN:
                if (COM_FILTER_ALGORITHM_TYPE_ALWAYS !=  FilterConfigPtr->FilterAlgorithmType)
                {
                    FilterResult = FALSE;
                }
                break;
            case COM_SIGNALTYPE_UINT8_N:
                if (COM_FILTER_ALGORITHM_TYPE_ALWAYS !=  FilterConfigPtr->FilterAlgorithmType)
                {
                    FilterResult = FALSE;
                }
                break;
            default:
                FilterResult = TRUE;
                break;
        }
    }
    return FilterResult;
}
#endif

#if((COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON) || (COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON))
/********************************************************************************************************************
*   Service Name     : Com_ProcessBooleanSignalFilter
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessBooleanSignalFilter
(
    boolean SignalOldValue , 
    P2CONST(boolean,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr
)
{
    boolean FilterResult = FALSE;
    boolean SignalNewValue;
    boolean SignalMaskValue;
    boolean SignalXValue;
    Com_FilterAlgorithmType FilterAlgorithm;

    SignalNewValue  = *SignalDataPtr;
    FilterAlgorithm = FilterConfigPtr->FilterAlgorithmType;
    if (COM_NUM_OF_BOOLEAN_FILTER_MASK_ID > FilterConfigPtr->FilterMaskBufferId)
    {
        SignalMaskValue = Com_BooleanFilterMaskValueConfig[FilterConfigPtr->FilterMaskBufferId];
    }
    else
    {
        SignalMaskValue = 0U;
    }
    
    if (COM_NUM_OF_BOOLEAN_FILTER_X_ID > FilterConfigPtr->FilterXBufferId)
    {
        SignalXValue    = Com_BooleanFilterXValueConfig[FilterConfigPtr->FilterXBufferId];
    }
    else
    {
        SignalXValue = 0U;
    }

    switch(FilterAlgorithm)
    {
        case COM_FILTER_ALGORITHM_TYPE_ALWAYS:
            FilterResult = TRUE;
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_X:
            /* new_value&mask) != x */
            if ((SignalNewValue & SignalMaskValue) != SignalXValue)
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_EQUALS_X:
            /* (new_value&mask) == x  */
            /* new_value&mask) != x */
            if ((SignalNewValue & SignalMaskValue) == SignalXValue)
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_MASKED_OLD:
            /* (new_value&mask) != (old_value&mask) */
            if ((SignalOldValue & SignalMaskValue) != (SignalNewValue & SignalMaskValue))
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_ONE_EVERY_N:
            FilterResult = TRUE; /* Not Implemented Always return True .*/
            break;
        default: /* COM_FILTER_ALGORITHM_TYPE_NEVER */
            FilterResult = FALSE;
            break;
    }
    return FilterResult;
}
#endif

#if((COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON) || (COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON))
/********************************************************************************************************************
*   Service Name     : Com_ProcessUint8SignalFilter
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessUint8SignalFilter
(
    uint8 SignalOldValue ,
    P2CONST(uint8,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr
)
{
    boolean FilterResult = FALSE;
    uint8 SignalNewValue;
    uint8 SignalMaskValue;
    uint8 SignalXValue;
    uint8 MinValue;
    uint8 MaxValue;
    Com_FilterAlgorithmType FilterAlgorithm;

    SignalNewValue = *SignalDataPtr;
    FilterAlgorithm = FilterConfigPtr->FilterAlgorithmType;
    if ((FilterConfigPtr->FilterMaskBufferId < COM_NUM_OF_UINT8_FILTER_MASK_ID) && (FilterConfigPtr->FilterXBufferId < COM_NUM_OF_UINT8_FILTER_X_ID))
    {
        SignalMaskValue = Com_Uint8FilterMaskValueConfig[FilterConfigPtr->FilterMaskBufferId];
        SignalXValue = Com_Uint8FilterXValueConfig[FilterConfigPtr->FilterXBufferId];
    }
    else
    {
        FilterAlgorithm = COM_FILTER_ALGORITHM_TYPE_ALWAYS;
    }
    switch(FilterAlgorithm)
    {
        case COM_FILTER_ALGORITHM_TYPE_ALWAYS:
            FilterResult = TRUE;
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_MASKED_OLD:
            /* (new_value&mask) != (old_value&mask) */
            if ((SignalOldValue & SignalMaskValue) != (SignalNewValue&SignalMaskValue))
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_X:
            /* new_value&mask) != x */
            if ((SignalNewValue & SignalMaskValue) != SignalXValue)
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_EQUALS_X:
            /* (new_value&mask) == x  */
            /* new_value&mask) != x */
            if ((SignalNewValue & SignalMaskValue) == SignalXValue)
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_NEW_IS_WITHIN:
            MinValue = Com_Uint8FilterMinValueConfig[FilterConfigPtr->FilterMinBufferId];
            MaxValue = Com_Uint8FilterMaxValueConfig[FilterConfigPtr->FilterMaxBufferId];
            /*  min <= new_value <= max */
            if ((MinValue <= SignalNewValue) && (SignalNewValue <= MaxValue))
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_NEW_IS_OUTSIDE:
            MinValue = Com_Uint8FilterMinValueConfig[FilterConfigPtr->FilterMinBufferId];
            MaxValue = Com_Uint8FilterMaxValueConfig[FilterConfigPtr->FilterMaxBufferId];
            /* (min > new_value) OR (new_value > max) */
            /*  min <= new_value <= max */
            if ((MinValue <= SignalNewValue) && (SignalNewValue <= MaxValue))
            {
                FilterResult = FALSE;
            }
            else
            {
                FilterResult = TRUE;
            }
            
            break;

        case COM_FILTER_ALGORITHM_TYPE_ONE_EVERY_N:
            FilterResult = TRUE; /* Not Implemented Always return True .*/
            break;

        default: /* COM_FILTER_ALGORITHM_TYPE_NEVER */
            FilterResult = FALSE;
            break;
    }
    return FilterResult;
}
#endif

#if((COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON) || (COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON))
/********************************************************************************************************************
*   Service Name     : Com_ProcessSint8SignalFilter
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessSint8SignalFilter
(
    sint8 SignalOldValue , 
    P2CONST(sint8,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr
)
{
    boolean FilterResult = FALSE;
    sint8 SignalNewValue;
    sint8 SignalMaskValue;
    sint8 SignalXValue;
    sint8 MinValue;
    sint8 MaxValue;
    Com_FilterAlgorithmType FilterAlgorithm;

    SignalNewValue = *SignalDataPtr;
    FilterAlgorithm = FilterConfigPtr->FilterAlgorithmType;
    if((FilterConfigPtr->FilterMaskBufferId < COM_NUM_OF_SINT8_FILTER_MASK_ID) && (FilterConfigPtr->FilterXBufferId < COM_NUM_OF_SINT8_FILTER_X_ID))
    {
        SignalMaskValue = Com_Sint8FilterMaskValueConfig[FilterConfigPtr->FilterMaskBufferId];
        SignalXValue = Com_Sint8FilterXValueConfig[FilterConfigPtr->FilterXBufferId];
    }
    else
    {
        FilterAlgorithm = COM_FILTER_ALGORITHM_TYPE_NEVER;
    }
    switch(FilterAlgorithm)
    {
        case COM_FILTER_ALGORITHM_TYPE_ALWAYS:
            FilterResult = TRUE;
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_MASKED_OLD:
            /* (new_value&mask) != (old_value&mask) */
            if ((SignalOldValue & SignalMaskValue) != (SignalNewValue & SignalMaskValue))
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_X:
            /* new_value&mask) != x */
            if ((SignalNewValue & SignalMaskValue) != SignalXValue)
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_EQUALS_X:
            /* (new_value&mask) == x  */
            /* new_value&mask) != x */
            if ((SignalNewValue & SignalMaskValue) == SignalXValue)
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_NEW_IS_WITHIN:
            if ((FilterConfigPtr->FilterMinBufferId < COM_NUM_OF_SINT8_FILTER_MIN_ID) && (FilterConfigPtr->FilterMaxBufferId < COM_NUM_OF_SINT8_FILTER_MAX_ID))
            {
                MinValue = Com_Sint8FilterMinValueConfig[FilterConfigPtr->FilterMinBufferId];
                MaxValue = Com_Sint8FilterMaxValueConfig[FilterConfigPtr->FilterMaxBufferId];
                /*  min <= new_value <= max */
                if ((MinValue <= SignalNewValue) && (SignalNewValue <= MaxValue))
                {
                    FilterResult = TRUE;
                }
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_NEW_IS_OUTSIDE:
            if((COM_NUM_OF_SINT8_FILTER_MIN_ID > FilterConfigPtr->FilterMinBufferId ) && (COM_NUM_OF_SINT8_FILTER_MAX_ID > FilterConfigPtr->FilterMaxBufferId ))
            {
                MinValue = Com_Sint8FilterMinValueConfig[FilterConfigPtr->FilterMinBufferId];
                MaxValue = Com_Sint8FilterMaxValueConfig[FilterConfigPtr->FilterMaxBufferId];
                /* (min > new_value) OR (new_value > max) */
                if ((MinValue <= SignalNewValue) && (SignalNewValue <= MaxValue))
                {
                    FilterResult = FALSE;
                }
                else
                {
                    FilterResult = TRUE;
                }
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_ONE_EVERY_N:
            FilterResult = TRUE; /* Not Implemented Always return True .*/
            break;

        default: /* COM_FILTER_ALGORITHM_TYPE_NEVER */
            FilterResult = FALSE;
            break;
    }
    return FilterResult;
}
#endif

#if((COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON) || (COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON))
/********************************************************************************************************************
*   Service Name     : Com_ProcessUint16SignalFilter
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessUint16SignalFilter
(
    uint16 SignalOldValue , 
    P2CONST(uint16,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr
)
{
    boolean FilterResult = FALSE;
    uint16 SignalNewValue;
    uint16 SignalMaskValue;
    uint16 SignalXValue;
    uint16 MinValue;
    uint16 MaxValue;
    Com_FilterAlgorithmType FilterAlgorithm;

    SignalNewValue = *SignalDataPtr;
    FilterAlgorithm = FilterConfigPtr->FilterAlgorithmType;
    if((FilterConfigPtr->FilterMaskBufferId < COM_NUM_OF_UINT16_FILTER_MASK_ID) && (FilterConfigPtr->FilterXBufferId < COM_NUM_OF_UINT16_FILTER_X_ID))
    {
        SignalMaskValue = Com_Uint16FilterMaskValueConfig[FilterConfigPtr->FilterMaskBufferId];
        SignalXValue = Com_Uint16FilterXValueConfig[FilterConfigPtr->FilterXBufferId];
    }
    else
    {
        FilterAlgorithm = COM_FILTER_ALGORITHM_TYPE_ALWAYS;
    }
    switch(FilterAlgorithm)
    {
        case COM_FILTER_ALGORITHM_TYPE_ALWAYS:
            FilterResult = TRUE;
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_MASKED_OLD:
            /* (new_value&mask) != (old_value&mask) */
            if ((SignalOldValue & SignalMaskValue) != (SignalNewValue & SignalMaskValue))
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_X:
            /* new_value&mask) != x */
            if ((SignalNewValue & SignalMaskValue) != SignalXValue)
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_EQUALS_X:
            /* (new_value&mask) == x  */
            /* new_value&mask) != x */
            if ((SignalNewValue & SignalMaskValue) == SignalXValue)
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_NEW_IS_WITHIN:
            if((FilterConfigPtr->FilterMinBufferId < COM_NUM_OF_UINT16_FILTER_MIN_ID) && (FilterConfigPtr->FilterMaxBufferId < COM_NUM_OF_UINT16_FILTER_MAX_ID))
            {
                MinValue = Com_Uint16FilterMinValueConfig[FilterConfigPtr->FilterMinBufferId];
                MaxValue = Com_Uint16FilterMaxValueConfig[FilterConfigPtr->FilterMaxBufferId];
                /*  min <= new_value <= max */
                if ((MinValue <= SignalNewValue) && (SignalNewValue <= MaxValue))
                {
                    FilterResult = TRUE;
                }
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_NEW_IS_OUTSIDE:
            if((FilterConfigPtr->FilterMinBufferId < COM_NUM_OF_UINT16_FILTER_MIN_ID) && (FilterConfigPtr->FilterMaxBufferId < COM_NUM_OF_UINT16_FILTER_MAX_ID))
            {
                MinValue = Com_Uint16FilterMinValueConfig[FilterConfigPtr->FilterMinBufferId];
                MaxValue = Com_Uint16FilterMaxValueConfig[FilterConfigPtr->FilterMaxBufferId];
                /* (min > new_value) OR (new_value > max) */
                if ((MinValue <= SignalNewValue) && (SignalNewValue <= MaxValue))
                {
                    FilterResult = FALSE;
                }
                else
                {
                    FilterResult = TRUE;
                }
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_ONE_EVERY_N:
            FilterResult = TRUE; /* Not Implemented Always return True .*/
            break;

        default: /* COM_FILTER_ALGORITHM_TYPE_NEVER */
            FilterResult = FALSE;
            break;
    }
    return FilterResult;
}
#endif

#if((COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON) || (COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON))
/********************************************************************************************************************
*   Service Name     : Com_ProcessSint16SignalFilter
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessSint16SignalFilter
(
    sint16 SignalOldValue , 
    P2CONST(sint16,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr
)
{
    boolean FilterResult = FALSE;
    sint16 SignalNewValue;
    sint16 SignalMaskValue;
    sint16 SignalXValue;
    sint16 MinValue;
    sint16 MaxValue;
    Com_FilterAlgorithmType FilterAlgorithm;

    SignalNewValue = *SignalDataPtr;
    FilterAlgorithm = FilterConfigPtr->FilterAlgorithmType;
    SignalMaskValue = Com_Sint16FilterMaskValueConfig[FilterConfigPtr->FilterMaskBufferId];
    SignalXValue = Com_Sint16FilterXValueConfig[FilterConfigPtr->FilterXBufferId];

    switch(FilterAlgorithm)
    {
        case COM_FILTER_ALGORITHM_TYPE_ALWAYS:
            FilterResult = TRUE;
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_MASKED_OLD:
            /* (new_value&mask) != (old_value&mask) */
            if ((SignalOldValue & SignalMaskValue) != (SignalNewValue & SignalMaskValue))
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_X:
            /* new_value&mask) != x */
            if ((SignalNewValue & SignalMaskValue) != SignalXValue)
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_EQUALS_X:
            /* (new_value&mask) == x  */
            /* new_value&mask) != x */
            if ((SignalNewValue & SignalMaskValue) == SignalXValue)
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_NEW_IS_WITHIN:
            MinValue = Com_Sint16FilterMinValueConfig[FilterConfigPtr->FilterMinBufferId];
            MaxValue = Com_Sint16FilterMaxValueConfig[FilterConfigPtr->FilterMaxBufferId];
            /*  min <= new_value <= max */
            if ((MinValue <= SignalNewValue) && (SignalNewValue <= MaxValue))
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_NEW_IS_OUTSIDE:
            MinValue = Com_Sint16FilterMinValueConfig[FilterConfigPtr->FilterMinBufferId];
            MaxValue = Com_Sint16FilterMaxValueConfig[FilterConfigPtr->FilterMaxBufferId];
            /* (min > new_value) OR (new_value > max) */
            if ((MinValue <= SignalNewValue) && (SignalNewValue <= MaxValue))
            {
                FilterResult = FALSE;
            }
            else
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_ONE_EVERY_N:
            FilterResult = TRUE; /* Not Implemented Always return True .*/
            break;

        default: /* COM_FILTER_ALGORITHM_TYPE_ALWAYS */
            FilterResult = FALSE;
            break;
    }
    return FilterResult;
}
#endif

#if((COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON) || (COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON))
/********************************************************************************************************************
*   Service Name     : Com_ProcessUint32SignalFilter
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessUint32SignalFilter
(
    uint32 SignalOldValue , 
    P2CONST(uint32,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr
)
{
    boolean FilterResult = FALSE;
    uint32 SignalNewValue;
    uint32 SignalMaskValue;
    uint32 SignalXValue;
    uint32 MinValue;
    uint32 MaxValue;
    Com_FilterAlgorithmType FilterAlgorithm;

    SignalNewValue = *SignalDataPtr;
    FilterAlgorithm = FilterConfigPtr->FilterAlgorithmType;
    SignalMaskValue = Com_Uint32FilterMaskValueConfig[FilterConfigPtr->FilterMaskBufferId];
    SignalXValue = Com_Uint32FilterXValueConfig[FilterConfigPtr->FilterXBufferId];

    switch(FilterAlgorithm)
    {
        case COM_FILTER_ALGORITHM_TYPE_ALWAYS:
            FilterResult = TRUE;
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_MASKED_OLD:
            /* (new_value&mask) != (old_value&mask) */
            if ((SignalOldValue & SignalMaskValue) != (SignalNewValue & SignalMaskValue))
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_X:
            /* new_value&mask) != x */
            if ((SignalNewValue & SignalMaskValue) != SignalXValue)
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_EQUALS_X:
            /* (new_value&mask) == x  */
            /* new_value&mask) != x */
            if ((SignalNewValue & SignalMaskValue) == SignalXValue)
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_NEW_IS_WITHIN:
            MinValue = Com_Uint32FilterMinValueConfig[FilterConfigPtr->FilterMinBufferId];
            MaxValue = Com_Uint32FilterMaxValueConfig[FilterConfigPtr->FilterMaxBufferId];
            /*  min <= new_value <= max */
            if ((MinValue <= SignalNewValue) && (SignalNewValue <= MaxValue))
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_NEW_IS_OUTSIDE:
            MinValue = Com_Uint32FilterMinValueConfig[FilterConfigPtr->FilterMinBufferId];
            MaxValue = Com_Uint32FilterMaxValueConfig[FilterConfigPtr->FilterMaxBufferId];
            /* (min > new_value) OR (new_value > max) */
            if ((MinValue <= SignalNewValue) && (SignalNewValue <= MaxValue))
            {
                FilterResult = FALSE;
            }
            else
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_ONE_EVERY_N:
            FilterResult = TRUE; /* Not Implemented Always return True .*/
            break;

        default: /* COM_FILTER_ALGORITHM_TYPE_ALWAYS */
            FilterResult = FALSE;
            break;
    }
    return FilterResult;
}
#endif

#if((COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON) || (COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON))
/********************************************************************************************************************
*   Service Name     : Com_ProcessSint32SignalFilter
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessSint32SignalFilter
(
    sint32 SignalOldValue , 
    P2CONST(sint32,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr
)
{
    boolean FilterResult = FALSE;
    sint32 SignalNewValue;
    sint32 SignalMaskValue;
    sint32 SignalXValue;
    sint32 MinValue;
    sint32 MaxValue;
    Com_FilterAlgorithmType FilterAlgorithm;

    SignalNewValue = *SignalDataPtr;
    FilterAlgorithm = FilterConfigPtr->FilterAlgorithmType;
    SignalMaskValue = Com_Sint32FilterMaskValueConfig[FilterConfigPtr->FilterMaskBufferId];
    SignalXValue = Com_Sint32FilterXValueConfig[FilterConfigPtr->FilterXBufferId];

    switch(FilterAlgorithm)
    {
        case COM_FILTER_ALGORITHM_TYPE_ALWAYS:
            FilterResult = TRUE;
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_MASKED_OLD:
            /* (new_value&mask) != (old_value&mask) */
            if ((SignalOldValue & SignalMaskValue) != (SignalNewValue & SignalMaskValue))
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_X:
            /* new_value&mask) != x */
            if ((SignalNewValue & SignalMaskValue) != SignalXValue)
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_EQUALS_X:
            /* (new_value&mask) == x  */
            /* new_value&mask) != x */
            if ((SignalNewValue & SignalMaskValue) == SignalXValue)
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_NEW_IS_WITHIN:
            MinValue = Com_Sint32FilterMinValueConfig[FilterConfigPtr->FilterMinBufferId];
            MaxValue = Com_Sint32FilterMaxValueConfig[FilterConfigPtr->FilterMaxBufferId];
            /*  min <= new_value <= max */
            if ((MinValue <= SignalNewValue) && (SignalNewValue <= MaxValue))
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_NEW_IS_OUTSIDE:
            MinValue = Com_Sint32FilterMinValueConfig[FilterConfigPtr->FilterMinBufferId];
            MaxValue = Com_Sint32FilterMaxValueConfig[FilterConfigPtr->FilterMaxBufferId];
            /* (min > new_value) OR (new_value > max) */
            if ((MinValue <= SignalNewValue) && (SignalNewValue <= MaxValue))
            {
                FilterResult = FALSE;
            }
            else
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_ONE_EVERY_N:
            FilterResult = TRUE; /* Not Implemented Always return True .*/
            break;

        default: /* COM_FILTER_ALGORITHM_TYPE_ALWAYS */
            FilterResult = FALSE;
            break;
    }
    return FilterResult;
}
#endif

#if((COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON) || (COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON))
/********************************************************************************************************************
*   Service Name     : Com_ProcessUint64SignalFilter
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessUint64SignalFilter
(
    uint64 SignalOldValue , 
    P2CONST(uint64,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr
)
{
    boolean FilterResult = FALSE;
    uint64 SignalNewValue;
    uint64 SignalMaskValue;
    uint64 SignalXValue;
    uint64 MinValue;
    uint64 MaxValue;
    Com_FilterAlgorithmType FilterAlgorithm;

    SignalNewValue = *SignalDataPtr;
    FilterAlgorithm = FilterConfigPtr->FilterAlgorithmType;
    if((COM_NUM_OF_UINT64_FILTER_MASK_ID > FilterConfigPtr->FilterMaskBufferId  ) && 
       (COM_NUM_OF_UINT64_FILTER_X_ID > FilterConfigPtr->FilterXBufferId ))
    {
        SignalMaskValue = Com_Uint64FilterMaskValueConfig[FilterConfigPtr->FilterMaskBufferId];
        SignalXValue = Com_Uint64FilterXValueConfig[FilterConfigPtr->FilterXBufferId];
    }
    else
    {
        FilterAlgorithm = COM_FILTER_ALGORITHM_TYPE_ALWAYS;
    }
    switch(FilterAlgorithm)
    {
        case COM_FILTER_ALGORITHM_TYPE_ALWAYS:
            FilterResult = TRUE;
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_MASKED_OLD:
            /* (new_value&mask) != (old_value&mask) */
            if ((SignalOldValue & SignalMaskValue) != (SignalNewValue & SignalMaskValue))
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_X:
            /* new_value&mask) != x */
            if ((SignalNewValue & SignalMaskValue) != SignalXValue)
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_EQUALS_X:
            /* (new_value&mask) == x  */
            /* new_value&mask) != x */
            if ((SignalNewValue & SignalMaskValue) == SignalXValue)
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_NEW_IS_WITHIN:
            if((COM_NUM_OF_UINT64_FILTER_MIN_ID > FilterConfigPtr->FilterMinBufferId ) && 
               (COM_NUM_OF_UINT64_FILTER_MAX_ID > FilterConfigPtr->FilterMaxBufferId ))
            {
                MinValue = Com_Uint64FilterMinValueConfig[FilterConfigPtr->FilterMinBufferId];
                MaxValue = Com_Uint64FilterMaxValueConfig[FilterConfigPtr->FilterMaxBufferId];
                /*  min <= new_value <= max */
                if ((MinValue <= SignalNewValue) && (SignalNewValue <= MaxValue))
                {
                    FilterResult = TRUE;
                }
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_NEW_IS_OUTSIDE:
            if((COM_NUM_OF_UINT64_FILTER_MIN_ID > FilterConfigPtr->FilterMinBufferId ) && 
               (COM_NUM_OF_UINT64_FILTER_MAX_ID > FilterConfigPtr->FilterMaxBufferId ))
            {
                MinValue = Com_Uint64FilterMinValueConfig[FilterConfigPtr->FilterMinBufferId];
                MaxValue = Com_Uint64FilterMaxValueConfig[FilterConfigPtr->FilterMaxBufferId];
                /* (min > new_value) OR (new_value > max) */
                if ((MinValue <= SignalNewValue) && (SignalNewValue <= MaxValue))
                {
                    FilterResult = FALSE;
                }
                else
                {
                    FilterResult = TRUE;
                }
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_ONE_EVERY_N:
            FilterResult = TRUE; /* Not Implemented Always return True .*/
            break;

        default: /* COM_FILTER_ALGORITHM_TYPE_NEVER */
            FilterResult = FALSE;
            break;
    }
    return FilterResult;
}
#endif
#if((COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON) || (COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON))
/********************************************************************************************************************
*   Service Name     : Com_ProcessSint64SignalFilter
********************************************************************************************************************/
COM_LOCAL FUNC(boolean,COM_CODE) Com_ProcessSint64SignalFilter
(
    sint64 SignalOldValue , 
    P2CONST(sint64,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr
)
{
    boolean FilterResult = FALSE;
    sint64 SignalNewValue;
    sint64 SignalMaskValue;
    sint64 SignalXValue;
    sint64 MinValue;
    sint64 MaxValue;
    Com_FilterAlgorithmType FilterAlgorithm;

    SignalNewValue = *SignalDataPtr;
    FilterAlgorithm = FilterConfigPtr->FilterAlgorithmType;
    if((COM_NUM_OF_SINT64_FILTER_MASK_ID > FilterConfigPtr->FilterMaskBufferId ) &&
       (COM_NUM_OF_SINT64_FILTER_X_ID > FilterConfigPtr->FilterXBufferId ))
    {
        SignalMaskValue = Com_Sint64FilterMaskValueConfig[FilterConfigPtr->FilterMaskBufferId];
        SignalXValue = Com_Sint64FilterXValueConfig[FilterConfigPtr->FilterXBufferId];
    }
    else
    {
        FilterAlgorithm = COM_FILTER_ALGORITHM_TYPE_ALWAYS;
    }
    switch(FilterAlgorithm)
    {
        case COM_FILTER_ALGORITHM_TYPE_ALWAYS:
            FilterResult = TRUE;
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_MASKED_OLD:
            /* (new_value&mask) != (old_value&mask) */
            if ((SignalOldValue & SignalMaskValue) != (SignalNewValue & SignalMaskValue))
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_X:
            /* new_value&mask) != x */
            if ((SignalNewValue & SignalMaskValue) != SignalXValue)
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_EQUALS_X:
            /* (new_value&mask) == x  */
            /* new_value&mask) != x */
            if ((SignalNewValue & SignalMaskValue) == SignalXValue)
            {
                FilterResult = TRUE;
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_NEW_IS_WITHIN:
            if((COM_NUM_OF_SINT64_FILTER_MIN_ID > FilterConfigPtr->FilterMinBufferId ) && 
               (COM_NUM_OF_SINT64_FILTER_MAX_ID > FilterConfigPtr->FilterMaxBufferId ))
            {
                MinValue = Com_Sint64FilterMinValueConfig[FilterConfigPtr->FilterMinBufferId];
                MaxValue = Com_Sint64FilterMaxValueConfig[FilterConfigPtr->FilterMaxBufferId];
                /*  min <= new_value <= max */
                if ((MinValue <= SignalNewValue) && (SignalNewValue <= MaxValue))
                {
                    FilterResult = TRUE;
                }
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_NEW_IS_OUTSIDE:
            if((COM_NUM_OF_SINT64_FILTER_MIN_ID > FilterConfigPtr->FilterMinBufferId ) && 
               (COM_NUM_OF_SINT64_FILTER_MAX_ID > FilterConfigPtr->FilterMaxBufferId))
            {
                MinValue = Com_Sint64FilterMinValueConfig[FilterConfigPtr->FilterMinBufferId];
                MaxValue = Com_Sint64FilterMaxValueConfig[FilterConfigPtr->FilterMaxBufferId];
                /* (min > new_value) OR (new_value > max) */
                if ((MinValue <= SignalNewValue) && (SignalNewValue <= MaxValue))
                {
                    FilterResult = FALSE;
                }
                else
                {
                    FilterResult = TRUE;
                }
            }
            break;

        case COM_FILTER_ALGORITHM_TYPE_ONE_EVERY_N:
            FilterResult = TRUE; /* Not Implemented Always return True .*/
            break;

        default: /* COM_FILTER_ALGORITHM_TYPE_NEVER */
            FilterResult = FALSE;
            break;
    }
    return FilterResult;
}
#endif
/********************************************************************************************************************
*   Service Name     : Com_RxIpduSignalProcessing
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_RxIpduSignalProcessing(PduIdType RxIpduId)
{
    Com_NotifyStatusType NotifyStatus = COM_SIGNAL_NOTIFY_NONE;
    P2CONST(Com_RxIpduConfigType,AUTOMATIC,COM_APPL_CONST) RxIpduConfigPtr;
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
    P2CONST(Com_RxTpIpduConfigType,AUTOMATIC,COM_APPL_CONST) RxTpIpduConfigPtr;
#endif
    P2CONST(Com_RxIpduBufferConfigType,AUTOMATIC,COM_APPL_CONST) RxIpduBufferConfigPtr;
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr;
#if(COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON)
    P2CONST(Com_RxSigTimeoutCounterConfigType,AUTOMATIC,COM_APPL_CONST) RxSigTimeoutCounterConfigPtr;
#endif
#if(COM_RX_SIGNAL_UB_SUPPORT == STD_ON)
    P2CONST(Com_UBPropsType,AUTOMATIC,COM_APPL_CONST) RxSignalUBPropsPtr ;
    boolean IsUBSet ;
#endif
    PduLengthType BufferOffset;
    PduLengthType BufferLength;
    Com_SignalIdType SigIdx;

    if (COM_NUM_OF_RX_IPDU_ID > RxIpduId)
    {
        RxIpduConfigPtr =&Com_RxIpduConfig[RxIpduId];
        RxIpduBufferConfigPtr = &Com_RxIpduBufferConfig[RxIpduId];
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
        RxTpIpduConfigPtr = &Com_RxTpIpduConfig[RxIpduConfigPtr->RxTpId];
#endif
        for (SigIdx =  RxIpduConfigPtr->SignalStartId ;
             ((SigIdx <= RxIpduConfigPtr->SignalEndId) && (COM_NUM_OF_RX_SIGNAL_ID > SigIdx));SigIdx++)
        {
            RxSignalConfigPtr = &Com_RxSignalConfig[SigIdx];

            /* Check for UB support */
#if(COM_RX_SIGNAL_UB_SUPPORT == STD_ON)
            IsUBSet = TRUE;
            if (COM_NUM_OF_RX_SIGNAL_UB_ID > RxSignalConfigPtr->UBConfigId)
            {
                RxSignalUBPropsPtr = &Com_RxSignalUBConfig[RxSignalConfigPtr->UBConfigId];
                BufferOffset = RxIpduBufferConfigPtr->BufferStartId+RxSignalUBPropsPtr->UBBytePosition;
                IsUBSet = Com_UtilIsBitSet(Com_RxIpduBuffer[BufferOffset],RxSignalUBPropsPtr->UBBitPosition);
            }

            if (IsUBSet == TRUE)
#endif
            {

#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
                if (RxIpduConfigPtr->IpduType == COM_IPDU_TYPE_TP)
                {
                    BufferOffset = RxTpIpduConfigPtr->BufferStartId;
                }
                else
#endif
                {
                    BufferOffset = RxIpduBufferConfigPtr->BufferStartId;
                }
                if (Com_GetRxIpduBufferLength(RxIpduId) > 0U)
                {
                    BufferLength = Com_GetRxIpduBufferLength(RxIpduId);
                    /* Defect Fix for higher DLC Rx processing */
                    if (BufferLength > Com_RxIpduBufferConfig[RxIpduId].MaximumLength)
                    {
                        BufferLength = Com_RxIpduBufferConfig[RxIpduId].MaximumLength;
                    }
                }
                else
                {
                    BufferLength = 0U;
                }
                /* check for valid signal */
                NotifyStatus = Com_RxSignalValidationAndNotification(RxSignalConfigPtr,BufferOffset,
                                                                    BufferLength,RxIpduConfigPtr->IpduType,TRUE);
#if(COM_RX_SIGNAL_INVALID_CALLBACK_SUPPORT == STD_ON)
                if (NotifyStatus == COM_SIGNAL_NOTIFY_INVALID)
                {
                    if (COM_NUM_OF_RX_INV_FUNCT_ID > RxSignalConfigPtr->RxInvFunctId)
                    {
                        Com_CbkRxInvFunctType CbkRxInvFunctPtr;
                        CbkRxInvFunctPtr = Com_CbkRxInvFunctConfig[RxSignalConfigPtr->RxInvFunctId];
                        if (CbkRxInvFunctPtr != NULL_PTR)
                        {
                            /* notify */
                            (*CbkRxInvFunctPtr)();
                        }
                    }
                }
                else if(NotifyStatus  == COM_SIGNAL_NOTIFY_ACK)
#else
                if(NotifyStatus  == COM_SIGNAL_NOTIFY_ACK)
#endif
                {
#if(COM_RX_SIGNAL_ACK_CALLBACK_SUPPORT == STD_ON)
                    if (COM_NUM_OF_RX_ACK_FUNCT_ID > RxSignalConfigPtr->RxAckFunctId)
                    {
                        Com_CbkRxAckFunctType CbkRxAckFunctPtr;
                        CbkRxAckFunctPtr = Com_CbkRxAckFunctConfig[RxSignalConfigPtr->RxAckFunctId];
                        if (CbkRxAckFunctPtr != NULL_PTR)
                        {
                            /* notify */
                            (*CbkRxAckFunctPtr)();
                        }
                    }
#endif
                }
                else
                {

                }
#if(COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON)
                /* Reload Timeout monitor support */
                if (COM_NUM_OF_RX_SIGNAL_TIMEOUT_COUNTER_ID > RxSignalConfigPtr->RxSignalTimeoutCounterId)
                {
                    RxSigTimeoutCounterConfigPtr = &Com_RxSigTimeoutCounterConfig[RxSignalConfigPtr->RxSignalTimeoutCounterId];
                    if ( TRUE == Com_GetRxSigDeadlineMonitoringState(RxSignalConfigPtr->RxSignalTimeoutCounterId))
                    {
                        Com_SetRxSigDeadlineCount(RxSignalConfigPtr->RxSignalTimeoutCounterId,
                                             RxSigTimeoutCounterConfigPtr->Timeout);
                    }

                }
#endif
            }
        }
    }
}

#if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
/********************************************************************************************************************
*   Service Name     : Com_RxIpduSignalGroupProcessing
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_RxIpduSignalGroupProcessing(PduIdType RxIpduId)
{
    boolean IsUBSet ;
    Com_SignalIdType SigIdx;
    Com_SignalGroupIdType SigGroupIdx;
    P2CONST(Com_RxIpduConfigType,AUTOMATIC,COM_APPL_CONST) RxIpduConfigPtr;
    P2CONST(Com_RxIpduBufferConfigType,AUTOMATIC,COM_APPL_CONST) RxIpduBufferConfigPtr;
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr;
    P2CONST(Com_RxSignalGroupConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalGroupConfigPtr;
    Com_NotifyStatusType NotifyStatus = COM_SIGNAL_NOTIFY_NONE;
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
    P2CONST(Com_RxTpIpduConfigType,AUTOMATIC,COM_APPL_CONST) RxTpIpduConfigPtr;
#endif
#if (COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON)
    P2CONST(Com_RxSigGroupTimeoutCounterConfigType,AUTOMATIC,COM_APPL_CONST) RxSigGroupTimeoutCounterConfigPtr;
#endif
    PduLengthType BufferOffset = 0U;
#if (COM_RX_SIGNAL_GROUP_UB_SUPPORT == STD_ON)
    P2CONST(Com_UBPropsType,AUTOMATIC,COM_APPL_CONST) RxSignalGroupUBPropsPtr;
#endif

    if (COM_NUM_OF_RX_IPDU_ID > RxIpduId)
    {
        RxIpduConfigPtr =&Com_RxIpduConfig[RxIpduId];
        RxIpduBufferConfigPtr = &Com_RxIpduBufferConfig[RxIpduId];
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
        RxTpIpduConfigPtr = &Com_RxTpIpduConfig[RxIpduConfigPtr->RxTpId];
#endif
        /* Process Rx Signal Group */
        for (SigGroupIdx =  RxIpduConfigPtr->SignalGroupStartId ;
             ((SigGroupIdx <= RxIpduConfigPtr->SignalGroupEndId) && (COM_NUM_OF_RX_SIGNAL_GROUP_ID > SigGroupIdx));
             SigGroupIdx++)
        {
            IsUBSet = TRUE;
            RxSignalGroupConfigPtr = &Com_RxSignalGroupConfig[SigGroupIdx];
#if (COM_RX_SIGNAL_GROUP_UB_SUPPORT == STD_ON)
            if (COM_NUM_OF_RX_SIGNAL_GROUP_UB_ID > RxSignalGroupConfigPtr->UBConfigId)
            {
                RxSignalGroupUBPropsPtr = &Com_RxSignalGroupUBConfig[RxSignalGroupConfigPtr->UBConfigId];
                BufferOffset = RxIpduBufferConfigPtr->BufferStartId+RxSignalGroupUBPropsPtr->UBBytePosition;
                if (COM_RX_IPDU_BUFFER_SIZE > BufferOffset)
                {
                    IsUBSet = Com_UtilIsBitSet(Com_RxIpduBuffer[BufferOffset],RxSignalGroupUBPropsPtr->UBBitPosition);
                }
            }
#endif

            if (IsUBSet == TRUE)
            {
                NotifyStatus = COM_SIGNAL_NOTIFY_NONE;
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
                if (RxIpduConfigPtr->IpduType == COM_IPDU_TYPE_TP)
                {
                    BufferOffset = RxTpIpduConfigPtr->BufferStartId;
                }
                else
#endif
                {
                    BufferOffset = RxIpduBufferConfigPtr->BufferStartId;
                }
                
                /* Check for invalid data in the received buffer */
                for (SigIdx = RxSignalGroupConfigPtr->GroupSignalStartId;
                        SigIdx <= RxSignalGroupConfigPtr->GroupSignalEndId;SigIdx++)
                {
                    RxSignalConfigPtr = &Com_RxSignalConfig[SigIdx];
                    /* check for valid signal */
                    NotifyStatus = Com_RxSignalValidationAndNotification(RxSignalConfigPtr,
                                                                              BufferOffset,
                                                                              Com_GetRxIpduBufferLength(RxIpduId),
                                                                              RxIpduConfigPtr->IpduType,
                                                                              FALSE);

                    if ((NotifyStatus != COM_SIGNAL_NOTIFY_NONE) && (NotifyStatus!=COM_SIGNAL_NOTIFY_ACK))
                    {
                        break;
                    }
                }

                if ((NotifyStatus != COM_SIGNAL_NOTIFY_NONE) && (NotifyStatus!=COM_SIGNAL_NOTIFY_ACK))
                {
#if(COM_RX_SIGNAL_INVALID_CALLBACK_SUPPORT == STD_ON)
                    /* Check for the Notification status */
                    if(RxSignalGroupConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_NOTIFY)
                    {
                        if (COM_NUM_OF_RX_INV_FUNCT_ID > RxSignalGroupConfigPtr->RxInvFunctId)
                        {
                            Com_CbkRxInvFunctType CbkRxInvFunctPtr;
                            CbkRxInvFunctPtr = Com_CbkRxInvFunctConfig[RxSignalGroupConfigPtr->RxInvFunctId];
                            if (CbkRxInvFunctPtr != NULL_PTR)
                            {
                                /* notify */
                                (*CbkRxInvFunctPtr)();
                            }
                        }
                    }
                    else if(RxSignalGroupConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_REPLACE)
#else
                    if(RxSignalGroupConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_REPLACE)
#endif
                    {
                        /* Copy the Initial values to the all group signal shadow buffer .*/
                        for (SigIdx = RxSignalGroupConfigPtr->GroupSignalStartId;
                             SigIdx <= RxSignalGroupConfigPtr->GroupSignalEndId;SigIdx++)
                        {
                            RxSignalConfigPtr = &Com_RxSignalConfig[SigIdx];
                            Com_SetRxSignalInitValue(RxSignalConfigPtr);
                        }
                        /*! Initialize signal group array */
                        #if (COM_RX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON)
                        BufferOffset = RxSignalGroupConfigPtr->SignalGroupArrayBufferIdx;
                        if (COM_RX_SIGNAL_GROUP_RTE_ARRAY_BUFFER_SIZE > BufferOffset)
                        {
                            Com_UtilMemCopy(&Com_RxSignalGroupRteArrayBuffer[BufferOffset],
                                        &Com_RxSignalGroupRteArrayInitBuffer[BufferOffset],
                                        RxSignalGroupConfigPtr->ByteLength);
                        }
                        #endif
                    }
                    else
                    {

                    }
                }
                else
                {
                    if(NotifyStatus == COM_SIGNAL_NOTIFY_ACK)
                    {
                        for (SigIdx = RxSignalGroupConfigPtr->GroupSignalStartId;
                             SigIdx <= RxSignalGroupConfigPtr->GroupSignalEndId;SigIdx++)
                        {
                            RxSignalConfigPtr = &Com_RxSignalConfig[SigIdx];
                            #if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
                            if (RxIpduConfigPtr->IpduType == COM_IPDU_TYPE_TP)
                            {
                                if( COM_RX_TP_BUFFER_SIZE > RxIpduBufferConfigPtr->BufferStartId)
                                { 
                                    Com_RxSignalGroupShadowBufferUpdate(RxSignalConfigPtr,
                                                        &Com_RxTpIpduBuffer[RxTpIpduConfigPtr->BufferStartId],
                                                        Com_GetRxIpduBufferLength(RxIpduId));    
                                }
                            }
                            else
                            #endif
                            {
                                if( COM_RX_IPDU_BUFFER_SIZE > RxIpduBufferConfigPtr->BufferStartId)
                                {    
                                    Com_RxSignalGroupShadowBufferUpdate(RxSignalConfigPtr,
                                                        &Com_RxIpduBuffer[RxIpduBufferConfigPtr->BufferStartId],
                                                        Com_GetRxIpduBufferLength(RxIpduId));
                                }
                            }
                        }
                        
                        /* Copy data to the Array Buffer Buffer */
                        #if (COM_RX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON)
                        BufferOffset = RxIpduBufferConfigPtr->BufferStartId+RxSignalGroupConfigPtr->LsBytePosition;
                        if (TRUE == RxSignalGroupConfigPtr->SignalGroupArrayAccess)
                        {
                            if ((COM_RX_SIGNAL_GROUP_RTE_ARRAY_BUFFER_SIZE > RxSignalGroupConfigPtr->SignalGroupArrayBufferIdx) && 
                                (COM_RX_IPDU_BUFFER_SIZE > BufferOffset))
                            {
                                Com_UtilMemCopy(&Com_RxSignalGroupRteArrayBuffer[RxSignalGroupConfigPtr->SignalGroupArrayBufferIdx],
                                        &Com_RxIpduBuffer[BufferOffset],
                                        RxSignalGroupConfigPtr->ByteLength);
                            }
                        }
                        #endif
                        #if(COM_RX_SIGNAL_ACK_CALLBACK_SUPPORT == STD_ON)
                        if (COM_NUM_OF_RX_ACK_FUNCT_ID > RxSignalGroupConfigPtr->RxAckFunctId)
                        {
                            Com_CbkRxAckFunctType CbkRxAckFunctPtr;
                            CbkRxAckFunctPtr = Com_CbkRxAckFunctConfig[RxSignalGroupConfigPtr->RxAckFunctId];
                            if (CbkRxAckFunctPtr != NULL_PTR)
                            {
                                /* notify */
                                (*CbkRxAckFunctPtr)();
                            }
                        }
                        #endif
                    }
                }
#if (COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON)
                /* Reload Timeout monitor support */
                if (COM_NUM_OF_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_ID > RxSignalGroupConfigPtr->RxSigGroupTimeoutCounterId)
                {
                    RxSigGroupTimeoutCounterConfigPtr = &Com_RxSigGroupTimeoutCounterConfig[RxSignalGroupConfigPtr->RxSigGroupTimeoutCounterId];
                    if ( TRUE == Com_GetRxSigGroupDeadlineMonitoringState(RxSignalGroupConfigPtr->RxSigGroupTimeoutCounterId))
                    {
                        Com_SetRxSigGroupDeadlineCount(RxSignalGroupConfigPtr->RxSigGroupTimeoutCounterId,
                                                            RxSigGroupTimeoutCounterConfigPtr->Timeout);
                    }

                }
#endif
            }
        }
    }

}
#endif

/********************************************************************************************************************
*   Service Name     : Com_RxIpduProcessing
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_RxIpduProcessing(PduIdType RxIpduId)
{
#if(COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT == STD_ON)
    P2CONST(Com_RxIpduConfigType,AUTOMATIC,COM_APPL_CONST) RxIpduConfigPtr;
    P2CONST(Com_RxIpduTimeoutCounterConfigType,AUTOMATIC,COM_APPL_CONST) RxIpduTimeoutConfigPtr;
#endif
    if (COM_NUM_OF_RX_IPDU_ID > RxIpduId)
    {
        /* Process signals */
        Com_RxIpduSignalProcessing(RxIpduId);
        /* Process signal groups */
#if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
        Com_RxIpduSignalGroupProcessing(RxIpduId);
#endif
#if(COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT == STD_ON)
        RxIpduConfigPtr = &Com_RxIpduConfig[RxIpduId];
        /* Reload Timeout monitor support */
        if (COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID > RxIpduConfigPtr->IpduTimeoutCounterId)
        {
            RxIpduTimeoutConfigPtr = &Com_RxIpduTimeoutCounterConfig[RxIpduConfigPtr->IpduTimeoutCounterId];
            if ( TRUE == Com_GetRxIpduDeadlineMonitoringState(RxIpduConfigPtr->IpduTimeoutCounterId))
            {
                Com_SetRxIpduDeadlineCount(RxIpduConfigPtr->IpduTimeoutCounterId,
                                          RxIpduTimeoutConfigPtr->Timeout);
            }
        }
#endif
    }
}

/********************************************************************************************************************
*   Service Name     : Com_RxDeadlineMonitoringControl
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_RxDeadlineMonitoringControl(PduIdType RxIpduId,boolean InitTimeout,boolean StateCheck)
{
    #if((COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT == STD_ON) || (COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON) || \
    (COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON))
    P2CONST(Com_RxIpduConfigType,AUTOMATIC,COM_APPL_CONST) RxIpduConfigPtr;
    #endif
    #if(COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT == STD_ON)
    P2CONST(Com_RxIpduTimeoutCounterConfigType,AUTOMATIC,COM_APPL_CONST) RxIpduTimeoutCounterConfigPtr;
    #endif
    #if (COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON)
    P2CONST(Com_RxSigTimeoutCounterConfigType,AUTOMATIC,COM_APPL_CONST) RxSigTimeoutCounterConfigPtr;
    Com_RxSigToutIdType RxSigToutIdx;
    #endif
    #if (COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON)
    P2CONST(Com_RxSigGroupTimeoutCounterConfigType,AUTOMATIC,COM_APPL_CONST) RxSigGroupTimeoutCounterConfigPtr;
    Com_RxSigGroupToutIdType RxSigGroupToutIdx;
    #endif
    
    if (COM_NUM_OF_RX_IPDU_ID > RxIpduId)
    {
        #if((COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT == STD_ON) || (COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON) || \
            (COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON))
        RxIpduConfigPtr = &Com_RxIpduConfig[RxIpduId];
        #endif
        #if(COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT == STD_ON)
        /* Initialize the Ipdu Timeout properties  */
        if (COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID > RxIpduConfigPtr->IpduTimeoutCounterId)
        {
            RxIpduTimeoutCounterConfigPtr = &Com_RxIpduTimeoutCounterConfig[RxIpduConfigPtr->IpduTimeoutCounterId];
            if (FALSE != InitTimeout)
            {
                if(TRUE != StateCheck)
                {
                    Com_SetRxIpduDeadlineCount( RxIpduConfigPtr->IpduTimeoutCounterId,
                                                RxIpduTimeoutCounterConfigPtr->FirstTimeout);
                }
                else
                {
                    if (TRUE != Com_GetRxIpduDeadlineMonitoringState(RxIpduConfigPtr->IpduTimeoutCounterId))
                    {
                        Com_SetRxIpduDeadlineCount( RxIpduConfigPtr->IpduTimeoutCounterId,
                                                RxIpduTimeoutCounterConfigPtr->FirstTimeout);
                    }
                }
            }
            else
            {
                Com_SetRxIpduDeadlineCount(RxIpduConfigPtr->IpduTimeoutCounterId,0U);
            }
            Com_SetRxIpduDeadlineMonitoringState(RxIpduConfigPtr->IpduTimeoutCounterId,InitTimeout);
        }
        #endif
        #if (COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON)
        /* Initialize the signal with UB properties */
        if (COM_NUM_OF_RX_SIGNAL_TIMEOUT_COUNTER_ID > RxIpduConfigPtr->SigTimeoutCounterStartId)
        {
            for (RxSigToutIdx=RxIpduConfigPtr->SigTimeoutCounterStartId;
                    RxSigToutIdx<=RxIpduConfigPtr->SigTimeoutCounterEndId;RxSigToutIdx++)
            {
                RxSigTimeoutCounterConfigPtr = &Com_RxSigTimeoutCounterConfig[RxSigToutIdx];
                if (FALSE != InitTimeout)
                {
                    if(TRUE != StateCheck)
                    {
                        Com_SetRxSigDeadlineCount(RxSigToutIdx,RxSigTimeoutCounterConfigPtr->FirstTimeout);
                    }
                    else
                    {
                        if (TRUE != Com_GetRxSigDeadlineMonitoringState(RxSigToutIdx))
                        {
                            Com_SetRxSigDeadlineCount(RxSigToutIdx,RxSigTimeoutCounterConfigPtr->FirstTimeout);
                        }
                    }
                }
                else
                {
                    Com_SetRxSigDeadlineCount(RxSigToutIdx,0U);
                }
                Com_SetRxSigDeadlineMonitoringState(RxSigToutIdx,InitTimeout);
            }
        }
        #endif

        #if (COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON)
        /* Initialize the signal with UB properties */
        if (COM_NUM_OF_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_ID > RxIpduConfigPtr->SigGroupTimeoutCounterStartId)
        {
            for (RxSigGroupToutIdx=RxIpduConfigPtr->SigGroupTimeoutCounterStartId;
                    RxSigGroupToutIdx<=RxIpduConfigPtr->SigGroupTimeoutCounterEndId;RxSigGroupToutIdx++)
            {
                RxSigGroupTimeoutCounterConfigPtr = &Com_RxSigGroupTimeoutCounterConfig[RxSigGroupToutIdx];
                if (FALSE != InitTimeout)
                {
                    if(TRUE != StateCheck)
                    {
                        Com_SetRxSigGroupDeadlineCount( RxSigGroupToutIdx,
                                                        RxSigGroupTimeoutCounterConfigPtr->FirstTimeout);
                    }
                    else
                    {
                        if (TRUE != Com_GetRxSigGroupDeadlineMonitoringState(RxSigGroupToutIdx))
                        {
                            Com_SetRxSigGroupDeadlineCount( RxSigGroupToutIdx,
                                                            RxSigGroupTimeoutCounterConfigPtr->FirstTimeout);
                        }
                    }
                }
                else
                {
                    Com_SetRxSigGroupDeadlineCount( RxSigGroupToutIdx,0U);
                }
                Com_SetRxSigGroupDeadlineMonitoringState(RxSigGroupToutIdx,InitTimeout);
            }
        }
        #endif
    }
}

/********************************************************************************************************************
*   Service Name     : Com_RxBooleanSignalValidationAndNotification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxBooleanSignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset,
    PduLengthType BufferLength, 
    Com_IpduType IpduType,
    boolean BufferUpdateStatus
)
{
    boolean ReceivedData = 0U;
    PduLengthType MaxRxBufferSize;
    Com_NotifyStatusType NotifyStatus = COM_SIGNAL_NOTIFY_NONE;
    Com_RxRteBufferIdType RteBufferIndex = COM_RX_SIGNAL_RTE_INVALID_BUFFER_IDX;
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) RxIpduSrcBufferPtr;
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    boolean SignalData;
#endif
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
    boolean IsSignalValid = TRUE;
#endif
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    boolean FilterState;
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr;
#endif

#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
    if (IpduType == COM_IPDU_TYPE_TP)
    {
        MaxRxBufferSize = COM_RX_TP_BUFFER_SIZE;
    }
    else
#endif
    {
        MaxRxBufferSize = COM_RX_IPDU_BUFFER_SIZE;
    }
    
    if ((RxSignalConfigPtr != NULL_PTR) &&
        (MaxRxBufferSize > (RxIpduBufferOffset+BufferLength-1U)))
    {
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
        if (IpduType == COM_IPDU_TYPE_TP)
        {
            RxIpduSrcBufferPtr = &Com_RxTpIpduBuffer[RxIpduBufferOffset];
        }
        else
#endif
        {
            RxIpduSrcBufferPtr  = &Com_RxIpduBuffer[RxIpduBufferOffset];
        }
        /* Read received data */
        Com_ReadRxSignalFromBuffer((void *)&ReceivedData,RxSignalConfigPtr,RxIpduSrcBufferPtr,BufferLength);
        /* check for invalid data */
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
        if (COM_RX_BOOLEAN_SIGNAL_INVALID_DATA_BUFFER_SIZE > RxSignalConfigPtr->DataInitValueBufferIdStart)
        {
            if (ReceivedData == Com_RxBooleanSignalInvalidData[RxSignalConfigPtr->DataInitValueBufferIdStart])
            {
                IsSignalValid = FALSE;
                if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_NOTIFY)
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID;
                }
                else if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_REPLACE)
                {
                    if (BufferUpdateStatus == TRUE)
                    {
                        /* Write the Init data */
                        Com_SetRxSignalInitValue(RxSignalConfigPtr);
                    }
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_REPLACE;
                }
                else
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_NONE;
                }
            }
        }

        if(IsSignalValid == TRUE)
#endif
        {
            RteBufferIndex = RxSignalConfigPtr->RteBufferIdx;
            if (COM_RX_SIGNAL_RTE_U8BUFFER_SIZE > RteBufferIndex)
            {
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
                FilterState = TRUE;
                if ((COM_NUM_OF_RX_SIGNAL_FILTER_ID > RxSignalConfigPtr->FilterId))
                {
                    FilterConfigPtr = &Com_RxSignalFilterConfig[RxSignalConfigPtr->FilterId];
                    /* Read old Data */
                    #if (COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
                    if (FALSE != RxSignalConfigPtr->IsGroupSignal)
                    {
                        SignalData = (boolean) Com_RxSignalShadowRteU8Buffer[RxSignalConfigPtr->RteShadowBufferIdx];
                    }
                    else
                    #endif
                    {
                        SignalData = (boolean) Com_RxSignalRteU8Buffer[RteBufferIndex];
                    }
                    FilterState= Com_ProcessBooleanSignalFilter(SignalData,&ReceivedData,FilterConfigPtr);
                }
                if(FilterState == TRUE)
#endif
                {
                    if (BufferUpdateStatus == TRUE)
                    {
                        /* Update data to ComRte buffer */
                        Com_RxSignalRteU8Buffer[RteBufferIndex] = ReceivedData;
                    }
                    NotifyStatus = COM_SIGNAL_NOTIFY_ACK;
                }
            }
        }
    }
    #if(COM_RX_TP_IPDU_SUPPORT != STD_ON)
    COM_DUMMY_STATEMENT(IpduType);
    #endif
    return NotifyStatus;
}

/********************************************************************************************************************
*   Service Name     : Com_RxUint8SignalValidationAndNotification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxUint8SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
)
{
    uint8 ReceivedData = 0U;
    PduLengthType MaxRxBufferSize;
    Com_NotifyStatusType NotifyStatus = COM_SIGNAL_NOTIFY_NONE;
    Com_RxRteBufferIdType RteBufferIndex = COM_RX_SIGNAL_RTE_INVALID_BUFFER_IDX;
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) RxIpduSrcBufferPtr;
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    uint8 SignalData;
#endif
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
    boolean IsSignalValid = TRUE;
#endif
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    boolean FilterState;
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr;
#endif

#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
    if (IpduType == COM_IPDU_TYPE_TP)
    {
        MaxRxBufferSize = COM_RX_TP_BUFFER_SIZE;
    }
    else
#endif
    {
        MaxRxBufferSize = COM_RX_IPDU_BUFFER_SIZE;
    }

    if ((RxSignalConfigPtr != NULL_PTR) &&
        (MaxRxBufferSize > (RxIpduBufferOffset + BufferLength - 1U)))
    {
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
        if (IpduType == COM_IPDU_TYPE_TP)
        {
            RxIpduSrcBufferPtr = &Com_RxTpIpduBuffer[RxIpduBufferOffset];
        }
        else
#endif
        {
            RxIpduSrcBufferPtr  = &Com_RxIpduBuffer[RxIpduBufferOffset];
        }
        /* Read received data */
        Com_ReadRxSignalFromBuffer((void *)&ReceivedData,RxSignalConfigPtr,RxIpduSrcBufferPtr,BufferLength);
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
        /* check for invalid data */
        if (COM_RX_UINT8_SIGNAL_INVALID_DATA_BUFFER_SIZE > RxSignalConfigPtr->DataInitValueBufferIdStart)
        {
            if (ReceivedData == Com_RxUint8SignalInvalidData[RxSignalConfigPtr->DataInitValueBufferIdStart])
            {
                IsSignalValid = FALSE;
                if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_NOTIFY)
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID;
                }
                else if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_REPLACE)
                {
                    if (BufferUpdateStatus == TRUE)
                    {
                        /* Write the Init data */
                        Com_SetRxSignalInitValue(RxSignalConfigPtr);
                    }
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_REPLACE;
                }
                else
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_NONE;
                }
            }
        }

        if(IsSignalValid == TRUE)
#endif
        {
            RteBufferIndex = RxSignalConfigPtr->RteBufferIdx;
            if (COM_RX_SIGNAL_RTE_U8BUFFER_SIZE > RteBufferIndex)
            {
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
                FilterState = TRUE;
                if (COM_NUM_OF_RX_SIGNAL_FILTER_ID > RxSignalConfigPtr->FilterId)
                {
                    FilterConfigPtr = &Com_RxSignalFilterConfig[RxSignalConfigPtr->FilterId];
                    /* Read old Data */
                    #if (COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
                    if (FALSE != RxSignalConfigPtr->IsGroupSignal)
                    {
                        SignalData = Com_RxSignalShadowRteU8Buffer[RxSignalConfigPtr->RteShadowBufferIdx];
                    }
                    else
                    #endif
                    {
                        SignalData = Com_RxSignalRteU8Buffer[RteBufferIndex];
                    }
                    FilterState= Com_ProcessUint8SignalFilter(SignalData,&ReceivedData,FilterConfigPtr);
                }
                if(FilterState == TRUE)
#endif
                {
                    if (BufferUpdateStatus == TRUE)
                    {
                        /* Update data to ComRte buffer */
                        Com_RxSignalRteU8Buffer[RteBufferIndex] = ReceivedData;
                    }
                    /* notify upper layer */
                    NotifyStatus = COM_SIGNAL_NOTIFY_ACK;
                }
            }
        }
    }
    #if(COM_RX_TP_IPDU_SUPPORT != STD_ON)
    COM_DUMMY_STATEMENT(IpduType);
    #endif
    return NotifyStatus;
}

/********************************************************************************************************************
*   Service Name     : Com_RxSint8SignalValidationAndNotification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxSint8SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength ,
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
)
{
    sint8 ReceivedData = 0;
    PduLengthType MaxRxBufferSize;
    Com_NotifyStatusType NotifyStatus = COM_SIGNAL_NOTIFY_NONE;
    Com_RxRteBufferIdType RteBufferIndex = COM_RX_SIGNAL_RTE_INVALID_BUFFER_IDX;
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) RxIpduSrcBufferPtr;
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    sint8 SignalData;
#endif
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
    boolean IsSignalValid = TRUE;
#endif
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    boolean FilterState;
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr;
#endif
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
    if (IpduType == COM_IPDU_TYPE_TP)
    {
        MaxRxBufferSize = COM_RX_TP_BUFFER_SIZE;
    }
    else
#endif
    {
        MaxRxBufferSize = COM_RX_IPDU_BUFFER_SIZE;
    }
    
    if ((RxSignalConfigPtr != NULL_PTR) &&
        (MaxRxBufferSize > (RxIpduBufferOffset + BufferLength - 1U)))
    {
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
        if (IpduType == COM_IPDU_TYPE_TP)
        {
            RxIpduSrcBufferPtr = &Com_RxTpIpduBuffer[RxIpduBufferOffset];
        }
        else
#endif
        {
            RxIpduSrcBufferPtr  = &Com_RxIpduBuffer[RxIpduBufferOffset];
        }
        /* Read received data */
        Com_ReadRxSignalFromBuffer((void *)&ReceivedData,RxSignalConfigPtr,RxIpduSrcBufferPtr,BufferLength);
        /* check for invalid data */
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
        if (COM_RX_SINT8_SIGNAL_INVALID_DATA_BUFFER_SIZE > RxSignalConfigPtr->DataInitValueBufferIdStart)
        {
            if (ReceivedData == Com_RxSint8SignalInvalidData[RxSignalConfigPtr->DataInitValueBufferIdStart])
            {
                IsSignalValid = FALSE;
                if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_NOTIFY)
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID;
                }
                else if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_REPLACE)
                {
                    if (BufferUpdateStatus == TRUE)
                    {
                        /* Write the Init data */
                        Com_SetRxSignalInitValue(RxSignalConfigPtr);
                    }
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_REPLACE;
                }
                else
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_NONE;
                }
            }
        }

        if(IsSignalValid == TRUE)
#endif
        {
            RteBufferIndex = RxSignalConfigPtr->RteBufferIdx;
            if (COM_RX_SIGNAL_RTE_U8BUFFER_SIZE > RteBufferIndex)
            {
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
                FilterState = TRUE;
                if (COM_NUM_OF_RX_SIGNAL_FILTER_ID > RxSignalConfigPtr->FilterId)
                {
                    FilterConfigPtr = &Com_RxSignalFilterConfig[RxSignalConfigPtr->FilterId];
                    /* Read old Data */
                    #if (COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
                    if (FALSE != RxSignalConfigPtr->IsGroupSignal)
                    {
                        SignalData = (sint8) Com_RxSignalShadowRteU8Buffer[RxSignalConfigPtr->RteShadowBufferIdx];
                    }
                    else
                    #endif
                    {
                        SignalData = (sint8) Com_RxSignalRteU8Buffer[RteBufferIndex];
                    }
                    FilterState= Com_ProcessSint8SignalFilter(SignalData,&ReceivedData,FilterConfigPtr);
                }
                if(FilterState == TRUE)
#endif
                {
                    if (BufferUpdateStatus == TRUE)
                    {
                        /* Update data to ComRte buffer */
                        Com_RxSignalRteU8Buffer[RteBufferIndex] = (uint8)ReceivedData;
                    }
                    /* notify upper layer */
                    NotifyStatus = COM_SIGNAL_NOTIFY_ACK;
                }
            }
        }
    }
    #if(COM_RX_TP_IPDU_SUPPORT != STD_ON)
    COM_DUMMY_STATEMENT(IpduType);
    #endif
    return NotifyStatus;
}

/********************************************************************************************************************
*   Service Name     : Com_RxUint16SignalValidationAndNotification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxUint16SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
)
{
    uint16 ReceivedData = 0U;
    PduLengthType MaxRxBufferSize;
    Com_NotifyStatusType NotifyStatus = COM_SIGNAL_NOTIFY_NONE;
    Com_RxRteBufferIdType RteBufferIndex = COM_RX_SIGNAL_RTE_INVALID_BUFFER_IDX;
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) RxIpduSrcBufferPtr;
#if (COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    uint16 SignalData;
#endif
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
    boolean IsSignalValid = TRUE;
#endif
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    boolean FilterState;
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr;
#endif

#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
    if (IpduType == COM_IPDU_TYPE_TP)
    {
        MaxRxBufferSize = COM_RX_TP_BUFFER_SIZE;
    }
    else
#endif
    {
        MaxRxBufferSize = COM_RX_IPDU_BUFFER_SIZE;
    }
    
    if ((RxSignalConfigPtr != NULL_PTR) &&
        (MaxRxBufferSize > (RxIpduBufferOffset + BufferLength - 1U)))
    {
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
        if (IpduType == COM_IPDU_TYPE_TP)
        {
            RxIpduSrcBufferPtr = &Com_RxTpIpduBuffer[RxIpduBufferOffset];
        }
        else
#endif
        {
            RxIpduSrcBufferPtr  = &Com_RxIpduBuffer[RxIpduBufferOffset];
        }
        /* Read received data */
        Com_ReadRxSignalFromBuffer((void *)&ReceivedData,RxSignalConfigPtr,RxIpduSrcBufferPtr,BufferLength);
        /* check for invalid data */
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
        if (COM_RX_UINT16_SIGNAL_INVALID_DATA_BUFFER_SIZE > RxSignalConfigPtr->DataInitValueBufferIdStart)
        {
            if (ReceivedData == Com_RxUint16SignalInvalidData[RxSignalConfigPtr->DataInitValueBufferIdStart])
            {
                IsSignalValid = FALSE;
                if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_NOTIFY)
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID;
                }
                else if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_REPLACE)
                {
                    if (BufferUpdateStatus == TRUE)
                    {
                        /* Write the Init data */
                        Com_SetRxSignalInitValue(RxSignalConfigPtr);
                    }
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_REPLACE;
                }
                else
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_NONE;
                }
            }
        }

        if(IsSignalValid == TRUE)
#endif
        {
            RteBufferIndex = RxSignalConfigPtr->RteBufferIdx;
            if (COM_RX_SIGNAL_RTE_U16BUFFER_SIZE > RteBufferIndex)
            {
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
                FilterState = TRUE;
                if (COM_NUM_OF_RX_SIGNAL_FILTER_ID > RxSignalConfigPtr->FilterId)
                {
                    FilterConfigPtr = &Com_RxSignalFilterConfig[RxSignalConfigPtr->FilterId];
                    /* Read old Data */
                    
                    #if (COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
                    if (FALSE != RxSignalConfigPtr->IsGroupSignal)
                    {
                        SignalData = Com_RxSignalShadowRteU16Buffer[RxSignalConfigPtr->RteShadowBufferIdx];
                    }
                    else
                    #endif
                    {
                        SignalData = Com_RxSignalRteU16Buffer[RteBufferIndex];
                    }
                    FilterState= Com_ProcessUint16SignalFilter(SignalData,&ReceivedData,FilterConfigPtr);
                }
                if(FilterState == TRUE)
    #endif
                {
                    if (BufferUpdateStatus == TRUE)
                    {                       
                        /* Update data to ComRte buffer */
                        Com_RxSignalRteU16Buffer[RteBufferIndex] = ReceivedData;
                    }
                    /* notify upper layer */
                    NotifyStatus = COM_SIGNAL_NOTIFY_ACK;
                }
            }
        }
    }
    #if(COM_RX_TP_IPDU_SUPPORT != STD_ON)
    COM_DUMMY_STATEMENT(IpduType);
    #endif
    return NotifyStatus;
}

/********************************************************************************************************************
*   Service Name     : Com_RxSint16SignalValidationAndNotification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxSint16SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset , 
    PduLengthType BufferLength , 
    Com_IpduType IpduType , 
    boolean BufferUpdateStatus
)
{
    sint16 ReceivedData = 0;
    PduLengthType MaxRxBufferSize;
    Com_NotifyStatusType NotifyStatus = COM_SIGNAL_NOTIFY_NONE;
    Com_RxRteBufferIdType RteBufferIndex = COM_RX_SIGNAL_RTE_INVALID_BUFFER_IDX;
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) RxIpduSrcBufferPtr;
#if (COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    sint16 SignalData = 0U;
#endif
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
    boolean IsSignalValid = TRUE;
#endif
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    boolean FilterState;
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr;
#endif

#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
    if (IpduType == COM_IPDU_TYPE_TP)
    {
        MaxRxBufferSize = COM_RX_TP_BUFFER_SIZE;
    }
    else
#endif
    {
        MaxRxBufferSize = COM_RX_IPDU_BUFFER_SIZE;
    }
    
    if ((RxSignalConfigPtr != NULL_PTR) &&
        (MaxRxBufferSize > (RxIpduBufferOffset + BufferLength - 1U)))
    {
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
        if (IpduType == COM_IPDU_TYPE_TP)
        {
            RxIpduSrcBufferPtr = &Com_RxTpIpduBuffer[RxIpduBufferOffset];
        }
        else
#endif
        {
            RxIpduSrcBufferPtr  = &Com_RxIpduBuffer[RxIpduBufferOffset];
        }
        /* Read received data */
        Com_ReadRxSignalFromBuffer((void *)&ReceivedData,RxSignalConfigPtr,RxIpduSrcBufferPtr,BufferLength);
        /* check for invalid data */
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
        if (COM_RX_SINT16_SIGNAL_INVALID_DATA_BUFFER_SIZE > RxSignalConfigPtr->DataInitValueBufferIdStart)
        {
            if (ReceivedData == Com_RxSint16SignalInvalidData[RxSignalConfigPtr->DataInitValueBufferIdStart])
            {
                IsSignalValid = FALSE;
                if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_NOTIFY)
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID;
                }
                else if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_REPLACE)
                {
                    if (BufferUpdateStatus == TRUE)
                    {
                        /* Write the Init data */
                        Com_SetRxSignalInitValue(RxSignalConfigPtr);
                    }
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_REPLACE;
                }
                else
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_NONE;
                }
            }
        }

        if(IsSignalValid == TRUE)
#endif
        {
            RteBufferIndex = RxSignalConfigPtr->RteBufferIdx;
            if (COM_RX_SIGNAL_RTE_U16BUFFER_SIZE > RteBufferIndex)
            {
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
                FilterState = TRUE;
                if (COM_NUM_OF_RX_SIGNAL_FILTER_ID > RxSignalConfigPtr->FilterId)
                {
                    FilterConfigPtr = &Com_RxSignalFilterConfig[RxSignalConfigPtr->FilterId];
                    /* Read old Data */
                    #if (COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
                    if (FALSE != RxSignalConfigPtr->IsGroupSignal)
                    {
                        SignalData = (sint16) Com_RxSignalShadowRteU16Buffer[RxSignalConfigPtr->RteShadowBufferIdx];
                    }
                    else
                    #endif
                    {
                        SignalData = (sint16) Com_RxSignalRteU16Buffer[RteBufferIndex];
                    }
                    FilterState= Com_ProcessSint16SignalFilter(SignalData,&ReceivedData,FilterConfigPtr);
                }
                if(FilterState == TRUE)
#endif
                {
                    if (BufferUpdateStatus == TRUE)
                    {
                        /* Update data to ComRte buffer */
                        Com_RxSignalRteU16Buffer[RteBufferIndex] = ReceivedData;
                    }
                    /* notify upper layer */
                    NotifyStatus = COM_SIGNAL_NOTIFY_ACK;
                }
            }
        }
    }
    #if(COM_RX_TP_IPDU_SUPPORT != STD_ON)
    COM_DUMMY_STATEMENT(IpduType);
    #endif
    return NotifyStatus;
}

/********************************************************************************************************************
*   Service Name     : Com_RxUint32SignalValidationAndNotification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxUint32SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
)
{
    uint32 ReceivedData = 0U;
    PduLengthType MaxRxBufferSize;
    Com_NotifyStatusType NotifyStatus = COM_SIGNAL_NOTIFY_NONE;
    Com_RxRteBufferIdType RteBufferIndex = COM_RX_SIGNAL_RTE_INVALID_BUFFER_IDX;
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) RxIpduSrcBufferPtr;
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    uint32 SignalData;
#endif
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
    boolean IsSignalValid = TRUE;
#endif
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    boolean FilterState;
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr;
#endif
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
    if (IpduType == COM_IPDU_TYPE_TP)
    {
        MaxRxBufferSize = COM_RX_TP_BUFFER_SIZE;
    }
    else
#endif
    {
        MaxRxBufferSize = COM_RX_IPDU_BUFFER_SIZE;
    }
    
    if ((RxSignalConfigPtr != NULL_PTR) &&
        (MaxRxBufferSize > (RxIpduBufferOffset + BufferLength - 1U)))
    {
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
        if (IpduType == COM_IPDU_TYPE_TP)
        {
            RxIpduSrcBufferPtr = &Com_RxTpIpduBuffer[RxIpduBufferOffset];
        }
        else
#endif
        {
            RxIpduSrcBufferPtr  = &Com_RxIpduBuffer[RxIpduBufferOffset];
        }
        /* Read received data */
        Com_ReadRxSignalFromBuffer((void *)&ReceivedData,RxSignalConfigPtr,RxIpduSrcBufferPtr,BufferLength);
        /* check for invalid data */
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
        if (COM_RX_UINT32_SIGNAL_INVALID_DATA_BUFFER_SIZE > RxSignalConfigPtr->DataInitValueBufferIdStart)
        {
            if (ReceivedData == Com_RxUint32SignalInvalidData[RxSignalConfigPtr->DataInitValueBufferIdStart])
            {
                IsSignalValid = FALSE;
                if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_NOTIFY)
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID;
                }
                else if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_REPLACE)
                {
                    if (BufferUpdateStatus == TRUE)
                    {
                        /* Write the Init data */
                        Com_SetRxSignalInitValue(RxSignalConfigPtr);
                    }
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_REPLACE;
                }
                else
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_NONE;
                }
            }
        }

        if(IsSignalValid == TRUE)
#endif
        {
            RteBufferIndex = RxSignalConfigPtr->RteBufferIdx;
            if (COM_RX_SIGNAL_RTE_U32BUFFER_SIZE > RteBufferIndex)
            {
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
                FilterState = TRUE;
                if (COM_NUM_OF_RX_SIGNAL_FILTER_ID > RxSignalConfigPtr->FilterId)
                {
                    FilterConfigPtr = &Com_RxSignalFilterConfig[RxSignalConfigPtr->FilterId];
                    /* Read old Data */
                    #if (COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
                    if (FALSE != RxSignalConfigPtr->IsGroupSignal)
                    {
                        SignalData = Com_RxSignalShadowRteU32Buffer[RxSignalConfigPtr->RteShadowBufferIdx];
                    }
                    else
                    #endif
                    {
                        SignalData = Com_RxSignalRteU32Buffer[RteBufferIndex];
                    }
                    FilterState= Com_ProcessUint32SignalFilter(SignalData,&ReceivedData,FilterConfigPtr);
                }
                if(FilterState == TRUE)
#endif
                {
                    if (BufferUpdateStatus == TRUE)
                    {
                        /* Update data to ComRte buffer */
                        Com_RxSignalRteU32Buffer[RteBufferIndex] = ReceivedData;
                    }
                    /* notify upper layer */
                    NotifyStatus = COM_SIGNAL_NOTIFY_ACK;
                }
            }
        }
    }
    #if(COM_RX_TP_IPDU_SUPPORT != STD_ON)
    COM_DUMMY_STATEMENT(IpduType);
    #endif
    return NotifyStatus;
}

/********************************************************************************************************************
*   Service Name     : Com_RxSint32SignalValidationAndNotification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxSint32SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset , 
    PduLengthType BufferLength , 
    Com_IpduType IpduType , 
    boolean BufferUpdateStatus
)
{
    sint32 ReceivedData = 0;
    PduLengthType MaxRxBufferSize;
    Com_NotifyStatusType NotifyStatus = COM_SIGNAL_NOTIFY_NONE;
    Com_RxRteBufferIdType RteBufferIndex = COM_RX_SIGNAL_RTE_INVALID_BUFFER_IDX;
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) RxIpduSrcBufferPtr;
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    sint32 SignalData;
#endif
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
    boolean IsSignalValid = TRUE;
#endif
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    boolean FilterState;
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr;
#endif

#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
    if (IpduType == COM_IPDU_TYPE_TP)
    {
        MaxRxBufferSize = COM_RX_TP_BUFFER_SIZE;
    }
    else
#endif
    {
        MaxRxBufferSize = COM_RX_IPDU_BUFFER_SIZE;
    }
    
    if ((RxSignalConfigPtr != NULL_PTR) &&
        (MaxRxBufferSize > (RxIpduBufferOffset + BufferLength - 1U)))
    {
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
        if (IpduType == COM_IPDU_TYPE_TP)
        {
            RxIpduSrcBufferPtr = &Com_RxTpIpduBuffer[RxIpduBufferOffset];
        }
        else
#endif
        {
            RxIpduSrcBufferPtr  = &Com_RxIpduBuffer[RxIpduBufferOffset];
        }

        /* Read received data */
        Com_ReadRxSignalFromBuffer((void *)&ReceivedData,RxSignalConfigPtr,RxIpduSrcBufferPtr,BufferLength);
        /* check for invalid data */
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
        if (COM_RX_SINT32_SIGNAL_INVALID_DATA_BUFFER_SIZE > RxSignalConfigPtr->DataInitValueBufferIdStart)
        {
            if (ReceivedData == Com_RxSint32SignalInvalidData[RxSignalConfigPtr->DataInitValueBufferIdStart])
            {
                IsSignalValid = FALSE;
                if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_NOTIFY)
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID;
                }
                else if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_REPLACE)
                {
                    if (BufferUpdateStatus == TRUE)
                    {
                        /* Write the Init data */
                        Com_SetRxSignalInitValue(RxSignalConfigPtr);
                    }
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_REPLACE;
                }
                else
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_NONE;
                }
            }
        }

        if(IsSignalValid == TRUE)
#endif
        {
            RteBufferIndex = RxSignalConfigPtr->RteBufferIdx;
            if (COM_RX_SIGNAL_RTE_U32BUFFER_SIZE > RteBufferIndex)
            {
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
                FilterState = TRUE;
                if (COM_NUM_OF_RX_SIGNAL_FILTER_ID > RxSignalConfigPtr->FilterId)
                {
                    FilterConfigPtr = &Com_RxSignalFilterConfig[RxSignalConfigPtr->FilterId];
                    /* Read old Data */
                    #if (COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
                    if (FALSE != RxSignalConfigPtr->IsGroupSignal)
                    {
                        SignalData = (sint32) Com_RxSignalShadowRteU32Buffer[RxSignalConfigPtr->RteShadowBufferIdx];
                    }
                    else
                    #endif
                    {
                        SignalData = (sint32) Com_RxSignalRteU32Buffer[RteBufferIndex];
                    }
                    FilterState= Com_ProcessSint32SignalFilter(SignalData,&ReceivedData,FilterConfigPtr);
                }
                if(FilterState == TRUE)
#endif
                {
                    if (BufferUpdateStatus == TRUE)
                    {
                        /* Update data to ComRte buffer */
                        Com_RxSignalRteU32Buffer[RteBufferIndex] = ReceivedData;
                    }
                    /* notify upper layer */
                    NotifyStatus = COM_SIGNAL_NOTIFY_ACK;
                }
            }
        }
    }
    #if(COM_RX_TP_IPDU_SUPPORT != STD_ON)
    COM_DUMMY_STATEMENT(IpduType);
    #endif
    return NotifyStatus;
}

/********************************************************************************************************************
*   Service Name     : Com_RxUint64SignalValidationAndNotification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxUint64SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
)
{
    uint64 ReceivedData = 0U;
    PduLengthType MaxRxBufferSize;
    Com_NotifyStatusType NotifyStatus = COM_SIGNAL_NOTIFY_NONE;
    Com_RxRteBufferIdType RteBufferIndex = COM_RX_SIGNAL_RTE_INVALID_BUFFER_IDX;
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) RxIpduSrcBufferPtr;
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    uint64 SignalData;
#endif
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
    boolean IsSignalValid = TRUE;
#endif
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    boolean FilterState;
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr;
#endif

#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
    if (IpduType == COM_IPDU_TYPE_TP)
    {
        MaxRxBufferSize = COM_RX_TP_BUFFER_SIZE;
    }
    else
#endif
    {
        MaxRxBufferSize = COM_RX_IPDU_BUFFER_SIZE;
    }
    
    if ((RxSignalConfigPtr != NULL_PTR) &&
        (MaxRxBufferSize > (RxIpduBufferOffset + BufferLength - 1U)))
    {
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
        if (IpduType == COM_IPDU_TYPE_TP)
        {
            RxIpduSrcBufferPtr = &Com_RxTpIpduBuffer[RxIpduBufferOffset];
        }
        else
#endif
        {
            RxIpduSrcBufferPtr  = &Com_RxIpduBuffer[RxIpduBufferOffset];
        }
        /* Read received data */
        Com_ReadRxSignalFromBuffer((void *)&ReceivedData,RxSignalConfigPtr,RxIpduSrcBufferPtr,BufferLength);
        /* check for invalid data */
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
        if (COM_RX_UINT64_SIGNAL_INVALID_DATA_BUFFER_SIZE > RxSignalConfigPtr->DataInitValueBufferIdStart)
        {
            if (ReceivedData == Com_RxUint64SignalInvalidData[RxSignalConfigPtr->DataInitValueBufferIdStart])
            {
                IsSignalValid = FALSE;
                if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_NOTIFY)
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID;
                }
                else if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_REPLACE)
                {
                    if (BufferUpdateStatus == TRUE)
                    {
                        /* Write the Init data */
                        Com_SetRxSignalInitValue(RxSignalConfigPtr);
                    }
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_REPLACE;
                }
                else
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_NONE;
                }
            }
        }

        if(IsSignalValid == TRUE)
#endif
        {
            RteBufferIndex = RxSignalConfigPtr->RteBufferIdx;
            if (COM_RX_SIGNAL_RTE_U64BUFFER_SIZE > RteBufferIndex)
            {
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
                FilterState = TRUE;
                if (COM_NUM_OF_RX_SIGNAL_FILTER_ID > RxSignalConfigPtr->FilterId)
                {
                    FilterConfigPtr = &Com_RxSignalFilterConfig[RxSignalConfigPtr->FilterId];
                    /* Read old Data */
                    #if (COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
                    if (FALSE != RxSignalConfigPtr->IsGroupSignal)
                    {
                        SignalData = Com_RxSignalShadowRteU64Buffer[RxSignalConfigPtr->RteShadowBufferIdx];
                    }
                    else
                    #endif
                    {
                        SignalData = Com_RxSignalRteU64Buffer[RteBufferIndex];
                    }
                    FilterState= Com_ProcessUint64SignalFilter(SignalData,&ReceivedData,FilterConfigPtr);
                }
                if(FilterState == TRUE)
#endif
                {
                    if (BufferUpdateStatus == TRUE)
                    {
                        /* Update data to ComRte buffer */
                        Com_RxSignalRteU64Buffer[RteBufferIndex] = ReceivedData;
                    }
                    /* notify upper layer */
                    NotifyStatus = COM_SIGNAL_NOTIFY_ACK;
                }
            }
        }
    }
    #if(COM_RX_TP_IPDU_SUPPORT != STD_ON)
    COM_DUMMY_STATEMENT(IpduType);
    #endif
    return NotifyStatus;
}

/********************************************************************************************************************
*   Service Name     : Com_RxSint64SignalValidationAndNotification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxSint64SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr ,
    PduLengthType RxIpduBufferOffset , 
    PduLengthType BufferLength , 
    Com_IpduType IpduType , 
    boolean BufferUpdateStatus
)
{
    sint64 ReceivedData = 0;
    PduLengthType MaxRxBufferSize;
    Com_NotifyStatusType NotifyStatus = COM_SIGNAL_NOTIFY_NONE;
    Com_RxRteBufferIdType RteBufferIndex = COM_RX_SIGNAL_RTE_INVALID_BUFFER_IDX;
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) RxIpduSrcBufferPtr;
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    sint64 SignalData;
#endif
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
    boolean IsSignalValid = TRUE;
#endif
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    boolean FilterState;
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr;
#endif

#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
    if (IpduType == COM_IPDU_TYPE_TP)
    {
        MaxRxBufferSize = COM_RX_TP_BUFFER_SIZE;
    }
    else
#endif
    {
        MaxRxBufferSize = COM_RX_IPDU_BUFFER_SIZE;
    }
    
    if ((RxSignalConfigPtr != NULL_PTR) &&
        (MaxRxBufferSize > (RxIpduBufferOffset + BufferLength - 1U)))
    {
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
        if (IpduType == COM_IPDU_TYPE_TP)
        {
            RxIpduSrcBufferPtr = &Com_RxTpIpduBuffer[RxIpduBufferOffset];
        }
        else
#endif
        {
            RxIpduSrcBufferPtr  = &Com_RxIpduBuffer[RxIpduBufferOffset];
        }

        /* Read received data */
        Com_ReadRxSignalFromBuffer((void *)&ReceivedData,RxSignalConfigPtr,RxIpduSrcBufferPtr,BufferLength);
        /* check for invalid data */
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
        if (COM_RX_SINT64_SIGNAL_INVALID_DATA_BUFFER_SIZE > RxSignalConfigPtr->DataInitValueBufferIdStart)
        {
            if (ReceivedData == Com_RxSint64SignalInvalidData[RxSignalConfigPtr->DataInitValueBufferIdStart])
            {
                IsSignalValid = FALSE;
                if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_NOTIFY)
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID;
                }
                else if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_REPLACE)
                {
                    if (BufferUpdateStatus == TRUE)
                    {
                        /* Write the Init data */
                        Com_SetRxSignalInitValue(RxSignalConfigPtr);
                    }
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_REPLACE;
                }
                else
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_NONE;
                }
            }
        }

        if(IsSignalValid == TRUE)
#endif
        {
            RteBufferIndex = RxSignalConfigPtr->RteBufferIdx;
            if (COM_RX_SIGNAL_RTE_U64BUFFER_SIZE > RteBufferIndex)
            {
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
                FilterState = TRUE;
                if (COM_NUM_OF_RX_SIGNAL_FILTER_ID > RxSignalConfigPtr->FilterId)
                {
                    FilterConfigPtr = &Com_RxSignalFilterConfig[RxSignalConfigPtr->FilterId];
                    /* Read old Data */
                    #if (COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
                    if (FALSE != RxSignalConfigPtr->IsGroupSignal)
                    {
                        SignalData = (sint64) Com_RxSignalShadowRteU64Buffer[RxSignalConfigPtr->RteShadowBufferIdx];
                    }
                    else
                    #endif
                    {
                        SignalData = (sint64) Com_RxSignalRteU64Buffer[RteBufferIndex];
                    }
                    FilterState= Com_ProcessSint64SignalFilter(SignalData,&ReceivedData,FilterConfigPtr);
                }
                if(FilterState == TRUE)
#endif
                {
                    if (BufferUpdateStatus == TRUE)
                    {
                        /* Update data to ComRte buffer */
                        Com_RxSignalRteU64Buffer[RteBufferIndex] = (uint64)ReceivedData;
                    }
                    /* notify upper layer */
                    NotifyStatus = COM_SIGNAL_NOTIFY_ACK;
                }
            }
        }
    }
    #if(COM_RX_TP_IPDU_SUPPORT != STD_ON)
    COM_DUMMY_STATEMENT(IpduType);
    #endif
    return NotifyStatus;
}

/********************************************************************************************************************
*   Service Name     : Com_RxUint8ArrSignalValidationAndNotification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxUint8ArrSignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType , 
    boolean BufferUpdateStatus
)
{
    PduLengthType MaxRxBufferSize;
    Com_NotifyStatusType NotifyStatus = COM_SIGNAL_NOTIFY_NONE;
    Com_RxRteBufferIdType RteBufferIndex = COM_RX_SIGNAL_RTE_INVALID_BUFFER_IDX;
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) RxIpduSrcBufferPtr;
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
    boolean IsSignalValid = TRUE;
#endif

#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    P2CONST(Com_FilterConfigType,AUTOMATIC,COM_APPL_CONST) FilterConfigPtr;
    PduLengthType Idx;
    boolean FilterState;
#endif

#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
    if (IpduType == COM_IPDU_TYPE_TP)
    {
        MaxRxBufferSize = COM_RX_TP_BUFFER_SIZE;
    }
    else
#endif
    {
        MaxRxBufferSize = COM_RX_IPDU_BUFFER_SIZE;
    }
    
    if ((RxSignalConfigPtr != NULL_PTR) &&
        (MaxRxBufferSize > (RxIpduBufferOffset + BufferLength - 1U)))
    {
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
        if (IpduType == COM_IPDU_TYPE_TP)
        {
            RxIpduSrcBufferPtr = &Com_RxTpIpduBuffer[RxIpduBufferOffset+RxSignalConfigPtr->LsBytePosition];
        }
        else
#endif
        {
            RxIpduSrcBufferPtr  = &Com_RxIpduBuffer[RxIpduBufferOffset+RxSignalConfigPtr->LsBytePosition];
        }
        
        RteBufferIndex = RxSignalConfigPtr->RteBufferIdx;
       
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
        /* check for invalid data */
        if (COM_RX_UINT8_ARR_SIGNAL_INVALID_DATA_BUFFER_SIZE > RxSignalConfigPtr->DataInitValueBufferIdStart)
        {
            for(Idx = 0U;Idx<BufferLength;Idx++)
            {
                if(RxIpduSrcBufferPtr[Idx]!=Com_RxUint8ArrSignalInvalidData[RxSignalConfigPtr->DataInitValueBufferIdStart+Idx])
                {
                    IsSignalValid = FALSE;
                    break;
                }
            }
            if (IsSignalValid == FALSE)
            {
                if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_NOTIFY)
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID;
                }
                else if (RxSignalConfigPtr->DataInvalidActionType == COM_DATA_INVALID_ACTION_REPLACE)
                {
                    if (BufferUpdateStatus == TRUE)
                    {
                        Com_SetRxSignalInitValue(RxSignalConfigPtr);
                    }
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_REPLACE;
                }
                else
                {
                    NotifyStatus = COM_SIGNAL_NOTIFY_INVALID_NONE;
                }
            }
        }

        if(IsSignalValid == TRUE)
#endif
        {
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
            FilterState = TRUE;
            if (COM_NUM_OF_RX_SIGNAL_FILTER_ID > RxSignalConfigPtr->FilterId)
            {
                FilterConfigPtr = &Com_RxSignalFilterConfig[RxSignalConfigPtr->FilterId];
                /* Uint8 and uintArr supports only Always or Never */
                if (FilterConfigPtr->FilterAlgorithmType != COM_FILTER_ALGORITHM_TYPE_ALWAYS)
                {
                    FilterState = FALSE;
                }
            }

            if(FilterState == TRUE)
#endif
            {
                if ((BufferUpdateStatus == TRUE) && 
                    (COM_RX_SIGNAL_RTE_ARRBUFFER_SIZE >= (RteBufferIndex+RxSignalConfigPtr->ByteLength)))
                {
                    /* Update data to ComRte buffer */
                    Com_UtilMemCopy(&Com_RxSignalRteArrBuffer[RteBufferIndex],
                                    RxIpduSrcBufferPtr,RxSignalConfigPtr->ByteLength);
                }
                /* notify upper layer */
                NotifyStatus = COM_SIGNAL_NOTIFY_ACK;
            }
        }
    }
    #if(COM_RX_TP_IPDU_SUPPORT != STD_ON)
    COM_DUMMY_STATEMENT(IpduType);
    #endif
    return NotifyStatus;
}

#if(COM_SIGNAL_TYPE_FLOAT32_SUPPORT == STD_ON)
/********************************************************************************************************************
*   Service Name     : Com_RxFloat32SignalValidationAndNotification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxFloat32SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
)
{
    float32 ReceivedData=0;
    PduLengthType MaxRxBufferSize;
    Com_RxRteBufferIdType RteBufferIndex = COM_RX_SIGNAL_RTE_INVALID_BUFFER_IDX;
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) RxIpduSrcBufferPtr;
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
    if (IpduType == COM_IPDU_TYPE_TP)
    {
        MaxRxBufferSize = COM_RX_TP_BUFFER_SIZE;
    }
    else
#endif
    {
        MaxRxBufferSize = COM_RX_IPDU_BUFFER_SIZE;
    }
    
    if ((RxSignalConfigPtr != NULL_PTR) &&
        (MaxRxBufferSize > (RxIpduBufferOffset + BufferLength - 1U)))
    {

#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
        if (IpduType == COM_IPDU_TYPE_TP)
        {
            RxIpduSrcBufferPtr = &Com_RxTpIpduBuffer[RxIpduBufferOffset];
        }
        else
#endif
        {
            RxIpduSrcBufferPtr  = &Com_RxIpduBuffer[RxIpduBufferOffset];
        }
        
        RteBufferIndex = RxSignalConfigPtr->RteBufferIdx;
        if ((BufferUpdateStatus == TRUE) && (COM_RX_SIGNAL_RTE_U32BUFFER_SIZE > RteBufferIndex))
        {
            /* Update data to ComRte buffer */
            Com_ReadRxSignalFromBuffer((void *)&ReceivedData,RxSignalConfigPtr,RxIpduSrcBufferPtr,BufferLength);
            /* Update data to ComRte buffer */
            Com_RxSignalRteU32Buffer[RteBufferIndex] = ReceivedData;
        }
        /* notify upper layer */
    }
    #if(COM_RX_TP_IPDU_SUPPORT != STD_ON)
    COM_DUMMY_STATEMENT(IpduType);
    #endif
    return COM_SIGNAL_NOTIFY_ACK;
}
#endif

#if(COM_SIGNAL_TYPE_FLOAT64_SUPPORT == STD_ON)
/********************************************************************************************************************
*   Service Name     : Com_RxFloat64SignalValidationAndNotification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxFloat64SignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
)
{
    float64 ReceivedData=0;
    PduLengthType MaxRxBufferSize;
    Com_RxRteBufferIdType RteBufferIndex = COM_RX_SIGNAL_RTE_INVALID_BUFFER_IDX;
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) RxIpduSrcBufferPtr;
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
    if (IpduType == COM_IPDU_TYPE_TP)
    {
        MaxRxBufferSize = COM_RX_TP_BUFFER_SIZE;
    }
    else
#endif
    {
        MaxRxBufferSize = COM_RX_IPDU_BUFFER_SIZE;
    }
    
    if ((RxSignalConfigPtr != NULL_PTR) &&
        (MaxRxBufferSize > (RxIpduBufferOffset + BufferLength - 1U)))
    {
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
        if (IpduType == COM_IPDU_TYPE_TP)
        {
            RxIpduSrcBufferPtr = &Com_RxTpIpduBuffer[RxIpduBufferOffset];
        }
        else
#endif
        {
            RxIpduSrcBufferPtr  = &Com_RxIpduBuffer[RxIpduBufferOffset];
        }
        
        RteBufferIndex = RxSignalConfigPtr->RteBufferIdx;
        if ((BufferUpdateStatus == TRUE) && (COM_RX_SIGNAL_RTE_U64BUFFER_SIZE > RteBufferIndex))
        {
            /* Update data to ComRte buffer */
            Com_ReadRxSignalFromBuffer((void *)&ReceivedData,RxSignalConfigPtr,RxIpduSrcBufferPtr,BufferLength);
            /* Update data to ComRte buffer */
            Com_RxSignalRteU64Buffer[RteBufferIndex] = ReceivedData;
        }

    }
    #if(COM_RX_TP_IPDU_SUPPORT != STD_ON)
    COM_DUMMY_STATEMENT(IpduType);
    #endif
    return COM_SIGNAL_NOTIFY_ACK;
}
#endif

/********************************************************************************************************************
*   Service Name     : Com_RxSignalValidationAndNotification
********************************************************************************************************************/
COM_LOCAL FUNC(Com_NotifyStatusType,COM_CODE) Com_RxSignalValidationAndNotification
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    PduLengthType RxIpduBufferOffset ,
    PduLengthType BufferLength , 
    Com_IpduType IpduType ,
    boolean BufferUpdateStatus
)
{
    Com_NotifyStatusType  NotifyStatus=COM_SIGNAL_NOTIFY_NONE;

    switch(RxSignalConfigPtr->SignalType)
    {
        case COM_SIGNALTYPE_BOOLEAN:
            NotifyStatus = Com_RxBooleanSignalValidationAndNotification(RxSignalConfigPtr,RxIpduBufferOffset,
                                                                        BufferLength,IpduType,BufferUpdateStatus);
            break;
        case COM_SIGNALTYPE_UINT8:
            NotifyStatus = Com_RxUint8SignalValidationAndNotification(RxSignalConfigPtr,RxIpduBufferOffset,
                                                                        BufferLength,IpduType,BufferUpdateStatus);
            break;
        case COM_SIGNALTYPE_SINT8:
            NotifyStatus = Com_RxSint8SignalValidationAndNotification(RxSignalConfigPtr,RxIpduBufferOffset,
                                                                        BufferLength,IpduType,BufferUpdateStatus);

            break;
        case COM_SIGNALTYPE_UINT16:
            NotifyStatus = Com_RxUint16SignalValidationAndNotification(RxSignalConfigPtr,RxIpduBufferOffset,
                                                                        BufferLength,IpduType,BufferUpdateStatus);

            break;

        case COM_SIGNALTYPE_SINT16:
            NotifyStatus = Com_RxSint16SignalValidationAndNotification(RxSignalConfigPtr,RxIpduBufferOffset,
                                                                        BufferLength,IpduType,BufferUpdateStatus);

            break;

        case COM_SIGNALTYPE_UINT32:
            NotifyStatus = Com_RxUint32SignalValidationAndNotification(RxSignalConfigPtr,RxIpduBufferOffset,
                                                                        BufferLength,IpduType,BufferUpdateStatus);

            break;

        case COM_SIGNALTYPE_SINT32:
            NotifyStatus = Com_RxSint32SignalValidationAndNotification(RxSignalConfigPtr,RxIpduBufferOffset,
                                                                        BufferLength,IpduType,BufferUpdateStatus);

            break;

        case COM_SIGNALTYPE_UINT64:
            NotifyStatus = Com_RxUint64SignalValidationAndNotification(RxSignalConfigPtr,RxIpduBufferOffset,
                                                                        BufferLength,IpduType,BufferUpdateStatus);

            break;

        case COM_SIGNALTYPE_SINT64:
            NotifyStatus = Com_RxSint64SignalValidationAndNotification(RxSignalConfigPtr,RxIpduBufferOffset,
                                                                        BufferLength,IpduType,BufferUpdateStatus);

            break;
#if(COM_SIGNAL_TYPE_FLOAT32_SUPPORT == STD_ON)
        case COM_SIGNALTYPE_FLOAT32:
            NotifyStatus = Com_RxFloat32SignalValidationAndNotification(RxSignalConfigPtr,RxIpduBufferOffset,
                                                                        BufferLength,IpduType,BufferUpdateStatus);
            break;
#endif

#if(COM_SIGNAL_TYPE_FLOAT64_SUPPORT == STD_ON)
        case COM_SIGNALTYPE_FLOAT64:
            NotifyStatus = Com_RxFloat64SignalValidationAndNotification(RxSignalConfigPtr,RxIpduBufferOffset,
                                                                        BufferLength,IpduType,BufferUpdateStatus);
            break;
#endif
        case COM_SIGNALTYPE_UINT8_N:
        case COM_SIGNALTYPE_UINT8_DYN:
            NotifyStatus = Com_RxUint8ArrSignalValidationAndNotification(RxSignalConfigPtr,RxIpduBufferOffset,
                                                                        BufferLength,IpduType,BufferUpdateStatus);

            break;
        default:
            break;
    }
    return NotifyStatus;
}

/********************************************************************************************************************
*   Service Name     : Com_ReadRxSignalFromBuffer
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_ReadRxSignalFromBuffer
(
    P2CONST(void,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    P2CONST(uint8,AUTOMATIC,COM_APPL_CONST) RxIpduBufferPtr ,
    PduLengthType MaximumLength
)
{
    Com_UtilBitCopyPropsType UtilBitCopyProps;

    if ((SignalDataPtr!= NULL_PTR ) && (RxSignalConfigPtr != NULL_PTR)  &&
        (RxIpduBufferPtr!=NULL_PTR) && (MaximumLength > 0U))
    {
        /* Get buffer for the Pdu */
        UtilBitCopyProps.SignalLengthInBits  = RxSignalConfigPtr->BitSize;
        UtilBitCopyProps.SingalLengthInBytes = RxSignalConfigPtr->ByteLength;
        /* Update the bit copy details */
        UtilBitCopyProps.SrcLsBit = RxSignalConfigPtr->LsBitPosition;
        UtilBitCopyProps.SrcLsByte = RxSignalConfigPtr->LsBytePosition;
        if (RxSignalConfigPtr->SignalEndiannessType == COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN)
        {
            UtilBitCopyProps.SrcBufferEndianess = COM_ENDIANESS_BIG;
        }
        else
        {
            /* Opaque uint8[n] is for same as Little Endian , bit 0 in byte 0*/
            UtilBitCopyProps.SrcBufferEndianess = COM_ENDIANESS_LITTLE;
        }
        UtilBitCopyProps.MaxSrcBufferSize = MaximumLength;

        #if(COM_MICRO_ENDIANESS == COM_ENDIANESS_LITTLE)
        UtilBitCopyProps.DestLsBit = 0U;
        UtilBitCopyProps.DestLsByte = 0U;
        UtilBitCopyProps.DestBufferEndianess = COM_ENDIANESS_LITTLE;
        #else
        UtilBitCopyProps.DestLsBit = 0U;
        UtilBitCopyProps.DestLsByte = RxSignalConfigPtr->ByteLength;
        UtilBitCopyProps.DestBufferEndianess = COM_ENDIANESS_BIG;
        #endif
        UtilBitCopyProps.MaxDestBufferSize = RxSignalConfigPtr->ByteLength;
        /* Clear source buffer */
        Com_UtilMemSet((uint8*)SignalDataPtr,0U,RxSignalConfigPtr->ByteLength);
        /* copy the data from RxIpdu Rte buffer to SignalDataPtr */
        Com_UtilBitCopy(&UtilBitCopyProps,RxIpduBufferPtr,(uint8*)SignalDataPtr);

        /* Extend sign */
        switch(RxSignalConfigPtr->SignalType)
        {
            case COM_SIGNALTYPE_SINT8:
                Com_UtilGetSignExtended8BitData((uint8*)SignalDataPtr,RxSignalConfigPtr->BitSize);
                break;
            case COM_SIGNALTYPE_SINT16:
                Com_UtilGetSignExtended16BitData((uint16*)SignalDataPtr,RxSignalConfigPtr->BitSize);
                break;
            case COM_SIGNALTYPE_SINT32:
                Com_UtilGetSignExtended32BitData((uint32*)SignalDataPtr,RxSignalConfigPtr->BitSize);
                break;
            case COM_SIGNALTYPE_SINT64:
                Com_UtilGetSignExtended64BitData((uint64*)SignalDataPtr,RxSignalConfigPtr->BitSize);
                break;
            default:
                break;
        }
    }
}

#ifdef COM_RX_SIGNAL_WRITE_API_SUPPORT 
/********************************************************************************************************************
*   Service Name     : Com_WriteRxSignalToBuffer
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_WriteRxSignalToBuffer
(
    P2CONST(void,AUTOMATIC,COM_APPL_CONST) SignalDataPtr , 
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    P2VAR(uint8,AUTOMATIC,COM_APPL_CONST) RxIpduBufferPtr , 
    PduLengthType MaximumLength
)
{
    Com_UtilBitCopyPropsType UtilBitCopyProps;

    if ((SignalDataPtr!= NULL_PTR ) && (RxSignalConfigPtr != NULL_PTR) &&
        (RxIpduBufferPtr!=NULL_PTR) && (MaximumLength > 0U))
    {
        /* Get buffer for the Pdu */
        UtilBitCopyProps.SignalLengthInBits  = RxSignalConfigPtr->BitSize;
        UtilBitCopyProps.SingalLengthInBytes = RxSignalConfigPtr->ByteLength;
        /* Update the bit copy details */
        #if(COM_MICRO_ENDIANESS == COM_ENDIANESS_LITTLE)
        UtilBitCopyProps.SrcLsBit = 0;
        UtilBitCopyProps.SrcLsByte = 0;
        UtilBitCopyProps.SrcBufferEndianess = COM_ENDIANESS_LITTLE;
        #else
        UtilBitCopyProps.SrcLsBit = 0;
        UtilBitCopyProps.SrcLsByte = RxSignalConfigPtr->ByteLength;
        UtilBitCopyProps.SrcBufferEndianess = COM_ENDIANESS_BIG;
        #endif
        UtilBitCopyProps.MaxSrcBufferSize = RxSignalConfigPtr->ByteLength;
        UtilBitCopyProps.DestLsBit = RxSignalConfigPtr->LsBitPosition;
        UtilBitCopyProps.DestLsByte = RxSignalConfigPtr->LsBytePosition;
        if (RxSignalConfigPtr->SignalEndiannessType == COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN)
        {
            UtilBitCopyProps.DestBufferEndianess = COM_ENDIANESS_BIG;
        }
        else
        {
            /* Opaque uint8[n] is for same as Little Endian , bit 0 in byte 0*/
            UtilBitCopyProps.DestBufferEndianess = COM_ENDIANESS_LITTLE;
        }
        UtilBitCopyProps.MaxDestBufferSize = MaximumLength;
        /* copy the data from RxIpdu Rte buffer to SignalDataPtr */
        Com_UtilBitCopy(&UtilBitCopyProps,(uint8*)SignalDataPtr,RxIpduBufferPtr);
    }
}
#endif

/********************************************************************************************************************
*   Service Name     : Com_SetRxSignalInitValue
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_SetRxSignalInitValue
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,AUTOMATIC) RxSignalConfigPtr
)
{
    Com_RxRteBufferIdType RteBufferIndex;
    Com_RxRteBufferIdType InitBufferIndex ;
    #if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
    Com_RxRteShadowBufferIdType RteShadowBufferIdxIndex;
    #endif

    if (NULL_PTR != RxSignalConfigPtr)
    {
        InitBufferIndex = RxSignalConfigPtr->InitBufferIdx ;
        RteBufferIndex = RxSignalConfigPtr->RteBufferIdx ;
        #if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
        RteShadowBufferIdxIndex = RxSignalConfigPtr->RteShadowBufferIdx;
        #endif
        Com_EnterCriticalSection();
        /* Copy data from the Rte signal buffer */
        switch(RxSignalConfigPtr->SignalType)
        {
            case COM_SIGNALTYPE_BOOLEAN:
            case COM_SIGNALTYPE_UINT8:
            case COM_SIGNALTYPE_SINT8:
                if ((COM_RX_SIGNAL_RTE_U8BUFFER_SIZE > RteBufferIndex ) && 
                    (COM_RX_SIGNAL_U8_INIT_BUFFER_SIZE > InitBufferIndex))
                {
                    Com_RxSignalRteU8Buffer[RteBufferIndex] = Com_RxSignalU8InitBuffer[InitBufferIndex];
                }
                #if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
                if(FALSE != RxSignalConfigPtr->IsGroupSignal)
                {
                    if ((COM_RX_SIGNAL_SHADOW_RTE_U8BUFFER_SIZE > RteShadowBufferIdxIndex ) && 
                        (COM_RX_SIGNAL_U8_INIT_BUFFER_SIZE > InitBufferIndex))
                    {
                        Com_RxSignalShadowRteU8Buffer[RteShadowBufferIdxIndex] = Com_RxSignalU8InitBuffer[InitBufferIndex];
                    }
                }
                #endif
                break;
            case COM_SIGNALTYPE_UINT16:
            case COM_SIGNALTYPE_SINT16:
                if ((COM_RX_SIGNAL_RTE_U16BUFFER_SIZE > RteBufferIndex ) && 
                    (COM_RX_SIGNAL_U16_INIT_BUFFER_SIZE > InitBufferIndex))
                {
                    Com_RxSignalRteU16Buffer[RteBufferIndex] = Com_RxSignalU16InitBuffer[InitBufferIndex];
                }
                #if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
                if(FALSE != RxSignalConfigPtr->IsGroupSignal)
                {
                    if ((COM_RX_SIGNAL_SHADOW_RTE_U16BUFFER_SIZE > RteShadowBufferIdxIndex ) && 
                        (COM_RX_SIGNAL_U16_INIT_BUFFER_SIZE > InitBufferIndex))
                    {
                        Com_RxSignalShadowRteU16Buffer[RteShadowBufferIdxIndex] = Com_RxSignalU16InitBuffer[InitBufferIndex];
                    }
                }
                #endif
                break;
            case COM_SIGNALTYPE_UINT32:
            case COM_SIGNALTYPE_SINT32:
            case COM_SIGNALTYPE_FLOAT32:
                if ((COM_RX_SIGNAL_RTE_U32BUFFER_SIZE > RteBufferIndex ) && 
                    (COM_RX_SIGNAL_U32_INIT_BUFFER_SIZE > InitBufferIndex))
                {
                    Com_RxSignalRteU32Buffer[RteBufferIndex] = Com_RxSignalU32InitBuffer[InitBufferIndex];
                }
                #if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
                if(FALSE != RxSignalConfigPtr->IsGroupSignal)
                {
                    if ((COM_RX_SIGNAL_SHADOW_RTE_U32BUFFER_SIZE > RteShadowBufferIdxIndex ) && 
                        (COM_RX_SIGNAL_U32_INIT_BUFFER_SIZE > InitBufferIndex))
                    {
                        Com_RxSignalShadowRteU32Buffer[RteShadowBufferIdxIndex] = Com_RxSignalU32InitBuffer[InitBufferIndex];
                    }
                }
                #endif
                break;
            case COM_SIGNALTYPE_UINT64:
            case COM_SIGNALTYPE_SINT64:
            case COM_SIGNALTYPE_FLOAT64:
                if ((COM_RX_SIGNAL_RTE_U64BUFFER_SIZE > RteBufferIndex ) && 
                    (COM_RX_SIGNAL_U64_INIT_BUFFER_SIZE > InitBufferIndex))
                {
                    Com_RxSignalRteU64Buffer[RteBufferIndex] = Com_RxSignalU64InitBuffer[InitBufferIndex];
                }
                #if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
                if(FALSE != RxSignalConfigPtr->IsGroupSignal)
                {
                    if ((COM_RX_SIGNAL_SHADOW_RTE_U64BUFFER_SIZE > RteShadowBufferIdxIndex ) && 
                        (COM_RX_SIGNAL_U64_INIT_BUFFER_SIZE > InitBufferIndex))
                    {
                        Com_RxSignalShadowRteU64Buffer[RteShadowBufferIdxIndex] = Com_RxSignalU64InitBuffer[InitBufferIndex];
                    }
                }
                #endif
                break;
            case COM_SIGNALTYPE_UINT8_N:    
            case COM_SIGNALTYPE_UINT8_DYN:
                /* COM_SIGNALTYPE_UINT8_N */
                if ((COM_RX_SIGNAL_RTE_ARRBUFFER_SIZE >= (RxSignalConfigPtr->ByteLength+RteBufferIndex)) && 
                    (COM_RX_SIGNAL_RTE_ARR_INIT_BUFFER_SIZE > InitBufferIndex))
                {
                    Com_UtilMemCopy(&Com_RxSignalRteArrBuffer[RteBufferIndex],
                                    &Com_RxSignalArrInitBuffer[InitBufferIndex],RxSignalConfigPtr->ByteLength);
                }
                #if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
                if(FALSE != RxSignalConfigPtr->IsGroupSignal)
                {
                    if ((COM_RX_SIGNAL_SHADOW_RTE_ARRBUFFER_SIZE > RteShadowBufferIdxIndex) && 
                        (COM_RX_SIGNAL_RTE_ARR_INIT_BUFFER_SIZE > InitBufferIndex))
                    {
                        Com_UtilMemCopy(&Com_RxSignalShadowRteArrBuffer[RteShadowBufferIdxIndex],
                                        &Com_RxSignalArrInitBuffer[InitBufferIndex],RxSignalConfigPtr->ByteLength);
                    }
                }
                #endif
                break;
            default:
                /* Do Nothing*/
                break;
        } 
        Com_ExitCriticalSection();
    }
}

#if (COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
/********************************************************************************************************************
*   Service Name     : Com_RxSignalGroupShadowBufferUpdate
*   Description      : This method is used to update the shadow buffer data with the received data
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_RxSignalGroupShadowBufferUpdate
(
    P2CONST(Com_RxSignalConfigType,AUTOMATIC,COM_APPL_CONST) RxSignalConfigPtr , 
    CONSTP2CONST(uint8,AUTOMATIC,COM_APPL_CONST) RxIpduSrcBufferPtr ,
    PduLengthType BufferLength
)
{
    uint8 ReceivedDataU8 = 0U;
    uint16 ReceivedDataU16 = 0U;
    uint32 ReceivedDataU32 = 0U;
    uint64 ReceivedDataU64 = 0U;
    Com_RxRteShadowBufferIdType RteBufferIndex;
    
    RteBufferIndex = RxSignalConfigPtr->RteShadowBufferIdx;
    /* Copy data from the Rte signal buffer */
    switch(RxSignalConfigPtr->SignalType)
    {
        case COM_SIGNALTYPE_BOOLEAN:
        case COM_SIGNALTYPE_UINT8:
        case COM_SIGNALTYPE_SINT8:
            Com_ReadRxSignalFromBuffer((void *)&ReceivedDataU8,RxSignalConfigPtr,RxIpduSrcBufferPtr,BufferLength);
            if (COM_RX_SIGNAL_SHADOW_RTE_U8BUFFER_SIZE > RteBufferIndex)
            {
                Com_EnterCriticalSection();
                Com_RxSignalShadowRteU8Buffer[RteBufferIndex] = ReceivedDataU8;
                Com_ExitCriticalSection();
            }
            break;
        case COM_SIGNALTYPE_UINT16:
        case COM_SIGNALTYPE_SINT16:
            Com_ReadRxSignalFromBuffer((void *)&ReceivedDataU16,RxSignalConfigPtr,RxIpduSrcBufferPtr,BufferLength);
            if (COM_RX_SIGNAL_SHADOW_RTE_U16BUFFER_SIZE > RteBufferIndex)
            {
                Com_EnterCriticalSection();
                Com_RxSignalShadowRteU16Buffer[RteBufferIndex] = ReceivedDataU16;
                Com_ExitCriticalSection();
            }
            break;
        case COM_SIGNALTYPE_UINT32:
        case COM_SIGNALTYPE_SINT32:
        case COM_SIGNALTYPE_FLOAT32:
            Com_ReadRxSignalFromBuffer((void *)&ReceivedDataU32,RxSignalConfigPtr,RxIpduSrcBufferPtr,BufferLength);
            if (COM_RX_SIGNAL_SHADOW_RTE_U32BUFFER_SIZE > RteBufferIndex)
            {
                Com_EnterCriticalSection();
                Com_RxSignalShadowRteU32Buffer[RteBufferIndex] = ReceivedDataU32;
                Com_ExitCriticalSection();
            }
            break;
        case COM_SIGNALTYPE_UINT64:
        case COM_SIGNALTYPE_SINT64:
        case COM_SIGNALTYPE_FLOAT64:
            Com_ReadRxSignalFromBuffer((void *)&ReceivedDataU64,RxSignalConfigPtr,RxIpduSrcBufferPtr,BufferLength);
            if (COM_RX_SIGNAL_SHADOW_RTE_U64BUFFER_SIZE > RteBufferIndex)
            {
                Com_EnterCriticalSection();
                Com_RxSignalShadowRteU64Buffer[RteBufferIndex] = ReceivedDataU64;
                Com_ExitCriticalSection();
            }
            break;
        case COM_SIGNALTYPE_UINT8_N: 
        case COM_SIGNALTYPE_UINT8_DYN:
            /* COM_SIGNALTYPE_UINT8_N */
            if (COM_RX_SIGNAL_SHADOW_RTE_ARRBUFFER_SIZE >= (RxSignalConfigPtr->ByteLength+RteBufferIndex))
            {
                Com_EnterCriticalSection();
                Com_UtilMemCopy(&Com_RxSignalShadowRteArrBuffer[RteBufferIndex],
                                RxIpduSrcBufferPtr,RxSignalConfigPtr->ByteLength);
                Com_ExitCriticalSection();
            }
            break;
            
        default:
            /* Do Nothing*/
            break;
    }
}
#endif

/********************************************************************************************************************
*   Service Name     : Com_UtilBitCopy
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UtilBitCopy
(
    P2VAR(Com_UtilBitCopyPropsType,AUTOMATIC,COM_APPL_DATA) UtilBitCopyPropsPtr,
    CONSTP2CONST(uint8,AUTOMATIC,COM_APPL_CONST) SrcBufferPtr , 
    CONSTP2VAR(uint8,AUTOMATIC,COM_APPL_DATA) DestBufferPtr
)
{
    uint8 destBufferBitOffset;
    uint8 srcBufferBitOffset;
    uint8 copyBitPosition;
    uint8 noOfBitsToCopy;
    uint8 tempSrcValue;
    uint32 destBufferByteIndex;
    uint32 srcBufferByteIndex;
    uint32 remainingSignalLength;

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
    (void)copyBitPosition;
    /* set remaining signal length */
    remainingSignalLength = UtilBitCopyPropsPtr->SignalLengthInBits;
    if ((8U > destBufferBitOffset) && (8U > srcBufferBitOffset))
    {
        /* Copy to destination data buffer , should be in critical section */
        Com_EnterCriticalSection();
        while((remainingSignalLength!=0U) &&
           (UtilBitCopyPropsPtr->MaxDestBufferSize > destBufferByteIndex)  &&
           (UtilBitCopyPropsPtr->MaxSrcBufferSize > srcBufferByteIndex))
        {
            /* find bits position for copy in current iteration*/
            if ((destBufferBitOffset == 0U) && (srcBufferBitOffset != 0U))
            {
                copyBitPosition = 8U-srcBufferBitOffset;
            }
            else if((srcBufferBitOffset == 0U) && (destBufferBitOffset != 0U))
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
                noOfBitsToCopy = (uint8)remainingSignalLength;
            }
            else
            {
                noOfBitsToCopy = copyBitPosition;
            }
            /* Get the source byte to be copied for current iteration*/
            tempSrcValue = SrcBufferPtr[srcBufferByteIndex] >> srcBufferBitOffset;
            tempSrcValue &= Com_UtilBitWidthMasks[noOfBitsToCopy];
            tempSrcValue = (tempSrcValue << destBufferBitOffset);
            /* Copy it to the destination */
            /* First Clear the Signal Bits in the MSByte */
            Com_UtilSetClearBitMask(&DestBufferPtr[destBufferByteIndex],
                                    (uint8)(Com_UtilBitWidthMasks[noOfBitsToCopy] << destBufferBitOffset), FALSE);
            DestBufferPtr[destBufferByteIndex] |= tempSrcValue;

            /* Update source buffer offset and index */
            if (UtilBitCopyPropsPtr->SrcBufferEndianess == COM_ENDIANESS_LITTLE)
            {
                srcBufferByteIndex += (uint32)((srcBufferBitOffset+copyBitPosition)/8U);
            }
            else
            {
                srcBufferByteIndex -= (uint32)((srcBufferBitOffset+copyBitPosition)/8U);
            }
            srcBufferBitOffset = (srcBufferBitOffset+copyBitPosition) % 8U;
            /* Update destination buffer offset and index */
            if (UtilBitCopyPropsPtr->DestBufferEndianess == COM_ENDIANESS_LITTLE)
            {
                /* cert 17223937 - The bit offset and bit position will be within 64, so no overflow */
                /* for Intel format */
                destBufferByteIndex +=(uint32)((destBufferBitOffset+copyBitPosition)/8U);
            }
            else
            {
                /* for Motorola format */
                destBufferByteIndex -=(uint32)((destBufferBitOffset+copyBitPosition)/8U);
            }
            destBufferBitOffset = ((destBufferBitOffset+copyBitPosition) % 8U);
            /* Update the remaining signal length */
            remainingSignalLength = (uint32)(remainingSignalLength-noOfBitsToCopy);
        }
        Com_ExitCriticalSection();
    }
}

/********************************************************************************************************************
*   Service Name     : Com_UtilSetClearBitMask
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UtilSetClearBitMask
(
    CONSTP2VAR(uint8,AUTOMATIC,COM_APPL_DATA) DataPtr ,
    uint8 BitMask ,
    boolean SetMode
)
{
    Com_EnterCriticalSection();
    if(TRUE == SetMode)
    {
        (*(DataPtr)) |= BitMask;
    }
    else
    {
        (*(DataPtr)) &= ((0xFFU) ^ (BitMask));
    }
    Com_ExitCriticalSection();
}

/********************************************************************************************************************
*   Service Name     : Com_UtilSetClearBit
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UtilSetClearBit
(
    CONSTP2VAR(uint8,AUTOMATIC,COM_APPL_DATA) DataPtr ,
    uint8 BitPosition , 
    boolean SetMode
)
{
    Com_EnterCriticalSection();
    if(TRUE == SetMode)
    {
        (*(DataPtr)) |= (uint8)(1U<<BitPosition);
    }
    else
    {
        (*(DataPtr)) &= (uint8)(~(1U<<BitPosition));
    }
    Com_ExitCriticalSection();
}

/********************************************************************************************************************
*   Service Name     : Com_UtilGetSignExtended8BitData
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UtilGetSignExtended8BitData
(
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) DataPtr ,
    uint32 BitSize
)
{
    uint8 Mask;
    uint8 SignMask;

    if (8U > BitSize)
    {
        Mask =(uint8)(0xFFUL >> (8U - BitSize));
        SignMask = ~(Mask >> 1U);
        (*DataPtr) &= Mask;
        if(0U < ((*DataPtr) & SignMask))
        {
            (*DataPtr) |= SignMask; /* add sign bits */
        }
    }
}

/********************************************************************************************************************
*   Service Name     : Com_UtilGetSignExtended16BitData
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UtilGetSignExtended16BitData
(
    P2VAR(uint16,AUTOMATIC,COM_APPL_DATA) DataPtr ,
    uint32 BitSize
)
{
    uint16 Mask;
    uint16 SignMask;

    if (16U > BitSize)
    {
        Mask = (uint16)(0xFFFFUL >> (16U - BitSize));
        SignMask = ~(Mask >> 1U);
        (*DataPtr) &= Mask;
        if(0U < ((*DataPtr) & SignMask))
        {
            (*DataPtr) |= SignMask; /* add sign bits */
        }
    }
}

/********************************************************************************************************************
*   Service Name     : Com_UtilGetSignExtended32BitData
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UtilGetSignExtended32BitData
(
    P2VAR(uint32,AUTOMATIC,COM_APPL_DATA) DataPtr ,
    uint32 BitSize
)
{
    uint32 Mask;
    uint32 SignMask;

    if (32U > BitSize)
    {
        Mask = 0xFFFFFFFFUL >> (32U - BitSize);
        SignMask = ~(Mask >> 1U);
        (*DataPtr) &= Mask;
        if(0U < ((*DataPtr) & SignMask))
        {
            (*DataPtr) |= SignMask; /* add sign bits */
        }
    }
}

/********************************************************************************************************************
*   Service Name     : Com_UtilGetSignExtended64BitData
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UtilGetSignExtended64BitData
(
    P2VAR(uint64,AUTOMATIC,COM_APPL_DATA) DataPtr ,
    uint32 BitSize
)
{
    uint64 Mask;
    uint64 SignMask;

    if (64U > BitSize)
    {
        Mask = 0xFFFFFFFFFFFFFFFFULL >> (64U - BitSize);
        SignMask = ~(Mask >> 1U);
        (*DataPtr) &= Mask;
        if(0U < ((*DataPtr) & SignMask))
        {
            (*DataPtr) |= SignMask; /* add sign bits */
        }
    }
}

/********************************************************************************************************************
*   Service Name     : Com_UtilMemCopy
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UtilMemCopy
(
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) DestPtr , 
    CONSTP2CONST(uint8,AUTOMATIC,COM_APPL_CONST) SrcPtr , 
    PduLengthType Length
)
{
    PduLengthType Idx;
    /* copy number of bytes from [pSrc] to [pDest]. */
    for (Idx = 0; Idx < Length; Idx++)
    {
        DestPtr[Idx] = SrcPtr[Idx];
    }
}

/********************************************************************************************************************
*   Service Name     : Com_UtilMemSet
********************************************************************************************************************/
COM_LOCAL FUNC(void,COM_CODE) Com_UtilMemSet
(
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) DestPtr , 
    uint8 Value , 
    PduLengthType Length
)
{
    PduLengthType Idx;
    /* copy number of bytes from [pSrc] to [pDest]. */
    for (Idx = 0; Idx < Length; Idx++)
    {
        DestPtr[Idx] = Value;
    }
}

#define COM_STOP_SEC_CODE
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
*  @date    14-JUL-2023 
*  @version 1.0.0
*  @author  pchinnat
*  @brief   Implemented of AUTOSAR 4.3 Initial version
*******************************************************************************************************************/
