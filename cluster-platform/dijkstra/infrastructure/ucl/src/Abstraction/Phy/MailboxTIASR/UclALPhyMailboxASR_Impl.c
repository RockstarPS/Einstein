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
#include "UclCmnRingBuffer.h"
#include "UclALPhyCbk.h"
#include "UclALOs.h"
#include "UclALDebug.h"
#include "UclALPhyMailboxASR_Impl.h"

#define MAILBOX_MESSAGE_REG(n)               ( ( uint32 ) 0x40U + ( (n) * 4U ) )
#define MAILBOX_FIFOSTATUS_REG(n)            ( ( uint32 ) 0x80U + ( (n) * 4U ) )
#define MAILBOX_MSGSTATUS_REG(n)             ( ( uint32 ) 0xC0U + ( (n) * 4U ) )

#define MAILBOX_REG_RD(addr) ( * ( volatile uint32 * ) ( addr ) )

#define MAILBOX_REG_WR(addr, value)  ( * ( ( volatile uint32 * ) ( addr ) ) = ( value ) )

#define MAILBOX_DRIVER_STATE_CHECK_TIME_MS        50U

/// Mailbox Driver States
#define MAILBOX_INIT_ST     0U
#define MAILBOX_SETUP_ST    1U
#define MAILBOX_READY_ST    2U
#define MAILBOX_ERROR_ST    3U
#define MAILBOX_INVALID_ST  4U

/// Mailbox message queue index
#define MAILBOX_DRIVER_STATUS_MSG_QUE_IDX          0U
#define MAILBOX_REMOTE_DRIVER_STATUS_MSG_QUE_IDX   1U
#define MAILBOX_SHARDMEMORY_MSG_QUE_IDX            2U
#define MAILBOX_TRASMIT_MSG_QUE_IDX                3U
#define MAILBOX_RECEIVE_MSG_QUE_IDX                4U

#define MAILBOX_MESSAGE_STATUS_EMPTY  0U
#define MAILBOX_FIFO_STATUS_EMPTY     0U

#define MAILBOX_BUFFER_MAX_SIZE      4096U
#define MAILBOX_DATA_SIZE_MIN        0U

static void *UclALPhyMailboxASR_Impl_TimerTask ( void *pData );
static void *UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask ( void *pData );
static void UclALPhyMailboxASR_Impl_Transfer ( SUclALPhyMailboxASRInst *pInst );
static Ucl_ReturnType UclALPhyMailboxASR_Impl_Hw_Open ( SUclALPhyMailboxASRInst *pInst );
static Ucl_ReturnType UclALPhyMailboxASR_Impl_Hw_Close ( SUclALPhyMailboxASRInst *pInst );
static Ucl_ReturnType UclALPhyMailboxASR_Impl_Hw_Write ( SUclALPhyMailboxASRInst *pInst, uint32 data, uint8 queueId );
static Ucl_ReturnType UclALPhyMailboxASR_Impl_Hw_Read ( SUclALPhyMailboxASRInst *pInst, uint32 *pData, uint8 queueId );
static Ucl_ReturnType UclALPhyMailboxASR_Impl_Hw_SetDriverState ( SUclALPhyMailboxASRInst *pInst, uint8 state );
static uint8 UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState ( SUclALPhyMailboxASRInst *pInst );
static uint8 UclALPhyMailboxASR_Impl_Hw_MsgStatus ( SUclALPhyMailboxASRInst *pInst, uint8 queueId );

Ucl_ReturnType UclALPhyMailboxASR_Impl_IUclALPhy_Initialize ( SUclALPhyMailboxASRInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    ( void ) InstId;

    ( void ) UclALPhyMailboxASR_Impl_Hw_Open( pInst );

    Ret = UclALPhyMailboxASR_Impl_Hw_SetDriverState ( pInst, MAILBOX_INIT_ST );
    pInst->remoteDriverState = MAILBOX_INVALID_ST;

    if(UCL_E_OK == Ret)
    {
        Ret = UclCmnRingBuffer_Initialize ( &pInst->txRingBuffer, pInst->pCfg->pTxRingBuffer, pInst->pCfg->txRingBufferSize );
    }

    if ( UCL_E_OK == Ret )
    {
        Ret = UclCmnRingBuffer_Initialize ( &pInst->rxRingBuffer, pInst->pCfg->pRxRingBuffer, pInst->pCfg->rxRingBufferSize );
    }

    if ( UCL_E_OK == Ret )
    {
        Ret = UclALOs_MutexCreate ( 0U, &pInst->txRingBufferMutexId );
    }

    if ( UCL_E_OK == Ret )
    {
        Ret = UclALOs_MutexCreate ( 0U, &pInst->rxRingBufferMutexId );
    }

    if ( 0U != pInst->pCfg->periodicityMs )
    {
        //Initialize TimerTask
        if ( UCL_E_OK == Ret )
        {
            Ret = UclALOs_TimerCreate ( 0U, &pInst->timerTaskId, UclALPhyMailboxASR_Impl_TimerTask, ( void * ) pInst,
                                        eUclOsTimerType_Periodic );
        }

        //Initialize Driver State Check Timer
        if ( UCL_E_OK == Ret )
        {
            Ret = UclALOs_TimerCreate ( 0U, &pInst->driverStateChkTimerTaskId, UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask, ( void * ) pInst,
                        eUclOsTimerType_Periodic );
        }

        //Start TimerTask
        if ( UCL_E_OK == Ret )
        {
            Ret = UclALOs_TimerStart ( 0U, pInst->timerTaskId, pInst->pCfg->periodicityMs );
        }
    }

    return Ret;
}

Ucl_ReturnType UclALPhyMailboxASR_Impl_IUclALPhy_Shutdown ( SUclALPhyMailboxASRInst *pInst, uint8 InstId )
{
    ( void ) InstId;

    ( void ) UclALPhyMailboxASR_Impl_Hw_Close ( pInst );

    ( void ) UclALOs_TimerStop ( 0U, pInst->timerTaskId );
    ( void ) UclALOs_TimerDestroy ( 0U, pInst->timerTaskId );
    ( void ) UclALOs_TimerStop ( 0U, pInst->driverStateChkTimerTaskId );
    ( void ) UclALOs_TimerDestroy ( 0U, pInst->driverStateChkTimerTaskId );

    ( void ) UclALOs_MutexDestroy ( 0U, pInst->txRingBufferMutexId );
    ( void ) UclALOs_MutexDestroy ( 0U, pInst->rxRingBufferMutexId );

    return UCL_E_OK;
}

Ucl_ReturnType UclALPhyMailboxASR_Impl_IUclALPhy_Write ( SUclALPhyMailboxASRInst *pInst, uint8 InstId, uint8 *pData,
        uint16 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    ( void ) InstId;

    if ( ( NULL == pData ) || ( 0U == Size ) )
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else
    {
        if ( UCL_E_OK == UclALOs_MutexLock ( 0U, pInst->txRingBufferMutexId ) )
        {
            Ret = UclCmnRingBuffer_Write ( & ( pInst->txRingBuffer ), pData, Size );

            if ( UCL_E_NOK == Ret )
            {
                //TODO: Buffer full Handle Error
            }

            ( void ) UclALOs_MutexUnlock ( 0U, pInst->txRingBufferMutexId );
        }
    }

    return Ret;
}

Ucl_ReturnType UclALPhyMailboxASR_Impl_IUclALPhy_Read ( SUclALPhyMailboxASRInst *pInst, uint8 InstId, uint8 *pData,
        uint16 *pSize )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    ( void ) InstId;

    if ( ( NULL == pData ) || ( NULL == pSize ) || ( 0U == *pSize ) )
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else
    {
        if ( UCL_E_OK == UclALOs_MutexLock ( 0U, pInst->rxRingBufferMutexId ) )
        {
            Ret = UclCmnRingBuffer_ReadFrame ( &pInst->rxRingBuffer, 0U, pData, pSize );
            ( void ) UclALOs_MutexUnlock ( 0U, pInst->rxRingBufferMutexId );
        }
    }

    return Ret;
}

void UclALPhyMailboxASR_Impl_IUclALHwCbk_TransmitComplete ( SUclALPhyMailboxASRInst *pInst, uint8 InstId )
{
    (void) pInst;
    (void) InstId;
}

void UclALPhyMailboxASR_Impl_IUclALHwCbk_ReceiveComplete ( SUclALPhyMailboxASRInst *pInst, uint8 InstId )
{
    (void) pInst;
    (void) InstId;
}

void UclALPhyMailboxASR_Impl_IUclALHwCbk_GpioChanged ( SUclALPhyMailboxASRInst *pInst, uint8 InstId, uint16 GpioId )
{
    (void) pInst;
    (void) InstId;
    (void) GpioId;
}

static void *UclALPhyMailboxASR_Impl_DriveStateCheckTimerTask ( void *pData )
{
    SUclALPhyMailboxASRInst *pInst = ( SUclALPhyMailboxASRInst * ) pData;

    if( NULL != pInst )
    {
        pInst->remoteDriverState = UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState ( pInst );

        //Stop Driver State Check Timer
        ( void ) UclALOs_TimerStop ( 0U, pInst->driverStateChkTimerTaskId );

        if ( ( MAILBOX_READY_ST != pInst->driverState ) || ( MAILBOX_READY_ST != pInst->remoteDriverState ) )
        {
            ( void ) UclALPhyMailboxASR_Impl_Hw_SetDriverState ( pInst, MAILBOX_ERROR_ST );

            for ( uint8 i = 0U; i < pInst->numIUclALPhyCbk; i++ )
            {
                UclALPhyCbk_PeerReadyStatusChanged ( pInst->pIUclALPhyCbk[i], eUclALPhyPeerReadyStatus_NotReady );
            }
        }
    }

    return NULL;
}

static void *UclALPhyMailboxASR_Impl_TimerTask ( void *pData )
{
    SUclALPhyMailboxASRInst *pInst = ( SUclALPhyMailboxASRInst * ) pData;

    if( NULL != pInst )
    {
        //Check States
        switch ( pInst->driverState )
        {
            case MAILBOX_INIT_ST:
            {
                pInst->remoteDriverState = UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState ( pInst );
                if ( MAILBOX_INIT_ST ==  pInst->remoteDriverState )
                {
                    ( void ) UclALPhyMailboxASR_Impl_Hw_SetDriverState ( pInst, MAILBOX_SETUP_ST );
                }
            }
            break;

            case MAILBOX_SETUP_ST:
            {
                pInst->remoteDriverState = UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState ( pInst );
                if ( MAILBOX_SETUP_ST ==  pInst->remoteDriverState )
                {
                    ( void ) UclALPhyMailboxASR_Impl_Hw_Read( pInst, &pInst->rxShMemBufferAddr, MAILBOX_SHARDMEMORY_MSG_QUE_IDX );

                    ( void ) UclALPhyMailboxASR_Impl_Hw_Read( pInst, &pInst->txShMemBuffeAddr, MAILBOX_SHARDMEMORY_MSG_QUE_IDX );

                    pInst->pTxShMemBuffer = ( uint8 * ) pInst->txShMemBuffeAddr;
                    pInst->pRxShMemBuffer = ( uint8 * ) pInst->rxShMemBufferAddr;

                    ( void ) UclALPhyMailboxASR_Impl_Hw_SetDriverState ( pInst, MAILBOX_READY_ST );

                    for ( uint8 i = 0U; i < pInst->numIUclALPhyCbk; i++ )
                    {
                        UclALPhyCbk_PeerReadyStatusChanged ( pInst->pIUclALPhyCbk[i], eUclALPhyPeerReadyStatus_Ready );
                    }

                    //Start Driver State Check Timer
                    ( void ) UclALOs_TimerStart ( 0U, pInst->driverStateChkTimerTaskId, MAILBOX_DRIVER_STATE_CHECK_TIME_MS );
                }
            }
            break;

            case MAILBOX_READY_ST:
            {
                pInst->remoteDriverState = UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState ( pInst );
                if ( MAILBOX_READY_ST ==  pInst->remoteDriverState )
                {
                    UclALPhyMailboxASR_Impl_Transfer( pInst );
                }
            }
            break;

            case MAILBOX_ERROR_ST:
            {
                ( void ) UclALPhyMailboxASR_Impl_Hw_SetDriverState ( pInst, MAILBOX_INIT_ST );
            }
            break;

            default:
            break;
        }
    }

    return NULL;
}

static void UclALPhyMailboxASR_Impl_Transfer ( SUclALPhyMailboxASRInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    ///Receive
    if( MAILBOX_MESSAGE_STATUS_EMPTY != UclALPhyMailboxASR_Impl_Hw_MsgStatus( pInst, MAILBOX_RECEIVE_MSG_QUE_IDX ) )
    {
        uint32 recvDataSize = MAILBOX_DATA_SIZE_MIN;
        Ret = UclALPhyMailboxASR_Impl_Hw_Read( pInst, &recvDataSize, MAILBOX_RECEIVE_MSG_QUE_IDX );

        if( ( UCL_E_OK == Ret ) && ( MAILBOX_DATA_SIZE_MIN < recvDataSize ) )
        {
            if ( UCL_E_OK == UclALOs_MutexLock ( 0U, pInst->rxRingBufferMutexId ) )
            {
                Ret = UclCmnRingBuffer_Write ( &pInst->rxRingBuffer, pInst->pRxShMemBuffer, ( uint16 ) recvDataSize );
                ( void ) UclALOs_MutexUnlock ( 0U, pInst->rxRingBufferMutexId );
            }
        }
    }

    ///Transfer
    if( MAILBOX_MESSAGE_STATUS_EMPTY == UclALPhyMailboxASR_Impl_Hw_MsgStatus ( pInst, MAILBOX_TRASMIT_MSG_QUE_IDX ) )
    {
        uint16 TxSize = MAILBOX_BUFFER_MAX_SIZE;
        if ( UCL_E_OK == UclALOs_MutexLock ( 0U, pInst->txRingBufferMutexId ) )
        {
            Ret = UclCmnRingBuffer_Read ( &pInst->txRingBuffer, pInst->pTxShMemBuffer, &TxSize );
            ( void ) UclALOs_MutexUnlock ( 0U, pInst->txRingBufferMutexId );
        }

        if ( ( MAILBOX_DATA_SIZE_MIN < TxSize ) && ( UCL_E_OK == Ret ) )
        {
            ( void ) UclALPhyMailboxASR_Impl_Hw_Write(pInst, ( uint32 ) TxSize, MAILBOX_TRASMIT_MSG_QUE_IDX );
        }
    }

}

static Ucl_ReturnType UclALPhyMailboxASR_Impl_Hw_Open ( SUclALPhyMailboxASRInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;
    
    ( void ) pInst;

    return Ret;
}

static Ucl_ReturnType UclALPhyMailboxASR_Impl_Hw_Close ( SUclALPhyMailboxASRInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;
    
    ( void ) pInst;

    return Ret;
}

static Ucl_ReturnType UclALPhyMailboxASR_Impl_Hw_SetDriverState ( SUclALPhyMailboxASRInst *pInst, uint8 state )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    pInst->driverState = state;
    Ret = UclALPhyMailboxASR_Impl_Hw_Write( pInst, ( uint32 ) state, MAILBOX_DRIVER_STATUS_MSG_QUE_IDX );

    return Ret;
}

static uint8 UclALPhyMailboxASR_Impl_Hw_GetRemoteDriverState ( SUclALPhyMailboxASRInst *pInst )
{
    uint32 RemoteState = pInst->remoteDriverState;

    ( void ) UclALPhyMailboxASR_Impl_Hw_Read( pInst, &RemoteState, MAILBOX_REMOTE_DRIVER_STATUS_MSG_QUE_IDX );

    return ( uint8 ) RemoteState;
}

static Ucl_ReturnType UclALPhyMailboxASR_Impl_Hw_Write ( SUclALPhyMailboxASRInst *pInst, uint32 data, uint8 queueId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    uint32 fifoStatus = MAILBOX_REG_RD( pInst->pCfg->mailboxBaseAddress + MAILBOX_FIFOSTATUS_REG( queueId ) );

    if( MAILBOX_FIFO_STATUS_EMPTY == fifoStatus )
    {
        MAILBOX_REG_WR( ( pInst->pCfg->mailboxBaseAddress + MAILBOX_MESSAGE_REG( queueId ) ), data );
        Ret = UCL_E_OK;
    }

    return Ret;
}

static Ucl_ReturnType UclALPhyMailboxASR_Impl_Hw_Read ( SUclALPhyMailboxASRInst *pInst, uint32 *pData, uint8 queueId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if(  NULL != pData )
    {
        uint32 msgLen =  MAILBOX_REG_RD( pInst->pCfg->mailboxBaseAddress + MAILBOX_MSGSTATUS_REG( queueId ) );

        if( MAILBOX_MESSAGE_STATUS_EMPTY != msgLen)
        {
            *pData = MAILBOX_REG_RD( pInst->pCfg->mailboxBaseAddress + MAILBOX_MESSAGE_REG( queueId ) );
            Ret = UCL_E_OK;
        }
    }

    return Ret;
}

static uint8 UclALPhyMailboxASR_Impl_Hw_MsgStatus ( SUclALPhyMailboxASRInst *pInst, uint8 queueId)
{
    uint32 MsgStatus = MAILBOX_REG_RD(pInst->pCfg->mailboxBaseAddress + MAILBOX_MSGSTATUS_REG(queueId));

    return ( uint8 ) MsgStatus;
}
