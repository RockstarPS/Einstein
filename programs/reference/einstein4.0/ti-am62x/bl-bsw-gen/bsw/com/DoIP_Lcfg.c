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
*    @file DoIP_Lcfg.c
*    @ingroup DoIPConfiguration
*    @brief This is DoIP Link time configuration source file. It contains definitions of Link time configuration
*    parameters for the DoIP module.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "DoIP.h"
#include "DoIP_Lcfg.h"
#include "DoIP_Externals.h"
/********************************************************************************************************************
* #! GLOBAL VARIABLES                                                                                               *
********************************************************************************************************************/
DoIP_ConCtrlStatusType DoIP_ConCtrlStatus[DOIP_NUM_OF_CONNECTION];
DoIP_TxTcpQueueElementType DoIP_TxTcpQueue[DOIP_TCP_TX_QUEUE_SIZE];
DoIP_TcpConCtrlStatusType DoIP_TcpConCtrlStatus[DOIP_NUM_OF_TCP_CONNECTION];
DoIP_UdpConCtrlStatusType DoIP_UdpConCtrlStatus[DOIP_NUM_OF_UDP_CONNECTION];
DoIP_UdpTxCtrlStatusType DoIP_UdpTxCtrlStatus[DOIP_UDP_NUM_OF_TX_CTRL];
DoIP_ChannelCtrlStatusType DoIP_ChannelCtrlStatus[DOIP_NUM_OF_CHANNEL];
DoIP_TesterCtrlStatusType DoIP_TesterCtrlStatus[DOIP_NUM_OF_TESTER];
DoIP_IpAddrAssignmentCtrlType DoIP_IpAddrAssignmentCtrl[DOIP_NUM_OF_IP_ADDRESS_ASSIGNEMENT];
DoIP_RoutingActivationCtrlStatusType DoIP_RoutingActivationCtrlStatus;
DoIP_OemPayloadCtrlStatusType DoIP_OemPayloadCtrlStatus;
uint8 DoIP_OemPayloadUdpBuffer[DOIP_OEM_PAYLOAD_UDP_BUFFER_SIZE];
#if (DOIP_OEM_PAYLOAD_TCP_BUFFER_SIZE > 0u)
uint8 DoIP_OemPayloadTcpBuffer[DOIP_OEM_PAYLOAD_TCP_BUFFER_SIZE];
#endif
uint8 DoIP_RxHeaderBuffer[DOIP_RX_HEADER_BUFFER_SIZE];
uint8 DoIP_TxHeaderBuffer[DOIP_TX_HEADER_BUFFER_SIZE];
uint8 DoIP_TxIfBuffer[DOIP_TX_IF_BUFFER_SIZE];
uint8 DoIP_DiagNAckBuffer[DOIP_DIAG_NACK_BUFFER_SIZE];
boolean DoIP_ActivationLineInactiveReq;
boolean DoIP_PduSizeRoutingStatus;
boolean DoIP_GroupIdInSyncStatus;
DoIP_ActivationLineType DoIP_ActivationLineState;
DoIP_LocalIpAddrIdxType DoIP_LocalIpAddrAssignedCount;
/********************************************************************************************************************
* #! DoIP const config  data                                                                                       *
********************************************************************************************************************/
const DoIP_ConfigType DoIP_Config =
{
    .dummy = 0u
};

/* 4 doip connection 2 tcp server con , 1 udp server con, 1 udp vehicle announce */
const DoIP_ConnectionConfigType DoIP_ConnectionConfig[DOIP_NUM_OF_CONNECTION]=
{
    {   /* doip tcp server config */
        .LocalIpAddrIdx = 0,
        .RxCancelPduId = SOAD_PDU_TcpDoIPServerSocketRouteTp,
        .TxPduId = SOAD_PDU_TcpDoIPServerPduRouteTp 
    }, 
    {   /* doip udp server config */
        .LocalIpAddrIdx = 0, 
        .RxCancelPduId = SOAD_PDU_UdpDoIPServerSocketRouteTp,
        .TxPduId = SOAD_PDU_UdpDoIPServerPduRouteTp 
    }, 
    {   /* doip udp server config */
        .LocalIpAddrIdx = 0,
        .RxCancelPduId = SOAD_NUM_OF_SOCKET_ROUTE,
        .TxPduId = SOAD_PDU_UdpDoIPServerPduRouteIf 
    }, 

};

/*! @brief Configured EID (Entity ID of) for vehicle identification/vehicle announcement. Only necessary if 
    DoIPUseMacAddressForIdentification is set to FALSE. */
const uint8 DoIP_CfgEid[DOIP_EID_LENGTH]=
{
    0x00u,
    0x00u,
    0x00u,
    0x00u,
    0x00u,
    0x01u 
};
/*! @brief Configured GID (Group ID of) for vehicle identification/vehicle announcement. */
const uint8 DoIP_CfgGid[DOIP_GID_LENGTH]=
{
    0x00u,
    0x00u,
    0x00u,
    0x00u,
    0x00u,
    0x01u 
};

const DoIP_TesterConfigType DoIP_TesterConfig[DOIP_NUM_OF_TESTER]=
{
    {   /* Tester_E80 */
        .IsRoutingActivationRequired = FALSE,
        .TesterAddr = 0x0E80U,
        .NumOfDiagAckNackRespBytes= 0u, 
        .RoutingActivationIdx = 0u,
        .DiagNackBufferStartIdx = 0u,
        .DiagNackBufferEndIdx = 0u,
        .TesterToRoutingActivationMapStartIdx = 0u,
        .TesterToRoutingActivationMapEndIdx = 0u
    } 
};

const DoIP_RoutingActivationConfigType DoIP_RoutingActivationConfig[DOIP_NUM_OF_ROUTING_ACTIVATION]=
{
    {   /* DoIPRoutingActivation_E80 */
        .RoutingActivationNumber = 0,
        .AuthResLength = 0,
        .AuthReqLength = 0,
        .ConfReqLength = 0,
        .ConfResLength = 0,
        .ChannelStartIdx = 0, /* DoIPChannel_E80_14B2_Phy */
        .ChannelEndIdx = 1, /* DoIPChannel_E80_E400_func */
        .pAuthCallbackFn = NULL_PTR,
        .pConfCallbackFn =  NULL_PTR
    } 
};

const DoIP_TcpConConfigType DoIP_TcpConConfig[DOIP_NUM_OF_TCP_CONNECTION]=
{
    {   /* DoIPTcpServerConnection */
        .RxHeaderBufferStartIdx = 1U,
        .TxHeaderBufferStartIdx = 0U,
        .TcpTxQueueElementStartIdx = 0U,
        .TcpTxQueueElementEndIdx= 9U,
        .TcpTxQueueElementSize = 10u
    }
};

const DoIP_ChannelConfigType DoIP_ChannelConfig[DOIP_NUM_OF_CHANNEL]=
{
    { /*  DoIPChannel_E80_14B2_Phy */
        .IsDefaultChannel = FALSE,
        .ApiType = DOIP_API_TYPE_TP,
        .TesterIdx =  0u,
        .EcuAddr= 0x14B2u,
        .TpMaxLength = 10u,
        .RxPduId = 0u, /* pdu id to notify upper layer dcm Rx indication*/
        .TxConfId = 0u, /* pdu ud to notify upper layer dcm Tx indication */
        .TxIfBufferStartIdx = 0,
        .TxIfBufferSize = 0 
    },
    { /*  DoIPChannel_E80_E400_func */
        .IsDefaultChannel = FALSE,
        .ApiType = DOIP_API_TYPE_TP,
        .TesterIdx =  0u,
        .EcuAddr= 0x14B2u,
        .TpMaxLength = 10u,
        .RxPduId = 1u,
        .TxConfId = 0u,
        .TxIfBufferStartIdx = 0,
        .TxIfBufferSize = 0 
    }
};

const DoIP_LocalAddrConfigType DoIP_LocalAddrConfig[DOIP_NUM_OF_LOCAL_ADDR]=
{
    { 
        .IsUpdAliveTimeoutEnabled = TRUE ,
        .IpAddrAssignmentStartIdx = 0u ,
        .IpAddrAssignmentEndIdx = 0u,
        .ConMapStartIdx = 0,
        .ConMapEndIdx = 1
    }
};

// local address assignment config mapping doip 
const DoIP_IpAddrAssignmentConfigType DoIP_IpAddrAssignmentConfig[DOIP_NUM_OF_IP_ADDRESS_ASSIGNEMENT]=
{
    {
        .IsIpAssignementEnabled = FALSE,
        .IpAddrAssignmentType = DOIP_IPADDR_ASSIGN_TYPE_STATIC
    }
};

const DoIP_RxPduConfigType DoIP_RxPduConfig[DOIP_NUM_OF_RX_PDU]=
{
    { 
        .ChannelIdx = 0 
    }
};

const DoIP_DefaultAddrConfigType DoIP_DefaultAddrConfig=
{
    .TesterIdx = 0
};

const DoIP_RoutingActivationIdxType DoIP_TesterToRoutingActivationIdxMap[DoIP_NUM_OF_TESTER_TO_ROUTING_ACTIVATION]=
{
    0u /* DoIPRoutingActivation_E80 idx*/
};

const DoIP_ConIdxType DoIP_LocalAddrToConMap[DOIP_LOCAL_ADDR_TO_CON_MAP_SIZE]=
{
    0u
};

const DoIP_UserGetFurtherActionByteCallbackFnType DoIP_UserGetFurtherActionByteCallbackFn = DoIPApp_UserGetFurtherActionByte;
const DoIP_UserGetPayloadCallbackFnType DoIP_UserGetPayloadCallbackFn = DoIPApp_UserGetPayloadCallbackFn;
const DoIP_UserGetGidCallbackFnType DoIP_UserGetGidCallbackFn = DoIPApp_UserGetGidCallback ;
const DoIP_UserGetVinCallbackFnType DoIP_UserGetVinCallbackFn = DoIPApp_UserGetVinCallback ;
const DoIP_UserTriggerGidSyncCallbackFnType DoIP_UserTriggerGidSyncCallbackFn = DoIPApp_UserTriggerGidSyncCallback ;
const DoIP_UserGetPowerModeCallbackFnType DoIP_UserGetPowerModeCallbackFn= DoIpApp_UserGetPowerModeCallback;
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


