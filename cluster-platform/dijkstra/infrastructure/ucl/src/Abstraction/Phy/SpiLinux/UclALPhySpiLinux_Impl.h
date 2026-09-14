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
/// UCL Physical Layer Abstraction Implementation for SPI on Linux Operating Systems.
/// APIs in this file are not to called directly by the users
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALPHY_SPILINUXIMPL
#define UCLALPHY_SPILINUXIMPL

#include "UclALPhy_Types.h"
#include "UclCmnRingBuffer.h"

///
/// @brief Configuration structure for UclALPhySpiLinux
///
/// The SUclALPhySpiLinuxCfg structure defines the configuration
/// data for UclALPhySpiLinux_Impl class.
///
typedef struct SUclALPhySpiLinuxCfg_t
{
    const char8 *pDevicePath; ///< SPI Device path e.g. /dev/spidev4.0
    sint32 gpioNum;           ///< GPIO Id
    uint8 spiMode;            ///< SPI Transfer Mode
    uint8 bitsperword;        ///< SPI Transfer Bits per word
    uint32 speed;             ///< SPI Transfer Speed
    uint16 txRingBufferSize;  ///< Transmit Ring Buffer Size
    uint16 rxRingBufferSize;  ///< Receive Ring Buffer Size
    uint8 *pTxRingBuffer;     ///< Transmit Ring Buffer Data Pointer
    uint8 *pRxRingBuffer;     ///< Receive Ring Buffer Data Pointer
    uint16 txDmaBufferSize;   ///< Transmit Dma Buffer Size
    uint16 rxDmaBufferSize;   ///< Receive Dma Buffer Size
    uint8 *pTxDmaBuffer;      ///< Transmit Dma Buffer Data Pointer
    uint8 *pRxDmaBuffer;      ///< Receive Dma Buffer Data Pointer
} SUclALPhySpiLinuxCfg;

///
/// @brief Instance Structure for UclALPhySpiLinux
///
/// The SUclALPhySpiLinuxInst structure defines the private
/// instance data for UclALPhySpiLinux class.
///
typedef struct SUclALPhySpiLinuxInst_t
{
    uint8 numIUclALPhyCbk;            ///< Number of connected IUclALPhyCbk instances
    uint8 *pIUclALPhyCbk;             ///< Instance ID of the connected IUclALPhyCbk instances
    const SUclALPhySpiLinuxCfg *pCfg; ///< Configuration for the UclALPhySpiLinux instance
    SUclCmnRingBuffer txRingBuffer;   ///< Transmit Ring Buffer
    SUclCmnRingBuffer rxRingBuffer;   ///< Receive Ring Buffer
    uint32 txRingBufferMutexId;       ///< Transmit Ring Buffer Protection Mutex
    uint32 rxRingBufferMutexId;       ///< Receive Ring Buffer Protection Mutex
    sint32 spiFd;                     ///< SPI device file descriptor
    sint32 gpioFd;                    ///< GPIO device file descriptor
    uint32 timerTaskId;               ///< Timer Task Identifier
} SUclALPhySpiLinuxInst;

///
/// @brief Function to Initialize the UclALPhySpiLinux class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_NOK - Successfully initialized
/// @return UCL_E_NOK - Initialization failed
///
Ucl_ReturnType UclALPhySpiLinux_Impl_IUclALPhy_Initialize(SUclALPhySpiLinuxInst *pInst, uint8 InstId);

///
/// @brief Function to Shutdown the UclALPhySpiLinux class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_OK - Shutdown successful
/// @return UCL_E_NOK - Shutdown failed
///
Ucl_ReturnType UclALPhySpiLinux_Impl_IUclALPhy_Shutdown(SUclALPhySpiLinuxInst *pInst, uint8 InstId);

///
/// @brief Function to Send data to the UclALPhySpiLinux class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
/// @param pData Pointer to the data buffer
/// @param Size Size of the data buffer
///
/// @return UCL_E_OK - Write successful
/// @return UCL_E_NOK - Write failed
///
Ucl_ReturnType UclALPhySpiLinux_Impl_IUclALPhy_Write(SUclALPhySpiLinuxInst *pInst, uint8 InstId, uint8 *pData,
                                                     uint16 Size);

///
/// @brief Function to read data from the UclALPhySpiLinux class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
/// @param pData Pointer to the data buffer
/// @param *pSize [in] Size of the data buffer, [out] Number of bytes copied
///
/// @return UCL_E_OK - Read successful
/// @return UCL_E_NOK - Read failed or no data to read
///
Ucl_ReturnType UclALPhySpiLinux_Impl_IUclALPhy_Read(SUclALPhySpiLinuxInst *pInst, uint8 InstId, uint8 *pData,
                                                    uint16 *pSize);

#endif //UCLALPHY_SPILINUXIMPL
