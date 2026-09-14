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
/// UCL Physical Layer Abstraction Implementation for Serial Port on Windows Operating Systems.
/// APIs in this file are not to called directly by the users.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALPHY_SERIALWINDOWSIMPL
#define UCLALPHY_SERIALWINDOWSIMPL

#include "UclALPhy_Types.h"
#include "UclCmnRingBuffer.h"
#include "windows.h"

///
/// @brief Configruation structure for UclALPhySerialWindows
///
/// The SUclALPhySerialWindowsCfg structure defines the configuration
/// data for UclALPhySerialWindows_Impl class.
///
typedef struct SUclALPhySerialWindowsCfg_t
{
    char8 *pDevicePath;
    uint16 txRingBufferSize; ///< Transmit Ring Buffer Size
    uint16 rxRingBufferSize; ///< Receive Ring Buffer Size
    uint8 *pTxRingBuffer;    ///< Transmit Ring Buffer Data Pointer
    uint8 *pRxRingBuffer;    ///< Receive Ring Buffer Data Pointer
    uint16 txDmaBufferSize;  ///< Transmit Dma Buffer Size
    uint16 rxDmaBufferSize;  ///< Receive Dma Buffer Size
    uint8 *pTxDmaBuffer;     ///< Transmit Dma Buffer Data Pointer
    uint8 *pRxDmaBuffer;     ///< Receive Dma Buffer Data Pointer
} SUclALPhySerialWindowsCfg;

///
/// @brief Instance Structure for UclALPhySerialWindows
///
/// The SUclALPhySerialWindowsInst structure defines the private
/// instance data for UclALPhySerialWindows_Impl class.
///

typedef struct SUclALPhySerialWindowsInst_t
{
    uint8 numIUclALPhyCbk;                 ///< Number of connected IUclALPhyCbk instances
    uint8 *pIUclALPhyCbk;                  ///< Instance ID of the connected IUclALPhyCbk instances
    const SUclALPhySerialWindowsCfg *pCfg; ///< Configuration for the UclALPhySpiLinux instance
    SUclCmnRingBuffer txRingBuffer;        ///< Transmit Ring Buffer
    SUclCmnRingBuffer rxRingBuffer;        ///< Receive Ring Buffer
    uint32 txRingBufferMutexId;            ///< Transmit Ring Buffer Protection Mutex
    uint32 rxRingBufferMutexId;            ///< Receive Ring Buffer Protection Mutex
    HANDLE hSerial;                        ///< Handle for the Serial Device
    uint32 txTaskId;
    uint32 rxTaskId;
    uint32 txSemId;
} SUclALPhySerialWindowsInst;

///
/// @brief Function to intialize the UclALPhySerialWindows_Impl class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_NOK - Init success, UCL_E_NOK - Init Failure.
///
///
Ucl_ReturnType UclALPhySerialWindows_Impl_IUclALPhy_Initialize(SUclALPhySerialWindowsInst *pInst, uint8 InstId);
Ucl_ReturnType UclALPhySerialWindows_Impl_IUclALPhy_Shutdown(SUclALPhySerialWindowsInst *pInst, uint8 InstId);
Ucl_ReturnType UclALPhySerialWindows_Impl_IUclALPhy_Write(SUclALPhySerialWindowsInst *pInst, uint8 InstId, uint8 *pData,
                                                          uint16 Size);
Ucl_ReturnType UclALPhySerialWindows_Impl_IUclALPhy_Read(SUclALPhySerialWindowsInst *pInst, uint8 InstId, uint8 *pData,
                                                         uint16 *pSize);

#endif //UCLALPHY_SERIALWINDOWSIMPL
