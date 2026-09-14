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
/// UCL Physical Layer Abstraction Implementation for UART on AUTOSAR Operating Systems.
/// APIs in this file are not to called directly by the users
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALPHY_SERIALASRIMPL
#define UCLALPHY_SERIALASRIMPL

#include "Ucl_Types.h"
#include "UclALPhyCbk_Types.h"
#include "UclCmnRingBuffer.h"

///
/// @brief Configruation structure for UclALPhySerialASR
///
/// The SUclALPhySerialASRCfg structure defines the configuration
/// data for UclALPhySerialASR_Impl class.
///
typedef struct SUclALPhySerialASRCfg_t
{
    uint8 channelId;
    uint8 enableDMA;
    uint8 periodicityMs;
    uint16 txRingBufferSize;
    uint16 rxRingBufferSize;
    uint8 *pTxRingBuffer;
    uint8 *pRxRingBuffer;
    uint16 txDmaBufferSize;
    uint16 rxDmaBufferSize;
    uint8 *pTxDmaBuffer;
    uint8 *pRxDmaBuffer;
} SUclALPhySerialASRCfg;

///
/// @brief Instance Structure for UclALPhySerialASR
///
/// The SUclALPhySerialASRInst structure defines the private
/// instance data for UclALPhySerialASR_Impl class.
///
typedef struct SUclALPhySerialASRInst_t
{
    uint8 numIUclALPhyCbk;
    uint8 *pIUclALPhyCbk;

    const SUclALPhySerialASRCfg *pCfg;
    EUclALPhyPeerReadyStatus peerReadyState;

    uint32 timerTaskId;
    SUclCmnRingBuffer txRingBuffer;
    SUclCmnRingBuffer rxRingBuffer;
} SUclALPhySerialASRInst;

/**
 * @brief Function to intialize the UclALPhySerialASR_Impl class.
 *
 * @param pInst  Instance Pointer.
 * @param InstId Instance ID of the caller
 *
 * @return UCL_E_NOK - Init success, UCL_E_NOK - Init Failure.
 *
 */
Ucl_ReturnType UclALPhySerialASR_Impl_IUclALPhy_Initialize ( SUclALPhySerialASRInst *pInst, uint8 InstId );
Ucl_ReturnType UclALPhySerialASR_Impl_IUclALPhy_Shutdown ( SUclALPhySerialASRInst *pInst, uint8 InstId );
Ucl_ReturnType UclALPhySerialASR_Impl_IUclALPhy_Write ( SUclALPhySerialASRInst *pInst, uint8 InstId, uint8 *pData,
        uint16 Size );
Ucl_ReturnType UclALPhySerialASR_Impl_IUclALPhy_Read ( SUclALPhySerialASRInst *pInst, uint8 InstId, uint8 *pData,
        uint16 *pSize );

//Implementation for interface IUclALDmaCbk
void UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete ( SUclALPhySerialASRInst *pInst, uint8 InstId );
void UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete ( SUclALPhySerialASRInst *pInst, uint8 InstId );
void UclALPhySerialASR_Impl_IUclALHwCbk_GpioChanged ( SUclALPhySerialASRInst *pInst, uint8 InstId, uint16 GpioId );

#endif //UCLALPHY_SERIALASRIMPL
