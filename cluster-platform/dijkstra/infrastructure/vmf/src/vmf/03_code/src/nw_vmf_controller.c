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

  Module:               nw_vmf_controller.c
  Description:          vmf controller

  Project Scope:        All QNX /Linux

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Joachim Becker - 15 August 2012

  Compiler/Assembler:   gcc /qcc
  Target Hardware:      Any

  *****************************************************************************/
#define VMF_CONTROLL_C

/* For unit testing functions must not be declared static! */
#ifdef UNIT_TEST
#warning "*************** UNIT_TEST ON! ********************"
#define NW_STATIC
#else
#define NW_STATIC static
#endif


/* system includes */
#include "intEvtDefs.h"
#include "nw_os_config.h"
#include "nw_vmf_cfg.h"           /* vmf cfg file */
#include "nw_config.h"
#include "nw_vmf.h"
#include "nw_vmf_controller.h"
#include "nw_vmf_debug.h"
#include "nw_vmf_timer.h"
#include "nw_vmf_ipc.h"
#include "nw_vmf_trace.h"
#ifdef VMF_TRACE
#include "nw_vmf_trace_server.h"
#endif

/* defines */
#ifndef VMF_IPC_TYPE
#define VMF_IPC_TYPE    VMF_CTRL_IPC_NOT_SET
#endif

#define VMF_CTRL_SOFT_TIMER         /* use software timer */
#define NUM_ITEMS 1                 /* used for reading/writing pers-data */
#define VMF_REC_TIMOUT      500     /* timout for vmf_timed_receive */

/* global data */
vmf_ctrl_pers_t     pers_data={.pers_version=VMF_CTRL_PERS_VERSION,.vmf_start_q_ena=0};

/* static data */
static vmf_client_id_t     gcid=0;
static bool                timeserver_is_running = false;

#ifdef VMF_TRACE
static unsigned8           gtrid = VMF_TRID_VMF;
#else
static unsigned8           gtrid = 0;
#endif

#ifdef VMF_CTRL_SOFT_TIMER
vmf_ctrl_soft_timer_t      soft_timer_list[MAX_SOFT_TIMER];
unsigned8                  max_used_timer_ix;
bool                       timer_aktive=false;
unsigned16                 current_timer_id = VMF_INVALID_TIMER;
unsigned32                 current_timer_abs_elaps = 0;
#endif

extern bool                vmf_file_system_access;
extern bool                enable_timeserver;
extern bool                enable_timeclient;
extern unsigned16          timeserver_intervall;
extern char                tardis_name[];
extern unsigned32          ms_time_offset;
#ifdef VMF_TRACE
extern vmf_trace_shm_t     *vmf_trace_shm;
#endif
extern unsigned32          vmf_total_message_count;
const char                 MY_CTRL_MONITOR_NAME[] = {'v','m','f', '-','s','e','r','v','e','r',0};

extern bool                vmf_sequence_diagram_enabled;
extern unsigned8           vmf_sequence_diagram_pl_used;

/* debug macros */
#define VMF_TRACE_CTRL_ERROR_PRINT(args...)      fprintf(ERROR_CHANNEL,"error:");fprintf(ERROR_CHANNEL,args);fprintf(ERROR_CHANNEL,"\n");delay(100);
#define VMF_TRACE_CTRL_INFO_PRINT(args...)       // fprintf(ERROR_CHANNEL,"error:");fprintf(ERROR_CHANNEL,args);fprintf(ERROR_CHANNEL,"\n");delay(100);


/* local function declarations */
#ifndef VMF_CTRL_SOFT_TIMER
NW_STATIC void      nw_vmf_ctrl_timer_cb(unsigned32 system_time_ms,void *arg);
#endif
NW_STATIC void     *nw_vmf_controller_handler(void *pNoArg);
NW_STATIC vmf_ret_t nw_vmf_controller_cmd_decoder(vmf_basic_msg_t *pmsg,unsigned16 len);
NW_STATIC vmf_ret_t nw_vmf_ctrl_enable_spy_queue(vmf_basic_msg_t *pmsg);
NW_STATIC vmf_ret_t nw_vmf_ctrl_write_pers_data(void);
NW_STATIC vmf_ret_t nw_vmf_ctrl_disable_spy_queue(vmf_basic_msg_t *pmsg);
NW_STATIC vmf_ret_t nw_vmf_ctrl_version_string_response(vmf_basic_msg_t *pmsg);
NW_STATIC vmf_ret_t nw_vmf_ctrl_vmf_info_response(vmf_basic_msg_t *pmsg);
NW_STATIC vmf_ret_t nw_vmf_ctrl_display_pers_data(void);
NW_STATIC vmf_ret_t nw_vmf_ctrl_get_next_elaps_timer_val(unsigned32 *pabs_time);
NW_STATIC void      nw_vmf_ctrl_set_time_offset(unsigned32 ms_timeserver);
NW_STATIC vmf_ret_t nw_vmf_ctrl_monitor (vmf_ctrl_monitoring_req_t *p_vmf_ctrl_monitoring_req);


#ifdef VMF_CTRL_SOFT_TIMER
NW_STATIC void      nw_vmf_ctrl_timers_init(void);
NW_STATIC vmf_ret_t nw_vmf_ctrl_timer_send_event(unsigned8 soft_timer_nr);
NW_STATIC void      nw_vmf_ctrl_timer_send_elapsed(unsigned32 system_time_ms,void *ignore);
NW_STATIC vmf_ret_t nw_vmf_ctrl_timer_add(unsigned8 event, unsigned8 group, unsigned16 rel_time,vmf_ctrl_start_timer_pl_t *pl);
#endif


/*************************************************************************//**
 *   global functions
 ******************************************************************************/


/**************************************************************************//**
 *
 *   Function Name: vmf_nw_status_create_thread
 *
 *   Description:   create the nw-status Handler Task
 *
 *   \param         void
 *   \return        bool - true if OK
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_controller_create_thread(void)
{
    int             iRet;
    vmf_ret_t       vmf_ret=VMF_OK;
    pthread_t       th;
    pthread_attr_t  attr;
    struct sched_param param;
	char Thread_name[100];

    /* set thread stack */
    (void) pthread_attr_init( &attr );
    (void) pthread_attr_setschedpolicy (&attr, SCHED_RR);

    #ifndef __ANDROID__
    if ( pthread_attr_setstacksize(&attr, VMF_CTRL_STACK_SIZE ) != 0 )
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_controller_create_thread() - pthread_attr_setstacksize() failed");
    }
    #endif

    #ifdef INTEGRITY
    (void)pthread_attr_setthreadname(&attr, "vmf ctrl");
    #endif

    (void)pthread_attr_getschedparam (&attr, &param );      /* NOTE QNX does have a param.sched_curpriority which we don't want to touch! */
    param.sched_priority = 10;
    (void)pthread_attr_setschedparam (&attr, &param );

    (void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );
    iRet = pthread_create (&th  , &attr, nw_vmf_controller_handler, NULL);
    (void) pthread_attr_destroy(&attr);
    if (iRet)
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_controller_create_thread() error! errno = %d\n",iRet);
        //perror("nw_vmf_controller_create_thread() error");
        vmf_ret=VMF_ERROR;
    }
    else
    {
#if ((defined(__QNX__) && (_NTO_VERSION >= 632)) || defined(__LINUX__))	
    /* Name the nw-vmf-controller-thread  */
	sprintf(Thread_name, "Vmf-Controller-%d", th);
	nw_os_set_thread_name(th, Thread_name);    
#endif
    }

    return vmf_ret;
}



/*************************************************************************//**
 *
 *   Function Name: nw_vmf_controller_is_spy_queue_enabled
 *
 *   Description:   returns true is spy queue is enabled
 *
 *   \param[in]     void
 *   \return        bool
 *
 ******************************************************************************/
bool nw_vmf_controller_is_spy_queue_enabled(void)
{
    bool bRet = true;
    
    if (0 == pers_data.vmf_start_q_ena)
    {
        bRet = false;
    }

    return bRet;
}


/*************************************************************************//**
 *
 *   Function Name: nw_vmf_controller_tx_timesync
 *
 *   Description:   send a time-sync message with the current time
 *
 *   \param[in]     void
 *   \return        bool
 *
 ******************************************************************************/
void nw_vmf_controller_tx_timesync(void)
{
    VMF_CTRL_DEBUG_INFO(gtrid,"nw_vmf_controller_tx_timesync()","entry");
    if (enable_timeserver != false)
    {
    /* create and send time sync message */
        VMF_VAR_BASIC_MSG_TYP(sizeof(vmf_ctrl_time_sync_t))    vmf_basic_msg;
        unsigned16           pl_len=0;
        unsigned32           current_time;
        vmf_ctrl_time_sync_t pl={0};

        VMF_CTRL_DEBUG_INFO(gtrid,"nw_vmf_controller_start_timesync()","send VMF_TRACE_CTRL_TIME_SYNC message");
        pl_len       =  sizeof(vmf_ctrl_time_sync_t) - sizeof(pl.server_name);
        current_time = nw_os_cfg_get_ms_time();
        pl.time_ll   = (unsigned8)(current_time  & 0xff);
        pl.time_lh   = (unsigned8)((current_time & 0xff00) >> 8);
        pl.time_hl   = (unsigned8)((current_time & 0xff0000) >> 16);
        pl.time_hh   = (unsigned8)((current_time & 0xff000000) >> 24);
        if (0 != tardis_name[0])
        {
            /* add tardis name to payload */
            nw_os_sstrncpy((pl.server_name), tardis_name, sizeof(pl.server_name));
            pl_len += strlen(tardis_name) + 1;
        }

        memcpy(vmf_basic_msg.data.pl,&pl,sizeof(vmf_ctrl_time_sync_t));
        vmf_basic_msg.msg_base.id.event = VMF_TRACE_CTRL_TIME_SYNC;
        vmf_basic_msg.msg_base.id.group = VMF_TRACE_CTRL;
        vmf_basic_msg.data.length = pl_len;
        (void)nw_vmf_send_basic(gcid,(vmf_basic_msg_t*)&vmf_basic_msg);
    }
}

/*************************************************************************//**
 *
 *   Function Name: nw_vmf_controller_start_timesync
 *
 *   Description:   start the time sync server
 *
 *   \param[in]     void
 *   \return        bool
 *
 ******************************************************************************/
void nw_vmf_controller_start_timesync(void)
{
    VMF_CTRL_DEBUG_INFO(gtrid,"nw_vmf_controller_start_timesync()","entry");
    if (enable_timeserver != false)
    {
        if (false == timeserver_is_running)
        {
            VMF_VAR_BASIC_MSG_TYP(0)    vmf_basic_msg;

            VMF_CTRL_DEBUG_INFO(gtrid,"nw_vmf_controller_start_timesync()","send VMF_TRACE_CTRL_TIME_INTERNAL message");
            vmf_basic_msg.msg_base.id.event = VMF_TRACE_CTRL_TIME_INTERNAL;
            vmf_basic_msg.msg_base.id.group = VMF_TRACE_CTRL;
            vmf_basic_msg.data.length=0;

            (void)nw_vmf_send_basic(gcid,(vmf_basic_msg_t*)&vmf_basic_msg);
        }
        else
        {
            VMF_CTRL_DEBUG_INFO(gtrid,"nw_vmf_controller_start_timesync()","timeserver_is_running=true");
        }
    }
    else
    {
        VMF_CTRL_DEBUG_INFO(gtrid,"nw_vmf_controller_start_timesync()","enable_timeserver=false");
    }
}




/*************************************************************************//**
 *   local functions
 ******************************************************************************/


/**************************************************************************//**
 *
 *   Function Name: vmf_nw_controller_handler(uint32_T ulContext)
 *
 *   Description:   vmf controller thread
 *
 *   \param         void
 *   \return        void
 *
 ******************************************************************************/
NW_STATIC void *nw_vmf_controller_handler(void *pNoArg)
{
    vmf_client_id_t     vmf_client_id=0;
    vmf_ret_t           vmf_ret=VMF_OK;
    unsigned8           groupid_list[]={VMF_TRACE_CTRL, VMF_TRACE_SYSINFO_CTRL};

    UNUSED_PARAM(pNoArg);

    /* register to the VMF server - wait for connection */
    while (FOREVER)
    {
        /* try to connect to vmf-server */
        vmf_client_id = nw_vmf_connect(  VMF_CTRL_CON_NAME, NULL,0,VMF_CLIENT_QUEUE_SIZE_STANDARD,VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD );
        if (vmf_client_id <= 0)
        {
            delay(WAIT_SOME_TIME);
        }
        else
        {
            /* connected */
            break;
        }
    }
    gcid = vmf_client_id;

    /* register to trace server */
    VMF_TRACE_CTRL_INFO_PRINT("nw_vmf_controller_handler() VMF_TRACE_REGISTER %s\n",VMF_TRACE_TRID_NAME);
#ifdef VMF_TRACE
    if (VMF_TRACE_REGISTER(&gtrid , VMF_TRACE_TRID_NAME) < 0)
    {
         NW_VMF_DEBUG_ERROR("nw_vmf_controller_handler: CANNOT CONNECT TO VMF TRACER!!!");
    }
#endif
    VMF_CTRL_DEBUG_INFO(gtrid,VMF_TRACE_CONTROLLER,"thread started");

    VMF_TRACE_CTRL_INFO_PRINT("nw_vmf_controller_handler() gtrid=%d\n",gtrid);

    /* read persistent data */
    vmf_ret = nw_vmf_ctrl_read_pers_data();
    if (vmf_ret != VMF_OK)
    {
        VMF_CTRL_DEBUG_WARNING(gtrid,VMF_TRACE_CONTROLLER,"vw_vmf_ctrl_read_pers_data failed");
        (void)nw_vmf_ctrl_write_pers_data();      /* write defaut set of persistent data */
    }

    /* register VMF-message groups */
    vmf_ret = nw_vmf_register_msg_group(vmf_client_id,sizeof(groupid_list),groupid_list);
    if (vmf_ret != VMF_OK)
    {
        VMF_CTRL_DEBUG_ERROR(gtrid,VMF_TRACE_CONTROLLER,"nw_vmf_register_msg_group() failed\n");
    }

#ifdef VMF_CTRL_SOFT_TIMER
    nw_vmf_ctrl_timers_init();
#endif

    /* start time server if enabled */
    nw_vmf_controller_start_timesync();

    /* main reception loop */
    VMF_CTRL_DEBUG_INFO2(gtrid,VMF_TRACE_CONTROLLER,"enter main loop");
    VMF_CTRL_DEBUG_DEBUG(gtrid,VMF_TRACE_CONTROLLER,VMF_TRACE_SEVERITY_INFO,VMF_OS_STRING " " VMF_VERSION_STRING " " IPC_VERSION_STRING);
    while (FOREVER)
    {
        vmf_msg_t   vmf_msg;
        unsigned16  numBytes;

        vmf_ret = nw_vmf_timed_receive(vmf_client_id,&vmf_msg,sizeof(vmf_msg),VMF_REC_TIMOUT);
        #ifdef VMF_TRACE
        if (vmf_trace_shm != NULL)
        {
            vmf_trace_shm->task[0].msg_num++;
        }
            #endif
        if (vmf_ret > 0)
        {
            numBytes = (unsigned16)vmf_ret;
            vmf_ret = nw_vmf_controller_cmd_decoder((vmf_basic_msg_t *)&vmf_msg,numBytes);
            if (vmf_ret != VMF_OK)
            {
                VMF_CTRL_DEBUG_ERROR(gtrid,VMF_TRACE_CONTROLLER,"nw_vmf_controller_cmd_decoder() failed with %d\n",vmf_ret);
            }
        }
        else
        {
            /* we got a vmf-receive error - or timeout */
            delay(10);
        }
    }

    return NULL;
}




/**************************************************************************//**
 *
 *   Function Name: vmf_nw_controller_cmd_decoder(uint32_T ulContext)
 *
 *   Description:   vmf controller thread
 *
 *   \param         pmsg        ; vmf basic message with controll cmd
 *   \param         pmsg        ; size of vmf message

 *   \return        vmf_ret_t
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t nw_vmf_controller_cmd_decoder(vmf_basic_msg_t *pmsg,unsigned16 len)
{
    vmf_ret_t   vmf_ret=VMF_OK;     /* ignore unknown events */

    /* argument check */
    if (0 == len)
    {
        vmf_ret = VMF_ERR_OUT_OF_RANGE;
    }
    else if (NULL == pmsg)
    {
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else
    {
        if (pmsg->msg_base.id.group == VMF_TRACE_CTRL)
        {
            switch(pmsg->msg_base.id.event)
            {
                case VMF_CTRL_START_TIMER:
                {
                    #ifdef VMF_CTRL_SOFT_TIMER
                    vmf_ctrl_start_timer_pl_t  *ppayload;
                    unsigned16                  ms_time=0;

                    ppayload = (vmf_ctrl_start_timer_pl_t*)pmsg->data.pl;
                    ms_time = (ppayload->ms_time_h << 8) + ppayload->ms_time_l;

                    vmf_ret = nw_vmf_ctrl_timer_add(ppayload->event, ppayload->group,ms_time,ppayload);
                    if (vmf_ret != VMF_OK)
                    {
                        VMF_CTRL_DEBUG_ERROR(gtrid,VMF_TRACE_CONTROLLER,"vmf_ctrl_timer_add() failed with %d\n",vmf_ret);
                    }
                    
                    #else
                    unsigned16 vmf_timer_id=0;
                    unsigned16 ms_time=0;
                    unsigned32 arg=0;
                    vmf_ctrl_start_timer_pl_t  *ppayload;

                    ppayload = (vmf_ctrl_start_timer_pl_t*)pmsg->data.pl;
                    ms_time = (ppayload->ms_time_h << 8) + ppayload->ms_time_l;
                    arg = (ppayload->group << 8) + ppayload->event;

                    VMF_CTRL_DEBUG_INFO(gtrid,VMF_TRACE_CONTROLLER,"VMF_TRACE_CTRL_START_TIMER %dms\n",ms_time);
                    vmf_ret = vmf_timer_start (&vmf_timer_id, ms_time, nw_vmf_ctrl_timer_cb,(void *)arg);
                    if (vmf_ret != VMF_OK)
                    {
                        VMF_CTRL_DEBUG_ERROR(gtrid,VMF_TRACE_CONTROLLER,"vmf_timer_start() failed with %d\n",vmf_ret);
                    }
                    #endif
                }
                break;

                case VMF_CTRL_VMF_INFO_REQUEST:
                {
                    vmf_ret = nw_vmf_ctrl_vmf_info_response(pmsg);
                    if (vmf_ret != VMF_OK)
                    {
                        VMF_CTRL_DEBUG_ERROR(gtrid,VMF_TRACE_CONTROLLER,"nw_vmf_ctrl_vmf_info_response() failed with %d\n",vmf_ret);
                    }

                    vmf_ret = nw_vmf_ctrl_version_string_response(pmsg);
                    if (vmf_ret != VMF_OK)
                    {
                        VMF_CTRL_DEBUG_ERROR(gtrid,VMF_TRACE_CONTROLLER,"nw_vmf_ctrl_version_string_response() failed with %d\n",vmf_ret);
                    }
                    VMF_CTRL_DEBUG_DEBUG(gtrid,VMF_TRACE_CONTROLLER,VMF_TRACE_SEVERITY_INFO,VMF_OS_STRING " " VMF_VERSION_STRING " " IPC_VERSION_STRING);
                }
                break;

                case VMF_CTRL_VMF_ENABLE_SPY_QUEUE:
                {
                    /* enable the vmf startup queue for spy messages */
                    vmf_ret = nw_vmf_ctrl_enable_spy_queue(pmsg);
                    if (vmf_ret != VMF_OK)
                    {
                        VMF_CTRL_DEBUG_ERROR(gtrid,VMF_TRACE_CONTROLLER,"nw_vmf_ctrl_enable_spy_queue() failed with %d\n",vmf_ret);
                    }
                    vmf_ret = nw_vmf_ctrl_vmf_info_response(pmsg);
                    if (vmf_ret != VMF_OK)
                    {
                        VMF_CTRL_DEBUG_ERROR(gtrid,VMF_TRACE_CONTROLLER,"nw_vmf_ctrl_vmf_info_response() failed with %d\n",vmf_ret);
                    }
                }
                break;

                case VMF_CTRL_VMF_DISABLE_SPY_QUEUE:
                {
                    /* disable the vmf startup queue for spy messages */
                    vmf_ret = nw_vmf_ctrl_disable_spy_queue(pmsg);
                    if (vmf_ret != VMF_OK)
                    {
                        VMF_CTRL_DEBUG_ERROR(gtrid,VMF_TRACE_CONTROLLER,"nw_vmf_ctrl_disable_spy_queue() failed with %d\n",vmf_ret);
                    }
                    vmf_ret = nw_vmf_ctrl_vmf_info_response(pmsg);
                    if (vmf_ret != VMF_OK)
                    {
                        VMF_CTRL_DEBUG_ERROR(gtrid,VMF_TRACE_CONTROLLER,"nw_vmf_ctrl_vmf_info_response() failed with %d\n",vmf_ret);
                    }
                }
                break;

                case VMF_TRACE_CTRL_TIME_INTERNAL:
                {
                    vmf_ctrl_start_timer_pl_t  payload={0};

                    if (enable_timeserver != false)
                    {
                        timeserver_is_running = true;

                        /* start a new timer */
                        (void)nw_vmf_ctrl_timer_add(VMF_TRACE_CTRL_TIME_INTERNAL, VMF_TRACE_CTRL,timeserver_intervall*1000, &payload);

                        /* send time sync message */
                        nw_vmf_controller_tx_timesync();
                    }
                }
                break;

                case VMF_TRACE_CTRL_TIME_SYNC:
                    if (false == enable_timeserver)
                    {
                        /* never sync time if this is the time-server !*/
                        if (enable_timeclient!= false)
                        {
                            unsigned32 server_time_ms;
                            vmf_ctrl_time_sync_t    *p_server_time;

                            /* time sync message */
                            /* set timer offset for this core */
                            p_server_time = (vmf_ctrl_time_sync_t*)NW_VMF_BASIC_MSG_DATA_PTR(pmsg);
                            server_time_ms = p_server_time->time_ll + (p_server_time->time_lh * 256) + (p_server_time->time_hl * (256*256)) + (p_server_time->time_hh * (256*256*256));
                            nw_vmf_ctrl_set_time_offset(server_time_ms);
                        }
                    }
                break;

                case VMF_TRACE_CTRL_TIME_REQ:
                    /* send time sync message */
                    nw_vmf_controller_tx_timesync();
                break;

                case VMF_CTRL_MONITOR_REQUEST:
                    /* simple monitoring -- first version (to be improved!) */
                    {
                        vmf_ctrl_monitoring_req_t *p_vmf_ctrl_monitoring_req = (vmf_ctrl_monitoring_req_t*)pmsg->data.pl;
                        (void) nw_vmf_ctrl_monitor(p_vmf_ctrl_monitoring_req);
                    }
                break;

                case VMF_CTRL_SEQ_DIAGRAM_ENABLE:
                    /* enable/disable sending data for sequence diagrams */
                    if (1 == pmsg->data.length)
                    {
                        if (1 == pmsg->data.pl[0])
                        {
                            vmf_sequence_diagram_enabled = VMF_TRUE;
                            vmf_sequence_diagram_pl_used = 0;
                            (void) fprintf(stdout, "Sequence Diagrams ENABLED\n");
                        }
                        else
                        {
                            vmf_sequence_diagram_enabled = VMF_FALSE;
                            (void) fprintf(stdout, "Sequence Diagrams disabled\n");
                        }
                    }
                break;


                default:
                    /* ignore unknown events */
                    vmf_ret = VMF_OK;
                break;
            }
        }
        else if (VMF_TRACE_SYSINFO_CTRL == pmsg->msg_base.id.group)
        {
            if (VMF_IPC_STATUS_CTRL_START_STOP == pmsg->msg_base.id.event)
            {

                #if VMF_IPC_TYPE == VMF_CTRL_IPC_SHM || VMF_IPC_TYPE == VMF_CTRL_IPC_MQ

                /* payload byte 0: 0 = false / 1 = true */
                if (pmsg->data.pl[0] == 0x00)
                {
                    /* stop if running */
                    if (true == nw_vmf_ipc_is_status_thread_running())
                    {
                        (void) nw_vmf_ipc_stop_status_thread();
                    }
                }
                else
                {
                    /* start if not running */
                    if (false == nw_vmf_ipc_is_status_thread_running())
                    {
                        (void) nw_vmf_ipc_create_status_thread();
                    }
                }
                
                #else
                    VMF_CTRL_DEBUG_ERROR(gtrid,VMF_TRACE_CONTROLLER,"start stop ipc status thread NOT supported!!");
                #endif
                
            }
            else
            {
                /* ignore all other events */
                vmf_ret = VMF_OK;
            }
        }
    }

    return vmf_ret;
}


#ifndef VMF_CTRL_SOFT_TIMER
/*************************************************************************//**
 *
 *   vmf-controller timer callback
 *
 *   \param[in]     system_time_ms  -   time in ms
 *   \param[in]     arg             -   event and group
 *   \return        void
 *
 ******************************************************************************/
NW_STATIC void nw_vmf_ctrl_timer_cb(unsigned32 system_time_ms,void *arg)
{
    unsigned8   group;
    unsigned8   event;
    unsigned32  v_arg;
    VMF_VAR_BASIC_MSG_TYP(0)    vmf_basic_msg;  /* no payload needed */

    /* check if already connected to VMF */
    if (0 != gcid)
    {
        v_arg=(unsigned32)arg;

        /* get event and group from arg */
        event = (unsigned8)(v_arg & 0xff);
        group = (unsigned8)((v_arg >> 8) & 0xff);

        VMF_CTRL_DEBUG_INFO(gtrid,VMF_TRACE_CONTROLLER,"v_arg = %d, event=%d, group=%d\n",v_arg,event,group);

        vmf_basic_msg.msg_base.id.event = event;
        vmf_basic_msg.msg_base.id.group = group;
        vmf_basic_msg.data.length=0;
        (void)nw_vmf_send_basic(gcid,(vmf_basic_msg_t*)&vmf_basic_msg);
    }
}
#endif


/*************************************************************************//**
 *
 *   send the the vmf info response
 *
 *   \param[in]     pmsg  -   vmf basic message
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t nw_vmf_ctrl_vmf_info_response(vmf_basic_msg_t *pmsg)
{
    vmf_ret_t           vmf_ret;
    vmf_ctrl_vmf_info_t vmf_info;
    VMF_VAR_BASIC_MSG_TYP(sizeof(vmf_ctrl_vmf_info_t))    vmf_basic_msg;

    /* argument check */
    if (NULL == pmsg)
    {
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else    
    {
        vmf_ret = nw_vmf_ctrl_create_vmf_info_response(&vmf_info);
    }

    if (VMF_OK == vmf_ret)
    {
        VMF_CTRL_DEBUG_INFO(gtrid,VMF_TRACE_CONTROLLER,"");

        vmf_basic_msg.msg_base.id.event = VMF_CTRL_VMF_INFO_RESPONSE;
        vmf_basic_msg.msg_base.id.group = VMF_TRACE_CTRL;

        vmf_basic_msg.data.length = sizeof(vmf_info);
        nw_os_smemcpy(vmf_basic_msg.data.pl,sizeof(vmf_ctrl_vmf_info_t),&vmf_info,sizeof(vmf_ctrl_vmf_info_t));
        vmf_ret = nw_vmf_send_basic(gcid,(vmf_basic_msg_t*)&vmf_basic_msg);
    }

    return vmf_ret;
}

/*************************************************************************//**
 *
 *   send the the vmf info response
 *
 *   \param[in]     pmsg  -   vmf basic message
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ctrl_create_vmf_info_response(vmf_ctrl_vmf_info_t *pvmf_info)
{
    vmf_ret_t           vmf_ret = VMF_OK;

    /* argument check */
    if (NULL == pvmf_info)
    {
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else
    {
        /* create and send info struct */
        memset(pvmf_info,0,sizeof(vmf_ctrl_vmf_info_t));
        pvmf_info->pl_len_max_l = (unsigned8)(MAX_VMF_DATA_LEN & 0xff);
        pvmf_info->pl_len_max_h = (unsigned8)((MAX_VMF_DATA_LEN >> 8) & 0xff);
        pvmf_info->pl_major_version = (unsigned8)VMF_MAJOR_NUMBER;
        pvmf_info->pl_minor_version = (unsigned8)VMF_MINOR_NUMBER;
        pvmf_info->pl_ipc = (unsigned8)VMF_IPC_TYPE;
        pvmf_info->pl_spy_queue = pers_data.vmf_start_q_ena;

        /* get the os */
        #if defined(__linux__)
            pvmf_info->pl_os = (unsigned8)VMF_CTRL_OS_LINUX;
        #elif defined(__QNX__)
            pvmf_info->pl_os = (unsigned8)VMF_CTRL_OS_QNX;
        #elif defined(__CYGWIN__)
            pvmf_info->pl_os = (unsigned8)VMF_CTRL_OS_CYGWIN;
        #elif defined(__WINDOWS__)
            pvmf_info->pl_os = (unsigned8)VMF_CTRL_OS_WINDOWS;
        #elif defined(INTEGRITY)
            pvmf_info->pl_os = (unsigned8)VMF_CTRL_OS_INTEGRITY;            
        #endif

        /* get the CPU */
        #if defined(__i686 )
            pvmf_info->pl_cpu = (unsigned8)VMF_CTRL_CPU_X86;
        #elif defined(__i386 )
            pvmf_info->pl_cpu = (unsigned8)VMF_CTRL_CPU_X86;
        #elif defined(__arm__)
            pvmf_info->pl_cpu = (unsigned8)VMF_CTRL_CPU_ARM;
        #endif

        #if defined( __ARM_ARCH_4__ )
            pvmf_info->pl_cpu = (unsigned8)VMF_CTRL_CPU_ARM_V4;
        #elif defined( __ARM_ARCH_4T__ )
            pvmf_info->pl_cpu = (unsigned8)VMF_CTRL_CPU_ARM_V4;
        #elif defined( __ARM_ARCH_4TE__ )
            pvmf_info->pl_cpu = (unsigned8)VMF_CTRL_CPU_ARM_V4;
        #endif

        #if defined( __ARM_ARCH_5__)
            pvmf_info->pl_cpu = (unsigned8)VMF_CTRL_CPU_ARM_V5;
        #elif defined( __ARM_ARCH_5T__ )
            pvmf_info->pl_cpu = (unsigned8)VMF_CTRL_CPU_ARM_V5;
        #elif defined( __ARM_ARCH_5TE__ )
            pvmf_info->pl_cpu = (unsigned8)VMF_CTRL_CPU_ARM_V5;
        #endif

    }

    return vmf_ret;
}


/*************************************************************************//**
 *
 *   send the vmf version string
 *
 *   \param[in]     pmsg  -   vmf basic message
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t nw_vmf_ctrl_version_string_response(vmf_basic_msg_t *pmsg)
{
    #define MAX_VERSION_STRING 150
    vmf_ret_t           vmf_ret = VMF_OK;
    char                tmp[MAX_VERSION_STRING+1]={0};
    VMF_VAR_BASIC_MSG_TYP(MAX_VERSION_STRING)    vmf_basic_msg;

    /* argument check */
    if (NULL == pmsg)
    {
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else
    {
        /* send version string */
        (void) snprintf(tmp,sizeof(tmp),VMF_OS_STRING " " VMF_VERSION_STRING " " IPC_VERSION_STRING);
        tmp[MAX_VERSION_STRING]=0;
        vmf_basic_msg.msg_base.id.event = VMF_CTRL_VMF_VERSION_STRING;
        vmf_basic_msg.msg_base.id.group = VMF_TRACE_CTRL;
        vmf_basic_msg.data.length = strlen(tmp);
        nw_os_smemcpy(vmf_basic_msg.data.pl,MAX_VERSION_STRING,tmp,vmf_basic_msg.data.length);

        vmf_ret = nw_vmf_send_basic(gcid,(vmf_basic_msg_t*)&vmf_basic_msg);
    }
    VMF_CTRL_DEBUG_INFO(gtrid,VMF_TRACE_CONTROLLER,"send version string: %s",tmp);

    return vmf_ret;
}




/*************************************************************************//**
 *
 *   enable spy queue
 *
 *   \param[in]     pmsg  -   vmf basic message
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t nw_vmf_ctrl_enable_spy_queue(vmf_basic_msg_t *pmsg)
{
    vmf_ret_t vmf_ret = VMF_OK;

    VMF_CTRL_DEBUG_INFO(gtrid,VMF_TRACE_CONTROLLER,"enable spy queue");

    /* argument check */
    if (NULL == pmsg)
    {
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else
    {
        pers_data.vmf_start_q_ena = 0x01;
        vmf_ret = nw_vmf_ctrl_write_pers_data();
    }

    return vmf_ret;
}



/*************************************************************************//**
 *
 *   disable spy queue
 *
 *   \param[in]     pmsg  -   vmf basic message
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t nw_vmf_ctrl_disable_spy_queue(vmf_basic_msg_t *pmsg)
{
    vmf_ret_t vmf_ret = VMF_OK;

    VMF_CTRL_DEBUG_INFO(gtrid,VMF_TRACE_CONTROLLER,"disable spy queue");

    /* argument check */
    if (NULL == pmsg)
    {
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else
    {
        pers_data.vmf_start_q_ena = 0x00;
        vmf_ret = nw_vmf_ctrl_write_pers_data();
    }

    return vmf_ret;
}



/*************************************************************************//**
 *
 *   write persistent data
 *
 *   \param[in]     void
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t nw_vmf_ctrl_write_pers_data(void)
{
    vmf_ret_t   vmf_ret = VMF_OK;
    FILE        *fp_rw=NULL;
    size_t      written_len;

    VMF_CTRL_DEBUG_INFO(gtrid,VMF_TRACE_CONTROLLER,"write persistent data");

    if (false == vmf_file_system_access)
    {
        VMF_CTRL_DEBUG_WARNING(gtrid,VMF_TRACE_CONTROLLER,"persistent write disabled");
        vmf_ret = VMF_OK;
    }
    else
    {
        fp_rw = fopen( VMF_CTRL_PERSISTENT_DATA, "wb" );
        if(fp_rw != NULL)
        {
            written_len = fwrite( &pers_data, sizeof(vmf_ctrl_pers_t ), NUM_ITEMS, fp_rw);
            if (written_len != NUM_ITEMS)
            {
                VMF_CTRL_DEBUG_ERROR(gtrid,VMF_TRACE_CONTROLLER,"fwrite() failed written_len=%d",written_len);
                perror("fwrite");
                vmf_ret = VMF_ERROR;
            }
            else
            {
                /* write successfull */
                vmf_ret = VMF_OK;
            }
            (void) fclose( fp_rw );
        }
        else
        {
            VMF_CTRL_DEBUG_ERROR(gtrid,VMF_TRACE_CONTROLLER,"fopen(%s) failed",VMF_CTRL_PERSISTENT_DATA);
            vmf_ret = VMF_ERROR;
        }
    }
    return vmf_ret;
}


/*************************************************************************//**
 *
 *   read persistent data
 *
 *   \param[in]     void
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ctrl_read_pers_data(void)
{
    vmf_ret_t       vmf_ret = VMF_OK;
    FILE            *fp_rw=NULL;
    size_t          read_len;
    vmf_ctrl_pers_t l_pers_data;

    VMF_CTRL_DEBUG_INFO(gtrid,VMF_TRACE_CONTROLLER,"read persistent data");

#if 0
    if (false == vmf_file_system_access)
    {
        /* no file system access */
        return VMF_ERROR;
    }
#endif

    fp_rw = fopen( VMF_CTRL_PERSISTENT_DATA, "rb" );

    if(fp_rw != NULL)
    {
        read_len = fread( &l_pers_data, sizeof(vmf_ctrl_pers_t ), NUM_ITEMS, fp_rw);
        if (NUM_ITEMS != read_len)
        {
            /* read error */
            VMF_CTRL_DEBUG_WARNING(gtrid,VMF_TRACE_CONTROLLER,"fread() failed");
            vmf_ret = VMF_ERROR;
        }
        else
        {
            /* read successfull - check version */
            if (l_pers_data.pers_version == VMF_CTRL_PERS_VERSION)
            {
                /* version ok - transfer pers data to global pers data */
                pers_data = l_pers_data;
                (void) nw_vmf_ctrl_display_pers_data();
                vmf_ret = VMF_OK;
            }
            else
            {
                /* invalid persistent version */
                VMF_CTRL_DEBUG_WARNING(gtrid,VMF_TRACE_CONTROLLER,"invalid version per-data - file-version=%d, current version=%d",l_pers_data.pers_version,VMF_CTRL_PERS_VERSION);
                vmf_ret = VMF_ERR_INVALID_VERSION;
            }
        }
        (void) fclose( fp_rw );
    }
    else
    {
        VMF_CTRL_DEBUG_WARNING(gtrid,VMF_TRACE_CONTROLLER,"fopen(%s) failed\n",VMF_CTRL_PERSISTENT_DATA);
        vmf_ret = VMF_ERROR;
    }

    return vmf_ret;
}



/*************************************************************************//**
 *
 *   display persistent data on tracer
 *
 *   \param[in]     void
 *   \return        void
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t nw_vmf_ctrl_display_pers_data(void)
{

    VMF_CTRL_DEBUG_INFO2(gtrid,VMF_TRACE_CONTROLLER,"per-data: version=%d",pers_data.pers_version);
    if (pers_data.vmf_start_q_ena == 0)
    {
        VMF_CTRL_DEBUG_INFO2(gtrid,VMF_TRACE_CONTROLLER,"per-data: spy startup queue disabled");
    }
    else if (pers_data.vmf_start_q_ena == 1)
    {
        VMF_CTRL_DEBUG_INFO2(gtrid,VMF_TRACE_CONTROLLER,"per-data: spy startup queue enabled");
    }
    else
    {
        VMF_CTRL_DEBUG_WARNING(gtrid,VMF_TRACE_CONTROLLER,"per-data: spy startup queue invalid data=%d",pers_data.vmf_start_q_ena);
    }

    return VMF_OK;
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_ctrl_set_time_offset()
 *
 *   Description:   set current timer-offset
 *
 *   Parameters:    time server time in ms
 *
 *   Return value:  \return true if OK
 *
 ******************************************************************************/
static void nw_vmf_ctrl_set_time_offset(unsigned32 ms_timeserver)
{
    unsigned32 curr_time;

    curr_time = nw_os_cfg_get_ms_time_raw();
    ms_time_offset = ms_timeserver - curr_time;

}

/**************************************************************************//**
 *
 *   Function Name: nw_vmf_ctrl_monitor()
 *
 *   Description:   send response to ControlMonitor Tool
 *
 *   Parameters:    pointer to basic message payload containing ctrl monitor request.
 *
 *   Return value:  \return none
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t nw_vmf_ctrl_monitor (vmf_ctrl_monitoring_req_t *p_vmf_ctrl_monitoring_req)
{
    vmf_ret_t vmf_ret = VMF_OK;
    VMF_VAR_BASIC_MSG_TYP(sizeof(vmf_ctrl_monitoring_resp_t))    vmf_response_msg;
    vmf_ctrl_monitoring_resp_t  vmf_ctrl_monitoring_resp;
    static unsigned32  my_msg_count = 0;
    unsigned32 my_msg_count_diff;

    if (NULL == p_vmf_ctrl_monitoring_req)
    {
        /* error -- do nothing */
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else
    {
        if (0 == strncmp((char *)&MY_CTRL_MONITOR_NAME, (char *)&p_vmf_ctrl_monitoring_req->item_name, sizeof(MY_CTRL_MONITOR_NAME)))
        {
            /* calculate message diff */
            if (vmf_total_message_count > my_msg_count)
            {
                my_msg_count_diff = vmf_total_message_count - my_msg_count;
            }
            else
            {
                /* wrap around */
                my_msg_count_diff = sizeof(my_msg_count) - 1 - my_msg_count + vmf_total_message_count;
            }
            my_msg_count = vmf_total_message_count;

            /* copy request into response */
            memset(vmf_ctrl_monitoring_resp.item_name, 0, VMF_MON_ITEM_NAME_LEN);
            nw_os_smemcpy((void *)&vmf_ctrl_monitoring_resp, sizeof(vmf_ctrl_monitoring_resp_t), (void *)p_vmf_ctrl_monitoring_req, sizeof(vmf_ctrl_monitoring_req_t));

            /* set status */
            vmf_ctrl_monitoring_resp.status = VMF_MON_STATUS_GREEN;

            /* set status text */
            memset(vmf_ctrl_monitoring_resp.status_text, 0, VMF_MON_TEXT_LEN);
            (void) sprintf(vmf_ctrl_monitoring_resp.status_text, "Message Count = %d", (int)my_msg_count_diff);
            vmf_ctrl_monitoring_resp.status_text_len = strlen(vmf_ctrl_monitoring_resp.status_text) + 1;

            /* create and send vmf message */
            vmf_response_msg.msg_base.id.group = VMF_TRACE_CTRL;
            vmf_response_msg.msg_base.id.event = VMF_CTRL_MONITOR_RESPONSE;
            vmf_response_msg.data.length = sizeof(vmf_ctrl_monitoring_req_t) + 2 + vmf_ctrl_monitoring_resp.status_text_len;
            nw_os_smemcpy((void *)&vmf_response_msg.data.pl, sizeof(vmf_ctrl_monitoring_resp_t), (void *)&vmf_ctrl_monitoring_resp, vmf_response_msg.data.length);

            vmf_ret = nw_vmf_send_basic(gcid,(vmf_basic_msg_t*)&vmf_response_msg);

        }
    }

    return vmf_ret;
}



#ifdef VMF_CTRL_SOFT_TIMER

/*************************************************************************//**
 *
 *   init the timer-list
 *
 *   \param[in]     void
 *   \return        void
 *
 ******************************************************************************/
NW_STATIC void nw_vmf_ctrl_timers_init(void)
{
    unsigned8  cnt;

    for (cnt=0;cnt<MAX_SOFT_TIMER-1;cnt++)
    {
        soft_timer_list[cnt].in_use = 0;
        soft_timer_list[cnt].pl_len = 0;
    }
    max_used_timer_ix = 0;
}


/*************************************************************************//**
 *
 *   add a timer to the list
 *
 *   \param[in]     void
 *   \return        vmf_ret
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t nw_vmf_ctrl_timer_add(unsigned8 event, unsigned8 group, unsigned16 rel_time,vmf_ctrl_start_timer_pl_t *pl)
{
    unsigned32  current_time = 0;
    unsigned32  timer_abs_time = 0;
    unsigned16  cnt;
    vmf_ret_t   vmf_ret = VMF_ERROR;
    unsigned8   pl_len=0;

    current_time    = nw_os_cfg_get_ms_time();
    timer_abs_time  = current_time + rel_time;

    /* search a free timer */
    for (cnt=0;cnt<MAX_SOFT_TIMER;cnt++)
    {
        if (soft_timer_list[cnt].in_use == 0)
        {
            VMF_CTRL_DEBUG_INFO2(gtrid,VMF_TRACE_CONTROLLER,"found free timer = %d, rel-time=%d, abs-time=%d, current-time=%d",cnt,rel_time,current_time + rel_time,current_time);

            /* found a free timer */
            soft_timer_list[cnt].event = event;
            soft_timer_list[cnt].group = group;
            soft_timer_list[cnt].abs_time = timer_abs_time;
            pl_len = pl->pl_len;
            if (pl_len > MAX_VMF_TIMER_PL)
            {
                soft_timer_list[cnt].pl_len = MAX_VMF_TIMER_PL;
            }
            else
            {
                soft_timer_list[cnt].pl_len = pl_len;
            }
            nw_os_smemcpy(soft_timer_list[cnt].pl,MAX_VMF_TIMER_PL,pl->pl,soft_timer_list[cnt].pl_len);

            soft_timer_list[cnt].in_use = 0x01;
            if (cnt > max_used_timer_ix)
            {
                max_used_timer_ix = cnt;
            }
            if (false == timer_aktive)
            {
                /* no timer running - start new one */
                VMF_CTRL_DEBUG_INFO2(gtrid,VMF_TRACE_CONTROLLER,"start new timer with %dms",rel_time);
                vmf_ret = vmf_timer_start (&current_timer_id, rel_time, nw_vmf_ctrl_timer_send_elapsed,NULL);
                if (VMF_OK == vmf_ret)
                {
                    current_timer_abs_elaps = timer_abs_time;
                    timer_aktive = true;
                }
            }
            else
            {
                /* timer is already running */
                /* test if we ned to re-set the time */
                unsigned32 next_time = 0;

                vmf_ret = nw_vmf_ctrl_get_next_elaps_timer_val(&next_time);
                VMF_CTRL_DEBUG_INFO2(gtrid,VMF_TRACE_CONTROLLER,"found running timer(%d) current_timer_abs_elaps=%d netx-time=%dms, current time=%dms",current_timer_id,current_timer_abs_elaps,next_time,current_time);
                if (VMF_OK == vmf_ret)
                {
                    if (current_timer_abs_elaps > next_time)
                    {
                        /* set new timer value */
                        VMF_CTRL_DEBUG_INFO2(gtrid,VMF_TRACE_CONTROLLER,"re-set timer value for timer %d to %dms",current_timer_id,next_time-current_time);
                        vmf_ret = vmf_timer_set(current_timer_id,next_time-current_time);
                        if (VMF_OK != vmf_ret)
                        {
                            VMF_CTRL_DEBUG_ERROR(gtrid,VMF_TRACE_CONTROLLER,"vmf_timer_set(%d) with %dms failed",current_timer_id,next_time-current_time);
                        }
                    }
                }
            }

            break;
        }
    }
    return vmf_ret;
}



/*************************************************************************//**
 *
 *   get next timer that will elaps
 *
 *   \param[in]     void
 *   \return        vmf_ret
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t nw_vmf_ctrl_get_next_elaps_timer_val(unsigned32 *pabs_time)
{
    vmf_ret_t vmf_ret = VMF_ERROR;
    unsigned32  abs_time = (unsigned32)-1;
    unsigned16  cnt;

    for (cnt=0;cnt<max_used_timer_ix+1;cnt++)
    {
        if (soft_timer_list[cnt].in_use != 0)
        {
            /* timer is in use */
            if (soft_timer_list[cnt].abs_time < abs_time)
            {
                /* found earlier time */
                abs_time = soft_timer_list[cnt].abs_time;
            }
        }
    }

    if (abs_time != (unsigned32)-1)
    {
        *pabs_time = abs_time;
        vmf_ret = VMF_OK;
    }
    return vmf_ret;
}



/*************************************************************************//**
 *
 *   find elapsed timers and send registered events
 *
 *   \param[in]     void
 *   \return        vmf_ret
 *
 ******************************************************************************/
NW_STATIC void nw_vmf_ctrl_timer_send_elapsed(unsigned32 system_time_ms,void *ignore)
{
    unsigned32  current_time = 0;
    unsigned32  current_time2 = 0;
    unsigned32  timer_abs_time = 0;
    unsigned32  next_time = (unsigned32)(-1);
    unsigned8   cnt;
    unsigned8   current_max_timer_ix = 0;
    vmf_ret_t   ret_val;

    UNUSED_PARAM(ignore);

    VMF_CTRL_DEBUG_INFO2(gtrid,VMF_TRACE_CONTROLLER,"nw_vmf_ctrl_timer_send_elapsed time=%d",system_time_ms);

    current_time = nw_os_cfg_get_ms_time();
    for (cnt=0;cnt<max_used_timer_ix+1;cnt++)
    {
        if (soft_timer_list[cnt].in_use != 0)
        {
            /* found a used timer */
            timer_abs_time = soft_timer_list[cnt].abs_time;
            VMF_CTRL_DEBUG_INFO2(gtrid,VMF_TRACE_CONTROLLER,"current time=%d ms",current_time);
            VMF_CTRL_DEBUG_INFO2(gtrid,VMF_TRACE_CONTROLLER,"found used timer %d - elapse in %d ms",cnt, timer_abs_time-current_time);
            current_max_timer_ix = cnt;
            if (timer_abs_time <= current_time)
            {
                /* timer elapsed */
                (void)nw_vmf_ctrl_timer_send_event(cnt);
                soft_timer_list[cnt].in_use = 0x00;
            }
            else
            {
                if (timer_abs_time < next_time)
                {
                    next_time = timer_abs_time;     /* store next timer value */
                }
            }
        }
    }
    max_used_timer_ix = current_max_timer_ix;

    /* check if timer has to be restarted */
    current_time2 = nw_os_cfg_get_ms_time();
    if(next_time != (unsigned32)(-1))
    {
        unsigned16  rel_time;

        rel_time = next_time-current_time;

        /* special check to get a better accuracy in Windows*/
        if (rel_time < (current_time2-current_time))
        {
            rel_time = 0;
            next_time = current_time2;
        }


        {
            VMF_CTRL_DEBUG_INFO2(gtrid,VMF_TRACE_CONTROLLER,"current time=%d ms",current_time);
            VMF_CTRL_DEBUG_INFO2(gtrid,VMF_TRACE_CONTROLLER,"re-start timer with %dms",rel_time);
            ret_val = vmf_timer_start (&current_timer_id, rel_time, nw_vmf_ctrl_timer_send_elapsed,NULL);
            if (VMF_OK != ret_val)
            {
                VMF_CTRL_DEBUG_ERROR(gtrid,VMF_TRACE_CONTROLLER,"error starting timer with %dms",rel_time);
                timer_aktive = false;
            }
            else
            {
                current_timer_abs_elaps = next_time;
                timer_aktive = true;
            }
        }
    }
    else
    {
        current_timer_id = VMF_INVALID_TIMER;
        timer_aktive = false;
    }
    return;
}

/*************************************************************************//**
 *
 *   send the timer event to vmf
 *
 *   \param[in]     void
 *   \return        vmf_ret
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t nw_vmf_ctrl_timer_send_event(unsigned8 soft_timer_nr)
{
    VMF_VAR_BASIC_MSG_TYP(MAX_VMF_TIMER_PL)    vmf_basic_msg;
    vmf_ret_t   vmf_ret=VMF_OK;
    unsigned8   event;
    unsigned8   group;

    /* check if already connected to VMF */
    if ((0 == gcid) || (soft_timer_nr > max_used_timer_ix))
    {
        /* no connection to VMF established - so ignore */
        vmf_ret =  VMF_ERROR;
    }
    else
    {
        event = soft_timer_list[soft_timer_nr].event;
        group = soft_timer_list[soft_timer_nr].group;

        VMF_CTRL_DEBUG_INFO(gtrid,VMF_TRACE_CONTROLLER,"event=%d, group=%d, pl-len=%d\n",event,group,soft_timer_list[soft_timer_nr].pl_len);

        vmf_basic_msg.msg_base.id.event = event;
        vmf_basic_msg.msg_base.id.group = group;
        vmf_basic_msg.data.length=soft_timer_list[soft_timer_nr].pl_len;
        nw_os_smemcpy(vmf_basic_msg.data.pl,MAX_VMF_TIMER_PL,soft_timer_list[soft_timer_nr].pl,soft_timer_list[soft_timer_nr].pl_len);

        vmf_ret = nw_vmf_send_basic(gcid,(vmf_basic_msg_t*)&vmf_basic_msg);
    }
    return vmf_ret;
}

#endif
