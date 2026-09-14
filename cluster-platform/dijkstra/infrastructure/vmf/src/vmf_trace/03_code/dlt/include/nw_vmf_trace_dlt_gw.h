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
*  PROJECT NAME :  VMF dlt gateway                                                       *
*******************************************************************************
*  MODULE NAME  :  nw_vmf_trace_dlt_gw.h                                                *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   16th Oct 2013                                            *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  used by the Visteon message framework                    *
******************************************************************************/
#ifndef __VMF_TRACE_DLT_GW_H
#define __VMF_TRACE_DLT_GW_H


#define VMF_TRACE_SERVER_GW_PRIO        (10)
#define VMF_TRACE_SERVER_GW_STACK_SIZE  VMF_NW_STACK_SIZE



bool vmf_trace_dlt_gw_create_thread(void);
vmf_ret_t	nw_vmf_dlt_set_monitor_msg_grps(unsigned8 *groups,int groups_num);


#endif



