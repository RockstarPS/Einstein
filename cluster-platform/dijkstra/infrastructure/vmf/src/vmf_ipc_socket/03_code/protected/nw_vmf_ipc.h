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

  \file                 nw_vmf_ipc.h
  \brief                header of nw_vmf_ipc.c

  \author               Joerg Merkle
  \author               Visteon Deutschland GmbH, Infotainment Software

  *****************************************************************************/
#ifndef __VMF_IPC_H__
#define __VMF_IPC_H__

#include "nw_vmf_controller.h"

/* definitions */
#define MAX_IPC_CHANNELS                126                         /*!< Maximum number of IPC connection channels */
                                                                    /*!< NOTE: each connection require 2 channels! */

#define VMF_IPC_QUEUE_SIZE_SERVER       (unsigned16) 200                        /*!< Server queue size */
#define VMF_IPC_QUEUE_SIZE_MIN          (unsigned16) 5                          /*!< Client minimum queue size */
#define VMF_IPC_QUEUE_SIZE_MAX          (unsigned16) VMF_IPC_QUEUE_SIZE_SERVER  /*!< Client maximum queue size */
#define VMF_IPC_MSG_SIZE_MIN            (unsigned16) MIN_VMF_MESSAGE_LEN        /*!< Minimum message size */
#define VMF_IPC_MSG_SIZE_MAX            (unsigned16) MAX_VMF_MESSAGE_LEN        /*!< Maximum message size */

#ifdef INTEGRITY
#define IPC_SERVER_CHANNEL_NAME         "vmf_server"                /*!< Name of server receive queue */
#define VMF_TRACE_STARTUP_Q             "vmf_trace_startup"         /*<! name of tracer startup Q */
#else
#define IPC_SERVER_CHANNEL_NAME         "/dev/127.0.0.1"            /*!< Name of server receive queue */
#define VMF_TRACE_STARTUP_Q             "/dev/vmf_trace_startup"    /*<! name of tracer startup Q */
#endif

#define IPC_IP_PORT                     3141
#define IPC_CHANNEL_NAME_SIZE_MIN       16                          /*!< Minimum of buffer size for channel name */

#define IPC_BLOCKING                    true                        /*!< Parameter definition for opening IPC */
#define IPC_NON_BLOCKING                false                       /*!< Parameter definition for opening IPC */

#define IPC_VERSION_STRING              "DOMAIN-SOCKET IPC"
#define VMF_IPC_TYPE                    VMF_CTRL_IPC_DSOCK
NW_COMPILER_MESSAGE ("DOMAIN Socket IPC")


/* function prototypes */
void            nw_vmf_ipc_pre_init             (void);
vmf_ret_t       nw_vmf_ipc_init                 (bool remove_ressources);
vmf_handle_t    nw_vmf_ipc_open                 (char *channel_name, bool block_on_send);
vmf_handle_t    nw_vmf_ipc_create               (char *channel_name, unsigned16 queue_size, unsigned16 msg_size);
vmf_handle_t    nw_vmf_ipc_create_async         (char *channel_name, unsigned16 queue_size, unsigned16 msg_size, unsigned32 channel_id,unsigned32 async_event);
vmf_ret_t       nw_vmf_ipc_close                (vmf_handle_t vmf_handle);
vmf_ret_t       nw_vmf_ipc_destroy              (vmf_handle_t vmf_handle);
vmf_ret_t       nw_vmf_ipc_create_channel_name  (pid_t pid, unsigned8 cid, char *p_channel_name, unsigned8 buffer_size);

vmf_ret_t       nw_vmf_ipc_send                 (vmf_handle_t vmf_handle, unsigned8 *buffer, unsigned16 number_bytes);
vmf_ret_t       nw_vmf_ipc_receive              (vmf_handle_t vmf_handle, unsigned16 buffer_size,
                                                 unsigned8 *buffer, unsigned16 *number_bytes);
vmf_ret_t       nw_vmf_ipc_timed_receive        (vmf_handle_t vmf_handle,unsigned16 buffer_size,
                                                 unsigned8 *buffer,unsigned16 *number_bytes,
                                                 unsigned16 ms_timeout);

#endif




