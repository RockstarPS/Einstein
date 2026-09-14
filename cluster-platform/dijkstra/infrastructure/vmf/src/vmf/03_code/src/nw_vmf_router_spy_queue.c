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

  \file                 nw_vmf_router_spy_queue.c
  \brief                spy queue functionality for vmf-router

  \author               Joerg Merkle / Jochen Becker
  \author               Visteon Deutschland GmbH, Infotainment Software

  *****************************************************************************/
#define _NW_VMF_ROUTER_QUEUES_C_


/* system includes */
#include "nw_os_config.h"

/* application includes */
#include "nw_vmf_debug.h"
#include "nw_config.h"
#include "nw_vmf_types.h"
#include "nw_vmf_ipc.h"
#include "nw_vmf_util.h"
#include "nw_vmf_trace.h"
#include "nw_vmf_timer.h"
#include "nw_vmf_client_private.h"
#include "nw_vmf_router.h"

#if 0 /* must be disabled, no debugging on console allowed in released sw. */
#define VMF_RQ_CONSOLE_DEBUG
#endif
#ifdef VMF_RQ_CONSOLE_DEBUG
  #define VMF_RQ_PRINTF3(...)  //(void)fprintf(ERROR_CHANNEL, "vmf_router_queue debug: "); (void)fprintf(ERROR_CHANNEL, __VA_ARGS__); (void)fprintf(ERROR_CHANNEL, "\n");
  #define VMF_RQ_PRINTF2(...)  //(void)fprintf(ERROR_CHANNEL, "%d vmf_router_queue debug: ",(int)nw_os_cfg_get_ms_time()); (void)fprintf(ERROR_CHANNEL, __VA_ARGS__); (void)fprintf(ERROR_CHANNEL, "\n");
  #define VMF_RQ_PRINTF(...)   //(void)fprintf(ERROR_CHANNEL, "vmf_router_queue debug: "); (void)fprintf(ERROR_CHANNEL, __VA_ARGS__); (void)fprintf(ERROR_CHANNEL, "\n");
  #define VMF_RQ_ERROR(...)    (void)fprintf(ERROR_CHANNEL, "%d vmf_router_queue error: ",(int)nw_os_cfg_get_ms_time()); (void)fprintf(ERROR_CHANNEL, __VA_ARGS__); (void)fprintf(ERROR_CHANNEL, "\n");
#else
  #define VMF_RQ_PRINTF3(...)
  #define VMF_RQ_PRINTF2(...)
  #define VMF_RQ_PRINTF(...)
  #define VMF_RQ_ERROR(...)
#endif

#define VMF_ROUTER_SPY_TX_NOW      (2)
#define VMF_ROUTER_SPY_TX_RETRY    (250)
#define VMF_ROUTER_SPY_TX_TIMEOUT  (250)
#define VMF_ROUTER_SPY_MAX_ERROR   (10000/VMF_ROUTER_SPY_TX_RETRY)      /* max retry for 10 seconds */

#if 0
#define VMF_MUX_LOCK(mux)                            \
    if (pthread_mutex_lock(mux) != 0)                \
    {                                                \
        VMF_RQ_ERROR("pthread_mutex_lock failed");   \
    }                                                \


#define VMF_MUX_UNLOCK(mux)                          \
    if (pthread_mutex_unlock(mux) != 0)              \
    {                                                \
        VMF_RQ_ERROR("pthread_mutex_unlock failed"); \
    }

#endif


typedef struct vmf_spy_queue_tag     vmf_spy_queue_t;

struct vmf_spy_queue_tag
{
    unsigned8               index;              /* index in the pool */
    unsigned8               in_use;             /* 0 if not in use */
    vmf_basic_msg_t         *pvmf_spy_msg;      /* address of spy message */
    vmf_spy_queue_t         *next_msg;          /* points to next spy msg */
};

/* external data */
// extern vmf_handle_t         spy_channel_handle;
extern vmf_spy_tab_t          spy_channel_handle_tab;

/* local data */
#if defined EAGLE_UPDATE
    #warning "Spy Pool Size (EAGLE_UPDATE) = 500"
    #define VMF_SPY_POOL_NUM    500
#elif defined U321
    #warning "Spy Pool Size (U321) = 500"
    #define VMF_SPY_POOL_NUM    500
#else
    #define VMF_SPY_POOL_NUM    50
#endif

static vmf_spy_queue_t      *p_current_pool_msg=NULL;
static vmf_spy_queue_t      nw_vmf_spy_pool[VMF_SPY_POOL_NUM];
static vmf_spy_queue_t      *p_vmf_spy_p_first_msg=NULL;
static vmf_spy_queue_t      *p_vmf_spy_p_last_msg=NULL;
static unsigned8            vmf_spy_q_elements=0;
static pthread_mutex_t      queue_mux = PTHREAD_MUTEX_INITIALIZER;
static vmf_basic_msg_t      *pvmf_co_message=NULL;
static pthread_mutex_t      vmf_spy_mx = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t      vmf_spy_co_tx_mx = PTHREAD_MUTEX_INITIALIZER;
static unsigned16           tx_timer_id=VMF_INVALID_TIMER;
static bool                 spy_pool_init_done=false;


/* local functions */
static void         vw_vmf_router_co_tx_timeout_cb(unsigned32 system_time_ms,void *arg);
static vmf_ret_t    nw_vmf_spy_pool_init(vmf_spy_queue_t *pnw_vmf_spy_pool);
static vmf_ret_t    nw_vmf_spy_pool_get(vmf_spy_queue_t *pnw_vmf_spy_pool,vmf_spy_queue_t **ppmsg);
static vmf_ret_t    nw_vmf_spy_q_get_first_msg(vmf_spy_queue_t **pp_q_msg);
static vmf_ret_t    nw_vmf_spy_q_peek_first_msg(vmf_spy_queue_t **pp_q_msg);
static vmf_ret_t    nw_vmf_spy_q_add_msg(vmf_spy_queue_t *p_q_msg);
static vmf_ret_t    nw_vmf_spy_pool_free(vmf_spy_queue_t *p_q_msg);
static void         vw_vmf_router_co_tx_timeout_cb(unsigned32 system_time_ms,void *arg);
static vmf_ret_t    nw_vmf_spy_q_add_and_get_new(vmf_spy_queue_t *pnw_vmf_spy_pool,vmf_spy_queue_t **pp_q_msg);
static vmf_ret_t    vw_vmf_router_co_start_tx_timer(unsigned32 system_time_ms);


/*****************************************************************************
    global functions
******************************************************************************/


/***************************************************************************//**
 *
 *   Send a message using the IPC to the spy
 *
 *   \param[in]     client_handle -- where to send
 *   \param[in]     message       -- pointer to the message to send
 *   \param[in]     msg_size      -- actual message size
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_spy_send_msg (unsigned8 *message, unsigned16 msg_size,unsigned8 *raw_buffer)
{
    vmf_ret_t       ret_val=VMF_OK;

    UNUSED_PARAM(msg_size);
    UNUSED_PARAM(raw_buffer);

    /* init message pool */
    if (false == spy_pool_init_done)
    {
        ret_val = nw_vmf_spy_pool_init((vmf_spy_queue_t *)&nw_vmf_spy_pool);
        if (VMF_OK == ret_val)
        {
            spy_pool_init_done = true;
        }
        else
        {
           VMF_RQ_ERROR("nw_vmf_spy_send_msg() nw_vmf_spy_pool_init() failed with %d",(int)ret_val);
        }
    }

    /* allocate startup queue */
    if (NULL == p_current_pool_msg)
    {
        if (vmf_spy_q_elements >= VMF_SPY_POOL_NUM)
        {
            /* no queue left */
            VMF_RQ_PRINTF("nw_vmf_spy_send_msg() start message timer with 100ms");
            ret_val = vw_vmf_router_co_start_tx_timer(VMF_ROUTER_SPY_TX_NOW);
            return VMF_ERR_NO_MORE_DATA;
        }

        /* get a buffer for the startup queue */
        ret_val = nw_vmf_spy_q_add_and_get_new((vmf_spy_queue_t *)&nw_vmf_spy_pool,&p_current_pool_msg);
        if (VMF_OK == ret_val)
        {
            if (NULL == p_current_pool_msg)
            {
               VMF_RQ_ERROR("nw_vmf_spy_send_msg() nw_vmf_spy_q_add_and_get_new() returned NULL pointer");
               ret_val = VMF_ERR_NULL_POINTER;
            }
        }
        else
        {
           VMF_RQ_PRINTF("nw_vmf_spy_send_msg() nw_vmf_spy_q_add_and_get_new() failed with %d, vmf_spy_q_elements=%d",ret_val,vmf_spy_q_elements);
        }
    }

    if (ret_val != VMF_OK)
    {
        return  ret_val;
    }

    VMF_MUX_LOCK(&vmf_spy_co_tx_mx);
    pvmf_co_message = p_current_pool_msg->pvmf_spy_msg;
    if (nw_vmf_is_spy_avail()==false)
    {
        /* spy not connected yet */
        /* add the vmf-message to the co-message */
        ret_val = nw_vmf_co_client_add_msg(0,&vmf_spy_mx, pvmf_co_message, (VMF_ROUTER_STARTUP_QLEN - 128U), (vmf_basic_msg_t *)message, false);
        VMF_RQ_PRINTF("nw_vmf_spy_send_msg(0) nw_vmf_co_client_add_msg() ret =%d",ret_val);
        if (VMF_OK != ret_val)
        {
            /* co-message buffer full ? - add mesage to startup queue */
            VMF_RQ_PRINTF("nw_vmf_spy_send_msg()  nw_vmf_co_client_add_msg() failed with %d", ret_val);
            ret_val = nw_vmf_spy_q_add_and_get_new((vmf_spy_queue_t *)&nw_vmf_spy_pool,&p_current_pool_msg);
            if (NULL != p_current_pool_msg)
            {
                pvmf_co_message = p_current_pool_msg->pvmf_spy_msg;
                if (VMF_OK != ret_val)
                {
                    VMF_RQ_ERROR("nw_vmf_spy_send_msg(0)  nw_vmf_spy_q_add_and_get_new() failed with %d, vmf_spy_q_elements=%d", ret_val,vmf_spy_q_elements);
                }

                /* add org message to ne co-message buffer */
                ret_val = nw_vmf_co_client_add_msg(0,&vmf_spy_mx, pvmf_co_message, (VMF_ROUTER_STARTUP_QLEN - 128U), (vmf_basic_msg_t *)message, false);
                if (VMF_OK != ret_val)
                {
                    VMF_RQ_PRINTF("nw_vmf_spy_send_msg(0)  nw_vmf_co_client_add_msg() failed with %d", ret_val);
                }
            }
            else
            {
                VMF_RQ_PRINTF("nw_vmf_spy_send_msg()  nw_vmf_co_client_add_msg() returned NULL pointer num buffers=%d", vmf_spy_q_elements);
            }
        }
    }
    else
    {
        /* spy is connected */
        {
            /* add the vmf-message to the startup queue */
            ret_val = nw_vmf_co_client_add_msg(0,&vmf_spy_mx, pvmf_co_message, (VMF_ROUTER_STARTUP_QLEN - 128U), (vmf_basic_msg_t *)message, false);
            VMF_RQ_PRINTF("nw_vmf_spy_send_msg(1) nw_vmf_co_client_add_msg() ret =%d len=%d",ret_val,pvmf_co_message->data.length);
            if (VMF_OK != ret_val)
            {
                {
                    VMF_RQ_PRINTF("nw_vmf_spy_send_msg()  nw_vmf_co_client_add_msg() failed with %d - default ", ret_val);
                    /* all other errors   */
                    /* transfer co-buffer */

                    ret_val = nw_vmf_spy_q_add_and_get_new((vmf_spy_queue_t*)&nw_vmf_spy_pool,&p_current_pool_msg);
                    if (VMF_OK != ret_val)
                    {
                        VMF_RQ_PRINTF("nw_vmf_spy_send_msg(2)  nw_vmf_spy_q_add_and_get_new() failed with %d, vmf_spy_q_elements=%d", ret_val,vmf_spy_q_elements);
                    }
                    else
                    {
                        if (NULL != p_current_pool_msg)
                        {
                            pvmf_co_message = p_current_pool_msg->pvmf_spy_msg;

                            /* add the org vmf message to the new co-buffer */
                            ret_val = nw_vmf_co_client_add_msg (0,&vmf_spy_mx, pvmf_co_message, (VMF_ROUTER_STARTUP_QLEN - 128U), (vmf_basic_msg_t *)message, false);
                            VMF_RQ_PRINTF("nw_vmf_spy_send_msg(2) nw_vmf_co_client_add_msg() ret =%d len=%d",ret_val,pvmf_co_message->data.length);

                            /* start transfer now */
                            ret_val = vw_vmf_router_co_start_tx_timer(10);
                            if (VMF_OK != ret_val)
                            {
                                VMF_RQ_ERROR("nw_vmf_spy_send_msg()  vw_vmf_router_co_start_tx_timer() failed with %d", ret_val);
                            }
                        }
                    }
                }
            }
            /* start transfer timer if not already started */
#if 1
            if (VMF_INVALID_TIMER == tx_timer_id)
            {
                {
                    VMF_RQ_PRINTF("nw_vmf_spy_send_msg() start message timer with 250ms");
                    ret_val = vw_vmf_router_co_start_tx_timer(VMF_ROUTER_SPY_TX_TIMEOUT);
                    if (ret_val != VMF_OK)
                    {
                        VMF_RQ_ERROR("nw_vmf_spy_send_msg() vmf_timer_start() failed with %d", ret_val);
                    }
                }
            }
#endif
        }
    }
    VMF_MUX_UNLOCK(&vmf_spy_co_tx_mx);
    return ret_val;
}



 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_spy_q_add_msg  ()
 *
 *   Description:   add a message to the queue and get new message
 *
 *
 *   Parameters:    pp_q_msg       (input/output)  address of message pointer
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_spy_q_add_and_get_new(vmf_spy_queue_t *pnw_vmf_spy_pool,vmf_spy_queue_t **pp_q_msg)
{
    vmf_spy_queue_t    *p_q_msg=NULL;
    vmf_ret_t           vmf_ret=VMF_OK;

    VMF_RQ_PRINTF("nw_vmf_spy_q_add_an_get_new()");

    /* argument check */
    if (NULL == pp_q_msg)
    {
        VMF_RQ_ERROR("nw_vmf_spy_q_add_and_get_new() pp_q_msg = NULL");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else
    {
        p_q_msg = *pp_q_msg;
    }
    if (NULL != p_q_msg)
    {
        /* add message to queue */
        VMF_RQ_PRINTF("nw_vmf_spy_q_add_and_get_new() add message to queue");
        *pp_q_msg = NULL;
        vmf_ret = nw_vmf_spy_q_add_msg(p_q_msg);
    }

    if (VMF_OK == vmf_ret)
    {
        /* get new buffer */
        VMF_RQ_PRINTF("nw_vmf_spy_q_add_and_get_new() get new buffer");
        vmf_ret = nw_vmf_spy_pool_get(pnw_vmf_spy_pool,pp_q_msg);
        if (vmf_ret != VMF_OK)
        {
            VMF_RQ_PRINTF("nw_vmf_spy_pool_get() failed with %d",vmf_ret);
        }
        VMF_RQ_PRINTF("nw_vmf_spy_q_add_and_get_new() got buffer %p",*pp_q_msg);
    }

    return vmf_ret;
}


 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_spy_pool_init  ()
 *
 *   Description:   init the message pool
 *
 *
 *   Parameters:    pnw_vmf_spy_pool    (input)  address of message pool
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_spy_pool_init(vmf_spy_queue_t *pnw_vmf_spy_pool)
{
    unsigned    cnt;
    vmf_ret_t   vmf_ret=VMF_OK;

    VMF_RQ_PRINTF("nw_vmf_spy_pool_init()");

    /* argument check */
    if (NULL == pnw_vmf_spy_pool)
    {
        vmf_ret = VMF_ERR_NULL_POINTER;
    }

    VMF_MUX_LOCK(&queue_mux);
    if (VMF_OK == vmf_ret)
    {
        for (cnt=0;cnt<VMF_SPY_POOL_NUM;cnt++)
        {
            pnw_vmf_spy_pool[cnt].pvmf_spy_msg = NULL;
            pnw_vmf_spy_pool[cnt].next_msg = NULL;
            pnw_vmf_spy_pool[cnt].index = cnt;
            pnw_vmf_spy_pool[cnt].in_use = 0;
        }
    }
    VMF_MUX_UNLOCK(&queue_mux);

    return vmf_ret;
}



 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_spy_pool_get  ()
 *
 *   Description:   get a message from the pool
 *                  pool is set up as linear list
 *
 *   Parameters:    pnw_vmf_spy_pool    (input)  address of message pool
 *                  ppmsg               (output) address of message pointer
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_spy_pool_get(vmf_spy_queue_t *pnw_vmf_spy_pool,vmf_spy_queue_t **ppmsg)
{
    unsigned    cnt;
    vmf_ret_t   vmf_ret=VMF_OK;

    VMF_RQ_PRINTF("nw_vmf_spy_pool_get()");

    /* argument check */
    if (NULL == pnw_vmf_spy_pool)
    {
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else if (NULL == ppmsg)
    {
        vmf_ret = VMF_ERR_NULL_POINTER;
    }

    VMF_MUX_LOCK(&queue_mux);
    if (VMF_OK == vmf_ret)
    {
        *ppmsg = NULL;

        vmf_ret = VMF_ERROR;
        /* search a free pool entry */
        for (cnt=0;cnt<VMF_SPY_POOL_NUM;cnt++)
        {
            if (0 == pnw_vmf_spy_pool[cnt].in_use )
            {
                /* found a free entry in the pool */
                VMF_RQ_PRINTF("nw_vmf_spy_pool_get() found free pool entry %d",cnt);
                vmf_ret = VMF_OK;
                if (NULL == pnw_vmf_spy_pool[cnt].pvmf_spy_msg)
                {
                    /* get a new message buffer if needed */
                    VMF_RQ_PRINTF("nw_vmf_spy_pool_get() get new buffer with len %d",VMF_ROUTER_STARTUP_QLEN);
                    vmf_ret = nw_vmf_co_client_get_buffer((void **)&(pnw_vmf_spy_pool[cnt].pvmf_spy_msg),VMF_ROUTER_STARTUP_QLEN+1);
                    if (VMF_OK == vmf_ret)
                    {
                        unsigned8   *ptr;
                        VMF_RQ_PRINTF("nw_vmf_spy_pool_get() got new buffer =%p",pnw_vmf_spy_pool[cnt].pvmf_spy_msg);
                        ptr = (unsigned8*)pnw_vmf_spy_pool[cnt].pvmf_spy_msg;
                        ptr[VMF_ROUTER_STARTUP_QLEN]=0xaa;
                    }
                    else
                    {
                        VMF_RQ_PRINTF("nw_vmf_spy_pool_get() nw_vmf_co_client_get_buffer() returned with error %d",vmf_ret);
                    }
                }
                pnw_vmf_spy_pool[cnt].in_use = 1;
                *ppmsg = &pnw_vmf_spy_pool[cnt];
                VMF_RQ_PRINTF("nw_vmf_spy_pool_get() set *ppmsg to  =%p",*ppmsg);
                break;
            }
        }
    }
    VMF_MUX_UNLOCK(&queue_mux);

    return vmf_ret;
}


 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_spy_pool_free  ()
 *
 *   Description:   free a message buffer
 *
 *
 *   Parameters:    p_q_msg       (input)  address of message
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_spy_pool_free(vmf_spy_queue_t *p_q_msg)
{
    vmf_ret_t   vmf_ret=VMF_OK;

    /* argument check */
    if (NULL == p_q_msg)
    {
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    VMF_RQ_PRINTF("nw_vmf_spy_pool_free(%d) %p",p_q_msg->index,p_q_msg->pvmf_spy_msg);

    VMF_MUX_LOCK(&queue_mux);
    if (VMF_OK == vmf_ret)
    {
        unsigned8 *ptr;

        /* test integrity of buffer */
        ptr = (unsigned8*)p_q_msg->pvmf_spy_msg;
        if (ptr[VMF_ROUTER_STARTUP_QLEN] != 0xaa)
        {
            VMF_RQ_ERROR("nw_vmf_spy_pool_free() %p buffer currupted!! last byte is %02x",p_q_msg->pvmf_spy_msg,ptr[VMF_ROUTER_STARTUP_QLEN]);
        }
        else
        {
            VMF_RQ_PRINTF("nw_vmf_spy_pool_free() %p buffer OK!! last byte is %02x",p_q_msg->pvmf_spy_msg,ptr[VMF_ROUTER_STARTUP_QLEN]);
        }
#if 0
        nw_vmf_co_client_free_buffer(p_q_msg->pvmf_spy_msg);
#else
        /* re-use vmf message - so empty it */
        p_q_msg->pvmf_spy_msg->data.length = 0;
        p_q_msg->pvmf_spy_msg->msg_base.base.vmf_co_num_msgs = 0;    /* num_msgs */
        p_q_msg->pvmf_spy_msg->msg_base.base.vmf_co_curr_msg = 0;    /* curr_msg */
#endif

        p_q_msg->in_use = 0;
    }
    VMF_MUX_UNLOCK(&queue_mux);

    return vmf_ret;
}





 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_spy_q_add_msg  ()
 *
 *   Description:   add a message to the queue
 *
 *
 *   Parameters:    p_q_msg       (input)  address of message
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_spy_q_add_msg(vmf_spy_queue_t *p_q_msg)
{
    vmf_ret_t   vmf_ret=VMF_OK;

    VMF_RQ_PRINTF("nw_vmf_spy_q_add_msg()");

    if (NULL == p_q_msg)
    {
        VMF_RQ_PRINTF("nw_vmf_spy_q_add_msg() VMF_ERR_NULL_POINTER");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }

    VMF_MUX_LOCK(&queue_mux);
    if (VMF_OK == vmf_ret)
    {
        if (NULL == p_vmf_spy_p_first_msg)
        {
            p_vmf_spy_p_first_msg = p_q_msg;
        }
        if (NULL != p_vmf_spy_p_last_msg)
        {
            p_vmf_spy_p_last_msg->next_msg = p_q_msg;
        }
        p_vmf_spy_p_last_msg = p_q_msg;
        p_vmf_spy_p_last_msg->next_msg = NULL;
        vmf_spy_q_elements++;
    }
    VMF_MUX_UNLOCK(&queue_mux);

    return vmf_ret;
}


 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_spy_q_get_first_msg  ()
 *
 *   Description:   get first message from queue
 *
 *
 *   Parameters:    pp_q_msg       (output)  pointer to address of message
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_spy_q_get_first_msg(vmf_spy_queue_t **pp_q_msg)
{
    vmf_ret_t   vmf_ret=VMF_OK;

    VMF_RQ_PRINTF("nw_vmf_spy_q_get_first_msg() num elements=%d",vmf_spy_q_elements);

    if (NULL == pp_q_msg)
    {
        VMF_RQ_PRINTF("nw_vmf_spy_q_get_first_msg() NULL-pointer");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else if (NULL == p_vmf_spy_p_first_msg)
    {
        VMF_RQ_PRINTF("nw_vmf_spy_q_get_first_msg() VMF_ERR_NO_MORE_DATA");
        vmf_ret = VMF_ERR_NO_MORE_DATA;
    }

    VMF_MUX_LOCK(&queue_mux);
    if (VMF_OK == vmf_ret)
    {
        /* there is a message available  */
        *pp_q_msg = p_vmf_spy_p_first_msg;
        p_vmf_spy_p_first_msg = p_vmf_spy_p_first_msg->next_msg;
        vmf_spy_q_elements--;
        VMF_RQ_PRINTF("nw_vmf_spy_q_get_first_msg() got data left elements = %d",vmf_spy_q_elements);
    }
    VMF_MUX_UNLOCK(&queue_mux);

    return vmf_ret;
}



 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_spy_q_peek_first_msg  ()
 *
 *   Description:   peek first message from queue
 *                  message is still in the queue after thi cann
 *
 *   Parameters:    pp_q_msg       (output)  pointer to address of message
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t nw_vmf_spy_q_peek_first_msg(vmf_spy_queue_t **pp_q_msg)
{
    vmf_ret_t   vmf_ret=VMF_OK;

    VMF_RQ_PRINTF("nw_vmf_spy_q_get_first_msg() num elements=%d",vmf_spy_q_elements);

    if (NULL == pp_q_msg)
    {
        VMF_RQ_PRINTF("nw_vmf_spy_q_get_first_msg() NULL-pointer");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else if (NULL == p_vmf_spy_p_first_msg)
    {
        VMF_RQ_PRINTF("nw_vmf_spy_q_get_first_msg() VMF_ERR_NO_MORE_DATA");
        vmf_ret = VMF_ERR_NO_MORE_DATA;
    }

    VMF_MUX_LOCK(&queue_mux);
    if (VMF_OK == vmf_ret)
    {
        /* there is a message available  */
        *pp_q_msg = p_vmf_spy_p_first_msg;
    }
    VMF_MUX_UNLOCK(&queue_mux);

    return vmf_ret;
}


/*************************************************************************//**
 *
 *   collector buffer timeout function
 *
 *   \param[in]     system_time_ms  -   time in ms
 *   \param[in]     arg             -   not used
 *   \return        void
 *
 ******************************************************************************/
static void vw_vmf_router_co_tx_timeout_cb(unsigned32 system_time_ms,void *arg)
{
    static unsigned16   error_cnt[VMF_MAX_SPY_NUM]={0}; /* init ALL elements to 0 */
    vmf_basic_msg_t *pvmf_basic_co_msg=NULL;
    vmf_spy_queue_t *pvmf_q_msg = NULL;
    vmf_ret_t        vmf_ret = VMF_OK;

    UNUSED_PARAM(system_time_ms);
    UNUSED_PARAM(arg);

    VMF_RQ_PRINTF2("vw_vmf_router_co_tx_timeout_cb()");
    tx_timer_id = VMF_INVALID_TIMER;

    if (nw_vmf_is_spy_avail()==false)
    {
        VMF_RQ_PRINTF("vw_vmf_router_co_tx_timeout_cb() spy not connected");
        return;
    }
    else
    {
        VMF_RQ_PRINTF("vw_vmf_router_co_tx_timeout_cb() spy is connected");
    }

    {
        /* send a message from the spy message queue */
        VMF_MUX_LOCK(&vmf_spy_co_tx_mx);
        /* peek first message from queue */
        vmf_ret = nw_vmf_spy_q_peek_first_msg(&pvmf_q_msg);
        VMF_RQ_PRINTF("vw_vmf_router_co_tx_timeout_cb() nw_vmf_spy_q_peek_first_msg() returned %d",vmf_ret);
        if (vmf_ret == VMF_OK)
        {
            int cnt;
            VMF_RQ_PRINTF("vw_vmf_router_co_tx_timeout_cb() nw_vmf_spy_q_get_first_msg=OK");

            if (NULL != pvmf_q_msg)
            {
                pvmf_basic_co_msg = pvmf_q_msg->pvmf_spy_msg;
                VMF_RQ_PRINTF("vw_vmf_router_co_tx_timeout_cb() nw_vmf_co_client_transfer_msg(%d)",pvmf_q_msg->index);

                vmf_ret = VMF_ERROR;
                /* send to all conected spies */
                for (cnt=0; cnt<VMF_MAX_SPY_NUM; cnt++)
                {
                    if (spy_channel_handle_tab.handle[cnt] != VMF_HANDLE_INVALID)
                    {
                        VMF_RQ_PRINTF3("vw_vmf_router_co_tx_timeout_cb() send to spy %d",spy_channel_handle_tab.handle[cnt]);

                        if (VMF_OK == nw_vmf_ipc_send(spy_channel_handle_tab.handle[cnt],(unsigned8*)pvmf_basic_co_msg,
                                        VMF_BASIC_MSG_LEN(pvmf_basic_co_msg->data.length)))
                        {
                            /* at least one worked */
                            VMF_RQ_PRINTF3("vw_vmf_router_co_tx_timeout_cb() send to spy %d OK",spy_channel_handle_tab.handle[cnt]);
                            error_cnt[cnt] = 0;
                            vmf_ret = VMF_OK;
                        }
                        else
                        {
                            (error_cnt[cnt])++;
                            if (error_cnt[cnt] > VMF_ROUTER_SPY_MAX_ERROR)
                            {
                                /* deregister the spy and delete the message */
                                (void)nw_vmf_delete_spy(spy_channel_handle_tab.handle[cnt]);
                                vmf_ret = VMF_OK;   /* delete message */
                            }
                        }
                    }
                }

                if (vmf_ret == VMF_OK)
                {
                    /* remove message from queue */
                    (void)nw_vmf_spy_q_get_first_msg(&pvmf_q_msg);
                    (void)nw_vmf_spy_pool_free(pvmf_q_msg);

                    /* initiate transfer of next message */
                    VMF_RQ_PRINTF("vw_vmf_router_co_tx_timeout_cb(1) start next message timer with 2ms");
                    (void)vw_vmf_router_co_start_tx_timer(VMF_ROUTER_SPY_TX_NOW);
                }
                else
                {
                    VMF_RQ_PRINTF("vw_vmf_router_co_tx_timeout_cb() - nw_vmf_co_client_transfer_msg() failed with %d",vmf_ret);
                    /* re start transfer timer */
                    VMF_RQ_PRINTF("vw_vmf_router_co_tx_timeout_cb(2) start new message timer with 250ms");
                    (void)vw_vmf_router_co_start_tx_timer(VMF_ROUTER_SPY_TX_RETRY);
                }
            }
            else
            {
                VMF_RQ_PRINTF("vw_vmf_router_co_tx_timeout_cb() - nw_vmf_spy_q_get_first_msg returned NULL pointer");
            }
        }
        else
        {
            /* no more messages in spy message queue */
            /* try to send current buffer */
            if (p_current_pool_msg != NULL)
            {
                if (p_current_pool_msg->pvmf_spy_msg->data.length > 0)
                {
                    /* add current message to spy message queue */
                    VMF_RQ_PRINTF("vw_vmf_router_co_tx_timeout_cb() add current msg to queue");
                    vmf_ret = nw_vmf_spy_q_add_and_get_new((vmf_spy_queue_t*)&nw_vmf_spy_pool,&p_current_pool_msg);
                    if (VMF_OK == vmf_ret)
                    {
                        /* start transfer timer with small value */
                        VMF_RQ_PRINTF("vw_vmf_router_co_tx_timeout_cb(3) start new message timer with 10ms");
                        (void)vw_vmf_router_co_start_tx_timer(VMF_ROUTER_SPY_TX_NOW);
                    }
                }
            }
        }
        VMF_MUX_UNLOCK(&vmf_spy_co_tx_mx);
    }
    VMF_RQ_PRINTF("vw_vmf_router_co_tx_timeout_cb() return");
}


/*************************************************************************//**
 *
 *   start a new tx-timer with given timeout
 *
 *   \param[in]     system_time_ms  -   time in ms
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t  vw_vmf_router_co_start_tx_timer(unsigned32 system_time_ms)
{
        vmf_ret_t   ret_val;

        if (VMF_INVALID_TIMER != tx_timer_id)
        {
            VMF_RQ_PRINTF2("nw_vmf_spy_send_msg() set timer %d to %dms",tx_timer_id,system_time_ms);
            ret_val = vmf_timer_set_if_smaller(tx_timer_id,system_time_ms);
        }
        else
        {
            ret_val = vmf_timer_start (&tx_timer_id, system_time_ms, vw_vmf_router_co_tx_timeout_cb,(void*)NULL);
            VMF_RQ_PRINTF2("nw_vmf_spy_send_msg() started new timer %d with %dms",tx_timer_id,system_time_ms);
        }

    return ret_val;
}



#undef _NW_VMF_ROUTER_QUEUES_C_
