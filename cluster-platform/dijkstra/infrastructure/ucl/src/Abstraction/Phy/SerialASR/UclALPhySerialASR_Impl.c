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

#include "SciDrv.h"
#include "UclCmnRingBuffer.h"
#include "UclALPhyCbk.h"
#include "UclALOs.h"
#include "UclALDebug.h"
#include "SciDrv_Cfg.h"
#include "UclALPhySerialASR_Impl.h"

#define SCI_DRV_MODE_INT 0u
#define SCI_DRV_MODE_DMA 1u

static Ucl_ReturnType UclALPhySerialASR_Impl_SetupTransmit ( SUclALPhySerialASRInst *pInst );
static Ucl_ReturnType UclALPhySerialASR_Impl_SetupReceive ( SUclALPhySerialASRInst *pInst );
static Ucl_ReturnType UclALPhySerialASR_Impl_ReadData ( SUclALPhySerialASRInst *pInst, uint32 Count );
static void *UclALPhySerialASR_Impl_TimerTask ( void *pData );
Ucl_ReturnType UclALPhySerialASR_Impl_IUclALPhy_Initialize ( SUclALPhySerialASRInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    pInst->peerReadyState = eUclALPhyPeerReadyStatus_NotReady;

    // Initialize ring buffers
    Ret = UclCmnRingBuffer_Initialize ( &pInst->txRingBuffer, pInst->pCfg->pTxRingBuffer, pInst->pCfg->txRingBufferSize );

    if ( UCL_E_OK == Ret )
    {
        Ret = UclCmnRingBuffer_Initialize ( &pInst->rxRingBuffer, pInst->pCfg->pRxRingBuffer, pInst->pCfg->rxRingBufferSize );
    }

    if ( UCL_E_OK == Ret )
    {
        // Initialize DMA buffers
        ( void ) UclALOs_Memset ( 0, ( void * ) ( pInst->pCfg->pTxDmaBuffer ), 0, pInst->pCfg->txDmaBufferSize );
        ( void ) UclALOs_Memset ( 0, ( void * ) ( pInst->pCfg->pRxDmaBuffer ), 0, pInst->pCfg->rxDmaBufferSize );

        // Check Driver Status
        if ( eSciDrvStatus_Ready == SciDrv_GetStatus() )
        {
            if(SciDrv_EnableChn( pInst->pCfg->channelId ) != E_OK )
            {
                Ret = UCL_E_NOK;
            }
        }
        else
        {
            LOGE ( 0, "UclALPhySerialASR_Impl", "%s", "IUclALPhy_Initialize: SciDrv_GetStatus Not Initialized" );
            Ret = UCL_E_NOK;
        }
    }

    if ( UCL_E_OK == Ret )
    {
        // Set Async Mode as Interrupt / DMA
        if ( pInst->pCfg->enableDMA == SCI_DRV_MODE_INT )
        {
            if ( SciDrv_SetAsyncMode ( pInst->pCfg->channelId, eSciDrvAsyncMode_Interrupt ) != E_OK )
            {
                Ret = UCL_E_NOK;
            }
        }
        else if ( pInst->pCfg->enableDMA == SCI_DRV_MODE_DMA )
        {
            if(SciDrv_SetAsyncMode ( pInst->pCfg->channelId, eSciDrvAsyncMode_Dma )!= E_OK )
            {
                Ret = UCL_E_NOK;
            }
        }
        else
        {
            Ret = UCL_E_NOK;
        }
    }

    if ( UCL_E_OK == Ret )
    {
        Ret = UclALPhySerialASR_Impl_SetupReceive ( pInst );
    }
    if ( pInst->pCfg->periodicityMs != 0)  //SciDrv Timer for TVII Only
    {
        //Initialize TimerTask
        if ( Ret == UCL_E_OK )
        {
            Ret = UclALOs_TimerCreate ( 0, &pInst->timerTaskId, UclALPhySerialASR_Impl_TimerTask, ( void * ) pInst,
                                        eUclOsTimerType_Periodic );
        }

        //Start TimerTask
        if ( Ret == UCL_E_OK )
        {
            Ret = UclALOs_TimerStart ( 0, pInst->timerTaskId, pInst->pCfg->periodicityMs );
        }
    }
    if ( UCL_E_NOK == Ret )
    {
        LOGE ( 0, "UclALPhySerialASR_Impl", "IUclALPhy_Initialize: Failed %d", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALPhySerialASR_Impl_IUclALPhy_Shutdown ( SUclALPhySerialASRInst *pInst, uint8 InstId )
{
    //Cancel Receive
    ( void ) SciDrv_Cancel ( pInst->pCfg->channelId, eSciDrvDirection_Receive );

    //Cancel Transmit
    ( void ) SciDrv_Cancel ( pInst->pCfg->channelId, eSciDrvDirection_Transmit );

    //Disable Channel
    ( void ) SciDrv_DisableChn ( pInst->pCfg->channelId );

    //Destroy Timer
    ( void ) UclALOs_TimerStop ( 0, pInst->timerTaskId );
    ( void ) UclALOs_TimerDestroy ( 0, pInst->timerTaskId );

    return UCL_E_OK;
}

Ucl_ReturnType UclALPhySerialASR_Impl_IUclALPhy_Write ( SUclALPhySerialASRInst *pInst, uint8 InstId, uint8 *pData,
        uint16 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( ( NULL != pData ) && ( 0u < Size ) )
    {

        UclALOs_DisableAllInterrupts ( 0 );
        Ret = UclCmnRingBuffer_Write ( & ( pInst->txRingBuffer ), pData, Size );

        if ( pInst->pCfg->periodicityMs == 0)  //SetupTransmit for TVI only
        {
            if ( UCL_E_OK == Ret )
            {
                Ret = UclALPhySerialASR_Impl_SetupTransmit ( pInst );
            }
            else
            {
                UclALPhyCbk_FatalError ( pInst->pIUclALPhyCbk[0], UCL_E_BUFFER_FULL );
            }
        }

        ( void ) UclALOs_EnableAllInterrupts ( 0 );
    }

    return Ret;
}

Ucl_ReturnType UclALPhySerialASR_Impl_IUclALPhy_Read ( SUclALPhySerialASRInst *pInst, uint8 InstId, uint8 *pData,
        uint16 *pSize )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( ( NULL != pData ) && ( NULL != pSize ) && ( 0u < *pSize ) )
    {
        UclALOs_DisableAllInterrupts ( 0 );

        Ret = UclCmnRingBuffer_ReadFrame ( &pInst->rxRingBuffer, 0x0, pData, pSize );

        ( void ) UclALOs_EnableAllInterrupts ( 0 );
    }

    return Ret;
}

void UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete ( SUclALPhySerialASRInst *pInst, uint8 InstId )
{
    ESciDrvChnResult Result;

    Result = SciDrv_GetChnResult ( ( pInst->pCfg->channelId ), eSciDrvDirection_Transmit, NULL );

    if ( eSciDrvChnResult_Ok == Result )
    {
        if ( pInst->pCfg->periodicityMs == 0) //SetupTransmit after Every Tansmit Complete for TVI
        {
            ( void ) UclALPhySerialASR_Impl_SetupTransmit ( pInst );
        }
    }
    else
    {
        // TODO: Handle Error
    }
}

void UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete ( SUclALPhySerialASRInst *pInst, uint8 InstId )
{
    uint32 BytesRecvd = 0;
    ESciDrvChnResult Result;

    Result = SciDrv_GetChnResult ( ( pInst->pCfg->channelId ), eSciDrvDirection_Receive, &BytesRecvd );

    if ( eSciDrvChnResult_Ok == Result )
    {
        // Read the data into the ring buffer
        if ( BytesRecvd > 0u )
        {
            if ( pInst->pCfg->enableDMA == SCI_DRV_MODE_INT )
            {
                ( void ) UclCmnRingBuffer_Write ( &pInst->rxRingBuffer, pInst->pCfg->pRxDmaBuffer, BytesRecvd );
            }
            else if ( pInst->pCfg->enableDMA == SCI_DRV_MODE_DMA )
            {
                ( void ) UclALPhySerialASR_Impl_ReadData ( pInst, BytesRecvd );
            }
        }
        else
        {
            //Do Nothing
        }

        ( void ) UclALPhySerialASR_Impl_SetupReceive ( pInst );

        // Started getting pings. Master is up
        if ( eUclALPhyPeerReadyStatus_NotReady == pInst->peerReadyState )
        {
            pInst->peerReadyState = eUclALPhyPeerReadyStatus_Ready;

            UclALPhyCbk_PeerReadyStatusChanged ( pInst->pIUclALPhyCbk[0], eUclALPhyPeerReadyStatus_Ready );
        }

        UclALPhyCbk_ReceiveDataAvailable ( pInst->pIUclALPhyCbk[0] );
    }
    else
    {
        ( void ) UclALPhySerialASR_Impl_SetupReceive ( pInst );
        // TODO: Handle Error
    }
}

void UclALPhySerialASR_Impl_IUclALHwCbk_GpioChanged ( SUclALPhySerialASRInst *pInst, uint8 InstId, uint16 GpioId )
{
}

static void *UclALPhySerialASR_Impl_TimerTask ( void *pData )
{
    SUclALPhySerialASRInst *pInst = ( SUclALPhySerialASRInst * ) pData;
    if ( pInst->pCfg->periodicityMs != 0) //SetupTranmit once every TimerTask Call for TVII
    {
        UclALPhySerialASR_Impl_SetupTransmit ( pInst );
    }

    return NULL;
}


static Ucl_ReturnType UclALPhySerialASR_Impl_SetupTransmit ( SUclALPhySerialASRInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;
    uint16 Size = 0;
    uint8 bSend = TRUE;

    if ( pInst->pCfg->enableDMA == SCI_DRV_MODE_INT )
    {
        if ( eSciDrvChnResult_Busy == SciDrv_GetChnResult ( pInst->pCfg->channelId, eSciDrvDirection_Transmit, NULL ) )
        {
            bSend = FALSE;
        }
    }

    if ( bSend == TRUE )
    {
        ( void ) UclALOs_Memset ( 0, ( void * ) ( pInst->pCfg->pTxDmaBuffer ), 0x0, pInst->pCfg->txDmaBufferSize );

        Size = pInst->pCfg->txDmaBufferSize;

        Ret = UclCmnRingBuffer_Read ( &pInst->txRingBuffer, pInst->pCfg->pTxDmaBuffer, &Size );

        if ( ( Ret == UCL_E_OK ) && ( 0u < Size ) )
        {
            if ( pInst->pCfg->enableDMA == SCI_DRV_MODE_INT )
            {
                // Setup EB
                Ret = ( Ucl_ReturnType ) SciDrv_SetupEB ( pInst->pCfg->channelId, eSciDrvDirection_Transmit, pInst->pCfg->pTxDmaBuffer, Size );

                if ( Ret == UCL_E_OK )
                {
                    Ret = ( Ucl_ReturnType ) SciDrv_ASyncTransmit ( pInst->pCfg->channelId );
                }
            }
            else if ( pInst->pCfg->enableDMA == SCI_DRV_MODE_DMA )
            {
                // Setup IB
                Ret = ( Ucl_ReturnType ) SciDrv_WriteIB ( pInst->pCfg->channelId, eSciDrvDirection_Transmit, pInst->pCfg->pTxDmaBuffer, Size );
            }
        }
        else
        {
            //Do Nothing
        }
    }

    return Ret;
}

static Ucl_ReturnType UclALPhySerialASR_Impl_SetupReceive ( SUclALPhySerialASRInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Check if channel is busy
    if ( eSciDrvChnResult_Busy != SciDrv_GetChnResult ( pInst->pCfg->channelId, eSciDrvDirection_Receive, NULL ) )
    {
        if ( pInst->pCfg->enableDMA == SCI_DRV_MODE_INT )
        {
            ( void ) UclALOs_Memset ( 0, ( void * ) ( pInst->pCfg->pRxDmaBuffer ), 0x0, pInst->pCfg->rxDmaBufferSize );

            Ret = ( Ucl_ReturnType ) SciDrv_SetupEB ( pInst->pCfg->channelId, eSciDrvDirection_Receive, pInst->pCfg->pRxDmaBuffer,
                    pInst->pCfg->rxDmaBufferSize );
        }
        else if ( pInst->pCfg->enableDMA == SCI_DRV_MODE_DMA )
        {
            Ret = UCL_E_OK;
        }
        else
        {
            //Do Nothing
        }
    }

    // Trigger Receive
    if ( UCL_E_OK == Ret )
    {
        if ( SciDrv_ASyncReceive ( pInst->pCfg->channelId ) != E_OK)
        {
            Ret = UCL_E_NOK;
        }
    }

    return Ret;
}
static Ucl_ReturnType UclALPhySerialASR_Impl_ReadData ( SUclALPhySerialASRInst *pInst, uint32 Count )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint16 ReadCount = 0;

    /*Collect the rcvd data from SCI_RX_IB */
    while ( Count > 0u )
    {
        if ( Count > pInst->pCfg->rxDmaBufferSize )
        {
            ReadCount = pInst->pCfg->rxDmaBufferSize;
        }
        else
        {
            ReadCount = Count;
        }

        ( void ) UclALOs_Memset ( 0, ( void * ) ( pInst->pCfg->pRxDmaBuffer ), 0, pInst->pCfg->rxDmaBufferSize );

        if ( SciDrv_ReadIB ( pInst->pCfg->channelId, eSciDrvDirection_Receive, pInst->pCfg->pRxDmaBuffer, ReadCount ) == E_OK )
        {
            Ret = UCL_E_OK;
        }

        if ( UCL_E_OK == Ret )
        {
            ( void ) UclCmnRingBuffer_Write ( &pInst->rxRingBuffer, pInst->pCfg->pRxDmaBuffer, ReadCount );
            Count -= ReadCount;
        }
        else
        {
            break;
        }
    }

    return Ret;
}
