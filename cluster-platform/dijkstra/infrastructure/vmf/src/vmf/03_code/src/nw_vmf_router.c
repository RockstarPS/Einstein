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

  \file                 nw_vmf_router.c
  \brief                router functionality for vmf

  \author               Joerg Merkle / Jochen Becker
  \author               Visteon Deutschland GmbH, Infotainment Software

  *****************************************************************************/
#define _NW_VMF_ROUTER_C_

#define NW_VMF_DEBUG
#define ENABLE_VMF_CO

#ifdef VMF_TRACE
 #define FILTER_SPY_TRACE
#endif

/* allways enable vmf spy if profiler is enabled */

/* system includes */
#include "nw_os_config.h"

/* application includes */
#ifndef UNIT_TEST
    #include "nw_vmf_debug.h"
#endif /* UNIT_TEST */
#include "intEvtDefs.h"
#include "nw_config.h"
#include "nw_vmf_types.h"
#include "nw_vmf_ipc.h"
#include "nw_vmf_util.h"
#include "nw_vmf_routing_db.h"
#include "nw_vmf_router.h"
#include "nw_vmf_error_handler.h"
#include "nw_vmf_trace.h"
#ifdef VMF_TRACE
#include "nw_vmf_trace_server.h"
#endif
#include "nw_vmf_routing_db-private.h"
#include "nw_vmf_client.h"
#include "nw_vmf_client_private.h"
#include "nw_vmf_timer.h"
#include "nw_vmf_controller.h"
#include "nw_vmf_client_uties.h"

#ifdef VMF_TARDIS
#include "nw_vmf_tardis.h"
#endif

#ifdef UNIT_TEST
    #include "unit_test.h"
#endif

#ifndef NW_EXTERNAL_MOST_ENABLED
#include "nw_vmf_nw_status_handler.h"
#endif

#ifdef VMF_REM
#include "nw_vmf_rem_server_connector.h"
#endif

#ifdef VMF_MI
#include "nw_vmf_mi.h"
#endif


/* WARNING!!! */
/* Do NOT activate VMF Trace macros -- DEADLOCKS can occur!!! */
#define VMF_ROUTER_TRACE_PRINT(a,b,c,d,e)                   // (void)fprintf (ERROR_CHANNEL,"%s - %s",d,e);(void)fprintf (ERROR_CHANNEL,"\n")  /* VMF_TRACE_PRINT(a,b,c,d,e) */
#define VMF_ROUTER_TRACE_PRINTF(a,b,c,d,e,args...)          // (void)fprintf (ERROR_CHANNEL,"%s - ",d);(void)fprintf (ERROR_CHANNEL,e,args);(void)fprintf (ERROR_CHANNEL,"\n") /* VMF_TRACE_PRINTF(a,b,c,d,e,__VA_ARGS__) */
#define VMF_ROUTER_TRACE_PRINTF2(a,b,c,d,e,args...)         (void)fprintf (ERROR_CHANNEL,"%s - ",d);(void)fprintf (ERROR_CHANNEL,e,args);(void)fprintf (ERROR_CHANNEL,"\n") /* VMF_TRACE_PRINTF(a,b,c,d,e,__VA_ARGS__) */


/* typedefs and macros */

/*! Definition of the status values of communication channels. */
enum nw_vmf_handle_status_values_enum
{
    NW_VMF_HANDLE_SERVER        = 0x00,                         /*!< Server receive channel*/
    NW_VMF_HANDLE_STANDARD,                                     /*!< Client channel with receiver and sender */
    NW_VMF_HANDLE_SENDER_ONLY,                                  /*!< Client channel sender only */
    NW_VMF_HANDLE_OUT_OF_ORDER,                                 /*!< Client is not able to receive it's messages.
                                                                     It will then not receive any more messages! */

    /* keep as last entry!!! */
    NW_VMF_HANDLE_CLIENT_NOT_CONNECTED = 0xFF                   /*!< Initialization value */
};

#define NW_VMF_PARAM_NOT_USED       0                           /*!< Value for parameters that are not used.
                                                                     Cast it for correct usage!*/

/*! Type for the router handle database used for message distribution. The logical handle is used as index */
typedef struct
{
    unsigned8           status;                                 /*!< Status of the channel (see nw_vmf_handle_status_values_enum). */
    pid_t               pid;                                    /*!< Client process ID */
    vmf_client_id_t     cid;                                    /*!< Client ID */
    bool                queue_overflown;                        /*!< vmf client queue is overflown if set to "true", else "false" */
    unsigned8           error_count;                            /*!< Error / retry count to evaluate if a client shall be removed from handle db */
    char                name[MAX_CTRL_CONN_PL_LEN];             /*!< Name of this connection ( process,connection name ) */
    char                zero;                                   /*!< name string is always zero terminated */
    vmf_client_shm_t    *pshm;                                  /*!< address of client shared memory */
    int                 fdshm;                                  /*!< shm file handle */
}handles_db_t;

#pragma pack(push,4)
/* load response version 0 */
typedef struct
{
    unsigned32  pid;                                            /* process id - (ll,lh,hl,hh  */
    unsigned8   cid;                                            /* cid */
    unsigned8   name_len;                                       /* size of name */
    char        name[MAX_CTRL_CONN_PL_LEN];                     /* name */
    char        zero;                                           /*!< name string is always zero terminated */
}vmf_connection_name_resp_pl_t;

#pragma pack(pop)

#pragma pack(push,1)
typedef struct
{
    unsigned32  pid;
    unsigned8   cid;
    unsigned8   not_used_1;
    unsigned8   not_used_2;
    unsigned8   not_used_3;
} vmf_sequence_diagram_client_list_t;

typedef struct
{
    unsigned32  time_ms;                                                /*!< time stamp milliseconds */
    unsigned32  pid;                                                    /*!< sender PID */
    unsigned8   cid;                                                    /*!< sender CID */
    unsigned8   group;                                                  /*!< message group */
    unsigned8   event;                                                  /*!< message event */
    unsigned8   client_count;                                           /*!< number of clients receiving this message */
    vmf_sequence_diagram_client_list_t  client_list[0];                 /*!< list of clients which received this message
                                                                             -- actual size will be longer! */
} vmf_sequence_diagram_pl_t;
#pragma pack(pop)


/*external data */
extern vmf_ctrl_pers_t pers_data;                               /* to save some cpu time we address this memory direct */
extern char progname[];                                         /* name of the current running process - should work in QNX and Linux */

/* global data */
vmf_spy_tab_t     spy_channel_handle_tab;
unsigned32        vmf_total_message_count = 0;                  /* used by vmf_controller */

/* static data */
#if 0 /* disabled, because VMF_ROUTER_TRACE_PRINTF disabled, too. */
static  unsigned8       vmf_trid=VMF_TRID_VMF;
#endif
static  vmf_handle_t    server_channel_handle = VMF_HANDLE_INVALID;         /*!< Logical handle of the server receive message queue */
static  vmf_handle_t    trace_server_channel_handle = VMF_HANDLE_INVALID;   /*!< Logical handle of the spy process channel */
static  handles_db_t    handle_db[MAX_IPC_CHANNELS];                        /*!< Client connection information storage */
static  unsigned8       last_handle;                                        /*!< Identifies the last valid entry of the handle_db */
static  unsigned8       vmf_spy_groups[MAX_GROUP_NUM];
#define VMF_ROUTER_SPY_GROUP    0x01
#define VMF_ROUTER_NO_SPY_GROUP 0x00


#define VMF_SEQUENCE_DIAGRAM_PL_MAX     200                                 /*!< Max. size for payload buffer */
        bool        vmf_sequence_diagram_enabled = VMF_FALSE;
        unsigned8   vmf_sequence_diagram_pl_used = 0;                       /*!< bytes used in vmf_sequence_diagram_pl */
static  unsigned8   vmf_sequence_diagram_pl[VMF_SEQUENCE_DIAGRAM_PL_MAX];   /*!< "metadata" of VMF messages for sequence diagrams */
static  VMF_VAR_BASIC_MSG_TYP(VMF_SEQUENCE_DIAGRAM_PL_MAX)  vmf_sequence_diagram_msg;                   /*!< VMF message for sequence diagram meta data */
static  vmf_basic_msg_t *vmf_sequence_diagram_msg_p = (vmf_basic_msg_t *)&vmf_sequence_diagram_msg;     /*!< pointer to VMF message for sequence diagram meta data */


/* local prototypes */
vmf_ret_t nw_vmf_init_router (void);
vmf_ret_t nw_vmf_router_eval_message (unsigned8 *message_buffer, unsigned16 message_length,unsigned8 *p_raw_msg);
vmf_ret_t nw_vmf_router_connect_client (vmf_ctrl_msg_connect_t *message);
vmf_ret_t nw_vmf_router_disconnect_client (vmf_ctrl_msg_connect_t *message);
vmf_ret_t nw_vmf_router_register_basic_msg_groups (vmf_ctrl_msg_register_msg_group_t *message);
vmf_ret_t nw_vmf_router_de_register_basic_msg_groups (vmf_ctrl_msg_register_msg_group_t *message);
vmf_ret_t nw_vmf_router_register_spy (vmf_ctrl_msg_register_spy_t *message);
vmf_ret_t nw_vmf_router_register_trace_server (vmf_ctrl_msg_register_spy_t *message);
vmf_ret_t nw_vmf_router_handle_basic_msg (vmf_basic_msg_t *message,unsigned8 *p_raw_msg);
vmf_ret_t nw_vmf_router_sequence_diagram_collector(unsigned8 handle_count, vmf_handle_t *handle_list, vmf_msg_t *message);
vmf_ret_t nw_vmf_router_send_sequence_diagram_data (void);

#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
vmf_ret_t nw_vmf_router_register_ext_most_link (vmf_ctrl_msg_register_ext_most_link_t *message);
vmf_ret_t nw_vmf_router_register_most_fblock (vmf_ctrl_msg_register_most_fblock_t *message);
vmf_ret_t nw_vmf_router_de_register_most_fblock (vmf_ctrl_msg_de_register_most_fblock_t *message);
vmf_ret_t nw_vmf_router_register_most_shadow (vmf_ctrl_msg_register_most_shadow_t *message);
vmf_ret_t nw_vmf_router_de_register_most_shadow (vmf_ctrl_msg_de_register_most_shadow_t *message);
vmf_ret_t nw_vmf_router_handle_most_msg (vmf_most_msg_t *message,unsigned8 *p_raw_msg);
#endif

vmf_ret_t nw_vmf_router_basic_msg_broadcast (vmf_basic_msg_t *message,unsigned8 *raw_buffer);
vmf_ret_t nw_vmf_router_msg_distribute (unsigned8 handle_count, vmf_handle_t *handle_list, vmf_msg_t *message,unsigned8* raw_buffer);
vmf_ret_t nw_vmf_router_handle_db_add (vmf_handle_t vmf_handle, pid_t pid, vmf_client_id_t cid, char *name,unsigned16 len);
vmf_ret_t nw_vmf_router_handle_db_remove (vmf_handle_t vmf_handle);

vmf_ret_t nw_vmf_router_msg_send_spy (unsigned8 *message, unsigned16 msg_len,unsigned8 *raw_buffer);

static vmf_ret_t nw_vmf_send_connection_name (vmf_handle_t tx_handle,vmf_handle_t client_handle);
static vmf_ret_t nw_vmf_send_connection_names(vmf_handle_t tx_handle);
static vmf_ret_t nw_vmf_send_vmf_connection_name (vmf_handle_t tx_handle);
#ifdef NW_DTC_VMF
static void nw_vmf_router_send_dtc (unsigned8 dtc, unsigned8 reason0, unsigned8 reason1, unsigned8 reason2);
#endif
static void     nw_vmf_router_send_dtc_overflow (void);
static inline   unsigned32 getmypid(void);

static void         nw_vmf_spy_init(void);
static vmf_ret_t    nw_vmf_add_spy(vmf_handle_t spy_handle);
static bool         nw_vmf_test_if_spy_hdl(vmf_handle_t spy_handle);
static vmf_ret_t    nw_vmf_send_connection_name_2all (vmf_handle_t client_handle);
static vmf_ret_t    nw_vmf_router_shm_request(vmf_ctrl_msg_connect_t * p_message);
static vmf_ret_t    nw_vmf_router_map_client_shm (vmf_handle_t client_handle);
static vmf_ret_t    nw_vmf_router_shm_parse_request(vmf_handle_t client_handle,vmf_client_shm_t *pshm);
static vmf_ret_t    nw_vmf_router_clshm_request_p2p_partner(vmf_handle_t client_handle,vmf_client_shm_t *pshm);
static char         *get_conn_string(char *in_str);
static void         vmf_router_register_spy_group( unsigned8 group);
static void         vmf_router_deregister_spy_group(unsigned8 group);
static void         vmf_router_init_spy_groups( void );
static bool         vmf_router_check_spy_group( unsigned8 group);


extern void nw_vmf_debug_msgs(char *prefix, pid_t pid, vmf_msg_t *p_my_msg);


/***************************************************************************//**
 *
 *   Main routing function. \n
 *   It receives the messages through the IPC in the while loop and forwards
 *   each message to the evaluation function.
 *
 *   \param         none
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router (void)
{
    vmf_ret_t   ret_val = VMF_OK;
    vmf_ret_t   eval_ret;

    /* do the initializations */
    if(VMF_OK != nw_vmf_init_router())
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_router: router initialization failed!");
        return VMF_ERR_ROUTER_INIT_FAILED;
    }

    VMF_ROUTER_TRACE_PRINT(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router","nw_vmf_init_router() done");

    /* add vmf name into spy queue */
    (void)nw_vmf_send_vmf_connection_name(0);

#ifdef VMF_TRACE
    VMF_ROUTER_TRACE_PRINT(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router","call vmf_trace_server_create_thread()");
    NW_COMPILER_MESSAGE("VMF_TRACE active")
    /* start the VMF-Trace-server thread */
    if (VMF_OK != vmf_trace_server_create_thread())
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_router: cannot start the vmf-trace server thread!");
    }
    else
    {
        /* wait for trace server (it will take 2-3ms) */
        while(false == trace_sync)
        {
            delay(1);
        }
    }
    VMF_ROUTER_TRACE_PRINT(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router","vmf_trace_server_create_thread() done");
#endif

#ifdef VMF_REM
    NW_COMPILER_MESSAGE("VMF_REM active")
    /* start remote vmf thread */
    if (nw_vmf_create_rem_vmf_thread() != VMF_OK)
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_router: cannot start the remote vmf thread!");
    }
#endif

#ifdef NW_VMF_MOST_ENABLED
  #ifndef NW_EXTERNAL_MOST_ENABLED
    /* start most process replacement thread */
    if (false == vmf_nw_status_create_thread())
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_router: cannot start most process replacement thread!\n");
        return VMF_ERR_ROUTER_INIT_FAILED;
    }
  #endif
#endif

    /* start vmf controller */
    ret_val = nw_vmf_controller_create_thread();
    if (ret_val != VMF_OK)
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_router: cannot create vmf-controller thread!\n");
    }

    /* start vmf mi */
#ifdef VMF_MI
    NW_COMPILER_MESSAGE("VMF_MI active")
    ret_val = nw_vmf_mi_create_starter_thread();
    if (ret_val != VMF_OK)
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_router: cannot create vmf-mi starter thread!\n");
    }
#endif

#ifdef VMF_TARDIS
    /* start VMF tardis */
    ret_val =  nw_vmf_create_tardis_thread ();
    if (ret_val != VMF_OK)
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_router: cannot create tardis thread!\n");
    }
#endif

    /* receive in the loop */
#ifndef UNIT_TEST
    while (1u == 1u)
#endif
    {
        unsigned16  message_length;
        unsigned8   *raw_buffer=NULL;


#ifdef VMF_IPC_SHM_ZEROCPY
        unsigned8 *message_buffer;

        raw_buffer = nw_vmf_ipc_receive_raw (server_channel_handle);
        if (NULL != raw_buffer)
        {
            message_buffer = ((vmf_buffer_pool_msg_t*)raw_buffer)->shm_msg;
            message_length = ((vmf_buffer_pool_msg_t*)raw_buffer)->msg_payload_len;
        }

        if (NULL == raw_buffer)
#else
        /* IMPORTANT: move message_buffer to a even 32Bit address */
        static      unsigned32   message_buffer[(MAX_VMF_MESSAGE_LEN/sizeof(unsigned32))+1];
        VMF_ROUTER_TRACE_PRINT(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router","call receive");

        if (VMF_OK != nw_vmf_ipc_receive( server_channel_handle, MAX_VMF_MESSAGE_LEN, (unsigned8 *)message_buffer, &message_length))
#endif
        {
            /* ignore and try again */
            VMF_ROUTER_TRACE_PRINT(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router","receive failed");
            delay(1);
        }
        else
        {
            VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router","receive done - len=%d",message_length);

            if (0 == message_length)
            {
                /* ignore zero message */
                continue;
            }

            /* use client_count to store the number of receive clients */
            ((vmf_msg_t*)message_buffer)->vmf_most_msg.msg_base.base.client_count = 0;

            /* evaluate the received message */
            eval_ret = nw_vmf_router_eval_message((unsigned8 *)message_buffer, message_length,raw_buffer);

            if (VMF_OK != eval_ret)
            {
                VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_WARNING_10,"vmf_server","nw_vmf_router","eval message returned error: %d",eval_ret);
            }
            else
            {
                /* NOP */
            }

            /* if the spy is registered or queue enabled , send all messages to it as well */
            if ((pers_data.vmf_start_q_ena != 0) || (nw_vmf_is_spy_avail()))
            {
                if (vmf_router_check_spy_group(((vmf_msg_base_t*)message_buffer)->id.group))
                {
                    eval_ret = nw_vmf_router_msg_send_spy((unsigned8 *)message_buffer, message_length,raw_buffer);
                    if (eval_ret != VMF_OK)
                    {
                        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_19,"vmf_server","nw_vmf_router","nw_vmf_router_msg_send_spy() failed, error code =%d",eval_ret);
                    }
                }
            }
        }
        #ifdef VMF_IPC_SHM_ZEROCPY
        eval_ret = nw_vmf_ipc_pool_free_buff_raw(raw_buffer);
        if (eval_ret != VMF_OK)
        {
            VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_19,"vmf_server","nw_vmf_router","nw_vmf_ipc_pool_free_buff_raw() failed, error code =%d",eval_ret);
        }
        #endif
    }

    return ret_val;
}

/***************************************************************************//**
 *
 *   Initialize global data and open the server message channel.
 *
 *   \param         none
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_init_router (void)
{
    vmf_ret_t       ret_val = VMF_OK;
    vmf_handle_t    i;


    /* reset global data */
    last_handle = 0;

    /* initialize the db stati */
    memset(handle_db,0,sizeof(handle_db));
    for (i=0;i<MAX_IPC_CHANNELS;i++)
    {
        handle_db[(unsigned8)i].status = NW_VMF_HANDLE_CLIENT_NOT_CONNECTED;
        handle_db[(unsigned8)i].queue_overflown = false;
        handle_db[(unsigned8)i].error_count = 0;
        handle_db[(unsigned8)i].name[0]=0;
        handle_db[(unsigned8)i].zero=0;
        handle_db[(unsigned8)i].pshm = NULL;
        handle_db[(unsigned8)i].fdshm = 0;
    }

    /* initialize the IPC -- remove old and unneeded ressources */
    if(VMF_OK != nw_vmf_ipc_init(true))
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_init_router: ipc initialization failed!");
        return VMF_ERR_ROUTER_INIT_FAILED;
    }

    /* initialize the router db */
    nw_vmf_routing_db_clear();

    /* create the message channel where server is receiving */
    while ((VMF_HANDLE_INVALID == server_channel_handle) || (server_channel_handle < 0))
    {
        server_channel_handle = nw_vmf_ipc_create(IPC_SERVER_CHANNEL_NAME, VMF_IPC_QUEUE_SIZE_SERVER, MAX_VMF_MESSAGE_LEN);
        delay(1);
    }

    #if VMF_IPC_TYPE == VMF_CTRL_IPC_SHM || VMF_IPC_TYPE == VMF_CTRL_IPC_MQ
    (void)nw_vmf_ipc_register_queue_name   (server_channel_handle,"vmf");
    #endif

    handle_db[(unsigned8)server_channel_handle].status = NW_VMF_HANDLE_SERVER;

    VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router","nw_vmf_init_router - server channel handle == %d\n", server_channel_handle);

    /* read persistent data for vmf-controller */
    (void) nw_vmf_ctrl_read_pers_data();

    /* init the spy table */
    nw_vmf_spy_init();
    
    /* set defaultgroups */
    vmf_router_init_spy_groups();
    

    /* set some data for sequence diagrams */
    NW_VMF_BASIC_MSG_TYPE(vmf_sequence_diagram_msg_p) = MSG_TYPE_BASIC_MESSAGE;
    NW_VMF_BASIC_MSG_GROUP(vmf_sequence_diagram_msg_p) = VMF_TRACE_CTRL;
    NW_VMF_BASIC_MSG_EVENT(vmf_sequence_diagram_msg_p) = VMF_CTRL_SEQ_DIAGRAM_DATA;

    return ret_val;
}


/**************************************************************************//**
 *
 *   Dependend on the message type each function is forwarded to
 *   the appropriate message handler.
 *
 *   \param[in]     message_buffer      pointer to the received message (still serial)
 *   \param[in]     message_length      length of the received message
 *   \param[in]     p_raw_msg           pointer to raw message - depending on IPC it may be the same as message_buffer
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_eval_message (unsigned8 *message_buffer, unsigned16 message_length, unsigned8 *p_raw_msg)
{
    vmf_ret_t       ret_val = VMF_OK;
    msg_type_t      msg_type;

    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_eval_message - message_buffer", message_buffer);
    NW_VMF_ARG_CHECK_SMALLER("nw_vmf_router_eval_message - message_length", message_length, MAX_VMF_MESSAGE_LEN);
    NW_VMF_ARG_CHECK_BIGGER_OR_EQUAL("nw_vmf_router_eval_message - message_length", message_length,sizeof(vmf_base_t));

#ifdef NW_VMF_DEBUG_ROUTER_MESSAGES_RECEIVED
    nw_vmf_debug_msgs("router IN :",((vmf_base_t*)message_buffer)->pid, (vmf_msg_t *)message_buffer);
#endif

    /* evaluate the incoming message dependent on the message type */
    msg_type = ((vmf_base_t*)message_buffer)->msg_type;

    switch (msg_type)
    {
        case MSG_TYPE_BASIC_MESSAGE:
            ret_val = nw_vmf_router_handle_basic_msg ((vmf_basic_msg_t *)message_buffer,p_raw_msg);
        break;

        case MSG_TYPE_P2P_BASIC_MESSAGE:
            /* this is a p2p message - just send it to the spies */
            (void)nw_vmf_router_msg_send_spy (message_buffer, message_length,NULL);
        break;

        case MSG_TYPE_CONNECT:
            ret_val = nw_vmf_router_connect_client((vmf_ctrl_msg_connect_t *)message_buffer);
        break;
#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
        case MSG_TYPE_MOST_MESSAGE:
            ret_val = nw_vmf_router_handle_most_msg ((vmf_most_msg_t *)message_buffer,p_raw_msg);
        break;

        case MSG_TYPE_REGISTER_EXT_MOST_LINK:
            ret_val = nw_vmf_router_register_ext_most_link ((vmf_ctrl_msg_register_ext_most_link_t *)message_buffer);
        break;

        case MSG_TYPE_REGISTER_MOST_FBLOCK:
            ret_val = nw_vmf_router_register_most_fblock ((vmf_ctrl_msg_register_most_fblock_t *)message_buffer);
        break;

        case MSG_TYPE_DE_REGISTER_MOST_FBLOCK:
            ret_val = nw_vmf_router_de_register_most_fblock ((vmf_ctrl_msg_de_register_most_fblock_t *)message_buffer);
        break;

        case MSG_TYPE_REGISTER_MOST_SHADOW:
            ret_val = nw_vmf_router_register_most_shadow ((vmf_ctrl_msg_register_most_shadow_t *)message_buffer);
        break;

        case MSG_TYPE_DE_REGISTER_MOST_SHADOW:
            ret_val = nw_vmf_router_de_register_most_shadow ((vmf_ctrl_msg_de_register_most_shadow_t *)message_buffer);
        break;
#endif

        case MSG_TYPE_REGISTER_MSG_GROUPS:
            ret_val = nw_vmf_router_register_basic_msg_groups((vmf_ctrl_msg_register_msg_group_t *)message_buffer);
        break;

        case MSG_TYPE_DE_REGISTER_MSG_GROUPS:
            ret_val = nw_vmf_router_de_register_basic_msg_groups ((vmf_ctrl_msg_register_msg_group_t *)message_buffer);
        break;


#ifndef UNIT_TEST
        case MSG_TYPE_REGISTER_SPY:
            ret_val = nw_vmf_router_register_spy ((vmf_ctrl_msg_register_spy_t *)message_buffer);
        break;
#endif /* UNIT_TEST */

        case MSG_TYPE_REGISTER_TRACE_SERVER:
            ret_val = nw_vmf_router_register_trace_server ((vmf_ctrl_msg_register_spy_t *)message_buffer);
        break;

        case MSG_TYPE_DISCONNECT:
            ret_val = nw_vmf_router_disconnect_client((vmf_ctrl_msg_connect_t *)message_buffer);
        break;

        case MSG_TYPE_SHM_REQUEST:
            ret_val = nw_vmf_router_shm_request((vmf_ctrl_msg_connect_t *)message_buffer);
        break;

        default:
            /* unknown message type */
            ret_val = VMF_ERR_ROUTER_UNKNOWN_MESSAGE;
            VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_WARNING_10,"vmf_server","nw_vmf_router_eval_message","unknown message type = %d",msg_type);
        break;
    }

    return ret_val;
}


/***************************************************************************//**
 *
 *   Connect with client IPC after receiving a connect request.
 *
 *   \param[in]     message -- pointer to a connect message type
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_connect_client(vmf_ctrl_msg_connect_t *message)
{
    vmf_ret_t       ret_val = VMF_OK;
    char            channel_name[MAX_NAME_LEN];
    vmf_handle_t    vmf_handle;

    #if VMF_IPC_TYPE == VMF_CTRL_IPC_SHM || VMF_IPC_TYPE == VMF_CTRL_IPC_MQ
    unsigned8       conn_string_len;
    #endif


    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_connect_client - message", message);
    if (VMF_OK != nw_vmf_ipc_create_channel_name(message->base.pid, message->base.client_id, channel_name, sizeof(channel_name)))
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_11,"vmf_server","nw_vmf_router_connect_client","cannot create channel_name pid=%d, cid=%d",message->base.pid, message->base.client_id);
        ret_val = VMF_ERR_ROUTER_CLIENT_CONNECT_FAILED;
    }
    else
    {
        vmf_handle = nw_vmf_ipc_open(channel_name, IPC_NON_BLOCKING);
        if ((VMF_HANDLE_INVALID == vmf_handle) || (vmf_handle < 0))
        {
            VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_11,"vmf_server","nw_vmf_router_connect_client","cannot open IPC %s",channel_name);
            ret_val = VMF_ERR_ROUTER_CLIENT_CONNECT_FAILED;
        }
        else
        {
            if (VMF_OK != nw_vmf_router_handle_db_add(vmf_handle, message->base.pid, message->base.client_id, message->pl_data,message->pl_len))
            {
                /* if the handle_db entry fails --> close the channel! */
                if (VMF_OK != nw_vmf_ipc_close(vmf_handle))
                {
                    VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_connect_client","registration failed but channel NOT closed %s !\n", channel_name);
                }
                else
                {
                    VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_connect_client","registration failed and channel closed %s !\n", channel_name);
                }
                ret_val = VMF_ERR_ROUTER_CLIENT_CONNECT_FAILED;
            }
            else
            {
                #if VMF_IPC_TYPE == VMF_CTRL_IPC_SHM || VMF_IPC_TYPE == VMF_CTRL_IPC_MQ
                /* give name to IPC for debug purpose */
                if (message->pl_len > 0)
                {
                    conn_string_len = strlen((char *) message->pl_data);
                    if (conn_string_len > 0)
                    {
                        (void) nw_vmf_ipc_register_queue_name(vmf_handle, message->pl_data);
                    }
                }
                #endif
                VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router_connect_client","channel name == %s, channel handle == %d",channel_name, vmf_handle);
            }
        }
    }

    return ret_val;
}


/***************************************************************************//**
 *
 *   disconnect a client
 *
 *   \param[in]     message -- pointer to a connect message type
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_disconnect_client (vmf_ctrl_msg_connect_t *message)
{
    vmf_ret_t       ret_val = VMF_OK;
    vmf_handle_t    vmf_handle;

    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_disconnect_client - message", message);

    ret_val = nw_vmf_router_get_client_handle(message->base.pid, message->base.client_id);

    if (    (VMF_HANDLE_INVALID == ret_val)
         || (VMF_ERR_OUT_OF_RANGE == ret_val) )
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_disconnect_client","cannot get vmf handle, error code =%d, pid=%d, cid=%d",ret_val,message->base.pid, message->base.client_id);
        ret_val = (VMF_ERR_ROUTER_SENDER_HANDLE_NOT_FOUND);
    }
    else
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router_disconnect_client","vmf handle =%d, pid=%d, cid=%d",ret_val,message->base.pid, message->base.client_id);

        /* close the channel */
        vmf_handle = (vmf_handle_t)ret_val;

        // NW_VMF_DEBUG_INFO("nw_vmf_router_disconnect_client vmf_handlevmf_handle=%d, spy_channel_handle=%d\n",vmf_handle,spy_channel_handle);


        (void)nw_vmf_ipc_destroy(vmf_handle);               /* free all used buffers */
        ret_val = nw_vmf_ipc_close(vmf_handle);
        if (VMF_OK != ret_val)
        {
            VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_disconnect_client","cannot close channel: vmf_handle=%x",vmf_handle);
        }
        else
        {
            /* remove all entries from this client in VMF database */
            __nw_vmf_routing_db_remove_handle(vmf_handle);

            /* remove handle from handle database */
            ret_val = nw_vmf_router_handle_db_remove(vmf_handle);
            if (VMF_OK != ret_val)
            {
                VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_disconnect_client","cannot remove handle from database: vmf_handle=%x",vmf_handle);
            }

            /* if this client was registered as spy then remove spy registration */
            (void)nw_vmf_delete_spy(vmf_handle);

            VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router_disconnect_client","nw_vmf_router_disconnect_client: OK - vmf_handle = %d",vmf_handle);
        }
    }

    return ret_val;
}



/***************************************************************************//**
 *
 *   Register this client for the received basic message groups
 *
 *   \param[in]     message -- pointer to registration message
 *   \return        vmf return
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_register_basic_msg_groups (vmf_ctrl_msg_register_msg_group_t *message)
{
    vmf_ret_t       ret_val = VMF_OK;
    vmf_ret_t       ret_val_get_handle;
    vmf_handle_t    sender;
    vmf_error_t     ret_reg;
    unsigned16      i;

    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_register_basic_msg_groups - message", message);
    NW_VMF_ARG_CHECK_SMALLER("nw_vmf_router_register_basic_msg_groups - groups_num",message->groups_num , MAX_GROUP_NUM);

    ret_val_get_handle = nw_vmf_router_get_client_handle(message->base.pid, message->base.client_id);
    if (    (VMF_HANDLE_INVALID == ret_val_get_handle)
         || (VMF_ERR_OUT_OF_RANGE == ret_val_get_handle) )
    {
        ret_val = VMF_ERR_ROUTER_SENDER_HANDLE_NOT_FOUND;
    }
    else
    {
        /* return value of nw_vmf_router_get_client_handle is sender handle */
        sender = ret_val_get_handle;

        for (i=0; i<message->groups_num; i++)
        {
            if (nw_vmf_test_if_spy_hdl(sender))
            {
                /* client is a spy */
                vmf_router_register_spy_group(message->groupList[i]);
            }
            else
            {
                /* normal client */
                ret_reg = nw_vmf_routing_db_event_register(sender, message->groupList[i]);

                if(VMF_OK != ret_reg)
                {

                    VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_register_basic_msg_groups","nw_vmf_routing_db_event_register failed err=%d",ret_reg);

                    ret_val = VMF_ERR_ROUTER_REGISTRATION_FAILED;
                }
                else
                {
                    /* do not set ret_val to VMF_OK since we want to remember any error! */
                }
            }
        }
    }
    return ret_val;
}

/***************************************************************************//**
 *
 *   De-register the client for the message groups.
 *
 *   \param[in]     message -- pointer to registration message
 *   \return        vmf return
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_de_register_basic_msg_groups (vmf_ctrl_msg_register_msg_group_t *message)
{
    vmf_ret_t       ret_val = VMF_OK;
    vmf_ret_t       ret_val_get_handle;
    vmf_handle_t    sender;
    unsigned16      i;

    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_deregister_basic_msg_groups - message", message);
    NW_VMF_ARG_CHECK_SMALLER("nw_vmf_router_deregister_basic_msg_groups - groups_num",message->groups_num , MAX_GROUP_NUM);

    ret_val_get_handle = nw_vmf_router_get_client_handle(message->base.pid, message->base.client_id);
    if (    (VMF_HANDLE_INVALID == ret_val_get_handle)
         || (VMF_ERR_OUT_OF_RANGE == ret_val_get_handle) )
    {
        ret_val = VMF_ERR_ROUTER_SENDER_HANDLE_NOT_FOUND;
    }
    else
    {
        /* return value of nw_vmf_router_get_client_handle is sender handle */
        sender = ret_val_get_handle;

        for (i=0; i<message->groups_num; i++)
        {
            if (nw_vmf_test_if_spy_hdl(sender))
            {
                /* client is a spy */
                vmf_router_deregister_spy_group(message->groupList[i]);
            }
            else
            {
                /* normal client */
                nw_vmf_routing_db_event_deregister(sender, message->groupList[i]);
            }
        }
    }
    return ret_val;
}


/***************************************************************************//**
 *
 *   handel client shm request
 *
 *   \param[in]     message -- pointer to message
 *   \return        vmf return
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_router_shm_request(vmf_ctrl_msg_connect_t * p_message)
{
    vmf_client_shm_t    *pshm = NULL;
    vmf_ret_t           ret_val = VMF_OK;
    vmf_handle_t        client_handle;

    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_shm_request", p_message);

    client_handle = nw_vmf_router_get_client_handle(p_message->base.pid, p_message->base.client_id);
    if (VMF_HANDLE_INVALID == client_handle)
    {
        ret_val = (vmf_ret_t)VMF_HANDLE_INVALID;
    }

    if (VMF_OK == ret_val)
    {
        /* map shared memory if needed */
        if (handle_db[(unsigned8)client_handle].pshm == NULL)
        {
            ret_val =  nw_vmf_router_map_client_shm(client_handle);
        }
    }

    if (VMF_OK == ret_val)
    {
        pshm = handle_db[(unsigned8)client_handle].pshm;
    }

    if (pshm != NULL)
    {
        ret_val = nw_vmf_router_shm_parse_request(client_handle, pshm);
    }
    else
    {
        ret_val = VMF_ERR_NULL_POINTER;
    }

    return ret_val;
}



/***************************************************************************//**
 *
 *   parse client shm requests
 *
 *   \param[in]     client vmf handle
 *   \param[in]     pointer to shared memory
 *
 *   \return        vmf return
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_router_shm_parse_request(vmf_handle_t client_handle,vmf_client_shm_t *pshm)
{
    vmf_ret_t           ret_val = VMF_OK;

    switch (pshm->request_cmd)
    {
        case VMF_CLSHM_REQUEST_REGISTER:
            /* nothing to do - shm already mapped */
        break;

        case VMF_CLSHM_REQUEST_P2P_PARTNER:
            ret_val = nw_vmf_router_clshm_request_p2p_partner(client_handle,pshm);
        break;

        case VMF_CLSHM_REQUEST_INVALID:
        /* no break */
        default:
        break;
    }

    return ret_val;
}


/***************************************************************************//**
 *
 *   handle MSG_TYPE_SHM_REQUEST
 *
 *   \param[in]     client vmf handle
 *   \param[in]     pointer to shared memory
 *
 *   \return        vmf return
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_router_clshm_request_p2p_partner(vmf_handle_t client_handle,vmf_client_shm_t *pshm)
{
    clshm_p2p_partner_t *p_pl=NULL;
    vmf_ret_t           ret_val = VMF_OK;
    int                 len=0;
    int                 handle=0;

    UNUSED_PARAM(client_handle);

    if (pshm->valid != VMF_CLIENT_SHM_VALID_KEY)
    {
        ret_val = VMF_ERR_SHM;
    }

    /* create pointer to the payload */
    p_pl = &(pshm->pl.psp_partner);
    len = strlen(p_pl->name);
    if (len > MAX_NAME_LEN)
    {
        len = MAX_NAME_LEN;
    }

    /* search for the given connection string */
    p_pl->pid = 0;
    p_pl->cid = 0;

    VMF_ROUTER_TRACE_PRINTF2(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router_clshm_request_p2p_partner","search for %s",p_pl->name);

    for (handle=0; handle<=last_handle; handle++)
    {
        char *conn_string;
        int  clen=0;

        VMF_ROUTER_TRACE_PRINTF2(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router_clshm_request_p2p_partner","stored con-string = %s",handle_db[(unsigned8)handle].name);
        conn_string = get_conn_string(handle_db[(unsigned8)handle].name);
        VMF_ROUTER_TRACE_PRINTF2(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router_clshm_request_p2p_partner","con-string in stored con-string = %s",conn_string);
        clen = strlen(conn_string);
        if (clen == len)
        {
            if (0 == strncmp(p_pl->name,conn_string,len))
            {
                /* connection string found */
                p_pl->pid = handle_db[(unsigned8)handle].pid;
                p_pl->cid = handle_db[(unsigned8)handle].cid;
                break;
            }
        }
    }
    p_pl->valid = VMF_CLIENT_SHM_VALID_KEY;

    return ret_val;
}






#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
/***************************************************************************//**
 *
 *   Register this client as external MOST link
 *
 *   \param[in]     message -- pointer to a message containing registration data
 *   \return        vmf return
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_register_ext_most_link (vmf_ctrl_msg_register_ext_most_link_t *message)
{
    vmf_ret_t       ret_val = VMF_OK;
    vmf_ret_t       ret_val_get_handle;
    vmf_error_t     ret_reg;
    vmf_handle_t    sender;


    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_register_ext_most_link - message", message);


    ret_val_get_handle = nw_vmf_router_get_client_handle(message->base.pid, message->base.client_id);
    if (    (VMF_HANDLE_INVALID == ret_val_get_handle)
         || (VMF_ERR_OUT_OF_RANGE == ret_val_get_handle) )
    {
        ret_val = VMF_ERR_ROUTER_SENDER_HANDLE_NOT_FOUND;
    }
    else
    {
        /* return value of nw_vmf_router_get_client_handle is sender handle */
        sender = ret_val_get_handle;

        ret_reg = nw_vmf_routing_db_most_register(NW_VMF_ROUTING_DB_REGISTRATION_EXTERNAL_MOST, sender,
                                                  (unsigned8)NW_VMF_PARAM_NOT_USED, (unsigned8)NW_VMF_PARAM_NOT_USED,
                                                  NULL, (unsigned16)NW_VMF_PARAM_NOT_USED);

        if(VMF_OK != ret_reg)
        {
            ret_val = VMF_ERR_ROUTER_REGISTRATION_FAILED;
        }
    }

    return ret_val;
}
#endif

#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
/***************************************************************************//**
 *
 *   Register the received FBlock/InstID within this client
 *
 *   \param[in]     message -- pointer to a message containing the registration data
 *   \return        vmf return
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_register_most_fblock (vmf_ctrl_msg_register_most_fblock_t *message)
{
    vmf_ret_t       ret_val = VMF_OK;
    vmf_ret_t       ret_val_get_handle;
    vmf_error_t     ret_reg;
    vmf_handle_t    sender;


    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_register_most_fblock - message", message);


    ret_val_get_handle = nw_vmf_router_get_client_handle(message->base.pid, message->base.client_id);
    if (    (VMF_HANDLE_INVALID == ret_val_get_handle)
         || (VMF_ERR_OUT_OF_RANGE == ret_val_get_handle) )
    {
        ret_val = VMF_ERR_ROUTER_SENDER_HANDLE_NOT_FOUND;
    }
    else
    {
        /* return value of nw_vmf_router_get_client_handle is sender handle */
        sender = ret_val_get_handle;

        ret_reg = nw_vmf_routing_db_most_register(NW_VMF_ROUTING_DB_REGISTRATION_FBLOCK, sender,
                                                  message->fBlockId, message->instId,
                                                  NULL, (unsigned16)NW_VMF_PARAM_NOT_USED);

        if(VMF_OK != ret_reg)
        {
            ret_val = VMF_ERR_ROUTER_REGISTRATION_FAILED;
        }
    }

    return ret_val;
}
#endif

#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
/***************************************************************************//**
 *
 *   De-register this FBlock/InstID from this client
 *
 *   \param[in]     message -- pointer to a message containing the registration data
 *   \return        vmf return
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_de_register_most_fblock (vmf_ctrl_msg_de_register_most_fblock_t *message)
{
    vmf_ret_t   ret_val = VMF_OK;


    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_register_most_fblock - message", message);

    return ret_val;
}
#endif

#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
/***************************************************************************//**
 *
 *   Register a shadow FBlock function for this client.
 *
 *   \param[in]     message -- pointer to a message containing the registration data
 *   \return        vmf return
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_register_most_shadow (vmf_ctrl_msg_register_most_shadow_t *message)
{
    vmf_ret_t       ret_val = VMF_OK;
    vmf_ret_t       ret_val_get_handle;
    vmf_error_t     ret_reg;
    vmf_handle_t    sender;


    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_register_most_shadow - message", message);


    ret_val_get_handle = nw_vmf_router_get_client_handle(message->base.pid, message->base.client_id);
    if (    (VMF_HANDLE_INVALID == ret_val_get_handle)
         || (VMF_ERR_OUT_OF_RANGE == ret_val_get_handle) )
    {
        ret_val = VMF_ERR_ROUTER_SENDER_HANDLE_NOT_FOUND;
    }
    else
    {
        /* return value of nw_vmf_router_get_client_handle is sender handle */
        sender = ret_val_get_handle;

        ret_reg = nw_vmf_routing_db_most_register(NW_VMF_ROUTING_DB_REGISTRATION_SHADOW, sender,
                                                  message->fBlockId, message->instId,
                                                  message->funcIdList, message->u16NumFKtIds);

        if(VMF_OK != ret_reg)
        {
            ret_val = VMF_ERR_ROUTER_REGISTRATION_FAILED;
        }
    }

    return ret_val;
}
#endif

#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
/***************************************************************************//**
 *
 *   De-register a shadow FBlock (complete shadow!)
 *
 *   \param[in]     message -- pointer to a message containing the registration data
 *   \return        vmf return
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_de_register_most_shadow (vmf_ctrl_msg_de_register_most_shadow_t *message)
{
    vmf_ret_t   ret_val = VMF_OK;


    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_de_register_most_shadow - message", message);

    return ret_val;
}
#endif

/***************************************************************************//**
 *
 *   Register this client as message spy
 *
 *   \param[in]     message -- pointer to a message containing registration data
 *   \return        vmf return
 *
 ******************************************************************************/
#ifndef UNIT_TEST
vmf_ret_t nw_vmf_router_register_spy (vmf_ctrl_msg_register_spy_t *message)
{
    vmf_ret_t       ret_val = VMF_OK;
    vmf_ret_t       ret_val_get_handle;

    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_register_spy - message", message);

    ret_val_get_handle = nw_vmf_router_get_client_handle(message->base.pid, message->base.client_id);
    if (    (VMF_HANDLE_INVALID == ret_val_get_handle)
         || (VMF_ERR_OUT_OF_RANGE == ret_val_get_handle) )
    {

        VMF_ROUTER_TRACE_PRINT(vmf_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_server","nw_vmf_router_register_spy","register spy failed");
        ret_val = VMF_ERR_ROUTER_REGISTER_SPY_FAILED;
    }
    else
    {
        /* regster new spy */
        if (nw_vmf_add_spy(ret_val_get_handle) == VMF_OK)
        {
            /* send all connection names to the new spy */
            (void)nw_vmf_send_connection_names(ret_val_get_handle);
            VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_14,"vmf_server","nw_vmf_router_register_spy","new spy_channel_handle = %d",ret_val_get_handle);
        }
        else
        {
            VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_WARNING_10,"vmf_server","nw_vmf_router_register_spy","new nw_vmf_add_spy() failed");
        }
    }

    return ret_val;
}
#endif /* UNIT_TEST */



/***************************************************************************//**
 *
 *   Register this client as trace server
 *
 *   \param[in]     message -- pointer to a message containing registration data
 *   \return        vmf return
 *
 ******************************************************************************/
#ifndef UNIT_TEST
vmf_ret_t nw_vmf_router_register_trace_server (vmf_ctrl_msg_register_spy_t *message)
{
    vmf_ret_t       ret_val = VMF_OK;
    vmf_ret_t       ret_val_get_handle;

    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_register_trace_server - message", message);

    ret_val_get_handle = nw_vmf_router_get_client_handle(message->base.pid, message->base.client_id);
    VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_server","nw_vmf_router_register_trace_server","cid = %d",ret_val_get_handle);

    if (    (VMF_HANDLE_INVALID == ret_val_get_handle)
         || (VMF_ERR_OUT_OF_RANGE == ret_val_get_handle) )
    {

        VMF_ROUTER_TRACE_PRINT(vmf_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_server","nw_vmf_router_register_trace_server","register trace server failed");
        ret_val = VMF_ERR_ROUTER_REGISTER_SPY_FAILED;
    }
    else
    {
        /* return value of nw_vmf_router_get_client_handle is sender handle */
        trace_server_channel_handle = ret_val_get_handle;

        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_14,"vmf_server","nw_vmf_router_register_trace_server","trace_server_channel_handle = %d",trace_server_channel_handle);
    }

    return ret_val;
}
#endif /* UNIT_TEST */


/***************************************************************************//**
 *
 *   MOST message handler
 *
 *   \param[in]     message -- pointer to most message
 *   \return        vmf return
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_handle_most_msg (vmf_most_msg_t *message,unsigned8 *p_raw_msg)
{
    vmf_ret_t       ret_val = VMF_OK;
    vmf_ret_t       ret_val_db = VMF_OK;
    vmf_handle_t    *handle_list;
    unsigned8       handle_count;


    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_handle_most_msg - message", message);

    ret_val_db = (vmf_ret_t) nw_vmf_routing_db_get_handle_list((vmf_msg_base_t *)message, &handle_list);


    if (ret_val_db > 0)
    {
        /* here ret_val is the number of handles */
        handle_count = (unsigned8)ret_val_db;

        /* send to registered clients */
        ret_val = nw_vmf_router_msg_distribute(handle_count, handle_list, (vmf_msg_t*)message,p_raw_msg);
    }
    else if (0 == ret_val_db)
    {
        /* number handles == 0 */
        ret_val = VMF_OK;

#ifdef NW_VMF_DEBUG_ROUTER_MESSAGES_RECEIVED_BUT_NOT_SENT
        /* The routing db tells us that the received message shall not sent to any client!!! */
        NW_VMF_DEBUG_INFO("nw_vmf_router_handle_most_msg: MESSAGE NOT SENT -- FBlockId=0x%x InstId=0x%x FuncId=0x%x\n",
                            message->fblock_id, message->inst_id, message->func_id);
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEV_STD_INFO,"vmf_server","nw_vmf_router_handle_most_msg","MESSAGE NOT SENT -- FBlockId=0x%x InstId=0x%x FuncId=0x%x",message->fblock_id, message->inst_id, message->func_id);

#endif /* NW_VMF_DEBUG_ROUTER_MESSAGES_RECEIVED_BUT_NOT_SENT */
    }
    else
    {
        /* call the error handler */
#ifdef NW_VMF_ENABLE_MOST_ERROR_HANDLER
        (void) nw_vmf_handle_invalid_most_msg ((vmf_msg_t*)message,ret_val_db,p_raw_msg);

        /* return DB error */
#endif /* NW_VMF_ENABLE_MOST_ERROR_HANDLER */
        ret_val = ret_val_db;
    }


/* For vmf wrapper use, it's allowed to register a shadow with empty function list (only FBlockId and InstId).
   Therefore the router db needs a second call to get those registered clients... */
#ifdef NW_VMF_CFG_ALLOW_SHADOW_WITH_EMPTY_FUNCTION_LIST
    ret_val_db = (vmf_ret_t) nw_vmf_routing_db_get_general_shadow_handle_list((vmf_msg_base_t *)message, &handle_list);
    if (ret_val_db > 0)
    {
        /* here ret_val is the number of handles */
        handle_count = (unsigned8)ret_val_db;

        /* send to registered clients */
        if (VMF_OK != nw_vmf_router_msg_distribute(handle_count, handle_list, (vmf_msg_t*)message))
        {
            ret_val = VMF_ERR_ROUTER_SEND_FAILED;
        }
    }
    else if (0 == ret_val_db)
    {
        /* number handles == 0 */

        /* jmerkle  25.06.2008 14:03:11 */
        /* jmerkle  NOTE: */
        /* jmerkle  This could overwrite an error from first call into routing db!!! */
        /* jmerkle  Since it is only for VMF WRAPPER it has to be removed later... */
        ret_val = VMF_OK;
    }
    else
    {
        /* ret_val is an error */

        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_handle_most_msg","nw_vmf_routing_db_get_general_shadow_handle_list() returned error=%d",ret_val_db);
        ret_val = VMF_ERR_ROUTER_DB_ERROR;
    }
#endif /* NW_VMF_CFG_ALLOW_SHADOW_WITH_EMPTY_FUNCTION_LIST */

    return ret_val;
}

/***************************************************************************//**
 *
 *   basic message handler
 *
 *   \param[in]     message -- pointer to basic message
 *   \return        vmf return
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_handle_basic_msg (vmf_basic_msg_t *message,unsigned8 *p_raw_msg)
{
    vmf_ret_t       ret_val = VMF_OK;
    unsigned8       handle_count;
    vmf_handle_t    *handle_list;

    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_handle_basic_msg - *message", message);

    ret_val = (vmf_ret_t) nw_vmf_routing_db_get_handle_list((vmf_msg_base_t *)message, &handle_list);
    if (ret_val > 0)
    {
        if (VMF_HANDLE_BROADCAST == handle_list[0])
        {
            /* broadcast message */
            ret_val = nw_vmf_router_basic_msg_broadcast(message,p_raw_msg);
        }
        else
        {
            /* ret_val is the number of handles */
            handle_count = (unsigned8)ret_val;

            /* send to registered clients */
            ret_val = nw_vmf_router_msg_distribute(handle_count, handle_list, (vmf_msg_t*)message,p_raw_msg);

#ifdef NW_VMF_CFG_ENABLE_SEQUENCE_DIAGRAMS      /* --> nw_vmf_cfg.h */
            {
                vmf_ret_t       ret_val_seq;

                /* collect data for sequence diagram if enabled */
                if (VMF_TRUE == vmf_sequence_diagram_enabled)
                {
                    ret_val_seq = nw_vmf_router_sequence_diagram_collector(handle_count, handle_list, (vmf_msg_t*)message);
                    if (ret_val_seq != VMF_OK)
                    {
                        /* Don't mind if it doesn't work */
                        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_handle_basic_msg",
                                                            "nw_vmf_router_sequence_diagram_collector() returned error=%d",ret_val_seq);
                    }
                }
            }
#endif            
        }
    }
    else if (0 == ret_val)
    {
        /* number handles == 0 */
        ret_val = VMF_OK;
    }
    else
    {
        /* ret_val is an error */
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_handle_basic_msg","nw_vmf_routing_db_get_handle_list() returned error=%d",ret_val);
        ret_val = VMF_ERR_ROUTER_DB_ERROR;
    }


    return ret_val;
}


/***************************************************************************//**
 *
 *   Collect the "metadata" of received basic message for sequence diagrams. \n
 *   If collector is full then send collection as basic message to VMF Analyzer. \n
 *
 *   \param[in]     handle_count  -- number of handles
 *   \param[in]     handle_list   -- pointer to the client handle list
 *   \param[in]     message       -- pointer to the message
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_sequence_diagram_collector(unsigned8 handle_count, vmf_handle_t *handle_list, vmf_msg_t *message)
{
    vmf_ret_t                           ret_val = VMF_OK;
    vmf_ret_t                           send_ret_val;
    vmf_basic_msg_t                     *p_basic_msg;
    unsigned8                           i;
    vmf_sequence_diagram_pl_t           seq_payload = {0};
    vmf_sequence_diagram_client_list_t  seq_client_list[handle_count];
    unsigned16                          seq_payload_size = 0;       /* size in byte */
    unsigned16                          seq_client_list_size = 0;   /* size in byte */


//    fprintf(stdout, "collector: handle_count = %d\n", handle_count);

    NW_VMF_ARG_CHECK_SMALLER("nw_vmf_router_basic_msg_distribute - handle_count", handle_count, MAX_IPC_CHANNELS);
    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_basic_msg_distribute - handle_list", handle_list);
    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_basic_msg_distribute - message", message);
    
    if (MSG_TYPE_MOST_MESSAGE == message->vmf_most_msg.msg_base.base.msg_type)
    {
        /* feature isn't supported for MOST messages */
        ret_val = VMF_ERR_NOT_SUPPORTED;
    }
    else
    {
        p_basic_msg = (vmf_basic_msg_t *) message;
        seq_payload.time_ms      = (unsigned32) (p_basic_msg->msg_base.base.msg_clk & 0x0000FFFF);
        seq_payload.pid          = p_basic_msg->msg_base.base.pid;
        seq_payload.cid          = p_basic_msg->msg_base.base.client_id;
        seq_payload.group        = p_basic_msg->msg_base.id.group;
        seq_payload.event        = p_basic_msg->msg_base.id.event;
        seq_payload.client_count = handle_count;

        
        for (i=0; i<handle_count; i++)
        {
            seq_client_list[i].pid = handle_db[handle_list[i]].pid;
            seq_client_list[i].cid = handle_db[handle_list[i]].cid;
            seq_client_list_size = seq_client_list_size + sizeof(vmf_sequence_diagram_client_list_t);

//            fprintf(stdout, "collector: i = %d, pid = %d, cid = %d\n", i, seq_client_list[i].pid, seq_client_list[i].cid);
        }
        
        seq_payload_size = sizeof(vmf_sequence_diagram_pl_t);
        
        if ((VMF_SEQUENCE_DIAGRAM_PL_MAX - vmf_sequence_diagram_pl_used) < (seq_payload_size + seq_client_list_size))
        {
            /* NOT enough space in collector, first send collected data */
            send_ret_val = nw_vmf_router_send_sequence_diagram_data ();
            if (send_ret_val != VMF_OK)
            {
                VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_sequence_diagram_collector",
                                                        "nw_vmf_router_send_sequence_diagram_data returned error=%d",send_ret_val);
            }
            vmf_sequence_diagram_pl_used = 0;           
        }

        if ((VMF_SEQUENCE_DIAGRAM_PL_MAX - vmf_sequence_diagram_pl_used) < (seq_payload_size + seq_client_list_size))
        {
            /* seems it will never fit -- skip this and reset collector */
            vmf_sequence_diagram_pl_used = 0;
            ret_val = VMF_ERR_TO_MUCH_DATA;
//            fprintf(stdout,"collector: too much data!\n");
        }
        else
        {
            /* collect */
            NW_MEMCOPY(&vmf_sequence_diagram_pl[vmf_sequence_diagram_pl_used], &seq_payload, seq_payload_size);
            vmf_sequence_diagram_pl_used = vmf_sequence_diagram_pl_used + seq_payload_size;
            NW_MEMCOPY(&vmf_sequence_diagram_pl[vmf_sequence_diagram_pl_used], &seq_client_list, seq_client_list_size);
            vmf_sequence_diagram_pl_used = vmf_sequence_diagram_pl_used + seq_client_list_size;
            
//            fprintf(stdout,"collector: seq_payload_size=%d, seq_client_list_size=%d\n",seq_payload_size,seq_client_list_size);
            
        }
    }
    
    return ret_val;
}



/***************************************************************************//**
 *
 *   Send collected data from sequence diagram collector \n
 *
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_send_sequence_diagram_data (void)
{
    vmf_ret_t ret_val = VMF_OK;
    vmf_basic_msg_t *my_msg_p = vmf_sequence_diagram_msg_p;

    NW_MEMCOPY(NW_VMF_BASIC_MSG_DATA_PTR(my_msg_p), vmf_sequence_diagram_pl, vmf_sequence_diagram_pl_used);
    NW_VMF_BASIC_MSG_DATA_LENGTH(my_msg_p) = vmf_sequence_diagram_pl_used;
    
    ret_val = nw_vmf_router_msg_send_spy((unsigned8 *)my_msg_p, NW_VMF_BASIC_MSG_TOTAL_LENGTH(my_msg_p), (unsigned8 *)my_msg_p);
    
    return ret_val;
}




/***************************************************************************//**
 *
 *   Broadcast the received basic message. \n
 *   Send basic messages to all clients (except the sender).
 *
 *   \param[in]     message -- pointer to the message to broadcast
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_basic_msg_broadcast (vmf_basic_msg_t *message,unsigned8 *raw_buffer)
{
    vmf_ret_t       ret_val = VMF_OK;
    vmf_ret_t       ret_val_get_handle;
    vmf_handle_t    sender;
    vmf_handle_t    i;
    unsigned16      msg_size;
    unsigned8       client_count=0;

    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_basic_msg_broadcast - message", message);


    ret_val_get_handle = nw_vmf_router_get_client_handle(message->msg_base.base.pid, message->msg_base.base.client_id);
    if (    (VMF_HANDLE_INVALID == ret_val_get_handle)
         || (VMF_ERR_OUT_OF_RANGE == ret_val_get_handle) )
    {
        ret_val = VMF_ERR_ROUTER_SENDER_HANDLE_NOT_FOUND;
    }
    else
    {
        /* return value of nw_vmf_router_get_client_handle is sender handle */
        sender = ret_val_get_handle;

        /* size is sizeof(vmf_msg_base_t) + sizof(unsigned16 data_length) + actual data length */
        /* msg_size = sizeof(  vmf_msg_base_t) + 2 + message->data.length; */
        /* msg_size = sizeof(VMF_VAR_BASIC_MSG_TYP(0)) + message->data.length; */
        msg_size = VMF_BASIC_MSG_LEN(message->data.length);

        for (i=0; i<=last_handle; i++)
        {
            if (nw_vmf_test_if_spy_hdl(i))
            {
                /* prevent duplicate transmission of broadcast messages to the spy */
                continue;
            }

            if ((i != sender) && (NW_VMF_HANDLE_STANDARD == handle_db[(unsigned8)i].status))
            {
                if (VMF_ERR_ROUTER_SEND_FAILED == nw_vmf_router_msg_send (i, (unsigned8 *)message, msg_size,raw_buffer))
                {
                    ret_val = VMF_ERR_ROUTER_SEND_FAILED;
                }
                else
                {
                    client_count++;
                }
            }
        }
    }

    message->msg_base.base.client_count = client_count;      /* use client_count to store the number of receive clients */

    return ret_val;
}

/***************************************************************************//**
 *
 *   Distribute the received basic or MOST message to all registered clients.
 *
 *   \param[in]     handle_count  -- number of handles
 *   \param[in]     handle_list   -- pointer to the client handle list
 *   \param[in]     message       -- pointer to the message to distribute
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_msg_distribute (unsigned8 handle_count, vmf_handle_t *handle_list, vmf_msg_t *message,unsigned8* raw_buffer)
{
    vmf_ret_t       ret_val = VMF_OK;
    vmf_handle_t    client_handle;
    unsigned8       i;
    unsigned16      msg_size;
    unsigned8       client_count=0;

    NW_VMF_ARG_CHECK_SMALLER("nw_vmf_router_basic_msg_distribute - handle_count", handle_count, MAX_IPC_CHANNELS);
    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_basic_msg_distribute - handle_list", handle_list);
    NW_VMF_ARG_CHECK_POINTER("nw_vmf_router_basic_msg_distribute - message", message);

    if (MSG_TYPE_MOST_MESSAGE == message->vmf_most_msg.msg_base.base.msg_type)
    {
        msg_size = sizeof(VMF_VAR_MOST_MSG_TYP(0)) + message->vmf_most_msg.data.length;
    }
    else
    {
        /* base msg size is sizeof(vmf_msg_base_t) + sizof(unsigned16 data_length) + actual data length */
        /* msg_size = sizeof(vmf_msg_base_t) + sizeof(message->vmf_basic_msg.data.length) + message->vmf_basic_msg.data.length; */
        /* msg_size = sizeof(VMF_VAR_BASIC_MSG_TYP(0)) + message->vmf_basic_msg.data.length; */
        msg_size = VMF_BASIC_MSG_LEN(message->vmf_basic_msg.data.length);
    }

    for (i=0; i<handle_count; i++)
    {
        client_handle = handle_list[i];

        if (NW_VMF_HANDLE_STANDARD == handle_db[(unsigned8)client_handle].status)
        {
            if (VMF_ERR_ROUTER_SEND_FAILED == nw_vmf_router_msg_send (client_handle, (unsigned8 *)message, msg_size,raw_buffer))
            {
                ret_val = VMF_ERR_ROUTER_SEND_FAILED;
            }
            else
            {
#if 0
                unsigned8 group = message->vmf_basic_msg.msg_base.id.group;
                unsigned8 id = message->vmf_basic_msg.msg_base.id.event;
                VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router_handle_basic_msg","nw_vmf_router_msg_distribute(%s) len=%d client_handle=%d, group=%d, id=%d",handle_db[(unsigned8)client_handle].name,msg_size,client_handle,group,id);
#endif
                client_count++;
            }
       }
    }
    message->vmf_most_msg.msg_base.base.client_count = client_count;     /* use client_count to store the number of receive clients */

    return ret_val;
}




/***************************************************************************//**
 *
 *   Send a message using the IPC to all spies
 *
 *   \param[in]     message       -- unsigned8 pointer to the VMF message to send
 *   \param[in]     msg_size      -- actual message size
 *   \param[in]     raw_buffer    -- 
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_msg_send_spy (unsigned8 *message, unsigned16 msg_len,unsigned8 *raw_buffer)
{
    vmf_ret_t       ret_val=VMF_OK;

#ifdef ENABLE_VMF_CO
    if ((nw_vmf_is_spy_avail()) || ((pers_data.vmf_start_q_ena != 0)))
    {
        VMF_ROUTER_TRACE_PRINTF(0,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router_msg_send_spy","nw_vmf_spy_send_msg() len=%d",msg_len);
        ret_val = nw_vmf_spy_send_msg(message,msg_len,raw_buffer);
    }
    return ret_val;
#else
    if (nw_vmf_is_spy_avail())
    {
        int cnt;
        VMF_ROUTER_TRACE_PRINTF(0,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router_msg_send_spy","nw_ipc_send_msg() len=%d",msg_len);

        /* send to all spies */
        for (cnt=0; cnt<VMF_MAX_SPY_NUM; cnt++)
        {
            if (spy_channel_handle_tab.handle[cnt] != VMF_HANDLE_INVALID)
            {
                ret_val = nw_vmf_ipc_send(spy_channel_handle_tab.handle[cnt], message, msg_size);
                if (ret_val != VMF_OK)
                {
                    /* error sending to spy !*/
                    /* deregister spy */
                    (void)nw_vmf_delete_spy(spy_channel_handle_tab.handle[cnt]);
                }
            }
        }
    }
    return ret_val;
#endif
}


/***************************************************************************//**
 *
 *   Send a message using the IPC
 *
 *   \param[in]     client_handle -- where to send
 *   \param[in]     message       -- pointer to the message to send
 *   \param[in]     msg_size      -- actual message size
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_msg_send (vmf_handle_t client_handle, unsigned8 *message, unsigned16 msg_size,unsigned8 *raw_buffer)
{
    vmf_ret_t       ret_val=VMF_OK;

    #ifdef VMF_IPC_SHM_ZEROCPY
    if (NULL != raw_buffer)
    {
        ret_val = nw_vmf_ipc_send_raw(client_handle, raw_buffer);
    }
    else
    #else
    {
        ret_val = nw_vmf_ipc_send(client_handle, message, msg_size);

        UNUSED_PARAM(raw_buffer);        
#if 0        
        /* REMOVE!!!!!!!!!! */
        if (handle_db[(unsigned8)client_handle].name[0] == 'g' && 
            handle_db[(unsigned8)client_handle].name[1] == 'u' && 
            handle_db[(unsigned8)client_handle].name[2] == 'i')
        {
            unsigned16 count;
            unsigned16 watermark;

            count = vmf_ipc_get_current_count(client_handle);
            watermark = vmf_ipc_get_high_watermark(client_handle);
            fprintf(stderr, "vmf_router: %s queue: message count=%d, watermark=%d\n", handle_db[(unsigned8)client_handle].name, count, watermark);

            nw_vmf_debug_msgs("vmf_router:",handle_db[(unsigned8)client_handle].pid,(vmf_msg_t *)message);
        }
        /* REMOVE!!!!!!!!!! */
#endif
        
    }
    #endif
    if (VMF_OK != ret_val)
    {
        /* there was an error while sending the message */
        if ((nw_vmf_test_if_spy_hdl(client_handle) == false))
        {
            /* check only once for any client */
            if(false == handle_db[(unsigned8)client_handle].queue_overflown)
            {
                handle_db[(unsigned8)client_handle].queue_overflown = true;
                VMF_ROUTER_TRACE_PRINTF2(vmf_trid,VMF_TRACE_SEVERITY_ERROR_19,"vmf_server","nw_vmf_router_msg_send","Client queue overflow! cid=%d, name==%s, send error = %d, msg_size=%d!",client_handle,handle_db[(unsigned8)client_handle].name,(int)ret_val,msg_size);
                nw_vmf_router_send_dtc_overflow();
                nw_vmf_debug_msgs("",handle_db[(unsigned8)client_handle].pid,(vmf_msg_t *)message);
            }
        }

        #ifdef NW_VMF_CFG_ALLOW_KICKOUT_NON_RESPONDING_CLIENTS
        #ifdef NW_VMF_CFG_DISALLOW_KICKOUT_SPY_OR_TRACER
        /* never kick out the spy or tracer */
        if ((nw_vmf_test_if_spy_hdl(client_handle)==false) && (client_handle != trace_server_channel_handle))
        #endif /*NW_VMF_CFG_DISALLOW_KICKOUT_SPY_OR_TRACER*/
        {
            /* increase error counter and check if already at max */
            handle_db[(unsigned8)client_handle].error_count ++;
            if (handle_db[(unsigned8)client_handle].error_count >= NW_VMF_CFG_SEND_ERROR_RETRY_COUNT_MAX)
            {
                /* This client doesn't respond anymore for several times! Kick it off!!! */
                (void) nw_vmf_router_handle_db_remove (client_handle);
                (void) nw_vmf_delete_spy(client_handle);

                VMF_ROUTER_TRACE_PRINTF2(vmf_trid,VMF_TRACE_SEVERITY_ERROR,"vmf_server","nw_vmf_router_msg_send","CLIENT KICKED OFF (still queue overlow)!!! PID=%d CID=%d", handle_db[(unsigned8)client_handle].pid, handle_db[(unsigned8)client_handle].cid);
            }
        }
        #endif /* NW_VMF_CFG_ALLOW_KICKOUT_NON_RESPONDING_CLIENTS */

        /* return with ipc error */
    }
    else
    {
        /* OK */
        
        /* Increase total message count */
        vmf_total_message_count++;
        
        /* Reset error count and overflow bit */
        handle_db[(unsigned8)client_handle].error_count = 0;
    }

#ifdef NW_VMF_DEBUG_ROUTER_MESSAGES_SENT
    nw_vmf_debug_msgs("router OUT:", handle_db[(unsigned8)client_handle].pid, (vmf_msg_t *)message);
#endif

    return ret_val;
}




/*****************************************************************************
 *                                                                           *
 *    LOCAL UTILITIES                                                        *
 *                                                                           *
 *****************************************************************************/

/***************************************************************************//**
 *
 *   Add a client vmf handle to the handle db of the router
 *
 *   \param[in]     vmf_handle -- handle to define the clients channel
 *   \param[in]     pid        -- process ID from client
 *   \param[in]     cid        -- client ID
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_handle_db_add (vmf_handle_t vmf_handle, pid_t pid, vmf_client_id_t cid, char *name,unsigned16 len)
{
    vmf_ret_t       ret_val = VMF_OK;

    UNUSED_PARAM(len);

    NW_VMF_ARG_CHECK_RANGE("nw_vmf_router_handle_db_add - vmf_handle", vmf_handle, 0, MAX_IPC_CHANNELS);

    /* write data to handle db */
    handle_db[(unsigned8)vmf_handle].status = NW_VMF_HANDLE_STANDARD;
    handle_db[(unsigned8)vmf_handle].pid = pid;
    handle_db[(unsigned8)vmf_handle].cid = cid;
    nw_os_sstrncpy(handle_db[(unsigned8)vmf_handle].name, name, MAX_CTRL_CONN_PL_LEN);

    if (vmf_handle > last_handle)
    {
        last_handle = vmf_handle;
    }

#ifdef NW_VMF_DEBUG_HANDLE_DB_INFO
    unsigned8 i;

    NW_VMF_DEBUG_INFO("-- server handle_db -- \n");
    for (i=0; i<=last_handle; i++)
    {
        NW_VMF_DEBUG_INFO("\tvmf_handle: %2u \tpid: %10u \tcid: %2u \tstatus %d \n"
                            , i, handle_db[i].pid, handle_db[i].cid, handle_db[i].status);
    }
    NW_VMF_DEBUG_INFO("-- server handle_db -- \n");
#endif

    /* send new connetion name to spies */
    if ((pers_data.vmf_start_q_ena != 0) || (nw_vmf_is_spy_avail()))
    {
        (void)nw_vmf_send_connection_name_2all(vmf_handle);
    }

    VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router_handle_db_add","pid=%d, cid=%d, connection-name=%s",pid,cid,name);

    return ret_val;
}



/***************************************************************************//**
 *
 *   remove a client vmf handle from the handle db of the router
 *
 *   \param[in]     vmf_handle -- handle to define the clients channel
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_router_handle_db_remove (vmf_handle_t vmf_handle)
{
    vmf_ret_t       ret_val = VMF_OK;
    unsigned8       u8hdl;

    NW_VMF_ARG_CHECK_RANGE("nw_vmf_router_handle_db_remove - vmf_handle", vmf_handle, 0, MAX_IPC_CHANNELS);
    u8hdl = (unsigned8)vmf_handle;

    /* remove handle from db */
    if (handle_db[(unsigned8)vmf_handle].pshm  != NULL)
    {
        /* free mapped shared memory */
        (void)munmap(handle_db[u8hdl].pshm,sizeof(vmf_client_shm_t));
        handle_db[u8hdl].pshm = NULL;
        (void) nw_shm_close(handle_db[u8hdl].fdshm);
        handle_db[u8hdl].fdshm = 0;
    }

    (void)nw_vmf_ipc_destroy(vmf_handle);
    handle_db[u8hdl].status = NW_VMF_HANDLE_CLIENT_NOT_CONNECTED;
    handle_db[u8hdl].pid = 0;
    handle_db[u8hdl].cid = 0;
    handle_db[u8hdl].name[0]=0;
    return ret_val;
}



/***************************************************************************//**
 *
 *   Obtain handle of a registered client from process ID and Client ID.
 *
 *   \param[in]     pid -- client pid
 *   \param[in]     cid -- client id
 *   \return        vmf handle or error (if <0)
 *
 ******************************************************************************/
vmf_handle_t nw_vmf_router_get_client_handle (pid_t pid, vmf_client_id_t cid)
{
    vmf_handle_t    handle = VMF_HANDLE_INVALID;
    vmf_handle_t    i;


    for (i=0; i<=last_handle; i++)
    {
        if ((handle_db[(unsigned8)i].pid == pid) && (handle_db[(unsigned8)i].cid == cid))
        {
            handle = i;
            break;
        }
    }

    return handle;
}


#ifdef NW_DTC_VMF
/***************************************************************************//**
 *
 *   send dtc via vmf.
 *
 *   \param[in]     dtc
 *   \param[in]     reason
 *   \return        void
 *
 ******************************************************************************/
static void nw_vmf_router_send_dtc (unsigned8 dtc, unsigned8 reason0,unsigned8 reason1,unsigned8 reason2)
{
    VMF_VAR_BASIC_MSG_TYP(sizeof(VMF_VAR_MSG_TYP(0))) my_basic_msg;
    unsigned16 dtc_msgs_size;
    unsigned16 i;

    /* log DTC */
    my_basic_msg.msg_base.base.msg_type  = MSG_TYPE_BASIC_MESSAGE;
    my_basic_msg.msg_base.base.pid       = NW_GET_PID();
    my_basic_msg.msg_base.base.client_id = 0;
    my_basic_msg.msg_base.base.vmf_mi_server_id = 0;
    my_basic_msg.msg_base.base.co_msg_type = 0;
    my_basic_msg.msg_base.id.group       = NW_MSG__GROUPID(TX_MSG_HEAD__DTC_SET);
    my_basic_msg.msg_base.id.event       = NW_MSG__EVENTID(TX_MSG_HEAD__DTC_SET);
    my_basic_msg.data.pl[0]              = dtc;
    my_basic_msg.data.pl[1]              = reason0;
    my_basic_msg.data.pl[2]              = reason1;
    my_basic_msg.data.pl[3]              = reason2;
    my_basic_msg.data.length             = 4;
    my_basic_msg.msg_base.base.msg_clk   = NW_GET_CLOCK_CYCLES();

    dtc_msgs_size = VMF_BASIC_MSG_LEN(my_basic_msg.data.length);
    (void)nw_vmf_ipc_send(server_channel_handle, (unsigned8 *)&my_basic_msg, dtc_msgs_size);
    /* NW_DTC_VMF_CLIENT_QUEUE_OVERFLOWN */
}
#endif

/***************************************************************************//**
 *
 *   send overflown dtc via vmf.
 *
 *   \param[in]     void
 *   \return        void
 *
 ******************************************************************************/
static void nw_vmf_router_send_dtc_overflow (void)
{
    #ifdef NW_DTC_VMF_CLIENT_QUEUE_OVERFLOWN
        nw_vmf_router_send_dtc (NW_DTC_VMF_CLIENT_QUEUE_OVERFLOWN, NW_DTC_NO_SPECIFIC_REASON,0,0);
    #endif
}



/**************************************************************************//**
 *
 *   Function Name: send_connection_name()
 *
 *   Description:   send all connection names to the spy
 *
 *   \param[in]     txcid       - tx handle
 *   \param[in]     cid         - name of this connection is send
 *   \return        void
 *
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_send_connection_names (vmf_handle_t tx_handle)
{
    vmf_ret_t vmf_ret = VMF_OK;
    vmf_handle_t  handle;

    if (VMF_HANDLE_INVALID == tx_handle)
    {
        vmf_ret = VMF_ERR_ROUTER_SENDER_HANDLE_NOT_FOUND;
    }
    else
    {
        /* first send vmf connection name */
        (void)nw_vmf_send_vmf_connection_name (tx_handle);

        /* send all current connections */
        for (handle=0; handle<=last_handle; handle++)
        {
            /* ignore error because this is only a debug function */
            (void)nw_vmf_send_connection_name(tx_handle,handle);
        }
    }

    return vmf_ret;
}



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_send_connection_name_2all()
 *
 *   Description:   send a single connection name to all spies
 *
 *   \param[in]     txcid       - tx handle
 *   \param[in]     cid         - name of this connection is send
 *   \return        void
 *
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_send_connection_name_2all (vmf_handle_t client_handle)
{
        vmf_ret_t   ret_val = VMF_ERROR;
        int         cnt;

        for (cnt=0; cnt<VMF_MAX_SPY_NUM; cnt++)
        {
            if (spy_channel_handle_tab.handle[cnt] != VMF_HANDLE_INVALID)
            {
                if (VMF_OK == nw_vmf_send_connection_name(spy_channel_handle_tab.handle[cnt],client_handle))
                {
                    /* at least one spy worked */
                    ret_val = VMF_OK;
                }
            }
        }
        return ret_val;
}


/**************************************************************************//**
 *
 *   Function Name: send_connection_name()
 *
 *   Description:   send a single connection name to the spy
 *
 *   \param[in]     txcid       - tx handle
 *   \param[in]     cid         - name of this connection is send
 *   \return        void
 *
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_send_connection_name (vmf_handle_t tx_handle,vmf_handle_t client_handle)
{
    vmf_ret_t                       ret_val = VMF_OK;
    vmf_connection_name_resp_pl_t   msg;

    UNUSED_PARAM(tx_handle);

    if (VMF_HANDLE_INVALID == client_handle)
    {
        /* ignore */
        return ret_val;
    }

    if (handle_db[(unsigned8)client_handle].status != NW_VMF_HANDLE_CLIENT_NOT_CONNECTED)
    {
        if (strlen(handle_db[(unsigned8)client_handle].name) > 0)
        {
            VMF_VAR_BASIC_MSG_TYP(sizeof(vmf_connection_name_resp_pl_t)) vmf_msg;
            unsigned16  transfer_len=0;

            /* there is a name for this connection */
            /* transfer this message */
            msg.pid = handle_db[(unsigned8)client_handle].pid;
            msg.cid = handle_db[(unsigned8)client_handle].cid;
            msg.name_len = strlen(handle_db[(unsigned8)client_handle].name);
            nw_os_sstrncpy(msg.name, handle_db[(unsigned8)client_handle].name, sizeof(msg.name));
            msg.zero = 0;

            /* create a vmf basic message */
            vmf_msg.msg_base.base.msg_type  = MSG_TYPE_BASIC_MESSAGE;
            vmf_msg.msg_base.base.pid       = getmypid();
            vmf_msg.msg_base.base.client_id = 0;
            vmf_msg.msg_base.base.vmf_mi_server_id = 0;
            vmf_msg.msg_base.base.co_msg_type = 0;
            vmf_msg.msg_base.base.client_count  = spy_channel_handle_tab.num; // 1;     /* number of message receiver = 1 */
            vmf_msg.msg_base.base.msg_clk   = nw_os_cfg_get_ms_time();

            vmf_msg.msg_base.id.group = VMF_TRACE_CTRL;
            vmf_msg.msg_base.id.event = VMF_TRACE_CTRL_CONNECTION_NAMES;

            /* copy payload */
            vmf_msg.data.length = sizeof(msg) - MAX_CTRL_CONN_PL_LEN + msg.name_len;
            nw_os_smemcpy(vmf_msg.data.pl,sizeof(vmf_msg.data.pl),&msg, vmf_msg.data.length);

            transfer_len = sizeof(vmf_msg);
            ret_val = nw_vmf_router_msg_send_spy ((unsigned8*)&vmf_msg, transfer_len,NULL);
        }
    }

    return ret_val;
}


/**************************************************************************//**
 *
 *   Function Name: send_vmf_connection_name()
 *
 *   Description:   send the name of the VMF process to the spy
 *
 *   \param[in]     txcid       - tx handle
 *   \param[in]     cid         - name of this connection is send
 *   \return        void
 *
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_send_vmf_connection_name (vmf_handle_t tx_handle)
{
    #define VMF_CONN_NAME           "VMF,router"
    #define VMF_CONN_NAME_SUFFIX    "router"
    vmf_ret_t                       ret_val = VMF_OK;
    vmf_connection_name_resp_pl_t   msg;
    VMF_VAR_BASIC_MSG_TYP(sizeof(vmf_connection_name_resp_pl_t)) vmf_msg;
    unsigned16  transfer_len=0;

    UNUSED_PARAM(tx_handle);

    memset(&msg,0,sizeof(vmf_connection_name_resp_pl_t));
    msg.pid = getmypid();
    msg.cid = 0;

    if (strlen(progname)> 0)
    {
        /* progname set - so use it */
        (void) snprintf(msg.name,MAX_CTRL_CONN_PL_LEN,"%s,%s",progname,VMF_CONN_NAME_SUFFIX);
    }
    else
    {
        /* no progname set - so use default name */
        nw_os_sstrncpy(msg.name, VMF_CONN_NAME, MAX_CTRL_CONN_PL_LEN);
    }

    msg.name_len = strlen(msg.name);
    msg.zero = 0;

    /* create a vmf basic message */
    vmf_msg.msg_base.base.msg_type  = MSG_TYPE_BASIC_MESSAGE;
    vmf_msg.msg_base.base.pid       = getmypid();
    vmf_msg.msg_base.base.client_id = 0;
    vmf_msg.msg_base.base.vmf_mi_server_id = 0;
    vmf_msg.msg_base.base.co_msg_type = 0;
    vmf_msg.msg_base.base.client_count  = spy_channel_handle_tab.num; // 1;
    vmf_msg.msg_base.base.msg_clk   = nw_os_cfg_get_ms_time();

    vmf_msg.msg_base.id.group = VMF_TRACE_CTRL;
    vmf_msg.msg_base.id.event = VMF_TRACE_CTRL_CONNECTION_NAMES;

    /* copy payload */
    vmf_msg.data.length = sizeof(msg) - MAX_CTRL_CONN_PL_LEN + msg.name_len;
    nw_os_smemcpy(vmf_msg.data.pl,sizeof(vmf_msg.data.pl),&msg, vmf_msg.data.length);

    transfer_len = sizeof(vmf_msg);
    ret_val = nw_vmf_router_msg_send_spy ((unsigned8*)&vmf_msg, transfer_len,NULL);
#if 0
    fprintf(stderr,"nw_vmf_send_vmf_connection_name(%s) at %lu\n",msg.name,(long unsigned int)vmf_msg.msg_base.base.msg_clk );
#endif
    return ret_val;
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_spy_init()
 *
 *   Description:   init the spy table
 *
 *   \param[in]     void
 *
 *   \return        void
 *
 ******************************************************************************/
static void    nw_vmf_spy_init(void)
{
    int         cnt;

    for (cnt=0; cnt<VMF_MAX_SPY_NUM; cnt++)
    {
        spy_channel_handle_tab.handle[cnt] = VMF_HANDLE_INVALID;
    }
     spy_channel_handle_tab.num=0;
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_add_spy()
 *
 *   Description:   add a handle to the spy table
 *
 *   \param[in]     spy_handle       - handle
 *
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t    nw_vmf_add_spy(vmf_handle_t spy_handle)
{
    vmf_ret_t   ret_val=VMF_ERR_OUT_OF_MEMORY;
    int         cnt;

    for (cnt=0; cnt<VMF_MAX_SPY_NUM; cnt++)
    {
        if (spy_handle==spy_channel_handle_tab.handle[cnt])
        {
            /* already connected */
            ret_val = VMF_OK;
            break;
        }
        else if (VMF_HANDLE_INVALID==spy_channel_handle_tab.handle[cnt])
        {
            /* found free entry */
            spy_channel_handle_tab.handle[cnt] = spy_handle;
            spy_channel_handle_tab.num++;
            ret_val = VMF_OK;
            VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_add_spy","handle=%d, num-spies=%d",spy_handle,spy_channel_handle_tab.num);
            break;
        }
    }
    return ret_val;
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_delete_spy()
 *
 *   Description:   delete a handle from the spy table
 *
 *   \param[in]     spy_handle       - handle
 *
 *   \return        vmf_ret_t   VMF_OK if spy was deletet,
 *                              VMF_ERROR if handle was no-spy handle
 *
 ******************************************************************************/
vmf_ret_t    nw_vmf_delete_spy(vmf_handle_t spy_handle)
{
    vmf_ret_t   ret_val=VMF_ERROR;
    int         cnt;

    for (cnt=0; cnt<VMF_MAX_SPY_NUM; cnt++)
    {
        if (spy_handle==spy_channel_handle_tab.handle[cnt])
        {
            /* found the handle */
            spy_channel_handle_tab.handle[cnt] = VMF_HANDLE_INVALID;
            spy_channel_handle_tab.num--;
            ret_val = VMF_OK;
            VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_delete_spy","handle=%d, num-spies=%d",spy_handle,spy_channel_handle_tab.num);
            break;
        }
    }
    return ret_val;
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_test_if_spy_hdl()
 *
 *   Description:   test if handle is a a spy handle
 *
 *   \param[in]     spy_handle  vmf_handle
 *
 *   \return        bool       true if spy handle else false
 *
 ******************************************************************************/
static bool    nw_vmf_test_if_spy_hdl(vmf_handle_t spy_handle)
{
    bool        ret_val=false;
    int         cnt;

    for (cnt=0; cnt<VMF_MAX_SPY_NUM; cnt++)
    {
        if (spy_handle==spy_channel_handle_tab.handle[cnt])
        {
            /* found handle */
            ret_val = true;
            break;
        }
    }
    return ret_val;

}

/**************************************************************************//**
 *
 *   Function Name: nw_vmf_is_spy_avail()
 *
 *   Description:   test if at least one spy is registered
 *
 *   \param[in]     void
 *
 *   \return        bool        bool if there is at least one spy else false
 *
 ******************************************************************************/
bool    nw_vmf_is_spy_avail(void)
{
    bool ret_val = false;
    
    if (spy_channel_handle_tab.num > 0)
    {
        ret_val = true;
    }
    
    return ret_val;
}


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
static inline unsigned32 getmypid(void)
{
    static unsigned32 u32myPid = 0;

    if (0 == u32myPid )
    {
        u32myPid= nw_os_getpid();
    }
    return u32myPid;
}




/***************************************************************************//**
 *
 *   map the client shared memory and store address in handle_db
 *
 *   \param[in]     vmf_handle -- handle to define the clients channel
 *
 *   \return        vmf return type
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_router_map_client_shm (vmf_handle_t client_handle)
{
    char            ShmName[MAX_NAME_LEN]={0};
    vmf_ret_t       ret_val;
    pid_t           pid;
    vmf_client_id_t cid;
    unsigned8       u8hdl;

    NW_VMF_ARG_CHECK_RANGE("nw_vmf_router_map_client_shm - vmf_handle", client_handle, 0, MAX_IPC_CHANNELS);
    u8hdl = (unsigned8)client_handle;

    if (handle_db[u8hdl].status == NW_VMF_HANDLE_CLIENT_NOT_CONNECTED)
    {
        ret_val = VMF_ERR_INVALID_VMF_HANDLE;
    }
    else if (handle_db[u8hdl].pshm != NULL)
    {
        /* already mapped */
        ret_val = VMF_OK;
    }
    else
    {
        pid = handle_db[u8hdl].pid;
        cid = handle_db[u8hdl].cid;

        /* get shared memory name */
        ret_val = nw_vmf_create_shm_channel_name(pid, cid, ShmName, sizeof(ShmName));
    }

    if (VMF_OK == ret_val)
    {
        int fd;

        /* open the shared memory */
        fd = nw_shm_open(ShmName);
        if (-1 == fd)
        {
            /* shm open failed */
            VMF_ROUTER_TRACE_PRINT(vmf_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_server","nw_vmf_router_map_client_shm","shm_open() failed");
            ret_val = VMF_ERROR;
        }
        else
        {
            vmf_client_shm_t    *pshm;

            /* shm is open - map it now */
            pshm = mmap(NULL, sizeof(vmf_client_shm_t), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
            if (pshm == (void*)MAP_FAILED)
            {
                /* mmap failed */
                (void) nw_shm_close(fd);
                VMF_ROUTER_TRACE_PRINT(vmf_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_server","nw_vmf_router_map_client_shm","mmap() failed");
            }
            else
            {
                handle_db[u8hdl].pshm = pshm;
                handle_db[u8hdl].fdshm = fd;
            }
        }
    }

    return ret_val;
}


/***************************************************************************//**
 *
 *   get the string string from a string that includes "<process-name>, <connection-strin>
 *
 *   \param[in]     pointer to input string
 *
 *   \return        pointer to beginning of connection string
 *
 ******************************************************************************/
static char *get_conn_string(char *in_str)
{
    char *ptr;

    ptr = strchr(in_str,',');
    return ptr+1;
}


/***************************************************************************//**
 *
 *   initialize the spy group registration of a single spy
 *
 *   \param[in]     group
 *
 *   \return       void
 *
 ******************************************************************************/
static void vmf_router_init_spy_groups( void)
{
    /* first register all groups as spy groups */
    memset(vmf_spy_groups,VMF_ROUTER_SPY_GROUP,sizeof(vmf_spy_groups));

    /* now deregister some groups */
    #ifdef FILTER_SPY_TRACE
    vmf_router_deregister_spy_group( VMF_TRACE_IN);
    vmf_router_deregister_spy_group( VMF_TRACE_OUT);
    vmf_router_deregister_spy_group( VMF_TRACE_IPC_DATA);
    vmf_router_deregister_spy_group( VMF_TRACE_SYSINFO_CTRL);
    vmf_router_deregister_spy_group( VMF_TRACE_SYSINFO_DATA);
    #endif
}


/***************************************************************************//**
 *
 *   register a group for of a single spy
 *
 *   \param[in]     group
 *
 *   \return        void
 *
 ******************************************************************************/
static void vmf_router_deregister_spy_group( unsigned8 group)
{
    if (group < MAX_GROUP_NUM)
    {
        vmf_spy_groups[group] = VMF_ROUTER_NO_SPY_GROUP;
    }
}

/***************************************************************************//**
 *
 *   de-register a group for of a single spy
 *
 *   \param[in]     group
 *
 *   \return        void
 *
 ******************************************************************************/
static void vmf_router_register_spy_group( unsigned8 group)
{
    if (group < MAX_GROUP_NUM)
    {
        vmf_spy_groups[group] = VMF_ROUTER_SPY_GROUP;
    }
}


/***************************************************************************//**
 *
 *   check if  a group is registered for single spy
 *
 *   \param[in]     group
 *
 *   \return        true is group is registered for that spy
 *
 ******************************************************************************/
static bool vmf_router_check_spy_group( unsigned8 group)
{
    bool bret = false;

    if (group < MAX_GROUP_NUM)
    {
        if (VMF_ROUTER_SPY_GROUP == vmf_spy_groups[group])
        {
            bret = true;
        }
    }
    return bret;
}



#undef _NW_VMF_ROUTER_C_
