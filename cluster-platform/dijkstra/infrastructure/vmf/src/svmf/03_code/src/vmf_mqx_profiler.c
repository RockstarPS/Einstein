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

  \file                 vmf_mqx_profiler.c
  \brief                VMF mqx profiler functions

  \author               Joachim Becker
  \author               Visteon Deutschland GmbH, Infotainment Software

  compiler              iar
  target                mqx

  *****************************************************************************/
#define __NW_VMF_MQX__PROFILER_C__


#include "vmf.h"
#include "vmf_mqx_profiler.h"

//#if ( VMF_CORE == VS_MICRO_CORE )

#define MY_TRACE(...)
#define MY_ERROR(...)

#define VMF_SYSINFO_TIME_INVALID    (10000)
#define VMF_SYSINFO_TRANSFER_DELAY  (10)                                    /* transfer delay in ms */

/* static data */
static VMF_RTA_PROFILE_INFO_STRUCT  *vmf_rta_ptr = NULL;

static vmf_profiler_stat_t          proc_stat={0};
static unsigned16                   num_cpus=1;
static unsigned16                   requested_pids_count=0;
static unsigned16                   int_time=VMF_SYSINFO_TIME_INVALID;      /* integration time in ms */
static proc_sys_info_t              requested_pids[MAX_PIDS]={0};
static BOOL                         procs_alive[MAX_PIDS];
static BOOL                         new_pid_name_request=FALSE;
static BOOL                         load_timer_running = FALSE;
static vmf_cid_t                    tx_cid=0;
static KERNEL_DATA_STRUCT_PTR       kernel_data_ptr = NULL;

static INT_ISR_FPTR                 org_old_isr=NULL;
static pointer                      org_old_isr_data=NULL;

/* initial mips = MHz for diagram scaling */
#if ( VS_MICRO_CORE_M4 == VS_MICRO_CORE )
static unsigned16                   curr_mips=VMF_PROFILER_M4_CLK;
#else
static unsigned16                   curr_mips=VMF_PROFILER_A5_CLK;
#endif

#define TIMER_TASL_IX 1
#define TIMER_TASK_STACK    1000
#define TIMER_TASK_PRIO     8
#define TIMER_TASK_NAME     "sysinfo_task"
#define TIMER_DEFAULT_TASK_PRIORITY 2

/* share memory */
#pragma language = extended
#pragma location = ".shared_ram"
#pragma segment  = ".shared_ram"
VMF_RTA_PROFILE_INFO_STRUCT  vmf_rta_a5 @ ".shared_ram" ={0};
VMF_RTA_PROFILE_INFO_STRUCT  vmf_rta_m4 @ ".shared_ram" ={0};



#if 0
const TASK_TEMPLATE_STRUCT MQX_template_list[] =
{
    /* Task Index, Function, Stack, Priority, Name, Attributes, Param, Time Slice */
    { TIMER_TASL_IX, load_timer_task, TIMER_TASK_STACK, TIMER_TASK_PRIO, "Main", MQX_AUTO_START_TASK, 0, 0},
    { 0 }
};
#endif

#define NON_OSAL_TASKS      10
#define NUM_OSAL_TASK       (NUM_TASKS + MAX_DYNAMIC + NON_OSAL_TASKS)
extern os_task_control_t    os_task_list[];             /* osal profile data */

/* local functions */
static void         vmf_profiler_isr(void * isr_data);
static inline void  vmf_mqx_profiler_clock(VMF_RTA_PROFILE_INFO_STRUCT *isr_data);
static unsigned32   vmf_profiler_update_task_info(vmf_profiler_stat_t *p_proc_stat);
static vmf_ret_t    vmf_sysinfo_send_name_resp(vmf_cid_t cid,vmf_sysinfo_pid_name_resp_pl_t *vmf_sysinfo_pid_name_resp);
static void         vmf_load_timer_task(void *param);
static vmf_ret_t    vmf_sysinfo_start_load_timer(unsigned16 int_time);
static vmf_ret_t    vmf_sysinfo_calculate_and_send_process_load(unsigned16 ms_time);
static vmf_ret_t    vmf_sysinfo_send_load_resp(vmf_client_id_t cid,vmf_sysinfo_load_resp_v2_pl_t *p_sysinfo_load);
static unsigned16   vmf_profiler_get_stack_usage(TD_STRUCT_PTR td_ptr, unsigned32 *total_stack, unsigned32 *used_stack);
static unsigned16   vmf_sysinfo_measure_curr_mips(void);

/********************************************************
 global functions
 ********************************************************/

/**************************************************************************//**
 *
 *   Function Name: vmf_profiler_install()
 *
 *   Description:   chains/ unchains the profiler isr to the kernel timer isr
 *                  start profiler timer
 *   Parameters:
 *
 *   \param[in]     time    - time in ms or 0 to disarm profiler

 *   \return        resulution    time resolution in ticks per second
 *                                or VMF_MQX_PROF_ERROR if mnalloc error
 ******************************************************************************/
unsigned32 vmf_profiler_install(unsigned16 ms_time)
{
    static  bool            isr_installed=FALSE;
    KERNEL_DATA_STRUCT_PTR  kernel_data;
    unsigned32              timer_vector;
    unsigned16              ticks_ps=0;
    unsigned16              int_rate_ms = 0;

    int_time = ms_time;
    _GET_KERNEL_DATA(kernel_data);
    if (int_time > 0)
    {
        /* enable profiling */
        if (vmf_rta_ptr == NULL)
        {
            #if VMF_CORE == VS_MICRO_CORE_M4
            vmf_rta_ptr = &vmf_rta_m4;
            #else
            vmf_rta_ptr = &vmf_rta_a5;
            #endif

            vmf_rta_ptr->kernel_data = kernel_data;
            #if ( VS_MICRO_CORE_M4 == VS_MICRO_CORE )
            timer_vector = systick_get_vector();
            #else
            timer_vector = gtim_get_vector();   // BSP_TIMER_INTERRUPT_VECTOR; // kernel_data->SYSTEM_CLOCK_INT_NUMBER;
            #endif
            vmf_rta_ptr->timer_isr_vector = timer_vector;

            /* store original mqx timer isr and isr data */
            vmf_rta_ptr->OLD_ISR_DATA = _int_get_isr_data(timer_vector);
            vmf_rta_ptr->OLD_ISR =      _int_install_isr(timer_vector, vmf_profiler_isr, kernel_data);
            if (NULL == org_old_isr)
            {
                /* store oly once */
                org_old_isr                 = vmf_rta_ptr->OLD_ISR;
                org_old_isr_data            = vmf_rta_ptr->OLD_ISR_DATA;
            }
        }

        if (FALSE == isr_installed)
        {
            volatile INT_ISR_FPTR   org_isr;    /* debug */
            /* chain isr */
            org_isr = _int_install_isr(vmf_rta_ptr->timer_isr_vector, vmf_profiler_isr, vmf_rta_ptr);
            isr_installed = TRUE;
        }

        vmf_rta_ptr->PROFILING_ACTIVE = TRUE;
        ticks_ps = kernel_data->TICKS_PER_SECOND;
        vmf_rta_ptr->profile_data.ticks_ps = ticks_ps;
        int_rate_ms = 1000 / ticks_ps;
        vmf_rta_ptr->profile_data.ticks_ps = ticks_ps;
        vmf_rta_ptr->profile_data.int_rate_ms = int_rate_ms;
        vmf_rta_ptr->profile_data.mips = curr_mips;
    }
    else /* int_time == 0 */
    {
        /* disable profiling */
        #if 0
        /* unchain isr */
        if (vmf_rta_ptr != NULL)
        {
            timer_vector = vmf_rta_ptr->timer_isr_vector ;
            _int_install_isr(timer_vector, org_old_isr, org_old_isr_data);

            _mem_free(vmf_rta_ptr);
            vmf_rta_ptr = NULL;
            isr_installed = FALSE;
        }
        #endif
        vmf_rta_ptr->PROFILING_ACTIVE = FALSE;
        vmf_rta_ptr->profile_data.ticks_ps = 0;
        vmf_rta_ptr->profile_data.int_rate_ms = 0;
        vmf_rta_ptr->profile_data.mips = 0;
    }

    vmf_sysinfo_start_load_timer(int_time);

    return ticks_ps;
}



 /**************************************************************************//**
 *
 *   Function Name: vmf_sysinfo_send_all_process_names
 *
 *   Description:   get list of running processes and forward it to VMF
 *
 *   \param[in]     client-id
 *
 *   Function Return value: - VMF_OK if OK else error
 *
 ******************************************************************************/
vmf_ret_t vmf_sysinfo_send_all_process_names(vmf_client_id_t cid)
{
    vmf_ret_t vmf_ret;
    unsigned32 task_num;
    unsigned32 num;
    unsigned32 tasks_send;

    MY_TRACE("vmf_sysinfo_send_all_process_names()\n");

    tx_cid = cid;
    task_num = vmf_profiler_update_task_info(&proc_stat);
    for (num =0,tasks_send=0; num<VMF_PROFILER_MAX_TASK_NUM; num++)
    {
        if (proc_stat.tasks[num].pid != 0)
        {
            vmf_ret = vmf_sysinfo_send_process_name(cid, num);
            if (VMF_OK != vmf_ret)
            {
                MY_ERROR("vmf_sysinfo_send_all_process_names(): vmf_sysinfo_send_process_name() failed\n");
                //nw_sleep_ms(VMF_SYSINFO_TRANSFER_DELAY);       /* wait some time to prevent queue flooding */
            }
            else
            {
                /* no code */
                //nw_sleep_ms(VMF_SYSINFO_TRANSFER_DELAY);       /* wait some time to prevent queue flooding */
            }
            tasks_send++;
        }
        if (tasks_send>=task_num)
        {
            break;
        }
    }

    return VMF_OK;
}


  /**************************************************************************//**
 *
 *   Function Name: vmf_sysinfo_send_updated_process_names
 *
 *   Description:   update task-info of all tasks
 *
 *   \param[in]     void
 *
 *   Function Return value: - VMF_OK if OK else error
 *
 ******************************************************************************/
vmf_ret_t vmf_sysinfo_send_updated_process_names(vmf_client_id_t cid)
{
    vmf_ret_t vmf_ret;
    unsigned32 task_num;
    unsigned32 num;
    unsigned32 tasks_send;

    MY_TRACE("vmf_sysinfo_send_all_process_names()\n");

    tx_cid = cid;
    task_num = vmf_profiler_update_task_info(&proc_stat);
    for (num =0,tasks_send=0; num<VMF_PROFILER_MAX_TASK_NUM; num++)
    {
        if ((proc_stat.tasks[num].pid != 0) && (proc_stat.tasks[num].num_send==0))
        {
            vmf_ret = vmf_sysinfo_send_process_name(cid, num);
            if (VMF_OK != vmf_ret)
            {
                MY_ERROR("vmf_sysinfo_send_all_process_names(): vmf_sysinfo_send_process_name() failed\n");
            }
            else
            {
                /* no code */
            }
            tasks_send++;
        }
        if (tasks_send>=task_num)
        {
            break;
        }
    }

    return VMF_OK;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_sysinfo_measure_curr_mips
 *
 *   Description:   measure the current mips
 *
 *   \param[in]     void
 *
 *   Function Return value: - VMF_OK if OK else error
 *
 ******************************************************************************/
static unsigned16 vmf_sysinfo_measure_curr_mips(void)
{
    int i;
    unsigned16  start;
    unsigned16  stop;

    asm("CPSID I");
    start = _time_get_microseconds();
    for (i=0;i<1000;i++);       /* the inner loop will take  cycles */
    stop = _time_get_microseconds();
    asm("CPSIE I");

    if (stop > start)
    {
            curr_mips = 4000/(stop-start);
    }
    else
    {
            stop+=4096;
    }
    curr_mips = 4000/(stop-start);
    return curr_mips;
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
vmf_ret_t vmf_sysinfo_send_process_name(vmf_cid_t my_cid, pid_t pid)
{
    int len;
    vmf_ret_t                   vmf_ret=VMF_OK;
    vmf_profiler_stat_t         *p_proc_stat;
    TD_STRUCT_PTR               td_ptr=NULL;
    vmf_sysinfo_pid_name_resp_pl_t  vmf_resp={0};

    if (pid > VMF_PROFILER_MAX_TASK_NUM)
    {
        return VMF_ERR_INVALID_ARG;
    }
    if (NULL == kernel_data_ptr)
    {
        kernel_data_ptr = _mqx_get_kernel_data ();
    }

    tx_cid = my_cid;
    p_proc_stat = &proc_stat;
    {
        unsigned32  total_stack=0;
        unsigned32  used_stack=0;
        unsigned16  per_cent=0;

        vmf_resp.MemTotal = 0;
        vmf_resp.pid = (unsigned32)pid;

        /* get stack usage */
        td_ptr = _task_get_td(p_proc_stat->tasks[pid].task_id);
        per_cent = vmf_profiler_get_stack_usage(td_ptr,&total_stack, &used_stack);

        /* get task-name */
        snprintf(vmf_resp.name,NAME_LEN_MAX,"%s %s",CPU_NAME,p_proc_stat->tasks[pid].name);
        len=strlen(vmf_resp.name);
        vmf_resp.name[len]=0;

        if (1 == pid)
        {
            vmf_resp.state    = ST_KERNEL;
        }
        else
        {
            vmf_resp.state    = ST_STD;
        }
        vmf_resp.ppid     = 0;
        vmf_resp.Threads  = 1;
        vmf_resp.VmSize   = total_stack;
        vmf_resp.VmRSS    = per_cent;
        vmf_resp.MemTotal = total_stack;
        vmf_resp.stime    = 0;
        if (vmf_rta_ptr->profile_data.ticks_ps > 0)
        {
            vmf_resp.utime = vmf_rta_ptr->profile_data.task_ticks[pid] * vmf_rta_ptr->profile_data.int_rate_ms;
        }
        else
        {
            vmf_resp.utime  = 0;
        }


        vmf_resp.rtime  = (unsigned32)nw_vmf_ipc_get_ms_time();

        /* forward information to tracer-frontend */
        vmf_ret = vmf_sysinfo_send_name_resp(my_cid,&vmf_resp);
        if (VMF_OK != vmf_ret)
        {
            MY_ERROR("vmf_sysinfo_send_process_name_2(): vmf_sysinfo_send_name_resp() failed\n");
        }
        else
        {
            p_proc_stat->tasks[pid].num_send++;
        }
    }
    return (vmf_ret);
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
vmf_ret_t vmf_sysinfo_get_requested_pids (unsigned8 *payload)
{
    vmf_ret_t   vmf_ret = VMF_OK;
    unsigned16  i;
    unsigned16  offset;
    vmf_sysinfo_pidlist_t   *p_pid_list;

    if (NULL == payload)
    {
        requested_pids_count = 0;
        new_pid_name_request = true;
        return VMF_OK;
    }

    p_pid_list = (vmf_sysinfo_pidlist_t*)payload;

    /* Byte 0..1 == PID count */
    requested_pids_count = (unsigned16)payload[0] + (unsigned16)(payload[1] << 8); /* little endian */
    if (requested_pids_count > MAX_PIDS)
    {
        MY_TRACE("vmf_sysinfo_get_requested_pids: pid count (=%d) too big... pl[0]=%d -- pl[1]=%d !!!\n", requested_pids_count, payload[0], payload[1]);
        requested_pids_count = 0;
        return VMF_ERROR;
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







/********************************************************
 local functions
 ********************************************************/



 /*************************************************************************//**
 *
 *   vmf_sysinfo_calculate_and_send_process_load
 *   get process load of requested processes and transfer it to frontend
 *
 *   \param[in] total used CPU tim in ms
 *   \return    void
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_calculate_and_send_process_load(unsigned16 ms_time)
{
    // #define VMF_SYSINFO_PL_CHECK_ALIVE
    vmf_ret_t       ret_val = VMF_OK;
    unsigned16      i=0;
    unsigned16      num_dead=0;                         /* number of dead processes */
    unsigned32      u_time_diff_jiffies;
    unsigned32      u_time_diff_load;
    unsigned32      s_time_diff_jiffies;
    unsigned32      s_time_diff_load;
    unsigned32      pid;
    unsigned8       cpu=0;
    unsigned32      idle_ticks=0;
    unsigned32      load;
    unsigned16      mips;
    vmf_sysinfo_load_resp_v2_pl_t   sysinfo_load; // ={0};

    sysinfo_load.num_loads = 0;
    if (NULL == vmf_rta_ptr)
    {
        return VMF_ERROR;
    }

    idle_ticks = vmf_rta_ptr->profile_data.task_ticks[VMF_IDLE_TASK] - vmf_rta_ptr->profile_data.old_idle_ticks;
    load = (idle_ticks * vmf_rta_ptr->profile_data.int_rate_ms * 255)/ms_time;
    vmf_rta_ptr->profile_data.old_idle_ticks = vmf_rta_ptr->profile_data.task_ticks[VMF_IDLE_TASK];
    if (load > 255)
    {
        load = 255;
    }
    /* calculate core load */
    sysinfo_load.load[cpu].pid      = 0;  /* system load = CPU 0 */
    sysinfo_load.load[cpu].cpu_num  = cpu;
    sysinfo_load.load[cpu].s_time   = 0;
    sysinfo_load.load[cpu].u_time   = (unsigned8) (255-load);   /* core load = 255 - idle-load */
    sysinfo_load.load[cpu].io_time  = 0;
    sysinfo_load.load[cpu].irq_time = 0;
    sysinfo_load.load[cpu].sirq_time= 0;
    sysinfo_load.load[cpu].mips_l   = 0;
    sysinfo_load.load[cpu].mips_h   = 0;
    sysinfo_load.num_loads++;


    /* calculate cpu loads of the requested pids */
    for (i=num_cpus; i<(requested_pids_count+num_cpus); i++)
    {
        /* check if process is alive */
#ifdef VMF_SYSINFO_PL_CHECK_ALIVE
        if (procs_alive[i]!=false)
#endif
        {
            pid = requested_pids[i].pid;
            if (pid <= VMF_PROFILER_MAX_TASK_NUM)
            {
                unsigned32 tmp;

                tmp = (vmf_rta_ptr->profile_data.task_ticks[pid] - vmf_rta_ptr->profile_data.old_task_ticks[pid]);
                vmf_rta_ptr->profile_data.old_task_ticks[pid] = vmf_rta_ptr->profile_data.task_ticks[pid] ;
                u_time_diff_load = (tmp * vmf_rta_ptr->profile_data.int_rate_ms * 255)/ms_time;

                sysinfo_load.load[i-num_dead].pid       = pid;
                sysinfo_load.load[i-num_dead].cpu_num   = 0;
                sysinfo_load.load[i-num_dead].s_time    = 0;
                sysinfo_load.load[i-num_dead].u_time    = u_time_diff_load;
                sysinfo_load.load[i-num_dead].io_time   = 0;
                sysinfo_load.load[i-num_dead].irq_time  = 0;
                sysinfo_load.load[i-num_dead].sirq_time = 0;
                sysinfo_load.load[i-num_dead].mips_l    = 0;
                sysinfo_load.load[i-num_dead].mips_h    = 0;
            }
        }
#ifdef VMF_SYSINFO_PL_CHECK_ALIVE
        else
        {
            MY_TRACE("irgnore pid%d i=%d\n",pid,i);
            num_dead++;
        }
#endif
    }

    mips = vmf_rta_ptr->profile_data.mips;
    sysinfo_load.num_loads = num_cpus + requested_pids_count;
    sysinfo_load.cpu_frq_l = (unsigned8)(mips & 0xff);
    sysinfo_load.cpu_frq_h = (unsigned8)((mips >> 8) & 0xff);
    sysinfo_load.version   = SYSINFO_LOAD_RESP_VERSION_1;

    if ((sysinfo_load.num_loads > 0) && (false == new_pid_name_request))
    {
        ret_val = vmf_sysinfo_send_load_resp(tx_cid,&sysinfo_load);
    }
    else
    {
        new_pid_name_request = false;
    }

    /* measure current mips */
    vmf_rta_ptr->profile_data.mips = vmf_sysinfo_measure_curr_mips();
    return ret_val;
}




/**************************************************************************//**
 *
 *   Function Name: vmf_profiler_update_task_info()
 *
 *   Description:   add all processes to proc_stat
 *
 *   Parameters:
 *
 *   \param[in]     pointer to proc_stat

 *   \return        number of tasks
 ******************************************************************************/

static unsigned32 vmf_profiler_update_task_info(vmf_profiler_stat_t *p_proc_stat)
{
    char                        name[12];
    unsigned32                  qsize=0;
    TD_STRUCT_PTR               td_ptr;
    TASK_TEMPLATE_STRUCT_PTR    template_ptr;
    char *                      task_name;

    if (NULL == kernel_data_ptr)
    {
        kernel_data_ptr = _mqx_get_kernel_data ();
    }

    qsize = _QUEUE_GET_SIZE(&kernel_data_ptr->TD_LIST);
    td_ptr = (TD_STRUCT_PTR)((uchar_ptr)kernel_data_ptr->TD_LIST.NEXT - FIELD_OFFSET(TD_STRUCT,TD_LIST_INFO));
    p_proc_stat->num_tasks=0;

    /* get all task names */
    while ((0 != qsize) && (NULL != td_ptr))
    {
        unsigned32  current_task=0;
        unsigned32  state=0;

        current_task = (td_ptr->TASK_ID) & 0xffff;
        state = td_ptr->STATE;
        if (current_task != 0)
        {
            #if MQX_TD_HAS_TASK_TEMPLATE_PTR
            template_ptr = td_ptr->TASK_TEMPLATE_PTR;
            if (NULL == template_ptr)
            {
                break;
            }
            task_name = template_ptr->TASK_NAME;
            #else
            snprintf(name,sizeof(name),"0x%x", current_task);
            task_name = name;
            #endif

            if (current_task < VMF_PROFILER_MAX_TASK)
            {
                vmf_profiler_task_stat_t    *task;

                task = &(p_proc_stat->tasks[current_task]);
                task->pid = current_task;
                task->task_id = td_ptr->TASK_ID;
                task->state = state;
                task->utime = vmf_rta_ptr->profile_data.old_task_ticks[current_task];
                strncpy(task->name,task_name,NAME_LEN_MAX);
                p_proc_stat->num_tasks++;
            }
        }
        else
        {
            break;
        }
        td_ptr = (TD_STRUCT_PTR)((uchar_ptr)(td_ptr->TD_LIST_INFO.NEXT) - FIELD_OFFSET(TD_STRUCT,TD_LIST_INFO));
    }
    return p_proc_stat->num_tasks;
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
static vmf_ret_t vmf_sysinfo_send_name_resp(vmf_client_id_t cid, vmf_sysinfo_pid_name_resp_pl_t *vmf_sysinfo_pid_name_resp)
{
    vmf_ret_t vmf_ret;

    VMF_VAR_MSG_TYP(sizeof(vmf_sysinfo_pid_name_resp_pl_t)) vmf_basic_msg;

    /* prepare payload*/
    NW_VMF_BASIC_MSG_GROUP(&vmf_basic_msg) = VMF_TRACE_SYSINFO_DATA;
    NW_VMF_BASIC_MSG_EVENT(&vmf_basic_msg) = VMF_SYSINFO_DATA_PROFILER_PID_NAME_RESP;
    NW_VMF_BASIC_MSG_DATA_LENGTH(&vmf_basic_msg) = sizeof(vmf_sysinfo_pid_name_resp_pl_t)- sizeof(vmf_sysinfo_pid_name_resp->name) + strlen(vmf_sysinfo_pid_name_resp->name)+1;
    memcpy(NW_VMF_BASIC_MSG_DATA_PTR(&vmf_basic_msg),vmf_sysinfo_pid_name_resp, NW_VMF_BASIC_MSG_DATA_LENGTH(&vmf_basic_msg));

    /* send data to VMF */
    vmf_ret = nw_vmf_send_basic (cid,(vmf_basic_msg_t*)&vmf_basic_msg);
    if(vmf_ret < 0)
    {
        MY_ERROR("vmf_sysinfo_send_name_resp(): nw_vmf_send_basic() failed");
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
 *   \param[in]     vmf_sysinfo_load_resp_v2_pl_t payload
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_send_load_resp(vmf_client_id_t cid,vmf_sysinfo_load_resp_v2_pl_t *p_sysinfo_load)
{
    vmf_ret_t   vmf_ret=VMF_OK;
//#if ( VS_MICRO_CORE_A5 == VS_MICRO_CORE )
    unsigned16  len;


    VMF_VAR_MSG_TYP(sizeof(vmf_sysinfo_load_resp_v2_pl_t)) vmf_msg;

    NW_VMF_BASIC_MSG_GROUP(&vmf_msg)    = VMF_TRACE_SYSINFO_DATA;
    NW_VMF_BASIC_MSG_EVENT(&vmf_msg)    = VMF_SYSINFO_DATA_PROFILER_LOAD_RESP;

    /* copy payload */
    len = sizeof(vmf_sysinfo_load_resp_v2_pl_t)- (sizeof(load_t) * (VMF_TRACE_LOAD_MAX_LOADS - p_sysinfo_load->num_loads));
    NW_VMF_BASIC_MSG_DATA_LENGTH(&vmf_msg) = len;
    memcpy(NW_VMF_BASIC_MSG_DATA_PTR(&vmf_msg),p_sysinfo_load, len);

    vmf_ret = nw_vmf_send_basic (cid,(vmf_basic_msg_t*)&vmf_msg);
    if(vmf_ret < 0)
    {
        MY_ERROR("vmf_sysinfo_send_load_resp - nw_vmf_send_basic() failed");
    }
//#endif
    return vmf_ret;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_load_timer_task
 *
 *   Description:   cyclic timer for measuring the cpu load
 *
 *   \param[in]
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static void vmf_load_timer_task(void *param)
{
    static unsigned32   old_time=0;
    unsigned32          curr_time=0;

    if (int_time > 0)
    {
        curr_time = nw_vmf_ipc_get_ms_time();
        if (0 == old_time)
        {
            old_time = curr_time-int_time;
        }

        vmf_sysinfo_calculate_and_send_process_load(curr_time - old_time);
        old_time = curr_time;
    }
}



 /**************************************************************************//**
 *
 *   Function Name: vmf_sysinfo_start_load_timer
 *
 *   Description:   start the system load timer
 *
 *   \param[in]
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t vmf_sysinfo_start_load_timer(unsigned16    int_time)
{
    static _timer_id load_timer_id=0;

    if (0 == int_time)
    {
        /* just cancel the timer */
        _timer_cancel(load_timer_id);
        load_timer_running = FALSE;
        return VMF_OK;
    }

    if (TRUE == load_timer_running)
    {
        /* timer already running */
        /* so first cancel old timer */
        _timer_cancel(load_timer_id);
    }

    {
        unsigned32      intervall = int_time;
        #if 0   /* timer-component already created */
        _timer_create_component(TIMER_DEFAULT_TASK_PRIORITY, 1024);
        #endif

        load_timer_id = _timer_start_periodic_every(vmf_load_timer_task, &int_time, TIMER_ELAPSED_TIME_MODE, intervall);

        load_timer_running = TRUE;
    }
}






/********************************************************
 isr functions
 ********************************************************/


/**************************************************************************//**
 *
 *   Function Name: vmf_mqx_profiler_clock()
 *
 *   Description:   profile tasks
 *
 *   Parameters:
 *
 *   \param[in]     void

 *   \return        void
 ******************************************************************************/
static inline void vmf_mqx_profiler_clock(VMF_RTA_PROFILE_INFO_STRUCT *isr_data)
{
    VMF_PROFILE_DATA    *p_profile_data=NULL;
    unsigned32           current_task;

#if 0
    if (NULL == isr_data)
    {
        return;
    }
#endif
    p_profile_data = &(isr_data->profile_data);

    if ( p_profile_data != NULL)
    {
        /* increment ticks of current task */
        current_task = (isr_data->kernel_data->ACTIVE_PTR->TASK_ID) & 0xffff;
        if (current_task < VMF_PROFILER_MAX_TASK)
        {
            isr_data->profile_data.task_ticks[current_task]++;
        }
        else
        {
            isr_data->invalid_ticks++;
        }
    }
}


/**************************************************************************//**
 *
 *   Function Name: vmf_profiler_isr()
 *
 *   Description:   chains/ unchains the profiler isr to the kernel timer isr
 *
 *   Parameters:
 *
 *   \param[in]     pointer to VMF_RTA_PROFILE_INFO_STRUCT

 *   \return        void
 ******************************************************************************/
static void vmf_profiler_isr(void * isr_data)
{
   VMF_RTA_PROFILE_INFO_STRUCT  *rta_ptr = (VMF_RTA_PROFILE_INFO_STRUCT *)isr_data;
    if (rta_ptr != NULL)
    {
        /*  call the vmf-profiler clock function */
#ifndef VMF_PROFILER_MQX_FIRST
        if (rta_ptr->PROFILING_ACTIVE)
        {
            vmf_mqx_profiler_clock(rta_ptr);
        }
#endif

        /* call the original kernel timer isr */
        if (NULL != rta_ptr->OLD_ISR)
        {
            (*org_old_isr)(rta_ptr->OLD_ISR_DATA);
        }

#ifdef VMF_PROFILER_MQX_FIRST
        /* now call the vmf-profiler clock function */
        if (rta_ptr->PROFILING_ACTIVE)
        {
            vmf_mqx_profiler_clock(rta_ptr);
        }
#endif
    }
}

/**************************************************************************//**
 *
 *   Function Name: vmf_profiler_get_stack_usage()
 *
 *   Description:   get stack usage
 *
 *   Parameters:
 *
 *   \param[in]    td-strukt pointer
 *   \param[in]    total stack
 *   \param[in]    used stack
 *   \return       stack usage in %
 ******************************************************************************/
static unsigned16   vmf_profiler_get_stack_usage(TD_STRUCT_PTR td_ptr, unsigned32 *total_stack, unsigned32 *used_stack)
{
    static unsigned16   ret_val =0;
    static unsigned32   ltotal_stack=0;
    static unsigned32   lused_stack=0;
    static _mqx_uint_ptr    pstack_base;
    static _mqx_uint_ptr    pstack_limit;
    static _mqx_uint_ptr    pstack_used;
    static _mqx_uint_ptr    pstack_ptr;

    if (td_ptr != NULL)
    {
        pstack_base  = (_mqx_uint_ptr)td_ptr->STACK_BASE;
        pstack_limit = (_mqx_uint_ptr)td_ptr->STACK_LIMIT;
        pstack_ptr   = (_mqx_uint_ptr)td_ptr->STACK_PTR;

        ltotal_stack = (pstack_base - pstack_limit) * sizeof(void*);
        pstack_used = pstack_ptr;
        pstack_used--;
        while (*pstack_used != 0x7374616B)
        {
            pstack_used--;
#if 1
            if (pstack_used <= td_ptr->STACK_LIMIT)
            {
                break;
            }
#endif
        }

        lused_stack = (pstack_base - pstack_used) * sizeof(void*);
        if (lused_stack >= ltotal_stack)
        {
            lused_stack=ltotal_stack;       /* 100% */
        }
        else
        {
            lused_stack = (pstack_base - pstack_used) * sizeof(void*);
        }
    }

    if (ltotal_stack > 0)
    {
        ret_val = (lused_stack * 100) / ltotal_stack;
    }
    if (total_stack != NULL)
    {
        *total_stack = ltotal_stack;
    }
    if (used_stack != NULL)
    {
        *used_stack = lused_stack;
    }

    return ret_val;
}

//#endif
