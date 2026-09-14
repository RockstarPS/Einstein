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
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include "UclALPhySerialAndroid_Impl.h"
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
        Ret = UclALOs_MutexCreate ( 0u, &pInst->devFdMutexId );
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
        LOGI ( 0u, "UclALPhySerialAndroid_Impl_IUclALPhy_Initialize", "%s", "Success\n" );

        for ( i = 0u; i < pInst->numIUclALPhyCbk; i++ )
        {
            //TODO: Implement HW Flow Control
            UclALPhyCbk_PeerReadyStatusChanged ( pInst->pIUclALPhyCbk[i], eUclALPhyPeerReadyStatus_Ready );
        }
    }
    else
    {
        LOGE ( 0u, "UclALPhySerialAndroid_Impl_IUclALPhy_Initialize", "Failed %d\n", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown ( SUclALPhySerialPOSIXInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret;

    Ret = UclALPhySerialPOSIX_Impl_Hw_Close ( pInst );

    if ( UCL_E_OK == Ret )
    {
        ///< Sem post
        ( void ) UclALOs_TaskDestroy ( 0u, pInst->txTaskId );
        ( void ) UclALOs_TaskDestroy ( 0u, pInst->rxTaskId );
        ( void ) UclALOs_SemPost ( 0u, pInst->txSemId ); ///< wait for thread exit
        usleep(100000u);     //If the thread is waiting in poll() the kernel may delay thread exit until the syscall returns.
        ( void ) UclALOs_SemDestroy ( 0u, pInst->txSemId );
        ( void ) UclALOs_MutexDestroy ( 0u, pInst->txRingBufferMutexId );
        ( void ) UclALOs_MutexDestroy ( 0u, pInst->rxRingBufferMutexId );
        ( void ) UclALOs_MutexDestroy ( 0u, pInst->devFdMutexId );

        LOGI ( 0u, "UclALPhySerialAndroid_Impl_IUclALPhy_Shutdown", "%s", "Success\n" );
    }
    else
    {
        LOGE ( 0u, "UclALPhySerialAndroid_Impl_IUclALPhy_Shutdown", "Failed %d\n", Ret );
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
        LOGE ( 0u, "UclALPhySerialAndroid_Impl_IUclALPhy_Write", "Invalid Dev Fd for %s\n", pInst->pCfg->DeviceName );
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
                LOGE ( 0u, "UclALPhySerialAndroid_Impl_IUclALPhy_Write", "No space to write %d\n", Size );
            }
            else
            {
                LOGE ( 0u, "UclALPhySerialAndroid_Impl_IUclALPhy_Write", "Error %d\n", Ret );
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

    LOGI ( 0u, "UclALPhySerialAndroid_Impl_TransmitTask", "%s", "Begins\n" );


    while ( pInst->devFd >= 0 )
    {
        Ret = UclALOs_SemWait ( 0u, pInst->txSemId );

        if ( ( UCL_E_OK == Ret ) && (pInst->devFd >= 0))
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
                        LOGE ( 0u, "UclALPhySerialAndroid_Impl_TransmitTask", "Write Failed %d\n", Ret );
                    }
                }

                ( void ) usleep ( 500u );
            }
            while ( 0u < BytesRead );
        }
    }

    LOGI ( 0u, "UclALPhySerialAndroid_Impl_TransmitTask", "%s", "Exit\n" );

    return NULL_PTR;
}

void *UclALPhySerialPOSIX_Impl_ReceiveTask ( void *pData )
{
    SUclALPhySerialPOSIXInst *pInst = ( SUclALPhySerialPOSIXInst * ) pData;
    const SUclALPhySerialPOSIXCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret;
    uint16 BytesRead;
    uint8 i;

    LOGI ( 0u, "UclALPhySerialAndroid_Impl_ReceiveTask", "%s", "Begins\n" );

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

    LOGI ( 0u, "UclALPhySerialAndroid_Impl_ReceiveTask", "%s", "Exit\n" );

    return NULL_PTR;
}

static Ucl_ReturnType UclALPhySerialPOSIX_Impl_Hw_Open ( SUclALPhySerialPOSIXInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;
    struct termios oldtio, newtio;

    pInst->devFd = open ( pInst->pCfg->DeviceName, ( O_RDWR | O_NOCTTY | O_NONBLOCK ) );

    if ( pInst->devFd < 0 )
    {
        LOGE ( 0u, "UclALPhySerialAndroid_Impl_Hw_Initialize", "Cannot open %s\n", pInst->pCfg->DeviceName );
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
        newtio.c_iflag &= ~ICRNL;
        newtio.c_oflag = 0u;

        /* set input mode (non-canonical, no echo,...) */
        newtio.c_lflag = 0u;

        newtio.c_cc[VTIME] = 0u; /* inter-character timer 100ms */
        newtio.c_cc[VMIN] = 1u;  /* blocking read until a char received */

        ( void ) cfsetospeed ( &newtio, ( speed_t ) pInst->pCfg->BaudRate ); // 115200 baud
        ( void ) cfsetispeed ( &newtio, ( speed_t ) pInst->pCfg->BaudRate ); // 115200 baud

        ( void ) tcflush ( pInst->devFd, TCIFLUSH );
        ( void ) tcsetattr ( pInst->devFd, TCSANOW, &newtio );

        LOGI ( 0u, "UclALPhySerialAndroid_Impl_Hw_Initialize", "Device %s opened\n", pInst->pCfg->DeviceName );
    }

    return Ret;
}

static Ucl_ReturnType UclALPhySerialPOSIX_Impl_Hw_Close ( SUclALPhySerialPOSIXInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;
    if (UCL_E_OK == UclALOs_MutexLock(0u, pInst->devFdMutexId))
    {
        if ( pInst->devFd >= 0 )
        {
            if ( 0 != close ( pInst->devFd ) )
            {
                Ret = UCL_E_NOK;
                LOGE ( 0u, "UclALPhySerialAndroid_Impl_Hw_Close", "Device %s close failed\n", pInst->pCfg->DeviceName );
            }
            else
            {
                LOGI ( 0u, "UclALPhySerialAndroid_Impl_Hw_Close", "Device %s closed\n", pInst->pCfg->DeviceName );
            }
            pInst->devFd = -1;
        }
        else
        {
            LOGE ( 0u, "UclALPhySerialAndroid_Impl_Hw_Close", "Device %s already closed\n", pInst->pCfg->DeviceName );
        }
        ( void ) UclALOs_MutexUnlock(0u, pInst->devFdMutexId);
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
            LOGE ( 0u, "UclALPhySerialAndroid_Impl_Hw_Write", "%s", "Write Failed\n" );
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
static Ucl_ReturnType UclALPhySerialPOSIX_Impl_Hw_Read(SUclALPhySerialPOSIXInst *pInst, uint8 *pData, uint16 *pSize)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    struct pollfd pfd;
    sint32 res = 0;
    sint32 BytesRead = 0;
    sint32 readDevFd = -1;
    const sint32 pollTimeoutMs = 4; // Set timeout to 4 milliseconds

    // Validate input parameters
    if ((NULL_PTR == pData) || (NULL_PTR == pSize) || (0u == *pSize))
    {
        LOGE(0u, "UclALPhySerialAndroid_Impl_Hw_Read", "%s", "Invalid arguments (pData, pSize or *pSize is NULL/zero)\n");
        Ret = UCL_E_INVALID_ARGS;
    }
    else
    {
        // Acquire mutex to safely get the file descriptor
        if (UCL_E_OK == UclALOs_MutexLock(0u, pInst->devFdMutexId))
        {
            readDevFd = pInst->devFd;
            (void)UclALOs_MutexUnlock(0u, pInst->devFdMutexId);
        }
        else
        {
            LOGE(0u, "UclALPhySerialAndroid_Impl_Hw_Read", "%s", "Failed to acquire mutex for devFd\n");
            readDevFd = -1;
        }

        // Check if the device file descriptor is valid
        if (readDevFd < 0)
        {
            LOGE(0u, "UclALPhySerialAndroid_Impl_Hw_Read", "%s", "Invalid device file descriptor\n");
        }
        else
        {
            // Initialize the pollfd structure for the file descriptor
            pfd.fd = readDevFd;
            pfd.events = POLLIN;

            // Call poll with the 4ms timeout
            res = poll(&pfd, 1, pollTimeoutMs);

            if (res > 0)
            {
                if (pfd.revents & POLLIN)
                {
                    BytesRead = read(readDevFd, pData, *pSize);

                    if (BytesRead > 0)
                    {
                        *pSize = (uint16)BytesRead;
                        Ret = UCL_E_OK;
                    }
                    else if (BytesRead == 0)
                    {
                        LOGE(0u, "UclALPhySerialAndroid_Impl_Hw_Read", "%s", "Read returned 0 bytes (EOF?)\n");
                    }
                    else
                    {
                        if ((errno == EAGAIN) || (errno == EWOULDBLOCK))
                        {
                            LOGI(0u, "UclALPhySerialAndroid_Impl_Hw_Read", "Read returned EAGAIN/EWOULDBLOCK after poll. errno: %d\n", errno);
                        }
                        else
                        {
                            LOGI(0u, "UclALPhySerialAndroid_Impl_Hw_Read", "Read Failed with errno: %d\n", errno);
                        }
                    }
                }
                else
                {
                    LOGE(0u, "UclALPhySerialAndroid_Impl_Hw_Read", "Poll returned positive but POLLIN not set. revents: %x\n", pfd.revents);
                }
            }
            else if (res < 0)
            {
                // Poll error
                LOGE(0u, "UclALPhySerialAndroid_Impl_Hw_Read", "Poll Failed with errno: %d\n", errno);
            }
        }
    }

    return Ret;
}

