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

  Module:               nw_vmf_rem_server_rpc.c
  Description:          server side of rpc

  Project Scope:        Beethoven VM platform

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   Visual Studio
  Target Hardware:      Any

  *****************************************************************************/
#define PREVENT_MEMORY_CRASH


#ifdef VMF_REM_SERVER_UNIT_TEST
#include "nw_vmf_rem_server_unit_test.h"
#endif

#include "nw_vmf_rem.h"
#include "nw_vmf.h"
#include "nw_vmf_cfg.h"
#ifndef VMF_REM_SERVER_UNIT_TEST
#include "nw_vmf_trace.h"
#endif

#ifdef VMF_REM_SERVER_UNIT_TEST
#define VMF_REM_SERV_STATIC
#else
#define VMF_REM_SERV_STATIC static
#endif

extern 	   unsigned8	vmf_trace_trid;


/* local function declaration */
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_connect(vmf_rpc_msg_t *p_rpc_msg);
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_reg_msg_grp(vmf_rpc_msg_t *p_rpc_msg);
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_de_reg_msg_grp(vmf_rpc_msg_t *p_rpc_msg);
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_reg_ext_most_link(vmf_rpc_msg_t *p_rpc_msg);
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_reg_spy(vmf_rpc_msg_t *p_rpc_msg);
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_reg_most_fblock(vmf_rpc_msg_t *p_rpc_msg);
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_de_reg_most_fblock(vmf_rpc_msg_t *p_rpc_msg);
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_reg_most_shadow(vmf_rpc_msg_t *p_rpc_msg);
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_de_reg_most_shadow(vmf_rpc_msg_t *p_rpc_msg);
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_send_most_async(vmf_rpc_msg_t *p_rpc_msg);
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_send_most_ctrl(vmf_rpc_msg_t *p_rpc_msg);
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_send_basic(vmf_rpc_msg_t *p_rpc_msg);
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_send(vmf_rpc_msg_t *p_rpc_msg);
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_receive(vmf_rpc_msg_t *p_rpc_msg,vmf_rpc_response_t *p_response);
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_disconnect(vmf_rpc_msg_t *p_rpc_msg);
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_timed_receive(vmf_rpc_msg_t *p_rpc_msg,vmf_rpc_response_t *p_response,unsigned16 timeout);

/*************************************************************************//**
 *
 *   decode rpc messages from a remote client \n
 *   NOTE:
 *
 *
 *   \param[in] void
 *   \return    vmf_error_t
 *
 ******************************************************************************/
vmf_error_t vmf_client_rpc_decoder(vmf_rpc_msg_t *p_rpc_msg,vmf_rpc_response_t *p_response,unsigned16 timeout)
{
    vmf_error_t vmf_ret=VMF_ERR_NOT_SUPPORTED;

    if (NULL == p_rpc_msg)
    {
        NW_REM_VMF_DEBUG_ERROR ("vmf_client_rpc_decoder() p_rpc_msg NULL pointer");
	    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_rem","vmf_client_rpc_decoder","vmf_client_rpc_decoder() p_rpc_msg NULL pointer");
        return VMF_ERR_NULL_POINTER;
    }

    if (NULL == p_response)
    {
        NW_REM_VMF_DEBUG_ERROR ("vmf_client_rpc_decoder() p_response NULL pointer");
	    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_rem","vmf_client_rpc_decoder","vmf_client_rpc_decoder() p_response NULL pointer");
        return VMF_ERR_NULL_POINTER;
    }    
    
    /* start to fill reponse message */
    p_response->r_cid = p_rpc_msg->r_cid; 
    p_response->rpc_id = p_rpc_msg->rpc_id;
    p_response->msg_length.length = sizeof(vmf_rpc_response_t);     /* set default size */
                                                                    /* has to be changed if */
                                                                    /* payload is send !! */

    switch(p_rpc_msg->rpc_id)
    {
        case VMF_RPC_FKT_CONNECT:
		    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_CONNECT");
            vmf_ret = vmf_client_rpc_decoder_connect(p_rpc_msg);
            break;


        case VMF_RPC_FKT_CONNECT_ASYNC:
		    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_CONNECT_ASYNC");
            vmf_ret=VMF_ERR_NOT_SUPPORTED;
            break;

        case VMF_RPC_FKT_REGISTER_EXT_MOST_LINK:
		    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_REGISTER_EXT_MOST_LINK");
            vmf_ret = vmf_client_rpc_decoder_reg_ext_most_link(p_rpc_msg);
            break;

        case VMF_RPC_FKT_REGISTER_SPY:
		    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_REGISTER_SPY");
            vmf_ret = vmf_client_rpc_decoder_reg_spy(p_rpc_msg);
            break;

        case VMF_RPC_FKT_REGISTER_MOST_FB:
		    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_REGISTER_MOST_FB");
            vmf_ret = vmf_client_rpc_decoder_reg_most_fblock(p_rpc_msg);
            break;

        case VMF_RPC_FKT_DEREGISTER_MOST_FB:
		    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_DEREGISTER_MOST_FB");
            vmf_ret = vmf_client_rpc_decoder_de_reg_most_fblock(p_rpc_msg);
            break;

        case VMF_RPC_FKT_REGISTER_MOST_SHAD:
		    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_REGISTER_MOST_SHAD");
            vmf_ret = vmf_client_rpc_decoder_reg_most_shadow(p_rpc_msg);
            break;

        case VMF_RPC_FKT_DEREGISTER_MOST_SHAD:
		    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_DEREGISTER_MOST_SHAD");
            vmf_ret = vmf_client_rpc_decoder_de_reg_most_shadow(p_rpc_msg);
            break;

        case VMF_RPC_FKT_REGISTER_MSG_GRP:
		    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_REGISTER_MSG_GRP");
            vmf_ret = vmf_client_rpc_decoder_reg_msg_grp(p_rpc_msg);
            break;

        case VMF_RPC_FKT_DEREGISTER_MSG_GRP:
		    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_DEREGISTER_MSG_GRP");
            vmf_ret = vmf_client_rpc_decoder_de_reg_msg_grp(p_rpc_msg);
            break;

        case VMF_RPC_FKT_SEND_MOST_ASYNC:
		    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_SEND_MOST_ASYNC");
            vmf_ret = vmf_client_rpc_decoder_send_most_async(p_rpc_msg);
            break;

        case VMF_RPC_FKT_SEND_MOST_CTRL:
		    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_SEND_MOST_CTRL");
            vmf_ret = vmf_client_rpc_decoder_send_most_ctrl(p_rpc_msg);
            break;

        case VMF_RPC_FKT_SEND_BASIC:
		    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_SEND_BASIC");
            vmf_ret = vmf_client_rpc_decoder_send_basic(p_rpc_msg);
            break;

        case VMF_RPC_FKT_SEND:
		    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_SEND");
            vmf_ret = vmf_client_rpc_decoder_send(p_rpc_msg);
            break;

        case VMF_RPC_FKT_RECEIVE:
#if 0
		    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_20,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_RECEIVE");
#endif
            vmf_ret = vmf_client_rpc_decoder_receive(p_rpc_msg,p_response);
            break;
            
        case VMF_RPC_FKT_DISCONNECT:
		    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_DISCONNECT");
            vmf_ret = vmf_client_rpc_decoder_disconnect(p_rpc_msg);
            break;

        case VMF_RPC_FKT_TIMED_RECEIVE:
            NW_REM_VMF_DEBUG_INFO ("VMF_RPC_FKT_TIMED_RECEIVE");
            vmf_ret = vmf_client_rpc_decoder_timed_receive(p_rpc_msg,p_response,timeout);
            break;

        #ifdef VMF_RPC_FKT_BLOCK_RECEIVE
            case VMF_RPC_FKT_BLOCK_RECEIVE:
            NW_REM_VMF_DEBUG_INFO ("VMF_RPC_FKT_BLOCK_RECEIVE");
            vmf_ret = vmf_client_rpc_decoder_receive(p_rpc_msg,p_response);
            break;
        #endif

        default:
            vmf_ret = VMF_ERR_INVALID_RPC_ID;
		    VMF_TRACE_PRINTF(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","invalid RPC if=%d",p_rpc_msg->rpc_id);
            break;
    }

    /* finish reponse message */
    p_response->response = vmf_ret;

    return vmf_ret;
}





/*************************************************************************//**
 *
 *   rpc connect messages\n
 *   NOTE:
 *
 *
 *   \param[in] vmf_rpc_msg_t
 *   \return    vmf_error_t
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_connect(vmf_rpc_msg_t *p_rpc_msg)
{
    vmf_error_t vmf_ret;

    vmf_ret = nw_vmf_connect( p_rpc_msg->rpc_connect.process_name, /* channel name */
                              NULL,                                                 /* rx callback or NULL */
                              0,                                                    /* thread priority of rx callback function */
                              /* p_rpc_msg->rpc_connect.message_queue_lenght.length, */   /* VMF queue size */
                              VMF_TRACE_QUEUE_SIZE,                                 /* use always may queue size if remote vmf */
                              p_rpc_msg->rpc_connect.message_queue_msg_size.length  /* VMF message size */
                              );

    if (vmf_ret < 0)
    {
        NW_REM_VMF_DEBUG_ERROR ("VMF RPC - nw_vmf_connect() failed error=%d",vmf_ret);
	    VMF_TRACE_PRINTF(vmf_trace_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_rem","vmf_client_rpc_decoder_connect","nw_vmf_connect() failed error=%d",vmf_ret);
    }
    
    return vmf_ret;
 }



/*************************************************************************//**
 *
 *   rpc disconnect messages\n
 *   NOTE:
 *
 *
 *   \param[in] vmf_rpc_msg_t
 *   \return    vmf_error_t
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_disconnect(vmf_rpc_msg_t *p_rpc_msg)
{
    vmf_error_t vmf_ret;

	VMF_TRACE_PRINTF(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder_disconnect","nw_vmf_disconnect(%d)",p_rpc_msg->r_cid);
   
    vmf_ret = nw_vmf_disconnect( p_rpc_msg->r_cid);	/* cid */

    if (vmf_ret < 0)
    {
    	/* this may fail if connection already close */
        NW_REM_VMF_DEBUG_INFO ("VMF RPC - nw_vmf_disconnect() failed error=%d",vmf_ret);
	    VMF_TRACE_PRINTF(vmf_trace_trid,VMF_TRACE_SEVERITY_WARNING_10,"vmf_rem","vmf_client_rpc_decoder_disconnect","nw_vmf_disconnect() failed error=%d",vmf_ret);
    }
    
    return vmf_ret;
 }



/*************************************************************************//**
 *
 *   rpc register message group\n
 *   NOTE:
 *
 *
 *   \param[in] vmf_rpc_msg_t
 *   \return    vmf_error_t
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_reg_msg_grp(vmf_rpc_msg_t *p_rpc_msg)
{
    vmf_error_t vmf_ret;

    vmf_ret = nw_vmf_register_msg_group (p_rpc_msg->r_cid,                   /**<INPUT connection_id*/
                                         p_rpc_msg->rpc_reg_group.grps_num,  /**<INPUT number of groups in List*/
                                         p_rpc_msg->rpc_reg_group.grps);     /**<INPUT pointer to a list of message groups*/

    if (vmf_ret != VMF_OK)
    {
        NW_REM_VMF_DEBUG_ERROR ("VMF RPC - nw_vmf_register_msg_group() failed error=%d",vmf_ret);
	    VMF_TRACE_PRINTF(vmf_trace_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_rem","vmf_client_rpc_decoder_reg_msg_grp","nw_vmf_register_msg_group() failed error=%d",vmf_ret);
    }

    return vmf_ret;
}


/*************************************************************************//**
 *
 *   rpc register message group\n
 *   NOTE:
 *
 *
 *   \param[in] vmf_rpc_msg_t
 *   \return    vmf_error_t
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_de_reg_msg_grp(vmf_rpc_msg_t *p_rpc_msg)
{
    vmf_error_t vmf_ret;

    vmf_ret = nw_vmf_de_register_msg_group (p_rpc_msg->r_cid,                   /**<INPUT connection_id*/
                                            p_rpc_msg->rpc_reg_group.grps_num,  /**<INPUT number of groups in List*/
                                            p_rpc_msg->rpc_reg_group.grps);     /**<INPUT pointer to a list of message groups*/

    if (vmf_ret != VMF_OK)
    {
        NW_REM_VMF_DEBUG_ERROR ("VMF RPC - nw_vmf_deregister_msg_group() failed error=%d",vmf_ret);
	    VMF_TRACE_PRINTF(vmf_trace_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_rem","vmf_client_rpc_decoder_de_reg_msg_grp","nw_vmf_deregister_msg_group() failed error=%d",vmf_ret);
    }

    return vmf_ret;
}



/*************************************************************************//**
 *
 *   rpc register as external most link\n
 *   NOTE:
 *
 *
 *   \param[in] vmf_rpc_msg_t
 *   \return    vmf_error_t
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_reg_ext_most_link(vmf_rpc_msg_t *p_rpc_msg)
{
    vmf_error_t vmf_ret;

    vmf_ret = nw_vmf_register_ext_most_link(p_rpc_msg->r_cid); 


    if (vmf_ret != VMF_OK)
    {
        NW_REM_VMF_DEBUG_ERROR ("VMF RPC - vmf_client_rpc_decoder_reg_ext_most_link() failed error=%d",vmf_ret);
	    VMF_TRACE_PRINTF(vmf_trace_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_rem","vmf_client_rpc_decoder_reg_ext_most_link","vmf_client_rpc_decoder_reg_ext_most_link() failed error=%d",vmf_ret);
    }

    return vmf_ret;
}




/*************************************************************************//**
 *
 *   rpc register as spy\n
 *   NOTE:
 *
 *
 *   \param[in] vmf_rpc_msg_t
 *   \return    vmf_error_t
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_reg_spy(vmf_rpc_msg_t *p_rpc_msg)
{
    vmf_error_t vmf_ret;

    NW_REM_VMF_DEBUG_INFO ("VMF_RPC_FKT_REGISTER_SPY -  cid=%d",p_rpc_msg->r_cid);

    vmf_ret = nw_vmf_register_spy(p_rpc_msg->r_cid); 


    if (vmf_ret != VMF_OK)
    {
        NW_REM_VMF_DEBUG_ERROR ("VMF RPC - vmf_client_rpc_decoder_spy() failed error=%d",vmf_ret);
    }

    return vmf_ret;
}



/*************************************************************************//**
 *
 *   rpc register most fblock\n
 *   NOTE:
 *
 *
 *   \param[in] vmf_rpc_msg_t
 *   \return    vmf_error_t
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_reg_most_fblock(vmf_rpc_msg_t *p_rpc_msg)
{
    vmf_error_t vmf_ret;

    vmf_ret = nw_vmf_register_most_fblock  (p_rpc_msg->r_cid,                   /**< INPUT connection client-id*/
                                            p_rpc_msg->rpc_reg_fblock.fBlockId, /**< INPUT FBlock ID*/
                                            p_rpc_msg->rpc_reg_fblock.instId);  /**< INPUT Instant ID*/


    if (vmf_ret != VMF_OK)
    {
        NW_REM_VMF_DEBUG_ERROR ("VMF RPC - vmf_client_rpc_decoder_reg_most_fblock() failed error=%d",vmf_ret);
    }

    return vmf_ret;
}


/*************************************************************************//**
 *
 *   rpc deregister most fblock\n
 *   NOTE:
 *
 *
 *   \param[in] vmf_rpc_msg_t
 *   \return    vmf_error_t
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_de_reg_most_fblock(vmf_rpc_msg_t *p_rpc_msg)
{
    vmf_error_t vmf_ret;

    vmf_ret = nw_vmf_de_register_most_fblock  (p_rpc_msg->r_cid,                   /**< INPUT connection client-id*/
                                               p_rpc_msg->rpc_reg_fblock.fBlockId, /**< INPUT FBlock ID*/
                                               p_rpc_msg->rpc_reg_fblock.instId);  /**< INPUT Instant ID*/


    if (vmf_ret != VMF_OK)
    {
        NW_REM_VMF_DEBUG_ERROR ("VMF RPC - vmf_client_rpc_decoder_de_reg_most_fblock() failed error=%d",vmf_ret);
    }

    return vmf_ret;
}



/*************************************************************************//**
 *
 *   rpc register most fblock\n
 *   NOTE:
 *
 *
 *   \param[in] vmf_rpc_msg_t
 *   \return    vmf_error_t
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_reg_most_shadow(vmf_rpc_msg_t *p_rpc_msg)
{
    vmf_error_t vmf_ret;

    vmf_ret = nw_vmf_register_most_shadow  (p_rpc_msg->r_cid,               
                                            p_rpc_msg->rpc_reg_shadow.fBlockId, 
                                            p_rpc_msg->rpc_reg_shadow.instId,
                                            p_rpc_msg->rpc_reg_shadow.fcIds_num.length,
                                            (unsigned16*)p_rpc_msg->rpc_reg_shadow.funcIds); 


    if (vmf_ret != VMF_OK)
    {
        NW_REM_VMF_DEBUG_ERROR ("VMF RPC - vmf_client_rpc_decoder_reg_most_shadow() failed error=%d",vmf_ret);
    }

    return vmf_ret;
}




/*************************************************************************//**
 *
 *   rpc deregister most fblock\n
 *   NOTE:
 *
 *
 *   \param[in] vmf_rpc_msg_t
 *   \return    vmf_error_t
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_de_reg_most_shadow(vmf_rpc_msg_t *p_rpc_msg)
{
    vmf_error_t vmf_ret;

    vmf_ret = nw_vmf_de_register_most_shadow  (p_rpc_msg->r_cid,                
                                               p_rpc_msg->rpc_reg_fblock.fBlockId, 
                                               p_rpc_msg->rpc_reg_fblock.instId);


    if (vmf_ret != VMF_OK)
    {
        NW_REM_VMF_DEBUG_ERROR ("VMF RPC - vmf_client_rpc_decoder_de_reg_most_shadow() failed error=%d",vmf_ret);
    }

    return vmf_ret;
}







/*************************************************************************//**
 *
 *   rpc send most async\n
 *   NOTE:
 *
 *
 *   \param[in] vmf_rpc_msg_t
 *   \return    vmf_error_t
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_send_most_async(vmf_rpc_msg_t *p_rpc_msg)
{
    vmf_error_t vmf_ret;

#ifdef PREVENT_MEMORY_CRASH
    unsigned16  ulen;
    ulen = p_rpc_msg->rpc_send_most.vmf_most_msg.data.length;
    VMF_VAR_MOST_MSG_TYP(ulen)  my_most_msg;

    memcpy((void*)&my_most_msg,(void*)&(p_rpc_msg->rpc_send_most.vmf_most_msg),sizeof(VMF_VAR_MOST_MSG_TYP(ulen)));

    vmf_ret = nw_vmf_send_most_async (p_rpc_msg->r_cid,    
                                    (vmf_most_msg_t*)&my_most_msg);
#else
    vmf_ret = nw_vmf_send_most_async (p_rpc_msg->r_cid,    
                                     (vmf_most_msg_t*)&p_rpc_msg->rpc_send_most.vmf_most_msg);
#endif

    if (vmf_ret != VMF_OK)
    {
        NW_REM_VMF_DEBUG_ERROR ("VMF RPC - vmf_client_rpc_decoder_send_most_async() failed error=%d",vmf_ret);
    }

    return vmf_ret;
}




/*************************************************************************//**
 *
 *   rpc send most async\n
 *   NOTE:
 *
 *
 *   \param[in] vmf_rpc_msg_t
 *   \return    vmf_error_t
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_send_most_ctrl(vmf_rpc_msg_t *p_rpc_msg)
{
    vmf_error_t vmf_ret;

#ifdef PREVENT_MEMORY_CRASH
    unsigned16  ulen;
    ulen = p_rpc_msg->rpc_send_most.vmf_most_msg.data.length;
    VMF_VAR_MOST_MSG_TYP(ulen)  my_most_msg;

    memcpy((void*)&my_most_msg,(void*)&(p_rpc_msg->rpc_send_most.vmf_most_msg),sizeof(VMF_VAR_MOST_MSG_TYP(ulen)));

#if 0
        printf ("sizeof(vmf_rpc_msg_t)=%d\n",sizeof(vmf_rpc_msg_t));fflush(stdout);
        printf ("ulen=%d\n",ulen);fflush(stdout);
        printf ("sizeof(VMF_VAR_MOST_MSG_TYP(ulen))=%d\n",sizeof(VMF_VAR_MOST_MSG_TYP(ulen)));fflush(stdout);
        nw_vmf_HexDump("p_rpc_msg->:",(unsigned8 *)&(p_rpc_msg->rpc_send_most.vmf_most_msg),50);
        nw_vmf_HexDump("my_most_msg:",(unsigned8 *)&my_most_msg,50);
#endif


    vmf_ret = nw_vmf_send_most_ctrl (p_rpc_msg->r_cid,    
                                    (vmf_most_msg_t*)&my_most_msg);
#else
    vmf_ret = nw_vmf_send_most_ctrl (p_rpc_msg->r_cid,    
                                    (vmf_most_msg_t*)&p_rpc_msg->rpc_send_most.vmf_most_msg);

#endif

    if (vmf_ret != VMF_OK)
    {
        NW_REM_VMF_DEBUG_ERROR ("VMF RPC - vmf_client_rpc_decoder_send_most_ctrl() failed error=%d",vmf_ret);
    }

    return vmf_ret;
}



/*************************************************************************//**
 *
 *   rpc send most\n
 *   NOTE:
 *
 *
 *   \param[in] vmf_rpc_msg_t
 *   \return    vmf_error_t
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_send_basic(vmf_rpc_msg_t *p_rpc_msg)
{
    vmf_error_t vmf_ret;

#ifdef PREVENT_MEMORY_CRASH
    unsigned16  ulen;
    ulen = p_rpc_msg->rpc_send_basic.vmf_basic_msg.data.length;
    
    VMF_VAR_BASIC_MSG_TYP(ulen) my_basic_msg;
    
    memcpy((void*)&my_basic_msg,(void*)&(p_rpc_msg->rpc_send_basic.vmf_basic_msg),sizeof(VMF_VAR_BASIC_MSG_TYP(ulen)));

    vmf_ret = nw_vmf_send_basic  (p_rpc_msg->r_cid,(vmf_basic_msg_t*)&my_basic_msg);
#else
    vmf_ret = nw_vmf_send_basic  (p_rpc_msg->r_cid,    
                                 (vmf_basic_msg_t*)&(p_rpc_msg->rpc_send_basic.vmf_basic_msg));
#endif


    if (vmf_ret != VMF_OK)
    {
        NW_REM_VMF_DEBUG_ERROR ("VMF RPC - vmf_client_rpc_decoder_send_basic() failed error=%d",vmf_ret);
    }

    return vmf_ret;
}




/*************************************************************************//**
 *
 *   rpc send most\n
 *   NOTE:
 *
 *
 *   \param[in] vmf_rpc_msg_t
 *   \return    vmf_error_t
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_send(vmf_rpc_msg_t *p_rpc_msg)
{
    vmf_error_t vmf_ret;

    vmf_ret = nw_vmf_send  (p_rpc_msg->r_cid,    
                           (vmf_msg_t*)&(p_rpc_msg->rpc_send.vmf_msg));

    if (vmf_ret != vmf_ret)
    {
        NW_REM_VMF_DEBUG_ERROR ("VMF RPC - vmf_client_rpc_decoder_send() failed error=%d",vmf_ret);
    }

    return vmf_ret;
}






/*************************************************************************//**
 *
 *   rpc receive most message \n
 *   NOTE:
 *
 *
 *   \param[in] vmf_rpc_msg_t
 *   \return    vmf_error_t
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_receive(vmf_rpc_msg_t *p_rpc_msg,vmf_rpc_response_t *p_response)
{
    vmf_error_t vmf_ret;
    #if 0
    unsigned16  data_len;
    #endif

    VMF_VAR_MSG_TYP(p_rpc_msg->rpc_receive.vmf_msg_length.length)   my_vmf_msg;

    NW_REM_VMF_DEBUG_INFO ("VMF RPC - vmf_client_rpc_decoder_receive()- cid=%d",p_rpc_msg->r_cid);

    /* this receive will block till data is available */
    vmf_ret = nw_vmf_receive (p_rpc_msg->r_cid,  
                              (vmf_msg_t*)&my_vmf_msg,                       /* pointer to a vmf_message*/
                              p_rpc_msg->rpc_receive.vmf_msg_length.length); /* length of message buffer */

    if (vmf_ret <= 0)
    {
        NW_REM_VMF_DEBUG_ERROR ("VMF RPC - vmf_client_rpc_decoder_receive()- nw_vmf_receive() failed error=%d",vmf_ret);
        return VMF_ERROR;
    }
    else
    {   
#if 0
        nw_vmf_HexDump("vmf_client_rx_data",(unsigned8 *)&my_vmf_msg,vmf_ret);
#endif
    }

/* if packing between cllient and server is equal  - we can just copy the vmf message */
#if 1
    /* same packing on client and server */

    memcpy(&(p_response->vmf_msg),&my_vmf_msg,sizeof(vmf_rpc_response_t) + vmf_ret + 10); 
    
    /* set length of response message */
    p_response->msg_length.length = sizeof(vmf_rpc_response_t) + vmf_ret + 10; /* send some additional byte (packing))*/

#else

    /* copy vmf message to destination buffer                                                 */
    /* because the packing of the data may be different it has to be copied element by element */
    /* first copy header  - header is equal in all message types */
    p_response->vmf_msg.vmf_most_msg.msg_base.base.msg_type  = my_vmf_msg.vmf_most_msg.msg_base.base.msg_type;
    p_response->vmf_msg.vmf_most_msg.msg_base.base.pid       = my_vmf_msg.vmf_most_msg.msg_base.base.pid;
    p_response->vmf_msg.vmf_most_msg.msg_base.base.client_id = my_vmf_msg.vmf_most_msg.msg_base.base.client_id;
    p_response->vmf_msg.vmf_most_msg.msg_base.id.group       = my_vmf_msg.vmf_most_msg.msg_base.id.group;
    p_response->vmf_msg.vmf_most_msg.msg_base.id.event       = my_vmf_msg.vmf_most_msg.msg_base.id.event;

    /* copy message specific data */    
    if (my_vmf_msg.vmf_most_msg.msg_base.base.msg_type  == MSG_TYPE_MOST_MESSAGE)
    {
        NW_REM_VMF_DEBUG_INFO ("VMF RPC - received MOST msg length=%d",vmf_ret);

        /* copy most data */
        p_response->vmf_msg.vmf_most_msg.tgt_addr     = my_vmf_msg.vmf_most_msg.tgt_addr;
        p_response->vmf_msg.vmf_most_msg.src_addr     = my_vmf_msg.vmf_most_msg.src_addr;
        p_response->vmf_msg.vmf_most_msg.channel_flag = my_vmf_msg.vmf_most_msg.channel_flag;
        p_response->vmf_msg.vmf_most_msg.fblock_id    = my_vmf_msg.vmf_most_msg.fblock_id;
        p_response->vmf_msg.vmf_most_msg.inst_id      = my_vmf_msg.vmf_most_msg.inst_id;
        p_response->vmf_msg.vmf_most_msg.func_id      = my_vmf_msg.vmf_most_msg.func_id;
        p_response->vmf_msg.vmf_most_msg.op_type      = my_vmf_msg.vmf_most_msg.op_type;
        p_response->vmf_msg.vmf_most_msg.data.length  = my_vmf_msg.vmf_most_msg.data.length;
        /* copy the payload */
        if (p_response->vmf_msg.vmf_most_msg.data.length > 0)
        {
            memcpy( p_response->vmf_msg.vmf_most_msg.data.pl,
                    my_vmf_msg.vmf_most_msg.data.pl,
                    p_response->vmf_msg.vmf_most_msg.data.length);
        }

        /* set sizte of response message */
        /* we are sending some additional bytes, but who cares */
        p_response->msg_length.length = sizeof(vmf_rpc_response_t) + sizeof(VMF_VAR_MOST_MSG_TYP(p_response->vmf_msg.vmf_basic_msg.data.length));
    }
    else
    {
        NW_REM_VMF_DEBUG_INFO ("VMF RPC - received BASIC msg length=%d",vmf_ret);
        data_len = my_vmf_msg.vmf_basic_msg.data.length;

        /* copy basic data */ 
        p_response->vmf_msg.vmf_basic_msg.data.length = my_vmf_msg.vmf_basic_msg.data.length;
        NW_REM_VMF_DEBUG_INFO ("VMF RPC - .data.length=%d",data_len);
    
        /* copy the payload */
        if (data_len > 0)
        {
            memcpy( p_response->vmf_msg.vmf_basic_msg.data.pl,
                    my_vmf_msg.vmf_basic_msg.data.pl,
                    data_len);
        }

        /* set lenth of response message */
        /* we are sending some additional bytes, but who cares */
        p_response->msg_length.length = sizeof(vmf_rpc_response_t) + sizeof(VMF_VAR_BASIC_MSG_TYP(data_len))-sizeof(VMF_VAR_BASIC_MSG_TYP(0));
    }
#endif

#ifdef VMF_ENABLE_MSG_CLK
    /* convert message clock to ms for remote clients !! */
    p_response->vmf_msg.vmf_most_msg.msg_base.base.msg_clk   = vmf_rem_get_time_in_ms(my_vmf_msg.vmf_most_msg.msg_base.base.msg_clk);
#endif

    return vmf_ret;
}




/*************************************************************************//**
 *
 *   rpc receive most message \n
 *   NOTE:
 *
 *
 *   \param[in] vmf_rpc_msg_t
 *   \return    vmf_error_t
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_timed_receive(vmf_rpc_msg_t *p_rpc_msg,vmf_rpc_response_t *p_response,unsigned16 timeout)
{
    vmf_error_t vmf_ret;

    VMF_VAR_MSG_TYP(p_rpc_msg->rpc_receive.vmf_msg_length.length)   my_vmf_msg;

    NW_REM_VMF_DEBUG_INFO ("VMF RPC - vmf_client_rpc_decoder_timed_receive()- cid=%d",p_rpc_msg->r_cid);


    /* this receive will block till data is available */
    vmf_ret = nw_vmf_timed_receive (p_rpc_msg->r_cid,  
                              (vmf_msg_t*)&my_vmf_msg,                       /* pointer to a vmf_message*/
                              p_rpc_msg->rpc_receive.vmf_msg_length.length,  /* length of message buffer */
                              timeout);
                              
                              
    if (vmf_ret < 0)
    {
        NW_REM_VMF_DEBUG_INFO ("VMF RPC - vmf_client_rpc_decoder_timed_receive()- nw_vmf_receive() failed error=%d",vmf_ret);
        vmf_ret = VMF_ERROR;
    }
    else
    {   
    
        /* !!! this will only work if the same packing and endian is used on client and server !!! */
        memcpy(&(p_response->vmf_msg),&my_vmf_msg,sizeof(vmf_rpc_response_t) + vmf_ret + 10); 
        
        /* set length of response message */
        p_response->msg_length.length = sizeof(vmf_rpc_response_t) + vmf_ret + 10; /* send some additional byte (packing))*/
    
        /* convert message clock to ms for remote clients !! */
        p_response->vmf_msg.vmf_most_msg.msg_base.base.msg_clk   = vmf_rem_get_time_in_ms(my_vmf_msg.vmf_most_msg.msg_base.base.msg_clk);
    }
    return vmf_ret;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_get_time_in_ms(void)
 *
 *   Description:   get time in ms - input = clocks
 *
 *   Parameters:    clocks
 *
 *   Function Return value: - time in ms
 *
 ******************************************************************************/
unsigned32 vmf_rem_get_time_in_ms(unsigned64 clocks)
{
    unsigned32  msTime =0;
    static      unsigned32          cps;
    static      unsigned32          cpsMS=0;  /* = cps/1000 */
    static bool bGotCps=false;
    
    #ifdef VMF_REM_SERVER_UNIT_TEST
    typedef struct 
    {
        unsigned32  cycles_per_sec;   
    }my_time_t;

    my_time_t *qtime;
    my_time_t my_time;
    
    my_time.cycles_per_sec = 5000;
    qtime = &my_time;
    
    #endif
    
    /* find out how many cycles per second */
    if (!bGotCps)
    {
        cps = SYSPAGE_ENTRY(qtime)->cycles_per_sec;
        cpsMS = cps/1000L;
        bGotCps=true;
    }

    /* convert cycles to useconds */
    msTime = (clocks/cpsMS);       /* time in ms */
    
    return (msTime);
}
