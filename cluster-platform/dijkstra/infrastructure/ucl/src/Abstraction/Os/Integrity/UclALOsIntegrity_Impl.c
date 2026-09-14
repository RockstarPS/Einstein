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
#include "UclALDebug.h"
#include "UclALOsIntegrity_Impl.h"

static Value UclALOsIntegrity_Impl_TimerTaskHandler(Address arg);

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_Initialize(SUclALOsIntegrityInst *pInst, uint8 InstId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclALOsIntegrityCfg *pCfg = pInst->pCfg;
    Error Err;
    uint8 i;

    // Initialize Mutex
    for (i = 0; i < pInst->pCfg->maxMutex; i++)
    {
        pInst->pCfg->pMutexList[i].state = eUclOsMutexResState_UnInit;
    }

    // Initialize Semaphores
    for (i = 0; i < pInst->pCfg->maxSem; i++)
    {
        pInst->pCfg->pSemList[i].state = eUclOsSemResState_UnInit;
    }

    // Initialize Timers
    for (i = 0; i < pCfg->maxTimers; i++)
    {
        pCfg->pTimerList[i].state = eUclOsTimerResState_UnInit;
    }

    // Create Dummy Timer Task
    Err = CommonCreateTaskWithArgument(127, (TASKENTRYPOINT)UclALOsIntegrity_Impl_TimerTaskHandler, (Value)pInst,
                                       0x1000, "UclTimer", &pInst->timerTaskId);
    if (Success == Err)
    {
        RunTask(pInst->timerTaskId);
        Ret = UCL_E_OK;
    }

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALOsIntegrity_Impl", "%s", "IUclALOs_Initialize: Success");
    }
    else
    {
        LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_Initialize: Failed %d", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_Shutdown(SUclALOsIntegrityInst *pInst, uint8 InstId)
{
    uint8 i;

    for (i = 0; i < pInst->pCfg->maxTimers; i++)
    {
        if (eUclOsTimerResState_Running == pInst->pCfg->pTimerList[i].state)
        {
            (void)UclALOsIntegrity_Impl_IUclALOs_TimerStop(pInst, InstId, i);
        }

        if ((eUclOsTimerResState_Created == pInst->pCfg->pTimerList[i].state) || (eUclOsTimerResState_Stopped == pInst->pCfg->pTimerList[i].state))
        {
            (void)UclALOsIntegrity_Impl_IUclALOs_TimerDestroy(pInst, InstId, i);
        }
    }

    // Destroy Tasks
    for (i = 0; i < pInst->pCfg->maxTask; i++)
    {
        if (eUclOsTaskResState_Created == pInst->pCfg->pTaskList[i].state)
        {
            (void)UclALOsIntegrity_Impl_IUclALOs_TaskDestroy(pInst, InstId, i);
        }
    }
    return UCL_E_OK;
}

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_Memset(SUclALOsIntegrityInst *pInst, uint8 InstId, void *pBuffer, uint8 val,
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

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_Memcpy(SUclALOsIntegrityInst *pInst, uint8 InstId, void *pDst, void *pSrc,
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

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_Memcmp(SUclALOsIntegrityInst *pInst, uint8 InstId, void *pDst, void *pSrc,
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

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_DisableAllInterrupts(SUclALOsIntegrityInst *pInst, uint8 InstId)
{
    //SuspendAllInterrupts();
    return UCL_E_OK;
}

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_EnableAllInterrupts(SUclALOsIntegrityInst *pInst, uint8 InstId)
{
    //ResumeAllInterrupts();
    return UCL_E_OK;
}

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_MutexCreate(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 *pMutexId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i;
    Error Err;

    // Validate I/P Params
    if (NULL != pMutexId)
    {
        // Get the Available Mutex
        for (i = 0; i < pInst->pCfg->maxMutex; i++)
        {
            if ((eUclOsMutexResState_UnInit == pInst->pCfg->pMutexList[i].state) || (eUclOsMutexResState_Destroyed == pInst->pCfg->pMutexList[i].state))
            {

                Err = CreateLocalMutex(&pInst->pCfg->pMutexList[i].mutex);
                if (Success == Err)
                {
                    *pMutexId = i;
                    pInst->pCfg->pMutexList[i].state = eUclOsMutexResState_Created;
                    Ret = UCL_E_OK;
                    break;
                }
            }
        }
		
		if((i == pInst->pCfg->maxMutex) && (Ret != UCL_E_OK))
		{
			LOGE(0, "UclALOsIntegrity_Impl", "Mutex Count Exhausted. Increase MaxMutex Count");			
		}
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALOsIntegrity_Impl", "%s", "IUclALOs_MutexCreate: Success");
    }
    else
    {
        LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_MutexCreate: Failed %d", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_MutexDestroy(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 MutexId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Error Err;

    // Validate I/P Params
    if (MutexId < pInst->pCfg->maxMutex)
    {
        if ((eUclOsMutexResState_Created == pInst->pCfg->pMutexList[MutexId].state) || (eUclOsMutexResState_UnLocked == pInst->pCfg->pMutexList[MutexId].state))
        {

            Err = CloseLocalMutex(pInst->pCfg->pMutexList[MutexId].mutex);
            if (Success == Err)
            {
                pInst->pCfg->pMutexList[MutexId].state = eUclOsMutexResState_Destroyed;
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

    if (UCL_E_OK != Ret)
    {
        LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_MutexDestroy: Failed %d", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_MutexLock(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 MutexId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Error Err;

    // Validate I/P Params
    if (MutexId < pInst->pCfg->maxMutex)
    {
        if ((eUclOsMutexResState_UnInit != pInst->pCfg->pMutexList[MutexId].state) && (eUclOsMutexResState_Destroyed != pInst->pCfg->pMutexList[MutexId].state))
        {

            Err = WaitForLocalMutex(pInst->pCfg->pMutexList[MutexId].mutex);
            if (Success == Err)
            {
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

    if (UCL_E_OK == Ret)
    {
        pInst->pCfg->pMutexList[MutexId].State = eUclOsMutexResState_Locked;
    }
    else
    {
        LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_MutexLock: Failed %d", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_MutexTryLock(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 MutexId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Error Err;

    // Validate I/P Params
    if (MutexId < pInst->pCfg->maxMutex)
    {
        if ((eUclOsMutexResState_UnInit != pInst->pCfg->pMutexList[MutexId].state) && (eUclOsMutexResState_Destroyed != pInst->pCfg->pMutexList[MutexId].state))
        {

            //Err = WaitForLocalMutex(pInst->pCfg->pMutexList[MutexId].mutex);
            //if (Success == Err)
			if(pInst->pCfg->pMutexList[MutexId].State != eUclOsMutexResState_Locked)
            {
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

    if (UCL_E_OK == Ret)
    {
        pInst->pCfg->pMutexList[MutexId].State = eUclOsMutexResState_Locked;
    }
    else
    {
        LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_MutexTryLock: Failed %d", Ret);
    }

    return Ret;
}
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_MutexUnlock(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 MutexId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Error Err;

    // Validate I/P Params
    if (MutexId < pInst->pCfg->maxMutex)
    {
        if ((eUclOsMutexResState_UnInit != pInst->pCfg->pMutexList[MutexId].state) && (eUclOsMutexResState_Destroyed != pInst->pCfg->pMutexList[MutexId].state))
        {
            // Unlock while the lock is still being held, otherwise race condition may happen
            pInst->pCfg->pMutexList[MutexId].State = eUclOsMutexResState_UnLocked;

            Err = ReleaseLocalMutex(pInst->pCfg->pMutexList[MutexId].mutex);
            if (Success == Err)
            {
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

    if (UCL_E_OK != Ret)
    {
        LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_MutexUnlock: Failed %d", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_TaskCreate(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 *pThreadId,
                                                         TUclOsTaskEntryFunc pFunc, void *pData)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Error Err;
    uint8 i;
    char TaskName[32];

    if ((NULL != pThreadId) && (NULL != pFunc))
    {
        for (i = 0; i < pInst->pCfg->maxTask; i++)
        {
            if ((eUclOsTaskResState_UnInit == pInst->pCfg->pTaskList[i].state) || (eUclOsTaskResState_Destroyed == pInst->pCfg->pTaskList[i].state))
            {
                (void)memset(TaskName, 0x00, 32);
                snprintf(TaskName, 32, "UclTask_%d", i);
                Err = CommonCreateTaskWithArgument(1, (TASKENTRYPOINT)pFunc, (Address)pData, 0x1000, TaskName,
                                                   &pInst->pCfg->pTaskList[i].thread);
                if (Success == Err)
                {
                    *pThreadId = i;
                    pInst->pCfg->pTaskList[i].state = eUclOsTaskResState_Created;
                    Ret = UCL_E_OK;
                    RunTask(pInst->pCfg->pTaskList[i].thread);
                    break;
                }
            }
        }
		
		if((i == pInst->pCfg->maxTask) && (Ret != UCL_E_OK))
		{
			LOGE(0, "UclALOsIntegrity_Impl", "Task Count Exhausted. Increase MaxTask Count");			
		}
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALOsIntegrity_Impl", "%s", "IUclALOs_TaskCreate: Success");
    }
    else
    {
        LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_TaskCreate: Failed %d", Ret);
    }
    return Ret;
}

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_TaskDestroy(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 ThreadId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Error Err;

    // Validate I/P Params
    if (ThreadId < pInst->pCfg->maxTask)
    {
        if (eUclOsTaskResState_Created == pInst->pCfg->pTaskList[ThreadId].state)
        {
            Err = CloseANSICTask(pInst->pCfg->pTaskList[ThreadId].thread);
            if (Success == Err)
            {
                pInst->pCfg->pTaskList[ThreadId].state = eUclOsTaskResState_Destroyed;
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

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALOsIntegrity_Impl", "%s", "IUclALOs_TaskDestroy: Success");
    }
    else
    {
        LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_TaskDestroy: Failed %d", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_SemCreate(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 *pSemId, uint8 Val)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i;
    Error Err;

    // Validate I/P Params
    if (NULL != pSemId)
    {
        // Get the Available Mutex
        for (i = 0; i < pInst->pCfg->maxSem; i++)
        {
            if ((eUclOsSemResState_UnInit == pInst->pCfg->pSemList[i].state) || (eUclOsSemResState_Destroyed == pInst->pCfg->pSemList[i].state))
            {
                Err = CreateSemaphore(Val, &pInst->pCfg->pSemList[i].sem);
                if (Success != Err)
                {
                    LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_SemCreate: CreateSemaphore Failed %d", Err);
                    Ret = UCL_E_NOK;
                }
                else
                {
                    *pSemId = i;

                    pInst->pCfg->pSemList[i].state = eUclOsSemResState_Created;
                    Ret = UCL_E_OK;
                    break;
                }
            }
        }
		
		if((i == pInst->pCfg->maxSem) && (Ret != UCL_E_OK))
		{
			LOGE(0, "UclALOsIntegrity_Impl", "Sem Count Exhausted. Increase MaxSem Count");			
		}
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALOsIntegrity_Impl", "%s", "IUclALOs_SemCreate: Success");
    }
    else
    {
        LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_SemCreate: Failed %d", Ret);
    }
    return Ret;
}

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_SemDestroy(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 SemId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Error Err;

    // Validate I/P Params
    if (SemId < pInst->pCfg->maxSem)
    {
        if (eUclOsSemResState_Created == pInst->pCfg->pSemList[SemId].state)
        {
            Err = CloseSemaphore(pInst->pCfg->pSemList[SemId].sem);
            if (Success != Err)
            {
                LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_SemDestroy: CloseSemaphore Failed %d", Err);
                Ret = UCL_E_NOK;
            }
            else
            {
                pInst->pCfg->pSemList[SemId].state = eUclOsSemResState_Destroyed;
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

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALOsIntegrity_Impl", "%s", "IUclALOs_SemDestroy: Success");
    }
    else
    {
        LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_SemDestroy: Failed %d", Ret);
    }
    return Ret;
}

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_SemWait(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 SemId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Error Err;

    // Validate I/P Params
    if (SemId < pInst->pCfg->maxSem)
    {
        if ((eUclOsSemResState_UnInit != pInst->pCfg->pSemList[SemId].state) && (eUclOsSemResState_Destroyed != pInst->pCfg->pSemList[SemId].state))
        {
            Err = WaitForSemaphore(pInst->pCfg->pSemList[SemId].sem);
            if (Success != Err)
            {
                LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_SemWait: WaitForSemaphore Failed %d", Err);
                Ret = UCL_E_NOK;
            }
            else
            {
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

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALOsIntegrity_Impl", "%s", "IUclALOs_SemWait: Success");
    }
    else
    {
        LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_SemWait: Failed %d", Ret);
    }
    return Ret;
}

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_SemPost(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 SemId)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Error Err;

    // Validate I/P Params
    if (SemId < pInst->pCfg->maxSem)
    {
        if ((eUclOsSemResState_UnInit != pInst->pCfg->pSemList[SemId].state) && (eUclOsSemResState_Destroyed != pInst->pCfg->pSemList[SemId].state))
        {
            Err = ReleaseSemaphore(pInst->pCfg->pSemList[SemId].sem);
            if (Success != Err)
            {
                LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_SemPost: ReleaseSemaphore Failed %d", Err);
                Ret = UCL_E_NOK;
            }
            else
            {
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

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALOsIntegrity_Impl", "%s", "IUclALOs_SemPost: Success");
    }
    else
    {
        LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_SemPost: Failed %d", Ret);
    }
    return Ret;
}

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_TimerCreate(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 *pTimerId,
                                                          TUclOsTaskEntryFunc pFunc, void *pData, EUclOsTimerType TimerType)
{
    SUclALOsIntegrityCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret = UCL_E_NOK;
    Error Err;
    uint8 i;

    // Validate Arguments
    if ((NULL != pTimerId) || (NULL != pFunc) || (NULL != pData) || (eUclOsTimerType_Last > TimerType))
    {
        // Find a free Timers
        for (i = 0; i < pCfg->maxTimers; i++)
        {
            if ((eUclOsTimerResState_UnInit == pCfg->pTimerList[i].state) || (eUclOsTimerResState_Destroyed == pCfg->pTimerList[i].state))
            {

                Err = CreateVirtualClock(HighestResStandardClock, CLOCK_READTIME | CLOCK_ALARM,
                                         &pInst->pCfg->pTimerList[i].alarmClock);
                if (Success != Err)
                {
                    LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_TimerCreate: Create Virtual Clock Failed %d", Err);
                    break;
                }

                Err = CreateActivity(pInst->timerTaskId, 2, false, (Value)i,
                                     &pInst->pCfg->pTimerList[i].timerActivity);
                if (Success != Err)
                {
                    LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_TimerCreate: Create Activity Failed %d", Err);
                    break;
                }

                pCfg->pTimerList[i].pFunc = pFunc;
                pCfg->pTimerList[i].pData = pData;
                pCfg->pTimerList[i].type = TimerType;
                pCfg->pTimerList[i].count = 0;
                pCfg->pTimerList[i].state = eUclOsTimerResState_Created;

                *pTimerId = i;
                Ret = UCL_E_OK;
                break;
            }
        }
		
		if((i == pInst->pCfg->maxTimers) && (Ret != UCL_E_OK))
		{
			LOGE(0, "UclALOsIntegrity_Impl", "Timer Count Exhausted. Increase MaxTimers Count");			
		}
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (UCL_E_OK == Ret)
    {
        LOGI(0, "UclALOsIntegrity_Impl", "%s", "IUclALOs_TimerCreate: Success");
    }
    else
    {
        LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_TimerCreate: Failed %d", Ret);
    }

    return Ret;
}

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_TimerStart(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 TimerId, uint32 Timeout)
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Time AlarmTime;
    Error Err;
    uint64 Fraction;

    // Validate I/P Params
    if (TimerId < pInst->pCfg->maxTimers)
    {
        if ((eUclOsTimerResState_Created == pInst->pCfg->pTimerList[TimerId].state) || (eUclOsTimerResState_Stopped == pInst->pCfg->pTimerList[TimerId].state))
        {

            Err = AsynchronousReceive(pInst->pCfg->pTimerList[TimerId].timerActivity,
                                      (Object)pInst->pCfg->pTimerList[TimerId].alarmClock, NULL);

            if (Success == Err)
            {
                pInst->pCfg->pTimerList[TimerId].timeout = Timeout;

                AlarmTime.Seconds = 0;
                if (Timeout >= 1000)
                {
                    AlarmTime.Seconds = (Timeout / 1000);
                    Fraction = Timeout - (AlarmTime.Seconds * 1000);
                }
                else
                {
                    Fraction = Timeout;
                }

                AlarmTime.Fraction = (uint32)((Fraction << 32) / 1000);

                if (eUclOsTimerType_Periodic == pInst->pCfg->pTimerList[TimerId].type)
                {
                    Err = SetClockAlarm(pInst->pCfg->pTimerList[TimerId].alarmClock, true, NULLTime, &AlarmTime);
                }
                else
                {
                    Err = SetClockAlarm(pInst->pCfg->pTimerList[TimerId].alarmClock, false, NULLTime, &AlarmTime);
                }

                if (Success == Err)
                {
                    pInst->pCfg->pTimerList[TimerId].state = eUclOsTimerResState_Running;
                    Ret = UCL_E_OK;
                }
                else
                {
                    LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_TimerStart: SetClockAlarm Failed %d", Err);
                    Ret = UCL_E_NOK;
                }
            }
            else
            {
                LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_TimerStart: AsynchronousReceive Failed %d", Err);
                Ret = UCL_E_NOK;
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
        LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_TimerStart Failed %d\n", Ret);
    }
    else
    {
        LOGI(0, "UclALOsIntegrity_Impl", "%s" "IUclALOs_TimerStart Success\n");
    }

    return Ret;
}

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_TimerStop(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 TimerId)
{
    SUclALOsIntegrityCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret = UCL_E_NOK;
    Error Err;

    if (TimerId < pCfg->maxTimers)
    {
        if (eUclOsTimerResState_Running == pCfg->pTimerList[TimerId].state)
        {
            Err = ResetActivity(pInst->pCfg->pTimerList[TimerId].timerActivity);
            if (Success == Err)
            {
                Err = SetClockAlarm(pInst->pCfg->pTimerList[TimerId].alarmClock, false, NULLTime, NULLTime);
                if (Success == Err)
                {
                    pCfg->pTimerList[TimerId].state = eUclOsTimerResState_Stopped;
                    pCfg->pTimerList[TimerId].count = 0;
                    Ret = UCL_E_OK;
                }
            }
        }
        else if ((eUclOsTimerResState_Stopped == pCfg->pTimerList[TimerId].state) || (eUclOsTimerResState_Created == pCfg->pTimerList[TimerId].state))
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
        LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_TimerStop Failed %d\n", Ret);
    }
    else
    {
        LOGI(0, "UclALOsIntegrity_Impl", "%s", "IUclALOs_TimerStop Success\n");
    }
    return Ret;
}

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_TimerDestroy(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 TimerId)
{
    SUclALOsIntegrityCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret = UCL_E_NOK;
    Error Err;

    if (TimerId < pCfg->maxTimers)
    {
        if (eUclOsTimerResState_UnInit != pCfg->pTimerList[TimerId].state)
        {
            Err = CloseActivity(pInst->pCfg->pTimerList[TimerId].timerActivity);
            if (Success == Err)
            {
                Err = CloseClock(pInst->pCfg->pTimerList[TimerId].alarmClock);
                if (Success == Err)
                {
                    Ret = UCL_E_OK;
                }
            }
            pCfg->pTimerList[TimerId].state = eUclOsTimerResState_Destroyed;
            pCfg->pTimerList[TimerId].count = 0;
            pCfg->pTimerList[TimerId].pFunc = NULL;
            pCfg->pTimerList[TimerId].pData = NULL;
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
        LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_TimerDestroy Failed %d\n", Ret);
    }
    else
    {
        LOGI(0, "UclALOsIntegrity_Impl", "%s", "IUclALOs_TimerDestroy Success\n");
    }

    return Ret;
}

uint64 UclALOsIntegrity_Impl_IUclALOs_GetSystemTimeMs(SUclALOsIntegrityInst *pInst, uint8 InstId)
{
    Time currentTime;
    uint64 currentTimeInMs = 0;
    Error Err;

    currentTime.Fraction = 0;
    currentTime.Seconds = 0;

    Err = GetClockTime(HighestResStandardClock, &currentTime);
    if (Success == Err)
    {
        currentTimeInMs = (uint64)(currentTime.Seconds * 1000) + (uint64)(currentTime.Fraction * 1000ULL / (1ULL << 32));
    }
    return currentTimeInMs;
}

uint32 UclALOsIntegrity_Impl_IUclALOs_GetSystemTimeResolutionMs(SUclALOsIntegrityInst *pInst, uint8 InstId)
{
    return 1u;
}

void UclALOsIntegrity_Impl_IUclALOs_Tick(SUclALOsIntegrityInst *pInst, uint8 InstId)
{
}

static Value UclALOsIntegrity_Impl_TimerTaskHandler(Address arg)
{
    SUclALOsIntegrityInst *pInst = (SUclALOsIntegrityInst *)arg;
    SUclALOsIntegrityTimerList *pTimer;
    Value Id;
    Error Err;

    while (1)
    {
        WaitForActivityAndReturnStatus(&Id, &Err);

        if (Id < pInst->pCfg->maxTimers)
        {
            pTimer = &pInst->pCfg->pTimerList[Id];
            if (eUclOsTimerResState_Running == pTimer->state)
            {
                if (eUclOsTimerType_OneShot == pTimer->type)
                {
                    pTimer->state = eUclOsTimerResState_Stopped;
                }
                else
                {
                    Err = AsynchronousReceive(pTimer->timerActivity, (Object)pTimer->alarmClock, NULL);
                    if (Success != Err)
                    {
                        LOGE(0, "UclALOsIntegrity_Impl", "IUclALOs_TimerCreate: AsynchronousReceive Failed %d", Err);
                    }
                }
                // Trigger the callback
                (void)(pTimer->pFunc)(pTimer->pData);
            }
        }
    }
}
