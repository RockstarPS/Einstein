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
*    @file CanTp_Cbk.h
*    @ingroup CanTp
*    @brief This file provides the callback function prototype of the CanTp module. This header file should be  
*    included only by modules calling callbacks of CanTp module.
********************************************************************************************************************/
#ifndef CANTP_CBK_H
#define CANTP_CBK_H

/*******************************************************************************************************************
*  PUBLIC CALLBACK FUNCTION PROTOTYPE                                                                              *
********************************************************************************************************************/

/*!*****************************************************************************************************************
*   @brief      Indication of a received I-PDU from a lower layer communication interface module
*   @param[in]  RxPduId     ID of the received I-PDU.
*   @param[in]  PduInfoPtr  Contains the length (SduLength) of the received I-PDU and a pointer to a 
*                           buffer (SduDataPtr) containing the I-PDU.
*   @ServiceID  0x42
*   @Sync/Async Synchronous 
*   @note       The function CanTp_TxConfirmation shall be callable in interrupt context 
*   @Reentrancy Reentrant for different PduIds. Non Reentrant for the same PduId.
********************************************************************************************************************/
void CanTp_RxIndication(PduIdType RxPduId,const PduInfoType* PduInfoPtr); 

/*!***************************************************************************************************************** 
*   @brief      The lower layer communication interface module confirms the transmission of an I-PDU.
*   @param[in]  TxPduId     ID of the I-PDU that has been transmitted.
*   @ServiceID  0x40
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
*   @note       The function CanTp_TxConfirmation shall be callable in interrupt context 
********************************************************************************************************************/
void CanTp_TxConfirmation(PduIdType TxPduId, Std_ReturnType result);

#endif /* CANTP_CBK_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/



