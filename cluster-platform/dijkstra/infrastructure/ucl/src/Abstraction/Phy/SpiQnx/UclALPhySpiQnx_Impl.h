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
/// @file UclALPhySpiQnx_Impl.h
/// @ingroup UclALPhy
///
/// @brief UCL Physical Layer Abstraction Implementation for SPI on QNX Operating System
///
/// APIs in this file are not to called directly by the users
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALPHY_SPIQNXIMPL
#define UCLALPHY_SPIQNXIMPL

#include "UclCmnRingBuffer.h"
#include "Ucl_Types.h"

///
/// @brief Configuration Structure for UclALPhySpiQnx_Impl
/// @ingroup UclALPhy
///
/// The SUclALPhySpiQnxCfg structure defines the configuration
/// data for UclALPhySpiQnx class.
///
typedef struct
{
    char8 *pDevicePath;        ///< SPI device path
    char8 *pGpioDevicePath;    ///< GPIO device path
    sint32 gpioNum;            ///< GPIO Id
    uint8 spiMode;             ///< SPI Transfer Mode 0: CPOL O CPHA 0, 1:CPOL 0 CPHA 1, 2:CPOL 1 CPHA 0, 3:CPOL 1 CPHA 1
    uint8 bitsPerWord;         ///< SPI Transfer Bits per word
    uint8 bitFormat;           ///< LSB -0 MSB -1
    uint8 slaveSelectPolarity; ///< Chip polarity 0 -Low or 1-High
    uint8 slaveSelectDfltLevel;	///< Chip select stat-hold logic level
	uint32 speedHz;            ///< SPI transfer speed in Hz
    uint8 periodicityMs;       ///< SPI transfer task periodicity
    uint16 txRingBufferSize;   ///< Size of the transmit ring buffer
    uint16 rxRingBufferSize;   ///< Size of the receive ring buffer
    uint8 *pTxRingBuffer;      ///< Pointer to transmit ring buffer data
    uint8 *pRxRingBuffer;      ///< Pointer to receive ring buffer data
    uint16 txDmaBufferSize;    ///< Size of the transmit DMA buffer
    uint16 rxDmaBufferSize;    ///< Size of the receive DMA buffer
    uint8 *pTxDmaBuffer;       ///< Pointer to transmit dma buffer data
    uint8 *pRxDmaBuffer;       ///< Pointer to receive dma buffer data
} SUclALPhySpiQnxCfg;

///
/// @brief Configuration Structure for UclALPhySpiQnx_Impl
/// @ingroup UclALPhy
///
/// The SUclALPhySpiQnxInst structure defines the instance
/// data for UclALPhySpiQnx class.
///
typedef struct
{
    uint8 numIUclALPhyCbk;          ///< Number of connected IUclALPhyCbk instances
    uint8 *pIUclALPhyCbk;           ///< Instance ID of the connected IUclALPhyCbk instances
    const SUclALPhySpiQnxCfg *pCfg; ///< Configuration for the UclALPhySpiQnx instance
    SUclCmnRingBuffer txRingBuffer; ///< Transmit Ring Buffer
    SUclCmnRingBuffer rxRingBuffer; ///< Receive Ring Buffer
    uint32 txRingBufferMutexId;     ///< Transmit Ring Buffer Protection Mutex
    uint32 rxRingBufferMutexId;     ///< Receive Ring Buffer Protection Mutex
	uint32 spiChMutexId;            ///< To protect thread arbitration between SPI calls.
    sint32 spiFd;                   ///< SPI device file descriptor
    sint32 gpioFd;                  ///< GPIO device file descriptor
    uint32 timerTaskId;             ///< SPI TimerTask Id
    uint64 lastXchgTime;           ///< Last SPI exchange time
} SUclALPhySpiQnxInst;

///
/// @brief Function to Initialize the UclALPhySpiQnx class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_NOK - Successfully initialized
/// @return UCL_E_NOK - Initialization failed
///
Ucl_ReturnType UclALPhySpiQnx_Impl_IUclALPhy_Initialize ( SUclALPhySpiQnxInst *pInst, uint8 InstId );

///
/// @brief Function to Shutdown the UclALPhySpiQnx class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_OK - Shutdown successful
/// @return UCL_E_NOK - Shutdown failed
///
Ucl_ReturnType UclALPhySpiQnx_Impl_IUclALPhy_Shutdown ( SUclALPhySpiQnxInst *pInst, uint8 InstId );

///
/// @brief Function to send data to the UclALPhySpiQnx class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
/// @param pData Pointer to the data buffer
/// @param Size Size of the data buffer
///
/// @return UCL_E_OK - Write successful
/// @return UCL_E_NOK - Write failed
///
Ucl_ReturnType UclALPhySpiQnx_Impl_IUclALPhy_Write ( SUclALPhySpiQnxInst *pInst, uint8 InstId, uint8 *pData, uint16 Size );

///
/// @brief Function to read data from the UclALPhySpiQnx class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
/// @param pData Pointer to the data buffer
/// @param *pSize [in] Size of the data buffer, [out] Number of bytes copied
///
/// @return UCL_E_OK - Read successful
/// @return UCL_E_NOK - Read failed or no data to read
///
Ucl_ReturnType UclALPhySpiQnx_Impl_IUclALPhy_Read ( SUclALPhySpiQnxInst *pInst, uint8 InstId, uint8 *pData, uint16 *pSize );

#endif //UCLALPHY_SPIQNXIMPL
