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
#include <string.h>
#include "UclALPhyMuFreeRtosSlave_Impl.h"
#include "UclALPhyCbk.h"
#include "UclALDebug.h"
#include "UclALOs.h"
#include "cmsis_gcc.h"

#define MU_READY_TIME_MS        50u
///< TR Bit Fields
#define MU_TR_TR0_MASK 0xFFFFFFFFu
#define MU_TR_TR0_SHIFT 0
#define MU_TR_TR0(x) (((uint32)(((uint32)(x)) << MU_TR_TR0_SHIFT)) & MU_TR_TR0_MASK)
///< RR Bit Fields
#define MU_RR_RR0_MASK 0xFFFFFFFFu
#define MU_RR_RR0_SHIFT 0
#define MU_RR_RR0(x) (((uint32)(((uint32)(x)) << MU_RR_RR0_SHIFT)) & MU_RR_RR0_MASK)
///< SR Bit Fields
#define MU_SR_Fn_MASK 0x7u
#define MU_SR_Fn_SHIFT 0
#define MU_SR_Fn(x) (((uint32)(((uint32)(x)) << MU_SR_Fn_SHIFT)) & MU_SR_Fn_MASK)
#define MU_SR_EP_MASK 0x10u
#define MU_SR_EP_SHIFT 4
#define MU_SR_PM_MASK 0x60u
#define MU_SR_PM_SHIFT 5
#define MU_SR_PM(x) (((uint32)(((uint32)(x)) << MU_SR_PM_SHIFT)) & MU_SR_PM_MASK)
#define MU_SR_RS_MASK 0x80u
#define MU_SR_RS_SHIFT 7
#define MU_SR_FUP_MASK 0x100u
#define MU_SR_FUP_SHIFT 8
#define MU_SR_TEn_MASK 0xF00000u
#define MU_SR_TEn_SHIFT 20
#define MU_SR_TEn(x) (((uint32)(((uint32)(x)) << MU_SR_TEn_SHIFT)) & MU_SR_TEn_MASK)
#define MU_SR_RFn_MASK 0xF000000u
#define MU_SR_RFn_SHIFT 24
#define MU_SR_RFn(x) (((uint32)(((uint32)(x)) << MU_SR_RFn_SHIFT)) & MU_SR_RFn_MASK)
#define MU_SR_GIPn_MASK 0xF0000000u
#define MU_SR_GIPn_SHIFT 28
#define MU_SR_GIPn(x) (((uint32)(((uint32)(x)) << MU_SR_GIPn_SHIFT)) & MU_SR_GIPn_MASK)
///< CR Bit Fields
#define MU_CR_Fn_MASK (uint32)(0x7u)
#define MU_CR_Fn_SHIFT 0
#define MU_CR_Fn(x) (((uint32)(((uint32)(x)) << MU_CR_Fn_SHIFT)) & MU_CR_Fn_MASK)
#define MU_CR_HRM_MASK 0x10u
#define MU_CR_HRM_SHIFT 4
#define MU_CR_GIRn_MASK (uint32)(0xF0000u)
#define MU_CR_GIRn_SHIFT 16
#define MU_CR_GIRn(x) (((uint32)(((uint32)(x)) << MU_CR_GIRn_SHIFT)) & MU_CR_GIRn_MASK)
#define MU_CR_TIEn_MASK (uint32)(0xF00000u)
#define MU_CR_TIEn_SHIFT 20
#define MU_CR_TIEn(x) (((uint32)(((uint32)(x)) << MU_CR_TIEn_SHIFT)) & MU_CR_TIEn_MASK)
#define MU_CR_RIEn_MASK (uint32)(0xF000000u)
#define MU_CR_RIEn_SHIFT 24
#define MU_CR_RIEn(x) (((uint32)(((uint32)(x)) << MU_CR_RIEn_SHIFT)) & MU_CR_RIEn_MASK)
#define MU_CR_GIEn_MASK (uint32)(0xF0000000u)
#define MU_CR_GIEn_SHIFT 28
#define MU_CR_GIEn(x) (((uint32)(((uint32)(x)) << MU_CR_GIEn_SHIFT)) & MU_CR_GIEn_MASK)

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

#define MU_BUFFER_SIZE 0x400

static void *UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask ( void *pData );
static void *UclALPhyMuFreeRtosSlave_Impl_TimerTask ( void *pData );
static void UclALPhyMuFreeRtosSlave_Impl_Transfer ( SUclALPhyMuFreeRtosSlaveInst *pInst );

static Ucl_ReturnType UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen ( SUclALPhyMuFreeRtosSlaveInst *pInst );
static Ucl_ReturnType UclALPhyMuFreeRtosSlave_Impl_Hw_MuClose ( SUclALPhyMuFreeRtosSlaveInst *pInst );
static uint8 UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState ( SUclALPhyMuFreeRtosSlaveInst *pInst );
static void UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState ( SUclALPhyMuFreeRtosSlaveInst *pInst, uint8 state );
static uint8 UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty ( SUclALPhyMuFreeRtosSlaveInst *pInst, uint8 txRegId );
static uint8 UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull ( SUclALPhyMuFreeRtosSlaveInst *pInst, uint8 rxRegId );

static uint8 mu_debug = 0; //debug


Ucl_ReturnType UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Initialize ( SUclALPhyMuFreeRtosSlaveInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    LOGI ( 0, "UclALPhyMuFreeRtosSlave_Impl", "1 Num Phy Cbks %d\n", pInst->numIUclALPhyCbk );

    Ret = UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen ( pInst );

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
        Ret = UclALOs_TimerCreate ( 0, &pInst->timerTaskId, UclALPhyMuFreeRtosSlave_Impl_TimerTask, ( void * ) pInst,
                        eUclOsTimerType_Periodic );
    }

    //Initialize MU State Check Timer
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TimerCreate ( 0, &pInst->muStateChkTimerTaskId, UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask, ( void * ) pInst,
                        eUclOsTimerType_Periodic );
    }

    //Start TimerTask
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TimerStart ( 0, pInst->timerTaskId, pInst->pCfg->periodicityMs );
    }

    if ( UCL_E_OK == Ret )
    {
        UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState ( pInst, MU_INIT_ST );

        LOGI ( 0, "UclALPhyMuFreeRtosSlave_Impl", "IUclALPhy_Initialize Success %d %d\n", pInst->timerTaskId,  pInst->muStateChkTimerTaskId);
    }
    else
    {
        LOGE ( 0, "UclALPhyMuLinux_Impl", "IUclALPhy_Initialize Failed %ld\n", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Shutdown ( SUclALPhyMuFreeRtosSlaveInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret;

    Ret = UclALPhyMuFreeRtosSlave_Impl_Hw_MuClose ( pInst );

    if ( UCL_E_OK == Ret )
    {
        ( void ) UclALOs_TimerStop ( 0, pInst->timerTaskId );
        ( void ) UclALOs_TimerDestroy ( 0, pInst->timerTaskId );
        ( void ) UclALOs_TimerStop ( 0, pInst->muStateChkTimerTaskId );
        ( void ) UclALOs_TimerDestroy ( 0, pInst->muStateChkTimerTaskId );

        ( void ) UclALOs_MutexDestroy ( 0, pInst->txRingBufferMutexId );
        ( void ) UclALOs_MutexDestroy ( 0, pInst->rxRingBufferMutexId );

        LOGI ( 0, "UclALPhyMuFreeRtosSlave_Impl", "%s", "IUclALPhy_Shutdown Success\n" );
    }
    else
    {
        LOGE ( 0, "UclALPhyMuFreeRtosSlave_Impl", "IUclALPhy_Shutdown Failed %ld\n", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Write ( SUclALPhyMuFreeRtosSlaveInst *pInst, uint8 InstId, uint8 *pData, uint16 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( ( NULL_PTR == pData ) || ( 0u == Size ) )
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else if ( NULL_PTR == pInst->pMuRegs )
    {
        LOGE ( 0, "UclALPhyMuFreeRtosSlave_Impl", "IUclALPhy_Write Invalid MU Pointer for 0x%08x\n", pInst->pCfg->muBaseAddress );
    }
    else
    {
        if ( UCL_E_OK == UclALOs_MutexLock ( 0, pInst->txRingBufferMutexId ) )
        {
			
            Ret = UclCmnRingBuffer_Write ( & ( pInst->txRingBuffer ), pData, Size );
			

            if ( UCL_E_NOK == Ret )
            {
                //TODO: Buffer full Handle Error
                LOGE ( 0, "UclALPhyMuFreeRtosSlave_Impl", "IUclALPhy_Write No space to write %d\n", Size );
            }

            ( void ) UclALOs_MutexUnlock ( 0, pInst->txRingBufferMutexId );
        }
    }

    return Ret;
}

Ucl_ReturnType UclALPhyMuFreeRtosSlave_Impl_IUclALPhy_Read ( SUclALPhyMuFreeRtosSlaveInst *pInst, uint8 InstId, uint8 *pData, uint16 *pSize )
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

static void *UclALPhyMuFreeRtosSlave_Impl_MuStateCheckTimerTask ( void *pData )
{
    uint16 i = 0;
    SUclALPhyMuFreeRtosSlaveInst *pInst = ( SUclALPhyMuFreeRtosSlaveInst * ) pData;
    uint8 rmtMuState;

    //Stop MU State Check Timer
    ( void ) UclALOs_TimerStop ( 0, pInst->muStateChkTimerTaskId );
    rmtMuState = UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState ( pInst );

    if ( ( pInst->muState != MU_READY_ST ) || ( rmtMuState != MU_READY_ST ) )
    {
        LOGI ( 0, "UclALPhyMuFreeRtosSlave_Impl", "eUclALPhyPeerReadyStatus_NotReady %d - %d", pInst->muState, rmtMuState );
        UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState ( pInst, MU_ERROR_ST );

        for ( i = 0; i < pInst->numIUclALPhyCbk; i++ )
        {
            (void)UclALPhyCbk_PeerReadyStatusChanged ( pInst->pIUclALPhyCbk[i], eUclALPhyPeerReadyStatus_NotReady );
        }
    }
    else
    {
        LOGI ( 0, "UclALPhyMuFreeRtosSlave_Impl", "MUs In Lock, %d - %d", pInst->muState, rmtMuState );
    }

    return NULL_PTR;

}

static void *UclALPhyMuFreeRtosSlave_Impl_TimerTask ( void *pData )
{
    uint16 i = 0;
    SUclALPhyMuFreeRtosSlaveInst *pInst = ( SUclALPhyMuFreeRtosSlaveInst * ) pData;

    //Check States
    switch ( pInst->muState )
    {
        case MU_INIT_ST:
            if ( MU_SETUP_ST == UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState ( pInst ) )
            {
                pInst->pMuRegs->TR[0] = ( uint32 ) pInst->pCfg->txShmMemPhyAddr; // m4 to m7
                pInst->pMuRegs->TR[1] = ( uint32 ) pInst->pCfg->rxShmMemPhyAddr; // m7 to M4
                pInst->pMuRegs->TR[2] = MU_BUFFER_IDLE;
                pInst->pMuRegs->TR[3] = MU_BUFFER_IDLE;
                UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState ( pInst, MU_SETUP_ST );

                //Start MU State Check Timer
                ( void ) UclALOs_TimerStart ( 0, pInst->muStateChkTimerTaskId, MU_READY_TIME_MS );
            }

            break;

        case MU_SETUP_ST:
            if ( MU_READY_ST == UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState ( pInst ) )
            {
                pInst->txBufferState = MU_BUFFER_IDLE;

                pInst->rxBufferState = MU_BUFFER_EMPTY;
                pInst->rxBufferSize = MU_BUFFER_SIZE;
                pInst->pMuRegs->TR[1] = ( ( ( uint32 ) pInst->rxBufferSize << 16 ) | MU_BUFFER_EMPTY );

                UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState ( pInst, MU_READY_ST );
                LOGI ( 0, "UclALPhyMuFreeRtosSlave_Impl", "%s", "MU Ready State\n" );

                for ( i = 0; i < pInst->numIUclALPhyCbk; i++ )
                {
                    LOGI ( 0, "UclALPhyMuFreeRtosSlave_Impl", "PeerReadyStatusChanged %d\n", i );
                    UclALPhyCbk_PeerReadyStatusChanged ( pInst->pIUclALPhyCbk[i], eUclALPhyPeerReadyStatus_Ready );
                }
            }

            break;

        case MU_READY_ST:
            if ( MU_READY_ST == UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState ( pInst ) )
            {
                if ( mu_debug == 0u ) //debug
                {
                    mu_debug = 1;//debug
                    LOGI ( 0, "UclALPhyMuFreeRtosSlave_Impl", "%s", "MUs locked. Transfer started \n" );
                }

                UclALPhyMuFreeRtosSlave_Impl_Transfer ( pInst );
            }

            break;

        case MU_ERROR_ST:
        {
            pInst->pMuRegs->TR[0] = MU_BUFFER_IDLE;
            pInst->pMuRegs->TR[1] = MU_BUFFER_IDLE;
            pInst->pMuRegs->TR[2] = MU_BUFFER_IDLE;
            pInst->pMuRegs->TR[3] = MU_BUFFER_IDLE;
            //TODO: Error Handling
            UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState ( pInst, MU_INIT_ST );
            LOGE ( 0, "UclALPhyMuFreeRtosSlave_Impl", "%s", "MU in Error State. Set to INIT_ST\n" );
        }
        break;

        default:
            LOGE ( 0, "UclALPhyMuFreeRtosSlave_Impl", "Invalid MU State %d\n", pInst->muState );
            break;
    }

    return NULL_PTR;

}

static void UclALPhyMuFreeRtosSlave_Impl_Transfer ( SUclALPhyMuFreeRtosSlaveInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;
    uint32 Temp32 = 0;
    uint16 TxSize = 0;
    uint16 RxSize = 0;

    // Transmit: Update Buffer Status from remote node
    if ( 0u != UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull ( pInst, 0 ) )
    {
        Temp32 = pInst->pMuRegs->RR[0];
        pInst->txBufferState = ( uint16 ) ( Temp32 & 0xFFFFu );

        if ( MU_BUFFER_EMPTY == pInst->txBufferState )
        {
            pInst->txBufferSize = ( uint16 ) ( ( Temp32 >> 16 ) & 0xFFFFu );
        }
    }

    // Transmit: Transfer Data
    if ( ( MU_BUFFER_EMPTY == pInst->txBufferState ) && ( 0u != UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty ( pInst, 0 ) ) )
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
            
            pInst->pMuRegs->TR[0] = Temp32;
            pInst->txBufferState = MU_BUFFER_READY;
        }
		else
		{
			
		}
    }

    // Receive: Update Buffer Status from remote node
    if ( 0u != UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull ( pInst, 1 ) )
    {
        Temp32 = pInst->pMuRegs->RR[1];
        pInst->rxBufferState = ( uint16 ) ( Temp32 & 0xFFFFu );

        if ( MU_BUFFER_READY == pInst->rxBufferState )
        {
            RxSize = ( uint16 ) ( ( Temp32 >> 16 ) & 0xFFFFu );
        }
    }

    // Receive: Transfer Data
    if ( ( MU_BUFFER_READY == pInst->rxBufferState ) && ( 0u != UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty ( pInst, 1 ) ) )
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
		
        pInst->pMuRegs->TR[1] = Temp32;
        pInst->rxBufferState = MU_BUFFER_EMPTY;

    }

}

static Ucl_ReturnType UclALPhyMuFreeRtosSlave_Impl_Hw_MuOpen ( SUclALPhyMuFreeRtosSlaveInst *pInst )
{
	Ucl_ReturnType Ret = UCL_E_OK;

	pInst->pMuRegs = ( SUclALPhyMuReg * ) pInst->pCfg->muBaseAddress;
	pInst->pTxShMemBuffer =  pInst->pCfg->txShmMemPhyAddr;
	pInst->pRxShMemBuffer =  pInst->pCfg->rxShmMemPhyAddr;

	if ( NULL != pInst->pMuRegs )
	{
		// Clear GIEn, RIEn, TIEn, GIRn and ABFn.
		pInst->pMuRegs->CR &= ( uint32 ) ( ~ ( MU_CR_GIEn_MASK | MU_CR_RIEn_MASK | MU_CR_TIEn_MASK | MU_CR_GIRn_MASK | MU_CR_Fn_MASK ) );

		pInst->pMuRegs->TR[0] = 0x0;
		pInst->pMuRegs->TR[1] = 0x0;
		pInst->pMuRegs->TR[2] = 0x0;
		pInst->pMuRegs->TR[3] = 0x0;
		pInst->pMuRegs->CR = 0x0;
		//TODO: Attach Interrupt
		Ret = UCL_E_OK;
	}

	return Ret;

}

static Ucl_ReturnType UclALPhyMuFreeRtosSlave_Impl_Hw_MuClose ( SUclALPhyMuFreeRtosSlaveInst *pInst )
{
	Ucl_ReturnType Ret = UCL_E_OK;
	
	pInst->pRxShMemBuffer = NULL_PTR;
	pInst->pTxShMemBuffer = NULL_PTR;
	pInst->pMuRegs = NULL_PTR;

	return Ret;
}

static void UclALPhyMuFreeRtosSlave_Impl_Hw_SetMuState ( SUclALPhyMuFreeRtosSlaveInst *pInst, uint8 state )
{
    uint32 tempCR = pInst->pMuRegs->CR;

    pInst->muState = state;

    tempCR &= ~MU_CR_Fn_MASK;
    tempCR |= MU_CR_Fn ( state );
    pInst->pMuRegs->CR = tempCR;

}

static uint8 UclALPhyMuFreeRtosSlave_Impl_Hw_IsTransmitRegisterEmpty ( SUclALPhyMuFreeRtosSlaveInst *pInst, uint8 txRegId )
{
    return ( uint8 ) ( ( ( pInst->pMuRegs->SR & MU_SR_TEn ( ( ( uint32 ) 1u << ( 3u - txRegId ) ) ) ) ) != 0u );
}

static uint8 UclALPhyMuFreeRtosSlave_Impl_Hw_IsReceiveRegisterFull ( SUclALPhyMuFreeRtosSlaveInst *pInst, uint8 rxRegId )
{
    return ( uint8 ) ( ( ( pInst->pMuRegs->SR & MU_SR_RFn ( ( ( uint32 ) 1u << ( 3u - rxRegId ) ) ) ) ) != 0u );
}

static uint8 UclALPhyMuFreeRtosSlave_Impl_Hw_GetRemoteMuState ( SUclALPhyMuFreeRtosSlaveInst *pInst )
{
    return ( ( uint8 ) ( pInst->pMuRegs->SR & MU_SR_Fn_MASK ) );
}
