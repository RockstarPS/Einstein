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
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <linux/spi/spidev.h>
#include <linux/input.h>
#include "UclALPhySpiLinux_Impl.h"
#include "UclCmnRingBuffer.h"
#include "UclALPhyCbk.h"
#include "UclALDebug.h"
#include "UclALOs.h"

#define ENABLE_RCARH3_BYTE_SWAP_WORKAROUND

static void *UclALPhySpiLinux_Impl_TimerTask(void *pData);
static Ucl_ReturnType UclALPhySpiLinux_Impl_HwSpiOpen(SUclALPhySpiLinuxInst *pInst);
static Ucl_ReturnType UclALPhySpiLinux_Impl_HwSpiClose(SUclALPhySpiLinuxInst *pInst);
static Ucl_ReturnType UclALPhySpiLinux_Impl_HwSpiTransfer(SUclALPhySpiLinuxInst *pInst);
static Ucl_ReturnType UclALPhySpiLinux_Impl_HwGpioOpen(SUclALPhySpiLinuxInst *pInst);
static Ucl_ReturnType UclALPhySpiLinux_Impl_HwGpioClose(SUclALPhySpiLinuxInst *pInst);
static uint8 UclALPhySpiLinux_Impl_HwGpioRead(SUclALPhySpiLinuxInst *pInst);

Ucl_ReturnType UclALPhySpiLinux_Impl_IUclALPhy_Initialize(SUclALPhySpiLinuxInst *pInst, uint8 InstId)
{
    Ucl_ReturnType Ret;
    uint8 i;

    //open the SPI device
    Ret = UclALPhySpiLinux_Impl_HwSpiOpen(pInst);

    if (Ret != UCL_E_OK)
    {
        LOGE(0, "UclALPhySpiLinux_Impl", "UclALPhySpiLinux_Impl_HwSpiOpen Failed %d\n", Ret);
    }

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

    //Initialize TimerTask
    if (Ret == UCL_E_OK)
    {
        Ret = UclALOs_TimerCreate(0, &pInst->timerTaskId, UclALPhySpiLinux_Impl_TimerTask, (void *)pInst, eUclOsTimerType_Periodic);
    }

    //Start TimerTask
    if (Ret == UCL_E_OK)
    {
        Ret = UclALOs_TimerStart(0, pInst->timerTaskId, 4u);
    }

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALPhySpiLinux_Impl", "%s", "IUclALPhy_Initialize Success\n");

        for (i = 0; i < pInst->numIUclALPhyCbk; i++)
        {
            //TODO: Implement HW Flow Control
            UclALPhyCbk_PeerReadyStatusChanged(pInst->pIUclALPhyCbk[i], eUclALPhyPeerReadyStatus_Ready);
        }
    }
    else
    {
        LOGE(0, "UclALPhySpiLinux_Impl", "IUclALPhy_Initialize Failed %d\n", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALPhySpiLinux_Impl_IUclALPhy_Shutdown(SUclALPhySpiLinuxInst *pInst, uint8 InstId)
{
    Ucl_ReturnType Ret;

    Ret = UclALPhySpiLinux_Impl_HwSpiClose(pInst);

    if (UCL_E_OK == Ret)
    {
        (void)UclALOs_MutexDestroy(0, pInst->txRingBufferMutexId);
        (void)UclALOs_MutexDestroy(0, pInst->rxRingBufferMutexId);
        (void)UclALOs_TimerStop(0, pInst->timerTaskId);
        (void)UclALOs_TimerDestroy(0, pInst->timerTaskId);

        LOGI(0, "UclALPhySpiLinux_Impl", "%s", "IUclALPhy_Shutdown Success\n");
    }
    else
    {
        LOGE(0, "UclALPhySpiLinux_Impl", "IUclALPhy_Shutdown Failed %d\n", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALPhySpiLinux_Impl_IUclALPhy_Write(SUclALPhySpiLinuxInst *pInst, uint8 InstId, uint8 *pData,
                                                     uint16 Size)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ((NULL == pData) || (0 == Size))
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else if (0 > pInst->spiFd)
    {
        LOGE(0, "UclALPhySpiLinux_Impl", "IUclALPhy_Write Invalid Dev Fd for %s\n", pInst->pCfg->pDevicePath);
    }
    else
    {
        if (UCL_E_OK == UclALOs_MutexLock(0, pInst->txRingBufferMutexId))
        {
            Ret = UclCmnRingBuffer_Write(&pInst->txRingBuffer, pData, Size);
            if (UCL_E_NOK == Ret)
            {
                //TODO: Buffer full Handle Error
                LOGE(0, "UclALPhySpiLinux_Impl", "IUclALPhy_Write No space to write %d\n", Size);
            }
            (void)UclALOs_MutexUnlock(0, pInst->txRingBufferMutexId);
        }
    }

    return Ret;
}

Ucl_ReturnType UclALPhySpiLinux_Impl_IUclALPhy_Read(SUclALPhySpiLinuxInst *pInst, uint8 InstId, uint8 *pData,
                                                    uint16 *pSize)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ((NULL == pData) || (NULL == pSize) || (0 == *pSize))
    {
        Ret = UCL_E_INVALID_ARGS;
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

static void *UclALPhySpiLinux_Impl_TimerTask(void *pData)
{
    SUclALPhySpiLinuxInst *pInst = (SUclALPhySpiLinuxInst *)pData;

    // Perform transfer
    (void)UclALPhySpiLinux_Impl_HwSpiTransfer(pInst);

    return NULL;
}

static Ucl_ReturnType UclALPhySpiLinux_Impl_HwSpiOpen(SUclALPhySpiLinuxInst *pInst)
{
    Ucl_ReturnType Ret = UCL_E_OK;
    sint32 Status;
    uint8 mode;

    // Open the SPI device
    pInst->spiFd = open(pInst->pCfg->pDevicePath, O_RDWR);

    if (0 > pInst->spiFd)
    {
        LOGE(0, "UclALPhySpiLinux_Impl", "Unable to open SPI device %s component Exit", pInst->pCfg->pDevicePath);
        Ret = UCL_E_NOK;
    }
    else
    {
        LOGI(0, "UclALPhySpiLinux_Impl", "Open SPI device %s component Success", pInst->pCfg->pDevicePath);
    }

    if ((Ret == UCL_E_OK) && (0 != pInst->pCfg->gpioNum))
    {
        Ret = UclALPhySpiLinux_Impl_HwGpioOpen(pInst);
    }

    mode = pInst->pCfg->spiMode | SPI_LSB_FIRST;
    if (UCL_E_OK == Ret)
    {
        Status = ioctl(pInst->spiFd, SPI_IOC_WR_MODE, &mode);
        if (0 > Status)
        {
            LOGE(0, "UclALPhySpiLinux_Impl", "%s", "Unable to Set SPI Write Mode Exit\n");
            Ret = UCL_E_NOK;
        }
        else
        {
            LOGI(0, "UclALPhySpiLinux_Impl", "SPI Write Mode %d", mode);
        }
    }

    if (UCL_E_OK == Ret)
    {
        Status = ioctl(pInst->spiFd, SPI_IOC_RD_MODE, &mode);
        if (0 > Status)
        {
            LOGE(0, "UclALPhySpiLinux_Impl", "%s", "Unable to Set SPI Read Mode Exit\n");
            Ret = UCL_E_NOK;
        }
        else
        {
            LOGI(0, "UclALPhySpiLinux_Impl", "SPI Read Mode %d", mode);
        }
    }

    if (UCL_E_OK == Ret)
    {
        Status = ioctl(pInst->spiFd, SPI_IOC_WR_BITS_PER_WORD, &pInst->pCfg->bitsperword);
        if (0 > Status)
        {
            LOGE(0, "UclALPhySpiLinux_Impl", "%s", "Unable to Set SPI write bits per word Exit\n");
            Ret = UCL_E_NOK;
        }
        else
        {
            LOGI(0, "UclALPhySpiLinux_Impl", "SPI write bits per word %d", pInst->pCfg->bitsperword);
        }
    }

    if (UCL_E_OK == Ret)
    {
        Status = ioctl(pInst->spiFd, SPI_IOC_RD_BITS_PER_WORD, &pInst->pCfg->bitsperword);
        if (0 > Status)
        {
            LOGE(0, "UclALPhySpiLinux_Impl", "%s", "Unable to Set SPI read bits per word Exit\n");
            Ret = UCL_E_NOK;
        }
        else
        {
            LOGI(0, "UclALPhySpiLinux_Impl", "SPI read bits per word %d", pInst->pCfg->bitsperword);
        }
    }

    if (UCL_E_OK == Ret)
    {
        Status = ioctl(pInst->spiFd, SPI_IOC_WR_MAX_SPEED_HZ, &pInst->pCfg->speed);
        if (0 > Status)
        {
            LOGE(0, "UclALPhySpiLinux_Impl", "%s", "Unable to set write SPI baud rate");
            Ret = UCL_E_NOK;
        }
        else
        {
            LOGI(0, "UclALPhySpiLinux_Impl", "SPI write baudrate %d", pInst->pCfg->speed);
        }
    }

    if (UCL_E_OK == Ret)
    {
        Status = ioctl(pInst->spiFd, SPI_IOC_RD_MAX_SPEED_HZ, &pInst->pCfg->speed);
        if (0 > Status)
        {
            LOGE(0, "UclALPhySpiLinux_Impl", "%s", "Unable to set read SPI baud rate");
            Ret = UCL_E_NOK;
        }
        else
        {
            LOGI(0, "UclALPhySpiLinux_Impl", "SPI read baudrate %d", pInst->pCfg->speed);
        }
    }

    return Ret;
}

static Ucl_ReturnType UclALPhySpiLinux_Impl_HwSpiClose(SUclALPhySpiLinuxInst *pInst)
{
    Ucl_ReturnType Ret = UCL_E_OK;

    if (0 < pInst->spiFd)
    {
        LOGE(0, "UclALPhySpiLinux_Impl", "Device %s already closed\n", pInst->pCfg->pDevicePath);
    }
    else
    {
        if (0 != pInst->pCfg->gpioNum)
        {
            Ret = UclALPhySpiLinux_Impl_HwGpioClose(pInst);
        }

        if (0 > close(pInst->spiFd))
        {
            Ret = UCL_E_NOK;
            LOGE(0, "UclALPhySpiLinux_Impl", "Device %s close failed\n", pInst->pCfg->pDevicePath);
        }
        else
        {
            LOGI(0, "UclALPhySpiLinux_Impl", "Device %s closed\n", pInst->pCfg->pDevicePath);
        }
    }

    return Ret;
}

static Ucl_ReturnType UclALPhySpiLinux_Impl_HwSpiTransfer(SUclALPhySpiLinuxInst *pInst)
{
    Ucl_ReturnType Ret = UCL_E_OK;
    struct spi_ioc_transfer Transferlen;
    struct spi_ioc_transfer Transferdata;
    uint16 TransferSize = 0;
    uint16 TxSize = 0;
    uint16 RxSize = 0;
    sint32 Status = 0;
    uint32 SlaveTimeout;
    int i;

    if (0 > pInst->spiFd)
    {
        LOGI(0, "UclALPhySpiLinux_Impl", "%s", "Hw_Transfer: Invalid FD");
        Ret = UCL_E_NOK;
    }

    // Wait until VIP is ready or timeout
    if (0 != pInst->pCfg->gpioNum)
    {
        SlaveTimeout = 500;
        while ((FALSE == UclALPhySpiLinux_Impl_HwGpioRead(pInst)) && (SlaveTimeout > 0))
        {
            usleep(10);
            SlaveTimeout--;
            if (0 == SlaveTimeout)
            {
                LOGI(0, "UclALPhySpiLinux_Impl", "%s", "Slave timeout during length transfer");
            }
        }
    }

    // Read data to transmit
    if (Ret == UCL_E_OK)
    {
        (void)UclALOs_Memset(0, (void *)(pInst->pCfg->pTxDmaBuffer), 0, pInst->pCfg->txDmaBufferSize);
        (void)UclALOs_Memset(0, (void *)(pInst->pCfg->pRxDmaBuffer), 0, pInst->pCfg->rxDmaBufferSize);

        TxSize = pInst->pCfg->txDmaBufferSize;
        Ret = UclCmnRingBuffer_Read(&pInst->txRingBuffer, &pInst->pCfg->pTxDmaBuffer[2], &TxSize);

        if ((0 < TxSize) && (UCL_E_OK == Ret))
        {
            pInst->pCfg->pTxDmaBuffer[0] = (uint8)(TxSize >> 8);
            pInst->pCfg->pTxDmaBuffer[1] = (uint8)(TxSize & 0x00FF);
        }
        else if ((0 == TxSize) && (UCL_E_NOK == Ret))
        {
            Ret = UCL_E_OK;
        }
    }

    // Negotiate transfer length
    if (Ret == UCL_E_OK)
    {
        (void)UclALOs_Memset(0, (uint8 *)&Transferlen, 0, sizeof(Transferlen));

        Transferlen.rx_buf = (uint64)pInst->pCfg->pRxDmaBuffer;
        Transferlen.tx_buf = (uint64)pInst->pCfg->pTxDmaBuffer;
        Transferlen.len = 2u;
        Transferlen.bits_per_word = 8;

        Status = ioctl(pInst->spiFd, SPI_IOC_MESSAGE(1), &Transferlen);
        if (0 > Status)
        {
            LOGI(0, "UclALPhySpiLinux_Impl", "%s", "Hw_Transfer: Get length SPI transfer failed");
            Ret = UCL_E_NOK;
        }
        else
        {
            RxSize = (uint16)(((uint16)(pInst->pCfg->pRxDmaBuffer[0] << 8)) | ((uint16)(pInst->pCfg->pRxDmaBuffer[1])));

            if (RxSize <= pInst->pCfg->rxDmaBufferSize)
            {
                if (TxSize > RxSize)
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
                LOGE(0, "UclALPhySpiLinux_Impl", "Hw_Transfer: Invalid Rx Size received :%d\n", RxSize);
                Ret = UCL_E_NOK;
            }
        }
    }

    if ((UCL_E_OK == Ret) && (0 < TransferSize))
    {
        if (0 != pInst->pCfg->gpioNum)
        {
            SlaveTimeout = 500;
            while ((TRUE == UclALPhySpiLinux_Impl_HwGpioRead(pInst)) && (SlaveTimeout > 0))
            {
                usleep(10);
                SlaveTimeout--;
                if (0 == SlaveTimeout)
                {
                    LOGI(0, "UclALPhySpiLinux_Impl", "%s", "Slave timeout during length transfer");
                }
            }
        }
        else
        {
            usleep(200);
        }

#ifdef ENABLE_RCARH3_BYTE_SWAP_WORKAROUND
        // TEMPORARY FIX START. YES THIS IS UGLY AND THERE IS A BETTER WAY. I DONT HAVE TIME, DEAL WITH IT.
        if ((TxSize >= 16) && ((TxSize % 4) == 0))
        {
            for (i = 0; (i < TxSize / 4); i++)
            {
                uint8 tempVal;
                uint8 *tempSwap = &pInst->pCfg->pTxDmaBuffer[2 + (i * 4)];

                tempVal = tempSwap[0];
                tempSwap[0] = tempSwap[3];
                tempSwap[3] = tempVal;

                tempVal = tempSwap[1];
                tempSwap[1] = tempSwap[2];
                tempSwap[2] = tempVal;
            }
        }
        else if ((RxSize >= 16) && ((RxSize % 4) == 0))
        {
            for (i = 0; (i < TxSize / 4); i++)
            {
                uint8 tempVal;
                uint8 *tempSwap = &pInst->pCfg->pTxDmaBuffer[2 + (i * 4)];

                tempVal = tempSwap[0];
                tempSwap[0] = tempSwap[3];
                tempSwap[3] = tempVal;

                tempVal = tempSwap[1];
                tempSwap[1] = tempSwap[2];
                tempSwap[2] = tempVal;
            }
        }
// TEMPORARY FIX END
#endif

        (void)UclALOs_Memset(0, (uint8 *)&Transferdata, 0, sizeof(Transferdata));

        Transferdata.rx_buf = (uint64)&pInst->pCfg->pRxDmaBuffer[2];
        Transferdata.tx_buf = (uint64)&pInst->pCfg->pTxDmaBuffer[2];
        Transferdata.len = TransferSize;
        Transferdata.bits_per_word = 8;

        Status = ioctl(pInst->spiFd, SPI_IOC_MESSAGE(1), &Transferdata);

        if (0 > Status)
        {
            LOGI(0, "UclALPhySpiLinux_Impl", "%s", "Hw_Transfer: data transfer failed");
            Ret = UCL_E_NOK;
        }

        //LOGI(0, "UclALPhySpiLinux_Impl", "Hw_Transfer: RxSize %d, TxSize %d, XferSize %d", RxSize, TxSize, TransferSize);
    }

    // Copy any received data to ring buffer
    if ((Ret == UCL_E_OK) && (0 < RxSize))
    {
#ifdef ENABLE_RCARH3_BYTE_SWAP_WORKAROUND
        // TEMPORARY FIX START. YES THIS IS UGLY AND THERE IS A BETTER WAY. I DONT HAVE TIME, DEAL WITH IT.
        if ((RxSize >= 16) && ((RxSize % 4) == 0))
        {
            for (i = 0; (i < RxSize / 4); i++)
            {
                uint8 tempVal;
                uint8 *tempSwap = &pInst->pCfg->pRxDmaBuffer[2 + (i * 4)];

                tempVal = tempSwap[0];
                tempSwap[0] = tempSwap[3];
                tempSwap[3] = tempVal;

                tempVal = tempSwap[1];
                tempSwap[1] = tempSwap[2];
                tempSwap[2] = tempVal;
            }
        }
// TEMPORARY FIX END
#endif

        Ret = UclCmnRingBuffer_Write(&pInst->rxRingBuffer, &pInst->pCfg->pRxDmaBuffer[2], RxSize);
    }

    if (Ret != UCL_E_OK)
    {
        //TODO: Call error callbacks
        LOGE(0, "UclALPhySpiLinux_Impl", "%s", "Hw_Transfer: ipcl Phy fatal error");
    }

    return Ret;
}

static Ucl_ReturnType UclALPhySpiLinux_Impl_HwGpioOpen(SUclALPhySpiLinuxInst *pInst)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    int fd_temp;
    int success = 0;
    char buff[64];

    (void)memset(buff, 0, 64);
    fd_temp = open("/sys/class/gpio/export", O_WRONLY);
    if (fd_temp < 0)
    {
        LOGE(0, "UclALPhySpiLinux_Impl", "%s", "Can't open GPIO for export\n");
    }
    else
    {
        sprintf(buff, "%d", (int)pInst->pCfg->gpioNum);
        (void)write(fd_temp, buff, strlen(buff));
        close(fd_temp);
        success = 1;
    }

    if (1 == success)
    {
        (void)memset(buff, 0, 64);
        (void)sprintf(buff, "/sys/class/gpio/gpio%d/direction", (int)pInst->pCfg->gpioNum);

        fd_temp = open(buff, O_WRONLY);

        if (fd_temp < 0)
        {
            LOGE(0, "UclALPhySpiLinux_Impl", "%s", "Can't set direction for GPIO\n");
            success = 0;
        }
        else
        {
            (void)write(fd_temp, "in", 2);
            close(fd_temp);
        }
    }

    if (1 == success)
    {
        (void)memset(buff, 0, 64);
        (void)sprintf(buff, "/sys/class/gpio/gpio%d/value", (int)pInst->pCfg->gpioNum);
        pInst->gpioFd = open(buff, O_RDONLY);

        if (pInst->gpioFd < 0)
        {
            LOGE(0, "UclALPhySpiLinux_Impl", "%s", "Can't open for GPIO for read\n");
        }
        else
        {
            Ret = UCL_E_OK;
        }
    }

    return Ret;
}

static Ucl_ReturnType UclALPhySpiLinux_Impl_HwGpioClose(SUclALPhySpiLinuxInst *pInst)
{
    Ucl_ReturnType Ret = UCL_E_OK;
    int fd_temp;
    char buff[4];

    close(pInst->gpioFd);

    fd_temp = open("/sys/class/gpio/unexport", O_WRONLY);

    if (fd_temp < 0)
    {
        LOGE(0, "UclALPhySpiLinux_Impl", "%s", "Can't open GPIO for unexport\n");
    }
    else
    {
        sprintf(buff, "%d", (int)pInst->pCfg->gpioNum);
        (void)write(fd_temp, buff, strlen(buff));
        close(fd_temp);
    }

    return Ret;
}

static uint8 UclALPhySpiLinux_Impl_HwGpioRead(SUclALPhySpiLinuxInst *pInst)
{
    char fc_raw;
    uint8 state = FALSE;

    if (pInst->gpioFd < 0)
    {
        LOGE(0, "UclALPhySpiLinux_Impl", "%s", "get fc invalid fd\n");
    }
    else
    {
        (void)lseek(pInst->gpioFd, 0, SEEK_SET);

        (void)read(pInst->gpioFd, &fc_raw, 1);

        if (0x30 == fc_raw)
        {
            state = FALSE;
        }
        else
        {
            state = TRUE;
        }
    }

    return state;
}
