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
#include "UclALOsVlite_Impl.h"
#include <string.h>

#define EI() __asm("ei")
#define DI() __asm("di")

static void UclALOsVlite_Impl_TimerProcess(SUclALOsVliteInst *pInst, uint8 InstId);

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_Initialize(SUclALOsVliteInst *pInst, uint8 InstId)
{
    SUclALOsVliteCfg *pCfg = pInst->pCfg;
    uint8 i;

    // Initialize Timers
    for (i = 0; i < pCfg->maxTimers; i++)
    {
        pCfg->pTimerList[i].state = eUclOsTimerResState_UnInit;
    }
    return UCL_E_OK;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_Shutdown(SUclALOsVliteInst *pInst, uint8 InstId)
{
    return UCL_E_OK;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_Memset(SUclALOsVliteInst *pInst, uint8 InstId, void *pBuffer, uint8 val,
                                                 uint32 size)
{
    (void)memset(pBuffer, (sint32)val, size);
    return UCL_E_OK;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_Memcpy(SUclALOsVliteInst *pInst, uint8 InstId, void *pDst, void *pSrc,
                                                 uint32 Size)
{
    (void)memcpy(pDst, pSrc, Size);
    return UCL_E_OK;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_Memcmp(SUclALOsVliteInst *pInst, uint8 InstId, void *pDst, void *pSrc,
                                                 uint32 Size)
{
    Ucl_ReturnType Ret=UCL_E_NOK;

    if ((NULL != pDst) && (NULL != pSrc) && (0u < Size))
    {
        if ((memcmp(pDst, pSrc, Size))==((sint8)0))
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

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_DisableAllInterrupts(SUclALOsVliteInst *pInst, uint8 InstId)
{

	//disable_interrupts();
    return UCL_E_OK;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_EnableAllInterrupts(SUclALOsVliteInst *pInst, uint8 InstId)
{

	//enable_interrupts();
    return UCL_E_OK;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_MutexCreate(SUclALOsVliteInst *pInst, uint8 InstId, uint32 *pMutexId)
{
    return UCL_E_OK;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_MutexDestroy(SUclALOsVliteInst *pInst, uint8 InstId, uint32 MutexId)
{
    return UCL_E_OK;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_TaskCreate(SUclALOsVliteInst *pInst, uint8 InstId, uint32 *pThreadId,
                                                     TUclOsTaskEntryFunc pFunc, void *pData)
{

    return UCL_E_OK;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_TaskDestroy(SUclALOsVliteInst *pInst, uint8 InstId, uint32 ThreadId)
{
    return UCL_E_OK;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_MutexLock(SUclALOsVliteInst *pInst, uint8 InstId, uint32 MutexId)
{

    return UCL_E_OK;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_MutexTryLock(SUclALOsVliteInst *pInst, uint8 InstId, uint32 MutexId)
{

    return UCL_E_OK;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_MutexUnlock(SUclALOsVliteInst *pInst, uint8 InstId, uint32 MutexId)
{
    return UCL_E_OK;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_SemCreate(SUclALOsVliteInst *pInst, uint8 InstId, uint32 *pSemId, uint8 Val)
{
    return UCL_E_OK;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_SemDestroy(SUclALOsVliteInst *pInst, uint8 InstId, uint32 SemId)
{
    return UCL_E_OK;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_SemWait(SUclALOsVliteInst *pInst, uint8 InstId, uint32 SemId)
{
    return UCL_E_OK;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_SemPost(SUclALOsVliteInst *pInst, uint8 InstId, uint32 SemId)
{
    return UCL_E_OK;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_TimerCreate(SUclALOsVliteInst *pInst, uint8 InstId, uint32 *pTimerId,
                                                      TUclOsTaskEntryFunc pFunc, void *pData, EUclOsTimerType TimerType)
{
    SUclALOsVliteCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i;

    // Validate Arguments
    if ((NULL != pTimerId) && (NULL != pFunc) && (NULL != pData) && (eUclOsTimerType_Last > TimerType))
    {
        // Find a free Timers
        for (i = 0; i < pCfg->maxTimers; i++)
        {
            if ((eUclOsTimerResState_UnInit == pCfg->pTimerList[i].state) || (eUclOsTimerResState_Destroyed == pCfg->pTimerList[i].state))
            {
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
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    return Ret;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_TimerStart(SUclALOsVliteInst *pInst, uint8 InstId, uint32 TimerId, uint32 Timeout)
{
    SUclALOsVliteCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret = UCL_E_NOK;

    if (TimerId < pCfg->maxTimers)
    {
        if ((eUclOsTimerResState_Created == pCfg->pTimerList[TimerId].state) || (eUclOsTimerResState_Stopped == pCfg->pTimerList[TimerId].state))
        {
            pCfg->pTimerList[TimerId].state = eUclOsTimerResState_Running;

            if (Timeout < pCfg->tickResolutionMs)
            {
                pCfg->pTimerList[TimerId].timeout = 1;
            }
            else
            {
                pCfg->pTimerList[TimerId].timeout = Timeout / pCfg->tickResolutionMs;
            }

            pCfg->pTimerList[TimerId].count = 0;

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
    return Ret;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_TimerStop(SUclALOsVliteInst *pInst, uint8 InstId, uint32 TimerId)
{
    SUclALOsVliteCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret = UCL_E_NOK;

    if (TimerId < pCfg->maxTimers)
    {
        if (eUclOsTimerResState_Running == pCfg->pTimerList[TimerId].state)
        {
            pCfg->pTimerList[TimerId].state = eUclOsTimerResState_Stopped;
            pCfg->pTimerList[TimerId].count = 0;
            Ret = UCL_E_OK;
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
    return Ret;
}

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_TimerDestroy(SUclALOsVliteInst *pInst, uint8 InstId, uint32 TimerId)
{
    SUclALOsVliteCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret = UCL_E_NOK;

    if (TimerId < pCfg->maxTimers)
    {
        if (eUclOsTimerResState_UnInit != pCfg->pTimerList[TimerId].state)
        {
            pCfg->pTimerList[TimerId].state = eUclOsTimerResState_Destroyed;
            pCfg->pTimerList[TimerId].count = 0;
            pCfg->pTimerList[TimerId].pFunc = NULL;
            pCfg->pTimerList[TimerId].pData = NULL;
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
    return Ret;
}

uint64 UclALOsVlite_Impl_IUclALOs_GetSystemTimeMs(SUclALOsVliteInst *pInst, uint8 InstId)
{
    return (pInst->elapsedTicksInMs * pInst->pCfg->tickResolutionMs);
}

uint32 UclALOsVlite_Impl_IUclALOs_GetSystemTimeResolutionMs(SUclALOsVliteInst *pInst, uint8 InstId)
{
    return pInst->pCfg->tickResolutionMs;
}

void UclALOsVlite_Impl_IUclALOs_Tick(SUclALOsVliteInst *pInst, uint8 InstId)
{
    pInst->elapsedTicksInMs++;
    UclALOsVlite_Impl_TimerProcess(pInst, InstId);
}

static void UclALOsVlite_Impl_TimerProcess(SUclALOsVliteInst *pInst, uint8 InstId)
{
    SUclALOsVliteCfg *pCfg = pInst->pCfg;
    uint8 i;

    for (i = 0; i < pCfg->maxTimers; i++)
    {
        if (eUclOsTimerResState_Running == pCfg->pTimerList[i].state)
        {
            pCfg->pTimerList[i].count++;

            if (pCfg->pTimerList[i].count >= pCfg->pTimerList[i].timeout)
            {
                pCfg->pTimerList[i].count = 0;

                if (eUclOsTimerType_OneShot == pCfg->pTimerList[i].type)
                {
                    pCfg->pTimerList[i].state = eUclOsTimerResState_Stopped;
                }

                // Trigger the callback
                (void)(pCfg->pTimerList[i].pFunc)(pCfg->pTimerList[i].pData);
            }
        }
    }
}
