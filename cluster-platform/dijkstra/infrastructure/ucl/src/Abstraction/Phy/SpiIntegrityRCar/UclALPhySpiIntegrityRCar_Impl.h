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
/// UCL Physical Layer Abstraction Implementation for SPI on Integrity Operating Systems for RCar Controller.
/// APIs in this file are not to called directly by the users
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALPHY_SPIINTRCARIMPL
#define UCLALPHY_SPIINTRCARIMPL

#include "Ucl_Types.h"
#include "UclALPhyCbk_Types.h"
#include "UclCmnRingBuffer.h"
#include <INTEGRITY.h>
#include "support/virt_iodevice_interface.h"
#include "driver/spi/rcar_msiof_spi.h"
#include "driver/spi/rcar_msiof_spi_interface.h"
#include "driver/gpio/rcar_gpio_interface.h"

///
/// @brief Configuration Structure for UclALPhySpiIntegrityRCar
///
/// The SUclALPhySpiIntegrityRCarCfg structure defines the
/// configuration data for UclALPhySpiIntegrityRCar class.
///
typedef struct SUclALPhySpiIntegrityRCarCfg_t
{
    char8 *spiDev;           ///< RCar SPI Device Name String
    char8 *gpioDev;          ///< RCar GPIO Device Name String
    uint8 gpioPin;           ///< Flow Control Pin Number
    uint16 txRingBufferSize; ///< Transmit Ring Buffer Size
    uint16 rxRingBufferSize; ///< Receive Ring Buffer Size
    uint8 *pTxRingBuffer;    ///< Transmit Ring Buffer Data Pointer
    uint8 *pRxRingBuffer;    ///< Receive Ring Buffer Data Pointer
    uint16 txDmaBufferSize;  ///< Transmit Dma Buffer Size
    uint16 rxDmaBufferSize;  ///< Receive Dma Buffer Size
    uint8 *pTxDmaBuffer;     ///< Transmit Dma Buffer Data Pointer
    uint8 *pRxDmaBuffer;     ///< Receive Dma Buffer Data Pointer
} SUclALPhySpiIntegrityRCarCfg;

///
/// @brief Instance Structure for UclALPhySpiIntegrityRCar
///
/// The SUclALPhySpiIntegrityRCarInst structure defines the
/// instance data for UclALPhySpiIntegrityRCar class.
///
typedef struct SUclALPhySpiIntegrityRCarInst_t
{
    uint8 numIUclALPhyCbk;                    ///< Number of connected IUclALPhyCbk instances
    uint8 *pIUclALPhyCbk;                     ///< Instance ID of the connected IUclALPhyCbk instances
    const SUclALPhySpiIntegrityRCarCfg *pCfg; ///< Configuration for the UclALPhySpiIntegrityRCar instance
    SUclCmnRingBuffer txRingBuffer;           ///< Transmit Ring Buffer
    SUclCmnRingBuffer rxRingBuffer;           ///< Receive Ring Buffer
    uint32 txRingBufferMutexId;               ///< Transmit Ring Buffer Protection Mutex
    uint32 rxRingBufferMutexId;               ///< Receive Ring Buffer Protection Mutex
    uint32 taskId;                            ///< Phy Task Id
    uint8 exitTask;                           ///< Flag to exit task
    EUclALPhyPeerReadyStatus peerReadyState;  ///< Peer Ready State
    uint8 dataTransferPhase;                  ///< Data Transfer Phase
    Rcar_MsiofSpi_DeviceInfo *pSpiIf;         ///< RCar SPI Device Interface
    Rcar_Gpio_DeviceInfo *pGpioIf;            ///< RCar GPIO Device Interface
} SUclALPhySpiIntegrityRCarInst;

///
/// @brief Function to Initialize the UclALPhySpiIntegrityRCar class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_NOK - Successfully initialized
/// @return UCL_E_NOK - Initialization failed
///
Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_IUclALPhy_Initialize(SUclALPhySpiIntegrityRCarInst *pInst, uint8 InstId);

///
/// @brief Function to Shutdown the UclALPhySpiIntegrityRCar class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_OK - Shutdown successful
/// @return UCL_E_NOK - Shutdown failed
///
Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_IUclALPhy_Shutdown(SUclALPhySpiIntegrityRCarInst *pInst, uint8 InstId);

///
/// @brief Function to send data to the UclALPhySpiIntegrityRCar class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
/// @param pData Pointer to the data buffer
/// @param Size Size of the data buffer
///
/// @return UCL_E_OK - Write successful
/// @return UCL_E_NOK - Write failed
///
Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_IUclALPhy_Write(SUclALPhySpiIntegrityRCarInst *pInst, uint8 InstId,
                                                             uint8 *pData, uint16 size);

///
/// @brief Function to read data from the UclALPhySpiIntegrityRCar class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
/// @param pData Pointer to the data buffer
/// @param *pSize [in] Size of the data buffer, [out] Number of bytes copied
///
/// @return UCL_E_OK - Read successful
/// @return UCL_E_NOK - Read failed or no data to read
///
Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_IUclALPhy_Read(SUclALPhySpiIntegrityRCarInst *pInst, uint8 InstId,
                                                            uint8 *pData, uint16 *pSize);

#endif //UCLALPHY_SPIINTRCARIMPL
