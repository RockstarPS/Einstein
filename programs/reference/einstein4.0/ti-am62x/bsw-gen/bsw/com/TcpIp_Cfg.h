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
*    @file TcpIp_Cfg.h
*    @ingroup TcpIpConfiguration
*    @brief This is TcpIp Pre-compile time configuration header file. It contains definitions of pre-compile time 
*    configuration parameters for the TcpIp module.
*    @defgroup TcpIpConfiguration
*    @brief This contains the configuration files for the TcpIp module.
********************************************************************************************************************/
#ifndef TCPIP_CFG_H
#define TCPIP_CFG_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComStack_Types.h"
#include "TcpIp_Types.h" 
/********************************************************************************************************************
*  #! Precompile Configuration                                                                                      *
********************************************************************************************************************/
/*! @brief  Memory size in bytes reserved for TCP/IP buffers. Range 0 .. 4294967295 */
#define TCPIP_BUFFER_MEMORY                             5000U
/*! @brief  Switches the development error detection and notification on or off.
    true: detection and notification is enabled.
    false: detection and notification is disabled. */
#define TCPIP_DEV_ERROR_DETECT                          STD_ON
/*! @brief Enables (TRUE) or disables (FALSE) the DHCP (Dynamic Host Configuration Protocol) Server. */
#define TCPIP_DHCP_SERVER_ENABLED                       STD_OFF
/*! @brief Enables / Disables the Get and Reset Measurement Data API */
#define TCPIP_GET_AND_RESET_MEASUREMENT_DATA_API        STD_OFF
/*! @brief Period of TcpIp_MainFunction in [s]. */
#define TCPIP_MAINFUNCTIONPERIOD                        10U
/*! @brief Enables/disables the API TcpIp_ResetIpAssignment of a DHCP-client. */
#define TCPIP_RESET_IP_ASSIGNMENT_API                   STD_OFF
/*! @brief Defines the scalability class 1 ,IPv4 - In-Vehicle and Diagnostic Communication */
#define TCPIP_SCALABILITY_CLASS_SC1                     0U
/*! @brief Defines the scalability class 2 ,IPv6 - In-Vehicle and Diagnostic Communication */
#define TCPIP_SCALABILITY_CLASS_SC2                     1U
/*! @brief Defines the scalability class 3 ,IPv4 and IPv6 (Dual Stack) - In-Vehicle and Diagnostic Communication */
#define TCPIP_SCALABILITY_CLASS_SC3                     2U
/*! @brief In order to customize the TcpIp Stack to the specific needs of the user it can be scaled according 
    to the scalability classes. */
#define TCPIP_SCALABILITY_CLASS                         TCPIP_SCALABILITY_CLASS_SC1
/*! @brief Enables (TRUE) or disabled (FALSE) support of TCP (Transmission Control Protocol). */
#define TCPIP_TCP_ENABLED                               STD_OFF
/*! @brief Maximum number of TCP sockets */
#define TCPIP_TCP_SOCKET_MAX                            1U
/*! @brief Enables (TRUE) or disabled (FALSE) support of UDP (User Datagram Protocol) */
#define TCPIP_UDP_ENABLED                               STD_OFF
/*! @brief Maximum number of UDP sockets. */
#define TCPIP_UDP_SOCKET_MAX                            1U
/*! @brief If true the TcpIp_GetVersionInfo API is available. */
#define TCPIP_VERSION_INFO_API                          STD_OFF
/*! @brief Enables (TRUE) or disables (FALSE) support of ARP (Address Resolution Protocol). */
#define TCPIP_ARP_ENABLED                               STD_OFF
/*! @brief Enables (TRUE) or disables (FALSE) the Auto-IP (automatic private IP addressing) sub-module. */
#define TCPIP_AUTO_IP_ENABLED                           STD_OFF
/*! @brief Enables (TRUE) or disables (FALSE) the DHCP (Dynamic Host Configuration Protocol) Client. */
#define TCPIP_DHCP_CLIENT_ENABLED                       STD_OFF
/*! @brief Enables (TRUE) or disabled (FALSE) support of ICMP (Internet Control Message Protocol). */
#define TCPIP_ICMP_ENABLED                              STD_OFF
/*! @brief Enables (TRUE) or disables (FALSE) support of IPv4 (Internet Protocol version 4). */
#define TCPIP_IPV4_ENABLED                              STD_OFF
/*! @brief Maximum number of LocalAddr table entries for IPv4. */
#define TCPIP_LOCAL_ADDR_IPV4_ENTRIES_MAX               1U
/*! @brief Enables (TRUE) or disables (FALSE) the discovery of the maximum transmission unit on a path according 
    to IETF RfC 1191. */
#define TCPIP_PATH_MTU_DISCOVERY_ENABLED                STD_OFF
/*! @brief Enables (TRUE) or disables (FALSE) the DHCPv6 (Dynamic Host Configuration Protocol for IPv6) Client. */
#define TCPIP_DHCPV6_CLIENT_ENABLED                     STD_OFF
/*! @brief Enables (TRUE) or disables (FALSE) support of IPv6 (Internet Protocol version 6). */
#define TCPIP_IPV6_ENABLED                              STD_OFF
/*! @brief Enables (TRUE) or disables (FALSE) Path MTU Discovery support for IPv6 according to IETF RFC 1981. */
#define TCPIP_IPV6_PATH_MTU_DISCOVERY_ENABLED           STD_OFF
/*! @brief Maximum number of LocalAddr table entries for IPv6. */ 
#define TCPIP_LOCAL_ADDR_IPV6_ENTRIES_MAX               1U
/*! @brief Enables (TRUE) or disables (FALSE) support of Address Resoultion and Neighbor Unreachability 
Detetion via NDP. */
#define TCPIP_NDP_AR_UNRECHABILITY_DETECTION_ENABLED    STD_OFF
/*! @brief Enables (TRUE) or disables (FALSE) support of Prefix and Router Discovery via NDP. */
#define TCPIP_NDP_PREFIX_AND_ROUTER_DISCOVERY_ENABLED   STD_OFF

/********************************************************************************************************************
*  #! TcpIp Internal feature support                                                                                *
********************************************************************************************************************/
/*! @brief Defines the dummy macro */
#ifndef TCPIP_DUMMY_STATEMENT
#define TCPIP_DUMMY_STATEMENT(v)
#endif
/********************************************************************************************************************
*  #! SW and AUTOSAR Version Macros                                                                                 *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the TcpIp configuration software Major version */
#define TCPIP_CFG_SW_MAJOR_VERSION                      1u
/*! @brief Defines the TcpIp configuration software Minor version */
#define TCPIP_CFG_SW_MINOR_VERSION                      0u
/*! @brief Defines the TcpIp configuration software Patch version */
#define TCPIP_CFG_SW_PATCH_VERSION                      0u
/* Autosar Release */
/*! @brief Defines the AUTOSAR Release Major version supported by ComM configuration  */
#define TCPIP_CFG_AR_RELEASE_MAJOR_VERSION              4u
/*! @brief Defines the AUTOSAR Release Minor version supported by ComM configuration  */
#define TCPIP_CFG_AR_RELEASE_MINOR_VERSION              3u
/*! @brief Defines the AUTOSAR Release patch version supported by ComM configuration  */
#define TCPIP_CFG_AR_RELEASE_REVISION_VERSION           1u
/*******************************************************************************************************************
*  #! TcpIp module configuration                                                                                   *
*******************************************************************************************************************/
#define TCPIP_NUM_OF_CONTROLLERS    1U
#define TCPIP_ADDR_ID_CFG1          0u
#define TCPIP_NUM_OF_SOCKETS        9u
#define TCPIP_NUM_OF_LOCALADDR      1u
#define TCPIP_RX_BUFFER_SIZE        3000u
#define ETH_MAC_ADDR { 0x1C, 0xBA, 0x8C, 0x94, 0x52, 0x0B }
#define LWIP_TCPIP_INIT_DONE_CALLBACK 0
#define LWIP_NO_SYS 0
#define TCPIP_SOCKET_OWNER_ID_SOAD 0u
/********************************************************************************************************************
* #! TcpIp types                                                                                                    *
* #! macro , typedef declaration                                                                                    *
********************************************************************************************************************/
/*! @brief Defines the wildcard for Ipv4 address */
#define TCPIP_IPADDR_ANY                            0x00u
/*! @brief Defines the wildcard for port */
#define TCPIP_PORT_ANY                              0x00u
/*! @brief Defines the TcpIp address families. Use IPv4 */
#define TCPIP_AF_INET                               0x02U
/*! @brief Defines the TcpIp address families. Use IPv6 */
#define TCPIP_AF_INET6                              0x1CU
/*! @brief Specifies the maximum TCP receive window for the socket. [uint16] */
#define TCPIP_PARAMID_TCP_RXWND_MAX                 0x00U
/*! @brief priority for outgoing frames on the socket. [uint8] */
#define TCPIP_PARAMID_FRAMEPRIO                     0x01U
/*! @brief Specifies if the Nagle Algorithm according to IETF RFC 896 is enabled or not. [boolean] */
#define TCPIP_PARAMID_TCP_NAGLE                     0x02U
/*! @brief Specifies if TCP Keep Alive Probes are sent on the socket connection. [boolean] */
#define TCPIP_PARAMID_TCP_KEEPALIVE                 0x03U
/*! @brief Specifies the time to live value for outgoing frames on the socket. For IPv6 this parameter 
    specifies the value of the HopLimit field used in the IPv6 header. [uint8] */
#define TCPIP_PARAMID_TTL                           0x04U
/*! @brief Specifies the time in [s] between the last data packet sent (simple ACKs are not considered data) and 
    the first keepalive probe. [uint32] */
#define TCPIP_PARAMID_TCP_KEEPALIVE_TIME            0x05U
/*! @brief Specifies the maximum number of times that a keepalive probe is retransmitted. [uint16] */
#define TCPIP_PARAMID_TCP_KEEPALIVE_PROBES_MAX      0x06U
/*! @brief Specifies the interval in [s] between subsequent keepalive probes. [uint32] */
#define TCPIP_PARAMID_TCP_KEEPALIVE_INTERVAL        0x07U
/*! @brief Specifies which TCP option filter shall be applied on the related socket. [uint8] */
#define TCPIP_PARAMID_TCP_OPTIONFILTER              0x08U
/*! @brief Specifies if the Path MTU Discovery shall be performed on the related socket. [boolean] */
#define TCPIP_PARAMID_PATHMTU_ENABLE                0x09U
/*! @brief The 20-bit Flow Label according to IETF RFC 6437. [uint32] */
#define TCPIP_PARAMID_FLOWLABEL                     0x0AU
/*! @brief The 6-bit Differentiated Service Code Point according to IETF RFC 2474. [uint8] */
#define TCPIP_PARAMID_DSCP                          0x0BU
/*! @brief 0x0c Specifies if UDP checksum handling shall be enabled (TRUE) or skipped (FALSE) on the 
    related socket. [boolean] */
#define TCPIP_PARAMID_UDP_CHECKSUM                  0x0CU
/*! @brief Start of vendor specific range of parameter IDs. [vendor specific] */
#define TCPIP_PARAMID_VENDOR_SPECIFIC               0x80U
/*! @brief Measurement index of dropped PDUs caused by invalid destination TCP-Port */
#define TCPIP_MEAS_DROP_TCP                         0x01U
/*! @brief Measurement index of dropped PDUs caused by invalid destination UDP-Port */
#define TCPIP_MEAS_DROP_UDP                         0x02U
/*! @brief Measurement index of dropped datagrams caused by invalid IPv4 address */
#define TCPIP_MEAS_DROP_IPV4                        0x03U
/*! @brief Measurement index of dropped datagrams caused by invalid IPv6 address */
#define TCPIP_MEAS_DROP_IPV6                        0x04U
/*! @brief represents all measurement indexes */
#define TCPIP_MEAS_ALL                              0xFFU

/*! @brief Defines the TcpIp address families.*/
typedef uint16 TcpIp_DomainType;
/*! @brief Protocol type used by a socket. */
typedef enum
{
    TCPIP_IPPROTO_TCP = 0x06U,  /*! @brief Use TCP */
    TCPIP_IPPROTO_UDP = 0x11U   /*! @brief Use UDP */
}TcpIp_ProtocolType;

/*! @brief This structure defines an IPv4 address type which can be derived from the generic address structure 
*   via cast.*/
typedef struct
{
  TcpIp_DomainType   Domain; /* This is the code for the address format of this address */
  uint16             Port; /* port number */
  uint32             Addr[1]; /* IPv4 address in network byte order */
} TcpIp_SockAddrInetType;
/*! @brief This structure defines a IPv6 address type which can be derived from the generic address structure via 
    cast.*/
typedef struct
{
  TcpIp_DomainType   Domain;    /* This is the code for the address format of this address */
  uint16             Port;      /* port number */
  uint32             Addr[4];   /* IPv6 address in network byte order */
} TcpIp_SockAddrInet6Type;

/*! @brief Generic structure used by APIs to specify an IP address. (A specific address type can be derived from this 
*   structure via a cast to the specific struct type.)*/
typedef union 
{
    /*! @brief This is the code for the address format of this address */
    TcpIp_DomainType Domain;
    TcpIp_SockAddrInetType SockAddrInetType;
    TcpIp_SockAddrInet6Type SockAddrInet6Type;
}TcpIp_SockAddrType;

/*! @brief Address identification type for unique identification of a local IP address and EthIf
     Controller configured in the TcpIp module. */
typedef uint8 TcpIp_LocalAddrIdType;
/*! @brief socket identifier type for unique identification of a TcpIp stack socket. TCPIP_SOCKETID_INVALID shall 
    specify an invalid socket handle , uint8, uint16 */
typedef uint8 TcpIp_SocketIdType;
/*!@ brief Defines the Specifies the TcpIp state for a specific EthIf controller. */
typedef enum
{
    /*! @brief TCP/IP stack state for a specific EthIf controller is ONLINE, i.e. communication via at least one IP
    address is possible.*/
    TCPIP_STATE_ONLINE   = 0U, 
    /*! @brief TCP/IP stack state for a specific EthIf controller is ONHOLD, i.e. no communication is currently 
    possible (e.g. link down).*/
    TCPIP_STATE_ONHOLD   = 1U,
    /*! @brief TCP/IP stack state for a specific EthIf controller is OFFLINE, i.e. no communication is possible. */
    TCPIP_STATE_OFFLINE  = 2U,
    /*! @brief TCP/IP stack state for a specific EthIf controller is STARTUP, i.e. IP address assignment in progress 
    or ready for manual start, communication is currently not possible*/
    TCPIP_STATE_STARTUP  = 3U,
    /*! @brief TCP/IP stack state for a specific EthIf controller is SHUTDOWN, i.e. release of resources using the 
        EthIf controller, release of IP address assignment.*/
    TCPIP_STATE_SHUTDOWN = 4U
}TcpIp_StateType;
/*!@brief Specifies the state of local IP address assignment */
typedef enum 
{
    /*! @brief local IP address is assigned */
    TCPIP_IPADDR_STATE_ASSIGNED=0U, 
    /*! @brief local IP address is assigned, but cannot be used as the network is not active */
    TCPIP_IPADDR_STATE_ONHOLD = 1U, 
    /*! @brief local IP address is unassigned */
    TCPIP_IPADDR_STATE_UNASSIGNED=2U
}TcpIp_IpAddrStateType;
/*! @brief Events reported by TcpIp. */
typedef enum
{
    /*! @brief TCP connection was reset, TCP socket and all related resources have been released. */
    TCPIP_TCP_RESET=0U,
    /*! @brief TCP connection was closed successfully, TCP socket and all related resources have been released. */
    TCPIP_TCP_CLOSED=1U,
    /*! @brief A FIN signal was received on the TCP connection, TCP socket is still valid. */
    TCPIP_TCP_FIN_RECEIVED=2U,
    /*! @brief UDP socket and all related resources have been released. */
    TCPIP_UDP_CLOSED=3U
}TcpIp_EventType;
/*! @brief Specification of IPv4/IPv6 address assignment policy. */
typedef enum
{
    /*! @brief Static configured IPv4/IPv6 address. */
    TCPIP_IPADDR_ASSIGNMENT_STATIC=0U,
    /*! @brief Linklocal IPv4/IPv6 address assignment using DoIP parameters. */
    TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP =1U,
    /*! @brief Dynamic configured IPv4/IPv6 address by DHCP. */
    TCPIP_IPADDR_ASSIGNMENT_DHCP=2U,
    /*! @brief Linklocal IPv4/IPv6 address assignment. */
    TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL=3U,
    /*! @brief Dynamic configured IPv4/IPv6 address by Router Advertisement.*/
    TCPIP_IPADDR_ASSIGNMENT_IPV6_ROUTER=4U,
    /*! @brief All configured TcpIp-AssignmentMethods with TcpIpAssignmentTrigger set to TCPIP_MANUAL */
    TCPIP_IPADDR_ASSIGNMENT_ALL=5U
}TcpIp_IpAddrAssignmentType;
/*! @brief TcpIp specific return type. */
typedef enum
{
    TCPIP_E_OK=0U, /*! @brief operation completed successfully.*/
    TCPIP_E_NOT_OK=1U, /*! @brief operation failed.*/
    TCPIP_E_PHYS_ADDR_MISS=2U /*! @brief operation failed because of an ARP/NDP cache miss. */
}TcpIp_ReturnType;
/*! @brief Type for the specification of all supported Parameter IDs and their data types. */
typedef uint8 TcpIp_ParamIdType;
/*! @brief IP address wildcard. Range : TCPIP_IPADDR_ANY , defines the value used as wildcard */
typedef uint32 TcpIpIpAddrWildcardType;
/*! @brief IP6 address wildcard. Range : TCPIP_IPADDR_ANY , defines the value used as wildcard for all IP6
address parts */
typedef uint32 TcpIpIp6AddrWildcardType;
/*! @brief Port wildcard. TCPIP_PORT_ANY , defines the value used as wildcard */
typedef uint16 TcpIpPortWildcardType;
/*! @brief LocalAddrId wildcard. TCPIP_LOCALADDRID_ANY , defines the value used as wildcard */
typedef TcpIp_LocalAddrIdType TcpIpLocalAddrIdWildcardType;
/*! @brief TcpIp_ArpCacheEntries elements type */
typedef struct
{
    /*! @brief  IPv4 address in network byte order */
    uint32   InetAddr[1];   
    /*! @brief  physical address in network byte order */
    uint8    PhysAddr[6];
    /*! @brief  state of the address entry (TCPIP_ARP_ENTRY_STATIC, TCPIP_ARP_ENTRY_VALID, TCPIP_ARP_ENTRY_STALE) */
    uint8    State;         
} TcpIp_ArpCacheEntryType;
/*! @brief TcpIp_NdpCacheEntries elements type */
typedef struct 
{
    /*! @brief IPv6 address in network byte order */
    uint32  Inet6Addr[4];
    /*! @brief physical address in network byte order */
    uint8   PhysAddr[6];
    /*! @brief state of the address entry (TCPIP_NDP_ENTRY_STATIC, TCPIP_NDP_ENTRY_VALID, TCPIP_NDP_ENTRY_STALE) */
    uint8   state;
}TcpIp_NdpCacheEntryType;
/*! @brief Index to select specific measurement data */
typedef uint8  TcpIp_MeasurementIdxType;

/*! @brief By this API service the TCP/IP stack is requested to allocate a new socket. 
    Note: Each accepted incoming TCP connection also allocates a socket resource.*/
typedef P2FUNC(Std_ReturnType,TCPIP_APPL_CODE,TcpIp_UpGetSocket)
(
    TcpIp_DomainType Domain,
    TcpIp_ProtocolType Protocol,
    P2VAR(TcpIp_SocketIdType,AUTOMATIC,TCPIP_APPL_DATA) SocketIdPtr
);

/*! @brief The TCP/IP stack calls this primitive after the reception of data on a socket. The socket identifier 
    along with configuration information determines which module is to be called.*/
typedef P2FUNC(void,TCPIP_APPL_CODE,Up_RxIndicationUpFuncType)
(
    TcpIp_SocketIdType SocketId,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) RemoteAddrPtr,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) BufPtr,
    uint16 Length 
);

/*! @brief This service gets called if the stack encounters a condition described by the values in Event. */
typedef P2FUNC(void,TCPIP_APPL_CODE,Up_TcpIpEventFuncType)( TcpIp_SocketIdType SocketId, TcpIp_EventType Event );
/*! @brief The TCP/IP stack calls this function after the data has been acknowledged by the peer for TCP.*/
typedef P2FUNC(void,TCPIP_APPL_CODE,Up_TxConfirmationFuncType)( TcpIp_SocketIdType SocketId, uint16 Length );
/*! @brief This service gets called if the stack put a socket into the listen mode before (as server) and a peer 
    connected to it (as client).*/
typedef P2FUNC(Std_ReturnType,TCPIP_APPL_CODE,Up_TcpAcceptedFuncType) 
(
    TcpIp_SocketIdType SocketId,
    TcpIp_SocketIdType SocketIdConnected,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) RemoteAddrPtr
);
/*! @brief This service gets called if the stack initiated a TCP connection before (as client) and the peer 
    (the server) acknowledged the connection set up.*/
typedef P2FUNC(void,TCPIP_APPL_CODE,Up_TcpConnectedFuncType)(TcpIp_SocketIdType SocketId );
/*! @brief This service requests to copy data for transmission to the buffer indicated. This call is triggered by 
    TcpIp_Transmit().*/
typedef P2FUNC(BufReq_ReturnType,TCPIP_APPL_CODE,Up_CopyTxDataFunctType)
( 
    TcpIp_SocketIdType SocketId,
    uint8* BufPtr,
    uint16 BufLength
);

/*! @brief This service gets called by the TCP/IP stack if an IP address assignment changes */
typedef P2FUNC(void,TCPIP_APPL_CODE,Up_LocalIpAddrAssignmentFuncType)
(
    TcpIp_LocalAddrIdType IpAddrId,
    TcpIp_IpAddrStateType State 
);

/* !# configuration */
typedef struct 
{
    /*! @brief Specifies the default value for the priority for all outgoing frames.
    Note: the value can be changed for each socket individually via TcpIp_ChangeParameter() service. If this optional
    parameter is not available, 0 is used as default priority. Range 0 .. 7 */
    uint8   FramePrioDefault;
    /*! @brief Reference to EthIf controller where the IP address shall be assigned. */
    uint8   EthIfCtrlId;
}TcpIp_CtrlConfigType;

typedef enum
{
    TCPIP_FORGET = 0, /*! @brief After a dynamic IP address has been assigned just use it for this link-up time. */
    TCPIP_STORE =1 /*! @brief After a dynamic IP address has been assigned store the address persistently. */
}TcpIp_AssignmentLifetime;

typedef enum
{
    TCPIP_AUTOMATIC = 0u, /*! @brief Assignment shall be initiated automatically by TCP/IP stack. */
    TCPIP_MANUAL = 1u /*! @breif Assignment shall be initiated manually via TcpIp_RequestIpAddrAssignment(). */
}TcpIp_AssignmentTrigger;
/*! @brief specifies the assignment policy for the IP address. */
typedef struct
{
    /*! @brief Defines the lifetime of a dynamically fetched IP address. If TcpIpAssignmentMethod = TCPIP_STATIC 
    then TcpIpAssignmentLifetime shall*/
    TcpIp_AssignmentLifetime    AssignmentLifetime;
    /*! @brief Method of address assignment */
    TcpIp_IpAddrAssignmentType  AssignmentMethod;   
    /*! @brief Priority of assignment (1 is highest). If a new address from an assignment method with a higher 
    priority is available, it overwrites the IP address previously assigned by an assignment method with a 
    lower priority.*/
    uint8   TcpIpAssignmentPriority;
    /*! @brief Trigger of address assignment. */
    TcpIp_AssignmentTrigger TcpIpAssignmentTrigger;
}TcpIp_AddrAssignmentConfigType;

/*! @brief Defines the address type */
typedef enum
{
    TCPIP_ANYCAST = 0U, /*! @brief Anycast address */
    TCPIP_MULTICAST = 1U, /*! @brief Multicast address */
    TCPIP_UNICAST = 2U, /*! @brief Unicast address */
}TcpIp_AddressType;

/*! @brief specifies a static IP address including directly related parameters. */
typedef struct 
{
    /*! @brief Static IP Address. To specify any IP address for a certain EthIfCtrl, "ANY" has to be set as wildcard. 
    See TcpIp_Bind() for more details. */
    uint32 TcpIpStaticIpAddress;
    /*! @brief IP address of default router (gateway) */
    uint32 TcpIpDefaultRouter;
    /*! @brief Network mask of IPv4 address or address prefix of IPv6 address in CIDR Notation, i.e. 
    decimal value between 0 and 32 (IPv4) or 0 and 128 (IPv6) that describes the number of significant bits defining 
    the network number or prefix of an IP address.*/
    uint8 TcpIpNetmask;
    /*! @brief Defines if the address is valid */
    boolean IsValid;
}TcpIp_StaticIpAddressConfigType;

/*! @brief Specifies the local IP (Internet Protocol) addresses used for IP communication. */
typedef struct 
{
    /*! @brief IP address table identifier assigned by TCP/IP stack. */
    TcpIp_LocalAddrIdType   TcpIpAddrId;
    /*! @brief Defines the address type */
    TcpIp_AddressType       AddressType;
    /*! @brief Address family. */
    TcpIp_DomainType        DomainType;
    /*! @brief Reference to a TcpIpCtrl specifying the EthIf Controller where the IP address shall be assigned.*/
    uint8                   CtrlConfigId;
    /*! @brief Reference to the AddrAssignment configuration */
    const TcpIp_AddrAssignmentConfigType * pAddrAssignmentConfig;
    /*! @brief Reference to the Static Ip Address configuration */
    const TcpIp_StaticIpAddressConfigType * pStaticIpAddressConfig;
}TcpIp_LocalAddrConfigType;

typedef enum
{
    TcpIp_SocketOwnerULCDD=0U,
    TcpIp_SocketOwnerULSOAD
}TcpIp_SocketOwnerULType;

/*! @brief specifies an upper layer of TcpIp that uses the socket API. */
typedef struct 
{
    /*! @brief This parameter defines the <Up_CopyTxData> function of the TcpIpSocketOwner module. */
    Up_CopyTxDataFunctType              pSocketOwnerCopyTxDataFunc;
    /*! @brief This parameter defines the name of the <Up_LocalIpAddrAssignmentChg> function of the TcpIpSocketOwner 
    module. The function name shall only be configurable if TcpIpSocketOwnerUpperLayerType is set to CDD.*/
    Up_LocalIpAddrAssignmentFuncType    pSocketOwnerLocalIpAddrAssignmentChgFunc;
    /*! @brief This parameter defines the name of the <Up_RxIndication> function of the TcpIpSocketOwner module. 
    The function name shall only be configurable if TcpIpSocketOwnerUpperLayerType is set to CDD*/
    Up_RxIndicationUpFuncType           pSocketOwnerRxIndicationFunc;
    /*! @brief This parameter defines the name of the <Up_TcpAccepted> function of the TcpIpSocketOwner module. 
    The function name shall only be configurable if TcpIpSocketOwnerUpperLayerType is set to CDD.*/
    Up_TcpAcceptedFuncType              pSocketOwnerTcpAcceptedFunc;
    /*! @brief This parameter defines the name of the <Up_TcpConnected> function of the TcpIpSocketOwner module. 
    The function name shall only be configurable if TcpIpSocketOwnerUpperLayerType is set to CDD.*/
    Up_TcpConnectedFuncType             pSocketOwnerTcpConnectedFunc;
    /*! @brief This parameter defines the name of the <Up_TcpIpEvent> function of the TcpIpSocketOwner module. 
    The function name shall only be configurable if TcpIpSocketOwnerUpperLayerType is set to CDD.*/
    Up_TcpIpEventFuncType               pSocketOwnerTcpIpEventFunc;
    /*! @brief This parameter defines the name of the <Up_TxConfirmation> function of the TcpIpSocketOwner module. 
    The function name shall only be configurable if TcpIpSocketOwnerUpperLayerType is set to CDD*/
    Up_TxConfirmationFuncType           pSocketOwnerTxConfirmationFunc;
    /*! @brief This parameter specifies the type of the upper layer module. */
    TcpIp_SocketOwnerULType             SocketOwnerUL;
}TcpIp_SocketOwnerConfigType;

typedef struct
{
    /*! @brief pointer to the Controller configuration array */
    const TcpIp_CtrlConfigType          *pCtrlConfig;
    /*! @brief pointer to the Local address configuration array */
    const TcpIp_LocalAddrConfigType     *pLocalAddrConfig;
    /*! @brief pointer to the Controller configuration array */
    const TcpIp_SocketOwnerConfigType   *pSocketOwnerConfig;
}TcpIp_TcpIpConfigType;

/*! @brief defines Configuration data structure of the TcpIp module. */
typedef struct 
{
    uint8 dummy;/* The content of the configuration data structure is implementation specific.Not supported */
}TcpIp_ConfigType;


#define TcpIp_CfgGetTcpIpConfigPtr()        (pTcpIpConfig)
#define TcpIp_CfgGetTcpIpCtrlConfig(pCfg)   (pCfg->pCtrlConfig)

/* TcpIp_CtrlConfig */
#define TcpIp_CfgGetTcpIpCtrlEthIfCtrlId(pCfg)      (TcpIp_CfgGetTcpIpCtrlConfig(pCfg).EthIfCtrlId)
#define TcpIp_CfgGetTcpIpCtrlFramePrioDefault(pCfg) (TcpIp_CfgGetTcpIpCtrlConfig(pCfg).FramePrioDefault)

/* socket function */
#define TcpIp_CfgGetSocketOwnerConfig(pCfg,Id)             (&pCfg->pSocketOwnerConfig[Id])
#define TcpIp_CfgGetUpCopyTxDataFunc(pCfg,Id)              (TcpIp_CfgGetSocketOwnerConfig(pCfg,Id)->pSocketOwnerCopyTxDataFunc)
#define TcpIp_CfgGetUpLocalIpAddrAssignmentFunc(pCfg,Id)   (TcpIp_CfgGetSocketOwnerConfig(pCfg,Id)->pSocketOwnerLocalIpAddrAssignmentChgFunc)
#define TcpIp_CfgGetUpRxIndicationUpFunc(pCfg,Id)          (TcpIp_CfgGetSocketOwnerConfig(pCfg,Id)->pSocketOwnerRxIndicationFunc)
#define TcpIp_CfgGetUpTcpAcceptedFunc(pCfg,Id)             (TcpIp_CfgGetSocketOwnerConfig(pCfg,Id)->pSocketOwnerTcpAcceptedFunc)
#define TcpIp_CfgGetUpTcpConnectedFunc(pCfg,Id)            (TcpIp_CfgGetSocketOwnerConfig(pCfg,Id)->pSocketOwnerTcpConnectedFunc)
#define TcpIp_CfgGetUpTcpIpEventFunc(pCfg,Id)              (TcpIp_CfgGetSocketOwnerConfig(pCfg,Id)->pSocketOwnerTcpIpEventFunc)
#define TcpIp_CfgGetUpTxConfirmationFunc(pCfg,Id)          (TcpIp_CfgGetSocketOwnerConfig(pCfg,Id)->pSocketOwnerTxConfirmationFunc)
#define TcpIp_CfgGetUpSocketOwnerUL(pCfg,Id)               (TcpIp_CfgGetSocketOwnerConfig(pCfg,Id)->SocketOwnerUL)

#define TcpIp_CfgGetLocalAddrConfig(pCfg,Id)                   (&pCfg->pLocalAddrConfig[Id])
#define TcpIp_CfgGetLocalAddrConfigAddrId(pCfg,Id)             (TcpIp_CfgGetLocalAddrConfig(pCfg,Id)->TcpIpAddrId)
#define TcpIp_CfgGetLocalAddrConfigAddrType(pCfg,Id)           (TcpIp_CfgGetLocalAddrConfig(pCfg,Id)->AddressType)
#define TcpIp_CfgGetLocalAddrConfigDomainType(pCfg,Id)         (TcpIp_CfgGetLocalAddrConfig(pCfg,Id)->DomainType)
#define TcpIp_CfgGetLocalAddrConfigCtrlConfigId(pCfg,Id)       (TcpIp_CfgGetLocalAddrConfig(pCfg,Id)->CtrlConfigId)
#define TcpIp_CfgGetLocalAddrAssignmentConfig(pCfg,Id)         (TcpIp_CfgGetLocalAddrConfig(pCfg,Id)->pAddrAssignmentConfig)
#define TcpIp_CfgGetLocalAddrStaticIpAddressConfig(pCfg,Id)    (TcpIp_CfgGetLocalAddrConfig(pCfg,Id)->pStaticIpAddressConfig)

#define TcpIp_CfgGetLocalAddrTcpIpStaticIpAddressConfig(pCfg,Id) (&TcpIp_CfgGetLocalAddrStaticIpAddressConfig(pCfg,Id)[Id])
#define TcpIp_CfgGetLocalAddrTcpIpStaticIpAddress(pCfg,Id) (TcpIp_CfgGetLocalAddrTcpIpStaticIpAddressConfig(pCfg,Id)->TcpIpStaticIpAddress)
#define TcpIp_CfgGetLocalAddrTcpIpDefaultRouter(pCfg,Id)   (TcpIp_CfgGetLocalAddrTcpIpStaticIpAddressConfig(pCfg,Id)->TcpIpStaticIpAddress)
#define TcpIp_CfgGetLocalAddrTcpIpNetmask(pCfg,Id)         (TcpIp_CfgGetLocalAddrTcpIpStaticIpAddressConfig(pCfg,Id)->TcpIpNetmask)
#define TcpIp_CfgGetLocalAddrTcpIpStaticIpAddrValid(pCfg,Id) (TcpIp_CfgGetLocalAddrTcpIpStaticIpAddressConfig(pCfg,Id)->IsValid)

#define TcpIp_CfgGetLocalAssignmentConfig(pCfg,Id)         (&TcpIp_CfgGetLocalAddrAssignmentConfig(pCfg,Id)[Id])
#define TcpIp_CfgGetLocalAddrAssignmentLifetime(pCfg,Id)   (TcpIp_CfgGetLocalAddrAssignmentConfig(pCfg,Id)->AssignmentLifetime)
#define TcpIp_CfgGetLocalAssignmentMethod(pCfg,Id)         (TcpIp_CfgGetLocalAddrAssignmentConfig(pCfg,Id)->AssignmentMethod)
#define TcpIp_CfgGetLocalAssignmentPriority(pCfg,Id)       (TcpIp_CfgGetLocalAddrAssignmentConfig(pCfg,Id)->TcpIpAssignmentPriority)
#define TcpIp_CfgGetLocalAssignmentTrigger(pCfg,Id)        (TcpIp_CfgGetLocalAddrAssignmentConfig(pCfg,Id)->TcpIpAssignmentTrigger)


Std_ReturnType TcpIp_SoAdGetSocket
(
    TcpIp_DomainType Domain,
    TcpIp_ProtocolType Protocol,
    P2VAR(TcpIp_SocketIdType,AUTOMATIC,TCPIP_APPL_DATA) SocketIdPtr
);
#endif /* TCPIP_CFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
