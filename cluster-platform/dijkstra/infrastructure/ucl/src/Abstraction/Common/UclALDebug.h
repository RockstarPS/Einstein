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
/// @defgroup UclALDebug
/// @brief UCL Debug Abstraction Layer provides debug and trace services
/// @file
/// @ingroup UclALDebug
/// UCL Debug Abstraction Layer Interface APIs.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLALDEBUG_H
#define UCLALDEBUG_H

#include "UclALDebug_Types.h" //MISRA C++-2008 Rule 16-0-1

#ifdef __cplusplus
extern "C" {
#endif

#ifdef UCL_DEBUG_ON
#define LOGE(inst, tag, fmt, ...) UclALDebug_Log((inst), eUclALDebugLevel_Error, (tag), (fmt), ##__VA_ARGS__) // MISRA C++-2008 Rule 16-0-6, CID - 12255674
#define LOGW(inst, tag, fmt, ...) UclALDebug_Log((inst), eUclALDebugLevel_Warn, (tag), (fmt), ##__VA_ARGS__) //MISRA C++-2008 Rule 16-0-6, CID - 12256396
#define LOGI(inst, tag, fmt, ...) UclALDebug_Log((inst), eUclALDebugLevel_Info, (tag), (fmt), ##__VA_ARGS__) // MISRA C++-2008 Rule 16-0-6, CID - 12250830
#else
#define LOGE(inst, tag, fmt, ...)
#define LOGW(inst, tag, fmt, ...)
#define LOGI(inst, tag, fmt, ...)
#endif

///
/// @brief This method is used to initialize the UclALDebug Instance
///
/// @param InstId Instance Id to initialize
///
/// @return None
///
void UclALDebug_Initialize(uint8 InstId);

///
/// @brief This method is used to shutdown the UclALDebug Instance
///
/// @param InstId Instance Id to shutdown
///
/// @return None
///
void UclALDebug_Shutdown(uint8 InstId);

///
/// @brief This method is used to set the debug log level
///
/// @param InstId Instance Id
/// @param Level Log level
///
/// @return None
///
void UclALDebug_SetLevel(uint8 InstId, EUclALDebugLevel Level);

///
/// @brief This method is used to log a debug message
///        Use the helper macros LOGI, LOGW, LOGE
///
/// @param InstId Instance Id
/// @param Level Log level
/// @param tag Debug Tag
///
/// @return None
///
void UclALDebug_Log(uint8 InstId, EUclALDebugLevel Level, const char8 *tag, const char8 *fmt, ...);

#ifdef __cplusplus
}
#endif
#endif //UCLALDEBUG_H
