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

  \file                 vmf_mcc.c
  \brief                inter core communication

  \author               Joachim Becker
  \author               Visteon Deutschland GmbH, Infotainment Software

  compiler              iar
  target                mqx

  *****************************************************************************/
#define __NW_VMF_MCC_C__

#include "os_if.h"
#include "mqx_osal_if.h"
#include <mcc_config.h>     /* needed for MCC_RESERVED2_SEMAPHORE_NUMBER */
#include <util_micro_regs_vybrid.h>
#include <mfs.h>
#include <mqx_inc.h>
#include <charq.h>
#include <stdlib.h>

#include "vmf.h"
#include "vmf_ipc.h"
#include "vmf_mcc.h"
#include "vmf_mqx_profiler.h"


#define SPIN_LOCK()          {vmf_mcc_soft_lock();}
#define SPIN_UNLOCK()        {vmf_mcc_soft_unlock();}
#define SPIN_LOCK_INIT()     {vmf_mcc_soft_lock_init();}

#define MCC_DI()            _int_disable() // asm("CPSID I")
#define MCC_EI()            _int_enable(); // asm("CPSIE I")

#define MCC_Q_READ_TIMEOUT  (100)           /* mcc q read timeout in ticks */

#if 1
#if ( VS_MICRO_CORE_M4 == VS_MICRO_CORE )
    #define MCC_MQX_NODE MCC_MQX_NODE_M4
#else
    #define MCC_MQX_NODE MCC_MQX_NODE_A5
#endif
#endif

/* local macros */
#if 1
#define VMF_TRACE_SCOPE                 (char *)__FUNCTION__
#define VMF_DEBUG_INFO(scope, ...)      VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO, scope, VMF_TRACE_SCOPE, __VA_ARGS__);
#define VMF_DEBUG_WARNING(scope, ...)   VMF_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_WARNING,scope,VMF_TRACE_SCOPE,__VA_ARGS__);
#define VMF_DEBUG_ERROR(scope, ...)     VMF_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR,scope,VMF_TRACE_SCOPE,__VA_ARGS__);
#else
#define VMF_DEBUG_INFO(scope, ...)
#define VMF_DEBUG_WARNING(scope, ...)
#define VMF_DEBUG_EROR(scope, ...)
#endif

#define EV_MCC_TEST_TMO                 0x01

#ifndef MSCM_IRCP3IR_REG
#define MSCM_IRCP3IR_REG(base)              ((base)->IRCP3IR)
#define MSCM_IRCP3IR                        MSCM_IRCP3IR_REG(MSCM_BASE_PTR)
#endif

/* Field definitions for IRCP1IR */
#ifndef MSCM_IRCP3IR_INT1_MASK
#define MSCM_IRCP3IR_INT1_SHIFT             (3)
#define MSCM_IRCP3IR_INT1_MASK              ((1) << (MSCM_IRCP3IR_INT1_SHIFT))
#endif


/* static variables */
static  unsigned8                           vmf_trid=0;
static  vmf_client_id_t                     mcc_cid=0;
static  MUTEX_STRUCT                        mcc_mux={0};
static  MUTEX_STRUCT                        mcc_write_mux={0};
static  MUTEX_STRUCT                        mcc_read_mux={0};
static  volatile int                        soft_mux=0;
static  bool                                mux_init=FALSE;
static  volatile bool                       mux_lock=FALSE;

/* local functions */
static inline void  vmf_mcc_soft_lock_init  (void);
static inline void  vmf_mcc_soft_lock       (void);
static inline void  vmf_mcc_soft_unlock     (void);



/* shared memory */
#pragma language = extended
#pragma location = ".shared_ram"
#pragma segment  = ".shared_ram"
#define VMF_MCC_POOL_MSG_NUM    25
#define VMF_MCC_CORE_NUM        2
#define VMF_MCC_OTHER_CORE      ((VMF_MCC_CORE_NUM + 1) - VS_MICRO_CORE)
volatile vmf_mcc_msg_t  vmf_mcc_msgs[VMF_MCC_POOL_MSG_NUM]  @ ".shared_ram" = {0};
volatile vmf_mcc_msg_t *vmf_mcc_msg_q[VMF_MCC_POOL_MSG_NUM] @ ".shared_ram" = {0};
volatile vmf_mcc_pool_t vmf_mcc_msg_pool                    @ ".shared_ram" = {0};
volatile int            read_ix                             @ ".shared_ram" = 0;
volatile int            write_ix                            @ ".shared_ram" = 0;
volatile bool           vmf_mcc_lock                        @ ".shared_ram" = FALSE;
volatile int            softtry[VMF_MCC_CORE_NUM+1]         @ ".shared_ram" = {0};
volatile bool           softlock[VMF_MCC_CORE_NUM+1]        @ ".shared_ram" = {0};

#if ( VS_MICRO_CORE_M4 == VS_MICRO_CORE )

/****************************************************************************/
/*                           M4 code                                        */
/****************************************************************************/

/* local function declaration */
void    vmf_mcc_m4_msg_handler           (vmf_msg_t *p_vmf_msg);
static  inline vmf_mcc_trigger_a5_c2c_int(void);

/**************************************************************************//**
 *
 *   Function Name: vmf_mcc_test()
 *                  M4 task
 *   Description:   osal message receive
 *                  and trace message sender
 *   Parameters:    mcc_node           (input)mcc node number
 *
 *   Return value:  vmf_ret_t type
 *
 ******************************************************************************/
void vmf_mcc_test(unsigned32 data)
{
    static  BOOL    init=FALSE;
    int             iret=0;
    vmf_ret_t       vmf_ret=VMF_ERROR;
    volatile        os_event_t  event_mask;
    volatile        os_status_t os_ret;

    if (0 == vmf_trid)
    {
        VMF_TRACE_REGISTER(&vmf_trid,"vmf_mcc_m4");
    }
    if (0 == mcc_cid)
    {
        mcc_cid = nw_vmf_connect("vmf_mcc_m4",NULL,0,0,0);
    }

#if 0
    if (FALSE == init)
    {
        os_ret = os_alarm_periodic(ALARM_MCC_TEST_PERIODIC_TMO_ID, 100, TASK_VMF_MCC_TEST, EV_MCC_TEST_TMO);
        if (os_ret != OS_STATUS_OK)
        {
            unsigned8   dummy=0;

            VMF_DEBUG_ERROR("MCCM4Task","os_alarm_periodic error - ret =%d",os_ret);
            os_message_send(TASK_VMF_MCC_TEST, (os_message_id_t)1, sizeof(dummy), (void *)&dummy);
        }
        else
        {
            VMF_DEBUG_INFO("MCCM4Task","started",0);
            init = TRUE;
        }
    }

    {
        static int  i=0;
        int         j;
        unsigned16  start;
        unsigned16  stop;

        os_event_get(&event_mask);
        if ( EV_MCC_TEST_TMO == (event_mask & EV_MCC_TEST_TMO) )
        {
            VMF_DEBUG_INFO("MCCM4Test","test %d",i++);
        }
    }
#endif
}




/**************************************************************************//**
 *
 *   Function Name: vmf_mcc_m4_msg_handler()
 *
 *   Description:   handle messages received via mcc
 *
 *   Parameters:    vmf message
 *
 *   Return value:  void
 *
 ******************************************************************************/
void vmf_mcc_m4_msg_handler(vmf_msg_t *p_vmf_msg)
{
    vmf_ret_t vmf_ret = VMF_ERROR;

    if (NW_VMF_BASIC_MSG_TYPE(p_vmf_msg) != SVMF_BASIC_MSG)
    {
        /* only handle basic messages  */
        return;
    }

    /* message is a basic message */
    switch(NW_VMF_BASIC_MSG_GROUP(p_vmf_msg))
    {
        case VMF_TRACE_CTRL:
        {
            /* set trace filter in trace-shared memory */
            vmf_trace_ctrl_pl_t *pctrl_pl=NULL;
            pctrl_pl = NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_msg);

            switch (NW_VMF_BASIC_MSG_EVENT(p_vmf_msg))
            {
                case VMF_TRACE_CTRL_FILTER_SET:
                {
                    unsigned8   trid;                   /* trace id or 0x00 for all Trace-Tasks */
                    unsigned8   severity;               /* trace only messages with a severity >=  */
                    unsigned8   trace_active;           /* 0x01 if trace for this trace_sif is enabled */

                    trid = pctrl_pl->u.flt_severity.trid;
                    severity = pctrl_pl->u.flt_severity.severity;
                    trace_active = pctrl_pl->u.flt_severity.trace_active;

                    (void)vmf_trace_filter(trid,severity,trace_active);
                }
                break;
            }
            break;
        } /* case VMF_TRACE_CTRL: */

        case VMF_TRACE_SYSINFO_CTRL:
        {
            switch (NW_VMF_BASIC_MSG_EVENT(p_vmf_msg))
            {
                case VMF_SYSINFO_CTRL_PROFILER_PID_NAME_REQ:
                {
                    vmf_sysinfo_pid_name_req_pl_t *ptr;
                    VMF_DEBUG_INFO("VMF_TRACE_SYSINFO_CTRL","vmf_sysinfo_parse_msg VMF_SYSINFO_CTRL_PROFILER_PID_NAME_REQ",0);

                    ptr = (vmf_sysinfo_pid_name_req_pl_t*)(NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_msg));
                    if (SYSINFO_ALL_PIDS == ptr->pid)
                    {
                        /* send all pids */
                        vmf_ret = vmf_sysinfo_send_all_process_names(mcc_cid);
                    }
                    else if (SYSINFO_UPDATE_PIDS == ptr->pid)
                    {
                        /* send only updated pids */
                        vmf_ret = vmf_sysinfo_send_updated_process_names(mcc_cid);
                    }
                    else
                    {   /* send only this pid */
                        vmf_ret = vmf_sysinfo_send_process_name(mcc_cid, (pid_t)ptr->pid);
                    }
                }
                break;

                case VMF_SYSINFO_CTRL_PROFILER_START:
                {
                    vmf_sysinfo_start_req_pl_t *ptr;
                    ptr = (vmf_sysinfo_start_req_pl_t*)(NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_msg));
                    vmf_profiler_install(ptr->int_time);
                }
                break;

                case VMF_SYSINFO_CTRL_PROFILER_STOP:
                {
                    /* de-install the isr */
                    vmf_profiler_install(0);
                }
                break;

                case VMF_SYSINFO_CTRL_PROFILER_START_LOAD_REQ:
                {
                    VMF_DEBUG_INFO("VMF_TRACE_SYSINFO_CTRL","VMF_SYSINFO_CTRL_PROFILER_START_LOAD_REQ",0);
                    vmf_ret = vmf_sysinfo_get_requested_pids((unsigned8 *)NW_VMF_BASIC_MSG_DATA_PTR(p_vmf_msg));
                }
                break;

                case VMF_SYSINFO_CTRL_PROFILER_STOP_LOAD_REQ:
                {
                    VMF_DEBUG_INFO("VMF_TRACE_SYSINFO_CTRL","VMF_SYSINFO_CTRL_PROFILER_STOP_LOAD_REQ",0);
                    vmf_sysinfo_get_requested_pids(NULL);
                }
                break;

                default:
                    VMF_DEBUG_WARNING("VMF_TRACE_SYSINFO_CTRL","VMF_TRACE_SYSINFO_CTRL invalid cmd=%d",NW_VMF_BASIC_MSG_EVENT(p_vmf_msg));
                    /* ignore */
                break;
            }
        }

    } /* switch */
}



/**************************************************************************//**
 *
 *   Function Name: vmf_mcc_m4_trigger_c2c_int()
 *
 *   Description:   trigger the p2p isr on A5
 *
 *   Parameters:    void
 *
 *   Return value:  void
 *
 ******************************************************************************/
static inline vmf_mcc_trigger_a5_c2c_int(void)
{
    #if 0
    MSCM_IRCPGIR = MSCM_IRCPGIR_TLF(3) | MSCM_IRCPGIR_INTID(3);
    #else
    /* use alive isr */
    MSCM_IRCPGIR = MSCM_IRCPGIR_TLF(1) | MSCM_IRCPGIR_INTID(1); /* Trigger the CPU2CPU interrupt */
    #endif
}





#else


/*****************  A5 *******************/





/****************************************************************************/
/*                           A5 code                                        */
/****************************************************************************/


LWEVENT_STRUCT      mcc_event_group={0};
#define             MCC_VMF_MSG_EVENT   0x02

/* local function declaration */
static void vmf_adapt_core_trids (vmf_msg_t *p_vmf_msg);
static void vmf_mcc_a5_isr_install(void);
static void vmf_mcc_gw(uint_32 param);
static BOOL vmf_mcc_start_gw(void);

/**************************************************************************//**
 *
 *   Function Name: vmf_mcc_a5_isr_install()
 *
 *   Description:   install mcc isr on A5
 *
 *   Parameters:    void
 *
 *   Return value:  void
 *
 ******************************************************************************/
static void vmf_mcc_a5_isr_install(void)
{
    static  BOOL    installed=FALSE;
#if 0
    if (FALSE == installed)
    {
        util_int_vec_install(INTERRUPT_CA5_C2C_3, vmf_mcc_a5_isr , (void*) NULL);
        util_int_vec_enable(INTERRUPT_CA5_C2C_3);
        installed = TRUE;
    }
#endif
    _lwevent_create(&mcc_event_group, LWEVENT_AUTO_CLEAR);

}






/**************************************************************************//**
 *
 *   Function Name: vmf_mcc_a5_isr()
 *
 *   Description:   A5 mcc cpu2cpu isr
 *
 *   Parameters:    void
 *
 *   Return value:  void
 *
 ******************************************************************************/
void vmf_mcc_a5_isr(void *not_used)
{
#if 0
    volatile vmf_ret_t   vmf_ret;
    vmf_mcc_msg_t *vmf_mcc_rx_msg;

    if (0 == mcc_cid)
    {
        return;
    }

    if (VMF_OK == vmf_mcc_msg_q_get_msg(&vmf_mcc_rx_msg))
    {
        vmf_ret = nw_vmf_send_raw(mcc_cid,&(vmf_mcc_rx_msg->vmf_msg),sizeof(vmf_mcc_rx_msg->vmf_msg));
        (void)vmf_mcc_msg_pool_put(vmf_mcc_rx_msg);
    }
#else
    (void)_lwevent_set(&mcc_event_group, MCC_VMF_MSG_EVENT);
#endif

}


/**************************************************************************//**
 *
 *   Function Name: vmf_mcc_a5()
 *
 *   Description:   task to communicate between CPU cores
 *
 *   Parameters:    mcc_node           (input)mcc node number
 *
 *   Return value:  vmf_ret_t type
 *
 ******************************************************************************/
void vmf_mcc_a5(unsigned32 data)
{
    int         iret=0;
    vmf_ret_t   vmf_ret=VMF_ERROR;

    os_event_t  event_mask;
    volatile    unsigned32  m_id=0;
    unsigned16  len=0;
    vmf_msg_t   vmf_message;

    if (0==mcc_cid)
    {
        /* connect to vmf */
        while(mcc_cid<=0)
        {
            mcc_cid = nw_vmf_connect("vmf_mi",NULL,0,0,sizeof(vmf_msg_t));
            if (mcc_cid <= 0)
            {
                nw_sleep_ms(WAIT_SOME_TIME);
            }
        }

        vmf_ret = vmf_trace_register(&vmf_trid,"vmf_mcc_a5");
        if (vmf_ret < 0)
        {
            /* no trace output possible so set trid to zero */
            vmf_trid = 0;
        }
        vmf_mcc_init();
        vmf_mcc_start_gw();
    }

    os_event_get(&event_mask);
    if ( EV_MESSAGE == (event_mask & EV_MESSAGE) )
    {
        vmf_mcc_msg_t *vmf_mcc_rx_msg;
        {
#if 0
            /* get message from shared memory and forward message to vmf */
            while (vmf_mcc_msg_q_get_msg(&vmf_mcc_rx_msg) != VMF_OK)
            {
                nw_sleep_ms(0); // yield
            }
            // vmf_adapt_core_trids(&(vmf_mcc_rx_msg->vmf_msg));
            vmf_ret = nw_vmf_send_raw(mcc_cid,&(vmf_mcc_rx_msg->vmf_msg),sizeof(vmf_mcc_rx_msg->vmf_msg));

            (void)vmf_mcc_msg_pool_put(vmf_mcc_rx_msg);
#endif
#if 1
            if( OS_STATUS_OK == os_message_get(&m_id, &len, &vmf_message, sizeof(vmf_message)) )
            {
                /* forward message to vmf */
                vmf_adapt_core_trids(&vmf_message);
                vmf_ret = nw_vmf_send_raw(mcc_cid,&vmf_message,len);
            }
#endif
        }
    }

}


/**************************************************************************//**
 *
 *   Function Name: vmf_adapt_core_trids()
 *
 *   Description:   adapt the trids of M4 trace messages to A5 trids
 *
 *   Parameters:    mcc_node           (input)mcc node number
 *
 *   Return value:  vmf_ret_t type
 *
 ******************************************************************************/
 static void vmf_adapt_core_trids (vmf_msg_t *p_vmf_msg)
{

#if 0
    unsigned8       rtrid=0;
    unsigned8       ltrid=0;
    volatile        vmf_group_t group;

    if (NULL == p_vmf_msg)
    {
        return;
    }

    if (NW_VMF_MSG_TYPE(p_vmf_msg) != SVMF_BASIC_MSG)
    {
        return;
    }

    group = NW_VMF_MSG_GROUP(p_vmf_msg);
    switch (group)
    {
        case VMF_TRACE_CTRL:
        {
            vmf_trace_ctrl_pl_t *ptrace_ctrl=NULL;

            /* replace local trid with remote trid */
            ptrace_ctrl = (vmf_trace_ctrl_pl_t*)NW_VMF_MSG_DATA_PTR(p_vmf_msg);

            ltrid = ptrace_ctrl->u.flt_severity.trid;
            rtrid = ltrid+=MAX_VMF_TRACE_CORE_TRIDS;    /* add offset */
            ptrace_ctrl->u.flt_severity.trid = rtrid;
        }
        break;

        case VMF_TRACE_IN:
            /* no break */
        case VMF_TRACE_OUT:
        {
            vmf_trace_pl_t  *trace_pl=NULL;

            trace_pl = (vmf_trace_pl_t*)NW_VMF_MSG_DATA_PTR(p_vmf_msg);
            ltrid = trace_pl->trid;
            rtrid = ltrid+=MAX_VMF_TRACE_CORE_TRIDS;    /* add offset */
            trace_pl->trid = ltrid;
        }
        break;

        default:
        /* do nothing */
        break;
    }
#endif
    return;
}


/**************************************************************************//**
 *
 *   Function Name: start_vmf_mcc_gw()
 *
 *   Description:   A5: start the VMF mcc gateway thread
 *
 *   Parameters:    void
 *
 *   Return value:  \return true if OK
 *
 ******************************************************************************/
static BOOL vmf_mcc_start_gw(void)
{

    BOOL bret = TRUE;

    #ifdef VMF_MQX
    /* use native mqx task */

    #define VMF_APP_TASK 1
    _task_id vmf_apptask_id;
    static TASK_TEMPLATE_STRUCT mqx_vmfapp_template;

    mqx_vmfapp_template.TASK_TEMPLATE_INDEX = 1;
    mqx_vmfapp_template.TASK_ADDRESS        = vmf_mcc_gw;
    mqx_vmfapp_template.TASK_NAME           = "VMF_MCC_GW";
    mqx_vmfapp_template.CREATION_PARAMETER  = (uint_32)(0);
    mqx_vmfapp_template.TASK_STACKSIZE      = 1000;
    mqx_vmfapp_template.TASK_PRIORITY       = 7;
    mqx_vmfapp_template.CREATION_PARAMETER  = 0;
    mqx_vmfapp_template.DEFAULT_TIME_SLICE  = 5;
    mqx_vmfapp_template.TASK_ATTRIBUTES = MQX_TIME_SLICE_TASK;

    vmf_apptask_id = _task_create(0, 0, (uint_32)&mqx_vmfapp_template);
    if (MQX_NULL_TASK_ID == vmf_apptask_id)
    {
        bret = FALSE;
    }

    #else
    /* use OSAL */
    static os_task_create_t vmf_apptask = { 1000, 40, vmf_mcc_gw, 0, FALSE };    /* stack, priority, cannback, arg, use_queue */
    static os_task_id_t     vmf_app_task_id;


    if (OS_STATUS_OK != os_task_create(&vmf_app_task_id, &vmf_apptask))
    {
        bret = FALSE;
    }
    #endif

    return bret;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_rec_thread()
 *
 *   Description:   VMF mcc-gw thread
 *
 *   Parameters:    NOT USED
 *
 *   Return value:  \return true if OK
 *
 ******************************************************************************/
static void vmf_mcc_gw(uint_32 param)
{
    while(TRUE)
    {
        _lwevent_wait_ticks(&mcc_event_group, MCC_VMF_MSG_EVENT, FALSE,MCC_Q_READ_TIMEOUT);
        {
            static volatile vmf_ret_t   vmf_ret;
            vmf_mcc_msg_t *vmf_mcc_rx_msg;
            if (0 == mcc_cid)
            {
                continue;
            }

            while (VMF_OK == vmf_mcc_msg_q_get_msg(&vmf_mcc_rx_msg))
            {
                vmf_ret = nw_vmf_send(mcc_cid,&(vmf_mcc_rx_msg->vmf_msg));
                // vmf_ret = nw_vmf_send_raw(mcc_cid,&(vmf_mcc_rx_msg->vmf_msg),VMF_MSG_LEN(NW_VMF_MSG_DATA_LENGTH(&(vmf_mcc_rx_msg->vmf_msg))));
                (void)vmf_mcc_msg_pool_put(vmf_mcc_rx_msg);
                nw_sleep_ms(0); // yield
            }
        }
    }
}



#endif

/****************************************************************************/
/*                       code for both cores                                */
/****************************************************************************/


/**************************************************************************//**
 *
 *   Function Name: vmf_mcc_init()
 *
 *   Description:   init the vmf-mcc message pool an queue
 *
 *   Parameters:    void
 *
 *   Return value:  void
 *
 ******************************************************************************/
void vmf_mcc_init(void)
{
    int         cnt=0;
    volatile bool   error=0;    /* for debugger */

    SPIN_LOCK_INIT();

    #if ( VS_MICRO_CORE_A5 == VS_MICRO_CORE )
    /* A5 */
    vmf_mcc_a5_isr_install();
    if (_mutex_init(&mcc_read_mux, NULL) != MQX_OK)
    {
        error = TRUE;   /* debug */
    }
    read_ix =0;
    #else
    /* M4 */
    if (_mutex_init(&mcc_write_mux, NULL) != MQX_OK)
    {
        error = TRUE;   /* debug */
    }
    read_ix =0;         /* prevent optimisation */
    write_ix =0;
    #endif

    SPIN_LOCK();
    if (TRUE == vmf_mcc_msg_pool.initialised)
    {
        SPIN_UNLOCK();
        return;
    }

    for (cnt=0; cnt <VMF_MCC_POOL_MSG_NUM-1; cnt++)
    {
        vmf_mcc_msgs[cnt].next = &vmf_mcc_msgs[cnt+1];
    }
    vmf_mcc_msgs[cnt].next = NULL;                          /* last buffer */
    vmf_mcc_msg_pool.first = &vmf_mcc_msgs[0];
    vmf_mcc_msg_pool.last  = &vmf_mcc_msgs[VMF_MCC_POOL_MSG_NUM-1];
    vmf_mcc_msg_pool.num   = VMF_MCC_POOL_MSG_NUM;
    vmf_mcc_msg_pool.num_lost_messages = 0;
    vmf_mcc_msg_pool.initialised = TRUE;
    SPIN_UNLOCK();

}


/**************************************************************************//**
 *
 *   Function Name: vmf_mcc_msg_pool_get()
 *
 *   Description:   get a buffer from the vmf-mcc message pool
 *                  messages are taken from start of pool
 *   Parameters:    pointer pointer to message
 *   Return value:  VMF_OK id mesage available
 *
 ******************************************************************************/
vmf_ret_t vmf_mcc_msg_pool_get(vmf_mcc_msg_t **pp_msg)
{
    volatile BOOL   error=FALSE;
    if (NULL == pp_msg)
    {
        return VMF_ERR_NULL_POINTER;
    }
    /* as long as this function is only called only from the M4 no need to check if the pool is initialized */

    /* is there a free buffer in the pool ?*/
    if (NULL == vmf_mcc_msg_pool.first)
    {
        /* no more buffers */
        *pp_msg = NULL;
        vmf_mcc_msg_pool.num_lost_messages++;
        #if ( VS_MICRO_CORE_M4 == VS_MICRO_CORE )
        vmf_mcc_trigger_a5_c2c_int();    /* wake A5  */
        #endif
        return VMF_ERR_NO_MORE_DATA;
    }
    else if (NULL == vmf_mcc_msg_pool.last)
    {
        /* ERROR !!! */
        error=TRUE;
        return VMF_ERR_NO_MORE_DATA;
    }

    SPIN_LOCK();
    if (TRUE == vmf_mcc_lock)
    {
        /* error */
        error=TRUE;
    }
    vmf_mcc_lock = TRUE;

    *pp_msg = vmf_mcc_msg_pool.first;
    vmf_mcc_msg_pool.first = vmf_mcc_msg_pool.first->next;
    if (NULL == vmf_mcc_msg_pool.first)
    {
        /* pool is empty now */
        vmf_mcc_msg_pool.last = NULL;
        #if ( VS_MICRO_CORE_M4 == VS_MICRO_CORE )
        vmf_mcc_trigger_a5_c2c_int();    /* wake A5  */
        #endif
    }

    if (0 == vmf_mcc_msg_pool.num)
    {
        error=TRUE;
    }

    vmf_mcc_msg_pool.num--;             /* debug only */

    vmf_mcc_lock = FALSE;
    SPIN_UNLOCK();

    return VMF_OK;
}

/**************************************************************************//**
 *
 *   Function Name: vmf_mcc_msg_pool_put()
 *
 *   Description:   put a message back to the vmf-mcc message pool
 *                  messages are added to the end of the pool
 *   Parameters:    pointer pointer to message
 *   Return value:  VMF_OK id mesage available
 *
 ******************************************************************************/
vmf_ret_t vmf_mcc_msg_pool_put(vmf_mcc_msg_t *p_msg)
{
    volatile BOOL   error=FALSE;
    if (NULL == p_msg)
    {
        /* invalid buffer */
        return VMF_ERR_NULL_POINTER;
    }
#if 0
    else if (FALSE == vmf_mcc_msg_pool.initialised)
    {
        /* pool not jet initialized */
        /* that shouldnt happen !!! */
        return VMF_ERROR;
    }
#endif
    SPIN_LOCK();
    if (TRUE == vmf_mcc_lock)
    {
        /* error */
        SPIN_UNLOCK();
        error = TRUE;
        return VMF_ERROR;
    }
    vmf_mcc_lock = TRUE;

    p_msg->next = NULL;
    if (NULL != vmf_mcc_msg_pool.last)
    {
        /* pool is not empty */
        vmf_mcc_msg_pool.last->next = p_msg;    /* add the buffer to end of the pool */
        if (0 == vmf_mcc_msg_pool.num)
        {
            error = TRUE;
        }
    }
    else
    {
        /* pool is empty */
        vmf_mcc_msg_pool.first = p_msg;
    }
    vmf_mcc_msg_pool.last = p_msg;
    vmf_mcc_msg_pool.num++;                     /* debug only */

    vmf_mcc_lock = FALSE;
    SPIN_UNLOCK();

    return VMF_OK;
}




/**************************************************************************//**
 *
 *   Function Name: vmf_mcc_msg_queue_get_msg()
 *
 *   Description:   get a message from the vmf-mcc message queue
 *
 *   Parameters:    pointer pointer to message
 *   Return value:  VMF_OK id mesage available
 *
 ******************************************************************************/
vmf_ret_t vmf_mcc_msg_q_get_msg(vmf_mcc_msg_t **pp_msg)
{
    if (NULL == pp_msg)
    {
        /* invalid buffer */
        return VMF_ERR_NULL_POINTER;
    }

    /* is there a mesage in the queue? */
    if (write_ix == read_ix)
    {
        /* no message */
        return VMF_ERR_NO_MORE_DATA;
    }

    _mutex_lock(&mcc_read_mux);
    /* read message from queue */
    *pp_msg = vmf_mcc_msg_q[read_ix];
    read_ix++;
    if (read_ix >=VMF_MCC_POOL_MSG_NUM)
    {
        read_ix=0;
    }
    _mutex_unlock(&mcc_read_mux);
    return VMF_OK;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_mcc_msg_q_put_msg()
 *
 *   Description:   put a message to the vmf-mcc message queue
 *
 *   Parameters:    pointer to message
 *   Return value:  VMF_OK id mesage available
 *
 ******************************************************************************/
vmf_ret_t vmf_mcc_msg_q_put_msg(vmf_mcc_msg_t *p_msg)
{
    if (NULL == p_msg)
    {
        /* invalid buffer */
        return VMF_ERR_NULL_POINTER;
    }
    _int_disable();
    _mutex_lock(&mcc_write_mux);
    vmf_mcc_msg_q[write_ix] = p_msg;
    write_ix++;
    if (write_ix >=VMF_MCC_POOL_MSG_NUM)
    {
        write_ix=0;
    }
    _mutex_unlock(&mcc_write_mux);
    _int_enable();
    vmf_mcc_trigger_a5_c2c_int();
    return VMF_OK;
}





/**************************************************************************//**
 *
 *   Function Name: vmf_mcc_m4()
 *
 *   Description:   this task will run on the M4
 *                  task to communicate between CPU cores
 *
 *   Parameters:    not used
 *
 *   Return value:  vmf_ret_t type
 *
 ******************************************************************************/
void vmf_mcc_m4(unsigned32 data)
{
    static      BOOL    init_done=FALSE;
    volatile    os_event_t  event_mask;
    volatile    os_status_t os_ret=OS_STATUS_OK;
    volatile    unsigned32  m_id=0;
    unsigned16  len=0;
    vmf_msg_t   vmf_message;

    if (FALSE == init_done)
    {
        vmf_mcc_init();
        init_done = TRUE;
    }

    os_event_get(&event_mask);

    if ( EV_MESSAGE == (event_mask & EV_MESSAGE) )
    {
        /* handle all pending messages */
        while(OS_STATUS_OK == os_ret)
        {
            os_ret = os_message_get(&m_id, &len, &vmf_message, sizeof(vmf_message));
            if( OS_STATUS_OK == os_ret)
            {
                /* handle single message*/
                (void)vmf_mcc_m4_msg_handler(&vmf_message);
            }
        }
    }
}


/**************************************************************************//**
 *
 *   Function Name: vmf_mcc_soft_lock_init()
 *
 *   Description:   replacement for the non working spinlocks
 *   Parameters:    void
 *
 *   Return value:  void
 *
 ******************************************************************************/
static inline void vmf_mcc_soft_lock_init   (void)
{
    static   bool   init=FALSE;

    volatile BOOL   error=FALSE;
    if (FALSE == mux_init)
#ifdef USE_MUX
    {
        VMF_MCC_HW_SEM_RELEASE(VMF_MCC);
        if (_mutex_init(&mcc_mux, NULL) != MQX_OK)
        {
            error = TRUE;   /* debug */
        }
        mux_init=TRUE;
    }
#else
    {
        VMF_MCC_HW_SEM_RELEASE(VMF_MCC);
        mux_lock = FALSE;
        mux_init=TRUE;
    }
#endif
}

/**************************************************************************//**
 *
 *   Function Name: vmf_mcc_soft_lock()
 *
 *   Description:   replacement for the non working spinlocks
 *   Parameters:    void
 *
 *   Return value:  void
 *
 ******************************************************************************/
static inline void vmf_mcc_soft_lock       (void)
{
    #define ME 1
    volatile BOOL   error=FALSE;
#ifdef USE_MUX
    if (MQX_EOK != _mutex_lock(&mcc_mux))
    {
        error = TRUE;   /* debug */
    }
#else
    MCC_DI();
    if (FALSE == mux_init)
    {
        vmf_mcc_soft_lock_init();
    }
    while(TRUE == mux_lock);
    mux_lock=TRUE;
#endif
    while( VMF_MCC_HW_SEM_BUSY(VMF_MCC));
    VMF_MCC_HW_SEM_LOCK(VMF_MCC);

}

/**************************************************************************//**
 *
 *   Function Name: vmf_mcc_soft_unlock()
 *
 *   Description:   replacement for the non working spinlocks
 *   Parameters:    void
 *
 *   Return value:  void
 *
 ******************************************************************************/
static inline void vmf_mcc_soft_unlock     (void)
{
#ifdef USE_MUX
    (void)_mutex_unlock(&mcc_mux);
    VMF_MCC_HW_SEM_RELEASE(VMF_MCC);
#else
    VMF_MCC_HW_SEM_RELEASE(VMF_MCC);
    mux_lock = FALSE;
    MCC_EI();
#endif
}










