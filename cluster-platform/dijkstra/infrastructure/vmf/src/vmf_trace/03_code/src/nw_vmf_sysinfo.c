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
/*                                                                            *
*******************************************************************************
*  PROJECT NAME :  VMF_TRACE                                                  *
*******************************************************************************
*  MODULE NAME  :  vmf_trace.c                                                *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   10 January 2011                                              *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  VMF_TRACE                                                                  *
******************************************************************************/

/***************************************************************************

  Module:               nw_vmf_sysinfo.c
  Description:          Main functions for the vmf SYSINFO

  Project Scope:

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   gcc
  Target Hardware:      Any

  *****************************************************************************/
#define _VMF_SYSINFO_C

#include "nw_os_config.h"

//#define FULL_DEBUG

#include "nw_vmf_cfg.h"           /* vmf cfg file */
#include "nw_vmf.h"
#include "nw_vmf_trace_server.h"
#include "nw_vmf_trace.h"
#include "nw_vmf_sysinfo.h"

#include "limits.h"


#ifndef DISABLE_SYSINFO
#if defined (__LINUX__) || defined (__ANDROID__)

/* MAKROS */
#define IDLE_LOAD_FILE              "/proc/stat"
#define CPU_FRQ_FILE                "/sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq"
#define SHOW_100PERCENT_PER_CORE    /* if define the load per CPU core is calculated from 0..100% */
                                    /* if not the total load is 100% ( in a dual core system a core can then only rach 50%)*/

/* local data */
static FILE                         *idle_load_file=NULL;                   /* file handle of idle load file*/
static long tickspersec;
static int jiffies_allcores = 0;                                                      /* diff jiffies of all cpus */
static unsigned32       last_load_calc_time_ms=0;

/* local function declaration for LINUX version */
static vmf_ret_t  vmf_sysinfo_open(void);
static vmf_ret_t  vmf_sysinfo_close(void);
static vmf_ret_t  vmf_sysinfo_calculate_and_send_process_load(void);
static vmf_ret_t  vmf_sysinfo_get_total_memory(unsigned32 *p_total_mem);
static int        vmf_getCPUcount(void);
#endif  /* #ifdef __LINUX__        */


#ifdef __ANDROID__
#include <cpu-features.h>
#endif

#ifdef __QNX__
#include <sys/procfs.h>


enum MEM_TYPE
{
    MEM_TEXT,
    MEM_DATA,
    MEM_STACK,
    MEM_DYNAMIC,
    MEM_SHARED,
    MEM_DEVICE,
    MEM_DLL,
    MEM_MAP_SHARED,
    MEM_ALL
};

static unsigned32   elapsed_time_ms=1;
static int          procfs_get_process_mapinfo(int fd, procfs_mapinfo ** mapinfo_pp);
static size_t       procfs_get_mem_size(int pid, int mtype);
static int          classify_block(procfs_mapinfo *map) ;
static unsigned32   GetElapsedTime(unsigned64 start_time,unsigned64 stop_time);

#endif

/* macros for all versions */
#define VMF_SYSINFO_MIN_TIME        (50)
#define MAX_TASK_MONITOR            (30)
#define VMF_SYSINFO_TIME_INVALID    (10000)
#define MAX_PIDS                    (100)
#define MAX_DSP_PIDS                (10)
#define PROC_BASE                   "/proc"
#define MILLION                     (1000000L)
#define MAX_ATTEMPTS                (10)

/* debug macros */
#ifdef FULL_DEBUG
#define MY_TRACE(arg...)            (void) fprintf(ERROR_CHANNEL,arg)
#define MY_TRACE2(arg...)           (void) fprintf(ERROR_CHANNEL,arg)
#define MY_ERROR(arg...)            (void) fprintf(ERROR_CHANNEL,arg)
#else
#define MY_TRACE(arg...)
#define MY_TRACE2(arg...)
#define MY_ERROR(arg...)            (void) fprintf(ERROR_CHANNEL,arg)
#endif


/* variables for all versions */
static vmf_client_id_t              my_cid=0;
static proc_sys_info_t              requested_pids[MAX_PIDS] ;
static vmf_sysinfo_load_resp_pl_t   sysinfo_load;
static vmf_sysinfo_pidlist_t        current_pids;
static long                         timesinceboot;
static unsigned16                   requested_pids_count=0;
static unsigned16                   int_time=VMF_SYSINFO_TIME_INVALID;      /* integration time in ms */
static unsigned16                   num_cpus=1;                             /* number of CPUs */
static unsigned32                   mem_total = 0;
static bool                         new_pid_name_request=false;
static bool                         procs_alive[MAX_PIDS];

/* local function declaration for all versions */
static void      *vmf_sysinfo_thread(void *pArg);
static vmf_ret_t  vmf_sysinfo_get_idle_load(void);
static vmf_ret_t  vmf_sysinfo_calculate_and_send_process_load(void);
static vmf_ret_t  vmf_sysinfo_get_proc_stat(pid_t pid, vmf_sysinfo_proc_stat_t *proc_stat);
static vmf_ret_t  vmf_sysinfo_parse_msg(vmf_msg_t *pvmf_msg);
static vmf_ret_t  vmf_sysinfo_set_int_time(unsigned16 new_int_time);
static vmf_ret_t  vmf_sysinfo_get_requested_pids (unsigned8 *payload);
static vmf_ret_t  vmf_sysinfo_send_all_process_names(void);
static vmf_ret_t  vmf_sysinfo_get_pidlist(vmf_sysinfo_pidlist_t *p_pidlist);
static vmf_ret_t  vmf_sysinfo_send_updated_process_names(void);
static vmf_ret_t  vmf_sysinfo_send_process_name_2(pid_t pid);
static vmf_ret_t  vmf_sysinfo_send_process_name(pid_t pid);
static vmf_ret_t  vmf_sysinfo_send_load_resp(vmf_client_id_t cid,vmf_sysinfo_load_resp_pl_t *p_sysinfo_load);
static long       vmf_gettimesinceboot(void);
static vmf_ret_t  vmf_sysinfo_send_name_resp(vmf_client_id_t cid,vmf_sysinfo_pid_name_resp_pl_t *vmf_sysinfo_pid_name_resp);
static unsigned32 vmf_sysinfo_get_ms_time(void);
static unsigned16 vmf_sysinfo_get_cpu_frq(void);


#endif  /* #ifndef DISABLE_SYSINFO */






/*************************************************************************//**
 *
 *   create vmf sysinfo thread  \n
 *   NOTE: this thread will handle the cyclic load measurement
 *
 *
 *   \param[in] void      -- void
 *   \return    vmf_ret_t
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_create_sysinfo_thread  (void)
{
#ifndef DISABLE_SYSINFO
    pthread_t       th;
    pthread_attr_t  attr;
    int             iRet;
	char Thread_name[100];

    (void)pthread_attr_init(&attr);
    (void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );

    /* set the thread stack size*/
    #ifndef __ANDROID__
    iRet = pthread_attr_setstacksize  (&attr, VMF_NW_STACK_SIZE);
    if (EOK != iRet)
    {
        MY_ERROR("rem_vmf: nw_vmf_create_sysinfo_thread() - pthread_attr_setstacksize() failed: %d", iRet);
    }
    #endif

    iRet = pthread_create (&th  , &attr,vmf_sysinfo_thread,NULL);
    (void)pthread_attr_destroy(&attr);
    if (iRet)
    {
        MY_ERROR("rem_vmf: nw_vmf_create_sysinfo_thread() - pthread_create() failed: %d", iRet);
        return VMF_ERROR;
    }
#if ((defined(__QNX__) && (_NTO_VERSION >= 632)) || defined(__LINUX__))
    /* Name the vmf-trace-server thread */
	sprintf(Thread_name, "Sys-Info-%d", th);
    nw_os_set_thread_name(th, Thread_name);
#endif 
	
#endif
    return VMF_OK;
}

/* functions valid for LINUX and QNX */
#ifndef DISABLE_SYSINFO


/*************************************************************************//**
 *
 *   return time in ms
 *
 *
 *   \param[in] void
 *   \return    time in ms
 *
 ******************************************************************************/
unsigned32 vmf_sysinfo_get_ms_time(void)
{
    return (nw_os_cfg_get_ms_time());
}


/*************************************************************************//**
 *
 *   parse msg
 *
 *
 *   \param[in] void
 *   \return    time in ms
 *
 ******************************************************************************/
static vmf_ret_t  vmf_sysinfo_parse_msg(vmf_msg_t *pvmf_msg)
{
    vmf_ret_t   vmf_ret=VMF_OK;

    /* check if message is a control message */
    if (VMF_BASIC_MSG_GROUP_ID(pvmf_msg) != VMF_TRACE_SYSINFO_CTRL)
    {
        MY_TRACE("vmf_sysinfo_parse_msg group != VMF_TRACE_SYSINFO_CTRL\n");
        return VMF_ERROR;
    }

    switch (VMF_BASIC_MSG_EVENT_ID(pvmf_msg))
    {
        case VMF_SYSINFO_CTRL_PROFILER_START:
        {
            vmf_sysinfo_start_req_pl_t *ptr;
            requested_pids_count=0;
            ptr = (vmf_sysinfo_start_req_pl_t*)(pvmf_msg->vmf_basic_msg.data.pl);
            (void) vmf_sysinfo_set_int_time(ptr->int_time);
            MY_TRACE("vmf_sysinfo_parse_msg VMF_SYSINFO_CTRL_PROFILER_START(%d)\n",ptr->int_time);
        }
        break;

        case VMF_SYSINFO_CTRL_PROFILER_STOP:
        {
            MY_TRACE("vmf_sysinfo_parse_msg VMF_SYSINFO_CTRL_PROFILER_STOP\n");
            (void) vmf_sysinfo_set_int_time(VMF_SYSINFO_TIME_INVALID);
        }
        break;

        case VMF_SYSINFO_CTRL_PROFILER_START_LOAD_REQ:
            MY_TRACE("vmf_sysinfo_parse_msg VMF_SYSINFO_CTRL_PROFILER_START_LOAD_REQ\n");
            vmf_ret = vmf_sysinfo_get_requested_pids((unsigned8 *)pvmf_msg->vmf_basic_msg.data.pl);
        break;

        case VMF_SYSINFO_CTRL_PROFILER_STOP_LOAD_REQ:
            MY_TRACE("vmf_sysinfo_parse_msg VMF_SYSINFO_CTRL_PROFILER_STOP_LOAD_REQ\n");
        break;

        case VMF_SYSINFO_CTRL_PROFILER_PID_NAME_REQ:
        {
            vmf_sysinfo_pid_name_req_pl_t *ptr;
            MY_TRACE("vmf_sysinfo_parse_msg VMF_SYSINFO_CTRL_PROFILER_PID_NAME_REQ\n");

            ptr = (vmf_sysinfo_pid_name_req_pl_t*)(pvmf_msg->vmf_basic_msg.data.pl);
            if (SYSINFO_ALL_PIDS == ptr->pid)
            {
                /* send a pids */
                vmf_ret = vmf_sysinfo_send_all_process_names();
            }
            else if (SYSINFO_UPDATE_PIDS == ptr->pid)
            {
                /* send only updated pids */
                vmf_ret = vmf_sysinfo_send_updated_process_names();
            }
            else
            {   /* send only this pid */
                vmf_ret = vmf_sysinfo_send_process_name((pid_t)ptr->pid);
            }
            break;
        }
        default:
            MY_TRACE("vmf_sysinfo_parse_msg invalid cmd=%d\n",VMF_BASIC_MSG_EVENT_ID(pvmf_msg));
            vmf_ret = VMF_ERROR;
        break;
    }
    return vmf_ret;
}

/*************************************************************************//**
 *
 *   vmf sysinfo \n
 *   NOTE: set the integration time for the load integration
 *
 *
 *   \param[in] unsigned16 new_int_time
 *   \return    vmf_error_t
 *
 ******************************************************************************/
static vmf_ret_t  vmf_sysinfo_set_int_time(unsigned16 new_int_time)
{
    int_time = new_int_time;

    return VMF_OK;
}



 /**************************************************************************//**
 *
 *   Function Name: vmf_sysinfo_get_requested_pids
 *
 *   Description:   pick pids out of received VMF_SYSINFO_CTRL_PROFILER_START_LOAD_REQ
 *                  message and put into active pids structure.
 *
 *   \param[in]     unsigned8   *payload -- pointer to payload of a
 *                                          VMF_SYSINFO_CTRL_PROFILER_START_LOAD_REQ
 *                                          message
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_get_requested_pids (unsigned8 *payload)
{
    vmf_ret_t   vmf_ret = VMF_OK;
    unsigned16  i;
    unsigned16  offset;

    /* Byte 0..1 == PID count */
    requested_pids_count = (unsigned16)payload[0] + (unsigned16)(payload[1] << 8);
    if (requested_pids_count > MAX_PIDS)
    {
        MY_TRACE("vmf_sysinfo_get_requested_pids: pid count (=%d) too big... pl[0]=%d -- pl[1]=%d !!!\n", requested_pids_count, payload[0], payload[1]);
        requested_pids_count = 0;
        vmf_ret = VMF_ERROR;
    }

    MY_TRACE("vmf_sysinfo_get_requested_pids: pid count =%d\n", requested_pids_count);

    /* PIDs each 4 Byte */
    for (i=0; i<requested_pids_count; i++)
    {
        offset = i * 4 + 2;

        requested_pids[i+num_cpus].pid =  (unsigned32)payload[offset]           + (unsigned32)(payload[offset+1] << 8)
                                        + (unsigned32)(payload[offset+2] << 16) + (unsigned32)(payload[offset+3] << 24);

        requested_pids[i+num_cpus].s_time_jiffies=0;
        requested_pids[i+num_cpus].u_time_jiffies=0;

        procs_alive[i+num_cpus]=true;    /* mark process as alive */
        MY_TRACE("vmf_sysinfo_get_requested_pids: added pid %d\n", requested_pids[i].pid);
    }
    new_pid_name_request = true;

    return vmf_ret;
}




 /**************************************************************************//**
 *
 *   Function Name: vmf_sysinfo_send_all_process_names
 *
 *   Description:   get list of running processes and forward it to VMF
 *
 *   \param[in]     void
 *
 *   Function Return value: - VMF_OK if OK else error
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_send_all_process_names(void)
{
    DIR *ProcDir;
    struct dirent *ProcessDir;
    vmf_ret_t vmf_ret;
    pid_t   pid;

    MY_TRACE("vmf_sysinfo_send_all_process_names()\n");

    if ((ProcDir = opendir(PROC_BASE)) == NULL)
    {
        MY_ERROR("vmf_sysinfo_send_all_process_names(): Cannot opendir /proc\n");
        return VMF_ERROR;
    }

    current_pids.num = 0;

    (void)vmf_gettimesinceboot();       /* store current time into timesinceboot */

    while ((ProcessDir = readdir(ProcDir)) != NULL)
    {
        if (isdigit(ProcessDir->d_name[0]))
        {
            pid = (pid_t)atoi(ProcessDir->d_name);

            if (current_pids.num < VMF_SYSINFO_MAX_PIDLIST_PIDS)
            {
                current_pids.list[current_pids.num++]=pid;      /* store pid in pidlist */
            }

            vmf_ret = vmf_sysinfo_send_process_name_2(pid);
            if (VMF_OK != vmf_ret)
            {
                MY_ERROR("vmf_sysinfo_send_all_process_names(): vmf_sysinfo_send_process_name() failed\n");
            }
            else
            {
                /* no code */
                delay(1);       /* wait some time to prevent queue flooding */
            }
            delay(1);
        }
    }
    (void) closedir(ProcDir);
    return VMF_OK;
}




 /**************************************************************************//**
 *
 *   Function Name: vmf_sysinfo_send_updated_process_names
 *
 *   Description:   get list of changed processes and forward it to VMF
 *
 *   \param[in]     void
 *
 *   Function Return value: - VMF_OK if OK else error
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_send_updated_process_names(void)
{
    vmf_ret_t               vmf_ret;
    vmf_sysinfo_pidlist_t   new_pids;
    int                     current_pidlist_ix=0;
    int                     new_pidlist_ix=0;

    MY_TRACE("vmf_sysinfo_send_updated_process_names()\n");


    /* get the new pid-list */
    vmf_ret = vmf_sysinfo_get_pidlist(&new_pids);
    if (VMF_OK != vmf_ret)
    {
        MY_ERROR("vmf_sysinfo_send_updated_process_names(): vmf_sysinfo_get_pidlist() failed\n");
        return vmf_ret;
    }

    if (0 == new_pids.num)
    {
        MY_ERROR("vmf_sysinfo_send_updated_process_names(): number of pids=0!\n");
        return VMF_ERROR;
    }


    (void)vmf_gettimesinceboot();                           /* store current time into timesinceboot */

    /* compare new pidlist with current pidlist */
    /* search only until the end of one list is reached */
    while ((new_pidlist_ix < new_pids.num) && (current_pidlist_ix < current_pids.num))
    {
        if (current_pids.list[current_pidlist_ix] ==  new_pids.list[new_pidlist_ix])
        {
            /* no change */
            current_pidlist_ix++;
            new_pidlist_ix++;
        }
        else if (current_pids.list[current_pidlist_ix] < new_pids.list[new_pidlist_ix])
        {
            /* a process died */
            MY_TRACE("vmf_sysinfo_send_updated_process_names: process died:%d current_pidlist_ix=%d,new_pidlist_ix=%d\n",current_pids.list[current_pidlist_ix],current_pidlist_ix,new_pidlist_ix);
            vmf_ret = vmf_sysinfo_send_process_name_2(current_pids.list[current_pidlist_ix]);
            if (VMF_OK != vmf_ret)
            {
                MY_ERROR("vmf_sysinfo_send_updated_process_names(): vmf_sysinfo_send_process_name_2() failed\n");
                break;
            }
            delay(1);       /* wait some time to prevent queue flooding */
            current_pidlist_ix++;
        }
        else
        {
            /* a new process appeared */
            MY_TRACE("vmf_sysinfo_send_updated_process_names: found new process:%d\n",new_pids.list[new_pidlist_ix]);
            vmf_ret = vmf_sysinfo_send_process_name_2(new_pids.list[new_pidlist_ix]);
            if (VMF_OK != vmf_ret)
            {
                MY_ERROR("vmf_sysinfo_send_updated_process_names(): vmf_sysinfo_send_process_name_2() failed\n");
                break;
            }
            delay(1);       /* wait some time to prevent queue flooding */
            new_pidlist_ix++;
        }
    }


    /* one list has more pids than the other */
    while((new_pidlist_ix < new_pids.num) || (current_pidlist_ix < current_pids.num))
    {
        if (current_pidlist_ix < current_pids.num)
        {
            /* pid is in current list but not in new list */
            /* so  the processes died */
            MY_TRACE("vmf_sysinfo_send_updated_process_names: process died:%d current_pidlist_ix=%d,new_pidlist_ix=%d\n",current_pids.list[current_pidlist_ix],current_pidlist_ix,new_pidlist_ix);
            vmf_ret = vmf_sysinfo_send_process_name_2(current_pids.list[current_pidlist_ix]);
            if (VMF_OK != vmf_ret)
            {
                MY_ERROR("vmf_sysinfo_send_updated_process_names(): vmf_sysinfo_send_process_name_2() failed\n");
                break;
            }
            delay(1);       /* wait some time to prevent queue flooding */
            current_pidlist_ix++;
        }
        else if (new_pidlist_ix < new_pids.num)
        {
            /* there are pids in new list but nor in current list */
            /* so these pids are new */
            MY_TRACE("vmf_sysinfo_send_updated_process_names: found new process:%d\n",new_pids.list[new_pidlist_ix]);
            vmf_ret = vmf_sysinfo_send_process_name_2(new_pids.list[new_pidlist_ix]);
            if (VMF_OK != vmf_ret)
            {
                MY_ERROR("vmf_sysinfo_send_updated_process_names(): vmf_sysinfo_send_process_name_2() failed\n");
                break;
            }
            delay(1);       /* wait some time to prevent queue flooding */
            new_pidlist_ix++;
        }
    }



    /* store new pidlist as current pidlist */
    current_pids = new_pids;

    return VMF_OK;
}



/**************************************************************************//**
 *
 *   Function Name: vmf_sysinfo_get_pidlist
 *
 *   Description:   get list of pids and store it in a pidlist
 *
 *   \param[in]     void
 *
 *   Function Return value: - VMF_OK if OK else error
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_get_pidlist (vmf_sysinfo_pidlist_t *p_pidlist)
{
    DIR *ProcDir;
    struct dirent *ProcessDir;
    pid_t   pid;


    if ((ProcDir = opendir(PROC_BASE)) == NULL)
    {
        MY_ERROR("vmf_sysinfo_send_all_process_names(): Cannot opendir /proc\n");
        return VMF_ERROR;
    }

    p_pidlist->num = 0;

    while ((ProcessDir = readdir(ProcDir)) != NULL)
    {
        if (isdigit(ProcessDir->d_name[0]))
        {
            pid = (pid_t)atoi(ProcessDir->d_name);
            p_pidlist->list[p_pidlist->num++]=pid;      /* store pid in pidlist */
            if (p_pidlist->num >= VMF_SYSINFO_MAX_PIDLIST_PIDS)
            {
                break;
            }
        }
    }
    (void) closedir(ProcDir);
    delay(1);
    return VMF_OK;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_sysinfo_send_process_name
 *
 *   Description:   get process infos and forward it to VMF
 *                  data is taken from /proc/[pid]/stat
 *
 *   \param[in]     void
 *
 *   Function Return value: - VMF_OK if OK else error
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_send_process_name_2(pid_t pid)
{
    vmf_sysinfo_pid_name_resp_pl_t  vmf_resp;
    vmf_sysinfo_proc_stat_t proc_stat = {0};
    vmf_ret_t vmf_ret;

    vmf_ret = vmf_sysinfo_get_proc_stat(pid,&proc_stat);
    if (VMF_OK == vmf_ret)
    {
        vmf_resp.MemTotal = mem_total;
        vmf_resp.pid = (unsigned32)pid;

#ifdef __QNX__
        {
            nw_os_sstrncpy(vmf_resp.name, &proc_stat.name[0], STRING_LENGTH);
        }
#else
        {
            nw_os_sstrncpy(vmf_resp.name, &proc_stat.name[1], STRING_LENGTH);
        }
#endif

        vmf_resp.state  =  proc_stat.state;
        vmf_resp.ppid   = (unsigned32)proc_stat.ppid;
        vmf_resp.Threads= (unsigned32)proc_stat.Threads;
        vmf_resp.VmSize = (unsigned32)proc_stat.VmSize;
        vmf_resp.VmRSS  = (unsigned32)proc_stat.VmRSS;
        vmf_resp.utime  = (unsigned32)proc_stat.utime;
        vmf_resp.stime  = (unsigned32)proc_stat.stimev;
        vmf_resp.rtime  = (unsigned32)proc_stat.running_time;

    #if 0
        printf("proc_name=%s - ",vmf_resp.name);
        printf("State=%c ",vmf_resp.state);
        printf("PID=%d ",vmf_resp.pid);
        printf("PPID=%d ",vmf_resp.ppid);
        printf("VmSize=%d ",vmf_resp.VmSize);
        printf("VmRSS=%d ",vmf_resp.VmRSS);
        printf("Threads=%d\n",vmf_resp.Threads);
        printf("MemTotal=%d\n",vmf_resp.MemTotal);
    #endif

        /* forward information to tracer-frontend */
        vmf_ret = vmf_sysinfo_send_name_resp(my_cid,&vmf_resp);
        if (VMF_OK != vmf_ret)
        {
            MY_ERROR("vmf_sysinfo_send_process_name_2(): vmf_sysinfo_send_name_resp() failed\n");
        }
    }
    else
    {
        /* inform front-end that process died */
        vmf_resp.pid    = (unsigned32)pid;
        vmf_resp.state  = 'X';
        vmf_resp.Threads= 0;
        vmf_resp.VmSize = 0;
        vmf_resp.VmRSS  = 0;
        vmf_resp.name[0]= 0;

        vmf_ret = vmf_sysinfo_send_name_resp(my_cid,&vmf_resp);
        if (VMF_OK != vmf_ret)
        {
            MY_ERROR("vmf_sysinfo_send_process_name_2(): vmf_sysinfo_send_name_resp() failed\n");
        }
    }
    return (vmf_ret);
}



 /**************************************************************************//**
 *
 *   Function Name: vmf_sysinfo_send_name_resp
 *
 *   Description:   send the load response message
 *
 *   \param[in]     cid                         tx client id
 *   \param[in]     vmf_sysinfo_pid_name_resp_pl_t payload
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_send_name_resp(vmf_client_id_t cid,vmf_sysinfo_pid_name_resp_pl_t *vmf_sysinfo_pid_name_resp)
{
    vmf_ret_t vmf_ret;

    VMF_VAR_BASIC_MSG_TYP(sizeof(vmf_sysinfo_pid_name_resp_pl_t)) vmf_basic_msg;

    /* prepare payload*/
    vmf_basic_msg.msg_base.id.group = VMF_TRACE_SYSINFO_DATA;
    vmf_basic_msg.msg_base.id.event = VMF_SYSINFO_DATA_PROFILER_PID_NAME_RESP;
    vmf_basic_msg.data.length = sizeof(vmf_sysinfo_pid_name_resp_pl_t) - sizeof(vmf_sysinfo_pid_name_resp->name) + strlen(vmf_sysinfo_pid_name_resp->name)+1;
    nw_os_smemcpy(vmf_basic_msg.data.pl,sizeof(vmf_basic_msg.data.pl),vmf_sysinfo_pid_name_resp, vmf_basic_msg.data.length);

    /* send data to VMF */
    vmf_ret = nw_vmf_send_basic (cid,(vmf_basic_msg_t*)&vmf_basic_msg);
    if(vmf_ret < 0)
    {
        MY_ERROR("vmf_sysinfo_send_name_resp(): nw_vmf_send_basic() failed\n");
    }

    return vmf_ret;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_sysinfo_send_load_resp
 *
 *   Description:   send the load response message
 *
 *   \param[in]     cid                         tx client id
 *   \param[in]     vmf_sysinfo_load_resp_pl_t payload
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_send_load_resp(vmf_client_id_t cid,vmf_sysinfo_load_resp_pl_t *p_sysinfo_load)
{
    vmf_ret_t vmf_ret;

    VMF_VAR_MSG_TYP(sizeof(vmf_sysinfo_load_resp_pl_t)) vmf_msg;

    VMF_BASIC_MSG_GROUP_ID(&vmf_msg)    = VMF_TRACE_SYSINFO_DATA;
    VMF_BASIC_MSG_EVENT_ID(&vmf_msg)    = VMF_SYSINFO_DATA_PROFILER_LOAD_RESP;

    /* copy payload */
    vmf_msg.vmf_basic_msg.data.length = sizeof(vmf_sysinfo_load_resp_pl_t);
    nw_os_smemcpy(vmf_msg.vmf_basic_msg.data.pl,sizeof(vmf_msg.vmf_basic_msg.data.pl),p_sysinfo_load, vmf_msg.vmf_basic_msg.data.length);

    vmf_ret = nw_vmf_send_basic (cid,(vmf_basic_msg_t*)&vmf_msg);
    if(vmf_ret < 0)
    {
        MY_ERROR("vmf_sysinfo_send_load_resp - nw_vmf_send_basic() failed\n");
    }

    return vmf_ret;
}


#if defined (__LINUX__) || defined (__ANDROID__)

NW_COMPILER_MESSAGE("Sysinfo Linux / Android")



/*************************************************************************//**
 *
 *   vmf sysinfo thread \n
 *   NOTE: this function will never return
 *
 *
 *   \param[in] pmsg     -- pointer to a gw message
 *   \return    vmf_error_t
 *
 ******************************************************************************/
static void *vmf_sysinfo_thread(void *pArg)
{
    vmf_error_t vmf_ret=VMF_OK;
//    VMF_VAR_MSG_TYP(100)   my_msg;
    unsigned8       nw_vmf_trace_group_list[] = {VMF_TRACE_SYSINFO_CTRL};
    unsigned32      last_tx_time= vmf_sysinfo_get_ms_time();
    unsigned16      current_timeout=int_time;
    vmf_msg_t       vmf_msg;

    MY_TRACE("vmf_sysinfo_thread started\n");

    UNUSED_PARAM(pArg);

    /* connect to VMF */
    my_cid = nw_vmf_connect("vmf_sysinfo", NULL, 0, VMF_CLIENT_QUEUE_SIZE_STANDARD, VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD);
    if (my_cid < 0)
    {
        return (NULL);
    }

    /* register message group */
    vmf_ret = nw_vmf_register_msg_group (my_cid, sizeof(nw_vmf_trace_group_list), nw_vmf_trace_group_list);
    if (vmf_ret < 0)
    {
        return (NULL);
    }

    /* get total system memory */
    (void)vmf_sysinfo_get_total_memory(&mem_total);

    /* get and store ticks per seconds */
    tickspersec = sysconf(_SC_CLK_TCK);
    /* get number of cores */
    num_cpus = vmf_getCPUcount();
    requested_pids_count = 0;

    while (1)
    {
        vmf_ret = nw_vmf_timed_receive(my_cid,&vmf_msg,VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD,current_timeout);
        if (vmf_ret <= 0)
        {
            MY_TRACE("vmf sysinfo thread: timeout\n");

            /* timeout */
            current_timeout = int_time; // next_tx_time - vmf_sysinfo_get_ms_time();

            if (VMF_SYSINFO_TIME_INVALID != int_time)
            {
                /* store current time as tx time */
                last_load_calc_time_ms = vmf_sysinfo_get_ms_time();
                last_tx_time = last_load_calc_time_ms;

                /* get load and send it */
                if (vmf_sysinfo_get_idle_load() < VMF_OK)
                {
                    MY_TRACE("vmf sysinfo thread: get and send idle load failed!\n");
                }

                /* get load for requested PIDs and send */
                if (vmf_sysinfo_calculate_and_send_process_load() < VMF_OK)
                {
                    MY_TRACE("vmf sysinfo thread: calculate and send processes load failed!\n");
                }
            }
        }
        else
        {
            MY_TRACE("vmf sysinfo thread: msg received\n");

            /* msg received - parse commands */
            vmf_sysinfo_parse_msg(&vmf_msg);

            if (VMF_SYSINFO_TIME_INVALID != int_time)
            {
                unsigned32  t_tmp;

                /* calculate remaining waiting time */
                t_tmp = (vmf_sysinfo_get_ms_time() - last_tx_time);
                if (t_tmp < int_time)
                {
                    current_timeout = int_time - t_tmp;
                }
                else
                {
                    current_timeout = 1;            /* very short time */
                }
            }
            else
            {
                current_timeout = VMF_SYSINFO_TIME_INVALID;
            }
        }
    }

    return(NULL);
}





/*************************************************************************//**
 *
 *   open whatever is needed to get the sysinfo \n
 *
 *
 *   \param[in] void
 *   \return    vmf_error_t
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_open(void)
{
    vmf_ret_t ret_val = VMF_OK;

    idle_load_file = fopen(IDLE_LOAD_FILE, "r");

    if (NULL == idle_load_file)
    {
        ret_val = VMF_ERROR;
    }

    return (ret_val);
}


/*************************************************************************//**
 *
 *   open what ever is needed to get the sysinfo \n
 *
 *
 *   \param[in] void
 *   \return    vmf_error_t
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_close(void)
{
    vmf_ret_t ret_val = VMF_OK;

    fclose(idle_load_file);

    return (ret_val);
}


/*************************************************************************//**
 *
 *   open what ever is needed to get the sysinfo \n
 *
 *
 *   \param[in] void
 *   \return    vmf_error_t
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_get_idle_load(void)
{
    vmf_ret_t ret_val = VMF_OK;
    int  user;
    int  nice;
    int  systm;
    int  idle;
    int  iowait;
    int  irq;
    int  sirq;
    int  num=0;
    char ch_tmp[80];
    unsigned8 cpu=0;
    unsigned32    consumed_time_ms=0;
    unsigned32    jiffies2=0;
    unsigned32    jiffies2_d;
    static unsigned32   jiffies2_old[VMF_TRACE_LOAD_MAX_LOADS];
    static int old_system[VMF_TRACE_LOAD_MAX_LOADS]={0,0};
    static int old_niceuser[VMF_TRACE_LOAD_MAX_LOADS]={0,0};
    static int old_idle[VMF_TRACE_LOAD_MAX_LOADS]={0,0};
    static int old_iowait[VMF_TRACE_LOAD_MAX_LOADS]={0,0};
    static int old_irq[VMF_TRACE_LOAD_MAX_LOADS]={0,0};
    static int old_sirq[VMF_TRACE_LOAD_MAX_LOADS]={0,0};
    static unsigned32   old_load_calc_time_ms=0;


    #define PROC_STAT_FMT     "cpu%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d"
    #define PROC_STAT_ALL_FMT "cpu\t%d\t%d\t%d\t%d\t%d\t%d\t%d"

    /* get "real" consumed time */
    consumed_time_ms = last_load_calc_time_ms - old_load_calc_time_ms;
    old_load_calc_time_ms = last_load_calc_time_ms;

    vmf_sysinfo_open();

    /* get total jiffies of all cpus */
    num = fscanf(idle_load_file, PROC_STAT_ALL_FMT,&user,&nice,&systm,&idle,&iowait,&irq,&sirq);
    fgets (ch_tmp,sizeof(ch_tmp),idle_load_file);

    sysinfo_load.num_loads=0;

    /* get load of all cpus */
    while(true)
    {
        num = fscanf(idle_load_file, PROC_STAT_FMT, (int*)&cpu,&user,&nice,&systm,&idle,&iowait,&irq,&sirq);
        fgets (ch_tmp,sizeof(ch_tmp),idle_load_file);       /* set file-pointer to start of next line */


        jiffies2 = user+nice+systm+idle+iowait+irq+sirq;
        jiffies2_d= jiffies2-jiffies2_old[cpu];
        jiffies2_old[cpu] = jiffies2;
        if (jiffies2_d == 0)
        {
            jiffies2_d = 1;
        }

        if ((num > 0) && (cpu < VMF_TRACE_LOAD_MAX_LOADS))
        {
            /* found CPU */

            sysinfo_load.load[cpu].pid      = 0;  /* system load = CPU 0 */
            sysinfo_load.load[cpu].cpu_num  = cpu;
            sysinfo_load.load[cpu].s_time   = ((systm-old_system[cpu])     *255)/jiffies2_d;
            sysinfo_load.load[cpu].u_time   = ((user+nice-old_niceuser[cpu])*255)/jiffies2_d;
            sysinfo_load.load[cpu].io_time  = ((iowait-old_iowait[cpu])     *255)/jiffies2_d;
            sysinfo_load.load[cpu].irq_time = ((irq-old_irq[cpu])           *255)/jiffies2_d;
            sysinfo_load.load[cpu].sirq_time= ((sirq-old_sirq[cpu])         *255)/jiffies2_d;
            sysinfo_load.load[cpu].idle_time= ((idle - old_idle[cpu])       *255)/jiffies2_d;
            sysinfo_load.num_loads++;

#if 0
            {
                {
                    fprintf(stderr,"cpu=%d - ",cpu);
                    fprintf(stderr,"s_time=%d - ",sysinfo_load.load[cpu].s_time);
                    fprintf(stderr,"jiffies2_d=%d - ",jiffies2_d);
                    fprintf(stderr,"u_time=%d\n ",sysinfo_load.load[cpu].u_time);
                }
            }
#endif


            /* print results */
            MY_TRACE("; s_load=%03d"         ,sysinfo_load.load[cpu].s_time);
            MY_TRACE("; u_load=%03d\n"       ,sysinfo_load.load[cpu].u_time);

            /* store valus as "old" values */
            old_system[cpu] = systm;
            old_niceuser[cpu]  = user+nice;
            old_idle[cpu]  = idle;
            old_iowait[cpu]= iowait;
            old_irq[cpu]   = irq;
            old_sirq[cpu]  = sirq;
        }
        else
        {
            /* invalid CPU */
            break;
        }
    }

    {
        unsigned32 jiffis_singlecore=0;

        jiffis_singlecore = (consumed_time_ms * tickspersec)/1000;
        jiffies_allcores = jiffis_singlecore * (cpu+1);
        if (jiffies_allcores == 0)
        {
            jiffies_allcores = 1;
        }
    }

    vmf_sysinfo_close();
    MY_TRACE("\n");

    return ret_val;
}


/*************************************************************************//**
 *
 *   vmf_sysinfo_calculate_and_send_process_load
 *   get process load of requested processes and transfer it to frontend
 *
 *   \param[in] void
 *   \return    void
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_calculate_and_send_process_load(void)
{
    #define VMF_SYSINFO_PL_CHECK_ALIVE

    vmf_ret_t       ret_val = VMF_OK;
    unsigned16      i=0;
    unsigned16      num_dead=0;                         /* number of dead processes */
    unsigned32      u_time_diff_jiffies;
    unsigned32      u_time_diff_load;
    unsigned32      s_time_diff_jiffies;
    unsigned32      s_time_diff_load;
    unsigned32      pid;
    vmf_sysinfo_proc_stat_t proc_stat;
    unsigned16      cpu_frq=0;

    for (i=num_cpus; i<(requested_pids_count+num_cpus); i++)
    {
        /* check if process is alive */
#ifdef VMF_SYSINFO_PL_CHECK_ALIVE
        if (procs_alive[i]!=false)
#else
        if (1)
#endif
        {
            pid = requested_pids[i].pid;
            if (VMF_OK ==  vmf_sysinfo_get_proc_stat(pid, &proc_stat))
            {

                u_time_diff_jiffies = proc_stat.utime - requested_pids[i].u_time_jiffies;
                requested_pids[i].u_time_jiffies = proc_stat.utime;
                u_time_diff_load = (u_time_diff_jiffies*255) / jiffies_allcores;
                MY_TRACE("vmf sysinfo thread: u_time_diff_jiffies=%d -- u_load=%d \n", (int)u_time_diff_jiffies, u_time_diff_load);

                s_time_diff_jiffies = proc_stat.stimev - requested_pids[i].s_time_jiffies;
                requested_pids[i].s_time_jiffies = proc_stat.stimev;
                s_time_diff_load = (s_time_diff_jiffies*255) / jiffies_allcores;
                MY_TRACE("vmf sysinfo thread: s_time_diff_jiffies=%d -- s_load=%d \n", (int)s_time_diff_jiffies, s_time_diff_load);

                sysinfo_load.load[i-num_dead].pid       = pid;
                sysinfo_load.load[i-num_dead].cpu_num   = 0;
                sysinfo_load.load[i-num_dead].s_time    = s_time_diff_load;
                sysinfo_load.load[i-num_dead].u_time    = u_time_diff_load;
                sysinfo_load.load[i-num_dead].io_time   = 0;
                sysinfo_load.load[i-num_dead].irq_time  = 0;
                sysinfo_load.load[i-num_dead].sirq_time = 0;
            }
            else
            {
                /* process just died */
#ifndef VMF_SYSINFO_PL_CHECK_ALIVE
                sysinfo_load.load[i-num_dead].pid       = pid;
                sysinfo_load.load[i-num_dead].cpu_num   = 0;
                sysinfo_load.load[i-num_dead].s_time    = 0;
                sysinfo_load.load[i-num_dead].u_time    = 0;
                sysinfo_load.load[i-num_dead].io_time   = 0;
                sysinfo_load.load[i-num_dead].irq_time  = 0;
                sysinfo_load.load[i-num_dead].sirq_time = 0;
#else
                procs_alive[i]=false;       /* do not check this process in the future */
                num_dead++;
#endif
                MY_TRACE("process died pid%d i=%d\n",pid,i);
            }
        }
        else
        {
            MY_TRACE("irgnore pid%d i=%d\n",pid,i);
            num_dead++;
        }
    }

    cpu_frq = vmf_sysinfo_get_cpu_frq();
    sysinfo_load.version   = SYSINFO_LOAD_RESP_VERSION_1;
    sysinfo_load.num_loads = num_cpus + requested_pids_count - num_dead;
    sysinfo_load.cpu_frq_l = (unsigned8)(cpu_frq & 0xff);
    sysinfo_load.cpu_frq_h = (unsigned8)((cpu_frq >> 8) & 0xff);

    MY_TRACE("requested_pids_count=%d, num_dead=%d, num_loads=%d\n",requested_pids_count,num_dead,sysinfo_load.num_loads);

    if ((sysinfo_load.num_loads > 0) && (false == new_pid_name_request))
    {
        ret_val = vmf_sysinfo_send_load_resp(my_cid,&sysinfo_load);
        delay(1);
    }
    else
    {
        new_pid_name_request = false;
    }

    return ret_val;
}





/*************************************************************************//**
 *
 *   get current CPU frequency in MHz
 *
 *   \param[in] void
 *   \return    void
 *
 ******************************************************************************/
static unsigned16 vmf_sysinfo_get_cpu_frq(void)
{
    FILE *fp;
    unsigned    cpu_frq=0;
    unsigned16  cpu_frq_mhz=0;

    fp = fopen(CPU_FRQ_FILE, "r");
    if(fp != NULL)
    {
       /* get frequency in KHz */
       fscanf(fp, "%u", &cpu_frq);
       cpu_frq_mhz = cpu_frq/1000;
       fclose(fp);
    }

    return (cpu_frq_mhz);
}






 /**************************************************************************//**
 *
 *   Function Name: vmf_sysinfo_send_process_name
 *
 *   Description:   get process infos and forward it to VMF
 *                  data is taken from /proc/[pid]/status
 *
 *   \param[in]     void
 *
 *   Function Return value: - VMF_OK if OK else error
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_send_process_name(pid_t pid)
{
    int threads;
    FILE *file_hd;
    char ProcFileName[STRING_LENGTH+1];
    char line[STRING_LENGTH+1];
    vmf_sysinfo_pid_name_resp_pl_t  vmf_resp;
    vmf_ret_t vmf_ret;

    MY_TRACE("vmf_sysinfo_send_process_name(%d)\n",pid);


    vmf_resp.pid = pid;

    sprintf(ProcFileName,"/proc/%d/status",vmf_resp.pid);
    file_hd = fopen(ProcFileName,"r");
    if (file_hd != NULL)
    {
        line[0] = 0;
        vmf_resp.ppid = -1;
        vmf_resp.VmRSS = 0;
        vmf_resp.VmSize = 0;
        threads = 0xffff;
        vmf_resp.name[0] = 0;
        vmf_resp.state = ' ';
        vmf_resp.MemTotal = mem_total;

        while (fgets(line,STRING_LENGTH-1,file_hd) != NULL)
        {
            sscanf(line,"Name:\t%70s",(char *)&vmf_resp.name); /* currently hard coded */
            sscanf(line,"State:\t%c",&vmf_resp.state);
            sscanf(line,"VmSize:\t%d",&vmf_resp.VmSize);
            sscanf(line,"PPid:\t%d",&vmf_resp.ppid);
            sscanf(line,"VmRSS:\t%d",&vmf_resp.VmRSS);
            sscanf(line,"Threads:\t%d",&threads);
            vmf_resp.Threads = threads;

            if (vmf_resp.Threads != 0xffff)
            {
                break;
            }
        }
        vmf_resp.name[STRING_LENGTH-1]=0;

        vmf_resp.version = SYSINFO_PID_NAME_RESP_VERSION;
#if 0
                printf("proc_name=%s - ",vmf_resp.name);
                printf("State=%c ",vmf_resp.state);
                printf("PID=%d ",vmf_resp.pid);
                printf("PPID=%d ",vmf_resp.ppid);
                printf("VmSize=%d ",vmf_resp.VmSize);
                printf("VmRSS=%d ",vmf_resp.VmRSS);
                printf("Threads=%d\n",vmf_resp.Threads);
#endif
        /* forward information to Tracer */
        vmf_ret = vmf_sysinfo_send_name_resp(my_cid,&vmf_resp);
        if (VMF_OK != vmf_ret)
        {
            MY_ERROR("vmf_sysinfo_send_process_name(): vmf_sysinfo_send_name_resp() failed\n");
        }
        fclose(file_hd);
    }
    else
    {
        MY_ERROR("vmf_sysinfo_send_process_name(): fopen(%s) failed\n",ProcFileName);
    }
    return VMF_OK;
}






 /**************************************************************************//**
 *
 *   Function Name: vmf_sysinfo_get_proc_stat
 *
 *   Description:   get process infos from /proc/[pid]/stat
 *
 *   \param[in]     void
 *
 *   Function Return value: - VMF_OK if OK else error
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_get_proc_stat(pid_t pid, vmf_sysinfo_proc_stat_t *proc_stat)
{
    #define readlonglong(hd,x) { fscanf(hd, "%lld ", x); }
    #define readunsigned(hd,x) { fscanf(hd, "%llu ", x); }
    #define readstr(hd,x)      { fscanf(hd, "%s ", x);}
    #define readchar(hd,x)     { fscanf(hd, "%c ", x);}

    FILE *file_hd=NULL;
    char ProcFileName[PATH_MAX+1];
    vmf_ret_t vmf_ret=VMF_OK;

    sprintf(ProcFileName,"/proc/%d/stat",pid);
    file_hd = fopen(ProcFileName,"r");
    if (NULL != file_hd)
    {
        readlonglong(file_hd,&proc_stat->pid);
        readstr(file_hd,proc_stat->name);
        readchar(file_hd,&proc_stat->state);
        readlonglong(file_hd,&proc_stat->ppid);
        readlonglong(file_hd,&proc_stat->pgid);
        readlonglong(file_hd,&proc_stat->sid);
        readlonglong(file_hd,&proc_stat->tty_nr);
        readlonglong(file_hd,&proc_stat->tty_pgrp);
        readlonglong(file_hd,&proc_stat->flags);
        readlonglong(file_hd,&proc_stat->min_flt);
        readlonglong(file_hd,&proc_stat->cmin_flt);
        readlonglong(file_hd,&proc_stat->maj_flt);
        readlonglong(file_hd,&proc_stat->cmaj_flt);
        readlonglong(file_hd,&proc_stat->utime);
        readlonglong(file_hd,&proc_stat->stimev);
        readlonglong(file_hd,&proc_stat->cutime);
        readlonglong(file_hd,&proc_stat->cstime);
        readlonglong(file_hd,&proc_stat->priority);
        readlonglong(file_hd,&proc_stat->nicev);
        readlonglong(file_hd,&proc_stat->Threads);
        readlonglong(file_hd,&proc_stat->it_real_value);
        readunsigned(file_hd,&proc_stat->start_time);
        proc_stat->running_time = timesinceboot-(long)proc_stat->start_time;

        readlonglong(file_hd,&proc_stat->VmSize);
        readlonglong(file_hd,&proc_stat->VmRSS);
        readlonglong(file_hd,&proc_stat->rsslim);
        readlonglong(file_hd,&proc_stat->start_code);
        readlonglong(file_hd,&proc_stat->end_code);
    #ifdef VMF_SYSINFO_PROC_STAT_ALL_DATA
        readlonglong(file_hd,&proc_stat->start_stack);
        readlonglong(file_hd,&proc_stat->esp);
        readlonglong(file_hd,&proc_stat->eip);
        readlonglong(file_hd,&proc_stat->pending);
        readlonglong(file_hd,&proc_stat->blocked);
        readlonglong(file_hd,&proc_stat->sigign);
        readlonglong(file_hd,&proc_stat->sigcatch);
        readlonglong(file_hd,&proc_stat->wchan);
        readlonglong(file_hd,&proc_stat->zero1);
        readlonglong(file_hd,&proc_stat->zero2);
        readlonglong(file_hd,&proc_stat->exit_signal);
        readlonglong(file_hd,&proc_stat->cpu);
        readlonglong(file_hd,&proc_stat->rt_priority);
        readlonglong(file_hd,&proc_stat->policy);
    #endif
    #if 0
        printf("proc_name=%s - ",proc_stat->name);
        printf("State=%c "      ,proc_stat->state);
        printf("PID=%d "        ,(int)proc_stat->pid);
        printf("PPID=%d "       ,(int)proc_stat->ppid);
        printf("VmSize=%d "     ,(int)proc_stat->VmSize);
        printf("VmRSS=%d \n"    ,(int)proc_stat->VmRSS);
        printf("Threads=%d - "  ,(int)proc_stat->Threads);
        printf("cutime=%ld - "  ,(long)proc_stat->cutime);
        printf("cstime=%ld\n"   ,(long)proc_stat->cstime);
        printf("utime=%ld - "   ,(long)proc_stat->utime);
        printf("stimev=%ld\n"   ,(long)proc_stat->stimev);
        printf("start time=%llu\n",  proc_stat->start_time);
        printf("running time=%lu\n",proc_stat->running_time);
        printf("start time=%lu\n",  (long)proc_stat->start_time);
        printf("timesinceboot=%lu\n",timesinceboot);
    #endif
#if 1
        /* check if this thread is a Kernel thread and mark if yes */
        if ((proc_stat->start_code == 0) && (proc_stat->end_code == 0))
        {
            proc_stat->state = KERNEL_THREAD_STATE;
        }
#endif
        fclose(file_hd);
    }
    else
    {
        /* process does not exist anymore */
        #if 0
        MY_ERROR("vmf_sysinfo_get_proc_stat(): fopen(%s) failed\n",ProcFileName);
        #endif
        vmf_ret=VMF_ERROR;
    }
    delay(1);

    return (vmf_ret);
}




 /**************************************************************************//**
 *
 *   Function Name: vmf_gettimesinceboot
 *
 *   Description:   get time in jiffies since system booted
 *
 *   \param[in]     void
 *
 *   Function Return value: - Vtime in jiffies
 *
 ******************************************************************************/
static long vmf_gettimesinceboot(void)
{
    FILE *procuptime;
    int sec, ssec;

    #define UPTIME_FILE "/proc/uptime"

    procuptime = fopen(UPTIME_FILE, "r");
    fscanf(procuptime, "%d.%ds", &sec, &ssec);
    fclose(procuptime);

    timesinceboot = (sec*tickspersec)+(ssec*100)/tickspersec;
#if 0
printf("sec=%d,tickspersec=%d, ssec=%d\n",sec,tickspersec,ssec);
printf("timesinceboot=%lu\n",timesinceboot);
#endif
    return (timesinceboot);
}



 /**************************************************************************//**
 *
 *   Function Name: vmf_sysinfo_get_total_memory
 *
 *   Description:   get the total emory in KBytes
 *
 *   \param[in]     pointer to memory size
 *
 *   Function Return value: - VMF_OK if OK else error
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_get_total_memory(unsigned32 *p_total_mem)
{
    FILE *file_hd;
    char line[STRING_LENGTH+1];
    vmf_ret_t vmf_ret=VMF_OK;
    #define MEMINFO_FILE "/proc/meminfo"


    file_hd = fopen(MEMINFO_FILE,"r");
    if (file_hd != NULL)
    {
        *p_total_mem = 0;

        while (fgets(line,STRING_LENGTH-1,file_hd) != NULL)
        {
            if (sscanf(line,"MemTotal:\t%d",p_total_mem) > 0)
            {
                break;
            }
        }
#if 0
        printf("total_mem=%d - ",*p_total_mem);
#endif
    }
    else
    {
        MY_ERROR("vmf_sysinfo_get_total_memory(): fopen(%s) failed\n",MEMINFO_FILE);
        vmf_ret = VMF_ERROR;
    }
    return vmf_ret;
}





/**************************************************************************//**
 *
 *   Function Name: GetCPUCount
 *
 *   Description:   get number of CPU cores
 *
 *   \param[in]     void
 *
 *   Function Return value: - number of cores
 *
 ******************************************************************************/
static int vmf_getCPUcount(void)
{
    int count = 0;

#ifndef __ANDROID__
    cpu_set_t cs;
    CPU_ZERO(&cs);
    sched_getaffinity(0, sizeof(cs), &cs);
    int i;

    for (i = 0; i < 8; i++)
    {
        if (CPU_ISSET(i, &cs))
        {
            count++;
        }
    }
#else
    count = android_getCpuCount();
#endif
    MY_TRACE("vmf_getCPUcount: %d",count);

    return count;
}

#endif
#endif

#ifndef DISABLE_SYSINFO
#ifdef __QNX__
/*************************************************************************//**
 *
 *   vmf sysinfo thread - qnx version \n
 *   NOTE: this function will never return
 *
 *
 *   \param[in] pmsg     -- pointer to a gw message
 *   \return    vmf_error_t
 *
 ******************************************************************************/
static void *vmf_sysinfo_thread(void *pArg)
{

    vmf_error_t vmf_ret=VMF_OK;
    unsigned8   nw_vmf_trace_group_list[]      = {VMF_TRACE_SYSINFO_CTRL};

    MY_TRACE("vmf_sysinfo_thread started\n");

    /* connect to VMF */
    my_cid = nw_vmf_connect("vmf_sysinfo", NULL, 0, VMF_CLIENT_QUEUE_SIZE_STANDARD, VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD);
    if (my_cid < 0)
    {
        return (NULL);
    }

    /* register message group */
    vmf_ret = nw_vmf_register_msg_group (my_cid, sizeof(nw_vmf_trace_group_list), nw_vmf_trace_group_list);
    if (vmf_ret < 0)
    {
        return (NULL);
    }

    /* get number of cores */
    num_cpus =  _syspage_ptr->num_cpu;
    requested_pids_count = 0;

    while (1)
    {
        vmf_msg_t       vmf_msg;
        unsigned32      last_tx_time= vmf_sysinfo_get_ms_time();
        unsigned16      current_timeout=int_time;

        vmf_ret = nw_vmf_timed_receive(my_cid,&vmf_msg,VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD,current_timeout);
        if (vmf_ret <= 0)
        {
            {
                static unsigned16 my_timeout =0;
                if (my_timeout != current_timeout)
                {
                    MY_TRACE("vmf sysinfo thread: timeout current_timeout=%d\n",current_timeout);
                    my_timeout = current_timeout;
                }
            }

            /* timeout */
            current_timeout = int_time; // next_tx_time - vmf_sysinfo_get_ms_time();

            if (VMF_SYSINFO_TIME_INVALID != int_time)
            {
                /* store current time as tx time */
                last_tx_time= vmf_sysinfo_get_ms_time();
                /* get cpu load(s) */
                if (vmf_sysinfo_get_idle_load() < VMF_OK)
                {
                    MY_TRACE("vmf sysinfo thread: get and send idle load failed!\n");
                }

                /* get load for requested PIDs and send */
                if (vmf_sysinfo_calculate_and_send_process_load() < VMF_OK)
                {
                    MY_TRACE("vmf sysinfo thread: calculate and send processes load failed!\n");
                }
            }
        }
        else
        {
            MY_TRACE("vmf sysinfo thread: msg received\n");

            /* msg received - parse commands */
            (void) vmf_sysinfo_parse_msg(&vmf_msg);

            if (VMF_SYSINFO_TIME_INVALID != int_time)
            {
                unsigned32  t_tmp;

                /* calculate remaining waiting time */
                t_tmp = (vmf_sysinfo_get_ms_time() - last_tx_time);
                if (t_tmp < int_time)
                {
                    current_timeout = int_time - t_tmp;
                }
                else
                {
                    current_timeout = 1;            /* very short time */
                }
            }
            else
            {
                current_timeout = VMF_SYSINFO_TIME_INVALID;
            }
        }
    }



    return NULL;
}

/*****************************************************************************
 *
 *   Function Name: GetIdleLoad
 *
 *   Description:   get the overall system load in %
 *
 *   Parameters:    void
 *
 *
 *   Function Return value: system load in %
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_get_idle_load(void)
{
    /* get and transfer system load from idle task */
    unsigned64              clock_now = 0;
    static unsigned64       clock_old;
    debug_thread_t          debug_data;
    unsigned8               cpu = 0;
    unsigned16              cpu_frq = 0;
    unsigned64              su_time_current;
    unsigned64              su_time_delta;
    static unsigned64       su_time_old[VMF_TRACE_LOAD_MAX_LOADS];
    unsigned8               su_load;
    static int              proc_fd = 0;
    static bool             first_call = true;


    /* Open up the proc namespace to find our process info */
    if (0==proc_fd)
    {
        if((proc_fd = open("/proc/1/as", O_RDONLY)) == -1 )
        {
            MY_ERROR("%s: Error opening path to '/proc/1/as'!",__FUNCTION__);
            (void) close(proc_fd);
            proc_fd = 0;
            return VMF_ERROR;
        }
    }

    if (num_cpus > VMF_TRACE_LOAD_MAX_LOADS)
    {
        MY_ERROR("%s: Too many CPUs!!",__FUNCTION__);
        num_cpus = VMF_TRACE_LOAD_MAX_LOADS;
    }

    /* calculate elapsed time since last call */
    clock_now = nw_os_cfg_get_ms_time();
    elapsed_time_ms = GetElapsedTime(clock_old,clock_now);
    clock_old = clock_now;

    /* prevent division by zero*/
    if (0 == elapsed_time_ms)
    {
        elapsed_time_ms = 1;
    }

    cpu_frq = vmf_sysinfo_get_cpu_frq();
    sysinfo_load.version   =  SYSINFO_LOAD_RESP_VERSION_1;
    sysinfo_load.cpu_frq_l = (unsigned8)(cpu_frq & 0xff);
    sysinfo_load.cpu_frq_h = (unsigned8)((cpu_frq >> 8) & 0xff);
    
    /* kernel thread[i+1] is CPU[i] idle !? */
    for (cpu=0; cpu<num_cpus; cpu++)
    {
        debug_data.tid = cpu + 1; 
        (void) devctl(proc_fd, DCMD_PROC_TIDSTATUS, &debug_data, sizeof(debug_data), NULL); 
        
        su_time_current = (debug_data.sutime / 1000000);
        su_time_delta = su_time_current - su_time_old[cpu];
        su_load = 255 - ( (su_time_delta * 255) / elapsed_time_ms );
        
        //fprintf(stdout,"su_load[%d] = %d, su_time_current = %d, su_time_old = %d, su_time_delta = %d, elapsed time = %d\n", cpu, su_load, (int)su_time_current, (int)su_time_old[cpu], (int)su_time_delta, (int)elapsed_time_ms);
        //fflush(stdout);

        sysinfo_load.load[cpu].pid      = 0;  /* system load = CPU 0 */
        sysinfo_load.load[cpu].cpu_num  = cpu;
        sysinfo_load.load[cpu].s_time   = 0;
        sysinfo_load.load[cpu].u_time   = su_load;
        sysinfo_load.load[cpu].io_time  = 0;
        sysinfo_load.load[cpu].irq_time = 0;
        sysinfo_load.load[cpu].sirq_time= 0;

        /* the first value is always wrong */
        if (first_call)
        {
            sysinfo_load.load[cpu].u_time   = 0;
            first_call = false;
        }
        
        su_time_old[cpu] = su_time_current;
    }

    return (VMF_OK);
}

/*************************************************************************//**
 *
 *   get current CPU frequency in MHz
 *
 *   \param[in] void
 *   \return    void
 *
 ******************************************************************************/
static unsigned16 vmf_sysinfo_get_cpu_frq(void)
{
    unsigned64  cpu_cycles  = 0;
    unsigned16  cpu_frq_mhz = 0;

    /* get frequency in Hz */
    cpu_cycles =  SYSPAGE_ENTRY(qtime)->cycles_per_sec;
    cpu_frq_mhz = (unsigned16)(cpu_cycles / 1000000L);

//    printf("Cycles per second = %lld, CPU frequency [MHz] %lld\n", (long long)cpu_cycles, (long long)cpu_frq_mhz);
//    fflush(stdout);

    return (cpu_frq_mhz);
}



/*************************************************************************//**
 *
 *   vmf_sysinfo_calculate_and_send_process_load
 *   get process load of requested processes and transfer it to frontend
 *
 *   \param[in] void
 *   \return    void
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_calculate_and_send_process_load()
{
    #define VMF_SYSINFO_PL_CHECK_ALIVE
    vmf_ret_t       ret_val = VMF_OK;
    unsigned16      i=0;
    unsigned16      num_dead=0;                         /* number of dead processes */
    unsigned32      u_time_diff_jiffies;
    unsigned32      u_time_diff_load;
    unsigned32      s_time_diff_jiffies;
    unsigned32      s_time_diff_load;
    unsigned32      pid;
    vmf_sysinfo_proc_stat_t proc_stat;


    if (0 == elapsed_time_ms)
    {
        elapsed_time_ms = 1;
    }

    for (i=num_cpus; i<(requested_pids_count+num_cpus); i++)
    {
        /* check if process is alive */
        if (procs_alive[i]!=false)
        {
            pid = requested_pids[i].pid;

            if (VMF_OK ==  vmf_sysinfo_get_proc_stat(pid, &proc_stat))
            {
                MY_TRACE("vmf sysinfo thread: requested_pids[i].pid=%d, proc_stat.pid=%d\n", (int)pid,(int)(proc_stat.pid));
                MY_TRACE("vmf sysinfo thread: PID=%d -- name=%s -- utime=%d -- stime=%d \n", (int)(proc_stat.pid), proc_stat.name , (int)(proc_stat.utime), (int)(proc_stat.stimev));

                /* there was a change in the requested_pids array */
                /* that means that the old stored values are not valid anymore */

                /* in QNX we assume that a jiffi = 1ms */
                u_time_diff_jiffies = proc_stat.utime - requested_pids[i].u_time_jiffies;
                requested_pids[i].u_time_jiffies = proc_stat.utime;
                u_time_diff_load = (u_time_diff_jiffies*255) / elapsed_time_ms;

                s_time_diff_jiffies = proc_stat.stimev - requested_pids[i].s_time_jiffies;
                requested_pids[i].s_time_jiffies = proc_stat.stimev;
                s_time_diff_load = (s_time_diff_jiffies*255) / elapsed_time_ms;

                MY_TRACE("vmf sysinfo thread: PID=%d -- name=%s -- u_time_diff_jiffies=%d -- s_time_diff_jiffies=%d \n", (int)(proc_stat.pid), proc_stat.name , (int)(u_time_diff_jiffies), (int)(s_time_diff_jiffies));
                MY_TRACE("vmf sysinfo thread: PID=%d -- name=%s -- u_time_diff_load=%d -- s_time_diff_load=%d \n", (int)(proc_stat.pid), proc_stat.name , (int)(u_time_diff_load), (int)(s_time_diff_load));

                sysinfo_load.load[i-num_dead].pid       = pid;
                sysinfo_load.load[i-num_dead].cpu_num   = 0;
                sysinfo_load.load[i-num_dead].s_time    = s_time_diff_load;
                sysinfo_load.load[i-num_dead].u_time    = u_time_diff_load;
                sysinfo_load.load[i-num_dead].io_time   = 0;
                sysinfo_load.load[i-num_dead].irq_time  = 0;
                sysinfo_load.load[i-num_dead].sirq_time = 0;
            }
            else
            {
                /* process just died */
                procs_alive[i]=false;       /* do not check this process in the future */
                num_dead++;
                MY_TRACE("process died pid%d i=%d\n",pid,i);
            }
        }
        else
        {
            MY_TRACE("irgnore pid%d i=%d\n",pid,i);
            num_dead++;
        }
    }

    sysinfo_load.num_loads = num_cpus + requested_pids_count - num_dead;

    if ((sysinfo_load.num_loads > 0) && (false == new_pid_name_request))
    {
        ret_val = vmf_sysinfo_send_load_resp(my_cid,&sysinfo_load);
        delay(1);
    }
    else
    {
        new_pid_name_request = false;
    }

    return ret_val;
}



/*****************************************************************************
 *
 *   Function Name: GetElapsedTime(uint64_t start_time,uint64_t stop_time)
 *
 *   Description:   calculate time diff in ms
 *
 *   Parameters:    start and stop time in ms
 *
 *   Function Return value: - time in msec
 *
 ******************************************************************************/
static unsigned32 GetElapsedTime(unsigned64 start_time,unsigned64 stop_time)
{
    unsigned32  usTime;

    usTime= stop_time-start_time;

    return (usTime);
}

 /**************************************************************************//**
 *
 *   Function Name: vmf_sysinfo_get_proc_stat
 *
 *   Description:   get process infos from /proc/[pid]/stat
 *
 *   \param[in]     void
 *
 *   Function Return value: - VMF_OK if OK else error
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_get_proc_stat(pid_t pid, vmf_sysinfo_proc_stat_t *proc_stat)
{

    int         fd=-1;
    char        ProcFileName[PATH_MAX+1];
    vmf_ret_t   vmf_ret=VMF_OK;
    procfs_info info;
    struct
    {
        procfs_debuginfo        info;
        char                    buff [PATH_MAX];
    } name;

    memset(&info,0,sizeof(procfs_info));
    (void) sprintf(ProcFileName, "%s/%d/as", PROC_BASE, pid);
    fd = open(ProcFileName,O_RDONLY);

    MY_TRACE("vmf_sysinfo_get_proc_stat: open %s\n",ProcFileName);

    if (fd >= 0)
    {
        /* get system information */
        if (devctl (fd, DCMD_PROC_INFO, &info, sizeof (info), NULL) != EOK)
        {
            MY_TRACE("vmf_sysinfo_get_proc_stat: Error in devctl(DCMD_PROC_INFO) call. %s\n",ProcFileName );
            (void) close(fd);
            return VMF_ERROR;
        }
        else
        {
            if ( devctl (fd, DCMD_PROC_MAPDEBUG_BASE,  &name, sizeof (name), 0) != EOK)
            {
                MY_TRACE("vmf_sysinfo_get_proc_stat: Error in devctl(DCMD_PROC_MAPDEBUG_BASE) call. %s\n",ProcFileName );
                (void) close(fd);
                return VMF_ERROR;
            }

            proc_stat->pid        = info.pid;
            proc_stat->ppid       = info.parent;
            nw_os_sstrncpy(proc_stat->name, name.info.path, PATH_MAX);
            proc_stat->Threads    = info.num_threads;
            proc_stat->sid        = info.sid;
            proc_stat->start_time = info.start_time/MILLION;   /* calc all times in ms */
            proc_stat->utime      = info.utime/MILLION;
            proc_stat->cutime     = info.cutime/MILLION;
            proc_stat->cstime     = info.cstime/MILLION;
            proc_stat->stimev     = info.stime/MILLION;
            proc_stat->priority   = info.priority;
            proc_stat->pgid       = info.gid;
            proc_stat->flags      = info.flags;
            proc_stat->running_time = (nw_os_cfg_get_ns_time()-info.start_time)/MILLION;

            proc_stat->min_flt    = 0;
            proc_stat->cmin_flt   = 0;
            proc_stat->maj_flt    = 0;
            proc_stat->cmaj_flt   = 0;
            proc_stat->it_real_value=0;

            proc_stat->VmSize     = 0;
            proc_stat->rsslim     = 0;
            proc_stat->start_code = 0;
            proc_stat->end_code   = 0;
            proc_stat->VmRSS      = (unsigned32)procfs_get_mem_size(pid, MEM_ALL) / 1024;
        }

#if defined (__LINUX__) || defined (__ANDROID__)

        /* check if this thread is a Kernel thread and mark if yes */
        if ((proc_stat->start_code == 0) && (proc_stat->end_code == 0))
        {
            proc_stat->state = KERNEL_THREAD_STATE;
        }
#endif
        (void) close(fd);
    }
    else
    {
        /* process does not exist anymore */
        #if 0
        MY_ERROR("vmf_sysinfo_get_proc_stat(): fopen(%s) failed\n",ProcFileName);
        #endif
        vmf_ret=VMF_ERROR;
    }

    return (vmf_ret);
}



 /**************************************************************************//**
 *
 *   Function Name: vmf_sysinfo_send_process_name
 *
 *   Description:   get process infos and forward it to VMF
 *
 *
 *   \param[in]     void
 *
 *   Function Return value: - VMF_OK if OK else error
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_send_process_name(pid_t pid)
{
    int fd = -1;
    char ProcFileName[STRING_LENGTH+1];
    vmf_sysinfo_pid_name_resp_pl_t  vmf_resp;
    vmf_ret_t vmf_ret;
    procfs_info info;

    struct {
        procfs_debuginfo        info;
        char                    buff [PATH_MAX];
    } name;

    MY_TRACE("vmf_sysinfo_send_process_name(%d)\n",pid);

    vmf_resp.pid = pid;
    memset(&info,0,sizeof(procfs_info));

    (void) sprintf(ProcFileName, "%s/%d/as", PROC_BASE, pid);
    fd = open(ProcFileName,O_RDONLY);
    if (fd >= 0)
    {
        vmf_resp.ppid = -1;
        vmf_resp.VmRSS = 0;
        vmf_resp.VmSize = 0;
        vmf_resp.name[0] = 0;
        vmf_resp.state = ' ';
        vmf_resp.MemTotal = mem_total;


        if ( devctl (fd, DCMD_PROC_MAPDEBUG_BASE,  &name, sizeof (name), 0) != EOK)
        {
            MY_TRACE("vmf_sysinfo_get_proc_stat: Error in devctl(DCMD_PROC_MAPDEBUG_BASE) call. %s\n",ProcFileName );
            (void) close(fd);
            return VMF_ERROR;
        }

        if   ( devctl (fd, DCMD_PROC_INFO, &info, sizeof (info), NULL) != EOK)
        {
            MY_TRACE("vmf_sysinfo_get_proc_stat: Error in devctl(DCMD_PROC_INFO) call. %s\n",ProcFileName );
            (void) close(fd);
            return VMF_ERROR;
        }

        nw_os_sstrncpy(vmf_resp.name, name.info.path, STRING_LENGTH);

        vmf_resp.Threads = info.num_threads;
        vmf_resp.ppid = info.parent;
#if 0
        vmf_resp.VmSize =
        vmf_resp.VmRSS =
        vmf_resp.state =
#endif
        vmf_resp.version = SYSINFO_PID_NAME_RESP_VERSION;

        /* forward information to Tracer */
        vmf_ret = vmf_sysinfo_send_name_resp(my_cid,&vmf_resp);
        if (VMF_OK != vmf_ret)
        {
            MY_ERROR("vmf_sysinfo_send_process_name(): vmf_sysinfo_send_name_resp() failed\n");
        }
        (void) close(fd);
    }
    else
    {
        MY_ERROR("vmf_sysinfo_send_process_name(): open(%s) failed\n",ProcFileName);
    }
    return VMF_OK;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_gettimesinceboot
 *
 *   Description:   get time in jiffies since system booted
 *
 *   \param[in]     void
 *
 *   Function Return value: - Vtime in jiffies
 *
 ******************************************************************************/
static long vmf_gettimesinceboot(void)
{

    timesinceboot = 0;
    return (timesinceboot);
}



/**************************************************************************//**
 *
 *   Function Name: procfs_get_process_mapinfo
 *
 *   Description:   get mapinfo of process
 *                  taken from QNX procfs_util.c
 *
 *   \param[in]     void
 *
 *   Function Return value: - Vtime in jiffies
 *
 ******************************************************************************/
static int procfs_get_process_mapinfo(int fd, procfs_mapinfo ** mapinfo_pp)
{
    procfs_mapinfo  *mem = NULL;
    int         num, new_num;
    int                 iterations;

    if ( (devctl(fd, DCMD_PROC_MAPINFO, NULL, 0, &num) < 0) || num <= 0)
    {
        *mapinfo_pp = NULL;
        return -1;
    }

   /*
    * alloc space for 5 more blocks, this will help incase process made
    * more memory allocations after the last devctl call.
    */
    num += 5;
    mem = malloc(num * sizeof(procfs_mapinfo));
    if (NULL == mem)
    {
        *mapinfo_pp = mem;
        return -1;
    }

    for (new_num = num + 1, iterations = 0; new_num > num && iterations < MAX_ATTEMPTS; iterations++)
    {
        if (devctl(fd, DCMD_PROC_MAPINFO, mem, num * sizeof(procfs_mapinfo), &new_num) < 0)
        {
            free(mem);
            mem = NULL;
            new_num = -1;
            break;
        }
        else if (new_num > num)
        {
            num = new_num + 5;
            mem = realloc(mem, num * sizeof(procfs_mapinfo));
            if (!mem) {
                new_num = -1;
                break;
            }
        }
    }

    if (iterations == MAX_ATTEMPTS) {
        /*
         * something wrong we are taking too many attempts to get the info
         * about this process, return error.
         */
        free(mem);
        mem = NULL;
        new_num = -1;
    }

    *mapinfo_pp = mem;

    return(new_num);
}


/**************************************************************************//**
 *
 *   Function Name: classify_block
 *
 *   Description:   Return a simplified classification (TYPE_*) for this memory map block.
 *                  taken from QNX showmem project
 *
 *   \param[in]     procfs_mapinfo structure
 *
 *   Function Return value: - memory type
 *
 ******************************************************************************/
static int classify_block(procfs_mapinfo *map)
{
    int flags = map->flags;
    int map_type;

    if(IS_STACK(flags))
    {
    	map_type = TYPE_STACK;
    }
    else if(IS_ELF_CODE(flags))
    {
    	map_type = TYPE_CODE;
    }
    else if(IS_ELF_SHARED_DATA(flags))
    {
    	map_type = TYPE_UNKNOWN; /* temp kludge until we figure out what to do */
    }
    else if(IS_ELF_DATA(flags))
    {
    	map_type = TYPE_DATA;
    }
    else if(IS_GENERIC_HEAP(flags))
    {
    	map_type = TYPE_HEAP;
    }
    else
    {
    	map_type = TYPE_UNKNOWN;
    }

    return map_type;
}


/**************************************************************************//**
 *
 *   Function Name: procfs_get_mem_size
 *
 *   Description:   get used memory size of a project
 *
 *   \param[in]     pid and type of memory that is requested
 *
 *   Function Return value: - Vtime in jiffies
 *
 ******************************************************************************/
static size_t procfs_get_mem_size(int pid, int mtype)
{
    int             fd=0;
    int             i=0;
    int             num=0;
    int             type;
    char            buff[50];
    uint64_t        totals[TYPE_MAX]={0};
    procfs_mapinfo *mem;

    (void) snprintf(buff, sizeof(buff) - 1, "/proc/%d", pid);
    if ((fd = open(buff, O_RDONLY)) == -1)
    {
        return -1;
    }

    num = procfs_get_process_mapinfo(fd, &mem);
    if (num == -1)
    {
        (void) close(fd);
        return -1;
    }

    /* collect all system load and store them into the totals array */
    for(i = 0; i < num; i++)
    {
        if(!IS_RAM_CONSUMING(mem[i].flags)) {
            continue;
        }

        type = classify_block(&mem[i]);
        totals[type] += mem[i].size;
    }
#if 0
    MY_TRACE2("\nprocfs_get_mem_size(%d)\n",pid);
    for (i=0;i<TYPE_MAX;i++)
    {
        MY_TRACE2("totals[%d]=%ld\n",i,(long int)totals[i]);
    }
#endif
    (void) close(fd);
    free(mem);

    switch (mtype)
    {
        case MEM_TEXT:
            return totals[TYPE_CODE];
        case MEM_DATA:
            return totals[TYPE_DATA];
        case MEM_STACK:
            return totals[TYPE_STACK];
        case MEM_DYNAMIC:
            return totals[TYPE_HEAP];
        case MEM_DLL:
            return 0;
        case MEM_SHARED:
            return totals[TYPE_ELF_SHARED_DATA];
        case MEM_DEVICE:
            return 0;
        case MEM_MAP_SHARED:
            return 0;
        case MEM_ALL:
            return (totals[TYPE_DATA] + totals[TYPE_HEAP]); //+ totals[TYPE_STACK]);
    }

    return -1;
}


#endif  /* #ifdef __QNX__ */
#endif  /* #ifndef DISABLE_SYSINFO */

#undef _VMF_SYSINFO_C
