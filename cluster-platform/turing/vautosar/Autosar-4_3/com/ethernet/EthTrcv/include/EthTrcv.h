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
*   @file EthTrcv.h
*   @ingroup EthTrcv
*   @brief This file provides the declaration of the EthTrcv API. This header file should be included by other
*   modules that use the EthTrcv API.
*   @defgroup EthTrcv
*   @brief The main task of the Ethernet Transceiver Driver: Provide to the upper layer (Ethernet Interface) a 
*   hardware independent interface comprising multiple equal transceivers. This interface shall be uniform for all
*   transceivers. Thus, the upper layer (Ethernet Interface) may access the underlying bus system in a uniform manner.
*   The configuration of the Ethernet Transceiver Driver however is bus specific, since it takes into account the 
*   specific features of the communication transceiver
********************************************************************************************************************/
#ifndef ETHTRCV_H
#define ETHTRCV_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "EthTrcv_Types.h"
#include "EthTrcv_Cfg.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the EthTrcv SW major version */
#define ETHTRCV_SW_MAJOR_VERSION                1u
/*! @brief Defines the EthTrcv SW minor version */
#define ETHTRCV_SW_MINOR_VERSION                0u
/*! @brief Defines the EthTrcv SW patch version */
#define ETHTRCV_SW_PATCH_VERSION                0u
/* Autosar Release */
/*! @brief Defines the EthTrcv AUTOSAR major version */
#define ETHTRCV_AR_RELEASE_MAJOR_VERSION        4u
/*! @brief Defines the EthTrcv AUTOSAR minor version */
#define ETHTRCV_AR_RELEASE_MINOR_VERSION        3u
/*! @brief Defines the EthTrcv AUTOSAR patch version */
#define ETHTRCV_AR_RELEASE_REVISION_VERSION     1u
/********************************************************************************************************************
*  MODULE INFORMATION                                                                                               *
********************************************************************************************************************/                      
/*! @brief Defines the Vendor Id of EthTrcv module. */
#define ETHTRCV_VENDOR_ID                       0x0033u
/*! @brief Defines the Module Id of EthTrcv module.*/
#define ETHTRCV_MODULE_ID                       73u
/*! @brief Defines the version Id of EthTrcv module.*/
#define ETHTRCV_INSTANCE_ID                     0u
/********************************************************************************************************************
*  API Id                                                                                                           *
********************************************************************************************************************/
/*! @brief Defines the service Id for EthTrcv_Init function */
#define ETHTRCV_INIT_API						0x01u
/*! @brief Defines the service Id for EthTrcv_SetTransceiverMode function */
#define ETHTRCV_SETTRANSCEIVERMODE_API		    0x03u
/*! @brief Defines the service Id for EthTrcv_GetTransceiverMode function */
#define ETHTRCV_GETTRANSCEIVERMODE_API			0x04u
/*! @brief Defines the service Id for EthTrcv_SetTransceiverWakeupMode function */
#define ETHTRCV_SETTRANSCEIVERWAKEUPMODE_API	0x0Du
/*! @brief Defines the service Id for EthTrcv_GetTransceiverWakeupMode function */
#define ETHTRCV_GETTRANSCEIVERWAKEUPMODE_API	0x0Eu
/*! @brief Defines the service Id for EthTrcv_CheckWakeup function */
#define ETHTRCV_CHECKWAKEUP_API					0x0Fu
/*! @brief Defines the service Id for EthTrcv_StartAutoNegotiation function */
#define ETHTRCV_STARTAUTONEGOTIATION_API		0x05u
/*! @brief Defines the service Id for EthTrcv_GetLinkState function */
#define ETHTRCV_GETLINKSTATE_API				0x06u
/*! @brief Defines the service Id for EthTrcv_GetBaudRate function */
#define ETHTRCV_GETBAUDRATE_API					0x07u
/*! @brief Defines the service Id for EthTrcv_GetDuplexMode function */
#define ETHTRCV_GETDUPLEXMODE_API				0x08u
/*! @brief Defines the service Id for EthTrcv_GetVersionInfo function */
#define ETHTRCV_GETVERSIONINFO_API				0x0Bu
/*! @brief Defines the service Id for EthTrcv_ReadMiiIndication function */
#define ETHTRCV_READMIIINDICATION_API			0x09u
/*! @brief Defines the service Id for EthTrcv_ReadMiiIndication function */
#define ETHTRCV_WRITEMIIINDICATION_API			0x0Au
/*! @brief Defines the service Id for EthTrcv_ReadMiiIndication function */
#define ETHTRCV_MAINFUNCTION_API				0x0Cu
/********************************************************************************************************************
*  DEVELOPMENT ERRORS VALUES                                                                                        *
********************************************************************************************************************/
/*! @brief API service called with Invalid transceiver index */
#define ETHTRCV_E_INV_TRCV_IDX		 		0x01u
/*! @brief API service called with EthTrcv module was not initialized */
#define ETHTRCV_E_NOT_INITIALIZED		    0x02u
/*! @brief API service called with Invalid pointer in parameter list */
#define ETHTRCV_E_PARAM_POINTER		 		0x03u
/*! @brief Defines No error id  */
#define ETHTRCV_E_NO_ERROR                  0xFFu
/* #! Extended Production Errors */
/*! @brief Ethernet Transceiver Access Failure. Monitors the access to the Ethernet Transceiver.
*   Detection Criteria: 
*   FAIL : access to the Ethernet Transceiver fails the module shall report the extended production error with event 
*   status DEM_EVENT_STATUS_PREFAILED to DEM.
*   Pass : When access to the Ethernet Transceiver succeds the module shall report the extended production error with 
*   event status DEM_EVENT_STATUS_PREPASSED to DEM.
*/
#define ETHTRCV_E_ACCESS                    0x01u
/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
#define ETHTRCV_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief      Initializes the Ethernet Transceiver Driver
*   @param[in]  CfgPtr  Points to the implementation specific structure 
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(void, ETHTRCV_CODE) EthTrcv_Init( P2CONST(EthTrcv_ConfigType,AUTOMATIC,ETHTRCV_APPL_CONST) CfgPtr );
/*!******************************************************************************************************************
*   @brief      Enables / disables the indexed transceiver
*   @param[in]  TrcvIdx  Index of the transceiver within the context of the Ethernet Transceiver Driver
*   @param[in]  CtrlMode ETHTRCV_MODE_DOWN: disable the transceiver ETHTRCV_MODE_ACTIVE: enable the transceiver 
*   @return     E_OK: Service accepted E_NOT_OK: Service denied
*   @ServiceID  0x03
*   @Sync/Async Asynchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_SetTransceiverMode( uint8 TrcvIdx, EthTrcv_ModeType CtrlMode );
/*!******************************************************************************************************************
*   @brief      Obtains the state of the indexed transceiver
*   @param[in]  TrcvIdx  Index of the transceiver within the context of the Ethernet Transceiver Driver 
*   @param[out] TrcvModePtr ETHTRCV_MODE_DOWN: the transceiver is disabled 
*               ETHTRCV_MODE_ACTIVE: the transceiver is enable
*   @return     E_OK: success E_NOT_OK: transceiver could not be initialized
*   @ServiceID  0x04
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetTransceiverMode
( 
    uint8 TrcvIdx, 
    P2VAR(EthTrcv_ModeType,AUTOMATIC,ETHTRCV_APPL_DATA) TrcvModePtr
);
/*!******************************************************************************************************************
*   @brief      Enables / disables the wake-up mode or clear the wake-up reason of the indexed transceiver
*   @param[in]  TrcvIdx  Index of the transceiver within the context of the Ethernet Transceiver Driver 
*   @param[in]  TrcvWakeupMode ETHTRCV_WUM_DISABLE: disable transceiver wake up ETHTRCV_WUM_ENABLE: enable transceiver 
*               wake up  ETHTRCV_WUM_CLEAR: clears transceiver wake up reason 
*   @return     E_OK: transceiver wake up mode has been changed. 
*               E_NOT_OK: transceiver wake up mode could not be changed or the wake-up reason could not be cleared.
*   @ServiceID  0x0d
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_SetTransceiverWakeupMode
( 
    uint8 TrcvIdx, 
    EthTrcv_WakeupModeType TrcvWakeupMode 
);
/*!******************************************************************************************************************
*   @brief      Returns the wake up mode of the indexed transceiver
*   @param[in]  TrcvIdx  Index of the transceiver within the context of the Ethernet Transceiver Driver 
*   @param[out] TrcvWakeupModePtr ETHTRCV_WUM_DISABLE: transceiver wake up is disabled 
*               ETHTRCV_WUM_ENABLE: transceiver wake up is enabled
*   @return     E_OK: success E_NOT_OK: transceiver wake up mode could not be obtained
*   @ServiceID  0x0e
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetTransceiverWakeupMode
( 
    uint8 TrcvIdx, 
    P2VAR(EthTrcv_WakeupModeType,AUTOMATIC,ETHTRCV_APPL_DATA) TrcvWakeupModePtr 
);
/*!******************************************************************************************************************
*   @brief      Service is called by EthIf in case a wake-up interrupt is detected.
*   @param[in]  TrcvIdx  Index of the transceiver within the context of the Ethernet Transceiver Driver 
*   @return     E_OK: The function has been successfully executed E_NOT_OK: The function could not be successfully 
*               executed
*   @ServiceID  0x0f
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_CheckWakeup( uint8 TrcvIdx );
/*!******************************************************************************************************************
*   @brief      Restarts the negotiation of the transmission parameters used by the indexed transceiver
*   @param[in]  TrcvIdx  Index of the transceiver within the context of the Ethernet Transceiver Driver 
*   @return     E_OK: success E_NOT_OK: transceiver could not be initialized
*   @ServiceID  0x05
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_StartAutoNegotiation( uint8 TrcvIdx );
/*!******************************************************************************************************************
*   @brief      Obtains the link state of the indexed transceiver
*   @param[in]  TrcvIdx  Index of the transceiver within the context of the Ethernet Transceiver Driver 
*   @param[out] LinkStatePtr ETHTRCV_LINK_STATE_DOWN: transceiver is disconnected 
*               ETHTRCV_LINK_STATE_ACTIVE: transceiver is connected
*   @return     E_OK: success E_NOT_OK: transceiver could not be initialized
*   @ServiceID  0x06
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetLinkState
( 
    uint8 TrcvIdx, 
    P2VAR(EthTrcv_LinkStateType,AUTOMATIC,ETHTRCV_APPL_DATA) LinkStatePtr 
);
/*!******************************************************************************************************************
*   @brief      Obtains the baud rate of the indexed transceiver
*   @param[in]  TrcvIdx  Index of the transceiver within the context of the Ethernet Transceiver Driver 
*   @param[out] BaudRatePtr ETHTRCV_BAUD_RATE_10MBIT: 10MBit connection ETHTRCV_BAUD_RATE_100MBIT: 100MBit connection
*               ETHTRCV_BAUD_RATE_1000MBIT: 1000MBit connection
*   @return     E_OK: success E_NOT_OK: transceiver could not be initialized
*   @ServiceID  0x07
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetBaudRate
( 
    uint8 TrcvIdx, 
    P2VAR(EthTrcv_BaudRateType,AUTOMATIC,ETHTRCV_APPL_DATA) BaudRatePtr 
);
/*!******************************************************************************************************************
*   @brief      Obtains the duplex mode of the indexed transceiver
*   @param[in]  TrcvIdx  Index of the transceiver within the context of the Ethernet Transceiver Driver 
*   @param[out] DuplexModePtr ETHTRCV_DUPLEX_MODE_HALF: half duplex connections 
*               ETHTRCV_DUPLEX_MODE_FULL: full duplex connection 
*   @return     E_OK: success E_NOT_OK: transceiver could not be initialized
*   @ServiceID  0x08
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetDuplexMode
( 
    uint8 TrcvIdx, 
    P2VAR(EthTrcv_DuplexModeType,AUTOMATIC,ETHTRCV_APPL_DATA) DuplexModePtr 
);
/*!******************************************************************************************************************
*   @brief      Returns the version information of this module
*   @param[out] VersionInfoPtr Version information of this module
*   @ServiceID  0x0b
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(void, ETHTRCV_CODE) EthTrcv_GetVersionInfo
(
    P2VAR(Std_VersionInfoType,AUTOMATIC,ETHTRCV_APPL_DATA) VersionInfoPtr 
); 
/*!******************************************************************************************************************
*   @brief      Called when information has been read out via MII interface. Triggered by previous Eth_ReadMii call. 
*               Can directly be called within Eth_ReadMii.
*   @param[in]  CtrlIdx Index of the controller within the context of the Ethernet Driver
*   @param[in]  TrcvIdx Index of the transceiver on the MII
*   @param[in]  RegIdx Index of the transceiver register on the MII
*   @param[in]  RegVal Value contained in the indexed register 
*   @ServiceID  0x09
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant for the same CtrlIdx, reentrant for different Parameters.
********************************************************************************************************************/
extern FUNC(void, ETHTRCV_CODE) EthTrcv_ReadMiiIndication( uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx, uint8 RegVal );
/*!******************************************************************************************************************
*   @brief      Called when information has been written via MII interface. Triggered by previous Eth_WriteMii call.
*               Can directly be called within Eth_WriteMii.
*   @param[in]  CtrlIdx Index of the controller within the context of the Ethernet Driver
*   @param[in]  TrcvIdx Index of the transceiver on the MII
*   @param[in]  RegIdx Index of the transceiver register on the MII
*   @ServiceID  0x0a
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant for the same CtrlIdx, reentrant for different Parameters.
********************************************************************************************************************/
extern FUNC(void, ETHTRCV_CODE) EthTrcv_WriteMiiIndication( uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx );
/*!******************************************************************************************************************
*   @brief      Used for polling state changes and wakeup reasons. Calls EthIf_TrcvModeIndication when the transceiver
*               mode changed. Stores wakeup events if EthTrcvWakeUpSupport is set to ETHTRCV_WAKEUP_BY_POLLING.
*   @ServiceID  0x0c
********************************************************************************************************************/
extern FUNC(void, ETHTRCV_CODE) EthTrcv_MainFunction( void );

#define ETHTRCV_STOP_SEC_CODE
#include "MemMap.h"

#endif /* ETHTRCV_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

