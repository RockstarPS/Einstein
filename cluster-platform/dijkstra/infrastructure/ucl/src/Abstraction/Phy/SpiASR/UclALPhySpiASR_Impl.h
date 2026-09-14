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
/// UCL Physical Layer Abstraction Implementation for SPI on AUTOSAR Operating Systems.
/// APIs in this file are not to called directly by the users.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALPHY_SPIASRIMPL
#define UCLALPHY_SPIASRIMPL

#include "Ucl_Types.h"
#include "UclALPhyCbk_Types.h"
#include "UclCmnRingBuffer.h"

//Constant configruation for UclALPhySerialASR
typedef struct SUclALPhySpiASRCfg_t
{
    uint8 channelId;
    sint32 gpio;
	uint8 spiMode;
    uint16 txRingBufferSize;
    uint16 rxRingBufferSize;
    uint8 *pTxRingBuffer;
    uint8 *pRxRingBuffer;
    uint16 txDmaBufferSize;
    uint16 rxDmaBufferSize;
    uint8 *pTxDmaBuffer;
    uint8 *pRxDmaBuffer;
} SUclALPhySpiASRCfg;

//Instance Data for UclALPhySpiASR
typedef struct SUclALPhySpiASRInst_t
{
    uint8 numIUclALPhyCbk;
    uint8 *pIUclALPhyCbk;
    const SUclALPhySpiASRCfg *pCfg;
    uint8 dataTransferPhase;
    EUclALPhyPeerReadyStatus peerReadyState;
    SUclCmnRingBuffer txRingBuffer;
    SUclCmnRingBuffer rxRingBuffer;
} SUclALPhySpiASRInst;

//Implementation for interface IUclALPhy
Ucl_ReturnType UclALPhySpiASR_Impl_IUclALPhy_Initialize ( SUclALPhySpiASRInst *pInst, uint8 InstId );
Ucl_ReturnType UclALPhySpiASR_Impl_IUclALPhy_Shutdown ( SUclALPhySpiASRInst *pInst, uint8 InstId );
Ucl_ReturnType UclALPhySpiASR_Impl_IUclALPhy_Write ( SUclALPhySpiASRInst *pInst, uint8 InstId, uint8 *pData, uint16 size );
Ucl_ReturnType UclALPhySpiASR_Impl_IUclALPhy_Read ( SUclALPhySpiASRInst *pInst, uint8 InstId, uint8 *pData, uint16 *pSize );

//Implementation for interface IUclALDmaCbk
void UclALPhySpiASR_Impl_IUclALHwCbk_TransmitComplete ( SUclALPhySpiASRInst *pInst, uint8 InstId );
void UclALPhySpiASR_Impl_IUclALHwCbk_ReceiveComplete ( SUclALPhySpiASRInst *pInst, uint8 InstId );
void UclALPhySpiASR_Impl_IUclALHwCbk_GpioChanged ( SUclALPhySpiASRInst *pInst, uint8 InstId, uint16 GpioId );

#endif //UCLALPHY_SPIASRIMPL
