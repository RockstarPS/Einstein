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

  Module:               nw_vmf_client.c
  Description:          Main routine for the message framework lib

  Project Scope:        Beethoven VM platform

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   gcc
  Target Hardware:      Any

  *****************************************************************************/
#define VMF_CLIENT_C

//#define DO_CLIENT_DEBUG
//#define DO_CLIENT_DEBUG_HEX

#define VMF_MESSAGE_COLLECTOR

#ifndef UNIT_TEST
    #include "nw_os_config.h"

    /* application includes */
    #include "nw_vmf_types.h"
    #include "nw_vmf_ipc.h"
    #include "nw_vmf_debug.h"
    #include "nw_vmf_client_private.h"
    #include "nw_vmf_client.h"
    #include "nw_vmf_cfg.h"           /* vmf cfg file */

    #include "nw_config.h"
    #include "nw_vmf_timer.h"
    #ifdef VMF_TRACE
    #include "nw_vmf_trace_server.h"
    #endif
    #ifdef VMF_REM
    #include "nw_vmf_rem_types.h"
    #endif

#else
    #include "nw_os_config.h"

    /* application includes */
    #include "nw_vmf_types.h"
    #include "nw_vmf_ipc.h"
    #include "nw_vmf_debug.h"
    #include "nw_vmf_client.h"
    #include "nw_vmf_cfg.h"           /* vmf cfg file */
    #include "stub_debug_print.h"
    #include "stub_vmf_client.h"

    #include "nw_config.h"
#endif

/*! Macro to suppress Compiler warning of un-referenced variables */
#ifndef UNUSED_PARAM
#define UNUSED_PARAM(x) ((void)(x))
#endif


#ifdef NW_VMF_CFG_ALLOW_SHADOW_WITH_EMPTY_FUNCTION_LIST
#define ALLOW_EMPTY_SH_LIST
#endif

extern char *__progname;                                        /* name of the current running process - should work in QNX and Linux */
extern char progname[];                                         /* name of the current running process - should work in QNX and Linux */

/************** typedefs ********************/


/*************** MACROS *********************/
#define VMF_CLIENT_LOCK                                                                                     \
        {                                                                                                   \
            if (pthread_mutex_lock((&myMutex)) != 0)                                                        \
            {                                                                                               \
                NW_VMF_CLIB_DEBUG_ERROR("VMF-CLient-Lib: mutex Lock Failed %s line %d\n", __FILE__, __LINE__);   \
            }                                                                                               \
        }

#define VMF_CLIENT_UNLOCK                                                                                   \
        {                                                                                                   \
            if (pthread_mutex_unlock((&myMutex)) != 0)                                                      \
            {                                                                                               \
                NW_VMF_CLIB_DEBUG_ERROR("VMF-CLient-Lib: mutex Unlock Failed %s line %d\n", __FILE__, __LINE__); \
            }                                                                                               \
        }


#ifdef DO_CLIENT_DEBUG
    #define NW_VMF_CLIB_DEBUG_INFO(args...)      NW_VMF_DEBUG_INFO(args)
    #define NW_VMF_CLIB_DEBUG_INFO2(args...)     NW_VMF_DEBUG_INFO(args)
#else
    #define NW_VMF_CLIB_DEBUG_INFO(args...)
    #define NW_VMF_CLIB_DEBUG_INFO2(args...)
#endif
#define NW_VMF_CLIB_DEBUG_ERROR(args...)     NW_VMF_DEBUG_ERROR(args)

#define VMF_MUTEX_INIT      {;}

#define MAX_CID             (cid_tab.free_cid)
#define CID_TX_HDL(cid)     (cid_tab.my_cid[cid].tx_handle)
#define CID_RX_HDL(cid)     (cid_tab.my_cid[cid].rx_handle)
#ifndef FOREVER
#define FOREVER             (true)
#endif
#define VMF_CLIENT_CONSTATE_MIN_TIME    1000    /* allowed time between two connection status checks */


/************** module global variables ************/
static bool                    init_done=false;
static bool                    cid_tab_init_done=false;                /*!< true if cd-table is initialized */
static my_cid_tab_t            cid_tab;                                /*!< cid table */
static pthread_mutex_t         myMutex = PTHREAD_MUTEX_INITIALIZER;
static bool                    nw_vmf_ipc_init_done = false;
static pthread_mutex_t         shm_mutex = PTHREAD_MUTEX_INITIALIZER;

#ifdef VMF_TRACE
static vmf_trace_shm_t     *vmf_trace_shm=NULL;
#endif

/************ local functions **************/
static vmf_ret_t        nw_vmf_register_client      (vmf_client_id_t vmf_client_id,const char *my_channel_name,vmf_handle_t tx_handle,vmf_handle_t p2p_handle,vmf_handle_t rx_handle,my_cid_tab_t *pcid_tab, unsigned8 unpack_spy_msgs);
static void             nw_vmf_ini_cid_tab          (my_cid_tab_t *pcid_tab);
static inline vmf_client_id_t  nw_vmf_client_get_free_cid  (my_cid_tab_t *pcid_tab);
static inline vmf_handle_t     nw_vmf_client_get_rx_hdl    (vmf_client_id_t vmf_client_id,my_cid_tab_t *pcid_tab);
static inline vmf_handle_t     nw_vmf_client_get_tx_hdl    (vmf_client_id_t vmf_client_id,my_cid_tab_t *pcid_tab);
static void             nw_vmf_free_cid             (vmf_client_id_t vmf_client_id);
static inline unsigned32 getmypid(void);

#if 0 
/* jmerkle 2016-08-16 -- function not used! */
static inline vmf_handle_t     nw_vmf_client_get_p2p_hdl   (vmf_client_id_t vmf_client_id,my_cid_tab_t *pcid_tab);
#endif

static vmf_ret_t nw_vmf_co_client_init_buffer       (vmf_client_id_t vmf_client_id, signed32 timeout,my_cid_tab_t *pcid_tab);
static vmf_ret_t nw_vmf_co_basic_send               (vmf_client_id_t vmf_client_id, vmf_basic_msg_t  *pvmf_msg, unsigned16 msg_len);
static vmf_ret_t nw_vmf_co_receive                  (vmf_client_id_t vmf_client_id,unsigned16 dest_buffer_len,vmf_basic_msg_t *pdest_vmf_msg,unsigned16 *dest_read_num_bytes);
static vmf_ret_t nw_vmf_co_store_msg                (vmf_client_id_t vmf_client_id, vmf_basic_msg_t *pco_vmf_msg,unsigned16 co_vmf_msg_len);
static void vw_vmf_co_tx_timeout_cb                 (unsigned32 system_time_ms,void *arg);
static vmf_ret_t nw_vmf_init_shm                    (vmf_client_shm_t *pshm);
static vmf_ret_t nw_vmf_tx_shm_req                  (vmf_client_id_t   cid);


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_client_init ()
 *   Description:   initialize the vmf client
 *                  this has to becalled before connecting to the VMF server
 *
 *
 *   Parameters:    void
 *
 *   Return value:   \return  vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_client_init(void)
{
    if (init_done != false)
    {
        /* already initialized */
        delay(1);
    }
    else
    {
        init_done = true;

        if (strlen(progname) == 0)
        {
            (void) nw_get_app_name(progname,MAX_PROGNAME_LEN);
        }
    }

    return VMF_OK;
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_connect_p2p ()\n
 *   Description:   establis a p2p connection to another vmf client  \n
 *                  A tx channel to the destination client is opened \n
 *                  and an rx channel for this client is created.    \n
 *
 *
 *   Parameters:    my_process_name                     (input) text-identifier or NULL\n
 *                  dest_pid()                          (input) pid if destination-client \n
 *                  vmf_collector_timeout               (input) cid of destination client \n
 *                  message_queue_size                  (input) length of message queue in number of messages
 *                  message_size                        (input) size of a single message in the queue
 *   Return value:  \return if >0  then client-id else error as vmf_ret_t\n
 *
 ******************************************************************************/
vmf_client_id_t nw_vmf_connect_p2p( const char *p_my_conn_string,       /*!< INPUT channel name or NULL  */
                                    pid_t           dest_pid,           /*!< INPUT destination pid  */
                                    vmf_client_id_t dest_cid,           /*!< INPUT destination cid  */
                                    unsigned16 message_queue_size,      /*!< INPUT queue size for receiving messages */
                                    unsigned16 message_size )           /*!< INPUT message size for the receive queue */
{
    nw_vmf_connect_ctrl_t   ctrl;
    char                    dest_channel_name[MAX_NAME_LEN]={0};
    char                    myShmName[MAX_NAME_LEN]={0};
    int                     current_timeout=0;
    int                     fd=0;
    vmf_handle_t            p2p_handle=VMF_HANDLE_INVALID;
    vmf_client_id_t         cid=0;
    vmf_ret_t               ret_val = VMF_OK;
    vmf_client_shm_t        *pcl_shm = NULL;

    /* argument check */
    if (0 == dest_pid)
    {
        ret_val = VMF_ERR_INVALID_ARG;
    }
    else if (dest_cid <= 0)
    {
        ret_val = VMF_ERR_INVALID_CID;
    }
    else
    {
        /* get destination channel name */
        ret_val = nw_vmf_ipc_create_channel_name(dest_pid, dest_cid, dest_channel_name, sizeof(dest_channel_name));
    }

    if (VMF_OK == ret_val)
    {
        /* try to open connection to p2p destination                                            */
        /* try for VMF_CLIENT_WAIT_SERVER_TIMEOUT milliseconds before returning with an error   */
        p2p_handle = VMF_ERROR;
        while (p2p_handle < 0)
        {
            NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_ipc_open");
            p2p_handle = nw_vmf_ipc_open(dest_channel_name,IPC_BLOCKING);
            if (p2p_handle < 0)
            {
                /* an error occured - try again */
                if (current_timeout >= VMF_CLIENT_WAIT_SERVER_TIMEOUT)
                {
                    /* abort */
                    NW_VMF_DEBUG_ERROR("pid=%d, vmf-client-lib: nw_vmf_connect_p2p() - nw_vmf_ipc_open() failed\n",(int)getmypid());
                    break;;
                }

                current_timeout += VMF_CLIENT_WAIT_SOME_TIME;
                delay(VMF_CLIENT_WAIT_SOME_TIME);
            }
        }

        /* test if a connection to the destination was established */
        if ((VMF_HANDLE_INVALID == p2p_handle) || (p2p_handle < 0))
        {
            NW_VMF_DEBUG_ERROR("pid=%d, vmf-client-lib: nw_vmf_connect_p2p() - connection to destination failed\n",(int)getmypid());
            ret_val = ((vmf_client_id_t)VMF_ERROR);
        }
    }
    else
    {
        NW_VMF_DEBUG_ERROR("pid=%d, vmf-client-lib: nw_vmf_connect_p2p() - nw_vmf_ipc_create_channel_name() failed",(int)getmypid());
    }

    if(VMF_OK == ret_val)
    {
        /* connect to vmf server and create a message queue */
        ctrl.p2p_handle = p2p_handle;
        cid = nw_vmf_connect( p_my_conn_string,&ctrl,0,message_queue_size,message_size);
        if (cid < INITAL_CID_VALUE)
        {
            /* error connecting to vmf server */
            /* free all resources             */
            (void) nw_vmf_ipc_close(p2p_handle);
            NW_VMF_DEBUG_ERROR("pid=%d, vmf-client-lib: nw_vmf_connect_p2p() - nw_vmf_connect() failed\n",(int)getmypid());
            ret_val=(vmf_client_id_t)cid;   /* copy error to retval */
        }
    }

    /* create own shared-memory name */
    if (VMF_OK == ret_val)
    {
        ret_val=nw_vmf_create_shm_channel_name(cid_tab.pid, cid, myShmName, sizeof(myShmName));
    }

    /* create shared memory for this channel */
    if (VMF_OK == ret_val)
    {
        fd = nw_shm_create(myShmName, 0777,sizeof(vmf_client_shm_t));
        if (fd == -1)
        {
            NW_VMF_DEBUG_ERROR("pid=%d, vmf-client-lib: nw_vmf_connect_p2p() - nw_shm_create() failed\n",(int)getmypid());
            ret_val = VMF_ERR_SHM;
        }
    }
    
    /* map own shared  memory */
    if (VMF_OK == ret_val)
    {
        pcl_shm = (vmf_client_shm_t*)mmap(NULL, sizeof(vmf_client_shm_t), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
        if (pcl_shm == (vmf_client_shm_t*)MAP_FAILED)
        {
            NW_VMF_DEBUG_ERROR("pid=%d, vmf-client-lib: nw_vmf_connect_p2p() - mmap() failed\n",(int)getmypid());
            (void)nw_shm_close(fd);
            ret_val = VMF_ERR_SHM;
        }
        else
        {
            /* init shared memory */
            ret_val = nw_vmf_init_shm(pcl_shm);
            /* store shm addr */
            cid_tab.my_cid[cid].pcl_shm = pcl_shm;
            cid_tab.my_cid[cid].fd_shm =  fd;
        }
    }

    /* return cid if there was no error */
    if (VMF_OK == ret_val)
    {
        ret_val=(vmf_client_id_t)cid;
    }

    return ret_val;
}



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_connect (const char *pmy_process_name[31],
 *                                  void * cb_api_vmf_msg_receive_callback())\n
 *   Description:   register as a client to the vmf-server\n
 *                  A tx channel to the server is opened and an rx channel for this client is created.
 *
 *
 *   Parameters:    my_process_name                     (input) text-identifier or NULL\n
 *                  cb_api_vmf_msg_receive_callback()   not supported - always NULL\n
 *                  vmf_collector_timeout               (input) vmf collector timeout in ms or 0 if no timeout\n
 *                  message_queue_size                  (input) length of message queue in number of messages
 *                  message_size                        (input) size of a single message in the queue
 *   Return value:  \return if >0  then client-id else error as vmf_ret_t\n
 *
 ******************************************************************************/
vmf_client_id_t nw_vmf_connect( const char *p_my_conn_string,       /*!< INPUT channel name or NULL  */
                                void *vctrl,                        /*!< INPUT pointer to ctrl struct */
                                signed32 vmf_collector_timeout,     /*!< INPUT vmf collector timeout */
                                unsigned16 message_queue_size,      /*!< INPUT queue size for receiving messages */
                                unsigned16 message_size )           /*!< INPUT message size for the queue */
{
    char                    myChannelName[MAX_NAME_LEN] = {0};
    nw_vmf_connect_ctrl_t   *pctrl = NULL;
    vmf_handle_t            tx_handle = VMF_HANDLE_INVALID;
    vmf_handle_t            p2p_handle = VMF_HANDLE_INVALID;
    vmf_handle_t            rx_handle=VMF_HANDLE_INVALID;
    vmf_client_id_t         my_client_id=0;
    vmf_ret_t               vmf_ret=VMF_OK;
    int                     current_timeout=0;
    unsigned8               unpack_spy_msgs = 0;

    if (false == init_done)
    {
        (void) nw_vmf_client_init();
    }

    VMF_MUTEX_INIT
    VMF_CLIENT_LOCK

    NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_connect()");

    /* init cid table */
    nw_vmf_ini_cid_tab(&cid_tab);

    pctrl = (nw_vmf_connect_ctrl_t*)vctrl;
    if (pctrl != NULL)
    {
        p2p_handle = pctrl->p2p_handle;
        unpack_spy_msgs = pctrl->unpack_vmf_spy_msgs;
    }

    /* init IPC */
    if (!nw_vmf_ipc_init_done)
    {
        NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_connect init ipc");
        while (true)
        {
            vmf_ret = nw_vmf_ipc_init(false);
            if (VMF_OK == vmf_ret)
            {
                break;
            }
            delay(VMF_CLIENT_WAIT_SOME_TIME);
        }

        NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_connect init ipc done");
        nw_vmf_ipc_init_done = true;
    }

    /* get a free cid */
    NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_client_get_free_cid");
    my_client_id = nw_vmf_client_get_free_cid(&cid_tab);
    if (my_client_id >= MAX_SERVER_CONNECTIONS)
    {
        NW_VMF_DEBUG_ERROR("pid=%d, vmf-client-lib: nw_vmf_connect() - nw_vmf_client_get_free_cid() failed",(int)getmypid());
        vmf_ret = ((vmf_client_id_t)VMF_ERROR);
    }

    if(VMF_OK == vmf_ret)
    {
        /* init collector buffer if collector timeout set */
        if (vmf_collector_timeout > 0)
        {
            NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_co_client_init_buffer");
            vmf_ret = nw_vmf_co_client_init_buffer (my_client_id, vmf_collector_timeout ,&cid_tab);
            if (VMF_OK != vmf_ret)
            {
                NW_VMF_DEBUG_ERROR("pid=%d, vmf-client-lib: nw_vmf_connect() - nw_vmf_co_client_init_buffer() failed\n",(int)getmypid());
            }
        }

        /* try to open a tx channel to the vmf-Server */
        tx_handle = VMF_ERROR;
        while (tx_handle < 0)
        {
            NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_ipc_open");
            tx_handle = nw_vmf_ipc_open(IPC_SERVER_CHANNEL_NAME,IPC_BLOCKING);
            if (tx_handle < 0)
            {
                /* an error occured - try again */
                if (current_timeout >= VMF_CLIENT_WAIT_SERVER_TIMEOUT)
                {
                    /* abort */
                    NW_VMF_DEBUG_ERROR("pid=%d, vmf-client-lib: nw_vmf_connect() - nw_vmf_ipc_open() failed\n",(int)getmypid());
                    break;;
                }

                current_timeout += VMF_CLIENT_WAIT_SOME_TIME;
                delay(VMF_CLIENT_WAIT_SOME_TIME);
            }
        }

        /* test if a connection to the server was established */
        if ((VMF_HANDLE_INVALID == tx_handle) || (tx_handle < 0))
        {
            NW_VMF_DEBUG_ERROR("pid=%d, vmf-client-lib: nw_vmf_connect() - connection to server failed\n",(int)getmypid());
            vmf_ret = ((vmf_client_id_t)VMF_ERROR);
        }
    }
    
    if(VMF_OK == vmf_ret)
    {
        if (message_queue_size > 0)
        {
            vmf_ctrl_msg_connect_t  myCtrlConMsg;
            char        pl[MAX_CTRL_CONN_PL_LEN];
            unsigned16  cstr_len=0;

            /* get channel name */
            vmf_ret = nw_vmf_ipc_create_channel_name(cid_tab.pid, my_client_id, myChannelName, sizeof(myChannelName));
            if (VMF_OK == vmf_ret)
            {
                NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: created channel name=%s",myChannelName);

                /* create own rx channel */
                NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_ipc_create()");
                rx_handle=nw_vmf_ipc_create(myChannelName, message_queue_size, message_size);
                NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_ipc_create() done - rx_handle=%d",rx_handle);
                if ((VMF_HANDLE_INVALID == rx_handle) || (rx_handle < 0))
                {
                    NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_connect() - nw_vmf_ipc_create() myChannelName=%s\n",(int)getmypid(),myChannelName);
                    vmf_ret = ((vmf_client_id_t)VMF_ERROR);
                }
                else
                {
                    /* prepare and send the connect-control-message */
                    memset(&myCtrlConMsg,0,sizeof(vmf_ctrl_msg_connect_t));
                    myCtrlConMsg.base.msg_type  = MSG_TYPE_CONNECT;
                    myCtrlConMsg.base.pid       = cid_tab.pid;
                    myCtrlConMsg.base.client_id = my_client_id;
                    myCtrlConMsg.base.msg_clk   = nw_os_cfg_get_ms_time();

                    NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: prepare tx payload");
                    NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: progname=%s",progname);

                    /* add process name and connection string to message */
                    /* create prefix == process name */
                    memset(pl,0,sizeof(pl));
                    if (strlen(progname)!=0)
                    {
                        (void) snprintf(pl,sizeof(pl),"%s,",progname);
                    }
                    else
                    {
                        (void) snprintf(pl,sizeof(pl),"%s,",NW_VMF_CLIENT_UNDEFINED);
                    }

                    #ifdef VMF_REM
                    /* add suffix == connection string */
                    {
                        char        tmp[NW_VMF_RPC_CONN_MAX_NAME_LEN+1];
                        unsigned8   pl_len = strlen(pl);

                        memset(tmp,0,sizeof(tmp));
                        if (NULL != p_my_conn_string)
                        {
                            nw_os_sstrncpy(tmp, p_my_conn_string, NW_VMF_RPC_CONN_MAX_NAME_LEN);
                            strncat(pl,tmp, sizeof(pl)-pl_len-1);
                        }
                        else
                        {
                            strncat(pl,NW_VMF_CLIENT_UNDEFINED,sizeof(pl)-pl_len-1);
                        }
                    }
                    #endif

                    NW_VMF_CLIB_DEBUG_INFO("vmf_client_lib- conn-name=%s",pl);
                    NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: prepare tx payload part2");
                    cstr_len = strlen(pl);               /* length of connection string without zero */

                    if (cstr_len > sizeof(myCtrlConMsg.pl_data)-1)
                    {
                        cstr_len = sizeof(myCtrlConMsg.pl_data)-1;
                    }

                    myCtrlConMsg.pl_len = cstr_len+1;    /* payload length = string-length + 1 for zero */
                    nw_os_sstrncpy(myCtrlConMsg.pl_data, pl, cstr_len);
                    NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_ipc_send()");
                    vmf_ret = nw_vmf_ipc_send (tx_handle, (unsigned8*)&myCtrlConMsg, sizeof(myCtrlConMsg));
                    NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_ipc_send() done");
                    if (VMF_OK != vmf_ret)
                    {
                        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_connect() - nw_vmf_ipc_send() failed\n",(int)getmypid());
                        (void)nw_vmf_ipc_close(tx_handle);
                        (void)nw_vmf_ipc_destroy(rx_handle);
                    }
                    else
                    {
                        NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_ipc_send(MSG_TYPE_CONNECT)- OK\n");
                    }
                }
            }
            else
            {
                NW_VMF_DEBUG_ERROR("pid=%d, vmf-client-lib: nw_vmf_connect() - nw_vmf_ipc_create_channel_name() failed\n",(int)getmypid());
            }
        }
    }

    if (VMF_OK == vmf_ret)
    {
        /* register connection-id, connection name and handles */
        NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_register_client(%s)",p_my_conn_string);
        vmf_ret = nw_vmf_register_client (my_client_id,p_my_conn_string,tx_handle,p2p_handle,rx_handle,&cid_tab,unpack_spy_msgs);
        if (VMF_OK == vmf_ret)
        {
            #if VMF_IPC_TYPE == VMF_CTRL_IPC_SHM
            //#ifdef VMF_IPC_SHM
            if (rx_handle != VMF_HANDLE_INVALID)
            {
                (void)nw_vmf_ipc_register_queue_name(rx_handle,p_my_conn_string);
            }
            #endif
        }
        else
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_connect() - register_client() failed\n",(int)getmypid());
            (void)nw_vmf_ipc_close(tx_handle);
            (void)nw_vmf_ipc_destroy(rx_handle);
        }
    }

    if (VMF_OK != vmf_ret)
    {
        my_client_id = vmf_ret;
    }

    VMF_CLIENT_UNLOCK

    if (NULL == p_my_conn_string)
    {
        NW_VMF_CLIB_DEBUG_INFO("pid=%d vmf-client-lib: nw_vmf_connect() - cid=%d()",(int)getmypid(),my_client_id);
    }
    else
    {
        NW_VMF_CLIB_DEBUG_INFO("pid=%d vmf-client-lib: nw_vmf_connect(%s) - cid=%d()",(int)getmypid(),p_my_conn_string,my_client_id);
    }
    return (my_client_id);
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_disconnect (vmf_client_id_t vmf_client_id)\n
 *   Description:   disconnect client \n
 *                  close tx channel and close and destroy rx channel.
 *
 *
 *   Parameters:    cid                                 (input) client id\n
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_disconnect( vmf_client_id_t vmf_client_id)      /*!< client id */
{
    vmf_ret_t                   vmf_ret;
    vmf_ctrl_msg_connect_t      myCtrlConMsg;
    VMF_VAR_BASIC_MSG_TYP(0)    vmf_basic_msg;
    vmf_basic_msg_t *           p_vmf_basic_msg = (vmf_basic_msg_t *) &(vmf_basic_msg);

    NW_VMF_CLIB_DEBUG_INFO("pid=%d vmf-client-lib: nw_vmf_disconnect(%d)",(int)getmypid(),vmf_client_id);

    /* argument check */
    if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_disconnect()- argument error: invalid vmf_client_id=%d",(int)getmypid(),vmf_client_id);
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else if (cid_tab.my_cid[(unsigned8)vmf_client_id].in_use == false)
    {
        /* already disconnected */
        NW_VMF_CLIB_DEBUG_INFO("pid=%d vmf-client-lib: nw_vmf_disconnect(%d) already disconnected",(int)getmypid(),vmf_client_id);
        vmf_ret = (VMF_OK);
    }
    else
    {
        /* prepare and send disconnect-control-message */
        myCtrlConMsg.base.msg_type  = MSG_TYPE_DISCONNECT;
        myCtrlConMsg.base.pid       = cid_tab.pid;
        myCtrlConMsg.base.client_id = vmf_client_id;
        myCtrlConMsg.base.msg_clk   = nw_os_cfg_get_ms_time();
        myCtrlConMsg.pl_len = 0;

        vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab), (unsigned8*)&myCtrlConMsg, sizeof(myCtrlConMsg));
        if (VMF_OK != vmf_ret)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_disconnect() - nw_vmf_ipc_send() failed",(int)getmypid());
            /* ignore the error */
        }

        /* free buffer */
        nw_vmf_co_client_free_buffer(cid_tab.my_cid[(unsigned8)vmf_client_id].pcol_rx_buffer);
        cid_tab.my_cid[(unsigned8)vmf_client_id].pcol_rx_buffer = NULL;
        nw_vmf_co_client_free_buffer(cid_tab.my_cid[(unsigned8)vmf_client_id].pcol_tx_buffer);
        cid_tab.my_cid[(unsigned8)vmf_client_id].pcol_tx_buffer = NULL;

        /* send a dummy message to free resources (get rid of receiver) */
        p_vmf_basic_msg->msg_base.base.msg_type  = MSG_TYPE_BASIC_MESSAGE;
        p_vmf_basic_msg->msg_base.base.pid       = cid_tab.pid;
        p_vmf_basic_msg->msg_base.base.client_id = vmf_client_id;
        p_vmf_basic_msg->msg_base.base.vmf_mi_server_id = 0;
        p_vmf_basic_msg->msg_base.base.co_msg_type = 0;
        p_vmf_basic_msg->msg_base.base.msg_clk   = 0;
        p_vmf_basic_msg->data.length = 0;
        (void) nw_vmf_ipc_send(nw_vmf_client_get_rx_hdl(vmf_client_id,&cid_tab),(unsigned8*)p_vmf_basic_msg, sizeof(vmf_basic_msg));

        /* close the tx channel */
        NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_connect() close ipc-hdl %d",nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab));
        (void)nw_vmf_ipc_close(nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab));

        /* close and destroy rx channel */
        NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_connect() destroy ipc-hdl %d",nw_vmf_client_get_rx_hdl(vmf_client_id,&cid_tab));
        (void)nw_vmf_ipc_destroy(nw_vmf_client_get_rx_hdl(vmf_client_id,&cid_tab));

        /* free shm buffer if 2p2 connection */
        if (cid_tab.my_cid[(unsigned8)vmf_client_id].pcl_shm != NULL)
        {
            (void)munmap(cid_tab.my_cid[(unsigned8)vmf_client_id].pcl_shm,sizeof(vmf_client_shm_t));
            (void)nw_shm_close(cid_tab.my_cid[(unsigned8)vmf_client_id].fd_shm);
        }

        nw_vmf_free_cid(vmf_client_id);
    }

    return(vmf_ret);

}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_connect_async (const char *pmy_process_name[31],
 *                                  void * cb_api_vmf_msg_receive_callback())\n
 *   Description:   register as a client to the vmf-server\n
 *                  A tx channel to the server is opened and an rx channel for this client is created.
 *
 *
 *   Parameters:    my_process_name                    (input) text-identifier or NULL\n
 *                  cb_api_vmf_msg_receive_callback()  rx callback function or NULL\n
 *                  callback_priority                  (input) priority of the callback thread\n
 *                  message_queue_size                 (input) size of the message queue \n
 *                  message_size                       (input) size of a single message \n
 *                  sync mode                          (input) VMF_SYNC_Q or VMF_ASYNC_Q \n
 *                  channel ID                         (input) OSAL coid \n
 *                  async_event                        (input) event that is fired \n
 *   Return value:  \return if >=0  then client-id else error as vmf_ret_t\n
 *
 ******************************************************************************/
vmf_client_id_t nw_vmf_connect_async
                                ( const char *p_my_conn_string,                             /*!< INPUT channel name or NULL  */
                                unsigned16 message_queue_size,                              /*!< INPUT queue size for receiving messages */
                                unsigned16 message_size,                                    /*!< INPUT message size for the queue */
                                unsigned32 osal_coid,                                       /*!< INPUT OSAL coid */
                                unsigned32 async_event)                                     /*!< INPUT OSAL event that is fired if vmf queue changed from empty to data */
{
    vmf_handle_t    tx_handle=VMF_HANDLE_INVALID;
    vmf_handle_t    p2p_handle=VMF_HANDLE_INVALID;
    vmf_handle_t    rx_handle=VMF_HANDLE_INVALID;
    vmf_client_id_t my_client_id = VMF_ERROR;
    vmf_ret_t       vmf_ret = VMF_OK;
    char            myChannelName[MAX_NAME_LEN];
   // bool            blocking;
    unsigned8       unpack_spy_msgs = 0;                /* do NOT unpack! */

    VMF_MUTEX_INIT
    VMF_CLIENT_LOCK
    
    NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_connect_async");

    /* argument check */
    if ((0 == message_queue_size) || (message_size < sizeof(VMF_VAR_MSG_TYP(0))))
    {
        vmf_ret = ((vmf_client_id_t)VMF_ERR_OUT_OF_RANGE);
    }
    else
    {
        /* init cid table */
        nw_vmf_ini_cid_tab(&cid_tab);

        /* init IPC */
        if (!nw_vmf_ipc_init_done)
        {
            (void) nw_vmf_ipc_init(false);
            nw_vmf_ipc_init_done = true;
        }

        /* get a free cid */
        my_client_id = nw_vmf_client_get_free_cid(&cid_tab);
        if (my_client_id >= MAX_SERVER_CONNECTIONS)
        {
            NW_VMF_DEBUG_ERROR("pid=%d, vmf-client-lib: nw_vmf_connect() - nw_vmf_client_get_free_cid() failed\n",(int)getmypid());
            VMF_CLIENT_UNLOCK
            vmf_ret = ((vmf_client_id_t)VMF_ERROR);
        }
    }
    
    if(VMF_OK == vmf_ret)
    {
        /* get channel name */
        vmf_ret=nw_vmf_ipc_create_channel_name(cid_tab.pid, my_client_id, myChannelName, sizeof(myChannelName));
        if (VMF_OK != vmf_ret)
        {
            NW_VMF_DEBUG_ERROR("pid=%d, vmf-client-lib: nw_vmf_connect() - nw_vmf_ipc_create_channel_name() failed\n",(int)getmypid());
        }
    }

    if(VMF_OK == vmf_ret)
    {
        /* create own rx channel */
        rx_handle=nw_vmf_ipc_create_async(myChannelName, message_queue_size, message_size,osal_coid,async_event);
        if ((VMF_HANDLE_INVALID == rx_handle) || (rx_handle < 0))
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_connect() - nw_vmf_ipc_create() myChannelName=%s\n",(int)getmypid(),myChannelName);
            vmf_ret = ((vmf_client_id_t)VMF_ERROR);
        }
    }

    if(VMF_OK == vmf_ret)
    {
        /* open a tx channel to the vmf-Server */
        tx_handle = nw_vmf_ipc_open(IPC_SERVER_CHANNEL_NAME,IPC_BLOCKING);
        /* test if a connection to the server was established */
        if ((VMF_HANDLE_INVALID == tx_handle) || (tx_handle < 0))
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_connect() - nw_vmf_ipc_open() failed\n",(int)getmypid());
            (void)nw_vmf_ipc_close(tx_handle);
            (void)nw_vmf_ipc_destroy(rx_handle);
            vmf_ret = ((vmf_client_id_t)VMF_ERROR);
        }
    }

    if(VMF_OK == vmf_ret)
    {
        /* prepare and send connect-control-message */
        char        pl[MAX_CTRL_CONN_PL_LEN];
        unsigned8   bytes_written;

        vmf_ctrl_msg_connect_t  myCtrlConMsg;
        myCtrlConMsg.base.msg_type  = MSG_TYPE_CONNECT;
        myCtrlConMsg.base.pid       = cid_tab.pid;
        myCtrlConMsg.base.client_id = my_client_id;
        myCtrlConMsg.base.msg_clk   = nw_os_cfg_get_ms_time();

        pl[0]=0;
        /* add process name and connection string to message */
        if (strlen(progname) != 0)
        {
            bytes_written = snprintf(pl,sizeof(pl),"%s,",progname);
        }
        else
        {
            bytes_written = snprintf(pl,sizeof(pl),"%s,",NW_VMF_CLIENT_UNDEFINED);
        }
        /* add connection string */
        
        if (NULL != p_my_conn_string)
        {
            (void) strncat(pl,p_my_conn_string,sizeof(pl)-bytes_written);
        }
        else
        {
            (void) strncat(pl,NW_VMF_CLIENT_UNDEFINED,sizeof(pl)-bytes_written);
        }
        myCtrlConMsg.pl_len = (unsigned8)strlen(pl);
        nw_os_sstrncpy(myCtrlConMsg.pl_data, pl, sizeof(myCtrlConMsg.pl_data));

        vmf_ret = nw_vmf_ipc_send (tx_handle, (unsigned8*)&myCtrlConMsg, sizeof(myCtrlConMsg));
        if (VMF_OK != vmf_ret)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_connect() - nw_vmf_ipc_send() failed\n",(int)getmypid());
            (void)nw_vmf_ipc_close(tx_handle);
            (void)nw_vmf_ipc_destroy(rx_handle);
        }
        else
        {
            NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_ipc_send(MSG_TYPE_CONNECT)- OK\n");
        }
    }

    if(VMF_OK == vmf_ret)
    {
        /* register connection-id, connection name and handles */
        vmf_ret = nw_vmf_register_client (my_client_id,p_my_conn_string,tx_handle,p2p_handle,rx_handle,&cid_tab,unpack_spy_msgs);
        if (VMF_OK != vmf_ret)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_connect() - register_client() failed\n",(int)getmypid());
            (void)nw_vmf_ipc_close(tx_handle);
            (void)nw_vmf_ipc_destroy(rx_handle);
        }
    }
    
    if (VMF_OK != vmf_ret)
    {
        my_client_id = vmf_ret;
    }

    VMF_CLIENT_UNLOCK

    return (my_client_id);
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_register_ext_most_link (vmf_client_id_t vmf_client_id)
 *
 *   Description:   register a client as external MOST link
 *
 *   Parameters:    vmf_client_id    (input) connection client-id
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_register_ext_most_link(vmf_client_id_t vmf_client_id) /*!< INPUT client id */
{
#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
    vmf_ret_t       vmf_ret;
    vmf_ctrl_msg_register_ext_most_link_t myCtrlConMsg;

    /* argument check */
    if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_register_ext_most_link()- argument error: invalid vmf_client_id=%d\n",(int)getmypid(),vmf_client_id);
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else
    {
        /* prepare and send connect-control-message */
        myCtrlConMsg.base.msg_type  = MSG_TYPE_REGISTER_EXT_MOST_LINK;
        myCtrlConMsg.base.pid       = cid_tab.pid;
        myCtrlConMsg.base.client_id = vmf_client_id;
        myCtrlConMsg.base.msg_clk   = nw_os_cfg_get_ms_time();

        vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab), (unsigned8*)&myCtrlConMsg, sizeof(myCtrlConMsg));
        if (VMF_OK != vmf_ret)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_register_ext_most_link() - nw_vmf_ipc_send() failed\n",(int)getmypid());
        }
    }
    return (vmf_ret);
#else
    UNUSED_PARAM(vmf_client_id);
    return (VMF_ERROR);
#endif
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_register_spy (vmf_client_id_t vmf_client_id)
 *
 *   Description:   register a client as spy
 *
 *   Parameters:    vmf_client_id    (input) connection client-id
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_register_spy(vmf_client_id_t vmf_client_id) /*!< INPUT client id */
{
    vmf_ret_t       vmf_ret;
    vmf_ctrl_msg_register_spy_t myCtrlConMsg;

    /* argument check */
    if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_register_spy()- argument error: invalid vmf_client_id=%d\n",(int)getmypid(),vmf_client_id);
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else
    {
        /* prepare and send connect-control-message */
        myCtrlConMsg.base.msg_type  = MSG_TYPE_REGISTER_SPY;
        myCtrlConMsg.base.pid       = cid_tab.pid;
        myCtrlConMsg.base.client_id = vmf_client_id;
        myCtrlConMsg.base.msg_clk   = nw_os_cfg_get_ms_time();

        vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab), (unsigned8*)&myCtrlConMsg, sizeof(myCtrlConMsg));
        if (VMF_OK != vmf_ret)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_register_spy() - nw_vmf_ipc_send() failed\n",(int)getmypid());
        }
    }

    return (vmf_ret);
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_register_most_fblock (vmf_client_id_t vmf_client_id
 *                                               unsigned8 fBlockId,unsigned8 instId)
 *
 *   Description:   register a local MOST Fblock
 *
 *   Parameters:    vmf_client_id       (input)connection client-id
 *                  fBlockId            (input)FBlock ID
 *                  instId              (input)Instant ID
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_register_most_fblock  (vmf_client_id_t vmf_client_id,  /**< INPUT connection client-id*/
                                        unsigned8 fBlockId,             /**< INPUT FBlock ID*/
                                        unsigned8 instId)               /**< INPUT Instant ID*/
{
#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))

    vmf_ret_t       vmf_ret;
    vmf_ctrl_msg_register_most_fblock_t myCtrlConMsg;

    /* argument check */
    if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_register_most_fblock()- argument error: invalid vmf_client_id=%d\n",(int)getmypid(),vmf_client_id);
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else
    {
        /* prepare and send connect-control-message */
        myCtrlConMsg.base.msg_type  = MSG_TYPE_REGISTER_MOST_FBLOCK;
        myCtrlConMsg.base.pid       = cid_tab.pid;
        myCtrlConMsg.base.client_id = vmf_client_id;

        myCtrlConMsg.fBlockId       = fBlockId;
        myCtrlConMsg.instId         = instId;
        myCtrlConMsg.base.msg_clk   = nw_os_cfg_get_ms_time();

        vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab), (unsigned8*)&myCtrlConMsg, sizeof(myCtrlConMsg));
        
        if (VMF_OK != vmf_ret)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_register_most_fblock() - nw_vmf_ipc_send1() failed\n",(int)getmypid());
        }
    }

    if (VMF_OK == vmf_ret)
    {
        /* prepare and send reg_opr_add_comp-message */
        VMF_VAR_BASIC_MSG_TYP(0) my_basic_msg;
        my_basic_msg.msg_base.base.msg_type  = MSG_TYPE_BASIC_MESSAGE;
        my_basic_msg.msg_base.base.pid       = cid_tab.pid;
        my_basic_msg.msg_base.base.client_id = vmf_client_id;
        my_basic_msg.msg_base.base.vmf_mi_server_id = 0;
        my_basic_msg.msg_base.base.co_msg_type = 0;
        my_basic_msg.msg_base.id.group       = NW_MSG__GROUPID(RX_MSG_HEAD__REG_INTERNAL_MOST_FBLOCK);
        my_basic_msg.msg_base.id.event       = NW_MSG__EVENTID(RX_MSG_HEAD__REG_INTERNAL_MOST_FBLOCK);
        my_basic_msg.data.pl[0]              = fBlockId;
        my_basic_msg.data.pl[1]              = instId;
        my_basic_msg.data.length             = 2;
        my_basic_msg.msg_base.base.msg_clk   = nw_os_cfg_get_ms_time();


        vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab), (unsigned8*)&my_basic_msg, sizeof(vmf_evt_reg_opr_add_comp_t));

        if (VMF_OK != vmf_ret)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_register_most_fblock() - nw_vmf_ipc_send2() failed\n",(int)getmypid());
        }
    }

    return (vmf_ret);
#else
    UNUSED_PARAM(vmf_client_id);
    UNUSED_PARAM(fBlockId);
    UNUSED_PARAM(instId);
    return (VMF_ERROR);
#endif
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_de_register_most_fblock(vmf_client_id_t vmf_client_id
 *                                                 unsigned8 fBlockId,unsigned8 instId)
 *
 *   Description:   de-register a local MOST Fblock
 *
 *   Parameters:    vmf_client_id       (input)connection client-id
 *                  fBlockId            (input)FBlock ID
 *                  instId              (input)Instant ID
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_de_register_most_fblock(vmf_client_id_t vmf_client_id,     /**< INPUT connection client-id */
                                         unsigned8 fBlockId,                /**< INPUT FBlock ID */
                                         unsigned8 instId)                  /**< INPUT Instant ID */
{
#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
    vmf_ret_t       vmf_ret;
    vmf_ctrl_msg_de_register_most_fblock_t myCtrlConMsg;

    /* argument check */
    if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_de_register_most_fblock()- argument error: invalid vmf_client_id=%d\n",(int)getmypid(),vmf_client_id);
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else
    {
        /* prepare and send connect-control-message */
        myCtrlConMsg.base.msg_type  = MSG_TYPE_DE_REGISTER_MOST_FBLOCK;
        myCtrlConMsg.base.pid       = cid_tab.pid;
        myCtrlConMsg.base.client_id = vmf_client_id;

        myCtrlConMsg.fBlockId       = fBlockId;
        myCtrlConMsg.instId         = instId;

        myCtrlConMsg.base.msg_clk   = nw_os_cfg_get_ms_time();

        vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab), (unsigned8*)&myCtrlConMsg, sizeof(myCtrlConMsg));
        
        if (VMF_OK != vmf_ret)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_de_register_most_fblock() - nw_vmf_ipc_send() failed - cid=%d\n",(int)getmypid(),vmf_client_id);
        }
    }

    if (VMF_OK == vmf_ret)
    {
        /* prepare and send reg_opr_del_comp-message */
        VMF_VAR_BASIC_MSG_TYP(0) my_basic_msg;
        my_basic_msg.msg_base.base.msg_type  = MSG_TYPE_BASIC_MESSAGE;
        my_basic_msg.msg_base.base.pid       = cid_tab.pid;
        my_basic_msg.msg_base.base.client_id = vmf_client_id;
        my_basic_msg.msg_base.base.vmf_mi_server_id = 0;
        my_basic_msg.msg_base.base.co_msg_type = 0;
        my_basic_msg.msg_base.id.group       = NW_MSG__GROUPID(RX_MSG_HEAD__DEREG_INTERNAL_MOST_FBLOCK);
        my_basic_msg.msg_base.id.event       = NW_MSG__EVENTID(RX_MSG_HEAD__DEREG_INTERNAL_MOST_FBLOCK);
        my_basic_msg.data.pl[0]              = fBlockId;
        my_basic_msg.data.pl[1]              = instId;
        my_basic_msg.data.length             = 2;
        my_basic_msg.msg_base.base.msg_clk   = nw_os_cfg_get_ms_time();

        vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab), (unsigned8*)&my_basic_msg, sizeof(vmf_evt_reg_opr_add_comp_t));

        if (VMF_OK != vmf_ret)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_de_register_most_fblock() - nw_vmf_ipc_send2() failed\n",(int)getmypid());
        }
    }

    return (vmf_ret);
#else
    UNUSED_PARAM(vmf_client_id);
    UNUSED_PARAM(fBlockId);
    UNUSED_PARAM(instId);
    return (VMF_ERROR);
#endif
}



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_register_most_shadow (vmf_client_id_t vmf_client_id
 *                                               unsigned8 fBlockId,unsigned8 instId,
 *                                               unsigned16 fcIds_num,unsigned16 *funcIds)
 *
 *   Description:   register a local MOST Shadow (FuncIds are to be given)
 *
 *   Parameters:    vmf_client_id       (input)connection client-id
 *                  fBlockId            (input)FBlock ID
 *                  instId              (input)Instant ID
 *                  fcIds_num           (input)number of function ID's in list
 *                  *funcIds            (input)pointer to a list of function ID's
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_register_most_shadow  (vmf_client_id_t vmf_client_id,  /**< INPUT connection client-id */
                                        unsigned8 fBlockId,             /**< INPUT FBlock ID */
                                        unsigned8 instId,               /**< INPUT Instant ID */
                                        unsigned16 fcIds_num,           /**< INPUT number of function ID's in list */
                                        unsigned16 *funcIds)            /**< INPUT pointer to a list of function ID's*/
{
#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
    vmf_ret_t       vmf_ret = VMF_OK;
    VMF_VAR_CTRL_MSG_REGISTER_MOST_SHADOW_TYP(fcIds_num)    myCtrlConMsg;
    unsigned16      uCnt;

    /* argument check */
#ifndef ALLOW_EMPTY_SH_LIST
    if (NULL == funcIds)
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_register_most_shadow() - argument error: NULL pointer\n",(int)getmypid());
        vmf_ret = (VMF_ERR_NULL_POINTER);
    }
#endif

#ifdef DO_CLIENT_DEBUG_SHADOW
    if(VMF_OK == vmf_ret)
    {
        int iCnt;
        NW_VMF_CLIB_DEBUG_INFO("\nbvm-VMF-CLient-Lib: nw_vmf_register_most_shadow fBlockId=%d,instId=%d,function-no=%d -list= ", fBlockId,instId,fcIds_num);
        for (iCnt=0;iCnt<fcIds_num;iCnt++)
        {
            NW_VMF_CLIB_DEBUG_INFO("%d ", funcIds[iCnt]);
        }
        NW_VMF_CLIB_DEBUG_INFO("\n");
    }
#endif
    if(VMF_OK == vmf_ret)
    {
        if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_register_most_shadow()- argument error: invalid vmf_client_id=%d\n",(int)getmypid(),vmf_client_id);
            vmf_ret = (VMF_ERR_OUT_OF_RANGE);
        }
    }

    if(VMF_OK == vmf_ret)
    {
        /* prepare and send connect-control-message */
        myCtrlConMsg.base.msg_type  = MSG_TYPE_REGISTER_MOST_SHADOW;
        myCtrlConMsg.base.pid       = cid_tab.pid;
        myCtrlConMsg.base.client_id = vmf_client_id;

        myCtrlConMsg.fBlockId       = fBlockId;
        myCtrlConMsg.instId         = instId;
        myCtrlConMsg.u16NumFKtIds   = fcIds_num;

        myCtrlConMsg.base.msg_clk   = nw_os_cfg_get_ms_time();

        /* serialize function ids */
        for (uCnt =0; uCnt < fcIds_num; uCnt++)
        {
            myCtrlConMsg.funcIdList[uCnt] = funcIds[uCnt];
        }

        /* transfer control message */
        vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab), (unsigned8*)&myCtrlConMsg, sizeof(myCtrlConMsg));
        
        if (VMF_OK != vmf_ret)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_register_most_shadow() - nw_vmf_ipc_send() failed - cid=%d\n",(int)getmypid(),vmf_client_id);
        }
        else
        {
            #if (!defined NW_NM_OPTION_NETWORK_MASTER) && (defined NW_EXTERNAL_MOST_ENABLED) && (defined RX_MSG_HEAD__REG_INTERNAL_MOST_SHADOW)
            /* register all shadows to the NetworkMaster shadow mosule within MOST process */
            VMF_VAR_BASIC_MSG_TYP(0) my_basic_msg;

            my_basic_msg.msg_base.base.msg_type  = MSG_TYPE_BASIC_MESSAGE;
            my_basic_msg.msg_base.base.pid       = cid_tab.pid;
            my_basic_msg.msg_base.base.client_id = vmf_client_id;
            my_basic_msg.msg_base.base.vmf_mi_server_id = 0;
            my_basic_msg.msg_base.base.co_msg_type = 0;
            my_basic_msg.msg_base.id.group       = NW_MSG__GROUPID(RX_MSG_HEAD__REG_INTERNAL_MOST_SHADOW);
            my_basic_msg.msg_base.id.event       = NW_MSG__EVENTID(RX_MSG_HEAD__REG_INTERNAL_MOST_SHADOW);
            my_basic_msg.data.pl[0]              = fBlockId;
            my_basic_msg.data.pl[1]              = instId;
            my_basic_msg.data.length             = 2;
            my_basic_msg.msg_base.base.msg_clk   = nw_os_cfg_get_ms_time();


            vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab), (unsigned8*)&my_basic_msg, sizeof(vmf_evt_reg_opr_add_comp_t));

            if (VMF_OK != vmf_ret)
            {
                NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_register_most_fblock() - nw_vmf_ipc_send2() failed\n",(int)getmypid());
            }
            #endif
        }
    }

    return (vmf_ret);
#else
    UNUSED_PARAM(vmf_client_id);
    UNUSED_PARAM(fBlockId);
    UNUSED_PARAM(instId);
    UNUSED_PARAM(fcIds_num);
    UNUSED_PARAM(funcIds);
    return (VMF_ERROR);
#endif
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_de_register_most_shadow (vmf_client_id_t vmf_client_id
 *                                               unsigned8 fBlockId,unsigned8 instId)
 *
 *   Description:   de-register a local MOST Shadow
 *
 *   Parameters:    vmf_client_id       (input)connection client id
 *                  fBlockId            (input)FBlock ID
 *                  instId              (input)Instant ID
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_de_register_most_shadow(vmf_client_id_t vmf_client_id,     /**<INPUT connection client id*/
                                         unsigned8 fBlockId,                /**<INPUT FBlock ID*/
                                         unsigned8 instId)                  /**<INPUT Instant ID*/
{
#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
    vmf_ret_t       vmf_ret;
    vmf_ctrl_msg_de_register_most_shadow_t myCtrlConMsg;

    /* argument check */
    if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_de_register_most_shadow()- argument error: invalid vmf_client_id=%d\n",(int)getmypid(),vmf_client_id);
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else
    {
        /* prepare and send connect-control-message */
        myCtrlConMsg.base.msg_type  = MSG_TYPE_DE_REGISTER_MOST_SHADOW;
        myCtrlConMsg.base.pid       = cid_tab.pid;
        myCtrlConMsg.base.client_id = vmf_client_id;

        myCtrlConMsg.fBlockId       = fBlockId;
        myCtrlConMsg.instId         = instId;
        myCtrlConMsg.base.msg_clk   = nw_os_cfg_get_ms_time();

        /* transfer control message */
        vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab), (unsigned8*)&myCtrlConMsg, sizeof(myCtrlConMsg));
        
        if (VMF_OK != vmf_ret)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_de_register_most_shadow() - nw_vmf_ipc_send() failed - cid=%d\n",(int)getmypid(),vmf_client_id);
        }
    }

    return (vmf_ret);
#else
    UNUSED_PARAM(vmf_client_id);
    UNUSED_PARAM(fBlockId);
    UNUSED_PARAM(instId);
    return (VMF_ERROR);
#endif
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_register_msg_group (vmf_client_id_t vmf_client_id
 *                                             unsigned16 groups_num,unsigned8 * groupList)
 *
 *   Description:   register for a none-MOST message groups
 *
 *   Parameters:    vmf_client_id       (input)connection client id
 *                  groups_num          (input)number of groups in List
 *                  *groupList          (input)pointer to a list of message groups
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_register_msg_group (vmf_client_id_t vmf_client_id, /**<INPUT connection client id*/
                                     unsigned16 groups_num,         /**<INPUT number of groups in List*/
                                     unsigned8 * groupList)         /**<INPUT pointer ro a list of message groups*/
{
    vmf_ret_t       vmf_ret = VMF_ERROR;

#ifdef INTEGRITY
    vmf_ctrl_msg_register_msg_group_t                       myCtrlConMsg;
#else    
    VMF_VAR_CTRL_MSG_REGISTER_MSG_GROUP_TYP(groups_num)     myCtrlConMsg;
#endif    

    NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_register_msg_group()");


    /* argument check */
    if (NULL == groupList)
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_register_msg_group() - argument error: NULL pointer",(int)getmypid());
        vmf_ret = VMF_ERR_NULL_POINTER;
    } 
    else if (groups_num > MAX_GROUP_NUM)
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_register_msg_group() - argument error: groups_num > MAX_GROUP_NUM",(int)getmypid());
        vmf_ret = VMF_ERR_OUT_OF_RANGE;
    }
    else if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_register_msg_group()- argument error: invalid vmf_client_id=%d",(int)getmypid(),vmf_client_id);
        vmf_ret = VMF_ERR_OUT_OF_RANGE;
    }
    else
    {
        /* prepare connect-control-message */
        myCtrlConMsg.base.msg_type  = MSG_TYPE_REGISTER_MSG_GROUPS;
        myCtrlConMsg.base.pid       = cid_tab.pid;
        myCtrlConMsg.base.client_id = vmf_client_id;
        myCtrlConMsg.groups_num     = groups_num;
        myCtrlConMsg.base.msg_clk   = nw_os_cfg_get_ms_time();

        /* serialize message groups */
        if (groups_num > 0)
        {
            NW_MEMCOPY(myCtrlConMsg.groupList,groupList,groups_num);
        }
        NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_register_msg_group() call nw_vmf_ipc_send");

        /* transfer control message */
        vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab), (unsigned8*)&myCtrlConMsg, sizeof(myCtrlConMsg));
        if (VMF_OK != vmf_ret)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_register_msg_group() - nw_vmf_ipc_send1() failed",(int)getmypid());
        }
    }

    return (vmf_ret);
}

/**************************************************************************//**
 *
 *   Function Name: nw_vmf_deregister_msg_group (vmf_client_id_t vmf_client_id
 *                                              unsigned16 groups_num,unsigned8 * groupList)
 *
 *   Description:   de-register for a none-MOST message groups
 *
 *   Parameters:    vmf_client_id       (input)connection_id
 *                  groups_num          (input)number of groups in List
 *                  *groupList          (input)pointer to a list of message groups
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_de_register_msg_group  (vmf_client_id_t vmf_client_id, /**<INPUT connection_id*/
                                        unsigned16 groups_num,          /**<INPUT number of groups in List*/
                                        unsigned8 * groupList)          /**<INPUT pointer to a list of message groups*/
{
    vmf_ret_t       vmf_ret;

#ifdef INTEGRITY
    vmf_ctrl_msg_register_msg_group_t                       myCtrlConMsg;
#else    
    VMF_VAR_CTRL_MSG_REGISTER_MSG_GROUP_TYP(groups_num)     myCtrlConMsg;
#endif

    /* argument check */
    if (NULL == groupList)
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_de_register_msg_group() - argument error: NULL pointer\n",(int)getmypid());
        vmf_ret = (VMF_ERR_NULL_POINTER);
    }
    else if (groups_num > MAX_GROUP_NUM)
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_de_register_msg_group() - argument error: groups_num > MAX_GROUP_NUM\n",(int)getmypid());
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_de_register_msg_group()- argument error: invalid vmf_client_id=%d\n",(int)getmypid(),vmf_client_id);
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else
    {
        /* prepare and send connect-control-message */
        myCtrlConMsg.base.msg_type  = MSG_TYPE_DE_REGISTER_MSG_GROUPS;
        myCtrlConMsg.base.pid       = cid_tab.pid;
        myCtrlConMsg.base.client_id = vmf_client_id;
        myCtrlConMsg.groups_num     = groups_num;
        myCtrlConMsg.base.msg_clk   = nw_os_cfg_get_ms_time();

        /* serialize message groups */
        if (groups_num > 0)
        {
            NW_MEMCOPY(myCtrlConMsg.groupList,groupList,groups_num);
        }

        /* transfer control message */
        vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab), (unsigned8*)&myCtrlConMsg, sizeof(myCtrlConMsg));

        if (VMF_OK != vmf_ret)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_de_register_msg_group() - nw_vmf_ipc_send() failed\n",(int)getmypid());
        }
    }

    return (vmf_ret);
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_send_most_async (vmf_client_id_t vmf_client_id
 *                                          vmf_most_msg_t *p_vmf_msg)
 *
 *   Description:   To send a most-async msg (most high message)
 *
 *   Parameters:    vmf_client_id       (input)connection_id
 *                  p_vmf_msg           (input)pointer to a MOST vmf_message
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_send_most_async      (vmf_client_id_t vmf_client_id,     /**<INPUT connection_id*/
                                       vmf_most_msg_t * p_vmf_msg)        /**<INPUT pointer to a MOST vmf_message*/
{
#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
    vmf_ret_t       vmf_ret;
    unsigned16      u_len;

    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send_most_async() - argument error: NULL pointer\n",(int)getmypid());
        vmf_ret = (VMF_ERR_NULL_POINTER);
    }
    else if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        if (0==vmf_client_id)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send_most_async()- error - client not connected\n",(int)getmypid());
        }
        else
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send_most_async()- argument error: invalid vmf_client_id=%d\n",(int)getmypid(),vmf_client_id);
        }
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else
    {
        /* prepare MOST message */
        p_vmf_msg->msg_base.base.msg_type  = MSG_TYPE_MOST_MESSAGE;
        p_vmf_msg->msg_base.base.pid       = cid_tab.pid;
        p_vmf_msg->msg_base.base.client_id = vmf_client_id;
        p_vmf_msg->msg_base.id.group       = MOST_MESSAGE;
        p_vmf_msg->msg_base.id.event       = 0;
        p_vmf_msg->channel_flag            = CHANNEL_TYPE_MOST_ASYNC;    /* set to async message */
        p_vmf_msg->msg_base.base.vmf_mi_server_id = 0;
        p_vmf_msg->msg_base.base.co_msg_type = 0;
        p_vmf_msg->msg_base.base.msg_clk   = nw_os_cfg_get_ms_time();

        /* calculate 'real' size of MOST message */
        u_len = sizeof(VMF_VAR_MOST_MSG_TYP(0)) + p_vmf_msg->data.length;

        /* transfer a MOST message */
        vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab), (unsigned8*)p_vmf_msg, u_len);
        
        if (VMF_OK != vmf_ret)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send_most_async() - nw_vmf_ipc_send() failed\n",(int)getmypid());
        }
    }

    return (vmf_ret);
#else
    UNUSED_PARAM(vmf_client_id);
    UNUSED_PARAM(p_vmf_msg);
    return (VMF_ERROR);
#endif
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_send_most_ctrl (vmf_client_id_t vmf_client_id
 *                                         vmf_most_msg_t *p_vmf_msg)
 *
 *   Description:   To send a most-control msg
 *
 *   Parameters:    vmf_client_id       (input)connection_id
 *                  p_vmf_msg           (input)pointer to a MOST vmf_message
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_send_most_ctrl     (vmf_client_id_t vmf_client_id,     /**<INPUT connection_id*/
                                     vmf_most_msg_t * p_vmf_msg)        /**<INPUT pointer to a MOST vmf_message*/
{
#if ((defined NW_VIRTUAL_MOST_ENABLED) || (defined NW_EXTERNAL_MOST_ENABLED))
    vmf_ret_t       vmf_ret;
    unsigned16      u_len;

    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send_most_ctrl() - argument error: NULL pointer\n",(int)getmypid());
        vmf_ret = (VMF_ERR_NULL_POINTER);
    }
    else if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        if (0==vmf_client_id)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send_most_ctrl()- error - client not connected\n",(int)getmypid());
        }
        else
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send_most_ctrl()- argument error: invalid vmf_client_id=%d\n",(int)getmypid(),vmf_client_id);
        }
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else
    {
        /* prepare MOST message */
        p_vmf_msg->msg_base.base.msg_type  = MSG_TYPE_MOST_MESSAGE;
        p_vmf_msg->msg_base.base.pid       = cid_tab.pid;
        p_vmf_msg->msg_base.base.client_id = vmf_client_id;
        p_vmf_msg->msg_base.id.group       = MOST_MESSAGE;
        p_vmf_msg->msg_base.id.event       = 0;
        p_vmf_msg->channel_flag            = CHANNEL_TYPE_MOST_CTRL;    /* set to control message */
        p_vmf_msg->msg_base.base.vmf_mi_server_id = 0;
        p_vmf_msg->msg_base.base.co_msg_type = 0;
        p_vmf_msg->msg_base.base.msg_clk   = nw_os_cfg_get_ms_time();

        /* calculate 'real' size of MOST message */
        u_len = sizeof(VMF_VAR_MOST_MSG_TYP(0)) + p_vmf_msg->data.length;

        /* transfer a MOST message */
        vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab), (unsigned8*)p_vmf_msg, u_len);

        if (VMF_OK != vmf_ret)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send_most_ctrl() - nw_vmf_ipc_send() failed\n",(int)getmypid());
        }
    }

    return (vmf_ret);
#else
    UNUSED_PARAM(vmf_client_id);
    UNUSED_PARAM(p_vmf_msg);   
    return (VMF_ERROR);
#endif
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_send_basic_p2p (vmf_client_id_t vmf_client_id
 *                                     vmf_basic_msg_t *p_vmf_msg)
 *
 *   Description:   To send a basic msg to a p2p destination
 *
 *   Parameters:    vmf_client_id  (input)connection_id
 *                  p_vmf_msg      (input)pointer to a basic vmf_message
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_send_basic_p2p (vmf_client_id_t vmf_client_id,     /**<INPUT connection_id*/
                                 vmf_basic_msg_t *p_vmf_msg)        /**<INPUT pointer to a basic vmf_message*/
{
    vmf_ret_t       vmf_ret=VMF_ERROR;
    unsigned16      u_len=0;
    vmf_handle_t    p2p_hdl=VMF_HANDLE_INVALID;

    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_VMF_DEBUG_ERROR("%s: pid=%d vmf-client-lib: nw_vmf_send_basic_p2p() - argument error: NULL pointer\n",progname,(int)getmypid());
        vmf_ret = (VMF_ERR_NULL_POINTER);
    }
    else if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        if (0==vmf_client_id)
        {
            NW_VMF_DEBUG_ERROR("%s: pid=%d vmf-client-lib: nw_vmf_send_basic_p2p()- error - client not connected\n",progname,(int)getmypid());
        }
        else
        {
            NW_VMF_DEBUG_ERROR("%s: pid=%d vmf-client-lib: nw_vmf_send_basic_p2p()- argument error: not yet assigned vmf_client_id=%d\n",progname,(int)getmypid(),vmf_client_id);
        }
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else if (p_vmf_msg->data.length  > MAX_VMF_DATA_LEN)
    /* check size of message */
    {
        /* message to long */
        NW_VMF_DEBUG_ERROR("%s: pid=%d vmf-client-lib: nw_vmf_send_basic_p2p()- to much data=%d bytes, allowed size =%d\n",progname,(int)getmypid(),p_vmf_msg->data.length,MAX_VMF_DATA_LEN);
        vmf_ret = VMF_ERR_TO_MUCH_DATA;
    }
    else
    {
        /* prepare BASIC message */
        p_vmf_msg->msg_base.base.msg_type  = MSG_TYPE_P2P_BASIC_MESSAGE;
        p_vmf_msg->msg_base.base.pid       = cid_tab.pid;
        p_vmf_msg->msg_base.base.client_id = vmf_client_id;
        p_vmf_msg->msg_base.base.vmf_mi_server_id = 0;
        p_vmf_msg->msg_base.base.co_msg_type = 0;
        p_vmf_msg->msg_base.base.client_count = 0;
        p_vmf_msg->msg_base.base.msg_clk   = nw_os_cfg_get_ms_time();

        /* calculate 'real' size of the P2P_BASIC message */
        u_len = VMF_BASIC_MSG_LEN(p_vmf_msg->data.length);
        p2p_hdl = cid_tab.my_cid[(unsigned8)vmf_client_id].p2p_handle;
        if (p2p_hdl != VMF_HANDLE_INVALID)
        {
            /* send message to ipc */
            vmf_ret = nw_vmf_ipc_send(p2p_hdl,(unsigned8*)p_vmf_msg, u_len);
            if (VMF_OK != vmf_ret)
            {
                NW_VMF_CLIB_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send_basic_p2p(cid=%d) - nw_vmf_ipc_send() failed\n",(int)getmypid(),vmf_client_id);
                p_vmf_msg->msg_base.base.client_count = 0;
            }
            else
            {
                NW_VMF_CLIB_DEBUG_INFO("pid=%d vmf-client-lib: nw_vmf_send_basic_p2p(cid=%d) - nw_vmf_ipc_send(%d bytes) OK",(int)getmypid(),vmf_client_id,u_len);
                p_vmf_msg->msg_base.base.client_count = 1;
            }
        }
        else
        {
            /* this handle is not a p2p handle! */
            NW_VMF_CLIB_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send_basic_p2p(cid=%d) - invalid handle for a p2p function\n",(int)getmypid(),vmf_client_id);
            vmf_ret = VMF_ERR_INVALID_P2P_CID;
        }

        if (NULL == cid_tab.my_cid[(unsigned8)vmf_client_id].pcl_shm)
        {
            vmf_ret = VMF_ERR_SHM;
        }

        if (VMF_OK == vmf_ret)
        {
            if (cid_tab.my_cid[(unsigned8)vmf_client_id].pcl_shm->enable_spy != 0)
            {
                (void)nw_vmf_ipc_send(nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab),(unsigned8*)p_vmf_msg, u_len);
            }
        }       
    }

    return vmf_ret;
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_send_basic (vmf_client_id_t vmf_client_id
 *                                     vmf_basic_msg_t *p_vmf_msg)
 *
 *   Description:   To send a basic msg
 *
 *   Parameters:    vmf_client_id  (input)connection_id
 *                  p_vmf_msg      (input)pointer to a basic vmf_message
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_send_basic     (vmf_client_id_t vmf_client_id,     /**<INPUT connection_id*/
                                 vmf_basic_msg_t *p_vmf_msg)        /**<INPUT pointer to a basic vmf_message*/
{
    vmf_ret_t       vmf_ret;
    unsigned16      u_len;

    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_VMF_DEBUG_ERROR("%s: pid=%d vmf-client-lib: nw_vmf_send_basic() - argument error: NULL pointer\n",progname,(int)getmypid());
        vmf_ret = (VMF_ERR_NULL_POINTER);
    }
    else if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        if (0==vmf_client_id)
        {
            NW_VMF_DEBUG_ERROR("%s: pid=%d vmf-client-lib: nw_vmf_send_basic()- error - client not connected\n",progname,(int)getmypid());
        }
        else
        {
            NW_VMF_DEBUG_ERROR("%s: pid=%d vmf-client-lib: nw_vmf_send_basic()- argument error: not yet assigned vmf_client_id=%d\n",progname,(int)getmypid(),vmf_client_id);
        }
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else if (p_vmf_msg->data.length  > MAX_VMF_DATA_LEN)
    /* check size of message */
    {
        /* message to long */
        NW_VMF_DEBUG_ERROR("%s: pid=%d vmf-client-lib: nw_vmf_send_basic()- to much data=%d bytes, allowed size =%d\n",progname,(int)getmypid(),p_vmf_msg->data.length,MAX_VMF_DATA_LEN);
        vmf_ret = VMF_ERR_TO_MUCH_DATA;
    }
    else
    {
        /* prepare BASIC message */
        p_vmf_msg->msg_base.base.msg_type  = MSG_TYPE_BASIC_MESSAGE;
        p_vmf_msg->msg_base.base.pid       = cid_tab.pid;
        p_vmf_msg->msg_base.base.client_id = vmf_client_id;
        p_vmf_msg->msg_base.base.vmf_mi_server_id = 0;
        p_vmf_msg->msg_base.base.co_msg_type = 0;
        p_vmf_msg->msg_base.base.msg_clk   = nw_os_cfg_get_ms_time();

        /* always send VMF_BASIC_MSG_NEAR_DATA_LENGTH bytes of near data !!!
            so if amount of near data less than four, fill them */
        #if VMF_BASIC_MSG_NEAR_DATA_LENGTH > 0
        if(p_vmf_msg->data.length < VMF_BASIC_MSG_NEAR_DATA_LENGTH)
        {
            unsigned16      i;

            for(i = p_vmf_msg->data.length; i < VMF_BASIC_MSG_NEAR_DATA_LENGTH; i++)
            {
                p_vmf_msg->data.pl[i] = 0x00;
            }

            p_vmf_msg->data.length = VMF_BASIC_MSG_NEAR_DATA_LENGTH;
        }
        #endif

        /* calculate 'real' size of the BASIC message */
        u_len = VMF_BASIC_MSG_LEN(p_vmf_msg->data.length);

        if (cid_tab.my_cid[(unsigned8)vmf_client_id].collector_timeout == 0)
        {
            /* send message to ipc */
            vmf_ret = nw_vmf_ipc_send(nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab),(unsigned8*)p_vmf_msg, u_len);
            if (VMF_OK != vmf_ret)
            {
                NW_VMF_CLIB_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send_basic(cid=%d) - nw_vmf_ipc_send() failed\n",(int)getmypid(),vmf_client_id);
            }
            else
            {
                NW_VMF_CLIB_DEBUG_INFO("pid=%d vmf-client-lib: nw_vmf_send_basic(cid=%d) - nw_vmf_ipc_send(%d bytes) OK",(int)getmypid(),vmf_client_id,u_len);
            }
        }
        else
        {
            /* send message to collector */
            {
                vmf_ret = nw_vmf_co_basic_send (vmf_client_id, p_vmf_msg, u_len);
            }
        }
    }

    return (vmf_ret);
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_send       (vmf_client_id_t vmf_client_id
 *                                     vmf_msg_t       *p_vmf_msg)
 *
 *   Description:   To send a msg (BASIC or MOST message)
 *                  message type is define in base.msg_type
 *
 *   Parameters:    vmf_client_id       (input)connection_id
 *                  p_vmf_msg           (input)pointer to a vmf_message
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_send           (vmf_client_id_t vmf_client_id,  /**<INPUT connection_id*/
                                 vmf_msg_t * p_vmf_msg)          /**<INPUT pointer to a vmf_message*/
{
    vmf_ret_t       vmf_ret;

    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send() - argument error: NULL pointer\n",(int)getmypid());
        vmf_ret = (VMF_ERR_NULL_POINTER);
    }
    else if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        if (0 == vmf_client_id)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send()- error - client not connected\n",(int)getmypid());
        }
        else
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send()- argument error: invalid vmf_client_id=%d\n",(int)getmypid(),vmf_client_id);
        }
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else
    {
        if (p_vmf_msg->vmf_most_msg.msg_base.base.msg_type == MSG_TYPE_MOST_MESSAGE)
        {
            /* MOST message */
            vmf_ret = (nw_vmf_send_most_ctrl (vmf_client_id,(vmf_most_msg_t *)p_vmf_msg));
        }
        else
        {
            /* BASIC message */
            vmf_ret = (nw_vmf_send_basic (vmf_client_id,(vmf_basic_msg_t *)p_vmf_msg));
        }
    }
    
    return vmf_ret;
}





/**************************************************************************//**
 *
 *   Function Name: nw_vmf_send_raw       ( vmf_client_id_t vmf_client_id
 *                                          void * buffer,
 *                                          unsigned16 buffer_len)
 *
 *   Description:   send a raw buffer to the ipc)
 *
 *   Parameters:    vmf_trace_tx_cid        (input)connection_id
 *                  pbuffer                 (input)address of the raw buffer
 *                  len                     (input)len of the raw buffer
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_send_raw (vmf_client_id_t vmf_trace_tx_cid,void * pbuffer,unsigned16 len)
{
    vmf_ret_t       vmf_ret;

    /* argument check */
    if (NULL == pbuffer)
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send_raw() - argument error: NULL pointer\n",(int)getmypid());
        vmf_ret = (VMF_ERR_NULL_POINTER);
    }
    else if (0 == len)
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send_raw() - argument error: len = 0\n",(int)getmypid());
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else if ((vmf_trace_tx_cid >= MAX_CID) || (vmf_trace_tx_cid < INITAL_CID_VALUE ))
    {
        if (0==vmf_trace_tx_cid)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send_raw()- error - client not connected\n",(int)getmypid());
        }
        else
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send_raw()- argument error: invalid vmf_client_id=%d\n",(int)getmypid(),vmf_trace_tx_cid);
        }
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else
    {
        /* transfer the message */
        vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_trace_tx_cid,&cid_tab),(unsigned8*)pbuffer,len);
        if (VMF_OK != vmf_ret)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_send_raw() - nw_vmf_ipc_send() failed\n",(int)getmypid());
        }
    }

    return (vmf_ret);
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_receive    (vmf_client_id_t vmf_conn_id
 *                                     vmf_msg_t    *p_vmf_msg)
 *
 *   Description:   receive a vmf message
 *                  function blocks until it receives a message
 *
 *   Parameters:    vmf_client_id       (input)connection_id
 *                  p_vmf_msg           (output)pointer to a vmf_message
 *
 *   Return value:  \return number of received data bytes if > 0 or error
 *
 ******************************************************************************/
signed16 nw_vmf_receive          (vmf_client_id_t vmf_client_id,    /**< INPUT connection_id*/
                                  vmf_msg_t * p_vmf_msg,            /**< OUTPUT pointer to a vmf_message*/
                                  unsigned16  vmf_buffer_length)    /**< INPUT length of COMPLETE message buffer */
{
    vmf_ret_t       vmf_ret;
    unsigned16      uReadSize=0;
    bool            bco_msg=false;

    NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_receive");

    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_receive()- argument error: NULL pointer",(int)getmypid());
        vmf_ret = (VMF_ERR_NULL_POINTER);
    }
    else if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_receive()- argument error: invalid vmf_client_id=%d",(int)getmypid(),vmf_client_id);
        delay(10);                      /* to allow killing the process*/
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else
    {
        /* check if there are messages in the collector buffer */
        bco_msg = true;
        vmf_ret = nw_vmf_co_receive (vmf_client_id,vmf_buffer_length, (vmf_basic_msg_t *)p_vmf_msg,&uReadSize);
        if (vmf_ret != VMF_OK)
        {
            bco_msg = false;

            /* receive a message (can be a MOST or BASIC message) */
            /* this function will block until a message is received */
            vmf_ret = nw_vmf_ipc_receive (nw_vmf_client_get_rx_hdl(vmf_client_id,&cid_tab),
                                          vmf_buffer_length,(unsigned8 *)p_vmf_msg,&uReadSize);

#ifdef DO_CLIENT_DEBUG_HEX
           // nw_con_HexDump("vmf-client-lib: nw_vmf_receive() raw-rx-data=", (unsigned8 *)p_vmf_msg, uReadSize);
#endif
            if (VMF_OK == vmf_ret)
            {

                if (p_vmf_msg->vmf_most_msg.msg_base.base.msg_type == MSG_TYPE_BASIC_MESSAGE)
                {

                    /* check if the received message is a co message or a co-spy message */
#if 1

    /* OLD
                    if (((COL_VMF_MSG == p_vmf_msg->vmf_basic_msg.msg_base.base.co_msg_type) ||
                         (COL_VMF_MSG_SPY == p_vmf_msg->vmf_basic_msg.msg_base.base.co_msg_type))&&
                        (p_vmf_msg->vmf_most_msg.msg_base.base.msg_type == MSG_TYPE_BASIC_MESSAGE))
    */

                    if ( (COL_VMF_MSG == p_vmf_msg->vmf_basic_msg.msg_base.base.co_msg_type) ||
                        ((COL_VMF_MSG_SPY == p_vmf_msg->vmf_basic_msg.msg_base.base.co_msg_type) && (1 == cid_tab.my_cid[vmf_client_id].unpack_vmf_spy_msgs)) )


#else
                    if ((COL_VMF_MSG == p_vmf_msg->vmf_basic_msg.msg_base.base.co_msg_type) &&
                        (p_vmf_msg->vmf_most_msg.msg_base.base.msg_type == MSG_TYPE_BASIC_MESSAGE))
#endif
                    {
                        /* store message in co buffer*/
                        vmf_ret = nw_vmf_co_store_msg(vmf_client_id, (vmf_basic_msg_t *)p_vmf_msg,uReadSize);
                        if (VMF_OK == vmf_ret)
                        {
                            /* get first message from buffer */
                            vmf_ret = nw_vmf_co_receive (vmf_client_id,vmf_buffer_length, (vmf_basic_msg_t *)p_vmf_msg,&uReadSize);
                            bco_msg = true;
                       }
                    }
                }
            }
        }

        if ( vmf_ret < 0)
        {
            NW_VMF_DEBUG_ERROR("%s: vmf-client-lib: nw_vmf_receive() error = %d",progname,vmf_ret);
            uReadSize = 0;
        }
        else
        {
            /* reception was ok */
            /* return numbe of received bytes */
            vmf_ret = uReadSize;
        }

        /* check if message was cut during transfer */
        if (uReadSize > 0)
        {
            switch(p_vmf_msg->vmf_most_msg.msg_base.base.msg_type)
            {
                unsigned16 msg_len;

                case  MSG_TYPE_MOST_MESSAGE:
                    msg_len = sizeof(VMF_VAR_MOST_MSG_TYP(0)) + p_vmf_msg->vmf_most_msg.data.length;
                    if (msg_len > vmf_buffer_length)
                    {
                        /* message was cut ! */
                        NW_VMF_DEBUG_ERROR("%s: vmf-client-lib: nw_vmf_receive() buffer to small! uReadSize=%d vmf-msglen=%d, bufferlen=%d\n",progname,uReadSize,msg_len,vmf_buffer_length);
                        vmf_ret = VMF_ERR_BUFFER_TO_SMALL;
                    }
                    break;

                case  MSG_TYPE_BASIC_MESSAGE:
                    msg_len = VMF_BASIC_MSG_LEN(p_vmf_msg->vmf_basic_msg.data.length);
                    if (msg_len > vmf_buffer_length)
                    {
                        /* message was cut ! */
                        NW_VMF_DEBUG_ERROR("%s: vmf-client-lib: nw_vmf_receive() buffer to small! uReadSize=%d, vmf-msglen=%d, bufferlen=%d\n", progname, uReadSize, msg_len, vmf_buffer_length);
                        vmf_ret = VMF_ERR_BUFFER_TO_SMALL;
                    }
                    break;

                default:
                    /* ignore */
                    break;
            }
        }
    }


#ifdef DO_CLIENT_DEBUG_HEX
    if (bco_msg)
    {
        if (uReadSize > 0)
        {
            nw_con_HexDump("vmf-client-lib: nw_vmf_receive() co-data=", (unsigned8 *) p_vmf_msg, uReadSize);
        }
    }
    else
    {
        if (uReadSize > 0)
        {
            nw_con_HexDump("vmf-client-lib: nw_vmf_receive() data=", (unsigned8 *) p_vmf_msg, uReadSize);
        }
    }
#else
    UNUSED_PARAM(bco_msg);
#endif
    NW_VMF_CLIB_DEBUG_INFO("nw_vmf_receive() ret=%d",vmf_ret);

    return(vmf_ret);
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_basic_receive (vmf_client_id_t vmf_conn_id
 *                                        vmf_basic_msg_t  *p_vmf_msg)
 *
 *   Description:   receive a vmf basic message
 *                  most messages are returned with len 0 if received by this call
 *
 *   Parameters:    vmf_client_id       (input)connection_id
 *                  p_vmf_msg           (output)pointer to a vmf_message
 *                  vmf_buffer_length   (input) length or receive buffer
 *
 *   Return value:  \return number of received data bytes if > 0 or error
 *
 ******************************************************************************/
signed16 nw_vmf_receive_basic    (vmf_client_id_t vmf_client_id,    /**< INPUT connection_id                     */
                                  vmf_basic_msg_t * p_vmf_basic_msg,/**< OUTPUT pointer to a vmf_message         */
                                  unsigned16  vmf_buffer_length)    /**< INPUT length of COMPLETE message buffer */
{
    vmf_ret_t       vmf_ret;
    unsigned16      uReadSize=0;

    /* argument check */
    if (NULL == p_vmf_basic_msg)
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_basic_receive()- argument error: NULL pointer\n",(int)getmypid());
        vmf_ret = (VMF_ERR_NULL_POINTER);
    }
    else if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_basic_receive()- argument error: invalid vmf_client_id=%d\n",(int)getmypid(),vmf_client_id);
        delay(10);                      /* to allow killing the process*/
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else
    {
        /* receive a message (can be a MOST or BASIC message) */
        /* this function will block until a message is received or until an error occurred */
        vmf_ret = nw_vmf_ipc_receive (nw_vmf_client_get_rx_hdl(vmf_client_id,&cid_tab),
                                      vmf_buffer_length,
                                     (unsigned8 *)p_vmf_basic_msg,&uReadSize);
        if ( vmf_ret < 0)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_basic_receive() error = %d\n",(int)getmypid(),vmf_ret);
            uReadSize = 0;
        }

        /* if message is a non basic message then set size to 0 so that message is ignored */
        if (p_vmf_basic_msg->msg_base.base.msg_type != MSG_TYPE_BASIC_MESSAGE)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_basic_receive() ignoring non basic message=%d\n",(int)getmypid(),p_vmf_basic_msg->msg_base.base.msg_type);
            uReadSize = 0;
        }
    }

#ifdef DO_CLIENT_DEBUG_HEX
    if (uReadSize > 0)
    {
        nw_con_HexDump("vmf-client-lib: nw_vmf_basic_receive() data=", (unsigned8 *)p_vmf_basic_msg, uReadSize);
    }
#endif

    if(VMF_OK != vmf_ret)
    {
        uReadSize = vmf_ret;
    }

    return(uReadSize);
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_timed receive    (vmf_client_id_t vmf_conn_id
 *                                           vmf_msg_t    *p_vmf_msg)
 *
 *   Description:   receive a vmf message with timeout
 *                  function blocks until it receives a message or timeouts
 *
 *   Parameters:    vmf_client_id       (input)connection_id
 *                  p_vmf_msg           (output)pointer to a vmf_message
 *                  vmf_buffer_length   (input)size of destination vmf_message buffer
 *                  ms_timeout          (input)timeout in ms
 *
 *   Return value:  \return number of received data bytes if > 0 or error
 *
 ******************************************************************************/
signed16 nw_vmf_timed_receive    (vmf_client_id_t vmf_client_id,    /**< INPUT connection_id */
                                  vmf_msg_t * p_vmf_msg,            /**< OUTPUT pointer to a vmf_message */
                                  unsigned16  vmf_buffer_length,    /**< INPUT length of COMPLETE message buffer */
                                  unsigned16  ms_timeout)           /**< INPUT message timeout in ms */
{
    unsigned32      start_time=1;
    unsigned32      end_time=1;
    unsigned16      new_ms_timeout=0;
    vmf_ret_t       vmf_ret;
    unsigned16      uReadSize=0;
    bool            bco_msg=false;

    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_timed_receive()- argument error: NULL pointer\n",(int)getmypid());
        vmf_ret = (VMF_ERR_NULL_POINTER);
    }
    else if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_timed_receive()- argument error: invalid vmf_client_id=%d\n",(int)getmypid(),vmf_client_id);
        delay(10);                      /* to allow killing the process*/
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else
    {
        /* get the start time */
        start_time = nw_os_cfg_get_ms_time();

        /* check if there are messages in the collector buffer */
        bco_msg = true;
        vmf_ret = nw_vmf_co_receive (vmf_client_id,vmf_buffer_length, (vmf_basic_msg_t *)p_vmf_msg,&uReadSize);
        if (vmf_ret != VMF_OK)
        {
            bco_msg = false;
            /* receive a message (can be a MOST or BASIC message) */
            /* this function will block until a message is received or until timeout*/

            new_ms_timeout = ms_timeout;
            while(true)
            {
                vmf_ret = nw_vmf_ipc_timed_receive (nw_vmf_client_get_rx_hdl(vmf_client_id,&cid_tab),
                                                    vmf_buffer_length,(unsigned8 *)p_vmf_msg,&uReadSize,new_ms_timeout);

                if (((0 == uReadSize) && (VMF_OK == vmf_ret)) || (VMF_OK != vmf_ret))
                {
                    /* timeout - check elapsed time */
                    end_time = nw_os_cfg_get_ms_time();
                    if ((end_time - start_time) < new_ms_timeout)
                    {
                        /* the function returned too early */
                        /* wait the remaining time */
                        new_ms_timeout = ms_timeout - (end_time - start_time);
                        if (vmf_ret != VMF_OK)
                        {
                            delay(1);
                        }
                        continue;
                    }
                }
                break;
            }

        #ifdef DO_CLIENT_DEBUG_HEX
            NW_VMF_CLIB_DEBUG_INFO("\nnw_vmf_timed_receive() nw_vmf_ipc_timed_receive() uReadSize=%d",uReadSize);
            nw_con_HexDump("vmf-client-lib: nw_vmf_timed_receive() raw-rx-data=", (unsigned8 *)p_vmf_msg, uReadSize);
        #endif

            if (VMF_OK == vmf_ret)
            {
                /* check if the received message is a co message */
                if ((COL_VMF_MSG == p_vmf_msg->vmf_basic_msg.msg_base.base.co_msg_type) &&
                    (p_vmf_msg->vmf_most_msg.msg_base.base.msg_type == MSG_TYPE_BASIC_MESSAGE))
                {
                    /* store message in co buffer*/
                    vmf_ret = nw_vmf_co_store_msg(vmf_client_id, (vmf_basic_msg_t *)p_vmf_msg,uReadSize);
                    if (VMF_OK == vmf_ret)
                    {
                        /* get first message from buffer */
                        vmf_ret = nw_vmf_co_receive (vmf_client_id,vmf_buffer_length, (vmf_basic_msg_t *)p_vmf_msg,&uReadSize);
                    }
                    else
                    {
                        /* message to big to fit in co-buffer!*/
                        vmf_ret = VMF_OK;   /* forward co-message to client */
                    }
                }
            }
        }

        if ( VMF_ERR_IPC_RECEIVE == vmf_ret)
        {
            /* error or timeout  - do not log any error */
            uReadSize = 0;
        }
        else if (VMF_ERR_NO_MORE_DATA == vmf_ret)
        {
            /* no more data  - do not log any error */
            uReadSize = 0;
        }
        else if ( vmf_ret < 0)
        {
            /* receive error */
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_timed_receive() error = %d\n",(int)getmypid(),vmf_ret);
            delay(0);
            uReadSize = 0;
        }
        else
        {
            /* reception was ok */
            /* return number of received bytes */
            vmf_ret = uReadSize;
        }

        /* check if message was cut during transfer */
        if (uReadSize > 0)
        {
            switch(p_vmf_msg->vmf_most_msg.msg_base.base.msg_type)
            {
                unsigned16 msg_len;

                case  MSG_TYPE_MOST_MESSAGE:
                    msg_len = sizeof(VMF_VAR_MOST_MSG_TYP(0)) + p_vmf_msg->vmf_most_msg.data.length;
                    if (msg_len > vmf_buffer_length)
                    {
                        /* message was cut ! */
                        NW_VMF_DEBUG_ERROR("%s: vmf-client-lib: nw_vmf_timed_receive() buffer to small! uReadSize=%d vmf-msglen=%d, bufferlen=%d\n",progname,uReadSize,msg_len,vmf_buffer_length);
                        vmf_ret = VMF_ERR_BUFFER_TO_SMALL;
                    }
                    break;

                case  MSG_TYPE_BASIC_MESSAGE:
                    msg_len = VMF_BASIC_MSG_LEN(p_vmf_msg->vmf_basic_msg.data.length);
                    if (msg_len > vmf_buffer_length)
                    {
                        /* message was cut ! */
                        NW_VMF_DEBUG_ERROR("%s: vmf-client-lib: nw_vmf_timed_receive() buffer to small! uReadSize=%d, vmf-msglen=%d, bufferlen=%d\n",progname,uReadSize,msg_len,vmf_buffer_length);
                        vmf_ret = VMF_ERR_BUFFER_TO_SMALL;
                    }
                    break;

                default:
                    /* ignore */
                    break;
            }
        }
    }

#ifdef DO_CLIENT_DEBUG_HEX
    if (bco_msg)
    {
        if (uReadSize > 0)
        {
            NW_VMF_CLIB_DEBUG_INFO("uReadSize=%d",uReadSize);
            nw_con_HexDump("vmf-client-lib: nw_vmf_timed_receive() co-data=", (unsigned8 *)p_vmf_msg, uReadSize);
        }
    }
    else
        if (uReadSize > 0)
        {
            NW_VMF_CLIB_DEBUG_INFO("uReadSize=%d",uReadSize);
            nw_con_HexDump("vmf-client-lib: nw_vmf_timed_receive() data=", (unsigned8 *)p_vmf_msg, uReadSize);
        }

#else
    UNUSED_PARAM(bco_msg);
#endif
    return(vmf_ret);
}



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_get_p2p_con_data receive    (vmf_client_id_t vmf_conn_id
 *                                           vmf_msg_t    *p_vmf_msg)
 *
 *   Description:   rget pid and cid of a p2p partner
 *
 *
 *   Parameters:    vmf_client_id       (input)connection_id
 *                  psp_conn_name       (input)connection name of p2p partner
 *                  p2p_pid             (input/output)pointer to pid of p2p partner
 *                  ms_timeout          (input/output)pointer to cid of p2p partner
 *
 *   Return value:  \return number of received data bytes if > 0 or error
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_get_p2p_con_data (vmf_client_id_t   cid,            /**< INPUT connection_id */
                                   char *            psp_conn_name,  /**< INPUT connection name of P2P partner */
                                   pid_t            *p2p_pid,        /**< OUTPUT pid of p2p partner */
                                   vmf_client_id_t  *p2p_cid)        /**< OUTPUT cid of p2p partner */
{
    vmf_ret_t   ret_val = VMF_OK;

    /* argument check */
    if ((cid >= MAX_CID)  || (cid < INITAL_CID_VALUE))
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_get_pwp_con_data()- argument error: invalid cid=%d",(int)getmypid(),cid);
        delay(10);                      /* to allow killing the process*/
        ret_val = (VMF_ERR_OUT_OF_RANGE);
    }
    else if ((NULL == p2p_pid) || (NULL == p2p_cid))
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_get_pwp_con_data()- argument error: NULL pointer",(int)getmypid());
        ret_val = (VMF_ERR_NULL_POINTER);
    }
    else if (NULL == psp_conn_name)
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_get_pwp_con_data()- argument error: NULL pointer",(int)getmypid());
        ret_val = (VMF_ERR_NULL_POINTER);
    }
    else if (pthread_mutex_lock((&shm_mutex)) != 0)                                                        \
    {
        /* error locking mutex */
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_get_pwp_con_data()- error locking mutex",(int)getmypid());
        ret_val = (VMF_ERR_MUX);
    }
    else
    {
        clshm_p2p_partner_t *p_pl=NULL;
        int                 cnt=0;

        /* create pointer to the payload */
        p_pl = &(cid_tab.my_cid[(unsigned8)cid].pcl_shm->pl.psp_partner);
        nw_os_sstrncpy(p_pl->name, psp_conn_name, MAX_NAME_LEN);
        cid_tab.my_cid[(unsigned8)cid].pcl_shm->valid = 0;      /* invalidate data - set to valid by router */

        /* send request to server */
        ret_val = nw_vmf_tx_shm_req(cid);
        if ( VMF_OK == ret_val)
        {
            /* wait for server response */
            while (cid_tab.my_cid[(unsigned8)cid].pcl_shm->valid != VMF_CLIENT_SHM_VALID_KEY)
            {
                nw_sleep_ms(VMF_CLIENT_SHM_DELAY);
                cnt++;
                if ((cnt * VMF_CLIENT_SHM_DELAY) > VMF_CLIENT_SHM_MAX_DELAY)
                {
                    ret_val = VMF_ERR_TIMEOUT;
                    NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_get_pwp_con_data()- timeout while waiting for server response",(int)getmypid());
                    break;
                }
            }

            if (VMF_OK == ret_val)
            {
                *p2p_pid = p_pl->pid;
                *p2p_cid = p_pl->cid;
            }
        }
        
        if (pthread_mutex_unlock((&shm_mutex)) != 0)                                                        \
        {
            /* error locking mutex */
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_get_pwp_con_data()- error unlocking mutex",(int)getmypid());
            ret_val = VMF_ERR_MUX;
        }
    }

    return ret_val;
}



/*****************************************************************************/
/*                          local functions                                  */
/*****************************************************************************/

/**************************************************************************//**
 *
 *   Function Name: nw_vmf_tx_shm_req (vmf_client_id_t vmf_conn_id)
 *
 *   Description:   send a shm request message to the router
 *
 *
 *   Parameters:    vmf_client_id       (input)connection_id
 *
 *   Return value:  \return vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_tx_shm_req (vmf_client_id_t   cid)           /**< INPUT connection_id */
{
    vmf_ctrl_msg_connect_t  myCtrlMsg;
    vmf_ret_t               vmf_ret;

        /* argument check */
    if ((cid >= MAX_CID)  || (cid < INITAL_CID_VALUE))
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_tx_shm_req()- argument error: invalid cid=%d",(int)getmypid(),cid);
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else
    {
        myCtrlMsg.base.msg_type  = MSG_TYPE_SHM_REQUEST;
        myCtrlMsg.base.pid       = cid_tab.pid;
        myCtrlMsg.base.client_id = cid;
        myCtrlMsg.base.msg_clk   = nw_os_cfg_get_ms_time();
        myCtrlMsg.pl_len = 0;

        vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(cid,&cid_tab), (unsigned8*)&myCtrlMsg, sizeof(myCtrlMsg));
        if (VMF_OK != vmf_ret)
        {
            NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_tx_shm_req() - nw_vmf_ipc_send() failed\n",(int)cid_tab.pid);
        }
    }

    return vmf_ret;
}



/**************************************************************************//**
 *
 *   Function Name: ini_cid_tab    (my_cid_tab_t *pcid_tab)
 *
 *   Description:   initialize the cid table
 *
 *
 *   Parameters:    pcid_tab            (input)pointer to cid table
 *
 *   Return value:  \return void
 *
 ******************************************************************************/
static void nw_vmf_ini_cid_tab            (my_cid_tab_t *pcid_tab) /**< INPUT pointer to cid table*/
{
    unsigned8 u8Cnt;

    NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_ini_cid_tab()");

    if (cid_tab_init_done != true)
    {
        (void)memset(pcid_tab,0,sizeof(my_cid_tab_t));
        cid_tab_init_done=true;
        /* mhammer3, tms 85418, cid must not be 0*/
        pcid_tab->free_cid=INITAL_CID_VALUE;
        pcid_tab->pid = getmypid();

        /* delete name, list and vmf_handles */
        for (u8Cnt = 0; u8Cnt < MAX_SERVER_CONNECTIONS; u8Cnt++)
        {
            pcid_tab->my_cid[u8Cnt].in_use = false;
            pcid_tab->my_cid[u8Cnt].my_channel_name[0]=0;
            pcid_tab->my_cid[u8Cnt].tx_handle = VMF_HANDLE_INVALID;
            pcid_tab->my_cid[u8Cnt].p2p_handle = VMF_HANDLE_INVALID;
            pcid_tab->my_cid[u8Cnt].rx_handle = VMF_HANDLE_INVALID;
            pcid_tab->my_cid[u8Cnt].pcol_rx_buffer = NULL;
            pcid_tab->my_cid[u8Cnt].col_rx_buffer_len = 0;
            pcid_tab->my_cid[u8Cnt].col_rx_buffer_msg_num = 0;
            pcid_tab->my_cid[u8Cnt].pcol_tx_buffer = NULL;
            pcid_tab->my_cid[u8Cnt].col_tx_buffer_len = 0;
            pcid_tab->my_cid[u8Cnt].col_tx_buffer_msg_num = 0;
            pcid_tab->my_cid[u8Cnt].collector_timeout = 0;
            pcid_tab->my_cid[u8Cnt].tx_timer_id = VMF_INVALID_TIMER;
            pcid_tab->my_cid[u8Cnt].receiver_started=false;
            pcid_tab->my_cid[u8Cnt].pcl_shm=NULL;
            pcid_tab->my_cid[u8Cnt].fd_shm=0;
        }
    }
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_free_cid    (my_cid_tab_t *pcid_tab)
 *
 *   Description:   free a cid in the table
 *
 *
 *   Parameters:    vmf_client_id   (input)client id
 *                  pcid_tab        (input)pointer to cid table
 *
 *   Return value:  \return void
 *
 ******************************************************************************/
static void nw_vmf_free_cid        (vmf_client_id_t vmf_client_id) /**< connection id */
{
    my_cid_tab_t *pcid_tab;

    pcid_tab = &cid_tab;
    pcid_tab->my_cid[(unsigned8)vmf_client_id].my_channel_name[0]=0;
    pcid_tab->my_cid[(unsigned8)vmf_client_id].tx_handle = VMF_HANDLE_INVALID;
    pcid_tab->my_cid[(unsigned8)vmf_client_id].p2p_handle = VMF_HANDLE_INVALID;
    pcid_tab->my_cid[(unsigned8)vmf_client_id].rx_handle = VMF_HANDLE_INVALID;
    pcid_tab->my_cid[(unsigned8)vmf_client_id].receiver_started=false;
    pcid_tab->my_cid[(unsigned8)vmf_client_id].pcl_shm=NULL;
    pcid_tab->my_cid[(unsigned8)vmf_client_id].fd_shm=0;
    pcid_tab->my_cid[(unsigned8)vmf_client_id].in_use = false;
}


/**************************************************************************//**
 *
 *   Function Name:  nw_vmf_register_client  (const char *my_channel_name,
 *                                            vmf_handle_t tx_handle,
 *                                            vmf_handle_t p2p_handle,
 *                                            vmf_handle_t rx_handle,
 *                                            my_cid_tab_t *pcid_tab,
 *                                            unsigned8    unpack_spy_msgs
 *                                            )
 *
 *   Description:   register a new client to the client tab
 *
 *
 *   Parameters:    vmf_client_id        (input)client id
 *                   my_channel_name     (input)pointer to channel name or NULL
 *                  tx_handle            (input)transmit handle
 *                  p2p_handle           (input)transmit handle for p2p connections
 *                  rx_handle            (input)receive handle
 *                  pcid_tab             (input)pointer to cid table
 *                  cb_api_vmf_msg_receive_callback rx (input)callback function
 *                  unsigned8            (input)unpack_spy_msgs
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_register_client (vmf_client_id_t vmf_client_id,                               /**< INPUT client id*/
                                         const char *my_channel_name,                                 /**< INPUT pointer to channel name or NULL*/
                                         vmf_handle_t tx_handle,                                      /**< INPUT transmit handle*/
                                         vmf_handle_t p2p_handle,                                     /**< INPUT p2p transmit handle*/
                                         vmf_handle_t rx_handle,                                      /**< INPUT receive handle*/
                                         my_cid_tab_t *pcid_tab,                                      /**< INPUT pointer to cid table*/
                                         unsigned8    unpack_spy_msgs)                                /**< INPUT unpack collected spy messages */

{
    vmf_ret_t               vmf_ret;
    
    NW_VMF_CLIB_DEBUG_INFO("  vmf-client-lib: nw_vmf_register_client() my_channel_name=%s, rx_handle=%d, tx_handle=%d\n",my_channel_name,rx_handle,tx_handle);

    /* test if cid-tab is already initialized */
    if (cid_tab_init_done)
    {
        nw_vmf_ini_cid_tab (pcid_tab);
    }

    if (vmf_client_id >= MAX_SERVER_CONNECTIONS)
    {
        vmf_ret = (vmf_client_id_t)VMF_ERROR;
    }
    else
    {
        /* mark entry as in-use */
        pcid_tab->my_cid[(unsigned8)vmf_client_id].in_use = true;

        /* copy name */
        nw_os_sstrncpy((pcid_tab->my_cid[(unsigned8)vmf_client_id].my_channel_name), my_channel_name, MAX_NAME_LEN);

        /* copy handles */
        pcid_tab->my_cid[(unsigned8)vmf_client_id].tx_handle = tx_handle;
        pcid_tab->my_cid[(unsigned8)vmf_client_id].p2p_handle = p2p_handle;
        pcid_tab->my_cid[(unsigned8)vmf_client_id].rx_handle = rx_handle;

        /* remind if we want to unpack collected vmf spy messages */
        pcid_tab->my_cid[(unsigned8)vmf_client_id].unpack_vmf_spy_msgs = unpack_spy_msgs;

        /* set receiver state to 'no-receiver is started' */
        pcid_tab->my_cid[(unsigned8)vmf_client_id].receiver_started=false;

        /* move to next free cid (if not already there) */
        if (pcid_tab->free_cid < MAX_SERVER_CONNECTIONS)
        {
            pcid_tab->free_cid++;
        }

        vmf_ret = VMF_OK;
    }

    return (vmf_ret);
}


/**********************************************************************************************
 *              static inline functions
 **********************************************************************************************/


/**************************************************************************//**
 *
 *   Function Name: vmf_client_get_free_cid    (my_cid_tab_t *pcid_tab)
 *
 *   Description:   get the next free cid
 *
 *
 *   Parameters:    pcid_tab             (input)pointer to cid table
 *
 *   Return value:  \return free client-id
 *
 ******************************************************************************/
static inline vmf_client_id_t nw_vmf_client_get_free_cid (my_cid_tab_t *pcid_tab)  /**< INPUT pointer to cid table*/
{
    vmf_client_id_t free_cid;
    unsigned8       u8Cnt;

    free_cid = MAX_SERVER_CONNECTIONS;
#if 0
    /* get next free cid */
    if (pcid_tab->free_cid < MAX_SERVER_CONNECTIONS)
    {
        free_cid = pcid_tab->free_cid;
    }
    else
#endif
    {
        /* try to find a freed cid */
        for (u8Cnt = INITAL_CID_VALUE; u8Cnt < MAX_SERVER_CONNECTIONS; u8Cnt++)
        {
            if (false == pcid_tab->my_cid[u8Cnt].in_use)
            {
                /* found free cid */
                free_cid = u8Cnt;
                break;
            }
        }
    }

    return (free_cid);
}



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_client_get_tx_hdl    ( vmf_client_id_t vmf_client_id.
 *                                                my_cid_tab_t *pcid_tab
 *
 *   Description:   get the tx handle out of the cid table
 *
 *
 *   Parameters:    vmf_conn_id          (input)connection_id
 *                  pcid_tab             (input)pointer to cid table
 *
 *
 *   Return value:  \return tx handle
 *
 ******************************************************************************/
static inline vmf_handle_t nw_vmf_client_get_tx_hdl (vmf_client_id_t vmf_client_id, /**< connection id */
                                              my_cid_tab_t *pcid_tab)        /** <INPUT pointer to cid table */
{
    return pcid_tab->my_cid[(unsigned8)vmf_client_id].tx_handle;
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_client_get_p2p_hdl    ( vmf_client_id_t vmf_client_id.
 *                                                my_cid_tab_t *pcid_tab
 *
 *   Description:   get the p2p handle from the cid table
 *
 *
 *   Parameters:    vmf_conn_id          (input)connection_id
 *                  pcid_tab             (input)pointer to cid table
 *
 *
 *   Return value:  \return tx handle
 *
 ******************************************************************************/
#if 0 
/* jmerkle 2016-08-16 -- function not used! */

static inline vmf_handle_t nw_vmf_client_get_p2p_hdl (vmf_client_id_t vmf_client_id, /**< connection id */
                                               my_cid_tab_t *pcid_tab)        /** <INPUT pointer to cid table */
{
    return pcid_tab->my_cid[(unsigned8)vmf_client_id].p2p_handle;
}
#endif


/**************************************************************************//**
 *
 *   Function Name: vmf_client_get_rx_hdl    ( vmf_client_id_t vmf_client_id.
 *                                             my_cid_tab_t *pcid_tab
 *
 *   Description:   get the rx handle out of the cid table
 *
 *
 *   Parameters:    vmf_conn_id          (input)connection_id
 *                  pcid_tab             (input)pointer to cid table
 *
 *
 *   Return value:  \return rx handle
 *
 ******************************************************************************/
static inline vmf_handle_t nw_vmf_client_get_rx_hdl (vmf_client_id_t vmf_client_id,    /**< connection id */
                                              my_cid_tab_t *pcid_tab)           /**< INPUT pointer to cid table */
{
    return pcid_tab->my_cid[(unsigned8)vmf_client_id].rx_handle;
}



/*****************************************************************************/
/*                          vmf private functions                            */
/*****************************************************************************/



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_create_shm_channel_name()
 *
 *   Description:   create a shared memory name for this client
 *
 *   Parameters:    pid             (input)
 *                  cid             (input)
 *                  channel_name    (output) buffer for shm_channel
 *                  buffer_size     (input) size of shm_channel name buffer
 *
 *   Function Return value: \return  true if OK else false
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_create_shm_channel_name (pid_t pid, unsigned8 cid, char *p_channel_name,unsigned8 buffer_size)
{
    vmf_ret_t ret_val = VMF_OK;
    char    chtmp[MAX_NAME_LEN]={0};

    memset(p_channel_name,0,buffer_size);
    ret_val = nw_vmf_ipc_create_channel_name(pid, cid, chtmp, sizeof(chtmp));
    if (VMF_OK == ret_val)
    {
        (void) snprintf(p_channel_name,buffer_size,"shm_%s",chtmp);
        NW_VMF_DEBUG_INFO("vmf-client-lib: nw_vmf_create_shm_channel_name() - name = %s",p_channel_name);
    }
    else
    {
        NW_VMF_DEBUG_ERROR("vmf-client-lib: nw_vmf_create_shm_channel_name() - nw_vmf_ipc_create_channel_name failed");
    }

    return ret_val;
}



/**********************************************************************************************
 *               vmf message collector functions
 **********************************************************************************************/

  /**************************************************************************//**
 *
 *   Function Name: nw_vmf_co_client_init_buffer  ( vmf_basic_msg_t  *vmf_co_msg)
 *
 *   Description:   init a message collector message
 *
 *
 *   Parameters:    pvmf_co_msg       (input/output)   collector message
 *
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_co_client_init_buffer ( vmf_client_id_t vmf_client_id, signed32 timeout,my_cid_tab_t *pcid_tab)
{
    vmf_ret_t vmf_ret = VMF_OK;
    vmf_basic_msg_t *pvmf_co_msg = NULL;
    unsigned16 blen=0;

    /* argument check */
    if ((vmf_client_id > MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        /* invalid client id */
        NW_VMF_DEBUG_ERROR("  vmf-client-lib: nw_vmf_co_client_init_buffer() - invalid client id=%d, MAX_CID=%d",vmf_client_id,MAX_CID);
        vmf_ret = VMF_ERR_INVALID_CID;
    }
    else if (EOK != pthread_mutex_init(&(pcid_tab->my_cid[(unsigned8)vmf_client_id].co_mutex),NULL))
    {
        /* pthread_mutex_init() failed */
        NW_VMF_DEBUG_ERROR("  vmf-client-lib: cid=%d nw_vmf_co_client_init_buffer() - pthread_mutex_init() failed",vmf_client_id);
        vmf_ret = VMF_ERROR;
    }
    else
    {
        /* get a tx collector buffer */
        blen = VMF_BASIC_MSG_LEN(VMF_CO_DATA_LEN);
        vmf_ret = nw_vmf_co_client_get_buffer(&(pcid_tab->my_cid[(unsigned8)vmf_client_id].pcol_tx_buffer),blen+1);
    }

    /* init the co message */
    if (VMF_OK == vmf_ret)
    {
        pcid_tab->my_cid[(unsigned8)vmf_client_id].collector_timeout = timeout;
        pcid_tab->my_cid[(unsigned8)vmf_client_id].col_tx_buffer_len = blen;
        pvmf_co_msg = pcid_tab->my_cid[(unsigned8)vmf_client_id].pcol_tx_buffer;
        if (NULL != pvmf_co_msg)
        {
            pvmf_co_msg->data.length = 0;
        }
        else
        {
            vmf_ret = VMF_ERR_NULL_POINTER;
        }
    }
    else
    {
        NW_VMF_DEBUG_ERROR("  vmf-client-lib: cid=%d nw_vmf_co_client_init_buffer() - error",vmf_client_id);
    }

    return vmf_ret;
}



/*************************************************************************//**
 *
 *   collector buffer timeout function
 *
 *   \param[in]     system_time_ms  -   time in ms
 *   \param[in]     arg             -   pointer to cid tab entry
 *   \return        void
 *
 ******************************************************************************/
static void vw_vmf_co_tx_timeout_cb(unsigned32 system_time_ms,void *arg)
{
    vmf_basic_msg_t *pvmf_basic_co_msg;
    my_cid_t        *pmy_cid;
    pthread_mutex_t *pco_mutex=NULL;
    vmf_handle_t     tx_hdl=0;
    vmf_ret_t        vmf_ret = VMF_OK;

    UNUSED_PARAM(system_time_ms);

    pmy_cid           =   arg;
    pco_mutex         =   &pmy_cid->co_mutex;
    pvmf_basic_co_msg =   pmy_cid->pcol_tx_buffer;
    tx_hdl            =   pmy_cid->tx_handle;

    pmy_cid->tx_timer_id = VMF_INVALID_TIMER;

    vmf_ret = nw_vmf_co_client_transfer_msg ( tx_hdl, pco_mutex, pvmf_basic_co_msg);

    if (vmf_ret != VMF_OK)
    {
        NW_VMF_DEBUG_ERROR("  vmf-client-lib: vw_vmf_co_tx_timeout() - nw_vmf_co_client_transfer_msg() failed");
    }

}


/*************************************************************************//**
 *
 *   Add a message to the co message and
 *   send message if
 *   1. no more room to store message in co buffer
 *   2. timeout
 *   3. message is send to differen group
 *
 *   \param[in]     vmf_handle   -- logic channel handle
 *                                  (from nw_vmf_ipc_open or nw_vmf_ipc_create)
 *   \param[in]     buffer       -- pointer to message to send
 *   \param[in]     number_bytes -- number of bytes to send
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_co_basic_send (vmf_client_id_t vmf_client_id, vmf_basic_msg_t  *pvmf_msg, unsigned16 msg_len)
{
    vmf_basic_msg_t  *pvmf_basic_co_msg = NULL;
    pthread_mutex_t  *pco_mutex=NULL;
    vmf_ret_t         vmf_ret;
    vmf_handle_t      tx_hdl=0;
    unsigned16        co_msg_buff_len=0;
    bool              start_timer = false;

    /* argument check */
    if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        /* invalid client id */
        NW_VMF_DEBUG_ERROR("  vmf-client-lib: nw_vmf_co_basic_send() - invalid client id=%d",vmf_client_id);
        vmf_ret = VMF_ERR_INVALID_CID;
    }
    else if (NULL == pvmf_msg)
    {
        NW_VMF_DEBUG_ERROR("  vmf-client-lib: cid =%d nw_vmf_co_client_add_msg() - pvmf_msg=NULL",vmf_client_id);
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else
    {
#ifdef DO_CLIENT_DEBUG_HEX
        NW_VMF_CLIB_DEBUG_INFO("  nw_vmf_co_basic_send() cid =%d, len =%d",vmf_client_id,msg_len);
        if (msg_len <= 127)
        {
            nw_con_HexDump("  nw_vmf_co_basic_send data:",(void *)pvmf_msg,msg_len);
        }
        else
        {
            nw_con_HexDump("  nw_vmf_co_basic_send data (cut):",(void *)pvmf_msg,127);
        }
#endif
        pvmf_basic_co_msg =   cid_tab.my_cid[(unsigned8)vmf_client_id].pcol_tx_buffer;
        co_msg_buff_len   =   cid_tab.my_cid[(unsigned8)vmf_client_id].col_tx_buffer_len;
        pco_mutex         = &(cid_tab.my_cid[(unsigned8)vmf_client_id].co_mutex);
        tx_hdl            =   nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab);

        if (pvmf_basic_co_msg->data.length == 0)
        {
            start_timer = true;
        }

        vmf_ret = nw_vmf_co_client_add_msg (vmf_client_id, pco_mutex,pvmf_basic_co_msg, co_msg_buff_len, pvmf_msg,true);
        if (vmf_ret != VMF_OK)
        {
            /* we got an error - so try to send the co-buffer to the ipc */
            vmf_ret = nw_vmf_co_client_transfer_msg ( tx_hdl, pco_mutex, pvmf_basic_co_msg);
            if (vmf_ret == VMF_OK)
            {
                /* stop the timer */
                if (cid_tab.my_cid[(unsigned8)vmf_client_id].tx_timer_id != VMF_INVALID_TIMER)
                {
                    (void)vmf_timer_stop(cid_tab.my_cid[(unsigned8)vmf_client_id].tx_timer_id);
                    cid_tab.my_cid[(unsigned8)vmf_client_id].tx_timer_id = VMF_INVALID_TIMER;
                }

                /* this original message was not send yet - so try to add message to new co_message */
                vmf_ret = nw_vmf_co_client_add_msg (vmf_client_id, pco_mutex, pvmf_basic_co_msg, co_msg_buff_len, pvmf_msg,true);
                if (vmf_ret != VMF_OK)
                {
                    /* adding the message to a co message didnt work (perhaps to big )*/
                    /* transfer direct to the ipc */
                    start_timer = false;
                    vmf_ret = nw_vmf_ipc_send(tx_hdl,(unsigned8*)pvmf_msg, msg_len);
                    if (VMF_OK != vmf_ret)
                    {
                        NW_VMF_DEBUG_ERROR("  pid=%d vmf-client-lib: cid=%d nw_vmf_co_basic_send() - nw_vmf_ipc_send() failed",(int)getmypid(),vmf_client_id);
                    }
                    else
                    {
    #ifdef DO_CLIENT_DEBUG_HEX
                        NW_VMF_CLIB_DEBUG_INFO("  pid=%d vmf-client-lib: cid=%d nw_vmf_co_basic_send() - nw_vmf_ipc_send(%d) called direct",(int)getmypid(),vmf_client_id,msg_len);
                        nw_con_HexDump("  nw_vmf_ipc_send OK",(void *)pvmf_msg,48);
    #endif
                    }
                }
                else
                {
                    start_timer = true;
                }
            }
            else
            {
                NW_VMF_DEBUG_ERROR("  vmf-client-lib: cid = %d nw_vmf_co_basic_send() - nw_vmf_co_client_transfer_msg() failed with %d",vmf_client_id,vmf_ret);
            }
        }
        else
        {
            NW_VMF_CLIB_DEBUG_INFO("  nw_vmf_co_basic_send() added message to co-buff");
        }

        if (start_timer)
        {
            /* message was the first msg added to co-message */
            /* start the the timeout timer */
            unsigned16 *ptx_timer_id=NULL;
            unsigned16 tx_timeout=0;

            /* start the timer for the tx timeout */
            ptx_timer_id = &(cid_tab.my_cid[(unsigned8)vmf_client_id].tx_timer_id);
            tx_timeout   = cid_tab.my_cid[(unsigned8)vmf_client_id].collector_timeout;
            vmf_ret = vmf_timer_start (ptx_timer_id, tx_timeout, vw_vmf_co_tx_timeout_cb,&(cid_tab.my_cid[(unsigned8)vmf_client_id]));
            if (vmf_ret != VMF_OK)
            {
                NW_VMF_DEBUG_ERROR("  vmf-client-lib: cid = %d nw_vmf_co_basic_send() - vmf_timer_start() failed with %d",vmf_client_id,vmf_ret);
            }
         }
         NW_VMF_CLIB_DEBUG_INFO("  nw_vmf_co_basic_send() - ret = %d",vmf_ret);
    }

    return vmf_ret;
}





/**************************************************************************//**
 *
 *   Function Name: nw_vmf_connection_state ()\n
 *   Description:   return the VMF connection state\n
 *
 *
 *   Parameters:    cid  (input) connection cid \n
 *   Return value:  \return  VMF_OK if the connection to VMF is established
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_connection_state( vmf_client_id_t vmf_client_id)          /*!< INPUT cid  */
{

#ifdef VMF_TRACE
    static      unsigned32  old_cnt=0;
    static      unsigned32  last_time =0;
    static      vmf_ret_t   old_status = VMF_ERROR;

    int         fd=-1;
    unsigned32  current_cnt=0;
    unsigned32  now = nw_os_cfg_get_ms_time();
    void        *shm  = NULL;
    vmf_ret_t   ret_val = VMF_ERROR;

    /* test cid */
    if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        NW_VMF_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_connection_state()- argument error: invalid vmf_client_id=%d",(int)getmypid(),vmf_client_id);
        delay(10);                      /* to allow killing the process*/
        ret_val = (VMF_ERR_OUT_OF_RANGE);
    }
    /* return last status if the request was to early */
    else if ((now-last_time ) < VMF_CLIENT_CONSTATE_MIN_TIME)
    {
        ret_val = old_status;
    }
    else
    {
        /* check if shared memory was already mapped */
        if (NULL == vmf_trace_shm)
        {
            last_time=now;

            /* try to open the shared memory */
            fd = nw_shm_open(VMF_TRACE_SHM);
            if (-1 == fd)
            {
                /* shm open failed */
                ret_val = VMF_ERROR;
            }
            else
            {
                /* shm is open */
                NW_VMF_CLIB_DEBUG_INFO ("pid=%d vmf-client-lib: nw_vmf_connection_state():shm_open OK - fd=%d\n",(int)getmypid(), (int)fd);

                shm = mmap(NULL, sizeof(vmf_trace_shm_t), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
                if (shm == (void*)MAP_FAILED)
                {
                    /* Failed to access the memory */
                    (void) nw_shm_close(fd);
                    vmf_trace_shm = NULL;
                    ret_val = VMF_ERROR;
                }
                else
                {
                    /* check if mmap returned a NULL pointer */
                    if (NULL == shm)
                    {
                        NW_VMF_CLIB_DEBUG_ERROR ("pid=%d vmf-client-lib: nw_vmf_connection_state():mmap returned NULL pointer\n",(int)getmypid());
                        ret_val = VMF_ERROR;
                    }
                    else
                    {
                        NW_VMF_CLIB_DEBUG_INFO ("pid=%d vmf-client-lib: nw_vmf_connection_state():mmap OK\n",(int)getmypid());
                        vmf_trace_shm = (vmf_trace_shm_t*)shm;
                        ret_val = VMF_OK;
                    }
                }
            }
        }

        /* test if VMF is alive */
        ret_val = VMF_ERROR;        /* pre-set the error status before the actual test */
        if (vmf_trace_shm != NULL)
        {
            last_time=now;

            current_cnt = vmf_trace_shm->task[0].msg_num;
            if (old_cnt != current_cnt)
            {
                /* the counter did change so VMF is alive */
                ret_val = VMF_OK;
                old_cnt = current_cnt;
            }
        }

        old_status = ret_val;
    }
    return ret_val;

#else
    return VMF_ERR_NOT_SUPPORTED;
#endif

}




 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_co_receive()
 *
 *   Description:   reveive a message collector message
 *
 *
 *   Parameters:    vmf_client_id_t     (input)     client id
 *                  dest_buffer_len     (input)     length of destination buffer
 *                  pdest_vmf_msg       (output)    pointer to destination message buffer
 *                  dest_read_num_bytes (output)    pointer to received message length
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_co_receive (vmf_client_id_t vmf_client_id,unsigned16 dest_buffer_len,
                                    vmf_basic_msg_t *pdest_vmf_msg,unsigned16 *dest_read_num_bytes)
{
    vmf_ret_t       vmf_ret = VMF_ERR_NO_MORE_DATA;
    vmf_basic_msg_t *pvmf_co_buffer=NULL;
    unsigned16      col_rx_buffer_len=0;


    pvmf_co_buffer    = cid_tab.my_cid[(unsigned8)vmf_client_id].pcol_rx_buffer;
    col_rx_buffer_len = cid_tab.my_cid[(unsigned8)vmf_client_id].col_rx_buffer_len;

    /* check if there are still messages in the co-buffer  */
    if (NULL != pvmf_co_buffer)
    {
        if (cid_tab.my_cid[(unsigned8)vmf_client_id].col_rx_buffer_msg_num > 0)
        {
            unsigned16      msg_len;

            /* get next message from co-buffer */
            vmf_ret = nw_vmf_co_client_get_next_co_msg (pvmf_co_buffer, col_rx_buffer_len,pdest_vmf_msg,dest_buffer_len);
            if (VMF_OK == vmf_ret)
            {
                /* check if message is an embedded message */
                if (pdest_vmf_msg->msg_base.base.msg_type == MSG_TYPE_BASIC_EMBEDDED_MESSAGE)
                {
                    /* get embedded message */
                    memmove(pdest_vmf_msg,(vmf_basic_msg_t*)pdest_vmf_msg->data.pl,pdest_vmf_msg->data.length);
                    /* get new message length */
                    vmf_ret = nw_vmf_co_client_get_msg_len((vmf_msg_t*)pdest_vmf_msg,&msg_len);
                }
                else
                {
                    /* message is a basic message */
                    msg_len = VMF_BASIC_MSG_LEN(pdest_vmf_msg->data.length);
    #ifdef DO_CLIENT_DEBUG_HEX
                    if (msg_len > 0)
                    {
                        nw_con_HexDump("  vmf-client-lib: nw_vmf_co_receive() data from co=", (unsigned8 *)pdest_vmf_msg, msg_len);
                    }
                    NW_VMF_CLIB_DEBUG_INFO("  nw_vmf_co_receive() msg-len=%d",msg_len);
    #endif
                    *dest_read_num_bytes = msg_len;
                }
            }
            else
            {
                /* no more messages - discard buffer */
                cid_tab.my_cid[(unsigned8)vmf_client_id].col_rx_buffer_msg_num = 0;
            }
        }
        else
        {
            NW_VMF_CLIB_DEBUG_INFO("  nw_vmf_co_receive()col_rx_buffer_msg_num=%d",cid_tab.my_cid[(unsigned8)vmf_client_id].col_rx_buffer_msg_num);
        }
    }
    return vmf_ret;
}



 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_co_store_msg()
 *
 *   Description:   store a co message in a co buffer
 *
 *
 *   Parameters:    vmf_client_id_t     (input)     client id
 *                  pco_vmf_msg         (input)     vmf co-messgae
 *                  co_vmf_msg_len      (input)     size of vmf co-message
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_co_store_msg (vmf_client_id_t vmf_client_id, vmf_basic_msg_t *pco_vmf_msg,unsigned16 co_vmf_msg_len)
{
    unsigned16 blen = VMF_BASIC_MSG_LEN(VMF_CO_DATA_LEN + 1);
    vmf_ret_t       vmf_ret = VMF_OK;

    if (co_vmf_msg_len > blen)
    {
        /* message will not fit into buffer */
        NW_VMF_CLIB_DEBUG_INFO("  %s: vmf-client-lib: nw_vmf_co_store_msg() co-message to big to fit in co-buffer",progname);
        vmf_ret = VMF_ERR_CO_BUFFER;
    }
    else
    {
        /* check if a buffer was already allocated */
        if (NULL == cid_tab.my_cid[(unsigned8)vmf_client_id].pcol_rx_buffer)
        {
            /* allocate a buffer */
            vmf_ret = nw_vmf_co_client_get_buffer(&(cid_tab.my_cid[(unsigned8)vmf_client_id].pcol_rx_buffer),blen);
            if (vmf_ret != VMF_OK)
            {
                NW_VMF_DEBUG_ERROR("  %s: vmf-client-lib: nw_vmf_co_store_msg() nw_vmf_co_client_get_buffer() failed",progname);
                vmf_ret = VMF_ERR_CO_BUFFER;
            }
        }

        if (VMF_OK == vmf_ret)
        {
            /* copy the received vmf message to the co-buffer*/
            /* store buffer len */
            nw_os_smemcpy((void*)cid_tab.my_cid[(unsigned8)vmf_client_id].pcol_rx_buffer,blen,(void*)pco_vmf_msg,co_vmf_msg_len);

            /* store number of vmf messages that are stored in co-buffer and buffer len in client struct */
            cid_tab.my_cid[(unsigned8)vmf_client_id].col_rx_buffer_len = blen;
            cid_tab.my_cid[(unsigned8)vmf_client_id].col_rx_buffer_msg_num = pco_vmf_msg->msg_base.base.vmf_co_num_msgs;
        }
    }

    return vmf_ret;
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_init_shm()
 *
 *   Description:   init the shared memory
 *
 *   Parameters:    pointer to shared memory
 *
 *   Function Return value: - vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_init_shm(vmf_client_shm_t *pshm)
{
    vmf_ret_t       vmf_ret;

    if (NULL == pshm)
    {
        NW_VMF_DEBUG_ERROR("  %s: vmf-client-lib: nw_vmf_init_shm() NULLPOINTER!",progname);
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else
    {
        memset(pshm,0,sizeof(vmf_client_shm_t));
        pshm->version = VMF_CLIENT_SHM_VERSION;
        pshm->valid = VMF_CLIENT_SHM_VALID_KEY;
        vmf_ret = VMF_OK;
    }
    return vmf_ret;
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



