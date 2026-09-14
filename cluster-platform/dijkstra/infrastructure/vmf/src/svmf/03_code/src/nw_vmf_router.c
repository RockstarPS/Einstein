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

#define NW_STATIC static


#include "vmf.h"
#include "vmf_ipc.h"
#include "nw_vmf_debug.h"
#include "nw_vmf_routing_db.h"
#include "nw_vmf_routing_db-private.h"
#include "nw_vmf_router.h"

/* WARNING!!! */
/* Do NOT activate VMF Trace macros -- DEADLOCKS can occur!!! */
#define VMF_ROUTER_TRACE_PRINT(a,b,c,d,e)                   		// fprintf (ERROR_CHANNEL,"router: %s - %s",d,e);fprintf (ERROR_CHANNEL,"\n")  /* VMF_TRACE_PRINT(a,b,c,d,e) */
#define VMF_ROUTER_TRACE_PRINTF(a,b,c,d,e,...)          			// fprintf (ERROR_CHANNEL,"router: %s - ",d);fprintf (ERROR_CHANNEL,e,__VA_ARGS__);fprintf (ERROR_CHANNEL,"\n") /* VMF_TRACE_PRINTF(a,b,c,d,e,__VA_ARGS__) */
#define VMF_ROUTER_TRACE_PRINTF_ALWAYS_ENABLED(a,b,c,d,e,...)       //  fprintf (ERROR_CHANNEL,"router: %s - ",d);fprintf (ERROR_CHANNEL,e,__VA_ARGS__);fprintf (ERROR_CHANNEL,"\n") /* VMF_TRACE_PRINTF(a,b,c,d,e,__VA_ARGS__) */

#define VMF_TRACE_SCOPE      			(char *)__PRETTY_FUNCTION__
#define VMF_DEBUG_PRINT(scope, ...)   								// VMF_TRACE_PRINTF(vmf_trace_svr_trid, 50, scope, VMF_TRACE_SCOPE, __VA_ARGS__);


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

/*! Type for the router handle database used for message distribution. The logical handle is used as index */
typedef struct
{
    unsigned8           status;                                 /*!< Status of the channel (see nw_vmf_handle_status_values_enum). */
    pid_t               pid;                                    /*!< Client process ID */
    vmf_client_id_t     cid;                                    /*!< Client ID */
    char                name[MAX_NAME_LEN];             		/*!< Name of this connection ( process,connection name ) */
    char                zero;                                   /*!< name string is always zero terminated */
}handles_db_t;

#pragma pack(push,4)
/* load response version 0 */
typedef struct
{
    unsigned32  pid;                                            /* process id - (ll,lh,hl,hh  */
    unsigned8   cid;                                            /* cid */
    unsigned8   name_len;                                       /* size of name */
    char        name[MAX_NAME_LEN];                     		/* name */
    char        zero;                                           /*!< name string is always zero terminated */
}vmf_connection_name_resp_pl_t;
#pragma pack(pop)


/* global data */
// static unsigned8   vmf_trace_svr_trid=0;

/* static data */
NW_STATIC  vmf_handle_t    server_channel_handle = VMF_HANDLE_INVALID;      /*!< Logical handle of the server receive message queue */
NW_STATIC  vmf_handle_t    spy_channel_handle = VMF_HANDLE_INVALID;         /*!< Spy handle -- ONLY 1 SPY ALLOWED FOR SVMF */
NW_STATIC  handles_db_t    handle_db[MAX_IPC_CHANNELS];                     /*!< Client connection information storage */
NW_STATIC  unsigned8       last_handle;                                     /*!< Identifies the last valid entry of the handle_db */

/* local prototypes */
NW_STATIC vmf_ret_t nw_vmf_init_router (void);
NW_STATIC vmf_ret_t nw_vmf_router_eval_message (unsigned8 *message_buffer);
NW_STATIC vmf_ret_t nw_vmf_router_connect_client (vmf_msg_t *message);
NW_STATIC vmf_ret_t nw_vmf_router_disconnect_client (vmf_msg_t *message);
NW_STATIC vmf_ret_t nw_vmf_router_register_basic_msg_groups (vmf_msg_t *message);
NW_STATIC vmf_ret_t nw_vmf_router_de_register_basic_msg_groups (vmf_msg_t *message);
NW_STATIC vmf_ret_t nw_vmf_router_register_spy (vmf_msg_t *message);
NW_STATIC vmf_ret_t nw_vmf_router_de_register_spy (vmf_msg_t *message);
NW_STATIC vmf_ret_t nw_vmf_router_handle_basic_msg (vmf_msg_t *message);
NW_STATIC vmf_ret_t nw_vmf_router_basic_msg_broadcast (vmf_msg_t *message);
NW_STATIC vmf_ret_t nw_vmf_router_msg_send (vmf_handle_t client_handle, unsigned8 *message, unsigned16 msg_size);
NW_STATIC vmf_ret_t nw_vmf_router_msg_distribute (unsigned8 last_handle, vmf_handle_t *handle_list, vmf_msg_t *message);
NW_STATIC vmf_ret_t nw_vmf_router_msg_send_spy(vmf_msg_t *message);
NW_STATIC vmf_handle_t nw_vmf_router_get_client_handle (pid_t pid, vmf_client_id_t cid);
NW_STATIC vmf_ret_t nw_vmf_router_handle_db_add (vmf_handle_t vmf_handle, pid_t pid, vmf_client_id_t cid, char *name,unsigned16 len);
NW_STATIC vmf_ret_t nw_vmf_router_handle_db_remove (vmf_handle_t vmf_handle);
NW_STATIC vmf_ret_t nw_vmf_send_connection_name (vmf_handle_t tx_handle,vmf_handle_t client_handle);
NW_STATIC vmf_ret_t nw_vmf_send_connection_names (vmf_handle_t tx_handle);
NW_STATIC vmf_ret_t nw_vmf_send_vmf_connection_name (vmf_handle_t tx_handle);



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
void nw_vmf_router (uint32_t param)
{
    vmf_ret_t   eval_ret;
    bool        do_the_loop = true;

    /* do the initializations */
    if(VMF_OK != nw_vmf_init_router())
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_router: router initialization failed!");
        return;
    }

    VMF_ROUTER_TRACE_PRINT(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router","nw_vmf_init_router() done");

    /* receive in the loop */
    while (do_the_loop)
    {
        {
            unsigned16  message_length;

            /* IMPORTANT: move message_buffer to a even 32Bit address */
            static unsigned32   message_buffer[(VMF_MAX_MSG_LEN / sizeof(unsigned32))+1];
            VMF_ROUTER_TRACE_PRINT(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router","call receive");

            if (VMF_OK != nw_vmf_ipc_timed_receive( server_channel_handle, VMF_MAX_MSG_LEN, (unsigned8 *)message_buffer, &message_length,100))
            {
                // VMF_ROUTER_TRACE_PRINT(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router","receive failed");
                nw_sleep_ms(1);
            }
            else
            {
                VMF_ROUTER_TRACE_PRINT(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router","receive done - len=%d",message_length);

                if (0 == message_length)
                {
                    /* ignore zero message */
                    continue;
                }

                /* initialize client_count (number of receive clients) */
                ((vmf_msg_t*)message_buffer)->client_count = 0;

                /* evaluate the received message */
                eval_ret = nw_vmf_router_eval_message((unsigned8 *)message_buffer);
                if (VMF_OK != eval_ret)
                {
                    VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_WARNING_10,"vmf_server","nw_vmf_router","eval message returned error: %d",eval_ret);
                }
            }
        }
    }

    return;
}

/***************************************************************************//**
 *
 *   Initialize global data and open the server message channel.
 *
 *   \param         none
 *   \return        vmf return type
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t nw_vmf_init_router (void)
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
        handle_db[(unsigned8)i].name[0]=0;
        handle_db[(unsigned8)i].zero=0;
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
        server_channel_handle = nw_vmf_ipc_create(VMF_IPC_SERVER_NAME, VMF_IPC_QUEUE_SIZE_SERVER, VMF_MAX_MSG_LEN);
        nw_sleep_ms(1);
    }

    handle_db[(unsigned8)server_channel_handle].status = NW_VMF_HANDLE_SERVER;

    VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router","nw_vmf_init_router - server channel handle == %d\n", server_channel_handle);
    // (void)vmf_trace_register(&vmf_trace_svr_trid,"vmf-router");

    return ret_val;
}

/**************************************************************************//**
 *
 *   Dependend on the message type each function is forwarded to
 *   the appropriate message handler.
 *
 *   \param[in]     message_buffer      pointer to the received message (still serial)
 *   \param[in]     message_length      length of the received message
 *   \return        vmf return type
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t nw_vmf_router_eval_message (unsigned8 *message_buffer)
{
    vmf_ret_t       ret_val = VMF_OK;
    unsigned8       msg_type;
    unsigned8       ctrl_type;

    if (NULL == message_buffer)
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_eval_message","message_buffer == NULL");
        return (vmf_ret_t)VMF_ERR_NULL_POINTER;
    }
    

    /* evaluate the incoming message dependent on the message type */
    msg_type = NW_VMF_MSG_TYPE(((vmf_msg_t*)message_buffer));

    if (SVMF_BASIC_MSG == msg_type)
    {
        ret_val = nw_vmf_router_handle_basic_msg ((vmf_msg_t *)message_buffer);
    }
    else if (VMF_CTRL_MSG == msg_type)
    {
        ctrl_type = ((vmf_msg_t *)message_buffer)->ctrl_type;

        switch (ctrl_type)
        {

            case VMF_CTRL_CONNECT:
                ret_val = nw_vmf_router_connect_client((vmf_msg_t *)message_buffer);
            break;

            case VMF_CTRL_REGISTER_MSG_GRP:
                ret_val = nw_vmf_router_register_basic_msg_groups((vmf_msg_t *)message_buffer);
            break;

            case VMF_CTRL_DEREGISTER_MSG_GRP:
                ret_val = nw_vmf_router_de_register_basic_msg_groups ((vmf_msg_t *)message_buffer);
            break;

            case VMF_CTRL_DISCONNECT:
                ret_val = nw_vmf_router_disconnect_client((vmf_msg_t *)message_buffer);
            break;

            case VMF_CTRL_REGISTER_SPY:
                ret_val = nw_vmf_router_register_spy ((vmf_msg_t *)message_buffer);
            break;

            default:
                /* unknown message type */
                ret_val = VMF_ERR_ROUTER_UNKNOWN_MESSAGE;
                VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_WARNING_10,"vmf_server","nw_vmf_router_eval_message","unknown message type = %d",msg_type);
            break;
        }

    }
    else
    {
        /* unknown message type */
        ret_val = VMF_ERR_ROUTER_UNKNOWN_MESSAGE;
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_WARNING_10,"vmf_server","nw_vmf_router_eval_message","unknown message type = %d",msg_type);
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
NW_STATIC vmf_ret_t nw_vmf_router_connect_client(vmf_msg_t *message)
{
    vmf_ret_t       ret_val = VMF_OK;
    char            channel_name[MAX_NAME_LEN];
    vmf_handle_t    vmf_handle;

    if (NULL == message)
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_connect_client","message == NULL");
        return (vmf_ret_t)VMF_ERR_NULL_POINTER;
    }

    if (VMF_OK != nw_vmf_ipc_create_channel_name(message->pid, message->cid, channel_name, sizeof(channel_name)))
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_11,"vmf_server","nw_vmf_router_connect_client","cannot create channel_name pid=%d, cid=%d",message->pid, message->cid);
        return VMF_ERR_ROUTER_CLIENT_CONNECT_FAILED;
    }

    vmf_handle = nw_vmf_ipc_open(channel_name, IPC_NON_BLOCKING);
    if ((VMF_HANDLE_INVALID == vmf_handle) || (vmf_handle < 0))
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_11,"vmf_server","nw_vmf_router_connect_client","cannot open IPC %s",channel_name);
        return VMF_ERR_ROUTER_CLIENT_CONNECT_FAILED;
    }

    if (VMF_OK != nw_vmf_router_handle_db_add(vmf_handle, message->pid, message->cid, (char *)(NW_VMF_MSG_DATA_PTR(message)),NW_VMF_MSG_DATA_LENGTH(message)))
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
        return VMF_ERR_ROUTER_CLIENT_CONNECT_FAILED;
    }

    VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router_connect_client","channel name == %s, channel handle == %d",channel_name, vmf_handle);
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
NW_STATIC vmf_ret_t nw_vmf_router_disconnect_client (vmf_msg_t *message)
{
    vmf_ret_t       ret_val = VMF_OK;
    vmf_handle_t    vmf_handle;

    if (NULL == message)
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_disconnect_client","message == NULL");
        return (vmf_ret_t)VMF_ERR_NULL_POINTER;
    }

    ret_val = nw_vmf_router_get_client_handle(message->pid, message->cid);

    if (VMF_HANDLE_INVALID == ret_val)
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_disconnect_client","cannot get vmf handle, error code =%d, pid=%d, cid=%d",ret_val,message->pid, message->cid);
        return (VMF_ERR_ROUTER_SENDER_HANDLE_NOT_FOUND);
    }
    else
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router_disconnect_client","vmf handle =%d, pid=%d, cid=%d",ret_val,message->pid, message->cid);
    }

    /* close the channel */
    vmf_handle = (vmf_handle_t)ret_val;

    // NW_VMF_DEBUG_INFO("nw_vmf_router_disconnect_client vmf_handlevmf_handle=%d, spy_channel_handle=%d\n",vmf_handle,spy_channel_handle);


    (void)nw_vmf_ipc_destroy(vmf_handle);               /* free all used buffers */
    ret_val = nw_vmf_ipc_close(vmf_handle);
    if (VMF_OK != ret_val)
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_disconnect_client","cannot close channel: vmf_handle=%x",vmf_handle);
        return ret_val;
    }

    /* remove all entries from this client in VMF database */
    __nw_vmf_routing_db_remove_handle(vmf_handle);

    /* remove handle from handle database */
    ret_val = nw_vmf_router_handle_db_remove(vmf_handle);
    if (VMF_OK != ret_val)
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_disconnect_client","cannot remove handle from database: vmf_handle=%x",vmf_handle);
    }

    VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_INFO_15,"vmf_server","nw_vmf_router_disconnect_client","nw_vmf_router_disconnect_client: OK - vmf_handle = %d",vmf_handle);

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
NW_STATIC vmf_ret_t nw_vmf_router_register_basic_msg_groups (vmf_msg_t *message)
{
    vmf_ret_t       ret_val = VMF_OK;
    vmf_ret_t       ret_val_get_handle;
    vmf_handle_t    sender;
    vmf_ret_t       ret_reg;
    unsigned16      i;
    

    if (NULL == message)
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_register_basic_msg_groups","message == NULL");
        return (vmf_ret_t)VMF_ERR_NULL_POINTER;
    }

    ret_val_get_handle = nw_vmf_router_get_client_handle(message->pid, message->cid);
    if (VMF_HANDLE_INVALID == ret_val)
    {
        ret_val = VMF_ERR_ROUTER_SENDER_HANDLE_NOT_FOUND;
    }
    else
    {
        /* return value of nw_vmf_router_get_client_handle is sender handle */
        sender = ret_val_get_handle;
        
        /* payload length == unsigned16 groups_num, payload == unsigned8 group_list[] */
        if (message->pl_len > 0 && message->pl_len < MAX_GROUP_NUM)
        {
            for (i=0; i<message->pl_len; i++)
            {
                ret_reg = nw_vmf_routing_db_event_register(sender, message->pl[i]);
                if(VMF_OK != ret_reg)
                {
                    VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_register_basic_msg_groups","nw_vmf_routing_db_event_register failed err=%d",ret_reg);
                    ret_val = VMF_ERR_ROUTER_REGISTRATION_FAILED;
                }
                else
                {
					VMF_ROUTER_TRACE_PRINT(vmf_trid,VMF_TRACE_SEVERITY_INFO_11,"vmf_server","nw_vmf_router_register_basic_msg_groups","sender =%d, group=%d",sender,message->pl[i]);
                }
            }
        }
        else
        {
            ret_val = VMF_ERR_ROUTER_REGISTRATION_FAILED;
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
NW_STATIC vmf_ret_t nw_vmf_router_de_register_basic_msg_groups (vmf_msg_t *message)
{
    vmf_ret_t   ret_val = VMF_OK;

    if (NULL == message)
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_de_register_basic_msg_groups","message == NULL");
        return (vmf_ret_t)VMF_ERR_NULL_POINTER;
    }


    return ret_val;
}


/***************************************************************************//**
 *
 *   Register this client as message spy
 *
 *   \param[in]     message -- pointer to a message containing registration data
 *   \return        vmf return
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t nw_vmf_router_register_spy (vmf_msg_t *message)
{
    vmf_ret_t       ret_val = VMF_OK;
    vmf_handle_t    ret_val_get_handle;

    if (NULL == message)
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_register_spy","message == NULL");
        return (vmf_ret_t)VMF_ERR_NULL_POINTER;
    }

    ret_val_get_handle = nw_vmf_router_get_client_handle(message->pid, message->cid);
    if (VMF_HANDLE_INVALID == ret_val_get_handle)
    {
        VMF_ROUTER_TRACE_PRINT(vmf_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_server","nw_vmf_router_register_spy","register spy failed");
        ret_val = VMF_ERR_ROUTER_REGISTER_SPY_FAILED;
    }
    else
    {
        /* register spy */
        spy_channel_handle = ret_val_get_handle;
		(void)nw_vmf_send_connection_names(spy_channel_handle);
    }

    return ret_val;
}


/***************************************************************************//**
 *
 *   De-register this client as message spy
 *
 *   \param[in]     message -- pointer to a message containing registration data
 *   \return        vmf return
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t nw_vmf_router_de_register_spy (vmf_msg_t *message)
{
    vmf_ret_t       ret_val = VMF_OK;
    vmf_handle_t    ret_val_get_handle;

    if (NULL == message)
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_de_register_spy","message == NULL");
        return (vmf_ret_t)VMF_ERR_NULL_POINTER;
    }

    ret_val_get_handle = nw_vmf_router_get_client_handle(message->pid, message->cid);
    if (VMF_HANDLE_INVALID == ret_val_get_handle)
    {
        VMF_ROUTER_TRACE_PRINT(vmf_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_server","nw_vmf_router_de_register_spy","de-register spy failed");
        ret_val = VMF_ERR_ROUTER_REGISTER_SPY_FAILED;
    }
    else
    {
        /* de-register spy */
        if (ret_val_get_handle == spy_channel_handle)
        {
            spy_channel_handle = VMF_HANDLE_INVALID;
        }
    }

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
NW_STATIC vmf_ret_t nw_vmf_router_handle_basic_msg (vmf_msg_t *message)
{
    vmf_ret_t       ret_val = VMF_OK;
    unsigned8       handle_count;
    vmf_handle_t    *handle_list;


    if (NULL == message)
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_handle_basic_msg","message == NULL");
        return (vmf_ret_t)VMF_ERR_NULL_POINTER;
    }

    ret_val = (vmf_ret_t) nw_vmf_routing_db_get_handle_list((vmf_msg_t *)message, &handle_list);
    if (ret_val > 0)
    {
        if (VMF_HANDLE_BROADCAST == handle_list[0])
        {
            /* broadcast message */
            ret_val = nw_vmf_router_basic_msg_broadcast(message);
        }
        else
        {
            /* ret_val is the number of handles */
            handle_count = (unsigned8)ret_val;

            /* send to registered clients */
            ret_val = nw_vmf_router_msg_distribute(handle_count, handle_list, (vmf_msg_t*)message);
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
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_handle_basic_msg","nw_vmf_routing_db_get_handle_list() retunrned error=%d",ret_val);
        ret_val = VMF_ERR_ROUTER_DB_ERROR;
    }

    /* send message to spy (if connected) */
    if (spy_channel_handle != VMF_HANDLE_INVALID)
    {
        if (VMF_OK != nw_vmf_router_msg_send_spy((vmf_msg_t*)message) )
        {
            VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_handle_basic_msg","Send message to spy failed! Error=%d",ret_val);
        }
    }

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
NW_STATIC vmf_ret_t nw_vmf_router_basic_msg_broadcast (vmf_msg_t *message)
{
    vmf_ret_t       ret_val = VMF_OK;
    vmf_ret_t       ret_val_get_handle;
    vmf_handle_t    sender;
    vmf_handle_t    i;
    unsigned16      msg_size;
    unsigned8       client_count=0;

    if (NULL == message)
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_basic_msg_broadcast","message == NULL");
        return (vmf_ret_t)VMF_ERR_NULL_POINTER;
    }

    ret_val_get_handle = nw_vmf_router_get_client_handle(message->pid, message->cid);
    if (VMF_HANDLE_INVALID == ret_val)
    {
        ret_val = VMF_ERR_ROUTER_SENDER_HANDLE_NOT_FOUND;
    }
    else
    {
        /* return value of nw_vmf_router_get_client_handle is sender handle */
        sender = ret_val_get_handle;

        msg_size = VMF_MSG_LEN(message->pl_len);

        for (i=0; i<=last_handle; i++)
        {
            if ((i != sender) && (NW_VMF_HANDLE_STANDARD == handle_db[(unsigned8)i].status))
            {
                if (VMF_ERR_ROUTER_SEND_FAILED == nw_vmf_router_msg_send (i, (unsigned8 *)message, msg_size))
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

    message->client_count = client_count;      /* use client_count to store the number of receive clients */

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
NW_STATIC vmf_ret_t nw_vmf_router_msg_distribute (unsigned8 handle_count, vmf_handle_t *handle_list, vmf_msg_t *message)
{
    vmf_ret_t       ret_val = VMF_OK;
    vmf_handle_t    client_handle;
    unsigned8       i;
    unsigned16      msg_size;
    unsigned8       client_count=0;


    if (NULL == message)
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_msg_distribute","message == NULL");
        return (vmf_ret_t)VMF_ERR_NULL_POINTER;
    }

    if (NULL == handle_list)
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_msg_distribute","handle_list == NULL");
        return (vmf_ret_t)VMF_ERR_NULL_POINTER;
    }

    if (handle_count > MAX_IPC_CHANNELS)
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_msg_distribute","handle_count exceeds max: handle_count = %d", handle_count);
        return (vmf_ret_t)VMF_ERR_OUT_OF_RANGE;
    }
    
    if (SVMF_BASIC_MSG == message->msg_type)
    {
        msg_size = VMF_MSG_LEN(message->pl_len);

        for (i=0; i<handle_count; i++)
        {
            client_handle = handle_list[i];

            if (NW_VMF_HANDLE_STANDARD == handle_db[(unsigned8)client_handle].status)
            {
                if (VMF_ERR_ROUTER_SEND_FAILED == nw_vmf_router_msg_send (client_handle, (unsigned8 *)message, msg_size))
                {
                    ret_val = VMF_ERR_ROUTER_SEND_FAILED;
                }
                else
                {
                    client_count++;
                }
           }
        }
        message->client_count = client_count;     /* use client_count to store the number of receive clients */
    }
    else
    {
        /* This is obviously an ERROR!! */
        ret_val = VMF_ERR_ROUTER_UNKNOWN_MESSAGE;
    }

    return ret_val;
}


/***************************************************************************//**
 *
 *   Distribute the received basic or MOST message to all registered clients.
 *
 *   \param[in]     message       -- pointer to the message to distribute
 *   \return        vmf return type
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t nw_vmf_router_msg_send_spy(vmf_msg_t *message)
{
    vmf_ret_t       ret_val;
    unsigned16      msg_size;

    if (NULL == message)
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_msg_send_spy","message == NULL");
        return (vmf_ret_t)VMF_ERR_NULL_POINTER;
    }

    if (SVMF_BASIC_MSG == message->msg_type)
    {
        msg_size = VMF_MSG_LEN(message->pl_len);
        ret_val = nw_vmf_router_msg_send (spy_channel_handle, (unsigned8 *)message, msg_size);
    }

    return ret_val;
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
NW_STATIC vmf_ret_t nw_vmf_router_msg_send (vmf_handle_t client_handle, unsigned8 *message, unsigned16 msg_size)
{
    vmf_ret_t       ret_val=VMF_OK;

    if (NULL == message)
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_msg_send","message == NULL");
        return (vmf_ret_t)VMF_ERR_NULL_POINTER;
    }

    ret_val = nw_vmf_ipc_send(client_handle, message, msg_size);
    if (VMF_OK != ret_val)
    {
        /* return with ipc error - don't modify ret_val */
        VMF_ROUTER_TRACE_PRINTF_ALWAYS_ENABLED(vmf_trid,VMF_TRACE_SEVERITY_ERROR_19,"vmf_server","nw_vmf_router_msg_send","Client queue overflow! cid=%d, name==%s, send error = %d, msg_size=%d!",client_handle,handle_db[(unsigned8)client_handle].name,(int)ret_val,msg_size);
    }

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
NW_STATIC vmf_ret_t nw_vmf_router_handle_db_add (vmf_handle_t vmf_handle, pid_t pid, vmf_cid_t cid, char *name,unsigned16 len)
{
    vmf_ret_t       ret_val = VMF_OK;

    if (vmf_handle < 0 || vmf_handle > MAX_IPC_CHANNELS)
    {
        VMF_ROUTER_TRACE_PRINTF_ALWAYS_ENABLED(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_handle_db_add","vmf_handle out of range: vmf_handle == %d", vmf_handle);
        return (vmf_ret_t)VMF_ERR_OUT_OF_RANGE;
    }


    /* write data to handle db */
    handle_db[(unsigned8)vmf_handle].status = NW_VMF_HANDLE_STANDARD;
    handle_db[(unsigned8)vmf_handle].pid = pid;
    handle_db[(unsigned8)vmf_handle].cid = cid;
    strncpy(handle_db[(unsigned8)vmf_handle].name,name,MAX_NAME_LEN);
    handle_db[(unsigned8)vmf_handle].name[len]=0;

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
#if 0
    if (spy_channel_handle != VMF_HANDLE_INVALID)
	{
		(void)nw_vmf_send_connection_name(spy_channel_handle,vmf_handle);
	}
#endif

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
NW_STATIC vmf_ret_t nw_vmf_router_handle_db_remove (vmf_handle_t vmf_handle)
{
    vmf_ret_t       ret_val = VMF_OK;
    unsigned8       u8hdl;

    if (vmf_handle < 0 || vmf_handle > MAX_IPC_CHANNELS)
    {
        VMF_ROUTER_TRACE_PRINTF(vmf_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_server","nw_vmf_router_handle_db_remove","vmf_handle out of range: vmf_handle == %d", vmf_handle);
        return (vmf_ret_t)VMF_ERR_OUT_OF_RANGE;
    }

    u8hdl = (unsigned8)vmf_handle;

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
NW_STATIC vmf_handle_t nw_vmf_router_get_client_handle (pid_t pid, vmf_cid_t cid)
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
NW_STATIC vmf_ret_t nw_vmf_send_connection_name (vmf_handle_t tx_handle,vmf_handle_t client_handle)
{
    vmf_ret_t                       ret_val = VMF_OK;
    vmf_connection_name_resp_pl_t   msg;

    if (VMF_HANDLE_INVALID == client_handle)
    {
        /* ignore */
        return ret_val;
    }

    if (handle_db[(unsigned8)client_handle].status != NW_VMF_HANDLE_CLIENT_NOT_CONNECTED)
    {
        if (strlen(handle_db[(unsigned8)client_handle].name) > 0)
        {
            VMF_VAR_MSG_TYP(sizeof(vmf_connection_name_resp_pl_t)) vmf_msg;
            unsigned16  transfer_len=0;

            /* there is a name for this connection */
            /* transfer this message */
            msg.pid = handle_db[(unsigned8)client_handle].pid;
            msg.cid = handle_db[(unsigned8)client_handle].cid;
            msg.name_len = strlen(handle_db[(unsigned8)client_handle].name);
            strncpy(msg.name,handle_db[(unsigned8)client_handle].name,sizeof(msg.name));
            msg.zero = 0;

            /* create a vmf basic message */
            vmf_msg.msg_type  = SVMF_BASIC_MSG;
            vmf_msg.pid       = getmypid();
            vmf_msg.cid    	  = 0;
			{
				unsigned32 ctime = nw_os_cfg_get_ms_time(); 
				vmf_msg.msg_time    = ctime & 0xffff;
				vmf_msg.msg_time_hh = (ctime >> 16) & 0xff;
			}
			vmf_msg.client_count = 1;

			NW_VMF_BASIC_MSG_GROUP(&vmf_msg) = VMF_TRACE_CTRL;
			NW_VMF_BASIC_MSG_EVENT(&vmf_msg) = VMF_TRACE_CTRL_CONNECTION_NAMES;

            /* copy payload */
            NW_VMF_BASIC_MSG_DATA_LENGTH(&vmf_msg) = sizeof(msg) - MAX_NAME_LEN + msg.name_len;
            memcpy(NW_VMF_BASIC_MSG_DATA_PTR(&vmf_msg),&msg, NW_VMF_BASIC_MSG_DATA_LENGTH(&vmf_msg));

            transfer_len = sizeof(vmf_msg);
            ret_val = nw_vmf_router_msg_send (tx_handle,(unsigned8*)&vmf_msg, transfer_len);
			VMF_DEBUG_PRINT("Conn-Name","%s",msg.name);
        }
    }

    return ret_val;
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_send_vmf_connection_name()
 *
 *   Description:   send the vmf connection name name to the spy
 *
 *   \param[in]     txcid       - tx handle
 *   \param[in]     cid         - name of this connection is send
 *   \return        void
 *
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t nw_vmf_send_vmf_connection_name (vmf_handle_t tx_handle)
{
#if ( VS_MICRO_CORE_M4 == VS_MICRO_CORE )	
    #define VMF_CONN_NAME           "VMF-M4,router"
    #define VMF_CONN_NAME_SUFFIX    "router"
#else
    #define VMF_CONN_NAME           "VMF-A5,router"
    #define VMF_CONN_NAME_SUFFIX    "router"
#endif
    vmf_ret_t                       ret_val = VMF_OK;
    vmf_connection_name_resp_pl_t   msg;

    if (VMF_HANDLE_INVALID == tx_handle)
    {
        /* ignore */
        return ret_val;
    }
	else
    {
        {
            static VMF_VAR_MSG_TYP(sizeof(vmf_connection_name_resp_pl_t)) vmf_msg;
            unsigned16  transfer_len=0;

            msg.pid = getmypid();
            msg.cid = 0;
	        strncpy(msg.name,VMF_CONN_NAME,MAX_NAME_LEN);
			msg.name_len = strlen(msg.name);
            msg.zero = 0;

            /* create a vmf basic message */
            vmf_msg.msg_type  = SVMF_BASIC_MSG;
            vmf_msg.pid       = getmypid();
            vmf_msg.cid    	  = 0;
			{
				unsigned32 ctime = nw_os_cfg_get_ms_time(); 
				vmf_msg.msg_time    = ctime & 0xffff;
				vmf_msg.msg_time_hh = (ctime >> 16) & 0xff;
			}
			vmf_msg.client_count = 1;

			NW_VMF_BASIC_MSG_GROUP(&vmf_msg) = VMF_TRACE_CTRL;
			NW_VMF_BASIC_MSG_EVENT(&vmf_msg) = VMF_TRACE_CTRL_CONNECTION_NAMES;

            /* copy payload */
            NW_VMF_BASIC_MSG_DATA_LENGTH(&vmf_msg) = sizeof(msg) - MAX_NAME_LEN + msg.name_len;
            memcpy(NW_VMF_BASIC_MSG_DATA_PTR(&vmf_msg),&msg, NW_VMF_BASIC_MSG_DATA_LENGTH(&vmf_msg));

            transfer_len = sizeof(vmf_msg);
            ret_val = nw_vmf_router_msg_send (tx_handle,(unsigned8*)&vmf_msg, transfer_len);
			VMF_DEBUG_PRINT("Conn-Name","%s",VMF_CONN_NAME);
		}
    }

    return ret_val;
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
NW_STATIC vmf_ret_t nw_vmf_send_connection_names (vmf_handle_t tx_handle)
{
    vmf_handle_t  handle;

    if (VMF_HANDLE_INVALID == tx_handle)
    {
        return VMF_ERR_ROUTER_SENDER_HANDLE_NOT_FOUND;
    }

    /* first send vmf connection name */
   (void)nw_vmf_send_vmf_connection_name (tx_handle);

    /* send all current connections */
    for (handle=0; handle<=last_handle; handle++)
    {
        /* ignore error because this is only a debug function */
        (void)nw_vmf_send_connection_name(tx_handle,handle);
    }

    return VMF_OK;
}




#undef _NW_VMF_ROUTER_C_
