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
#include "UclALPhySerialWindows_Impl.h"
#include "UclCmnRingBuffer.h"
#include "UclALPhyCbk.h"
#include "UclALDebug.h"
#include "UclALOs.h"

void *UclALPhySerialWindows_Impl_TransmitTask(void *pData);
void *UclALPhySerialWindows_Impl_ReceiveTask(void *pData);
static Ucl_ReturnType UclALPhySerialWindows_Impl_Hw_Open(SUclALPhySerialWindowsInst *pInst);
static Ucl_ReturnType UclALPhySerialWindows_Impl_Hw_Close(SUclALPhySerialWindowsInst *pInst);
static Ucl_ReturnType UclALPhySerialWindows_Impl_Hw_Write(SUclALPhySerialWindowsInst *pInst, uint8 *pData, uint16 Size);
static Ucl_ReturnType UclALPhySerialWindows_Impl_Hw_Read(SUclALPhySerialWindowsInst *pInst, uint8 *pData, uint16 *pSize);

Ucl_ReturnType UclALPhySerialWindows_Impl_IUclALPhy_Initialize(SUclALPhySerialWindowsInst *pInst, uint8 InstId)
{
    Ucl_ReturnType Ret;
    uint8 i;

    Ret = UclALPhySerialWindows_Impl_Hw_Open(pInst);

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
        Ret = UclALOs_SemCreate(0, &pInst->txSemId, 1);
    }
    if (Ret == UCL_E_OK)
    {
        Ret = UclALOs_TaskCreate(0, &pInst->txTaskId, UclALPhySerialWindows_Impl_TransmitTask, (void *)pInst);
    }
    if (Ret == UCL_E_OK)
    {
        Ret = UclALOs_TaskCreate(0, &pInst->rxTaskId, UclALPhySerialWindows_Impl_ReceiveTask, (void *)pInst);
    }

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALPhySerialWindows_Impl", "%s", "IUclALPhy_Initialize: Success\n");

        for (i = 0; i < pInst->numIUclALPhyCbk; i++)
        {
            //TODO: Implement HW Flow Control
            UclALPhyCbk_PeerReadyStatusChanged(pInst->pIUclALPhyCbk[i], eUclALPhyPeerReadyStatus_Ready);
        }
    }
    else
    {
        LOGE(0, "UclALPhySerialWindows_Impl", "IUclALPhy_Initialize: Failed %d\n", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALPhySerialWindows_Impl_IUclALPhy_Shutdown(SUclALPhySerialWindowsInst *pInst, uint8 InstId)
{
    Ucl_ReturnType Ret;

    Ret = UclALPhySerialWindows_Impl_Hw_Close(pInst);

    if (UCL_E_OK == Ret)
    {
        (void)UclALOs_SemDestroy(0, pInst->txSemId);
        (void)UclALOs_MutexDestroy(0, pInst->txRingBufferMutexId);
        (void)UclALOs_MutexDestroy(0, pInst->rxRingBufferMutexId);
        (void)UclALOs_TaskDestroy(0, pInst->txTaskId);
        (void)UclALOs_TaskDestroy(0, pInst->rxTaskId);

        LOGI(0, "UclALPhySerialWindows_Impl", "%s", "IUclALPhy_Shutdown: Success\n");
    }
    else
    {
        LOGE(0, "UclALPhySerialWindows_Impl", "IUclALPhy_Shutdown: Failed %d\n", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALPhySerialWindows_Impl_IUclALPhy_Write(SUclALPhySerialWindowsInst *pInst, uint8 InstId, uint8 *pData,
                                                          uint16 Size)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ((NULL == pData) || (0 == Size))
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else if (INVALID_HANDLE_VALUE == pInst->hSerial)
    {
        LOGE(0, "UclALPhySerialWindows_Impl", "IUclALPhy_Write: Invalid Serial Handle", pInst->pCfg->pDevicePath);
    }
    else
    {
        if (UCL_E_OK == UclALOs_MutexLock(0, pInst->txRingBufferMutexId))
        {
            Ret = UclCmnRingBuffer_Write(&pInst->txRingBuffer, pData, Size);

            (void)UclALOs_MutexUnlock(0, pInst->txRingBufferMutexId);

            if (UCL_E_OK == Ret)
            {
                (void)UclALOs_SemPost(0, pInst->txSemId);
            }
            else
            {
                //TODO: Buffer full Handle Error
                LOGE(0, "UclALPhySerialPOSIX_Impl_IUclALPhy_Write", "No space to write %d\n", Size);
            }
        }
    }

    return Ret;
}

Ucl_ReturnType UclALPhySerialWindows_Impl_IUclALPhy_Read(SUclALPhySerialWindowsInst *pInst, uint8 InstId, uint8 *pData,
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

void *UclALPhySerialWindows_Impl_TransmitTask(void *pData)
{
    SUclALPhySerialWindowsInst *pInst = (SUclALPhySerialWindowsInst *)pData;
    const SUclALPhySerialWindowsCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret;
    uint16 BytesRead;

    LOGI(0, "UclALPhySerialWindows_Impl", "%s", "TransmitTask: Begins");

    while (INVALID_HANDLE_VALUE != pInst->hSerial)
    {
        Ret = UclALOs_SemWait(0, pInst->txSemId);

        if (UCL_E_OK == Ret)
        {
            do
            {
                BytesRead = pCfg->txDmaBufferSize;

                (void)UclALOs_Memset(0, pCfg->pTxDmaBuffer, 0, pCfg->txDmaBufferSize);

                Ret = UclALOs_MutexLock(0, pInst->txRingBufferMutexId);

                if (UCL_E_OK == Ret)
                {
                    Ret = UclCmnRingBuffer_Read(&pInst->txRingBuffer, pCfg->pTxDmaBuffer, &BytesRead);

                    (void)UclALOs_MutexUnlock(0, pInst->txRingBufferMutexId);
                }

                if (0 < BytesRead)
                {
                    if (UCL_E_OK == Ret)
                    {
                        Ret = UclALPhySerialWindows_Impl_Hw_Write(pInst, pCfg->pTxDmaBuffer, BytesRead);
                    }

                    if (UCL_E_OK != Ret)
                    {
                        LOGE(0, "UclALPhySerialPOSIX_Impl", "TransmitTask: Write Failed %d\n", Ret);
                    }
                }

                //usleep( 500 );
            } while (0 < BytesRead);
        }
    }

    LOGI(0, "UclALPhySerialWindows_Impl", "%s", "TransmitTask: Exit");

    return NULL;
}

void *UclALPhySerialWindows_Impl_ReceiveTask(void *pData)
{
    SUclALPhySerialWindowsInst *pInst = (SUclALPhySerialWindowsInst *)pData;
    const SUclALPhySerialWindowsCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret;
    uint16 BytesRead;
    uint8 i;
    DWORD dwCommEvent;

    LOGI(0, "UclALPhySerialWindows_Impl", "%s", "ReceiveTask: Begins");

    if (!SetCommMask(pInst->hSerial, EV_RXCHAR))
    {
        LOGI(0, "UclALPhySerialWindows_Impl", "%s", "SetCommMask: Failed");
        return NULL;
    }
    // Error setting communications event mask.

    while (INVALID_HANDLE_VALUE != pInst->hSerial)
    {
        (void)UclALOs_Memset(0, pCfg->pRxDmaBuffer, 0, pCfg->rxDmaBufferSize);

        if (WaitCommEvent(pInst->hSerial, &dwCommEvent, NULL))
        {
            BytesRead = pCfg->rxDmaBufferSize;

            Ret = UclALPhySerialWindows_Impl_Hw_Read(pInst, pCfg->pRxDmaBuffer, &BytesRead);

            if (UCL_E_OK == Ret)
            {
                Ret = UclALOs_MutexLock(0, pInst->rxRingBufferMutexId);
            }
            if (UCL_E_OK == Ret)
            {
                Ret = UclCmnRingBuffer_Write(&pInst->rxRingBuffer, pCfg->pRxDmaBuffer, BytesRead);

                (void)UclALOs_MutexUnlock(0, pInst->rxRingBufferMutexId);
            }

            if (UCL_E_OK == Ret)
            {
                for (i = 0; i < pInst->numIUclALPhyCbk; i++)
                {
                    UclALPhyCbk_ReceiveDataAvailable(pInst->pIUclALPhyCbk[i]);
                }
            }
        }
    }

    LOGI(0, "UclALPhySerialWindows_Impl", "%s", "ReceiveTask: Exit");

    return NULL;
}

static Ucl_ReturnType UclALPhySerialWindows_Impl_Hw_Open(SUclALPhySerialWindowsInst *pInst)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    DCB dcbSerialParams = {0};
    COMMTIMEOUTS timeouts = {0};

    pInst->hSerial = CreateFile(pInst->pCfg->pDevicePath, GENERIC_READ | GENERIC_WRITE, 0, 0,
                                OPEN_EXISTING, FILE_FLAG_OVERLAPPED, 0);

    if (INVALID_HANDLE_VALUE != pInst->hSerial)
    {
        dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
        if (GetCommState(pInst->hSerial, &dcbSerialParams) == 0)
        {
            LOGE(0, "UclALPhySerialWindows_Impl", "%s", "Hw_Open Error getting device state");
            CloseHandle(pInst->hSerial);
            pInst->hSerial = INVALID_HANDLE_VALUE;
            Ret = UCL_E_NOK;
        }
        else
        {
            Ret = UCL_E_OK;
        }
    }
    else
    {
        LOGE(0, "UclALPhySerialWindows_Impl", "CreateFile Failed %d", GetLastError());
    }

    if (UCL_E_OK == Ret)
    {
        dcbSerialParams.BaudRate = CBR_115200;
        dcbSerialParams.ByteSize = 8;
        dcbSerialParams.StopBits = ONESTOPBIT;
        dcbSerialParams.Parity = NOPARITY;
        if (SetCommState(pInst->hSerial, &dcbSerialParams) == 0)
        {
            LOGE(0, "UclALPhySerialWindows_Impl", "%s", "Hw_Open Error setting device parameters");
            CloseHandle(pInst->hSerial);
            pInst->hSerial = INVALID_HANDLE_VALUE;
            Ret = UCL_E_NOK;
        }
    }

    if (UCL_E_OK == Ret)
    {
        // Set COM port timeout settings
        timeouts.ReadIntervalTimeout = 50;
        timeouts.ReadTotalTimeoutConstant = 50;
        timeouts.ReadTotalTimeoutMultiplier = 10;
        timeouts.WriteTotalTimeoutConstant = 50;
        timeouts.WriteTotalTimeoutMultiplier = 10;
        if (SetCommTimeouts(pInst->hSerial, &timeouts) == 0)
        {
            LOGE(0, "UclALPhySerialWindows_Impl", "%s", "Hw_Open Error Error setting timeouts");
            CloseHandle(pInst->hSerial);
            pInst->hSerial = INVALID_HANDLE_VALUE;
            Ret = UCL_E_NOK;
        }
    }

    return Ret;
}

static Ucl_ReturnType UclALPhySerialWindows_Impl_Hw_Close(SUclALPhySerialWindowsInst *pInst)
{
    Ucl_ReturnType Ret = UCL_E_OK;

    if (INVALID_HANDLE_VALUE != pInst->hSerial)
    {
        CloseHandle(pInst->hSerial);
        pInst->hSerial = INVALID_HANDLE_VALUE;
    }

    return Ret;
}

static Ucl_ReturnType UclALPhySerialWindows_Impl_Hw_Write(SUclALPhySerialWindowsInst *pInst, uint8 *pData, uint16 Size)
{
    Ucl_ReturnType Ret = UCL_E_OK;
    DWORD BytesWrote, BytesSent = 0;

    if (INVALID_HANDLE_VALUE != pInst->hSerial)
    {
        Ucl_ReturnType Ret = UCL_E_NOK;
        BytesSent = 0;
        do
        {
            OVERLAPPED osWrite = {0};
            osWrite.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

            if (osWrite.hEvent == NULL)
            {
                LOGE(0, "UclALPhySerialWindows_Impl", "Hw_Write CreateEvent Failed %d", GetLastError());
                break;
            }

            if (!WriteFile(pInst->hSerial, &pData[BytesSent], (Size - BytesSent), &BytesWrote, &osWrite))
            {
                if (GetLastError() != ERROR_IO_PENDING)
                {
                    LOGE(0, "UclALPhySerialWindows_Impl", "Hw_Write WriteFile Failed %d", GetLastError());
                    break;
                }
                else
                {
                    // Write is pending.
                    if (!GetOverlappedResult(pInst->hSerial, &osWrite, &BytesWrote, TRUE))
                    {
                        LOGE(0, "UclALPhySerialWindows_Impl", "Hw_Write GetOverlappedResult Failed %d", GetLastError());
                        break;
                    }
                }
            }
            BytesSent += BytesWrote;

            CloseHandle(osWrite.hEvent);
        } while (BytesSent < Size);

        if (BytesSent == Size)
        {
            Ret = UCL_E_OK;
        }

        return Ret;
    }

    return Ret;
}

static Ucl_ReturnType UclALPhySerialWindows_Impl_Hw_Read(SUclALPhySerialWindowsInst *pInst, uint8 *pData, uint16 *pSize)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 chRead;
    DWORD dwRead;
    uint16 bytesRead = 0;

    if (INVALID_HANDLE_VALUE != pInst->hSerial)
    {
        do
        {
            if (ReadFile(pInst->hSerial, &chRead, 1, &dwRead, NULL))
            {
                pData[bytesRead] = chRead;
                bytesRead++;
            }
            else
            {
                break;
            }
        } while ((0 != dwRead) || (bytesRead < *pSize));

        *pSize = bytesRead;

        Ret = UCL_E_OK;
    }

    return Ret;
}
