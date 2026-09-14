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

/***************************************************************************

  Module:               nw_vmf_rem_client_connector.c
  Description:          connects windows vmf client with target

  Project Scope:        Beethoven VM platform

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   Visual Studio
  Target Hardware:      Any

  *****************************************************************************/

#if 1
 #define NW_VMF_DEBUG
 #define DO_CLIENT_DEBUG_HEX
 #define DO_CLIENT_DEBUG
 #define VMF_REM_DEBUG
#endif

#include "nw_vmf_rem.h"
#include "nw_vmf_rem_client_connector.h"


/*************** MACROS *********************/
#define VMF_RPC_LOCK     if (pthread_mutex_lock((&rpcMutex)) != 0) {NW_REM_VMF_DEBUG_ERROR("VMF-CLient-Lib: mutex Lock Failed %s line %d\n", __FILE__, __LINE__);}
#define VMF_RPC_UNLOCK   if (pthread_mutex_unlock((&rpcMutex)) != 0) {NW_REM_VMF_DEBUG_ERROR("VMF-CLient-Lib: mutex Unlock Failed %s line %d\n", __FILE__, __LINE__);}
#define VMF_RPC_INIT     if (false == bmyMutexInitialized) rpc_mutex_init(&rpcMutex);



/** definition of the rx connection table.\n
*   the connection description for each
*   connection instance is stored in this table.
*/



#define SIO_KEEPALIVE_VALS _WSAIOW(IOC_VENDOR,4)

typedef struct {
u_long onoff;
u_long keepalivetime;
u_long keepaliveinterval;
}tcp_keepalive;

/* global data */
tx_con_tab_t				tx_tab[VMF_RPC_MAX_SERVER_CONNECTIONS];
con_tab_t					con_tab[VMF_RPC_MAX_SERVER_CONNECTIONS];

static tx_handle_t			max_tx_handle=0;
static WSADATA				wsaData;
static pthread_mutex_t		rpcMutex;
static bool					rpcMutexIsInit=false;
static bool					bmyMutexInitialized=false;
static SOCKET				client_tx_socket=0;
static int					i_wsastartup=0;

/* local functions */
static vmf_error_t	rpc_mutex_init				(pthread_mutex_t *pMutex);
static vmf_error_t	vmf_target_connect			(SOCKET *p_sock,SOCKADDR_IN *pserver_addr);
static vmf_error_t	vmf_target_recv_answer		(vmf_rpc_response_t *p_response,SOCKET sock);
static vmf_error_t	vmf_target_send_request		(vmf_rpc_msg_t *p_rpc_msg,SOCKET sock);
static int			recv_wait					(SOCKET s,char * buf,int len,int flags);
static void			vmf_rem_init_con_tabs		(void);
static unsigned8	vmf_rem_get_tx_handle		(unsigned long	laddr);
static tx_handle_t	vmf_rem_get_free_tx_handle	(void);
static vmf_error_t	vmf_target_con_init			(void);
static void			vmf_rem_free_tx_handle		(tx_handle_t tx_hdl);


/*************************************************************************//**
 *
 *   vmf target connector init \n
 *   NOTE: init the remote conector
 *   
 *
 *   \param[in] void
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
static vmf_error_t vmf_target_con_init(void)
{
	static init_done = false;
	vmf_ret_t	vmf_ret = VMF_OK;

	VMF_RPC_INIT

	if (false == init_done)
	{
		NW_REM_VMF_DEBUG_PRINTF("  vmf_target_con_init()");

		/* setup tcp stack */
		if (0 == i_wsastartup)
		{
			i_wsastartup = WSAStartup(MAKEWORD(2,2), &wsaData);
			if (i_wsastartup != 0)
			{
				NW_REM_VMF_DEBUG_PRINTF("  WSAStartup failed: %d", i_wsastartup);
				return VMF_ERROR;
			}
		}
		
		vmf_rem_init_con_tabs();					/* init the connection tables */
		NW_REM_VMF_DEBUG_PRINTF("  vmf_target_con_init()done");
	}
	return vmf_ret;
}






/*************************************************************************//**
 *
 *   vmf target tx connection init \n
 *   NOTE: create tx socket and connect tx socket to target.
 *   
 *
 *   \param[in] void
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
vmf_error_t vmf_target_tx_con_init(vmf_client_id_t rcid, char *p_target_ip)
{
	SOCKADDR_IN		server_addr;
	tx_handle_t		tx_hdl;
	vmf_error_t		vmf_ret=VMF_OK;
    unsigned long   u_tmp_addr=0;

	NW_REM_VMF_DEBUG_PRINTF("  vmf_target_tx_con_init(rcid=%d, addr=%s)",rcid,p_target_ip);

	vmf_ret = vmf_target_con_init();
	if (vmf_ret != VMF_OK)
	{
		return vmf_ret;
	}
	
	/* argument check */
    if (NULL == p_target_ip)
	{
		NW_REM_VMF_DEBUG_ERROR("  vmf_target_tx_con_init(rcid=%d) p_target_ip == NULL",rcid);
		return VMF_ERROR;
	}
	if (rcid <=0)
	{
		NW_REM_VMF_DEBUG_ERROR("  vmf_target_tx_con_init(rcid=%d) out of range",rcid);
		return VMF_ERR_OUT_OF_RANGE;
	}

	/* argument check */
	if (rcid >= VMF_RPC_MAX_SERVER_CONNECTIONS)
	{
		NW_REM_VMF_DEBUG_ERROR("  vmf_target_tx_con_init(rcid=%d) out of range",rcid);
		return VMF_ERR_OUT_OF_RANGE;
	}


	/* test if target is already connected */
	u_tmp_addr = inet_addr(p_target_ip);

	tx_hdl = vmf_rem_get_tx_handle(u_tmp_addr);
	if (INVALID_TX_HANDLE == tx_hdl)
	{
		/* target is not connected - get a free tx-handle */
		tx_hdl = vmf_rem_get_free_tx_handle();
		if (INVALID_TX_HANDLE == tx_hdl)
		{
			NW_REM_VMF_DEBUG_PRINTF("  vmf_rem_get_free_tx_handle() failed - no free tx handle");
			return VMF_ERR_OUT_OF_IPC_CHANNELS;
		}
		else
		{
			SOCKET	*psock;

			NW_REM_VMF_DEBUG_PRINTF("  vmf_rem_get_free_tx_handle(rcid=%d) got - free tx handle %d",rcid,tx_hdl);

			if (INADDR_NONE != u_tmp_addr)
			{
				server_addr.sin_addr.s_addr = u_tmp_addr;
				NW_REM_VMF_DEBUG_PRINTF("  vmf_target_tx_con_init(rcid=%d) try to connect to target addr: %s",rcid,p_target_ip);
			}
			server_addr.sin_port	= htons(VMF_RPC_SERVER_PORT);
			server_addr.sin_family	= AF_INET;

			/* connect to target */
			psock	= &(VMF_TXTAB_TX_SOCK(tx_hdl));
			VMF_TXTAB_SOCKADDR(tx_hdl)	= server_addr;
			VMF_TXTAB_ADDR(tx_hdl)		= u_tmp_addr;
			VMF_RPC_TX_HANDLE(rcid)		= tx_hdl;

			NW_REM_VMF_DEBUG_PRINTF("  vmf_target_tx_con_init(rcid=%d) store tx_hdl=%d in %p",rcid,tx_hdl,&VMF_RPC_TX_HANDLE(rcid));

			vmf_ret = vmf_target_connect((SOCKET*)psock,&server_addr);
			if (VMF_OK ==vmf_ret)
			{
				VMF_TXTAB_TX_SOCK(tx_hdl) = *psock;
				NW_REM_VMF_DEBUG_PRINTF("  vmf_target_tx_con_init(rcid=%d) connected to target %s socket=%d",rcid,p_target_ip,VMF_TXTAB_TX_SOCK(tx_hdl));
			}
			else
			{
				/* connect to target failed - clear entry */
				NW_REM_VMF_DEBUG_PRINTF("  vmf_target_tx_con_init(rcid=%d) vmf_target_connect() failed",rcid);
				vmf_rem_free_tx_handle(tx_hdl);
				VMF_RPC_TX_HANDLE(rcid) = INVALID_TX_HANDLE;
			}
		}
	}

	/* store tx handle for thir rcid */
	VMF_RPC_TX_HANDLE(rcid)=tx_hdl;

	return vmf_ret;
}




/*************************************************************************//**
 *
 *   vmf target rx connector init \n
 *   NOTE: create rx socket and connect rx socket to target.
 *   
 *
 *   \param[in] vmf_client_id_t	 -- pointer to cid
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
vmf_error_t vmf_target_rx_con_init(vmf_client_id_t rcid)
{
	vmf_error_t vmf_ret=VMF_OK;
	SOCKADDR_IN	*psockaddr=NULL;
	SOCKET		*psocket=NULL;
//	vmf_client_id_t		cid;

	NW_REM_VMF_DEBUG_PRINTF("  vmf_target_rx_con_init(rcid=%d)",rcid);
	if (rcid >= VMF_RPC_MAX_SERVER_CONNECTIONS)
	{
		NW_REM_VMF_DEBUG_ERROR("  vmf_target_rx_con_init(rcid=%d) out of range",rcid);
		return VMF_ERR_OUT_OF_RANGE;
	}

//	cid = VMF_RPC_CID(rcid);

	/* argument check */
	if (rcid >= VMF_RPC_MAX_SERVER_CONNECTIONS)
	{
		return VMF_ERR_OUT_OF_RANGE;
	}

	if (0 == VMF_RPC_TXTAB_TXSOCK(rcid))
	{
		/* tx channel not connected! */
		NW_REM_VMF_DEBUG_PRINTF("  vmf_target_rx_con_init(rcid=%d) error tx channel not connected!",rcid);
		return VMF_ERROR;
	}

	/* connect to target */
	psockaddr = &VMF_RPC_TXTAB_SOCKADDR(rcid);
	psocket = &VMF_RPC_RX_SOCK(rcid);
	vmf_ret = vmf_target_connect(psocket,psockaddr);

	if (VMF_OK == vmf_ret)
	{
		NW_REM_VMF_DEBUG_PRINTF("  vmf_target_rx_con_init(rcid=%d) connected to target socket=%d",rcid,VMF_RPC_RX_SOCK(rcid));
	}

	return vmf_ret;
}



/*************************************************************************//**
 *
 *   vmf_target_disconnect \n
 *   NOTE: disconnect from vmf-server.
 *   
 *
 *   \param[in] vmf_client_id_t	 -- pointer to cid
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
vmf_error_t vmf_target_disconnect(vmf_client_id_t rcid)
{
	vmf_error_t vmf_ret=VMF_OK;

	NW_REM_VMF_DEBUG_PRINTF("  vmf_target_disconnect(rcid=%d)",rcid);

	/* argument check */
	if (rcid >= VMF_RPC_MAX_SERVER_CONNECTIONS)
	{
		NW_REM_VMF_DEBUG_ERROR("  vmf_target_disconnect(rcid=%d) out of range",rcid);
		return VMF_ERR_OUT_OF_RANGE;
	}
	if (false == VMF_RPC_INUSE(rcid))
	{
		return VMF_ERR_INVALID_VMF_HANDLE;
	}


	/* disconnect from target */
	NW_REM_VMF_DEBUG_PRINTF("  vmf_target_disconnect(rcid=%d) shutdown sock=%d",rcid,(VMF_RPC_RX_SOCK(rcid)));
	shutdown((VMF_RPC_RX_SOCK(rcid)),SD_BOTH);

	/* free rcid */
	vmf_rem_free_rcid(rcid);

	return vmf_ret;
}








/*************************************************************************//**
 *
 *   call rpc function on target  \n
 *   NOTE: call via tx socket
 *   
 *
 *   \param[in] pmsg	 -- pointer to a gw message
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
vmf_error_t vmf_target_call(vmf_client_id_t rcid, vmf_rpc_msg_t *p_rpc_msg, vmf_rpc_response_t *p_response)
{
	vmf_ret_t			vmf_ret=VMF_OK;
	tx_handle_t			tx_hdl=0;
	SOCKET				txsock;

	NW_REM_VMF_DEBUG_PRINTF("  vmf_target_call(rcid=%d)",rcid);

	/* argument check */
	if (rcid >= VMF_RPC_MAX_SERVER_CONNECTIONS)
	{
		NW_REM_VMF_DEBUG_ERROR("  vmf_target_call(rcid=%d) out of range",rcid);
		return VMF_ERR_OUT_OF_RANGE;
	}

	/* send rpc message to target */
	if (false == VMF_RPC_INUSE(rcid))
	{
		return VMF_ERR_INVALID_VMF_HANDLE;
	}

	tx_hdl = VMF_RPC_TX_HANDLE(rcid);
	txsock = VMF_TXTAB_TX_SOCK(tx_hdl);

	if (false == VMF_TXTAB_INUSE(tx_hdl))
	{
		return VMF_ERR_INVALID_VMF_HANDLE;
	}

	vmf_ret = vmf_target_send_request(p_rpc_msg,txsock);
	if (VMF_OK == vmf_ret)
	{
		vmf_ret = vmf_target_recv_answer(p_response,VMF_RPC_TXTAB_TXSOCK(rcid));
		if (VMF_OK == vmf_ret)
		{
			vmf_ret = p_response->response; 	
		}
	}
	else
	{
		/* tcp error on tx socket */
		/* close connection and free table */
		shutdown(txsock,SD_BOTH);
		vmf_rem_free_tx_handle(tx_hdl);
	}

	NW_REM_VMF_DEBUG_PRINTF("  vmf_target_call(rcid=%d) ret=%d",rcid,vmf_ret);
	return vmf_ret;
}



/*************************************************************************//**
 *
 *   call rpc receive function on target  \n
 *   NOTE: call via rx socket
 *   
 *
 *   \param[in] pmsg	 -- pointer to a gw message
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
vmf_error_t vmf_target_call_rx(vmf_client_id_t rcid, vmf_rpc_msg_t *p_rpc_msg, vmf_rpc_response_t *p_response)
{
	vmf_ret_t			vmf_ret=VMF_OK;
	SOCKET				rx_sock;

	NW_REM_VMF_DEBUG_PRINTF("  vmf_target_call_rx(rcid=%d)",rcid);


	/* argument check */
	if (rcid >= VMF_RPC_MAX_SERVER_CONNECTIONS)
	{
		NW_REM_VMF_DEBUG_ERROR("  vmf_target_call_rx(rcid=%d) out of range",rcid);
		return VMF_ERR_OUT_OF_RANGE;
	}

	if (true == VMF_RPC_ONRECEIVE(rcid))
	{
		/* there is already an active receiver for this rcid !!*/
		NW_REM_VMF_DEBUG_ERROR("    vmf_target_call_rx(%d): already active receiver!!",rcid);
		return VMF_ERROR;
	}

	VMF_RPC_ONRECEIVE(rcid)=true;
	rx_sock = VMF_RPC_RX_SOCK(rcid);

	if (0 == rx_sock)
	{
		VMF_RPC_ONRECEIVE(rcid)=false;
		return VMF_ERR_REM_SOCK_INVALID;
	}

	if (false == VMF_RPC_INUSE(rcid))
	{
		VMF_RPC_ONRECEIVE(rcid)=false;
		return VMF_ERR_INVALID_VMF_HANDLE;
	}

	/* send rpc message to target */
	vmf_ret = vmf_target_send_request(p_rpc_msg,rx_sock);
	if (VMF_OK == vmf_ret)
	{
		vmf_ret = vmf_target_recv_answer(p_response,rx_sock);
		if (VMF_OK == vmf_ret)
		{
			vmf_ret = p_response->response; 	
		}
		else
		{
			/* we got an tcp error - free rcid */
			vmf_target_disconnect(rcid);
		}
	}
	else
	{
		/* we got an tcp error - free rcid */
		vmf_target_disconnect(rcid);
	}

	NW_REM_VMF_DEBUG_PRINTF("  vmf_target_call_rx(rcid=%d) ret=%d",rcid,vmf_ret);
	VMF_RPC_ONRECEIVE(rcid)=false;
	return vmf_ret;
}



/******************************************************************************
 *		local functions
 ******************************************************************************/



/*************************************************************************//**
 *
 *   send rpc message to target\n
 *   NOTE: 
 *   
 *
 *   \param[in] rpc_msg	 -- pointer to a rpc message
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
static vmf_error_t vmf_target_send_request(vmf_rpc_msg_t *p_rpc_msg,SOCKET sock)
{
	vmf_ret_t	vmf_ret=VMF_OK;
	int			reslt;

	if (NULL == p_rpc_msg)
	{
		NW_REM_VMF_DEBUG_ERROR("    vmf_target_send_request(): error NULL poiner");
		return VMF_ERR_NULL_POINTER;
	}
	
    /* Send the rpc message */
    reslt = send( sock, (char *)p_rpc_msg, p_rpc_msg->msg_length.length, 0 );
    if (reslt == SOCKET_ERROR) 
	{
        NW_REM_VMF_DEBUG_ERROR("    vmf_target_send_request() send failed: %d, socket=%d", WSAGetLastError(),sock);
        closesocket(sock);
		client_tx_socket = 0;
        vmf_ret =  VMF_ERROR;
	}



	return vmf_ret;
}




/*************************************************************************//**
 *
 *   receive rpc message from target\n
 *   NOTE: 
 *   
 *
 *   \param[in] **vmf_rpc_msg_t	 -- pointer pointer to a rpc message
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
static vmf_error_t vmf_target_recv_answer(vmf_rpc_response_t *p_response,SOCKET sock)
{
	vmf_ret_t	vmf_ret=VMF_OK;
	int			num_bytes;

	if (NULL == p_response)
	{
		NW_REM_VMF_DEBUG_ERROR("    vmf_target_recv_answer(): error NULL pointer");
		return VMF_ERR_NULL_POINTER;
	}

	/* read the message size */
	num_bytes = recv_wait(sock,(char*)p_response ,sizeof(p_response->msg_length),0);

	/* cut message if too big */
	if (num_bytes > VMF_REM_MAX_DATA_SIZE)
	{
		NW_REM_VMF_DEBUG_ERROR("    vmf_target_recv_answer(): num_bytes too big (%d bytes)",num_bytes);
		num_bytes = VMF_REM_MAX_DATA_SIZE;
	}

	/* read remaining data */
	num_bytes = recv_wait(sock,(char*)&(p_response->rpc_id),p_response->msg_length.length - num_bytes,0);
	if (num_bytes <= 0)
	{
		NW_REM_VMF_DEBUG_ERROR("    vmf_target_recv_answer(): recv_wait() failed, socket=%d",sock);
		vmf_ret = VMF_ERROR;
	}

	return vmf_ret;
}



/*************************************************************************//**
 *
 *   connect to target VMF Server\n
 *   NOTE: 
 *   
 *
 *   \param[in] SOCKET*	 -- pointer to socket for connection
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
static vmf_error_t vmf_target_connect(SOCKET *p_sock,SOCKADDR_IN *pserver_addr)
{
	int	result= VMF_ERROR;

	NW_REM_VMF_DEBUG_PRINTF("    vmf_target_connect()");

	if (NULL == pserver_addr)
	{
		NW_REM_VMF_DEBUG_ERROR("    vmf_target_connect: error SOCKADDR NULL pointer");
		return VMF_ERR_NULL_POINTER;
	}

	if (NULL == p_sock)
	{
		NW_REM_VMF_DEBUG_ERROR("    vmf_target_connect: error NULL poiner");
		return VMF_ERR_NULL_POINTER;
	}

    /* Create a SOCKET for connecting to server */
    *p_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (*p_sock == INVALID_SOCKET) 
	{
        NW_REM_VMF_DEBUG_ERROR("    Error at socket(): %ld", WSAGetLastError() );
        return VMF_ERROR;
    }


	{
	/* set socket options */
	    int dummy = 1;
		unsigned long  dwError = 0L ;
		unsigned long dwBytes;
		tcp_keepalive sKA_Settings = {0};
		tcp_keepalive sReturned    = {0} ;
		
		setsockopt(*p_sock,SOL_SOCKET,SO_KEEPALIVE,(char *)&dummy,sizeof(dummy));

		sKA_Settings.onoff = 1 ;
		sKA_Settings.keepalivetime = 1000 ; // Keep Alive in 5.5 sec.
		sKA_Settings.keepaliveinterval = 1500 ; // Resend if No-Reply
		if (WSAIoctl(*p_sock, SIO_KEEPALIVE_VALS, &sKA_Settings,
					 sizeof(sKA_Settings), &sReturned, sizeof(sReturned), &dwBytes,
					 NULL, NULL) != 0)
		{
			dwError = WSAGetLastError() ;
			NW_REM_VMF_DEBUG_ERROR("    vmf_target_connect: SIO_KEEPALIVE_VALS failed with: %d", dwError);
		}
	}

	/* set server address */
	#if 0
	server_addr.sin_addr.s_addr = inet_addr(VMF_RPC_SERVER_IP);
    server_addr.sin_port = htons(VMF_RPC_SERVER_PORT);
	server_addr.sin_family = AF_INET;
    #endif

	/* connect to VMF rpc server */
	result = connect( *p_sock, (SOCKADDR*) pserver_addr, sizeof(SOCKADDR) );
    if ( result == SOCKET_ERROR) {
		NW_REM_VMF_DEBUG_ERROR("    vmf_target_connect: Unable to connect to server: %d", WSAGetLastError());
        closesocket (*p_sock);
		client_tx_socket = 0;
        return VMF_ERROR;
    }

	NW_REM_VMF_DEBUG_PRINTF("    vmf_target_connect: connected to server - socket=%d",*p_sock);

	return VMF_OK;
}



/*************************************************************************//**
 *
 *   init the rpc mutex\n
 *   NOTE: 
 *   
 *
 *   \param[in] *pthread_mutex_t	 -- pointer to  mutex
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
static vmf_error_t rpc_mutex_init(pthread_mutex_t *pMutex) /**< INPUT/OUTPUT pointer to a mutex*/
{
    pthread_mutexattr_t attr;
    static  unsigned  bInUse=0;

    if (bmyMutexInitialized != false)
    {
        /* mutex already created */
        return VMF_OK;
    }

    if (0 != pthread_mutexattr_init(&attr))
    {
        NW_REM_VMF_DEBUG_ERROR("    nw_vmf_client_mutex_init() - pthread_mutexattr_init() failed");
        return(VMF_ERR_REM_MUTEX_INIT);
    }

    /* initialize mutex as a blocking mutex */
    if (0 != pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_NORMAL))
    {
        NW_REM_VMF_DEBUG_ERROR("    nw_vmf_client_mutex_init() - pthread_mutexattr_settype() failed");
        pthread_mutexattr_destroy(&attr);
        return(VMF_ERR_REM_MUTEX_INIT);
    }

    if(pthread_mutex_init( pMutex, &attr ))
    {
        NW_REM_VMF_DEBUG_ERROR("    nw_vmf_client_mutex_init() - pthread_mutex_init() failed");
        pthread_mutexattr_destroy(&attr);
        return(VMF_ERR_REM_MUTEX_INIT);
    }
    pthread_mutexattr_destroy(&attr);
    bmyMutexInitialized = true;

  return(VMF_OK);
}


/*************************************************************************//**
 *
 *   receives data on a socket till all data is received  \n
 *   NOTE: done because MSG_WAITALL is not supported on Windows
 *   
 *
 *   \param[in] SOCKET	 -- socket
 *   \param[in] buf		 -- buffer for rx data
 *   \param[in] len		 -- buffer len
 *   \param[in] flags	 -- rx flags
 *   \return    number of bytes or 0 or -1 
 *
 ******************************************************************************/
static int recv_wait(SOCKET s,char  * buf,int len,int flags)
{
	int num_bytes;
	unsigned16	all_bytes=0;

	while (all_bytes < len)
	{
		/* receive rpc_id */
		num_bytes = recv(s, &(buf[all_bytes]), len-all_bytes, 0);
		if (num_bytes > 0)
		{
			all_bytes+=num_bytes;			
		}
		else
		{
			return num_bytes;
		}
	}
	return all_bytes;
}



/*************************************************************************//**
 *
 *   init the rx connection table  \n
 *   NOTE: 
 *
 ******************************************************************************/
static void	vmf_rem_init_con_tabs(void)
{
	static bool init_done=false;
	unsigned16 iCnt;
	VMF_RPC_INIT
	VMF_RPC_LOCK
	if (init_done)
	{
		VMF_RPC_UNLOCK
		return;
	}

    NW_REM_VMF_DEBUG_PRINTF("    VMF-CLient-Lib: vmf_rem_init_con_tabs()");

	/*  init the rx_con_tab */
	for (iCnt=0;iCnt<VMF_RPC_MAX_SERVER_CONNECTIONS;iCnt++)
	{
		VMF_RPC_INUSE(iCnt)=false;
		VMF_RPC_ONRECEIVE(iCnt)=false;
		VMF_RPC_ADDR(iCnt)=0;
		VMF_RPC_RX_SOCK(iCnt)=0;
		VMF_RPC_TX_HANDLE(iCnt)=INVALID_TX_HANDLE;
		VMF_RPC_CID(iCnt)=0;

		VMF_TXTAB_INUSE(iCnt)	= false;
		VMF_TXTAB_ADDR(iCnt)	= 0;
		VMF_TXTAB_TX_SOCK(iCnt) = 0;
	}
	init_done = true;
	VMF_RPC_UNLOCK
}


/*************************************************************************//**
 *
 *   get a free rcid  \n
 *   NOTE: 
 *
 ******************************************************************************/
vmf_client_id_t	vmf_rem_get_free_rcid(void)
{
	vmf_client_id_t rcid=VMF_ERR_OUT_OF_IPC_CHANNELS;
	unsigned8 iCnt;
	
    NW_REM_VMF_DEBUG_PRINTF("  VMF-CLient-Lib: vmf_rem_get_free_rcid()");
	vmf_rem_init_con_tabs();
	
	VMF_RPC_INIT
	VMF_RPC_LOCK

	/*  search for free entry in rx_con_tab */
	for (iCnt=1;iCnt<VMF_RPC_MAX_SERVER_CONNECTIONS;iCnt++)
	{
		if (VMF_RPC_INUSE(iCnt)==false)
		{
			/* found free entry */
			rcid = iCnt;
			VMF_RPC_INUSE(iCnt)=true;
			break;
		}
	}
	VMF_RPC_UNLOCK
    NW_REM_VMF_DEBUG_PRINTF("  vmf_rem_get_free_rcid() rcid=%d",rcid);
	return(rcid);
}


/*************************************************************************//**
 *
 *   get a free rcid  \n
 *   NOTE: 
 *
 ******************************************************************************/
void	vmf_rem_free_rcid(vmf_client_id_t rcid)
{
    NW_REM_VMF_DEBUG_PRINTF("    VMF-CLient-Lib: vmf_rem_free_rcid(rcid=%d)",rcid);

	VMF_RPC_INIT
	VMF_RPC_LOCK

	if (rcid < VMF_RPC_MAX_SERVER_CONNECTIONS)
	{
		VMF_RPC_INUSE(rcid)		= false;
		VMF_RPC_ADDR(rcid)		= 0;
		VMF_RPC_RX_SOCK(rcid)	= 0;
		VMF_RPC_TX_HANDLE(rcid)	= INVALID_TX_HANDLE;
		VMF_RPC_CID(rcid)		= 0;
	}
	else
	{
	    NW_REM_VMF_DEBUG_ERROR("    VMF-CLient-Lib: vmf_rem_free_rcid(rcid=%d) invalid rcid",rcid);
	}

	VMF_RPC_UNLOCK
}


/*************************************************************************//**
 *
 *   get a free rcid  \n
 *   NOTE: 
 *
 ******************************************************************************/
static unsigned8 vmf_rem_get_tx_handle(unsigned long	laddr)
{
	tx_handle_t tx_handle=INVALID_TX_HANDLE;
	unsigned8 iCnt;
	VMF_RPC_INIT
	VMF_RPC_LOCK

	/*  search for the tx handle in the tx-tab */
	for (iCnt=0;iCnt<max_tx_handle;iCnt++)
	{
		if (VMF_TXTAB_INUSE(iCnt)==true)
		{
			if (VMF_TXTAB_ADDR(iCnt) == laddr)
			{
				/* found the address */
				tx_handle = iCnt;
				break;
			}
		}
	}
	VMF_RPC_UNLOCK
	return(tx_handle);
}


/*************************************************************************//**
 *
 *   get a free tx handle  \n
 *   NOTE: 
 *
 ******************************************************************************/
static tx_handle_t	vmf_rem_get_free_tx_handle(void)
{
	tx_handle_t tx_handle=INVALID_TX_HANDLE;
	unsigned8 iCnt;

    NW_REM_VMF_DEBUG_INFO("  VMF-CLient-Lib: vmf_rem_get_free_tx_handle()");

	VMF_RPC_INIT
	VMF_RPC_LOCK

	/*  search for free entry in rx_con_tab */
	for (iCnt=1;iCnt<VMF_RPC_MAX_SERVER_CONNECTIONS;iCnt++)
	{
		if (VMF_TXTAB_INUSE(iCnt)==false)
		{
			tx_handle = iCnt;
			if (max_tx_handle < tx_handle)
			{
				max_tx_handle = tx_handle;
			}
			VMF_TXTAB_INUSE(iCnt)=true;
			break;
		}
	}
	VMF_RPC_UNLOCK
    NW_REM_VMF_DEBUG_INFO("  VMF-CLient-Lib: vmf_rem_get_free_tx_handle() ret=%d",tx_handle);

	return(tx_handle);
}



/*************************************************************************//**
 *
 *   free a tx handle  \n
 *   NOTE: 
 *
 ******************************************************************************/
static void vmf_rem_free_tx_handle(tx_handle_t tx_hdl)
{
	VMF_RPC_INIT
	VMF_RPC_LOCK

    NW_REM_VMF_DEBUG_INFO("  VMF-CLient-Lib: vmf_rem_free_tx_handle(%d)",tx_hdl);
	if ((tx_hdl <= 0) || (tx_hdl > VMF_RPC_MAX_SERVER_CONNECTIONS))
	{
        NW_REM_VMF_DEBUG_ERROR("  VMF-CLient-Lib: vmf_rem_get_free_tx_handle() - invalid tx_hdl=%d",tx_hdl);
		VMF_RPC_UNLOCK
		return;
	}

	VMF_TXTAB_INUSE(tx_hdl)	= false;
	VMF_TXTAB_ADDR(tx_hdl)	= 0;
	VMF_TXTAB_TX_SOCK(tx_hdl) = 0;

	VMF_RPC_UNLOCK
	return;
}
