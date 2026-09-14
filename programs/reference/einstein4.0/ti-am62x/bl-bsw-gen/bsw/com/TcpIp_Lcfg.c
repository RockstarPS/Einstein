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
*    @file TcpIp_Lcfg.c
*    @ingroup TcpIpConfiguration
*    @brief This is TcpIp Link time configuration source file. It contains definitions of Link time configuration
*     parameters for the TcpIp module.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "TcpIp_Cfg.h"
#include "TcpIp_Lcfg.h"
#include "SoAd_Cbk.h"
#include "TcpIp.h"
/********************************************************************************************************************
* #! GLOBAL VARIABLES                                                                                               *
********************************************************************************************************************/

/********************************************************************************************************************
* #! TcpIp const config  data                                                                                       *
********************************************************************************************************************/

/*! @brief specifies the assignment policy for the IP address. 
AssignmentLifetime :  Defines the lifetime of a dynamically fetched IP address.
AssignmentMethod : Method of address assignment
TcpIpAssignmentPriority : Method of address assignment
TcpIpAssignmentTrigger : Method of address assignment
*/
const TcpIp_AddrAssignmentConfigType TcpIp_AddrAssignmentConfig[TCPIP_NUM_OF_LOCALADDR] = 
{
    { TCPIP_FORGET, TCPIP_IPADDR_ASSIGNMENT_STATIC, 1U, TCPIP_AUTOMATIC }
};

/*! @brief specifies a static IP address including directly related parameters. 
TcpIpStaticIpAddress : Static IPv4 Address
TcpIpDefaultRouter : IPv4 address of default router (gateway)
TcpIpNetmask : IPv4 address of default router (gateway)
*/
const TcpIp_StaticIpAddressConfigType TcpIp_StaticIpAddressConfig[TCPIP_NUM_OF_LOCALADDR] =
{
    { 
        0x0A00A8C0,    /* 192.168.0.10 */
        0x0,    /* 192.168.0.10 */
        24U,             /* 255.255.255.0 */
        TRUE
    }
};

/*! @brief Specifies the local IP (Internet Protocol) addresses used for IP communication.
TcpIpAddrId : IP address table identifier assigned by TCP/IP stack
AddressType : Defines the address type
DomainType : Address family.
CtrlConfigId : Reference to a TcpIpCtrl specifying the EthIf Controller where the IP address shall be assigned
pAddrAssignmentConfig : Pointer to the AddrAssignment configuration
pStaticIpAddressConfig : Pointer to the Static Ip Address configuration
*/
const TcpIp_LocalAddrConfigType TcpIp_LocalAddrConfig[TCPIP_NUM_OF_LOCALADDR] =
{
    {
        TCPIP_ADDR_ID_CFG1,
        TCPIP_UNICAST,
        TCPIP_AF_INET,
        0U,
        &TcpIp_AddrAssignmentConfig[0],
        &TcpIp_StaticIpAddressConfig[0]
    }
};

/*! @brief specifies an upper layer of TcpIp that uses the socket API. 
SocketOwnerCopyTxDataFunc : Defines  the <Up_CopyTxData> function of the TcpIpSocketOwner module 
SocketOwnerLocalIpAddrAssignmentChgFunc : Defines the name of the <Up_LocalIpAddrAssignmentChg> function of the 
    TcpIpSocketOwner  Module 
SocketOwnerRxIndicationFunc : Defines the name of the <Up_RxIndication> function of the TcpIpSocketOwner module
SocketOwnerTcpAcceptedFunc : Defines the name of the <Up_TcpAccepted> function of the TcpIpSocketOwner module
SocketOwnerTcpConnectedFunc : defines the name of the <Up_TcpConnected> function of the TcpIpSocketOwner module
SocketOwnerTcpIpEventFunc : defines the name of the <Up_TcpIpEvent> function of the TcpIpSocketOwner module
SocketOwnerTxConfirmationFunc : defines the name of the <Up_TxConfirmation> function of the TcpIpSocketOwner module
SocketOwnerUL : specifies the type of the upper layer module.
*/
const TcpIp_SocketOwnerConfigType TcpIp_SocketOwnerConfig[TCPIP_NUM_OF_SOCKETS] =
{
    {
        &SoAd_CopyTxData,
        &SoAd_LocalIpAddrAssignmentChg,
        &SoAd_RxIndication,
        &SoAd_TcpAccepted,
        &SoAd_TcpConnected,
        &SoAd_TcpIpEvent,
        &SoAd_TxConfirmation,
        TcpIp_SocketOwnerULSOAD
    }
};

/*! @brief Defines the connfiguration of the TcpIp ctrl 
* FramePrioDefault :Specifies the default value for the priority for all outgoing frames.
* EthIfCtrlId : Reference to EthIf controller where the IP address shall be assigned. 
*/
const TcpIp_CtrlConfigType TcpIp_CtrlConfig = 
{
    0u,
    0u
};

/*! @brief defines Configuration data structure of the TcpIp module. 
* pCtrlConfig - pointer to the Controller configuration array
* pLocalAddrConfig - pointer to the Local address configuration array 
* pSocketOwnerConfig - pointer to the Controller configuration array
*/
const TcpIp_TcpIpConfigType TcpIp_TcpIpConfig =
{
    &TcpIp_CtrlConfig,
    &TcpIp_LocalAddrConfig[0],
    &TcpIp_SocketOwnerConfig[0]
};

Std_ReturnType TcpIp_SoAdGetSocket
(
    TcpIp_DomainType Domain,
    TcpIp_ProtocolType Protocol,
    P2VAR(TcpIp_SocketIdType,AUTOMATIC,TCPIP_APPL_DATA) SocketIdPtr
)
{
    return TcpIp_GetSocket(TCPIP_SOCKET_OWNER_ID_SOAD,Domain,Protocol,SocketIdPtr);
}
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


