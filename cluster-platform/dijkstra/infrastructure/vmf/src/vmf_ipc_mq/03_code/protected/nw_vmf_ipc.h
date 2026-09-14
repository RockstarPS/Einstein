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
#define MAX_IPC_CLIENTS                 60                  /*!< Maximum number of clients */
#define MAX_IPC_CHANNELS                2*MAX_IPC_CLIENTS   /*!< Maximum number of IPC connection channels */

#define VMF_IPC_QUEUE_SIZE_SERVER       (unsigned16) 200                        /*!< Server queue size */
#define VMF_IPC_QUEUE_SIZE_MIN          (unsigned16) 5                          /*!< Client minimum queue size */
#define VMF_IPC_QUEUE_SIZE_MAX          (unsigned16) VMF_IPC_QUEUE_SIZE_SERVER  /*!< Client maximum queue size */
#define VMF_IPC_MSG_SIZE_MIN            (unsigned16) MIN_VMF_MESSAGE_LEN        /*!< Minimum message size */
#define VMF_IPC_MSG_SIZE_MAX            (unsigned16) MAX_VMF_MESSAGE_LEN        /*!< Maximum message size */

#define IPC_SERVER_CHANNEL_NAME         "/vmf"            /*!< Name of server receive queue */
#define VMF_TRACE_STARTUP_Q             "/vmf_trace_startup"    /*<! name of tracer startup Q */     
#define IPC_IP_PORT                     3141
#define IPC_CHANNEL_NAME_SIZE_MIN       16                          /*!< Minimum of buffer size for channel name */

#define IPC_BLOCKING                    true                        /*!< Parameter definition for opening IPC */
#define IPC_NON_BLOCKING                false                       /*!< Parameter definition for opening IPC */

#define IPC_VERSION_STRING              "Message-Queue-IPC"
#define VMF_IPC_TYPE                    VMF_CTRL_IPC_MQ

NW_COMPILER_MESSAGE ("MQ Socket IPC")




#pragma pack(push,1)

/* VmfQStatus payload transfered with group VMF_TRACE_CTRL, event VMF_SHM_IPC_STATUS_QUEUES */
typedef struct  
{
    unsigned16              version;                                    /* version of the status message (currently 0) */
    unsigned16              num_queues;                                 /* number of message queues */
    unsigned16              queue_high_wm[MAX_IPC_CHANNELS];            /* high watermark of the queues - 0xffff means inactive queue */
}vmf_ipc_status_queue_t;


/* VmfQStatus  payload transfered with group VMF_TRACE_CTRL, event VMF_SHM_IPC_STATUS_POOLS */
typedef struct  
{
    unsigned16              version;                                    /* version of the status message (currently 0) */
    unsigned8               queue;                                      /* queue number */
    unsigned8               name_len;                                   /* len of queue name  */
    char                    name[2*MAX_NAME_LEN];                       /* queue name */
}vmf_ipc_status_queue_name_t;
  

#pragma pack(pop)



/* function prototypes */
void            nw_vmf_ipc_pre_init             (void);
vmf_ret_t       nw_vmf_ipc_init                 (bool remove_ressources);
vmf_handle_t    nw_vmf_ipc_open                 (char *channel_name, bool block_on_send);
vmf_handle_t    nw_vmf_ipc_create               (char *channel_name, unsigned16 queue_size, unsigned16 msg_size);
vmf_handle_t    nw_vmf_ipc_create_async         (char *channel_name, unsigned16 queue_size, unsigned16 msg_size, unsigned32 coid,unsigned32 async_event);
vmf_ret_t       nw_vmf_ipc_close                (vmf_handle_t vmf_handle);
vmf_ret_t       nw_vmf_ipc_destroy              (vmf_handle_t vmf_handle);
vmf_ret_t       nw_vmf_ipc_create_channel_name  (pid_t pid, unsigned8 cid, char *p_channel_name, unsigned8 buffer_size);
vmf_ret_t       nw_vmf_ipc_register_queue_name  (vmf_handle_t vmf_handle, const char* p_connection_name);

vmf_ret_t       nw_vmf_ipc_send                 (vmf_handle_t vmf_handle, unsigned8 *buffer, unsigned16 number_bytes);
vmf_ret_t       nw_vmf_ipc_receive              (vmf_handle_t vmf_handle, unsigned16 buffer_size,
                                                 unsigned8 *buffer, unsigned16 *number_bytes);
vmf_ret_t       nw_vmf_ipc_timed_receive        (vmf_handle_t vmf_handle,unsigned16 buffer_size,
                                                 unsigned8 *buffer,unsigned16 *number_bytes,
                                                 unsigned16 ms_timeout);

bool            nw_vmf_ipc_create_status_thread (void);
void            nw_vmf_ipc_stop_status_thread   (void);
bool            nw_vmf_ipc_is_status_thread_running(void);

#endif

