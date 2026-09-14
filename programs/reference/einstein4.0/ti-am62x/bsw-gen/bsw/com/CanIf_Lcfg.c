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
 *    @file CanIf_Lcfg.c
 *    @ingroup CanIfConfiguration
 *    @brief This is CanIf Link time configuration source file. It contains definitions of Link time configuration
 *     parameters for the CanIf module.
 ********************************************************************************************************************/
/********************************************************************************************************************
 *  HEADER INCLUDES                                                                                                  *
 ********************************************************************************************************************/
#include "CanIf.h"
#include "CanIf_Lcfg.h"
#include "CanSM.h"
#include "CanSM_Cbk.h"
#include "Can.h"
#include "CanNm_Cfg.h"
#include "CanTp_Cfg.h"
#include "CanNm.h"
#include "CanNm_Cbk.h"
// #include "Can_Flexcan.h"
#include "EcuM_Cbk.h"
#include "PduR_CanIf.h"
#include "PduR_Cfg.h"
#include "CanTp.h"
#include "CanTp_Cbk.h"
#ifdef BOOT_KPI_LOG_EN
#include "boot_kpi_r5_asr.h"
#endif   /*BOOT_KPI_LOG_EN*/
/********************************************************************************************************************
 * #! GLOBAL VARIABLES                                                                                               *
 ********************************************************************************************************************/
#define CANIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/*! @brief It contains the CanIf status for each controller */
VAR(CanIf_CtrlInfoType, CANIF_VAR_NO_INIT)
CanIf_CtrlInfo[CANIF_NUM_OF_CAN_CONTROLLERS];
#if ((CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API == STD_ON) || (CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT == STD_ON))
/*! @brief It contains the CanIf Tx Confirmation Notify Status */
VAR(CanIf_NotifStatusType, CANIF_VAR_NO_INIT)
CanIf_TxNotifyStatus[CANIF_NUM_OF_TX_PDU];
#endif
#if (CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API == STD_ON)
/*! @brief It contains the CanIf Rx Indication Notify Status */
VAR(CanIf_NotifStatusType, CANIF_VAR_NO_INIT)
CanIf_RxNotifyStatus[CANIF_NUM_OF_RX_PDU];
#endif
#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
/*! @brief It contains the CanIf Tx fifo Status */
VAR(CanIf_TxBufferFifoStatusType, CANIF_VAR_NO_INIT)
CanIf_TxBufferFifoStatus[CANIF_NUM_OF_TX_FIFO];
/*! @brief It contains the CanIf Tx fifo element info */
VAR(CanIf_TxBufferFifoElementType, CANIF_VAR_NO_INIT)
CanIf_TxBufferFifoElement[CANIF_NUM_OF_TX_FIFO_ELEMENTS];
#endif
#if (CANIF_PUBLIC_READ_RX_PDU_DATA_API == STD_ON)
/*! @brief It contains the CanIf Rx buffer element info */
VAR(CanIf_RxBufferConfigType, CANIF_VAR_NO_INIT)
CanIf_RxBuffer[CANIF_MAX_RX_BUFFER_SIZE];
#endif

#if (CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API == STD_ON)
/*! @brief It contains the CanIf dynamic pdu info */
VAR(CanIf_DynamicPduConfigType, CANIF_VAR_NO_INIT)
CanIf_DynamicPduConfig[CANIF_NUM_OF_TX_DYNAMIC_PDU];
#endif

#define CANIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

#if ((CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT == STD_ON) && (CANIF_WAKEUP_SUPPORT == STD_ON))
/*! @brief It contains the wakeup info of each controller */
VAR(boolean, CANIF_VAR_NO_INIT)
CanIf_WakeupDetected[CANIF_NUM_OF_CAN_CONTROLLERS];
#endif

#define CANIF_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "MemMap.h"

#if (CANIF_PUBLIC_READ_RX_PDU_DATA_API == STD_ON)
/*! @brief It is used for buffering the receive message */
VAR(uint8, CANIF_VAR_NO_INIT)
CanIf_RxReceiveBuffer[CANIF_MAX_RX_BUFFER_SIZE * CANIF_CFG_RX_MAXVALIDRXDLC];
/*! @brief It indicates the current Rx buffer index */
VAR(uint8, CANIF_VAR_NO_INIT)
CanIf_RxBufferIndex;
#endif

#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h"

#ifdef BOOT_KPI_LOG_EN
#define CANIF_START_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"
/*! @brief It indicates whether the first CAN message has been sent/processed. */
VAR(boolean, CANIF_VAR_INIT) CanIf_FirstCAN_Message = FALSE;
#define CANIF_STOP_SEC_VAR_INIT_BOOLEAN
#include "MemMap.h"
#endif

#ifdef BOOT_KPI_LOG_EN
#define CANIF_START_SEC_APPL_CODE
#include "MemMap.h"
/*! @brief The Stub Function Prototype for BootKPI- first CAN message out measurement*/
static FUNC(void,PDUR_CODE) CanIf_StubPduRTxConfirmation(PduIdType TxPduId,Std_ReturnType result);
#define CANIF_STOP_SEC_APPL_CODE
#include "MemMap.h"
#endif

/********************************************************************************************************************
 * #! CanIf const config  data                                                                                       *
 ********************************************************************************************************************/
#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* CanIf Mailbox configuration */
/*! @brief Defines the mailbox HOH configuration of the CAN driver
    Elements        : Description
    PduStartId      : the start id of the PDU which is mapped to this mailbox HOH
    PduEndId        : the end id of the PDU which is mapped to this mailbox HOH
    CanIdType       : the CAN-ID type of the mailbox
    CanControllerId : the controller Id to which the mailbox belongs
    CanHandleType   : the type (Full-CAN or Basic-CAN) of a hardware object
    CanObjectType   : the HardwareObject is used as Transmit or as Receive object
    TxBufferId      : Defines Tx Buffer Index for this HOH
                      Enabled only if CANIF_PUBLIC_TX_BUFFERING is STD_ON
*/
CONST(CanIf_MailBoxConfigType, CANIF_CONFIG_DATA)
CanIf_MailBoxConfig[CANIF_NUM_OF_MAILBOX] =
    {
        {0U, 0U, CANIF_CANID_TYPE_STANDARD, 0U, CANIF_CAN_HANDLE_TYPE_FULL_CAN, CANIF_CAN_OBJECT_TYPE_TRANSMIT}, /* Mailbox 0 - Cluster_Secure_Tx */
        {0U, 0U, CANIF_CANID_TYPE_STANDARD, 0U, CANIF_CAN_HANDLE_TYPE_FULL_CAN, CANIF_CAN_OBJECT_TYPE_TRANSMIT}, /* Mailbox 1 - CLuster_Tx_Normal_COM_HS */
        {0U, 0U, CANIF_CANID_TYPE_STANDARD, 0U, CANIF_CAN_HANDLE_TYPE_FULL_CAN, CANIF_CAN_OBJECT_TYPE_TRANSMIT}, /* Mailbox 2 - Cluster_Tx_Normal_COM_LS */
        {0U, 0U, CANIF_CANID_TYPE_STANDARD, 0U, CANIF_CAN_HANDLE_TYPE_FULL_CAN, CANIF_CAN_OBJECT_TYPE_TRANSMIT}, /* Mailbox 3 - Cluster_Tx_Normal_COM_MS */
        {0U, 0U, CANIF_CANID_TYPE_STANDARD, 0U, CANIF_CAN_HANDLE_TYPE_FULL_CAN, CANIF_CAN_OBJECT_TYPE_TRANSMIT}, /* Mailbox 4 - Cluster_Tx_Reduced_Com */
        {0U, 0U, CANIF_CANID_TYPE_STANDARD, 0U, CANIF_CAN_HANDLE_TYPE_FULL_CAN, CANIF_CAN_OBJECT_TYPE_TRANSMIT}, /* Mailbox 5 - Debug_Frame_1 */
        {0U, 0U, CANIF_CANID_TYPE_STANDARD, 0U, CANIF_CAN_HANDLE_TYPE_FULL_CAN, CANIF_CAN_OBJECT_TYPE_TRANSMIT}, /* Mailbox 6 - Debug_Frame_2 */
        {0U, 0U, CANIF_CANID_TYPE_STANDARD, 0U, CANIF_CAN_HANDLE_TYPE_FULL_CAN, CANIF_CAN_OBJECT_TYPE_TRANSMIT}, /* Mailbox 7 - Debug_Frame_3 */
        {0U, 0U, CANIF_CANID_TYPE_STANDARD, 0U, CANIF_CAN_HANDLE_TYPE_FULL_CAN, CANIF_CAN_OBJECT_TYPE_TRANSMIT}, /* Mailbox 8 - Debug_Frame_4 */
        {0U, 0U, CANIF_CANID_TYPE_STANDARD, 0U, CANIF_CAN_HANDLE_TYPE_FULL_CAN, CANIF_CAN_OBJECT_TYPE_TRANSMIT}, /* Mailbox 9 - Debug_Frame_5 */
        {0U, 0U, CANIF_CANID_TYPE_STANDARD, 0U, CANIF_CAN_HANDLE_TYPE_FULL_CAN, CANIF_CAN_OBJECT_TYPE_TRANSMIT}, /* Mailbox 10 - Diag_Resp_USDT */
        {0U, 0U, CANIF_CANID_TYPE_STANDARD, 0U, CANIF_CAN_HANDLE_TYPE_FULL_CAN, CANIF_CAN_OBJECT_TYPE_TRANSMIT}, /* Mailbox 11 - Diag_Resp_UUDT */
        {0U, 0U, CANIF_CANID_TYPE_STANDARD, 0U, CANIF_CAN_HANDLE_TYPE_FULL_CAN, CANIF_CAN_OBJECT_TYPE_TRANSMIT}, /* Mailbox 12 - IC_NMPDU */
        {0U ,4U ,CANIF_CANID_TYPE_STANDARD ,0U,CANIF_CAN_HANDLE_TYPE_BASIC_CAN ,CANIF_CAN_OBJECT_TYPE_RECEIVE },/* Mailbox 13 - CAN0_BasicRx */
        {0U, 0U, CANIF_CANID_TYPE_MIXED, 1U, CANIF_CAN_HANDLE_TYPE_FULL_CAN, CANIF_CAN_OBJECT_TYPE_TRANSMIT},    /* Mailbox 14 - CAN1_Tx */
        {0U, 4U, CANIF_CANID_TYPE_STANDARD, 1U, CANIF_CAN_HANDLE_TYPE_BASIC_CAN, CANIF_CAN_OBJECT_TYPE_RECEIVE}  /* Mailbox 15 - CAN1_BasicRx */
};

/*! @brief Defines the function config for the receive notification function */
CONST(CanIf_RxNotificationFunctType, CANIF_CONFIG_DATA)
CanIf_RxNotificationFunctConfig[CANIF_NUM_OF_RX_NOTIFICATION_FUNCTION] =
    {
        /*CanIf_RxNotificationFunctPtr*/
        &PduR_CanIfRxIndication,
        &CanTp_RxIndication,
        &CanNm_RxIndication};

/*! @brief Defines the CanIf Receive PDU configuration .
    Elements                : Description
    RxPduCanId              : the CAN Identifier value of the CanIf PDU
    RxPduDlc                : the data length of the CanIf PDU
    UpperPduId              : the upper layer PDU-ID
    RxNotificationFunctId   : the id of the Receive notification function
    RxCanIdMaskIdx          : the can id mask index value
    RxMetaDataLength        : the meta data length
                              Enabled only if CANIF_META_DATA_RX_SUPPORT is STD_ON
    RxPduReadDataOption     : the support for the API for reading the received L-SDU data for this PDU
                              Enabled only if CANIF_PUBLIC_READ_RX_PDU_DATA_API is STD_ON
    RxPduReadNotifyStatusOption  : the support for the API for reading the notification status for this PDU
                              Enabled only if CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API is STD_ON
    RxRangePduEnabled       : whether the PDU range functionality is enabled for software filtering
                              Enabled only if CANIF_RX_PDU_RANGE_SUPPORT is STD_ON
    RxRangePduConfigId      : the range PDU configuration.
                              Enabled only if CANIF_RX_PDU_RANGE_SUPPORT is STD_ON
    RxHashTableId           : the HashTable Id for this buffer
                              Enabled only if CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_TABLE is supported
 */
CONST(CanIf_RxPduIdConfigType, CANIF_CONFIG_DATA)
CanIf_RxPduIdConfig[CANIF_NUM_OF_RX_PDU] =
    {
        {0x100, 8U, PDUR_SRC_VEHICLE_CONTROL, 0U, 0U},      /* 0 VehicleControl */
        {0x101, 3U, PDUR_SRC_ILLUM_CONTROL, 0U, 0U},        /* 1 ILLUM_CONTROL */
        {0x102, 7U, PDUR_SRC_ABS, 0U, 0U},                  /*2 ABS_Message*/
        {0x500, 8U, CANNM_PDU_NM_COORD_NMPDU, 2U, 0U},      /* 3 NM_CoOrd_NMPDU */
        {0x700, 64U, CANTP_PDU_DIAG_REQ_PHYSICAL, 1U, 0U},   /* 4 DIAG_REQ_PHYSICAL */
        {0x7DF, 64U, CANTP_PDU_DIAG_REQ_FUNCTIONAL, 1U, 0U} /* 5 DIAG_REQ_FUNCTIONAL */
};

/*! @brief Defines the CanIf transmit confirmation function configuration .*/
CONST(CanIf_TxConfirmationFunctType, CANIF_CONFIG_DATA)
CanIf_TxConfirmationFunctConfig[CANIF_NUM_OF_TX_CONFIRMATION_FUNCTION] =
    {
        /* CanIf_TxConfirmationFunct */
        #ifdef BOOT_KPI_LOG_EN
        &CanIf_StubPduRTxConfirmation,
        #else
        &PduR_CanIfTxConfirmation,
        #endif
        &CanTp_TxConfirmation,
        &CanNm_TxConfirmation};

/*! @brief Defines the CanIf Receive PDU configuration .
    Elements                    : Description
    TxPduCanId                  : the CAN-ID value of Tx PDU
    TxPduLength                 : the data length of Tx PDU
    UpperPduId                  : the upper layer PDU-ID
    TxPduHTHId                  : the Mailbox HOH Id for this PDU
    TxPduCanIdType              : the CAN-ID transmit type of Tx PDU
    TxConfirmationFunctId       : the function Id for transmit confirmation
    TxCanIdMaskIdx              : the index of the filter mask configuration table
                                  Enabled only if CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API is STD_ON
    TxPduType                   : the type of each transmit CAN L-PDU.(static/dynamic)
                                  Enabled only if CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API is STD_ON
    TxBufferId                  : the tx buffer id
                                  Enabled only if CANIF_PUBLIC_TX_BUFFERING is STD_ON
    TxMetaDataLength            : tx meta data length
                                  Enabled only if CANIF_META_DATA_TX_SUPPORT is STD_ON
    TxPduPnFilterPdu            : whether this PDU is configured for the Partial networking functionality
                                  Enabled only if CANIF_PUBLIC_PN_FILTER_SUPPORT is STD_ON
    TxPduReadNotifyStatus       : Enables/Disables read transmit confirmation notification status supoprt
                                  Enabled only if CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API is STD_ON
    TxTriggerTransmit           : whether TriggerTransmit enabled or not
                                  Enabled only if CANIF_TRIGGER_TRANSMIT_SUPPORT is STD_ON
    TxTriggerTransmitFunctId    : function Id for trigger transmit
                                  Enabled only if CANIF_TRIGGER_TRANSMIT_SUPPORT is STD_ON
*/
CONST(CanIf_TxPduIdConfigType, CANIF_CONFIG_DATA)
CanIf_TxPduIdConfig[CANIF_NUM_OF_TX_PDU] =
    {
        {0x200, 3U, PDUR_SRC_CLUSTER_TX_NORMAL_COM_HS, 1U, CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_CAN, 0U}, /* 0 CLuster_Tx_Normal_COM_HS */
        {0x201, 2U, PDUR_SRC_CLUSTER_TX_NORMAL_COM_MS, 3U, CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_CAN, 0U}, /* 1 Cluster_Tx_Normal_COM_MS */
        {0x202, 4U, PDUR_SRC_CLUSTER_TX_NORMAL_COM_LS, 2U, CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_CAN, 0U}, /* 2 Cluster_Tx_Normal_COM_LS */
        {0x210, 1U, PDUR_SRC_CLUSTER_TX_REDUCED_COM, 4U, CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_CAN, 0U},   /* 3 Cluster_Tx_Reduced_Com */
        {0x300, 8U, PDUR_SRC_CLUSTER_SECURE_TX, 0U, CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_CAN, 0U},        /* 4 Cluster_Secure_Tx */
        {0x501, 8U, CANNM_PDU_IC_NMPDU, 12U, CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_CAN, 2U},               /* 5 IC_NMPDU */
        {0x550, 8U, PDUR_SRC_DEBUG_FRAME1, 5U, CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_CAN, 0U},             /* 6 Debug_Frame_1 */
        {0x551, 8U, PDUR_SRC_DEBUG_FRAME2, 6U, CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_CAN, 0U},             /* 7 Debug_Frame_2 */
        {0x552, 8U, PDUR_SRC_DEBUG_FRAME3, 7U, CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_CAN, 0U},             /* 8 Debug_Frame_3 */
        {0x553, 8U, PDUR_SRC_DEBUG_FRAME4, 8U, CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_CAN, 0U},             /* 9 Debug_Frame_4 */
        {0x554, 8U, PDUR_SRC_DEBUG_FRAME5, 9U, CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_CAN, 0U},             /* 10 Debug_Frame_5 */
        {0x608, 8U, CANTP_PDU_DIAG_RESP_UUDT, 11U, CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_CAN, 1U},         /* 11 Diag_Resp_UUDT */
        {0x708, 64U, CANTP_PDU_DIAG_RESP_USDT, 10U, CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_FD_CAN, 1U}          /* 12 Diag_Resp_USDT */
};

#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
/*! @brief Defines the configuration of Tx Buffer
    Elements                : Description
    TxPduStartIdx           : the Start index of Tx PDU
    TxPduEndIdx             : the End index of Tx PDU
    TxBufferSize            : the buffer size
    TxBufferId              : the start Id of the buffer
    TxBufferHandlingType    : the buffer type. Supported is FIFO
    CanCtrlId               : the Controller ID
*/
CONST(CanIf_TxBufferConfigType, CANIF_CONFIG_DATA)
CanIf_TxBufferConfig[CANIF_NUM_OF_TX_BUFFERS] =
    {
        {15u, 21u, 0u, 10u, CANIF_TX_BUFFER_HANDLING_TYPE_FIFO, 0u}};

/*! @brief Defines the configuration of Tx fifo Buffer
    Elements                : Description
    TxFifoElementStartId    : the element start Id of the buffer
    TxFifoElementEndId      : the element end Id of the buffer
    TxFifoElementSize       : the buffer size
*/
CONST(CanIf_TxBufferFifoConfigType, CANIF_CONFIG_DATA)
CanIf_TxBufferFifoConfig[CANIF_NUM_OF_TX_FIFO] =
    {
        {0u, 9u, 10u}};
#endif

/*! @brief Defines the configuration of CAN driver API's used by the CanIf module
    Elements                            : Description
    CanDrvSetControllerModeFunctPtr     : the function for CAN controller state transition API of the CAN Driver
    CanDrvWriteFunctPtr                 : the function for CAN controller write API of the CAN Driver
    CanDrvSetBaudrateFunctPtr           : the function for CAN controller set Baud rate API of the CAN Driver
                                          Enabled only if CANIF_SET_BAUD_RATE_API is STD_ON
    CanDrvSetIcomConfigurationFunctPtr  : the function for CAN controller set ICOM configuration API of the CAN Driver
                                          Enabled only if CANIF_PUBLIC_ICOM_SUPPORT is STD_ON
    CanDrvCheckWakeupFunctPtr           : the function for CAN controller CheckWakeup API of the CAN Driver
                                          Enabled only if CANIF_WAKEUP_SUPPORT is STD_ON
    CanGetCtrlErrorStateFunctPtr        : the function for CAN get controller error state API of the CAN driver
                                          Enabled only if ASR version is 4.3
    CanGetControllerModeFunctPtr        : the function for CAN get controller mode API of the CAN driver
                                          Enabled only if ASR version is 4.3
*/
CONST(CanIf_CanDrvFunctConfigType, CANIF_CONFIG_DATA)
CanIf_CanDrvFunctConfig[CANIF_NUM_OF_CAN_DRIVERS] =
    {
        {&Can_SetControllerMode,
         &Can_Write,
#if (CANIF_SET_BAUD_RATE_API == STD_ON)
         NULL_PTR,
#endif
#if (CANIF_PUBLIC_ICOM_SUPPORT == STD_ON)
         NULL_PTR
#endif
        }};

/*! @brief Defines the configuration of Controller Id to driver API configuration Id mapping
    Elements        : Description
    CanDrvFunctId   : the Id of CAN driver API's configuration
*/
CONST(CanIf_CtrlIdtoCanDrvFunctMapConfigType, CANIF_CONFIG_DATA)
CanIf_CtrlIdtoCanDrvFunctMapConfig[CANIF_NUM_OF_CAN_CONTROLLERS] =
    {
        /* CanDrvFunctId */
        0U};

#if (CANIF_TRCV_HANDLING == STD_ON)
/*! @brief Defines Defines the configuration of CAN Transceiver API's used by the CanIf module.
    Elements            : Description
    CanTrcvSetOpModeFunctPtr        : the function for setting the mode of the Transceiver
    CanTrcvGetOpModeFunctPtr        : the function for getting the mode of the Transceiver
    CanTrcvSetWakeupModeFunctPtr    : the function for controlling the wake-up events of the Transceiver
                                      Enabled only if CANIF_WAKEUP_SUPPORT is STD_ON
    CanTrcvCheckWakeupFunctPtr      : the function for checking the Wake-up event of the Transceiver.
                                      Enabled only if CANIF_WAKEUP_SUPPORT is STD_ON
    CanTrcvGetBusWuReasonFunctPtr   : the function for getting the wake-up reason for the Transceiver.
                                      Enabled only if CANIF_WAKEUP_SUPPORT is STD_ON
    CanTrcvClearTrcvWufFlagFunctPtr : the function to clear Transceiver wakeup flag.
                                      Enabled only if CANIF_WAKEUP_SUPPORT and CANIF_PUBLIC_PN_SUPPORTisis STD_ON
    CanTrcvCheckTrcvWakeFlagFunctPtr : the function to check Transceiver wakeup flag.
                                      Enabled only if CANIF_WAKEUP_SUPPORT  and CANIF_PUBLIC_PN_SUPPORTis STD_ON
*/
CONST(CanIf_TrcvDrvFunctConfigType,CANIF_CONFIG_DATA)  CanIf_CanTrcvFunctConfig[CANIF_NUM_OF_CAN_TRANSCEIVERS] =
{
    {
        &CanTrcv_SetOpMode,
         &CanTrcv_GetOpMode,
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
         NULL_PTR,
         NULL_PTR,
         NULL_PTR,
#if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
         NULL_PTR,
         NULL_PTR
#endif
#endif
    },
    {
        &CanTrcv_SetOpMode,
        &CanTrcv_GetOpMode,
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
#if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
        NULL_PTR,
        NULL_PTR
#endif
#endif
    }
};   

/*! @brief Defines the configuration of Controller Id to Transceiver driver configuration
    Elements            : Description
    TrcvDrvFunctId      : the transceiver Id
    TrcvWakeupSupport   : whether the transceiver supports Wake-up functionality
*/
CONST(CanIf_CtrlIdtoTrcvDrvMapConfigType,CANIF_CONFIG_DATA)  CanIf_CtrlIdtoTrcvDrvMapConfig[CANIF_NUM_OF_CAN_CONTROLLERS] =
    {
        /* {TrcvDrvFunctId           ,TrcvWakeupSupport } */
        {0U, FALSE},
    {1U ,FALSE }
};
#endif
/*! @brief Defines the configuration for the mode indication functions to the user.
    Elements                                : Description
    UserControllerModeIndicationFunctPtr    : the function for indicating CAN controller state transition
    UserControllerBusOffFunctPtr            : the function for indicating CAN controller a bus-off event
    UserTrcvModeIndicationFunctPtr          : the function for indicating CAN transceiver state transition
    UserValidateWakeupEventFunctPtr         : the function for indicating wake up event initiated from the wakeup source
                                              Enabled only if CANIF_WAKEUP_SUPPORT is STD_ON
    UserClearTrcvWufFlagIndicationFunctPtr  : the function for indicating wake up flag is cleared in CAN transceiver
    UserCheckTrcvWakeFlagIndicationFunctPtr : the function for indicating wake up flag is set in CAN transceiver
    UserConfirmPnAvailabilityFunctPtr       : the function for indicating CAN transceiver is in PN mode
    UserCurrentIcomConfigurationFunctPtr    : the function for indicating indicating current Icom configuration
                                              Enabled only if CANIF_PUBLIC_ICOM_SUPPORT is STD_ON
                                              Enabled only if CANIF_PUBLIC_ICOM_SUPPORT is STD_ON
*/
CONST(CanIf_UserCallbackConfigType, CANIF_CONFIG_DATA)
CanIf_UserCallbackConfig =
    {
        &CanSM_ControllerModeIndication,
        &CanSM_ControllerBusOff,
#if (CANIF_TRCV_HANDLING == STD_ON)
        CanSM_TransceiverModeIndication,
#endif
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
#endif
        NULL_PTR,
#if (CANIF_PUBLIC_ICOM_SUPPORT == STD_ON)
        NULL_PTR
#endif
};

#if (CANIF_WAKEUP_SUPPORT == STD_ON)
/*! @brief Defines the configuration for Wakeup Support.
    Elements        : Description
    WakeupSrcId     : Wake-up source identifier
    WakeupCtrlId    : CAN controller handle ID
    WakeupTargetId  : Logical handle ID of target (CAN controller / transceiver)
    WakeupTargetModuleConfig : Target for wake-up source: CAN controller / transceiver
*/
CONST(CanIf_WakeUpConfigType, CANIF_CONFIG_DATA)
CanIf_WakeUpConfig[CANIF_CFG_MAX_WAKEUPSOURCES] =
    {
        {32UL,
         0U,
         0U,
         CANIF_WAKEUPREQUEST_CAN}};
#endif
#if (CANIF_TRIGGER_TRANSMIT_SUPPORT == STD_ON)
/*! @brief Defines the function for the Tx trigger transmission config */
CONST(CanIf_TxTriggerTransmitFunctType, CANIF_CONFIG_DATA)
CanIf_TxTriggerTransmitFunctConfig[CANIF_NUM_OF_TX_TRIGGER_TRANSMIT] =
    {
        /* CanIfTriggerTransmit */
        &PduR_CanIfTriggerTransmit};
#endif

#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_TABLE)
/*! @brief Defines the key value pair for the Rx Hash table config
    Elements    : Description
    RxCanId     : the CanId which is used as key for Hash
    RxPduId     : the CanIf RxPduId which is used as Value for Hash
*/
CONST(CanIf_RxHashTableType, CANIF_CONFIG_DATA)
CanIf_RxHashTableMailBox20[CANIF_RX_HASH_TABLE_MAILBOX20_SIZE] =
    {
        /* RxCanId, RxPduId */
        {0x100, 20}};

/*! @brief Defines the Rx Hash table configuration
    Elements                : Description
    RxHashTableSize         : the size of the hash table
    RxHash2PrimeNum         : the prime number used in Hash2 algorithm
    RxHashTableEmptyValue   : the Empty Value to be used in the Hash table
    pRxRxHashTableRef       : the reference to the Hash table
*/
CONST(CanIf_RxHashTableConfigType, CANIF_CONFIG_DATA)
CanIf_RxHashTableConfig[CANIF_RX_NUM_OF_HASH_TABLE] =
    {
        /*{ RxHashTableSize, RxHash2PrimeNum, RxHashTableEmptyValue, pRxRxHashTableRef }*/
        {CANIF_RX_HASH_TABLE_MAILBOX20_SIZE, 7U, 0U, &CanIf_RxHashTableMailBox20[0]}};
#endif

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_32
#include "MemMap.h"

/*! @brief defines the configuration for the Rx filter mask   */
CONST(uint32, CANIF_CONFIG_DATA)
CanIf_RxCanIdMaskConfig[CANIF_NUM_OF_RX_CAN_ID_MASKS] =
    {
        0x7FFU,
        0x1FFFFFFFU};

#if (CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API == STD_ON)
/*! @brief defines the configuration for the Tx filter mask   */
CONST(uint32, CANIF_CONFIG_DATA)
CanIf_TxCanIdMaskConfig[CANIF_NUM_OF_TX_CAN_ID_MASKS] =
    {
        0x7FFU,
        0x1FFFFFFFU};
#endif

#define CANIF_STOP_SEC_CONFIG_DATA_32
#include "MemMap.h"

#ifdef BOOT_KPI_LOG_EN
#define CANIF_START_SEC_APPL_CODE
#include "MemMap.h"
static FUNC(void,PDUR_CODE) CanIf_StubPduRTxConfirmation(PduIdType TxPduId,Std_ReturnType result)
{
    if(CanIf_FirstCAN_Message == FALSE)
    {
        BOOT_KPI_LOG(KPI_ID_VIP_FIRST_CAN_MSGOUT, "CAN_MSG_OUT");
        CanIf_FirstCAN_Message = TRUE;
    }
    PduR_CanIfTxConfirmation(TxPduId,result);
}
#define CANIF_STOP_SEC_APPL_CODE
#include "MemMap.h"
#endif

/*******************************************************************************************************************
 *                                 END OF FILE                                                                      *
 ********************************************************************************************************************/
