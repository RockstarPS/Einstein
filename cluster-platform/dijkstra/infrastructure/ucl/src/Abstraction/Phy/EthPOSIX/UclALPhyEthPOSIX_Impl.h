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
/// @ingroup UclALPhy
/// UCL Physical Layer Abstraction Implementation for Network Interface on POSIX Operating Systems (QNX, Linux).
/// APIs in this file are not to called directly by the users.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALPHY_ETHPOSIXIMPL
#define UCLALPHY_ETHPOSIXIMPL


#include <netinet/in.h>
#include "UclALPhy_Types.h"
#include "UclALPhyCbk_Types.h"
#include "UclCmnRingBuffer.h"

///
/// @brief UCL Network Node Type Definitions
///
typedef uint8 EUclALPhyEthNodeType;
#define eUclALPhyEthNodeType_Server     (EUclALPhyEthNodeType)0     ///< Server Node.
#define eUclALPhyEthNodeType_Client     (EUclALPhyEthNodeType)1     ///< Client Node.

///
/// @brief Configruation structure for UclALPhyEthPOSIX
///
/// The SUclALPhyEthPOSIXCfg structure defines the configuration
/// data for UclALPhyEthPOSIX_Impl class.
///
typedef struct
{
    EUclALPhyEthNodeType nodeType;
    char8 *interfaceIp;         ///< Server - N/W interface to listen for incoming connections
								///< Client - Destination IP
    uint16 portNo;              ///< Port No to bind to

    uint16 txRingBufferSize;    ///< Transmit Ring Buffer Size
    uint16 rxRingBufferSize;    ///< Receive Ring Buffer Size
    uint8 *pTxRingBuffer;       ///< Transmit Ring Buffer Data Pointer
    uint8 *pRxRingBuffer;       ///< Receive Ring Buffer Data Pointer
    uint16 txDmaBufferSize;     ///< Transmit Dma Buffer Size
    uint16 rxDmaBufferSize;     ///< Receive Dma Buffer Size
    uint8 *pTxDmaBuffer;        ///< Transmit Dma Buffer Data Pointer
    uint8 *pRxDmaBuffer;        ///< Receive Dma Buffer Data P
} SUclALPhyEthPOSIXCfg;

///
/// @brief Instance Structure for UclALPhyEthPOSIX
///
/// The SUclALPhyEthInst structure defines the private
/// instance data for UclALPhyEthPOSIX_Impl class.
///
typedef struct
{
    uint8 numIUclALPhyCbk;              ///< Number of connected IUclALPhyCbk instances
    uint8 *pIUclALPhyCbk;               ///< Instance ID of the connected IUclALPhyCbk instances
    const SUclALPhyEthPOSIXCfg *pCfg;   ///< Configuration for the SUclALPhyEthPOSIXCfg instance
    EUclALPhyPeerReadyStatus peerReadyState;
    sint32 sockFd;
    struct sockaddr_in servAddr;
    struct sockaddr_in cliAddr;
    socklen_t cliAddrLen;
    SUclCmnRingBuffer txRingBuffer;     ///< Transmit Ring Buffer
    SUclCmnRingBuffer rxRingBuffer;     ///< Receive Ring Buffer
    uint32 txRingBufferMutexId;         ///< Transmit Ring Buffer Protection Mutex
    uint32 rxRingBufferMutexId;         ///< Receive Ring Buffer Protection Mutex
    uint32 txTaskId;
    uint32 rxTaskId;
    uint32 txSemId;
} SUclALPhyEthPOSIXInst;

///
/// @brief Function to intialize the UclALPhyEthPOSIX_Impl class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_NOK - Init success, UCL_E_NOK - Init Failure.
///
///
Ucl_ReturnType UclALPhyEthPOSIX_Impl_IUclALPhy_Initialize ( SUclALPhyEthPOSIXInst *pInst, uint8 InstId );
Ucl_ReturnType UclALPhyEthPOSIX_Impl_IUclALPhy_Shutdown ( SUclALPhyEthPOSIXInst *pInst, uint8 InstId );
Ucl_ReturnType UclALPhyEthPOSIX_Impl_IUclALPhy_Write ( SUclALPhyEthPOSIXInst *pInst, uint8 InstId, uint8 *pData,
        uint16 Size );
Ucl_ReturnType UclALPhyEthPOSIX_Impl_IUclALPhy_Read ( SUclALPhyEthPOSIXInst *pInst, uint8 InstId, uint8 *pData,
        uint16 *pSize );

#endif //UCLALPHY_ETHPOSIXIMPL
