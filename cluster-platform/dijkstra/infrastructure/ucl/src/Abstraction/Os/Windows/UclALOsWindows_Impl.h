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
/// UCL OS Abstraction Layer Implementation for Windows Operating Systems.
/// APIs in this file are not to called directly by the users.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALOS_WINDOWSIMPL
#define UCLALOS_WINDOWSIMPL

#include "UclALOs_Types.h"
#include "windows.h"

typedef struct SUclALOsWindowsInst_t SUclALOsWindowsInst;

typedef struct SUclALOsWindowsSemList_t
{
    HANDLE sem;
    EUclOsSemResState State;
} SUclALOsWindowsSemList;

typedef struct SUclALOsWindowsMutexList_t
{
    HANDLE mutex;
    EUclOsMutexResState State;
} SUclALOsWindowsMutexList;

typedef struct SUclALOsWindowsTaskList_t
{
    HANDLE thread;
    EUclOsTaskResState State;
    TUclOsTaskEntryFunc pFunc;
    void *pData;
} SUclALOsWindowsTaskList;

typedef struct SUclALOsWindowsTimerList_t
{
    HANDLE timer;
    EUclOsTimerResState State;
    TUclOsTaskEntryFunc pFunc;
    void *pData;
    EUclOsTimerType Type;
    uint32 Timeout;
} SUclALOsWindowsTimerList;

///
/// @brief Configruation structure for UclALOsWindows
///
/// The SUclALOsWindowsCfg structure defines the configuration
/// data for UclALOsWindows_Impl class.
///
typedef struct SUclALOsWindowsCfg_t
{
    uint8 MaxMutex;                       ///< Maximum number of Mutex'es supported
    uint8 MaxTask;                        ///< Maximum number of Tasks supported
    uint8 MaxTimers;                      ///< Maximum number of Timers supported
    uint8 MaxSem;                         ///< Maximum number of Semaphores supported
    SUclALOsWindowsMutexList *pMutexList; ///< Array of Tasks
    SUclALOsWindowsTaskList *pTaskList;   ///< Array of Mutex'es
    SUclALOsWindowsTimerList *pTimerList; ///< Array of Timers
    SUclALOsWindowsSemList *pSemList;     ///< Array of Semaphores
} SUclALOsWindowsCfg;

///
/// @brief Instance Structure for UclALOsWindows_Impl. \n
/// @ingroup UclALOs
/// The SUclALOsWindowsInst structure defines the private
/// instance data for UclALOsWindows_Impl class.
///
struct SUclALOsWindowsInst_t
{
    SUclALOsWindowsCfg *pCfg; ///< Pointer to the configuration structure
};

Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_Initialize(SUclALOsWindowsInst *pInst, uint8 InstId);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_Shutdown(SUclALOsWindowsInst *pInst, uint8 InstId);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_Memset(SUclALOsWindowsInst *pInst, uint8 InstId, void *pBuffer, uint8 val,
                                                   uint32 Size);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_Memcpy(SUclALOsWindowsInst *pInst, uint8 InstId, void *pDst, void *pSrc,
                                                   uint32 Size);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_Memcmp( SUclALOsWindowsInst *pInst, uint8 InstId, void *pDst, void *pSrc,
                                                   uint32 Size );
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_DisableAllInterrupts(SUclALOsWindowsInst *pInst, uint8 InstId);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_EnableAllInterrupts(SUclALOsWindowsInst *pInst, uint8 InstId);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_MutexCreate(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 *pMutexId);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_MutexDestroy(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 MutexId);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_TaskCreate(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 *pThreadId,
                                                       TUclOsTaskEntryFunc pFunc, void *pData);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_TaskDestroy(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 ThreadId);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_MutexLock(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 MutexId);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_MutexTryLock(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 MutexId);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_MutexUnlock(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 MutexId);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_TimerCreate(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 *pTimerId,
                                                        TUclOsTaskEntryFunc pFunc, void *pData, EUclOsTimerType TimerType);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_TimerStart(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 TimerId,
                                                       uint32 Timeout);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_TimerStop(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 TimerId);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_TimerDestroy(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 TimerId);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_SemCreate(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 *pSemId, uint8 Val);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_SemDestroy(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 SemId);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_SemWait(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 SemId);
Ucl_ReturnType UclALOsWindows_Impl_IUclALOs_SemPost(SUclALOsWindowsInst *pInst, uint8 InstId, uint32 SemId);
uint64 UclALOsWindows_Impl_IUclALOs_GetSystemTimeMs(SUclALOsWindowsInst *pInst, uint8 InstId);
uint32 UclALOsWindows_Impl_IUclALOs_GetSystemTimeResolutionMs(SUclALOsWindowsInst *pInst, uint8 InstId);
void UclALOsWindows_Impl_IUclALOs_Tick(SUclALOsWindowsInst *pInst, uint8 InstId);

#endif //UCLALOS_WINDOWSIMPL
