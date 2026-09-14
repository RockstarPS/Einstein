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
*  File Name         :  Dlt_Cfg.h                                            *
*  Module Short Name :  Dlt_Cfg_H                                            *
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
#ifndef DLT_CFG_H
#define DLT_CFG_H

/*****************************************************************************
 * INCLUDES                                                                  *
 *****************************************************************************/
#include "Std_Types.h"
#include "MemLib.h"
#include "NvM_Cfg.h"
#include "ComStack_Types.h"
#include "DltExt.h"
#include "Rte_Type.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/* Static configurations */

/* Dlt.DltConfigSet.DltProtocol */
#define DLT_HEADERUSEECUID                          STD_ON
#define DLT_HEADERUSESESSIONID                      STD_ON
#define DLT_HEADERUSETIMESTAMP                      STD_ON
#define DLT_USEEXTHEADERINNONVERBMODE               STD_ON
#define DLT_USEVERBOSEMODE                          STD_ON

/* Dlt.DltConfigSet.DltTraceStatusSetting */
#define DLT_DEFAULTTRACESTATUS                      STD_OFF
#define DLT_NUM_TRACESTATUSASSIGNMENTSWCCONTEXTREF  (1U)
#define DLT_NUM_TRACESTATUSASSIGNMENT               (1U)

/* Dlt.DltConfigSet.DltLogOutput */
#define DLT_NUM_TXPDU                               (1U)

/* Dlt.DltConfigSet.DltLogOutput.DltLogChannelAssignment */
#define DLT_NUM_LOGCHANNELREF                       (2U)
#define DLT_NUM_LOGCHANNELASSIGNMENT                (3U)
#define DLT_NUM_LOGCHANNELASSIGNMENTSWCCONTEXTREF   DLT_NUM_SWCCONTEXT

/* Dlt.DltGeneral */
#define DLT_GENERAL_DEVERRORDETECT                  STD_ON 
#define DLT_GENERAL_INJECTIONSUPPORT                STD_OFF
#define DLT_GENERAL_REGISTERCONTEXTNOTIFICATION     STD_OFF
#define DLT_GENERAL_RXDATAPATHSUPPORT               STD_OFF
#define DLT_GENERAL_STARTUPDELAYTIMER               (0U)
#define DLT_GENERAL_TIMESTAMPSUPPORT                STD_OFF
#define DLT_GENERAL_TRAFFICSHAPINGSUPPORT           STD_OFF
#define DLT_GENERAL_VERSIONINFOAPI                  STD_OFF
#define DLT_GENERAL_GPTCHANNELREF_CONFIG            STD_OFF
#define DLT_GENERAL_GPTCHANNELREF                   (GptConf_GptChannelConfiguration_MCU_TIMER1)          //Add GptChannelID
#define DLT_GENERAL_STBMTIMEBASEREF_CONFIG          STD_OFF
#define DLT_GENERAL_STBMTIMEBASEREF                 (0U)          //Add STMBChannelID
#define DLT_GENERAL_NVRAMREF                        (0U)

/* Dlt.DltSwc */
#define DLT_SWC_SESSIONID                           (0U)
#define DLT_SWC_SUPPORTLOGLEVELCHANGENOTIFICATION   STD_OFF
#define DLT_MAXSWCLOGMESSAGELENGTH                  (1024U)
#define DLT_MAXSWCTRACEMESSAGELENGTH                (1024U)

/* Dlt.DltSwc.DltSwcContext */
#define DLT_NUM_SWCCONTEXT                          (3U)

/* Internal Compiler Switches */
#define DLT_USE_VAUTOSAR_DLTEXT                     STD_ON
#define DLT_TESTCODE_EN                             STD_ON
#define DLT_FAULTCOUNTER_ENABLE                     STD_OFF    
#define HARDWARE_FAULTS_EN                          STD_OFF
#define BLOCK_WRITE_ON_EXEPTION                     STD_ON

/* Dlt logging ID for DET */
#define DLT_INSTANCE_ID_DET                         (0x00U)

/* Internal macros*/
#define MAX_MSG_COUNT_RESET                         (0U)
#define MAX_MSG_COUNT_VALUE                         (255U)
#define MAX_ALLOWED_APPIDS                          (126U)
#define DLT_INIT                                    (0U)
#define DLT_UNINIT                                  (1U)
#define DLT_ACTIVE_SESSION                          (0U)
#define DLT_INACTIVE_SESSION                        (1U)
#define MSG_FILTER_ENABLE                           TRUE
#define MSG_FILTER_DISABLE                          FALSE
#define DLT_INTERNAL_BUFFER_SIZE                    (1024U)
#define DLT_ISMSGVERBOSEMODE_BIT                    1U
#define DLT_MAX_NUM_SWCCONTEXT                      128U
#define DLT_MAX_NUM_LOGCHANNELASSIGNMENT            (DLT_MAX_NUM_SWCCONTEXT + DLT_NUM_LOGCHANNELREF)

/* Dlt extended header formation*/
#define DLT_ECUID_VALUE                             (0x45344943U) //{'E','4','I','C'}
#define DLT_ISBIGENDIAN                             (1U)
#define DLT_MAX_HEADER_BUFF_SIZE                    (26U)
/* --- Numeric Configuration Macros --- */
#define DLT_CFG_BUF_SIZE_2048       (2048U)
#define DLT_CFG_MAX_MSG_LEN_8       (8U)
#define DLT_CFG_MAX_MSG_LEN_512     (512U)
#define DLT_CFG_MAX_RETRIES_3       (3U)
#define DLT_CFG_TRAFFIC_SHAPING_100 (100U)
#define DLT_TX_PDU_HANDLE_ID_30     (30U)
#define DLT_CFG_INDEX_0 (0)
#define DLT_CFG_INDEX_1 (1U)
#define DLT_CFG_INDEX_2 (2U)

/* --- Test Function Configuration --- */
#define DLT_TEST_LOG_DATA_LEN       (10U)
#define DLT_TEST_INIT_VAL           (0xFDU)
/* Phase 1: Define Safety Constants */
/* Calculation: 12-byte destination buffer - 4-byte DLT header = 8-byte max payload */
#define DLT_MAX_SAFE_PAYLOAD (8U)
#define DLT_MAX_CHANNEL_VAL (4U)
/*****************************************************************************
*                   External Functions Mapping                               *
******************************************************************************/
Std_ReturnType PduR_DltTransmit(PduIdType TxPduId, PduInfoType PduInfoPtr);
#if(DLT_USE_VAUTOSAR_DLTEXT == STD_ON)
extern void DltExt_MainFunction(void);
extern Std_ReturnType DltExt_SendLogMessage(uint8 *payLoadHeader, uint8 *payLoad, uint16 payLoadHeaderLength, uint16 payLoadLength, uint8 logLevel);
#endif

/*****************************************************************************
*                  Type Declarations                                         *
******************************************************************************/
typedef uint32 Dlt_Internal_ContextIDType;
typedef uint32 Dlt_Internal_ApplicationIDType;
typedef uint32 Dlt_ConfigType;

typedef enum
{
    DLT_TYPE_LOG,
    DLT_TYPE_APP_TRACE,
    DLT_TYPE_NW_TRACE,
    DLT_TYPE_CONTROL,
} Dlt_MessageType;

typedef enum
{
    DLT_E_OK = 0x00,
    DLT_E_NOT_OK = 0x01,
    DLT_E_MSG_TOO_LARGE = 0x02,
    DLT_E_CONTEXT_ALREADY_REG = 0x03,
    DLT_E_UNKNOWN_SESSION_ID = 0x04,
    DLT_E_NO_BUFFER = 0x05,
    DLT_E_CONTEXT_NOT_YET_REG = 0x06,
    DLT_E_NOT_IN_VERBOSE_MODE = 0x07,
    DLT_E_ERROR = 0x09,
} Dlt_ReturnType;

typedef struct 
{
  boolean             initStatus; 
  Dlt_SessionIDType   sessionID;
  boolean             filterEnabled; 
  uint8               regContextIDCount;
}tDlt_LocalConfigDataType;

typedef struct
{
    Dlt_ApplicationIDType DltSwcApplicationId;  // Application ID of the SWC 
    Dlt_ContextIDType DltSwcContextId;          // Context ID of the SWC 
    Dlt_MessageLogLevelType DltLogLevelThreshold; // Log channel threshold 
    boolean DltTraceStatus;
} DltSwcContext_Type;

typedef struct
{
    Dlt_MessageLogLevelType DltDefaultLogLevel; // Default log level 
    uint8 DltLogLevelThreshold;                 // need to be discussed 
} DltLogLevelSetting_Type;

typedef struct
{
    boolean DltTraceStatus;                                    // Enable/disable trace status 
    DltSwcContext_Type *DltTraceStatusAssignmentSwcContextRef; // SWC context reference for trace status assignment 
} DltTraceStatusAssignment_Type;

typedef struct
{
    uint16 DltITxPduHandleId; // TX PDU handle ID 
    boolean DltITxPduUsesTp;  // TX PDU uses TP 
    uint8 DltTxPduIdRef;      // need to discuss 
} DltTxPdu_Type;

typedef struct
{
    float32 DltLogChannelBUfferOverflowTimer;       // Log channel buffer overflow timer 
    uint32 DltLogChannelBUfferSize;                 // Log channel buffer size 
    uint8 DltLogChannelId[DLT_MAX_CHANNEL_VAL];                      // Log channel ID 
    uint16 DltLogChannelMaxMessageLength;           // Log channel maximum message length 
    uint8 DltLogChannelMaxNumOfRetries;             // Log channel maximum number of retries 
    Dlt_MessageLogLevelType DltLogChannelThreshold; // Log channel threshold 
    uint64 DltLogChannelTrafficShapingBandwidth;    // Log channel traffic shaping bandwidth 
    float32 DltLogChannelTransmitCycle;             // Log channel transmit cycle 
    boolean DltLogTraceStatusFlag;                  // Log trace status flag 
    const DltTxPdu_Type *DltTxPdu;                  // TX PDU type 
} DltLogChannel_Type;

typedef struct
{
    DltSwcContext_Type *DltLogChannelAssignmentSwcContextRef; // SWC context reference for log channel assignment, need to confirm 
    DltLogChannel_Type *DltLogChannelRef;                     // need to be discussed 
} DltLogChannelAssignment_Type;

typedef struct
{
    uint32 AppId_Tupple;
    uint32 ContextId_Tupple;
} tDlt_App_Ctx_Tuples;

/*****************************************************************************
*                  Extern Declarations                                       *
******************************************************************************/
extern const tDlt_LocalConfigDataType DltConfig;
extern VAR(DltLogLevelSetting_Type, Dlt_CONST) DltLogLevelSetting;
extern VAR(DltLogChannel_Type, Dlt_CONST) DltDefaultLogChannelRef;
extern VAR(DltLogChannel_Type, Dlt_CONST) DltLogChannelRef[DLT_NUM_LOGCHANNELREF];
extern VAR(DltSwcContext_Type, Dlt_CONST) DltSwcContext[DLT_NUM_SWCCONTEXT];
extern VAR(DltLogChannelAssignment_Type, Dlt_CONST) DltLogChannelAssignment[DLT_NUM_LOGCHANNELASSIGNMENT];

/*****************************************************************************
*                   Function Mapping                                         *
******************************************************************************/
#define DLT_GPT_GETTIMEELAPSED                      Gpt_GetTimeElapsed
#define DLT_STBM_GETCURRENTTIME                     //Add STMB interface
#define DLT_PDUR_TRANSMIT                           PduR_DltTransmit

#if(DLT_GENERAL_DEVERRORDETECT == STD_ON)
#define DLT_DET_REPORTERROR                         Det_ReportError
#else
#define DLT_DET_REPORTERROR                         DLT_E_OK
#endif

#if(DLT_USE_VAUTOSAR_DLTEXT == STD_ON)
#define DLTEXT_CHANNEL_ID                           0x444C5458U //{'D','L','T','X'}
#define DLTEXT_MAIN_CALLOUT                         DltExt_MainFunction
#define DLTEXT_INIT_CALLOUT                         DltExt_Init
#define DLTEXT_FILTERMESSAGE_CALLOUT                DltExt_SendLogMessage
#define DLTEXT_GENERATETIMESTAMP                    DltExt_GetTimeStamp
#endif

#if(DLT_TESTCODE_EN == STD_ON)
void Dlt_testFunction (void);
#define DLT_TESTCODE_CALLOUT                        Dlt_testFunction
#endif
extern CONST(DltTxPdu_Type, Dlt_CONST) Dlt_TxPduConfig[DLT_NUM_TXPDU];
extern CONST(DltLogChannel_Type, Dlt_CONST) Dlt_LogChannelConfig[DLT_NUM_LOGCHANNELREF];
/*****************************************************************************
*                   Reference typedefs                                       *
******************************************************************************/
/*****************************************************************************
typedef struct
{
    boolean DltGeneralDevErrorDetect;                       // Enable/disable development error detection
    boolean DltGeneralInjectionSupport;                     // Enable/disable support for injection
    boolean DltGeneralRegisterContextNotification;          // Enable/disable context notification registration
    boolean DltGeneralRxDataPathSupport;                    // Enable/disable RX data path support
    float32 DltGeneralStartUpDelayTimer;                    // need to be discussed
    boolean DltGeneralTimeStampSupport;                     // Enable/disable timestamp support
    boolean DltGeneralTrafficShapingSupport;                // Enable/disable traffic shaping support
    boolean DltGeneralVersionInfoApi;                       // Enable/disable version info API
    uint8 DltGeneralGptChannelRef;                          // need to be discussed
    uint8 DltGeneralNvRamRef;                               // need to be discussed
    uint8 DltGeneralStbMTimeBaseRef;                        // need to be discussed
} DltGeneral_Type;

typedef struct
{
    uint64 DltSwcSessionId;                                 // Session ID for the SWC 
    boolean DltSwcSupportLogLevelChangeNotification;        // Enable/disable log level change notifications 
    uint64 MaxSwcLogMessageLength;                          // Maximum length of log messages for the SWC 
    uint64 MaxSwcTraceMessageLength;                        // Maximum length of trace messages for the SWC 
    DltSwcContext_Type DltSwcContext;                       // Context information for the SWC 
} DltSwc_Type;

typedef struct
{
    DltConfigSet_Type DltConfigSet;                         // DLT configuration set
    DltGeneral_Type DltGeneral;                             // General DLT settings
    DltSwc_Type DltSwc;                                     // SWC settings
} Dlt_Type;

typedef struct
{
    DltLogChannel_Type DltDefaultLogChannelRef;             // Default log channel reference, need to discuss 
    DltLogChannelAssignment_Type DltLogChannelAssignment;   // Log channel assignment 
} DltLogOutput_Type;

typedef struct
{
    boolean DltDefaultTraceStatus;                          // Default trace status 
    DltTraceStatusAssignment_Type DltTraceStatusAssignment; // Trace status assignment 
} DltTraceStatusSetting_Type;

typedef struct
{
    boolean DltHeaderUseEcuId;                              // Use ECU ID in the header 
    boolean DltHeaderUseSessionID;                          // Use Session ID in the header 
    boolean DltHeaderUseTimestamp;                          // Use timestamp in the header 
    boolean DltUseExtHeaderInNonVerbMode;                   // Use extended header in non-verbose mode 
    boolean DltUseVerboseMode;                              // Use verbose mode 
    uint32 DltEcuId                                         // need to be discussed 
} DltProtocol_Type;

typedef struct
{
    DltProtocol_Type DltProtocol;                           // DLT protocol type
    DltLogLevelSetting_Type DltLogLevelSetting;             // DLT log level setting
    DltTraceStatusSetting_Type DltTraceStatusSetting;       // DLT trace status setting
    DltLogOutput_Type DltLogOutput;                         // DLT log output
} DltConfigSet_Type;

typedef struct
{
    uint16 DltIRxPduHandleId;                               // RX PDU handle ID 
    boolean DltIRxPduUsesTp;                                // RX PDU uses TP 
    uint8 DltRxPduIdRef                                     // need to discuss 
} DltRxPdu_Type;

*****************************************************************************/

/*****************************************************************************
*                  EOF - End of file                                         *
******************************************************************************/
#endif /* DLT_CFG_H */
