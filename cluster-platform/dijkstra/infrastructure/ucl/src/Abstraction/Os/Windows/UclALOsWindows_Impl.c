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
#include "UclALOsWindows_Impl.h"
#include "UclALDebug.h"
#include <string.h>
#include <math.h>
#include <signal.h>
#include <errno.h>

DWORD WINAPI UclALOsWindows_Impl_ThreadCB(LPVOID lpParam);
VOID CALLBACK UclALOsWindows_Impl_TimerCB(PVOID lpParam, BOOLEAN TimerOrWaitFired);

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_Initialize(SUclALOsWindowsInst *pInst, uint8 InstId)
{
    Ucl_ReturnType Ret = UCL_E_OK;
    uint8 i;

    // Initialize Mutex
    for (i = 0; i < pInst->pCfg->MaxMutex; i++)
    {
        pInst->pCfg->pMutexList[i].State = eUclOsMutexResState_UnInit;
    }

    // Initialize Task
    for (i = 0; i < pInst->pCfg->MaxTask; i++)
    {
        pInst->pCfg->pTaskList[i].State = eUclOsTaskResState_UnInit;
        pInst->pCfg->pTaskList[i].pFunc = NULL;
        pInst->pCfg->pTaskList[i].pData = NULL;
    }

    // Initialize Timer
    for (i = 0; i < pInst->pCfg->MaxTimers; i++)
    {
        pInst->pCfg->pTimerList[i].State = eUclOsTimerResState_UnInit;
        pInst->pCfg->pTimerList[i].pFunc = NULL;
        pInst->pCfg->pTimerList[i].pData = NULL;
        pInst->pCfg->pTimerList[i].Type = eUclOsTimerType_Last;
    }

    // Initialize Semaphores
    for (i = 0; i < pInst->pCfg->MaxSem; i++)
    {
        pInst->pCfg->pSemList[i].State = eUclOsSemResState_UnInit;
    }

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALOsWindows_Impl", "%s", "IUclALOs_Initialize: Success");
    }
    else
    {
        LOGE(0, "UclALOsWindows_Impl", "IUclALOs_Initialize: Failed %d", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_Shutdown(SUclALOsWindowsInst *pInst, uint8 InstId)
{
    uint8 i;

    // Destroy Timers
    for (i = 0; i < pInst->pCfg->MaxTimers; i++)
    {
        if (eUclOsTimerResState_Running == pInst->pCfg->pTimerList[i].State)
        {
            (void)UclALOsWindows_Impl_IUclALOs_TimerStop(pInst, InstId, i);
        }

        if ((eUclOsTimerResState_Created == pInst->pCfg->pTimerList[i].State) || (eUclOsTimerResState_Stopped == pInst->pCfg->pTimerList[i].State))
        {
            (void)UclALOsWindows_Impl_IUclALOs_TimerDestroy(pInst, InstId, i);
        }
    }

    // Destroy Tasks
    for (i = 0; i < pInst->pCfg->MaxTask; i++)
    {
        if (eUclOsTaskResState_Created == pInst->pCfg->pTaskList[i].State)
        {
            (void)UclALOsWindows_Impl_IUclALOs_TaskDestroy(pInst, InstId, i);
        }
    }

    return UCL_E_OK;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_Memset(SUclALOsWindowsInst *pInst, uint8 InstId, void *pBuffer, uint8 val,
                                                   uint32 Size)
{
    Ucl_ReturnType Ret;

    if ((NULL != pBuffer) && (0 < Size))
    {
        (void)memset(pBuffer, val, Size);
        Ret = UCL_E_OK;
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    return Ret;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_Memcpy(SUclALOsWindowsInst *pInst, uint8 InstId, void *pDst, void *pSrc,
                                                   uint32 Size)
{
    Ucl_ReturnType Ret;

    if ((NULL != pDst) && (NULL != pSrc) && (0 < Size))
    {
        (void)memcpy(pDst, pSrc, Size);
        Ret = UCL_E_OK;
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    return Ret;
}


Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_Memcmp(SUclALOsWindowsInst *pInst, uint8 InstId, void *pDst, void *pSrc,
                                                 uint32 Size)
{
    Ucl_ReturnType Ret=UCL_E_NOK;

    if ((NULL != pDst) && (NULL != pSrc) && (0 < Size))
    {
        if ((memcmp(pDst, pSrc, Size))==((int)0))
        {
        Ret = UCL_E_OK;
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    return Ret;
}


Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_DisableAllInterrupts(SUclALOsWindowsInst *pInst, uint8 InstId)
{
    // Not Applicable
    return UCL_E_NOK;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_EnableAllInterrupts(SUclALOsWindowsInst *pInst, uint8 InstId)
{
    // Not Applicable
    return UCL_E_NOK;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_MutexCreate(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 *pMutexId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i;

    // Validate I/P Params
    if (NULL != pMutexId)
    {
        // Get the Available Mutex
        for (i = 0; i < pInst->pCfg->MaxMutex; i++)
        {
            if ((eUclOsMutexResState_UnInit == pInst->pCfg->pMutexList[i].State) || (eUclOsMutexResState_Destroyed == pInst->pCfg->pMutexList[i].State))
            {

                pInst->pCfg->pMutexList[i].mutex = CreateMutex(NULL, FALSE, NULL);

                if (NULL != pInst->pCfg->pMutexList[i].mutex)
                {
                    *pMutexId = i;

                    pInst->pCfg->pMutexList[i].State = eUclOsMutexResState_Created;
                    Ret = UCL_E_OK;

                    break;
                }
                else
                {
                    LOGE(0, "UclALOsWindows_Impl", "CreateMutex: Failed %d", GetLastError());
                }
            }
        }
		
		if((i == pInst->pCfg->MaxMutex) && (Ret != UCL_E_OK))
		{
			LOGE(0, "UclALOsWindows_Impl", "Mutex Count Exhausted. Increase MaxMutex Count");			
		}
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALOsWindows_Impl", "%s", "IUclALOs_MutexCreate: Success");
    }
    else
    {
        LOGE(0, "UclALOsWindows_Impl", "IUclALOs_MutexCreate: Failed %d", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_MutexDestroy(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 MutexId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if (MutexId < pInst->pCfg->MaxMutex)
    {
        if ((eUclOsMutexResState_Created == pInst->pCfg->pMutexList[MutexId].State) || (eUclOsMutexResState_UnLocked == pInst->pCfg->pMutexList[MutexId].State))
        {
            if (0 != CloseHandle(pInst->pCfg->pMutexList[MutexId].mutex))
            {
                pInst->pCfg->pMutexList[MutexId].State = eUclOsMutexResState_Destroyed;
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE(0, "UclALOsWindows_Impl", "CloseHandle: Failed %d", GetLastError());
            }
        }
        else
        {
            Ret = UCL_E_INVALID_STATE;
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALOsWindows_Impl", "%s", "IUclALOs_MutexDestroy: Success");
    }
    else
    {
        LOGE(0, "UclALOsWindows_Impl", "IUclALOs_MutexDestroy: Failed %d", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_MutexLock(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 MutexId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    DWORD dwWaitResult;

    // Validate I/P Params
    if (MutexId < pInst->pCfg->MaxMutex)
    {
        if ((eUclOsMutexResState_UnInit != pInst->pCfg->pMutexList[MutexId].State) && (eUclOsMutexResState_Destroyed != pInst->pCfg->pMutexList[MutexId].State))
        {
            dwWaitResult = WaitForSingleObject(pInst->pCfg->pMutexList[MutexId].mutex, INFINITE);

            if (WAIT_OBJECT_0 == dwWaitResult)
            {
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE(0, "UclALOsWindows_Impl", "WaitForSingleObject: Failed %d", GetLastError());
            }
        }
        else
        {
            Ret = UCL_E_INVALID_STATE;
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (UCL_E_OK == Ret)
    {
        pInst->pCfg->pMutexList[MutexId].State = eUclOsMutexResState_Locked;
    }
    else
    {
        LOGE(0, "UclALOsWindows_Impl", "IUclALOs_MutexLock: Failed %d", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_MutexTryLock(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 MutexId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    DWORD dwWaitResult;

    // Validate I/P Params
    if (MutexId < pInst->pCfg->MaxMutex)
    {
        if ((eUclOsMutexResState_UnInit != pInst->pCfg->pMutexList[MutexId].State) && (eUclOsMutexResState_Destroyed != pInst->pCfg->pMutexList[MutexId].State))
        {
            dwWaitResult = WaitForSingleObject(pInst->pCfg->pMutexList[MutexId].mutex, 0);

            if (WAIT_OBJECT_0 == dwWaitResult)
            {
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE(0, "UclALOsWindows_Impl", "WaitForSingleObject: Failed %d", GetLastError());
            }
        }
        else
        {
            Ret = UCL_E_INVALID_STATE;
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (UCL_E_OK == Ret)
    {
        pInst->pCfg->pMutexList[MutexId].State = eUclOsMutexResState_Locked;
    }
    else
    {
        LOGE(0, "UclALOsWindows_Impl", "IUclALOs_MutexTryLock: Failed %d", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_MutexUnlock(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 MutexId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if (MutexId < pInst->pCfg->MaxMutex)
    {
        if ((eUclOsMutexResState_UnInit != pInst->pCfg->pMutexList[MutexId].State) && (eUclOsMutexResState_Destroyed != pInst->pCfg->pMutexList[MutexId].State))
        {

            // Unlock while the lock is still being held, otherwise race condition may happen
            pInst->pCfg->pMutexList[MutexId].State = eUclOsMutexResState_UnLocked;

            if (0 != ReleaseMutex(pInst->pCfg->pMutexList[MutexId].mutex))
            {
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE(0, "UclALOsWindows_Impl", "ReleaseMutex: Failed %d", GetLastError());
            }
        }
        else
        {
            Ret = UCL_E_INVALID_STATE;
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (UCL_E_OK != Ret)
    {
        LOGE(0, "UclALOsWindows_Impl", "IUclALOs_MutexUnlock: Failed %d", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_TaskCreate(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 *pThreadId,
                                                       TUclOsTaskEntryFunc pFunc, void *pData)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i;

    if ((NULL != pThreadId) && (NULL != pFunc))
    {
        for (i = 0; i < pInst->pCfg->MaxTask; i++)
        {
            if ((eUclOsTaskResState_UnInit == pInst->pCfg->pTaskList[i].State) || (eUclOsTaskResState_Destroyed == pInst->pCfg->pTaskList[i].State))
            {

                pInst->pCfg->pTaskList[i].thread = CreateThread(NULL, 0, UclALOsWindows_Impl_ThreadCB,
                                                                &pInst->pCfg->pTaskList[i], 0, NULL);

                if (NULL != pInst->pCfg->pTaskList[i].thread)
                {
                    *pThreadId = i;
                    pInst->pCfg->pTaskList[i].pFunc = pFunc;
                    pInst->pCfg->pTaskList[i].pData = pData;
                    pInst->pCfg->pTaskList[i].State = eUclOsTaskResState_Created;
                    Ret = UCL_E_OK;
                    break;
                }
                else
                {
                    LOGE(0, "UclALOsWindows_Impl", "CreateThread: Failed %d", GetLastError());
                }
            }
        }
		
		if((i == pInst->pCfg->MaxTask) && (Ret != UCL_E_OK))
		{
			LOGE(0, "UclALOsWindows_Impl", "Task Count Exhausted. Increase MaxTask Count");			
		}
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALOsWindows_Impl", "%s", "IUclALOs_TaskCreate: Success");
    }
    else
    {
        LOGE(0, "UclALOsWindows_Impl", "IUclALOs_TaskCreate: Failed %d", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_TaskDestroy(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 ThreadId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if (ThreadId < pInst->pCfg->MaxTask)
    {
        if (eUclOsTaskResState_Created == pInst->pCfg->pTaskList[ThreadId].State)
        {
            if (0 != TerminateThread(pInst->pCfg->pTaskList[ThreadId].thread, 0))
            {
                pInst->pCfg->pTaskList[ThreadId].State = eUclOsTaskResState_Destroyed;
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE(0, "UclALOsWindows_Impl", "TerminateThread: Failed %d", GetLastError());
            }
        }
        else
        {
            Ret = UCL_E_INVALID_STATE;
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALOsWindows_Impl", "%s", "IUclALOs_TaskDestroy: Success");
    }
    else
    {
        LOGE(0, "UclALOsWindows_Impl", "IUclALOs_TaskDestroy: Failed %d", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_TimerCreate(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 *pTimerId,
                                                        TUclOsTaskEntryFunc pFunc, void *pData, EUclOsTimerType TimerType)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i;

    /* Validate I/P Params */
    if ((NULL != pTimerId) && (NULL != pFunc) && (NULL != pData) && (eUclOsTimerType_Last > TimerType))
    {
        for (i = 0; i < pInst->pCfg->MaxTimers; i++)
        {
            if ((eUclOsTimerResState_UnInit == pInst->pCfg->pTimerList[i].State) || (eUclOsTimerResState_Destroyed == pInst->pCfg->pTimerList[i].State))
            {
                pInst->pCfg->pTimerList[i].pData = pData;
                pInst->pCfg->pTimerList[i].pFunc = pFunc;
                pInst->pCfg->pTimerList[i].Type = TimerType;

                if (0 != CreateTimerQueueTimer(&pInst->pCfg->pTimerList[i].timer,
                                               NULL,
                                               UclALOsWindows_Impl_TimerCB,
                                               &pInst->pCfg->pTimerList[i],
                                               999999, 0, 0))
                {
                    *pTimerId = i;
                    pInst->pCfg->pTimerList[i].State = eUclOsTimerResState_Created;
                    Ret = UCL_E_OK;
                    break;
                }
                else
                {
                    LOGE(0, "UclALOsWindows_Impl", "CreateTimerQueueTimer: Failed %d", GetLastError());
                }
            }
        }
		
		if((i == pInst->pCfg->MaxTimers) && (Ret != UCL_E_OK))
		{
			LOGE(0, "UclALOsWindows_Impl", "Timer Count Exhausted. Increase MaxTimers Count");			
		}
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALOsWindows_Impl", "%s", "IUclALOs_TimerCreate: Success");
    }
    else
    {
        LOGE(0, "UclALOsWindows_Impl", "IUclALOs_TimerCreate: Failed %d", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_TimerStart(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 TimerId,
                                                       uint32 Timeout)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    BOOL winRet;

    // Validate I/P Params
    if (TimerId < pInst->pCfg->MaxTimers)
    {
        if ((eUclOsTimerResState_Created == pInst->pCfg->pTimerList[TimerId].State) || (eUclOsTimerResState_Stopped == pInst->pCfg->pTimerList[TimerId].State))
        {
            pInst->pCfg->pTimerList[TimerId].Timeout = Timeout;

            if (eUclOsTimerType_Periodic == pInst->pCfg->pTimerList[TimerId].Type)
            {
                winRet = ChangeTimerQueueTimer(NULL, pInst->pCfg->pTimerList[TimerId].timer, Timeout, Timeout);
            }
            else
            {
                winRet = ChangeTimerQueueTimer(NULL, pInst->pCfg->pTimerList[TimerId].timer, Timeout, 0);
            }

            if (0 != winRet)
            {
                pInst->pCfg->pTimerList[TimerId].State = eUclOsTimerResState_Running;
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE(0, "UclALOsWindows_Impl", "ChangeTimerQueueTimer: Failed %d", GetLastError());
            }
        }
        else
        {
            Ret = UCL_E_INVALID_STATE;
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (Ret != UCL_E_OK)
    {
        LOGE(0, "UclALOsWindows_Impl", "IUclALOs_TimerStart Failed %d\n", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_TimerStop(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 TimerId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if (TimerId < pInst->pCfg->MaxTimers)
    {
        if (eUclOsTimerResState_Running == pInst->pCfg->pTimerList[TimerId].State)
        {
            if (0 != ChangeTimerQueueTimer(NULL, pInst->pCfg->pTimerList[TimerId].timer, 0, 0))
            {
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE(0, "UclALOsWindows_Impl", "ChangeTimerQueueTimer: Failed %d", GetLastError());
            }

            pInst->pCfg->pTimerList[TimerId].State = eUclOsTimerResState_Stopped;
        }
        else if ((eUclOsTimerResState_Stopped == pInst->pCfg->pTimerList[TimerId].State) || (eUclOsTimerResState_Created == pInst->pCfg->pTimerList[TimerId].State))
        {
            Ret = UCL_E_OK;
        }
        else
        {
            Ret = UCL_E_INVALID_STATE;
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (Ret != UCL_E_OK)
    {
        LOGE(0, "UclALOsWindows_Impl", "IUclALOs_TimerStop Failed %d\n", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_TimerDestroy(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 TimerId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if (TimerId < pInst->pCfg->MaxTimers)
    {
        if ((eUclOsTimerResState_Created == pInst->pCfg->pTimerList[TimerId].State) || (eUclOsTimerResState_Stopped == pInst->pCfg->pTimerList[TimerId].State))
        {
            (void)DeleteTimerQueueTimer(NULL, pInst->pCfg->pTimerList[TimerId].timer, NULL);

            pInst->pCfg->pTimerList[TimerId].Timeout = 0;
            pInst->pCfg->pTimerList[TimerId].pData = NULL;
            pInst->pCfg->pTimerList[TimerId].pFunc = NULL;
            pInst->pCfg->pTimerList[TimerId].Type = eUclOsTimerType_Last;
            pInst->pCfg->pTimerList[TimerId].State = eUclOsTimerResState_Destroyed;

            Ret = UCL_E_OK;
        }
        else
        {
            Ret = UCL_E_INVALID_STATE;
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (Ret != UCL_E_OK)
    {
        LOGE(0, "UclALOsWindows_Impl", "IUclALOs_TimerDestroy Failed %d\n", Ret);
    }
    return Ret;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_SemCreate(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 *pSemId, uint8 Val)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i;

    // Validate I/P Params
    if (NULL != pSemId)
    {
        // Get the Available Mutex
        for (i = 0; i < pInst->pCfg->MaxSem; i++)
        {
            if ((eUclOsSemResState_UnInit == pInst->pCfg->pSemList[i].State) || (eUclOsSemResState_Destroyed == pInst->pCfg->pSemList[i].State))
            {
                pInst->pCfg->pSemList[i].sem = CreateSemaphore(NULL, Val, Val, NULL);

                if (NULL == pInst->pCfg->pSemList[i].sem)
                {
                    LOGE(0, "UclALOsWindows_Impl", "CreateSemaphore: Failed %d", GetLastError());
                }
                else
                {
                    *pSemId = i;

                    pInst->pCfg->pSemList[i].State = eUclOsSemResState_Created;
                    Ret = UCL_E_OK;
                    break;
                }
            }
        }
		
		if((i == pInst->pCfg->MaxSem) && (Ret != UCL_E_OK))
		{
			LOGE(0, "UclALOsWindows_Impl", "Sem Count Exhausted. Increase MaxSem Count");			
		}
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALOsWindows_Impl", "%s", "IUclALOs_SemCreate: Success");
    }
    else
    {
        LOGE(0, "UclALOsWindows_Impl", "IUclALOs_SemCreate: Failed %d", Ret);
    }
    return Ret;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_SemDestroy(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 SemId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if (SemId < pInst->pCfg->MaxSem)
    {
        if (eUclOsSemResState_Created == pInst->pCfg->pSemList[SemId].State)
        {
            if (0 != CloseHandle(pInst->pCfg->pSemList[SemId].sem))
            {
                pInst->pCfg->pSemList[SemId].State = eUclOsSemResState_Destroyed;
                Ret = UCL_E_OK;
            }
        }
        else
        {
            Ret = UCL_E_INVALID_STATE;
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (Ret != UCL_E_OK)
    {
        LOGE(0, "UclALOsWindows_Impl", "IUclALOs_SemDestroy Failed %d\n", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_SemWait(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 SemId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    DWORD dwWaitResult;

    // Validate I/P Params
    if (SemId < pInst->pCfg->MaxSem)
    {
        if ((eUclOsSemResState_UnInit != pInst->pCfg->pSemList[SemId].State) && (eUclOsSemResState_Destroyed != pInst->pCfg->pSemList[SemId].State))
        {
            dwWaitResult = WaitForSingleObject(pInst->pCfg->pSemList[SemId].sem, INFINITE);

            if (WAIT_OBJECT_0 == dwWaitResult)
            {
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE(0, "UclALOsWindows_Impl", "WaitForSingleObject: Failed %d", GetLastError());
            }
        }
        else
        {
            Ret = UCL_E_INVALID_STATE;
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (Ret != UCL_E_OK)
    {
        LOGE(0, "UclALOsWindows_Impl", "IUclALOs_SemWait Failed %d\n", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_SemPost(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 SemId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if (SemId < pInst->pCfg->MaxSem)
    {
        if ((eUclOsSemResState_UnInit != pInst->pCfg->pSemList[SemId].State) && (eUclOsSemResState_Destroyed != pInst->pCfg->pSemList[SemId].State))
        {
            if (0 != ReleaseSemaphore(pInst->pCfg->pSemList[SemId].sem, 1, NULL))
            {
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE(0, "UclALOsWindows_Impl", "ReleaseSemaphore: Failed %d", GetLastError());
            }
        }
        else
        {
            Ret = UCL_E_INVALID_STATE;
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (Ret != UCL_E_OK)
    {
        LOGE(0, "UclALOsWindows_Impl", "IUclALOs_SemPost Failed %d\n", Ret);
    }

    return Ret;
}

uint64 UclALOsWindows_Impl_IUclALOs_GetSystemTimeMs(SUclALOsWindowsInst *pInst, uint8 InstId)
{
    uint64 ms; // Milliseconds
    FILETIME ft;

    GetSystemTimeAsFileTime(&ft);

    ms = (LONGLONG)ft.dwLowDateTime + ((LONGLONG)(ft.dwHighDateTime) << 32LL);

    return ms;
}

uint32 UclALOsWindows_Impl_IUclALOs_GetSystemTimeResolutionMs(SUclALOsWindowsInst *pInst, uint8 InstId)
{
    return 1u; // Resolution is 1 ms
}

void UclALOsWindows_Impl_IUclALOs_Tick(SUclALOsWindowsInst *pInst, uint8 InstId)
{
    // Not applicable
}

VOID CALLBACK UclALOsWindows_Impl_TimerCB(PVOID lpParam, BOOLEAN TimerOrWaitFired)
{
    SUclALOsWindowsTimerList *pTimerData = (SUclALOsWindowsTimerList *)lpParam;

    if (eUclOsTimerResState_Running == pTimerData->State)
    {
        if (eUclOsTimerType_OneShot == pTimerData->Type)
        {
            pTimerData->State = eUclOsTimerResState_Stopped;
        }
        (void)(pTimerData->pFunc)(pTimerData->pData);
    }
}

DWORD WINAPI UclALOsWindows_Impl_ThreadCB(LPVOID lpParam)
{
    SUclALOsWindowsTaskList *pTaskData = (SUclALOsWindowsTaskList *)lpParam;

    if (eUclOsTaskResState_Created == pTaskData->State)
    {
        (void)(pTaskData->pFunc)(pTaskData->pData);
    }
    return 0;
}
