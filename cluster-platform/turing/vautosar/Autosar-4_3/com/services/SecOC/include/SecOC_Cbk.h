/*******************************************************************************
 * Copyright (C) 2025 Visteon Corporation., Ltd.
 * All rights reserved.
 *
 * NOTICE: This is an unpublished work of authorship, which contains trade
 * secrets. Visteon Corporation owns all rights to this work and intends to
 * maintain it in confidence to preserve its trade secret status.
 * Visteon Corporation reserves the right, under the copyright laws of the
 * United States or those of any other country that may have jurisdiction,
 * to protect this work as an unpublished work, in the event of an inadvertent
 * or deliberate unauthorized publication. Visteon Corporation also reserves its
 * rights under all copyright laws to protect this work as a published work,
 * when appropriate. Those having access to this work may not copy it, use it,
 * modify it, or disclose the information contained in it without the written
 * authorization of Visteon Corporation.
/*******************************************************************************
********************************************************************************
**                                                                            **
**  FILENAME         : SecOC_Cbk.h                                            **
**                                                                            **
**  Created on       : July - 2025                                            **
**  Author           : cvenkata                                               **
**  Vendor           :                                                        **
**  DESCRIPTION      :                                                        **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR CP Release 4.3.1                               **
**                                                                            **
*******************************************************************************/

#ifndef SECOC_CBK_H
#define SECOC_CBK_H

#include "ComStack_Types.h"
#include "Csm_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/******************************************************************************/
/*
 * Brief               Indication of a received PDU from a lower layer
 *                     communication interface module.
 * ServiceId           0x42
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different PduIds.
 * Param-Name[in]      RxPduId: ID of the received PDU.
 *                     PduInfoPtr: Contains the length (SduLength) of the
 *                     received PDU,a pointer to a buffer (SduDataPtr)containing
 *                     the PDU, and the MetaData related to this PDU.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, SECOC_CODE)
SecOC_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) PduInfoPtr);

/******************************************************************************/
/*
 * Brief               Indication of a received PDU from a lower layer
 *                     communication interface module.
 * ServiceId           0x45
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      id: Identification of the received I-PDU.
 *                     result: Result of the reception.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, SECOC_CODE) SecOC_TpRxIndication(PduIdType id, Std_ReturnType result);

/******************************************************************************/
/*
 * Brief               The lower layer communication interface module confirms
 *                     the transmission of a PDU,or the failure transmit a PDU.
 * ServiceId           0x40
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different PduIds.
 * Param-Name[in]      TxPduId: ID of the PDU that has been transmitted.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, SECOC_CODE) SecOC_TxConfirmation(PduIdType TxPduId);

/******************************************************************************/
/*
 * Brief               This function is called after the I-PDU has been
 *                     transmitted on its network, the result indicates whether
 *                     the transmission was successful or not.
 * ServiceId           0x48
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      id: Identification of the transmitted I-PDU.
 *                     result: Result of the transmission of the I-PDU.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, SECOC_CODE) SecOC_TpTxConfirmation(PduIdType id, Std_ReturnType result);

/******************************************************************************/
/*
 * Brief               Within this API, the upper layer module (called module)
 *                     shall check whether the available data fits into the
 *                     buffer size reported by PduInfoPtr->SduLength.If it fits,
 *                     it shall copy its data into the buffer provided by
 *                     PduInfoPtr->SduDataPtr and update the length of the
 *                     actual copied data in PduInfoPtr->SduLength. If not, it
 *                     returns E_NOT_OK without changing PduInfoPtr.
 * ServiceId           0x41
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different PduIds.
 * Param-Name[in]      TxPduId:ID of the SDU that is requested to be transmitted
 *                     PduInfoPtr: Contains a pointer to a buffer (SduDataPtr)
 *                     to where the SDU data shall be copied, and the available
 *                     buffer size in SduLengh. On return, the service will
 *                     indicate the length of the copied SDU data in SduLength.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: SDU has been copied and SduLength indicates the
 *                           number of copied bytes.
 *                     E_NOT_OK: No SDU data has been copied. PduInfoPtr must
 *                               not be used since it may contain a NULL pointer
 *                               or point to invalid data.
 */
/******************************************************************************/

FUNC(Std_ReturnType, SECOC_CODE)
SecOC_TriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, SECOC_APPL_DATA) PduInfoPtr);


/******************************************************************************/
/*
 * Brief               This function is called to provide the received data of
 *                     an I-PDU segment (N-PDU) to the upper layer. Each call to
 *                     this function provides the next part of the I-PDU data.
 *                     The size of the remaining buffer is written to the
 *                     position indicated by bufferSizePtr.
 * ServiceId           0x44
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      id: Identification of the received I-PDU.
 *                     info: Provides the source buffer (SduDataPtr) and the
 *                     number of bytes to be copied (SduLength). An SduLength of
 *                     0 can be used to query the current amount of available
 *                     buffer in the upper layer module. In this case, the
 *                     SduDataPtr may be a NULL_PTR.
 * Param-Name[out]     bufferSizePtr: Available receive buffer after data has
 *                                    been copied.
 * Param-Name[in/out]  None
 * Return              BUFREQ_OK: Data copied successfully
 *                     BUFREQ_E_NOT_OK: Data was not copied because an error
 *                                      occurred.
 */
/******************************************************************************/

FUNC(BufReq_ReturnType, SECOC_CODE)
SecOC_CopyRxData(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) info,
    P2VAR(PduLengthType, AUTOMATIC, SECOC_APPL_DATA) bufferSizePtr);


/******************************************************************************/
/*
 * Brief               This function is called to acquire the transmit data of
 *                     an I-PDU segment (N-PDU).Each call to this function
 *                     provides the next part of the I-PDU data unless retry->Tp
 *                     DataState is TP_DATARETRY. In this case the function
 *                     restarts to copy the data beginning at the offset from
 *                     the current position indicated by retry->TxTpDataCnt.The
 *                     size of the remaining data is written to the position
 *                     indicated by availableDataPtr.
 * ServiceId           0x43
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      id: Identification of the transmitted I-PDU.
 *                     info: Provides the destination buffer (SduDataPtr) and
 *                           the number of bytes to be copied (SduLength).
 *                     retry: This parameter is used to acknowledge transmitted
 *                     data or to retransmit data after transmission problems.
 * Param-Name[out]     availableDataPtr: Indicates the remaining number of bytes
 *                     that are available in the upper layer module's Tx buffer.
 * Param-Name[in/out]  None
 * Return              BUFREQ_OK: Data has been copied to the transmit buffer
 *                                completely as requested.
 *                     BUFREQ_E_BUSY: Request could not be fulfilled, because
 *                     the required amount of Tx data is not available.
 *                     BUFREQ_E_NOT_OK: Data has not been copied. Request failed
 */
/******************************************************************************/

FUNC(BufReq_ReturnType, SECOC_CODE)
SecOC_CopyTxData(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) info,
    P2CONST(RetryInfoType, AUTOMATIC, SECOC_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, SECOC_APPL_DATA) availableDataPtr);


/******************************************************************************/
/*
 * Brief               This function is called at the start of receiving an
 *                     N-SDU. The N-SDU might be fragmented into multiple N-PDUs
 *                     (FF with one or more following CFs) or might consist of a
 *                     single N-PDU (SF).The service shall provide the currently
 *                     available maximum buffer size when invoked with
 *                     TpSduLength equal to 0.
 * ServiceId           0x46
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      id: Identification of the I-PDU.
 *                     info: Pointer to a PduInfoType structure containing the
 *                     payload data (without protocol information) and payload
 *                     length of the first frame or single frame of a transport
 *                     protocol I-PDU reception, and the MetaData related to
 *                     this PDU. If neither first/single frame data nor MetaData
 *                     are available, this parameter is set to NULL_PTR.
 *                     TpSduLength: Total length of the N-SDU to be received.
 * Param-Name[out]     bufferSizePtr: Available receive buffer in the receiving
 *                     module. This parameter will be used to compute the Block
 *                     Size (BS) in the transport protocol module.
 * Param-Name[in/out]  None
 * Return              BUFREQ_OK: Connection has been accepted.
 *                     BUFREQ_E_NOT_OK: Connection has been rejected.
 *                     BUFREQ_E_OVFL: No buffer of the required length can be
 *                                    provided; reception is aborted.
 */
/******************************************************************************/

FUNC(BufReq_ReturnType, SECOC_CODE)
SecOC_StartOfReception(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, SECOC_APPL_DATA) bufferSizePtr);


/******************************************************************************/
/*
 * Brief               CSM notifies SecOC that a Authenticator generate job has
 *                     finished.
 * ServiceId           0x50
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      job: JobID of the operation that caused the callback.
 *                     result: Contains the result of cryptographic operation.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, SECOC_CODE)
SecOC_CsmGenerateJobFinishedIndication(
    P2CONST(Crypto_JobType, AUTOMATIC, SECOC_APPL_CONST) job,
    Crypto_ResultType result);

/******************************************************************************/
/*
 * Brief               CSM notifies SecOC that a Authenticator verify job has
 *                     finished.
 * ServiceId           0x51
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      job: JobID of the operation that caused the callback.
 *                     result: Contains the result of cryptographic operation.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, SECOC_CODE)
SecOC_CsmVerifyJobFinishedIndication(
    P2CONST(Crypto_JobType, AUTOMATIC, SECOC_APPL_CONST) job,
    Crypto_ResultType result);

/*******************************************************************************
**                      Revision  History                                     **
*******************************************************************************/
/*---------------------------------------------------------------------------
Date              : 27/Jul/2025
By                : cvenkata
Traceability      : DICVA-19595
Change Description: SecOC module - Initial development.
-----------------------------------------------------------------------------*/

#endif /* SECOC_CBK_H */
