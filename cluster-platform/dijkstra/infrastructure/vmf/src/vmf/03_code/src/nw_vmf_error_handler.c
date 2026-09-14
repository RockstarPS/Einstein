/****************************************************************************/
/* Copyright Statement                                                       */
/* CONFIDENTIAL - VISTEON CORPORATION                                        */
/* This is an unpublished work, which contains trade secrets, created in     */
/* 2002. Visteon Corporation owns all rights to this work and intends        */
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

  Module:             nw_vmf_error_handler.c
  Description:        vmf error handler
  Project Scope:
  Organization:       Joachim Becker
                      Visteon, TMS Software
  Version Control:
  Compiler/Assembler: gcc
  Target Hardware:    Any
  *****************************************************************************/
#define VMF_ERROR_HANDLER_C

    /* system includes */
    #include "nw_os_config.h"

#ifndef UNIT_TEST
    #include "nw_vmf_debug.h"
#else
    #include "unit_test.h"
#endif

    /* application includes */
    #include "nw_vmf_cfg.h"
    #include "nw_most_defs.h"
    #include "nw_vmf_types.h"
    #include "nw_vmf_ipc.h"
    #include "nw_vmf_router.h"
    #include "nw_vmf_error_handler.h"


/**************************************************************************//**
 *
 *   handle invalid most message
 *   depending in the message the function will send back an error response to
 *   the original sender of the message
 *
 *   \param[in]     message_buffer      pointer to the vmf message
 *   \param[in]     vmf_router_error    error reponse from the database. (nw_vmf_router_eval_message())
 *   \return        vmf return type
 *
 ******************************************************************************/
#ifdef NW_VMF_ENABLE_MOST_ERROR_HANDLER
vmf_ret_t nw_vmf_handle_invalid_most_msg (vmf_msg_t *vmf_message, vmf_ret_t vmf_router_error,unsigned8 *p_raw_msg )
{
    unsigned8               most_error=0;
    vmf_most_msg_t          *p_most_msg;
    VMF_VAR_MOST_MSG_TYP(1) vmf_most_tx_msg;
    vmf_ret_t               ret_val = VMF_OK;
    vmf_handle_t            client_handle;

    NW_VMF_ERROR_HDLR_DEBUG(5,"vmf_most_error_handler: nw_vmf_handle_invalid_most_msg()\n");

    /* argument check */
    if (NULL == vmf_message)
    {
        NW_VMF_ERROR_HDLR_DEBUG(1,"vmf_most_error_handler: NULL pointer\n");
        return (vmf_router_error);
    }

    /* check if we will (error)handle this message */

        /* check the router error */
    switch(vmf_router_error)
    {

        case VMF_ERR_ROUTER_INVALID_FB:
            most_error = MOST_ERR_FBLOCKID;             /* store error type for later use */
            NW_VMF_ERROR_HDLR_DEBUG(1,"vmf_most_error_handler: VMF_ERR_ROUTER_INVALID_FB \n");
        break;

        case VMF_ERR_ROUTER_INVALID_INST_ID:
            most_error = MOST_ERR_INSTID;               /* store error type for later use */
            NW_VMF_ERROR_HDLR_DEBUG(1,"vmf_most_error_handler: VMF_ERR_ROUTER_INVALID_INST_ID \n");
        break;

        default:
            /* there was an unknown error response from the database */
            /* we will not handle this error type */
            /* return the database error to the calling function */
            NW_VMF_ERROR_HDLR_DEBUG(1,"vmf_most_error_handler: nw_vmf_handle_invalid_most_msg() invalid router error=%d\n",vmf_router_error);
            return(vmf_router_error);
        break;
    }

    p_most_msg = (vmf_most_msg_t*)vmf_message;
    /* check if most messag is a command */
    if (!MOST_OPTYPE_COMMAND(p_most_msg->op_type))
    {
        /* we will only handle commands */
        /* return with the database error of the database */
        NW_VMF_ERROR_HDLR_DEBUG(2,"vmf_most_error_handler: optype!=command\n");
        return(vmf_router_error);
    }
    else
    {
        /*NOP*/
    }

    /* we will (error) handle this MOST message */
    /* create MOST error message */
    vmf_most_tx_msg.msg_base =      p_most_msg->msg_base;       /* copy whole message base */
    vmf_most_tx_msg.tgt_addr =      p_most_msg->src_addr;       /* always replace source and target address */
    vmf_most_tx_msg.src_addr =      p_most_msg->tgt_addr;
    vmf_most_tx_msg.channel_flag =  CHANNEL_TYPE_MOST_CTRL;     /* always a controll message */
    vmf_most_tx_msg.fblock_id =     p_most_msg->fblock_id;
    vmf_most_tx_msg.inst_id =       p_most_msg->inst_id;
    vmf_most_tx_msg.func_id =       p_most_msg->func_id;
    vmf_most_tx_msg.op_type =       MOST_OP_ERROR;              /* set error type */
    vmf_most_tx_msg.data.length =   1;                          /* size is fixed */
    vmf_most_tx_msg.data.pl[0] =    most_error;                 /* add the already stored error type */

    /* try to send error message to sender of the original message */
    /* first get the sender handle */
    client_handle = nw_vmf_router_get_client_handle(p_most_msg->msg_base.base.pid, p_most_msg->msg_base.base.client_id);
    if (client_handle < 0)
    {
        /* we could not get the sender handle - return an error ! */
        NW_VMF_ERROR_HDLR_DEBUG(0,"vmf_most_error_handler: sender handle not found\n");
        ret_val = VMF_ERR_ROUTER_SENDER_HANDLE_NOT_FOUND;
    }
    else
    {
        if (VMF_ERR_ROUTER_SEND_FAILED == nw_vmf_router_msg_send (client_handle, (unsigned8 *)&vmf_most_tx_msg, sizeof(vmf_most_tx_msg),NULL))
        {
            NW_VMF_ERROR_HDLR_DEBUG(0,"vmf_most_error_handler: transmission failed\n");
            ret_val = VMF_ERR_ROUTER_SEND_FAILED;
        }
        else
        {
            /*NOP*/
        }
    }
    return (ret_val);
}
#endif /* NW_VMF_ENABLE_MOST_ERROR_HANDLER */

#undef VMF_ERROR_HANDLER_C


