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
*    @file TcpIp.c
*    @ingroup TcpIp
*    @brief This file implements the AUTOSAR TcpIp module.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "TcpIp.h"
#include "TcpIp_Lcfg.h"
#include "SchM_TcpIp.h"
#include "TcpIp_EthSM.h"
#include "EthIf.h"
#include "lwip/inet.h"
#include "lwip/sockets.h"
#include <string.h>
#include "lwip/def.h"
#include "lwip/opt.h"
#include "lwip/tcp.h"
#include "lwip/udp.h"
#include "lwip/snmp.h"
#include "lwip/mem.h"
#include "lwip/memp.h"
#include "lwip/tcpip.h"
#include "lwip/netif.h"
#include "netif/etharp.h"
#include "lwip/dhcp.h"
#include "lwip/autoip.h"
#include "lwip/ethip6.h"

#if( TCPIP_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif
/********************************************************************************************************************
*  Version check                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if ((TCPIP_SW_MAJOR_VERSION != TCPIP_CFG_SW_MAJOR_VERSION) || \
    (TCPIP_SW_MINOR_VERSION != TCPIP_CFG_SW_MINOR_VERSION) || \
    (TCPIP_SW_PATCH_VERSION != TCPIP_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if ((TCPIP_AR_RELEASE_MAJOR_VERSION != TCPIP_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (TCPIP_AR_RELEASE_MINOR_VERSION != TCPIP_CFG_AR_RELEASE_MINOR_VERSION) || \
    (TCPIP_AR_RELEASE_REVISION_VERSION != TCPIP_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif
/********************************************************************************************************************
*  feature validation check                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
/* Macro for static and inline type */
#ifndef TCPIP_LOCAL 
#define TCPIP_LOCAL                             static
#endif

#ifndef LOCAL_INLINE
#define LOCAL_INLINE                            static inline
#endif

#ifndef TCPIP_LOCAL_INLINE
#define TCPIP_LOCAL_INLINE                      LOCAL_INLINE
#endif
/* Ethernet Size cfg */
#define  TCPIP_MTU_SIZE                         1500u
#define  TCPIP_ETH_HEADER_SIZE                  14u
#define  TCPIP_ETH_MAC_ADDR_SIZE                6u
#define  TCPIP_ETH_FRAMETYPE_SIZE               2u
/* Ethernet types used */
#define  TCPIP_FRAME_TYPE_IPV4                  0x0800
#define  TCPIP_FRAME_TYPE_ARP                   0x0806
#define TCPIP_NOF_ERR_BEFORE_RESET              100
/* Define for network interface. */
#define IFNAME0 'E'
#define IFNAME1 'T'
#define TCPIP_ETH_CTRL_INDEX 0U  
/* Det error api */
#define TcpIp_DetReportError(api,err)   (void)Det_ReportError(TCPIP_MODULE_ID, TCPIP_INSTANCE_ID, (api), (err))
#define TcpIp_GetLocalUnicastAddr(Id)                       (TcpIp_CtrlStatus[Id].pLocalUnicastAddr)
#define TcpIp_GetLocalUnicastAddrAddrId(Id)                 (TcpIp_GetLocalUnicastAddr(Id)->TcpIpAddrId)
#define TcpIp_GetLocalUnicastAddrAddrType(Id)               (TcpIp_GetLocalUnicastAddr(Id)->AddressType)
#define TcpIp_GetLocalUnicastAddrDomainType(Id)             (TcpIp_GetLocalUnicastAddr(Id)->DomainType)
#define TcpIp_GetLocalUnicastAddrIsValid(Id)                (TcpIp_GetLocalUnicastAddr(Id)->IsValid)
#define TcpIp_GetLocalUnicastAddrCtrlConfigId(Id)           (TcpIp_GetLocalUnicastAddr(Id)->CtrlConfigId)
#define TcpIp_GetLocalUnicastAddrAssignmentConfig(Id)       (TcpIp_GetLocalUnicastAddr(Id)->pAddrAssignmentConfig)
#define TcpIp_GetLocalUnicastAddrStaticIpAddressConfig(Id)  (TcpIp_GetLocalUnicastAddr(Id)->pStaticIpAddressConfig)

#define TcpIp_GetLocalUnicastAddrTcpIpStaticIpAddress(Id)   (TcpIp_GetLocalUnicastAddrStaticIpAddressConfig(Id)->TcpIpStaticIpAddress)
#define TcpIp_GetLocalUnicastAddrTcpIpDefaultRouter(Id)     (TcpIp_GetLocalUnicastAddrStaticIpAddressConfig(Id)->TcpIpStaticIpAddress)
#define TcpIp_GetLocalUnicastAddrTcpIpNetmask(Id)           (TcpIp_GetLocalUnicastAddrStaticIpAddressConfig(Id)->TcpIpNetmask)
#define TcpIp_GetLocalUnicastAddrStaticIpAddrIsValid(Id)    (TcpIp_GetLocalUnicastAddrStaticIpAddressConfig(Id)->IsValid)

#define TcpIp_GetLocalUnicastAddrAssignmentLifetime(Id)     (TcpIp_GetLocalUnicastAddrAssignmentConfig(Id)->AssignmentLifetime)
#define TcpIp_GetLocalUnicastAddrAssignmentMethod(Id)       (TcpIp_GetLocalUnicastAddrAssignmentConfig(Id)->AssignmentMethod)
#define TcpIp_GetLocalUnicastAddrAssignmentPriority(Id)     (TcpIp_GetLocalUnicastAddrAssignmentConfig(Id)->TcpIpAssignmentPriority)
#define TcpIp_GetLocalUnicastAddrAssignmentTrigger(Id)      (TcpIp_GetLocalUnicastAddrAssignmentConfig(Id)->TcpIpAssignmentTrigger)
/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/
/*! @brief Defines the socket state */
typedef enum 
{
    TCPIP_SOCKET_INIT,
    TCPIP_SOCKET_BIND,
    TCPIP_SOCKET_TCP_CONNECT_LISTEN,
    TCPIP_SOCKET_TCP_CONNECTING,
    TCPIP_SOCKET_TCP_LISTENING,
    TCPIP_SOCKET_TCP_READY,
    TCPIP_SOCKET_UDP_READY
} TcpIp_SocketStateType;

/*! @brief Defines the socket status type */
typedef struct 
{
    boolean                             ProtocolIsTcp;
    uint8                               OwnerId;
    uint16                              ErrCnt;
    sint32                              Handle;
    TcpIp_SocketStateType               State;
    TcpIp_SockAddrType                  RemoteAddr;
    const TcpIp_LocalAddrConfigType     *pLocalAddr;
    void			                    *pvPcbAddr;
#ifdef CFG_TCPIP_DEBUG
    uint16                              ErrCntMax;
    uint16                              NumofClosedSocket;
    sint32                              SockErrorsArr[TCPIP_NOF_ERR_BEFORE_RESET];
#endif
}TcpIp_SocketStatusType;

/*! @brief Defines the Ctrl status type */
typedef struct 
{
    boolean                     LinkUp;
    TcpIp_StateType             CtrlState;
    TcpIp_StateType             ReqCtrlState;
    const TcpIp_LocalAddrConfigType   *pLocalUnicastAddr;
    struct netif                TcpIpNetif;
}TcpIp_CtrlStatusType;

/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
#define TCPIP_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "MemMap.h"

TCPIP_LOCAL VAR(TcpIp_CtrlStatusType,TCPIP_VAR_INIT) TcpIp_CtrlStatus[TCPIP_NUM_OF_CONTROLLERS];
TCPIP_LOCAL VAR(TcpIp_SocketStatusType,TCPIP_VAR_INIT) TcpIp_SocketStatus[TCPIP_NUM_OF_SOCKETS];
TCPIP_LOCAL P2CONST(TcpIp_TcpIpConfigType,AUTOMATIC,TCPIP_VAR_INIT) pTcpIpConfig = &TcpIp_TcpIpConfig;

#define TCPIP_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED
#include "MemMap.h"

#define TCPIP_START_SEC_VAR_INIT_LOCAL_BOOLEAN
#include "MemMap.h"
static boolean TcpIp_InitStatus = FALSE;
#define TCPIP_STOP_SEC_VAR_INIT_LOCAL_BOOLEAN
#include "MemMap.h"

/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
#define TCPIP_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief      This service is to intialize the LWIP stack  
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) TcpIp_LwIPInit(void);
/*!******************************************************************************************************************
*   @brief      This service is to process the socket states
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_SocketStateHandling(void);
/*!******************************************************************************************************************
*   @brief      This service is to process the controller state handling
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_CtrlStateHandling(void);
/*!******************************************************************************************************************
*   @brief      This service is to process the tcp socket Listening state
*   @param[in]  SocketId Socket Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_HandleSocketStateListening(TcpIp_SocketIdType SocketId);
/*!******************************************************************************************************************
*   @brief      This service is to process the tcp socket connecting state
*   @param[in]  SocketId Socket Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE)  TcpIp_HandleSocketStateConnecting(TcpIp_SocketIdType SocketId);
/*!******************************************************************************************************************
*   @brief      This service is to process the tcp socket ready state
*   @param[in]  SocketId Socket Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_HandleSocketStateTcpReady(TcpIp_SocketIdType SocketId);
/*!******************************************************************************************************************
*   @brief      This service is to process the tcp socket ready state
*   @param[in]  SocketId Socket Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_HandleSocketStateUdpReady(TcpIp_SocketIdType SocketId);
/*!******************************************************************************************************************
*   @brief      This service is to process the tcp ctrl offline state
*   @param[in]  CtrlIdx Ctrl Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_HandleStateOffline(uint8 CtrlIdx);
/*!******************************************************************************************************************
*   @brief      This service is to process entry to the tcp ctrl offline state
*   @param[in]  CtrlIdx Ctrl Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_EnterOfflineState(uint8 CtrlIdx);
/*!******************************************************************************************************************
*   @brief      This service is to process the tcp ctrl Online state
*   @param[in]  CtrlIdx Ctrl Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_HandleStateOnline(uint8 CtrlIdx);
/*!******************************************************************************************************************
*   @brief      This service is to process the tcp ctrl Onhold state
*   @param[in]  CtrlIdx Ctrl Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_HandleStateOnhold(uint8 CtrlIdx);
/*!******************************************************************************************************************
*   @brief      This service is to process the tcp ctrl Startup state
*   @param[in]  CtrlIdx Ctrl Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_HandleStateStartup(uint8 CtrlIdx);
/*!******************************************************************************************************************
*   @brief      This service is to process the tcp ctrl Startup state
*   @param[in]  CtrlIdx Ctrl Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_HandleStateShutdown(uint8 CtrlIdx);
/*!******************************************************************************************************************
*   @brief      This service is to enable all the Ip address assignment 
*   @param[in]  CtrlIdx Ctrl Id to be processed
*   @param[in]  CtrlIdx Ctrl Ip address state
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) TcpIp_NotifyLocalIpAddrAssignmentChg(uint8 CtrlIdx, TcpIp_IpAddrStateType IpAddrState);
/*!******************************************************************************************************************
*   @brief      This service is to enable all the Ip address assignment 
*   @param[in]  CtrlIdx Ctrl Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_EnableAllIpAddrAssignments(uint8 CtrlIdx);
/*!******************************************************************************************************************
*   @brief      This service is to enable all the Ip address assignment 
*   @param[in]  CtrlIdx Ctrl Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_DisableAllIpAddrAssignments(uint8 CtrlIdx);
/*!******************************************************************************************************************
*   @brief      This service is to process the automatic address assignment
*   @param[in]  LocalAddrId Ctrl Id to be processed
*   @param[in]  Type Ctrl Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_AutomaticIpAddrAssignment
(
    TcpIp_LocalAddrIdType LocalAddrId
);
/*!******************************************************************************************************************
*   @brief This service is to release the assigned ip address and reques the LwIp stack to release the assigned the
*   ip address
*   @param[in] pLocalAddrConfig pointer to the local address configuration
*   @return status of the request E_OK: ip address release request accepted 
    E_NOT_OK: ip address release request not accepted
********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_RelIpAddrAssignment
(
    TcpIp_LocalAddrIdType LocalAddrId
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
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) LwIp_RxIndication
(
    uint8 CtrlIdx,
    Eth_FrameType FrameType,
    boolean IsBroadcast,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) PhysAddrPtr,
    P2CONST(Eth_DataType,AUTOMATIC,TCPIP_APPL_CONST) DataPtr,
    uint16 LenByte
);
/*!******************************************************************************************************************
*   @brief This service is to set up the network interface of the Lwip stack
*   @param[in] ipaddr ipv4 address
*   @param[in] netmask ipv4 netmask
*   @param[in] gw ipv4 gateway address
*   @param[in] initFnc Init function of LwIp protocol
*   @param[in] inputFnc input function of LwIp protocol
*   @param[in] netif netif struc to be updated to LwIP stack
*   @return status of the request TRUE: Request accepted FALSE: Request not accepted
********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean,TCPIP_CODE) LwIP_AddNetIf
( 
    P2CONST(ip_addr_t,AUTOMATIC,TCPIP_APPL_CONST) pIpAddr, 
    P2CONST(ip_addr_t,AUTOMATIC,TCPIP_APPL_CONST) pNetMask, 
    P2CONST(ip_addr_t,AUTOMATIC,TCPIP_APPL_CONST) pGwAddr, 
    netif_init_fn pInitFnc,
    netif_input_fn pInputFnc,
    struct netif *pNetIf
);
/*!******************************************************************************************************************
*   @brief This service is to get the local address id configuration
*   @param[in] LocalAddrId Local address id
*   @return E_OK if the configuration is found E_NOT_OK if configuration is not found
********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_VerifyLocalAddrId
(
    TcpIp_LocalAddrIdType AddressId
);
/*!******************************************************************************************************************
*   @brief This service is to switch the ethernet controller state
*   @param[in] CtrlIdx requested controller id
*   @param[in] TcpIpState requested state
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) TcpIp_SwitchEthIfCtrlState(uint8 CtrlIdx, TcpIp_StateType TcpIpState);
/*!******************************************************************************************************************
*   @brief This service is to get the available free socket id
*   @param[out] pSocketIdPtr pointer to update the socket id
*   @return status of the request E_OK Socket available E_NOT_OK Socket not available
********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_GetFirstFreeSocket(TcpIp_SocketIdType *pSocketId);
/*!******************************************************************************************************************
*   @brief This service is to re-initialize the status of the socket
*   @param[in] SocketId socket id to be reinitialized
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) TcpIp_FreeUpSocket(TcpIp_SocketIdType SocketId);
/*!******************************************************************************************************************
*   @brief      This service is to process the socket status
*   @param[in]  SocketId socket id to get the status
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) TcpIp_SocketStatusCheck(TcpIp_SocketIdType SocketId);
#if LWIP_NO_SYS
/*!******************************************************************************************************************
*   @brief This service is to get buffer from the memory pool
*   @param[in] size requested buffer size
*   @param[out] buffPtr pointer to get the allocated buffer
*   @return result of the request TRUE: Buffer is allocated and returns the address
*   FALSE: Buffer not allocated and returns NULL_PTR
********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean,TCPIP_CODE) TcpIp_BufferGet(uint32 Size, uint8** buffPtr);
/*!******************************************************************************************************************
*   @brief This service is to free the allocated buffer
*   @param[in] CtrlIdx EthIf controller Id
********************************************************************************************************************/
LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_BufferFree(P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) pBuffer);
#endif
/*!******************************************************************************************************************
*   @brief This service is to convert 32 bit ip address array to the 8 bit ip address
*   @param[in] CtrlIdx EthIf controller Id
*   @param[in] IpAddr 32 bit ip address
*   @param[in] Action Add or remove the address from the Ethernet controllers filter.
*   @return status of the request E_OK: filter was successfully changed E_NOT_OK: filter could not be changed
********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_ChangePhysAddrFilterForMulticast
(
    uint8 CtrlIdx, 
    uint32 IpAddr, 
    Eth_FilterActionType Action
);
/*!******************************************************************************************************************
*   @brief This service is to convert 32 bit ip address array to the 8 bit ip address
*   @param[in] src input buffer containing the 32 bit ip address
*   @param[out] dest pointer to the output buffer with the 8 bit ip address
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) TcpIp_IpAddr32To8(uint32 src, P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) dest);
/*!******************************************************************************************************************
*   @brief This service is to convert 8 bit ip address array to the 32 bit ip  address
*   @param[in] src pointer to input buffer containing the 8 bit ip address
*   @param[out] dest pointer to the output buffer with the 32 bit ip address
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) TcpIp_IpAddr8to32
(
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) src, 
    P2VAR(uint32,AUTOMATIC,TCPIP_APPL_DATA) dest
);
/*!******************************************************************************************************************
*   @brief This service is to convert CIDR netmask to net mask ip addr 
*   @param[in,out] NetmaskAddr pointer to buffer for updating the netmask
*   @param[in] Netmask CIDR notation of netmask
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) TcpIp_Ip4NetmaskToIpAddr
(
    P2VAR(ip_addr_t,AUTOMATIC,TCPIP_APPL_DATA) NetmaskAddr,
    uint8 Netmask
);
#if LWIP_TCPIP_INIT_DONE_CALLBACK
/*!******************************************************************************************************************
*   @brief This service is the callback function which will be called after TcpIp stack initilisation from LwIp stack
*   @param[in] pArg pointer to the arg from the LwIp stack
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) LwIp_TcpIpInitDone(void *pArg);
#endif
#if LWIP_NETIF_STATUS_CALLBACK
/*!******************************************************************************************************************
*   @brief This service is the callback function which will be called after after netif setup or down or link change 
*   from LwIp stack.
*   @param[in] pNetIf pointer to the NetIf struct
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) LwIP_StatusCallback(struct netif *pNetIf);
#endif
/*!******************************************************************************************************************
*   @brief This service is the callback function which will be called after network interface start from LwIp stack.
*   @param[in] pNetIf pointer to the NetIf struct
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) LwIP_EthernetifStart(struct netif *pNetIf);
/*!******************************************************************************************************************
*   @brief This service is the callback function which will be called for HW initialisation function (low level init)
*   from LwIp stack.
*   @param[in] pNetIf pointer to the NetIf struct
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) LwIp_EthernetifInit(struct netif *pNetIf);
/*!******************************************************************************************************************
*   @brief This service is the callback function which will be called at set up netif and subsequently HW 
*   initialisation.This function should be passed as a parameter to netif_add()
*   @param[in] pNetIf pointer to the NetIf struct
********************************************************************************************************************/
TCPIP_LOCAL FUNC(err_t,TCPIP_CODE) ethernetif_init(struct netif *pNetIf);
/*!******************************************************************************************************************
*   @brief This service is the callback function which will be called for Frames Transmission function
*   @param[in] pNetIf pointer to the NetIf struct
*   @param[in] pBuffer pointer to the buffer
*   @retrun error status of the request
********************************************************************************************************************/
TCPIP_LOCAL FUNC(err_t,TCPIP_CODE) LwIp_Output
(
    P2VAR(struct netif,AUTOMATIC,TCPIP_APPL_DATA) pNetIf,
    P2VAR(struct pbuf,AUTOMATIC,TCPIP_APPL_DATA) pBuffer
);
static void udp_recv_cb_fn(void *arg, struct udp_pcb *pcb, struct pbuf *p, const ip_addr_t *addr, u16_t port);
static err_t tcp_recv_cb_fn(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err);
static err_t tcp_accept_cb_fn(void *arg, struct tcp_pcb *pcb, err_t err);
static err_t tcp_sent_cb_fn(void *arg, struct tcp_pcb *pcb, u16_t len);
static err_t tcp_connect_cb_fn(void *arg, struct tcp_pcb *pcb,  err_t err);
static void tcp_error_fn(void *arg, err_t err);

#define TCPIP_STOP_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC FUNCTION IMPLEMENTATION                                                                                   *
********************************************************************************************************************/
#define TCPIP_START_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*   @brief      This service initializes the TCP/IP Stack. TcpIp_Init may not block the start-up process for
*               an indefinite amount of time. Caveats: The call of this service is mandatory before using the TcpIp
*               instance for further processing.
*   @param[in]  ConfigPtr  Pointer to the configuration data of the TcpIp module
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_Init(P2CONST(TcpIp_ConfigType,AUTOMATIC,TCPIP_APPL_CONST) ConfigPtr)
{
    uint8    CtrlId;
    TcpIp_SocketIdType  SocketId;
    /*! Initialize the Ctrl status */
    for(CtrlId = 0U; CtrlId < TCPIP_NUM_OF_CONTROLLERS; CtrlId++)
    {
        TcpIp_CtrlStatus[CtrlId].CtrlState = TCPIP_STATE_OFFLINE;
        TcpIp_CtrlStatus[CtrlId].ReqCtrlState = TCPIP_STATE_OFFLINE;
        TcpIp_CtrlStatus[CtrlId].pLocalUnicastAddr = NULL_PTR;
        TcpIp_CtrlStatus[CtrlId].LinkUp = FALSE;
    }

    /*! Initialize the socket status */
    for(SocketId =0U; SocketId < TCPIP_NUM_OF_SOCKETS; SocketId++)
    {
        TcpIp_SocketStatus[SocketId].State = TCPIP_SOCKET_INIT;
        TcpIp_SocketStatus[SocketId].Handle = -1;
        TcpIp_SocketStatus[SocketId].pLocalAddr = NULL_PTR;
        TcpIp_SocketStatus[SocketId].pvPcbAddr = NULL_PTR;
        TcpIp_SocketStatus[SocketId].ProtocolIsTcp = FALSE;
        TcpIp_SocketStatus[SocketId].ErrCnt = 0;
    }
    /* LWIP Stack Init */
    TcpIp_LwIPInit();
    TcpIp_InitStatus = TRUE;
    TCPIP_DUMMY_STATEMENT(ConfigPtr);
}
/********************************************************************************************************************
*   @brief      Returns the version information.
*   @param[out] versioninfo  Pointer to where to store the version information of this module
*   @ServiceID  0x02
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(void,TCPIP_CODE) TcpIp_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,TCPIP_APPL_DATA) versioninfo)
{
    uint8 ErrorId = TCPIP_E_NO_ERROR;

    /* Check if parameter VersionInfo is valid */
    if ( NULL_PTR == versioninfo )
    {
        ErrorId = TCPIP_E_PARAM_POINTER;
    }
    else
    {
        versioninfo->vendorID         = TCPIP_VENDOR_ID;
        versioninfo->moduleID         = TCPIP_MODULE_ID;
        versioninfo->sw_major_version = TCPIP_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = TCPIP_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = TCPIP_SW_PATCH_VERSION;
    }
#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_GETVERSIONINFO_API, ErrorId);
    }
#else
    TCPIP_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_Close(TcpIp_SocketIdType SocketId, boolean Abort)
{
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    Std_ReturnType Result = E_NOT_OK;
    TcpIp_EventType event;
    uint8 OwnerId;
    if (TRUE != TcpIp_InitStatus )
    {
        ErrorId = TCPIP_E_UNINIT;
    }
    else if (TCPIP_NUM_OF_SOCKETS <= SocketId)
    {
        ErrorId = TCPIP_E_INV_ARG;
    }
    else
    {
        if(TRUE == TcpIp_SocketStatus[SocketId].ProtocolIsTcp)
        {
            tcp_close(TcpIp_SocketStatus[SocketId].pvPcbAddr);
            event = TCPIP_TCP_CLOSED;
        }
        else
        {
            udp_remove(TcpIp_SocketStatus[SocketId].pvPcbAddr);
            event = TCPIP_UDP_CLOSED;
        }
        OwnerId = TcpIp_SocketStatus[SocketId].OwnerId;
        if(TcpIp_CfgGetUpTcpIpEventFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId) != NULL_PTR)
        {
            TcpIp_CfgGetUpTcpIpEventFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId)(SocketId, event);
        }
        /* ReInitialize the socket status */
        TcpIp_FreeUpSocket(SocketId);
        Result = E_OK;
    }

    TCPIP_DUMMY_STATEMENT(Abort);
    
#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_CLOSE_API, ErrorId);
    }
#else
    TCPIP_DUMMY_STATEMENT(ErrorId);
#endif
    return Result;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_Bind
(
    TcpIp_SocketIdType SocketId,
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(uint16,AUTOMATIC,TCPIP_APPL_DATA) PortPtr
)
{
    Std_ReturnType Result = E_NOT_OK;
    ip_addr_t IpAddr;
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    
    if (TRUE != TcpIp_InitStatus )
    {
        ErrorId = TCPIP_E_UNINIT;
    }
    else if (TCPIP_NUM_OF_SOCKETS <= SocketId)
    {
        ErrorId = TCPIP_E_INV_ARG;
    }
    else if ( NULL_PTR == PortPtr)
    {
        ErrorId = TCPIP_E_PARAM_POINTER;
    }
    else
    {
        if(TcpIp_VerifyLocalAddrId(LocalAddrId) != E_NOT_OK)
        {
            IpAddr.addr = TcpIp_CfgGetLocalAddrTcpIpStaticIpAddress(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId);
            
            if(FALSE == TcpIp_SocketStatus[SocketId].ProtocolIsTcp)
            {
                if (ERR_OK == udp_bind(TcpIp_SocketStatus[SocketId].pvPcbAddr, &IpAddr, *PortPtr))
                {
                    Result = E_OK;
                }
                else
                {
                    udp_remove(TcpIp_SocketStatus[SocketId].pvPcbAddr);
                    (void)TcpIp_Close(SocketId,FALSE);
                    ErrorId = TCPIP_E_NOTCONN;
                }
            }
            else
            {
                if (ERR_OK == tcp_bind(TcpIp_SocketStatus[SocketId].pvPcbAddr, &IpAddr, *PortPtr))
                {
                    Result = E_OK;
                }
                else
                {
                    tcp_close(TcpIp_SocketStatus[SocketId].pvPcbAddr);
                    (void)TcpIp_Close(SocketId,FALSE);
                    ErrorId = TCPIP_E_NOTCONN;
                }
            }
            /* Bind the local address to the socket */
            if(Result == E_OK) 
            {
                TcpIp_SocketStatus[SocketId].Handle = SocketId;
                TcpIp_SocketStatus[SocketId].pLocalAddr = TcpIp_CfgGetLocalAddrConfig(TcpIp_CfgGetTcpIpConfigPtr(),
                                                                                        LocalAddrId);
                if (TcpIp_SocketStatus[SocketId].ProtocolIsTcp == TRUE)
                {
                    TcpIp_SocketStatus[SocketId].State = TCPIP_SOCKET_TCP_CONNECT_LISTEN;
                }
                else
                {
                    TcpIp_SocketStatus[SocketId].State = TCPIP_SOCKET_UDP_READY;
                }
            }
        }
        else
        {
            ErrorId = TCPIP_E_ADDRNOTAVAIL; 
        }
    }
#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_BIND_API, ErrorId);
    }
#else
    TCPIP_DUMMY_STATEMENT(ErrorId);
#endif
    return Result;
}
/********************************************************************************************************************
*   @brief      By this API service the TCP/IP stack is requested to establish a TCP connection to the configured
*               peer.
*   @param[in]  SocketId  Socket handle identifying the local socket resource
*   @param[in]  RemoteAddrPtr IP address and port of the remote host to connect to.
*   @return     E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x06
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant for different SocketIds. Non reentrant for the same SocketId.
********************************************************************************************************************/
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_TcpConnect
(
    TcpIp_SocketIdType SocketId,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) RemoteAddrPtr
)
{
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    Std_ReturnType Result = E_NOT_OK;
    ip_addr_t IpAddr;

    if (TRUE != TcpIp_InitStatus )
    {
        ErrorId = TCPIP_E_UNINIT;
    }
    else if (TCPIP_NUM_OF_SOCKETS <= SocketId)
    {
        ErrorId = TCPIP_E_INV_ARG;
    }
    else if(NULL_PTR == RemoteAddrPtr)
    {
        ErrorId = TCPIP_E_PARAM_POINTER;
    }
    else
    {
        if (RemoteAddrPtr->Domain == TCPIP_AF_INET)
        {
            if ((TcpIp_SocketStatus[SocketId].State == TCPIP_SOCKET_TCP_CONNECT_LISTEN) ||
                (TcpIp_SocketStatus[SocketId].State == TCPIP_SOCKET_BIND))
            {
                IpAddr.addr = RemoteAddrPtr->SockAddrInetType.Addr[0];
                if (ERR_OK != tcp_connect(TcpIp_SocketStatus[SocketId].pvPcbAddr,
                    &IpAddr, (RemoteAddrPtr->SockAddrInetType.Port), tcp_connect_cb_fn))
                {
                    ErrorId = TCPIP_E_NOTCONN;
                }
                else
                {
                    TcpIp_SocketStatus[SocketId].State = TCPIP_SOCKET_TCP_CONNECTING;
                    Result = E_OK;
                }
            }
        }
    }
#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_TCPCONNECT_API, ErrorId);
    }
#else
    TCPIP_DUMMY_STATEMENT(ErrorId);
#endif
    return Result;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_TcpListen(TcpIp_SocketIdType SocketId,uint16 MaxChannels)
{
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    Std_ReturnType Result = E_NOT_OK;
    void* pvNewPcb = NULL_PTR;
    
    if (TRUE != TcpIp_InitStatus )
    {
        ErrorId = TCPIP_E_UNINIT;
    }
    else if (TCPIP_NUM_OF_SOCKETS <= SocketId)
    {
        ErrorId = TCPIP_E_INV_ARG;
    }
    else
    {
        if (TcpIp_SocketStatus[SocketId].State == TCPIP_SOCKET_TCP_CONNECT_LISTEN)
        {
            pvNewPcb = tcp_listen(TcpIp_SocketStatus[SocketId].pvPcbAddr);
            if (NULL_PTR != pvNewPcb)
            {
                TcpIp_SocketStatus[SocketId].pvPcbAddr = pvNewPcb;
            }
            /* Register callback to be called when connection is accepted by tcp server */
            tcp_accept(TcpIp_SocketStatus[SocketId].pvPcbAddr, tcp_accept_cb_fn);
            
            Result = E_OK;
        }
    }
#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
        TcpIp_DetReportError(TCPIP_TCPLISTEN_API, ErrorId);
    }
#endif
    return Result;
}
/********************************************************************************************************************
*   @brief      By this API service the reception of socket data is confirmed to the TCP/IP stack.
*   @param[in]  SocketId  Socket identifier of the related local socket resource
*   @param[in]  Length Number of bytes finally consumed by the upper layer
*   @return     E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x08
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant for different SocketIds. Non reentrant for the same SocketId.
********************************************************************************************************************/
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_TcpReceived(TcpIp_SocketIdType SocketId,uint32 Length)
{
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    Std_ReturnType Result = E_NOT_OK;
    
    if (TRUE != TcpIp_InitStatus )
    {
        ErrorId = TCPIP_E_UNINIT;
    }
    else if (TCPIP_NUM_OF_SOCKETS <= SocketId)
    {
        ErrorId = TCPIP_E_INV_ARG;
    }
    else
    {
        Result = E_OK;
    }

    TCPIP_DUMMY_STATEMENT(SocketId);
    TCPIP_DUMMY_STATEMENT(Length);
#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_TCPRECEIVED_API, ErrorId);
    }
#else
    TCPIP_DUMMY_STATEMENT(ErrorId);
#endif
    return Result;
}
/********************************************************************************************************************
*   @brief      By this API service the TCP/IP stack is requested to change the TcpIp state of the communication
*               network identified by EthIf controller index.
*   @param[in]  CtrlIdx  EthIf controller index to identify the communication network where the TcpIp state is
*               requested.
*   @param[in]  State Requested TcpIp state.
*   @return     E_OK: Service accepted E_NOT_OK: Service denied
*   @ServiceID  0x09
*   @Sync/Async Asynchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_RequestComMode(uint8 CtrlIdx,TcpIp_StateType State)
{
    Std_ReturnType Result = E_NOT_OK;
    uint8 ErrorId = TCPIP_E_NO_ERROR;

    if (TRUE != TcpIp_InitStatus)
    {
        ErrorId = TCPIP_E_UNINIT;
    }
    else if ((TCPIP_NUM_OF_CONTROLLERS <= CtrlIdx) || 
            ((TCPIP_STATE_SHUTDOWN == State) || (TCPIP_STATE_STARTUP == State) ||
            ((TCPIP_STATE_SHUTDOWN+1U) <= State)))
    {
        ErrorId = TCPIP_E_INV_ARG;
    }
    else
    {        
        if(State != TcpIp_CtrlStatus[CtrlIdx].CtrlState)
        {
            switch (State) 
            {
                /* Handled as part of request/release ip address */
                case TCPIP_STATE_OFFLINE:
                case TCPIP_STATE_ONLINE:
                    Result = E_OK;
                    break;
                default: /* TCPIP_STATE_ONHOLD */
                    if(TcpIp_CtrlStatus[CtrlIdx].CtrlState == TCPIP_STATE_ONLINE)
                    {
                        Result = E_OK; /* Can only request onhold from online */
                    }
                    break;
            }
        }
        else
        {
            /* Already in current state */
            Result = E_OK;
        }

        if(Result == E_OK)
        {
            TcpIp_CtrlStatus[CtrlIdx].ReqCtrlState = State;
        }
    }

#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_REQUESTCOMMODE_API, ErrorId);
    }
#else
    TCPIP_DUMMY_STATEMENT(ErrorId);
#endif
    return Result;       
}

/********************************************************************************************************************
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
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_RequestIpAddrAssignment
(
    TcpIp_LocalAddrIdType LocalAddrId,
    TcpIp_IpAddrAssignmentType Type,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) LocalIpAddrPtr,
    uint8 Netmask,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) DefaultRouterPtr
)
{
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    struct netif *pNetif;
    ip_addr_t Ipaddr;
    ip_addr_t LocalNetmask; 
    ip_addr_t GwAddr;
    Std_ReturnType Result=E_NOT_OK;
    uint8 CtrlId;
    if (TRUE != TcpIp_InitStatus )
    {
        ErrorId = TCPIP_E_UNINIT;
    }
    else
    {
        /* Initialize the address */
        Ipaddr.addr = 0;
        LocalNetmask.addr = 0;
        GwAddr.addr = 0;
        /* Get the local address config */
        if(TcpIp_VerifyLocalAddrId(LocalAddrId) != E_NOT_OK)
        {
            CtrlId = TcpIp_CfgGetLocalAddrConfigCtrlConfigId(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId);
            pNetif = &TcpIp_CtrlStatus[CtrlId].TcpIpNetif;
            if(TCPIP_AUTOMATIC == TcpIp_CfgGetLocalAssignmentTrigger(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId))
            {
                Result = E_NOT_OK;
            }
            else
            {
                /* Static address config */
                if(Type == TCPIP_IPADDR_ASSIGNMENT_STATIC) 
                {   
                    if(TRUE == TcpIp_CfgGetLocalAddrTcpIpStaticIpAddrValid(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId))
                    {
                        Ipaddr.addr = TcpIp_CfgGetLocalAddrTcpIpStaticIpAddress(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId);
                        GwAddr.addr = TcpIp_CfgGetLocalAddrTcpIpDefaultRouter(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId);
                        TcpIp_Ip4NetmaskToIpAddr(&LocalNetmask,
                                            TcpIp_CfgGetLocalAddrTcpIpNetmask(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId));
                    }
                    else
                    {
                        /* Convert address and netmask */
                        // TcpIp_IpAddr8to32(LocalIpAddrPtr->addr,&Ipaddr.addr);
                        // TcpIp_Ip4NetmaskToIpAddr(&LocalNetmask, Netmask);
                        // TcpIp_IpAddr8to32(DefaultRouterPtr->addr,&GwAddr.addr);
                        /* #! Todo update the configuration */
                        //pLocalAddrConfig->StaticIpAddrConfig->StaticIpAddress = Ipaddr.addr;
                        // pLocalAddrConfig->StaticIpAddrConfig->DefaultRouter = GwAddr.addr;
                        // pLocalAddrConfig->StaticIpAddrConfig->Netmask = Netmask;
                    } /* Valid local address check */
                } /* Static Assignment check */
                
                /* If multicast address is added , then update the ethernet if layer about the multicast */
                if(ip_addr_ismulticast(&Ipaddr))
                {                    
                    Result = TcpIp_ChangePhysAddrFilterForMulticast(CtrlId,Ipaddr.addr, ETH_ADD_TO_FILTER);
                }
                else
                { /* if Unicast address , the update the Lwip stack */
                    if( TRUE == LwIP_AddNetIf(&Ipaddr, &LocalNetmask, &GwAddr, ethernetif_init,  netif_input, pNetif))
                    {
                        Result = E_OK;
                        /* update the current local address configuration for the controller */
                        TcpIp_CtrlStatus[CtrlId].pLocalUnicastAddr = TcpIp_CfgGetLocalAddrConfig(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId);
                        /* Check for assignment type */
                        if( (Type == TCPIP_IPADDR_ASSIGNMENT_DHCP) || 
                            (Type == TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP) || 
                            (Type == TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL) )
                        {
                            if(Type == TCPIP_IPADDR_ASSIGNMENT_DHCP)
                            {
                                #if LWIP_DHCP
                                /* If assignment type is DHCP, then request LwIp Dhcp to start */
                                if(ERR_OK != dhcp_start(pNetif))
                                {
                                    Result = E_NOT_OK;
                                }
                                #endif
                            }

                            if ((Type == TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP) || 
                                (Type == TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL))
                            {
                                /* If assignment type is local link , then request LwIp AutoIp to start */
                                if (LWIP_DHCP_AUTOIP_COOP == 0u) /* dhcp_start will call autoip_start */
                                { 
                                    #if LWIP_AUTOIP
                                    if(ERR_OK != autoip_start(pNetif))
                                    {
                                        Result = E_NOT_OK;
                                    }
                                    #endif
                                }
                            }
                        }
                        else if(Type == TCPIP_IPADDR_ASSIGNMENT_STATIC) 
                        {
                            /* If assignment type is static , then start the Ip */
                            netif_set_up(pNetif);
                        }
                        else
                        {
                            Result = E_NOT_OK;
                        }/* Type Check */
                    } 
                    else
                    {
                        Result = E_NOT_OK;
                    }/* LwIP_AddNetIf check */
                } /* ip_addr_ismulticast check */
            }/* Assignment trigger check */ 
        } /* TcpIp_VerifyLocalAddrId */
        else
        {
            ErrorId = TCPIP_E_ADDRNOTAVAIL; 
        } 
    }
#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_REQUESTIPADDRASSIGNMENT_API, ErrorId);
    }
#else
    TCPIP_DUMMY_STATEMENT(ErrorId);
#endif
    return Result;
}
/********************************************************************************************************************
*   @brief      By this API service the local IP address assignment for the IP address specified by LocalAddrId
*               shall be released.
*   @param[in]  LocalAddrId  IP address index specifying the IP address for which an assignment shall be released.
*   @return     E_OK: The request has been accepted E_NOT_OK: The request has not been accepted
*   @ServiceID  0x0B
*   @Sync/Async Asynchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_ReleaseIpAddrAssignment(TcpIp_LocalAddrIdType LocalAddrId)
{
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    Std_ReturnType Result=E_NOT_OK;

    if (TRUE != TcpIp_InitStatus )
    {
        ErrorId = TCPIP_E_UNINIT;
    }
    else
    {
        /* Get the local address config */
        if(TcpIp_VerifyLocalAddrId(LocalAddrId) != E_NOT_OK)
        {
            /* Check for assignment triger, if automatic request is invalid */
            if(TCPIP_AUTOMATIC == TcpIp_CfgGetLocalAssignmentTrigger(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId))
            {
                Result = E_NOT_OK;
            }
            else
            {
                Result = TcpIp_RelIpAddrAssignment(LocalAddrId);
            }
        }
        else
        {
            ErrorId = TCPIP_E_ADDRNOTAVAIL;
            Result = E_NOT_OK;
        }
    }
#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_RELEASEIPADDRASSIGNMENT_API, ErrorId);
    }
#else
    TCPIP_DUMMY_STATEMENT(ErrorId);
#endif
    return Result;
}
/********************************************************************************************************************
*   @brief      Resets all learned IP-addresses to invalid values.
*   @return     E_OK: success E_NOT_OK: switch port could not be initialized
*   @ServiceID  0x1B
*   @Sync/Async Synchronous /Asynchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_ResetIpAssignment(void)
{
    /* !TODO: Reset Ip assignment to be implemented */
    return E_OK;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_IcmpTransmit
(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) RemoteAddrPtr,
    uint8 Ttl,
    uint8 Type,
    uint8 Code,
    uint16 DataLength,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) DataPtr
)
{
    /* !TODO: IcmpV4 Transmit to be implemented */
    TCPIP_DUMMY_STATEMENT(LocalIpAddrId);
    TCPIP_DUMMY_STATEMENT(RemoteAddrPtr);
    TCPIP_DUMMY_STATEMENT(Ttl);
    TCPIP_DUMMY_STATEMENT(Type);
    TCPIP_DUMMY_STATEMENT(Code);
    TCPIP_DUMMY_STATEMENT(DataLength);
    TCPIP_DUMMY_STATEMENT(DataPtr);
    return E_OK;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_IcmpV6Transmit
(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) RemoteAddrPtr,
    uint8 HopLimit,
    uint8 Type,
    uint8 Code,
    uint16 DataLength,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) DataPtr
)
{
    /* !TODO: IcmpV6 Transmit to be implemented */
    TCPIP_DUMMY_STATEMENT(LocalIpAddrId);
    TCPIP_DUMMY_STATEMENT(RemoteAddrPtr);
    TCPIP_DUMMY_STATEMENT(HopLimit);
    TCPIP_DUMMY_STATEMENT(Type);
    TCPIP_DUMMY_STATEMENT(Code);
    TCPIP_DUMMY_STATEMENT(DataLength);
    TCPIP_DUMMY_STATEMENT(DataPtr);
    return E_OK;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_DhcpReadOption
(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    uint8 Option,
    P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) DataLength,
    P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) DataPtr
)
{
    /* !TODO: DhcpV4 Read Option to be implemented */
    TCPIP_DUMMY_STATEMENT(LocalIpAddrId);
    TCPIP_DUMMY_STATEMENT(Option);
    TCPIP_DUMMY_STATEMENT(DataLength);
    TCPIP_DUMMY_STATEMENT(DataPtr);
    
    return E_OK;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_DhcpV6ReadOption
(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    uint16 Option,
    P2VAR(uint16,AUTOMATIC,TCPIP_APPL_DATA) DataLength,
    P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) DataPtr
)
{
    /* !TODO: DhcpV6 Read Option to be implemented */
    TCPIP_DUMMY_STATEMENT(LocalIpAddrId);
    TCPIP_DUMMY_STATEMENT(Option);
    TCPIP_DUMMY_STATEMENT(DataLength);
    TCPIP_DUMMY_STATEMENT(DataPtr);
    
    return E_OK;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_DhcpWriteOption
(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    uint8 Option,
    uint8 DataLength,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) DataPtr
)
{
    /* !TODO: DhcpV4 Read Option to be implemented */
    TCPIP_DUMMY_STATEMENT(LocalIpAddrId);
    TCPIP_DUMMY_STATEMENT(Option);
    TCPIP_DUMMY_STATEMENT(DataLength);
    TCPIP_DUMMY_STATEMENT(DataPtr);
    
    return E_OK;

}
/********************************************************************************************************************
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
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_DhcpV6WriteOption
(
    TcpIp_LocalAddrIdType LocalIpAddrId,
    uint16 Option,
    uint16 DataLength,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) DataPtr
)
{
    /* !TODO: DhcpV Read Option to be implemented */
    TCPIP_DUMMY_STATEMENT(LocalIpAddrId);
    TCPIP_DUMMY_STATEMENT(Option);
    TCPIP_DUMMY_STATEMENT(DataLength);
    TCPIP_DUMMY_STATEMENT(DataPtr);
    
    return E_OK;

}
/********************************************************************************************************************
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
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_ChangeParameter
(
    TcpIp_SocketIdType SocketId,
    TcpIp_ParamIdType ParameterId,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) ParameterValue
)
{
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    Std_ReturnType Result = E_NOT_OK;
            
    if (TRUE != TcpIp_InitStatus )
    {
        ErrorId = TCPIP_E_UNINIT;
    }
    else if (TCPIP_NUM_OF_SOCKETS <= SocketId)
    {
        ErrorId = TCPIP_E_INV_ARG;
    }
    else
    {
        TCPIP_DUMMY_STATEMENT(SocketId);
        TCPIP_DUMMY_STATEMENT(ParameterId);
        TCPIP_DUMMY_STATEMENT(ParameterValue);
        Result = E_OK;
    }

#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_CHANGEPARAMETER_API, ErrorId);
    }
#else
    TCPIP_DUMMY_STATEMENT(ErrorId);
#endif
    return Result;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_GetIpAddr
(
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_DATA) IpAddrPtr,
    P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) NetmaskPtr,
    P2VAR(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_DATA) DefaultRouterPtr
)
{
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    Std_ReturnType Result = E_NOT_OK;
    if (TRUE != TcpIp_InitStatus )
    {
        ErrorId = TCPIP_E_UNINIT;
    }
    else if ((NULL_PTR == IpAddrPtr) || (NULL_PTR == NetmaskPtr) || (NULL_PTR == DefaultRouterPtr))
    {
        ErrorId = TCPIP_E_PARAM_POINTER;
    }
    else
    {
        /* Get the Local address configuration  */
        if(TcpIp_VerifyLocalAddrId(LocalAddrId) != E_NOT_OK)
        {
            /* Check for valid domain */
            if ((IpAddrPtr->Domain == TcpIp_CfgGetLocalAddrConfigDomainType(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId)) &&
                (DefaultRouterPtr->Domain == TcpIp_CfgGetLocalAddrConfigDomainType(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId)))
            {
                IpAddrPtr->SockAddrInetType.Addr[0] = TcpIp_CfgGetLocalAddrTcpIpStaticIpAddress(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId);
                DefaultRouterPtr->SockAddrInetType.Addr[0] = TcpIp_CfgGetLocalAddrTcpIpStaticIpAddress(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId);
                *NetmaskPtr = TcpIp_CfgGetLocalAddrTcpIpNetmask(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId);
                Result = E_OK;
            }
            else
            {
                ErrorId = TCPIP_E_INV_ARG;
            }
        }
        else
        {
            ErrorId = TCPIP_E_ADDRNOTAVAIL;
        }
    }

#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_GETIPADDR_API, ErrorId);
    }
#else
    TCPIP_DUMMY_STATEMENT(ErrorId);
#endif
    return Result;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_GetPhysAddr
(
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) PhysAddrPtr
)
{
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    Std_ReturnType Result = E_NOT_OK;
    if (TRUE != TcpIp_InitStatus )
    {
        ErrorId = TCPIP_E_UNINIT;
    }
    else if (NULL_PTR == PhysAddrPtr)
    {
        ErrorId = TCPIP_E_PARAM_POINTER;
    }
    else
    {
        /* Get the Local address configuration  */
        if(TcpIp_VerifyLocalAddrId(LocalAddrId) != E_NOT_OK)
        {
            /* Get physical address from configure Eth ctrl */
            EthIf_GetPhysAddr(TcpIp_CfgGetLocalAddrConfigCtrlConfigId(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId), PhysAddrPtr);
            Result = E_OK;
        }
        else
        {
            ErrorId = TCPIP_E_ADDRNOTAVAIL; 
        }
    }
    
#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_GETPHYSADDR_API, ErrorId);
    }
#else
    TCPIP_DUMMY_STATEMENT(ErrorId);
#endif
    return Result;
}
/********************************************************************************************************************
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
FUNC(TcpIp_ReturnType,TCPIP_CODE) TcpIp_GetRemotePhysAddr
(
    uint8 CtrlIdx,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) IpAddrPtr,
    P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) PhysAddrPtr,
    boolean initRes
)
{
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    TcpIp_ReturnType Result = TCPIP_E_NOT_OK;
    struct eth_addr* pEthAddr;
    const ip_addr_t* pIpAddr;
    ip_addr_t IpAddr;
    struct netif *pNetIf;
    if (TRUE != TcpIp_InitStatus )
    {
        ErrorId = TCPIP_E_UNINIT;
    }
    else if ((NULL_PTR == IpAddrPtr) || (NULL_PTR == PhysAddrPtr))
    {
        ErrorId = TCPIP_E_PARAM_POINTER;
    }
    else
    {
        /* get the u32 ip address */
        IpAddr.addr = IpAddrPtr->SockAddrInetType.Addr[0];
        pNetIf = &TcpIp_CtrlStatus[CtrlIdx].TcpIpNetif;
        /* Request Lwip ARP to find the Ethaddr */
        if (etharp_find_addr(pNetIf, &IpAddr, &pEthAddr, &pIpAddr) > -1)
        {
            /* If the physical address is already known, PhysAddrPtr shall be set to the related
                physical address and the function shall return with TCPIP_E_OK */
            memcpy(PhysAddrPtr,pEthAddr->addr, ETHARP_HWADDR_LEN);
            Result = TCPIP_E_OK;
        }
        else
        {
            /* Otherwise it shall (a) initiate an address resolution if parameter initRes is set to
               TRUE and (b) return with TCPIP_E_PHYS_ADDR_MISS. PhysAddrPtr is not updated in this case. */
            Result = TCPIP_E_PHYS_ADDR_MISS;
            if(TRUE == initRes)
            {
                /* Initate address resolution to LWIP ARP */
                if((err_t)ERR_OK != etharp_query(pNetIf, &IpAddr, NULL_PTR))
                {
                    ErrorId = TCPIP_E_INV_ARG;
                }
            }
        }
    }

#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_GETREMOTEPHYSADDR_API, ErrorId);
    }
#else
    TCPIP_DUMMY_STATEMENT(ErrorId);
#endif
    return Result;
}
/********************************************************************************************************************
*   @brief      TcpIp_GetCtrlIdx returns the index of the controller related to LocalAddrId.
*   @param[in]  LocalAddrId Local address identifier implicitely specifing the EthIf controller that shall be returned.
*   @param[out] CtrlIdxPtr Pointer to the memory where the index of the controller related to LocalAddrId is stored
*   @return     Result of operation E_OK the request was successful E_NOT_OK the request was not successful
*   @ServiceID  0x17
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_GetCtrlIdx
(
    TcpIp_LocalAddrIdType LocalAddrId,
    P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) CtrlIdxPtr
)
{
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    Std_ReturnType Result=E_NOT_OK;
    if (TRUE != TcpIp_InitStatus )
    {
        ErrorId = TCPIP_E_UNINIT;
    }
    else if (NULL_PTR == CtrlIdxPtr)
    {
        ErrorId = TCPIP_E_PARAM_POINTER;
    }
    else
    {
        if(TcpIp_VerifyLocalAddrId(LocalAddrId) != E_NOT_OK)
        {
            *CtrlIdxPtr = TcpIp_CfgGetLocalAddrConfigCtrlConfigId(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId);
            Result=E_OK;
        }
        else
        {
            ErrorId = TCPIP_E_ADDRNOTAVAIL; 
        }
    }

#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_GETCTRLIDX_API, ErrorId);
    }
#else
    TCPIP_DUMMY_STATEMENT(ErrorId);
#endif
    return Result;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_GetArpCacheEntries
(
    uint8 ctrlIdx,
    P2VAR(uint32,AUTOMATIC,TCPIP_APPL_DATA) numberOfElements,
    P2VAR(TcpIp_ArpCacheEntryType,AUTOMATIC,TCPIP_APPL_DATA) entryListPtr
)
{
    /* !TODO: Get Arp Cache Entries to be implemented */
    TCPIP_DUMMY_STATEMENT(ctrlIdx);
    TCPIP_DUMMY_STATEMENT(numberOfElements);
    TCPIP_DUMMY_STATEMENT(entryListPtr);
    
    return E_OK;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_GetNdpCacheEntries
(
    uint8 ctrlIdx,
    P2VAR(uint32,AUTOMATIC,TCPIP_APPL_DATA) numberOfElements,
    P2VAR(TcpIp_NdpCacheEntryType,AUTOMATIC,TCPIP_APPL_DATA) entryListPtr
)
{
    /* !TODO: Get Ndp Cache Entries to be implemented */
    TCPIP_DUMMY_STATEMENT(ctrlIdx);
    TCPIP_DUMMY_STATEMENT(numberOfElements);
    TCPIP_DUMMY_STATEMENT(entryListPtr);
    
    return E_OK;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_GetAndResetMeasurementData
(
    TcpIp_MeasurementIdxType MeasurementIdx,
    boolean MeasurementResetNeeded,
    P2VAR(uint32,AUTOMATIC,TCPIP_APPL_DATA) MeasurementDataPtr
)
{
    /* !TODO: Get Ndp Cache Entries to be implemented */
    TCPIP_DUMMY_STATEMENT(MeasurementIdx);
    TCPIP_DUMMY_STATEMENT(MeasurementResetNeeded);
    TCPIP_DUMMY_STATEMENT(MeasurementDataPtr);
    
    return E_OK;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_UdpTransmit
(
    TcpIp_SocketIdType SocketId,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) DataPtr,
    P2CONST(TcpIp_SockAddrType,AUTOMATIC,TCPIP_APPL_CONST) RemoteAddrPtr,
    uint16 TotalLength
)
{
    uint8  CtrlIdx;
    uint16 Length = TotalLength;
    uint16 CopyLength = TotalLength;
    uint16 LenToCpy = 0;
    struct pbuf *pBuffer;
    struct pbuf *qBuffer;
    ip_addr_t IpAddr;
    uint8 OwnerId;
    Std_ReturnType Result = E_NOT_OK;
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    
    if (TRUE != TcpIp_InitStatus )
    {
        ErrorId = TCPIP_E_UNINIT;
    }
    else if (TCPIP_NUM_OF_SOCKETS <= SocketId)
    {
        ErrorId = TCPIP_E_INV_ARG;
    }
    else if (NULL_PTR == RemoteAddrPtr)
    {
        ErrorId = TCPIP_E_PARAM_POINTER;
    }
    else if (0 > TcpIp_SocketStatus[SocketId].Handle)
    {
        ErrorId = TCPIP_E_NOTCONN;
    }
    else
    {
        if (TcpIp_SocketStatus[SocketId].State  == TCPIP_SOCKET_UDP_READY)
        {
            CtrlIdx = TcpIp_SocketStatus[SocketId].pLocalAddr->CtrlConfigId;
            if (TcpIp_CtrlStatus[CtrlIdx].CtrlState  == TCPIP_STATE_ONLINE)
            {
                pBuffer = pbuf_alloc(PBUF_TRANSPORT, Length, PBUF_POOL);
                if (NULL_PTR == pBuffer)
                {
                    ErrorId = TCPIP_E_NOBUFS;
                }
                qBuffer = pBuffer;
                if (NULL_PTR != pBuffer)
                {
                    if (NULL_PTR != DataPtr)
                    {
                        memcpy(pBuffer->payload, DataPtr, Length);
                    }
                    else
                    {
                        OwnerId = TcpIp_SocketStatus[SocketId].OwnerId;
                        if(NULL_PTR != TcpIp_CfgGetUpCopyTxDataFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId))
                        {
                            Result = E_OK;
                            while (CopyLength > 0 && qBuffer != NULL_PTR)
                            {
                                LenToCpy = (CopyLength < qBuffer->len) ? CopyLength:qBuffer->len;
                                if (TcpIp_CfgGetUpCopyTxDataFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId)(SocketId,
                                     (uint8 *)qBuffer->payload, LenToCpy) != BUFREQ_OK )
                                {
                                    ErrorId = TCPIP_E_NOBUFS;
                                    Result = E_NOT_OK;
                                    //pbuf_free(qBuffer);
                                    pbuf_free(pBuffer);
                                    break;
                                }
                                qBuffer = qBuffer->next;
                                CopyLength -= LenToCpy;
                            }
                        }
                        else
                        {
                            Result = E_NOT_OK;
                            ErrorId = TCPIP_E_NOBUFS;
                        }
                    }
                    IpAddr.addr =  RemoteAddrPtr->SockAddrInetType.Addr[0];
                    if ((Result == E_OK ) &&
                        (ERR_OK == udp_sendto(TcpIp_SocketStatus[SocketId].pvPcbAddr, pBuffer, &IpAddr,
                                    (RemoteAddrPtr->SockAddrInetType.Port))))
                    {
                        Result = E_OK;
                    }
                    pbuf_free(pBuffer);
                }
                else
                {
                    // For anything other than err_ok socket shall be closed gracefully.
                    udp_remove(TcpIp_SocketStatus[SocketId].pvPcbAddr);
                    (void)TcpIp_Close(SocketId,FALSE);
                }
            }/* (BufferResponse == BUFREQ_OK) */
        } /* (TcpIp_CtrlStatus[CtrlIdx].CtrlState  == TCPIP_STATE_ONLINE) */
    } /* if (TcpIp_SocketStatus[SocketId].State  == TCPIP_SOCKET_UDP_READY) */

#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
        TcpIp_DetReportError(TCPIP_UDPTRANSMIT_API, ErrorId);
    }
#else
    TCPIP_DUMMY_STATEMENT(ErrorId);
#endif
    return Result;
}
/********************************************************************************************************************
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
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_TcpTransmit
(
    TcpIp_SocketIdType SocketId,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) DataPtr,
    uint32 AvailableLength,
    boolean ForceRetrieve
)
{
    uint8  CtrlIdx;
    uint16 TcpSndWndlen = 0;
    struct pbuf*  pBuffer = NULL;
    struct pbuf*  qBuffer = NULL;
    Std_ReturnType Result = E_NOT_OK;
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    uint16 Length = AvailableLength;
    uint16 CopyLen = AvailableLength;
    uint16 LenToCopy = 0;
    uint8 OwnerId;

    if (TRUE != TcpIp_InitStatus )
    {
        ErrorId = TCPIP_E_UNINIT;
    }
    else if (TCPIP_NUM_OF_SOCKETS <= SocketId)
    {
        ErrorId = TCPIP_E_INV_ARG;
    }
    else if (0 > TcpIp_SocketStatus[SocketId].Handle)
    {
        ErrorId = TCPIP_E_NOTCONN;
    }
    else
    {
        /* get tcpip ctrl index */
        CtrlIdx = TcpIp_SocketStatus[SocketId].pLocalAddr->CtrlConfigId;
        if (TcpIp_CtrlStatus[CtrlIdx].CtrlState  == TCPIP_STATE_ONLINE)
        {
            TcpSndWndlen = tcp_sndbuf((struct tcp_pcb *)TcpIp_SocketStatus[SocketId].pvPcbAddr);

            if (TcpSndWndlen < AvailableLength)
            {
                CopyLen = TcpSndWndlen;
                Length = TcpSndWndlen;
            }
            
            /* malloc buffer */
            pBuffer = pbuf_alloc(PBUF_TRANSPORT, Length, PBUF_POOL);
            qBuffer = pBuffer;
            if (NULL != DataPtr)
            {
                memcpy(pBuffer, DataPtr, Length);
            }
            else
            {
                //Ask SoAD to fill buffer with data
                OwnerId = TcpIp_SocketStatus[SocketId].OwnerId;
                if ( NULL_PTR != TcpIp_CfgGetUpCopyTxDataFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId))
                {
                    Result = E_OK;
                    /* Get the TCP send window length */
                    while (CopyLen > 0 && qBuffer != NULL)
                    {
                        LenToCopy = (CopyLen < qBuffer->len) ? CopyLen:qBuffer->len;
                        if (TcpIp_CfgGetUpCopyTxDataFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId)(SocketId,
                             (uint8 *)qBuffer->payload, LenToCopy) != BUFREQ_OK)
                        {
                            pbuf_free(pBuffer);
                            ErrorId = TCPIP_E_NOBUFS;
                            break;
                        }
                        qBuffer = qBuffer->next;
                        CopyLen -= LenToCopy;
                    }
                } 
                else
                {
                    Length = 0;
                    ErrorId = TCPIP_E_NOBUFS;
                }
            }

            if (Length > 0)
            {
                if (ERR_OK == tcp_write(TcpIp_SocketStatus[SocketId].pvPcbAddr, pBuffer->payload, Length, TCP_WRITE_FLAG_COPY))
                {
                     Result = E_OK;
                }
                else
                {
                    (void)TcpIp_Close(SocketId,FALSE);
                }
                /* Call tcp_ouput to send data which is being queued in lwip */
                if (ERR_OK == tcp_output(TcpIp_SocketStatus[SocketId].pvPcbAddr))
                {
                    Result = E_OK;
                }
                else
                {
                    (void)TcpIp_Close(SocketId,FALSE);
                }
            }
            else if (TcpSndWndlen == 0)
            {
                // Wait until send buffer is available
                Result = E_OK;		
            }
            else
            {
                /* Do Nothing */
            }

            if (pBuffer != NULL && pBuffer->ref == 1)
            {
                (void)pbuf_free(pBuffer);
                pBuffer = NULL;
            }
        } 
    }

#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_TCPTRANSMIT_API, ErrorId);
    }
#else
    TCPIP_DUMMY_STATEMENT(ErrorId);
#endif

    TCPIP_DUMMY_STATEMENT(ForceRetrieve);
    return Result;
}
/********************************************************************************************************************
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
FUNC(void,TCPIP_CODE) TcpIp_RxIndication
(
    uint8 CtrlIdx,
    Eth_FrameType FrameType,
    boolean IsBroadcast,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) PhysAddrPtr,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) DataPtr,
    uint16 LenByte
)
{
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    if(TcpIp_InitStatus != TRUE)
    {
        ErrorId = TCPIP_E_UNINIT;
    }
    else if ((NULL_PTR == PhysAddrPtr) || (NULL_PTR == DataPtr))
    {
        ErrorId = TCPIP_E_PARAM_POINTER;
    }
    else
    {
        LwIp_RxIndication(CtrlIdx,FrameType,IsBroadcast,PhysAddrPtr,(Eth_DataType *)DataPtr,LenByte);
    }
#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_RXINDICATION_API, ErrorId);
    }
#else
    TCPIP_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      Schedules the TCP/IP stack. (Entry point for scheduling)
*   @ServiceID  0x15
********************************************************************************************************************/
FUNC(void,TCPIP_CODE) TcpIp_MainFunction(void)
{
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    if(TcpIp_InitStatus != TRUE)
    {
        ErrorId = TCPIP_E_UNINIT;
    }
    else
    {           
        /* process the controller states */
        TcpIp_CtrlStateHandling();
        /* process the socket states */
        TcpIp_SocketStateHandling();
    }
#if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_MAINFUNCTION_API, ErrorId);
    }
#else
    TCPIP_DUMMY_STATEMENT(ErrorId);
#endif
}

/********************************************************************************************************************
*   @brief      By this API service the TCP/IP stack is requested to allocate a new socket. Note: Each accepted 
*               incoming TCP connection also allocates a socket resource.
*   @param[in]  SocketOwnerId Id identifying the socket owner
*   @param[in]  Domain IP address family.
*   @param[in]  protocol Socket protocol as sub-family of parameter type.
*   @param[out] SocketIdPtr Pointer to socket identifier representing the requested socket. This socket identifier 
*               must be provided for all further API calls which requires a SocketId. 
*               Note: SocketIdPtr is only valid if return value is E_OK.
*   @return     Result of operation 
*               E_OK The request has been accepted 
*               E_NOT_OK The request has not been accepted: no free socket  
*   @ServiceID  0x03
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_GetSocket
(
    uint8 SocketOwnerId,
    TcpIp_DomainType Domain, 
    TcpIp_ProtocolType Protocol, 
    P2VAR(TcpIp_SocketIdType,AUTOMATIC,TCPIP_APPL_DATA) SocketIdPtr
)
{
    TcpIp_SocketIdType SocketId;
    Std_ReturnType Result = E_NOT_OK;
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    
    if (TRUE != TcpIp_InitStatus )
    {
        ErrorId = TCPIP_E_UNINIT;
    }
    else if (SocketIdPtr  == NULL_PTR)
    {
        ErrorId = TCPIP_E_PARAM_POINTER;
    }
    else if (Domain != TCPIP_AF_INET)
    {
        ErrorId = TCPIP_E_AFNOSUPPORT;
    }
    else if ((TCPIP_IPPROTO_UDP != Protocol) && (TCPIP_IPPROTO_TCP != Protocol))
    {
        ErrorId = TCPIP_E_NOPROTOOPT;
    }
    else
    {
        
        /* If valid LwIp socket found , then get the TcpIp socket and bind the TcpIp socket to LwIp socket */ 
        if(E_OK == TcpIp_GetFirstFreeSocket(&SocketId))
        {
            /* Get the socket type for the protocol */
            if (TCPIP_IPPROTO_TCP == Protocol) 
            {
                TcpIp_SocketStatus[SocketId].pvPcbAddr = (void *)tcp_new();
                /*Register the argument to be alled by callback funtions*/
                tcp_arg(TcpIp_SocketStatus[SocketId].pvPcbAddr, &(TcpIp_SocketStatus[SocketId]));
                /*Register callback to be called when tcp  data sent is acknowledged by remote host*/
                tcp_sent(TcpIp_SocketStatus[SocketId].pvPcbAddr, tcp_sent_cb_fn);
                /*Register callback to be called for error */
                tcp_err(TcpIp_SocketStatus[SocketId].pvPcbAddr,tcp_error_fn);
            } 
            else
            {
                TcpIp_SocketStatus[SocketId].pvPcbAddr = (void *)udp_new();
                udp_recv(TcpIp_SocketStatus[SocketId].pvPcbAddr, udp_recv_cb_fn, &(TcpIp_SocketStatus[SocketId]));
            }
            if (TcpIp_SocketStatus[SocketId].pvPcbAddr != NULL_PTR)
            {
                /* Socket assigned, get first free socket index */
                TcpIp_SocketStatus[SocketId].Handle = SocketId;
                TcpIp_SocketStatus[SocketId].OwnerId = SocketOwnerId;
                TcpIp_SocketStatus[SocketId].State = TCPIP_SOCKET_BIND;
                TcpIp_SocketStatus[SocketId].ProtocolIsTcp = ((TCPIP_IPPROTO_TCP == Protocol) ? TRUE:FALSE );
                *SocketIdPtr = SocketId;
                Result = E_OK;
            }
        }
    }
    
    #if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_GETSOCKET_API, ErrorId);
    }
    #else
    TCPIP_DUMMY_STATEMENT(ErrorId);
    #endif
   
    return Result;
}
/********************************************************************************************************************
*  PRIVATE FUNCTION IMPLEMENTATION                                                                                  *
********************************************************************************************************************/
/********************************************************************************************************************
*   @brief      This service is to intialize the LWIP stack  
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) TcpIp_LwIPInit(void)
{    
#if (MEM_LIBC_MALLOC==0)
    mem_init();
#endif
#if (MEMP_MEM_MALLOC==0)
    memp_init();
#endif
}

/********************************************************************************************************************
*   @brief      This service is to process the socket states
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_SocketStateHandling(void)
{
    TcpIp_SocketIdType SocketId;
    for (SocketId = 0; SocketId < TCPIP_NUM_OF_SOCKETS; SocketId++) 
    {
        switch (TcpIp_SocketStatus[SocketId].State)
        {
            case TCPIP_SOCKET_TCP_LISTENING: /* handle socket tcp listening state */
                TcpIp_HandleSocketStateListening(SocketId);
                /* check error status and close the socket if needed */
                if(TcpIp_SocketStatus[SocketId].Handle != -1)
                {
                    TcpIp_SocketStatusCheck(SocketId);
                }
                break;

            case TCPIP_SOCKET_TCP_CONNECTING: /* handle socket tcp connecting state */
                TcpIp_HandleSocketStateConnecting(SocketId);
                break;

            case TCPIP_SOCKET_TCP_READY: /* handle socket tcp ready state */
                TcpIp_HandleSocketStateTcpReady(SocketId);
                /* check error status and close the socket if needed */
                if(TcpIp_SocketStatus[SocketId].Handle != -1)
                {
                    TcpIp_SocketStatusCheck(SocketId);
                }
                break;

            case TCPIP_SOCKET_UDP_READY: /* handle socket udp ready state */
                TcpIp_HandleSocketStateUdpReady(SocketId);
                /* check error status and close the socket if needed */
                if(TcpIp_SocketStatus[SocketId].Handle != -1)
                {
                    TcpIp_SocketStatusCheck(SocketId);
                }
                break;

            default:
                /* Do nothing */
                break;
        }
    }
}

/********************************************************************************************************************
*   @brief      This service is to process the controller state handling
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_CtrlStateHandling(void)
{
    uint8 CtrlIdx;
    /* Process the current ctrl states */
    for(CtrlIdx=0; CtrlIdx < TCPIP_NUM_OF_CONTROLLERS; CtrlIdx++)
    {
        switch (TcpIp_CtrlStatus[CtrlIdx].CtrlState)
        {
            case TCPIP_STATE_OFFLINE: /* Handle the Ctrl offline state */
                TcpIp_HandleStateOffline(CtrlIdx);
                break;
            case TCPIP_STATE_ONLINE: /* Handle the Ctrl online state */
                TcpIp_HandleStateOnline(CtrlIdx);
                break;
            case TCPIP_STATE_ONHOLD: /* Handle the Ctrl onhold state */
                TcpIp_HandleStateOnhold(CtrlIdx);
                break;
            case TCPIP_STATE_STARTUP: /* Handle the Ctrl startup state */
                TcpIp_HandleStateStartup(CtrlIdx);
                break;
            case TCPIP_STATE_SHUTDOWN: /* Handle the Ctrl shutdown state */
                TcpIp_HandleStateShutdown(CtrlIdx);
                break;
            default:
                break;
        }
    }
}

/* #! Socket state handling */
/********************************************************************************************************************
*   @brief      This service is to process the tcp socket Listening state
*   @param[in]  SocketId Socket Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_HandleSocketStateListening(TcpIp_SocketIdType SocketId)
{
#if LWIP_NO_SYS 
    sint32 ClientFd;
    sint32 SetFlag = 1;
    struct sockaddr_in ClientAddr;
    TcpIp_SocketIdType AvailSocketId;
    uint8 OwnerId;
    uint32 Addrlen = sizeof(ClientAddr);

    /* Get the socket fd and process it if its valid */
    ClientFd = accept(TcpIp_SocketStatus[SocketId].Handle, (struct sockaddr *)&ClientAddr, (socklen_t *)&Addrlen);
    if( ClientFd != (-1))
    {
        /* Get the available socket and update the processing state */
        if(E_OK == TcpIp_GetFirstFreeSocket(&AvailSocketId))
        {
            TcpIp_SocketStatus[AvailSocketId].Handle = ClientFd;
            TcpIp_SocketStatus[AvailSocketId].RemoteAddr.SockAddrInetType.Domain = ClientAddr.sin_family;
            TcpIp_SocketStatus[AvailSocketId].RemoteAddr.SockAddrInetType.Port = ntohs(ClientAddr.sin_port);
            ClientAddr.sin_addr.s_addr = TcpIp_SocketStatus[AvailSocketId].RemoteAddr.SockAddrInetType.Addr[0];
            TcpIp_SocketStatus[AvailSocketId].OwnerId = TcpIp_SocketStatus[SocketId].OwnerId;
            OwnerId = TcpIp_SocketStatus[AvailSocketId].OwnerId;

            /* Notify socket owner about the socket accept  */
            if(TcpIp_CfgGetUpTcpAcceptedFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId) != NULL_PTR)
            {
                if(E_OK == TcpIp_CfgGetUpTcpAcceptedFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId)(SocketId,
                                                     AvailSocketId, &TcpIp_SocketStatus[AvailSocketId].RemoteAddr))
                {
                    TcpIp_SocketStatus[AvailSocketId].State = TCPIP_SOCKET_TCP_READY;
                    TcpIp_SocketStatus[AvailSocketId].ProtocolIsTcp = TRUE;
                    /* Get local addr from listening socket */
                    TcpIp_SocketStatus[AvailSocketId].pLocalAddr = TcpIp_SocketStatus[SocketId].pLocalAddr;
                    /* update the socket in non block mode */
                    (void)ioctlsocket(ClientFd, FIONBIO, &SetFlag);
                }
                else
                {
                    /* if not accepted by socket owner, then free the lwip socket id and the TcpIp socket */
                    (void)closesocket(ClientFd);
                    TcpIp_FreeUpSocket(AvailSocketId);
                }
            }
        }
        else
        {
            /* If No TcpIp socket available , then close the lwip socket */
            (void)closesocket(ClientFd);
        } /* E_OK == TcpIp_GetFirstFreeSocket(&AvailSocketId) */
    }
#endif
}

/********************************************************************************************************************
*   @brief      This service is to process the tcp socket connecting state
*   @param[in]  SocketId Socket Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE)  TcpIp_HandleSocketStateConnecting(TcpIp_SocketIdType SocketId)
{
#if LWIP_NO_SYS
    sint32 SocketError;
    boolean IsConnected = FALSE;
    boolean CloseSocketReq = FALSE;
    uint8 OwnerId;
    
    /* get the socket error */
    SocketError = lwip_geterr(TcpIp_SocketStatus[SocketId].Handle);
    OwnerId = TcpIp_SocketStatus[SocketId].OwnerId;
    switch(SocketError)
    {
        case 0:
            IsConnected = TRUE;
            break;
        case ERR_INPROGRESS:
            /* Trying to connect*/
            break;

        case ERR_ABRT:
        case ERR_RST:
        case ERR_CLSD:
            CloseSocketReq = TRUE;
            break;
        default:
           break;
    }

    if(CloseSocketReq == TRUE)
    {
        /* If socket close requested,then close the socket and notify the event to the socket owner */
        (void)closesocket(TcpIp_SocketStatus[SocketId].Handle);
        if(TcpIp_CfgGetUpTcpIpEventFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId) != NULL_PTR)
        {
            TcpIp_CfgGetUpTcpIpEventFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId)(SocketId, TCPIP_TCP_CLOSED);
        }
        TcpIp_FreeUpSocket(SocketId);
    }
    else if(IsConnected == TRUE)
    {
        /* If socket connected ,then notify the connection to the socket owner */
        TcpIp_SocketStatus[SocketId].State = TCPIP_SOCKET_TCP_READY;
        if(TcpIp_CfgGetUpTcpConnectedFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId) != NULL_PTR)
        {
            TcpIp_CfgGetUpTcpConnectedFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId)(SocketId);
        }
    }
    else
    {
        /* Do nothing */
    }
#endif
}

/********************************************************************************************************************
*   @brief      This service is to process the tcp socket ready state
*   @param[in]  SocketId Socket Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_HandleSocketStateTcpReady(TcpIp_SocketIdType SocketId)
{
#if LWIP_NO_SYS
    uint8 *pDataBuffer;
    sint32 NumOfBytes = 1;
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    uint8 OwnerId;
    /* In ready state process the data received for tcp socket */
    OwnerId = TcpIp_SocketStatus[SocketId].OwnerId;
    while(NumOfBytes > 0)
    {
        if (TRUE == TcpIp_BufferGet(TCPIP_RX_BUFFER_SIZE, &pDataBuffer)) 
        {
            NumOfBytes = recv(TcpIp_SocketStatus[SocketId].Handle, pDataBuffer, TCPIP_RX_BUFFER_SIZE, 0);
            if (NumOfBytes > 0)
            {
                /* Notify the socket owner about the data reception */
                if(TcpIp_CfgGetUpRxIndicationUpFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId) != NULL_PTR)
                {
                    TcpIp_CfgGetUpRxIndicationUpFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId)(SocketId, 
                            &TcpIp_SocketStatus[SocketId].RemoteAddr, pDataBuffer, NumOfBytes);
                }
            }
            else if(NumOfBytes == 0)
            {
            	/* If no data pending then close the socket and notify the event to socket owner */
                (void)closesocket(TcpIp_SocketStatus[SocketId].Handle);
                if(TcpIp_CfgGetUpTcpIpEventFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId) != NULL_PTR)
                {
                    TcpIp_CfgGetUpTcpIpEventFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId)(SocketId, TCPIP_TCP_CLOSED);
                }
                TcpIp_FreeUpSocket(SocketId);
            }
            else
            {
                /* Nothing received */
            }
            TcpIp_BufferFree(pDataBuffer);
        }
        else
        {
            /* Buffer not available */
            NumOfBytes = 0;
            ErrorId = TCPIP_E_NOBUFS;
        }
    } /* (NumOfBytes > 0) */
    
    #if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_GETVERSIONINFO_API, ErrorId);
    }
    #else
    TCPIP_DUMMY_STATEMENT(ErrorId);
    #endif
#endif
}

/********************************************************************************************************************
*   @brief      This service is to process the tcp socket ready state
*   @param[in]  SocketId Socket Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_HandleSocketStateUdpReady(TcpIp_SocketIdType SocketId)
{
#if LWIP_NO_SYS
    uint8 ErrorId=TCPIP_E_NO_ERROR;
    uint8 *pDataBuffer;
    sint32 NumOfBytes = 1;
    struct sockaddr_in SourceAddr;
    TcpIp_SockAddrType RemoteAddr;
    uint8 OwnerId;
    uint32 SourceAddrLen = sizeof(SourceAddr);
    
    /* In ready state process the data received for udp socket */
    while(NumOfBytes > 0)
    {
        if (TRUE == TcpIp_BufferGet(TCPIP_RX_BUFFER_SIZE, &pDataBuffer)) 
        {
            NumOfBytes = recvfrom(TcpIp_SocketStatus[SocketId].Handle, pDataBuffer, 
                                TCPIP_RX_BUFFER_SIZE, 0, (struct sockaddr*)&SourceAddr, (socklen_t *)&SourceAddrLen);
            if (NumOfBytes > 0)
            {
                /* update the remote address for udp socket */
                RemoteAddr.SockAddrInetType.Domain = SourceAddr.sin_family;
                RemoteAddr.SockAddrInetType.Port = ntohs(SourceAddr.sin_port);
                RemoteAddr.SockAddrInetType.Addr[0] = SourceAddr.sin_addr.s_addr;
                /* Notify the socket owner about the data reception */
                OwnerId = TcpIp_SocketStatus[SocketId].OwnerId;
                if(TcpIp_CfgGetUpRxIndicationUpFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId) != NULL_PTR)
                {
                    TcpIp_CfgGetUpRxIndicationUpFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId)(SocketId, &RemoteAddr,
                                                        pDataBuffer, NumOfBytes);
                }
            }
            TcpIp_BufferFree(pDataBuffer);
        }
        else
        {
            /* Buffer not available */
            NumOfBytes = 0;
            ErrorId = TCPIP_E_NOBUFS;
        }
    }
    
    #if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_GETVERSIONINFO_API, ErrorId);
    }
    #else
    TCPIP_DUMMY_STATEMENT(ErrorId);
    #endif
#endif
}

/* #! TcpIP state Handling */
/********************************************************************************************************************
*   @brief      This service is to process the tcp ctrl offline state
*   @param[in]  CtrlIdx Ctrl Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_HandleStateOffline(uint8 CtrlIdx)
{
    if(TcpIp_CtrlStatus[CtrlIdx].ReqCtrlState == TCPIP_STATE_ONLINE)
    {
        /* If TCPIP_STATE_ONLINE is requested for an EthIf controller and the current state is TCPIP_STATE_OFFLINE
        for that EthIf controller, the TcpIp module shall
        (a) enable all IP address assignments according to the configured assignment
        methods (TcpIpAssignmentMethod) and triggers (TcpIpAssignmentTrigger) for
        that EthIf controller. (Note: If the assignment trigger is configured to
        TCPIP_MANUAL no assignment is actually performed but initiation by the upper
        layer enabled) and */
        TcpIp_EnableAllIpAddrAssignments(CtrlIdx);
        /* (b) enter the state TCPIP_STATE_STARTUP for the EthIf controller. */
        TcpIp_SwitchEthIfCtrlState(CtrlIdx, TCPIP_STATE_STARTUP);
    }
    else if(TcpIp_CtrlStatus[CtrlIdx].ReqCtrlState == TCPIP_STATE_ONHOLD)
    {
        /* Invalid state , so set to Offline */
        TcpIp_CtrlStatus[CtrlIdx].ReqCtrlState = TCPIP_STATE_OFFLINE;
    }
    else
    {
        /* Do nothing */
    }
}

/********************************************************************************************************************
*   @brief      This service is to process entry to the tcp ctrl offline state
*   @param[in]  CtrlIdx Ctrl Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_EnterOfflineState(uint8 CtrlIdx)
{
    TcpIp_SocketIdType SocketId;
    boolean CloseSocketInOtherCtrl = FALSE;
    /* If TCPIP_STATE_OFFLINE is requested or all assigned IP address have been released for an EthIf controller 
     and the current state is TCPIP_STATE_ONLINE or TCPIP_STATE_ONHOLD for that EthIf controller, the TcpIp module 
     shall */
    /* (a) call Up_LocalIpAddrAssignmentChg() with State TCPIP_IPADDR_STATE_UNASSIGNED for all assigned IP addresses 
    of the related EthIf controller, */
    TcpIp_NotifyLocalIpAddrAssignmentChg(CtrlIdx, TCPIP_IPADDR_STATE_UNASSIGNED);
    /* (b) deactivate the communication within the TcpIp module for the related EthIf controller, */
    /* (c) release related resources, i.e. any socket using the EthIf controller shall be closed and thereafter any 
       IP address assigned to the EthIf controller shall be unassigned,*/
    for(SocketId=0; SocketId < TCPIP_NUM_OF_SOCKETS; SocketId++)
    {
        if((TcpIp_SocketStatus[SocketId].pLocalAddr != NULL_PTR) && 
           (TcpIp_SocketStatus[SocketId].pLocalAddr->CtrlConfigId == CtrlIdx))
        {
            (void)TcpIp_Close(SocketId,FALSE);
        }
    }
    /* (d) in case the no EthIf controller is assigned any more, all unbound sockets shall
    be released as well */
    for(SocketId=0; SocketId < TCPIP_NUM_OF_SOCKETS; SocketId++)
    {
       if(TcpIp_SocketStatus[SocketId].pLocalAddr != NULL_PTR)
       {
           /* There are sockets assigned to other ctrl's */
           CloseSocketInOtherCtrl = TRUE;
           break;
       }
    }
    if(CloseSocketInOtherCtrl == TRUE)
    {
        /* There are no other assigned controllers, release all unbound sockets */
        for(SocketId=0; SocketId < TCPIP_NUM_OF_SOCKETS; SocketId++)
        {
            if(TcpIp_SocketStatus[SocketId].Handle >= 0)
            {
                (void)TcpIp_Close(SocketId,FALSE);
            }
        }
    }
    TcpIp_DisableAllIpAddrAssignments(CtrlIdx);
    /* (e) enter the state TCPIP_STATE_SHUTDOWN for the EthIf controller. */
    TcpIp_SwitchEthIfCtrlState(CtrlIdx, TCPIP_STATE_SHUTDOWN);
}

/********************************************************************************************************************
*   @brief      This service is to process the tcp ctrl Online state
*   @param[in]  CtrlIdx Ctrl Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_HandleStateOnline(uint8 CtrlIdx)
{
    if(TcpIp_CtrlStatus[CtrlIdx].ReqCtrlState == TCPIP_STATE_OFFLINE)
    {
        TcpIp_EnterOfflineState(CtrlIdx);
    }
    else if(TcpIp_CtrlStatus[CtrlIdx].ReqCtrlState == TCPIP_STATE_ONHOLD)
    {
        /* If TCPIP_STATE_ONHOLD is requested for an EthIf controller and the current state is TCPIP_STATE_ONLINE 
        for that EthIf controller, the TcpIp module shall
        (a) notify the upper layer via Up_LocalIpAddrAssignmentChg() with State TCPIP_IPADDR_STATE_ONHOLD for all 
        assigned IP addresses of the related EthIf controller, */
        netif_set_down(&TcpIp_CtrlStatus[CtrlIdx].TcpIpNetif);
        /* (b) deactivate the communication within the TcpIp module for the related EthIf controller, and */
        TcpIp_NotifyLocalIpAddrAssignmentChg(CtrlIdx, TCPIP_IPADDR_STATE_ONHOLD);
        /* (c) enter the state TCPIP_STATE_ONHOLD for the EthIf controller.*/
        TcpIp_SwitchEthIfCtrlState(CtrlIdx, TCPIP_STATE_ONHOLD);
    }
    else
    {
        /* Do nothing */
    }
}

/********************************************************************************************************************
*   @brief      This service is to process the tcp ctrl Onhold state
*   @param[in]  CtrlIdx Ctrl Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_HandleStateOnhold(uint8 CtrlIdx)
{

    if(TcpIp_CtrlStatus[CtrlIdx].ReqCtrlState == TCPIP_STATE_OFFLINE)
    {
        TcpIp_EnterOfflineState(CtrlIdx);
    }
    else if(TcpIp_CtrlStatus[CtrlIdx].ReqCtrlState == TCPIP_STATE_ONLINE)
    {
       /* If TCPIP_STATE_ONLINE is requested for an EthIf controller and the current state is TCPIP_STATE_ONHOLD 
       for that EthIf controller, the TcpIp module shall
        (a) reactivate the communication within the TcpIp module for the related EthIf controller, */
        netif_set_up(&TcpIp_CtrlStatus[CtrlIdx].TcpIpNetif);
        /* (b) call Up_LocalIpAddrAssignmentChg() with State TCPIP_IPADDR_STATE_ASSIGNED for all assigned IP addresses 
        of the elated EthIf controller, and */
        TcpIp_NotifyLocalIpAddrAssignmentChg(CtrlIdx, TCPIP_IPADDR_STATE_ASSIGNED);
        /* (c) enter the state TCPIP_STATE_ONLINE for the EthIf controller. */
        TcpIp_SwitchEthIfCtrlState(CtrlIdx, TCPIP_STATE_ONLINE);
    }
    else
    {
        /* Do nothing */
    }
}

/********************************************************************************************************************
*   @brief      This service is to process the tcp ctrl Startup state
*   @param[in]  CtrlIdx Ctrl Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_HandleStateStartup(uint8 CtrlIdx)
{
    if(TcpIp_CtrlStatus[CtrlIdx].ReqCtrlState == TCPIP_STATE_OFFLINE)
    {
        /* If TCPIP_STATE_OFFLINE is requested for an EthIf controller and the current state is TCPIP_STATE_STARTUP 
        for that EthIf controller, the TcpIp module shall
        (a) abort all ongoing IP address assignment actions appropriate and */
        TcpIp_DisableAllIpAddrAssignments(CtrlIdx);
        /* (b) enter the state TCPIP_STATE_OFFLINE for the EthIf controller. */
        TcpIp_SwitchEthIfCtrlState(CtrlIdx, TCPIP_STATE_OFFLINE);
    }
    else if(TcpIp_CtrlStatus[CtrlIdx].ReqCtrlState == TCPIP_STATE_ONLINE)
    {
        /* If at least one IP address has been successfully assigned to an EthIf controller and the current state is 
        TCPIP_STATE_STARTUP for that EthIf controller, the TcpIp module shall enter the state TCPIP_STATE_ONLINE for 
        the EthIf controller.*/
        if(TRUE == TcpIp_CtrlStatus[CtrlIdx].LinkUp)
        {
            /* (b) enter the state TCPIP_STATE_OFFLINE for the EthIf controller. */
            TcpIp_SwitchEthIfCtrlState(CtrlIdx, TCPIP_STATE_ONLINE);
            TcpIp_NotifyLocalIpAddrAssignmentChg(CtrlIdx, TCPIP_IPADDR_STATE_ASSIGNED);
        }
    }
    else
    {
        /* Do nothing */
    }
}

/********************************************************************************************************************
*   @brief      This service is to process the tcp ctrl Startup state
*   @param[in]  CtrlIdx Ctrl Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_HandleStateShutdown(uint8 CtrlIdx)
{
    /* If the current state of an EthIf controller is TCPIP_STATE_SHUTDOWN and all related resources have been 
    released, the TcpIp module shall enter the state TCPIP_STATE_OFFLINE for the EthIf controller.*/
    TcpIp_SwitchEthIfCtrlState(CtrlIdx, TCPIP_STATE_OFFLINE);
}

/* #! Address Assignment */
/********************************************************************************************************************
*   @brief      This service is to enable all the Ip address assignment 
*   @param[in]  CtrlIdx Ctrl Id to be processed
*   @param[in]  CtrlIdx Ctrl Ip address state
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) TcpIp_NotifyLocalIpAddrAssignmentChg(uint8 CtrlIdx, TcpIp_IpAddrStateType IpAddrState)
{
    /* Call upper layer */
    TcpIp_SocketIdType SocketId;
    TcpIp_LocalAddrIdType LocalAddrId;
    uint8 OwnerId;
    
    for(LocalAddrId=0; LocalAddrId < TCPIP_NUM_OF_LOCALADDR; LocalAddrId++)
    {
        if(TcpIp_CfgGetLocalAddrConfigCtrlConfigId(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId) == CtrlIdx)
        {
            /* Notify to all socket owners of this controller */
            for(SocketId=0; SocketId < TCPIP_NUM_OF_SOCKETS; SocketId++)
            {
                OwnerId = TcpIp_SocketStatus[SocketId].OwnerId;
                if(TcpIp_CfgGetUpLocalIpAddrAssignmentFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId) != NULL_PTR)
                {
                    TcpIp_CfgGetUpLocalIpAddrAssignmentFunc(TcpIp_CfgGetTcpIpConfigPtr(),OwnerId)(
                               TcpIp_CfgGetLocalAddrConfigAddrId(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId),
                                                                                        IpAddrState);
                }
            }
        }
    }
}

/********************************************************************************************************************
*   @brief      This service is to enable all the Ip address assignment 
*   @param[in]  CtrlIdx Ctrl Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_EnableAllIpAddrAssignments(uint8 CtrlIdx)
{
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    TcpIp_LocalAddrIdType LocalAddrId;
    /* We initiate all unicast first and then any multicast */
    for(LocalAddrId=0; LocalAddrId<TCPIP_NUM_OF_LOCALADDR; LocalAddrId++)
    {
        if((TcpIp_CfgGetLocalAddrConfigCtrlConfigId(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId) == CtrlIdx) && 
           (TcpIp_CfgGetLocalAssignmentTrigger(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId) == TCPIP_AUTOMATIC) &&
           (TcpIp_CfgGetLocalAddrConfigAddrType(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId) == TCPIP_UNICAST))
        {
            if(E_NOT_OK == TcpIp_AutomaticIpAddrAssignment(LocalAddrId))
            {
                /* Automatic address failed for this local address */
                ErrorId = TCPIP_E_ADDRNOTAVAIL; 
                break;
            }
        }
    }
    /* multicast address initialization */
    for(LocalAddrId =0; LocalAddrId<TCPIP_NUM_OF_LOCALADDR;LocalAddrId++)
    {
        if((TcpIp_CfgGetLocalAddrConfigCtrlConfigId(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId) == CtrlIdx) &&
           (TcpIp_CfgGetLocalAssignmentTrigger(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId) == TCPIP_AUTOMATIC) &&
           (TcpIp_CfgGetLocalAddrConfigAddrType(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId) == TCPIP_MULTICAST))
        {
            if(E_NOT_OK == TcpIp_AutomaticIpAddrAssignment(LocalAddrId))
            {
                /* Automatic address failed for this local address */
                ErrorId = TCPIP_E_ADDRNOTAVAIL; 
                break;
            }
        }
    }
    
    #if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_MAINFUNCTION_API, ErrorId);
    }
    #else
    TCPIP_DUMMY_STATEMENT(ErrorId);
    #endif
}

/********************************************************************************************************************
*   @brief      This service is to enable all the Ip address assignment 
*   @param[in]  CtrlIdx Ctrl Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_DisableAllIpAddrAssignments(uint8 CtrlIdx)
{
    uint8 ErrorId = TCPIP_E_NO_ERROR;
    TcpIp_LocalAddrIdType LocalAddrId;
    
    /* We initiate all unicast first and then any multicast. We assume there is only one */
    for(LocalAddrId =0; LocalAddrId<TCPIP_NUM_OF_LOCALADDR; LocalAddrId++)
    {
        if((TcpIp_CfgGetLocalAddrConfigCtrlConfigId(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId) == CtrlIdx) && 
           (TcpIp_CfgGetLocalAssignmentTrigger(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId) == TCPIP_AUTOMATIC) &&
           (TcpIp_CfgGetLocalAddrConfigAddrType(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId) == TCPIP_UNICAST))
        {
            if(E_NOT_OK == TcpIp_RelIpAddrAssignment(LocalAddrId))
            {
                /* Automatic address failed for this local address */
                ErrorId = TCPIP_E_ADDRNOTAVAIL; 
                break;
            }
        }
    }
    /* multicast address unassignement */
    for(LocalAddrId=0; LocalAddrId<TCPIP_NUM_OF_LOCALADDR;LocalAddrId++)
    {
        if((TcpIp_CfgGetLocalAddrConfigCtrlConfigId(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId) == CtrlIdx) && 
           (TcpIp_CfgGetLocalAssignmentTrigger(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId) == TCPIP_AUTOMATIC) &&
           (TcpIp_CfgGetLocalAddrConfigAddrType(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId) == TCPIP_MULTICAST))
        {
            if(E_NOT_OK == TcpIp_RelIpAddrAssignment(LocalAddrId))
            {
                /* Automatic address failed for this local address */
                ErrorId = TCPIP_E_ADDRNOTAVAIL; 
                break;
            }
        }
    }
    
    #if (TCPIP_DEV_ERROR_DETECT == STD_ON)
    if (TCPIP_E_NO_ERROR != ErrorId)
    {
      TcpIp_DetReportError(TCPIP_MAINFUNCTION_API, ErrorId);
    }
    #else
    TCPIP_DUMMY_STATEMENT(ErrorId);
    #endif
}

/********************************************************************************************************************
*   @brief      This service is to process the automatic address assignment
*   @param[in]  LocalAddrId Ctrl Id to be processed
*   @param[in]  Type Ctrl Id to be processed
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_AutomaticIpAddrAssignment
(
    TcpIp_LocalAddrIdType LocalAddrId
)
{
    Std_ReturnType Result = E_OK;
    ip_addr_t IpAddr;
    ip_addr_t NetMask;
    ip_addr_t GwAddr;
    uint8 CtrlId;
    struct netif *pNetif = &TcpIp_CtrlStatus[TcpIp_CfgGetLocalAddrConfigCtrlConfigId(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId)].TcpIpNetif;
    TcpIp_IpAddrAssignmentType Type = TcpIp_CfgGetLocalAssignmentMethod(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId);
    /* Initialize the address */
    IpAddr.addr = 0;
    NetMask.addr = 0;
    GwAddr.addr = 0;

    /* If static assignment is configured then update address configuration */
    if(Type == TCPIP_IPADDR_ASSIGNMENT_STATIC) 
    {
        if(TRUE == TcpIp_CfgGetLocalAddrTcpIpStaticIpAddrValid(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId))
        {
            IpAddr.addr = TcpIp_CfgGetLocalAddrTcpIpStaticIpAddress(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId);
            GwAddr.addr = TcpIp_CfgGetLocalAddrTcpIpDefaultRouter(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId);
            TcpIp_Ip4NetmaskToIpAddr(&NetMask, TcpIp_CfgGetLocalAddrTcpIpNetmask(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId));
        }
        else
        {
            Result = E_NOT_OK;
        }
    }

    if(Result == E_OK)
    {
        CtrlId = TcpIp_CfgGetLocalAddrConfigCtrlConfigId(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId);
        if(ip_addr_ismulticast(&IpAddr))
        {
            /* If multicast address is added , then update the ethernet if layer about the multicast */
            Result = TcpIp_ChangePhysAddrFilterForMulticast(CtrlId,IpAddr.addr, ETH_ADD_TO_FILTER);
        }
        else
        { 
            /* if Unicast address , the update the Lwip stack */
            if(TRUE == LwIP_AddNetIf(&IpAddr, &NetMask, &GwAddr, ethernetif_init, netif_input, pNetif))
            { 
                /* update the current local address configuration for the controller */
                TcpIp_CtrlStatus[CtrlId].pLocalUnicastAddr = TcpIp_CfgGetLocalAddrConfig(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId);
                /* Check for assignment type */
                if( (Type == TCPIP_IPADDR_ASSIGNMENT_DHCP) ||
                    (Type == TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP) ||
                    (Type == TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL) )
                {
                    if(Type == TCPIP_IPADDR_ASSIGNMENT_DHCP)
                    {
                        #if LWIP_DHCP
                        /* If assignment type is DHCP, then request LwIp Dhcp to start */
                        if(ERR_OK != dhcp_start(pNetif))
                        {
                            Result = E_NOT_OK;
                        }
                        #endif
                    }

                    if ((Type == TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP) || (Type == TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL))
                    {
                        if (LWIP_DHCP_AUTOIP_COOP == 0u) /* dhcp_start will call autoip_start */
                        {
                            #if LWIP_AUTOIP
                            /* If assignment type is local link , then request LwIp AutoIp to start */
                            if(ERR_OK != autoip_start(pNetif))
                            {
                                Result = E_NOT_OK;
                            }
                            #endif
                        }
                    }
                }
                else if(Type == TCPIP_IPADDR_ASSIGNMENT_STATIC) 
                {
                    /* If assignment type is static , then start the Ip */
                    netif_set_up(pNetif);
                }
                else
                {
                    Result = E_NOT_OK;
                } /* Type check */
            }
            else
            {
                Result = E_NOT_OK;
            } /* LwIP_AddNetIf status check */
        } /* ip_addr_ismulticast */
    }

    return Result;
}

/********************************************************************************************************************
*   @brief This service is to release the assigned ip address and reques the LwIp stack to release the assigned the
*   ip address
*   @param[in] pLocalAddrConfig pointer to the local address configuration
*   @return status of the request E_OK: ip address release request accepted 
    E_NOT_OK: ip address release request not accepted
********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_RelIpAddrAssignment
(
    TcpIp_LocalAddrIdType LocalAddrId
)
{
    Std_ReturnType Result = E_OK;
    uint8 CtrlId;
    ip_addr_t Ipaddr;
    struct netif *pNetif = &TcpIp_CtrlStatus[TcpIp_CfgGetLocalAddrConfigCtrlConfigId(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId)].TcpIpNetif;
    TcpIp_IpAddrAssignmentType Type = TcpIp_CfgGetLocalAssignmentMethod(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId);

    Ipaddr.addr =TcpIp_CfgGetLocalAddrTcpIpStaticIpAddress(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId);
    CtrlId = TcpIp_CfgGetLocalAddrConfigCtrlConfigId(TcpIp_CfgGetTcpIpConfigPtr(),LocalAddrId);
    /* Check for Multicast address */
    if(ip_addr_ismulticast(&Ipaddr))
    {
        /* In case a multicast address is assigned, TcpIp shall update the Eth MAC address filter by calling 
        EthIf_UpdatePhysAddrFilter() with action set to ETH_REMOVE_FROM_FILTER. */
        Result = TcpIp_ChangePhysAddrFilterForMulticast(CtrlId, Ipaddr.addr, ETH_REMOVE_FROM_FILTER);
    }
    else
    { 
        /* check for assignment type */
        if( (Type == TCPIP_IPADDR_ASSIGNMENT_DHCP) || 
            (Type == TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP) || 
            (Type == TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL) )
        {
            if(Type == TCPIP_IPADDR_ASSIGNMENT_DHCP)
            {
                /* if type is Dhcp , then release and stop the Lwip Dhcp */
                #if LWIP_DHCP
                (void)dhcp_release(pNetif);
                dhcp_stop(pNetif);
                #endif
            }

            if ((Type == TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL_DOIP) || (Type == TCPIP_IPADDR_ASSIGNMENT_LINKLOCAL))
            {
                /* if type is local link , then stop the Lwip auto Ip */
                if (LWIP_DHCP_AUTOIP_COOP == 0u)
                { 
                    #if LWIP_AUTOIP
                    (void)autoip_stop(pNetif);
                    #endif
                }
            }
        }
        else if (Type == TCPIP_IPADDR_ASSIGNMENT_STATIC) 
        {
            /* if type is static , then request the Lwip to remove the ip address */
            netif_remove(pNetif); 
        }
        else
        {
            Result = E_NOT_OK;
        } /* Type check */
    } /* Multicast address */

    return Result;
}

/********************************************************************************************************************
*   @brief      By this API service the TCP/IP stack gets an indication and the data of a received frame.
*   @param[in]  CtrlIdx Index of the EthIf controller.
*   @param[in]  FrameType frame type of received Ethernet frame
*   @param[in]  IsBroadcast parameter to indicate a broadcast frame
*   @param[in]  PhysAddrPtr pointer to Physical source address (MAC address in network byte order) of
*               received Ethernet frame
*   @param[in]  DataPtr Pointer to payload of the received Ethernet frame (i.e. Ethernet header is not provided).
*   @param[in]  LenByte Length of received data.
********************************************************************************************************************/
TCPIP_LOCAL_INLINE FUNC(void,TCPIP_CODE) LwIp_RxIndication
(
    uint8 CtrlIdx,
    Eth_FrameType FrameType,
    boolean IsBroadcast,
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) PhysAddrPtr,
    P2CONST(Eth_DataType,AUTOMATIC,TCPIP_APPL_CONST) DataPtr,
    uint16 LenByte
)
{
    struct pbuf *pBuffer, *qBuffer;
    struct netif * pNetIf;
	uint16 TempFrameType = PP_HTONS(FrameType);
    uint8 uiMacAddr[TCPIP_ETH_MAC_ADDR_SIZE] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    err_t ErroResult;
	uint16 CopyLen = LenByte;
	uint16 LenToCopy = 0;
    
    pBuffer = pbuf_alloc(PBUF_RAW, LenByte+TCPIP_ETH_HEADER_SIZE, PBUF_POOL);
    qBuffer = pBuffer;
    if (pBuffer != NULL)
    {
        if(IsBroadcast == FALSE)
        {
            EthIf_GetPhysAddr(CtrlIdx,uiMacAddr);
            memcpy((uint8*)pBuffer->payload,uiMacAddr,TCPIP_ETH_MAC_ADDR_SIZE);
        }
        else
        {
            memcpy((uint8*)pBuffer->payload,uiMacAddr,TCPIP_ETH_MAC_ADDR_SIZE);
        }
        memcpy((uint8*)pBuffer->payload+TCPIP_ETH_MAC_ADDR_SIZE,PhysAddrPtr,TCPIP_ETH_MAC_ADDR_SIZE);
        memcpy((uint8*)pBuffer->payload+(2*TCPIP_ETH_MAC_ADDR_SIZE),(void*)&TempFrameType,
            TCPIP_ETH_FRAMETYPE_SIZE);
        LenToCopy = ((CopyLen < PBUF_POOL_BUFSIZE - TCPIP_ETH_HEADER_SIZE) ? CopyLen:(PBUF_POOL_BUFSIZE - TCPIP_ETH_HEADER_SIZE));
        memcpy((uint8*)pBuffer->payload+TCPIP_ETH_HEADER_SIZE, DataPtr, LenToCopy);
        DataPtr += LenToCopy;
        CopyLen -= (LenToCopy);
        while(CopyLen > 0 && qBuffer->next != NULL)
        {
            qBuffer=qBuffer->next;
            memcpy(qBuffer->payload, DataPtr, LenToCopy = (CopyLen < PBUF_POOL_BUFSIZE) ? CopyLen:PBUF_POOL_BUFSIZE);
            DataPtr += LenToCopy;
            CopyLen -= LenToCopy;
        }
        pNetIf = &TcpIp_CtrlStatus[CtrlIdx].TcpIpNetif;
        if(pNetIf->input != NULL)
        {
            ErroResult = pNetIf->input(pBuffer, pNetIf);
            if((err_t)ERR_OK != ErroResult)
            {
                (void)pbuf_free(pBuffer);
            }
        }
        else
        {
            (void)pbuf_free(pBuffer);
        }
        qBuffer = NULL;
        if (pBuffer != NULL && pBuffer->ref == 1)
        {
            (void)pbuf_free(pBuffer);
            pBuffer = NULL;
        }
    }
    else
    {
        /* Do Nothing */
    }    
}

/********************************************************************************************************************
*   @brief This service is to set up the network interface of the Lwip stack
*   @param[in] ipaddr ipv4 address
*   @param[in] netmask ipv4 netmask
*   @param[in] gw ipv4 gateway address
*   @param[in] initFnc Init function of LwIp protocol
*   @param[in] inputFnc input function of LwIp protocol
*   @param[in] netif netif struc to be updated to LwIP stack
*   @return status of the request TRUE: Request accepted FALSE: Request not accepted
********************************************************************************************************************/
TCPIP_LOCAL FUNC(boolean,TCPIP_CODE) LwIP_AddNetIf
( 
    P2CONST(ip_addr_t,AUTOMATIC,TCPIP_APPL_CONST) pIpAddr, 
    P2CONST(ip_addr_t,AUTOMATIC,TCPIP_APPL_CONST) pNetMask, 
    P2CONST(ip_addr_t,AUTOMATIC,TCPIP_APPL_CONST) pGwAddr, 
    netif_init_fn pInitFnc,
    netif_input_fn pInputFnc,
    struct netif *pNetIf
)
{
    boolean Result=TRUE;
    /* Add network interface to the netif_list */
    if(NULL_PTR == netif_add(pNetIf, pIpAddr, pNetMask, pGwAddr, NULL_PTR, pInitFnc, pInputFnc))
    {
        Result = FALSE;
    }
    if (TRUE == Result) 
    {
        /*  Registers the default network interface.*/
        netif_set_default(pNetIf);
#if LWIP_NETIF_STATUS_CALLBACK
        netif_set_status_callback(pNetIf, LwIP_StatusCallback);
#endif

#if LWIP_NETIF_HOSTNAME
        netif_set_hostname(pNetIf, "LWIP"); 
#endif
    }
    return Result;
}

/********************************************************************************************************************
*   @brief This service is to get the local address id configuration
*   @param[in] LocalAddrId Local address id
*   @return E_OK if the configuration is found E_NOT_OK if configuration is not found
********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_VerifyLocalAddrId
(
    TcpIp_LocalAddrIdType AddressId
)
{
    TcpIp_LocalAddrIdType LocalAddrId =0;
    Std_ReturnType IdStatus = E_NOT_OK;
    for (LocalAddrId = 0; LocalAddrId < TCPIP_NUM_OF_LOCALADDR; LocalAddrId++) 
    {
        if (pTcpIpConfig->pLocalAddrConfig[LocalAddrId].TcpIpAddrId == AddressId) 
        {
            IdStatus = E_OK;
            break;
        }
    }
    return IdStatus;
}

/********************************************************************************************************************
*   @brief This service is to switch the ethernet controller state
*   @param[in] CtrlIdx requested controller id
*   @param[in] TcpIpState requested state
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) TcpIp_SwitchEthIfCtrlState(uint8 CtrlIdx, TcpIp_StateType TcpIpState)
{
    TcpIp_EnterCriticalSection();
    if(TcpIp_CtrlStatus[CtrlIdx].CtrlState != TcpIpState)
    {
        TcpIp_CtrlStatus[CtrlIdx].CtrlState = TcpIpState;
        /* After each transition the TcpIp module shall report new state to EthSM via EthSM_TcpIpModeIndication() */
        (void)EthSM_TcpIpModeIndication(CtrlIdx, TcpIpState);
    }
    TcpIp_ExitCriticalSection();
}

/********************************************************************************************************************
*   @brief This service is to get the available free socket id
*   @param[out] pSocketIdPtr pointer to update the socket id
*   @return status of the request E_OK Socket available E_NOT_OK Socket not available
********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_GetFirstFreeSocket(TcpIp_SocketIdType *pSocketId)
{
    Std_ReturnType Result = E_NOT_OK;
    TcpIp_SocketIdType SocketId;
    /* get the available free socket id */
    TcpIp_EnterCriticalSection();
    for(SocketId=0; SocketId < TCPIP_NUM_OF_SOCKETS; SocketId++)
    {
        if( (TcpIp_SocketStatus[SocketId].State == TCPIP_SOCKET_INIT) &&
            (TcpIp_SocketStatus[SocketId].pvPcbAddr == NULL_PTR))
        {
            *pSocketId = SocketId;
            Result = E_OK;
            break;
        }
    }
    TcpIp_ExitCriticalSection();
    return Result;
}

/********************************************************************************************************************
*   @brief This service is to re-initialize the status of the socket
*   @param[in] SocketId socket id to be reinitialized
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) TcpIp_FreeUpSocket(TcpIp_SocketIdType SocketId)
{
    /* Clear the socket status */
    TcpIp_EnterCriticalSection();
    TcpIp_SocketStatus[SocketId].State = TCPIP_SOCKET_INIT;
    TcpIp_SocketStatus[SocketId].Handle = -1;
    TcpIp_SocketStatus[SocketId].pLocalAddr = NULL_PTR;
    TcpIp_SocketStatus[SocketId].pvPcbAddr = NULL_PTR;
    TcpIp_ExitCriticalSection();
}

/********************************************************************************************************************
*   @brief      This service is to process the socket status
*   @param[in]  SocketId socket id to get the status
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) TcpIp_SocketStatusCheck(TcpIp_SocketIdType SocketId)
{
#if LWIP_NO_SYS
    sint32 SockErr;
    TcpIp_EventType Event;
    boolean IsSockCloseReq = FALSE;
    TcpIp_SocketOwnerConfigType const * pSocketOwnerConfig;
    
    /* get the socket error */
    SockErr = lwip_geterr(TcpIp_SocketStatus[SocketId].Handle);
    switch(SockErr)
    {
        /* Close socket on fatal errors */
        case ERR_ABRT:          /* Connection aborted.      */
        case ERR_RST:           /* Connection reset.        */
        case ERR_CLSD:          /* Connection closed.       */
        case ERR_ARG:           /* Illegal argument.        */
            IsSockCloseReq = TRUE;
            break;
        case 0:/* OK */
        case ERR_INPROGRESS:    /* Operation in progress    */
        case ERR_WOULDBLOCK:    /* Operation would block.   */
            break;
        case ERR_MEM:           /* Out of memory error.     */
        case ERR_BUF:           /* Buffer error.            */
        case ERR_TIMEOUT:       /* Timeout.                 */
        case ERR_RTE:           /* Routing problem.         */
        case ERR_VAL:           /* Illegal value.           */
        case ERR_USE:           /* Address in use.          */
        case ERR_ALREADY:       /* Already connecting.      */
        case ERR_ISCONN:        /* Conn already established.*/
        case ERR_CONN:          /* Not connected.           */
        case ERR_IF:            /* Low-level netif error    */
        default:
            /* Increase the error count and if the error count reaches the max count then close the socket */
            TcpIp_SocketStatus[SocketId].ErrCnt++;
            #ifdef CFG_TCPIP_DEBUG
            if(TcpIp_SocketStatus[SocketId].ErrCnt > TcpIp_SocketStatus[SocketId].ErrCntMax)
            {
                TcpIp_SocketStatus[SocketId].ErrCntMax = TcpIp_SocketStatus[SocketId].ErrCnt;
            }
            TcpIp_SocketStatus[SocketId].SockErrorsArr[TcpIp_SocketStatus[SocketId].ErrCnt] = SockErr;
            #endif
            if(TcpIp_SocketStatus[SocketId].ErrCnt >= TCPIP_NOF_ERR_BEFORE_RESET)
            {
                IsSockCloseReq = TRUE;
                TcpIp_SocketStatus[SocketId].ErrCnt = 0;
            }
            break;
    }

    if(IsSockCloseReq == TRUE)
    {
        /* If socket close is requested , then close the socket and update the socket owner about the event */
        #ifdef CFG_TCPIP_DEBUG
        TcpIp_SocketStatus[SocketId].NumofClosedSocket++;
        #endif
        (void)closesocket(TcpIp_SocketStatus[SocketId].Handle);
        if(TRUE == TcpIp_SocketStatus[SocketId].ProtocolIsTcp)
        {
            Event = TCPIP_TCP_CLOSED;
        }
        else
        {
            Event = TCPIP_UDP_CLOSED;
        }
        
        pSocketOwnerConfig = pTcpIpConfig->pSocketOwnerConfig;
        if(pSocketOwnerConfig->pSocketOwnerTcpIpEventFunc != NULL_PTR)
        {
            pSocketOwnerConfig->pSocketOwnerTcpIpEventFunc(SocketId, Event);
        }
        TcpIp_FreeUpSocket(SocketId);
    }
#endif
}

#if LWIP_NO_SYS
/********************************************************************************************************************
*   @brief This service is to get buffer from the memory pool
*   @param[in] size requested buffer size
*   @param[out] buffPtr pointer to get the allocated buffer
*   @return result of the request TRUE: Buffer is allocated and returns the address
*   FALSE: Buffer not allocated and returns NULL_PTR
********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean,TCPIP_CODE) TcpIp_BufferGet(uint32 Size, uint8** buffPtr)
{
    boolean Result = FALSE;
    /* get request buffer */
    *buffPtr = mem_malloc(Size);
    if (*buffPtr != NULL_PTR)
    {
        Result = TRUE;
    }

    return Result;
}

/********************************************************************************************************************
*   @brief This service is to free the allocated buffer
*   @param[in] CtrlIdx EthIf controller Id
********************************************************************************************************************/
LOCAL_INLINE FUNC(void,TCPIP_CODE) TcpIp_BufferFree(P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) pBuffer)
{
    mem_free(pBuffer);
}
#endif

/********************************************************************************************************************
*   @brief This service is to convert 32 bit ip address array to the 8 bit ip address
*   @param[in] CtrlIdx EthIf controller Id
*   @param[in] IpAddr 32 bit ip address
*   @param[in] Action Add or remove the address from the Ethernet controllers filter.
*   @return status of the request E_OK: filter was successfully changed E_NOT_OK: filter could not be changed
********************************************************************************************************************/
TCPIP_LOCAL FUNC(Std_ReturnType,TCPIP_CODE) TcpIp_ChangePhysAddrFilterForMulticast
(
    uint8 CtrlIdx, 
    uint32 IpAddr, 
    Eth_FilterActionType Action
)
{
    uint8 McastAddr[6];
    uint8 McastIpAddr[4];

    TcpIp_IpAddr32To8(IpAddr, McastIpAddr);
    /* Create the multicast mac address */
    McastAddr[0] = 0x01u;
    McastAddr[1] = 0x00u;
    McastAddr[2] = 0x5eu;
    McastAddr[3] = McastIpAddr[1] & 0x7fu;
    McastAddr[4] = McastIpAddr[2];
    McastAddr[5] = McastIpAddr[3];
    /* Update the lower layer with multicast mac */
    return EthIf_UpdatePhysAddrFilter(CtrlIdx, McastAddr, Action);
}

/*! Utility function */
/********************************************************************************************************************
*   @brief This service is to convert 32 bit ip address array to the 8 bit ip address
*   @param[in] src input buffer containing the 32 bit ip address
*   @param[out] dest pointer to the output buffer with the 8 bit ip address
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) TcpIp_IpAddr32To8(uint32 src, P2VAR(uint8,AUTOMATIC,TCPIP_APPL_DATA) dest)
{
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
    dest[0] = (uint8)((src & 0xff000000U) >> 24U);
    dest[1] = (uint8)((src & 0x00ff0000U) >> 16U);
    dest[2] = (uint8)((src & 0x0000ff00U) >> 8U);
    dest[3] = (uint8)(src  & 0x000000ffU);
#else
    dest[3] = (uint8)((src & 0xff000000U) >> 24U);
    dest[2] = (uint8)((src & 0x00ff0000U) >> 16U);
    dest[1] = (uint8)((src & 0x0000ff00U) >> 8U);
    dest[0] = (uint8)(src  & 0x000000ffU);
#endif
}
/********************************************************************************************************************
*   @brief This service is to convert 8 bit ip address array to the 32 bit ip  address
*   @param[in] src pointer to input buffer containing the 8 bit ip address
*   @param[out] dest pointer to the output buffer with the 32 bit ip address
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) TcpIp_IpAddr8to32
(
    P2CONST(uint8,AUTOMATIC,TCPIP_APPL_CONST) src, 
    P2VAR(uint32,AUTOMATIC,TCPIP_APPL_DATA) dest
)
{
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
    *dest = ( ((uint32)((src[0]) & 0xffU) << 24U) | ((uint32)((src[1]) & 0xffU) << 16U) | \
              ((uint32)((src[2]) & 0xffU) << 8U) | (uint32)((src[3]) & 0xffU) );
#else
    *dest = ((((uint32)src[3]) << 24u) | (((uint32)src[2]) << 16u) | (((uint32)src[1]) << 8u) | ((uint32)src[1]));
#endif
}

/********************************************************************************************************************
*   @brief This service is to convert CIDR netmask to net mask ip addr 
*   @param[in,out] NetmaskAddr pointer to buffer for updating the netmask
*   @param[in] Netmask CIDR notation of netmask
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) TcpIp_Ip4NetmaskToIpAddr
(
    P2VAR(ip_addr_t,AUTOMATIC,TCPIP_APPL_DATA) NetmaskAddr,
    uint8 Netmask
)
{
    uint8 addr[4];
    uint32 NetMask=0;

    if(Netmask >= 24U)
    {
        addr[0] = 255U;
        addr[1] = 255U;
        addr[2] = 255U;
        addr[3] = (uint8)(0xff00U >> (Netmask-24U));
    }
    else if(Netmask >= 16U)
    {
        addr[0] = 255U;
        addr[1] = 255U;
        addr[2] = (uint8)(0xff00U >> (Netmask-16U));
        addr[3] = 0U;
    }
    else if(Netmask >= 8U)
    {
        addr[0] = 255U;
        addr[1] = (uint8)(0xff00U >> (Netmask-8U));
        addr[2] = 0U;
        addr[3] = 0U;
    }
    else
    {
        addr[0] = (uint8)(0xff00U >> Netmask);
        addr[1] = 0U;
        addr[2] = 0U;
        addr[3] = 0U;
    }

    TcpIp_IpAddr8to32(&addr[0], &NetMask);
    NetmaskAddr->addr = NetMask;
}

/*! #! Lwip Callback functions */
#if LWIP_TCPIP_INIT_DONE_CALLBACK
/********************************************************************************************************************
*   @brief This service is the callback function which will be called after TcpIp stack initilisation from LwIp stack
*   @param[in] pArg pointer to the arg from the LwIp stack
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) LwIp_TcpIpInitDone(void *pArg)
{
    TcpIp_InitStatus = TRUE;
}
#endif

#if LWIP_NETIF_STATUS_CALLBACK
/********************************************************************************************************************
*   @brief This service is the callback function which will be called after after netif setup or down or link change 
*   from LwIp stack.
*   @param[in] pNetIf pointer to the NetIf struct
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) LwIP_StatusCallback(struct netif *pNetIf) 
{
    uint8 CtrlIdx;

    /* update for the controller netif struct */
    for(CtrlIdx=0; CtrlIdx < TCPIP_NUM_OF_CONTROLLERS; CtrlIdx++)
    {
        if(&TcpIp_CtrlStatus[CtrlIdx].TcpIpNetif == pNetIf)
        {
            /* #! TODO update the pointer */
            /*pLocalUnicastAddr = TcpIp_CtrlStatus[CtrlIdx].pLocalUnicastAddr;
            if( pLocalUnicastAddr != NULL_PTR)
            {
                pLocalUnicastAddr->StaticIpAddrConfig->StaticIpAddress = pNetIf->ip_addr.addr;
                pLocalUnicastAddr->StaticIpAddrConfig->DefaultRouter = pNetIf->gw.addr;
                pLocalUnicastAddr->StaticIpAddrConfig->Netmask = 32 - ilog2((ntohl(pNetIf->netmask.addr)));
                pLocalUnicastAddr->StaticIpAddrConfig->IsValid = TRUE;
            } */
            TcpIp_CtrlStatus[CtrlIdx].LinkUp = netif_is_link_up(pNetIf);
        }
    }
}  
#endif
/********************************************************************************************************************
*   @brief This service is the callback function which will be called after network interface start from LwIp stack.
*   @param[in] pNetIf pointer to the NetIf struct
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) LwIP_EthernetifStart(struct netif *pNetIf)
{
    /* TcpIp_NetIfPtrActive = pNetIf; */
}

/********************************************************************************************************************
*   @brief This service is the callback function which will be called for HW initialisation function (low level init)
*   from LwIp stack.
*   @param[in] pNetIf pointer to the NetIf struct
********************************************************************************************************************/
TCPIP_LOCAL FUNC(void,TCPIP_CODE) LwIp_EthernetifInit(struct netif *pNetIf)
{
    uint8 MacAddr[TCPIP_ETH_MAC_ADDR_SIZE] = ETH_MAC_ADDR;
    /* set MAC hardware address length */
    pNetIf->hwaddr_len = TCPIP_ETH_MAC_ADDR_SIZE;
    pNetIf->hwaddr[0] =  MacAddr[0];
    pNetIf->hwaddr[1] =  MacAddr[1];
    pNetIf->hwaddr[2] =  MacAddr[2];
    pNetIf->hwaddr[3] =  MacAddr[3];
    pNetIf->hwaddr[4] =  MacAddr[4];
    pNetIf->hwaddr[5] =  MacAddr[5];
    /* maximum transfer unit */
    pNetIf->mtu = TCPIP_MTU_SIZE;
    /* device capabilities */
    /* don't set NETIF_FLAG_ETHARP if this device is not an ethernet one */
    pNetIf->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_LINK_UP | NETIF_FLAG_IGMP;
}

/********************************************************************************************************************
*   @brief This service is the callback function which will be called at set up netif and subsequently HW 
*   initialisation.This function should be passed as a parameter to netif_add()
*   @param[in] pNetIf pointer to the NetIf struct
********************************************************************************************************************/
TCPIP_LOCAL FUNC(err_t,TCPIP_CODE) ethernetif_init(struct netif *pNetIf)
{
    err_t ErrStatus = (err_t)ERR_ARG;

    if(pNetIf != NULL_PTR)
    {
        /* Initialize the snmp variables and counters inside the struct netif. The last argument should be replaced 
        with your link speed, in units of bits per second. */
        NETIF_INIT_SNMP(pNetIf, snmp_ifType_ethernet_csmacd, 100000000);

        pNetIf->name[0] = IFNAME0;
        pNetIf->name[1] = IFNAME1;
        /* We directly use etharp_output() here to save a function call.
        * You can instead declare your own function an call etharp_output()
        * from it if you have to do some checks before sending (e.g. if link
        * is available...) */
        pNetIf->output = etharp_output;
        pNetIf->linkoutput = LwIp_Output;
        #if LWIP_IPV6
        netif->output_ip6 = ethip6_output;
        #endif /* LWIP_IPV6 */

        /* initialize the hardware */
        LwIp_EthernetifInit(pNetIf);

        LwIP_EthernetifStart(pNetIf);
        ErrStatus = (err_t)ERR_OK;
    }
    return ErrStatus;
}

/********************************************************************************************************************
*   @brief This service is the callback function which will be called for Frames Transmission function
*   @param[in] pNetIf pointer to the NetIf struct
*   @param[in] pBuffer pointer to the buffer
*   @retrun error status of the request
********************************************************************************************************************/
TCPIP_LOCAL FUNC(err_t,TCPIP_CODE) LwIp_Output
(
    P2VAR(struct netif,AUTOMATIC,TCPIP_APPL_DATA) pNetIf,
    P2VAR(struct pbuf,AUTOMATIC,TCPIP_APPL_DATA) pBuffer
)
{ 
    uint16 ReqLenByte;
    uint8 *pSrcBuffer;
    #if defined(ETH_CTRL_TX_FRAME_MIN_SIZE)
    uint16 LengthIdx;
    #endif
    uint16 TempLength = 0;
    err_t ErrStatus = E_OK;
    Eth_FrameType FrameType;
    Std_ReturnType TxStatus;
    #if (TCPIP_ETHIF_TRANSMIT_RETRY_SUPPORT == STD_ON)
    uint32 TimeCnt;
    #endif
    const struct pbuf *pTempBuffer;
    Eth_BufIdxType BufferIndex = 0;
    uint8 DestMacAdrs[TCPIP_ETH_MAC_ADDR_SIZE];
    uint8 FrameTypeBuffer[TCPIP_ETH_FRAMETYPE_SIZE];

#if ETH_PAD_SIZE
    /* drop the padding word */
    pbuf_header(pBuffer, -ETH_PAD_SIZE); 
#endif
	ReqLenByte = (pBuffer->tot_len - TCPIP_ETH_HEADER_SIZE);
	MEMCPY(FrameTypeBuffer, ((uint8*)pBuffer->payload + (2*TCPIP_ETH_MAC_ADDR_SIZE)), TCPIP_ETH_FRAMETYPE_SIZE); 
	FrameType = ((FrameTypeBuffer[0] << 8) | FrameTypeBuffer[1]); 
    MEMCPY(DestMacAdrs,(uint8*)pBuffer->payload,TCPIP_ETH_MAC_ADDR_SIZE);
#if (ETHIF_ENABLE_TX_INTERRUPT == STD_OFF)
    EthIf_MainFunctionTx(); 
#endif
    if(BUFREQ_OK != EthIf_ProvideTxBuffer(TCPIP_ETH_CTRL_INDEX,FrameType,0,&BufferIndex,&pSrcBuffer, &ReqLenByte))
    {
        /* notify error and return and  Try to increase the number of TX buffers in the Lower layer */
        ErrStatus = (err_t)ERR_MEM;
    }
    if (ErrStatus == E_OK) 
    { 
        /* Skip Ethernet header, ARP responses includes adding Ethernet header in the stack itself which is not easily
         * bypassed from the stack at the moment, response callback other than ARP can be moved to ASR TcpIp layer. */
        for(pTempBuffer = pBuffer; pTempBuffer != NULL_PTR; pTempBuffer = pTempBuffer->next)
        {
            if(TempLength == 0u)
            {
                MEMCPY(&pSrcBuffer[TempLength], ((uint8*)pTempBuffer->payload + TCPIP_ETH_HEADER_SIZE), 
                      (pTempBuffer->len - TCPIP_ETH_HEADER_SIZE));
                TempLength = (pTempBuffer->len - TCPIP_ETH_HEADER_SIZE);
            }
            else
            {
                MEMCPY(&pSrcBuffer[TempLength], (uint8*)pTempBuffer->payload, pTempBuffer->len);
                TempLength = TempLength + pTempBuffer->len;
            }
        }
        #if defined(ETH_CTRL_TX_FRAME_MIN_SIZE)
        if(TempLength < (ETH_CTRL_TX_FRAME_MIN_SIZE - TCPIP_ETH_HEADER_SIZE))
        {
            for(LengthIdx = TempLength; LengthIdx < (ETH_CTRL_TX_FRAME_MIN_SIZE - TCPIP_ETH_HEADER_SIZE); LengthIdx++)
            {
              pSrcBuffer[LengthIdx] = 0u;
            }
            TempLength = (ETH_CTRL_TX_FRAME_MIN_SIZE - TCPIP_ETH_HEADER_SIZE);
        }
        #endif
       
        /* Try to send and wait for timeout if pending , then the return timeout error */
        TxStatus = EthIf_Transmit(TCPIP_ETH_CTRL_INDEX,BufferIndex,FrameType,TRUE/*txconf*/,TempLength,DestMacAdrs);
        #if (TCPIP_ETHIF_TRANSMIT_RETRY_SUPPORT == STD_OFF)
        if (TxStatus != E_OK)
        {
            ErrStatus = ERR_IF;
        }
        #else
        TimeCnt = 0U;
        while(TxStatus != E_OK)
        {
    
            if((TimeCnt % 500U) == 0U)
            {
                #if (ETHIF_ENABLE_TX_INTERRUPT == STD_OFF)
                EthIf_MainFunctionTx();
                #endif
                TxStatus = EthIf_Transmit(TCPIP_ETH_CTRL_INDEX,BufferIndex,FrameType,TRUE,TempLength,DestMacAdrs);
            }
            TimeCnt++;
            if(TimeCnt > 1000000U)
            {
                /* timeout, notify error and return */
                ErrStatus = (err_t)ERR_TIMEOUT;
                break;
            }
        }
        #endif
        #if ETH_PAD_SIZE
        if (E_OK == ErrStatus ) 
        {
            pbuf_header(pBuffer, ETH_PAD_SIZE); /* reclaim the padding word */
        }
        #endif
    }
    TCPIP_DUMMY_STATEMENT(pNetIf);
    return ErrStatus;
} 

static void udp_recv_cb_fn(void *arg, struct udp_pcb *pcb, struct pbuf *p, const ip_addr_t *addr, u16_t port)
{
    TcpIp_SocketStatusType *pSocketStatus = (TcpIp_SocketStatusType *)arg;
    TcpIp_SockAddrType RemoteAddr;

    RemoteAddr.SockAddrInetType.Addr[0]=addr->addr;
    RemoteAddr.SockAddrInetType.Port = port;
    RemoteAddr.Domain = pSocketStatus->pLocalAddr->DomainType;
    // Send same to SoAd
    if (TcpIp_CfgGetUpRxIndicationUpFunc(TcpIp_CfgGetTcpIpConfigPtr(),pSocketStatus->OwnerId) != NULL)
    {
        TcpIp_CfgGetUpRxIndicationUpFunc(TcpIp_CfgGetTcpIpConfigPtr(),pSocketStatus->OwnerId)(pSocketStatus->Handle,
                                                                                      &RemoteAddr,p->payload, p->len);
    }
    pbuf_free(p);
}

/* Callback received from lwip after tcp data is received */
static err_t tcp_recv_cb_fn(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err)
{
    TcpIp_SockAddrType RemoteAddr;
    TcpIp_SocketStatusType *pSocketStatus = (TcpIp_SocketStatusType *)arg;
    TcpIp_SocketOwnerConfigType const * pSocketOwnerConfig;

    RemoteAddr.SockAddrInetType.Port = pcb->remote_port;
    RemoteAddr.SockAddrInetType.Domain = pSocketStatus->RemoteAddr.SockAddrInetType.Domain;
    // Send same to SoAd
    if (p != NULL_PTR)
    {
        if (TcpIp_CfgGetUpRxIndicationUpFunc(TcpIp_CfgGetTcpIpConfigPtr(),pSocketStatus->OwnerId) != NULL_PTR)
        {
            TcpIp_CfgGetUpRxIndicationUpFunc(TcpIp_CfgGetTcpIpConfigPtr(),pSocketStatus->OwnerId)(pSocketStatus->Handle,
                                                                                &RemoteAddr,p->payload, p->tot_len);
        }
        tcp_recved(pcb,p->tot_len);
    }
    else
    {
        pSocketOwnerConfig = pTcpIpConfig->pSocketOwnerConfig;
        if(pSocketOwnerConfig->pSocketOwnerTcpIpEventFunc != NULL_PTR)
        {
            pSocketOwnerConfig->pSocketOwnerTcpIpEventFunc(pSocketStatus->Handle, TCPIP_TCP_FIN_RECEIVED);
        }
    }
    return ERR_OK;
}

/* Callback to be called when connection is accepted by tcp server */
static err_t tcp_accept_cb_fn(void *arg, struct tcp_pcb *pcb, err_t err)
{
    TcpIp_SocketStatusType *pSocketStatus = (TcpIp_SocketStatusType *)arg;
    TcpIp_SocketIdType SocketId;
    if (pcb != NULL_PTR)
    {
        if (TcpIp_CfgGetUpTcpAcceptedFunc(TcpIp_CfgGetTcpIpConfigPtr(),pSocketStatus->OwnerId) != NULL_PTR)
        {
            /*! TODO update SocketStatus of connection not listen socket */
            if (TcpIp_GetFirstFreeSocket(&SocketId) == E_OK)
            {
                TcpIp_SocketStatus[SocketId].pvPcbAddr = pcb;
                /*Register the argument to be alled by callback funtions*/
                tcp_arg(pcb, &(TcpIp_SocketStatus[SocketId]));
                /*Register callback function to be called when tcp receives data*/
                tcp_recv(pcb, tcp_recv_cb_fn);
                /*Register callback function to be called when data tx confirm */
                tcp_sent(pcb, tcp_sent_cb_fn);
                /*Register callback to be called for error */
                tcp_err(pcb,tcp_error_fn);
                /* Socket assigned, get first free socket index */
                TcpIp_SocketStatus[SocketId].Handle = SocketId;
                TcpIp_SocketStatus[SocketId].ErrCnt = 0U;
                TcpIp_SocketStatus[SocketId].OwnerId = pSocketStatus->OwnerId;
                TcpIp_SocketStatus[SocketId].pLocalAddr = pSocketStatus->pLocalAddr;
                TcpIp_SocketStatus[SocketId].State = TCPIP_SOCKET_TCP_READY;
                TcpIp_SocketStatus[SocketId].ProtocolIsTcp = TRUE;
                TcpIp_SocketStatus[SocketId].RemoteAddr.SockAddrInetType.Port = pcb->remote_port;
                TcpIp_SocketStatus[SocketId].RemoteAddr.SockAddrInetType.Addr[0] = pcb->remote_ip.addr;
                (void)TcpIp_CfgGetUpTcpAcceptedFunc(TcpIp_CfgGetTcpIpConfigPtr(),pSocketStatus->OwnerId)(pSocketStatus->Handle,
                                    SocketId,&(TcpIp_SocketStatus[SocketId].RemoteAddr)); 
            }
        }
    }
    return ERR_OK;
}

/* Callback received from lwip after tcp data is being acknowledged from another peer */
static err_t tcp_sent_cb_fn(void *arg, struct tcp_pcb *pcb, u16_t len)
{
    TcpIp_SocketStatusType *pSocketStatus = (TcpIp_SocketStatusType *)arg;

    if (TcpIp_CfgGetUpTxConfirmationFunc(TcpIp_CfgGetTcpIpConfigPtr(),pSocketStatus->OwnerId) != NULL_PTR)
    {
        TcpIp_CfgGetUpTxConfirmationFunc(TcpIp_CfgGetTcpIpConfigPtr(),pSocketStatus->OwnerId)(pSocketStatus->Handle,len);
    }
    return ERR_OK;
}

/* Callback received from lwip after tcp connect is successful */
//  (*tcp_connected_fn)(void *arg, struct tcp_pcb *tpcb, err_t err)
static err_t tcp_connect_cb_fn(void *arg, struct tcp_pcb *pcb,  err_t err) 
{
    TcpIp_SocketStatusType *pSocketStatus = (TcpIp_SocketStatusType *)arg;

    if (TcpIp_CfgGetUpTcpConnectedFunc(TcpIp_CfgGetTcpIpConfigPtr(),pSocketStatus->OwnerId) != NULL_PTR)
    {
        TcpIp_CfgGetUpTcpConnectedFunc(TcpIp_CfgGetTcpIpConfigPtr(),pSocketStatus->OwnerId)(pSocketStatus->Handle);
    }
    return ERR_OK;
}

static void tcp_error_fn(void *arg, err_t err)
{
    TcpIp_EventType Event;
    boolean IsSockCloseReq = FALSE;
    TcpIp_SocketOwnerConfigType const * pSocketOwnerConfig;
    TcpIp_SocketStatusType *pSocketStatus = (TcpIp_SocketStatusType *)arg;

    switch(err)
    {
        /* Close socket on fatal errors */
        case ERR_ABRT:          /* Connection aborted.      */
        case ERR_RST:           /* Connection reset.        */
        case ERR_CLSD:          /* Connection closed.       */
        case ERR_ARG:           /* Illegal argument.        */
            IsSockCloseReq = TRUE;
            break;
        case 0:/* OK */
        case ERR_INPROGRESS:    /* Operation in progress    */
        case ERR_WOULDBLOCK:    /* Operation would block.   */
            break;
        case ERR_MEM:           /* Out of memory error.     */
        case ERR_BUF:           /* Buffer error.            */
        case ERR_TIMEOUT:       /* Timeout.                 */
        case ERR_RTE:           /* Routing problem.         */
        case ERR_VAL:           /* Illegal value.           */
        case ERR_USE:           /* Address in use.          */
        case ERR_ALREADY:       /* Already connecting.      */
        case ERR_ISCONN:        /* Conn already established.*/
        case ERR_CONN:          /* Not connected.           */
        case ERR_IF:            /* Low-level netif error    */
        default:
            /* Increase the error count and if the error count reaches the max count then close the socket */
            TcpIp_SocketStatus[pSocketStatus->Handle].ErrCnt++;
            #ifdef CFG_TCPIP_DEBUG
            if(TcpIp_SocketStatus[SocketId].ErrCnt > TcpIp_SocketStatus[SocketId].ErrCntMax)
            {
                TcpIp_SocketStatus[SocketId].ErrCntMax = TcpIp_SocketStatus[SocketId].ErrCnt;
            }
            TcpIp_SocketStatus[SocketId].SockErrorsArr[TcpIp_SocketStatus[SocketId].ErrCnt] = SockErr;
            #endif
            if(TcpIp_SocketStatus[pSocketStatus->Handle].ErrCnt >= TCPIP_NOF_ERR_BEFORE_RESET)
            {
                IsSockCloseReq = TRUE;
                TcpIp_SocketStatus[pSocketStatus->Handle].ErrCnt = 0;
            }
            break;
    }

    if(IsSockCloseReq == TRUE)
    {
        /* If socket close is requested , then close the socket and update the socket owner about the event */
        #ifdef CFG_TCPIP_DEBUG
        TcpIp_SocketStatus[SocketId].NumofClosedSocket++;
        #endif
        //(void)closesocket(TcpIp_SocketStatus[pSocketStatus->Handle].Handle);
        if(TRUE == TcpIp_SocketStatus[pSocketStatus->Handle].ProtocolIsTcp)
        {
            Event = TCPIP_TCP_CLOSED;
        }
        else
        {
            Event = TCPIP_UDP_CLOSED;
        }
        
        pSocketOwnerConfig = pTcpIpConfig->pSocketOwnerConfig;
        if(pSocketOwnerConfig->pSocketOwnerTcpIpEventFunc != NULL_PTR)
        {
            pSocketOwnerConfig->pSocketOwnerTcpIpEventFunc(pSocketStatus->Handle, Event);
        }
        //TcpIp_FreeUpSocket(SocketId); 
    }    
}



#define TCPIP_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
/*******************************************************************************************************************
*   For each change to this file, be sure to record:                                                               *
*      1.  who made the change and when the change was made                                                        *
*      2.  why the change was made and the intended Result                                                         *
*   Following block needs to be repeated for each change                                                           *
*******************************************************************************************************************/
/*!*****************************************************************************************************************
*  @date    29-Sep-2023
*  @version 1.0.0
*  @author  pchinnat
*  @brief   Traceability - AUTOSAR 4.3 version initial implementation
*******************************************************************************************************************/
