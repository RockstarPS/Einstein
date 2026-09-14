#ifndef DLT_H
#define DLT_H

#include <stdint.h>
#define DLT_ID_SIZE 4

typedef struct
{
    char contextID[DLT_ID_SIZE];                  /**< context id */
    int32_t log_level_pos;                        /**< offset in user-application context field */
    int8_t *log_level_ptr;                        /**< pointer to the log level */
    int8_t *trace_status_ptr;                     /**< pointer to the trace status */
    uint8_t mcnt;                                 /**< message counter */
} DltContext;

typedef enum
{
    DLT_LOG_DEFAULT = -1,               /**< Default log level */
    DLT_LOG_OFF = 0x00,                 /**< Log level off */
    DLT_LOG_FATAL = 0x01,               /**< fatal system error */
    DLT_LOG_ERROR = 0x02,               /**< error with impact to correct functionality */
    DLT_LOG_WARN = 0x03,                /**< warning, correct behaviour could not be ensured */
    DLT_LOG_INFO = 0x04,                /**< informational */
    DLT_LOG_DEBUG = 0x05,               /**< debug  */
    DLT_LOG_VERBOSE = 0x06,             /**< highest grade of information */
    DLT_LOG_MAX                         /**< maximum value, used for range check */
} DltLogLevelType;

typedef enum
{
    DLT_TRACE_STATUS_DEFAULT = -1,         /**< Default trace status */
    DLT_TRACE_STATUS_OFF = 0x00,           /**< Trace status: Off */
    DLT_TRACE_STATUS_ON = 0x01,            /**< Trace status: On */
    DLT_TRACE_STATUS_MAX                   /**< maximum value, used for range check */
} DltTraceStatusType;

typedef enum
{
	DLT_AUTO_TIMESTAMP = 0,
	DLT_USER_TIMESTAMP
} DltTimestampType;

typedef struct
{
    DltContext *handle;                           /**< pointer to DltContext */
    unsigned char *buffer;                        /**< buffer for building log message*/
    int32_t size;                                 /**< payload size */
    int32_t log_level;                            /**< log level */
    int32_t trace_status;                         /**< trace status */
    int32_t args_num;                             /**< number of arguments for extended header*/
    char *context_description;                    /**< description of context */
    DltTimestampType use_timestamp;               /**< whether to use user-supplied timestamps */
    uint32_t user_timestamp;                      /**< user-supplied timestamp to use */
} DltContextData;

typedef enum
{
    DLT_RETURN_LOGGING_DISABLED = -7,
    DLT_RETURN_USER_BUFFER_FULL = -6,
    DLT_RETURN_WRONG_PARAMETER = -5,
    DLT_RETURN_BUFFER_FULL = -4,
    DLT_RETURN_PIPE_FULL = -3,
    DLT_RETURN_PIPE_ERROR = -2,
    DLT_RETURN_ERROR = -1,
    DLT_RETURN_OK = 0,
    DLT_RETURN_TRUE = 1
} DltReturnValue;

DltReturnValue dlt_register_app(const char *apid, const char *description);

DltReturnValue dlt_register_context(DltContext *handle, const char *contextid, const char *description);

DltReturnValue dlt_unregister_context(DltContext *handle);

DltReturnValue dlt_register_context_ll_ts(DltContext *handle,
                                          const char *contextid,
                                          const char *description,
                                          int loglevel,
                                          int tracestatus);

DltReturnValue dlt_user_is_logLevel_enabled(DltContext *handle, DltLogLevelType loglevel);

DltReturnValue dlt_user_log_write_start(DltContext *handle, DltContextData *log, DltLogLevelType loglevel);

DltReturnValue dlt_user_log_write_finish(DltContextData *log);

DltReturnValue dlt_user_log_write_int8(DltContextData *log, int8_t data);

DltReturnValue dlt_user_log_write_uint8(DltContextData *log, uint8_t data);

DltReturnValue dlt_user_log_write_int16(DltContextData *log, int16_t data);

DltReturnValue dlt_user_log_write_uint16(DltContextData *log, uint16_t data);

DltReturnValue dlt_user_log_write_int32(DltContextData *log, int32_t data);

DltReturnValue dlt_user_log_write_uint32(DltContextData *log, uint32_t data);

DltReturnValue dlt_user_log_write_bool(DltContextData *log, uint8_t data);

DltReturnValue dlt_user_log_write_int64(DltContextData *log, int64_t data);

DltReturnValue dlt_user_log_write_uint64(DltContextData *log, uint64_t data);

DltReturnValue dlt_user_log_write_raw(DltContextData *log, void *data, uint16_t length);

DltReturnValue dlt_user_log_write_string(DltContextData *log, const char *text);

#endif /* DLT_H */
