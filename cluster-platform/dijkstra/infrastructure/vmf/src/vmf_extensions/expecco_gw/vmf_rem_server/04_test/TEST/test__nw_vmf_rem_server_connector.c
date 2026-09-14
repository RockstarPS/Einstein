#include "nw_vmf_rem_server_unit_test.h"
#include "stdlib.h"

/* macros */

#include "nw_vmf_rem_server_unit_test.h"
#include "stdlib.h"

bool test_vmf_client_con_init(void)
{
    vmf_error_t result;

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_LIMITER
    UNIT_TEST_INFO_PRINT("test_vmf_client_con_init:\n");

    UNIT_TEST_INFO_PRINT("rpc_mutex_init - shall fail\n");
    set_pthread_mutexattr_init(NOT_EOK);
    result = vmf_client_con_init();
    if(VMF_OK == result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d\n",(int)result);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc_mutex_init - has failed\n");

    UNIT_TEST_INFO_PRINT("rpc_mutex_init - shall pass\n");
    set_pthread_mutexattr_init(EOK);
    set_wsastartupresult(0xFF);
    UNIT_TEST_INFO_PRINT("WSAStartup - shall fail\n");

    result = vmf_client_con_init();
    if(VMF_OK == result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d\n",(int)result);
        return true;
    }
    UNIT_TEST_INFO_PRINT("WSAStartup - has failed\n");

    set_wsastartupresult(0);
    UNIT_TEST_INFO_PRINT("WSAStartup - shall pass\n");

    result = vmf_client_con_init();
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d\n",(int)result);
        return true;
    }
    UNIT_TEST_INFO_PRINT("WSAStartup - has passed\n");

    UNIT_TEST_INFO_PRINT("ALL OK\n");
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    return true;
}

bool test_vmf_create_rem_vmf_thread(void)
{
    vmf_error_t result;

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_LIMITER
    UNIT_TEST_INFO_PRINT("test_vmf_create_rem_vmf_thread:\n");

    UNIT_TEST_INFO_PRINT("pthread_create - shall fail\n");
    set_pthread_create(NOT_EOK);
    result = nw_vmf_create_rem_vmf_thread();
    if(VMF_OK == result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d\n",(int)result);
        return true;
    }
    UNIT_TEST_INFO_PRINT("pthread_create - FAILED\n");

    UNIT_TEST_INFO_PRINT("pthread_create - shall pass\n");
    set_pthread_create(EOK);
    result = nw_vmf_create_rem_vmf_thread();
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d\n",(int)result);
        return true;
    }
    UNIT_TEST_INFO_PRINT("pthread_create - PASSED\n");
    UNIT_TEST_INFO_PRINT("ALL OK\n");
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");

    return true;
}


extern bool test_vmf_client_rpc_handler(void)
{
    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_LIMITER
    UNIT_TEST_INFO_PRINT("test_vmf_client_rpc_handler:\n");

    set_wsastartupresult(-1);
    UNIT_TEST_INFO_PRINT("vmf_client_con_init - shall fail\n");
    vmf_client_rpc_handler(NULL);
    set_wsastartupresult(0);
    UNIT_TEST_INFO_PRINT("vmf_client_con_init - shall pass\n");
    set_result_listen(SOCKET_ERROR);
    UNIT_TEST_INFO_PRINT("vmf_client_con_listen_sock - shall fail\n");
    vmf_client_rpc_handler(NULL);
    set_result_listen(0);
    UNIT_TEST_INFO_PRINT("vmf_client_con_listen_sock - shall pass\n");
    vmf_client_rpc_handler(NULL);


    UNIT_TEST_INFO_PRINT("ALL OK\n");
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");


    return true;
}

bool test_vmf_client_con_accept_sock(void)
{
    vmf_error_t result;
    SOCKET *p_connectedSocket;
    SOCKET connectedSocket;
    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_LIMITER
    UNIT_TEST_INFO_PRINT("test_vmf_client_con_accept_sock:\n");

    p_connectedSocket = &connectedSocket;


    UNIT_TEST_INFO_PRINT("accept - shall fail\n");
    set_accept_result(INVALID_SOCKET);
    vmf_client_con_accept_sock(p_connectedSocket);

    UNIT_TEST_INFO_PRINT("accept - shall pass\n");
    set_accept_result(0);
    vmf_client_con_accept_sock(p_connectedSocket);


    UNIT_TEST_INFO_PRINT("ALL OK\n");
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");


    return true;
}

bool test_vmf_client_rpc_receiver(void)
{
    vmf_error_t result;
    SOCKET *p_connectedSocket;
    SOCKET connectedSocket;   
    
   /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_LIMITER
    UNIT_TEST_INFO_PRINT("test_vmf_client_rpc_receiver:\n");

    p_connectedSocket = &connectedSocket;
    
    UNIT_TEST_INFO_PRINT("recv_wait - shall return 0\n");
    set_result_recv(0);
    vmf_client_rpc_receiver(p_connectedSocket);

    UNIT_TEST_INFO_PRINT("recv_wait - shall return 10\n");
    set_result_recv(10);
    UNIT_TEST_INFO_PRINT("send - shall fail\n");
    set_send_result(SOCKET_ERROR);
    vmf_client_rpc_receiver(p_connectedSocket);    
    
    UNIT_TEST_INFO_PRINT("send - shall pass\n");
    set_send_result(0);    
    
    UNIT_TEST_INFO_PRINT("ALL OK\n");
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");


    return true;
}

bool test_rpc_mutex_init(void)
{
    vmf_error_t result;
    pthread_mutex_t my_mutex;
    pthread_mutex_t *pMutex;
    
   /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_LIMITER
    UNIT_TEST_INFO_PRINT("test_rpc_mutex_init:\n");
    
    pMutex = &my_mutex;    
    
    UNIT_TEST_INFO_PRINT("pthread_mutexattr_init - shall fail\n");
    set_pthread_mutexattr_init(NOT_EOK);
    rpc_mutex_init(pMutex);
    
    UNIT_TEST_INFO_PRINT("pthread_mutexattr_init - shall pass\n");
    set_pthread_mutexattr_init(EOK);
    UNIT_TEST_INFO_PRINT("pthread_mutexattr_settype - shall fail\n");
    set_pthread_mutexattr_settype(1);
    rpc_mutex_init(pMutex);    

    UNIT_TEST_INFO_PRINT("pthread_mutexattr_settype - shall pass\n");
    set_pthread_mutexattr_settype(0);
    UNIT_TEST_INFO_PRINT("pthread_mutex_init - shall fail\n");
    set_pthread_mutex_init(NOT_EOK);
    rpc_mutex_init(pMutex);        
    
    UNIT_TEST_INFO_PRINT("pthread_mutex_init - shall pass\n");
    set_pthread_mutex_init(EOK);
    rpc_mutex_init(pMutex);            
    
    UNIT_TEST_INFO_PRINT("ALL OK\n");
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");


    return true;    
}

bool test_rpc_create_and_bind_server_socket(void)
{
    SOCKET *p_socket;
    SOCKET my_socket;
   /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_LIMITER
    UNIT_TEST_INFO_PRINT("test_rpc_create_and_bind_server_socket:\n");
    
    p_socket = &my_socket;    
    
    UNIT_TEST_INFO_PRINT("socket - shall fail\n");
    set_socket(INVALID_SOCKET);
    rpc_create_and_bind_server_socket(p_socket);
    
    UNIT_TEST_INFO_PRINT("socket - shall pass\n");
    set_socket(0);
    rpc_create_and_bind_server_socket(p_socket);
    
    UNIT_TEST_INFO_PRINT("ALL OK\n");
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");


    return true;        
}

bool test_vmf_create_rx_thread(void)
{
    SOCKET *p_socket;
    SOCKET my_socket;
   /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_LIMITER
    UNIT_TEST_INFO_PRINT("test_rpc_create_and_bind_server_socket:\n");
    
    my_socket = 0;
    p_socket = &my_socket;    
    
    UNIT_TEST_INFO_PRINT("pthread_create - shall fail\n");
    set_pthread_create(NOT_EOK);
    nw_vmf_create_rx_thread(p_socket);

    UNIT_TEST_INFO_PRINT("pthread_create - shall pass\n");
    set_pthread_create(EOK);
    nw_vmf_create_rx_thread(p_socket);    
    
    
    UNIT_TEST_INFO_PRINT("ALL OK\n");
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");


    return true;        
}
