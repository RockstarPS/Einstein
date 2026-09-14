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

/*************************************************************************//**

  \file                 vmf_ipc.h
  \brief                header of nw_vmf_ipc.c

  \author               Joerg Merkle
  \author               Visteon Deutschland GmbH, Infotainment Software

  *****************************************************************************/
#ifndef __VMF_IPC_H__
#define __VMF_IPC_H__


/* definitions */
#define IPC_MAX_NAME_LEN               (50)
#define IPC_ALL_CHANNELS               (50)                       /*!< total number of  IPC channels including VMF,Tracer */
#define VMF_IPC_SERVER_NAME            "VMF"

/*******************************************************************************/
/* ADDED jmerkle! */
#define VMF_IPC_QUEUE_SIZE_SERVER       1
#define MAX_IPC_CHANNELS                100
#define IPC_NON_BLOCKING                true

typedef bool BOOL;
#define TRUE true
#define FALSE false

/*******************************************************************************/



/* function prototypes */
void            nw_vmf_ipc_pre_init             (void);
vmf_ret_t       nw_vmf_ipc_init                 (BOOL remove_ressources);
vmf_handle_t    nw_vmf_ipc_open                 (char *channel_name, BOOL block_on_send);
vmf_handle_t    nw_vmf_ipc_create               (char *channel_name, unsigned16 queue_size, unsigned16 msg_size);
vmf_handle_t    nw_vmf_ipc_create_async         (char *channel_name, unsigned16 queue_size, unsigned16 msg_size, unsigned32 channel_id,unsigned32 async_event);
vmf_ret_t       nw_vmf_ipc_close                (vmf_handle_t vmf_handle);
vmf_ret_t       nw_vmf_ipc_destroy              (vmf_handle_t vmf_handle);
vmf_ret_t       nw_vmf_ipc_create_channel_name  (vmf_pid_t pid, unsigned8 cid, char *p_channel_name, unsigned8 buffer_size);

vmf_ret_t       nw_vmf_ipc_send                 (vmf_handle_t vmf_handle, unsigned8 *buffer, unsigned16 number_bytes);
vmf_ret_t       nw_vmf_ipc_receive              (vmf_handle_t vmf_handle, unsigned16 buffer_size,
                                                 unsigned8 *buffer, unsigned16 *number_bytes);
vmf_ret_t       nw_vmf_ipc_timed_receive        (vmf_handle_t vmf_handle,unsigned16 buffer_size,
                                                 unsigned8 *buffer,unsigned16 *number_bytes,
                                                 unsigned16 ms_timeout);

#endif




