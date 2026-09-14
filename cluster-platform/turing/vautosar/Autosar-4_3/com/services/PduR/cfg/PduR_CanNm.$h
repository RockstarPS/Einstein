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
*    @file PduR_CanNm.h
*    @ingroup PduRConfiguration
*    @brief This file provides the callback function prototype of the PduR to CanNm module. This header file should   
*    be included only by CanNm module.
*    @defgroup ComConfiguration
*    @brief This file provides the callback function prototype of the PduR to CanNm module.
********************************************************************************************************************/

#ifndef PDUR_CANNM_H
#define PDUR_CANNM_H

#define PDUR_START_SEC_CODE
#include "MemMap.h"
#include "PduR_Types.h"

/********************************************************************************************************************
*  PUBLIC CALLBACK FUNCTION PROTOTYPES                                                                              *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @brief      Indication of a received PDU from a lower layer communication interface module.
*   @param[in]  RxPduId ID of the received PDU.
*   @param[in]  PduInfoPtr Contains the length (SduLength) of the received PDU, a pointer to a buffer (SduDataPtr) 
*               containing the PDU, and the MetaData related to this PDU.
*   @ServiceID  0x42
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
extern FUNC(void,PDUR_CODE) PduR_CanNmRxIndication
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
extern FUNC(void,PDUR_CODE) PduR_CanNmTxConfirmation(PduIdType TxPduId,Std_ReturnType result);
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
extern FUNC(Std_ReturnType,PDUR_CODE) PduR_CanNmTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType,AUTOMATIC,PDUR_APPL_DATA) PduInfoPtr
);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif /* PDUR_CANNM_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/
