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
*   @file App_Cbk.h
*   @ingroup App
*   @brief This file provides Call-Back functions which are called by the lower layer SoAd module.
********************************************************************************************************************/
#ifndef APP_CBK_H
#define APP_CBK_H

/*!******************************************************************************************************************
*   @brief      This function is called to acquire the transmit data of an I-PDU segment (N-PDU). Each call to this 
*               function provides the next part of the I-PDU data unless retry->TpDataState is TP_DATARETRY. In this
*               case the function restarts to copy the data beginning at the offset from the current position indicated
*               by retry->TxTpDataCnt. The size of the remaining data is written to the position indicated by 
*               availableDataPtr.
*   @param[in]  id  Identification of the transmitted I-PDU.
*   @param[in]  info  Provides the destination buffer (SduDataPtr) and the number of bytes to be copied (SduLength). 
*               If not enough transmit data is available, no data is copied by the upper layer module and BUFREQ_E_BUSY
*               is returned. The lower layer module may retry the call. An SduLength of 0 can be used to indicate state
*               changes in the retry parameter or to query the current amount of available data in the upper layer 
*               module. In this case, the SduDataPtr may be a NULL_PTR.
*   @param[in]  retry  This parameter is used to acknowledge transmitted data or to retransmit data after transmission
*               problems. If the retry parameter is a NULL_PTR, it indicates that the transmit data can be removed 
*               from the buffer immediately after it has been copied. Otherwise, the retry parameter must point to a 
*               valid RetryInfoType element.
*   @param[out] availableDataPtr  Indicates the remaining number of bytes that are available in the upper layer 
*               module's Tx buffer. availableDataPtr can be used by TP modules that support dynamic payload lengths 
*               (e.g. FrIsoTp) to determine the size of the following CFs
*   @return     BUFREQ_OK: Data has been copied to the transmit buffer completely as requested. 
*               BUFREQ_E_BUSY: Request could not be fulfilled, because the required amount of Tx data is not available.
*               The lower layer module may retry this call later on. No data has been copied. 
*               BUFREQ_E_NOT_OK: Data has not been copied. Request failed.
********************************************************************************************************************/
extern FUNC(BufReq_ReturnType, DOIP_CODE) App_SoAdTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) info,
    P2CONST(RetryInfoType,AUTOMATIC,DOIP_APPL_CONST) retry,
    P2VAR(PduLengthType,AUTOMATIC,DOIP_APPL_DATA) availableDataPtr
);
/*!******************************************************************************************************************
*   @brief      This function is called after the I-PDU has been transmitted on its network, the result indicates 
*               whether the transmission was successful or not.
*   @param[in]  id Identification of the transmitted I-PDU.
*   @param[in]  result Result of the transmission of the I-PDU.
********************************************************************************************************************/
extern FUNC(void, DOIP_CODE) App_SoAdTpTxConfirmation(PduIdType id, Std_ReturnType result);
/*!******************************************************************************************************************
*   @brief      This function is called to provide the received data of an I-PDU segment (N-PDU) to the upper layer.
*               Each call to this function provides the next part of the I-PDU data. The size of the remaining buffer 
*               is written to the position indicated by bufferSizePtr.
*   @param[in]  id Identification of the received I-PDU.
*   @param[in]  info Provides the source buffer (SduDataPtr) and the number of bytes to be copied (SduLength).
*               An SduLength of 0 can be used to query the current amount of available buffer in the upper layer module.
*               In this case, the SduDataPtr may be a NULL_PTR.
*   @param[out] bufferSizePtr Available receive buffer after data has been copied.
*   @return     BUFREQ_OK: Data copied successfully BUFREQ_E_NOT_OK: Data was not copied because an error occurred.
********************************************************************************************************************/
extern FUNC(BufReq_ReturnType, DOIP_CODE) App_SoAdTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) info,
    P2VAR(PduLengthType,AUTOMATIC,DOIP_APPL_DATA) bufferSizePtr
);
/*!******************************************************************************************************************
*   @brief      This function is called at the start of receiving an N-SDU. The N-SDU might be fragmented into multiple
*               N-PDUs (FF with one or more following CFs) or might consist of a single N-PDU (SF). The service shall 
*               provide the currently available maximum buffer size when invoked with TpSduLength equal to 0.
*   @param[in]  id Identification of the I-PDU.
*   @param[in]  info Pointer to a PduInfoType structure containing the payload data (without protocol information) 
*               and payload length of the first frame or single frame of a transport protocol I-PDU reception, and 
*               the MetaData related to this PDU. If neither first/single frame data nor MetaData are available, 
*               this parameter is set to NULL_PTR.
*   @param[in]  TpSduLength Total length of the N-SDU to be received.
*   @param[out] bufferSizePtr Available receive buffer in the receiving module. This parameter will be used to 
*               compute the Block Size (BS) in the transport protocol module.
*   @return     BUFREQ_OK: Connection has been accepted. bufferSizePtr indicates the available receive buffer;
*               reception is continued. If no buffer of the requested size is available, a receive buffer size of 0 
*               shall be indicated by bufferSizePtr. 
*               BUFREQ_E_NOT_OK: Connection has been rejected; reception is aborted. bufferSizePtr remains unchanged. 
*               BUFREQ_E_OVFL: No buffer of the required length can be provided; reception is aborted. 
*               bufferSizePtr remains unchanged.
********************************************************************************************************************/
extern FUNC(BufReq_ReturnType, DOIP_CODE) App_SoAdTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType,AUTOMATIC,DOIP_APPL_DATA) bufferSizePtr 
);
/*!******************************************************************************************************************
*   @brief      Called after an I-PDU has been received via the TP API, the result indicates whether the transmission 
*               was successful or not.
*   @param[in]  id Identification of the received I-PDU.
*   @param[in]  result Result of the reception.
********************************************************************************************************************/
extern FUNC(void, DOIP_CODE) App_SoAdTpRxIndication(PduIdType id, Std_ReturnType result);
/*!******************************************************************************************************************
*   @brief      Indication of a received PDU from a lower layer communication interface module.
*   @param[in]  RxPduId ID of the received PDU.
*   @param[in]  PduInfoPtr Contains the length (SduLength) of the received PDU, a pointer to a buffer (SduDataPtr) 
*               containing the PDU, and the MetaData related to this PDU.
********************************************************************************************************************/
extern FUNC(void, DOIP_CODE) App_SoAdIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType,AUTOMATIC,DOIP_APPL_CONST) PduInfoPtr
);
/*!******************************************************************************************************************
*   @brief      The lower layer communication interface module confirms the transmission of a PDU, or the failure to 
*               transmit a PDU.
*   @param[in]  TxPduId ID of the PDU that has been transmitted.
*   @param[in]  result E_OK: The PDU was transmitted. E_NOT_OK: Transmission of the PDU failed
********************************************************************************************************************/
extern FUNC(void, DOIP_CODE) App_SoAdIfTxConfirmation(PduIdType TxPduId, Std_ReturnType result);
/*!******************************************************************************************************************
*   @brief      Notification about a SoAd socket connection state change, e.g. socket connection gets online
*   @param[in]  SoConId socket connection index specifying the socket connection with the mode change.
*   @param[in]  Mode new Mode
********************************************************************************************************************/
extern FUNC(void, DOIP_CODE) App_SoConModeChg(SoAd_SoConIdType SoConId, SoAd_SoConModeType Mode);
/*!******************************************************************************************************************
*   @brief      This function gets called by the SoAd if an IP address assignment related to a socket connection 
*               changes (i.e. new address assigned or assigned address becomes invalid).
*   @param[in]  SoConId socket connection index specifying the socket connection where the IP address assigment has 
*               changed
*   @param[in]  State state of IP address assignment
********************************************************************************************************************/
extern FUNC(void, DOIP_CODE) App_LocalIpAddrAssignmentChg(SoAd_SoConIdType SoConId, TcpIp_IpAddrStateType State);


#endif /* APP_CBK_H */
