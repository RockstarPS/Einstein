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

  \file                 nw_vmf_router.h
  \brief                header of nw_vmf_router.c

  \author               Joerg Merkle
  \author               Visteon Deutschland GmbH, Infotainment Software

  *****************************************************************************/
#ifndef _NW_VMF_ROUTER_H_
#define _NW_VMF_ROUTER_H_

#include <types.h>

#define VMF_ROUTER_STARTUP_QLEN     MAX_VMF_MESSAGE_LEN                        /* size of a queue message in bytes   */
//#define VMF_ROUTER_STARTUP_QDEPTH   (100)                     /* number of messages in startup queue*/

#define VMF_MAX_SPY_NUM     5
typedef struct
{
    unsigned16    num;                                          /* number of registered spies */
    vmf_handle_t  handle[VMF_MAX_SPY_NUM];                      /* number of registered spies */
}vmf_spy_tab_t;


/* global function prototypes */
vmf_ret_t nw_vmf_router (void);
vmf_ret_t nw_vmf_router_msg_send (vmf_handle_t client_handle, unsigned8 *message, unsigned16 msg_size,unsigned8 *raw_buffer);
vmf_handle_t nw_vmf_router_get_client_handle (pid_t pid, vmf_client_id_t cid);

vmf_ret_t   nw_vmf_spy_send_msg   (unsigned8 *message, unsigned16 msg_size,unsigned8 *raw_buffer);
bool        nw_vmf_is_spy_avail   (void);
vmf_ret_t   nw_vmf_delete_spy(vmf_handle_t spy_handle);


#endif

