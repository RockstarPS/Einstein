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
#include <math.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "UclALOsPOSIX_Impl.h"
#include "UclALDebug.h"

#define TIMER_TRIGGER_DEVIATION				(5u)

static void *UclALOsPOSIX_Impl_SignalListenerThread ( void *pData );
static void *UclALOsPOSIX_Impl_SignalActionThread ( void *pData );
static void UclALOsPOSIX_Impl_UpdateTimerStats( SUclALOsPOSIXInst *pInst, uint64 timeNow );

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_Initialize ( SUclALOsPOSIXInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret = UCL_E_OK;
    uint8 i;
    sigset_t oldsigmask;
    sint32 rc;

    // Initialize Mutex
    for ( i = 0; i < pInst->pCfg->MaxMutex; i++ )
    {
        pInst->pCfg->pMutexList[i].State = eUclOsMutexResState_UnInit;
    }

    // Initialize Task
    for ( i = 0; i < pInst->pCfg->MaxTask; i++ )
    {
        pInst->pCfg->pTaskList[i].State = eUclOsTaskResState_UnInit;
        pInst->pCfg->pTaskList[i].pFunc = NULL_PTR;
        pInst->pCfg->pTaskList[i].pData = NULL_PTR;
    }

    // Initialize Timer
    pInst->isListenerUp = FALSE;
    ( void ) sigemptyset ( & ( pInst->newsigmask ) );

    for ( i = 0; i < pInst->pCfg->MaxTimers; i++ )
    {
        pInst->pCfg->pTimerList[i].State = eUclOsTimerResState_UnInit;
        pInst->pCfg->pTimerList[i].pFunc = NULL_PTR;
        pInst->pCfg->pTimerList[i].pData = NULL_PTR;
        pInst->pCfg->pTimerList[i].Type = eUclOsTimerType_Last;
        pInst->pCfg->pTimerList[i].sig = SIGRTMIN + ( sint32 ) i;
        ( void ) sigaddset ( & ( pInst->newsigmask ), pInst->pCfg->pTimerList[i].sig );
    }

    rc = pthread_sigmask ( SIG_BLOCK, & ( pInst->newsigmask ), &oldsigmask );

    if ( 0 != rc )
    {
        Ret = UCL_E_NOK;
        LOGE ( 0, "UclALOsPOSIX_Impl", "pthread_sigmask: Failed %d", rc );
    }

    // Initialize Semaphores
    if ( UCL_E_OK == Ret )
    {
        for ( i = 0; i < pInst->pCfg->MaxSem; i++ )
        {
            pInst->pCfg->pSemList[i].State = eUclOsSemResState_UnInit;
        }

        //Create Signal listener thread
        pInst->isListenerUp = TRUE;
        rc = pthread_create ( &pInst->sig_listener, NULL_PTR, &UclALOsPOSIX_Impl_SignalListenerThread, pInst );

        if ( rc != 0 )
        {
            Ret = UCL_E_NOK;
            LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_Initialize: SignalListenerThread Create Failed %d", rc );
        }
        else
        {
			(void) pthread_detach(pInst->sig_listener);
            LOGI ( 0, "UclALOsPOSIX_Impl", "%s", "IUclALOs_Initialize: SignalListenerThread Create Success" );
        }
    }

    if ( UCL_E_OK == Ret )
    {
        LOGI ( 0, "UclALOsPOSIX_Impl", "%s", "IUclALOs_Initialize: Success" );
    }
    else
    {
        LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_Initialize: Failed %d", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_Shutdown ( SUclALOsPOSIXInst *pInst, uint8 InstId )
{
    uint8 i; 
	pid_t pid;

    // Destroy Timers
    for ( i = 0; i < pInst->pCfg->MaxTimers; i++ )
    {
        if ( eUclOsTimerResState_Running == pInst->pCfg->pTimerList[i].State )
        {
            ( void ) UclALOsPOSIX_Impl_IUclALOs_TimerStop ( pInst, InstId, i );
        }

        if ( ( eUclOsTimerResState_Created == pInst->pCfg->pTimerList[i].State ) || ( eUclOsTimerResState_Stopped == pInst->pCfg->pTimerList[i].State ) )
        {
            ( void ) UclALOsPOSIX_Impl_IUclALOs_TimerDestroy ( pInst, InstId, i );
        }
    }

    //Exit the Timer Signals Listener Thread
    pInst->isListenerUp = FALSE;
    ( void ) pthread_cancel ( pInst->sig_listener );

    // Destroy Tasks
    for ( i = 0; i < pInst->pCfg->MaxTask; i++ )
    {
        ( void ) UclALOsPOSIX_Impl_IUclALOs_TaskDestroy ( pInst, InstId, i );
    }

    //Release all the mutexes if not released already
    for ( i = 0; i < pInst->pCfg->MaxMutex; i++ )
    {
        ( void ) UclALOsPOSIX_Impl_IUclALOs_MutexDestroy ( pInst, InstId, i );
    }

    //Release all the semaphores if not released already
    for ( i = 0; i < pInst->pCfg->MaxSem; i++ )
    {
        ( void ) UclALOsPOSIX_Impl_IUclALOs_SemDestroy ( pInst, InstId, i );
    }

	//Get self PID
    pid = getpid();
	
	//Raise Signal Interrupt to UCL	
	if( -1 == kill( pid, SIGINT ) )
	{
		LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_Shutdown: SIGINT Failed - %d", errno );
	}
	else
	{
		LOGI ( 0, "UclALOsPOSIX_Impl", "IUclALOs_Shutdown: Complete %d", pid );
	}
	
	LOGI ( 0, "UclALOsPOSIX_Impl", "%s", "IUclALOs_Shutdown: Complete" );

    return UCL_E_OK;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_Memset ( SUclALOsPOSIXInst *pInst, uint8 InstId, void *pBuffer, uint8 val,
        uint32 Size )
{
    Ucl_ReturnType Ret;

    if ( ( NULL_PTR != pBuffer ) && ( 0u < Size ) )
    {
        ( void ) memset ( pBuffer, ( sint32 ) val, Size );
        Ret = UCL_E_OK;
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    return Ret;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_Memcpy ( SUclALOsPOSIXInst *pInst, uint8 InstId, void *pDst, void *pSrc,
        uint32 Size )
{
    Ucl_ReturnType Ret;

    if ( ( NULL_PTR != pDst ) && ( NULL_PTR != pSrc ) && ( 0u < Size ) )
    {
        ( void ) memcpy ( pDst, pSrc, Size );
        Ret = UCL_E_OK;
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    return Ret;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_Memcmp ( SUclALOsPOSIXInst *pInst, uint8 InstId, void *pDst, void *pSrc,
        uint32 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( ( NULL_PTR != pDst ) && ( NULL_PTR != pSrc ) && ( 0u < Size ) )
    {
        if ( ( memcmp ( ( const uint8 * ) pDst, ( const uint8 * ) pSrc, Size ) ) == ( ( sint32 ) 0 ) ) //MISRA C-2012 Rule 21.16
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

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_DisableAllInterrupts ( SUclALOsPOSIXInst *pInst, uint8 InstId )
{
    // Not Applicable
    return UCL_E_NOK;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_EnableAllInterrupts ( SUclALOsPOSIXInst *pInst, uint8 InstId )
{
    // Not Applicable
    return UCL_E_NOK;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_MutexCreate ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 *pMutexId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i;
    pthread_mutexattr_t attr;

    // Validate I/P Params
    if ( NULL_PTR != pMutexId )
    {
        // Get the Available Mutex
        for ( i = 0; i < pInst->pCfg->MaxMutex; i++ )
        {
            if ( ( eUclOsMutexResState_UnInit == pInst->pCfg->pMutexList[i].State ) || ( eUclOsMutexResState_Destroyed == pInst->pCfg->pMutexList[i].State ) )
            {
                ( void ) pthread_mutexattr_init ( &attr );

                ( void ) pthread_mutexattr_settype ( &attr, PTHREAD_MUTEX_RECURSIVE );

                if ( 0 == pthread_mutex_init ( &pInst->pCfg->pMutexList[i].mutex, &attr ) )
                {
                    *pMutexId = i;

                    pInst->pCfg->pMutexList[i].State = eUclOsMutexResState_Created;
                    ( void ) pthread_mutexattr_destroy( &attr );
                    Ret = UCL_E_OK;

                    break;
                }
                else
                {
					#if defined(__QNX__)
					if ( __get_errno_ptr() != NULL_PTR )
					#endif
					{
						LOGE ( 0, "UclALOsPOSIX_Impl", "pthread_mutex_init: Failed %s", strerror ( errno ) );
					}
					#if defined(__QNX__)
					else
					{
						LOGE ( 0, "UclALOsPOSIX_Impl", "pthread_mutex_init: Failed __get_errno_ptr NULL" );
					}
					#endif
                }
                ( void ) pthread_mutexattr_destroy( &attr );
            }
        }

        if ( ( i == pInst->pCfg->MaxMutex ) && ( Ret != UCL_E_OK ) )
        {
            LOGE ( 0, "UclALOsPOSIX_Impl", "Mutex Count Exhausted. Increase MaxMutex Count" );
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if ( UCL_E_OK == Ret )
    {
        LOGI ( 0, "UclALOsPOSIX_Impl", "IUclALOs_MutexCreate: Success Id %d",  *pMutexId);
    }
    else
    {
        LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_MutexCreate: Failed %d", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_MutexDestroy ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 MutexId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if ( MutexId < pInst->pCfg->MaxMutex )
    {
        if ( ( eUclOsMutexResState_Created == pInst->pCfg->pMutexList[MutexId].State ) || ( eUclOsMutexResState_UnLocked == pInst->pCfg->pMutexList[MutexId].State ) )
        {
            if ( 0 == pthread_mutex_destroy ( &pInst->pCfg->pMutexList[MutexId].mutex ) )
            {
                pInst->pCfg->pMutexList[MutexId].State = eUclOsMutexResState_Destroyed;
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE ( 0, "UclALOsPOSIX_Impl", "%s", "pthread_mutex_destroy: Failed" );
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

    if ( UCL_E_OK == Ret )
    {
        LOGI ( 0, "UclALOsPOSIX_Impl", "IUclALOs_MutexDestroy: Success Id %d", MutexId );
    }
    else
    {
        LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_MutexDestroy: Status %d %d", Ret, MutexId );
    }

    return Ret;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_MutexLock ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 MutexId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
	sint32 err;

    // Validate I/P Params
    if ( MutexId < pInst->pCfg->MaxMutex )
    {
        if ( ( eUclOsMutexResState_UnInit != pInst->pCfg->pMutexList[MutexId].State ) && ( eUclOsMutexResState_Destroyed != pInst->pCfg->pMutexList[MutexId].State ) )
        {
			err = pthread_mutex_lock ( &pInst->pCfg->pMutexList[MutexId].mutex );
            if ( 0 == err)
            {
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE ( 0, "UclALOsPOSIX_Impl", "pthread_mutex_lock: Failed err %d", err );
            }
        }
        else
        {
			LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_MutexLock: Invalid State %d",  pInst->pCfg->pMutexList[MutexId].State);
            Ret = UCL_E_INVALID_STATE;
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if ( UCL_E_OK == Ret )
    {
        pInst->pCfg->pMutexList[MutexId].State = eUclOsMutexResState_Locked;
    }
    else
    {
        LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_MutexLock: Failed %d %d ", Ret, MutexId );
    }

    return Ret;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_MutexTryLock ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 MutexId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    sint32 LockStatus = 0;

    // Validate I/P Params
    if ( MutexId < pInst->pCfg->MaxMutex )
    {
        if ( ( eUclOsMutexResState_UnInit != pInst->pCfg->pMutexList[MutexId].State ) && ( eUclOsMutexResState_Destroyed != pInst->pCfg->pMutexList[MutexId].State ) )
        {
            LockStatus = pthread_mutex_trylock ( &pInst->pCfg->pMutexList[MutexId].mutex );

            if ( 0 == LockStatus )
            {
                Ret = UCL_E_OK;
            }
            else
            {
                if ( LockStatus != EBUSY )
                {
                    LOGE ( 0, "UclALOsPOSIX_Impl", "pthread_mutex_trylock: Failed %d \n", LockStatus );
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

    if ( UCL_E_OK == Ret )
    {
        pInst->pCfg->pMutexList[MutexId].State = eUclOsMutexResState_Locked;
    }

    return Ret;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_MutexUnlock ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 MutexId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if ( MutexId < pInst->pCfg->MaxMutex )
    {
        if ( ( eUclOsMutexResState_UnInit != pInst->pCfg->pMutexList[MutexId].State ) && ( eUclOsMutexResState_Destroyed != pInst->pCfg->pMutexList[MutexId].State ) )
        {
            // Unlock while the lock is still being held, otherwise race condition may happen
            pInst->pCfg->pMutexList[MutexId].State = eUclOsMutexResState_UnLocked;

            if ( 0 == pthread_mutex_unlock ( &pInst->pCfg->pMutexList[MutexId].mutex ) )
            {
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE ( 0, "UclALOsPOSIX_Impl", "%s", "pthread_mutex_unlock: Failed" );
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

    if ( UCL_E_OK != Ret )
    {
        LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_MutexUnlock: Failed %d", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_TaskCreate ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 *pThreadId,
        TUclOsTaskEntryFunc pFunc, void *pData )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i;

    if ( ( NULL_PTR != pThreadId ) && ( NULL_PTR != pFunc ) )
    {
        for ( i = 0; i < pInst->pCfg->MaxTask; i++ )
        {
            if ( ( eUclOsTaskResState_UnInit == pInst->pCfg->pTaskList[i].State ) || ( eUclOsTaskResState_Destroyed == pInst->pCfg->pTaskList[i].State ) )
            {

                if ( 0 == pthread_create ( &pInst->pCfg->pTaskList[i].thread, NULL_PTR, pFunc, pData ) )
                {
					(void) pthread_detach(pInst->pCfg->pTaskList[i].thread);
                    *pThreadId = i;
                    pInst->pCfg->pTaskList[i].State = eUclOsTaskResState_Created;
                    Ret = UCL_E_OK;
                    break;
                }
                else
                {
					#if defined(__QNX__)
					if ( __get_errno_ptr() != NULL_PTR )
					#endif
					{
						LOGE ( 0, "UclALOsPOSIX_Impl", "pthread_create: Failed %s", strerror ( errno ) );
					}
					#if defined(__QNX__)
					else
					{
						LOGE ( 0, "UclALOsPOSIX_Impl", "pthread_create: Failed __get_errno_ptr NULL" );
					}
					#endif
                }
            }
        }

        if ( ( i == pInst->pCfg->MaxTask ) && ( Ret != UCL_E_OK ) )
        {
            LOGE ( 0, "UclALOsPOSIX_Impl", "Task Count Exhausted. Increase MaxTask Count" );
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if ( UCL_E_OK == Ret )
    {
        LOGI ( 0, "UclALOsPOSIX_Impl", "%s", "IUclALOs_TaskCreate: Success" );
    }
    else
    {
        LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_TaskCreate: Failed %d", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_TaskDestroy ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 ThreadId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if ( ThreadId < pInst->pCfg->MaxTask )
    {
        if ( eUclOsTaskResState_Created == pInst->pCfg->pTaskList[ThreadId].State )
        {
            //TODO look for graceful thread exit options instead of pthread_cancel
            if ( 0 == pthread_cancel ( pInst->pCfg->pTaskList[ThreadId].thread ) )
            {
                pInst->pCfg->pTaskList[ThreadId].State = eUclOsTaskResState_Destroyed;
                Ret = UCL_E_OK;
            }
            else
            {
                LOGE ( 0, "UclALOsPOSIX_Impl", "%s", "pthread_cancel: Failed" );
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

    if ( UCL_E_OK == Ret )
    {
        LOGI ( 0, "UclALOsPOSIX_Impl", "%s", "IUclALOs_TaskDestroy: Success" );
    }
    else
    {
        LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_TaskDestroy: Status %d %d", Ret, ThreadId );
    }

    return Ret;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_TimerCreate ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 *pTimerId,
        TUclOsTaskEntryFunc pFunc, void *pData, EUclOsTimerType TimerType )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i;
    sint32 rc;
    struct sigevent timer_action={0};

    /* Validate I/P Params */
    if ( ( NULL_PTR != pTimerId ) && ( NULL_PTR != pFunc ) && ( NULL_PTR != pData ) && ( eUclOsTimerType_Last > TimerType ) )
    {
        for ( i = 0; i < pInst->pCfg->MaxTimers; i++ )
        {            
            if ( eUclOsTimerResState_UnInit == pInst->pCfg->pTimerList[i].State )
            {
                if ( sem_init ( & ( pInst->pCfg->pTimerList[i].sem ), 0, 0 ) < 0 )
                {
					#if defined(__QNX__)
					if ( __get_errno_ptr() != NULL_PTR )
					#endif
					{
						LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_TimerCreate: sem_init: Failed %s", strerror ( errno ) );
					}
					#if defined(__QNX__)
					else
					{
						LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_TimerCreate: sem_init: Failed __get_errno_ptr NULL");
					}
					#endif
                }
                else
                {
                    pInst->pCfg->pTimerList[i].pData = pData;
                    pInst->pCfg->pTimerList[i].pFunc = pFunc;
                    pInst->pCfg->pTimerList[i].Type = TimerType;

                    timer_action.sigev_notify = SIGEV_SIGNAL;
                    timer_action.sigev_signo = pInst->pCfg->pTimerList[i].sig;
                    timer_action.sigev_notify_attributes = NULL_PTR;

                    if ( 0 == timer_create ( CLOCK_MONOTONIC, &timer_action, &pInst->pCfg->pTimerList[i].timer ) )
                    {
                        //Create Signal Action Thread
                        rc = pthread_create ( & ( pInst->pCfg->pTimerList[i].thread_id ), NULL_PTR, &UclALOsPOSIX_Impl_SignalActionThread, & ( pInst->pCfg->pTimerList[i] ) );

                        if ( rc == 0 )
                        {
							(void) pthread_detach(pInst->pCfg->pTimerList[i].thread_id);
                            pInst->pCfg->pTimerList[i].State = eUclOsTimerResState_Created;
                            *pTimerId = i;
                            Ret = UCL_E_OK;
                        }
                        else
                        {
                            //Destroy the created timer
                            ( void ) timer_delete ( pInst->pCfg->pTimerList[i].timer );
                            LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_TimerStart: SignalActionThread Create Failed %d for sig %d", rc, pInst->pCfg->pTimerList[i].sig );
                        }

                        break;
                    }
                    else
                    {
						#if defined(__QNX__)
						if ( __get_errno_ptr() != NULL_PTR )
						#endif
						{
							LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_TimerCreate: timer_create: Failed %s", strerror ( errno ) );
						}
						#if defined(__QNX__)
						else
						{
							LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_TimerCreate: timer_create: Failed __get_errno_ptr NULL" );
						}
						#endif
                    }
                }
            }
        }

        if ( ( i == pInst->pCfg->MaxTimers ) && ( Ret != UCL_E_OK ) )
        {
            LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_TimerCreate: Timer Count Exhausted. Increase MaxTimers Count" );
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if ( UCL_E_OK == Ret )
    {
        LOGI ( 0, "UclALOsPOSIX_Impl", "%s", "IUclALOs_TimerCreate: Success" );
    }
    else
    {
        LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_TimerCreate: Failed %d", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_TimerStart ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 TimerId,
        uint32 Timeout )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    struct itimerspec TimerSpec;

    // Validate I/P Params
    if ( TimerId < pInst->pCfg->MaxTimers )
    {
        if ( ( eUclOsTimerResState_Created == pInst->pCfg->pTimerList[TimerId].State ) || ( eUclOsTimerResState_Stopped == pInst->pCfg->pTimerList[TimerId].State ) )
        {
            ( void ) memset ( ( void * ) &TimerSpec, 0, sizeof ( TimerSpec ) );

            pInst->pCfg->pTimerList[TimerId].Timeout = Timeout;

            TimerSpec.it_value.tv_sec = 0;
            TimerSpec.it_value.tv_nsec =  ( ( sint32 ) (pInst->pCfg->pTimerList[TimerId].Timeout * 1000000u ));

            if ( eUclOsTimerType_Periodic == pInst->pCfg->pTimerList[TimerId].Type )
            {
                TimerSpec.it_interval.tv_sec = 0;
                TimerSpec.it_interval.tv_nsec = ( ( sint32 ) (pInst->pCfg->pTimerList[TimerId].Timeout * 1000000u ));
            }

			pInst->pCfg->pTimerList[TimerId].State = eUclOsTimerResState_Running; ///< Fix false trigger 

            if ( 0 == timer_settime ( pInst->pCfg->pTimerList[TimerId].timer, 0, &TimerSpec, NULL_PTR ) )
            {
                Ret = UCL_E_OK;
            }
            else
            {
				///< Set the timer to UnInit State
				pInst->pCfg->pTimerList[TimerId].State = eUclOsTimerResState_UnInit;
				LOGE(0, "UclALOsAndroid_Impl", "IUclALOs_TimerStart: timer_settime: Failed %s", strerror(errno));
				
				#if defined(__QNX__)
				if ( __get_errno_ptr() != NULL_PTR )
				#endif
				{
					LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_TimerStart: timer_settime: Failed %s", strerror ( errno ) );
				}
				#if defined(__QNX__)
				else
				{
					LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_TimerStart: timer_settime: Failed __get_errno_ptr NULL" );
				}
				#endif
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

    if ( Ret != UCL_E_OK )
    {
        LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_TimerStart Failed %d\n", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_TimerStop ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 TimerId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    struct itimerspec TimerSpec;

    // Validate I/P Params
    if ( TimerId < pInst->pCfg->MaxTimers )
    {
        if ( eUclOsTimerResState_Running == pInst->pCfg->pTimerList[TimerId].State )
        {
            ( void ) memset ( ( void * ) &TimerSpec, 0, sizeof ( TimerSpec ) );

            if ( 0 == timer_settime ( pInst->pCfg->pTimerList[TimerId].timer, 0, &TimerSpec, NULL_PTR ) )
            {
                Ret = UCL_E_OK;
            }
            else
            {
				#if defined(__QNX__)
				if ( __get_errno_ptr() != NULL_PTR )
				#endif
				{
					LOGE ( 0, "UclALOsPOSIX_Impl", "timer_settime: Failed %s", strerror ( errno ) );
				}
				#if defined(__QNX__)
				else
				{
					LOGE ( 0, "UclALOsPOSIX_Impl", "timer_settime: Failed __get_errno_ptr NULL" );
				}
				#endif
            }

            pInst->pCfg->pTimerList[TimerId].State = eUclOsTimerResState_Stopped;
        }
        else if ( ( eUclOsTimerResState_Stopped == pInst->pCfg->pTimerList[TimerId].State ) || ( eUclOsTimerResState_Created == pInst->pCfg->pTimerList[TimerId].State ) )
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

    if ( Ret != UCL_E_OK )
    {
        LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_TimerStop Failed %d\n", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_TimerDestroy ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 TimerId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 WaitCount = 10;

    // Validate I/P Params
    if ( TimerId < pInst->pCfg->MaxTimers )
    {
        if ( ( eUclOsTimerResState_Created == pInst->pCfg->pTimerList[TimerId].State ) || ( eUclOsTimerResState_Stopped == pInst->pCfg->pTimerList[TimerId].State ) )
        {
            ( void ) timer_delete ( pInst->pCfg->pTimerList[TimerId].timer );

            pInst->pCfg->pTimerList[TimerId].State = eUclOsTimerResState_Destroyed;

            if ( sem_post ( & ( pInst->pCfg->pTimerList[TimerId].sem ) ) == 0 )
            {
                while ( ( pInst->pCfg->pTimerList[TimerId].State != eUclOsTimerResState_UnInit ) && ( WaitCount > 0u ) )
                {
                    //Signal Action Thread is expected to be exited in 1ms of destroying the timer
                    ( void ) usleep ( 100 );
                    WaitCount--;
                }

                if ( pInst->pCfg->pTimerList[TimerId].State != eUclOsTimerResState_UnInit )
                {
                    LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_TimerDestroy SignalActionThread of Timer %d forcefully exited\n", TimerId );
                    ( void ) pthread_cancel ( pInst->pCfg->pTimerList[TimerId].thread_id );
                    pInst->pCfg->pTimerList[TimerId].State = eUclOsTimerResState_UnInit;
                }

                pInst->pCfg->pTimerList[TimerId].Timeout = 0;
                pInst->pCfg->pTimerList[TimerId].pData = NULL_PTR;
                pInst->pCfg->pTimerList[TimerId].pFunc = NULL_PTR;
                pInst->pCfg->pTimerList[TimerId].Type = eUclOsTimerType_Last;

                //Destroy the sem blocked by Signal Action Thread after the thread exited
                ( void ) sem_destroy ( &pInst->pCfg->pTimerList[TimerId].sem );
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

    if ( Ret != UCL_E_OK )
    {
        LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_TimerDestroy Status %d %d\n", Ret, TimerId );
    }

    return Ret;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_SemCreate ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 *pSemId, uint8 Val )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i;

    // Validate I/P Params
    if ( NULL_PTR != pSemId )
    {
        // Get the Available Mutex
        for ( i = 0; i < pInst->pCfg->MaxSem; i++ )
        {
            if ( ( eUclOsSemResState_UnInit == pInst->pCfg->pSemList[i].State ) || ( eUclOsSemResState_Destroyed == pInst->pCfg->pSemList[i].State ) )
            {
                if ( sem_init ( &pInst->pCfg->pSemList[i].sem, 0, Val ) < 0 )
                {
					#if defined(__QNX__)
					if ( __get_errno_ptr() != NULL_PTR )
					#endif
					{
						LOGE ( 0, "UclALOsPOSIX_Impl", "sem_init: Failed %s", strerror ( errno ) );
					}
					#if defined(__QNX__)
					else
					{
						LOGE ( 0, "UclALOsPOSIX_Impl", "sem_init: Failed __get_errno_ptr NULL" );
					}
					#endif
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

        if ( ( i == pInst->pCfg->MaxSem ) && ( Ret != UCL_E_OK ) )
        {
            LOGE ( 0, "UclALOsPOSIX_Impl", "Sem Count Exhausted. Increase MaxSem Count" );
        }
    }
    else
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    if ( UCL_E_OK == Ret )
    {
        LOGI ( 0, "UclALOsPOSIX_Impl", "%s", "IUclALOs_SemCreate: Success" );
    }
    else
    {
        LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_SemCreate: Failed %d", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_SemDestroy ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 SemId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if ( SemId < pInst->pCfg->MaxSem )
    {
        if ( eUclOsSemResState_Created == pInst->pCfg->pSemList[SemId].State )
        {
            if ( 0 == sem_destroy ( &pInst->pCfg->pSemList[SemId].sem ) )
            {
                pInst->pCfg->pSemList[SemId].State = eUclOsSemResState_Destroyed;
                Ret = UCL_E_OK;
            }
			else
			{
				#if defined(__QNX__)
				if ( __get_errno_ptr() != NULL_PTR )
				#endif
				{
					LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_SemDestroy %d Error %d\n", SemId, errno );
				}
				#if defined(__QNX__)
				else
				{
					LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_SemDestroy %d __get_errno_ptr NULL \n", SemId );
				}
				#endif
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

    if ( Ret != UCL_E_OK )
    {
        LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_SemDestroy %d Status %d\n", SemId, Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_SemWait ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 SemId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if ( SemId < pInst->pCfg->MaxSem )
    {
        if ( ( eUclOsSemResState_UnInit != pInst->pCfg->pSemList[SemId].State ) && ( eUclOsSemResState_Destroyed != pInst->pCfg->pSemList[SemId].State ) )
        {
            if ( 0 == sem_wait ( &pInst->pCfg->pSemList[SemId].sem ) )
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

    if ( Ret != UCL_E_OK )
    {
        LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_SemWait Failed %d\n", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_SemPost ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 SemId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Validate I/P Params
    if ( SemId < pInst->pCfg->MaxSem )
    {
        if ( ( eUclOsSemResState_UnInit != pInst->pCfg->pSemList[SemId].State ) && ( eUclOsSemResState_Destroyed != pInst->pCfg->pSemList[SemId].State ) )
        {
            if ( 0 == sem_post ( &pInst->pCfg->pSemList[SemId].sem ) )
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

    if ( Ret != UCL_E_OK )
    {
        LOGE ( 0, "UclALOsPOSIX_Impl", "IUclALOs_SemPost Failed %d\n", Ret );
    }

    return Ret;
}

uint64 UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeMs ( SUclALOsPOSIXInst *pInst, uint8 InstId )
{
    uint64 ms = 0; // Milliseconds
    struct timespec spec;

    if ( 0 == clock_gettime ( CLOCK_MONOTONIC, &spec ) )
    {      
		ms = ( spec.tv_sec * 1000LLU ) + ( uint64 ) ( llround( ( ( float64 ) spec.tv_nsec / 1.0e6 ) ) );	  
    }

    return ms;
}

uint32 UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeResolutionMs ( SUclALOsPOSIXInst *pInst, uint8 InstId )
{
    return 1u; // Resolution is 1 ms
}

void UclALOsPOSIX_Impl_IUclALOs_Tick ( SUclALOsPOSIXInst *pInst, uint8 InstId )
{
    // Not applicable
}

static void *UclALOsPOSIX_Impl_SignalActionThread ( void *pData )
{
    SUclALOsPOSIXTimerList *pTimerInfo = ( SUclALOsPOSIXTimerList * ) pData;
    sint32 ret;
	struct timespec spec;

    LOGI ( 0, "UclALOsPOSIX_Impl", "SignalActionThread:Started for Sig%d\n", pTimerInfo->sig );

    if ( 0 == clock_gettime ( CLOCK_MONOTONIC, &spec ) )
    {      
		pTimerInfo->lastTriggerTime = ( spec.tv_sec * 1000LLU ) + ( uint64 ) ( llround( ( ( float64 ) spec.tv_nsec / 1.0e6 ) ) );	  
    }	
	else
	{
		#if defined(__QNX__)
		if ( __get_errno_ptr() != NULL_PTR )
		#endif
		{
			LOGE ( 0, "UclALOsPOSIX_Impl", "SignalActionThread%d: Clock_gettime failed %d\n", pTimerInfo->sig, errno );
		}
		#if defined(__QNX__)
		else
		{
			LOGE ( 0, "UclALOsPOSIX_Impl", "SignalActionThread%d: Clock_gettime failed. __get_errno_ptr NULL\n", pTimerInfo->sig );
		}
		#endif
	}
	
    while ( pTimerInfo->State != eUclOsTimerResState_Destroyed )
    {
        ret = sem_wait ( &pTimerInfo->sem );

        if ( ret == 0 )
        {
			pTimerInfo->timerServiceCnt++;
            if ( pTimerInfo->State != eUclOsTimerResState_Destroyed )
            {
                ( void ) pTimerInfo->pFunc ( pTimerInfo->pData );
            }
            else
            {
                LOGE ( 0, "UclALOsPOSIX_Impl", "SignalActionThread:Timer for Sig%d already destroyed ", pTimerInfo->sig );
            }
        }
        else
        {
			#if defined(__QNX__)
			if ( __get_errno_ptr() != NULL_PTR )
			#endif
			{
				LOGE ( 0, "UclALOsPOSIX_Impl", "SignalActionThread:sem_wait Failed Sig%d:%d =>%d\n", pTimerInfo->sig, ret, errno );
			}
			#if defined(__QNX__)
			else
			{
				LOGE ( 0, "UclALOsPOSIX_Impl", "SignalActionThread:sem_wait Failed Sig%d:%d\n", pTimerInfo->sig, ret );
			}
			#endif
        }
    }

    pTimerInfo->State = eUclOsTimerResState_UnInit;
    LOGE ( 0, "UclALOsPOSIX_Impl", "SignalActionThread %d Exiting\n", pTimerInfo->sig );

    return NULL_PTR;
}

static void *UclALOsPOSIX_Impl_SignalListenerThread ( void *pData )
{
    SUclALOsPOSIXInst *pInst = ( SUclALOsPOSIXInst * ) pData;
    SUclALOsPOSIXCfg *pCfg = pInst->pCfg;
    SUclALOsPOSIXTimerList *pTimerData;
    uint8 i;
    sint32 ret;
    sint32 sig=0;
	struct timespec spec;
	uint64 timeNow = 0;

	//Get System UP Time
    if ( 0 == clock_gettime ( CLOCK_MONOTONIC, &spec ) )
    {      
		pInst->sysUpTime = ( spec.tv_sec * 1000LLU ) + ( uint64 ) ( llround( ( ( float64 ) spec.tv_nsec / 1.0e6 ) ) );	  
    }	
	else
	{
		#if defined(__QNX__)
		if ( __get_errno_ptr() != NULL_PTR )
		#endif
		{
			LOGE ( 0, "UclALOsPOSIX_Impl", "SignalListenerThread: Clock_gettime failed %d\n", errno );
		}
		#if defined(__QNX__)
		else
		{
			LOGE ( 0, "UclALOsPOSIX_Impl", "SignalListenerThread: Clock_gettime failed __get_errno_ptr NULL\n" );
		}
		#endif
	}
	
    LOGI ( 0, "UclALOsPOSIX_Impl", "SignalListenerThread Started. UP_TIME - %ld\n", pInst->sysUpTime );

    while ( ( pInst->isListenerUp ) != 0u )
    {
        if ( 0 == sigwait ( & ( pInst->newsigmask ), &sig ) )
        {
            ( void ) sigemptyset ( & ( pInst->newsigmask ) );

            for ( i = 0; i < pCfg->MaxTimers; i++ )
            {
                pTimerData = &pCfg->pTimerList[i];

                if ( eUclOsTimerResState_Running == pTimerData->State )
                {
                    if ( sig == pTimerData->sig )
                    {
                        if ( eUclOsTimerType_OneShot == pTimerData->Type )
                        {
                            pTimerData->State = eUclOsTimerResState_Stopped;
                        }
						
                        ret = sem_post ( &pTimerData->sem );

                        if ( 0 != ret )
                        {
							#if defined(__QNX__)
							if ( __get_errno_ptr() != NULL_PTR )
							#endif
							{
								LOGE ( 0, "UclALOsPOSIX_Impl", "SignalListenerThread:sem_post Failed Sig%d:%d =>%d\n", pTimerData->sig, ret, errno );
							}
							#if defined(__QNX__)
							else
							{
								LOGE ( 0, "UclALOsPOSIX_Impl", "SignalListenerThread:sem_post Failed Sig%d:%d\n", pTimerData->sig, ret );
							}
							#endif
                        }
						else
						{
							pTimerData->timerTriggerCnt++;
							if ( 0 == clock_gettime ( CLOCK_MONOTONIC, &spec ) )
							{      
								timeNow = ( spec.tv_sec * 1000LLU ) + ( uint64 ) ( llround( ( ( float64 ) spec.tv_nsec / 1.0e6 ) ) );	  
							}
							
							//Trigger Timer Statistics Print if Timer Trigger Deviation is more than 5 times the expected time
							if( (timeNow - pTimerData->lastTriggerTime) > (pTimerData->Timeout * ( uint64 )TIMER_TRIGGER_DEVIATION))
							{
								UclALOsPOSIX_Impl_UpdateTimerStats(pInst, timeNow);
							}
							
							pTimerData->lastTriggerTime = timeNow;
						}
                    }

                    ( void ) sigaddset ( & ( pInst->newsigmask ), pTimerData->sig );
                }
            }
        }
    }

    LOGE ( 0, "UclALOsPOSIX_Impl", "%s", "SignalListenerThread Exiting\n" );
    return NULL_PTR;
}

static void UclALOsPOSIX_Impl_UpdateTimerStats( SUclALOsPOSIXInst *pInst, uint64 timeNow )
{
	SUclALOsPOSIXCfg *pCfg = pInst->pCfg;
    SUclALOsPOSIXTimerList *pTimerData;
	uint8 i;
		
	LOGI ( 0, "UclALOsPOSIX_Impl", "System Up Time %ld ## Time Now %ld", pInst->sysUpTime, timeNow );
	
	for ( i = 0; i < pCfg->MaxTimers; i++ )
	{
		pTimerData = &pCfg->pTimerList[i];
	
		if( eUclOsTimerResState_UnInit != pTimerData->State)
		{
			LOGI ( 0, "UclALOsPOSIX_Impl", "Timer %d - %d %d %d %ld %ld %ld", i, pTimerData->sig, pTimerData->State, pTimerData->Timeout, pTimerData->timerTriggerCnt, pTimerData->timerServiceCnt, pTimerData->lastTriggerTime);
		}
	}
}
