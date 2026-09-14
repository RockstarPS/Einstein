#ifndef DK_LOGGER_H
#define DK_LOGGER_H

#include <stdint.h>

typedef enum {
    DLT_LOG_DEFAULT = -1,
    DLT_LOG_OFF = 0x00,
    DLT_LOG_FATAL = 0x01,
    DLT_LOG_ERROR = 0x02,
    DLT_LOG_WARN = 0x03,
    DLT_LOG_INFO = 0x04,
    DLT_LOG_DEBUG = 0x05,
    DLT_LOG_VERBOSE = 0x06
} DltLogLevelType;

typedef struct {
    char contextID[4];
    int32_t log_level_pos;
    int32_t log_level_user;
} DltContext;

typedef enum {
    DLT_TRACE_STATUS_DEFAULT = -1,
    DLT_TRACE_STATUS_OFF = 0x00,
    DLT_TRACE_STATUS_ON = 0x01
} DltTraceStatusType;

#define LOG_DECLARE_CONTEXT(CONTEXT) DltContext CONTEXT

void dk_Logger_registerContext(DltContext *pHandle,
                               const char *pContextId,
                               const char *pDescription,
                               DltLogLevelType logLevel,
                               DltTraceStatusType traceStatus);
#define LOG_REGISTER_CONTEXT(HNDL, TAG, DESC, LEVEL)                           \
    dk_Logger_registerContext(&HNDL, TAG, DESC, LEVEL, DLT_TRACE_STATUS_OFF);

void dk_Logger_unregisterContext(DltContext *pHandle);
#define LOG_UNREGISTER_CONTEXT(HNDL) dk_Logger_unregisterContext(&HNDL);

void dk_Logger_log(DltContext *const pHandle,
                   const DltLogLevelType logLevel,
                   const char *const pFileName,
                   const char *const pDelim1,
                   const uint32_t lineNo,
                   const char *const pDelim2,
                   const char *const pFuncName,
                   const char *const pDelim3,
                   const char *fmt,
                   ...);

#define LOGE(HNDL, FMT, ...)                                                   \
    dk_Logger_log(HNDL,                                                        \
                  DLT_LOG_ERROR,                                               \
                  __FILE__,                                                    \
                  ":",                                                         \
                  __LINE__,                                                    \
                  ":",                                                         \
                  __FUNCTION__,                                                \
                  ": ",                                                        \
                  FMT,                                                         \
                  ##__VA_ARGS__)

#endif // DK_LOGGER_H
