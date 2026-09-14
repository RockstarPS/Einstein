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
*    @file SoAd_Types.h
*    @ingroup SoAd
*    @brief This file provides the types for the SoAd module.
********************************************************************************************************************/
#ifndef SOAD_TYPES_H
#define SOAD_TYPES_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "SoAd_Cfg.h"
#include "ComStack_Types.h"
#if (SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
#include "TcpIp_Types.h"
#endif
/********************************************************************************************************************
*   MACRO AND DATA TYPES                                                                                            *
********************************************************************************************************************/
/********************************************************************************************************************
*                                 #! memory and pointer classes.                                                    *
********************************************************************************************************************/
#ifndef AUTOMATIC
#define AUTOMATIC
#endif

#ifndef SOAD_CODE
#define SOAD_CODE
#endif 

#ifndef SOAD_CONST
#define SOAD_CONST
#endif  

#ifndef SOAD_APPL_DATA
#define SOAD_APPL_DATA
#endif

#ifndef SOAD_APPL_CONST
#define SOAD_APPL_CONST
#endif

#ifndef SOAD_CALLOUT_CODE
#define SOAD_CALLOUT_CODE
#endif

#ifndef SOAD_VAR
#define SOAD_VAR
#endif

#ifndef SOAD_VAR_INIT
#define SOAD_VAR_INIT
#endif

#ifndef SOAD_VAR_NOINIT
#define SOAD_VAR_NOINIT
#endif

#ifndef SOAD_VAR_POWER_ON_INIT
#define SOAD_VAR_POWER_ON_INIT
#endif

#ifndef SOAD_VAR_FAST
#define SOAD_VAR_FAST
#endif

#ifndef SOAD_VAR_SLOW
#define SOAD_VAR_SLOW
#endif

/*! @brief type to specify the state of a SoAd socket connection. */
typedef enum
{
    SOAD_SOCON_ONLINE=0u,
    SOAD_SOCON_RECONNECT,
    SOAD_SOCON_OFFLINE
}SoAd_SoConModeType;

/*! @brief Measurement index of dropped PDUs caused by invalid destination TCP-Port */
#define SOAD_MEAS_DROP_TCP              0x01u
/*! @brief  Measurement index of dropped PDUs caused by invalid destination UDP-Port */
#define SOAD_MEAS_DROP_UDP              0x02u
/*! @brief Measurement start index reserved by AUTOSAR */
#define SOAD_MEAS_RESERVED_1_START      0x03u
/*! @brief Measurement end index reserved by AUTOSAR */
#define SOAD_MEAS_RESERVED_1_END        0x7Fu
/*! @brief Measurement start index reserved by AUTOSAR */
#define SOAD_MEAS_RESERVED_2_START      0x80u
/*! @brief Measurement end index reserved by AUTOSAR */
#define SOAD_MEAS_RESERVED_2_END        0xEFu
/*! @brief Measurement start index reserved by AUTOSAR */
#define SOAD_MEAS_RESERVED_3_START      0xF0u
/*! @brief Measurement end index reserved by AUTOSAR */
#define SOAD_MEAS_RESERVED_3_END        0xFEu
/*! @brief Measurement index represents all measurement indexes */
#define SOAD_MEAS_ALL                   0xFFu

/*! @brief Index to select specific measurement data */ 
typedef uint8 SoAd_MeasurementIdxType;

/*! @brief Defines the type of Ipv4 address */
typedef uint32 SoAd_IpAddrInetType;

/*! @brief Specifies the bsd specific udp param id */
#define SOAD_PARAMID_STACK_SPECIFIC_UDP             0xFCU   
/*! @brief Specifies the bsd specific tcp param id */
#define SOAD_PARAMID_STACK_SPECIFIC_TCP             0xFDU
/*! @brief Specifies the bsd specific socket param id */
#define SOAD_PARAMID_STACK_SPECIFIC                 0xFEU

#if (SOAD_TCPIP_API == SOAD_TCPIP_API_AUTOSAR)
/*! @brief  Defines the Socket domain type for IPv4 . */
#define SOAD_AF_INET    TCPIP_AF_INET 
/*! @brief  Defines the Socket domain type for IPv6 . */
#define SOAD_AF_INET6   TCPIP_AF_INET6
/*! @brief  Defines the Socket domain type. */
typedef TcpIp_DomainType SoAd_DomainType;

/*! @brief  Defines the TCP protocol type */
#define SOAD_IPPROTO_TCP    TCPIP_IPPROTO_TCP     
/*! @brief  Defines the UDP protocol type */
#define SOAD_IPPROTO_UDP    TCPIP_IPPROTO_UDP   
/*! @brief  Defines the socket protocol type */
typedef TcpIp_ProtocolType  SoAd_ProtocolType;

/*! @brief Defines the socket address type */
typedef TcpIp_SockAddrType SoAd_SockAddrType;

typedef TcpIp_SocketIdType SoAd_TcpIpSocketIdType;

/*! @brief Defines the local Ip address state as assigned */
#define SOAD_IPADDR_STATE_ASSIGNED      TCPIP_IPADDR_STATE_ASSIGNED
/*! @brief Defines the local Ip address state as assigned but cannot be used as the network is not active */
#define SOAD_IPADDR_STATE_ONHOLD        TCPIP_IPADDR_STATE_ONHOLD
/*! @brief Defines the local Ip address state as unassigned */
#define SOAD_IPADDR_STATE_UNASSIGNED    TCPIP_IPADDR_STATE_UNASSIGNED
/*! @brief Defines the state of local IP address type */
typedef TcpIp_IpAddrStateType   SoAd_IpAddrStateType;

/*! @brief  Defines the assignment type as Static IP address. */
#define SOAD_IPADDR_ASSIGNMENT_STATIC           TCPIP_IPADDR_ASSIGNMENT_STATIC
/*! @brief  Defines the assignment type as DoIP use-case. */
#define SOAD_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP   TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP
/*! @brief  Defines the assignment type as DHCP IP address. */
#define SOAD_IPADDR_ASSIGNMENT_DHCP             TCPIP_IPADDR_ASSIGNMENT_DHCP
/*! @brief  Defines the assignment type as  Link local IP address. */
#define SOAD_IPADDR_ASSIGNMENT_LINKLOCAL        TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL
/*! @brief  Defines the assignment type IPv6 address by Router Advertisement. */
#define SOAD_IPADDR_ASSIGNMENT_IPV6_ROUTER      TCPIP_IPADDR_ASSIGNMENT_IPV6_ROUTER
/*! @brief  Defines the Ip address assignment type */
typedef TcpIp_IpAddrAssignmentType  SoAd_IpAddrAssignmentType;

/*! @brief  Defines the event type of TCP socket connection reset */
#define SOAD_TCP_RESET          TCPIP_TCP_RESET
/*! @brief  Defines the event type of TCP socket connection closed */
#define SOAD_TCP_CLOSED         TCPIP_TCP_CLOSED
/*! @brief  Defines the event type of TCP socket connection received a FIN. */
#define SOAD_TCP_FIN_RECEIVED   TCPIP_TCP_FIN_RECEIVED
/*! @brief  Defines the event type of UDP socket connection closed */
#define SOAD_UDP_CLOSED         TCPIP_UDP_CLOSED 
/*! @brief Socket event type defined for AUTOSAR Socket API. */
typedef TcpIp_EventType SoAd_EventType;

typedef TPParameterType SoAd_TcpIpParameterType;
#else

/*! @brief  Defines the Socket domain type for IPv4 . */
#define SOAD_AF_INET    (0x02U) 
/*! @brief  Defines the Socket domain type for IPv6 . */
#define SOAD_AF_INET6   (0x1CU)
/*! @brief  Defines the Socket domain type. */
typedef uint16 SoAd_DomainType;

/*! @brief  Defines the TCP protocol type */
#define SOAD_IPPROTO_TCP    (0x06u)     
/*! @brief  Defines the UDP protocol type */
#define SOAD_IPPROTO_UDP    (0x11u)    
/*! @brief  Defines the socket protocol type */
typedef uint8  SoAd_ProtocolType;

/*! @brief This structure defines an IPv4 address type which can be derived from the generic address structure 
*   via cast.*/
typedef struct
{
  SoAd_DomainType    Domain; /* This is the code for the address format of this address */
  uint16             Port; /* port number */
  uint32             Addr[1]; /* IPv4 address in network byte order */
} TcpIp_SockAddrInetType;
/*! @brief This structure defines a IPv6 address type which can be derived from the generic address structure via 
    cast.*/
typedef struct
{
  SoAd_DomainType   Domain;    /* This is the code for the address format of this address */
  uint16             Port;      /* port number */
  uint32             Addr[4];   /* IPv6 address in network byte order */
} TcpIp_SockAddrInet6Type;

/*! @brief Generic structure used by APIs to specify an IP address. (A specific address type can be derived from this 
*   structure via a cast to the specific struct type.)*/
typedef union 
{
    /*! @brief This is the code for the address format of this address */
    SoAd_DomainType Domain;
    TcpIp_SockAddrInetType SockAddrInetType;
    TcpIp_SockAddrInet6Type SockAddrInet6Type;
}TcpIp_SockAddrType;

/*! @brief Defines the socket address type */
typedef TcpIp_SockAddrType SoAd_SockAddrType;

typedef sint32 TcpIp_SocketIdType;
typedef TcpIp_SocketIdType SoAd_TcpIpSocketIdType;

/*! @brief Defines the local Ip address state as assigned */
#define SOAD_IPADDR_STATE_ASSIGNED      0u
/*! @brief Defines the local Ip address state as assigned but cannot be used as the network is not active */
#define SOAD_IPADDR_STATE_ONHOLD        1u
/*! @brief Defines the local Ip address state as unassigned */
#define SOAD_IPADDR_STATE_UNASSIGNED    2u
/*! @brief Defines the state of local IP address type */
typedef uint8   TcpIp_IpAddrStateType;
typedef TcpIp_IpAddrStateType   SoAd_IpAddrStateType;

/*! @brief  Defines the assignment type as Static IP address. */
#define SOAD_IPADDR_ASSIGNMENT_STATIC           0u
/*! @brief  Defines the assignment type as DoIP use-case. */
#define SOAD_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP   1u
/*! @brief  Defines the assignment type as DHCP IP address. */
#define SOAD_IPADDR_ASSIGNMENT_DHCP             2u
/*! @brief  Defines the assignment type as  Link local IP address. */
#define SOAD_IPADDR_ASSIGNMENT_LINKLOCAL        3u
/*! @brief  Defines the assignment type IPv6 address by Router Advertisement. */
#define SOAD_IPADDR_ASSIGNMENT_IPV6_ROUTER      4u
/*! @brief  Defines the Ip address assignment type */
typedef uint8  TcpIp_IpAddrAssignmentType;
typedef TcpIp_IpAddrAssignmentType  SoAd_IpAddrAssignmentType;

/*! @brief  Defines the event type of TCP socket connection reset */
#define SOAD_TCP_RESET          0U
/*! @brief  Defines the event type of TCP socket connection closed */
#define SOAD_TCP_CLOSED         1U
/*! @brief  Defines the event type of TCP socket connection received a FIN. */
#define SOAD_TCP_FIN_RECEIVED   2U
/*! @brief  Defines the event type of UDP socket connection closed */
#define SOAD_UDP_CLOSED         3U 
/*! @brief Socket event type defined for AUTOSAR Socket API. */
typedef uint8 TcpIp_EventType;
typedef TcpIp_EventType SoAd_EventType;

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
typedef uint8 SoAd_TcpIpParameterType;
#endif

#endif /* SOAD_TYPES_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/

