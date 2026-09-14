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
#include "UclALPhySpiIntegrityRCar_Impl.h"
#include "UclALPhyCbk.h"
#include "UclALOs.h"
#include "UclALDebug.h"

#define GPIO_LOW (0u)
#define GPIO_HIGH (1u)

#define SPI_SEND_LEN (0u)
#define SPI_SEND_DATA (1u)

#define SPI_INTR_NOTIF_ID (1u)
#define SPI_TIMER_ACTIVITY_ID (2u)

static void *UclALPhySpiIntegrityRCar_Impl_Task(void *pData);
static void UclALPhySpiIntegrityRCar_Impl_ReceiveComplete(SUclALPhySpiIntegrityRCarInst *pInst);
static Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_SetupLength(SUclALPhySpiIntegrityRCarInst *pInst);
static Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_SetupData(SUclALPhySpiIntegrityRCarInst *pInst);
static Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_HwSpiOpen(SUclALPhySpiIntegrityRCarInst *pInst);
static Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_HwSpiClose(SUclALPhySpiIntegrityRCarInst *pInst);
static Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_HwGpioOpen(SUclALPhySpiIntegrityRCarInst *pInst);
static Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_HwGpioClose(SUclALPhySpiIntegrityRCarInst *pInst);

Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_IUclALPhy_Initialize(SUclALPhySpiIntegrityRCarInst *pInst, uint8 InstId)
{
    Ucl_ReturnType Ret;

    //Initialize Hardware Resources
    Ret = UclALPhySpiIntegrityRCar_Impl_HwSpiOpen(pInst);

    if (Ret == UCL_E_OK)
    {
        Ret = UclALPhySpiIntegrityRCar_Impl_HwGpioOpen(pInst);
    }

    //Initialize OS Resources
    if (Ret == UCL_E_OK)
    {
        Ret = UclCmnRingBuffer_Initialize(&pInst->txRingBuffer, pInst->pCfg->pTxRingBuffer,
                                          pInst->pCfg->txRingBufferSize);
    }

    if (Ret == UCL_E_OK)
    {
        Ret = UclCmnRingBuffer_Initialize(&pInst->rxRingBuffer, pInst->pCfg->pRxRingBuffer,
                                          pInst->pCfg->txRingBufferSize);
    }

    if (Ret == UCL_E_OK)
    {
        Ret = UclALOs_MutexCreate(0, &pInst->txRingBufferMutexId);
    }

    if (Ret == UCL_E_OK)
    {
        Ret = UclALOs_MutexCreate(0, &pInst->rxRingBufferMutexId);
    }

    if (Ret == UCL_E_OK)
    {
        pInst->dataTransferPhase = SPI_SEND_LEN;
        pInst->peerReadyState = eUclALPhyPeerReadyStatus_NotReady;
        pInst->exitTask = FALSE;

        Ret = UclALOs_TaskCreate(0, &pInst->taskId, UclALPhySpiIntegrityRCar_Impl_Task, (void *)pInst);
    }

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALPhySpiIntegrityRCar", "%s", "IUclALPhy_Initialize Success\n");
    }
    else
    {
        LOGE(0, "UclALPhySpiIntegrityRCar", "IUclALPhy_Initialize Failed %d\n", Ret);
    }

    return UCL_E_OK;
}

Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_IUclALPhy_Shutdown(SUclALPhySpiIntegrityRCarInst *pInst, uint8 InstId)
{
    pInst->exitTask = TRUE;

    return UCL_E_OK;
}

Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_IUclALPhy_Write(SUclALPhySpiIntegrityRCarInst *pInst, uint8 InstId,
                                                             uint8 *pData, uint16 size)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ((NULL == pData) || (0 == size))
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else if (pInst->pSpiIf == NULL)
    {
        LOGE(0, "UclALPhySpiIntegrityRCar", "%s", "IUclALPhy_Write: Invalid SPI device \n");
    }
    else
    {
        if (UCL_E_OK == UclALOs_MutexLock(0, pInst->txRingBufferMutexId))
        {
            Ret = UclCmnRingBuffer_Write(&pInst->txRingBuffer, pData, size);
            if (UCL_E_NOK == Ret)
            {
                //TODO: Buffer full Handle Error
                LOGE(0, "UclALPhySpiIntegrityRCar", "%s", "IUclALPhy_Write: Buffer full \n");
            }
            (void)UclALOs_MutexUnlock(0, pInst->txRingBufferMutexId);
        }
    }

    return Ret;
}

Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_IUclALPhy_Read(SUclALPhySpiIntegrityRCarInst *pInst, uint8 InstId,
                                                            uint8 *pData, uint16 *pSize)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ((NULL == pData) || (NULL == pSize) || (0 == *pSize))
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else if (pInst->pSpiIf == NULL)
    {
        LOGE(0, "UclALPhySpiIntegrityRCar", "%s", "IUclALPhy_Read: Invalid SPI device \n");
    }
    else
    {
        if (UCL_E_OK == UclALOs_MutexLock(0, pInst->rxRingBufferMutexId))
        {
            Ret = UclCmnRingBuffer_ReadFrame(&pInst->rxRingBuffer, 0x0, pData, pSize);
            (void)UclALOs_MutexUnlock(0, pInst->rxRingBufferMutexId);
        }
    }

    return Ret;
}

static Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_HwSpiOpen(SUclALPhySpiIntegrityRCarInst *pInst)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    pInst->pSpiIf = Rcar_MsiofSpi_CreateInterface(pInst->pCfg->spiDev);

    if (NULL != pInst->pSpiIf)
    {
        Ret = UCL_E_OK;
    }
    else
    {
        LOGE(0, "UclALPhySpiIntegrityRCar", "%s", "Rcar_MsiofSpi_CreateInterface: Failed \n");
    }

    return Ret;
}

static Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_HwSpiClose(SUclALPhySpiIntegrityRCarInst *pInst)
{
    return UCL_E_OK;
}

static Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_HwGpioOpen(SUclALPhySpiIntegrityRCarInst *pInst)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    pInst->pGpioIf = Rcar_Gpio_CreateInterface(pInst->pCfg->gpioDev);

    if (NULL != pInst->pGpioIf)
    {
        // Output High
        rcar_gpio_direction_output(pInst->pGpioIf, pInst->pCfg->gpioPin, GPIO_HIGH);
        Ret = UCL_E_OK;
    }
    else
    {
        LOGE(0, "UclALPhySpiIntegrityRCar", "%s", "Rcar_Gpio_CreateInterface: Failed \n");
    }

    return Ret;
}

static Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_HwGpioClose(SUclALPhySpiIntegrityRCarInst *pInst)
{
    return UCL_E_OK;
}

static Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_SetupLength(SUclALPhySpiIntegrityRCarInst *pInst)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint16 Size = 0;
    Error err = Failure;

    (void)UclALOs_Memset(0, (void *)(pInst->pCfg->pTxDmaBuffer), 0, pInst->pCfg->txDmaBufferSize);
    (void)UclALOs_Memset(0, (void *)(pInst->pCfg->pRxDmaBuffer), 0, pInst->pCfg->rxDmaBufferSize);

    if (UCL_E_OK == UclALOs_MutexLock(0, pInst->txRingBufferMutexId))
    {
        Size = pInst->pCfg->txDmaBufferSize - 2u;
        (void)UclCmnRingBuffer_Read(&pInst->txRingBuffer, &pInst->pCfg->pTxDmaBuffer[2u], &Size);
        (void)UclALOs_MutexUnlock(0, pInst->txRingBufferMutexId);

        pInst->pCfg->pTxDmaBuffer[0] = (uint8)((Size & (uint16)(0xFF00)) >> 8);
        pInst->pCfg->pTxDmaBuffer[1] = (uint8)(Size & (uint16)(0x00FF));

        err = Rcar_MsiofSpi_TransferData(pInst->pSpiIf, pInst->pCfg->pTxDmaBuffer, pInst->pCfg->pRxDmaBuffer, 2u, 1u);
        if (Success == err)
        {
            // Setup next data transfer phase
            pInst->dataTransferPhase = SPI_SEND_DATA;
            // Indicate master that length is ready
            rcar_gpio_direction_output(pInst->pGpioIf, pInst->pCfg->gpioPin, GPIO_LOW);
            Ret = UCL_E_OK;
        }
        else
        {
            LOGE(0, "UclALPhySpiIntegrityRCar", "%s", "SetupLength Rcar_MsiofSpi_TransferData Failed \n");
            Ret = UCL_E_NOK;
        }
    }

    return Ret;
}

static Ucl_ReturnType UclALPhySpiIntegrityRCar_Impl_SetupData(SUclALPhySpiIntegrityRCarInst *pInst)
{
    Ucl_ReturnType Ret = UCL_E_OK;
    Error err = Failure;
    uint16 txSize = 0, rxSize = 0, xferSize = 0;

    txSize = (uint16)((uint16)pInst->pCfg->pTxDmaBuffer[0] << 8 | (uint16)pInst->pCfg->pTxDmaBuffer[1]);
    rxSize = (uint16)((uint16)pInst->pCfg->pRxDmaBuffer[0] << 8 | (uint16)pInst->pCfg->pRxDmaBuffer[1]);

    if (rxSize <= pInst->pCfg->rxDmaBufferSize)
    {
        if (txSize > rxSize)
        {
            xferSize = txSize;
        }
        else
        {
            xferSize = rxSize;
        }

        // Started getting pings. Master is up. Indicate Link up Status.
        if (eUclALPhyPeerReadyStatus_NotReady == pInst->peerReadyState)
        {
            pInst->peerReadyState = eUclALPhyPeerReadyStatus_Ready;
            UclALPhyCbk_PeerReadyStatusChanged(pInst->pIUclALPhyCbk[0], eUclALPhyPeerReadyStatus_Ready);
        }
    }

    if (xferSize > 0)
    {
        err = Rcar_MsiofSpi_TransferData(pInst->pSpiIf, &pInst->pCfg->pTxDmaBuffer[2u],
                                         &pInst->pCfg->pRxDmaBuffer[2u], xferSize, 1);

        if (Success == err)
        {
            // Setup next data transfer phase
            pInst->dataTransferPhase = SPI_SEND_LEN;
            // Indicate master that data is ready
            rcar_gpio_direction_output(pInst->pGpioIf, pInst->pCfg->gpioPin, GPIO_HIGH);
        }
        else
        {
            LOGE(0, "UclALPhySpiIntegrityRCar", "%s", "SetupData Rcar_MsiofSpi_TransferData Failed \n");
            Ret = UCL_E_NOK;
        }
    }
    else
    {
        Ret = UclALPhySpiIntegrityRCar_Impl_SetupLength(pInst);
        // Setup next length transfer
        if (UCL_E_OK != Ret)
        {
            LOGE(0, "UclALPhySpiIntegrityRCar", "%s", "SetupLength Failed \n");
        }
    }

    return Ret;
}

static void UclALPhySpiIntegrityRCar_Impl_ReceiveComplete(SUclALPhySpiIntegrityRCarInst *pInst)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Error err = Failure;
    uint16 txSize = 0, rxSize = 0, xferSize = 0;

    if (SPI_SEND_LEN == pInst->dataTransferPhase)
    {
        // Dequeue data and write to the receive ring buffer
        txSize = (uint16)((uint16)pInst->pCfg->pTxDmaBuffer[0] << 8 | (uint16)pInst->pCfg->pTxDmaBuffer[1]);
        rxSize = (uint16)((uint16)pInst->pCfg->pRxDmaBuffer[0] << 8 | (uint16)pInst->pCfg->pRxDmaBuffer[1]);

        if (rxSize <= pInst->pCfg->rxDmaBufferSize)
        {
            if (txSize > rxSize)
            {
                xferSize = txSize;
            }
            else
            {
                xferSize = rxSize;
            }
        }

        err = Rcar_MsiofSpi_Slave_Finalize_Transfer(pInst->pSpiIf, &pInst->pCfg->pRxDmaBuffer[2], xferSize);

        if (Success == err)
        {
            if (rxSize > 0)
            {
                if (UCL_E_OK == UclALOs_MutexLock(0, pInst->rxRingBufferMutexId))
                {
                    Ret = UclCmnRingBuffer_Write(&pInst->rxRingBuffer, &pInst->pCfg->pRxDmaBuffer[2], rxSize);
                    if (UCL_E_NOK == Ret)
                    {
                        LOGE(0, "UclALPhySpiIntegrityRCar", "%s", "ReceiveComplete : Rx Ring buffer full \n");
                    }
                    (void)UclALOs_MutexUnlock(0, pInst->rxRingBufferMutexId);
                }
            }
        }
        else
        {
            //TODO Handle Error
            LOGE(0, "UclALPhySpiIntegrityRCar", "%s", "ReceiveComplete (Data): Finalize_Transfer phase failed\n");
        }

        // Setup next length transfer
        if (UCL_E_OK != UclALPhySpiIntegrityRCar_Impl_SetupLength(pInst))
        {
            LOGE(0, "UclALPhySpiIntegrityRCar", "%s", "SetupLength Failed \n");
        }
    }
    else if (SPI_SEND_DATA == pInst->dataTransferPhase)
    {
        // Dequeue length and setup data transfer
        err = Rcar_MsiofSpi_Slave_Finalize_Transfer(pInst->pSpiIf, pInst->pCfg->pRxDmaBuffer, 2u);
        if (Success == err)
        {
            if (UCL_E_OK != UclALPhySpiIntegrityRCar_Impl_SetupData(pInst))
            {
                LOGE(0, "UclALPhySpiIntegrityRCar", "%s", "SetupData Failed \n");
            }
        }
        else
        {
            //TODO Handle Error
            LOGE(0, "UclALPhySpiIntegrityRCar", "%s", "ReceiveComplete (Length): Finalize_Transfer phase failed\n");
        }
    }
    else
    {
        //TODO Handle Error
        LOGE(0, "UclALPhySpiIntegrityRCar", "%s", "ReceiveComplete: Invalid Data transfer phase \n");
    }
}

static void *UclALPhySpiIntegrityRCar_Impl_Task(void *pData)
{
    SUclALPhySpiIntegrityRCarInst *pInst = (SUclALPhySpiIntegrityRCarInst *)pData;
    Ucl_ReturnType Ret = UCL_E_NOK;
    viodev_Interface *pViodev = NULL;
    IODevice iodev = NULLIODevice;
    Activity interruptActivity = NULLActivity;
    Activity timerActivity = NULLActivity;
    Clock alarmClock;
    Time AlarmTime;
    Value activityID = 0;
    Error Err;
    Value Priority;
    Value Weight;
    uint64 Timeout;

    // Make this a high priority task, else interrupts are delayed
    Err = GetPriorityAndWeight(CurrentTask(), &Priority, &Weight);
    if (Success == Err)
    {
        LOGI(0, "UclALPhySpiIntegrityRCar", "Old Priority = %d, Weight = %d\n", Priority, Weight);
    }

    if (Success == Err)
    {
        Priority = 240;
        Err = SetPriorityAndWeight(CurrentTask(), Priority, Weight, false);
    }

    if (Success == Err)
    {
        Err = GetPriorityAndWeight(CurrentTask(), &Priority, &Weight);
    }

    if (Success == Err)
    {
        LOGI(0, "UclALPhySpiIntegrityRCar", "New Priority = %d, Weight = %d\n", Priority, Weight);
    }

    if ((Success == Err) && (NULL != pInst->pSpiIf))
    {
        pViodev = Rcar_MsiofSpi_GetInterface(pInst->pSpiIf);
    }

    if (NULL != pViodev)
    {
        iodev = viodev_GetIODevice(pViodev);
    }

    if (NULLIODevice != iodev)
    {
        Err = CreateVirtualClock(HighestResStandardClock, CLOCK_READTIME | CLOCK_ALARM, &alarmClock);
        if (Success == Err)
        {
            CreateActivity(CurrentTask(), 200, false, SPI_TIMER_ACTIVITY_ID, &timerActivity);
        }
    }

    if (NULLActivity != timerActivity)
    {
        CreateActivity(CurrentTask(), 200, false, SPI_INTR_NOTIF_ID, &interruptActivity);
    }

    if (NULLActivity != interruptActivity)
    {
        if (UCL_E_OK != UclALPhySpiIntegrityRCar_Impl_SetupLength(pInst))
        {
            LOGE(0, "UclALPhySpiIntegrityRCar", "%s", "SetupLength Failed \n");
        }
    }
    else
    {
        pInst->exitTask = TRUE;
        LOGE(0, "UclALPhySpiIntegrityRCar", "%s", "Interrupt Setup Failed \n");
    }

    while (FALSE == pInst->exitTask)
    {
        // Hook up SPI interrupt
        Err = AsynchronousReceive(interruptActivity, (Object)iodev, NULL);
        if (Success != Err)
        {
            LOGE(0, "UclALPhySpiIntegrityRCar", "interruptActivity AsynchronousReceive Failed %d \n", Err);
        }

        if ((eUclALPhyPeerReadyStatus_Ready == pInst->peerReadyState) && (Success == Err))
        {
            // Hook up Timer Interrupt
            Err = AsynchronousReceive(timerActivity, (Object)alarmClock, NULL);
            if (Success != Err)
            {
                LOGE(0, "UclALPhySpiIntegrityRCar", "timerActivity AsynchronousReceive Failed %d\n", Err);
            }
            else
            {
                Timeout = 500; // 500ms timeout
                AlarmTime.Seconds = 0;
                AlarmTime.Fraction = (uint32)((Timeout << 32) / 1000);

                Err = SetClockAlarm(alarmClock, false, NULLTime, &AlarmTime);
                if (Success != Err)
                {
                    LOGE(0, "UclALPhySpiIntegrityRCar", "SetClockAlarm Failed %d\n", Err);
                }
            }
        }

        WaitForActivity(&activityID);

        if (SPI_INTR_NOTIF_ID == activityID)
        {
            UclALPhySpiIntegrityRCar_Impl_ReceiveComplete(pInst);

            // Stop Timer
            ResetActivity(timerActivity);
            SetClockAlarm(alarmClock, false, NULLTime, NULLTime);
        }
        else if (SPI_TIMER_ACTIVITY_ID == activityID)
        {
            // Handle Timeout
            LOGE(0, "UclALPhySpiIntegrityRCar", "%s", "SPI_TIMER_ACTIVITY_ID expired\n");
            // Stop DMA
            (void)Rcar_MsiofSpi_Slave_Finalize_Transfer(pInst->pSpiIf, NULL, 0);
            // Reset Activity
            ResetActivity(interruptActivity);
            // Wait for length phase
            if (UCL_E_OK != UclALPhySpiIntegrityRCar_Impl_SetupLength(pInst))
            {
                LOGE(0, "UclALPhySpiIntegrityRCar", "%s", "SetupLength Failed \n");
            }
        }
    }

    // Free up resources
    CloseActivity(interruptActivity);
    CloseActivity(timerActivity);
    CloseClock(alarmClock);

    UclALPhySpiIntegrityRCar_Impl_HwGpioClose(pInst);
    UclALPhySpiIntegrityRCar_Impl_HwSpiClose(pInst);

    return NULL;
}
