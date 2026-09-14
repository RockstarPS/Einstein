#include "nw_vmf_rem_server_unit_test.h"
#include "stdlib.h"

/* macros */

#include "nw_vmf_rem_server_unit_test.h"
#include "stdlib.h"

bool test_vmf_client_rpc_decoder(void)
{
    vmf_error_t result;
    unsigned16 timeout;

    vmf_rpc_msg_t *ptr_buffer;
    vmf_rpc_msg_t  buffer;
    
    unsigned32 resp_buffer[((sizeof(VMF_VAR_MSG_TYP(VMF_REM_MAX_DATA_SIZE))+sizeof(vmf_rpc_response_t))/sizeof(unsigned32))+1];
    vmf_rpc_response_t* response = (vmf_rpc_response_t*)&resp_buffer;

    buffer.r_cid = 70;

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_LIMITER
    UNIT_TEST_INFO_PRINT("test_vmf_client_rpc_decoder: NULL pointer check\n");

    response = NULL;
    ptr_buffer = &buffer;
    timeout = 22;
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERR_NULL_POINTER != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 set to NULL, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }


    response = (vmf_rpc_response_t*)&resp_buffer;
    ptr_buffer = NULL;
    timeout = 22;
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERR_NULL_POINTER != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param1 set to NULL, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }


    UNIT_TEST_INFO_PRINT("NULL pointer check: ALL OK\n");

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_LIMITER
    UNIT_TEST_INFO_PRINT("test_vmf_client_rpc_decoder: rpc id check\n");

    response = (vmf_rpc_response_t*)&resp_buffer;
    ptr_buffer = &buffer;
    timeout = 33;
    /*---------------------------------------------------------------------------------------------------------------*/
    ptr_buffer->rpc_id = VMF_RPC_FKT_CONNECT;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_CONNECT: to fail\n");
    set_nw_vmf_connect_result(-1);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERROR != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_CONNECT: result = has failed\n");
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_CONNECT: to pass\n");
    set_nw_vmf_connect_result(1);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(result <= 0)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_CONNECT: result = has passed\n");

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    ptr_buffer->rpc_id = VMF_RPC_FKT_CONNECT_ASYNC;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_CONNECT_ASYNC: to fail\n");
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERR_NOT_SUPPORTED != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_CONNECT_ASYNC: result = has failed\n");

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    ptr_buffer->rpc_id = VMF_RPC_FKT_REGISTER_EXT_MOST_LINK;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_EXT_MOST_LINK: to fail\n");
    set_nw_vmf_register_ext_most_link_result(VMF_ERROR);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERROR != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_EXT_MOST_LINK: result = has failed\n");

    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_EXT_MOST_LINK: to pass\n");
    set_nw_vmf_register_ext_most_link_result(VMF_OK);    
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_EXT_MOST_LINK: has passed\n");
    
    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    ptr_buffer->rpc_id = VMF_RPC_FKT_REGISTER_SPY;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_SPY: to fail\n");
    set_nw_vmf_register_spy_result(VMF_ERROR);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERROR != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_SPY: has failed\n");
    
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_SPY: to pass\n");
    set_nw_vmf_register_spy_result(VMF_OK);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_SPY: has passed\n");

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    ptr_buffer->rpc_id = VMF_RPC_FKT_REGISTER_MOST_FB;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_MOST_FB: to fail\n");
    set_nw_vmf_register_most_fblock_result(VMF_ERROR);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERROR != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_MOST_FB: has failed\n");
    
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_MOST_FB: to pass\n");
    set_nw_vmf_register_most_fblock_result(VMF_OK);    
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_MOST_FB: has passed\n");
    
    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    ptr_buffer->rpc_id = VMF_RPC_FKT_DEREGISTER_MOST_FB;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_DEREGISTER_MOST_FB: to fail\n");
    set_nw_vmf_de_register_most_fblock_result(VMF_ERROR);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERROR != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_DEREGISTER_MOST_FB: has failed\n");

    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_DEREGISTER_MOST_FB: to pass\n");
    set_nw_vmf_de_register_most_fblock_result(VMF_OK);    
    
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_DEREGISTER_MOST_FB: has passed\n");
    
    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    ptr_buffer->rpc_id = VMF_RPC_FKT_REGISTER_MOST_SHAD;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_MOST_SHAD: to fail\n");
    set_nw_vmf_register_most_shadow(VMF_ERROR);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERROR != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_MOST_SHAD: result = has failed\n");

    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_MOST_SHAD: to pass\n");
    set_nw_vmf_register_most_shadow(VMF_OK);    
    
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_MOST_SHAD: result = has passed\n");    

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    ptr_buffer->rpc_id = VMF_RPC_FKT_DEREGISTER_MOST_SHAD;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_DEREGISTER_MOST_SHAD: to fail\n");
    set_nw_vmf_de_register_most_shadow_result(VMF_ERROR);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERROR != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_DEREGISTER_MOST_SHAD: result = has failed\n");
    
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_DEREGISTER_MOST_SHAD: to pass\n");    
    set_nw_vmf_de_register_most_shadow_result(VMF_OK);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_DEREGISTER_MOST_SHAD: result = has passed\n");

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    ptr_buffer->rpc_id = VMF_RPC_FKT_REGISTER_MSG_GRP;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_MSG_GRP: to fail\n");
    set_nw_vmf_register_msg_group(VMF_ERROR);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERROR != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_MSG_GRP: result = has failed\n");

    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_MSG_GRP: to pass\n");
    set_nw_vmf_register_msg_group(VMF_OK);        
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_REGISTER_MSG_GRP: result = has passed\n");    

    
    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    ptr_buffer->rpc_id = VMF_RPC_FKT_DEREGISTER_MSG_GRP;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_DEREGISTER_MSG_GRP: to fail\n");
    set_nw_vmf_de_register_msg_group_result(VMF_ERROR);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERROR != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_DEREGISTER_MSG_GRP: result = has failed\n");
    
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_DEREGISTER_MSG_GRP: to pass\n");
    set_nw_vmf_de_register_msg_group_result(VMF_OK);    
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_DEREGISTER_MSG_GRP: result = has passed\n");

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    ptr_buffer->rpc_id = VMF_RPC_FKT_SEND_MOST_ASYNC;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_SEND_MOST_ASYNC: to fail\n");
    set_nw_vmf_send_most_async_result(VMF_ERROR);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERROR != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_SEND_MOST_ASYNC: result = has failed\n");

    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_SEND_MOST_ASYNC: to pass\n");
    set_nw_vmf_send_most_async_result(VMF_OK);    
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_SEND_MOST_ASYNC: result = has passed\n");    

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    ptr_buffer->rpc_id = VMF_RPC_FKT_SEND_MOST_CTRL;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_SEND_MOST_CTRL: to fail\n");
    set_nw_vmf_send_most_ctrl_result(VMF_ERROR);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERROR != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_SEND_MOST_CTRL: result = has failed\n");

    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_SEND_MOST_CTRL: to pass\n");
    set_nw_vmf_send_most_ctrl_result(VMF_OK);    
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_SEND_MOST_CTRL: result = has passed\n");    

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    ptr_buffer->rpc_id = VMF_RPC_FKT_SEND_BASIC;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_SEND_BASIC: to fail\n");
    set_nw_vmf_send_basic(VMF_ERROR);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERROR != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_SEND_BASIC: result = has failed\n");

    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_SEND_BASIC: to pass\n");
    set_nw_vmf_send_basic(VMF_OK);    
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_SEND_BASIC: result = has passed\n");

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    ptr_buffer->rpc_id = VMF_RPC_FKT_SEND;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_SEND: to fail\n");
    set_nw_vmf_send_result(VMF_ERROR);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERROR != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_SEND: result = has failed\n");    

    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_SEND: to pass\n");
    set_nw_vmf_send_result(VMF_OK);    
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_SEND: result = has passed\n");    

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    ptr_buffer->rpc_id = VMF_RPC_FKT_RECEIVE;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_RECEIVE: to fail\n");
    set_nw_vmf_receive_result(-1);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERROR != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_RECEIVE: result = has failed\n");
    
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_RECEIVE: to pass\n");
    set_nw_vmf_receive_result(1);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(result <= 0)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }    
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_RECEIVE: result = has passed\n");

        /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    ptr_buffer->rpc_id = VMF_RPC_FKT_DISCONNECT;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_DISCONNECT: to fail\n");
    set_nw_vmf_disconnect(VMF_ERROR);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERROR != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_DISCONNECT: result = has failed\n");
    
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_DISCONNECT: to pass\n");
    set_nw_vmf_disconnect(VMF_OK);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_DISCONNECT: result = has passed\n");    

     /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    ptr_buffer->rpc_id = VMF_RPC_FKT_TIMED_RECEIVE;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_TIMED_RECEIVE: to fail\n");
    set_nw_vmf_timed_receive_result(-1);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(0 < result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_TIMED_RECEIVE: result = has failed\n");

    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_TIMED_RECEIVE: to pass\n");    
    set_nw_vmf_timed_receive_result(1);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(result <= 0)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_TIMED_RECEIVE: result = has passed\n");

    /*---------------------------------------------------------------------------------------------------------------*/
    #ifdef VMF_RPC_FKT_BLOCK_RECEIVE
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    ptr_buffer->rpc_id = VMF_RPC_FKT_BLOCK_RECEIVE;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_BLOCK_RECEIVE: to fail\n");
    set_nw_vmf_receive_result(0);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(0 < result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_BLOCK_RECEIVE: result = has failed\n");    

    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_BLOCK_RECEIVE: to pass\n");
    set_nw_vmf_receive_result(1);
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(result <= 0)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_RPC_FKT_BLOCK_RECEIVE: result = has passed\n");        
    #endif

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    ptr_buffer->rpc_id = VMF_ERR_INVALID_RPC_ID;
    UNIT_TEST_INFO_PRINT("rpc id check: VMF_ERR_INVALID_RPC_ID: to be: error\n");
    result = vmf_client_rpc_decoder(ptr_buffer,response,timeout);
    if(VMF_ERR_INVALID_RPC_ID != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)response, (int)ptr_buffer);
        return true;
    }

    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");
    UNIT_TEST_INFO_PRINT("rpc id check: ALL OK\n");
    
    return true;
}

bool test_vmf_rem_get_time_in_ms(void)
{
    unsigned32 result;
   /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_LIMITER
    UNIT_TEST_INFO_PRINT("test_vmf_rem_get_time_in_ms:\n");
    
    UNIT_TEST_INFO_PRINT("clocks = 10000:\n");
    
    result = vmf_rem_get_time_in_ms(10000);    
    
    UNIT_TEST_INFO_PRINT("time = %d\n",(int)result);
    
    UNIT_TEST_INFO_PRINT("ALL OK\n");
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");


    return true;    
}

bool test_vmf_client_rpc_decoder_disconnect(void)
{
    vmf_rpc_msg_t *p_rpc_msg;
    vmf_rpc_msg_t msg;
   /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_LIMITER
    UNIT_TEST_INFO_PRINT("test_vmf_client_rpc_decoder_disconnect:\n");
    
    p_rpc_msg = &msg;
    
    UNIT_TEST_INFO_PRINT("nw_vmf_disconnect - shall fail\n");
    set_nw_vmf_disconnect(VMF_ERROR);
    if(VMF_OK == vmf_client_rpc_decoder_disconnect(p_rpc_msg))
    {
        UNIT_TEST_INFO_PRINT("UNIT TEST FAILED\n");    
    }    
    
    UNIT_TEST_INFO_PRINT("nw_vmf_disconnect - shall pass\n");
    set_nw_vmf_disconnect(VMF_OK);
    if(VMF_OK != vmf_client_rpc_decoder_disconnect(p_rpc_msg))
    {
        UNIT_TEST_INFO_PRINT("UNIT TEST FAILED\n");    
    }
    
    UNIT_TEST_INFO_PRINT("ALL OK\n");
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");


    return true;        
}

bool test_vmf_client_rpc_decoder_timed_receive(void)
{
    unsigned16 timeout;
    vmf_rpc_response_t *p_response;
    vmf_rpc_response_t response;
    vmf_rpc_msg_t *p_rpc_msg;
    vmf_rpc_msg_t rpc_msg;
    
    
   /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_LIMITER
    UNIT_TEST_INFO_PRINT("test_vmf_client_rpc_decoder_timed_receive:\n");
    
    p_response = &response;
    p_rpc_msg = &rpc_msg;
    p_rpc_msg->rpc_receive.vmf_msg_length.length = 10;
    timeout = 10;
    
    UNIT_TEST_INFO_PRINT("nw_vmf_timed_receive - shall fail\n");
    if(VMF_OK == vmf_client_rpc_decoder_timed_receive(p_rpc_msg, p_response, timeout))
    {
        UNIT_TEST_INFO_PRINT("UNIT TEST FAILED\n");    
    }    
    
    UNIT_TEST_INFO_PRINT("nw_vmf_timed_receive - shall pass\n");
    if(VMF_OK != vmf_client_rpc_decoder_timed_receive(p_rpc_msg, p_response, timeout))
    {
        UNIT_TEST_INFO_PRINT("UNIT TEST FAILED\n");    
    }
    
    UNIT_TEST_INFO_PRINT("ALL OK\n");
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");


    return true;            
}


bool test_vmf_client_rpc_decoder_receive(void)
{
    vmf_rpc_response_t *p_response;
    vmf_rpc_response_t response;
    vmf_rpc_msg_t *p_rpc_msg;
    vmf_rpc_msg_t rpc_msg;
   
   /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_LIMITER
    UNIT_TEST_INFO_PRINT("test_vmf_client_rpc_decoder_receive:\n");
    
    p_response = &response;
    p_rpc_msg = &rpc_msg;
    p_rpc_msg->rpc_receive.vmf_msg_length.length = 10;
    
    (void)vmf_client_rpc_decoder_receive(p_rpc_msg, p_response);
    (void)vmf_client_rpc_decoder_receive(p_rpc_msg, p_response);
    
    UNIT_TEST_INFO_PRINT("ALL OK\n");
    UNIT_TEST_INFO_PRINT("-----------------------------------------------------------\n");


    return true;            
}
