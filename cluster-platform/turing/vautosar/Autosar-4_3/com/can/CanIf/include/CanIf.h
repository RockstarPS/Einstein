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
*   @file CanIf.h
*   @ingroup CanIf
*   @brief This file provides the declaration of the CanIf API. This header file should be included by other
*   modules that use the CanIf API.
*   @defgroup CanIf
*   @brief The CAN Interface module provides a unique interface to manage different CAN hardware
*   device types like CAN Controllers and CAN Transceivers used by the defined ECU hardware layout.
*   The services of CanIf can be divided into the following main groups:
*      -   Initialization
*      -   Transmit request services
*      -   Transmit confirmation services
*      -   Reception indication services
*      -   Controller mode control services
*      -   PDU mode control services
********************************************************************************************************************/
#ifndef CANIF_H
#define CANIF_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "CanIf_Types.h"
#include "CanIf_Cfg.h"
#include "CanSM_Cbk.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the CanIf SW major version */
#define CANIF_SW_MAJOR_VERSION                              1u
/*! @brief Defines the CanIf SW minor version */
#define CANIF_SW_MINOR_VERSION                              0u
/*! @brief Defines the CanIf SW patch version */
#define CANIF_SW_PATCH_VERSION                              0u
/* Autosar Release */
/*! @brief Defines the CanIf AUTOSAR major version */
#define CANIF_AR_RELEASE_MAJOR_VERSION                      4u
/*! @brief Defines the CanIf AUTOSAR minor version */
#define CANIF_AR_RELEASE_MINOR_VERSION                      3u
/*! @brief Defines the CanIf AUTOSAR patch version */
#define CANIF_AR_RELEASE_REVISION_VERSION                   1u
/********************************************************************************************************************
*  MODULE INFORMATION                                                                                               *
********************************************************************************************************************/
/*! @brief Defines the Vendor Id of CanIf module. */
#define CANIF_VENDOR_ID                                     0x0033u
/*! @brief Defines the Module Id of CanIf module.*/
#define CANIF_MODULE_ID                                     60u
/*! @brief Defines the version Id of CanIf module.*/
#define CANIF_INSTANCE_ID                                   0u
/*******************************************************************************************************************/
/*  API Id                                                                                                         */
/*******************************************************************************************************************/
/*! @brief Defines the service Id for CanIf_Init function */
#define CANIF_INIT_API                                      0x01
/*! @brief Defines the service Id for CanIf_DeInit function */
#define CANIF_DEINIT_API                                    0x02
/*! @brief Defines the service Id for CanIf_SetControllerMode function */
#define CANIF_SETCONTROLLERMODE_API                         0x03
/*! @brief Defines the service Id for CanIf_GetControllerMode function */
#define CANIF_GETCONTROLLERMODE_API                         0x04
/*! @brief Defines the service Id for CanIf_Transmit function */
#define CANIF_TRANSMIT_API                                  0x05
/*! @brief Defines the service Id for CanIf_ReadRxPduData function */
#define CANIF_READRXPDUDATA_API                             0x06
/*! @brief Defines the service Id for CanIf_ReadTxNotifStatus function */
#define CANIF_READTXNOTIFSTATUS_API                         0x07
/*! @brief Defines the service Id for CanIf_ReadRxNotifStatus function */
#define CANIF_READRXNOTIFSTATUS_API                         0x08
/*! @brief Defines the service Id for CanIf_SetPduMode function */
#define CANIF_SETPDUMODE_API                                0x09
/*! @brief Defines the service Id for CanIf_GetPduMode function */
#define CANIF_GETPDUMODE_API                                0x0a
/*! @brief Defines the service Id for CanIf_GetVersionInfo function */
#define CANIF_GETVERSIONINFO_API                            0x0b
/*! @brief Defines the service Id for CanIf_SetDynamicTxId function */
#define CANIF_SETDYNAMICTXID_API                            0x0c
/*! @brief Defines the service Id for CanIf_SetTrcvMode function */
#define CANIF_SETTRCVMODE_API                               0x0d
/*! @brief Defines the service Id for CanIf_GetTrcvMode function */
#define CANIF_GETTRCVMODE_API                               0x0e
/*! @brief Defines the service Id for CanIf_GetTrcvWakeupReason function */
#define CANIF_GETTRCVWAKEUPREASON_API                       0x0f
/*! @brief Defines the service Id for CanIf_SetTrcvWakeupMode function */
#define CANIF_SETTRCVWAKEUPMODE_API                         0x10
/*! @brief Defines the service Id for CanIf_CheckWakeup function */
#define CANIF_CHECKWAKEUP_API                               0x11
/*! @brief Defines the service Id for CanIf_CheckValidation function */
#define CANIF_CHECKVALIDATION_API                           0x12
/*! @brief Defines the service Id for CanIf_TxConfirmation function */
#define CANIF_TXCONFIRMATION_API                            0x13
/*! @brief Defines the service Id for CanIf_RxIndication function */
#define CANIF_RXINDICATION_API                              0x14
/*! @brief Defines the service Id for CanIf_ControllerBusOff function */
#define CANIF_CONTROLLERBUSOFF_API                          0x16
/*! @brief Defines the service Id for CanIf_ControllerModeIndication function */
#define CANIF_CONTROLLERMODEINDICATION_API                  0x17
/*! @brief Defines the service Id for CanIf_CancelTransmit function */
#define CANIF_CANCELTRANSMIT_API                            0x18
/*! @brief Defines the service Id for CanIf_GetTxConfirmationState function */
#define CANIF_GETTXCONFIRMATIONSTATE_API                    0x19
/*! @brief Defines the service Id for CanIf_ConfirmPnAvailability function */
#define CANIF_CONFIRMPNAVAILABILITY_API                     0x1a
/*! @brief Defines the service Id for CanIf_ClearTrcvWufFlag function */
#define CANIF_CLEARTRCVWUFFLAG_API                          0x1e
/*! @brief Defines the service Id for CanIf_CheckTrcvWakeFlag function */
#define CANIF_CHECKTRCVWAKEFLAG_API                         0x1f
/*! @brief Defines the service Id for CanIf_ClearTrcvWufFlagIndication function */
#define CANIF_CLEARTRCVWUFFLAGINDICATION_API                0x20
/*! @brief Defines the service Id for CanIf_CheckTrcvWakeFlagIndication function */
#define CANIF_CHECKTRCVWAKEFLAGINDICATION_API               0x21
/*! @brief Defines the service Id for CanIf_TrcvModeIndication function */
#define CANIF_TRCVMODEINDICATION_API                        0x22
/*! @brief Defines the service Id for CanIf_SetIcomConfiguration function */
#define CANIF_SETICOMCONFIGURATION_API                      0x25
/*! @brief Defines the service Id for CanIf_CurrentIcomConfiguration function */
#define CANIF_CURRENTICOMCONFIGURATION_API                  0x26
/*! @brief Defines the service Id for CanIf_SetBaudrate function */
#define CANIF_SETBAUDRATE_API                               0x27
/*! @brief Defines the service Id for CanIf_TriggerTransmit function */
#define CANIF_TRIGGERTRANSMIT_API                           0x41
/*! @brief Defines the service Id for CanIf_GetControllerErrorState function */
#define CANIF_GETCONTROLLERERRORSTATE_API                   0x4B
/********************************************************************************************************************
*  DEVELOPMENT ERRORS VALUES                                                                                        *
********************************************************************************************************************/
/*! @brief API service called with invalid CanId parameter */
#define CANIF_E_PARAM_CANID                                 10u
/*! @brief API service called with invalid HOH parameter */
#define CANIF_E_PARAM_HOH                                   12u
/*! @brief API service called with invalid LPDU parameter */
#define CANIF_E_PARAM_LPDU                                  13u
/*! @brief API service called with invalid controller parameter */
#define CANIF_E_PARAM_CONTROLLERID                          15u
/*! @brief API service called with invalid wakeup source parameter */
#define CANIF_E_PARAM_WAKEUPSOURCE                          16u
/*! @brief API service called with invalid transceiver parameter */
#define CANIF_E_PARAM_TRCV                                  17u
/*! @brief API service called with invalid transceiver mode parameter */
#define CANIF_E_PARAM_TRCVMODE                              18u
/*! @brief API service called with invalid transceiver wakeup mode parameter */
#define CANIF_E_PARAM_TRCVWAKEUPMODE                        19u
/*! @brief API service called with invalid controller mode parameter */
#define CANIF_E_PARAM_CTRLMODE                              21u
/*! @brief API service called with invalid Pdu mode parameter */
#define CANIF_E_PARAM_PDU_MODE                              22u
/*! @brief API service called with invalid pointer parameter */
#define CANIF_E_PARAM_POINTER                               20u
/*! @brief API service used without module initialization */
#define CANIF_E_UNINIT                                      30u
/*! @brief Transmit PDU ID invalid */
#define CANIF_E_INVALID_TXPDUID                             50u
/*! @brief Transmit PDU ID invalid */
#define CANIF_E_INVALID_RXPDUID                             60u
/*! @brief CAN Interface initialisation failed */
#define CANIF_E_INIT_FAILED                                 80u
/*! @brief Defines No error id  */
#define CANIF_E_NO_ERROR                                    0xFFu
/********************************************************************************************************************
*  RUNTIME ERRORS VALUES                                                                                            *
********************************************************************************************************************/
/*! @brief Failed Data Length Check */
#define CANIF_E_INVALID_DLC                                 61u
/*! @brief data length mismatch */
#define CANIF_E_DATA_LENGTH_MISMATCH                        62u
/*! @brief Transmit requested on offline PDU channe  */
#define CANIF_E_STOPPED                                     70u
/*! @brief Message length was exceeding the maximum length  */
#define CANIF_E_TXPDU_LENGTH_EXCEEDED                       90u

#define CANIF_START_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @brief      This service Initializes internal and external interfaces of the CAN Interfacefor the further
*               processing
*   @param[in]  ConfigPtr  Pointer to configuration parameter set, used e.g. for post build parameters
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(void, CANIF_CODE) CanIf_Init(P2CONST(CanIf_ConfigType,AUTOMATIC,CANIF_APPL_CONST) ConfigPtr);
/*!******************************************************************************************************************
*   @brief      De-initializes the CanIf module.
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(void, CANIF_CODE) CanIf_DeInit(void);
/*!******************************************************************************************************************
*   @brief      This service calls the corresponding CAN Driver service for changing of
*               the CAN controller mode.
*   @param[in]  ControllerId Abstracted CanIf ControllerId which is assigned to a CAN controller, which is requested
*               for mode transition.
*   @param[in]  ControllerMode Requested mode transition
*   @return     Std_ReturnType E_OK: Controller mode request has been accepted
*               E_NOT_OK: Controller mode request has not been accepted
*   @ServiceID  0x03
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant (Not for the same controller).
********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
);
/*!******************************************************************************************************************
*   @brief      This service calls the corresponding CAN Driver service for obtaining the 
*               current status of the CAN controller
*   @param[in]  ControllerId Abstracted CanIf ControllerId which is assigned to a CAN controller, which is requested 
*               for current operation mode.
*   @param[out] ControllerModePtr Pointer to a memory location, where the current mode of the CAN controller 
*               will be stored.
*   @return     Std_ReturnType E_OK: Controller mode request has been accepted
*               E_NOT_OK: Controller mode request has not been accepted
*   @ServiceID  0x04
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerMode
(
    uint8 ControllerId,
    P2VAR(CanIf_ControllerModeType,AUTOMATIC,CANIF_APPL_DATA) ControllerModePtr
);
/*!******************************************************************************************************************
*   @brief      Requests transmission of a PDU.
*   @param[in]  TxPduId Identifier of the PDU to be transmitted
*   @param[out] PduInfoPtr Length of and pointer to the PDU data and pointer to MetaData.
*   @return     Std_ReturnType E_OK: Transmit request has been accepted. 
*               E_NOT_OK: Transmit request has not been accepted.
*   @ServiceID  0x049
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit
(
    PduIdType CanIfTxSduId,
    P2CONST(PduInfoType,AUTOMATIC,CANIF_APPL_CONST) CanIfTxInfoPtr
);
/*!******************************************************************************************************************
*   @brief      Requests cancellation of an ongoing transmission of a PDU in a lower layer communication module
*   @param[in]  TxPduId Identification of the PDU to be cancelled.
*   @return     Std_ReturnType E_OK: Cancellation was executed successfully by the destination module.
*               E_NOT_OK: Cancellation was rejected by the destination module.
*   @ServiceID  0x04a
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,CANIF_CODE) CanIf_CancelTransmit(PduIdType TxPduId);
#if (CANIF_PUBLIC_READ_RX_PDU_DATA_API == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service provides the Data Length and the received data of the requested CanIfRxSduId to the 
*               calling upper layer.
*   @param[in]  CanIfRxSduId Receive L-SDU handle specifying the corresponding CAN L-SDU ID and implicitly the 
*               CAN Driver instance as well as the corresponding CAN controller device.
*   @param[out] CanIfRxInfoPtr Contains the length (SduLength) of the received PDU, a pointer to a buffer (SduDataPtr) 
*               containing the PDU, and the MetaData related to this PDU.
*   @return     Std_ReturnType E_OK: Request for L-SDU data has been accepted
*               E_NOT_OK: No valid data has been received
*   @ServiceID  0x06
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReadRxPduData
(
    PduIdType CanIfRxSduId,
    P2VAR(PduInfoType,AUTOMATIC,CANIF_APPL_DATA) CanIfRxInfoPtr
);
#endif

#if (CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service returns the confirmation status (confirmation occurred or not) of a specific static or 
*               dynamic CAN Tx L-PDU, requested by the CanIfTxSduId.
*   @param[in]  CanIfTxSduId L-SDU handle to be transmitted. This handle specifies the corresponding CAN LSDU ID and 
*               implicitly the CAN Driver instance as well as the corresponding CAN controller device
*   @return     CanIf_NotifStatusType Current confirmation status of the corresponding CAN Tx L-PDU.
*   @ServiceID  0x07
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadTxNotifStatus(PduIdType CanIfTxSduId);
#endif
#if (CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service returns the indication status (indication occurred or not) of a
*               specific CAN Rx L-PDU, requested by the CanIfRxSduId.
*   @param[in]  CanIfRxSduId Receive L-SDU handle specifying the corresponding CAN L-SDU ID and implicitly the CAN 
*               Driver instance as well as the corresponding CAN controller device.
*   @return     CanIf_NotifStatusType Current indication status of the corresponding CAN Rx L-PDU.
*   @ServiceID  0x08
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadRxNotifStatus(PduIdType CanIfRxSduId);
#endif
/*!******************************************************************************************************************
*   @brief      This service sets the requested mode at the L-PDUs of a predefined logical PDU channel.
*   @param[in]  ControllerId All PDUs of the own ECU connected to the corresponding CanIf ControllerId, which is 
*               assigned to a physical CAN controller are addressed.
*   @param[in]  PduModeRequest Requested PDU mode change 
*   @return     Std_ReturnType E_OK: Request for mode transition has been accepted.
*               E_NOT_OK: Request for mode transition has not been accepted.
*   @ServiceID  0x09
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode(uint8 ControllerId, CanIf_PduModeType PduModeRequest);
/*!******************************************************************************************************************
*   @brief      This service reports the current mode of a requested PDU channel
*   @param[in]  ControllerId All PDUs of the own ECU connected to the corresponding CanIf ControllerId, which is 
*               assigned to a physical CAN controller are addressed
*   @param[out] PduModePtr Pointer to a memory location, where the current mode of the logical PDU channel will be 
*               stored.
*   @return     Std_ReturnType E_OK: PDU mode request has been accepted.
*               E_NOT_OK: PDU mode request has not been accepted
*   @ServiceID  0x0A
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant (Not for the same channel)
********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetPduMode
(
    uint8 ControllerId,
    P2VAR(CanIf_PduModeType,AUTOMATIC,CANIF_APPL_DATA) PduModePtr
);
#if (CANIF_VERSION_INFO_API == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service returns the version information of the called CAN Interface module.
*   @param[out] VersionInfo Pointer to where to store the version information of this module.
*   @ServiceID  0x0B
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(void, CANIF_CODE) CanIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType,AUTOMATIC,CANIF_APPL_DATA) VersionInfo
);
#endif
#if (CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service reconfigures the corresponding CAN identifier of the requested CAN L-PDU.
*   @param[in]  CanIfTxSduId L-SDU handle to be transmitted. This handle specifies the corresponding CAN LSDU
*               ID and implicitly the CAN Driver instance as well as the corresponding CAN controller device
*   @param[in]  CanId Standard/Extended CAN ID of CAN L-SDU that shall be transmitted as FD or conventional 
*               CAN frame.
*   @ServiceID  0x0C
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant 
********************************************************************************************************************/
extern FUNC(void, CANIF_CODE) CanIf_SetDynamicTxId(PduIdType CanIfTxSduId, Can_IdType CanId);
#endif
#if (CANIF_TRCV_HANDLING == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service changes the operation mode of the tansceiver TransceiverId, via calling the 
*               corresponding CAN Transceiver Driver service
*   @param[in]  TransceiverId Abstracted CanIf TransceiverId, which is assigned to a CAN transceiver, which is 
*               requested for mode transition
*   @param[in]  TransceiverMode Requested mode transition
*   @return     Std_ReturnType E_OK: Transceiver mode request has been accepted.
*               E_NOT_OK: Transceiver mode request has not been accepted.
*   @ServiceID  0x0D
*   @Sync/Async Asynchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvMode(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode);
/*!******************************************************************************************************************
*   @brief      This service changes the operation mode of the tansceiver TransceiverId, via calling the 
*               corresponding CAN Transceiver Driver service
*   @param[in]  TransceiverId Abstracted CanIf TransceiverId, which is requested for current operation mode
*   @param[out] TransceiverModePtr Requested mode of requested network the Transceiver is connected to
*   @return     Std_ReturnType E_OK: Transceiver mode request has been accepted.
*               E_NOT_OK: Transceiver mode request has not been accepted.
*   @ServiceID  0x0E
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvMode
(
    P2VAR(CanTrcv_TrcvModeType,AUTOMATIC,CANIF_APPL_DATA) TransceiverModePtr,
    uint8 TransceiverId
);
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service returns the reason for the wake up of the transceiver TransceiverId, via calling the
*               corresponding CAN Transceiver Driver service
*   @param[in]  TransceiverId Abstracted CanIf TransceiverId, which is assigned to a CAN transceiver, which is 
*               requested for wake up reason.
*   @param[out] TrcvWuReasonPtr provided pointer to where the requested transceiver wake up reason shall be returned
*   @return     Std_ReturnType E_OK: Transceiver wake up reason request has been accepted.
*               E_NOT_OK: Transceiver wake up reason request has not been accepted.
*   @ServiceID  0x0F
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason
(
    uint8 TransceiverId,
    P2VAR(CanTrcv_TrcvWakeupReasonType,AUTOMATIC,CANIF_APPL_DATA) TrcvWuReasonPtr
);
/*!******************************************************************************************************************
*   @brief      This function shall call CanTrcv_SetTrcvWakeupMode.
*   @param[in]  TransceiverId Abstracted CanIf TransceiverId,which is requested for wake up notification mode
*               transition.
*   @param[in]  TrcvWakeupMode Requested transceiver wake up notification mode
*   @return     Std_ReturnType E_OK: Will be returned, if the wake up notifications state has been changed to the
*               requested mode. E_NOT_OK: Will be returned, if the wake up notifications state change has failed 
*               or the parameter is out of the allowed range. The previous state has not been changed.
*   @ServiceID  0x10
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvWakeupMode
(
    uint8 TransceiverId,
    CanTrcv_TrcvWakeupModeType TrcvWakeupMode
);
#endif
#endif
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service checks, whether an underlying CAN driver or a CAN transceiver driver already signals a 
*               wakeup event.
*   @param[in]  WakeupSource Source device, which initiated the wake up event: CAN controller or CAN transceiver
*   @return     Std_ReturnType E_OK: Will be returned, if the check wake up request has been accepted
*               E_NOT_OK: Will be returned, if the check wake up request has not been accepted
*   @ServiceID  0x11
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
#if (CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service is performed to validate a previous wakeup event.
*   @param[in]  WakeupSource Source device which initiated the wake-up event and which has to be validated: CAN 
*               controller or CAN transceiver
*   @return     Std_ReturnType E_OK: Will be returned, if the check validation request has been accepted.
*               E_NOT_OK: Will be returned, if the check validation request has not been accepted.
*   @ServiceID  0x12
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckValidation(EcuM_WakeupSourceType WakeupSource);
#endif
#endif
#if (CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service reports, if any TX confirmation has been done for the whole CAN controller since the 
*               last CAN controller start.
*   @param[in]  ControllerId Abstracted CanIf ControllerId which is assigned to a CAN controller
*   @return     CanIf_NotifStatusType Combined TX confirmation status for all TX PDUs of the CAN controller
*   @ServiceID  0x19
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant (Not for the same controller)
********************************************************************************************************************/
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_GetTxConfirmationState(uint8 ControllerId);
#endif
#if ((CANIF_PUBLIC_PN_SUPPORT == STD_ON) && (CANIF_TRCV_HANDLING == STD_ON))
/*!******************************************************************************************************************
*   @brief      Requests the CanIf module to check the Wake flag of the designated CAN transceiver.
*   @param[in]  TransceiverId Abstract CanIf TransceiverId, which is assigned to the designated CAN transceiver
*   @return     Std_ReturnType E_OK: Request has been accepted E_NOT_OK: Request has not been accepted
*   @ServiceID  0x1F
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant for different CAN transceivers
********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_CheckTrcvWakeFlag(uint8 TransceiverId);
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      Requests the CanIf module to clear the WUF flag of the designated CAN transceiver.
*   @param[in]  TransceiverId Abstract CanIf TransceiverId, which is assigned to the designated CAN transceiver
*   @return     Std_ReturnType E_OK: Request has been accepted E_NOT_OK: Request has not been accepted
*   @ServiceID  0x1E
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant for different CAN transceivers
********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag(uint8 TransceiverId);
#endif

#endif

#if (CANIF_SET_BAUD_RATE_API == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service shall set the baud rate configuration of the CAN controller. Depending on necessary 
*               baud rate modifications the controller might have to reset
*   @param[in]  ControllerId Abstract CanIf ControllerId which is assigned to a CAN controller, whose baud rate 
*               shall be set.
*   @param[in]  BaudRateConfigID references a baud rate configuration by ID
*   @return     Std_ReturnType E_OK: Service request accepted, setting of (new) baud rate started
*               E_NOT_OK: Service request not accepted
*   @ServiceID  0x1E
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different ControllerIds. Non reentrant for the same ControllerId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetBaudrate(uint8 ControllerId, uint16 BaudRateConfigID);
#endif
#if (CANIF_PUBLIC_ICOM_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service shall change the Icom Configuration of a CAN controller to the requested one..
*   @param[in]  ControllerId Abstracted CanIf Controller Id which is assigned to a CAN controller
*   @param[in]  ConfigurationId Requested Configuration
*   @return     Std_ReturnType E_OK: Request accepted E_NOT_OK: Request denied
*   @ServiceID  0x25
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant only for different controller Ids
********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetIcomConfiguration
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId
);
#endif
#if ((CANIF_CFG_AR_RELEASE_MAJOR_VERSION >= 4U) && (CANIF_CFG_AR_RELEASE_MINOR_VERSION >= 3U))
/*!******************************************************************************************************************
*   @brief      This service calls the corresponding CAN Driver service for obtaining the error state of the 
*               CAN controller.
*   @param[in]  ControllerId Abstracted CanIf ControllerId which is assigned to a CAN controller, which is requested 
*               for ErrorState
*   @param[out]  ErrorStatePtr Pointer to a memory location, where the error state of the CAN controller 
*                will be stored.
*   @return     Std_ReturnType - Return status
*               E_OK: Error state request has been accepted.
*               E_NOT_OK: Error state request has not been accepted.
*   @ServiceID  0x4B
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant for the same ControllerId
********************************************************************************************************************/
extern Std_ReturnType CanIf_GetControllerErrorState
(
    uint8 ControllerId, 
    P2VAR(Can_ErrorStateType,AUTOMATIC,CANIF_APPL_DATA) ErrorStatePtr
);
#endif

#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CANIF_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

