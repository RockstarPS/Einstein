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
*   @file DoIP_Rx.c
*   @ingroup DoIP
*   @brief This file implements the DoIP receive functionality of udp and tcp data.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "DoIP.h"
#include "DoIP_Lcfg.h"
#include "SchM_DoIP.h"
#include "DoIP_MemMap.h"
#include "DoIP.h"
#include "PduR_DoIP.h"
#include "DoIP_Internal.h"
/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
#define DOIP_START_SEC_CODE
#include "MemMap.h"
/* #! udp rx */
/*!******************************************************************************************************************
* @brief  This api used to check the generic header validity for the udp message
* @param[in] ConIdx the DoIP connection idx
* @param[in] PduInfoPtr the pointer to the Pdu Info
* @param[out] HeaderLength the pointer to the header length 
* @param[in] DataOffset the offset of the header
* @return Header valid status E_OK: valid header E_NOT_OK: invalid header 
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxUdpCheckGenericHeader
(
    DoIP_ConIdxType ConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    P2VAR(uint32, AUTOMATIC, DOIP_APPL_VAR) HeaderLengthPtr,
    uint32 DataOffset
);
/*!******************************************************************************************************************
* @brief  This api used to handle the udp message types
* @param[in] ConIdx the DoIP connection idx
* @param[in] PduInfoPtr the pointer to the Pdu Info
* @param[in] DataOffset the offset of the message type
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxUdpHandleRxIndicationMessageTypes
(
    DoIP_ConIdxType ConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    uint32 DataOffset
);
/*!******************************************************************************************************************
* @brief  This api used to handle the udp message type vehicle identification request 
* @param[in] ConIdx the DoIP connection idx
* @param[in] PduInfoPtr the pointer to the Pdu Info
* @param[in] DataOffset the offset of the message type
* @param[in] CloseSocketReq the socket close request 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxUdpHandleVehicleIdentReq
(
    DoIP_ConIdxType ConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    uint32 DataOffset,
    boolean CloseSocketReq
);
/*!******************************************************************************************************************
* @brief  This api used to handle the udp message type vehicle identification request VIN
* @param[in] ConIdx the DoIP connection idx
* @param[in] PduInfoPtr the pointer to the Pdu Info
* @param[in] DataOffset the offset of the message type
* @param[in] CloseSocketReq the socket close request 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxUdpHandleVehicleIdentReqVin
( 
    DoIP_ConIdxType ConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    uint32 DataOffset,
    boolean CloseSocketReq
);
/*!******************************************************************************************************************
* @brief  This api used to handle the udp message type vehicle identification request EID
* @param[in] ConIdx the DoIP connection idx
* @param[in] PduInfoPtr the pointer to the Pdu Info
* @param[in] DataOffset the offset of the message type
* @param[in] CloseSocketReq the socket close request 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxUdpHandleVehicleIdentReqEid
(
    DoIP_ConIdxType ConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    uint32 DataOffset,
    boolean CloseSocketReq
);
/*!******************************************************************************************************************
* @brief  This api used to handle the udp message type Diag power mode info request
* @param[in] ConIdx the DoIP connection idx
* @param[in] PduInfoPtr the pointer to the Pdu Info
* @param[in] DataOffset the offset of the message type
* @param[in] CloseSocketReq the socket close request 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxUdpHandleDiagPowerModeInfoReq
(
    DoIP_ConIdxType ConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    uint32 DataOffset,
    boolean CloseSocketReq
);
/*!******************************************************************************************************************
* @brief  This api used to handle the udp message type Entity state request
* @param[in] ConIdx the DoIP connection idx
* @param[in] PduInfoPtr the pointer to the Pdu Info
* @param[in] DataOffset the offset of the message type
* @param[in] CloseSocketReq the socket close request 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxUdpHandleEntityStateReq
(
    DoIP_ConIdxType ConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    uint32 DataOffset,
    boolean CloseSocketReq
);
/*!******************************************************************************************************************
* @brief  This api used to handle the udp message type with unkown header type
* @param[in] ConIdx the DoIP connection idx
* @param[in] PduInfoPtr the pointer to the Pdu Info
* @param[in] DataOffset the offset of the message type
* @param[in] CloseSocketReq the socket close request 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxUdpHandleUnkownHdrType
(
    DoIP_ConIdxType ConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    uint32 DataOffset,
    boolean CloseSocketReq
);
/* #! tcp rx */
/*!******************************************************************************************************************
* @brief  This api used to handle the tcp rx copy generic header
* @param[in] TcpConIdx the tcp connection idx
* @param[in] PduInfoPtr the pointer to the pdu info
* @param[out] ReadDataLenPtr the pointer to the read data length
* @return status of the request E_OK:request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpGenCopyGenHdr
(
    DoIP_TcpConIdxType  TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr
);
/*!******************************************************************************************************************
* @brief  This api used to handle the tcp rx copy data
* @param[in] TcpConIdx the tcp connection idx
* @param[in] PduInfoPtr the pointer to the pdu info
* @param[out] BufferSizePtr the pointer to the buffer size
* @param[out] ReadDataLenPtr the pointer to the read data length
* @param[out] ErrorIdPtr the pointer to the error id
* @return status of the request BUFREQ_E_OK:request accepted BUFREQ_E_NOT_OK: request not accepted
********************************************************************************************************************/
DOIP_LOCAL FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_RxTcpHandleCopyRxDataCopyBody
(
    DoIP_TcpConIdxType  TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) ErrorIdPtr
);
/*!******************************************************************************************************************
* @brief  This api used to handle the addition of nack in copy rx data 
* @param[in] TcpConIdx the tcp connection idx
* @param[in] PduInfoPtr pointer to the pdu info
* @param[in] ReadDataLenPtr pointer to the read length data
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpHandleCopyRxDataAppendNack
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    P2CONST(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr
);
/*!******************************************************************************************************************
* @brief  This api used to handle the tcp routing activation request
* @param[in] TcpConIdx the tcp connection idx
* @param[in] PduInfoPtr pointer to the pduinfo
* @param[out] BufferSizePtr pointer to the buffer size
* @param[out] ReadDataLenPtr pointer to the read data length 
* @param[out] ErrorIdPtr pointer to the error id
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpRoutHandleRoutingActivationReq
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) ErrorIdPtr
);
/*!******************************************************************************************************************
* @brief  This api used to handle the tcp alive check response
* @param[in] TcpConIdx the tcp connection idx
* @param[in] PduInfoPtr pointer to the pduinfo
* @param[out] BufferSizePtr pointer to the buffer size
* @param[out] ReadDataLenPtr pointer to the read data length 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpAliveHandleAliveCheckRes
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr
);
/*!******************************************************************************************************************
* @brief  This api used to handle the tcp rx diag message
* @param[in] TcpConIdx the tcp connection idx
* @param[in] PduInfoPtr pointer to the pduinfo
* @param[out] BufferSizePtr pointer to the buffer size
* @param[out] ReadDataLenPtr pointer to the read data length 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpDiagHandleDiagnosticMessage
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr
);
/*!******************************************************************************************************************
* @brief  This api used to handle the tcp rx Oem payload types
* @param[in] TcpConIdx the tcp connection idx
* @param[in] PduInfoPtr pointer to the pduinfo
* @param[out] BufferSizePtr pointer to the buffer size
* @param[out] ReadDataLenPtr pointer to the read data length 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpOemHandleOemPayloadTypes
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr
);
/*!******************************************************************************************************************
* @brief  This api used to copy data to the header buffer
* @param[in] TcpConIdx the tcp connection idx
* @param[in] PduInfoPtr pointer to the pduinfo
* @param[out] ReadDataLenPtr pointer to the read data length 
* @param[in] BytesToCopy the bytes to copy
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpGenCopyDataToHeaderBuffer
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr,
    uint32 BytesToCopy
);
/*!******************************************************************************************************************
* @brief  This api used to get the tester idx from the tester address
* @param[in] TesterAddr the tester addr
* @param[out] pTesterIdx pointer to the tester idx
* @return status of the request E_OK:valid tester idx found E_NOT_OK: no tester idx found
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpRoutGetTesterIdxByTesterAddr
(
    uint16 TesterAddr,
    P2VAR(DoIP_TesterIdxType, AUTOMATIC, DOIP_APPL_VAR) pTesterIdx
);
/*!******************************************************************************************************************
* @brief  This api used to trigger the alive check response handling for the tcp con idx
* @param[in] TcpConIdx the tcp con idx
* @param[out] ErrorIdPtr pointer to the error id
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpRoutTriggerAliveCheckSingleConnection
(
    DoIP_TcpConIdxType TcpConIdx,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) ErrorIdPtr
);
/*!******************************************************************************************************************
* @brief  This api used to get the available number of the socket for this local address idx
* @param[in] LocalAddrIdx the local address idx
* @return available number of the socket number
********************************************************************************************************************/
DOIP_LOCAL FUNC(PduIdType, DOIP_CODE) DoIP_RxTcpRoutGetAvailableSockNum(DoIP_LocalAddrIdxType LocalAddrIdx);
/*!******************************************************************************************************************
* @brief  This api used to trigger alive check for all connections
* @param[in] ConIdx the doip connection idx
* @param[out] ErrorIdPtr the pointer to error idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpRoutTriggerAliveCheckAllConnections
(
    DoIP_ConIdxType ConIdx,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) ErrorIdPtr
);
/*!******************************************************************************************************************
* @brief  This api used to check if the tester is registered tester or not.
* @param[in] TcpConIdx the tcp connection idx
* @param[in] TesterIdx the tester idx
* @return status of the request E_OK:registered address E_NOT_OK:not a registered address
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpRoutCheckForRegisteredTester
(
    DoIP_TcpConIdxType TcpConIdx,
    DoIP_TesterIdxType TesterIdx
);
/*!******************************************************************************************************************
* @brief  This api used to handle the routing activation request of oem type
* @param[in] TcpConIdx the tcp connection idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpRoutHandleCopiedRoutingActivationReqOem(DoIP_TcpConIdxType TcpConIdx);
/*!******************************************************************************************************************
* @brief  This api used to get the conncetion idx for the tester
* @param[in] TesterAddr the tester address
* @return the tcp connection idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(DoIP_TcpConIdxType, DOIP_CODE) DoIP_RxTcpRoutGetConnectionIdxOfTesterAddr(uint16 TesterAddr);
/*!******************************************************************************************************************
* @brief  This api used to check for alive check response
* @param[in] ConIdx the conncetion idx
* @param[in] TesterAddr the tester address
* @param[out] ErrorIdPtr the pointer to error idx
* @return request status E_OK:alive check required E_NOT_OK: alive check not required
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpRoutCheckForAliveChecks
(
    DoIP_ConIdxType ConIdx,
    uint16 TesterAddr,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) ErrorIdPtr
);
/*!******************************************************************************************************************
* @brief  This api used to process the routing activation
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpRoutPerformRoutingActivation(void);
/*!******************************************************************************************************************
* @brief  This api used to process the routing activation authentication
* @param[out] pRoutingActivationNextState pointer to get the next activation state
* @return status request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpRoutPerformRoutingActivationAuth
(
    P2VAR(DoIP_RoutingActivationStateType, AUTOMATIC, DOIP_APPL_VAR) pRoutingActivationNextState
);
/*!******************************************************************************************************************
* @brief  This api used to process the routing activation confirmation
* @param[out] pRoutingActivationNextState pointer to get the next activation state
* @return status request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpRoutPerformRoutingActivationConf
(
    P2VAR(DoIP_RoutingActivationStateType, AUTOMATIC, DOIP_APPL_VAR) pRoutingActivationNextState
);
/*!******************************************************************************************************************
* @brief  This api used to register the tester
* @param[in] TcpConIdx the tcp con idx
* @param[in] TesterIdx the tester idx
* @param[in] TesterAddr the tester address
* @param[in] RoutingActivationIdx the routing activation idx
* @param[in] RoutingActivationNextState the routing activation next state
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpRoutRegisterTester
(
    DoIP_TcpConIdxType TcpConIdx,
    DoIP_TesterIdxType TesterIdx,
    uint16 TesterAddr,
    DoIP_RoutingActivationIdxType RoutingActivationIdx,
    DoIP_RoutingActivationStateType RoutingActivationNextState
);
/*!******************************************************************************************************************
* @brief  This api used to handle the routing activation request
* @param[in] TcpConIdx the tcp con idx
* @param[out] ErrorIdPtr pointer to the error idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpRoutHandleCopiedRoutingActivationReq
(
    DoIP_TcpConIdxType TcpConIdx,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) ErrorIdPtr
);
/*!******************************************************************************************************************
* @brief  This api used to handle the alive check response
* @param[in] TcpConIdx the tcp con idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpAliveHandleCopiedAliveCheckRes(DoIP_TcpConIdxType TcpConIdx);
/*!******************************************************************************************************************
* @brief  This api used to remove the alive check from the routing activation handler
* @param[in] TcpConIdx the tcp con idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpAliveRemoveAliveCheckFromRoutActHandler(DoIP_TcpConIdxType TcpConIdx);
/*!******************************************************************************************************************
* @brief  This api used to handle user data copy of the tcp diag message
* @param[in] TcpConIdx the tcp con idx
* @param[in] PduInfoPtr the pointer to the received pdu info
* @param[out] BufferSizePtr the pointer to the buffer size
* @param[out] ReadDataLenPtr the pointer to the read data length
* @param[in] LocalPduInfoPtr the pointer to the local pdu info
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpDiagCopyUserData
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) LocalPduInfoPtr
);
/*!******************************************************************************************************************
* @brief  This api used to handle user data copy of the tcp diag message to pdur
* @param[in] TcpConIdx the tcp con idx
* @param[out] BufferSizePtr the pointer to the buffer size
* @param[in] LocalPduInfoPtr the pointer to the local pdu info
* @return request status E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpDiagCopyDataToPduR
(
    DoIP_TcpConIdxType TcpConIdx,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_CONST) LocalPduInfoPtr
);
/*!******************************************************************************************************************
* @brief  This api used to process the received logical address
* @param[in] TcpConIdx the tcp con idx
* @return E_OK: valid logical address E_NOT_OK: invalid logical address
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpDiagHandleCopiedLogicalAddr(DoIP_TcpConIdxType TcpConIdx);
/*!******************************************************************************************************************
* @brief  This api used to process the target logical address
* @param[in] TcpConIdx the tcp con idx
* @return E_OK: valid target logical address E_NOT_OK: invalid target logical address
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpDiagHandleTargetLogicalAddress(DoIP_TcpConIdxType TcpConIdx);
/*!******************************************************************************************************************
* @brief  This api used to get the channel idx for the target address
* @param[in] TargetAddr the target address
* @return the channel idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(DoIP_ChannelIdxType, DOIP_CODE) DoIP_RxTcpDiagGetChannelByTgtAddr(uint16 TargetAddr) ;
/*!******************************************************************************************************************
* @brief  This api used to get the channel idx by the target address for the routing activation
* @param[in] RoutingActivationIdx the routing activation idx
* @param[in] TargetAddr the target address
* @param[in] DataLen the data length
* @return the channel idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(DoIP_ChannelIdxType, DOIP_CODE) DoIP_RxTcpDiagGetChannelByTgtAddrForRoutAct
(
    DoIP_RoutingActivationIdxType RoutingActivationIdx,
    uint16 TargetAddr,
    uint32 DataLen
);
/*!******************************************************************************************************************
* @brief  This api used to handle the valid diagnostic message 
* @param[in] TcpConIdx the tcp connection idx
* @param[in] PduInfoPtr the pointer to the pdu info
* @param[out] BufferSizePtr the pointer to data buffer
* @param[out] ReadDataLenPtr the pointer to the read data length
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpDiagHandleValidDiagnosticMessage
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr
);
/*!******************************************************************************************************************
* @brief  This api used to append nacka data for the rx tcp 
* @param[in] TcpConIdx the tcp connection idx
* @param[in] PduInfoPtr the pointer to the pdu info
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpDiagAppendNackData
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr
);
/*!******************************************************************************************************************
* @brief  This api used to handle verification of the rx pdu of tcp diag
* @param[in] TcpConIdx the tcp connection idx
* @param[in] PduInfoPtr the pointer to the pdu info
* @param[out] BufferSizePtr the pointer to buffer size
* @param[out] ReadDataLenPtr the pointer to read data length
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpDiagVerifyRxPdu
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr
);
/*!******************************************************************************************************************
* @brief  This api used to process the verified rx pdu of tcp diag
* @param[in] TcpConIdx the tcp connection idx
* @param[in] HeaderLength the header length
* @param[out] BufferSizePtr the pointer to buffer size
* @return request status E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpDiagHandleCopiedVerifyRxPdu
(
    DoIP_TcpConIdxType TcpConIdx,
    uint32 HeaderLength,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr
);
/*!******************************************************************************************************************
* @brief  This api used to handle the received logical address of the tcp diag
* @param[in] TcpConIdx the tcp connection idx
* @param[in] PduInfoPtr the pointer to the pdu info
* @param[out] BufferSizePtr the pointer to buffer size
* @param[out] ReadDataLenPtr the pointer to read data length
* @return request status E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpDiagCopyLogicalAddr
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr
);
#if (DOIP_OEM_PAYLOAD_TCP_BUFFER_SIZE > 0U)
/*!******************************************************************************************************************
* @brief  This api used to handle the oem payload type of the received tcp data
* @param[in] TcpConIdx the tcp connection idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpOemHandleCopiedOemPayloadTypes(DoIP_TcpConIdxType TcpConIdx);
#endif
/*!******************************************************************************************************************
* @brief  This api used to handle the routing activation alive check timeout and close socket if required
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpRoutHandleAliveCheckTimeoutsSocketsClose(void);
/*!******************************************************************************************************************
* @brief  This api used to handle the routing activation conncetion check 
* @return request status E_OK: connection available E_NOT_OK: connection not available
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpRoutCheckConnectionAvailablility(DoIP_ConIdxType ConIdx);
#define DOIP_STOP_SEC_CODE
#include "MemMap.h"
/********************************************************************************************************************
*  #! PUBLIC FUNCTION IMPLEMENTATION                                                                                *
********************************************************************************************************************/
#define DOIP_START_SEC_CODE
#include "MemMap.h"
/* #! udp rx */
/********************************************************************************************************************
* @brief  This api used to handle the reception of Udp message  
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_RxUdpHandleRxIndication
(
    DoIP_ConIdxType ConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr
)
{
    uint32 SrcHeaderLength = 0U;
    uint32 ProcessedDataOffset = 0U;
    uint8 ReqCount = 0U;
    boolean CloseSocketReq = FALSE;
    /* process the received DoIP frame */
    while (PduInfoPtr->SduLength > ProcessedDataOffset)
    {
        if (DoIP_RxUdpCheckGenericHeader(ConIdx,PduInfoPtr,&SrcHeaderLength,ProcessedDataOffset) != E_OK)
        {
            break;
        }
        ReqCount++;
        /* check for maximum amont of UDP Requests necessary to handle paralel within a single UDP connection */
        if (ReqCount <= DOIP_MAX_UDP_REQUEST_PER_MESSAGE)
        {
            DoIP_RxUdpHandleRxIndicationMessageTypes(ConIdx, PduInfoPtr, ProcessedDataOffset);
        }
        else
        {
            if ((DOIP_GENERIC_HEADER_LENGTH+SrcHeaderLength) == (PduInfoPtr->SduLength - ProcessedDataOffset))
            {
                /* Close socket if there is no pending DoIP message and no UDP alive timeout configured */
                if (DoIP_LocalAddCfgGetIsUpdAliveTimeoutEnabled(DoIP_ConCfgGetLocalIpAddrIdx(ConIdx)) == FALSE)
                {
                    CloseSocketReq = TRUE;
                }
            }
            (void)DoIP_TxUdpTransmit(ConIdx, DOIP_HEADER_TYPE_GEN_NACK, DOIP_GEN_NACK_OUT_OF_MEM, CloseSocketReq);
        }
        ProcessedDataOffset += (DOIP_GENERIC_HEADER_LENGTH+SrcHeaderLength);
    }
}
/* #! tcp rx */
/********************************************************************************************************************
* @brief  This api used to handle the tcp rx data copy
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_RxTcpHandleCopyRxDataCopy
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) ErrorIdPtr
)
{
    PduLengthType ReadDataLength = 0U;
    #if (DOIP_TCP_RX_MULTI_MSG == STD_ON)
    DoIP_TesterIdxType TesterIdx;
    #endif
    
    if (DoIP_TcpConCtrlGetRoutingActivationState(TcpConIdx) == DOIP_ROUTING_ACTIVATION_STATE_ACTIVATED)
    {
        DoIP_TcpConCtrlSetInactiveTimeCount(TcpConIdx,0U);
    }
    
    /* Copy data */
    do
    {
        if (DoIP_RxTcpGenCopyGenHdr(TcpConIdx, PduInfoPtr, &ReadDataLength) == E_OK)
        {
            /* Copy body data */
            if (DoIP_RxTcpHandleCopyRxDataCopyBody(TcpConIdx, PduInfoPtr, BufferSizePtr, &ReadDataLength,ErrorIdPtr) == BUFREQ_E_NOT_OK )
            {
                break;
            }
        }
        else
        {
            /* update buffer size. */
            *BufferSizePtr = (PduLengthType) (DOIP_GENERIC_HEADER_LENGTH - DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx));
            DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx,*BufferSizePtr);
        }
    }while(PduInfoPtr->SduLength > ReadDataLength);
    
    /* Block buffer if message is not processed completely. */
    if (DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx) == 0U )
    {
        #if (DOIP_TCP_RX_MULTI_MSG == STD_ON)
        TesterIdx = DoIP_TcpConCtrlGetTesterIdx(TcpConIdx);
        if ((TesterIdx != DoIP_CfgGetNumOfTester()) && (DoIP_TesterCfgGetNumOfDiagAckNackRespBytes(TesterIdx) > 0U))
        {
            if (DoIP_TesterCtrlGetNegativeAckOffset(TesterIdx) > 0U)
            {
                /* Do not accept new data until acknowledge is pending (if enabled). */
                *BufferSizePtr = 0U;
                DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx, 0U); 
            }
        }
        else
        {
            /* Update buffer size for previously received user data */
            *BufferSizePtr = DOIP_GENERIC_HEADER_LENGTH; 
            DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx, DOIP_GENERIC_HEADER_LENGTH);
        }
        #else
        *BufferSizePtr = 0U;
        DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx,0U);
        #endif
    } 
    else if (DoIP_TcpConCtrlGetTxTcpCtrlQueueLevel(TcpConIdx) >= DoIP_TcpConCfgGetTcpTxQueueElementSize(TcpConIdx))
    { 
        /* Queue full */
        *BufferSizePtr = 0U;
        DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx,0U);
    }
    else if ((DoIP_TcpConCtrlGetRoutingActivationState(TcpConIdx) == DOIP_ROUTING_ACTIVATION_STATE_AUTH_PENDING) ||
            (DoIP_TcpConCtrlGetRoutingActivationState(TcpConIdx) == DOIP_ROUTING_ACTIVATION_STATE_CONF_PENDING))
    { 
        /* activation state is pending */
        *BufferSizePtr = 0U;
        DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx,0U);
    }
    else
    {
        /* Do Nothing */
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the routing activation authentication and confirmation retry
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_RxTcpRoutHandleRetryRoutingActivationAuthAndConf(void)
{
    DoIP_TcpConIdxType TcpConIdx;
    uint16 TesterAddr;
    DoIP_TesterIdxType TesterIdx;
    DoIP_RoutingActivationIdxType TcpRoutingActivationIdx;
    DoIP_RoutingActivationStateType LastState;
    DoIP_RoutingActivationStateType NextState=DOIP_ROUTING_ACTIVATION_STATE_NONE;
    TcpConIdx = DoIP_RoutingActivationCtrlGetTcpConIdx();
    if((TcpConIdx != DoIP_CfgGetNumOfTcpConnection()) && (DoIP_RoutingActivationCtrlGetAliveCheckCount() == 0u))
    {
        TesterAddr = DoIP_TcpConCtrlGetTesterAddr(TcpConIdx);
        TesterIdx = DoIP_TcpConCtrlGetTesterIdx(TcpConIdx);
        LastState = DoIP_TcpConCtrlGetRoutingActivationState(TcpConIdx);
        TcpRoutingActivationIdx = DoIP_TcpConCtrlGetRoutingActivationIdx(TcpConIdx);
        if (LastState == DOIP_ROUTING_ACTIVATION_STATE_AUTH_PENDING)
        {
            /* do authentication if auth pending */
            (void)DoIP_RxTcpRoutPerformRoutingActivationAuth(&NextState);  
        }
        if ((LastState == DOIP_ROUTING_ACTIVATION_STATE_CONF_PENDING) ||
            ((NextState == DOIP_ROUTING_ACTIVATION_STATE_ACTIVATED) && 
            (DoIP_RoutingActivationCfgGetpConfCallbackFn(TcpRoutingActivationIdx) != NULL_PTR)))
        {
            (void)DoIP_RxTcpRoutPerformRoutingActivationConf(&NextState);
        }
        
        if (NextState == DOIP_ROUTING_ACTIVATION_STATE_ACTIVATED )
        {
            DoIP_TesterCtrlSetTcpConIdx(TesterIdx,TcpConIdx);
            DoIP_TcpConCtrlSetRoutingActivationState(TcpConIdx,DOIP_ROUTING_ACTIVATION_STATE_ACTIVATED);
            
            if (LastState != DOIP_ROUTING_ACTIVATION_STATE_CONF_PENDING)
            {
                DoIP_TcpConCtrlSetInactiveTimeCount(TcpConIdx,0u);
                /* send routing activ response */
                (void)DoIP_TxTcpTransmit(TcpConIdx, DOIP_HEADER_TYPE_ROUT_ACTIV_RES,TesterAddr,
                                            DOIP_ROUT_ACTIV_RES_CODE_SUCCESS,TesterIdx,NULL_PTR,FALSE);
            }
            else
            {
                /* Release routing activation handler if activated after confirmation was pending. */
                DoIP_RoutingActivationCtrlSetTcpConIdx(DoIP_CfgGetNumOfTcpConnection());
            }
        }
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the alive check timeouts
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_RxTcpRoutHandleAliveCheckTimeouts(void)
{
    DoIP_TcpConIdxType TcpConIdx;
    TcpConIdx = DoIP_RoutingActivationCtrlGetTcpConIdx();
    
    if (TcpConIdx != DoIP_CfgGetNumOfTcpConnection())
    {
        if (DoIP_RoutingActivationCtrlGetAliveCheckCount() > 0u)
        {
            DoIP_RoutingActivationCtrlDecAliveCheckCount();
            if (DoIP_RoutingActivationCtrlGetAliveCheckCount() == 0u)
            {
                DoIP_RxTcpRoutHandleAliveCheckTimeoutsSocketsClose();
                if ( DoIP_RxTcpRoutCheckConnectionAvailablility(TcpConIdx) == E_OK )
                {
                    /*Continue with received routing activation request if there is a free connection. */
                    DoIP_RxTcpRoutPerformRoutingActivation();
                }
            }
        }
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the routing activation inactivity timeouts
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_RxTcpRoutHandleInactivityTimeouts(void)
{
    DoIP_TcpConIdxType TcpConIdx;
    for (TcpConIdx = 0u; TcpConIdx < DoIP_CfgGetNumOfTcpConnection();TcpConIdx++)
    {
        if (DoIP_ConCtrlGetSoConMode(TcpConIdx) == SOAD_SOCON_ONLINE)
        {
            if (DoIP_TcpConCtrlGetRoutingActivationState(TcpConIdx) != DOIP_ROUTING_ACTIVATION_STATE_ACTIVATED)
            {
                if (DoIP_TcpConCtrlGetInactiveTimeCount(TcpConIdx) == DOIP_INITIAL_INACTIVITY_TIME)
                {
                    /* Close socket after inital timeout if no routing is activated. */
                    DoIP_SoConClose(TcpConIdx);
                }
            }
            else
            {
                if (DoIP_TcpConCtrlGetInactiveTimeCount(TcpConIdx) == DOIP_INITIAL_INACTIVITY_TIME )
                {
                    /* Close socket after general timeout if routing is activated. */
                    DoIP_SoConClose(TcpConIdx);
                }
            }
            DoIP_TcpConCtrlIncInactiveTimeCount(TcpConIdx);
        }
    }
}

/********************************************************************************************************************
*  #! PRIVATE FUNCTION IMPLEMENTATION                                                                               *
********************************************************************************************************************/
/* #! udp Rx */
/********************************************************************************************************************
* @brief  This api used to check the generic header validity for the udp message
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxUdpCheckGenericHeader
(
    DoIP_ConIdxType ConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    P2VAR(uint32, AUTOMATIC, DOIP_APPL_VAR) HeaderLengthPtr,
    uint32 DataOffset
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    DoIP_GenericHeaderType GenericHeader={0};
    
    if ((PduInfoPtr->SduLength - DataOffset) < DOIP_GENERIC_HEADER_LENGTH)
    {
        DoIP_SoConClose(ConIdx);
    }
    else
    {
        /* process Header data */
        DOIP_UtilExtractGenericHeader(&GenericHeader,(uint8 *)&PduInfoPtr->SduDataPtr[DataOffset]);
        *HeaderLengthPtr = GenericHeader.HeaderLength;
        if (((GenericHeader.HeaderVersion != DOIP_PROTOCOL_VERSION_2012) ||
            (GenericHeader.HeaderInvVersion != DOIP_PROTOCOL_INV_VERSION_2012)) &&
            ((GenericHeader.HeaderVersion != DOIP_PROTOCOL_VERSION_DEFAULT) ||
             (GenericHeader.HeaderInvVersion != DOIP_PROTOCOL_INV_VERSION_DEFAULT) ||
             (GenericHeader.HeaderType < DOIP_HEADER_TYPE_VEHICLE_IDENT_REQ) ||
             (GenericHeader.HeaderType > DOIP_HEADER_TYPE_VEHICLE_IDENT_REQ_VIN)))
        {
            (void)DoIP_TxUdpTransmit(ConIdx,DOIP_HEADER_TYPE_GEN_NACK,DOIP_GEN_NACK_FORMAT,TRUE);
        }
        else if ((DOIP_GENERIC_HEADER_LENGTH + GenericHeader.HeaderLength) > (PduInfoPtr->SduLength - DataOffset))
        {
            /* invalid data length NACK */
            (void)DoIP_TxUdpTransmit(ConIdx,DOIP_HEADER_TYPE_GEN_NACK,DOIP_GEN_NACK_INV_LEN,TRUE); 
        }
        else
        {
            RetVal = E_OK;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to handle the udp message types
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxUdpHandleRxIndicationMessageTypes
(
    DoIP_ConIdxType ConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    uint32 DataOffset
)
{
    boolean CloseSocketReq = FALSE;
    DoIP_GenericHeaderType GenericHeader={0};
    /* process Header data */
    DOIP_UtilExtractGenericHeader(&GenericHeader,(uint8 *)&PduInfoPtr->SduDataPtr[DataOffset]);
    if ((GenericHeader.HeaderLength + DOIP_GENERIC_HEADER_LENGTH) == (PduInfoPtr->SduLength - DataOffset))
    {
        /* Close socket if there is no pending DoIP message and no UDP alive timeout configured */
        if (DoIP_LocalAddCfgGetIsUpdAliveTimeoutEnabled(DoIP_ConCfgGetLocalIpAddrIdx(ConIdx)) == FALSE)
        {
            CloseSocketReq = TRUE;
        }
    }
    /* process Header Type */
    switch(GenericHeader.HeaderType)
    {
        case DOIP_HEADER_TYPE_VEHICLE_IDENT_REQ: 
            DoIP_RxUdpHandleVehicleIdentReq(ConIdx, PduInfoPtr, DataOffset, CloseSocketReq);
            break;
        case DOIP_HEADER_TYPE_VEHICLE_IDENT_REQ_VIN:
            DoIP_RxUdpHandleVehicleIdentReqVin(ConIdx, PduInfoPtr, DataOffset, CloseSocketReq);
            break;
        case DOIP_HEADER_TYPE_VEHICLE_IDENT_REQ_EID: 
            DoIP_RxUdpHandleVehicleIdentReqEid(ConIdx, PduInfoPtr, DataOffset, CloseSocketReq);
            break;
        case DOIP_HEADER_TYPE_DIAG_POWER_MODE_INFO_REQ: 
            DoIP_RxUdpHandleDiagPowerModeInfoReq(ConIdx, PduInfoPtr, DataOffset, CloseSocketReq);
            break;
        case DOIP_HEADER_TYPE_ENTITY_STATE_REQ:
            DoIP_RxUdpHandleEntityStateReq(ConIdx, PduInfoPtr, DataOffset, CloseSocketReq);
            break;
        case DOIP_HEADER_TYPE_GEN_NACK: 
        case DOIP_HEADER_TYPE_VEHICLE_ANNOUNCEMENT: 
        case DOIP_HEADER_TYPE_ROUT_ACTIV_REQ: 
        case DOIP_HEADER_TYPE_ROUT_ACTIV_RES: 
        case DOIP_HEADER_TYPE_ALIVE_CHECK_REQ: 
        case DOIP_HEADER_TYPE_ALIVE_CHECK_RES: 
        case DOIP_HEADER_TYPE_ENTITY_STATE_RES: 
        case DOIP_HEADER_TYPE_DIAG_POWER_MODE_INFO_RES:
        case DOIP_HEADER_TYPE_DIAG_REQ: 
        case DOIP_HEADER_TYPE_DIAG_ACK: 
        case DOIP_HEADER_TYPE_DIAG_NACK:
            /* close socket as invalid header seq received */
            DoIP_SoConClose(ConIdx); 
            break;
        default:
            /* Nack: unknown header type */
            DoIP_RxUdpHandleUnkownHdrType(ConIdx, PduInfoPtr, DataOffset, CloseSocketReq);       
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the udp message type vehicle identification request 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxUdpHandleVehicleIdentReq
(
    DoIP_ConIdxType ConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    uint32 DataOffset,
    boolean CloseSocketReq
)
{
    DoIP_GenericHeaderType GenericHeader={0};
    /* process Header data */
    DOIP_UtilExtractGenericHeader(&GenericHeader,(uint8 *)&PduInfoPtr->SduDataPtr[DataOffset]);
    if (GenericHeader.HeaderLength > DOIP_MAX_REQUEST_BYTES)
    {
        /* Send Nack if max message length exceeded. */
        (void)DoIP_TxUdpTransmit(ConIdx, DOIP_HEADER_TYPE_GEN_NACK, DOIP_GEN_NACK_MAX_LEN, CloseSocketReq);
    }
    else if(GenericHeader.HeaderLength != 0U)
    {
        /* Send Nack if header length check failed. */
        (void)DoIP_TxUdpTransmit(ConIdx, DOIP_HEADER_TYPE_GEN_NACK, DOIP_GEN_NACK_INV_LEN, CloseSocketReq);
    }
    else
    {
        /* Otherwise send vehicle identification response. */
        (void)DoIP_TxUdpTransmit(ConIdx, DOIP_HEADER_TYPE_VEHICLE_ANNOUNCEMENT,DOIP_IDENT_RES_NUM, CloseSocketReq);
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the udp message type vehicle identification request VIN
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxUdpHandleVehicleIdentReqVin
( 
    DoIP_ConIdxType ConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    uint32 DataOffset,
    boolean CloseSocketReq
)
{
    uint8 VinIdx;
    boolean IsVinIdCheckOk = TRUE;
    uint8 VinBuffer[DOIP_VIN_LENGTH] = {0U};
    DoIP_GenericHeaderType GenericHeader={0};
    /* process Header data */
    DOIP_UtilExtractGenericHeader(&GenericHeader,(uint8 *)&PduInfoPtr->SduDataPtr[DataOffset]);
    if (GenericHeader.HeaderLength > DOIP_MAX_REQUEST_BYTES )
    {
        /* Send Nack if max message length exceeded. */
        (void)DoIP_TxUdpTransmit(ConIdx, DOIP_HEADER_TYPE_GEN_NACK, DOIP_GEN_NACK_MAX_LEN,CloseSocketReq);
    }
    else if (GenericHeader.HeaderLength != DOIP_VIN_LENGTH )
    {
        /* Send Nack if header length check failed. */
        (void)DoIP_TxUdpTransmit(ConIdx, DOIP_HEADER_TYPE_GEN_NACK, DOIP_GEN_NACK_INV_LEN,CloseSocketReq);              
    }
    else
    {
        if (DoIP_CfgGetUserGetVinCallbackFn(&VinBuffer[0]) == E_OK)
        {
            /* Compare VIN to retrieved VIN . */
            for (VinIdx = 0U;VinIdx < DOIP_VIN_LENGTH;VinIdx++ )
            {
                if (PduInfoPtr->SduDataPtr[DataOffset+DOIP_GENERIC_HEADER_LENGTH+VinIdx] != VinBuffer[VinIdx])
                {
                    IsVinIdCheckOk = FALSE;
                    break;
                }
            }
        }
        else
        {
            /* compare VIN to invalid pattern. */
            for (VinIdx = 0U; VinIdx < DOIP_VIN_LENGTH;VinIdx++)
            {
                if (PduInfoPtr->SduDataPtr[DataOffset+DOIP_GENERIC_HEADER_LENGTH+VinIdx] != DOIP_VIN_INVALIDITY_PATTERN)
                {
                    IsVinIdCheckOk = FALSE;
                    break;
                }
            }
        }
        
        if(IsVinIdCheckOk == TRUE)
        {
            /* Send vehicle identification response if VIN check passed. */
            (void)DoIP_TxUdpTransmit(ConIdx, DOIP_HEADER_TYPE_VEHICLE_ANNOUNCEMENT, 
                                        DOIP_IDENT_RES_NUM, CloseSocketReq);
        }
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the udp message type vehicle identification request EID
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxUdpHandleVehicleIdentReqEid
(
    DoIP_ConIdxType ConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    uint32 DataOffset,
    boolean CloseSocketReq
)
{
    uint8 EidIdx;
    boolean IsEidCheckOk = TRUE;
    DoIP_GenericHeaderType GenericHeader={0};
    #if (DOIP_USE_MAC_ADDRESS_FOR_IDENTIFICATION == STD_ON)
    uint8 PhyAddrBuffer[DOIP_PHYS_ADDR_LENGTH]={0};
    #endif
    /* process Header data */
    DOIP_UtilExtractGenericHeader(&GenericHeader,(uint8 *)&PduInfoPtr->SduDataPtr[DataOffset]);
    if (GenericHeader.HeaderLength > DOIP_MAX_REQUEST_BYTES)
    {
        /* Send Nack if max message length exceeded. */
        (void)DoIP_TxUdpTransmit(ConIdx, DOIP_HEADER_TYPE_GEN_NACK, DOIP_GEN_NACK_MAX_LEN, CloseSocketReq); 
    }
    else if (GenericHeader.HeaderLength != DOIP_PHYS_ADDR_LENGTH)
    {
        /* Send Nack if header length check failed. */
        (void)DoIP_TxUdpTransmit(ConIdx, DOIP_HEADER_TYPE_GEN_NACK, DOIP_GEN_NACK_INV_LEN, CloseSocketReq);
    }
    else
    {
        #if (DOIP_USE_MAC_ADDRESS_FOR_IDENTIFICATION == STD_ON)
        /* Get mac address for SoAd */
        if (SoAd_GetPhyAddr(DoIP_ConCtrlGetSoConIdx(ConIdx),&PhyAddrBuffer[0]) == E_OK)
        {
            for(EidIdx = 0U; EidIdx < DOIP_PHYS_ADDR_LENGTH; EidIdx++)
            {
                /* Compare retrieved mac address with received data. */
                if (PduInfoPtr->SduDataPtr[DataOffset+DOIP_GENERIC_HEADER_LENGTH+EidIdx] != PhyAddrBuffer[EidIdx])
                {
                    IsEidCheckOk = FALSE;
                    break;
                }
            }
        }
        else
        {
            IsEidCheckOk = FALSE;
        }
        #else
        for (EidIdx = 0U; EidIdx < DOIP_PHYS_ADDR_LENGTH; EidIdx++)
        {
            /* Compare configured EID with received data. */
            if (PduInfoPtr->SduDataPtr[DataOffset+DOIP_GENERIC_HEADER_LENGTH+EidIdx] != DoIP_CfgEid[EidIdx])
            {
                IsEidCheckOk = FALSE;
                break;
            }
        }
        #endif
        if (IsEidCheckOk == TRUE)
        {
            /* Send vehicle identification response if EID check passed. */
            (void)DoIP_TxUdpTransmit(ConIdx,DOIP_HEADER_TYPE_VEHICLE_ANNOUNCEMENT,DOIP_IDENT_RES_NUM,CloseSocketReq);
        }
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the udp message type Diag power mode info request
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxUdpHandleDiagPowerModeInfoReq
(
    DoIP_ConIdxType ConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    uint32 DataOffset,
    boolean CloseSocketReq
)
{
    DoIP_GenericHeaderType GenericHeader={0};
    /* process Header data */
    DOIP_UtilExtractGenericHeader(&GenericHeader,(uint8 *)&PduInfoPtr->SduDataPtr[DataOffset]);
    if (GenericHeader.HeaderLength > DOIP_MAX_REQUEST_BYTES)
    {
        /* Send Nack if max message length exceeded. */
        (void)DoIP_TxUdpTransmit(ConIdx, DOIP_HEADER_TYPE_GEN_NACK, DOIP_GEN_NACK_MAX_LEN, CloseSocketReq);
    }
    else if (GenericHeader.HeaderLength != 0U)
    {
        /* Send Nack if header length check failed. */
        (void)DoIP_TxUdpTransmit(ConIdx, DOIP_HEADER_TYPE_GEN_NACK, DOIP_GEN_NACK_INV_LEN, CloseSocketReq);
    }
    else
    {
        DoIP_PowerStateType PowerState = DOIP_NOT_SUPPORTED;
        
        if (DoIP_CfgUserGetPowerModeCallbackFn(&PowerState) == E_NOT_OK)
        {
            PowerState = DOIP_NOT_READY;
        }
        /* Send diagnostic power mode response. */
        (void)DoIP_TxUdpTransmit(ConIdx,DOIP_HEADER_TYPE_DIAG_POWER_MODE_INFO_RES,PowerState,CloseSocketReq);
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the udp message type Entity state request
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxUdpHandleEntityStateReq
(
    DoIP_ConIdxType ConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    uint32 DataOffset,
    boolean CloseSocketReq
)
{
    DoIP_GenericHeaderType GenericHeader={0};
    /* process Header data */
    DOIP_UtilExtractGenericHeader(&GenericHeader,(uint8 *)&PduInfoPtr->SduDataPtr[DataOffset]);    
    if (GenericHeader.HeaderLength > DOIP_MAX_REQUEST_BYTES)
    {
        /* Send Nack if max message length exceeded. */
        (void)DoIP_TxUdpTransmit(ConIdx, DOIP_HEADER_TYPE_GEN_NACK, DOIP_GEN_NACK_MAX_LEN, CloseSocketReq);
    }
    else if (GenericHeader.HeaderLength != 0U)
    {
        /* Send Nack if header length check failed. */
        (void)DoIP_TxUdpTransmit(ConIdx, DOIP_HEADER_TYPE_GEN_NACK, DOIP_GEN_NACK_INV_LEN, CloseSocketReq);
    }
    else
    {
        /* Otherwise send entity state response. */
        (void)DoIP_TxUdpTransmit(ConIdx, DOIP_HEADER_TYPE_ENTITY_STATE_RES, DOIP_UNUSED_PARAM, CloseSocketReq);
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the udp message type with unkown header type
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxUdpHandleUnkownHdrType
(
    DoIP_ConIdxType ConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    uint32 DataOffset,
    boolean CloseSocketReq
)
{
#if ( DOIP_OEM_PAYLOAD_TYPE_ENABLED == STD_ON )
    uint16 TxHeaderType;
    PduInfoType RxUserPduInfo;
    PduInfoType TxUserPduInfo;
    DoIP_GenericHeaderType GenericHeader={0};
#endif

#if ( DOIP_OEM_PAYLOAD_TYPE_ENABLED == STD_ON )
    /* process Header data */
    DOIP_UtilExtractGenericHeader(&GenericHeader,(uint8 *)&PduInfoPtr->SduDataPtr[DataOffset]);
    /* update pduinfo */
    RxUserPduInfo.SduLength = GenericHeader.HeaderLength;
    if (GenericHeader.HeaderLength == 0U)
    {
        RxUserPduInfo.SduDataPtr = NULL_PTR;
    }
    else
    {
        RxUserPduInfo.SduDataPtr = &PduInfoPtr->SduDataPtr[DataOffset+DOIP_GENERIC_HEADER_LENGTH];
    }
   
    if (DoIP_OemPayloadCtrlGetUdpBufferLength() == 0U)
    {
        TxHeaderType = DOIP_HEADER_TYPE_INVALID;
        /* Update user data pduinfo */
        TxUserPduInfo.SduDataPtr = &DoIP_OemPayloadUdpBuffer[0];
        TxUserPduInfo.SduLength = DOIP_OEM_PAYLOAD_UDP_BUFFER_SIZE;
        /* copy data from upper layer */
        if (E_NOT_OK == DoIP_UserGetPayloadCallbackFn(GenericHeader.HeaderType,&RxUserPduInfo,
                            DOIP_OEM_PAYLOAD_TYPE_PROT_UDP,&TxHeaderType,&TxUserPduInfo))
        {
            /* Send Nack */
            (void)DoIP_TxUdpTransmit(ConIdx, DOIP_HEADER_TYPE_GEN_NACK, DOIP_GEN_NACK_TYPE, CloseSocketReq);
        }
        else
        {
            /* Send user data response */
            if (TxHeaderType != DOIP_HEADER_TYPE_INVALID)
            {
                if (TxUserPduInfo.SduLength <= DOIP_OEM_PAYLOAD_UDP_BUFFER_SIZE)
                {
                    DoIP_OemPayloadCtrlSetUdpBufferLength(TxUserPduInfo.SduLength + DOIP_GENERIC_HEADER_LENGTH);
                    (void)DoIP_TxUdpTransmit(ConIdx, DOIP_HEADER_TYPE_OEM_SPECIFIC, TxHeaderType, CloseSocketReq);
                }
            }
        }
    }
    else
    {
        /* Otherwise send Nack , no buffer available */
        (void)DoIP_TxUdpTransmit(ConIdx, DOIP_HEADER_TYPE_GEN_NACK, DOIP_GEN_NACK_OUT_OF_MEM, CloseSocketReq);
    }
#else
    /* Send general Nack (if OEM payload type not enabled) */
    (void)DoIP_TxUdpTransmit(ConIdx, DOIP_HEADER_TYPE_GEN_NACK, DOIP_GEN_NACK_TYPE, CloseSocketReq); 
    DOIP_DUMMY_STATEMENT_CONST_VAR(PduInfoPtr); 
    DOIP_DUMMY_STATEMENT_CONST_VAR(DataOffset); 
#endif
}
/* #! tcp rx */

/********************************************************************************************************************
* @brief  This api used to handle the tcp rx copy generic header
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpGenCopyGenHdr
(
    DoIP_TcpConIdxType  TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr
)
{
    uint32 BytesToCopy;
    Std_ReturnType RetVal = E_NOT_OK;
    DoIP_TcpRxBufferIdxType RxMsgOffset;
    
    /* copy generic header */
    RxMsgOffset = DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx);
    if (RxMsgOffset < DOIP_GENERIC_HEADER_LENGTH)
    {
        BytesToCopy = PduInfoPtr->SduLength;
        DoIP_UtilMemCopy(&DoIP_RxHeaderBuffer[DoIP_TcpConCfgGetRxHeaderBufferStartIdx(TcpConIdx)+RxMsgOffset],
                         &PduInfoPtr->SduDataPtr[*ReadDataLenPtr],BytesToCopy);
        RxMsgOffset += BytesToCopy;
        *ReadDataLenPtr +=BytesToCopy;
        DoIP_TcpConCtrlSetRxMsgOffset(TcpConIdx,RxMsgOffset);
    }
    
    if (RxMsgOffset >= DOIP_GENERIC_HEADER_LENGTH)
    {
        RetVal = E_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to handle the tcp rx copy data
********************************************************************************************************************/
DOIP_LOCAL FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_RxTcpHandleCopyRxDataCopyBody
(
    DoIP_TcpConIdxType  TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) ErrorIdPtr
)
{
    BufReq_ReturnType RetVal = BUFREQ_OK;
    DoIP_TcpRxBufferIdxType RxMsgOffset;
    DoIP_GenericHeaderType GenericHeader={0};
    
    RxMsgOffset = DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx);
    /* copy generic header */
    DOIP_UtilExtractGenericHeader(&GenericHeader,
                                &DoIP_RxHeaderBuffer[DoIP_TcpConCfgGetRxHeaderBufferStartIdx(TcpConIdx)]);
    /* check for header verion */
    if ((GenericHeader.HeaderVersion != DOIP_PROTOCOL_VERSION_2012) || 
        (GenericHeader.HeaderInvVersion != DOIP_PROTOCOL_INV_VERSION_2012))
    {
        (void)DoIP_TxTcpTransmit(TcpConIdx,DOIP_HEADER_TYPE_GEN_NACK,DOIP_GEN_NACK_FORMAT,0U,0U,NULL_PTR,TRUE);
    }
    else
    {
        /* check if Routing activation's TcpConIdx  is not set */
        if ((GenericHeader.HeaderType == DOIP_HEADER_TYPE_ROUT_ACTIV_REQ) &&
            (DoIP_RoutingActivationCtrlGetTcpConIdx () != DoIP_CfgGetNumOfTcpConnection()))
        {
            *BufferSizePtr = 0U;
            DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx,0U);
            RetVal = BUFREQ_E_NOT_OK;
        }
        else
        {
            /* check for msg skip */
            if (DoIP_TcpConCtrlGetRxSkipMsg(TcpConIdx) == TRUE)
            {
                /* Append Nack data (if enabled). */
                DoIP_RxTcpHandleCopyRxDataAppendNack(TcpConIdx,PduInfoPtr,ReadDataLenPtr);
                if (((DOIP_GENERIC_HEADER_LENGTH+GenericHeader.HeaderLength)-RxMsgOffset) > 
                                                                (PduInfoPtr->SduLength - *ReadDataLenPtr))
                {
                    uint32 BufferSize = (DOIP_GENERIC_HEADER_LENGTH+GenericHeader.HeaderLength)-RxMsgOffset;
                    RxMsgOffset += (PduInfoPtr->SduLength - *ReadDataLenPtr);
                    /* check for max request bytes */
                    if (BufferSize > DOIP_MAX_REQUEST_BYTES)
                    {
                        *BufferSizePtr = DOIP_MAX_REQUEST_BYTES;
                    }
                    else
                    {
                        *BufferSizePtr = BufferSize;
                    }
                    /* update read length */
                    *ReadDataLenPtr = PduInfoPtr->SduLength;
                    DoIP_TcpConCtrlSetRxMsgOffset(TcpConIdx,RxMsgOffset);
                    DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx,*BufferSizePtr);
                }
                else
                {
                    DoIP_TxTcpFinishTransmit(TcpConIdx);
                    /* Reset TcpCon Rx status */    
                    *BufferSizePtr = 0U;
                    *ReadDataLenPtr = PduInfoPtr->SduLength;
                    DoIP_TcpConCtrlSetRxMsgOffset(TcpConIdx,0U);
                    DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx,0U);
                    DoIP_TcpConCtrlSetRxSkipMsg(TcpConIdx,FALSE);
               
                }
            }
            else
            {
                /* Handle message based on Header type */
                switch(GenericHeader.HeaderType)
                {
                    case DOIP_HEADER_TYPE_ROUT_ACTIV_REQ:
                        DoIP_RxTcpRoutHandleRoutingActivationReq(TcpConIdx, PduInfoPtr, BufferSizePtr, ReadDataLenPtr,ErrorIdPtr);
                        break;
                    case DOIP_HEADER_TYPE_ALIVE_CHECK_RES:
                        DoIP_RxTcpAliveHandleAliveCheckRes(TcpConIdx, PduInfoPtr, BufferSizePtr, ReadDataLenPtr);
                        break;
                    case DOIP_HEADER_TYPE_DIAG_REQ:
                        DoIP_RxTcpDiagHandleDiagnosticMessage(TcpConIdx, PduInfoPtr, BufferSizePtr, ReadDataLenPtr);
                        break;
                    case DOIP_HEADER_TYPE_GEN_NACK:
                    case DOIP_HEADER_TYPE_VEHICLE_IDENT_REQ:
                    case DOIP_HEADER_TYPE_VEHICLE_IDENT_REQ_EID:
                    case DOIP_HEADER_TYPE_VEHICLE_IDENT_REQ_VIN:
                    case DOIP_HEADER_TYPE_VEHICLE_ANNOUNCEMENT:
                    case DOIP_HEADER_TYPE_ROUT_ACTIV_RES:
                    case DOIP_HEADER_TYPE_ALIVE_CHECK_REQ:
                    case DOIP_HEADER_TYPE_ENTITY_STATE_REQ:
                    case DOIP_HEADER_TYPE_ENTITY_STATE_RES:
                    case DOIP_HEADER_TYPE_DIAG_POWER_MODE_INFO_REQ:
                    case DOIP_HEADER_TYPE_DIAG_POWER_MODE_INFO_RES:
                    case DOIP_HEADER_TYPE_DIAG_ACK:
                    case DOIP_HEADER_TYPE_DIAG_NACK:
                        /* skip message as it is not relevant payload type */
                        DoIP_TcpConCtrlSetRxSkipMsg(TcpConIdx,TRUE);
                        break;
                    default:
                    { 
                        /* unknown payload type, check for OEM payload type */
                        #if ( DOIP_OEM_PAYLOAD_TYPE_ENABLED == STD_ON )
                        DoIP_RxTcpOemHandleOemPayloadTypes(TcpConIdx, PduInfoPtr, BufferSizePtr, ReadDataLenPtr);
                        #else
                        /* Send error if payload type are unkown. */
                        DoIP_TcpConCtrlSetRxSkipMsg(TcpConIdx,TRUE);
                        (void)DoIP_TxTcpTransmit(TcpConIdx,DOIP_HEADER_TYPE_GEN_NACK, DOIP_GEN_NACK_TYPE, 0U, 0U, NULL_PTR, FALSE);
                        #endif
                        break;
                    }
                } /* switch(GenericHeader.HeaderType) */
            }
            
            /* Set buffer size to receive entire message in next function call if message shall be skipped. */
            if (DoIP_TcpConCtrlGetRxSkipMsg(TcpConIdx) == TRUE )
            {
                uint32 BufferSize = ((DOIP_GENERIC_HEADER_LENGTH + GenericHeader.HeaderLength) - 
                                                                DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx));
                /* update BufferSize */
                if (BufferSize > DOIP_MAX_REQUEST_BYTES)
                {
                    *BufferSizePtr = DOIP_MAX_REQUEST_BYTES;
                }
                else
                {
                    *BufferSizePtr = BufferSize;
                }
                DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx,*BufferSizePtr);
            }
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to handle the addition of nack in copy rx data 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpHandleCopyRxDataAppendNack
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    P2CONST(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr
)
{
    uint16 HeaderType;
    uint8 * pHeaderBuffer;
    DoIP_TesterIdxType TesterIdx;
    PduLengthType NegativeAckOffset;
    PduLengthType NumOfNegAckByte;
    
    pHeaderBuffer = &DoIP_RxHeaderBuffer[DoIP_TcpConCfgGetRxHeaderBufferStartIdx(TcpConIdx)];
    HeaderType = ((uint16)(pHeaderBuffer[0] << 8u) | (uint16)(pHeaderBuffer[1]));
    if (HeaderType == DOIP_HEADER_TYPE_DIAG_REQ)
    {
        if ((DoIP_TcpConCtrlGetTxTpHeaderType(TcpConIdx) == DOIP_HEADER_TYPE_DIAG_NACK) ||
            (DoIP_TcpConCtrlGetTxTpHeaderType(TcpConIdx) == DOIP_HEADER_TYPE_DIAG_ACK))
        {
            TesterIdx = DoIP_TcpConCtrlGetTesterIdx(TcpConIdx);
            if ( TesterIdx != DoIP_CfgGetNumOfTester())
            {
                NegativeAckOffset = DoIP_TesterCtrlGetNegativeAckOffset(TesterIdx);
                NumOfNegAckByte = DoIP_TesterCfgGetNumOfDiagAckNackRespBytes(TesterIdx);
                if (NumOfNegAckByte > 0U)
                {
                    uint32 BytesToCopy = PduInfoPtr->SduLength - *ReadDataLenPtr;
                    /* update length */
                    if ((NumOfNegAckByte - NegativeAckOffset) < BytesToCopy)
                    {
                        BytesToCopy = (NumOfNegAckByte - NegativeAckOffset);
                    }
                    /* copy data */
                    if (BytesToCopy > 0U)
                    {
                        DoIP_UtilMemCopy(&DoIP_DiagNAckBuffer[DoIP_TesterCfgGetDiagNackBufferStartIdx(TesterIdx)+NegativeAckOffset],
                                        &PduInfoPtr->SduDataPtr[*ReadDataLenPtr],BytesToCopy);
                        DoIP_TesterCtrlSetNegativeAckOffset(TesterIdx,(NegativeAckOffset+BytesToCopy));
                    }
                }
            }
        }
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the tcp routing activation request
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpRoutHandleRoutingActivationReq
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) ErrorIdPtr
)
{
    uint32 BytesToCopy;
    DoIP_GenericHeaderType GenericHeader={0};
    DOIP_UtilExtractGenericHeader(&GenericHeader,
                                &DoIP_RxHeaderBuffer[DoIP_TcpConCfgGetRxHeaderBufferStartIdx(TcpConIdx)]);
    if (GenericHeader.HeaderLength > DOIP_MAX_REQUEST_BYTES)
    {
        /* send Nack for invalid length */
        DoIP_TcpConCtrlSetRxSkipMsg(TcpConIdx,TRUE);
        (void)DoIP_TxTcpTransmit(TcpConIdx,DOIP_HEADER_TYPE_GEN_NACK,DOIP_GEN_NACK_MAX_LEN, 0U, 0U, NULL_PTR,FALSE);
    }
    else if((GenericHeader.HeaderLength != DOIP_ROUT_ACTIV_REQ_MIN_LENGTH) &&
            (GenericHeader.HeaderLength != (DOIP_ROUT_ACTIV_REQ_MIN_LENGTH+DOIP_ROUT_ACTIV_REQ_OEM_LENGTH)))
    {
        (void)DoIP_TxTcpTransmit(TcpConIdx, DOIP_HEADER_TYPE_GEN_NACK, DOIP_GEN_NACK_INV_LEN, 0U, 0U, NULL_PTR, TRUE);
    }
    else
    {
        BytesToCopy = (GenericHeader.HeaderLength+DOIP_GENERIC_HEADER_LENGTH)-DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx);
        /* copy data to header buffer */
        DoIP_RxTcpGenCopyDataToHeaderBuffer(TcpConIdx, PduInfoPtr, ReadDataLenPtr, BytesToCopy);
        if (DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx) == (GenericHeader.HeaderLength+DOIP_GENERIC_HEADER_LENGTH))
        {
            DoIP_RxTcpRoutHandleCopiedRoutingActivationReq(TcpConIdx, ErrorIdPtr);
        }
        else
        {
            BytesToCopy = (GenericHeader.HeaderLength+DOIP_GENERIC_HEADER_LENGTH)-DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx);
            if (BytesToCopy > DOIP_MAX_REQUEST_BYTES)
            {
                *BufferSizePtr = DOIP_MAX_REQUEST_BYTES;
            }
            else
            {
                *BufferSizePtr = BytesToCopy;
            }
            DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx,*BufferSizePtr);
        }
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the tcp alive check response
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpAliveHandleAliveCheckRes
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr
)
{
    uint32 BytesToCopy;
    DoIP_GenericHeaderType GenericHeader={0};
    
    DOIP_UtilExtractGenericHeader(&GenericHeader,
                                &DoIP_RxHeaderBuffer[DoIP_TcpConCfgGetRxHeaderBufferStartIdx(TcpConIdx)]);
    if (GenericHeader.HeaderLength > DOIP_MAX_REQUEST_BYTES)
    {
        /* send Nack for invalid length */
        DoIP_TcpConCtrlSetRxSkipMsg(TcpConIdx,TRUE);
        (void)DoIP_TxTcpTransmit(TcpConIdx,DOIP_HEADER_TYPE_GEN_NACK,DOIP_GEN_NACK_MAX_LEN,0U,0U,NULL_PTR,FALSE);
    }
    else if (GenericHeader.HeaderLength != DOIP_ADDR_LENGTH)
    {
        /* send nack for invalid header length */
       (void)DoIP_TxTcpTransmit(TcpConIdx,DOIP_HEADER_TYPE_GEN_NACK,DOIP_GEN_NACK_INV_LEN,0U,0U,NULL_PTR,TRUE);
    }
    else
    {
        /* copy data */
        BytesToCopy = (GenericHeader.HeaderLength+DOIP_GENERIC_HEADER_LENGTH)-DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx);
        DoIP_RxTcpGenCopyDataToHeaderBuffer(TcpConIdx,PduInfoPtr,ReadDataLenPtr,BytesToCopy);
        
        if (DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx) == (GenericHeader.HeaderLength+DOIP_GENERIC_HEADER_LENGTH))
        {
            /* Handle Alive check */
            DoIP_RxTcpAliveHandleCopiedAliveCheckRes(TcpConIdx);
        }
        else
        {
            /* update BufferSizePtr */
            BytesToCopy = (GenericHeader.HeaderLength+DOIP_GENERIC_HEADER_LENGTH)-
                                            DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx);
            if (BytesToCopy > DOIP_MAX_REQUEST_BYTES)
            {
                *BufferSizePtr = DOIP_MAX_REQUEST_BYTES;
            }
            else
            {
                *BufferSizePtr = BytesToCopy; 
            }
            DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx,*BufferSizePtr);
        }
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the tcp rx diag message
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpDiagHandleDiagnosticMessage
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr
)
{
    DoIP_GenericHeaderType GenericHeader={0};
    
    DOIP_UtilExtractGenericHeader(&GenericHeader,
                                &DoIP_RxHeaderBuffer[DoIP_TcpConCfgGetRxHeaderBufferStartIdx(TcpConIdx)]);    
    if (GenericHeader.HeaderLength > DOIP_MAX_REQUEST_BYTES)
    {
        /* send nack for invalid length */
        DoIP_TcpConCtrlSetRxMsgOffset(TcpConIdx,TRUE);
        (void)DoIP_TxTcpTransmit(TcpConIdx, DOIP_HEADER_TYPE_GEN_NACK,DOIP_GEN_NACK_MAX_LEN,0U,0U,NULL_PTR,FALSE);
    }
    else if (GenericHeader.HeaderLength <= DOIP_DIAG_MSG_REQ_MIN_LENGTH)
    {
        /* send nack for invalid min length */
        (void)DoIP_TxTcpTransmit(TcpConIdx,DOIP_HEADER_TYPE_GEN_NACK,DOIP_GEN_NACK_INV_LEN,0U,0U,NULL_PTR,TRUE);
    }
    else
    {
        /* process diag message */
        DoIP_RxTcpDiagHandleValidDiagnosticMessage(TcpConIdx,PduInfoPtr,BufferSizePtr,ReadDataLenPtr);
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the tcp rx Oem payload types
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpOemHandleOemPayloadTypes
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr
)
{
    uint8 *pRxHeaderBuffer;
    DoIP_GenericHeaderType GenericHeader={0};
    #if ( DOIP_OEM_PAYLOAD_TCP_BUFFER_SIZE > 0U )
    DoIP_TcpRxBufferIdxType RxMsgOffset;
    uint32 BytesToCopy;
    DoIP_ConIdxType OemConIdx;
    #else
    PduInfoType RxUserPduInfo={.SduDataPtr=NULL_PTR,.SduLength=0};
    PduInfoType TxUserPduInfo={.SduDataPtr=NULL_PTR,.SduLength=0};
    uint8 TcpOemFlags;
    uint16 OemHeaderType = DOIP_HEADER_TYPE_INVALID;
    #endif
    
    pRxHeaderBuffer = &DoIP_RxHeaderBuffer[DoIP_TcpConCfgGetRxHeaderBufferStartIdx(TcpConIdx)];
    DOIP_UtilExtractGenericHeader(&GenericHeader,pRxHeaderBuffer);
    DoIP_UtilMemCopy((uint8 *)&GenericHeader,pRxHeaderBuffer,DOIP_GENERIC_HEADER_LENGTH);
    #if ( DOIP_OEM_PAYLOAD_TCP_BUFFER_SIZE > 0U )
    RxMsgOffset = DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx);
    OemConIdx = DoIP_OemPayloadCtrlGetTcpBufferConIdx();
    #endif
    
    if (GenericHeader.HeaderLength > DOIP_OEM_PAYLOAD_TCP_BUFFER_SIZE )
    {
        /* send Nack incase of unsupported header length */
        DoIP_TcpConCtrlSetRxSkipMsg(TcpConIdx, TRUE);
        (void)DoIP_TxTcpTransmit(TcpConIdx,DOIP_HEADER_TYPE_GEN_NACK,DOIP_GEN_NACK_MAX_LEN,0U,0U,NULL_PTR,FALSE);
    }
    #if ( DOIP_OEM_PAYLOAD_TCP_BUFFER_SIZE > 0U )
    else if((OemConIdx != DoIP_CfgGetNumOfConnection()) &&
           ((OemConIdx != TcpConIdx) || (DoIP_OemPayloadCtrlGetTcpBufferReqTx() == TRUE)))
    {
        /* wait for free buffer */
        *BufferSizePtr = 0U; 
        DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx,*BufferSizePtr);
    }
    #endif 
    else
    {
        #if (DOIP_OEM_PAYLOAD_TCP_BUFFER_SIZE > 0U)
        if (OemConIdx == DoIP_CfgGetNumOfConnection() )
        {
            /* set TcpCon to indicate the buffer user */
            DoIP_OemPayloadCtrlSetTcpBufferConIdx(TcpConIdx);
        }
        /* copy data */
        BytesToCopy = (GenericHeader.HeaderLength+DOIP_GENERIC_HEADER_LENGTH) - RxMsgOffset;
        if (BytesToCopy > (PduInfoPtr->SduLength - *ReadDataLenPtr))
        {
            BytesToCopy = (PduInfoPtr->SduLength - *ReadDataLenPtr);
        }
        if (BytesToCopy > 0U)
        {
            DoIP_UtilMemCopy(&DoIP_OemPayloadTcpBuffer[RxMsgOffset-DOIP_GENERIC_HEADER_LENGTH],
                            &PduInfoPtr->SduDataPtr[*ReadDataLenPtr],BytesToCopy);
            RxMsgOffset += BytesToCopy;
            *ReadDataLenPtr += BytesToCopy;
            DoIP_TcpConCtrlSetRxMsgOffset(TcpConIdx,RxMsgOffset);
        }
        /* Handle Oem message */
        if (RxMsgOffset == (GenericHeader.HeaderLength+DOIP_GENERIC_HEADER_LENGTH))
        {
            DoIP_RxTcpOemHandleCopiedOemPayloadTypes(TcpConIdx);
        }
        else
        {
            BytesToCopy = (GenericHeader.HeaderLength-(DOIP_GENERIC_HEADER_LENGTH - RxMsgOffset));
            if (BytesToCopy > DOIP_MAX_REQUEST_BYTES)
            {
                *BufferSizePtr = DOIP_MAX_REQUEST_BYTES;
            }
            else
            {
                *BufferSizePtr = BytesToCopy;
            }
            DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx,*BufferSizePtr);
        }
        #else     
        /* Set TCP flags for callback. */
        TcpOemFlags = DOIP_OEM_PAYLOAD_TYPE_PROT_TCP;
        if (DoIP_TcpConCtrlGetRoutingActivationState(TcpConIdx) != DOIP_ROUTING_ACTIVATION_STATE_ACTIVATED)
        {
          TcpOemFlags |= DOIP_OEM_PAYLOAD_TYPE_ROUT_ACTIV;
        }
        /* copy data from upper layer */
        if (E_NOT_OK == DoIP_UserGetPayloadCallbackFn(GenericHeader.HeaderType,&RxUserPduInfo,
                            TcpOemFlags,&OemHeaderType,&TxUserPduInfo))
        {
            /* Send Nack if payload type are unkown. */
            (void)DoIP_TxTcpTransmit(TcpConIdx, DOIP_HEADER_TYPE_GEN_NACK, DOIP_GEN_NACK_TYPE,0U, 0U, NULL_PTR,FALSE);
        }
        else
        {
            /* Send user data response */
            if (OemHeaderType != DOIP_HEADER_TYPE_INVALID)
            {
                (void)DoIP_TxTcpTransmit(TcpConIdx, DOIP_HEADER_TYPE_OEM_SPECIFIC,OemHeaderType,0U,0U,NULL_PTR,FALSE); 
            }
        }
        DoIP_TcpConCtrlSetRxMsgOffset(TcpConIdx,0U);
        DOIP_DUMMY_STATEMENT(PduInfoPtr);
        DOIP_DUMMY_STATEMENT(ReadDataLenPtr);
        DOIP_DUMMY_STATEMENT(BufferSizePtr);
        #endif
    }
}
/********************************************************************************************************************
* @brief  This api used to copy data to the header buffer
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpGenCopyDataToHeaderBuffer
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr,
    uint32 BytesToCopy
)
{
    DoIP_TcpRxBufferIdxType RxMsgOffset;
    
    RxMsgOffset = DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx);
    /* update length */
    if (BytesToCopy > (PduInfoPtr->SduLength - *ReadDataLenPtr))
    {
        BytesToCopy = (PduInfoPtr->SduLength - *ReadDataLenPtr);
    }
    /* copy data to header buffer */
    if (BytesToCopy > 0U)
    {
        DoIP_UtilMemCopy(&DoIP_RxHeaderBuffer[DoIP_TcpConCfgGetRxHeaderBufferStartIdx(TcpConIdx)+RxMsgOffset],
                                        &PduInfoPtr->SduDataPtr[*ReadDataLenPtr],BytesToCopy);
        *ReadDataLenPtr += (PduLengthType)BytesToCopy;
        DoIP_TcpConCtrlSetRxMsgOffset(TcpConIdx,(RxMsgOffset+BytesToCopy));
    }
}
/********************************************************************************************************************
* @brief  This api used to get the tester idx from the tester address
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpRoutGetTesterIdxByTesterAddr
(
    uint16 TesterAddr,
    P2VAR(DoIP_TesterIdxType, AUTOMATIC, DOIP_APPL_VAR) pTesterIdx
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    DoIP_TcpConIdxType TcpConIdx;
    DoIP_TesterIdxType LocalTesterIdx;
    
    *pTesterIdx = DoIP_CfgGetNumOfTester();
    for(LocalTesterIdx = 0U; LocalTesterIdx < DoIP_CfgGetNumOfTester();LocalTesterIdx++)
    {
        if (DoIP_TesterCfgGetTesterAddr(LocalTesterIdx) == TesterAddr)
        {
            *pTesterIdx = LocalTesterIdx;
            RetVal = E_OK;
        }
    }
    /* If not found check for ANY_ADDR */
    if (RetVal == E_NOT_OK)
    {
        LocalTesterIdx = DoIP_DefaultTesterCfgGetTesterIdx();
        TcpConIdx = DoIP_TesterCtrlGetTcpConIdx(LocalTesterIdx);
        if ((TcpConIdx != DoIP_CfgGetNumOfTcpConnection()) || 
            (DoIP_TcpConCtrlGetTesterIdx(TcpConIdx) != DoIP_CfgGetNumOfTester()) ||
            (TesterAddr == DoIP_TcpConCtrlGetTesterAddr(TcpConIdx)))
            
        {
            *pTesterIdx = LocalTesterIdx;
            RetVal = E_OK;
        }
    }
    return RetVal;
    
}
/********************************************************************************************************************
* @brief  This api used to trigger the alive check response handling for the tcp con idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpRoutTriggerAliveCheckSingleConnection
(
    DoIP_TcpConIdxType TcpConIdx,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) ErrorIdPtr
)
{
    if (DoIP_TxTcpTransmit(TcpConIdx, DOIP_HEADER_TYPE_ALIVE_CHECK_REQ, 0U, 0U, 0U, NULL_PTR, FALSE) == E_OK )
    {
        /* Load alive check timer if alive check could be send. */
        DoIP_RoutingActivationCtrlSetAliveCheckCount(DOIP_ALIVE_CHECK_RESPONSE_TIMEOUT);
        #if TODO
        DoIP_SetConnectionIdxOfAliveCheckList(0U, TcpConIdx);
        #endif 
        DoIP_RoutingActivationCtrlSetAliveCheckElemNum(1u);
    }
    else
    {
#if ( DOIP_DEV_ERROR_DETECT == STD_ON )
    /* Otherwise set error (if enabled). */
    *ErrorIdPtr = DOIP_E_INVALID_PARAMETER;
#else
    DOIP_DUMMY_STATEMENT(ErrorIdPtr); 
#endif 
    }
}
/********************************************************************************************************************
* @brief  This api used to get the available number of the socket for this local address idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(PduIdType, DOIP_CODE) DoIP_RxTcpRoutGetAvailableSockNum(DoIP_LocalAddrIdxType LocalAddrIdx) 
{
    PduIdType NumOfConnection=0U;
    PduIdType NumOfAvailableSock;
    DoIP_TcpConIdxType TcpConIdx;
    PduIdType NumOfRoutingActivation = 0U;
    
    for (TcpConIdx =0U; TcpConIdx < DoIP_CfgGetNumOfTcpConnection(); TcpConIdx++)
    {
        if (DoIP_ConCfgGetLocalIpAddrIdx(TcpConIdx) == LocalAddrIdx)
        {
            NumOfConnection++;
            if (DoIP_TcpConCtrlGetTesterIdx(TcpConIdx) != DoIP_CfgGetNumOfTester())
            {
                NumOfRoutingActivation++;
            }
        }
    }
    /* TODO check for additional conncetion */
    NumOfAvailableSock = NumOfConnection-NumOfRoutingActivation;
    return NumOfAvailableSock;
}
/********************************************************************************************************************
* @brief  This api used to trigger alive check for all connections
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpRoutTriggerAliveCheckAllConnections
(
    DoIP_ConIdxType ConIdx,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) ErrorIdPtr
)
{
    DoIP_TcpConIdxType TcpConIdx;
    
    for (TcpConIdx =0U;TcpConIdx < DoIP_CfgGetNumOfTcpConnection();TcpConIdx++)
    {
        if ((DoIP_ConCfgGetLocalIpAddrIdx(TcpConIdx) == DoIP_ConCfgGetLocalIpAddrIdx(ConIdx)) && 
            (DoIP_TcpConCtrlGetTesterIdx(TcpConIdx) != DoIP_CfgGetNumOfTester()))
        {
            /* trigger for alive check */
            if (DoIP_TxTcpTransmit(TcpConIdx,DOIP_HEADER_TYPE_ALIVE_CHECK_REQ,0U, 0U, 0U, NULL_PTR, FALSE) == E_OK)
            {
                #if TODO
                DoIP_SetConnectionIdxOfAliveCheckList(DoIP_GetAliveCheckElemNumOfRoutActivHandler(0U),TcpConIdx);
                #endif
                DoIP_RoutingActivationCtrlSetAliveCheckElemNum(DoIP_RoutingActivationCtrlGetAliveCheckElemNum()+1);
            }
            else
            {
                #if ( DOIP_DEV_ERROR_DETECT == STD_ON )
                *ErrorIdPtr = DOIP_E_INVALID_PARAMETER;
                #else
                DOIP_DUMMY_STATEMENT_CONST_VAR(ErrorIdPtr); 
                #endif
            }
        }
    }
    /* set alive check wait timer */
    DoIP_RoutingActivationCtrlSetAliveCheckCount(DOIP_ALIVE_CHECK_RESPONSE_TIMEOUT);
}
/********************************************************************************************************************
* @brief  This api used to check if the tester is registered tester or not.
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpRoutCheckForRegisteredTester
(
    DoIP_TcpConIdxType TcpConIdx,
    DoIP_TesterIdxType TesterIdx
)
{
    Std_ReturnType RetVal = E_OK;
    
    if ((DoIP_TcpConCtrlGetTesterIdx(TcpConIdx) != DoIP_CfgGetNumOfTester()) && 
        (DoIP_TcpConCtrlGetTesterIdx(TcpConIdx) != TesterIdx))
    {
        RetVal = E_NOT_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to handle the routing activation request of oem type
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpRoutHandleCopiedRoutingActivationReqOem(DoIP_TcpConIdxType TcpConIdx)
{
    uint32 OemSpecReq=0U;
    uint8 * pRxHeaderBuffer;
    
    DoIP_GenericHeaderType GenericHeader={0};
    pRxHeaderBuffer = &DoIP_RxHeaderBuffer[DoIP_TcpConCfgGetRxHeaderBufferStartIdx(TcpConIdx)];
    DOIP_UtilExtractGenericHeader(&GenericHeader,pRxHeaderBuffer);
    if (GenericHeader.HeaderLength == DOIP_ROUT_ACTIV_REQ_MAX_LENGTH)
    {
        /* reset Oem response */
        DoIP_RoutingActivationCtrlSetOemResponse(0U);
        /* update Oem Request */
        OemSpecReq |= (uint32)(((uint32)pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH+7u]) << 24u);
        OemSpecReq |= (uint32)(((uint32)pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH+8u]) << 16u);
        OemSpecReq |= (uint32)(((uint32)pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH+9u]) << 8u);
        OemSpecReq |= (uint32)pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH+10u];
        /* update Oem payload status */
        DoIP_RoutingActivationCtrlSetOemRequest(OemSpecReq);
        DoIP_RoutingActivationCtrlSetOemReqResUsed(TRUE);
    }
    else
    {
        DoIP_RoutingActivationCtrlSetOemReqResUsed(FALSE);
    }
}
/********************************************************************************************************************
* @brief  This api used to get the conncetion idx for the tester
********************************************************************************************************************/
DOIP_LOCAL FUNC(DoIP_TcpConIdxType, DOIP_CODE) DoIP_RxTcpRoutGetConnectionIdxOfTesterAddr(uint16 TesterAddr)
{
    DoIP_TcpConIdxType TcpConIdx;
    
    for (TcpConIdx = 0U; TcpConIdx < DoIP_CfgGetNumOfTcpConnection(); TcpConIdx++)
    {
        if ((DoIP_TcpConCtrlGetTesterIdx(TcpConIdx) != DoIP_CfgGetNumOfTester()) && 
            (DoIP_TcpConCtrlGetTesterAddr(TcpConIdx) == TesterAddr))
        {
            break;
        }
    }
    return TcpConIdx;
}
/********************************************************************************************************************
* @brief  This api used to check for alive check response
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpRoutCheckForAliveChecks
(
    DoIP_ConIdxType ConIdx,
    uint16 TesterAddr,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) ErrorIdPtr
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    DoIP_LocalAddrIdxType LocalAddrIdx;
    DoIP_TcpConIdxType TcpConIdxFromTester;
    
    LocalAddrIdx = DoIP_ConCfgGetLocalIpAddrIdx(ConIdx);
    TcpConIdxFromTester = DoIP_RxTcpRoutGetConnectionIdxOfTesterAddr(TesterAddr);
    if (TcpConIdxFromTester != ConIdx)
    {
        if (TcpConIdxFromTester != DoIP_CfgGetNumOfTcpConnection())
        {
            /* trigger alive check connection */
            DoIP_RxTcpRoutTriggerAliveCheckSingleConnection(ConIdx, ErrorIdPtr);
            RetVal = E_OK;
        }
        else if (DoIP_RxTcpRoutGetAvailableSockNum(LocalAddrIdx) == 0U)
        {
            /* trigger alive check on all connections if there is no free socket. */
            DoIP_RxTcpRoutTriggerAliveCheckAllConnections(ConIdx, ErrorIdPtr);
            RetVal = E_OK;
        }
    }
    else
    {
        /* Do Nothing as it is already connected */
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to process the routing activation
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpRoutPerformRoutingActivation(void)
{
    Std_ReturnType RetVal = E_OK;
    uint16 TesterAddr;
    DoIP_TesterIdxType TesterIdx;
    DoIP_TcpConIdxType TcpConIdx;
    DoIP_RoutingActivationStateType  RoutingActivationNextState;
    DoIP_RoutingActivationIdxType RoutingActivationIdx;
    
    RoutingActivationNextState = DOIP_ROUTING_ACTIVATION_STATE_NONE;
    RoutingActivationIdx = DoIP_RoutingActivationCtrlGetRoutingActivationIdx();
    TesterIdx = DoIP_RoutingActivationCtrlGetTesterIdx();
    TesterAddr = DoIP_RoutingActivationCtrlGetTesterAddr();
    TcpConIdx = DoIP_RoutingActivationCtrlGetTcpConIdx();
    
    if ((DoIP_RoutingActivationCtrlGetOemReqResUsed() == FALSE) &&
        ((DoIP_RoutingActivationCtrlGetOemResponse() != 0U) ||
        (DoIP_RoutingActivationCtrlGetOemRequest() != 0U)))
    {
        DoIP_TcpConCtrlSetRoutingActivationState(TcpConIdx,RoutingActivationNextState);
        /* send nack if oem payload not received */
        (void)DoIP_TxTcpTransmit(TcpConIdx, DOIP_HEADER_TYPE_ROUT_ACTIV_RES,TesterAddr,
                                    DOIP_ROUT_ACTIV_RES_CODE_MISSING_AUTHENT,TesterIdx,NULL_PTR,FALSE);
    }
    else
    {
        if (DoIP_RoutingActivationCfgGetpAuthCallbackFn(RoutingActivationIdx) != NULL_PTR)
        {
            RetVal = DoIP_RxTcpRoutPerformRoutingActivationAuth(&RoutingActivationNextState);
        }
        
        if ((RetVal == E_OK) && (DoIP_RoutingActivationCfgGetpConfCallbackFn(RoutingActivationIdx) != NULL_PTR))
        {
            RetVal = DoIP_RxTcpRoutPerformRoutingActivationConf(&RoutingActivationNextState);
        }
        
        if (RetVal == E_OK)
        {
             /* Register tester, activate route */ 
            DoIP_RxTcpRoutRegisterTester(TcpConIdx,TesterIdx,TesterAddr,
                                            RoutingActivationIdx, DOIP_ROUTING_ACTIVATION_STATE_ACTIVATED);
            DoIP_TcpConCtrlSetInactiveTimeCount(TcpConIdx,0U);
            DoIP_TesterCtrlSetTcpConIdx(TesterIdx,TcpConIdx);
            /* send response if authentification and confirmation passed. */
            (void)DoIP_TxTcpTransmit(TcpConIdx, DOIP_HEADER_TYPE_ROUT_ACTIV_RES,TesterAddr,
                                        DOIP_ROUT_ACTIV_RES_CODE_SUCCESS,TesterIdx, NULL_PTR, FALSE);
    
        }
    }
}
/********************************************************************************************************************
* @brief  This api used to process the routing activation authentication
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpRoutPerformRoutingActivationAuth
(
    P2VAR(DoIP_RoutingActivationStateType, AUTOMATIC, DOIP_APPL_VAR) pRoutingActivationNextState
)
{
    uint16 TesterAddr;
    uint8 OemSpecReq[4];
    uint8 OemSpecRes[4];
    Std_ReturnType RetVal;
    DoIP_TesterIdxType TesterIdx;
    DoIP_TcpConIdxType TcpConIdx;
    boolean AuthenticaionStatus = FALSE;
    DoIP_RoutingActivationIdxType RoutingActivationIdx;
    
    RoutingActivationIdx = DoIP_RoutingActivationCtrlGetRoutingActivationIdx();
    TesterIdx = DoIP_RoutingActivationCtrlGetTesterIdx();
    TesterAddr = DoIP_RoutingActivationCtrlGetTesterAddr();
    TcpConIdx = DoIP_RoutingActivationCtrlGetTcpConIdx();
    /* update Oem spec req and resp */
    OemSpecReq[0] = (uint8)(DoIP_RoutingActivationCtrlGetOemRequest() >> 24u);
    OemSpecReq[1] = (uint8)(DoIP_RoutingActivationCtrlGetOemRequest() >> 16u);
    OemSpecReq[2] = (uint8)(DoIP_RoutingActivationCtrlGetOemRequest() >> 8u);
    OemSpecReq[3] = (uint8)DoIP_RoutingActivationCtrlGetOemRequest();
    OemSpecRes[0] = (uint8)(DoIP_RoutingActivationCtrlGetOemResponse() >> 24u);
    OemSpecRes[1] = (uint8)(DoIP_RoutingActivationCtrlGetOemResponse() >> 16u);
    OemSpecRes[2] = (uint8)(DoIP_RoutingActivationCtrlGetOemResponse() >> 8u);
    OemSpecRes[3] = (uint8)DoIP_RoutingActivationCtrlGetOemResponse();
    /* Req authentication status */
    RetVal = DoIP_RoutingActivationCfgGetpAuthCallbackFn(RoutingActivationIdx)(&AuthenticaionStatus,
                                            &OemSpecReq[0],&OemSpecRes[0]);
    switch(RetVal)
    {
        case DOIP_E_PENDING:
            /* register tester and upate state as pending */
            DoIP_RxTcpRoutRegisterTester(TcpConIdx,TesterIdx,TesterAddr,
                                            RoutingActivationIdx,DOIP_ROUTING_ACTIVATION_STATE_AUTH_PENDING);
            break;
        case E_OK:
            if (AuthenticaionStatus == TRUE )
            {
                /* set next state as activated */
                *pRoutingActivationNextState = DOIP_ROUTING_ACTIVATION_STATE_ACTIVATED;
            }
            else
            {
                /* set state as None and send Nack */
                DoIP_RxTcpRoutRegisterTester(TcpConIdx,TesterIdx,TesterAddr,
                                                RoutingActivationIdx,DOIP_ROUTING_ACTIVATION_STATE_NONE);
                (void)DoIP_TxTcpTransmit(TcpConIdx,DOIP_HEADER_TYPE_ROUT_ACTIV_RES,TesterAddr,
                                            DOIP_ROUT_ACTIV_RES_CODE_MISSING_AUTHENT,TesterIdx,NULL_PTR,FALSE);
                RetVal = E_NOT_OK;
            }
            break;
        default:
            /* set state as None and send Nack */
            DoIP_RxTcpRoutRegisterTester(TcpConIdx,TesterIdx,TesterAddr,
                                                RoutingActivationIdx,DOIP_ROUTING_ACTIVATION_STATE_NONE);
                (void)DoIP_TxTcpTransmit(TcpConIdx,DOIP_HEADER_TYPE_ROUT_ACTIV_RES,TesterAddr,
                                            DOIP_ROUT_ACTIV_RES_CODE_MISSING_AUTHENT,TesterIdx,NULL_PTR,FALSE);
            break;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to process the routing activation confirmation
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpRoutPerformRoutingActivationConf
(
    P2VAR(DoIP_RoutingActivationStateType, AUTOMATIC, DOIP_APPL_VAR) pRoutingActivationNextState
)
{
    uint16 TesterAddr;
    uint8 OemSpecReq[4];
    uint8 OemSpecRes[4];
    Std_ReturnType RetVal;
    uint32 OemSpeReqU32 = 0;
    uint32 OemSpeResU32 = 0;
    uint8 OemSpecReqOffset=0U;
    uint8 OemSpecResOffset=0U;
    DoIP_TesterIdxType TesterIdx;
    DoIP_TcpConIdxType TcpConIdx;
    boolean ConfStatus = FALSE;
    DoIP_RoutingActivationIdxType RoutingActivationIdx;
    
    RoutingActivationIdx = DoIP_RoutingActivationCtrlGetRoutingActivationIdx();
    TesterIdx = DoIP_RoutingActivationCtrlGetTesterIdx();
    TesterAddr = DoIP_RoutingActivationCtrlGetTesterAddr();
    TcpConIdx = DoIP_RoutingActivationCtrlGetTcpConIdx();
    /* update req and res offset */
    if (DoIP_RoutingActivationCfgGetConfReqLength(RoutingActivationIdx) > 0U)
    {
        OemSpecReqOffset = DOIP_ROUT_ACTIV_ACK_OEM_LENGTH - 
                               DoIP_RoutingActivationCfgGetConfReqLength(RoutingActivationIdx);
    }
    if (DoIP_RoutingActivationCfgGetConfResLength(RoutingActivationIdx) > 0U)
    {
        OemSpecResOffset = DOIP_ROUT_ACTIV_ACK_OEM_LENGTH - 
                               DoIP_RoutingActivationCfgGetConfResLength(RoutingActivationIdx);
    }
    /* update Oem spec req and resp */
    OemSpeReqU32 = DoIP_RoutingActivationCtrlGetOemRequest();
    OemSpecReq[0] = (uint8)(OemSpeReqU32 >> 24u);
    OemSpecReq[1] = (uint8)(OemSpeReqU32 >> 16u);
    OemSpecReq[2] = (uint8)(OemSpeReqU32 >> 8u);
    OemSpecReq[3] = (uint8)OemSpeReqU32;
    OemSpeResU32 = DoIP_RoutingActivationCtrlGetOemResponse();
    OemSpecRes[0] = (uint8)(OemSpeResU32 >> 24u);
    OemSpecRes[1] = (uint8)(OemSpeResU32 >> 16u);
    OemSpecRes[2] = (uint8)(OemSpeResU32 >> 8u);
    OemSpecRes[3] = (uint8)OemSpeResU32;
    /* Req confirmation status */
    RetVal = DoIP_RoutingActivationCfgGetpConfCallbackFn(RoutingActivationIdx)(&ConfStatus,
                                                        &OemSpecReq[OemSpecReqOffset],&OemSpecRes[OemSpecResOffset]);
    /* update oem spec req and resp data */
    OemSpeReqU32 |= (uint32)(((uint32)OemSpecReq[0]) << 24U);
    OemSpeReqU32 |= (uint32)(((uint32)OemSpecReq[0]) << 16U);
    OemSpeReqU32 |= (uint32)(((uint32)OemSpecReq[0]) << 8U);
    OemSpeReqU32 |= ((uint32)OemSpecReq[0]);
    DoIP_RoutingActivationCtrlSetOemRequest(OemSpeReqU32);
    OemSpeResU32 |= (uint32)(((uint32)OemSpecRes[0]) << 24U);
    OemSpeResU32 |= (uint32)(((uint32)OemSpecRes[0]) << 16u);
    OemSpeResU32 |= (uint32)(((uint32)OemSpecRes[0]) << 8u);
    OemSpeResU32 |= ((uint32)OemSpecRes[0]);
    DoIP_RoutingActivationCtrlSetOemResponse(OemSpeResU32);
    
    switch (RetVal)
    {
        case DOIP_E_PENDING:
            DoIP_RxTcpRoutRegisterTester(TcpConIdx,TesterIdx,TesterAddr,RoutingActivationIdx,
                                            DoIP_TcpConCtrlGetRoutingActivationState(TcpConIdx));
            if (*pRoutingActivationNextState == DOIP_ROUTING_ACTIVATION_STATE_ACTIVATED)
            {
                DoIP_TcpConCtrlSetRoutingActivationState(TcpConIdx,DOIP_ROUTING_ACTIVATION_STATE_CONF_PENDING);
                (void)DoIP_TxTcpTransmit(TcpConIdx, DOIP_HEADER_TYPE_ROUT_ACTIV_RES,TesterAddr,
                                        DOIP_ROUT_ACTIV_RES_CODE_CONFIRM_REQUIRED,TesterIdx,NULL_PTR,FALSE);
            }
            break;
        case E_OK:
            if (ConfStatus == TRUE)
            {   
                *pRoutingActivationNextState = DOIP_ROUTING_ACTIVATION_STATE_ACTIVATED;
            }
            else
            {
                /* send nack for failure */
                DoIP_RxTcpRoutRegisterTester(TcpConIdx,TesterIdx,TesterAddr,
                                    RoutingActivationIdx,DOIP_ROUTING_ACTIVATION_STATE_NONE); 
                (void)DoIP_TxTcpTransmit(TcpConIdx, DOIP_HEADER_TYPE_ROUT_ACTIV_RES,TesterAddr,
                                        DOIP_ROUT_ACTIV_RES_CODE_CONFIRM_REJECTED, TesterIdx, NULL_PTR, TRUE);

            }
            break;
        default:
            /* send nack for failure */
            DoIP_RxTcpRoutRegisterTester(TcpConIdx,TesterIdx,TesterAddr,
                                    RoutingActivationIdx,DOIP_ROUTING_ACTIVATION_STATE_NONE); 
            (void)DoIP_TxTcpTransmit(TcpConIdx, DOIP_HEADER_TYPE_ROUT_ACTIV_RES,TesterAddr,
                                        DOIP_ROUT_ACTIV_RES_CODE_CONFIRM_REJECTED, TesterIdx, NULL_PTR, TRUE);
            break;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to register the tester
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpRoutRegisterTester
(
    DoIP_TcpConIdxType TcpConIdx,
    DoIP_TesterIdxType TesterIdx,
    uint16 TesterAddr,
    DoIP_RoutingActivationIdxType RoutingActivationIdx,
    DoIP_RoutingActivationStateType RoutingActivationNextState
)
{
    /* Save tester data. */
    DoIP_TcpConCtrlSetTesterIdx(TcpConIdx,TesterIdx);
    DoIP_TcpConCtrlSetTesterAddr(TcpConIdx,TesterAddr);
    DoIP_TcpConCtrlSetRoutingActivationIdx(TcpConIdx,RoutingActivationIdx);
    DoIP_TcpConCtrlSetRoutingActivationState(TcpConIdx,RoutingActivationNextState);
}
/********************************************************************************************************************
* @brief  This api used to handle the routing activation request
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpRoutHandleCopiedRoutingActivationReq
(
    DoIP_TcpConIdxType TcpConIdx,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) ErrorIdPtr
)
{
    uint8 ActiveNum;
    uint8  * pRxHeaderBuffer;
    DoIP_TesterAddrType TesterAddr;
    boolean IsRoutingActivationFound = FALSE;
    DoIP_TesterIdxType TesterIdx=DoIP_CfgGetNumOfTester();
    
    pRxHeaderBuffer = &DoIP_RxHeaderBuffer[DoIP_TcpConCfgGetRxHeaderBufferStartIdx(TcpConIdx)];
    /* Reset routing activation */
    DoIP_TcpConCtrlSetInactiveTimeCount(TcpConIdx,0U);
    DoIP_TcpConCtrlSetRxMsgOffset(TcpConIdx,0U);
    DoIP_RoutingActivationCtrlSetTcpConIdx(TcpConIdx);
    /* Get tester address */
    TesterAddr = (((uint16)pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH])<<8u);
    TesterAddr |= ((uint16)pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH+1u]);
    if (DoIP_RxTcpRoutGetTesterIdxByTesterAddr(TesterAddr,&TesterIdx) == E_NOT_OK)
    {
         /* Send nack if no tester with received tester address is configured */
        (void)DoIP_TxTcpTransmit(TcpConIdx, DOIP_HEADER_TYPE_ROUT_ACTIV_RES, TesterAddr,
                                    DOIP_ROUT_ACTIV_RES_CODE_UNKNOWN_TESTER,TesterIdx,NULL_PTR,TRUE);
    }
    else if (DoIP_RxTcpRoutCheckForRegisteredTester(TcpConIdx,TesterIdx) == E_NOT_OK)
    {
        /* send nack with different tester */
        (void)DoIP_TxTcpTransmit(TcpConIdx, DOIP_HEADER_TYPE_ROUT_ACTIV_RES, TesterAddr,
                                    DOIP_ROUT_ACTIV_RES_CODE_DIFFERENT_TESTER,TesterIdx, NULL_PTR, TRUE); 
    }
    else
    {
        DoIP_RoutingActivationIdxType RoutingActivationIdx=DoIP_CfgGetNumOfRoutingActivation();
        DoIP_TesterToRoutingActivationMapIdxType TesterToRoutingActivationMapIdx;
        /* update tester info */
        DoIP_RoutingActivationCtrlSetTesterAddr(TesterAddr);
        DoIP_RoutingActivationCtrlSetTesterIdx(TesterIdx);
        ActiveNum = pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH+DOIP_ADDR_LENGTH];
        /* check if routing activation is configured for this activation number/type */
        for (TesterToRoutingActivationMapIdx = DoIP_TesterCfgGetTesterToRoutingActivationMapStartIdx(TesterIdx);
             TesterToRoutingActivationMapIdx <= DoIP_TesterCfgGetTesterToRoutingActivationMapEndIdx(TesterIdx);
             TesterToRoutingActivationMapIdx++)
        {
            RoutingActivationIdx = DoIP_CfgGetDoIP_TesterToRoutingActivationIdxMap(TesterToRoutingActivationMapIdx);
            if (DoIP_RoutingActivationCfgGetActivationNumber(RoutingActivationIdx) == ActiveNum)
            {
                IsRoutingActivationFound = TRUE;
                break;
            }
        }
        if (IsRoutingActivationFound == FALSE)
        {
            /* Send nack if activation type check failed. */
            (void)DoIP_TxTcpTransmit(TcpConIdx, DOIP_HEADER_TYPE_ROUT_ACTIV_RES,TesterAddr,
                                        DOIP_ROUT_ACTIV_RES_CODE_INV_ACTIV_TYPE,TesterIdx, NULL_PTR, TRUE);
        }
        else
        {
            DoIP_RoutingActivationCtrlSetRoutingActivationIdx(RoutingActivationIdx);
            /* handle OEM specific part. */
            DoIP_RxTcpRoutHandleCopiedRoutingActivationReqOem(TcpConIdx);
            if (DoIP_RxTcpRoutCheckForAliveChecks(TcpConIdx,TesterAddr,ErrorIdPtr) == E_NOT_OK )
            {
                /* Perform routing activation */
                DoIP_RxTcpRoutPerformRoutingActivation();
            }
        }
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the alive check response
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpAliveHandleCopiedAliveCheckRes(DoIP_TcpConIdxType TcpConIdx)
{
    uint8 *pRxHeaderBuffer;
    uint16 TesterAddr;
    uint16 RxHeaderTesterAddr;
    
    if (DoIP_TcpConCtrlGetTesterIdx(TcpConIdx) != DoIP_CfgGetNumOfTester())
    {
        TesterAddr = DoIP_TesterCfgGetTesterAddr(DoIP_TcpConCtrlGetTesterIdx(TcpConIdx));
        if (TesterAddr == DOIP_ADDR_ANY)
        {
            /* get dyn addr */
            TesterAddr = DoIP_TcpConCtrlGetTesterAddr(TcpConIdx);
        }
        pRxHeaderBuffer = &DoIP_RxHeaderBuffer[(DoIP_TcpConCfgGetRxHeaderBufferStartIdx(TcpConIdx)+
                                                                DOIP_GENERIC_HEADER_LENGTH)];
        RxHeaderTesterAddr = (uint16)(((uint16)pRxHeaderBuffer[0]) << 8u) | ((uint16)pRxHeaderBuffer[1]);
        if (RxHeaderTesterAddr == TesterAddr)
        {
            DoIP_RxTcpAliveRemoveAliveCheckFromRoutActHandler(TcpConIdx);
        }
        else
        {
            /* close socket for invalid address */
            DoIP_ConCtrlSetSoConCloseReq(TcpConIdx,TRUE);
            DoIP_SoConClose(TcpConIdx);
        }
    }
    DoIP_TcpConCtrlSetRxMsgOffset(TcpConIdx,0U);
}
/********************************************************************************************************************
* @brief  This api used to remove the alive check from the routing activation handler
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpAliveRemoveAliveCheckFromRoutActHandler(DoIP_TcpConIdxType TcpConIdx)
{
    /* TODO update alive timer */
    DOIP_DUMMY_STATEMENT(TcpConIdx);
}
/********************************************************************************************************************
* @brief  This api used to handle user data copy of the tcp diag message
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpDiagCopyUserData
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) LocalPduInfoPtr
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    DoIP_TcpRxBufferIdxType RxMsgOffset;
    DoIP_GenericHeaderType GenericHeader={0};
    uint8 *pRxHeaderBuffer;
    DoIP_ChannelIdxType ChannelIdx;
    
    RxMsgOffset = DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx);
    if (RxMsgOffset >= (DOIP_GENERIC_HEADER_LENGTH + DOIP_DIAG_MSG_REQ_MIN_LENGTH + DOIP_VERIFY_RX_PDU_MAX_DATA_LENGTH))
    {   
        pRxHeaderBuffer = &DoIP_RxHeaderBuffer[DoIP_TcpConCfgGetRxHeaderBufferStartIdx(TcpConIdx)];
        DOIP_UtilExtractGenericHeader(&GenericHeader,pRxHeaderBuffer);
        
        if (DoIP_TcpConCtrlGetRxChannelActive(TcpConIdx) == TRUE)
        {
            /* Copy data to PduR if channel is still active. */
            RetVal = DoIP_RxTcpDiagCopyDataToPduR(TcpConIdx, BufferSizePtr, PduInfoPtr);
        }
        if (RetVal == E_OK)
        {
            uint32 BytesToCopy = ((DOIP_GENERIC_HEADER_LENGTH + GenericHeader.HeaderLength) - 
                                                        (RxMsgOffset + LocalPduInfoPtr->SduLength));
            if (BytesToCopy < *BufferSizePtr)
            {
                *BufferSizePtr = BytesToCopy;
            }
            DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx,*BufferSizePtr);
            
            if (BytesToCopy == 0U)
            {
                /* send pos ack  */
                (void)DoIP_TxTcpTransmit(TcpConIdx, DOIP_HEADER_TYPE_DIAG_ACK,
                                            DoIP_TcpConCtrlGetRxLastTargetAddr(TcpConIdx),0U, 0U, NULL_PTR, FALSE);
                /* notify pdur about complete reception */
                ChannelIdx = DoIP_TcpConCtrlGetRxLastChannelIdx(TcpConIdx);
                PduR_DoIPTpRxIndication(DoIP_ChannelCfgGetRxPduId(ChannelIdx),E_OK); 
                /* Reset Rx TcpCon status  */
                DoIP_TcpConCtrlSetRxMsgOffset(TcpConIdx,0U);
                DoIP_TcpConCtrlSetRxLastChannelIdx(TcpConIdx,DoIP_CfgGetNumOfChannel());
                DoIP_TcpConCtrlSetRxChannelActive(TcpConIdx,FALSE);
            }
            else
            {
                /* increment the offset */
                DoIP_TcpConCtrlSetRxMsgOffset(TcpConIdx,(RxMsgOffset+LocalPduInfoPtr->SduLength));
            }
        }
        *ReadDataLenPtr += LocalPduInfoPtr->SduLength; 
    }
}
/********************************************************************************************************************
* @brief  This api used to handle user data copy of the tcp diag message to pdur
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpDiagCopyDataToPduR
(
    DoIP_TcpConIdxType TcpConIdx,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_CONST) LocalPduInfoPtr
)
{
    Std_ReturnType RetVal = E_OK;
    DoIP_ChannelIdxType ChannelIdx;
    uint16 TesterAddr ;
    ChannelIdx = DoIP_TcpConCtrlGetRxLastChannelIdx(TcpConIdx);
    if (PduR_DoIPTpCopyRxData(DoIP_ChannelCfgGetRxPduId(ChannelIdx),LocalPduInfoPtr,BufferSizePtr) != BUFREQ_OK)
    {
        TesterAddr = DoIP_TesterCfgGetTesterAddr(DoIP_TcpConCtrlGetTesterIdx(TcpConIdx));
        if (TesterAddr == DOIP_ADDR_ANY)
        {
            TesterAddr = DoIP_TcpConCtrlGetTesterAddr(TcpConIdx);
        }
        
        /* send nack for invalid copy */
        DoIP_TxTcpPrepareTransmit(TcpConIdx,DOIP_HEADER_TYPE_DIAG_NACK,DoIP_TcpConCtrlGetRxLastTargetAddr(TcpConIdx),
                                   TesterAddr,DOIP_DIAG_MSG_RES_CODE_NETWORK_TRANSPROT,FALSE);
        /* notify PduR about invalid notification */
        PduR_DoIPTpRxIndication(DoIP_ChannelCfgGetRxPduId(ChannelIdx), E_NOT_OK);
        DoIP_TcpConCtrlSetRxSkipMsg(TcpConIdx,TRUE);
        DoIP_TcpConCtrlSetRxLastChannelIdx(TcpConIdx,DoIP_CfgGetNumOfChannel());
        DoIP_TcpConCtrlSetRxChannelActive(TcpConIdx,FALSE);
        RetVal = E_NOT_OK;
  }
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to process the received logical address
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpDiagHandleCopiedLogicalAddr(DoIP_TcpConIdxType TcpConIdx)
{
    uint16 SourceAddr;
    uint16 TargetAddr;
    uint8 *pRxHeaderBuffer;
    Std_ReturnType RetVal = E_NOT_OK;
    
    pRxHeaderBuffer = &DoIP_RxHeaderBuffer[DoIP_TcpConCfgGetRxHeaderBufferStartIdx(TcpConIdx)];
    
    SourceAddr = ((((uint16)(pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH])) << 8u) | 
                            (uint16)pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH+1u]);
    TargetAddr = ((((uint16)(pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH+DOIP_ADDR_LENGTH])) << 8u) | 
                            (uint16)pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH+DOIP_ADDR_LENGTH+1u]);
                            
    if (DoIP_TcpConCtrlGetRoutingActivationState(TcpConIdx) != DOIP_ROUTING_ACTIVATION_STATE_ACTIVATED)
    {
        /* send nack if routing activation not done */
        DoIP_TxTcpPrepareTransmit(TcpConIdx,DOIP_HEADER_TYPE_DIAG_NACK,TargetAddr,SourceAddr,
                                    DOIP_DIAG_MSG_RES_CODE_INVALID_SRC_ADDR, TRUE);
    }
    else if ((DoIP_TesterCfgGetTesterAddr(DoIP_TcpConCtrlGetTesterIdx(TcpConIdx)) == DOIP_ADDR_ANY) &&
             (DoIP_TcpConCtrlGetTesterAddr(TcpConIdx) != SourceAddr))
    {
        /* send nack for invalid address if default is configured */
        DoIP_TxTcpPrepareTransmit(TcpConIdx, DOIP_HEADER_TYPE_DIAG_NACK,TargetAddr,SourceAddr,
                                    DOIP_DIAG_MSG_RES_CODE_INVALID_SRC_ADDR,TRUE);
    }
    else if ((DoIP_TesterCfgGetTesterAddr(DoIP_TcpConCtrlGetTesterIdx(TcpConIdx)) != DOIP_ADDR_ANY) &&
             (DoIP_TesterCfgGetTesterAddr(DoIP_TcpConCtrlGetTesterIdx(TcpConIdx)) != SourceAddr))
    {
        /* send nack if invalid address */
        DoIP_TxTcpPrepareTransmit(TcpConIdx, DOIP_HEADER_TYPE_DIAG_NACK,TargetAddr,SourceAddr,
                                    DOIP_DIAG_MSG_RES_CODE_INVALID_SRC_ADDR,TRUE);
    }
    else
    {
        /* handle target logical address. */
        RetVal = DoIP_RxTcpDiagHandleTargetLogicalAddress(TcpConIdx);
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to process the target logical address
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpDiagHandleTargetLogicalAddress(DoIP_TcpConIdxType TcpConIdx)
{
    uint16 SourceAddr;
    uint16 TargetAddr;
    uint32 DiagMsgLength;
    uint8 *pRxHeaderBuffer;
    DoIP_ChannelIdxType ChannelIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    DoIP_GenericHeaderType GenericHeader={0};
    DoIP_RoutingActivationIdxType RoutingActivationIdx;
    
    pRxHeaderBuffer = &DoIP_RxHeaderBuffer[DoIP_TcpConCfgGetRxHeaderBufferStartIdx(TcpConIdx)];
    RoutingActivationIdx = DoIP_TcpConCtrlGetRoutingActivationIdx(TcpConIdx);
    /* update header length , source and target address */
    DOIP_UtilExtractGenericHeader(&GenericHeader,pRxHeaderBuffer);
    SourceAddr = ((((uint16)(pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH])) << 8u) | 
                            (uint16)pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH+1u]);
    TargetAddr = ((((uint16)(pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH+DOIP_ADDR_LENGTH])) << 8u) | 
                            (uint16)pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH+DOIP_ADDR_LENGTH+1u]);
    DiagMsgLength = GenericHeader.HeaderLength - DOIP_DIAG_MSG_REQ_MIN_LENGTH;
    ChannelIdx = DoIP_RxTcpDiagGetChannelByTgtAddrForRoutAct(RoutingActivationIdx,TargetAddr,DiagMsgLength);
    if (ChannelIdx == DoIP_CfgGetNumOfChannel())
    {
        ChannelIdx = DoIP_RxTcpDiagGetChannelByTgtAddr(TargetAddr);
        if (ChannelIdx == DoIP_CfgGetNumOfChannel())
        {
            /* send nack for invalid channel */
            DoIP_TxTcpPrepareTransmit(TcpConIdx,DOIP_HEADER_TYPE_DIAG_NACK,TargetAddr,SourceAddr,
                                        DOIP_DIAG_MSG_RES_CODE_TGT_UNREACHABLE, FALSE);
        }
        else
        {
            /* send nack for invalid target address */
            DoIP_TxTcpPrepareTransmit(TcpConIdx,DOIP_HEADER_TYPE_DIAG_NACK,TargetAddr,SourceAddr,
                                        DOIP_DIAG_MSG_RES_CODE_UNKNOWN_TGT_ADDR, FALSE);
        }
    }
    else if (DoIP_ChannelCfgGetTpMaxLength(ChannelIdx) < DiagMsgLength)
    {
        /* send nack for invalid length */
        DoIP_TxTcpPrepareTransmit(TcpConIdx, DOIP_HEADER_TYPE_DIAG_NACK,TargetAddr,SourceAddr,
                                    DOIP_DIAG_MSG_RES_CODE_MSG_TOO_LARGE, FALSE);
    } /* Todo: DoIP pdu size routing and user Verify target API */
    else
    {
        /* Accept target address and message length. */
        DoIP_TcpConCtrlSetRxLastChannelIdx(TcpConIdx,ChannelIdx);
        DoIP_TcpConCtrlSetRxChannelActive(TcpConIdx,TRUE);
        RetVal = E_OK;
  }
  return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to get the channel idx for the target address
********************************************************************************************************************/
DOIP_LOCAL FUNC(DoIP_ChannelIdxType, DOIP_CODE) DoIP_RxTcpDiagGetChannelByTgtAddr(uint16 TargetAddr) 
{
    DoIP_ChannelIdxType ChannelIdx;

    for (ChannelIdx = 0U;ChannelIdx<DoIP_CfgGetNumOfChannel();ChannelIdx++)
    {
        if(DoIP_ChannelCfgGetEcuAddr(ChannelIdx) == TargetAddr)
        {
            break;
        }   
    }
    return ChannelIdx;
}
/********************************************************************************************************************
* @brief  This api used to get the channel idx by the target address for the routing activation
********************************************************************************************************************/
DOIP_LOCAL FUNC(DoIP_ChannelIdxType, DOIP_CODE) DoIP_RxTcpDiagGetChannelByTgtAddrForRoutAct
(
    DoIP_RoutingActivationIdxType RoutingActivationIdx,
    uint16 TargetAddr,
    uint32 DataLen
)
{
    boolean IsChannelFound = FALSE;
    DoIP_ChannelIdxType ChannelIdx;
    
    for (ChannelIdx = DoIP_RoutingActivationCfgGetChannelEndIdx(RoutingActivationIdx);
         ChannelIdx < DoIP_RoutingActivationCfgGetChannelStartIdx(RoutingActivationIdx); ChannelIdx++)
    {
        IsChannelFound = TRUE;
        break;
    }
    if (IsChannelFound == FALSE)
    {
        ChannelIdx = DoIP_CfgGetNumOfChannel();
        /* Todo : handle pdu size routing */
    }
    DOIP_DUMMY_STATEMENT(TargetAddr);
    DOIP_DUMMY_STATEMENT(DataLen);
    return ChannelIdx;
}
/********************************************************************************************************************
* @brief  This api used to handle the valid diagnostic message 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpDiagHandleValidDiagnosticMessage
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr
)
{
    Std_ReturnType RetVal;
    PduInfoType ReadPduInfo;
    /* copy logical address */
    RetVal = DoIP_RxTcpDiagCopyLogicalAddr(TcpConIdx,PduInfoPtr,BufferSizePtr,ReadDataLenPtr);
    if (RetVal == E_OK)
    {
        /* update PduInfo with Read data len */
        ReadPduInfo.SduDataPtr = &PduInfoPtr->SduDataPtr[*ReadDataLenPtr];
        ReadPduInfo.SduLength = (PduInfoPtr->SduLength - *ReadDataLenPtr);
        /* check for user data */
        DoIP_RxTcpDiagAppendNackData(TcpConIdx, &ReadPduInfo);  
        RetVal = DoIP_RxTcpDiagVerifyRxPdu(TcpConIdx, PduInfoPtr, BufferSizePtr, ReadDataLenPtr); 
        if (RetVal == E_OK)
        {
            /* todo DOIP_VERIFY_RX_PDU_ENABLED */
            DoIP_RxTcpDiagCopyUserData(TcpConIdx, PduInfoPtr, BufferSizePtr, ReadDataLenPtr, &ReadPduInfo);
        }
    }
    
    if (RetVal == E_NOT_OK )
    {
        /* Skip message failed. */
        DoIP_TcpConCtrlSetRxSkipMsg(TcpConIdx,TRUE);
    }
}
/********************************************************************************************************************
* @brief  This api used to append nacka data for the rx tcp 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpDiagAppendNackData
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr
)
{
    uint32 BytesToCopy;
    DoIP_TesterIdxType TesterIdx;
    PduLengthType NumOfNegAckByte;
    PduLengthType NegativeAckOffset;
    
    if (PduInfoPtr->SduLength > 0U)
    {
        TesterIdx = DoIP_TcpConCtrlGetTesterIdx(TcpConIdx);
        NegativeAckOffset = DoIP_TesterCtrlGetNegativeAckOffset(TesterIdx);
        NumOfNegAckByte = DoIP_TesterCfgGetNumOfDiagAckNackRespBytes(TesterIdx);
        if (NumOfNegAckByte > 0U)
        {
            BytesToCopy = NumOfNegAckByte - NegativeAckOffset;
            if (BytesToCopy > PduInfoPtr->SduLength)
            {
                BytesToCopy = PduInfoPtr->SduLength;
            }
            /* copy data bytes */
            if (BytesToCopy > 0U)
            {
                DoIP_UtilMemCopy(
                    &DoIP_DiagNAckBuffer[DoIP_TesterCfgGetDiagNackBufferStartIdx(TesterIdx)+NegativeAckOffset],
                    PduInfoPtr->SduDataPtr,BytesToCopy);
                DoIP_TesterCtrlSetNegativeAckOffset(TesterIdx,(NegativeAckOffset+BytesToCopy));
            }
        }
    }
}
/********************************************************************************************************************
* @brief  This api used to handle verification of the rx pdu of tcp diag
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpDiagVerifyRxPdu
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr
)
{
    uint32 BytesToCopy;
    Std_ReturnType RetVal = E_NOT_OK;
    uint32 MinMsgReqLength;
    uint32 MaxMsgReqLength;
    uint32 MsgHeaderLength;
    uint8 *pRxHeaderBuffer;
    DoIP_GenericHeaderType GenericHeader={0};
    DoIP_TcpRxBufferIdxType RxMsgOffset;
    boolean IsMsgRxPending=FALSE;
    
    MinMsgReqLength = DOIP_GENERIC_HEADER_LENGTH + DOIP_DIAG_MSG_REQ_MIN_LENGTH;
    MaxMsgReqLength = MinMsgReqLength + DOIP_VERIFY_RX_PDU_MAX_DATA_LENGTH;
    RxMsgOffset =  DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx);
    pRxHeaderBuffer = &DoIP_RxHeaderBuffer[DoIP_TcpConCfgGetRxHeaderBufferStartIdx(TcpConIdx)];
    DOIP_UtilExtractGenericHeader(&GenericHeader,pRxHeaderBuffer);
    MsgHeaderLength = GenericHeader.HeaderLength + DOIP_GENERIC_HEADER_LENGTH;
    
#if ( DOIP_VERIFY_RX_PDU_MAX_DATA_LENGTH != 0U )
    if ((RxMsgOffset >= MinMsgReqLength) && (RxMsgOffset < MsgHeaderLength) && (RxMsgOffset < MaxMsgReqLength))
    {
        /* update bytes to copy */
        if ((MaxMsgReqLength - RxMsgOffset) <= (MsgHeaderLength - RxMsgOffset))
        {
            BytesToCopy = (MaxMsgReqLength - RxMsgOffset);
        }
        else
        {
            BytesToCopy = (MsgHeaderLength - RxMsgOffset);
        }
        DoIP_RxTcpGenCopyDataToHeaderBuffer(TcpConIdx,PduInfoPtr,ReadDataLenPtr,BytesToCopy);
        RxMsgOffset = DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx);
        if ((RxMsgOffset == MsgHeaderLength) || (RxMsgOffset == MaxMsgReqLength))
        {
#else
    if ((RxMsgOffset == MinMsgReqLength) && (DoIP_TcpConCtrlGetVerifyPduOffet(TcpConIdx) == 0U))
    {
        DoIP_TcpConCtrlSetVerifyPduOffet(TcpConIdx,1u);
        {
#endif
            RetVal = DoIP_RxTcpDiagHandleCopiedVerifyRxPdu(TcpConIdx,GenericHeader.HeaderLength,BufferSizePtr);
            IsMsgRxPending = TRUE;
        }
#if ( DOIP_VERIFY_RX_PDU_MAX_DATA_LENGTH != 0U )
        else
        {
            if ((MaxMsgReqLength - RxMsgOffset) <= (MsgHeaderLength - RxMsgOffset))
            {
                BytesToCopy = (MaxMsgReqLength - RxMsgOffset);
            }
            else
            {
                BytesToCopy = (MsgHeaderLength - RxMsgOffset);
            }
            
            if (BytesToCopy > DOIP_MAX_REQUEST_BYTES)
            {
                *BufferSizePtr = DOIP_MAX_REQUEST_BYTES;
            }
            else
            {
                *BufferSizePtr = BytesToCopy; 
            }
            DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx,*BufferSizePtr);
            RetVal = DOIP_E_PENDING;
            IsMsgRxPending = TRUE;
        }
    }
#endif        
    /* Check if message part is received completely. */
    if ((IsMsgRxPending == FALSE) && ((RxMsgOffset >= MaxMsgReqLength) || (RxMsgOffset >= MsgHeaderLength)))
    {
        RetVal = E_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to process the verified rx pdu of tcp diag
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpDiagHandleCopiedVerifyRxPdu
(
    DoIP_TcpConIdxType TcpConIdx,
    uint32 HeaderLength,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr
)
{
    uint16 SourceAddr;
    uint16 TargetAddr;
    uint8 *pRxHeaderBuffer;
    DoIP_ChannelIdxType ChannelIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    DoIP_GenericHeaderType GenericHeader={0};
    
    pRxHeaderBuffer = &DoIP_RxHeaderBuffer[DoIP_TcpConCfgGetRxHeaderBufferStartIdx(TcpConIdx)];
    DOIP_UtilExtractGenericHeader(&GenericHeader,pRxHeaderBuffer);
    
    SourceAddr = ((((uint16)(pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH])) << 8u) | 
                            (uint16)pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH+1u]);
    TargetAddr = ((((uint16)(pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH+DOIP_ADDR_LENGTH])) << 8u) | 
                            (uint16)pRxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH+DOIP_ADDR_LENGTH+1u]);
                            
    if (DoIP_TcpConCtrlGetRxChannelActive(TcpConIdx) == TRUE)
    {
        ChannelIdx = DoIP_TcpConCtrlGetRxLastChannelIdx(TcpConIdx);
        if (BUFREQ_OK != PduR_DoIPTpStartOfReception(DoIP_ChannelCfgGetRxPduId(ChannelIdx),NULL_PTR,
                                        (GenericHeader.HeaderLength-DOIP_DIAG_HDR_LENGTH),BufferSizePtr))
        {
            /* send nack for buffer reqeuest error */
            DoIP_TxTcpPrepareTransmit(TcpConIdx, DOIP_HEADER_TYPE_DIAG_NACK,TargetAddr,SourceAddr, 
                                            DOIP_DIAG_MSG_RES_CODE_OUT_OF_MEMORY, FALSE);
            RetVal = E_NOT_OK;
        }
        else
        {
            PduInfoType RxPduInfo;
            RxPduInfo.SduLength = 0U;
            /* update channel status */ 
            DoIP_TcpConCtrlSetRxLastChannelIdx(TcpConIdx,ChannelIdx);
            DoIP_TcpConCtrlSetRxChannelActive(TcpConIdx,TRUE);
            DoIP_TcpConCtrlSetRxLastTargetAddr(TcpConIdx,TargetAddr);
            /* copy data to PduR */
            RetVal = DoIP_RxTcpDiagCopyDataToPduR(TcpConIdx, BufferSizePtr, &RxPduInfo);
            if (RetVal == E_OK)
            {
                /* set buffer size */
                DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx,*BufferSizePtr);
            }
        }
    }
    DOIP_DUMMY_STATEMENT(HeaderLength);
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to handle the received logical address of the tcp diag
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpDiagCopyLogicalAddr
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) BufferSizePtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) ReadDataLenPtr
)
{
    uint32 BytesToCopy;
    Std_ReturnType RetVal = E_OK;
    DoIP_TcpRxBufferIdxType RxMsgOffset;
    
    RxMsgOffset = DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx);
    
    if (RxMsgOffset < (DOIP_GENERIC_HEADER_LENGTH + DOIP_DIAG_MSG_REQ_MIN_LENGTH))
    {
        BytesToCopy = (DOIP_GENERIC_HEADER_LENGTH + DOIP_DIAG_MSG_REQ_MIN_LENGTH) - RxMsgOffset;
        /* copy data to header buffer */
        DoIP_RxTcpGenCopyDataToHeaderBuffer(TcpConIdx,PduInfoPtr,ReadDataLenPtr,BytesToCopy);
        if (DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx) == (DOIP_GENERIC_HEADER_LENGTH + DOIP_DIAG_MSG_REQ_MIN_LENGTH))
        {
            RetVal = DoIP_RxTcpDiagHandleCopiedLogicalAddr(TcpConIdx);
        }
        else
        {
            BytesToCopy = (DOIP_GENERIC_HEADER_LENGTH + DOIP_DIAG_HDR_LENGTH)-DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx);
            if (BytesToCopy > DOIP_MAX_REQUEST_BYTES)
            {
                *BufferSizePtr = DOIP_MAX_REQUEST_BYTES;
            }
            else
            {
                *BufferSizePtr = BytesToCopy;
            }
            DoIP_TcpConCtrlSetRxLastBufferSize(TcpConIdx,*BufferSizePtr);
            RetVal = DOIP_E_PENDING;
        }
    }
    return RetVal;
}
#if (DOIP_OEM_PAYLOAD_TCP_BUFFER_SIZE > 0U)
/********************************************************************************************************************
* @brief  This api used to handle the oem payload type of the received tcp data
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpOemHandleCopiedOemPayloadTypes(DoIP_TcpConIdxType TcpConIdx)
{
    DoIP_GenericHeaderType GenericHeader={0};
    uint16 OemHeaderType=DOIP_HEADER_TYPE_INVALID;
    uint8 TcpOemFlags=DOIP_OEM_PAYLOAD_TYPE_PROT_TCP;
    uint8 * pOemTcpBuffer;
    PduInfoType RxUserPduInfo;
    PduInfoType TxUserPduInfo;
    
    pOemTcpBuffer = &DoIP_OemPayloadTcpBuffer[0U];
    DOIP_UtilExtractGenericHeader(&GenericHeader,pRxHeaderBuffer);
    if (DoIP_TcpConCtrlGetRoutingActivationState(TcpConIdx) == DOIP_ROUTING_ACTIVATION_STATE_ACTIVATED)
    {
        TcpOemFlags |= DOIP_OEM_PAYLOAD_TYPE_ROUT_ACTIV;
    }
    /* update Rx PduInfo */
    RxUserPduInfo.SduDataPtr = &DoIP_OemPayloadTcpBuffer[0];
    RxUserPduInfo.SduLength = (DoIP_TcpConCtrlGetRxMsgOffset(TcpConIdx) - DOIP_GENERIC_HEADER_LENGTH);
    /* update Tx PduInfo */
    TxUserPduInfo.SduDataPtr = &DoIP_OemPayloadTcpBuffer[0];
    RxUserPduInfo.SduLength = DOIP_OEM_PAYLOAD_TCP_BUFFER_SIZE;
    /* copy data from upper layer */
    if (E_NOT_OK == DoIP_UserGetPayloadCallbackFn(GenericHeader.HeaderType,&RxUserPduInfo,
                        TcpOemFlags,&OemHeaderType,&TxUserPduInfo))
    {
        /* Send Nack if payload type are unkown. */
        (void)DoIP_TxTcpTransmit(TcpConIdx, DOIP_HEADER_TYPE_GEN_NACK, DOIP_GEN_NACK_TYPE,0U, 0U, NULL_PTR,FALSE);
        DoIP_OemPayloadCtrlSetTcpBufferConIdx(DoIP_CfgGetNumOfConnection());
    }
    else
    {
        /* Send user data response */
        if (OemHeaderType != DOIP_HEADER_TYPE_INVALID)
        {
            if (TxUserPduInfo.SduLength <= DOIP_OEM_PAYLOAD_TCP_BUFFER_SIZE)
            {
                DoIP_OemPayloadCtrlSetTcpBufferLength(TxUserPduInfo.SduLength);
                if (TxUserPduInfo.SduLength > 0U)
                {
                    DoIP_OemPayloadCtrlSetTcpBufferReqTx(TRUE);
                }
                
                if (E_NOT_OK == DoIP_TxTcpTransmit(TcpConIdx, DOIP_HEADER_TYPE_OEM_SPECIFIC,OemHeaderType,
                                                    0U,0U,NULL_PTR,FALSE))
                {
                    DoIP_OemPayloadCtrlSetTcpBufferConIdx(DoIP_CfgGetNumOfConnection());
                }
            }
            else
            {
                DoIP_OemPayloadCtrlSetTcpBufferConIdx(DoIP_CfgGetNumOfConnection());
            }
        }
        else
        {
            DoIP_OemPayloadCtrlSetTcpBufferConIdx(DoIP_CfgGetNumOfConnection());
        }
    }
    DoIP_TcpConCtrlSetRxMsgOffset(TcpConIdx,0U);
}
#endif

/********************************************************************************************************************
* @brief  This api used to handle the routing activation alive check timeout and close socket if required
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_RxTcpRoutHandleAliveCheckTimeoutsSocketsClose(void)
{
    /* TODO update alive timer */
}
/********************************************************************************************************************
* @brief  This api used to handle the routing activation conncetion check 
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_RxTcpRoutCheckConnectionAvailablility(DoIP_ConIdxType ConIdx)
{
    Std_ReturnType RetVal = E_NOT_OK;
    DoIP_TcpConIdxType TcpConIdx;
    uint16 TesterAddr;
    if (DoIP_ConCtrlGetSoConMode(ConIdx) == SOAD_SOCON_ONLINE)
    {
        TesterAddr = DoIP_RoutingActivationCtrlGetTesterAddr();
        TcpConIdx = DoIP_TesterCtrlGetTcpConIdx(TesterAddr);
        if (TcpConIdx != DoIP_CfgGetNumOfTcpConnection())
        {
            /* Deny routing activation */
            (void)DoIP_TxTcpTransmit(TcpConIdx,DOIP_HEADER_TYPE_ROUT_ACTIV_RES,TesterAddr,
                                        DOIP_ROUT_ACTIV_RES_CODE_ALREADY_ACTIV, 0u, NULL_PTR, TRUE);
        }
        else
        {
            if (DoIP_RxTcpRoutGetAvailableSockNum(DoIP_ConCfgGetLocalIpAddrIdx(ConIdx)) == 0u)
            {
                /* Deny routing activation if all socket are in use */
                (void)DoIP_TxTcpTransmit(TcpConIdx, DOIP_HEADER_TYPE_ROUT_ACTIV_RES,TesterAddr,
                                        DOIP_ROUT_ACTIV_RES_CODE_SOCKETS_IN_USE, 0u, NULL_PTR, TRUE);
            }
            else
            {
                /* accept routing activation.  */
                RetVal = E_OK;
            }
        }
    }
    return RetVal;
}
#define DOIP_STOP_SEC_CODE
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
*  @date    29-Dec-2023
*  @version 1.0.0
*  @author  pchinnat
*  @brief   Traceability - AUTOSAR 4.3 version initial implementation 
*******************************************************************************************************************/

