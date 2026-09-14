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

#ifndef DK_LOGGER_H
#define DK_LOGGER_H


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
    #define TRUE (1U)
#endif

#ifndef FALSE
    #define FALSE (0U)
#endif

#ifndef NULL
    #define NULL ((void *)0U)
#endif

typedef enum eLogDestination
{
    eLogDestination_DLT = 0,     ///< Log to DLT Daemon
    eLogDestination_Console = 1, ///< Log to Console
    eLogDestination_File = 2,    ///< Log to File
    eLogDestination_Slog2 = 3    ///< Log to Slogger
} eLogDestination_t;

void dk_Logger_createInstance ( const char *const pName, const char *const pDesc, const uint8_t bEnable, const eLogDestination_t dest, const uint8_t bSilent, const char *const pFile, const uint8_t bOnlyError );
void dk_Logger_registerContext ( DltContext *const pHandle, const char *const pContextId, const char *const pDescription, const DltLogLevelType logLevel, const DltTraceStatusType traceStatus );
void dk_Logger_unregisterContext ( DltContext *const pHandle );
void dk_Logger_log ( DltContext *const pHandle, const DltLogLevelType logLevel, const char *const pFileName, const char *const pDelim1,
        const uint32_t lineNo, const char *const pDelim2, const char *const pFuncName, const char *const pDelim3, const char *fmt, ... );

#define LOG_DECLARE_CONTEXT(CONTEXT) DltContext CONTEXT
#define LOG_IMPORT_CONTEXT(CONTEXT) extern DltContext CONTEXT
#define LOG_REGISTER_APP_SLOG2(NAME, DESC) dk_Logger_createInstance(NAME, DESC, TRUE, eLogDestination_Slog2, FALSE, NULL, FALSE)
#define LOG_REGISTER_CONTEXT(HNDL, TAG, DESC, LEVEL) dk_Logger_registerContext(&HNDL, TAG, DESC, LEVEL, DLT_TRACE_STATUS_OFF);
#define LOG_UNREGISTER_CONTEXT(HNDL) dk_Logger_unregisterContext(&HNDL);
#define LOGV(HNDL, FMT, ...) dk_Logger_log(HNDL, DLT_LOG_VERBOSE, __FILE__, ":", __LINE__, ":", __FUNCTION__, ": ", FMT, ##__VA_ARGS__)
#define LOGD(HNDL, FMT, ...) dk_Logger_log(HNDL, DLT_LOG_DEBUG, __FILE__, ":", __LINE__, ":", __FUNCTION__, ": ", FMT, ##__VA_ARGS__)
#define LOGI(HNDL, FMT, ...) dk_Logger_log(HNDL, DLT_LOG_INFO, __FILE__, ":", __LINE__, ":", __FUNCTION__, ": ", FMT, ##__VA_ARGS__)
#define LOGW(HNDL, FMT, ...) dk_Logger_log(HNDL, DLT_LOG_WARN, __FILE__, ":", __LINE__, ":", __FUNCTION__, ": ", FMT, ##__VA_ARGS__)
#define LOGE(HNDL, FMT, ...) dk_Logger_log(HNDL, DLT_LOG_ERROR, __FILE__, ":", __LINE__, ":", __FUNCTION__, ": ", FMT, ##__VA_ARGS__)


#endif //DK_LOGGER_H
