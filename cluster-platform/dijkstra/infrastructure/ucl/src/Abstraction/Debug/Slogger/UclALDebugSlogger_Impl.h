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
/// UCL Debug Layer Abstraction Implementation for logging on to Slogger.
/// APIs in this file are not to called directly by the users
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALDEBUG_SLOGGERIMPL
#define UCLALDEBUG_SLOGGERIMPL

#include "UclALDebug.h"
#include <sys/slog2.h>

///
/// @brief Configuration structure for UclALDebugSlogger
///
/// The SUclALDebugSloggerCfg structure defines the configuration
/// data for UclALDebugSlogger_Impl class.
///
typedef struct
{
    EUclALDebugLevel logLevel; ///< Log print level configuration
} SUclALDebugSloggerCfg;

///
/// @brief Instance Structure for UclALDebugSlogger
///
/// The SUclALOsPOSIXInst structure defines the private
/// instance data for UclALDebugSlogger_Impl class.
///
typedef struct
{
    EUclALDebugLevel logLevel;   ///< Log print level configuration
    SUclALDebugSloggerCfg *pCfg; ///< Pointer to the configuration structure

    slog2_buffer_set_config_t bufferConfig; ///< Slog2 buffer configuration
    slog2_buffer_t bufferHandle[1];         ///< Slog2 buffer handler
} SUclALDebugSloggerInst;

void UclALDebugSlogger_Impl_IUclALDebug_Initialize ( SUclALDebugSloggerInst *pInst, uint8 InstId );
void UclALDebugSlogger_Impl_IUclALDebug_Shutdown ( SUclALDebugSloggerInst *pInst, uint8 InstId );
void UclALDebugSlogger_Impl_IUclALDebug_SetLevel ( SUclALDebugSloggerInst *pInst, uint8 InstId, EUclALDebugLevel Level );
void UclALDebugSlogger_Impl_IUclALDebug_Log ( SUclALDebugSloggerInst *pInst, uint8 InstId, EUclALDebugLevel Level,
        char8 *pTag, char8 *pMsg );

#endif //UCLALDEBUG_SLOGGERIMPL
