//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2018] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
///
/// @mainpage
///
/// @section intro Introduction
///
/// Dijkstra Logger is the library that interfaces with the platform specific logging mechanism
///
/// @section features Features
///  Supports logging to
///    * GENIVI DLT
///    * Console
///    * File
///
/// @section build_instructions Build Instructions
///    * Add define DK_DLT_ENABLED
///    * Add include path to dk.lib.logger/rel/<os_arch>/public
///    * Add library libdk_logger.so
///
/// @section usage_instructions Usage Instructions
///    * Register Application
///    * Register one or more Context
///    * Log Messages
///    * Unregister context
///
/// @section cpp_example CPP Example
/// @code{.cpp}
///  #include "dk_logger.h"
///
///  int main()
///  {
///    LOG_DECLARE_CONTEXT(mLogContext1);
///    LOG_DECLARE_CONTEXT(mLogContext2);
///
///    LOG_REGISTER_APP_CONSOLE("TCPP", "Test CPP Application");
///    LOG_REGISTER_CONTEXT(mLogContext1, "MOD1", "Module 1 Context", DLT_LOG_VERBOSE);
///    LOG_REGISTER_CONTEXT(mLogContext2, "MOD2", "Module 2 Context", DLT_LOG_WARN);
///
///    LOGD(&mLogContext1, "Debug message ", 100, "and ", 200);
///    LOGV(&mLogContext1, "Verbose message ", "Hello", " World");
///    LOGI(&mLogContext1, "Info message");
///
///    LOGW(&mLogContext2, "Warning message");
///    LOGE(&mLogContext2, "Error message");
///
///    LOG_UNREGISTER_CONTEXT(mLogContext1);
///    LOG_UNREGISTER_CONTEXT(mLogContext2);
///  }
///
/// @endcode
/// @section c_example C Example
/// @code{.c}
///  #include "dk_logger.h"
///
///  int main()
///  {
///    LOG_DECLARE_CONTEXT(mLogContext1);
///    LOG_DECLARE_CONTEXT(mLogContext2);
///
///    LOG_REGISTER_APP_CONSOLE("TCEX", "Test C Application");
///    LOG_REGISTER_CONTEXT(mLogContext1, "MOD1", "Module 1 Context", DLT_LOG_VERBOSE);
///    LOG_REGISTER_CONTEXT(mLogContext2, "MOD2", "Module 2 Context", DLT_LOG_WARN);
///
///    LOGD(&mLogContext1, "Debug message %d and %d", 100, 200);
///    LOGV(&mLogContext1, "Verbose message %s %s", "Hello", "World");
///    LOGI(&mLogContext1, "Info message");
///
///    LOGW(&mLogContext2, "Warning message");
///    LOGE(&mLogContext2, "Error message");
///
///    LOG_UNREGISTER_CONTEXT(mLogContext1);
///    LOG_UNREGISTER_CONTEXT(mLogContext2);
///  }
///
/// @endcode
/// @defgroup Logger Dijkstra Logger APIs
///
/// @file dk_logger.h
///
/// @ingroup Logger
///
//---------------------------------------------------------------------------------------------------------------------

#ifndef DK_LOGGER_H
#define DK_LOGGER_H

#include <dlt/dlt.h>

typedef struct
{
    char contextID[4];
    int32_t log_level_pos;
    int32_t log_level_user;
} DltContext;

#define LOG_DECLARE_CONTEXT(CONTEXT) DltContext CONTEXT
#define LOG_IMPORT_CONTEXT(CONTEXT) extern DltContext CONTEXT

#define LOG_REGISTER_CONTEXT(HNDL, TAG, DESC, LEVEL)
#define LOG_UNREGISTER_CONTEXT(HNDL)
#define LOGI(HNDL, ...)
#define LOGE(HNDL, ...) 
#define LOGV(HNDL, ...)
#define LOGW(HNDL, ...)


#endif //DK_LOGGER_H
