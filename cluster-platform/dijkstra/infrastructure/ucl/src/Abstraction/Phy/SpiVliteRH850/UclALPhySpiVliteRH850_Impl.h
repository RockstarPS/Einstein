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
/// UCL Physical Layer Abstraction Implementation for SPI on VLite Operating Systems for RH850 Controller.
/// APIs in this file are not to called directly by the users.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALPHY_SPIVLITERH850IMPL
#define UCLALPHY_SPIVLITERH850IMPL

#include "UclCmnRingBuffer.h"
#include "Ucl_Types.h"

///
/// @brief Configuration Structure for UclALPhySpiVliteRH850
///
/// The SUclALPhySpiVliteRH850Cfg structure defines the configuration
/// data for UclALPhySpiVliteRH850Cfg class.
///
typedef struct SUclALPhySpiVliteRH850Cfg_t
{
    uint8 channelId;         ///< SPI Channel Id
    uint16 phyLinkUpDelayMs; ///< SPI Link up delay timeout
    uint16 txRingBufferSize; ///< Size of the transmit ring buffer
    uint16 rxRingBufferSize; ///< Size of the receive ring buffer
    uint8 *pTxRingBuffer;    ///< Pointer to transmit ring buffer data
    uint8 *pRxRingBuffer;    ///< Pointer to receive ring buffer data
    uint16 txDmaBufferSize;  ///< Size of the transmit DMA buffer
    uint16 rxDmaBufferSize;  ///< Size of the receive DMA buffer
    uint8 *pTxDmaBuffer;     ///< Pointer to transmit dma buffer data
    uint8 *pRxDmaBuffer;     ///< Pointer to receive dma buffer data
} SUclALPhySpiVliteRH850Cfg;

///
/// @brief Instance Structure for UclALPhySpiVliteRH850
///
/// The SUclALPhySpiVliteRH850Inst structure defines the instance
/// data for UclALPhySpiVliteRH850Cfg class.
///
typedef struct SUclALPhySpiVliteRH850Inst_t
{
    uint8 numIUclALPhyCbk;                 ///< Number of connected IUclALPhyCbk instances
    uint8 *pIUclALPhyCbk;                  ///< Instance ID of the connected IUclALPhyCbk instances
    const SUclALPhySpiVliteRH850Cfg *pCfg; ///< Configuration for the UclALPhySpiVliteRH850 instance
    SUclCmnRingBuffer txRingBuffer;        ///< Transmit Ring Buffer
    SUclCmnRingBuffer rxRingBuffer;        ///< Receive Ring Buffer
    uint8 isPeerReady;                     ///< Peer ready flag
    uint8 dataTransferPhase;               ///< SPI Data Transfer Phase
    uint16 spiXferlen;                     ///< SPI Data Transfer Length
    uint32 timerTaskId;                    ///< SPI TimerTask Id
    uint32 timerStartupDelayTaskId;        ///< SPI Initialization Delay TimerTask Id
} SUclALPhySpiVliteRH850Inst;

///
/// @brief Function to Initialize the UclALPhySpiVliteRH850 class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_NOK - Successfully initialized
/// @return UCL_E_NOK - Initialization failed
///
Ucl_ReturnType UclALPhySpiVliteRH850_Impl_IUclALPhy_Initialize(SUclALPhySpiVliteRH850Inst *pInst, uint8 InstId);

///
/// @brief Function to Shutdown the UclALPhySpiVliteRH850 class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_OK - Shutdown successful
/// @return UCL_E_NOK - Shutdown failed
///
Ucl_ReturnType UclALPhySpiVliteRH850_Impl_IUclALPhy_Shutdown(SUclALPhySpiVliteRH850Inst *pInst, uint8 InstId);

///
/// @brief Function to send data to the UclALPhySpiVliteRH850 class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
/// @param pData Pointer to the data buffer
/// @param Size Size of the data buffer
///
/// @return UCL_E_OK - Write successful
/// @return UCL_E_NOK - Write failed
///
Ucl_ReturnType UclALPhySpiVliteRH850_Impl_IUclALPhy_Write(SUclALPhySpiVliteRH850Inst *pInst, uint8 InstId, uint8 *pData, uint16 size);

///
/// @brief Function to read data from the UclALPhySpiVliteRH850 class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
/// @param pData Pointer to the data buffer
/// @param *pSize [in] Size of the data buffer, [out] Number of bytes copied
///
/// @return UCL_E_OK - Read successful
/// @return UCL_E_NOK - Read failed or no data to read
///
Ucl_ReturnType UclALPhySpiVliteRH850_Impl_IUclALPhy_Read(SUclALPhySpiVliteRH850Inst *pInst, uint8 InstId, uint8 *pData, uint16 *pSize);

///
/// @brief Function to notify UclALPhySpiVliteRH850 class about completion of data transmit
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_OK - Notification successful
/// @return UCL_E_NOK - Notification failed
///
Ucl_ReturnType UclALPhySpiVliteRH850_Impl_IUclALHwCbk_TransmitComplete(SUclALPhySpiVliteRH850Inst *pInst, uint8 InstId);

///
/// @brief Function to notify UclALPhySpiVliteRH850 class about completion of data reception
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_OK - Notification successful
/// @return UCL_E_NOK - Notification failed
///
Ucl_ReturnType UclALPhySpiVliteRH850_Impl_IUclALHwCbk_ReceiveComplete(SUclALPhySpiVliteRH850Inst *pInst, uint8 InstId);

///
/// @brief Function to notify UclALPhySpiVliteRH850 class about change in the GPIO state
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
/// @param GpioId GPIO Identifier
///
/// @return UCL_E_OK - Notification successful
/// @return UCL_E_NOK - Notification failed
///
Ucl_ReturnType UclALPhySpiVliteRH850_Impl_IUclALHwCbk_GpioChanged(SUclALPhySpiVliteRH850Inst *pInst, uint8 InstId, uint16 GpioId);

#endif //UCLALPHY_SPIINTRCARIMPL
