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
/// UCL OS Abstraction Layer Implementation for INTEGRIRY Operating Systems.
/// APIs in this file are not to called directly by the users.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALOS_INTEGRITYIMPL
#define UCLALOS_INTEGRITYIMPL

#include <INTEGRITY.h>
#include "UclALOs_Types.h"

typedef struct SUclALOsIntegrityInst_t SUclALOsIntegrityInst;

typedef struct SUclALOsIntegrityTaskList_t
{
    Task thread;
    EUclOsTaskResState state;
    TUclOsTaskEntryFunc pFunc;
    void *pData;
} SUclALOsIntegrityTaskList;

typedef struct SUclALOsIntegrityTimerList_t
{
    Clock alarmClock;
    Activity timerActivity;
    EUclOsTimerResState state;
    TUclOsTaskEntryFunc pFunc;
    void *pData;
    EUclOsTimerType type;
    uint32 timeout;
    uint32 count;
} SUclALOsIntegrityTimerList;

typedef struct SUclALOsIntegrityMutexList_t
{
    LocalMutex mutex;
    EUclOsMutexResState state;
} SUclALOsIntegrityMutexList;

typedef struct SUclALOsIntegritySemList_t
{
    Semaphore sem;
    EUclOsSemResState state;
} SUclALOsIntegritySemList;

///
/// @brief Configuration Structure for UclALOsIntegrity class
///
/// The SUclALOsVliteCfg structure defines the configuration
/// data for UclALOsIntegrity class.
///
typedef struct SUclALOsIntegrityCfg_t
{
    uint8 tickResolutionMs;                 ///< Platform clock tick resolution
    uint8 maxMutex;                         ///< Maximum number of Mutex'es supported
    uint8 maxTimers;                        ///< Maximum number of Timers supported
    uint8 maxTask;                          ///< Maximum number of Tasks supported
    uint8 maxSem;                           ///< Maximum number of Semaphores supported
    SUclALOsIntegrityTimerList *pTimerList; ///< Array of Timers
    SUclALOsIntegrityTaskList *pTaskList;   ///< Array of Tasks
    SUclALOsIntegrityMutexList *pMutexList; ///< Array of Mutex
    SUclALOsIntegritySemList *pSemList;     ///< Array of Semaphores
} SUclALOsIntegrityCfg;

///
/// @brief Instance Structure for UclALOsIntegrity_Impl. \n
/// @ingroup UclALOs
/// The SUclALOsIntegrityInst structure defines the private
/// instance data for UclALOsIntegrity_Impl class.
///
struct SUclALOsIntegrityInst_t
{
    Task timerTaskId;
    uint64 elapsedTicksInMs; /**< Elapsed ticks in millisecond */
    SUclALOsIntegrityCfg *pCfg;
};

Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_Initialize(SUclALOsIntegrityInst *pInst, uint8 InstId);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_Shutdown(SUclALOsIntegrityInst *pInst, uint8 InstId);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_Memset(SUclALOsIntegrityInst *pInst, uint8 InstId, void *pBuffer, uint8 val,
                                                     uint32 size);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_Memcpy(SUclALOsIntegrityInst *pInst, uint8 InstId, void *pDst, void *pSrc,
                                                     uint32 Size);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_DisableAllInterrupts(SUclALOsIntegrityInst *pInst, uint8 InstId);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_EnableAllInterrupts(SUclALOsIntegrityInst *pInst, uint8 InstId);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_MutexCreate(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 *pMutexId);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_MutexDestroy(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 MutexId);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_TaskCreate(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 *pThreadId,
                                                         TUclOsTaskEntryFunc pFunc, void *pData);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_TaskDestroy(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 ThreadId);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_MutexLock(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 MutexId);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_MutexTryLock(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 MutexId);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_MutexUnlock(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 MutexId);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_TimerCreate(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 *pTimerId,
                                                          TUclOsTaskEntryFunc pFunc, void *pData, EUclOsTimerType TimerType);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_TimerStart(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 TimerId, uint32 Timeout);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_TimerStop(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 TimerId);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_TimerDestroy(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 TimerId);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_SemCreate(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 *pSemId, uint8 Val);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_SemDestroy(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 SemId);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_SemWait(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 SemId);
Ucl_ReturnType UclALOsIntegrity_Impl_IUclALOs_SemPost(SUclALOsIntegrityInst *pInst, uint8 InstId, uint32 SemId);
uint64 UclALOsIntegrity_Impl_IUclALOs_GetSystemTimeMs(SUclALOsIntegrityInst *pInst, uint8 InstId);
uint32 UclALOsIntegrity_Impl_IUclALOs_GetSystemTimeResolutionMs(SUclALOsIntegrityInst *pInst, uint8 InstId);
void UclALOsIntegrity_Impl_IUclALOs_Tick(SUclALOsIntegrityInst *pInst, uint8 InstId);

#endif //UCLALOS_INTEGRITYIMPL
