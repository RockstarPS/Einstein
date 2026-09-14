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
#ifndef UCLALDEBUG_SYSLOGIMPL
#define UCLALDEBUG_SYSLOGIMPL

#include "UclALDebug.h"
#include <syslog.h>  
// @brief Configuration structure for UclALDebugSyslog
typedef struct
{
    EUclALDebugLevel logLevel; ///< Log print level configuration
} SUclALDebugSyslogCfg;

// @brief Instance structure for UclALDebugSyslog
typedef struct
{
    EUclALDebugLevel logLevel;   ///< Log print level configuration
    SUclALDebugSyslogCfg *pCfg; ///< Pointer to the configuration structure
} SUclALDebugSyslogInst;

void UclALDebugSyslog_Impl_IUclALDebug_Initialize ( SUclALDebugSyslogInst *pInst, uint8 InstId );
void UclALDebugSyslog_Impl_IUclALDebug_Shutdown ( SUclALDebugSyslogInst *pInst, uint8 InstId );
void UclALDebugSyslog_Impl_IUclALDebug_SetLevel ( SUclALDebugSyslogInst *pInst, uint8 InstId, EUclALDebugLevel Level );
void UclALDebugSyslog_Impl_IUclALDebug_Log ( SUclALDebugSyslogInst *pInst, uint8 InstId, EUclALDebugLevel Level, char8 *pTag, char8 *pMsg );

#endif // UCLALDEBUG_SYSLOGIMPL

