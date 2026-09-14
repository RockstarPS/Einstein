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
*  MODULE NAME  :  nw_vmf_rem_util.h                                               *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   16th Feb 2009                                            *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  utility functions used by the Visteon remote message framework                    *
******************************************************************************/
#ifndef VMF_REMOTE_UTIL__H_
#define VMF_REMOTE_UTIL__H_



/* function prototypes */
vmf_error_t vmf_rem_get_rpc_msg_len(unsigned16 *p_msglen, vmf_rpc_msg_t *p_rpc_msg);
vmf_error_t vmf_rem_get_vmf_msg_len(unsigned16 *p_msglen, vmf_msg_t *p_vmf_msg);


#endif



