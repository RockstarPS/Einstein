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
*    @file CanIf_Lcfg.h
*    @ingroup CanIfConfiguration
*    @brief This is CanIf link time configuration header file. It contains definitions of link time
*    configuration parameters for the CanIf module.
*    @defgroup CanIfConfiguration
*    @brief This contains the link time configurations for the CanIf module.
********************************************************************************************************************/
#ifndef CANIF_LCFG_H
#define CANIF_LCFG_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "CanIf_Cfg.h"
/********************************************************************************************************************
* #! GLOBAL VARIABLES                                                                                               *
********************************************************************************************************************/
#define CANIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

/*! @brief It contains the CanIf status for each controller */
extern VAR(CanIf_CtrlInfoType,CANIF_VAR_NO_INIT) CanIf_CtrlInfo[CANIF_NUM_OF_CAN_CONTROLLERS];
#if ((CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API == STD_ON) || (CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT == STD_ON))
/*! @brief It contains the CanIf Tx Confirmation Notify Status */
extern VAR(CanIf_NotifStatusType,CANIF_VAR_NO_INIT)  CanIf_TxNotifyStatus[CANIF_NUM_OF_TX_PDU];
#endif
#if (CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API == STD_ON)
/*! @brief It contains the CanIf Rx Indication Notify Status */
extern VAR(CanIf_NotifStatusType,CANIF_VAR_NO_INIT)  CanIf_RxNotifyStatus[CANIF_NUM_OF_RX_PDU];
#endif
#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
/*! @brief It contains the CanIf Tx fifo Status */
extern VAR(CanIf_TxBufferFifoStatusType,CANIF_VAR_NO_INIT)  CanIf_TxBufferFifoStatus[CANIF_NUM_OF_TX_FIFO];
/*! @brief It contains the CanIf Tx fifo element info */
extern VAR(CanIf_TxBufferFifoElementType,CANIF_VAR_NO_INIT)  CanIf_TxBufferFifoElement[CANIF_NUM_OF_TX_FIFO_ELEMENTS];
#endif
#if (CANIF_PUBLIC_READ_RX_PDU_DATA_API == STD_ON)
/*! @brief It contains the CanIf Rx buffer element info */
extern VAR(CanIf_RxBufferConfigType,CANIF_VAR_NO_INIT)  CanIf_RxBuffer[CANIF_MAX_RX_BUFFER_SIZE];
#endif

#if (CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API == STD_ON)
/*! @brief It contains the CanIf dynamic pdu info */
extern VAR(CanIf_DynamicPduConfigType,CANIF_VAR_NO_INIT)  CanIf_DynamicPduConfig[CANIF_NUM_OF_TX_DYNAMIC_PDU];
#endif

#define CANIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

#if ((CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT == STD_ON) && (CANIF_WAKEUP_SUPPORT == STD_ON))
/*! @brief It contains the wakeup info of each controller */
extern VAR(boolean,CANIF_VAR_NO_INIT)  CanIf_WakeupDetected[CANIF_NUM_OF_CAN_CONTROLLERS];
#endif

#define CANIF_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "MemMap.h"

#if (CANIF_PUBLIC_READ_RX_PDU_DATA_API == STD_ON)
/*! @brief It is used for buffering the receive message */
extern VAR(uint8,CANIF_VAR_NO_INIT)  CanIf_RxReceiveBuffer[CANIF_MAX_RX_BUFFER_SIZE * CANIF_CFG_RX_MAXVALIDRXDLC];
/*! @brief It indicates the current Rx buffer index */
extern VAR(uint8,CANIF_VAR_NO_INIT)  CanIf_RxBufferIndex;
#endif

#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h"

/********************************************************************************************************************
* #! CanIf const config  data                                                                                       *
********************************************************************************************************************/
#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

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
extern CONST(CanIf_MailBoxConfigType,CANIF_CONFIG_DATA) CanIf_MailBoxConfig[CANIF_NUM_OF_MAILBOX];
/*! @brief Defines the function config for the receive notification function */
extern CONST(CanIf_RxNotificationFunctType,CANIF_CONFIG_DATA) CanIf_RxNotificationFunctConfig[CANIF_NUM_OF_RX_NOTIFICATION_FUNCTION];
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
extern CONST(CanIf_RxPduIdConfigType,CANIF_CONFIG_DATA)  CanIf_RxPduIdConfig[CANIF_NUM_OF_RX_PDU];
/*! @brief Defines the CanIf transmit confirmation function configuration .*/
extern CONST(CanIf_TxConfirmationFunctType,CANIF_CONFIG_DATA)  CanIf_TxConfirmationFunctConfig[CANIF_NUM_OF_TX_CONFIRMATION_FUNCTION];
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
extern CONST(CanIf_TxPduIdConfigType,CANIF_CONFIG_DATA)  CanIf_TxPduIdConfig[CANIF_NUM_OF_TX_PDU];
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
extern CONST(CanIf_CanDrvFunctConfigType,CANIF_CONFIG_DATA)  CanIf_CanDrvFunctConfig[CANIF_NUM_OF_CAN_DRIVERS];
/*! @brief Defines the configuration of Controller Id to driver API configuration Id mapping 
    Elements        : Description
    CanDrvFunctId   : the Id of CAN driver API's configuration 
*/
extern CONST(CanIf_CtrlIdtoCanDrvFunctMapConfigType,CANIF_CONFIG_DATA)   CanIf_CtrlIdtoCanDrvFunctMapConfig[CANIF_NUM_OF_CAN_CONTROLLERS];
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
extern CONST(CanIf_TrcvDrvFunctConfigType,CANIF_CONFIG_DATA)  CanIf_CanTrcvFunctConfig[CANIF_NUM_OF_CAN_TRANSCEIVERS];
/*! @brief Defines the configuration of Controller Id to Transceiver driver configuration
    Elements            : Description
    TrcvDrvFunctId      : the transceiver Id
    TrcvWakeupSupport   : whether the transceiver supports Wake-up functionality
*/
extern CONST(CanIf_CtrlIdtoTrcvDrvMapConfigType,CANIF_CONFIG_DATA)  CanIf_CtrlIdtoTrcvDrvMapConfig[CANIF_NUM_OF_CAN_CONTROLLERS];
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
extern CONST(CanIf_UserCallbackConfigType,CANIF_CONFIG_DATA) CanIf_UserCallbackConfig;
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
/*! @brief Defines the configuration for Wakeup Support.
    Elements        : Description
    WakeupSrcId     : Wake-up source identifier
    WakeupCtrlId    : CAN controller handle ID
    WakeupTargetId  : Logical handle ID of target (CAN controller / transceiver)
    WakeupTargetModuleConfig : Target for wake-up source: CAN controller / transceiver
*/
extern CONST(CanIf_WakeUpConfigType,CANIF_CONFIG_DATA) CanIf_WakeUpConfig[CANIF_CFG_MAX_WAKEUPSOURCES];
#endif
#if (CANIF_TRIGGER_TRANSMIT_SUPPORT == STD_ON)
/*! @brief Defines the function for the Tx trigger transmission config */
extern CONST(CanIf_TxTriggerTransmitFunctType,CANIF_CONFIG_DATA) CanIf_TxTriggerTransmitFunctConfig[CANIF_NUM_OF_TX_TRIGGER_TRANSMIT];
#endif
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
extern CONST(CanIf_TxBufferConfigType,CANIF_CONFIG_DATA) CanIf_TxBufferConfig[CANIF_NUM_OF_TX_BUFFERS];
/*! @brief Defines the configuration of Tx fifo Buffer
    Elements                : Description
    TxFifoElementStartId    : the element start Id of the buffer
    TxFifoElementEndId      : the element end Id of the buffer
    TxFifoElementSize       : the buffer size 
*/
extern CONST(CanIf_TxBufferFifoConfigType,CANIF_CONFIG_DATA) CanIf_TxBufferFifoConfig[CANIF_NUM_OF_TX_FIFO];
#endif

#if ( CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_TABLE)
/*! @brief Defines the Rx Hash table configuration 
    Elements                : Description 
    RxHashTableSize         : the size of the hash table
    RxHash2PrimeNum         : the prime number used in Hash2 algorithm
    RxHashTableEmptyValue   : the Empty Value to be used in the Hash table
    pRxRxHashTableRef       : the reference to the Hash table
*/
extern CONST(CanIf_RxHashTableConfigType,CANIF_CONFIG_DATA) CanIf_RxHashTableConfig[CANIF_RX_NUM_OF_HASH_TABLE];
/*! @brief Defines the key value pair for the Rx Hash table config 
    Elements    : Description 
    RxCanId     : the CanId which is used as key for Hash
    RxPduId     : the CanIf RxPduId which is used as Value for Hash
*/
extern CONST(CanIf_RxHashTableType,CANIF_CONFIG_DATA)  CanIf_RxHashTableMailBox20[CANIF_RX_HASH_TABLE_MAILBOX20_SIZE];
#endif

#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_32
#include "MemMap.h"
/*! @brief defines the configuration for the Rx filter mask   */
extern CONST(uint32,CANIF_CONFIG_DATA) CanIf_RxCanIdMaskConfig[CANIF_NUM_OF_RX_CAN_ID_MASKS];
#if (CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API == STD_ON)
/*! @brief defines the configuration for the Tx filter mask   */
extern CONST(uint32,CANIF_CONFIG_DATA) CanIf_TxCanIdMaskConfig[CANIF_NUM_OF_TX_CAN_ID_MASKS];
#endif

#define CANIF_STOP_SEC_CONFIG_DATA_32
#include "MemMap.h"

#endif /* CANIF_LCFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


