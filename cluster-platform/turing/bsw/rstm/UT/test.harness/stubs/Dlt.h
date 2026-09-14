/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2017. Visteon Corporation owns all rights to           *
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
*  File Name         :  Dlt.h                                                *
*  Module Short Name :  Dlt                                                  *
*  Description       :                                                       *
*                                                                            *
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

#ifndef DLT_H
#define DLT_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Dlt_Cfg.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/* vendor and module identification */
# define DLT_VENDOR_ID                       (30U)
# define DLT_MODULE_ID                       (55U) /* ESCAN00087212 */

/* AUTOSAR Software specification version information */
# define DLT_AR_RELEASE_MAJOR_VERSION        (4U)
# define DLT_AR_RELEASE_MINOR_VERSION        (3U)
# define DLT_AR_RELEASE_REVISION_VERSION     (1U)

/* Component version information (decimal version of ALM implementation package) */
# define DLT_SW_MAJOR_VERSION                (5U)
# define DLT_SW_MINOR_VERSION                (1U)
# define DLT_SW_PATCH_VERSION                (0U)

/* Dlt protocol version number */
#define DLT_PROTOCOL_VERSION                 (0x01U)
#define DLT_PROTOCOL_VERSION_MASK            (0x07U)

/* Internal Macros*/
#define REGISTER_CONTEXT                     (5U)
#define UNREGISTER_CONTEXT                   (6U)
#define UNUSED(x)                            (void)(x)

/* Tuple conversion*/
#define DLT_UINT32_TUPLE_MSB_FIRST(ptr)      ( (uint32) \
                                             ( ((uint32)((ptr)[0]) << 24U) \
                                             | ((uint32)((ptr)[1]) << 16U) \
                                             | ((uint32)((ptr)[2]) << 8U)  \
                                             | ((uint32)((ptr)[3]) ) ) )

#define DLT_UINT32_CONVERT_TUPLE(ptr)       DLT_UINT32_TUPLE_MSB_FIRST(ptr) /* Converting the Tuple in to uint32 variable */

/* Dlt header formation*/
#define DLT_HEADER_BIT_UEH                  (0U)
#define DLT_HEADER_BIT_MSBF                 (1U)
#define DLT_HEADER_BIT_WEID                 (2U)
#define DLT_HEADER_BIT_WSID                 (3U)
#define DLT_HEADER_BIT_WTMS                 (4U)

/* Dlt extended header formation*/
#define DLT_EXTENDED_HEADER_BIT_VERB        (0U)
#define DLT_MSTP_FIELD_CLEAR_MASK           (0xF1U)     //Bit 1-3: MSTP
#define DLT_MSTP_FIELD_SET_MASK             (0x02U)     //Bit 1-3: MSTP
#define DLT_MTIN_FIELD_MASK                 (0xF0U)     //Bit 4-7: MSTP

/* API service IDs */
# define DLT_API_ID_INIT                     ((uint8)0x01U) /*!< ASR4.0 Dlt_Init() service ID [Dlt239]. */
# define DLT_API_ID_GETVERSIONINFO           ((uint8)0x02U) /*!< ASR4.0 Dlt_GetVersionInfo() service ID [Dlt271]. */
# define DLT_API_ID_SENDLOGMESSAGE           ((uint8)0x03U) /*!< ASR4.0 Dlt_SendLogMessage() service ID [Dlt241]. */
# define DLT_API_ID_SENDTRACEMESSAGE         ((uint8)0x04U) /*!< ASR4.0 Dlt_SendTraceMessage() service ID [Dlt243]. */
# define DLT_API_ID_REGISTERCONTEXT          ((uint8)0x05U) /*!< ASR4.0 Dlt_RegisterContext() service ID [Dlt245]. */
# define DLT_API_ID_RESETTOFACTORYDEFAULT    ((uint8)0x06U) /*!< ASR4.0 Dlt_ResetToFactoryDefault() service ID [SWS_Dlt_00739]. */
# define DLT_API_ID_DETFORWARDERRORTRACE     ((uint8)0x07U) /*!< ASR4.0 Dlt_DetForwardErrorTrace() service ID [Dlt432]. */
# define DLT_API_ID_SETLOGLEVEL              ((uint8)0x08U) /*!< ASR4.0 Dlt_SetLogLevel() service ID [SWS_Dlt_00252]. */
# define DLT_API_ID_SETTRACESTATUS           ((uint8)0x09U) /*!< ASR4.0 Dlt_SetTraceStatus() service ID [SWS_Dlt_00254]. */
# define DLT_API_ID_GETLOGINFO               ((uint8)0x0AU) /*!< ASR4.0 Dlt_GetLogInfo() service ID [SWS_Dlt_00732]. */
# define DLT_API_ID_SETDEFAULTLOGLEVEL       ((uint8)0x11U) /*!< ASR4.0 Dlt_SetDefaultLogLevel() service ID [SWS_Dlt_00740]. */
# define DLT_API_ID_SETDEFAULTTRACESTATUS    ((uint8)0x12U) /*!< ASR4.0 Dlt_SetDefaultTraceStatus() service ID [SWS_Dlt_00743]. */
# define DLT_API_ID_INJECTCALL               ((uint8)0x14U) /*!< ASR4.0 Dlt_InjectCall() service ID [SWS_Dlt_00259]. */
# define DLT_API_ID_DEMTRIGGERONEVENTSTATUS  ((uint8)0x15U) /*!< ASR4.0 Dlt_DemTriggerOnEventStatus() service ID [Dlt470]. */
# define DLT_API_ID_GETLOGCHANNELNAMES       ((uint8)0x17U) /*!< ASR4.0 Dlt_GetLogChannelNames() service ID [SWS_Dlt_00749]. */
# define DLT_API_ID_GETDEFAULTLOGLEVEL       ((uint8)0x18U) /*!< ASR4.0 Dlt_GetDefaultLogLevel() service ID [SWS_Dlt_00733]. */
# define DLT_API_ID_GETDEFAULTTRACESTATUS    ((uint8)0x19U) /*!< ASR4.0 Dlt_GetDefaultTraceStatus() service ID [SWS_Dlt_00746]. */
# define DLT_API_ID_STORECONFIGURATION       ((uint8)0x1AU) /*!< ASR4.0 Dlt_StoreConfiguration() service ID [SWS_Dlt_00736]. */
# define DLT_API_ID_SETMESSAGEFILTERING      ((uint8)0x1BU) /*!< ASR4.0 Dlt_SetMessageFiltering() service ID [SWS_Dlt_00770]. */
# define DLT_API_ID_GETTRACESTATUS           ((uint8)0x1FU) /*!< ASR4.0 Dlt_GetTraceStatus() service ID [SWS_Dlt_00750]. */
# define DLT_API_ID_SETLOGCHANNELASSIGNMENT  ((uint8)0x20U) /*!< ASR4.0 Dlt_SetLogChannelAssignment() service ID [SWS_Dlt_00751]. */
# define DLT_API_ID_SETLOGCHANNELTHRESHOLD   ((uint8)0x21U) /*!< ASR4.0 Dlt_SetLogChannelThreshold() service ID [SWS_Dlt_00752]. */
# define DLT_API_ID_GETLOGCHANNELTHRESHOLD   ((uint8)0x22U) /*!< ASR4.0 Dlt_GetLogChannelThreshold() service ID [SWS_Dlt_00753]. */
# define DLT_API_ID_COPYTXDATA               ((uint8)0x43U) /*!< ASR4.0 Dlt_CopyTxData() service ID [SWS_Dlt_00516]. */
# define DLT_API_ID_COPYRXDATA               ((uint8)0x44U) /*!< ASR4.0 Dlt_CopyRxData() service ID [SWS_Dlt_91008]. */
# define DLT_API_ID_TPRXINDICATION           ((uint8)0x45U) /*!< ASR4.0 Dlt_TpRxIndication() service ID [SWS_Dlt_91007]. */
# define DLT_API_ID_STARTOFRECEPTION         ((uint8)0x46U) /*!< ASR4.0 Dlt_StartOfReception() service ID [SWS_Dlt_91006]. */
# define DLT_API_ID_TPTXCONFIRMATION         ((uint8)0x48U) /*!< ASR4.0 Dlt_TpTxConfirmation() service ID [SWS_Dlt_00756]. */
# define DLT_API_ID_MAINFUNCTION             ((uint8)0x50U) /*!< MSR4.0 Dlt_MainFunction() service ID. */
# define DLT_API_ID_SETSTATE                 ((uint8)0x51U) /*!< MSR4.0 Dlt_SetState() service ID. */
# define DLT_API_ID_GETSTATE                 ((uint8)0x52U) /*!< MSR4.0 Dlt_GetState() service ID. */

/*****************************************************************************
*                  Type Declarations                                         *
******************************************************************************/
typedef enum
{
    eDlt_Transmit_Idle,
    eDlt_Transmit_InProgress,
} Dlt_TxStatusType;

typedef struct {
    uint8 buffer[DLT_INTERNAL_BUFFER_SIZE]; // Circular buffer for the LogChannel
    uint8 head;                             // Write index
    uint16 count;                           // Current number of bytes in the buffer
    boolean overflowFlag;                   // Buffer overflow flag
    uint16 maxMessageLength;                // Maximum message length allowed for this channel
    PduIdType TxPduId;
    uint8 MaxNumOfRetries;
    uint8 TransmitCounter;
    Dlt_TxStatusType TxStatus;
} LogChannelBufferType;

typedef struct 
{
    uint32 applicationId;
    uint32 contextId;
    DltSwcContext_Type *LogChannelAssignmentPtr;
    DltLogChannel_Type *LogChannelPtr[DLT_NUM_LOGCHANNELREF];
    uint32 MessageLength;
    uint8 channelCount;
} DltLogMsgInfo;

/*****************************************************************************
*                            Function Prototypes                             *
******************************************************************************/ 

/*============================================================================
**
** Function Name    :   Dlt_Init
**
** Visibility       :   Public
**
** Description      :
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
void Dlt_Init(const Dlt_ConfigType *config);

/*============================================================================
**
** Function Name    :   Dlt_DemTriggerOnEventData
**
** Visibility       :   Public
**
** Description      :   Triggers on changes of the event related data in the
**                      event memory.
**
** Invocation       :
**
** Inputs           :   Dem_EventIdType EventId - event id
**
** Outputs          :   DLT_E_OK - if success
**                      DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_DemTriggerOnEventData(Dem_EventIdType EventId);

/*============================================================================
**
** Function Name    :   Dlt_RxIndication
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
void Dlt_RxIndication(PduIdType RxPduId, const PduInfoType *PduInfoPtr);

/*============================================================================
**
** Function Name    :   Dlt_TriggerTransmit
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_TriggerTransmit(PduIdType TxPduId, PduInfoType *PduInfoPtr);

/*============================================================================
**
** Function Name    :   Dlt_TxConfirmation
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
void Dlt_TxConfirmation(PduIdType TxPduId, Std_ReturnType result);

/*============================================================================
**
** Function Name    :   Dlt_TpTxConfirmation
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
void Dlt_TpTxConfirmation(PduIdType PduId, Std_ReturnType result);

/*============================================================================
**
** Function Name    :   Dlt_CopyTxData
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
BufReq_ReturnType Dlt_CopyTxData(PduIdType id, const PduInfoType *info, const RetryInfoType *retry, PduLengthType *availableDataPtr);

/*============================================================================
**
** Function Name    :   Dlt_StartOfReception
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
BufReq_ReturnType Dlt_StartOfReception(PduIdType id, const PduInfoType *info, PduLengthType TpSduLength, PduLengthType *bufferSizePtr);

/*============================================================================
**
** Function Name    :   Dlt_TpRxIndication
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
void Dlt_TpRxIndication(PduIdType id, Std_ReturnType result);

/*============================================================================
**
** Function Name    :   Dlt_CopyRxData
**
** Visibility       :   Public
**
** Description      :   Sets the filter threshold for the given LogChannel.
**
** Invocation       :
**
** Inputs           :   Dlt_LogChannelNameType logChannelName - Name of logchannel
**                      Dlt_MessageLogLevelType newThreshold - New threshold
**                      boolean newTraceStatus - set trace status
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
BufReq_ReturnType Dlt_CopyRxData(PduIdType id, const PduInfoType *info, PduLengthType *bufferSizePtr);

/*============================================================================
**
** Function Name    :   Dlt_SetMessageFiltering
**
** Visibility       :   Public
**
** Description      :   Switches on/off the message filtering functionality of
**                      the Dlt module.
**
** Invocation       :
**
** Inputs           :   boolean MessageFiltering - sets the message filtering
**
** Outputs          :  DLT_E_OK - if success
**                     DLT_E_NOT_OK - if error occured
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType Dlt_SetMessageFiltering(boolean MessageFilteringStatus);

#endif /* DLT_H */
