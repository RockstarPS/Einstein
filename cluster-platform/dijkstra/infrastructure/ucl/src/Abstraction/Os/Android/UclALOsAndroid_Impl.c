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
#include "UclALOsAndroid_Impl.h"
#include "UclALDebug.h"
#include <string.h>
#include <math.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

static void *UclALOsAndroid_Impl_SignalListenerThread(void *pData);
static void *UclALOsAndroid_Impl_SignalActionThread(void *pData);

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_Initialize( SUclALOsAndroidInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret = UCL_E_OK;
    uint8 i;
    sigset_t oldsigmask;
    sint32 ret;

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
    pInst->isListenerUp = FALSE;
    (void)sigemptyset(&(pInst->newsigmask));
    for (i = 0; i < pInst->pCfg->MaxTimers; i++)
    {
        pInst->pCfg->pTimerList[i].State = eUclOsTimerResState_UnInit;
        pInst->pCfg->pTimerList[i].pFunc = NULL;
        pInst->pCfg->pTimerList[i].pData = NULL;
        pInst->pCfg->pTimerList[i].Type = eUclOsTimerType_Last;
        pInst->pCfg->pTimerList[i].sig = SIGRTMIN + i;
        (void)sigaddset(&(pInst->newsigmask), pInst->pCfg->pTimerList[i].sig);
    }

    ret = pthread_sigmask(SIG_BLOCK, &(pInst->newsigmask), &oldsigmask);
    if (0 != ret)
    {
        Ret = UCL_E_NOK;
        LOGE(0, "UclALOsAndroid_Impl", "pthread_sigmask: Failed %d", ret);
    }

    // Initialize Semaphores
    if (UCL_E_OK == Ret)
    {
        for (i = 0; i < pInst->pCfg->MaxSem; i++)
        {
            pInst->pCfg->pSemList[i].State = eUclOsSemResState_UnInit;
        }

        //Create Signal listener thread
        pInst->isListenerUp = TRUE;
        ret = pthread_create(&pInst->sig_listener, NULL, &UclALOsAndroid_Impl_SignalListenerThread, pInst);
        if (ret != 0)
        {
            Ret = UCL_E_NOK;
            LOGE(0, "UclALOsAndroid_Impl", "IUclALOs_Initialize: SignalListenerThread Create Failed %d", ret);
        }
        else
        {
            pthread_detach(pInst->sig_listener);

            LOGI(0, "UclALOsAndroid_Impl", "%s", "IUclALOs_Initialize: SignalListenerThread Create Success");
        }
    }

    if (UCL_E_OK == Ret)
    {
        LOGI( 0, "UclALOsAndroid_Impl", "%s", "IUclALOs_Initialize: Success" );
    }
    else
    {
        LOGE( 0, "UclALOsAndroid_Impl", "IUclALOs_Initialize: Failed %d", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_Shutdown( SUclALOsAndroidInst *pInst, uint8 InstId )
{
    uint8 i;

    // Destroy Timers
    for (i = 0; i < pInst->pCfg->MaxTimers; i++)
    {
        if (eUclOsTimerResState_Running == pInst->pCfg->pTimerList[i].State)
        {
            (void) UclALOsAndroid_Impl_IUclALOs_TimerStop( pInst, InstId, i );
        }

        if ((eUclOsTimerResState_Created == pInst->pCfg->pTimerList[i].State)
                || (eUclOsTimerResState_Stopped == pInst->pCfg->pTimerList[i].State))
        {
            (void) UclALOsAndroid_Impl_IUclALOs_TimerDestroy( pInst, InstId, i );
        }
    }

    //Exit the Signal Listener Thread
    pInst->isListenerUp = FALSE;

    // Destroy Tasks
    for (i = 0; i < pInst->pCfg->MaxTask; i++)
    {
        (void)UclALOsAndroid_Impl_IUclALOs_TaskDestroy(pInst, InstId, i);
    }

    //Release all the mutexes if not released already
    for (i = 0; i < pInst->pCfg->MaxMutex; i++)
    {
        (void)UclALOsAndroid_Impl_IUclALOs_MutexDestroy(pInst, InstId, i);
    }

    //Release all the semaphores if not released already
    for (i = 0; i < pInst->pCfg->MaxSem; i++)
    {
        (void)UclALOsAndroid_Impl_IUclALOs_SemDestroy(pInst, InstId, i);
    }

    return UCL_E_OK;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_Memset( SUclALOsAndroidInst *pInst, uint8 InstId, void *pBuffer, uint8 val,
        uint32 Size )
{
    Ucl_ReturnType Ret;

    if ((NULL != pBuffer) && (0 < Size))
    {
        (void) memset( pBuffer, val, Size );
        Ret = UCL_E_OK;
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    return Ret;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_Memcpy( SUclALOsAndroidInst *pInst, uint8 InstId, void *pDst, void *pSrc,
        uint32 Size )
{
    Ucl_ReturnType Ret;

    if ((NULL != pDst) && (NULL != pSrc) && (0 < Size))
    {
        (void) memcpy( pDst, pSrc, Size );
        Ret = UCL_E_OK;
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    return Ret;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_Memcmp( SUclALOsAndroidInst *pInst, uint8 InstId, void *pDst, void *pSrc,
        uint32 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ((NULL != pDst) && (NULL != pSrc) && (0 < Size))
    {
        if ((memcmp( pDst, pSrc, Size )) == ((int) 0))
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

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_DisableAllInterrupts( SUclALOsAndroidInst *pInst, uint8 InstId )
{
    // Not Applicable
    return UCL_E_NOK;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_EnableAllInterrupts( SUclALOsAndroidInst *pInst, uint8 InstId )
{
    // Not Applicable
    return UCL_E_NOK;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_MutexCreate( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 *pMutexId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i;
    pthread_mutexattr_t attr;

    // Validate I/P Params
    if (NULL != pMutexId)
    {
        // Get the Available Mutex
        for (i = 0; i < pInst->pCfg->MaxMutex; i++)
        {
            if ((eUclOsMutexResState_UnInit == pInst->pCfg->pMutexList[i].State)
                    || (eUclOsMutexResState_Destroyed == pInst->pCfg->pMutexList[i].State))
            {
                (void) pthread_mutexattr_init( &attr );

                (void) pthread_mutexattr_settype( &attr, PTHREAD_MUTEX_RECURSIVE );

                if (0 == pthread_mutex_init( &pInst->pCfg->pMutexList[i].mutex, &attr ))
                {
                    *pMutexId = i;

                    pInst->pCfg->pMutexList[i].State = eUclOsMutexResState_Created;
                    Ret = UCL_E_OK;

                    break;
                }
                else
                {
                    LOGE( 0, "UclALOsAndroid_Impl", "pthread_mutex_init: Failed %s", strerror( errno ) );
                }
            }
        }

        if((i == pInst->pCfg->MaxMutex) && (Ret != UCL_E_OK))
        {
            LOGE( 0, "UclALOsAndroid_Impl", "Mutex Exhausted. Increase MaxMutex Count" );
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (UCL_E_OK == Ret)
    {
        LOGI( 0, "UclALOsAndroid_Impl", "%s", "IUclALOs_MutexCreate: Success" );
    }
    else
    {
        LOGE( 0, "UclALOsAndroid_Impl", "IUclALOs_MutexCreate: Failed %d", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_MutexDestroy( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 MutexId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if (MutexId < pInst->pCfg->MaxMutex)
    {
        if ((eUclOsMutexResState_Created == pInst->pCfg->pMutexList[MutexId].State)
                || (eUclOsMutexResState_UnLocked == pInst->pCfg->pMutexList[MutexId].State))
        {
            if (0 == pthread_mutex_destroy( &pInst->pCfg->pMutexList[MutexId].mutex ))
            {
                pInst->pCfg->pMutexList[MutexId].State = eUclOsMutexResState_Destroyed;
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE( 0, "UclALOsAndroid_Impl", "pthread_mutex_destroy: Failed" );
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
        LOGI( 0, "UclALOsAndroid_Impl", "%s", "IUclALOs_MutexDestroy: Success" );
    }
    else
    {
        LOGE( 0, "UclALOsAndroid_Impl", "IUclALOs_MutexDestroy: Failed %d", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_MutexLock( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 MutexId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if (MutexId < pInst->pCfg->MaxMutex)
    {
        if ((eUclOsMutexResState_UnInit != pInst->pCfg->pMutexList[MutexId].State)
                && (eUclOsMutexResState_Destroyed != pInst->pCfg->pMutexList[MutexId].State))
        {
            if (0 == pthread_mutex_lock( &pInst->pCfg->pMutexList[MutexId].mutex ))
            {
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE( 0, "UclALOsAndroid_Impl", "%s", "pthread_mutex_lock: Failed" );
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
        LOGE( 0, "UclALOsAndroid_Impl", "IUclALOs_MutexLock: Failed %d", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_MutexTryLock( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 MutexId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    int LockStatus = 0;

    // Validate I/P Params
    if (MutexId < pInst->pCfg->MaxMutex)
    {
        if ((eUclOsMutexResState_UnInit != pInst->pCfg->pMutexList[MutexId].State)
                && (eUclOsMutexResState_Destroyed != pInst->pCfg->pMutexList[MutexId].State))
        {
            LockStatus = pthread_mutex_trylock( &pInst->pCfg->pMutexList[MutexId].mutex );
            if (0 == LockStatus)
            {
                Ret = UCL_E_OK;
            }
            else
            {
                if (LockStatus != EBUSY)
                {
                    LOGE( 0, "UclALOsAndroid_Impl", "pthread_mutex_trylock: Failed %d \n", LockStatus );
                }
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

    return Ret;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_MutexUnlock( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 MutexId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if (MutexId < pInst->pCfg->MaxMutex)
    {
        if ((eUclOsMutexResState_UnInit != pInst->pCfg->pMutexList[MutexId].State)
                && (eUclOsMutexResState_Destroyed != pInst->pCfg->pMutexList[MutexId].State))
        {
            // Unlock while the lock is still being held, otherwise race condition may happen
            pInst->pCfg->pMutexList[MutexId].State = eUclOsMutexResState_UnLocked;

            if (0 == pthread_mutex_unlock( &pInst->pCfg->pMutexList[MutexId].mutex ))
            {
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE( 0, "UclALOsAndroid_Impl", "%s", "pthread_mutex_unlock: Failed" );
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
        LOGE( 0, "UclALOsAndroid_Impl", "IUclALOs_MutexUnlock: Failed %d", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_TaskCreate( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 *pThreadId,
        TUclOsTaskEntryFunc pFunc, void *pData )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i;

    if ((NULL != pThreadId) && (NULL != pFunc))
    {
        for (i = 0; i < pInst->pCfg->MaxTask; i++)
        {
            if ((eUclOsTaskResState_UnInit == pInst->pCfg->pTaskList[i].State)
                    || (eUclOsTaskResState_Destroyed == pInst->pCfg->pTaskList[i].State))
            {

                if (0 == pthread_create( &pInst->pCfg->pTaskList[i].thread, NULL, pFunc, pData ))
                {
                    pthread_detach(pInst->pCfg->pTaskList[i].thread);
                    *pThreadId = i;
                    pInst->pCfg->pTaskList[i].State = eUclOsTaskResState_Created;
                    Ret = UCL_E_OK;
                    break;
                }
                else
                {
                    LOGE( 0, "UclALOsAndroid_Impl", "pthread_create: Failed %s", strerror( errno ) );
                }
            }
        }

        if((i == pInst->pCfg->MaxTask) && (Ret != UCL_E_OK))
        {
            LOGE(0, "UclALOsAndroid_Impl", "Task Count Exhausted. Increase MaxTask Count");
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (UCL_E_OK == Ret)
    {
        LOGI( 0, "UclALOsAndroid_Impl", "%s", "IUclALOs_TaskCreate: Success" );
    }
    else
    {
        LOGE( 0, "UclALOsAndroid_Impl", "IUclALOs_TaskCreate: Failed %d", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_TaskDestroy( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 ThreadId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if (ThreadId < pInst->pCfg->MaxTask)
    {
        if (eUclOsTaskResState_Created == pInst->pCfg->pTaskList[ThreadId].State)
        {
            pInst->pCfg->pTaskList[ThreadId].State = eUclOsTaskResState_Destroyed;
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

    if (UCL_E_OK == Ret)
    {
        LOGI( 0, "UclALOsAndroid_Impl", "%s", "IUclALOs_TaskDestroy: Success" );
    }
    else
    {
        LOGE( 0, "UclALOsAndroid_Impl", "IUclALOs_TaskDestroy: Failed %d", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_TimerCreate( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 *pTimerId,
        TUclOsTaskEntryFunc pFunc, void *pData, EUclOsTimerType TimerType )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i;
    sint32 ret;
    struct sigevent timer_action;

    /* Validate I/P Params */
    if ((NULL != pTimerId) && (NULL != pFunc) && (NULL != pData) && (eUclOsTimerType_Last > TimerType))
    {
        for (i = 0; i < pInst->pCfg->MaxTimers; i++)
        {
            // if ((eUclOsTimerResState_UnInit == pInst->pCfg->pTimerList[i].State) || (eUclOsTimerResState_Destroyed == pInst->pCfg->pTimerList[i].State))
            if (eUclOsTimerResState_UnInit == pInst->pCfg->pTimerList[i].State)
            {
                if (sem_init(&(pInst->pCfg->pTimerList[i].sem), 0, 0) < 0)
                {
                    LOGE(0, "UclALOsAndroid_Impl", "IUclALOs_TimerCreate: sem_init: Failed %s", strerror(errno));
                }
                else
                {
                    pInst->pCfg->pTimerList[i].pData = pData;
                    pInst->pCfg->pTimerList[i].pFunc = pFunc;
                    pInst->pCfg->pTimerList[i].Type = TimerType;

                    timer_action.sigev_notify = SIGEV_SIGNAL;
                    timer_action.sigev_signo = pInst->pCfg->pTimerList[i].sig;
                    timer_action.sigev_notify_attributes = NULL;

                    if (0 == timer_create(CLOCK_MONOTONIC, &timer_action, &pInst->pCfg->pTimerList[i].timer))
                    {
                        //Create Signal Action Thread
                        ret = pthread_create(&(pInst->pCfg->pTimerList[i].thread_id), NULL, &UclALOsAndroid_Impl_SignalActionThread, &(pInst->pCfg->pTimerList[i]));
                        if ( ret == 0)
                        {
                            pthread_detach(pInst->pCfg->pTimerList[i].thread_id);
                            pInst->pCfg->pTimerList[i].State = eUclOsTimerResState_Created;
                            *pTimerId = i;
                            Ret = UCL_E_OK;
                        }
                        else
                        {
                            //Destroy the created timer
                            (void)timer_delete(pInst->pCfg->pTimerList[i].timer);
                            LOGE(0, "UclALOsAndroid_Impl", "IUclALOs_TimerStart: SignalActionThread Create Failed %d for sig %d", ret, pInst->pCfg->pTimerList[i].sig);
                        }
                        break;
                    }
                    else
                    {
                        LOGE(0, "UclALOsAndroid_Impl", "IUclALOs_TimerCreate: timer_create: Failed %s", strerror(errno));
                    }
                }
            }
        }

        if((i == pInst->pCfg->MaxTimers) && (Ret != UCL_E_OK))
        {
            LOGE(0, "UclALOsAndroid_Impl", "IUclALOs_TimerCreate: Timer Count Exhausted. Increase MaxTimers Count");
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (UCL_E_OK == Ret)
    {
        LOGI( 0, "UclALOsAndroid_Impl", "%s", "IUclALOs_TimerCreate: Success" );
    }
    else
    {
        LOGE( 0, "UclALOsAndroid_Impl", "IUclALOs_TimerCreate: Failed %d", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_TimerStart( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 TimerId,
        uint32 Timeout )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    struct itimerspec TimerSpec;

    // Validate I/P Params
    if (TimerId < pInst->pCfg->MaxTimers)
    {
        if ((eUclOsTimerResState_Created == pInst->pCfg->pTimerList[TimerId].State) || (eUclOsTimerResState_Stopped == pInst->pCfg->pTimerList[TimerId].State))
        {
            (void)memset((void *)&TimerSpec, 0, sizeof(TimerSpec));

            pInst->pCfg->pTimerList[TimerId].Timeout = Timeout;

            TimerSpec.it_value.tv_sec = 0;
            TimerSpec.it_value.tv_nsec = (pInst->pCfg->pTimerList[TimerId].Timeout * 1000000);

            if (eUclOsTimerType_Periodic == pInst->pCfg->pTimerList[TimerId].Type)
            {
                TimerSpec.it_interval.tv_sec = 0;
                TimerSpec.it_interval.tv_nsec = (pInst->pCfg->pTimerList[TimerId].Timeout * 1000000);
            }

            if (0 == timer_settime(pInst->pCfg->pTimerList[TimerId].timer, 0, &TimerSpec, NULL))
            {
                pInst->pCfg->pTimerList[TimerId].State = eUclOsTimerResState_Running;
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE(0, "UclALOsAndroid_Impl", "IUclALOs_TimerStart: timer_settime: Failed %s", strerror(errno));
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
        LOGE( 0, "UclALOsAndroid_Impl", "IUclALOs_TimerStart Failed %d\n", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_TimerStop( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 TimerId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    struct itimerspec TimerSpec;

    // Validate I/P Params
    if (TimerId < pInst->pCfg->MaxTimers)
    {
        if (eUclOsTimerResState_Running == pInst->pCfg->pTimerList[TimerId].State)
        {
            (void) memset( (void *) &TimerSpec, 0, sizeof(TimerSpec) );

            if (0 == timer_settime( pInst->pCfg->pTimerList[TimerId].timer, 0, &TimerSpec, NULL ))
            {
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE( 0, "UclALOsAndroid_Impl", "timer_settime: Failed %s", strerror( errno ) );
            }

            pInst->pCfg->pTimerList[TimerId].State = eUclOsTimerResState_Stopped;
        }
        else if ((eUclOsTimerResState_Stopped == pInst->pCfg->pTimerList[TimerId].State)
                 || (eUclOsTimerResState_Created == pInst->pCfg->pTimerList[TimerId].State))
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
        LOGE( 0, "UclALOsAndroid_Impl", "IUclALOs_TimerStop Failed %d\n", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_TimerDestroy( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 TimerId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    int WaitCount = 10;

    // Validate I/P Params
    if (TimerId < pInst->pCfg->MaxTimers)
    {
        if ((eUclOsTimerResState_Created == pInst->pCfg->pTimerList[TimerId].State)
                || (eUclOsTimerResState_Stopped == pInst->pCfg->pTimerList[TimerId].State))
        {
            (void) timer_delete( pInst->pCfg->pTimerList[TimerId].timer );
            pInst->pCfg->pTimerList[TimerId].State = eUclOsTimerResState_Destroyed;

            if(sem_post(&(pInst->pCfg->pTimerList[TimerId].sem)) == 0)
            {
                while((pInst->pCfg->pTimerList[TimerId].State != eUclOsTimerResState_UnInit) && (WaitCount))
                {
                    //Signal Action Thread is expected to be exited in 1ms of destroying the timer
                    usleep(100);
                    WaitCount--;
                }

                if(pInst->pCfg->pTimerList[TimerId].State != eUclOsTimerResState_UnInit)
                {
                    LOGE(0, "UclALOsAndroid_Impl", "IUclALOs_TimerDestroy SignalActionThread of Timer %d forcefully exited\n", TimerId);
                    pInst->pCfg->pTimerList[TimerId].State = eUclOsTimerResState_UnInit;
                }

                pInst->pCfg->pTimerList[TimerId].Timeout = 0;
                pInst->pCfg->pTimerList[TimerId].pData = NULL;
                pInst->pCfg->pTimerList[TimerId].pFunc = NULL;
                pInst->pCfg->pTimerList[TimerId].Type = eUclOsTimerType_Last;

                //Destroy the sem blocked by Signal Action Thread after the thread exited
                (void)sem_destroy(&pInst->pCfg->pTimerList[TimerId].sem);
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
        LOGE( 0, "UclALOsAndroid_Impl", "IUclALOs_TimerDestroy Failed %d\n", Ret );
    }
    return Ret;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_SemCreate( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 *pSemId, uint8 Val )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i;

    // Validate I/P Params
    if (NULL != pSemId)
    {
        // Get the Available Mutex
        for (i = 0; i < pInst->pCfg->MaxSem; i++)
        {
            if ((eUclOsSemResState_UnInit == pInst->pCfg->pSemList[i].State)
                    || (eUclOsSemResState_Destroyed == pInst->pCfg->pSemList[i].State))
            {
                if (sem_init( &pInst->pCfg->pSemList[i].sem, 0, Val ) < 0)
                {
                    LOGE( 0, "UclALOsAndroid_Impl", "sem_init: Failed %s", strerror( errno ) );
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
            LOGE(0, "UclALOsAndroid_Impl", "Sem Count Exhausted. Increase MaxSem Count");
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if (UCL_E_OK == Ret)
    {
        LOGI( 0, "UclALOsAndroid_Impl", "%s", "IUclALOs_SemCreate: Success" );
    }
    else
    {
        LOGE( 0, "UclALOsAndroid_Impl", "IUclALOs_SemCreate: Failed %d", Ret );
    }
    return Ret;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_SemDestroy( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 SemId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if (SemId < pInst->pCfg->MaxSem)
    {
        if (eUclOsSemResState_Created == pInst->pCfg->pSemList[SemId].State)
        {
            if (0 == sem_destroy( &pInst->pCfg->pSemList[SemId].sem ))
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
        LOGE( 0, "UclALOsAndroid_Impl", "IUclALOs_SemDestroy Failed %d\n", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_SemWait( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 SemId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if (SemId < pInst->pCfg->MaxSem)
    {
        if ((eUclOsSemResState_UnInit != pInst->pCfg->pSemList[SemId].State)
                && (eUclOsSemResState_Destroyed != pInst->pCfg->pSemList[SemId].State))
        {
            if (0 == sem_wait( &pInst->pCfg->pSemList[SemId].sem ))
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

    if (Ret != UCL_E_OK)
    {
        LOGE( 0, "UclALOsAndroid_Impl", "IUclALOs_SemWait Failed %d\n", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_SemPost( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 SemId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if (SemId < pInst->pCfg->MaxSem)
    {
        if ((eUclOsSemResState_UnInit != pInst->pCfg->pSemList[SemId].State)
                && (eUclOsSemResState_Destroyed != pInst->pCfg->pSemList[SemId].State))
        {
            if (0 == sem_post( &pInst->pCfg->pSemList[SemId].sem ))
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

    if (Ret != UCL_E_OK)
    {
        LOGE( 0, "UclALOsAndroid_Impl", "IUclALOs_SemPost Failed %d\n", Ret );
    }

    return Ret;
}

uint64 UclALOsAndroid_Impl_IUclALOs_GetSystemTimeMs( SUclALOsAndroidInst *pInst, uint8 InstId )
{
    uint64 ms = 0; // Milliseconds
    struct timespec spec;

    //clock_gettime(CLOCK_MONOTONIC, &spec);
    if (0 == clock_gettime( CLOCK_MONOTONIC, &spec ))
    {
        ms = (spec.tv_sec * 1000ll) + llround( spec.tv_nsec / 1.0e6 );
    }

    return ms;
}

uint32 UclALOsAndroid_Impl_IUclALOs_GetSystemTimeResolutionMs( SUclALOsAndroidInst *pInst, uint8 InstId )
{
    return 1u; // Resolution is 1 ms
}

void UclALOsAndroid_Impl_IUclALOs_Tick( SUclALOsAndroidInst *pInst, uint8 InstId )
{
    // Not applicable
}


static void *UclALOsAndroid_Impl_SignalActionThread(void *pData)
{
    SUclALOsAndroidTimerList *pTimerInfo = pData;
    sint32 ret;

    while(pTimerInfo->State != eUclOsTimerResState_Destroyed)
    {
        ret = sem_wait(&pTimerInfo->sem);
        if (( ret == 0)	&& (pTimerInfo->State != eUclOsTimerResState_Destroyed))
        {
            pTimerInfo->pFunc(pTimerInfo->pData);
        }
        else if(ret != 0)
        {
            LOGE(0, "UclALOsAndroid_Impl", "SignalActionThread:sem_wait Failed Sig%d:%d =>%d\n", pTimerInfo->sig, ret, errno);
        }
    }

    pTimerInfo->State = eUclOsTimerResState_UnInit;
    LOGE(0, "UclALOsAndroid_Impl", "%s", "SignalActionThread Exiting\n");
    return NULL;
}

static void *UclALOsAndroid_Impl_SignalListenerThread(void *pData)
{
    SUclALOsAndroidInst *pInst = (SUclALOsAndroidInst *)pData;
    SUclALOsAndroidCfg *pCfg = pInst->pCfg;
    SUclALOsAndroidTimerList *pTimerData;
    uint8 i;
    sint16 ret;
    sint32 sig;

    while(pInst->isListenerUp)
    {
        if(0 == sigwait(&(pInst->newsigmask), &sig))
        {
            (void)sigemptyset(&(pInst->newsigmask));
            for (i = 0; i < pCfg->MaxTimers; i++)
            {
                pTimerData = &pCfg->pTimerList[i];
                if (eUclOsTimerResState_Running == pTimerData->State)
                {
                    if( sig == pTimerData->sig )
                    {
                        if (eUclOsTimerType_OneShot == pTimerData->Type)
                        {
                            pTimerData->State = eUclOsTimerResState_Stopped;
                        }

                        ret = sem_post(&pTimerData->sem);
                        if (0 != ret)
                        {
                            LOGE(0, "UclALOsAndroid_Impl", "SignalListenerThread:sem_post Failed Sig%d:%d =>%d\n", pTimerData->sig, ret, errno);
                        }

                    }

                    (void)sigaddset(&(pInst->newsigmask), pTimerData->sig);
                }
            }
        }
    }

    LOGE(0, "UclALOsAndroid_Impl", "%s", "SignalListenerThread Exiting\n");
    return NULL;
}
