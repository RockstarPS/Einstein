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
*    @file PduR_CanTp.h
*    @ingroup PduRConfiguration
*    @brief This file provides the callback function prototype of the PduR to CanTp module. This header file should   
*    be included only by CanTp module.
*    @defgroup ComConfiguration
*    @brief This file provides the callback function prototype of the PduR to CanTp module.
********************************************************************************************************************/
#ifndef PDUR_CANTP_H
#define PDUR_CANTP_H
#include "PduR_Types.h"
#define PDUR_START_SEC_CODE
#define PDUR_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC CALLBACK FUNCTION PROTOTYPES                                                                              *
********************************************************************************************************************/
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
extern FUNC(BufReq_ReturnType,PDUR_CODE) PduR_CanTpCopyRxData
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
extern FUNC(void,PDUR_CODE) PduR_CanTpRxIndication(PduIdType id, Std_ReturnType result);
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
extern FUNC(BufReq_ReturnType,PDUR_CODE) PduR_CanTpStartOfReception
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
extern FUNC(BufReq_ReturnType,PDUR_CODE) PduR_CanTpCopyTxData
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
extern FUNC(void,PDUR_CODE) PduR_CanTpTxConfirmation(PduIdType id, Std_ReturnType result);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif /* PDUR_CANIF_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/
