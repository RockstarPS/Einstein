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
/// UCL OS Abstraction Layer Implementation for Android Operating Systems.
/// APIs in this file are not to called directly by the users.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALOS_AndroidIMPL
#define UCLALOS_AndroidIMPL

#include "UclALOs_Types.h"
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

typedef struct SUclALOsAndroidInst_t SUclALOsAndroidInst;

typedef struct SUclALOsAndroidSemList_t
{
    sem_t sem;
    EUclOsSemResState State;
} SUclALOsAndroidSemList;

typedef struct SUclALOsAndroidMutexList_t
{
    pthread_mutex_t mutex;
    EUclOsMutexResState State;
} SUclALOsAndroidMutexList;

typedef struct SUclALOsAndroidTaskList_t
{
    pthread_t thread;
    EUclOsTaskResState State;
    TUclOsTaskEntryFunc pFunc;
    void *pData;
} SUclALOsAndroidTaskList;

typedef struct SUclALOsAndroidTimerList_t
{
    timer_t timer;
	int sig;
	pthread_t thread_id;		///< Signal Action Thread for all the Active Timers
	sem_t sem;
    EUclOsTimerResState State;
    TUclOsTaskEntryFunc pFunc;
    void *pData;
    EUclOsTimerType Type;
    uint32 Timeout;
} SUclALOsAndroidTimerList;

///
/// @brief Configruation structure for UclALOsAndroid
///
/// The SUclALOsAndroidCfg structure defines the configuration
/// data for UclALOsAndroid_Impl class.
///
typedef struct SUclALOsAndroidCfg_t
{
    uint8 MaxMutex;                     ///< Maximum number of Mutex'es supported
    uint8 MaxTask;                      ///< Maximum number of Tasks supported
    uint8 MaxTimers;                    ///< Maximum number of Timers supported
    uint8 MaxSem;                       ///< Maximum number of Semaphores supported
    SUclALOsAndroidMutexList *pMutexList; ///< Array of Tasks
    SUclALOsAndroidTaskList *pTaskList;   ///< Array of Mutex'es
    SUclALOsAndroidTimerList *pTimerList; ///< Array of Timers
    SUclALOsAndroidSemList *pSemList;     ///< Array of Semaphores
} SUclALOsAndroidCfg;

///
/// @brief Instance Structure for UclALOsAndroid_Impl. \n
/// @ingroup UclALOs
/// The SUclALOsAndroidInst structure defines the private
/// instance data for UclALOsAndroid_Impl class.
///
struct SUclALOsAndroidInst_t
{
    SUclALOsAndroidCfg *pCfg; ///< Pointer to the configuration structure
	uint8 isListenerUp;
	sigset_t newsigmask;
	pthread_t sig_listener;				///< Signal Listener Thread for all the Active Timers
};

Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_Initialize( SUclALOsAndroidInst *pInst, uint8 InstId );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_Shutdown( SUclALOsAndroidInst *pInst, uint8 InstId );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_Memset( SUclALOsAndroidInst *pInst, uint8 InstId, void *pBuffer, uint8 val,
                uint32 Size );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_Memcpy( SUclALOsAndroidInst *pInst, uint8 InstId, void *pDst, void *pSrc,
                uint32 Size );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_Memcmp( SUclALOsAndroidInst *pInst, uint8 InstId, void *pDst, void *pSrc,
                uint32 Size );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_DisableAllInterrupts( SUclALOsAndroidInst *pInst, uint8 InstId );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_EnableAllInterrupts( SUclALOsAndroidInst *pInst, uint8 InstId );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_MutexCreate( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 *pMutexId );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_MutexDestroy( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 MutexId );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_TaskCreate( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 *pThreadId,
                TUclOsTaskEntryFunc pFunc, void *pData );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_TaskDestroy( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 ThreadId );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_MutexLock( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 MutexId );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_MutexTryLock( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 MutexId );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_MutexUnlock( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 MutexId );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_TimerCreate( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 *pTimerId,
                TUclOsTaskEntryFunc pFunc, void *pData, EUclOsTimerType TimerType );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_TimerStart( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 TimerId,
                uint32 Timeout );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_TimerStop( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 TimerId );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_TimerDestroy( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 TimerId );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_SemCreate( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 *pSemId, uint8 Val );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_SemDestroy( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 SemId );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_SemWait( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 SemId );
Ucl_ReturnType UclALOsAndroid_Impl_IUclALOs_SemPost( SUclALOsAndroidInst *pInst, uint8 InstId, uint32 SemId );
uint64 UclALOsAndroid_Impl_IUclALOs_GetSystemTimeMs( SUclALOsAndroidInst *pInst, uint8 InstId );
uint32 UclALOsAndroid_Impl_IUclALOs_GetSystemTimeResolutionMs( SUclALOsAndroidInst *pInst, uint8 InstId );
void UclALOsAndroid_Impl_IUclALOs_Tick( SUclALOsAndroidInst *pInst, uint8 InstId );

#endif //UCLALOS_AndroidIMPL
