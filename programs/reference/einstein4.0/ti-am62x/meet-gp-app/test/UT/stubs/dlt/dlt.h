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
    int8_t verbose_mode;                          /**< verbose mode: 1 enabled, 0 disabled */
} DltContextData;

#define DLT_DECLARE_CONTEXT(x) DltContext x;
#define DLT_REGISTER_APP(APPID,DESCRIPTION)
#define DLT_REGISTER_CONTEXT(CONTEXT,CONTEXTID,DESCRIPTION)
#define DLT_REGISTER_INJECTION_CALLBACK(CONTEXT, SERVICEID, CALLBACK)

extern int dlt_user_log_file_infoAbout(DltContext *fileContext, const char *filename);
extern int dlt_user_log_file_complete(DltContext *fileContext, const char *filename, int deleteFlag, int timeout);
extern void dlt_set_id(char *id, const char *text);

#endif /* DLT_H */
