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

#include "nw_vmf_rem.h"


/*************** MACROS *********************/
#define VMF_RPC_LOCK     if (pthread_mutex_lock((&rpcMutex)) != 0) {NW_REM_VMF_DEBUG_ERROR("VDF-CLient-Lib: mutex Lock Failed %s line %d\n", __FILE__, __LINE__);}
#define VMF_RPC_UNLOCK   if (pthread_mutex_unlock((&rpcMutex)) != 0) {NW_REM_VMF_DEBUG_ERROR("VDF-CLient-Lib: mutex Unlock Failed %s line %d\n", __FILE__, __LINE__);}
#define VMF_RPC_INIT     if (false == bmyMutexInitialized) rpc_mutex_init(&rpcMutex);

#define VMF_RPC_RX_SOCK(cid)	(rx_con_tab.rx_socks[cid])
/** definition of the rx connection table.\n
*   the connection description for each
*   connection instance is stored in this table.
*/
typedef struct
{
	SOCKET					rx_socks[VMF_RPC_MAX_SERVER_CONNECTIONS];
}rx_con_tab_t;


#define SIO_KEEPALIVE_VALS _WSAIOW(IOC_VENDOR,4)

typedef struct {
u_long onoff;
u_long keepalivetime;
u_long keepaliveinterval;
}tcp_keepalive;

/* global data */
static rx_con_tab_t			rx_con_tab;
static WSADATA				wsaData;
static pthread_mutex_t		rpcMutex;
static bool					bmyMutexInitialized=false;
static SOCKET				client_tx_socket=0;
static struct 				sockaddr_in server_addr;


/* local functions */
static vmf_error_t	rpc_mutex_init			(pthread_mutex_t *pMutex);
static vmf_error_t	vmf_target_connect		(SOCKET *p_sock);
static vmf_error_t	vmf_target_recv_answer	(vmf_rpc_response_t *p_response,SOCKET sock);
static vmf_error_t	vmf_target_send_request	(vmf_rpc_msg_t *p_rpc_msg,SOCKET sock);
static int			recv_wait				(SOCKET s,char * buf,int len,int flags);
static void			vmf_rem_init_rx_con_list(void);



/*************************************************************************//**
 *
 *   vmf target connector init \n
 *   NOTE: create tx socket and connect tx socket to target.
 *   
 *
 *   \param[in] void
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
vmf_error_t vmf_target_tx_con_init(char *p_target_ip)
{
	int iResult;
	vmf_error_t vmf_ret=VMF_OK;
    unsigned long   u_tmp_addr;

	NW_REM_VMF_DEBUG_PRINTF("vmf_target_tx_con_init()\n");

	if (0 != client_tx_socket)
	{
		/* target already connected */
		return VMF_OK;
	}

	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

	/* init mutex */
	vmf_ret = rpc_mutex_init(&rpcMutex);
	if (vmf_ret !=  VMF_OK)
	{
		return vmf_ret;
	}

	vmf_rem_init_rx_con_list();					/* init the rx connection table */

	/* setup tcp stack */
	if (iResult != 0)
	{
		NW_REM_VMF_DEBUG_PRINTF("WSAStartup failed: %d\n", iResult);
		return VMF_ERROR;
	}

    /* set target IP adresse and port */
    if (NULL != p_target_ip)
    {
		u_tmp_addr = inet_addr(p_target_ip);
        if (INADDR_NONE != u_tmp_addr)
        {
			server_addr.sin_addr.s_addr = inet_addr(p_target_ip);
			NW_REM_VMF_DEBUG_PRINTF("vmf_target_tx_con_init() connect to target addr: %s\n",p_target_ip);
        }
	    else
	    {
			server_addr.sin_addr.s_addr = inet_addr(VMF_RPC_SERVER_IP);     /* use default addr */
			NW_REM_VMF_DEBUG_PRINTF("vmf_target_tx_con_init() connect to target addr: %s\n",VMF_RPC_SERVER_IP);
	    }
	}
    else
    {
		server_addr.sin_addr.s_addr = inet_addr(VMF_RPC_SERVER_IP);         /* use default addr */
		NW_REM_VMF_DEBUG_PRINTF("vmf_target_tx_con_init() connect to target addr: %s\n",VMF_RPC_SERVER_IP);
    }
    server_addr.sin_port = htons(VMF_RPC_SERVER_PORT);
	server_addr.sin_family = AF_INET;


	/* connect to target */
	vmf_ret = vmf_target_connect(&client_tx_socket);

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
vmf_error_t vmf_target_rx_con_init(vmf_client_id_t cid)
{
	vmf_error_t vmf_ret=VMF_OK;

	NW_REM_VMF_DEBUG_PRINTF("vmf_target_rx_con_init()\n");


	/* argument check */
	if (cid >= VMF_RPC_MAX_SERVER_CONNECTIONS)
	{
		return VMF_ERR_OUT_OF_RANGE;
	}

	if (0 == client_tx_socket)
	{
		/* tx channel not connected! */
		NW_REM_VMF_DEBUG_PRINTF("vmf_target_rx_con_init() error tx channel not connected!");
		return VMF_ERROR;
	}

	/* connect to target */
	vmf_ret = vmf_target_connect(&(VMF_RPC_RX_SOCK(cid)));

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
vmf_error_t vmf_target_disconnect(vmf_client_id_t cid)
{
	vmf_error_t vmf_ret=VMF_OK;

	NW_REM_VMF_DEBUG_PRINTF("vmf_target_disconnect()\n");

	/* argument check */
	if (cid >= VMF_RPC_MAX_SERVER_CONNECTIONS)
	{
		return VMF_ERR_OUT_OF_RANGE;
	}

	/* disconnect from target */
	shutdown((VMF_RPC_RX_SOCK(cid)),SD_BOTH);

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
vmf_error_t vmf_target_call(vmf_rpc_msg_t *p_rpc_msg, vmf_rpc_response_t *p_response)
{
	vmf_ret_t			vmf_ret=VMF_OK;

	/* send rpc message to target */
//	VMF_RPC_LOCK
	vmf_ret = vmf_target_send_request(p_rpc_msg,client_tx_socket);
	if (VMF_OK == vmf_ret)
	{
		vmf_ret = vmf_target_recv_answer(p_response,client_tx_socket);
		if (VMF_OK == vmf_ret)
		{
			vmf_ret = p_response->response; 	
		}
	}
//	VMF_RPC_UNLOCK
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
vmf_error_t vmf_target_call_rx(vmf_rpc_msg_t *p_rpc_msg, vmf_rpc_response_t *p_response)
{
	vmf_ret_t			vmf_ret=VMF_OK;
	SOCKET				rx_sock;


	rx_sock = VMF_RPC_RX_SOCK(p_rpc_msg->r_cid);

	if (0 == rx_sock)
	{
		return VMF_ERR_REM_SOCK_INVALID;
	}

	/* send rpc message to target */
//	VMF_RPC_LOCK
	vmf_ret = vmf_target_send_request(p_rpc_msg,rx_sock);
	if (VMF_OK == vmf_ret)
	{
		vmf_ret = vmf_target_recv_answer(p_response,rx_sock);
		if (VMF_OK == vmf_ret)
		{
			vmf_ret = p_response->response; 	
		}
	}
//	VMF_RPC_UNLOCK
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
		NW_REM_VMF_DEBUG_PRINTF("vmf_target_send: error NULL poiner\n");
		return VMF_ERR_NULL_POINTER;
	}
	
    /* Send the rpc message */
    reslt = send( sock, (char *)p_rpc_msg, p_rpc_msg->msg_length.length, 0 );
    if (reslt == SOCKET_ERROR) 
	{
        NW_REM_VMF_DEBUG_PRINTF("send failed: %d\n", WSAGetLastError());
        closesocket(sock);
        WSACleanup();
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
		NW_REM_VMF_DEBUG_PRINTF("vmf_target_recv_answer: error NULL pointer\n");
		return VMF_ERR_NULL_POINTER;
	}

	/* read the message size */
	num_bytes = recv_wait(sock,(char*)p_response ,sizeof(p_response->msg_length),0);

	/* read remaining data */
	num_bytes = recv_wait(sock,(char*)&(p_response->rpc_id),p_response->msg_length.length - num_bytes,0);
	if (num_bytes <= 0)
	{
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
static vmf_error_t vmf_target_connect(SOCKET *p_sock)
{
	int	result= VMF_ERROR;

		NW_REM_VMF_DEBUG_PRINTF("vmf_target_connect()\n");


	if (NULL == p_sock)
	{
		NW_REM_VMF_DEBUG_PRINTF("vmf_target_connect: error NULL poiner\n");
		return VMF_ERR_NULL_POINTER;
	}

    /* Create a SOCKET for connecting to server */
    *p_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (*p_sock == INVALID_SOCKET) {
        NW_REM_VMF_DEBUG_PRINTF("Error at socket(): %ld\n", WSAGetLastError() );
        WSACleanup();
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
			NW_REM_VMF_DEBUG_PRINTF("vmf_target_connect: SIO_KEEPALIVE_VALS failed with: %d\n", dwError);
		}
	}

	/* set server address */
	#if 0
	server_addr.sin_addr.s_addr = inet_addr(VMF_RPC_SERVER_IP);
    server_addr.sin_port = htons(VMF_RPC_SERVER_PORT);
	server_addr.sin_family = AF_INET;
    #endif

	/* connect to VMF rpc server */
	result = connect( *p_sock, (SOCKADDR*) &server_addr, sizeof(server_addr) );
    if ( result == SOCKET_ERROR) {
		NW_REM_VMF_DEBUG_PRINTF("vmf_target_connect: Unable to connect to server: %d\n", WSAGetLastError());
        closesocket (*p_sock);
        WSACleanup();
		client_tx_socket = 0;
        return VMF_ERROR;
    }

	NW_REM_VMF_DEBUG_PRINTF("vmf_target_connect: connected to server\n");

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
        NW_REM_VMF_DEBUG_ERROR("bvm-VDF-CLient-Lib: nw_vmf_client_mutex_init() - pthread_mutexattr_init() failed\n");
        return(VMF_ERR_REM_MUTEX_INIT);
    }

    /* initialize mutex as a blocking mutex */
    if (0 != pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_NORMAL))
    {
        NW_REM_VMF_DEBUG_ERROR("bvm-VDF-CLient-Lib: nw_vmf_client_mutex_init() - pthread_mutexattr_settype() failed\n");
        pthread_mutexattr_destroy(&attr);
        return(VMF_ERR_REM_MUTEX_INIT);
    }

    if(pthread_mutex_init( pMutex, &attr ))
    {
        NW_REM_VMF_DEBUG_ERROR("bvm-VDF-CLient-Lib: nw_vmf_client_mutex_init() - pthread_mutex_init() failed\n");
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
static void	vmf_rem_init_rx_con_list(void)
{
	unsigned16 iCnt;
	VMF_RPC_LOCK

	/*  init the rx_con_tab */
	for (iCnt=0;iCnt<VMF_RPC_MAX_SERVER_CONNECTIONS;iCnt++)
	{
		rx_con_tab.rx_socks[iCnt]=0; 
	}
	VMF_RPC_UNLOCK
}


