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
/// UCL Debug Layer Abstraction Implementation for Null.
/// APIs in this file are not to called directly by the users
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALDEBUG_NULLIMPL
#define UCLALDEBUG_NULLIMPL

#include "UclALDebug.h"

///
/// @brief Configruation structure for UclALDebugNull
///
/// The SUclALDebugConsoleCfg structure defines the configuration
/// data for SUclALDebugNull_Impl class.
///
typedef struct SUclALDebugNullCfg_t
{
    uint8 dummy;
} SUclALDebugNullCfg;

///
/// @brief Instance Structure for UclALDebugConsole
///
/// The SUclALOsPOSIXInst structure defines the private
/// instance data for SUclALDebugNull_Impl class.
///

typedef struct SUclALDebugNullInst_t
{
    SUclALDebugNullCfg *pCfg; ///< Pointer to the configuration structure
} SUclALDebugNullInst;

void UclALDebugNull_Impl_IUclALDebug_Initialize ( SUclALDebugNullInst *pInst, uint8 InstId );
void UclALDebugNull_Impl_IUclALDebug_Shutdown ( SUclALDebugNullInst *pInst, uint8 InstId );
void UclALDebugNull_Impl_IUclALDebug_SetLevel ( SUclALDebugNullInst *pInst, uint8 InstId, EUclALDebugLevel Level );
void UclALDebugNull_Impl_IUclALDebug_Log ( SUclALDebugNullInst *pInst, uint8 InstId, EUclALDebugLevel Level, char8 *pTag,
        char8 *pMsg );

#endif //UCLALDEBUG_NULLIMPL
