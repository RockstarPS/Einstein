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
#include "UclALPhyMbASR_Impl.h"
#include "UclALPhyCbk.h"
#include "UclALOs.h"
#include "UclALDebug.h"
#include "arch_helper.h"
#include "SfiLib.h"
#include <CDD_Compat.h>

#define MU_READY_TIME_MS        50u

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

#define CLI_DRAM_BASE0 (0x05800000u)
#define CLI_DRAM_BASE1 (0x06100000u)

/**< using mailbox in sfi core0 */
#define MAILBOX_CORE_0          (uint8)(0u)
/**< using mailbox in sfi core1 */
#define MAILBOX_CORE_1          (uint8)(1u)

static unsigned int cli_host_dram_addr_diff;
void *invalidate_start;
void *invalidate_end;

static void *UclALPhyMuASR_Impl_MuStateCheckTimerTask ( void *pData );
static void *UclALPhyMuASR_Impl_TimerTask ( void *pData );
static void UclALPhyMuASR_Impl_Transfer ( SUclALPhyMuASRInst *pInst );
static Ucl_ReturnType UclALPhyMuASR_Impl_Hw_MuOpen ( SUclALPhyMuASRInst *pInst );
static Ucl_ReturnType UclALPhyMuASR_Impl_Hw_MuClose ( SUclALPhyMuASRInst *pInst );
static uint8 UclALPhyMuASR_Impl_Hw_GetRemoteMuState ( SUclALPhyMuASRInst *pInst );
static void UclALPhyMuASR_Impl_Hw_SetMuState ( SUclALPhyMuASRInst *pInst, uint8 state );
static uint8 UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty ( SUclALPhyMuASRInst *pInst, uint8 txRegId );
static uint8 UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull ( SUclALPhyMuASRInst *pInst, uint8 rxRegId );

static void UclALPhyMuASR_Impl_Hw_WriteDataRegister ( SUclALPhyMuASRInst *pInst, uint8 regId, uint32 value );
static uint32 UclALPhyMuASR_Impl_Hw_ReadDataRegister ( SUclALPhyMuASRInst *pInst, uint8 regId );
static uint8 UclALPhyMuASR_Impl_Hw_IsDataAvailable ( SUclALPhyMuASRInst *pInst, uint8 regId );

Ucl_ReturnType UclALPhyMuASR_Impl_IUclALPhy_Initialize ( SUclALPhyMuASRInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint32 cli_dram_base;

    if (Compat_Get_Cpuid() == MAILBOX_CORE_0)
    {
        cli_dram_base = CLI_DRAM_BASE0;
    }
    else if (Compat_Get_Cpuid() == MAILBOX_CORE_1)
    {
        cli_dram_base = CLI_DRAM_BASE1;
    }
    else
    {
        cli_dram_base = CLI_DRAM_BASE0;
    }

    cli_host_dram_addr_diff = SfiLib_BaawConvertToDramSysAddr(cli_dram_base) - cli_dram_base;

    Ret = UclALPhyMuASR_Impl_Hw_MuOpen ( pInst );

    if ( Ret != UCL_E_OK )
    {
        LOGE ( 0, "UclALPhyMuLinux_Impl", "UclALPhyMuLinux_Impl_HwMuOpen Failed %d\n", Ret );
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
        Ret = UclALOs_TimerCreate ( 0, &pInst->timerTaskId, UclALPhyMuASR_Impl_TimerTask, ( void * ) pInst,
                        eUclOsTimerType_Periodic );
    }

    //Initialize MU State Check Timer
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TimerCreate ( 0, &pInst->muStateChkTimerTaskId, UclALPhyMuASR_Impl_MuStateCheckTimerTask, ( void * ) pInst,
                        eUclOsTimerType_Periodic );
    }

    //Start TimerTask
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TimerStart ( 0, pInst->timerTaskId, pInst->pCfg->periodicityMs );
    }

    if ( UCL_E_OK == Ret )
    {
        UclALPhyMuASR_Impl_Hw_SetMuState ( pInst, MU_INIT_ST );

        LOGI ( 0, "UclALPhyMuASR_Impl", "%s", "IUclALPhy_Initialize Success\n" );
    }
    else
    {
        LOGE ( 0, "UclALPhyMuLinux_Impl", "IUclALPhy_Initialize Failed %d\n", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALPhyMuASR_Impl_IUclALPhy_Shutdown ( SUclALPhyMuASRInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret;

    Ret = UclALPhyMuASR_Impl_Hw_MuClose ( pInst );

    if ( UCL_E_OK == Ret )
    {
        ( void ) UclALOs_TimerStop ( 0, pInst->timerTaskId );
        ( void ) UclALOs_TimerDestroy ( 0, pInst->timerTaskId );
        ( void ) UclALOs_TimerStop ( 0, pInst->muStateChkTimerTaskId );
        ( void ) UclALOs_TimerDestroy ( 0, pInst->muStateChkTimerTaskId );

        ( void ) UclALOs_MutexDestroy ( 0, pInst->txRingBufferMutexId );
        ( void ) UclALOs_MutexDestroy ( 0, pInst->rxRingBufferMutexId );

        LOGI ( 0, "UclALPhyMuASR_Impl", "%s", "IUclALPhy_Shutdown Success\n" );
    }
    else
    {
        LOGE ( 0, "UclALPhyMuASR_Impl", "IUclALPhy_Shutdown Failed %d\n", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALPhyMuASR_Impl_IUclALPhy_Write ( SUclALPhyMuASRInst *pInst, uint8 InstId, uint8 *pData, uint16 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( ( NULL == pData ) || ( 0u == Size ) )
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else
    {
        if ( UCL_E_OK == UclALOs_MutexLock ( 0, pInst->txRingBufferMutexId ) )
        {
            Ret = UclCmnRingBuffer_Write ( & ( pInst->txRingBuffer ), pData, Size );

            if ( UCL_E_NOK == Ret )
            {
                //TODO: Buffer full Handle Error
                LOGE ( 0, "UclALPhyMuASR_Impl", "IUclALPhy_Write No space to write %d\n", Size );
            }

            ( void ) UclALOs_MutexUnlock ( 0, pInst->txRingBufferMutexId );
        }
    }

    return Ret;
}

Ucl_ReturnType UclALPhyMuASR_Impl_IUclALPhy_Read ( SUclALPhyMuASRInst *pInst, uint8 InstId, uint8 *pData, uint16 *pSize )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( ( NULL == pData ) || ( NULL == pSize ) || ( 0u == *pSize ) )
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

void UclALPhyMuASR_Impl_IUclALHwCbk_TransmitComplete ( SUclALPhyMuASRInst *pInst, uint8 InstId )
{
}

void UclALPhyMuASR_Impl_IUclALHwCbk_ReceiveComplete ( SUclALPhyMuASRInst *pInst, uint8 InstId )
{
}

void UclALPhyMuASR_Impl_IUclALHwCbk_GpioChanged ( SUclALPhyMuASRInst *pInst, uint8 InstId, uint16 GpioId )
{
}

static void *UclALPhyMuASR_Impl_MuStateCheckTimerTask ( void *pData )
{
    uint16 i = 0;
    SUclALPhyMuASRInst *pInst = ( SUclALPhyMuASRInst * ) pData;

    //Stop MU State Check Timer
    ( void ) UclALOs_TimerStop ( 0, pInst->muStateChkTimerTaskId );

    if ( ( pInst->muState != MU_READY_ST ) || ( UclALPhyMuASR_Impl_Hw_GetRemoteMuState ( pInst ) != MU_READY_ST ) )
    {
        UclALPhyMuASR_Impl_Hw_SetMuState ( pInst, MU_ERROR_ST );

        for ( i = 0; i < pInst->numIUclALPhyCbk; i++ )
        {
            LOGI ( 0, "UclALPhyMuQnx_Impl", "PeerReadyStatusChanged %d\n", i );
            UclALPhyCbk_PeerReadyStatusChanged ( pInst->pIUclALPhyCbk[i], eUclALPhyPeerReadyStatus_NotReady );
        }
    }

    return NULL;
}

static void *UclALPhyMuASR_Impl_TimerTask ( void *pData )
{
    uint16 i = 0;
    SUclALPhyMuASRInst *pInst = ( SUclALPhyMuASRInst * ) pData;

    //Check States
    switch ( pInst->muState )
    {
        case MU_INIT_ST:
            if ( MU_INIT_ST == UclALPhyMuASR_Impl_Hw_GetRemoteMuState ( pInst ) )
            {
                UclALPhyMuASR_Impl_Hw_WriteDataRegister( pInst, MB_SR3, ( uint32 ) MU_BUFFER_IDLE );
                UclALPhyMuASR_Impl_Hw_WriteDataRegister( pInst, MB_SR4, ( uint32 ) MU_BUFFER_IDLE );

                UclALPhyMuASR_Impl_Hw_SetMuState ( pInst, MU_SETUP_ST );
            }

            break;

        case MU_SETUP_ST:
            if ( MU_SETUP_ST == UclALPhyMuASR_Impl_Hw_GetRemoteMuState ( pInst ) )
            {
                pInst->pTxShMemBuffer = pInst->pCfg->txShmMemPhyAddr ;
                pInst->pRxShMemBuffer = pInst->pCfg->rxShmMemPhyAddr ;

                pInst->txBufferState = MU_BUFFER_IDLE;
                pInst->rxBufferState = MU_BUFFER_EMPTY;
                pInst->rxBufferSize = MU_BUFFER_SIZE;

                UclALPhyMuASR_Impl_Hw_WriteDataRegister( pInst, MB_SR3, ( uint32 ) ( ( ( uint32 ) pInst->rxBufferSize << 16 ) | MU_BUFFER_EMPTY ) );

                UclALPhyMuASR_Impl_Hw_SetMuState ( pInst, MU_READY_ST );
                LOGI ( 0, "UclALPhyMuASR_Impl", "%s", "MU Ready State\n" );

                for ( i = 0; i < pInst->numIUclALPhyCbk; i++ )
                {
                    LOGI ( 0, "UclALPhyMuASR_Impl", "PeerReadyStatusChanged %d\n", i );
                    UclALPhyCbk_PeerReadyStatusChanged ( pInst->pIUclALPhyCbk[i], eUclALPhyPeerReadyStatus_Ready );
                }

                //Start MU State Check Timer
                ( void ) UclALOs_TimerStart ( 0, pInst->muStateChkTimerTaskId, MU_READY_TIME_MS );
            }

            break;

        case MU_READY_ST:
            if ( MU_READY_ST == UclALPhyMuASR_Impl_Hw_GetRemoteMuState ( pInst ) )
            {
                UclALPhyMuASR_Impl_Transfer ( pInst );
            }

            break;

        case MU_ERROR_ST:
        {
            UclALPhyMuASR_Impl_Hw_WriteDataRegister( pInst, MB_SR3, ( uint32 ) MU_BUFFER_IDLE );
            UclALPhyMuASR_Impl_Hw_WriteDataRegister( pInst, MB_SR4, ( uint32 ) MU_BUFFER_IDLE );

            //TODO: Error Handling
            UclALPhyMuASR_Impl_Hw_SetMuState ( pInst, MU_INIT_ST );
            LOGE ( 0, "UclALPhyMuASR_Impl", "%s", "MU Error State\n" );
        }
        break;

        default:
            //LOGE(0, "UclALPhyMuASR_Impl", "Invalid MU State %d\n", pInst->muState);
            break;
    }

    return NULL;
}

static void UclALPhyMuASR_Impl_Transfer ( SUclALPhyMuASRInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;
    uint32 Temp32 = 0;
    uint16 TxSize = 0;
    uint16 RxSize = 0;

    // Transmit: Update Buffer Status from remote node
    if ( 0u != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull ( pInst, MB_SR1 ) )
    {
        Temp32 = UclALPhyMuASR_Impl_Hw_ReadDataRegister( pInst, MB_SR1 );
        pInst->txBufferState = ( uint16 ) ( Temp32 & 0xFFFFu );

        if ( MU_BUFFER_EMPTY == pInst->txBufferState )
        {
            pInst->txBufferSize = ( uint16 ) ( ( Temp32 >> 16 ) & 0xFFFF );
        }

        LOGI ( 0, "UclALPhyMuASR_Impl", "Transfer: Transmit Remote Node State 0x%08x\n", Temp32 );
    }

    // Transmit: Transfer Data
    if ( ( MU_BUFFER_EMPTY == pInst->txBufferState ) && ( 0u != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty ( pInst, MB_SR4 ) ) )
    {
        if ( UCL_E_OK == UclALOs_MutexLock ( 0, pInst->txRingBufferMutexId ) )
        {
            TxSize = pInst->txBufferSize;

            invalidate_start = (void *)pInst->pTxShMemBuffer;
            invalidate_end = (void *)((unsigned int)pInst->pTxShMemBuffer + TxSize);
            clean_invalidate_dcache_range(invalidate_start, invalidate_end);

            Ret = UclCmnRingBuffer_Read ( &pInst->txRingBuffer, pInst->pTxShMemBuffer, &TxSize );

            ( void ) UclALOs_MutexUnlock ( 0, pInst->txRingBufferMutexId );
        }

        if ( ( 0 < TxSize ) && ( UCL_E_OK == Ret ) )
        {
            Temp32 = ( ( ( uint32 ) TxSize << 16 ) | MU_BUFFER_READY );
            UclALPhyMuASR_Impl_Hw_WriteDataRegister( pInst, MB_SR4, ( uint32 ) Temp32 );

            pInst->txBufferState = MU_BUFFER_READY;

            LOGI ( 0, "UclALPhyMuASR_Impl", "Transfer: Transmit Node State 0x%08x\n", Temp32 );
        }
    }

    // Receive: Update Buffer Status from remote node
    if ( 0u != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull ( pInst, MB_SR0 ) )
    {
        Temp32 = UclALPhyMuASR_Impl_Hw_ReadDataRegister( pInst, MB_SR0 );
        pInst->rxBufferState = ( uint16 ) ( Temp32 & 0xFFFFu );

        if ( MU_BUFFER_READY == pInst->rxBufferState )
        {
            RxSize = ( uint16 ) ( ( Temp32 >> 16u ) & 0xFFFFu );
        }

        LOGI ( 0, "UclALPhyMuASR_Impl", "Transfer: Receive Remote Node State 0x%08x\n", Temp32 );
    }

    // Receive: Transfer Data
    if ( ( MU_BUFFER_READY == pInst->rxBufferState ) && ( 0 != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty ( pInst, MB_SR3 ) ) )
    {
        if ( 0u < RxSize )
        {
            if ( UCL_E_OK == UclALOs_MutexLock ( 0, pInst->rxRingBufferMutexId ) )
            {
                invalidate_start = (void *)pInst->pRxShMemBuffer;
                invalidate_end = (void *)((unsigned int)pInst->pRxShMemBuffer + RxSize);
                clean_invalidate_dcache_range(invalidate_start, invalidate_end);

                Ret = UclCmnRingBuffer_Write ( &pInst->rxRingBuffer, pInst->pRxShMemBuffer, RxSize );

                ( void ) UclALOs_MutexUnlock ( 0, pInst->rxRingBufferMutexId );
            }
        }

        Temp32 = ( ( ( uint32 ) pInst->rxBufferSize << 16 ) | MU_BUFFER_EMPTY );
        UclALPhyMuASR_Impl_Hw_WriteDataRegister( pInst, MB_SR3, ( uint32 ) Temp32 );

        pInst->rxBufferState = MU_BUFFER_EMPTY;

        LOGI ( 0, "UclALPhyMuASR_Impl", "Transfer: Receive Node State 0x%08x\n", Temp32 );
    }
}

static Ucl_ReturnType UclALPhyMuASR_Impl_Hw_MuOpen ( SUclALPhyMuASRInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;

    pInst->pMuRegs = ( SUclALPhyMuReg * ) pInst->pCfg->muBaseAddress;

    if ( NULL != pInst->pMuRegs )
    {
        //TODO: Attach Interrupt
        Ret = UCL_E_OK;
    }

    return Ret;
}

static Ucl_ReturnType UclALPhyMuASR_Impl_Hw_MuClose ( SUclALPhyMuASRInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;

    return Ret;
}

static void UclALPhyMuASR_Impl_Hw_SetMuState ( SUclALPhyMuASRInst *pInst, uint8 state )
{
    pInst->muState = state;
    UclALPhyMuASR_Impl_Hw_WriteDataRegister( pInst, MB_SR5, ( uint32 ) state );
}

static uint8 UclALPhyMuASR_Impl_Hw_GetRemoteMuState ( SUclALPhyMuASRInst *pInst )
{
    return ( (uint8) UclALPhyMuASR_Impl_Hw_ReadDataRegister( pInst, MB_SR2 ) );
}

static uint8 UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty ( SUclALPhyMuASRInst *pInst, uint8 txRegId )
{
    return ( ( (uint8) UclALPhyMuASR_Impl_Hw_IsDataAvailable( pInst, txRegId ) ) == 0U );
}

static uint8 UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull ( SUclALPhyMuASRInst *pInst, uint8 rxRegId )
{
    return ( ( (uint8) UclALPhyMuASR_Impl_Hw_IsDataAvailable( pInst, rxRegId ) ) != 0U );
}

static void UclALPhyMuASR_Impl_Hw_WriteDataRegister ( SUclALPhyMuASRInst *pInst, uint8 regId, uint32 value )
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

static uint32 UclALPhyMuASR_Impl_Hw_ReadDataRegister ( SUclALPhyMuASRInst *pInst, uint8 regId )
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

static uint8 UclALPhyMuASR_Impl_Hw_IsDataAvailable ( SUclALPhyMuASRInst *pInst, uint8 regId )
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
