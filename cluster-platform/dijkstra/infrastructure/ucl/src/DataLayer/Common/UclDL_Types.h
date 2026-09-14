///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///
///---------------------------------------------------------------------------------------------------------------------
/// @file
/// @ingroup UclDL
/// UCL Data Layer Type Definitions
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLDLTYPES_H
#define UCLDLTYPES_H

#include "Ucl_Types.h"

#ifdef __cplusplus
extern "C" {
#endif


///< UCLDL Message Security Levels
#define UCLDL_MSG_SEC_LEVEL_0 (0U)    ///< Level 0 - Unsecure Messages
#define UCLDL_MSG_SEC_LEVEL_1 (1U)    ///< Level 1 - Authenticated Messages
#define UCLDL_MSG_SEC_LEVEL_2 (2U)    ///< Level 2 - Authenticated and Encrypted Messages
#define UCLDL_MSG_SEC_LEVEL_RSVD (3U) ///< Level 3 - Reserved Type
///< UCLDL Message Security Helper Macro to set the security level to the message header
#define UCLDL_MSG_SEC_LEVEL_SET(Hdr, lvl) ((Hdr) |= ((lvl) << (7U)))
///< UCLDL Message Security Helper Macro to get the security level to the message header
#define UCLDL_MSG_SEC_LEVEL_GET(Hdr) (((Hdr) & 0x0180U) >> 7U)

///< UCLDL Message Priority Levels
#define UCLDL_MSG_PRI_LEVEL_0 (0U) ///< Level 0 - Low Priority Messages
#define UCLDL_MSG_PRI_LEVEL_1 (1U) ///< Level 1 - Medium Priority Messages
#define UCLDL_MSG_PRI_LEVEL_2 (2U) ///< Level 2 - High Priority Messages
#define UCLDL_MSG_PRI_LEVEL_3 (3U) ///< Level 3 - Critical Priority Messages
///< UCLDL Message Priority Helper Macro to set the priority level to the message header
#define UCLDL_MSG_PRI_LEVEL_SET(Hdr, lvl) ((Hdr) |= ((lvl) << (5U)))
///< UCLDL Message Priority Helper Macro to get the priority level to the message header
#define UCLDL_MSG_PRI_LEVEL_GET(Hdr) (((Hdr) & 0x0050U) >> 5U)
///< UCLDL Message Helper Macro to set the destination node id to the message header
#define UCLDL_MSG_SET_DESTNODE_ID(Hdr, id) ((Hdr) |= (((uint16)(id)) << (12U)))
///< UCLDL Message Helper Macro to get the destination node id to the message header
#define UCLDL_MSG_GET_DESTNODE_ID(Hdr) ((((Hdr) & 0x7000U) >> 12U))
///< UCLDL Message Helper Macro to set the Source node id to the message header
#define UCLDL_MSG_SET_SRCNODE_ID(Hdr, id) ((Hdr) |= (((uint16)(id)) << (9U)))
///< UCLDL Message Helper Macro to get the Source node id to the message header
#define UCLDL_MSG_GET_SRCNODE_ID(Hdr) (((Hdr) & 0x0E00U) >> 9U)

///
/// @brief Ucl Data Layer Message Structure
///
/// Ucl Message Header \n
/// Bit[15] -Reserved \n
/// Bit[14:12] - Destination Node ID \n
/// Bit[11:9] - Src Node ID  \n
/// Bit[8:7] - Security Level \n
/// Bit[6:5] - Priority Level \n
/// Bit[4:2] - Message Sub Type \n
/// Bit[0:1]  - Message Type: Normal(00) / P2P(01) / N2N(10) / RSVD(11)
///
typedef struct SUclDLMsg_t
{
    uint16 MsgHdr;    ///< Message Header
    uint16 MsgId;    ///< Message Identifier
    uint8 *pPayload; ///< Pointer to the payload
    uint16 Size;     ///< Size of the payload
} SUclDLMsg;

///
/// @brief Statistics for the Ucl Data Layer
///
/// The SUclDLStats structure defines the variables to track the
/// statistics for Ucl Data Layer Implementations.
///
typedef struct SUclDLStats_t
{
    uint32 txMsgs;        ///< Total transmitted messages
    uint32 rxMsgs;        ///< Total received messages
    uint32 txBytes;       ///< Total transmitted bytes
    uint32 rxBytes;       ///< Total received bytes
    uint32 txHbMsgs;      ///< No of transmitted heart beat messages
    uint32 txAckMsgs;     ///< No of transmitted ack messages
    uint32 txSendFail;    ///< No of failed transmissions
    uint32 txAckTmo;      ///< No of transmit ack timeouts
    uint32 rxHbMsgs;      ///< No of received heart beat messages
    uint32 rxAckMsgs;     ///< No of received ack messages
    uint32 rxChksumErr;   ///< No of received messages with checksum error
    uint32 rxCmacErr;     ///< No of received messages with cmac error
    uint32 linkDropCntr;  ///< No of times the link has been dropped
    uint32 avgAckLatency; ///< Average latency to receive the ACK
    uint32 txBps;         ///< Transmit Bits per second
    uint32 rxBps;         ///< Receive Bits per second
    uint64 linkUpTime;    ///< Last Link up time in milliseconds
} SUclDLStats;

#ifdef __cplusplus
}
#endif
#endif //UCLDLTYPES_H
