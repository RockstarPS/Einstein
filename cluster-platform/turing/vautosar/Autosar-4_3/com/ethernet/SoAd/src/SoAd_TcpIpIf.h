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
*   @file SoAd_TcpIpIf.h
*   @ingroup SoAd
*   @brief This module implements the TcpIp interface which is used by SoAd. 
********************************************************************************************************************/
#ifndef SOAD_TCPIP_IF
#define SOAD_TCPIP_IF
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "SoAd_TcpIpBsd.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
/*!******************************************************************************************************************
* @brief The Api is used to request the Ip address assignment of the the TcpIp
* @param[in] LocalAddrIdx loacl addr id
* @param[in] Type the assignment type of the local addr
* @param[in] LocalIpAddrPtr pointer to the local addr
* @param[in] Netmask netmask cidr value
* @param[in] DefaultRouterPtr pointer to the default router addr
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfRequestIpAddrAssignment
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    TcpIp_IpAddrAssignmentType Type,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_CONST) LocalIpAddrPtr,
    uint8 Netmask,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_CONST) DefaultRouterPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to release the ip addr assigned  of the the TcpIp
* @param[in] LocalAddrIdx loacl addr id
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfReleaseIpAddrAssignment(SoAd_LocalIpAddrIdxType LocalAddrIdx);
/*!******************************************************************************************************************
* @brief The Api is used to get the current ip address assigned to the local addr id of the the TcpIp
* @param[in] LocalAddrIdx loacl addr id
* @param[out] LocalAddrPtr pointer to update the local addr
* @param[out] NetmaskPtr pointer to update the net mask
* @param[out] DefaultRouterPtr pointer to update the default router
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfGetIpAddr
(   
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    P2VAR(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_VAR) LocalAddrPtr,
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_VAR) NetmaskPtr,
    P2VAR(TcpIp_SockAddrType,AUTOMATIC,SOAD_APPL_VAR) DefaultRouterPtr 
);
/*!******************************************************************************************************************
* @brief The Api is used to get the physicall addr(MAC) of the local addr id of the the TcpIp
* @param[in] LocalAddrIdx local addr id
* @param[in] TcpIpSocketId tcpip socket id
* @param[out] PhysAddrPtr pointer to the physical address buffer 
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfGetPhysAddr
(   
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    SoAd_SocketIdxType   SocketIdx,
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_VAR) PhysAddrPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to read the DHCP host name of the the TcpIp
* @param[in] LocalAddrIdx local addr id
* @param[out] LengthPtr pointer to the length of the host name read
* @param[out] DataPtr pointer to the host name read
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfDhcpReadOption
(   
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_VAR) length,
    P2VAR(uint8,AUTOMATIC,SOAD_APPL_VAR) data
);
/*!******************************************************************************************************************
* @brief The Api is used to write the DHCP host name of the the TcpIp
* @param[in] LocalAddrIdx local addr id
* @param[in] Length length of the host name data 
* @param[in] DataPtr pointer to the host name data 
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfDhcpWriteOption
(   
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    uint8 length,
    P2CONST(uint8,AUTOMATIC,SOAD_APPL_CONST) data
);
/*!******************************************************************************************************************
* @brief The Api is used to get and reset the measurement data
* @param[in] MeasurementIdx local addr id
* @param[in] Length length of the host name data 
* @param[out] DataPtr pointer to the host name data 
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfGetAndResetMeasurementData
( 
    SoAd_MeasurementIdxType MeasurementIdx,
    boolean MeasurementResetNeeded,
    P2VAR(uint32,AUTOMATIC,SOAD_APPL_VAR) MeasurementDataPtr 
);
/*!******************************************************************************************************************
* @brief The Api is used to trigger the address resolution to check for remote address
* @param[in] LocalAddrIdx local addr id
* @param[in] RemoteAddr pointer to the remote addr
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpIfTriggerAddressResolution
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    SoAd_SockAddrType RemoteAddr
);
/*!******************************************************************************************************************
* @brief The Api request to transmit UDP data the TcpIp
* @param[in] SocketIdx SoAd socket id
* @param[in] TcpIpSocketIdx tcpip socket id 
* @param[out] RemAddrPtr pointer to remote address to which the data to be transmitted
* @param[in] AvailableLength udp transmit length
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType,SOAD_CODE) SoAd_TcpIpIfUdpTransmit
(
    SoAd_SocketIdxType TcpIpSocketId,
    SoAd_SockAddrType *pRemoteAddr,
    uint16 TotalLength
);
/*!******************************************************************************************************************
* @brief The Api request to transmit Tcp data of the the TcpIp
* @param[in] SocketIdx SoAd socket id
* @param[in] TcpIpSocketIdx tcpip socket id 
* @param[in] AvailableLength tcp transmit length
* @param[in] ForceRetrieve Indicates how the TCP/IP stack retrieves data from upper layer 
*   TRUE: the whole data indicated by availableLength shall be retrieved from the upper layer via one or multiple 
*   <Up>_CopyTxData() calls within the context of this transmit function. 
*   FALSE: The TCP/IP stack may retrieve up to availableLength data from the upper layer. It is allowed to retrieve 
*   less than availableLength bytes.
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType,SOAD_CODE) SoAd_TcpIpIfTcpTransmit
(
    SoAd_SocketIdxType SocketIdx,
    uint32 AvailableLength, 
    boolean ForceRetrieve
);
/*!******************************************************************************************************************
* @brief The Api is used to change the socket parameter of the the TcpIp
* @param[in] SocketId SoAd socket id
* @param[in] TcpIpSocketId tcpip socket id 
* @param[in] ParameterId tcpip parameter id of the TcpIp
* @param[out] ParameterValue pointer to tcpip parameter value 
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfChangeParameter 
(
    SoAd_SocketIdxType SocketId,
    TcpIp_SocketIdType TcpIpSocketId,
    SoAd_TcpIpParameterType ParameterId,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) ParameterValue
);
/*!******************************************************************************************************************
* @brief The Api is used to handle the Tcp connect of the the TcpIp
* @param[in] SocketIdx SoAd socket id
* @param[in] TcpIpSocketId tcpip socket id
* @param[in] RemAddrPtr pointer to the remote address to connect 
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfTcpConnect
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketId, 
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemAddrPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to handle tcp listen of the the TcpIp
* @param[in] ListenSocketIdx SoAd listen socket id
* @param[in] TcpIpSocketIdx tcpip socket id
* @param[in] MaxChannels max number of connections it can accept
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfTcpListen
(
    SoAd_SocketIdxType ListenSocketIdx,
    TcpIp_SocketIdType SocketIdx,
    uint16 MaxChannels
);
/*!******************************************************************************************************************
* @brief The Api is used to bind the socket of the TcpIp
* @param[in] SocketIdx SoAd socket id
* @param[in] TcpIpSocketIdx tcpip socket id
* @param[out] PortPtr pointer to the port that is binded to the socket
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfBind
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIPSocketIdx,
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    P2VAR(SoAd_PortType, AUTOMATIC, SOAD_APPL_VAR) PortPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to get the socket of the TcpIp
* @param[in] SocketId SoAd socket id
* @param[in] Domain Ipv4 or Ipv6
* @param[in] Protocol tcp or udp socket
* @param[in] LocalAddrIdx local addr id
* @param[out] SocketIdPtr pointer to tcp socket id
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfGetSocket
(
    SoAd_SocketIdxType SocketId,
    SoAd_DomainType Domain,
    SoAd_ProtocolType Protocol,
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    P2VAR(TcpIp_SocketIdType, AUTOMATIC, SOAD_APPL_DATA) SocketIdPtr
);
/*!******************************************************************************************************************
* @brief The Api is used close the socket of the TcpIp
* @param[in] SocketIdx SoAd socket id 
* @param[in] TcpIpSocketIdx tcpip socket id
* @param[in] Abort close type TRUE: close immediately FALSE: close after completing pending tx,rx
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpIfClose
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketIdx,
    boolean Abort
);
/*!******************************************************************************************************************
* @brief The Api is used indicate that the SoAd has received and processed the message
* @param[in] SocketIdx the SoAd socket id on which the message received
* @param[in] Length the length of the processsed received message
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpIfTcpReceived(SoAd_SocketIdxType SocketIdx,PduLengthType Length);

#endif /* SOAD_TCPIP_IF */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
