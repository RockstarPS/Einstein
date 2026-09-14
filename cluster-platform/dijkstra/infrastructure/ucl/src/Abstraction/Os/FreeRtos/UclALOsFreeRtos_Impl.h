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

typedef struct SUclALOsFreeRtosInst_t SUclALOsFreeRtosInst;

///
/// @brief Timer Structure for the AUTOSAR OSAL
///
/// The SUclALOsFreeRtosTimerList structure defines the data for the timers
///
typedef struct SUclALOsFreeRtosTimerList_t
{
    EUclOsTimerResState state; ///< Timer current state
    TUclOsTaskEntryFunc pFunc; ///< Timer callback function
    void *pData;               ///< Data for the callback function
    EUclOsTimerType type;      ///< Timer type
    uint32 timeout;            ///< Timout for the timer
    uint32 count;              ///< Current timer count
} SUclALOsFreeRtosTimerList;

///
/// @brief Configuration Structure for UclALOsFreeRtos_Impl.
///
/// The SUclALOsFreeRtosCfg structure defines the configuration data for UclALOsFreeRtos_Impl class.
///
typedef struct SUclALOsFreeRtosCfg_t
{
    uint8 tickResolutionMs;           ///< Duration with which the tick API will be called
    uint8 maxTimers;                  ///< Maximum number of Timers supported
    SUclALOsFreeRtosTimerList *pTimerList; ///< Array of Timers
} SUclALOsFreeRtosCfg;

///
/// @brief Instance Structure for UclALOsFreeRtos_Impl.
/// @ingroup UclALOs
/// The SUclALOsFreeRtosInst structure defines the private instance data for UclALOsFreeRtos_Impl class.
///
struct SUclALOsFreeRtosInst_t
{
    uint64 elapsedTicksInMs; ///< Elapsed ticks in millisecond
    SUclALOsFreeRtosCfg *pCfg;
};

Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_Initialize ( SUclALOsFreeRtosInst *pInst, uint8 InstId );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_Shutdown ( SUclALOsFreeRtosInst *pInst, uint8 InstId );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_Memset ( SUclALOsFreeRtosInst *pInst, uint8 InstId, void *pBuffer, uint8 val,
        uint32 size );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_Memcpy ( SUclALOsFreeRtosInst *pInst, uint8 InstId, void *pDst, void *pSrc,
        uint32 Size );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_Memcmp ( SUclALOsFreeRtosInst *pInst, uint8 InstId, void *pDst, void *pSrc,
        uint32 Size );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_DisableAllInterrupts ( SUclALOsFreeRtosInst *pInst, uint8 InstId );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_EnableAllInterrupts ( SUclALOsFreeRtosInst *pInst, uint8 InstId );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_MutexCreate ( SUclALOsFreeRtosInst *pInst, uint8 InstId, uint32 *pMutexId );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_MutexDestroy ( SUclALOsFreeRtosInst *pInst, uint8 InstId, uint32 MutexId );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_TaskCreate ( SUclALOsFreeRtosInst *pInst, uint8 InstId, uint32 *pThreadId,
        TUclOsTaskEntryFunc pFunc, void *pData );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_TaskDestroy ( SUclALOsFreeRtosInst *pInst, uint8 InstId, uint32 ThreadId );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_MutexLock ( SUclALOsFreeRtosInst *pInst, uint8 InstId, uint32 MutexId );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_MutexTryLock ( SUclALOsFreeRtosInst *pInst, uint8 InstId, uint32 MutexId );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_MutexUnlock ( SUclALOsFreeRtosInst *pInst, uint8 InstId, uint32 MutexId );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_TimerCreate ( SUclALOsFreeRtosInst *pInst, uint8 InstId, uint32 *pTimerId,
        TUclOsTaskEntryFunc pFunc, void *pData, EUclOsTimerType TimerType );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_TimerStart ( SUclALOsFreeRtosInst *pInst, uint8 InstId, uint32 TimerId, uint32 Timeout );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_TimerStop ( SUclALOsFreeRtosInst *pInst, uint8 InstId, uint32 TimerId );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_TimerDestroy ( SUclALOsFreeRtosInst *pInst, uint8 InstId, uint32 TimerId );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_SemCreate ( SUclALOsFreeRtosInst *pInst, uint8 InstId, uint32 *pSemId, uint8 Val );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_SemDestroy ( SUclALOsFreeRtosInst *pInst, uint8 InstId, uint32 SemId );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_SemWait ( SUclALOsFreeRtosInst *pInst, uint8 InstId, uint32 SemId );
Ucl_ReturnType UclALOsFreeRtos_Impl_IUclALOs_SemPost ( SUclALOsFreeRtosInst *pInst, uint8 InstId, uint32 SemId );
uint64 UclALOsFreeRtos_Impl_IUclALOs_GetSystemTimeMs ( SUclALOsFreeRtosInst *pInst, uint8 InstId );
uint32 UclALOsFreeRtos_Impl_IUclALOs_GetSystemTimeResolutionMs ( SUclALOsFreeRtosInst *pInst, uint8 InstId );
void UclALOsFreeRtos_Impl_IUclALOs_Tick ( SUclALOsFreeRtosInst *pInst, uint8 InstId );

#endif //UCLALOS_ASRIMPL
