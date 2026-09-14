/********************************************************************************************************************
|    File Name: CanIf.h
|
|  Description: Implementation of the AUTOSAR CAN Interface
|--------------------------------------------------------------------------------------------------------------------
|               C O P Y R I G H T
|--------------------------------------------------------------------------------------------------------------------
| Copyright (c) 2019 by Visteon Corporation.       All rights reserved.
|
| NOTICE: This is an unpublished work of authorship, which contains trade secrets.
| Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
| its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
| or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
| in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
| under all copyright laws to protect this work as a published work, when appropriate.
| Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
| without the written authorization of Visteon Corporation.
|--------------------------------------------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|--------------------------------------------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| MA            Muthu Alexander          Visteon Corporation
|--------------------------------------------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|--------------------------------------------------------------------------------------------------------------------
| Date        Version   Author  Description
| ----------  --------  ------  -------------------------------------------------------------------------------------
| 2020-03-20  00.00.04  MA     Review comments fixed (Task 782921)
| 2020-03-06  00.00.03  MA     TRCV support, Wakeup Support, Tx and Rx Buffer support are added
| 2020-01-30  00.00.02  MA     Review comments fixed (Task 1394507)
| 2019-12-16  00.00.01  MA     Initial Version
|*******************************************************************************************************************/
#ifndef CANIF_H
#define CANIF_H

#include "CanIf_Cfg.h"
#include "CanIf_Types.h"
#include "CanSM_Cbk.h"
/*******************************************************************************************************************/
/*  Version Information                                                                                            */
/*******************************************************************************************************************/
/* Software Version */
#define CANIF_SW_MAJOR_VERSION                              0u
#define CANIF_SW_MINOR_VERSION                              0u
#define CANIF_SW_PATCH_VERSION                              2u
/* Autosar Release */
#define CANIF_AR_RELEASE_MAJOR_VERSION                      4u
#define CANIF_AR_RELEASE_MINOR_VERSION                      2u
#define CANIF_AR_RELEASE_REVISION_VERSION                   1u
/*******************************************************************************************************************/
/*  Module Information                                                                                             */
/*******************************************************************************************************************/
/* Vendor Id */
#define CANIF_VENDOR_ID                                     255u
/* Module Id */
#define CANIF_MODULE_ID                                     60u
/* Instance Id */
#define CANIF_INSTANCE_ID                                   0u
/*******************************************************************************************************************/
/*  API Id                                                                                                         */
/*******************************************************************************************************************/
#define CANIF_INIT_API                                      0x01
#define CANIF_SETCONTROLLERMODE_API                         0x03
#define CANIF_GETCONTROLLERMODE_API                         0x04
#define CANIF_TRANSMIT_API                                  0x05
#define CANIF_READRXPDUDATA_API                             0x06
#define CANIF_READTXNOTIFSTATUS_API                         0x07
#define CANIF_READRXNOTIFSTATUS_API                         0x08
#define CANIF_SETPDUMODE_API                                0x09
#define CANIF_GETPDUMODE_API                                0x0a
#define CANIF_GETVERSIONINFO_API                            0x0b
#define CANIF_SETDYNAMICTXID_API                            0x0c
#define CANIF_SETTRCVMODE_API                               0x0d
#define CANIF_GETTRCVMODE_API                               0x0e
#define CANIF_GETTRCVWAKEUPREASON_API                       0x0f
#define CANIF_SETTRCVWAKEUPMODE_API                         0x10
#define CANIF_CHECKWAKEUP_API                               0x11
#define CANIF_CHECKVALIDATION_API                           0x12
#define CANIF_TXCONFIRMATION_API                            0x13
#define CANIF_RXINDICATION_API                              0x14
#define CANIF_CONTROLLERBUSOFF_API                          0x16
#define CANIF_CONTROLLERMODEINDICATION_API                  0x17
#define CANIF_CANCELTRANSMIT_API                            0x18
#define CANIF_GETTXCONFIRMATIONSTATE_API                    0x19
#define CANIF_CONFIRMPNAVAILABILITY_API                     0x1a
#define CANIF_CLEARTRCVWUFFLAG_API                          0x1e
#define CANIF_CHECKTRCVWAKEFLAG_API                         0x1f
#define CANIF_CLEARTRCVWUFFLAGINDICATION_API                0x20
#define CANIF_CHECKTRCVWAKEFLAGINDICATION_API               0x21
#define CANIF_TRCVMODEINDICATION_API                        0x22
#define CANIF_SETICOMCONFIGURATION_API                      0x25
#define CANIF_CURRENTICOMCONFIGURATION_API                  0x26
#define CANIF_SETBAUDRATE_API                               0x27
#define CANIF_TRIGGERTRANSMIT_API                           0x41
/*******************************************************************************************************************/
/*  Development Errors                                                                                             */
/*******************************************************************************************************************/
#define CANIF_E_ALREADY_INITIALIZED                         06u
#define CANIF_E_PARAM_CANID                                 10u
#define CANIF_E_PARAM_HOH                                   12u
#define CANIF_E_PARAM_LPDU                                  13u
#define CANIF_E_PARAM_CONTROLLER                            14u
#define CANIF_E_PARAM_CONTROLLERID                          15u
#define CANIF_E_PARAM_WAKEUPSOURCE                          16u
#define CANIF_E_PARAM_TRCV                                  17u
#define CANIF_E_PARAM_TRCVMODE                              18u
#define CANIF_E_PARAM_TRCVWAKEUPMODE                        19u
#define CANIF_E_PARAM_CTRLMODE                              21u
#define CANIF_E_PARAM_PDU_MODE                              22u
#define CANIF_E_PARAM_POINTER                               20u
#define CANIF_E_UNINIT                                      30u
#define CANIF_E_INVALID_TXPDUID                             50u
#define CANIF_E_INVALID_RXPDUID                             60u
#define CANIF_E_INVALID_DLC                                 61u
#define CANIF_E_DATA_LENGTH_MISMATCH                        62u
#define CANIF_E_STOPPED                                     70u
#define CANIF_E_NOT_SLEEP                                   71u
#define CANIF_E_INIT_FAILED                                 80u
/*******************************************************************************************************************/
/*  Defines                                                                                                        */
/*******************************************************************************************************************/
#define CANIF_E_NO_ERROR                                    0xFFu
#define CANIF_SET_ONLINE                                    CANIF_ONLINE
#define CANIF_SET_TX_OFFLINE                                CANIF_TX_OFFLINE
#define CANIF_SET_RX_ONLINE                                 CANIF_ONLINE
/* Can Id type */
/*  00 CAN message with Standard CAN ID
    01 CAN FD frame with Standard CAN ID
    10 CAN message with Extended CAN ID
    11 CAN FD frame with Extended CAN ID */
#if (CANIF_EXTENDEDID_SUPPORT == STD_ON)
#define CANIF_CANID_MASK                                    0xC0000000u
#define CANIF_CANID_FD_CAN                                  0x40000000u
#define CANIF_CANID_EXTENDED_CAN                            0x80000000u
#else
#define CANIF_CANID_MASK                                    0xC000u
#define CANIF_CANID_FD_CAN                                  0x4000u
#define CANIF_CANID_EXTENDED_CAN                            0x8000u
#endif
#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
#define BUFFER_FIRST_PDU        					        (uint8)0
#define BUFFER_NOT_ALLOCATED                                (uint8)0xFF
/* Macro definition for Tx Queue */
#define Tx_QUEUE_READY								        (uint8)0
#define Tx_QUEUE_EMPTY								        (uint8)1
#define Tx_QUEUE_FULL									    (uint8)2
#define Tx_QUEUE_ERROR								        (uint8)0xFF
#endif
/*******************************************************************************************************************/
/*  Declaration of Public APIs                                                                                     */
/*******************************************************************************************************************/
/* This service Initializes internal and external interfaces of the CAN Interface
for the further processing. */
extern FUNC(void, CANIF_CODE) CanIf_Init(const CanIf_ConfigType* ConfigPtr);
/* This service calls the corresponding CAN Driver service for changing of
the CAN controller mode. */
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode(uint8 ControllerId, CanIf_ControllerModeType ControllerMode);
/* This service reports about the current status of the requested CAN controller. */
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerMode(uint8 ControllerId, CanIf_ControllerModeType* ControllerModePtr);
/* This service initiates a request for transmission of the CAN L-PDU specified
by the CanTxSduId and CAN related data in the L-SDU structure. */
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit(PduIdType CanIfTxSduId, const PduInfoType* CanIfTxInfoPtr);
/* This service sets the requested mode at the L-PDUs of a predefined
logical PDU channel. */
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode(uint8 ControllerId, CanIf_PduModeType PduModeRequest);
/* This service reports the current mode of a requested PDU channel. */
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetPduMode(uint8 ControllerId, CanIf_PduModeType* PduModePtr);
/* This service returns the version information of the called CAN Interface
module. */
extern FUNC(void, CANIF_CODE) CanIf_GetVersionInfo(Std_VersionInfoType* VersionInfo);
/* This service provides the CAN DLC and the received data of the requested
CanIfRxSduId to the calling upper layer. */
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReadRxPduData(PduIdType CanIfRxSduId, PduInfoType* CanIfRxInfoPtr);
/* This service returns the confirmation status (confirmation occurred or
not) of a specific static or dynamic CAN Tx L-PDU, requested by the
CanIfTxSduId. */
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadTxNotifStatus(PduIdType CanIfTxSduId);
/* This service returns the indication status (indication occurred or not) of a
specific CAN Rx L-PDU, requested by the CanIfRxSduId. */
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadRxNotifStatus(PduIdType CanIfRxSduId);
/* This service reconfigures the corresponding CAN identifier of the requested
CAN L-PDU. */
extern FUNC(void, CANIF_CODE) CanIf_SetDynamicTxId(PduIdType CanIfTxSduId, Can_IdType CanId);
#if (CANIF_TRCV_HANDLING == STD_ON)
/* This service changes the operation mode of the tansceiver TransceiverId,
via calling the corresponding CAN Transceiver Driver service. */
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvMode(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode);
/* This function invokes CanTrcv_GetOpMode and updates the parameter
TransceiverModePtr with the value OpMode provided by CanTrcv. */
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvMode(CanTrcv_TrcvModeType* TransceiverModePtr, uint8 TransceiverId);
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
/* This service returns the reason for the wake up of the transceiver
TransceiverId, via calling the corresponding CAN Transceiver Driver service. */
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason(uint8 TransceiverId, CanTrcv_TrcvWakeupReasonType* TrcvWuReasonPtr);
/* This function shall call CanTrcv_SetTrcvWakeupMode. */
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvWakeupMode(uint8 TransceiverId, CanTrcv_TrcvWakeupModeType TrcvWakeupMode);
#endif
/* This service indicates a transceiver state transition referring to the corresponding
CAN transceiver with the abstract CanIf TransceiverId. */
extern FUNC(void, CANIF_CODE) CanIf_TrcvModeIndication(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode);
#if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
/* This service indicates that the transceiver is running in PN communication
mode referring to the corresponding CAN transceiver with the abstract
CanIf TransceiverId. */
extern FUNC(void, CANIF_CODE) CanIf_ConfirmPnAvailability(uint8 TransceiverId);
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
/* Requests the CanIf module to clear the WUF flag of the designated CAN
transceiver. */
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag(uint8 TransceiverId);
/* Requests the CanIf module to check the Wake flag of the designated
CAN transceiver. */
extern FUNC(Std_ReturnType, CANIF_CODE)CanIf_CheckTrcvWakeFlag(uint8 TransceiverId);
/* This service indicates that the transceiver has cleared the WufFlag referring
to the corresponding CAN transceiver with the abstract CanIf
TransceiverId. */
extern FUNC(void, CANIF_CODE) CanIf_ClearTrcvWufFlagIndication(uint8 TransceiverId);
/* This service indicates that the check of the transceiver’s wake-up flag
has been finished by the corresponding CAN transceiver with the abstract
CanIf TransceiverId. This indication is used to cope with the asynchronous
transceiver communication. */
extern FUNC(void, CANIF_CODE) CanIf_CheckTrcvWakeFlagIndication(uint8 TransceiverId);
#endif
#endif
#endif
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
/* This service checks, whether an underlying CAN driver or a CAN
transceiver driver already signals a wakeup event. */
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
#endif
#if (CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION == STD_ON)
/* This service is performed to validate a previous wakeup event. */
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckValidation(EcuM_WakeupSourceType WakeupSource);
#endif
#if (CANIF_PUBLIC_TXCONFIRM_POLLING == STD_ON)
/* This service reports, if any TX confirmation has been done for the whole
CAN controller since the last CAN controller start. */
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_GetTxConfirmationState(uint8 ControllerId);
#endif
#if (CANIF_TRIGGER_TRANSMIT_SUPPORT == STD_ON)
/* Within this API, the upper layer module (called module) shall check
whether the available data fits into the buffer size reported by PduInfoPtr-
>SduLength. If it fits, it shall copy its data into the buffer provided by
PduInfoPtr->SduDataPtr and update the length of the actual copied data
in PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing
PduInfoPtr. */
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_TriggerTransmit(PduIdType TxPduId, PduInfoType* PduInfoPtr);
#endif
/* This service shall set the baud rate configuration of the CAN controller.
Depending on necessary baud rate modifications the controller might
have to reset. */
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetBaudrate(uint8 ControllerId, uint16 BaudRateConfigID);
/* This service shall change the Icom Configuration of a CAN controller to
the requested one. */
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetIcomConfiguration(uint8 ControllerId, IcomConfigIdType ConfigurationId);
/* This service shall inform about the change of the Icom Configuration of
a CAN controller using the abstract CanIf ControllerId. */
extern FUNC(void, CANIF_CODE) CanIf_CurrentIcomConfiguration(uint8 ControllerId, IcomConfigIdType ConfigurationId, IcomSwitch_ErrorType Error);
#endif
