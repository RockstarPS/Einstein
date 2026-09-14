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

  Module:               nw_vmf_ipc_shm.c
  Description:          shared memory ipc

  Project Scope:        Multiple platforms

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker (jbecke30@visteon.com)

  Compiler/Assembler:   Visual Studio
  Target Hardware:      Any

  *****************************************************************************/
#define __NW_VMF_IPC_C__


#define SHM_TEST
#define VMF_IPC_REUSE_HDL

#include <fcntl.h>
#include <stddef.h>
#include "os_types.h"
#include "nw_os_config.h"
#include "nw_vmf.h"
#include "nw_vmf_cfg.h"
#include "nw_vmf_ipc.h"
#include "intEvtDefs.h"

#ifndef O_CREATE
#define O_CREATE O_CREAT
#endif

#define ERROR_WAIT      (50)                            /* sleep time in case of error */

/* shared memory base addresses - needed for address calculation */
static  unsigned8  *server_base=NULL;                   /* shared memory base address of server */
static  unsigned8  *local_base =NULL;                   /* shared memory base address of this client */

static  ptrdiff_t   local_diff=0;                       /* add this diff to get the local address */
static  ptrdiff_t   server_diff=0;                      /* add this diff to get the server address */

static  vmf_msg_queue_shm_t *pvmf_msg_queue_shm = NULL; /*  shared memory of this process */

/* local function declaration  */
static vmf_ret_t nw_vmf_shm_ipc_init_queue (vmf_msg_queue_t     *queues,unsigned16 num_queues);
static vmf_ret_t nw_vmf_shm_ipc_init_pool1 (vmf_buffer_pool1_t  *pool,unsigned16 num_msgs, unsigned16 pool_msg_len);
static vmf_ret_t nw_vmf_shm_ipc_init_pool2 (vmf_buffer_pool2_t  *pool,unsigned16 num_msgs, unsigned16 pool_msg_len);
static vmf_ret_t nw_vmf_shm_ipc_init_pool3 (vmf_buffer_pool3_t  *pool,unsigned16 num_msgs, unsigned16 pool_msg_len);
static vmf_ret_t nw_vmf_shm_ipc_init_pool4 (vmf_buffer_pool4_t  *pool,unsigned16 num_msgs, unsigned16 pool_msg_len);
static vmf_ret_t nw_vmf_shm_ipc_init_pool_s(vmf_buffer_poolS_t  *pool,unsigned16 num_msgs, unsigned16 pool_msg_len);

static vmf_ret_t nw_vmf_shm_ipc_open_shm   (vmf_msg_queue_shm_t** pp_shm);
static vmf_ret_t nw_vmf_shm_ipc_create_shm (vmf_msg_queue_shm_t** pp_shm);
static vmf_ret_t nw_vmf_shm_ipc_wait_valid (vmf_msg_queue_shm_t* pp_shm);
static vmf_ret_t nw_vmf_shm_ipc_store_channel_name(vmf_msg_queue_t *queues, vmf_handle_t vmf_handle,char *channel_name);

static vmf_handle_t nw_vmf_ipc_get_free_vmf_handle (void);
static vmf_handle_t nw_vmf_shm_ipc_get_vmf_handle(vmf_msg_queue_t  *queues,char *channel_name);
static void  nw_vmf_shm_debug_info(vmf_msg_queue_shm_t* pshm);
unsigned nw_vmf_shm_ipc_get_max_client_id(vmf_msg_queue_shm_t *pshm);

static unsigned32 getmypid(void);

static void nw_vmf_HexDump  (char *chPrefixText,            /*!< INPUT pointer to prefix text */
                             unsigned8 *u8mem,              /*!< INPUT pointer to data to be displayedt */
                             unsigned length);
static vmf_ret_t        nw_vmf_ipc_clean_recources          (void);

bool                    ipc_status_thread_is_running = false;
static void             *nw_vmf_ipc_shm_status_thread       (void *pNoArg);

/***************************************************************************//**
*    global ipc functions
 ******************************************************************************/



/**************************************************************************//**
 *
 *   pre-init ipc
 *
 *   \param[in]     void
 *   \return        void
 ******************************************************************************/
void nw_vmf_ipc_pre_init(void)
{
    shm_unlink(VMF_IPC_SHM);
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
    vmf_ret_t   ret_val = VMF_OK;

    NW_VMF_SHM_IPC_INFO("info: nw_vmf_ipc_init()");

    if (remove_ressources)
    {
        NW_VMF_SHM_IPC_INFO("info: nw_vmf_ipc_init() remove_ressources=true");

        /* called by server */
        (void)nw_vmf_ipc_clean_recources();

        /* create the shm */
        ret_val = nw_vmf_shm_ipc_create_shm(&pvmf_msg_queue_shm);

        if (VMF_OK == ret_val)
        {
            ret_val = nw_vmf_shm_ipc_init(pvmf_msg_queue_shm);
            if (VMF_OK != ret_val)
            {
                NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_init: nw_vmf_shm_ipc_init() failed with %d",getmypid(),ret_val);
            }
        }
        else
        {
            NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_init: nw_vmf_shm_ipc_create_shm() failed",getmypid());
        }
    }
    else
    {
        /* called by a client */
        /* open the shm */
        unsigned16 timeout=0;

        NW_VMF_SHM_IPC_INFO("info: nw_vmf_ipc_init() remove_ressources=false");

        /* try to open shm until timeout */
        while (timeout < SHM_VALID_TIMEOUT)
        {
            ret_val = nw_vmf_shm_ipc_open_shm(&pvmf_msg_queue_shm);
            if (VMF_OK == ret_val)
            {
                break;
            }
            delay(SHM_SOME_TIME);
            timeout += SHM_SOME_TIME;
        }

        if (VMF_OK != ret_val)
        {
            NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_init: timeout opening shm",getmypid());
        }

        if (VMF_OK == ret_val)
        {
            /* wait until shm is valid */
            ret_val = nw_vmf_shm_ipc_wait_valid(pvmf_msg_queue_shm);
            if (VMF_OK != ret_val)
            {
                NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_init: nw_vmf_shm_ipc_wait_valid failed with %d",getmypid(),ret_val);
            }
        }

        if (VMF_OK == ret_val)
        {
            /* get shared memory base address -> move to open_shm function */
            local_base  = (unsigned8 *)&(pvmf_msg_queue_shm->shm_server_base);
            server_base = (unsigned8 *)pvmf_msg_queue_shm->shm_server_base;

            NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_ipc_init() local_base =%p",getmypid(),local_base);
            NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_ipc_init() server_base=%p",getmypid(),server_base);

            local_diff  = local_base-server_base;
            server_diff = server_base-local_base;
        }
    }

    return ret_val;
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
    vmf_error_t     ret_val = VMF_OK;
    vmf_handle_t    vmf_handle=0;


    /* argument check */
    if (NULL == channel_name)
    {
        NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_ipc_open: channel name = NULL",getmypid());
        return (VMF_ERR_NULL_POINTER);
    }
    else if (NULL == pvmf_msg_queue_shm)
    {
        /* check if shared memory already mapped */
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_open: shared memory not mapped",getmypid());
        return (VMF_ERROR);
    }

    NW_VMF_SHM_IPC_INFO("pid=%d, info: nw_vmf_ipc_open(%s)", getmypid(),channel_name);

    /* check if shared memory is valid */
    ret_val = nw_vmf_shm_ipc_wait_valid(pvmf_msg_queue_shm);
    if (VMF_OK != ret_val)
    {
        return ret_val;
    }

    NW_VMF_SHM_IPC_INFO("info: nw_vmf_ipc_open(%s)",channel_name);

    /* search the handle for this queue */
    vmf_handle = nw_vmf_shm_ipc_get_vmf_handle(pvmf_msg_queue_shm->queues,channel_name);

    if (vmf_handle < 0)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_open(%s): unknown channel name",getmypid(),channel_name);
    }
    else
    {
        /* check if queue is connected */
        if (pvmf_msg_queue_shm->queues[vmf_handle].in_use == false)
        {
            NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_open(%s): queue not connected vmf_handle=%d",getmypid(),channel_name,vmf_handle);
            ret_val = VMF_ERR_ROUTER_SENDER_HANDLE_NOT_FOUND;
        }
        else
        {
        /* queue for this channel found */
        /* set tx blocking for this queue */
        ret_val = nw_vmf_shm_ipc_queue_set_blocking(pvmf_msg_queue_shm,vmf_handle,true,block_on_send);
        if (VMF_OK != ret_val)
        {
            NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_open: nw_vmf_shm_ipc_queue_set_blocking failed",getmypid());
        }
        NW_VMF_SHM_IPC_INFO("info3: nw_vmf_ipc_open() num-queue[0]=%d",pvmf_msg_queue_shm->queues[0].num);
        NW_VMF_SHM_IPC_INFO2("pid=%d, info: nw_vmf_ipc_open(%s) ipc_handle=%d", getmypid(),channel_name,vmf_handle);
        }
    }

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
    vmf_ret_t           ret_val = VMF_OK;
    vmf_handle_t        vmf_handle = 0;
    unsigned32          num_name = 0;


    /* argument check */
    if (NULL == channel_name)
    {
        NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_ipc_create: channel name=NULL",getmypid());
        return (VMF_ERR_NULL_POINTER);
    }
    else if (NULL == pvmf_msg_queue_shm)
    {
        /* check if shared memory already mapped */
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_create: shared memory not mapped",getmypid());
        return (VMF_ERROR);
    }

    NW_VMF_SHM_IPC_INFO("pid=%d, info: nw_vmf_ipc_create(%s)", getmypid(),channel_name);

    /* resize arguments to limits if out of bounds */
    if (queue_size < VMF_IPC_QUEUE_SIZE_MIN)
    {
        NW_VMF_SHM_IPC_INFO("pid = %d, nw_vmf_ipc_create: queue size too small --> set to minimum (=%d)\n",getmypid(), VMF_IPC_QUEUE_SIZE_MIN);
        queue_size = VMF_IPC_QUEUE_SIZE_MIN;
    }
    else if ((queue_size > VMF_IPC_QUEUE_SIZE_MAX) && (queue_size != VMF_SPY_QUEUE_SIZE) && (queue_size != VMF_TRACE_QUEUE_SIZE) && (queue_size != VMF_IPC_QUEUE_SIZE_SERVER))
    {
        /* only the VMF spy and VMF trace are allowed to use bigger queues! */
        NW_VMF_SHM_IPC_INFO("pid = %d, nw_vmf_ipc_create: queue size too big --> set to maximum (=%d)\n",getmypid(), VMF_IPC_QUEUE_SIZE_MAX);
        queue_size = VMF_IPC_QUEUE_SIZE_MAX;
    }
    else
    {
        /* nothing to do here. */
    }

    NW_VMF_SHM_IPC_INFO("info: nw_vmf_ipc_create() channel_name=%s, queue_size=%d",channel_name,queue_size);

    num_name = atoi(channel_name);          /* numerical representation of channel name */

    /* shm was already created in nw_vmf_ipc_init - so not mutch to do here */
    if (IPC_SERVER_CHANNEL_NAME_NUM == num_name)
    {
        /* this is the server queue */
        vmf_handle = IPC_SERVER_HANDLE;
        if (VMF_OK == ret_val)
        {
            ret_val = nw_vmf_shm_ipc_store_channel_name(pvmf_msg_queue_shm->queues,vmf_handle,channel_name);
        }
        if (VMF_OK == ret_val)
        {
            ret_val = nw_vmf_shm_ipc_queue_set_max_num(pvmf_msg_queue_shm,vmf_handle,queue_size);           /* set tx blocking for this queue */
        }
        else
        {
            NW_VMF_SHM_IPC_ERROR("error: nw_vmf_ipc_create() nw_vmf_shm_ipc_store_channel_name() failed");
        }
    }
    else
    {
        /* this is a client */
        vmf_handle = nw_vmf_ipc_get_free_vmf_handle();
        if (vmf_handle < 0)
        {
            /* we got an erro */
            NW_VMF_SHM_IPC_ERROR("error: nw_vmf_ipc_create() nw_vmf_ipc_get_free_vmf_handle() failed");
        }
        else
        {
            if (VMF_OK == ret_val)
            {
                ret_val = nw_vmf_shm_ipc_store_channel_name(pvmf_msg_queue_shm->queues,vmf_handle,channel_name);
            }
            if (VMF_OK == ret_val)
            {
                ret_val = nw_vmf_shm_ipc_queue_set_max_num(pvmf_msg_queue_shm,vmf_handle,queue_size);
            }
            else
            {
                NW_VMF_SHM_IPC_ERROR("error: nw_vmf_ipc_create() nw_vmf_shm_ipc_store_channel_name() failed");
            }
        }
    }
    if (ret_val != VMF_OK)
    {
        NW_VMF_SHM_IPC_ERROR("error: nw_vmf_ipc_create() error retval=%d",ret_val);
        vmf_handle = (vmf_handle_t)ret_val;
    }
    else
    {
        NW_VMF_SHM_IPC_INFO2("info: nw_vmf_ipc_create() channel_name=%s, queue_size=%d, ipc_handle=%d",channel_name,queue_size,vmf_handle);
    }

    return vmf_handle;
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
vmf_handle_t nw_vmf_ipc_create_async (char *channel_name, unsigned16 queue_size,
                                      unsigned16 msg_size, unsigned32 coid,
                                      unsigned32 async_event)
{
    NW_VMF_SHM_IPC_ERROR("nw_vmf_ipc_create_async: NOT SUPPORTED!!!");
    return VMF_ERR_NOT_SUPPORTED;
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
    /* no need to do something */
    NW_VMF_SHM_IPC_INFO2("info: nw_vmf_ipc_close ipc_handle=%d",vmf_handle);
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
    NW_VMF_SHM_IPC_INFO2("info: nw_vmf_ipc_destroy ipc_handle=%d",vmf_handle);

    /* free all messages in this queue and free the queue */
    (void)nw_vmf_shm_ipc_queue_free_all_buff(pvmf_msg_queue_shm, vmf_handle);
    nw_vmf_shm_debug_info(pvmf_msg_queue_shm);

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
static vmf_ret_t nw_vmf_ipc_clean_recources (void)
{
    return VMF_OK;
}






/* REMOVE!!! */
unsigned16 vmf_ipc_get_current_count(vmf_handle_t vmf_handle)
{
    if (vmf_handle >= NW_VMF_SHM_IPC_MAX_QUEUES)
    {
        fprintf(stderr,"pid=%d, vmf_ipc_get_current_count: invalid vmf-handle=%d",getmypid(),vmf_handle);
        return 0;
    }
//    fprintf(stderr, "vmf_ipc_get_current_count: handle = %d, in_use=%d\n", vmf_handle, (int) pvmf_msg_queue_shm->queues[vmf_handle].in_use);
    return pvmf_msg_queue_shm->queues[vmf_handle].num;
}


/* REMOVE!!! */
unsigned16 vmf_ipc_get_high_watermark(vmf_handle_t vmf_handle)
{
    if (vmf_handle >= NW_VMF_SHM_IPC_MAX_QUEUES)
    {
        fprintf(stderr,"pid=%d, vmf_ipc_get_high_watermark: invalid vmf-handle=%d",getmypid(),vmf_handle);
        return 0;
    }
    return pvmf_msg_queue_shm->queues[vmf_handle].high_wm;
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
vmf_ret_t nw_vmf_ipc_send (vmf_handle_t vmf_handle, unsigned8 *buffer, unsigned16 number_bytes)
{
    vmf_ret_t  ret_val = VMF_OK;

    NW_VMF_SHM_IPC_INFO2("pid=%d, ipc_handle=%d, info: nw_vmf_ipc_send() number_bytes=%d",getmypid(),vmf_handle,number_bytes);

#if 0
    if (255 == vmf_handle)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, vmf_handle=%d, info: nw_vmf_ipc_send() number_bytes=%d",getmypid(),vmf_handle,number_bytes);
        nw_vmf_HexDump("nw_vmf_ipc_send ",buffer,number_bytes);
    }
#endif

    /* argument check */
    if (vmf_handle >= NW_VMF_SHM_IPC_MAX_QUEUES)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_send: invalid vmf-handle=%d",getmypid(),vmf_handle);
        ret_val =  VMF_ERR_OUT_OF_RANGE;
    }
    else if (NULL == buffer)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_send: buffer=NULL",getmypid());
        ret_val = VMF_ERR_NULL_POINTER;
    }
    else if (number_bytes > MAX_VMF_DATA_LEN)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_send: number of tx bytes > MAX_VMF_DATA_LEN",getmypid());
        ret_val =  VMF_ERR_OUT_OF_RANGE;
    }
    else if (0 == number_bytes)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_send: number of tx bytes = 0",getmypid());
        ret_val =  VMF_ERR_OUT_OF_RANGE;
    }
    else if (NULL == pvmf_msg_queue_shm)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_send: shared memory not mapped",getmypid());
        ret_val = VMF_ERR_SHM_IPC_SHM_INVALID;
    }
    else if (pvmf_msg_queue_shm->queues[vmf_handle].in_use == false)
    {
        NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_ipc_send: queue not connected vmf_handle=%d",getmypid(),vmf_handle);
        ret_val = VMF_ERR_ROUTER_SENDER_HANDLE_NOT_FOUND;
    }
    else
    {
        /* all arguments OK */
        vmf_buffer_pool_msg_t   *ptx_buffer=NULL;
        ret_val = VMF_ERROR;
        int tries=0;

        /* get a message buffer */
        /* if queue is set to tx-blocking then wait infinite for a buffer */
        NW_VMF_SHM_IPC_INFO("pid=%d, vmf_handle=%d, info: nw_vmf_ipc_send() waiting for buffer with len=%d",getmypid(),vmf_handle,number_bytes);
        while (ret_val != VMF_OK)
        {
            ret_val = nw_vmf_shm_ipc_pool_get_buff(pvmf_msg_queue_shm,vmf_handle,&ptx_buffer,number_bytes);
            if (ret_val != VMF_OK)
            {
                NW_VMF_SHM_IPC_INFO("vmf_handle=%d, info: nw_vmf_ipc_send() no buffer from nw_vmf_shm_ipc_pool_get_buff",vmf_handle);
#ifdef VMF_IPC_SHM_NO_BLOCK_ON_GETBUFF
                if (false == pvmf_msg_queue_shm->queues[vmf_handle].tx_blocking)
                {
                    NW_VMF_SHM_IPC_INFO("vmf_handle=%d, info: nw_vmf_ipc_send() no buffer  - break",vmf_handle);
                    /* no retry if queue is not set to tx-blocking*/
                    break;
                }
                else
#endif
                {
                    tries++;
                    NW_VMF_SHM_IPC_INFO("vmf_handle=%d, info: nw_vmf_ipc_send() no buffer - wait - tries = %d",vmf_handle,tries);
                    delay(tries);   /* wait some time for a free buffer */
                    if (tries >= 2)
                    {
                        NW_VMF_SHM_IPC_INFO("vmf_handle=%d, info: nw_vmf_ipc_send() no buffer after %d retries - want %d size buffer",vmf_handle,tries,number_bytes);
                        if (IPC_SERVER_HANDLE != vmf_handle)
                        {
                            /* no endless blocking if this is the server */
                            break;
                        }
                    }
                }
            }
        }

        if (VMF_OK == ret_val)
        {
            if (tries > 0)
            {
                NW_VMF_SHM_IPC_INFO("vmf_handle=%d, info: nw_vmf_ipc_send() got buffer with len=%d after %d tries",vmf_handle,ptx_buffer->pool_msg_len,tries);
            }

            /* write message to buffer and then to queue */
            ptx_buffer->msg_payload_len = number_bytes;
            memcpy(ptx_buffer->shm_msg,buffer,number_bytes);
            ret_val = nw_vmf_shm_ipc_queue_write(pvmf_msg_queue_shm,ptx_buffer,vmf_handle);
        }
        else
        {
            /* we got an error */
            NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_send: nw_vmf_shm_ipc_pool_get_buff() failed after %d tries",getmypid(),tries);
        }

        /* free the buffer in the case on an error */
        if ((VMF_OK != ret_val) && (NULL != ptx_buffer))
        {
            if (VMF_OK != nw_vmf_shm_ipc_pool_free_buff(pvmf_msg_queue_shm,ptx_buffer))
            {
                NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_send: nw_vmf_shm_ipc_pool_free_buff() failed!!!!!",getmypid());
            }
        }
    }

    return ret_val;
}





/*************************************************************************//**
 *
 *   Send a message on the IPC channel. \n
 *   NOTE: the buffer argument is a pointer to the raw ipc message that is owned by the ipc
 *         the ipc will increment the ref_counter of the buffer during queue_write
 *
 *   \param[in]     vmf_handle   -- logic channel handle
 *                                  (from nw_vmf_ipc_open or nw_vmf_ipc_create)
 *   \param[in]     buffer       -- pointer to the raw ipc message
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_send_raw (vmf_handle_t vmf_handle, unsigned8 *p_buffer)
{
    vmf_ret_t  ret_val = VMF_OK;

    NW_VMF_SHM_IPC_INFO("vmf_handle=%d, info: nw_vmf_ipc_send_raw()",vmf_handle);

    if (vmf_handle >= NW_VMF_SHM_IPC_MAX_QUEUES)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_send_raw: invalid vmf-handle=%d",getmypid(),vmf_handle);
        ret_val =  VMF_ERR_OUT_OF_RANGE;
    }
    else if (NULL == p_buffer)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_send_raw: buffer = NULL",getmypid());
        ret_val = VMF_ERR_NULL_POINTER;
    }
    else
    {
        /* write the buffer to the queue */
        ret_val = nw_vmf_shm_ipc_queue_write(pvmf_msg_queue_shm,(vmf_buffer_pool_msg_t *)p_buffer,vmf_handle);
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
 *                                  timeout of 0 (==IPC_SOCKET_NO_TIMEOUT)
 *                                  is a very big timeout!!
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_ipc_timed_receive (vmf_handle_t vmf_handle,unsigned16 buffer_size,
                                    unsigned8 *buffer,unsigned16 *p_number_bytes,
                                    unsigned16 ms_timeout)
{
    vmf_ret_t           ret_val = VMF_OK;

    NW_VMF_SHM_IPC_INFO("vmf_handle=%d, info: nw_vmf_ipc_timed_receive(%d)",vmf_handle,ms_timeout);

    /* argument check */
    if (vmf_handle >= NW_VMF_SHM_IPC_MAX_QUEUES)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_timed_receive: invalid vmf-handle=%d",getmypid(),vmf_handle);
        ret_val =  VMF_ERR_OUT_OF_RANGE;
    }
    else if (NULL == buffer)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_timed_receive: buffer=NULL",getmypid());
        ret_val = VMF_ERR_NULL_POINTER;
    }
    else if (0 == buffer_size)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_timed_receive: buffer-size=0",getmypid());
        ret_val =  VMF_ERR_OUT_OF_RANGE;
    }
    else if (NULL == pvmf_msg_queue_shm)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_timed_receive: shared memory not mapped",getmypid());
        ret_val = VMF_ERR_SHM_IPC_SHM_INVALID;
    }
    else
    {
        vmf_buffer_pool_msg_t *prx_buffer = NULL;

        ret_val = nw_vmf_shm_ipc_queue_read(pvmf_msg_queue_shm,&prx_buffer,vmf_handle,ms_timeout);
        if (VMF_OK == ret_val)
        {
            NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_ipc_timed_receive: nw_vmf_shm_ipc_queue_read() OK .buff=%p",getmypid(),prx_buffer);
            /* read queue ok */
            /* copy data to destination buffer */
            if (buffer_size >= prx_buffer->msg_payload_len)
            {
                *p_number_bytes = prx_buffer->msg_payload_len;
                memcpy(buffer,prx_buffer->shm_msg,prx_buffer->msg_payload_len);
            }
            else
            {
                /* rx buffer to small */
                /* to prevent locking of this queue this message will be discarded */
                NW_VMF_SHM_IPC_ERROR("pid=%d,        nw_vmf_ipc_timed_receive: rx buffer to small",getmypid());
                NW_VMF_SHM_IPC_ERROR("vmf_handle=%d, nw_vmf_ipc_timed_receive: payload_len in Q=%d",vmf_handle,prx_buffer->msg_payload_len);
                NW_VMF_SHM_IPC_ERROR("               nw_vmf_ipc_timed_receive: buffer_size=%d",buffer_size);

                /* copy the part of the message into the buffer that will fit */
                /* only for debug */
                memcpy(buffer,prx_buffer->shm_msg,buffer_size);
                ret_val = VMF_ERR_BUFFER_TO_SMALL;
            }
            /* free buffer */
            NW_VMF_SHM_IPC_INFO("pid=%d,vmf_handle=%d, nw_vmf_ipc_timed_receive: free %p",getmypid(),vmf_handle,prx_buffer);
            (void)nw_vmf_shm_ipc_pool_free_buff(pvmf_msg_queue_shm,prx_buffer);
            nw_vmf_shm_debug_info(pvmf_msg_queue_shm);
        }
        else
        {
            /* read queue failed or timeout */
            NW_VMF_SHM_IPC_INFO("%dms, pid=%d, nw_vmf_ipc_timed_receive: nw_vmf_shm_ipc_queue_read(timeout=%d) failed",nw_os_cfg_get_ms_time(),getmypid(),ms_timeout);
            *p_number_bytes = 0;
            
            if (VMF_ERR_SHM_IPC_EAGAIN == ret_val)
            {
                /* Timeout! */
                ret_val = VMF_OK;
            }
            else
            {
                ret_val = VMF_ERR_IPC_RECEIVE;
            }
            nw_vmf_shm_debug_info(pvmf_msg_queue_shm);
        }
        NW_VMF_SHM_IPC_INFO2("ipc_handle=%d, info: nw_vmf_ipc_timed_receive(timeout=%d) number of bytes=%d",vmf_handle,ms_timeout,*p_number_bytes);
    }

    return (ret_val);
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
vmf_ret_t nw_vmf_ipc_receive (vmf_handle_t vmf_handle,unsigned16 buffer_size,
                              unsigned8 *buffer,unsigned16 *pnumber_bytes)
{
    vmf_ret_t           ret_val = VMF_OK;

    ret_val = nw_vmf_ipc_timed_receive(vmf_handle,buffer_size,buffer,pnumber_bytes,0);
    // if (0 == vmf_handle) NW_VMF_SHM_IPC_ERROR("vmf_handle=%d, info: !!!!!!! nw_vmf_ipc_receive() ret=%d, number_bytes=%d",vmf_handle,ret_val,*pnumber_bytes);

    return (ret_val);
}



/*************************************************************************//**
 *
 *   Receive a message on the IPC channel. \n
 *   NOTE:  the function will return a pointer to the raw ipc message
 *          this pointer has to be freed later!
 *
 *   \param[in]     vmf_handle   -- logic channel handle
 *                                  (from nw_vmf_ipc_open or nw_vmf_ipc_create)
 *   \return        vmf return type
 *
 ******************************************************************************/
unsigned8 *nw_vmf_ipc_receive_raw (vmf_handle_t vmf_handle)
{
    vmf_buffer_pool_msg_t   *prx_buffer=NULL;
    vmf_ret_t               ret_val = VMF_OK;

    NW_VMF_SHM_IPC_INFO("vmf_handle=%d, info: nw_vmf_ipc_receive_raw()",vmf_handle);

    if (vmf_handle >= NW_VMF_SHM_IPC_MAX_QUEUES)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_receive_ptr: invalid vmf-handle=%d",getmypid(),vmf_handle);
        prx_buffer =  NULL;
    }
    else
    {
        ret_val = nw_vmf_shm_ipc_queue_read(pvmf_msg_queue_shm,&prx_buffer,vmf_handle,0);
        if (VMF_OK != ret_val)
        {
            prx_buffer = NULL;
        }
    }

    return ((unsigned8*)prx_buffer);
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

    if (NULL == p_channel_name)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, cid=%d, nw_vmf_ipc_create_channel_name: p_channel_name=NULL",getmypid(),cid);
        return VMF_ERR_OUT_OF_RANGE;
    }

    snprintf (p_channel_name, buffer_size,"%u",(pid<<8)+cid);
    NW_VMF_SHM_IPC_INFO("pid=%d, cid=%d, nw_vmf_ipc_create_channel_name: =%s",pid,cid,p_channel_name);
    return ret_val;
}



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
static vmf_handle_t nw_vmf_ipc_get_free_vmf_handle (void)
{
    vmf_handle_t    ret_val=(vmf_handle_t)VMF_ERROR;;
    vmf_handle_t    hdl;

    NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_ipc_get_free_vmf_handle()",getmypid());

    if(NULL == pvmf_msg_queue_shm)
    {
        ret_val = VMF_ERR_SHM_IPC_SHM_INVALID;
    }

    hdl = nw_vmf_shm_ipc_get_free_hdl(pvmf_msg_queue_shm);
    if (VMF_HANDLE_INVALID == hdl)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_get_free_vmf_handle: out of ipc-handles",getmypid());
        ret_val = (vmf_handle_t)VMF_ERR_OUT_OF_IPC_CHANNELS;
    }
    else
    {
        ret_val = hdl;
    }
    NW_VMF_SHM_IPC_INFO2("pid=%d, nw_vmf_ipc_get_free_vmf_handle() ipc_handle=%d",getmypid(),hdl);

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
vmf_error_t nw_vmf_ipc_register_queue_name(vmf_handle_t vmf_handle,const char* p_name)
{
    vmf_error_t     ret_val  = VMF_OK;;
    vmf_msg_queue_t *p_msq_q = NULL;

    /* argument check */
    if(NULL == p_name)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_register_queue_name: name = NULL",getmypid());
        ret_val = VMF_ERR_NULL_POINTER;
    }

    NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_ipc_register_queue_name(%s)",getmypid(),p_name);

    if (vmf_handle >= NW_VMF_SHM_IPC_MAX_QUEUES)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, VMF_ERR_OUT_OF_RANGE: invalid vmf-handle=%d",getmypid(),vmf_handle);
        ret_val =  VMF_ERR_OUT_OF_RANGE;
    }
    else if (vmf_handle == VMF_HANDLE_INVALID)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, VMF_ERR_OUT_OF_RANGE: vmf-handle=0",getmypid());
        ret_val = (vmf_handle_t)VMF_ERR_OUT_OF_RANGE;
    }

    if (VMF_OK == ret_val)
    {
        /* copy name to queue */
        p_msq_q = &(pvmf_msg_queue_shm->queues[vmf_handle]);
        nw_os_sstrncpy(p_msq_q->name, p_name, VMF_IPC_QNAME_LEN);
    }
    else
    {
        /* no code */
    }

    return ret_val;
}







/*************************************************************************//**
 *
 *   free a raw ipc buffer \n
 *   NOTE: - a buffer owned by the ipc will be freed
 *
 *   \param         pointer to ipc buffer
 *   \return        vmf error type
 *
 ******************************************************************************/
vmf_error_t nw_vmf_ipc_pool_free_buff_raw(unsigned8 *p_buffer)
{
    vmf_error_t ret_val = VMF_OK;

    NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_ipc_pool_free_buff_raw()",getmypid());

    /* argument check */
    if(NULL == p_buffer)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_ipc_pool_free_buff_raw: p_buffer = NULL",getmypid());
        ret_val = VMF_ERR_NULL_POINTER;
    }

    ret_val = nw_vmf_shm_ipc_pool_free_buff(pvmf_msg_queue_shm,(vmf_buffer_pool_msg_t *)p_buffer);

    return ret_val;
}




/***************************************************************************//**
*    global shm functions
 ******************************************************************************/


/***************************************************************************//**
 *   init message shared memory
 *
 *   \param[in]     pointer to shared memory
 *   \return        vmf_error_t
 ******************************************************************************/
vmf_ret_t nw_vmf_shm_ipc_init (vmf_msg_queue_shm_t *pshm)
{
    vmf_ret_t   ret_val = VMF_OK;
    int         error = 0;

    NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_ipc_init()",getmypid());

    /* argument check */
    if (NULL == pshm)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_shm_ipc_init() - NULLPOINTER",getmypid());
        return (VMF_ERR_NULL_POINTER);
    }

    /* mark shm as invalid*/
    pshm->shm_valid = 0;

    /* store address-base*/
    server_base = (void *)&(pshm->shm_server_base);
    pshm->shm_server_base = server_base;

    /* init shm */
    pshm->max_client_id = 0;
    pshm->num_client_ids = 0;


    /* init message pools */
    if (VMF_OK == ret_val)
    {
        ret_val =  nw_vmf_shm_ipc_init_pool_s (&(pshm->pools),NW_VMF_BUFFER_POOLS_MSG_NUM,NW_VMF_BUFFER_POOLS_PAYLOAD_LEN);
        pshm->pools.nextpool = (vmf_buffer_pool_t*)&pshm->pool1;

        if (ret_val != VMF_OK)
        {
            NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_shm_ipc_init() - nw_vmf_shm_ipc_init_pool_s failed with %d",getmypid(),ret_val);
        }
    }

    if (VMF_OK == ret_val)
    {
        ret_val =  nw_vmf_shm_ipc_init_pool1 (&(pshm->pool1),NW_VMF_BUFFER_POOL1_MSG_NUM,NW_VMF_BUFFER_POOL1_PAYLOAD_LEN);
        pshm->pool1.nextpool = (vmf_buffer_pool_t*)&pshm->pool2;
    }

    if (VMF_OK == ret_val)
    {
        ret_val =  nw_vmf_shm_ipc_init_pool2 (&(pshm->pool2),NW_VMF_BUFFER_POOL2_MSG_NUM,NW_VMF_BUFFER_POOL2_PAYLOAD_LEN);
        pshm->pool2.nextpool = (vmf_buffer_pool_t*)&pshm->pool3;
    }

    if (VMF_OK == ret_val)
    {
        ret_val =  nw_vmf_shm_ipc_init_pool3 (&(pshm->pool3),NW_VMF_BUFFER_POOL3_MSG_NUM,NW_VMF_BUFFER_POOL3_PAYLOAD_LEN);
        pshm->pool3.nextpool = (vmf_buffer_pool_t*)&pshm->pool4;
    }

    if (VMF_OK == ret_val)
    {
        ret_val =  nw_vmf_shm_ipc_init_pool4 (&(pshm->pool4),NW_VMF_BUFFER_POOL4_MSG_NUM,NW_VMF_BUFFER_POOL4_PAYLOAD_LEN);
        pshm->pool4.nextpool = NULL;
    }

    /* init all queues mux */
    error = nw_sem_init(&(pshm->mux),SEM_PSHARED,SEM_MUTEX);
    if (0 != error)
    {
        NW_VMF_SHM_IPC_ERROR("error: nw_vmf_shm_ipc_init() sem_init failed with=%d",error);
    }

    /* init all message queues */
    if (VMF_OK == ret_val)
    {
        ret_val =  nw_vmf_shm_ipc_init_queue (pshm->queues,NW_VMF_SHM_IPC_MAX_QUEUES);
    }

    /* mark shm as valid*/
    pshm->shm_valid = SHM_VALID_TOKEN;

    return ret_val;
}



/***************************************************************************//**
 *   get a free handle
 *
 *   \param[in]     pointer to shared memory
 *   \return        handle or 0
 ******************************************************************************/
vmf_handle_t nw_vmf_shm_ipc_get_free_hdl(vmf_msg_queue_shm_t *pshm)
{
    vmf_handle_t    hdl=VMF_HANDLE_INVALID;
    unsigned16      cnt=0;
    signed16        ttr=0;

    NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_ipc_get_free_hdl()",getmypid());
    /* argument check */
    if (NULL == pshm)
    {
        return (0);
    }

    nw_os_sem_wait(&(pshm->mux));
    for (cnt=0;cnt < NW_VMF_SHM_IPC_MAX_QUEUES; cnt++)
    {
        if (false == pshm->queues[cnt].in_use)
        {
            if (pshm->queues[cnt].ttr == 0)
            {
                pshm->queues[cnt].in_use = true;
                /* found queue */
                hdl = cnt;
                if (hdl > pshm->max_client_id)
                {
                    pshm->max_client_id = hdl;
                }
                pshm->num_client_ids++;
                ttr = (NW_VMF_SHM_IPC_MAX_QUEUES - pshm->num_client_ids);
                if (ttr < 0)
                {
                    ttr = 0;
                }
#if 0
                pshm->queues[cnt].ttr = (unsigned16)(ttr<<2);
#else
                pshm->queues[cnt].ttr = 5;
#endif
                break;
            }
            else
            {
                pshm->queues[cnt].ttr--;
            }
        }
    }
    nw_sem_post(&(pshm->mux));

    NW_VMF_SHM_IPC_INFO2("pid=%d, nw_vmf_shm_ipc_get_free_hdl() Ix=%d - num-clients=%d ",getmypid(),hdl,pshm->num_client_ids);

    return (vmf_handle_t)hdl;
}

/***************************************************************************//**
 *   get the max client id
 *
 *   \param[in]     pointer to shared memory
 *   \return        handle or 0
 ******************************************************************************/
unsigned nw_vmf_shm_ipc_get_max_client_id(vmf_msg_queue_shm_t *pshm)
{
    unsigned16      cnt;
    unsigned16      num=0;

    pshm->max_client_id = 0;
    for (cnt=0;cnt < NW_VMF_SHM_IPC_MAX_QUEUES; cnt++)
    {
        if (true == pshm->queues[cnt].in_use)
        {
            if (cnt > pshm->max_client_id)
            {
                pshm->max_client_id = (unsigned)cnt;
            }
            num++;
        }
    }
    pshm->num_client_ids = num;
    return pshm->max_client_id;
}



/***************************************************************************//**
*    message pool functions
 ******************************************************************************/




/***************************************************************************//**
 *   get a free message buffer from the pool
 *
 *   \param[in]     pointer to shared memory
 *   \param[in]     pointer pointer to resutling buffer
 *   \param[in]     wanted payload length
 *   \return        vmf_error_t
 ******************************************************************************/
vmf_error_t nw_vmf_shm_ipc_pool_get_buff(vmf_msg_queue_shm_t *pshm, vmf_handle_t vmf_handle, vmf_buffer_pool_msg_t **pp_free_buffer,unsigned16 wanted_pl_len)
{
    vmf_error_t             ret_val = VMF_ERROR;
    vmf_buffer_pool_msg_t   *ps_buffer=NULL;        /* server address */
    vmf_buffer_pool_msg_t   *pl_buffer=NULL;        /* local address */
    vmf_buffer_pool_t       *pcurrent_pool=NULL;
    vmf_buffer_pool_t       *pcurrents_pool=NULL;
    bool                    server_pool_used=false;

    NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_ipc_pool_get_buff:() pshm=%p",getmypid(),pshm);

    /* argument check */
    if (NULL == pshm)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_shm_ipc_pool_get_buff: pshm=NULL!!",getmypid());
        return (VMF_ERR_NULL_POINTER);
    }
    if (NULL == pp_free_buffer)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_shm_ipc_pool_get_buff: pp_free_buffer=NULL!!",getmypid());
        return (VMF_ERR_NULL_POINTER);
    }
    if (0 == wanted_pl_len)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_shm_ipc_pool_get_buff: wanted_pl_len=0!!",getmypid());
        return (VMF_ERR_NULL_POINTER);
    }

    NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_ipc_pool_get_buff:() args OK",getmypid());

    /* search for free buffer in all pools */
    pcurrent_pool = &pshm->pool1;                       /* start with pool1 */
    while((NULL != pcurrent_pool) && (NULL == ps_buffer))
    {
        /* check if buffers in this pool are big enought */
        if (pcurrent_pool->pool_msg_len >= wanted_pl_len)
        {

            /* buffers in this pool are big enought */
            /* check if there is a buffer left      */
    NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_ipc_pool_get_buff:() call nw_os_sem_wait",getmypid());
            nw_os_sem_wait(&pcurrent_pool->mux);            /* lock pool */
    NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_ipc_pool_get_buff:() nw_os_sem_wait done",getmypid());

            /* check if there was a mux error */
            if (true == pcurrent_pool->lock)
            {
                NW_VMF_SHM_IPC_ERROR("%d: nw_vmf_shm_ipc_pool_get_buff:()pool_msg_len=%d, mux failed !!!!",nw_os_cfg_get_ms_time(),pcurrent_pool->pool_msg_len);
            }
            pcurrent_pool->lock = true;

            /* get server and local address of first buffer in pool */
            ps_buffer = pcurrent_pool->first;
            pl_buffer = (vmf_buffer_pool_msg_t*)GET_LOCAL_ADDR(ps_buffer);

            if (NULL != ps_buffer)
            {
                /* free buffer  found      */
                /* remove buffer from pool */
                pcurrent_pool->first=pl_buffer->next;       /* next buffer is new first buffer */
                pcurrent_pool->num--;                       /* debug only */
                /* handle low watermark */
                if (pcurrent_pool->num < pcurrent_pool->low_wm)
                {
                     pcurrent_pool->low_wm = pcurrent_pool->num;    /* store low watermark */
                }

                pcurrent_pool->lock = false;
                nw_sem_post(&pcurrent_pool->mux);              /* free pool */
                break;                                      /* search done */
            }
            else
            {
                /* check queue health state */
                if (pcurrent_pool->num > 0)
                {
                    /* queue is corupted !!!*/
                    NW_VMF_SHM_IPC_ERROR("%d: nw_vmf_shm_ipc_pool_get_buff:() pool_msg_len=%d, pool corupted ps_buffer=NULL, num=%d",nw_os_cfg_get_ms_time(),pcurrent_pool->pool_msg_len,pcurrent_pool->num);
                }

                /* queue is empty */
                pcurrent_pool->lock = false;
                nw_sem_post(&pcurrent_pool->mux);              /* free pool */
            }
        }

        /* goto next pool */
        pcurrents_pool = pcurrent_pool->nextpool;           /* pool server address */
        if (pcurrents_pool != NULL)
        {
            /* convert pool server address to local address */
            pcurrent_pool = (vmf_buffer_pool_t*)GET_LOCAL_ADDR(pcurrents_pool);
        }
        else
        {
            /* no pool left */
            if (IPC_SERVER_HANDLE != vmf_handle)
            {
                /* only the server will send data to non server queues */
                if (false == server_pool_used)
                {
                    server_pool_used = true;
                    /* this is the server */
                    NW_VMF_SHM_IPC_INFO("%d-vmf_handle=%d: nw_vmf_shm_ipc_pool_get_buff:() use server pool-msgs in pool=%d",nw_os_cfg_get_ms_time(),vmf_handle,pshm->pools.num);
                    /* the server is allowed to use an additional pool! */
                    pcurrent_pool = (vmf_buffer_pool_t*)&pshm->pools;
                }
                else
                {
                    break;  /* no endless loop if this is the server */
                }
            }
            break;  /* end loop */
        }
    }

    if (NULL != ps_buffer)
    {
        /* got buffer  */

        /* check buffer */
        if (pl_buffer->msg_valid != SHM_VALID_TOKEN)
        {
            NW_VMF_SHM_IPC_ERROR("pid=%d-vmf_handle=%d, nw_vmf_shm_ipc_pool_get_buff: got invalid buffer %p!!",getmypid(),vmf_handle,pl_buffer);
            NW_VMF_SHM_IPC_ERROR("pid=%d-vmf_handle=%d, msg-len=%d",getmypid(),vmf_handle,pl_buffer->pool_msg_len);
            NW_VMF_SHM_IPC_ERROR("pid=%d-vmf_handle=%d, ref_count=%d",getmypid(),vmf_handle,pl_buffer->ref_count);
            nw_vmf_HexDump("nw_vmf_shm_ipc_pool_get_buff",(unsigned8 *)pl_buffer,pl_buffer->pool_msg_len+18);
            ret_val = VMF_ERR_INVALID_ARG;
        }
        else
        {
            NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_ipc_pool_get_buff:() got buffer %p with len %d",getmypid(),pl_buffer,pl_buffer->pool_msg_len);
            *pp_free_buffer = pl_buffer;
            ret_val = VMF_OK;
        }
    }
    else
    {
        /* no buffer found*/
        NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_ipc_pool_get_buff: no buffer found wanted_pl_len=%d!!",getmypid(),wanted_pl_len);
        *pp_free_buffer = NULL;
        ret_val = VMF_ERR_OUT_OF_MEMORY;
    }

    return ret_val;
}



/***************************************************************************//**
 *   put a message buffer back to its pool
 *
 *   \param[in]     pointer to shared memory
 *   \param[in]     pointer to memory buffer
 *   \return        vmf_error_t
 ******************************************************************************/
vmf_error_t nw_vmf_shm_ipc_pool_free_buff(vmf_msg_queue_shm_t *pshm,vmf_buffer_pool_msg_t *pl_buffer)
{
    vmf_error_t             ret_val = VMF_ERROR;
    vmf_buffer_pool_t       *pcurrent_pool_l = NULL;
    vmf_buffer_pool_t       *pcurrent_pool_s = NULL;
    vmf_buffer_pool_msg_t   *ps_buffer = NULL;
    unsigned16              ref_cnt=0;

    NW_VMF_SHM_IPC_INFO("nw_vmf_shm_ipc_pool_free_buff: pl_buffer=%p!!",pl_buffer);

    /* argument check */
    if (NULL == pshm)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_shm_ipc_pool_free_buff: pshm=NULL!!",getmypid());
        return (VMF_ERR_NULL_POINTER);
    }
    if (NULL == pl_buffer)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_shm_ipc_pool_free_buff: pl_buffer=NULL!!",getmypid());
        return (VMF_ERR_NULL_POINTER);
    }
    if (pl_buffer->msg_valid != SHM_VALID_TOKEN)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_shm_ipc_pool_free_buff: invalid buffer!!",getmypid());
        return (VMF_ERR_INVALID_ARG);
    }

    /* dec ref count and free buffer if count is zero */
    ref_cnt = nw_atomic_dec(&(pl_buffer->ref_count));
    if (0 != ref_cnt)
    {
        /*  do not free buffer until 0 is reached */
        NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_ipc_pool_free_buff:%p not freed ref_count=%d!",getmypid(),pl_buffer,ref_cnt);
#if 0
        return (VMF_OK);
#endif
    }


    /* transfer local buffer address to server-address */
    ps_buffer = (vmf_buffer_pool_msg_t*)GET_SERVER_ADDR(pl_buffer);

    /* search the associated message pool */
    pcurrent_pool_l = (vmf_buffer_pool_t*)&pshm->pools;   /* start of all pools */
    pcurrent_pool_s = (vmf_buffer_pool_t*)GET_SERVER_ADDR(pcurrent_pool_l->nextpool);
    while((NULL != pcurrent_pool_s))
    {
        /* check if this is the correct message pool */
        if (pcurrent_pool_l->pool_msg_len == pl_buffer->pool_msg_len)
        {
            /* messages pool found */
            /* lock pool */
            NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_ipc_pool_free_buff call nw_os_sem_wait",getmypid());
            nw_os_sem_wait(&pcurrent_pool_l->mux);
            NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_ipc_pool_free_buff call nw_os_sem_wait done",getmypid());
            if (true == pcurrent_pool_l->lock)
            {
                NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_shm_ipc_pool_free_buff pool:%p mux failed !!!!",getmypid(),pcurrent_pool_l);
            }
            pcurrent_pool_l->lock = true;

            /* put message back to pool */
            pl_buffer->next = pcurrent_pool_l->first;
            pcurrent_pool_l->first=ps_buffer;
            pcurrent_pool_l->num++;                       /* debug only */

            /* free pool */
            pcurrent_pool_l->lock = false;
            nw_sem_post(&pcurrent_pool_l->mux);              /* free pool */
            pcurrent_pool_s = NULL;                       /* end the loop */
            ret_val = VMF_OK;
        }
        else
        {
            /* goto next pool */
            pcurrent_pool_s = pcurrent_pool_l->nextpool;
            pcurrent_pool_l = (vmf_buffer_pool_t*)GET_LOCAL_ADDR(pcurrent_pool_s);
        }
    }

    if (ret_val != VMF_OK)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_shm_ipc_pool_free_buff() could not free buf !!!!",getmypid());
    }

    return ret_val;
}






/***************************************************************************//**
*    message queue functions
 ******************************************************************************/


/***************************************************************************//**
 *   free all messages from a queue
 *
 *   \param[in]     pointer to shared memory
 *   \param[in]     pointer to memory buffer
 *   \return        vmf_error_t
 ******************************************************************************/
vmf_error_t nw_vmf_shm_ipc_queue_free_all_buff(vmf_msg_queue_shm_t *pshm,vmf_handle_t vmf_handle)
{
    vmf_error_t ret_val=VMF_OK;
    vmf_buffer_pool_msg_t *pmsg=NULL;

    nw_os_sem_wait(&(pshm->mux));
    if (false == pshm->queues[vmf_handle].in_use)
    {
        /* queue already freed */
        nw_sem_post(&(pshm->mux));
        return VMF_OK;
    }

    pshm->queues[vmf_handle].in_use = false;        /* disable this queue */
    while (VMF_OK == ret_val)
    {
        ret_val = nw_vmf_shm_ipc_queue_read(pshm, &pmsg, vmf_handle,1);
        if (VMF_OK == ret_val)
        {
            (void)nw_vmf_shm_ipc_pool_free_buff(pshm,pmsg);
        }
    }
    pshm->queues[vmf_handle].num_name= INVALID_NUMNAME;
    pshm->queues[vmf_handle].name[0] = 0;

    nw_vmf_shm_ipc_get_max_client_id(pshm);
    nw_sem_post(&(pshm->mux));

    NW_VMF_SHM_IPC_INFO2("vmf_handle=%d: nw_vmf_shm_ipc_queue_free_all_buff() - num_clients=%d",vmf_handle,pshm->num_client_ids );

    return VMF_OK;
}



/***************************************************************************//**
 *   write a message to a message queue
 *
 *   \param[in]     pointer to shared memory
 *   \param[in]     pointer to the message
 *   \param[in]     vmf-handle of queue
 *   \return        vmf_error_t
 ******************************************************************************/
vmf_error_t nw_vmf_shm_ipc_queue_write(vmf_msg_queue_shm_t *pshm,vmf_buffer_pool_msg_t *pl_msg,vmf_handle_t vmf_handle)
{
    vmf_error_t ret_val=VMF_OK;
    vmf_msg_queue_t *p_queue=NULL;
    vmf_buffer_pool_msg_t *ps_msg=NULL;
    vmf_buffer_pool_msg_t *ppl_msg=NULL;

    NW_VMF_SHM_IPC_INFO("pid=%d, vmf_handle=%d,info: nw_vmf_shm_ipc_queue_write() pshm,=%p",getmypid(),vmf_handle,pshm);

    /* argument check */
    if (NULL == pshm)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_shm_ipc_queue_write: shm=NULL!!",getmypid());
        return(VMF_ERR_NULL_POINTER);
    }
    if (NULL == pl_msg)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_shm_ipc_queue_write: buffer=NULL!!",getmypid());
        return(VMF_ERR_NULL_POINTER);
    }
    if (vmf_handle >= NW_VMF_SHM_IPC_MAX_QUEUES)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_shm_ipc_queue_write: invalid handle=%d!!",getmypid(),vmf_handle);
        return(VMF_ERR_OUT_OF_RANGE);
    }
    if (pl_msg->msg_valid != SHM_VALID_TOKEN)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_shm_ipc_queue_write: invalid buffer!!",getmypid());
        return (VMF_ERR_INVALID_ARG);
    }

    /* transfer local address to server-address */
    ps_msg = (vmf_buffer_pool_msg_t*)GET_SERVER_ADDR(pl_msg);

    /* get address of the queue */
    p_queue = &pshm->queues[vmf_handle];

    /* handle queue fill-level and blocking */
    if (p_queue->max_num > 0)                           /* does this queue have a limit ?*/
    {
        /* queue with limit */
        if (p_queue->tx_blocking)
        {
            /* blocking queue */
            NW_VMF_SHM_IPC_INFO("pid=%d, vmf_handle=%d,info: nw_vmf_shm_ipc_queue_write() call nw_os_sem_wait() - wait until room in the Q",getmypid(),vmf_handle);
            /* wait until there is room in the queue */
            nw_os_sem_wait(&p_queue->tx_sem);
            NW_VMF_SHM_IPC_INFO("pid=%d, vmf_handle=%d,info: nw_vmf_shm_ipc_queue_write() nw_os_sem_wait() done - there is room in the queue",getmypid(),vmf_handle);
        }
        else
        {
            /* non tx blocking queue*/
            int sem_ret_val;
            NW_VMF_SHM_IPC_INFO("pid=%d, vmf_handle=%d,info: nw_vmf_shm_ipc_queue_write() call sem_trywait()",getmypid(),vmf_handle);
            sem_ret_val = nw_os_sem_trywait(&p_queue->tx_sem);
            if (0 != sem_ret_val)
            {
                /* no room in queue - so return */
                ret_val = VMF_ERR_SHM_IPC_EAGAIN;
            }
        }
    }
    else
    {
        /* queue without limit */
        /* no code */
    }

    if (VMF_OK == ret_val)
    {
        /* write the message to the queue */
        NW_VMF_SHM_IPC_INFO("pid=%d, vmf_handle=%d,info: nw_vmf_shm_ipc_queue_write() pl_msg=%p, len=%d",getmypid(),vmf_handle,pl_msg,pl_msg->msg_payload_len);

        /* inc msg ref counter */
        (void)nw_atomic_inc(&(pl_msg->ref_count));

        NW_VMF_SHM_IPC_INFO("pid=%d, vmf_handle=%d,info: nw_vmf_shm_ipc_queue_write() call nw_os_sem_wait() 2",getmypid(),vmf_handle);
        nw_os_sem_wait(&p_queue->mux);          /* first lock the queue */
         NW_VMF_SHM_IPC_INFO("pid=%d, vmf_handle=%d,info: nw_vmf_shm_ipc_queue_write() call nw_os_sem_wait() 2 done",getmypid(),vmf_handle);
        if (true == p_queue->lock)
        {
            /* mutex did not work !! */
            NW_VMF_SHM_IPC_ERROR("info: nw_vmf_shm_ipc_queue_write() mutex failed!!");
        }
        p_queue->lock = true;

        /* put the buffer to the bottom of the queue */
        pl_msg->previous = p_queue->last;       /* store last message in queue as previus message inside message */

        /* check if there was data in the queue */
        if (p_queue->last != NULL)
        {
            /* there is data in the queue */
            if (p_queue->num == 0)
            {
                NW_VMF_SHM_IPC_ERROR("vmf_handle=%d,info: nw_vmf_shm_ipc_queue_write() queue corupted data in queue, num=0, data=%p",vmf_handle,p_queue->last);
            }
            /* write new message as next message to previous message  */
            ppl_msg = GET_LOCAL_MSG_ADDR(pl_msg->previous);
            ppl_msg->next = ps_msg; /* next message of former last message is the new message */
        }
        else
        {
            /* queue was empty */
            p_queue->first = ps_msg;            /* new message is also new first message */

            /* check health status of queue */
            if (p_queue->num > 0)
            {
                NW_VMF_SHM_IPC_ERROR("vmf_handle=%d,info: nw_vmf_shm_ipc_queue_write() queue corupted ->last=NULL, num=%d, data=%p",vmf_handle,p_queue->num,p_queue->last);
            }
        }

        pl_msg->next = NULL;                    /* mark new message as last mesage in the list */
        p_queue->last = ps_msg;                 /* the new message is now the last mesage in the liste */
        p_queue->num++;
        if (p_queue->num > p_queue->high_wm)
        {
            p_queue->high_wm = p_queue->num;    /* high watermark */
        }

        p_queue->lock = false;
        nw_sem_post(&p_queue->mux);                /* free the queue */
        nw_sem_post(&p_queue->rx_sem);             /* post sem to unlock waiting receiver */
        ret_val =  VMF_OK;
    }
    else
    {
        if (ret_val != VMF_ERR_SHM_IPC_EAGAIN)
        {
            NW_VMF_SHM_IPC_ERROR("vmf_handle=%d,info: nw_vmf_shm_ipc_queue_write() error=%d",vmf_handle,ret_val);
        }
    }

    return ret_val;
}




/***************************************************************************//**
 *   read a message from a message queue
 *
 *   \param[in]     pointer to shared memory
 *   \param[in]     pointer pointer to the message
 *   \param[in]     cid of queue
 *   \param[in]     timeout in ms (or 0 if blocking)
 *   \return        vmf_error_t
 ******************************************************************************/
vmf_error_t nw_vmf_shm_ipc_queue_read(vmf_msg_queue_shm_t *pshm, vmf_buffer_pool_msg_t **ppmsg, vmf_handle_t vmf_handle,unsigned16 ms_timout)
{
    vmf_error_t ret_val=VMF_OK;
    vmf_msg_queue_t *p_queue=NULL;
    int         sem_retval=0;
    vmf_buffer_pool_msg_t   *pl_msg=NULL;
    vmf_buffer_pool_msg_t   *ps_msg=NULL;


    NW_VMF_SHM_IPC_INFO("vmf_handle=%d,info: nw_vmf_shm_ipc_queue_read() pshm=%p,vmf_handle=%d",vmf_handle,pshm,vmf_handle);

    /* argument check */
    if (NULL == pshm)
    {
        NW_VMF_SHM_IPC_ERROR("vmf_handle=%d, nw_vmf_shm_ipc_queue_read: shared memory =NULL",vmf_handle);
        return(VMF_ERR_NULL_POINTER);
    }
    if (NULL == ppmsg)
    {
        NW_VMF_SHM_IPC_ERROR("vmf_handle=%d, nw_vmf_shm_ipc_queue_read: pointer to rx message = NULL",vmf_handle);
        return(VMF_ERR_NULL_POINTER);
    }
    if (vmf_handle >= NW_VMF_SHM_IPC_MAX_QUEUES)
    {
        NW_VMF_SHM_IPC_ERROR("vmf_handle=%d, nw_vmf_shm_ipc_queue_read: invalid CIDd",vmf_handle);
        return(VMF_ERR_OUT_OF_RANGE);
    }

    /* get address of the queue */
    p_queue = &pshm->queues[vmf_handle];

    NW_VMF_SHM_IPC_INFO("vmf_handle=%d, nw_vmf_shm_ipc_queue_read: timeout=%d, blocking=%d, p_queue=%p",vmf_handle,ms_timout,p_queue->rx_blocking,p_queue);

    if (p_queue->rx_blocking)
    {
        NW_VMF_SHM_IPC_INFO("info: nw_vmf_shm_ipc_queue_read() blocking read");
        /* blocking read */
        if (0 == ms_timout)
        {
            /* blocking sem */
            sem_retval = nw_os_sem_wait(&p_queue->rx_sem);                      /* wait for data in the queue */
        }
        else
        {
            /* sem with timeout */
            sem_retval = nw_os_sem_timedwait(&p_queue->rx_sem,ms_timout);       /* wait for data in the queue */
        }

        NW_VMF_SHM_IPC_INFO("vmf_handle=%d, nw_vmf_shm_ipc_queue_read: nw_os_sem_timedwait ret=%d",vmf_handle,sem_retval);
        if (sem_retval != 0)
        {
            /* handle sem error !*/
            if (0 == ms_timout)
            {
                /* we got an error !*/
                NW_VMF_SHM_IPC_ERROR("vmf_handle=%d, nw_vmf_shm_ipc_queue_read: nw_os_sem_timedwait timeout=%d",vmf_handle,ms_timout);
                ret_val = VMF_ERR_SHM_IPC_SEM;
            }
            else
            {
                /* error or timeout */
                NW_VMF_SHM_IPC_INFO("vmf_handle=%d, nw_vmf_shm_ipc_queue_read: VMF_ERR_SHM_IPC_EAGAIN",vmf_handle);
                ret_val = VMF_ERR_SHM_IPC_EAGAIN;
            }
        }
        else
        {
            /* we got data */
            NW_VMF_SHM_IPC_INFO("vmf_handle=%d, nw_vmf_shm_ipc_queue_read: nw_os_sem_timedwait no error",vmf_handle);
            ret_val=VMF_OK;
        }
    }
    else
    {
        /* non blocking read */
        NW_VMF_SHM_IPC_INFO("info: nw_vmf_shm_ipc_queue_read() non blocking read");
        sem_retval = nw_os_sem_trywait(&p_queue->rx_sem);
        if (sem_retval != 0)
        {
            /* call would block */
            NW_VMF_SHM_IPC_INFO("vmf_handle=%d, nw_vmf_shm_ipc_queue_read: non blocking sem would block",vmf_handle);
            ret_val = VMF_ERR_SHM_IPC_EAGAIN;
        }
        else
        {
            /* we got data */
            NW_VMF_SHM_IPC_INFO("vmf_handle=%d, nw_vmf_shm_ipc_queue_read: sem_trywait no error",vmf_handle);
            ret_val=VMF_OK;
        }
    }

    if (VMF_OK == ret_val)
    {
        /* read data from queue */
        NW_VMF_SHM_IPC_INFO("info: nw_vmf_shm_ipc_queue_read() ret_val=OK");

        /* lock the queue */
        nw_os_sem_wait(&p_queue->mux);              /* lock the queue */
        if (true == p_queue->lock)
        {
            /* mutex did not work !! */
            NW_VMF_SHM_IPC_ERROR("info: nw_vmf_shm_ipc_queue_read() mutex failed!!");
        }
        p_queue->lock = true;

        ps_msg = p_queue->first;                    /* get first message from top of queue */
        pl_msg = GET_LOCAL_MSG_ADDR(ps_msg);

        /* is there data in the queue ? */
        if (NULL != ps_msg)
        {
            /* check if buffer is valid */
            if (pl_msg->msg_valid != SHM_VALID_TOKEN)
            {
                NW_VMF_SHM_IPC_ERROR("pid=%d, pl_msg=%p,nw_vmf_shm_ipc_queue_read: invalid buffer!!",getmypid(),pl_msg);
            }

            /* there is data in the queue */
            /* get message from queue */
            p_queue->first = pl_msg->next;          /* second message is now  first message */
            p_queue->num--;                         /* number of messages in the queue  */

            /* test if the queue is empty now */
            if (NULL == p_queue->first)
            {
                p_queue->last = NULL;
                if (p_queue->num > 0)
                {
                    /* queue is corupted !!!*/
                    NW_VMF_SHM_IPC_ERROR("%d-vmf_handle=%d: nw_vmf_shm_ipc_queue_read:() queue corupted queue empty now, num=%d",nw_os_cfg_get_ms_time(),vmf_handle,p_queue->num);
                }
            }
            ret_val = VMF_OK;
        }
        else
        {
            /* queue is empty */
            NW_VMF_SHM_IPC_INFO("vmf_handle=%d, nw_vmf_shm_ipc_queue_read: queue empty",vmf_handle);
            if (p_queue->num > 0)
            {
                /* queue is corupted !!!*/
                NW_VMF_SHM_IPC_ERROR("%d-vmf_handle=%d: nw_vmf_shm_ipc_queue_read:() queue corupted ps_buffer=NULL, num=%d",nw_os_cfg_get_ms_time(),vmf_handle,p_queue->num);
            }

            ret_val = VMF_ERR_SHM_IPC_NO_DATA;
        }
        p_queue->lock = false;
        nw_sem_post(&p_queue->mux);                    /* free the queue */
        nw_sem_post(&p_queue->tx_sem);                 /* release one write position in queue */
    }

    /* return local address of message */
    *ppmsg = pl_msg;

    return ret_val;
}





/***************************************************************************//**
 *   set the maximum number of messages for a message queue
 *
 *   \param[in]     pointer to shared memory
 *   \param[in]     pointer to the message
 *   \param[in]     cid of queue
 *   \param[in]     maxomum number of messages in this queue
 *   \return        vmf_error_t
 ******************************************************************************/
vmf_error_t nw_vmf_shm_ipc_queue_set_max_num(vmf_msg_queue_shm_t *pshm,vmf_handle_t vmf_handle,unsigned16 max_num)
{
    vmf_error_t ret_val=VMF_OK;
    vmf_msg_queue_t *p_queue=NULL;
    sem_t           *p_sem;
    int error;

    NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_ipc_queue_set_max_num(), set to max_num=%d",getmypid(),max_num);

    /* argument check */
    if (NULL == pshm)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_shm_ipc_queue_set_max_num() NULL == pshm",getmypid());
        return(VMF_ERR_NULL_POINTER);
    }
    if (vmf_handle >= NW_VMF_SHM_IPC_MAX_QUEUES)
    {
        NW_VMF_SHM_IPC_ERROR("info: nw_vmf_shm_ipc_queue_set_max_num() vmf_handle >= NW_VMF_SHM_IPC_MAX_QUEUES");
        return(VMF_ERR_OUT_OF_RANGE);
    }
    if (max_num > NW_VMF_SHM_IPC_MSG_NUM_MAX)
    {
        NW_VMF_SHM_IPC_ERROR("info: nw_vmf_shm_ipc_queue_set_max_num() max_num > NW_VMF_SHM_IPC_MSG_NUM_MAX");
        return(VMF_ERR_OUT_OF_RANGE);
    }

    /* get address of the queue */
    p_queue = &pshm->queues[vmf_handle];
    p_sem = &(p_queue->tx_sem);
    if (p_queue->max_num != max_num)
    {
        NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_ipc_queue_set_max_num(), sem=%p, current max_num=%d",getmypid(),p_sem,p_queue->max_num);
        nw_os_sem_wait(&p_queue->mux);                    /* lock queue */
        if (true == p_queue->lock)
        {
            /* mutex did not work !! */
            NW_VMF_SHM_IPC_ERROR("info: nw_vmf_shm_ipc_queue_set_max_num() mutex failed!!");
        }
        p_queue->lock = true;
        if (p_queue->max_num != max_num)
        {
            p_queue->max_num = max_num;
            /* destroy the sem and recreate it with new value */
            error = sem_destroy(p_sem);
            if (0 != error)
            {
                NW_VMF_SHM_IPC_ERROR("vmf_handle=%d,error: sem_destroy error ret=%d",vmf_handle,error);
                ret_val = VMF_ERR_SHM_IPC_SEM;
            }
            else
            {
                NW_VMF_SHM_IPC_INFO("info: nw_vmf_shm_ipc_queue_set_max_num(), sem_destroy sem=%p ok",p_sem);
            }

            error = nw_sem_init(p_sem,SEM_PSHARED,p_queue->max_num);
            if (0 != error)
            {
                NW_VMF_SHM_IPC_ERROR("vmf_handle=%d,error: sem_init tx sem error ret=%d",vmf_handle,error);
                ret_val = VMF_ERR_SHM_IPC_SEM;
            }
            else
            {
                NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_ipc_queue_set_max_num(), sem_init sem=%p ok",getmypid(),p_sem);
            }

        }
        p_queue->in_use = true;
        p_queue->lock = false;
        nw_sem_post(&p_queue->mux);                    /* free queue */
    }
    else
    {
        NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_ipc_queue_set_max_num(), sem=%p, num=%d nothing to do",getmypid(),p_sem,p_queue->max_num);
    }

    /* init rx sem */
    {
        nw_os_sem_wait(&p_queue->mux);              /* lock queue */
        if (true == p_queue->lock)
        {
            /* mutex did not work !! */
            NW_VMF_SHM_IPC_ERROR("info: nw_vmf_shm_ipc_queue_set_max_num() mutex failed2!!");
        }
        p_queue->lock = true;

        p_sem = &(p_queue->rx_sem);
        error = nw_sem_init(p_sem,SEM_PSHARED,SEM_INIT_VAL);
        if (0 != error)
        {
            NW_VMF_SHM_IPC_ERROR("vmf_handle=%d,error: sem_init rx-sem ret=%d",vmf_handle,error);
            ret_val = VMF_ERR_SHM_IPC_SEM;
        }

        p_queue->lock = false;
        nw_sem_post(&p_queue->mux);                    /* free queue */
   }

    return ret_val;
}


/***************************************************************************//**
 *   set blocking states of a message queue
 *
 *   \param[in]     pointer to shared memory
 *   \param[in]     pointer to the message
 *   \param[in]     cid of queue
 *   \param[in]     true if rx from this queue is blocking
 *   \param[in]     true if tx to this queue is blocking
 *   \return        vmf_error_t
 ******************************************************************************/
vmf_error_t nw_vmf_shm_ipc_queue_set_blocking(vmf_msg_queue_shm_t *pshm,vmf_handle_t vmf_handle,bool rx_blocking,bool tx_blocking)
{
    vmf_error_t ret_val=VMF_OK;
    vmf_msg_queue_t *p_queue=NULL;

    NW_VMF_SHM_IPC_INFO("info: nw_vmf_shm_ipc_queue_set_blocking(), rx-blocking=%d, tx_blocking=%d,num=%d",rx_blocking,tx_blocking,pshm->queues[vmf_handle].num);

    /* argument check */
    if (NULL == pshm)
    {
        NW_VMF_SHM_IPC_ERROR("error: nw_vmf_shm_ipc_queue_set_blocking shm=NULL");
        return(VMF_ERR_NULL_POINTER);
    }
    if (vmf_handle >= NW_VMF_SHM_IPC_MAX_QUEUES)
    {
        NW_VMF_SHM_IPC_ERROR("error: nw_vmf_shm_ipc_queue_set_blocking invalid vmf_handle=%d",vmf_handle);
        return(VMF_ERR_OUT_OF_RANGE);
    }

    /* get address of the queue */
    p_queue = &pshm->queues[vmf_handle];
    nw_os_sem_wait(&p_queue->mux);                  /* lock queue */
    if (true == p_queue->lock)
    {
        /* mutex did not work !! */
        NW_VMF_SHM_IPC_ERROR("info: nw_vmf_shm_ipc_queue_set_blocking() mutex failed!!");
    }
    p_queue->lock = true;

    p_queue->rx_blocking = rx_blocking;
    p_queue->tx_blocking = tx_blocking;

    NW_VMF_SHM_IPC_INFO("info: nw_vmf_shm_ipc_queue_set_blocking(), p_queue=%p, num=%d",p_queue,p_queue->num);
    p_queue->lock = false;
    nw_sem_post(&p_queue->mux);                        /* free queue */

    return ret_val;
}



/***************************************************************************//**
*    local functions
 ******************************************************************************/


/***************************************************************************//**
 *   setup message pool 1
 *
 *   \param[in]     pointer to message pool
 *   \param[in]     number of messages in this pool
 *   \param[in]     palyload len of a single pool message
 *   \return        vmf_error_t
 ******************************************************************************/
static vmf_ret_t nw_vmf_shm_ipc_init_pool1 (vmf_buffer_pool1_t  *pool,unsigned16 num_msgs, unsigned16 pool_msg_len)
{
    vmf_ret_t  ret_val = VMF_OK;
    unsigned16 cnt;


    /* argument check */
    if (NULL == pool)
    {
        return (VMF_ERR_NULL_POINTER);
    }

    /* setup pool struct */
    if (0 != nw_sem_init(&(pool->mux),SEM_PSHARED,SEM_MUTEX))
    {
        return (VMF_ERR_SHM_IPC_SEM);
    }
    pool->pool_msg_len = pool_msg_len;         /* payload len of a single message */
    pool->num = num_msgs;                       /* number of messages in this pool */
    pool->low_wm = num_msgs;
    pool->lock = false;

    NW_VMF_SHM_IPC_INFO("info: nw_vmf_shm_ipc_init_pool1(), pool=%p, num_msgs=%dm pool_msg_len=%d",pool,num_msgs,pool_msg_len);

    /* setup pool messages */
    for (cnt=0; cnt < num_msgs;cnt++)
    {
        pool->msgs[cnt].pool_msg_len=pool_msg_len;

        /* set previous and next message pointers */
        if (cnt > 0)
        {
            /* set previous message */
            pool->msgs[cnt].previous= &(pool->msgs[cnt-1]);
        }
        if (cnt < num_msgs-1)
        {
            /* next message */
             pool->msgs[cnt].next= &(pool->msgs[cnt+1]);
        }
        pool->msgs[cnt].ref_count = 0;
        pool->msgs[cnt].msg_valid = SHM_VALID_TOKEN;      /* mark message as valid */
    }

    /* set first and last message pointers */
    pool->msgs[0].previous= NULL;           /* first element in linked list */
    pool->msgs[num_msgs-1].next= NULL;      /* last element in linked list */
    pool->first = &(pool->msgs[0]);         /* first element */
    pool->last  = &(pool->msgs[num_msgs-1]);/* last element */

    return ret_val;
}


/***************************************************************************//**
 *   setup message pool 2
 *
 *   \param[in]     pointer to message pool
 *   \param[in]     number of messages in this pool
 *   \param[in]     palyload len of a single pool message
 *   \return        vmf_error_t
 ******************************************************************************/
static vmf_ret_t nw_vmf_shm_ipc_init_pool2 (vmf_buffer_pool2_t  *pool,unsigned16 num_msgs, unsigned16 pool_msg_len)
{
    vmf_ret_t  ret_val = VMF_OK;
    unsigned16 cnt;

    /* argument check */
    if (NULL == pool)
    {
        return (VMF_ERR_NULL_POINTER);
    }

    /* setup pool struct */
    if (0 != nw_sem_init(&(pool->mux),SEM_PSHARED,SEM_MUTEX))
    {
        return (VMF_ERR_SHM_IPC_SEM);
    }
    pool->pool_msg_len = pool_msg_len;    /* payload len of a single message */
    pool->num = num_msgs;                    /* number of messages in this pool */
    pool->low_wm = num_msgs;
    pool->lock = false;

    NW_VMF_SHM_IPC_INFO("info: nw_vmf_shm_ipc_init_pool2(), pool=%p, num_msgs=%dm pool_msg_len=%d",pool,num_msgs,pool_msg_len);

    /* setup pool messages */
    for (cnt=0; cnt < num_msgs;cnt++)
    {
        pool->msgs[cnt].pool_msg_len=pool_msg_len;

        /* set previous and next message pointers */
        if (cnt > 0)
        {
            /* set previous message */
            pool->msgs[cnt].previous= (vmf_buffer_pool_msg_t*)&(pool->msgs[cnt-1]);
        }
        if (cnt < num_msgs-1)
        {
            /* next message */
             pool->msgs[cnt].next= (vmf_buffer_pool_msg_t*)&(pool->msgs[cnt+1]);
        }
        pool->msgs[cnt].ref_count = 0;
        pool->msgs[cnt].msg_valid = SHM_VALID_TOKEN;      /* mark message as valid */
    }

    /* set first and last message pointers */
    pool->msgs[0].previous= NULL;           /* first element in linked list */
    pool->msgs[num_msgs-1].next= NULL;      /* last element in linked list */
    pool->first = &(pool->msgs[0]);         /* first element */
    pool->last  = &(pool->msgs[num_msgs-1]);/* last element */

    return ret_val;
}


/***************************************************************************//**
 *   setup message pool 3
 *
 *   \param[in]     pointer to message pool
 *   \param[in]     number of messages in this pool
 *   \param[in]     palyload len of a single pool message
 *   \return        vmf_error_t
 ******************************************************************************/
static vmf_ret_t nw_vmf_shm_ipc_init_pool3 (vmf_buffer_pool3_t  *pool,unsigned16 num_msgs, unsigned16 pool_msg_len)
{
    vmf_ret_t  ret_val = VMF_OK;
    unsigned16 cnt;

    /* argument check */
    if (NULL == pool)
    {
        return (VMF_ERR_NULL_POINTER);
    }

    /* setup pool struct */
    if (0 != nw_sem_init(&(pool->mux),SEM_PSHARED,SEM_MUTEX))
    {
        return (VMF_ERR_SHM_IPC_SEM);
    }
    pool->pool_msg_len = pool_msg_len;    /* payload len of a single message */
    pool->num = num_msgs;                    /* number of messages in this pool */
    pool->low_wm = num_msgs;
    pool->lock = false;

    NW_VMF_SHM_IPC_INFO("info: nw_vmf_shm_ipc_init_pool3(), pool=%p, num_msgs=%dm pool_msg_len=%d",pool,num_msgs,pool_msg_len);


    /* setup pool messages */
    for (cnt=0; cnt < num_msgs;cnt++)
    {
        pool->msgs[cnt].pool_msg_len=pool_msg_len;

        /* set previous and next message pointers */
        if (cnt > 0)
        {
            /* set previous message */
            pool->msgs[cnt].previous= (vmf_buffer_pool_msg_t*)&(pool->msgs[cnt-1]);
        }
        if (cnt < num_msgs-1)
        {
            /* next message */
             pool->msgs[cnt].next= (vmf_buffer_pool_msg_t*)&(pool->msgs[cnt+1]);
        }
        pool->msgs[cnt].ref_count = 0;
        pool->msgs[cnt].msg_valid = SHM_VALID_TOKEN;      /* mark message as valid */
    }

    /* set first and last message pointers */
    pool->msgs[0].previous= NULL;           /* first element in linked list */
    pool->msgs[num_msgs-1].next= NULL;      /* last element in linked list */
    pool->first = &(pool->msgs[0]);         /* first element */
    pool->last  = &(pool->msgs[num_msgs-1]);/* last element */
    return ret_val;
}


/***************************************************************************//**
 *   setup message pool 4
 *
 *   \param[in]     pointer to message pool
 *   \param[in]     number of messages in this pool
 *   \param[in]     palyload len of a single pool message
 *   \return        vmf_error_t
 ******************************************************************************/
static vmf_ret_t nw_vmf_shm_ipc_init_pool4 (vmf_buffer_pool4_t  *pool,unsigned16 num_msgs, unsigned16 pool_msg_len)
{
    vmf_ret_t  ret_val = VMF_OK;
    unsigned16 cnt;

    /* argument check */
    if (NULL == pool)
    {
        return (VMF_ERR_NULL_POINTER);
    }

    /* setup pool struct */
    if (0 != nw_sem_init(&(pool->mux),SEM_PSHARED,SEM_MUTEX))
    {
        return (VMF_ERR_SHM_IPC_SEM);
    }
    pool->pool_msg_len = pool_msg_len;    /* payload len of a single message */
    pool->num = num_msgs;               /* number of messages in this pool */
    pool->low_wm = num_msgs;
    pool->lock = false;

    NW_VMF_SHM_IPC_INFO("info: nw_vmf_shm_ipc_init_pool4(), pool=%p, num_msgs=%dm pool_msg_len=%d",pool,num_msgs,pool_msg_len);


    /* setup pool messages */
    for (cnt=0; cnt < num_msgs;cnt++)
    {
        pool->msgs[cnt].pool_msg_len=pool_msg_len;

        /* set previous and next message pointers */
        if (cnt > 0)
        {
            /* set previous message */
            pool->msgs[cnt].previous= (vmf_buffer_pool_msg_t*)&(pool->msgs[cnt-1]);
        }
        if (cnt < num_msgs-1)
        {
            /* next message */
             pool->msgs[cnt].next= (vmf_buffer_pool_msg_t*)&(pool->msgs[cnt+1]);
        }
        pool->msgs[cnt].ref_count = 0;
        pool->msgs[cnt].msg_valid = SHM_VALID_TOKEN;      /* mark message as valid */
    }

    /* set first and last message pointers */
    pool->msgs[0].previous= NULL;           /* first element in linked list */
    pool->msgs[num_msgs-1].next= NULL;      /* last element in linked list */
    pool->first = &(pool->msgs[0]);         /* first element */
    pool->last  = &(pool->msgs[num_msgs-1]);/* last element */
    return ret_val;
}




/***************************************************************************//**
 *   setup server message pool
 *
 *   \param[in]     pointer to message pool
 *   \param[in]     number of messages in this pool
 *   \param[in]     palyload len of a single pool message
 *   \return        vmf_error_t
 ******************************************************************************/
static vmf_ret_t nw_vmf_shm_ipc_init_pool_s (vmf_buffer_poolS_t  *pool,unsigned16 num_msgs, unsigned16 pool_msg_len)
{
    vmf_ret_t  ret_val = VMF_OK;
    unsigned16 cnt;


    /* argument check */
    if (NULL == pool)
    {
        return (VMF_ERR_NULL_POINTER);
    }

    /* setup pool struct */
    if (0 != nw_sem_init(&(pool->mux),SEM_PSHARED,SEM_MUTEX))
    {
        NW_VMF_SHM_IPC_ERROR("info: nw_vmf_shm_ipc_init_pool_s() sem_init failed");
        return (VMF_ERR_SHM_IPC_SEM);
    }
    pool->pool_msg_len =pool_msg_len;         /* payload len of a single message */
    pool->num = num_msgs;                     /* number of messages in this pool */
    pool->low_wm = num_msgs;
    pool->lock = false;


    NW_VMF_SHM_IPC_INFO("info: nw_vmf_shm_ipc_init_pool_s(), pool=%p, num_msgs=%dm pool_msg_len=%d",pool,num_msgs,pool_msg_len);


    /* setup pool messages */
    for (cnt=0; cnt < num_msgs;cnt++)
    {
        pool->msgs[cnt].pool_msg_len=pool_msg_len;

        /* set previous and next message pointers */
        if (cnt > 0)
        {
            /* set previous message */
            pool->msgs[cnt].previous= &(pool->msgs[cnt-1]);
        }
        if (cnt < num_msgs-1)
        {
            /* next message */
             pool->msgs[cnt].next= &(pool->msgs[cnt+1]);
        }
        pool->msgs[cnt].ref_count = 0;
        pool->msgs[cnt].msg_valid = SHM_VALID_TOKEN;      /* mark message as valid */
    }

    /* set first and last message pointers */
    pool->msgs[0].previous= NULL;           /* first element in linked list */
    pool->msgs[num_msgs-1].next= NULL;      /* last element in linked list */
    pool->first = &(pool->msgs[0]);         /* first element */
    pool->last  = &(pool->msgs[num_msgs-1]);/* last element */

    return ret_val;
}




/***************************************************************************//**
 *   init all message queues
 *
 *   \param[in]     pointer to message queues
 *   \param[in]     number of queues
 *   \return        vmf_error_t
 ******************************************************************************/
static vmf_ret_t nw_vmf_shm_ipc_init_queue (vmf_msg_queue_t  *queues,unsigned16 num_queues)
{
//#define VMF_IPC_SHM_PREINIT_RX_SEM
    vmf_ret_t  ret_val = VMF_OK;
    unsigned16 cnt;

    /* argument check */
    if (NULL == queues)
    {
        NW_VMF_SHM_IPC_ERROR("error: nw_vmf_shm_ipc_init_queue() NULLPOINTER");
        return (VMF_ERR_NULL_POINTER);
    }
    if (0 == num_queues)
    {
        NW_VMF_SHM_IPC_ERROR("error: nw_vmf_shm_ipc_init_queue() num_queues=0");
        return (VMF_ERR_OUT_OF_RANGE);
    }

    for (cnt=0;cnt < num_queues; cnt++)
    {
        int error;

        /* setup queue */
        queues[cnt].num     = 0;
        queues[cnt].high_wm = 0;
        queues[cnt].ttr =     0;
        queues[cnt].max_num = 0;
        queues[cnt].num_name= INVALID_NUMNAME;
        queues[cnt].first   = NULL;
        queues[cnt].last    = NULL;
        queues[cnt].rx_blocking = true;
        queues[cnt].tx_blocking = true;
        queues[cnt].in_use  = false;
        queues[cnt].name[0] = 0;

        /* this sem acts as a mutex */
        error = nw_sem_init(&(queues[cnt].mux),SEM_PSHARED,SEM_MUTEX);
        if (0 != error)
        {
            NW_VMF_SHM_IPC_ERROR("error: nw_vmf_shm_ipc_init_queue() sem_init failed with=%d",error);
            ret_val = VMF_ERR_SHM_IPC_SEM;
            break;
        }
        queues[cnt].lock = false;
        /* sem for tx blocking */
        error = nw_sem_init(&(queues[cnt].tx_sem),SEM_PSHARED,queues[cnt].max_num);
        if (0 != error)
        {
            NW_VMF_SHM_IPC_ERROR("error: nw_vmf_shm_ipc_init_queue() sem_init failed with=%d",error);
            ret_val = VMF_ERR_SHM_IPC_SEM;
            break;
        }
    }

    return ret_val;
}



/***************************************************************************//**
 *   get the vmf handle for a queue
 *
 *   \param[in]     pointer to the channel nme
 *   \return        vmf_handle_t or vmf_error_t
 ******************************************************************************/
static vmf_handle_t nw_vmf_shm_ipc_get_vmf_handle(vmf_msg_queue_t *queues, char *channel_name)
{
    unsigned16  cnt;
    unsigned32  num_name;
    vmf_ret_t   ret_val = VMF_ERROR;

    /* channel_name was aready checked for NULL pointer in the upper layer */
    num_name = atoi(channel_name);

    for (cnt=0;cnt < NW_VMF_SHM_IPC_MAX_QUEUES; cnt++)
    {
        /* search through all queues */
        if (true == queues[cnt].in_use)
        {
            if (num_name == queues[cnt].num_name)
            {
                /* queue found */
                ret_val = cnt;
                break;
            }
        }
    }

    return ret_val;
}



/***************************************************************************//**
 *   store the numerical representation of the channel name into the queue
 *
 *   \param[in]     pointer to all message queues
 *   \param[in]     handle of queue
 *   \param[in]     pointer to the channel name
 *   \return        vmf_handle_t or vmf_error_t
 ******************************************************************************/
static vmf_ret_t nw_vmf_shm_ipc_store_channel_name(vmf_msg_queue_t *queues, vmf_handle_t vmf_handle,char *channel_name)
{
    unsigned32  num_name;
    vmf_ret_t   ret_val = VMF_ERROR;

    /* channel_name aready checked for NULL pointer in the upper layer */
    num_name = atoi(channel_name);

    NW_VMF_SHM_IPC_INFO("info: nw_vmf_shm_ipc_store_channel_name() vmf_handle=%d, nw_vmf_shm_ipc_store_channel_name=%d",vmf_handle,num_name);

    if (vmf_handle > NW_VMF_SHM_IPC_MAX_QUEUES)
    {
        /* invalid vmf_handle */
        ret_val = VMF_ERR_OUT_OF_RANGE;
    }
    else
    {
        queues[vmf_handle].num_name = num_name;
        ret_val = VMF_OK;
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
static unsigned32 getmypid(void)
{
    static unsigned32 u32myPid = 0;

    if (0 == u32myPid )
    {
        u32myPid= nw_os_getpid();
    }
    return u32myPid;
}


/***************************************************************************//**
*    local shm functions
 ******************************************************************************/


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_shm_ipc_create_shm()
 *
 *   Description:   open the ipc-shm shared memory area
 *
 *   \param[in]     pp_shm       pointer pointer to shared memory
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_shm_ipc_create_shm(vmf_msg_queue_shm_t** pp_shm)
{
    int fd;
    void * shm = NULL;
    vmf_ret_t ret_val;

    /* create shared memory entry */
    *pp_shm = NULL;
    (void)shm_unlink(VMF_IPC_SHM);

    fd = nw_shm_create(VMF_IPC_SHM, 0777,sizeof(vmf_msg_queue_shm_t));
    if (fd == -1)
    {
        NW_VMF_SHM_IPC_ERROR("nw_vmf_shm_ipc_create_shm()-shm_open() failed");
        nw_sleep_us(ERROR_WAIT*1000);
        ret_val = VMF_ERROR;
    }
    else
    {
        {
            /* map shared memory */
            shm = mmap(NULL, sizeof(vmf_msg_queue_shm_t), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
            if (shm == MAP_FAILED)
            {
                // Failed to access the memory
                NW_VMF_SHM_IPC_ERROR("vmf_ipc_shm: nw_vmf_shm_ipc_create_shm()-mmap() failed");
                (void) nw_shm_close(fd);
                ret_val = VMF_ERROR;
            }
            else
            {
                *pp_shm = (vmf_msg_queue_shm_t*)shm;
                ret_val = VMF_OK;
            }
        }
    }

    return ret_val;
}





 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_shm_ipc_open_shm()
 *
 *   Description:   open the vmf_shm_ipc shared memory page
 *
 *   Parameters:
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_shm_ipc_open_shm(vmf_msg_queue_shm_t** pp_shm)
{
    int         fd=-1;
    void        *shm  = NULL;
    vmf_ret_t   ret_val= VMF_ERROR;


    /* vmf_trace_shm is pre-initialized to NULL */
    if (NULL != *pp_shm)
    {
        /* another thread already mapped the shm */
        NW_VMF_SHM_IPC_INFO ("pid=%d nw_vmf_shm_ipc_open_shm() shm already mapped",(int)getmypid());
        return VMF_OK;
    }

    /* open the shared memory */
    fd = shm_open(VMF_IPC_SHM, O_RDWR, 0777);
    if (-1 == fd)
    {
        /* shm open failed */
        NW_VMF_SHM_IPC_INFO("pid=%d nw_vmf_shm_ipc_open_shm:shm_open() failed",(int)getmypid());
        nw_sleep_us(ERROR_WAIT*1000);
        ret_val = VMF_ERROR;
    }
    else
    {
        /* shm is open */
        NW_VMF_SHM_IPC_INFO ("pid=%d vmf_shm_ipc:nw_vmf_shm_ipc_open_shm() shm_open OK - fd=%d",(int)getmypid(),(int)fd);

        shm = mmap(NULL, sizeof(vmf_msg_queue_shm_t), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
        if (MAP_FAILED == shm)
        {
            /* Failed to access the memory */
            (void) nw_shm_close(fd);
            *pp_shm = NULL;
            NW_VMF_SHM_IPC_ERROR ("pid=%d nw_vmf_shm_ipc_open_shm:mmap failed",(int)getmypid());
            ret_val = VMF_ERROR;
        }
        else
        {
            NW_VMF_SHM_IPC_INFO ("pid=%d nw_vmf_shm_ipc_open_shmmmap OK",(int)getmypid());
            *pp_shm = (vmf_msg_queue_shm_t*)shm;
            ret_val = VMF_OK;
        }
    }

    return ret_val;
}



 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_shm_ipc_wait_valid()
 *
 *   Description:   wait until shm is valid
 *
 *   Parameters:
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t  nw_vmf_shm_ipc_wait_valid(vmf_msg_queue_shm_t* pshm)
{
    unsigned16  timeout = 0;
    vmf_ret_t   ret_val = VMF_ERR_SHM_IPC_SHM_TIMEOUT;

    if (NULL == pshm)
    {
        return VMF_ERR_SHM_IPC_SHM_INVALID;
    }

    while(timeout < SHM_VALID_TIMEOUT)
    {
        if (SHM_VALID_TOKEN == pshm->shm_valid)
        {
            ret_val = VMF_OK;
            break;
        }
        delay(1);
    }

    if (VMF_OK != ret_val)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_shm_ipc_wait_valid: shared memory not valid timeout",getmypid());
    }
    else
    {
        NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_ipc_wait_valid: shared memory is valid=%p",getmypid(),pshm);
    }
    return ret_val;
}




/*************************************************************************//**
 *
 *   hex_dump
 *   NOTE: hex dump a buffer
 *
 *
 *   \param[in] unsigned8 *     - pointer to bufer
 *   \param[in] len             - length of bufer
 *   \return    void
 *
 ******************************************************************************/
static void nw_vmf_HexDump(char * name,unsigned8 *buffer,unsigned len)
{
#define CPL 16
    static  bool b_in_use = false;
    int     i,j, ct;
    char    asci[2*CPL];

    if (buffer == NULL)
    {
        return;
    }

    while (b_in_use)
    {
        delay(1);
    }
    b_in_use = true;


    if (len <= 0)
    {
        b_in_use = false;
        return;
    }

    fprintf(ERROR_CHANNEL,"%s",name);
    for (i=0,j=0; i<len; ++i)
    {
        if ((i % CPL) == 0)
        {
            fprintf(ERROR_CHANNEL,"    %s\n",asci);
            j=0;
        }
        asci[j]='.';
        asci[j+1]=0;

        ct = (int)buffer[i];
        fprintf(ERROR_CHANNEL,"%02x ", ct);
        if ((ct > 0x1f) && (ct < 0x7f))
        {
            asci[j]=ct;
        }
        j+=1;
    }
    for (; j<CPL; ++j)
    {
        fprintf(ERROR_CHANNEL,"   ");
    }

    fprintf(ERROR_CHANNEL,"    %s\n\n",asci);
    b_in_use = false;
}



 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_shm_debug_info()
 *
 *   Description:   display shared memory infos on console
 *
 *   Parameters:
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static void  nw_vmf_shm_debug_info(vmf_msg_queue_shm_t* pshm)
{

// #define NW_VFM_DSP_DEBUG_INFO
#ifdef NW_VFM_DSP_DEBUG_INFO
    #define MIN_DSP_DELAY   1000     /* minimum delay between displays in ms */
    int cnt=0;
    int max_queue=0;
    vmf_msg_queue_t *queue=NULL;
    unsigned8   cid=0;
    unsigned32  pid=0;
    unsigned32  c_time=0;
    static  unsigned32  last_time=0;


    if (NULL == pshm)
    {
        NW_VMF_SHM_IPC_ERROR("pid=%d, nw_vmf_shm_debug_info: pshm=NULL",getmypid());
        return;
    }

    c_time = nw_os_cfg_get_ms_time();
    if ((last_time+MIN_DSP_DELAY) > c_time)
    {
        return;
    }
    last_time = c_time;

    NW_VMF_SHM_IPC_INFO("");
    NW_VMF_SHM_IPC_INFO("pshm-start=%p len=%d",pshm,sizeof(vmf_msg_queue_shm_t));
    NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_debug_info: poolS number of left msgs=%d",getmypid(),pshm->pools.num);
    NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_debug_info: pool1 number of left msgs=%d",getmypid(),pshm->pool1.num);
    NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_debug_info: pool2 number of left msgs=%d",getmypid(),pshm->pool2.num);
    NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_debug_info: pool3 number of left msgs=%d",getmypid(),pshm->pool3.num);
    NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_debug_info: pool4 number of left msgs=%d",getmypid(),pshm->pool4.num);

    NW_VMF_SHM_IPC_INFO("pid=%d, nw_vmf_shm_debug_info: numbr of queues=%d",getmypid(),pshm->next_client_id);

    max_queue = pshm->next_client_id;
    for (cnt=0; cnt<max_queue; cnt++)
    {
        queue = &pshm->queues[cnt];
        {
            cid = queue->num_name - ((queue->num_name >> 8)<<8);
            pid = queue->num_name >> 8;
            NW_VMF_SHM_IPC_INFO("queue%02d-%06d.%03d %s number of msgs=%d - inuse=%d",cnt,pid,cid,queue->name,queue->num,queue->in_use);
            queue->high_wm =0;
        }
    }
#endif
}





/**************************************************************************//**
 *
 *   Function Name: nw_vmf_ipc_shm_status_thread
 *
 *   Description:   ipc shm status handler thread
 *                  only used for debugging
 *
 *   \param         void
 *   \return        void
 *
 ******************************************************************************/
static void *nw_vmf_ipc_shm_status_thread(void *pNoArg)
{
    #define NW_VMF_STATUS_MSG_INTERVALL 500         /* message intervall in ms */
    int max_queue=0;

    ipc_status_thread_is_running = true;

    /* fill payload */
    while (true == ipc_status_thread_is_running)
    {
        delay(NW_VMF_STATUS_MSG_INTERVALL);
        /* send pool status */
        {
            vmf_ipc_shm_status_pool_t   payload;
            VMF_VAR_BASIC_MSG_TYP(sizeof(payload))   vmf_basic_msg;
            vmf_ret_t   ret_val = VMF_OK;

			ret_val=ret_val;				/* prevent warning  */
            /* create payload */
            payload.version =0;
            payload.num_pools = VMF_IPC_SHM_POOL_NUM;
            payload.pool_low_wm[0] = pvmf_msg_queue_shm->pools.low_wm;
            payload.pool_low_wm[1] = pvmf_msg_queue_shm->pool1.low_wm;
            payload.pool_low_wm[2] = pvmf_msg_queue_shm->pool2.low_wm;
            payload.pool_low_wm[3] = pvmf_msg_queue_shm->pool3.low_wm;
            payload.pool_low_wm[4] = pvmf_msg_queue_shm->pool4.low_wm;

            pvmf_msg_queue_shm->pools.low_wm =pvmf_msg_queue_shm->pools.num;
            pvmf_msg_queue_shm->pool1.low_wm =pvmf_msg_queue_shm->pool1.num;;
            pvmf_msg_queue_shm->pool2.low_wm =pvmf_msg_queue_shm->pool2.num;;
            pvmf_msg_queue_shm->pool3.low_wm =pvmf_msg_queue_shm->pool3.num;;
            pvmf_msg_queue_shm->pool4.low_wm =pvmf_msg_queue_shm->pool4.num;;

            /* transfer message */
            vmf_basic_msg.msg_base.base.msg_type  = MSG_TYPE_BASIC_MESSAGE;
            vmf_basic_msg.msg_base.base.pid       = 0;
            vmf_basic_msg.msg_base.base.client_id = 0;
            vmf_basic_msg.msg_base.base.vmf_mi_server_id = 0;
            vmf_basic_msg.msg_base.base.co_msg_type = 0;
            vmf_basic_msg.msg_base.id.group       = VMF_TRACE_IPC_DATA;
            vmf_basic_msg.msg_base.id.event       = VMF_IPC_STATUS_DATA_POOLS;
            vmf_basic_msg.data.length             = sizeof(payload);
            memcpy(vmf_basic_msg.data.pl,(unsigned8*)&payload,vmf_basic_msg.data.length);
            ret_val = nw_vmf_ipc_send (IPC_SERVER_HANDLE,(unsigned8*)&vmf_basic_msg, sizeof(vmf_basic_msg));
        }

        /* send queue status */
        {
            vmf_ret_t   ret_val = VMF_OK;
            vmf_ipc_shm_status_queue_t   payload;
            VMF_VAR_BASIC_MSG_TYP(sizeof(payload))   vmf_basic_msg;
            int cnt = 0;

			ret_val=ret_val;				/* prevent warning  */
            max_queue = pvmf_msg_queue_shm->max_client_id;

            payload.version = 0;
            payload.num_queues = max_queue;


            for (cnt=0; cnt<max_queue; cnt++)
            {
                vmf_msg_queue_t *p_queue=NULL;

                p_queue = &pvmf_msg_queue_shm->queues[cnt];
                if (true == p_queue->in_use)
                {
                    if (p_queue->high_wm > 0)
                    {
                        payload.queue_high_wm[cnt]=p_queue->high_wm;
                        p_queue->high_wm = 0;
                    }
                    else
                    {
                        /* number of elements in queue not changed since last transfer */
                        /* so send the current number of elements */
                        payload.queue_high_wm[cnt]= p_queue->num;
                    }
                }
                else
                {
                    payload.queue_high_wm[cnt]=0xffff;
                }
            }

            /* transfer message */
            vmf_basic_msg.msg_base.base.msg_type  = MSG_TYPE_BASIC_MESSAGE;
            vmf_basic_msg.msg_base.base.pid       = 0;
            vmf_basic_msg.msg_base.base.client_id = 0;
            vmf_basic_msg.msg_base.base.vmf_mi_server_id = 0;
            vmf_basic_msg.msg_base.base.co_msg_type = 0;
            vmf_basic_msg.msg_base.id.group       = VMF_TRACE_IPC_DATA;
            vmf_basic_msg.msg_base.id.event       = VMF_IPC_STATUS_DATA_QUEUES;
            vmf_basic_msg.data.length             = sizeof(payload);

            memcpy(vmf_basic_msg.data.pl,(unsigned8*)&payload,vmf_basic_msg.data.length);
            ret_val = nw_vmf_ipc_send (IPC_SERVER_HANDLE,(unsigned8*)&vmf_basic_msg, sizeof(vmf_basic_msg));
        }

        /* send queue name */
        {
            vmf_ret_t   ret_val = VMF_OK;
            vmf_ipc_shm_status_queue_name_t     payload;
            VMF_VAR_BASIC_MSG_TYP(sizeof(payload))   vmf_basic_msg;
            vmf_msg_queue_t *p_msq_q = NULL;
            static unsigned8 current_q = 0;

			ret_val=ret_val;				/* prevent warning  */
            p_msq_q = &(pvmf_msg_queue_shm->queues[current_q]);
            payload.version = 0;
            payload.queue = current_q;
            payload.name_len = strlen(p_msq_q->name);
            if (payload.name_len  > 0)
            {
                nw_os_sstrncpy(payload.name, p_msq_q->name, VMF_IPC_QNAME_LEN);
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

            memcpy(vmf_basic_msg.data.pl,(unsigned8*)&payload,vmf_basic_msg.data.length);
            ret_val = nw_vmf_ipc_send (IPC_SERVER_HANDLE,(unsigned8*)&vmf_basic_msg, sizeof(vmf_basic_msg));

            current_q++;
            if (current_q > max_queue)
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
 *   Description:   create the shared memory IPC status thread
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
    pthread_attr_init( &attr );
    if ( pthread_attr_setstacksize(&attr, VMF_NW_STACK_SIZE ) != 0 )
    {
        NW_VMF_SHM_IPC_ERROR("%mf_nw_status_create_thread() - pthread_attr_setstacksize() failed");
    }

    iRet = pthread_create (&th  , &attr, nw_vmf_ipc_shm_status_thread, NULL);
    pthread_attr_destroy(&attr);
    if (iRet != 0)
    {
        NW_VMF_SHM_IPC_ERROR("mf_nw_status_create_thread() error! errno = %d\n",iRet);
        return false;
    }
#if ((defined(__QNX__) && (_NTO_VERSION >= 632)) || defined(__LINUX__))		
    /* Name the vmf-Logger thread */
	sprintf(Thread_name, "IPC-SHM-%d", th);
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
