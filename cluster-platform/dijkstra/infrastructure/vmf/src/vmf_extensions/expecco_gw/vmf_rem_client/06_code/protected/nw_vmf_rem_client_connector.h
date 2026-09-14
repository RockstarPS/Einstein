/******************************************************************************
*                                                                             *
*                   CONFIDENTIAL - Visteon Automotive Systems                 *
*                                                                             *
*  This is an unpublished work, which is a trade secret, created in 2007.     *
*  Visteon Automotive Systems owns all rights to this work and intends to     *
*  maintain it in confidence to preserve its trade secret status.  Visteon    *
*  Automotive Systems reserves the right to protect this work as an           *
*  unpublished copyrighted work in the event of an inadvertent or deliberate  *
*  unauthorized publication.  Visteon Automotive Systems also reserves        *
*  its rights under the copyright laws to protect this work as a published    *
*  work.  Those having access to this work may not copy it, use it, or        *
*  disclose the information contained in it without the written authorization *
*  of Visteon Automotive Systems.                                             *
*                                                                             *
*******************************************************************************
*  PROJECT NAME :  VMF                                                        *
*******************************************************************************
*  MODULE NAME  :  nw_vmf_rem_client_connector.h                                              *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   16th Feb 2009                                            *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  vmf client connector header file                                           *
******************************************************************************/
#ifndef VMF_TARGET_CONN__H_
#define VMF_TARGET_CONN__H_




vmf_error_t vmf_target_tx_con_init(char * p_target_ip);
vmf_error_t vmf_target_call(vmf_rpc_msg_t *p_rpc_msg, vmf_rpc_response_t *p_response);
vmf_error_t vmf_target_call_rx(vmf_rpc_msg_t *p_rpc_msg, vmf_rpc_response_t *p_response);
vmf_error_t vmf_target_rx_con_init(vmf_client_id_t cid);
vmf_error_t vmf_target_disconnect(vmf_client_id_t cid);


#endif

