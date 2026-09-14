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

  Module:               nw_vmf_rem_util.c
  Description:          utility functions for remote VMF

  Project Scope:        Beethoven VM platform

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   gcc
  Target Hardware:      Any

  *****************************************************************************/

/* application includes */
#include "nw_vmf_rem.h"                 /* vmf cfg file */

/*************************************************************************//**
 *
 *   get rpc  message size\n
 *   NOTE: 
 *   
 *
 *   \param[in] p_msglen*    -- pointer to resulting length
 *   \param[in] p_rpc_msg*   -- pointer to rpc message
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
vmf_error_t vmf_rem_get_rpc_msg_len(unsigned16 *p_msglen, vmf_rpc_msg_t *p_rpc_msg)
{
    if ((NULL == p_rpc_msg) || (NULL == p_msglen))
    {
        return (VMF_ERR_NULL_POINTER);
    }

    *p_msglen =0;

    /* calculate message size */
    switch (p_rpc_msg->rpc_id)
    {   
        case VMF_RPC_FKT_CONNECT_ASYNC:                 /* no break */
        case VMF_RPC_FKT_CONNECT:
            *p_msglen  = GET_VMF_RPC_HEADER_LENGTH + sizeof(p_rpc_msg->rpc_connect);
            break;

        case VMF_RPC_FKT_REGISTER_EXT_MOST_LINK:        /* no break */
        case VMF_RPC_FKT_REGISTER_SPY:
        case VMF_RPC_FKT_DISCONNECT:
            *p_msglen  = GET_VMF_RPC_HEADER_LENGTH; 
            break;

        case VMF_RPC_FKT_REGISTER_MOST_FB:              /* no break */
        case VMF_RPC_FKT_DEREGISTER_MOST_FB:            /* no break */
        case VMF_RPC_FKT_DEREGISTER_MOST_SHAD:
            *p_msglen = GET_VMF_RPC_HEADER_LENGTH + sizeof(p_rpc_msg->rpc_reg_fblock);
            break;

        case VMF_RPC_FKT_REGISTER_MOST_SHAD:
            *p_msglen   = GET_VMF_RPC_HEADER_LENGTH + sizeof(p_rpc_msg->rpc_reg_shadow) + (sizeof(p_rpc_msg->rpc_reg_shadow.funcIds)*(p_rpc_msg->rpc_reg_shadow.fcIds_num.length));
            break;

        case VMF_RPC_FKT_REGISTER_MSG_GRP:
        case VMF_RPC_FKT_DEREGISTER_MSG_GRP:
            *p_msglen  = GET_VMF_RPC_HEADER_LENGTH + sizeof(p_rpc_msg->rpc_reg_group)+ (sizeof(p_rpc_msg->rpc_reg_group.grps)*(p_rpc_msg->rpc_reg_group.grps_num));
            break;

        case VMF_RPC_FKT_SEND_MOST_ASYNC:
        case VMF_RPC_FKT_SEND_MOST_CTRL:
            {
                unsigned16          most_msg_len;
                most_msg_len = sizeof(VMF_VAR_MOST_MSG_TYP(0)) + (sizeof(p_rpc_msg->rpc_send_most.vmf_most_msg.data.pl[0])*p_rpc_msg->rpc_send_most.vmf_most_msg.data.length);
                *p_msglen  = GET_VMF_RPC_HEADER_LENGTH + most_msg_len;
            }
            break;


        case VMF_RPC_FKT_SEND_BASIC:
            {
                unsigned16          basic_msg_len;
                basic_msg_len = sizeof(VMF_VAR_MOST_MSG_TYP(0)) + (sizeof(p_rpc_msg->rpc_send_basic.vmf_basic_msg.data.pl[0])*(p_rpc_msg->rpc_send_basic.vmf_basic_msg.data.length));
                *p_msglen  = GET_VMF_RPC_HEADER_LENGTH + basic_msg_len;

            }
            break;

        case VMF_RPC_FKT_RECEIVE:
            *p_msglen  = GET_VMF_RPC_HEADER_LENGTH + sizeof(p_rpc_msg->rpc_receive);
            break;

        default:
        break;
    }

    return (VMF_OK);
}


/*************************************************************************//**
 *
 *   get rpc  message size\n
 *   NOTE:  this function should work on Windows and QNX 
 *
 *   \param[in] p_msglen*    -- pointer to resulting length
 *   \param[in] p_rpc_msg*   -- pointer to rpc message
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
vmf_error_t vmf_rem_get_vmf_msg_len(unsigned16 *p_msglen, vmf_msg_t *p_vmf_msg)
{
    if ((NULL == p_vmf_msg) || (NULL == p_msglen))
    {
        return (VMF_ERR_NULL_POINTER);
    }

    switch (p_vmf_msg->vmf_most_msg.msg_base.base.msg_type)
    {
        //unsigned16 pl_el_size,v1,v2,v3;

        case MSG_TYPE_MOST_MESSAGE:
            *p_msglen = sizeof(VMF_VAR_MOST_MSG_TYP(0)) + (sizeof(p_vmf_msg->vmf_most_msg.data.pl[0])*(p_vmf_msg->vmf_most_msg.data.length))+VMF_BASIC_MSG_NEAR_DATA_LENGTH;
        break;

        case MSG_TYPE_BASIC_MESSAGE:
            *p_msglen = sizeof(VMF_VAR_BASIC_MSG_TYP(0)) + (sizeof(p_vmf_msg->vmf_basic_msg.data.pl[0])*(p_vmf_msg->vmf_basic_msg.data.length))+VMF_BASIC_MSG_NEAR_DATA_LENGTH;
            break;

        default:
            *p_msglen = 0;
            break;
    }
    return (VMF_OK);
}
