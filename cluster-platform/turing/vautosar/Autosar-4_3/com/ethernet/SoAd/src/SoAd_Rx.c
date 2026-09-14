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
*   @file SoAd_Rx.c
*   @ingroup SoAd
*   @brief The main purpose of the SoAd_Rx is to implement the receive functionality of the SoAd module.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "SoAd.h"
#include "SoAd_Internal.h"
#include "SoAd_Lcfg.h"
#include "SchM_SoAd.h"
#include "SoAd_Rx.h"
#include "SoAd_Tx.h"
#include "SoAd_Socket.h"
#if (SOAD_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
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
/*!******************************************************************************************************************
* @brief The Api is used to extract the pdu header id from the buffer 
* @param[in] pBuffer pointer to the buffer
* @return extracted header id
********************************************************************************************************************/
SoAd_PduHeaderIdType SoAd_UtilExtractPduHeaderId(P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) pBuffer);
/*!******************************************************************************************************************
* @brief The Api is used to extract the Pdu header length from the buffer
* @param[in] pBuffer pointer to the buffer
* @return extracted header length
********************************************************************************************************************/
SoAd_PduHeaderLenType SoAd_UtilExtractPduHeaderLength(P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) pBuffer);
/*!******************************************************************************************************************
* @brief The Api is used to get the best matched SoConIdx for the received remode addr
* @param[in] RemoteAddrPtr pointer to the the received remote addr  
* @param[in] BufPtr pointer to the data buffer
* @param[in] Length received data length 
* @param[out] SoConIdxPtr pointer to update the best match SoCon Idx 
* @return status of the request E_OK: SoCon Idx found E_NOT_OK: SoCon Idx not found 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxGetBestMactchSoConIdx
(
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemoteAddrPtr,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length,
    P2VAR(SoAd_SoConIdType, AUTOMATIC, SOAD_APPL_DATA) SoConIdxPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to get the best matched SoConIdx using the best match algo for the received remode addr
* @param[in] RemoteAddrPtr pointer to the the received remote addr  
* @param[in] BufPtr pointer to the data buffer
* @param[in] Length received data length 
* @param[out] SoConIdxPtr pointer to update the best match SoCon Idx 
* @return status of the request E_OK: SoCon Idx found E_NOT_OK: SoCon Idx not found 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxGetSoConIdxByBestMatchAlgo
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemoteAddrPtr,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length,
    P2VAR(SoAd_SoConIdType, AUTOMATIC, SOAD_APPL_DATA) SoConIdxPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to get the socket route idx by the pdu header 
* @param[in] SoConIdx the socket connection idx
* @param[in] BufPtr pointer the data buffer
* @param[out] SockRouteIdxPtr pointer to update the socket route Idx
* @return status of the request E_OK: socket route Idx found E_NOT_OK: socket route Idx not found 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxGetSocketRouteIdxByPduHeader
(
  SoAd_SoConIdType SoConIdx,
  P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
  P2VAR(SoAd_SocketRouteIdxType, AUTOMATIC, SOAD_APPL_VAR) SockRouteIdxPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to notify SoAd about the reception of protocol message 
* @param[in] SoConIdx the socket connection idx
* @param[in] BufPtr pointer the data buffer
* @param[in] Length length of the data buffer
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxIndicationProtocol
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
);
/*!******************************************************************************************************************
* @brief The Api is used to indicate the reception of Udp pdu header
* @param[in] SoConIdx the socket connection idx
* @param[in] BufPtr pointer the data buffer
* @param[in] Length length of the data buffer
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxUdpPduHdrRxIndication
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
);
/*!******************************************************************************************************************
* @brief The Api is used to check the all pdu header length of the Udp message
* @param[in] SoConIdx the socket connection idx
* @param[in] BufPtr pointer the data buffer
* @param[in] Length length of the data buffer
* @return status of the length check E_OK: valid length E_NOT_OK: Invalid length
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxUdpPduHdrCheckAllHeaderLength
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
);
/*!******************************************************************************************************************
* @brief The Api is used to check the pdu header length 
* @param[in] SoConIdx the socket connection idx
* @param[in] BufPtr pointer the data buffer
* @param[in] Length length of the data buffer
* @param[in] ReadDataLen offset in which the pdu header starts
* @param[out] PduHdrLenPtr pointer to update the pdu header length
* @return status of the length check E_OK: valid length E_NOT_OK: Invalid length
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxUdpPduHdrCheckHeaderLength
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length,
    uint16 ReadDataLen,
    P2VAR(SoAd_PduHeaderLenType, AUTOMATIC, SOAD_APPL_VAR) PduHdrLenPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to process the data of the pdu header
* @param[in] SoConIdx the socket connection idx
* @param[in] SocketRouteIdx the socket route idx
* @param[in] BufPtr pointer the data buffer
* @param[in] PduHeaderLength the pdu header length
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxUdpPduHdrReceiveData
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SocketRouteIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    SoAd_PduHeaderLenType PduHeaderLength
);
/*!******************************************************************************************************************
* @brief The Api is used to forward the received Pdu header
* @param[in] SoConIdx the socket connection idx
* @param[in] SocketRouteIdx the socket route idx
* @param[in] PduHeaderLength the pdu header length
* @param[in] BufPtr pointer the data buffer
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxIfUdpPduHdrForwardPdu
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SocketRouteIdx,
    SoAd_PduHeaderLenType PduHeaderLength,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to add meta data to the received pdu info
* @param[in] SoConIdx the socket connection idx
* @param[in] SocketRouteIdx the socket route idx
* @param[in,out] PduInfoPtr pointer to pduinfo for adding meta data
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxIfAddMetaDataToPdu
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SocketRouteIdx,
    P2VAR(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to process the Udp Rx Tp start of reception
* @param[in] SoConIdx the socket connection idx
* @param[in] SocketRouteIdx the socket route idx
* @param[in] PduHdrLen the pdu header length
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTpUdpPduHdrStartOfReception
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SocketRouteIdx,
    SoAd_PduHeaderLenType PduHdrLen
);
/*!******************************************************************************************************************
* @brief The Api is used to copy and process the Udp Tp Pdu header data 
* @param[in] SoConIdx the socket connection idx
* @param[in] SocketRouteIdx the socket route idx
* @param[in] BufPtr pointer to data buffer
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpUdpPduHdrCopyRxData
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SocketRouteIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to copy Udp Tp Pdu header data to the local buffer .
* @param[in] SoConIdx the socket connection idx
* @param[in] SocketRouteIdx the socket route idx
* @param[in] BufPtr pointer to data buffer
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpUdpPduHdrCopyDataToBuffer
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SocketRouteIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to check whether the routing group is enabled for the socket route dest idx
* @param SocketRouteDestIdx the socket route dest idx
* @return routing group status TRUE: if routing group enabled FALSE: if routing group disabled
********************************************************************************************************************/
boolean SoAd_CheckRoutingGroupSocketDestEnabled(SoAd_SocketRouteDestIdxType SocketRouteDestIdx);
/*!******************************************************************************************************************
* @brief The Api is used to indicate the Udp reception
* @param[in] SoConIdx the socket connection idx
* @param[in] BufPtr the pointer ot data buffer
* @param[in] Length the buffer length
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxUdpRxIndication
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
);
/*!******************************************************************************************************************
* @brief The Api is used to process the received If Udp pdu
* @param[in] SocketRouteIdx the socket route idx
* @param[in] BufPtr the pointer ot data buffer
* @param[in] Length the buffer length
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxIfUdpReceivePdu
(
    SoAd_SocketRouteIdxType SocketRouteIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
);
/*!******************************************************************************************************************
* @brief The Api is used to process the received Tp Udp pdu
* @param[in] SocketRouteIdx the socket route idx
* @param[in] BufPtr the pointer ot data buffer
* @param[in] Length the buffer length 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpUdpReceivePdu
(
    SoAd_SocketRouteIdxType SocketRouteIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
);
/*!******************************************************************************************************************
* @brief The Api is used to forward the the received Tp Udp pdu
* @param[in] SocketRouteIdx the socket route idx
* @param[in] BufPtr the pointer ot data buffer
* @param[in] Length the buffer length 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpUdpForwardPdu
(
    SoAd_SocketRouteIdxType SocketRouteIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
);
/*!******************************************************************************************************************
* @brief The Api is used to indicate the received tcp pdu header
* @param[in] SoConIdx the socket conncetion idx
* @param[in] BufPtr the pointer ot data buffer
* @param[in] Length the buffer length 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTcpPduHdrRxIndication
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
);
/*!******************************************************************************************************************
* @brief The Api is used to write the received data to the segment buffer
* @param[in] SoConIdx the socket conncetion idx
* @param[in] SrcBufPtr the pointer ot data buffer
* @param[in] SrcBufLen the buffer length 
* @return status of the request E_OK:request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxBufStructWriteSegment
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) SrcBufPtr,
    uint16 SrcBufLen
);
/*!******************************************************************************************************************
* @brief The Api is used to write the received data to the additional segment buffer
* @param[in] SoConIdx the socket conncetion idx
* @param[in] SrcBufPtr the pointer ot data buffer
* @param[in] SrcBufLen the buffer length 
* @return status of the request E_OK:request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxBufStructWriteAdditionalSegment
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) SrcBufPtr,
    uint16 SrcBufLen
);
/*!******************************************************************************************************************
* @brief The Api is used to calculate the next segment size
* @param[in] RxBufferSegIdx the current buffer segment idx
* @param[in] SegmentDataIdx  the current segment data idx
* @param[in] SegmentLvl the current segment level
* @return SoAd_RxBufferSegDataSizeType next segment size 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(SoAd_RxBufferSegDataSizeType, SOAD_CODE) SoAd_RxBufStructCalculateNextSegment
(
    SoAd_RxBufferSegIdxType RxBufferSegIdx,
    SoAd_RxBufferSegDataSizeType SegmentDataIdx,
    SoAd_RxBufferSegLevelType SegmentLvl
);
/*!******************************************************************************************************************
* @brief The Api is used to get the total length of the buffer
* @param[in] SoConIdx the socket connection idx
* @param[in] BufSegOffset the buffer segment offset 
* @return length of the buffer 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(uint32, SOAD_CODE) SoAd_RxBufStructGetTotLen
(
    SoAd_SoConIdType SoConIdx,
    SoAd_RxBufferSegDataSizeType BufSegOffset
);
/*!******************************************************************************************************************
* @brief The Api is used to process the received tcp pdu header
* @param[in] SoConIdx the socekt connection idx
* @param[out] ReleaseBufLenPtr pointer to update the processed data length
* @param[in] TotalLen total length of the received data
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTcpPduHdrReceiveHeader
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) ReleaseBufLenPtr,
    uint32 TotalLen
);
/*!******************************************************************************************************************
* @brief The Api is used to copy the received data to the local buffer
* @param[in] SoConIdx the socket connection idx
* @param[out] BufPtr the pointer to copy the buffer
* @param[in] BufLen the buffer length to be copied
* @param[in] BufSegOffset the offset length to be released
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxBufStructCopy2Buf
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint8, SOAD_APPL_DATA, SOAD_APPL_DATA) BufPtr,
    uint32 BufLen, 
    uint32 BufSegOffset 
);
/*!******************************************************************************************************************
* @brief The Api is used to process the received Tcp pdu header  
* @param[in] SoConIdx the socket connection idx
* @param[out] ReleaseBufLenPtr the pointer to update the release data buffer length
* @param[in] TotalLen the buffer length 
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTcpPduHdrReceivePdu
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) ReleaseBufLenPtr,
    uint32 TotalLen
);
/*!******************************************************************************************************************
* @brief The Api is used to get the buffer segment data idx
* @param[in] SoConIdx the socket connection idx 
* @param[out] OffsetPtr the pointer to update the offset
* @param[out] RxBufferSegDataIdxPtr the pointer to update the segment data idx
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxBufStructGetBufSegIdx
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) OffsetPtr,
    P2VAR(SoAd_RxBufferSegDataSizeType, AUTOMATIC, SOAD_APPL_VAR) RxBufferSegDataIdxPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to request the release of the rx buffer segment
* @param[in] SoConIdx the socket connection idx 
* @param[in] Len length of the data to be released
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxBufStructReleaseSegment
(
    SoAd_SoConIdType SoConIdx,
    uint32 Len
);
/*!******************************************************************************************************************
* @brief The Api is used to find the socket routed for the received tcp pdu header
* @param[in] SoConIdx the socket connection idx 
* @param[in] PduHdrBufPtr pointer to the pdu header buffer 
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTcpPduHdrFindSocketRoute
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_DATA) PduHdrBufPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to process the received Tcp If pdu header
* @param[in] SoConIdx the socket connection idx 
* @param[in] SockRouteIdx the socket route idx 
* @param[in] PduHdrBufPtr pointer to the pdu header buffer 
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxIfTcpPduHdrReceiveHeader
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SockRouteIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_DATA) PduHdrBufPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to process the received Tcp Tp pdu header
* @param[in] SoConIdx the socket connection idx 
* @param[in] SockRouteIdx the socket route idx 
* @param[in] PduHdrBufPtr pointer to the pdu header buffer 
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpTcpPduHdrReceiveHeader
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SockRouteIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_DATA) PduHdrBufPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to process the received tcp pdu header data
* @param[in] SoConIdx the socket connection idx 
* @param[out] ReleaseBufLenPtr the pointer to update the release buffer length
* @param[in] TotalLen total length of the received msg 
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTcpPduHdrReceiveData
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) ReleaseBufLenPtr,
    uint32 TotalLen
);
/*!******************************************************************************************************************
* @brief The Api is used to copy the data of the received If tcp pdu header
* @param[in] SoConIdx the socket connection idx 
* @param[out] ReleaseBufLenPtr the pointer to update the release buffer length
* @param[in] TotalLen total length of the received msg 
* @param[out] PduInfoPtr total length of the received msg 
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxIfTcpPduHdrCopyData
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) ReleaseBufLenPtr,
    uint32 TotalLen,
    P2VAR(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to get segment for the received msg
* @param[in] SoConIdx the socket connection idx 
* @param[in] BufSegOffset the buffer segment offset
* @param[out] BufSegPtr pointer to the buffer segment 
* @param[out] BufSegLenPtr pointer to buffer segment length
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxBufStructGetSegment
(
    SoAd_SoConIdType SoConIdx,
    uint32 BufSegOffset,
    P2VAR(uint8*, AUTOMATIC, SOAD_APPL_VAR) BufSegPtr,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) BufSegLenPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to forward the received If tcp header
* @param[in] SoConIdx the socket connection idx 
* @param[out] PduInfoPtr the pointer to the pdu info
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxIfTcpPduHdrForwardPdu
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to forward the received Tp tcp header
* @param[in] SoConIdx the socket connection idx 
* @param[out] ReleaseBufLenPtr the pointer to the release buffer length
* @param[in] TotalLen the total length of the received data
* @return status of the request E_OK:request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTpTcpPduHdrForwardPdu
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) ReleaseBufLenPtr,
    uint32 TotalLen
);
/*!******************************************************************************************************************
* @brief The Api is used to indicate the Tcp Tp start of reception for pdu header
* @param[in] SoConIdx the socket connection idx
* @param[in] PduHdrLen  the pdu header length 
* @return status of the request E_OK:request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTpTcpPduHdrStartOfReception
(
    SoAd_SoConIdType SoConIdx,
    SoAd_PduHeaderLenType PduHdrLen
);
/*!******************************************************************************************************************
* @brief The Api is used to indicate the Tcp Tp copy data for pdu header
* @param[in] SoConIdx the socket connection idx
* @param[out] ReleaseBufLenPtr the pointer to the release buffer length
* @return status of the request E_OK:request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTpTcpPduHdrCopyRxData
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) ReleaseBufLenPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to process and notify the Tcp Tp copy data for pdu header to upper layer
* @param[in] SoConIdx the socket connection idx
* @param[out] ReleaseBufLenPtr the pointer to the release buffer length
* @param[out] PduInfoPtr the pointer to the pdu info
* @return status of the request E_OK:request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTpTcpPduHdrCopyRxDataCall
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) ReleaseBufLenPtr,
    P2VAR(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to indicate the received Tcp data
* @param[in] SoConIdx the socket connection idx
* @param[in] BufPtr the pointer to the buffer
* @param[in] Length the length of the buffer
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTcpRxIndication
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
);
/*!******************************************************************************************************************
* @brief The Api is used to process the received Tcp If Pdu
* @param[in] SoConIdx the socket connection idx
* @param[in] SocketRouteIdx the socket route idx
* @param[in] BufPtr the pointer to the buffer
* @param[in] Length the length of the buffer
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxIfTcpReceivePdu
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SocketRouteIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
);
/*!******************************************************************************************************************
* @brief The Api is used to process the received Tcp Tp Pdu
* @param[in] SoConIdx the socket connection idx
* @param[in] BufPtr the pointer to the buffer
* @param[in] Length the length of the buffer
* @param[out] ReleaseBufLenPtr pointer to the release buffer length 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpTcpReceivePdu
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_DATA) ReleaseBufLenPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to forward the received Tp Tcp pdu
* @param[in] SoConIdx the socket connection idx
* @param[out] ReleaseBufLenPtr pointer to the release buffer length 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpTcpForwardPdu
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_DATA) ReleaseBufLenPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to handle the cancellation of the received Tp data
* @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpHandleCancellation(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
* @brief The Api is used to handle the reception of the Tp data on the udp socket connection
* @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpHandleReceptionOnSoConUdp(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
* @brief The Api is used to handle the reception of the tp data on the udp socket connection for copy data
* @param[in] SoConIdx the socket connection idx
* @param[in] SockRouteIdx the socket route idx
* @param[out] PduInfoPtr the pointer to the Pdu info
* @return TRUE: continue to process the copy data FALSE: stop processing the copy data
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(boolean, SOAD_CODE) SoAd_RxTpHandleReceptionOnSoConUdpCopyRxData
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SockRouteIdx,
    P2VAR(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to handle the reception of tp data on the socket connection idx 
* @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpHandleReceptionOnSoConTcp(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
* @brief The Api is used to handle the reception terminate requset for the socket connection idx
* @param[in] SoConIdx the socket connection idx
* @param[in] NormalClose TRUE: termination called by close request FALSE:termination called by other
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpTerminateReceive(SoAd_SoConIdType SoConIdx,boolean NormalClose);
#define SOAD_STOP_SEC_CODE
#include "MemMap.h"
/********************************************************************************************************************
*  #! PUBLIC FUNCTION IMPLEMENTATION                                                                                *
********************************************************************************************************************/
#define SOAD_START_SEC_CODE
#include "MemMap.h" 
/********************************************************************************************************************
* @brief This Api is used to initialize the rx properties of the SoCon
* @param[in] SoConIdx the socket connection idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_RxInitSoCon(SoAd_SoConIdType SoConIdx)
{
    SoAd_RxIfBufferIdxType RxIfBufferIdx;
    SoAd_RxBufferSegIdxType RxBufferSegIdx;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    SoAd_TpRxBufferIdxType TpRxBufferCfgIdx;
    
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    if (SoAd_SoConCfgIsSocketRouteSupported(SoConIdx) == TRUE)
    {
        /* Reset RxPduCtrlIdx status */
        SoAd_SoConRxPduCtrlSetRxBytesPending(RxPduCtrlIdx,0u);
        SoAd_SoConRxPduCtrlSetSocketRouteIdx(RxPduCtrlIdx,SoAd_CfgGetNumOfSocketRoute());
        SoAd_SoConRxPduCtrlSetCancelRequest(RxPduCtrlIdx,FALSE);
    }
    /* Reset buffe segment */
    RxBufferSegIdx = SoAd_SoConCfgGetRxBufferSegIdx(SoConIdx);
    SoAd_RxBufferSegCtrlSetSegLevel(RxBufferSegIdx,0u);
    SoAd_RxBufferSegCtrlSetSegDataIdx(RxBufferSegIdx,SoAd_RxBufferSegCfgGetSegDataStartIdx(RxBufferSegIdx));
    /* Reset Tp buffer ctrl status */
    TpRxBufferCfgIdx = SoAd_SoConCfgGetTpRxBufferCfgIdx(SoConIdx);
    SoAd_TpRxBufferCtrlSetCurrentBufferIdx(TpRxBufferCfgIdx,SoAd_TpRxBufferCfgGetTpRxBufferStartIdx(TpRxBufferCfgIdx));
    /* Rest If buffer ctrl status */
    RxIfBufferIdx = SoAd_SoConCfgGetRxIfBufferIdx(SoConIdx);
    SoAd_RxIfBufferCtrlSetBufferIdx(RxIfBufferIdx,SoAd_RxIfBufferCfgGetStartIdx(RxIfBufferIdx));
}
/********************************************************************************************************************
* @brief This Api is used to indicate the start of Tp recepetion for the socket connection idx
* @param[in] SoConIdx the socket connection idx
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTpStartOfReception(SoAd_SoConIdType SoConIdx)
{
    PduLengthType BufferSize=0U;
    SoAd_ULIdxType SocketRouteULIdx;
    Std_ReturnType RetVal = E_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SocketRouteIdxType SocketRouteIdx;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    SoAd_UpTpStartOfReceptionFuncType pUpTpStartOfReceptionFunc;
    
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    if ((SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == 0u) && 
        (SoAd_SoConCfgIsSocketRouteSupported(SoConIdx) != 0u))
    {
        SocketRouteIdx = SoAd_SoConCfgGetSocketRouteStartIdx(SoConIdx);
        if (SoAd_SocketRouteCfgGetSocketRouteULType(SocketRouteIdx) == SOAD_UPPER_LAYER_TYPE_TP)
        {
            SocketRouteULIdx = SoAd_SocketRouteCfgGetSocketRouteULIdx(SocketRouteIdx);
            pUpTpStartOfReceptionFunc = SoAd_UpperLayerCfgGetUpTpStartOfReceptionFunc(SocketRouteULIdx);
            /* invoke start of reception */
            if (pUpTpStartOfReceptionFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),NULL_PTR,0u,&BufferSize) == BUFREQ_OK)
            {
                /* set SocketRouteIdx */
                SoAd_SoConRxPduCtrlGetSocketRouteIdx(RxPduCtrlIdx) = SocketRouteIdx;
            }
            else
            {
                /* Reset socket connection  */
                SoAd_SoConSetCloseReq(SoConIdx, SOAD_CLOSE_REQ_OFFLINE_RESET);
                SoAd_SoConCtrlSetSoConEventStateChange(SoConIdx,TRUE);
                RetVal = E_NOT_OK;
            }
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief This Api is used to terminate the pending reception
* @param[in] SoConIdx the socket connection idx
* @param[in] NormalClose TRUE: termination called by close request FALSE:termination called by other
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_RxTerminateReceive(SoAd_SoConIdType SoConIdx,boolean NormalClose)
{
    /* Terminate active TP session. */
    SoAd_RxTpTerminateReceive(SoConIdx, NormalClose);
    /* Initialize rx struct elements. */
    SoAd_RxInitSoCon(SoConIdx);
}
/********************************************************************************************************************
* @brief The TCP/IP stack calls this primitive after the reception of data on a socket. The socket identifier 
* along with configuration information determines which module is to be called.
* @param[in]  SocketId Socket identifier of the related local socket resource.
* @param[in]  RemoteAddrPtr Pointer to memory containing IP address and port of the remote host which sent the data
* @param[in]  BufPtr Pointer to the received data.
* @param[in]  Length Data length of the received TCP segment or UDP datagram.
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_RxIndicationProcessing
( 
    SoAd_SocketIdxType SocketIdx,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_CONST) RemoteAddrPtr,
    P2CONST(uint8,AUTOMATIC,SOAD_APPL_CONST) BufPtr,
    uint16 Length 
)
{
    SoAd_SoConIdType SoConIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    boolean IsRxInd=FALSE; 
    
    SoConIdx = SoAd_SocketCfgGetSoConStartIdx(SocketIdx); 
    SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(SocketIdx);
    LocalAddrIdx = SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx);
    /* Check for valid states */
    if ((SoAd_CtrlGetIpAddrState(LocalAddrIdx)  == SOAD_IPADDR_STATE_ASSIGNED) &&
        (SoAd_SocketCtrlGetSocketState(SocketIdx) == SOAD_SOCK_STATE_ESTABLISHED))
    {
        /* Get SoConIdx for the received message */
        if(SoAd_RxGetBestMactchSoConIdx(RemoteAddrPtr, BufPtr, Length, &SoConIdx) == E_OK)
        {
            /* Check the SoCon for reception */
            if (SoAd_SoConCheckStatesAndOpenSoConOnReception(SoConIdx, RemoteAddrPtr) == E_OK )    
            {
                /* process the received message */
                SoAd_RxIndicationProtocol(SoConIdx, BufPtr, Length);
                IsRxInd = TRUE;
            }            
        }
    }

    if ((IsRxInd == FALSE) && (SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE))
    {
        /* Release buffer if Tcp data not processed */
        SoAd_SocketTcpReceived(SoAd_SoConCfgGetSocketIdx(SoConIdx), Length);
    }
}
/********************************************************************************************************************
* @brief This Api is used to process the reception in the main function
********************************************************************************************************************/
void SoAd_RxMainFunction(void)
{
    SoAd_SoConIdType SoConIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    /* Process Tp Rx */
    for (SoConIdx = 0u; SoConIdx < SoAd_CfgGetNumOfSoCon(); SoConIdx++)
    {
        if(SoAd_SoConCtrlGetSoConEventTpReception(SoConIdx) == TRUE)
        {
            /* if there is no close request */
            if (SoAd_SoConCtrlGetCloseReqType(SoConIdx) == SOAD_CLOSE_REQ_NONE)
            {
                RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
                if (SoAd_SoConRxPduCtrlGetCancelRequest(RxPduCtrlIdx) == TRUE)
                {
                    /* process cancel request */
                    SoAd_RxTpHandleCancellation(SoConIdx);
                }
                else
                {
                    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
                    if (SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE)
                    {
                        /* process pending rx of UDP */
                        SoAd_RxTpHandleReceptionOnSoConUdp(SoConIdx);
                    }
                    else
                    {
                        /* process pending rx of TCP */
                        SoAd_RxTpHandleReceptionOnSoConTcp(SoConIdx); 
                    }
                }
            }   
            SoAd_SoConCtrlSetSoConEventTpReception(SoConIdx,FALSE);
        }
    }
}
/********************************************************************************************************************
* @brief Requests cancellation of an ongoing reception of a PDU in a lower layer transport protocol module.
* @param[in]  RxPduId  Identification of the PDU to be cancelled.
* @return     Std_ReturnType E_OK: Cancellation was executed successfully by the destination module. 
*               E_NOT_OK: Cancellation was rejected by the destination module.
* @ServiceID  0x4c
* @Sync/Async Synchronous
* @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TpCancelReceive(PduIdType RxPduId)
{
    uint8 ErrorId = SOAD_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SocketRouteIdxType SocketRouteIdx;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    SoAd_SoConIdType SoConIdx;
    
    if (SOAD_UNINITIALIZED == SoAd_InitStatus)
    {
        ErrorId = SOAD_E_UNINIT;
    }
    else if (SOAD_NUM_OF_RX_PDU <= RxPduId)
    {
        ErrorId = SOAD_E_INV_ARG;
    }
    else
    {
        SocketRouteIdx = RxPduId;
        if (SoAd_SocketRouteCfgGetSocketRouteULType(SocketRouteIdx) == SOAD_UPPER_LAYER_TYPE_TP)
        {
            SoConIdx = SoAd_SocketRouteCfgGetSoConIdx(SocketRouteIdx);
            RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
            /* Check for Tp tx in progress */
            if (SoAd_SoConRxPduCtrlGetSocketRouteIdx(RxPduCtrlIdx) == SocketRouteIdx)
            {
                /* set cancel request to true */
                SoAd_SoConRxPduCtrlSetCancelRequest(RxPduCtrlIdx,TRUE);
                SoAd_SoConCtrlSetSoConEventTpReception(SoConIdx,TRUE);
                RetVal = E_OK;
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
      SoAd_DetReportError(SOAD_TPCANCELRECEIVE_API, ErrorId);
    }
#else
    SOAD_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal; 
}
/********************************************************************************************************************
*  #! PRIVATE FUNCTION IMPLEMENTATION			                                                                    *
********************************************************************************************************************/
/********************************************************************************************************************
* @brief The Api is used to extract the pdu header id from the buffer 
********************************************************************************************************************/
SoAd_PduHeaderIdType SoAd_UtilExtractPduHeaderId(P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) pBuffer)
{
    SoAd_PduHeaderIdType  RcvdPduHeaderId=0U;
    /* Get Received PDU pdu header id. */
    RcvdPduHeaderId = (SoAd_PduHeaderIdType)pBuffer[3u];
    RcvdPduHeaderId |= ((SoAd_PduHeaderIdType)pBuffer[2u] << 8U);
    RcvdPduHeaderId |= ((SoAd_PduHeaderIdType)pBuffer[1u] << 16U);
    RcvdPduHeaderId |= ((SoAd_PduHeaderIdType)pBuffer[0u] << 24U); 
    return RcvdPduHeaderId;
}
/********************************************************************************************************************
* @brief The Api is used to extract the Pdu header length from the buffer
********************************************************************************************************************/
SoAd_PduHeaderLenType SoAd_UtilExtractPduHeaderLength(P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) pBuffer)
{
    SoAd_PduHeaderLenType  RcvdPduHeaderLength=0U;
    /* Get Received PDU pdu header id. */
    RcvdPduHeaderLength = (SoAd_PduHeaderLenType)pBuffer[SOAD_PDU_HEADER_ID_SIZE+3u];
    RcvdPduHeaderLength |= ((SoAd_PduHeaderLenType)pBuffer[SOAD_PDU_HEADER_ID_SIZE+2u] << 8U);
    RcvdPduHeaderLength |= ((SoAd_PduHeaderLenType)pBuffer[SOAD_PDU_HEADER_ID_SIZE+1u] << 16U);
    RcvdPduHeaderLength |= ((SoAd_PduHeaderLenType)pBuffer[SOAD_PDU_HEADER_ID_SIZE+0u] << 24U); 
    return RcvdPduHeaderLength;
}
/********************************************************************************************************************
* @brief The Api is used to get the best matched SoConIdx for the received remode addr
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxGetBestMactchSoConIdx
(
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemoteAddrPtr,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length,  
    P2VAR(SoAd_SoConIdType, AUTOMATIC, SOAD_APPL_DATA) SoConIdxPtr
)
{
    SoAd_SoConIdType LocalSoConIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;    
    /* Get start SoConIdx from the SocketId */
    LocalSoConIdx = *SoConIdxPtr;
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(LocalSoConIdx);
    if (SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE)
    {
        /* If TCP ,use the first SoConIdx */
        *SoConIdxPtr = LocalSoConIdx;
        RetVal = E_OK;
    }
    else
    {
        /* If msg acceptance filter is enabled, then find the best match SoConIdx else return the first SoConIdx */
        if (SoAd_SoConGrpCfgIsMsgAcceptFilterSupported(SoConGrpIdx) == TRUE)
        {
            if (SoAd_RxGetSoConIdxByBestMatchAlgo(LocalSoConIdx,RemoteAddrPtr,BufPtr,Length,&LocalSoConIdx) == E_OK)
            {
                *SoConIdxPtr = LocalSoConIdx; 
                RetVal = E_OK;
            }
        }
        else
        {
            *SoConIdxPtr = LocalSoConIdx;
            RetVal = E_OK;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to get the best matched SoConIdx using the best match algo for the received remode addr
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxGetSoConIdxByBestMatchAlgo
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemoteAddrPtr,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length,
    P2VAR(SoAd_SoConIdType, AUTOMATIC, SOAD_APPL_DATA) SoConIdxPtr
)
{
    SoAd_SoConIdType  BestMatchSoConIdx=SOAD_NUM_OF_SOCON;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SocketRouteIdxType SocketRouteIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    if (TRUE == SoAd_SoConGetSoConIdxByBestMatchAlgo(SoConGrpIdx,RemoteAddrPtr,&BestMatchSoConIdx))
    {
        /* Check for Pdu header best match option */
        if (SoAd_SoConGrpCfgIsBestMatchByPduHeaderEnabled(SoConGrpIdx) == TRUE)
        {
            if ( Length >= SOAD_PDU_HEADER_SIZE )
            {
                /* If pdu header matches for this BestMatchSoConIdx */
                if (SoAd_RxGetSocketRouteIdxByPduHeader(BestMatchSoConIdx,BufPtr,&SocketRouteIdx) == E_OK)
                {
                    *SoConIdxPtr = BestMatchSoConIdx; 
                    RetVal = E_OK;
                }
            }
        }
        else if (SoAd_SoConGrpCfgIsBestMatchBySocketRouteEnabled(SoConGrpIdx) == TRUE)
        {
            /* If socket route enabled for this BestMatchSoConIdx */
            if (SoAd_SoConCfgIsSocketRouteSupported(BestMatchSoConIdx) == TRUE)
            {
                *SoConIdxPtr = BestMatchSoConIdx; 
                 RetVal = E_OK;
            }
        }
        else
        {
            *SoConIdxPtr = BestMatchSoConIdx;
            RetVal = E_OK;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to get the socket route idx by the pdu header 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxGetSocketRouteIdxByPduHeader
(
  SoAd_SoConIdType SoConIdx,
  P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
  P2VAR(SoAd_SocketRouteIdxType, AUTOMATIC, SOAD_APPL_VAR) SockRouteIdxPtr
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_PduHeaderIdType  RcvdPduHeaderId;
    SoAd_PduHeaderLenType RcvdPduHeaderLength;
    SoAd_SocketRouteIdxType SocketRouteIdx;    
    /* Get Received PDU pdu header id. */
    RcvdPduHeaderId = SoAd_UtilExtractPduHeaderId(BufPtr);
    /* Get Received PDU pdu header Length. */
    RcvdPduHeaderLength = SoAd_UtilExtractPduHeaderLength(BufPtr);
    if (RcvdPduHeaderLength != 0u)
    {
        /* Iterate over all socket routes of the socket connection. */
        for (SocketRouteIdx = SoAd_SoConCfgGetSocketRouteStartIdx(SoConIdx);
             SocketRouteIdx <= SoAd_SoConCfgGetSocketRouteEndIdx(SoConIdx);SocketRouteIdx++)
        {
            if (SoAd_SocketRouteCfgGetRxPduHeaderId(SocketRouteIdx) == RcvdPduHeaderId)
            {
                if(TRUE == SoAd_CheckRoutingGroupSocketDestEnabled(
                            SoAd_SocketRouteCfgGetSocketRouteDestIdx(SocketRouteIdx)))
                {
                    *SockRouteIdxPtr = SocketRouteIdx;
                    RetVal = E_OK;
                    break;
                }
            }
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to notify SoAd about the reception of protocol message 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxIndicationProtocol
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
)
{
    uint16 SkippedLength = 0u;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    if (SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE)
    {
        if (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
        {
            /* process reception on UDP socket connection with PDU header  */
            SoAd_RxUdpPduHdrRxIndication(SoConIdx, BufPtr, Length); 
        }    
        else
        {
            /* process reception on UDP socket connection */
            SoAd_RxUdpRxIndication(SoConIdx, BufPtr, Length);
        }
    }
    else
    {
       /* Skip data if required by a previous erroneous reception. */
        if (SoAd_SocketTcpCheckAndUpdateSkipData(SoAd_SoConCfgGetSocketIdx(SoConIdx),Length,&SkippedLength) == E_OK) 
        {
            if (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
            {
                /* process reception on Tcp socket connection with PDU header  */
                SoAd_RxTcpPduHdrRxIndication(SoConIdx, &BufPtr[SkippedLength], (uint16)(Length - SkippedLength));
            }
            else
            {
                /* process reception on Tcp socket connection */
                SoAd_RxTcpRxIndication(SoConIdx, &BufPtr[SkippedLength], (uint16)(Length - SkippedLength));
            }
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to indicate the reception of Udp pdu header
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxUdpPduHdrRxIndication
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
)
{
    uint16 ReadDataLength=0U;
    SoAd_PduHeaderLenType PduHeaderLength = 0U;
    SoAd_SocketRouteIdxType SocketRouteIdx;
    
    if(SoAd_RxUdpPduHdrCheckAllHeaderLength(SoConIdx, BufPtr, Length) == E_OK)
    {
        /* loop through the received frame and forward the pdus */
        while(Length>ReadDataLength)
        {
            /* Evaluate the Received Header */
            if (SoAd_RxUdpPduHdrCheckHeaderLength(SoConIdx, BufPtr, Length, ReadDataLength,&PduHeaderLength) == E_OK ) 
            {
                /* Evaluate the Received Pdu header */
                if (SoAd_RxGetSocketRouteIdxByPduHeader(SoConIdx, &BufPtr[ReadDataLength], &SocketRouteIdx) == E_OK )
                {
                    SoAd_RxUdpPduHdrReceiveData(SoConIdx, SocketRouteIdx, &BufPtr[ReadDataLength],PduHeaderLength); 
                }
                ReadDataLength += (SOAD_PDU_HEADER_SIZE + PduHeaderLength);
            }
            else
            {
                break;
            }
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to check the all pdu header length of the Udp message
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxUdpPduHdrCheckAllHeaderLength
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
)
{
    uint16 HeaderOffset = 0u;
    Std_ReturnType RetVal = E_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    boolean InvalidDataLength = FALSE;
    SoAd_SocketUdpIdxType SocketUdpIdx;
    SoAd_PduHeaderLenType PduHeaderLength = 0U;
    
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    SocketUdpIdx =SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx);
    /* Check if strict header length check is enabled */
    if (SoAd_SocketUdpCfgGetStrictHeaderLenCheck(SocketUdpIdx) == TRUE)
    {
        /* Loop through all the Header and check its Header length and data length */
        while ((HeaderOffset < Length) && (InvalidDataLength == FALSE))
        {
            if ((Length-HeaderOffset) >= (uint16)SOAD_PDU_HEADER_SIZE)
            {
                /* Get Header length */
                PduHeaderLength = SoAd_UtilExtractPduHeaderLength(BufPtr);
                HeaderOffset+=SOAD_PDU_HEADER_SIZE;
                /* Check Hdeader length */
                if ((uint16)PduHeaderLength > (Length-HeaderOffset))
                {
                    InvalidDataLength = TRUE;
                    RetVal = E_NOT_OK;
                }
                else
                {
                    HeaderOffset+=PduHeaderLength;
                }
            }
            else
            {
                InvalidDataLength = TRUE;
                RetVal = E_NOT_OK;
            }            
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to check the pdu header length 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxUdpPduHdrCheckHeaderLength
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length,
    uint16 ReadDataLen,
    P2VAR(SoAd_PduHeaderLenType, AUTOMATIC, SOAD_APPL_VAR) PduHdrLenPtr
)
{
    Std_ReturnType RetVal =E_NOT_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SocketUdpIdxType SocketUdpIdx;
    SoAd_PduHeaderLenType PduHeaderLength;
    
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    SocketUdpIdx =SoAd_SoConGrpCfgGetSocketUdpIdx(SoConGrpIdx);
    /* Check if strict header length check is disabled */
    if (SoAd_SocketUdpCfgGetStrictHeaderLenCheck(SocketUdpIdx) == FALSE)
    {
        /* Get PduHeaderLength and validate the header and data length */
        if ((Length-ReadDataLen) >= (uint16)SOAD_PDU_HEADER_SIZE)
        {
            PduHeaderLength = SoAd_UtilExtractPduHeaderLength(BufPtr);
            if (PduHeaderLength <= (Length-ReadDataLen-SOAD_PDU_HEADER_SIZE))
            {
                *PduHdrLenPtr = PduHeaderLength;
                RetVal = E_OK;
            }
        }
    }
    else
    {
        /* length check in strict length check, so copy header length */
        *PduHdrLenPtr = SoAd_UtilExtractPduHeaderLength(BufPtr);
        RetVal = E_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to process the data of the pdu header
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxUdpPduHdrReceiveData
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SocketRouteIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    SoAd_PduHeaderLenType PduHeaderLength
)
{   
    if (SoAd_SocketRouteCfgGetSocketRouteULType(SocketRouteIdx) == SOAD_UPPER_LAYER_TYPE_IF)
    {
        /* process If layer Pdu */
        SoAd_RxIfUdpPduHdrForwardPdu(SoConIdx, SocketRouteIdx, PduHeaderLength, BufPtr);
    }
    else
    {
        /* process Tplayer Pdu */
        if (SoAd_RxTpUdpPduHdrStartOfReception(SoConIdx, SocketRouteIdx, PduHeaderLength) == E_OK )
        {
            SoAd_RxTpUdpPduHdrCopyRxData(SoConIdx, SocketRouteIdx, &BufPtr[SOAD_PDU_HEADER_SIZE]); 
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to forward the received Pdu header
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxIfUdpPduHdrForwardPdu
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SocketRouteIdx,
    SoAd_PduHeaderLenType PduHeaderLength,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr
)
{
    PduInfoType PduInfo;
    SoAd_UpIfRxIndicationFuncType pUpIfRxIndicationFunc;
    SoAd_ULIdxType SocketRouteULIdx;
    /* Update PduInfo */
    PduInfo.SduDataPtr = (uint8 *)&BufPtr[SOAD_PDU_HEADER_SIZE];
    PduInfo.SduLength = PduHeaderLength;
    SocketRouteULIdx = SoAd_SocketRouteCfgGetSocketRouteULIdx(SocketRouteIdx);
    pUpIfRxIndicationFunc = SoAd_UpperLayerCfgGetUpIfRxIndicationFunc(SocketRouteULIdx);
    /* Check and Add meta data if configured , then forward to UL */
    if (SoAd_RxIfAddMetaDataToPdu(SoConIdx,SocketRouteIdx,&PduInfo) == E_OK )
    {
        /* Notify to upper layer */
        if (pUpIfRxIndicationFunc != NULL_PTR)
        {
            pUpIfRxIndicationFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),&PduInfo);
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to add meta data to the received pdu info
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxIfAddMetaDataToPdu
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SocketRouteIdx,
    P2VAR(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
)
{
    uint8 * pRxMetaDataBuffer;
    Std_ReturnType RetVal = E_OK;    
    /* If meta data support enabled then process the data */
    if (SoAd_SocketRouteCfgIsRxMetaDataEnabled(SocketRouteIdx) == TRUE)
    {
        if ((PduInfoPtr->SduLength + SOAD_RX_META_DATA_LEN) <= SOAD_RX_META_DATA_BUFFER_SIZE)
        {
            /* Copy data into Rx meta data buffer */
            pRxMetaDataBuffer = SoAd_CtrlGetRxMetaDataBuffer();
            SoAd_UtilMemCopy(pRxMetaDataBuffer,PduInfoPtr->SduDataPtr,PduInfoPtr->SduLength);
            /* Update meta data */
            pRxMetaDataBuffer[PduInfoPtr->SduLength] = (uint8)(SoConIdx >> 8u);
            pRxMetaDataBuffer[PduInfoPtr->SduLength+1u] = (uint8)(SoConIdx);
            /* Update PduInfoPtr with metaData */
            PduInfoPtr->SduDataPtr = pRxMetaDataBuffer;  
            PduInfoPtr->SduLength += SOAD_RX_META_DATA_LEN; 
        }
        else
        {
            RetVal = E_NOT_OK;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to process the Udp Rx Tp start of reception
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTpUdpPduHdrStartOfReception
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SocketRouteIdx,
    SoAd_PduHeaderLenType PduHdrLen
)
{
    PduLengthType BufferSize=0U;
    Std_ReturnType RetVal = 0U;
    SoAd_ULIdxType SocketRouteULIdx;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    SoAd_UpTpStartOfReceptionFuncType pUpTpStartOfReceptionFunc;
    
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    if (SoAd_SoConRxPduCtrlGetSocketRouteIdx(RxPduCtrlIdx) == SoAd_CfgGetNumOfSocketRoute())
    {
        SocketRouteULIdx = SoAd_SocketRouteCfgGetSocketRouteULIdx(SocketRouteIdx);
        pUpTpStartOfReceptionFunc = SoAd_UpperLayerCfgGetUpTpStartOfReceptionFunc(SocketRouteULIdx);
        if (pUpTpStartOfReceptionFunc != NULL_PTR)
        {
            if (BUFREQ_OK == pUpTpStartOfReceptionFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),
                NULL_PTR,PduHdrLen,&BufferSize))
            {
                /* update RxPdu ctrl status */ 
                SoAd_SoConRxPduCtrlSetSocketRouteIdx(RxPduCtrlIdx,SocketRouteIdx);
                SoAd_SoConRxPduCtrlSetRxBytesPending(RxPduCtrlIdx,PduHdrLen);
                RetVal = E_OK;
            }
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to copy and process the Udp Tp Pdu header data 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpUdpPduHdrCopyRxData
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SocketRouteIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr
)
{
    PduInfoType PduInfo;
    Std_ReturnType RetVal=E_OK;
    uint16 ReadDataLen = 0u;
    PduLengthType BufferSize = 0u;
    SoAd_ULIdxType SocketRouteULIdx;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    SoAd_UpTpCopyRxDataFuncType pUpTpCopyRxDataFunc;
    SoAd_UpTpRxIndicationFuncType pUpTpRxIndicationFunc;
    
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    SocketRouteULIdx = SoAd_SocketRouteCfgGetSocketRouteULIdx(SocketRouteIdx);
    pUpTpCopyRxDataFunc = SoAd_UpperLayerCfgGetUpTpCopyRxDataFunc(SocketRouteULIdx);
    pUpTpRxIndicationFunc = SoAd_UpperLayerCfgGetUpTpRxIndicationFunc(SocketRouteULIdx);
    /* first CopyRxData call is called with length 0 to get the available buffer size. */
    PduInfo.SduLength = 0u;
    if ((pUpTpCopyRxDataFunc== NULL_PTR) && (pUpTpRxIndicationFunc== NULL_PTR))
    {
        RetVal = E_NOT_OK;
    }
    
    while((SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx) >0U) && (RetVal == E_OK))
    {
        /* process data if no cancel reqeuest */
        if (SoAd_SoConRxPduCtrlGetCancelRequest(RxPduCtrlIdx) == FALSE)
        {
            /* update Pdu data and length*/
            PduInfo.SduDataPtr = (uint8 *)&BufPtr[ReadDataLen];
            if (PduInfo.SduLength >0U)
            {
                if (PduInfo.SduLength > SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx))
                {
                    PduInfo.SduLength = SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx);
                }
            }
            /* invoke UL copy data */
            if (pUpTpCopyRxDataFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),&PduInfo,&BufferSize) == BUFREQ_OK)
            {
                /* update copied length */
                ReadDataLen+=PduInfo.SduLength;
                SoAd_SoConRxPduCtrlSetRxBytesPending(RxPduCtrlIdx,
                                            (SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx)-PduInfo.SduLength));
                if (SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx) > 0U)
                {
                    if (BufferSize > 0U)
                    {
                        /* If buffer available , try again to copy data */
                        if (BufferSize <= SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx))
                        {
                            PduInfo.SduLength = BufferSize; 
                        }
                        else
                        {
                            PduInfo.SduLength = SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx); 
                        }
                    }
                    else
                    {
                        /* copy to local buffer and retry in mainfunction */
                        SoAd_RxTpUdpPduHdrCopyDataToBuffer(SoConIdx, SocketRouteIdx, 
                                                            &PduInfo.SduDataPtr[PduInfo.SduLength]); 
                        RetVal = E_NOT_OK;
                    }
                }
                else
                {
                    /* All data copied , notify to UL */
                    SoAd_SoConRxPduCtrlSetSocketRouteIdx(RxPduCtrlIdx,SoAd_CfgGetNumOfSocketRoute());
                    pUpTpRxIndicationFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),E_OK);
                }
            }
            else
            {
                /* Data copy failure , reset RxPdu status */
                SoAd_SoConRxPduCtrlSetRxBytesPending(RxPduCtrlIdx,0u);
                SoAd_SoConRxPduCtrlSetSocketRouteIdx(RxPduCtrlIdx,SoAd_CfgGetNumOfSocketRoute());
                pUpTpRxIndicationFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),E_NOT_OK);
            }
        }
        else
        {
            RetVal = E_NOT_OK;
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to copy Udp Tp Pdu header data to the local buffer .
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpUdpPduHdrCopyDataToBuffer
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SocketRouteIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr
)
{
    SoAd_ULIdxType SocketRouteULIdx;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    SoAd_UpTpRxIndicationFuncType pUpTpRxIndicationFunc;
    SoAd_TpRxBufferIdxType TpRxBufferCfgIdx;
    
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    TpRxBufferCfgIdx = SoAd_SoConCfgGetTpRxBufferCfgIdx(SoConIdx);
    SocketRouteULIdx = SoAd_SocketRouteCfgGetSocketRouteULIdx(SocketRouteIdx);
    pUpTpRxIndicationFunc = SoAd_UpperLayerCfgGetUpTpRxIndicationFunc(SocketRouteULIdx);    
    /* If Tp buffer available */
    if (SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx) <= SoAd_TpRxBufferCfgGetTpRxBufferSize(TpRxBufferCfgIdx))
    {
        SoAd_UtilMemCopy(SoAd_CtrlGetPtrToTpRxBuffer(SoAd_TpRxBufferCfgGetTpRxBufferStartIdx(TpRxBufferCfgIdx)),
                         BufPtr,SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx));
        SoAd_TpRxBufferCtrlSetCurrentBufferIdx(TpRxBufferCfgIdx,
            (SoAd_TpRxBufferCfgGetTpRxBufferStartIdx(TpRxBufferCfgIdx) + 
            SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx)));
        /* Set event to process in the mainfunction */
        SoAd_SoConCtrlSetSoConEventTpReception(SoConIdx,TRUE);
    }
    else
    {
        /* Data copy failure , reset RxPdu status */
        SoAd_SoConRxPduCtrlSetRxBytesPending(RxPduCtrlIdx,0u);
        SoAd_SoConRxPduCtrlSetSocketRouteIdx(RxPduCtrlIdx,SoAd_CfgGetNumOfSocketRoute());
        pUpTpRxIndicationFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),E_NOT_OK);
    }
}
/********************************************************************************************************************
* @brief The Api is used to check whether the routing group is enabled for the socket route dest idx
********************************************************************************************************************/
boolean SoAd_CheckRoutingGroupSocketDestEnabled(SoAd_SocketRouteDestIdxType SocketRouteDestIdx)
{
    boolean Enabled = FALSE;
    SoAd_RgSocketRouteDestMapIdxType RgSocketRouteDestMapIdx;
    SoAd_RgSocketRouteDestIdxType RgSocketRouteDestIdx;
    
    for(RgSocketRouteDestMapIdx= SoAd_SocketRouteDestCfgGetRgSocketRouteDestMapStartIdx(SocketRouteDestIdx);
        RgSocketRouteDestMapIdx<= SoAd_SocketRouteDestCfgGetRgSocketRouteDestMapEndIdx(SocketRouteDestIdx);
        RgSocketRouteDestMapIdx++)
    {
        RgSocketRouteDestIdx = SoAd_RgSocketRouteDestMapCfgGetRgSocketRouteDestIdx(RgSocketRouteDestMapIdx);
        if (SoAd_RoutingGroupSocketRouteDestCtrlGetEnabled(RgSocketRouteDestIdx) == TRUE)
        {
            Enabled = TRUE;
            break;
        }
    }
    return Enabled;
}
/********************************************************************************************************************
* @brief The Api is used to indicate the Udp reception
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxUdpRxIndication
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
)
{
    SoAd_SocketRouteIdxType SocketRouteIdx;
    
    for(SocketRouteIdx=SoAd_SoConCfgGetSocketRouteStartIdx(SoConIdx);
        SocketRouteIdx<=SoAd_SoConCfgGetSocketRouteEndIdx(SoConIdx);SocketRouteIdx++)
    {
        /* Check if routing group is enabled for this socket route */
        if (SoAd_CheckRoutingGroupSocketDestEnabled(SoAd_SocketRouteCfgGetSocketRouteDestIdx(SocketRouteIdx)) == TRUE)
        {
            if (SoAd_SocketRouteCfgGetSocketRouteULType(SocketRouteIdx) == SOAD_UPPER_LAYER_TYPE_IF)
            {
                SoAd_RxIfUdpReceivePdu(SocketRouteIdx, BufPtr, Length); 
            }
            else
            {
                SoAd_RxTpUdpReceivePdu(SocketRouteIdx, BufPtr, Length);
            }
        }
            
    }
}
/********************************************************************************************************************
* @brief The Api is used to process the received If Udp pdu
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxIfUdpReceivePdu
(
    SoAd_SocketRouteIdxType SocketRouteIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
)
{
    PduInfoType PduInfo;
    SoAd_SoConIdType SoConIdx;
    SoAd_ULIdxType SocketRouteULIdx;
    SoAd_UpIfRxIndicationFuncType pUpIfRxIndicationFunc;
   
    SoConIdx = SoAd_SocketRouteCfgGetSoConIdx(SocketRouteIdx);
    /* Update PduInfo */
    PduInfo.SduDataPtr =(uint8 *)&BufPtr[0];
    PduInfo.SduLength = Length;
    SocketRouteULIdx = SoAd_SocketRouteCfgGetSocketRouteULIdx(SocketRouteIdx);
    pUpIfRxIndicationFunc = SoAd_UpperLayerCfgGetUpIfRxIndicationFunc(SocketRouteULIdx);
    /* Check and Add meta data if configured , then forward to UL */
    if (SoAd_RxIfAddMetaDataToPdu(SoConIdx, SocketRouteIdx, &PduInfo) == E_OK )
    {
        /* Notify to upper layer */
        if (pUpIfRxIndicationFunc != NULL_PTR)
        {
            pUpIfRxIndicationFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),&PduInfo);
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to process the received Tp Udp pdu
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpUdpReceivePdu
(
    SoAd_SocketRouteIdxType SocketRouteIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
)
{
    SoAd_SoConIdType SoConIdx;
    SoAd_TpRxBufferIdxType TpRxBufferIdx;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    SoAd_TpRxBufferIdxType TpRxBufferCfgIdx;
    
    SoConIdx = SoAd_SocketRouteCfgGetSoConIdx(SocketRouteIdx);
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    TpRxBufferCfgIdx = SoAd_SoConCfgGetTpRxBufferCfgIdx(SoConIdx);
    
    if (SoAd_SoConRxPduCtrlGetSocketRouteIdx(RxPduCtrlIdx) != SoAd_CfgGetNumOfSocketRoute())
    {
        /* If data already present in buffer */
        if (SoAd_TpRxBufferCtrlGetCurrentBufferIdx(TpRxBufferCfgIdx) > 
            SoAd_TpRxBufferCfgGetTpRxBufferStartIdx(TpRxBufferCfgIdx))
        {
            TpRxBufferIdx = SoAd_TpRxBufferCtrlGetCurrentBufferIdx(TpRxBufferCfgIdx);
            /* Chcek if data can be copied */
            if ((TpRxBufferIdx+ Length) <= SoAd_TpRxBufferCfgGetTpRxBufferEndIdx(TpRxBufferCfgIdx))
            {
                /* copy data to reception buffer */
                SoAd_UtilMemCopy(SoAd_CtrlGetPtrToTpRxBuffer(TpRxBufferIdx),&BufPtr[0],Length);
                SoAd_TpRxBufferCtrlSetCurrentBufferIdx(TpRxBufferCfgIdx,
                                                    SoAd_TpRxBufferCtrlGetCurrentBufferIdx(TpRxBufferCfgIdx)+Length );
            }
        }
        else
        {
            /* Forward PDU to UL. */
            SoAd_RxTpUdpForwardPdu(SocketRouteIdx, BufPtr, Length);
            if ((SoAd_SoConCtrlGetCloseReqType(SoConIdx) == SOAD_CLOSE_REQ_NONE) && 
                (SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx) > 0u))
            {
                /*update length */
                TpRxBufferIdx = SoAd_TpRxBufferCtrlGetCurrentBufferIdx(TpRxBufferCfgIdx)+
                                    (Length - SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx));
                /* Chcek if data can be copied */
                if ((TpRxBufferIdx+ Length) <= SoAd_TpRxBufferCfgGetTpRxBufferEndIdx(TpRxBufferCfgIdx))
                {
                    /* copy data to reception buffer */
                    SoAd_UtilMemCopy(SoAd_CtrlGetPtrToTpRxBuffer(TpRxBufferIdx),&BufPtr[0],Length);
                    SoAd_TpRxBufferCtrlSetCurrentBufferIdx(TpRxBufferCfgIdx,
                                                    SoAd_TpRxBufferCtrlGetCurrentBufferIdx(TpRxBufferCfgIdx)+Length );
                }
                /* Set event to process in the mainfunction */
                SoAd_SoConCtrlSetSoConEventTpReception(SoConIdx,TRUE);
            }
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to forward the the received Tp Udp pdu
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpUdpForwardPdu
(
    SoAd_SocketRouteIdxType SocketRouteIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
)
{
    boolean ContinueRx=TRUE;
    PduLengthType BufferSize=0u;
    SoAd_SoConIdType SoConIdx;
    PduInfoType PduInfo={NULL_PTR,0u};
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    SoAd_ULIdxType SocketRouteULIdx;
    SoAd_UpTpCopyRxDataFuncType pUpTpCopyRxDataFunc;
    
    SoConIdx = SoAd_SocketRouteCfgGetSoConIdx(SocketRouteIdx);
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    SocketRouteULIdx = SoAd_SocketRouteCfgGetSocketRouteULIdx(SocketRouteIdx);
    pUpTpCopyRxDataFunc = SoAd_UpperLayerCfgGetUpTpCopyRxDataFunc(SocketRouteULIdx);
    SoAd_SoConRxPduCtrlSetRxBytesPending(RxPduCtrlIdx,Length);
    if (pUpTpCopyRxDataFunc == NULL_PTR)
    {
        ContinueRx = FALSE;
    }
    /* copy data until all recevied or cancel requsted */
    while((SoAd_SoConRxPduCtrlGetCancelRequest(RxPduCtrlIdx) == FALSE) && (ContinueRx == TRUE))
    {
        /* Request UL to be copy the data */ 
        if (pUpTpCopyRxDataFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),&PduInfo,&BufferSize) == BUFREQ_OK)
        {
            SoAd_SoConRxPduCtrlSetRxBytesPending(RxPduCtrlIdx,
                                                (SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx)-PduInfo.SduLength));
            /* Check for fuurther reception */
            if ((SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx) == 0u) || (BufferSize == 0U))
            {
                ContinueRx = FALSE;
            }
            else
            {
                /* Update pending length */
                PduInfo.SduLength  = SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx);
                if (PduInfo.SduLength > BufferSize)
                {
                    PduInfo.SduLength = BufferSize;
                }
                PduInfo.SduDataPtr = (uint8 *)&BufPtr[Length - SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx)];
            }
        }
        else
        {
            /* Close socket connection in next main function. */
            SoAd_SoConSetCloseReq(SoConIdx, SOAD_CLOSE_REQ_OFFLINE_RESET);
            SoAd_SoConCtrlSetSoConEventStateChange(SoConIdx,TRUE);
            ContinueRx = FALSE;
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to indicate the received tcp pdu header
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTcpPduHdrRxIndication
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
)
{
    uint16 TotalLength;
    uint32 ReleaseBufferLength=0U;
    Std_ReturnType RetVal=E_NOT_OK;
    SoAd_SocketRouteIdxType SocketRouteIdx;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    /* Add tcp segment to the buffer */
    if(SoAd_RxBufStructWriteSegment(SoConIdx,BufPtr,Length) == E_OK)
    {
        /* Get total length */
        TotalLength = SoAd_RxBufStructGetTotLen(SoConIdx, 0u);
        /* Handle reception */
        while (ReleaseBufferLength < TotalLength)
        {
            /* Receive the data */
            if (SoAd_RxTcpPduHdrReceivePdu(SoConIdx, &ReleaseBufferLength, TotalLength) == E_NOT_OK ) 
            {
                RetVal = SoAd_SocketTcpUpdateSkipData(SoConIdx, &ReleaseBufferLength, TotalLength); 
                if ((RetVal == E_NOT_OK) && (ReleaseBufferLength != TotalLength))
                {
                    /* If Tp pdu, set event to process in main function */
                    SocketRouteIdx = SoAd_SoConRxPduCtrlGetSocketRouteIdx(RxPduCtrlIdx);
                    if ((SocketRouteIdx != SoAd_CfgGetNumOfSocketRoute()) && 
                        (SoAd_SocketRouteCfgGetSocketRouteULType(SocketRouteIdx) == SOAD_UPPER_LAYER_TYPE_TP))
                    {
                        SoAd_SoConCtrlSetSoConEventTpReception(SoConIdx,TRUE);
                    }
                    break;
                }
            }
        }
        
        if (ReleaseBufferLength > 0u )
        {
            /* Release buffer segment */
            SoAd_RxBufStructReleaseSegment(SoConIdx,ReleaseBufferLength);
            /* notify TcpIp about reception of socket data is confirmed */
            SoAd_SocketTcpReceived(SoAd_SoConCfgGetSocketIdx(SoConIdx), Length);
        }
    }
    else
    {
        /* Close socket connection in next main function. */
        SoAd_SoConSetCloseReq(SoConIdx, SOAD_CLOSE_REQ_OFFLINE_RESET);
        SoAd_SoConCtrlSetSoConEventStateChange(SoConIdx,TRUE);
    }
}
/********************************************************************************************************************
* @brief The Api is used to write the received data to the segment buffer
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxBufStructWriteSegment
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) SrcBufPtr,
    uint16 SrcBufLen
)
{
    SoAd_RxBufferSegIdxType RxBufferSegIdx;
    SoAd_RxBufferSegDataSizeType RxBufferSegDataIdx; 
    Std_ReturnType RetVal = E_OK;
    
    RxBufferSegIdx = SoAd_SoConCfgGetRxBufferSegIdx(SoConIdx);
    if(SrcBufLen >0U)
    {
        /* If seg buffer is empty, write data to the buffer */
        if (SoAd_RxBufferSegCtrlGetSegLevel(RxBufferSegIdx) == 0u)
        {
            RxBufferSegDataIdx = SoAd_RxBufferSegCtrlGetSegDataIdx(RxBufferSegIdx);
            /* Update Segment data */
            SoAd_RxBufferSegDataCtrlSetSegDataLength(RxBufferSegDataIdx,SrcBufLen);
            SoAd_RxBufferSegDataCtrlSetpRxBufferSegData(RxBufferSegDataIdx,(uint8 *)SrcBufPtr);
            SoAd_RxBufferSegCtrlIncSegLevel(RxBufferSegIdx);
        }
        else
        {
            RetVal = SoAd_RxBufStructWriteAdditionalSegment(SoConIdx, SrcBufPtr, SrcBufLen); 
        }  
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to write the received data to the additional segment buffer
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxBufStructWriteAdditionalSegment
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) SrcBufPtr,
    uint16 SrcBufLen
)
{
    Std_ReturnType RetVal = E_OK;
    uint8 * pLastRxBufferSegData;
    SoAd_RxBufferSegIdxType RxBufferSegIdx;
    SoAd_RxBufferSegLevelType LastSegLevel; 
    SoAd_RxBufferSegDataSizeType LastSegDataIdx; 
    SoAd_RxBufferSegDataSizeType WriteSegDataIdx; 
    
    RxBufferSegIdx = SoAd_SoConCfgGetRxBufferSegIdx(SoConIdx);
    /* Get last data ptr*/
    LastSegLevel = SoAd_RxBufferSegCtrlGetSegLevel(RxBufferSegIdx)-1U;
    LastSegDataIdx = SoAd_RxBufStructCalculateNextSegment(RxBufferSegIdx,
                                                    SoAd_RxBufferSegCtrlGetSegDataIdx(RxBufferSegIdx),LastSegLevel);
    pLastRxBufferSegData=SoAd_RxBufferSegDataCtrlGetpRxBufferSegData(LastSegDataIdx);
    /* Ignore if same segment is called */
    if (&SrcBufPtr[0] != &pLastRxBufferSegData[0u])
    {
        if (&SrcBufPtr[0] == &pLastRxBufferSegData[SoAd_RxBufferSegDataCtrlGetSegDataLength(LastSegDataIdx)])
        {   
            /* update length of the last segment */
            SoAd_RxBufferSegDataCtrlSetSegDataLength(LastSegDataIdx,
                                                SoAd_RxBufferSegDataCtrlGetSegDataLength(LastSegDataIdx)+SrcBufLen);
        }
        else if (SoAd_RxBufferSegCfgGetSegDataSize(RxBufferSegIdx) > SoAd_RxBufferSegCtrlGetSegLevel(RxBufferSegIdx))
        {
            WriteSegDataIdx= SoAd_RxBufStructCalculateNextSegment(RxBufferSegIdx,
                                                                  SoAd_RxBufferSegCtrlGetSegDataIdx(RxBufferSegIdx),
                                                                  SoAd_RxBufferSegCtrlGetSegLevel(RxBufferSegIdx));
            /* Update Segment data */
            SoAd_RxBufferSegDataCtrlSetSegDataLength(WriteSegDataIdx,SrcBufLen);
            SoAd_RxBufferSegDataCtrlSetpRxBufferSegData(WriteSegDataIdx,(uint8 *)SrcBufPtr);
            SoAd_RxBufferSegCtrlIncSegLevel(RxBufferSegIdx);
        }
        else
        {
            RetVal = E_NOT_OK;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to calculate the next segment size
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(SoAd_RxBufferSegDataSizeType, SOAD_CODE) SoAd_RxBufStructCalculateNextSegment
(
    SoAd_RxBufferSegIdxType RxBufferSegIdx,
    SoAd_RxBufferSegDataSizeType SegmentDataIdx,
    SoAd_RxBufferSegLevelType SegmentLvl
)
{ 
    SoAd_RxBufferSegDataSizeType NextSegDataIdx;    
    /* Wrap around the buffer if the SegmentIdx exceeds, else return the next SegmentIdx*/
    if (SegmentDataIdx+SegmentLvl >= SoAd_RxBufferSegCfgGetSegDataStartIdx(RxBufferSegIdx))
    {
        NextSegDataIdx = SegmentLvl-(SoAd_RxBufferSegCfgGetSegDataEndIdx(RxBufferSegIdx)-SegmentDataIdx);
    }
    else
    {
        NextSegDataIdx = SegmentDataIdx+SegmentLvl;
    }
    return NextSegDataIdx;
}
/********************************************************************************************************************
* @brief The Api is used to get the total length of the buffer
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(uint32, SOAD_CODE) SoAd_RxBufStructGetTotLen
(
    SoAd_SoConIdType SoConIdx,
    SoAd_RxBufferSegDataSizeType BufSegOffset
)
{
    uint32 TotalLength = 0u;
    SoAd_RxBufferSegIdxType RxBufferSegIdx;
    SoAd_RxBufferSegDataSizeType RxBufferSegDataIdx;
    SoAd_RxBufferSegDataSizeType RxBufferSegDataOffsetIdx=BufSegOffset;
    
    RxBufferSegIdx = SoAd_SoConCfgGetRxBufferSegIdx(SoConIdx);
    RxBufferSegDataIdx = SoAd_RxBufferSegCtrlGetSegDataIdx(RxBufferSegIdx);
    while(RxBufferSegDataOffsetIdx < SoAd_RxBufferSegCtrlGetSegLevel(RxBufferSegIdx))
    {
        TotalLength += SoAd_RxBufferSegDataCtrlGetSegDataLength(RxBufferSegDataIdx);
        if (RxBufferSegDataIdx+RxBufferSegDataOffsetIdx <= SoAd_RxBufferSegCfgGetSegDataEndIdx(RxBufferSegIdx))
        {
            RxBufferSegDataIdx += RxBufferSegDataOffsetIdx;
        }
        else
        {
            RxBufferSegDataIdx += (RxBufferSegDataOffsetIdx-SoAd_RxBufferSegCfgGetSegDataEndIdx(RxBufferSegIdx));
        }
        RxBufferSegDataOffsetIdx++;
    }
    return TotalLength;
}
/********************************************************************************************************************
* @brief The Api is used to process the received tcp pdu header
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTcpPduHdrReceiveHeader
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) ReleaseBufLenPtr,
    uint32 TotalLen
)
{
    Std_ReturnType RetVal;
    SoAd_PduHeaderLenType PduHeaderLength;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    uint8 PduHeaderBuffer[SOAD_PDU_HEADER_SIZE] = { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u };
    
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    if (SoAd_SoConRxPduCtrlGetSocketRouteIdx(RxPduCtrlIdx) != SoAd_CfgGetNumOfSocketRoute())
    {
        RetVal = E_OK;
    }
    else if ((TotalLen - *ReleaseBufLenPtr) < SOAD_PDU_HEADER_SIZE)
    {
        /* PDU header not yet received completely */
        RetVal = E_NOT_OK;
    }
    else
    {
        /* Copy Header */
        SoAd_RxBufStructCopy2Buf(SoConIdx, &PduHeaderBuffer[0], SOAD_PDU_HEADER_SIZE, *ReleaseBufLenPtr);  
        /* get Header Length */
        PduHeaderLength = SoAd_UtilExtractPduHeaderLength(PduHeaderBuffer);
        if ((PduHeaderLength <= SOAD_MAX_PDU_LENGTH) && (PduHeaderLength != 0u))
        {
            /* Get socket route by PDU header. */
            RetVal = SoAd_RxTcpPduHdrFindSocketRoute(SoConIdx, PduHeaderBuffer); 
        }
        else
        {
            RetVal = E_NOT_OK;
        }
        /* Release TcpIp buffer for PDU header */
        *ReleaseBufLenPtr += SOAD_PDU_HEADER_SIZE; 

        /* Skip PDU if any error occurred. */
        if (RetVal == E_NOT_OK)
        {
            SoAd_SocketCtrlSetSkipBytes(SoAd_SoConCfgGetSocketIdx(SoConIdx),PduHeaderLength);
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to copy the received data to the local buffer
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxBufStructCopy2Buf
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint8, SOAD_APPL_DATA, SOAD_APPL_DATA) BufPtr,
    uint32 BufLen, /* Header size */
    uint32 BufSegOffset /* data length to be released */
)
{
    uint8 * pSegDataBuffer;
    uint32 SegDataOffset;
    uint32 BytesToCopy=0u;
    uint32 BytesCopied=0u;
    uint32 LocalBufferLength = BufLen; /* header size */
    uint32 LocalBufferSegOffset=BufSegOffset;
    SoAd_RxBufferSegDataSizeType RxBufferSegDataIdx; /* current copied length*/ 
    
    while(LocalBufferLength > 0U)
    {
        /* Get segment offset from which to copy data */
        SegDataOffset = LocalBufferSegOffset;
        (void)SoAd_RxBufStructGetBufSegIdx(SoConIdx, &SegDataOffset, &RxBufferSegDataIdx); 
        /* calculate the byte to copy */
        BytesToCopy = SoAd_RxBufferSegDataCtrlGetSegDataLength(RxBufferSegDataIdx) - SegDataOffset;
        /* calculate the copy data length */
        if (LocalBufferLength <  BytesToCopy)
        {
            BytesToCopy = LocalBufferLength;
        }
        /* copy data to buffer */
        pSegDataBuffer = SoAd_RxBufferSegDataCtrlGetpRxBufferSegData(RxBufferSegDataIdx);
        SoAd_UtilMemCopy(&BufPtr[BytesCopied],&pSegDataBuffer[SegDataOffset],BytesToCopy);
        /* update length */
        BytesCopied+=BytesToCopy;
        LocalBufferLength-=BytesToCopy;
        LocalBufferSegOffset+=BytesToCopy;
    }
}
/********************************************************************************************************************
* @brief The Api is used to process the received Tcp pdu header  
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTcpPduHdrReceivePdu
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) ReleaseBufLenPtr,
    uint32 TotalLen
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    /* Receive PDU header. */
    if (SoAd_RxTcpPduHdrReceiveHeader(SoConIdx, ReleaseBufLenPtr, TotalLen) == E_OK) 
    {
        RetVal = SoAd_RxTcpPduHdrReceiveData(SoConIdx, ReleaseBufLenPtr, TotalLen); 
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to get the buffer segment data idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxBufStructGetBufSegIdx
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) OffsetPtr,
    P2VAR(SoAd_RxBufferSegDataSizeType, AUTOMATIC, SOAD_APPL_VAR) RxBufferSegDataIdxPtr
)
{
    uint32 Offset = *OffsetPtr;
    Std_ReturnType RetVal=E_NOT_OK;
    SoAd_RxBufferSegIdxType RxBufferSegIdx;
    SoAd_RxBufferSegDataSizeType RxBufferSegDataIdx;
    SoAd_RxBufferSegDataSizeType RxBufferSegDataOffsetIdx=0u;
    
    RxBufferSegIdx = SoAd_SoConCfgGetRxBufferSegIdx(SoConIdx);
    RxBufferSegDataIdx = SoAd_RxBufferSegCtrlGetSegDataIdx(RxBufferSegIdx);
    /* check and get the RxBufferSegDataIdx and offset */
    for(RxBufferSegDataOffsetIdx=0u;RxBufferSegDataOffsetIdx < SoAd_RxBufferSegCtrlGetSegLevel(RxBufferSegIdx);
        RxBufferSegDataOffsetIdx++)
    {
        if (Offset >= SoAd_RxBufferSegDataCtrlGetSegDataLength(RxBufferSegDataIdx))
        {
            Offset -= SoAd_RxBufferSegDataCtrlGetSegDataLength(RxBufferSegDataIdx);
            /* consider overlap */
            if (RxBufferSegDataIdx+1u > SoAd_RxBufferSegCfgGetSegDataEndIdx(RxBufferSegIdx))
            {
                RxBufferSegDataIdx = SoAd_RxBufferSegCfgGetSegDataEndIdx(RxBufferSegIdx);
            }
            else
            {
                RxBufferSegDataIdx++;
            }
        }
        else
        {
            *OffsetPtr =Offset;
            *RxBufferSegDataIdxPtr = RxBufferSegDataIdx;
            RetVal = E_OK;
            break;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to request the release of the rx buffer segment
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxBufStructReleaseSegment(SoAd_SoConIdType SoConIdx,uint32 Len)
{
    uint8 * pRxBufferSegData;
    uint32  LocalLength = Len;
    SoAd_RxBufferSegIdxType RxBufferSegIdx;
    SoAd_RxBufferSegDataSizeType RxBufferSegDataIdx;
    SoAd_RxBufferSegDataSizeType RxBufferSegDataOffsetIdx=0u;
    
    RxBufferSegIdx = SoAd_SoConCfgGetRxBufferSegIdx(SoConIdx);
    /* check and get the RxBufferSegDataIdx and offset */
    for(RxBufferSegDataOffsetIdx=0u;
        RxBufferSegDataOffsetIdx < SoAd_RxBufferSegCtrlGetSegLevel(RxBufferSegIdx);RxBufferSegDataOffsetIdx++)
    {
        RxBufferSegDataIdx = SoAd_RxBufferSegCtrlGetSegDataIdx(RxBufferSegIdx);
        pRxBufferSegData = SoAd_RxBufferSegDataCtrlGetpRxBufferSegData(RxBufferSegDataIdx);
        if (LocalLength < SoAd_RxBufferSegDataCtrlGetSegDataLength(RxBufferSegDataIdx))
        {
            /* Release current segment  */
            SoAd_RxBufferSegDataCtrlSetSegDataLength(RxBufferSegDataIdx,
                                    SoAd_RxBufferSegDataCtrlGetSegDataLength(RxBufferSegDataIdx)-LocalLength);
            SoAd_RxBufferSegDataCtrlSetpRxBufferSegData(RxBufferSegDataIdx,&pRxBufferSegData[LocalLength]);
        }
        else
        {
            /* Reset segment length and decrement length to be released. */
            LocalLength -= SoAd_RxBufferSegDataCtrlGetSegDataLength(RxBufferSegDataIdx);
            SoAd_RxBufferSegDataCtrlSetSegDataLength(RxBufferSegDataIdx,0u);
            SoAd_RxBufferSegCtrlSetSegLevel(RxBufferSegIdx,0u);
            /* Calculate next segment index considering buffer struct wrap around. */
            if ((RxBufferSegDataIdx + 1u) == SoAd_RxBufferSegCfgGetSegDataEndIdx(RxBufferSegIdx))
            {
                SoAd_RxBufferSegCtrlSetSegDataIdx(RxBufferSegIdx,SoAd_RxBufferSegCfgGetSegDataStartIdx(RxBufferSegIdx));
            }
            else
            {
                SoAd_RxBufferSegCtrlIncSegDataIdx(RxBufferSegIdx);
            }
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to find the socket routed for the received tcp pdu header
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTcpPduHdrFindSocketRoute
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_DATA) PduHdrBufPtr
)
{
    Std_ReturnType RetVal=E_NOT_OK;
    SoAd_PduHeaderIdType PduHeaderId;
    SoAd_SocketRouteIdxType SocketRouteIdx;
    SoAd_SocketRouteDestIdxType SocketRouteDestIdx;
    
    PduHeaderId = SoAd_UtilExtractPduHeaderId(PduHdrBufPtr);
    /* Check if Pdu Id is supported or not */
    for (SocketRouteIdx = SoAd_SoConCfgGetSocketRouteStartIdx(SoConIdx);
         SocketRouteIdx <= SoAd_SoConCfgGetSocketRouteEndIdx(SoConIdx);SocketRouteIdx++)
    {
        /* if pdu header id found */
        if (PduHeaderId == SoAd_SocketRouteCfgGetRxPduHeaderId(SocketRouteIdx))
        {
            SocketRouteDestIdx = SoAd_SocketRouteCfgGetSocketRouteDestIdx(SocketRouteIdx);
            if (SoAd_CheckRoutingGroupSocketDestEnabled(SocketRouteDestIdx) == TRUE)
            {
                if (SoAd_SocketRouteCfgGetSocketRouteULType(SocketRouteIdx) == SOAD_UPPER_LAYER_TYPE_IF)
                {
                    RetVal = SoAd_RxIfTcpPduHdrReceiveHeader(SoConIdx,SocketRouteIdx,PduHdrBufPtr);
                }
                else
                {
                    SoAd_RxTpTcpPduHdrReceiveHeader(SoConIdx,SocketRouteIdx,PduHdrBufPtr);
                    RetVal = E_OK;
                }
            }
            break;
        }                
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to process the received Tcp If pdu header
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxIfTcpPduHdrReceiveHeader
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SockRouteIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_DATA) PduHdrBufPtr
)
{
    Std_ReturnType RetVal=E_NOT_OK;
    SoAd_PduHeaderLenType PduHeaderLength;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    SoAd_RxIfBufferIdxType RxIfBufferIdx;
    
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    RxIfBufferIdx = SoAd_SoConCfgGetRxIfBufferIdx(SoConIdx);
    /* Get header length */
    PduHeaderLength = SoAd_UtilExtractPduHeaderLength(PduHdrBufPtr);
    
    if ((PduHeaderLength+SOAD_PDU_HEADER_SIZE) <= SoAd_RxIfBufferCfgGetSize(RxIfBufferIdx))
    {
        SoAd_SoConRxPduCtrlSetSocketRouteIdx(RxPduCtrlIdx,SockRouteIdx);
        /* copy data to if buffer */
        SoAd_UtilMemCopy(SoAd_CtrlGetPtrToRxIfBuffer(SoAd_RxIfBufferCfgGetStartIdx(RxIfBufferIdx)),
                        PduHdrBufPtr,SOAD_PDU_HEADER_SIZE);
        /* Set buffer idx */
        SoAd_RxIfBufferCtrlSetBufferIdx(RxIfBufferIdx,
                                        SoAd_RxIfBufferCtrlGetBufferIdx(RxIfBufferIdx)+SOAD_PDU_HEADER_SIZE);
        RetVal = E_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to process the received Tcp Tp pdu header
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpTcpPduHdrReceiveHeader
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SockRouteIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_DATA) PduHdrBufPtr
)
{
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    SoAd_TpRxBufferIdxType TpRxBufferCfgIdx;
    
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    TpRxBufferCfgIdx = SoAd_SoConCfgGetTpRxBufferCfgIdx(SoConIdx);
    /* copy pdu header data */
    SoAd_SoConRxPduCtrlSetSocketRouteIdx(RxPduCtrlIdx,SockRouteIdx);
    SoAd_UtilMemCopy(SoAd_CtrlGetPtrToTpRxBuffer(SoAd_TpRxBufferCfgGetTpRxBufferStartIdx(TpRxBufferCfgIdx)),
                     PduHdrBufPtr,SOAD_PDU_HEADER_SIZE);
}
/********************************************************************************************************************
* @brief The Api is used to process the received tcp pdu header data
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTcpPduHdrReceiveData
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) ReleaseBufLenPtr,
    uint32 TotalLen
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SocketRouteIdxType SocketRouteIdx;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    PduInfoType PduInfo = { NULL_PTR, 0u };
    
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    SocketRouteIdx = SoAd_SoConRxPduCtrlGetSocketRouteIdx(RxPduCtrlIdx);
    
    if (SoAd_SocketRouteCfgGetSocketRouteULType(SocketRouteIdx) == SOAD_UPPER_LAYER_TYPE_IF)
    {
        /* copy complete pdu data */
        if (SoAd_RxIfTcpPduHdrCopyData(SoConIdx, ReleaseBufLenPtr, TotalLen, &PduInfo) == E_OK)
        {
            /* notify to upper layer */
            SoAd_RxIfTcpPduHdrForwardPdu(SoConIdx, &PduInfo);
            RetVal = E_OK;
        }
    }
    else
    {
        /* notify to upper layer */
        RetVal = SoAd_RxTpTcpPduHdrForwardPdu(SoConIdx, ReleaseBufLenPtr, TotalLen);
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to copy the data of the received If tcp pdu header
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxIfTcpPduHdrCopyData
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) ReleaseBufLenPtr,
    uint32 TotalLen,
    P2VAR(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
)
{
    uint8 *pRxIfBuffer;
    uint32 BytesToCopy;
    uint32 RxBufferSegLength = 0u;
    Std_ReturnType RetVal=E_NOT_OK;
    SoAd_PduHeaderLenType PduHeaderLen;
    SoAd_RxIfBufferIdxType RxIfBufferIdx;
    SoAd_RxIfBufferIdxType RxIfBufferLength;
    SoAd_RxIfBufferIdxType RxIfBufferStartIdx;
    uint32 LocalReleaseBufLen=*ReleaseBufLenPtr;
    
    RxIfBufferIdx = SoAd_SoConCfgGetRxIfBufferIdx(SoConIdx);
    RxIfBufferStartIdx = SoAd_RxIfBufferCfgGetStartIdx(RxIfBufferIdx);
    RxIfBufferLength = SoAd_RxIfBufferCtrlGetBufferIdx(RxIfBufferIdx)-RxIfBufferStartIdx;
    pRxIfBuffer =SoAd_CtrlGetPtrToRxIfBuffer(RxIfBufferStartIdx);
    /* copy header length */
    PduHeaderLen = SoAd_UtilExtractPduHeaderLength(pRxIfBuffer);
    /* sets data pointer to TcpIp buffer segment */
    SoAd_RxBufStructGetSegment(SoConIdx, LocalReleaseBufLen, &PduInfoPtr->SduDataPtr, &RxBufferSegLength); 
    if ((PduHeaderLen <= RxBufferSegLength) && (RxIfBufferLength == SOAD_PDU_HEADER_SIZE))
    {
        /* if PDU is received within one TCP segment. */
        LocalReleaseBufLen+=PduHeaderLen;
        PduInfoPtr->SduLength = (PduLengthType)PduHeaderLen;
        RetVal=E_OK;
    }
    else
    {
        /* if PDU is received in multiple TCP segments. */
        /* copy data to if reception buffer */
        BytesToCopy = PduHeaderLen+SOAD_PDU_HEADER_SIZE - RxIfBufferLength;
        if (BytesToCopy > (TotalLen-LocalReleaseBufLen))
        {
            BytesToCopy = (TotalLen-LocalReleaseBufLen);
        }
        SoAd_RxBufStructCopy2Buf(SoConIdx,SoAd_CtrlGetPtrToRxIfBuffer(SoAd_RxIfBufferCtrlGetBufferIdx(RxIfBufferIdx)),
                                 BytesToCopy,LocalReleaseBufLen);
        /* update buffer length */
        RxIfBufferLength +=BytesToCopy;
        SoAd_RxIfBufferCtrlSetBufferIdx(RxIfBufferIdx,RxIfBufferStartIdx+RxIfBufferLength);
        /* Release buffer length */
        LocalReleaseBufLen+=BytesToCopy;
        if (RxIfBufferLength == (PduHeaderLen+SOAD_PDU_HEADER_SIZE))
        {
            /* If entire pdu length is copied */
            PduInfoPtr->SduDataPtr = SoAd_CtrlGetPtrToRxIfBuffer((RxIfBufferStartIdx + SOAD_PDU_HEADER_SIZE));
            PduInfoPtr->SduLength = (PduLengthType)(RxIfBufferLength - SOAD_PDU_HEADER_SIZE);
            RetVal = E_OK;
        }
    }
    /* update release buffer length */
    *ReleaseBufLenPtr = LocalReleaseBufLen;
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to get segment for the received msg
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxBufStructGetSegment
(
    SoAd_SoConIdType SoConIdx,
    uint32 BufSegOffset,
    P2VAR(uint8*, AUTOMATIC, SOAD_APPL_VAR) BufSegPtr,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) BufSegLenPtr
)
{
    uint8 * pLocalBufferSeg;
    uint32 LocalBufferSegOffset =BufSegOffset;
    SoAd_RxBufferSegIdxType RxBufferSegIdx;
    SoAd_RxBufferSegDataSizeType RxBufferSegDataIdx;
    
    RxBufferSegIdx = SoAd_SoConCfgGetRxBufferSegIdx(SoConIdx);
    RxBufferSegDataIdx = SoAd_RxBufferSegCtrlGetSegDataIdx(RxBufferSegIdx);
    if (SoAd_RxBufStructGetBufSegIdx(SoConIdx,&LocalBufferSegOffset,&RxBufferSegDataIdx) == E_OK)
    {
        /* set the RxBuffer segment */
        pLocalBufferSeg = SoAd_RxBufferSegDataCtrlGetpRxBufferSegData(RxBufferSegDataIdx);
        *BufSegPtr = &pLocalBufferSeg[LocalBufferSegOffset];
        *BufSegLenPtr = SoAd_RxBufferSegDataCtrlGetSegDataLength(RxBufferSegDataIdx)-LocalBufferSegOffset;
    }
    else
    {
        /* set the BufSegLenPtr is 0 to indicate no segment available */
        *BufSegPtr = SoAd_RxBufferSegDataCtrlGetpRxBufferSegData(RxBufferSegDataIdx);
        *BufSegLenPtr=0U;
    }
}
/********************************************************************************************************************
* @brief The Api is used to forward the received If tcp header
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxIfTcpPduHdrForwardPdu
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
)
{
    SoAd_ULIdxType SocketRouteULIdx;
    SoAd_SocketRouteIdxType SocketRouteIdx; 
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    SoAd_RxIfBufferIdxType RxIfBufferIdx;
    SoAd_UpIfRxIndicationFuncType pUpIfRxIndicationFunc;
    
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    SocketRouteIdx = SoAd_SoConRxPduCtrlGetSocketRouteIdx(RxPduCtrlIdx);
    RxIfBufferIdx = SoAd_SoConCfgGetRxIfBufferIdx(SoConIdx);
    SocketRouteULIdx = SoAd_SocketRouteCfgGetSocketRouteULIdx(SocketRouteIdx);
    pUpIfRxIndicationFunc = SoAd_UpperLayerCfgGetUpIfRxIndicationFunc(SocketRouteULIdx);
    /* Add Meta data if configured */
    if(SoAd_RxIfAddMetaDataToPdu(SoConIdx,SocketRouteIdx,PduInfoPtr) == E_OK)
    {
        pUpIfRxIndicationFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),PduInfoPtr);
    }
    /* reset if buffer */
    SoAd_RxIfBufferCtrlSetBufferIdx(RxIfBufferIdx,SoAd_RxIfBufferCfgGetStartIdx(RxIfBufferIdx));
    SoAd_SoConRxPduCtrlSetSocketRouteIdx(RxPduCtrlIdx,SoAd_CfgGetNumOfSocketRoute()); 
}
/********************************************************************************************************************
* @brief The Api is used to forward the received Tp tcp header
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTpTcpPduHdrForwardPdu
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) ReleaseBufLenPtr,
    uint32 TotalLen
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_PduHeaderLenType PduHeaderLen;
    SoAd_TpRxBufferIdxType TpRxBufferCfgIdx;
    SoAd_TpRxBufferIdxType TpRxBufferIdx;
    
    TpRxBufferCfgIdx = SoAd_SoConCfgGetTpRxBufferCfgIdx(SoConIdx);
    TpRxBufferIdx = SoAd_TpRxBufferCfgGetTpRxBufferStartIdx(TpRxBufferCfgIdx);
    /*get header length */
    PduHeaderLen=SoAd_UtilExtractPduHeaderLength(SoAd_CtrlGetPtrToTpRxBuffer(TpRxBufferIdx));
    /* Call StartOfReception. */
    if (SoAd_RxTpTcpPduHdrStartOfReception(SoConIdx, PduHeaderLen) == E_OK)
    {
        /* Copy data by calling CopyRxData. */
        RetVal = SoAd_RxTpTcpPduHdrCopyRxData(SoConIdx, ReleaseBufLenPtr);
    }
    SOAD_DUMMY_STATEMENT(TotalLen);
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to indicate the Tcp Tp start of reception for pdu header
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTpTcpPduHdrStartOfReception
(
    SoAd_SoConIdType SoConIdx,
    SoAd_PduHeaderLenType PduHdrLen
)
{
    PduLengthType BufferSize = 0U;
    Std_ReturnType RetVal=E_NOT_OK;
    SoAd_ULIdxType SocketRouteULIdx;
    SoAd_SocketRouteIdxType SocketRouteIdx;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    SoAd_UpTpStartOfReceptionFuncType pUpTpStartOfReceptionFunc;
    
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    /* If no data received , then notify the upper layer to process the pdu */
    if (SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx) == 0U)
    {
        SocketRouteIdx = SoAd_SoConRxPduCtrlGetSocketRouteIdx(RxPduCtrlIdx);
        SocketRouteULIdx = SoAd_SocketRouteCfgGetSocketRouteULIdx(SocketRouteIdx);
        pUpTpStartOfReceptionFunc = SoAd_UpperLayerCfgGetUpTpStartOfReceptionFunc(SocketRouteULIdx);
        
        if (pUpTpStartOfReceptionFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),NULL_PTR,
                                        PduHdrLen,&BufferSize) == BUFREQ_OK)
        {
            /* update Pending length */
            SoAd_SoConRxPduCtrlSetRxBytesPending(RxPduCtrlIdx,PduHdrLen);
            RetVal = E_OK;
        }
        else
        {
            /* If failed update skip bytes */
            SoAd_SocketCtrlSetSkipBytes(SoAd_SoConCfgGetSocketIdx(SoConIdx),PduHdrLen);
            SoAd_SoConRxPduCtrlSetSocketRouteIdx(RxPduCtrlIdx,SoAd_CfgGetNumOfSocketRoute());
        }
    }
    else
    {
        RetVal = E_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to indicate the Tcp Tp copy data for pdu header
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTpTcpPduHdrCopyRxData
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) ReleaseBufLenPtr
)
{
    uint32 BufSegLength = 0u;
    Std_ReturnType RetVal = E_NOT_OK;
    PduInfoType PduInfo = { NULL_PTR, 0u };
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    while(SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx) > 0u)
    {
        /* process data if no cancel reqeuest */
        if (SoAd_SoConRxPduCtrlGetCancelRequest(RxPduCtrlIdx) == FALSE)
        {
            /* Get next segment */
            SoAd_RxBufStructGetSegment(SoConIdx, *ReleaseBufLenPtr, &PduInfo.SduDataPtr, &BufSegLength);
            /* if there is segment for receive data */
            if (BufSegLength > 0)
            {
                /* Calculate available length of data to be copied in next CopyRxData call. */
                if (PduInfo.SduLength > 0u )
                {
                    if (PduInfo.SduLength > BufSegLength)
                    {
                        /* set buffer segment length if its smaller than length provided by UL. */
                        PduInfo.SduLength = (PduLengthType)BufSegLength;
                    }
                    if (PduInfo.SduLength > SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx))
                    {
                        /* Set PDU pending length if  its smaller than length provided by UL. */
                        PduInfo.SduLength = SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx);
                    }
                }                
                /* Call CopyRxData. */
                RetVal = SoAd_RxTpTcpPduHdrCopyRxDataCall(SoConIdx, ReleaseBufLenPtr, &PduInfo);  
            }
            else
            {
                RetVal = E_NOT_OK;
            }
        }
        else
        {
            RetVal = E_NOT_OK;
        }
        /* if E_NOT_OK , then return without processing */
        if (RetVal == E_NOT_OK)
        {
            break;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to process and notify the Tcp Tp copy data for pdu header to upper layer
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_RxTpTcpPduHdrCopyRxDataCall
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) ReleaseBufLenPtr,
    P2VAR(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
)
{
    PduLengthType BufferSize = 0u;
    SoAd_ULIdxType SocketRouteULIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    SoAd_SocketRouteIdxType SocketRouteIdx;
    SoAd_UpTpCopyRxDataFuncType pUpTpCopyRxDataFunc;
    SoAd_UpTpRxIndicationFuncType pUpTpRxIndicationFunc;
    
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    SocketRouteIdx = SoAd_SoConRxPduCtrlGetSocketRouteIdx(RxPduCtrlIdx);
    SocketRouteULIdx = SoAd_SocketRouteCfgGetSocketRouteULIdx(SocketRouteIdx);
    pUpTpCopyRxDataFunc = SoAd_UpperLayerCfgGetUpTpCopyRxDataFunc(SocketRouteULIdx);
    pUpTpRxIndicationFunc = SoAd_UpperLayerCfgGetUpTpRxIndicationFunc(SocketRouteULIdx);
    
    if (pUpTpCopyRxDataFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),PduInfoPtr,&BufferSize) == BUFREQ_OK)
    {
        /* Release copied data */
        *ReleaseBufLenPtr += PduInfoPtr->SduLength; 
        SoAd_SoConRxPduCtrlSetRxBytesPending(RxPduCtrlIdx,
                                            SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx)-PduInfoPtr->SduLength);
        
        if (SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx) > 0u)
        {
            /* If still Rx data is pending and UL buffer size is available,continue to receive */
            if (BufferSize > 0u)
            {
                PduInfoPtr->SduLength = BufferSize;
                RetVal=E_OK;
            }
        }
        else
        {
            /* if all data received , call RxIndication  */
            SoAd_SoConRxPduCtrlSetSocketRouteIdx(RxPduCtrlIdx,SoAd_CfgGetNumOfSocketRoute());
            pUpTpRxIndicationFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),E_OK);
            RetVal=E_OK;
        }
    }
    else
    {
        /* set skip bytes if copy fails */
        SoAd_SocketCtrlSetSkipBytes(SoAd_SoConCfgGetSocketIdx(SoConIdx),
                                    SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx));
        /* Reset RxPduCtrlIdx */
        SoAd_SoConRxPduCtrlSetSocketRouteIdx(RxPduCtrlIdx,SoAd_CfgGetNumOfSocketRoute());
        SoAd_SoConRxPduCtrlSetRxBytesPending(RxPduCtrlIdx,0U);
        /* notify upper layer E_NOT_OK */
        pUpTpRxIndicationFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),E_NOT_OK);
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to indicate the received Tcp data
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTcpRxIndication
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
)
{
    uint32 ReleaseBufferLength = 0U;
    SoAd_SocketRouteIdxType SocketRouteIdx;
    SoAd_SocketRouteDestIdxType SocketRouteDestIdx;
    
    /* process for all socket route */
    for(SocketRouteIdx = SoAd_SoConCfgGetSocketRouteStartIdx(SoConIdx);
        SocketRouteIdx <= SoAd_SoConCfgGetSocketRouteEndIdx(SoConIdx);SocketRouteIdx++)
    {
        SocketRouteDestIdx = SoAd_SocketRouteCfgGetSocketRouteDestIdx(SocketRouteIdx);
        if (SoAd_CheckRoutingGroupSocketDestEnabled(SocketRouteDestIdx) == TRUE)
        {
            if (SoAd_SocketRouteCfgGetSocketRouteULType(SocketRouteIdx) == SOAD_UPPER_LAYER_TYPE_IF)
            {
                /* notify received TCP segment as one PDU to user. */
                SoAd_RxIfTcpReceivePdu(SoConIdx,SocketRouteIdx, BufPtr, Length);
                /* Release whole buffer length */
                ReleaseBufferLength = Length;
            }
            else
            {
                /* notify received TCP segment as streaming PDU to user. */
                SoAd_RxTpTcpReceivePdu(SoConIdx, BufPtr, Length, &ReleaseBufferLength);
            }
        }
    }
    
    if (ReleaseBufferLength > 0u)
    {
        /* Release buffer */
        SoAd_RxBufStructReleaseSegment(SoConIdx, ReleaseBufferLength);
        /* Release buffer in TcpIp. */
        SoAd_SocketTcpReceived(SoAd_SoConCfgGetSocketIdx(SoConIdx), ReleaseBufferLength);
    }
}
/********************************************************************************************************************
* @brief The Api is used to process the received Tcp If Pdu
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxIfTcpReceivePdu
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SocketRouteIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length
)
{
    PduInfoType PduInfo;
    SoAd_ULIdxType SocketRouteULIdx;
    SoAd_UpIfRxIndicationFuncType pUpIfRxIndicationFunc;
    
    SocketRouteULIdx = SoAd_SocketRouteCfgGetSocketRouteULIdx(SocketRouteIdx);
    pUpIfRxIndicationFunc = SoAd_UpperLayerCfgGetUpIfRxIndicationFunc(SocketRouteULIdx);
    /* update PduInfo */
    PduInfo.SduDataPtr = (uint8 *)BufPtr;
    PduInfo.SduLength = (PduLengthType)Length;
    /* Add meta data if enabled */
    if (SoAd_RxIfAddMetaDataToPdu(SoConIdx,SocketRouteIdx,&PduInfo) == E_OK)
    {
        /* notify to user. */
        pUpIfRxIndicationFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),&PduInfo);
    }
}
/********************************************************************************************************************
* @brief The Api is used to process the received Tcp Tp Pdu
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpTcpReceivePdu
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) BufPtr,
    uint16 Length,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_DATA) ReleaseBufLenPtr
)
{
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    /* check if Tp in progress */
    if (SoAd_SoConRxPduCtrlGetSocketRouteIdx(RxPduCtrlIdx) != SoAd_CfgGetNumOfSocketRoute())
    {
        /* if no cancel request pending */
        if (SoAd_SoConRxPduCtrlGetCancelRequest(RxPduCtrlIdx) == FALSE)
        {
            /* add segment to buffer */
            if(SoAd_RxBufStructWriteSegment(SoConIdx,BufPtr,Length) == E_OK)
            {
                /* notify to UL */
                SoAd_RxTpTcpForwardPdu(SoConIdx, ReleaseBufLenPtr);
            }
            else
            {
                SoAd_SoConSetCloseReq(SoConIdx, SOAD_CLOSE_REQ_OFFLINE_RESET); 
                SoAd_SoConCtrlSetSoConEventStateChange(SoConIdx,TRUE);
            }
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to forward the received Tp Tcp pdu
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpTcpForwardPdu
(
    SoAd_SoConIdType SoConIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_DATA) ReleaseBufLenPtr
)
{
    boolean ContinueRx=TRUE;
    PduLengthType BufferSize = 0u;
    uint32 RxBufferSegLength = 0u;
    SoAd_ULIdxType SocketRouteULIdx;
    PduInfoType PduInfo={NULL_PTR,0U};
    SoAd_SocketRouteIdxType SocketRouteIdx;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    SoAd_UpTpCopyRxDataFuncType pUpTpCopyRxDataFunc;
    
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    SocketRouteIdx = SoAd_SoConRxPduCtrlGetSocketRouteIdx(RxPduCtrlIdx);
    SocketRouteULIdx = SoAd_SocketRouteCfgGetSocketRouteULIdx(SocketRouteIdx);
    pUpTpCopyRxDataFunc = SoAd_UpperLayerCfgGetUpTpCopyRxDataFunc(SocketRouteULIdx);
    while (ContinueRx == TRUE)
    {
        /* call UL CopyRxData */
        if (pUpTpCopyRxDataFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),&PduInfo,&BufferSize) == BUFREQ_OK)
        {
            *ReleaseBufLenPtr += PduInfo.SduLength;
            /* Get next TCP segment. */
            SoAd_RxBufStructGetSegment(SoConIdx, *ReleaseBufLenPtr,&PduInfo.SduDataPtr,&RxBufferSegLength); 
            /* update sdulength */
            PduInfo.SduLength = RxBufferSegLength;
            if (PduInfo.SduLength > BufferSize)
            {
                PduInfo.SduLength = BufferSize;
            }
            if(RxBufferSegLength == 0U)
            {
                /* If no data left to be copied */
                ContinueRx = FALSE;
            }
            else if (BufferSize == 0U)
            {
                /* continue to request UL in next main function */
                SoAd_SoConCtrlSetSoConEventTpReception(SoConIdx,TRUE);
                ContinueRx = FALSE;
            }
            else
            {
                /* continue to copy data */
            }
        }
        else
        {
            /* Close socket connection in next main function. */
            SoAd_SoConSetCloseReq(SoConIdx, SOAD_CLOSE_REQ_OFFLINE_RESET); 
            SoAd_SoConCtrlSetSoConEventStateChange(SoConIdx,TRUE);
            ContinueRx = FALSE;
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to handle the cancellation of the received Tp data
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpHandleCancellation(SoAd_SoConIdType SoConIdx)
{
    SoAd_ULIdxType SocketRouteULIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_SocketRouteIdxType SocketRouteIdx;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    SoAd_TpRxBufferIdxType TpRxBufferCfgIdx;
    SoAd_UpTpRxIndicationFuncType pUpTpRxIndicationFunc;
    
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    SocketRouteIdx = SoAd_SoConRxPduCtrlGetSocketRouteIdx(RxPduCtrlIdx);
    TpRxBufferCfgIdx = SoAd_SoConCfgGetTpRxBufferCfgIdx(SoConIdx);
    SocketRouteULIdx = SoAd_SocketRouteCfgGetSocketRouteULIdx(SocketRouteIdx);
    pUpTpRxIndicationFunc = SoAd_UpperLayerCfgGetUpTpRxIndicationFunc(SocketRouteULIdx);
    /* Reset Tcp RxTp buffer Idx */
    if (SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE)
    {
        SoAd_TpRxBufferCtrlSetCurrentBufferIdx(TpRxBufferCfgIdx,
                                               SoAd_TpRxBufferCfgGetTpRxBufferStartIdx(TpRxBufferCfgIdx));
    }
    /* Reset Tp status */
    SoAd_SoConRxPduCtrlSetSocketRouteIdx(RxPduCtrlIdx,SoAd_CfgGetNumOfSocketRoute());
    SoAd_SoConRxPduCtrlSetCancelRequest(RxPduCtrlIdx,FALSE);
    SoAd_SoConRxPduCtrlSetRxBytesPending(RxPduCtrlIdx,0u);
    /* notify to close the socket connection in next main function */
    SoAd_SoConSetCloseReq(SoConIdx, SOAD_CLOSE_REQ_OFFLINE_RESET);
    SoAd_SoConCtrlSetSoConEventStateChange(SoConIdx,TRUE);
    /*Notify user with E_NOT_OK */
    pUpTpRxIndicationFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),E_OK);
}
/********************************************************************************************************************
* @brief The Api is used to handle the reception of the Tp data on the udp socket connection
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpHandleReceptionOnSoConUdp(SoAd_SoConIdType SoConIdx)
{
    PduInfoType PduInfo = { NULL_PTR, 0u }; 
    SoAd_SocketRouteIdxType SocketRouteIdx;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    SoAd_TpRxBufferIdxType TpRxBufferCfgIdx;
    
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    TpRxBufferCfgIdx = SoAd_SoConCfgGetTpRxBufferCfgIdx(SoConIdx);
    SocketRouteIdx = SoAd_SoConRxPduCtrlGetSocketRouteIdx(RxPduCtrlIdx);
    /* check if data is available */
    if (TpRxBufferCfgIdx > SoAd_TpRxBufferCfgGetTpRxBufferStartIdx(TpRxBufferCfgIdx))
    {
        while((SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx) > 0u) &&
             (SoAd_SoConRxPduCtrlGetCancelRequest(RxPduCtrlIdx) == FALSE))
        {
            if (FALSE == SoAd_RxTpHandleReceptionOnSoConUdpCopyRxData(SoConIdx, SocketRouteIdx, &PduInfo))
            {
                break;
            }
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to handle the reception of the tp data on the udp socket connection for copy data
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(boolean, SOAD_CODE) SoAd_RxTpHandleReceptionOnSoConUdpCopyRxData
(
    SoAd_SoConIdType SoConIdx,
    SoAd_SocketRouteIdxType SocketRouteIdx,
    P2VAR(PduInfoType, AUTOMATIC, SOAD_APPL_VAR) PduInfoPtr
)
{
    boolean ContinueRx=TRUE;
    PduLengthType BufferSize = 0u;
    SoAd_ULIdxType SocketRouteULIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_TpRxBufferIdxType TpRxBufferIdx;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    SoAd_TpRxBufferIdxType TpRxBufferCfgIdx;
    SoAd_UpTpCopyRxDataFuncType pUpTpCopyRxDataFunc;
    SoAd_UpTpRxIndicationFuncType pUpTpRxIndicationFunc;
    
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    TpRxBufferCfgIdx = SoAd_SoConCfgGetTpRxBufferCfgIdx(SoConIdx);
    SocketRouteIdx = SoAd_SoConRxPduCtrlGetSocketRouteIdx(RxPduCtrlIdx);
    SocketRouteULIdx = SoAd_SocketRouteCfgGetSocketRouteULIdx(SocketRouteIdx);
    pUpTpCopyRxDataFunc = SoAd_UpperLayerCfgGetUpTpCopyRxDataFunc(SocketRouteULIdx);
    pUpTpRxIndicationFunc = SoAd_UpperLayerCfgGetUpTpRxIndicationFunc(SocketRouteULIdx);
    
    if (pUpTpCopyRxDataFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),PduInfoPtr,&BufferSize) == BUFREQ_OK)
    {
        SoAd_SoConRxPduCtrlSetRxBytesPending(RxPduCtrlIdx,
                                    (SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx)-PduInfoPtr->SduLength));
        /* Check if full data received  */
        if (SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx) == 0u)
        {
            SoAd_TpRxBufferCtrlSetCurrentBufferIdx(TpRxBufferCfgIdx,
                                                   SoAd_TpRxBufferCfgGetTpRxBufferStartIdx(TpRxBufferCfgIdx));
            if (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
            {
                SoAd_SoConRxPduCtrlSetSocketRouteIdx(RxPduCtrlIdx,SoAd_CfgGetNumOfSocketRoute());
                pUpTpRxIndicationFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),E_OK);
            }
            ContinueRx = FALSE;
        }
        else if (BufferSize == 0U)
        {
            ContinueRx = FALSE;
        }
        else
        {
            /* update PduInfo for next iteration */
            PduInfoPtr->SduLength = SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx); 
            if (PduInfoPtr->SduLength > BufferSize)
            {
                PduInfoPtr->SduLength = BufferSize;
            }
            TpRxBufferIdx = SoAd_TpRxBufferCtrlGetCurrentBufferIdx(TpRxBufferCfgIdx)-
                                            SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx);
            PduInfoPtr->SduDataPtr = SoAd_CtrlGetPtrToTpRxBuffer(TpRxBufferIdx);
        }
    }
    else
    {
        /* Close socket connection in next main function. */
        SoAd_SoConSetCloseReq(SoConIdx, SOAD_CLOSE_REQ_OFFLINE_RESET); 
        SoAd_SoConCtrlSetSoConEventStateChange(SoConIdx,TRUE);
        ContinueRx = FALSE;
    }
    return ContinueRx;
}
/********************************************************************************************************************
* @brief The Api is used to handle the reception of tp data on the socket connection idx 
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpHandleReceptionOnSoConTcp(SoAd_SoConIdType SoConIdx)
{
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_RxBufferSegIdxType RxBufferSegIdx;
    
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    RxBufferSegIdx = SoAd_SoConCfgGetRxBufferSegIdx(SoConIdx);
    /* Check if received data is pending. */
    if (SoAd_RxBufferSegCtrlGetSegLevel(RxBufferSegIdx) > 0U)
    {
        if (SoAd_SoConGrpCfgIsPduHeaderSupported(SoConGrpIdx) == TRUE)
        {
            /* Handle reception for TCP socket connection with PDU header  */
            SoAd_RxTcpPduHdrRxIndication(SoConIdx, NULL_PTR, 0u);
        }
        else
        {
            /* Handle reception for TCP socket connection  */
            SoAd_RxTcpRxIndication(SoConIdx, NULL_PTR, 0u); 
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to handle the reception terminate requset for the socket connection idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_RxTpTerminateReceive(SoAd_SoConIdType SoConIdx,boolean NormalClose)
{
    Std_ReturnType RetVal=E_NOT_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_ULIdxType SocketRouteULIdx;
    SoAd_SoConRxPduCtrlIdxType RxPduCtrlIdx;
    SoAd_SocketRouteIdxType SocketRouteIdx;
    SoAd_RxBufferSegIdxType RxBufferSegIdx;
    SoAd_UpTpRxIndicationFuncType pUpTpRxIndicationFunc; 
    
    RxPduCtrlIdx = SoAd_SoConCfgGetSoConRxPduCtrlIdx(SoConIdx);
    SocketRouteIdx = SoAd_SoConRxPduCtrlGetSocketRouteIdx(RxPduCtrlIdx);
    RxBufferSegIdx = SoAd_SoConCfgGetRxBufferSegIdx(SoConIdx);
    SoConGrpIdx = SoAd_SoConCfgGetSoConGrpIdx(SoConIdx);
    /*  if TP reception is active on socket connection. */
    if (SocketRouteIdx != SoAd_CfgGetNumOfSocketRoute())
    {
        if ( NormalClose == TRUE )
        {
            if ((SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE) &&
                (SoAd_SoConRxPduCtrlGetRxBytesPending(RxPduCtrlIdx) != 0U))
            {
                /* Terminate Udp */
                RetVal = E_NOT_OK;
            }
            else if ((SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE) &&
                    (SoAd_RxBufferSegCtrlGetSegLevel(RxBufferSegIdx) != 0U))
            {
                /* Terminate Tcp */
                RetVal = E_NOT_OK;
            }
            else
            {
                RetVal = E_OK;
            }
        }
        else
        {
            /* close on reception completion*/
            RetVal = E_NOT_OK;
        }
        /* notify upper layer */
        SocketRouteULIdx = SoAd_SocketRouteCfgGetSocketRouteULIdx(SocketRouteIdx);
        pUpTpRxIndicationFunc = SoAd_UpperLayerCfgGetUpTpRxIndicationFunc(SocketRouteULIdx);
        if (pUpTpRxIndicationFunc != NULL_PTR)
        {
            pUpTpRxIndicationFunc(SoAd_SocketRouteCfgGetRxULPduId(SocketRouteIdx),RetVal);
        }
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

