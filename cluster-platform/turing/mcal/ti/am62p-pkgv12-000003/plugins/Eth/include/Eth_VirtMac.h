/*
*
* Copyright (C) 2024 Texas Instruments Incorporated
*
* All rights reserved not granted herein.
*
* Limited License.
*
* Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
* license under copyrights and patents it now or hereafter owns or controls to make,
* have made, use, import, offer to sell and sell ("Utilize") this software subject to the
* terms herein.  With respect to the foregoing patent license, such license is granted
* solely to the extent that any such patent is necessary to Utilize the software alone.
* The patent license shall not apply to any combinations which include this software,
* other than combinations with devices manufactured by or for TI ("TI Devices").
* No hardware patent is licensed hereunder.
*
* Redistributions must preserve existing copyright notices and reproduce this license
* (including the above copyright notice and the disclaimer and (if applicable) source
* code license limitations below) in the documentation and/or other materials provided
* with the distribution
*
* Redistribution and use in binary form, without modification, are permitted provided
* that the following conditions are met:
*
* *       No reverse engineering, decompilation, or disassembly of this software is
* permitted with respect to any software provided in binary form.
*
* *       any redistribution and use are licensed by TI for use only with TI Devices.
*
* *       Nothing shall obligate TI to provide you with source code for the software
* licensed and provided to you in object code.
*
* If software source code is provided to you, modification and redistribution of the
* source code are permitted provided that the following conditions are met:
*
* *       any redistribution and use of the source code, including any resulting derivative
* works, are licensed by TI for use only with TI Devices.
*
* *       any redistribution and use of any object code compiled from the source code
* and any resulting derivative works, are licensed by TI for use only with TI Devices.
*
* Neither the name of Texas Instruments Incorporated nor the names of its suppliers
*
* may be used to endorse or promote products derived from this software without
* specific prior written permission.
*
* DISCLAIMER.
*
* THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL TI AND TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
* OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

/**
 *  \file     Eth_VirtMac.h
 *
 *  \brief    This file contains the interface of the Virtual Mac Ethernet driver.
 */

/**
 *  \defgroup MCAL_VIRTUAL_MAC_ETH_API Ethernet Virtual Mac Driver API
 *
 *  The Virtual Mac Ethernet Driver provides low-level access to the five-port or 
 *  night-port Gigabit Ethernet Switch hardware in the Jacinto 7 family 
 *  which integrate Ethernet Firmware functionality.
 *
 *
 *  The Ethernet Driver is part of the Communication Stack in the AUTOSAR
 *  Basic Software (BSW).
 *
 *  \sa MCAL_ETH_CFG
 *  \sa MCAL_ETH_IRQ
 *  @{
 */

#ifndef ETH_VIRTMAC_H__
#define ETH_VIRTMAC_H__

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "Eth_Types.h"
#include "Eth_Cfg.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

#if (STD_ON == ETH_VIRTUALMAC_SUPPORT)
/**
 *  \brief This function initializes Eth Virtual MAC driver's Remote Procedure Call
 *
 *  \verbatim
 *  Service name      : Eth_VirtMacRpcInit
 *  Syntax            : Std_ReturnType Eth_VirtMacRpcInit(Eth_ConfigType *CfgPtr)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : 0x2BU
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : CfgPtr. Pointer to virt mac config struct. Refer to /ref Eth_ConfigType
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      :  Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: otherwise
 *
 *  Description       :  The function initializes the RPC configuration required to invoke remote procedure
 *                       calls to ethernet firmware to enable data path setup to AUTOSAR Eth MCAL
 *                       driver. On initialization of AUTOSAR MCAL driver in virtual mac mode, the driver
 *                       announces autosar ethernet mcal driver RpMsg service to the ethernet
 *                       firmware core. The ethernet firmware server service will block  waiting for
 *                       the announcment from MCAL driver and then attach to the Ethernet MCAL driver
 *                       by sending it a EthFwInfo msg
 *                       If configured in virtual mac mode application should
 *                       invoke this API as follows:
 *                       1. Eth_VirtMacRpcInit()
 *                       2. Wait for fwRegisteredCb() callback
 *                       3. Eth_DispatchVirtmacInit
 *                       4. Wait for rpcCmdComplete() callback with status E_OK
 *                       5. Eth_Init()
 *                       The callbacks fwRegisteredCb() and rpcCmdComplete() are
 *                       populated by the application as part of the Eth_ConfigType
 *                       structure
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_VirtMacRpcInit(P2CONST(Eth_ConfigType, AUTOMATIC, ETH_PBCFG) CfgPtr);
#endif  /* (STD_ON == ETH_VIRTUALMAC_SUPPORT) */

#if (STD_ON == ETH_VIRTUALMAC_SUPPORT)
/**
 *  \brief Dispatch virtual mac initialization request to ethernet firmware
 *
 *  \verbatim
 *  Service name      : Eth_DispatchVirtmacInit
 *  Syntax            : Std_ReturnType Eth_DispatchVirtmacInit(CtrlIdx)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : 0x1CU
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : CtrlIdx. Index of the controller within the context of the
 *                                Ethernet Driver
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      :  Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: RPC init failed
 *
 *  Description       :  The function dispatches RPC command to ethernet
 *                       firmware core to allocate data path resources.
 *                       The allocated Tx, Rx DMA channels are then setup in the
 *                       Eth_Init() API. The function only send the
 *                       RPC msg to ethernet firmware core. Completion of RPC msg
 *                       processing is indicated by invokcation of
 *                       rpcCmdComplete part of Eth_ConfigType sturcture.
 *                       If configured in virtual mac mode application should
 *                       invoke this API as follows:
 *                       1. Eth_VirtMacRpcInit()
 *                       2. Wait for fwRegisteredCb() callback
 *                       3. Eth_DispatchVirtmacInit
 *                       4. Wait for rpcCmdComplete() callback with status E_OK
 *                       5. Eth_Init()
 *                       The callbacks fwRegisteredCb() and rpcCmdComplete() are
 *                       populated by the application as part of the Eth_ConfigType
 *                       structure
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_DispatchVirtmacInit(uint8 CtrlIdx);
#endif  /* (STD_ON == ETH_VIRTUALMAC_SUPPORT) */

#if (STD_ON == ETH_VIRTUALMAC_SUPPORT)
/**
 *  \brief Dispatch virtual mac deinit request to ethernet firmware
 *
 *  \verbatim
 *  Service name      : Eth_DispatchVirtmacDeinit
 *  Syntax            : Std_ReturnType Eth_DispatchVirtmacDeinit(CtrlIdx)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : 0x1DU
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : CtrlIdx. Index of the controller within the context of the
 *                                Ethernet Driver
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      :  Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: virtual mac init failed
 *
 *  Description       :  The function dispatches RPC command to ethernet
 *                       firmware core to free data path resources.
 *                       This function dispatches RPC msg to ethernet firmware core.
 *                       Completion of RPC msg processing is indicated by invokcation
 *                       of rpcCmdComplete part of Eth_ConfigType sturcture.
 *                       Once complete the data path to Ethernet virtual MAC
 *                       has been torn down and driver can no loner send or receive packets
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_DispatchVirtmacDeinit(uint8 CtrlIdx);
#endif  /* (STD_ON == ETH_VIRTUALMAC_SUPPORT) */

#if ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_NOTIFYMSGRECEIVED_API))
/**
 *  \brief Notify Ethernet driver that a RPC msg has been received from ethernet firmware
 *
 *  \verbatim
 *  Service name      : Eth_NotifyVirtmacMsgReceived
 *  Syntax            : Std_ReturnType Eth_NotifyVirtmacMsgReceived(CtrlIdx)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : 0x1EU
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : CtrlIdx. Index of the controller within the context of the
 *                                Ethernet Driver
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      :  Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: otherwise
 *
 *  Description       :  Invocation of this function will cause the Ethernet
 *                       MCAL driver to process any queued messages received
 *                       from ethernet firmware. Depending on type of msg received
 *                       ethernet firmware will invoke rpcCmdComplete/fwRegisteredCb
 *                       application callbacks. This function is typically
 *                       called from the Cdd_IpcNewMessageNotify if the channel
 *                       id matches the Ethernet MCAL IPC channel id
 *                       (ethfwRpcComChId member of Eth_ConfigType structure)
 *                       Application can also trigger recv msg processing by
 *                       setting pollRecvMsgInEthMain in Eth_ConfigType to TRUE
 *                       Invoking Eth_MainFunction with this config set will
 *                       trigger recv msg processing. In triggering recv msg
 *                       processing from Eth_MainFunction, this API should be
 *                       disabled
 *
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_NotifyVirtmacMsgReceived(uint8 CtrlIdx);
#endif  /* ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_NOTIFYMSGRECEIVED_API)) */

#if ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_SUBSCRIBEALLTRAFFIC_API))
/**
 *  \brief Dispatch virtual mac all traffic subscription request to ethernet firmware
 *
 *  \verbatim
 *  Service name      : Eth_DispatchVirtmacSubscribeAllTraffic
 *  Syntax            : Std_ReturnType Eth_DispatchVirtmacSubscribeAllTraffic(CtrlIdx)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : 0x1FU
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : CtrlIdx. Index of the controller within the context of the
 *                                Ethernet Driver
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      :  Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: otherwise
 *
 *  Description       :  The function dispatches RPC command to ethernet
 *                       firmware core to subscribe to all default flow traffic
 *                       received on host port.The default flow contains all
 *                       traffic that is not explicitly categorized into a specific
 *                       flow using a classifier entry in the switch .
 *                       Note that only one core can subscribe to default flow
 *                       traffic in a system and this is by default the ethernet
 *                       firmware core. This API requires a compatible ethernet
 *                       firmware that _does_ _not_ subscribe to default flow
 *                       and allows Eth Driver to subscribe to default flow
 *                       The function only send the RPC msg to ethernet firmware core.
 *                       Completion of RPC msg processing is indicated by invokcation of
 *                       rpcCmdComplete part of Eth_ConfigType sturcture.
 *                       A failure status indicates ethernet firmware does not allow
 *                       AUTOSAR Eth Driver to subscribe to default flow
 *                       If configured in virtual mac mode application should
 *                       invoke this API as follows:
 *                       1. Eth_VirtMacRpcInit()
 *                       2. Wait for fwRegisteredCb() callback
 *                       3. Eth_DispatchVirtmacInit
 *                       4. Wait for rpcCmdComplete() callback with status E_OK
 *                       5. Eth_Init()
 *                       6. Eth_DispatchVirtmacSubscribeAllTraffic()
 *                       7. Wait for rpcCmdComplete() callback with status E_OK
 *                       The callbacks fwRegisteredCb() and rpcCmdComplete() are
 *                       populated by the application as part of the Eth_ConfigType
 *                       structure
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_DispatchVirtmacSubscribeAllTraffic(uint8 CtrlIdx);
#endif  /* ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_SUBSCRIBEALLTRAFFIC_API)) */

#if ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_UNSUBSCRIBEALLTRAFFIC_API))
/**
 *  \brief Dispatch virtual mac all traffic unsubscription request to ethernet firmware
 *
 *  \verbatim
 *  Service name      : Eth_DispatchVirtmacUnsubscribeAllTraffic
 *  Syntax            : Std_ReturnType Eth_DispatchVirtmacUnsubscribeAllTraffic(CtrlIdx)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : 0x20U
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : CtrlIdx. Index of the controller within the context of the
 *                                Ethernet Driver
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      :  Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: otherwise
 *
 *  Description       :  The function dispatches RPC command to ethernet
 *                       firmware core to unsubscribe to all default flow traffic
 *                       received on host port.The driver should have subscribed
 *                       to all default flow traffic previously by invoking
 *                       Eth_DispatchVirtmacSubscribeAllTraffic().
 *                       On unsubscribing to default flow all traffic with
 *                       default flow will be dropped.
 *                       The function only send the RPC msg to ethernet firmware core.
 *                       Completion of RPC msg processing is indicated by invokcation of
 *                       rpcCmdComplete part of Eth_ConfigType sturcture.
 *                       The callbacks fwRegisteredCb() and rpcCmdComplete() are
 *                       populated by the application as part of the Eth_ConfigType
 *                       structure
 *                       If configured in virtual mac mode application should
 *                       invoke this API as follows:
 *                       1. Eth_VirtMacRpcInit()
 *                       2. Wait for fwRegisteredCb() callback
 *                       3. Eth_DispatchVirtmacInit
 *                       4. Wait for rpcCmdComplete() callback with status E_OK
 *                       5. Eth_Init()
 *                       6. Eth_DispatchVirtmacSubscribeAllTraffic()
 *                       7. Wait for rpcCmdComplete() callback with status E_OK
 *                       8. Eth_SetControllerMode(ETH_MODE_ACTIVE)
 *                       9. Packet processing using Eth_Receive/Eth_Trasmit
 *                       10. Eth_DispatchVirtmacUnsubscribeAllTraffic
 *                       11. Wait for rpcCmdComplete() callback with status E_OK
 *                       The callbacks fwRegisteredCb() and rpcCmdComplete() are
 *                       populated by the application as part of the Eth_ConfigType
 *                       structure
 *
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_DispatchVirtmacUnsubscribeAllTraffic(uint8 CtrlIdx);
#endif  /* ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_UNSUBSCRIBEALLTRAFFIC_API)) */

#if ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_SUBSCRIBEDSTMAC_API))
/**
 *  \brief Dispatch virtual mac destination mac traffic subscription request to ethernet firmware
 *
 *  \verbatim
 *  Service name      : Eth_DispatchVirtmacSubscribeDstMac
 *  Syntax            : Std_ReturnType Eth_DispatchVirtmacSubscribeDstMac(CtrlIdx, macAddress)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : 0x21
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : CtrlIdx: Index of the controller within the context of the
 *                                Ethernet Driver
 *                      macAddress: Destination Mac address
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      :  Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: otherwise
 *
 *  Description       :  The function dispatches RPC command to ethernet
 *                       firmware core to subscribe to traffic with the given
 *                       destination macAddress to be routed to the rx flow
 *                       of the Ethernet MCAL driver so that driver can receive
 *                       the packets.The macAddres can be a unicast address
 *                       allocated to the EthDriver (returned by Eth_GetPhysAddr())
 *                       or a multicast address.
 *                       The switch address resolution table should have an entry to
 *                       route the destination mac address to the host port.
 *                       For unicast address , the switch address resolution table
 *                       can be updated using Eth_DispatchVirtmacSubscribeDstMac()
 *                       For multicast address , the switch address resolution table
 *                       can be updated using Eth_DispatchVirtmacSubscribeDstMac()
 *                       Note that broadcast address is usually subscribed to by
 *                       ethernet firmware so that it can respond to ARP requests.
 *                       If ARP response handling by ethernet firmware is required,
 *                       Eth driver should not be subscribed to broadcast address.
 *                       The function only send the RPC msg to ethernet firmware core.
 *                       Completion of RPC msg processing is indicated by invokcation of
 *                       rpcCmdComplete part of Eth_ConfigType sturcture.
 *                       A failure status indicates ethernet firmware does not allow
 *                       AUTOSAR Eth Driver to subscribe to default flow
 *                       If configured in virtual mac mode application should
 *                       invoke this API as follows:
 *                       1. Eth_VirtMacRpcInit()
 *                       2. Wait for fwRegisteredCb() callback
 *                       3. Eth_DispatchVirtmacInit
 *                       4. Wait for rpcCmdComplete() callback with status E_OK
 *                       5. Eth_Init()
 *                       6. Eth_DispatchVirtmacSubscribeDstMac()
 *                       7. Wait for rpcCmdComplete() callback with status E_OK
 *                       The callbacks fwRegisteredCb() and rpcCmdComplete() are
 *                       populated by the application as part of the Eth_ConfigType
 *                       structure
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_DispatchVirtmacSubscribeDstMac(uint8 CtrlIdx, uint8 *macAddress);
#endif  /* ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_SUBSCRIBEDSTMAC_API)) */

#if ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_UNSUBSCRIBEDSTMAC_API))
/**
 *  \brief Dispatch virtual mac destination traffic unsubscription request to ethernet firmware
 *
 *  \verbatim
 *  Service name      : Eth_DispatchVirtmacUnsubscribeDstMac
 *  Syntax            : Std_ReturnType Eth_DispatchVirtmacUnsubscribeDstMac(CtrlIdx)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : 0x22
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : CtrlIdx. Index of the controller within the context of the
 *                                Ethernet Driver
 *                      macAddress: Destination Mac address
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      :  Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: otherwise
 *
 *  Description       :  The function dispatches RPC command to ethernet
 *                       firmware core to unsubscribe the specified destination
 *                       mac address flow traffic received on host port.
 *                       The driver should have subscribed to the destination mac
 *                       address previously by invoking
 *                       Eth_DispatchVirtmacSubscribeDstMac().
 *                       On unsubscribing to destination mac flow , traffic with
 *                       given destination mac address flow will be directed to
 *                       default flow.
 *                       The function only send the RPC msg to ethernet firmware core.
 *                       Completion of RPC msg processing is indicated by invokcation of
 *                       rpcCmdComplete part of Eth_ConfigType sturcture.
 *                       The callbacks fwRegisteredCb() and rpcCmdComplete() are
 *                       populated by the application as part of the Eth_ConfigType
 *                       structure
 *                       If configured in virtual mac mode application should
 *                       invoke this API as follows:
 *                       1. Eth_VirtMacRpcInit()
 *                       2. Wait for fwRegisteredCb() callback
 *                       3. Eth_DispatchVirtmacInit
 *                       4. Wait for rpcCmdComplete() callback with status E_OK
 *                       5. Eth_Init()
 *                       6. Eth_DispatchVirtmacSubscribeDstMac()
 *                       7. Wait for rpcCmdComplete() callback with status E_OK
 *                       8. Eth_SetControllerMode(ETH_MODE_ACTIVE)
 *                       9. Packet processing using Eth_Receive/Eth_Trasmit
 *                       10. Eth_DispatchVirtmacUnsubscribeDstMac()
 *                       11. Wait for rpcCmdComplete() callback with status E_OK
 *                       12. Eth_SetControllerMode(ETH_MODE_DOWN)
 *                       Note that all subscribed MAC address must be unsubscribed
 *                       before Eth_SetControllerMode(ETH_MODE_DOWN) is invoked
 *                       The callbacks fwRegisteredCb() and rpcCmdComplete() are
 *                       populated by the application as part of the Eth_ConfigType
 *                       structure
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_DispatchVirtmacUnsubscribeDstMac(uint8 CtrlIdx, uint8 *macAddress);
#endif  /* ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_UNSUBSCRIBEDSTMAC_API)) */

#if ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_ASSOCIATEIPV4MACADDR_API))
/**
 *  \brief Dispatch virtual mac IPV4 address:destination mac association request to ethernet firmware
 *
 *  \verbatim
 *  Service name      : Eth_DispatchVirtmacAssociateIPv4Macaddr
 *  Syntax            : Std_ReturnType Eth_DispatchVirtmacAssociateIPv4Macaddr(CtrlIdx, ipv4Address, macAddress)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : 0x23
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : CtrlIdx: Index of the controller within the context of the
 *                                Ethernet Driver
 *                      ipv4Address: IPv4 address
 *                      macAddress: Destination Mac address
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      :  Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: otherwise
 *
 *  Description       :  The function dispatches RPC command to ethernet
 *                       firmware core to associate the given unicast macaddress
 *                       with the given IP address.
 *                       The ethernet firmware maintains the ARP database for
 *                       the ethernet driver and ethfw will respond to any ARP request.
 *                       To correctly respond to ARP queries for IP address assigned to
 *                       the AUTOSAR network stack , the AUTOSAR stack must invoke
 *                       this API so that the ARP database maintained by ethernet
 *                       firmware is updated.The macAddres must be a unicast address
 *                       allocated to the EthDriver (returned by Eth_GetPhysAddr())
 *                       If configured in virtual mac mode application should
 *                       invoke this API as follows:
 *                       1. Eth_VirtMacRpcInit()
 *                       2. Wait for fwRegisteredCb() callback
 *                       3. Eth_DispatchVirtmacInit
 *                       4. Wait for rpcCmdComplete() callback with status E_OK
 *                       5. Eth_Init()
 *                       6. Eth_DispatchVirtmacSubscribeDstMac()
 *                       7. Wait for rpcCmdComplete() callback with status E_OK
 *                       8. Eth_SetControllerMode(ETH_MODE_ACTIVE)
 *                       9. Send out DHCP request to acquire IP address for the
 *                          AUTOSAR network stack
 *                       10. On getting DHCP response with IP address, invoke
 *                           Eth_DispatchVirtmacAssociateIPv4Macaddr
 *                       11. Wait for rpcCmdComplete() callback with status E_OK
 *                       The callbacks fwRegisteredCb() and rpcCmdComplete() are
 *                       populated by the application as part of the Eth_ConfigType
 *                       structure
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_DispatchVirtmacAssociateIPv4Macaddr(uint8 CtrlIdx, uint8 *ipv4Address, uint8 *macAddress);
#endif  /* ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_ASSOCIATEIPV4MACADDR_API)) */


#if ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_DISASSOCIATEIPV4MACADDR_API))
/**
 *  \brief Dispatch virtual mac IPV4 address:destination mac disassociation request to ethernet firmware
 *
 *  \verbatim
 *  Service name      : Eth_DispatchVirtmacDisassociateIPv4Macaddr
 *  Syntax            : Std_ReturnType Eth_DispatchVirtmacDisassociateIPv4Macaddr(CtrlIdx, ipv4Address)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : 0x24
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : CtrlIdx: Index of the controller within the context of the
 *                                Ethernet Driver
 *                      ipv4Address: IPv4 address
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      :  Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: otherwise
 *
 *  Description       :  The function dispatches RPC command to ethernet
 *                       firmware core to remove the given IP address from the
 *                       ARP database maintained by ethernet firmware.
 *                       On deletion the ethfw will no longer respond to any ARP
 *                       queries for the given IP address.
 *                       If configured in virtual mac mode application should
 *                       invoke this API as follows:
 *                       1. Eth_VirtMacRpcInit()
 *                       2. Wait for fwRegisteredCb() callback
 *                       3. Eth_DispatchVirtmacInit
 *                       4. Wait for rpcCmdComplete() callback with status E_OK
 *                       5. Eth_Init()
 *                       6. Eth_DispatchVirtmacSubscribeDstMac()
 *                       7. Wait for rpcCmdComplete() callback with status E_OK
 *                       8. Eth_SetControllerMode(ETH_MODE_ACTIVE)
 *                       9. Send out DHCP request to acquire IP address for the
 *                          AUTOSAR network stack
 *                       10. On getting DHCP response with IP address, invoke
 *                           Eth_DispatchVirtmacAssociateIPv4Macaddr
 *                       11. Wait for rpcCmdComplete() callback with status E_OK
 *                       12. Network Packet processing
 *                       13. Eth_DispatchVirtmacDisassociateIPv4Macaddr
 *                       14. Wait for rpcCmdComplete() callback with status E_OK
 *                       The callbacks fwRegisteredCb() and rpcCmdComplete() are
 *                       populated by the application as part of the Eth_ConfigType
 *                       structure
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_DispatchVirtmacDisassociateIPv4Macaddr(uint8 CtrlIdx, uint8 *ipv4Address);
#endif  /* ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_DISASSOCIATEIPV4MACADDR_API)) */

#if ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_ADD_MCAST_MACADDR_API))
/**
 *  \brief Dispatch virtual mac addition of given multicast address to switch address resolution table request to ethernet firmware
 *
 *  \verbatim
 *  Service name      : Eth_DispatchVirtmacAddMcastAddr
 *  Syntax            : Std_ReturnType Eth_DispatchVirtmacAddMcastAddr(CtrlIdx, macAddress, numLsbToIgnore, vlanId, portList)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : 0x26
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : CtrlIdx: Index of the controller within the context of the
 *                                Ethernet Driver
 *                      macAddress: _Exclusive_ multicast address, or _shared_ multicast address
 *                                  in devices with ALE multihost support
 *                      vlanId: Vlan Id associated with the mac Address. If vlan id is not needed, 0 should be passed
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      :  Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: otherwise
 *
 *  Description       :  The function dispatches RPC command to ethernet
 *                       firmware core to add the given multicast macaddress
 *                       to the switch address resolution table with the given
 *                       vlan id.
 *                       Note that this API requires that either the address is an
 *                       _exclusive_ multicast address not claimed by any other
 *                       remote client, or if the address is a _shared_ multicast
 *                       address that the device supports ALE multihost feature
 *                       (ETHFW with VEPA support).  _Shared_ multicast address
 *                       support in devices withotu ALE multihost feature are
 *                       currently not supported as this requires shared memory
 *                       packet transfer, which is not supported in MCAL.
 *                       If configured in virtual mac mode application should
 *                       invoke this API as follows:
 *                       1. Eth_VirtMacRpcInit()
 *                       2. Wait for fwRegisteredCb() callback
 *                       3. Eth_DispatchVirtmacInit
 *                       4. Wait for rpcCmdComplete() callback with status E_OK
 *                       5. Eth_Init()
 *                       6. Eth_DispatchVirtmacSubscribeDstMac()
 *                       7. Wait for rpcCmdComplete() callback with status E_OK
 *                       8. Eth_DispatchVirtmacAddMcastAddr()
 *                       9. Wait for rpcCmdComplete() callback with status E_OK
 *                       10. Eth_SetControllerMode(ETH_MODE_ACTIVE)
 *                       The callbacks fwRegisteredCb() and rpcCmdComplete() are
 *                       populated by the application as part of the Eth_ConfigType
 *                       structure
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_DispatchVirtmacAddMcastAddr(uint8 CtrlIdx, uint8 *macAddress, uint32 vlanId);
#endif  /* ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_ADD_MCAST_MACADDR_API)) */

#if ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_DEL_MACADDR_API))
/**
 *  \brief Dispatch virtual mac removal of given mac address from switch address resolution table request to ethernet firmware
 *
 *  \verbatim
 *  Service name      : Eth_DispatchVirtmacDelAddr
 *  Syntax            : Std_ReturnType Eth_DispatchVirtmacDelAddr(uint8 CtrlIdx, uint8 *macAddress, uint32 vlanId)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : 0x27
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : CtrlIdx: Index of the controller within the context of the
 *                                Ethernet Driver
 *                      macAddress: Multicast Mac address to be removed from filter
 *                      vlanId: Vlan Id associated with the mac Address. If vlan id is not needed, 0 should be passed
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      :  Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: otherwise
 *
 *  Description       :  The function dispatches RPC command to ethernet
 *                       firmware core to remove the given multicast macaddress
 *                       and vlan id from the switch address resolution table
 *                       On removal of entry switch would switch frames
 *                       received with the given destination macAddress:
 *                       vlan id  combo by flooding to all the ports in vlan membership.
 *                       Address should have been added previously using
 *                       Eth_DispatchVirtmacAddMcastAddr().
 *                       If configured in virtual mac mode application should
 *                       invoke this API as follows:
 *                       1. Eth_VirtMacRpcInit()
 *                       2. Wait for fwRegisteredCb() callback
 *                       3. Eth_DispatchVirtmacInit
 *                       4. Wait for rpcCmdComplete() callback with status E_OK
 *                       5. Eth_Init()
 *                       6. Eth_DispatchVirtmacSubscribeDstMac()
 *                       7. Wait for rpcCmdComplete() callback with status E_OK
 *                       8. Eth_DispatchVirtmacAddMcastAddr()
 *                       9. Wait for rpcCmdComplete() callback with status E_OK
 *                       10. Eth_DispatchVirtmacDelAddr()
 *                       11. Wait for rpcCmdComplete() callback with status E_OK
 *                       The callbacks fwRegisteredCb() and rpcCmdComplete() are
 *                       populated by the application as part of the Eth_ConfigType
 *                       structure
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_DispatchVirtmacDelAddr(uint8 CtrlIdx, uint8 *macAddress, uint32 vlanId);
#endif  /* ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_DEL_MACADDR_API)) */

#if ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_ADD_VLAN_API))
/**
 *  \brief Dispatch virtual VLAN join request to ethernet firmware
 *
 *  \verbatim
 *  Service name      : Eth_DispatchVirtmacAddVlan
 *  Syntax            : Std_ReturnType Eth_DispatchVirtmacAddVlan(CtrlIdx, vlanId)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : 0x28
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : CtrlIdx: Index of the controller within the context of the
 *                                Ethernet Driver
 *                      vlanId:  Vlan Id for which port membership is to be added to switch VLAN membership table
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      :  Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: otherwise
 *
 *  Description       :  The function dispatches RPC command to ethernet
 *                       firmware core to join a VLAN.  The VLAN creation is
 *                       owned by ethernet firmware which defines what
 *                       Ethernet ports and virtual ports are members.  If
 *                       the virtual client is not a member of the VLAN, then
 *                       the request to join the VLAN will be rejected.
 *                       If configured in virtual mac mode application should
 *                       invoke this API as follows:
 *                       1. Eth_VirtMacRpcInit()
 *                       2. Wait for fwRegisteredCb() callback
 *                       3. Eth_DispatchVirtmacInit
 *                       4. Wait for rpcCmdComplete() callback with status E_OK
 *                       5. Eth_Init()
 *                       6. Eth_DispatchVirtmacSubscribeDstMac()
 *                       7. Wait for rpcCmdComplete() callback with status E_OK
 *                       8. Eth_DispatchVirtmacAddVlan()
 *                       9. Wait for rpcCmdComplete() callback with status E_OK
 *                       10. Eth_SetControllerMode(ETH_MODE_ACTIVE)
 *                       The callbacks fwRegisteredCb() and rpcCmdComplete() are
 *                       populated by the application as part of the Eth_ConfigType
 *                       structure
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_DispatchVirtmacAddVlan(uint8 CtrlIdx, uint32 vlanId);
#endif  /* ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_ADD_VLAN_API)) */

#if ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_DEL_VLAN_API))
/**
 *  \brief Dispatch virtual VLAN leave command to ethernet firmware
 *
 *  \verbatim
 *  Service name      : Eth_DispatchVirtmacDelVlan
 *  Syntax            : Std_ReturnType Eth_DispatchVirtmacDelVlan(uint8 CtrlIdx, uint32 vlanId)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : 0x29
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : CtrlIdx: Index of the controller within the context of the
 *                                Ethernet Driver
 *                      vlanId: Vlan Id which is to be removed from switch VLAN membership table
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      :  Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: otherwise
 *
 *  Description       :  The function dispatches RPC command to ethernet
 *                       firmware core to leave a VLAN previously joined
 *                       through Eth_DispatchVirtmacAddVlan().
 *                       If configured in virtual mac mode application should
 *                       invoke this API as follows:
 *                       1. Eth_VirtMacRpcInit()
 *                       2. Wait for fwRegisteredCb() callback
 *                       3. Eth_DispatchVirtmacInit
 *                       4. Wait for rpcCmdComplete() callback with status E_OK
 *                       5. Eth_Init()
 *                       6. Eth_DispatchVirtmacSubscribeDstMac()
 *                       7. Wait for rpcCmdComplete() callback with status E_OK
 *                       8. Eth_DispatchVirtmacAddVlan()
 *                       9. Wait for rpcCmdComplete() callback with status E_OK
 *                       10. Eth_DispatchVirtmacDelVlan()
 *                       11. Wait for rpcCmdComplete() callback with status E_OK
 *                       The callbacks fwRegisteredCb() and rpcCmdComplete() are
 *                       populated by the application as part of the Eth_ConfigType
 *                       structure
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_DispatchVirtmacDelVlan(uint8 CtrlIdx, uint32 vlanId);
#endif  /* ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_DEL_VLAN_API)) */

#if (STD_ON == ETH_VIRTUALMAC_SUPPORT)
/**
 *  \brief Dispatch virtual mac port link status
 *
 *  \verbatim
 *  Service name      : Eth_DispatchVirtmacLinkStatus
 *  Syntax            : Std_ReturnType Eth_DispatchVirtmacLinkStatus(CtrlIdx)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : 0x3EU
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : CtrlIdx. Index of the controller within the context of the
 *                                Ethernet Driver
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      :  Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: failed
 *
 *  Description       :  The function dispatches RPC command to ethernet
 *                       transceiver to get link status
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_DispatchVirtmacLinkStatus(uint8 CtrlIdx);
#endif  /* (STD_ON == ETH_VIRTUALMAC_SUPPORT) */

#if (STD_ON == ETH_VIRTUALMAC_SUPPORT)
/**
 *  The function checks for state related to EthFw(attach/error, or new message from EthFw)
 *         polling state changes.
 *
 *  \verbatim
 *  Service name      : Eth_VirtMac_MainFunction
 *  Syntax            : Std_ReturnType Eth_VirtMac_MainFunction(uint8 CtrlIdx)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : None
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : CtrlIdx: Index of the controller within the context of the
 *                                Ethernet Drivere
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      : None
 *
 *  Description       :  The function check the controller state(firmware attach state or 
 *                       recovery state)
 *  \endverbatim
 */
FUNC(void, ETH_CODE)
Eth_VirtMac_MainFunction(uint8 ctrlIdx);
#endif  /* ((STD_ON == ETH_VIRTUALMAC_SUPPORT) */

#if (STD_ON == ETH_VIRTUALMAC_SUPPORT)
/**
 *  The function gets the link status of the virtual MAC device:
 *  (0) link down, (1) link up.
 *
 *  \verbatim
 *  Service name      : Eth_VirtmacGetLinkStatus
 *  Syntax            : Eth_VirtmacGetLinkStatus(uint8 ctrlIdx, boolean *linkStatusPtr)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : None
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : ctrlIdx: Index of the controller within the context of the
 *                                Ethernet Driver
 *                      linkStatusPtr: Pointer to link status variable.
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      :  Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: Failure to retrieve link status remotely
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_VirtmacGetLinkStatus(uint8 ctrlIdx, boolean *linkStatusPtr);
#endif  /* (STD_ON == ETH_VIRTUALMAC_SUPPORT) */

#if (STD_ON == ETH_VIRTUALMAC_SUPPORT)
/**
 *  The function gets the link duplexity of the virtual MAC device.  Duplexity values
 *  are reported consistently with EthTrcv_BaudRateType: (0) 10Mbps, (1) 100Mbps and
 *  (2) 1Gbps.
 *
 *  \verbatim
 *  Service name      : Eth_VirtmacGetLinkSpeed
 *  Syntax            : Eth_VirtmacGetLinkSpeed(uint8 ctrlIdx, uint32 *linkSpeedPtr)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : None
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : ctrlIdx: Index of the controller within the context of the
 *                                Ethernet Driver
 *                      linkSpeedPtr: Pointer to link speed variable
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      :  Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: Failure to retrieve link speed remotely
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_VirtmacGetLinkSpeed(uint8 ctrlIdx, uint32 *linkSpeedPtr);
#endif  /* (STD_ON == ETH_VIRTUALMAC_SUPPORT) */

#if (STD_ON == ETH_VIRTUALMAC_SUPPORT)
/**
 *  The function gets the link speed of the virtual MAC device.  Speed values are
 *  reported consistently with EthTrcv_DuplexModeType: (0) Half duplex,
 *  (1) Full duplex.
 *
 *  \verbatim
 *  Service name      : Eth_VirtmacGetLinkDuplexity
 *  Syntax            : Eth_VirtmacGetLinkDuplexity(uint8 ctrlIdx, uint32 *linkDuplexityPtr)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : None
 *  Sync/Async        : Asynchronous
 *  Reentrancy        : Non-Reentrant
 *  Parameters (in)   : ctrlIdx: Index of the controller within the context of the
 *                                Ethernet Driver
 *                      linkDuplexityPtr: Pointer to link duplexity variable
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      :  Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: Failure to retrieve link duplexity remotely
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_VirtmacGetLinkDuplexity(uint8 ctrlIdx, uint32 *linkDuplexityPtr);
#endif  /* (STD_ON == ETH_VIRTUALMAC_SUPPORT) */


#if ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_INTERCORE_ENABLE))
/**
 *  \brief This function provides access to a transmit buffer of the specified
 *         controller.
 *
 *  \verbatim
 *  Service name      : Eth_VirtMacInterCoreProvideTxBuffer
 *  Syntax            : BufReq_ReturnType Eth_VirtMacInterCoreProvideTxBuffer(
 *                          uint8 CtrlIdx,
 *                          uint8 Priority,
 *                          uint8* BufIdxPtr,
 *                          uint8** BufPtr,
 *                          uint16* LenBytePtr
 *                      )
 *  Mode              : User Mode (Non-Privileged Mode)
 *  Service ID[hex]   : 0x09
 *  Sync/Async        : Synchronous
 *  Reentrancy        : Non Reentrant
 *  Parameters (in)   : CtrlIdx. Index of the controller within the context of the
 *                               Ethernet Driver
 *  Parameters (in)   : Priority. Frame priority for transmit buffer FIFO selection
 *  Parameters (inout): LenBytePtr
 *                        In: desired length in bytes, out: granted length in bytes
 *  Parameters (out)  : BufIdxPtr. Index to the granted buffer resource. To be used
 *                                 for subsequent requests
 *                      BufPtr. Pointer to the granted buffer
 *  Return value      : BufReq_ReturnType
 *                        BUFREQ_OK: success
 *                        BUFREQ_E_NOT_OK: development error detected
 *                        BUFREQ_E_BUSY: all buffers in use
 *                        BUFREQ_E_OVFL: requested buffer too large
 *  Description       : Provides access to a transmit buffer of the specified
 *                      controller.
 *  \endverbatim
 */
FUNC(BufReq_ReturnType, ETH_CODE)
Eth_VirtMacInterCoreProvideTxBuffer(uint8 CtrlIdx,
                    uint8 Priority,
                    P2VAR(Eth_BufIdxType, AUTOMATIC, ETH_APPL_DAT) BufIdxPtr,
                    P2VAR(uint8, AUTOMATIC, ETH_APPL_DAT) *BufPtr,
                    P2VAR(uint16, AUTOMATIC, ETH_APPL_DAT) LenBytePtr);
#endif  /* (STD_ON == ETH_VIRTUALMAC_SUPPORT) */

#if ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_INTERCORE_ENABLE))
/**
 *  \brief This function triggers transmission of a previously filled transmit
 *         buffer.
 *
 *  \verbatim
 *  Service name      : Eth_VirtMacInterCoreTransmit
 *  Syntax            : Std_ReturnType Eth_VirtMacInterCoreTransmit(
 *                          uint8 CtrlIdx,
 *                          Eth_BufIdxType BufIdx,
 *                          Eth_FrameType FrameType,
 *                          boolean TxConfirmation,
 *                          uint16 LenByte,
 *                          uint8 *PhysAddrPtr)
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : 0xA
 *  Sync/Async        : Synchronous
 *  Reentrancy        : Non Reentrant
 *  Parameters (in)   : CtrlIdx. Index of the controller within the context of the
 *                               Ethernet Driver
 *                      BufIdx. Index of the buffer resource
 *                      FrameType. Ethernet frame type
 *                      TxConfirmation. Activates transmission confirmation
 *                      LenByte. Data length in byte
 *                      PhysAddrPtr. Physical target address (MAC address) in
 *                                   network byte order
 *  Parameters (inout): None
 *  Parameters (out)  : None
 *  Return value      : Std_ReturnType
 *                        E_OK: success
 *                        E_NOT_OK: transmission failed
 *  Description       : Triggers transmission of a previously filled transmit
 *                      buffer.
 *  \endverbatim
 */
FUNC(Std_ReturnType, ETH_CODE)
Eth_VirtMacInterCoreTransmit(uint8 CtrlIdx,
             Eth_BufIdxType BufIdx,
             Eth_FrameType FrameType,
             boolean TxConfirmation,
             uint16 LenByte,
             P2CONST(uint8, AUTOMATIC, ETH_APPL_DAT) PhysAddrPtr);
#endif  /* (STD_ON == ETH_VIRTUALMAC_SUPPORT) */

#if ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_INTERCORE_ENABLE))
/**
 *  \brief This function triggers frame reception.
 *
 *  \verbatim
 *  Service name      : Eth_VirtMacInterCoreReceive
 *  Syntax            : void Eth_VirtMacInterCoreReceive(
 *                          uint8 CtrlIdx,
 *                          uint8 FifoIdx,
 *                          Eth_RxStatusType* RxStatusPtr
 *                      )
 *  Mode              : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]   : 0xB
 *  Sync/Async        : Synchronous
 *  Reentrancy        : Non Reentrant
 *  Parameters (in)   : CtrlIdx. Index of the controller within the context of the
 *                               Ethernet Driver
 *  Parameters (in)   : FifoIdx. Specifies the related fifo
 *  Parameters (inout): None
 *  Parameters (out)  : RxStatusPtr. Indicates whether a frame has been received and
 *                                   if so, whether more frames are available or
 *                                   frames got lost
 *  Return value      : None
 *  Description       : Triggers frame reception.
 *  \endverbatim
 */
FUNC(void, ETH_CODE)
Eth_VirtMacInterCoreReceive(uint8 CtrlIdx,
            uint8 FifoIdx,
            P2VAR(Eth_RxStatusType, AUTOMATIC, ETH_APPL_DAT) RxStatusPtr);
#endif  /* (STD_ON == ETH_VIRTUALMAC_SUPPORT) */


#ifdef __cplusplus
}
#endif

#endif

/*! @} */