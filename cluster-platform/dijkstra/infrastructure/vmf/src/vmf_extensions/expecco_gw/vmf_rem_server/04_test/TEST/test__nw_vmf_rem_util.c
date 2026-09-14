#include "nw_vmf_rem_server_unit_test.h"
#include "stdlib.h"

bool test_util_get_rpc_msg_len(void)
{
    vmf_error_t result;
    vmf_rpc_msg_t buffer;
    vmf_rpc_msg_t *ptr_buffer;
    unsigned16 msg_length;
    unsigned16 *ptr_msg_length;

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_LIMITER
    UNIT_TEST_INFO_PRINT("test_util_get_rpc_msg_len: NULL pointer check\n");

    ptr_buffer = &buffer;
    ptr_msg_length = NULL;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_ERR_NULL_POINTER != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 set to NULL, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    ptr_buffer = NULL;
    msg_length = 10;
    ptr_msg_length = &msg_length;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_ERR_NULL_POINTER != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param1 set to NULL, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    ptr_buffer = &buffer;
    ptr_msg_length = &msg_length;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param1 set to NULL, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    UNIT_TEST_INFO_PRINT("NULL pointer check: ALL OK\n");

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_LIMITER
    UNIT_TEST_INFO_PRINT("test_util_get_rpc_msg_len: rpc ids\n");

    ptr_buffer = &buffer;
    ptr_msg_length = &msg_length;

    buffer.rpc_id = VMF_RPC_FKT_CONNECT_ASYNC;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    if(GET_VMF_RPC_HEADER_LENGTH + sizeof(ptr_buffer->rpc_connect) == msg_length)
    {
        UNIT_TEST_INFO_PRINT("VMF_RPC_FKT_CONNECT_ASYNC: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: msg_length = %d\n",(int)msg_length);
        return true;
    }


    buffer.rpc_id = VMF_RPC_FKT_CONNECT;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    if(GET_VMF_RPC_HEADER_LENGTH + sizeof(ptr_buffer->rpc_connect) == msg_length)
    {
        UNIT_TEST_INFO_PRINT("VMF_RPC_FKT_CONNECT: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: msg_length = %d\n",(int)msg_length);
        return true;
    }


    buffer.rpc_id = VMF_RPC_FKT_REGISTER_EXT_MOST_LINK;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    if(GET_VMF_RPC_HEADER_LENGTH == msg_length)
    {
        UNIT_TEST_INFO_PRINT("VMF_RPC_FKT_REGISTER_EXT_MOST_LINK: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: msg_length = %d\n",(int)msg_length);
        return true;
    }

    buffer.rpc_id = VMF_RPC_FKT_REGISTER_SPY;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    if(GET_VMF_RPC_HEADER_LENGTH == msg_length)
    {
        UNIT_TEST_INFO_PRINT("VMF_RPC_FKT_REGISTER_SPY: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: msg_length = %d\n",(int)msg_length);
        return true;
    }


    buffer.rpc_id = VMF_RPC_FKT_DISCONNECT;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    if(GET_VMF_RPC_HEADER_LENGTH == msg_length)
    {
        UNIT_TEST_INFO_PRINT("VMF_RPC_FKT_DISCONNECT: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: msg_length = %d\n",(int)msg_length);
        return true;
    }


    buffer.rpc_id = VMF_RPC_FKT_REGISTER_MOST_FB;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    if(GET_VMF_RPC_HEADER_LENGTH + sizeof(ptr_buffer->rpc_reg_fblock) == msg_length)
    {
        UNIT_TEST_INFO_PRINT("VMF_RPC_FKT_REGISTER_MOST_FB: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: msg_length = %d\n",(int)msg_length);
        return true;
    }


    buffer.rpc_id = VMF_RPC_FKT_DEREGISTER_MOST_FB;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    if(GET_VMF_RPC_HEADER_LENGTH + sizeof(ptr_buffer->rpc_reg_fblock) == msg_length)
    {
        UNIT_TEST_INFO_PRINT("VMF_RPC_FKT_DEREGISTER_MOST_FB: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: msg_length = %d\n",(int)msg_length);
        return true;
    }


    buffer.rpc_id = VMF_RPC_FKT_DEREGISTER_MOST_SHAD;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    if(GET_VMF_RPC_HEADER_LENGTH + sizeof(ptr_buffer->rpc_reg_fblock) == msg_length)
    {
        UNIT_TEST_INFO_PRINT("VMF_RPC_FKT_DEREGISTER_MOST_SHAD: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: msg_length = %d\n",(int)msg_length);
        return true;
    }


    buffer.rpc_id = VMF_RPC_FKT_REGISTER_MOST_SHAD;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    if(GET_VMF_RPC_HEADER_LENGTH + sizeof(ptr_buffer->rpc_reg_shadow) + (sizeof(ptr_buffer->rpc_reg_shadow.funcIds)*(ptr_buffer->rpc_reg_shadow.fcIds_num.length)) == msg_length)
    {
        UNIT_TEST_INFO_PRINT("VMF_RPC_FKT_REGISTER_MOST_SHAD: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: msg_length = %d\n",(int)msg_length);
        return true;
    }


    buffer.rpc_id = VMF_RPC_FKT_REGISTER_MSG_GRP;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    if(GET_VMF_RPC_HEADER_LENGTH + sizeof(ptr_buffer->rpc_reg_group)+ (sizeof(ptr_buffer->rpc_reg_group.grps)*(ptr_buffer->rpc_reg_group.grps_num)) == msg_length)
    {
        UNIT_TEST_INFO_PRINT("VMF_RPC_FKT_REGISTER_MSG_GRP: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: msg_length = %d\n",(int)msg_length);
        return true;
    }

    
    buffer.rpc_id = VMF_RPC_FKT_DEREGISTER_MSG_GRP;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    if(GET_VMF_RPC_HEADER_LENGTH + sizeof(ptr_buffer->rpc_reg_group)+ (sizeof(ptr_buffer->rpc_reg_group.grps)*(ptr_buffer->rpc_reg_group.grps_num)) == msg_length)
    {
        UNIT_TEST_INFO_PRINT("VMF_RPC_FKT_DEREGISTER_MSG_GRP: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: msg_length = %d\n",(int)msg_length);
        return true;
    }


    buffer.rpc_id = VMF_RPC_FKT_SEND_MOST_ASYNC;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    if(sizeof(VMF_VAR_MOST_MSG_TYP(0)) + (sizeof(ptr_buffer->rpc_send_most.vmf_most_msg.data.pl[0])*ptr_buffer->rpc_send_most.vmf_most_msg.data.length) + GET_VMF_RPC_HEADER_LENGTH  == msg_length)
    {
        UNIT_TEST_INFO_PRINT("VMF_RPC_FKT_SEND_MOST_ASYNC: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: msg_length = %d\n",(int)msg_length);
        return true;
    }


    buffer.rpc_id = VMF_RPC_FKT_SEND_MOST_CTRL;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    if(sizeof(VMF_VAR_MOST_MSG_TYP(0)) + (sizeof(ptr_buffer->rpc_send_most.vmf_most_msg.data.pl[0])*ptr_buffer->rpc_send_most.vmf_most_msg.data.length) + GET_VMF_RPC_HEADER_LENGTH  == msg_length)
    {
        UNIT_TEST_INFO_PRINT("VMF_RPC_FKT_SEND_MOST_CTRL: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: msg_length = %d\n",(int)msg_length);
        return true;
    }


    buffer.rpc_id = VMF_RPC_FKT_SEND_BASIC;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    if(sizeof(VMF_VAR_MOST_MSG_TYP(0)) + (sizeof(ptr_buffer->rpc_send_basic.vmf_basic_msg.data.pl[0])*(ptr_buffer->rpc_send_basic.vmf_basic_msg.data.length)) + GET_VMF_RPC_HEADER_LENGTH  == msg_length)
    {
        UNIT_TEST_INFO_PRINT("VMF_RPC_FKT_SEND_BASIC: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: msg_length = %d\n",(int)msg_length);
        return true;
    }


    buffer.rpc_id = VMF_RPC_FKT_RECEIVE;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    if(GET_VMF_RPC_HEADER_LENGTH + sizeof(ptr_buffer->rpc_receive)  == msg_length)
    {
        UNIT_TEST_INFO_PRINT("VMF_RPC_FKT_RECEIVE: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: msg_length = %d\n",(int)msg_length);
        return true;
    }


    buffer.rpc_id = 0;
    result = vmf_rem_get_rpc_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    if(0 == msg_length)
    {
        UNIT_TEST_INFO_PRINT("INVALID ID: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: msg_length = %d\n",(int)msg_length);
        return true;
    }


    return true;
}

bool test_util_get_vmf_msg_len(void)
{
    vmf_error_t result;
    vmf_msg_t buffer;
    vmf_msg_t *ptr_buffer;
    unsigned16 msg_length;
    unsigned16 *ptr_msg_length;
    VMF_VAR_MSG_TYP(0) vmf_msg;
    vmf_msg_t *ptr_vmf_msg = (vmf_msg_t *)&vmf_msg;

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_LIMITER
    UNIT_TEST_INFO_PRINT("test_util_get_vmf_msg_len: NULL pointer check\n");

    ptr_buffer = &buffer;
    ptr_msg_length = NULL;
    result = vmf_rem_get_vmf_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_ERR_NULL_POINTER != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 set to NULL, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    ptr_buffer = NULL;
    msg_length = 0;
    ptr_msg_length = &msg_length;
    result = vmf_rem_get_vmf_msg_len(ptr_msg_length, ptr_buffer);
    if(VMF_ERR_NULL_POINTER != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param1 set to NULL, param0 = %d, param1 = %d\n",(int)result, (int)ptr_msg_length, (int)ptr_buffer);
        return true;
    }

    UNIT_TEST_INFO_PRINT("NULL pointer check: ALL OK\n");

    /*---------------------------------------------------------------------------------------------------------------*/
    UNIT_TEST_LIMITER
    UNIT_TEST_INFO_PRINT("test_util_get_vmf_msg_len: msg type check\n");

    /* MOST */
    msg_length = 0;
    ptr_msg_length = &msg_length;
    ptr_vmf_msg->vmf_most_msg.msg_base.base.msg_type = MSG_TYPE_MOST_MESSAGE;
    result = vmf_rem_get_vmf_msg_len(ptr_msg_length, ptr_vmf_msg);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)msg_length, (int)ptr_vmf_msg);
        return true;
    }

    if(sizeof(VMF_VAR_MOST_MSG_TYP(0)) + (sizeof(ptr_vmf_msg->vmf_most_msg.data.pl[0])*(ptr_vmf_msg->vmf_most_msg.data.length))+4  == msg_length)
    {
        UNIT_TEST_INFO_PRINT("MOST msg type: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: MOST msgs type: msg_length = %d\n",(int)msg_length);
        return true;
    }

    /* BASIC */
    msg_length = 0;
    ptr_msg_length = &msg_length;
    ptr_vmf_msg->vmf_most_msg.msg_base.base.msg_type = MSG_TYPE_BASIC_MESSAGE;
    result = vmf_rem_get_vmf_msg_len(ptr_msg_length, ptr_vmf_msg);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)msg_length, (int)ptr_vmf_msg);
        return true;
    }

    if(sizeof(VMF_VAR_BASIC_MSG_TYP(0)) + (sizeof(ptr_vmf_msg->vmf_basic_msg.data.pl[0])*(ptr_vmf_msg->vmf_basic_msg.data.length))+4  == msg_length)
    {
        UNIT_TEST_INFO_PRINT("BASIC msg type: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: BASIC msgs type: msg_length = %d\n",(int)msg_length);
        return true;
    }


    /* INVALID*/
    msg_length = 0;
    ptr_msg_length = &msg_length;
    ptr_vmf_msg->vmf_most_msg.msg_base.base.msg_type = 0;
    result = vmf_rem_get_vmf_msg_len(ptr_msg_length, ptr_vmf_msg);
    if(VMF_OK != result)
    {
        UNIT_TEST_INFO_PRINT("ERROR: result = %d, param0 = %d, param1 = %d\n",(int)result, (int)msg_length, (int)ptr_vmf_msg);
        return true;
    }

    if(0 == msg_length)
    {
        UNIT_TEST_INFO_PRINT("INVALID msg type: OK\n");
    }
    else
    {
        UNIT_TEST_INFO_PRINT("ERROR: INVALID msgs type: msg_length = %d\n",(int)msg_length);
        return true;
    }

}
