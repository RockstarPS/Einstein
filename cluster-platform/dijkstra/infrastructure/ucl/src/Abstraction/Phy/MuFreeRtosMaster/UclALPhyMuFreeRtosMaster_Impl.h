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
/// @file UclALPhyMuFreeRtosMaster_Impl.h
/// @ingroup UclALPhy
///
/// @brief UCL Physical Layer Abstraction Implementation for MU on FreeRtosMaster Operating System
///
/// APIs in this file are not to called directly by the users
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALPHY_MUFreeRtosMasterIMPL
#define UCLALPHY_MUFreeRtosMasterIMPL

#include "UclCmnRingBuffer.h"
#include "Ucl_Types.h"

/// MU - Register Layout Typedef
typedef struct SUclALPhyMuReg_t
{
    volatile uint32 TR[4];       ///< Processor A Transmit Register 0, array offset: 0x0, array step: 0x4
    volatile const uint32 RR[4]; ///< Processor A Receive Register 0, array offset: 0x10, array step: 0x4
    volatile uint32 SR;          ///< Processor A Status Register, offset: 0x20
    volatile uint32 CR;          ///< Processor A Control Register, offset: 0x24
} SUclALPhyMuReg;

///
/// @brief Configuration Structure for UclALPhyMuFreeRtosMaster_Impl
/// @ingroup UclALPhy
///
/// The SUclALPhyMuFreeRtosMasterCfg structure defines the configuration
/// data for UclALPhyMuFreeRtosMaster class.
///
typedef struct SUclALPhyMuFreeRtosMasterCfg_t
{
    uint32 muBaseAddress;    ///< MU Base Address
    uint32 interruptNum;     ///< MU Interrupt Number
    uint8 periodicityMs;     ///< MU Driver task periodicity
    uint16 txRingBufferSize; ///< Size of the transmit ring buffer
    uint16 rxRingBufferSize; ///< Size of the receive ring buffer
    uint8 *pTxRingBuffer;    ///< Pointer to transmit ring buffer data
    uint8 *pRxRingBuffer;    ///< Pointer to receive ring buffer data
} SUclALPhyMuFreeRtosMasterCfg;

///
/// @brief Configuration Structure for UclALPhyMuFreeRtosMaster_Impl
/// @ingroup UclALPhy
///
/// The SUclALPhyMuFreeRtosMasterInst structure defines the instance
/// data for UclALPhyMuFreeRtosMaster class.
///
typedef struct SUclALPhyMuFreeRtosMasterInst_t
{
    uint8 numIUclALPhyCbk;         ///< Number of connected IUclALPhyCbk instances
    uint8 *pIUclALPhyCbk;          ///< Instance ID of the connected IUclALPhyCbk instances
    const SUclALPhyMuFreeRtosMasterCfg *pCfg; ///< Configuration for the UclALPhyMuFreeRtosMaster instance

    SUclALPhyMuReg *pMuRegs;        ///< MU Registers
    uint8 muState;                  ///< MU Driver State
    uint8 *pTxShMemBuffer;          ///< Transmit Shared Memory Buffer Address
    uint8 *pRxShMemBuffer;          ///< Receive Shared Memory Buffer Address
    SUclCmnRingBuffer txRingBuffer; ///< Transmit Ring Buffer
    SUclCmnRingBuffer rxRingBuffer; ///< Receive Ring Buffer
    uint32 txRingBufferMutexId;     ///< Transmit Ring Buffer Protection Mutex
    uint32 rxRingBufferMutexId;     ///< Receive Ring Buffer Protection Mutex
    uint32 timerTaskId;             ///< MU TimerTask Id
    uint32 muStateChkTimerTaskId;   ///< MU State Check TimerTask Id
    uint16 txBufferState;           ///< Transmit Buffer State
    uint16 txBufferSize;            ///< Transmit Buffer Size
    uint16 rxBufferState;           ///< Receive Buffer State
    uint16 rxBufferSize;            ///< Receive Buffer Size
} SUclALPhyMuFreeRtosMasterInst;

///
/// @brief Function to Initialize the UclALPhyMuFreeRtosMaster class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_NOK - Successfully initialized
/// @return UCL_E_NOK - Initialization failed
///
Ucl_ReturnType UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Initialize ( SUclALPhyMuFreeRtosMasterInst *pInst, uint8 InstId );

///
/// @brief Function to Shutdown the UclALPhyMuFreeRtosMaster class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_OK - Shutdown successful
/// @return UCL_E_NOK - Shutdown failed
///
Ucl_ReturnType UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Shutdown ( SUclALPhyMuFreeRtosMasterInst *pInst, uint8 InstId );

///
/// @brief Function to send data to the UclALPhyMuFreeRtosMaster class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
/// @param pData Pointer to the data buffer
/// @param Size Size of the data buffer
///
/// @return UCL_E_OK - Write successful
/// @return UCL_E_NOK - Write failed
///
Ucl_ReturnType UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Write ( SUclALPhyMuFreeRtosMasterInst *pInst, uint8 InstId, uint8 *pData, uint16 Size );

///
/// @brief Function to read data from the UclALPhyMuFreeRtosMaster class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
/// @param pData Pointer to the data buffer
/// @param *pSize [in] Size of the data buffer, [out] Number of bytes copied
///
/// @return UCL_E_OK - Read successful
/// @return UCL_E_NOK - Read failed or no data to read
///
Ucl_ReturnType UclALPhyMuFreeRtosMaster_Impl_IUclALPhy_Read ( SUclALPhyMuFreeRtosMasterInst *pInst, uint8 InstId, uint8 *pData, uint16 *pSize );

//Implementation for interface IUclALHwCbk
void UclALPhyMuFreeRtosMaster_Impl_IUclALHwCbk_TransmitComplete ( SUclALPhyMuFreeRtosMasterInst *pInst, uint8 InstId );
void UclALPhyMuFreeRtosMaster_Impl_IUclALHwCbk_ReceiveComplete ( SUclALPhyMuFreeRtosMasterInst *pInst, uint8 InstId );
void UclALPhyMuFreeRtosMaster_Impl_IUclALHwCbk_GpioChanged ( SUclALPhyMuFreeRtosMasterInst *pInst, uint8 InstId, uint16 GpioId );

#endif //UCLALPHY_MUFreeRtosMasterIMPL
