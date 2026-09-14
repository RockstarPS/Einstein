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
/*!******************************************************************************************************************
*   @file Xcp.h
*   @ingroup Xcp
*   @brief This file provides the declaration of the Xcp API. This header file should be included by other
*   modules that use the Xcp API.
*   @defgroup Xcp
*   @brief The XCP is a protocol description (ASAM standard) between a master (tool) and a slave (device), which 
*   provides the following basic features:
*   - Synchronous data acquisition (measurement)
*   - Synchronous data acquisition (measurement)
*   - Synchronous data stimulation (for rapid prototyping)
*   - Online memory calibration (read / write access)
*   - Calibration data page initialization and switching
*   - Flash Programming for ECU development purposes
*   - Every feature is optional and the access can be restricted
*   - Various communications busses are supported
********************************************************************************************************************/
#ifndef XCP_H 
#define XCP_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "Xcp_Types.h"
#include "Xcp_Cfg.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the Xcp SW major version */
#define XCP_SW_MAJOR_VERSION                               1u
/*! @brief Defines the Xcp SW minor version */
#define XCP_SW_MINOR_VERSION                               0u
/*! @brief Defines the Xcp SW patch version */
#define XCP_SW_PATCH_VERSION                               0u
/* Autosar Release */
/*! @brief Defines the Xcp AUTOSAR major version */
#define XCP_AR_RELEASE_MAJOR_VERSION                       4u
/*! @brief Defines the Xcp AUTOSAR minor version */
#define XCP_AR_RELEASE_MINOR_VERSION                       3u
/*! @brief Defines the Xcp AUTOSAR patch version */
#define XCP_AR_RELEASE_REVISION_VERSION                    1u
/********************************************************************************************************************
*  MODULE INFORMATION                                                                                               *
********************************************************************************************************************/ 
/*! @brief Defines the Vendor Id of Xcp module. */
#define XCP_VENDOR_ID                                      0x0033u
/*! @brief Defines the Module Id of Xcp module.*/
#define XCP_MODULE_ID                                      212U
/*! @brief Defines the version Id of Xcp module.*/
#define XCP_INSTANCE_ID                                    0u
/********************************************************************************************************************
*  API Id                                                                                                           *
********************************************************************************************************************/
/*! @brief Defines the service Id for Xcp_Init Api */
#define XCP_INIT_API                0x00U
/*! @brief Defines the service Id for Xcp_GetVersionInfo Api */
#define XCP_GETVERSIONINFO_API      0x01U
/*! @brief Defines the service Id for Xcp_MainFunction Api */
#define XCP_MAINFUNCTION_API        0x02U
/*! @brief Defines the service Id for Xcp_SetTransmission Api */
#define XCP_SETTRANSMISSION_MODE    0x05U
/*! @brief Defines the service Id for Xcp_TlTxConfirmation Api */
#define XCP_TLTXCONFIRMATION_API    0x40U
/*! @brief Defines the service Id for Xcp_TlTriggerTransmit Api */
#define XCP_TLTRIGGERTRANSMIT_API   0x41U
/*! @brief Defines the service Id for Xcp_TlRxIndication Api */
#define XCP_TLRXINDICATION_API      0x42U
/*! @brief Defines the service Id for Xcp_TlDisconnect Api */
#define XCP_DISCONNECT_API          0x03U
/*! @brief Defines the service Id for Xcp_SendCrm Api */
#define XCP_SENDCRM_API             0x04U
/*! @brief Defines the service Id for Xcp_SetACtiveTl Api */
#define XCP_SETACTIVETL_API         0x05U
/*! @brief Defines the service Id for Xcp_GetACtiveTl Api */
#define XCP_GETACTIVETL_API         0x06U
/*! @brief Defines the service Id for Xcp_Event Api */
#define XCP_EVENT_API               0x07U
/*! @brief Defines the service Id for Xcp_SendEvent Api */
#define XCP_SENDEVENT_API           0x09U
/********************************************************************************************************************
*  DEVELOPMENT ERRORS VALUES                                                                                        *
********************************************************************************************************************/
/*! @brief API service called with Module not initialized */
#define XCP_E_UNINIT                                       0x02u
/*! @brief API service called when Initialization of XCP failed */
#define XCP_E_INIT_FAILED                                  0x04u
/*! @brief API service called with Null pointer has been passed as an argument */
#define XCP_E_PARAM_POINTER                                0x12u
/*! @brief API service called with API call with wrong PDU ID */
#define XCP_E_INVALID_PDUID                                0x03u
/*! @brief API service called with API call with invalid parameter */
#define XCP_E_INVALID_PARAM                                0xFEu
/*! @brief Defines No error id  */
#define XCP_E_NO_ERROR                                     255u
/********************************************************************************************************************
*  Module Macros                                                                                                    *
********************************************************************************************************************/
#ifndef XCP_LOCAL 
#define XCP_LOCAL  static
#endif

#ifndef LOCAL_INLINE
#define LOCAL_INLINE    static inline
#endif

#ifndef XCP_LOCAL_INLINE
#define XCP_LOCAL_INLINE  LOCAL_INLINE
#endif
/********************************************************************************************************************
*  PUBLIC TYPES                                                                                                     *
********************************************************************************************************************/

/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief      This service initializes interfaces and variables of the AUTOSAR XCP layer.
*   @param[in]  Xcp_ConfigPtr Pointer to the configuration data of the Xcp module
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_Init(P2CONST(Xcp_ConfigType, AUTOMATIC, XCP_APPL_CONST) Xcp_ConfigPtr);
/*!******************************************************************************************************************
*   @brief      Returns the version information.
*   @param[out] versioninfo  Pointer to where to store the version information of this module
*   @ServiceID  0x02
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, XCP_APPL_CONST) versioninfo );
/*!******************************************************************************************************************
*   @brief      This API is used to turn on and off of the TX capabilities of used communication bus channel in XCP 
*               module
*   @param[in]  Channel The Network channel for the used bus communication
*   @param[in]  Mode Enabled or disabled Transmission mode Parameters
*   @ServiceID  0x05
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_SetTransmissionMode( NetworkHandleType Channel, Xcp_TransmissionModeType Mode );
/*!******************************************************************************************************************
*   @brief      Indication of a received PDU from a lower layer communication interface module.
*   @param[in]  XcpChannel Xcp channel Idx
*   @param[in]  CmdPtr pointer to the command buffer 
*   @ServiceID  0x42
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_TlRxIndication( Xcp_ChannelType XcpChannel, P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) CmdPtr );
/*!******************************************************************************************************************
*   @brief      Indication of a tramsision for PDU from a lower layer communication interface module.
*   @param[in]  XcpChannel Xcp channel Idx
*   @ServiceID  0x40
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_TlTxConfirmation( Xcp_ChannelType XcpChannel );
/*!******************************************************************************************************************
*   @brief      Scheduled function of the XCP module
*   @ServiceID  0x40
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_MainFunction( void );
/*!******************************************************************************************************************
*   @brief      This API is used to set the active TL and its properties for this channel .
*   @param[in]  XcpChannel Xcp channel Idx
*   @param[in]  XcpChannel MaxCto Maximum supported CTO length in bytes 
*   @param[in]  XcpChannel MaxDto Maximum supported Dto length in bytes
*   @param[in]  XcpChannel ActiveTl active tl idx 
*   @ServiceID  0x4
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_SetActiveTl( Xcp_ChannelType XcpChannel, uint8 MaxCto, uint16 MaxDto, uint8 ActiveTl );
/*!******************************************************************************************************************
*   @brief      This API is used to get the active TL for this channel.
*   @param[in]  XcpChannel Xcp channel Idx
*   @return  XcpChannel ActiveTl active tl idx 
********************************************************************************************************************/
FUNC(uint8, XCP_CODE) Xcp_GetActiveTl( Xcp_ChannelType XcpChannel );
/*!******************************************************************************************************************
*   @brief      This API is used to disconnect the Xcp.
*   @param[in]  XcpChannel Xcp channel Idx
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_Disconnect( Xcp_ChannelType XcpChannel );
/*!******************************************************************************************************************
* @brief  This Api used to process the event channel
* @param[in] EventChannel pointer to destination buffer data
* @return Event processing status
********************************************************************************************************************/
FUNC(uint8, XCP_CODE) Xcp_Event( uint16 EventChannel );
/*!******************************************************************************************************************
* @brief  This Api used to set the STIM mode 
* @param[in] Mode STIM mode to be set 0: XCP_STIM_SINGLE_SHOT_MODE, 1: XCP_STIM_CONTINUOUS_MODE
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_SetStimMode(uint8 Mode);
/*!******************************************************************************************************************
* @brief  This Api used to set the STIM event status for the event channel
* @param[in] EventChannel Event channel idx
* @param[in] Action event value . 0: XCP_STIM_CHECK_ODT_BUFFER, 1: XCP_STIM_RESET_ODT_BUFFER
* @return Returns the stim event status 
********************************************************************************************************************/
FUNC(uint8, XCP_CODE) Xcp_StimEventStatus( uint16 EventChannel, uint8 Action );
/*!******************************************************************************************************************
*   @brief      This API is used update the protection status .
*   @param[in]  XcpChannel Xcp channel Idx
*   @param[in]  ResourceValBitMask resource value mask bit
*   @param[in]  SetClear set/clear the status. 0- set the status . 1- clear the status
*   @return  returns the status of the protection register
********************************************************************************************************************/
FUNC(uint8, XCP_CODE) Xcp_ModifyProtectionStatus
(
    Xcp_ChannelType XcpChannel,
    uint8 ResourceValBitMask,
    boolean SetClear 
);
/********************************************************************************************************************
* @brief  This Api used to set requested data to the destination buffer
* @param[out] DestPtr pointer to destination buffer data
* @param[in] Value value to be set
* @param[in] Length byte size to be set
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_UtilMemSet
(   
    P2VAR(uint8,AUTOMATIC,XCP_APPL_DATA) DestPtr , 
    uint8 Value , 
    PduLengthType Length
);
/********************************************************************************************************************
*   @brief     This service used to copy data from source buffer to destination buffer
*   @param[in] DestPtr pointer to destination buffer data
*   @param[in] SrcPtr pointer to source buffer data
*   @param[in] Length byte size to be copied
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_UtilMemCopy
(
    P2VAR(uint8,AUTOMATIC,XCP_APPL_DATA) DestPtr , 
    CONSTP2CONST(uint8,AUTOMATIC,XCP_APPL_CONST) SrcPtr , 
    PduLengthType Length
);
/********************************************************************************************************************
*   @brief     This service used to update the protection status for the XCP resources 
*   @param[in] XcpChannel Xcp channel id
*   @param[in] ResourceValBitMask resource bit mask value. 
*   @param[in] SetClear FALSE - Clear the bit mask , TRUE - Set the bit mask.
*   @return returns the current protection resource value bit mask.
********************************************************************************************************************/
FUNC(uint8, XCP_CODE) Xcp_ModifyProtectionStatus
(
    Xcp_ChannelType XcpChannel,
    uint8 ResourceValBitMask,
    boolean SetClear 
);
/*!******************************************************************************************************************
* @brief  This Api used to process the transmission of event data for the xcp channel
* @param[in] XcpChannel xcp channel idx
* @param[in] EventCode event code value
* @param[in] EventData pointer to the event data buffer
* @param[in] Length Length of the event data
********************************************************************************************************************/
#if(XCP_SEND_EVENT == STD_ON)
FUNC(void, XCP_CODE) Xcp_SendEvent
(
    Xcp_ChannelType XcpChannel,
    uint8 EventCode,
    P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) EventData,
    uint8 Length 
);
#endif
#define XCP_STOP_SEC_CODE
#include "MemMap.h"
#endif /* XCP_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/