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
/// UCL Physical Layer Abstraction Implementation for IPC Mailbox ASR Operating Systems.
/// APIs in this file are not to called directly by the users.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALPHY_MAILBOXASRIMPL
#define UCLALPHY_MAILBOXASRIMPL

#include "UclALPhy_Types.h"
#include "UclCmnRingBuffer.h"
#include "UclALPhyCbk_Types.h"

///
/// @brief Configruation structure for UclALPhyMailboxASR
///
/// The SUclALPhyMailboxASRCfg structure defines the configuration
/// data for UclALPhyMailboxASR_Impl class.
///
typedef struct SUclALPhyMailboxASRCfg_t
{
    uint32 mailboxBaseAddress;  ///< Mailbox Base Address
    uint8 periodicityMs;        ///< Mailbox Driver task periodicity
    uint16 txRingBufferSize;    ///< Transmit Ring Buffer Size
    uint16 rxRingBufferSize;    ///< Receive Ring Buffer Size
    uint8 *pTxRingBuffer;       ///< Transmit Ring Buffer Data Pointer
    uint8 *pRxRingBuffer;       ///< Receive Ring Buffer Data Pointer
} SUclALPhyMailboxASRCfg;

///
/// @brief Instance Structure for UclALPhyMailboxASR
///
/// The SUclALPhyRpMsgASRInst structure defines the private
/// instance data for UclALPhyMailboxASR_Impl class.
///
typedef struct SUclALPhyMailboxASRInst_t
{
    uint8 numIUclALPhyCbk;                ///< Number of connected IUclALPhyCbk instances
    uint8 *pIUclALPhyCbk;                 ///< Instance ID of the connected IUclALPhyCbk instances
    const SUclALPhyMailboxASRCfg *pCfg;   ///< Configuration for the SUclALPhyMailboxCfg instance
    uint8 driverState;                    ///< Mailbox Driver State
    uint8 remoteDriverState;              ///< Mailbox Remote Driver State
    uint32 timerTaskId;                   ///< Transfer/Receive TimerTask Id
    uint32 driverStateChkTimerTaskId;     ///< Mailbox driver State Check TimerTask Id
    uint32 txShMemBuffeAddr;              ///< Transmit Shared Memory Buffer Address
    uint32 rxShMemBufferAddr;             ///< Receive Shared Memory Buffer Address
    uint8 *pTxShMemBuffer;                ///< Transmit Shared Memory Buffer Address
    uint8 *pRxShMemBuffer;                ///< Receive Shared Memory Buffer Address
    SUclCmnRingBuffer txRingBuffer;       ///< Transmit Ring Buffer
    SUclCmnRingBuffer rxRingBuffer;       ///< Receive Ring Buffer
    uint32 txRingBufferMutexId;           ///< Transmit Ring Buffer Protection Mutex
    uint32 rxRingBufferMutexId;           ///< Receive Ring Buffer Protection Mutex
} SUclALPhyMailboxASRInst;

///
/// @brief Function to intialize the UclALMailboxASR_Impl class.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_NOK - Init success, UCL_E_NOK - Init Failure.
///
///
Ucl_ReturnType UclALPhyMailboxASR_Impl_IUclALPhy_Initialize ( SUclALPhyMailboxASRInst *pInst, uint8 InstId );

///
/// @brief Function to shutdown the connection to the Mailbox physical layer.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
/// @return UCL_E_NOK - Init success, UCL_E_NOK - Init Failure.
///
///
Ucl_ReturnType UclALPhyMailboxASR_Impl_IUclALPhy_Shutdown ( SUclALPhyMailboxASRInst *pInst, uint8 InstId );

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
Ucl_ReturnType UclALPhyMailboxASR_Impl_IUclALPhy_Write ( SUclALPhyMailboxASRInst *pInst, uint8 InstId, uint8 *pData,
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
Ucl_ReturnType UclALPhyMailboxASR_Impl_IUclALPhy_Read ( SUclALPhyMailboxASRInst *pInst, uint8 InstId, uint8 *pData,
        uint16 *pSize );

///
/// @brief Callback Function to notify transmit complete.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
///
void UclALPhyMailboxASR_Impl_IUclALHwCbk_TransmitComplete ( SUclALPhyMailboxASRInst *pInst, uint8 InstId );

///
/// @brief Callback Function to notify Receive complete.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
///
void UclALPhyMailboxASR_Impl_IUclALHwCbk_ReceiveComplete ( SUclALPhyMailboxASRInst *pInst, uint8 InstId );

///
/// @brief Callback Function to notify GPIO changed.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller
///
///
void UclALPhyMailboxASR_Impl_IUclALHwCbk_GpioChanged ( SUclALPhyMailboxASRInst *pInst, uint8 InstId, uint16 GpioId );

#endif //UCLALPHY_MAILBOXASRIMPL
