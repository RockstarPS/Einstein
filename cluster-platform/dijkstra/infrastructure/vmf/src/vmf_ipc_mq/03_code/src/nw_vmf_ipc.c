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

  \file                 nw_vmf_ipc.c
  \brief                inter process communication

  \author               Joerg Merkle
  \author               Visteon Deutschland GmbH, Infotainment Software

  compiler              gcc
  target                any

  *****************************************************************************/
#define __NW_VMF_IPC_C__

//#define NW_VMF_DEBUG

/* system includes */
#include <mqueue.h>
#include "nw_os_config.h"
//#include "os_event.h"

/* application includes */
#include "nw_vmf_types.h"
#include "nw_vmf_cfg.h"
#include "nw_vmf_debug.h"
#include "nw_vmf_util.h"
#include "nw_vmf_ipc.h"

#ifdef UNIT_TEST
#include "unit_test.h"
#endif

#include "intEvtDefs.h"

/* definitions and types */
#define NW_VMF_IPC_MQ_PERMISSIONS   O_CREAT                             /*!< message queue access rights (644) */

#ifdef INTEGRITY
#define NW_VMF_IPC_MQ_DESC_INVALID      MQ_FAILED                       /*!< value for a invalid queue descriptor */
#else
#define NW_VMF_IPC_MQ_DESC_INVALID      -1                              /*!< value for a invalid queue descriptor */
#endif
#define NW_VMF_IPC_MQ_ERROR             -1                              /*!< mq_send / mq_receive error */

#define NW_VMF_STATUS_MSG_INTERVALL     500                             /* message intervall in ms */
#define IPC_SERVER_HANDLE               (0)                             /* should be zero */
#define IPC_SERVER_THREAD               (pthread_t)(1)                  /* should be one */



/*! IPC connections information structure */
typedef struct
{
    mqd_t           mq_descriptor[MAX_IPC_CHANNELS];                    /*!< message queue identifier (posix) */
    char            client_name[MAX_IPC_CHANNELS][MAX_NAME_LEN];        /*!< client name received on connection request */
    unsigned8       client_id[MAX_IPC_CHANNELS];                        /*!< client ID received on connection request */
    pid_t           pid[MAX_IPC_CHANNELS];                              /*!< client process ID received on connection request */
    unsigned8       count;                                              /*!< number of active connections */
    unsigned32      coid[MAX_IPC_CHANNELS];                             /*!< coid of client Q */
    unsigned32      osal_event[MAX_IPC_CHANNELS];                       /*!< this event is fired if msg queue is filled */
    bool            async_rx_connection[MAX_IPC_CHANNELS];              /*!< true if rx connection is async */
    bool            was_notified[MAX_IPC_CHANNELS];                     /*!< true if a notification was already received */
    char            channel_name[MAX_IPC_CHANNELS][MAX_NAME_LEN];       /*!< optional channel name */
}ipc_connection_t;


/* module private function prototypes*/
static            vmf_handle_t    nw_vmf_ipc_get_free_vmf_handle  (void);
static            vmf_ret_t       nw_vmf_ipc_mutex_lock           (void);
static            vmf_ret_t       nw_vmf_ipc_mutex_unlock         (void);
static inline     vmf_ret_t       nw_vmf_ipc_notify (vmf_handle_t vmf_handle);
static inline     unsigned32      getmypid(void);
static            void            *nw_vmf_ipc_status_thread (void *pNoArg);


/* global data */
static ipc_connection_t    ipc_connections;
static pthread_mutex_t     ipc_mutex = PTHREAD_MUTEX_INITIALIZER;
static bool                ipc_init_done = false;

bool                       ipc_status_thread_is_running = false;
static unsigned16          high_watermark[MAX_IPC_CHANNELS];
static pthread_t           thread_id[MAX_IPC_CHANNELS];



/**************************************************************************//**
 *
 *   pre-init ipc
 *
 *   \param[in]     void     
 *   \return        void  
 ******************************************************************************/
void nw_vmf_ipc_pre_init(void)
{
}


/*************************************************************************//**
 *
 *   Initialization of IPC data
 *
 *   \param         none
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_init (bool remove_ressources)
{
    unsigned8 i;

    #if 0
    NW_VMF_DEBUG_INFO("nw_vmf_ipc_init - remove_ressources=%d\n",remove_ressources); 
    #endif
    
    if (remove_ressources)  /* means server only! */
    {
        for (i=0;i<MAX_IPC_CHANNELS;i++)
        {
            high_watermark[i]=0;
            thread_id[i] = 0;
        }
    }
    
    if (false == ipc_init_done)
    {
        /* initialize data */
        ipc_connections.count = 0x00;

        /* set mq_descriptors to invalid */
        for (i=0;i<MAX_IPC_CHANNELS;i++)
        {
            ipc_connections.mq_descriptor[i] = NW_VMF_IPC_MQ_DESC_INVALID;
            ipc_connections.channel_name[i][0]=0;
            ipc_connections.client_name[i][0]=0;
        }

        /* inhibit addtional inits */
        ipc_init_done = true;
    }

    return VMF_OK;
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
vmf_handle_t nw_vmf_ipc_open (char *channel_name, bool block_on_send)
{
    vmf_handle_t    vmf_handle = VMF_HANDLE_INVALID;
    mqd_t           mq_descriptor = NW_VMF_IPC_MQ_DESC_INVALID;
    signed32        mq_flags = O_RDWR;


    NW_VMF_ARG_CHECK_POINTER ("nw_vmf_ipc_open - channel_name", channel_name);

    if (IPC_NON_BLOCKING == block_on_send)
    {
        mq_flags |= O_NONBLOCK;
    }

    mq_descriptor = mq_open(channel_name, mq_flags);
    if (mq_descriptor != NW_VMF_IPC_MQ_DESC_INVALID)
    {
        /* obtain a new vmf handle */
        if(VMF_ERR_IPC_MUTEX == nw_vmf_ipc_mutex_lock())
        {
            NW_VMF_DEBUG_ERROR("ipc_open: mutex lock failed \n");
        }

        vmf_handle = nw_vmf_ipc_get_free_vmf_handle();

        if(VMF_ERR_IPC_MUTEX == nw_vmf_ipc_mutex_unlock())
        {
            NW_VMF_DEBUG_ERROR("ipc_open: mutex unlock failed \n");
        }

        if ((vmf_handle_t)VMF_ERR_OUT_OF_IPC_CHANNELS != vmf_handle)
        {
            /* make an entry to ipc_connections table */
            ipc_connections.mq_descriptor[(unsigned8)vmf_handle] = mq_descriptor;
            /* set async flag */
            ipc_connections.async_rx_connection[(unsigned8)vmf_handle] = false;

            /* store channel name */
            nw_os_sstrncpy(ipc_connections.channel_name[(unsigned8)vmf_handle], channel_name, sizeof(ipc_connections.channel_name[(unsigned8)vmf_handle]));

            /* remind my thread id */
            thread_id[vmf_handle] = pthread_self();

            NW_VMF_DEBUG_PRINT(NW_VMF_DBG_LVL_IPC, NW_VMF_DBG_ASP_IPC,
                "ipc_open: OK -- channel %s \tvmf_handle %d \n", channel_name, vmf_handle);
        }
        else
        {
            vmf_handle = VMF_HANDLE_INVALID;
        }
    }
    else
    {
        /* jmerkle  06.03.2008 17:20:20 TBD */
        /* jmerkle  what to do if mq access failed? */
        NW_VMF_DEBUG_ERROR("ipc_open:%d: mq_open %s failed! %s\n", getpid(), channel_name, strerror(errno));
    }

#ifdef NW_VMF_DEBUG_IPC_CONNECTION_INFO
    {
        unsigned8       i;
    
        NW_VMF_DEBUG_INFO("ipc_connections:\n");
        for (i=0;i<ipc_connections.count;i++)
        {
            NW_VMF_DEBUG_INFO("%u\tmq_desc: %d\n", i, (int)ipc_connections.mq_descriptor[i]);
        }
    }
#endif
    return vmf_handle;
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
vmf_handle_t nw_vmf_ipc_create (char *channel_name, unsigned16 queue_size, unsigned16 msg_size)
{
    vmf_handle_t    vmf_handle = VMF_HANDLE_INVALID;
    mqd_t           mq_descriptor = NW_VMF_IPC_MQ_DESC_INVALID;
    struct mq_attr  mq_attributes;
    char vmf_server_channel[100];
    char vmf_client_channel[100];
	 mode_t  mask;
     struct stat st;
	 gid_t my_egid;

    NW_VMF_ARG_CHECK_POINTER ("nw_vmf_ipc_create - channel_name", channel_name);

    /* resize arguments to limits if out of bounds */
    if (queue_size < VMF_IPC_QUEUE_SIZE_MIN)
    {
        NW_VMF_DEBUG_PRINT(NW_VMF_DBG_LVL_IPC, NW_VMF_DBG_ASP_IPC,"pid = %d, nw_vmf_ipc_create: queue size too small --> set to minimum (=%d)\n",getmypid(), VMF_IPC_QUEUE_SIZE_MIN);
        queue_size = VMF_IPC_QUEUE_SIZE_MIN;
    }
    else if ((queue_size > VMF_IPC_QUEUE_SIZE_MAX) && (queue_size != VMF_SPY_QUEUE_SIZE) && (queue_size != VMF_TRACE_QUEUE_SIZE))
    {
        /* only the VMF spy and VMF trace are allowed to use bigger queues! */
        NW_VMF_DEBUG_PRINT(NW_VMF_DBG_LVL_IPC, NW_VMF_DBG_ASP_IPC,"pid = %d, nw_vmf_ipc_create: queue size too big --> set to maximum (=%d)\n",getmypid(), VMF_IPC_QUEUE_SIZE_MAX);
        queue_size = VMF_IPC_QUEUE_SIZE_MAX;
    }
    else
    {
        /* nothing to do here. */
    }

    if (msg_size < VMF_IPC_MSG_SIZE_MIN)
    {
        NW_VMF_DEBUG_ERROR("ipc_create: msg size too small! \n");
        return (VMF_ERR_IPC_MSG_SIZE_TO_SMALL);
    }
    else
    {
        /* nothing to do here. */
    }

    /* settings for the message queue */
    mq_attributes.mq_maxmsg = (long)queue_size;             /* max number messages 4 server */
    mq_attributes.mq_msgsize = (long)msg_size;              /* max message size */
    mq_attributes.mq_flags = 0;                             /* blocking */

    (void) mq_unlink(channel_name);

    // VMF_Rootless_Execution: Change Default umask to allow file creation with group write access
    mask = umask(0);

    //Create mq
    mq_descriptor = mq_open(channel_name, O_CREAT|O_RDWR , (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP), &mq_attributes);

    // VMF_Rootless_Execution: Reset the umask
    (void)umask(mask);

    if (mq_descriptor != NW_VMF_IPC_MQ_DESC_INVALID)
    {
    	// VMF_Rootless_Execution: Get the VMF Server & Client Channel name
		snprintf(vmf_server_channel, sizeof(vmf_server_channel), "%s%s", "/dev/mq", IPC_SERVER_CHANNEL_NAME);
		snprintf(vmf_client_channel, sizeof(vmf_client_channel), "%s%s", "/dev/mq", channel_name);

		if(stat(vmf_client_channel, &st) != 0)
		{
			NW_VMF_DEBUG_ERROR("ipc_create: VMF Client Channel %s doesn't exist\n", vmf_client_channel);
		}
		my_egid = st.st_gid;

		// VMF_Rootless_Execution: Change the process group of VMF Clients to match with that of VMF Server Channel
		if((stat(vmf_server_channel, &st) == 0) && (my_egid != st.st_gid))
		{
			chown(vmf_client_channel, -1, st.st_gid);
		}
		
        /* obtain a new vmf handle */
        if(VMF_ERR_IPC_MUTEX == nw_vmf_ipc_mutex_lock())
        {
            NW_VMF_DEBUG_ERROR("ipc_create: mutex lock failed \n");
        }
        vmf_handle = nw_vmf_ipc_get_free_vmf_handle();

        if(VMF_ERR_IPC_MUTEX == nw_vmf_ipc_mutex_unlock())
        {
            NW_VMF_DEBUG_ERROR("ipc_create: mutex unlock failed \n");
        }

        if ((vmf_handle_t)VMF_ERR_OUT_OF_IPC_CHANNELS != vmf_handle)
        {
            /* make an entry to ipc_connections table */
            ipc_connections.mq_descriptor[(unsigned8)vmf_handle] = mq_descriptor;
            nw_os_sstrncpy(ipc_connections.channel_name[(unsigned8)vmf_handle], channel_name, sizeof(ipc_connections.channel_name[(unsigned8)vmf_handle]));

            /* set async flag */
            ipc_connections.async_rx_connection[(unsigned8)vmf_handle] = false;

            /* remind my thread id */
            thread_id[vmf_handle] = pthread_self();

            #if 0
            NW_VMF_DEBUG_INFO("nw_vmf_ipc_create: vmf_handle= %d, name=%s \n",vmf_handle,ipc_connections.channel_name[vmf_handle]); 
            #endif
            
            NW_VMF_DEBUG_PRINT(NW_VMF_DBG_LVL_IPC, NW_VMF_DBG_ASP_IPC,
                "ipc_create: OK -- channel %s \tvmf_handle %d \n", channel_name, vmf_handle);
        }
        else
        {
            vmf_handle = VMF_HANDLE_INVALID;
        }
    }
    else
    {
        /* jmerkle  06.03.2008 17:20:20 TBD */
        /* jmerkle  what to do if mq access failed? */
        NW_VMF_DEBUG_ERROR("ipc_create: mq_open failed! \n");
        perror("ipc_create: errno:"); 
        delay(100);
   }

#ifdef NW_VMF_DEBUG_IPC_CONNECTION_INFO
    {
        unsigned8       i;
    
        NW_VMF_DEBUG_PRINT(NW_VMF_DBG_LVL_IPC, NW_VMF_DBG_ASP_IPC, "ipc_connections:\n");
        for (i=0;i<ipc_connections.count;i++)
        {
            NW_VMF_DEBUG_PRINT(NW_VMF_DBG_LVL_IPC, NW_VMF_DBG_ASP_IPC, "%u\tmq_desc: %d\n", i, (int)ipc_connections.mq_descriptor[i]);
        }
    }
#endif
    return vmf_handle;
}



/*************************************************************************//**
 *
 *   Create an async IPC channel. \n
 *   Generally the 'receiver' shall use nw_vmf_ipc_create. \n
 *   NOTE: mqueues created with this function are then BLOCKING!
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
vmf_handle_t nw_vmf_ipc_create_async (char *channel_name, unsigned16 queue_size,
                                      unsigned16 msg_size, unsigned32 coid,
                                      unsigned32 async_event)
{
#ifndef ENABLE_OSAL_ASYNC

    UNUSED_PARAM(channel_name);
    UNUSED_PARAM(queue_size);
    UNUSED_PARAM(msg_size);
    UNUSED_PARAM(coid);
    UNUSED_PARAM(async_event);

    NW_COMPILER_MESSAGE("MQ-IPC async disabled");
    NW_VMF_DEBUG_ERROR("nw_vmf_ipc_create_async: not supported! \n");
    return VMF_ERROR;

#else
    vmf_ret_t       ret_val = VMF_ERROR;
    vmf_handle_t    vmf_handle = VMF_HANDLE_INVALID;
    mqd_t           mq_descriptor = NW_VMF_IPC_MQ_DESC_INVALID;
    struct mq_attr  mq_attributes;

    NW_COMPILER_MESSAGE("MQ-IPC async enabled");

    NW_VMF_ARG_CHECK_POINTER ("nw_vmf_ipc_open - channel_name", channel_name);
    
    /* resize arguments to limits if out of bounds */
    if (queue_size < VMF_IPC_QUEUE_SIZE_MIN)
    {
        NW_VMF_DEBUG_PRINT(NW_VMF_DBG_LVL_IPC, NW_VMF_DBG_ASP_IPC, "nw_vmf_ipc_create_async: queue size too small --> set to minimum (=%d)\n", VMF_IPC_QUEUE_SIZE_MIN);
        queue_size = VMF_IPC_QUEUE_SIZE_MIN;
    }
    else if (queue_size > VMF_IPC_QUEUE_SIZE_MAX)
    {
        NW_VMF_DEBUG_PRINT(NW_VMF_DBG_LVL_IPC, NW_VMF_DBG_ASP_IPC, "nw_vmf_ipc_create_async: queue size too big --> set to maximum (=%d)\n", VMF_IPC_QUEUE_SIZE_MAX);
        queue_size = VMF_IPC_QUEUE_SIZE_MAX;
    }
    else
    {
        /* nothing to do here. */
    }

    if (msg_size < VMF_IPC_MSG_SIZE_MIN)
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_ipc_create_async: msg size too small! \n");
        vmf_handle = VMF_ERR_IPC_MSG_SIZE_TO_SMALL;
    }
    else
    {
		/* settings for the message queue */
		mq_attributes.mq_maxmsg = (long)queue_size;             /* max number messages 4 server */
		mq_attributes.mq_msgsize = (long)msg_size;              /* max message size */
		mq_attributes.mq_flags = O_NONBLOCK;

		mq_descriptor = mq_open(channel_name, O_CREAT|O_RDWR | O_NONBLOCK, NW_VMF_IPC_MQ_PERMISSIONS, &mq_attributes);
		if (mq_descriptor != NW_VMF_IPC_MQ_DESC_INVALID)
		{
			/* obtain a new vmf handle */
			if(VMF_ERR_IPC_MUTEX == nw_vmf_ipc_mutex_lock())
			{
				NW_VMF_DEBUG_ERROR("nw_vmf_ipc_create_async: mutex lock failed \n");
			}

			vmf_handle = nw_vmf_ipc_get_free_vmf_handle();

			if(VMF_ERR_IPC_MUTEX == nw_vmf_ipc_mutex_unlock())
			{
				NW_VMF_DEBUG_ERROR("nw_vmf_ipc_create_async: mutex unlock failed \n");
			}

			if ((vmf_handle_t)VMF_ERR_OUT_OF_IPC_CHANNELS != vmf_handle)
			{
				/* make an entry to ipc_connections table */
				ipc_connections.mq_descriptor[(unsigned8)vmf_handle] = mq_descriptor;
				/* set async flag */
				ipc_connections.coid[(unsigned8)vmf_handle] = coid;
				ipc_connections.osal_event[(unsigned8)vmf_handle] = async_event;
				ipc_connections.async_rx_connection[(unsigned8)vmf_handle] = true;

				nw_os_sstrncpy(ipc_connections.channel_name[(unsigned8)vmf_handle], channel_name, sizeof(ipc_connections.channel_name[(unsigned8)vmf_handle]));
				NW_VMF_DEBUG_PRINT(NW_VMF_DBG_LVL_IPC, NW_VMF_DBG_ASP_IPC,
					"nw_vmf_ipc_create_async: OK -- channel %s \tvmf_handle %d \n", channel_name, vmf_handle);
				#if 0
				NW_VMF_DEBUG_INFO("nw_vmf_ipc_create_async: vmf_handle= %d, name=%s \n",vmf_handle,ipc_connections.channel_name[vmf_handle]);
				#endif

				/* remind my thread id */
				thread_id[vmf_handle] = pthread_self();

				/* inform mq-server to send a pulse if a message is in the rx-queue*/
				ret_val= nw_vmf_ipc_notify(vmf_handle);
				if (ret_val != VMF_OK)
				{
					vmf_handle =(vmf_handle_t)ret_val;
				}
				else
				{
					ipc_connections.was_notified[(unsigned8)vmf_handle] = false;
					/* empty the queue */
					{
						unsigned8 buffer[msg_size];
						while (mq_receive(mq_descriptor, (char *)buffer, msg_size, NULL) > 0)
						{
							delay(0);
						}
					}
				}
			}
			else
			{
				vmf_handle = VMF_HANDLE_INVALID;
			}
		}
		else
		{
			/* jmerkle  06.03.2008 17:20:20 TBD */
			/* jmerkle  what to do if mq access failed? */
			NW_VMF_DEBUG_ERROR("nw_vmf_ipc_create_async: mq_open failed! \n");
			/* perror("ipc_create: errno:"); */
		}


#ifdef NW_VMF_DEBUG_IPC_CONNECTION_INFO
		{
			unsigned8       i;

			NW_VMF_DEBUG_PRINT(NW_VMF_DBG_LVL_IPC, NW_VMF_DBG_ASP_IPC, "ipc_connections:\n");
			for (i=0;i<ipc_connections.count;i++)
			{
				NW_VMF_DEBUG_PRINT(NW_VMF_DBG_LVL_IPC, NW_VMF_DBG_ASP_IPC, "%u\tmq_desc: %d\n", i, (int)ipc_connections.mq_descriptor[i]);
			}
		}
#endif
    }

    return vmf_handle;
#endif /* ENABLE_OSAL_ASYNC */
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
    vmf_ret_t ret_val = VMF_ERROR;
    mqd_t           mq_descriptor;

    NW_VMF_ARG_CHECK_RANGE ("nw_vmf_ipc_close - vmf_handle", vmf_handle, 0, MAX_IPC_CHANNELS-1);

    #if 0
    NW_VMF_DEBUG_INFO("nw_vmf_ipc_close: vmf_handle= %d, name=%s \n",vmf_handle,ipc_connections.channel_name[vmf_handle]); 
    #endif
    
    /* get the message queue descriptor from table and check */
    mq_descriptor = ipc_connections.mq_descriptor[(unsigned8)vmf_handle];
    if (NW_VMF_IPC_MQ_DESC_INVALID != mq_descriptor)
    {
        /* close the channel */
        if (NW_VMF_IPC_MQ_ERROR == mq_close(mq_descriptor))
        {
            NW_VMF_DEBUG_ERROR("nw_vmf_ipc: nw_vmf_ipc_close()-mq_close() failed - error=%d", NW_VMF_IPC_MQ_ERROR);
        }
        ipc_connections.mq_descriptor[(unsigned8)vmf_handle] = NW_VMF_IPC_MQ_DESC_INVALID;
        /* ignore this error        */
        ret_val = VMF_OK;
    }
    else
    {
        /* ignore this error        */
        /* channel is already closed */
        ret_val = VMF_OK;
    }


    return ret_val;
}

/*************************************************************************//**
 *
 *   Remove IPC channel from system
 *
 *   \param[in]     pchannel_name -- name of message queue
 *
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_destroy (vmf_handle_t vmf_handle)
{
    vmf_ret_t ret_val = VMF_ERROR;
    int iRet;

    NW_VMF_ARG_CHECK_RANGE ("nw_vmf_ipc_destroy - vmf_handle", vmf_handle, 0, MAX_IPC_CHANNELS-1);

    #if 0
    NW_VMF_DEBUG_INFO("nw_vmf_ipc_destroy: vmf_handle= %d, name=%s \n",vmf_handle,ipc_connections.channel_name[vmf_handle]); 
    #endif
    
    /* first try to close the channel */
    (void) nw_vmf_ipc_close(vmf_handle);

    if(strlen(ipc_connections.channel_name[(unsigned8)vmf_handle])>0)
    {
        /* unlink the channel */
        iRet = mq_unlink(ipc_connections.channel_name[(unsigned8)vmf_handle]);

        if (iRet != -1)
        {
            ret_val = VMF_OK;
        }
        else
        {
            #if 0
            NW_VMF_DEBUG_INFO("nw_vmf_ipc: nw_vmf_ipc_destroy-mq_unlink(%s) failed - errno=%d", ipc_connections.channel_name[vmf_handle],errno);
            #endif
            /* perror("unlink failed"); */
            /* do not report an error - normal usecase if queue was already destroyed */
            ret_val = VMF_OK;
        }
        ipc_connections.channel_name[(unsigned8)vmf_handle][0]=0;      /* delete name even if there was an error */
    }
    

    return ret_val;
}

/*************************************************************************//**
 *
 *   Send a message on the IPC channel. \n
 *   NOTE: in combination with nw_vmf_ipc_open this is non-blocking
 *
 *   \param[in]     vmf_handle   -- logic channel handle
 *                                  (from nw_vmf_ipc_open or nw_vmf_ipc_create)
 *   \param[in]     buffer       -- pointer to message to send
 *   \param[in]     number_bytes -- number of bytes to send
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_send ( vmf_handle_t vmf_handle,unsigned8 *buffer,unsigned16 number_bytes)
{
    vmf_ret_t       ret_val = VMF_OK;
    mqd_t           mq_descriptor;

    NW_VMF_ARG_CHECK_RANGE   ("nw_vmf_ipc_send - vmf_handle", vmf_handle, 0, MAX_IPC_CHANNELS-1);
    NW_VMF_ARG_CHECK_POINTER ("nw_vmf_ipc_send - buffer", buffer);
    NW_VMF_ARG_CHECK_SMALLER ("nw_vmf_ipc_send - number_bytes", number_bytes, VMF_IPC_MSG_SIZE_MAX);

    /* get the message queue descriptor from table and check */
    mq_descriptor = ipc_connections.mq_descriptor[(unsigned8)vmf_handle];
    if (NW_VMF_IPC_MQ_DESC_INVALID != mq_descriptor)
    {
        /* send the message */
        if (NW_VMF_IPC_MQ_ERROR == mq_send(mq_descriptor, (char *)buffer, number_bytes, 0))
        {
#if 0
            char    myTmp[255];
            /* errno can only be used for debugging purposes! */
            struct mq_attr  mqstat;
            mq_getattr(mq_descriptor,&mqstat );
/*
            NW_VMF_DEBUG_ERROR("ipc_send: handle %d \tmqstat.mq_curmsgs %d \n", vmf_handle, mqstat.mq_curmsgs);
            sprintf(myTmp,"mq_send failed pid=%d,vmf_handle=%d",getmypid(),vmf_handle);
            perror(myTmp);
*/            
            NW_VMF_DEBUG_ERROR("ipc_send: mq_send error - errno =%d!\n",errno);
#endif
            ret_val = VMF_ERR_IPC_SEND;
        }
    }
    else
    {
        NW_VMF_DEBUG_ERROR("ipc_send: invalid mq_descriptor (probably invalid handle)!\n");
        ret_val = VMF_ERR_INVALID_VMF_HANDLE;
    }
    
    /* remind high watermark */
    if (true == ipc_status_thread_is_running)
    {   
        struct mq_attr  mq_stat;
        unsigned16      mq_curmsgs;

        if (IPC_SERVER_THREAD == thread_id[(unsigned8)vmf_handle])
        {
            if (-1 != mq_getattr(mq_descriptor, &mq_stat))
            {
                mq_curmsgs = (unsigned16) mq_stat.mq_curmsgs;
            
                if (mq_curmsgs > high_watermark[(unsigned8)vmf_handle])
                {
                    high_watermark[(unsigned8)vmf_handle] = mq_curmsgs;
                }
            }
        }
    }

    return ret_val;
}

/*************************************************************************//**
 *
 *   receive a message on the IPC channel. \n
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
vmf_ret_t nw_vmf_ipc_receive (vmf_handle_t vmf_handle,unsigned16 buffer_size,
                              unsigned8 *buffer,unsigned16 *number_bytes)
{
    vmf_ret_t   ret_val = VMF_OK;
    mqd_t       mq_descriptor;
    signed32    mq_ret;


    NW_VMF_ARG_CHECK_RANGE ("nw_vmf_ipc_receive - vmf_handle", vmf_handle, 0, MAX_IPC_CHANNELS-1);
    NW_VMF_ARG_CHECK_POINTER ("nw_vmf_ipc_receive - buffer", buffer);
    NW_VMF_ARG_CHECK_POINTER ("nw_vmf_ipc_receive - number_bytes", number_bytes);

    /* get the message queue descriptor from table and check */
    mq_descriptor = ipc_connections.mq_descriptor[(unsigned8)vmf_handle];

    /* send new notification if this is the first byte in the buffer */
    /* since the last notification */
    if (ipc_connections.async_rx_connection[(unsigned8)vmf_handle])
    {
        if (!ipc_connections.was_notified[(unsigned8)vmf_handle])
        {
            /* what to do if we have an error here ?? */
            ret_val = nw_vmf_ipc_notify(vmf_handle);
            if ( VMF_OK != ret_val )
            {
                  /* second chance */
                  delay(1);
                  ret_val = nw_vmf_ipc_notify(vmf_handle);
                  if ( VMF_OK != ret_val )
                  {
                      return ret_val;
                  }
            }
            ipc_connections.was_notified[(unsigned8)vmf_handle] = true;
        }
    }

    if (NW_VMF_IPC_MQ_DESC_INVALID != mq_descriptor)
    {
        /* receive on queue */
        mq_ret = mq_receive(mq_descriptor, (char *)buffer, buffer_size, NULL);
        if (NW_VMF_IPC_MQ_ERROR == mq_ret)
        {
            *number_bytes = 0;
            /* handle error only if no async connection */
            if (!ipc_connections.async_rx_connection[(unsigned8)vmf_handle])
            {
            
                perror("mq_receive");
                NW_VMF_DEBUG_ERROR("ipc_receive: mq_receive error!\n");
                ret_val = VMF_ERR_IPC_RECEIVE;
            }
        }
        else
        {
            /* buffer_size is unsigned16 --> return cannot exceed unsigned16! */
            *number_bytes = (unsigned16)mq_ret;
        }
    }
    else
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_ipc_receive: invalid mq_descriptor (probably invalid handle)!\n");
        *number_bytes = 0;
        ret_val = VMF_ERR_INVALID_VMF_HANDLE;
    }

    if ((0 == *number_bytes) && (ipc_connections.async_rx_connection[(unsigned8)vmf_handle]))
    {
        ipc_connections.was_notified[(unsigned8)vmf_handle]= false;
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
 *                                  timeout of 0 means that the function 
 *                                  will return instantly
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_timed_receive (vmf_handle_t vmf_handle,unsigned16 buffer_size,
                                    unsigned8 *buffer,unsigned16 *number_bytes,
                                    unsigned16 ms_timeout)
{
    vmf_ret_t   ret_val = VMF_OK;
    mqd_t       mq_descriptor;
    signed32    mq_ret;

    NW_VMF_ARG_CHECK_RANGE   ("nw_vmf_ipc_timed_receive - vmf_handle", vmf_handle, 0, MAX_IPC_CHANNELS-1);
    NW_VMF_ARG_CHECK_POINTER ("nw_vmf_ipc_timed_receive - buffer", buffer);
    NW_VMF_ARG_CHECK_POINTER ("nw_vmf_ipc_timed_receive - number_bytes", number_bytes);

    /* get the message queue descriptor from table and check */
    mq_descriptor = ipc_connections.mq_descriptor[(unsigned8)vmf_handle];

    /* send new notification if this is the first byte in the buffer */
    /* since the last notification */
    if (ipc_connections.async_rx_connection[(unsigned8)vmf_handle])
    {
        if (!ipc_connections.was_notified[(unsigned8)vmf_handle])
        {
            /* what to do if we have an error here ?? */
            ret_val = nw_vmf_ipc_notify(vmf_handle);
            if ( VMF_OK != ret_val )
            {
                  /* second chance */
                  delay(1);
                  ret_val = nw_vmf_ipc_notify(vmf_handle);
                  if ( VMF_OK != ret_val )
                  {
                      return ret_val;
                  }
            }
            ipc_connections.was_notified[(unsigned8)vmf_handle] = true;
        }
    }

    if (NW_VMF_IPC_MQ_DESC_INVALID != mq_descriptor)
    {
        struct      timespec tm;
    
        /* get actual time and add timeout */
        if (0 == clock_gettime(CLOCK_REALTIME, &tm))
        {
            /* clock_gettime() returned with no error */
            if (ms_timeout > 0)
            {
                /* add ms_timeout to current time */
                tm.tv_sec  += ms_timeout / 1000;            /* ms / 1000    = seconds      */
                tm.tv_nsec +=(ms_timeout % 1000)*1000000;    /* ms * 1000000 = nano seconds  */
    
                /* handle possible tv_nsec overflow*/
                if (tm.tv_nsec >= 1000000000)
                {
                    tm.tv_sec  += tm.tv_nsec / 1000000000;
                    tm.tv_nsec %= 1000000000;
                }
            }
        }
        else
        {
            /* clock_gettime() returned with an error ! */
            tm.tv_sec  = ms_timeout / 1000;
            tm.tv_nsec =(ms_timeout % 1000)*1000000;
        }
        
        /* receive on queue (with timeout) */
        mq_ret = mq_timedreceive(mq_descriptor, (char *)buffer, buffer_size, NULL,&tm);
        if (NW_VMF_IPC_MQ_ERROR == mq_ret)
        {
            /* error or timeout */
            *number_bytes = 0;
            ret_val = VMF_OK;

            /* handle error only if no async connection */
            if (!ipc_connections.async_rx_connection[(unsigned8)vmf_handle])
            {
                if (errno != ETIMEDOUT)
                {
                    /* log no error because this may be just a timeout */
                    ret_val = VMF_ERR_IPC_RECEIVE;
                }
            }
        }
        else
        {
            /* buffer_size is unsigned16 --> return cannot exceed unsigned16! */
            *number_bytes = (unsigned16)mq_ret;
        }
    }
    else
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_ipc_timed_receive: invalid mq_descriptor (probably invalid handle)!\n");
        *number_bytes = 0;
        ret_val = VMF_ERR_INVALID_VMF_HANDLE;
    }

    if ((0 == *number_bytes) && (ipc_connections.async_rx_connection[(unsigned8)vmf_handle]))
    {
        ipc_connections.was_notified[(unsigned8)vmf_handle]= false;
    }

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
vmf_ret_t nw_vmf_ipc_create_channel_name (pid_t pid, unsigned8 cid,
                                          char *p_channel_name, unsigned8 buffer_size)
{
    vmf_ret_t   ret_val = VMF_OK;

    NW_VMF_ARG_CHECK_POINTER("nw_vmf_ipc_create_channel_name - p_channel_name", p_channel_name);
    NW_VMF_ARG_CHECK_BIGGER("nw_vmf_ipc_create_channel_name - pid", pid, 0);
    NW_VMF_ARG_CHECK_SMALLER("nw_vmf_ipc_create_channel_name - cid", cid, MAX_IPC_CLIENTS);
    NW_VMF_ARG_CHECK_BIGGER("nw_vmf_ipc_create_channel_name - buffer_size", buffer_size, IPC_CHANNEL_NAME_SIZE_MIN);

    (void) snprintf ((char *)p_channel_name, buffer_size, "/VMF_%08x_%x", pid, cid);

    return ret_val;
}





/*************************************************************************//**
 *
 *   register a queue name \n
 *
 *   \param         vmf_handle   -- logic channel handle
 *                                  (from nw_vmf_ipc_open or nw_vmf_ipc_create)
 *   \param         *p_name      -- pointer to connection name
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_register_queue_name(vmf_handle_t vmf_handle, const char* p_connection_name)
{
    vmf_ret_t     ret_val  = VMF_OK;;

    /* argument checks return on error! */
    NW_VMF_ARG_CHECK_RANGE   ("nw_vmf_ipc_register_queue_name - vmf_handle", vmf_handle, 0, MAX_IPC_CHANNELS-1);
    NW_VMF_ARG_CHECK_POINTER ("nw_vmf_ipc_register_queue_name - connection_name", p_connection_name);
    if (vmf_handle == VMF_HANDLE_INVALID)

    {
        NW_VMF_DEBUG_ERROR("pid=%d, VMF_ERR_OUT_OF_RANGE: vmf-handle=0",getmypid());
        return VMF_ERR_OUT_OF_RANGE;
    }

#if 0
    NW_VMF_DEBUG_INFO("pid=%d, %d: nw_vmf_ipc_register_queue_name(%s)", getmypid(), (int)vmf_handle, p_connection_name);
#endif    

    /* copy name to queue */
    nw_os_sstrncpy(&ipc_connections.client_name[vmf_handle][0], p_connection_name, MAX_NAME_LEN);
    return ret_val;
}




/******************************************************************************
    LOCAL FUNCTIONS
 ******************************************************************************/

/*************************************************************************//**
 *
 *   Obtain a free ipc handle. \n
 *   NOTE: - keep function short to make ipc_open re-entrant.
 *         - safe with mutex around the call of this function!
 *
 *   \param         none
 *   \return        next free IPC handle or vmf error type
 *
 ******************************************************************************/
vmf_handle_t nw_vmf_ipc_get_free_vmf_handle (void)
{
    vmf_handle_t    ret_val;
    unsigned8       count;

    count = ipc_connections.count;

    if (count < MAX_IPC_CHANNELS)
    {
        ipc_connections.count++;
        NW_VMF_DEBUG_PRINT(NW_VMF_DBG_LVL_IPC, NW_VMF_DBG_ASP_IPC,"pid = %d, nw_vmf_ipc_get_free_vmf_handle: handle=%d\n",getmypid(),count);
        ret_val = (vmf_handle_t)count;
    }
    else
    {
        /* try to find an already closed handle */
        for (count =0; count < MAX_IPC_CHANNELS ; count++)
        {
            if (NW_VMF_IPC_MQ_DESC_INVALID == ipc_connections.mq_descriptor[count])
            {
                /* found a free entry */
                ret_val = (vmf_handle_t)count;
                break;
            }
        }

        if (count >= MAX_IPC_CHANNELS)
        {
            NW_VMF_DEBUG_ERROR("pid = %d, nw_vmf_ipc_get_free_vmf_handle: out of IPC channels!\n",(int)getmypid());
            ret_val = (vmf_handle_t)VMF_ERR_OUT_OF_IPC_CHANNELS;
        }
    }


    return ret_val;
}

/*************************************************************************//**
 *
 *   Safe global access with mutex
 *
 *   \param         none
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_mutex_lock (void)
{
    vmf_ret_t ret_val;

    if (EOK == pthread_mutex_lock(&ipc_mutex))
    {
        ret_val = VMF_OK;
    }
    else
    {
        ret_val = VMF_ERR_IPC_MUTEX;
    }

    return ret_val;
}

/*************************************************************************//**
 *
 *   Remove the mutex set by nw_vmf_ipc_mutex_lock.
 *
 *   \param         none
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_mutex_unlock (void)
{
    vmf_ret_t ret_val;

    if (EOK == pthread_mutex_unlock(&ipc_mutex))
    {
        ret_val = VMF_OK;
    }
    else
    {
        ret_val = VMF_ERR_IPC_MUTEX;
    }

    return ret_val;
}



/*************************************************************************//**
 *
 *   set notify for client queue
 *
 *   \param         vmf_handle
 *   \return        vmf return type
 *
 ******************************************************************************/
static inline vmf_ret_t nw_vmf_ipc_notify (vmf_handle_t vmf_handle)
{
#define VMF_IPC_SET_NOTIFY_PRIO
    
#ifndef ENABLE_OSAL_ASYNC
    UNUSED_PARAM(vmf_handle);
    return ((vmf_ret_t)VMF_ERROR);
#else
    
    struct sigevent     sigNotify;
#ifdef VMF_IPC_SET_NOTIFY_PRIO
    struct sched_param  read_params;
    int                 read_policy;

    NW_VMF_ARG_CHECK_RANGE ("nw_vmf_ipc_notify - vmf_handle", vmf_handle, 0, MAX_IPC_CHANNELS-1);
    
    /* get the current priority */    
    (void) pthread_getschedparam( pthread_self(), &read_policy, &read_params );

    SIGEV_PULSE_INIT(&sigNotify,
            ipc_connections.coid[(unsigned8)vmf_handle],
            read_params.sched_priority,             /* inherit own priority  */
            OSAL_EVENT_SET_TYPE,
            ipc_connections.osal_event[(unsigned8)vmf_handle]);
#else
    NW_VMF_ARG_CHECK_RANGE ("nw_vmf_ipc_notify - vmf_handle", vmf_handle, 0, MAX_IPC_CHANNELS-1);
    
    SIGEV_PULSE_INIT(&sigNotify,
            ipc_connections.coid[(unsigned8)vmf_handle],
            SIGEV_PULSE_PRIO_INHERIT,              /* SIGEV_PULSE_PRIO_INHERIT is suspicious - may not work!  */
            OSAL_EVENT_SET_TYPE,
            ipc_connections.osal_event[(unsigned8)vmf_handle]);
#endif

    if (NW_VMF_IPC_MQ_ERROR == mq_notify (ipc_connections.mq_descriptor[(unsigned8)vmf_handle], &sigNotify))
    {
        NW_VMF_DEBUG_ERROR("pid=%d nw_vmf_ipc: nw_vmf_ipc_notify() - unable to set mq notify - errno=%d\n",(int)getmypid(),errno);
        return ((vmf_ret_t)VMF_ERR_IPC_NOTIFY);
    }
    return ((vmf_ret_t)VMF_OK);
#endif /* ENABLE_OSAL_ASYNC */

}

/****************************************************************************/
/*                  Helper Funktionen                                       */          
/****************************************************************************/


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



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_ipc_status_thread
 *
 *   Description:   ipc status handler thread
 *                  only used for debugging
 *
 *   \param         void
 *   \return        void
 *
 ******************************************************************************/
static void *nw_vmf_ipc_status_thread(void *pNoArg)
{

    struct mq_attr  mq_stat;
    unsigned16      mq_curmsgs;
    unsigned8       queue_count;
    unsigned8       list_of_sent_q_ids[MAX_IPC_CHANNELS] = {0};
    
    UNUSED_PARAM(pNoArg);

    ipc_status_thread_is_running = true;
    
    /* fill payload */
    while (true == ipc_status_thread_is_running)
    {
        delay(NW_VMF_STATUS_MSG_INTERVALL);

        /* send queue status */
        {
            vmf_ret_t   ret_val = VMF_OK;
            int         cnt = 0;
            vmf_ipc_status_queue_t                  payload = {0};
            VMF_VAR_BASIC_MSG_TYP(sizeof(payload))  vmf_basic_msg;
            queue_count = 0;

            for (cnt=0; cnt<ipc_connections.count; cnt++)
            {
                if (IPC_SERVER_THREAD == thread_id[cnt])
                {
                    if (NW_VMF_IPC_MQ_DESC_INVALID != ipc_connections.mq_descriptor[cnt])
                    {
                        if (-1 != mq_getattr(ipc_connections.mq_descriptor[cnt], &mq_stat))
                        {
                            mq_curmsgs = (unsigned16) mq_stat.mq_curmsgs;

                            if (high_watermark[cnt] > 0)
                            {
                                payload.queue_high_wm[queue_count] = high_watermark[cnt];
                                high_watermark[cnt] = 0;
                            }
                            else
                            {
                                /* number of elements in queue not changed since last transfer */
                                /* so send the current number of elements */
                                payload.queue_high_wm[queue_count] = mq_curmsgs;
                            }

                            list_of_sent_q_ids[cnt] = queue_count;
                            queue_count++;

#if 0

                            printf("%3d: Y \tID == %2d \tchannel: %s \tHW: %d \n", 
                                cnt, (int)queue_count, &ipc_connections.channel_name[cnt][0], payload.queue_high_wm[queue_count]);
#endif
                        }
                    }
                }
                else
                {
#if 0
                    printf("%3d: N \tchannel: %s \n", cnt, &ipc_connections.channel_name[cnt][0]);
#endif                    
                }
            }
            
            payload.version = 0;
            payload.num_queues = queue_count;

            /* transfer message */
            vmf_basic_msg.msg_base.base.msg_type  = MSG_TYPE_BASIC_MESSAGE;
            vmf_basic_msg.msg_base.base.pid       = 0;
            vmf_basic_msg.msg_base.base.client_id = 0;
            vmf_basic_msg.msg_base.base.vmf_mi_server_id = 0;
            vmf_basic_msg.msg_base.base.co_msg_type = 0;
            vmf_basic_msg.msg_base.id.group       = VMF_TRACE_IPC_DATA;
            vmf_basic_msg.msg_base.id.event       = VMF_IPC_STATUS_DATA_QUEUES;
            vmf_basic_msg.data.length             = sizeof(payload);

            nw_os_smemcpy(vmf_basic_msg.data.pl,sizeof(vmf_basic_msg.data.pl),(unsigned8*)&payload,vmf_basic_msg.data.length);
            ret_val = nw_vmf_ipc_send (IPC_SERVER_HANDLE,(unsigned8*)&vmf_basic_msg, sizeof(vmf_basic_msg));
            if (ret_val != VMF_OK)
            {
                NW_VMF_DEBUG_ERROR("nw_vmf_ipc: nw_vmf_ipc_send() failed (1)\n");
            }
            
        }

        /* send queue name */
        {
            vmf_ret_t   ret_val = VMF_OK;
            vmf_ipc_status_queue_name_t     payload;
            VMF_VAR_BASIC_MSG_TYP(sizeof(payload))   vmf_basic_msg;
            static unsigned8 current_q = 0;

            memset(&payload, 0, sizeof(payload));

            if (IPC_SERVER_THREAD == thread_id[current_q])
            {
                if (NW_VMF_IPC_MQ_DESC_INVALID != ipc_connections.mq_descriptor[current_q])
                {
                    payload.version = 0;
                    payload.queue = list_of_sent_q_ids[current_q];
                    payload.name_len = strlen(&ipc_connections.client_name[current_q][0]) + strlen(&ipc_connections.channel_name[current_q][0]) + 5;
                    if (payload.name_len  > 5)
                    {
                        (void) snprintf((char *)&payload.name, payload.name_len, "%s (%s)", 
                                         &ipc_connections.client_name[current_q][0], &ipc_connections.channel_name[current_q][0]);
                    }

                    /* transfer message */
                    vmf_basic_msg.msg_base.base.msg_type  = MSG_TYPE_BASIC_MESSAGE;
                    vmf_basic_msg.msg_base.base.pid       = 0;
                    vmf_basic_msg.msg_base.base.client_id = 0;
                    vmf_basic_msg.msg_base.base.vmf_mi_server_id = 0;
                    vmf_basic_msg.msg_base.base.co_msg_type = 0;
                    vmf_basic_msg.msg_base.id.group       = VMF_TRACE_IPC_DATA;
                    vmf_basic_msg.msg_base.id.event       = VMF_IPC_STATUS_DATA_QUEUE_NAME;
                    vmf_basic_msg.data.length             = sizeof(payload);

                    nw_os_smemcpy(vmf_basic_msg.data.pl,sizeof(vmf_basic_msg.data.pl),(unsigned8*)&payload,vmf_basic_msg.data.length);
                    ret_val = nw_vmf_ipc_send (IPC_SERVER_HANDLE,(unsigned8*)&vmf_basic_msg, sizeof(vmf_basic_msg));
                    if (ret_val != VMF_OK)
                    {
                        NW_VMF_DEBUG_ERROR("nw_vmf_ipc: nw_vmf_ipc_send() failed (2)\n");
                    }
                    
    #if 0
                    printf("queue id == %d \tclient name: %s \n"
                        , list_of_sent_q_ids[current_q], &ipc_connections.client_name[current_q][0]);
    #endif                
    #if 0
                    printf("queue id == %d \tqueue name: %s \tclient name: %s\n"
                        , list_of_sent_q_ids[current_q], &ipc_connections.channel_name[current_q][0], &ipc_connections.client_name[current_q][0]);
    #endif                
                }
            }

            current_q++;
            if (current_q > ipc_connections.count)
            {
                current_q = 0;
            }
        }

    }
    
    return NULL;
}



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_ipc_create_status_thread
 *
 *   Description:   create IPC status thread
 *
 *   \param         void
 *   \return        bool - true if OK
 *
 ******************************************************************************/
bool nw_vmf_ipc_create_status_thread(void)
{
    pthread_t th;
    pthread_attr_t  attr;
    int iRet;
	char Thread_name[100];

    /* set thread stack */
    (void) pthread_attr_init( &attr );
    if ( pthread_attr_setstacksize(&attr, VMF_NW_STACK_SIZE ) != 0 )
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_ipc_create_status_thread() - pthread_attr_setstacksize() failed");
    }

    iRet = pthread_create (&th  , &attr, nw_vmf_ipc_status_thread, NULL);
    (void) pthread_attr_destroy(&attr);
    if (iRet != 0)
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_ipc_create_status_thread() error! errno = %d\n",iRet);
        return false;
    }
#if ((defined(__QNX__) && (_NTO_VERSION >= 632)) || defined(__LINUX__))		
    /* Name the vmf-Logger thread */
	sprintf(Thread_name, "IPC-MQ-%d", th);
	nw_os_set_thread_name(th, Thread_name);    
#endif	

    return true;
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_ipc_stop_status_thread
 *
 *   Description:   set the proper flags to stop the IPC status thread
 *
 *   \param         void
 *   \return        void
 *
 ******************************************************************************/
void nw_vmf_ipc_stop_status_thread(void)
{
    ipc_status_thread_is_running = false;
    return;
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_ipc_is_status_thread_running
 *
 *   Description:   returns true / false 
 *
 *   \param         void
 *   \return        bool  -- true / false
 *
 ******************************************************************************/
bool nw_vmf_ipc_is_status_thread_running(void)
{
    return ipc_status_thread_is_running;
}


#undef __NW_VMF_IPC_C__
