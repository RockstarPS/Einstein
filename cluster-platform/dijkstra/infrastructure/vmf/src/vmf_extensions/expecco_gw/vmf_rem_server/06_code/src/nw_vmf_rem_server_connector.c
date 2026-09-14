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

  Module:               nw_vmf_rem_targett_connector.c
  Description:          connects windows vmf target with remote client

  Project Scope:        Beethoven VM platform

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   Visual Studio
  Target Hardware:      Any

  *****************************************************************************/

#include "os_types.h"
#include "nw_os_config.h"
#include "nw_vmf_debug.h"
#include "nw_vmf_rem.h"
#ifndef VMF_REM_SERVER_UNIT_TEST
#include "nw_vmf_trace.h"
#endif

#ifdef VMF_REM_SERVER_UNIT_TEST
#include "nw_vmf_rem_server_unit_test.h"
#endif

/*************** MACROS *********************/
#define VMF_RPC_LOCK     if (pthread_mutex_lock((&rpcMutex)) != 0) {NW_REM_VMF_DEBUG_ERROR("VDF-CLient-Lib: mutex Lock Failed %s line %d\n", __FILE__, __LINE__);}
#define VMF_RPC_UNLOCK   if (pthread_mutex_unlock((&rpcMutex)) != 0) {NW_REM_VMF_DEBUG_ERROR("VDF-CLient-Lib: mutex Unlock Failed %s line %d\n", __FILE__, __LINE__);}
#define VMF_RPC_INIT     if (false == bmyMutexInitialized) rpc_mutex_init(&rpcMutex);

#define BACKLOG             (20)

#ifdef VMF_REM_SERVER_UNIT_TEST
#define VMF_REM_SERV_STATIC
#else
#define VMF_REM_SERV_STATIC static
#endif

/* definitions */
#define             RX_SOCKET_THREAD_PRIORITY    (30)
#define             REM_VMF_RX_THREAD_STACK_SIZE (16384)
/* global data */
#ifdef WIN32
static WSADATA              wsaData;
#endif

static pthread_mutex_t      rpcMutex;
static SOCKET               rpc_srv_socket;             /* the server(listener) socket */
static bool                 bmyMutexInitialized=false;
static vmf_client_id_t      spy_client=0;   
	   unsigned8			vmf_trace_trid=0;
	   
/* local functions */
VMF_REM_SERV_STATIC vmf_error_t rpc_mutex_init(pthread_mutex_t *pMutex);
VMF_REM_SERV_STATIC vmf_error_t rpc_create_and_bind_server_socket(SOCKET *rpc_srv_socket);
VMF_REM_SERV_STATIC vmf_error_t vmf_client_con_listen_sock(SOCKET sock);
VMF_REM_SERV_STATIC vmf_error_t vmf_client_con_accept_sock(SOCKET *p_connectedSocket);
VMF_REM_SERV_STATIC void *vmf_client_rpc_receiver(SOCKET *rpc_socket);
VMF_REM_SERV_STATIC int recv_wait(SOCKET s,char  * buf,int len,int flags);
VMF_REM_SERV_STATIC vmf_ret_t nw_vmf_create_rx_thread  (SOCKET *p_sock);
#ifdef VMF_RPC_FKT_BLOCK_RECEIVE
VMF_REM_SERV_STATIC void vmf_client_rpc_block_receive(SOCKET *rpc_socket,vmf_rpc_msg_t   *prpc_buffer);
#endif



/*************************************************************************//**
 *
 *   vmf client connector init \n
 *   NOTE: 
 *   
 *
 *   \param[in] pmsg     -- pointer to a gw message
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
vmf_error_t vmf_client_con_init(void)
{
    int result;
    vmf_error_t vmf_ret=VMF_OK;

    /* ignore broken pipe signal */
    signal( SIGPIPE, SIG_IGN );

    /* init mutex */
    vmf_ret = rpc_mutex_init(&rpcMutex);
    if (vmf_ret !=  VMF_OK)
    {
        return vmf_ret;
    }

    /* setup tcp stack */
    result = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (result != 0)
    {
        NW_REM_VMF_DEBUG_PRINTF("WSAStartup failed: %d", result);
        return VMF_ERROR;
    }

    /* bind the socket */
    vmf_ret = rpc_create_and_bind_server_socket(&rpc_srv_socket);
    return vmf_ret;
}



/*************************************************************************//**
 *
 *   create vmf server thread  \n
 *   NOTE: this thread will handle remote vmf connections
 *   
 *
 *   \param[in] void      -- void
 *   \return    vmf_ret_t 
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_create_rem_vmf_thread  (void)
{
    pthread_t       th;
    pthread_attr_t  attr;
    int             iRet;

    (void)pthread_attr_init(&attr);
    (void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );

    (void)pthread_attr_setstacklazy(&attr,PTHREAD_STACK_LAZY);
    iRet = pthread_create (&th  , &attr,(void*)&vmf_client_rpc_handler,NULL);
    (void)pthread_attr_destroy(&attr);
    if (EOK != iRet)
    {
        NW_REM_VMF_DEBUG_ERROR("rem_vmf: nw_vmf_create_rx_thread() - pthread_create() failed: %d", iRet);
        return VMF_ERROR;
    }

    #if (_NTO_VERSION >= 632)
    /* name the thread nw vmf-spy thread */
    if ( pthread_setname_np(th, "remote_vmf svr") != EOK)
    {
        NW_VMF_DEBUG_ERROR("Unable to name nw remote_vmf thread!\n");
    }
    #endif


    return VMF_OK;
}



/*************************************************************************//**
 *
 *   vmf client rpc handler \n
 *   NOTE: this function will never return
 *   
 *
 *   \param[in] pmsg     -- pointer to a gw message
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
void *vmf_client_rpc_handler(void *pArg)
{
    vmf_error_t vmf_ret=VMF_OK;
    SOCKET      rpc_connected_socket;

#ifdef VMF_TRACE
	while (VMF_OK != vmf_trace_register(&vmf_trace_trid,"vmf"))	
    {
		delay(1);	/* wait some time and retry*/
    }

    VMF_TRACE_PRINT(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","vmf_client_rpc_handler","connected to vmf_trace server");

#endif

    /* init all client connections */
    vmf_ret = vmf_client_con_init();
    if (VMF_OK != vmf_ret)
    {
        NW_REM_VMF_DEBUG_ERROR("rem_vmf: vmf_client_con_init() failed - exit process");
        return(NULL);
    }


    /* start listener at the server socket */
    vmf_ret = vmf_client_con_listen_sock(rpc_srv_socket);
    if (VMF_OK != vmf_ret)
    {
        NW_REM_VMF_DEBUG_ERROR("rem_vmf: vmf_client_rpc_handler() - vmf_client_con_listen_sock() failed");
        return(NULL);
    }

    while(VMF_OK==vmf_ret)
    {
        /* wait for new connection */
        vmf_ret = vmf_client_con_accept_sock(&rpc_connected_socket);
        if (VMF_OK == vmf_ret)
        {
            /* crerate new receiver thread */
            vmf_ret = nw_vmf_create_rx_thread(&rpc_connected_socket);

            #ifdef VMF_REM_SERVER_UNIT_TEST
            /* to break the while loop */
            if (vmf_ret == VMF_OK)
            {
                vmf_ret = VMF_ERROR;
            }
            #endif
                
            if (vmf_ret != VMF_OK)
            {
                NW_REM_VMF_DEBUG_ERROR("rem_vmf: vmf_client_rpc_handler() - nw_vmf_create_rx_thread() failed");
                delay(10);  
            }
        }
        delay(100);
    }
    
    NW_REM_VMF_DEBUG_ERROR("rem_vmf: vmf_client_rpc_handler() - committing suicide because of severe error");
    return(NULL);
}






/******************************************************************************
 *      local functions
 ******************************************************************************/




/*************************************************************************//**
 *
 *   listen on client port and handle rpc messages \n
 *   NOTE: 
 *   
 *
 *   \param[in] void     
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t vmf_client_con_listen_sock(SOCKET sock)
{
    int rc;

    /* listen on socket */
    rc=listen(sock,BACKLOG);
    if(SOCKET_ERROR==rc)
    {
        NW_REM_VMF_DEBUG_ERROR("rem_vmf: vmf_client_con_listen_sock() - listen(), failed with %d",WSAGetLastError());
#if 0
        perror("listen");
#endif
        return VMF_ERROR;
    }

    return VMF_OK;
}



/*************************************************************************//**
 *
 *   listen on client port and handle rpc messages \n
 *   NOTE: 
 *   
 *
 *   \param[in] void     
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t vmf_client_con_accept_sock(SOCKET *p_connectedSocket)
{
    vmf_error_t vmf_ret=VMF_ERROR;

    NW_REM_VMF_DEBUG_INFO("rem_vmf: vmf_client_con_listen_sock() - wait for new connection");

    /* wait to accept a connection - this function is blocking */
    *p_connectedSocket=accept(rpc_srv_socket,NULL,NULL);
    if(INVALID_SOCKET == *p_connectedSocket)
    {
        NW_REM_VMF_DEBUG_ERROR("rem_vmf: vmf_client_con_listen_sock() - error: accept, error code: %d",WSAGetLastError());
        return vmf_ret;
    }

    NW_REM_VMF_DEBUG_INFO("rem_vmf: vmf_client_con_listen_sock() - new connection");

    return VMF_OK;
}





/*************************************************************************//**
 *
 *   receive rpc messages from a remote client \n
 *   NOTE: this thread will kill itself if the tcp connection was lost
 *   
 *
 *   \param[in] void     
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC void *vmf_client_rpc_receiver(SOCKET *rpc_socket)
{
    vmf_error_t     vmf_ret=VMF_ERROR;
    vmf_rpc_msg_t   rpc_buffer;
    unsigned16      tx_buffer_len=0;
    int result;
    
    /* we have here some KB on the stack !*/
    unsigned32          my_resp_buffer[((sizeof(VMF_VAR_MSG_TYP(VMF_REM_MAX_DATA_SIZE))+sizeof(vmf_rpc_response_t))/sizeof(unsigned32))+1];
    vmf_rpc_response_t* p_rpc_response = (vmf_rpc_response_t*)&my_resp_buffer;
    int                 num_bytes;
    SOCKET              my_sock;
    vmf_client_id_t     my_client_id=-1;

    NW_REM_VMF_DEBUG_INFO("rem_vmf: vmf_client_rpc_receiver() - new receiver thread started for socket=%x",*rpc_socket);
    /* cop the socket */
    my_sock = *rpc_socket;
    *rpc_socket = 0;        /* signal that this thread is running */

    /* receive rpc messages */
    while (true)
    {

        /* receive msg length */
        num_bytes = recv_wait(my_sock, (char *)&rpc_buffer, sizeof(rpc_buffer.msg_length), 0);
        if (num_bytes > 0)
        {
            /* receive remainig msg */
            num_bytes = recv_wait(my_sock, (char *)&(rpc_buffer.rpc_id) , rpc_buffer.msg_length.length-num_bytes,0);
            if (num_bytes > 0)
            {
                
                
                /* decode message and call rpc function */
                vmf_ret = vmf_client_rpc_decoder(&rpc_buffer,p_rpc_response,0);
                if (VMF_ERR_INVALID_RPC_ID == vmf_ret)
                {
                    /* received an invalid rpc ID */
                    NW_REM_VMF_DEBUG_INFO("rem_vmf: vmf_client_rpc_receiver() - invalid rpc-ID");
                }

                tx_buffer_len=p_rpc_response->msg_length.length;
                
                /* send result back to remote client */
                result = send( my_sock, (char *) p_rpc_response,tx_buffer_len, 0 );
                if (result == SOCKET_ERROR) 
                {
                    /* there was a send error */
                    /* most likely the connection was closed by the client */
                    NW_REM_VMF_DEBUG_INFO("rem_vmf: vmf_client_rpc_receiver() - send() failed");
                    vmf_ret = VMF_ERROR;
                    break;
                }

                if (VMF_RPC_FKT_CONNECT == rpc_buffer.rpc_id)
                {
                    /* if this was a vmf connect then store the client id */
                    my_client_id = p_rpc_response->response;
                } 
                else if (VMF_RPC_FKT_REGISTER_SPY == rpc_buffer.rpc_id)
                {
                    /* store spy cid */
                    spy_client = rpc_buffer.r_cid;              
                } 
                #ifdef VMF_RPC_FKT_BLOCK_RECEIVE
                else if (VMF_RPC_FKT_BLOCK_RECEIVE == rpc_buffer.rpc_id)
                {
                    /* do a block receive */ 
                    /* this function will only return if there was an error */
                    /* and the tcp connection has to be closed              */
                    vmf_client_rpc_block_receive(rpc_socket,&rpc_buffer);
                    break;
                }               
                #endif
                else
                {
                    /* nothing */
                }               
            }       
        } /* end of: num_bytes > 0 */
        else
        {
            /* there was a receive error */
            /* most likely the connection was closed by the client */
            vmf_ret = VMF_ERROR;
            NW_REM_VMF_DEBUG_INFO("rem_vmf: vmf_client_rpc_receiver() recv failed: %d", WSAGetLastError());
            break;
        }
        
        #ifdef VMF_REM_SERVER_UNIT_TEST
        break;
        #endif
        
    }
    closesocket(my_sock);

    /* close the message channel */
    if (my_client_id > 0)
    {
        (void)nw_vmf_disconnect(my_client_id);
    }
    NW_REM_VMF_DEBUG_INFO("vmf_client_rpc_receiver() socket closed");
    return NULL;
}



/*************************************************************************//**
 *
 *   endless receive for VMF_RPC_FKT_BLOCK_RECEIVE \n
 *   NOTE: 
 *   will only return in the case of a tcp error
 *
 *   \param[in] void     
 *   \return    void 
 *
 ******************************************************************************/
#ifdef VMF_RPC_FKT_BLOCK_RECEIVE
VMF_REM_SERV_STATIC void vmf_client_rpc_block_receive(SOCKET *rpc_socket,vmf_rpc_msg_t   *prpc_buffer)
{
    vmf_error_t         vmf_ret=VMF_ERROR;
    bool                do_break=false;
    bool                do_send=false;
    int                 result;
    unsigned16          tx_data_len=0;
    unsigned32          tx_time;
    unsigned32          current_time;
    signed32            time_left;
    SOCKET              my_sock;

    /* cop the socket */
    my_sock = *rpc_socket;
    *rpc_socket = 0;        /* signal that this thread is running */        

    /* we have here some KB on the stack !*/
    unsigned32          my_resp_buffer[((sizeof(VMF_VAR_MSG_TYP(VMF_REM_MAX_DATA_SIZE))+sizeof(vmf_rpc_response_t))/sizeof(unsigned32))+1];
    vmf_rpc_response_t* p_rpc_response = (vmf_rpc_response_t*)&my_resp_buffer;
    unsigned32          my_resp_buffer_2[((sizeof(VMF_VAR_MSG_TYP(VMF_REM_MAX_DATA_SIZE))+sizeof(vmf_rpc_response_t))/sizeof(unsigned32))+1];
    vmf_rpc_response_t* p_rpc_response_2 = (vmf_rpc_response_t*)&my_resp_buffer_2;

    
    time_left = VMF_REM_SPY_COLL_TIMEOUT;
    tx_time   =  vmf_rem_get_time_in_ms(ClockCycles());

    /* overload rpc receive with VMF_RPC_FKT_TIMED_RECEIVE */
    prpc_buffer->rpc_id = VMF_RPC_FKT_TIMED_RECEIVE;
    while (do_break == false)
    {
        /* decode message and call rpc function */
        vmf_ret = vmf_client_rpc_decoder(prpc_buffer,p_rpc_response_2,time_left);
        if (vmf_ret > 0)
        {
            /* we received data */
            current_time = vmf_rem_get_time_in_ms(ClockCycles());
            time_left = VMF_REM_SPY_COLL_TIMEOUT - (current_time - tx_time);
            
            /* add data to tx buffer */
            /* check if data will fit into the tx buffer */
            if ((p_rpc_response_2->msg_length.length + tx_data_len) >= VMF_REM_MAX_DATA_SIZE)
            {
                /* there is a problem  - data will not fit into the tx buffer */
                /* so send the old data directly and store the new data       */
                /* this should never happen                                   */
                NW_REM_VMF_DEBUG_INFO("rem_vmf: vmf_client_rpc_block_receive() msg collector - data will not fit into tx buffer!");

                /* send  collected rx data back to remote client */
                result = send( my_sock, (char *) p_rpc_response,tx_data_len, 0 );
                if (result == SOCKET_ERROR) 
                {
                    /* there was a tx error */
                    /* most likely the connection was closed by the client */
                    NW_REM_VMF_DEBUG_INFO("rem_vmf: vmf_client_rpc_block_receive() - send() failed 1");
                    vmf_ret  = VMF_ERROR;
                    do_break =true;
                    break;
                }
                do_send    = false;
                tx_time    = current_time;
                tx_data_len= 0;
            }

            /* add data to tx buffer */
            memcpy((&((char *)p_rpc_response)[tx_data_len]),p_rpc_response_2,p_rpc_response_2->msg_length.length);
            tx_data_len += p_rpc_response_2->msg_length.length;

            /* check if we have to send the data */
            /* check for timeout */
            if (time_left < 0)
            {
                do_send=true;
            }

            /* check if buffer limit reached */
            if (tx_data_len >= WMF_REN_SPY_COLLECTOR_LEN)
            {
                /* stop the collection of data */
                do_send=true;
            }
            
            if (true==do_send)
            {
                /* send  collected rx data back to remote client */
                result = send( my_sock, (char *) p_rpc_response,tx_data_len, 0 );
                if (result == SOCKET_ERROR) 
                {
                    /* there was a tx error */
                    /* most likely the connection was closed by the client */
                    NW_REM_VMF_DEBUG_INFO("rem_vmf: vmf_client_rpc_block_receive() - send() failed 2");
                    vmf_ret = VMF_ERROR;
                    do_break=true;
                    break;
                }
                do_send    = false;
                tx_time    = current_time;
                tx_data_len= 0;
            }

        } /* end of: if (vmf_ret > 0)*/
        else
        {
            /* VMF_RPC_FKT_TIMED_RECEIVE reported an error (timeout) */
            /* ignore the error by now */
            (void)delay(10);
        }
    } /* end of: while */
}
#endif /* VMF_RPC_FKT_BLOCK_RECEIVE */


/*************************************************************************//**
 *
 *   init the rpc mutex\n
 *   NOTE: 
 *   
 *
 *   \param[in] *pthread_mutex_t     -- pointer to  mutex
 *   \return    vmf_error_t 
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t rpc_mutex_init(pthread_mutex_t *pMutex) /**< INPUT/OUTPUT pointer to a mutex*/
{
    vmf_error_t vmf_ret=VMF_OK;
    pthread_mutexattr_t attr;
    
    if (bmyMutexInitialized != false)
    {
        /* mutex already created */
        return vmf_ret;
    }

    if (EOK != pthread_mutexattr_init(&attr))
    {
        NW_REM_VMF_DEBUG_ERROR("rem_vmf: nw_vmf_client_mutex_init() - pthread_mutexattr_init() failed");
        return(VMF_ERROR);
    }

    /* initialize mutex as a blocking mutex */
    if (0 != pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_NORMAL))
    {
        NW_REM_VMF_DEBUG_ERROR("rem_vmf: nw_vmf_client_mutex_init() - pthread_mutexattr_settype() failed");
        (void)pthread_mutexattr_destroy(&attr);
        return(VMF_ERROR);
    }

    if(EOK != pthread_mutex_init( pMutex, &attr ))
    {
        NW_REM_VMF_DEBUG_ERROR("rem_vmf: nw_vmf_client_mutex_init() - pthread_mutex_init() failed");
        (void)pthread_mutexattr_destroy(&attr);
        return(VMF_ERROR);
    }
    
    (void)pthread_mutexattr_destroy(&attr);
    bmyMutexInitialized = true;

  return(vmf_ret);
}




/*************************************************************************//**
 *
 *   create the rpc server socket and bind it to port VMF_RPC_SERVER_PORT \n
 *   NOTE:
 *
 *
 *   \param[in] *SOCKET  -- pointer to the rpc rx socket
 *   \return    vmf_error_t
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_error_t rpc_create_and_bind_server_socket(SOCKET *p_rpc_srv_socket) /**< INPUT/OUTPUT pointer to a mutex*/
{
    #ifndef VMF_REM_SERVER_UNIT_TEST
    #define WAIT_4_SOCKET   500         /* time in ms/10 */
    #define WAIT_MORE_4_SOCKET  0xffff  /* time in ms/500 */
    #endif
    vmf_error_t vmf_ret=VMF_ERROR;
    SOCKADDR_IN addr;                   /* sockaddr object */
    unsigned16      cnt;

    /* wait some time to connect the socket */
    for (cnt=0;cnt<WAIT_MORE_4_SOCKET;cnt++)
    {
        *p_rpc_srv_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (*p_rpc_srv_socket == INVALID_SOCKET)
        {
            if (cnt < WAIT_4_SOCKET)
            {
                delay(10);
            }
            else
            {
                delay(500);
            }
            continue;
        }
        break;
    }
    
    if (*p_rpc_srv_socket == INVALID_SOCKET)
    {
        NW_REM_VMF_DEBUG_ERROR("rem_vmf: rpc_create_and_bind_server_socket() - Error at socket(): %d", WSAGetLastError());
        WSACleanup();
        return vmf_ret;
    }

    // AF_INET is the Internet address family.
    addr.sin_family = AF_INET;

    // set local host
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    //bind to port number
    addr.sin_port = htons(VMF_RPC_SERVER_PORT);

    /* bind the socket */
    if (bind(*p_rpc_srv_socket, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR)
    {
        NW_REM_VMF_DEBUG_ERROR("rem_vmf: rpc_create_and_bind_server_socket() - bind() failed: %d", WSAGetLastError());
#if 0
        perror("bind");
#endif
        vmf_ret=VMF_ERR_REM_SERVER_BIND_ERROR;
        closesocket(*p_rpc_srv_socket);
        return vmf_ret;
    }

    return VMF_OK;
}


/*************************************************************************//**
 *
 *   receives data on a socket till all data is received  \n
 *   NOTE: done because MSG_WAITALL is not supported on Windows
 *   
 *
 *   \param[in] SOCKET   -- socket
 *   \param[in] buf      -- buffer for rx data
 *   \param[in] len      -- buffer len
 *   \param[in] flags    -- rx flags
 *   \return    number of bytes or 0 or -1 
 *
 ******************************************************************************/
int recv_wait(SOCKET s,char  * buf,int len,int flags)
{
    int num_bytes;
    unsigned16  all_bytes=0;

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
#if 0
NW_REM_VMF_DEBUG_INFO("rem_vmf: recv_wait - receive %d bytes",all_bytes);
#endif
    return all_bytes;
}




/*************************************************************************//**
 *
 *   create socket receiver thread  \n
 *   NOTE: this thread will kill itseld if socket connection is closed
 *   
 *
 *   \param[in] SOCKET   -- socket
 *   \return    vmf_ret_t 
 *
 ******************************************************************************/
VMF_REM_SERV_STATIC vmf_ret_t nw_vmf_create_rx_thread  (SOCKET *p_sock)
{
    pthread_t       th;
    pthread_attr_t  attr;
    int             iRet;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );

#ifdef VMF_TRACE
    vmf_trace_printf(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","nw_vmf_create_rx_thread","");
#endif

    pthread_attr_setstacklazy(&attr,PTHREAD_STACK_LAZY);
    pthread_attr_setstacksize (&attr, REM_VMF_RX_THREAD_STACK_SIZE);
    iRet = pthread_create (&th  , &attr,(void*)&vmf_client_rpc_receiver,p_sock);
    pthread_attr_destroy(&attr);
    if (EOK != iRet)
    {
#ifdef VMF_TRACE
	    vmf_trace_printf(vmf_trace_trid,VMF_TRACE_SEVERITY_INFO_10,"vmf_rem","nw_vmf_create_rx_thread"," pthread_create() failed: %d",iRet);
#else
		NW_REM_VMF_DEBUG_ERROR("rem_vmf: nw_vmf_create_rx_thread() - pthread_create() failed: %d", iRet);
#endif
        return VMF_ERROR;
    }


    #if (_NTO_VERSION >= 632)
    /* name the thread nw vmf-spy thread */
    if ( pthread_setname_np(th, "remote_vmf rx") != EOK)
    {
        NW_REM_VMF_DEBUG_ERROR("Unable to name nw remote_vmf rx thread!\n");
    }
    #endif


    /* wait till thread is up and running */
    #ifndef VMF_REM_SERVER_UNIT_TEST
    while (0 != (*p_sock))
    {
        delay(2);       /* wait some time */
    }
    #endif

    return VMF_OK;
}




