

#ifndef _VMF_SYSINFO_H
#define _VMF_SYSINFO_H

#ifndef VMF_TRACE_SYSINFO_CTRL
    #define VMF_TRACE_SYSINFO_CTRL    (VMF_TRACE_CTRL + 1)
    #define VMF_TRACE_SYSINFO_DATA    (VMF_TRACE_CTRL + 2)
    #define VMF_TRACE_IPC_DATA        (VMF_TRACE_CTRL + 3)

    #define VMF_SYSINFO_START                        (0)
    #define VMF_SYSINFO_CTRL_PROFILER_START          (VMF_SYSINFO_START +0)     /* start profiler thread */
    #define VMF_SYSINFO_CTRL_PROFILER_STOP           (VMF_SYSINFO_START +1)     /* stop profiler thread  */
    #define VMF_SYSINFO_CTRL_PROFILER_START_LOAD_REQ (VMF_SYSINFO_START +2)     /* start transfering load for given pid */
    #define VMF_SYSINFO_CTRL_PROFILER_STOP_LOAD_REQ  (VMF_SYSINFO_START +3)     /* stop transfering load for given pid */
    #define VMF_SYSINFO_DATA_PROFILER_LOAD_RESP      (VMF_SYSINFO_START +4)     /* transfer load */
    #define VMF_SYSINFO_CTRL_PROFILER_PID_NAME_REQ   (VMF_SYSINFO_START +5)     /* request a name for a given pid*/
    #define VMF_SYSINFO_DATA_PROFILER_PID_NAME_RESP  (VMF_SYSINFO_START +6)     /* response with a name for a gíven pid  */
#endif

#ifdef __QNX__
#define IS_SHARED(f)            (((f) & MAP_TYPE) == MAP_SHARED)
#define IS_ELF_CODE(f)          (((f) & (MAP_ELF | PROT_EXEC | PROT_WRITE | PROT_READ)) == (MAP_ELF | PROT_EXEC | PROT_READ))
#define IS_ELF_DATA(f)          (((f) & (MAP_ELF | PROT_WRITE)) == (MAP_ELF | PROT_WRITE))
#define IS_ELF_SHARED_DATA(f)   ((((f) & (MAP_SYSRAM|MAP_ANON)) == MAP_SYSRAM) && IS_ELF_DATA((f)))
#define IS_STACK(f)             (((f) & MAP_STACK) == MAP_STACK)
#define IS_STACK_ALLOCATED(f)   (((f) & (MAP_STACK | PG_HWMAPPED)) == (MAP_STACK | PG_HWMAPPED))
//#define IS_GENERIC_HEAP(f)      ((((f) & MAP_PRIVATEANON) == MAP_PRIVATEANON) || \
//                                (((f) & (MAP_PRIVATE | MAP_ANON)) == (MAP_PRIVATE | MAP_ANON))) 
#define IS_GENERIC_HEAP(f)      (((f) & (MAP_PRIVATE | MAP_ANON)) == (MAP_PRIVATE | MAP_ANON)) 
#define IS_FROM_IFS(f)          ((!((f) & MAP_SYSRAM)) && ((f) & PG_HWMAPPED) && ((f) & MAP_PHYS))
//IFS files can't consume ram, private files need sys ram to consume ram
#define IS_RAM_CONSUMING(f)     (!IS_FROM_IFS((f)) && (IS_SHARED((f)) || ((f) & MAP_SYSRAM)))
#endif


enum mem_types {
    TYPE_UNKNOWN = 0,
    TYPE_CODE,
    TYPE_DATA,
    TYPE_HEAP,
    TYPE_STACK,
    TYPE_FILE,
    TYPE_ELF_SHARED_DATA,
    TYPE_MAX,
};


#pragma pack(push,1)


#define VMF_TRACE_LOAD_MAX_LOADS  40


typedef struct
{
    unsigned32  pid;
    unsigned32  u_time_jiffies;       /* value of previous user time snapshot */
    unsigned32  s_time_jiffies;       /* value of previous system time snapshot */
}proc_sys_info_t;


/*************** VMF_SYSINFO_CTRL_PROFILER_START ***************/ 
typedef struct 
{
    unsigned16      int_time;   /* profiler integration time (l,h) in ms */
}vmf_sysinfo_start_req_pl_t;
/*****************************************************************/


/************** VMF_TRACE_CTRL_PROFILER_START_LOAD_REQ *****************/ 
typedef struct
{
    unsigned16  pid_count;
    unsigned32  pid[VMF_TRACE_LOAD_MAX_LOADS];          /* process id - (ll,lh,hl,hh)  */
}vmf_sysinfo_load_req_pl_t;
/*****************************************************************/

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



/* load response version 0 */
#define SYSINFO_LOAD_RESP_VERSION   0
#define SYSINFO_LOAD_RESP_VERSION_1 1
typedef struct 
{
    unsigned8   version;      /* version of load response - 0x00 for version 0 */ 
    unsigned8   num_loads;    /* number of loads in this payload */
    unsigned8   cpu_frq_l;    /* low part of CPU_FRQ in MHz */ 
    unsigned8   cpu_frq_h;    /* high part of CPU frq in MHz*/ 
    load_t      load[VMF_TRACE_LOAD_MAX_LOADS];
}vmf_sysinfo_load_resp_pl_t;




/************** VMF_SYSINFO_CTRL_PROFILER_PID_NAME_REQ **************/ 
#define SYSINFO_ALL_PIDS        (0xffffffff)
#define SYSINFO_UPDATE_PIDS     (0)
typedef struct 
{
    unsigned32  pid;             /* pid or SYSINFO_ALL_PIDS for all pids */
}vmf_sysinfo_pid_name_req_pl_t;

/************** VMF_SYSINFO_DATA_PROFILER_PID_NAME_RESP **************/ 
/* pid name response version 0 */
#define SYSINFO_PID_NAME_RESP_VERSION   0
#define STRING_LENGTH 80
#define KERNEL_THREAD_STATE 'K'
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
    char        name[STRING_LENGTH+1]; /* process name zero terminated          */   
}vmf_sysinfo_pid_name_resp_pl_t;


#define VMF_SYSINFO_PROC_STAT_ALL_DATA
/************** vmf_sysinfo_proc_stat_t **************/ 
/* content of /proc/[pid]/stat file */
typedef struct 
{
    long long pid;
    long long ppid;
    long long pgid;
    long long Threads;
    long long sid;
    long long tty_nr;
    long long tty_pgrp;
    long long flags;
    long long min_flt;
    long long cmin_flt;
    long long maj_flt;
    long long cmaj_flt;
    long long utime;
    long long stimev;
    long long cutime;
    long long cstime;
    long long priority;
    long long nicev;
    long long it_real_value;
    long long start_time;
    long      running_time;         /* running time in jiffies or ms */
    long long VmSize;
    long long VmRSS;
    long long rsslim;
    long long start_code;
    long long end_code;
#ifdef VMF_SYSINFO_PROC_STAT_ALL_DATA
    long long start_stack;
    long long esp;
    long long eip;
    long long pending;
    long long blocked;
    long long sigign;
    long long sigcatch;
    long long wchan;
    long long zero1;
    long long zero2;
    long long exit_signal;
    long long cpu;
    long long rt_priority;
    long long policy;
#endif
    char state;
    char name[PATH_MAX];
}vmf_sysinfo_proc_stat_t;




/*****************************************************************/
#define VMF_SYSINFO_MAX_PIDLIST_PIDS    400
typedef struct 
{
    int     num;
    pid_t   list[VMF_SYSINFO_MAX_PIDLIST_PIDS+1];
}vmf_sysinfo_pidlist_t;




/*****************************************************************/


/*****************************************************************/


#pragma pack(pop)


vmf_ret_t nw_vmf_create_sysinfo_thread  (void);


#endif
