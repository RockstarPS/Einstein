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
#include <sys/types.h>
#include <sys/select.h>
#include <termios.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include "UclALPhySerialPOSIX_Impl.h"
#include "UclCmnRingBuffer.h"
#include "UclALPhyCbk.h"
#include "UclALDebug.h"
#include "UclALOs.h"

void *UclALPhySerialPOSIX_Impl_TransmitTask ( void *pData );
void *UclALPhySerialPOSIX_Impl_ReceiveTask ( void *pData );

static Ucl_ReturnType UclALPhySerialPOSIX_Impl_Hw_Open ( SUclALPhySerialPOSIXInst *pInst );
static Ucl_ReturnType UclALPhySerialPOSIX_Impl_Hw_Close ( SUclALPhySerialPOSIXInst *pInst );
static Ucl_ReturnType UclALPhySerialPOSIX_Impl_Hw_Write ( SUclALPhySerialPOSIXInst *pInst, uint8 *pData, uint16 Size );
static Ucl_ReturnType UclALPhySerialPOSIX_Impl_Hw_Read ( SUclALPhySerialPOSIXInst *pInst, uint8 *pData, uint16 *pSize );

Ucl_ReturnType UclALPhySerialPOSIX_Impl_IUclALPhy_Initialize ( SUclALPhySerialPOSIXInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret;
    uint8 i;

    Ret = UclALPhySerialPOSIX_Impl_Hw_Open ( pInst );

    if ( Ret == UCL_E_OK )
    {
        Ret = UclCmnRingBuffer_Initialize ( &pInst->txRingBuffer, pInst->pCfg->pTxRingBuffer, pInst->pCfg->txRingBufferSize );
    }

    if ( Ret == UCL_E_OK )
    {
        Ret = UclCmnRingBuffer_Initialize ( &pInst->rxRingBuffer, pInst->pCfg->pRxRingBuffer, pInst->pCfg->rxRingBufferSize );
    }

    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_MutexCreate ( 0u, &pInst->txRingBufferMutexId );
    }

    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_MutexCreate ( 0u, &pInst->rxRingBufferMutexId );
    }

    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_SemCreate ( 0u, &pInst->txSemId, 1u );
    }

    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TaskCreate ( 0u, &pInst->txTaskId, UclALPhySerialPOSIX_Impl_TransmitTask, ( void * ) pInst );
    }

    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TaskCreate ( 0u, &pInst->rxTaskId, UclALPhySerialPOSIX_Impl_ReceiveTask, ( void * ) pInst );
    }

    if ( UCL_E_OK == Ret )
    {
        LOGI ( 0u, "UclALPhySerialPOSIX_Impl_IUclALPhy_Initialize", "%s", "Success\n" );

        for ( i = 0u; i < pInst->numIUclALPhyCbk; i++ )
        {
            //TODO: Implement HW Flow Control
            UclALPhyCbk_PeerReadyStatusChanged ( pInst->pIUclALPhyCbk[i], eUclALPhyPeerReadyStatus_Ready );
        }
    }
    else
    {
        LOGE ( 0u, "UclALPhySerialPOSIX_Impl_IUclALPhy_Initialize", "Failed %d\n", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown ( SUclALPhySerialPOSIXInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret;

    Ret = UclALPhySerialPOSIX_Impl_Hw_Close ( pInst );

    if ( UCL_E_OK == Ret )
    {
        ( void ) UclALOs_SemDestroy ( 0u, pInst->txSemId );
        ( void ) UclALOs_MutexDestroy ( 0u, pInst->txRingBufferMutexId );
        ( void ) UclALOs_MutexDestroy ( 0u, pInst->rxRingBufferMutexId );
        ( void ) UclALOs_TaskDestroy ( 0u, pInst->txTaskId );
        ( void ) UclALOs_TaskDestroy ( 0u, pInst->rxTaskId );

        LOGI ( 0u, "UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown", "%s", "Success\n" );
    }
    else
    {
        LOGE ( 0u, "UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown", "Failed %d\n", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALPhySerialPOSIX_Impl_IUclALPhy_Write ( SUclALPhySerialPOSIXInst *pInst, uint8 InstId, uint8 *pData,
        uint16 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( ( NULL_PTR == pData ) || ( 0u == Size ) )
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else if ( 0 > pInst->devFd )
    {
        LOGE ( 0u, "UclALPhySerialPOSIX_Impl_IUclALPhy_Write", "Invalid Dev Fd for %s\n", pInst->pCfg->DeviceName );
    }
    else
    {
        if ( UCL_E_OK == UclALOs_MutexLock ( 0u, pInst->txRingBufferMutexId ) )
        {
            Ret = UclCmnRingBuffer_Write ( &pInst->txRingBuffer, pData, Size );

            ( void ) UclALOs_MutexUnlock ( 0u, pInst->txRingBufferMutexId );

            if ( UCL_E_OK == Ret )
            {
                ( void ) UclALOs_SemPost ( 0u, pInst->txSemId );
            }
            else if ( UCL_E_BUFFER_FULL == Ret )
            {
                UclALPhyCbk_FatalError ( pInst->pIUclALPhyCbk[0], UCL_E_BUFFER_FULL );
                LOGE ( 0u, "UclALPhySerialPOSIX_Impl_IUclALPhy_Write", "No space to write %d\n", Size );
            }
            else
            {
                LOGE ( 0u, "UclALPhySerialPOSIX_Impl_IUclALPhy_Write", "Error %d\n", Ret );
            }
        }
    }

    return Ret;
}

Ucl_ReturnType UclALPhySerialPOSIX_Impl_IUclALPhy_Read ( SUclALPhySerialPOSIXInst *pInst, uint8 InstId, uint8 *pData,
        uint16 *pSize )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( ( NULL_PTR == pData ) || ( NULL_PTR == pSize ) || ( 0u == *pSize ) )
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else
    {
        if ( UCL_E_OK == UclALOs_MutexLock ( 0u, pInst->rxRingBufferMutexId ) )
        {
            Ret = UclCmnRingBuffer_ReadFrame ( &pInst->rxRingBuffer, 0x0u, pData, pSize );

            ( void ) UclALOs_MutexUnlock ( 0u, pInst->rxRingBufferMutexId );
        }
    }

    return Ret;
}

void *UclALPhySerialPOSIX_Impl_TransmitTask ( void *pData )
{
    SUclALPhySerialPOSIXInst *pInst = ( SUclALPhySerialPOSIXInst * ) pData;
    const SUclALPhySerialPOSIXCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret;
    uint16 BytesRead;

    LOGI ( 0u, "UclALPhySerialPOSIX_Impl_TransmitTask", "%s", "Begins\n" );

	pthread_setcancelstate( PTHREAD_CANCEL_ENABLE, NULL );
	pthread_setcanceltype( PTHREAD_CANCEL_ASYNCHRONOUS, NULL );

    while ( pInst->devFd >= 0 )
    {
        Ret = UclALOs_SemWait ( 0u, pInst->txSemId );

        if ( UCL_E_OK == Ret )
        {
            do
            {
                BytesRead = pCfg->txDmaBufferSize;

                ( void ) UclALOs_Memset ( 0u, pCfg->pTxDmaBuffer, 0u, pCfg->txDmaBufferSize );

                Ret = UclALOs_MutexLock ( 0u, pInst->txRingBufferMutexId );

                if ( UCL_E_OK == Ret )
                {
                    Ret = UclCmnRingBuffer_Read ( &pInst->txRingBuffer, pCfg->pTxDmaBuffer, &BytesRead );

                    ( void ) UclALOs_MutexUnlock ( 0u, pInst->txRingBufferMutexId );
                }

                if ( 0u < BytesRead )
                {
                    if ( UCL_E_OK == Ret )
                    {
                        Ret = UclALPhySerialPOSIX_Impl_Hw_Write ( pInst, pCfg->pTxDmaBuffer, BytesRead );
                    }

                    if ( UCL_E_OK != Ret )
                    {
                        LOGE ( 0u, "UclALPhySerialPOSIX_Impl_TransmitTask", "Write Failed %d\n", Ret );
                    }
                }

                ( void ) usleep ( 500u );
            }
            while ( 0u < BytesRead );
        }
    }

    LOGI ( 0u, "UclALPhySerialPOSIX_Impl_TransmitTask", "%s", "Exit\n" );

    return NULL_PTR;
}

void *UclALPhySerialPOSIX_Impl_ReceiveTask ( void *pData )
{
    SUclALPhySerialPOSIXInst *pInst = ( SUclALPhySerialPOSIXInst * ) pData;
    const SUclALPhySerialPOSIXCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret;
    uint16 BytesRead;
    uint8 i;

    LOGI ( 0u, "UclALPhySerialPOSIX_Impl_ReceiveTask", "%s", "Begins\n" );

	pthread_setcancelstate( PTHREAD_CANCEL_ENABLE, NULL );
	pthread_setcanceltype( PTHREAD_CANCEL_ASYNCHRONOUS, NULL );

    while ( pInst->devFd >= 0 )
    {
        ( void ) UclALOs_Memset ( 0u, pCfg->pRxDmaBuffer, 0u, pCfg->rxDmaBufferSize );

        BytesRead = pCfg->rxDmaBufferSize;

        Ret = UclALPhySerialPOSIX_Impl_Hw_Read ( pInst, pCfg->pRxDmaBuffer, &BytesRead );

        if ( UCL_E_OK == Ret )
        {
            Ret = UclALOs_MutexLock ( 0u, pInst->rxRingBufferMutexId );
        }

        if ( UCL_E_OK == Ret )
        {
            Ret = UclCmnRingBuffer_Write ( &pInst->rxRingBuffer, pCfg->pRxDmaBuffer, BytesRead );

            ( void ) UclALOs_MutexUnlock ( 0u, pInst->rxRingBufferMutexId );
        }

        if ( UCL_E_OK == Ret )
        {
            for ( i = 0u; i < pInst->numIUclALPhyCbk; i++ )
            {
                UclALPhyCbk_ReceiveDataAvailable ( pInst->pIUclALPhyCbk[i] );
            }
        }
    }

    LOGI ( 0u, "UclALPhySerialPOSIX_Impl_ReceiveTask", "%s", "Exit\n" );

    return NULL_PTR;
}

static Ucl_ReturnType UclALPhySerialPOSIX_Impl_Hw_Open ( SUclALPhySerialPOSIXInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;
    struct termios oldtio, newtio;

    pInst->devFd = open ( pInst->pCfg->DeviceName, ( O_RDWR | O_NOCTTY | O_NONBLOCK ) );

    if ( pInst->devFd < 0 )
    {
        LOGE ( 0u, "UclALPhySerialPOSIX_Impl_Hw_Initialize", "Cannot open %s\n", pInst->pCfg->DeviceName );
        Ret = UCL_E_NOK;
    }
    else
    {
        ( void ) tcgetattr ( pInst->devFd, &oldtio ); /* save current port settings */

        ( void ) UclALOs_Memset ( 0u, &newtio, 0u, (uint32)sizeof ( newtio ) );

        if ( TRUE == pInst->pCfg->HwFlowCtrlOn )
        {
#ifdef CRTSCTS
            newtio.c_cflag = CS8 | CLOCAL | CRTSCTS | CREAD;
#else
            newtio.c_cflag = CS8 | CLOCAL | IHFLOW | OHFLOW | CREAD;
#endif
        }
        else
        {
            newtio.c_cflag = CS8 | CLOCAL | CREAD;
        }

        newtio.c_iflag = IGNPAR;
        newtio.c_oflag = 0u;

        /* set input mode (non-canonical, no echo,...) */
        newtio.c_lflag = 0u;

        newtio.c_cc[VTIME] = 0u; /* inter-character timer 100ms */
        newtio.c_cc[VMIN] = 1u;  /* blocking read until a char received */

        ( void ) cfsetospeed ( &newtio, ( speed_t ) pInst->pCfg->BaudRate ); // 115200 baud
        ( void ) cfsetispeed ( &newtio, ( speed_t ) pInst->pCfg->BaudRate ); // 115200 baud

        ( void ) tcflush ( pInst->devFd, TCIFLUSH );
        ( void ) tcsetattr ( pInst->devFd, TCSANOW, &newtio );

        LOGI ( 0u, "UclALPhySerialPOSIX_Impl_Hw_Initialize", "Device %s opened\n", pInst->pCfg->DeviceName );
    }

    return Ret;
}

static Ucl_ReturnType UclALPhySerialPOSIX_Impl_Hw_Close ( SUclALPhySerialPOSIXInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;

    if ( pInst->devFd >= 0 )
    {
        if ( 0 != close ( pInst->devFd ) )
        {
            Ret = UCL_E_NOK;
            LOGE ( 0u, "UclALPhySerialPOSIX_Impl_Hw_Close", "Device %s close failed\n", pInst->pCfg->DeviceName );
        }
        else
        {
            LOGI ( 0u, "UclALPhySerialPOSIX_Impl_Hw_Close", "Device %s closed\n", pInst->pCfg->DeviceName );
        }
        pInst->devFd = -1;
    }
    else
    {
        LOGE ( 0u, "UclALPhySerialPOSIX_Impl_Hw_Close", "Device %s already closed\n", pInst->pCfg->DeviceName );
    }

    return Ret;
}

static Ucl_ReturnType UclALPhySerialPOSIX_Impl_Hw_Write ( SUclALPhySerialPOSIXInst *pInst, uint8 *pData, uint16 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint16 BytesSent;
    sint32 BytesWrote;

    BytesSent = 0;

    do
    {
        BytesWrote = write ( pInst->devFd, &pData[BytesSent], ( Size - BytesSent ) );

        if ( BytesWrote < 0 )
        {
            LOGE ( 0u, "UclALPhySerialPOSIX_Impl_Hw_Write", "%s", "Write Failed\n" );
            break;
        }

        BytesSent += ( uint16 ) BytesWrote;
    }
    while ( BytesSent < Size );

    if ( BytesSent == Size )
    {
        Ret = UCL_E_OK;
    }

    return Ret;
}

static Ucl_ReturnType UclALPhySerialPOSIX_Impl_Hw_Read ( SUclALPhySerialPOSIXInst *pInst, uint8 *pData, uint16 *pSize )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    fd_set readfd;
    sint32 res;
    struct timeval timeout;
    sint32 BytesRead;

    FD_ZERO ( &readfd );
    FD_SET ( pInst->devFd, &readfd );

    timeout.tv_usec = 100000; /* 100 milliseconds */
    timeout.tv_sec = 0;       /* seconds */

    res = select ( pInst->devFd + 1, &readfd, NULL_PTR, NULL_PTR, &timeout );

    if ( res > 0 )
    {
        if ( FD_ISSET ( pInst->devFd, &readfd ) != 0 )
        {
            BytesRead = read ( pInst->devFd, pData, *pSize );

            if ( 0 < BytesRead )
            {
                *pSize = ( ( uint16 ) BytesRead );
                Ret = UCL_E_OK;
            }
        }
    }

    return Ret;
}
