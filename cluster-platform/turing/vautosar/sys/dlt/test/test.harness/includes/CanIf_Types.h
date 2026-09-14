/********************************************************************************************************************
|   File Name   : CanIf_Types.h
|
|   Description : Implementation of the AUTOSAR CanIf Types
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
#ifndef CANIF_TYPES_H
#define CANIF_TYPES_H

#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"
#include "CanIf_Cfg.h"
#include "EcuM_Cbk.h"

#if (CANIF_TRCV_HANDLING == STD_ON)
# include "CanTrcv_GeneralTypes.h"
#endif

/*******************************************************************************************************************/
/*  Defines                                                                                                        */
/*******************************************************************************************************************/
/* CanIf Types */
/*! @brief  This type contains the implementation-specific post build configuration structure .
    Dummy config is used as post build not supported*/
typedef struct
{
    uint8 Dummy;
}CanIf_ConfigType;

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

/*! @brief Return value of CAN L-PDU notification status */
typedef enum
{
    /*! @brief No transmit or receive event occurred for the requested L-PDU.*/
    CANIF_NO_NOTIFICATION = 0u,
    /*! @brief The requested Rx/Tx CAN L-PDU was successfully transmitted or received.*/
    CANIF_TX_RX_NOTIFICATION
} CanIf_NotifStatusType;

/* CanIf Types configuration Types */
/* CanIf Mailbox configuration */
/*! @brief Defines the Id value is of type Standard (11 bit) */
#define CANIF_CANID_TYPE_STANDARD   0U
/*! @brief Defines the Id value is of type Extended (29 bit) */
#define CANIF_CANID_TYPE_EXTENDED   1U
/*! @brief Defines the Id value is of type Mixed . It supports both  Standard and Extended) */
#define CANIF_CANID_TYPE_MIXED      2U
/* @brief Defines the Id Value type of CAN */
typedef uint8 CanIf_CanIdType;
/* @brief Defines Controller Id type */
typedef uint8 CanIf_ControllerIdType;
/*! @brief Defines the type Full-CAN hardware object*/
#define CANIF_CAN_HANDLE_TYPE_FULL_CAN      0U
/*! @brief Defines the type Basic-CAN hardware object*/
#define CANIF_CAN_HANDLE_TYPE_BASIC_CAN     1U
/*! @brief Defines the type (Full-CAN or Basic-CAN) of a hardware object*/
typedef uint8 CanIf_CanHandleType;

/*! @brief Defines the HardwareObject is used as Transmit object*/
#define CANIF_CAN_OBJECT_TYPE_TRANSMIT  0U
/*! @brief Defines the HardwareObject is used as Receive object*/
#define CANIF_CAN_OBJECT_TYPE_RECEIVE   1U
/*! @brief Defines if the HardwareObject is used as Transmit or as Receive object*/
typedef uint8 CanIf_CanObjectType;

/*! @brief Defines the type of CanIf PduId */
typedef uint16 CanIf_PduIdConfigIdType;

/*! @brief Defines the filter configuration .*/
typedef struct
{
    /*! @brief Defines the filter code.It is the value of CAN ID code. */
    uint32  CanHwFilterCode;
    /*! @brief Defines the filter mask. */
    uint32  CanHwFilterMask;
}CanIf_RxFilterType;

/*! @brief Defines the type of HOH Id*/
#if (CANIF_PUBLIC_HANDLE_TYPE_ENUM == CANIF_PUBLIC_HANDLE_TYPE_UINT8)
typedef uint8  CanIf_MailBoxConfigIdType;
#else
typedef uint16 CanIf_MailBoxConfigIdType
#endif

#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
/*! @brief Defines the buffer type as fifo */
#define CANIF_TX_BUFFER_HANDLING_TYPE_FIFO			0U
/*! @brief Defines the buffer type as None */
#define CANIF_TX_BUFFER_HANDLING_TYPE_NONE			1U
typedef uint8 CanIf_TxBufferHandlingType;
/*! @brief defines the datatype for the tx buffer id */
typedef uint16 CanIf_TxBufferIdType;

typedef struct
{
	/*! @brief Defines the Start index of Tx PDU*/
	PduIdType					TxPduStartIdx;
	/*! @brief Defines the End index of Tx PDU*/
	PduIdType					TxPduEndIdx;
	/*! @brief Defines the start Id of the buffer */
	CanIf_TxBufferIdType		TxBufferId;
	/*! @brief Defines the buffer size */
	PduLengthType				TxBufferSize;
	/*! @brief Defines the buffer type. Supported is FIFO */
	CanIf_TxBufferHandlingType 	TxBufferHandlingType;
	/*! @brief Defines the Controller ID*/
	uint8						CanCtrlId;
}CanIf_TxBufferConfigType;

typedef struct
{
	/*! @brief Defines the element start Id of the buffer */
	CanIf_TxBufferIdType		TxFifoElementStartId;
	/*! @brief Defines the element end Id of the buffer */
	CanIf_TxBufferIdType		TxFifoElementEndId;
	/*! @brief Defines the buffer size */
	PduLengthType				TxFifoElementSize;
}CanIf_TxBufferFifoConfigType;

#endif
/*! @brief Defines the mailbox HOH configuration of the CAN driver */
typedef struct
{
    /*! @brief Defines the CAN-ID value for the mailbox.*/
    Can_IdType              CanIdValue;
    /*! @brief Defines the filter configuration of this mailbox.*/
    CanIf_RxFilterType      RxFilterConfig;
    /*! @brief Defines the CAN-ID type of the mailbox.*/
    CanIf_CanIdType         CanIdType;
    /*! @brief Defines the controller Id to which the mailbox belongs*/
    uint8                   CanControllerId;
    /*! @brief Defines the number of hardware objects used to implement one HOH. */
    uint16                  CanHwObjectCount;
    /*! @brief Defines the type (Full-CAN or Basic-CAN) of a hardware object*/
    CanIf_CanHandleType     CanHandleType;
#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
    /*! @brief Defines Tx Buffer Index for this HOH */
    CanIf_TxBufferIdType    TxBufferId;
#endif
    /*! @brief Defines if the HardwareObject is used as Transmit or as Receive object*/
    CanIf_CanObjectType     CanObjectType;
    /*! @brief Defines the start id of the PDU which is mapped to this mailbox HOH */
    CanIf_PduIdConfigIdType PduStartId;
    /*! @brief Defines the end id of the PDU which is mapped to this mailbox HOH */
    CanIf_PduIdConfigIdType PduEndId;
}CanIf_MailBoxConfigType;

/* CanIf Rx PDU configuration */

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
/*! @brief Defines the type of receive CAN L-PDU's CAN Identifier
used by the CAN Driver for CAN L-PDU reception.*/
typedef uint8 CanIf_RxPduCanIdType;

/*! @brief Defines the function type for the receive notification function */
typedef void (*CanIf_RxNotificationFunctType)(PduIdType, const PduInfoType *);
/*! @brief Defines the type of the receive notification function Id*/
typedef uint8 CanIf_RxNotificationFunctIdType;

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

/*! @brief Defines the type of RX PDU Range configuration Id */
typedef uint8 CanIf_PduRangeConfigIdType;

/*! @brief Defines the CanIf Receive PDU configuration .
    TODO: Rx PDU buffer configuration needs to be updated */
typedef struct
{
    /*! @brief Defines the CAN Identifier value of the CanIf PDU*/
    Can_IdType                      RxPduCanId;
    /*! @brief Defines the CAN Identifier mask value of the CanIf PDU which is used for the filtering.*/
    uint32                          RxPduCanIdMask;
    /*! @brief Defines the type of receive CAN L-PDU's CAN Identifier
        used by the CAN Driver for CAN L-PDU reception.*/
    CanIf_RxPduCanIdType            RxPduCanIdType;
    /*! @brief Defines the upper layer PDU-ID .This id is used when calling upper layer APIs*/
    PduIdType                       UpperPduId;
    /*! @brief Defines the data length of the CanIf PDU */
    PduLengthType                   RxPduDlc;
    /*! @brief Defines the id of the Receive notification function */
    CanIf_RxNotificationFunctIdType RxNotificationFunctId;
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
	#if (CANIF_META_DATA_RX_SUPPORT == STD_ON)
	/*! @brief defines the meta data length */
	uint8								RxMetaDataLength;
	#endif
}CanIf_RxPduIdConfigType;

/* CanIf Tx PDU configuration */
/*! @brief Defines the type of CAN Identifier of the transmit CAN L-PDU as CAN frame
    with standard identifier (11 bits)*/
#define CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_CAN       0U
/*! @brief Defines the type of CAN Identifier of the transmit CAN L-PDU as CAN FD frame
    with standard identifier(11 bits)*/
#define CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_FD_CAN    1U
/*! @brief Defines the type of CAN Identifier of the transmit CAN L-PDU as CAN frame
    with extended identifier (29 bits)*/
#define CANIF_TX_PDU_CAN_ID_TYPE_EXTENDED_CAN       2U
/*! @brief Defines the type of CAN Identifier of the transmit CAN L-PDU as CAN FD frame
    with extended identifier (29 bits)*/
#define CANIF_TX_PDU_CAN_ID_TYPE_EXTENDED_FD_CAN    3U
/*! @brief Defines the type of CAN Identifier of the transmit CAN L-PDU used by the CAN
Driver module for CAN L-PDU transmission. */
typedef uint8 CanIf_TxPduCanIdType;

/*! @brief Specifies the CAN ID is defined at runtime */
#define CANIF_TX_PDU_TYPE_DYNAMIC   0U
/*! @brief Specifies the CAN ID is defined at compile-time.*/
#define CANIF_TX_PDU_TYPE_STATIC    1U
/*! @brief Defines the type of each transmit CAN L-PDU. */
typedef uint8 CanIf_TxPduType;

/*! @brief Defines the function type for the Tx trigger transmission */
typedef Std_ReturnType (*CanIf_TxTriggerTransmitFunctType) (PduIdType, PduInfoType*);
/*! @brief Defines the type of the Tx trigger transmission ID */
typedef uint8 CanIf_TxTriggerTransmitFunctIdType;
/*! @brief Defines the function type for the Tx confirmation*/
typedef void (*CanIf_TxConfirmationFunctType) (PduIdType);
/*! @brief Defines the type of the Tx confirmation ID */
typedef uint8 CanIf_TxConfirmationFunctIdType;

/*! @brief Defines the configuration of CanIf Tx PDU
    TODO: Rx PDU buffer configuration needs to be updated */
typedef struct
{
    /*! @brief Defines the CAN-ID value of Tx PDU*/
    Can_IdType                          TxPduCanId;
    /*! @brief Defines the CAN-ID mask value of Tx PDU*/
    uint32                              TxPduCanIdMask;
    /*! @brief Defines the CAN-ID transmit type of Tx PDU*/
    CanIf_TxPduCanIdType                TxPduCanIdType;
    /*! @brief Defines the data length of Tx PDU*/
    PduLengthType                       TxPduLength;
    /*! @brief Defines the Mailbox HOH Id for this PDU */
    CanIf_MailBoxConfigIdType           TxPduHTHId;
    /*! @brief Defines the upper layer PDU-ID .This id is used when calling upper layer APIs*/
    PduIdType                           UpperPduId;
    /*! @brief Defines the type of each transmit CAN L-PDU.(static/dynamic)*/
    CanIf_TxPduType                     TxPduType;
    #if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
    CanIf_TxBufferIdType                TxBufferId; 
    #endif
    /*! @brief Defines the function Id for transmit confirmation */
    CanIf_TxConfirmationFunctIdType     TxConfirmationFunctId;
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
	#if (CANIF_META_DATA_TX_SUPPORT == STD_ON)
	uint8								TxMetaDataLength;
	#endif
}CanIf_TxPduIdConfigType;

/* CanIf to Can Driver and Can Transceiver mapping configuration */
/*! @brief Defines the function type for CAN controller state transition API */
typedef Can_ReturnType (*CanIf_CanDrvSetControllerModeFunctType)(uint8, Can_StateTransitionType );
/*! @brief Defines the function type for CAN controller write API */
typedef Can_ReturnType (*CanIf_CanDrvWriteFunctType)(Can_HwHandleType, const Can_PduType* );
/*! @brief Defines the function type for CAN controller change Baud rate API */
typedef Std_ReturnType (*CanIf_CanDrvChangeBaudrateFunctType)(uint8, uint16 );
/*! @brief Defines the function type for CAN controller check Baud rate API */
typedef Std_ReturnType (*CanIf_CanDrvCheckBaudrateFunctType)(uint8, uint16 );
/*! @brief Defines the function type for CAN controller set Baud rate API */
typedef Std_ReturnType (*CanIf_CanDrvSetBaudrateFunctType)(uint8, uint16);
/*! @brief Defines the function type for CAN controller set ICOM configuration rate API */
typedef Std_ReturnType (*CanIf_CanDrvSetIcomConfigurationFunctType)(uint8, IcomConfigIdType);
/*! @brief Defines the function type for CAN controller CheckWakeup API */
typedef Std_ReturnType (*CanIf_CanDrvCheckWakeupType)(uint8);

/*! @brief Defines the type of Can diver function type configuration */
typedef uint8 CanIf_CanDrvFunctIdType;
/*! @brief Defines the configuration of CAN driver API's used by the CanIf module */
typedef struct
{
    /*! @brief Defines the function for CAN controller state transition API of the CAN Driver */
    CanIf_CanDrvSetControllerModeFunctType CanDrvSetControllerModeFunctPtr;
    /*! @brief Defines the function for CAN controller write API of the CAN Driver*/
    CanIf_CanDrvWriteFunctType CanDrvWriteFunctPtr;
    /*! @brief Defines the function for CAN controller change Baud rate API of the CAN Driver*/
    CanIf_CanDrvChangeBaudrateFunctType CanDrvChangeBaudrateFunctPtr;
    /*! @brief Defines the function for CAN controller check Baud rate API of the CAN Driver*/
    CanIf_CanDrvCheckBaudrateFunctType CanDrvCheckBaudrateFunctPtr;
#if (CANIF_SET_BAUD_RATE_API == STD_ON)
    /*! @brief Defines the function for CAN controller set Baud rate API of the CAN Driver*/
    CanIf_CanDrvSetBaudrateFunctType CanDrvSetBaudrateFunctPtr;
#endif
    /*! @brief Defines the function for CAN controller set ICOM configuration rate API of the CAN Driver*/
    CanIf_CanDrvSetIcomConfigurationFunctType CanDrvSetIcomConfigurationFunctPtr;
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
    /*! @brief Defines the function for CAN controller CheckWakeup API of the CAN Driver*/
    CanIf_CanDrvCheckWakeupType CanDrvCheckWakeupFunctPtr;
#endif
}CanIf_CanDrvFunctConfigType;

/*! @brief Defines the configuration of Controller Id to driver API configuration Id mapping */
typedef struct
{
    /*! @brief Defines the Id of CAN driver API's configuration */
    CanIf_CanDrvFunctIdType CanDrvFunctId;
}CanIf_CtrlIdtoCanDrvFunctMapConfigType;
#if (CANIF_TRCV_HANDLING == STD_ON)
/*! @brief Defines the type of Can diver function type configuration */
typedef uint8 CanIf_CanTrcvDrvFunctIdType;

/*! @brief Defines the function type for setting the mode of the Transceiver. */
typedef Std_ReturnType (*CanIf_CanTrcvSetOpModeFunctType)(uint8, CanTrcv_TrcvModeType);
/*! @brief Defines the function type for getting the mode of the Transceiver. */
typedef Std_ReturnType (*CanIf_CanTrcvGetOpModeFunctType) (uint8, CanTrcv_TrcvModeType*);
/*! @brief Defines the function type for controlling the wake-up events of the Transceiver
    according to TrcvWakeupMode*/
typedef Std_ReturnType (*CanIf_CanTrcvSetWakeupModeFunctType)(uint8, CanTrcv_TrcvWakeupModeType);
/*! @brief Defines the function type for checking the Wake-up event of the Transceiver. */
typedef Std_ReturnType (*CanIf_CanTrcvCheckWakeupFunctType)(uint8);
/*! @brief Defines the function type for getting the wake-up reason for the Transceiver. */
typedef Std_ReturnType (*CanIf_CanTrcvGetBusWuReasonFunctType)(uint8,CanTrcv_TrcvWakeupReasonType*);
/*! @brief Defines the function type for ClearTrcvWufFlag. */
typedef Std_ReturnType (*CanIf_CanTrcvClearTrcvWufFlagType)(uint8);
/*! @brief Defines the function type for CheckTrcvWakeFlag. */
typedef Std_ReturnType (*CanIf_CanTrcvCheckTrcvWakeFlagType)(uint8);

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
/*! @brief Defines the function type for indicating CAN controller state transition to the corresponding
    upper layer module .*/
typedef void (*CanIf_UserControllerModeIndicationFunctType) (uint8,CanIf_ControllerModeType);
/*! @brief Defines the function type for indicating a bus-off event to the corresponding upper layer
    module. */
typedef void (*CanIf_UserControllerBusOffFunctType) (uint8);
#if (CANIF_TRCV_HANDLING == STD_ON)
/*! @brief Defines the function type for indicating a CAN transceiver state transition to the corresponding
    upper layer module . */
typedef void (*CanIf_UserTrcvModeIndicationFunctType) (uint8, CanTrcv_TrcvModeType);
#endif
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
/*! @brief Defines the function type for indicating if a wake up event initiated from the wake up
    source (CAN controller or transceiver) after a former request to the CAN Driver or CAN Transceiver
    Driver module is valid. */
typedef void (*CanIf_UserValidateWakeupEventFunctType) (EcuM_WakeupSourceType);
/*! @brief Defines the function type for indicating that the CAN transceiver has cleared the WufFlag.
    This function is called in CanIf_ClearTrcvWufFlagIndication. */
typedef void (*CanIf_UserClearTrcvWufFlagIndicationFunctType) (uint8);
/*! @brief Defines the function type for indicating that the wake up flag in the CAN transceiver is set.
    This function is called in CanIf_CheckTrcvWakeFlagIndication.*/
typedef void (*CanIf_UserCheckTrcvWakeFlagIndicationFunctType) (uint8);
#endif
/*! @brief Defines the function type for indicating that the CAN transceiver is running in PN communication
    mode.*/
typedef void (*CanIf_UserConfirmPnAvailabilityFunctType) (uint8);
#if (CANIF_PUBLIC_ICOM_SUPPORT == STD_ON)
/*! @brief Defines the function type for indicating the change of the Icom Configuration of
a CAN controller using the abstract CanIf ControllerId.*/
typedef void (*CanIf_UserCurrentIcomConfigurationFunctType) (uint8, IcomConfigIdType, IcomSwitch_ErrorType);
#endif

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
    CanIf_UserCurrentIcomConfigurationFunctType     UserCurrentIcomConfigurationFunctPtr;
#endif
}CanIf_UserCallbackConfigType;
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
/*! type used for WakeupCtrlId */
typedef uint8 CanIf_WakeupCtrlIdType;
/*! type used for WakeUpTargetAddressOfWakeUpConfig*/
typedef uint8 CanIf_WakeUpTargetAddressConfigType;
/*! type used for WakeupTargetModuleConfig*/
typedef enum
{
  CANIF_WAKEUPREQUEST_NONE = 0u,
  CANIF_WAKEUPREQUEST_CAN  = 1u,
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
#endif /* CANIF_TYPES_H */
