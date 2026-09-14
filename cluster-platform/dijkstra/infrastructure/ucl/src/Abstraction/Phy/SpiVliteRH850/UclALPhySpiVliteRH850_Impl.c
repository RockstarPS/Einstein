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
#include "spi_driver.h"
#include "spi_proto_ipcl.h"
#include "spi_mgr_cfg.h"
#include "spi_client_mgr.h"
#include "spi_if.h"
#include "spi_proto_ipcl_cfg.h"
#include "spi_client_cfg.h"
#include "spi_driver_types.h"
#include "spi_types.h"
#include "UclCmnRingBuffer.h"
#include "UclALPhyCbk.h"
#include "UclALOs.h"
#include "UclALDebug.h"
#include "UclALPhySpiVliteRH850_Impl.h"
#include "spi_mgr.h"
#include "portman_interrupt_auxiliary_if.h"

#define SPI_DT_IDLE 0u
#define SPI_DT_LEN 1u
#define SPI_DT_DATA 2u

#define SPI_SLAVE_WAIT_FOR_LEN 0u
#define SPI_SLAVE_WAIT_FOR_DATA 1u

extern uint8 UclHwIf_PowerUpHost(uint8 InstId);
extern uint8 UclHwIf_GetSlaveFlowControlStatus(uint8 InstId);

static void *UclALPhySpiVliteRH850_Impl_TimerTask(void *pData);
static void *UclALPhySpiVliteRH850_Impl_StartupDelayTimerTask(void *pData);
Ucl_ReturnType UclALPhySpiVliteRH850_Impl_SendLen(SUclALPhySpiVliteRH850Inst *pInst, uint8 always);
Ucl_ReturnType UclALPhySpiVliteRH850_Impl_SendData(SUclALPhySpiVliteRH850Inst *pInst);

Ucl_ReturnType UclALPhySpiVliteRH850_Impl_IUclALPhy_Initialize(SUclALPhySpiVliteRH850Inst *pInst, uint8 InstId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Initialize ring buffers
    Ret = UclCmnRingBuffer_Initialize(&pInst->txRingBuffer, pInst->pCfg->pTxRingBuffer,
                                      pInst->pCfg->txRingBufferSize);
    if (UCL_E_OK == Ret)
    {
        Ret = UclCmnRingBuffer_Initialize(&pInst->rxRingBuffer, pInst->pCfg->pRxRingBuffer,
                                          pInst->pCfg->rxRingBufferSize);
    }

    //Initialize TimerTask
    if (Ret == UCL_E_OK)
    {
        Ret = UclALOs_TimerCreate(0, &pInst->timerTaskId, UclALPhySpiVliteRH850_Impl_TimerTask, (void *)pInst,
                                  eUclOsTimerType_Periodic);
    }

    if (Ret == UCL_E_OK)
    {
        Ret = UclALOs_TimerCreate(0, &pInst->timerStartupDelayTaskId, UclALPhySpiVliteRH850_Impl_StartupDelayTimerTask,
                                  (void *)pInst, eUclOsTimerType_OneShot);

        //Start TimerTask
        if (Ret == UCL_E_OK)
        {
            UclHwIf_PowerUpHost(0);

            Ret = UclALOs_TimerStart(0, pInst->timerStartupDelayTaskId, pInst->pCfg->phyLinkUpDelayMs);
        }
    }

    if (UCL_E_OK == Ret)
    {
        // Initialize DMA buffers
        (void)UclALOs_Memset(0, (void *)(pInst->pCfg->pTxDmaBuffer), 0, pInst->pCfg->txDmaBufferSize);
        (void)UclALOs_Memset(0, (void *)(pInst->pCfg->pRxDmaBuffer), 0, pInst->pCfg->rxDmaBufferSize);

        pInst->isPeerReady = FALSE;
        pInst->dataTransferPhase = SPI_DT_IDLE;
        pInst->spiXferlen = 0;

        spi_mgr_open();
        spi_proto_ipcl_dma_int_enable();
        portman_ext_enable_intp5_mode();
    }
    else
    {
        LOGE(0, "UclALPhySerialASR_Impl", "%s", "IUclALPhy_Initialize: SciDrv_GetStatus Not Initialized");
        Ret = UCL_E_NOK;
    }
    return Ret;
}

Ucl_ReturnType UclALPhySpiVliteRH850_Impl_IUclALPhy_Shutdown(SUclALPhySpiVliteRH850Inst *pInst, uint8 InstId)
{
    spi_proto_ipcl_dma_int_disable();
    return UCL_E_OK;
}

Ucl_ReturnType UclALPhySpiVliteRH850_Impl_IUclALPhy_Write(SUclALPhySpiVliteRH850Inst *pInst, uint8 InstId, uint8 *pData, uint16 Size)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ((NULL != pData) && (0 < Size))
    {
        UclALOs_DisableAllInterrupts(0);
        Ret = UclCmnRingBuffer_Write(&(pInst->txRingBuffer), pData, Size);
        UclALOs_EnableAllInterrupts(0);
    }
    return Ret;
}

Ucl_ReturnType UclALPhySpiVliteRH850_Impl_IUclALPhy_Read(SUclALPhySpiVliteRH850Inst *pInst, uint8 InstId, uint8 *pData, uint16 *pSize)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ((NULL != pData) && (NULL != pSize) && (0 < *pSize))
    {
        UclALOs_DisableAllInterrupts(0);
        Ret = UclCmnRingBuffer_ReadFrame(&pInst->rxRingBuffer, 0x0, pData, pSize);
        UclALOs_EnableAllInterrupts(0);
    }

    return Ret;
}

Ucl_ReturnType UclALPhySpiVliteRH850_Impl_IUclALHwCbk_TransmitComplete(SUclALPhySpiVliteRH850Inst *pInst, uint8 InstId)
{
    return UCL_E_OK;
}

Ucl_ReturnType UclALPhySpiVliteRH850_Impl_IUclALHwCbk_ReceiveComplete(SUclALPhySpiVliteRH850Inst *pInst, uint8 InstId)
{
    Ucl_ReturnType Ret = UCL_E_OK;
    uint16 rxSize, txSize;

    if (SPI_DT_LEN == pInst->dataTransferPhase)
    {
        txSize = (uint16)(((uint16)(pInst->pCfg->pTxDmaBuffer[0]) << 8) | ((uint16)(pInst->pCfg->pTxDmaBuffer[1])));
        rxSize = (uint16)(((uint16)(pInst->pCfg->pRxDmaBuffer[0]) << 8) | ((uint16)(pInst->pCfg->pRxDmaBuffer[1])));

        if (rxSize <= pInst->pCfg->rxDmaBufferSize)
        {
            if (txSize > rxSize)
            {
                pInst->spiXferlen = txSize;
            }
            else
            {
                pInst->spiXferlen = rxSize;
            }

            if (pInst->spiXferlen == 0)
            {
                pInst->dataTransferPhase = SPI_DT_IDLE;
            }
        }
    }
    else if (SPI_DT_DATA == pInst->dataTransferPhase)
    {
        UclALOs_DisableAllInterrupts(0);

        rxSize = (uint16)(((uint16)(pInst->pCfg->pRxDmaBuffer[0]) << 8) | ((uint16)(pInst->pCfg->pRxDmaBuffer[1])));

        if (rxSize <= pInst->pCfg->rxDmaBufferSize)
        {
            // Copy the Received data into the  Ring buffer
            Ret = UclCmnRingBuffer_Write(&pInst->rxRingBuffer, &pInst->pCfg->pRxDmaBuffer[2], rxSize);
        }

        pInst->dataTransferPhase = SPI_DT_IDLE;

        UclALOs_EnableAllInterrupts(0);
    }

    return Ret;
}

Ucl_ReturnType UclALPhySpiVliteRH850_Impl_IUclALHwCbk_GpioChanged(SUclALPhySpiVliteRH850Inst *pInst, uint8 InstId, uint16 GpioId)
{
    Ucl_ReturnType Ret = UCL_E_OK;

    if (SPI_SLAVE_WAIT_FOR_DATA == UclHwIf_GetSlaveFlowControlStatus(GpioId))
    {
        // Slave ready to receive data
        if ((SPI_DT_LEN == pInst->dataTransferPhase) && (pInst->spiXferlen > 0))
        {
            UclALPhySpiVliteRH850_Impl_SendData(pInst);
        }
        else
        {
            //TODO: Handle Error
        }
    }
    else
    {
        // Slave ready to receive length
        if ((SPI_DT_IDLE == pInst->dataTransferPhase) && (TRUE == pInst->isPeerReady))
        {
            // Initiate transfer only if there is pending data
            UclALPhySpiVliteRH850_Impl_SendLen(pInst, FALSE);
        }
    }

    return Ret;
}

static void *UclALPhySpiVliteRH850_Impl_StartupDelayTimerTask(void *pData)
{
    SUclALPhySpiVliteRH850Inst *pInst = (SUclALPhySpiVliteRH850Inst *)pData;

    // Check if slave is ready
    if (SPI_SLAVE_WAIT_FOR_LEN == UclHwIf_GetSlaveFlowControlStatus(0))
    {
        pInst->isPeerReady = TRUE;
        // Notify Peer Ready Status
        UclALPhyCbk_PeerReadyStatusChanged(pInst->pIUclALPhyCbk[0], eUclALPhyPeerReadyStatus_Ready);
        // Start scheduled transfers
        (void)UclALOs_TimerStart(0, pInst->timerTaskId, 8u);
    }
    else
    {
        // Slave still not ready, try after sometime
        (void)UclALOs_TimerStart(0, pInst->timerStartupDelayTaskId, 5000u);
    }

    return NULL;
}

static void *UclALPhySpiVliteRH850_Impl_TimerTask(void *pData)
{
    SUclALPhySpiVliteRH850Inst *pInst = (SUclALPhySpiVliteRH850Inst *)pData;

    if (SPI_DT_IDLE == pInst->dataTransferPhase)
    {
        if (SPI_SLAVE_WAIT_FOR_LEN == UclHwIf_GetSlaveFlowControlStatus(0))
        {
            // Trigger length transfer
            UclALPhySpiVliteRH850_Impl_SendLen(pInst, TRUE);
        }
        else
        {
            // TODO: Handle Error
        }
    }
    else if (SPI_DT_LEN == pInst->dataTransferPhase)
    {
        // Stuck waiting for Data Phase to Start
        // Retry sending the length again
        if (SPI_SLAVE_WAIT_FOR_LEN == UclHwIf_GetSlaveFlowControlStatus(0))
        {
            // Trigger length transfer
            UclALPhySpiVliteRH850_Impl_SendLen(pInst, TRUE);
        }
        else
        {
            // Did we miss the GPIO Toggle?
            // Do data transfer
            UclALPhySpiVliteRH850_Impl_SendData(pInst);
        }
    }
    else if (SPI_DT_DATA == pInst->dataTransferPhase)
    {
        // Stuck waiting for Data Phase to End
        // Retry sending the data again
        if (SPI_SLAVE_WAIT_FOR_DATA == UclHwIf_GetSlaveFlowControlStatus(0))
        {
            UclALPhySpiVliteRH850_Impl_SendData(pInst);
        }
        else
        {
            pInst->dataTransferPhase = SPI_DT_IDLE;
        }
    }
    else
    {
        // End of world
        pInst->dataTransferPhase = SPI_DT_IDLE;
    }

    return NULL;
}

Ucl_ReturnType UclALPhySpiVliteRH850_Impl_SendLen(SUclALPhySpiVliteRH850Inst *pInst, uint8 always)
{
    Ucl_ReturnType Ret = UCL_E_OK;
    DEVICECOMM_STATUS_TYPE status;
    uint16 txSize;

    if (SPI_DT_IDLE == pInst->dataTransferPhase)
    {
        pInst->spiXferlen = 0;

        (void)UclALOs_Memset(0, (void *)(pInst->pCfg->pTxDmaBuffer), 0, pInst->pCfg->txDmaBufferSize);
        (void)UclALOs_Memset(0, (void *)(pInst->pCfg->pRxDmaBuffer), 0, pInst->pCfg->rxDmaBufferSize);

        txSize = pInst->pCfg->txDmaBufferSize - 2u;
        Ret = UclCmnRingBuffer_Read(&pInst->txRingBuffer, &pInst->pCfg->pTxDmaBuffer[2], &txSize);

        if (((UCL_E_OK == Ret) && (txSize > 0)) || (TRUE == always))
        {
            pInst->pCfg->pTxDmaBuffer[0] = (uint8)((txSize >> 8) & 0xFFu);
            pInst->pCfg->pTxDmaBuffer[1] = (uint8)(txSize & 0xFFu);

            status = spi_tx_read_req(SPI_IPCL, pInst->pCfg->pTxDmaBuffer, 2, pInst->pCfg->pRxDmaBuffer, 2);

            if ((status == DEVICECOMM_STATUS_MSG_GOOD) || (status == DEVICECOMM_STATUS_MSG_PENDING))
            {
                pInst->dataTransferPhase = SPI_DT_LEN;
            }
            else
            {
                //TODO: Handle Error
                Ret = UCL_E_NOK;
            }
        }
    }
    else if (SPI_DT_LEN == pInst->dataTransferPhase)
    {
        status = spi_tx_read_req(SPI_IPCL, pInst->pCfg->pTxDmaBuffer, 2, pInst->pCfg->pRxDmaBuffer, 2);

        if ((status == DEVICECOMM_STATUS_MSG_GOOD) || (status == DEVICECOMM_STATUS_MSG_PENDING))
        {
            pInst->dataTransferPhase = SPI_DT_LEN;
        }
        else
        {
            //TODO: Handle Error
            pInst->dataTransferPhase = SPI_DT_IDLE;
        }
    }

    return Ret;
}

Ucl_ReturnType UclALPhySpiVliteRH850_Impl_SendData(SUclALPhySpiVliteRH850Inst *pInst)
{
    Ucl_ReturnType Ret = UCL_E_OK;
    DEVICECOMM_STATUS_TYPE status;
    uint16 xferSize;

    xferSize = pInst->spiXferlen;
    if (pInst->spiXferlen > 0)
    {
        status = spi_tx_read_req(SPI_IPCL, &(pInst->pCfg->pTxDmaBuffer[2]),
                                 xferSize, &(pInst->pCfg->pRxDmaBuffer[2]), xferSize);

        if ((status == DEVICECOMM_STATUS_MSG_GOOD) || (status == DEVICECOMM_STATUS_MSG_PENDING))
        {
            pInst->dataTransferPhase = SPI_DT_DATA;
        }
        else
        {
            //TODO: Handle Error
            pInst->dataTransferPhase = SPI_DT_IDLE;
            Ret = UCL_E_NOK;
        }
    }
    else
    {
        pInst->dataTransferPhase = SPI_DT_IDLE;
        Ret = UCL_E_NOK;
    }

    return Ret;
}
