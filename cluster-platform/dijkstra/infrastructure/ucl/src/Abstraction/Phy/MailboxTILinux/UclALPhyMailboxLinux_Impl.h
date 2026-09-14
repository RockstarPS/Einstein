///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2024] Visteon Corporation
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
/// UCL Physical Layer Abstraction Implementation for IPC-Mailbox Linux Operating Systems.
/// APIs in this file are not to called directly by the users.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALPHY_MAILBOXLINUXIMPL
#define UCLALPHY_MAILBOXLINUXIMPL

#include "UclALPhy_Types.h"
#include "UclCmnRingBuffer.h"

///
/// @brief Register structure for Mailbox
///
/// The sMailboxReg structure defines the Mailbox registers
///
typedef struct
{
    volatile uint32 revisionReg;
    volatile uint32 reserved1[3];
    volatile uint32 sysconfig;
    volatile uint32 reserved2[11];
    volatile uint32 message[16];
    volatile uint32 fifoStatus[16];
    volatile uint32 msgStatus[16];
    volatile uint32 unused[17];
}sMailboxReg;

///
/// @brief Configruation structure for UclALPhyMailboxLinux
///
/// The SUclALPhyMailboxCfg structure defines the configuration
/// data for UclALPhyMailboxLinux_Impl class.
///
typedef struct
{
    uint32 mailboxBaseAddress;   ///< Mailbox Base Address
    uint8 periodicityMs;         ///< Mailbox Driver task periodicity
    uint16 txRingBufferSize;     ///< Transmit Ring Buffer Size
    uint16 rxRingBufferSize;     ///< Receive Ring Buffer Size
    uint8 *pTxRingBuffer;        ///< Transmit Ring Buffer Data Pointer
    uint8 *pRxRingBuffer;        ///< Receive Ring Buffer Data Pointer
    uint64 txShmMemPhyAddr;      ///< Transmit shared memory physical address
    uint16 txShmMemPhySize;      ///< Transmit shared memory physical address size
    uint64 rxShmMemPhyAddr;      ///< Receive shared memory physical address
    uint16 rxShmMemPhySize;      ///< Receive shared memory physical address size
} SUclALPhyMailboxCfg;

///
/// @brief Instance Structure for UclALPhyMailboxLinux
///
/// The SUclALPhyMailboxLinuxInst structure defines the private
/// instance data for UclALPhyMailboxLinux_Impl class.
///

typedef struct
{
    uint8 numIUclALPhyCbk;              ///< Number of connected IUclALPhyCbk instances
    uint8 *pIUclALPhyCbk;               ///< Instance ID of the connected IUclALPhyCbk instances
    const SUclALPhyMailboxCfg *pCfg;    ///< Configuration for the SUclALPhyMailboxCfg instance
    sMailboxReg* pMailboxReg;           ///< Mailbox Registers
    uint8 driverState;                  ///< Mailbox Driver State
    uint8 remoteDriverState;            ///< Mailbox Remote Driver State
    uint8 *pTxShMemBuffer;              ///< Transmit Shared Memory Buffer Virtual Address
    uint8 *pRxShMemBuffer;              ///< Receive Shared Memory Buffer Virtual Address
    SUclCmnRingBuffer txRingBuffer;     ///< Transmit Ring Buffer
    SUclCmnRingBuffer rxRingBuffer;     ///< Receive Ring Buffer
    uint32 txRingBufferMutexId;         ///< Transmit Ring Buffer Protection Mutex
    uint32 rxRingBufferMutexId;         ///< Receive Ring Buffer Protection Mutex
    uint32 timerTaskId;                 ///< Transfer/Receive TimerTask Id
    uint32 driverStateChkTimerTaskId;   ///< Mailbox driver State Check TimerTask Id
} SUclALPhyMailboxLinuxInst;

///
/// @brief Function to intialize the UclALPhyMailboxLinux_Impl class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_NOK - Init success, UCL_E_NOK - Init Failure.
///
///
Ucl_ReturnType UclALPhyMailboxLinux_Impl_IUclALPhy_Initialize ( SUclALPhyMailboxLinuxInst *pInst, uint8 InstId );

///
/// @brief Function to shutdown the connection to the Mailbox physical layer.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_NOK - Init success, UCL_E_NOK - Init Failure.
///
///
Ucl_ReturnType UclALPhyMailboxLinux_Impl_IUclALPhy_Shutdown ( SUclALPhyMailboxLinuxInst *pInst, uint8 InstId );

///
/// @brief Function to write data to the Mailbox physical layer.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
/// @param pData Pointer to the data to be written
/// @param Size Size of the data to be written
///
/// @return UCL_E_NOK - Init success, UCL_E_NOK - Init Failure.
///
///
Ucl_ReturnType UclALPhyMailboxLinux_Impl_IUclALPhy_Write ( SUclALPhyMailboxLinuxInst *pInst, uint8 InstId, uint8 *pData,
        uint16 Size );

///
/// @brief Function to read data from the Mailbox physical layer.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
/// @param pData Pointer to the data to copy
/// @param Size Size of the data
///
/// @return UCL_E_NOK - Init success, UCL_E_NOK - Init Failure.
///
///
Ucl_ReturnType UclALPhyMailboxLinux_Impl_IUclALPhy_Read ( SUclALPhyMailboxLinuxInst *pInst, uint8 InstId, uint8 *pData,
        uint16 *pSize );

#endif //UCLALPHY_MAILBOXLINUXIMPL
