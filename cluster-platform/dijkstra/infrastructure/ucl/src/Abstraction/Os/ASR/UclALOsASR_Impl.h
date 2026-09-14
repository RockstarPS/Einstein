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
#ifndef UCLALOS_ASRIMPL
#define UCLALOS_ASRIMPL

#include "UclALOs_Types.h"

typedef struct SUclALOsASRInst_t SUclALOsASRInst;

///
/// @brief Timer Structure for the AUTOSAR OSAL
///
/// The SUclALOsASRTimerList structure defines the data for the timers
///
typedef struct SUclALOsASRTimerList_t
{
    EUclOsTimerResState state; ///< Timer current state
    TUclOsTaskEntryFunc pFunc; ///< Timer callback function
    void *pData;               ///< Data for the callback function
    EUclOsTimerType type;      ///< Timer type
    uint32 timeout;            ///< Timout for the timer
    uint32 count;              ///< Current timer count
} SUclALOsASRTimerList;

///
/// @brief Configuration Structure for UclALOsASR_Impl.
///
/// The SUclALOsASRCfg structure defines the configuration data for UclALOsASR_Impl class.
///
typedef struct SUclALOsASRCfg_t
{
    uint8 tickResolutionMs;           ///< Duration with which the tick API will be called
    uint8 maxTimers;                  ///< Maximum number of Timers supported
    SUclALOsASRTimerList *pTimerList; ///< Array of Timers
} SUclALOsASRCfg;

///
/// @brief Instance Structure for UclALOsASR_Impl.
/// @ingroup UclALOs
/// The SUclALOsASRInst structure defines the private instance data for UclALOsASR_Impl class.
///
struct SUclALOsASRInst_t
{
    uint64 elapsedTicksInMs; ///< Elapsed ticks in millisecond
    SUclALOsASRCfg *pCfg;
};

Ucl_ReturnType UclALOsASR_Impl_IUclALOs_Initialize ( SUclALOsASRInst *pInst, uint8 InstId );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_Shutdown ( SUclALOsASRInst *pInst, uint8 InstId );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_Memset ( SUclALOsASRInst *pInst, uint8 InstId, void *pBuffer, uint8 val,
        uint32 size );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_Memcpy ( SUclALOsASRInst *pInst, uint8 InstId, void *pDst, void *pSrc,
        uint32 Size );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_Memcmp ( SUclALOsASRInst *pInst, uint8 InstId, void *pDst, void *pSrc,
        uint32 Size );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_DisableAllInterrupts ( SUclALOsASRInst *pInst, uint8 InstId );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_EnableAllInterrupts ( SUclALOsASRInst *pInst, uint8 InstId );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_MutexCreate ( SUclALOsASRInst *pInst, uint8 InstId, uint32 *pMutexId );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_MutexDestroy ( SUclALOsASRInst *pInst, uint8 InstId, uint32 MutexId );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_TaskCreate ( SUclALOsASRInst *pInst, uint8 InstId, uint32 *pThreadId,
        TUclOsTaskEntryFunc pFunc, void *pData );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_TaskDestroy ( SUclALOsASRInst *pInst, uint8 InstId, uint32 ThreadId );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_MutexLock ( SUclALOsASRInst *pInst, uint8 InstId, uint32 MutexId );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_MutexTryLock ( SUclALOsASRInst *pInst, uint8 InstId, uint32 MutexId );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_MutexUnlock ( SUclALOsASRInst *pInst, uint8 InstId, uint32 MutexId );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_TimerCreate ( SUclALOsASRInst *pInst, uint8 InstId, uint32 *pTimerId,
        TUclOsTaskEntryFunc pFunc, void *pData, EUclOsTimerType TimerType );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_TimerStart ( SUclALOsASRInst *pInst, uint8 InstId, uint32 TimerId, uint32 Timeout );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_TimerStop ( SUclALOsASRInst *pInst, uint8 InstId, uint32 TimerId );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_TimerDestroy ( SUclALOsASRInst *pInst, uint8 InstId, uint32 TimerId );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_SemCreate ( SUclALOsASRInst *pInst, uint8 InstId, uint32 *pSemId, uint8 Val );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_SemDestroy ( SUclALOsASRInst *pInst, uint8 InstId, uint32 SemId );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_SemWait ( SUclALOsASRInst *pInst, uint8 InstId, uint32 SemId );
Ucl_ReturnType UclALOsASR_Impl_IUclALOs_SemPost ( SUclALOsASRInst *pInst, uint8 InstId, uint32 SemId );
uint64 UclALOsASR_Impl_IUclALOs_GetSystemTimeMs ( SUclALOsASRInst *pInst, uint8 InstId );
uint32 UclALOsASR_Impl_IUclALOs_GetSystemTimeResolutionMs ( SUclALOsASRInst *pInst, uint8 InstId );
void UclALOsASR_Impl_IUclALOs_Tick ( SUclALOsASRInst *pInst, uint8 InstId );

#endif //UCLALOS_ASRIMPL
