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
*   @file SoAd_TcpIpBsd.c
*   @ingroup SoAd
*   @brief This module implements the bsd socket interface for Linux. 
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "SoAd_Cfg.h"
#if (SOAD_TCPIP_API == SOAD_TCPIP_API_LINUX)
#include "SoAd.h"
#include "SoAd_Lcfg.h"
#include "SoAd_Cbk.h"
#include "SoAd_Tx.h"
#include "SoAd_Socket.h"
#include "SchM_SoAd.h"
#include "SoAd_TcpIpBsd.h"
#include "SoAd_Internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <ifaddrs.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <net/if.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
/********************************************************************************************************************
*  feature validation check                                                                                         *
********************************************************************************************************************/
/* define SOAD_BSD_ENABLE_BIND_SOCKET_TO_INTERFACE to enable bind to socket interface */
/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
/* Bsd macros */
/*! @brief Indicates that no flags shall be set in case of transmission over BSD-like Socket API. */
#define SOAD_BSD_ZERO_FLAGS             0x00
/*! @brief Offset in IPv6 address where ScopeId is stored on BSD-like Socket API. */
#define SOAD_BSD_ADDR_IF_OFFSET         2u
/*! @brief Negative return value in case of BSD-like Socket API. */
#define SOAD_BSD_E_NOT_OK               -1
/*! @brief Value to indicate if file descriptor has not been changed. */
# define SOAD_BSD_FD_NO_CHANGE          0u
/*! @brief Value to indicate if a TCP connection has been established. */
# define SOAD_BSD_TCP_CONNECTED         0u
/*! @brief Positive return value of BSD API. */
# define SOAD_BSD_NO_ERROR              0u
/*! @brief defines the Ipv4 multicast mask value */
#define SOAD_BSD_IPV4_MULTICAST_MASK    0x000000F0U
/*! @brief defines the Ipv4 multicast value. */
#define SOAD_BSD_IPV4_MULTICAST         0x000000E0U
/*! @brief defines the uint32 broad cast address value 255.255.225.255 */
#define SOAD_BSD_INADDR_BROADCAST       0xFFFFFFFFu

#define SoAd_UtilIsIpv4AddrMulticast(IpAddr) (((IpAddr)&SOAD_BSD_IPV4_MULTICAST_MASK) == SOAD_BSD_IPV4_MULTICAST)
#define SoAd_UtilIsIpv4AddrNotMulticast(IpAddr) (((IpAddr)&SOAD_BSD_IPV4_MULTICAST_MASK) != SOAD_BSD_IPV4_MULTICAST)
/********************************************************************************************************************
*  #! PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                     *
********************************************************************************************************************/
#define SOAD_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" 
SOAD_LOCAL VAR(SoAd_LocalAddrCheckCountType,SOAD_VAR_NOINIT) SoAd_TcpIpBsdLocalAddrCheckCounter;
#define SOAD_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/********************************************************************************************************************
*  #! PRIVATE FUNCTION PROTOTYPES                                                                                   *
********************************************************************************************************************/
/*!******************************************************************************************************************
* @brief The Api is used to reset the Ip addr configuration to the default values.
* @param LocalAddrIdx the local Ip addr id
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsdResetLocalIpAddr(SoAd_LocalIpAddrIdxType LocalAddrIdx);
/*!******************************************************************************************************************
* @brief The Api handles the Ip addr state changes.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsdIpAddrStateHandler(void);
/*!******************************************************************************************************************
* @brief The Api is used to check the availability and link status of the local ip addr.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsdLocalAddressCheckHandler(void);
/*!******************************************************************************************************************
* @brief The Api is handls the unassigned Ip address state
* @param LocalAddrIdx the local Ip addr id
* @return SoAd_IpAddrStateType Ip address state SOAD_IPADDR_STATE_ASSIGNED,SOAD_IPADDR_STATE_ONHOLD,
*         SOAD_IPADDR_STATE_UNASSIGNED
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(SoAd_IpAddrStateType, SOAD_CODE) SoAd_TcpIpBsdIpAddrStateUnassignedHandler
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx
);
/*!******************************************************************************************************************
* @brief The Api is handls the assigned Ip address state
* @param LocalAddrIdx the local Ip addr id
* @return SoAd_IpAddrStateType Ip address state SOAD_IPADDR_STATE_ASSIGNED,SOAD_IPADDR_STATE_ONHOLD,
*         SOAD_IPADDR_STATE_UNASSIGNED
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(SoAd_IpAddrStateType, SOAD_CODE) SoAd_TcpIpBsdIpAddrStateAssignedHandler
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx
);
/*!******************************************************************************************************************
* @brief The Api is used to assign the local ip address
* @param LocalAddrIdx the local Ip addr id
* @return status of the request E_OK: requested accepted E_NOT_OK: requested not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdAssignIpAddr
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx
);
/*!******************************************************************************************************************
* @brief The Api is used to check if ip address is assigned and overwrite the existing local address if requested 
*   by OverwriteLocal flag
* @param LocalAddrIdx the local Ip addr id
* @param OverwriteLocal TRUE: Overwrite existing ip FALSE: Donot overwrite existing ip
* @return status of the request E_OK: requested accepted E_NOT_OK: requested not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdCheckAndOverwriteLocalAddr
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    boolean OverwriteLocal
);
/*!******************************************************************************************************************
* @brief The Api is used to release the assigned IP address
* @param LocalAddrIdx the local Ip addr id
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsdReleaseIpAddr(SoAd_LocalIpAddrIdxType LocalAddrIdx);
/*!******************************************************************************************************************
* @brief The Api is used to check the link status of the local ip address
* @param LocalAddrIdx the local Ip addr id
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsdCheckLinkStatus(SoAd_LocalIpAddrIdxType LocalAddrIdx);
/*!******************************************************************************************************************
* @brief The Api is used to handle the Tcp socket states.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsdTcpSocketStatesHandler(void);
/*!******************************************************************************************************************
* @brief The Api is used to poll for the tcp connection check
* @param SocketIdx the socket id
* @return status of the request. TRUE: retry again FALSE: donot retry again
********************************************************************************************************************/
SOAD_LOCAL FUNC(boolean, SOAD_CODE) SoAd_TcpIpBsdTcpCheckConnect(SoAd_SocketIdxType SocketIdx);
/*!******************************************************************************************************************
* @brief The Api is used to poll for the tcp accpet check
* @param SocketIdx the socket id
* @return status of the request. TRUE: retry again FALSE: donot retry again
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(boolean, SOAD_CODE) SoAd_TcpIpBsdTcpCheckAccept(SoAd_SocketIdxType SocketIdx);
/*!******************************************************************************************************************
* @brief The Api is used to bind the socket to the requested ip and port
* @param SocketIdx the autosar socket id
* @param TcpIpSocketIdx the bsd socket id
* @param[in] LocalAddrPtr pointer to the bsd local ip address
* @param LocalAddrSize the size of the bsd local ip address
* @param[in,out] PortPtr the pointer to the port , in: requested port out: assigned port by linux
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdBindSocket
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketIdx,
    P2CONST(struct sockaddr, AUTOMATIC, SOAD_APPL_VAR) LocalAddrPtr,
    size_t LocalAddrSize,
    P2VAR(SoAd_PortType, AUTOMATIC, SOAD_APPL_VAR) PortPtr
);
#ifdef SOAD_BSD_ENABLE_BIND_SOCKET_TO_INTERFACE
/*!******************************************************************************************************************
* @brief The Api is used to bind the socket to the interface of the local addr
* @param LocalAddrIdx the local Ip addr id
* @param TcpIpSocketIdx the bsd socket id  
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdBindSocketToInterface
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    TcpIp_SocketIdType TcpIpSocketIdx
);
#endif
/*!******************************************************************************************************************
* @brief The Api is used to release the socket tx buffer used by the socket 
* @param SocketTxBufferIdx the socket tx buffer idx
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsdReleaseSocketTxBuffer(SoAd_SocketTxBufferIdType SocketTxBufferIdx);
/********************************************************************************************************************
* @brief The Api is used to release the socket tx buffer used by the socket id
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsd_ReleaseSocketTxBufferForSocket(SoAd_SocketIdxType SocketIdx);
/*!******************************************************************************************************************
* @brief The Api is used to reset the Ip addr configuration to the default values.
* @param SocketIdx the requesting socket id
* @param Length the request length
* @param SocketTxBufferIdx[out] the socket tx buffer idx if the request was accepted 
* @return status of the request E_OK: requested accepted E_NOT_OK: requested not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdRequestSocketTxBuffer
(
    SoAd_SocketIdxType SocketIdx,
    uint16 Length,
    P2VAR(SoAd_SocketTxBufferIdType, SOAD_APPL_DATA, SOAD_APPL_DATA) SocketTxBufferIdx
);
/*!******************************************************************************************************************
* @brief The Api is used to update the length of the successfully transmitted bytes
* @param SocketTxBufferIdx the socket tx buffer idx
* @param Length the transmitted length
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdUpdateSocketTxBuffer
(
    SoAd_SocketTxBufferIdType SocketTxBufferIdx,
    uint16 Length
);
/*!******************************************************************************************************************
* @brief The Api is used to handle the pending tx bytes in the socket tx buffer.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsdSocketTxBufferHandler(void);
/*!******************************************************************************************************************
* @brief The Api is handle and process the socket reception
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsdSocketReceptionHandler(void);
/*!******************************************************************************************************************
* @brief The Api is used to process the tcp receive.
* @param SoConIdx the socket connection id
* @return status of the request E_OK: requested accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdTcpReceive(SoAd_SoConIdType SoConIdx);
/*!******************************************************************************************************************
* @brief The Api is used to reset the Ip addr configuration to the default values.
* @param SoConIdx the socket connection id
* @param TcpIpSocketId the bsd socket id
* @param RemAddrPtr[out] pointer to the remote address of the udp message
* @param RemAddrSize size of the remote address
* @return status of the request E_OK: requested accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdUdpReceiveFrom
(
    SoAd_SoConIdType SoConIdx,
    TcpIp_SocketIdType TcpIpSocketId,
    P2VAR(struct sockaddr, AUTOMATIC, SOAD_APPL_VAR) RemAddrPtr,
    socklen_t RemAddrSize
);
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdIsSameAsLocalIp
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(SoAd_SockAddrType,AUTOMATIC,SOAD_APPL_CONST)  pRemAddr
);
/********************************************************************************************************************
*  #! PUBLIC FUNCTION IMPLEMENTATION                                                                                *
********************************************************************************************************************/
/********************************************************************************************************************
* @brief The Api is used to initialize the bsd TcpIp
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpBsdInit(void)
{
    SoAd_SocketIdxType SocketIdx;
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    SoAd_SocketTcpRxBufferIdType TcpRxBufferCtrlIdx;
    SoAd_SocketTxBufferIdType SocketTxBufferCtrlIdx;
    /* Initialize the local address */
    for(LocalAddrIdx=0u; LocalAddrIdx < SoAd_CfgGetNumOfLocalIpAddr();LocalAddrIdx++)
    {
        if (SoAd_LocalAddrCfgGetAssignTriggerType(LocalAddrIdx) == SOAD_ASSIGN_TRIGGER_AUTOMATIC)
        {
            SoAd_LocalIpAddrCtrlSetLocalAddrEventStatus(LocalAddrIdx,TRUE);
        }
        SoAd_LocalIpAddrCtrlSetIpAddrReqState(LocalAddrIdx,SOAD_LOCAL_IP_ADDR_REQ_STATE_NONE);
        SoAd_TcpIpBsdResetLocalIpAddr(LocalAddrIdx);
    }
    /* Initialize the Tcp Rx buffer */
    for (SocketIdx = 0u; SocketIdx < SoAd_CfgGetNumOfSocket(); SocketIdx++)
    {
        if (SoAd_SocketCfgGetTcpRxBufferEnable(SocketIdx) == TRUE) // TODO
        {
            TcpRxBufferCtrlIdx = SoAd_SocketCfgGetTcpRxBufferCtrlIdx(SocketIdx); // TODO
            SoAd_SocketTcpRxBufferCtrlSetLength(TcpRxBufferCtrlIdx,0U);
            SoAd_SocketTcpRxBufferCtrlSetTcpRxBufferIdx(TcpRxBufferCtrlIdx,
                            SoAd_TcpIpBsdCfgGetTcpRxBufferStartIdx(TcpRxBufferCtrlIdx));
        }
        SoAd_SocketBrdAddrCtrlSetDirectBrdAddrSockId(SocketIdx,SOAD_SOCKET_ID_INVALID);
        SoAd_SocketBrdAddrCtrlSetLimitedBrdAddrSockId(SocketIdx,SOAD_SOCKET_ID_INVALID);
    }
    /* Initialize the socket Tx buffer */
    for(SocketTxBufferCtrlIdx = 0u; 
        SocketTxBufferCtrlIdx < SoAd_CfgGetSocketNumOfTxBuffer(); SocketTxBufferCtrlIdx++)
    {
        /* Reset socket transmission buffer. */
        SoAd_SocketTxBufferCtrlSetSocketIdx(SocketTxBufferCtrlIdx,SOAD_NUM_OF_SOCKET);
        SoAd_SocketTxBufferCtrlSetLength(SocketTxBufferCtrlIdx,0U);
    }
    /* Initialize local address check interval counter */
    SoAd_TcpIpBsdLocalAddrCheckCounter = SoAd_CfgGetLocalAddrCheckCount();
}
/*!******************************************************************************************************************
* @brief The Api is used to request the Ip address assignment of the the bsd TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdRequestIpAddrAssignment
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    SoAd_IpAddrAssignmentType Type,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) LocalIpAddrPtr,
    uint8 Netmask,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) DefaultRouterPtr
)
{
    Std_ReturnType RetVal = E_NOT_OK;    
    /* check if Ip address is already assigned */
    if (SoAd_CtrlGetIpAddrState(LocalAddrIdx) == SOAD_IPADDR_STATE_ASSIGNED)
    {
        if (Type == SOAD_IPADDR_ASSIGNMENT_STATIC)
        {
            /* compare if currrent and requested are same */
            if (SoAd_LocalIpAddrCtrlGetIpv4Addr(LocalAddrIdx) == SoAd_UtilpAddrGetIpv4Addr(LocalIpAddrPtr))
            {
                RetVal = E_OK;
            }
        }
    }
    else
    {
        if (SoAd_LocalAddrCfgGetAssignTriggerType(LocalAddrIdx) == SOAD_ASSIGN_TRIGGER_MANUAL)
        {
            if (Type == SOAD_IPADDR_ASSIGNMENT_STATIC)
            {
                if (SoAd_LocalAddrCfgGetAddressType(LocalAddrIdx) == SOAD_ADDRESS_TYPE_MULTICAST)
                {
                    /* multicast address */
                    if (SoAd_UtilIsIpv4AddrMulticast(SoAd_UtilpAddrGetIpv4Addr(LocalIpAddrPtr)))
                    {
                        RetVal = E_OK;
                    }
                }
                else
                {
                    /* Unicast */
                    if ((DefaultRouterPtr != NULL_PTR) && (Netmask <=32u))
                    {
                        if (SoAd_UtilIsIpv4AddrNotMulticast((SoAd_UtilpAddrGetIpv4Addr(DefaultRouterPtr))))
                        {
                            RetVal = E_OK;
                        }
                    }
                    /* update netmask */
                    if (RetVal == E_OK)
                    {
                        SoAd_LocalIpAddrCtrlSetNetMask(LocalAddrIdx,Netmask);
                    }
                }
                /* update address */
                if (RetVal == E_OK)
                {
                    SoAd_LocalIpAddrCtrlSetIpv4Addr(LocalAddrIdx,SoAd_UtilpAddrGetIpv4Addr(LocalIpAddrPtr));
                    SoAd_LocalIpAddrCtrlSetIpAddrReqState(LocalAddrIdx,SOAD_LOCAL_IP_ADDR_REQ_STATE_REQUEST);
                    SoAd_LocalIpAddrCtrlSetLocalAddrEventStatus(LocalAddrIdx,TRUE);
                }
            }
        }
        else
        {
            SoAd_LocalIpAddrCtrlSetLocalAddrEventStatus(LocalAddrIdx,TRUE);
            /* Accept request for link-local or DHCP IP address since it is automatically started at startup. */
            RetVal = E_OK;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to release the ip addr assigned  of the the bsd TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdReleaseIpAddrAssignment(SoAd_LocalIpAddrIdxType LocalAddrIdx)
{
    Std_ReturnType RetVal=E_NOT_OK;
    /* process release request */
    if (SoAd_CtrlGetIpAddrState(LocalAddrIdx) == SOAD_IPADDR_STATE_ASSIGNED)
    {
        if (SoAd_LocalAddrCfgGetAddressType(LocalAddrIdx) == SOAD_ADDRESS_TYPE_MULTICAST)
        {
            SoAd_LocalIpAddrCtrlSetIpAddrReqState(LocalAddrIdx,SOAD_LOCAL_IP_ADDR_REQ_STATE_RELEASE);
            SoAd_LocalIpAddrCtrlSetLocalAddrEventStatus(LocalAddrIdx,TRUE);
            RetVal = E_OK;
        }
    }
    else
    {
        if (SoAd_CtrlGetIpAddrState(LocalAddrIdx) == SOAD_IPADDR_STATE_UNASSIGNED)
        {
            SoAd_LocalIpAddrCtrlSetIpAddrReqState(LocalAddrIdx,SOAD_LOCAL_IP_ADDR_REQ_STATE_NONE);
            RetVal = E_OK;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to get the current ip address assigned to the local addr id of the the bsd TcpIp
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpBsdGetIpAddr
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) LocalAddrPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) NetmaskPtr,
    P2VAR(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) DefaultRouterPtr
)
{
    /* port update to be done at socket */
    *NetmaskPtr = SoAd_LocalIpAddrCtrlGetNetMask(LocalAddrIdx);
    SoAd_UtilpAddrSetIpv4Addr(LocalAddrPtr,SoAd_LocalIpAddrCtrlGetIpv4Addr(LocalAddrIdx));
    SoAd_UtilpAddrSetDomain(LocalAddrPtr,SOAD_AF_INET);
    SOAD_DUMMY_STATEMENT(DefaultRouterPtr);
}
/********************************************************************************************************************
* @brief The Api is used to get the physicall addr(MAC) of the local addr id of the the bsd TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdGetPhysAddr
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    TcpIp_SocketIdType TcpIpSocketId,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) PhysAddrPtr
)
{
    struct ifreq ifr;
    Std_ReturnType  RetVal=E_NOT_OK;
    SoAd_TcpIpCtrlIdxType TcpIpCtrlIdx;
    SoAd_TcpIpCtrlNameBufferSizeType TcpIpCtrlNameStartIdx;
    /* get TcpIp ctrl id*/
    TcpIpCtrlIdx = SoAd_LocalAddrCfgGetTcpIpCtrlIdx(LocalAddrIdx);
    if (TcpIpSocketId != SOAD_SOCKET_ID_INVALID)
    {
        TcpIpCtrlNameStartIdx = SoAd_TcpIpBsdCfgGetCtrlNameBufferStartIdx(TcpIpCtrlIdx);
        SoAd_UtilMemCopy((uint8 *)ifr.ifr_name,
                        (uint8 *)SoAd_TcpIpBsdCfgGetPtrToTcpIpCtrlNameBuffer(TcpIpCtrlNameStartIdx),
                        SoAd_TcpIpBsdCfgGetCtrlNameBufferSize(TcpIpCtrlIdx));
        /* get phy addr */
        if (ioctl(TcpIpSocketId, SIOCGIFHWADDR, &ifr) != SOAD_BSD_E_NOT_OK )
        {
            PhysAddrPtr[0] = (uint8)ifr.ifr_hwaddr.sa_data[0];
            PhysAddrPtr[1] = (uint8)ifr.ifr_hwaddr.sa_data[1];
            PhysAddrPtr[2] = (uint8)ifr.ifr_hwaddr.sa_data[2];
            PhysAddrPtr[3] = (uint8)ifr.ifr_hwaddr.sa_data[3];
            PhysAddrPtr[4] = (uint8)ifr.ifr_hwaddr.sa_data[4];
            PhysAddrPtr[5] = (uint8)ifr.ifr_hwaddr.sa_data[5];
            RetVal = E_OK;
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to read the DHCP host name of the the bsd TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdReadDhcpHostNameOption
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) LengthPtr,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_VAR) DataPtr
)
{
    uint8 Idx;
    Std_ReturnType RetVal = E_NOT_OK;
    /* Retrieve hostname via Socket API. */
    if (gethostname((char*)DataPtr, *LengthPtr) == SOAD_BSD_NO_ERROR) 
    {
        /* Determine hostname length. */
        for (Idx = 0u; Idx < *LengthPtr; Idx++)
        {
            if (DataPtr[Idx] == 0u)
            {
                *LengthPtr = Idx;
            }
        }
        RetVal = E_OK;
    }
    SOAD_DUMMY_STATEMENT(LocalAddrIdx);
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to write the DHCP host name of the the bsd TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdWriteDhcpHostNameOption
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    uint8 Length,
    P2CONST(uint8, AUTOMATIC, SOAD_APPL_VAR) DataPtr
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    /* Set hostname via Socket API. */
    if (sethostname((char *)DataPtr,Length) == SOAD_BSD_NO_ERROR)
    {
        RetVal = E_OK;
    }
    SOAD_DUMMY_STATEMENT(LocalAddrIdx);
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api request to transmit UDP data the bsd TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdUdpTransmit
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketId,
    P2VAR(SoAd_SockAddrType, AUTOMATIC, AUTOMATIC) RemAddrPtr,
    uint16 AvailableLength
)
{
    uint8 *pSendBuffer;
    struct sockaddr_in  RemSockAddr;    
    Std_ReturnType RetVal = E_NOT_OK;
    uint16 MsgFlags = SOAD_BSD_ZERO_FLAGS;
    SoAd_SocketTxBufferIdType SocketTxBufferIdx = 0u;
    size_t RemSockAddrLength = sizeof(struct sockaddr_in);
    /* create BSD sockaddr */
    RemSockAddr.sin_family = AF_INET;
    RemSockAddr.sin_port = SoAd_UtilpAddrGetPort(RemAddrPtr);
    RemSockAddr.sin_addr.s_addr = SoAd_UtilpAddrGetIpv4Addr(RemAddrPtr);
    if (SoAd_TcpIpBsdRequestSocketTxBuffer(SocketIdx, AvailableLength, &SocketTxBufferIdx) == E_OK)
    {
        pSendBuffer = &SoAd_CtrlGetSocketTxBuffer(SoAd_TcpIpBsdCfgGetTxBufferStartIdx(SocketTxBufferIdx)); 
        if (BUFREQ_OK == SoAd_CopyTxData(TcpIpSocketId,pSendBuffer,AvailableLength))
        {
            if (RemSockAddr.sin_addr.s_addr == INADDR_BROADCAST)
            {
                /* Disable routing for IPv4 limited broadcast messages. */
                MsgFlags = MSG_DONTROUTE;
            }
            /* Check if call to Socket API for transmission succeeds. */
            if (SOAD_BSD_E_NOT_OK != sendto(TcpIpSocketId,pSendBuffer,AvailableLength,MsgFlags,
                                                (struct sockaddr *)&RemSockAddr,RemSockAddrLength))
            {
                RetVal = E_OK;
            }
            else
            {
                #ifdef DLOG
                Dlog_Print("!!Udp Transmit (sendto) failed bsd Socket %d error %d",TcpIpSocketId,errno);
                #endif
            }
        }
        SoAd_TcpIpBsdReleaseSocketTxBuffer(SocketTxBufferIdx);
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api request to transmit Tcp data of the the bsd TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdTcpTransmit
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketIdx,
    uint32 AvailableLength,
    boolean ForceRetrieve
)
{
    uint8 *pSendBuffer;
    uint16  LocalAvailableLength;
    Std_ReturnType  RetVal = E_NOT_OK;
    SoAd_SocketTxBufferIdType SocketTxBufferIdx;
    /* Request socket transmission buffer. */
    LocalAvailableLength = (uint16)AvailableLength;
    if (SoAd_TcpIpBsdRequestSocketTxBuffer(SocketIdx, LocalAvailableLength, &SocketTxBufferIdx) == E_OK)
    {
        pSendBuffer = &SoAd_CtrlGetSocketTxBuffer(SoAd_TcpIpBsdCfgGetTxBufferStartIdx(SocketTxBufferIdx)); 
        if (SoAd_CopyTxData(SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx),pSendBuffer,LocalAvailableLength) == BUFREQ_OK)
        {
            /* Call bsd send api for tcp tx. */
            if (send(TcpIpSocketIdx,pSendBuffer,LocalAvailableLength,SOAD_BSD_ZERO_FLAGS) != SOAD_BSD_E_NOT_OK)
            {
                /* Release socket transmission buffer. */
                SoAd_TcpIpBsdReleaseSocketTxBuffer(SocketTxBufferIdx);
                /* Set event to handle TCP confirmation in main function. */
                SoAd_CtrlSetSocketTcpTxEventStatus(SocketIdx,TRUE);
                RetVal = E_OK;
            }
            else
            {
                /* Update length of requested socket transmission buffer for retry if call failed. */
                if (E_OK == SoAd_TcpIpBsdUpdateSocketTxBuffer(SocketTxBufferIdx, LocalAvailableLength))
                {
                    /* Set event to handle TCP confirmation in main function if there is an unused buffer left. */
                    SoAd_CtrlSetSocketTcpTxEventStatus(SocketIdx,TRUE);
                    RetVal = E_OK;
                }
                else
                {
                    /* Release socket transmission buffer if requested buffer is last buffer. */
                    SoAd_TcpIpBsdReleaseSocketTxBuffer(SocketTxBufferIdx);
                    #ifdef DLOG
                    Dlog_Print("!!Tcp Transmit (send) failed bsd Socket %d error %d",TcpIpSocketIdx,errno);
                    #endif
                }
            }
        }
        else
        {
            /* Release socket transmission buffer if data could not be copied. */
            SoAd_TcpIpBsdReleaseSocketTxBuffer(SocketTxBufferIdx);
        }
    }
    SOAD_DUMMY_STATEMENT(ForceRetrieve);
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to change the socket parameter of the the bsd TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdChangeParameter
(
    SoAd_SocketIdxType SocketId,
    TcpIp_SocketIdType TcpIpSocketId,
    SoAd_TcpIpParameterType ParameterId,
    P2VAR(uint8, AUTOMATIC, SOAD_APPL_DATA) ParameterValue
)
{
    sint32 Value;
    sint32 SockOptStatus;
    size_t SocketBufferMin;
    struct linger lingerConfig;
    Std_ReturnType RetVal = E_OK;
    switch (ParameterId)
    {
        case TCPIP_PARAMID_FRAMEPRIO:
            Value = (uint32 )*ParameterValue;
            /* Set frame priority on socket. */
            if (setsockopt(TcpIpSocketId, SOL_SOCKET, SO_PRIORITY, &Value, sizeof(Value)) == SOAD_BSD_E_NOT_OK)
            {
                RetVal = E_NOT_OK;
            }
            break;
        case TCPIP_PARAMID_TCP_RXWND_MAX:
            SocketBufferMin = *((uint32*)ParameterValue);
            /* Set TCP rx buffer size. */
            if (SOAD_BSD_E_NOT_OK == setsockopt(TcpIpSocketId, SOL_SOCKET, SO_RCVBUF, 
                                                &SocketBufferMin, sizeof(SocketBufferMin)))
            {
                RetVal = E_NOT_OK;
            }
            break;
        case TCPIP_PARAMID_TCP_NAGLE:
            /* Set TCP no delay (Nagle algorithm). */
            Value = *((uint8*)ParameterValue);
            if (setsockopt(TcpIpSocketId, IPPROTO_TCP, TCP_NODELAY, &Value, sizeof(Value)) == SOAD_BSD_E_NOT_OK)
            {
                RetVal = E_NOT_OK;
            }
            break;
        case TCPIP_PARAMID_TCP_KEEPALIVE:
            Value = *((uint8*)ParameterValue);
            /* Set TCP keep alive. */
            if (setsockopt(TcpIpSocketId, SOL_SOCKET, SO_KEEPALIVE, &Value, sizeof(Value)) == SOAD_BSD_E_NOT_OK)
            {
                RetVal = E_NOT_OK;
            }
            break;
        case TCPIP_PARAMID_TCP_KEEPALIVE_TIME:
            Value = *((uint32*)ParameterValue);
            /* Set TCP keep alive time. */
            if (setsockopt(TcpIpSocketId, IPPROTO_TCP, TCP_KEEPIDLE, &Value, sizeof(Value)) == SOAD_BSD_E_NOT_OK)
            {
                RetVal = E_NOT_OK;
            }
            break;
        case TCPIP_PARAMID_TCP_KEEPALIVE_PROBES_MAX:
            Value = *((uint16*)ParameterValue);
            /* Set TCP keep alive maximum probes. */
            if (setsockopt(TcpIpSocketId, IPPROTO_TCP, TCP_KEEPCNT, &Value, sizeof(Value)) == SOAD_BSD_E_NOT_OK)
            {
                RetVal = E_NOT_OK;
            }
            break;
        case TCPIP_PARAMID_TCP_KEEPALIVE_INTERVAL:
            Value = *((uint32*)ParameterValue);
            /* Set TCP keep alive interval. */
            if (setsockopt(TcpIpSocketId, IPPROTO_TCP, TCP_KEEPINTVL, &Value, sizeof(Value)) == SOAD_BSD_E_NOT_OK)
            {
                RetVal = E_NOT_OK;
            }
            break;
        case SOAD_PARAMID_STACK_SPECIFIC:
            /* Set socket to non-blocking mode. */
            SockOptStatus = fcntl(TcpIpSocketId, F_GETFL, 0);
            if (SockOptStatus == SOAD_BSD_E_NOT_OK )
            {
                #ifdef DLOG
                Dlog_Print("!!Get socket option(fcntl) failed bsd Socket %d error %d",TcpIpSocketId,errno);
                #endif
                RetVal = E_NOT_OK;
            }
            else
            {
                if (fcntl(TcpIpSocketId, F_SETFL, SockOptStatus|O_NONBLOCK) == SOAD_BSD_E_NOT_OK)
                {
                    #ifdef DLOG
                    Dlog_Print("!!Set socket option(fcntl) O_NONBLOCK failed bsd Socket %d error %d",
                                TcpIpSocketId,errno);
                    #endif
                    RetVal = E_NOT_OK;
                }
            }
            /* Set reuse option for IP address to have the possibility to bind same address to 
            another local address. */
            SockOptStatus = (sint32)TRUE;
            if (SOAD_BSD_E_NOT_OK == setsockopt(TcpIpSocketId, SOL_SOCKET, SO_REUSEADDR,
                                                 &SockOptStatus, sizeof(SockOptStatus)))
            {
                #ifdef DLOG
                Dlog_Print("!!Set socket option(setsockopt) SO_REUSEADDR failed bsd Socket %d error %d",
                        TcpIpSocketId,errno);
                #endif
                RetVal = E_NOT_OK;
            }
            break;
        case SOAD_PARAMID_STACK_SPECIFIC_TCP:
            lingerConfig.l_onoff = 1;
            lingerConfig.l_linger = 0;
            if (SOAD_BSD_E_NOT_OK == setsockopt(TcpIpSocketId, SOL_SOCKET, SO_LINGER,
                                                 &lingerConfig, sizeof(lingerConfig)))
            {
                #ifdef DLOG
                Dlog_Print("!!Set socket option(setsockopt) SO_LINGER failed bsd Socket %d error %d",
                        TcpIpSocketId,errno);
                #endif
                RetVal = E_NOT_OK;
            }
            break;
        case SOAD_PARAMID_STACK_SPECIFIC_UDP:
            /* Set broadcast flag to have the possibility to send to broadcast addresses on UDP socket connections. */
            Value = TRUE;
            if ((SoAd_SocketBrdAddrCtrlGetDirectBrdAddrSockId(SocketId) != TcpIpSocketId) &&
                (SoAd_SocketBrdAddrCtrlGetLimitedBrdAddrSockId(SocketId) != TcpIpSocketId))
            {
                if (setsockopt(TcpIpSocketId, SOL_SOCKET, SO_BROADCAST, &Value, sizeof(Value)) == SOAD_BSD_E_NOT_OK )
                {
                    #ifdef DLOG
                    Dlog_Print("!!Set socket option(setsockopt) SO_BROADCAST failed bsd Socket %d error %d",
                        TcpIpSocketId,errno);
                    #endif
                    RetVal = E_NOT_OK;
                }
            }
            break;
        default:
            break;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used for hanlding the mulicast group join request of the the bsd TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdJoinMultiCastGroupV4
(
    SoAd_SocketIdxType SocketId,
    TcpIp_SocketIdType TcpIpSocketId
)
{
    Std_ReturnType RetVal;
    struct ip_mreqn mreq;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    SoAd_TcpIpCtrlIdxType TcpIpCtrlIdx;
    /* get LocalAddrId */
    SoConGrpIdx =  SoAd_SocketCfgGetSoConGrpIdx(SocketId);
    LocalAddrIdx = SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx);
    TcpIpCtrlIdx = SoAd_LocalAddrCfgGetTcpIpCtrlIdx(LocalAddrIdx);
    /* update muticast group config */
    mreq.imr_ifindex = SoAd_LocalAddrTcpIpCtrlGetIfNameToIndex(TcpIpCtrlIdx);
    // TODO: need to check if unicast ip addr should be mapped
    mreq.imr_address.s_addr = SoAd_LocalIpAddrCtrlGetIpv4Addr(LocalAddrIdx);
    mreq.imr_multiaddr.s_addr = SoAd_LocalIpAddrCtrlGetIpv4Addr(LocalAddrIdx); 
    /* Check if multicast group can be joined. */
    if (setsockopt(TcpIpSocketId, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) != SOAD_BSD_E_NOT_OK)
    {
        RetVal = E_OK;
    }
    else
    {
        #ifdef DLOG
        Dlog_Print("!!Set socket option(setsockopt) IP_ADD_MEMBERSHIP failed bsd Socket %d error %d",
                    TcpIpSocketId,errno);
        #endif
        RetVal = E_NOT_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to handle the Tcp connect of the the bsd TcpIp
********************************************************************************************************************/
Std_ReturnType SoAd_TcpIpBsdTcpConnect
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketId,
    P2CONST(SoAd_SockAddrType, AUTOMATIC, SOAD_APPL_VAR) RemAddrPtr
)
{
    size_t SockAddrLen;
    Std_ReturnType RetVal;
    struct sockaddr_in SockAddr;
    /* update remote address */
    SockAddrLen = sizeof(struct sockaddr_in);
    ((struct sockaddr_in*)&SockAddr)->sin_family = AF_INET;
    ((struct sockaddr_in*)&SockAddr)->sin_port = SoAd_UtilpAddrGetPort(RemAddrPtr);
    ((struct sockaddr_in*)&SockAddr)->sin_addr.s_addr = SoAd_UtilpAddrGetIpv4Addr(RemAddrPtr);
    /* Call Socket API. */
    (void)connect(TcpIpSocketId, (struct sockaddr *)&SockAddr, SockAddrLen);
    if (EINPROGRESS == errno)
    {
        /* set event to process in main function */
        SoAd_CtrlSetSocketStateEventStatus(SocketIdx,TRUE);
        RetVal = E_OK;
    }
    else
    {
        #ifdef DLOG
        Dlog_Print("!!Bsd connect failed bsd Socket %d error %d",TcpIpSocketId,errno);
        #endif
        RetVal = E_NOT_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to handle tcp listen of the the bsd TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdTcpListen
(
    SoAd_SocketIdxType ListenSocketIdx,
    TcpIp_SocketIdType TcpIpSocketIdx,
    uint16 MaxChannels
)
{
    Std_ReturnType RetVal;
    if (listen(TcpIpSocketIdx, MaxChannels) != SOAD_BSD_E_NOT_OK)
    {
        /* set event to process in main function */
        SoAd_CtrlSetSocketStateEventStatus(ListenSocketIdx,TRUE);
        RetVal = E_OK;
    }
    else
    {
        #ifdef DLOG
        Dlog_Print("!!Bsd listen failed bsd Socket %d error %d",ListenSocketIdx,errno);
        #endif
        RetVal = E_NOT_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to bind the socket of the bsd TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdBind
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketIdx,
    P2VAR(SoAd_PortType, AUTOMATIC, SOAD_APPL_VAR) PortPtr
)
{
    uint32 LocalIpAddr;
    uint32 DirAddr;
    struct sockaddr_in SockAddr;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    /* get local addr */
    SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(SocketIdx);
    LocalAddrIdx = SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx);
    LocalIpAddr = SoAd_LocalIpAddrCtrlGetIpv4Addr(LocalAddrIdx);
    /* update Ipv4 address */
    ((struct sockaddr_in*)&SockAddr)->sin_family = AF_INET;
    ((struct sockaddr_in*)&SockAddr)->sin_port = *PortPtr;
    ((struct sockaddr_in*)&SockAddr)->sin_addr.s_addr = LocalIpAddr; 
    /* Bind socket to local address */
    RetVal = SoAd_TcpIpBsdBindSocket(SocketIdx, TcpIpSocketIdx,(struct sockaddr *)&SockAddr,sizeof(SockAddr),PortPtr);
    /* update port */
    ((struct sockaddr_in*)&SockAddr)->sin_port = *PortPtr;
    if(SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE)
    {
        if(SoAd_LocalAddrCfgGetAddressType(LocalAddrIdx) == SOAD_ADDRESS_TYPE_UNICAST)
        {
            /* Bind separate socket to receive from directed broadcast address. 
            for 192.168.1.1/24 -> directed broadcast is 192.168.1.255 */
            DirAddr = (LocalIpAddr | (SOAD_BSD_INADDR_BROADCAST << SoAd_LocalIpAddrCtrlGetNetMask(LocalAddrIdx)));
            ((struct sockaddr_in*)&SockAddr)->sin_addr.s_addr = DirAddr;
            RetVal |= SoAd_TcpIpBsdBindSocket(SocketIdx,SoAd_SocketBrdAddrCtrlGetDirectBrdAddrSockId(SocketIdx),
                                                    (struct sockaddr *)&SockAddr, sizeof(SockAddr), PortPtr);        
            /* Bind separate socket to receive from limited broadcast/node-local address is 255.255.255.255*/
            ((struct sockaddr_in*)&SockAddr)->sin_addr.s_addr = SOAD_BSD_INADDR_BROADCAST;
            RetVal |= SoAd_TcpIpBsdBindSocket(SocketIdx,SoAd_SocketBrdAddrCtrlGetLimitedBrdAddrSockId(SocketIdx),
                                                    (struct sockaddr *)&SockAddr, sizeof(SockAddr), PortPtr);
        }
    }
    /* Add event to handle UDP socket in main function if all calls to BSD-like Socket API succeeded. */
    if ((RetVal == E_OK) && SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE)
    {
        SoAd_CtrlSetSocketStateEventStatus(SocketIdx,TRUE);
    }   
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to get the socket of the bsd TcpIp
********************************************************************************************************************/
FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdGetSocket
(
    SoAd_SocketIdxType SocketId,
    SoAd_DomainType Domain,
    SoAd_ProtocolType Protocol,
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    P2VAR(TcpIp_SocketIdType, AUTOMATIC, SOAD_APPL_DATA) SocketIdPtr
)
{
    sint32 SockType;
    TcpIp_SocketIdType TcpIpSocketIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    TcpIp_SocketIdType DirectBrdAddrSocketId;
    TcpIp_SocketIdType LimitedBrdAddrSocketId;
    /* Convert protocol for BSD-like Socket API. */
    if ( Protocol == SOAD_IPPROTO_TCP )
    {
        SockType = SOCK_STREAM;
    }
    else
    {
        SockType = SOCK_DGRAM;
    }
    /* Get socket from BSD-like Socket API. */
    TcpIpSocketIdx = socket(AF_INET, SockType, 0);
    /* Check if socket is UDP and of type unicast. */
    if ((Protocol == SOAD_IPPROTO_UDP) && (SoAd_LocalAddrCfgGetAddressType(LocalAddrIdx) == SOAD_ADDRESS_TYPE_UNICAST))
    {
        /* Get separate socket to receive from directed broadcast/link-local address. */
        DirectBrdAddrSocketId = socket(AF_INET, SockType, 0);
        /* Get separate socket to receive from limited broadcast/node-local address. */
        LimitedBrdAddrSocketId = socket(AF_INET, SockType, 0);
    }
    else
    {
        DirectBrdAddrSocketId = TcpIpSocketIdx;
        LimitedBrdAddrSocketId = TcpIpSocketIdx;
    }
    /* Handle errors. */
    if ((TcpIpSocketIdx == SOAD_SOCKET_ID_INVALID) ||
        (DirectBrdAddrSocketId == SOAD_SOCKET_ID_INVALID) ||
        (LimitedBrdAddrSocketId == SOAD_SOCKET_ID_INVALID))
    {
        if (TcpIpSocketIdx != SOAD_SOCKET_ID_INVALID)
        {
            (void)close(TcpIpSocketIdx);
        }
        if (DirectBrdAddrSocketId != SOAD_SOCKET_ID_INVALID)
        {
            (void)close(DirectBrdAddrSocketId);
        }
        if (LimitedBrdAddrSocketId != SOAD_SOCKET_ID_INVALID)
        {
            (void)close(LimitedBrdAddrSocketId);
        }
    }
    else
    {
        /* update the bsd socket id */
        *SocketIdPtr = TcpIpSocketIdx;
        SoAd_SocketBrdAddrCtrlSetDirectBrdAddrSockId(SocketId,DirectBrdAddrSocketId);
        SoAd_SocketBrdAddrCtrlSetLimitedBrdAddrSockId(SocketId,LimitedBrdAddrSocketId);
        RetVal = E_OK;
    }
    SOAD_DUMMY_STATEMENT(Domain);
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used close the socket of the bsd TcpIp
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpBsdClose(SoAd_SocketIdxType SocketIdx,TcpIp_SocketIdType TcpIpSocketIdx,boolean Abort)
{
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    SoAd_SocketTcpRxBufferCtrlIdxType TcpRxBufferCtrlIdx;
    /* get local addr id */
    SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(SocketIdx);
    LocalAddrIdx = SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx);
    /* close sockets */
    (void)close(TcpIpSocketIdx);
    if (SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE)
    {
        if(SoAd_LocalAddrCfgGetAddressType(LocalAddrIdx) == SOAD_ADDRESS_TYPE_UNICAST)
        {
            /* close direct socket */
            (void)close(SoAd_SocketBrdAddrCtrlGetDirectBrdAddrSockId(SocketIdx));
            SoAd_SocketBrdAddrCtrlSetDirectBrdAddrSockId(SocketIdx,SOAD_SOCKET_ID_INVALID);
            /* close limited socket */
            (void)close(SoAd_SocketBrdAddrCtrlGetLimitedBrdAddrSockId(SocketIdx));
            SoAd_SocketBrdAddrCtrlSetLimitedBrdAddrSockId(SocketIdx,SOAD_SOCKET_ID_INVALID);
        }
    }
    /* Release socket buffer. */
    SoAd_TcpIpBsd_ReleaseSocketTxBufferForSocket(SocketIdx);
    if(SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE)
    {
        /* notify udp closed */
        SoAd_TcpIpEvent(TcpIpSocketIdx, SOAD_UDP_CLOSED);
    }
    else
    {
        /* notify tcp closed */
        if (SoAd_SocketCfgGetTcpRxBufferEnable(SocketIdx) == TRUE)
        {
            TcpRxBufferCtrlIdx = SoAd_SocketCfgGetTcpRxBufferCtrlIdx(SocketIdx);
            SoAd_SocketTcpRxBufferCtrlSetLength(TcpRxBufferCtrlIdx,0u);
            SoAd_SocketTcpRxBufferCtrlSetTcpRxBufferIdx(TcpRxBufferCtrlIdx,
                                                        SoAd_TcpIpBsdCfgGetTcpRxBufferStartIdx(TcpRxBufferCtrlIdx));
        }
        SoAd_TcpIpEvent(TcpIpSocketIdx, SOAD_TCP_CLOSED);
    }
    SOAD_DUMMY_STATEMENT(Abort);
}
/********************************************************************************************************************
* @brief The Api is used idicate that the SoAd has received and processed the message
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpBsdTcpReceived(SoAd_SocketIdxType SocketIdx,uint32 Length)
{
    SoAd_SocketTcpRxBufferCtrlIdxType TcpRxBufferCtrlIdx;
    SoAd_SocketTcpRxBufferSizeType ReleaseBufferIdx;
    /* get rx buffer*/
    TcpRxBufferCtrlIdx = SoAd_SocketCfgGetTcpRxBufferCtrlIdx(SocketIdx);
    ReleaseBufferIdx = SoAd_SocketTcpRxBufferCtrlGetTcpRxBufferIdx(TcpRxBufferCtrlIdx)-
                            SoAd_TcpIpBsdCfgGetTxBufferStartIdx(TcpRxBufferCtrlIdx);
    /* handle buffer wrap around */
    if ((ReleaseBufferIdx+Length) > SoAd_TcpIpBsdCfgGetTxBufferSize(TcpRxBufferCtrlIdx))
    {
        SoAd_SocketTcpRxBufferCtrlSetTcpRxBufferIdx(TcpRxBufferCtrlIdx,
            (SoAd_SocketTcpRxBufferCtrlGetTcpRxBufferIdx(TcpRxBufferCtrlIdx)-
            (SoAd_TcpIpBsdCfgGetTxBufferSize(TcpRxBufferCtrlIdx)-Length)));
            
    }
    else
    {
        SoAd_SocketTcpRxBufferCtrlSetTcpRxBufferIdx(TcpRxBufferCtrlIdx,
            (SoAd_SocketTcpRxBufferCtrlGetTcpRxBufferIdx(TcpRxBufferCtrlIdx)+Length));    
    }
    /* update length */
    if (SoAd_SocketTcpRxBufferCtrlGetLength(TcpRxBufferCtrlIdx) > Length)
    {
        SoAd_SocketTcpRxBufferCtrlSetLength(TcpRxBufferCtrlIdx,
                                        (SoAd_SocketTcpRxBufferCtrlGetLength(TcpRxBufferCtrlIdx)-Length));
    }
    else
    {
        SoAd_SocketTcpRxBufferCtrlSetLength(TcpRxBufferCtrlIdx,0u);
    }
}
/********************************************************************************************************************
* @brief The Api is process the state of bsd TcpIp. This should be called from SoAd mainfuction
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpBsdMainFunctionState(void)
{
    /* Handle local IP address availability */
    SoAd_TcpIpBsdLocalAddressCheckHandler();
    /* Handle IP addres states */
    SoAd_TcpIpBsdIpAddrStateHandler();
    /* Handle TCP socket states */
    SoAd_TcpIpBsdTcpSocketStatesHandler();
} 
/********************************************************************************************************************
* @brief The Api is process the transmission of bsd TcpIp. This should be called from SoAd mainfuction
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpBsdMainFunctionTx(void)
{
    uint16 TotalLength;
    SoAd_SocketIdxType SocketIdx;
    for(SocketIdx=0u; SocketIdx < SOAD_NUM_OF_SOCKET; SocketIdx++)
    {
        if (SoAd_CtrlGetSocketTcpTxEventStatus(SocketIdx) == TRUE)
        {
            /* Handle pending TCP Tx Confirmation on socket connection. */
            TotalLength = SoAd_TxTcpGetUnconfirmedDataLength(SocketIdx);
            if (TotalLength > 0u)
            {
                SoAd_TxConfirmation(SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx),(uint16)TotalLength);
                SoAd_CtrlSetSocketTcpTxEventStatus(SocketIdx,FALSE);
            }
        }
    }
    /* Handle socket transmission buffers. */
    SoAd_TcpIpBsdSocketTxBufferHandler();
}
/********************************************************************************************************************
* @brief The Api is process the reception of bsd TcpIp. This should be called from SoAd mainfuction
********************************************************************************************************************/
FUNC(void, SOAD_CODE) SoAd_TcpIpBsdMainFunctionRx(void)
{
    /* handle socket reception */
    SoAd_TcpIpBsdSocketReceptionHandler();
}
/********************************************************************************************************************
*  #! PRIVATE FUNCTION IMPLEMENTATION                                                                               *
********************************************************************************************************************/
/********************************************************************************************************************
* @brief The Api is used to reset the Ip addr configuration to the default values.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsdResetLocalIpAddr(SoAd_LocalIpAddrIdxType LocalAddrIdx)
{
    const char * pTcpIpCtrlNameBuffer;
    SoAd_TcpIpCtrlIdxType TcpIpCtrlIdx;
    SoAd_RemAddrIpV4IdxType RemAddrIpV4Idx;
    /* get local addr id*/
    RemAddrIpV4Idx = SoAd_LocalAddrCfgGetRemAddrIpV4Idx(LocalAddrIdx);
    if (SOAD_IPADDR_ASSIGNMENT_STATIC == SoAd_LocalAddrCfgGetAssignTypeOfLocalAddr(LocalAddrIdx))
    {
        /* Get Ipv4 address and netmask */
        SoAd_LocalIpAddrCtrlSetNetMask(LocalAddrIdx,SoAd_SocketCfgGetRemAddrNetMask(RemAddrIpV4Idx));
        SoAd_LocalIpAddrCtrlSetIpv4Addr(LocalAddrIdx,SoAd_SocketCfgGetRemAddrIpv4(RemAddrIpV4Idx));
    }
    else
    {
        /* Get Ipv4 address and netmask */
        SoAd_LocalIpAddrCtrlSetNetMask(LocalAddrIdx,0U);
        SoAd_LocalIpAddrCtrlSetIpv4Addr(LocalAddrIdx,SOAD_IPADDR_ANY);
    }
    /* set the interface to index */
    TcpIpCtrlIdx = SoAd_LocalAddrCfgGetTcpIpCtrlIdx(LocalAddrIdx);
    pTcpIpCtrlNameBuffer = &SoAd_TcpIpBsdCfgGetpTcpIpCtrlNameBuffer(
                                                    SoAd_TcpIpBsdCfgGetCtrlNameBufferStartIdx(TcpIpCtrlIdx));
    SoAd_LocalAddrTcpIpCtrlSetIfNameToIndex(TcpIpCtrlIdx,if_nametoindex(pTcpIpCtrlNameBuffer));
}
/********************************************************************************************************************
* @brief The Api handles the Ip addr state changes.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsdIpAddrStateHandler(void)
{
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    SoAd_IpAddrStateType IpAddrState;
    for(LocalAddrIdx=0u;LocalAddrIdx < SoAd_CfgGetNumOfLocalIpAddr();LocalAddrIdx++)
    {
        if (SoAd_LocalIpAddrCtrlGetLocalAddrEventStatus(LocalAddrIdx) == TRUE)
        {
            SoAd_EnterCriticalSection();
            SoAd_LocalIpAddrCtrlSetLocalAddrEventStatus(LocalAddrIdx,FALSE);
            if (SoAd_CtrlGetIpAddrState(LocalAddrIdx) != SOAD_IPADDR_STATE_ASSIGNED)
            {
                IpAddrState = SoAd_TcpIpBsdIpAddrStateUnassignedHandler(LocalAddrIdx);
            }
            else
            {
                IpAddrState = SoAd_TcpIpBsdIpAddrStateAssignedHandler(LocalAddrIdx);
            }
            SoAd_ExitCriticalSection();
            /* Check if local address assignment has changed. */
            if (IpAddrState != SOAD_IPADDR_STATE_ONHOLD)
            {
                /* Notify about local IP address assignment state change. */
                SoAd_LocalIpAddrAssignmentChg(LocalAddrIdx, IpAddrState);
            }
            /* monitor link status */
            SoAd_TcpIpBsdCheckLinkStatus(LocalAddrIdx);
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to check the availability and link status of the local ip addr.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsdLocalAddressCheckHandler(void)
{
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    /* process addr check counter */
    if (SoAd_TcpIpBsdLocalAddrCheckCounter > 0u)
    {
        SoAd_TcpIpBsdLocalAddrCheckCounter--;
        if (SoAd_TcpIpBsdLocalAddrCheckCounter == 0U)
        {
            for(LocalAddrIdx=0u;LocalAddrIdx < SoAd_CfgGetNumOfLocalIpAddr();LocalAddrIdx++)
            {
                if((SoAd_LocalAddrCfgGetAddressType(LocalAddrIdx) == SOAD_ADDRESS_TYPE_UNICAST) &&
                   (SoAd_CtrlGetIpAddrState(LocalAddrIdx) == SOAD_IPADDR_STATE_ASSIGNED))
                {
                    SoAd_LocalIpAddrCtrlSetCheckAvailability(LocalAddrIdx,TRUE);  
                }
            }
            SoAd_TcpIpBsdLocalAddrCheckCounter = SoAd_CfgGetLocalAddrCheckCount();
        }
    }
}
/********************************************************************************************************************
* @brief The Api is handls the unassigned Ip address state
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(SoAd_IpAddrStateType, SOAD_CODE) SoAd_TcpIpBsdIpAddrStateUnassignedHandler
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx
)
{
    SoAd_IpAddrStateType IpAddrState = SOAD_IPADDR_STATE_ONHOLD;
    if ((SoAd_LocalAddrCfgGetAssignTriggerType(LocalAddrIdx) == SOAD_ASSIGN_TRIGGER_AUTOMATIC) ||
        (SoAd_LocalIpAddrCtrlGetIpAddrReqState(LocalAddrIdx) == SOAD_LOCAL_IP_ADDR_REQ_STATE_REQUEST))
    {
        /* Try to assign the local IP address. */
        if (E_OK == SoAd_TcpIpBsdAssignIpAddr(LocalAddrIdx))
        {
            /* Mark IP address as assigned and reset request state if local IP address could be assigned. */
            IpAddrState = SOAD_IPADDR_STATE_ASSIGNED;
            SoAd_LocalIpAddrCtrlSetIpAddrReqState(LocalAddrIdx, SOAD_LOCAL_IP_ADDR_REQ_STATE_NONE);
        }
        SoAd_LocalIpAddrCtrlSetLocalAddrEventStatus(LocalAddrIdx,TRUE);
    }
    return IpAddrState;
}
/********************************************************************************************************************
* @brief The Api is handls the assigned Ip address state
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(SoAd_IpAddrStateType, SOAD_CODE) SoAd_TcpIpBsdIpAddrStateAssignedHandler
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx
)
{
    SoAd_IpAddrStateType IpAddrState = SOAD_IPADDR_STATE_ONHOLD;
    /* process ip addr state */
    if (SoAd_LocalIpAddrCtrlGetIpAddrReqState(LocalAddrIdx) == SOAD_LOCAL_IP_ADDR_REQ_STATE_RELEASE)
    {
        /* Release local IP address and close corresponding sockets. */
        SoAd_TcpIpBsdReleaseIpAddr(LocalAddrIdx);
        /* set IP address as unassigned and reset request state. */
        IpAddrState = SOAD_IPADDR_STATE_UNASSIGNED;
        SoAd_LocalIpAddrCtrlSetIpAddrReqState(LocalAddrIdx,SOAD_LOCAL_IP_ADDR_REQ_STATE_NONE);
        /* set event if local IP address is triggered automatically to reassign it later. */
        if (SoAd_LocalAddrCfgGetAssignTriggerType(LocalAddrIdx) == SOAD_ASSIGN_TRIGGER_AUTOMATIC)
        {
            SoAd_LocalIpAddrCtrlSetLocalAddrEventStatus(LocalAddrIdx,TRUE);
        }
        SoAd_LocalIpAddrCtrlSetCheckAvailability(LocalAddrIdx,FALSE);
    }
    else if (SoAd_LocalIpAddrCtrlGetCheckAvailability(LocalAddrIdx) == TRUE)
    {
        /* Check if local IP address shall be checked for availability. */
        if (SoAd_TcpIpBsdCheckAndOverwriteLocalAddr(LocalAddrIdx, FALSE) == E_NOT_OK )
        {
            /* Release local IP address and close corresponding sockets. */
            SoAd_TcpIpBsdReleaseIpAddr(LocalAddrIdx);
            /* set IP address as unassigned and reset request state. */
            IpAddrState = SOAD_IPADDR_STATE_UNASSIGNED;
            SoAd_LocalIpAddrCtrlSetIpAddrReqState(LocalAddrIdx,SOAD_LOCAL_IP_ADDR_REQ_STATE_REQUEST);
        }
        SoAd_LocalIpAddrCtrlSetLocalAddrEventStatus(LocalAddrIdx,TRUE);
        SoAd_LocalIpAddrCtrlSetCheckAvailability(LocalAddrIdx,FALSE);
    }
    else
    {
        /* set event to check for availability later */
        SoAd_LocalIpAddrCtrlSetLocalAddrEventStatus(LocalAddrIdx,TRUE);
    }
    return IpAddrState;
}
/********************************************************************************************************************
* @brief The Api is used to assign the local ip address
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdAssignIpAddr(SoAd_LocalIpAddrIdxType LocalAddrIdx)
{
    Std_ReturnType RetVal = E_NOT_OK;
    /* assign ip address */
    if (SoAd_LocalAddrCfgGetAddressType(LocalAddrIdx) == SOAD_ADDRESS_TYPE_UNICAST)
    {
        if (SoAd_LocalAddrCfgGetAssignTypeOfLocalAddr(LocalAddrIdx) == SOAD_IPADDR_ASSIGNMENT_STATIC)
        {
            RetVal = SoAd_TcpIpBsdCheckAndOverwriteLocalAddr(LocalAddrIdx, FALSE);
        }
        else
        {
            RetVal = SoAd_TcpIpBsdCheckAndOverwriteLocalAddr(LocalAddrIdx, TRUE);
        }
    }
    else
    {
        RetVal = E_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to check if ip address is assigned and overwrite the existing local address if requested 
*   by OverwriteLocal flag
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdCheckAndOverwriteLocalAddr
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    boolean OverwriteLocal
)
{
    uint32 IfIndex;
    uint32 NetmaskAddr;
    uint8  NetMaskBit;
    struct ifaddrs * IfAddr;
    struct ifaddrs * IfAddrList;
    SoAd_IpAddrInetType LocalIpAddr;
    SoAd_IpAddrInetType BsdIpAddr;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_TcpIpCtrlIdxType TcpIpCtrlIdx;
    /* Get all local addresses via BSD-like Socket API. */
    if (getifaddrs(&IfAddrList) == SOAD_BSD_NO_ERROR )
    {
        /* Iterate over all local addresses. */
        for (IfAddr = IfAddrList; IfAddr != NULL; IfAddr = IfAddr->ifa_next )
        {
            /* Check if local address interface and address family matches the configured local IP address. */
            IfIndex = if_nametoindex(IfAddr->ifa_name);
            TcpIpCtrlIdx = SoAd_LocalAddrCfgGetTcpIpCtrlIdx(LocalAddrIdx);
            if (IfIndex == SoAd_LocalAddrTcpIpCtrlGetIfNameToIndex(TcpIpCtrlIdx))
            {
                if ( IfAddr->ifa_addr != NULL )
                {
                    if (AF_INET == IfAddr->ifa_addr->sa_family)
                    {
                        /* Overwrite local IP address with first suitable local address on interface if required. */
                        if ( TRUE == OverwriteLocal )
                        {
                            /* Overwrite local IPv4 address otherwise. */
                            NetmaskAddr = (((struct sockaddr_in*)IfAddr->ifa_netmask)->sin_addr.s_addr);
                            LocalIpAddr = (uint32)((struct sockaddr_in*)IfAddr->ifa_addr)->sin_addr.s_addr;
                            SoAd_LocalIpAddrCtrlSetIpv4Addr(LocalAddrIdx,LocalIpAddr);
                            SoAd_LocalIpAddrCtrlSetNetMask(LocalAddrIdx,0u);
                            /* CIDR conversion */
                            for (NetMaskBit = 0u;NetMaskBit< 32u;NetMaskBit++ )
                            {
                                if (((uint32)(NetmaskAddr << NetMaskBit)) == 0u )
                                {
                                    SoAd_LocalIpAddrCtrlSetNetMask(LocalAddrIdx,NetMaskBit);
                                    break;
                                }
                            }
                            RetVal = E_OK;
                            break;
                        }
                        else
                        {
                            /* Check if local address matches the configured local IP address otherwise. */
                            LocalIpAddr = SoAd_LocalIpAddrCtrlGetIpv4Addr(LocalAddrIdx);
                            BsdIpAddr = *((uint32*)&((struct sockaddr_in*)IfAddr->ifa_addr)->sin_addr.s_addr);
                            /* Check local IPv4 address otherwise. */
                            if (LocalIpAddr == BsdIpAddr)
                            {
                                RetVal = E_OK;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (RetVal == E_OK)
        {
            /* check for link status */
            int sockfd;
            struct ifreq ifr;
            memset(&ifr, 0, sizeof(struct ifreq));
            strncpy(ifr.ifr_name, IfAddr->ifa_name, IFNAMSIZ - 1);
            sockfd = socket(AF_INET, SOCK_DGRAM, 0);
            RetVal = E_NOT_OK; 
            if ((sockfd != -1) && (ioctl(sockfd, SIOCGIFFLAGS, &ifr) != -1))
            {
                if ((ifr.ifr_flags & IFF_UP) != 0)
                {
                    RetVal = E_OK;
                }
            }
            close(sockfd);
        }
        /* Free occupied buffer of BSD-like Socket API used to get all local addresses. */
        freeifaddrs(IfAddrList);
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to release the assigned IP address
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsdReleaseIpAddr(SoAd_LocalIpAddrIdxType LocalAddrIdx)
{
    SoAd_SocketIdxType SocketId;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    for (SocketId = 0u; SocketId < SOAD_NUM_OF_SOCKET; SocketId++)
    {
        SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(SocketId);
        if ((SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx) == LocalAddrIdx) &&
            (SoAd_SocketCtrlGetTcpIpSocketId(SocketId) != SOAD_SOCKET_ID_INVALID))
        {
            SoAd_TcpIpBsdClose(SocketId, SoAd_SocketCtrlGetTcpIpSocketId(SocketId),TRUE);
        }
    }
    /* Reset local IP address struct. */
    SoAd_TcpIpBsdResetLocalIpAddr(LocalAddrIdx);
}
/********************************************************************************************************************
* @brief The Api is used to check the link status of the local ip address
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsdCheckLinkStatus(SoAd_LocalIpAddrIdxType LocalAddrIdx)
{
    uint32 IfIndex;
    struct ifaddrs * IfAddr;
    struct ifaddrs * IfAddrList;
    SoAd_IpAddrInetType LocalIpAddr;
    SoAd_IpAddrInetType BsdIpAddr;
    SoAd_TcpIpCtrlIdxType TcpIpCtrlIdx;
    /* Get all local addresses via BSD-like Socket API. */
    if (getifaddrs(&IfAddrList) == SOAD_BSD_NO_ERROR )
    {
        /* Iterate over all local addresses. */
        for (IfAddr = IfAddrList; IfAddr != NULL; IfAddr = IfAddr->ifa_next )
        {
            /* Check if local address interface and address family matches the configured local IP address. */
            IfIndex = if_nametoindex(IfAddr->ifa_name);
            TcpIpCtrlIdx = SoAd_LocalAddrCfgGetTcpIpCtrlIdx(LocalAddrIdx);
            if (IfIndex == SoAd_LocalAddrTcpIpCtrlGetIfNameToIndex(TcpIpCtrlIdx))
            {
                if (IfAddr->ifa_addr != NULL)
                {
                    if (AF_INET == IfAddr->ifa_addr->sa_family)
                    {
                        /* Check if local address matches the configured local IP address otherwise. */
                        LocalIpAddr = SoAd_LocalIpAddrCtrlGetIpv4Addr(LocalAddrIdx);
                        BsdIpAddr = *((uint32*)&((struct sockaddr_in*)IfAddr->ifa_addr)->sin_addr.s_addr);
                        /* Check local IPv4 address otherwise. */
                        if (LocalIpAddr == BsdIpAddr)
                        {
                            int sockfd;
                            struct ifreq ifr;
                            memset(&ifr, 0, sizeof(struct ifreq));
                            strncpy(ifr.ifr_name, IfAddr->ifa_name, IFNAMSIZ - 1);
                            sockfd = socket(AF_INET, SOCK_DGRAM, 0);
                            if ((sockfd != -1) &&
                                (ioctl(sockfd, SIOCGIFFLAGS, &ifr) != -1))
                            {
                                if ((SoAd_CtrlGetIpAddrState(LocalAddrIdx) == SOAD_IPADDR_STATE_ASSIGNED) &&
                                ((ifr.ifr_flags & IFF_UP) == 0))
                                {
                                    /* notify about link down. */
                                    SoAd_LocalIpAddrAssignmentChg(LocalAddrIdx, SOAD_IPADDR_STATE_ONHOLD);
                                }
                                else if ((SoAd_CtrlGetIpAddrState(LocalAddrIdx) == SOAD_IPADDR_STATE_ONHOLD) &&
                                        ((ifr.ifr_flags & IFF_UP)!= 0))
                                {
                                    if (SoAd_LocalIpAddrCtrlGetIpAddrReqState(LocalAddrIdx) == 
                                                                        SOAD_LOCAL_IP_ADDR_REQ_STATE_RELEASE)
                                    {
                                        /* notify about link up. */
                                        SoAd_LocalIpAddrAssignmentChg(LocalAddrIdx, SOAD_IPADDR_STATE_ASSIGNED);
                                    }
                                }
                                else
                                {
                                    /* Do Nothing */
                                }
                            }
                            close(sockfd);
                            break;
                        } /*  (LocalIpAddr == BsdIpAddr) */
                    } /* (AF_INET == IfAddr->ifa_addr->sa_family) */
                } /* (IfAddr->ifa_addr != NULL) */
            } /* if (IfIndex == SoAd_LocalAddrTcpIpCtrlGetTcpIpCtrlIdx(LocalAddrIdx)) */
        } /* for all IfAddrList*/
        /* Free occupied buffer of BSD-like Socket API used to get all local addresses. */
        freeifaddrs(IfAddrList);
    }
}
/********************************************************************************************************************
* @brief The Api is used to handle the Tcp socket states.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsdTcpSocketStatesHandler(void)
{
    boolean ProcessEventAgain;
    SoAd_SocketIdxType SocketIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    /* process socket states */
    for(SocketIdx=0u;SocketIdx < SOAD_NUM_OF_SOCKET; SocketIdx++)
    {
        ProcessEventAgain = FALSE;
        SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(SocketIdx);
        if (SoAd_CtrlGetSocketStateEventStatus(SocketIdx) == TRUE)
        {
            if(SoAd_SoConGrpCfgIsProtoTcpSupported(SoConGrpIdx) == TRUE)
            {
                if (SoAd_SoConGrpCfgIsProtoTcpInitiateEnabled(SoConGrpIdx) == TRUE)
                {
                    if (SoAd_SocketCtrlGetSocketState(SocketIdx) == SOAD_SOCK_STATE_CONNECT)
                    {
                        if (SoAd_TcpIpBsdTcpCheckConnect(SocketIdx) == TRUE )
                        {
                            /* set event if connection is not yet established or to start reception. */
                            ProcessEventAgain = TRUE;
                        }
                    }
                    else
                    {
                        /*set event if connection is not yet established or to start reception. */
                        ProcessEventAgain = TRUE;
                    }
                }
                else
                {
                    /* Handle TCP server sockets. */
                    if (SoAd_SoConGrpCfgGetSoConGrpSocketIdx(SoConGrpIdx) == SocketIdx)
                    {
                        if (SoAd_SocketCtrlGetSocketState(SocketIdx) == SOAD_SOCK_STATE_LISTEN)
                        {
                            /* Check if any new connection has been established. */
                            if (SoAd_TcpIpBsdTcpCheckAccept(SocketIdx) == TRUE )
                            {
                                /* set event if no socket error occurred. */
                                ProcessEventAgain = TRUE;
                            }
                        }
                    }
                    else
                    {
                        /* set event if no socket error occurred. */
                        ProcessEventAgain = TRUE;
                    }
                }
            }
            else
            {
                /* set event to process again. */
                ProcessEventAgain = TRUE;
            }
            SoAd_CtrlSetSocketStateEventStatus(SocketIdx,ProcessEventAgain);
        }
    } 
}
/********************************************************************************************************************
* @brief The Api is used to poll for the tcp connection check
********************************************************************************************************************/
SOAD_LOCAL FUNC(boolean, SOAD_CODE) SoAd_TcpIpBsdTcpCheckConnect(SoAd_SocketIdxType SocketIdx)
{
    fd_set SocketFd;
    int ErrorSelect; 
    boolean Retry = FALSE;
    struct timeval Timeout;
    socklen_t ErrorGetSockOptLength;
    TcpIp_SocketIdType TcpIpSocketId;
    int ErrorGetSockOpt = SOAD_BSD_E_NOT_OK; 
    /* get bsd socket id */
    TcpIpSocketId = SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx);
    ErrorGetSockOptLength = sizeof(ErrorGetSockOpt);
    /* init fd */
    FD_ZERO(&SocketFd);
    FD_SET(TcpIpSocketId, &SocketFd);
    Timeout.tv_sec = 0;
    Timeout.tv_usec = 0;
    if (TcpIpSocketId >= FD_SETSIZE)
    {
        SoAd_TcpIpBsdClose(SocketIdx,TcpIpSocketId,TRUE);
    }
    else
    {
        /* Invoke select BSD API for polling to check if the connection state changed. */
        ErrorSelect = select(TcpIpSocketId + 1, 0, &SocketFd, 0, &Timeout);
        if (ErrorSelect == SOAD_BSD_E_NOT_OK)
        {
            /* set retry to process again in main function. */
            Retry = TRUE;
            /* Close socket. */
            SoAd_TcpIpBsdClose(SocketIdx,TcpIpSocketId, TRUE);
        }
        else if ( ErrorSelect == SOAD_BSD_FD_NO_CHANGE )
        {
            /* set retry to process again in main function. */
            Retry = TRUE;
        }
        /*  Try to check the state via BSD Socket API getsockopt otherwise. */
        else if (SOAD_BSD_E_NOT_OK != getsockopt(TcpIpSocketId, SOL_SOCKET, SO_ERROR, 
                                                &ErrorGetSockOpt, &ErrorGetSockOptLength))
        {
            /* Check if TCP connection is established. */
            if (ErrorGetSockOpt == SOAD_BSD_TCP_CONNECTED )
            {
                /* Notify that TCP connection is established. */
                SoAd_TcpConnected(TcpIpSocketId);
                /* set retry to start reception in main function. */
                Retry = TRUE;
            }
            else
            {
                /* Close socket. */
                SoAd_TcpIpBsdClose(SocketIdx,TcpIpSocketId, TRUE);
            }
        }
        else
        {
            /* Close socket. */
            SoAd_TcpIpBsdClose(SocketIdx,TcpIpSocketId, TRUE);
        }
    }
    return Retry;
} 
/********************************************************************************************************************
* @brief The Api is used to poll for the tcp accpet check
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(boolean, SOAD_CODE) SoAd_TcpIpBsdTcpCheckAccept(SoAd_SocketIdxType SocketIdx)
{
    int SocketIdConnected;
    boolean Retry = FALSE;
    socklen_t SockAddrLen;
    SoAd_SoConIdType SoConIdx;
    struct sockaddr_in SockAddr;
    SoAd_SockAddrType RemSockAddr;
    TcpIp_SocketIdType TcpIpSocketIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    /* get bsd socket idx */
    TcpIpSocketIdx = SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx);
    SockAddrLen = sizeof(SockAddr);
    ((struct sockaddr_in *)&SockAddr)->sin_family = AF_INET;
    /* Call accept Socket API. */
    SocketIdConnected = accept(TcpIpSocketIdx,((struct sockaddr *)&SockAddr),&SockAddrLen);
    if (SocketIdConnected != SOAD_BSD_E_NOT_OK)
    {
        /* update remote address */
        SoAd_UtilAddrSetIpv4Addr(RemSockAddr,AF_INET);
        SoAd_UtilAddrSetIpv4Addr(RemSockAddr,((struct sockaddr_in*)&SockAddr)->sin_addr.s_addr);
        SoAd_UtilAddrSetPort(RemSockAddr,((struct sockaddr_in*)&SockAddr)->sin_port);
        /* Change parameters on newly connected socket. */
        SoAd_SocketTcpChangeParameter(SocketIdx, SocketIdConnected);
        /* Notify about newly connected socket if parameters could be changed. */
        if (SoAd_TcpAccepted(TcpIpSocketIdx,SocketIdConnected,&RemSockAddr) == E_OK )
        {
            /* Set event to handle socket reception in main function. */
            for(SoConIdx = SoAd_SocketCfgGetSoConStartIdx(SocketIdx);
                SoConIdx <= SoAd_SocketCfgGetSoConEndIdx(SocketIdx); SoConIdx++)
            {
                if (SoAd_SocketCtrlGetTcpIpSocketId(SoAd_SoConCfgGetSocketIdx(SoConIdx)) == SocketIdConnected)
                {
                    SoAd_CtrlSetSocketStateEventStatus(SoAd_SoConCfgGetSocketIdx(SoConIdx),TRUE);
                    break;
                }
            }
            RetVal = E_OK;
        }
        if(RetVal == E_NOT_OK)
        {
            /* Close socket if parameters could not be changed or newly connected socket is not accepted. */
            SoAd_TcpIpBsdClose(SocketIdx,TcpIpSocketIdx, TRUE);
        }
        /* set retry since listen socket is still active. */
        Retry = TRUE;
    }
    else
    {
        /* set retry if no new socket is available since listen socket is still active. */
        if ((errno == EAGAIN) || (errno == EWOULDBLOCK))
        {
            Retry = TRUE;
        }
        else
        {
            SoAd_TcpIpBsdClose(SocketIdx,TcpIpSocketIdx, TRUE);
        }
    }
    return Retry;
}
/********************************************************************************************************************
* @brief The Api is used to bind the socket to the requested ip and port
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdBindSocket
(
    SoAd_SocketIdxType SocketIdx,
    TcpIp_SocketIdType TcpIpSocketIdx,
    P2CONST(struct sockaddr, AUTOMATIC, SOAD_APPL_VAR) LocalAddrPtr,
    size_t LocalAddrSize,
    P2VAR(SoAd_PortType, AUTOMATIC, SOAD_APPL_VAR) PortPtr
)
{
    Std_ReturnType RetVal = E_OK;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    SoAd_LocalIpAddrIdxType LocalAddrIdx;
    /* get local address */
    SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(SocketIdx);
    LocalAddrIdx = SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx);
    /* invoke bind socket */
    if (bind(TcpIpSocketIdx, LocalAddrPtr, LocalAddrSize) == SOAD_BSD_E_NOT_OK )
    {
        if ( errno == EADDRNOTAVAIL )
        {
            /* overwrite local addr */
            if ( SoAd_TcpIpBsdCheckAndOverwriteLocalAddr(LocalAddrIdx, FALSE) == E_NOT_OK )
            {
                SoAd_LocalIpAddrCtrlSetIpAddrReqState(LocalAddrIdx,SOAD_LOCAL_IP_ADDR_REQ_STATE_RELEASE);
                SoAd_LocalIpAddrCtrlSetLocalAddrEventStatus(LocalAddrIdx,TRUE);
            }
        }
        RetVal = E_NOT_OK;
    }
    #ifdef SOAD_BSD_ENABLE_BIND_SOCKET_TO_INTERFACE
    else if (SoAd_TcpIpBsdBindSocketToInterface(LocalAddrIdx, TcpIpSocketIdx) == E_NOT_OK)
    {
        RetVal = E_NOT_OK;
    }
    #endif
    else
    {
        if ( *PortPtr == 0u )
        {
            struct sockaddr_in SockAddr;
            socklen_t SockAddrSize = sizeof(SockAddr);
            /* Get port via BSD-like Socket API. */
            if(getsockname(TcpIpSocketIdx,(struct sockaddr *)&SockAddr,&SockAddrSize) == SOAD_BSD_E_NOT_OK)
            {
                RetVal = E_NOT_OK;
            }
            else
            {
                /* Update local port if call succeeded. */
                *PortPtr = ((struct sockaddr_in *)&SockAddr)->sin_port;
            }
        }
    }
    return RetVal;
}
#ifdef SOAD_BSD_ENABLE_BIND_SOCKET_TO_INTERFACE
/********************************************************************************************************************
* @brief The Api is used to bind the socket to the interface of the local addr
********************************************************************************************************************/
SOAD_LOCAL FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdBindSocketToInterface
(
    SoAd_LocalIpAddrIdxType LocalAddrIdx,
    TcpIp_SocketIdType TcpIpSocketIdx
)
{
    struct ifreq Ifr;
    Std_ReturnType RetVal = E_OK;
    SoAd_TcpIpCtrlIdxType TcpIpCtrlIdx;
    SoAd_TcpIpCtrlNameBufferSizeType TcpIpCtrlNameStartIdx;
    /* get TcpIp Ctrl Idx */
    TcpIpCtrlIdx = SoAd_LocalAddrCfgGetTcpIpCtrlIdx(LocalAddrIdx);
    TcpIpCtrlNameStartIdx = SoAd_TcpIpBsdCfgGetCtrlNameBufferStartIdx(TcpIpCtrlIdx);
    memset(&Ifr, 0, sizeof(Ifr));
    SoAd_UtilMemCopy((uint8 *)ifr.ifr_name,&SoAd_TcpIpBsdCfgGetpTcpIpCtrlNameBuffer(TcpIpCtrlNameStartIdx),
                        SoAd_TcpIpBsdCfgGetCtrlNameBufferSize(TcpIpCtrlIdx));
    /* Bind socket to interface. */
    if (setsockopt(TcpIpSocketIdx, SOL_SOCKET, SO_BINDTODEVICE, &Ifr, sizeof(Ifr)) == SOAD_BSD_E_NOT_OK)
    {
        RetVal = E_NOT_OK;
    }
    return RetVal;
}
#endif
/********************************************************************************************************************
* @brief The Api is used to release the socket tx buffer  
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsdReleaseSocketTxBuffer(SoAd_SocketTxBufferIdType SocketTxBufferIdx)
{
    /* reset tx buffer ctrl status */
    SoAd_SocketTxBufferCtrlSetSocketIdx(SocketTxBufferIdx,SoAd_CfgGetNumOfSocket());
    SoAd_SocketTxBufferCtrlSetLength(SocketTxBufferIdx,0U);
}
/********************************************************************************************************************
* @brief The Api is used to release the socket tx buffer used by the socket id
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsd_ReleaseSocketTxBufferForSocket(SoAd_SocketIdxType SocketIdx)
{
    SoAd_SocketTxBufferIdType TxBufferIdx;
    /* reset tx buffer ctrl status that is used by the SocketIdx */
    for (TxBufferIdx=0U;TxBufferIdx<SoAd_CfgGetSocketNumOfTxBuffer();TxBufferIdx++)
    {
        if (SoAd_SocketTxBufferCtrlGetSocketIdx(TxBufferIdx) == SocketIdx)
        {
            SoAd_SocketTxBufferCtrlSetSocketIdx(TxBufferIdx,SoAd_CfgGetNumOfSocket());
            SoAd_SocketTxBufferCtrlSetLength(TxBufferIdx,0U);
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to reset the Ip addr configuration to the default values.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdRequestSocketTxBuffer
(
    SoAd_SocketIdxType SocketIdx,
    uint16 Length,
    P2VAR(SoAd_SocketTxBufferIdType, SOAD_APPL_DATA, SOAD_APPL_DATA) SocketTxBufferIdx
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SocketTxBufferIdType LocalTxBufferIdx;
    /* check for buffer availability */
    SoAd_EnterCriticalSection();
    if (Length <= SoAd_TcpIpBsdCfgGetTxBufferSize(0))
    {
        for(LocalTxBufferIdx=0u;LocalTxBufferIdx < SoAd_CfgGetSocketNumOfTxBuffer();LocalTxBufferIdx++)
        {
            if (SoAd_SocketTxBufferCtrlGetSocketIdx(LocalTxBufferIdx) == SoAd_CfgGetNumOfSocket())
            {
                SoAd_SocketTxBufferCtrlSetSocketIdx(LocalTxBufferIdx,SocketIdx);
                *SocketTxBufferIdx = LocalTxBufferIdx;
                RetVal = E_OK;
            }
        }
    }
    SoAd_ExitCriticalSection();
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to update the length of the successfully transmitted bytes
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdUpdateSocketTxBuffer
(
    SoAd_SocketTxBufferIdType SocketTxBufferIdx,
    uint16 Length
)
{
    Std_ReturnType  RetVal = E_NOT_OK;
    SoAd_SocketTxBufferIdType TxBufferIdx;
    /* Check if there is an unused socket transmission buffer. */
    SoAd_EnterCriticalSection();
    for (TxBufferIdx = 0u; TxBufferIdx < SoAd_CfgGetSocketNumOfTxBuffer(); TxBufferIdx++)
    {
        if (SoAd_SocketTxBufferCtrlGetSocketIdx(TxBufferIdx) == SoAd_CfgGetNumOfSocket())
        {
            RetVal = E_OK;
            break;
        }
    }
    /* Update requested socket transmission buffer if an unused element was found. */
    if (RetVal == E_OK )
    {
        SoAd_SocketTxBufferCtrlSetLength(SocketTxBufferIdx,Length);
    }
    SoAd_ExitCriticalSection();
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to handle the pending tx bytes in the socket tx buffer.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsdSocketTxBufferHandler(void)
{
    uint16 Length;
    uint8 *pSendBuffer;
    SoAd_SocketIdxType SocketIdx;
    TcpIp_SocketIdType TcpIpSocketIdx=SOAD_SOCKET_ID_INVALID;
    SoAd_SocketTxBufferIdType TxBufferIdx;
    /* process all tx buffers */
    for(TxBufferIdx = 0u; TxBufferIdx < SoAd_CfgGetSocketNumOfTxBuffer();TxBufferIdx++)
    {
        SoAd_EnterCriticalSection();   
        SocketIdx = SoAd_SocketTxBufferCtrlGetSocketIdx(TxBufferIdx);
        Length = SoAd_SocketTxBufferCtrlGetLength(TxBufferIdx);
        if((SocketIdx != SoAd_CfgGetNumOfSocket()) && (Length!=0U))
        {
            TcpIpSocketIdx = SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx);
        }
        SoAd_ExitCriticalSection();
        /* invoke send API for transmission. */
        pSendBuffer = &SoAd_CtrlGetSocketTxBuffer(SoAd_TcpIpBsdCfgGetTxBufferStartIdx(TxBufferIdx)); 
        if (SOAD_BSD_E_NOT_OK != send(TcpIpSocketIdx,pSendBuffer,Length,SOAD_BSD_ZERO_FLAGS))
        {
            /* Release socket transmission buffer if call was successful. */
            SoAd_TcpIpBsdReleaseSocketTxBuffer(TxBufferIdx);
        }
    }
}
/********************************************************************************************************************
* @brief The Api is handle and process the socket reception
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(void, SOAD_CODE) SoAd_TcpIpBsdSocketReceptionHandler(void)
{
    boolean AddEventAgain;
    SoAd_SoConIdType SoConIdx;
    SoAd_SocketIdxType SocketIdx;
    SoAd_SoConGrpIdxType SoConGrpIdx;
    /* process reception in all socket */
    for (SocketIdx = 0u; SocketIdx < SoAd_CfgGetNumOfSocket(); SocketIdx++)
    {
        if (SoAd_CtrlGetSocketStateEventStatus(SocketIdx) == TRUE)
        {
            AddEventAgain = FALSE;
            /* Check if socket is ready to receive data. */
            if (SoAd_SocketCtrlGetSocketState(SocketIdx) == SOAD_SOCK_STATE_ESTABLISHED)
            {
                SoConIdx = SoAd_SocketCfgGetSoConStartIdx(SocketIdx);
                SoConGrpIdx = SoAd_SocketCfgGetSoConGrpIdx(SocketIdx);       
                if (SoAd_SoConGrpCfgIsProtoUdpSupported(SoConGrpIdx) == TRUE)
                {
                    struct sockaddr_in SockAddr;
                    socklen_t AddrLen = sizeof(SockAddr);
                    SoAd_LocalIpAddrIdxType LocalAddrIdx;
                    LocalAddrIdx = SoAd_SoConGrpCfgGetLocalAddrIdx(SoConGrpIdx);
                    /* Receive from unicast socket. */
                    if (E_OK == SoAd_TcpIpBsdUdpReceiveFrom(SoConIdx,SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx),
                                                (struct sockaddr *)&SockAddr,AddrLen))
                    {
                        AddEventAgain = TRUE;
                    }
                    if(SoAd_LocalAddrCfgGetAddressType(LocalAddrIdx) == SOAD_ADDRESS_TYPE_UNICAST)
                    {
                        /* Receive from directed broadcast address socket. */
                        if (SoAd_SocketBrdAddrCtrlGetDirectBrdAddrSockId(SocketIdx) != SOAD_SOCKET_ID_INVALID)
                        {
                            if (E_OK == SoAd_TcpIpBsdUdpReceiveFrom(SoConIdx, 
                                                            SoAd_SocketBrdAddrCtrlGetDirectBrdAddrSockId(SocketIdx),
                                                            (struct sockaddr *)&SockAddr,AddrLen))
                            {
                                /* Add event to process again */
                                AddEventAgain = TRUE;
                            }
                        }
                        /*  Receive from limited broadcast/node-local address socket. */
                        if (SoAd_SocketBrdAddrCtrlGetLimitedBrdAddrSockId(SocketIdx) != SOAD_SOCKET_ID_INVALID)
                        {
                            if (E_OK == SoAd_TcpIpBsdUdpReceiveFrom(SoConIdx,
                                                            SoAd_SocketBrdAddrCtrlGetLimitedBrdAddrSockId(SocketIdx),
                                                            (struct sockaddr *)&SockAddr,AddrLen))
                            {
                                /* Add event to process again */
                                AddEventAgain = TRUE;
                            }
                        }
                    }
                }
                else
                {
                    /* Receive from client or server data socket. */
                    if (SoAd_SocketTcpCfgGetTcpInitiate(SoAd_SoConGrpCfgGetSocketTcpIdx(SoConGrpIdx)) == TRUE ||
                        (SoAd_SoConGrpCfgGetSoConGrpSocketIdx(SoConGrpIdx) != SocketIdx))
                    {
                        if (E_OK == SoAd_TcpIpBsdTcpReceive(SoConIdx))
                        {
                            AddEventAgain = TRUE;
                        }
                    }
                    else
                    {
                        AddEventAgain = TRUE;
                    }
                }
            }
            else
            {
                AddEventAgain = TRUE;
            }
            SoAd_CtrlSetSocketStateEventStatus(SocketIdx,AddEventAgain);
        }
    }
}
/********************************************************************************************************************
* @brief The Api is used to process the tcp receive.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdTcpReceive(SoAd_SoConIdType SoConIdx)
{
    ssize_t DataLen;
    SoAd_SocketIdxType SocketIdx;
    TcpIp_SocketIdType TcpIpSocketIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_SocketTcpRxBufferIdType BufferIdx;
    SoAd_SocketTcpRxBufferSizeType BufferLength;
    SoAd_SocketTcpRxBufferSizeType RelBufferIdx;
    SoAd_SocketTcpRxBufferIdType TcpRxBufferCtrlIdx;
    /* get buffer ctrl idx */
    SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConIdx);
    TcpIpSocketIdx = SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx);
    TcpRxBufferCtrlIdx = SoAd_SocketCfgGetTcpRxBufferCtrlIdx(SocketIdx);
    if (SoAd_SocketTcpRxBufferCtrlGetLength(TcpRxBufferCtrlIdx) != SoAd_TcpIpBsdCfgGetTxBufferSize(TcpRxBufferCtrlIdx))
    {
        RelBufferIdx = SoAd_SocketTcpRxBufferCtrlGetTcpRxBufferIdx(TcpRxBufferCtrlIdx)-
                                SoAd_TcpIpBsdCfgGetTxBufferStartIdx(TcpRxBufferCtrlIdx);
        /* check for buffer wrap */
        if (SoAd_TcpIpBsdCfgGetTxBufferSize(TcpRxBufferCtrlIdx) <= 
                (RelBufferIdx+SoAd_SocketTcpRxBufferCtrlGetLength(TcpRxBufferCtrlIdx)))
        {
            /* wrap around update */
            BufferLength = SoAd_TcpIpBsdCfgGetTxBufferSize(TcpRxBufferCtrlIdx) - 
                                SoAd_SocketTcpRxBufferCtrlGetLength(TcpRxBufferCtrlIdx);
            BufferIdx = SoAd_SocketTcpRxBufferCtrlGetTcpRxBufferIdx(TcpRxBufferCtrlIdx)-BufferLength;
        }
        else
        {
            BufferLength =  SoAd_TcpIpBsdCfgGetTxBufferSize(TcpRxBufferCtrlIdx)- 
                            (RelBufferIdx+SoAd_SocketTcpRxBufferCtrlGetLength(TcpRxBufferCtrlIdx));
            BufferIdx = SoAd_SocketTcpRxBufferCtrlGetTcpRxBufferIdx(TcpRxBufferCtrlIdx)+
                            SoAd_SocketTcpRxBufferCtrlGetLength(TcpRxBufferCtrlIdx);
        }
         /* Receive data via BSD-like Socket API. */
        DataLen = recv(TcpIpSocketIdx, &SoAd_CtrlGetSocketTcpRxBuffer(BufferIdx),(ssize_t)BufferLength, 0);
        if ((DataLen == 0u) || (DataLen == SOAD_BSD_E_NOT_OK))
        {
            /* set E_OK if no data is received to check again. */
            if (((errno == EAGAIN) || (errno == EWOULDBLOCK)) && (DataLen != 0))
            {
                RetVal = E_OK;
            }
            else
            {
                /* Close socket if unknown error occurred otherwise. */
                SoAd_TcpIpBsdClose(SocketIdx,TcpIpSocketIdx, TRUE);
            }
        }
        else
        {
            #ifdef DLOG
            Dlog_Print("Tcp Message rcvd bsd socket %d length %ld ",TcpIpSocketIdx,DataLen);
            #endif
            SoAd_SocketTcpRxBufferCtrlSetLength(TcpRxBufferCtrlIdx,
                                                (SoAd_SocketTcpRxBufferCtrlGetLength(TcpRxBufferCtrlIdx)+DataLen));
            /* notify SoAd */
            SoAd_RxIndication(TcpIpSocketIdx, (SoAd_SockAddrType *)&SoAd_SoConCtrlGetRemoteAddr(SoConIdx),
                               &SoAd_CtrlGetSocketTcpRxBuffer(BufferIdx),DataLen);
            RetVal = E_OK;
        }
    }
    else
    {
        RetVal = E_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief The Api is used to reset the Ip addr configuration to the default values.
********************************************************************************************************************/
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdUdpReceiveFrom
(
    SoAd_SoConIdType SoConIdx,
    TcpIp_SocketIdType TcpIpSocketId,
    P2VAR(struct sockaddr, AUTOMATIC, SOAD_APPL_VAR) RemAddrPtr,
    socklen_t RemAddrSize
)
{
    ssize_t DataLen;
    SoAd_SocketIdxType SocketIdx;
    TcpIp_SocketIdType UnicastSocketIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    /* get unicast address id */
    SocketIdx = SoAd_SoConCfgGetSocketIdx(SoConIdx);
    UnicastSocketIdx = SoAd_SocketCtrlGetTcpIpSocketId(SocketIdx);
    /* Receive data from socket */
    DataLen = recvfrom(TcpIpSocketId, &SoAd_CtrlGetSocketUdpRxBuffer(0u), SOAD_SOCKET_UDP_RX_BUFFER_SIZE, 0u,
                        RemAddrPtr,&RemAddrSize);    
    if ((DataLen == 0u) || (DataLen == SOAD_BSD_E_NOT_OK))
    {
        if(((errno == EAGAIN) || (errno == EWOULDBLOCK)) && (DataLen != 0) )
        {
            RetVal = E_OK;
        }
        else
        {
            /* Close unicast socket (broadcast/multicast sockets closed in same context) if unknown error occurred. */
            SoAd_TcpIpBsdClose(SocketIdx,UnicastSocketIdx, TRUE);
        }
    }
    else
    {
        SoAd_SockAddrType RemAddr;
        /* update remote address */
        SoAd_UtilAddrSetDomain(RemAddr,SOAD_AF_INET);
        SoAd_UtilAddrSetIpv4Addr(RemAddr,((struct sockaddr_in*)RemAddrPtr)->sin_addr.s_addr);
        SoAd_UtilAddrSetPort(RemAddr,((struct sockaddr_in*)RemAddrPtr)->sin_port);
        #ifdef DLOG
        Dlog_Print("Udp Message rcvd from Ip %d port %d length %d\n",((struct sockaddr_in*)RemAddrPtr)->sin_addr.s_addr,
                                ((struct sockaddr_in*)RemAddrPtr)->sin_port,DataLen);
        #endif
        /* notiy if data received from IP different from local ip */
        if (E_NOT_OK == SoAd_TcpIpBsdIsSameAsLocalIp(SoConIdx,&RemAddr))
        {
            /* notify SoAd */
            SoAd_RxIndication(UnicastSocketIdx,(SoAd_SockAddrType *)&RemAddr,
                                    &SoAd_CtrlGetSocketUdpRxBuffer(0u),DataLen);
        }
        RetVal = E_OK;
    }
    return RetVal;
}
SOAD_LOCAL_INLINE FUNC(Std_ReturnType, SOAD_CODE) SoAd_TcpIpBsdIsSameAsLocalIp
(
    SoAd_SoConIdType SoConIdx,
    P2CONST(SoAd_SockAddrType,AUTOMATIC,SOAD_APPL_CONST)  pRemAddr
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    SoAd_LocalIpAddrIdxType LocalAddrIdx;

    LocalAddrIdx = SoAd_SoConGrpCfgGetLocalAddrIdx(SoConIdx);

    if (SoAd_LocalIpAddrCtrlGetIpv4Addr(LocalAddrIdx) == SoAd_UtilpAddrGetIpv4Addr(pRemAddr))
    {
        RetVal = E_OK;
    }
    return RetVal;
}


#endif
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
