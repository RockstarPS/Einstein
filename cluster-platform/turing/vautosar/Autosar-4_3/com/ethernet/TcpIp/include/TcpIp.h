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
*   @file TcpIp.h
*   @ingroup TcpIp
*   @brief This file provides the declaration of the TcpIp API. This header file should be included by other
*   modules that use the TcpIp API.
*   @defgroup TcpIp
*   @brief
********************************************************************************************************************/
#ifndef TCPIP_H
#define TCPIP_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "TcpIp_Cfg.h"
#include "EthSM_Cbk.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the TcpIp SW major version */
#define TCPIP_SW_MAJOR_VERSION                              1u
/*! @brief Defines the TcpIp SW minor version */
#define TCPIP_SW_MINOR_VERSION                              0u
/*! @brief Defines the TcpIp SW patch version */
#define TCPIP_SW_PATCH_VERSION                              0u
/* Autosar Release */
/*! @brief Defines the TcpIp AUTOSAR major version */
#define TCPIP_AR_RELEASE_MAJOR_VERSION                      4u
/*! @brief Defines the TcpIp AUTOSAR minor version */
#define TCPIP_AR_RELEASE_MINOR_VERSION                      3u
/*! @brief Defines the TcpIp AUTOSAR patch version */
#define TCPIP_AR_RELEASE_REVISION_VERSION                   1u
/********************************************************************************************************************
*  MODULE INFORMATION                                                                                               *
********************************************************************************************************************/
/*! @brief Defines the Vendor Id of TcpIp module. */
#define TCPIP_VENDOR_ID                                     0x0033u
/*! @brief Defines the Module Id of TcpIp module.*/
#define TCPIP_MODULE_ID                                     60u
/*! @brief Defines the version Id of TcpIp module.*/
#define TCPIP_INSTANCE_ID                                   0u
/********************************************************************************************************************
*  API Id                                                                                                           *
********************************************************************************************************************/
/*! @brief Defines the service Id for TcpIp_Init function */
#define TCPIP_INIT_API                      0x01u
/*! @brief Defines the service Id for TcpIp_GetVersionInfo function */
#define TCPIP_GETVERSIONINFO_API            0x02u
/*! @brief Defines the service Id for TcpIp_GetSocket function */
#define TCPIP_GETSOCKET_API                 0x03u
/*! @brief Defines the service Id for TcpIp_Close function */
#define TCPIP_CLOSE_API                     0x04u
/*! @brief Defines the service Id for TcpIp_Bind function */
#define TCPIP_BIND_API	                    0x05u
/*! @brief Defines the service Id for TcpIp_TcpConnect function */
#define TCPIP_TCPCONNECT_API                0x06u
/*! @brief Defines the service Id for TcpIp_TcpListen function */
#define TCPIP_TCPLISTEN_API                 0x07u
/*! @brief Defines the service Id for TcpIp_TcpReceived function */
#define TCPIP_TCPRECEIVED_API               0x08u
/*! @brief Defines the service Id for TcpIp_RequestComMode function */
#define TCPIP_REQUESTCOMMODE_API            0x09u
/*! @brief Defines the service Id for TcpIp_RequestIpAddrAssignment function */
#define TCPIP_REQUESTIPADDRASSIGNMENT_API   0x0Au
/*! @brief Defines the service Id for TcpIp_ReleaseIpAddrAssignment function */
#define TCPIP_RELEASEIPADDRASSIGNMENT_API   0x0Bu
/*! @brief Defines the service Id for TcpIp_ResetIpAssignment function */
#define TCPIP_RESETIPASSIGNMENT_API         0x1Bu
/*! @brief Defines the service Id for TcpIp_IcmpTransmit function */
#define TCPIP_ICMPTRANSMIT_API              0x0Cu
/*! @brief Defines the service Id for TcpIp_IcmpV6Transmit function */
#define TCPIP_ICMPV6TRANSMIT_API            0x18u
/*! @brief Defines the service Id for TcpIp_DhcpReadOption function */
#define TCPIP_DHCPREADOPTION_API            0x0Du
/*! @brief Defines the service Id for TcpIp_DhcpV6ReadOption function */
#define TCPIP_DHCPV6READOPTION_API          0x19u
/*! @brief Defines the service Id for TcpIp_DhcpWriteOption function */
#define TCPIP_DHCPWRITEOPTION_API           0x0Eu
/*! @brief Defines the service Id for TcpIp_DhcpV6WriteOption function */
#define TCPIP_DHCPV6WRITEOPTION_API         0x1Au
/*! @brief Defines the service Id for TcpIp_GetIpAddr function  */ 
#define TCPIP_GETIPADDR_API                 0x10u 
/*! @brief Defines the service Id for TcpIp_GetPhysAddr function  */ 
#define TCPIP_GETPHYSADDR_API               0x11u
/*! @brief Defines the service Id for TcpIp_GetRemotePhysAddr function  */
#define TCPIP_GETREMOTEPHYSADDR_API         0x16u
/*! @brief Defines the service Id for TcpIp_GetCtrlIdx function  */
#define TCPIP_GETCTRLIDX_API                0x17u
/*! @brief Defines the service Id for TcpIp_GetArpCacheEntries function  */
#define TCPIP_GETARPCACHEENTRIES_API        0x1Du
/*! @brief Defines the service Id for TcpIp_GetNdpCacheEntries function  */
#define TCPIP_GETNDPCACHEENTRIES_API        0x1Cu
/*! @brief Defines the service Id for TcpIp_GetAndResetMeasurementData function  */
#define TCPIP_GETANDRESETMEASUREMENTDATA_API 0x45u
/*! @brief Defines the service Id for TcpIp_UdpTransmit function  */
#define TCPIP_UDPTRANSMIT_API               0x12u
/*! @brief Defines the service Id for TcpIp_TcpTransmit function  */
#define TCPIP_TCPTRANSMIT_API               0x13u
/*! @brief Defines the service Id for TcpIp_ChangeParameter function  */ 
#define TCPIP_CHANGEPARAMETER_API           0x0Fu 
/*! @brief Defines the service Id for TcpIp_RxIndication function */
#define TCPIP_RXINDICATION_API              0x14u
/*! @brief Defines the service Id for TcpIp_MainFunction function */
#define TCPIP_MAINFUNCTION_API              0x15u
/********************************************************************************************************************
*  DEVELOPMENT ERRORS VALUES                                                                                        *
********************************************************************************************************************/
/*! @brief API service called before initializing the module */
#define TCPIP_E_UNINIT                                  0x01u
/*! @brief API service called with NULL pointer */
#define TCPIP_E_PARAM_POINTER                           0x02u
/*! @brief Invalid argument Development */
#define TCPIP_E_INV_ARG                                 0x03u
/*! @brief No buffer space available Development */
#define TCPIP_E_NOBUFS                                  0x04u
/*! @brief Message too long Development */
#define TCPIP_E_MSGSIZE                                 0x07u
/*! @brief Protocol wrong type for socket Development */
#define TCPIP_E_PROTOTYPE                               0x08u
/*! @brief Address already in use Development */
#define TCPIP_E_ADDRINUSE                               0x09u
/*! @brief Can't assign requested address Development */
#define TCPIP_E_ADDRNOTAVAIL                            0x0Au
/*! @brief Socket is already connected Development */
#define TCPIP_E_ISCONN                                  0x0Bu
/*! @brief Socket is not connected Development */
#define TCPIP_E_NOTCONN                                 0x0Cu
/*! @brief Protocol not available Development */
#define TCPIP_E_NOPROTOOPT                              0x0Du
/*! @brief Address family not supported by protocol family Development */
#define TCPIP_E_AFNOSUPPORT                             0x0Eu
/*! @brief Invalid configuration set selection Development */
#define TCPIP_E_INIT_FAILED                             0x0Fu
/*! @brief Defines No error id  */
#define TCPIP_E_NO_ERROR                                0xFFu
/********************************************************************************************************************
*  RUNTIME ERRORS VALUES                                                                                            *
********************************************************************************************************************/

#define TCPIP_START_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @brief      This service initializes the TCP/IP Stack. TcpIp_Init may not block the start-up process for
*               an indefinite amount of time. Caveats: The call of this service is mandatory before using the TcpIp
*               instance for further processing.
*   @param[in]  ConfigPtr  Pointer to the configuration data of the TcpIp module
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(void, TCPIP_CODE) TcpIp_Init(P2CONST(TcpIp_ConfigType,AUTOMATIC,TCPIP_APPL_CONST) ConfigPtr);
/*!******************************************************************************************************************
*   @brief      Returns the version information.
*   @param[out] versioninfo  Pointer to where to store the version information of this module
*   @ServiceID  0x02
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(void,TCPIP_CODE) TcpIp_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,TCPIP_APPL_DATA) versioninfo);
/*!******************************************************************************************************************
*   @brief      By this API service the TCP/IP stack is requested to close the socket and release all related
*               resources.
*   @param[in]  SocketId  Socket handle identifying the local socket resource
*   @param[in]  Abort  TRUE: connection will immediately be terminated by sending a RST-Segment and releasing
*               all related resources.
*               FALSE: connection will be terminated after performing a regular connection termination handshake
*               and releasing all related resources.
*   @return     E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x04
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different SocketIds. Non reentrant for the same SocketId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_Close(TcpIp_SocketIdType SocketId, boolean Abort);
/*!******************************************************************************************************************
*   @brief      By this API service the TCP/IP stack is requested to bind a UDP or TCP socket to a local resource.
*   @param[in]  SocketId  Socket handle identifying the local socket resource
*   @param[in]  LocalAddrId  IP address identifier representing the local IP address and EthIf controller to bind the
*               socket to.
*               Note: to listen to all EthIf controller, TCPIP_LOCALADDRID_ANY has to be specified as LocalAddrId.
*               Note: to listen on any IP addresss of a EthIf controller, the configuration parameter
*               TcpIpStaticIpAddress referenced by LocalAddrId must be set to "ANY". The remote IP address of an
*               incoming packet has no effect then. In case the socket shall be used as client socket, the IP address
*               and EthIf controller represented by LocalAddrId is used for transmission.
*               Note: for an automatic selection of the Local IP address and EthIf Controller, TCPIP_LOCALADDRID_ANY
*               has to be specified as LocalAddrId.
*   @param[inout]   PortPtr : Pointer to memory where the local port to which the socket shall be bound is specified.
*               In case the parameter is specified as TCPIP_PORT_ANY, the TCP/IP stack shall choose the local port
*               automatically from the range 49152 to 65535 and shall update the parameter to the chosen value.
*   @return     E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x05
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different SocketIds. Non reentrant for the same SocketId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_Bind
(
    TcpIp_SocketIdType SocketId,
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(uint16,AUTOMATIC,TCPIP_APPL_DATA) PortPtr
);
/*!******************************************************************************************************************
*   @brief      By this API service the TCP/IP stack is requested to establish a TCP connection to the configured
*               peer.
*   @param[in]  SocketId  Socket handle identifying the local socket resource
*   @param[in]  RemoteAddrPtr IP address and port of the remote host to connect to.
*   @return     E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x06
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant for different SocketIds. Non reentrant for the same SocketId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_TcpConnect
(
    TcpIp_SocketIdType SocketId,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) RemoteAddrPtr
);
/*!******************************************************************************************************************
*   @brief      By this API service the TCP/IP stack is requested to listen on the TCP socket specified by the
*               socket identifier.
*   @param[in]  SocketId  Socket handle identifying the local socket resource
*   @param[in]  MaxChannels Maximum number of new parallel connections established on this listen connection.
*   @return     E_OK: The request has been accepted
*               E_NOT_OK: The request has not been accepted, the socket is not configured to be a server socket.
*   @ServiceID  0x07
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant for different SocketIds. Non reentrant for the same SocketId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_TcpListen(TcpIp_SocketIdType SocketId,uint16 MaxChannels);
/*!******************************************************************************************************************
*   @brief      By this API service the reception of socket data is confirmed to the TCP/IP stack.
*   @param[in]  SocketId  Socket identifier of the related local socket resource
*   @param[in]  Length Number of bytes finally consumed by the upper layer
*   @return     E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x08
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant for different SocketIds. Non reentrant for the same SocketId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_TcpReceived(TcpIp_SocketIdType SocketId,uint32 Length);
/*!******************************************************************************************************************
*   @brief      By this API service the local IP address assignment for the IP address specified by LocalAddrId
*               shall be initiated.
*   @param[in]  LocalAddrId  IP address index specifying the IP address for which an assignment shall be initiated
*   @param[in]  Type  Type of IP address assignment which shall be initiated
*   @param[in]  LocalIpAddrPtr Pointer to structure containing the IP address which shall be assigned to the EthIf
*               controller indirectly specified via LocalAddrId. Note: This parameter is only used in case the
*               parameter Type is set to TCPIP_IPADDR_ASSIGNMENT_STATIC, can be set to NULL_PTR otherwise.
*   @param[in]  Netmask Network mask of IPv4 address or address prefix of IPv6 address in CIDR Notation.
*               Note: This parameter is only used in case the parameter Type is set to TCPIP_IPADDR_ASSIGNMENT_STATIC.
*   @param[in]  DefaultRouterPtr Pointer to structure containing the IP address of the default router (gateway) which
*               shall be assigned. Note: This parameter is only used in case the parameter Type is set to
*               TCPIP_IPADDR_ASSIGNMENT_STATIC, can be set to NULL_PTR otherwise.
*   @return     E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x0A
*   @Sync/Async Asynchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_RequestIpAddrAssignment
(
    TcpIp_LocalAddrIdType LocalAddrId,
    TcpIp_IpAddrAssignmentType Type,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) LocalIpAddrPtr,
    uint8 Netmask,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) DefaultRouterPtr
);
/*!******************************************************************************************************************
*   @brief      By this API service the local IP address assignment for the IP address specified by LocalAddrId
*               shall be released.
*   @param[in]  LocalAddrId  IP address index specifying the IP address for which an assignment shall be released.
*   @return     E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x0B
*   @Sync/Async Asynchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_ReleaseIpAddrAssignment(TcpIp_LocalAddrIdType LocalAddrId);
/*!******************************************************************************************************************
*   @brief      Resets all learned IP-addresses to invalid values.
*   @return     E_OK: success E_NOT_OK: switch port could not be initialized
*   @ServiceID  0x1B
*   @Sync/Async Synchronous /Asynchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_ResetIpAssignment(void);
/*!******************************************************************************************************************
*   @brief      By this API service the TCP/IP stack sends an ICMP message according to the specified parameters.
*   @param[in]  LocalIpAddrId IP address identifier representing the local IP address and EthIf controller which
*               shall be used for transmission of the ICMP message.
*   @param[in]  RemoteAddrPtr pointer to struct representing the remote address
*   @param[in]  Ttl Time to live value to be used for the ICMP message. If 0 is specified the default value
*               shall be used.
*   @param[in]  Type type field value to be used in the ICMP message (Note: the value of the type field determines
*               the format of the remaining ICMP message data)
*   @param[in]  Code code field value to be used in the ICMP message
*   @param[in]  DataLength length of ICMP message
*   @param[in]  DataPtr Pointer to data which shall be sent as ICMP message data
*   @return     Result of operation E_OK The ICMP message has been sent successfully
*               E_NOT_OK The ICMP message was not sent.
*   @ServiceID  0x0C
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_IcmpTransmit
(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) RemoteAddrPtr,
    uint8 Ttl,
    uint8 Type,
    uint8 Code,
    uint16 DataLength,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) DataPtr
);
/*!******************************************************************************************************************
*   @brief      By this API service the TCP/IP stack sends an ICMPv6 message according to the specified parameters.
*   @param[in]  LocalIpAddrId IP address identifier representing the local IP address and EthIf controller which
*               shall be used for transmission of the ICMPv6 message.
*   @param[in]  RemoteAddrPtr pointer to struct representing the remote address
*   @param[in]  HopLimit Hop Limit value to be used for the ICMPv6 message. If 0 is specified the default value
*               shall be used.
*   @param[in]  Type type field value to be used in the ICMPv6 message.
*               (Note: the value of the type field determines the format of the remaining ICMPv6 message data)
*   @param[in]  Code code field value to be used in the ICMPv6 message
*   @param[in]  DataLength length of ICMPv6 message
*   @param[in]  DataPtr Pointer to data which shall be sent as ICMPv6 message data
*   @return     Result of operation E_OK: The ICMPv6 message has been sent successfully
*               E_NOT_OK: The ICMPv6 message was not sent.
*   @ServiceID  0x18
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_IcmpV6Transmit
(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) RemoteAddrPtr,
    uint8 HopLimit,
    uint8 Type,
    uint8 Code,
    uint16 DataLength,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) DataPtr
);
/*!******************************************************************************************************************
*   @brief      By this API service the TCP/IP stack retrieves DHCP option data identified by parameter option for
*               already received DHCP options.
*   @param[in]  LocalIpAddrId IP address identifier representing the local IP address and EthIf controller for which
*               the DHCP option shall be read.
*   @param[in]  Option DHCP option according to IEFT RfC 2132, e.g. hostname
*   @param[inout]  DataLength As input parameter, contains the length of the provided data buffer. Will be overwritten
*                  with the length of the actual data.
*   @param[out]  DataPtr Pointer to memory containing DHCP option data
*   @return     Result of operation E_OK requested data retrieved successfully.
*               E_NOT_OK requested data could not be retrieved.
*   @ServiceID  0x0D
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_DhcpReadOption
(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    uint8 Option,
    P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) DataLength,
    P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) DataPtr
);
/*!******************************************************************************************************************
*   @brief      By this API service the TCP/IP stack retrieves DHCPv6 option data identified by parameter option for
*               already received DHCPv6 options.
*   @param[in]  LocalIpAddrId IP address identifier representing the local IP address and EthIf controller for which
*               the DHCPv6 option shall be read.
*   @param[in]  Option DHCP option according to IEFT RfC 3315, e.g. hostname
*   @param[inout]  DataLength As input parameter, contains the length of the provided data buffer. Will be overwritten
*               with the length of the actual data.
*   @param[out]  DataPtr Pointer to memory containing DHCPv6 option data
*   @return     Result of operation E_OK: requested data retrieved successfully.
*               E_NOT_OK: requested data could not be retrieved.
*   @ServiceID  0x19
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_DhcpV6ReadOption
(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    uint16 Option,
    P2VAR(uint16,AUTOMATIC,TCPIP_APPL_DATA) DataLength,
    P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) DataPtr
);
/*!******************************************************************************************************************
*   @brief      By this API service the TCP/IP stack writes the DHCP option data identified by parameter option.
*   @param[in]  LocalIpAddrId IP address identifier representing the local IP address and EthIf controller for
*               which the DHCP option shall be written.
*   @param[in]  Option DHCP option according to IEFT RfC 2132, e.g. hostname
*   @param[in]  length length of DHCP option data
*   @param[in]  DataPtr Pointer to memory containing DHCP option data
*   @return     Result of operation E_OK no error occured. E_NOT_OK DHCP option data could not be written.
*   @ServiceID  0x0E
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_DhcpWriteOption
(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    uint8 Option,
    uint8 DataLength,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) DataPtr
);
/*!******************************************************************************************************************
*   @brief      By this API service the TCP/IP stack writes the DHCPv6 option data identified by parameter option.
*   @param[in]  LocalIpAddrId IP address identifier representing the local IP address and EthIf controller for which
*               the DHCPv6 option shall be written
*   @param[in]  Option DHCP option according to IEFT RfC 3315, e.g. hostname
*   @param[in]  length length of DHCPv6 option data
*   @param[in]  DataPtr Pointer to memory containing DHCPv6 option data
*   @return     Result of operation E_OK: no error occured. E_NOT_OK: DHCPv6 option data could not be written.
*   @ServiceID  0x1A
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_DhcpV6WriteOption
(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    uint16 Option,
    uint16 DataLength,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) DataPtr
);
/*!******************************************************************************************************************
*   @brief      By this API service the TCP/IP stack is requested to change a parameter of a socket.
*               E.g. the Nagle algorithm may be controlled by this API.
*   @param[in]  SocketId Socket identifier of the related local socket resource
*   @param[in]  Option Identifier of the parameter to be changed
*   @param[in]  ParameterId length of DHCPv6 option data
*   @param[in]  ParameterValue Pointer to memory containing the new parameter value
*   @return     E_OK: The parameter has been changed successfully. E_NOT_OK: The parameter could not be changed.
*   @ServiceID  0x0F
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different SocketIds. Non reentrant for the same SocketId.
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_ChangeParameter
(
    TcpIp_SocketIdType SocketId,
    TcpIp_ParamIdType ParameterId,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) ParameterValue
);
/*!******************************************************************************************************************
*   @brief      Obtains the local IP address actually used by LocalAddrId, the netmask and default router
*   @param[in]  LocalAddrId Local address identifier referring to the local IP address which shall be obtained.
*   @param[inout]   IpAddrPtr Pointer to a struct where the IP address shall be stored. The struct member domain shall
*               be set to the desired TcpIp_DomainType and it shall be ensured that the struct is large enough to
*               store an address of the selected type (INET or INET6). Struct members not related to the IP address
*               are of arbitrary value and shall not be used.
*   @param[out] NetmaskPtr Pointer to memory where Network mask of IPv4 address or address prefix of IPv6 address in
*               CIDR Notation is stored
*   @param[inout]   DefaultRouterPtr Pointer to struct where the IP address of the default router (gateway) is stored
*               (struct member "port" is not used and of arbitrary value). The struct must be of the same type and
*               size as IpAddrPtr.
*   @return     Result of operation E_OK: The request was successful E_NOT_OK: The request was not successful,
*               e.g. domain in IpAddrPtr and the local domain type do not match
*   @ServiceID  0x10
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_GetIpAddr
(
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_DATA) IpAddrPtr,
    P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) NetmaskPtr,
    P2VAR(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_DATA) DefaultRouterPtr
);
/*!******************************************************************************************************************
*   @brief      Obtains the physical source address used by the EthIf controller implicitly specified via
*               LocalAddrId.
*   @param[in]  LocalAddrId Local address identifier implicitely specifing the EthIf controller for which the
*               physical address shall be obtained.
*   @param[out] PhysAddrPtr Pointer to the memory where the physical source address (MAC address) in network byte
*               order is stored
*   @return     Result of operation E_OK The request was successful E_NOT_OK The request was not successful,
*               e.g. no unique Ctrl specified via IpAddrId.
*   @ServiceID  0x11
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_GetPhysAddr
(
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) PhysAddrPtr
);
/*!******************************************************************************************************************
*   @brief      TcpIp_GetRemotePhysAddr queries the IP/physical address translation table specified by CtrlIdx and
*               returns the physical address related to the IP address specified by IpAddrPtr. In case no physical
*               address can be retrieved and parameter initRes is TRUE, address resolution for the specified IP
*               address is initiated on the local network.
*   @param[in]  CtrlIdx EthIf controller index to identify the related ARP/NDP table.
*   @param[in]  IpAddrPtr specifies the IP address for which the physical address shall be retrieved
*   @param[out] PhysAddrPtr Pointer to the memory where the physical address (MAC address) related to the specified IP
*               address is stored in network byte order.
*   @param[in]  initRes specifies if the address resolution shall be initiated (TRUE) or not (FALSE) in case the
*               physical address related to the specified IP address is currently unknown.
*   @return     TCPIP_E_OK: specified IP address resolved, physical address provided via PhysAddrPtr
*               TCPIP_E_PHYS_ADDR_MISS: physical address currently unknown (address resolution initiated if
*               initRes set to TRUE)
*   @ServiceID  0x16
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(TcpIp_ReturnType,TCPIP_CODE) TcpIp_GetRemotePhysAddr
(
    uint8 CtrlIdx,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) IpAddrPtr,
    P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) PhysAddrPtr,
    boolean initRes
);
/*!******************************************************************************************************************
*   @brief      TcpIp_GetCtrlIdx returns the index of the controller related to LocalAddrId.
*   @param[in]  LocalAddrId Local address identifier implicitely specifing the EthIf controller that shall be returned.
*   @param[out] CtrlIdxPtr Pointer to the memory where the index of the controller related to LocalAddrId is stored
*   @return     Result of operation E_OK the request was successful E_NOT_OK the request was not successful
*   @ServiceID  0x17
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_GetCtrlIdx
(
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) CtrlIdxPtr
);
/*!******************************************************************************************************************
*   @brief      Copies entries from the physical address cache of the IPv4 instance that is active on the EthIf
*               controller specified by ctrlIdx into a user provided buffer. The function will copy all or
*               numberOfElements into the output list. If input value of numberOfElements is 0 the function will
*               not copy any data but only return the number of valid entries in the cache. EntryListPtr may be
*               NULL_PTR in this case
*   @param[in]  ctrlIdx EthIf controller index to identify the related ARP table.
*   @param[inout] numberOfElements In: Maximum number of entries that can be stored in output entryListPtr.
*               Out: Number of entries written to output entryListPtr (Number of all entries in the cache if
*               input value is 0).
*   @param[out] entryListPtr Pointer to memory where the list of cache entries shall be stored
*   @return     E_OK: physical address cache could be read. E_NOT_OK: physical address cache could not be read
*               (i.e. no IPv4 instance active on this controller)
*   @ServiceID  0x1D
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_GetArpCacheEntries
(
    uint8 ctrlIdx,
    P2VAR(uint32,AUTOMATIC,TCPIP_APPL_DATA) numberOfElements,
    P2VAR(TcpIp_ArpCacheEntryType,AUTOMATIC,TCPIP_APPL_DATA) entryListPtr
);
/*!******************************************************************************************************************
*   @brief      Copies entries from the physical address cache of the IPv6 instance that is active on the EthIf
*               controller specified by ctrlIdx into a user provided buffer. The function will copy all or
*               numberOfElements into the output list. If input value of numberOfElements is 0 the function will not
*               copy any data but only return the number of valid entries in the cache. EntryListPtr may be NULL_PTR
*               in this case.
*   @param[in]  ctrlIdx EthIf controller index to identify the related NDP table.
*   @param[inout] numberOfElements In: Maximum number of entries that can be stored in output entryListPtr.
*               Out: Number of entries written to output entryListPtr (Number of all entries in the cache if input
*               value is 0).
*   @param[out] entryListPtr Pointer to memory where the list of cache entries shall be stored.
*   @return     E_OK: physical address cache could be read. E_NOT_OK: physical address cache could not be read
*               (i.e. no IPv6 instance active on this controller)
*   @ServiceID  0x1C
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_GetNdpCacheEntries
(
    uint8 ctrlIdx,
    P2VAR(uint32,AUTOMATIC,TCPIP_APPL_DATA) numberOfElements,
    P2VAR(TcpIp_NdpCacheEntryType,AUTOMATIC,TCPIP_APPL_DATA) entryListPtr
);
/*!******************************************************************************************************************
*   @brief      Copies entries from the physical address cache of the IPv6 instance that is active on the EthIf
*               controller specified by ctrlIdx into a user provided buffer. The function will copy all or
*               numberOfElements into the output list. If input value of numberOfElements is 0 the function will not
*               copy any data but only return the number of valid entries in the cache. EntryListPtr may be NULL_PTR
*               in this case.
*   @param[in]  MeasurementIdx Data index of measurement data
*   @param[in]  MeasurementResetNeeded Flag to trigger a reset of the measurement data
*   @param[out] MeasurementDataPtr Reference to data buffer, where to copy measurement data
*   @return     E_OK: successful E_NOT_OK: failed
*   @ServiceID  0x45
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_GetAndResetMeasurementData
(
    TcpIp_MeasurementIdxType MeasurementIdx,
    boolean MeasurementResetNeeded,
    P2VAR(uint32,AUTOMATIC,TCPIP_APPL_DATA) MeasurementDataPtr
);
/*!******************************************************************************************************************
*   @brief      This service transmits data via UDP to a remote node. The transmission of the data is immediately
*               performed with this function call by forwarding it to EthIf.
*   @param[in]  SocketId Socket identifier of the related local socket resource
*   @param[in]  DataPtr Pointer to a linear buffer of TotalLength bytes containing the data to be transmitted. In
*               case DataPtr is a NULL_PTR, TcpIp shall retrieve data from upper layer via callback <Up>_CopyTxData().
*   @param[in]  RemoteAddrPtr IP address and port of the remote host to transmit to.
*   @param[in]  TotalLength indicates the payload size of the UDP datagram.
*   @return     E_OK: UDP message has been forwarded to EthIf for transmission.
*               E_NOT_OK: UDP message could not be sent because of a permanent error, e.g. message is too long.
*   @ServiceID  0x12
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different SocketIds. Non reentrant for the same SocketId
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_UdpTransmit
(
    TcpIp_SocketIdType SocketId,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) DataPtr,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) RemoteAddrPtr,
    uint16 TotalLength
);
/*!******************************************************************************************************************
*   @brief      This service requests transmission of data via TCP to a remote node. The transmission of the data is
*               decoupled. Note: The TCP segment(s) are sent dependent on runtime factors (e.g. receive window) and
*               configuration parameter (e.g. Nagle algorithm) .
*   @param[in]  SocketId Socket identifier of the related local socket resource
*   @param[in]  DataPtr Pointer to a linear buffer of AvailableLength bytes containing the data to be transmitted.
*               In case DataPtr is a NULL_PTR, TcpIp shall retrieve data from upper layer via callback
*               <Up>_CopyTxData().
*   @param[in]  AvailableLength Available data for transmission in bytes.
*   @param[in]  ForceRetrieve This parameter is only valid if DataPtr is a NULL_PTR. Indicates how the TCP/IP stack
*               retrieves data from upper layer if DataPtr is a NULL_PTR. TRUE: the whole data indicated by
*               availableLength shall be retrieved from the upper layer via one or multiple <Up>_CopyTxData()
*               calls within the context of this transmit function. FALSE: The TCP/IP stack may retrieve up to
*               availableLength data from the upper layer. It is allowed to retrieve less than availableLength
*               bytes. Note: Not retrieved data will be provided by upper layer with the next call to TcpIp_TcpTransmit
*               (along with new data if available).
*   @return     E_OK: The request has been accepted
*               E_NOT_OK: The request has not been accepted, e.g. due to a lack of buffer space or the socket is
*               not connected.
*   @ServiceID  0x13
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant for different SocketIds. Non reentrant for the same SocketId
********************************************************************************************************************/
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_TcpTransmit
(
    TcpIp_SocketIdType SocketId,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) DataPtr,
    uint32 AvailableLength,
    boolean ForceRetrieve
);
/*!******************************************************************************************************************
*   @brief      By this API service the TCP/IP stack gets an indication and the data of a received frame.
*   @param[in]  CtrlIdx Index of the EthIf controller.
*   @param[in]  FrameType frame type of received Ethernet frame
*   @param[in]  IsBroadcast parameter to indicate a broadcast frame
*   @param[in]  PhysAddrPtr pointer to Physical source address (MAC address in network byte order) of
*               received Ethernet frame
*   @param[in]  DataPtr Pointer to payload of the received Ethernet frame (i.e. Ethernet header is not provided).
*   @param[in]  LenByte Length of received data.
*   @ServiceID  0x14
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(void,TCPIP_CODE) TcpIp_RxIndication
(
    uint8 CtrlIdx,
    Eth_FrameType FrameType,
    boolean IsBroadcast,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) PhysAddrPtr,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) DataPtr,
    uint16 LenByte
);
/*!******************************************************************************************************************
*   @brief      Schedules the TCP/IP stack. (Entry point for scheduling)
*   @ServiceID  0x15
********************************************************************************************************************/
extern FUNC(void,TCPIP_CODE) TcpIp_MainFunction(void);
extern FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_GetSocket
(
    uint8 SocketOwnerId,
    TcpIp_DomainType Domain, 
    TcpIp_ProtocolType Protocol, 
    P2VAR(TcpIp_SocketIdType,AUTOMATIC,TCPIP_APPL_DATA) SocketIdPtr
);
#define TCPIP_STOP_SEC_CODE
#include "MemMap.h"

#endif /* TCPIP_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
