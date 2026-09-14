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
*   @file DoIP.h
*   @ingroup DoIP
*   @brief This file provides the declaration of the DoIP API. This header file should be included by other
*   modules that use the DoIP API.
*   @defgroup DoIP
*   @brief DoIP implements the ISO 13400 Diagnostic over IP . The main functionality of the DoIP are 
*   Vehicle identification and announcement: Is necessary to detect who is participating in the DoIP communication
*   Routing Activation: Allows that single Diagnostic Message pathes are activated or not to treat different 
*   protocols different (like UDS and OBD) and to also treat single testers different
*   Node information: Provides general information of the single DoIP entity. Usually used by the testers to get
*   the current DoIP protocol relevant information from the single DoIPEntities.
*   Alive mechanism: Is used to maintain different tester connections.
********************************************************************************************************************/
#ifndef DOIP_H
#define DOIP_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "DoIP_Types.h"
#include "DoIP_Cfg.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the DoIP SW major version */
#define DOIP_SW_MAJOR_VERSION                1u
/*! @brief Defines the DoIP SW minor version */
#define DOIP_SW_MINOR_VERSION                0u
/*! @brief Defines the DoIP SW patch version */
#define DOIP_SW_PATCH_VERSION                0u
/* Autosar Release */
/*! @brief Defines the DoIP AUTOSAR major version */
#define DOIP_AR_RELEASE_MAJOR_VERSION        4u
/*! @brief Defines the DoIP AUTOSAR minor version */
#define DOIP_AR_RELEASE_MINOR_VERSION        3u
/*! @brief Defines the DoIP AUTOSAR patch version */
#define DOIP_AR_RELEASE_REVISION_VERSION     1u
/********************************************************************************************************************
*  MODULE INFORMATION                                                                                               *
********************************************************************************************************************/                      
/*! @brief Defines the Vendor Id of DoIP module. */
#define DOIP_VENDOR_ID                       0x0033u
/*! @brief Defines the Module Id of DoIP module.*/
#define DOIP_MODULE_ID                       173u
/*! @brief Defines the version Id of DoIP module.*/
#define DOIP_INSTANCE_ID                     0u
/********************************************************************************************************************
*  API Id                                                                                                           *
********************************************************************************************************************/
/*! @brief Defines the service Id for DoIP_TpTransmit function */
#define DOIP_TPTRANSMIT_API	                    0X49
/*! @brief Defines the service Id for DoIP_TpCancelTransmit function */
#define DOIP_TPCANCELTRANSMIT_API	            0X4A
/*! @brief Defines the service Id for DoIP_TpCancelReceive function */
#define DOIP_TPCANCELRECEIVE_API                0X4C
/*! @brief Defines the service Id for DoIP_IfTransmit function */
#define DOIP_IFTRANSMIT_API	                    0X49
/*! @brief Defines the service Id for DoIP_IfCancelTransmit function */
#define DOIP_IFCANCELTRANSMIT_API	            0X4A
/*! @brief Defines the service Id for DoIP_Init function */
#define DOIP_INIT_API 	                        0X01
/*! @brief Defines the service Id for DoIP_GetVersionInfo function */
#define DOIP_GETVERSIONINFO_API	                0X00
/*! @brief Defines the service Id for DoIP_SoAdTpCopyTxData function */
#define DOIP_SOADTPCOPYTXDATA_API               0X43
/*! @brief Defines the service Id for DoIP_SoAdTpTxConfirmation function */
#define DOIP_SOADTPTXCONFIRMATION_API	        0X48
/*! @brief Defines the service Id for DoIP_SoAdTpCopyRxData function */
#define DOIP_SOADTPCOPYRXDATA_API	            0X44
/*! @brief Defines the service Id for DoIP_SoAdTpStartOfReception function */
#define DOIP_SOADTPSTARTOFRECEPTION_API         0X46
/*! @brief Defines the service Id for DoIP_SoAdTpRxIndication function */
#define DOIP_SOADTPRXINDICATION_API 	        0X45
/*! @brief Defines the service Id for DoIP_SoAdIfRxIndication function */
#define DOIP_SOADIFRXINDICATION_API 	        0X42
/*! @brief Defines the service Id for DoIP_SoAdIfTxConfirmation function */
#define DOIP_SOADIFTXCONFIRMATION_API 	        0X40
/*! @brief Defines the service Id for DoIP_SoConModeChg function */
#define DOIP_SOCONMODECHG_API 	                0X0B
/*! @brief Defines the service Id for DoIP_LocalIpAddrAssignmentChg function */
#define DOIP_LOCALIPADDRASSIGNMENTCHG_API 	    0X0C
/*! @brief Defines the service Id for DoIP_ActivationLineSwitchActive function */
#define DOIP_ACTIVATIONLINESWITCHACTIVE_API     0X0F
/*! @brief Defines the service Id for DoIP_ActivationLineSwitchInactive function */
#define DOIP_ACTIVATIONLINESWITCHINACTIVE_API   0X0E
/*! @brief Defines the service Id for DoIP_MainFunction function */
#define DOIP_MAINFUNCTION_API                   0X02
/********************************************************************************************************************
*  DEVELOPMENT ERRORS VALUES                                                                                        *
********************************************************************************************************************/
/*! @brief Defines API service call without module initialization */
#define DOIP_E_UNINIT           		 		0x01u
/*! @brief Defines API service called with Invalid pointer in parameter list */
#define DOIP_E_PARAM_POINTER		            0x02u
/*! @brief Defines Wrong Lower Layer (SoaAd) or Upper Layer (PduRouter) Id received */
#define DOIP_E_INVALID_PDU_SDU_ID               0x03u
/*! @brief Defines API call with invalid Parameter  */
#define DOIP_E_INVALID_PARAMETER                0x04u
/*! @brief Defines DoIP Init service call failure */
#define DOIP_E_INIT_FAILED                      0x05u
/*! @brief Defines No error id  */
#define DOIP_E_NO_ERROR                         0xFFu
/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
#define DOIP_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief      Requests transmission of a PDU.
*   @param[in]  TxPduId  Identifier of the PDU to be transmitted
*   @param[in]  Length of and pointer to the PDU data and pointer to MetaData
*   @return     E_OK: Transmit request has been accepted E_NOT_OK: Transmit request has not been accepted
*   @ServiceID  0x49
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, DOIP_CODE) DoIP_TpTransmit
(
    PduIdType TxPduId,
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) PduInfoPtr 
);
/*!******************************************************************************************************************
*   @brief      Requests cancellation of an ongoing transmission of a PDU in a lower layer communication module.
*   @param[in]  TxPduId  Identification of the PDU to be cancelled.
*   @return     E_OK: Cancellation was executed successfully by the destination module.
*               E_NOT_OK: Cancellation was rejected by the destination module.
*   @ServiceID  0x4a
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, DOIP_CODE) DoIP_TpCancelTransmit(PduIdType TxPduId);
/*!******************************************************************************************************************
*   @brief      Requests cancellation of an ongoing reception of a PDU in a lower layer transport protocol module.
*   @param[in]  RxPduId  Identification of the PDU to be cancelled.
*   @return     E_OK: Cancellation was executed successfully by the destination module.
*               E_NOT_OK: Cancellation was rejected by the destination module.
*   @ServiceID  0x4c
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, DOIP_CODE) DoIP_TpCancelReceive(PduIdType RxPduId);
/*!******************************************************************************************************************
*   @brief      Requests transmission of a PDU.
*   @param[in]  TxPduId  Identifier of the PDU to be transmitted
*   @param[in]  PduInfoPtr Length of and pointer to the PDU data and pointer to MetaData.
*   @return     E_OK: Transmit request has been accepted.
*               E_NOT_OK: Transmit request has not been accepted.
*   @ServiceID  0x49
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, DOIP_CODE) DoIP_IfTransmit
(
    PduIdType TxPduId, 
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) PduInfoPtr
);
/*!******************************************************************************************************************
*   @brief      Requests cancellation of an ongoing transmission of a PDU in a lower layer
*   @param[in]  TxPduId  Identification of the PDU to be cancelled.
*   @return     E_OK: Cancellation was executed successfully by the destination module.
*               E_NOT_OK: Cancellation was rejected by the destination module.
*   @ServiceID  0x4a
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, DOIP_CODE) DoIP_IfCancelTransmit(PduIdType TxPduId);
/*!******************************************************************************************************************
*   @brief      This service initializes all global variables of the DoIP module. After return of this service the 
*               DoIP module is operational.
*   @param[in]  DoIPConfigPtr  Pointer to the configuration data of the DoIP module
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non reentrant
********************************************************************************************************************/
extern FUNC(void, DOIP_CODE) DoIP_Init(P2CONST(DoIP_ConfigType,AUTOMATIC,DOIP_APPL_CONST) DoIPConfigPtr);
#if (DOIP_VERSION_INFO_API == STD_ON)
/*!******************************************************************************************************************
*   @brief      Returns the version information of this module.
*   @param[out] versioninfo  Pointer to where to store the version information of this module.
*   @ServiceID  0x00
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(void, DOIP_CODE) DoIP_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,DOIP_APPL_DATA) versioninfo);
/*!******************************************************************************************************************
*   @brief      Schedules the Diagnostic over IP module. (Entry point for scheduling)
*   @ServiceID  0x02
********************************************************************************************************************/
extern FUNC(void, DOIP_CODE) DoIP_MainFunction(void);
#endif

#define DOIP_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DOIP_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

