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
*    @file PduR_LinIf.h
*    @ingroup PduRConfiguration
*    @brief This file provides the callback function prototype of the PduR to Dcm module. This header file should   
*    be included only by Dcm module.
*    @defgroup ComConfiguration
*    @brief This file provides the callback function prototype of the PduR to Dcm module.
********************************************************************************************************************/
#ifndef PDUR_DCM_H
#define PDUR_DCM_H
#include "PduR_Types.h"

#define PDUR_START_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC CALLBACK FUNCTION PROTOTYPES                                                                              *
********************************************************************************************************************/
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
extern FUNC(Std_ReturnType,PDUR_CODE) PduR_DcmTransmit
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
extern FUNC(Std_ReturnType,PDUR_CODE) PduR_DcmCancelTransmit(PduIdType TxPduId);
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
extern FUNC(Std_ReturnType,PDUR_CODE) PduR_DcmChangeParameter(PduIdType id, TPParameterType parameter, uint16 value);
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
extern FUNC(Std_ReturnType,PDUR_CODE) PduR_DcmCancelReceive(PduIdType RxPduId);
/********************************************************************************************************************
 *   @brief    Dcm Interface Functions
 ********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE)
PduR_DcmTransmit(
    PduIdType TxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) PduInfoPtr);

FUNC(Std_ReturnType, PDUR_CODE)
PduR_DcmCancelTransmit(
    PduIdType TxPduId);

FUNC(Std_ReturnType, PDUR_CODE)
PduR_DcmChangeParameter(
    PduIdType id,
    TPParameterType parameter,
    uint16 value);

FUNC(Std_ReturnType, PDUR_CODE)
PduR_DcmCancelReceive(
    PduIdType RxPduId);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif /* PDUR_DCM_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/
