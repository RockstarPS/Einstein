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

#define INVALID_TX_HANDLE  0xff
typedef unsigned8			tx_handle_t; 
typedef struct
{
	bool					in_use;
	unsigned long			laddr;
	SOCKET					rx_socks;
	tx_handle_t				tx_handle;
	vmf_client_id_t			cid;
	bool					receiving;
}con_tab_t;

typedef struct
{
	bool					in_use;
	SOCKADDR_IN				server_addr;
	unsigned long			laddr;
	SOCKET					tx_socks;
}tx_con_tab_t;

#define VMF_RPC_ONRECEIVE(rcid)			(con_tab[rcid].receiving)
#define VMF_RPC_INUSE(rcid)				(con_tab[rcid].in_use)
#define VMF_RPC_ADDR(rcid)				(con_tab[rcid].laddr)
#define VMF_RPC_RX_SOCK(rcid)			(con_tab[rcid].rx_socks)
#define VMF_RPC_TX_HANDLE(rcid)			(con_tab[rcid].tx_handle)
#define VMF_RPC_CID(rcid)				(con_tab[rcid].cid)

#define VMF_TXTAB_INUSE(txhdl)			(tx_tab[txhdl].in_use)
#define VMF_TXTAB_ADDR(txhdl)			(tx_tab[txhdl].laddr)
#define VMF_TXTAB_TX_SOCK(txhdl)		(tx_tab[txhdl].tx_socks)
#define VMF_TXTAB_SOCKADDR(txhdl)		(tx_tab[txhdl].server_addr)

#define VMF_RPC_TXTAB_SOCKADDR(rcid)	((VMF_TXTAB_SOCKADDR(VMF_RPC_TX_HANDLE(rcid))))
#define VMF_RPC_TXTAB_TXSOCK(rcid)		((VMF_TXTAB_TX_SOCK(VMF_RPC_TX_HANDLE(rcid))))

vmf_error_t		vmf_target_rx_con_init	(vmf_client_id_t cid);
vmf_error_t     vmf_target_tx_con_init	(vmf_client_id_t rcid, char *p_target_ip);
vmf_error_t     vmf_target_call			(vmf_client_id_t rcid, vmf_rpc_msg_t *p_rpc_msg, vmf_rpc_response_t *p_response);
vmf_error_t     vmf_target_call_rx		(vmf_client_id_t rcid, vmf_rpc_msg_t *p_rpc_msg, vmf_rpc_response_t *p_response);
vmf_error_t     vmf_target_disconnect	(vmf_client_id_t rcid);
vmf_client_id_t	vmf_rem_get_free_rcid	(void);
void			vmf_rem_free_rcid		(vmf_client_id_t rcid);

#endif

