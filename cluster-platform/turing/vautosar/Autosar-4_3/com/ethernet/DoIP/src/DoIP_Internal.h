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
*   @file DoIP_Internal.h
*   @ingroup DoIP
*   @brief This file provides the declaration of the DoIP internals API and data types .
********************************************************************************************************************/
#ifndef DOIP_INTERNAL_H
#define DOIP_INTERNAL_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#if (DOIP_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
#define DoIP_DetReportError(ApiId,ErrId) (void)Det_ReportError(DOIP_MODULE_ID,DOIP_INSTANCE_ID,(ApiId),(ErrId)) 
/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
/*!******************************************************************************************************************
* @brief This api is used to request closing of the socket connection
* @param[in] ConIdx the DoIP connection Idx
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_SoConClose(DoIP_ConIdxType ConIdx);
/* #! util mem copy */
/*!******************************************************************************************************************
* @brief     This Api used to copy data from source buffer to destination buffer
* @param[out] DestPtr pointer to destination buffer data
* @param[in] SrcPtr pointer to source buffer data
* @param[in] Length byte size to be copied
********************************************************************************************************************/
FUNC(void,DOIP_CODE) DoIP_UtilMemCopy
(
    P2VAR(uint8,AUTOMATIC,DOIP_APPL_DATA) DestPtr, 
    CONSTP2CONST(uint8,AUTOMATIC,DOIP_APPL_CONST) SrcPtr, 
    PduLengthType Length
);
/*!******************************************************************************************************************
* @brief  This Api used to set requested data to the destination buffer
* @param[out] DestPtr pointer to destination buffer data
* @param[in] Value value to be set
* @param[in] Length byte size to be set
********************************************************************************************************************/
FUNC(void,DOIP_CODE) DoIP_UtilMemSet
(   
    P2VAR(uint8,AUTOMATIC,DOIP_APPL_DATA) DestPtr , 
    uint8 Value , 
    PduLengthType Length
);
/* #! Udp transmit */
/*!******************************************************************************************************************
* @brief This api is used to process the udp transmit request
* @param[in] ConIdx the DoIP connection Idx
* @param[in] HeaderType the header type
* @param[in] Param the parameter value
* @param[in] CloseSocketReq the request to close socket connection
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxUdpTransmit
(
    DoIP_ConIdxType ConIdx,
    uint16 HeaderType,
    uint16 Param,
    boolean CloseSocketReq
);
/*!******************************************************************************************************************
* @brief This api is used to process the udp delayed transmit 
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_TxUdpCtrlHandler(void);
/* #! tcp tx */
/*!******************************************************************************************************************
* @brief  This api used to transmit the tcp data
* @param[in] TcpConIdx the tcp connection idx
* @param[in] HeaderType the header type
* @param[in] Param1 the first parameter
* @param[in] Param2 the second parameter
* @param[in] Param3 the third parameter
* @param[in] DataPtr the pointer to the buffer size
* @param[in] CloseSocketReq the socket connection close request
* @return status of the request BUFREQ_E_OK:request accepted BUFREQ_E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxTcpTransmit
(
    DoIP_TcpConIdxType TcpConIdx,
    uint16 HeaderType,
    uint16 Param1,
    uint16 Param2,
    uint8  Param3,
    P2VAR(uint8,AUTOMATIC,DOIP_APPL_DATA) DataPtr,
    boolean CloseSocketReq
);
/*!******************************************************************************************************************
* @brief  This api used to handle the copying of tcp tx data to the queue 
* @param[in] TcpConIdx the tcp conncetion idx
* @param[in] PduInfoPtr the pointer to the pdu info
* @param[out] AvailableDataPtr the pointer to available buffer
* @return status request BUFREQ_E_OK: request accepted BUFREQ_E_NOT_OK: request not accepted 
********************************************************************************************************************/
FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_TxTcpQueueCopy
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) AvailableDataPtr
);
/*!******************************************************************************************************************
* @brief  This api used to remove the tx element from the tcp queue
* @param[in] TcpConIdx the DoIP tcp connection Idx
* @param[in] Result the result of tcp transmit E_OK: tcp transmit success E_NOT_OK: tcp transmit failure
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_TxTcpQueueRemoveElement(DoIP_TcpConIdxType TcpConIdx, Std_ReturnType Result);
/*!******************************************************************************************************************
* @brief  This api used to handle the transmission of queue element 
* @param[in] TcpConIdx the tcp conncetion idx
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_TxTcpQueueTransmitElement(DoIP_TcpConIdxType TcpConIdx);
/*!******************************************************************************************************************
* @brief  This api used to handle the tcp queue pending transmit
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_TxTcpQueueHandleTransmit(void);
/*!******************************************************************************************************************
* @brief  This api used to complete the tcp transmit data 
* @param[in] TcpConIdx the tcp connection idx
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_TxTcpFinishTransmit(DoIP_TcpConIdxType TcpConIdx);
/*!******************************************************************************************************************
* @brief  This api used to prepare tcp data for transmission
* @param[in] TcpConIdx the tcp con idx
* @param[in] HeaderType the header type
* @param[in] Param1 the first parameter
* @param[in] Param2 the second parameter
* @param[in] Param3 the third parameter
* @param[in] CloseSocketReq the socket close request
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_TxTcpPrepareTransmit
(
    DoIP_TcpConIdxType TcpConIdx,
    uint16 HeaderType,
    uint16 Param1,
    uint16 Param2,
    uint8  Param3,
    boolean CloseSocketReq
);
/* #! udp rx */
/*!******************************************************************************************************************
* @brief  This api used to handle the reception of Udp message  
* @param[in] ConIdx the DoIP connection idx
* @param[in] PduInfoPtr the pointer to the Pdu Info
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_RxUdpHandleRxIndication
(
    DoIP_ConIdxType ConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr
);
/* #! tcp rx */
/*!******************************************************************************************************************
* @brief  This api used to handle the tcp rx data copy
* @param[in] TcpConIdx the tcp connection idx
* @param[in] PduInfoPtr the pointer to the pdu info
* @param[out] BufferSizePtr the pointer to the buffer size 
* @param[out] ErrorIdPtr the pointer to the error id
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_RxTcpHandleCopyRxDataCopy
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) ErrorIdPtr
);
/*!******************************************************************************************************************
* @brief  This api used to handle the routing activation authentication and confirmation retry
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_RxTcpRoutHandleRetryRoutingActivationAuthAndConf(void);
/*!******************************************************************************************************************
* @brief  This api used to handle the routing activation alive timeout check
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_RxTcpRoutHandleAliveCheckTimeouts(void);
/*!******************************************************************************************************************
* @brief  This api used to handle the routing activation inactivity timeouts
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_RxTcpRoutHandleInactivityTimeouts(void);
FUNC(uint8, DOIP_CODE) DoIP_UtilGetU8(P2CONST(uint8,AUTOMATIC,DOIP_APPL_CONST) pBuffer,uint32 Offset);
FUNC(uint16, DOIP_CODE) DoIP_UtilGetU16(P2CONST(uint8,AUTOMATIC,DOIP_APPL_CONST) pBuffer,uint32 Offset);
FUNC(uint32, DOIP_CODE) DoIP_UtilGetU32(P2CONST(uint8,AUTOMATIC,DOIP_APPL_CONST) pBuffer,uint32 Offset);
FUNC(void, DOIP_CODE) DOIP_UtilExtractGenericHeader
(
    P2VAR(DoIP_GenericHeaderType,AUTOMATIC,DOIP_APPL_DATA) pGenericHeader,
    P2CONST(uint8,AUTOMATIC,DOIP_APPL_DATA) pBuffer
);
#endif /* DOIP_INTERNAL_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
