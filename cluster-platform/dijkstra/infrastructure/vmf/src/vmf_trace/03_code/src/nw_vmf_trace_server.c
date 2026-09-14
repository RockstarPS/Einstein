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
*  PROJECT NAME :  VMF_TRACE_SERVER                                           *
*******************************************************************************
*  MODULE NAME  :  vmf_trace_server.c                                         *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   13 July 2009                                              *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  VMF_TRACE                                                                  *
******************************************************************************/

/***************************************************************************

  Module:               nw_vmf_trace_server.c
  Description:          vmf trace server

  Project Scope:        Fisker

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   gcc
  Target Hardware:      Any

  *****************************************************************************/
#define VMF_TRACE_SERVER_C

#if 0
#define DSP_STARTUPQ_MSG
#endif

// #define VMF_TRACE_KEEP_STARTUP_Q
#define VMF_TRACE_ALLOW_PREREGISTER /* allow pre-registration of all clients */
#include "nw_os_config.h"
#include "nw_vmf.h"
#include "nw_vmf_cfg.h"             /* in 07_system */
#include "nw_vmf_trace_server.h"
#include "nw_vmf_trace.h"
#include "nw_vmf_ipc.h"
#include "nw_vmf_sysinfo.h"
#include "nw_vmf_debug.h"
#ifdef DLT_GW
#include "nw_vmf_trace_dlt_gw.h"
#endif
#ifdef VMF_TARGET_LOGGING
#include "nw_vmf_target_log.h"
#endif

/* global variables */

/* share memory page */
vmf_trace_shm_t     *vmf_trace_shm=NULL;

/* storage for persistent data */
NW_STATIC  vmf_trace_shm_t  vmf_persistent_data;

NW_STATIC   bool            viewer_connected=false;
NW_STATIC   unsigned8       vmf_trace_svr_trid=1;
NW_STATIC   bool            vmf_tracer_data_in_stq=false;

NW_STATIC   unsigned8       vmf_trace_def_severity      = VMF_TRACE_DEF_SEVERITY;
NW_STATIC   bool            vmf_trace_def_startup_q     = VMF_TRACE_DEF_STARTUP_Q;
NW_STATIC   bool            vmf_trace_def_trid_active   = VMF_TRACE_DEF_TRID_ACTIVE;
NW_STATIC   bool            vmf_trace_def_global_active = VMF_TRACE_DEF_GLOBAL_ACTIVE;

bool                        trace_sync = false;

/* trace severities in ini file */
vmf_ini_trace_severity_t    vmf_ini_trace_severities[MAX_VMF_TRACE_TRIDS];
unsigned8                   vmf_ini_trace_severities_count = 0;


/* definitions  */
#define COLLECTOR_BUFFER_LEN 1900                       /* collector buffer size (max size about VMF_TRACE_MSG_LEN-50) */

#define COLLECTOR_TX_TIMEOUT 500                        /* collector tx timout in ms */

#define VMF_TRACE_SERVER_STACK_SIZE    (VMF_NW_STACK_SIZE + COLLECTOR_BUFFER_LEN)
#define VMF_TRACE_SERVER_THREAD_PRIO   (10)
#define VMF_TRACE_MSG_LEN              (2000)

#define COLLECTOR_TX_TIMEOUT_SQ 100                     /* collector tx timout in ms if data in startup queue */
#ifndef FOREVER
#define FOREVER (true)
#endif

/* externals */
#ifdef DLT_GW
extern bool enable_dlt_gw;
#endif
extern void TraceShm(vmf_trace_shm_t* p_shm);
extern bool vmf_file_system_access;

/* local function prototypes */
NW_STATIC void *vmf_trace_server_task               (void *pArg);
NW_STATIC vmf_ret_t vmf_trace_create_shm            (vmf_trace_shm_t**pp_shm);
NW_STATIC vmf_ret_t vmf_trace_init_shm              (vmf_trace_shm_t* p_shm);
NW_STATIC vmf_ret_t vmf_trace_init_shm_msg_ctr      (vmf_trace_shm_t* p_shm);
NW_STATIC vmf_ret_t vmf_trace_decode_ctrl           (vmf_client_id_t cid,vmf_trace_shm_t* p_shm, vmf_trace_shm_t* p_pers, vmf_msg_t *pvm_msg);
NW_STATIC vmf_ret_t vmf_trace_filter                (vmf_trace_shm_t* p_shm, unsigned8 trid,unsigned8 severity, unsigned8 trace_active);
NW_STATIC vmf_ret_t vmf_trace_persistent_write      (vmf_trace_shm_t* p_shm);
NW_STATIC vmf_ret_t vmf_trace_persistent_read       (vmf_trace_shm_t* p_pers);
NW_STATIC vmf_ret_t vmf_trace_persistent_2_shm      (vmf_trace_shm_t* p_shm,vmf_trace_shm_t* p_pers, char *trid_name,unsigned8 trid);
NW_STATIC vmf_ret_t vmf_trace_ini_severity_2_shm    (unsigned8 trid, vmf_trace_shm_t* p_shm);
NW_STATIC vmf_ret_t vmf_trace_handle_filter_req     (vmf_client_id_t cid,vmf_trace_shm_t* p_shm);
NW_STATIC vmf_ret_t vmf_trace_msg_collector         (vmf_trace_shm_t* p_shm,vmf_client_id_t vmf_trace_tx_cid,vmf_msg_t *pvm_msg,unsigned16 vmf_msg_len);
NW_STATIC vmf_ret_t vmf_trace_handle_startup_q_req  (vmf_client_id_t cid,vmf_trace_shm_t* p_shm);
NW_STATIC vmf_ret_t vmf_trace_send_filter_response  (vmf_client_id_t cid,unsigned8 trid,vmf_trace_shm_t* p_shm);
NW_STATIC inline unsigned32 getmypid(void);
NW_STATIC vmf_ret_t vmf_trace_register_trace_server (vmf_client_id_t vmf_client_id);
NW_STATIC vmf_ret_t vmf_trace_msg_check_plausibility(char *prefix,vmf_msg_t *pvm_msg);
#if !defined __WINDOWS__ && !defined INTEGRITY
NW_STATIC void      vmf_trace_sig_handler(int sig);
#endif


/**************************************************************************//**
 *
 *   create vmf_trace server main thread
 *
 *   \param[in]     void
 *   \return        vmf_ret_t           VMF_OK or VMF_ERROR
 *
 ******************************************************************************/
vmf_ret_t vmf_trace_server_create_thread(void)
{
    pthread_t       th;
    pthread_attr_t  attr;
    struct sched_param param;
    int             iRet;
	char Thread_name[100];

    VMF_TRACE_SERVER_INFO_PRINT("vmf_trace_server_create_thread() entry");
    /* set the attributes of the thread */
    (void)pthread_attr_init (&attr);
    (void)pthread_attr_setschedpolicy (&attr, SCHED_RR);

    #ifndef __ANDROID__
    iRet = pthread_attr_setstacksize  (&attr, VMF_TRACE_SERVER_STACK_SIZE);
    if (EOK != iRet)
    {
        VMF_TRACE_SERVER_ERROR_PRINT("vmf_trace_server: vmf_trace_server_create_thread() pthread_attr_setstacksize() failed with = %d -- We go on...\n",iRet);
    }
    #endif

    #ifdef INTEGRITY
    (void)pthread_attr_setthreadname(&attr, "vmf trace svr");
    #endif

    (void)pthread_attr_getschedparam (&attr, &param );      /* NOTE QNX does have a param.sched_curpriority which we don't want to touch! */
    param.sched_priority = VMF_TRACE_SERVER_THREAD_PRIO;
    (void)pthread_attr_setschedparam (&attr, &param );

    (void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );

    iRet = pthread_create (&th  ,&attr, vmf_trace_server_task, NULL);
    (void)pthread_attr_destroy(&attr);
    if (iRet)
    {
        VMF_TRACE_SERVER_ERROR_PRINT("vmf_trace_server: vmf_trace_server_create_thread() error errno = %d\n",iRet);
        return VMF_ERROR;
    }
		
#ifdef NW_SET_PRIO_AGAIN
    /* set priority (again) */
    {
        int policy;
        policy=SCHED_RR;
        param.sched_priority = VMF_TRACE_SERVER_THREAD_PRIO;
        iRet = pthread_setschedparam(th, policy, &param);
        if (0 != iRet)
        {
            VMF_TRACE_SERVER_ERROR_PRINT("vmf_trace_server: vmf_trace_server_create_thread() error setting priority error=%d\n",iRet);
            /* no error return ! */
        }
    }
#endif

#if ((defined(__QNX__) && (_NTO_VERSION >= 632)) || defined(__LINUX__))
    /* Name the vmf-trace-server thread */
	sprintf(Thread_name, "Trace-Server-%d", th);
    nw_os_set_thread_name(th, Thread_name);
#endif    

    (void) nw_vmf_create_sysinfo_thread();
    VMF_TRACE_SERVER_INFO_PRINT("vmf_trace_server_create_thread() exit");
    return VMF_OK;
}


/**************************************************************************//**
 *
 *   pre-init vmf_trace server
 *
 *   \param[in]     void
 *   \return        void
 ******************************************************************************/
void vmf_trace_server_pre_init(void)
{

#ifdef CLEAR_SHM
    (void) shm_unlink(VMF_TRACE_SHM);
#endif
    (void) sem_unlink(VMF_TRACE_SEM);
}



/**************************************************************************//**
 *
 *   vmf_trace server main thread
 *
 *   \param[in]     pArg                thread argument
 *   \return        void *
 *
 ******************************************************************************/
NW_STATIC void *vmf_trace_server_task(void *pArg)
{
    static      vmf_client_id_t     vmf_trace_cid=0;
    vmf_ret_t   ret_val;
    unsigned8   nw_vmf_trace_group_list[]      = {VMF_TRACE_CTRL,VMF_TRACE_IN};

    UNUSED_PARAM(pArg);

    VMF_TRACE_SERVER_INFO_PRINT("vmf_trace_server_task() started");

    /* intstall signal handler */
    #if !defined __WINDOWS__ && !defined INTEGRITY
    signal(SIGINT, vmf_trace_sig_handler);
    #endif
    /* connect trace-message group to vmf server */
    /* connect to vmf server */

    while(true)
    {
        VMF_TRACE_SERVER_INFO_PRINT("vmf_trace_server_task() call nw_vmf_connect");
        vmf_trace_cid = nw_vmf_connect("vmf_trace_server",NULL,0,VMF_TRACE_QUEUE_SIZE,VMF_TRACE_QUEUE_MSG_SIZE);
        if (vmf_trace_cid < 0)
        {
            /* an error occured */
            VMF_TRACE_ERROR_PRINT("vmf_trace_server: nw_vmf_connect failed");
            delay(20);
        }
        else
        {
            VMF_TRACE_SERVER_INFO_PRINT("vmf_trace_server_task() connected to VMF cid=%d",vmf_trace_cid);
            break;
        }
    }
    VMF_TRACE_INFO_PRINT("vmf_trace_server_task connected to VMF\n");

    /* register to trace input group and control group */
    if(nw_vmf_register_msg_group(vmf_trace_cid,sizeof(nw_vmf_trace_group_list),&nw_vmf_trace_group_list[0]) < 0)
    {
        VMF_TRACE_ERROR_PRINT("vmf_trace_server: nw_vmf_register_msg_group() failed");
        return NULL;
    }

    if(VMF_OK != vmf_trace_register_trace_server(vmf_trace_cid))
    {
        VMF_TRACE_ERROR_PRINT("vmf_trace_server: vmf_trace_register_trace_server() failed");
    }

    VMF_TRACE_INFO_PRINT("vmf_trace_server_task vmf_trace_create_shm()\n");
    /* open the shared memory page */
    ret_val = vmf_trace_create_shm(&vmf_trace_shm);
    if (VMF_OK != ret_val)
    {
        /* an error occured */
        VMF_TRACE_ERROR_PRINT("vmf_trace_server: vmf_trace_create_shm() failed\n");
        return NULL;
    }

    VMF_TRACE_INFO_PRINT("vmf_trace_server_task vmf_trace_init_shm()\n");
    ret_val = vmf_trace_init_shm(vmf_trace_shm);
    if (VMF_OK != ret_val)
    {
        /* an error occured */
        VMF_TRACE_ERROR_PRINT("vmf_trace_server: vmf_trace_init_shm() failed\n");
        return NULL;
    }

    /* read persistent data */
    VMF_TRACE_INFO_PRINT("vmf_trace_server_task vmf_trace_persistent_read()\n");
    if (VMF_OK != vmf_trace_persistent_read(&vmf_persistent_data))
    {
        VMF_TRACE_INFO_PRINT("vmf_trace_persistent_read() failed\n");

        /* copy default settings to persistent memory area */
        vmf_persistent_data = *vmf_trace_shm;
        (void) vmf_trace_persistent_write(vmf_trace_shm);
    }
    else
    {
        VMF_TRACE_INFO_PRINT("vmf_trace_persistent_read() OK!\n");
        if (vmf_persistent_data.gl_startup_q)
        {
            /* store startup queue status in shm */
            vmf_trace_shm->gl_trace_active      = true;
            vmf_trace_shm->gl_startup_q         = true;
            vmf_persistent_data.gl_trace_active = true; /* alway open global filter if startup Q enabled*/
        }
    }

#ifdef VMF_TRACE_ALLOW_PREREGISTER
    /* store persistent file to shared memory - so alle trace-clients are pre-registered */
    *vmf_trace_shm = vmf_persistent_data;
    (void) vmf_trace_init_shm_msg_ctr(vmf_trace_shm);
#else
    /* register vmf early */
    (void) vmf_trace_persistent_2_shm(vmf_trace_shm,&vmf_persistent_data, "vmf",VMF_TRID_VMF);
#endif

    /* connect the trace server also as trace client to output its own error messages */
    VMF_TRACE_INFO_PRINT("vmf_trace_server_task vmf_trace_register()\n");
    ret_val = vmf_trace_register(&vmf_trace_svr_trid,"vmf");
    if (ret_val < 0)
    {
        VMF_TRACE_ERROR_PRINT("vmf_trace_server: vmf_trace_register failed - ret=%d\n",ret_val);
    }

    /* endless loop for all trace message       */
    /* a Viewer is connected                    */
    /* start the reception of all trace messages*/
    (void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_trace_server","rx-loop2","enter endless loop for vmf_trace_cid");
    VMF_TRACE_SERVER_INFO_PRINT("vmf_trace_server_task() set trace_sync and start endloess loop");
    trace_sync = true;
#ifdef DLT_GW
    vmf_trace_dlt_gw_create_thread();
    if (true == enable_dlt_gw)
    {
//      viewer_connected=true;
    }
#endif


#ifdef VMF_TARGET_LOGGING
                /* init target logging */
                (void) vmf_target_log_init_trace();
#endif


    while (true)
    {
        VMF_VAR_MSG_TYP(VMF_TRACE_MSG_SIZE)  vmf_msg;
        unsigned16  vmf_msg_len;
        vmf_ret_t   vmf_ret;
        unsigned16  rx_timeout;

        /* decrease the receive timeout if there is data in the startup queue */
        if (false == vmf_tracer_data_in_stq)
        {
            /* no data in startup queue */
            rx_timeout = COLLECTOR_TX_TIMEOUT+1;
        }
        else
        {
            /* smaller timeout if data in startup queue to display stored data faster */
            rx_timeout = COLLECTOR_TX_TIMEOUT_SQ;
        }

        vmf_ret = nw_vmf_timed_receive(vmf_trace_cid,(vmf_msg_t*)&vmf_msg,sizeof(vmf_msg),rx_timeout);
        if (vmf_ret <= 0)
        {
            /* no data or timeout */
            /* check if we have to send collected messages */
            (void) vmf_trace_msg_collector(vmf_trace_shm,vmf_trace_cid,NULL,0);
            delay(50);
#ifdef UNIT_TEST
            VMF_TRACE_ERROR_PRINT("vmf_trace_server: nw_vmf_timed_receive failed - ret=%d\n",vmf_ret);
            return NULL;
#else
            /* continue; */
#endif
        }
        else
        {
            vmf_msg_len = (unsigned16)vmf_ret;

            if (VMF_BASIC_MSG_GROUP_ID((vmf_msg_t*)&vmf_msg)== VMF_TRACE_CTRL)
            {
                VMF_TRACE_SERVER_INFO_PRINT("vmf_trace_server:rx-loop: msg-group=VMF_TRACE_CTRL");
                (void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_5,"vmf_trace_server","rx-loop2","received VMF_TRACE_CTRL - event=%d",VMF_BASIC_MSG_EVENT_ID(&vmf_msg));
                (void) vmf_trace_decode_ctrl(vmf_trace_cid,vmf_trace_shm,&vmf_persistent_data,(vmf_msg_t*)&vmf_msg);
            }
            else if (VMF_BASIC_MSG_GROUP_ID((vmf_msg_t*)&vmf_msg)== VMF_TRACE_IN)
            {

#ifdef VMF_TARGET_LOGGING
                /* send message to target logging */
                vmf_ret = vmf_target_log_write_trace((unsigned8 *)&vmf_msg.vmf_basic_msg.data.pl);
                if (vmf_ret < 0)
                {
                	(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","rx-loop2","write to target log failed with %d",vmf_ret);
                }
#endif

                /* send message to collector */
                VMF_TRACE_SERVER_INFO_PRINT("vmf_trace_server:rx-loop: msg-group=VMF_TRACE_IN, msg-rx-len==%d, data-len==%d",vmf_msg_len, vmf_msg.vmf_basic_msg.data.length);
                vmf_ret = vmf_trace_msg_collector(vmf_trace_shm,vmf_trace_cid,(vmf_msg_t*)&vmf_msg,vmf_msg_len);
                if (vmf_ret < 0)
                {
                    /* an error occured */
                	(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","rx-loop2","vmf_trace_msg_collector failed with %d",vmf_ret);
                }
            }
            else
            {
                VMF_TRACE_SERVER_INFO_PRINT("vmf_trace_server:rx-loop: ignore msg-group=%d",VMF_BASIC_MSG_GROUP_ID((vmf_msg_t*)&vmf_msg));
                (void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_5,"vmf_trace_server","rx-loop2","received group=%d - event%d",VMF_BASIC_MSG_GROUP_ID(&vmf_msg),VMF_BASIC_MSG_EVENT_ID(&vmf_msg));
            }
        }
    } /* while (true)*/
}




/**************************************************************************//**
 *
 *   get startup queue status
 *
 *   \param[in]     void
 *   \return        bool        01 if startup queue enabled else 0x00
 *
 ******************************************************************************/
unsigned8 vmf_trace_server_startup_q_status(void)
{
   return (vmf_persistent_data.gl_startup_q);
}

/******************************************************************************
        local functions
 ******************************************************************************/



 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_decode_ctrl()
 *
 *   Description:   decode a vmf trace control message
 *
 *   Parameters:
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_trace_decode_ctrl(vmf_client_id_t cid,vmf_trace_shm_t* p_shm, vmf_trace_shm_t* p_pers, vmf_msg_t *pvm_msg)
{
    vmf_trace_ctrl_pl_t *pctrl_pl;
    vmf_ret_t           vmf_ret=VMF_OK;

    /* check if message is a control message */
    if (VMF_BASIC_MSG_GROUP_ID(pvm_msg) != VMF_TRACE_CTRL)
    {
    	(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","vmf_trace_decode_ctrl","vmf_trace_decode_ctrl message != VMF_TRACE_CTRL");
    	vmf_ret = VMF_ERROR;
    }
    else
    {
		switch (VMF_BASIC_MSG_EVENT_ID(pvm_msg))
		{
			case VMF_TRACE_CTRL_REG_CLIENT:


				/* store trace client in shm */
				if (pvm_msg->vmf_basic_msg.data.length <= sizeof(vmf_trace_ctrl_reg_client_t))
				{
					unsigned8 trid;
					pctrl_pl = (vmf_trace_ctrl_pl_t*)(pvm_msg->vmf_basic_msg.data.pl);
					trid = pctrl_pl->reg_client.trid;
					/* store trace client in shared mem */
					/* take filters from persistent mem */

					(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_trace_server","vmf_trace_decode_ctrl","VMF_TRACE_CTRL_REG_CLIENT '%s'",pctrl_pl->reg_client.name);
					VMF_TRACE_INFO_PRINT("vmf_trace_decode_ctrl() VMF_TRACE_CTRL_REG_CLIENT %s",pctrl_pl->reg_client.name);
					vmf_ret = vmf_trace_persistent_2_shm(p_shm,p_pers, pctrl_pl->reg_client.name,pctrl_pl->reg_client.trid);

					/* name is already stored by client in shm - so no need to do it here */
					/* send filter response to inform windows client */
					if (VMF_OK == vmf_ret)
					{
						(void) vmf_trace_ini_severity_2_shm(trid, p_shm);
						vmf_ret = vmf_trace_send_filter_response(cid,trid,p_shm);
					}
				}
				else
				{
					(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_trace_server","vmf_trace_decode_ctrl","payload > sizeof(vmf_trace_ctrl_reg_client_t) = %d",pvm_msg->vmf_basic_msg.data.length);
					(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_trace_server","vmf_trace_decode_ctrl","pvm_msg->vmf_basic_msg.data.length=%d",pvm_msg->vmf_basic_msg.data.length);
					(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_trace_server","vmf_trace_decode_ctrl","sizeof(vmf_trace_ctrl_reg_client_t)=%d",sizeof(vmf_trace_ctrl_reg_client_t));
					vmf_ret = VMF_ERR_OUT_OF_RANGE;
				}
				break;


			case VMF_TRACE_CTRL_REG_VIEWER:
				(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_trace_server","vmf_trace_decode_ctrl","VMF_TRACE_CTRL_REG_VIEWER");
				VMF_TRACE_INFO_PRINT ("vmf_trace_server: VMF_TRACE_CTRL_REG_VIEWER\n");
				viewer_connected = true;
				break;


			 case VMF_TRACE_CTRL_UNREG_VIEWER:
				 (void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_trace_server","vmf_trace_decode_ctrl","VMF_TRACE_CTRL_UNREG_VIEWER");
				VMF_TRACE_INFO_PRINT ("vmf_trace_server: VMF_TRACE_CTRL_UNREG_VIEWER\n");
				/* if dlt-gw is enabled then do not disable trace messages */
#ifdef DLT_GW
				if (false == enable_dlt_gw)
				{
					viewer_connected = false;
				}
#endif
				break;


			case VMF_TRACE_CTRL_FILTER_SET:
				viewer_connected = true;
				(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_trace_server","vmf_trace_decode_ctrl","VMF_TRACE_CTRL_FILTER");
				VMF_TRACE_INFO_PRINT ("vmf_trace_server: VMF_TRACE_CTRL_FILTER_SET\n");

				/* copy vmf payload to a trace message */
				pctrl_pl = (vmf_trace_ctrl_pl_t *)pvm_msg->vmf_basic_msg.data.pl;
				{
					unsigned8   trid;                   /* trace id or 0x00 for all Trace-Tasks */
					unsigned8   severity;               /* trace only messages with a severity >=  */
					unsigned8   trace_active;           /* 0x01 if trace for this trace_sif is enabled */

					trid         = pctrl_pl->flt_severity.trid;
					severity     = pctrl_pl->flt_severity.severity;
					trace_active = pctrl_pl->flt_severity.trace_active;

					(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_4,"vmf_trace_server","vmf_trace_decode_ctrl","received trid=%d, severity=%d, trace_active=%d",trid,severity,trace_active);
					vmf_ret = vmf_trace_filter(p_shm,trid,severity,trace_active);
				}
				break;

			/* write filter data to persistent memory */
			case VMF_TRACE_CTRL_PERSISTENT:
				{
					bool startup_q;
					bool trace_active;

					(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_trace_server","vmf_trace_decode_ctrl","VMF_TRACE_CTRL_PERSISTENT");

					/* store startup queue flag and global trace active flag */
					startup_q    = vmf_persistent_data.gl_startup_q;
					trace_active = vmf_persistent_data.gl_trace_active;

					/* copy current data to persistent buffer */
					vmf_persistent_data = *p_shm;

					/* restore flags */
					vmf_persistent_data.gl_startup_q    = startup_q;
					vmf_persistent_data.gl_trace_active = trace_active;

					vmf_ret= vmf_trace_persistent_write(&vmf_persistent_data);
					if (vmf_ret != VMF_OK)
					{
						(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","vmf_trace_decode_ctrl","vmf_trace_persistent_write() failed");
					}
				}

				break;

			/* windows client requested all filters */
			case VMF_TRACE_CTRL_FILTER_REQ:
				/* send filter response */
				viewer_connected = true;
				(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_trace_server","vmf_trace_decode_ctrl","VMF_TRACE_CTRL_FILTER_REQ");
				vmf_ret= vmf_trace_handle_filter_req(cid,p_shm);
				break;

			case VMF_TRACE_CTRL_FILTER_RESP:
				/* own filter response */
				/* ignore */
				(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_trace_server","vmf_trace_decode_ctrl","VMF_TRACE_CTRL_FILTER_RESP");
				break;

			case VMF_TRACE_CTRL_STARTUP_Q_SET:
				(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_trace_server","vmf_trace_decode_ctrl","VMF_TRACE_CTRL_STARTUP_Q_SET");

				/* enable or disable startup queueing */
				pctrl_pl = (vmf_trace_ctrl_pl_t*)(pvm_msg->vmf_basic_msg.data.pl);

				(void) vmf_trace_persistent_read(&vmf_persistent_data);
				if (STARTUP_Q_DIS == pctrl_pl->startup_q.enable)
				{
					vmf_persistent_data.gl_startup_q = false;
					vmf_persistent_data.gl_trace_active = false;
				}
				else
				{
					vmf_persistent_data.gl_startup_q = true;
					vmf_persistent_data.gl_trace_active = true;
				}
				vmf_ret = vmf_trace_persistent_write(&vmf_persistent_data);
				if (vmf_ret != VMF_OK)
				{
					if (false == vmf_file_system_access)
					{
						(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_trace_server","vmf_trace_decode_ctrl","vmf_trace_persistent_write() disabled");
					}
					else
					{
						(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","vmf_trace_decode_ctrl","vmf_trace_persistent_write() failed");
					}
				}

				break;

			case VMF_TRACE_CTRL_STARTUP_Q_REQ:
				/* startup Q request */
				viewer_connected = true;
				(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_trace_server","vmf_trace_decode_ctrl","VMF_TRACE_CTRL_STARTUP_Q_REQ");
				vmf_ret= vmf_trace_handle_startup_q_req(cid,p_shm);
				break;

			case VMF_TRACE_CTRL_STARTUP_Q_RESP:
				/* own response */
				/* ignore */
				(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_trace_server","vmf_trace_decode_ctrl","VMF_TRACE_CTRL_STARTUP_Q_RESP");
				break;



			default:
				/* ignore unkown event */
				vmf_ret = VMF_OK;
				break;
		}
    }
    return vmf_ret;
}






 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_handle_filter_req()
 *
 *   Description:   send all trace filters to the windows client
 *
 *   \param[in]     cid         tx client id
 *   \param[in]     p_shm       pointer to shared memory
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_trace_handle_filter_req(vmf_client_id_t cid,vmf_trace_shm_t* p_shm)
{
    vmf_ret_t           vmf_ret=VMF_OK;
    unsigned8           cnt;
    unsigned            max_trid=0; /* has to be unsigned beacuse the shm value is written by atomic functions */


    (void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_5,"vmf_trace_server","vmf_trace_handle_filter_req","enter function");

    if (NULL == p_shm)
    {
    	(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","vmf_trace_handle_filter_req","p_shm=NULL!");
    	vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else
    {
    	max_trid = p_shm->gl_free_trid;

    	/* send all current filters to the windows client */
    	for (cnt=MIN_VMF_TRACE_TRID; cnt<max_trid ;cnt++)
    	{
    		vmf_ret = vmf_trace_send_filter_response(cid,cnt,p_shm);
    		if (VMF_OK != vmf_ret)
    		{
    			break;
    		}
    	}
    }

    return vmf_ret;
}



 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_send_filter_response()
 *
 *   Description:   send a trace filters of a single trace client to the windows client
 *
 *   \param[in]     cid         tx client id
 *   \param[in]     trid        filters response of this client is send
 *   \param[in]     p_shm       pointer to shared memory
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_trace_send_filter_response(vmf_client_id_t cid,unsigned8 trid,vmf_trace_shm_t* p_shm)
{
    vmf_ret_t           vmf_ret=VMF_OK;

    // if (strlen(p_shm->task[trid].name) > 0)
    {
        vmf_trace_ctrl_pl_t pl;
        unsigned16 len;

        pl.flt_response.severity    = p_shm->task[trid].severity;
        pl.flt_response.trid        = trid;
        pl.flt_response.trace_active= p_shm->task[trid].trace_active;
        nw_os_sstrncpy(pl.flt_response.name, p_shm->task[trid].name, MAX_TRACE_NAME_LEN);
        len = sizeof(vmf_trace_ctrl_filter_response_t)- MAX_TRACE_NAME_LEN + strlen(pl.flt_response.name) +1;

        /* transfer this filter to the client */
        vmf_ret = vmf_trace_send_ctrl(cid,VMF_TRACE_CTRL_FILTER_RESP,&pl,len);
        if (VMF_OK != vmf_ret)
        {
        	(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","vmf_trace_send_filter_response","vmf_trace_send_ctrl() failed error = %d",vmf_ret);
        }
        else
        {
//            vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_4,"vmf_trace_server","vmf_trace_send_filter_response","send filter: trid-name=%s, severity=%d, trace_active=%d",pl.flt_response.name,pl.flt_response.severity,pl.flt_response.trace_active);
        }
    }
    return vmf_ret;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_trace_register_trace_server (vmf_client_id_t vmf_client_id)
 *
 *   Description:   register this client as trace server
 *
 *   Parameters:    vmf_client_id    (input) connection client-id
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_trace_register_trace_server(vmf_client_id_t vmf_client_id) /*!< INPUT client id */
{
    vmf_ret_t       vmf_ret;
    vmf_ctrl_msg_register_trace_server_t myCtrlConMsg;

   /* prepare the control-message */
    myCtrlConMsg.base.msg_type  = MSG_TYPE_REGISTER_TRACE_SERVER;
    myCtrlConMsg.base.pid       = getmypid();
    myCtrlConMsg.base.client_id = vmf_client_id;
    myCtrlConMsg.base.vmf_mi_server_id = 0;
    myCtrlConMsg.base.co_msg_type = 0;
    myCtrlConMsg.base.msg_clk   = nw_os_cfg_get_ms_time();

    vmf_ret = nw_vmf_send_raw(vmf_client_id,&myCtrlConMsg,sizeof(vmf_ctrl_msg_register_trace_server_t));
    if (VMF_OK != vmf_ret)
    {
        (void) fprintf (ERROR_CHANNEL,"vmf_trace_register_trace_server-nw_vmf_send_raw() failed\n");
        (void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","vmf_trace_register_trace_server","nw_vmf_ipc_send() failed with %d",vmf_ret);
    }
    return (vmf_ret);
}



 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_handle_startup_q_req()
 *
 *   Description:   send startup queue status to the windows client
 *
 *   Parameters:
 *   \param[in]     cid         tx client id
 *   \param[in]     p_shm       pointer to shared memory
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_trace_handle_startup_q_req(vmf_client_id_t cid,vmf_trace_shm_t* p_shm)
{
    vmf_ret_t           vmf_ret = VMF_OK;
    vmf_trace_ctrl_pl_t pl;
    unsigned16          len;

    if (NULL == p_shm)
    {
    	(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","vmf_trace_handle_filter_req","p_shm=NULL!");
    	vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else
    {
    	if (vmf_persistent_data.gl_startup_q)
    	{
    		pl.startup_q.enable = STARTUP_Q_ENA;
    	}
    	else
    	{
    		pl.startup_q.enable = STARTUP_Q_DIS;
    	}

    	len = sizeof(vmf_trace_ctrl_filter_response_t);

    	/* transfer this filter to the client */
    	vmf_ret = vmf_trace_send_ctrl(cid,VMF_TRACE_CTRL_STARTUP_Q_RESP,&pl,len);
    	if (VMF_OK != vmf_ret)
    	{
    		(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","vmf_trace_handle_startup_q_resp","vmf_trace_send_ctrl() failed error = %d",vmf_ret);
    	}
    	else
    	{
    		(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_trace_server","vmf_trace_handle_startup_q_resp","q status=%d ",vmf_persistent_data.gl_startup_q);
    	}
    }

    return vmf_ret;
}






 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_create_shm()
 *
 *   Description:   open the vmf_trace shared memory page
 *
 *   \param[in]     pp_shm       pointer pointer to shared memory
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_trace_create_shm(vmf_trace_shm_t** pp_shm)
{
    int fd;
    void *      shm = NULL;
    vmf_ret_t   ret_val;

    /* create a sem to sync the sharem mem access */
#if !defined (__WINDOWS__) && !defined (__ANDROID__) && !defined (INTEGRITY)
#ifndef UNIT_TEST
    mode_t  mask;
    sem_t * sem = NULL;
    mask = umask(0);
    (void) sem_unlink(VMF_TRACE_SEM);

    sem = nw_sem_open(VMF_TRACE_SEM, O_CREAT, 0777 ,0); /* sem is locked! */
    (void)umask(mask);
    if (sem == (sem_t *)SEM_FAILED)
    {
        perror("vmf_trace_server: vmf_trace_create_shm()-sem_open() failed");
        VMF_TRACE_ERROR_PRINT("vmf_trace_server: vmf_trace_create_shm()-sem_open() failed\n");
        return (VMF_ERROR);
    }
#endif
#endif
    /* create share memory */
    *pp_shm = NULL;
    #ifdef CLEAR_SHM
    (void) shm_unlink(VMF_TRACE_SHM);     /*first Remove the Shared Memory */
    #endif

    fd = nw_shm_create(VMF_TRACE_SHM, 0777,sizeof(vmf_trace_shm_t));
    if (fd == -1)
    {
        VMF_TRACE_ERROR_PRINT("vmf_trace_server: vmf_trace_create_shm()-shm_open() failed");
        ret_val = VMF_ERROR;
    }
    else
    {
        /* map shared memory */
        shm = mmap(NULL, sizeof(vmf_trace_shm_t), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
        if (shm == MAP_FAILED)
        {
            // Failed to access the memory
            VMF_TRACE_ERROR_PRINT("vmf_trace_server: vmf_trace_create_shm()-mmap() failed\n");
            (void) nw_shm_close(fd);
            ret_val = VMF_ERROR;
        }
        else
        {
            *pp_shm = (vmf_trace_shm_t*)shm;
            ret_val = VMF_OK;
        }
    }

    /* release the sem */
#if !defined (__WINDOWS__) && !defined (__ANDROID__) && !defined (INTEGRITY)
    #ifndef UNIT_TEST
    if (-1 == sem_post(sem))
    {
        VMF_TRACE_ERROR_PRINT("vmf_trace_server: vmf_trace_create_shm()-sem_post() failed errno=%d\n",errno);
    }
    else
    {
        VMF_TRACE_INFO_PRINT("vmf_trace_server: vmf_trace_create_shm()-sem_post() ok\n");
    }
    #endif
#endif

    return ret_val;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_init_shm()
 *
 *   Description:   init the vmf_trace shared memory page
 *
 *   Parameters:
 *   \param[in]     p_shm                pointer to shared memory
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_trace_init_shm(vmf_trace_shm_t* p_shm)
{
    unsigned8 cnt;
    vmf_ret_t vmf_ret = VMF_ERROR;

    if (NULL == p_shm)
    {
    	vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else
	{
		p_shm->valid=0;

		/* init the global shm */
		p_shm->version          = VMF_SHM_VERSION;
		p_shm->gl_trace_active  = vmf_trace_def_global_active;
		p_shm->gl_startup_q     = vmf_trace_def_startup_q;

		p_shm->gl_trace_group   = VMF_TRACE_IN;     /* initial trace group */
		p_shm->gl_free_trid     = 2;                /* first free task id (1 = reserved for vmf) */

		/* init the task shm */
		for (cnt=0; cnt<MAX_VMF_TRACE_TRIDS ;cnt++)
		{
			p_shm->task[cnt].name[0]='\000';
			p_shm->task[cnt].trace_active = vmf_trace_def_trid_active;  /* start with trace inactive */
			p_shm->task[cnt].severity = vmf_trace_def_severity;
			p_shm->task[cnt].signals = 0;
			p_shm->task[cnt].msg_num = 0;           /* clear the message counter */
		}

		/* pre-load for special clients */
		nw_os_sstrncpy(p_shm->task[0].name, "init", MAX_TRACE_NAME_LEN);
		nw_os_sstrncpy(p_shm->task[1].name, "vmf", MAX_TRACE_NAME_LEN);

		p_shm->task[1].severity = VMF_TRACE_DEF_SEVERITY_VMF;

		/* set chared memory to valid*/
		p_shm->valid = VMF_SHM_VALID_KEY;
		vmf_ret = VMF_OK;
	}
    return vmf_ret;
}

 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_init_shm_msg_ctr()
 *
 *   Description:   init the vmf_trace message counter
 *
 *   Parameters:
 *   \param[in]     p_shm                pointer to shared memory
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_trace_init_shm_msg_ctr(vmf_trace_shm_t* p_shm)
{
    unsigned8 cnt;

    if (NULL == p_shm)
    {
        return VMF_ERR_NULL_POINTER;
    }

    /* init the task shm */
    for (cnt=0; cnt<MAX_VMF_TRACE_TRIDS ;cnt++)
    {
        p_shm->task[cnt].msg_num = 0;           /* clear the message counter */
    }

    return VMF_OK;
}



 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_set_def_severity()
 *
 *   Description:   set the default severity
 *
 *   Parameters:
 *   \param[in]     severity        severity 0..255
 *   \return        vmf_ret_t

 *
 ******************************************************************************/
vmf_ret_t vmf_trace_set_def_severity(unsigned8 severity)
{
    vmf_trace_def_severity = severity;
    vmf_trace_def_trid_active = true;
    vmf_trace_def_global_active = true;
    vmf_trace_def_startup_q = true;

    return VMF_OK;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_set_def_startup_queue()
 *
 *   Description:   set the default state of the startup queueu
 *
 *   Parameters:
 *   \param[in]     p_shm                pointer to shared memory
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
vmf_ret_t vmf_trace_set_def_startup_queue(bool st_queue_enabled)
{
    vmf_trace_def_startup_q = st_queue_enabled;

    return VMF_OK;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_filter()
 *
 *   Description:   set a client trace filter
 *
 *   Parameters:    pointer to shared mem
 *                  trid - trace id or 0 for all sigs
 *                  severity
 *                  trace_active -  0 if no trace message from this sig
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_trace_filter(vmf_trace_shm_t* p_shm,unsigned8 trid,unsigned8 severity, unsigned8 trace_active)
{
    vmf_ret_t   vmf_ret=VMF_OK;
    unsigned    max_trid=0; /* has to be unsigned because the shm value is written by atomic functions */

    if (NULL == p_shm)
    {
    	vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else
    {
    	max_trid = p_shm->gl_free_trid;
    }

    if(VMF_OK == vmf_ret)
    {
    	if (trid > max_trid)
    	{
    		(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","vmf_trace_filter","invalid arg - trid(%d) > max_trid(%d)",trid,max_trid);
    		vmf_ret = VMF_ERR_OUT_OF_RANGE;
    	}
    	else
    	{
    		(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_5,"vmf_trace_server","vmf_trace_filter","set new filter trid = %d, severity=%d, active =%d",trid,severity,trace_active);
    		if (0 == trid)
    		{
    			/* set global filter - ignore severity */

    			if (trace_active != 0)
    			{
    				p_shm->gl_trace_active = true;
    			}
    			else
    			{
    				p_shm->gl_trace_active = false;
    			}
#ifdef DLT_GW
    			if (true == enable_dlt_gw)
    			{
    				p_shm->gl_trace_active = true;
    			}
#endif
    		}
    		else
    		{
    			if (trace_active != 0)
    			{
    				p_shm->task[trid].trace_active = true;      /* start with trace active */
    			}
    			else
    			{
    				p_shm->task[trid].trace_active = false;     /* start with trace not active */
    			}

    			p_shm->task[trid].severity = severity;
    		}
    	}
    }

    return(vmf_ret);
}




 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_persistent_write()
 *
 *   Description:   write persistent data
 *
 *   Parameters:    pointer to shared mem
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_trace_persistent_write(vmf_trace_shm_t* p_shm)
{
    vmf_ret_t   vmf_ret=VMF_OK;
    FILE        *fp_rw;
    size_t      written_len;

    if (false == vmf_file_system_access)
    {
    	(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_WARNING_10,"vmf_trace_server","vmf_trace_persistent_write","write disabled");
        return VMF_OK;
    }

    if (NULL == p_shm)
    {
    	(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","vmf_trace_persistent_write","p_shm = NULL");
        return VMF_ERR_NULL_POINTER;
    }
#ifdef PERS_SET_FILETIME
    /* remove the file first to get a new file-date */
    remove(VMF_TRACE_PERSISTENT_DATA);
#endif

    fp_rw = fopen( VMF_TRACE_PERSISTENT_DATA, "wb" );
    if(fp_rw != NULL)
    {
        #define NUM_ITEMS 1
        written_len = fwrite( p_shm, sizeof(vmf_trace_shm_t ), NUM_ITEMS, fp_rw);
        if (written_len != NUM_ITEMS)
        {
        	(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","vmf_trace_persistent_write","fwrite() failed len = %d",written_len);
            vmf_ret = VMF_ERROR;
        }
        else
        {
            if (vmf_trace_svr_trid > 0)
            {
            	(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_5,"vmf_trace_server","vmf_trace_persistent_write","fwrite() OK");
            }
        }
        (void) fclose( fp_rw );
    }
    else
    {
    	(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","vmf_trace_persistent_write","fopen() failed");
        vmf_ret = VMF_ERROR;
    }

    return vmf_ret;
}




 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_persistent_read()
 *
 *   Description:   read persistent data
 *
 *   Parameters:    pointer to shared mem
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_trace_persistent_read(vmf_trace_shm_t* p_pers)
{
    vmf_ret_t       vmf_ret=VMF_OK;
    FILE            *fp_rw;
    size_t          read_len;
    vmf_trace_shm_t tmp_mem;

    VMF_TRACE_INFO_PRINT("vmf_trace_server: vmf_trace_persistent_read\n");
#if 0
    if (false == vmf_file_system_access)
    {
        return VMF_ERROR;
    }
#endif

    if (NULL == p_pers)
    {
        return VMF_ERR_NULL_POINTER;
    }


    fp_rw = fopen( VMF_TRACE_PERSISTENT_DATA, "rb" );
    if(fp_rw != NULL)
    {
        #define NUM_ITEMS 1
        read_len = fread( &tmp_mem, sizeof(vmf_trace_shm_t ), NUM_ITEMS, fp_rw);
        if (NUM_ITEMS != read_len)
        {
            /* read error */
            vmf_ret = VMF_ERROR;
            (void) fclose( fp_rw );
        }
        else
        {
            (void) fclose( fp_rw );

            /* if version is OK then copy pers data to memory */
            if (VMF_SHM_VERSION==tmp_mem.version)
            {
                memcpy(p_pers, &tmp_mem, sizeof(vmf_trace_shm_t));
                VMF_TRACE_INFO_PRINT("vmf_trace_server: vmf_trace_persistent_read - persitent data version (%d) OK\n",tmp_mem.version);
            }
            else
            {
                VMF_TRACE_INFO_PRINT("vmf_trace_server: vmf_trace_persistent_read - persitent data version (%d) outdated - ignored\n",tmp_mem.version);
                vmf_ret = VMF_ERROR;
            }
        }
    }
    else
    {
        vmf_ret = VMF_ERROR;
    }


    return vmf_ret;
}



/**************************************************************************//**
 *
 *   Function Name: vmf_trace_persistent_2_shm()
 *
 *   Description:   transfer data from persistent memory to shm
 *
 *   Parameters:    pointer to shared mem
 *                  pointer to persistent mem
 *                  unique  trid name
 *                  trid pointing to shared mem
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_trace_persistent_2_shm(vmf_trace_shm_t* p_shm,vmf_trace_shm_t* p_pers, char *trid_name,unsigned8 trid)
{
    unsigned8 cnt;
    int       ret;
    vmf_ret_t vmf_ret = VMF_ERROR;


    if (NULL == trid_name)
    {
    	(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","vmf_trace_persistent_2_shm","trid_name = NULL!");
    	vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else
    {
    	VMF_TRACE_INFO_PRINT("vmf_trace_persistent_2_shm() search for %s\n",trid_name);
    	vmf_ret = VMF_OK;
    }

    if(VMF_OK == vmf_ret)
    {
    	/* argument check */
    	if (NULL == p_shm)
    	{
    		(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","vmf_trace_persistent_2_shm","p_shm = NULL!");
    		vmf_ret = VMF_ERR_NULL_POINTER;
    	}
    	else if (NULL == p_pers)
    	{
    		(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","vmf_trace_persistent_2_shm","p_pers = NULL!");
    		vmf_ret = VMF_ERR_NULL_POINTER;
    	}
    	else
    	{

    	}
    }

    if(VMF_OK == vmf_ret)
    {
    	VMF_TRACE_INFO_PRINT("vmf_trace_persistent_2_shm() .name=%s, trid_name=%s, trid=%d",p_pers->task[trid].name,trid_name,trid);

    	#ifdef SHM_TEST
    	if (strncmp(p_pers->task[trid].name,trid_name,MAX_TRACE_NAME_LEN)==0)
    	{
    		(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_trace_server","vmf_trace_persistent_2_shm","shm OK");
    	}
    	else
    	{
    		(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","vmf_trace_persistent_2_shm","shm inconsistent");
    		return VMF_ERROR;
    	}
    	#endif


    	/* check if entry for this trid_name is present in persistent data */
    	for (cnt=0; cnt < MAX_VMF_TRACE_TRIDS ;cnt++)
    	{
    		VMF_TRACE_INFO_PRINT("vmf_trace_persistent_2_shm() compare with %s\n",p_pers->task[cnt].name);

        	#if 0
    		(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_11,"vmf_trace_server","vmf_trace_persistent_2_shm","cmp pername:%s with %s",p_pers->task[cnt].name,trid_name);
        	#endif
    		/* precheck for speedup  */
    		if ((p_pers->task[cnt].name[0] == trid_name[0]) &&
    				(p_pers->task[cnt].name[1] == trid_name[1]))
    		{
    			unsigned32 msg_num;
    			/* compare*/
    			ret = strncmp(p_pers->task[cnt].name,trid_name,MAX_TRACE_NAME_LEN);
    			if (ret == 0)
    			{
    				/* found entry */
    				/* copy persistent trid entry to shm */
    				msg_num = p_shm->task[trid].msg_num;            /* get the message counter */
    				p_shm->task[trid]=p_pers->task[cnt];
    				p_shm->task[trid].msg_num = msg_num;            /* clear the message counter */
    				VMF_TRACE_INFO_PRINT("vmf_trace_persistent_2_shm() found entry %s\n",trid_name);

    				break;
    			}
    		}
    	}
    	vmf_ret = VMF_OK;
    }

    return vmf_ret;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_trace_ini_severity_2_shm()
 *
 *   Description:   set severity from to to shm
 *
 *   Parameters:    trid pointing to shared mem
 *                  pointer to shared mem
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_trace_ini_severity_2_shm(unsigned8 trid, vmf_trace_shm_t* p_shm)
{
    vmf_ret_t ret_val = VMF_OK;
    unsigned8 i;

    if (NULL == p_shm)
    {
    	(void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_trace_server","vmf_trace_ini_severity_2_shm","p_shm = NULL!");
    	ret_val = VMF_ERR_NULL_POINTER;
    } else {
    	for (i=0; i<vmf_ini_trace_severities_count; i++)
    	{
    		if (0 == strncmp(vmf_ini_trace_severities[i].name, p_shm->task[trid].name, MAX_TRACE_NAME_LEN))
    		{
    			p_shm->task[trid].severity = vmf_ini_trace_severities[i].severity;
    			break;
    		}
    	}
    }
    
    return ret_val;
}






/**************************************************************************//**
 *
 *   Function Name: vmf_trace_msg_collector()
 *
 *   Description:   collect some vmf_messages and add them to one big vmf message
 *                  send message after fixed timeout
 *   Parameters:
 *   \param[in]     p_shm               pointer to persistent memory
 *   \param[in]     vmf_trace_tx_cid    cid used to transmit the vmf message
 *   \param[in]     pvm_msg             pointer to incoming vmf message
 *
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_trace_msg_collector(vmf_trace_shm_t* p_shm,vmf_client_id_t vmf_trace_tx_cid,vmf_msg_t *pvm_msg,unsigned16 vmf_msg_len)
{
    static  VMF_VAR_BASIC_MSG_TYP(VMF_TRACE_MSG_LEN) vmf_collector_msg;
    static  vmf_trace_pl_t *last_trace_message = NULL;
    static  vmf_trace_pl_t *current_trace_message;
    static  unsigned16      current_trace_message_len;
    static  unsigned32      last_tx_time = 0;
    static  bool            init_done = false;
    static  vmf_handle_t    startup_q_tx = VMF_HANDLE_INVALID;
    static  vmf_handle_t    startup_q_rx = VMF_HANDLE_INVALID;
    static  unsigned32      q_msgs = 0;
    static  unsigned16      startup_q_len=0;
    static  bool b_informed = false;
            bool            transfer_msg = false;
            vmf_ret_t       vmf_ret;

    /* init collector vmf message */
    if (!init_done)
    {
        VMF_TRACE_SERVER_INFO_PRINT2("vmf_trace_msg_collector init!");
        vmf_collector_msg.data.length = 0;
        init_done = true;
        if (p_shm->gl_startup_q)
        {
            VMF_TRACE_SERVER_INFO_PRINT2("vmf_trace_msg_collector create the startup Q '%s'",VMF_TRACE_STARTUP_Q);

            /* create the startup Q */
            startup_q_rx = nw_vmf_ipc_create(VMF_TRACE_STARTUP_Q, VMF_TRACE_QUEUE_SIZE,sizeof(VMF_VAR_BASIC_MSG_TYP(VMF_TRACE_MSG_LEN)));
            if (VMF_HANDLE_INVALID == startup_q_rx)
            {
                /* we got a problem creating the Q - so disable startup queueing */
                p_shm->gl_startup_q = false;
                VMF_TRACE_SERVER_ERROR_PRINT("vmf_trace_msg_collector error creating startup queue");
            }
            else
            {
                #define DSP_STARTUPQ_MSG
                #ifdef DSP_STARTUPQ_MSG
                VMF_TRACE_SERVER_INFO_PRINT2("%ums VMF-Trace Server: startup msg-queue activated ipc-hanlde=%d",(unsigned)vmf_trace_get_time_in_ms(),startup_q_rx);
                #else
                (void)vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_trace_server","vmf_trace_msg_collector","startup msg-queue activated");
                #endif

                #if VMF_IPC_TYPE == VMF_CTRL_IPC_SHM
                //#ifdef VMF_IPC_SHM
                (void)nw_vmf_ipc_register_queue_name   (startup_q_rx,"startup queue");
                #endif
            }
            /* the open function is only called to set queue to non-blocking */
            startup_q_tx =  nw_vmf_ipc_open (VMF_TRACE_STARTUP_Q, IPC_NON_BLOCKING);
            if (VMF_HANDLE_INVALID == startup_q_tx)
            {
                /* we got a problem creating the Q - so disable startup queueing */
                p_shm->gl_startup_q = false;
                VMF_TRACE_SERVER_ERROR_PRINT("vmf_trace_msg_collector error opening startup queue");
            }
        }
    }

    if (NULL != pvm_msg)
    {
        /* check if vmf message is valid */
        if (pvm_msg->vmf_basic_msg.data.length > VMF_CLIENT_DATA_SIZE_BIG)
        {
            /* invalid message */
            VMF_TRACE_SERVER_INFO_PRINT("vmf_trace_msg_collector ignore message because vmf message size > VMF_CLIENT_DATA_SIZE_BIG");
            return VMF_ERR_OUT_OF_RANGE;
        }


        VMF_TRACE_SERVER_INFO_PRINT ("vmf_trace_server: vmf_trace_msg_collector() collected data=%d bytes",vmf_collector_msg.data.length);
        /* check if message will fit into the collector buffer */
        if ((vmf_collector_msg.data.length + pvm_msg->vmf_basic_msg.data.length) >= COLLECTOR_BUFFER_LEN)
        {
            /* the message will not fit into the collector buffer */
            /* so send collector bufer before storing message     */
            VMF_TRACE_SERVER_INFO_PRINT ("vmf_trace_server: vmf_trace_msg_collector() -- collector full!");
            transfer_msg = true;
        }
    }
    else
    {
#if 0
        VMF_TRACE_SERVER_INFO_PRINT ("vmf_trace_server: vmf_trace_msg_collector() pvm_msg=NULL");
#endif
    }

    /* check transfer time only if viewer is connected */
    if (viewer_connected)
    {
        /* check if it is time to send the message */
        if ((vmf_trace_get_time_in_ms()-last_tx_time) > COLLECTOR_TX_TIMEOUT)
        {
            // VMF_TRACE_INFO_PRINT ("vmf_trace_server: vmf_trace_msg_collector() timeout.\n");
            transfer_msg = true;
        }
    }

    /* check if collector message has to be transfered  */
    if (transfer_msg)
    {
        if (vmf_collector_msg.data.length > 0)
        {
            /* send collected message-buffer to server */
            vmf_collector_msg.msg_base.id.group = VMF_TRACE_OUT;
            VMF_BASIC_MSG_GROUP_ID(&vmf_collector_msg) = VMF_TRACE_OUT;
            VMF_BASIC_MSG_EVENT_ID(&vmf_collector_msg) = VMF_TRACE_MSG_TYPE_TEXT;

            /* mark last trace message as VMF_TRACE_PL_LAST_MSG */
            if (NULL != last_trace_message)
            {
                VMF_TRACE_INFO_PRINT("vmf_trace_server: vmf_trace_msg_collector() mark last message");
                last_trace_message->sequence_type = VMF_TRACE_PL_LAST_MSG;
            }
            else
            {
                VMF_TRACE_SERVER_ERROR_PRINT ("vmf_trace_server: vmf_trace_msg_collector() last_trace_message=NULL");
            }

            /* check if message has to be stored in startup Q or send direct to windows client */
            if (p_shm->gl_startup_q)
            {
                /* store message in startup queue */
                static unsigned16 tx_num = 0;
                unsigned16      u_len;
                startup_q_len++;

                /* get message length */
                u_len = VMF_BASIC_MSG_LEN(vmf_collector_msg.data.length);

                /* send msg to startup Q */
                tx_num++;
                VMF_TRACE_SERVER_INFO_PRINT2 ("vmf_trace_server: send msg with len %d to startup queue %d",u_len,tx_num);

                vmf_ret = nw_vmf_ipc_send (startup_q_tx,(unsigned8*)&vmf_collector_msg, u_len);
                (void)vmf_trace_msg_check_plausibility("send to startup q - ",(vmf_msg_t*)&vmf_collector_msg);
                VMF_TRACE_SERVER_INFO_PRINT ("vmf_trace_server: vmf_trace_msg_collector() send to startup queue returned %d",vmf_ret);

                if (VMF_OK != vmf_ret)
                {
                    /* startup queue is full */
                    /* ignore it by now */
                    if (false == b_informed)
                    {
                        VMF_TRACE_SERVER_ERROR_PRINT ("vmf_trace_server: vmf_trace_msg_collector() startup Q full");
                        b_informed = true;
                    }
                }
            }
            else
            {
                /* send message to vmf server */
                VMF_TRACE_SERVER_INFO_PRINT ("vmf_trace_server: send msg with len %d to VMF",vmf_collector_msg.data.length);
                (void)vmf_trace_msg_check_plausibility("send to vmf - ",(vmf_msg_t*)&vmf_collector_msg);
                vmf_ret = nw_vmf_send_basic (vmf_trace_tx_cid,(vmf_basic_msg_t*)&vmf_collector_msg);
                if (vmf_ret != VMF_OK)
                {
                    /* This error output will probably never reach its target but we tried... */
                    VMF_TRACE_SERVER_ERROR_PRINT ("vmf_trace_server: vmf_send_basic() failed!");
                }
                q_msgs=0;
            }

            last_tx_time = vmf_trace_get_time_in_ms();
            vmf_collector_msg.data.length = 0;
        }
        else
        {
            /* no data to transmit */
            last_tx_time = vmf_trace_get_time_in_ms();
        }
    }

    /* add trace message to collector message */
    if ((vmf_msg_len > 0) && (NULL != pvm_msg))
    {
        unsigned8 *dest_ptr;

        /* get trace message */
        current_trace_message     = (vmf_trace_pl_t*)pvm_msg->vmf_basic_msg.data.pl;
        current_trace_message_len = pvm_msg->vmf_basic_msg.data.length;

        /* message is by now not the last message */
        current_trace_message->sequence_type = VMF_TRACE_PL_MSG;

        /* copy to collector message */
        dest_ptr = &(vmf_collector_msg.data.pl[vmf_collector_msg.data.length]);

        last_trace_message = (vmf_trace_pl_t*)dest_ptr; /* store last trace message */
        memcpy(dest_ptr,(void*)current_trace_message,current_trace_message_len);
        vmf_collector_msg.data.length += current_trace_message_len;
        q_msgs++;
        VMF_TRACE_SERVER_INFO_PRINT("vmf_collector_msg.data.length=%d",vmf_collector_msg.data.length);
    }

    /* check if there are messages in the startup queue to send to vmf */
    if (p_shm->gl_startup_q && viewer_connected)
    {
        VMF_VAR_BASIC_MSG_TYP(VMF_TRACE_MSG_LEN) q_msg;
        unsigned16  uReadSize=0;
        static unsigned16 ucount=0;

        /* read message from startup Q */
        vmf_ret = nw_vmf_ipc_timed_receive (startup_q_rx,sizeof(q_msg),(unsigned8 *)&q_msg,&uReadSize,2);
        if ( (vmf_ret != VMF_OK) || ((VMF_OK == vmf_ret) && (0 == uReadSize)) )
        {
        VMF_TRACE_SERVER_INFO_PRINT("vmf_collector: no data in startup Q");
#ifndef VMF_TRACE_KEEP_STARTUP_Q
            /* no more data in queue */
            p_shm->gl_startup_q = false;    /* we are done - startup queue is drained */
                                            /* switch off the queue                   */
            /*
            vmf_trace_printf(vmf_trace_svr_trid,VMF_TRACE_SEVERITY_INFO_5,"vmf_trace_server","vmf_trace_msg_collector","Number of messages transfered to Q=%d, q_msgs=%d",ucount,q_msgs);
            */
            /* delete the startup queue */
            VMF_TRACE_SERVER_INFO_PRINT2("%ums VMF-Trace Server: detelete startup queue",(unsigned)vmf_trace_get_time_in_ms());
            (void) nw_vmf_ipc_close(startup_q_tx);
            (void) nw_vmf_ipc_destroy(startup_q_rx);
#endif
            vmf_tracer_data_in_stq=false;
        }
        else
        {
            /* send message to vmf */
            VMF_TRACE_SERVER_INFO_PRINT("vmf_collector: data in startup Q");
            vmf_tracer_data_in_stq=true;
            ucount++;
            startup_q_len--;
            VMF_TRACE_SERVER_INFO_PRINT("q_msg.data.length=%d",q_msg.data.length);

            (void)vmf_trace_msg_check_plausibility("get from startup queue - ",(vmf_msg_t*)&q_msg);
            vmf_ret = nw_vmf_send_basic (vmf_trace_tx_cid,(vmf_basic_msg_t*)&q_msg);
            if (vmf_ret < 0)
            {
                VMF_TRACE_SERVER_ERROR_PRINT("vmf_trace_msg_collector error sending queued message to vmf");
            }
        }
    }
    return VMF_OK;
}

/**************************************************************************//**
 *
 *   Function Name: vmf_trace_sig_handler
 *
 *   Description:   csignal hanlder that is called if trace task is killed
 *   Parameters:
 *   \param[in]     signal
 *
 *   \return        void
 *
 ******************************************************************************/
#if !defined __WINDOWS__ && !defined INTEGRITY
NW_STATIC void  vmf_trace_sig_handler(int sig)
{
    VMF_TRACE_INFO_PRINT("vmf_trace_sig_handler() signal received=%d\n",sig);

    UNUSED_PARAM(sig);

    /* invalidate shm */
#ifdef CLEAR_SHM
    (void) shm_unlink(VMF_TRACE_SHM);
#endif
    (void) sem_unlink(VMF_TRACE_SEM);
    exit(0);
}
#endif

/**************************************************************************//**
 *
 *   Function Name: getmypid()
 *
 *   Description:   get the pid
 *
 *   Parameters:
 *
 *   Function Return value: - \return void
 *
 ******************************************************************************/
NW_STATIC inline unsigned32 getmypid(void)
{
    static unsigned32 u32myPid = 0;

    if (0 == u32myPid )
    {
        u32myPid= nw_os_getpid();
    }
    return u32myPid;
}




/**************************************************************************//**
 *
 *   Function Name: vmf_trace_msg_collector()
 *
 *   Description:   collect some vmf_messages and add them to one big vmf message
 *                  send message after fixed timeout
 *   Parameters:
 *   \param[in]     p_shm               pointer to persistent memory
 *   \param[in]     vmf_trace_tx_cid    cid used to transmit the vmf message
 *   \param[in]     pvm_msg             pointer to incoming vmf message
 *
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_trace_msg_check_plausibility(char *prefix,vmf_msg_t *pvm_msg)
{
/*    #define CHECK_PLAUSIBILITY */
#ifdef CHECK_PLAUSIBILITY
    vmf_trace_pl_t  *p_trace_msg=NULL;
    unsigned16      vmf_pl_len=0;
    unsigned16      trace_pl_len=0;
    unsigned16      num_trace_msgs=0;
    vmf_ret_t       ret_val = VMF_ERROR;

    if (NULL == pvm_msg)
    {
        return VMF_ERR_NULL_POINTER;
    }
    if (NULL == prefix)
    {
        return VMF_ERR_NULL_POINTER;
    }

    vmf_pl_len = pvm_msg->vmf_basic_msg.data.length;
    p_trace_msg = (vmf_trace_pl_t*)pvm_msg->vmf_basic_msg.data.pl ;

#if 0
    VMF_TRACE_ERROR_PRINT("vmf_trace_msg_check_plausibility: %s msg-pl-len=%d",prefix,vmf_pl_len);
    nw_con_HexDump(prefix,pvm_msg,50);
#endif
    while(true)
    {
        trace_pl_len = p_trace_msg->tpl_len;

        if (0xa0 == p_trace_msg->sequence_type)
        {
            /* valid message */
            num_trace_msgs++;
#if 0
            VMF_TRACE_ERROR_PRINT("vmf_trace_msg_check_plausibility: %s found valid message %d, trace_pl_len=%d",prefix,num_trace_msgs,trace_pl_len);
            nw_con_HexDump("trace_message",p_trace_msg,trace_pl_len>100?100:trace_pl_len);

            VMF_TRACE_ERROR_PRINT("vmf_trace_msg_check_plausibility: found valid message, num trace msgs=%d, vmf_pl_len=%d",num_trace_msgs,vmf_pl_len);
            nw_con_HexDump("vmf_pl",pvm_msg->vmf_basic_msg.data.pl,vmf_pl_len);
#endif
        }
        else if (0xa1 == p_trace_msg->sequence_type)
        {
            /* last message */
            num_trace_msgs++;
            ret_val = VMF_OK;
#if 0
            VMF_TRACE_ERROR_PRINT("vmf_trace_msg_check_plausibility: %s found last message %d, trace_pl_len=%d",prefix,num_trace_msgs,trace_pl_len);
            nw_con_HexDump("trace_message",p_trace_msg,trace_pl_len>100?100:trace_pl_len);

            VMF_TRACE_ERROR_PRINT("vmf_trace_msg_check_plausibility: found last message, num trace msgs=%d, vmf_pl_len=%d",num_trace_msgs,vmf_pl_len);
            nw_con_HexDump("vmf_pl",pvm_msg->vmf_basic_msg.data.pl,vmf_pl_len);
#endif
            break;
        }
        else
        {
            /* invalid message */
            VMF_TRACE_ERROR_PRINT("vmf_trace_msg_check_plausibility: %s found invalid message, num trace msgs=%d, vmf_pl_len=%d",prefix,num_trace_msgs,vmf_pl_len);
            nw_con_HexDump("vmf_pl:",pvm_msg->vmf_basic_msg.data.pl,vmf_pl_len);

            VMF_TRACE_ERROR_PRINT("vmf_trace_msg_check_plausibility: %s found invalid message %d, trace_pl_len=%d",prefix,num_trace_msgs,trace_pl_len);
            nw_con_HexDump("trace_message:",p_trace_msg,(trace_pl_len==0?100:trace_pl_len)>100?100:trace_pl_len);

            ret_val = VMF_ERROR;
            break;
        }
        /* next trace msg */
#if 0
        VMF_TRACE_ERROR_PRINT("next msg: GET_TPL_LEN(p_trace_msg)=%d",GET_TPL_LEN(p_trace_msg));
        VMF_TRACE_ERROR_PRINT("next msg: org trace_msg_addr=%p",p_trace_msg);
        VMF_TRACE_ERROR_PRINT("next msg: new trace_msg_addr=%p",p_trace_msg);
#endif
        p_trace_msg = (vmf_trace_pl_t*)(((char*)p_trace_msg) + GET_TPL_LEN(p_trace_msg));
    }
    return ret_val;

#else /* CHECK_PLAUSIBILITY */
    UNUSED_PARAM(prefix);
    UNUSED_PARAM(pvm_msg);
    return VMF_OK;
#endif /* CHECK_PLAUSIBILITY */

}


