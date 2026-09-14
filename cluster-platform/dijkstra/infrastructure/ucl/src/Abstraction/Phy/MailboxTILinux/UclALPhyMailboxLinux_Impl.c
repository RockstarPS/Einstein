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
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "UclALPhyMailboxLinux_Impl.h"
#include "UclCmnRingBuffer.h"
#include "UclALPhyCbk.h"
#include "UclALDebug.h"
#include "UclALOs.h"

#define MAILBOX_DRIVER_STATE_CHECK_TIME_MS        50U

/// Mailbox Driver States
#define MAILBOX_INIT_ST     0U
#define MAILBOX_SETUP_ST    1U
#define MAILBOX_READY_ST    2U
#define MAILBOX_ERROR_ST    3U
#define MAILBOX_INVALID_ST  4U

/// Mailbox message queue index
#define MAILBOX_REMOTE_DRIVER_STATUS_MSG_QUE_IDX   0U
#define MAILBOX_DRIVER_STATUS_MSG_QUE_IDX          1U
#define MAILBOX_SHARDMEMORY_MSG_QUE_IDX            2U
#define MAILBOX_RECEIVE_MSG_QUE_IDX                3U
#define MAILBOX_TRASMIT_MSG_QUE_IDX                4U

#define MAILBOX_MESSAGE_STATUS_EMPTY  0U
#define MAILBOX_FIFO_STATUS_EMPTY     0U

#define MAILBOX_BUFFER_MAX_SIZE      4096U
#define MAILBOX_DATA_SIZE_MIN        0U

static void *UclALPhyMailboxLinux_Impl_TimerTask ( void *pData );
static void *UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask ( void *pData );
static void UclALPhyMailboxLinux_Impl_Transfer ( SUclALPhyMailboxLinuxInst *pInst );
static Ucl_ReturnType UclALPhyMailboxLinux_Impl_Hw_Open ( SUclALPhyMailboxLinuxInst *pInst );
static Ucl_ReturnType UclALPhyMailboxLinux_Impl_Hw_Close ( SUclALPhyMailboxLinuxInst *pInst );
static Ucl_ReturnType UclALPhyMailboxLinux_Impl_Hw_Write ( SUclALPhyMailboxLinuxInst *pInst, uint32 data, uint8 queueId );
static Ucl_ReturnType UclALPhyMailboxLinux_Impl_Hw_Read ( SUclALPhyMailboxLinuxInst *pInst, uint32 *pData, uint8 queueId );
static Ucl_ReturnType UclALPhyMailboxLinux_Impl_Hw_SetDriverState ( SUclALPhyMailboxLinuxInst *pInst, uint8 state );
static uint8 UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState ( SUclALPhyMailboxLinuxInst *pInst );
static uint8 UclALPhyMailboxLinux_Impl_Hw_MsgStatus ( SUclALPhyMailboxLinuxInst *pInst, uint8 queueId );


Ucl_ReturnType UclALPhyMailboxLinux_Impl_IUclALPhy_Initialize ( SUclALPhyMailboxLinuxInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret;

    ( void ) InstId;

    Ret = UclALPhyMailboxLinux_Impl_Hw_Open ( pInst );

    if ( UCL_E_OK == Ret )
    {
        Ret = UclALPhyMailboxLinux_Impl_Hw_SetDriverState ( pInst, MAILBOX_INIT_ST );

        pInst->remoteDriverState = MAILBOX_INVALID_ST;
    }

    if ( UCL_E_OK == Ret )
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

    //Initialize TimerTask
    if ( UCL_E_OK == Ret )
    {
        Ret = UclALOs_TimerCreate ( 0U, &pInst->timerTaskId, UclALPhyMailboxLinux_Impl_TimerTask, ( void * ) pInst,
                        eUclOsTimerType_Periodic );
    }

    //Initialize Driver State Check Timer
    if ( UCL_E_OK == Ret )
    {
        Ret = UclALOs_TimerCreate ( 0U, &pInst->driverStateChkTimerTaskId, UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask, ( void * ) pInst,
                        eUclOsTimerType_Periodic );
    }

    //Start TimerTask
    if ( UCL_E_OK == Ret )
    {
        Ret = UclALOs_TimerStart ( 0U, pInst->timerTaskId, pInst->pCfg->periodicityMs );
    }

    if ( UCL_E_OK == Ret )
    {
        LOGI ( 0U, "UclALPhyMailboxLinux_Impl", "IUclALPhy_Initialize Success %d %d\n", pInst->timerTaskId,  pInst->driverStateChkTimerTaskId);
    }
    else
    {
        LOGE ( 0U, "UclALPhyMailboxLinux_Impl", "IUclALPhy_Initialize Failed %d\n", Ret  );
    }

    return Ret;
}

Ucl_ReturnType UclALPhyMailboxLinux_Impl_IUclALPhy_Shutdown ( SUclALPhyMailboxLinuxInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret = UCL_E_OK;

    ( void ) InstId;

    ( void ) UclALPhyMailboxLinux_Impl_Hw_Close ( pInst );

    ( void ) UclALOs_TimerStop ( 0U, pInst->timerTaskId );
    ( void ) UclALOs_TimerDestroy ( 0U, pInst->timerTaskId );
    ( void ) UclALOs_TimerStop ( 0U, pInst->driverStateChkTimerTaskId );
    ( void ) UclALOs_TimerDestroy ( 0U, pInst->driverStateChkTimerTaskId );

    ( void ) UclALOs_MutexDestroy ( 0U, pInst->txRingBufferMutexId );
    ( void ) UclALOs_MutexDestroy ( 0U, pInst->rxRingBufferMutexId );

    LOGI ( 0U, " UclALPhyMailboxLinux_Impl", "%s", "IUclALPhy_Shutdown Success\n" );

    return Ret;
}

Ucl_ReturnType UclALPhyMailboxLinux_Impl_IUclALPhy_Write ( SUclALPhyMailboxLinuxInst *pInst, uint8 InstId, uint8 *pData,
        uint16 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    ( void ) InstId;

    if ( ( NULL_PTR == pData ) || ( 0U == Size ) )
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else
    {
        if ( UCL_E_OK == UclALOs_MutexLock ( 0U, pInst->txRingBufferMutexId ) )
        {
            Ret = UclCmnRingBuffer_Write ( & ( pInst->txRingBuffer ), pData, Size );

            if ( UCL_E_BUFFER_FULL == Ret )
            {
                //TODO: Buffer full Handle Error
                LOGE ( 0U, "UclALPhyMuQnx_Impl", "IUclALPhy_Write No space to write %d\n", Size );
            }

            ( void ) UclALOs_MutexUnlock ( 0U, pInst->txRingBufferMutexId );
        }
    }

    return Ret;
}

Ucl_ReturnType UclALPhyMailboxLinux_Impl_IUclALPhy_Read ( SUclALPhyMailboxLinuxInst *pInst, uint8 InstId, uint8 *pData,
        uint16 *pSize )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    ( void ) InstId;

    if ( ( NULL_PTR == pData ) || ( NULL_PTR == pSize ) || ( 0U == *pSize ) )
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else
    {
        if ( UCL_E_OK == UclALOs_MutexLock ( 0U, pInst->rxRingBufferMutexId ) )
        {
            Ret = UclCmnRingBuffer_ReadFrame ( &pInst->rxRingBuffer, 0x0U, pData, pSize );

            ( void ) UclALOs_MutexUnlock ( 0U, pInst->rxRingBufferMutexId );
        }
    }

    return Ret;
}

static void *UclALPhyMailboxLinux_Impl_DriveStateCheckTimerTask ( void *pData )
{
    SUclALPhyMailboxLinuxInst *pInst = ( SUclALPhyMailboxLinuxInst * ) pData;

    if(NULL_PTR != pInst)
    {
        pInst->remoteDriverState = UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState ( pInst );

        //Stop Driver State Check Timer
        ( void ) UclALOs_TimerStop ( 0U, pInst->driverStateChkTimerTaskId );

        if ( ( MAILBOX_READY_ST != pInst->driverState ) || ( MAILBOX_READY_ST != pInst->remoteDriverState ) )
        {
            ( void ) UclALPhyMailboxLinux_Impl_Hw_SetDriverState ( pInst, MAILBOX_ERROR_ST );

            for ( uint8 i = 0U; i < pInst->numIUclALPhyCbk; i++ )
            {
                UclALPhyCbk_PeerReadyStatusChanged ( pInst->pIUclALPhyCbk[i], eUclALPhyPeerReadyStatus_NotReady );
            }
        }
    }

    return NULL_PTR;
}

static void *UclALPhyMailboxLinux_Impl_TimerTask ( void *pData )
{
    SUclALPhyMailboxLinuxInst *pInst = ( SUclALPhyMailboxLinuxInst * ) pData;

    if( NULL_PTR != pInst )
    {
        //Check States
        switch ( pInst->driverState )
        {
            case MAILBOX_INIT_ST:
            {
                pInst->remoteDriverState = UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState ( pInst );
                if ( MAILBOX_SETUP_ST == pInst->remoteDriverState )
                {
                    ( void ) UclALPhyMailboxLinux_Impl_Hw_Write ( pInst, ( uint32 ) pInst->pCfg->txShmMemPhyAddr, MAILBOX_SHARDMEMORY_MSG_QUE_IDX );
                    ( void ) UclALPhyMailboxLinux_Impl_Hw_Write ( pInst, ( uint32 ) pInst->pCfg->rxShmMemPhyAddr, MAILBOX_SHARDMEMORY_MSG_QUE_IDX );
                    ( void ) UclALPhyMailboxLinux_Impl_Hw_SetDriverState ( pInst, MAILBOX_SETUP_ST );

                    //Start Driver State Check Timer
                    ( void ) UclALOs_TimerStart ( 0U, pInst->driverStateChkTimerTaskId, MAILBOX_DRIVER_STATE_CHECK_TIME_MS );
                }
            }
            break;

            case MAILBOX_SETUP_ST:
            {
                pInst->remoteDriverState = UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState ( pInst );
                if ( MAILBOX_READY_ST == pInst->remoteDriverState )
                {
                    Ucl_ReturnType Ret;
                    Ret = UclALPhyMailboxLinux_Impl_Hw_SetDriverState ( pInst, MAILBOX_READY_ST );

                    if(UCL_E_OK == Ret)
                    {
                        LOGI ( 0U, "UclALPhyMailboxLinux_Impl", "%s", "Mailbox driver in Ready State\n" );

                        for ( uint8 i = 0U; i < pInst->numIUclALPhyCbk; i++ )
                        {
                            LOGI ( 0U, "UclALPhyMailboxLinux_Impl", "PeerReadyStatusChanged %d\n", i );
                            UclALPhyCbk_PeerReadyStatusChanged ( pInst->pIUclALPhyCbk[i], eUclALPhyPeerReadyStatus_Ready );
                        }
                    }
                    else
                    {
                        LOGE ( 0U, "UclALPhyMailboxLinux_Impl", "%s", "Mailbox driver not in Ready State\n" );
                    }
                }
            }
            break;

            case MAILBOX_READY_ST:
            {
                pInst->remoteDriverState = UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState ( pInst );
                if ( MAILBOX_READY_ST == pInst->remoteDriverState )
                {
                    UclALPhyMailboxLinux_Impl_Transfer( pInst );
                }
            }
            break;

            case MAILBOX_ERROR_ST:
            {
                ( void ) UclALPhyMailboxLinux_Impl_Hw_SetDriverState ( pInst, MAILBOX_INIT_ST );
                LOGE ( 0U, "UclALPhyMailboxLinux", "%s", "Mailbox driver in Error State. Set to INIT_ST\n" );
            }
            break;

            default:
            LOGE ( 0U, "UclALPhyMailboxLinux", "Invalid Mailbox driver State %d\n", pInst->driverState );
            break;
        }
    }

    return NULL_PTR;
}

static void UclALPhyMailboxLinux_Impl_Transfer ( SUclALPhyMailboxLinuxInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    ///Receive
    if( MAILBOX_MESSAGE_STATUS_EMPTY != UclALPhyMailboxLinux_Impl_Hw_MsgStatus ( pInst, MAILBOX_RECEIVE_MSG_QUE_IDX ) )
    {
        uint32 recvDataSize = MAILBOX_DATA_SIZE_MIN;
        Ret = UclALPhyMailboxLinux_Impl_Hw_Read ( pInst, &recvDataSize, MAILBOX_RECEIVE_MSG_QUE_IDX );

        if((UCL_E_OK == Ret) && (MAILBOX_DATA_SIZE_MIN < recvDataSize))
        {
            if ( UCL_E_OK == UclALOs_MutexLock ( 0U, pInst->rxRingBufferMutexId ) )
            {
                Ret = UclCmnRingBuffer_Write ( &pInst->rxRingBuffer, pInst->pRxShMemBuffer, ( uint16 ) recvDataSize );
                ( void ) UclALOs_MutexUnlock ( 0U, pInst->rxRingBufferMutexId );
            }
        }
    }

    ///Transfer
    ///To avoid overwrite there should be no data in the message queue
    if( MAILBOX_MESSAGE_STATUS_EMPTY == UclALPhyMailboxLinux_Impl_Hw_MsgStatus( pInst, MAILBOX_TRASMIT_MSG_QUE_IDX ) )
    {
        uint16 TxSize = MAILBOX_BUFFER_MAX_SIZE;
        if ( UCL_E_OK == UclALOs_MutexLock ( 0U, pInst->txRingBufferMutexId ) )
        {
            Ret = UclCmnRingBuffer_Read ( &pInst->txRingBuffer, pInst->pTxShMemBuffer, &TxSize );
            ( void ) UclALOs_MutexUnlock ( 0U, pInst->txRingBufferMutexId );
        }

        if ( ( MAILBOX_DATA_SIZE_MIN < TxSize ) && ( UCL_E_OK == Ret ) )
        {
            ( void ) UclALPhyMailboxLinux_Impl_Hw_Write ( pInst, ( uint32 ) TxSize, MAILBOX_TRASMIT_MSG_QUE_IDX );
        }
    }
}

static Ucl_ReturnType UclALPhyMailboxLinux_Impl_Hw_Open ( SUclALPhyMailboxLinuxInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;
    sint32 fd;

    fd = open( "/dev/mem", O_RDWR );

    if ( -1  == fd )
    {
        LOGE ( 0U, "UclALPhyMailboxLinux_Impl_Hw_Open", "%s", "Failed to open /dev/mem \n" );
        Ret = UCL_E_NOK;
    }
    else
    {
        pInst->pMailboxReg = ( sMailboxReg * ) mmap( NULL_PTR, getpagesize(), PROT_WRITE | PROT_READ, MAP_SHARED, fd, pInst->pCfg->mailboxBaseAddress );
        if ( MAP_FAILED == pInst->pMailboxReg )
        {
            LOGE ( 0U, "UclALPhyMailboxLinux_Impl_Hw_Open", "%s", "Failed to mmap /dev/mem \n" );
            Ret = UCL_E_NOK;
        }

        // Allocate Shared Memory for Transmit Buffer
        if ( UCL_E_OK == Ret )
        {
            pInst->pTxShMemBuffer = ( uint8 * ) mmap ( NULL_PTR, pInst->pCfg->txShmMemPhySize, PROT_WRITE | PROT_READ, MAP_SHARED, fd, pInst->pCfg->txShmMemPhyAddr );

            if ( MAP_FAILED == pInst->pTxShMemBuffer )
            {
                Ret = UCL_E_NOK;
                LOGE ( 0U, "UclALPhyMailboxLinux_Impl_Hw_Open", "%s", "pTxShMemBuffer mmap failed\n" );
            }
        }

        // Allocate Shared Memory for Receive Buffer
        if ( UCL_E_OK == Ret )
        {
            pInst->pRxShMemBuffer = ( uint8 * ) mmap ( NULL_PTR, pInst->pCfg->rxShmMemPhySize, PROT_WRITE | PROT_READ, MAP_SHARED, fd, pInst->pCfg->rxShmMemPhyAddr );

            if ( MAP_FAILED == pInst->pRxShMemBuffer )
            {
                Ret = UCL_E_NOK;
                LOGE ( 0U, "UclALPhyMailboxLinux_Impl_Hw_Open", "%s", "pRxShMemBuffer mmap failed\n" );
            }
        }

        ( void ) close ( fd );
    }

    return Ret;
}

static Ucl_ReturnType UclALPhyMailboxLinux_Impl_Hw_Close ( SUclALPhyMailboxLinuxInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;

    ( void ) munmap ( ( void * ) pInst->pRxShMemBuffer, pInst->pCfg->rxShmMemPhySize );
    ( void ) munmap ( ( void * ) pInst->pTxShMemBuffer, pInst->pCfg->txShmMemPhySize );
    ( void ) munmap ( ( void * ) pInst->pMailboxReg, getpagesize() );

    LOGI ( 0U, "UclALPhyMailboxLinux_Impl_Hw_Close", "%s", "HW closed Successfully \n" );

    return Ret;
}

static Ucl_ReturnType UclALPhyMailboxLinux_Impl_Hw_SetDriverState ( SUclALPhyMailboxLinuxInst *pInst, uint8 state )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    pInst->driverState = state;
    Ret = UclALPhyMailboxLinux_Impl_Hw_Write( pInst, (uint32) state, MAILBOX_DRIVER_STATUS_MSG_QUE_IDX );

    return Ret;
}

static uint8 UclALPhyMailboxLinux_Impl_Hw_GetRemoteDriverState ( SUclALPhyMailboxLinuxInst *pInst )
{
    uint32 RemoteState = pInst->remoteDriverState;

    ( void ) UclALPhyMailboxLinux_Impl_Hw_Read( pInst, &RemoteState, MAILBOX_REMOTE_DRIVER_STATUS_MSG_QUE_IDX );

    return (uint8) RemoteState;
}

static Ucl_ReturnType UclALPhyMailboxLinux_Impl_Hw_Write ( SUclALPhyMailboxLinuxInst *pInst, uint32 data, uint8 queueId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    uint32 fifoStatus = pInst->pMailboxReg->fifoStatus[queueId];

    if( MAILBOX_FIFO_STATUS_EMPTY == fifoStatus )
    {
        pInst->pMailboxReg->message[queueId] = data;
        Ret = UCL_E_OK;
    }

    return Ret;
}

static Ucl_ReturnType UclALPhyMailboxLinux_Impl_Hw_Read ( SUclALPhyMailboxLinuxInst *pInst, uint32 *pData, uint8 queueId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if( NULL_PTR != pData )
    {
        uint32 msgLen =  pInst->pMailboxReg->msgStatus[queueId];

        if( MAILBOX_MESSAGE_STATUS_EMPTY != msgLen )
        {
            *pData = pInst->pMailboxReg->message[queueId];
            Ret = UCL_E_OK;
        }
    }

    return Ret;
}

static uint8 UclALPhyMailboxLinux_Impl_Hw_MsgStatus ( SUclALPhyMailboxLinuxInst *pInst, uint8 queueId )
{
    uint32 MsgStatus = ( pInst->pMailboxReg->msgStatus[queueId] & 0xFFFU );

    return ( uint8 ) MsgStatus;
}
