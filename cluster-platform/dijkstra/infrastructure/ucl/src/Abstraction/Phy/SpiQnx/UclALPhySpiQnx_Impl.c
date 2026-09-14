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
#include <hw/spi-master.h>
#include <spi_client.h>
#include <gpio_client.h>
#include "UclALPhySpiQnx_Impl.h"
#include "UclCmnRingBuffer.h"
#include "UclALPhyCbk.h"
#include "UclALDebug.h"
#include "UclALOs.h"

#define DEBUG   (0U)

#ifndef LOW
    #define LOW (0U)
#endif
#ifndef HIGH
    #define HIGH (1U)
#endif
#define MSB_FIRST (1U)
#define LSB_FIRST (0U)
#define SPI_LEN_BYTES_SIZE  (2U)
#define SPI_MIN_FRAME_LEN  (8U)
#define SPI_MIN_TIME_GAP_MS (2U)
#define ROUND_TO_4BYTE(n) (((n) + 3U) & 0xFFFCU)

static void *UclALPhySpiQnx_Impl_TimerTask ( void *pData );
static Ucl_ReturnType UclALPhySpiQnx_Impl_Hw_SpiOpen ( SUclALPhySpiQnxInst *pInst );
static Ucl_ReturnType UclALPhySpiQnx_Impl_Hw_SpiClose ( SUclALPhySpiQnxInst *pInst );
static Ucl_ReturnType UclALPhySpiQnx_Impl_Hw_SpiTransfer ( SUclALPhySpiQnxInst *pInst );
static uint8 UclALPhySpiQnx_Impl_Hw_GpioRead ( SUclALPhySpiQnxInst *pInst );

Ucl_ReturnType UclALPhySpiQnx_Impl_IUclALPhy_Initialize ( SUclALPhySpiQnxInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i = 0;

    Ret = UclALPhySpiQnx_Impl_Hw_SpiOpen ( pInst );

    if ( Ret != UCL_E_OK )
    {
        LOGE ( 0, "UclALPhySpiQnx_Impl", "UclALPhySpiQnx_Impl_HwSpiOpen Failed %d\n", Ret );
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
	
	if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_MutexCreate ( 0, &pInst->spiChMutexId );
    }

    //Initialize TimerTask
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TimerCreate ( 0, &pInst->timerTaskId, UclALPhySpiQnx_Impl_TimerTask, ( void * ) pInst,
                        eUclOsTimerType_Periodic );
    }

    //Start TimerTask
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TimerStart ( 0, pInst->timerTaskId, pInst->pCfg->periodicityMs );
    }

    if ( UCL_E_OK == Ret )
    {
        // Initialize DMA buffers
        ( void ) UclALOs_Memset ( 0, ( void * ) ( pInst->pCfg->pTxDmaBuffer ), 0, pInst->pCfg->txDmaBufferSize );
        ( void ) UclALOs_Memset ( 0, ( void * ) ( pInst->pCfg->pRxDmaBuffer ), 0, pInst->pCfg->rxDmaBufferSize );

        LOGI ( 0, "UclALPhySpiQnx_Impl", "%s", "IUclALPhy_Initialize Success\n" );

        for ( i = 0; i < pInst->numIUclALPhyCbk; i++ )
        {
            //TODO: Implement HW Flow Control
            UclALPhyCbk_PeerReadyStatusChanged ( pInst->pIUclALPhyCbk[i], eUclALPhyPeerReadyStatus_Ready );
        }
    }
    else
    {
        LOGE ( 0, "UclALPhySpiQnx_Impl", "IUclALPhy_Initialize Failed %d\n", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALPhySpiQnx_Impl_IUclALPhy_Shutdown ( SUclALPhySpiQnxInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret;
	
	if ( UCL_E_OK == UclALOs_MutexLock ( 0, pInst->spiChMutexId ) )
	{
		Ret = UclALPhySpiQnx_Impl_Hw_SpiClose ( pInst );
		pInst->spiFd = -1;
		pInst->gpioFd = -1;
		( void ) UclALOs_MutexUnlock ( 0, pInst->spiChMutexId );
	}

    if ( UCL_E_OK == Ret )
    {
        ( void ) UclALOs_TimerStop ( 0, pInst->timerTaskId );
        ( void ) UclALOs_TimerDestroy ( 0, pInst->timerTaskId );
		( void ) UclALOs_MutexDestroy ( 0, pInst->txRingBufferMutexId );
        ( void ) UclALOs_MutexDestroy ( 0, pInst->rxRingBufferMutexId );
		( void ) UclALOs_MutexDestroy ( 0, pInst->spiChMutexId );


        LOGI ( 0, "UclALPhySpiQnx_Impl", "%s", "IUclALPhy_Shutdown Success\n" );
    }
    else
    {
        LOGE ( 0, "UclALPhySpiQnx_Impl", "IUclALPhy_Shutdown Failed %d\n", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALPhySpiQnx_Impl_IUclALPhy_Write ( SUclALPhySpiQnxInst *pInst, uint8 InstId, uint8 *pData, uint16 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( ( NULL_PTR == pData ) || ( 0u == Size ) )
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else if ( 0 > pInst->spiFd )
    {
        LOGE ( 0, "UclALPhySpiQnx_Impl", "IUclALPhy_Write Invalid Dev Fd for %s\n", pInst->pCfg->pDevicePath );
    }
    else
    {
        if ( UCL_E_OK == UclALOs_MutexLock ( 0, pInst->txRingBufferMutexId ) )
        {
            Ret = UclCmnRingBuffer_Write ( & ( pInst->txRingBuffer ), pData, Size );

            if ( UCL_E_NOK == Ret )
            {
                //TODO: Buffer full Handle Error
                LOGE ( 0, "UclALPhySpiQnx_Impl", "IUclALPhy_Write No space to write %d\n", Size );
            }

            ( void ) UclALOs_MutexUnlock ( 0, pInst->txRingBufferMutexId );
        }
    }

    return Ret;
}

Ucl_ReturnType UclALPhySpiQnx_Impl_IUclALPhy_Read ( SUclALPhySpiQnxInst *pInst, uint8 InstId, uint8 *pData, uint16 *pSize )
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

static void *UclALPhySpiQnx_Impl_TimerTask ( void *pData )
{
    SUclALPhySpiQnxInst *pInst = ( SUclALPhySpiQnxInst * ) pData;
    uint64 getTime = UclALOs_GetSystemTimeMs ( 0 ); //misra_violation: time shall not be declared.

    if ( SPI_MIN_TIME_GAP_MS < ( getTime - pInst->lastXchgTime ) )
    {
		
		if ( UCL_E_OK == UclALOs_MutexLock ( 0, pInst->spiChMutexId ) )
		{
			// Perform transfer
			( void ) UclALPhySpiQnx_Impl_Hw_SpiTransfer ( pInst );
			pInst->lastXchgTime = UclALOs_GetSystemTimeMs ( 0 );
			( void ) UclALOs_MutexUnlock ( 0, pInst->spiChMutexId );
		}
    }

    return NULL_PTR;
}

static Ucl_ReturnType UclALPhySpiQnx_Impl_Hw_SpiOpen ( SUclALPhySpiQnxInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;
    spi_cfg_t SpiCfg = { 0x0 };
    uint32_t value = 0x0u;
    sint32 SpiStatus;
    sint32 GpioStatus = -1;

    if ( pInst->pCfg->gpioNum >= 0 )
    {
        pInst->gpioFd = gpio_open ( pInst->pCfg->pGpioDevicePath );

        if ( pInst->gpioFd >= 0 )
        {
            if ( gpio_get_pin ( pInst->gpioFd, ( uint32_t ) pInst->pCfg->gpioNum, &value ) == GPIO_SUCCESS )
            {
                GpioStatus = 0x0;
                LOGI ( 0, "UclALPhySpiQnx_Impl_Hw_SpiOpen", "Intial Gpio status %d\n", value );
            }
            else
            {
                LOGE ( 0, "UclALPhySpiQnx_Impl_Hw_SpiOpen", "Cannot open Gpio : Port Number %d\n", pInst->pCfg->gpioNum );
            }
        }

        else
        {
            LOGE ( 0, "UclALPhySpiQnx_Impl_Hw_SpiOpen", "Cannot open Gpio %s\n", pInst->pCfg->pGpioDevicePath );
        }
    }

    else
    {
        GpioStatus = 0x0;

    }

    pInst->spiFd = spi_open ( pInst->pCfg->pDevicePath );

    if ( ( 0 > pInst->spiFd ) && ( GpioStatus == 0x0 ) ) //Cov: "0 > pInst->spiFd && (GpioStatus = 0)" is always false regardless of the values of its operands. This occurs as the logical operand of "if".

    {
        LOGE ( 0, "UclALPhySpiQnx_Impl_Hw_SpiOpen", "Cannot open %s\n", pInst->pCfg->pDevicePath );
        Ret = UCL_E_NOK;
    }
    else
    {
        SpiCfg.clock_rate = pInst->pCfg->speedHz;

        if ( pInst->pCfg->bitFormat == MSB_FIRST )
        {
            SpiCfg.mode |= ( ( uint32 ) SPI_MODE_BODER_MSB );
        }

        else
        {
            SpiCfg.mode = ( ( SpiCfg.mode ) & ( ~ ( ( uint32 ) SPI_MODE_BODER_MSB ) ) );
        }

        SpiCfg.mode |= ( ( ( uint32 ) pInst->pCfg->bitsPerWord ) & SPI_MODE_CHAR_LEN_MASK );

        if ( pInst->pCfg->slaveSelectPolarity == HIGH )
        {
            SpiCfg.mode |= ( ( uint32 ) SPI_MODE_CSPOL_MASK );
        }
        else
        {
            SpiCfg.mode = ( ( SpiCfg.mode ) & ( ~ ( ( uint32 ) SPI_MODE_CSPOL_MASK ) ) );
            //SpiCfg.mode = ((SpiCfg.mode) & ((uint32) (~(SPI_MODE_CSPOL_MASK))));// Cov: integer conversion resulted in truncation
        }

        SpiCfg.mode |= ( ( ( uint32 ) pInst->pCfg->spiMode << 8 ) & 0x0300u );
		SpiCfg.mode |= ( ( ( uint32 ) pInst->pCfg->slaveSelectDfltLevel << 12 ) & 0x03000u );
		
		LOGI(0, "UclALPhySpiQnx_Impl_Hw_SpiOpen", "SPI_MODE =  %x", SpiCfg.mode);
        SpiStatus = spi_setcfg ( pInst->spiFd, SPI_DEV_DEFAULT, &SpiCfg );

        if ( SpiStatus != EOK )
        {
            Ret = UCL_E_NOK;

        }

    }

    return Ret;
}

static Ucl_ReturnType UclALPhySpiQnx_Impl_Hw_SpiClose ( SUclALPhySpiQnxInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;
    sint32 SpiStatus = 0x0;
    sint32 gpioStatus = 0x0;

    SpiStatus = spi_close ( pInst->spiFd );

    if ( ( pInst->pCfg->gpioNum >= 0 ) && ( pInst->pCfg->pGpioDevicePath != NULL_PTR ) )
    {
        gpioStatus = gpio_close ( pInst->pCfg->pGpioDevicePath );

        if ( gpioStatus == 0x0 ) // if gpio closed sucessfully
        {
            LOGI ( 0, "UclALPhySpiQnx_Impl_Hw_SpiClose", "%s", "Gpio is closed " );
        }
    }

    if ( ( SpiStatus < 0 ) || ( gpioStatus < 0 ) )
    {
        Ret = UCL_E_NOK;
    }

    return Ret;
}

static Ucl_ReturnType UclALPhySpiQnx_Impl_Hw_SpiTransfer ( SUclALPhySpiQnxInst *pInst )
{

    Ucl_ReturnType Ret = UCL_E_OK;
    uint16 TransferSize = 0;
    uint16 TxSize = 0;
    uint16 RxSize = 0;
    sint32 Status = 0;
    uint32 SlaveTimeout;

    if ( 0 > pInst->spiFd )
    {
        LOGE ( 0, "UclALPhySpiQnx_Impl", "%s", "Hw_Transfer: Invalid FD" );
        Ret = UCL_E_NOK;
    }

    if ( pInst->pCfg->gpioNum >= 0 )
    {
        if ( HIGH == UclALPhySpiQnx_Impl_Hw_GpioRead ( pInst ) )
        {
            LOGE ( 0, "UclALPhySpiQnx_Impl", "%s", "Slave not ready" );
            Ret = UCL_E_NOK;
        }
    }

    // Read data to transmit
    if ( Ret == UCL_E_OK )
    {
        ( void ) UclALOs_Memset ( 0, ( void * ) ( pInst->pCfg->pTxDmaBuffer ), 0, pInst->pCfg->txDmaBufferSize );
        ( void ) UclALOs_Memset ( 0, ( void * ) ( pInst->pCfg->pRxDmaBuffer ), 0, pInst->pCfg->rxDmaBufferSize );

        TxSize = pInst->pCfg->txDmaBufferSize - SPI_LEN_BYTES_SIZE;

        if ( UCL_E_OK == UclALOs_MutexLock ( 0, pInst->txRingBufferMutexId ) )
        {
            Ret = UclCmnRingBuffer_Read ( &pInst->txRingBuffer, &pInst->pCfg->pTxDmaBuffer[SPI_LEN_BYTES_SIZE],
                            &TxSize );

            ( void ) UclALOs_MutexUnlock ( 0, pInst->txRingBufferMutexId );
        }

        if ( ( 0u < TxSize ) && ( UCL_E_OK == Ret ) )
        {
            pInst->pCfg->pTxDmaBuffer[0] = ( uint8 ) ( TxSize >> 8 );
            pInst->pCfg->pTxDmaBuffer[1] = ( uint8 ) ( TxSize & 0x00FFU );
        }
        else if ( ( 0u == TxSize ) && ( UCL_E_NOK == Ret ) )
        {
            Ret = UCL_E_OK;
        }
        else
        {
            //Do Nothing
        }
    }

    // Negotiate transfer length
    if ( Ret == UCL_E_OK )
    {

        Status = spi_xchange ( pInst->spiFd, SPI_DEV_DEFAULT, &pInst->pCfg->pTxDmaBuffer[0],
                        &pInst->pCfg->pRxDmaBuffer[0], ( sint32 ) SPI_MIN_FRAME_LEN );

        if ( 0 > Status )
        {
            LOGE ( 0, "UclALPhySpiQnx_Impl", "Hw_Transfer: Get length SPI transfer failed %d", Status );
            Ret = UCL_E_NOK;
        }
        else
        {
            RxSize = ( ( ( ( uint16 ) pInst->pCfg->pRxDmaBuffer[0] ) << 8 )
                            | ( ( uint16 ) ( pInst->pCfg->pRxDmaBuffer[1] ) ) );

            if ( RxSize <= ( pInst->pCfg->rxDmaBufferSize - SPI_LEN_BYTES_SIZE ) )
            {
                if ( TxSize > RxSize )
                {
                    TransferSize = TxSize;
                }
                else
                {
                    TransferSize = RxSize;
                }
            }
            else
            {
                LOGE ( 0, "UclALPhySpiQnx_Impl", "Hw_Transfer: Invalid Rx Size %d\n", RxSize );
                Ret = UCL_E_NOK;
            }
        }

    }

    //LOGI(0, "UclALPhySpiQnx_Impl", "RxSize, TxSize : %d, %d\n", RxSize, TxSize);

    if ( ( UCL_E_OK == Ret ) && ( 0u < TransferSize ) )
    {
        if ( TransferSize <= ( SPI_MIN_FRAME_LEN - SPI_LEN_BYTES_SIZE ) )
        {
            if ( ( UCL_E_OK == UclALOs_MutexLock ( 0, pInst->rxRingBufferMutexId ) ) && ( RxSize > ( uint16 ) 0u ) )
            {
                Ret = UclCmnRingBuffer_Write ( &pInst->rxRingBuffer, &pInst->pCfg->pRxDmaBuffer[SPI_LEN_BYTES_SIZE], RxSize );
                ( void ) UclALOs_MutexUnlock ( 0, pInst->rxRingBufferMutexId );
            }

            if ( Ret != UCL_E_OK )
            {
                LOGI ( 0, "UclALPhySpiQnx_Impl", "%s", "Copy to Rx Ring buffer:failed" );
            }
        }
        else
        {
            TransferSize = ROUND_TO_4BYTE ( TransferSize - ( SPI_MIN_FRAME_LEN - SPI_LEN_BYTES_SIZE ) );

            if ( TransferSize < SPI_MIN_FRAME_LEN )
            {
                TransferSize = SPI_MIN_FRAME_LEN;
            }

            if ( pInst->pCfg->gpioNum >= 0 )
            {
                SlaveTimeout = 2000u; //500ms wait time // sleep time 250uS

                while ( ( LOW == UclALPhySpiQnx_Impl_Hw_GpioRead ( pInst ) ) && ( SlaveTimeout > 0u ) )
                {
                    ( void ) usleep ( 250u ); //Cov: Calling "usleep" without checking return value
                    SlaveTimeout--;
                }

                if ( 0u == SlaveTimeout )
                {
                    LOGE ( 0, "UclALPhySpiQnx_Impl", "%s", "Slave timeout during data transfer" );
                    Ret = UCL_E_NOK;
                }
            }
            else
            {
                ( void ) usleep ( 500 ); //Cov: Calling "usleep" without checking return value
            }

            if ( UCL_E_OK == Ret )
            {
                Status = spi_xchange ( pInst->spiFd, SPI_DEV_DEFAULT, & ( pInst->pCfg->pTxDmaBuffer[SPI_MIN_FRAME_LEN] ),
                                & ( pInst->pCfg->pRxDmaBuffer[SPI_MIN_FRAME_LEN] ), ( sint32 ) TransferSize );

                if ( 0 > Status )
                {
                    LOGI ( 0, "UclALPhySpiQnx_Impl", "%s", "Hw_Transfer: data transfer failed" );
                    Ret = UCL_E_NOK;
                }
                else
                {
#if DEBUG
                    LOGI ( 0, "UclALPhySpiQnx_Impl", "Hw_Transfer: received %d bytes", RxSize );

                    if ( RxSize > 0 )
                    {
                        LOGI ( 0, "UclALPhySpiQnx_Impl", "%d %d %d %d %d %d %d %d", pInst->pCfg->pRxDmaBuffer[0], pInst->pCfg->pRxDmaBuffer[1], pInst->pCfg->pRxDmaBuffer[2], pInst->pCfg->pRxDmaBuffer[3], pInst->pCfg->pRxDmaBuffer[4], pInst->pCfg->pRxDmaBuffer[5], pInst->pCfg->pRxDmaBuffer[6], pInst->pCfg->pRxDmaBuffer[7] );
                    }

                    if ( RxSize > 7 )
                    {
                        LOGI ( 0, "UclALPhySpiQnx_Impl", "%d %d %d %d %d %d %d %d", pInst->pCfg->pRxDmaBuffer[8], pInst->pCfg->pRxDmaBuffer[9], pInst->pCfg->pRxDmaBuffer[10], pInst->pCfg->pRxDmaBuffer[11], pInst->pCfg->pRxDmaBuffer[12], pInst->pCfg->pRxDmaBuffer[13], pInst->pCfg->pRxDmaBuffer[14], pInst->pCfg->pRxDmaBuffer[15] );
                    }

                    if ( RxSize > 15 )
                    {
                        LOGI ( 0, "UclALPhySpiQnx_Impl", "%d %d %d %d %d %d %d %d", pInst->pCfg->pRxDmaBuffer[16], pInst->pCfg->pRxDmaBuffer[17], pInst->pCfg->pRxDmaBuffer[18], pInst->pCfg->pRxDmaBuffer[19], pInst->pCfg->pRxDmaBuffer[20], pInst->pCfg->pRxDmaBuffer[21], pInst->pCfg->pRxDmaBuffer[22], pInst->pCfg->pRxDmaBuffer[23] );
                    }

                    if ( RxSize > 23 )
                    {
                        LOGI ( 0, "UclALPhySpiQnx_Impl", "%d %d %d %d %d %d %d %d", pInst->pCfg->pRxDmaBuffer[24], pInst->pCfg->pRxDmaBuffer[25], pInst->pCfg->pRxDmaBuffer[26], pInst->pCfg->pRxDmaBuffer[27], pInst->pCfg->pRxDmaBuffer[28], pInst->pCfg->pRxDmaBuffer[29], pInst->pCfg->pRxDmaBuffer[30], pInst->pCfg->pRxDmaBuffer[31] );
                    }

                    if ( RxSize > 31 )
                    {
                        LOGI ( 0, "UclALPhySpiQnx_Impl", "%d %d %d %d %d %d %d %d", pInst->pCfg->pRxDmaBuffer[32], pInst->pCfg->pRxDmaBuffer[33], pInst->pCfg->pRxDmaBuffer[34], pInst->pCfg->pRxDmaBuffer[35] );
                    }

#endif

                    if ( UCL_E_OK == UclALOs_MutexLock ( 0, pInst->rxRingBufferMutexId ) )
                    {
                        Ret = UclCmnRingBuffer_Write ( &pInst->rxRingBuffer, &pInst->pCfg->pRxDmaBuffer[SPI_LEN_BYTES_SIZE], RxSize );
                        ( void ) UclALOs_MutexUnlock ( 0, pInst->rxRingBufferMutexId );
                    }

                    if ( Ret != UCL_E_OK )
                    {
                        LOGI ( 0, "UclALPhySpiQnx_Impl", "%s", "Copy to Rx Ring buffer:failed" );
                    }
                }
            }

        }
    }

    return Ret;
}

static uint8 UclALPhySpiQnx_Impl_Hw_GpioRead ( SUclALPhySpiQnxInst *pInst )
{
    uint8 portVal = 0X0;
    uint32_t value; //misra_violation: The object pointer expression &value of type uint32 * is cast to type uint32_t *.

    if ( pInst->gpioFd >= 0 )
    {
        if ( gpio_get_pin ( pInst->gpioFd, pInst->pCfg->gpioNum, &value ) == GPIO_SUCCESS )
        {
            portVal = ( uint8 ) value;
        }
        else
        {
            LOGE ( 0, "UclALPhySpiQnx_Impl", "%s", "GPIO_SUCCESS_get_pin:failed" );
        }
    }

    return portVal;
}
