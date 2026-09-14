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
*  MODULE NAME  :  nw_vmf_rem_target_rpc_server.h                                                *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   10th March 2008                                            *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  header file for rpc server                    *
******************************************************************************/
#ifndef __REM_VMF_RPC_SERVER_H
#define __REM_VMF_RPC_SERVER_H



vmf_error_t vmf_client_rpc_decoder(vmf_rpc_msg_t *p_rpc_msg,vmf_rpc_response_t *p_response);
unsigned32   vmf_rem_convert_clocks_to_ms   (unsigned64 clocks);


#endif

