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
 *  \file     Eth.c
 *
 *  \brief    This file contains the implementation of the main APIs
 *            of the Ethernet driver.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <string.h>
#include "Eth.h"
#if (STD_ON == ETH_DEV_ERROR_DETECT)
#include "Det.h"
#endif
#include "Eth_Priv.h"
#include "Eth_Rpc.h"
#include "Eth_RpcPriv.h"
#include "Cdd_Ipc.h"
#include "Eth_Cfg.h"

#if (STD_ON == ETH_VIRTUALMAC_SUPPORT)

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief Data Structure of mapping between Rpc Cmd to SID
 */
typedef struct Eth_RpcCmdToSidInfoMapType_s
{
    uint8 sid;
    /**< Service ID */
    boolean isInternal;
    /**< Is internal service */
} Eth_RpcCmdToSidInfoMapType;

/**< \brief Rpc cmd handler function */
typedef Std_ReturnType (*EthRpc_Handler)(uint8 ctrlIdx,
                                         uint8 callerApiId,
                                         EthRemoteCfg_MsgHdr *hdr);

/**
 *  \brief Data Structure of mapping between Rpc message Id and handler
 */
typedef struct Eth_RpcMsgToHandlerType_s
{
    EthRpc_Handler handler;
    /**< Command handler */
    uint32 msgLen;
    /**< Expected message length */
} Eth_RpcMsgToHandlerType;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

static Std_ReturnType Eth_RpcFwInfoResProc(uint8 ctrlIdx,
                                           uint8 callerApiId,
                                           EthRemoteCfg_MsgHdr *hdr);
static Std_ReturnType Eth_RpcAttachExtResProc(uint8 ctrlIdx,
                                              uint8 callerApiId,
                                              EthRemoteCfg_MsgHdr *hdr);
static Std_ReturnType Eth_RpcTeardownCompleteResProc(uint8 ctrlIdx,
                                                     uint8 callerApiId,
                                                     EthRemoteCfg_MsgHdr *hdr);
static Std_ReturnType Eth_RpcGenericResProc(uint8 ctrlIdx,
                                            uint8 callerApiId,
                                            EthRemoteCfg_MsgHdr *hdr);
static Std_ReturnType Eth_RpcHwErrorProc(uint8 ctrlIdx,
                                         uint8 callerApiId,
                                         EthRemoteCfg_MsgHdr *hdr);
static Std_ReturnType Eth_RpcHwRecoveryCompleteProc(uint8 ctrlIdx,
                                                    uint8 callerApiId,
                                                    EthRemoteCfg_MsgHdr *hdr);
static Std_ReturnType Eth_RpcSendLinkStatusResProc(uint8 ctrlIdx,
                                                   uint8 callerApiId,
                                                   EthRemoteCfg_MsgHdr *hdr);

static void Eth_RpcSetupHdrCmd(uint8 ctrlIdx,
                               EthRemoteCfg_CmdType reqType,
                               EthRemoteCfg_ReqHdr *req);

static void Eth_RpcCmdRespondWithErrorStatus(uint8 ctrlIdx,
                                           const EthRemoteCfg_ResHdr* hdr);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#define  ETH_START_SEC_CONST_UNSPECIFIED
#include "Eth_MemMap.h"
/**
 *  \brief Table mapping between RpcCmd to SID
 */
static CONST(Eth_RpcCmdToSidInfoMapType, ETH_VAR_NO_INIT) rpcCmdToSidInfo[ETHREMOTECFG_CMD_TYPE_COUNT] =
{
    /* ETHREMOTECFG_* commands  */
    /* OFFER_VIRT_PORT          */ { 0xFFU,                                              FALSE },
    /* ATTACH                   */ { 0xFFU,                                              FALSE },
    /* ATTACH_EXT               */ { ETH_SID_DISPATCH_VIRTMAC_INIT,                      FALSE },
    /* DETACH                   */ { ETH_SID_DISPATCH_VIRTMAC_DEINIT,                    FALSE },
    /* PORT_LINK_STATUS         */ { ETH_SID_DISPATCH_VIRTMAC_PORT_LINK_STATUS,          FALSE },
    /* ALLOC_TX                 */ { 0xFFU,                                              FALSE },
    /* ALLOC_RX                 */ { 0xFFU,                                              FALSE },
    /* ALLOC_MAC                */ { 0xFFU,                                              FALSE },
    /* FREE_TX                  */ { 0xFFU,                                              FALSE },
    /* FREE_RX                  */ { 0xFFU,                                              FALSE },
    /* FREE_MAC                 */ { 0xFFU,                                              FALSE },
    /* REGISTER_MAC             */ { ETH_SID_DISPATCH_VIRTMAC_SUBSCRIBE_DSTMAC,          FALSE },
    /* DEREGISTER_MAC           */ { ETH_SID_DISPATCH_VIRTMAC_UNSUBSCRIBE_DSTMAC,        FALSE },
    /* SET_RX_DEFAULTFLOW       */ { ETH_SID_DISPATCH_VIRTMAC_SUBSCRIBE_ALLTRAFFIC,      FALSE },
    /* DEL_RX_DEFAULTFLOW       */ { ETH_SID_DISPATCH_VIRTMAC_UNSUBSCRIBE_ALLTRAFFIC,    FALSE },
    /* REGISTER_IPv4            */ { ETH_SID_DISPATCH_VIRTMAC_IPV4_MACADDR_ASSOCIATE,    FALSE },
    /* DEREGISTER_IPv4          */ { ETH_SID_DISPATCH_VIRTMAC_IPV4_MACADDR_DISASSOCIATE, FALSE },
    /* JOIN_VLAN                */ { ETH_SID_DISPATCH_VIRTMAC_ADD_VLAN,                  FALSE },
    /* LEAVE_VLAN               */ { ETH_SID_DISPATCH_VIRTMAC_DEL_VLAN,                  FALSE },
    /* ADD_FILTER_MAC           */ { ETH_SID_DISPATCH_VIRTMAC_ADD_MCAST_MACADDR,         FALSE },
    /* DEL_FILTER_MAC           */ { ETH_SID_DISPATCH_VIRTMAC_DEL_MACADDR,               FALSE },
    /* REGISTER_MATCH_ETHTYPE   */ { 0xFFU,                                              FALSE },
    /* DEREGISTER_MATCH_ETHTYPE */ { 0xFFU,                                              FALSE },
    /* REGISTER_REMOTE_TIMER    */ { 0xFFU,                                              FALSE },
    /* DEREGISTER_REMOTE_TIMER  */ { 0xFFU,                                              FALSE },
    /* GET_SERVER_STATUS        */ { 0xFFU,                                              FALSE },
    /* TEARDOWN_COMPLETION      */ { 0xFFU,                                              TRUE  },
    /* DUMP                     */ { 0xFFU,                                              FALSE },
    /* ALLOC_CPTS_HW_PUSH       */ { 0xFFU,                                              FALSE },
    /* FREE_CPTS_HW_PUSH        */ { 0xFFU,                                              FALSE },
};

/**
 *  \brief Table mapping between RpcCmd to handler
 */
static CONST(Eth_RpcMsgToHandlerType, ETH_VAR_NO_INIT) rpcCmdToHandler[ETHREMOTECFG_CMD_TYPE_COUNT] =
{
    /* ETHREMOTECFG_* commands  */
    /* OFFER_VIRT_PORT          */ { (EthRpc_Handler)NULL_PTR,      0U },
    /* ATTACH                   */ { (EthRpc_Handler)NULL_PTR,      0U },
    /* ATTACH_EXT               */ { &Eth_RpcAttachExtResProc,      sizeof(EthRemoteCfg_AttachExtRes) },
    /* DETACH                   */ { &Eth_RpcGenericResProc,        sizeof(EthRemoteCfg_StatusRes) },
    /* PORT_LINK_STATUS         */ { &Eth_RpcSendLinkStatusResProc, sizeof(EthRemoteCfg_PortLinkStatusRes) },
    /* ALLOC_TX                 */ { (EthRpc_Handler)NULL_PTR,      0U },
    /* ALLOC_RX                 */ { (EthRpc_Handler)NULL_PTR,      0U },
    /* ALLOC_MAC                */ { (EthRpc_Handler)NULL_PTR,      0U },
    /* FREE_TX                  */ { (EthRpc_Handler)NULL_PTR,      0U },
    /* FREE_RX                  */ { (EthRpc_Handler)NULL_PTR,      0U },
    /* FREE_MAC                 */ { (EthRpc_Handler)NULL_PTR,      0U },
    /* REGISTER_MAC             */ { &Eth_RpcGenericResProc,        sizeof(EthRemoteCfg_StatusRes) },
    /* DEREGISTER_MAC           */ { &Eth_RpcGenericResProc,        sizeof(EthRemoteCfg_StatusRes) },
    /* SET_RX_DEFAULTFLOW       */ { (EthRpc_Handler)NULL_PTR,      0U },
    /* DEL_RX_DEFAULTFLOW       */ { (EthRpc_Handler)NULL_PTR,      0U },
    /* REGISTER_IPv4            */ { &Eth_RpcGenericResProc,        sizeof(EthRemoteCfg_StatusRes) },
    /* DEREGISTER_IPv4          */ { &Eth_RpcGenericResProc,        sizeof(EthRemoteCfg_StatusRes) },
    /* JOIN_VLAN                */ { &Eth_RpcGenericResProc,        sizeof(EthRemoteCfg_StatusRes) },
    /* LEAVE_VLAN               */ { &Eth_RpcGenericResProc,        sizeof(EthRemoteCfg_StatusRes) },
    /* ADD_FILTER_MAC           */ { &Eth_RpcGenericResProc,        sizeof(EthRemoteCfg_StatusRes) },
    /* DEL_FILTER_MAC           */ { &Eth_RpcGenericResProc,        sizeof(EthRemoteCfg_StatusRes) },
    /* REGISTER_MATCH_ETHTYPE   */ { (EthRpc_Handler)NULL_PTR,      0U },
    /* DEREGISTER_MATCH_ETHTYPE */ { (EthRpc_Handler)NULL_PTR,      0U },
    /* REGISTER_REMOTE_TIMER    */ { (EthRpc_Handler)NULL_PTR,      0U },
    /* DEREGISTER_REMOTE_TIMER  */ { (EthRpc_Handler)NULL_PTR,      0U },
    /* GET_SERVER_STATUS        */ { (EthRpc_Handler)NULL_PTR,      0U },
    /* TEARDOWN_COMPLETION      */ { &Eth_RpcTeardownCompleteResProc, sizeof(EthRemoteCfg_StatusRes) },
    /* DUMP                     */ { (EthRpc_Handler)NULL_PTR,      0U },
    /* ALLOC_CPTS_HW_PUSH       */ { (EthRpc_Handler)NULL_PTR,      0U },
    /* FREE_CPTS_HW_PUSH        */ { (EthRpc_Handler)NULL_PTR,      0U },
};

/**
 *  \brief Table mapping between notify message to handler
 */
static CONST(Eth_RpcMsgToHandlerType, ETH_VAR_NO_INIT) rpcNotifyToHandler[ETHREMOTECFG_NOTIFY_TYPE_COUNT] =
{
    /* ETHREMOTECFG_* notify           */
    /* NOTIFYCLIENT_FWINFO             */ { &Eth_RpcFwInfoResProc,          sizeof(EthRemoteCfg_DeviceData) },
    /* NOTIFYCLIENT_HWPUSH             */ { (EthRpc_Handler)NULL_PTR,       0U },
    /* NOTIFYTYPE_HWERROR              */ { &Eth_RpcHwErrorProc,            sizeof(EthRemoteCfg_CommonNotify) },
    /* NOTIFYTYPE_HWRECOVERY_COMPLETE  */ { &Eth_RpcHwRecoveryCompleteProc, sizeof(EthRemoteCfg_CommonNotify) },
    /* NOTIFYCLIENT_CUSTOM             */ { (EthRpc_Handler)NULL_PTR,       0U },
};

#define  ETH_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_MemMap.h"

/* ========================================================================== */
/*                  Internal Function Definitions                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"

static void Eth_RpcSetupHdrCmd(uint8 ctrlIdx,
                               EthRemoteCfg_CmdType reqType,
                               EthRemoteCfg_ReqHdr *req)
{
    req->common.msgType  = ETHREMOTECFG_MSGTYPE_REQUEST;
    req->common.clientId = ETHREMOTECFG_CLIENTID_AUTOSAR;
    req->common.token    = Eth_VirtMacInfo[ctrlIdx].token;

    req->reqType = (uint32)reqType;
    req->reqId   = Eth_VirtMacInfo[ctrlIdx].reqId;
    Eth_VirtMacInfo[ctrlIdx].reqId++;
}

static Std_ReturnType Eth_RpcSendCmd(uint8 ctrlIdx,
                                     EthRemoteCfg_CmdType reqType,
                                     const void* reqData,
                                     uint32 reqLen)
{
    Std_ReturnType status;

    status = Cdd_IpcSendMsg(Eth_VirtMacGetEthFwRpcComChannelId(ctrlIdx),
                            reqData, reqLen);

    (void)reqType; /* future use */
    (void)ctrlIdx; /* turn off warning in case precompile */
    return status;
}

Std_ReturnType Eth_RpcSendExtendedAttachReq(uint8 ctrlIdx)
{
    EthRemoteCfg_AttachReq req;
    Std_ReturnType status;

    if ((Eth_VirtMacInfo[ctrlIdx].ethFwAttached == TRUE) &&
        (Eth_VirtMacInfo[ctrlIdx].detachResponsePending == FALSE) &&
        (Eth_VirtMacInfo[ctrlIdx].token == ETHREMOTECFG_TOKEN_NONE))
    {
        req.virtPort = Eth_VirtMacGetRemoteVirtPort(ctrlIdx);
        Eth_RpcSetupHdrCmd(ctrlIdx, ETHREMOTECFG_CMD_ATTACH_EXT, &req.hdr);
        status = Eth_RpcSendCmd(ctrlIdx, ETHREMOTECFG_CMD_ATTACH_EXT,
                                (const void*)&req, sizeof(req));
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

Std_ReturnType Eth_RpcSendDetachReq(uint8 ctrlIdx)
{
    EthRemoteCfg_ReqHdr req;
    Std_ReturnType status;

    if ((Eth_VirtMacInfo[ctrlIdx].ethFwAttached == TRUE) &&
        (Eth_VirtMacInfo[ctrlIdx].detachResponsePending == FALSE) &&
        (Eth_VirtMacInfo[ctrlIdx].token != ETHREMOTECFG_TOKEN_NONE))
    {
        Eth_RpcSetupHdrCmd(ctrlIdx, ETHREMOTECFG_CMD_DETACH, &req);
        status = Eth_RpcSendCmd(ctrlIdx, ETHREMOTECFG_CMD_DETACH,
                                (const void*)&req, sizeof(req));
        if (E_OK == status)
        {
            /* Clear Cpsw Handle Info on sending the DETACH request */
            Eth_VirtMacInfo[ctrlIdx].token = ETHREMOTECFG_TOKEN_NONE;
        }
        else
        {
            /* If IpcSendMsg failed, clear the response pending flag */
            Eth_VirtMacInfo[ctrlIdx].detachResponsePending = FALSE;
        }
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

Std_ReturnType Eth_RpcSendLinkStatusReq(uint8 ctrlIdx)
{
    EthRemoteCfg_CommonReq req;
    Std_ReturnType status;

    if ((Eth_VirtMacInfo[ctrlIdx].ethFwAttached == TRUE) &&
        (Eth_VirtMacInfo[ctrlIdx].token != ETHREMOTECFG_TOKEN_NONE))
    {

        Eth_RpcSetupHdrCmd(ctrlIdx, ETHREMOTECFG_CMD_PORT_LINK_STATUS, &req.hdr);
        status = Eth_RpcSendCmd(ctrlIdx, ETHREMOTECFG_CMD_PORT_LINK_STATUS,
                                (const void*)&req, sizeof(req));
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

Std_ReturnType Eth_RpcSendRegisterDefaultReq(uint8 ctrlIdx)
{
    EthRemoteCfg_RxDefaultFlowRegisterReq req;
    Std_ReturnType status;

    if ((Eth_VirtMacInfo[ctrlIdx].ethFwAttached == TRUE) &&
        (Eth_VirtMacInfo[ctrlIdx].token != ETHREMOTECFG_TOKEN_NONE))
    {
        req.flowIdxBase = Eth_VirtMacInfo[ctrlIdx].rxFlowStartIdx;
        req.flowIdxOffset = Eth_VirtMacInfo[ctrlIdx].rxFlowIdx;

        Eth_RpcSetupHdrCmd(ctrlIdx, ETHREMOTECFG_CMD_SET_RX_DEFAULTFLOW, &req.hdr);
        status = Eth_RpcSendCmd(ctrlIdx, ETHREMOTECFG_CMD_SET_RX_DEFAULTFLOW,
                                (const void*)&req, sizeof(req));
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

Std_ReturnType Eth_RpcSendUnregisterDefaultReq(uint8 ctrlIdx)
{
    EthRemoteCfg_RxDefaultFlowRegisterReq req;
    Std_ReturnType status;

    if ((Eth_VirtMacInfo[ctrlIdx].ethFwAttached == TRUE) &&
        (Eth_VirtMacInfo[ctrlIdx].token != ETHREMOTECFG_TOKEN_NONE))
    {
        req.flowIdxBase = Eth_VirtMacInfo[ctrlIdx].rxFlowStartIdx;
        req.flowIdxOffset = Eth_VirtMacInfo[ctrlIdx].rxFlowIdx;

        Eth_RpcSetupHdrCmd(ctrlIdx, ETHREMOTECFG_CMD_DEL_RX_DEFAULTFLOW, &req.hdr);
        status = Eth_RpcSendCmd(ctrlIdx, ETHREMOTECFG_CMD_DEL_RX_DEFAULTFLOW,
                                (const void*)&req, sizeof(req));
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

Std_ReturnType Eth_RpcSendRegisterMacReq(uint8 ctrlIdx, uint8 *macAddress)
{
    EthRemoteCfg_MacAddrRxFlowReq req;
    Std_ReturnType status;

    if ((Eth_VirtMacInfo[ctrlIdx].ethFwAttached == TRUE) &&
        (Eth_VirtMacInfo[ctrlIdx].token != ETHREMOTECFG_TOKEN_NONE))
    {
        req.flowIdxBase = Eth_VirtMacInfo[ctrlIdx].rxFlowStartIdx;
        req.flowIdxOffset = Eth_VirtMacInfo[ctrlIdx].rxFlowIdx;
        memcpy(&req.macAddr[0U], macAddress, sizeof(req.macAddr));

        Eth_RpcSetupHdrCmd(ctrlIdx, ETHREMOTECFG_CMD_REGISTER_MAC, &req.hdr);
        status = Eth_RpcSendCmd(ctrlIdx, ETHREMOTECFG_CMD_REGISTER_MAC,
                                (const void*)&req, sizeof(req));
    }
    else
    {
        status = E_NOT_OK;
    }

    return  status;
}

Std_ReturnType Eth_RpcSendUnregisterMacReq(uint8 ctrlIdx, uint8 *macAddress)
{
    EthRemoteCfg_MacAddrRxFlowReq req;
    Std_ReturnType status;

    if ((Eth_VirtMacInfo[ctrlIdx].ethFwAttached == TRUE) &&
        (Eth_VirtMacInfo[ctrlIdx].token != ETHREMOTECFG_TOKEN_NONE))
    {
        req.flowIdxBase = Eth_VirtMacInfo[ctrlIdx].rxFlowStartIdx;
        req.flowIdxOffset = Eth_VirtMacInfo[ctrlIdx].rxFlowIdx;
        memcpy(&req.macAddr[0U], macAddress, sizeof(req.macAddr));

        Eth_RpcSetupHdrCmd(ctrlIdx, ETHREMOTECFG_CMD_DEREGISTER_MAC, &req.hdr);
        status = Eth_RpcSendCmd(ctrlIdx, ETHREMOTECFG_CMD_DEREGISTER_MAC,
                                (const void*)&req, sizeof(req));
    }
    else
    {
        status = E_NOT_OK;
    }

    return  status;
}

Std_ReturnType Eth_RpcSendIPv4RegisterMacReq(uint8 ctrlIdx,
                                             uint8 *ipv4Address,
                                             uint8 *macAddress)
{
    EthRemoteCfg_IPv4AddrRegisterReq req;
    Std_ReturnType status;

    if ((Eth_VirtMacInfo[ctrlIdx].ethFwAttached == TRUE) &&
        (Eth_VirtMacInfo[ctrlIdx].token != ETHREMOTECFG_TOKEN_NONE))
    {
        memcpy(&req.macAddr[0U], macAddress, sizeof(req.macAddr));
        memcpy(&req.ipAddr[0U], ipv4Address, sizeof(req.ipAddr));

        Eth_RpcSetupHdrCmd(ctrlIdx, ETHREMOTECFG_CMD_REGISTER_IPv4, &req.hdr);
        status = Eth_RpcSendCmd(ctrlIdx, ETHREMOTECFG_CMD_REGISTER_IPv4,
                                (const void*)&req, sizeof(req));
    }
    else
    {
        status = E_NOT_OK;
    }

    return  status;
}

Std_ReturnType Eth_RpcSendIPv4UnregisterMacReq(uint8 ctrlIdx,
                                               uint8 *ipv4Address)
{
    EthRemoteCfg_IPv4AddrDeregisterReq req;
    Std_ReturnType status;

    if ((Eth_VirtMacInfo[ctrlIdx].ethFwAttached == TRUE) &&
        (Eth_VirtMacInfo[ctrlIdx].token != ETHREMOTECFG_TOKEN_NONE))
    {
        memcpy(&req.ipAddr[0U], ipv4Address, sizeof(req.ipAddr));

        Eth_RpcSetupHdrCmd(ctrlIdx, ETHREMOTECFG_CMD_DEREGISTER_IPv4, &req.hdr);
        status = Eth_RpcSendCmd(ctrlIdx, ETHREMOTECFG_CMD_DEREGISTER_IPv4,
                                (const void*)&req, sizeof(req));
    }
    else
    {
        status = E_NOT_OK;
    }

    return  status;
}

Std_ReturnType Eth_RpcSendAddMulticastEntry(uint8 ctrlIdx,
                                            const uint8 *macAddr,
                                            uint32 vlanId)
{
    EthRemoteCfg_FilterMacAddReq req;
    Std_ReturnType status;

    if ((Eth_VirtMacInfo[ctrlIdx].ethFwAttached == TRUE) &&
        (Eth_VirtMacInfo[ctrlIdx].token != ETHREMOTECFG_TOKEN_NONE))
    {
        memcpy(&req.macAddr[0U], macAddr, sizeof(req.macAddr));
        req.vlanId = (uint16)vlanId;
        req.flowIdxBase = Eth_VirtMacInfo[ctrlIdx].rxFlowStartIdx;
        req.flowIdxOffset = Eth_VirtMacInfo[ctrlIdx].rxFlowIdx;

        Eth_RpcSetupHdrCmd(ctrlIdx, ETHREMOTECFG_CMD_ADD_FILTER_MAC, &req.hdr);
        status = Eth_RpcSendCmd(ctrlIdx, ETHREMOTECFG_CMD_ADD_FILTER_MAC,
                                (const void*)&req, sizeof(req));
    }
    else
    {
        status = E_NOT_OK;
    }

    return  status;
}

Std_ReturnType Eth_RpcSendDelMulticastEntry(uint8 ctrlIdx,
                                            const uint8 *macAddr,
                                            uint32 vlanId)
{
    EthRemoteCfg_FilterMacDelReq req;
    Std_ReturnType status;

    if ((Eth_VirtMacInfo[ctrlIdx].ethFwAttached == TRUE) &&
        (Eth_VirtMacInfo[ctrlIdx].token != ETHREMOTECFG_TOKEN_NONE))
    {
        memcpy(&req.macAddr[0U], macAddr, sizeof(req.macAddr));
        req.vlanId = (uint16)vlanId;

        Eth_RpcSetupHdrCmd(ctrlIdx, ETHREMOTECFG_CMD_DEL_FILTER_MAC, &req.hdr);
        status = Eth_RpcSendCmd(ctrlIdx, ETHREMOTECFG_CMD_DEL_FILTER_MAC,
                                (const void*)&req, sizeof(req));
    }
    else
    {
        status = E_NOT_OK;
    }

    return  status;
}

static void Eth_RpcMapRpcRecvCmd2Sid(uint32 rpcCmd,
                                               boolean *isInternalCmd,
                                               uint8 *sid)
{
    *sid = rpcCmdToSidInfo[rpcCmd].sid;
    *isInternalCmd = rpcCmdToSidInfo[rpcCmd].isInternal;
}

static void Eth_RpcMsgStatusCb(uint8 ctrlIdx,
                               Eth_RpcCmdComplete rpcCmdComplete,
                               uint32 rpcCmdId,
                               sint32 status)
{
    boolean isInternalCmd;
    uint8 sid;

    /* Caller already verify rpcCmdId and this function is only use for external command */
    Eth_RpcMapRpcRecvCmd2Sid(rpcCmdId, &isInternalCmd, &sid);
    if (rpcCmdComplete != (Eth_RpcCmdComplete)NULL_PTR)
    {
        rpcCmdComplete(ctrlIdx, sid, status);
    }
    (void)isInternalCmd;
}

Std_ReturnType Eth_RpcAnnounce(uint8 ctrlIdx)
{
    uint8 *announceMsg = ((uint8 *)ETHREMOTECFG_AUTOSAR_REMOTE_SERVICE_NAME);
    Std_ReturnType status;

    status = Cdd_IpcAnnounce(announceMsg, Eth_VirtMacGetEthFwRpcComChannelId(ctrlIdx));
    return status;
}

static Std_ReturnType Eth_RpcFwInfoResProc(uint8 ctrlIdx,
                                           uint8 callerApiId,
                                           EthRemoteCfg_MsgHdr *hdr)
{
    EthRemoteCfg_DeviceData *devData = (EthRemoteCfg_DeviceData *)hdr;
    EthRemoteCfg_FwVerInfo *fwVer = &devData->fwVer;
    Std_ReturnType status;

    if (fwVer->major == ETHREMOTECFG_FW_ETHSWITCH_VERSION_MAJOR)
    {
        Eth_VirtMacInfo[ctrlIdx].fwInfo = *fwVer;
        Eth_VirtMacInfo[ctrlIdx].ethFwAttached = TRUE;
        if (Eth_VirtMacGetFwRegisterFuncPtr(ctrlIdx) != (Eth_RpcFwRegistered)NULL_PTR)
        {
            Eth_VirtMacGetFwRegisterFuncPtr(ctrlIdx)(ctrlIdx);
        }
        status = E_OK;
    }
    else
    {
        status = E_NOT_OK;
        #if (STD_ON == ETH_DEV_ERROR_DETECT)
        Eth_reportDetError(callerApiId, ETH_E_VIRTMAC_APIMISMATCH);
        #endif /* (STD_ON == ETH_DEV_ERROR_DETECT) */
    }

    return status;
}

static Std_ReturnType Eth_RpcHwErrorProc(uint8 ctrlIdx,
                                         uint8 callerApiId,
                                         EthRemoteCfg_MsgHdr *hdr)
{
    Std_ReturnType status = E_OK;
    (void)hdr;

    Eth_VirtMacInfo[ctrlIdx].s2CNotifyId = ETHREMOTECFG_NOTIFY_HWERROR;

    (void)callerApiId;

    return status;
}

static Std_ReturnType Eth_RpcHwRecoveryCompleteProc(uint8 ctrlIdx,
                                                    uint8 callerApiId,
                                                    EthRemoteCfg_MsgHdr *hdr)
{
    Std_ReturnType status = E_OK;

    Eth_VirtMacInfo[ctrlIdx].s2CNotifyId = ETHREMOTECFG_NOTIFY_HWRECOVERY_COMPLETE;

    (void)callerApiId;

    return status;
}

static Std_ReturnType Eth_RpcAttachExtResProc(uint8 ctrlIdx,
                                              uint8 callerApiId,
                                              EthRemoteCfg_MsgHdr *hdr)
{
    Std_ReturnType retVal = E_OK;

    EthRemoteCfg_AttachExtRes *res = (EthRemoteCfg_AttachExtRes *)hdr;

    Eth_RpcMsgStatusCb(ctrlIdx,
                       Eth_VirtMacGetRpcCmdCompleteFuncPtr(ctrlIdx),
                       res->hdr.resType,
                       res->hdr.status);

    Eth_VirtMacInfo[ctrlIdx].token          = res->hdr.common.token;
    Eth_VirtMacInfo[ctrlIdx].hostPortRxMtu  = res->rxMtu;
    Eth_VirtMacInfo[ctrlIdx].txPSILThreadId = res->txPsilDstId;
    Eth_VirtMacInfo[ctrlIdx].rxFlowStartIdx = res->rxFlowIdxBase;
    Eth_VirtMacInfo[ctrlIdx].rxFlowIdx      = res->rxFlowIdxOffset;
    Eth_VirtMacInfo[ctrlIdx].features       = res->features;
    Eth_VirtMacInfo[ctrlIdx].txMtu          = res->txMtu;

    if (Eth_UseDefaultMacAddress(ctrlIdx) == TRUE)
    {
        memcpy(Eth_VirtMacInfo[ctrlIdx].macAddress, res->macAddr,
               sizeof(Eth_VirtMacInfo[ctrlIdx].macAddress));
    }
    else
    {
        Eth_VirtMacInfo[ctrlIdx].macAddress[0u] = (uint8)((Eth_GetMacAddressHigh(ctrlIdx) >> 24u) & 0xFFu);
        Eth_VirtMacInfo[ctrlIdx].macAddress[1u] = (uint8)((Eth_GetMacAddressHigh(ctrlIdx) >> 16u) & 0xFFu);
        Eth_VirtMacInfo[ctrlIdx].macAddress[2u] = (uint8)((Eth_GetMacAddressHigh(ctrlIdx) >> 8u)  & 0xFFu);
        Eth_VirtMacInfo[ctrlIdx].macAddress[3u] = (uint8)((Eth_GetMacAddressHigh(ctrlIdx))        & 0xFFu);
        Eth_VirtMacInfo[ctrlIdx].macAddress[4u] = (uint8)((Eth_GetMacAddressLow(ctrlIdx)  >> 8u)  & 0xFFu);
        Eth_VirtMacInfo[ctrlIdx].macAddress[5u] = (uint8)((Eth_GetMacAddressLow(ctrlIdx))         & 0xFFu);
    }

    Eth_VirtMacInfo[ctrlIdx].features = res->features;

#if ((STD_ON == ETH_CTRL_ENABLE_OFFLOAD_CHECKSUM_TCP) || \
     (STD_ON == ETH_CTRL_ENABLE_OFFLOAD_CHECKSUM_UDP))
    if((Eth_VirtMacInfo[ctrlIdx].features & ETHREMOTECFG_FEATURE_TXCSUM) == FALSE)
    {
        retVal = E_NOT_OK;
    }
#endif

    (void)callerApiId;

    return retVal;
}

static Std_ReturnType Eth_RpcTeardownCompleteResProc(uint8 ctrlIdx,
                                                     uint8 callerApiId,
                                                     EthRemoteCfg_MsgHdr *hdr)
{
    (void)hdr;
    (void)callerApiId;

    Eth_VirtMacInfo[ctrlIdx].teardownResponsePending = FALSE;

    return E_OK;
}

static Std_ReturnType Eth_RpcGenericResProc(uint8 ctrlIdx,
                                            uint8 callerApiId,
                                            EthRemoteCfg_MsgHdr *hdr)
{
    EthRemoteCfg_StatusRes *res = (EthRemoteCfg_StatusRes *)hdr;
 
    Eth_RpcMsgStatusCb(ctrlIdx,
                       Eth_VirtMacGetRpcCmdCompleteFuncPtr(ctrlIdx),
                       res->hdr.resType,
                       res->hdr.status);

    (void)callerApiId;

    return E_OK;
}

static Std_ReturnType Eth_RpcSendLinkStatusResProc(uint8 ctrlIdx,
                                                   uint8 callerApiId,
                                                   EthRemoteCfg_MsgHdr *hdr)
{
    EthRemoteCfg_PortLinkStatusRes *res = (EthRemoteCfg_PortLinkStatusRes *)hdr;

    Eth_RpcMsgStatusCb(ctrlIdx,
                       Eth_VirtMacGetRpcCmdCompleteFuncPtr(ctrlIdx),
                       res->hdr.resType,
                       res->hdr.status);

    Eth_VirtMacInfo[ctrlIdx].linkStatus = res->isLinked;
    Eth_VirtMacInfo[ctrlIdx].linkSpeed = res->speed;
    Eth_VirtMacInfo[ctrlIdx].linkDuplexity = res->duplexity;

    (void)callerApiId;

    return E_OK;
}

static Std_ReturnType Eth_RpcCmdResHandler(uint8 ctrlIdx,
                                           uint8 callerApiId,
                                           EthRemoteCfg_MsgHdr *common,
                                           uint32 msgLen)
{
    EthRemoteCfg_ResHdr *hdr = (EthRemoteCfg_ResHdr *)common;
    Std_ReturnType status = E_NOT_OK;

    if ((hdr->resType <= ((uint32)ETHREMOTECFG_CMD_TYPE_LAST)) &&
        (msgLen == rpcCmdToHandler[hdr->resType].msgLen))
    {
        if (hdr->status == ETHREMOTECFG_SOK)
        {
            if (rpcCmdToHandler[hdr->resType].handler != (EthRpc_Handler)NULL_PTR)
            {
                status = rpcCmdToHandler[hdr->resType].handler(ctrlIdx,
                                                               callerApiId,
                                                               common);
            }
        }
        else
        {
            Eth_RpcCmdRespondWithErrorStatus(ctrlIdx, (const EthRemoteCfg_ResHdr*)hdr);
        }
    }

    return status;
}

static void Eth_RpcCmdRespondWithErrorStatus(uint8 ctrlIdx,
                                           const EthRemoteCfg_ResHdr* hdr)
{
    boolean isInternalCmd;
    uint8 sid;

    /* Caller already verify rpcCmdId */
    Eth_RpcMapRpcRecvCmd2Sid(hdr->resType, &isInternalCmd, &sid);
    if (isInternalCmd == TRUE)
    {
        /* For Rpc cmds initiated by the ETH Driver internally
         * only invoke DetReportError on failure */
        #if (STD_ON == ETH_DEV_ERROR_DETECT)
        Eth_reportDetError(sid, ETH_E_VIRTMAC_RPCCMDFAILED);
        #endif /* (STD_ON == ETH_DEV_ERROR_DETECT) */
    }
    else
    { 
        if (Eth_VirtMacGetRpcCmdCompleteFuncPtr(ctrlIdx) != (Eth_RpcCmdComplete)NULL_PTR)
        {
            Eth_VirtMacGetRpcCmdCompleteFuncPtr(ctrlIdx)(ctrlIdx, sid, hdr->status);
        }
    }
}

static Std_ReturnType Eth_RpcNotifyHandler(uint8 ctrlIdx,
                                           uint8 callerApiId,
                                           EthRemoteCfg_MsgHdr *common,
                                           uint32 msgLen)
{
    EthRemoteCfg_NotifyHdr *hdr = (EthRemoteCfg_NotifyHdr *)common;
    Std_ReturnType status = E_NOT_OK;

    if (hdr->notifyType <= ((uint32)ETHREMOTECFG_NOTIFY_LAST))
    {
        if (msgLen == rpcNotifyToHandler[hdr->notifyType].msgLen)
        {
            if (rpcNotifyToHandler[hdr->notifyType].handler != (EthRpc_Handler)NULL_PTR)
            {
                status = rpcNotifyToHandler[hdr->notifyType].handler(ctrlIdx,
                                                                     callerApiId,
                                                                     common);
            }
        }
        else
        {
            #if (STD_ON == ETH_DEV_ERROR_DETECT)
            Eth_reportDetError(callerApiId, ETH_E_VIRTMAC_UNSUPPORTEDSRVCMD);
            #endif /* (STD_ON == ETH_DEV_ERROR_DETECT) */
        }

    }
    else
    {
        #if (STD_ON == ETH_DEV_ERROR_DETECT)
        Eth_reportDetError(callerApiId, ETH_E_VIRTMAC_UNSUPPORTECLIENTNOTIFY);
        #endif /* (STD_ON == ETH_DEV_ERROR_DETECT) */
    }

    return status;
}


static Std_ReturnType Eth_RpcRecvMsgInternal(uint8 ctrlIdx,
                                             uint8 callerApiId,
                                             uint8 *msgBuffer,
                                             uint32 msgLen)
{
    EthRemoteCfg_MsgHdr *common = (EthRemoteCfg_MsgHdr *)msgBuffer;
    Std_ReturnType status;

    if (common->msgType == ((uint32)ETHREMOTECFG_MSGTYPE_RESPONSE))
    {
        status = Eth_RpcCmdResHandler(ctrlIdx, callerApiId, common, msgLen);
    }
    else if (common->msgType == ((uint32)ETHREMOTECFG_MSGTYPE_NOTIFY))
    {
        status = Eth_RpcNotifyHandler(ctrlIdx, callerApiId, common, msgLen);
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

Std_ReturnType Eth_RpcRecvMsg(uint8 ctrlIdx, uint8 callerApiId)
{
    uint64 msgBuffer[(ETHREMOTECFG_IPC_MSG_SIZE / sizeof(uint64))];
    uint32 msgSize;
    Std_ReturnType status;

    msgSize = sizeof(msgBuffer);
    status = Cdd_IpcReceiveMsg(Eth_VirtMacGetEthFwRpcComChannelId(ctrlIdx),
                               &msgBuffer, &msgSize);

    if ((status == E_OK) && (msgSize <= sizeof(msgBuffer)))
    {
        status = Eth_RpcRecvMsgInternal(ctrlIdx, callerApiId, (uint8*)msgBuffer, msgSize);
    }

    return status;
}


Std_ReturnType Eth_RpcSendAddVlan(uint8 ctrlIdx,
                                  uint32 vlanId)
{
    EthRemoteCfg_VlanJoinReq req;
    Std_ReturnType status;

    if ((Eth_VirtMacInfo[ctrlIdx].ethFwAttached == TRUE) &&
        (Eth_VirtMacInfo[ctrlIdx].token != ETHREMOTECFG_TOKEN_NONE))
    {
        req.vlanId = (uint16)vlanId;
        req.flowIdxBase = Eth_VirtMacInfo[ctrlIdx].rxFlowStartIdx;
        req.flowIdxOffset = Eth_VirtMacInfo[ctrlIdx].rxFlowIdx;
        memcpy(&req.macAddr[0], Eth_VirtMacInfo[ctrlIdx].macAddress,
               sizeof(req.macAddr));

        Eth_RpcSetupHdrCmd(ctrlIdx, ETHREMOTECFG_CMD_JOIN_VLAN, &req.hdr);
        status = Eth_RpcSendCmd(ctrlIdx, ETHREMOTECFG_CMD_JOIN_VLAN,
                                (const void*)&req, sizeof(req));
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

Std_ReturnType Eth_RpcSendDelVlan(uint8 ctrlIdx,
                                  uint32 vlanId)
{
    EthRemoteCfg_VlanLeaveReq req;
    Std_ReturnType status;

    if ((Eth_VirtMacInfo[ctrlIdx].ethFwAttached == TRUE) &&
        (Eth_VirtMacInfo[ctrlIdx].token != ETHREMOTECFG_TOKEN_NONE))
    {
        req.vlanId = (uint16)vlanId;
        req.flowIdxBase = Eth_VirtMacInfo[ctrlIdx].rxFlowStartIdx;
        req.flowIdxOffset = Eth_VirtMacInfo[ctrlIdx].rxFlowIdx;
        memcpy(&req.macAddr[0], Eth_VirtMacInfo[ctrlIdx].macAddress,
               sizeof(req.macAddr));

        Eth_RpcSetupHdrCmd(ctrlIdx, ETHREMOTECFG_CMD_LEAVE_VLAN, &req.hdr);
        status = Eth_RpcSendCmd(ctrlIdx, ETHREMOTECFG_CMD_LEAVE_VLAN,
                                (const void*)&req, sizeof(req));
    }
    else
    {
        status = E_NOT_OK;
    }

    return status;
}

Std_ReturnType Eth_RpcSendResetComplete(uint8 ctrlIdx)
{
    EthRemoteCfg_ReqHdr req;
    Std_ReturnType status = E_OK;

    if ((Eth_VirtMacInfo[ctrlIdx].ethFwAttached == TRUE) &&
        (Eth_VirtMacInfo[ctrlIdx].token != ETHREMOTECFG_TOKEN_NONE))
    {
        Eth_RpcSetupHdrCmd(ctrlIdx, ETHREMOTECFG_CMD_TEARDOWN_COMPLETION, &req);
        status = Eth_RpcSendCmd(ctrlIdx, ETHREMOTECFG_CMD_TEARDOWN_COMPLETION,
                                (const void*)&req, sizeof(req));
    }

    return status;
}

#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#endif /* (STD_ON == ETH_VIRTUALMAC_SUPPORT) */
