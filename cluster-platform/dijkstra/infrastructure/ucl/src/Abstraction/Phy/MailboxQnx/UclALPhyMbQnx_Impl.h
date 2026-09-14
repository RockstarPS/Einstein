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
/// @file UclALPhyMuQnx_Impl.h
/// @ingroup UclALPhy
///
/// @brief UCL Physical Layer Abstraction Implementation for MU on QNX Operating System
///
/// APIs in this file are not to called directly by the users
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALPHY_MUQNXIMPL
#define UCLALPHY_MUQNXIMPL

#include "UclCmnRingBuffer.h"
#include "Ucl_Types.h"

/// MailBox Layout - Register Layout Typedef
typedef struct
{
    volatile uint32 MCUCTLR;     ///< MCU Controller array offset: 0x0, array step: 0x4
    volatile uint32 reserved;
    volatile uint32 INTGR0;         ///< Interrupt Generate Register, offset: 0x8 step: 0x4
    volatile uint32 INTCR0;         ///< Interrupt Clear Register 0, array offset: 0xc, array step: 0x4
    volatile uint32 INTMR0;         ///< Interrupt Mask Register array offset: 0x10, array step: 0x4
    volatile uint32 INTSR0;         ///< Interrupt Status Register 0 
    volatile uint32 INTMSR0;        ///< Interrupt Mask Register 0
    volatile uint32 INTGR1;
    volatile uint32 INTCR1;
    volatile uint32 INTMR1;
    volatile uint32 INTSR1;
    volatile uint32 INTMSR1;
    volatile uint32 INTGR2;
    volatile uint32 INTCR2;
    volatile uint32 INTMR2;
    volatile uint32 INTSR2;
    volatile uint32 INTMSR2;
    volatile uint32 INTGR3;
    volatile uint32 INTCR3;
    volatile uint32 INTMR3;
    volatile uint32 INTSR3;
    volatile uint32 INTMSR3;
    volatile uint32 INTGR4;
    volatile uint32 INTCR4;
    volatile uint32 INTMR4;
    volatile uint32 INTSR4;
    volatile uint32 INTMSR4;
    volatile uint32 reserved1;
    volatile uint32 VERSION;
    volatile uint32 reserved2;
    volatile uint32 reserved3;
    volatile uint32 reserved4;
    volatile uint32 SR0;
    volatile uint32 SR1;
    volatile uint32 SR2;
    volatile uint32 SR3;
    volatile uint32 SR4;
    volatile uint32 SR5;
    /* Not used SR6 TO SR63  0x80 TO 0x17C Shared Register 0 to 63 between CPU cores - Reset Value (0x0000_0000) */
} SUclALPhyMuReg;

///
/// @brief Configuration Structure for UclALPhyMuQnx_Impl
/// @ingroup UclALPhy
///
/// The SUclALPhyMuQnxCfg structure defines the configuration
/// data for UclALPhyMuQnx class.
///
typedef struct
{
    uint32 muBaseAddress;    ///< MU Base Address
    uint32 interruptNum;     ///< MU Interrupt Number
    uint8 periodicityMs;     ///< MU Driver task periodicity
    uint16 txRingBufferSize; ///< Size of the transmit ring buffer
    uint16 rxRingBufferSize; ///< Size of the receive ring buffer
    uint8 *pTxRingBuffer;    ///< Pointer to transmit ring buffer data
    uint8 *pRxRingBuffer;    ///< Pointer to receive ring buffer data
    uint64 txShmMemPhyAddr;
    uint16 txShmMemPhySize;
    uint64 rxShmMemPhyAddr;
    uint16 rxShmMemPhySize;
} SUclALPhyMuQnxCfg;

///
/// @brief Configuration Structure for UclALPhyMuQnx_Impl
/// @ingroup UclALPhy
///
/// The SUclALPhyMuQnxInst structure defines the instance
/// data for UclALPhyMuQnx class.
///
typedef struct
{
    const SUclALPhyMuQnxCfg *pCfg; ///< Configuration for the UclALPhyMuQnx instance
    uint8 numIUclALPhyCbk;         ///< Number of connected IUclALPhyCbk instances
    uint8 *pIUclALPhyCbk;          ///< Instance ID of the connected IUclALPhyCbk instances

    SUclALPhyMuReg *pMuRegs;        ///< MU Registers
    uint8 muState;                  ///< MU Driver State
    uint8 *pTxShMemBuffer;          ///< Transmit Shared Memory Buffer Virtual Address
    uint8 *pRxShMemBuffer;          ///< Receive Shared Memory Buffer Virtual Address
    SUclCmnRingBuffer txRingBuffer; ///< Transmit Ring Buffer
    SUclCmnRingBuffer rxRingBuffer; ///< Receive Ring Buffer
    uint32 txRingBufferMutexId;     ///< Transmit Ring Buffer Protection Mutex
    uint32 rxRingBufferMutexId;     ///< Receive Ring Buffer Protection Mutex
    uint32 timerTaskId;             ///< MU TimerTask Id
	uint32 muStateChkTimerTaskId;	///< MU State Check TimerTask Id
    uint16 txBufferState;           ///< Transmit Buffer State
    uint16 txBufferSize;            ///< Transmit Buffer Size
    uint16 rxBufferState;           ///< Receive Buffer State
    uint16 rxBufferSize;            ///< Receive Buffer Size
} SUclALPhyMuQnxInst;

///
/// @brief Function to Initialize the UclALPhyMuQnx class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_NOK - Successfully initialized
/// @return UCL_E_NOK - Initialization failed
///
Ucl_ReturnType UclALPhyMuQnx_Impl_IUclALPhy_Initialize ( SUclALPhyMuQnxInst *pInst, uint8 InstId );

///
/// @brief Function to Shutdown the UclALPhyMuQnx class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_OK - Shutdown successful
/// @return UCL_E_NOK - Shutdown failed
///
Ucl_ReturnType UclALPhyMuQnx_Impl_IUclALPhy_Shutdown ( SUclALPhyMuQnxInst *pInst, uint8 InstId );

///
/// @brief Function to send data to the UclALPhyMuQnx class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
/// @param pData Pointer to the data buffer
/// @param Size Size of the data buffer
///
/// @return UCL_E_OK - Write successful
/// @return UCL_E_NOK - Write failed
///
Ucl_ReturnType UclALPhyMuQnx_Impl_IUclALPhy_Write ( SUclALPhyMuQnxInst *pInst, uint8 InstId, uint8 *pData, uint16 Size );

///
/// @brief Function to read data from the UclALPhyMuQnx class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
/// @param pData Pointer to the data buffer
/// @param *pSize [in] Size of the data buffer, [out] Number of bytes copied
///
/// @return UCL_E_OK - Read successful
/// @return UCL_E_NOK - Read failed or no data to read
///
Ucl_ReturnType UclALPhyMuQnx_Impl_IUclALPhy_Read ( SUclALPhyMuQnxInst *pInst, uint8 InstId, uint8 *pData, uint16 *pSize );

#endif //UCLALPHY_MUQNXIMPL
