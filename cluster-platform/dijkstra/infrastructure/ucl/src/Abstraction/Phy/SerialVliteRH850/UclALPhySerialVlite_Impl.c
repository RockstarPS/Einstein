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
#include "uart_if.h"
#include "UclCmnRingBuffer.h"
#include "UclALPhyCbk.h"
#include "UclALOs.h"
#include "UclALDebug.h"
#include "UclALPhySerialVlite_Impl.h"


extern uint8 UclHwIf_PowerUpHost( uint8 InstId );
extern uint8 UclHWIf_ByteReceived( uint16 *length );
extern uint8 inspect_uart_sts(uint8 channel);

static Ucl_ReturnType UclALPhySerialVlite_Impl_SetupTransmit( SUclALPhySerialVliteInst *pInst );
static Ucl_ReturnType UclALPhySerialVlite_Impl_SetupReceive( SUclALPhySerialVliteInst *pInst );

#define UCL_UART_CHANNEL_BUSY (uint8)1
#define UCL_UART_CHANNEL_IDLE (uint8)0

static uint8 UartChStatus = UCL_UART_CHANNEL_IDLE;

Ucl_ReturnType UclALPhySerialVlite_Impl_IUclALPhy_Initialize( SUclALPhySerialVliteInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    UartChStatus = UCL_UART_CHANNEL_IDLE;
    // Initialize ring buffers
    Ret = UclCmnRingBuffer_Initialize( &pInst->txRingBuffer, pInst->pCfg->pTxRingBuffer,
                                       pInst->pCfg->txRingBufferSize );
    if (UCL_E_OK == Ret)
    {
        Ret = UclCmnRingBuffer_Initialize( &pInst->rxRingBuffer, pInst->pCfg->pRxRingBuffer,
                                           pInst->pCfg->rxRingBufferSize );
    }
    if (Ret == UCL_E_OK)
    {
        // Function shall be left dummy, if VIP doesn't power up GIP through UCL
        (void) UclHwIf_PowerUpHost( 0 );
    }

    if (UCL_E_OK == Ret)
    {
        // Initialize DMA buffers
        (void) UclALOs_Memset( 0, (void *) (pInst->pCfg->pTxDmaBuffer), 0, pInst->pCfg->txDmaBufferSize );
        (void) UclALOs_Memset( 0, (void *) (pInst->pCfg->pRxDmaBuffer), 0, pInst->pCfg->rxDmaBufferSize );
        pInst->isPeerReady = FALSE;
    }

    if (UCL_E_OK == Ret)
    {
        Ret = UclALPhySerialVlite_Impl_SetupReceive( pInst );
    }
    else
    {
        LOGE(0, "UclALPhySerialVlite_Impl", "%s", "IUclALPhy_Initialize: SciDrv_GetStatus Not Initialized");
        Ret = UCL_E_NOK;
    }
    return Ret;
}

Ucl_ReturnType UclALPhySerialVlite_Impl_IUclALPhy_Shutdown( SUclALPhySerialVliteInst *pInst, uint8 InstId )
{

    return UCL_E_OK;
}

Ucl_ReturnType UclALPhySerialVlite_Impl_IUclALPhy_Write(SUclALPhySerialVliteInst *pInst, uint8 InstId, uint8 *pData, uint16 Size)

{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ((NULL != pData) && (0u < Size))
    {
        (void)UclALOs_DisableAllInterrupts( 0 );
        Ret = UclCmnRingBuffer_Write( &(pInst->txRingBuffer), pData, Size );
        if (UCL_E_OK == Ret)
        {
            Ret = UclALPhySerialVlite_Impl_SetupTransmit( pInst );
        }
        (void)UclALOs_EnableAllInterrupts( 0 );
    }

    return Ret;
}

Ucl_ReturnType UclALPhySerialVlite_Impl_IUclALPhy_Read( SUclALPhySerialVliteInst *pInst, uint8 InstId, uint8 *pData,
        uint16 *pSize )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ((NULL != pData) && (NULL != pSize) && (0u < *pSize))
    {
        (void)UclALOs_DisableAllInterrupts( 0 );
        Ret = UclCmnRingBuffer_ReadFrame( &pInst->rxRingBuffer, 0x0, pData, pSize );
        (void)UclALOs_EnableAllInterrupts( 0 );
    }

    return Ret;
}

Ucl_ReturnType UclALPhySerialVlite_Impl_IUclALHwCbk_TransmitComplete( SUclALPhySerialVliteInst *pInst, uint8 InstId )
{

    Ucl_ReturnType Ret = UCL_E_OK;

    UartChStatus = UCL_UART_CHANNEL_IDLE;
    Ret = UclALPhySerialVlite_Impl_SetupTransmit( pInst );

    return Ret;
}

Ucl_ReturnType UclALPhySerialVlite_Impl_IUclALHwCbk_ReceiveComplete( SUclALPhySerialVliteInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint16 BytesRecvd = 0u;

    // Read the data into the ring buffer
    (void)UclHWIf_ByteReceived( (uint16 *) &BytesRecvd );
    if (BytesRecvd > 0u)
    {
        (void) UclCmnRingBuffer_Write( &pInst->rxRingBuffer, pInst->pCfg->pRxDmaBuffer, BytesRecvd );
        UclALPhyCbk_ReceiveDataAvailable( pInst->pIUclALPhyCbk[0] );
    }

    (void) UclALPhySerialVlite_Impl_SetupReceive( pInst );

    // Started getting pings. Master is up
    if (eUclALPhyPeerReadyStatus_NotReady == pInst->isPeerReady)
    {
        pInst->isPeerReady = eUclALPhyPeerReadyStatus_Ready;
        UclALPhyCbk_PeerReadyStatusChanged( pInst->pIUclALPhyCbk[0], eUclALPhyPeerReadyStatus_Ready );
    }

    return Ret;
}

Ucl_ReturnType UclALPhySerialVlite_Impl_IUclALHwCbk_GpioChanged( SUclALPhySerialVliteInst *pInst, uint8 InstId, uint16 GpioId )
{
    Ucl_ReturnType Ret = UCL_E_OK;

    return Ret;
}

static Ucl_ReturnType UclALPhySerialVlite_Impl_SetupReceive( SUclALPhySerialVliteInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;

    (void) UclALOs_Memset( 0u, (void *) (pInst->pCfg->pRxDmaBuffer), 0x0, pInst->pCfg->rxDmaBufferSize );

    return Ret;
}

static Ucl_ReturnType UclALPhySerialVlite_Impl_SetupTransmit( SUclALPhySerialVliteInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_OK;
    uint16 Size = 0u;
    DEVICECOMM_STATUS_TYPE UartRet;
    uint8 UartInspectChSts = UCL_UART_CHANNEL_IDLE;

    if (1u == pInst->pCfg->HwFlowCtrlOn)
    {
        UartInspectChSts = inspect_uart_sts(pInst->pCfg->channelId);
    }

    if ((UartChStatus == UCL_UART_CHANNEL_IDLE) && (UartInspectChSts == UCL_UART_CHANNEL_IDLE ))
    {
        (void) UclALOs_Memset( 0u, (void *) (pInst->pCfg->pTxDmaBuffer), 0x0, pInst->pCfg->txDmaBufferSize );

        Size = pInst->pCfg->txDmaBufferSize;

        Ret = UclCmnRingBuffer_Read( &pInst->txRingBuffer, pInst->pCfg->pTxDmaBuffer, &Size );

        if ((Ret == UCL_E_OK)&& (0u < Size))
        {
            UartRet = uart_tx_req(pInst->pCfg->channelId, pInst->pCfg->pTxDmaBuffer, Size);

            if ((UartRet == DEVICECOMM_STATUS_MSG_GOOD) || (UartRet == DEVICECOMM_STATUS_MSG_PENDING))
            {
                Ret = UCL_E_OK;
                UartChStatus = UCL_UART_CHANNEL_BUSY;
            }

        }
    }
    return Ret;
}
