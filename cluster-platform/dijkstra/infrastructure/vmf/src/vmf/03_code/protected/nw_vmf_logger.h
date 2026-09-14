/*****************************************************************************/
/* Copyright Statement                                                       */
/* CONFIDENTIAL - VISTEON CORPORATION                                        */
/* This is an unpublished work, which contains trade secrets, created in     */
/* 2008. Visteon Corporation owns all rights to this work and intends        */
/* to maintain it in confidence to preserve its trade secret status. Visteon */
/* Corporation reserves the right, under the copyright laws of the United    */
/* States or those of any other country that may have jurisdiction, to       */
/* protect this work as an unpublished copyright work in the event of an     */
/* inadvertent or deliberate unauthorized publication. Visteon Corporation   */
/* also reserves its rights under the copyright laws to protect this work    */
/* as a published work, when appropriate. Those having access to this work   */
/* may not copy it, use it or disclose the information contained in it       */
/* without the written authorization of Visteon Corporation.                 */
/*****************************************************************************/

/***************************************************************************

  Module:               vmf_logger.h
  Description:          header file of vmf logger

  Project Scope:        VMF

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   gcc
  Target Hardware:      Any

  *****************************************************************************/

#ifndef VMF_LOGGER_H__
#define VMF_LOGGER_H__

/*
#define     VMF_LOGGER_STANDALONE
*/
/* all strings lower case !! */
#define VMF_LOGGER_STACK_SIZE       VMF_NW_STACK_SIZE
#define VMF_LOG_FILE_EXTENSION      ".log"
#define VMF_LOG_INI_FILE            "vmf_log.ini"
#ifdef VMF_LOG_USE_SHORT_FILENAMES
#define VMF_LOG_INDEX_INI           "vmf_logx.ini"
#else
#define VMF_LOG_INDEX_INI           "vmf_log_ix.ini"
#endif
#define VMF_INI_SEVERITY_SEC        "trace_severities"
#define VMF_INI_VMF_MSG_SEC         "vmf_messages"
#define VMF_INI_VMF_ROUTING_SEC     "routing"
#define VMF_INI_DAB_KEY             "dab"
#define VMF_INI_DAB_SPI_KEY         "dab_spi"
#define VMF_INI_PRINTF_M4_KEY       "printf_M4"
#define VMF_INI_PRINTF_A5_KEY       "printf_A5"
#define VMF_INI_FPRINTF_A5_KEY      "fprintf_A5"
#define VMF_INI_FORWARD_GROUPS_KEY  "forward_groups"
#define VMF_LOG_START_SECTION       "[vmf_logging]"
#define VMF_LOG_START_IX_KEY        "start_index"
#define VMF_TRACE_FILE_NAME_PREFIX  "vmf_"
#define VMF_HEADER_TEXT             "vmf"
#define MAX_INI_VMF_FILTER_STRING   "message"

#define VMF_INI_LOGGING_SEC         "logging"
#define VMF_INI_LOG_PATH_KEY        "path"
#define VMF_INI_LOG_ENABLE_KEY      "enabled"
#define VMF_INI_LOG_FILE_LEN_KEY    "max_file_len"
#define VMF_INI_LOG_FILE_TIME_KEY   "max_file_time"


#define MAX_INI_NUM_PROC_SEVERITIES     100          /* number of process severities in ini file */
#define MAX_INI_VMF_MAX_MSG_NUM         25           /* number of filter messages */
#define MAX_INI_VMF_MAX_PL_LEN          10           /* number of filter payload bytes */
#define MAX_INI_VMF_MAX_FORWARD_GROUPS  50           /* max number of forward groups */

#define MAX_VMF_TRACE_PL_LEN            (250)
#define MAX_VMF_TRACE_TASK_NAME_LEN     (50)
#define VMF_LOGG_MAX_DEBUG_FILE_LEN_KB  (1024)      /* max file-len in KByte */
#define VMF_LOGG_MAX_DEBUG_FILE_TIME_S  (3600)      /* max file time in s (3600=1h) */
#define VMF_LOGG_MAX_PATH_LEN           (255)

typedef struct
{
    char        vmf[3];    /* 'vmf'  */
    unsigned8   version_h;
    unsigned8   version_l;
    unsigned8   year;     /* 0 == year 2000 */
    unsigned8   month;    /* Range 1..12 */
    unsigned8   days;     /* Range 1..31 */
    unsigned8   hours;    /* Range 0..23 */
    unsigned8   minutes;  /* Range 0..59 */
    unsigned8   seconds;  /* Range 0..59 */
    unsigned8   not_used;
}vmf_usb_trace_header_t;


typedef struct
{
    bool        enabled;
    int         max_file_len_kb;                /* max file length in kbyte*/
    int         max_file_time_s;                /* maximum file time in seconds */
    char        path[VMF_LOGG_MAX_PATH_LEN];    /* path for log files and ini file */
}vmf_logger_info_t;



vmf_ret_t vmf_logger_create_thread(void);


#endif

