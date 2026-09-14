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

/*************************************************************************//**

  \file                 nw_vmf_nw_controller.h
  \brief                header file of vmf controller

  \author               Joachim Becker - 15 August 2012
  \author               Visteon Deutschland GmbH, Infotainment Software

  *****************************************************************************/
#ifndef _NW_VMF_CTRL_H
#define _NW_VMF_CTRL_H

#include "nw_vmf_timer.h"

#define VMF_TRACE_TRID_NAME     "vmf"                   /* trid name */
#define VMF_TRACE_CONTROLLER    "vmf-ctrl"              /* trace name (tab in tracer) */
#define VMF_CTRL_CON_NAME       "vmf_ctrl"              /* name for vmf connect */
#define VMF_CTRL_STACK_SIZE     (2000 + VMF_NW_STACK_SIZE)
#define WAIT_SOME_TIME          50                      /* connection dely before re-try */
#define FOREVER                 true

#define VMF_TRACE_CTRL_SCOPE    (char *)__PRETTY_FUNCTION__

/* debug macros */
#define VMF_CTRL_DEBUG_ERROR(trid,scope, ...)           (void)VMF_TRACE_PRINTF(trid, VMF_TRACE_SEVERITY_ERROR, scope, VMF_TRACE_CTRL_SCOPE, __VA_ARGS__);
#define VMF_CTRL_DEBUG_INFO(trid,scope, ...)            (void)VMF_TRACE_PRINTF(trid, VMF_TRACE_SEVERITY_INFO_10, scope, VMF_TRACE_CTRL_SCOPE,  __VA_ARGS__);
#define VMF_CTRL_DEBUG_INFO2(trid,scope, ...)           (void)VMF_TRACE_PRINTF(trid, VMF_TRACE_SEVERITY_INFO_20, scope, VMF_TRACE_CTRL_SCOPE,  __VA_ARGS__);
#define VMF_CTRL_DEBUG_DEBUG(trid,scope,severity, ...)  (void)VMF_TRACE_PRINTF(trid, severity, scope, VMF_TRACE_CTRL_SCOPE,  __VA_ARGS__);
#define VMF_CTRL_DEBUG_WARNING(trid,scope, ...)         (void)VMF_TRACE_PRINTF(trid, VMF_TRACE_SEVERITY_WARNING, scope, VMF_TRACE_CTRL_SCOPE, __VA_ARGS__);
#define VMF_CTRL_DEBUG_HEX(trid,scope,len,data)         (void)VMF_TRACE_HEX(trid,VMF_TRACE_SEVERITY_INFO_20,scope,VMF_TRACE_CTRL_SCOPE,len,data);

#define MAX_SOFT_TIMER 100                    /* maximum is 255 timer !*/
#define VMF_CTRL_SOFT_TIMER_HEADER_LEN (sizeof(vmf_ctrl_soft_timer_t) - MAX_VMF_TIMER_PL)





/* VMF_CTRL_REQUEST_VMF_INFO_RESP */
/* ipc definitions */
#define VMF_CTRL_IPC_NOT_SET    0
#define VMF_CTRL_IPC_MQ         1
#define VMF_CTRL_IPC_DSOCK      2
#define VMF_CTRL_IPC_UDP        3
#define VMF_CTRL_IPC_SHM        4

/* os definitions */
#define VMF_CTRL_OS_NOT_SET     0
#define VMF_CTRL_OS_QNX         1
#define VMF_CTRL_OS_LINUX       2
#define VMF_CTRL_OS_CYGWIN      3
#define VMF_CTRL_OS_WINDOWS     4
#define VMF_CTRL_OS_INTEGRITY   5

/* CPU definitions */
#define VMF_CTRL_CPU_NOT_SET    0
#define VMF_CTRL_CPU_ARM        1
#define VMF_CTRL_CPU_X86        2
#define VMF_CTRL_CPU_ARM_V4     3
#define VMF_CTRL_CPU_ARM_V5     4

typedef struct
{
    unsigned8       pl_major_version;   /* vmf major version                     */
    unsigned8       pl_minor_version;   /* vmf minor version                     */
    unsigned8       pl_ipc;             /* used IPC - see definitions            */
    unsigned8       pl_os;              /* operating system - see definitions    */
    unsigned8       pl_cpu;             /* CPU - values see definitions          */
    unsigned8       pl_len_max_l;       /* low  of max vmf-payload len           */
    unsigned8       pl_len_max_h;       /* high of max vmf-payload len           */
    unsigned8       pl_spy_queue;       /* 0 if spy queue disabled, 1 if enabled */
#if 0
    unsigned8       pl_trace_queue;     /* o if trace queue disabled else 0x01   */
#endif
}vmf_ctrl_vmf_info_t;

#define VMF_CTRL_PERS_VERSION 1
typedef struct
{
    unsigned8       pers_version;       /* version of persistant data      */
    unsigned8       vmf_start_q_ena;    /* 0 if spy start queue is enabled */
}
vmf_ctrl_pers_t;



enum VMF_MON_STATUS
{
    VMF_MON_STATUS_UNKNOWN,
    VMF_MON_STATUS_GREEN,
    VMF_MON_STATUS_YELLOW,
    VMF_MON_STATUS_RED
};

#define VMF_MON_ITEM_NAME_LEN   30
#define VMF_MON_TEXT_LEN        100
#define VMF_MON_VERSION         (unsigned8)1

typedef struct
{
    unsigned8   version;                            /* version of load response - 0x00 for version 0 */
    unsigned8   item_name_len;                      /* length of item name INCLUDING TERMINATING ZERO */
    char        item_name[VMF_MON_ITEM_NAME_LEN];   /* monitor item name – zero terminated */
}vmf_ctrl_monitoring_req_t;

typedef struct
{
    unsigned8   version;                            /* version of load response - 0x00 for version 0 */
    unsigned8   item_name_len;                      /* length of item name INCLUDING TERMINATING ZERO */
    char        item_name[VMF_MON_ITEM_NAME_LEN];   /* monitor item name – zero terminated */
    unsigned8   status;                             /* monitor status */
    unsigned8   status_text_len;                    /* length of status text INCLUDING TERMINATING ZERO */
    char        status_text[VMF_MON_TEXT_LEN];      /* status text – zero terminated  */
}vmf_ctrl_monitoring_resp_t;


/* prototypes */
vmf_ret_t nw_vmf_controller_create_thread(void);
bool      nw_vmf_controller_is_spy_queue_enabled(void);
vmf_ret_t nw_vmf_ctrl_read_pers_data(void);
vmf_ret_t nw_vmf_ctrl_create_vmf_info_response(vmf_ctrl_vmf_info_t *pvmf_info);
void      nw_vmf_controller_tx_timesync(void);
void      nw_vmf_controller_start_timesync(void);

#endif

