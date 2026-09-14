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
*  MODULE NAME  :  nw_vmf_client.h                                               *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   6th March 2008                                            *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  header file of nw_vmf_client.c                                                *
******************************************************************************/
#ifndef VMF_REM_CLIENT__H_
#define VMF_REM_CLIENT__H_

#ifdef WIN32
#define DLL_EXPORT	__declspec(dllexport)
#else
#define DLL_EXPORT
#endif

/* register as a client to the vmf-server */
DLL_EXPORT vmf_client_id_t nw_vmf_connect(char *p_my_process_name,void cb_api_vmf_msg_receive_callback(vmf_msg_t * p_vmf_msg),
                               signed32 callback_priority, unsigned16 message_queue_size, unsigned16 message_size);

DLL_EXPORT vmf_client_id_t nw_vmf_connect_async(char *p_my_process_name,unsigned16 message_queue_size,unsigned16 message_size,
                               unsigned32 osal_channel_id,unsigned32 async_event);


/* disconnect from vmf-server */
DLL_EXPORT vmf_ret_t nw_vmf_disconnect(vmf_client_id_t vmf_client_id);


/* vmf_ret vmf_register_ext_most_link */
DLL_EXPORT vmf_ret_t nw_vmf_register_ext_most_link(vmf_client_id_t vmf_client_id);

/* register a local MOST Fblock */
DLL_EXPORT vmf_ret_t nw_vmf_register_most_fblock  (vmf_client_id_t vmf_client_id,unsigned8 fBlockId,unsigned8 instId);
/* deregister a local MOST Fblock */
DLL_EXPORT vmf_ret_t nw_vmf_de_register_most_fblock(vmf_client_id_t vmf_client_id,unsigned8 fBlockId,unsigned8 instId);

/* register a local MOST Shadow (FuncIds are to be given) */
DLL_EXPORT vmf_ret_t nw_vmf_register_most_shadow  (vmf_client_id_t vmf_client_id,unsigned8 fBlockId,unsigned8 instId,unsigned16 fcIds_num,unsigned16 *funcIds);
/* deregister a local MOST Shadow */
DLL_EXPORT vmf_ret_t nw_vmf_de_register_most_shadow(vmf_client_id_t vmf_client_id,unsigned8 fBlockId,unsigned8 instId );

/* register for a none-MOST message groups */
DLL_EXPORT vmf_ret_t nw_vmf_register_msg_group    (vmf_client_id_t vmf_client_id,unsigned16 groups_num,unsigned8 * groupList);
/* deregister non-MOST message groups */
DLL_EXPORT vmf_ret_t nw_vmf_de_register_msg_group (vmf_client_id_t vmf_client_id,unsigned16 groups_num,unsigned8 * groupList);
/* register a client as message spy */
DLL_EXPORT vmf_ret_t nw_vmf_register_spy          (vmf_client_id_t vmf_client_id);


/* To send a vmf-most-async-msg */
DLL_EXPORT vmf_ret_t nw_vmf_send_most_async (vmf_client_id_t vmf_client_id,vmf_most_msg_t * vmf_msg);
/* To send a vmf-most-ctrl-msg */
DLL_EXPORT vmf_ret_t nw_vmf_send_most_ctrl  (vmf_client_id_t vmf_client_id,vmf_most_msg_t * vmf_msg);

/* To send a vmf-basic-msg */
DLL_EXPORT vmf_ret_t nw_vmf_send_basic		(vmf_client_id_t vmf_client_id,vmf_basic_msg_t * vmf_msg);
/* To send a vmf-basic-msg */
DLL_EXPORT vmf_ret_t nw_vmf_send			(vmf_client_id_t vmf_client_id,vmf_msg_t * vmf_msg);
/* To receive a vmf-msg */
DLL_EXPORT signed16 nw_vmf_receive			(vmf_client_id_t vmf_client_id,vmf_msg_t * vmf_msg, unsigned16 vmf_msg_length);


#endif
