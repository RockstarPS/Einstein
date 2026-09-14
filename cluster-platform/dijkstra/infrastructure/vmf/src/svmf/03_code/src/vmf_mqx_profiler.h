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

  \file                 vmf_mqx_profiler.h
  \brief                header file of vmf_mqx_profiler.c

  \author               Joachim Becker
  \author               Visteon Deutschland GmbH, Infotainment Software

  *****************************************************************************/
#ifndef __VMF_MQX_PROFILER_H__
#define __VMF_MQX_PROFILER_H__

#include "vmf_ipc.h"

#define TARGET_NAME_LEN 16
#define CORE_NAME_LEN   8

#define VMF_PROFILER_TARGET_NAME      "Leopard-E"
#define VMF_PROFILER_CORE_NAME_M4     "M4"
#define VMF_PROFILER_CORE_NAME_A5     "A5"

#define BIT_SVMF        0x01        /* SVMF */
#define BIT_MEM         0x02        /* memory is shown in % of stack */
#define BIT_LOAD        0x04        /* load is shown in mips */


#if ( VS_MICRO_CORE_M4 == VS_MICRO_CORE )
#define VMF_MCC_PROFILER_USE_OSAL_TIMER
#endif


#define VMF_MQX_PROF_ERROR      (0xFFFFFFFF)

#define     VMF_PROFILER_MAX_TASK       (50)
#define     VMF_PROFILER_MAX_TASK_NUM   (VMF_PROFILER_MAX_TASK+1)
typedef struct
{
    unsigned16              mips;
    unsigned16              ticks_ps;
    unsigned16              int_rate_ms;
    unsigned32              old_idle_ticks;
    unsigned32              old_task_ticks[VMF_PROFILER_MAX_TASK_NUM];
    unsigned32              task_ticks[VMF_PROFILER_MAX_TASK_NUM];
}VMF_PROFILE_DATA;

typedef struct
{
   BOOL                     PROFILING_ACTIVE;
   unsigned32               timer_isr_vector;

   INT_ISR_FPTR             OLD_ISR;
   pointer                  OLD_ISR_DATA;
   KERNEL_DATA_STRUCT_PTR   kernel_data;
   VMF_PROFILE_DATA         profile_data;
   unsigned32               invalid_ticks;
} VMF_RTA_PROFILE_INFO_STRUCT;


#define NAME_LEN_MAX 30
typedef struct
{
    unsigned32  pid;
    _task_id    task_id;
    unsigned32  state;
    unsigned32  stack_used_kb;
    unsigned32  utime;              /* user time in ms */
    unsigned16  num_send;
    char        name[NAME_LEN_MAX+1];
}vmf_profiler_task_stat_t;

typedef struct
{
    unsigned32                  num_tasks;
    vmf_profiler_task_stat_t    tasks[VMF_PROFILER_MAX_TASK_NUM];
}vmf_profiler_stat_t;

typedef struct
{
    unsigned8   version;        /* version of load response - 0x00 for version 0*/
    char        state;          /* process status R,Z,S,X,K                     */
    unsigned16  Threads;        /* number of threads              (l,h)         */
    unsigned32  pid;            /* pid                            (ll,lh,hl,hh) */
    unsigned32  ppid;           /* parent pid                     (ll,lh,hl,hh) */
    unsigned32  VmRSS;          /* phys memory size in KByte      (ll,lh,hl,hh) */
    unsigned32  VmSize;         /* virtual memory size in KByte   (ll,lh,hl,hh) */
    unsigned32  MemTotal;       /* total memory in KByte          (ll,lh,hl,hh) */
    unsigned32  utime;          /* user time in jiffies                         */
    unsigned32  stime;          /* system time in jiffies                       */
    unsigned32  rtime;          /* running time in jiffies                      */
    char        name[NAME_LEN_MAX+1]; /* process name zero terminated          */
}vmf_sysinfo_pid_name_resp_pl_t;


#define SYSINFO_ALL_PIDS        (0xffffffff)
#define SYSINFO_UPDATE_PIDS     (0)
typedef struct
{
    unsigned32              pid;             /* pid or SYSINFO_ALL_PIDS for all pids */
}vmf_sysinfo_pid_name_req_pl_t;

#define MAX_PIDS                        VMF_PROFILER_MAX_TASK
#define VMF_SYSINFO_MAX_PIDLIST_PIDS    MAX_PIDS
typedef struct
{
    unsigned16              num;
    unsigned32              pids[VMF_SYSINFO_MAX_PIDLIST_PIDS+1];
}vmf_sysinfo_pidlist_t;

typedef struct
{
    unsigned32  pid;
    unsigned32  u_time_jiffies;       /* value of previous user time snapshot */
    unsigned32  s_time_jiffies;       /* value of previous system time snapshot */
}proc_sys_info_t;

typedef struct
{
    unsigned16      int_time;   /* profiler integration time (l,h) in ms */
}vmf_sysinfo_start_req_pl_t;



/*****************VMF_TRACE_CTRL_PROFILER_LOAD_RESP **************/
typedef struct
{
    unsigned32  pid;          /* process id - (ll,lh,hl,hh  */
    unsigned8   cpu_num;      /* CPU number starting with 0 */
    unsigned8   s_time;       /* system time    255 = 100%  */
    unsigned8   u_time;       /* user time      255 = 100%  */
    unsigned8   io_time;      /* io-wait time   255 = 100%  */
    unsigned8   irq_time;     /* irq time       255 = 100%  */
    unsigned8   sirq_time;    /* soft irq time  255 = 100%  */
    unsigned8   idle_time;    /* idle time */

    unsigned8   plh_0;        /* place-holder */
}load_t;

typedef struct
{
    unsigned32  pid;          /* process id - (ll,lh,hl,hh  */
    unsigned8   cpu_num;      /* CPU number starting with 0 */
    unsigned8   s_time;       /* system time    255 = 100%  */
    unsigned8   u_time;       /* user time      255 = 100%  */
    unsigned8   io_time;      /* io-wait time   255 = 100%  */
    unsigned8   irq_time;     /* irq time       255 = 100%  */
    unsigned8   sirq_time;    /* soft irq time  255 = 100%  */
    unsigned8   mips_l;       /* mips_low                   */
    unsigned8   mips_h;       /* mips_high                  */
}load_v2_t;

/* load response version 0 */
#define VERSION_SVMF    0x8
#define SYSINFO_LOAD_RESP_VERSION   0
#define SYSINFO_LOAD_RESP_VERSION_1 1
#define SYSINFO_LOAD_RESP_VERSION_2 2
#define SYSINFO_LOAD_RESP_VERSION_SVMF (SYSINFO_LOAD_RESP_VERSION_1 | (VERSION_SVMF <<4))
/* load response version byte */
/* higher nibble is used as flag bits */
/* 0B 10000 0000        is SVMF */

#define VMF_TRACE_LOAD_MAX_LOADS  MAX_PIDS

typedef struct
{
    unsigned8   version;      /* version of load response - 0x00 for version 0 */
    unsigned8   num_loads;    /* number of loads in this payload */
    unsigned8   cpu_frq_l;    /* low part of CPU_FRQ in MHz */
    unsigned8   cpu_frq_h;    /* high part of CPU frq in MHz*/
    load_t      load[VMF_TRACE_LOAD_MAX_LOADS];
}vmf_sysinfo_load_resp_pl_t;

typedef struct
{
    unsigned8   version;      /* version of load response - 0x00 for version 0 */
    unsigned8   num_loads;    /* number of loads in this payload */
    unsigned8   cpu_frq_l;    /* low part of CPU_FRQ in MHz */
    unsigned8   cpu_frq_h;    /* high part of CPU frq in MHz*/
    load_v2_t   load[VMF_TRACE_LOAD_MAX_LOADS];
}vmf_sysinfo_load_resp_v2_pl_t;




enum PROC_STATES
{
    ST_STD      = ' ',      /* normal task */
    ST_DEAD     = 'X',      /* dead task   */
    ST_KERNEL   = 'K'       /* kernel task */
};

#define VMF_IDLE_TASK   (1)
#define VMF_PROFILER_A5_CLK (417)       /* MIPS */
#define VMF_PROFILER_M4_CLK (166)       /* MIPS */

#ifndef MQX_STACK_MONITOR_VALUE
#define MQX_STACK_MONITOR_VALUE 0x7374616B
#endif

/*********************************************************************/

/* new style profiler messages */
#define VMF_PROFILER_NS_VERSION     0

#define SYSINFO_ALL_TARGETS         0xffff

/* VMF_SYSINFO_CTRL_TARGET_INFO_REQ */
typedef struct
{
    unsigned8   version;            /* version starting with 0 */
    unsigned8   fill;
    unsigned16  target_id;          /* target id or 0xffff for all targets */
} vmf_sysinfo_ctrl_target_info_req_pl_t;


/* VMF_SYSINFO_DATA_TARGET_INFO_RESP */
typedef struct
{
    unsigned8   version;                        /* version starting with 0 */
    unsigned8   fill;
    unsigned16  target_id;                      /* target id or 0xffff for all targets */
    char        target_name[TARGET_NAME_LEN];   /* target name – zero terminated if it will fit */
    char        core_name[CORE_NAME_LEN  ];     /* core name   – zero terminated if it will fit */

    unsigned16  vmf_version;                    /* VMF version  0x0201 fpr version 2.01 */
    unsigned16  bit_mask;                       /* pid or SYSINFO_ALL_PIDS for all pids */
}vmf_sysinfo_data_target_info_resp_pl_t;


/* VMF_SYSINFO_CTRL_TARGET_ID_SET */
typedef struct
{
    unsigned8   version;                        /* version starting with 0 */
    unsigned8   fill;
    unsigned16  target_id;                      /* target id or 0xffff for all targets */    char        target_name[TARGET_NAME_LEN];    /* target name – zero terminated if it will fit  */
    char        core_name[CORE_NAME_LEN  ];     /* core name   – zero terminated if it will fit  */
} vmf_sysinfo_ctrl_target_id_set_t;


/* VMF_SYSINFO_CTRL_TARGET_PID_NAME_REQ */
typedef struct
{
    unsigned8  version;                         /* version - 0x00 for version 0*/
    unsigned8  fill;
    unsigned16 target_id;
    unsigned32 pid;                             /* pid or SYSINFO_ALL_PIDS for all pids */
}vmf_sysinfo_ctrl_target_pid_name_req_pl_t;


/* VMF_SYSINFO_CTRL_TARGET_PROFILER _START */
typedef struct
{
    unsigned8  version;                         /* version - 0x00 for version 0*/
    unsigned8  fill;
    unsigned16 target_id;

    unsigned16 int_time;                        /* profiler integration time (l,h) in ms */
}vmf_sysinfo_ctrl_target_profiler_start_pl_t;



/* VMF_SYSINFO_CTRL_TARGET_PROFILER_LR_START */
typedef struct
{
    unsigned8   version;        /* version - 0x00 for version 0*/
    unsigned8   fill;
    unsigned16  target_id;
    unsigned16  num_pids;               /* number of pids              (l,h)    */
    unsigned32  pid[VMF_TRACE_LOAD_MAX_LOADS];   /* pid or SYSINFO_ALL_PIDS for all pids */
}vmf_sysinfo_ctrl_target_load_req_pl_t;



/* VMF_SYSINFO_CTRL_TARGET_PROFILER _STOP */
typedef struct
{
    unsigned8  version;        /* version - 0x00 for version 0*/
    unsigned8  fill;
    unsigned16 target_id;
}vmf_sysinfo_ctrl_target_profiler_stop_pl_t;



/* VMF_SYSINFO_DATA_TARGET_PROFILER_PID_NAME_RESP */
typedef struct
{
    unsigned8   version;        /* version - 0x00 for version 0*/

    unsigned8   fill;
    unsigned16  target_id;

    unsigned8   stack;          /* stack usage in %                             */
    char        state;          /* process status R,Z,S,X,K                     */
    unsigned16  Threads;        /* number of threads              (l,h)         */
    unsigned32  pid;            /* pid                            (ll,lh,hl,hh) */
    unsigned32  ppid;           /* parent pid                     (ll,lh,hl,hh) */
    unsigned32  VmRSS;          /* phys memory size in KByte      (ll,lh,hl,hh) */
    unsigned32  VmSize;         /* virtual memory size in KByte   (ll,lh,hl,hh) */
    unsigned32  MemTotal;       /* total memory in KByte          (ll,lh,hl,hh) */
    unsigned32  utime;          /* user time in jiffies                         */
    unsigned32  stime;          /* system time in jiffies                       */
    unsigned32  rtime;          /* running time in jiffies                      */
    char        name[NAME_LEN_MAX+1]; /* process name zero terminated           */
}vmf_sysinfo_data_target_pid_name_resp_pl_t;


/* VMF_SYSINFO_DATA_TARGET_PROFILER_LOAD_RESP */
typedef struct
{
    unsigned8   version;      /* version of load response - 0x00 for version 0 */
    unsigned8   fill;
    unsigned16  target_id;
    unsigned8   dummy;      /* placeholder */

    unsigned8   num_loads;    /* number of loads in this payload */
    unsigned8   cpu_frq_l;    /* low part of CPU_FRQ in MHz */
    unsigned8   cpu_frq_h;    /* high part of CPU frq in MHz*/
    load_t      load[VMF_TRACE_LOAD_MAX_LOADS];
}vmf_sysinfo_data_target_load_resp_pl_t;






/*********************************************************************/


vmf_ret_t   vmf_sysinfo_send_process_name(vmf_cid_t cid, pid_t pid);
vmf_ret_t   vmf_sysinfo_send_all_process_names(vmf_cid_t cid);
vmf_ret_t   vmf_sysinfo_send_updated_process_names(vmf_client_id_t cid);
vmf_ret_t   vmf_sysinfo_set_int_time(unsigned16 time);
vmf_ret_t   vmf_sysinfo_get_requested_pids (unsigned8 *payload);
unsigned32  vmf_profiler_install(unsigned16 ms_time);
void        vmf_load_timer_task(void *param);

#endif


