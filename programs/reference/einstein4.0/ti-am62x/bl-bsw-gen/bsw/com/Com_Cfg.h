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
*    @file Com_Cfg.h
*    @ingroup ComConfiguration
*    @brief This is Com Pre-compile time configuration header file. It contains definitions of pre-compile time 
*    configuration parameters for the Com module.
*    @defgroup ComConfiguration
*    @brief This contains the configuration files for the COM module.
********************************************************************************************************************/
#ifndef COM_CFG_H
#define COM_CFG_H


#include "Com_Types.h"

/*!@ brief Enables/Disables the COM cancellation support  */
#define COM_CANCELLATION_SUPPORT                    	STD_ON
/*!@ brief Enables/Disables the  Default Error Tracer (Det) detection and notification support */
#define COM_CONFIGURATION_USE_DET                   	STD_ON
/*!@ brief Enables/Disables the the minimum delay time monitoring for cyclic and repeated transmissions*/
#define COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION          STD_ON
/*! @brief Enables/Disables the signal group array access APIs
    (Com_SendSignalGroupArray, Com_ReceiveSignalGroupArray).*/
#define COM_ENABLE_SIGNAL_GROUP_ARRAY_API           	STD_ON
/*! @brief Enables/Disables the support of meta-data feature including the
    API Com_TriggerIPDUSendWithMetaData */
#define COM_META_DATA_SUPPORT                       	STD_ON
/*! @brief  Enables/Disables the retry of failed transmission requests support*/
#define COM_RETRY_FAILED_TRANSMIT_REQUESTS          	STD_ON
/*! @brief Activate/Deactivate the version information API (Com_GetVersionInfo). */
#define COM_VERSION_INFO_API                         	STD_ON
/*! @brief The period between successive calls to Com_MainFunctionRouteSignals in milliseconds */
#define COM_GW_TIME_BASE                          		10U
/*! @brief The period between successive calls to Com_MainFunctionRx in milliseconds */
#define COM_RX_TIME_BASE                          		10U
/*! @brief The period between successive calls to Com_MainFunctionTx in milliseconds */
#define COM_TX_TIME_BASE                          		10U

/* Internal config */
/*! @brief Switches the Default Error Tracer (Det) detection and notification ON or OFF.*/
#define COM_DEV_ERROR_DETECT                        	STD_ON
/*********************************************************************************************************************
*                                 #! Transmit IPDU Feature Macro                                                     *
*********************************************************************************************************************/
/*! @brief Enables/Disables the support of meta-data feature for transmission . Enabled if any of the Tx IPDU supports
    Meta data  */
#define COM_TX_IPDU_META_DATA_SUPPORT               	STD_ON
/*! @brief Enables/Disables the support for Transmit cancellation .Enabled if any of the Tx IPDU supports
   IPDU cancellation feature */
#define COM_TX_IPDU_CANCELLATION_SUPPORT            	STD_ON
/*! @brief Enables/Disables the Com Tx I-PDU counter support .Enabled if any of the Tx I-PDU supports counter feature*/
#define COM_TX_IPDU_COUNTER_SUPPORT						STD_OFF
/*! @brief Enables/Disables the Com Tx I-PDU trigger transmit support. Enabled if any of the Tx I-PDU supports 
    I-PDU trigger feature */
#define COM_TX_IPDU_TRIGGER_TRANSMIT_SUPPORT            STD_ON
/*! @brief Enables/Disables the Com Tx I-PDU trigger transmit callout support. Enabled if any of the Tx I-PDU supports 
    I-PDU trigger transmit callout feature */
#define COM_TX_IPDU_TRIGGER_TRANSMIT_CALLOUT_SUPPORT    STD_ON
/*! @brief Enables/Disables the Com Tx I-PDU callout support. Enabled if any of the Tx I-PDU supports 
    I-PDU callout feature */
#define COM_TX_IPDU_CALLOUT_SUPPORT                     STD_ON
/*! @brief Enables/Disables the Com Tx TP I-PDU  support. Enabled if any of the Tx I-PDU supports 
    TP feature */
#define COM_TX_TP_IPDU_SUPPORT                          STD_ON
/*! @brief Enables/Disables the Com Tx timeout monitoring feature . Enabled if any of the I-PDU , TP I-PDU , signal or
    signal group timeout monitoring feature */
#define COM_TX_TIMEOUT_COUNTER_SUPPORT                  STD_ON
/*! @brief Enables/Disables the Com Tx I-PDU no I-PDU group support.Enabled if any of the Tx I-PDU has no I-PDU 
    group */
#define COM_TX_PDU_NO_GROUP_SUPPORT                     STD_ON 
/*********************************************************************************************************************
*                                 #! Transmit signal Feature Macro                                                   *
*********************************************************************************************************************/
/*! @brief Enables/Disables the support for the signal transmit acknowledge callout .Enabled if any of the Tx signal 
   or signal group supports Tx Ack callback feature  */
#define COM_TX_SIGNAL_ACK_CALLBACK_SUPPORT           	STD_ON
/*! @brief Enables/Disables the support for the signal transmit Error callout .Enabled if any of the Tx signal 
    or signal group supports Tx error callback feature */
#define COM_TX_SIGNAL_ERROR_CALLBACK_SUPPORT         	STD_OFF
/*! @brief Enables/Disables the support for the signal transmit timeout callout .Enabled if any of the Tx signal 
    or signal group supports Tx timeout callback feature */
#define COM_TX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT       	STD_ON
/*! @brief Enables/Disables the Com Tx  Signal Dynamic length support. Enabled if any of the Tx signal supports 
    Dynamic length feature */
#define COM_TX_SIGNAL_DYN_SUPPORT						STD_ON
/*! @brief Enables/Disables the Com Tx Signal invalidate support. Enabled if any of the Tx signal supports 
     invalidate feature */
#define COM_TX_SIGNAL_INVALIDATE_SUPPORT				STD_ON
/*! @brief Enables/Disables the Com Tx Signal update bit support. Enabled if any of the Tx signal supports  
     update bit feature */
#define COM_TX_SIGNAL_UB_SUPPORT                        STD_ON
/*! @brief Enables/Disables the Com Tx Signal group support. Enabled if any of the Tx I-PDU supports signal group 
    feature */
#define COM_TX_SIGNAL_GROUP_SUPPORT                     STD_ON
/*! @brief Enables/Disables the Com Tx Signal group with Update Bit support. Enabled if any of the Tx I-PDU supports   
    signal group with Update Bit feature */
#define COM_TX_SIGNAL_GROUP_UB_SUPPORT                  STD_OFF
/*! @brief Enables/Disables the Com Tx Signal group with array access support. Enabled if any of the Tx I-PDU supports   
    signal group with array access feature */
#define COM_TX_SIGNAL_GROUP_ARRAY_SUPPORT               STD_ON
/*! @brief Enables/Disables the Com Tx Signal group invalidate support. Enabled if any of the Tx signal group supports 
     invalidate feature */
#define COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT          STD_ON
/*! @brief Enables/Disables the Com Tx Boolean Signal with invalidate support. Enabled if any of the Tx Boolean Signal 
    supports invalidate feature */
#define COM_TX_SIGNAL_INVALID_BOOLEAN_SUPPORT           STD_ON
/*! @brief Enables/Disables the Com Tx uint8 Signal with invalidate support. Enabled if any of the Tx uint8 Signal 
    supports invalidate feature */
#define COM_TX_SIGNAL_INVALID_UINT8_SUPPORT             STD_ON
/*! @brief Enables/Disables the Com Tx sint8 Signal with invalidate support. Enabled if any of the Tx sint8 Signal 
    supports invalidate feature */
#define COM_TX_SIGNAL_INVALID_SINT8_SUPPORT             STD_ON
/*! @brief Enables/Disables the Com Tx uint16 Signal with invalidate support. Enabled if any of the Tx uint16 Signal 
    supports invalidate feature */
#define COM_TX_SIGNAL_INVALID_UINT16_SUPPORT            STD_ON
/*! @brief Enables/Disables the Com Tx sint16 Signal with invalidate support. Enabled if any of the Tx sint16 Signal 
    supports invalidate feature */
#define COM_TX_SIGNAL_INVALID_SINT16_SUPPORT            STD_ON
/*! @brief Enables/Disables the Com Tx uint32 Signal with invalidate support. Enabled if any of the Tx uint32 Signal 
    supports invalidate feature */
#define COM_TX_SIGNAL_INVALID_UINT32_SUPPORT            STD_ON
/*! @brief Enables/Disables the Com Tx sint32 Signal with invalidate support. Enabled if any of the Tx sint32 Signal 
    supports invalidate feature */
#define COM_TX_SIGNAL_INVALID_SINT32_SUPPORT            STD_ON
/*! @brief Enables/Disables the Com Tx uint64 Signal with invalidate support. Enabled if any of the Tx uint64 Signal 
    supports invalidate feature */
#define COM_TX_SIGNAL_INVALID_UINT64_SUPPORT            STD_ON
/*! @brief Enables/Disables the Com Tx sint64 Signal with invalidate support. Enabled if any of the Tx sint64 Signal 
    supports invalidate feature */
#define COM_TX_SIGNAL_INVALID_SINT64_SUPPORT            STD_ON
/*! @brief Enables/Disables the Com Tx float32 Signal with invalidate support. Enabled if any of the Tx float32 Signal 
    supports invalidate feature */
#define COM_TX_SIGNAL_INVALID_FLOAT32_SUPPORT           STD_ON
/*! @brief Enables/Disables the Com Tx float64 Signal with invalidate support. Enabled if any of the Tx float64 Signal 
    supports invalidate feature */
#define COM_TX_SIGNAL_INVALID_FLOAT64_SUPPORT           STD_ON
/*! @brief Enables/Disables the Com Tx uint8_n Signal with invalidate support. Enabled if any of the Tx uint8_n Signal 
    supports invalidate feature */
#define COM_TX_SIGNAL_INVALID_UINT8ARR_SUPPORT          STD_ON
/*! @brief Enables/Disables the Com Tx Signal filter support. Enabled if any of the Tx signal supports filter feature*/
#define COM_TX_SIGNAL_FILTER_SUPPORT                    STD_ON
/*********************************************************************************************************************
*                                 #! Receive IPDU Feature Macro                                                      *
*********************************************************************************************************************/
/*! @brief Enables/Disables the support of meta-data feature for Reception Enabled if any of the Rx IPDU supports
    Meta data  */
#define COM_RX_IPDU_META_DATA_SUPPORT              	 	  STD_ON
/*! @brief Enables/Disables the support for receive TP cancellation .Enabled if any of the Rx TP IPDU supports
   IPDU cancellation feature*/
#define COM_RX_IPDU_CANCELLATION_SUPPORT            	  STD_ON
/*! @brief Enables/Disables the support for receive I-PDU replications. Enabled if any of the Rx IPDU supports
   IPDU replication feature */
#define COM_RX_IPDU_REPLICATION_SUPPORT             	  STD_OFF
/*! @brief Enables/Disables the support for Rx Tp I-PDU . Enabled if any of the Rx IPDU supports Tp feature */
#define COM_RX_TP_IPDU_SUPPORT                            STD_OFF
/*! @brief Enables/Disables the Com Rx I-PDU counter support .Enabled if any of the Rx I-PDU supports counter feature*/
#define COM_RX_IPDU_COUNTER_SUPPORT                       STD_OFF
/*! @brief Enables/Disables the Com Rx I-PDU callout support. Enabled if any of the Rx I-PDU supports 
    I-PDU callout feature */
#define COM_RX_IPDU_CALLOUT_SUPPORT                       STD_ON
/*! @brief Enables/Disables the Com Rx timeout monitoring feature . Enabled if any of the I-PDU supports timeout 
    monitoring feature */
#define COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT               STD_ON   
/*! @brief Enables/Disables the support of Rx Tp I-PDU Appl callback support .Enabled if any of the Rx TP Ipdu  
    supports Rx Tp I-PDU Appl callback feature */
#define COM_RX_TP_APPL_CBK_SUPPORT                        STD_OFF
/*! @brief Enables/Disables the Com Rx I-PDU no I-PDU group support.Enabled if any of the Rx I-PDU has no I-PDU 
    group */
#define COM_RX_PDU_NO_GROUP_SUPPORT                       STD_ON 
/*********************************************************************************************************************
*                                 #! Receive signal Feature Macro                                                    *
*********************************************************************************************************************/
/*! @brief Enables/Disables the support for the signal transmit timeout callout.Enabled if any of the Rx signal 
    or signal group supports Rx timeout callback  */
#define COM_RX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT       	  STD_ON
/*! @brief Enables/Disables the support for the signal receive acknowledge callout .Enabled if any of the Rx signal 
    or signal group supports Rx ack callback  */
#define COM_RX_SIGNAL_ACK_CALLBACK_SUPPORT                STD_ON
/*! @brief Enables/Disables the support for the signal receive invalid callout .Enabled if any of the Rx signal 
    or signal group supports Rx invalid callback  */
#define COM_RX_SIGNAL_INVALID_CALLBACK_SUPPORT       	  STD_ON
/*! @brief Enables/Disables the Com Rx Signal Dynamic length support. Enabled if any of the Rx signal supports 
    Dynamic length feature */
#define COM_RX_SIGNAL_DYN_SUPPORT                         STD_ON
/*! @brief Enables/Disables the Com Rx Signal update bit support. Enabled if any of the Rx signal supports  
     update bit feature */
#define COM_RX_SIGNAL_UB_SUPPORT                          STD_OFF
/*! @brief Enables/Disables the Com Rx Signal timeout support. Enabled if any of the Rx signal supports  
    timeout feature */
#define COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT             STD_OFF
/*! @brief Enables/Disables the Com Rx Signal group support. Enabled if any of the Rx I-PDU supports signal group 
    feature */
#define COM_RX_SIGNAL_GROUP_SUPPORT                       STD_ON
/*! @brief Enables/Disables the Com Rx Signal group with array access support. Enabled if any of the Rx I-PDU supports 
    signal group  with array access feature */
#define COM_RX_SIGNAL_GROUP_ARRAY_SUPPORT                 STD_ON
/*! @brief Enables/Disables the Com Rx Signal group with update-bit support. Enabled if any of the Rx I-PDU supports 
    signal group with update-bit feature */
#define COM_RX_SIGNAL_GROUP_UB_SUPPORT                    STD_ON
/*! @brief Enables/Disables the Com Rx Signal group timeout support. Enabled if any of the Rx signal group supports  
    timeout feature */
#define COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT       STD_ON
/*! @brief Enables/Disables the Com Rx Signal filter support. Enabled if any of the Rx signal supports filter feature*/
#define COM_RX_SIGNAL_FILTER_SUPPORT                      STD_OFF
/*! @brief Enables/Disables the Com Rx Signal with invalid check support. Enabled if any of the Rx Signal supports
    invalid check feature */
#define COM_RX_SIGNAL_INVALID_DATA_SUPPORT                STD_OFF
/*********************************************************************************************************************
*                                 #! Tx , Rx Common Feature Macro                                                    *
*********************************************************************************************************************/
/*! @brief Enables/Disables the Com Tx/Rx boolean Signal with filter mask support. Enabled if any of the Tx/Rx 
    boolean Signal supports filter mask feature */
#define COM_BOOLEAN_FILTER_MASK_VALUE_SUPPORT             STD_ON
/*! @brief Enables/Disables the Com Tx/Rx boolean Signal with filter X support. Enabled if any of the Tx/Rx 
    boolean Signal supports filter X feature */
#define COM_BOOLEAN_FILTER_X_VALUE_SUPPORT                STD_ON
/*! @brief Enables/Disables the Com Tx/Rx uint8 Signal with filter mask support. Enabled if any of the Tx/Rx 
    uint8 Signal supports filter mask feature */
#define COM_UINT8_FILTER_MASK_VALUE_SUPPORT               STD_ON
/*! @brief Enables/Disables the Com Tx/Rx uint8 Signal with filter X support. Enabled if any of the Tx/Rx 
    uint8 Signal supports filter mask feature */
#define COM_UINT8_FILTER_X_VALUE_SUPPORT                  STD_ON
/*! @brief Enables/Disables the Com Tx/Rx uint8 Signal with filter Min support. Enabled if any of the Tx/Rx 
    uint8 Signal supports filter Min feature */
#define COM_UINT8_FILTER_MIN_VALUE_SUPPORT                STD_ON
/*! @brief Enables/Disables the Com Tx/Rx uint8 Signal with filter Max support. Enabled if any of the Tx/Rx 
    uint8 Signal supports filter Max feature */
#define COM_UINT8_FILTER_MAX_VALUE_SUPPORT                STD_ON
/*! @brief Enables/Disables the Com Tx/Rx sint8 Signal with filter mask support. Enabled if any of the Tx/Rx 
    sint8 Signal supports filter mask feature */
#define COM_SINT8_FILTER_MASK_VALUE_SUPPORT               STD_ON
/*! @brief Enables/Disables the Com Tx/Rx sint8 Signal with filter X support. Enabled if any of the Tx/Rx 
    sint8 Signal supports filter X feature */
#define COM_SINT8_FILTER_X_VALUE_SUPPORT                  STD_ON
/*! @brief Enables/Disables the Com Tx/Rx sint8 Signal with filter min support. Enabled if any of the Tx/Rx 
    sint8 Signal supports filter min feature */
#define COM_SINT8_FILTER_MIN_VALUE_SUPPORT                STD_ON
/*! @brief Enables/Disables the Com Tx/Rx sint8 Signal with filter max support. Enabled if any of the Tx/Rx 
    sint8 Signal supports filter max feature */
#define COM_SINT8_FILTER_MAX_VALUE_SUPPORT                STD_ON
/*! @brief Enables/Disables the Com Tx/Rx uint16 Signal with filter mask support. Enabled if any of the Tx/Rx 
    uint16 Signal supports filter mask feature */
#define COM_UINT16_FILTER_MASK_VALUE_SUPPORT              STD_ON
/*! @brief Enables/Disables the Com Tx/Rx uint16 Signal with filter X support. Enabled if any of the Tx/Rx 
    uint16 Signal supports filter X feature */
#define COM_UINT16_FILTER_X_VALUE_SUPPORT                 STD_ON
/*! @brief Enables/Disables the Com Tx/Rx uint16 Signal with filter min support. Enabled if any of the Tx/Rx 
    uint16 Signal supports filter min feature */
#define COM_UINT16_FILTER_MIN_VALUE_SUPPORT               STD_ON
/*! @brief Enables/Disables the Com Tx/Rx uint16 Signal with filter max support. Enabled if any of the Tx/Rx 
    uint16 Signal supports filter max feature */
#define COM_UINT16_FILTER_MAX_VALUE_SUPPORT               STD_ON
/*! @brief Enables/Disables the Com Tx/Rx sint16 Signal with filter mask support. Enabled if any of the Tx/Rx 
    boolean sint16 supports filter mask feature */
#define COM_SINT16_FILTER_MASK_VALUE_SUPPORT              STD_ON
/*! @brief Enables/Disables the Com Tx/Rx sint16 Signal with filter X support. Enabled if any of the Tx/Rx 
    boolean sint16 supports filter X feature */
#define COM_SINT16_FILTER_X_VALUE_SUPPORT                 STD_ON
/*! @brief Enables/Disables the Com Tx/Rx sint16 Signal with filter min support. Enabled if any of the Tx/Rx 
    boolean sint16 supports filter min feature */
#define COM_SINT16_FILTER_MIN_VALUE_SUPPORT               STD_ON
/*! @brief Enables/Disables the Com Tx/Rx sint16 Signal with filter max support. Enabled if any of the Tx/Rx 
    boolean sint16 supports filter max feature */
#define COM_SINT16_FILTER_MAX_VALUE_SUPPORT               STD_ON
/*! @brief Enables/Disables the Com Tx/Rx uint32 Signal with filter mask support. Enabled if any of the Tx/Rx 
    uint32 Signal supports filter mask feature */
#define COM_UINT32_FILTER_MASK_VALUE_SUPPORT              STD_ON
/*! @brief Enables/Disables the Com Tx/Rx uint32 Signal with filter X support. Enabled if any of the Tx/Rx 
    uint32 Signal supports filter X feature */
#define COM_UINT32_FILTER_X_VALUE_SUPPORT                 STD_ON
/*! @brief Enables/Disables the Com Tx/Rx uint32 Signal with filter min support. Enabled if any of the Tx/Rx 
    uint32 Signal supports filter min feature */
#define COM_UINT32_FILTER_MIN_VALUE_SUPPORT               STD_ON
/*! @brief Enables/Disables the Com Tx/Rx uint32 Signal with filter max support. Enabled if any of the Tx/Rx 
    uint32 Signal supports filter max feature */
#define COM_UINT32_FILTER_MAX_VALUE_SUPPORT               STD_ON
/*! @brief Enables/Disables the Com Tx/Rx sint32 Signal with filter mask support. Enabled if any of the Tx/Rx 
    sint32 Signal supports filter mask feature */
#define COM_SINT32_FILTER_MASK_VALUE_SUPPORT              STD_ON
/*! @brief Enables/Disables the Com Tx/Rx sint32 Signal with filter X support. Enabled if any of the Tx/Rx 
    sint32 Signal supports filter X feature */
#define COM_SINT32_FILTER_X_VALUE_SUPPORT                 STD_ON
/*! @brief Enables/Disables the Com Tx/Rx sint32 Signal with filter min support. Enabled if any of the Tx/Rx 
    sint32 Signal supports filter min feature */
#define COM_SINT32_FILTER_MIN_VALUE_SUPPORT               STD_ON
/*! @brief Enables/Disables the Com Tx/Rx sint32 Signal with filter max support. Enabled if any of the Tx/Rx 
    sint32 Signal supports filter max feature */
#define COM_SINT32_FILTER_MAX_VALUE_SUPPORT               STD_ON
/*! @brief Enables/Disables the Com Tx/Rx uint64 Signal with filter mask support. Enabled if any of the Tx/Rx 
    uint64 Signal supports filter mask feature */
#define COM_UINT64_FILTER_MASK_VALUE_SUPPORT              STD_ON
/*! @brief Enables/Disables the Com Tx/Rx uint64 Signal with filter X support. Enabled if any of the Tx/Rx 
    uint64 Signal supports filter X feature */
#define COM_UINT64_FILTER_X_VALUE_SUPPORT                 STD_ON
/*! @brief Enables/Disables the Com Tx/Rx uint64 Signal with filter min support. Enabled if any of the Tx/Rx 
    uint64 Signal supports filter min feature */
#define COM_UINT64_FILTER_MIN_VALUE_SUPPORT               STD_ON
/*! @brief Enables/Disables the Com Tx/Rx uint64 Signal with filter max support. Enabled if any of the Tx/Rx 
    uint64 Signal supports filter max feature */
#define COM_UINT64_FILTER_MAX_VALUE_SUPPORT               STD_ON
/*! @brief Enables/Disables the Com Tx/Rx sint64 Signal with filter mask support. Enabled if any of the Tx/Rx 
    sint64 Signal supports filter mask feature */
#define COM_SINT64_FILTER_MASK_VALUE_SUPPORT              STD_ON
/*! @brief Enables/Disables the Com Tx/Rx sint64 Signal with filter X support. Enabled if any of the Tx/Rx 
    sint64 Signal supports filter X feature */
#define COM_SINT64_FILTER_X_VALUE_SUPPORT                 STD_ON
/*! @brief Enables/Disables the Com Tx/Rx sint64 Signal with filter min support. Enabled if any of the Tx/Rx 
    sint64 Signal supports filter min feature */
#define COM_SINT64_FILTER_MIN_VALUE_SUPPORT               STD_ON
/*! @brief Enables/Disables the Com Tx/Rx sint64 Signal with filter max support. Enabled if any of the Tx/Rx 
    sint64 Signal supports filter max feature */
#define COM_SINT64_FILTER_MAX_VALUE_SUPPORT               STD_ON
/*! @brief Enables/Disables the Com signal gateway support .Enabled if any of the Rx signal or signal group supports 
    gateway feature */
#define COM_SIGNAL_GATEWAY_SUPPORT             			  STD_OFF
/*! @brief Enables/Disables the Com signal float32 type support .Enabled if any of the signal supports float32 type */
#define COM_SIGNAL_TYPE_FLOAT32_SUPPORT                   STD_ON
/*! @brief Enables/Disables the Com signal float64 type support .Enabled if any of the signal supports float32 type */
#define COM_SIGNAL_TYPE_FLOAT64_SUPPORT                   STD_ON
/*********************************************************************************************************************
*                                 #! Com SW and AUTOSAR Version Macros                                               *
*********************************************************************************************************************/
/*! @brief Defines the Com configuration software Major version */
#define COM_CFG_SW_MAJOR_VERSION                    	  1u
/*! @brief Defines the Com configuration software Minor version */
#define COM_CFG_SW_MINOR_VERSION                          0u
/*! @brief Defines the Com configuration software Patch version */
#define COM_CFG_SW_PATCH_VERSION                          0u
/* Autosar Release */
/*! @brief Defines the AUTOSAR Release Major version supported by Com configuration  */
#define COM_CFG_AR_RELEASE_MAJOR_VERSION                  4u
/*! @brief Defines the AUTOSAR Release Minor version supported by Com configuration  */
#define COM_CFG_AR_RELEASE_MINOR_VERSION                  3u
/*! @brief Defines the AUTOSAR Release Patch version supported by Com configuration  */
#define COM_CFG_AR_RELEASE_REVISION_VERSION               1u

/*********************************************************************************************************************
*                                 #! IPDU Group Configuration Macro                                                  *
*********************************************************************************************************************/
/*! @brief Defines the I-PDU group id */
#define COM_IPDU_GROUP_BHCAN_TX                   	      0U
#define COM_IPDU_GROUP_BHCAN_RX                           1U
#define COM_IPDU_GROUP_FDCCAN_TX                          2U
#define COM_IPDU_GROUP_FDCCAN_RX                          3U
/*! @brief Defines the maximum number of supported I-PDU groups */
#define COM_SUPPORTED_IPDU_GROUPS                         4U
/*! @brief Defines the number of bytes used for the I-PDU Group bit representation */
#define COM_NUM_OF_IPDU_GROUP_VECTOR_BYTES              ((COM_SUPPORTED_IPDU_GROUPS/8U)+1U)

/*********************************************************************************************************************
*                                 #! Tx Ipdu Configuration Macro                                                     *
*********************************************************************************************************************/
/*! @brief Defines the number of uint8 buffer for Tx I-PDU . 
    \ref Com_TxIpduBuffer , Com_TxIpduBufferInitValues  */
#define COM_TX_IPDU_BUFFER_SIZE                     	    8U
/*! @brief Defines the number of Com Tx I-PDU timeout counters. 
    \ref Com_TxIpduTxTimeoutCounter , Com_TxIpduTimeoutCounterConfig */
#define COM_NUM_OF_TX_IPDU_TIMEOUT_COUNTER_ID               1U

#if(COM_TX_IPDU_CALLOUT_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Tx I-PDU tx callout function id .
    \ref Com_TxIpduCalloutFuncConfig */
#define COM_NUM_OF_TX_IPDU_CALLOUT_FUNC_ID                  1U
#endif

#if(COM_TX_IPDU_TRIGGER_TRANSMIT_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Tx I-PDU trigger tx callout function id .
    \ref Com_TxIpduTriggerTxCalloutFunctConfig */
#define COM_NUM_OF_TX_IPDU_TRIGGER_TX_CALLOUT_FUNC_ID       1U
#endif

#if(COM_TX_TP_IPDU_SUPPORT  == STD_ON)
/*! @brief Defines the number of Com Tx Tp I-PDU id .
    \ref Com_TxTpIpduBufferState , Com_TxTpIpduCurrentPosition , Com_TxTpIpduBufferConfig  */  
#define COM_NUM_OF_TX_TP_IPDU_ID                            1U
/*! @brief Defines the Com Tx Tp I-PDU buffer size .
    \ref Com_TxTpIpduBuffer , Com_TxTpIpduBufferInitValues   */    
#define COM_TX_TP_TOTAL_BUFFERS                             1U
#endif

/*! @brief Defines the Com Transmit PDU IDs */
#define COM_PDU_CLIMATIC_PANEL                              0U 
#define COM_NUM_OF_TX_IPDU_ID                               1U
/*********************************************************************************************************************
*                                 #! Tx signal Configuration Macro                                                   *
*********************************************************************************************************************/
/*! @brief Defines the number of Com Tx signals Ack callout functions . \ref Com_CbkTxAckFunctConfig */
#define COM_NUM_OF_TX_ACK_FUNCTION                 		    1U
/*! @brief Defines the number of Com Tx signals error callout functions. \ref Com_CbkTxErrFunctConfig */
#define COM_NUM_OF_TX_ERR_FUNCTION                          1U
/*! @brief Defines the number of Com Tx signals error timeout functions. \ref COM_NUM_OF_TX_TOUT_FUNCTION */
#define COM_NUM_OF_TX_TOUT_FUNCTION                         1U

#if(COM_TX_SIGNAL_UB_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Tx signal ub configuration id. \ref Com_TxSignalUBConfig */
#define COM_NUM_OF_TX_SIGNAL_UB_ID                          1U
#endif

/*! @brief Defines the Com Tx signals group buffer size. 
    \ref Com_TxIpduShadowBuffer , Com_TxIpduShadowBufferInitValues */
#define COM_TX_SHADOW_BUFFER_SIZE                           1U

#if(COM_TX_SIGNAL_GROUP_UB_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Tx signal group ub configuration id */
#define COM_NUM_OF_TX_SIGNAL_GROUP_UB_ID                    1U
#endif

#if(COM_TX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON)
/*! @brief Defines the Com Tx signals array on change mask buffer size. \ref Com_SignalArrayOnChageMask */
#define COM_TX_SIGNAL_ARRAY_SIZE                            1U
#endif

#if(COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Tx signal filter configuration id .
    \ref Com_TxSignalFilterConfig , Com_TxSignalFilterState */
#define COM_NUM_OF_TX_SIGNAL_FILTER_ID                      1U
#endif

#if((COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_ON) || (COM_TX_SIGNAL_GROUP_INVALIDATE_SUPPORT == STD_ON))
    
#if(COM_TX_SIGNAL_INVALID_BOOLEAN_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Tx signal boolean invalid data configuration id .
    \ref Com_BooleanSignalInvalidData */
#define COM_BOOL_SIGNAL_INVALID_DATA_BUFFER_SIZE            1U
#endif      

#if(COM_TX_SIGNAL_INVALID_UINT8_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Tx signal uint8 invalid data configuration id .
    \ref Com_Uint8SignalInvalidData */
#define COM_UINT8_SIGNAL_INVALID_DATA_BUFFER_SIZE           1U
#endif

#if(COM_TX_SIGNAL_INVALID_SINT8_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Tx signal sint8 invalid data configuration id .
    \ref Com_Sint8SignalInvalidData */
#define COM_SINT8_SIGNAL_INVALID_DATA_BUFFER_SIZE           1U
#endif

#if(COM_TX_SIGNAL_INVALID_UINT16_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Tx signal uint16 invalid data configuration id .
    \ref Com_Uint16SignalInvalidData */
#define COM_UINT16_SIGNAL_INVALID_DATA_BUFFER_SIZE          1U
#endif  

#if(COM_TX_SIGNAL_INVALID_SINT16_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Tx signal sint16 invalid data configuration id .
    \ref Com_Sint16SignalInvalidData */
#define COM_SINT16_SIGNAL_INVALID_DATA_BUFFER_SIZE          1U
#endif

#if(COM_TX_SIGNAL_INVALID_UINT32_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Tx signal uint32 invalid data configuration id .
    \ref Com_Uint32SignalInvalidData */
#define COM_UINT32_SIGNAL_INVALID_DATA_BUFFER_SIZE          1U
#endif

#if(COM_TX_SIGNAL_INVALID_SINT32_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Tx signal sint32 invalid data configuration id .
    \ref Com_Sint32SignalInvalidData */
#define COM_SINT32_SIGNAL_INVALID_DATA_BUFFER_SIZE          1U
#endif

#if(COM_TX_SIGNAL_INVALID_UINT64_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Tx signal uint64 invalid data configuration id .
    \ref Com_Uint64SignalInvalidData */
#define COM_UINT64_SIGNAL_INVALID_DATA_BUFFER_SIZE          1U
#endif

#if(COM_TX_SIGNAL_INVALID_SINT64_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Tx signal sint64 invalid data configuration id .
    \ref Com_Sint64SignalInvalidData */
#define COM_SINT64_SIGNAL_INVALID_DATA_BUFFER_SIZE          1U
#endif

#if(COM_TX_SIGNAL_INVALID_FLOAT32_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Tx signal float32 invalid data configuration id .
    \ref Com_Float32SignalInvalidData */
#define COM_FLOAT32_SIGNAL_INVALID_DATA_BUFFER_SIZE         1U
#endif

#if(COM_TX_SIGNAL_INVALID_FLOAT64_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Tx signal float64 invalid data configuration id .
    \ref Com_Float64SignalInvalidData */
#define COM_FLOAT64_SIGNAL_INVALID_DATA_BUFFER_SIZE         1U
#endif

#if(COM_TX_SIGNAL_INVALID_UINT8ARR_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Tx signal uint8_n invalid data configuration id .
    \ref Com_BooleanSignalInvalidData */
#define COM_UINT8ARR_SIGNAL_INVALID_DATA_BUFFER_SIZE        1U
#endif

#endif

/*! @brief Defines the Com Transmit signals Ids */
#define COM_SIGNAL_RADIO_KNOB1_VAL_1050                     0U 
#define COM_SIGNAL_RADIO_KNOB1_DIR_1050                     1U
#define COM_SIGNAL_RADIO_KNOB2_VAL_1050                     2U
#define COM_SIGNAL_RADIO_KNOB2_DIR_1050                     3U
#define COM_SIGNAL_RADIO_BTN4_1050                          4U
#define COM_SIGNAL_RADIO_BTN3_1050                          5U
#define COM_SIGNAL_RADIO_BTN2_1050                          6U
#define COM_SIGNAL_RADIO_BTN1_1050                          7U
#define COM_SIGNAL_RADIO_BTN0_1050                          8U
#define COM_NUM_OF_TX_SIGNAL_ID                             9U

/*! @brief Defines the Com Transmit signals Group Ids */
#define COM_NUM_OF_TX_SIGNAL_GROUP_ID                       1U
/*********************************************************************************************************************
*                                 #! Rx Ipdu Configuration Macro                                                     *
*********************************************************************************************************************/
/*! @brief Defines the number of uint8 buffer for Rx I-PDU. \ref Com_RxIpduBuffer , Com_RxIpduBufferInitValues */
#define COM_RX_IPDU_BUFFER_SIZE                             12U
/*! @brief Defines the number of Com Tx I-PDU timeout counters. 
    \ref Com_RxIpduDeadlineMonitoringState, Com_RxIpduDeadlineCounter, Com_RxIpduTimeoutCounterConfig */
#define COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID    	        1U

#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
/*! @brief Defines the Rx Tp I-PDU buffer size .
    \ref Com_RxTpIpduBuffer, Com_RxTpIpduRteBuffer, Com_RxTpIpduBufferInitValues   */
#define COM_RX_TP_BUFFER_SIZE                               1U
/*! @brief Defines the number of Rx Tp I-PDU id . 
    \ref Com_RxTpIpduBufferState ,Com_RxTpIpduBytesCopied,Com_RxTpIpduConfig  */
#define COM_NUM_OF_RX_TP_IPDU_ID                            1U
#endif

#if(COM_RX_IPDU_CALLOUT_SUPPORT == STD_ON)
/*! @brief Defines the number of Rx I-PDU callout function id . \ref Com_RxIpduCalloutFunctConfig */
#define COM_NUM_OF_RX_IPDU_CALLOUT_FUNC_ID                  1U
#endif

/*! @brief Defines the Com Receive PDU IDs */
#define COM_PDU_BODY_CNTRL7                                 0U 
#define COM_PDU_EXTERNAL_LIGHTS                             1U
#define COM_NUM_OF_RX_IPDU_ID                               2U
/*********************************************************************************************************************
*                                 #! Rx signal Configuration Macro                                                   *
*********************************************************************************************************************/
/*! @brief Defines the Rx signal invlalid Rte buffer id */
#define COM_RX_SIGNAL_RTE_INVALID_BUFFER_IDX                       0xFFU
/*! @brief Defines the Rx signal buffer size for uint8 signal. \ref Com_RxSignalRteU8Buffer */
#define COM_RX_SIGNAL_RTE_U8BUFFER_SIZE                            12U
/*! @brief Defines the Rx signal buffer size for uint16 signal. \ref Com_RxSignalRteU16Buffer */
#define COM_RX_SIGNAL_RTE_U16BUFFER_SIZE                           1U
/*! @brief Defines the Rx signal buffer size for uint32 signal. \ref Com_RxSignalRteU32Buffer */
#define COM_RX_SIGNAL_RTE_U32BUFFER_SIZE                           1U
/*! @brief Defines the Rx signal buffer size for uint64 signal. \ref Com_RxSignalRteU64Buffer */
#define COM_RX_SIGNAL_RTE_U64BUFFER_SIZE                           1U
/*! @brief Defines the Rx signal buffer size for uint_n signal. \ref Com_RxSignalRteArrBuffer */
#define COM_RX_SIGNAL_RTE_ARRBUFFER_SIZE                           1U
/*! @brief Defines the Rx signal init buffer size for uint8 signal. \ref Com_RxSignalU8InitBuffer */
#define COM_RX_SIGNAL_U8_INIT_BUFFER_SIZE                          1U
/*! @brief Defines the Rx signal init buffer size for uint16 signal. \ref Com_RxSignalU16InitBuffer */
#define COM_RX_SIGNAL_U16_INIT_BUFFER_SIZE                         1U
/*! @brief Defines the Rx signal init buffer size for uint32 signal. \ref Com_RxSignalU32InitBuffer */
#define COM_RX_SIGNAL_U32_INIT_BUFFER_SIZE                         1U
/*! @brief Defines the Rx signal init buffer size for uint64 signal. \ref Com_RxSignalU64InitBuffer */
#define COM_RX_SIGNAL_U64_INIT_BUFFER_SIZE                         1U
/*! @brief Defines the Rx signal init buffer size for uint_n signal. \ref Com_RxSignalArrInitBuffer */
#define COM_RX_SIGNAL_RTE_ARR_INIT_BUFFER_SIZE                     1U
/*! @brief Defines the Rx signal invlalid Rte init buffer id */
#define COM_RX_SIGNAL_RTE_INVALID_INIT_BUFFER_IDX                  0xFFU

#if (COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
/*! @brief Defines the Rx signal group shadow buffer size for uint_8 group signal.
    \ref Com_RxSignalShadowRteU8Buffer */
#define COM_RX_SIGNAL_SHADOW_RTE_U8BUFFER_SIZE                      1U
/*! @brief Defines the Rx signal group shadow buffer size for uint_16 group signal.
    \ref Com_RxSignalShadowRteU16Buffer */
#define COM_RX_SIGNAL_SHADOW_RTE_U16BUFFER_SIZE                     1U
/*! @brief Defines the Rx signal group shadow buffer size for uint_32 group signal.
    \ref Com_RxSignalShadowRteU32Buffer */
#define COM_RX_SIGNAL_SHADOW_RTE_U32BUFFER_SIZE                     1U
/*! @brief Defines the Rx signal group shadow buffer size for uint_64 group signal.
    \ref Com_RxSignalShadowRteU64Buffer */
#define COM_RX_SIGNAL_SHADOW_RTE_U64BUFFER_SIZE                     1U
/*! @brief Defines the Rx signal group shadow buffer size for uint_n group signal.
    \ref Com_RxSignalShadowRteArrBuffer */
#define COM_RX_SIGNAL_SHADOW_RTE_ARRBUFFER_SIZE                     1U
#endif

#if (COM_RX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON)
/*! @brief Defines the Rx signal group array buffer size. 
    \ref Com_RxSignalGroupRteArrayBuffer Com_RxSignalGroupRteArrayInitBuffer */
#define COM_RX_SIGNAL_GROUP_RTE_ARRAY_BUFFER_SIZE                   1U
#endif

/*! @brief to enable the coverity check for buffer overrun check from configuration index */
#define COM_ENABLE_EXTENDED_COV_CHECK

/*! @brief Defines the number of Com Rx signals Ack callout functions . \ref Com_CbkRxAckFunctConfig */
#define COM_NUM_OF_RX_ACK_FUNCT_ID                          1U
/*! @brief Defines the number of Com Rx signals Timeout callout functions . \ref Com_CbkRxToutFunctConfig */
#define COM_NUM_OF_RX_TOUT_FUNCT_ID                         1U
/*! @brief Defines the number of Com Rx signals Invalid callout functions . \ref Com_CbkRxInvFunctConfig */
#define COM_NUM_OF_RX_INV_FUNCT_ID                          1U

#if (COM_RX_SIGNAL_UB_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Rx signals UB  id . \ref Com_RxSignalUBConfig */
#define COM_NUM_OF_RX_SIGNAL_UB_ID                          1U
#endif

#if(COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Rx signals timeout id .
    \ref Com_RxSigDeadlineMonitoringState, Com_RxSigDeadlineCounter , Com_RxSigTimeoutCounterConfig */
#define COM_NUM_OF_RX_SIGNAL_TIMEOUT_COUNTER_ID             1U
#endif

#if (COM_RX_SIGNAL_GROUP_UB_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Rx signals group UB id . \ref Com_RxSignalGroupUBConfig */
#define COM_NUM_OF_RX_SIGNAL_GROUP_UB_ID                    1U
#endif

#if(COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Rx signal group timeout id . 
    \ref Com_RxSigGroupDeadlineMonitoringState, Com_RxSigGroupDeadlineCounter , Com_RxSigGroupTimeoutCounterConfig */
#define COM_NUM_OF_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_ID       1U
#endif


#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
/*! @brief Defines the number of Com Rx signal filter id. \ref Com_RxSignalFilterConfig */
#define COM_NUM_OF_RX_SIGNAL_FILTER_ID                      1U
#endif

#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
/*! @brief Defines the Com Rx signal sint64 invalid data buffer size . \ref Com_RxSint64SignalInvalidData */
#define COM_RX_SINT64_SIGNAL_INVALID_DATA_BUFFER_SIZE       1U
/*! @brief Defines the Com Rx signal uint64 invalid data buffer size . \ref Com_RxUint64SignalInvalidData */
#define COM_RX_UINT64_SIGNAL_INVALID_DATA_BUFFER_SIZE       1U
/*! @brief Defines the Com Rx signal sint32 invalid data buffer size . \ref Com_RxSint32SignalInvalidData */
#define COM_RX_SINT32_SIGNAL_INVALID_DATA_BUFFER_SIZE       1U
/*! @brief Defines the Com Rx signal uint32 invalid data buffer size . \ref Com_RxUint32SignalInvalidData */
#define COM_RX_UINT32_SIGNAL_INVALID_DATA_BUFFER_SIZE       1U
/*! @brief Defines the Com Rx signal sint16 invalid data buffer size . \ref Com_RxSint16SignalInvalidData */
#define COM_RX_SINT16_SIGNAL_INVALID_DATA_BUFFER_SIZE       1U
/*! @brief Defines the Com Rx signal uint16 invalid data buffer size . \ref Com_RxUint16SignalInvalidData */
#define COM_RX_UINT16_SIGNAL_INVALID_DATA_BUFFER_SIZE       1U
/*! @brief Defines the Com Rx signal sint8 invalid data buffer size . \ref Com_RxSint8SignalInvalidData */
#define COM_RX_SINT8_SIGNAL_INVALID_DATA_BUFFER_SIZE        1U
/*! @brief Defines the Com Rx signal uint8 invalid data buffer size . \ref Com_RxUint8SignalInvalidData */
#define COM_RX_UINT8_SIGNAL_INVALID_DATA_BUFFER_SIZE        1U
/*! @brief Defines the Com Rx signal boolean invalid data buffer size . \ref Com_RxBooleanSignalInvalidData */
#define COM_RX_BOOLEAN_SIGNAL_INVALID_DATA_BUFFER_SIZE      1U
/*! @brief Defines the Com Rx signal uint8_n invalid data buffer size . \ref Com_RxUint8ArrSignalInvalidData */
#define COM_RX_UINT8_ARR_SIGNAL_INVALID_DATA_BUFFER_SIZE    1U 
#endif

/*! @brief Defines the Com Receive signals Ids */
#define COM_SIGNAL_HAZ_SWITCH_FB_250                        0U 
#define COM_SIGNAL_IPDIMMERPOS_FB_250                       1U
#define COM_SIGNAL_HLS_LEVEL_FB_250                         2U
#define COM_SIGNAL_HLS_REQ_FB_250                           3U
#define COM_SIGNAL_RR_FOG_REQ_FB_250                        4U
#define COM_SIGNAL_SCCACTVSTS_250                           5U
#define COM_SIGNAL_LHTURNSIGNALSTS_852                      6U
#define COM_NUM_OF_RX_SIGNAL_ID                             7U

/*! @brief Defines the number of Com Rx signal group id */
#define COM_NUM_OF_RX_SIGNAL_GROUP_ID                       1U
/*********************************************************************************************************************
*                                 #! Tx,Rx Common Configuration Macro                                                *
*********************************************************************************************************************/
/*! Defines the endianess type as little */
#define COM_ENDIANESS_LITTLE    0U
/*! Defines the endianess type as BIG */
#define COM_ENDIANESS_BIG       1U
/*! Defines the micro endianess configuration */
#define COM_MICRO_ENDIANESS     COM_ENDIANESS_LITTLE

/*! @brief dummy statement macro */
#ifndef COM_DUMMY_STATEMENT
#define COM_DUMMY_STATEMENT(param)                  ((void)(param))
#endif

/* Common filter configuration */
#if (COM_BOOLEAN_FILTER_MASK_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal boolean filter mask id . \ref Com_BooleanFilterMaskValueConfig */
#define COM_NUM_OF_BOOLEAN_FILTER_MASK_ID   1U
#endif

#if (COM_BOOLEAN_FILTER_X_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal boolean filter X id . \ref Com_BooleanFilterXValueConfig */
#define COM_NUM_OF_BOOLEAN_FILTER_X_ID      1U
#endif

#if (COM_UINT8_FILTER_MASK_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal uint8 filter mask id . \ref Com_Uint8FilterMaskValueConfig */
#define COM_NUM_OF_UINT8_FILTER_MASK_ID     1U
#endif

#if (COM_UINT8_FILTER_X_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal uint8 filter X id . \ref Com_Uint8FilterXValueConfig */
#define COM_NUM_OF_UINT8_FILTER_X_ID        1U
#endif

#if (COM_UINT8_FILTER_MIN_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal uint8 filter min id . \ref Com_Uint8FilterMinValueConfig */
#define COM_NUM_OF_UINT8_FILTER_MIN_ID      1U
#endif

#if (COM_UINT8_FILTER_MAX_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal uint8 filter max id . \ref Com_Uint8FilterMaxValueConfig */
#define COM_NUM_OF_UINT8_FILTER_MAX_ID      1U
#endif

#if (COM_SINT8_FILTER_MASK_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal sint8 filter mask id . \ref Com_Sint8FilterMaskValueConfig */
#define COM_NUM_OF_SINT8_FILTER_MASK_ID     1U
#endif

#if (COM_SINT8_FILTER_X_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal sint8 filter X id . \ref Com_Sint8FilterXValueConfig */
#define COM_NUM_OF_SINT8_FILTER_X_ID        1U
#endif

#if (COM_SINT8_FILTER_MIN_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal sint8 filter min id . \ref Com_Sint8FilterMinValueConfig */
#define COM_NUM_OF_SINT8_FILTER_MIN_ID      1U
#endif

#if (COM_SINT8_FILTER_MAX_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal sint8 filter max id . \ref Com_Sint8FilterMaxValueConfig */
#define COM_NUM_OF_SINT8_FILTER_MAX_ID      1U
#endif

#if (COM_UINT16_FILTER_MASK_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal uint16 filter mask id . \ref Com_Uint16FilterMaskValueConfig */
#define COM_NUM_OF_UINT16_FILTER_MASK_ID    1U
#endif

#if (COM_UINT16_FILTER_X_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal uint16 filter X id . \ref Com_Uint16FilterXValueConfig */
#define COM_NUM_OF_UINT16_FILTER_X_ID       1U
#endif

#if (COM_UINT16_FILTER_MIN_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal uint16 filter min id . \ref Com_Uint16FilterMinValueConfig */
#define COM_NUM_OF_UINT16_FILTER_MIN_ID     1U
#endif

#if (COM_UINT16_FILTER_MAX_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal uint16 filter max id . \ref Com_Uint16FilterMaxValueConfig */
#define COM_NUM_OF_UINT16_FILTER_MAX_ID     1U
#endif

#if (COM_SINT16_FILTER_MASK_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal sint16 filter mask id . \ref Com_Sint16FilterMaskValueConfig */
#define COM_NUM_OF_SINT16_FILTER_MASK_ID    1U
#endif

#if (COM_SINT16_FILTER_X_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal sint16 filter X id . \ref Com_Sint16FilterXValueConfig */
#define COM_NUM_OF_SINT16_FILTER_X_ID       1U
#endif

#if (COM_SINT16_FILTER_MIN_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal sint16 filter min id . \ref Com_Sint16FilterMinValueConfig */
#define COM_NUM_OF_SINT16_FILTER_MIN_ID     1U
#endif

#if (COM_SINT16_FILTER_MAX_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal sint16 filter max id . \ref Com_Sint16FilterMaxValueConfig */
#define COM_NUM_OF_SINT16_FILTER_MAX_ID     1U
#endif

#if (COM_UINT32_FILTER_MASK_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal uint32 filter mask id . \ref Com_Uint32FilterMaskValueConfig */
#define COM_NUM_OF_UINT32_FILTER_MASK_ID    1U
#endif

#if (COM_UINT32_FILTER_X_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal uint32 filter X id . \ref Com_Uint32FilterXValueConfig */
#define COM_NUM_OF_UINT32_FILTER_X_ID       1U
#endif

#if (COM_UINT32_FILTER_MIN_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal uint32 filter min id . \ref Com_Uint32FilterMinValueConfig */
#define COM_NUM_OF_UINT32_FILTER_MIN_ID     1U
#endif

#if (COM_UINT32_FILTER_MAX_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal uint32 filter max id . \ref Com_Uint32FilterMaxValueConfig */
#define COM_NUM_OF_UINT32_FILTER_MAX_ID     1U
#endif

#if (COM_SINT32_FILTER_MASK_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal sint32 filter mask id . \ref Com_Sint32FilterMaskValueConfig */
#define COM_NUM_OF_SINT32_FILTER_MASK_ID    1U
#endif

#if (COM_SINT32_FILTER_X_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal sint32 filter X id . \ref Com_Sint32FilterXValueConfig */
#define COM_NUM_OF_SINT32_FILTER_X_ID       1U
#endif

#if (COM_SINT32_FILTER_MIN_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal sint32 filter min id . \ref Com_Sint32FilterMinValueConfig */
#define COM_NUM_OF_SINT32_FILTER_MIN_ID     1U
#endif

#if (COM_SINT32_FILTER_MAX_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal sint32 filter max id . \ref Com_Sint32FilterMaxValueConfig */
#define COM_NUM_OF_SINT32_FILTER_MAX_ID     1U
#endif

#if (COM_UINT64_FILTER_MASK_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal uint64 filter mask id . \ref Com_Uint64FilterMaskValueConfig */
#define COM_NUM_OF_UINT64_FILTER_MASK_ID    1U
#endif

#if (COM_UINT64_FILTER_X_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal uint64 filter X id . \ref Com_Uint64FilterXValueConfig */
#define COM_NUM_OF_UINT64_FILTER_X_ID       1U
#endif

#if (COM_UINT64_FILTER_MIN_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal uint64 filter min id . \ref Com_Uint64FilterMinValueConfig */
#define COM_NUM_OF_UINT64_FILTER_MIN_ID     1U
#endif

#if (COM_UINT64_FILTER_MAX_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal uint64 filter max id . \ref Com_Uint64FilterMaxValueConfig */
#define COM_NUM_OF_UINT64_FILTER_MAX_ID     1U
#endif

#if (COM_SINT64_FILTER_MASK_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal sint64 filter mask id . \ref Com_Sint64FilterMaskValueConfig */
#define COM_NUM_OF_SINT64_FILTER_MASK_ID    1U
#endif

#if (COM_SINT64_FILTER_X_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal sint64 filter X id . \ref Com_Sint64FilterXValueConfig */
#define COM_NUM_OF_SINT64_FILTER_X_ID       1U
#endif

#if (COM_SINT64_FILTER_MIN_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal sint64 filter min id . \ref Com_Sint64FilterMinValueConfig */
#define COM_NUM_OF_SINT64_FILTER_MIN_ID     1U
#endif

#if (COM_SINT64_FILTER_MAX_VALUE_SUPPORT == STD_ON)
/*! @brief Defines the number of Com signal sint64 filter max id . \ref Com_Sint64FilterMaxValueConfig */
#define COM_NUM_OF_SINT64_FILTER_MAX_ID     1U
#endif

#if (COM_SIGNAL_GATEWAY_SUPPORT == STD_ON)
/*! @brief Defines the number of Gateway destination signal id . \ref Com_GatewayDestSignalConfig*/
#define COM_NUM_OF_GW_DEST_SIGNAL_ID        1U
/*! @brief Defines the number of Gateway source signal id . \ref Com_GatewaySourceSignalConfig*/
#define COM_NUM_OF_GW_SRC_SIGNAL_ID         1U
/*! @brief Defines the number of Gateway  signal id . \ref Com_GwDestinationConfig*/
#define COM_NUM_OF_GW_SIGNAL_ID             1U
#endif
/*********************************************************************************************************************
*                                 #! Com configuration macros ,typedef and structure                                 *
*********************************************************************************************************************/
/*! Defines the group transmit types as transmit , Com_IpduGroupDirectionType*/
#define COM_IPU_GROUP_DIRECTION_TYPE_TRANMSIT   0U
/*! Defines the group transmit types as receive , Com_IpduGroupDirectionType */
#define COM_IPU_GROUP_DIRECTION_TYPE_RECEIVE    1U

/*! @brief Defines the method of processing the I-PDU as Deferred.
 signal indication / confirmations are defer-red for example to a cyclic task */
#define COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED 0U
/*! @brief Defines the method of processing the I-PDU as Immediate.
 the signal indications / confirmations are performed in Com_RxIndication/ Com_TxConfirmation */
#define COM_IPDU_SIGNAL_PROCESSING_TYPE_IMMEDIATE 1U

/*! @brief Defines the type of I-PDU as normal I-PDU that can be sent unfragmented */
#define COM_IPDU_TYPE_NORMAL 0U
/*! @brief Defines the type of I-PDU as TP I-PDU that is a large I-PDU that shall be
 sent via the Transport Protocol of the underlying bus. */
#define COM_IPDU_TYPE_TP 1U

/*! @brief Defines the type of transmission modes as None. Transmission not possible*/
#define COM_TX_MODE_MODE_TYPE_NONE 0U
/*! @brief Defines the type of transmission modes as Direct .The transmission is explicitly
 initiated by sending a message with Triggered Transfer Property. */
#define COM_TX_MODE_MODE_TYPE_DIRECT 1U
/*! @brief Defines the type of transmission modes as Periodic.
 The I-PDU is transmitted repeatedly with a pre-set period */
#define COM_TX_MODE_MODE_TYPE_PERIODIC 2U
/*! @brief Defines the type of transmission modes as Mixed . I.e Both Direct and Periodic modes*/
#define COM_TX_MODE_MODE_TYPE_MIXED 3U

/*! @brief Defines that no update-bits of signals or signal groups are available*/
#define COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_NONE 0U
/*! @brief Defines that the update-bits of signals or signal groups,contained in this I-PDU,
 will be cleared when transmission of the I-PDU was confirmed */
#define COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_CONFIRMATION 1U
/*! @brief Defines that the update-bits of signals or signal groups,contained in this I-PDU,
 will be cleared when directly after the invocation of PduR_ComTransmit */
#define COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_TRANSMIT 2U
/*! @brief Defines that the update-bits of signals or signal groups,contained in this I-PDU,
 will be cleared when the I-PDU was fetched via Com_TriggerTransmit*/
#define COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_TRIGGER_TRANSMIT 3U

/*! @brief Defines the type of Tx mode configuration to be used if the ComFilter results FALSE*/
#define COM_IPDU_TX_MODE_TYPE_FALSE (uint8)0U
/*! @brief Defines the type of Tx mode configuration to be used if the ComFilter results TRUE*/
#define COM_IPDU_TX_MODE_TYPE_TRUE (uint8)1U

/*! @brief Defines the endianness of the signal's network representation as Big endian */
#define COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN 0U
/*! @brief Defines the endianness of the signal's network representation as Little endian */
#define COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN 1U
/*! @brief Defines the endianness of the signal's network representation as Opaque.
 With this type , the data is interpret as a n-bytes sized signal*/
#define COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_OPAQUE 2U

/*! @brief Defines that the signals shall not be replaced by their ComSig-nalInitValue
 upon expiration of the reception dead-line monitoring timer */
#define COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE 0U
/*! @brief Defines that the signals shall be replaced by their ComSig-nalInitValue upon
 expiration of the reception dead-line monitoring timer */
#define COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE 1U
/*! @brief  Defines that signals shall be replaced by their ComTimeoutSubstitutionValue */
#define COM_RX_DATA_TIMEOUT_ACTION_TYPE_SUBSTITUTE 2U

/*! @brief Defines the AUTOSAR type as BOOLEAN*/
#define COM_SIGNALTYPE_BOOLEAN 0U
/*! @brief Defines the AUTOSAR type as IEEE754 float32*/
#define COM_SIGNALTYPE_FLOAT32 1U
/*! @brief Defines the AUTOSAR type as IEEE754 float64*/
#define COM_SIGNALTYPE_FLOAT64 2U
/*! @brief Defines the AUTOSAR type as sint16*/
#define COM_SIGNALTYPE_SINT16 3U
/*! @brief Defines the AUTOSAR type as sint32*/
#define COM_SIGNALTYPE_SINT32 4U
/*! @brief Defines the AUTOSAR type as sint64*/
#define COM_SIGNALTYPE_SINT64 5U
/*! @brief Defines the AUTOSAR type as sint8*/
#define COM_SIGNALTYPE_SINT8 6U
/*! @brief Defines the AUTOSAR type as uint16*/
#define COM_SIGNALTYPE_UINT16 7U
/*! @brief Defines the AUTOSAR type as uint32*/
#define COM_SIGNALTYPE_UINT32 8U
/*! @brief Defines the AUTOSAR type as uint64*/
#define COM_SIGNALTYPE_UINT64 9U
/*! @brief Defines the AUTOSAR type as uint8*/
#define COM_SIGNALTYPE_UINT8 10U
/*! @brief Defines the AUTOSAR type as uint8 Dynamic array .
 The maximum length of the array is defined .*/
#define COM_SIGNALTYPE_UINT8_DYN 11U
/*! @brief Defines the AUTOSAR type as uint8 array */
#define COM_SIGNALTYPE_UINT8_N 12U

/*! @brief Defines the type of Com signal filter algorithm as Always . This
 allows signals as no filtering is performed.*/
#define COM_FILTER_ALGORITHM_TYPE_ALWAYS 0U
/*! @brief Defines the type of Com signal filter algorithm which allows signals
 only if the masked value has changed. (new_value&mask) != (old_value&mask) */
#define COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_MASKED_OLD 1U
/*! @brief Defines the type of Com signal filter algorithm which allows signals
 only if the masked value is not equal to a specific value.
 (new_value&mask) != x */
#define COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_DIFFERS_X 2u
/*! @brief Defines the type of Com signal filter algorithm which allows signals
 only if the masked value is equal to a specific value.
 (new_value&mask) == x */
#define COM_FILTER_ALGORITHM_TYPE_MASKED_NEW_EQUALS_X 3u
/*! @brief Defines the type of Com signal filter algorithm as Never . This
 will not allow the signals .*/
#define COM_FILTER_ALGORITHM_TYPE_NEVER 4u
/*! @brief Defines the type of Com signal filter algorithm which allows signals
 only if its value is outside a predefined boundary.
 (min > new_value) OR (new_value > max) */
#define COM_FILTER_ALGORITHM_TYPE_NEW_IS_OUTSIDE 5u
/*! @brief Defines the type of Com signal filter algorithm which allows signals
 only if its value is within a predefined boundary.
 min <= new_value <= max */
#define COM_FILTER_ALGORITHM_TYPE_NEW_IS_WITHIN 6u
/*! @brief Defines the type of Com signal filter algorithm which allows signals
 only if Pass a message once every N message occurrences.
 Start: occurrence = 0. Each time the message is received or transmitted,
 occurrence is incremented by 1 after filtering.
 Length of occurrence is 8 bit (minimum).
 occurrence % period == offset */
#define COM_FILTER_ALGORITHM_TYPE_ONE_EVERY_N 7u

/*! @brief A write access to this signal never triggers the transmission of the cor-responding I-PDU. */
#define COM_SIGNAL_TRANSFER_PROPERTY_TYPE_PENDING 0U
/*! @brief Depending on the trans-mission mode, a write access to this signal can trigger the
 transmission of the corresponding I-PDU*/
#define COM_SIGNAL_TRANSFER_PROPERTY_TYPE_TRIGGERED 1U
/*! @brief Depending on the trans-mission mode, a write access to this signal can trigger the
 transmission of the corresponding I-PDU, but only in case the written value is different
 to the locally stored (last sent or initial value) in length or value.*/
#define COM_SIGNAL_TRANSFER_PROPERTY_TYPE_TRIGGERED_ON_CHANGE 2U
/*! @brief Depending on the trans-mission mode, a write access to this signal can trigger the
 transmission of the corresponding I-PDU just once without a repetition, but only in case
 the written value is different to the locally stored (last sent or initial value) in length or value*/
#define COM_SIGNAL_TRANSFER_PROPERTY_TYPE_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION 3U
/*! @brief Depending on the trans-mission mode, a write access to this signal can trigger the transmission
 of the corresponding I-PDU just once without a repetition.*/
#define COM_SIGNAL_TRANSFER_PROPERTY_TYPE_TRIGGERED_WITHOUT_REPETITION 4U

/*! @brief Defines that COM module shall notify the RTE via the configured ComInvalidNotification
 function reception of an invalid signal. */
#define COM_DATA_INVALID_ACTION_NOTIFY 0U
/*! @brief Defines that the AUTOSAR COM module shall replace the signal’s value by
 its configured ComSignalInitValue upon reception of an invalid signal. */
#define COM_DATA_INVALID_ACTION_REPLACE 1U
/*! @brief Defines the action performed upon reception if no invalid signal value is configured. */
#define COM_DATA_INVALID_ACTION_NONE 2U

/*! @brief A change of the value of this group signal shall not be considered in the evaluation
 of the signal groups Com-TransferProperty. */
#define COM_GROUP_SIGNAL_TRANSFER_PROPERTY_TYPE_PENDING 0U
/*! @brief A change of the value of this group signal shall be considered in the evaluation
 of the signal groups ComTrans-ferProperty. */
#define COM_GROUP_SIGNAL_TRANSFER_PROPERTY_TYPE_TRIGGERED_ON_CHANGE 1U

/* Com Signal Gateway configuration */
#if (COM_SIGNAL_GATEWAY_SUPPORT == STD_ON)
/*! Defines the type of gateway signal reference as the signal Id reference */
#define COM_GATEWAY_REF_TYPE_SIGNAL_ID 0U
/*! Defines the type of gateway signal reference as the signal Description reference */
#define COM_GATEWAY_REF_TYPE_SIGNAL_DESCRIPTION 1U
#endif

/********************************************************************************************************************
*                                       #! Com Internal types                                                       *
*                                       #! typedef declaration                                                      *
********************************************************************************************************************/
/*! @brief Defines the endianess type */
typedef uint8 Com_EndianessType;
/*! @brief Defines the max buffer size type */
typedef uint16 Com_BufferSizeType;
/*! @brief Defines the max bit size type */
typedef uint16 Com_BitLengthSizeType;
/*! @brief Defines the type for method of processing the I-PDU */
typedef uint8 Com_IpduSignalProcessingType;
/*! @brief Defines Defines if this I-PDU is a normal I-PDU that can be sent unfragmented or
 if this is a large I-PDU that shall be sent via the Transport Protocol of the underlying bus. */
typedef uint8 Com_IpduType;
/*! @brief Defines the endianness of the signal's network representation */
typedef uint8 Com_SignalEndiannessType;
/*! Defines the AUTOSAR type of the signal */
typedef uint8 Com_SignalType;
/*! @brief Defines the type of Com signal filter algorithm used .*/
typedef uint8 Com_FilterAlgorithmType;
/*! @brief Defines the type of the filter mask value buffer ID*/
typedef uint16 Com_FilterMaskBufferIdType;
/*! @brief Defines the type of the filter max value buffer ID*/
typedef uint16 Com_FilterMaxBufferIdType;
/*! @brief Defines the type of the filter min value buffer ID*/
typedef uint16 Com_FilterMinBufferIdType;
/*! @brief Defines the type of the filter X value buffer ID*/
typedef uint16 Com_FilterXBufferIdType;
/*! @brief Defines the type of Signal access configuration Id */
typedef Com_SignalIdType Com_SignalAccessIdType;
/*! @brief Defines the type for signal buffer ID. */
typedef uint16 Com_SignalValueBufferIdType;
/*! @brief Defines the type for signal buffer ID. */
typedef uint16 Com_UBPropsConfigIdType;
/*! @brief This type can be used to store a flag (bit) for each I-PDU group within the system.
 It is used for setting the activation state and deadline monitoring state for I-PDU
 groups within one function call */
typedef uint8 Com_IpduGroupVector[COM_NUM_OF_IPDU_GROUP_VECTOR_BYTES];
/*! @brief Defines the group transmit types  */
typedef uint8 Com_IpduGroupDirectionType;
/*! @brief Defines the type for Ipdu Group byte Id */
typedef uint8 Com_IpduGroupByteIdType;

/*! @brief Defines the type for Tx Ipdu Buffer Id */
typedef uint8 Com_TxIpduBufferIdType;
/*! @brief Defines the type for Tx Ipdu tout id */
typedef uint8 Com_TxIpduToutIdType;
/*! @brief Defines the type for Tx ipdu shadow buffer id */
typedef uint8 Com_TxIpduShadowBufferIdType;
#if ((COM_TX_IPDU_COUNTER_SUPPORT == STD_ON) || (COM_RX_IPDU_COUNTER_SUPPORT == STD_ON))
/*! @brief Defines the function type for the I-PDU counter error notification */
typedef P2FUNC (void, COM_APPL_CODE,Com_ComIpduCounterErrorNotificationFunctType)
(
    PduIdType ComPduId,
    uint8 ExpectedCounter,
    uint8 ReceivedCounter
);
/*! @brief Defines the type of the counter ID*/
typedef uint8 Com_IpduCounterIdType;
#endif
/*! @brief Defines the type of transmission modes for the I-PDU */
typedef uint8 Com_TxModeModeType;
/*! @brief Defines when the update-bits of signals or signal groups, contained in this I-PDU, will be cleared. */
typedef uint8 Com_TxIpduClearUpdateBitType;
#if (COM_TX_IPDU_CALLOUT_SUPPORT == STD_ON)
/*! @brief Defines the function type for the TX I-PDU callout */
typedef P2FUNC(boolean,COM_APPL_CODE,Com_TxIpduCalloutFunctType)(PduIdType PduId, PduInfoType* PduInfoPtr);
/*! @brief Defines the type for the I-PDU Tx callout function Id */
typedef uint8 Com_TxIpduCalloutFunctIdType;
#endif
#if (COM_TX_IPDU_TRIGGER_TRANSMIT_SUPPORT == STD_ON)
/*! @brief Defines the function type for the trigger transmit callout for the I-PDU */
typedef P2FUNC(boolean,COM_APPL_CODE,Com_TxIpduTriggerTxCalloutFunctType)(PduIdType PduId, PduInfoType* PduInfoPtr);
/*! @brief Defines the type for the I-PDU Tx trigger callout function Id */
typedef uint8 Com_TxIpduTriggerTransmitCalloutFunctIdType;
#endif
/*! @brief Defines the type for the Tx I-PDU periodic counter ID */
typedef uint32 Com_TxIpduPeriodicCounterIdType;
#if (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*! @brief Defines the type for the Tx I-PDU timeout counter ID */
typedef uint32 Com_TxIpduTimeoutCounterIdType;
#endif
/*! @brief Defines the type for the Tx TP I-PDU config Id */
typedef uint8 Com_TxTpConfigId;
/*! @brief Defines the type for the Tx TP I-PDU Buffer Id */
typedef uint16 Com_TxTpBufferId;
/*! @brief Defines the type for the Tx shadow Buffer Id */
typedef uint8 Com_TxShadowBufferIdType;
/*! @brief Defines the type for the Tx shadow Buffer config Id */
typedef uint8 Com_TxShadowBufferConfigIdType;
/*! @brief Defines the type of Tx mode configuration to be used based on the ComFilter results */
typedef uint8 Com_TxIpduTxModeType;

/*! @brief Defines the type for Tx group signal Id */
typedef uint8 Com_TxGroupSignalIdType;
/*! @brief Defines the type for Tx signal filter id */
typedef uint8 Com_TxSignalFilterIdType;
/*! @brief Defines the type for Tx invalid data buffer id */
typedef uint8 Com_TxInvalidDataBufferIdType;
/*! @brief Defines the type of the Tx signal UB props Id */
typedef uint8 Com_TxSignalUBPropsIdType;
/*! @brief Defines the type of the Tx signal group UB props Id */
typedef uint8 Com_TxSignalGroupUBPropsIdType;
/*! @brief Defines the type of the Rx signal group Array UB props Id */
typedef uint8 Com_TxSignalGroupArrayUBPropsIdType;
/*! @brief Defines if a write access to this signal can trigger the transmission of the corresponding I-PDU.
 If the I-PDU is triggered, depends also on the transmission mode of the corresponding I-PDU.*/
typedef uint8 Com_SignalTransferPropertyType;
#if(COM_TX_SIGNAL_ACK_CALLBACK_SUPPORT == STD_ON)
/*! @brief Defines the function type of signal Tx ACK callout.
 It is called immediately after successful transmission of the I-PDU containing the message */
typedef P2FUNC(void,COM_APPL_CODE,Com_CbkTxAckFunctType)(void);
/*! @brief Defines the type for the Tx Ack callout function Id */
typedef uint16 Com_CbkTxAckFunctIdType;
#endif
#if(COM_TX_SIGNAL_ERROR_CALLBACK_SUPPORT == STD_ON)
/*! @brief It is called in case the transmission is not possible because the corresponding I-PDU group is stopped */
typedef P2FUNC(void,COM_APPL_CODE,Com_CbkTxErrFunctType)(void);
/*! @brief Defines the type for the Tx error callout function Id */
typedef uint16 Com_CbkTxErrFunctIdType;
#endif
#if(COM_TX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT == STD_ON)
/*! @brief This callback corresponds to notification class 4 of [17]. It is called immediately after a 
    message transmission error has been detected by the deadline monitoring mechanism. */
typedef P2FUNC(void,COM_APPL_CODE,Com_CbkTxToutFunctType)(void);
/*! @brief Defines the type for the Tx timeout callout function Id */
typedef uint16 Com_CbkTxToutFunctIdType;
#endif
/*! @brief defines whether this group signal shall contribute to the TRIGGE-RED_ON_CHANGE transfer
 property of the signal group. If at least one group signal of a signal group has the
 "ComTransferProperty" configured all other group signals of that signal group shall have
 the attribute configured as well. */
typedef uint8 Com_GroupSignalTransferPropertyType;

/*! @brief Defines the type for Rx ipdu buffer id */
typedef uint8 Com_RxIpduBufferIdType;
/*! @brief Defines the type for Rx Rte buffer Id */
typedef uint8 Com_RxRteBufferIdType;
/*! @brief Defines the type for Rx Rte shadow buffer id  */
typedef uint8 Com_RxRteShadowBufferIdType;
/*! @brief Defines the type for Rx signal group array buffer id */
#if(COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*! @brief Defines the type for the Rx I-PDU Timeout counter Id */
typedef uint8 Com_RxIpduTimeoutCounterIdType;
#endif
#if (COM_RX_IPDU_CALLOUT_SUPPORT == STD_ON)
/*! @brief Defines the function type for the RTX I-PDU callout */
typedef P2FUNC(boolean,COM_APPL_CODE,Com_RxIpduCalloutFunctType)(PduIdType PduId, const PduInfoType* PduInfoPtr);
/*! @brief Defines the type for the RX I-PDU callout function Id*/
typedef uint8 Com_RxIpduCalloutFunctIdType;
#endif
#if (COM_RX_IPDU_REPLICATION_SUPPORT == STD_ON)
/*! @brief Defines the type of the RX I-PDU replication configuration Id */
typedef uint8 Com_RxIpduReplicationIdType;
#endif
/*! @brief Defines the type of Rx Tp I-PDU Buffer Id */
typedef uint16 Com_RxTpIpduBufferIdType;
/*! @brief Defines the type of Rx Tp callback function ptr */
typedef P2FUNC(void,COM_APPL_CODE,Com_RxTpcbkFuncConfigType)
(
    P2VAR(uint8,AUTOMATIC,COM_APPL_DATA) PduDataPtr,
    uint8 Length
);
typedef uint8 Com_RxSignalGroupArrayBufferIdType;
/*! @brief Defines the type for Rx signal Tout Id */
typedef uint8 Com_RxSigToutIdType;
/*! @brief Defines the type for Rx signal Group Tout */
typedef uint8 Com_RxSigGroupToutIdType;
#if(COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*! @brief Defines the type for the Rx Signal Timeout counter Id */
typedef uint8 Com_RxSigTimeoutCounterIdType;
#endif
#if(COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*! @brief Defines the type for the Rx signal group Timeout counter Id */
typedef uint8 Com_RxSigGroupTimeoutCounterIdType;
#endif
/*! @brief Defines the type of the Rx signal UB props Id */
typedef uint8 Com_RxSignalUBPropsIdType;
/*! @brief Defines the type of the Rx signal group UB props Id */
typedef uint8 Com_RxSignalGroupUBPropsIdType;
/*! @brief Defines the type of the Rx signal group Array UB props Id */
typedef uint8 Com_RxSignalGroupArrayUBPropsIdType;
/*! @brief Defines the action performed upon expiration of the reception dead-line monitoring timer */
typedef uint8 Com_RxDataTimeoutActionType;
/*! @brief Defines the action performed upon reception if invalid signal is received. */
typedef uint8 Com_DataInvalidActionType;
/*! @brief Defines the type for Rx signal COM filter ID. */
typedef uint32 Com_RxSignalFilterIdType;
#if(COM_RX_SIGNAL_ACK_CALLBACK_SUPPORT == STD_ON)
/*! @brief Defines the type for the Rx Ack function
 It is called immediately after the message has been stored in the receiving message object */
typedef P2FUNC(void,COM_APPL_CODE,Com_CbkRxAckFunctType)(void);
/*! @brief Defines the type for Rx Ack function ID. */
typedef uint16 Com_CbkRxAckFunctIdType;
#endif
#if(COM_RX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT == STD_ON)
/*! @brief Defines the type for the Rx Timeout function
 It is called immediately after a message reception error has been detected by the deadline monitoring mechanism. */
typedef P2FUNC(void,COM_APPL_CODE,Com_CbkRxToutFunctType)(void);
/*! @brief Defines the type for Rx Timeout function ID. */
typedef uint16 Com_CbkRxToutFunctIdType;
#endif
#if(COM_RX_SIGNAL_INVALID_CALLBACK_SUPPORT == STD_ON)
/*! @brief Defines the type for the Rx Invalid function.
 It is called after reception of an invalid signal or signal group respectively */
typedef P2FUNC(void,COM_APPL_CODE,Com_CbkRxInvFunctType)(void);
/*! @brief Defines the type for Rx Invalid function ID. */
typedef uint16 Com_CbkRxInvFunctIdType;
#endif
/*! @brief Defines the type of Rx signal timeout counter configuration ID */
typedef uint16 Com_SignalRxTimeoutCounterConfigIdType;
/*! Defines the type for Rx shadow buffer config Id */
typedef uint16 Com_RxShadowBufferConfigIdType;

#if (COM_SIGNAL_GATEWAY_SUPPORT == STD_ON)
/*! @brief Defines the type of the gateway configuration Id */
typedef uint16 Com_GwDestinationConfigIdType ;
/*! Defines the type of gateway signal reference */
typedef uint8 Com_GatewayRefType;
/*! Defines the type for the gateway Destination signal Description config ID*/
typedef uint16 Com_GatewayDestSignalIdType;
/*! Defines the type for the gateway source signal Description config ID*/
typedef uint16 Com_GatewaySourceSignalIdType;
#endif

/********************************************************************************************************************
*                                       #! Structure and Enum declration                                            *
********************************************************************************************************************/
/*! @brief Defines the I-PDU to I-PDU Group vector mapping IpduGroupVectorInfo contains Com_IpduGroupVector array for 
each IpduGroup and in that Com_IpduGroupVector the current GroupId is set along with the parent group */
typedef struct
{
    /*! @brief Defines the I-PDU group bit mask for the I-PDU */
    Com_IpduGroupVector IpduGroupVectorMap;
}Com_IpduToIpduGroupMapConfigType;

/*! @brief Defines the type for the Update Bit(UB) configuration */
typedef struct
{
    /*! @brief Defines the Update Bit(UB) bit position in the buffer.*/
    uint8               UBBitPosition;
    /*! @brief Defines the Update Bit(UB) byte position in the buffer.*/
    Com_BufferSizeType  UBBytePosition;
}Com_UBPropsType;

/*! @brief Defines the type for the configuration of Com Signal Filter */
typedef struct
{
    /*! @brief Defines the type of Com signal filter algorithm used .*/
    Com_FilterAlgorithmType     FilterAlgorithmType;
    /*! @brief Defines the filter mask buffer Id */
    Com_FilterMaskBufferIdType  FilterMaskBufferId;
    /*! @brief Defines the filter max value buffer Id */
    Com_FilterMaxBufferIdType   FilterMaxBufferId;
    /*! @brief Defines the filter min value buffer Id */
    Com_FilterMinBufferIdType   FilterMinBufferId;
    /*! @brief Defines the filter X value buffer Id */
    Com_FilterXBufferIdType     FilterXBufferId;
    /*! @brief Defines the offset value for the algorithm COM_FILTER_ALGORITHM_TYPE_ONE_EVERY_N */
    uint32                      FilterOffset;
    /*! @brief Defines the period value for the algorithm COM_FILTER_ALGORITHM_TYPE_ONE_EVERY_N */
    uint32                      FilterPeriod;
}Com_FilterConfigType;

#if ((COM_TX_IPDU_COUNTER_SUPPORT == STD_ON) || (COM_RX_IPDU_COUNTER_SUPPORT == STD_ON))
/*! @brief Defines the configuration of COM I-PDU counter */
typedef struct
{
    /*! @brief Defines the Size of I-PDU Counter expressed in bits */
    uint8   IpduCounterSize;
    /*! @brief Defines the threshold value of the I-PDU Counter */
    uint8   IpduCounterThreshold;
    /*! @brief Defines the position of I-PDU counter expressed in bits from start position of data content
    of I-PDU (SDU). Note that PDU counter is not allowed to cross a byte border.
    The parameter ComIPduCounterStartPosition shall define the bit0 of the first byte
    like in little endian byte order*/
    uint32  IpduCounterStartPosition;
    /*! @brief Defines the function for the I-PDU counter error notification */
    Com_ComIpduCounterErrorNotificationFunctType ComIpduCounterErrorNotificationFunctPtr;
}Com_IpduCounterConfigType;
#endif

/*! @brief Defines the type for the configuration of Tx I-PDU */
typedef struct
{
    /*! @brief Defines when the update-bits of signals or signal groups, contained in this I-PDU,
    will be cleared. */
    Com_TxIpduClearUpdateBitType                TxIpduClearUpdateBitType;
    /*! @brief Defines if this I-PDU is a normal I-PDU that can be sent unfragmented or
    if this is a large I-PDU that shall be sent via the Transport Protocol of the underlying bus. */
    Com_IpduType                                IpduType;
    /*! @brief Defines the method of processing the I-PDU as immediate or deferred */
    Com_IpduSignalProcessingType                IpduSignalProcessingType;
    /*! @brief Defines the signal start id which belongs to this I-PDU */
    Com_SignalIdType                            SignalStartId;
    /*! @brief Defines the signal end id which belongs to this I-PDU */
    Com_SignalIdType                            SignalEndId;
#if (COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION == STD_ON)
    /*! @brief Defines the Minimum Delay Time (MDT) between successive transmissions of this I-PDU
    in milliseconds */
    uint32                                      MinimumDelayTime;
#endif
#if (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON)
    /*! @brief Defines the length of the deadline monitoring timeout period in milliseconds .
    The timeout value must be minimum of the Signal Tx timeouts */
    uint32                                      TxTimeoutValue;
    /*! @brief Defines the length of the first deadline monitoring timeout period in milliseconds.
    This timeout is used immediately after start (or restart) of the Ipdu Group */
    uint32                                      FirstTimeout;
#endif
    /*! @brief Defines the PDU ID which used for transmission request to the lower layer*/
    PduIdType                                   TargetIpduId;
#if(COM_TX_TP_IPDU_SUPPORT == STD_ON)
    /*! @brief Defines the PDU ID which used for Tp Config Id*/
    Com_TxTpConfigId                            TpConfigId;
#endif
    /*! @brief Defines the periodic counter ID for the I-PDU */
    Com_TxIpduPeriodicCounterIdType             TxPeriodicCounterId;
#if (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON)
    /*! @brief Defines the Tx timeout counter ID for the I-PDU */
    Com_TxIpduTimeoutCounterIdType              TxTimeoutCounterId;
#endif
#if(COM_TX_SIGNAL_GROUP_SUPPORT == STD_ON)
    /*! @brief Defines the signal group start id which belongs to this I-PDU */
    Com_SignalGroupIdType                       SignalGroupStartId;
    /*! @brief Defines the signal group end id which belongs to this I-PDU */
    Com_SignalGroupIdType                       SignalGroupEndId;
#endif
#if(COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON)
    /*! @brief Defines the Tx signal filter start id which belongs to this I-PDU */
    Com_TxSignalFilterIdType                    SignalFilterStartId;
    /*! @brief Defines the Tx signal filter end id which belongs to this I-PDU */
    Com_TxSignalFilterIdType                    SignalFilterEndId;
#endif
#if(COM_TX_IPDU_CANCELLATION_SUPPORT == STD_ON)
    /*! @brief Defines whether the I-PDU transmit cancellation is supported */
    boolean                                     IpduCancellationSupport;
#endif
#if(COM_TX_IPDU_CALLOUT_SUPPORT == STD_ON)
    /*! @brief Defines the I-PDU TX transmit callout function ID */
    Com_TxIpduCalloutFunctIdType                IpduCalloutFunctId;
#endif
#if (COM_TX_IPDU_TRIGGER_TRANSMIT_SUPPORT == STD_ON)
    /*! @brief Defines the I-PDU TX trigger transmit callout function ID */
    Com_TxIpduTriggerTransmitCalloutFunctIdType TriggerTxCalloutFunctId;
#endif
#if(COM_TX_IPDU_COUNTER_SUPPORT == STD_ON)
    /*! @brief Defines the I-PDU TX counter ID */
    Com_IpduCounterIdType                       IpduCounterId;
#endif
#if (COM_TX_PDU_NO_GROUP_SUPPORT == STD_ON)
    /*! @brief Defines whether the I-PDU has No Ipdu group */
    boolean                                     NoIpduGroupSupported;
#endif
}Com_TxIpduConfigType;

/*! @brief Defines the configuration for the transmission mode of I-PDU */
typedef struct
{
    /*! @brief Defines the type of transmission modes for the I-PDU */
    Com_TxModeModeType  TxModeModeType;
    /*! @brief Defines the number of repetitions for the transmission mode DIRECT
    and the event driven part of transmission mode MIXED. */
    uint8               RepetitionCount;
    /*! @brief Defines the repetition period in seconds of the multiple transmissions in
    case ComTxModeNumberOfRepetitions is configured greater than or equal to 1 and
    ComTxModeMode is configured to DIRECT or MIXED. In case of the mixed transmission
    mode only the event driven part is affected */
    uint32              RepetitionPeriod;
    /*! @brief Defines the period in seconds between the start of the I-PDU by Com_IpduGroupControl
    and the first transmission request in case ComTxModeMode is configured to PERIODIC
    or MIXED. In case of the mixed transmission mode only the periodic part is affected. */
    uint32              TimeOffset;
    /*! @brief Defines the repetition period in seconds of the periodic transmission re-quests in case
    ComTxModeMode is configured to PERIODIC or MIXED. In case of the mixed transmission mode
    only the periodic part is affected. */
    uint32              TimePeriod;
}Com_TxIpduTxModeConfigType;

#if (COM_TX_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*! @brief Defines the Tx timeout configuration type */
typedef struct
{
    /*! @brief Defines the Tx I-PDU Id for this timeout counter */
    PduIdType TxIpduId;
}Com_TxIpduTimeoutCounterConfigType;
#endif

/*! @brief Defines the type for the transmit I-PDU buffer configuration */
typedef struct
{
    /*! @brief Defines the start ID of the TX I-PDU buffer(uint8 array) */
    Com_TxIpduBufferIdType BufferStartId;
    /*! @brief Defines the end ID of the TX I-PDU buffer(uint8 array) */
    Com_TxIpduBufferIdType BufferEndId;
    /*! @brief Defines the minimum Tx I-PDU length */
    PduLengthType          MinimumLength;
    /*! @brief Defines the maximum Tx I-PDU length */
    PduLengthType          MaximumLength;
#if(COM_TX_IPDU_META_DATA_SUPPORT == STD_ON)
    /*! @brief Defines the Tx I-PDU meta data length */
    PduLengthType          MetaDataLength;
#endif
}Com_TxIpduBufferConfigType;

/*! @brief Defines the Tx Tp Ipdu buffer config type */
typedef struct
{
    /*! @brief defines the buffer start id of the Tp Ipdu */
    Com_TxTpBufferId    BufferStartId;
    /*! @brief defines the buffer end id of the Tp Ipdu */
    Com_TxTpBufferId    BufferEndId;
    /*! @brief defines the Tp Ipdu minimum length */
    PduLengthType       MinimumLength;
    /*! @brief defines the Tp Ipdu maximum length */
    PduLengthType       MaximumLength;
}Com_TxTpIpduBufferConfigType;

/*! @brief Defines the type for the configuration of TX signals */
typedef struct
{
    /*! @brief Defines the COM PduId to which the signal belongs */
    PduIdType                       ComPduId;
        /*! @brief This parameter defines that the respective signal's initial value shall
    be put into the respective PDU but there will not be any update of the value
    through the RTE*/
    boolean                         InitialValueOnly;
    /*! @brief Defines the endianness of the signal's network representation */
    Com_SignalEndiannessType        SignalEndiannessType;
    /*! @brief Defines the AUTOSAR type of the signal */
    Com_SignalType                  SignalType;
    /*! @brief Defines if a write access to this signal can trigger the transmission of the
    corresponding I-PDU. If the I-PDU is triggered, depends also on the transmission
    mode of the corresponding I-PDU.*/
    Com_SignalTransferPropertyType  TransferPropertyType;
    /*! @brief Defines the MS Bit position in the I-PDU data  */
    uint8                           MsBitPosition;
    /*! @brief Defines the LS Bit position in the I-PDU data */
    uint8                           LsBitPosition;
    /*! @brief Defines the MS Byte position in the I-PDU data bytes*/
    Com_BufferSizeType              MsBytePosition;
    /*! @brief Defines the LS Byte position in the I-PDU data bytes*/
    Com_BufferSizeType              LsBytePosition;
    /*! @brief Defines the Size in bits, for integer signal types .
    For ComSignalType UINT8_N and UINT8_DYN the size shall be configured
    by ComSignalLength.For ComSignalTypes FLOAT32 and FLOAT64 the size is
    already defined by the signal type and therefore may be omitted*/
    Com_BitLengthSizeType           BitSize;
    /*! @brief Defines the Size in bytes */
    PduLengthType                   ByteLength;
#if(COM_TX_SIGNAL_UB_SUPPORT == STD_ON )
    /*! @brief Defines the update-bit position for the signal in the I-PDU */
    Com_UBPropsConfigIdType         UBConfigId;
#endif
#if(COM_TX_SIGNAL_INVALIDATE_SUPPORT == STD_ON)
    /*! @brief Defines the Invalid value buffer start Id*/
    Com_SignalValueBufferIdType     InvalidDataBufferStartId;
    /*! @brief Defines the Invalid value buffer end Id*/
    Com_SignalValueBufferIdType     InvalidDataBufferEndId;
#endif
#if(COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON)
    /*! @brief Defines the signal Com filter Id */
    Com_TxSignalFilterIdType        TxFilterId;
#endif
#if(COM_TX_SIGNAL_ACK_CALLBACK_SUPPORT == STD_ON)
    /*! @brief Defines the Tx Ack callout function ID*/
    Com_CbkTxAckFunctIdType         TxAckFunctId;
#endif
#if(COM_TX_SIGNAL_ERROR_CALLBACK_SUPPORT == STD_ON)
    /*! @brief Defines the Tx Error callout function ID*/
    Com_CbkTxErrFunctIdType         TxErrFunctId;
#endif
#if(COM_TX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT == STD_ON)
    /*! @brief Defines the Tx Timeout callout function ID*/
    Com_CbkTxToutFunctIdType        TxToutFunctId;
#endif
}Com_TxSignalConfigType;

typedef struct
{
    /*! @brief Defines the start ID of the TX I-PDU buffer(uint8 array) */
    Com_TxShadowBufferIdType    BufferStartId;
    /*! @brief Defines the end ID of the TX I-PDU buffer(uint8 array) */
    Com_TxShadowBufferIdType    BufferEndId;
    /*! @brief Defines the Tx I-PDU length */
    PduLengthType               BufferLength;
}Com_TxShadowBufferConfigType;

/* Com Tx Signal Group Configuration */
#if(COM_TX_SIGNAL_GROUP_SUPPORT == STD_ON)
/*! @brief Defines the type for the configuration of Tx Signal group*/
typedef struct
{
    /*! @brief Defines the COM PduId to which the signal belongs */
    PduIdType                       ComPduId;
    /*! @brief Defines the MS Bit position in the I-PDU data MsBytePosition */
    uint8                           MsBitPosition;
    /*! @brief Defines the LS Bit position in the I-PDU data LsBytePosition*/
    uint8                           LsBitPosition;
    /*! @brief Defines the MS Byte position in the I-PDU data bytes*/
    Com_BufferSizeType              MsBytePosition;
    /*! @brief Defines the LS Byte position in the I-PDU data bytes*/
    Com_BufferSizeType              LsBytePosition;
    /*! @brief Defines the Size in bits, for integer signal types .
    For ComSignalType UINT8_N and UINT8_DYN the size shall be configured
    by ComSignalLength.For ComSignalTypes FLOAT32 and FLOAT64 the size is
    already defined by the signal type and therefore may be omitted*/
    Com_BitLengthSizeType           BitSize;
    /*! @brief Defines the Size in bytes */
    PduLengthType                   ByteLength;
    /*! @brief This parameter defines that the respective signal's initial value shall
    be put into the respective PDU but there will not be any update of the value
    through the RTE*/
#if (COM_TX_SIGNAL_GROUP_UB_SUPPORT == STD_ON)
    /*! @brief Defines the Update Bit(UB) bit position in the buffer.*/
    uint8                           UBBitPosition;
    /*! @brief Defines the Update Bit(UB) byte position in the buffer.*/
    Com_BufferSizeType              UBBytePosition;
#endif
#if(COM_TX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON)
    /*! @brief Defines the on change array mask id */
    uint8                           OnChangeBufferStartId;
#endif
    /*! @brief This parameter defines that the respective signal's initial value shall be put into the respective
        PDU but there will not be any update of the value through the RTE. Thus the Com implementation does not 
        need to expect any API calls for this signal (group). */
    boolean                         InitialValueOnly;
    /*! @brief Defines if a write access to this signal can trigger the transmission of the
    corresponding I-PDU. If the I-PDU is triggered, depends also on the transmission
    mode of the corresponding I-PDU.*/
    Com_SignalTransferPropertyType  TransferPropertyType;
    /*! @brief Defines the start id of the group signal belongs to this Signal group */
    Com_SignalIdType                GroupSignalIdStart;
    /*! @brief Defines the end id of the group signal belongs to this Signal group */
    Com_SignalIdType                GroupSignalIdStop;
    /*! @brief Defines the shadow buffer config Id  */
    Com_TxShadowBufferConfigIdType  ShadowBufferConfigId;
#if (COM_TX_SIGNAL_FILTER_SUPPORT == STD_ON)
    /*! @brief Defines the filter id for the tx shadow buffer */
    Com_TxShadowBufferConfigIdType  FilterId;
#endif
#if (COM_RX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON)
    /*! @brief Defines whether the uint8-array based access shall be used for this Com-SignalGroup. */
    boolean                         SignalGroupArrayAccess;
#endif
#if(COM_TX_SIGNAL_ACK_CALLBACK_SUPPORT == STD_ON)
    /*! @brief Defines the Tx Ack callout function ID*/
    Com_CbkTxAckFunctIdType         TxAckFunctId;
#endif
#if(COM_TX_SIGNAL_ERROR_CALLBACK_SUPPORT == STD_ON)
    /*! @brief Defines the Tx Error callout function ID*/
    Com_CbkTxErrFunctIdType         TxErrFunctId;
#endif
#if(COM_TX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT == STD_ON)
    /*! @brief Defines the Tx Timeout callout function ID*/
    Com_CbkTxToutFunctIdType        TxToutFunctId;
#endif
}Com_TxSignalGroupConfigType;
#endif

/*! @brief Defines the type for the configuration of Rx I-PDU */
typedef struct
{
    /*! @brief Defines Defines if this I-PDU is a normal I-PDU that can be sent unfragmented or
    if this is a large I-PDU that shall be sent via the Transport Protocol of the underlying bus. */
    Com_IpduType                        IpduType;
#if(COM_RX_TP_IPDU_SUPPORT == STD_ON)
    /*! @brief Defines the Tp confg id */
    PduIdType                           RxTpId;
#endif
    /*! @brief Defines the method of processing the I-PDU as immediate or deferred */
    Com_IpduSignalProcessingType        IpduSignalProcessingType;
    /*! @brief Defines the signal start id which belongs to this I-PDU */
    Com_SignalIdType                    SignalStartId;
    /*! @brief Defines the signal end id which belongs to this I-PDU */
    Com_SignalIdType                    SignalEndId;
#if(COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT == STD_ON)
    /*! @brief Defines the configuration Id for the timeout configuration */
    Com_RxIpduTimeoutCounterIdType      IpduTimeoutCounterId;
#endif
#if(COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON)
    /*! @brief Defines the start id of signal timeout config */
    Com_RxSigTimeoutCounterIdType       SigTimeoutCounterStartId;
    /*! @brief Defines the end id of signal timeout config */
    Com_RxSigTimeoutCounterIdType       SigTimeoutCounterEndId;
#endif
#if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
    /*! @brief Defines the signal group start id which belongs to this I-PDU */
    Com_SignalGroupIdType               SignalGroupStartId;
    /*! @brief Defines the signal group end id which belongs to this I-PDU */
    Com_SignalGroupIdType               SignalGroupEndId;
#if(COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON)
    /*! @brief Defines the signal group timout counter start id which belongs to this I-PDU */
    Com_RxSigGroupTimeoutCounterIdType  SigGroupTimeoutCounterStartId;
    /*! @brief Defines the signal group timout counter end id which belongs to this I-PDU */
    Com_RxSigGroupTimeoutCounterIdType  SigGroupTimeoutCounterEndId;
#endif
#endif
#if(COM_RX_IPDU_CANCELLATION_SUPPORT == STD_ON)
    /*! @brief Defines whether the I-PDU receive cancellation is supported */
    boolean                             IpduCancellationSupport;
#endif
#if(COM_RX_IPDU_CALLOUT_SUPPORT == STD_ON)
    /*! @brief Defines the RX I-PDU callout function Id*/
    Com_RxIpduCalloutFunctIdType        IpduCalloutFunctId;
#endif
#if(COM_RX_IPDU_COUNTER_SUPPORT == STD_ON)
    /*! @brief Defines the RX I-PDU counter configuration Id*/
    Com_IpduCounterIdType               IpduCounterId;
#endif
#if(COM_RX_IPDU_REPLICATION_SUPPORT == STD_ON)
    /*! @brief Defines the RX I-PDU replication configuration Id*/
    Com_RxIpduReplicationIdType         IpduReplicationId;
#endif
#if (COM_SIGNAL_GATEWAY_SUPPORT == STD_ON)
    /*! @brief Defines the gateway configuration Id start */
    Com_GwDestinationConfigIdType       GwDestinationConfigStartId;
    /*! @brief Defines the gateway configuration Id End */
    Com_GwDestinationConfigIdType       GwDestinationConfigEndId;
#endif
#if (COM_RX_PDU_NO_GROUP_SUPPORT == STD_ON)
    /*! @brief Defines whether the I-PDU has no Ipdu group */
    boolean                             NoIpduGroupSupported;
#endif
}Com_RxIpduConfigType;

/*! @brief Defines the type for the RX I-PDU buffer configuration */
typedef struct
{
    /*! @brief Defines the start ID of the RX I-PDU buffer(uint8 array) */
    Com_RxIpduBufferIdType  BufferStartId;
    /*! @brief Defines the end ID of the RX I-PDU buffer(uint8 array) */
    Com_RxIpduBufferIdType  BufferEndId;
    /*! @brief Defines the minimum PDU Length of the RX I-PDU */
    PduLengthType           MinimumLength;
    /*! @brief Defines the maximum PDU Length of the RX I-PDU */
    PduLengthType           MaximumLength;
#if(COM_RX_IPDU_META_DATA_SUPPORT == STD_ON)
    /*! @brief Defines the PDU meta data Length of the RX I-PDU */
    PduLengthType           MetaDataLength;
#endif
}Com_RxIpduBufferConfigType;

#if(COM_RX_IPDU_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*! @brief Defines the type for timeout configuration for Rx PDU*/
typedef struct
{
    /*! @brief Defines the PduId of the timeout configuration*/
    PduIdType   RxPduId;
    /*! @brief Defines the length of the first deadline monitoring timeout period in milliseconds.
    This timeout is used immediately after start (or restart) of the deadline monitoring service */
    uint32      FirstTimeout;
    /*! @brief Defines the length of the deadline monitoring timeout period in seconds */
    uint32      Timeout;
}Com_RxIpduTimeoutCounterConfigType;
#endif

/*! @brief Defines the Rx Tp Ipdu buffer config type */
typedef struct
{
/*! @brief Defines the Rx Tp Ipdu buffer start Id */
    Com_RxTpIpduBufferIdType    BufferStartId;
/*! @brief Defines the Rx Tp Ipdu buffer end Id */
    Com_RxTpIpduBufferIdType    BufferEndId;
/*! @brief Defines the Rx Tp Ipdu minimum length */
    PduLengthType               MinimumLength;
/*! @brief Defines the Rx Tp Ipdu maximum length */
    PduLengthType               MaximumLength;
}Com_RxTpIpduConfigType;

/*! @brief Defines the type for the configuration of RX signals */
typedef struct
{
    /*! @brief Defines the COM PduId to which the signal belongs */
    PduIdType                               ComPduId;
        /*! @brief This parameter defines that the respective signal's initial value shall
    be put into the respective PDU but there will not be any update of the value
    through the RTE*/
    boolean                                 InitialValueOnly;
    /*! @brief Defines the endianness of the signal's network representation */
    Com_SignalEndiannessType                SignalEndiannessType;
    /*! Defines the AUTOSAR type of the signal */
    Com_SignalType                          SignalType;
    /*! @brief Defines the action performed upon reception if invalid signal is received. */
    Com_DataInvalidActionType               DataInvalidActionType;
    /*! @brief Defines the action performed upon expiration of the reception dead-line monitoring timer */
    Com_RxDataTimeoutActionType             RxDataTimeoutActionType;
    /*! @brief Defines the MS Bit position in the I-PDU data MsBytePosition */
    uint8                                   MsBitPosition;
    /*! @brief Defines the LS Bit position in the I-PDU data LsBytePosition*/
    uint8                                   LsBitPosition;
    /*! @brief Defines the MS Byte position in the I-PDU data bytes*/
    Com_BufferSizeType                      MsBytePosition;
    /*! @brief Defines the LS Byte position in the I-PDU data bytes*/
    Com_BufferSizeType                      LsBytePosition;
    /*! @brief Defines the Size in bits, for integer signal types .
    For ComSignalType UINT8_N and UINT8_DYN the size shall be configured
    by ComSignalLength.For ComSignalTypes FLOAT32 and FLOAT64 the size is
    already defined by the signal type and therefore may be omitted*/
    Com_BitLengthSizeType                   BitSize;
    /*! @brief Defines the Size in bytes */
    PduLengthType                           ByteLength;
#if(COM_RX_SIGNAL_UB_SUPPORT == STD_ON)
    /*! @brief Defines the update-bit position for the signal in the I-PDU */
    Com_UBPropsConfigIdType                 UBConfigId;
#endif
#if(COM_RX_SIGNAL_INVALID_DATA_SUPPORT == STD_ON)
    /*! @brief Defines the Invalid value buffer end Id*/
    Com_SignalValueBufferIdType             DataInitValueBufferIdStart; 
    /*! @brief Defines the Invalid value buffer end Id*/
    Com_SignalValueBufferIdType             DataInitValueBufferIdStop;
#endif
#if(COM_RX_SIGNAL_FILTER_SUPPORT == STD_ON)
    /*! @brief Defines the signal Com filter Id */
    Com_RxSignalFilterIdType                FilterId;
#endif
#if(COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON)
    /*! @brief Defines the Rx signal timeout counter configuration ID */
    Com_SignalRxTimeoutCounterConfigIdType  RxSignalTimeoutCounterId;
#endif
#if(COM_RX_SIGNAL_ACK_CALLBACK_SUPPORT == STD_ON)
    /*! @brief Defines the Rx Ack callout function ID*/
    Com_CbkRxAckFunctIdType                 RxAckFunctId;
#endif
#if(COM_RX_SIGNAL_INVALID_CALLBACK_SUPPORT == STD_ON)
    /*! @brief Defines the Rx Invalid callout function ID*/
    Com_CbkRxInvFunctIdType                 RxInvFunctId;
#endif
#if(COM_RX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT == STD_ON)
    /*! @brief Defines the Rx Timeout callout function ID*/
    Com_CbkRxToutFunctIdType                RxToutFunctId;
#endif
#if (COM_SIGNAL_GATEWAY_SUPPORT == STD_ON)
    /*! @brief Defines the gateway configuration Id */
    Com_GwDestinationConfigIdType           GwDestinationConfigId;
#endif
    /*! @brief Defines the signal init buffer index */
    Com_RxRteBufferIdType                   InitBufferIdx;
    /*! @brief Defines the signal buffer index */
    Com_RxRteBufferIdType                   RteBufferIdx;
#if (COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
    /*! @brief Defines the signal shadow buffer index */
    Com_RxRteShadowBufferIdType             RteShadowBufferIdx;
    /*! @brief Defines whether the signal is group signal or not */
    boolean                                 IsGroupSignal ; 
#endif
}Com_RxSignalConfigType;

#if(COM_RX_SIGNAL_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*! @brief Defines the type for timeout configuration for Rx PDU*/
typedef struct
{
    /*! @brief Defines the signal id of the timeout configuration*/
    Com_SignalIdType    SignalId;
    /*! @brief Defines the length of the first deadline monitoring timeout period in milliseconds.
    This timeout is used immediately after start (or restart) of the deadline monitoring service */
    uint32              FirstTimeout;
    /*! @brief Defines the length of the deadline monitoring timeout period in seconds */
    uint32              Timeout;
}Com_RxSigTimeoutCounterConfigType;
#endif

#if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
/*! @brief Defines the type for the configuration of Rx Signal group*/
typedef struct
{
    /*! @brief Defines the COM PduId to which the signal belongs */
    PduIdType                           ComPduId;
    /*! @brief This parameter defines that the respective signal's initial value shall
    be put into the respective PDU but there will not be any update of the value
    through the RTE*/
    boolean                             InitialValueOnly;
    /*! @brief This parameter defines the action performed upon reception of an invalid signal.
    Relating to signal groups the action in case if one of the included signals is an invalid signal.
    If Replace is used the ComSignalInitValue will be used for the re-placement. */
    Com_DataInvalidActionType           DataInvalidActionType;
    /*! @brief This parameter defines the action performed upon expiration of the reception dead-line
    monitoring timer. */
    Com_RxDataTimeoutActionType         RxDataTimeoutActionType;
    /*! @brief Defines the MS Bit position in the I-PDU data MsBytePosition */
    uint8                               MsBitPosition;
    /*! @brief Defines the LS Bit position in the I-PDU data LsBytePosition*/
    uint8                               LsBitPosition;
    /*! @brief Defines the MS Byte position in the I-PDU data bytes*/
    Com_BufferSizeType                  MsBytePosition;
    /*! @brief Defines the LS Byte position in the I-PDU data bytes*/
    Com_BufferSizeType                  LsBytePosition;
    /*! @brief Defines the Size in bits, for integer signal types .
    For ComSignalType UINT8_N and UINT8_DYN the size shall be configured
    by ComSignalLength.For ComSignalTypes FLOAT32 and FLOAT64 the size is
    already defined by the signal type and therefore may be omitted*/
    Com_BitLengthSizeType               BitSize;
    /*! @brief Defines the Size in bytes */
    PduLengthType                       ByteLength;
#if (COM_RX_SIGNAL_GROUP_ARRAY_SUPPORT == STD_ON)
    /*! @brief Defines whether the uint8-array based access shall be used for this Com-SignalGroup. */
    boolean                             SignalGroupArrayAccess;
    /*! @brief Defines the signal Group Arraybuffer index */
    uint16                              SignalGroupArrayBufferIdx;
#endif
#if (COM_RX_SIGNAL_GROUP_UB_SUPPORT == STD_ON)
    /*! @brief Defines the update-bit position for the signal in the I-PDU */
    Com_UBPropsConfigIdType             UBConfigId;
#endif
#if (COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON)
    /*! @brief Defines the Rx signal group timeout counter config Id */
    Com_RxSigGroupTimeoutCounterIdType  RxSigGroupTimeoutCounterId;
#endif
    /*! @brief Defines the start id of the group signal belongs to this Signal group */
    Com_SignalIdType                    GroupSignalStartId;
    /*! @brief Defines the end id of the group signal belongs to this Signal group */
    Com_SignalIdType                    GroupSignalEndId;
#if(COM_RX_SIGNAL_ACK_CALLBACK_SUPPORT == STD_ON)
    /*! @brief Defines the Rx Ack callout function ID*/
    Com_CbkRxAckFunctIdType             RxAckFunctId;
#endif
#if(COM_RX_SIGNAL_INVALID_CALLBACK_SUPPORT == STD_ON)
    /*! @brief Defines the Rx Invalid callout function ID*/
    Com_CbkRxInvFunctIdType             RxInvFunctId;
#endif
#if(COM_RX_SIGNAL_TIMEOUT_CALLBACK_SUPPORT == STD_ON)
    /*! @brief Defines the Rx Timeout callout function ID*/
    Com_CbkRxToutFunctIdType            RxToutFunctId;
#endif
#if (COM_SIGNAL_GATEWAY_SUPPORT == STD_ON)
    /*! @brief Defines the gateway configuration Id */
    Com_GwDestinationConfigIdType       GwDestinationConfigId;
#endif
}Com_RxSignalGroupConfigType;

#if(COM_RX_SIGNAL_GROUP_TIMEOUT_COUNTER_SUPPORT == STD_ON)
/*! @brief Defines the type for timeout configuration for Rx PDU*/
typedef struct
{
    /*! @brief Defines the PduId of the timeout configuration*/
    Com_SignalGroupIdType   SignalGroupId;
    /*! @brief Defines the length of the first deadline monitoring timeout period in milliseconds.
    This timeout is used immediately after start (or restart) of the deadline monitoring service */
    uint32                  FirstTimeout;
    /*! @brief Defines the length of the deadline monitoring timeout period in seconds */
    uint32                  Timeout;
}Com_RxSigGroupTimeoutCounterConfigType;
#endif

#endif

#if (COM_RX_IPDU_REPLICATION_SUPPORT == STD_ON)
/*! @brief Defines the type for the RX I-PDU replication configuration */
typedef struct
{
    /*! @brief Defines the number of identical I-PDUs needed for successful voting. */
    uint8       IpduReplicationQuorum;
    /*! @brief Defines the RX I-PDU Id of the Replication I-PDU 1. */
    PduIdType   PduReplicationPduRef1;
    /*! @brief Defines the RX I-PDU Id of the Replication I-PDU 2. */
    PduIdType   PduReplicationPduRef2;
    /*! @brief Defines the RX I-PDU Id of the Replication I-PDU 3. */
    PduIdType   PduReplicationPduRef3;
}Com_IPduReplicationConfigType;
#endif

/* Com Signal Gateway configuration */
#if (COM_SIGNAL_GATEWAY_SUPPORT == STD_ON)
/*! @brief Defines the type for the configuration of Gateway destination signal description */
typedef struct
{
    /*! @brief Defines the MS Bit position in the I-PDU data MsBytePosition */
    uint8                           MsBitPosition;
    /*! @brief Defines the LS Bit position in the I-PDU data LsBytePosition*/
    uint8                           LsBitPosition;
    /*! @brief Defines the LS Byte position in the I-PDU data */
    Com_BufferSizeType              MsBytePosition;
    /*! @brief Defines the MS Byte position in the I-PDU data */
    Com_BufferSizeType              LsBytePosition;
    /*! @brief Defines the Update Bit(UB) bit position in the buffer.*/
    uint8                           UBBitPosition;
    /*! @brief Defines the Update Bit(UB) byte position in the buffer.*/
    Com_BufferSizeType              UBBytePosition;;
    /*! @brief Defines the Com destination I-PDU Id */
    PduIdType                       DestIPduId;
    /*! @brief Defines the endianness of the signal's network representation */
    Com_SignalEndiannessType        SignalEndiannessType;
    /*! @brief Defines if a write access to this signal can trigger the transmission of the
    corresponding I-PDU. If the I-PDU is triggered, depends also on the transmission
    mode of the corresponding I-PDU.*/
    Com_SignalTransferPropertyType  TransferPropertyType;
    /*! @brief Defines the Init value buffer start Id*/
    Com_SignalValueBufferIdType     DataInitValueBufferIdStart;
    /*! @brief Defines the Init value buffer end Id*/
    Com_SignalValueBufferIdType     DataInitValueBufferIdStop;
    /*! @brief Defines the signal Com filter Id */
    Com_SignalTxFilterIdType        TxFilterId;
}Com_GatewayDestSignalConfigType;

/*! @brief Defines the type for the configuration of Gateway source signal description */
typedef struct
{
    /*! @brief Defines the endianness of the signal's network representation */
    Com_SignalEndiannessType    SignalEndiannessType;
    /*! @brief Defines the AUTOSAR type of the signal */
    Com_SignalType              SignalType;
    /*! @brief Defines the MS Bit position in the I-PDU data MsBytePosition */
    uint8                       MsBitPosition;
    /*! @brief Defines the LS Bit position in the I-PDU data LsBytePosition*/
    uint8                       LsBitPosition;
    /*! @brief Defines the MS Byte position in the I-PDU data */
    Com_BufferSizeType          MsBytePosition;
    /*! @brief Defines the LS Byte position in the I-PDU data */
    Com_BufferSizeType          LsBytePosition;
    /*! @brief Defines the Size in bits, for integer signal types .
    For ComSignalType UINT8_N and UINT8_DYN the size shall be configured
    by ComSignalLength.For ComSignalTypes FLOAT32 and FLOAT64 the size is
    already defined by the signal type and therefore may be omitted*/
    Com_BitLengthSizeType       BitSize;
    /*! @brief Defines the Size in bytes */
    PduLengthType               ByteLength;
    /*! @brief Defines the Update Bit(UB) bit position in the buffer.*/
    uint8                       UBBitPosition;
    /*! @brief Defines the Update Bit(UB) byte position in the buffer.*/
    Com_BufferSizeType          UBBytePosition;
    /*! @brief Defines the Com source I-PDU Id */
    PduIdType                   SourceIPduId;
}Com_GatewaySourceSignalConfigType;

/*! @brief Defines the type for the configuration of Com Signal Gateway Destination */
typedef struct
{
    /*! Defines the type of gateway signal reference */
    Com_GatewayRefType           DestGatewayRefType;
    /*! Defines the signal Id if the gateway reference type is COM_GATEWAY_REF_TYPE_SIGNAL_ID*/
    Com_SignalIdType             DestSignalId;
    /*! Defines the description Id if the gateway reference type is COM_GATEWAY_REF_TYPE_SIGNAL_DESCRIPTION*/
    Com_GatewayDestSignalIdType  GatewayDestSignalId;
}Com_GwDestinationType;

/*! @brief Defines the type for the configuration of Com Signal Gateway source */
typedef struct
{
    /*! Defines the type of gateway signal reference */
    Com_GatewayRefType               SrcGatewayRefType;
    /*! Defines the signal Id if the gateway reference type is COM_GATEWAY_REF_TYPE_SIGNAL_ID*/
    Com_SignalIdType                 SrcSignalId;
    /*! Defines the description Id if the gateway reference type is COM_GATEWAY_REF_TYPE_SIGNAL_DESCRIPTION*/
    Com_GatewaySourceSignalIdType    GatewaySourceSignalId;
}ComGwSourceType;

/*! @brief Defines the type for the Gateway configuration.
 TODO: Gateway configuration needs to be updated*/
typedef struct
{
    /*! @brief Defines the configuration of Com Signal Gateway source */
    ComGwSourceType         ComGwSourceConfig;
    /*! @brief Defines the configuration of Com Signal Gateway destination */
    Com_GwDestinationType   ComGwDestinationConfig;
}Com_GwDestinationConfigType;
#endif

#endif /* COM_CFG_H */


/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

