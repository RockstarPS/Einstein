#ifndef PDUR_DOIP_H
#define PDUR_DOIP_H

#define PDUR_APPL_CONST
#define PDUR_APPL_DATA
#define PDUR_CODE


#define PDU_START_SEC_CODE
#include "MemMap.h"
void PduR_DoIPTpRxIndication(PduIdType RxPduId,Std_ReturnType Result);
void PduR_DoIPIfTxConfirmation(PduIdType TxPduId);
void PduR_DoIPTpTxConfirmation(PduIdType TxPduId,Std_ReturnType Result);
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_DoIPTpStartOfReception
(
    PduIdType id, 
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) info, 
    PduLengthType TpSduLength, 
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

FUNC(BufReq_ReturnType, PDUR_CODE) PduR_DoIPTpCopyRxData
(
    PduIdType id, 
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) info, 
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

FUNC(BufReq_ReturnType, PDUR_CODE) PduR_DoIPTpCopyTxData
(
    PduIdType id, 
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) info, 
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, 
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);

#define PDU_STOP_SEC_CODE
#include "MemMap.h"

#endif

