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
*    @file CanIf_Cfg.h
*    @ingroup CanIfConfiguration
*    @brief This is CanIf Pre-compile time configuration header file. It contains definitions of pre-compile time 
*    configuration parameters for the CanIf module.
*    @defgroup CanIfConfiguration
*    @brief This contains the configuration files for the CanIf module.
********************************************************************************************************************/
#ifndef CANIF_CFG_H
#define CANIF_CFG_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "CanIf_Types.h"
#include "EcuM_Cbk.h"
#include "EcuM.h"

/********************************************************************************************************************
*  #! Precompile Configuration                                                                                      *
********************************************************************************************************************/
/*! @brief Enables/Disables the support for Default Error Tracer (Det) detection */
#define CANIF_PUBLIC_DEV_ERROR_DETECT                   STD_ON
/*! @brief Enables/Disables the support for dynamic ID handling using L-SDU MetaData */
#define CANIF_META_DATA_SUPPORT                         STD_OFF
/*! @brief Enables/Disables the support for dummy API for upper layer modules which allows to
    request the cancellation of an I-PDU */
#define CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT            STD_ON
/*! @brief Enables/Disables the support for Pretended Network features in CanIf */
#define CANIF_PUBLIC_ICOM_SUPPORT                       STD_ON
/*! @brief Enables/Disables the support for multiple CAN Drivers */
#define CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT               STD_OFF
/*! @brief Enables/Disables the support for Partial Network features in CanIf */
#define CANIF_PUBLIC_PN_SUPPORT                         STD_OFF
/*! @brief Enables/Disables the support for the API CanIf_ReadRxPduData() for reading
    received L-SDU data */
#define CANIF_PUBLIC_READ_RX_PDU_DATA_API               STD_OFF
/*! @brief Enables/Disables the support for the API for reading the notification status of
    receive L-PDUs */
#define CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API      STD_OFF
/*! @brief Enables/Disables the support for the API for reading the notification status of
    transmit L-PDUs */
#define CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API      STD_OFF
/*! @brief Enables/Disables the support for the API for reconfiguration of the CAN Identifier
    for each Transmit L-PDU. */
#define CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API              STD_ON
/*! @brief Enables/Disables the support for the buffering of transmit L-PDUs (rejected by the
    CanDrv) within the CAN Interface module */
#define CANIF_PUBLIC_TX_BUFFERING                       STD_ON
/*! @brief Enables/Disables the support for the API to poll for Tx Confirmation state. */
#define CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT         STD_OFF
/*! @brief Enables/Disables the support for the wake-up event validation by NM message.
    If disabled, all received messages corresponding to a configured Rx PDU shall validate such a wake-up event*/
#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM           STD_OFF
/*! @brief Enables/Disables the support for the wake up validation. */
#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT         STD_OFF
/*! @brief Enables/Disables the support for the the CanIf_SetBaudrate API to change the baud rate of
    a CAN Controller. */
#define CANIF_SET_BAUD_RATE_API                         STD_ON
/*! @brief Enables/Disables the support for the CanIf_TriggerTransmit API. */
#define CANIF_TRIGGER_TRANSMIT_SUPPORT                  STD_ON
/*! @brief Enables/Disables the support for the TxOffLineActive feature. */
#define CANIF_TX_OFFLINE_ACTIVE_SUPPORT                 STD_ON
/*! @brief Enables/Disables the support for the API for reading the version information about
    the CAN Interface. */
#define CANIF_VERSION_INFO_API                          STD_OFF
/*! @brief Enables/Disables the support for the CanIf_CheckWakeup API. */
#define CANIF_WAKEUP_SUPPORT                            STD_ON
/* Private config */
/*! @brief This parameter defines if the buffer element length shall be fixed to 8 . */
#define CANIF_FIXED_BUFFER                              STD_OFF
/*! @brief Enables/Disables the support of DLC check feature */
#define CANIF_PRIVATE_DLC_CHECK                         STD_OFF
/*! @brief Enables/Disables the support for TTCAN */
#define CANIF_SUPPORT_TTCAN                             STD_OFF
/*! @brief  Defines the software filter mechanism as Linear Filter method */
#define CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_LINEAR       0U
/*! @brief  Defines the software filter mechanism as Binary Filter method */
#define CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_BINARY       1U
/*! @brief  Defines the software filter mechanism as Index Filter method */
#define CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_INDEX        2U
/*! @brief  Defines the software filter mechanism as Table Filter method */
#define CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_TABLE        3U
/*! @brief Selects the desired software filter mechanism for reception. */
#define CANIF_PRIVATE_SOFTWARE_FILTER_TYPE              CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_LINEAR
/*! @brief Defines the type of the Can_HwHandleType as uint8. */
#define CANIF_PUBLIC_HANDLE_TYPE_UINT8                  0U
/*! @brief Defines the type of the Can_HwHandleType as uint16*/
#define CANIF_PUBLIC_HANDLE_TYPE_UINT16                 1U
/*! @brief Defines the type of the Can_HwHandleType.
    For CAN hardware units with more than 255 HW objects the extended range shall be used (UINT16). */
#define CANIF_PUBLIC_HANDLE_TYPE_ENUM                   CANIF_PUBLIC_HANDLE_TYPE_UINT8
/********************************************************************************************************************
*  #! CanIf Internal feature support                                                                                *
********************************************************************************************************************/
/*! @brief  Enables/Disables the support of Rx PDU range . Enabled if any mailbox supports range */
#define CANIF_RX_PDU_RANGE_SUPPORT                      STD_OFF
/*! @brief  Enables/Disables the support of PN filter range  */
#define CANIF_PUBLIC_PN_FILTER_SUPPORT                  STD_OFF
/*! @brief  Enables/Disables the support of transceiver handling. */
#define CANIF_TRCV_HANDLING                             STD_OFF
/*! @brief  Enables/Disables the support of extended id support. */
#define CANIF_EXTENDEDID_SUPPORT                        STD_ON
/*! @brief  Enables/Disables the support Tx Meta data. */
#define CANIF_META_DATA_TX_SUPPORT                      STD_OFF
/*! @brief  Enables/Disables the support Rx Meta data. */
#define CANIF_META_DATA_RX_SUPPORT                      STD_OFF
/*! @brief Defines the dummy macro */
#ifndef CANIF_DUMMY_STATEMENT
#define CANIF_DUMMY_STATEMENT(v)
#endif
/********************************************************************************************************************
*  #! SW and AUTOSAR Version Macros                                                                                 *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the CanIf configuration software Major version */
#define CANIF_CFG_SW_MAJOR_VERSION                      1u
/*! @brief Defines the CanIf configuration software Minor version */
#define CANIF_CFG_SW_MINOR_VERSION                      0u
/*! @brief Defines the CanIf configuration software Patch version */
#define CANIF_CFG_SW_PATCH_VERSION                      0u
/* Autosar Release */
/*! @brief Defines the AUTOSAR Release Major version supported by ComM configuration  */
#define CANIF_CFG_AR_RELEASE_MAJOR_VERSION              4u
/*! @brief Defines the AUTOSAR Release Minor version supported by ComM configuration  */
#define CANIF_CFG_AR_RELEASE_MINOR_VERSION              3u
/*! @brief Defines the AUTOSAR Release patch version supported by ComM configuration  */
#define CANIF_CFG_AR_RELEASE_REVISION_VERSION           1u
/*******************************************************************************************************************
*  #! CanIf module configuration                                                                                   *
*******************************************************************************************************************/
/*! @brief Defines the number of mailbox supported */
#define CANIF_NUM_OF_MAILBOX                            5U
/*! @brief Defines the number of Tx Buffer supported */
#define CANIF_NUM_OF_TX_BUFFERS                         1U
/*! @brief Defines the number of Tx fifo Buffer supported */
#define CANIF_NUM_OF_TX_FIFO                            1U
/*! @brief Defines the mximum size of data buffer in Tx fifo */
#define CANIF_TX_FIFO_DATA_SIZE_MAX                     64U
/*! @brief Defines the depth of Tx fifo */
#define CANIF_NUM_OF_TX_FIFO_ELEMENTS                   10U
/*! @brief Defines the number of receive notification function supported */
#define CANIF_NUM_OF_RX_NOTIFICATION_FUNCTION           3U
/*! @brief Defines the number of transmit confirmation supported */
#define CANIF_NUM_OF_TX_CONFIRMATION_FUNCTION           3U
/*! @brief Defines the number of trigger transmit supported  Pdus*/
#define CANIF_NUM_OF_TX_TRIGGER_TRANSMIT                1U
/*! @brief Defines the number of CAN controllers supported */
#define CANIF_NUM_OF_CAN_CONTROLLERS                    2U
/*! @brief Defines the number of CAN Transceivers supported */
#define CANIF_NUM_OF_CAN_TRANSCEIVERS                   1U
/*! @brief Defines the number of CAN Drivers supported */
#define CANIF_NUM_OF_CAN_DRIVERS                        1U
/*! @brief Defines the number of CAN Transceiver Drivers supported */
#define CANIF_NUM_OF_TRANSCEIVER_DRIVERS                1U
/*! @brief Defines the ID for which no transceiver is supported */
#define CANIF_NO_CAN_TRANSCEIVER_ID                     255U
/*! @brief Defines the ID for which no Controller Id is supported */
#define CANIF_NO_CAN_CONTROLLER_ID                      255U
/*! @brief  Defines the maximum Rx DLC value. */
#define CANIF_CFG_RX_MAXVALIDRXDLC                      64U
/*! @brief  Defines the size of wakeup sources configuration . */
#define CANIF_CFG_MAX_WAKEUPSOURCES                     1U
/*! @brief  Defines the maximum Rx buffer . */
#define CANIF_MAX_RX_BUFFER_SIZE                        2U
/*! @brief  Defines the Nm Rx Pdu Id. */
#define CANIF_NM_RX_PDUID                               2U
/*! @brief Defines the CanIf Transmit PDU IDs */
#define CANIF_PDU_CLIMATIC_PANEL                        0U   
#define CANIF_PDU_E4_DIAG_RES                           1U
#define CANIF_PDU_NM_CENTERSTACK                        0U
/*! @brief Defines the number of transmit PDU supported */
#define CANIF_NUM_OF_TX_PDU                             2U
/*! @brief Defines the number of transmit Dynamic PDU supported */
#define CANIF_NUM_OF_TX_DYNAMIC_PDU                     1U
/*! @brief Defines the CanIf Receive PDU IDs */
#define CANIF_PDU_BODY_CNTRL7                           0U    
#define CANIF_PDU_EXTERNAL_LIGHTS                       1U
#define CANIF_PDU_E4_DIAG_PHY_REQ                       2U
#define CANIF_PDU_E4_DIAG_FUNC_REQ                      3U
/*! @brief Defines the number of receive PDU supported */
#define CANIF_NUM_OF_RX_PDU                             4U
/*! @brief Defines the maximum number of Rx canId mask */
#define CANIF_NUM_OF_RX_CAN_ID_MASKS                    2U

#if (CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API == STD_ON)
/*! @brief Defines the maximum number of Tx canId mask */
#define CANIF_NUM_OF_TX_CAN_ID_MASKS                    2U
#endif
 
#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_INDEX)
/*! @brief Defines the index group number for Index search algorithm */
#define CANIF_INDEX_FILTER_GROUP_NUMBER                 3u
#endif

#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_TABLE)
/*! @brief Defines the index group number for hash table supported */
#define CANIF_RX_NUM_OF_HASH_TABLE                      1u
/*! @brief Defines the hash table size */
#define CANIF_RX_HASH_TABLE_MAILBOX20_SIZE              1u
#endif

/********************************************************************************************************************
* #! CanIf types                                                                                                    *
* #! macro , typedef declaration                                                                                    *
********************************************************************************************************************/
#define CAN_OK  0u
#define CAN_NOT_OK 1u
/*! @brief Specifies the CAN ID is defined at runtime */
#define CANIF_TX_PDU_TYPE_DYNAMIC                       0U
/*! @brief Specifies the CAN ID is defined at compile-time.*/
#define CANIF_TX_PDU_TYPE_STATIC                        1U
/*! @brief Defines the type of each transmit CAN L-PDU. */
/*! @brief Defines the type of CAN Identifier of the transmit CAN L-PDU as CAN frame
    with standard identifier (11 bits)*/
#define CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_CAN           0U
/*! @brief Defines the type of CAN Identifier of the transmit CAN L-PDU as CAN FD frame
    with standard identifier(11 bits)*/
#define CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_FD_CAN        1U
/*! @brief Defines the type of CAN Identifier of the transmit CAN L-PDU as CAN frame
    with extended identifier (29 bits)*/
#define CANIF_TX_PDU_CAN_ID_TYPE_EXTENDED_CAN           2U
/*! @brief Defines the type of CAN Identifier of the transmit CAN L-PDU as CAN FD frame
    with extended identifier (29 bits)*/
#define CANIF_TX_PDU_CAN_ID_TYPE_EXTENDED_FD_CAN        3U
/*! @brief Defines the type of CAN Identifier of the transmit CAN L-PDU used by the CAN
Driver module for CAN L-PDU transmission. */
/*! @brief Defines the receive CAN L-PDU's CAN Identifier type as CAN 2.0 or CAN FD frame with
    standard identifier (11 bits)*/
#define CANIF_RX_PDU_CAN_ID_TYPE_STANDARD_CAN           0U
/*! @brief Defines the receive CAN L-PDU's CAN Identifier type as CAN FD frame with standard
    identifier (11 bits)*/
#define CANIF_RX_PDU_CAN_ID_TYPE_STANDARD_FD_CAN        1U
/*! @brief Defines the receive CAN L-PDU's CAN Identifier type as CAN 2.0 frame with standard
    identifier(11 bits)*/
#define CANIF_RX_PDU_CAN_ID_TYPE_STANDARD_NO_FD_CAN     2U
/*! @brief Defines the receive CAN L-PDU's CAN Identifier type as CAN 2.0 or CAN FD frame with
    extended identifier (29 bits)*/
#define CANIF_RX_PDU_CAN_ID_TYPE_EXTENDED_CAN           3U
/*! @brief Defines the receive CAN L-PDU's CAN Identifier type as CAN FD frame with extended
    identifier (29 bits)*/
#define CANIF_RX_PDU_CAN_ID_TYPE_EXTENDED_FD_CAN        4U
/*! @brief Defines the receive CAN L-PDU's CAN Identifier type as CAN 2.0 frame with extended
    identifier (29 bits)*/
#define CANIF_RX_PDU_CAN_ID_TYPE_EXTENDED_NO_FD_CAN     5U
/*! @brief Defines the Id value is of type Standard (11 bit) */
#define CANIF_CANID_TYPE_STANDARD                       0U
/*! @brief Defines the Id value is of type Extended (29 bit) */
#define CANIF_CANID_TYPE_EXTENDED                       1U
/*! @brief Defines the Id value is of type Mixed . It supports both  Standard and Extended) */
#define CANIF_CANID_TYPE_MIXED                          2U
/*! @brief Defines the HardwareObject is used as Transmit object*/
#define CANIF_CAN_OBJECT_TYPE_TRANSMIT                  0U
/*! @brief Defines the HardwareObject is used as Receive object*/
#define CANIF_CAN_OBJECT_TYPE_RECEIVE                   1U
/*! @brief Defines the buffer type as fifo */
#define CANIF_TX_BUFFER_HANDLING_TYPE_FIFO              0U
/*! @brief Defines the buffer type as None */
#define CANIF_TX_BUFFER_HANDLING_TYPE_NONE              1U
/* @brief Defines the Id Value type of CAN */
/*! @brief Defines the type Full-CAN hardware object*/
#define CANIF_CAN_HANDLE_TYPE_FULL_CAN                  0U
/*! @brief Defines the type Basic-CAN hardware object*/
#define CANIF_CAN_HANDLE_TYPE_BASIC_CAN                 1U
#if ((CANIF_CFG_AR_RELEASE_MAJOR_VERSION >= 4U) && (CANIF_CFG_AR_RELEASE_MINOR_VERSION >= 3U))
/*! @brief defines the controller state type for 4.3 version */
#define CanIf_ControllerModeType Can_ControllerStateType
#endif
/*! @brief Defines the type of CanIf PduId */
typedef uint8 CanIf_PduIdConfigIdType;
/*! @brief Defines the type of CanIf mask type */
typedef uint8 CanIf_RxCanIdMaskIdxType;
/* @brief Defines Controller Id type */
typedef uint8 CanIf_ControllerIdType;
#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
/*! @brief defines the datatype for the tx buffer id */
typedef uint16 CanIf_TxBufferIdType;
#endif
#if (CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API == STD_ON)
/*! @brief defines the tx canid mask index type */
typedef uint8 CanIf_TxCanIdMaskIdxType;
#endif
/*! @brief Defines the type of HOH Id*/
#if (CANIF_PUBLIC_HANDLE_TYPE_ENUM == CANIF_PUBLIC_HANDLE_TYPE_UINT8)
typedef uint8  CanIf_MailBoxConfigIdType;
#else
typedef uint16 CanIf_MailBoxConfigIdType
#endif
/*! @brief Defines the type of receive CAN L-PDU's CAN Identifier
used by the CAN Driver for CAN L-PDU reception.*/
typedef uint8 CanIf_RxPduCanIdType;
/*! @brief Defines the type of the receive notification function Id*/
typedef uint8 CanIf_RxNotificationFunctIdType;
/*! @brief Defines the type of RX PDU Range configuration Id */
typedef uint8 CanIf_PduRangeConfigIdType;
/*! @brief Defines the type of the Rx Hash table Id type */
typedef uint8 CanIf_RxHashTableIdType;
/*! @brief Defines the CanIf CanId type */
typedef uint8 CanIf_CanIdType;
/*! @brief Defines the type (Full-CAN or Basic-CAN) of a hardware object*/
typedef uint8 CanIf_CanHandleType;
/*! @brief Defines if the HardwareObject is used as Transmit or as Receive object*/
typedef uint8 CanIf_CanObjectType;
/*! @brief Defines the tx buffer handling type */
typedef uint8 CanIf_TxBufferHandlingType;
/*! @brief Defines the hash table size type */
typedef uint8 CanIf_RxHashTableSizeType;
/*! @brief Defines the hash2 prime number type size type */
typedef uint8 CanIf_RxHash2PrimeNumType;
/*! @brief Defines the Tx Pdu CanId type */
typedef uint8 CanIf_TxPduCanIdType;
/*! @brief Defines the Tx Pdu type */
typedef uint8 CanIf_TxPduType;
/*! @brief Defines the type of the Tx trigger transmission ID */
typedef uint8 CanIf_TxTriggerTransmitFunctIdType;
/*! @brief Defines the type of the Tx confirmation ID */
typedef uint8 CanIf_TxConfirmationFunctIdType;
/*! @brief Defines the function type for the receive notification function */
typedef P2FUNC(void,CANIF_APPL_CODE,CanIf_RxNotificationFunctType)
(
    PduIdType RxPduId,
    P2CONST(PduInfoType,AUTOMATIC,CANIF_APPL_CONST) PduInfoPtr)
;
/*! @brief Defines the function type for the Tx trigger transmission */
typedef P2FUNC(Std_ReturnType,CANIF_APPL_CODE,CanIf_TxTriggerTransmitFunctType)
(
    PduIdType TxPduId,
    P2VAR(PduInfoType,AUTOMATIC,CANIF_APPL_DATA) PduInfoPtr
);
/*! @brief Defines the function type for the Tx confirmation*/
typedef P2FUNC(void,CANIF_APPL_CODE,CanIf_TxConfirmationFunctType) (PduIdType TxPduId,Std_ReturnType result);
/*! @brief Defines the function type for CAN controller state transition API */
typedef P2FUNC(Can_ReturnType,CANIF_APPL_CODE,CanIf_CanDrvSetControllerModeFunctType)
(
    uint8 Controller,
    Can_ControllerStateType Transition
);
/*! @brief Defines the function type for CAN controller write API */
typedef P2FUNC(Can_ReturnType,CANIF_APPL_CODE,CanIf_CanDrvWriteFunctType)
(
    Can_HwHandleType Hth,
    P2CONST(Can_PduType,AUTOMATIC,CANIF_APPL_CONST) PduInfo
);
/*! @brief Defines the function type for CAN controller set Baud rate API */
typedef P2FUNC(Std_ReturnType,CANIF_APPL_CODE,CanIf_CanDrvSetBaudrateFunctType)
(
    uint8 Controller,
    uint16 BaudRateConfigID
);
/*! @brief Defines the function type for CAN controller set ICOM configuration rate API */
typedef P2FUNC(Std_ReturnType,CANIF_APPL_CODE,CanIf_CanDrvSetIcomConfigurationFunctType)
(
    uint8 Controller, 
    IcomConfigIdType ConfigurationId
);
/*! @brief Defines the function type for CAN controller CheckWakeup API */
typedef P2FUNC(Std_ReturnType,CANIF_APPL_CODE,CanIf_CanDrvCheckWakeupType)(uint8 Controller);
#if ((CANIF_CFG_AR_RELEASE_MAJOR_VERSION >= 4U) && (CANIF_CFG_AR_RELEASE_MINOR_VERSION >= 3U))
/*! @brief Defines the function type for the CAN controller get error state*/
typedef P2FUNC(Std_ReturnType,CANIF_APPL_CODE,CanIf_CanGetControllerErrorStateType)
(
    uint8 Controller,
    P2VAR(Can_ErrorStateType,AUTOMATIC,CANIF_APPL_DATA) ErrorStatePtr
);
/*! @brief Defines the function type for the get CAN controller state*/
typedef P2FUNC(Std_ReturnType,CANIF_APPL_CODE,CanIf_CanGetControllerModeType)
(
    uint8 Controller,
    P2VAR(CanIf_ControllerModeType,AUTOMATIC,CANIF_APPL_DATA) ControllerModePtr
);
#endif
/*! @brief Defines the type of Can diver function type configuration */
typedef uint8 CanIf_CanDrvFunctIdType;
#if (CANIF_TRCV_HANDLING == STD_ON)
/*! @brief Defines the type of Can diver function type configuration */
typedef uint8 CanIf_CanTrcvDrvFunctIdType;
/*! @brief Defines the function type for setting the mode of the Transceiver. */
typedef P2FUNC(Std_ReturnType,CANIF_APPL_CODE,CanIf_CanTrcvSetOpModeFunctType)
(
    uint8 Transceiver,
    CanTrcv_TrcvModeType OpMode
);
/*! @brief Defines the function type for getting the mode of the Transceiver. */
typedef P2FUNC(Std_ReturnType,CANIF_APPL_CODE,CanIf_CanTrcvGetOpModeFunctType)
(
    uint8 Transceiver, 
    P2VAR(CanTrcv_TrcvModeType,AUTOMATIC,CANIF_APPL_DATA) OpMode
);
/*! @brief Defines the function type for controlling the wake-up events of the Transceiver
    according to TrcvWakeupMode*/
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
typedef P2FUNC(Std_ReturnType,CANIF_APPL_CODE,CanIf_CanTrcvSetWakeupModeFunctType)
(
    uint8 Transceiver, 
    CanTrcv_TrcvWakeupModeType TrcvWakeupMode
);
/*! @brief Defines the function type for checking the Wake-up event of the Transceiver. */
typedef P2FUNC(Std_ReturnType,CANIF_APPL_CODE,CanIf_CanTrcvCheckWakeupFunctType) (uint8 Transceiver);
/*! @brief Defines the function type for getting the wake-up reason for the Transceiver. */
typedef P2FUNC(Std_ReturnType,CANIF_APPL_CODE,CanIf_CanTrcvGetBusWuReasonFunctType)
(
    uint8 Transceiver,
    P2VAR(CanTrcv_TrcvWakeupReasonType,AUTOMATIC,CANIF_APPL_DATA) reason
);
/*! @brief Defines the function type for ClearTrcvWufFlag. */
typedef P2FUNC(Std_ReturnType,CANIF_APPL_CODE,CanIf_CanTrcvClearTrcvWufFlagType) (uint8 Transceiver);
/*! @brief Defines the function type for CheckTrcvWakeFlag. */
typedef P2FUNC(Std_ReturnType,CANIF_APPL_CODE,CanIf_CanTrcvCheckTrcvWakeFlagType) (uint8 Transceiver);
#endif
#endif
/*! @brief Defines the function type for indicating CAN controller state transition to the corresponding
    upper layer module .*/
typedef P2FUNC(void,CANIF_APPL_CODE,CanIf_UserControllerModeIndicationFunctType)
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
);
/*! @brief Defines the function type for indicating a bus-off event to the corresponding upper layer
    module. */
typedef P2FUNC(void,CANIF_APPL_CODE,CanIf_UserControllerBusOffFunctType)(uint8 ControllerId);
#if (CANIF_TRCV_HANDLING == STD_ON)
/*! @brief Defines the function type for indicating a CAN transceiver state transition to the corresponding
    upper layer module . */
typedef P2FUNC(void,CANIF_APPL_CODE,CanIf_UserTrcvModeIndicationFunctType)
(
    uint8 TransceiverId,
    CanTrcv_TrcvModeType TransceiverMode
);
#endif
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
/*! @brief Defines the function type for indicating if a wake up event initiated from the wake up
    source (CAN controller or transceiver) after a former request to the CAN Driver or CAN Transceiver
    Driver module is valid. */
typedef P2FUNC(void,CANIF_APPL_CODE,CanIf_UserValidateWakeupEventFunctType) (EcuM_WakeupSourceType WakeupSource);
/*! @brief Defines the function type for indicating that the CAN transceiver has cleared the WufFlag.
    This function is called in CanIf_ClearTrcvWufFlagIndication. */
typedef P2FUNC(void,CANIF_APPL_CODE,CanIf_UserClearTrcvWufFlagIndicationFunctType) (uint8 TransceiverId);
/*! @brief Defines the function type for indicating that the wake up flag in the CAN transceiver is set.
    This function is called in CanIf_CheckTrcvWakeFlagIndication.*/
typedef P2FUNC(void,CANIF_APPL_CODE,CanIf_UserCheckTrcvWakeFlagIndicationFunctType) (uint8 TransceiverId);
#endif
/*! @brief Defines the function type for indicating that the CAN transceiver is running in PN communication
    mode.*/
typedef P2FUNC(void,CANIF_APPL_CODE,CanIf_UserConfirmPnAvailabilityFunctType) (uint8 TransceiverId);
#if (CANIF_PUBLIC_ICOM_SUPPORT == STD_ON)
/*! @brief Defines the function type for indicating the change of the Icom Configuration of
a CAN controller using the abstract CanIf ControllerId.*/
typedef P2FUNC(void,CANIF_APPL_CODE,CanIf_UserCurrentIcomConfigurationFunctType) 
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId, 
    IcomSwitch_ErrorType Error
);
#endif
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
/*! type used for WakeupCtrlId */
typedef uint8 CanIf_WakeupCtrlIdType;
/*! type used for WakeUpTargetAddressOfWakeUpConfig*/
typedef uint8 CanIf_WakeUpTargetAddressConfigType;
#endif

#if ((CANIF_CFG_AR_RELEASE_MAJOR_VERSION >= 4U) && (CANIF_CFG_AR_RELEASE_MINOR_VERSION >= 3U))
/*! @brief defines the controller state type for 4.3 version */
#define CANIF_CS_UNINIT     CAN_CS_UNINIT
#define CANIF_CS_STOPPED    CAN_CS_STOPPED
#define CANIF_CS_STARTED    CAN_CS_STARTED
#define CANIF_CS_SLEEP      CAN_CS_SLEEP
#else
/*! @brief Defines the Operating modes of a CAN controller */
typedef enum
{
    /*! @brief UNINIT mode. Default mode of each CAN controller after power on. */
    CANIF_CS_UNINIT = 0u,
    /*! @brief The CAN controller is halted and does not operate on the network. */
    CANIF_CS_STOPPED,
    /*! @brief The CAN controller is in full-operational mode */
    CANIF_CS_STARTED,
    /*! @brief The CAN controller is in SLEEP mode and can be woken up by an internal (SW) request
        or by a network event (This must be supported by CAN hardware.) */
    CANIF_CS_SLEEP
} CanIf_ControllerModeType;
#endif
/*! @brief Defines the PduMode of the channel .The PduMode defines its transmit or receive activity.
    Communication direction (transmission and/or reception) of the channel can be controlled
    separately or together by upper layers. */
typedef enum
{
    /*! @brief Transmit and receive path of the corresponding channel are disabled .
        i.e. no communication mode */
    CANIF_OFFLINE = 0u,
    /*! @brief Transmit path of the corresponding channel is disabled. The receive path
        is enabled.*/
    CANIF_TX_OFFLINE,
    /*! @brief Transmit path of the corresponding channel is in offline active mode.
        The receive path is disabled. This mode requires CanIfTxOfflineActiveSupport = TRUE.*/
    CANIF_TX_OFFLINE_ACTIVE,
    /*! @brief Transmit and receive path of the corresponding channel are enabled.
        i.e. full operation mode*/
    CANIF_ONLINE
} CanIf_PduModeType;
/*! @brief Defines the CanIf ctrl types */
typedef struct
{
    /*! @brief Variable to store Current ctrl mode */
    CanIf_ControllerModeType CurrentCtrlMode;
    /*! @brief Variable to store Current Pdu mode */
    CanIf_PduModeType  CurrentPduMode;
}CanIf_CtrlInfoType;

#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
/*! @brief Defines the CanIf fifo status types */
typedef struct
{
    /*! @brief write index of the fifo*/
    uint16 WriteIdx;
    /*! @brief read index of the fifo*/
    uint16 ReadIdx;
    /*! @brief element counter of the fifo */
    uint16 BufferCounter;
}CanIf_TxBufferFifoStatusType;

/*! @brief Defines the CanIf fifo element type */
typedef struct
{
    /*! @brief Can Id value */
    Can_IdType          CanId;
    /*! @brief defines the Can controller HW object id */
    Can_HwHandleType    TxHohId;
    /*! @brief defines the CanIf Hth Id i,e CanIf PduId */
    PduIdType           CanIfPduId;
    /*! @brief defines the length of the message */
    PduLengthType       Dlc;
    /*! @brief defines the controller id */
    uint8               CanCtrlId;
    /*! @brief contains the message data */
    uint8               TxBuffer[CANIF_TX_FIFO_DATA_SIZE_MAX];
}CanIf_TxBufferFifoElementType;
#endif
#if (CANIF_PUBLIC_READ_RX_PDU_DATA_API == STD_ON)
/*! @brief Defines the Rx buffering config type */
typedef struct
{
    /*! Variable to hold RxPduId */
    PduIdType CanIfRxPduId;
    /*! Variable to hold SduLength */
    PduLengthType CanIfSduLength;
    /*! Variable to hold Pdu Buffer */
    P2VAR(uint8,AUTOMATIC,CANIF_APPL_DATA) CanIfRxPduBuffer;
}CanIf_RxBufferConfigType;
#endif
#if (CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API == STD_ON)
/*! @brief Defines the Dynamic Pdu config type */
typedef struct
{
    /*! @brief defines the Can Id */
    Can_IdType CanId;
    /*! @brief defines the Can Tx SduId */
    PduIdType CanIfTxSduId;
    /*! @brief defines whether the recongiuration is allowed */
    boolean ReconfiguredSts;
}CanIf_DynamicPduConfigType;
#endif

/* CanIf Mailbox configuration */
#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
typedef struct
{
    /*! @brief Defines the Start index of Tx PDU*/
    PduIdType                   TxPduStartIdx;
    /*! @brief Defines the End index of Tx PDU*/
    PduIdType                   TxPduEndIdx;
    /*! @brief Defines the buffer size */
    PduLengthType               TxBufferSize;
    /*! @brief Defines the start Id of the buffer */
    CanIf_TxBufferIdType        TxBufferId;
    /*! @brief Defines the buffer type. Supported is FIFO */
    CanIf_TxBufferHandlingType  TxBufferHandlingType;
    /*! @brief Defines the Controller ID*/
    uint8                       CanCtrlId;
}CanIf_TxBufferConfigType;

typedef struct
{
    /*! @brief Defines the element start Id of the buffer */
    CanIf_TxBufferIdType        TxFifoElementStartId;
    /*! @brief Defines the element end Id of the buffer */
    CanIf_TxBufferIdType        TxFifoElementEndId;
    /*! @brief Defines the buffer size */
    PduLengthType               TxFifoElementSize;
}CanIf_TxBufferFifoConfigType;

#endif
/*! @brief Defines the mailbox HOH configuration of the CAN driver */
typedef struct
{
    /*! @brief Defines the start id of the PDU which is mapped to this mailbox HOH */
    CanIf_PduIdConfigIdType PduStartId;
    /*! @brief Defines the end id of the PDU which is mapped to this mailbox HOH */
    CanIf_PduIdConfigIdType PduEndId;
    /*! @brief Defines the CAN-ID type of the mailbox.*/
    CanIf_CanIdType         CanIdType;
    /*! @brief Defines the controller Id to which the mailbox belongs*/
    uint8                   CanControllerId;
    /*! @brief Defines the type (Full-CAN or Basic-CAN) of a hardware object*/
    CanIf_CanHandleType     CanHandleType;
    /*! @brief Defines if the HardwareObject is used as Transmit or as Receive object*/
    CanIf_CanObjectType     CanObjectType;
#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
    /*! @brief Defines Tx Buffer Index for this HOH */
    CanIf_TxBufferIdType    TxBufferId;
#endif
}CanIf_MailBoxConfigType;

/* CanIf Rx PDU configuration */
/*! @brief Defines the configuration type for the PDU Range which is used in reception filtering*/
typedef struct
{
    /*! @brief Lower CAN Identifier of a receive CAN L-PDU for identifier range
        definition, in which all CAN Ids shall pass the software filtering*/
    Can_IdType LowerPduIdValue;
    /*! @brief Upper CAN Identifier of a receive CAN L-PDU for identifier range
        definition, in which all CAN Ids shall pass the software filtering. */
    Can_IdType UpperPduIdValue;
}CanIf_PduRangeConfigType;
/*! @brief Defines the CanIf Receive PDU configuration .
    TODO: Rx PDU buffer configuration needs to be updated */
typedef struct
{
    /*! @brief Defines the CAN Identifier value of the CanIf PDU*/
    Can_IdType                      RxPduCanId;
    /*! @brief Defines the data length of the CanIf PDU */
    PduLengthType                   RxPduDlc;
    /*! @brief Defines the upper layer PDU-ID .This id is used when calling upper layer APIs*/
    PduIdType                       UpperPduId;
    /*! @brief Defines the id of the Receive notification function */
    CanIf_RxNotificationFunctIdType RxNotificationFunctId;
    /*! @brief Defines the can id mask index value */
    CanIf_RxCanIdMaskIdxType        RxCanIdMaskIdx;
    #if (CANIF_META_DATA_RX_SUPPORT == STD_ON)
    /*! @brief defines the meta data length */
    uint8                           RxMetaDataLength;
    #endif
    #if (CANIF_PUBLIC_READ_RX_PDU_DATA_API == STD_ON)
    /*! @brief Defines the support for the API for reading the received L-SDU data for this PDU */
    boolean                         RxPduReadDataOption;
    #endif
    #if (CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API == STD_ON)
    /*! @brief Defines the support for the API for reading the notification status for this PDU */
    boolean                         RxPduReadNotifyStatusOption;
    #endif
    #if (CANIF_RX_PDU_RANGE_SUPPORT == STD_ON)
    /*! @brief Defines whether the PDU range functionality is enabled for software filtering */
    boolean                         RxRangePduEnabled;
    /*! @brief Defines the range PDU configuration. */
    CanIf_PduRangeConfigIdType      RxRangePduConfigId;
    #endif
    #if ( CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_TABLE)
    /*! @brief Defines the HashTable Id for this buffer. */
    CanIf_RxHashTableIdType         RxHashTableId;  
    #endif
}CanIf_RxPduIdConfigType;

#if ( CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_TABLE)
/*! @brief Defines the type of key value pair for the Rx Hash table */
typedef struct 
{
    /*! @brief Defines the CanId which is used as key for Hash */
    Can_IdType                  RxCanId;
    /*! @brief Defines the CanIf RxPduId which is used as Value for Hash */
    CanIf_PduIdConfigIdType     RxPduId;
}CanIf_RxHashTableType;

/*! @brief Defines the type of Rx Hash table configuration */
typedef struct
{
    /*! @brief Defines the size of the hash table */
    CanIf_RxHashTableSizeType           RxHashTableSize;
    /*! @brief Defines the prime number used in Hash2 algorithm */
    CanIf_RxHash2PrimeNumType           RxHash2PrimeNum;
    /*! @brief Defines the Empty Value to be used in the Hash table */
    Can_IdType                          RxHashTableEmptyValue;  
    /*! @brief Defines the reference to the Hash table */
    P2CONST(CanIf_RxHashTableType,AUTOMATIC,CANIF_APPL_CONST) pRxRxHashTableRef;
}CanIf_RxHashTableConfigType;
#endif
    
/* CanIf Tx PDU configuration */
/*! @brief Defines the configuration of CanIf Tx PDU
    TODO: Rx PDU buffer configuration needs to be updated */
typedef struct
{
    /*! @brief Defines the CAN-ID value of Tx PDU*/
    Can_IdType                          TxPduCanId;
    /*! @brief Defines the data length of Tx PDU*/
    PduLengthType                       TxPduLength;
    /*! @brief Defines the upper layer PDU-ID .This id is used when calling upper layer APIs*/
    PduIdType                           UpperPduId;
    /*! @brief Defines the Mailbox HOH Id for this PDU */
    CanIf_MailBoxConfigIdType           TxPduHTHId;
    /*! @brief Defines the CAN-ID transmit type of Tx PDU*/
    CanIf_TxPduCanIdType                TxPduCanIdType;
    /*! @brief Defines the function Id for transmit confirmation */
    CanIf_TxConfirmationFunctIdType     TxConfirmationFunctId;
    #if (CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API == STD_ON)
    /*! @brief defines the index of the filter mask configuration table */
    CanIf_TxCanIdMaskIdxType            TxCanIdMaskIdx;
    /*! @brief Defines the type of each transmit CAN L-PDU.(static/dynamic)*/
    CanIf_TxPduType                     TxPduType;
    #endif
    #if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
    /*! @brief Defines the tx buffer id*/
    CanIf_TxBufferIdType                TxBufferId; 
    #endif
    #if (CANIF_META_DATA_TX_SUPPORT == STD_ON)
    /*! @brief Defines the tx meta data length */
    uint8                               TxMetaDataLength;
    #endif
    #if (CANIF_PUBLIC_PN_FILTER_SUPPORT == STD_ON)
    /*! @brief Defines whether this PDU is configured for the Partial networking functionality.*/
    boolean                             TxPduPnFilterPdu;
    #endif
    #if (CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API == STD_ON)
    /*! @brief Enables/Disables transmit confirmation for each transmit CAN L-SDU for reading
        its notification status API */
    boolean                             TxPduReadNotifyStatus;
    #endif
    #if(CANIF_TRIGGER_TRANSMIT_SUPPORT == STD_ON)
    /*! @brief Defines whether TriggerTransmit enabled or not */
    boolean                             TxTriggerTransmit;
    /*! @brief Defines function Id for trigger transmit */
    CanIf_TxTriggerTransmitFunctIdType  TxTriggerTransmitFunctId;
    #endif
}CanIf_TxPduIdConfigType;

/* CanIf to Can Driver and Can Transceiver mapping configuration */
/*! @brief Defines the configuration of CAN driver API's used by the CanIf module */
typedef struct
{
    /*! @brief Defines the function for CAN controller state transition API of the CAN Driver */
    CanIf_CanDrvSetControllerModeFunctType CanDrvSetControllerModeFunctPtr;
    /*! @brief Defines the function for CAN controller write API of the CAN Driver*/
    CanIf_CanDrvWriteFunctType CanDrvWriteFunctPtr;
#if (CANIF_SET_BAUD_RATE_API == STD_ON)
    /*! @brief Defines the function for CAN controller set Baud rate API of the CAN Driver*/
    CanIf_CanDrvSetBaudrateFunctType CanDrvSetBaudrateFunctPtr;
#endif
#if (CANIF_PUBLIC_ICOM_SUPPORT == STD_ON)
    /*! @brief Defines the function for CAN controller set ICOM configuration API of the CAN Driver*/
    CanIf_CanDrvSetIcomConfigurationFunctType CanDrvSetIcomConfigurationFunctPtr;
#endif
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
    /*! @brief Defines the function for CAN controller CheckWakeup API of the CAN Driver*/
    CanIf_CanDrvCheckWakeupType CanDrvCheckWakeupFunctPtr;
#endif
#if ((CANIF_CFG_AR_RELEASE_MAJOR_VERSION >= 4U) && (CANIF_CFG_AR_RELEASE_MINOR_VERSION >= 3U))
    /*!@ brief defines the function for CAN get controller error state API of the CAN driver */
    CanIf_CanGetControllerErrorStateType CanGetCtrlErrorStateFunctPtr;
    /*!@ brief defines the function for CAN get controller mode API of the CAN driver */
    CanIf_CanGetControllerModeType       CanGetControllerModeFunctPtr;
#endif
}CanIf_CanDrvFunctConfigType;

/*! @brief Defines the configuration of Controller Id to driver API configuration Id mapping */
typedef struct
{
    /*! @brief Defines the Id of CAN driver API's configuration */
    CanIf_CanDrvFunctIdType CanDrvFunctId;
}CanIf_CtrlIdtoCanDrvFunctMapConfigType;

#if (CANIF_TRCV_HANDLING == STD_ON)
/*! @brief Defines the configuration of Controller Id to Transceiver driver configuration */
typedef struct
{
    /*! @brief Defines the transceiver Id */
    CanIf_CanTrcvDrvFunctIdType TrcvDrvFunctId;
    /*! @brief Defines whether the transceiver supports Wake-up functionality*/
    boolean TrcvWakeupSupport;
}CanIf_CtrlIdtoTrcvDrvMapConfigType;

/*! @brief Defines the configuration of CAN Transceiver API's used by the CanIf module. */
typedef struct
{
    /*! @brief Defines the function for setting the mode of the Transceiver. */
    CanIf_CanTrcvSetOpModeFunctType CanTrcvSetOpModeFunctPtr;
    /*! @brief Defines the function for getting the mode of the Transceiver. */
    CanIf_CanTrcvGetOpModeFunctType CanTrcvGetOpModeFunctPtr;
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
    /*! @brief Defines the function for controlling the wake-up events of the Transceiver. */
    CanIf_CanTrcvSetWakeupModeFunctType CanTrcvSetWakeupModeFunctPtr;
    /*! @brief Defines the function for checking the Wake-up event of the Transceiver. */
    CanIf_CanTrcvCheckWakeupFunctType CanTrcvCheckWakeupFunctPtr;
    /*! @brief Defines the function for getting the wake-up reason for the Transceiver. */
    CanIf_CanTrcvGetBusWuReasonFunctType CanTrcvGetBusWuReasonFunctPtr;
#if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
    /*! @brief Defines the function to clear Transceiver wakeup flag. */
    CanIf_CanTrcvClearTrcvWufFlagType CanTrcvClearTrcvWufFlagFunctPtr;
    /*! @brief Defines the function to check Transceiver wakeup flag. */
    CanIf_CanTrcvCheckTrcvWakeFlagType CanTrcvCheckTrcvWakeFlagFunctPtr;
#endif
#endif
}CanIf_TrcvDrvFunctConfigType;
#endif

/* CanIf mode change Indication configuration */
/*! @brief Defines the configuration for the mode indication functions to the user.*/
typedef struct
{
    /*! @brief Defines the function for indicating CAN controller state transition to the corresponding
    upper layer module*/
    CanIf_UserControllerModeIndicationFunctType     UserControllerModeIndicationFunctPtr;
    /*! @brief Defines the function for indicating a bus-off event to the corresponding upper layer
    module.*/
    CanIf_UserControllerBusOffFunctType             UserControllerBusOffFunctPtr;
#if (CANIF_TRCV_HANDLING == STD_ON)
    /*! @brief Defines the function for indicating a CAN transceiver state transition to the corresponding
    upper layer module. */
    CanIf_UserTrcvModeIndicationFunctType           UserTrcvModeIndicationFunctPtr;
#endif
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
    /*! @brief Defines the function for indicating if a wake up event initiated from the wake up
    source (CAN controller or transceiver) after a former request to the CAN Driver or CAN Transceiver
    Driver module is valid. */
    CanIf_UserValidateWakeupEventFunctType          UserValidateWakeupEventFunctPtr;
    /*! @brief Defines the function for indicating that the CAN transceiver has cleared the WufFlag.
    This function is called in CanIf_ClearTrcvWufFlagIndication.*/
    CanIf_UserClearTrcvWufFlagIndicationFunctType   UserClearTrcvWufFlagIndicationFunctPtr;
    /*! @brief Defines the function for indicating that the wake up flag in the CAN transceiver is set.
    This function is called in CanIf_CheckTrcvWakeFlagIndication.*/
    CanIf_UserCheckTrcvWakeFlagIndicationFunctType  UserCheckTrcvWakeFlagIndicationFunctPtr;
#endif
    /*! @brief Defines the function for indicating that the CAN transceiver is running in PN communication
    mode.*/
    CanIf_UserConfirmPnAvailabilityFunctType        UserConfirmPnAvailabilityFunctPtr;
#if (CANIF_PUBLIC_ICOM_SUPPORT == STD_ON)
    /*! @brief Defines the function for indicating current Icom configuration  */
    CanIf_UserCurrentIcomConfigurationFunctType     UserCurrentIcomConfigurationFunctPtr;
#endif
}CanIf_UserCallbackConfigType;

#if (CANIF_WAKEUP_SUPPORT == STD_ON)
/*! type used for WakeupTargetModuleConfig*/
typedef enum
{
    /*! @brief Defines the wakeup request type as NONE */
    CANIF_WAKEUPREQUEST_NONE = 0u,
    /*! @brief Defines the wakeup request type as CAN */
    CANIF_WAKEUPREQUEST_CAN  = 1u,
    /*! @brief Defines the wakeup request type as TRCV */
    CANIF_WAKEUPREQUEST_TRCV = 2u
}CanIf_WakeUpTargetType;
/*! @brief Defines the configuration for Wakeup Support.*/
typedef struct
{
    /*! Wake-up source identifier */
    EcuM_WakeupSourceType WakeupSrcId;
    /*! CAN controller handle ID */
    CanIf_WakeupCtrlIdType WakeupCtrlId;
    /*! Logical handle ID of target (CAN controller / transceiver) */
    CanIf_WakeUpTargetAddressConfigType WakeupTargetId;
    /*! Target for wake-up source: CAN controller / transceiver */
    CanIf_WakeUpTargetType WakeupTargetModuleConfig;
}CanIf_WakeUpConfigType;
#endif

#endif /* CANIF_CFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
