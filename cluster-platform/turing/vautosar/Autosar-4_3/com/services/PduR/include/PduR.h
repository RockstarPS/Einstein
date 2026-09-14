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
*    @file PduR.h
*    @ingroup PduR
*    @brief This file provides the declaration of the PduR API. This header file should be included by other
*    modules that use the PduR API
*    @defgroup PduR
*    @brief This file provides the declaration of the PduR API and its types.
*    The PDU Router module provides services for routing of I-PDUs (Interaction Layer Protocol Data Units) 
*    using the following module types:
*       1. Communication interface modules, that are modules that use the <Provider:Up> or <Provider:Lo> API,
*          e.g. Com, IPduM, LinIf, CanIf, CanNm, FrIf and FrNm
*       2. Transport Protocol modules, that are modules using the <Provider:UpTp> or <Provider:LoTp> API, 
*          e.g. J1939Tp, LinTp (part of LinIf), CanTp, FrTp, COM, DCM
********************************************************************************************************************/
#ifndef PDUR_H
#define PDUR_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "PduR_Cfg.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Software Version */
/*! Defines the PduR SW major version */
#define PDUR_SW_MAJOR_VERSION                                   1u
/*! Defines the PduR SW minor version */
#define PDUR_SW_MINOR_VERSION                                   0u
/*! Defines the PduR SW patch version */
#define PDUR_SW_PATCH_VERSION                                   0u
/* Autosar Release */
/*! Defines the AUTOSAR Com Release major version */
#define PDUR_AR_RELEASE_MAJOR_VERSION                           4u
/*! Defines the AUTOSAR Com Release minor version */
#define PDUR_AR_RELEASE_MINOR_VERSION                           3u
/*! Defines the AUTOSAR Com Release patch version */
#define PDUR_AR_RELEASE_REVISION_VERSION                        1u
/********************************************************************************************************************
*  MODULE INFORMATION                                                                                               *
********************************************************************************************************************/
/*! Defines the Vendor ID of Com module. */
#define PDUR_VENDOR_ID                                          0x0033u
/*! Defines the Module ID of Com module.*/
#define PDUR_MODULE_ID                                          51u
/*! Defines the Instance ID of Com module.*/
#define PDUR_INSTANCE_ID                                        0u
/********************************************************************************************************************
*  API ID VALUES                                                                                                    *
********************************************************************************************************************/
/*! Defines the service Id for PduR_Init function */
#define PDUR_INIT_API                                           0xf0u
/*! Defines the service Id for PduR_GetVersionInfo function */
#define PDUR_GET_VERSION_INFO_API                               0xf1u
/*! Defines the service Id for PduR_GetConfigurationId function */
#define PDUR_GET_CONFIGURATION_ID_API                           0xf1u
/*! Defines the service Id for PduR_EnableRouting function */
#define PDUR_ENABLE_ROUTING_API                                 0xf3u
/*! Defines the service Id for PduR_DisableRouting function */
#define PDUR_DISABLE_ROUTING_API                                0xf4u
/*! Defines the service Id for PduR_UpTransmit function */
#define PDUR_UP_TRANSMIT_API									0x49u
/*! Defines the service Id for PduR_UpCancelTransmit function */
#define PDUR_UP_CANCEL_TRANSMIT_API           					0x4au
/*! Defines the service Id for PduR_UpChangeParameter function */
#define PDUR_UP_CHANGE_PARAMETER_API          					0x4bu
/*! Defines the service Id for PduR_UpCancelReceive function */
#define PDUR_UP_CANCEL_RECEIVE_API            					0x4cu
/*! Defines the service Id for PduR_LoRxIndication function */
#define PDUR_LO_RX_INDICATION_API             					0x42u
/*! Defines the service Id for PduR_LoTxConfirmation function */
#define PDUR_LO_TX_CONFIRMATION_API           					0x40u
/*! Defines the service Id for PduR_LoTriggerTransmit function */
#define PDUR_LO_TRIGGER_TRANSMIT_API          					0x41u
/*! Defines the service Id for PduR_LoTpCopyRxData function */
#define PDUR_LO_TP_COPY_RX_DATA_API           					0x44u
/*! Defines the service Id for PduR_LoTpRxIndication function */
#define PDUR_LO_TP_RX_INDICATION_API          					0x45u
/*! Defines the service Id for PduR_LoTpStartOfReception function */
#define PDUR_LO_TP_START_OF_RECEPTION_API     					0x46u
/*! Defines the service Id for PduR_LoTpCopyTxData function */
#define PDUR_LO_TP_COPY_TX_DATA_API           					0x43u
/*! Defines the service Id for PduR_LoTpTxConfirmation function */
#define PDUR_LO_TP_TX_CONFIRMATION_API							0x48u
/*! @brief Defines the ID for NO error */
#define PDUR_E_NO_ERROR                                         0xFFu
/********************************************************************************************************************
*  DEVELOPMENT ERRORS VALUES                                                                                        *
********************************************************************************************************************/
/*! @brief Defines the error ID for Invalid configuration pointer */
#define PDUR_E_INIT_FAILED                                      0x00u
/*! @brief Defines the error ID for API service used without module initialization or PduR_Init called in any 
    state other than PDUR_UNINIT */
#define PDUR_E_UNINIT                              				0x01u
/*! @brief Defines the error ID for Invalid PDU identifier */
#define PDUR_E_PDU_ID_INVALID                              		0x02u
/*! @brief Defines the error ID If the routing table is invalid that is given to the PduR_EnableRouting or 
    PduR_DisableRouting functions */
#define PDUR_E_ROUTING_PATH_GROUP_ID_INVALID                    0x08u
/*! @brief Defines the error ID for Null pointer has been passed as an argument */
#define PDUR_E_PARAM_POINTER                                    0x09u
/********************************************************************************************************************
*  RUNTIME ERRORS VALUES                                                                                            *
********************************************************************************************************************/
/*! @brief Defines the runtime error id if TP module rejects a transmit request for a valid PDU identifier */
#define PDUR_E_TP_TX_REQ_REJECTED                               0x03u
/*! @brief Defines the runtime error id if Loss of a PDU instance (buffer overrun in gateway operation) */
#define PDUR_E_PDU_INSTANCES_LOST                               0x0au

#define PDUR_START_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @brief      This service initializes the PDU Router
*   @param[in]  ConfigPtr Pointer to post build configuration
*   @ServiceID  0xf0
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant.
*   @note       To avoid problems calling the PDU Router module uninitialized it is important that the PDU Router 
*               module is initialized before interfaced modules.
********************************************************************************************************************/
extern FUNC(void,PDUR_CODE) PduR_Init(P2CONST(PduR_PBConfigType,AUTOMATIC,PDUR_APPL_CONST) ConfigPtr);
/*!******************************************************************************************************************
*   @brief      This service Returns the version information of this module.
*   @param[out] versionInfo Pointer to where to store the version information of this module.
*   @ServiceID  0xf1
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(void,PDUR_CODE) PduR_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,PDUR_APPL_DATA) versionInfo);
/*!******************************************************************************************************************
*   @brief      This service Returns the unique identifier of the post-build time configuration of the PDU Router
*   @return     PduR_PBConfigIdType Identifier of the post-build time configuration
*   @ServiceID  0xf2
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(PduR_PBConfigIdType,PDUR_CODE) PduR_GetConfigurationId(void);
/*!******************************************************************************************************************
*   @brief      This service Enables a routing path group.
*   @param[in]  id Identification of the routing path group. Routing path groups are defined in the PDU router
*               configuration.
*   @ServiceID  0xf3
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(void,PDUR_CODE) PduR_EnableRouting(PduR_RoutingPathGroupIdType id);
/*!******************************************************************************************************************
*   @brief      This service Disables a routing path group.
*   @param[in]  id Identification of the routing path group. Routing path groups are defined in the PDU router
*               configuration.
*   @param[in]  initialize true: initialize single buffers to the default value
*               false: retain current value of single buffers
*   @ServiceID  0xf4
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(void,PDUR_CODE) PduR_DisableRouting(PduR_RoutingPathGroupIdType id,boolean initialize);
/*!******************************************************************************************************************
*   @brief      This service Requests transmission of an I-PDU.
*   @param[in]  TxPduId  Identifier of the PDU to be transmitted.
*   @param[in]  PduInfoPtr Length of and pointer to the PDU data and pointer to MetaData.
*   @return     Std_ReturnType E_OK: Transmit request has been accepted. 
*               E_NOT_OK: Transmit request has not been accepted.
*   @ServiceID  0x49
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,PDUR_CODE) PduR_UpTransmit
(
    PduIdType TxPduId,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) PduInfoPtr
);
/*!******************************************************************************************************************
*   @brief      This service Requests cancellation of an ongoing transmission of a PDU in a lower layer communication 
*               module.
*   @param[in]  TxPduId  Identification of the I-PDU to be cancelled.
*   @return     Std_ReturnType  status of the request
*               E_OK: Cancellation was executed successfully by the destination module.
*               E_NOT_OK: Cancellation was rejected by the destination module.
*   @ServiceID  0x4A
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,PDUR_CODE) PduR_UpCancelTransmit(PduIdType TxPduId);
/*!******************************************************************************************************************
*   @brief      This service Request to change a specific transport protocol parameter (e.g. block size). obsolete
*   @param[in]  id  Identifiaction of the I-PDU which the parameter change shall affect.
*   @param[in]  parameter The parameter that shall change
*   @param[in]  value  The new value of the parameter
*   @return     Std_ReturnType  status of the request
*               - E_OK : The parameter was changed successfully
*               - E_NOT_OK : The parameter change was rejected.
*   @ServiceID  0x4B
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,PDUR_CODE) PduR_UpChangeParameter(PduIdType id, TPParameterType parameter, uint16 value);
/*!******************************************************************************************************************
*   @brief      This service Requests cancellation of an ongoing reception of an I-PDU in a lower layer transport
*               protocol module.
*   @param[in]  RxPduId  Identification of the PDU to be cancelled.
*   @return     Std_ReturnType  status of the request
*               - E_OK :  Cancellation was executed successfully by the destination module
*               - E_NOT_OK : Cancellation was rejected by the destination module
*   @ServiceID  0x4C
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,PDUR_CODE) PduR_UpCancelReceive(PduIdType RxPduId);
/*!******************************************************************************************************************
*   @brief      Indication of a received PDU from a lower layer communication interface module.
*   @param[in]  RxPduId ID of the received PDU.
*   @param[in]  PduInfoPtr Contains the length (SduLength) of the received PDU, a pointer to a buffer (SduDataPtr) 
*               containing the PDU, and the MetaData related to this PDU.
*   @ServiceID  0x42
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
extern FUNC(void,PDUR_CODE) PduR_LoRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) PduInfoPtr
);
/*!******************************************************************************************************************
*   @brief      The lower layer communication interface module confirms the transmission of a PDU, or the failure to 
*               transmit a PDU.
*   @param[in]  TxPduId ID of the PDU that has been transmitted.
*   @param[in]  result E_OK: The PDU was transmitted. E_NOT_OK: Transmission of the PDU failed.
*   @ServiceID  0x40
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
extern FUNC(void,PDUR_CODE) PduR_LoTxConfirmation(PduIdType TxPduId,Std_ReturnType result);
/*!******************************************************************************************************************
*   @brief      Within this API, the upper layer module (called module) shall check whether the available data fits 
*               into the buffer size reported by PduInfoPtr->SduLength. If it fits, it shall copy its data into the
*               buffer provided by PduInfoPtr->SduDataPtr and update the length of the actual copied data in 
*               PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing PduInfoPtr.
*   @param[in]      TxPduId ID of the SDU that is requested to be transmitted.
*   @param[in,out]  PduInfoPtr Contains a pointer to a buffer (SduDataPtr) to where the SDU data shall be copied,  
*                   and the available buffer size in SduLengh. On return, the service will indicate the length of  
*                   the copied SDU data in SduLength.
*   @return         Std_ReturnType E_OK: SDU has been copied and SduLength indicates the number of copied bytes. 
*                   E_NOT_OK: No SDU data has been copied. PduInfoPtr must not be used since it may contain a NULL
*                   pointer or point to invalid data.
*   @ServiceID      0x41
*   @Sync/Async     Synchronous 
*   @Reentrancy     Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,PDUR_CODE) PduR_LoTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType,AUTOMATIC,PDUR_APPL_DATA) PduInfoPtr
);
/*!******************************************************************************************************************
*   @brief      This function is called to provide the received data of an I-PDU segment (N-PDU) to the upper layer.
*               Each call to this function provides the next part of the I-PDU data. The size of the remaining buffer 
*               is written to the position indicated by bufferSizePtr.
*   @param[in]  id Identification of the received I-PDU.
*   @param[in]  info Provides the source buffer (SduDataPtr) and the number of bytes to be copied (SduLength).
*               An SduLength of 0 can be used to query the current amount of available buffer in the upper layer 
*               module. In this case, the SduDataPtr may be a NULL_PTR.
*   @param[out] bufferSizePtr Available receive buffer after data has been copied.
*   @return     BufReq_ReturnType BUFREQ_OK: Data copied successfully 
*               BUFREQ_E_NOT_OK: Data was not copied because an error occurred.
*   @ServiceID  0x44
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(BufReq_ReturnType,PDUR_CODE) PduR_LoTpCopyRxData
(
    PduIdType id, 
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) info,
    P2VAR(PduLengthType,AUTOMATIC,PDUR_APPL_DATA) bufferSizePtr
);
/*!******************************************************************************************************************
*   @brief      Called after an I-PDU has been received via the TP API, the result indicates whether the transmission 
*               was successful or not.
*   @param[in]  id Identification of the received I-PDU.
*   @param[in]  result Result of the reception.
*   @return     BufReq_ReturnType BUFREQ_OK: Data copied successfully 
*               BUFREQ_E_NOT_OK: Data was not copied because an error occurred.
*   @ServiceID  0x45
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(void,PDUR_CODE) PduR_LoTpRxIndication(PduIdType id, Std_ReturnType result);
/*!******************************************************************************************************************
*   @brief      This service is called at the start of receiving an N-SDU. The N-SDU might be fragmented into 
*               multiple N-PDUs (FF with one or more following CFs) or might consist of a single N-PDU (SF). 
*               The service shall provide the currently available maximum buffer size when invoked with TpSduLength 
*               equal to 0.
*   @param[in]  id Identification of the I-PDU.
*   @param[in]  info Pointer to a PduInfoType structure containing the payload data (without protocol information) 
*               and payload length of the first frame or single frame of a transport protocol I-PDU reception, and 
*               the MetaData related to this PDU. If neither first/single frame data nor MetaData are available, 
*               this parameter is set to NULL_PTR.
*   @param[in]  TpSduLength Total length of the N-SDU to be received.
*   @param[out] bufferSizePtr Available receive buffer in the receiving module. This parameter will be used to 
*               compute the Block Size (BS) in the transport protocol module.
*   @return     BufReq_ReturnType 
*               BUFREQ_OK: Connection has been accepted. bufferSizePtr indicates the available receive buffer; 
*               reception is continued. If no buffer of the requested size is available, 
*               a receive buffer size of 0 shall be indicated by bufferSizePtr. 
*               BUFREQ_E_NOT_OK: Connection has been rejected; reception is aborted. bufferSizePtr remains unchanged. 
*               BUFREQ_E_OVFL: No buffer of the required length can be provided; reception is aborted. bufferSizePtr 
*               remains unchanged.
*   @ServiceID  0x46
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(BufReq_ReturnType,PDUR_CODE) PduR_LoTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType,AUTOMATIC,PDUR_APPL_DATA) bufferSizePtr
);
/*!******************************************************************************************************************
*   @brief      This service is called to acquire the transmit data of an I-PDU segment (N-PDU). Each call to this 
*               function provides the next part of the I-PDU data unless retry->TpDataState is TP_DATARETRY. In this 
*               case the function restarts to copy the data beginning at the offset from the current position 
*               indicated by retry->TxTpDataCnt. The size of the remaining data is written to the position indicated 
*               by availableDataPtr.
*   @param[in]  id Identification of the transmitted I-PDU.
*   @param[in]  info Provides the destination buffer (SduDataPtr) and the number of bytes to be copied (SduLength). 
*               If not enough transmit data is available, no data is copied by the upper layer module and 
*               BUFREQ_E_BUSY is returned. The lower layer module may retry the call. An SduLength of 0 can be used 
*               to indicate state changes in the retry parameter or to query the current amount of available data 
*               in the upper layer module. In this case, the SduDataPtr may be a NULL_PTR.
*   @param[in]  retry This parameter is used to acknowledge transmitted data or to retransmit data after 
*               transmission problems. If the retry parameter is a NULL_PTR, it indicates that the transmit data can
*               be removed from the buffer immediately after it has been copied. Otherwise, the retry parameter must 
*               point to a valid RetryInfoType element. If TpDataState indicates TP_CONFPENDING, the previously copied 
*               data must remain in the TP buffer to be available for error recovery. TP_DATACONF indicates that all 
*               data that has been copied before this call is confirmed and can be removed from the TP buffer. 
*               Data copied by this API call is excluded and will be confirmed later. TP_DATARETRY indicates that this 
*               API call shall copy previously copied data in order to recover from an error. In this case TxTpDataCnt 
*               specifies the offset in bytes from the current data copy position.
*   @param[out] availableDataPtr Indicates the remaining number of bytes that are available in the upper layer
*               module's Tx buffer. availableDataPtr can be used by TP modules that support dynamic payload lengths 
*               (e.g. FrIsoTp) to determine the size of the following CFs.
*   @return     BufReq_ReturnType BUFREQ_OK: Data has been copied to the transmit buffer completely as requested. 
*               BUFREQ_E_BUSY: Request could not be fulfilled, because the required amount of Tx data is not available.
*               The lower layer module may retry this call later on. No data has been copied. 
*               BUFREQ_E_NOT_OK: Data has not been copied. Request failed..
*   @ServiceID  0x43
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(BufReq_ReturnType,PDUR_CODE) PduR_LoTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) info,
    P2VAR(RetryInfoType,AUTOMATIC,PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType,AUTOMATIC,PDUR_APPL_DATA) availableDataPtr
);
/*!******************************************************************************************************************
*   @brief      This service is called after the I-PDU has been transmitted on its network, the result indicates 
*               whether the transmission was successful or not.
*   @param[in]  id dentification of the transmitted I-PDU.
*   @param[in]  result Result of the transmission of the I-PDU.
*   @ServiceID  0x48
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant 
********************************************************************************************************************/
extern FUNC(void,PDUR_CODE) PduR_LoTpTxConfirmation(PduIdType id, Std_ReturnType result);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif /* PDUR_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/
