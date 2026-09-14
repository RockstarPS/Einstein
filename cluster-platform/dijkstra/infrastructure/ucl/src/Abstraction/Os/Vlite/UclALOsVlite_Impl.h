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
/// UCL OS Abstraction Layer Implementation for AUTOSAR Operating Systems.
/// APIs in this file are not to called directly by the users.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALOS_VLITEARCH3IMPL
#define UCLALOS_VLITEARCH3IMPL

#include "UclALOs_Types.h"

typedef struct SUclALOsVliteInst_t SUclALOsVliteInst;

///
/// @brief Timer Structure for UclALOsVlite class
///
/// The SUclALOsVliteTimerList structure defines the timer
/// data structure for UclALOsVlite class.
///
typedef struct
{
    EUclOsTimerResState state; ///< Timer state
    TUclOsTaskEntryFunc pFunc; ///< Timer expiry callback function
    void *pData;               ///< Callback function argument
    EUclOsTimerType type;      ///< Timer type
    uint32 timeout;            ///< Timeout
    uint32 count;              ///< Elapsed count
} SUclALOsVliteTimerList;

///
/// @brief Configuration Structure for UclALOsVlite class
///
/// The SUclALOsVliteCfg structure defines the configuration
/// data for UclALOsVlite class.
///
typedef struct
{
    uint8 tickResolutionMs;             ///< Duration with which the tick API will be called, must match the periodicity with which the UclSys_Task is scheduled
    uint8 maxTimers;                    ///< Maximum number of Timers supported
    SUclALOsVliteTimerList *pTimerList; ///< Array of Timers
} SUclALOsVliteCfg;

///
/// @brief Instance Structure for UclALOsVlite class \n
/// @ingroup UclALOs
/// The SUclALOsVliteInst structure defines the private
/// instance data for UclALOsVlite class.
///
struct SUclALOsVliteInst_t
{
    uint64 elapsedTicksInMs; ///< Elapsed ticks in millisecond
    SUclALOsVliteCfg *pCfg;  ///< Pointer to configuration data
};

Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_Initialize(SUclALOsVliteInst *pInst, uint8 InstId);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_Shutdown(SUclALOsVliteInst *pInst, uint8 InstId);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_Memset(SUclALOsVliteInst *pInst, uint8 InstId, void *pBuffer, uint8 val,
                                                 uint32 size);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_Memcpy(SUclALOsVliteInst *pInst, uint8 InstId, void *pDst, void *pSrc,
                                                 uint32 Size);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_Memcmp( SUclALOsVliteInst *pInst, uint8 InstId, void *pDst, void *pSrc,
                                                  uint32 Size );
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_DisableAllInterrupts(SUclALOsVliteInst *pInst, uint8 InstId);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_EnableAllInterrupts(SUclALOsVliteInst *pInst, uint8 InstId);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_MutexCreate(SUclALOsVliteInst *pInst, uint8 InstId, uint32 *pMutexId);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_MutexDestroy(SUclALOsVliteInst *pInst, uint8 InstId, uint32 MutexId);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_TaskCreate(SUclALOsVliteInst *pInst, uint8 InstId, uint32 *pThreadId,
                                                     TUclOsTaskEntryFunc pFunc, void *pData);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_TaskDestroy(SUclALOsVliteInst *pInst, uint8 InstId, uint32 ThreadId);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_MutexLock(SUclALOsVliteInst *pInst, uint8 InstId, uint32 MutexId);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_MutexTryLock(SUclALOsVliteInst *pInst, uint8 InstId, uint32 MutexId);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_MutexUnlock(SUclALOsVliteInst *pInst, uint8 InstId, uint32 MutexId);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_TimerCreate(SUclALOsVliteInst *pInst, uint8 InstId, uint32 *pTimerId,
                                                      TUclOsTaskEntryFunc pFunc, void *pData, EUclOsTimerType TimerType);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_TimerStart(SUclALOsVliteInst *pInst, uint8 InstId, uint32 TimerId, uint32 Timeout);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_TimerStop(SUclALOsVliteInst *pInst, uint8 InstId, uint32 TimerId);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_TimerDestroy(SUclALOsVliteInst *pInst, uint8 InstId, uint32 TimerId);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_SemCreate(SUclALOsVliteInst *pInst, uint8 InstId, uint32 *pSemId, uint8 Val);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_SemDestroy(SUclALOsVliteInst *pInst, uint8 InstId, uint32 SemId);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_SemWait(SUclALOsVliteInst *pInst, uint8 InstId, uint32 SemId);
Ucl_ReturnType UclALOsVlite_Impl_IUclALOs_SemPost(SUclALOsVliteInst *pInst, uint8 InstId, uint32 SemId);
uint64 UclALOsVlite_Impl_IUclALOs_GetSystemTimeMs(SUclALOsVliteInst *pInst, uint8 InstId);
uint32 UclALOsVlite_Impl_IUclALOs_GetSystemTimeResolutionMs(SUclALOsVliteInst *pInst, uint8 InstId);
void UclALOsVlite_Impl_IUclALOs_Tick(SUclALOsVliteInst *pInst, uint8 InstId);

#endif //UCLALOS_VLITEARCH3IMPL
