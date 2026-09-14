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
/// @ingroup UclALDebug
/// UCL Debug Abstraction Layer Type Definitions
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALDEBUGTYPES_H
#define UCLALDEBUGTYPES_H

#include "Ucl_Types.h" //MISRA C++-2008 Rule 16-0-1

#ifdef __cplusplus
extern "C" {
#endif

///
/// @brief Debug Level
///
typedef enum {
    eUclALDebugLevel_Debug,  ///< Log all message equal and above Debug level
    eUclALDebugLevel_Info,  ///< Log all message equal and above Info level
    eUclALDebugLevel_Warn,  ///< Log all message equal and above Warn level
    eUclALDebugLevel_Error, ///< Log all message equal and above Error level
    eUclALDebugLevel_Last   ///< Guard
} EUclALDebugLevel;

#ifdef __cplusplus
}
#endif
#endif //UCLALDEBUGTYPES_H
