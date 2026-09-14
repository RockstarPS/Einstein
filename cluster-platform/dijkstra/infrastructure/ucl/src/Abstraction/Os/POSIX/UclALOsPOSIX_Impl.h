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
/// @file
/// @ingroup UclALOs
/// UCL OS Abstraction Layer Implementation for POSIX Operating Systems.
/// APIs in this file are not to called directly by the users.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALOS_POSIXIMPL
#define UCLALOS_POSIXIMPL

#include "UclALOs_Types.h"
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <signal.h>


typedef struct
{
    sem_t sem;
    EUclOsSemResState State;
} SUclALOsPOSIXSemList;

typedef struct
{
    pthread_mutex_t mutex;
    EUclOsMutexResState State;
} SUclALOsPOSIXMutexList;

typedef struct
{
    pthread_t thread;
    EUclOsTaskResState State;
    TUclOsTaskEntryFunc pFunc;
    void *pData;
} SUclALOsPOSIXTaskList;

typedef struct
{
    timer_t timer;
    sint32 sig;
    pthread_t thread_id;        ///< Signal Action Thread for all the Active Timers
    sem_t sem;
    EUclOsTimerResState State;
    TUclOsTaskEntryFunc pFunc;
    void *pData;
    EUclOsTimerType Type;
    uint32 Timeout;
	uint64 timerServiceCnt;
	uint64 timerTriggerCnt;
	uint64 lastTriggerTime;
} SUclALOsPOSIXTimerList;

///
/// @brief Configruation structure for UclALOsPOSIX
///
/// The SUclALOsPOSIXCfg structure defines the configuration
/// data for UclALOsPOSIX_Impl class.
///
typedef struct
{
    uint8 MaxMutex;                     ///< Maximum number of Mutex'es supported
    uint8 MaxTask;                      ///< Maximum number of Tasks supported
    uint8 MaxTimers;                    ///< Maximum number of Timers supported
    uint8 MaxSem;                       ///< Maximum number of Semaphores supported
    SUclALOsPOSIXMutexList *pMutexList; ///< Array of Tasks
    SUclALOsPOSIXTaskList *pTaskList;   ///< Array of Mutex'es
    SUclALOsPOSIXTimerList *pTimerList; ///< Array of Timers
    SUclALOsPOSIXSemList *pSemList;     ///< Array of Semaphores
} SUclALOsPOSIXCfg;

///
/// @brief Instance Structure for UclALOsPOSIX_Impl. \n
/// @ingroup UclALOs
/// The SUclALOsPOSIXInst structure defines the private
/// instance data for UclALOsPOSIX_Impl class.
///
typedef struct
{
    SUclALOsPOSIXCfg *pCfg;             ///< Pointer to the configuration structure
    uint8 isListenerUp;
    sigset_t newsigmask;
	uint64 sysUpTime;
    pthread_t sig_listener;             ///< Signal Listener Thread for all the Active Timers
} SUclALOsPOSIXInst;

Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_Initialize ( SUclALOsPOSIXInst *pInst, uint8 InstId );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_Shutdown ( SUclALOsPOSIXInst *pInst, uint8 InstId );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_Memset ( SUclALOsPOSIXInst *pInst, uint8 InstId, void *pBuffer, uint8 val,
        uint32 Size );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_Memcpy ( SUclALOsPOSIXInst *pInst, uint8 InstId, void *pDst, void *pSrc,
        uint32 Size );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_Memcmp ( SUclALOsPOSIXInst *pInst, uint8 InstId, void *pDst, void *pSrc,
        uint32 Size );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_DisableAllInterrupts ( SUclALOsPOSIXInst *pInst, uint8 InstId );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_EnableAllInterrupts ( SUclALOsPOSIXInst *pInst, uint8 InstId );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_MutexCreate ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 *pMutexId );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_MutexDestroy ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 MutexId );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_TaskCreate ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 *pThreadId,
        TUclOsTaskEntryFunc pFunc, void *pData );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_TaskDestroy ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 ThreadId );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_MutexLock ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 MutexId );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_MutexTryLock ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 MutexId );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_MutexUnlock ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 MutexId );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_TimerCreate ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 *pTimerId,
        TUclOsTaskEntryFunc pFunc, void *pData, EUclOsTimerType TimerType );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_TimerStart ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 TimerId,
        uint32 Timeout );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_TimerStop ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 TimerId );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_TimerDestroy ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 TimerId );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_SemCreate ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 *pSemId, uint8 Val );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_SemDestroy ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 SemId );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_SemWait ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 SemId );
Ucl_ReturnType UclALOsPOSIX_Impl_IUclALOs_SemPost ( SUclALOsPOSIXInst *pInst, uint8 InstId, uint32 SemId );
uint64 UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeMs ( SUclALOsPOSIXInst *pInst, uint8 InstId );
uint32 UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeResolutionMs ( SUclALOsPOSIXInst *pInst, uint8 InstId );
void UclALOsPOSIX_Impl_IUclALOs_Tick ( SUclALOsPOSIXInst *pInst, uint8 InstId );

#endif //UCLALOS_POSIXIMPL
