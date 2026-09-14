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
  Author:               Joachim Becker

  Compiler/Assembler:   gcc
  Target Hardware:      Any

  *****************************************************************************/
#define VMF_CLIENT_C


#include "vmf_app_util.h"
#include "vmf.h"
#include "vmf_ipc.h"
#include "vmf_client.h"

#define DEBUG_STATIC        static

#define VMF_CLIENT_LOCK      {(void)vmf_mutex_lock(&vmf_cl_mux);}
#define VMF_CLIENT_UNLOCK    {(void)vmf_mutex_release(&vmf_cl_mux);}
#define VMF_MUTEX_INIT       {(void)vmf_mutex_init(&vmf_cl_mux);}

#define NW_VMF_CLIB_DEBUG_INFO(...)      // {printf("info:   ");printf("%s - ",__func__);printf(__VA_ARGS__);printf("\n");}
#define NW_VMF_CLIB_DEBUG_WARNING(...)   // {printf("warning:");printf("%s - ",__func__);printf(__VA_ARGS__);printf("\n");}
#define NW_VMF_CLIB_DEBUG_ERROR(...)     // {printf("error:  ");printf("%s - ",__func__);printf(__VA_ARGS__);printf("\n");}

#define MAX_CID             (cid_tab.free_cid)
#define CID_TX_HDL(cid)     (cid_tab.my_cid[cid].tx_handle)
#define CID_RX_HDL(cid)     (cid_tab.my_cid[cid].rx_handle)
#define FOREVER             (true)
#define INITAL_CID_VALUE    (1)


/************** module global variables ************/
static BOOL                 nw_vmf_ipc_init_done = FALSE;
static BOOL                 init_done=FALSE;
static BOOL                 cid_tab_init_done=FALSE;                /*!< true if cd-table is initialized */
static my_cid_tab_t         cid_tab={0};                            /*!< cid table */
static MUTEX_STRUCT         vmf_cl_mux;



/************** local functions  ************/
static void  nw_vmf_ini_cid_tab                     (my_cid_tab_t *pcid_tab);
static vmf_client_id_t  nw_vmf_client_get_free_cid  (my_cid_tab_t *pcid_tab);
static vmf_ret_t        nw_vmf_register_client      (vmf_client_id_t vmf_client_id,const char *my_channel_name,
                                                     vmf_handle_t tx_handle,vmf_handle_t rx_handle,my_cid_tab_t *pcid_tab);
static vmf_handle_t     nw_vmf_client_get_rx_hdl    (vmf_client_id_t vmf_client_id, my_cid_tab_t *pcid_tab);
static vmf_handle_t     nw_vmf_client_get_tx_hdl    (vmf_client_id_t vmf_client_id, my_cid_tab_t *pcid_tab);
static BOOL             vmf_mutex_init              (MUTEX_STRUCT *pmutex);
static BOOL             vmf_mutex_release           (MUTEX_STRUCT *pmutex);
static BOOL             vmf_mutex_lock              (MUTEX_STRUCT *pmutex);


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
    return VMF_OK;

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
    vmf_handle_t            tx_handle = VMF_HANDLE_INVALID;
    vmf_handle_t            p2p_handle = VMF_HANDLE_INVALID;
    vmf_handle_t            rx_handle=VMF_HANDLE_INVALID;
    vmf_client_id_t         my_client_id=0;
    vmf_ret_t               vmf_ret=VMF_ERROR;
    int                     current_timeout=0;

    VMF_MUTEX_INIT
    VMF_CLIENT_LOCK

    if (NULL == p_my_conn_string)
    {
        NW_VMF_CLIB_DEBUG_INFO("");
    }
    else
    {
        NW_VMF_CLIB_DEBUG_INFO("conn_string=%s",p_my_conn_string);
    }

    /* init cid table */
    if (FALSE == cid_tab_init_done)
    {
        nw_vmf_ini_cid_tab(&cid_tab);
    }

    /* init IPC */
    if (FALSE == nw_vmf_ipc_init_done)
    {
        (void)nw_vmf_ipc_init(FALSE);
        nw_vmf_ipc_init_done = TRUE;
    }

    /* get a free cid */
    my_client_id = nw_vmf_client_get_free_cid(&cid_tab);
    if (my_client_id >= MAX_SERVER_CONNECTIONS)
    {
        NW_VMF_CLIB_DEBUG_ERROR("pid=%d, vmf-client-lib: nw_vmf_connect() - nw_vmf_client_get_free_cid() failed",(int)getmypid());
        VMF_CLIENT_UNLOCK
        return ((vmf_client_id_t)VMF_ERROR);
    }

    /* try to open a tx channel to the vmf-Server */
    tx_handle = VMF_ERROR;
    while (tx_handle < 0)
    {
        NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_ipc_open");
        tx_handle = nw_vmf_ipc_open(VMF_IPC_SERVER_NAME,IPC_BLOCKING);
        if (tx_handle < 0)
        {
            /* an error occured - try again */
            if (current_timeout >= VMF_CLIENT_WAIT_SERVER_TIMEOUT)
            {
                /* abort */
                NW_VMF_CLIB_DEBUG_ERROR("pid=%d, vmf-client-lib: nw_vmf_connect() - nw_vmf_ipc_open() failed\n",(int)getmypid());
                break;;
            }

            current_timeout += VMF_CLIENT_WAIT_SOME_TIME;
            delay(VMF_CLIENT_WAIT_SOME_TIME);
        }
    }

    /* test if a connection to the server was established */
    if ((VMF_HANDLE_INVALID == tx_handle) || (tx_handle < 0))
    {
        NW_VMF_CLIB_DEBUG_ERROR("vmf-client-lib: nw_vmf_connect() - connection to server failed\n");
        (void)nw_vmf_ipc_close(tx_handle);
        (void)nw_vmf_ipc_destroy(rx_handle);
        VMF_CLIENT_UNLOCK
        return ((vmf_client_id_t)VMF_ERROR);
    }

    if (message_queue_size > 0)
    {
        vmf_msg_t   myCtrlConMsg;
        // char        pl[MAX_CTRL_CONN_PL_LEN];
        unsigned16  cstr_len=0;
        char        task_name[50];

        /* get channel name */
        vmf_ret=nw_vmf_ipc_create_channel_name(cid_tab.my_cid[my_client_id].pid, my_client_id, myChannelName, sizeof(myChannelName));
        if (VMF_OK != vmf_ret)
        {
            NW_VMF_CLIB_DEBUG_ERROR("nw_vmf_ipc_create_channel_name() failed\n");
            VMF_CLIENT_UNLOCK
            return ((vmf_client_id_t)vmf_ret);
        }
        NW_VMF_CLIB_DEBUG_INFO("created channel name=%s",myChannelName);

        /* create own rx channel */
        rx_handle=nw_vmf_ipc_create(myChannelName, message_queue_size, message_size);
        NW_VMF_CLIB_DEBUG_INFO("nw_vmf_ipc_create() done - rx_handle=%d",rx_handle);
        if ((VMF_HANDLE_INVALID == rx_handle) || (rx_handle < 0))
        {
            NW_VMF_CLIB_DEBUG_ERROR("nw_vmf_ipc_create() failed, myChannelName=%s \n",myChannelName);
            VMF_CLIENT_UNLOCK
            return ((vmf_client_id_t)VMF_ERROR);
        }

        /* prepare and send the connect-control-message */
        memset(&myCtrlConMsg,0,sizeof(myCtrlConMsg));
        myCtrlConMsg.msg_type  = VMF_CTRL_MSG;
        myCtrlConMsg.ctrl_type = VMF_CTRL_CONNECT;
        myCtrlConMsg.pid       = cid_tab.my_cid[my_client_id].pid;
        myCtrlConMsg.cid       = my_client_id;
        {
            unsigned32 ctime = nw_os_cfg_get_ms_time();
            myCtrlConMsg.msg_time    = ctime & 0xffff;
            myCtrlConMsg.msg_time_hh = (ctime >> 16) & 0xff;
        }

        /* add process name and connection string to message */
        /* create prefix == process name */
#if ( VS_MICRO_CORE_M4 == VS_MICRO_CORE )
        #define MQX_CPU_NAME    "M4"
#else
        #define MQX_CPU_NAME    "A5"
#endif
        vmf_ret = vmf_ipc_get_taskname(task_name,sizeof(task_name));
        if (vmf_ret != VMF_OK)
        {
            strncpy(task_name,MQX_CPU_NAME,sizeof(task_name));
        }

        if (p_my_conn_string != NULL)
        {
            snprintf(myCtrlConMsg.pl, MAX_CTRL_CONN_PL_LEN, "%s,%s",task_name,p_my_conn_string);
        }
        else
        {
            snprintf(myCtrlConMsg.pl, MAX_CTRL_CONN_PL_LEN, "%s,%s",task_name,NW_VMF_CLIENT_UNDEFINED);
        }
        myCtrlConMsg.pl_len = strlen(myCtrlConMsg.pl)+1;    /* payload length = string-length + 1 for zero */

        vmf_ret = nw_vmf_ipc_send (tx_handle, (unsigned8*)&myCtrlConMsg, VMF_MSG_LEN(myCtrlConMsg.pl_len));
        if (VMF_OK != vmf_ret)
        {
            NW_VMF_CLIB_DEBUG_ERROR("pid=%d vmf-client-lib: nw_vmf_connect() - nw_vmf_ipc_send() failed\n",(int)getmypid());
            (void)nw_vmf_ipc_close(tx_handle);
            (void)nw_vmf_ipc_destroy(rx_handle);
            VMF_CLIENT_UNLOCK
            return ((vmf_client_id_t)vmf_ret);
        }
        else
        {
            NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_ipc_send(MSG_TYPE_CONNECT)- OK\n");
        }
    }

    /* register connection-id, connection name and handles */
    NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_register_client(%s)",p_my_conn_string);
    vmf_ret = nw_vmf_register_client (my_client_id,p_my_conn_string,tx_handle,rx_handle,&cid_tab);
    if (VMF_OK != vmf_ret)
    {
        NW_VMF_CLIB_DEBUG_ERROR("vmf-client-lib: nw_vmf_connect() - register_client() failed\n");
        (void)nw_vmf_ipc_close(tx_handle);
        (void)nw_vmf_ipc_destroy(rx_handle);
        VMF_CLIENT_UNLOCK
        return ((vmf_client_id_t)vmf_ret);
    }
    else
    {
        NW_VMF_CLIB_DEBUG_INFO("nw_vmf_register_client() OK\n");
    }

    VMF_CLIENT_UNLOCK
    NW_VMF_CLIB_DEBUG_INFO("return %d",my_client_id);
    nw_sleep_ms(0);
    return (my_client_id);
}





/**************************************************************************//**
 *
 *   Function Name: nw_vmf_send (vmf_client_id_t vmf_client_id
 *                               vmf_msg_t *p_vmf_msg)
 *
 *   Description:   To send vmf msg
 *
 *   Parameters:    vmf_client_id  (input)connection_id
 *                  p_vmf_msg      (input)pointer to a basic vmf_message
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_send     (vmf_client_id_t vmf_client_id,     /**<INPUT connection_id*/
                           vmf_msg_t *p_vmf_msg)        /**<INPUT pointer to a basic vmf_message*/
{
    vmf_ret_t       vmf_ret;
    unsigned16      u_len;

    NW_VMF_CLIB_DEBUG_INFO("cid=%d",vmf_client_id);

    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_VMF_CLIB_DEBUG_ERROR("argument error: NULL pointer\n");
        return (VMF_ERR_NULL_POINTER);
    }

    if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        if (0==vmf_client_id)
        {
            NW_VMF_CLIB_DEBUG_ERROR("error - client not connected\n");
        }
        else
        {
            NW_VMF_CLIB_DEBUG_ERROR("argument error: not yet assigned vmf_client_id=%d\n",vmf_client_id);
        }
        return (VMF_ERR_OUT_OF_RANGE);
    }

    /* check size of message */
    if (p_vmf_msg->pl_len > MAX_VMF_DATA_LEN)
    {
        /* message to long */
        NW_VMF_CLIB_DEBUG_ERROR("to much data=%d bytes, allowed size =%d\n",p_vmf_msg->pl_len,MAX_VMF_DATA_LEN);
        return VMF_ERR_TO_MUCH_DATA;
    }

    /* prepare BASIC message */
    p_vmf_msg->msg_type  = SVMF_BASIC_MSG;
    p_vmf_msg->pid       = cid_tab.my_cid[vmf_client_id].pid;
    p_vmf_msg->cid       = vmf_client_id;
    {
        unsigned32 ctime = nw_os_cfg_get_ms_time();
        p_vmf_msg->msg_time    = ctime & 0xffff;
        p_vmf_msg->msg_time_hh = (ctime >> 16) & 0xff;
    }
    /* calculate 'real' size of the BASIC message */
    u_len = VMF_MSG_LEN(p_vmf_msg->pl_len);

    /* send message to ipc */
    vmf_ret = nw_vmf_ipc_send(nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab),(unsigned8*)p_vmf_msg, u_len);
    if (VMF_OK != vmf_ret)
    {
        NW_VMF_CLIB_DEBUG_ERROR("cid=%d, nw_vmf_ipc_send() failed\n",vmf_client_id);
    }
    else
    {
        NW_VMF_CLIB_DEBUG_INFO("cid=%d, nw_vmf_ipc_send(%d bytes) OK",vmf_client_id,u_len);
    }

    return (vmf_ret);
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
        NW_VMF_CLIB_DEBUG_ERROR("argument error: NULL pointer");
        return (VMF_ERR_NULL_POINTER);
    }

    if (0 == len)
    {
        NW_VMF_CLIB_DEBUG_ERROR("argument error: len = 0");
        return (VMF_ERR_OUT_OF_RANGE);
    }

    if ((vmf_trace_tx_cid >= MAX_CID) || (vmf_trace_tx_cid < INITAL_CID_VALUE ))
    {
        if (0==vmf_trace_tx_cid)
        {
            NW_VMF_CLIB_DEBUG_ERROR("client not connected");
        }
        else
        {
            NW_VMF_CLIB_DEBUG_ERROR("argument error: invalid vmf_client_id=%d",vmf_trace_tx_cid);
        }
        return (VMF_ERR_OUT_OF_RANGE);
    }

    /* transfer the message */
    vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_trace_tx_cid,&cid_tab),(unsigned8*)pbuffer,len);
    if (VMF_OK != vmf_ret)
    {
        NW_VMF_CLIB_DEBUG_ERROR("nw_vmf_ipc_send() failed\n");
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
    vmf_ret_t       vmf_ret=VMF_OK;
    unsigned16      uReadSize=0;


    NW_VMF_CLIB_DEBUG_INFO("");

    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_VMF_CLIB_DEBUG_ERROR("argument error: NULL pointer");
        return (VMF_ERR_NULL_POINTER);
    }

    if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        NW_VMF_CLIB_DEBUG_ERROR("invalid vmf_client_id=%d",vmf_client_id);
        delay(10);                      /* to allow killing the process*/
        return (VMF_ERR_OUT_OF_RANGE);
    }

    vmf_ret = nw_vmf_ipc_receive (nw_vmf_client_get_rx_hdl(vmf_client_id,&cid_tab),
                                  vmf_buffer_length,(unsigned8 *)p_vmf_msg,&uReadSize);
    if ( vmf_ret < 0)
    {
        NW_VMF_CLIB_DEBUG_ERROR("nw_vmf_ipc_timed_receive() failed error = %d",vmf_ret);
        uReadSize = uReadSize; /* debug */
    }
    else
    {
        /* reception was ok */
        /* return numbe of received bytes */
        #ifdef DO_CLIENT_DEBUG_HEX
               // nw_con_HexDump("vmf-client-lib: nw_vmf_receive() raw-rx-data=", (unsigned8 *)p_vmf_msg, uReadSize);
        #endif
        vmf_ret = uReadSize;
    }
    return(vmf_ret);
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
    vmf_ret_t       vmf_ret=VMF_OK;
    unsigned16      uReadSize=0;

    NW_VMF_CLIB_DEBUG_INFO("");

    /* argument check */
    if (NULL == p_vmf_msg)
    {
        NW_VMF_CLIB_DEBUG_ERROR("argument error: NULL pointer");
        return (VMF_ERR_NULL_POINTER);
    }

    if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        NW_VMF_CLIB_DEBUG_ERROR("invalid vmf_client_id=%d",vmf_client_id);
        delay(10);                      /* to allow killing the process*/
        return (VMF_ERR_OUT_OF_RANGE);
    }

    /* check if there are messages in the collector buffer */
    vmf_ret = nw_vmf_ipc_timed_receive (nw_vmf_client_get_rx_hdl(vmf_client_id,&cid_tab),
                                        vmf_buffer_length,(unsigned8 *)p_vmf_msg,&uReadSize,ms_timeout);
    if ( vmf_ret < 0)
    {
        NW_VMF_CLIB_DEBUG_ERROR("nw_vmf_ipc_timed_receive() failed error = %d",vmf_ret);
        uReadSize = 0;
    }
    else
    {
        /* reception was ok */
        /* return numbe of received bytes */
        #ifdef DO_CLIENT_DEBUG_HEX
               // nw_con_HexDump("vmf-client-lib: nw_vmf_receive() raw-rx-data=", (unsigned8 *)p_vmf_msg, uReadSize);
        #endif
        vmf_ret = uReadSize;
    }
    return(vmf_ret);
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
    vmf_ret_t                       vmf_ret;
    VMF_VAR_MSG_TYP(MAX_GROUP_NUM)  myCtrlConMsg;

    NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_register_msg_group()");

    /* argument check */
    if (NULL == groupList)
    {
        NW_VMF_CLIB_DEBUG_ERROR("argument error: NULL pointer");
        return (VMF_ERR_NULL_POINTER);
    }

    if (groups_num > MAX_GROUP_NUM)
    {
        NW_VMF_CLIB_DEBUG_ERROR("argument error: groups_num > MAX_GROUP_NUM");
        return (VMF_ERR_OUT_OF_RANGE);
    }

    if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        NW_VMF_CLIB_DEBUG_ERROR("argument error: invalid vmf_client_id=%d",vmf_client_id);
        return (VMF_ERR_OUT_OF_RANGE);
    }

    /* prepare and send register msg group control message */
    myCtrlConMsg.msg_type  = VMF_CTRL_MSG;
    myCtrlConMsg.ctrl_type = VMF_CTRL_REGISTER_MSG_GRP;
    myCtrlConMsg.pid       = cid_tab.my_cid[vmf_client_id].pid;
    myCtrlConMsg.cid       = vmf_client_id;
    myCtrlConMsg.pl_len    = groups_num;
    {
        unsigned32 ctime = nw_os_cfg_get_ms_time();
        myCtrlConMsg.msg_time    = ctime & 0xffff;
        myCtrlConMsg.msg_time_hh = (ctime >> 16) & 0xff;
    }

    /* copy groups to payload */
    if ((groups_num > 0) && (groupList != NULL))
    {
        NW_MEMCOPY(myCtrlConMsg.pl,groupList,groups_num);
    }

    /* transfer control message */
    vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab), (unsigned8*)&myCtrlConMsg, sizeof(myCtrlConMsg));
    if (VMF_OK != vmf_ret)
    {
        NW_VMF_CLIB_DEBUG_ERROR("nw_vmf_ipc_send() failed");
    }
    nw_sleep_ms(0);
    return (vmf_ret);
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_de_register_msg_group (vmf_client_id_t vmf_client_id
 *                                             unsigned16 groups_num,unsigned8 * groupList)
 *
 *   Description:   deregister message groups
 *
 *   Parameters:    vmf_client_id       (input)connection client id
 *                  groups_num          (input)number of groups in List
 *                  *groupList          (input)pointer to a list of message groups
 *
 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_de_register_msg_group (vmf_client_id_t vmf_client_id, /**<INPUT connection client id*/
                                     unsigned16 groups_num,         /**<INPUT number of groups in List*/
                                     unsigned8 * groupList)         /**<INPUT pointer ro a list of message groups*/
{
    vmf_ret_t                       vmf_ret;
    VMF_VAR_MSG_TYP(MAX_GROUP_NUM)  myCtrlConMsg;

    NW_VMF_CLIB_DEBUG_INFO("vmf-client-lib: nw_vmf_register_msg_group()");

    /* argument check */
    if (NULL == groupList)
    {
        NW_VMF_CLIB_DEBUG_ERROR("argument error: NULL pointer");
        return (VMF_ERR_NULL_POINTER);
    }

    if (groups_num > MAX_GROUP_NUM)
    {
        NW_VMF_CLIB_DEBUG_ERROR("argument error: groups_num > MAX_GROUP_NUM");
        return (VMF_ERR_OUT_OF_RANGE);
    }

    if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        NW_VMF_CLIB_DEBUG_ERROR("argument error: invalid vmf_client_id=%d",vmf_client_id);
        return (VMF_ERR_OUT_OF_RANGE);
    }

    /* prepare and send deregister msg group message */
    myCtrlConMsg.msg_type  = VMF_CTRL_MSG;
    myCtrlConMsg.ctrl_type = VMF_CTRL_DEREGISTER_MSG_GRP;
    myCtrlConMsg.pid       = cid_tab.my_cid[vmf_client_id].pid;
    myCtrlConMsg.cid       = vmf_client_id;
    myCtrlConMsg.pl_len    = groups_num;
    {
        unsigned32 ctime = nw_os_cfg_get_ms_time();
        myCtrlConMsg.msg_time    = ctime & 0xffff;
        myCtrlConMsg.msg_time_hh = (ctime >> 16) & 0xff;
    }

    /* copy groups to payload */
    if ((groups_num > 0) && (groupList != NULL))
    {
        NW_MEMCOPY(myCtrlConMsg.pl,groupList,groups_num);
    }

    /* transfer control message */
    vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab), (unsigned8*)&myCtrlConMsg, VMF_MSG_LEN(groups_num));
    if (VMF_OK != vmf_ret)
    {
        NW_VMF_CLIB_DEBUG_ERROR("nw_vmf_ipc_send() failed");
    }
    nw_sleep_ms(0);
    return (vmf_ret);
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
    vmf_msg_min_t   myCtrlConMsg;

    /* argument check */
    if ((vmf_client_id >= MAX_CID)  || (vmf_client_id < INITAL_CID_VALUE))
    {
        NW_VMF_CLIB_DEBUG_ERROR("argument error: invalid vmf_client_id=%d\n",vmf_client_id);
        return (VMF_ERR_OUT_OF_RANGE);
    }

    /* prepare and send register spy control message */
    myCtrlConMsg.msg_type   = VMF_CTRL_MSG;
    myCtrlConMsg.ctrl_type  = VMF_CTRL_REGISTER_SPY;
    myCtrlConMsg.pid        = cid_tab.my_cid[vmf_client_id].pid;
    myCtrlConMsg.cid        = vmf_client_id;
    {
        unsigned32 ctime = nw_os_cfg_get_ms_time();
        myCtrlConMsg.msg_time    = ctime & 0xffff;
        myCtrlConMsg.msg_time_hh = (ctime >> 16) & 0xff;
    }


    vmf_ret = nw_vmf_ipc_send (nw_vmf_client_get_tx_hdl(vmf_client_id,&cid_tab), (unsigned8*)&myCtrlConMsg, sizeof(myCtrlConMsg));
    if (VMF_OK != vmf_ret)
    {
        NW_VMF_CLIB_DEBUG_ERROR("nw_vmf_ipc_send() failed\n");
    }
    nw_sleep_ms(0);
    return (vmf_ret);
}


/******************************************************************************/
/*                          static functions                                  */
/******************************************************************************/


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

    NW_VMF_CLIB_DEBUG_INFO("");

    if (cid_tab_init_done)
    {
        /* cid-tab already initialized */
        NW_VMF_CLIB_DEBUG_WARNING("already called");
        return;
    }

    (void)memset(pcid_tab,0,sizeof(my_cid_tab_t));

    /* mhammer3, tms 85418, cid must not be 0*/
    pcid_tab->free_cid=INITAL_CID_VALUE;

    /* delete name, list and vmf_handles */
    for (u8Cnt = 0; u8Cnt < MAX_SERVER_CONNECTIONS; u8Cnt++)
    {
        pcid_tab->my_cid[u8Cnt].in_use = FALSE;
        pcid_tab->my_cid[u8Cnt].my_channel_name[0]=0;
        pcid_tab->my_cid[u8Cnt].tx_handle = VMF_HANDLE_INVALID;
        pcid_tab->my_cid[u8Cnt].rx_handle = VMF_HANDLE_INVALID;
        pcid_tab->my_cid[u8Cnt].pid =0;

    }
    cid_tab_init_done = TRUE;
    NW_VMF_CLIB_DEBUG_INFO("done");
}




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
static vmf_client_id_t nw_vmf_client_get_free_cid (my_cid_tab_t *pcid_tab)  /**< INPUT pointer to cid table*/
{
    vmf_client_id_t free_cid;
    unsigned8       u8Cnt;

    NW_VMF_CLIB_DEBUG_INFO("");
    free_cid = MAX_SERVER_CONNECTIONS;
    {
        /* try to find a freed cid */
        for (u8Cnt = INITAL_CID_VALUE; u8Cnt < MAX_SERVER_CONNECTIONS; u8Cnt++)
        {
            if (FALSE == pcid_tab->my_cid[u8Cnt].in_use)
            {
                /* found free cid */
                free_cid = u8Cnt;
                pcid_tab->my_cid[(unsigned8)free_cid].pid = getmypid();
                break;
            }
        }
    }

    NW_VMF_CLIB_DEBUG_INFO("return = %d",free_cid);
    return (free_cid);
}

/**************************************************************************//**
 *
 *   Function Name:  nw_vmf_register_client  (const char *my_channel_name,
 *                                            vmf_handle_t tx_handle,
 *                                            vmf_handle_t p2p_handle,
 *                                            vmf_handle_t rx_handle,
 *                                            my_cid_tab_t *pcid_tab,
 *
 *                                            )
 *
 *   Description:   register a new client to the client tab
 *
 *
 *   Parameters:    vmf_client_id        (input)client id
 *                   my_channel_name     (input)pointer to channel name or NULL
 *                  tx_handle            (input)transmit handle
 *                  rx_handle            (input)receive handle
 *                  pcid_tab             (input)pointer to cid table

 *   Return value:  \return vmf_ret_t error type
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_register_client (vmf_client_id_t vmf_client_id,                               /**< INPUT client id*/
                                         const char *my_channel_name,                                 /**< INPUT pointer to channel name or NULL*/
                                         vmf_handle_t tx_handle,                                      /**< INPUT transmit handle*/
                                         vmf_handle_t rx_handle,                                      /**< INPUT receive handle*/
                                         my_cid_tab_t *pcid_tab)                                      /**< INPUT pointer to cid table*/

{
    NW_VMF_CLIB_DEBUG_INFO("my_channel_name=%s, rx_handle=%d, tx_handle=%d\n",my_channel_name,rx_handle,tx_handle);

    if (vmf_client_id >= MAX_SERVER_CONNECTIONS)
    {
        NW_VMF_CLIB_DEBUG_ERROR("vmf_client_id >= MAX_SERVER_CONNECTIONS");
        return (vmf_client_id_t)VMF_ERROR;
    }

    /* mark entry as in-use */
    pcid_tab->my_cid[(unsigned8)vmf_client_id].in_use = TRUE;

    /* copy name */
    if (my_channel_name != NULL)
    {
        strncpy((pcid_tab->my_cid[(unsigned8)vmf_client_id].my_channel_name),my_channel_name,MAX_NAME_LEN-1);
    }

    /* copy handles */
    pcid_tab->my_cid[(unsigned8)vmf_client_id].tx_handle = tx_handle;
    pcid_tab->my_cid[(unsigned8)vmf_client_id].rx_handle = rx_handle;


    NW_VMF_CLIB_DEBUG_INFO("pid = %d",pcid_tab->my_cid[(unsigned8)vmf_client_id].pid);
    /* move to next free cid (if not already there) */
    if (pcid_tab->free_cid < MAX_SERVER_CONNECTIONS)
    {
        pcid_tab->free_cid++;
    }
    return (VMF_OK);
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
static vmf_handle_t nw_vmf_client_get_tx_hdl (vmf_client_id_t vmf_client_id, /**< connection id */
                                              my_cid_tab_t *pcid_tab)        /** <INPUT pointer to cid table */
{
    return pcid_tab->my_cid[(unsigned8)vmf_client_id].tx_handle;
}




/*************************************************************************//**
 *
 *   init a mutex. \n
  *
 *   \param         pointer to mutex struct
 *   \return        true if OK
 *
 ******************************************************************************/
static BOOL vmf_mutex_init(MUTEX_STRUCT *pmutex)
{
            BOOL    bRet = TRUE;
    static  BOOL    inUse = FALSE;

    NW_VMF_CLIB_DEBUG_INFO("");

    while(inUse)
    {
        nw_sleep_ms(0);
    }
    inUse = TRUE;

    if (_mutex_init(pmutex, NULL) != MQX_OK)
    {
        bRet = FALSE;
        NW_VMF_CLIB_DEBUG_ERROR("_mutex_init() failed");
    }

    inUse = FALSE;
    return bRet;
}

/*************************************************************************//**
 *
 *   lock a mutex. \n
  *
 *   \param         pointer to mutex struct
 *   \return        true if OK
 *
 ******************************************************************************/
static BOOL vmf_mutex_lock(MUTEX_STRUCT *pmutex)
{
    DWORD result;
    _mqx_uint ret_val;

    NW_VMF_CLIB_DEBUG_INFO("");

    ret_val = _mutex_lock(pmutex);
    if (ret_val != MQX_EOK)
    {
        NW_VMF_CLIB_DEBUG_ERROR("_mutex_lock() failed, retval=%d",ret_val);
        return FALSE;
    }

    return TRUE;
}


/*************************************************************************//**
 *
 *   lock a mutex. \n
 *
 *   \param         pointer to mutex struct
 *   \return        true if OK
 *
 ******************************************************************************/
static BOOL vmf_mutex_release(MUTEX_STRUCT *pmutex)
{
    _mqx_uint ret_val;
    NW_VMF_CLIB_DEBUG_INFO("");

    ret_val = _mutex_unlock(pmutex);
    if (ret_val != MQX_EOK)
    {
        NW_VMF_CLIB_DEBUG_ERROR("_mutex_unlock() failed, retval=%d",ret_val);
        return FALSE;
    }

    return TRUE;
}


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
static  vmf_handle_t nw_vmf_client_get_rx_hdl (vmf_client_id_t vmf_client_id,    /**< connection id */
                                              my_cid_tab_t *pcid_tab)           /**< INPUT pointer to cid table */
{
    return pcid_tab->my_cid[(unsigned8)vmf_client_id].rx_handle;
}

