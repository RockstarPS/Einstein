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
*   @file SoAd_Tx.c
*   @ingroup SoAd
*   @brief The main purpose of the SoAd_Tx is to implement the transmit functionality of the SoAd module.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "SoAd.h"
#include "SoAd_Internal.h"
#include "SoAd_Lcfg.h"
#include "SchM_SoAd.h"
#include "SoAd_Tx.h"
#include "SoAd_Socket.h"
#include "SoAd_TcpIpIf.h" 
/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
 
/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
#define SOAD_START_SEC_CODE
#include "MemMap.h"
/* #! routing group */
/*!******************************************************************************************************************
*   @brief This Api is used to check if the routing group for the pdu route destination is enabled
*   @param  PduRouteDestIdx the pdu route destination idx
*   @return status of routing group TRUE: routing group enabled FALSE: routing group disabled
********************************************************************************************************************/
boolean SoAd_CheckRoutingGroupPduDestEnabled(SoAd_PduRouteDestIdxType PduRouteDestIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the routing group if transmit
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_RouteGrpIfTransmitHandler(void);
/* #! confirmation */
/*!******************************************************************************************************************
*   @brief This Api is used to handle the tx confirmation
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TxConfirmationHandler(void);
/*!******************************************************************************************************************
*   @brief This Api is used to process pdu route idx confirmation and invoke upper confirmation call
*   @param[in] PduRouteIdx the pdu route idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxIfCallTxConfirmation(SoAd_PduRouteIdxType PduRouteIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the immediate If tx confirmation
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxUdpImmediateIfTxConfirmation(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the Udp Tx if confirmation
*   @param[in] PduRouteIdx the pdu route idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxIfUdpTxConfirmation(SoAd_PduRouteIdxType PduRouteIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the tx if tcp pdu confirmation
*   @param[in] SoConIdx the socket connection idx
*   @param[in] PduRouteIdx the pdu route idx
*   @param[in] ByResetSoCon socket conn reset request. TRUE:SoCon reset required FALSE: SoCon reset not required
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxIfTcpTxConfirmation
(
    SoAd_SoConIdType SoConIdx,
    SoAd_PduRouteIdxType PduRouteIdx,
    boolean ByResetSoCon
);
/* transmit */
/*!******************************************************************************************************************
*   @brief This Api is used to handle the transmission in main function call
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TxTransmissionHandler(void);
/* if transmit */
/*!******************************************************************************************************************
*   @brief This Api is used to check valid states for If Pdu transmission
*   @param[in] PduRouteIdx the pdu route idx
*   @return status of the request E_OK: valid states E_NOT_OK: Invalid states
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfCheckTxState(SoAd_PduRouteIdxType PduRouteIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to transmit the If Pdu
*   @param[in] PduRouteIdx the pdu route idx
*   @param[in] PduInfoPtr pointer to the Pdu Info
*   @param[in] ErrorIdPtr pointer to update the Error Id 
*   @return Std_ReturnType status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfTransmitPdu
(
    SoAd_PduRouteIdxType PduRouteIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_DATA) PduInfoPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) ErrorIdPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the transmission of If Pdu route dest
*   @param[in] PduRouteDestIdx the pdu route destination idx
*   @param[in] PduInfoPtr pointer to the Pdu Info
*   @param[in] ErrorIdPtr pointer to update the Error Id 
*   @return Std_ReturnType status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfTransmitPduRouteDest
(
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) ErrorIdPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to request the socket transmission for If pdu
*   @param[in] PduRouteDestIdx the pdu route destination idx
*   @return Std_ReturnType status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfTcpCallTransmit(SoAd_PduRouteDestIdxType PduRouteDestIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to get the Pdu route dest idx by the meta data
*   @param[in] PduRouteIdx the pdu route idx 
*   @param[in] PduInfoPtr pointer to update the pdu info
*   @param[out] PduRouteDestIdxPtr pointer to update the valid Pdu Route Dest Idx
*   @return Std_ReturnType status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfGetPduRouteDestIdxByMetaData
(
    SoAd_PduRouteIdxType PduRouteIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_DATA) PduInfoPtr,
    P2VAR(SoAd_PduRouteDestIdxType, AUTOMATIC, SOAD_APPL_DATA) PduRouteDestIdxPtr
);

/* #! udp if transmit */
/*!******************************************************************************************************************
*   @brief This Api is used to transmit the udp if normal Pdu
*   @param[in] PduRouteDestIdx the pdu route destination idx
*   @param[in] PduInfoPtr pointer to pdu info for transmission
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfUdpTransmitPdu
(
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to transmit the udp if pdu
*   @param[in] PduRouteDestIdx the pdu route destination idx
*   @param[in] PduInfoPtr pointer to pdu info for transmission
*   @param[out] ErrorIdPtr pointer to update the error status
*   @return Std_ReturnType status of the request E_OK:request accepted E_NOT_OK:request not accepted 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfUdpTransmit
(
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) ErrorIdPtr
);

/* #! Tcp if transmit */
/*!******************************************************************************************************************
*   @brief This Api is used to transmit the If tcp pdu.
*   @param[in] PduRouteDestIdx the pdu route destination idx
*   @param[in] PduInfoPtr pointer to the Pdu Info
*   @return Std_ReturnType status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfTcpTransmit
(
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to prepare the message for If Pdu Tx 
*   @param[in] PduRouteDestIdx the pdu route destination idx
*   @param[in] PduInfoPtr pointer to the Pdu Info
*   @return Std_ReturnType status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfTcpPrepareTransmit
(
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
);

/* #! Tcp tx queue */
/*!******************************************************************************************************************
*   @brief This Api is used to initialize the Tx Tcp Queue of the Socket connection idx
*   @param[in] SoConIdx Socket connectio idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTcpQueueInit(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to check if the Tx Tcp queue of the socket connection idx is FULL.
*   @param[in] SoConIdx the socket connection idx
*   @return TRUE: Buffer is FULL, FALSE: Buffer is not FULL
********************************************************************************************************************/
boolean SoAd_TxTcpQueueIsFull(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to add element to the Tx Tcp queue.
*   @param[in] SoConIdx the socket connection idx
*   @param[in] PduRouteIdx the pdu route idx
*   @param[in] PduLength the pdu length 
*   @return Std_ReturnType status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
Std_ReturnType SoAd_TxTcpQueueAddElement
(
    SoAd_SoConIdType SoConIdx,
    SoAd_PduRouteIdxType PduRouteIdx,
    PduLengthType PduLength
);
/*!******************************************************************************************************************
*   @brief This Api is used to remove the element from the tx tcp queue with the requested pdu route idx
*   @param[in] SoConIdx the socket connection idx 
*   @param[in] PduRouteIdx the pdu route idx
*   @return Std_ReturnType status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
Std_ReturnType SoAd_TxTcpQueueRemoveElement(SoAd_SoConIdType SoConIdx,SoAd_PduRouteIdxType PduRouteIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the tx tcp queue confirmation
*   @param[in] SoConIdx the socket connection idx
*   @param[in] PduLength the pdu length 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTcpQueueTxConfirmation(SoAd_SoConIdType SoConIdx,PduLengthType PduLength);
/*!******************************************************************************************************************
*   @brief This Api is used to process confirmation notification of the tx tcp queue confirmation of Pdu route idx
*   @param[in] SoConIdx the socket connection idx
*   @param[in] PduRouteIdx the pdu route idx
*   @param[in] ByResetSoCon flag to indicate reset of SoCon TRUE: Reset required FALSE: Reset not required
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTcpQueueCallTxConfirmation
(
  SoAd_SoConIdType SoConIdx,
  SoAd_PduRouteIdxType PduRouteIdx,
  boolean ByResetSoCon
);
/*!******************************************************************************************************************
*   @brief This Api is used to clear the tcp tx queue for the SoCon Idx
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTcpQueueClear(SoAd_SoConIdType SoConIdx);

/* #! tp tx */
/*!******************************************************************************************************************
*   @brief This Api is used to check the tx tp protocol paramater and update if valid
*   @param[in] PduRouteIdx the pdu route idx
*   @param[in] PduLength the pdu length
*   @return status of the request E_OK: status accepted E_NOT_OK: status not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxTpCheckAndSetProtocolParameter
(
    SoAd_PduRouteIdxType PduRouteIdx,
    PduLengthType PduLength
);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the tp tranmsisison in main function call
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpTransmissionHandler(void);
/*!******************************************************************************************************************
*   @brief This Api is used to transmit the tp pdu route dest of the SoCon
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpTransmitPduRouteDest(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the cancellation of tcp transmit of the SoCon
*   @param[in] SoConIdx the socket connection idx 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpCancellationHandler(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to terminate the transmission of the Tx tp pdu
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpTerminateTransmit(SoAd_SoConIdType SoConIdx);
/* #! udp tp tx */
/*!******************************************************************************************************************
*   @brief This Api is used to handle the transmission of the Udp Tp Pdu
*   @param[in] SoConIdx the socket connection idx
*   @return Std_ReturnType status of the request E_OK:request accepted E_NOT_OK:request not accepted 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxTpUdpTransmit(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to copy the pdu header of udp tp tx pdu for the SoCon idx
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpUdpCopyPduHdr(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to copy the pdu data for udp tp tx pdu for the SoCon idx
*   @param[in] SoConIdx the socket connection idx
*   @return Std_ReturnType status of the request E_OK:request accepted E_NOT_OK:request not accepted 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxTpUdpCopyPdu(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to transmi the tx tp udp pdu on the socket
*   @param[in] SoConIdx the socket connection idx
*   @return Std_ReturnType status of the request E_OK:request accepted E_NOT_OK:request not accepted 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxTpUdpTransmitOnSocket(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to terminate the tx tp udp pdu either on successful / failure transmission
*   @param[in] SoConIdx the socket connection idx
*   @param[in] Result  indicates the tx status. E_OK: Tx success E_NOT_OK: Tx not success
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpUdpTerminateTransmit(SoAd_SoConIdType SoConIdx,Std_ReturnType Result);
/* #! tcp tp tx */
/*!******************************************************************************************************************
*   @brief This Api is used to transmit tcp tp pdu of the SoCon
*   @param[in] SoConIdx the socket connection idx
*   @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxTpTcpTransmit(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to calcaulate the transmit tcp length for the SoCon
*   @param[in] SoConIdx the socket connection idx 
*   @param[out] pAvailBufferLength pointer to update the available transmit tcp length
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpTcpCalculateLength
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(PduLengthType, AUTOMATIC, SOAD_APPL_VAR) pAvailBufferLength
);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the tcp transmit success of the SoCon
*   @param[in] SoConIdx the socket connection idx 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpTcpTransmitHandleSuccess(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the tcp transmit fail of the SoCon
*   @param[in] SoConIdx the socket connection idx 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpTcpTransmitHandleFail(SoAd_SoConIdType SoConIdx);

/* #! copy data */
/*!******************************************************************************************************************
*   @brief This Api is used to check the parameters for the Tx Copy api for the SoCon
*   @param[in] SoConIdx the socket connection idx
*   @param[in] BufferLength the buffer length 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxCopyTxDataCheckParameter
(
    SoAd_SoConIdType SoConIdx,
    uint16 BufferLength
);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the pdu header copy tx
*   @param[in] SoConIdx the socket connection idx
*   @param[in] PduRouteDestIdx the pdu route destination idx
*   @param[out] BufPtrPtr Pointer to buffer for transmission data
*   @param[out] BufLengthPtr pointer to Length data buffer.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxCopyTxDataPduHeader
(
    SoAd_SoConIdType SoConIdx,
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2VAR(uint8*, AUTOMATIC, SOAD_APPL_VAR) BufPtrPtr,
    P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) BufLengthPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to copy the pdu header to the buffer provided
*   @param[in] PduHeaderId pdu header id
*   @param[in] PduHeaderLen pdu header length
*   @param[out] BufPtr pointer to buffer for updating the pdu header
*   @param[in] Offset buffer index offset to which the pdu header to be udpated
*   @param[in] Length length of the buffer 
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_UtilCopyPduHdr2Buf
(
    SoAd_PduHeaderIdType  PduHeaderId,
    SoAd_PduHeaderLenType PduHeaderLen,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Offset,
    uint16 Length
);
/* #! copy data if udp */

/*!******************************************************************************************************************
*   @brief This Api is used to handle the udp tx if copy data
*   @param[in] SoConIdx the socket connection idx
*   @param[out] BufPtr Pointer to buffer for transmission data
*   @param[in] BufLength  data buffer Length.
*   @return BufReq_ReturnType status of the request BUFREQ_OK:request accepted BUFREQ_E_NOT_OK:request not accepted 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_TxIfUdpCopyTxData
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 BufLength
);
/*!******************************************************************************************************************
*   @brief This Api is used to process the trigger transmit copy data in the udp tx if copy data
*   @param[in] SoConIdx the socket connection idx
*   @param[in] PduRouteIdx the pdu route idx
*   @param[out] BufPtr Pointer to buffer for transmission data
*   @param[out] BufLengthPtr pointer to data buffer Length.
*   @return BufReq_ReturnType status of the request BUFREQ_OK:request accepted BUFREQ_E_NOT_OK:request not accepted 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_TxIfUdpCopyTxDataTrigger
(
    SoAd_SoConIdType SoConIdx,
    SoAd_PduRouteIdxType PduRouteIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) BufLengthPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the direct data copy in the udp tx if copy data
*   @param[in] SoConIdx the socket connection idx
*   @param[out] BufPtr Pointer to buffer for transmission data
*   @param[in] BufLength data buffer Length.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxIfUdpCopyTxDataDirect
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 BufLength
);
/* #! copy data if tcp */
/*!******************************************************************************************************************
*   @brief This Api is used to process the tcp if tx copy data call 
*   @param[in] SoConIdx the socket connection idx
*   @param[out] BufPtr Pointer to buffer for transmission data
*   @param[in] BufLength Length of provided data buffer.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxIfTcpCopyTxData
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 BufLength
);
/* #! copy data tp udp */
/*!******************************************************************************************************************
*   @brief This Api is used to handle the udp tx Tp copy data
*   @param[in] SoConIdx the socket connection idx
*   @param[out] BufPtr Pointer to buffer for transmission data
*   @param[in] BufLength data buffer Length.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpUdpCopyTxData
(
  SoAd_SoConIdType SoConIdx,
  P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
  uint16 BufLength
);
/* #! copy data tp tcp */
/*!******************************************************************************************************************
*   @brief This Api is used to handle the tcp tx copy data
*   @param[in] SoConIdx the socket connection idx
*   @param[in] PduRouteDestIdx the pdu route destination idx
*   @param[out] BufPtr Pointer to buffer for transmission data
*   @param[out] BufLengthPtr pointer to Length data buffer.
*   @return BufReq_ReturnType status of the request BUFREQ_OK:request accepted BUFREQ_E_NOT_OK:request not accepted 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_TxTpTcpCopyTxData
(
    SoAd_SoConIdType SoConIdx,
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 BufLength
);

/* #! Udp NPdu Tx */
/*!******************************************************************************************************************
*   @brief This Api is used to handle the udp tx if NPdu 
*   @param[in] PduRouteDestIdx the pdu route destination idx
*   @param[in] PduInfoPtr Pointer to pdu info
*   @param[out] ErrorIdPtr pointer to Error id
*   @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfUdpTransmitNPdu
(
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) ErrorIdPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to transmit the data from buffer for udp tx if NPdu 
*   @param[in] PduRouteDestIdx the pdu route destination idx
*   @param[in] PduInfoPtr Pointer to pdu info
*   @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfUdpTransmitNPduBuffer
(
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to add buffer element for the Udp Tx NPdu
*   @param[in] PduRouteIdx the pdu route idx
*   @param[in] PduRouteDestIdx the pdu route destination idx
*   @param[in] PduInfoPtr Pointer to pdu info
*   @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(SoAd_NPduReturnType, SOAD_CODE) SoAd_TxNPduUdpBufferAddElement
(
    SoAd_PduRouteIdxType PduRouteIdx,
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to haddle the transmission of the the Udp Tx NPdu
*   @param[in] NPduUdpTxIdx the Udp Tx NPdu idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxNPduUdpBufferSend(SoAd_NPduUdpTxIdxType NPduUdpTxIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to set the trigger timeout for the the Udp Tx NPdu
*   @param[in] NPduUdpTxIdx the Udp Tx NPdu idx
*   @param[in] PduRouteDestIdx the pdu route destination idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxNPduUdpSetTriggerTimeout
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx,
    SoAd_PduRouteDestIdxType PduRouteDestIdx
);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the tranmission of If the Udp Tx NPdu from the queue
*   @param[in] PduRouteDestIdx the pdu route destination idx
*   @param[in] PduInfoPtr Pointer to pdu info
*   @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfUdpTransmitNPduQueue
(
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to add or udpate element to the Udp NPdu tx queue
*   @param[in] PduRouteDestIdx the pdu route destination idx
*   @param[in] PduInfoPtr pointer to the pdu info
*   @return status of the request SOAD_NPDU_OK: request accepted SOAD_NPDU_NOT_OK: request not accepted 
*           SOAD_NPDU_OVFL_NEW : overflow occured due to addition of the pdu
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(SoAd_NPduReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueAddOrUpdateElement
(
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to udpate element to the Udp NPdu tx queue
*   @param[in] NPduUdpTxIdx the Udp NPdu tx idx
*   @param[in] PduRouteDestIdx the pdu route destination idx
*   @param[in] DataLen data length of the pdu
*   @param[out] ElementUpdated TRUE: element udpated FALSE: element not updated
*   @return status of the request SOAD_NPDU_OK: request accepted SOAD_NPDU_NOT_OK: request not accepted 
*           SOAD_NPDU_OVFL_NEW : overflow occured due to addition of the pdu
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(SoAd_NPduReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueUpdateElement
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx,
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    PduLengthType DataLen,
    P2VAR(boolean, AUTOMATIC, SOAD_APPL_VAR) ElementUpdated
);
/*!******************************************************************************************************************
*   @brief This Api is used to add element to the Udp NPdu tx queue
*   @param[in] NPduUdpTxIdx the Udp NPdu tx idx
*   @param[in] PduRouteDestIdx the pdu route destination idx
*   @param[in] DataLen data length of the pdu
*   @param[in] PduInfoPtr pointer to the pdu info
*   @return status of the request SOAD_NPDU_OK: request accepted SOAD_NPDU_NOT_OK: request not accepted 
*           SOAD_NPDU_OVFL_NEW : overflow occured due to addition of the pdu
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(SoAd_NPduReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueAddElement
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx,
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    PduLengthType DataLen,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the transmission of the Udp NPdu tx queue
*   @param[in] NPduUdpTxIdx the Udp NPdu tx idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxNPduUdpQueueTransmit(SoAd_NPduUdpTxIdxType NPduUdpTxIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to prepare the buffer for the Udp NPdu tx segment transmission
*   @param[in] NPduUdpTxIdx the Udp NPdu tx idx
*   @return statu of the request E_OK:request accepted E_NOT_OK:request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxNPduUdpQueuePrepareTransmitSegment
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx
);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the Udp NPdu tx segment transmission
*   @param[in] NPduUdpTxIdx the Udp NPdu tx idx
*   @return statu of the request E_OK:request accepted E_NOT_OK:request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueTransmitSegment
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx
);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the transmit completion of the Udp NPdu tx segment
*   @param[in] NPduUdpTxIdx the Udp NPdu tx idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxNPduUdpQueueFinishTransmitSegment
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx
);
/*!******************************************************************************************************************
*   @brief This Api is used to get the pdu length upto the Udp NPdu tx queue overflow
*   @param[in] NPduUdpTxIdx the Udp NPdu tx idx
*   @return length upto the Udp NPdu tx queue overflow
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(uint16, SOAD_CODE) SoAd_TxNPduUdpQueueGetNPduLengthUpToOverflow(SoAd_NPduUdpTxIdxType NPduUdpTxIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to clear the pending tx of Udp NPdu tx queue 
*   @param[in] NPduUdpTxIdx the Udp NPdu tx idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxNPduUdpClear(SoAd_NPduUdpTxIdxType NPduUdpTxIdx);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the confirmation of the Udp NPdu tx queue 
*   @param[in] SoConIdx the socekt connection idx
*   @param[in] PduRouteIdx the pdu route idx
*   @param[in] AllowReconnect reconnect request TRUE: request reconnect FALSE: no reconnect request
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxNPduUdpQueueTxConfirmation
(
    SoAd_SoConIdType SoConIdx,
    SoAd_PduRouteIdxType PduRouteIdx,
    boolean AllowReconnect
);
/*!******************************************************************************************************************
*   @brief This Api is used to check the Udp NPdu buffer queue and set transmit state if data is present
*   @param[in] NPduUdpTxIdx the Udp NPdu tx idx
*   @return status of the request E_OK: if transmit state set E_NOT_OK: if transmit state not set
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueCheckAndSetTransmitState
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx
);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the copy tx data of Udp NPdu buffer
*   @param[in] NPduUdpTxIdx the Udp NPdu tx idx
*   @param[out] BufPtr pointer to data buffer Length.
*   @param[in] BufLength data buffer Length.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxNPduUdpBufferCopyTxData
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 BufLength
);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the copy tx data of Udp NPdu queue
*   @param[in] NPduUdpTxIdx the Udp NPdu tx idx
*   @param[out] BufPtr pointer to data buffer Length.
*   @param[out] BufLengthPtr pointer to data buffer Length.
*   @return BufReq_ReturnType status of the request BUFREQ_OK:request accepted BUFREQ_E_NOT_OK:request not accepted 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueCopyTxData
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) BufLengthPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the copy tx data of Udp NPdu buffer
*   @param[in] NPduUdpTxQueueIdx the Udp NPdu tx queue idx
*   @param[out] BufPtr pointer to data buffer Length.
*   @param[out] BufLengthPtr pointer to data buffer Length.
*   @return BufReq_ReturnType status of the request BUFREQ_OK:request accepted BUFREQ_E_NOT_OK:request not accepted 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueCopyTxDataBuffer
(
    SoAd_NPduUdpTxQueueIdxType NPduUdpTxQueueIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) BufLengthPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to handle for trigger transmit of copy tx data of Udp NPdu queue
*   @param[in] NPduUdpTxIdx the Udp NPdu tx idx
*   @param[in] NPduUdpTxQueueIdx the Udp NPdu tx queue idx
*   @param[out] BufPtr pointer to data buffer Length.
*   @param[out] BufLengthPtr pointer to data buffer Length.
*   @return BufReq_ReturnType status of the request BUFREQ_OK:request accepted BUFREQ_E_NOT_OK:request not accepted 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueCopyTxDataTrigger
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx,
    SoAd_NPduUdpTxQueueIdxType NPduUdpTxQueueIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) BufLengthPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to prepare for trigger transmit call of copy tx data of Udp NPdu queue
*   @param[in] NPduUdpTxIdx the Udp NPdu tx idx
*   @param[out] BufPtr pointer to data buffer Length.
*   @param[in] BufLength data buffer Length.
*   @param[out] PduInfoPtr pointer to pdu info
*   @return BufReq_ReturnType status of the request BUFREQ_OK:request accepted BUFREQ_E_NOT_OK:request not accepted 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueCopyTxDataTriggerPrepare
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 BufLength,
    P2VAR(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the trigger transmit call for copy tx data of Udp NPdu queue
*   @param[in] NPduUdpTxIdx the Udp NPdu tx idx
*   @param[in] NPduUdpTxQueueIdx the Udp NPdu tx queue idx
*   @param[out] BufLengthPtr pointer to data buffer Length.
*   @param[out] PduInfoPtr pointer to pdu info
*   @return BufReq_ReturnType status of the request BUFREQ_OK:request accepted BUFREQ_E_NOT_OK:request not accepted 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueCopyTxDataTriggerCall
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx,
    SoAd_NPduUdpTxQueueIdxType NPduUdpTxQueueIdx,
    P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) BufLengthPtr,
    P2VAR(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the trigger transmit of pdu header for Udp NPdu queue
*   @param[in] NPduUdpTxQueueIdx the Udp NPdu tx queue idx
*   @param[out] BufPtr Pointer to buffer for transmission data
*   @param[out] BufLengthPtr pointer to data buffer Length.
*   @param[in] PduInfoPtr pointer to pdu info
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxNPduUdpQueueCopyTxDataTriggerAddPduHeader
(
    SoAd_NPduUdpTxQueueIdxType NPduUdpTxQueueIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) BufLengthPtr,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the copy data for the the Udp NPdu of the SoCon idx
*   @param[in] SoConIdx the socket connection idx
*   @param[out] BufPtr Pointer to buffer for transmission data
*   @param[out] BufLengthPtr pointer to data buffer Length.
*   @return BufReq_ReturnType status of the request BUFREQ_OK:request accepted BUFREQ_E_NOT_OK:request not accepted 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_TxNPduUdpCopyTxData
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) BufLengthPtr
);
/*!******************************************************************************************************************
*   @brief This Api is used to handle the transmission of the Udp NPdu for the Udp NPdu idx
*   @param[in] NPduUdpTxIdx the Udp NPdu tx idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxNPduUdpTransmit(SoAd_NPduUdpTxIdxType NPduUdpTxIdx);
#define SOAD_STOP_SEC_CODE
#include "MemMap.h"
/********************************************************************************************************************
*  #! PUBLIC FUNCTION IMPLEMENTATION                                                                                *
********************************************************************************************************************/
#define SOAD_START_SEC_CODE
#include "MemMap.h" 
/********************************************************************************************************************
*   @brief This Api is used to intialize the tx for the SoCon idx
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TxSoConInit(SoAd_SoConIdType SoConIdx)
{
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_TpTxBufferIdxType TpTxBufferCfgIdx;
    /* Initialize the Tx Pdu Ctrl status */
    if (SoAd_SoConCfgIsPduRouteSupported(SoConIdx) == TRUE)
    {
        TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx);
        SoAd_SoConTxPduCtrlSetCancelRequest(TxPduCtrlIdx,FALSE);
        SoAd_SoConTxPduCtrlSetPduRouteDestIdx(TxPduCtrlIdx,SoAd_CfgGetNumOfPduRouteDest());
        SoAd_SoConTxPduCtrlSetTxBytesLen(TxPduCtrlIdx,0u);
        SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,0u);
        SoAd_SoConTxPduCtrlSetpBuffer(TxPduCtrlIdx,NULL_PTR);
    }
    /* Initialize Tx Tp buffer. */
    TpTxBufferCfgIdx = SoAd_SoConCfgGetTpTxBufferCfgIdx(SoConIdx);
    if (TpTxBufferCfgIdx != SoAd_CfgGetNumOfTpTxBuffer())
    {
        SoAd_TpTxBufferCtrlSetCurrentBufferIdx(TpTxBufferCfgIdx,SoAd_TpTxBufferCfgGetBufferStartIdx(TpTxBufferCfgIdx));
    }
    /* Initialize Tx TCP queue */
    SoAd_TxTcpQueueInit(SoConIdx);
}
/********************************************************************************************************************
*   @brief This Api is used to intialize the tx properties
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TxInit(void)
{
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx; 
    /* Initialize PduRoute status */
    for(PduRouteIdx = 0u; PduRouteIdx < SoAd_CfgGetNumOfPduRoute(); PduRouteIdx++)
    {
        SoAd_PduRouteCtrlSetPendingTxConfInMain(PduRouteIdx,FALSE);
        SoAd_PduRouteCtrlSetNumOfPendingTxConf(PduRouteIdx,0U);
    }
    /* Initialize nPduUdpTx status  */
    for (NPduUdpTxIdx = 0u; NPduUdpTxIdx < SoAd_CfgGetNumOfNPduUdpTx(); NPduUdpTxIdx++ )
    {
        SoAd_TxNPduUdpClear(NPduUdpTxIdx);
    }
}
/********************************************************************************************************************
*   @brief This Api is used to initialize the udp alive timer
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_UdpAliveTimerInit(void)
{
    SoAd_UdpAliveTimerIdxType UdpAliveTimerIdx;
    for (UdpAliveTimerIdx = 0U;UdpAliveTimerIdx < SoAd_CfgGetNumOfUdpAliveTimer();UdpAliveTimerIdx++)
    {
        SoAd_CtrlSetTxUdpAliveTimer(UdpAliveTimerIdx,0U);
    }
}
/********************************************************************************************************************
*   @brief This Api is used to intialize the Udp Npdu tx timer 
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TxUdpNPduTimerInit(void)
{
    SoAd_NPduUdpTxTimerIdxType NPduUdpTxTimerIdx;
    for (NPduUdpTxTimerIdx = 0U;NPduUdpTxTimerIdx < SoAd_CfgGetNumOfNPduUdpTxTimer();NPduUdpTxTimerIdx++)
    {
        SoAd_CtrlSetTxUdpNPduTimer(NPduUdpTxTimerIdx,0U);
    }
}
/********************************************************************************************************************
*   @brief This Api is used to update the alive timer for the SoCon Idx
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_UpdateUdpAliveTimeout(SoAd_SoConIdType SoConIdx)
{
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SocketUdpIdxType SocketUdpIdx;
    SoAd_UdpAliveTimerIdxType UdpAliveTimerIdx;
    
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    if (SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE)
    {
        SocketUdpIdx = SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx);
        if ((SoAd_SocketUdpCfgGetAliveSupervisionTime(SocketUdpIdx) > 0U) && 
            (SoAd_SocketUdpCfgGetTxUdpAliveTimerIdx(SocketUdpIdx) != SOAD_NUM_OF_TX_UDP_ALIVE_TIMER))
        {
            UdpAliveTimerIdx = SoAd_SocketUdpCfgGetTxUdpAliveTimerIdx(SocketUdpIdx);
            /* Update timer if it's  running */
            if(SoAd_CtrlGetTxUdpAliveTimer(UdpAliveTimerIdx) > 0U)
            {
                SoAd_CtrlSetTxUdpAliveTimer(UdpAliveTimerIdx,SoAd_SocketUdpCfgGetAliveSupervisionTime(SocketUdpIdx));
            }
        }
    }
}
/********************************************************************************************************************
*   @brief This Api is used to start the alive timer for the SoCon Idx
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_StartUdpAliveTimeout(SoAd_SoConIdType SoConIdx)
{
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SocketUdpIdxType SocketUdpIdx;
    SoAd_UdpAliveTimerIdxType UdpAliveTimerIdx;
    
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    if (SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE)
    {
        SocketUdpIdx = SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx);
        if ((SoAd_SocketUdpCfgGetAliveSupervisionTime(SocketUdpIdx) > 0U) && 
            (SoAd_SocketUdpCfgGetTxUdpAliveTimerIdx(SocketUdpIdx) != SOAD_NUM_OF_TX_UDP_ALIVE_TIMER))
        {
            UdpAliveTimerIdx = SoAd_SocketUdpCfgGetTxUdpAliveTimerIdx(SocketUdpIdx);
            SoAd_CtrlSetTxUdpAliveTimer(UdpAliveTimerIdx,SoAd_SocketUdpCfgGetAliveSupervisionTime(SocketUdpIdx));
        }
    }
}
/********************************************************************************************************************
*   @brief This Api is used to handle the alive timer expiry for the SoCon Idx
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_UdpAliveTimeoutHandler(SoAd_SoConIdType SoConIdx)
{
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SocketUdpIdxType SocketUdpIdx;
    SoAd_UdpAliveTimerIdxType UdpAliveTimerIdx;
    
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    if (SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE)
    {
        SocketUdpIdx = SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx);
        if (SoAd_SocketUdpCfgGetTxUdpAliveTimerIdx(SocketUdpIdx) != SOAD_NUM_OF_TX_UDP_ALIVE_TIMER)
        {
            UdpAliveTimerIdx = SoAd_SocketUdpCfgGetTxUdpAliveTimerIdx(SocketUdpIdx);
            /* Update timer if it's  running */
            if(SoAd_CtrlGetTxUdpAliveTimer(UdpAliveTimerIdx) > 0U)
            {
                SoAd_CtrlDecTxUdpAliveTimer(UdpAliveTimerIdx);
                if (SoAd_CtrlGetTxUdpAliveTimer(UdpAliveTimerIdx) == 0u)
                {
                    if ((SoAd_SoConCtrlGetSoConMode(SoConIdx) == SOAD_SOCON_ONLINE) &&
                        (SoAd_SoConCtrlGetCloseReqType(SoConIdx) == SOAD_CLOSE_REQ_NONE))
                    {
                        SoAd_SoConCtrlSetCloseReqType(SoConIdx,SOAD_CLOSE_REQ_RECONNECT);
                    }
                }
            }
        }
    }
}
/********************************************************************************************************************
*   @brief This Api is used to reset the the alive timer for the SoCon Idx
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SoConResetUdpAliveTimeout(SoAd_SoConIdType  SoConIdx)
{
    SoAd_SoConGrpIdxType  SoConGrpIdx;
    SoAd_SocketUdpIdxType SocketUdpIdx;
    SoAd_UdpAliveTimerIdxType UdpAliveTimerIdx;
    
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    SocketUdpIdx = SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx);
    UdpAliveTimerIdx = SoAd_SocketUdpCfgGetTxUdpAliveTimerIdx(SocketUdpIdx);
    if (UdpAliveTimerIdx != SoAd_CfgGetNumOfUdpAliveTimer())
    {
        SoAd_CtrlSetTxUdpAliveTimer(UdpAliveTimerIdx,0U);
    }
}
/*!******************************************************************************************************************
*   @brief This Api is used to terminate the pending tx for the SoCon Idx
*   @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TxTerminateTransmit(SoAd_SoConIdType SoConIdx)
{
    /* terminate tp transmit status */
    SoAd_TxTpTerminateTransmit(SoConIdx);
    /* clear tcp queue */
    SoAd_TxTcpQueueClear(SoConIdx);
    /* clear Npdu status */
    if (SoAd_SoConCfgIsUdpNPduSupported(SoConIdx) == TRUE) 
    {
        SoAd_TxNPduUdpClear(SoAd_SoConCfgGetNPduUdpTxIdx(SoConIdx));
    }
}
/********************************************************************************************************************
*   @brief This Api is used to get the unconfirmed transmit data of the socket idx 
*   @param[in] SocketIdx the socket idx
*   @return the unconfirmed data length
********************************************************************************************************************/
FUNC(uint32, SOAD_CODE) SoAd_TxTcpGetUnconfirmedDataLength(SoAd_SocketIdxType SocketIdx)
{
    SoAd_TcpTxQueueIdxType TcpTxQueueIdx;
    SoAd_SoConIdType SoConIdx;
    
    SoConIdx = SoAd_SocketCfgGetSoConStartIdx(SocketIdx);
    TcpTxQueueIdx = SoAd_SoConCfgGetTcpTxQueueIdx(SoConIdx);
    return SoAd_TcpTxQueueCtrlGetTotalLength(TcpTxQueueIdx);
}
/********************************************************************************************************************
*   @brief This Api is used to process the transmit and confirmation handling in the main function
********************************************************************************************************************/
void SoAd_TxMainFunction(void)
{
    /* process Pdu transmission. */
    SoAd_TxTransmissionHandler();
    SoAd_TcpIpBsdMainFunctionTx();
    /* process routing group transmission request */
    SoAd_RouteGrpIfTransmitHandler();
    /* process Tx Pdu confirmation handler */
    SoAd_TxConfirmationHandler();
}
/********************************************************************************************************************
*   @brief      Requests transmission of a PDU.
*   @param[in]  TxPduId  Identifier of the PDU to be transmitted
*   @param[in]  PduInfoPtr  Length of and pointer to the PDU data and pointer to MetaData
*   @return     Std_ReturnType E_OK: Transmit request has been accepted.
*               E_NOT_OK: Transmit request has not been accepted.
*   @ServiceID  0x49
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_IfTransmit
( 
    PduIdType TxPduId,
    P2CONST(PduInfoType,AUTOMATIC,SOAD_APPL_CONST) PduInfoPtr 
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = SOAD_E_NO_ERROR;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_CfgGetNumOfTxPdu() <= TxPduId)
    {
        ErrorId = SOAD_E_INV_PDUID;
    }
    else if (PduInfoPtr == NULL_PTR)
    {
        ErrorId = SOAD_E_PARAM_POINTER;
    }
    else
    {   
        if ((SoAd_PduRouteCfgGetPduRouteULType(TxPduId) == SOAD_UPPER_LAYER_TYPE_TP) || 
            ((SoAd_PduRouteCfgIsIfTriggerTxEnabled(TxPduId) != TRUE) && (PduInfoPtr->SduDataPtr == NULL_PTR)))
        {
            ErrorId = SOAD_E_INV_ARG;
        }
        else
        {
            /* Check minimum lengt for Tx*/
            if ((PduInfoPtr->SduLength >= SoAd_PduRouteCfgGetMinimumLength(TxPduId)) && 
                (SoAd_TxIfCheckTxState(TxPduId) == E_OK ))
            {
                RetVal = SoAd_TxIfTransmitPdu(TxPduId, PduInfoPtr, &ErrorId); 
            }
        }   
    }
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
      SoAd_DetReportError(SOAD_IFTRANSMIT_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      Triggers the transmission of all If-TxPDUs identified by the parameter id after requesting the data
*               from the related upper layer.
*   @param[in]  id  routing group identifier indirectly specifying PDUs to be transmitted
*   @return     Std_ReturnType Result of operation E_OK The request was successful 
*               E_NOT_OK The request was not successful.
*   @ServiceID  0x1D
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_IfRoutingGroupTransmit(SoAd_RoutingGroupIdType id)
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_RgPduRouteDestIdxType RgPduRouteDestIdx;
    /* check for dev error */   
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_CfgGetNumOfRoutingGroup() <= id)
    {
        ErrorId = SOAD_E_INV_ARG;
    }
    else 
    {
        if (SoAd_RoutingGroupCfgGetIsTriggerable(id) == TRUE)
        {
            /* Update the status for PduRouteDest's routing group */
            for(RgPduRouteDestIdx = SoAd_RoutingGroupCfgGetRgPduRouteDestStartIdx(id);
                RgPduRouteDestIdx <= SoAd_RoutingGroupCfgGetRgPduRouteDestEndIdx(id);RgPduRouteDestIdx++)
            {
                SoAd_RoutingGroupPduRouteDestCtrlSetTriggerRequest(RgPduRouteDestIdx,TRUE);
            }
            /* Set flag to process the event in the Main function */
            SoAd_CtrlSetRoutingGroupEventCtrlStatus(id,TRUE);
            RetVal = E_OK;
        }
        else
        {
            ErrorId = SOAD_E_INV_ARG;
        }
    }

#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
      SoAd_DetReportError(SOAD_IFROUTINGGROUPTRANSMIT_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      Triggers the transmission of all If-TxPDUs identified by the parameter id on the socket connection 
*               specified by SoConId after requesting the data from the related upper layer.
*   @param[in]  id  routing group identifier indirectly specifying PDUs to be transmitted
*   @param[in]  SoConId  socket connection index specifying the socket connection on which the PDUs shall be 
*               transmitted
*   @return     Std_ReturnType Result of operation E_OK The request was successful 
*               E_NOT_OK The request was not successful.
*   @ServiceID  0x1F
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_IfSpecificRoutingGroupTransmit
(
    SoAd_RoutingGroupIdType id,
    SoAd_SoConIdType SoConId 
)
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_RgPduRouteDestIdxType RgPduRouteDestIdx;
    /* check for dev error */
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if ((SoAd_CfgGetNumOfRoutingGroup() <= id) && (SoAd_CfgGetNumOfSoCon() <= SoConId))
    {
        ErrorId = SOAD_E_INV_ARG;
    }
    else 
    {
        if (SoAd_RoutingGroupCfgGetIsTriggerable(id) == TRUE)
        {
            /* Update the status for PduRouteDest's routing group */
            for(RgPduRouteDestIdx = SoAd_RoutingGroupCfgGetRgPduRouteDestStartIdx(id);
                RgPduRouteDestIdx <= SoAd_RoutingGroupCfgGetRgPduRouteDestEndIdx(id);RgPduRouteDestIdx++)
            {
                if (SoAd_PduRouteDestCfgGetSoConIdx(RgPduRouteDestIdx) == SoConId)
                {
                    SoAd_RoutingGroupPduRouteDestCtrlSetTriggerRequest(RgPduRouteDestIdx,TRUE);
                    RetVal = E_OK;
                }
            }
            if (RetVal == E_OK)
            {
                /* Set flag to process the event in the Main function */
                SoAd_CtrlSetRoutingGroupEventCtrlStatus(id,TRUE);
            }
        }
        else
        {
            ErrorId = SOAD_E_INV_ARG;
        }
    }

#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
      SoAd_DetReportError(SOAD_IFSPECIFICROUTINGGROUPTRANSMIT_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      Requests transmission of a PDU.
*   @param[in]  TxPduId  Identifier of the PDU to be transmitted
*   @param[in]  PduInfoPtr  Length of and pointer to the PDU data and pointer to MetaData
*   @return     Std_ReturnType E_OK: Transmit request has been accepted. 
*               E_NOT_OK: Transmit request has not been accepted.
*   @ServiceID  0x49
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId 
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpTransmit
( 
    PduIdType TxPduId,
    P2CONST(PduInfoType,AUTOMATIC,SOAD_APPL_CONST) PduInfoPtr 
)
{
    SoAd_SoConIdType  SoConIdx;
    SoAd_SocketIdxType  SocketIdx;
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SoConGrpIdxType  SoConGrpIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_PduRouteDestIdxType  PduRouteDestIdx;
    /* check for dev error */   
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SoAd_CfgGetNumOfTxPdu() <= TxPduId)
    {
        ErrorId = SOAD_E_INV_PDUID;
    }
    else if (PduInfoPtr == NULL_PTR)
    {
        ErrorId = SOAD_E_PARAM_POINTER;
    }
    else
    {
        PduRouteDestIdx = SoAd_PduRouteCfgGetPduRouteDestStartIdx(TxPduId);
        SoConIdx = SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx);
        SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
        TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx) ;
        if (SoAd_PduRouteCfgGetPduRouteULType(TxPduId) == SOAD_UPPER_LAYER_TYPE_TP)
        {
            /* Check Tp Tx parameters and SoCon states */
            if ((PduInfoPtr->SduLength > 0u) && 
                (SoAd_SoConCtrlGetCloseReqType(SoConIdx) == SOAD_CLOSE_REQ_NONE) &&
                (SoAd_SoConCtrlGetSoConMode(SoConIdx) == SOAD_SOCON_ONLINE))
            {
                SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConIdx);
                /* Check if routing group is enabled */
                if (SoAd_CheckRoutingGroupPduDestEnabled(PduRouteDestIdx) == TRUE)
                {
                    SoAd_EnterCriticalSection();
                    /* Check if not Tx in progress for this SoCon */
                    if (SoAd_SocketCtrlGetActiveTxSoCon(SocketIdx) == SoAd_CfgGetNumOfSoCon())
                    {
                        if (SoAd_TxTpCheckAndSetProtocolParameter(TxPduId, PduInfoPtr->SduLength) == E_OK)
                        {
                            /* Update SoCon TxPdu Ctrl status */
                            SoAd_SoConTxPduCtrlSetPduRouteDestIdx(TxPduCtrlIdx,PduRouteDestIdx);
                            /* Update the tx length based on Pdu Header */
                            if (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
                            {
                                SoAd_SoConTxPduCtrlSetTxBytesLen(TxPduCtrlIdx,
                                                                (PduInfoPtr->SduLength + SOAD_PDU_HEADER_SIZE));
                                SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,
                                                                (PduInfoPtr->SduLength + SOAD_PDU_HEADER_SIZE));
                            }
                            else
                            {
                                SoAd_SoConTxPduCtrlSetTxBytesLen(TxPduCtrlIdx,PduInfoPtr->SduLength);
                                SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,PduInfoPtr->SduLength);
                            }
                            /* Set SoConIdx for tx on the socket */
                            SoAd_SocketCtrlSetActiveTxSoCon(SocketIdx,SoConIdx);
                            /* Set flag to handle Tp transmission in the Main function */
                            SoAd_SoConEventCtrlSetEventTpTx(SoConIdx,TRUE);
                            RetVal = E_OK;
                        }
                    }   
                    SoAd_ExitCriticalSection();
                }
            }
        }
        else
        {
            ErrorId = SOAD_E_INV_PDUID;
        }
    }

#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
      SoAd_DetReportError(SOAD_TPTRANSMIT_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      This service requests to copy data for transmission to the buffer indicated. This call is triggered
*               by TcpIp_Transmit(). Note: The call to <Up>_CopyTxData() may happen in the context of TcpIp_Transmit().
*   @param[in]  SocketId Socket identifier of the related local socket resource.
*   @param[out] BufPtr Pointer to buffer for transmission data
*   @param[in]  BufLength Length of provided data buffer.
*   @return     BufReq_ReturnType BUFREQ_OK: Data has been copied to the transmit buffer completely as requested.
*               BUFREQ_E_NOT_OK: Data has not been copied. Request failed. (No further action for TcpIp required.
*               Later the upper layer might either close the socket or retry the transmit request)
*   @ServiceID  0x13
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different SocketIds. Non reentrant for the same SocketId 
********************************************************************************************************************/
FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_CopyTxData
( 
    TcpIp_SocketIdType SocketId,
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_VAR) BufPtr,
    uint16 BufLength 
)
{
    SoAd_SoConIdType SoConIdx;
    uint8 ErrorId = SOAD_E_NO_ERROR;
    SoAd_SocketIdxType LocalSocketIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    BufReq_ReturnType RetVal = BUFREQ_E_NOT_OK;
    /* check for dev error */   
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (BufLength == 0u)
    {
        ErrorId = SOAD_E_INV_ARG;        
    }
    else if(E_NOT_OK == SoAd_SocketGetSocketIdxByTcpIpSocketId(SocketId,&LocalSocketIdx))
    {
        ErrorId = SOAD_E_INV_SOCKETID;
    }
    else
    {
        SoConIdx = SoAd_SocketCtrlGetActiveTxSoCon(LocalSocketIdx);
        /* Check if the paramateres are valid for processing the copy data */
        if(SoAd_TxCopyTxDataCheckParameter(SoConIdx,BufLength) == E_OK)
        {
            TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx) ;
            PduRouteDestIdx = SoAd_SoConTxPduCtrlGetPduRouteDestIdx(TxPduCtrlIdx);
            PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
            SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
            if(SoAd_PduRouteCfgGetPduRouteULType(PduRouteIdx) == SOAD_UPPER_LAYER_TYPE_IF)
            {
                if(SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE)
                {
                    /* copy data for Tcp IF-API */
                    SoAd_TxIfTcpCopyTxData(SoConIdx, BufPtr, BufLength); 
                    RetVal = BUFREQ_OK;
                }
                else
                {
                    /* copy data for Udp IF-API */
                    RetVal = SoAd_TxIfUdpCopyTxData(SoConIdx, BufPtr, BufLength);
                }
            }
            else
            {
                if(SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE)
                {
                    /* copy data for Tcp Tp-API */
                    RetVal = SoAd_TxTpTcpCopyTxData(SoConIdx, PduRouteDestIdx, BufPtr, BufLength);
                }
                else
                {
                    /* copy data for Udp Tp-API */
                    SoAd_TxTpUdpCopyTxData(SoConIdx, BufPtr, BufLength);
                    RetVal = BUFREQ_OK;
                }
            }
        }
    }

#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
      SoAd_DetReportError(SOAD_COPYTXDATA_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif	
    return RetVal;
}
/********************************************************************************************************************
*   @brief      Requests cancellation of an ongoing transmission of a PDU in a lower layer communication module.
*   @param[in]  TxPduId  Identification of the PDU to be cancelled.
*   @return     Std_ReturnType E_OK: Cancellation was executed successfully by the destination module. 
*               E_NOT_OK: Cancellation was rejected by the destination module.
*   @ServiceID  0x4a
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId 
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpCancelTransmit( PduIdType TxPduId )
{
    SoAd_SoConIdType SoConIdx;
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    
    if(SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if(SoAd_CfgGetNumOfTxPdu() <= TxPduId)
    {
        ErrorId = SOAD_E_INV_PDUID;
    }
    else
    {
        PduRouteDestIdx = SoAd_PduRouteCfgGetPduRouteDestStartIdx(TxPduId);
        SoConIdx = SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx);
        TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx);
        if (SoAd_PduRouteCfgGetPduRouteULType(TxPduId) == SOAD_UPPER_LAYER_TYPE_TP)
        {
            /* If Tp Tx in progress , set cancel request and TpTx even to process in main function */
            if (PduRouteDestIdx == SoAd_SoConTxPduCtrlGetPduRouteDestIdx(TxPduCtrlIdx))
            {
                SoAd_SoConTxPduCtrlSetCancelRequest(TxPduCtrlIdx,TRUE);
                SoAd_SoConEventCtrlSetEventTpTx(SoConIdx,TRUE);
                RetVal = E_OK;
            }
        }
        else
        {
            ErrorId = SOAD_E_INV_PDUID;
        }
    }

#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
      SoAd_DetReportError(SOAD_TPCANCELTRANSMIT_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      The TCP/IP stack calls this function after the data has been acknowledged by the peer for TCP.
*   @param[in]  SocketId Socket identifier of the related local socket resource.
*   @param[in]  Length Number of transmitted data bytes.
*   @ServiceID  0x14
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different SocketIds. Non reentrant for the same SocketId 
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TxConfirmation(TcpIp_SocketIdType SocketId,uint16 Length)
{
    SoAd_SoConIdType SoConIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    uint8 ErrorId = SOAD_E_NO_ERROR;
    SoAd_SocketIdxType LocalSocketIdx = 0u;
    
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if ((Length == 0u) || (E_NOT_OK == SoAd_SocketGetSocketIdxByTcpIpSocketId(SocketId,&LocalSocketIdx))) 
    {
        ErrorId = SOAD_E_INV_ARG;
    }
    else 
    {
        SoConIdx = SoAd_SocketCfgGetSoConStartIdx(LocalSocketIdx);
        SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
        if(SoAd_SoConCfgIsPduRouteSupported(SoConIdx) == TRUE)
        {
            /* Process transmit if the SoCon and Socket states are valid */
            if ((SoAd_SocketCtrlGetSocketState(LocalSocketIdx) == SOAD_SOCK_STATE_ESTABLISHED) &&
                (SoAd_SoConCtrlGetSoConMode(SoConIdx) == SOAD_SOCON_ONLINE) &&
                (SoAd_SoConCtrlGetCloseReqType(SoConIdx) == SOAD_CLOSE_REQ_NONE))
            {
                if(SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE)
                {
                    SoAd_TxTcpQueueTxConfirmation(SoConIdx,(PduLengthType)Length);
                }
                else
                {
                    SoAd_TxUdpImmediateIfTxConfirmation(SoConIdx);
                }
            }
        }
    }

#if (SOAD_DEV_ERROR_DETECT == STD_ON)
    if (SOAD_E_NO_ERROR != ErrorId)
    {
      SoAd_DetReportError(SOAD_TXCONFIRMATION_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*  #! PRIVATE FUNCTION IMPLEMENTATION			                                                                    *
********************************************************************************************************************/
/********************************************************************************************************************
*   @brief This Api is used to check if the routing group for the pdu route destination is enabled
********************************************************************************************************************/
/* #! routing group */
boolean SoAd_CheckRoutingGroupPduDestEnabled(SoAd_PduRouteDestIdxType PduRouteDestIdx)
{
    boolean Enabled = FALSE;
    SoAd_RgPduRouteDestMapIdxType RgPduRouteDestMapIdx;
    SoAd_RgPduRouteDestIdxType RgPduRouteDestIdx;
    
    for(RgPduRouteDestMapIdx= SoAd_PduRouteDestCfgGetRgPduRouteDestMapStartIdx(PduRouteDestIdx);
        RgPduRouteDestMapIdx<= SoAd_PduRouteDestCfgGetRgPduRouteDestMapEndIdx(PduRouteDestIdx);RgPduRouteDestMapIdx++)
    {
        RgPduRouteDestIdx = SoAd_RgPduRouteDestMapCfgGetRgPduRouteDestIdx(RgPduRouteDestMapIdx);
        if (SoAd_RoutingGroupPduRouteDestCtrlGetEnabled(RgPduRouteDestIdx) == TRUE)
        {
            Enabled = TRUE;
            break;
        }
    }
    return Enabled;
}
/********************************************************************************************************************
*   @brief This Api is used to handle the routing group if transmit
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_RouteGrpIfTransmitHandler(void)
{
    PduInfoType PduInfo;
    boolean IsTriggerRequested;
    SoAd_ULIdxType PduRouteULIdx;
    uint8 ErrorId=SOAD_E_NO_ERROR;
    SoAd_PduRouteIdxType PrevRouteIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    SoAd_RgPduRouteDestIdxType RgPduRouteDestIdx;
    SoAd_RgPduRouteDestMapIdxType RgPduRouteDestMapIdx;
    SoAd_UpIfTriggerTransmitFuncType pUpIfTriggerTransmitFunc;
    
    PrevRouteIdx = SoAd_CfgGetNumOfPduRoute();
    for(PduRouteDestIdx=0u;PduRouteDestIdx<SoAd_CfgGetNumOfPduRouteDest();PduRouteDestIdx++)
    {
        IsTriggerRequested = FALSE;
        /* Check if the triggerable is enabled for this Pdu */
        for(RgPduRouteDestMapIdx = SoAd_PduRouteDestCfgGetRgPduRouteDestMapStartIdx(PduRouteDestIdx);
            RgPduRouteDestMapIdx <= SoAd_PduRouteDestCfgGetRgPduRouteDestMapEndIdx(PduRouteDestIdx);
            RgPduRouteDestMapIdx++)
        {
            RgPduRouteDestIdx = SoAd_RgPduRouteDestMapCfgGetRgPduRouteDestIdx(RgPduRouteDestMapIdx);
            if (SoAd_RoutingGroupPduRouteDestCtrlGetTriggerRequest(RgPduRouteDestIdx) == TRUE)
            {
                IsTriggerRequested = TRUE;
                SoAd_RoutingGroupPduRouteDestCtrlSetTriggerRequest(RgPduRouteDestIdx,FALSE);
            }
        }
        
        if (IsTriggerRequested == TRUE)
        {
            if ((PrevRouteIdx != SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx)) || 
                (PrevRouteIdx == SoAd_CfgGetNumOfPduRoute()))
            {
                /* Get data from upper layer and try to transmit the data */
                PduInfo.SduDataPtr = SoAd_CtrlGetPtrToRoutingGroupIfTxBuffer(0); 
                PduInfo.SduLength = SoAd_CfgGetRoutingGroupIfTxBufferSize();
                PduRouteULIdx = SoAd_PduRouteCfgGetPduRouteULIdx(SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx));
                pUpIfTriggerTransmitFunc = SoAd_UpperLayerCfgGetUpIfTriggerTransmitFunc(PduRouteULIdx);
                if (pUpIfTriggerTransmitFunc!=NULL_PTR)
                {
                    if (E_OK == pUpIfTriggerTransmitFunc(
                        SoAd_PduRouteCfgGetTxConfPduId(SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx)),&PduInfo))
                    {
                        /* Try to transmit the Pdu */
                        (void)SoAd_TxIfTransmitPduRouteDest(PduRouteDestIdx,&PduInfo,&ErrorId);
                    }
                }
            }
            else
            {
                /* Trigger called from previous PduRouteDest of same PduRoute Idx */
                if (PduInfo.SduDataPtr != NULL_PTR)
                {
                    /* Try to transmit the Pdu */
                    (void)SoAd_TxIfTransmitPduRouteDest(PduRouteDestIdx,&PduInfo,&ErrorId);
                }
            }
        }
        PrevRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
    }
}
/* #! confirmation */
/********************************************************************************************************************
*   @brief This Api is used to handle the tx confirmation
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TxConfirmationHandler(void)
{
    SoAd_PduRouteIdxType PduRouteIdx;
    /* Handle Udp IfTxConfirmations. */
    for (PduRouteIdx = 0U; PduRouteIdx < SoAd_CfgGetNumOfPduRoute();PduRouteIdx++)
    {
        if (SoAd_CtrlGetPduRouteEventUdpTxConf(PduRouteIdx) == TRUE)
        {
            SoAd_TxIfUdpTxConfirmation(PduRouteIdx);
            SoAd_CtrlSetPduRouteEventUdpTxConf(PduRouteIdx,FALSE);
        }
    }
}
/********************************************************************************************************************
*   @brief This Api is used to process pdu route idx confirmation and invoke upper confirmation call
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxIfCallTxConfirmation(SoAd_PduRouteIdxType PduRouteIdx)
{
    SoAd_ULIdxType PduRouteULIdx;
    SoAd_UpIfTxConfirmationFuncType UpIfTxConfirmationFunc;
    
	PduRouteULIdx = SoAd_PduRouteCfgGetPduRouteULIdx(PduRouteIdx);
    UpIfTxConfirmationFunc = SoAd_UpperLayerCfgGetUpIfTxConfirmationFunc(PduRouteULIdx);
    if (SoAd_PduRouteCfgIsIfTxConfEnabled(PduRouteIdx) == TRUE)
    {
        /* Call TxConfirmation of upper layer. */
        if (UpIfTxConfirmationFunc != NULL_PTR)
        {
            UpIfTxConfirmationFunc(SoAd_PduRouteCfgGetTxConfPduId(PduRouteIdx),E_OK);
        }
    }
}
/********************************************************************************************************************
*   @brief This Api is used to handle the immediate If tx confirmation
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxUdpImmediateIfTxConfirmation(SoAd_SoConIdType SoConIdx)
{
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_SocketUdpIdxType SocketUdpIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;

    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    SocketUdpIdx = SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx);
    if(SoAd_SocketUdpCfgGetImmTxConfirmation(SocketUdpIdx) == TRUE)
    {
        PduRouteDestIdx = SoAd_SoConCfgGetPduRouteDestStartIdx(SoConIdx);
        PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
        /* Reconnect socket connection. */
        SoAd_SoConRequestReconnect(SoConIdx);
        /* process Tx confirmation */
        SoAd_TxIfCallTxConfirmation(PduRouteIdx);
    }
}
/********************************************************************************************************************
*   @brief This Api is used to handle the Udp Tx if confirmation
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxIfUdpTxConfirmation(SoAd_PduRouteIdxType PduRouteIdx)
{
    SoAd_SoConIdType SoConIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    
    for(PduRouteDestIdx=SoAd_PduRouteCfgGetPduRouteDestStartIdx(PduRouteIdx);
        PduRouteDestIdx<=SoAd_PduRouteCfgGetPduRouteDestEndIdx(PduRouteIdx);PduRouteDestIdx++)
    {
        SoConIdx = SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx);
        SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
        /* Check if confirmation to be processed in the main function */
        if (SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE)
        {
            SoAd_PduRouteCtrlSetPendingTxConfInMain(PduRouteIdx,FALSE);
            /* process if no pending confirmation */
            if (SoAd_PduRouteCtrlGetNumOfPendingTxConf(PduRouteIdx) == 0U)
            {
                /* Reconnect socket connection. */
                SoAd_SoConRequestReconnect(SoConIdx);
                /* process Tx confirmation */
                SoAd_TxIfCallTxConfirmation(PduRouteIdx);
                break;
            }
        }
    }
}
/********************************************************************************************************************
*   @brief This Api is used to handle the tx if tcp pdu confirmation
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxIfTcpTxConfirmation
(
    SoAd_SoConIdType SoConIdx,
    SoAd_PduRouteIdxType PduRouteIdx,
    boolean ByResetSoCon
)
{
    boolean NotifyUL = FALSE;
    SoAd_ULIdxType PduRouteULIdx;
    SoAd_UpIfTxConfirmationFuncType UpIfTxConfirmationFunc;
    
    PduRouteULIdx = SoAd_PduRouteCfgGetPduRouteULIdx(PduRouteIdx);
    UpIfTxConfirmationFunc = SoAd_UpperLayerCfgGetUpIfTxConfirmationFunc(PduRouteULIdx);
    /* if confirmation is enabled and then the confirmation is pending ,then notify to upper layer */
    if (SoAd_PduRouteCfgIsIfTxConfEnabled(PduRouteIdx) == TRUE)
    {
        SoAd_EnterCriticalSection();
        if (SoAd_PduRouteCtrlGetNumOfPendingTxConf(PduRouteIdx) >0U)
        {
            SoAd_PduRouteCtrlDecNumOfPendingTxConf(PduRouteIdx);
            if ((SoAd_PduRouteCtrlGetNumOfPendingTxConf(PduRouteIdx) == 0U) && 
                (SoAd_PduRouteCtrlGetPendingTxConfInMain(PduRouteIdx) == FALSE))
            {
                /* if confirmation is not requested by socket connection reset on close then try to reconnect */
                if (ByResetSoCon == FALSE)
                {
                    SoAd_SoConRequestReconnect(SoConIdx);
                }
                NotifyUL = TRUE;
            }
        }
        SoAd_ExitCriticalSection();
        if (NotifyUL == TRUE)
        {
            UpIfTxConfirmationFunc = SoAd_UpperLayerCfgGetUpIfTxConfirmationFunc(PduRouteULIdx);
            if (UpIfTxConfirmationFunc != NULL_PTR)
            {
                UpIfTxConfirmationFunc(SoAd_PduRouteCfgGetTxConfPduId(PduRouteIdx),E_OK);
            }
        }
    }
}
/* #! transmit */
/********************************************************************************************************************
*   @brief This Api is used to handle the transmission in main function call
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TxTransmissionHandler(void)
{
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx;
    SoAd_NPduUdpTxTimerIdxType NPduUdpTxTimerIdx;
    /* Process TP transmission. */
    SoAd_TxTpTransmissionHandler();
    /* Handle nPdu transmission. */
    for (NPduUdpTxIdx = 0u; NPduUdpTxIdx < SoAd_CfgGetNumOfNPduUdpTx(); NPduUdpTxIdx++ )
    {
        NPduUdpTxTimerIdx = SoAd_NPduUdpTxCfgGetTxUdpNPduTimerIdx(NPduUdpTxIdx);
        if (NPduUdpTxTimerIdx <= SoAd_CfgGetNumOfNPduUdpTxTimer())
        {
            if (SoAd_CtrlGetTxUdpNPduTimer(NPduUdpTxTimerIdx) >0U)
            {
                SoAd_CtrlDecTxUdpNPduTimer(NPduUdpTxTimerIdx);
                if (SoAd_CtrlGetTxUdpNPduTimer(NPduUdpTxTimerIdx) == 0u)
                {
                    SoAd_TxNPduUdpTransmit(NPduUdpTxIdx);
                }
            }
        }
    }  
}
/* #! if transmit */
/********************************************************************************************************************
*   @brief This Api is used to check valid states for If Pdu transmission
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfCheckTxState(SoAd_PduRouteIdxType PduRouteIdx)
{
    Std_ReturnType RetVal = E_OK;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    SoAd_SoConIdType SoConIdx;
    
    PduRouteDestIdx = SoAd_PduRouteCfgGetPduRouteDestStartIdx(PduRouteIdx);
    SoConIdx = SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx);
    /* if a TxConfirmation is pending on the requested PDU , then return E_NOT_OK */
    if ((SoAd_SoConCfgIsUdpNPduSupported(SoConIdx) == TRUE) || 
        (SoAd_PduRouteCfgIsIfTriggerTxEnabled(PduRouteIdx) == FALSE))
    {
        if ((SoAd_PduRouteCtrlGetNumOfPendingTxConf(PduRouteIdx) != 0u) ||
            (SoAd_PduRouteCtrlGetPendingTxConfInMain(PduRouteIdx) == TRUE))
        {
            RetVal = E_NOT_OK;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to transmit the If Pdu
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfTransmitPdu
(
    SoAd_PduRouteIdxType PduRouteIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_DATA) PduInfoPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) ErrorIdPtr
)
{
    PduInfoType PduInfo;
    Std_ReturnType RetVal = E_OK;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    SoAd_PduRouteDestIdxType PduRouteDestRoutingGrpDisabled=0u;
    /* If Meta data is enabled, then send Pdu to the PduRouteDestIdx provided in meta data */
    if (SoAd_PduRouteCfgIsMetaDataEnabled(PduRouteIdx) == TRUE )
    {
        RetVal = E_NOT_OK;
        /* Get PduRouteDestIdx from the Meta data */
        if (SoAd_TxIfGetPduRouteDestIdxByMetaData(PduRouteIdx,PduInfoPtr, &PduRouteDestIdx) == E_OK)
        {
            /* Check if routing group enabled for this PduRouteDestIdx */
            if (SoAd_CheckRoutingGroupPduDestEnabled(PduRouteDestIdx) == TRUE)
            {
                /* Update PduInfo without the meta data */
                PduInfo.SduDataPtr = PduInfoPtr->SduDataPtr;
                PduInfo.SduLength = (PduLengthType)(PduInfoPtr->SduLength - SOAD_TX_META_DATA_LEN);
                /* Request transmit of Pdu in the PduRouteDest */
                RetVal = SoAd_TxIfTransmitPduRouteDest(PduRouteDestIdx, &PduInfo, ErrorIdPtr);
            }
        }
    }
    else
    {
        /* Try to transmit in all PduRouteDest */
        for(PduRouteDestIdx = SoAd_PduRouteCfgGetPduRouteDestStartIdx(PduRouteIdx); 
            PduRouteDestIdx <= SoAd_PduRouteCfgGetPduRouteDestEndIdx(PduRouteIdx);PduRouteDestIdx++)
        {
            /* Check if routing group enabled for this PduRouteDestIdx */
            if (SoAd_CheckRoutingGroupPduDestEnabled(PduRouteDestIdx) == TRUE)
            {
                RetVal |= SoAd_TxIfTransmitPduRouteDest(PduRouteDestIdx, PduInfoPtr, ErrorIdPtr);
            }
            else
            {
                PduRouteDestRoutingGrpDisabled++;
            }
        }
        /* If all PduRouteDest's routing group disabled then return E_NOT_OK */
        if (PduRouteDestRoutingGrpDisabled == SoAd_PduRouteCfgGetNumOfPduRouteDest(PduRouteIdx))
        {
            RetVal = E_NOT_OK;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to handle the transmission of If Pdu route dest
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfTransmitPduRouteDest
(
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) ErrorIdPtr
)
{
    SoAd_SoConIdType SoConIdx;
    SoAd_SocketIdxType SocketIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    
    SoConIdx = SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx);
    SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConIdx);
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);   
    /* Process transmit if the SoCon and Socket states are valid */
    if ((SoAd_SocketCtrlGetSocketState(SocketIdx) == SOAD_SOCK_STATE_ESTABLISHED) &&
        (SoAd_SoConCtrlGetSoConMode(SoConIdx) == SOAD_SOCON_ONLINE) &&
        (SoAd_SoConCtrlGetCloseReqType(SoConIdx) == SOAD_CLOSE_REQ_NONE))
    {
        if (SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE)
        {
            RetVal = SoAd_TxIfUdpTransmit(PduRouteDestIdx, PduInfoPtr, ErrorIdPtr);   
        }
        else
        {
            RetVal = SoAd_TxIfTcpTransmit(PduRouteDestIdx, PduInfoPtr);
        }
    }
    
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to request the socket transmission for If pdu
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfTcpCallTransmit(SoAd_PduRouteDestIdxType PduRouteDestIdx)
{
    SoAd_SoConIdType SoConIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx ;
    
    PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
    SoConIdx = SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx);
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx);
    /* Check if the queue is full */
    if (SoAd_TxTcpQueueIsFull(SoConIdx) != TRUE)
    {
        /* Try to transmit the data in the socket */
        if (E_OK == SoAd_SocketTcpTransmit(SoAd_SoConCfgGetSocketIdx(SoConIdx),
                                      SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx),TRUE))
        {
            /* Try to add the PduRouteIdx , TxBytesLen to the TxTcpQueue */
            RetVal = SoAd_TxTcpQueueAddElement(SoConIdx,PduRouteIdx,SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx));
            if((E_OK == RetVal) && (SoAd_PduRouteCfgIsIfTxConfEnabled(PduRouteIdx) == TRUE))
            {
                /* If added in the queue and the confirmation enabled, then increment the pending conf count */
                SoAd_PduRouteCtrlIncNumOfPendingTxConf(PduRouteIdx);
            }
        }
    }
    /* Update Tx completion on socket connection. */
    SoAd_SoConTxPduCtrlSetPduRouteDestIdx(TxPduCtrlIdx,SoAd_CfgGetNumOfPduRouteDest());
    SoAd_SoConTxPduCtrlSetpBuffer(TxPduCtrlIdx,NULL_PTR);
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to get the Pdu route dest idx by the meta data
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfGetPduRouteDestIdxByMetaData
(
    SoAd_PduRouteIdxType PduRouteIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_DATA) PduInfoPtr,
    P2VAR(SoAd_PduRouteDestIdxType, AUTOMATIC, SOAD_APPL_DATA) PduRouteDestIdxPtr
)
{
    SoAd_SoConIdType SoConIdx=0u;
    PduLengthType MetaDataStartIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;

    MetaDataStartIdx = PduInfoPtr->SduLength - SOAD_TX_META_DATA_LEN;
    SoConIdx =  PduInfoPtr->SduDataPtr[MetaDataStartIdx];
    SoConIdx |= (SoAd_SoConIdType)(PduInfoPtr->SduDataPtr[MetaDataStartIdx+1u] << 8u);
    /* If extracted SoConId is valid and check with PduRouteDest's SoConId . if matches update the PduRouteDestIdx */
    if (SoConIdx < SoAd_CfgGetNumOfSoCon())
    {
        for(PduRouteDestIdx = SoAd_PduRouteCfgGetPduRouteDestStartIdx(PduRouteIdx);
            PduRouteDestIdx <= SoAd_PduRouteCfgGetPduRouteDestEndIdx(PduRouteIdx);PduRouteDestIdx++)
        {
            if (SoConIdx == SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx))
            {
                *PduRouteDestIdxPtr = PduRouteDestIdx;
                RetVal = E_OK;
                break;
            }
        }
    }
    return RetVal;
}
/* #! udp if transmit */
/********************************************************************************************************************
*   @brief This Api is used to transmit the udp if normal Pdu
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfUdpTransmitPdu
(
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
)
{
    SoAd_SoConIdType SoConIdx;
    SoAd_SocketIdxType SocketIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    
    PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
    SoConIdx = SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx);
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx) ;
    SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConIdx);
    
    SoAd_EnterCriticalSection();
    /* Check if no Tx in progess on the socket */
    if (SoAd_SocketCtrlGetActiveTxSoCon(SocketIdx) == SoAd_CfgGetNumOfSoCon())
    {
        SoAd_SocketCtrlSetActiveTxSoCon(SocketIdx,SoConIdx);
        RetVal = E_OK;
    }
    SoAd_ExitCriticalSection();
    
    if (RetVal == E_OK)
    {
        /* Update the  SoCon TxPdu status */
        SoAd_SoConTxPduCtrlSetPduRouteDestIdx(TxPduCtrlIdx,PduRouteDestIdx);
        SoAd_SoConTxPduCtrlSetpBuffer(TxPduCtrlIdx,PduInfoPtr->SduDataPtr);
        /* Update the tx length based on Pdu Header */
        if (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
        {
            SoAd_SoConTxPduCtrlSetTxBytesLen(TxPduCtrlIdx,(PduInfoPtr->SduLength + SOAD_PDU_HEADER_SIZE));
            SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,(PduInfoPtr->SduLength + SOAD_PDU_HEADER_SIZE));
        }
        else
        {
            SoAd_SoConTxPduCtrlSetTxBytesLen(TxPduCtrlIdx,PduInfoPtr->SduLength);
            SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,PduInfoPtr->SduLength);
        }
        /* Try to tranmit on the socket */
        RetVal = SoAd_SocketUdpTransmit(SocketIdx,&SoAd_SoConCtrlGetRemoteAddr(SoConIdx),
                                        SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx));
        if (RetVal == E_OK)
        {
            /* If immediate confirmation is not enabled , set the flag and process in mainfunction
            Immediate tx check is for Tcp connection */
            //if (SoAd_SocketUdpCfgGetImmTxConfirmation(SocketUdpIdx) == FALSE) 
            {
                SoAd_PduRouteCtrlSetPendingTxConfInMain(PduRouteIdx,TRUE); 
                SoAd_CtrlSetPduRouteEventUdpTxConf(PduRouteIdx,TRUE);
            }
        }
        /* Reset the  SoCon TxPdu status */
        SoAd_SoConTxPduCtrlSetPduRouteDestIdx(TxPduCtrlIdx,SoAd_CfgGetNumOfPduRouteDest());
        SoAd_SoConTxPduCtrlSetpBuffer(TxPduCtrlIdx,NULL_PTR);        
        /* Remove transmission on socket. */
        SoAd_SocketCtrlSetActiveTxSoCon(SocketIdx,SoAd_CfgGetNumOfSoCon());
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to transmit the udp if pdu
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfUdpTransmit
(
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) ErrorIdPtr
)
{
    SoAd_SoConIdType SoConIdx;
    Std_ReturnType RetVal;
    
    SoConIdx = SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx);
    /* Update Alive Timeout */
    SoAd_UpdateUdpAliveTimeout(SoConIdx);
    if (SoAd_SoConCfgIsUdpNPduSupported(SoConIdx) == TRUE) 
    {
        /* process Npdu Udp transmission */
        RetVal = SoAd_TxIfUdpTransmitNPdu(PduRouteDestIdx, PduInfoPtr, ErrorIdPtr);
    }
    else
    {
        /* process Udp transmission */
        RetVal = SoAd_TxIfUdpTransmitPdu(PduRouteDestIdx, PduInfoPtr);
    }
    return RetVal;
}
/* #! Tcp if transmit */
/********************************************************************************************************************
*   @brief This Api is used to transmit the If tcp pdu.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfTcpTransmit
(
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
)
{
    SoAd_SoConIdType SoConIdx;
    SoAd_SocketIdxType SocketIdx;
    Std_ReturnType  RetVal = E_NOT_OK;
    
    SoConIdx = SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx);
    SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConIdx);
    
    SoAd_EnterCriticalSection();
    if (SoAd_SocketCtrlGetActiveTxSoCon(SocketIdx) == SoAd_CfgGetNumOfSoCon())
    {
        SoAd_SocketCtrlSetActiveTxSoCon(SocketIdx,SoConIdx);
        RetVal = E_OK;
    }
    SoAd_ExitCriticalSection();
    
    if (RetVal == E_OK)
    {
        /* Update data for tranmission */
        if (SoAd_TxIfTcpPrepareTransmit(PduRouteDestIdx, PduInfoPtr) == E_OK) 
        {
            /* Request IF-PDU Tx on TCP socket connection. */
            RetVal = SoAd_TxIfTcpCallTransmit(PduRouteDestIdx);
        }
        else
        {
            RetVal = E_NOT_OK;
        }
    }
    SoAd_SocketCtrlSetActiveTxSoCon(SocketIdx,SoAd_CfgGetNumOfSoCon());    
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to prepare the message for If Pdu Tx 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfTcpPrepareTransmit
(
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
)
{
    PduInfoType PduInfo;
    SoAd_SoConIdType SoConIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_ULIdxType PduRouteULIdx;
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_SoConGrpIdxType  SoConGrpIdx;
    PduLengthType MinLength,DataLength;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx ;
    SoAd_UpIfTriggerTransmitFuncType pUpIfTriggerTransmitFunc;
    
    PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
    SoConIdx = SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx);
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx);
    PduRouteULIdx = SoAd_PduRouteCfgGetPduRouteULIdx(PduRouteIdx);
    /* If trigger transmit is enabled , copy data from upper layer */
    if (SoAd_PduRouteCfgIsIfTriggerTxEnabled(PduRouteIdx) == TRUE)
    {
        /* Update PduInfo with configured trigger transmit buffer for this SoConId */
        PduInfo.SduDataPtr = SoAd_CtrlGetPtrToTriggerBuffer(SoAd_SoConCfgGetTriggerBufferStartIdx(SoConIdx));
        PduInfo.SduLength = (PduLengthType)SoAd_SoConCfgGetTriggerBufferSize(SoConIdx);
        /* Get upper layer trigger transmit function */
        pUpIfTriggerTransmitFunc = SoAd_UpperLayerCfgGetUpIfTriggerTransmitFunc(PduRouteULIdx);
        if (pUpIfTriggerTransmitFunc!=NULL_PTR)
        {
            if (E_OK == pUpIfTriggerTransmitFunc(SoAd_PduRouteCfgGetTxConfPduId(PduRouteIdx),&PduInfo))
            {
                /* Update MinLength and the dataLength based on Header support */
                if (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
                {
                    MinLength = 0u;
                    DataLength = SOAD_PDU_HEADER_SIZE;
                }
                else
                {
                    MinLength = 1u;
                    DataLength = 0u;
                }
                /* Check for valid PduInfo update by upper layer */
                if ((PduInfo.SduDataPtr != NULL_PTR) && 
                    (PduInfo.SduLength >= MinLength) &&
                    (PduInfo.SduLength <= (PduLengthType)SoAd_SoConCfgGetTriggerBufferSize(SoConIdx)))
                {
                    /* Update the SoCon Tx status */
                    DataLength += PduInfo.SduLength;
                    SoAd_SoConTxPduCtrlSetPduRouteDestIdx(TxPduCtrlIdx,PduRouteDestIdx);
                    SoAd_SoConTxPduCtrlSetTxBytesLen(TxPduCtrlIdx,DataLength); 
                    SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,DataLength);
                    SoAd_SoConTxPduCtrlSetpBuffer(TxPduCtrlIdx,
                                SoAd_CtrlGetPtrToTriggerBuffer(SoAd_SoConCfgGetTriggerBufferStartIdx(SoConIdx)));
                    RetVal = E_OK;
                }
            }
        }
    }
    else
    {
        /* Update the SoCon Tx status */
        SoAd_SoConTxPduCtrlSetPduRouteDestIdx(TxPduCtrlIdx,PduRouteDestIdx);
        SoAd_SoConTxPduCtrlSetpBuffer(TxPduCtrlIdx,PduInfoPtr->SduDataPtr);
        /* Update Data length based on Header support */
        if (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
        {
            SoAd_SoConTxPduCtrlSetTxBytesLen(TxPduCtrlIdx,(PduInfoPtr->SduLength + SOAD_PDU_HEADER_SIZE));
            SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,(PduInfoPtr->SduLength + SOAD_PDU_HEADER_SIZE));
        }
        else
        {
            SoAd_SoConTxPduCtrlSetTxBytesLen(TxPduCtrlIdx,PduInfoPtr->SduLength);
            SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,PduInfoPtr->SduLength);
        }
        RetVal = E_OK;
    }
    return RetVal;
}
/* #! Tcp tx queue */
/********************************************************************************************************************
*   @brief This Api is used to initialize the Tx Tcp Queue of the Socket connection idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTcpQueueInit(SoAd_SoConIdType SoConIdx)
{
    SoAd_TcpTxQueueIdxType TcpTxQueueIdx;
    SoAd_TcpTxQueueSizeType TcpTxQueueDataIdx;
    
    if (SoAd_SoConCfgIsTcpTxQueueEnabled(SoConIdx) == TRUE)
    {
        TcpTxQueueIdx = SoAd_SoConCfgGetTcpTxQueueIdx(SoConIdx);
        /* Initialize the queue data elements */
        for (TcpTxQueueDataIdx = SoAd_TcpTxQueueCfgGetDataStartIdx(TcpTxQueueIdx);
             TcpTxQueueDataIdx <= SoAd_TcpTxQueueCfgGetDataEndIdx(TcpTxQueueIdx);TcpTxQueueDataIdx++)
        {
            SoAd_TcpTxQueueDataCtrlSetPduRouteIdx(TcpTxQueueDataIdx,SoAd_CfgGetNumOfPduRoute());
            SoAd_TcpTxQueueDataCtrlSetLength(TcpTxQueueDataIdx,0U);
        }
        /* Initialize the Queue ctrl status */
        SoAd_TcpTxQueueCtrlSetReadIdx(TcpTxQueueIdx,SoAd_TcpTxQueueCfgGetDataStartIdx(TcpTxQueueIdx));
        SoAd_TcpTxQueueCtrlSetWriteIdx(TcpTxQueueIdx,SoAd_TcpTxQueueCfgGetDataStartIdx(TcpTxQueueIdx));
        SoAd_TcpTxQueueCtrlSetDataCounter(TcpTxQueueIdx,0U);
        SoAd_TcpTxQueueCtrlSetTotalLength(TcpTxQueueIdx,0U);
        
    }
}
/********************************************************************************************************************
*   @brief This Api is used to check if the Tx Tcp queue of the socket connection idx is FULL.
********************************************************************************************************************/
boolean SoAd_TxTcpQueueIsFull(SoAd_SoConIdType SoConIdx)
{
    boolean IsQueueFull = FALSE;
    SoAd_TcpTxQueueIdxType TcpTxQueueIdx;
    
    SoAd_EnterCriticalSection();
    /*! Check if the queue is full */
    if (SoAd_SoConCfgIsTcpTxQueueEnabled(SoConIdx) == TRUE)
    {
        TcpTxQueueIdx = SoAd_SoConCfgGetTcpTxQueueIdx(SoConIdx);
        if(SoAd_TcpTxQueueCtrlGetDataCounter(TcpTxQueueIdx) == SoAd_TcpTxQueueCfgGetQueueSize(TcpTxQueueIdx))
        {
            IsQueueFull = TRUE;
        }
    }
    SoAd_ExitCriticalSection();
    return IsQueueFull;
}
/********************************************************************************************************************
*   @brief This Api is used to add element to the Tx Tcp queue.
********************************************************************************************************************/
Std_ReturnType SoAd_TxTcpQueueAddElement
(
    SoAd_SoConIdType SoConIdx,
    SoAd_PduRouteIdxType PduRouteIdx,
    PduLengthType PduLength
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_TcpTxQueueSizeType WriteIdx;
    SoAd_TcpTxQueueIdxType TcpTxQueueIdx;
    
    SoAd_EnterCriticalSection();
    if (SoAd_SoConCfgIsTcpTxQueueEnabled(SoConIdx) == TRUE)
    {
        TcpTxQueueIdx = SoAd_SoConCfgGetTcpTxQueueIdx(SoConIdx);
        if (SoAd_TcpTxQueueCtrlGetDataCounter(TcpTxQueueIdx) != SoAd_TcpTxQueueCfgGetQueueSize(TcpTxQueueIdx))
        {
            WriteIdx = SoAd_TcpTxQueueCtrlGetWriteIdx(TcpTxQueueIdx);
            if (WriteIdx >= SoAd_TcpTxQueueCfgGetQueueSize(TcpTxQueueIdx))
            {
                WriteIdx = SoAd_TcpTxQueueCfgGetDataStartIdx(TcpTxQueueIdx);
            }
            /* Update Queue Data */
            SoAd_TcpTxQueueDataCtrlSetPduRouteIdx(WriteIdx,PduRouteIdx);
            SoAd_TcpTxQueueDataCtrlSetLength(WriteIdx,PduLength);
            WriteIdx++;
            /* Update Queue Ctrl data */
            SoAd_TcpTxQueueCtrlSetTotalLength(TcpTxQueueIdx,
                                             (SoAd_TcpTxQueueCtrlGetTotalLength(TcpTxQueueIdx)+PduLength));
            SoAd_TcpTxQueueCtrlSetWriteIdx(TcpTxQueueIdx,WriteIdx);
            SoAd_TcpTxQueueCtrlIncDataCounter(TcpTxQueueIdx);
            RetVal = E_OK;
        }
    }
    SoAd_ExitCriticalSection();
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to remove the element from the tx tcp queue with the requested pdu route idx
********************************************************************************************************************/
Std_ReturnType SoAd_TxTcpQueueRemoveElement
(
    SoAd_SoConIdType SoConIdx,
    SoAd_PduRouteIdxType PduRouteIdx
)
{
    PduLengthType LocalPduLength;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_TcpTxQueueSizeType ReadIdx;
    SoAd_TcpTxQueueIdxType TcpTxQueueIdx;
    
    SoAd_EnterCriticalSection();
    if (SoAd_SoConCfgIsTcpTxQueueEnabled(SoConIdx) == TRUE)
    {
        TcpTxQueueIdx = SoAd_SoConCfgGetTcpTxQueueIdx(SoConIdx);
        if (SoAd_TcpTxQueueCtrlGetDataCounter(TcpTxQueueIdx) > 0)
        {
            ReadIdx = SoAd_TcpTxQueueCtrlGetReadIdx(TcpTxQueueIdx); 
            /* Remove if the last element matches with the PduRouteIdx */
            if (PduRouteIdx == SoAd_TcpTxQueueDataCtrlGetPduRouteIdx(ReadIdx))
            {
                LocalPduLength = SoAd_TcpTxQueueDataCtrlGetLength(ReadIdx); 
                /* Update Queue Data */
                SoAd_TcpTxQueueDataCtrlSetPduRouteIdx(ReadIdx,SoAd_CfgGetNumOfPduRoute());
                SoAd_TcpTxQueueDataCtrlSetLength(ReadIdx,0u);
                ReadIdx++;
                if (ReadIdx >= SoAd_TcpTxQueueCfgGetQueueSize(TcpTxQueueIdx))
                {
                    ReadIdx = SoAd_TcpTxQueueCfgGetDataStartIdx(TcpTxQueueIdx);
                }
                /* Update Queue Ctrl data */
                if (SoAd_TcpTxQueueCtrlGetTotalLength(TcpTxQueueIdx) >= LocalPduLength)
                {
                    SoAd_TcpTxQueueCtrlSetTotalLength(TcpTxQueueIdx,
                                                    (SoAd_TcpTxQueueCtrlGetTotalLength(TcpTxQueueIdx)-LocalPduLength));
                }
                else
                {
                    SoAd_TcpTxQueueCtrlSetTotalLength(TcpTxQueueIdx,0u);
                }
                SoAd_TcpTxQueueCtrlSetReadIdx(TcpTxQueueIdx,ReadIdx);
                SoAd_TcpTxQueueCtrlDecDataCounter(TcpTxQueueIdx);
                RetVal = E_OK;
            }
        }
    }
    SoAd_ExitCriticalSection();
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to handle the tx tcp queue confirmation
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTcpQueueTxConfirmation(SoAd_SoConIdType SoConIdx,PduLengthType PduLength)
{
    PduLengthType LocalLength;
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_TcpTxQueueSizeType   ReadIdx;
    SoAd_TcpTxQueueIdxType TcpTxQueueIdx;
    
    LocalLength = PduLength;
    TcpTxQueueIdx = SoAd_SoConCfgGetTcpTxQueueIdx(SoConIdx);

    SoAd_EnterCriticalSection();
    while (LocalLength > 0u)
    {
        if ((SoAd_TcpTxQueueCtrlGetTotalLength(TcpTxQueueIdx) >0U) && 
            (SoAd_TcpTxQueueCtrlGetDataCounter(TcpTxQueueIdx) >0u))
        {
            /* Update Queue Data */
            ReadIdx = SoAd_TcpTxQueueCtrlGetReadIdx(TcpTxQueueIdx);
            PduRouteIdx = SoAd_TcpTxQueueDataCtrlGetPduRouteIdx(ReadIdx);
            if (SoAd_TcpTxQueueDataCtrlGetLength(ReadIdx) <= LocalLength)
            {
                LocalLength-=SoAd_TcpTxQueueDataCtrlGetLength(ReadIdx);
                if (SoAd_TcpTxQueueCtrlGetTotalLength(TcpTxQueueIdx) >= SoAd_TcpTxQueueDataCtrlGetLength(ReadIdx))
                {
                    SoAd_TcpTxQueueCtrlSetTotalLength(TcpTxQueueIdx,
                        (SoAd_TcpTxQueueCtrlGetTotalLength(TcpTxQueueIdx)-SoAd_TcpTxQueueDataCtrlGetLength(ReadIdx)));
                }
                else
                {
                    SoAd_TcpTxQueueCtrlSetTotalLength(TcpTxQueueIdx,0U);
                }
                SoAd_TcpTxQueueDataCtrlSetLength(ReadIdx,0U);
                SoAd_TcpTxQueueDataCtrlSetPduRouteIdx(ReadIdx,SoAd_CfgGetNumOfPduRoute());
                /* Update ReadIdx */
                ReadIdx++;
                if ( ReadIdx >= SoAd_TcpTxQueueCfgGetQueueSize(TcpTxQueueIdx))
                {
                    ReadIdx = SoAd_TcpTxQueueCfgGetDataStartIdx(TcpTxQueueIdx);
                }
                SoAd_TcpTxQueueCtrlSetReadIdx(TcpTxQueueIdx,ReadIdx);
                SoAd_TcpTxQueueCtrlDecDataCounter(TcpTxQueueIdx);                
                SoAd_ExitCriticalSection();
                /* Confirm PDU transmission. */
                SoAd_TxTcpQueueCallTxConfirmation(SoConIdx, PduRouteIdx,FALSE);
                SoAd_EnterCriticalSection();
            }
            else
            {
                SoAd_TcpTxQueueCtrlGetTotalLength(TcpTxQueueIdx)-=LocalLength;
                SoAd_TcpTxQueueDataCtrlGetLength(ReadIdx)-=LocalLength;
                LocalLength = 0U;
            }
        }
        else
        {
            /* set LocalLength 0, to exit as not data in TcpTxQueue */
            LocalLength = 0U;
        }
    }
    SoAd_ExitCriticalSection();
}
/********************************************************************************************************************
*   @brief This Api is used to process confirmation notification of the tx tcp queue confirmation of Pdu route idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTcpQueueCallTxConfirmation
(
  SoAd_SoConIdType SoConIdx,
  SoAd_PduRouteIdxType PduRouteIdx,
  boolean ByResetSoCon
)
{
    boolean NotifyUL = FALSE;
    SoAd_SocketIdxType SocketIdx;
    SoAd_ULIdxType PduRouteULIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_UpIfTxConfirmationFuncType UpIfTxConfirmationFunc;
    SoAd_UpTpTxConfirmationFuncType pUpTpTxConfirmationFunc;
        
    PduRouteULIdx = SoAd_PduRouteCfgGetPduRouteULIdx(PduRouteIdx);
    if (SoAd_PduRouteCfgGetPduRouteULType(PduRouteIdx) == SOAD_UPPER_LAYER_TYPE_IF)
    {
        /* if confirmation is enabled and then the confirmation is pending ,then notify to upper layer */
        if (SoAd_PduRouteCfgIsIfTxConfEnabled(PduRouteIdx) == TRUE)
        {
            SoAd_EnterCriticalSection();
            if (SoAd_PduRouteCtrlGetNumOfPendingTxConf(PduRouteIdx) >0U)
            {
                SoAd_PduRouteCtrlDecNumOfPendingTxConf(PduRouteIdx);
                if ((SoAd_PduRouteCtrlGetNumOfPendingTxConf(PduRouteIdx) == 0U) && 
                    (SoAd_PduRouteCtrlGetPendingTxConfInMain(PduRouteIdx) == FALSE))
                {
                    /* if confirmation is not requested by socket connection reset on close then try to reconnect */
                    if (ByResetSoCon == FALSE)
                    {
                        SoAd_SoConRequestReconnect(SoConIdx);
                    }
                    NotifyUL = TRUE;
                }
            }
            SoAd_ExitCriticalSection();
            if (NotifyUL == TRUE)
            {
                UpIfTxConfirmationFunc = SoAd_UpperLayerCfgGetUpIfTxConfirmationFunc(PduRouteULIdx);
                if (UpIfTxConfirmationFunc != NULL_PTR)
                {
                    UpIfTxConfirmationFunc(SoAd_PduRouteCfgGetTxConfPduId(PduRouteIdx),E_OK);
                }
            }
        }
    }
    else
    {
        TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx) ;
        SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
        SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConIdx);
        /* If Immediate tcp tx confirmation is not required */
        if (SoAd_SoConGrpCfgIsTcpImmConfSupported(SoConGrpIdx) == FALSE)
        {
            /* If cancel not requested for this tx */
            if (SoAd_SoConTxPduCtrlGetCancelRequest(TxPduCtrlIdx) != TRUE)
            {
                SoAd_SoConTxPduCtrlSetPduRouteDestIdx(TxPduCtrlIdx,SoAd_CfgGetNumOfPduRouteDest());
                SoAd_SoConTxPduCtrlSetTxBytesLen(TxPduCtrlIdx,0U);
                SoAd_SocketCtrlSetActiveTxSoCon(SocketIdx,SoAd_CfgGetNumOfSoCon());
                /* Reconnect socket connection. */
                SoAd_SoConRequestReconnect(SoConIdx);
                /* Notify upper layer */
                pUpTpTxConfirmationFunc = SoAd_UpperLayerCfgGetUpTpTxConfirmationFunc(PduRouteULIdx);
                if (pUpTpTxConfirmationFunc != NULL_PTR)
                {
                    pUpTpTxConfirmationFunc(SoAd_PduRouteCfgGetTxConfPduId(PduRouteIdx),E_OK);
                }
                /* Remove element from the TxTcp queue*/
                SoAd_TxTcpQueueRemoveElement(SoConIdx,PduRouteIdx);
            }
        }
    }
}
/********************************************************************************************************************
*   @brief This Api is used to clear the tcp tx queue for the SoCon Idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTcpQueueClear(SoAd_SoConIdType SoConIdx)
{
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_TcpTxQueueIdxType TcpTxQueueIdx;
    SoAd_TcpTxQueueSizeType TcpTxQueueDataIdx;
    
    /* check if queue is supported */
    if (SoAd_SoConCfgIsTcpTxQueueEnabled(SoConIdx) == TRUE)
    {
        TcpTxQueueIdx = SoAd_SoConCfgGetTcpTxQueueIdx(SoConIdx);
        /* Initialize all queue elements */
        for (TcpTxQueueDataIdx = SoAd_TcpTxQueueCfgGetDataStartIdx(TcpTxQueueIdx);
            TcpTxQueueDataIdx <= SoAd_TcpTxQueueCfgGetDataEndIdx(TcpTxQueueIdx);TcpTxQueueDataIdx++)
        {
            PduRouteIdx = SoAd_TcpTxQueueDataCtrlGetPduRouteIdx(TcpTxQueueDataIdx);
            if ((PduRouteIdx != SoAd_CfgGetNumOfPduRoute()) &&
                (SoAd_PduRouteCfgGetPduRouteULType(PduRouteIdx) == SOAD_UPPER_LAYER_TYPE_IF))
            {
                SoAd_TxIfTcpTxConfirmation(SoConIdx, PduRouteIdx, TRUE);
            }
            SoAd_TcpTxQueueDataCtrlSetPduRouteIdx(TcpTxQueueDataIdx,SoAd_CfgGetNumOfPduRoute());
            SoAd_TcpTxQueueDataCtrlSetLength(TcpTxQueueDataIdx,0U);
        }
        /* Rest Queue ctrl */
        SoAd_TcpTxQueueCtrlSetReadIdx(TcpTxQueueIdx,SoAd_TcpTxQueueCfgGetDataStartIdx(TcpTxQueueIdx));
        SoAd_TcpTxQueueCtrlSetWriteIdx(TcpTxQueueIdx,SoAd_TcpTxQueueCfgGetDataStartIdx(TcpTxQueueIdx));
        SoAd_TcpTxQueueCtrlSetDataCounter(TcpTxQueueIdx,0u);
        SoAd_TcpTxQueueCtrlSetTotalLength(TcpTxQueueIdx,0U);
    }
}
/* #! tp tx */
/********************************************************************************************************************
*   @brief This Api is used to check the tx tp protocol paramater and update if valid
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxTpCheckAndSetProtocolParameter
(
    SoAd_PduRouteIdxType PduRouteIdx,
    PduLengthType PduLength
)
{
    SoAd_SoConIdType SoConIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    SoAd_TpTxBufferIdxType TpTxBufferCfgIdx;
    
    PduRouteDestIdx = SoAd_PduRouteCfgGetPduRouteDestStartIdx(PduRouteIdx);
    SoConIdx = SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx);
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    
    if(SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE)
    {
        /* Handle Tcp transmission */
        if(SoAd_TxTcpQueueIsFull(SoConIdx) != TRUE)
        {
            /*! Add Tx element to the Queue */
            if(SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
            {
                RetVal=SoAd_TxTcpQueueAddElement(SoConIdx,PduRouteIdx,PduLength+SOAD_PDU_HEADER_SIZE);
            }
            else
            {
                RetVal=SoAd_TxTcpQueueAddElement(SoConIdx,PduRouteIdx,PduLength);
            }
        }
    }
    else
    {
        TpTxBufferCfgIdx = SoAd_SoConCfgGetTpTxBufferCfgIdx(SoConIdx);
        /* If Buffer available , then return E_OK */
        if(PduLength <= SoAd_TpTxBufferCfgGetBufferSize(TpTxBufferCfgIdx))
        {
            SoAd_UpdateUdpAliveTimeout(SoConIdx);
            RetVal = E_OK;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to handle the tp tranmsisison in main function call
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpTransmissionHandler(void)
{
    SoAd_SoConIdType SoConIdx;
    
    for(SoConIdx=0u;SoConIdx<=SoAd_CfgGetNumOfSoCon();SoConIdx++)
    {
        if (SoAd_SoConEventCtrlGetEventTpTx(SoConIdx) == TRUE)
        {
            SoAd_TxTpTransmitPduRouteDest(SoConIdx);
            SoAd_SoConEventCtrlSetEventTpTx(SoConIdx,FALSE);
        }
    }
}
/********************************************************************************************************************
*   @brief This Api is used to transmit the tp pdu route dest of the SoCon
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpTransmitPduRouteDest(SoAd_SoConIdType SoConIdx)
{
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx) ;
    PduRouteDestIdx = SoAd_SoConTxPduCtrlGetPduRouteDestIdx(TxPduCtrlIdx);
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    
    /* If not transmit is pending */
    if (PduRouteDestIdx != SoAd_CfgGetNumOfPduRouteDest())
    {
        if(SoAd_SoConCtrlGetCloseReqType(SoConIdx) == SOAD_CLOSE_REQ_NONE)
        {
            /* process cancel request for the SoCon */
            if(SoAd_SoConTxPduCtrlGetCancelRequest(TxPduCtrlIdx) == TRUE)
            {
                SoAd_TxTpCancellationHandler(SoConIdx);
            }
            else
            {
                if(SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE)
                {
                    (void)SoAd_TxTpTcpTransmit(SoConIdx);
                }
                else
                {
                    (void)SoAd_TxTpUdpTransmit(SoConIdx);
                }
            }
        }
    }
}
/********************************************************************************************************************
*   @brief This Api is used to handle the cancellation of tcp transmit of the SoCon
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpCancellationHandler(SoAd_SoConIdType SoConIdx)
{
    SoAd_ULIdxType PduRouteULIdx;
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    SoAd_UpTpTxConfirmationFuncType pUpTpTxConfirmationFunc;
    SoAd_TpTxBufferIdxType TpTxBufferCfgIdx;
    
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx) ;
    PduRouteDestIdx = SoAd_SoConTxPduCtrlGetPduRouteDestIdx(TxPduCtrlIdx);
    PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
    PduRouteULIdx = SoAd_PduRouteCfgGetPduRouteULIdx(PduRouteIdx);
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    /* Initialize Tx Tp buffer. */
    TpTxBufferCfgIdx = SoAd_SoConCfgGetTpTxBufferCfgIdx(SoConIdx);
    if ( TpTxBufferCfgIdx != SoAd_CfgGetNumOfTpTxBuffer())
    {
        SoAd_TpTxBufferCtrlSetCurrentBufferIdx(TpTxBufferCfgIdx,SoAd_TpTxBufferCfgGetBufferStartIdx(TpTxBufferCfgIdx));
    }
    /* Release Tx TCP queue element */
    if(SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE)
    {
        SoAd_TxTcpQueueRemoveElement(SoConIdx,PduRouteIdx);        
    }
    /* close socket connection and handle it in main function. */
    SoAd_SoConSetCloseReq(SoConIdx, SOAD_CLOSE_REQ_OFFLINE_RESET); 
    SoAd_SoConEventCtrlSetEventState(SoConIdx,TRUE);
    /* Reset TP session. */
    SoAd_SoConTxPduCtrlSetPduRouteDestIdx(TxPduCtrlIdx,SoAd_CfgGetNumOfPduRouteDest());
    SoAd_SoConTxPduCtrlSetTxBytesLen(TxPduCtrlIdx,0U);
    SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,0U);
    SoAd_SoConTxPduCtrlSetCancelRequest(TxPduCtrlIdx,FALSE);
    /* Notify upper layer */
    pUpTpTxConfirmationFunc = SoAd_UpperLayerCfgGetUpTpTxConfirmationFunc(PduRouteULIdx);
    if (pUpTpTxConfirmationFunc != NULL_PTR)
    {
        pUpTpTxConfirmationFunc(SoAd_PduRouteCfgGetTxConfPduId(PduRouteIdx),E_NOT_OK);
    }
}
/********************************************************************************************************************
*   @brief This Api is used to terminate the transmission of the Tx tp pdu
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpTerminateTransmit(SoAd_SoConIdType SoConIdx)
{
    SoAd_ULIdxType PduRouteULIdx;
    SoAd_PduRouteDestIdxType PduRouteIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    SoAd_UpTpTxConfirmationFuncType pUpTpTxConfirmationFunc;
    
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx) ;
    PduRouteDestIdx = SoAd_SoConTxPduCtrlGetPduRouteDestIdx(TxPduCtrlIdx);
    PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
    PduRouteULIdx = SoAd_PduRouteCfgGetPduRouteULIdx(PduRouteIdx);
    pUpTpTxConfirmationFunc = SoAd_UpperLayerCfgGetUpTpTxConfirmationFunc(PduRouteULIdx);
    
    /* if transmission is active on socket connection. */
    if ((PduRouteDestIdx != SoAd_CfgGetNumOfPduRouteDest()) &&
        (SoAd_PduRouteCfgGetPduRouteULType(PduRouteIdx) == SOAD_UPPER_LAYER_TYPE_TP))
    {
        /* If all data has been sent */
        if (SoAd_SoConTxPduCtrlGetTxBytesPending(TxPduCtrlIdx)  == 0U)
        {
            pUpTpTxConfirmationFunc(SoAd_PduRouteCfgGetTxConfPduId(PduRouteIdx),E_OK);
        }
        else
        {
            pUpTpTxConfirmationFunc(SoAd_PduRouteCfgGetTxConfPduId(PduRouteIdx),E_NOT_OK);
        }
        /* Rest Tx Pdu status */
        SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,0u);
        SoAd_SoConTxPduCtrlSetTxBytesLen(TxPduCtrlIdx,0u);
        SoAd_SoConTxPduCtrlSetCancelRequest(TxPduCtrlIdx,FALSE);
        SoAd_SoConTxPduCtrlSetPduRouteDestIdx(TxPduCtrlIdx,SoAd_CfgGetNumOfPduRouteDest());
    }
}
/* #! udp tp tx */
/********************************************************************************************************************
*   @brief This Api is used to handle the transmission of the Udp Tp Pdu
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxTpUdpTransmit(SoAd_SoConIdType SoConIdx)
{
    Std_ReturnType RetVal=E_NOT_OK;
    PduLengthType CurrentBufferLength;
    SoAd_TpTxBufferIdxType TpTxBufferCfgIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx ;
    
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx) ;
    TpTxBufferCfgIdx = SoAd_SoConCfgGetTpTxBufferCfgIdx(SoConIdx);
    
    /* Update UDP alive supervision timeout. */
    SoAd_UpdateUdpAliveTimeout(SoConIdx);
    /* Copy PDU header to TP transmission buffer. */
    SoAd_TxTpUdpCopyPduHdr(SoConIdx);
    /* Copy PDU to TP transmission buffer. */
    if (SoAd_TxTpUdpCopyPdu(SoConIdx) == E_OK)
    {
        CurrentBufferLength = ((SoAd_TpTxBufferCtrlGetCurrentBufferIdx(TpTxBufferCfgIdx) - 
                                SoAd_TpTxBufferCfgGetBufferStartIdx(TpTxBufferCfgIdx)));
        /* Transmit PDU over UDP socket if PDU is copied completely to TP transmission buffer. */
        if (SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx) == CurrentBufferLength)
        {
            RetVal = SoAd_TxTpUdpTransmitOnSocket(SoConIdx);
        }
        else
        {
            /* If full length not copied , try in next main function */
            RetVal = E_OK;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to copy the pdu header of udp tp tx pdu for the SoCon idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpUdpCopyPduHdr(SoAd_SoConIdType SoConIdx)
{
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_TpTxBufferIdxType CurrentBufferIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    SoAd_TpTxBufferIdxType TpTxBufferCfgIdx;
    
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx) ;
    PduRouteDestIdx = SoAd_SoConTxPduCtrlGetPduRouteDestIdx(TxPduCtrlIdx);
    TpTxBufferCfgIdx = SoAd_SoConCfgGetTpTxBufferCfgIdx(SoConIdx);
    
    if (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
    {
        CurrentBufferIdx = SoAd_TpTxBufferCtrlGetCurrentBufferIdx(TpTxBufferCfgIdx);
        /* copy the pdu header data */
        if (CurrentBufferIdx == SoAd_TpTxBufferCfgGetBufferStartIdx(TpTxBufferCfgIdx))
        {
            /* Copy Pdu header to the Pdu */
            SoAd_UtilCopyPduHdr2Buf(SoAd_PduRouteDestCfgGetTxPduHeaderId(PduRouteDestIdx)  ,
                                (SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx) - SOAD_PDU_HEADER_SIZE),
                                SoAd_CtrlGetPtrToTpTxBuffer(CurrentBufferIdx),0u,SOAD_PDU_HEADER_SIZE);
            /* Update current position of the TpTx buffer */
            SoAd_TpTxBufferCtrlSetCurrentBufferIdx(TpTxBufferCfgIdx,
                                (SoAd_TpTxBufferCtrlGetCurrentBufferIdx(TpTxBufferCfgIdx)+SOAD_PDU_HEADER_SIZE));
        }
    }
}
/********************************************************************************************************************
*   @brief This Api is used to copy the pdu data for udp tp tx pdu for the SoCon idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxTpUdpCopyPdu(SoAd_SoConIdType SoConIdx)
{
    SoAd_ULIdxType PduRouteULIdx;
    boolean IsTxRequired = TRUE;
    PduLengthType AvailBufLength;
    PduLengthType ExpectedLength;
    SoAd_PduRouteIdxType PduRouteIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    PduInfoType PduInfo = {NULL_PTR,0u};
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    SoAd_TpTxBufferIdxType TpTxBufferCfgIdx;
    SoAd_UpTpCopyTxDataFuncType pUpTpCopyTxDataFunc;
    
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx) ;
    TpTxBufferCfgIdx = SoAd_SoConCfgGetTpTxBufferCfgIdx(SoConIdx);
    PduRouteDestIdx = SoAd_SoConTxPduCtrlGetPduRouteDestIdx(TxPduCtrlIdx);
    PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
    PduRouteULIdx = SoAd_PduRouteCfgGetPduRouteULIdx(PduRouteIdx); 
    ExpectedLength = SoAd_TpTxBufferCtrlGetCurrentBufferIdx(TpTxBufferCfgIdx) - 
                                SoAd_TpTxBufferCfgGetBufferStartIdx(TpTxBufferCfgIdx);
    while(SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx) > ExpectedLength)
    {
        /* Copy data from upper layer */
        pUpTpCopyTxDataFunc = SoAd_UpperLayerCfgGetUpTpCopyTxDataFunc(PduRouteULIdx);
        if (pUpTpCopyTxDataFunc != NULL_PTR)
        {
            if (BUFREQ_OK == pUpTpCopyTxDataFunc(SoAd_PduRouteCfgGetTxConfPduId(PduRouteIdx),
                                                &PduInfo,NULL_PTR,&AvailBufLength))
            {
                /* Increment the current buffer index */
                SoAd_TpTxBufferCtrlSetCurrentBufferIdx(TpTxBufferCfgIdx,
                            SoAd_TpTxBufferCtrlGetCurrentBufferIdx(TpTxBufferCfgIdx)+PduInfo.SduLength);
                ExpectedLength = SoAd_TpTxBufferCtrlGetCurrentBufferIdx(TpTxBufferCfgIdx) - 
                                            SoAd_TpTxBufferCfgGetBufferStartIdx(TpTxBufferCfgIdx);
                /* check if still buffer not filled */
                if (SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx) > ExpectedLength)
                {
                    if (AvailBufLength > (SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx) - ExpectedLength))
                    {
                        AvailBufLength = SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx) - ExpectedLength;
                    }
                    /* If buffer available , then set the PduInfo else set flag to process in next main function*/
                    if (AvailBufLength>0)
                    {
                        
                        PduInfo.SduDataPtr = SoAd_CtrlGetPtrToTpTxBuffer(
                                            SoAd_TpTxBufferCtrlGetCurrentBufferIdx(TpTxBufferCfgIdx)); 
                        PduInfo.SduLength = AvailBufLength;
                    }
                    else
                    {
                        SoAd_SoConEventCtrlSetEventTpTxQueueState(SoConIdx,TRUE);
                        IsTxRequired = FALSE;
                    }
                    RetVal = E_OK; 
                }
            }
            else
            {
                IsTxRequired = FALSE;
                SoAd_TxTpUdpTerminateTransmit(SoConIdx, E_NOT_OK);
            }
        }
        else
        {
            IsTxRequired = FALSE;
        }
        
        if (IsTxRequired == FALSE)
        {    
           break;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to transmi the tx tp udp pdu on the socket
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxTpUdpTransmitOnSocket(SoAd_SoConIdType SoConIdx)
{
    Std_ReturnType RetVal;
    SoAd_SocketIdxType SocketIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_TpTxBufferIdxType TpTxBufferCfgIdx;
    
    SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConIdx);
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx);
    TpTxBufferCfgIdx = SoAd_SoConCfgGetTpTxBufferCfgIdx(SoConIdx);
    /* Update SoCon TxPdu parameters */
    SoAd_SoConTxPduCtrlSetpBuffer(TxPduCtrlIdx,
                                SoAd_CtrlGetPtrToTpTxBuffer(SoAd_TpTxBufferCfgGetBufferStartIdx(TpTxBufferCfgIdx)));
    /* Try to tranmit on the socket */
    RetVal = SoAd_SocketUdpTransmit(SocketIdx,&SoAd_SoConCtrlGetRemoteAddr(SoConIdx),
                            SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx));
    /* Terminate TP session */
    SoAd_TxTpUdpTerminateTransmit(SoConIdx,RetVal);
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to terminate the tx tp udp pdu either on successful / failure transmission
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpUdpTerminateTransmit(SoAd_SoConIdType SoConIdx,Std_ReturnType Result)
{
    SoAd_SocketIdxType SocketIdx;
    SoAd_ULIdxType PduRouteULIdx;
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    SoAd_TpTxBufferIdxType TpTxBufferCfgIdx;
    SoAd_UpTpTxConfirmationFuncType pUpTpTxConfirmationFunc;
    
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx) ;
    TpTxBufferCfgIdx = SoAd_SoConCfgGetTpTxBufferCfgIdx(SoConIdx);
    PduRouteDestIdx = SoAd_SoConTxPduCtrlGetPduRouteDestIdx(TxPduCtrlIdx);
    PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
    SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConIdx);
    PduRouteULIdx = SoAd_PduRouteCfgGetPduRouteULIdx(PduRouteIdx);
    /* Reset Tp buffer */
    SoAd_TpTxBufferCtrlSetCurrentBufferIdx(TpTxBufferCfgIdx,SoAd_TpTxBufferCfgGetBufferStartIdx(TpTxBufferCfgIdx));
    /* Reset Tp session */
    SoAd_SoConTxPduCtrlSetPduRouteDestIdx(TxPduCtrlIdx,SoAd_CfgGetNumOfPduRouteDest());
	SoAd_SoConTxPduCtrlSetTxBytesLen(TxPduCtrlIdx,0U);
	SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,0U);
    SoAd_SocketCtrlSetActiveTxSoCon(SocketIdx,SoAd_CfgGetNumOfSoCon());
    /* Notify Upper layer about confirmation */
    pUpTpTxConfirmationFunc = SoAd_UpperLayerCfgGetUpTpTxConfirmationFunc(PduRouteULIdx);
    if (Result == E_OK)
    {
        if (NULL_PTR != pUpTpTxConfirmationFunc)
        {
            pUpTpTxConfirmationFunc(SoAd_PduRouteCfgGetTxConfPduId(PduRouteIdx),E_OK);
        }
        SoAd_SoConRequestReconnect(SoConIdx);
    }
    else
    {
        if (NULL_PTR != pUpTpTxConfirmationFunc)
        {
            pUpTpTxConfirmationFunc(SoAd_PduRouteCfgGetTxConfPduId(PduRouteIdx),E_NOT_OK);
        }
    }
}
/* #! tcp tp tx */
/********************************************************************************************************************
*   @brief This Api is used to transmit tcp tp pdu of the SoCon
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxTpTcpTransmit(SoAd_SoConIdType SoConIdx)
{
    PduInfoType PduInfo; 
    boolean DoTransmit = TRUE;
    SoAd_SocketIdxType SocketIdx;
    Std_ReturnType RetVal = E_OK;
    SoAd_ULIdxType PduRouteULIdx;
    SoAd_PduRouteIdxType PduRouteIdx;
    PduLengthType AvailBufferLength=0u;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    SoAd_UpTpCopyTxDataFuncType pUpTpCopyTxDataFunc;
    
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx) ;
    PduRouteDestIdx = SoAd_SoConTxPduCtrlGetPduRouteDestIdx(TxPduCtrlIdx);
    PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
    SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConIdx);
    PduInfo.SduDataPtr = NULL_PTR;
    PduInfo.SduLength = 0U;
    
    while((SoAd_SoConTxPduCtrlGetTxBytesPending(TxPduCtrlIdx) > 0u) && (DoTransmit != FALSE))
    {
        PduRouteULIdx = SoAd_PduRouteCfgGetPduRouteULIdx(PduRouteIdx);
        pUpTpCopyTxDataFunc = SoAd_UpperLayerCfgGetUpTpCopyTxDataFunc(PduRouteULIdx);
        if (pUpTpCopyTxDataFunc!= NULL_PTR)
        {
            if (BUFREQ_OK == pUpTpCopyTxDataFunc(SoAd_PduRouteCfgGetTxConfPduId(PduRouteIdx),&PduInfo,
                                                    NULL_PTR,&AvailBufferLength))
            {
                /* Get Buffer length with Pdu header */
                SoAd_TxTpTcpCalculateLength(SoConIdx, &AvailBufferLength);
                if (AvailBufferLength >0U)
                {
                    /* Try to transmit data and handle TP session if transmission succeeded. */
                    if ( E_OK == SoAd_SocketTcpTransmit(SocketIdx,AvailBufferLength, FALSE))
                    {
                        SoAd_TxTpTcpTransmitHandleSuccess(SoConIdx);
                    }
                    else
                    {
                        /* Return that transmission has failed and handle TP session otherwise. */
                        SoAd_TxTpTcpTransmitHandleFail(SoConIdx);
                        RetVal = E_NOT_OK;
                    }
                }
                else
                {
                    /* Try in next main function */
                    SoAd_SoConEventCtrlSetEventTpTx(SoConIdx,TRUE);
                    DoTransmit = FALSE;
                }
            }
            else
            {
                /* Indicate to close socket connection in main function. */
                SoAd_SoConSetCloseReq(SoConIdx, SOAD_CLOSE_REQ_OFFLINE_RESET);
                SoAd_SoConEventCtrlSetEventState(SoConIdx,TRUE);
                DoTransmit = FALSE;
                RetVal = E_NOT_OK;
            }
        }
        else
        {
            RetVal = E_NOT_OK;
            DoTransmit = FALSE;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to calcaulate the transmit tcp length for the SoCon
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpTcpCalculateLength
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(PduLengthType, AUTOMATIC, SOAD_APPL_VAR) pAvailBufferLength
)
{
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_SoConGrpIdxType  SoConGrpIdx;
    PduLengthType ExpectedMaxBufferLength, PduHeaderLen;
    
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx);
    if (*pAvailBufferLength >0U)
    {
        ExpectedMaxBufferLength = SoAd_SoConTxPduCtrlGetTxBytesPending(TxPduCtrlIdx);
        /* Update Header length if Header is configured */
        if (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
        {
            PduHeaderLen = SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx) - 
                                SoAd_SoConTxPduCtrlGetTxBytesPending(TxPduCtrlIdx);
            if (PduHeaderLen>SOAD_PDU_HEADER_SIZE)
            {
                PduHeaderLen=0U;
            }
            else
            {
                PduHeaderLen = SOAD_PDU_HEADER_SIZE - PduHeaderLen;
            }
            *pAvailBufferLength += PduHeaderLen;
        }
        
        if (*pAvailBufferLength > ExpectedMaxBufferLength)
        {
            *pAvailBufferLength = ExpectedMaxBufferLength;
        }
    }
}
/********************************************************************************************************************
*   @brief This Api is used to handle the tcp transmit success of the SoCon
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpTcpTransmitHandleSuccess(SoAd_SoConIdType SoConIdx)
{
    SoAd_SocketIdxType SocketIdx;
    SoAd_ULIdxType PduRouteULIdx;
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    SoAd_UpTpTxConfirmationFuncType pUpTpTxConfirmationFunc;
    
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx) ;
    PduRouteDestIdx = SoAd_SoConTxPduCtrlGetPduRouteDestIdx(TxPduCtrlIdx);
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    SocketIdx =  SoAd_SoConCfgGetSocketIdx(SoConIdx);
    PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
    PduRouteULIdx = SoAd_PduRouteCfgGetPduRouteULIdx(PduRouteIdx);
    /* If transmit success , then Reset Tp session and notify upper layer */
    if (SoAd_SoConTxPduCtrlGetTxBytesPending(TxPduCtrlIdx)  == 0u)
    {
        if (SoAd_SoConGrpCfgIsTcpImmConfSupported(SoConGrpIdx) == TRUE)
        {
            SoAd_SoConTxPduCtrlSetPduRouteDestIdx(TxPduCtrlIdx,SoAd_CfgGetNumOfPduRouteDest());
            SoAd_SoConTxPduCtrlSetTxBytesLen(TxPduCtrlIdx,0U);
            SoAd_SocketCtrlSetActiveTxSoCon(SocketIdx,SoAd_CfgGetNumOfSoCon());
            /* Reconnect socket connection. */
            SoAd_SoConRequestReconnect(SoConIdx);
            /* Notify upper layer */
            pUpTpTxConfirmationFunc = SoAd_UpperLayerCfgGetUpTpTxConfirmationFunc(PduRouteULIdx);
            if (pUpTpTxConfirmationFunc != NULL_PTR)
            {
                pUpTpTxConfirmationFunc(SoAd_PduRouteCfgGetTxConfPduId(PduRouteIdx),E_OK);
            }
            /* Remove element from the TxTcp queue*/
            SoAd_TxTcpQueueRemoveElement(SoConIdx,PduRouteIdx);
        }
    }
}
/********************************************************************************************************************
*   @brief This Api is used to handle the tcp transmit fail of the SoCon
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpTcpTransmitHandleFail(SoAd_SoConIdType SoConIdx)
{
    SoAd_ULIdxType PduRouteULIdx;
    SoAd_SocketIdxType  SocketIdx;
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    SoAd_UpTpTxConfirmationFuncType pUpTpTxConfirmationFunc;
    
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx) ;
    PduRouteDestIdx = SoAd_SoConTxPduCtrlGetPduRouteDestIdx(TxPduCtrlIdx);
    SocketIdx =  SoAd_SoConCfgGetSocketIdx(SoConIdx);
    PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
    PduRouteULIdx = SoAd_PduRouteCfgGetPduRouteULIdx(PduRouteIdx); 
    /* If Transmission in progress , request to close socket connection */
    if (SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx) != SoAd_SoConTxPduCtrlGetTxBytesPending(TxPduCtrlIdx))
    {
        SoAd_SoConSetCloseReq(SoConIdx, SOAD_CLOSE_REQ_OFFLINE_RESET);
        SoAd_SoConEventCtrlSetEventState(SoConIdx,TRUE);
    }
    else
    {
        /* Remove element from the TxTcp queue*/
        SoAd_TxTcpQueueRemoveElement(SoConIdx,PduRouteIdx);
    }
    /* Reset TP session. */
    SoAd_SoConTxPduCtrlSetPduRouteDestIdx(TxPduCtrlIdx,SoAd_CfgGetNumOfPduRouteDest());
    SoAd_SoConTxPduCtrlSetTxBytesLen(TxPduCtrlIdx,0U);
    SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,0U);
    SoAd_SocketCtrlSetActiveTxSoCon(SocketIdx,SoAd_CfgGetNumOfSoCon());
    /* Notify upper layer */
    pUpTpTxConfirmationFunc = SoAd_UpperLayerCfgGetUpTpTxConfirmationFunc(PduRouteULIdx);
    if (pUpTpTxConfirmationFunc != NULL_PTR)
    {
        pUpTpTxConfirmationFunc(SoAd_PduRouteCfgGetTxConfPduId(PduRouteIdx),E_NOT_OK);
    }
}
/* #! copy data */
/********************************************************************************************************************
*   @brief This Api is used to check the parameters for the Tx Copy api for the SoCon
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxCopyTxDataCheckParameter
(
    SoAd_SoConIdType SoConIdx,
    uint16 BufferLength
)
{
    Std_ReturnType RetVal = E_OK;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx ;
    /* Check for valid Input parameters */
    if (SoConIdx != SoAd_CfgGetNumOfSoCon())
    {
        TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx) ;
        if ((SoAd_SoConCtrlGetCloseReqType(SoConIdx) != SOAD_CLOSE_REQ_NONE) ||
            (SoAd_SoConCtrlGetSoConMode(SoConIdx) != SOAD_SOCON_ONLINE))
        {
            RetVal = E_NOT_OK;
        }
        
        if (BufferLength > SoAd_SoConTxPduCtrlGetTxBytesPending(TxPduCtrlIdx))
        {
            RetVal = E_NOT_OK;
        }
    }
    else
    {
        RetVal = E_NOT_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to handle the pdu header copy tx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxCopyTxDataPduHeader
(
    SoAd_SoConIdType SoConIdx,
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2VAR(uint8*, AUTOMATIC, SOAD_APPL_VAR) BufPtrPtr,
    P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) BufLengthPtr
)
{
    uint16 BytesCopied =0U;
    uint16 BytesToCopy=0U;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx ;
    
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx);
    BytesCopied = SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx) - SoAd_SoConTxPduCtrlGetTxBytesPending(TxPduCtrlIdx);
    if (BytesCopied < SOAD_PDU_HEADER_SIZE)
    {
        /* Calculate the bytes to be copied */
        BytesToCopy = SOAD_PDU_HEADER_SIZE - BytesCopied;
        if (BytesToCopy > *BufLengthPtr)
        {
            BytesToCopy = *BufLengthPtr;
        }
        /* Copy Pdu header to the Pdu */
        SoAd_UtilCopyPduHdr2Buf(SoAd_PduRouteDestCfgGetTxPduHeaderId(PduRouteDestIdx),
                                (SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx) - SOAD_PDU_HEADER_SIZE),
                                *BufPtrPtr,BytesCopied,BytesToCopy);
        /* Update pending data to be copied and buffer length */
        SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,
                                            (SoAd_SoConTxPduCtrlGetTxBytesPending(TxPduCtrlIdx)-BytesToCopy));
        /* Update the ip buffer length and buffer pointer position after Pdu Header */
        *BufLengthPtr -= (uint16)BytesToCopy;
        *BufPtrPtr = &(*BufPtrPtr)[BytesToCopy];
    }
}
/********************************************************************************************************************
*   @brief This Api is used to copy the pdu header to the buffer provided
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_UtilCopyPduHdr2Buf
(
    SoAd_PduHeaderIdType  PduHeaderId,
    SoAd_PduHeaderLenType PduHeaderLen,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Offset,
    uint16 Length
)
{
    uint16 PduHeaderByteIdx;
    uint8  PduHeaderBuffer[SOAD_PDU_HEADER_SIZE];
    
    if(Length == SOAD_PDU_HEADER_SIZE)
    {
        /* Copy the PDU header  */
        BufPtr[0u] = (uint8)(PduHeaderId >> 24u);
        BufPtr[1u] = (uint8)(PduHeaderId >> 16u);
        BufPtr[2u] = (uint8)(PduHeaderId >> 8u);
        BufPtr[3u] = (uint8)(PduHeaderId);
        BufPtr[4u] = (uint8)(PduHeaderLen >> 24u);
        BufPtr[5u] = (uint8)(PduHeaderLen >> 16u);
        BufPtr[6u] = (uint8)(PduHeaderLen >> 8u); 
        BufPtr[7u] = (uint8)(PduHeaderLen);
    }
    else
    {
        /* Copy PDU header to local buffer and then */
        PduHeaderBuffer[0u] = (uint8)(PduHeaderId >> 24u);
        PduHeaderBuffer[1u] = (uint8)(PduHeaderId >> 16u);
        PduHeaderBuffer[2u] = (uint8)(PduHeaderId >> 8u);
        PduHeaderBuffer[3u] = (uint8)(PduHeaderId);  
        PduHeaderBuffer[4u] = (uint8)(PduHeaderLen >> 24u);
        PduHeaderBuffer[5u] = (uint8)(PduHeaderLen >> 16u);
        PduHeaderBuffer[6u] = (uint8)(PduHeaderLen >> 8u); 
        PduHeaderBuffer[7u] = (uint8)(PduHeaderLen);
        /* Copy PDU header segment from local buffer to provided buffer. */
        for(PduHeaderByteIdx = Offset; PduHeaderByteIdx < (Offset + Length);PduHeaderByteIdx++ )
        {
            BufPtr[PduHeaderByteIdx-Offset] = PduHeaderBuffer[PduHeaderByteIdx];
        }
    }
}
/* #! copy data if udp */
/********************************************************************************************************************
*   @brief This Api is used to handle the udp tx if copy data
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_TxIfUdpCopyTxData
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 BufLength
)
{
    uint8 * pLocalBuffer;
    uint16 LocalBufferLength;
    BufReq_ReturnType RetVal;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    
    pLocalBuffer = BufPtr;
    LocalBufferLength = BufLength;
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx);
    PduRouteDestIdx=SoAd_SoConTxPduCtrlGetPduRouteDestIdx(TxPduCtrlIdx);
    PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
    
    if(SoAd_SoConCfgIsUdpNPduSupported(SoConIdx) == FALSE) 
    {
        /* Copy PDU header to provided buffer if used. */
        if(SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
        {
            SoAd_TxCopyTxDataPduHeader(SoConIdx, PduRouteDestIdx, &pLocalBuffer, &LocalBufferLength);
        }
        
        if (SoAd_PduRouteCfgIsIfTriggerTxEnabled(PduRouteIdx) == TRUE)
        {
            /* Copy data via trigger tranmit from upper layer */
            RetVal = SoAd_TxIfUdpCopyTxDataTrigger(SoConIdx, PduRouteIdx, BufPtr, &BufLength); 
        }
        else
        {
            /* Copy data from the buffer */
            SoAd_TxIfUdpCopyTxDataDirect(SoConIdx, pLocalBuffer, LocalBufferLength);
            RetVal = BUFREQ_OK;
        }
    }
    else
    {
        RetVal = SoAd_TxNPduUdpCopyTxData(SoConIdx, BufPtr, &BufLength); 
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to process the trigger transmit copy data in the udp tx if copy data
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_TxIfUdpCopyTxDataTrigger
(
    SoAd_SoConIdType SoConIdx,
    SoAd_PduRouteIdxType PduRouteIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) BufLengthPtr
)
{
    PduInfoType PduInfo;
    boolean PduHeaderSupport;
    SoAd_ULIdxType PduRouteULIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    BufReq_ReturnType RetVal = BUFREQ_E_NOT_OK;
    SoAd_UpIfTriggerTransmitFuncType pUpIfTriggerTransmitFunc;
    
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    PduRouteULIdx = SoAd_PduRouteCfgGetPduRouteULIdx(PduRouteIdx); 
    pUpIfTriggerTransmitFunc = SoAd_UpperLayerCfgGetUpIfTriggerTransmitFunc(PduRouteULIdx);
    PduHeaderSupport = SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx);
    /* Update PduInfo based on the Pdu header */
    if (PduHeaderSupport == TRUE)
    {
        PduInfo.SduDataPtr = &BufPtr[SOAD_PDU_HEADER_SIZE];
        PduInfo.SduLength = (PduLengthType)(*BufLengthPtr - SOAD_PDU_HEADER_SIZE);
    }
    else
    {
        PduInfo.SduDataPtr = BufPtr;
        PduInfo.SduLength = (PduLengthType)*BufLengthPtr;
    }

    if (pUpIfTriggerTransmitFunc != NULL_PTR)
    {
        if (pUpIfTriggerTransmitFunc(SoAd_PduRouteCfgGetTxConfPduId(PduRouteIdx),&PduInfo) == E_OK)
        {
            /* check valid PduInfo */
            if (((PduHeaderSupport == TRUE) && (PduInfo.SduLength !=(*BufLengthPtr - SOAD_PDU_HEADER_SIZE))) ||
                ((PduHeaderSupport == FALSE) && (PduInfo.SduLength != (*BufLengthPtr))))
            {
                RetVal = BUFREQ_E_NOT_OK;
            }
            else if (PduInfo.SduDataPtr != NULL_PTR)
            {
                RetVal = BUFREQ_E_NOT_OK;
            }
            else
            {
                TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx) ;
                SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,0U);
                RetVal = BUFREQ_OK;
            }
        }
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to handle the direct data copy in the udp tx if copy data
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxIfUdpCopyTxDataDirect
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 BufLength
)
{
    uint16 BytesToCopy;
    uint8 * pLocalBuffer;
    PduLengthType BytesCopied;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;

    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx);
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    BytesCopied = SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx)-SoAd_SoConTxPduCtrlGetTxBytesPending(TxPduCtrlIdx);
    /* Copy PDU header to provided buffer if used. */
    if (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
    {
        if (BytesCopied<SOAD_PDU_HEADER_SIZE)
        {
            BytesToCopy = 0U;
            BytesCopied = 0U;
        }
        else
        {
            BytesToCopy = BufLength;
            BytesCopied -= SOAD_PDU_HEADER_SIZE;
        }
    }
    else
    {
        BytesToCopy = BufLength;
    }
    /* Copy PDU data. */
    pLocalBuffer = SoAd_SoConTxPduCtrlGetpBuffer(TxPduCtrlIdx);
    SoAd_UtilMemCopy(&BufPtr[0u],&pLocalBuffer[BytesCopied],BytesToCopy);
    SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,(SoAd_SoConTxPduCtrlGetTxBytesPending(TxPduCtrlIdx)-BytesToCopy));
}
/* #! copy data if tcp */
/********************************************************************************************************************
*   @brief This Api is used to process the tcp if tx copy data call 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxIfTcpCopyTxData
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 BufLength
)
{
    uint16 BytesCopied;
    uint8 * LocalBufPtr;
    uint8 * pTxSrcBuffer;
    uint16 LocalBufLength;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    
    LocalBufPtr = BufPtr;
    LocalBufLength = BufLength;
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx) ;
    PduRouteDestIdx = SoAd_SoConTxPduCtrlGetPduRouteDestIdx(TxPduCtrlIdx);
    if(SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
    {
        SoAd_TxCopyTxDataPduHeader(SoConIdx, PduRouteDestIdx, &LocalBufPtr, &LocalBufLength);
        BytesCopied = SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx) - 
                            SoAd_SoConTxPduCtrlGetTxBytesPending(TxPduCtrlIdx);
        if (BytesCopied >= SOAD_PDU_HEADER_SIZE)
        {
            BytesCopied -= SOAD_PDU_HEADER_SIZE;
            if (LocalBufLength>0U)
            {
                pTxSrcBuffer = &SoAd_SoConTxPduCtrlGetpBufferWithOffset(TxPduCtrlIdx,BytesCopied);
                /* Copy data */
                SoAd_UtilMemCopy(LocalBufPtr,pTxSrcBuffer,LocalBufLength);
            }
        }
    }
    else
    {
        /* copy data */
        BytesCopied = SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx) - 
                        SoAd_SoConTxPduCtrlGetTxBytesPending(TxPduCtrlIdx);
        pTxSrcBuffer = &SoAd_SoConTxPduCtrlGetpBufferWithOffset(TxPduCtrlIdx,BytesCopied);
        SoAd_UtilMemCopy(LocalBufPtr,pTxSrcBuffer,LocalBufLength);
    }
}
/* #! copy data tp udp */
/********************************************************************************************************************
*   @brief This Api is used to handle the udp tx Tp copy data
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxTpUdpCopyTxData
(
  SoAd_SoConIdType SoConIdx,
  P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
  uint16 BufLength
)
{
    uint8 * pLocalBuffer;
    PduLengthType BytesCopied;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx);
    BytesCopied = SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx)-SoAd_SoConTxPduCtrlGetTxBytesPending(TxPduCtrlIdx);
    /* Copy PDU data. */
    pLocalBuffer = SoAd_SoConTxPduCtrlGetpBuffer(TxPduCtrlIdx);
    SoAd_UtilMemCopy(&BufPtr[0u],&pLocalBuffer[BytesCopied],BufLength);
    SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,(SoAd_SoConTxPduCtrlGetTxBytesPending(TxPduCtrlIdx)-BufLength));
}
/* #! copy data tp tcp */
/********************************************************************************************************************
*   @brief This Api is used to handle the tcp tx copy data
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_TxTpTcpCopyTxData
(
    SoAd_SoConIdType SoConIdx,
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 BufLength
)
{
    PduInfoType PduInfo;
    uint8 * LocalBufPtr;
    uint16 LocalBufLength;
    BufReq_ReturnType RetVal;
    SoAd_ULIdxType PduRouteULIdx;
    PduLengthType AvailBufLength=0u;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_UpTpCopyTxDataFuncType pUpTpCopyTxDataFunc;
    
    LocalBufPtr = BufPtr;
    LocalBufLength = BufLength;
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx);
    PduRouteDestIdx = SoAd_SoConTxPduCtrlGetPduRouteDestIdx(TxPduCtrlIdx);
    PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
    
    if (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
    {
        /* If Pdu header id supported, then copy the header data */
        SoAd_TxCopyTxDataPduHeader(SoConIdx, PduRouteDestIdx, &LocalBufPtr, &LocalBufLength);
    }
    
    if(LocalBufLength != 0U)
    {
        /* If provided buffer is available to copy the data , then get data from upper layer copy data */
        PduInfo.SduDataPtr = LocalBufPtr;
        PduInfo.SduLength = (PduLengthType)LocalBufLength;
        
        PduRouteULIdx = SoAd_PduRouteCfgGetPduRouteULIdx(PduRouteIdx);;
        pUpTpCopyTxDataFunc = SoAd_UpperLayerCfgGetUpTpCopyTxDataFunc(PduRouteULIdx);
        if (pUpTpCopyTxDataFunc != NULL_PTR)
        {
            /* Get data from the upper layer */
            RetVal = pUpTpCopyTxDataFunc(SoAd_PduRouteCfgGetTxConfPduId(PduRouteIdx),&PduInfo,NULL_PTR,&AvailBufLength);
            if (RetVal==BUFREQ_OK)
            {
                SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,
                                            (SoAd_SoConTxPduCtrlGetTxBytesPending(TxPduCtrlIdx)-LocalBufLength));
            }
        }
        else
        {
            RetVal = BUFREQ_E_NOT_OK;
        }
    }
    else
    {
        RetVal = BUFREQ_OK;
    }
    return RetVal;
}
/* #! Udp NPdu Tx */
/********************************************************************************************************************
*   @brief This Api is used to handle the udp tx if NPdu 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfUdpTransmitNPdu
(
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) ErrorIdPtr
)
{
    SoAd_SoConIdType SoConIdx;
    PduLengthType LocalDataLength;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SocketUdpIdxType SocketUdpIdx;
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx; 
    
    SoConIdx = SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx);
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    SocketUdpIdx = SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx);
    LocalDataLength = PduInfoPtr->SduLength;
    /* Calculate length based on the Pdu header */
    if (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
    {
        LocalDataLength+=SOAD_PDU_HEADER_SIZE;
    }
    /* Check for valid length */
    if (LocalDataLength <= SoAd_SocketUdpCfgGetNPduUdpTxBufferMin(SocketUdpIdx)) 
    {
        NPduUdpTxIdx = SoAd_SoConCfgGetNPduUdpTxIdx(SoConIdx); 
        if (SoAd_NPduUdpTxCfgGetQueueSupport(NPduUdpTxIdx) == TRUE) 
        {
            /* Transmit via queue */
            RetVal = SoAd_TxIfUdpTransmitNPduQueue(PduRouteDestIdx, PduInfoPtr);
        }
        else
        {   
            /* Transmit via Npdu buffer */
            RetVal = SoAd_TxIfUdpTransmitNPduBuffer(PduRouteDestIdx, PduInfoPtr);
        }
    }
    else
    {
        *ErrorIdPtr = SOAD_E_INV_ARG;
    }
    return RetVal; 
}
/********************************************************************************************************************
*   @brief This Api is used to transmit the data from buffer for udp tx if NPdu 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfUdpTransmitNPduBuffer
(
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
)
{
    SoAd_SoConIdType SoConIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx;
    SoAd_NPduReturnType NPduUpdateStatus;
    
    PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
    SoConIdx = SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx);
    NPduUdpTxIdx = SoAd_SoConCfgGetNPduUdpTxIdx(SoConIdx);
    
    NPduUpdateStatus = SoAd_TxNPduUdpBufferAddElement(PduRouteIdx,PduRouteDestIdx,PduInfoPtr);
    if (NPduUpdateStatus == SOAD_NPDU_OK) 
    {
        /*  if trigger mode is set to always ,Transmit nPdu now */
        if (SoAd_PduRouteDestCfgGetTxUdpTriggerMode(PduRouteDestIdx) == SOAD_TX_UDP_TRIGGER_ALWAYS)
        {
            SoAd_TxNPduUdpBufferSend(NPduUdpTxIdx);
        }
        RetVal = E_OK;
    }
    else if (NPduUpdateStatus == SOAD_NPDU_OVFL_NEW)
    {
        /* if overflow occured, transmit current nPdu. */
        SoAd_TxNPduUdpBufferSend(NPduUdpTxIdx);

        /* Add new PDU to nPdu again. */
        if (SoAd_TxNPduUdpBufferAddElement(PduRouteIdx, PduRouteDestIdx, PduInfoPtr) == SOAD_NPDU_OK )
        {
            /*  if trigger mode is set to always ,Transmit nPdu now */
            if (SoAd_PduRouteDestCfgGetTxUdpTriggerMode(PduRouteDestIdx) == SOAD_TX_UDP_TRIGGER_ALWAYS)
            {
                SoAd_TxNPduUdpBufferSend(NPduUdpTxIdx);
            }
            RetVal = E_OK;
        }
    }
    else
    {
        /* Do Nothing */
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to add buffer element for the Udp Tx NPdu
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(SoAd_NPduReturnType, SOAD_CODE) SoAd_TxNPduUdpBufferAddElement
(
    SoAd_PduRouteIdxType PduRouteIdx,
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
)
{
    SoAd_NPduReturnType RetVal;
    SoAd_SoConIdType SoConIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    PduLengthType LocalDataLength = 0u;
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx;
    SoAd_SocketUdpIdxType SocketUdpIdx;
    SoAd_NPduUdpTxBufferSizeType BufferOffset;
    
    SoConIdx = SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx);
    NPduUdpTxIdx = SoAd_SoConCfgGetNPduUdpTxIdx(SoConIdx);
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    SocketUdpIdx = SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx);
    
    SoAd_EnterCriticalSection();
    
    /* Check if no Tx is active */
    if (SoAd_NPduUdpTxCtrlGetIsTxActive(NPduUdpTxIdx) == FALSE)
    {
        /* Calculate length based on the Pdu header */
        if (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
        {
            LocalDataLength+=SOAD_PDU_HEADER_SIZE;
        }
        
        if ((SoAd_NPduUdpTxCtrlGetTotalLength(NPduUdpTxIdx)+ LocalDataLength) > 
                                        SoAd_SocketUdpCfgGetNPduUdpTxBufferMin(SocketUdpIdx))
        {
            /* if nPdu size is not sufficient for new request.  */
            RetVal = SOAD_NPDU_OVFL_NEW;
        }
        else
        {
            /* Update NpduTimeout */
            SoAd_TxNPduUdpSetTriggerTimeout(NPduUdpTxIdx,PduRouteDestIdx);
            if (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
            {
                BufferOffset = SoAd_NPduUdpTxCfgGetNPduUdpTxBufferStartIdx(NPduUdpTxIdx) + 
                                            SoAd_NPduUdpTxCtrlGetBufferLength(NPduUdpTxIdx); 
                /* copy pdu header */
                SoAd_UtilCopyPduHdr2Buf(SoAd_PduRouteDestCfgGetTxPduHeaderId(PduRouteDestIdx),PduInfoPtr->SduLength,
                                       SoAd_CtrlGetPtrToNPduUdpTxBuffer(BufferOffset),0u,SOAD_PDU_HEADER_SIZE);
                /* Update length */
                SoAd_NPduUdpTxCtrlSetBufferLength(NPduUdpTxIdx,
                                        SoAd_NPduUdpTxCtrlGetBufferLength(NPduUdpTxIdx)+SOAD_PDU_HEADER_SIZE);
                SoAd_NPduUdpTxCtrlSetTotalLength(NPduUdpTxIdx,
                                        SoAd_NPduUdpTxCtrlGetTotalLength(NPduUdpTxIdx)+SOAD_PDU_HEADER_SIZE);
            }
            /* Copy data */
            BufferOffset = SoAd_NPduUdpTxCfgGetNPduUdpTxBufferStartIdx(NPduUdpTxIdx) + 
                                                            SoAd_NPduUdpTxCtrlGetBufferLength(NPduUdpTxIdx);
            SoAd_UtilMemCopy(SoAd_CtrlGetPtrToNPduUdpTxBuffer(BufferOffset),
                                &PduInfoPtr->SduDataPtr[0],PduInfoPtr->SduLength);
            /* Update Length */
            SoAd_NPduUdpTxCtrlSetBufferLength(NPduUdpTxIdx,
                                    SoAd_NPduUdpTxCtrlGetBufferLength(NPduUdpTxIdx)+PduInfoPtr->SduLength);
            SoAd_NPduUdpTxCtrlSetTotalLength(NPduUdpTxIdx,
                                    SoAd_NPduUdpTxCtrlGetTotalLength(NPduUdpTxIdx)+PduInfoPtr->SduLength);
            /* Increment Pending confirmation */
            SoAd_PduRouteCtrlIncNumOfPendingTxConf(PduRouteIdx);
            RetVal = SOAD_NPDU_OK;
        }
    }
    else
    {
        RetVal = SOAD_NPDU_NOT_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to haddle the transmission of the the Udp Tx NPdu
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxNPduUdpBufferSend(SoAd_NPduUdpTxIdxType NPduUdpTxIdx)
{
    SoAd_SoConIdType SoConIdx;
    SoAd_SocketIdxType SocketIdx; 
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_PduRouteDestIdxType  PduRouteDestIdx;  
    SoAd_NPduUdpTxTimerIdxType NPduUdpTxTimerIdx;
    
    SoConIdx = SoAd_NPduUdpTxCfgGetSoConIdx(NPduUdpTxIdx);
    SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConIdx);
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx);
    
    /* Check if tx data available */
    if (SoAd_NPduUdpTxCtrlGetTotalLength(NPduUdpTxIdx) > 0U)
    {
        /* Check if no tx is pending on this socket */
        if (SoAd_SocketCtrlGetActiveTxSoCon(SocketIdx) != SoAd_CfgGetNumOfSoCon())
        {
            SoAd_EnterCriticalSection();
            /* Use first PduRouteDest of socket connection as dummy identifier 
                (used to identify API type in CopyTxData). */
            PduRouteDestIdx = SoAd_SoConCfgGetPduRouteDestStartIdx(SoConIdx);
            /* Update the TxNPdu status */
            SoAd_NPduUdpTxCtrlSetIsTxActive(NPduUdpTxIdx,TRUE);
             /* Update tx pending on this socket */
            SoAd_SocketCtrlSetActiveTxSoCon(SocketIdx,SoConIdx);
            /* Update SoCon TxPdu Ctrl status */
            SoAd_SoConTxPduCtrlSetPduRouteDestIdx(TxPduCtrlIdx,PduRouteDestIdx);
            SoAd_SoConTxPduCtrlSetTxBytesLen(TxPduCtrlIdx,SoAd_NPduUdpTxCtrlGetTotalLength(NPduUdpTxIdx));
            SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,SoAd_NPduUdpTxCtrlGetTotalLength(NPduUdpTxIdx));
            SoAd_SoConTxPduCtrlSetpBuffer(TxPduCtrlIdx,NULL_PTR);
            SoAd_ExitCriticalSection();
            /* Try to send the pdu on the socket */
            (void)SoAd_SocketUdpTransmit(SocketIdx,&SoAd_SoConCtrlGetRemoteAddr(SoConIdx),
                                        SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx));                                
            SoAd_EnterCriticalSection();
            /* Cancel the Npdu timer */
            NPduUdpTxTimerIdx = SoAd_NPduUdpTxCfgGetTxUdpNPduTimerIdx(NPduUdpTxIdx);
            SoAd_CtrlSetTxUdpNPduTimer(NPduUdpTxTimerIdx,0u);
            /* Reset the Npdu status */
            SoAd_NPduUdpTxCtrlSetIsTxActive(NPduUdpTxIdx,FALSE);
            SoAd_NPduUdpTxCtrlSetTotalLength(NPduUdpTxIdx,0u);
            SoAd_NPduUdpTxCtrlSetBufferLength(NPduUdpTxIdx,0u);
            SoAd_SoConTxPduCtrlSetPduRouteDestIdx(TxPduCtrlIdx,SoAd_CfgGetNumOfPduRouteDest());
            SoAd_SocketCtrlSetActiveTxSoCon(SocketIdx,SoAd_CfgGetNumOfSoCon());
            SoAd_ExitCriticalSection();
        }
    }
}
/********************************************************************************************************************
*   @brief This Api is used to set the trigger timeout for the the Udp Tx NPdu
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxNPduUdpSetTriggerTimeout
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx,
    SoAd_PduRouteDestIdxType PduRouteDestIdx
)
{
    SoAd_SoConIdType SoConIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SocketUdpIdxType SocketUdpIdx;
    SoAd_NPduUdpTxTimerIdxType NPduUdpTxTimerIdx;
    
    SoConIdx = SoAd_NPduUdpTxCfgGetSoConIdx(NPduUdpTxIdx) ;
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    SocketUdpIdx =SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx);
    NPduUdpTxTimerIdx = SoAd_NPduUdpTxCfgGetTxUdpNPduTimerIdx(NPduUdpTxIdx); 
    /* Set PduRoute UdpTriggerTimeout if configured else set the Socket connection TriggerTimeout */
    if (SoAd_PduRouteDestCfgGetUdpTriggerTimeout(PduRouteDestIdx) > 0U) 
    {
        /* Update timer from PduRouteDest */
        if (SoAd_CtrlGetTxUdpNPduTimer(NPduUdpTxTimerIdx) == 0U)  
        {
            SoAd_CtrlSetTxUdpNPduTimer(NPduUdpTxTimerIdx,SoAd_PduRouteDestCfgGetUdpTriggerTimeout(PduRouteDestIdx));
        }
    }
    else
    {
        /* Update timer from SoCon Udp config */
        if (SoAd_CtrlGetTxUdpNPduTimer(NPduUdpTxTimerIdx) == 0U)
        {
            SoAd_CtrlSetTxUdpNPduTimer(NPduUdpTxTimerIdx,SoAd_SocketUdpCfgGetTriggerTimeout(SocketUdpIdx));
        }
    }
}
/********************************************************************************************************************
*   @brief This Api is used to handle the tranmission of If the Udp Tx NPdu from the queue
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxIfUdpTransmitNPduQueue
(
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
)
{
    SoAd_SoConIdType SoConIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx;
    SoAd_NPduReturnType  TxNPduUdpQueueStatus;
    
    SoConIdx = SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx);
    NPduUdpTxIdx = SoAd_SoConCfgGetNPduUdpTxIdx(SoConIdx);
    
    TxNPduUdpQueueStatus = SoAd_TxNPduUdpQueueAddOrUpdateElement(PduRouteDestIdx, PduInfoPtr);
    if (TxNPduUdpQueueStatus == SOAD_NPDU_OVFL_NEW)
    {
        /* Transmit nPdu. */
        SoAd_TxNPduUdpQueueTransmit(NPduUdpTxIdx);
        /* Try to add new PDU to nPdu again. */
        if(SoAd_TxNPduUdpQueueAddOrUpdateElement(PduRouteDestIdx, PduInfoPtr) == SOAD_NPDU_OK ) 
        {
            /* Transmit nPdu now if trigger mode is set to always. */
            if (SoAd_PduRouteDestCfgGetTxUdpTriggerMode(PduRouteDestIdx) == SOAD_TX_UDP_TRIGGER_ALWAYS)
            {
                SoAd_TxNPduUdpQueueTransmit(NPduUdpTxIdx);
            }
            RetVal = E_OK;
        }
    }
    else if (TxNPduUdpQueueStatus == SOAD_NPDU_OVFL_UPDATE)
    {
        /* Transmit nPdu now  */
        SoAd_TxNPduUdpQueueTransmit(NPduUdpTxIdx);
        RetVal = E_OK;
    }
    else
    {
        /* Transmit nPdu now if trigger mode is set to always. */
        if (SoAd_PduRouteDestCfgGetTxUdpTriggerMode(PduRouteDestIdx) == SOAD_TX_UDP_TRIGGER_ALWAYS)
        {
            SoAd_TxNPduUdpQueueTransmit(NPduUdpTxIdx);
        }
        RetVal = E_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to add or udpate element to the Udp NPdu tx queue
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(SoAd_NPduReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueAddOrUpdateElement
(
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
)
{
    SoAd_SoConIdType SoConIdx;
    SoAd_NPduReturnType RetVal;
    boolean IsElementUpdated=FALSE;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx;
    PduLengthType LocalDataLength = 0U;
    
    SoConIdx = SoAd_PduRouteDestCfgGetSoConIdx(PduRouteDestIdx);
    NPduUdpTxIdx = SoAd_SoConCfgGetNPduUdpTxIdx(SoConIdx);
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    
    SoAd_EnterCriticalSection();
    /* Calculate length based on the Pdu header */
    if (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
    {
        LocalDataLength+=SOAD_PDU_HEADER_SIZE;
    }
    /* Check and update if PDU is already in queue. */
    RetVal = SoAd_TxNPduUdpQueueUpdateElement(NPduUdpTxIdx, PduRouteDestIdx, LocalDataLength, &IsElementUpdated);
    /* Try to add element if PDU is not updated. */
    if (IsElementUpdated == FALSE)
    {
        /* Check if no Tx is active */
        if (SoAd_NPduUdpTxCtrlGetIsTxActive(NPduUdpTxIdx) == FALSE) 
        {
            RetVal = SoAd_TxNPduUdpQueueAddElement(NPduUdpTxIdx, PduRouteDestIdx, LocalDataLength, PduInfoPtr);
        }
        /* Indicate overflow of nPdu otherwise. */
        else
        {
            RetVal = SOAD_NPDU_OVFL_NEW;
        }
    }
    SoAd_ExitCriticalSection();
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to udpate element to the Udp NPdu tx queue
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(SoAd_NPduReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueUpdateElement
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx,
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    PduLengthType DataLen,
    P2VAR(boolean, AUTOMATIC, SOAD_APPL_VAR) ElementUpdated
)
{
    SoAd_SoConIdType SoConIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_SocketUdpIdxType SocketUdpIdx;
    SoAd_NPduReturnType RetVal = SOAD_NPDU_OK;
    SoAd_NPduUdpTxQueueIdxType NPduUdpTxQueueIdx;
    
    SoConIdx = SoAd_NPduUdpTxCfgGetSoConIdx(NPduUdpTxIdx); 
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    SocketUdpIdx =SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx);
    PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
    /* Check if trigger transmit is enabled so that element update is possible. */
    if (SoAd_PduRouteCfgIsIfTriggerTxEnabled(PduRouteIdx) == TRUE)
    {
        for(NPduUdpTxQueueIdx = SoAd_NPduUdpTxCfgGetNPduUdpTxQueueStartIdx(NPduUdpTxIdx);
            NPduUdpTxQueueIdx < (SoAd_NPduUdpTxCfgGetNPduUdpTxQueueStartIdx(NPduUdpTxIdx) + 
                                 SoAd_NPduUdpTxCtrlGetNPduLevel(NPduUdpTxIdx));NPduUdpTxQueueIdx++)
        {
            /* if the Queue contins the PduRouteDestIdx */
            if (SoAd_SoConTxPduCtrlGetPduRouteDestIdx(NPduUdpTxQueueIdx) == PduRouteDestIdx)
            {
                /* Update element. */ 
                SoAd_NPduUdpTxCtrlSetTotalLength(NPduUdpTxIdx,
                   SoAd_NPduUdpTxCtrlGetTotalLength(NPduUdpTxIdx)-SoAd_TcpTxQueueDataCtrlGetLength(NPduUdpTxQueueIdx));
                SoAd_TcpTxQueueDataCtrlSetLength(NPduUdpTxQueueIdx,DataLen); 
                SoAd_NPduUdpTxCtrlSetTotalLength(NPduUdpTxIdx,SoAd_NPduUdpTxCtrlGetTotalLength(NPduUdpTxIdx)+DataLen);
                *ElementUpdated = TRUE;
            }
            /* Check for overflow */
            if ((SoAd_NPduUdpTxCtrlGetTotalLength(NPduUdpTxIdx)+ DataLen) > 
                 SoAd_SocketUdpCfgGetNPduUdpTxBufferMin(SocketUdpIdx))
            {
                RetVal = SOAD_NPDU_OVFL_UPDATE;
            }
            break;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to add element to the Udp NPdu tx queue
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(SoAd_NPduReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueAddElement
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx,
    SoAd_PduRouteDestIdxType PduRouteDestIdx,
    PduLengthType DataLen,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
)
{
    SoAd_SoConIdType SoConIdx;
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_SocketUdpIdxType SocketUdpIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_NPduReturnType RetVal = SOAD_NPDU_OK;
    SoAd_NPduUdpTxQueueIdxType NPduUdpTxQueueIdx;
    
    SoConIdx = SoAd_NPduUdpTxCfgGetSoConIdx(NPduUdpTxIdx) ;
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
    SocketUdpIdx =SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx);
    
    /* Check if queue is available */
    if ((SoAd_NPduUdpTxCtrlGetNPduLevel(NPduUdpTxIdx) == SoAd_SocketUdpCfgGetNPduUdpTxQueueSize(SocketUdpIdx)) ||
      ((SoAd_NPduUdpTxCtrlGetTotalLength(NPduUdpTxIdx)+DataLen) > SoAd_SocketUdpCfgGetNPduUdpTxBufferMin(SocketUdpIdx)))
    {
        RetVal = SOAD_NPDU_OVFL_NEW;
    }
  
    if (RetVal == SOAD_NPDU_OK)
    {
        NPduUdpTxQueueIdx = SoAd_NPduUdpTxCfgGetNPduUdpTxQueueStartIdx(NPduUdpTxIdx)+
                                                        SoAd_NPduUdpTxCtrlGetNPduLevel(NPduUdpTxIdx);
        /* Store element in queue */
        SoAd_NPduUdpTxQueueCtrlSetIsCopiedToTxBuffer(NPduUdpTxQueueIdx,FALSE);
        SoAd_TcpTxQueueDataCtrlSetLength(NPduUdpTxQueueIdx,DataLen);
        SoAd_SoConTxPduCtrlSetPduRouteDestIdx(NPduUdpTxQueueIdx,PduRouteDestIdx);
        SoAd_NPduUdpTxCtrlIncNPduLevel(NPduUdpTxQueueIdx);
        /* Store the data */
        if (SoAd_PduRouteCfgIsIfTriggerTxEnabled(PduRouteIdx) == FALSE)
        {
            SoAd_NPduUdpTxQueueCtrlSetNPduUdpTxBufferIdx(NPduUdpTxQueueIdx,
             SoAd_NPduUdpTxCfgGetNPduUdpTxBufferStartIdx(NPduUdpTxIdx)+SoAd_NPduUdpTxCtrlGetBufferLength(NPduUdpTxIdx));
            (void)SoAd_TxNPduUdpBufferAddElement(PduRouteIdx, PduRouteDestIdx, PduInfoPtr);
        }
        else
        {
            /* Store PDU length only and indicate to call TxConfirmation */
            SoAd_NPduUdpTxCtrlSetTotalLength(NPduUdpTxIdx,SoAd_NPduUdpTxCtrlGetTotalLength(NPduUdpTxIdx)+DataLen);
            SoAd_PduRouteCtrlIncNumOfPendingTxConf(PduRouteIdx);
        }
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to handle the transmission of the Udp NPdu tx queue
*   @param[in] NPduUdpTxIdx the Udp NPdu tx idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxNPduUdpQueueTransmit(SoAd_NPduUdpTxIdxType NPduUdpTxIdx)
{
    /* prepare npdu Udp */
    if ( SoAd_TxNPduUdpQueuePrepareTransmitSegment(NPduUdpTxIdx) == E_OK )
    {
        /* Transmit nPdu Udp*/
        (void)SoAd_TxNPduUdpQueueTransmitSegment(NPduUdpTxIdx);
    }
}
/********************************************************************************************************************
*   @brief This Api is used to prepare the buffer for the Udp NPdu tx segment transmission
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxNPduUdpQueuePrepareTransmitSegment
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx
)
{
    SoAd_SoConIdType SoConIdx;
    uint16 OverflowNPduLength;
    SoAd_SocketIdxType SocketIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SocketUdpIdxType SocketUdpIdx; 
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx ;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    SoAd_NPduUdpTxTimerIdxType NPduUdpTxTimerIdx;
    
    SoConIdx = SoAd_NPduUdpTxCfgGetSoConIdx(NPduUdpTxIdx);
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConIdx); 
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx); 
    SocketUdpIdx =SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx);
    PduRouteDestIdx = SoAd_SoConCfgGetPduRouteDestStartIdx(SoConIdx); 

    SoAd_EnterCriticalSection();
    /* Check if any tx active on this socket */
    if (SoAd_SocketCtrlGetActiveTxSoCon(SocketIdx) == SoAd_CfgGetNumOfSoCon()) 
    {
        if (SoAd_TxNPduUdpQueueCheckAndSetTransmitState(NPduUdpTxIdx) == E_OK)
        {
            /* set tx active on the socket */
            SoAd_SocketCtrlSetActiveTxSoCon(SocketIdx,SoConIdx);
            /* Use PduRouteDestStartIdx of SoCon as dummy which used to identify API type in CopyTxData */
            SoAd_SoConTxPduCtrlSetPduRouteDestIdx(TxPduCtrlIdx,PduRouteDestIdx); 
            /* set length for SoCon TxPdu */
            if (SoAd_NPduUdpTxCtrlGetTotalLength(NPduUdpTxIdx) >SoAd_SocketUdpCfgGetNPduUdpTxBufferMin(SocketUdpIdx))
            {
                OverflowNPduLength = SoAd_TxNPduUdpQueueGetNPduLengthUpToOverflow(NPduUdpTxIdx);
                SoAd_SoConTxPduCtrlSetTxBytesLen(TxPduCtrlIdx,OverflowNPduLength); 
                SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,OverflowNPduLength); 
                
            }
            else
            {
                SoAd_SoConTxPduCtrlSetTxBytesLen(TxPduCtrlIdx,SoAd_NPduUdpTxCtrlGetTotalLength(NPduUdpTxIdx));
                SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,SoAd_NPduUdpTxCtrlGetTotalLength(NPduUdpTxIdx));
            }
            SoAd_SoConTxPduCtrlSetpBuffer(TxPduCtrlIdx,NULL_PTR); 
            RetVal = E_OK;
        }
        else
        {
            SoAd_TxNPduUdpClear(NPduUdpTxIdx);
        }            
    }
    else
    {
        /* Retry in next main function */
        NPduUdpTxTimerIdx = SoAd_NPduUdpTxCfgGetTxUdpNPduTimerIdx(NPduUdpTxIdx);
        SoAd_CtrlSetTxUdpNPduTimer(NPduUdpTxTimerIdx,1U);
    }
    SoAd_ExitCriticalSection();
    return RetVal;
}
/*******************************************************************************************************************
*   @brief This Api is used to handle the Udp NPdu tx segment transmission
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueTransmitSegment
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx
)
{
    Std_ReturnType RetVal;
    SoAd_SoConIdType SoConIdx;
    SoAd_SocketIdxType  SocketIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_NPduUdpTxTimerIdxType NPduUdpTxTimerIdx;
    
    SoConIdx = SoAd_NPduUdpTxCfgGetSoConIdx(NPduUdpTxIdx);
    SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConIdx);
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx) ;
    RetVal = SoAd_SocketUdpTransmit(SoAd_SoConCfgGetSocketIdx(SoConIdx),
                                    &SoAd_SoConCtrlGetRemoteAddr(SoConIdx),
                                    SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx)); 
    if (RetVal == E_OK)
    {
        /* Finish transmission of nPdu elements. */
        SoAd_TxNPduUdpQueueFinishTransmitSegment(NPduUdpTxIdx);
        /* Reset tx status */
        SoAd_SocketCtrlSetActiveTxSoCon(SocketIdx,SoAd_CfgGetNumOfSoCon());
        SoAd_SoConTxPduCtrlSetPduRouteDestIdx(TxPduCtrlIdx,SoAd_CfgGetNumOfPduRouteDest());
        /* if all npdu send , reset queue level */
        if (SoAd_NPduUdpTxCtrlGetTotalLength(NPduUdpTxIdx) == 0u)
        {
            SoAd_NPduUdpTxCtrlSetNPduLevel(NPduUdpTxIdx,0U);
            SoAd_NPduUdpTxCtrlSetIsTxActive(NPduUdpTxIdx,FALSE);
            /* Clear nPdu buffer. */
            if (SoAd_NPduUdpTxCfgGetNPduUdpTxBufferStartIdx(NPduUdpTxIdx) != 
                SoAd_NPduUdpTxCfgGetNPduUdpTxBufferSize(NPduUdpTxIdx))
            {
                SoAd_NPduUdpTxCtrlSetBufferLength(NPduUdpTxIdx,0U);
            }
            /* Reset timer */
            NPduUdpTxTimerIdx = SoAd_NPduUdpTxCfgGetTxUdpNPduTimerIdx(NPduUdpTxIdx);
            SoAd_CtrlSetTxUdpNPduTimer(NPduUdpTxTimerIdx,1U);
            
        }
        RetVal = E_OK;
    }
    else
    {
        /* Reset Tx status */
        SoAd_SoConTxPduCtrlSetPduRouteDestIdx(TxPduCtrlIdx,SoAd_CfgGetNumOfPduRouteDest());
        SoAd_SocketCtrlSetActiveTxSoCon(SocketIdx,SoAd_CfgGetNumOfSoCon());
        /* Retry in next main function */
        NPduUdpTxTimerIdx = SoAd_NPduUdpTxCfgGetTxUdpNPduTimerIdx(NPduUdpTxIdx);
        SoAd_CtrlSetTxUdpNPduTimer(NPduUdpTxTimerIdx, 1U);
        RetVal = E_NOT_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to handle the transmit completion of the Udp NPdu tx segment
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxNPduUdpQueueFinishTransmitSegment
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx
)
{
    SoAd_NPduUdpTxQueueIdxType NPduUdpTxQueueIdx;
    SoAd_SoConIdType SoConIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    SoAd_PduRouteIdxType     PduRouteIdx;

    SoConIdx = SoAd_NPduUdpTxCfgGetSoConIdx(NPduUdpTxIdx) ;
    
    /* get pdulength that can be support by the queue considering the NPduUdpTxBufferMin */
    for(NPduUdpTxQueueIdx = SoAd_NPduUdpTxCfgGetNPduUdpTxQueueStartIdx(NPduUdpTxIdx);
        NPduUdpTxQueueIdx < (SoAd_NPduUdpTxCfgGetNPduUdpTxQueueStartIdx(NPduUdpTxIdx) + 
                            SoAd_NPduUdpTxCtrlGetNPduLevel(NPduUdpTxIdx)-1U);
        NPduUdpTxQueueIdx++)
    {
        PduRouteDestIdx = SoAd_SoConTxPduCtrlGetPduRouteDestIdx(NPduUdpTxQueueIdx);
        PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
        /* if the Queue contins the PduRouteDestIdx */
        if (PduRouteDestIdx!= SoAd_CfgGetNumOfPduRouteDest())
        {
            /* If data copied to tx buffer */
            if (SoAd_NPduUdpTxQueueCtrlGetIsCopiedToTxBuffer(NPduUdpTxQueueIdx) == TRUE)  
            {
                if (SoAd_PduRouteCfgIsIfTxConfEnabled(PduRouteIdx) == TRUE)
                {
                    SoAd_TxNPduUdpQueueTxConfirmation(SoConIdx, PduRouteIdx, TRUE);
                }
                SoAd_NPduUdpTxCtrlGetTotalLength(NPduUdpTxIdx)-=SoAd_TcpTxQueueDataCtrlGetLength(NPduUdpTxQueueIdx);
                SoAd_SoConTxPduCtrlGetPduRouteDestIdx(NPduUdpTxQueueIdx)=SoAd_CfgGetNumOfPduRoute();
            }
            else
            {
                /* No element found */
                break;
            }
        }
    }
}
/********************************************************************************************************************
*   @brief This Api is used to get the pdu length upto the Udp NPdu tx queue overflow
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(uint16, SOAD_CODE) SoAd_TxNPduUdpQueueGetNPduLengthUpToOverflow
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx
)
{
    SoAd_SoConIdType SoConIdx;
    uint16 OverflowNPduLength=0u;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SocketUdpIdxType SocketUdpIdx;
    SoAd_NPduUdpTxQueueIdxType NPduUdpTxQueueIdx;

    SoConIdx = SoAd_NPduUdpTxCfgGetSoConIdx(NPduUdpTxIdx) ;
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    SocketUdpIdx = SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx);
    /* get pdulength that can be support by the queue considering the NPduUdpTxBufferMin */
    for(NPduUdpTxQueueIdx = SoAd_NPduUdpTxCfgGetNPduUdpTxQueueStartIdx(NPduUdpTxIdx);
        NPduUdpTxQueueIdx < (SoAd_NPduUdpTxCfgGetNPduUdpTxQueueStartIdx(NPduUdpTxIdx) + 
                             SoAd_NPduUdpTxCtrlGetNPduLevel(NPduUdpTxIdx)-1U);NPduUdpTxQueueIdx++)
    {
        if (OverflowNPduLength + SoAd_TcpTxQueueDataCtrlGetLength(NPduUdpTxQueueIdx) > 
                                        SoAd_SocketUdpCfgGetNPduUdpTxBufferMin(SocketUdpIdx))
        {
            break;
        }
        else
        {
            OverflowNPduLength+=SoAd_TcpTxQueueDataCtrlGetLength(NPduUdpTxQueueIdx);
        }
    }
    return OverflowNPduLength;
}
/********************************************************************************************************************
*   @brief This Api is used to clear the pending tx of Udp NPdu tx queue 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxNPduUdpClear(SoAd_NPduUdpTxIdxType NPduUdpTxIdx)
{
    SoAd_SoConIdType SoConIdx;
    SoAd_NPduUdpTxQueueIdxType NPduUdpTxQueueIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    SoAd_PduRouteIdxType PduRouteIdx;
    
    SoConIdx = SoAd_NPduUdpTxCfgGetSoConIdx(NPduUdpTxIdx);
    /* Reset NPduUdpTxIdx status */
    SoAd_NPduUdpTxCtrlSetIsTxActive(NPduUdpTxIdx,FALSE);
    SoAd_NPduUdpTxCtrlSetTotalLength(NPduUdpTxIdx,0u);
    /* Reset Timer */
    SoAd_CtrlSetTxUdpNPduTimer(SoAd_NPduUdpTxCfgGetTxUdpNPduTimerIdx(NPduUdpTxIdx),0U);
    /* clear nPdu queue */
    if (SoAd_NPduUdpTxCfgGetQueueSupport(NPduUdpTxIdx)  != FALSE)
    {
        for(NPduUdpTxQueueIdx = SoAd_NPduUdpTxCfgGetNPduUdpTxQueueStartIdx(NPduUdpTxIdx);
            NPduUdpTxQueueIdx <= SoAd_NPduUdpTxCfgGetNPduUdpTxQueueEndIdx(NPduUdpTxIdx);
            NPduUdpTxQueueIdx++)
        {
            PduRouteDestIdx = SoAd_SoConTxPduCtrlGetPduRouteDestIdx(NPduUdpTxQueueIdx);
            /* if the Queue contins the PduRouteDestIdx */
            if (PduRouteDestIdx!= SoAd_CfgGetNumOfPduRouteDest())
            {
                PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
                SoAd_TxNPduUdpQueueTxConfirmation(SoConIdx, PduRouteIdx, FALSE);
            }
            SoAd_SoConTxPduCtrlSetPduRouteDestIdx(NPduUdpTxQueueIdx,SoAd_CfgGetNumOfPduRouteDest());
            /* Initialize  NPdu UDP Tx Queue Ctrl status */
            SoAd_NPduUdpTxQueueCtrlSetIsCopiedToTxBuffer(NPduUdpTxQueueIdx,FALSE);
            SoAd_NPduUdpTxQueueCtrlSetLength(NPduUdpTxQueueIdx,0U);
            SoAd_NPduUdpTxQueueCtrlSetNPduUdpTxBufferIdx(NPduUdpTxQueueIdx,SoAd_CfgGetNPduUdpTxBufferSize());
            
        }
        SoAd_NPduUdpTxCtrlSetNPduLevel(NPduUdpTxIdx,0u);
    }
    /* Clear nPdu buffer. */
    if (SoAd_NPduUdpTxCfgGetNPduUdpTxBufferStartIdx(NPduUdpTxIdx) != SoAd_CfgGetNPduUdpTxBufferSize())
    {
        SoAd_NPduUdpTxCtrlSetBufferLength(NPduUdpTxIdx,0U); 
    }
}
/********************************************************************************************************************
*   @brief This Api is used to handle the confirmation of the Udp NPdu tx queue 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxNPduUdpQueueTxConfirmation
(
    SoAd_SoConIdType SoConIdx,
    SoAd_PduRouteIdxType PduRouteIdx,
    boolean AllowReconnect
)
{
    boolean NotifyUL=FALSE;
    SoAd_ULIdxType PduRouteULIdx;
    SoAd_UpIfTxConfirmationFuncType UpIfTxConfirmationFunc;
    
    PduRouteULIdx = SoAd_PduRouteCfgGetPduRouteULIdx(PduRouteIdx);
    if (SoAd_PduRouteCfgIsIfTxConfEnabled(PduRouteIdx) == TRUE)
    {
        SoAd_EnterCriticalSection();
        /* Check for pending confirmation,if all confirmation received notify to upper layer */
        if (SoAd_PduRouteCtrlGetNumOfPendingTxConf(PduRouteIdx) > 0U)
        {
            SoAd_PduRouteCtrlDecNumOfPendingTxConf(PduRouteIdx);
            if ((SoAd_PduRouteCtrlGetNumOfPendingTxConf(PduRouteIdx) == 0u) && 
                (SoAd_PduRouteCtrlGetPendingTxConfInMain(PduRouteIdx) == FALSE))
            {
                if(AllowReconnect == TRUE)
                {
                    SoAd_SoConRequestReconnect(SoConIdx);
                }
                NotifyUL=TRUE;
            }
        }
        SoAd_ExitCriticalSection();
        /* notify to upper layer */
        if (NotifyUL == TRUE)
        {
            UpIfTxConfirmationFunc = SoAd_UpperLayerCfgGetUpIfTxConfirmationFunc(PduRouteULIdx);
            if (UpIfTxConfirmationFunc!=NULL_PTR)
            {
                UpIfTxConfirmationFunc(SoAd_PduRouteCfgGetTxConfPduId(PduRouteIdx),E_OK);
            }
        }
    }
}
/********************************************************************************************************************
*   @brief This Api is used to check the Udp NPdu buffer queue and set transmit state if data is present
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueCheckAndSetTransmitState
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx
)
{
    Std_ReturnType RetVal = E_OK;
    /* check for Queue transmission state */
    if (SoAd_NPduUdpTxCtrlGetIsTxActive(NPduUdpTxIdx) == FALSE)
    {
        /* Check for retry count */
        if (SoAd_NPduUdpTxCtrlGetRetryCount(NPduUdpTxIdx) > 0u)
        {
            SoAd_NPduUdpTxCtrlDecRetryCount(NPduUdpTxIdx);
            if (SoAd_NPduUdpTxCtrlGetRetryCount(NPduUdpTxIdx) == 0u)
            {
                RetVal = E_NOT_OK;
            }
        }
    }
    else
    {
        SoAd_NPduUdpTxCtrlSetIsTxActive(NPduUdpTxIdx,TRUE);
        SoAd_NPduUdpTxCtrlSetRetryCount(NPduUdpTxIdx,SOAD_NPDU_UDP_TX_QUEUE_RETRY_CNT);
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to handle the copy tx data of Udp NPdu buffer
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxNPduUdpBufferCopyTxData
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 BufLength
)
{
    uint8 * pLocalBuffer;
    PduLengthType BytesCopied;
    SoAd_SoConIdType SoConIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    
    SoConIdx = SoAd_NPduUdpTxCfgGetSoConIdx(NPduUdpTxIdx);
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx);
    pLocalBuffer = SoAd_CtrlGetPtrToNPduUdpTxBuffer(SoAd_NPduUdpTxCfgGetNPduUdpTxBufferStartIdx(NPduUdpTxIdx));
    
    /* Copy buffer */
    BytesCopied = SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx) - SoAd_SoConTxPduCtrlGetTxBytesPending(TxPduCtrlIdx);
    SoAd_UtilMemCopy(&BufPtr[0],&pLocalBuffer[BytesCopied],BufLength);
    SoAd_SoConTxPduCtrlSetTxBytesPending(TxPduCtrlIdx,(SoAd_SoConTxPduCtrlGetTxBytesPending(TxPduCtrlIdx)-BufLength));
}
/********************************************************************************************************************
*   @brief This Api is used to handle the copy tx data of Udp NPdu queue
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueCopyTxData
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) BufLengthPtr
)
{
    uint16 BytesCopied = 0u;
    uint16 LocalBufferLength;
    SoAd_SoConIdType SoConIdx;
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_SoConTxPduCtrlIdxType TxPduCtrlIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    BufReq_ReturnType RetVal = BUFREQ_E_NOT_OK;
    SoAd_NPduUdpTxQueueIdxType NPduUdpTxQueueIdx;
    
    LocalBufferLength = *BufLengthPtr;
    SoConIdx = SoAd_NPduUdpTxCfgGetSoConIdx(NPduUdpTxIdx) ;
    TxPduCtrlIdx = SoAd_SoConCfgGetSoConTxPduCtrlIdx(SoConIdx);
    
    for(NPduUdpTxQueueIdx = SoAd_NPduUdpTxCfgGetNPduUdpTxQueueStartIdx(NPduUdpTxIdx);
        NPduUdpTxQueueIdx < (SoAd_NPduUdpTxCfgGetNPduUdpTxQueueStartIdx(NPduUdpTxIdx) + 
                            SoAd_NPduUdpTxCtrlGetNPduLevel(NPduUdpTxIdx));NPduUdpTxQueueIdx++)
    {
        PduRouteDestIdx = SoAd_SoConTxPduCtrlGetPduRouteDestIdx(NPduUdpTxQueueIdx);
        /* if the Queue contains the PduRouteDestIdx */
        if (PduRouteDestIdx!= SoAd_CfgGetNumOfPduRouteDest())
        {
            PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
            if (SoAd_PduRouteCfgIsIfTriggerTxEnabled(PduRouteIdx) == FALSE)
            {
                RetVal = SoAd_TxNPduUdpQueueCopyTxDataBuffer(NPduUdpTxQueueIdx,&BufPtr[BytesCopied],&LocalBufferLength);
            }
            else
            {
                RetVal = SoAd_TxNPduUdpQueueCopyTxDataTrigger(NPduUdpTxIdx,NPduUdpTxQueueIdx,
                                                                &BufPtr[BytesCopied],&LocalBufferLength);
            }
            if ( RetVal == BUFREQ_OK )
            {
                /* if it is successfully copied to provided buffer, set the IsCopiedToTxBuffer to TRUE  */
                BytesCopied = *BufLengthPtr - LocalBufferLength;
                SoAd_NPduUdpTxQueueCtrlSetIsCopiedToTxBuffer(NPduUdpTxQueueIdx,TRUE);
            }
            else
            {
                if ((RetVal == BUFREQ_E_OVFL) && (LocalBufferLength < *BufLengthPtr))
                {
                    /* if buffer size of provided buffer is not sufficient, indicating  an element is copied. */
                    RetVal = BUFREQ_OK;
                }
                break;
            }
        }
    }
    /* Update BytesCopied */
    *BufLengthPtr = BytesCopied;
    SoAd_SoConTxPduCtrlSetTxBytesLen(TxPduCtrlIdx,
                                     (SoAd_SoConTxPduCtrlGetTxBytesLen(TxPduCtrlIdx)-BytesCopied));
    return RetVal;
}

/********************************************************************************************************************
*   @brief This Api is used to handle the copy tx data of Udp NPdu buffer
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueCopyTxDataBuffer
(
    SoAd_NPduUdpTxQueueIdxType NPduUdpTxQueueIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) BufLengthPtr
)
{
    uint8 *pLocalBuffer;
    BufReq_ReturnType RetVal = BUFREQ_E_OVFL;
    
    if (*BufLengthPtr >= SoAd_TcpTxQueueDataCtrlGetLength(NPduUdpTxQueueIdx))
    {
        /* copy data */ 
        pLocalBuffer=SoAd_CtrlGetPtrToNPduUdpTxBuffer(SoAd_NPduUdpTxQueueCtrlGetNPduUdpTxBufferIdx(NPduUdpTxQueueIdx));
        SoAd_UtilMemCopy(&BufPtr[0],pLocalBuffer,SoAd_TcpTxQueueDataCtrlGetLength(NPduUdpTxQueueIdx)); 
        *BufLengthPtr -= SoAd_TcpTxQueueDataCtrlGetLength(NPduUdpTxQueueIdx);
        RetVal = BUFREQ_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to handle for trigger transmit of copy tx data of Udp NPdu queue
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueCopyTxDataTrigger
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx,
    SoAd_NPduUdpTxQueueIdxType NPduUdpTxQueueIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) BufLengthPtr
)
{
    BufReq_ReturnType RetVal;
    SoAd_SoConIdType SoConIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    PduInfoType PduInfo={NULL_PTR,0u};
    
    SoConIdx = SoAd_NPduUdpTxCfgGetSoConIdx(NPduUdpTxIdx) ;
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    /* Prepare buffer to copy data via trigger transmit. */
    RetVal = SoAd_TxNPduUdpQueueCopyTxDataTriggerPrepare(NPduUdpTxIdx,BufPtr,*BufLengthPtr,&PduInfo);
    if (RetVal == BUFREQ_OK)
    {
        /* Copy data */
        if ((SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE) ||
            ((SoAd_TcpTxQueueDataCtrlGetLength(NPduUdpTxQueueIdx) - SOAD_PDU_HEADER_SIZE) != 0U))
        {
            RetVal = SoAd_TxNPduUdpQueueCopyTxDataTriggerCall(NPduUdpTxIdx, NPduUdpTxQueueIdx, BufLengthPtr, &PduInfo);
        }
        
        if ((RetVal == BUFREQ_OK) && 
            (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE))
        {
            /* Copy pdu header data */
            SoAd_TxNPduUdpQueueCopyTxDataTriggerAddPduHeader(NPduUdpTxQueueIdx, BufPtr, BufLengthPtr, &PduInfo);     
        }
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to prepare for trigger transmit call of copy tx data of Udp NPdu queue
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueCopyTxDataTriggerPrepare
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 BufLength,
    P2VAR(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
)
{
    BufReq_ReturnType RetVal;
    SoAd_SoConIdType SoConIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    
    SoConIdx = SoAd_NPduUdpTxCfgGetSoConIdx(NPduUdpTxIdx);
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    if (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
    {
        /* update pdu header length */
        if (BufLength >= SOAD_PDU_HEADER_SIZE )
        {
            PduInfoPtr->SduDataPtr = &BufPtr[SOAD_PDU_HEADER_SIZE];
            PduInfoPtr->SduLength = (PduLengthType)(BufLength - SOAD_PDU_HEADER_SIZE);
            RetVal = BUFREQ_OK;
        }
        else
        {
            RetVal = BUFREQ_E_OVFL;
        }
    }
    else
    {
        PduInfoPtr->SduDataPtr = BufPtr;
        PduInfoPtr->SduLength = (PduLengthType)BufLength;
        RetVal = BUFREQ_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to handle the trigger transmit call for copy tx data of Udp NPdu queue
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_TxNPduUdpQueueCopyTxDataTriggerCall
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx,
    SoAd_NPduUdpTxQueueIdxType NPduUdpTxQueueIdx,
    P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) BufLengthPtr,
    P2VAR(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
)
{
    SoAd_SoConIdType SoConIdx;
    PduLengthType ExpectedLength;
    SoAd_ULIdxType PduRouteULIdx;
    SoAd_PduRouteIdxType PduRouteIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_PduRouteDestIdxType PduRouteDestIdx;
    BufReq_ReturnType RetVal = BUFREQ_E_NOT_OK;
    SoAd_UpIfTriggerTransmitFuncType pUpIfTriggerTransmitFunc;
    
    SoConIdx = SoAd_NPduUdpTxCfgGetSoConIdx(NPduUdpTxIdx) ;
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    PduRouteDestIdx = SoAd_SoConTxPduCtrlGetPduRouteDestIdx(NPduUdpTxQueueIdx);
    PduRouteIdx = SoAd_PduRouteDestCfgGetPduRouteIdx(PduRouteDestIdx);
    PduRouteULIdx = SoAd_PduRouteCfgGetPduRouteULIdx(PduRouteIdx);
    pUpIfTriggerTransmitFunc = SoAd_UpperLayerCfgGetUpIfTriggerTransmitFunc(PduRouteULIdx);
    
    if (pUpIfTriggerTransmitFunc!=NULL_PTR)
    {
        /* Copy data via trigger transmit */
        if (pUpIfTriggerTransmitFunc(SoAd_PduRouteCfgGetTxConfPduId(PduRouteIdx),PduInfoPtr) == E_OK)
        {
            if (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
            {
                ExpectedLength = SoAd_TcpTxQueueDataCtrlGetLength(NPduUdpTxQueueIdx)-SOAD_PDU_HEADER_SIZE;
            }
            else
            {
                ExpectedLength = SoAd_TcpTxQueueDataCtrlGetLength(NPduUdpTxQueueIdx);
            }
            /* If header data copied */
            if (PduInfoPtr->SduLength == ExpectedLength)
            {
                RetVal = BUFREQ_OK;
                *BufLengthPtr -= (uint16)PduInfoPtr->SduLength;
            }
        }
        else
        {
            RetVal = BUFREQ_E_OVFL;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to handle the trigger transmit of pdu header for Udp NPdu queue
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxNPduUdpQueueCopyTxDataTriggerAddPduHeader
(
    SoAd_NPduUdpTxQueueIdxType NPduUdpTxQueueIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) BufLengthPtr,
    P2CONST(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
)
{
    SoAd_PduRouteDestIdxType PduRouteDestIdx;

    PduRouteDestIdx = SoAd_SoConTxPduCtrlGetPduRouteDestIdx(NPduUdpTxQueueIdx);
    /* Copy PDU header of PduRouteDest to provided buffer. */
    SoAd_UtilCopyPduHdr2Buf(SoAd_PduRouteDestCfgGetTxPduHeaderId(PduRouteDestIdx) ,PduInfoPtr->SduLength,
                            BufPtr,0u,SOAD_PDU_HEADER_SIZE);
    /* update buffer length */
    *BufLengthPtr -= SOAD_PDU_HEADER_SIZE;
}
/********************************************************************************************************************
*   @brief This Api is used to handle the copy data for the the Udp NPdu of the SoCon idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_TxNPduUdpCopyTxData
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) BufLengthPtr
)
{
    BufReq_ReturnType RetVal;
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx;
    
    NPduUdpTxIdx = SoAd_SoConCfgGetNPduUdpTxIdx(SoConIdx);   
    if (SoAd_NPduUdpTxCfgGetQueueSupport(NPduUdpTxIdx) == TRUE)
    {
        RetVal = SoAd_TxNPduUdpQueueCopyTxData(NPduUdpTxIdx, BufPtr, BufLengthPtr);
    }
    else
    {
        SoAd_TxNPduUdpBufferCopyTxData(NPduUdpTxIdx, BufPtr, *BufLengthPtr);
        RetVal=BUFREQ_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief This Api is used to handle the transmission of the Udp NPdu for the Udp NPdu idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TxNPduUdpTransmit
(
    SoAd_NPduUdpTxIdxType NPduUdpTxIdx
)
{
    /* Restart tx on timer expiry */
    if (SoAd_NPduUdpTxCtrlGetIsTxActive(NPduUdpTxIdx) == FALSE)
    {
        SoAd_NPduUdpTxCtrlSetIsTxActive(NPduUdpTxIdx,TRUE);
        if (SoAd_NPduUdpTxCfgGetQueueSupport(NPduUdpTxIdx) == TRUE)
        {
            SoAd_NPduUdpTxCtrlSetRetryCount(NPduUdpTxIdx,SOAD_NPDU_UDP_TX_QUEUE_RETRY_CNT);
        }
    }
    
    if (SoAd_NPduUdpTxCfgGetQueueSupport(NPduUdpTxIdx) == TRUE)
    {
        /* process Queue transmit */
        SoAd_TxNPduUdpQueueTransmit(NPduUdpTxIdx);
    }
    else
    {
        /* process npdu buffer transmit */
        SoAd_TxNPduUdpBufferSend(NPduUdpTxIdx);
    }
}
#define SOAD_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
/*******************************************************************************************************************
*   For each change to this file, be sure to record:                                                               *
*      1.  who made the change and when the change was made                                                        *
*      2.  why the change was made and the intended result                                                         *
*   Following block needs to be repeated for each change                                                           *
*******************************************************************************************************************/
/*!*****************************************************************************************************************
*  @date    26-Oct-2023
*  @version 1.0.0
*  @author  pchinnat
*  @brief   Traceability - AUTOSAR 4.3 version initial implementation 
*******************************************************************************************************************/

