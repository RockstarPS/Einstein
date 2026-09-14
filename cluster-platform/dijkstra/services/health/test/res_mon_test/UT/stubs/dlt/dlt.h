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

#define DLT_DECLARE_CONTEXT(x) DltContext x;
#define DLT_REGISTER_APP(APPID,DESCRIPTION)
#define DLT_REGISTER_CONTEXT(CONTEXT,CONTEXTID,DESCRIPTION)
#define DLT_REGISTER_INJECTION_CALLBACK(CONTEXT, SERVICEID, CALLBACK)

extern int dlt_user_log_file_infoAbout(DltContext *fileContext, const char *filename);
extern int dlt_user_log_file_complete(DltContext *fileContext, const char *filename, int deleteFlag, int timeout);
extern void dlt_set_id(char *id, const char *text);

#endif /* DLT_H */
