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

#ifdef __cplusplus

#include "dk_logger_impl.h"
#include <unistd.h>

template <typename T, typename... TArgs>
void log ( DltContext *const context, DltLogLevelType loglevel, T value, TArgs... args )
{
    std::stringstream ss;
    dk::Logger *inst ( dk::Logger::getInstance() );

    if ( !inst->getEnabled() )
    {
        return;
    }

    if ( !inst->init ( loglevel, context ) )
    {
        return;
    }

    ss << getpid();
    std::string pidInfo = "(" + ss.str() + "|" + ss.str() + ") ";
    inst->append ( pidInfo );
    inst->append ( inst->getFileName ( value ) );
    inst->append ( args... );
    inst->send();
}

template <typename T, typename... TArgs>
void logDebug ( DltContext *const pContext, T value, TArgs... args )
{
    log ( pContext, DLT_LOG_DEBUG, value, args... );
}

template <typename T, typename... TArgs>
void logInfo ( DltContext *const pContext, T value, TArgs... args )
{
    log ( pContext, DLT_LOG_INFO, value, args... );
}

template <typename T, typename... TArgs>
void logError ( DltContext *const pContext, T value, TArgs... args )
{
    log ( pContext, DLT_LOG_ERROR, value, args... );
}

template <typename T, typename... TArgs>
void logWarning ( DltContext *const pContext, T value, TArgs... args )
{
    log ( pContext, DLT_LOG_WARN, value, args... );
}

template <typename T, typename... TArgs>
void logVerbose ( DltContext *const pContext, T value, TArgs... args )
{
    log ( pContext, DLT_LOG_VERBOSE, value, args... );
}

///
/// @def LOG_DECLARE_CONTEXT(CONTEXT)
/// @ingroup Logger
///
/// @brief Declare the logging context
/// @param CONTEXT Context Variable
///
#define LOG_DECLARE_CONTEXT(CONTEXT) DltContext CONTEXT

///
/// @def DLT_IMPORT_CONTEXT(CONTEXT)
/// @ingroup Logger
///
/// @brief Import the logging context
/// @param CONTEXT Context Variable
///
#define LOG_IMPORT_CONTEXT(CONTEXT) extern DltContext CONTEXT

///
/// @def LOG_REGISTER_APP_DLT(NAME, DESC)
/// @ingroup Logger
///
/// @brief Registers the application to log messages to DLT
/// @param NAME string Name of the application
/// @param DESC string Description of the appication
///
#define LOG_REGISTER_APP_DLT(NAME, DESC) dk::Logger::createInstance(NAME, DESC, true, dk::Logger::eLogDestination_DLT)

///
/// @def LOG_REGISTER_APP_CONSOLE(NAME, DESC)
/// @ingroup Logger
///
/// @brief Registers the application to log messages to the Console
/// @param NAME string Name of the application
/// @param DESC string Description of the appication
///
#define LOG_REGISTER_APP_CONSOLE(NAME, DESC) dk::Logger::createInstance(NAME, DESC, true, dk::Logger::eLogDestination_Console)

///
/// @def LOG_REGISTER_APP_CONSOLE_SILENT(NAME, DESC)
/// @ingroup Logger
///
/// @brief Registers the application to log messages to the Console, does not print DLT registration messages
/// @param NAME string Name of the application
/// @param DESC string Description of the appication
///
#define LOG_REGISTER_APP_CONSOLE_SILENT(NAME, DESC) dk::Logger::createInstance(NAME, DESC, true, dk::Logger::eLogDestination_Console, true)

///
/// @def LOG_REGISTER_APP_SLOG2(NAME, DESC, FILE)
/// @ingroup Logger
///
/// @brief Registers the application to log messages to the Slogger2
/// @param NAME string Name of the application
/// @param DESC string Description of the appication
///
#define LOG_REGISTER_APP_SLOG2(NAME, DESC) dk::Logger::createInstance(NAME, DESC, true, dk::Logger::eLogDestination_Slog2, true)

///
/// @def LOG_REGISTER_APP_FILE(NAME, DESC, FILE)
/// @ingroup Logger
///
/// @brief Registers the application to log messages to the Console
/// @param NAME string Name of the application
/// @param DESC string Description of the appication
/// @param FILE string Filename of the log file including the path
///
#define LOG_REGISTER_APP_FILE(NAME, DESC, FILE) dk::Logger::createInstance(NAME, DESC, true, dk::Logger::eLogDestination_File, false, FILE)

///
/// @def LOG_REGISTER_APP_EX(NAME, DESC, ENABLE, DEST, FILE, ONLY_ERROR, SILENT)
/// @ingroup Logger
///
/// @brief Registers the application to log messages, provides addtional options
/// @param NAME         string Name of the application
/// @param DESC         string Description of the appication
/// @param ENABLE       bool   true - Enable logging, false - Disable logging
/// @param DEST         enum   Logging destination
/// @param SILENT       bool   true - suppress registration messages, false - Log all messages
/// @param FILE         string Filename of the log file including the path
/// @param ONLY_ERROR   bool   true - Log only errors, false - Log all messages
///
#define LOG_REGISTER_APP_EX(NAME, DESC, ENABLE, DEST, FILE, ONLY_ERROR, SILENT) dk::Logger::createInstance(NAME, DESC, ENABLE, DEST, SILENT, FILE, ONLY_ERROR)

///
/// @def LOG_REGISTER_CONTEXT(HNDL, TAG, DESC)
/// @ingroup Logger
///
/// @brief Registers a new context
/// @param HNDL  DltContext DLT Context handle to store the context
/// @param TAG   string    Name of the context
/// @param DESC  string    Description of the context
/// @param LEVEL string    Loglevel for this context
///
#define LOG_REGISTER_CONTEXT(HNDL, TAG, DESC, LEVEL) dk::Logger::getInstance()->registerContext(HNDL, TAG, DESC, LEVEL, DLT_TRACE_STATUS_OFF);

///
/// @def LOG_UNREGISTER_CONTEXT(HNDL)
/// @ingroup Logger
///
/// @brief Registers a new context
/// @param HNDL DltContext DLT Context handle to unregister
///
#define LOG_UNREGISTER_CONTEXT(HNDL) dk::Logger::getInstance()->unregisterContext(HNDL);

///
/// @def LOGV(HNDL, ...)
/// @ingroup Logger
/// Log verbose message.
///
/// @brief This level is the most detailed level and should be used for in depth debug information
/// that can help developers debug the functionality of their software
///   * Detailed trace information
///   * Dumps of a large number of variables, dumps of arrays and structures
///   * Detailed information about events received, even events that happen very frequently
///   * Detailed network connection information
///   * Detailed hardware information
///   * Information about loops and iterations
///
/// @param HNDL DltContext* Pointer to the DLT Context handle
/// @param ...  Comma seperated variable length arguments to log
///
#define LOGV(HNDL, ...) logVerbose(HNDL, __FILE__, ":", __LINE__, ":", __FUNCTION__, ": ", ##__VA_ARGS__)

///
/// @def LOGD(HNDL, ...)
/// @ingroup Logger
/// Log debug messages.
///
/// @brief This level should be used for debug information that can help developers debug the
/// functionality of their software
///   * Information about entering and exiting major procedures
///   * Values of key variables, but not dumps of arrays and large number of variables
///   * Information about events received
///   * Network connection information
///   * Debug relevant information about hardware
///
/// @param HNDL DltContext* Pointer to the DLT Context handle
/// @param ...  Comma seperated variable length arguments to log
///
#define LOGD(HNDL, ...) logDebug(HNDL, __FILE__, ":", __LINE__, ":", __FUNCTION__, ": ", ##__VA_ARGS__)

///
/// @def LOGI(HNDL, ...)
/// @ingroup Logger
/// Log info messages.
///
/// @brief This level is reserved for key information and high-level events which are
/// not errors or warnings of the system itself or of connected consumer devices.
///   * Start and non-error related stop of software components. Include version information in start log.
///   * Detection of key hardware components. Include key HW information in log.
///   * Customer device connected. Include key device and media info.
///   * Customer device detached or connection lost.
///   * Failure to connect to customer device. Include reason
///   * Corrupted disk, song, photo, etc. on customer device.
///   * Key system/HW information at start-up
///   * Information needed for reproducing and understanding user activity
///   * Information for reproducing the environment (Large volume data such as GPS traces should be logged at a reasonable rate. Especially with very frequent logs it should be taken care of that no redundancy occurs)
///   * Key information used for KPI (Key performance index) reporting
///
/// @param HNDL DltContext* Pointer to the DLT Context handle
/// @param ...  Comma seperated variable length arguments to log
///
#define LOGI(HNDL, ...) logInfo(HNDL, __FILE__, ":", __LINE__, ":", __FUNCTION__, ": ", ##__VA_ARGS__)

///
/// @def LOGW(HNDL, ...)
/// @ingroup Logger
/// Log warning messages
///
/// @brief This level must be used for problems where a correct behavior cannot be ensured,
/// i.e. problems that could affect the correct functionality of the system or its components.
/// Warnings related to connected customer devices such as phones must be logged at INFO level.
///   * Most congestions
///   * DLT dropping logs
///   * No disk space for available for coredump
///   * Audio stream packet dropped
///   * If a process of calculation takes longer than the time allowed in specification e.g. Calculation of route in the navigation takes longer than allowed
///
/// @param HNDL DltContext* Pointer to the DLT Context handle
/// @param ...  Comma seperated variable length arguments to log
///
#define LOGW(HNDL, ...) logWarning(HNDL, __FILE__, ":", __LINE__, ":", __FUNCTION__, ": ", ##__VA_ARGS__)

///
/// @def LOGE(HNDL, ...)
/// @ingroup Logger
/// Log error messages
///
/// @brief This level is reserved for errors which impact the correct functionality of the system or its components.
///   * A critical component is failing or cannot be found
///   * A system component is crashing
///   * An system essential file can’t be read or written
///   * Detection of corrupted network messages, files, etc. when these impact correct
///   * Some major functionality could not be provided (e.g. the route in the navigation could not be calculated)
///   * When your software/process/component exits due to an error. Log the EXIT and reason
///
/// @param HNDL DltContext* Pointer to the DLT Context handle
/// @param ...  Comma seperated variable length arguments to log
///
#define LOGE(HNDL, ...) logError(HNDL, __FILE__, ":", __LINE__, ":", __FUNCTION__, ": ", ##__VA_ARGS__)

#else //__cplusplus

//#include <netdb.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifdef DK_DLT_ENABLED
#include "dlt/dlt.h"
#else //DK_DLT_ENABLED
#define DLT_USER_BUF_MAX_SIZE 2048
typedef struct
{
    char contextID[4];
    int32_t log_level_pos;
    int32_t log_level_user;
} DltContext;

typedef enum
{
    DLT_LOG_DEFAULT = -1,
    DLT_LOG_OFF = 0x00,
    DLT_LOG_FATAL = 0x01,
    DLT_LOG_ERROR = 0x02,
    DLT_LOG_WARN = 0x03,
    DLT_LOG_INFO = 0x04,
    DLT_LOG_DEBUG = 0x05,
    DLT_LOG_VERBOSE = 0x06
} DltLogLevelType;

typedef enum
{
    DLT_TRACE_STATUS_DEFAULT = -1,
    DLT_TRACE_STATUS_OFF = 0x00,
    DLT_TRACE_STATUS_ON = 0x01
} DltTraceStatusType;
#endif //DK_DLT_ENABLED

#ifndef TRUE
    #define TRUE (1u)
#endif

#ifndef FALSE
    #define FALSE (0u)
#endif

#ifndef NULL
    #define NULL ((void *)0u)
#endif

typedef enum eLogDestination
{
    eLogDestination_DLT = 0,     ///< Log to DLT Daemon
    eLogDestination_Console = 1, ///< Log to Console
    eLogDestination_File = 2,    ///< Log to File
    eLogDestination_Slog2 = 3    ///< Log to Slogger
} eLogDestination_t;

void dk_Logger_createInstance ( const char *pName, const char *pDesc, uint8_t bEnable, eLogDestination_t dest, uint8_t bSilent, const char *pFile, uint8_t bOnlyError );
void dk_Logger_registerContext ( DltContext *pHandle, const char *pContextId, const char *pDescription, DltLogLevelType logLevel, DltTraceStatusType traceStatus );
void dk_Logger_unregisterContext ( DltContext *pHandle );
void dk_Logger_log ( DltContext *pHandle, DltLogLevelType logLevel, const char *pFileName, const char *pDelim1,
        uint32_t lineNo, const char *pDelim2, const char *pFuncName, const char *pDelim3, const char *fmt, ... );

#define LOG_DECLARE_CONTEXT(CONTEXT) DltContext CONTEXT
#define LOG_IMPORT_CONTEXT(CONTEXT) extern DltContext CONTEXT
#define LOG_REGISTER_APP_DLT(NAME, DESC) dk_Logger_createInstance(NAME, DESC, TRUE, eLogDestination_DLT, FALSE, NULL, FALSE)
#define LOG_REGISTER_APP_SLOG2(NAME, DESC) dk_Logger_createInstance(NAME, DESC, TRUE, eLogDestination_Slog2, FALSE, NULL, FALSE)
#define LOG_REGISTER_APP_CONSOLE(NAME, DESC) dk_Logger_createInstance(NAME, DESC, TRUE, eLogDestination_Console, FALSE, NULL, FALSE)
#define LOG_REGISTER_APP_CONSOLE_SILENT(NAME, DESC) dk_Logger_createInstance(NAME, DESC, TRUE, eLogDestination_Console, TRUE, NULL, FALSE)
#define LOG_REGISTER_APP_FILE(NAME, DESC, FILE) dk_Logger_createInstance(NAME, DESC, TRUE, eLogDestination_Console, FALSE, FILE, FALSE)
#define LOG_REGISTER_APP_EX(NAME, DESC, ENABLE, DEST, FILE, ONLY_ERROR) dk_Logger_createInstance(NAME, DESC, ENABLE, DEST, FALSE, FILE, ONLY_ERROR)
#define LOG_REGISTER_CONTEXT(HNDL, TAG, DESC, LEVEL) dk_Logger_registerContext(&HNDL, TAG, DESC, LEVEL, DLT_TRACE_STATUS_OFF);
#define LOG_UNREGISTER_CONTEXT(HNDL) dk_Logger_unregisterContext(&HNDL);
#define LOGV(HNDL, FMT, ...) dk_Logger_log(HNDL, DLT_LOG_VERBOSE, __FILE__, ":", __LINE__, ":", __FUNCTION__, ": ", FMT, ##__VA_ARGS__)
#define LOGD(HNDL, FMT, ...) dk_Logger_log(HNDL, DLT_LOG_DEBUG, __FILE__, ":", __LINE__, ":", __FUNCTION__, ": ", FMT, ##__VA_ARGS__)
#define LOGI(HNDL, FMT, ...) dk_Logger_log(HNDL, DLT_LOG_INFO, __FILE__, ":", __LINE__, ":", __FUNCTION__, ": ", FMT, ##__VA_ARGS__)
#define LOGW(HNDL, FMT, ...) dk_Logger_log(HNDL, DLT_LOG_WARN, __FILE__, ":", __LINE__, ":", __FUNCTION__, ": ", FMT, ##__VA_ARGS__)
#define LOGE(HNDL, FMT, ...) dk_Logger_log(HNDL, DLT_LOG_ERROR, __FILE__, ":", __LINE__, ":", __FUNCTION__, ": ", FMT, ##__VA_ARGS__)

#endif //__cplusplus

#endif //DK_LOGGER_H
