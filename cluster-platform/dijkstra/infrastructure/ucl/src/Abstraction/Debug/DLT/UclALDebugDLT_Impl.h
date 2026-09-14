///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2024] Visteon Corporation
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
/// UCL Debug Layer Abstraction Implementation for logging on to Console.
/// APIs in this file are not to called directly by the users
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALDEBUG_DLTIMPL
#define UCLALDEBUG_DLTIMPL

#include "UclALDebug.h"
#include <dlt/dlt.h>

///
/// @brief Configuration structure for UclALDebugDLT
///
/// The SUclALDebugDLTCfg structure defines the configuration
/// data for UclALDebugDLT_Impl class.
///
typedef struct SUclALDebugDLTCfg_t
{
    EUclALDebugLevel logLevel; ///< Log print level configuration
} SUclALDebugDLTCfg;

///
/// @brief Instance Structure for UclALDebugDLT
///
/// The SUclALDebugDLTInst_t structure defines the private
/// instance data for UclALDebugDLT_Impl class.
///
typedef struct SUclALDebugDLTInst_t
{
    SUclALDebugDLTCfg *pCfg;       ///< Pointer to the configuration structure
    DltContext DltContext;         ///< DLT Contenxt
    DltLogLevelType DltLogLvl;     ///< DLT log level
    DltContextData ContextData;    ///< DLT Context data
    uint32 wrMutexId;              ///< Write Protection Mutex
} SUclALDebugDLTInst;

///
/// @brief Function to initialize debug layer.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller.
///
/// @return None.
///
///
void UclALDebugDLT_Impl_IUclALDebug_Initialize ( SUclALDebugDLTInst *pInst, uint8 InstId );

///
/// @brief Function to close debug session.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller.
///
/// @return None.
///
///
void UclALDebugDLT_Impl_IUclALDebug_Shutdown ( SUclALDebugDLTInst *pInst, uint8 InstId );

///
/// @brief Function to set debug level.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller.
/// @param Level Debug level.
///
/// @return None.
///
///
void UclALDebugDLT_Impl_IUclALDebug_SetLevel ( SUclALDebugDLTInst *pInst, uint8 InstId, EUclALDebugLevel Level );

///
/// @brief Function to write debug log.
///
/// @param pInst  Instance Pointer.
/// @param InstId Instance ID of the caller.
/// @param Level Debug level.
/// @param pTag Pointer to the tag information.
/// @param pMsg Pointer to the log message.
///
/// @return None.
///
///
void UclALDebugDLT_Impl_IUclALDebug_Log ( SUclALDebugDLTInst *pInst, uint8 InstId, EUclALDebugLevel Level,
        const char8 *pTag, const char8 *pMsg );

#endif //UCLALDEBUG_DLTIMPL
