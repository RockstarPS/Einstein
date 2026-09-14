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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/neutrino.h>
#include <hw/inout.h>
#include <errno.h>
#include <devctl.h>
#include <string.h>
#include "UclALPhyMbQnx_Impl.h"
#include "UclALPhyCbk.h"
#include "UclALDebug.h"
#include "UclALOs.h"

/*
SFI:
#define SFI_IPC_INTSR1 (0x100c0028)			 (0x0028) (SFI to Host)
#define SFI_IPC_SR3	(0x100c008c)			 (0x008C) Length (SFI to Host)
#define SFI_IPC_SR4	(0x100c0090)			 (0x0090) Payload (SFI to Host)
#define SFI_IPC_SR5	(0x100c0094)			 (0x0094) Payload (SFI to Host)

 Host to SFI
#define SFI_IPC_INTGR1						 (0x001C) // Interrupt Generation Register 1
#define SFI_IPC_INTSR0						 (0x0014) // Interrupt Status Register 0
#define SFI_IPC_SR0							 (0x0080) //  Shared Register 0
#define SFI_IPC_SR1							 (0x0084) //  Shared Register 1
#define SFI_IPC_SR2							 (0x0088) //  Shared Register 2
#define SFI_IPC_INTCR1						 (0x0020) //Interrupt Clear Register
#define SFI_IPC_INTMSR1						 (0x002C) //Interrupt Mask Status Register  (Whenever Trigger INTGR1 set ) 

 SFI TO Host
#define SFI_IPC_INTGR0						 (0x0008) // Interrupt Generation Register 0
#define SFI_IPC_INTSR1						 (0x0028) // Interrupt Status Register 1
#define SFI_IPC_INTMSR1						 (0x002C) // Interrupt Mask Status Reg
#define SFI_IPC_SR3							 (0x008C) //  Shared Register 3
#define SFI_IPC_SR4							 (0x0090) //  Shared Register 4
#define SFI_IPC_SR5							 (0x0094) //  Shared Register 5
#define SFI_IPC_INTCR0						 (0x000C)  //Interrupt Clear Register //SFI IPC interrupt status register clear

#define SFI_IPC_INTMR0						 (0x0010)  //Interrupt Mask Register
#define SFI_IPC_INTMSR0						 (0x0018)  //Interrupt Mask Status reg
#define SFI_IPC_INTMR1						 (0x0024) //Interrupt Mask Register


Reset the all the reg
Note: (set 1 to 0x100C0000) eg. {io 4B 0x100c0000 1}

 */


#define MU_READY_TIME_MS                 50u

#define MAILBOX_AP_CR52_C0_SIZE          0x1000

/// MU Driver States
#define MU_INIT_ST 0u
#define MU_SETUP_ST 1u
#define MU_READY_ST 2u
#define MU_ERROR_ST 3u

/// MU Buffer States
#define MU_BUFFER_IDLE 0u
#define MU_BUFFER_READY 1u
#define MU_BUFFER_EMPTY 2u
#define MU_BUFFER_BUSY 3u

#define MB_SR0      0U
#define MB_SR1      1U
#define MB_SR2      2U
#define MB_SR3      3U
#define MB_SR4      4U
#define MB_SR5      5U

#define MU_BUFFER_SIZE 0x400

static void *UclALPhyMuQnx_Impl_MuStateCheckTimerTask ( void *pData );
static void *UclALPhyMuQnx_Impl_TimerTask ( void *pData );
static void UclALPhyMuQnx_Impl_Transfer ( SUclALPhyMuQnxInst *pInst );

static Ucl_ReturnType UclALPhyMuQnx_Impl_Hw_MuOpen ( SUclALPhyMuQnxInst *pInst );
static Ucl_ReturnType UclALPhyMuQnx_Impl_Hw_MuClose ( SUclALPhyMuQnxInst *pInst );
static uint8 UclALPhyMuQnx_Impl_Hw_GetRemoteMuState ( SUclALPhyMuQnxInst *pInst );
static void UclALPhyMuQnx_Impl_Hw_SetMuState ( SUclALPhyMuQnxInst *pInst, uint8 state );
static uint8 UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty ( SUclALPhyMuQnxInst *pInst, uint8 txRegId );
static uint8 UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull ( SUclALPhyMuQnxInst *pInst, uint8 rxRegId );

static void UclALPhyMuQnx_Impl_Hw_WriteDataRegister ( SUclALPhyMuQnxInst *pInst, uint8 regId, uint32 value );
static uint32 UclALPhyMuQnx_Impl_Hw_ReadDataRegister ( SUclALPhyMuQnxInst *pInst, uint8 regId );
static uint8 UclALPhyMuQnx_Impl_Hw_IsDataAvailable ( SUclALPhyMuQnxInst *pInst, uint8 regId );

Ucl_ReturnType UclALPhyMuQnx_Impl_IUclALPhy_Initialize ( SUclALPhyMuQnxInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    LOGI ( 0, "UclALPhyMuQnx_Impl", "1 Num Phy Cbks %d\n", pInst->numIUclALPhyCbk );

    Ret = UclALPhyMuQnx_Impl_Hw_MuOpen ( pInst );

    if ( Ret != UCL_E_OK )
    {
        LOGE ( 0, "UclALPhyMuLinux_Impl", "UclALPhyMuLinux_Impl_HwMuOpen Failed %ld\n", Ret );
    }

    if ( Ret == UCL_E_OK )
    {
        Ret = UclCmnRingBuffer_Initialize ( &pInst->txRingBuffer, pInst->pCfg->pTxRingBuffer,
                        pInst->pCfg->txRingBufferSize );
    }

    if ( Ret == UCL_E_OK )
    {
        Ret = UclCmnRingBuffer_Initialize ( &pInst->rxRingBuffer, pInst->pCfg->pRxRingBuffer,
                        pInst->pCfg->rxRingBufferSize );
    }

    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_MutexCreate ( 0, &pInst->txRingBufferMutexId );
    }

    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_MutexCreate ( 0, &pInst->rxRingBufferMutexId );
    }

    //Initialize TimerTask
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TimerCreate ( 0, &pInst->timerTaskId, UclALPhyMuQnx_Impl_TimerTask, ( void * ) pInst,
                        eUclOsTimerType_Periodic );
    }

    //Initialize MU State Check Timer
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TimerCreate ( 0, &pInst->muStateChkTimerTaskId, UclALPhyMuQnx_Impl_MuStateCheckTimerTask, ( void * ) pInst,
                        eUclOsTimerType_Periodic );
    }

    //Start TimerTask
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TimerStart ( 0, pInst->timerTaskId, pInst->pCfg->periodicityMs );
    }

    if ( UCL_E_OK == Ret )
    {
        UclALPhyMuQnx_Impl_Hw_SetMuState ( pInst, MU_INIT_ST );

        LOGI ( 0, "UclALPhyMuQnx_Impl", "IUclALPhy_Initialize Success %d %d\n", pInst->timerTaskId,  pInst->muStateChkTimerTaskId);
    }
    else
    {
        LOGE ( 0, "UclALPhyMuLinux_Impl", "IUclALPhy_Initialize Failed %ld\n", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALPhyMuQnx_Impl_IUclALPhy_Shutdown ( SUclALPhyMuQnxInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret;

    Ret = UclALPhyMuQnx_Impl_Hw_MuClose ( pInst );

    if ( UCL_E_OK == Ret )
    {
        ( void ) UclALOs_TimerStop ( 0, pInst->timerTaskId );
        ( void ) UclALOs_TimerDestroy ( 0, pInst->timerTaskId );
        ( void ) UclALOs_TimerStop ( 0, pInst->muStateChkTimerTaskId );
        ( void ) UclALOs_TimerDestroy ( 0, pInst->muStateChkTimerTaskId );

        ( void ) UclALOs_MutexDestroy ( 0, pInst->txRingBufferMutexId );
        ( void ) UclALOs_MutexDestroy ( 0, pInst->rxRingBufferMutexId );

        LOGI ( 0, "UclALPhyMuQnx_Impl", "%s", "IUclALPhy_Shutdown Success\n" );
    }
    else
    {
        LOGE ( 0, "UclALPhyMuQnx_Impl", "IUclALPhy_Shutdown Failed %ld\n", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALPhyMuQnx_Impl_IUclALPhy_Write ( SUclALPhyMuQnxInst *pInst, uint8 InstId, uint8 *pData, uint16 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( ( NULL_PTR == pData ) || ( 0u == Size ) )
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else if ( NULL_PTR == pInst->pMuRegs )
    {
        LOGE ( 0, "UclALPhyMuQnx_Impl", "IUclALPhy_Write Invalid MU Pointer for 0x%08x\n", pInst->pCfg->muBaseAddress );
    }
    else
    {
        if ( UCL_E_OK == UclALOs_MutexLock ( 0, pInst->txRingBufferMutexId ) )
        {
            Ret = UclCmnRingBuffer_Write ( & ( pInst->txRingBuffer ), pData, Size );

            if ( UCL_E_NOK == Ret )
            {
                //TODO: Buffer full Handle Error
                LOGE ( 0, "UclALPhyMuQnx_Impl", "IUclALPhy_Write No space to write %d\n", Size );
            }

            ( void ) UclALOs_MutexUnlock ( 0, pInst->txRingBufferMutexId );
        }
    }

    return Ret;
}

Ucl_ReturnType UclALPhyMuQnx_Impl_IUclALPhy_Read ( SUclALPhyMuQnxInst *pInst, uint8 InstId, uint8 *pData, uint16 *pSize )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( ( NULL_PTR == pData ) || ( NULL_PTR == pSize ) || ( 0u == *pSize ) )
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else
    {
        if ( UCL_E_OK == UclALOs_MutexLock ( 0, pInst->rxRingBufferMutexId ) )
        {
            Ret = UclCmnRingBuffer_ReadFrame ( &pInst->rxRingBuffer, 0x0, pData, pSize );
            ( void ) UclALOs_MutexUnlock ( 0, pInst->rxRingBufferMutexId );
        }
    }

    return Ret;
}

static void *UclALPhyMuQnx_Impl_MuStateCheckTimerTask ( void *pData )
{
    uint16 i = 0;
    SUclALPhyMuQnxInst *pInst = ( SUclALPhyMuQnxInst * ) pData;
    uint8 rmtMuState;

    //Stop MU State Check Timer
    ( void ) UclALOs_TimerStop ( 0, pInst->muStateChkTimerTaskId );
    rmtMuState = UclALPhyMuQnx_Impl_Hw_GetRemoteMuState ( pInst );

    if ( ( pInst->muState != MU_READY_ST ) || ( rmtMuState != MU_READY_ST ) )
    {
        LOGI ( 0, "UclALPhyMuQnx_Impl", "eUclALPhyPeerReadyStatus_NotReady %d - %d", pInst->muState, rmtMuState );
        UclALPhyMuQnx_Impl_Hw_SetMuState ( pInst, MU_ERROR_ST );

        for ( i = 0; i < pInst->numIUclALPhyCbk; i++ )
        {
            (void)UclALPhyCbk_PeerReadyStatusChanged ( pInst->pIUclALPhyCbk[i], eUclALPhyPeerReadyStatus_NotReady );
        }
    }
    else
    {
        LOGI ( 0, "UclALPhyMuQnx_Impl", "MUs In Lock, %d - %d", pInst->muState, rmtMuState );
    }

    return NULL_PTR;
}

static void *UclALPhyMuQnx_Impl_TimerTask ( void *pData )
{
    uint16 i = 0;
    SUclALPhyMuQnxInst *pInst = ( SUclALPhyMuQnxInst * ) pData;

    //Check States
    switch ( pInst->muState )
    {
        case MU_INIT_ST:
            if ( MU_SETUP_ST == UclALPhyMuQnx_Impl_Hw_GetRemoteMuState ( pInst ) )
            {
                UclALPhyMuQnx_Impl_Hw_SetMuState ( pInst, MU_SETUP_ST );

                //Start MU State Check Timer
                ( void ) UclALOs_TimerStart ( 0, pInst->muStateChkTimerTaskId, MU_READY_TIME_MS );
            }

            break;

        case MU_SETUP_ST:
            if ( MU_READY_ST == UclALPhyMuQnx_Impl_Hw_GetRemoteMuState ( pInst ) )
            {
                pInst->txBufferState = MU_BUFFER_IDLE;
                pInst->rxBufferState = MU_BUFFER_EMPTY;
                pInst->rxBufferSize = MU_BUFFER_SIZE;

                UclALPhyMuQnx_Impl_Hw_WriteDataRegister( pInst, MB_SR1, ( ( ( uint32 ) pInst->rxBufferSize << 16 ) | MU_BUFFER_EMPTY ) );
                UclALPhyMuQnx_Impl_Hw_SetMuState ( pInst, MU_READY_ST );

                LOGI ( 0, "UclALPhyMuQnx_Impl", "%s", "MU Ready State\n" );

                for ( i = 0; i < pInst->numIUclALPhyCbk; i++ )
                {
                    LOGI ( 0, "UclALPhyMuQnx_Impl", "PeerReadyStatusChanged %d\n", i );
                    UclALPhyCbk_PeerReadyStatusChanged ( pInst->pIUclALPhyCbk[i], eUclALPhyPeerReadyStatus_Ready );
                }
            }

            break;

        case MU_READY_ST:
            if ( MU_READY_ST == UclALPhyMuQnx_Impl_Hw_GetRemoteMuState ( pInst ) )
            {

                UclALPhyMuQnx_Impl_Transfer ( pInst );
            }

            break;

        case MU_ERROR_ST:
        {
            UclALPhyMuQnx_Impl_Hw_WriteDataRegister( pInst, MB_SR0, ( uint32 ) MU_BUFFER_IDLE );
            UclALPhyMuQnx_Impl_Hw_WriteDataRegister( pInst, MB_SR1, ( uint32 ) MU_BUFFER_IDLE );

            //TODO: Error Handling
            UclALPhyMuQnx_Impl_Hw_SetMuState ( pInst, MU_INIT_ST );
            LOGE ( 0, "UclALPhyMuQnx_Impl", "%s", "MU in Error State. Set to INIT_ST\n" );
        }
        break;

        default:
            LOGE ( 0, "UclALPhyMuQnx_Impl", "Invalid MU State %d\n", pInst->muState );
            break;
    }

    return NULL_PTR;
}

static void UclALPhyMuQnx_Impl_Transfer ( SUclALPhyMuQnxInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;
    uint32 Temp32 = 0;
    uint16 TxSize = 0;
    uint16 RxSize = 0;

    // Transmit: Update Buffer Status from remote node
    if ( 0u != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull ( pInst, MB_SR3 ) )
    {
        Temp32 = UclALPhyMuQnx_Impl_Hw_ReadDataRegister( pInst, MB_SR3 );
        pInst->txBufferState = ( uint16 ) ( Temp32 & 0xFFFFu );

        if ( MU_BUFFER_EMPTY == pInst->txBufferState )
        {
            pInst->txBufferSize = ( uint16 ) ( ( Temp32 >> 16 ) & 0xFFFFu );
        }
    }

    // Transmit: Transfer Data
    if ( ( MU_BUFFER_EMPTY == pInst->txBufferState ) && ( 0u != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty ( pInst, MB_SR0 ) ) )
    {
        if ( UCL_E_OK == UclALOs_MutexLock ( 0, pInst->txRingBufferMutexId ) )
        {
            TxSize = pInst->txBufferSize;

            Ret = UclCmnRingBuffer_Read ( &pInst->txRingBuffer, pInst->pTxShMemBuffer, &TxSize );
            ( void ) UclALOs_MutexUnlock ( 0, pInst->txRingBufferMutexId );
        }

        if ( ( 0u < TxSize ) && ( UCL_E_OK == Ret ) )
        {
            Temp32 = ( ( ( uint32 ) TxSize << 16 ) | MU_BUFFER_READY );
            UclALPhyMuQnx_Impl_Hw_WriteDataRegister( pInst, MB_SR0, ( uint32 ) Temp32 );

            pInst->txBufferState = MU_BUFFER_READY;
        }
    }

    // Receive: Update Buffer Status from remote node
    if ( 0u != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull ( pInst, MB_SR4 ) )
    {
        Temp32 = UclALPhyMuQnx_Impl_Hw_ReadDataRegister( pInst, MB_SR4 );

        pInst->rxBufferState = ( uint16 ) ( Temp32 & 0xFFFFu );

        if ( MU_BUFFER_READY == pInst->rxBufferState )
        {
            RxSize = ( uint16 ) ( ( Temp32 >> 16 ) & 0xFFFFu );
        }
    }

    // Receive: Transfer Data
    if ( ( MU_BUFFER_READY == pInst->rxBufferState ) && ( 0u != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty ( pInst, MB_SR1 ) ) )
    {
        if ( 0u < RxSize )
        {
            if ( UCL_E_OK == UclALOs_MutexLock ( 0, pInst->rxRingBufferMutexId ) )
            {
                ( void ) UclCmnRingBuffer_Write ( &pInst->rxRingBuffer, pInst->pRxShMemBuffer, RxSize );
                ( void ) UclALOs_MutexUnlock ( 0, pInst->rxRingBufferMutexId );
            }
        }

        Temp32 = ( ( ( uint32 ) pInst->rxBufferSize << 16 ) | MU_BUFFER_EMPTY );
        UclALPhyMuQnx_Impl_Hw_WriteDataRegister( pInst, MB_SR1, ( uint32 ) Temp32 );

        pInst->rxBufferState = MU_BUFFER_EMPTY;

    }
}

static Ucl_ReturnType UclALPhyMuQnx_Impl_Hw_MuOpen ( SUclALPhyMuQnxInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    pInst->pMuRegs = NULL_PTR;

    if ( ThreadCtl ( _NTO_TCTL_IO, NULL_PTR ) == -1 )
    {
        LOGE ( 0, "UclALPhyMuQnx_Impl", "%s", "Hw_MuOpen ThreadCtl Failed\n" );
    }
    else
    {

        pInst->pMuRegs = ( SUclALPhyMuReg * ) mmap_device_memory ( NULL_PTR, MAILBOX_AP_CR52_C0_SIZE , PROT_READ | PROT_WRITE | PROT_NOCACHE, 0, pInst->pCfg->muBaseAddress );

        if ( MAP_FAILED != pInst->pMuRegs )
        {
            Ret = UCL_E_OK;
        }
        else
        {
            LOGE ( 0, "UclALPhyMuQnx_Impl", "%s", "Hw_MuOpen muBaseAddress mmap failed\n" );
        }
    }

    if (( UCL_E_OK == Ret ) && ( pInst->pMuRegs != NULL_PTR ))
    {
        /* make sure no interrupt is pending before initialization */
        //TODO: Attach Interrupt
        Ret = UCL_E_OK;
    }

    // Allocate Shared Memory for Transmit Buffer
    if ( UCL_E_OK == Ret )
    {
        pInst->pTxShMemBuffer = ( uint8 * ) mmap_device_memory ( NULL_PTR, pInst->pCfg->txShmMemPhySize, PROT_READ | PROT_WRITE | PROT_NOCACHE, 0, pInst->pCfg->txShmMemPhyAddr );

        if ( MAP_FAILED == pInst->pTxShMemBuffer )
        {
            Ret = UCL_E_NOK;
            LOGE ( 0, "UclALPhyMuQnx_Impl", "%s", "Hw_MuOpen pTxShMemBuffer mmap failed\n" );
        }
    }

    // Allocate Shared Memory for Receive Buffer
    if ( UCL_E_OK == Ret )
    {
        pInst->pRxShMemBuffer = ( uint8 * ) mmap_device_memory ( NULL_PTR, pInst->pCfg->rxShmMemPhySize, PROT_READ | PROT_WRITE | PROT_NOCACHE, 0, pInst->pCfg->rxShmMemPhyAddr );

        if ( MAP_FAILED == pInst->pRxShMemBuffer )
        {
            Ret = UCL_E_NOK;
            LOGE ( 0, "UclALPhyMuQnx_Impl", "%s", "Hw_MuOpen pRxShMemBuffer mmap failed\n" );
        }
    }

    return Ret;
}

static Ucl_ReturnType UclALPhyMuQnx_Impl_Hw_MuClose ( SUclALPhyMuQnxInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;

    ( void ) munmap_device_memory ( pInst->pRxShMemBuffer, pInst->pCfg->rxShmMemPhySize );
    ( void ) munmap_device_memory ( pInst->pTxShMemBuffer, pInst->pCfg->txShmMemPhySize );
    ( void ) munmap_device_memory ( ( void * ) pInst->pMuRegs, MAILBOX_AP_CR52_C0_SIZE );

    pInst->pMuRegs = NULL_PTR;

    return Ret;
}

static void UclALPhyMuQnx_Impl_Hw_SetMuState ( SUclALPhyMuQnxInst *pInst, uint8 state )
{
    pInst->muState = state;
    UclALPhyMuQnx_Impl_Hw_WriteDataRegister( pInst, MB_SR2, ( uint32 ) state );
}

static uint8 UclALPhyMuQnx_Impl_Hw_GetRemoteMuState ( SUclALPhyMuQnxInst *pInst )
{
    return ( (uint8) UclALPhyMuQnx_Impl_Hw_ReadDataRegister( pInst, MB_SR5 ) );
}

static uint8 UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty ( SUclALPhyMuQnxInst *pInst, uint8 txRegId )
{
    return ( ( (uint8) UclALPhyMuQnx_Impl_Hw_IsDataAvailable( pInst, txRegId ) ) == 0U );
}

static uint8 UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull ( SUclALPhyMuQnxInst *pInst, uint8 rxRegId )
{
    return ( ( (uint8) UclALPhyMuQnx_Impl_Hw_IsDataAvailable( pInst, rxRegId ) ) != 0U );
}

static void UclALPhyMuQnx_Impl_Hw_WriteDataRegister ( SUclALPhyMuQnxInst *pInst, uint8 regId, uint32 value )
{
    switch(regId) 
    {
        case MB_SR0:
            pInst->pMuRegs->SR0 = value;
            pInst->pMuRegs->INTGR1 = (1 << regId);
        break;
        case MB_SR1:
            pInst->pMuRegs->SR1 = value;
            pInst->pMuRegs->INTGR1 = (1 << regId);
        break;
        case MB_SR2:
            pInst->pMuRegs->SR2 = value;
            pInst->pMuRegs->INTGR1 = (1 << regId);
        break;
        case MB_SR3:
            pInst->pMuRegs->SR3 = value;
            pInst->pMuRegs->INTGR1 = (1 << regId);
        break;
        case MB_SR4:
            pInst->pMuRegs->SR4 = value;
            pInst->pMuRegs->INTGR1 = (1 << regId);
        break;
        case MB_SR5:
            pInst->pMuRegs->SR5 = value;
            pInst->pMuRegs->INTGR1 = (1 << regId);
        break;
    }
}

static uint32 UclALPhyMuQnx_Impl_Hw_ReadDataRegister ( SUclALPhyMuQnxInst *pInst, uint8 regId )
{
    uint32 value = 0U;

    switch(regId) 
    {
        case MB_SR0:
            value = pInst->pMuRegs->SR0;
            pInst->pMuRegs->INTCR1 = (1 << regId);
        break;
        case MB_SR1:
            value = pInst->pMuRegs->SR1;
            pInst->pMuRegs->INTCR1 = (1 << regId);
        break;
        case MB_SR2:
            value = pInst->pMuRegs->SR2;
            pInst->pMuRegs->INTCR1 = (1 << regId);
        break;
        case MB_SR3:
            value = pInst->pMuRegs->SR3;
            pInst->pMuRegs->INTCR1 = (1 << regId);
        break;
        case MB_SR4:
            value = pInst->pMuRegs->SR4;
            pInst->pMuRegs->INTCR1 = (1 << regId);
        break;
        case MB_SR5:
            value = pInst->pMuRegs->SR5;
            pInst->pMuRegs->INTCR1 = (1 << regId);
        break;
    }
	return value;
}

static uint8 UclALPhyMuQnx_Impl_Hw_IsDataAvailable ( SUclALPhyMuQnxInst *pInst, uint8 regId )
{
    uint8 value = 0U;

    switch(regId) 
    {
        case MB_SR0:
            value = (pInst->pMuRegs->INTSR1 & (1 << regId));
        break;
        case MB_SR1:
            value = (pInst->pMuRegs->INTSR1 & (1 << regId));
        break;
        case MB_SR2:
            value = (pInst->pMuRegs->INTSR1 & (1 << regId));
        break;
        case MB_SR3:
            value = (pInst->pMuRegs->INTSR1 & (1 << regId));
        break;
        case MB_SR4:
            value = (pInst->pMuRegs->INTSR1 & (1 << regId));
        break;
        case MB_SR5:
            value = (pInst->pMuRegs->INTSR1 & (1 << regId));
        break;
    }

    if(0U != value)
    {
        value = 1U;
    }

    return value;
}
