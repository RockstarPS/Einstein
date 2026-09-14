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
*   @file CanIf_Cbk.h
*   @ingroup CanIf
*   @brief This file provides list of functions provided for other modules. The function prototypes of the 
*   callback functions shall be provided in the file CanIf_Cbk.h
********************************************************************************************************************/
#ifndef CANIF_CBK_H
#define CANIF_CBK_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "CanIf_Cfg.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/*! @brief Defines the CanIf Callback AUTOSAR major version */ 
#define CANIF_CBK_AR_RELEASE_MAJOR_VERSION  4U
/*! @brief Defines the CanIf Callback AUTOSAR minor version */ 
#define CANIF_CBK_AR_RELEASE_MINOR_VERSION  2U
/*! @brief Defines the CanIf Callback AUTOSAR patch version */ 
#define CANIF_CBK_AR_RELEASE_PATCH_VERSION  1U

#define CANIF_START_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC CALLBACK FUNCTION PROTOTYPE                                                                               *
********************************************************************************************************************/
#if (CANIF_TRIGGER_TRANSMIT_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      Within this API, the upper layer module (called module) shall check whether the available data fits 
*               into the buffer size reported by PduInfoPtr->SduLength. If it fits, it shall copy its data into 
*               the buffer provided by PduInfoPtr->SduDataPtr and update the length of the actual copied data
*               in PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing PduInfoPtr.
*   @param[in]  TxPduId ID of the SDU that is requested to be transmitted.
*   @param[in,out] PduInfoPtr Contains a pointer to a buffer (SduDataPtr) to where the SDU data shall be copied, and 
*               the available buffer size in SduLengh. On return, the service will indicate the length of the copied 
*               SDU data in SduLength.
*   @return     Std_ReturnType E_OK: SDU has been copied and SduLength indicates the number of copied bytes.
*               E_NOT_OK: No SDU data has been copied. PduInfoPtr must not be used since it may contain a NULL
*               pointer or point to invalid data.
*   @ServiceID  0x41
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId 
********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_TriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType,AUTOMATIC,CANIF_APPL_DATA) PduInfoPtr
);
#endif
/*!******************************************************************************************************************
*   @brief      This service confirms a previously successfully processed transmission of a CAN TxPDU.
*   @param[in]  CanTxPduId L-PDU handle of CAN L-PDU successfully transmitted. This ID specifies the corresponding 
*               CAN L-PDU ID and implicitly the CAN Driver instance as well as the corresponding CAN controller device.
*   @ServiceID  0x13
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(void, CANIF_CODE) CanIf_TxConfirmation(PduIdType CanTxPduId);
/*!******************************************************************************************************************
*   @brief      This service indicates a successful reception of a received CAN Rx LPDU to the CanIf after passing 
*               all filters and validation checks
*   @param[in]  Mailbox Identifies the HRH and its corresponding CAN Controller
*   @param[in]  PduInfoPtr Pointer to the received L-PDU
*   @ServiceID  0x14
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(void, CANIF_CODE) CanIf_RxIndication
(
    P2CONST(Can_HwType,AUTOMATIC,CANIF_APPL_CONST) Mailbox,
    P2CONST(PduInfoType,AUTOMATIC,CANIF_APPL_CONST) PduInfoPtr
);
/*!******************************************************************************************************************
*   @brief      This service indicates a Controller BusOff event referring to the corresponding CAN Controller with 
*               the abstract CanIf ControllerId
*   @param[in]  ControllerId Abstract CanIf ControllerId which is assigned to a CAN controller, where a BusOff 
*               occured
*   @ServiceID  0x16
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(void, CANIF_CODE) CanIf_ControllerBusOff(uint8 ControllerId);
/*!******************************************************************************************************************
*   @brief      This service indicates a controller state transition referring to the corresponding CAN controller
*               with the abstract CanIf ControllerId.
*   @param[in]  ControllerId Abstract CanIf ControllerId which is assigned to a CAN controller, which state has
*               been transitioned.
*   @param[in]  ControllerMode Mode to which the CAN controller transitioned
*   @ServiceID  0x17
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
);
#if (CANIF_PUBLIC_ICOM_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service shall inform about the change of the Icom Configuration of a CAN controller using the 
*               abstract CanIf ControllerId.
*   @param[in]  ControllerId Abstract CanIf ControllerId which is assigned to a CAN controller, which informs about
*               the Configuration Id.
*   @param[in]  ConfigurationId Active Configuration Id.
*   @param[in]  Error ICOM_SWITCH_E_OK: No Error 
*               ICOM_SWITCH_E_FAILED: Switch to requested Configuration failed. Severe Error.
*   @ServiceID  0x26
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant only for different controller Ids 
********************************************************************************************************************/
extern FUNC(void, CANIF_CODE) CanIf_CurrentIcomConfiguration
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId,
    IcomSwitch_ErrorType Error
);
#endif
#if (CANIF_TRCV_HANDLING == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service indicates a transceiver state transition referring to the corresponding CAN transceiver 
*               with the abstract CanIf TransceiverId.
*   @param[in]  TransceiverId Abstract CanIf TransceiverId, which is assigned to a CAN transceiver, which state has 
*               been transitioned.
*   @param[in]  TransceiverMode Mode to which the CAN transceiver transitioned
*   @ServiceID  0x22
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(void, CANIF_CODE) CanIf_TrcvModeIndication(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode);
#endif

#if ((CANIF_PUBLIC_PN_SUPPORT == STD_ON) && (CANIF_TRCV_HANDLING == STD_ON))
/*!******************************************************************************************************************
*   @brief      This service indicates that the transceiver is running in PN communication mode referring to the 
*               corresponding CAN transceiver with the abstract CanIf TransceiverId.
*   @param[in]  TransceiverId Abstract CanIf TransceiverId, which is assigned to a CAN transceiver, which was 
*               checked for PN availability.
*   @ServiceID  0x1a
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(void, CANIF_CODE) CanIf_ConfirmPnAvailability(uint8 TransceiverId);
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This service indicates that the transceiver has cleared the WufFlag referring to the corresponding 
*               CAN transceiver with the abstract CanIf TransceiverId.
*   @param[in]  TransceiverId Abstract CanIf TransceiverId, which is assigned to a CAN transceiver, for which 
*               this function was called
*   @ServiceID  0x20
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(void, CANIF_CODE) CanIf_ClearTrcvWufFlagIndication(uint8 TransceiverId);
/*!******************************************************************************************************************
*   @brief      This service indicates that the check of the transceiver’s wake-up flag has been finished by the 
*               corresponding CAN transceiver with the abstract CanIf TransceiverId. This indication is used to cope
*               with the asynchronous transceiver communication
*   @param[in]  TransceiverId Abstract CanIf TransceiverId, which is assigned to a CAN transceiver, for which 
*               this function was called
*   @ServiceID  0x21
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(void, CANIF_CODE) CanIf_CheckTrcvWakeFlagIndication(uint8 TransceiverId);
#endif
#endif

#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CANIF_CBK_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


