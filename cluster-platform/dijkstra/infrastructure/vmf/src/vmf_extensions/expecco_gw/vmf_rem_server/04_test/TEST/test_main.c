#include "nw_vmf_rem_server_unit_test.h"
#include "stdlib.h"

/* macros */
#define UNIT_TEST_LIMITER printf("\n********************************************************************************************************\n");


int main(int argc, char** argv)
{
    hwut_info("VMF remote server Test;\n"
    "CHOICES: util_get_rpc_msg_len, util_get_vmf_msg_len, vmf_client_rpc_decoder, vmf_client_con_init, vmf_create_rem_vmf_thread, vmf_client_rpc_handler, vmf_client_con_accept_sock, vmf_client_rpc_receiver, rpc_mutex_init, rpc_create_and_bind_server_socket, vmf_create_rx_thread, vmf_rem_get_time_in_ms, vmf_client_rpc_decoder_disconnect, vmf_client_rpc_decoder_timed_receive, vmf_client_rpc_decoder_receive\n");

    /* !! coverage !! */
    hwut_choice("util_get_rpc_msg_len",                 test_util_get_rpc_msg_len());
    hwut_choice("util_get_vmf_msg_len",                 test_util_get_vmf_msg_len());
    hwut_choice("vmf_client_rpc_decoder",               test_vmf_client_rpc_decoder());
    hwut_choice("vmf_client_con_init",                  test_vmf_client_con_init());
    hwut_choice("vmf_create_rem_vmf_thread",            test_vmf_create_rem_vmf_thread());
    hwut_choice("vmf_client_rpc_handler",               test_vmf_client_rpc_handler());
    hwut_choice("vmf_client_con_accept_sock",           test_vmf_client_con_accept_sock());
    hwut_choice("vmf_client_rpc_receiver",              test_vmf_client_rpc_receiver());
    hwut_choice("rpc_mutex_init",                       test_rpc_mutex_init());
    hwut_choice("rpc_create_and_bind_server_socket",    test_rpc_create_and_bind_server_socket());
    hwut_choice("vmf_create_rx_thread",                 test_vmf_create_rx_thread());
    hwut_choice("vmf_rem_get_time_in_ms",               test_vmf_rem_get_time_in_ms());
    hwut_choice("vmf_client_rpc_decoder_disconnect",    test_vmf_client_rpc_decoder_disconnect());
    hwut_choice("vmf_client_rpc_decoder_timed_receive", test_vmf_client_rpc_decoder_timed_receive());
    hwut_choice("vmf_client_rpc_decoder_receive",       test_vmf_client_rpc_decoder_receive());
    return 0;
}

