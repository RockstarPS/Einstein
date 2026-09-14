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
*   @file SoAd_TcpIpBsd.h
*   @ingroup SoAd
*   @brief This module implements the bsd socket interface for Linux. 
********************************************************************************************************************/
#ifndef SOAD_TCPIPBSD_H
#define SOAD_TCPIPBSD_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "SoAd_Cfg.h"
#if (SOAD_TCPIP_API == SOAD_TCPIP_API_LINUX)
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
/*!******************************************************************************************************************
* @brief The Api is used to initialize the bsd TcpIp
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpBsdInit(void);
/*!******************************************************************************************************************
* @brief The Api is used to request the Ip address assignment of the the bsd TcpIp
* @param[in] LocalAddrIdx loacl addr id
* @param[in] Type the assignment type of the local addr
* @param[in] LocalIpAddrPtr[in] pointer to the local addr
* @param[in] Netmask netmask cidr value
* @param[in] DefaultRouterPtr[in] pointer to the default router addr
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdRequestIpAddrAssignment
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    SoAd_IpAddrAssignmentType Type,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) LocalIpAddrPtr,
    uint8 Netmask,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) DefaultRouterPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to release the ip addr assigned  of the the bsd TcpIp
* @param[in] LocalAddrIdx loacl addr id
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdReleaseIpAddrAssignment(SoAd_LocalIpAddrIdxType LocalAddrIdx);
/*!******************************************************************************************************************
* @brief The Api is used to get the current ip address assigned to the local addr id of the the bsd TcpIp
* @param[in] LocalAddrIdx loacl addr id
* @param[out] LocalAddrPtr pointer to update the local addr
* @param[out] NetmaskPtr pointer to update the net mask
* @param[out] DefaultRouterPtr pointer to update the default router
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpBsdGetIpAddr
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) LocalAddrPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) NetmaskPtr,
    P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) DefaultRouterPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to get the physicall addr(MAC) of the local addr id of the the bsd TcpIp
* @param[in] LocalAddrIdx local addr id
* @param[in] TcpIpSocketId bsd socket id
* @param[out] PhysAddrPtr pointer to the physical address buffer 
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdGetPhysAddr
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    TcpIp_SocketIdType TcpIpSocketId,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) PhysAddrPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to read the DHCP host name of the the bsd TcpIp
* @param[in] LocalAddrIdx local addr id
* @param[out] LengthPtr pointer to the length of the host name read
* @param[out] DataPtr pointer to the host name read
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdReadDhcpHostNameOption
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) LengthPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) DataPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to write the DHCP host name of the the bsd TcpIp
* @param[in] LocalAddrIdx local addr id
* @param[in] Length length of the host name data 
* @param[in] DataPtr pointer to the host name data 
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdWriteDhcpHostNameOption
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    uint8 Length,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) DataPtr
);
/*!******************************************************************************************************************
* @brief The Api request to transmit UDP data the bsd TcpIp
* @param[in] SocketIdx SoAd socket id
* @param[in] TcpIpSocketIdx bsd socket id 
* @param[out] RemAddrPtr pointer to remote address to which the data to be transmitted
* @param[in] AvailableLength udp transmit length
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdUdpTransmit
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketId,
    P2VAR(SoAd_SockAddrType, AUTOMATIC, AUTOMATIC) RemAddrPtr,
    uint16 AvailableLength
);
/*!******************************************************************************************************************
* @brief The Api request to transmit Tcp data of the the bsd TcpIp
* @param[in] SocketIdx SoAd socket id
* @param[in] TcpIpSocketIdx bsd socket id 
* @param[in] AvailableLength tcp transmit length
* @param[in] ForceRetrieve Indicates how the TCP/IP stack retrieves data from upper layer 
*   TRUE: the whole data indicated by availableLength shall be retrieved from the upper layer via one or multiple 
*   <Up>_CopyTxData() calls within the context of this transmit function. 
*   FALSE: The TCP/IP stack may retrieve up to availableLength data from the upper layer. It is allowed to retrieve 
*   less than availableLength bytes.
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdTcpTransmit
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketIdx,
    uint32 AvailableLength,
    boolean ForceRetrieve
);
/*!******************************************************************************************************************
* @brief The Api is used to change the socket parameter of the the bsd TcpIp
* @param[in] SocketId SoAd socket id
* @param[in] TcpIpSocketId bsd socket id 
* @param[in] ParameterId tcpip parameter id of the bsd TcpIp
* @param[out] ParameterValue pointer to tcpip parameter value 
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdChangeParameter
(
    SoAd_SocketIdxType SocketId,
    TcpIp_SocketIdType TcpIpSocketId,
    SoAd_TcpIpParameterType ParameterId,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) ParameterValue
);
/*!******************************************************************************************************************
* @brief The Api is used for hanlding the mulicast group join request of the the bsd TcpIp
* @param[in] SocketId SoAd socket id
* @param[in] TcpIpSocketId bsd socket id
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdJoinMultiCastGroupV4
(
    SoAd_SocketIdxType SocketId,
    TcpIp_SocketIdType TcpIpSocketId
);
/*!******************************************************************************************************************
* @brief The Api is used to handle the Tcp connect of the the bsd TcpIp
* @param[in] SocketIdx SoAd socket id
* @param[in] TcpIpSocketId bsd socket id
* @param[in] RemAddrPtr pointer to the remote address to connect 
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
Std_ReturnType SoAd_TcpIpBsdTcpConnect
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketId,
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemAddrPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to handle tcp listen of the the bsd TcpIp
* @param[in] ListenSocketIdx SoAd listen socket id
* @param[in] TcpIpSocketIdx bsd socket id
* @param[in] MaxChannels max number of connections it can accept
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdTcpListen
(
    SoAd_SocketIdxType ListenSocketIdx,
    TcpIp_SocketIdType TcpIpSocketIdx,
    uint16 MaxChannels
);
/*!******************************************************************************************************************
* @brief The Api is used to bind the socket of the bsd TcpIp
* @param[in] SocketIdx SoAd socket id
* @param[in] TcpIpSocketIdx bsd socket id
* @param[out] PortPtr pointer to the port that is binded to the socket
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdBind
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketIdx,
    P2VAR(SoAd_PortType, AUTOMATIC, SOAD_APPL_VAR) PortPtr
);
/*!******************************************************************************************************************
* @brief The Api is used to get the socket of the bsd TcpIp
* @param[in] SocketId SoAd socket id
* @param[in] Domain Ipv4 or Ipv6
* @param[in] Protocol tcp or udp socket
* @param[in] LocalAddrIdx local addr id
* @param[out] SocketIdPtr pointer to bsd socket id
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdGetSocket
(
    SoAd_SocketIdxType SocketId,
    SoAd_DomainType Domain,
    SoAd_ProtocolType Protocol,
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    P2VAR(TcpIp_SocketIdType, AUTOMATIC, SOAD_APPL_DATA) SocketIdPtr
);
/*!******************************************************************************************************************
* @brief The Api is used close the socket of the bsd TcpIp
* @param[in] SocketIdx SoAd socket id 
* @param[in] TcpIpSocketIdx bsd socket id
* @param[in] Abort close type TRUE: close immediately FALSE: close after completing pending tx,rx
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpBsdClose
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketIdx,
    boolean Abort
);
/*!******************************************************************************************************************
* @brief The Api is used idicate that the SoAd has received and processed the message
* @param[in] SocketIdx the SoAd socket id on which the message received
* @param[in] Length the length of the processsed received message
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpBsdTcpReceived(SoAd_SocketIdxType SocketIdx,uint32 Length);
/*!******************************************************************************************************************
* @brief The Api is process the state of bsd TcpIp. This should be called from SoAd mainfuction
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpBsdMainFunctionState(void);
/*!******************************************************************************************************************
* @brief The Api is process the transmission of bsd TcpIp. This should be called from SoAd mainfuction
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpBsdMainFunctionTx(void);
/*!******************************************************************************************************************
* @brief The Api is process the reception of bsd TcpIp. This should be called from SoAd mainfuction
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpBsdMainFunctionRx(void);
#else
#define SoAd_TcpIpBsdInit() 
#define SoAd_TcpIpBsdMainFunctionState() 
#define SoAd_TcpIpBsdMainFunctionTx() 
#define SoAd_TcpIpBsdMainFunctionRx() 
#endif

#endif /* SOAD_TCPIPBSD_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
