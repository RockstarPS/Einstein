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
#ifndef UCLALPHY_SERIALVLITEIMPL
#define UCLALPHY_SERIALVLITEIMPL

#include "UclCmnRingBuffer.h"
#include "Ucl_Types.h"

///
/// @brief Configuration Structure for UclALPhySerialVlite_Impl
/// @ingroup UclALPhy
///
/// The SUclALPhySerialVlitefg structure defines the configuration
/// data for UclALPhySerialVlite class.
///
typedef struct SUclALPhySerialVlitefg_t
{
    uint8 channelId;         ///< UART Channel Id
    uint8 periodicityMs;     ///< UART transfer task periodicity
    uint8 HwFlowCtrlOn;      ///< UART hardware flow control
    uint16 txRingBufferSize; ///< UART of the transmit ring buffer
    uint16 rxRingBufferSize; ///< Size of the receive ring buffer
    uint8 *pTxRingBuffer;    ///< Pointer to transmit ring buffer data
    uint8 *pRxRingBuffer;    ///< Pointer to receive ring buffer data
    uint16 txDmaBufferSize;  ///< Size of the transmit DMA buffer
    uint16 rxDmaBufferSize;  ///< Size of the receive DMA buffer
    uint8 *pTxDmaBuffer;     ///< Pointer to transmit dma buffer data
    uint8 *pRxDmaBuffer;     ///< Pointer to receive dma buffer data
} SUclALPhySerialVliteCfg;

///
/// @brief Configuration Structure for UclALPhySerialVlite_Impl
/// @ingroup UclALPhy
///
/// The SUclALPhySerialVliteInst structure defines the instance
/// data for UclALPhySerialVlite class.
///
typedef struct SUclALPhySerialVliteInst_t
{
    uint8 numIUclALPhy;                  ///< Number of connected IUclALPhy instances
    uint8 numIUclALPhyCbk;               ///< Number of connected IUclALPhyCbk instances
    uint8 *pIUclALPhy;                   ///< Instance ID of the connected IUclALPhy instances
    uint8 *pIUclALPhyCbk;                ///< Instance ID of the connected IUclALPhyCbk instances
    const SUclALPhySerialVliteCfg *pCfg; ///< Configuration for the UclALPhySerialVlite instance
    SUclCmnRingBuffer txRingBuffer;      ///< Transmit Ring Buffer
    SUclCmnRingBuffer rxRingBuffer;      ///< Receive Ring Buffer
    uint8 isPeerReady;                   ///< Peer ready flag
    uint32 timerTaskId;                  ///< UART TimerTask Id
} SUclALPhySerialVliteInst;

///
/// @brief Function to Initialize the UclALPhySerialVlite class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_NOK - Successfully initialized
/// @return UCL_E_NOK - Initialization failed
///
Ucl_ReturnType UclALPhySerialVlite_Impl_IUclALPhy_Initialize(SUclALPhySerialVliteInst *pInst, uint8 InstId);

///
/// @brief Function to Shutdown the UclALPhySerialVlite class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_OK - Shutdown successful
/// @return UCL_E_NOK - Shutdown failed
///
Ucl_ReturnType UclALPhySerialVlite_Impl_IUclALPhy_Shutdown(SUclALPhySerialVliteInst *pInst, uint8 InstId);

///
/// @brief Function to send data to the UclALPhySerialVlite class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
/// @param pData Pointer to the data buffer
/// @param Size Size of the data buffer
///
/// @return UCL_E_OK - Write successful
/// @return UCL_E_NOK - Write failed
///
Ucl_ReturnType UclALPhySerialVlite_Impl_IUclALPhy_Write(SUclALPhySerialVliteInst *pInst, uint8 InstId, uint8 *pData, uint16 Size);

///
/// @brief Function to read data from the UclALPhySerialVlite class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
/// @param pData Pointer to the data buffer
/// @param *pSize [in] Size of the data buffer, [out] Number of bytes copied
///
/// @return UCL_E_OK - Read successful
/// @return UCL_E_NOK - Read failed or no data to read
///
Ucl_ReturnType UclALPhySerialVlite_Impl_IUclALPhy_Read(SUclALPhySerialVliteInst *pInst, uint8 InstId, uint8 *pData, uint16 *pSize);

///
/// @brief Function to notify UclALPhySerialVlite class about completion of data transmit
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_OK - Notification successful
/// @return UCL_E_NOK - Notification failed
///
Ucl_ReturnType UclALPhySerialVlite_Impl_IUclALHwCbk_TransmitComplete(SUclALPhySerialVliteInst *pInst, uint8 InstId);

///
/// @brief Function to notify UclALPhySerialVlite class about completion of data reception
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_OK - Notification successful
/// @return UCL_E_NOK - Notification failed
///
Ucl_ReturnType UclALPhySerialVlite_Impl_IUclALHwCbk_ReceiveComplete(SUclALPhySerialVliteInst *pInst, uint8 InstId);

///
/// @brief Function to notify UclALPhySerialVlite class about change in the GPIO state
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
/// @param GpioId GPIO Identifier
///
/// @return UCL_E_OK - Notification successful
/// @return UCL_E_NOK - Notification failed
///
Ucl_ReturnType UclALPhySerialVlite_Impl_IUclALHwCbk_GpioChanged(SUclALPhySerialVliteInst *pInst, uint8 InstId, uint16 GpioId);

#endif //UCLALPHY_SERIALVLITEIMPL
