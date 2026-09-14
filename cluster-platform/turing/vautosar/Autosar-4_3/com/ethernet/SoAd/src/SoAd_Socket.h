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
*   @file SoAd_Socket.c
*   @ingroup SoAd
*   @brief The main purpose of the SoAd_Socket is to implement the socket functionality api and data type. 
********************************************************************************************************************/
#ifndef SOAD_SOCKET_H
#define SOAD_SOCKET_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/

/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
#define SOAD_START_SEC_CODE
#include "MemMap.h" 
/*!******************************************************************************************************************
* @brief The Api is used to initialize the socket properties
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketInit(void);
/*!******************************************************************************************************************
* @brief The Api is used to set the local port of the socket
* @param[in] SocketIdx the socket idx
* @param[in] Port the port value
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketSetLocalPort(SoAd_SocketIdxType SocketIdx,SoAd_PortType Port);
/*!******************************************************************************************************************
* @brief The Api is used to get the local port of the socket
* @param[in] SocketIdx the socket idx
* @return the port value
********************************************************************************************************************/
FUNC(SoAd_PortType, SOAD_CODE) SoAd_SocketGetLocalPort(SoAd_SocketIdxType  SocketIdx);
/*!******************************************************************************************************************
* @brief The Api is used to open the Udp socket
* @param[in] SocketIdx the socket idx
* @return status of the request E_OK:request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SocketUdpOpen(SoAd_SocketIdxType SocketIdx);
/*!******************************************************************************************************************
* @brief The Api is used to open the Tcp server socket
* @param[in] ListenSockIdx the listen socket idx
* @return status of the request E_OK:request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SocketTcpOpenServer(SoAd_SocketIdxType ListenSockIdx);
/*!******************************************************************************************************************
* @brief The Api is used to open the Tcp client socket
* @param[in] SocketIdx the socket idx
* @param[in] pRemoteAddr pointer to the remote address
* @return status of the request E_OK:request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SocketTcpOpenClient
(
    SoAd_SocketIdxType SocketIdx,
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) pRemoteAddr
);
/*!******************************************************************************************************************
* @brief The Api is used to handle the Udp close event
* @param[in] SocketIdx the socket idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketUdpEventClose(SoAd_SocketIdxType SocketIdx);
/*!******************************************************************************************************************
* @brief The Api is used to handle the tcp close event
* @param[in] SocketIdx the socket idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketTcpEventClose(SoAd_SocketIdxType SocketIdx);
/*!******************************************************************************************************************
* @brief The Api is used to handle the tcp FIN event
* @param[in] SocketIdx the socket idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketTcpEventFinReceived(SoAd_SocketIdxType SocketIdx);
/*!******************************************************************************************************************
* @brief The Api is used to get the socket idx from the tcpip socket idx
* @param[in] TcpIpSocketId the tcpip socket idx
* @param[out] pSocketIdx pointer to update the valid socket idx
* @return status of the request E_OK:socket idx found E_NOT_OK: socket idx not found 
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SocketGetSocketIdxByTcpIpSocketId
(
    TcpIp_SocketIdType TcpIpSocketId,
    P2VAR(SoAd_SocketIdxType, AUTOMATIC, SOAD_APPL_DATA) pSocketIdx
);
/*!******************************************************************************************************************
* @brief The Api is used to handle the tcp close request
* @param[in] SocketIdx the socket idx
* @param[in] Abort TRUE: close immdediately FALSE: close after completing pending tx/rx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketTcpClose(SoAd_SocketIdxType SocketIdx,boolean Abort);
/*!******************************************************************************************************************
* @brief The Api is used to handle the tcp close request for listen socket
* @param[in] SocketIdx the socket idx
* @param[in] Abort TRUE: close immdediately FALSE: close after completing pending tx/rx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketTcpCloseListen(SoAd_SocketIdxType SocketIdx, boolean Abort);
/*!******************************************************************************************************************
* @brief The Api is used to handle the tcp close request
* @param[in] SocketIdx the socket idx
* @param[in] Abort TRUE: close immdediately FALSE: close after completing pending tx/rx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketUdpClose(SoAd_SocketIdxType SocketIdx, boolean Abort);
/*!******************************************************************************************************************
* @brief The Api is used to process the change parameter request for the socket idx
* @param[in] SocketIdx SoAd socket id
* @param[in] ParameterId tcpip parameter id of the bsd TcpIp
* @param[out] ParameterValue pointer to tcpip parameter value 
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SocketTcpIpChangeParameter
(
    SoAd_SocketIdxType SocketIdx,
    TPParameterType Parameter,
    uint16 Value
);
/*!******************************************************************************************************************
* @brief The Api is used to indicate the accepted tcpip socket id for the listen socket idx 
* @param[in] SocketIdx socket idx
* @param[in] SocketIdConnected tcpip socket idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketTcpSetAcceptedSocketId
(
    SoAd_SocketIdxType SocketIdx,
    SoAd_SocketIdxType SocketIdConnected
);
/*!******************************************************************************************************************
* @brief The Api is used to indicate the processed tcp data for the socket
* @param[in] SocketIdx socket idx
* @param[in] Length length of the data processed
********************************************************************************************************************/
FUNC(void,SOAD_CODE) SoAd_SocketTcpReceived(SoAd_SocketIdxType SocketIdx,PduLengthType Length);
/*!******************************************************************************************************************
* @brief The Api is used to check and udpate skip data for the socket
* @param[in] SocketIdx socket idx
* @param[in] Length length of the data received
* @param[out] SkippedLengthPtr pointer to length of the skip data
* @return E_OK: if skip data is present E_NOT_OK: if skip data is not present
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SocketTcpCheckAndUpdateSkipData
(
    SoAd_SocketIdxType SocketIdx,
    uint16 Length,
    P2VAR(uint16, AUTOMATIC, SOAD_APPL_VAR) SkippedLengthPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to check and udpate skip data for the socket
* @param[in] SocketIdx socket idx
* @param[out] ReleaseBufLenPtr pointer to release buffer length
* @param[in] TotalLen length of the data received
* @return E_OK: if skip data is present E_NOT_OK: if skip data is not present
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_SocketTcpUpdateSkipData
(
    SoAd_SocketIdxType SocketIdx,
    P2VAR(uint32, AUTOMATIC, SOAD_APPL_VAR) ReleaseBufLenPtr,
    uint32 TotalLen
);
/*!******************************************************************************************************************
* @brief The Api is used to transmit the data on the Udp socket
* @param[in] SocketIdx socket idx
* @param[in] pRemoteAddr pointer to remote address
* @param[in] TotalLength length of the data to be transmitted
* @return E_OK: if tx success E_NOT_OK: if tx not success
********************************************************************************************************************/
FUNC(Std_ReturnType,SOAD_CODE) SoAd_SocketUdpTransmit
(
    SoAd_SocketIdxType SocketIdx,
    SoAd_SockAddrType *pRemoteAddr,
    uint16 TotalLength
);
/*!******************************************************************************************************************
* @brief The Api is used to transmit the data on the Tcp socket
* @param[in] SocketIdx socket idx
* @param[in] AvailableLength total length to transmit
* @param[in] ForceRetrieve Indicates how the TCP/IP stack retrieves data from upper layer.
* @return E_OK: if tx success E_NOT_OK: if tx not success
********************************************************************************************************************/
FUNC(Std_ReturnType,SOAD_CODE) SoAd_SocketTcpTransmit
(
    SoAd_SocketIdxType SocketIdx,
    uint32 AvailableLength, 
    boolean ForceRetrieve
);
/*!******************************************************************************************************************
* @brief The Api is used to change the parameter value of the socket 
* @param[in] SocketIdx socket idx
* @param[in] TcpIpSocketId tcpip socket idx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_SocketTcpChangeParameter(SoAd_SocketIdxType SocketId,TcpIp_SocketIdType TcpIpSocketId);

#define SOAD_STOP_SEC_CODE
#include "MemMap.h" 

#endif /* SOAD_SOCKET_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

