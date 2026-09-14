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
*   @file XcpOnCan.h
*   @ingroup XcpOnCan
*   @brief This file provides the declaration of the XcpOnCan API. This header file should be included by other
*   modules that use the XcpOnCan API.
*   @defgroup XcpOnCan
*   @brief The XcpOnCan module is responsible for providing the CAN transport layer interface for the 
*   Xcp module.
********************************************************************************************************************/
#ifndef XCPONCAN_H
#define XCPONCAN_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "XcpOnCan_Types.h"
#include "XcpOnCan_Cfg.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the XcpOnCan SW major version */
#define XCPONCAN_SW_MAJOR_VERSION                               1u
/*! @brief Defines the XcpOnCan SW minor version */
#define XCPONCAN_SW_MINOR_VERSION                               0u
/*! @brief Defines the XcpOnCan SW patch version */
#define XCPONCAN_SW_PATCH_VERSION                               0u
/* Autosar Release */
/*! @brief Defines the XcpOnCan AUTOSAR major version */
#define XCPONCAN_AR_RELEASE_MAJOR_VERSION                       4u
/*! @brief Defines the XcpOnCan AUTOSAR minor version */
#define XCPONCAN_AR_RELEASE_MINOR_VERSION                       3u
/*! @brief Defines the XcpOnCan AUTOSAR patch version */
#define XCPONCAN_AR_RELEASE_REVISION_VERSION                    1u
/********************************************************************************************************************
*  MODULE INFORMATION                                                                                               *
********************************************************************************************************************/ 
/*! @brief Defines the Vendor Id of XcpOnCan module. */
#define XCPONCAN_VENDOR_ID                                      0x0033u
/*! @brief Defines the Module Id of XcpOnCan module.*/
#define XCPONCAN_MODULE_ID                                      212U
/*! @brief Defines the version Id of XcpOnCan module.*/
#define XCPONCAN_INSTANCE_ID                                    0u
/********************************************************************************************************************
*  API Id                                                                                                           *
********************************************************************************************************************/
/*! @brief Defines the service Id for XcpOnCan_Init function */
#define XCPONCAN_INIT_API                                       1U
/*! @brief Defines the service Id for Xcp_CanIfRxIndication function */
#define XCPONCAN_CANIFRXINDICATION_API                          2U
/*! @brief Defines the service Id for Xcp_CanIfTxConfirmation function */
#define XCPONCAN_CANIFTXCONFIRMATION_API                        3U
/*! @brief Defines the service Id for XcpOnCan_Send function */
#define XCPONCAN_SEND_API                                       4U
/*! @brief Defines the service Id for XcpOnCan_SendFlush function */
#define XCPONCAN_SENDFLUSH_API                                  5U
/*! @brief Defines the service Id for XcpOnCan_TLService function */
#define XCPONCAN_TLSSERVICE_API                                 6U
/*! @brief Defines the service Id for XcpOnCan_MainFunction function */
#define XCPONCAN_MAINFUNCTION_API                               7U
/*! @brief Defines the service Id for XcpOnCan_SetPduMode function */
#define XCPONCAN_SETPDUMODE_API                                 8U
/********************************************************************************************************************
*  DEVELOPMENT ERRORS VALUES                                                                                        *
********************************************************************************************************************/
/*! @brief API service called with Invalid pointer in parameter list */
#define XCPONCAN_E_NULL_POINTER                                 0u
/*! @brief API service called with Invalid parameter index */
#define XCPONCAN_E_INV_PARAM_IDX                                1u
/*! @brief API service called with wrong command */
#define XCPONCAN_E_WRONG_CONTROL_COMMAND                        2u
/*! @brief API service called with XcpOnCan module was not initialized */
#define XCPONCAN_E_NOT_INITIALIZED                              3u
/*! @brief Defines No error id  */
#define XCPONCAN_E_NO_ERROR                                     255u
/********************************************************************************************************************
*  Module Macros                                                                                                    *
********************************************************************************************************************/

/********************************************************************************************************************
*  PUBLIC TYPES                                                                                                     *
********************************************************************************************************************/

/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
#define XCPONCAN_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief      Initializes the XcpOnCan module
*   @param[in]  ConfigPtr  Points to the implementation specific structure
*   @ServiceID  0x01
********************************************************************************************************************/
FUNC(void, XCPONCAN_CODE) XcpOnCan_Init( P2CONST(XcpOnCan_ConfigType, AUTOMATIC, XCPONCAN_APPL_CONST) ConfigPtr );
/*!******************************************************************************************************************
*   @brief      This service is used to indicate the reception of Pdu from SoAd module 
*   @param[in]  RxPduId  Receive pdu id
*   @param[in]  PduInfoPtr  pointer to the received pdu info 
*   @ServiceID  0x02
********************************************************************************************************************/
FUNC(void, XCPONCAN_CODE) Xcp_CanIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, XCPONCAN_APPL_DATA) PduInfoPtr
);
/*!******************************************************************************************************************
*   @brief      This service is used to indicate the confirmation of tramit Pdu from SoAd module 
*   @param[in]  TxPduId  Transmit pdu id
*   @param[in]  Result status of the transmit request E_OK, E_NOT_OK
*   @ServiceID  0x03
********************************************************************************************************************/
FUNC(void, XCPONCAN_CODE) Xcp_CanIfTxConfirmation(PduIdType TxPduId,Std_ReturnType Result);
/*!******************************************************************************************************************
*   @brief      This service is used to transmit the xcp pdu data to the SoAd
*   @param[in]  Xcp_Channel  xcp channel id
*   @param[in]  len  length of the data to be transmitted
*   @param[in]  msg  pointer to the transmit message buffer
*   @ServiceID  0x05
********************************************************************************************************************/
FUNC(void, XCPONCAN_CODE) XcpOnCan_Send
( 
    uint8 Xcp_Channel, 
    uint8 len, 
    P2CONST(uint8, AUTOMATIC, XCPONCAN_APPL_DATA) msg 
);
/*!******************************************************************************************************************
*   @brief      This service is used to flush the pending transmission of xcp pdu data to the SoAd.
*   @param[in]  Xcp_Channel  xcp channel id
*   @param[in]  XcpFlushTypeSel flush type : XCP_FLUSH_CTO, XCP_FLUSH_DTO, XCP_FLUSH_ALL
*   @ServiceID  0x06
********************************************************************************************************************/
FUNC(void, XCPONCAN_CODE) XcpOnCan_SendFlush( uint8 Xcp_Channel, uint8 XcpFlushTypeSel );
/*!******************************************************************************************************************
*   @brief      This service is used to handle the custom transport service layer commands
*   @param[in]  Xcp_Channel  xcp channel id
*   @param[in]  pCmd pointer to the command
*   @return returns the command error code
*   @ServiceID  0x07
********************************************************************************************************************/
FUNC(uint8, XCPONCAN_CODE) XcpOnCan_TLService( uint8 Xcp_Channel, P2CONST(uint8, AUTOMATIC, XCPONCAN_APPL_DATA) pCmd );
/*!******************************************************************************************************************
*   @brief      This service is process the pending transmission and tx confirmation timeout
*   @ServiceID  0x08
********************************************************************************************************************/
FUNC(void, XCPONCAN_CODE) XcpOnCan_MainFunction(void);
/*!******************************************************************************************************************
*   @brief      This service is used to set the PDU mode to control the transmission of PDU
*   @param[in]  Network network id 
*   @param[in]  PduMode Tx pdu mode type XcpOnCan_PduSetStateOffline : No Transmission
*   XcpOnCan_PduSetStateOnline : Transmission allowed
*   @ServiceID  0x09
********************************************************************************************************************/
FUNC(void, XCPONCAN_CODE) XcpOnCan_SetPduMode( NetworkHandleType Network, XcpOnCan_PduSetStateType PduMode );

#define XCPONCAN_STOP_SEC_CODE
#include "MemMap.h"
#endif /* XCPONCAN_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

