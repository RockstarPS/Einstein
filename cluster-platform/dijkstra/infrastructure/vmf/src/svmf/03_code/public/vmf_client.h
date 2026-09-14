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
*  MODULE NAME  :  vmf_client.h                                               *
*  AUTHOR NAME  :  Joachim Becker                                                   *
*******************************************************************************
*  MODULE DATE  :   6th March 2008                                            *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  header file of nw_vmf_client.c                                                *
******************************************************************************/
#ifndef VMF_CLIENT__H_
#define VMF_CLIENT__H_

#include "vmf_ipc.h"

#define MAX_NAME_LEN					IPC_MAX_NAME_LEN
#define MAX_SERVER_CONNECTIONS			(10)
#define VMF_CLIENT_WAIT_SOME_TIME   	(50)                      /* wait ime in ms in case of error */
#define VMF_CLIENT_WAIT_SERVER_TIMEOUT  (5000)                    /* server timeout */
#define NW_VMF_CLIENT_UNDEFINED    		"UNDEFINED-CLIENT"

#define IPC_BLOCKING                	TRUE                     
#define MAX_CTRL_CONN_PL_LEN			VMF_PL_LEN_STD

typedef struct
{
    BOOL                in_use;
    BOOL                receiver_started;                   /**<* true if a receiver is started for this cid */
    char                my_channel_name[MAX_NAME_LEN+1];    /**< connection name */
    vmf_pid_t           pid;                                /**< client pid   */
    vmf_handle_t        rx_handle;                          /**< receive handle */
    vmf_handle_t        tx_handle;                          /**< transmit handle */
}my_cid_t;

typedef struct
{
    vmf_cid_t     		free_cid;
    my_cid_t            my_cid[MAX_SERVER_CONNECTIONS];
}my_cid_tab_t;

#endif
