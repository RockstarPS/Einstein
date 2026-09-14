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
/* #define VMF_RPC_TRACE_HEX */


#ifdef VMF_REM_SERVER_UNIT_TEST
#include "nw_vmf_rem_server_unit_test.h"
#endif

#include "nw_os_config.h"
#include "nw_vmf_rem.h"
#include "nw_vmf.h"
#include "nw_vmf_cfg.h"
#ifndef VMF_REM_SERVER_UNIT_TEST
#include "nw_vmf_trace.h"
#include "nw_vmf_debug.h"
#endif

#ifdef VMF_REM_SERVER_UNIT_TEST
#define VMF_REM_SERV_STATIC
#else
#define VMF_REM_SERV_STATIC static
#endif

extern     unsigned8    vmf_trace_trid;

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
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_timed_receive(vmf_rpc_msg_t *p_rpc_msg,vmf_rpc_response_t *p_response);


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
vmf_error_t vmf_client_rpc_decoder(vmf_rpc_msg_t *p_rpc_msg,vmf_rpc_response_t *p_response)
{
    vmf_error_t vmf_ret=VMF_ERR_NOT_SUPPORTED;

    if (NULL == p_rpc_msg)
    {
        NW_REM_VMF_DEBUG_ERROR ("vmf_client_rpc_decoder() p_rpc_msg NULL pointer");
        VMF_REM_SERVER_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_rem","vmf_client_rpc_decoder","vmf_client_rpc_decoder() p_rpc_msg NULL pointer");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else if (NULL == p_response)
    {
        NW_REM_VMF_DEBUG_ERROR ("vmf_client_rpc_decoder() p_response NULL pointer");
        VMF_REM_SERVER_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_ERROR_10,"vmf_rem","vmf_client_rpc_decoder","vmf_client_rpc_decoder() p_response NULL pointer");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
	else
	{
		/* start to fill reponse message */
		p_response->r_cid = p_rpc_msg->r_cid; 
		p_response->rpc_id = p_rpc_msg->rpc_id;
		p_response->msg_length.length = sizeof(vmf_rpc_response_t);     /* set default size */
																		/* has to be changed if */
																		/* payload is send !! */
		switch(p_rpc_msg->rpc_id)
		{
			case VMF_RPC_FKT_CONNECT:
				VMF_REM_SERVER_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_CONNECT");
				vmf_ret = vmf_client_rpc_decoder_connect(p_rpc_msg);
				break;


			case VMF_RPC_FKT_CONNECT_ASYNC:
				VMF_REM_SERVER_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_CONNECT_ASYNC");
				vmf_ret=VMF_ERR_NOT_SUPPORTED;
				break;

			case VMF_RPC_FKT_REGISTER_EXT_MOST_LINK:
				VMF_REM_SERVER_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_REGISTER_EXT_MOST_LINK");
				vmf_ret = vmf_client_rpc_decoder_reg_ext_most_link(p_rpc_msg);
				break;

			case VMF_RPC_FKT_REGISTER_SPY:
				VMF_REM_SERVER_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_REGISTER_SPY");
				vmf_ret = vmf_client_rpc_decoder_reg_spy(p_rpc_msg);
				break;

			case VMF_RPC_FKT_REGISTER_MOST_FB:
				VMF_REM_SERVER_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_REGISTER_MOST_FB");
				vmf_ret = vmf_client_rpc_decoder_reg_most_fblock(p_rpc_msg);
				break;

			case VMF_RPC_FKT_DEREGISTER_MOST_FB:
				VMF_REM_SERVER_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_DEREGISTER_MOST_FB");
				vmf_ret = vmf_client_rpc_decoder_de_reg_most_fblock(p_rpc_msg);
				break;

			case VMF_RPC_FKT_REGISTER_MOST_SHAD:
				VMF_REM_SERVER_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_REGISTER_MOST_SHAD");
				vmf_ret = vmf_client_rpc_decoder_reg_most_shadow(p_rpc_msg);
				break;

			case VMF_RPC_FKT_DEREGISTER_MOST_SHAD:
				VMF_REM_SERVER_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_DEREGISTER_MOST_SHAD");
				vmf_ret = vmf_client_rpc_decoder_de_reg_most_shadow(p_rpc_msg);
				break;

			case VMF_RPC_FKT_REGISTER_MSG_GRP:
				VMF_REM_SERVER_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_REGISTER_MSG_GRP");
				vmf_ret = vmf_client_rpc_decoder_reg_msg_grp(p_rpc_msg);
				break;

			case VMF_RPC_FKT_DEREGISTER_MSG_GRP:
				VMF_REM_SERVER_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_DEREGISTER_MSG_GRP");
				vmf_ret = vmf_client_rpc_decoder_de_reg_msg_grp(p_rpc_msg);
				break;

			case VMF_RPC_FKT_SEND_MOST_ASYNC:
				VMF_REM_SERVER_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_SEND_MOST_ASYNC");
				vmf_ret = vmf_client_rpc_decoder_send_most_async(p_rpc_msg);
				break;

			case VMF_RPC_FKT_SEND_MOST_CTRL:
				VMF_REM_SERVER_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_SEND_MOST_CTRL");
				vmf_ret = vmf_client_rpc_decoder_send_most_ctrl(p_rpc_msg);
				break;

			case VMF_RPC_FKT_SEND_BASIC:
				VMF_REM_SERVER_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_SEND_BASIC");
				vmf_ret = vmf_client_rpc_decoder_send_basic(p_rpc_msg);
				break;

			case VMF_RPC_FKT_SEND:
				VMF_REM_SERVER_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_SEND");
				vmf_ret = vmf_client_rpc_decoder_send(p_rpc_msg);
				break;

			case VMF_RPC_FKT_RECEIVE:
	#if 0
				VMF_REM_SERVER_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_20,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_RECEIVE");
	#endif
				vmf_ret = vmf_client_rpc_decoder_receive(p_rpc_msg,p_response);
				break;
				
			case VMF_RPC_FKT_DISCONNECT:
				VMF_REM_SERVER_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","VMF_RPC_FKT_DISCONNECT");
				vmf_ret = vmf_client_rpc_decoder_disconnect(p_rpc_msg);
				break;

			case VMF_RPC_FKT_TIMED_RECEIVE:
				NW_REM_VMF_DEBUG_INFO ("VMF_RPC_FKT_TIMED_RECEIVE");
				vmf_ret = vmf_client_rpc_decoder_timed_receive(p_rpc_msg,p_response);
				break;

			#ifdef VMF_RPC_FKT_BLOCK_RECEIVE
				case VMF_RPC_FKT_BLOCK_RECEIVE:
				NW_REM_VMF_DEBUG_INFO ("VMF_RPC_FKT_BLOCK_RECEIVE");
				vmf_ret = vmf_client_rpc_decoder_receive(p_rpc_msg,p_response);
				break;
			#endif

			default:
				vmf_ret = VMF_ERR_INVALID_RPC_ID;
				VMF_REM_SERVER_TRACE_PRINTF(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder","invalid RPC if=%d",p_rpc_msg->rpc_id);
				break;
		}

		/* finish reponse message */
		p_response->response = vmf_ret;
	}
    
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
        VMF_REM_SERVER_TRACE_PRINTF(vmf_trace_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_rem","vmf_client_rpc_decoder_connect","nw_vmf_connect() failed error=%d",vmf_ret);
    }
    else
    {
        VMF_REM_SERVER_TRACE_PRINTF(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder_connect","nw_vmf_connect() cid=%d",vmf_ret);
        NW_REM_VMF_DEBUG_INFO2 ("VMF RPC - vmf_client_rpc_decoder_connect() cid=%d",vmf_ret);
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

    NW_REM_VMF_DEBUG_INFO2 ("VMF RPC - vmf_client_rpc_decoder_disconnect(%d)",p_rpc_msg->r_cid);
    VMF_REM_SERVER_TRACE_PRINTF(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_decoder_disconnect","nw_vmf_disconnect(%d)",p_rpc_msg->r_cid);
   
    vmf_ret = nw_vmf_disconnect( p_rpc_msg->r_cid); /* cid */

    if (vmf_ret < 0)
    {
        /* this may fail if connection already close */
        NW_REM_VMF_DEBUG_INFO ("VMF RPC - nw_vmf_disconnect() failed error=%d",vmf_ret);
        VMF_REM_SERVER_TRACE_PRINTF(vmf_trace_trid,VMF_TRACE_SEVERITY_WARNING_10,"vmf_rem","vmf_client_rpc_decoder_disconnect","nw_vmf_disconnect() failed error=%d",vmf_ret);
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
        VMF_REM_SERVER_TRACE_PRINTF(vmf_trace_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_rem","vmf_client_rpc_decoder_reg_msg_grp","nw_vmf_register_msg_group() failed error=%d",vmf_ret);
        VMF_REM_SERVER_TRACE_PRINTF(vmf_trace_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_rem","vmf_client_rpc_decoder_reg_msg_grp","cid=%d, num=%d",p_rpc_msg->r_cid,p_rpc_msg->rpc_reg_group.grps_num);
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
        VMF_REM_SERVER_TRACE_PRINTF(vmf_trace_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_rem","vmf_client_rpc_decoder_de_reg_msg_grp","nw_vmf_deregister_msg_group() failed error=%d",vmf_ret);
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
        VMF_REM_SERVER_TRACE_PRINTF(vmf_trace_trid,VMF_TRACE_SEVERITY_ERROR_15,"vmf_rem","vmf_client_rpc_decoder_reg_ext_most_link","vmf_client_rpc_decoder_reg_ext_most_link() failed error=%d",vmf_ret);
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
#ifdef INTEGRITY
    VMF_VAR_MOST_MSG_TYP(VMF_REM_MAX_DATA_SIZE)  my_most_msg;
#else
    VMF_VAR_MOST_MSG_TYP(ulen)  my_most_msg;
#endif    

    memcpy((void*)&my_most_msg,(void*)&(p_rpc_msg->rpc_send_most.vmf_most_msg),sizeof(VMF_VAR_MOST_MSG_TYP(0))+ulen);

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

#ifdef INTEGRITY
    VMF_VAR_MOST_MSG_TYP(VMF_REM_MAX_DATA_SIZE)  my_most_msg;
#else
    VMF_VAR_MOST_MSG_TYP(ulen)  my_most_msg;
#endif    

    memcpy((void*)&my_most_msg,(void*)&(p_rpc_msg->rpc_send_most.vmf_most_msg),sizeof(VMF_VAR_MOST_MSG_TYP(0))+ulen);

#ifdef VMF_RPC_TRACE_HEX
        printf ("sizeof(vmf_rpc_msg_t)=%d\n",sizeof(vmf_rpc_msg_t));fflush(ERROR_CHANNEL);
        printf ("ulen=%d\n",ulen);fflush(ERROR_CHANNEL);
        printf ("sizeof(VMF_VAR_MOST_MSG_TYP(ulen))=%d\n",sizeof(VMF_VAR_MOST_MSG_TYP(ulen)));fflush(ERROR_CHANNEL);
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

    NW_REM_VMF_DEBUG_INFO2 ("VMF RPC - vmf_client_rpc_decoder_send_basic(%d)",p_rpc_msg->r_cid);
    
#ifdef PREVENT_MEMORY_CRASH
    unsigned16  ulen;
    ulen = p_rpc_msg->rpc_send_basic.vmf_basic_msg.data.length;

#ifdef INTEGRITY
    /* Seems that Integrity cannot cope with var len VMF messages on stack! */
    VMF_VAR_BASIC_MSG_TYP(VMF_REM_MAX_DATA_SIZE) my_basic_msg;
#else
    VMF_VAR_BASIC_MSG_TYP(ulen) my_basic_msg;
#endif    
    
    memcpy((void*)&my_basic_msg,(void*)&(p_rpc_msg->rpc_send_basic.vmf_basic_msg),sizeof(VMF_VAR_BASIC_MSG_TYP(0))+ulen);

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

    NW_REM_VMF_DEBUG_INFO2 ("VMF RPC - vmf_client_rpc_decoder_send(%d)",p_rpc_msg->r_cid);
    
    vmf_ret = nw_vmf_send  (p_rpc_msg->r_cid,    
                           (vmf_msg_t*)&(p_rpc_msg->rpc_send.vmf_msg));

    if (VMF_OK != vmf_ret)
    {
        NW_REM_VMF_DEBUG_ERROR ("VMF RPC - vmf_client_rpc_decoder_send(%d) failed error=%d",p_rpc_msg->r_cid,vmf_ret);
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
    
    if (NULL == p_rpc_msg)
    {
        NW_REM_VMF_DEBUG_ERROR ("VMF RPC - vmf_client_rpc_decoder_receive(): p_rpc_msg == NULL ");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else if (NULL == p_response)
    {
        NW_REM_VMF_DEBUG_ERROR ("VMF RPC - vmf_client_rpc_decoder_receive(): p_response == NULL ");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
	else
	{
		if (p_rpc_msg->rpc_receive.vmf_msg_length.length > VMF_REM_MAX_DATA_SIZE)
		{
			p_rpc_msg->rpc_receive.vmf_msg_length.length = VMF_REM_MAX_DATA_SIZE;
		}
		
		{

	#ifdef INTEGRITY
			/* Seems that Integrity cannot cope with var len VMF messages on stack! */
			VMF_VAR_MSG_TYP(VMF_REM_MAX_DATA_SIZE)   my_vmf_msg;
	#else
			VMF_VAR_MSG_TYP(p_rpc_msg->rpc_receive.vmf_msg_length.length)   my_vmf_msg;
	#endif        
			
			NW_REM_VMF_DEBUG_INFO2 ("VMF RPC - vmf_client_rpc_decoder_receive(%d) len=%d",p_rpc_msg->r_cid,p_rpc_msg->rpc_receive.vmf_msg_length.length);
			
			/* this receive will block until data is available */
			vmf_ret = nw_vmf_receive (p_rpc_msg->r_cid,  
									  (vmf_msg_t*)&my_vmf_msg,                       /* pointer to a vmf_message*/
									  p_rpc_msg->rpc_receive.vmf_msg_length.length); /* length of message buffer */
			if (vmf_ret <= 0)
			{
				if (VMF_ERR_BUFFER_TO_SMALL == vmf_ret)
				{
					NW_REM_VMF_DEBUG_ERROR ("VMF RPC - vmf_client_rpc_decoder_receive()- VMF_ERR_BUFFER_TO_SMALL - buffer-len=%d",p_rpc_msg->rpc_receive.vmf_msg_length.length);
					/* if msg was cut during transfer the still transfer the cut message to the remote client */
					vmf_ret = p_rpc_msg->rpc_receive.vmf_msg_length.length;
					memcpy(&(p_response->vmf_msg),&my_vmf_msg,vmf_ret); 
					/* set length of response message */
					p_response->msg_length.length = vmf_ret; 
				}
				else
				{
					NW_REM_VMF_DEBUG_ERROR ("VMF RPC - vmf_client_rpc_decoder_receive()- nw_vmf_receive() failed error=%d",vmf_ret);
					NW_REM_VMF_DEBUG_INFO2 ("VMF RPC - vmf_client_rpc_decoder_receive()- nw_vmf_receive(%d) failed error=%d",p_rpc_msg->r_cid,vmf_ret);
					return vmf_ret;
				}
			}
			else
			{   
		#ifdef VMF_RPC_TRACE_HEX
				nw_vmf_HexDump("vmf_client_rx_data",(unsigned8 *)&my_vmf_msg,vmf_ret);
		#endif
			}

			/* if packing between cllient and server is equal  - we can just copy the vmf message */
			/* same packing on client and server */
			memcpy(&(p_response->vmf_msg),&my_vmf_msg,sizeof(vmf_rpc_response_t) + vmf_ret + 10); 
			
			/* set length of response message */
			p_response->msg_length.length = sizeof(vmf_rpc_response_t) + vmf_ret + 10; /* send some additional byte (packing))*/

			/* convert message clock to ms for remote clients !! */
			p_response->vmf_msg.vmf_most_msg.msg_base.base.msg_clk   = vmf_rem_convert_clocks_to_ms(my_vmf_msg.vmf_most_msg.msg_base.base.msg_clk);

			NW_REM_VMF_DEBUG_INFO2 ("VMF RPC - vmf_client_rpc_decoder_receive(%d)- exit - ret=%d",p_rpc_msg->r_cid,vmf_ret);
		}
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
VMF_REM_SERV_STATIC vmf_error_t vmf_client_rpc_decoder_timed_receive(vmf_rpc_msg_t *p_rpc_msg,vmf_rpc_response_t *p_response)
{
    vmf_error_t vmf_ret;

    if (p_rpc_msg->rpc_timed_receive.vmf_msg_length.length > VMF_REM_MAX_DATA_SIZE)
    {
        p_rpc_msg->rpc_timed_receive.vmf_msg_length.length = VMF_REM_MAX_DATA_SIZE;
    }
    
    {    
#ifdef INTEGRITY
        VMF_VAR_MSG_TYP(VMF_REM_MAX_DATA_SIZE)   my_vmf_msg;
#else
        VMF_VAR_MSG_TYP(p_rpc_msg->rpc_timed_receive.vmf_msg_length.length)   my_vmf_msg;
#endif        

        NW_REM_VMF_DEBUG_INFO2 ("VMF RPC - vmf_client_rpc_decoder_timed_receive()- cid=%d",p_rpc_msg->r_cid);
        
        /* this receive will block till data is available */
        vmf_ret = nw_vmf_timed_receive (p_rpc_msg->r_cid,  
                                  (vmf_msg_t*)&my_vmf_msg,                       /* pointer to a vmf_message*/
                                  p_rpc_msg->rpc_timed_receive.vmf_msg_length.length,  /* length of message buffer */
                                  p_rpc_msg->rpc_timed_receive.timeout_ms);
                                  
                                  
        if (vmf_ret < 0)
        {
            NW_REM_VMF_DEBUG_INFO ("VMF RPC - vmf_client_rpc_decoder_timed_receive() cid=%d - nw_vmf_receive() failed error=%d",p_rpc_msg->r_cid,vmf_ret);
            vmf_ret = VMF_ERROR;
        }
        else
        {   
        
            /* !!! this will only work if the same packing and endian is used on client and server !!! */
            memcpy(&(p_response->vmf_msg),&my_vmf_msg,sizeof(vmf_rpc_response_t) + vmf_ret + 10); 
            
            /* set length of response message */
            p_response->msg_length.length = sizeof(vmf_rpc_response_t) + vmf_ret + 10; /* send some additional byte (packing))*/
        
            /* convert message clock to ms for remote clients !! */
            p_response->vmf_msg.vmf_most_msg.msg_base.base.msg_clk   = vmf_rem_convert_clocks_to_ms(my_vmf_msg.vmf_most_msg.msg_base.base.msg_clk);
        }
    }
    return vmf_ret;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_rem_convert_clocks_to_ms(void)
 *
 *   Description:   convert clocks to ms
 *
 *   Parameters:    clocks
 *
 *   Function Return value: - time in ms
 *
 ******************************************************************************/
unsigned32 vmf_rem_convert_clocks_to_ms(unsigned64 clocks)
{
    return(nw_os_cfg_convert_clocks_to_ms_time(clocks));
}


