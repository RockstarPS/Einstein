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
#include "SpiS.h"
#include "UclALPhySpiASR_Impl.h"
#include "UclALPhyCbk.h"
#include "UclALDebug.h"
#include "UclALOs.h"
#include "Dio.h"

#define SPI_MODE_INTERRUPT		((uint8)1u)
#define SPI_MODE_DMA			((uint8)2u)

#define SPI_SEND_LEN 0
#define SPI_SEND_DATA 1

#define SPI_LEN_BYTES_SIZE 2u
#define SPI_MIN_FRAME_LEN  8u
#define ROUND_TO_4BYTE(n) ((n + 3u) & 0xFFFCu)

#define VIP_FLOW_CTRL_LENGTH_READY(GPIO)       Dio_WriteChannel( GPIO, (Dio_LevelType) STD_LOW )
#define VIP_FLOW_CTRL_DATA_READY(GPIO)         Dio_WriteChannel( GPIO, (Dio_LevelType) STD_HIGH )

static Ucl_ReturnType UclALPhySpiASR_Impl_SetupLength ( SUclALPhySpiASRInst *pInst );
static Ucl_ReturnType UclALPhySpiASR_Impl_SetupData ( SUclALPhySpiASRInst *pInst );

Ucl_ReturnType UclALPhySpiASR_Impl_IUclALPhy_Initialize ( SUclALPhySpiASRInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    pInst->dataTransferPhase = SPI_SEND_LEN;
    pInst->peerReadyState = eUclALPhyPeerReadyStatus_NotReady;

    // Initialize ring buffers
    Ret = UclCmnRingBuffer_Initialize ( &pInst->txRingBuffer, pInst->pCfg->pTxRingBuffer,
                    pInst->pCfg->txRingBufferSize );

    if ( UCL_E_OK == Ret )
    {
        Ret = UclCmnRingBuffer_Initialize ( &pInst->rxRingBuffer, pInst->pCfg->pRxRingBuffer,
                        pInst->pCfg->rxRingBufferSize );
    }

    if ( UCL_E_OK == Ret )
    {
        // Check Driver Status
        if ( eSpiSDrvStatus_Uninit != SpiS_GetStatus() )
        {
            Ret = SpiS_EnableChn ( pInst->pCfg->channelId );
        }
        else
        {
			LOGE ( 0, "UclALPhySpiASR_Impl", "%s", "IUclALPhy_Initialize: SpiDrv_GetStatus return not ready" );
			Ret = UCL_E_NOK;
        }
    }

    if ( UCL_E_OK == Ret )
    {
        Ret = UclALPhySpiASR_Impl_SetupLength ( pInst );
    }

    if ( UCL_E_OK == Ret )
    {
        LOGI ( 0, "UclALPhySpiASR_Impl", "%s", "IUclALPhy_Initialize: Success" );
    }
    else
    {
        LOGE ( 0, "UclALPhySpiASR_Impl", "IUclALPhy_Initialize: Failed %d", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALPhySpiASR_Impl_IUclALPhy_Shutdown ( SUclALPhySpiASRInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    pInst->dataTransferPhase = SPI_SEND_LEN;
    pInst->peerReadyState = eUclALPhyPeerReadyStatus_NotReady;

    Ret = SpiS_DisableChn ( pInst->pCfg->channelId );

    return Ret;
}

Ucl_ReturnType UclALPhySpiASR_Impl_IUclALPhy_Write ( SUclALPhySpiASRInst *pInst, uint8 InstId, uint8 *pData, uint16 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( ( NULL != pData ) && ( 0 < Size ) )
    {
        UclALOs_DisableAllInterrupts ( 0 );
        Ret = UclCmnRingBuffer_Write ( & ( pInst->txRingBuffer ), pData, Size );
        UclALOs_EnableAllInterrupts ( 0 );

        if ( UCL_E_BUFFER_FULL == Ret )
        {
            UclALPhyCbk_FatalError ( pInst->pIUclALPhyCbk[0], UCL_E_BUFFER_FULL );
        }
    }

    return Ret;
}

Ucl_ReturnType UclALPhySpiASR_Impl_IUclALPhy_Read ( SUclALPhySpiASRInst *pInst, uint8 InstId, uint8 *pData, uint16 *pSize )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( ( NULL != pData ) && ( NULL != pSize ) && ( 0 < *pSize ) )
    {
        UclALOs_DisableAllInterrupts ( 0 );
        Ret = UclCmnRingBuffer_ReadFrame ( &pInst->rxRingBuffer, 0x0, pData, pSize );
        UclALOs_EnableAllInterrupts ( 0 );
    }

    return Ret;
}

void UclALPhySpiASR_Impl_IUclALHwCbk_TransmitComplete ( SUclALPhySpiASRInst *pInst, uint8 InstId )
{
}

void UclALPhySpiASR_Impl_IUclALHwCbk_ReceiveComplete ( SUclALPhySpiASRInst *pInst, uint8 InstId )
{
    uint16 rxSize;

    if ( eSpiSChnStatus_Ok == SpiS_GetChnStatus ( pInst->pCfg->channelId ) )
    {
        if ( SPI_SEND_LEN == pInst->dataTransferPhase )
        {
            rxSize = ( uint16 ) ( ( uint16 ) pInst->pCfg->pRxDmaBuffer[0] << 8 | ( uint16 ) pInst->pCfg->pRxDmaBuffer[1] );

            if ( rxSize > 0 )
            {
                ( void ) UclCmnRingBuffer_Write ( &pInst->rxRingBuffer, &pInst->pCfg->pRxDmaBuffer[SPI_LEN_BYTES_SIZE], rxSize );
            }

            UclALPhySpiASR_Impl_SetupLength ( pInst );
        }
        else if ( SPI_SEND_DATA == pInst->dataTransferPhase )
        {
            UclALPhySpiASR_Impl_SetupData ( pInst );
        }
        else
        {
        }
    }
    else
    {
        UclALPhySpiASR_Impl_SetupLength ( pInst );
    }
}

void UclALPhySpiASR_Impl_IUclALHwCbk_GpioChanged ( SUclALPhySpiASRInst *pInst, uint8 InstId, uint16 GpioId )
{
    //Unused
}

static Ucl_ReturnType UclALPhySpiASR_Impl_SetupLength ( SUclALPhySpiASRInst *pInst )
{
    uint16 Size = 0;

    ( void ) UclALOs_Memset ( 0, ( void * ) ( pInst->pCfg->pTxDmaBuffer ), 0, pInst->pCfg->txDmaBufferSize );
    ( void ) UclALOs_Memset ( 0, ( void * ) ( pInst->pCfg->pRxDmaBuffer ), 0, pInst->pCfg->rxDmaBufferSize );

    Size = pInst->pCfg->txDmaBufferSize - SPI_LEN_BYTES_SIZE;
    ( void ) UclCmnRingBuffer_Read ( &pInst->txRingBuffer, &pInst->pCfg->pTxDmaBuffer[SPI_LEN_BYTES_SIZE], &Size );

    pInst->pCfg->pTxDmaBuffer[0] = ( uint8 ) ( ( Size & ( uint16 ) ( 0xFF00 ) ) >> 8 );
    pInst->pCfg->pTxDmaBuffer[1] = ( uint8 ) ( Size & ( uint16 ) ( 0x00FF ) );

 	if ( pInst->pCfg->spiMode == SPI_MODE_DMA )
	{
		( void ) SpiS_AsyncMode ( pInst->pCfg->channelId, eSpiSAsyncMode_Dma );
	}
	else if ( pInst->pCfg->spiMode == SPI_MODE_INTERRUPT )
	{
		( void ) SpiS_AsyncMode ( pInst->pCfg->channelId, eSpiSAsyncMode_Interrupt );
	}
	else
	{
		//Set Default Mode to interrupt Mode
		( void ) SpiS_AsyncMode ( pInst->pCfg->channelId, eSpiSAsyncMode_Interrupt );
	}
	
    if ( E_OK == SpiS_SetupEB ( pInst->pCfg->channelId, pInst->pCfg->pTxDmaBuffer, pInst->pCfg->pRxDmaBuffer, SPI_MIN_FRAME_LEN ) )
    {
        if ( E_OK == SpiS_AsyncTransmit ( pInst->pCfg->channelId ) )
        {
            pInst->dataTransferPhase = SPI_SEND_DATA;
        }
    }

    // Indicate master that length is ready
    if ( pInst->pCfg->gpio >= 0u )
    {
        VIP_FLOW_CTRL_LENGTH_READY ( pInst->pCfg->gpio );
    }

    return UCL_E_OK;
}

static Ucl_ReturnType UclALPhySpiASR_Impl_SetupData ( SUclALPhySpiASRInst *pInst )
{
    uint16 txSize, rxSize, xferSize = 0;

    txSize = ( uint16 ) ( ( uint16 ) pInst->pCfg->pTxDmaBuffer[0] << 8 | ( uint16 ) pInst->pCfg->pTxDmaBuffer[1] );
    rxSize = ( uint16 ) ( ( uint16 ) pInst->pCfg->pRxDmaBuffer[0] << 8 | ( uint16 ) pInst->pCfg->pRxDmaBuffer[1] );

    if ( rxSize <= pInst->pCfg->rxDmaBufferSize )
    {
        if ( txSize > rxSize )
        {
            xferSize = txSize;
        }
        else
        {
            xferSize = rxSize;
        }

        // Started getting pings. Master is up
        if ( eUclALPhyPeerReadyStatus_NotReady == pInst->peerReadyState )
        {
            pInst->peerReadyState = eUclALPhyPeerReadyStatus_Ready;
            UclALPhyCbk_PeerReadyStatusChanged ( pInst->pIUclALPhyCbk[0], eUclALPhyPeerReadyStatus_Ready );
        }
    }

    if ( ( xferSize > 0 ) && ( xferSize <= ( pInst->pCfg->rxDmaBufferSize - SPI_LEN_BYTES_SIZE ) ) )
    {
        if ( xferSize <= ( SPI_MIN_FRAME_LEN - SPI_LEN_BYTES_SIZE ) )
        {
            rxSize = ( uint16 ) ( ( uint16 ) pInst->pCfg->pRxDmaBuffer[0] << 8 | ( uint16 ) pInst->pCfg->pRxDmaBuffer[1] );

            if ( rxSize > 0 )
            {
                ( void ) UclCmnRingBuffer_Write ( &pInst->rxRingBuffer, &pInst->pCfg->pRxDmaBuffer[SPI_LEN_BYTES_SIZE], rxSize );
            }

            UclALPhySpiASR_Impl_SetupLength ( pInst );
        }
        else
        {
            xferSize = ROUND_TO_4BYTE ( ( xferSize - ( SPI_MIN_FRAME_LEN - SPI_LEN_BYTES_SIZE ) ) );

            if ( xferSize < SPI_MIN_FRAME_LEN )
            {
                xferSize = SPI_MIN_FRAME_LEN;
            }

			//Set SPI Mode
            if ( pInst->pCfg->spiMode == SPI_MODE_DMA )
			{
				( void ) SpiS_AsyncMode ( pInst->pCfg->channelId, eSpiSAsyncMode_Dma );
			}
			else if ( pInst->pCfg->spiMode == SPI_MODE_INTERRUPT )
			{
				( void ) SpiS_AsyncMode ( pInst->pCfg->channelId, eSpiSAsyncMode_Interrupt );
			}
			else
			{
				//Set Default Mode to Interrupt Mode
				( void ) SpiS_AsyncMode ( pInst->pCfg->channelId, eSpiSAsyncMode_Interrupt );
			}
			
            if ( E_OK == SpiS_SetupEB ( pInst->pCfg->channelId, &pInst->pCfg->pTxDmaBuffer[SPI_MIN_FRAME_LEN],
                            &pInst->pCfg->pRxDmaBuffer[SPI_MIN_FRAME_LEN], xferSize ) )
            {
                if ( E_OK == SpiS_AsyncTransmit ( pInst->pCfg->channelId ) )
                {
                    pInst->dataTransferPhase = SPI_SEND_LEN;
                }
            }

            // Indicate master that data is ready
            if ( pInst->pCfg->gpio >= 0u )
            {
                VIP_FLOW_CTRL_DATA_READY ( pInst->pCfg->gpio );
            }
        }
    }
    else
    {
        UclALPhySpiASR_Impl_SetupLength ( pInst );
    }

    return UCL_E_OK;
}
