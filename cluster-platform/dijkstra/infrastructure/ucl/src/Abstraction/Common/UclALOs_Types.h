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
/// UCL Operating System Abstraction Types.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALOSTYPES_H
#define UCLALOSTYPES_H

#include "Ucl_Types.h" //MISRA C++-2008 Rule 16-0-1

#ifdef __cplusplus
extern "C" {
#endif

///
/// @brief Callback function pointer type for OS services
///
typedef void *(*TUclOsTaskEntryFunc)(void *pData);

///
/// @brief Enumeration for OS Timer Type
///
typedef enum {
    eUclOsTimerType_OneShot,  ///< One shot timer. Callback will be called once.
    eUclOsTimerType_Periodic, ///< Periodic timer. Callback will be called as per periodictiy.
    eUclOsTimerType_Last      ///< Guard
} EUclOsTimerType;

///
/// @brief Enumeration for Mutex Resource States
///
typedef enum {
    eUclOsMutexResState_UnInit,    ///< Mutex UnInitialized
    eUclOsMutexResState_Created,   ///< Mutex Created
    eUclOsMutexResState_Destroyed, ///< Mutex Destroyed
    eUclOsMutexResState_Locked,    ///< Mutex Locked
    eUclOsMutexResState_UnLocked,  ///< Mutex UnLocked
    eUclOsMutexResState_Last       ///< Guard
} EUclOsMutexResState;

///
/// @brief Enumeration for Task Resource States
///
typedef enum {
    eUclOsTaskResState_UnInit,    ///< Task UnInitialized
    eUclOsTaskResState_Created,   ///< Task Created
    eUclOsTaskResState_Destroyed, ///< Task Destroyed
    eUclOsTaskResState_Last       ///< Guard
} EUclOsTaskResState;

///
/// @brief Enumeration for Timer Resource States
///
typedef enum {
    eUclOsTimerResState_UnInit,    ///< Timer UnInitialized
    eUclOsTimerResState_Created,   ///< Timer Created
    eUclOsTimerResState_Destroyed, ///< Timer Destroyed
    eUclOsTimerResState_Running,   ///< Timer Running
    eUclOsTimerResState_Stopped,   ///< Timer Stopped
    eUclOsTimerResState_Last       ///< Guard
} EUclOsTimerResState;

///
/// @brief Enumeration for Semaphore Resource States
///
typedef enum {
    eUclOsSemResState_UnInit,    ///< Semaphore UnInitialized
    eUclOsSemResState_Created,   ///< Semaphore Created
    eUclOsSemResState_Destroyed, ///< Semaphore Destroyed
    eUclOsSemResState_Last       ///< Guard
} EUclOsSemResState;

#ifdef __cplusplus
}
#endif
#endif //UCLALOSTYPES_H
