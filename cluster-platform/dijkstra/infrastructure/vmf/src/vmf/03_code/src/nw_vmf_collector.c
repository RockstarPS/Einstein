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

  Module:               nw_vmf_collector.c
  Description:          message collector functions

  Project Scope:        All QNX /Linux

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Joachim Becker - 13 August 2012

  Compiler/Assembler:   gcc /qcc
  Target Hardware:      Any

  *****************************************************************************/
#define VMF_COLL_C

#include "nw_os_config.h"

/* application includes */
#include "nw_vmf_types.h"
#include "nw_vmf_ipc.h"
#include "nw_vmf_debug.h"

/* #include "nw_vmf_cfg.h" */          /* vmf cfg file */
#include "nw_vmf_client.h"
#include "nw_vmf_client_private.h"

#include "nw_config.h"
#include "nw_vmf_timer.h"

//#define DO_CLIENT_DEBUG

#define VMF_CO_PRINTF(...)  // fprintf(ERROR_CHANNEL, "vmf_router_queue debug: "); fprintf(ERROR_CHANNEL, __VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");



 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_co_client_get_buffer  ( vmf_basic_msg_t  **pvmf_co_msg)
 *
 *   Description:   get a message collector message
 *
 *
 *   Parameters:    pvmf_co_msg       (input/output)  pointer to pointer of collector message
 *                  len               (input)         length of collector message    
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_co_client_get_buffer ( void  **ppvmf_co_msg,unsigned16 len)
{
    unsigned16  my_len;
    vmf_ret_t vmf_ret = VMF_OK;
    void *pbuffer = NULL;
    
    my_len = VMF_ALIGN4(len);
    if (NULL != *ppvmf_co_msg)
    {
        /* buffer already allocated */
        vmf_ret = VMF_OK;
    }
    else
    {
        pbuffer = nw_os_malloc(my_len);
        if (NULL == pbuffer)
        {
            /* error allocating buffer !!*/
            vmf_ret = VMF_ERR_OUT_OF_MEMORY;
        }
        else
        {
            memset(pbuffer,0,my_len);
            *ppvmf_co_msg = pbuffer;
            vmf_ret = VMF_OK;
        }
    }
    return vmf_ret;
}




 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_co_client_free_buffer  ( vmf_basic_msg_t  **pvmf_co_msg)
 *
 *   Description:   free a message collector message
 *
 *
 *   Parameters:    pvmf_co_msg       (input)  pointer to collector buffer
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
void nw_vmf_co_client_free_buffer ( void  *pvmf_co_msg)
{
    if (NULL != pvmf_co_msg)
    {
        nw_os_free(pvmf_co_msg);
    }
}


 /**************************************************************************//**
 *
 *   Function Name: nw_vmf_co_client_transfer_msg  
 *                      vmf_handle_t tx_hdl, pthread_mutex_t *pmux, vmf_basic_msg_t  *pvmf_co_msg)
 *   Description:   transfer a message collector message to the vmf server
 *
 *
 *   Parameters:    tx_hdl            (input)          tx-handle
 *                  pmux              (input)          pointer to mutex
 *                  vmf_client_id     (input)          client id  
 *                  pvmf_co_msg       (input/output)   collector message
 *
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_co_client_transfer_msg ( vmf_handle_t tx_hdl, pthread_mutex_t *pmux, vmf_basic_msg_t  *pvmf_co_msg)
{
    vmf_ret_t vmf_ret = VMF_OK;
    unsigned16 u_len;

    /* argument check */
    if ((NULL == pvmf_co_msg) || (NULL == pmux))
    {
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    /* is there data to send ? */
    else if (0 == pvmf_co_msg->data.length)
    {
        /* nothing to send, so we are done */
        VMF_CO_PRINTF("nw_vmf_co_client_transfer_msg(%d) len=%d",tx_hdl,VMF_BASIC_MSG_HEADER_SIZE + pvmf_co_msg->data.length);
    }
    else
    {
        /* mark message as collected message */
        VMF_MUX_LOCK(pmux);

        /* send message */
        u_len = VMF_BASIC_MSG_LEN(pvmf_co_msg->data.length); 
        vmf_ret = nw_vmf_ipc_send(tx_hdl,(unsigned8*)pvmf_co_msg, u_len);
        if (VMF_OK == vmf_ret)
        {
            /* clear co message */
            pvmf_co_msg->data.length = 0;
            pvmf_co_msg->msg_base.base.vmf_co_num_msgs = 0;    /* num_msgs */
            pvmf_co_msg->msg_base.base.vmf_co_curr_msg = 0;    /* curr_msg */
        }
        
        VMF_MUX_UNLOCK(pmux);

        if (VMF_OK != vmf_ret)
        {
            VMF_CO_PRINTF("nw_vmf_co_client_transfer_msg() - nw_vmf_ipc_send() failed with %d",vmf_ret);
        }
        else
        {
            VMF_CO_PRINTF("nw_vmf_co_client_transfer_msg() - nw_vmf_ipc_send() OK");
        }
    }
    
    return vmf_ret;
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_co_client_add_msg  ( vmf_client_id_t   vmf_client_id,
 *                                              pthread_mutex_t  *pco_mutex.
 *                                              vmf_basic_msg_t  *vmf_co_msg,
 *                                              unsigned16        co_msg_len,
 *                                              vmf_basic_msg_t  *vmf_msg,
 *                                              bool              check_ev_grp)
 *   Description:   add a message to the collector message
 *
 *
 *   Parameters:    client_id         (input) vmf client id - debug only
 *                  pco_mutex         (input) pointer to mutex
 *                  pvmf_co_msg       (input/output) collector message
 *                  co_msg_len        (input) size of collector message buffer
 *                  pvmf_msg          (input) vmf message to add to co-message
 *                  check_ev_grp      (input) true if group and event is tested
 *
 *
 *   Return value:  vmf_ret_t    
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_co_client_add_msg ( vmf_client_id_t vmf_client_id, pthread_mutex_t *pco_mutex, vmf_basic_msg_t  *pvmf_co_msg, unsigned16 co_msg_buff_len, vmf_basic_msg_t  *pvmf_msg, bool check_ev_grp)
{
    vmf_basic_msg_t tmp_msg;
    vmf_ret_t vmf_ret = VMF_OK;
    unsigned16  co_msg_len=0;
    unsigned16  co_msg_pl_len = 0;
    unsigned16  vmf_msg_len=0;
#ifdef DO_CLIENT_DEBUG
    unsigned16  vmf_msg_pl_len=0;
#endif    
    /* argument check */
    if (NULL == pvmf_co_msg)
    {
        NW_VMF_DEBUG_ERROR("vmf-client-lib: cid =%d nw_vmf_co_client_add_msg() - pvmf_co_msg=NULL",vmf_client_id);
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else if (NULL == pvmf_msg)
    {
        NW_VMF_DEBUG_ERROR("vmf-client-lib: cid=%d nw_vmf_co_client_add_msg() - pvmf_msg=NULL",vmf_client_id);
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else if (NULL == pco_mutex)
    {
        NW_VMF_DEBUG_ERROR("vmf-client-lib: cid=%d nw_vmf_co_client_add_msg() - pco_mutex=NULL",vmf_client_id);
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else if (COL_VMF_MSG == pvmf_co_msg->msg_base.base.co_msg_type)
    {
#ifdef DO_CLIENT_DEBUG
        NW_VMF_DEBUG_INFO("nw_vmf_co_client_add_msg(%d) - already a co-message ",vmf_client_id);
#endif
        vmf_ret = VMF_ERR_NOT_SUPPORTED;
    }
    else
    {
        /* check the message type and get the length of the message */
        vmf_ret = nw_vmf_co_client_get_msg_len((vmf_msg_t*)pvmf_msg,&vmf_msg_len);
        if (pvmf_msg->msg_base.base.msg_type ==  MSG_TYPE_BASIC_MESSAGE)
        {
#ifdef DO_CLIENT_DEBUG
                NW_VMF_DEBUG_INFO("nw_vmf_co_client_add_msg() basic msg"); 
#endif
        }
        else
        {
            /* this seems to be a ctrl or most message - copy message as payload to a temp vmf basic message */
            memcpy((void*)&(tmp_msg.msg_base),(void*)&(pvmf_msg->msg_base),sizeof(pvmf_msg->msg_base));     /* copy message header to co buffer */
#ifdef DO_CLIENT_DEBUG
            NW_VMF_DEBUG_INFO("nw_vmf_co_client_add_msg() embedd message with type %d ",tmp_msg.msg_base.base.msg_type); 
#endif            
            tmp_msg.msg_base.base.msg_type = MSG_TYPE_BASIC_EMBEDDED_MESSAGE;
            nw_os_smemcpy (&tmp_msg.data.pl,VMF_CLIENT_DATA_SIZE_STANDARD,pvmf_msg,vmf_msg_len);
            tmp_msg.data.length = vmf_msg_len;
            /* get size of new message */
            vmf_ret = nw_vmf_co_client_get_msg_len((vmf_msg_t*)&tmp_msg,&vmf_msg_len); 
            pvmf_msg = &tmp_msg;
            vmf_ret = VMF_OK;
        }
    }
    
    if (VMF_OK == vmf_ret)
    {
        VMF_MUX_LOCK(pco_mutex);
        
        /* get message length */
        co_msg_pl_len  = pvmf_co_msg->data.length;
        co_msg_len     = VMF_BASIC_MSG_LEN(co_msg_pl_len);
        
        /* will the message fit ?*/
        if (vmf_msg_len >= (co_msg_buff_len - co_msg_len))
        {
            /* it will not fit */
#ifdef DO_CLIENT_DEBUG
            NW_VMF_DEBUG_INFO("vmf-client-lib: cid=%d nw_vmf_co_client_add_msg() - message will not fit into buffer - mesg-len=%d,  room left=%d",vmf_client_id,vmf_msg_len,co_msg_buff_len - co_msg_len);
#endif        
            vmf_ret = VMF_ERR_CO_BUFFER;
        }
        else
        {
            /* copy message to collector-buffer */
            /* the vmf messages inside the collector buffer are not aligned!!! */
            
            /* is this the first message in the co-buffer ? */
            if (0 == co_msg_pl_len)
            {
                /* transfer message base with event and group to co buffer */
                memcpy((void*)&(pvmf_co_msg->msg_base),(void*)&(pvmf_msg->msg_base),sizeof(pvmf_msg->msg_base));     /* copy message header to co buffer */
                pvmf_co_msg->data.length = 0;                   /* no payload - we need only the header */
                pvmf_co_msg->msg_base.base.vmf_co_num_msgs = 0;    /* num_msgs */
                pvmf_co_msg->msg_base.base.vmf_co_curr_msg = 0;    /* curr_msg */
                pvmf_co_msg->msg_base.base.msg_type = MSG_TYPE_BASIC_MESSAGE;
                if (false != check_ev_grp)
                {
                    pvmf_co_msg->msg_base.base.co_msg_type = COL_VMF_MSG;
#ifdef DO_CLIENT_DEBUG
                    NW_VMF_DEBUG_INFO("nw_vmf_co_client_add_msg(%d), COL_VMF_MSG message, vmf_msg_pl_len=%d",vmf_client_id,vmf_msg_pl_len);
#endif
                    }
                else
                {
                    /* this message is send to the spy */
                    pvmf_co_msg->msg_base.base.co_msg_type = COL_VMF_MSG_SPY;
#ifdef DO_CLIENT_DEBUG
                    NW_VMF_DEBUG_INFO("nw_vmf_co_client_add_msg(%d), COL_VMF_MSG_SPY message, vmf_msg_pl_len=%d",vmf_client_id,vmf_msg_pl_len);
#endif
                }
            }
            
            {
                /* only collect messages with same group like the co message
                   group  are collected (if check_ev_grp is true) otherwise all 
                   messages are collected */

                /* test group */   
                if ((pvmf_co_msg->msg_base.id.group != pvmf_msg->msg_base.id.group) && check_ev_grp)
                {
                    /* we will not collect this message */
#ifdef DO_CLIENT_DEBUG
                    NW_VMF_DEBUG_INFO("nw_vmf_co_client_add_msg(%d) group changed",vmf_client_id);
#endif
                    vmf_ret = VMF_ERR_NO_CO_MSG;
                }
                else
                {
                    /* copy message to co-buffer */
                    memcpy(&(pvmf_co_msg->data.pl[co_msg_pl_len]),pvmf_msg,vmf_msg_len);
                    /* calc new payload len*/
                    co_msg_pl_len += vmf_msg_len;
                    pvmf_co_msg->data.length = co_msg_pl_len;
                    pvmf_co_msg->msg_base.base.vmf_co_num_msgs++;  /* number of vmf messages in this buffer */
                    vmf_ret = VMF_OK;
                }
            }
        }
#ifdef DO_CLIENT_DEBUG
        NW_VMF_DEBUG_INFO("nw_vmf_co_client_add_msg(%d) co-buffer-len=%d",vmf_client_id, co_msg_pl_len);    
#endif
        VMF_MUX_UNLOCK(pco_mutex);
    }
  
    return vmf_ret;
}




/**************************************************************************//**
 *
 *   Description:   get next message from the co-buffer
 *
 *
 *   Parameters:    msg_num           (input) number of message read from co-buffer 
 *                                            first message has index 0
 *                  pco_mutex         (input) pointer to mutex
 *                  pvmf_co_msg       (input) collector message buffer
 *                  co_msg_len        (input) size of collector message buffer
 *                  pvmf_msg          (inout) vmf message destination buffer
 *                  msg_buffer_len    (input) size of destination buffer
 *
 *
 *   Return value:  vmf_ret_t    
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_co_client_get_next_co_msg ( vmf_basic_msg_t  *pvmf_co_msg, unsigned16 co_msg_buff_len, vmf_basic_msg_t  *pvmf_dest_msg, unsigned16 msg_buffer_len)
{
    vmf_ret_t   vmf_ret = VMF_OK;
    unsigned8   current_msg=0;
    unsigned8   num_msgs=0;
    unsigned8   client_count=0;

    UNUSED_PARAM(co_msg_buff_len);

    /* argument check */
    if (NULL == pvmf_co_msg)
    {
        NW_VMF_DEBUG_ERROR("vmf-client-lib: nw_vmf_co_client_next_next_co_msg() - pvmf_co_msg=NULL");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else if (NULL == pvmf_dest_msg)
    {
        NW_VMF_DEBUG_ERROR("vmf-client-lib: nw_vmf_co_client_next_next_co_msg() - *pvmf_msg=NULL");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else if (0 == msg_buffer_len)
    {
        NW_VMF_DEBUG_ERROR("vmf-client-lib: nw_vmf_co_client_next_next_co_msg() - msg_buffer_len=0");
        vmf_ret = VMF_ERR_OUT_OF_RANGE;
    }
    else
    {
        /* check if last message is reached */
        num_msgs = pvmf_co_msg->msg_base.base.vmf_co_num_msgs;
        current_msg = pvmf_co_msg->msg_base.base.vmf_co_curr_msg;
        client_count = pvmf_co_msg->msg_base.base.client_count;  /* use client count from co-buffer */
        
        
        if (current_msg >= num_msgs)
        {
            /* last message read */
            pvmf_co_msg->msg_base.base.vmf_co_num_msgs = 0;        /* num_msgs */
            pvmf_co_msg->msg_base.base.vmf_co_curr_msg = 0;        /* curr_msg */
            vmf_ret = VMF_ERR_NO_MORE_DATA;     
        }
        else
        {
            #define     len_offset offsetof(vmf_basic_msg_t,data.length)
            unsigned8   msg_num=0;
            unsigned8   *pmsg_ptr=NULL;
            unsigned16  msg_pl_len=0;
            unsigned16  msg_len=0;
            
            pmsg_ptr = pvmf_co_msg->data.pl;                    /* address of first collected VMF msg */
            memcpy (&msg_pl_len,&(pmsg_ptr[len_offset]),sizeof(unsigned16));
            msg_len = VMF_BASIC_MSG_LEN(msg_pl_len);
            for (msg_num = 0; msg_num < current_msg; msg_num++)
            {
                /* get pl length of the current vmf message */
                /* we can not just cast to a vmf_basic_msg_t because the messages */
                /* in the buffer are not aligned !!                               */
                pmsg_ptr += msg_len;
                memcpy (&msg_pl_len,&(pmsg_ptr[len_offset]),sizeof(msg_pl_len));
                msg_len = VMF_BASIC_MSG_LEN(msg_pl_len);
            }
           
            /* pmsg_ptr is now pointing to the requested vmf-message */
            current_msg++;
            pvmf_co_msg->msg_base.base.vmf_co_curr_msg = current_msg;
            pvmf_dest_msg->msg_base.base.client_count  = client_count;
            nw_os_smemcpy(pvmf_dest_msg,msg_buffer_len,pmsg_ptr,msg_len);
            
            vmf_ret = VMF_OK;
        }
    }
    
    return vmf_ret;
}



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_co_client_is_co_msg  ( vmf_basic_msg_t  *vmf_co_msg)
 *   Description:   check if collector message
 *
 *
 *   Parameters:    pvmf_msg       (input) pointer to vmf basic message
 *
 *
 *   Return value:  vmf_ret_t      VMF_OK if co-message    
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_co_client_is_co_msg (vmf_basic_msg_t  *pvmf_co_msg)
{   
    vmf_ret_t   vmf_ret = VMF_OK;

    /* argument check */
    if (NULL == pvmf_co_msg)
    {
        NW_VMF_DEBUG_ERROR("vmf-client-lib:nw_vmf_co_client_is_co_msg() - pvmf_co_msg=NULL");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else if (COL_VMF_MSG == pvmf_co_msg->msg_base.base.co_msg_type)
    {
        vmf_ret = VMF_OK;
    }
    else
    {
        /* no co-message */
        vmf_ret = VMF_ERROR;
    }
    
    return vmf_ret;
}



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_co_client_get_msg_len  ( vmf_basic_msg_t  *vmf_co_msg)
 *   Description:   get the length of a vmf message
 *
 *
 *   Parameters:    pvmf_msg       (input) pointer to the vmf message
 *
 *
 *   Return value:  vmf_ret         vmf error type    
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_co_client_get_msg_len (vmf_msg_t  *pvmf_co_msg,unsigned16 *plen)
{  
    msg_type_t  msg_type;
    vmf_ret_t   vmf_ret=VMF_OK;
    
    /* argument check */
    if (NULL == pvmf_co_msg)
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_co_client_get_msg_len pvmf_co_msg NULL-Pointer");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else if (NULL == plen)
    {
        NW_VMF_DEBUG_ERROR("nw_vmf_co_client_get_msg_len plen NULL-Pointer");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else
    {
        *plen = 0;
        msg_type = pvmf_co_msg->vmf_basic_msg.msg_base.base.msg_type;

        switch (msg_type)
        {
            case MSG_TYPE_MOST_MESSAGE:
                *plen = sizeof(VMF_VAR_MOST_MSG_TYP(0)) + ((vmf_most_msg_t*)pvmf_co_msg)->data.length;
                vmf_ret = VMF_ERR_NO_CO_MSG;
            break;

            case MSG_TYPE_BASIC_EMBEDDED_MESSAGE:
                /*  no break */
            case MSG_TYPE_BASIC_MESSAGE:
            {
                *plen = VMF_BASIC_MSG_HEADER_SIZE + ((vmf_basic_msg_t*)pvmf_co_msg)->data.length;
            }

            break;

            case MSG_TYPE_CONNECT:
                *plen = sizeof(vmf_ctrl_msg_connect_t);
            break;

            case MSG_TYPE_REGISTER_EXT_MOST_LINK:
                *plen = sizeof(vmf_ctrl_msg_register_ext_most_link_t);
            break;

            case MSG_TYPE_REGISTER_MOST_FBLOCK:
                *plen = sizeof(vmf_ctrl_msg_register_most_fblock_t);
            break;

            case MSG_TYPE_DE_REGISTER_MOST_FBLOCK:
                *plen = sizeof(vmf_ctrl_msg_de_register_most_fblock_t);
            break;

            case MSG_TYPE_REGISTER_MOST_SHADOW:
                *plen = sizeof(vmf_ctrl_msg_register_most_shadow_t);
            break;

            case MSG_TYPE_DE_REGISTER_MOST_SHADOW:
                *plen = sizeof(vmf_ctrl_msg_de_register_most_shadow_t);
            break;

            case MSG_TYPE_REGISTER_MSG_GROUPS:
                *plen = sizeof(VMF_VAR_CTRL_MSG_REGISTER_MSG_GROUP_TYP(0));
                *plen += ((vmf_ctrl_msg_register_msg_group_t*)pvmf_co_msg)->groups_num;
            break;

            case MSG_TYPE_DE_REGISTER_MSG_GROUPS:
                *plen = sizeof(VMF_VAR_CTRL_MSG_REGISTER_MSG_GROUP_TYP(0));
                *plen += ((vmf_ctrl_msg_register_msg_group_t*)pvmf_co_msg)->groups_num;
            break;

            case MSG_TYPE_REGISTER_SPY:
                *plen = sizeof(vmf_ctrl_msg_register_spy_t);
            break;

            case MSG_TYPE_REGISTER_TRACE_SERVER:
                *plen = sizeof(vmf_ctrl_msg_register_trace_server_t);
            break;

            case MSG_TYPE_DISCONNECT:
                *plen = sizeof(vmf_ctrl_msg_connect_t);
            break;
            
            default:
                vmf_ret = VMF_ERR_NO_CO_MSG;
            break;
        }
    }
       
/*    NW_VMF_DEBUG_INFO("nw_vmf_co_client_get_msg_len vmf_ret=%d, msg-type=%d, len=%d",vmf_ret,msg_type,*plen); */
    
    return vmf_ret;
}


#undef VMF_COLL_C
    
