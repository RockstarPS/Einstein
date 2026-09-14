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
 *    @file ComM_Lcfg.h
 *    @ingroup ComConfiguration
 *    @brief This is Com Link compile time configuration header file. It contains definitions of Link time
 *    configuration parameters for the Com module.
 ********************************************************************************************************************/

#ifndef COM_LCFG_H
#define COM_LCFG_H

#include "Com_Types.h"

/*********************************************************************************************************************
 *                                       #! GLOBAL VARIABLES                                                          *
 *********************************************************************************************************************/
/*********************************************************************************************************************
 *                                 #! Ipdu group global variable                                                      *
 *********************************************************************************************************************/
#define COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

extern VAR(Com_IpduGroupVector, COM_VAR_NOINIT) Com_IpduGroupMapValue;

#define COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"
/*********************************************************************************************************************
 *                                 #! ComAbsMdl_OnData                                                    *
 *********************************************************************************************************************/
extern void CComAbsMdl_OnDataRx_DayNightMode(void);
extern void CComAbsMdl_OnDataRx_PowerMode(void);
extern void CComAbsMdl_OnDataTx_SecureTxByte0(void);
extern void CComAbsMdl_OnDataTx_Odometer(void);
extern void CComAbsMdl_OnDataTx_VehicleSpeedIC(void);
extern void CComAbsMdl_OnDataTx_Illumination_PWM(void);
extern void CComAbsMdl_OnDataTx_Debug1_Byte0(void);
extern void CComAbsMdl_OnDataTx_Debug2_Byte0(void);
extern void CComAbsMdl_OnDataTx_Debug3_Byte0(void);
extern void CComAbsMdl_OnDataTx_Debug4_Byte0(void);
extern void CComAbsMdl_OnDataTx_Debug5_Byte0(void);
/*********************************************************************************************************************
 *                                 #! Transmit global variable                                                        *
 *********************************************************************************************************************/
#define COM_START_SEC_VAR_NO_INIT_8
#include "MemMap.h"

/*! @brief Array to handle Tx Pdu Configuration */
extern VAR(uint8, COM_VAR_NOINIT) Com_TxIpduBuffer[COM_TX_IPDU_BUFFER_SIZE];
#if (COM_TX_SIGNAL_GROUP_SUPPORT == STD_ON)
/*! @brief  Tx Ipdu signal group trigger  status  .*/
extern VAR(uint8, COM_VAR_NOINIT) Com_TxSignalGroupTxTriggerStatus[COM_NUM_OF_TX_SIGNAL_GROUP_ID];
/*! @brief Rx Ipdu Tx Shadow buffer  */
extern VAR(uint8, COM_VAR_NOINIT) Com_TxIpduShadowBuffer[COM_TX_SHADOW_BUFFER_SIZE];
#endif
#if (COM_TX_TP_IPDU_SUPPORT == STD_ON)
/*! @brief Rx Ipdu Tp buffer */
extern VAR(uint8, COM_VAR_NOINIT) Com_TxTpIpduBuffer[COM_TX_TP_TOTAL_BUFFERS];
/*! @brief Rx Ipdu Tp Rte buffer */
extern VAR(uint8, COM_VAR_NOINIT) Com_TxTpIpduBufferState[COM_NUM_OF_TX_TP_IPDU_ID];
#endif

#define COM_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

/*! @brief  Tx periodic counter  .*/
extern VAR(boolean, COM_VAR_NOINIT) Com_TxIpduPeriodicTransmitRequest[COM_NUM_OF_TX_IPDU_ID];
/*! @brief  Tx transmit request  .*/
extern VAR(boolean, COM_VAR_NOINIT) Com_TxIpduTransmitRequest[COM_NUM_OF_TX_IPDU_ID];
/*! @brief  Tx group active state  .*/
extern VAR(boolean, COM_VAR_NOINIT) Com_TxIpduGroupActiveState[COM_NUM_OF_TX_IPDU_ID];
/*! @brief  Tx confirmation wait status  .*/
extern VAR(boolean, COM_VAR_NOINIT) Com_TxIpduConfirmationWaitStatus[COM_NUM_OF_TX_IPDU_ID];
/*! @brief  Tx Deferred notification status  .*/
extern VAR(boolean, COM_VAR_NOINIT) Com_TxIpduDefferedNotificationStatus[COM_NUM_OF_TX_IPDU_ID];
#if (COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON)
/*! @brief signal filter state  .*/
extern VAR(boolean, COM_VAR_NOINIT) Com_TxSignalFilterState[COM_NUM_OF_TX_SIGNAL_FILTER_ID];
#endif

#define COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_32
#include "MemMap.h"

#if (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*! @brief  the timeout counter  .*/
extern VAR(uint32, COM_VAR_NOINIT) Com_TxIpduTxTimeoutCounter[COM_NUM_OF_TX_IPDU_TIMEOUT_COUNTER_ID];
#endif
/*! @brief  Tx Repetition count  .*/
extern VAR(uint32, COM_VAR_NOINIT) Com_TxIpduRepetitionCount[COM_NUM_OF_TX_IPDU_ID];
/*! @brief  Tx Repetition cycle counter  .*/
extern VAR(uint32, COM_VAR_NOINIT) Com_TxIpduRepetitionCycleCounter[COM_NUM_OF_TX_IPDU_ID];
/*! @brief  Tx Minimum delay counter  .*/
extern VAR(uint32, COM_VAR_NOINIT) Com_TxIpduMinimumDelayCounter[COM_NUM_OF_TX_IPDU_ID];
/*! @brief  Tx Minimum delay counter  .*/
extern VAR(uint32, COM_VAR_NOINIT) Com_TxIpduPeriodicCounter[COM_NUM_OF_TX_IPDU_ID];

#define COM_STOP_SEC_VAR_NO_INIT_32
#include "MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/*! @brief  Tx Ipdu buffer length status  .*/
extern VAR(PduLengthType, COM_VAR_NOINIT) Com_TxIpduBufferLength[COM_NUM_OF_TX_IPDU_ID];
/*! @brief  Tx Ipdu mode  .*/
extern VAR(Com_TxIpduTxModeType, COM_VAR_NOINIT) Com_TxIpduTxMode[COM_NUM_OF_TX_IPDU_ID];
#if (COM_TX_TP_IPDU_SUPPORT == STD_ON)
/*! @brief Rx Ipdu Tx Tp current position data to be transmitted  */
extern VAR(PduLengthType, COM_VAR_NOINIT) Com_TxTpIpduCurrentPosition[COM_NUM_OF_TX_TP_IPDU_ID];
#endif

#define COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/*********************************************************************************************************************
 *                                 #! Receive global variable                                                         *
 *********************************************************************************************************************/
#define COM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

/*! @brief Rx Ipdu deferred processing status  */
extern VAR(boolean, COM_VAR_NOINIT) Com_RxIpduDeferredProcessingState[COM_NUM_OF_RX_IPDU_ID];
/*! @brief Rx Ipdu group activate state */
extern VAR(boolean, COM_VAR_NOINIT) Com_RxIpduGroupActiveState[COM_NUM_OF_RX_IPDU_ID];
#if (COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*! @brief Rx Ipdu dead line monitoring state   */
extern VAR(boolean, COM_VAR_NOINIT) Com_RxIpduDeadlineMonitoringState[COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID];
#endif
#if (COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*! @brief Rx signal dead line monitoring state   */
extern VAR(boolean, COM_VAR_NOINIT) Com_RxSigDeadlineMonitoringState[COM_NUM_OF_RX_SIGNAL_TIMEOUT_COUNTER_ID];
#endif
#if (COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*! @brief Rx signal group dead line monitoring state   */
extern VAR(boolean, COM_VAR_NOINIT) Com_RxSigGroupDeadlineMonitoringState[COM_NUM_OF_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_ID];
#endif
#define COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_8
#include "MemMap.h"

#if (COM_RX_TP_IPDU_SUPPORT == STD_ON)
/*! @brief  Rx Tp buffer .*/
extern VAR(uint8, COM_VAR_NOINIT) Com_RxTpIpduBuffer[COM_RX_TP_BUFFER_SIZE];
/*! @brief  Rx Tp Ipdu rte buffer  .*/
extern VAR(uint8, COM_VAR_NOINIT) Com_RxTpIpduRteBuffer[COM_RX_TP_BUFFER_SIZE];
/*! @brief  Rx Tp Ipdu buffer state   .*/
extern VAR(uint8, COM_VAR_NOINIT) Com_RxTpIpduBufferState[COM_NUM_OF_RX_TP_IPDU_ID];
#endif
/*! @brief Buffer used for storing the Rx Message */
extern VAR(uint8, COM_VAR_NOINIT) Com_RxIpduBuffer[COM_RX_IPDU_BUFFER_SIZE];
/*! @brief Defines the Com-Rte signals buffer for uint8  signal */
extern VAR(uint8, COM_VAR_NOINIT) Com_RxSignalRteU8Buffer[COM_RX_SIGNAL_RTE_U8BUFFER_SIZE];
/*! @brief Defines the Com-Rte signals buffer for uint_n or uint_dyn  signal */
extern VAR(uint8, COM_VAR_NOINIT) Com_RxSignalRteArrBuffer[COM_RX_SIGNAL_RTE_ARRBUFFER_SIZE];
/* Signal group buffers */
#if (COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
/*! @brief Defines the Com-Rte signals buffer for uint8  signal */
extern VAR(uint8, COM_VAR_NOINIT) Com_RxSignalShadowRteU8Buffer[COM_RX_SIGNAL_SHADOW_RTE_U8BUFFER_SIZE];
/*! @brief Defines the Com-Rte signals buffer for uint_n or uint_dyn  signal */
extern VAR(uint8, COM_VAR_NOINIT) Com_RxSignalShadowRteArrBuffer[COM_RX_SIGNAL_SHADOW_RTE_ARRBUFFER_SIZE];
#endif

#if (COM_RX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON)
extern VAR(uint8, COM_VAR_NOINIT) Com_RxSignalGroupRteArrayBuffer[COM_RX_SIGNAL_GROUP_RTE_ARRAY_BUFFER_SIZE];
#endif

#define COM_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_16
#include "MemMap.h"

/*! @brief Defines the Com-Rte signals buffer for uint16  signal */
extern VAR(uint16, COM_VAR_NOINIT) Com_RxSignalRteU16Buffer[COM_RX_SIGNAL_RTE_U16BUFFER_SIZE];
#if (COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
/*! @brief Defines the Com-Rte signals buffer for uint16  signal */
extern VAR(uint16, COM_VAR_NOINIT) Com_RxSignalShadowRteU16Buffer[COM_RX_SIGNAL_SHADOW_RTE_U16BUFFER_SIZE];
#endif

#define COM_STOP_SEC_VAR_NO_INIT_16
#include "MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_32
#include "MemMap.h"

#if (COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*! @brief Rx Ipdu Dead line counter   */
extern VAR(uint32, COM_VAR_NOINIT) Com_RxIpduDeadlineCounter[COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID];
#endif
#if (COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*! @brief Rx signal  dead line monitoring counter   */
extern VAR(uint32, COM_VAR_NOINIT) Com_RxSigDeadlineCounter[COM_NUM_OF_RX_SIGNAL_TIMEOUT_COUNTER_ID];
#endif
#if (COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*! @brief Rx signal group dead line monitoring counter   */
extern VAR(uint32, COM_VAR_NOINIT) Com_RxSigGroupDeadlineCounter[COM_NUM_OF_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_ID];
#endif
/*! @brief Defines the Com-Rte signals buffer for uint32  signal */
extern VAR(uint32, COM_VAR_NOINIT) Com_RxSignalRteU32Buffer[COM_RX_SIGNAL_RTE_U32BUFFER_SIZE];
#if (COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
/*! @brief Defines the Com-Rte signals buffer for uint32  signal */
extern VAR(uint32, COM_VAR_NOINIT) Com_RxSignalShadowRteU32Buffer[COM_RX_SIGNAL_SHADOW_RTE_U32BUFFER_SIZE];
#endif

#define COM_STOP_SEC_VAR_NO_INIT_32
#include "MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#if (COM_RX_TP_IPDU_SUPPORT == STD_ON)
/*! @brief  Rx Tp Ipdu bytes copied in current reception   .*/
extern VAR(PduLengthType, COM_VAR_NOINIT) Com_RxTpIpduBytesCopied[COM_NUM_OF_RX_TP_IPDU_ID];
#endif
/*! @brief Rx Ipdu received length   */
extern VAR(PduLengthType, COM_VAR_NOINIT) Com_RxIpduBufferLength[COM_NUM_OF_RX_IPDU_ID];

/*! @brief Defines the Com-Rte signals buffer for uint64  signal */
extern VAR(uint64, COM_VAR_NOINIT) Com_RxSignalRteU64Buffer[COM_RX_SIGNAL_RTE_U64BUFFER_SIZE];
#if (COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
/*! @brief Defines the Com-Rte signals buffer for uint64  signal */
extern VAR(uint64, COM_VAR_NOINIT) Com_RxSignalShadowRteU64Buffer[COM_RX_SIGNAL_SHADOW_RTE_U64BUFFER_SIZE];
#endif

#define COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/*********************************************************************************************************************
 *                                 #! Transmit IPDU const config  data                                                *
 *********************************************************************************************************************/
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/* @brief   Configuration for the Tx PDU and Com_IpduGroupVector Mapping
    Elements            :   Description
    IpduGroupVectorMap  :   the I-PDU group bit mask for the I-PDU
*/
extern CONST(Com_IpduToIpduGroupMapConfigType, COM_CONFIG_DATA) Com_IpduToIpduGroupMapTxConfig[COM_NUM_OF_TX_IPDU_ID];

/* @brief Configuration of Tx I-PDU
    Elements                    :   Description
    TxIpduClearUpdateBitType    :   Defines when the update-bits will be cleared
    IpduType                    :   defines the Ipdu type , Normal or TP
    IpduSignalProcessingType    :   defines the Ipdu signal processing type , deferred or immediate
    SignalStartId               :   the signal config start index of Com_TxSignalConfig
    SignalEndId                 :   the signal config end index of Com_TxSignalConfig
    MinimumDelayTime            :   the Minimum Delay Time (MDT) between successive transmissions of this I-PDU
                                    Enabled only if COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION is STD_ON.
    TxTimeoutValue              :   the length of the deadline monitoring timeout period in milliseconds
                                    Enabled only if COM_TX_TIMEOUT_COUNTER_SUPPORT is STD_ON.
    FirstTimeout                :   the length of the first deadline monitoring timeout period in milliseconds.
                                    Enabled only if COM_TX_TIMEOUT_COUNTER_SUPPORT is STD_ON.
    TargetIpduId                :   the PDU ID which used for transmission request to the lower layer
    TpConfigId                  :   the PDU ID which used for Tp Buffer Config Index - Com_TxTpIpduBufferConfig
                                    Enabled only if COM_TX_TP_IPDU_SUPPORT is STD_ON.
    TxPeriodicCounterId         :   the periodic counter Index for the I-PDU - Com_TxIpduPeriodicCounter
    TxTimeoutCounterId          :   the Tx timeout counter index for the I-PDU - Com_TxIpduTxTimeoutCounter
                                    Enabled only if COM_TX_TIMEOUT_COUNTER_SUPPORT is STD_ON.
    SignalGroupStartId          :   the signal group config start index of Com_TxSignalGroupConfig.
                                    Enabled only if COM_TX_SIGNAL_GROUP_SUPPORT is STD_ON.
    SignalGroupEndId            :   the signal group config end index of Com_TxSignalGroupConfig.
                                    Enabled only if COM_TX_SIGNAL_GROUP_SUPPORT is STD_ON.
    SignalFilterStartId         :   the signal filter config start index of Com_TxSignalGroupConfig.
                                    Enabled only if COM_TX_SIGNAL_FILTER_SUPPORT is STD_ON.
    SignalFilterEndId           :   the signal filter config end index of Com_TxSignalGroupConfig.
                                    Enabled only if COM_TX_SIGNAL_FILTER_SUPPORT is STD_ON.
    IpduCancellationSupport     :   Defines whether the I-PDU transmit cancellation is supported
                                    Enabled only if COM_TX_IPDU_CANCELLATION_SUPPORT is STD_ON.
    IpduCalloutFunctId          :   the I-PDU TX transmit callout function config index of Com_TxIpduCalloutFuncConfig
                                    Enabled only if COM_TX_IPDU_CALLOUT_SUPPORT is STD_ON.
    TriggerTxCalloutFunctId     :   the I-PDU TX trigger transmit callout config function index of
                                    Com_TxIpduTriggerTxCalloutFunctConfig. Enabled only if
                                    COM_TX_IPDU_TRIGGER_TRANSMIT_SUPPORT is STD_ON.
    IpduCounterId               :   the I-PDU TX counter config index of Com_IpduCounterConfig
                                    Enabled only if COM_TX_IPDU_COUNTER_SUPPORT is STD_ON.
    NoIpduGroupSupported        :   the I-PDU has No Ipdu group
                                    Enabled only if COM_TX_PDU_NO_GROUP_SUPPORT is STD_ON
*/
extern CONST(Com_TxIpduConfigType, COM_CONFIG_DATA) Com_TxIpduConfig[COM_NUM_OF_TX_IPDU_ID];

/*  @brief  Defines the configuration for the transmission mode of I-PDU for TxModeType True
    Elements            :   Description
    TxModeModeType      :   the type of transmission modes for the I-PDU.
    RepetitionCount     :   the number of repetitions for the transmission mode DIRECT or MIXED.
    RepetitionPeriod    :   the repetition period of the multiple transmissions in
                            case ComTxModeNumberOfRepetitions is configured greater than or equal to 1 and
                            ComTxModeMode is configured to DIRECT or MIXED.
    TimeOffset          :   the period between the start of the I-PDU by Com_IpduGroupControl
                            and the first transmission request.
    TimePeriod          :   the repetition period of the periodic transmission requests for PERIODIC or MIXED.
*/
extern CONST(Com_TxIpduTxModeConfigType, COM_CONFIG_DATA) Com_TxIpduTxModeTrueConfig[COM_NUM_OF_TX_IPDU_ID];

/* @brief  Defines the configuration for the transmission mode of I-PDU for TxModeType False
    Elements            :   Description
    TxModeModeType      :   the type of transmission modes for the I-PDU.
    RepetitionCount     :   the number of repetitions for the transmission mode DIRECT or MIXED.
    RepetitionPeriod    :   the repetition period of the multiple transmissions in
                            case ComTxModeNumberOfRepetitions is configured greater than or equal to 1 and
                            ComTxModeMode is configured to DIRECT or MIXED.
    TimeOffset          :   the period between the start of the I-PDU by Com_IpduGroupControl
                            and the first transmission request.
    TimePeriod          :   the repetition period of the periodic transmission requests for PERIODIC or MIXED.
*/
extern CONST(Com_TxIpduTxModeConfigType, COM_CONFIG_DATA) Com_TxIpduTxModeFalseConfig[COM_NUM_OF_TX_IPDU_ID];

#if (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/* @brief Defines the configuration of the Tx timeout counter configuration
    Elements    :   Description
    TxIpduId    :   the Tx I-PDU Id for this timeout counter Id
*/
extern CONST(Com_TxIpduTimeoutCounterConfigType, COM_CONFIG_DATA) Com_TxIpduTimeoutCounterConfig[COM_NUM_OF_TX_IPDU_TIMEOUT_COUNTER_ID];
#endif
/* @brief defines the transmit I-PDU buffer configuration
    Elements        :   Description
    BufferStartId   :   the start index of the TX I-PDU buffer Com_TxIpduBuffer
    BufferEndId     :   the Ends index of the TX I-PDU buffer Com_TxIpduBuffer
    MinimumLength   :   the minimum Tx I-PDU length
    MaximumLength   :   the maximum Tx I-PDU length
    MetaDataLength  :   the Tx I-PDU meta data length. Enabled only if COM_TX_IPDU_META_DATA_SUPPORT is STD_ON
*/
extern CONST(Com_TxIpduBufferConfigType, COM_CONFIG_DATA) Com_TxIpduBufferConfig[COM_NUM_OF_TX_IPDU_ID];

#if (COM_TX_IPDU_TRIGGER_TRANSMIT_SUPPORT == STD_ON)
/* @brief the trigger transmit callout function config for a Ipdu Id
    Elements                            :   Description
    Com_TxIpduTriggerTxCalloutFunctType :   the trigger transmit callout function for a Ipdu Id
*/
extern CONST(Com_TxIpduTriggerTxCalloutFunctType, COM_CONFIG_DATA) Com_TxIpduTriggerTxCalloutFunctConfig[COM_NUM_OF_TX_IPDU_TRIGGER_TX_CALLOUT_FUNC_ID];
#endif

#if (COM_TX_IPDU_CALLOUT_SUPPORT == STD_ON)
/* @brief  the transmit callout function config for a Ipdu Id
    Elements                   :   Description
    Com_TxIpduCalloutFunctType :   the transmit callout function for a Ipdu Id
*/
extern CONST(Com_TxIpduCalloutFunctType, COM_CONFIG_DATA) Com_TxIpduCalloutFuncConfig[COM_NUM_OF_TX_IPDU_CALLOUT_FUNC_ID];
#endif

#if (COM_TX_TP_IPDU_SUPPORT == STD_ON)
/* @brief the Tx Tp Ipdu buffer config type
    Elements        :   Description
    BufferStartId   :   the start index of the TX I-PDU buffer Com_TxTpIpduBuffer
    BufferEndId     :   the Ends index of the TX I-PDU buffer Com_TxTpIpduBuffer
    MinimumLength   :   the minimum Tx I-PDU length
    MaximumLength   :   the maximum Tx I-PDU length
*/
extern CONST(Com_TxTpIpduBufferConfigType, COM_CONFIG_DATA) Com_TxTpIpduBufferConfig[COM_NUM_OF_TX_TP_IPDU_ID];
#endif

#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define COM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

/* @brief Defines the initial value for the Tx I-PDU buffer */
extern CONST(uint8, COM_CONFIG_DATA) Com_TxIpduBufferInitValues[COM_TX_IPDU_BUFFER_SIZE];

#if (COM_TX_TP_IPDU_SUPPORT == STD_ON)
/* @brief Defines the initial value for the Tx Tp I-PDU buffer */
extern CONST(uint8, COM_CONFIG_DATA) Com_TxTpIpduBufferInitValues[COM_TX_TP_TOTAL_BUFFERS];
#endif

#define COM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

/*********************************************************************************************************************
 *                                 #! Transmit signal const config data                                               *
 *********************************************************************************************************************/
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* @brief the configuration of TX signals
    Elements                    :   Description
    ComPduId                    :   the COM PduId of the signal
    InitialValueOnly            :   defines that the respective signal's initial value shall be put into the
                                    respective PDU but there will not be any update of the value through the RTE
    SignalEndiannessType        :   the endianness of the signal's network representation
    SignalType                  :   the AUTOSAR type of the signal
    TransferPropertyType        :   the transfer property for the signal
    MsBitPosition               :   the MS Bit position in the I-PDU data
    LsBitPosition               :   the LS Bit position in the I-PDU data
    MsBytePosition              :   the MS Byte position in the I-PDU data
    LsBytePosition              :   the LS Byte position in the I-PDU data
    BitSize                     :   the Size in bits
    ByteLength                  :   the Size in bytes
    UBConfigId                  :   the UB config Index in Com_TxSignalUBConfig.
                                    Enabled only if COM_TX_SIGNAL_UB_SUPPORT is STD_ON
    InvalidDataBufferStartId    :   the Invalid value buffer start index of SignalType specific array.
                                    Enabled only if COM_TX_SIGNAL_INVALIDATE_SUPPORT is STD_ON
    InvalidDataBufferEndId      :   the Invalid value buffer End index of SignalType specific array.
                                    Enabled only if COM_TX_SIGNAL_INVALIDATE_SUPPORT is STD_ON
    TxFilterId                  :   the signal Com filter Index of Com_TxSignalFilterConfig.
                                    Enabled only if COM_TX_SIGNAL_FILTER_SUPPORT is STD_ON
    TxAckFunctId                :   the Tx Ack callout function index in Com_CbkTxAckFunctConfig.
                                    Enabled only if COM_TX_SIGNAL_ACK_CALLBACK_SUPPORT is STD_ON
    TxErrFunctId                :   the Tx Error callout function index in Com_CbkTxErrFunctConfig.
                                    Enabled only if COM_TX_SIGNAL_ERROR_CALLBACK_SUPPORT is STD_ON
    TxToutFunctId               :   the Tx Timeout callout function index in Com_CbkTxToutFunctConfig.
                                    Enabled only if COM_TX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT is STD_ON
*/
extern CONST(Com_TxSignalConfigType, COM_CONFIG_DATA) Com_TxSignalConfig[COM_NUM_OF_TX_SIGNAL_ID];

#if (COM_TX_SIGNAL_ACK_CALLBACK_SUPPORT == STD_ON)
/* @brief Defines the configuration of Com Tx signals Ack callout functions
    Elements                :   Description
    Com_CbkTxAckFunctType   :   the Tx Ack callout function for a Signal */
extern CONST(Com_CbkTxAckFunctType, COM_CONFIG_DATA) Com_CbkTxAckFunctConfig[COM_NUM_OF_TX_ACK_FUNCTION];
#endif

#if (COM_TX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT == STD_ON)
/* @brief Defines the configuration of Com Tx signals timeout callout functions
    Elements                 :   Description
    Com_CbkTxToutFunctType   :   the Tx Tout callout function for a Signal
*/
extern CONST(Com_CbkTxToutFunctType, COM_CONFIG_DATA) Com_CbkTxToutFunctConfig[COM_NUM_OF_TX_TOUT_FUNCTION];
#endif

#if (COM_TX_SIGNAL_ERROR_CALLBACK_SUPPORT == STD_ON)
/* @brief Defines the configuration of Com Tx signals error callout functions
    Elements                :   Description
    Com_CbkTxErrFunctType   :   the Tx Err callout function for a Signal
*/
extern CONST(Com_CbkTxErrFunctType, COM_CONFIG_DATA) Com_CbkTxErrFunctConfig[COM_NUM_OF_TX_ERR_FUNCTION];
#endif

#if (COM_TX_SIGNAL_GROUP_SUPPORT == STD_ON)
/* @brief the shadow buffer configuration for the tx signal group
    Elements        :   Description
    BufferStartId   :   the start index of the Tx shadow buffer Com_TxIpduShadowBuffer
    BufferEndId     :   the end index of the Tx shadow buffer Com_TxIpduShadowBuffer
    BufferLength    :   the length of the signal group
*/
extern CONST(Com_TxShadowBufferConfigType, COM_CONFIG_DATA) Com_TxShadowBufferConfig[COM_NUM_OF_TX_SIGNAL_GROUP_ID];

/* @brief the tx signal group configuration
    Elements                :   Description
    ComPduId                :   the COM PduId of the signal group
    MsBitPosition           :   the MS Bit position in the I-PDU data
    LsBitPosition           :   the LS Bit position in the I-PDU data
    MsBytePosition          :   the MS Byte position in the I-PDU data
    LsBytePosition          :   the LS Byte position in the I-PDU data
    BitSize                 :   the Size in bits of signal group
    ByteLength              :   the Size in bytes of signal group
    UBBitPosition           :   the Bit position in the I-PDU data for UB bit . Enabled only if
                                COM_TX_SIGNAL_GROUP_UB_SUPPORT is STD_ON
    UBBytePosition          :   the Byte position in the I-PDU data for UB bit. Enabled only if
                                COM_TX_SIGNAL_GROUP_UB_SUPPORT is STD_ON
    OnChangeBufferStartId   :   the length of the signal group COM_TX_SIGNAL_GROUP_ARRAY_SUPPORT
                                Enabled only if COM_TX_SIGNAL_GROUP_ARRAY_SUPPORT is STD_ON
    InitialValueOnly        :   defines that the respective signal's initial value shall be put into the
                                respective PDU but there will not be any update of the value through the RTE
    TransferPropertyType    :   the transfer property for the signal
    GroupSignalIdStart      :   the start index of the group signal in Com_TxSignalConfig
    GroupSignalIdStop       :   the stop index of the group signal in Com_TxSignalConfig
    ShadowBufferConfigId    :   the shadow buffer config index in Com_TxShadowBufferConfig
    FilterId                :   the filter id for the tx shadow buffer
                                Enabled only if COM_TX_SIGNAL_FILTER_SUPPORT is STD_ON
    SignalGroupArrayAccess  :   whether the uint8-array based access shall be used for this Com-SignalGroup.
                                Enabled only if COM_ENABLE_SIGNAL_GROUP_ARRAY_API is STD_ON.
    TxAckFunctId            :   the Tx Ack callout function index in Com_CbkTxAckFunctConfig.
                                Enabled only if COM_TX_SIGNAL_ACK_CALLBACK_SUPPORT is STD_ON
    TxErrFunctId            :   the Tx Error callout function index in Com_CbkTxErrFunctConfig.
                                Enabled only if COM_TX_SIGNAL_ERROR_CALLBACK_SUPPORT is STD_ON
    TxToutFunctId           :   the Tx Timeout callout function index in Com_CbkTxToutFunctConfig.
                                Enabled only if COM_TX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT is STD_ON
*/
extern CONST(Com_TxSignalGroupConfigType, COM_CONFIG_DATA) Com_TxSignalGroupConfig[COM_NUM_OF_TX_SIGNAL_GROUP_ID];
#endif

#if (COM_TX_SIGNAL_UB_SUPPORT == STD_ON)
/* @brief the Update bit configuration of the tx signal
    Elements        :   Description
    UBBitPosition   :   the Bit position in the I-PDU data for UB bit .
    UBBytePosition  :   the Byte position in the I-PDU data for UB bit.
*/
extern CONST(Com_UBPropsType, COM_CONFIG_DATA) Com_TxSignalUBConfig[COM_NUM_OF_TX_SIGNAL_UB_ID];
#endif

#if ((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_ON) || (COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_ON))

#if (COM_TX_SIGNAL_INVALID_FLOAT64_SUPPORT == STD_ON)
/* @brief the invalid value for the float64 signal */
extern CONST(float64, COM_CONFIG_DATA) Com_Float64SignalInvalidData[COM_FLOAT64_SIGNAL_INVALID_DATA_BUFFER_SIZE];
#endif

#if (COM_TX_SIGNAL_INVALID_FLOAT32_SUPPORT == STD_ON)
/* @brief the invalid value for the float32 signal */
extern CONST(float32, COM_CONFIG_DATA) Com_Float32SignalInvalidData[COM_FLOAT32_SIGNAL_INVALID_DATA_BUFFER_SIZE];
#endif

#if (COM_TX_SIGNAL_INVALID_SINT64_SUPPORT == STD_ON)
/* @brief the invalid value for the sint64 signal */
extern CONST(sint64, COM_CONFIG_DATA) Com_Sint64SignalInvalidData[COM_SINT64_SIGNAL_INVALID_DATA_BUFFER_SIZE];
#endif

#if (COM_TX_SIGNAL_INVALID_UINT64_SUPPORT == STD_ON)
/* @brief the invalid value for the uint64 signal */
extern CONST(uint64, COM_CONFIG_DATA) Com_Uint64SignalInvalidData[COM_UINT64_SIGNAL_INVALID_DATA_BUFFER_SIZE];
#endif

#endif

#if (COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON)
/*! @brief  the configuration of Com Signal Filter
    Elements            :   Description
    FilterAlgorithmType :   the type of Com signal filter algorithm used
    FilterMaskBufferId  :   the filter mask buffer index of SignalType specific buffers.
    FilterMaxBufferId   :   the filter max value buffer index of SignalType specific buffers.
    FilterMinBufferId   :   the filter min value buffer index of SignalType specific buffers.
    FilterXBufferId     :   the filter X value buffer index of SignalType specific buffers.
    FilterOffset        :   the offset value for the algorithm COM_FILTER_ALGORITHM_TYPE_ONE_EVERY_N
    FilterPeriod        :   the period value for the algorithm COM_FILTER_ALGORITHM_TYPE_ONE_EVERY_N
*/
extern CONST(Com_FilterConfigType, COM_CONFIG_DATA) Com_TxSignalFilterConfig[COM_NUM_OF_TX_SIGNAL_FILTER_ID];
#endif

#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define COM_START_SEC_CONFIG_DATA_BOOLEAN
#include "MemMap.h"

#if ((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_ON) || (COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_ON))

#if (COM_TX_SIGNAL_INVALID_BOOLEAN_SUPPORT == STD_ON)
/*! @brief  the configuration of Com Signal invalid value for boolean SignalType  */
extern CONST(boolean, COM_CONFIG_DATA) Com_BooleanSignalInvalidData[COM_BOOL_SIGNAL_INVALID_DATA_BUFFER_SIZE];
#endif

#endif

#define COM_STOP_SEC_CONFIG_DATA_BOOLEAN
#include "MemMap.h"

#define COM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

#if (COM_TX_SIGNAL_GROUP_SUPPORT == STD_ON)
/*! @brief  the configuration of Tx shadow buffer init values */
extern CONST(uint8, COM_CONFIG_DATA) Com_TxIpduShadowBufferInitValues[COM_TX_SHADOW_BUFFER_SIZE];
#endif

#if ((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_ON) || (COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_ON))

#if (COM_TX_SIGNAL_INVALID_UINT8_SUPPORT == STD_ON)
/*! @brief  the configuration of Com Signal invalid value for uint8 SignalType  */
extern CONST(uint8, COM_CONFIG_DATA) Com_Uint8SignalInvalidData[COM_UINT8_SIGNAL_INVALID_DATA_BUFFER_SIZE];
#endif

#if (COM_TX_SIGNAL_INVALID_SINT8_SUPPORT == STD_ON)
/*! @brief  the configuration of Com Signal invalid value for sint8 SignalType  */
extern CONST(sint8, COM_CONFIG_DATA) Com_Sint8SignalInvalidData[COM_SINT8_SIGNAL_INVALID_DATA_BUFFER_SIZE];
#endif

#if (COM_TX_SIGNAL_INVALID_UINT8ARR_SUPPORT == STD_ON)
/*! @brief  the configuration of Com Signal invalid value for UINT8_N SignalType  */
extern CONST(uint8, COM_CONFIG_DATA) Com_Uint8ArrSignalInvalidData[COM_UINT8ARR_SIGNAL_INVALID_DATA_BUFFER_SIZE];
#endif

#endif

#if (COM_TX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON)
/*! @brief  the configuration of Com Signal array on change mask value for UINT8_N SignalType  */
extern CONST(uint8, COM_CONFIG_DATA) Com_SignalArrayOnChageMask[COM_TX_SIGNAL_ARRAY_SIZE];
#endif

#define COM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

#define COM_START_SEC_CONFIG_DATA_16
#include "MemMap.h"
#if ((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_ON) || (COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_ON))

#if (COM_TX_SIGNAL_INVALID_UINT16_SUPPORT == STD_ON)
/*! @brief  the configuration of Com Signal invalid value for uint16 SignalType  */
extern CONST(uint16, COM_CONFIG_DATA) Com_Uint16SignalInvalidData[COM_UINT16_SIGNAL_INVALID_DATA_BUFFER_SIZE];
#endif

#if (COM_TX_SIGNAL_INVALID_SINT16_SUPPORT == STD_ON)
/*! @brief  the configuration of Com Signal invalid value for sint16 SignalType  */
extern CONST(sint16, COM_CONFIG_DATA) Com_Sint16SignalInvalidData[COM_SINT16_SIGNAL_INVALID_DATA_BUFFER_SIZE];
#endif

#endif

#define COM_STOP_SEC_CONFIG_DATA_16
#include "MemMap.h"

#define COM_START_SEC_CONFIG_DATA_32
#include "MemMap.h"

#if ((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_ON) || (COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_ON))

#if (COM_TX_SIGNAL_INVALID_UINT32_SUPPORT == STD_ON)
/*! @brief  the configuration of Com Signal invalid value for uint32 SignalType  */
extern CONST(uint32, COM_CONFIG_DATA) Com_Uint32SignalInvalidData[COM_UINT32_SIGNAL_INVALID_DATA_BUFFER_SIZE];
#endif

#if (COM_TX_SIGNAL_INVALID_SINT32_SUPPORT == STD_ON)
/*! @brief  the configuration of Com Signal invalid value for sint32 SignalType  */
extern CONST(sint32, COM_CONFIG_DATA) Com_Sint32SignalInvalidData[COM_SINT32_SIGNAL_INVALID_DATA_BUFFER_SIZE];
#endif

#endif

#define COM_STOP_SEC_CONFIG_DATA_32
#include "MemMap.h"

/*********************************************************************************************************************
 *                                 #! Receive IPDU const config data                                                  *
 *********************************************************************************************************************/
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* @brief Configuration for the Rx PDU and Com_IpduGroupVector Mapping
    Elements            :   Description
    IpduGroupVectorMap  :   the I-PDU group bit mask for the I-PDU
*/
extern CONST(Com_IpduToIpduGroupMapConfigType, COM_CONFIG_DATA) Com_IpduToIpduGroupMapRxConfig[COM_NUM_OF_RX_IPDU_ID];

/* @brief configuration of Rx I-PDU
    Elements                        :   Description
    IpduType                        :   defines the Ipdu type , Normal or TP .
    RxTpId                          :   the Rx Tp Ipdu config index in Com_RxTpIpduConfig
                                        Enabled only if COM_RX_TP_IPDU_SUPPORT is STD_ON
    IpduSignalProcessingType        :   defines the Ipdu signal processing type , deferred or immediate
    SignalStartId                   :   the signal config start index of Com_RxSignalConfig
    SignalEndId                     :   the signal config end index of Com_RxSignalConfig
    IpduTimeoutCounterId            :   the Rx Ipdu timeout counter index in Com_RxIpduTimeoutCounterConfig
                                        Enabled only if COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT is STD_ON
    SigTimeoutCounterStartId        :   the Rx signal timeout counter start index in Com_RxSigTimeoutCounterConfig
                                        Enabled only if COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT is STD_ON
    SigTimeoutCounterEndId          :   the Rx signal timeout counter end index in Com_RxSigTimeoutCounterConfig
                                        Enabled only if COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT is STD_ON
    SignalGroupStartId              :   the Rx signal group start index in Com_RxSignalGroupConfig
                                        Enabled only if COM_RX_SIGNAL_GROUP_SUPPORT is STD_ON
    SignalGroupEndId                :   the Rx signal group end index in Com_RxSignalGroupConfig
                                        Enabled only if COM_RX_SIGNAL_GROUP_SUPPORT is STD_ON
    SigGroupTimeoutCounterStartId   :   the Rx signal group timeout counter start index in
                                        Com_RxSigGroupTimeoutCounterConfigType .Enabled only if
                                        COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT is STD_ON
    SigGroupTimeoutCounterEndId     :   the Rx signal group timeout counter end index in
                                        Com_RxSigGroupTimeoutCounterConfigType .Enabled only if
                                        COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT is STD_ON
    IpduCancellationSupport         :   whether the I-PDU receive cancellation is supported.
                                        Enabled only if COM_RX_IPDU_CANCELLATION_SUPPORT is STD_ON
    IpduCalloutFunctId              :   the RX I-PDU callout function Index in  Com_TxIpduCalloutFuncConfig
                                        Enabled only if COM_RX_IPDU_CALLOUT_SUPPORT is STD_ON
    IpduCounterId                   :   the RX I-PDU counter Index in  Com_IpduCounterConfig
                                        Enabled only if COM_RX_IPDU_COUNTER_SUPPORT is STD_ON
    IpduReplicationId               :   the RX I-PDU the RX I-PDU replication config index in
                                        Com_RxIpduReplicationConfig Enabled only if COM_RX_IPDU_REPLICATION_SUPPORT
                                        is STD_ON
    GwDestinationConfigStartId      :   the RX signal destination config start Index in Com_GwDestinationConfig
                                        Enabled only if COM_SIGNAL_GATEWAY_SUPPORT is STD_ON
    GwDestinationConfigEndId        :   the RX signal destination config end Index in Com_GwDestinationConfig
                                        Enabled only if COM_SIGNAL_GATEWAY_SUPPORT is STD_ON
    NoIpduGroupSupported            :   the I-PDU has no Ipdu group
                                        Enabled only if COM_RX_PDU_NO_GROUP_SUPPORT is STD_ON
*/
extern CONST(Com_RxIpduConfigType, COM_CONFIG_DATA) Com_RxIpduConfig[COM_NUM_OF_RX_IPDU_ID];

/* @brief the configuration of Rx I-PDU Buffer
    Elements        :   Description
    BufferStartId   :   the start index of the Rx I-PDU buffer Com_TxIpduBuffer
    BufferEndId     :   the Ends index of the Rx I-PDU buffer Com_TxIpduBuffer
    MinimumLength   :   the minimum Rx I-PDU length
    MaximumLength   :   the maximum Rx I-PDU length
    MetaDataLength  :   the Rx I-PDU meta data length. Enabled only if COM_RX_IPDU_META_DATA_SUPPORT is STD_ON

*/
extern CONST(Com_RxIpduBufferConfigType, COM_CONFIG_DATA) Com_RxIpduBufferConfig[COM_NUM_OF_RX_IPDU_ID];

/* @brief Defines the timeout configuration for Rx PDU
    Elements        :   Description
    RxPduId         :   the Rx PduId for the timeout configuration
    FirstTimeout    :   the length of the first deadline monitoring timeout period in milliseconds.
    Timeout         :   the length of the deadline monitoring timeout period in milliseconds.
*/
#if (COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT == STD_ON)
extern CONST(Com_RxIpduTimeoutCounterConfigType, COM_CONFIG_DATA) Com_RxIpduTimeoutCounterConfig[COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID];
#endif

#if (COM_RX_TP_IPDU_SUPPORT == STD_ON)
/* @brief Defines the timeout configuration for Rx PDU
    Elements        :   Description
    BufferStartId   :   the start index of the Rx I-PDU buffer Com_TxIpduBuffer
    BufferEndId     :   the Ends index of the Rx I-PDU buffer Com_TxIpduBuffer
    MinimumLength   :   the minimum Rx I-PDU length
    MaximumLength   :   the maximum Rx I-PDU length
*/
extern CONST(Com_RxTpIpduConfigType, COM_CONFIG_DATA) Com_RxTpIpduConfig[COM_NUM_OF_RX_TP_IPDU_ID];
#endif

#if (COM_RX_IPDU_CALLOUT_SUPPORT == STD_ON)
/* @brief the RX I-PDU callout function configuration */
extern CONST(Com_RxIpduCalloutFunctType, COM_CONFIG_DATA) Com_RxIpduCalloutFunctConfig[COM_NUM_OF_RX_IPDU_CALLOUT_FUNC_ID];
#endif

#if (COM_RX_TP_APPL_CBK_SUPPORT == STD_ON)
extern CONST(Com_RxTpcbkFuncConfigType, COM_CONFIG_DATA) Com_RxTpcbkFuncConfig[COM_NUM_OF_RX_TP_IPDU_ID];
#endif

#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define COM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

/* @brief Defines the initial value for the Rx I-PDU buffer */
extern CONST(uint8, COM_CONFIG_DATA) Com_RxIpduBufferInitValues[COM_RX_IPDU_BUFFER_SIZE];

#if (COM_RX_TP_IPDU_SUPPORT == STD_ON)
/* @brief Defines the initial value for the Rx Tp I-PDU buffer */
extern CONST(uint8, COM_CONFIG_DATA) Com_RxTpIpduBufferInitValues[COM_RX_TP_BUFFER_SIZE];
#endif

#define COM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

/*********************************************************************************************************************
 *                                 #! Receive signal const config data                                                *
 *********************************************************************************************************************/
#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* @brief the configuration of RX signals
    Elements                    :   Description
    ComPduId                    :   the COM PduId of the signal
    InitialValueOnly            :   defines that the respective signal's initial value shall be put into the
                                    respective PDU but there will not be any update of the value through the reception
    SignalEndiannessType        :   the endianness of the signal's network representation
    SignalType                  :   the AUTOSAR type of the signal
    DataInvalidActionType       :   the action performed upon reception if invalid signal is received.
    RxDataTimeoutActionType     :   the action performed upon expiration of the reception deadline monitoring timer
    MsBitPosition               :   the MS Bit position in the I-PDU data
    LsBitPosition               :   the LS Bit position in the I-PDU data
    MsBytePosition              :   the MS Byte position in the I-PDU data
    LsBytePosition              :   the LS Byte position in the I-PDU data
    BitSize                     :   the Size in bits
    ByteLength                  :   the Size in bytes
    UBConfigId                  :   the UB config Index in Com_RxSignalUBConfig.
                                    Enabled only if COM_RX_SIGNAL_UB_SUPPORT is STD_ON
    DataInitValueBufferIdStart  :   the Invalid value buffer start index of SignalType specific array.
                                    Enabled only if COM_RX_SIGNAL_INVALID_DATA_SUPPORT is STD_ON
    DataInitValueBufferIdStop   :   the Invalid value buffer End index of SignalType specific array.
                                    Enabled only if COM_RX_SIGNAL_INVALID_DATA_SUPPORT is STD_ON
    FilterId                    :   the signal Com filter Index of Com_RxSignalFilterConfig.
                                    Enabled only if COM_RX_SIGNAL_FILTER_SUPPORT is STD_ON
    RxSignalTimeoutCounterId    :   the signal timeout counter index in Com_RxSigTimeoutCounterConfig
                                    Enabled only if COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT is STD_ON
    RxAckFunctId                :   the Rx Ack callout function index in Com_CbkRxAckFunctConfig.
                                    Enabled only if COM_RX_SIGNAL_ACK_CALLBACK_SUPPORT is STD_ON
    RxInvFunctId                :   the Rx Invalid callout function index in Com_CbkRxInvFunctConfig.
                                    Enabled only if COM_RX_SIGNAL_INVALID_CALLBACK_SUPPORT is STD_ON
    RxToutFunctId               :   the Rx Timeout callout function index in Com_CbkRxToutFunctConfig.
                                    Enabled only if COM_RX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT is STD_ON
    GwDestinationConfigId       :   the gateway configuration index in Com_GwDestinationConfig
                                    Enabled only if COM_SIGNAL_GATEWAY_SUPPORT is STD_ON
    InitBufferIdx               :   the signal init buffer index of SignalType init array config.
    RteBufferIdx                :   the signal buffer index of SignalType Rte buffer
    RteShadowBufferIdx          :   the signal buffer index of SignalType Rte shadow buffer.
                                    Enabled only if COM_RX_SIGNAL_GROUP_SUPPORT is STD_ON
    IsGroupSignal               :   whether the signal is group signal or not
                                    Enabled only if COM_RX_SIGNAL_GROUP_SUPPORT is STD_ON
*/
extern CONST(Com_RxSignalConfigType, COM_CONFIG_DATA) Com_RxSignalConfig[COM_NUM_OF_RX_SIGNAL_ID];

#if (COM_RX_SIGNAL_ACK_CALLBACK_SUPPORT == STD_ON)
/* @brief the configuration of Com signals Rx Ack functions */
extern CONST(Com_CbkRxAckFunctType, COM_CONFIG_DATA) Com_CbkRxAckFunctConfig[COM_NUM_OF_RX_ACK_FUNCT_ID];
#endif

#if (COM_RX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT == STD_ON)
/* @brief the configuration of Com signals Rx Tout functions */
extern CONST(Com_CbkRxToutFunctType, COM_CONFIG_DATA) Com_CbkRxToutFunctConfig[COM_NUM_OF_RX_TOUT_FUNCT_ID];
#endif

#if (COM_RX_SIGNAL_INVALID_CALLBACK_SUPPORT == STD_ON)
/* @brief the configuration of Com signals Rx Invalid functions */
extern CONST(Com_CbkRxInvFunctType, COM_CONFIG_DATA) Com_CbkRxInvFunctConfig[COM_NUM_OF_RX_INV_FUNCT_ID];
#endif

#if (COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/* @brief  the timeout configuration for Rx signal
    Elements        :   Description
    SignalId        :   the Rx signal id for the timeout configuration
    FirstTimeout    :   the length of the first deadline monitoring timeout period in milliseconds.
    Timeout         :   the length of the deadline monitoring timeout period in milliseconds.
*/
extern CONST(Com_RxSigTimeoutCounterConfigType, COM_CONFIG_DATA) Com_RxSigTimeoutCounterConfig[COM_NUM_OF_RX_SIGNAL_TIMEOUT_COUNTER_ID];
#endif

#if (COM_RX_SIGNAL_UB_SUPPORT == STD_ON)
/* @brief the Update bit configuration of the rx signal
    Elements        :   Description
    UBBitPosition   :   the Bit position in the I-PDU data for UB bit .
    UBBytePosition  :   the Byte position in the I-PDU data for UB bit.
*/
extern CONST(Com_UBPropsType, COM_CONFIG_DATA) Com_RxSignalUBConfig[COM_NUM_OF_RX_SIGNAL_UB_ID];
#endif

#if (COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
/* @brief the configuration of Rx Signal group
    Elements                    :   Description
    ComPduId                    :   the COM PduId of the signal group
    InitialValueOnly            :   defines that the respective signal group's initial value shall be put into the
                                    respective PDU but there will not be any update of the value through the reception
    DataInvalidActionType       :   the action performed upon reception if any invalid group signal is received.
    RxDataTimeoutActionType     :   the action performed upon expiration of the reception deadline monitoring timer
    MsBitPosition               :   the MS Bit position in the I-PDU data
    LsBitPosition               :   the LS Bit position in the I-PDU data
    MsBytePosition              :   the MS Byte position in the I-PDU data
    LsBytePosition              :   the LS Byte position in the I-PDU data
    BitSize                     :   the Size in bits
    ByteLength                  :   the Size in bytes
    SignalGroupArrayAccess      :   whether the uint8-array based access shall be used for this Com-SignalGroup.
                                    Enabled only if COM_RX_SIGNAL_GROUP_ARRAY_SUPPORT is STD_ON
    SignalGroupArrayBufferIdx   :   the signal Group Arraybuffer index in Com_RxSignalGroupRteArrayBuffer
                                    Enabled only if COM_RX_SIGNAL_GROUP_ARRAY_SUPPORT is STD_ON
    UBConfigId                  :   the UB config Index in Com_RxSignalGroupUBConfig.
                                    Enabled only if COM_RX_SIGNAL_GROUP_UB_SUPPORT is STD_ON
    RxSigGroupTimeoutCounterId  :   the Rx signal group timeout counter config index in
                                    Com_RxSigGroupTimeoutCounterConfig. Enabled only
                                    if COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT is STD_ON
    GroupSignalStartId          :   the start index of the group signal in Com_RxSignaConfig.
    GroupSignalEndId            :   the end index of the group signal in Com_RxSignaConfig.
    RxAckFunctId                :   the Rx Ack callout function index in Com_CbkRxAckFunctConfig
                                    Enabled only if COM_RX_SIGNAL_ACK_CALLBACK_SUPPORT is STD_ON
    RxInvFunctId                :   the Rx Invalid callout function index in Com_CbkRxInvFunctConfig
                                    Enabled only if COM_RX_SIGNAL_INVALID_CALLOUT_SUPPORT is STD_ON
    RxToutFunctId               :   the Rx Timeout callout function index in Com_CbkRxToutFunctConfig
                                    Enabled only if COM_RX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT is STD_ON
    GwDestinationConfigId       :   the Rx destination configuration index in  Com_GwDestinationConfig
                                    Enabled only if COM_SIGNAL_GATEWAY_SUPPORT is STD_ON
*/
extern CONST(Com_RxSignalGroupConfigType, COM_CONFIG_DATA) Com_RxSignalGroupConfig[COM_NUM_OF_RX_SIGNAL_GROUP_ID];
#endif

#if (COM_RX_SIGNAL_GROUP_UB_SUPPORT == STD_ON)
/* @brief the Update bit configuration of the rx signal group signal
    Elements        :   Description
    UBBitPosition   :   the Bit position in the I-PDU data for UB bit .
    UBBytePosition  :   the Byte position in the I-PDU data for UB bit.
*/
extern CONST(Com_UBPropsType, COM_CONFIG_DATA) Com_RxSignalGroupUBConfig[COM_NUM_OF_RX_SIGNAL_GROUP_UB_ID];
#endif

#if (COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/* @brief  the timeout configuration for Rx signal group
    Elements        :   Description
    SignalGroupId   :   the Rx signal group id for the timeout configuration
    FirstTimeout    :   the length of the first deadline monitoring timeout period in milliseconds.
    Timeout         :   the length of the deadline monitoring timeout period in milliseconds.
*/
extern CONST(Com_RxSigGroupTimeoutCounterConfigType, COM_CONFIG_DATA) Com_RxSigGroupTimeoutCounterConfig[COM_NUM_OF_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_ID];
#endif

#if (COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter
    Elements            :   Description
    FilterAlgorithmType :   the type of Com signal filter algorithm used
    FilterMaskBufferId  :   the filter mask buffer index of SignalType specific buffers.
    FilterMaxBufferId   :   the filter max value buffer index of SignalType specific buffers.
    FilterMinBufferId   :   the filter min value buffer index of SignalType specific buffers.
    FilterXBufferId     :   the filter X value buffer index of SignalType specific buffers.
    FilterOffset        :   the offset value for the algorithm COM_FILTER_ALGORITHM_TYPE_ONE_EVERY_N
    FilterPeriod        :   the period value for the algorithm COM_FILTER_ALGORITHM_TYPE_ONE_EVERY_N
*/
extern CONST(Com_FilterConfigType, COM_CONFIG_DATA) Com_RxSignalFilterConfig[COM_NUM_OF_RX_SIGNAL_FILTER_ID];
#endif

#if (COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal invalid value for sint64 SignalType  */
extern CONST(sint64, COM_CONFIG_DATA) Com_RxSint64SignalInvalidData[COM_RX_SINT64_SIGNAL_INVALID_DATA_BUFFER_SIZE];

/* @brief  the configuration of Com Signal invalid value for uint64 SignalType  */
extern CONST(uint64, COM_CONFIG_DATA) Com_RxUint64SignalInvalidData[COM_RX_UINT64_SIGNAL_INVALID_DATA_BUFFER_SIZE];
#endif

/*! @brief Defines the Com signals intial value for  for uint64  signal */
extern CONST(uint64, COM_CONFIG_DATA) Com_RxSignalU64InitBuffer[COM_RX_SIGNAL_U64_INIT_BUFFER_SIZE];

#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define COM_START_SEC_CONFIG_DATA_BOOLEAN
#include "MemMap.h"

#if (COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal invalid value for boolean SignalType  */
extern CONST(boolean, COM_CONFIG_DATA) Com_RxBooleanSignalInvalidData[COM_RX_BOOLEAN_SIGNAL_INVALID_DATA_BUFFER_SIZE];
#endif

#define COM_STOP_SEC_CONFIG_DATA_BOOLEAN
#include "MemMap.h"

#define COM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

#if (COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal invalid value for uint8 SignalType  */
extern CONST(uint8, COM_CONFIG_DATA) Com_RxUint8SignalInvalidData[COM_RX_UINT8_SIGNAL_INVALID_DATA_BUFFER_SIZE];

/* @brief  the configuration of Com Signal invalid value for sint8 SignalType  */
extern CONST(sint8, COM_CONFIG_DATA) Com_RxSint8SignalInvalidData[COM_RX_SINT8_SIGNAL_INVALID_DATA_BUFFER_SIZE];

/* @brief  the configuration of Com Signal invalid value for uint8_n SignalType  */
extern CONST(uint8, COM_CONFIG_DATA) Com_RxUint8ArrSignalInvalidData[COM_RX_UINT8_ARR_SIGNAL_INVALID_DATA_BUFFER_SIZE];
#endif
/*! @brief Defines the Com signals intial value for  for uint8  signal */
extern CONST(uint8, COM_CONFIG_DATA) Com_RxSignalU8InitBuffer[COM_RX_SIGNAL_U8_INIT_BUFFER_SIZE];
/*! @brief Defines the Com signals intial value for  for uint_n or uint_dyn  signal */
extern CONST(uint8, COM_CONFIG_DATA) Com_RxSignalArrInitBuffer[COM_RX_SIGNAL_RTE_ARR_INIT_BUFFER_SIZE];

#if (COM_RX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON)
extern CONST(uint8, COM_CONFIG_DATA) Com_RxSignalGroupRteArrayInitBuffer[COM_RX_SIGNAL_GROUP_RTE_ARRAY_BUFFER_SIZE];
#endif

#define COM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

#define COM_START_SEC_CONFIG_DATA_16
#include "MemMap.h"

#if (COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal invalid value for uint16 SignalType  */
extern CONST(uint16, COM_CONFIG_DATA) Com_RxUint16SignalInvalidData[COM_RX_UINT16_SIGNAL_INVALID_DATA_BUFFER_SIZE];

/* @brief  the configuration of Com Signal invalid value for sint16 SignalType  */
extern CONST(sint16, COM_CONFIG_DATA) Com_RxSint16SignalInvalidData[COM_RX_SINT16_SIGNAL_INVALID_DATA_BUFFER_SIZE];
#endif

/*! @brief Defines the Com signals intial value for  for uint16  signal */
extern CONST(uint16, COM_CONFIG_DATA) Com_RxSignalU16InitBuffer[COM_RX_SIGNAL_U16_INIT_BUFFER_SIZE];

#define COM_STOP_SEC_CONFIG_DATA_16
#include "MemMap.h"

#define COM_START_SEC_CONFIG_DATA_32
#include "MemMap.h"

#if (COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal invalid value for uint32 SignalType  */
extern CONST(uint32, COM_CONFIG_DATA) Com_RxUint32SignalInvalidData[COM_RX_UINT32_SIGNAL_INVALID_DATA_BUFFER_SIZE];

/* @brief  the configuration of Com Signal invalid value for sint32 SignalType  */
extern CONST(sint32, COM_CONFIG_DATA) Com_RxSint32SignalInvalidData[COM_RX_SINT32_SIGNAL_INVALID_DATA_BUFFER_SIZE];

#endif

/*! @brief Defines the Com signals intial value for  for uint32  signal */
extern CONST(uint32, COM_CONFIG_DATA) Com_RxSignalU32InitBuffer[COM_RX_SIGNAL_U32_INIT_BUFFER_SIZE];

#define COM_STOP_SEC_CONFIG_DATA_32
#include "MemMap.h"

/*********************************************************************************************************************
 *                                 #! Common const config data                                                        *
 *********************************************************************************************************************/
#define COM_START_SEC_CONFIG_DATA_BOOLEAN
#include "MemMap.h"

#if (COM_BOOLEAN_FILTER_MASK_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Mask value for boolean SignalType  */
extern CONST(boolean, COM_CONFIG_DATA) Com_BooleanFilterMaskValueConfig[COM_NUM_OF_BOOLEAN_FILTER_MASK_ID];
#endif

#if (COM_BOOLEAN_FILTER_X_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Mask value for boolean SignalType  */
extern CONST(boolean, COM_CONFIG_DATA) Com_BooleanFilterXValueConfig[COM_NUM_OF_BOOLEAN_FILTER_X_ID];
#endif

#define COM_STOP_SEC_CONFIG_DATA_BOOLEAN
#include "MemMap.h"

#define COM_START_SEC_CONFIG_DATA_8
#include "MemMap.h"

#if (COM_UINT8_FILTER_MASK_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Mask value for uint8 SignalType  */
extern CONST(uint8, COM_CONFIG_DATA) Com_Uint8FilterMaskValueConfig[COM_NUM_OF_UINT8_FILTER_MASK_ID];
#endif

#if (COM_UINT8_FILTER_X_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter X value for uint8 SignalType  */
extern CONST(uint8, COM_CONFIG_DATA) Com_Uint8FilterXValueConfig[COM_NUM_OF_UINT8_FILTER_X_ID];
#endif

#if (COM_UINT8_FILTER_MIN_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Min value for uint8 SignalType  */
extern CONST(uint8, COM_CONFIG_DATA) Com_Uint8FilterMinValueConfig[COM_NUM_OF_UINT8_FILTER_MIN_ID];
#endif

#if (COM_UINT8_FILTER_MAX_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Max value for uint8 SignalType  */
extern CONST(uint8, COM_CONFIG_DATA) Com_Uint8FilterMaxValueConfig[COM_NUM_OF_UINT8_FILTER_MAX_ID];
#endif

#if (COM_SINT8_FILTER_MASK_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Mask value for sint8 SignalType  */
extern CONST(sint8, COM_CONFIG_DATA) Com_Sint8FilterMaskValueConfig[COM_NUM_OF_SINT8_FILTER_MASK_ID];
#endif

#if (COM_SINT8_FILTER_X_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter X value for sint8 SignalType  */
extern CONST(sint8, COM_CONFIG_DATA) Com_Sint8FilterXValueConfig[COM_NUM_OF_SINT8_FILTER_X_ID];
#endif

#if (COM_SINT8_FILTER_MIN_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Min value for sint8 SignalType  */
extern CONST(sint8, COM_CONFIG_DATA) Com_Sint8FilterMinValueConfig[COM_NUM_OF_SINT8_FILTER_MIN_ID];
#endif

#if (COM_SINT8_FILTER_MAX_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Max value for sint8 SignalType  */
extern CONST(sint8, COM_CONFIG_DATA) Com_Sint8FilterMaxValueConfig[COM_NUM_OF_SINT8_FILTER_MAX_ID];
#endif

#define COM_STOP_SEC_CONFIG_DATA_8
#include "MemMap.h"

#define COM_START_SEC_CONFIG_DATA_16
#include "MemMap.h"

#if (COM_UINT16_FILTER_MASK_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Mask value for uint16 SignalType  */
extern CONST(uint16, COM_CONFIG_DATA) Com_Uint16FilterMaskValueConfig[COM_NUM_OF_UINT16_FILTER_MASK_ID];
#endif

#if (COM_UINT16_FILTER_X_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter X value for uint16 SignalType  */
extern CONST(uint16, COM_CONFIG_DATA) Com_Uint16FilterXValueConfig[COM_NUM_OF_UINT16_FILTER_X_ID];
#endif

#if (COM_UINT16_FILTER_MIN_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Min value for uint16 SignalType  */
extern CONST(uint16, COM_CONFIG_DATA) Com_Uint16FilterMinValueConfig[COM_NUM_OF_UINT16_FILTER_MIN_ID];
#endif

#if (COM_UINT16_FILTER_MAX_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Max value for uint16 SignalType  */
extern CONST(uint16, COM_CONFIG_DATA) Com_Uint16FilterMaxValueConfig[COM_NUM_OF_UINT16_FILTER_MAX_ID];
#endif

#if (COM_SINT16_FILTER_MASK_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Mask value for sint16 SignalType  */
extern CONST(sint16, COM_CONFIG_DATA) Com_Sint16FilterMaskValueConfig[COM_NUM_OF_SINT16_FILTER_MASK_ID];
#endif

#if (COM_SINT16_FILTER_X_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter X value for sint16 SignalType  */
extern CONST(sint16, COM_CONFIG_DATA) Com_Sint16FilterXValueConfig[COM_NUM_OF_SINT16_FILTER_X_ID];
#endif

#if (COM_SINT16_FILTER_MIN_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Min value for sint16 SignalType  */
extern CONST(sint16, COM_CONFIG_DATA) Com_Sint16FilterMinValueConfig[COM_NUM_OF_SINT16_FILTER_MIN_ID];
#endif

#if (COM_SINT16_FILTER_MAX_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Max value for sint16 SignalType  */
extern CONST(sint16, COM_CONFIG_DATA) Com_Sint16FilterMaxValueConfig[COM_NUM_OF_SINT16_FILTER_MAX_ID];
#endif

#define COM_STOP_SEC_CONFIG_DATA_16
#include "MemMap.h"

#define COM_START_SEC_CONFIG_DATA_32
#include "MemMap.h"

#if (COM_UINT32_FILTER_MASK_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Mask value for uint32 SignalType  */
extern CONST(uint32, COM_CONFIG_DATA) Com_Uint32FilterMaskValueConfig[COM_NUM_OF_UINT32_FILTER_MASK_ID];
#endif

#if (COM_UINT32_FILTER_X_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter X value for uint32 SignalType  */
extern CONST(uint32, COM_CONFIG_DATA) Com_Uint32FilterXValueConfig[COM_NUM_OF_UINT32_FILTER_X_ID];
#endif

#if (COM_UINT32_FILTER_MIN_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Min value for uint32 SignalType  */
extern CONST(uint32, COM_CONFIG_DATA) Com_Uint32FilterMinValueConfig[COM_NUM_OF_UINT32_FILTER_MIN_ID];
#endif

#if (COM_UINT32_FILTER_MAX_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Max value for uint32 SignalType  */
extern CONST(uint32, COM_CONFIG_DATA) Com_Uint32FilterMaxValueConfig[COM_NUM_OF_UINT32_FILTER_MAX_ID];
#endif

#if (COM_SINT32_FILTER_MASK_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Mask value for sint32 SignalType  */
extern CONST(sint32, COM_CONFIG_DATA) Com_Sint32FilterMaskValueConfig[COM_NUM_OF_SINT32_FILTER_MASK_ID];
#endif

#if (COM_SINT32_FILTER_X_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter X value for sint32 SignalType  */
extern CONST(sint32, COM_CONFIG_DATA) Com_Sint32FilterXValueConfig[COM_NUM_OF_SINT32_FILTER_X_ID];
#endif

#if (COM_SINT32_FILTER_MIN_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Min value for sint32 SignalType  */
extern CONST(sint32, COM_CONFIG_DATA) Com_Sint32FilterMinValueConfig[COM_NUM_OF_SINT32_FILTER_MIN_ID];
#endif

#if (COM_SINT32_FILTER_MAX_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Max value for sint32 SignalType  */
extern CONST(sint32, COM_CONFIG_DATA) Com_Sint32FilterMaxValueConfig[COM_NUM_OF_SINT32_FILTER_MAX_ID];
#endif

#define COM_STOP_SEC_CONFIG_DATA_32
#include "MemMap.h"

#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#if (COM_UINT64_FILTER_MASK_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Mask value for uint64 SignalType  */
extern CONST(uint64, COM_CONFIG_DATA) Com_Uint64FilterMaskValueConfig[COM_NUM_OF_UINT64_FILTER_MASK_ID];
#endif

#if (COM_UINT64_FILTER_X_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter X value for uint64 SignalType  */
extern CONST(uint64, COM_CONFIG_DATA) Com_Uint64FilterXValueConfig[COM_NUM_OF_UINT64_FILTER_X_ID];
#endif

#if (COM_UINT64_FILTER_MAX_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Min value for uint64 SignalType  */
extern CONST(uint64, COM_CONFIG_DATA) Com_Uint64FilterMinValueConfig[COM_NUM_OF_UINT64_FILTER_MIN_ID];
#endif

#if (COM_UINT64_FILTER_MIN_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Max value for uint64 SignalType  */
extern CONST(uint64, COM_CONFIG_DATA) Com_Uint64FilterMaxValueConfig[COM_NUM_OF_UINT64_FILTER_MAX_ID];
#endif

#if (COM_SINT64_FILTER_MASK_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Mask value for sint64 SignalType  */
extern CONST(sint64, COM_CONFIG_DATA) Com_Sint64FilterMaskValueConfig[COM_NUM_OF_SINT64_FILTER_MASK_ID];
#endif

#if (COM_SINT64_FILTER_X_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter X value for sint64 SignalType  */
extern CONST(sint64, COM_CONFIG_DATA) Com_Sint64FilterXValueConfig[COM_NUM_OF_SINT64_FILTER_X_ID];
#endif

#if (COM_SINT64_FILTER_MIN_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Min value for sint64 SignalType  */
extern CONST(sint64, COM_CONFIG_DATA) Com_Sint64FilterMinValueConfig[COM_NUM_OF_SINT64_FILTER_MIN_ID];
#endif

#if (COM_SINT64_FILTER_MAX_VALUE_SUPPORT == STD_ON)
/* @brief  the configuration of Com Signal Filter Max value for sint64 SignalType  */
extern CONST(sint64, COM_CONFIG_DATA) Com_Sint64FilterMaxValueConfig[COM_NUM_OF_SINT64_FILTER_MAX_ID];
#endif

#if ((COM_TX_IPDU_COUNTER_SUPPORT == STD_ON) || (COM_RX_IPDU_COUNTER_SUPPORT == STD_ON))
/*! @brief  the configuration of Com Signal Filter
    Elements                                :   Description
    IpduCounterSize                         :   the Size of I-PDU Counter expressed in bits
    IpduCounterThreshold                    :   the threshold value of the I-PDU Counter
    IpduCounterStartPosition                :   the position of I-PDU counter expressed in bits from start position
                                                of data content of I-PDU (SDU).
    ComIpduCounterErrorNotificationFunctPtr :   the function for the I-PDU counter error notification
*/
extern CONST(Com_IpduCounterConfigType, COM_CONFIG_DATA) Com_IpduCounterConfig[COM_NUM_OF_IPDU_COUNTER_ID];
#endif
#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*********************************************************************************************************************
 *                                 #! Gateway config data                                                             *
 *********************************************************************************************************************/
#if (COM_SIGNAL_GATEWAY_SUPPORT == STD_ON)

#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* @brief the configuration of Gateway destination signal description config
    Elements                    :   Description
    MsBitPosition               :   the MS Bit position in the I-PDU
    LsBitPosition               :   the LS Bit position in the I-PDU data
    MsBytePosition              :   the MS Byte position in the I-PDU data
    LsBytePosition              :   the LS Byte position in the I-PDU data
    UBBitPosition               :   the Update Bit(UB) bit position in I-PDU data
    UBBytePosition              :   the Update Bit(UB) byte position in I-PDU data
    DestIPduId                  :   the Com destination I-PDU Id
    SignalEndiannessType        :   the endianness of the signal's network representation
    TransferPropertyType        :   the signal transfer property type
    DataInitValueBufferIdStart  :   the Init value buffer start Index of its SignalType config
    DataInitValueBufferIdStop   :   the Init value buffer stop Index of its SignalType config
    TxFilterId                  :   the signal Com filter Index of Com_TxSignalFilterConfig
*/
extern CONST(Com_GatewayDestSignalConfigType, COM_CONFIG_DATA) Com_GatewayDestSignalConfig[COM_NUM_OF_GW_DEST_SIGNAL_ID];

/* @brief the configuration of Gateway source signal description config
    Elements                :   Description
    SignalEndiannessType    :   the endianness of the signal's network representation
    SignalType              :   the AUTOSAR type of the signal
    MsBitPosition           :   the MS Bit position in the I-PDU
    LsBitPosition           :   the LS Bit position in the I-PDU data
    MsBytePosition          :   the MS Byte position in the I-PDU data
    LsBytePosition          :   the LS Byte position in the I-PDU data
    BitSize                 :   the Size in bits
    ByteLength              :   the Size in bytes
    UBBitPosition           :   the Update Bit(UB) bit position in the buffer
    UBBytePosition          :   the Update Bit(UB) byte position in the buffer
    SourceIPduId            :    the Com source I-PDU Id
*/
extern CONST(Com_GatewaySourceSignalConfigType, COM_CONFIG_DATA) Com_GatewaySourceSignalConfig[COM_NUM_OF_GW_SRC_SIGNAL_ID];

/* @brief the configuration of Gateway source signal description config
    Elements                :   Description
    SrcGatewayRefType       :   the type of gateway signal reference SIGNAL_ID or SIGNAL_DESCRIPTION of soruce GW signal
    SrcSignalId             :   the signal Id when reference type is COM_GATEWAY_REF_TYPE_SIGNAL_ID of soruce GW signal
    GatewaySourceSignalId   :   the description Id when reference type is COM_GATEWAY_REF_TYPE_SIGNAL_DESCRIPTION
                                of soruce GW signal
    DestGatewayRefType      :   the type of gateway signal reference SIGNAL_ID or SIGNAL_DESCRIPTION of dest GW signal
    DestSignalId            :   the signal Id when reference type is COM_GATEWAY_REF_TYPE_SIGNAL_ID of dest GW signal
    GatewayDestSignalId     :   the description Id when reference type is COM_GATEWAY_REF_TYPE_SIGNAL_DESCRIPTION
                                of dest GW signal
*/
CONST(Com_GwDestinationConfigType, COM_CONFIG_DATA)
Com_GwDestinationConfig[COM_NUM_OF_GW_SIGNAL_ID];

#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#endif

#endif /*COM_LCFG_H */
/*******************************************************************************************************************
 *                                 END OF FILE                                                                      *
 ********************************************************************************************************************/
