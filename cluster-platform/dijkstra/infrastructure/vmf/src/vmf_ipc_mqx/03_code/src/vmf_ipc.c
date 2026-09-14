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

  \file                 vmf_ipc.c
  \brief                inter process communication

  \author               Joachim Becker
  \author               Visteon Deutschland GmbH, Infotainment Software

  compiler              iar
  target                mqx

  *****************************************************************************/
#define __NW_VMF_IPC_C__
#define MQX_Q_BUG_WORKAROUND			/* there is a bug in the mqx message queue implementation            */
										/* because of the bug the messages can be delivered out of order !!! */


 
#include "vmf_app_util.h"
#include "vmf.h"
#include "vmf_os_config.h"
#include "vmf_ipc.h"


TIME_STRUCT 				mqx_time_s={0};
	


/* debug macros */
#define IPC_ERROR(...)      {printf("error:   ...");printf("%s - ",__func__);printf(__VA_ARGS__);printf("\n");}  
#define IPC_INFO(...)       {printf("info:    ...");printf("%s - ",__func__);printf(__VA_ARGS__);printf("\n");}
#define IPC_WARNING(...)    {printf("warning: ...");printf("%s - ",__func__);printf(__VA_ARGS__);printf("\n");} 

/*! IPC connections information structure */
typedef struct
{
    BOOL                b_inuse;
	BOOL				block_on_send;						/* true if blocking */
	BOOL				block_on_receive;					/* true if blocking */
    char                channel_name[IPC_MAX_NAME_LEN];     /*!< client name received on connection request */
    vmf_pid_t           client_id;                          /*!< client ID received on connection request */
    vmf_pid_t           pid;                                /*!< client process ID received on connection request */
    _pool_id            pool_id;
    _queue_id           q_id;
    _queue_number       q_number;
    unsigned32          async_event;
    vmf_handle_t        owner_hdl;                          /* handle of the owber of the channel */
    unsigned16          msg_size;
}ipc_connection_t;


enum channels
{
    CHANN_SERVER = 0,
    CHANN_TRACER,
    CHANN_FIRST_FREE
};

#define IPC_CHANNELS                   (IPC_ALL_CHANNELS - CHANN_FIRST_FREE)    /*!< number of free IPC connection channels */
#define IPC_MAX_CHANNEL                (IPC_ALL_CHANNELS-1)                     /*!< biggest channel number */

typedef struct
{
    BOOL                init;
//    BOOL                lock;
    MUTEX_STRUCT        mux;
    int                 max;
    ipc_connection_t    conn[IPC_CHANNELS];             /* conn 0 is reserved for the server */
}ipc_connections_t;




/* global data */
ipc_connections_t       ipc_connections={0};
BOOL                    ipc_init_done = FALSE;
BOOL					ipc_preinit_done = FALSE;

/* module private function prototypes*/
vmf_handle_t            vmf_ipc_get_free_ipc_handle(char *channel_name);
static BOOL             vmf_mutex_init(MUTEX_STRUCT *pmutex);
static BOOL             vmf_mutex_lock(MUTEX_STRUCT *pmutex);
static BOOL             vmf_mutex_release(MUTEX_STRUCT *pmutex);
static vmf_handle_t     vmf_get_ipc_hdl(char * channel_name);
static BOOL             vmf_ipc_free_ipc_handle (vmf_handle_t ipc_hdl);
static MSGQ_NOTIFICATION_FPTR vmf_ipc_async_notification(uint_32 *param);


/**************************************************************************//**
 *
 *   pre-init ipc
 *
 *   \param[in]     void     
 *   \return        void  
 ******************************************************************************/
void nw_vmf_ipc_pre_init(void)
{
    BOOL bret;
    IPC_INFO("");
	
	if (TRUE == ipc_preinit_done)
	{
		/* pre-init already done */
		IPC_WARNING("nw_vmf_ipc_pre_init() already called");
		return;
	}
	bret = vmf_mutex_init(&(ipc_connections.mux));

    IPC_INFO("nw_vmf_ipc_pre_init()");
    
	mqx_time_s.SECONDS = 0;
	mqx_time_s.MILLISECONDS =0;
	_time_set(&mqx_time_s); 

    if (FALSE == bret)
    {
        /* report an error */
        IPC_ERROR("vmf_mutex_init() failed");
    }
	else
	{
		ipc_preinit_done = TRUE;
	}
}




/*************************************************************************//**
 *
 *   Initialization of IPC data
 *
 *   \param         none
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_init (BOOL remove_ressources)
{
    int     i;
    BOOL    bret;
    vmf_ret_t vmf_ret=VMF_OK;
    
    IPC_INFO("");
    
	if (TRUE == ipc_init_done)
	{
		/* already initialized */
		IPC_WARNING("nw_vmf_ipc_init() already called");
		return VMF_OK;
	}
	
	if (FALSE == ipc_preinit_done)
	{
		nw_vmf_ipc_pre_init();
	}
	
    if (FALSE == ipc_connections.init)
    {
        for (i=0;i<IPC_CHANNELS;i++)
        {
            ipc_connections.conn[i].pool_id = MSGPOOL_NULL_POOL_ID;
            ipc_connections.conn[i].q_id = MSGQ_NULL_QUEUE_ID;
			ipc_connections.conn[i].channel_name[0]=0;
			ipc_connections.conn[i].block_on_send = TRUE;
			ipc_connections.conn[i].block_on_receive = TRUE;
            ipc_connections.conn[i].b_inuse = FALSE;
        }

		/* pre-set server */
        ipc_connections.max = 0;
		strncpy(ipc_connections.conn[CHANN_SERVER].channel_name,VMF_IPC_SERVER_NAME,sizeof(ipc_connections.conn[CHANN_SERVER].channel_name));
		ipc_connections.conn[CHANN_SERVER].b_inuse = TRUE;
        ipc_connections.init = TRUE;
		
        #if 0
        bret = vmf_mutex_init(&ipc_connections.mux);

        if (FALSE == bret)
        {
            /* report an error */
            vmf_ret = VMF_ERR_IPC_MUTEX;
            IPC_ERROR("vmf_mutex_init() failed");
        }
        #endif
    }    
    
	ipc_init_done = TRUE;
    return vmf_ret;
}




/*************************************************************************//**
 *
 *   Open existing IPC channel. \n
 *   Generally the 'sender' shall use nw_vmf_ipc_open. \n
 *   NOTE: mqueues opened with this function are then NON-BLOCKING!
 *
 *   \param[in]     channel_name  -- system wide unique name for the channel
 *   \param[in]     block_on_send -- defines if the mq_send shall block on
 *                                   this message queue if full
 *   \return        logic handle to identify the opened channel
 *                  or
 *                  a invalid handle for "out of channels" or "open failed"
 *
 ******************************************************************************/
vmf_handle_t nw_vmf_ipc_open (char *channel_name, BOOL block_on_send)
{
    vmf_handle_t        ipc_handle=VMF_ERROR;
    _queue_id           q_id=0;
    _pool_id            pool_id=NULL;
    
    if (NULL == channel_name)
	{
        IPC_ERROR("channel_name = NULL");
        return VMF_ERROR;
	}
    
    if (FALSE == ipc_connections.init)
    {
        IPC_ERROR("vmf-ipc not initialized");
        return VMF_ERROR;
    }

    IPC_INFO("channel_name = %s",channel_name);
 
	/* get a new ipc handle */ 
    ipc_handle = vmf_ipc_get_free_ipc_handle(channel_name);
    if (ipc_handle >= 0)
    {
        vmf_handle_t owner_handle;
        
        /* get and store the ipc_handle of the channel owner */
        IPC_INFO("get ipc handle of channel owner, owner_name = %s",channel_name);
		owner_handle = vmf_get_ipc_hdl(channel_name);
        if (owner_handle >= 0)
        {
			ipc_connections.conn[ipc_handle].block_on_send = block_on_send;
            ipc_connections.conn[ipc_handle].owner_hdl = owner_handle;
            q_id = ipc_connections.conn[owner_handle].q_id;
            if (MSGQ_NULL_QUEUE_ID !=q_id)
            {
                ipc_connections.conn[ipc_handle].q_id = q_id;
            }            
        }
        else
        {
            /* unknown channel name */
            (void)vmf_ipc_free_ipc_handle(ipc_handle);
            ipc_handle = VMF_ERROR;        
        }
    }
    /* get a new ipc handle */ 
    
    return ipc_handle;
}



/*************************************************************************//**
 *
 *   Create a IPC channel. \n
 *   Generally the 'receiver' shall use nw_vmf_ipc_create. \n
 *   NOTE: mqueues created with this function are then BLOCKING!
 *
 *   \param[in]     channel_name -- system wide unique name for the channel
 *   \param[in]     queue_size   -- queue size (number of messages)
 *   \param[in]     msg_size     -- message size for the queue
 *   \return        logic handle to identify the created channel
 *
 ******************************************************************************/
vmf_handle_t nw_vmf_ipc_create (char *channel_name, unsigned16 msg_num, unsigned16 msg_size)
{
    _pool_id            pool_id=NULL;
     _queue_id          q_id;
    vmf_handle_t        ipc_handle=VMF_ERROR;
    BOOL                berr=TRUE;

    IPC_INFO("");

    /* argument check */
    if (NULL == channel_name)
    {
        IPC_ERROR("channel_name = NULL");
        return VMF_ERR_NULL_POINTER;
    }
    else if ((0 == msg_num) || (0 == msg_size))
    {
        IPC_ERROR("msg_num = 0 or msg_size = 0");
        return VMF_ERR_IPC_MSG_SIZE_TO_SMALL;
    }

    if (FALSE == ipc_connections.init)
    {
        IPC_ERROR("ipc_connections not initialized");
        return VMF_ERROR;
    }

    /* create a message pool and open a message queue */ 
    /* the channel name will be stored by vmf_ipc_get_free_ipc_handle() */
    ipc_handle = vmf_ipc_get_free_ipc_handle(channel_name);
    if (ipc_handle >= 0)
    {
        /* open a new queue */
        q_id = _msgq_open(MSGQ_FREE_QUEUE,0);
        IPC_INFO("quid = %d",q_id);
		if (MSGQ_NULL_QUEUE_ID !=q_id)
        {
            ipc_connections.conn[ipc_handle].q_id = q_id;
            ipc_connections.conn[ipc_handle].q_number = QUEUE_FROM_QID(q_id);
	        IPC_INFO("q_number = %d",ipc_connections.conn[ipc_handle].q_number);
			
            /* create a new message pool - so the message pool is owned by the receiver! */
            pool_id = _msgpool_create(msg_size,msg_num,0,0);
	        IPC_INFO("pool_id = %d, msg_size=%d, msg_num=%d",pool_id,msg_size,msg_num);

            ipc_connections.conn[ipc_handle].pool_id = pool_id;
            if (MSGPOOL_NULL_POOL_ID != pool_id)
            {
                /* everything worked well */
                ipc_connections.conn[ipc_handle].owner_hdl = ipc_handle;
                ipc_connections.conn[ipc_handle].msg_size = msg_size;
                berr = FALSE;
            }
            else
            {
                IPC_ERROR("_msgpool_create() failed");
            }
        }
        else
        {
            IPC_ERROR("_msgq_open() failed");
        }        
    }
    else
    {
        IPC_ERROR("vmf_ipc_get_free_ipc_handle() failed");
    }        

    if (TRUE == berr)
    {
        /* free all resources in case of an error */
        if (MSGPOOL_NULL_POOL_ID != pool_id)
        {
            (void)_msgpool_destroy(pool_id);
        }
        if (MSGQ_NULL_QUEUE_ID !=q_id)
        {
            (void)_msgq_close(q_id);
        }
        if (ipc_handle >= 0)
        {
            vmf_ipc_free_ipc_handle(ipc_handle);
            ipc_connections.conn[ipc_handle].q_number = MSGQ_NULL_QUEUE_ID;
            ipc_connections.conn[ipc_handle].pool_id = MSGPOOL_NULL_POOL_ID;
        }
        ipc_handle = VMF_ERROR;
    }
	else
	{
        IPC_INFO("nw_vmf_ipc_create() OK IPC-handle=%d",ipc_handle);
	}
	return ipc_handle;
}


/*************************************************************************//**
 *
 *   Create an async IPC channel. \n
 *   NOTE: mqueues created with this function are then NON-BLOCKING!
 *
 *   \param[in]     channel_name     -- system wide unique name for the channel
 *   \param[in]     queue_size       -- queue size (number of messages)
 *   \param[in]     msg_size         -- message size for the queue
 *   \param[in]     block_on_receive -- true if receive on the queue is
 *                                   -- blocking if queue is empty
 *   \param[in]     channel_id       -- OSAL channel ID
 *   \param[in]     async_event      -- event that is fired if VMF queue changed from empty to
 *                                   -- not empty
 *   \return        logic handle to identify the created channel
 *
 ******************************************************************************/
vmf_handle_t nw_vmf_ipc_create_async (char *channel_name, unsigned16 msg_num,
                                      unsigned16 msg_size, unsigned32 not_used,
                                      unsigned32 async_event)
{
    _pool_id            pool_id=NULL;
     _queue_id          q_id;
    vmf_handle_t        ipc_handle=VMF_ERROR;
    BOOL                berr=TRUE;

    IPC_INFO("");

    /* argument check */
    if (NULL == channel_name)
    {
        IPC_ERROR("channel_name = NULL");
        return VMF_ERR_NULL_POINTER;
    }
    else if ((0 == msg_num) || (0 == msg_size))
    {
        IPC_ERROR("msg_num = 0 or msg_size = 0");
        return VMF_ERR_IPC_MSG_SIZE_TO_SMALL;
    }

    if (FALSE == ipc_connections.init)
    {
        IPC_ERROR("ipc_connections not initialized");
        return VMF_ERROR;
    }

    /* create a message pool and open a message queue */ 
    /* the channel name is already stored by vmf_ipc_get_free_ipc_handle() */
    ipc_handle = vmf_ipc_get_free_ipc_handle(channel_name);
    if (ipc_handle >= 0)
    {
        /* open a new queue */
        q_id = _msgq_open(MSGQ_FREE_QUEUE,0);
        IPC_INFO("quid = %d",q_id);		
        if (MSGQ_NULL_QUEUE_ID !=q_id)
        {
            ipc_connections.conn[ipc_handle].q_id = q_id;
            ipc_connections.conn[ipc_handle].q_number = QUEUE_FROM_QID(q_id);
	        IPC_INFO("q_number = %d",ipc_connections.conn[ipc_handle].q_number);
			
            /* create a new message pool - so the message pool is owned by the receiver! */
            pool_id = _msgpool_create(msg_size,msg_num,0,0);
	        IPC_INFO("pool_id = %d",pool_id);
            ipc_connections.conn[ipc_handle].pool_id = pool_id;
            if (MSGPOOL_NULL_POOL_ID != pool_id)
            {
                /* register notification function */
                if (OS_STATUS_OK == _msgq_set_notification_function( q_id, vmf_ipc_async_notification,(void *)ipc_handle))
                {
                    /* everything worked well */
                    ipc_connections.conn[ipc_handle].async_event=async_event;
                    ipc_connections.conn[ipc_handle].msg_size = msg_size;
                    berr = FALSE;
                }
                else
                {
                    IPC_ERROR("_msgq_set_notification_function() failed");
                }
            }
            else
            {
                IPC_ERROR("_msgpool_create() failed");
            }
        }
        else
        {
            IPC_ERROR("_msgq_open() failed");
        }        
    }
    else
    {
        IPC_ERROR("vmf_ipc_get_free_ipc_handle() failed");
    }        

    if (TRUE == berr)
    {
        /* free all resources in case of an error */
        if (MSGPOOL_NULL_POOL_ID != pool_id)
        {
            (void)_msgpool_destroy(pool_id);
        }
        if (MSGQ_NULL_QUEUE_ID !=q_id)
        {
            (void)_msgq_close(q_id);
        }
        if (ipc_handle >= 0)
        {
            vmf_ipc_free_ipc_handle(ipc_handle);
            ipc_connections.conn[ipc_handle].q_number = MSGQ_NULL_QUEUE_ID;
            ipc_connections.conn[ipc_handle].pool_id = MSGPOOL_NULL_POOL_ID;
        }
        ipc_handle = VMF_ERROR;
    }
}




/*************************************************************************//**
 *
 *   Close IPC channel (not destroy)
 *
 *   \param[in]     vmf_handle -- logic channel handle
 *                                (from nw_vmf_ipc_open or nw_vmf_ipc_create)
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_close (vmf_handle_t vmf_handle)
{
    IPC_INFO("");
    
    (void)vmf_ipc_free_ipc_handle(vmf_handle);
    return VMF_OK;
}


/*************************************************************************//**
 *
 *   Remove IPC channel from system
 *
 *   \param[in]     vmf_handle -- logic channel handle
 *                                (from nw_vmf_ipc_open or nw_vmf_ipc_create)
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_destroy (vmf_handle_t vmf_handle)
{
    return VMF_OK;
}


/*************************************************************************//**
 *
 *   clean all recources used by this IPC
 *
 *   \param[in]     void
 *   \return        vmf return type
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_ipc_clean_recources(void)
{
    return VMF_OK;
}



/*************************************************************************//**
 *
 *   Send a message on the IPC channel. \n
 *   NOTE: 
 *
 *   \param[in]     vmf_handle   -- logic channel handle
 *                                  (from nw_vmf_ipc_open or nw_vmf_ipc_create)
 *   \param[in]     buffer       -- pointer to message to send
 *   \param[in]     number_bytes -- number of bytes to send
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_send ( vmf_handle_t ipc_handle, unsigned8 *buffer, unsigned16 number_bytes)
{
    vmf_ret_t           ret_val=VMF_OK;
    vmf_handle_t        owner_hdl;
    unsigned8           *pmsg=NULL;
    BOOL                bret;
    BOOL				block_on_send=TRUE;
	
    IPC_INFO("");
    
	nw_con_HexDump("nw_vmf_ipc_send=", (unsigned8 *)buffer, 20);
	
    /* get the owner of the channel */
    owner_hdl = ipc_connections.conn[ipc_handle].owner_hdl;
	block_on_send = ipc_connections.conn[ipc_handle].block_on_send;
	
    /* check message size */
    if (number_bytes > ipc_connections.conn[owner_hdl].msg_size)
    {
        ret_val = VMF_ERR_TO_MUCH_DATA;
        IPC_ERROR("message to big message-len=%d, max-len=%d",number_bytes,ipc_connections.conn[owner_hdl].msg_size);    
    }
    else
    {
        /* get a buffer - the pool is owned by the receiver==creator */
        IPC_INFO("pool_id = %d",ipc_connections.conn[owner_hdl].pool_id);
        IPC_INFO("q_id = %d",ipc_connections.conn[owner_hdl].q_id);
		
		/* wait for free message buffer in no blocking mode */
		while (block_on_send)
		{
			pmsg = _msg_alloc(ipc_connections.conn[owner_hdl].pool_id);
			if (NULL != pmsg)
			{	
				break;
			}
			_time_delay(0);
		}
        if (NULL != pmsg)
        {
            /* copy and transfer the message */
            memcpy(pmsg,buffer,number_bytes);
#ifdef MQX_Q_BUG_WORKAROUND
            /* wait until queue empty in no blocking mode*/
			{
				unsigned8           *plmsg=NULL;
				while(block_on_send)
				{
					plmsg = _msgq_peek(ipc_connections.conn[owner_hdl].q_id);
					if (NULL == plmsg)
					{	
						break;
					}
					_time_delay(0);
				}
				if (plmsg != NULL)
				{
					return VMF_ERR_IPC_SEND;		/* do not block */
				}
			}
#endif			
			IPC_INFO("send %d bytes to q_id=%d",number_bytes,ipc_connections.conn[owner_hdl].q_id);
			bret = _msgq_send_queue(pmsg, ipc_connections.conn[owner_hdl].q_id); 
			_time_delay(0);							/* context change */
            if (FALSE == bret)
            {
	           (void)_msg_free(pmsg);   
               ret_val = VMF_ERR_IPC_SEND;
			   IPC_ERROR("_msgq_send_queue() failed");
            }
			else
			{
				ret_val = VMF_OK;
			}
	
        }
		else
		{
			ret_val = VMF_ERR_IPC_SEND;;
			IPC_ERROR("_msg_alloc() failed");
	   }
    }
    return ret_val;
}




/*************************************************************************//**
 *
 *   receive a message on the IPC channel with timeout. \n
 *   NOTE: in combination with nw_vmf_ipc_create it is BLOCKING at QNX API
 *         if message queue is full!
 *
 *   \param[in]     vmf_handle   -- logic channel handle
 *                                  (from nw_vmf_ipc_open or nw_vmf_ipc_create)
 *   \param[in]     buffer_size  -- maximum buffer size
 *   \param[out]    buffer       -- pointer to buffer for received message
 *   \param[out]    number_bytes -- pointer to number of received bytes.
 *   \param[in]     ms_timeout   -- receive timeout in ms
 *                                  timeout of 0 is unlimited timeout !!
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_timed_receive (vmf_handle_t ipc_handle,unsigned16 buffer_size,
                                    unsigned8 *buffer,unsigned16 *p_number_bytes,
                                    unsigned16 ms_timeout)
{
    vmf_ret_t           ret_val=VMF_ERROR;
    vmf_handle_t        owner_hdl;
    unsigned8           *pmsg=NULL;
    unsigned16          number_bytes=0;
    
    IPC_INFO("timeout = %d",ms_timeout);
    
    /* get the owner of the channel */
    owner_hdl = ipc_connections.conn[ipc_handle].owner_hdl;
   
    /* get message size */
    number_bytes = ipc_connections.conn[owner_hdl].msg_size;
    *p_number_bytes = number_bytes;
        
    /* get a buffer - the pool is owned by the receiver == creator */
    IPC_INFO("quid = %d",ipc_connections.conn[ipc_handle].q_id);
    pmsg = _msgq_receive(ipc_connections.conn[ipc_handle].q_id,ms_timeout);
    if (NULL != pmsg)
    {
        /* copy the message to the destination buffer */
        if (buffer_size >= number_bytes)
        {
            memcpy(buffer,pmsg,buffer_size);
            ret_val = VMF_OK;
		    IPC_INFO(" number of rx_bytes=%d",number_bytes);
        }
        else
        {
            IPC_ERROR("dest buffer to small buffer-len=%d, data-len=%d",buffer_size,number_bytes);
            ret_val = VMF_ERR_TO_MUCH_DATA;
        }
        (void)_msg_free(pmsg);   
    }
	else
	{
        IPC_ERROR("_msgq_receive returned NULL");
	}
    IPC_INFO("return=%d",ret_val);
    return ret_val;
}

/*************************************************************************//**
 *
 *   Receive a message on the IPC channel. \n
 *   NOTE: in combination with nw_vmf_ipc_create it is BLOCKING at QNX API
 *         if message queue is full!
 *
 *   \param[in]     vmf_handle   -- logic channel handle
 *                                  (from nw_vmf_ipc_open or nw_vmf_ipc_create)
 *   \param[in]     buffer_size  -- maximum buffer size
 *   \param[out]    buffer       -- pointer to buffer for received message
 *   \param[out]    number_bytes -- pointer to number of received bytes.
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_receive (vmf_handle_t ipc_handle,unsigned16 buffer_size,
                              unsigned8 *buffer,unsigned16 *p_number_bytes)
{
    vmf_ret_t   ret_val=VMF_OK;
    IPC_INFO("");
    
    ret_val = nw_vmf_ipc_timed_receive (ipc_handle, buffer_size, buffer, p_number_bytes, 0);
    IPC_INFO("return=%d",ret_val);
	nw_con_HexDump("nw_vmf_ipc_receive=", (unsigned8 *)buffer, 20);
	return ret_val;
}



/*************************************************************************//**
 *
 *   Obtain a free ipc handle. \n
 *
 *   \param         none
 *   \return        next free IPC handle or vmf error type
 *
 ******************************************************************************/
vmf_handle_t vmf_ipc_get_free_ipc_handle (char *channel_name)
{
    int             i;
    vmf_handle_t    ret_val=VMF_ERR_OUT_OF_IPC_CHANNELS;

	if (NULL == channel_name)
	{
		IPC_ERROR("channel_name = NULL"); 
		return VMF_ERR_MUX;
	}
	
    IPC_INFO("channel_name = %s",channel_name); 
    if (FALSE == vmf_mutex_lock(&ipc_connections.mux))
    {
        /* mutex error */
        IPC_ERROR("vmf_mutex_lock() failed");
        return VMF_ERR_MUX;
    }

    /* test if server */
    if (0 == strncmp(channel_name,VMF_IPC_SERVER_NAME,sizeof(VMF_IPC_SERVER_NAME)))
    {
		IPC_INFO("Server channel - IPC-handle = %d",CHANN_SERVER); 
        ret_val = CHANN_SERVER;        /* server channel */
    }
    else
    {
        /* search for free entry */
        if (ipc_connections.max < IPC_MAX_CHANNEL)
        {
            /* use next free connection */
            IPC_INFO("Use next free connection");
			ipc_connections.max++;
            ret_val = (vmf_handle_t)ipc_connections.max;
        }
        else
        {
            /* search for a released connection */
            IPC_INFO("search for free connection");
            for (i=CHANN_FIRST_FREE; i<=ipc_connections.max; i++)
            {
                if (FALSE == ipc_connections.conn[i].b_inuse)
                {
                    /* found free entry */
                    ipc_connections.conn[i].b_inuse = TRUE;
                    break;
                }
            }
        }
    }
    if (ret_val >= 0)
    {
        /* store the channel name */
        ipc_connections.conn[ret_val].b_inuse = TRUE;
        strncpy(ipc_connections.conn[ret_val].channel_name,channel_name,sizeof(ipc_connections.conn[ret_val].channel_name));
		IPC_INFO("IPC handle =%d, channel_name =%s",ret_val,ipc_connections.conn[ret_val].channel_name); 
    }
    else
    {
        IPC_ERROR("no free IPC handle found");    
    }


    (void)vmf_mutex_release(&ipc_connections.mux); 
    return ret_val;
}




/*************************************************************************//**
 *
 *   Create a unique name for IPC channel from PID and ClientID
 *
 *   \param[in]     pid            -- process id
 *   \param[in]     cid            -- client id
 *   \param[out]    p_channel_name -- pointer to channel_name
 *   \param[in]     buffer_size    -- size of p_channel_name
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_create_channel_name (vmf_pid_t pid, vmf_cid_t cid,
                                          char *p_channel_name, unsigned8 buffer_size)
{
    vmf_ret_t   ret_val = VMF_OK;
    unsigned8   pid_hi;
    unsigned8   pid_lo;
	int			len;
	
    IPC_INFO("");
	if (NULL == p_channel_name)
	{
		return VMF_ERR_NULL_POINTER;
	}
	
    IPC_INFO("pid=%d, cid=%d",pid,cid);
	len = buffer_size;
	if (len > IPC_MAX_NAME_LEN)
	{
		len = IPC_MAX_NAME_LEN;
	}
    snprintf (p_channel_name, len, "%04x%02x",pid,cid);
    IPC_INFO("channel_name = %s",p_channel_name); 
    
    return ret_val;
}


/*************************************************************************//**
 *
 *   free an ipc handle. \n

 *
 *   \param         ipc handle
 *   \return        true if OK
 *
 ******************************************************************************/
static BOOL vmf_ipc_free_ipc_handle (vmf_handle_t ipc_hdl)
{
    BOOL    bret = FALSE;

    IPC_INFO("");
    if (FALSE == vmf_mutex_lock(&ipc_connections.mux))
    {
        /* mutex error */
        IPC_ERROR("vmf_mutex_lock() failed"); 
        return bret;
    }
    
    if ((ipc_hdl <= IPC_MAX_CHANNEL) && (ipc_hdl >= CHANN_FIRST_FREE))
    {
        if (TRUE == ipc_connections.conn[ipc_hdl].b_inuse)
        {
#if 0
            /* release all used resources */
            if (ipc_connections.conn[ipc_hdl].pool_id > 0)
            {
                (void)_msgpool_destroy(ipc_connections.conn[ipc_hdl].pool_id);
                ipc_connections.conn[ipc_hdl].pool_id = MSGPOOL_NULL_POOL_ID;
            } 
            if (ipc_connections.conn[ipc_hdl].q_id > 0)
            {
                (void)_msgq_close(ipc_connections.conn[ipc_hdl].q_id);
                ipc_connections.conn[ipc_hdl].q_id = MSGQ_NULL_QUEUE_ID;
            } 
#endif
            ipc_connections.conn[ipc_hdl].channel_name[0]=0;
            ipc_connections.conn[ipc_hdl].b_inuse = FALSE;
            ipc_connections.conn[ipc_hdl].q_number = MSGQ_NULL_QUEUE_ID;
            ipc_connections.conn[ipc_hdl].pool_id = MSGPOOL_NULL_POOL_ID;

            bret = TRUE;
        }
    }
    (void)vmf_mutex_release(&ipc_connections.mux); 
    return bret;
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

    IPC_INFO("");
    
    while(inUse)
    {
        _time_delay(0);
    }
    inUse = TRUE;

	if (_mutex_init(pmutex, NULL) != MQX_OK)
	{
		bRet = FALSE;
		IPC_ERROR("_mutex_init() failed");
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
    
    IPC_INFO("");
        
    ret_val = _mutex_lock(pmutex);
    if (ret_val != MQX_EOK)
    {
        IPC_ERROR("_mutex_lock() failed, retval=%d",ret_val);
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
	IPC_INFO("");

    ret_val = _mutex_unlock(pmutex);
    if (ret_val != MQX_EOK)
    {
        IPC_ERROR("_mutex_unlock() failed, retval=%d",ret_val);
        return FALSE;
    }

    return TRUE;
}


/*************************************************************************//**
 *
 *   get the ipc handle for a given channel name \n
 *
 *   \param         queue name
 *   \return        ipc_handle
 *
 ******************************************************************************/
static vmf_handle_t vmf_get_ipc_hdl(char * channel_name)
{
    vmf_handle_t    ipc_hdl=VMF_ERROR;
    int             i;
    
    IPC_INFO("");
    
    if (NULL == channel_name)
    {
        IPC_ERROR("channel_name = NULL!");
        return VMF_ERROR;
    }
	else
	{
		IPC_INFO("channel_name=%s",channel_name);
	}

    if (FALSE == vmf_mutex_lock(&ipc_connections.mux))
    {
        /* mutex error */
        IPC_ERROR("vmf_mutex_lock() failed");
        return VMF_ERR_MUX;
    }

	IPC_INFO("search for %s, max=%d",channel_name,ipc_connections.max);
    for (i=0; i<=ipc_connections.max; i++)
    {
        if (TRUE == ipc_connections.conn[i].b_inuse)
        {
            /* found entry */
            if (channel_name[0] == ipc_connections.conn[i].channel_name[0])     /* speedup*/
            {
                if (0 == strncmp(channel_name,ipc_connections.conn[i].channel_name,strlen(channel_name)))
                {
                    ipc_hdl = (vmf_handle_t)i;
                    IPC_INFO("found %s, ipc-handle=%d, q_id = ",channel_name,ipc_hdl,ipc_connections.conn[i].q_id);
					break;
                }
            }
        }
    }
    IPC_INFO("ipc_hdl = %d",ipc_hdl);
	(void)vmf_mutex_release(&ipc_connections.mux);
    return ipc_hdl;
}

/*************************************************************************//**
 *
 *   async notofication callback
 *
 *   \param[in]     ipc_handle
 *   \return        NULL
 *
 ******************************************************************************/
static MSGQ_NOTIFICATION_FPTR vmf_ipc_async_notification(uint_32 *param)
{
	unsigned32          async_event;
    
    async_event = ipc_connections.conn[(int)param].async_event;
    // _lwevent_set(&(os_task_list[*p].event_group), EV_MESSAGE);
	return NULL;
}


/*************************************************************************//**
 *
 *  get current time in ms
 *
 *   \param[in]     void
 *   \return        16 bit time in ms
 *
 ******************************************************************************/
unsigned32 nw_vmf_ipc_get_ms_time(void)
{
	unsigned32	ctime=0;
	
	_time_get(&mqx_time_s); 
	ctime = ((mqx_time_s.SECONDS * 1000) + (mqx_time_s.MILLISECONDS)) & 0xffffffff;
	return ctime;
}

