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
*   @file SoAd_Cbk.h
*   @ingroup SoAd
*   @brief This file provides list of functions provided for other modules. The function prototypes of the 
*   callback functions shall be provided in the file SoAd_Cbk.h
********************************************************************************************************************/
#ifndef SOAD_CBK_H
#define SOAD_CBK_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComStack_Types.h"
#include "SoAd_Types.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/*! @brief Defines the SoAd Callback AUTOSAR major version */ 
#define SOAD_CBK_AR_RELEASE_MAJOR_VERSION  4U
/*! @brief Defines the SoAd Callback AUTOSAR minor version */ 
#define SOAD_CBK_AR_RELEASE_MINOR_VERSION  3U
/*! @brief Defines the SoAd Callback AUTOSAR patch version */ 
#define SOAD_CBK_AR_RELEASE_PATCH_VERSION  1U

/********************************************************************************************************************
*  PUBLIC CALLBACK FUNCTION PROTOTYPE                                                                               *
********************************************************************************************************************/
#define SOAD_START_SEC_CODE
#include "MemMap.h"

/*!******************************************************************************************************************
*   @brief      The TCP/IP stack calls this primitive after the reception of data on a socket. The socket identifier 
*               along with configuration information determines which module is to be called.
*   @param[in]  SocketId Socket identifier of the related local socket resource.
*   @param[in]  RemoteAddrPtr Pointer to memory containing IP address and port of the remote host which sent the data
*   @param[in]  BufPtr Pointer to the received data.
*   @param[in]  Length Data length of the received TCP segment or UDP datagram.=
*   @ServiceID  0x12
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different SocketIds. Non reentrant for the same SocketId 
********************************************************************************************************************/
extern FUNC(void, SOAD_CODE) SoAd_RxIndication
( 
    TcpIp_SocketIdType SocketId,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_CONST) RemoteAddrPtr,
    P2CONST(uint8,AUTOMATIC,SOAD_APPL_CONST) BufPtr,
    uint16 Length 
);
/*!******************************************************************************************************************
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
extern FUNC(BufReq_ReturnType, SOAD_CODE) SoAd_CopyTxData
( 
    TcpIp_SocketIdType SocketId,
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_VAR) BufPtr,
    uint16 BufLength 
);
/*!******************************************************************************************************************
*   @brief      The TCP/IP stack calls this function after the data has been acknowledged by the peer for TCP.
*   @param[in]  SocketId Socket identifier of the related local socket resource.
*   @param[in]  Length Number of transmitted data bytes.
*   @ServiceID  0x14
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different SocketIds. Non reentrant for the same SocketId 
********************************************************************************************************************/
extern FUNC(void, SOAD_CODE) SoAd_TxConfirmation( TcpIp_SocketIdType SocketId, uint16 Length );
/*!******************************************************************************************************************
*   @brief      This service gets called if the stack put a socket into the listen mode before (as server) and a peer
*               connected to it (as client). In detail: The TCP/IP stack calls this function after a socket was set
*               into the listen state with TcpIp_TcpListen() and a TCP connection is requested by the peer.
*   @param[in]  SocketId Socket identifier of the related local socket resource which has been used at TcpIp_Bind()
*   @param[in]  SocketIdConnected Socket identifier of the local socket resource used for the established connection
*   @param[in]  RemoteAddrPtr IP address and port of the remote host.
*   @return     Std_ReturnType Result of operation E_OK upper layer accepts the established connection 
*               E_NOT_OK upper layer refuses the established connection, TcpIp stack shall close the connection.
*   @ServiceID  0x15
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpAccepted
( 
    TcpIp_SocketIdType SocketId,
    TcpIp_SocketIdType SocketIdConnected,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_CONST) RemoteAddrPtr 
);
/*!******************************************************************************************************************
*   @brief      This service gets called if the stack initiated a TCP connection before (as client) and the peer
*               (the server) acknowledged the connection set up. In detail: The TCP/IP stack calls this function 
*               after a socket was requested to connect with TcpIp_TcpConnect() and a TCP connection is confirmed 
*               by the peer. The parameter value of SocketId equals the SocketId value of the preceeding 
*               TcpIp_TcpConnect() call
*   @param[in]  SocketId Socket identifier of the related local socket resource.
*   @ServiceID  0x16
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(void, SOAD_CODE) SoAd_TcpConnected( TcpIp_SocketIdType SocketId );
/*!******************************************************************************************************************
*   @brief      This service gets called if the stack encounters a condition described by the values in Event
*   @param[in]  SocketId Socket identifier of the related local socket resource
*   @param[in]  Event This parameter contains a description of the event just encountered
*   @ServiceID  0x17
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(void, SOAD_CODE) SoAd_TcpIpEvent( TcpIp_SocketIdType SocketId, TcpIp_EventType Event );
/*!******************************************************************************************************************
*   @brief      This service gets called by the TCP/IP stack if an IP address assignment changes (i.e. new address 
*               assigned or assigned address becomes invalid).
*   @param[in]  IpAddrId IP address Identifier, representing an IP address specified in the TcpIp module configuraiton
*               (e.g. static IPv4 address on EthIf controller 0).
*   @param[in]  State state of IP address assignment
*   @ServiceID  0x18
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(void, SOAD_CODE) SoAd_LocalIpAddrAssignmentChg(TcpIp_LocalAddrIdType IpAddrId,TcpIp_IpAddrStateType State);

#define SOAD_STOP_SEC_CODE
#include "MemMap.h"

#endif /* SOAD_CBK_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
