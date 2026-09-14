#include "nw_vmf_rem_server_unit_test.h"
#include "nw_vmf_rem_server_connector.h"
#include "nw_vmf.h"

static int      wsastartupresult    = 0;
static int      listen_result       = 0;
static SOCKET   result_accept       = 0;
static SOCKET   result_send         = 0;
static int      result_recv         = 0;
static int      result_socket       = 0;

static signed16 nw_vmf_receive_result = VMF_OK;
static signed16 nw_vmf_timed_receive_result = VMF_OK;
static vmf_ret_t result_nw_vmf_disconnect = VMF_OK;
static vmf_ret_t nw_vmf_send_result = VMF_OK;
static vmf_ret_t nw_vmf_send_basic_result = VMF_OK;
static vmf_ret_t nw_vmf_send_most_ctrl_result = VMF_OK;
static vmf_ret_t nw_vmf_send_most_async_result = VMF_OK;
static vmf_ret_t nw_vmf_register_msg_group_result = VMF_OK;
static vmf_ret_t nw_vmf_register_most_shadow_result = VMF_OK;
static vmf_ret_t nw_vmf_register_most_fblock_result = VMF_OK;
static vmf_ret_t nw_vmf_de_register_most_shadow_result = VMF_OK;
static vmf_ret_t nw_vmf_de_register_most_fblock_result = VMF_OK;
static vmf_ret_t nw_vmf_register_spy_result = VMF_OK;
static vmf_ret_t nw_vmf_register_ext_most_link_result = VMF_OK;
static vmf_ret_t nw_vmf_de_register_msg_group_result = VMF_OK;
static vmf_client_id_t nw_vmf_connect_result = 1;

unsigned64 ClockCycles(void)
{
    return 0xAAAA;
}

unsigned int delay( unsigned int duration )
{
    return 0;
}

void set_result_recv(int param)
{
    result_recv = param;
}

int recv(SOCKET s,char *buf,int len,int flags)
{
    return result_recv;
}

void set_nw_vmf_connect_result(vmf_client_id_t param)
{
    nw_vmf_connect_result = param;
}

vmf_client_id_t nw_vmf_connect( const char *p_my_process_name,                               /*!< INPUT channel name or NULL  */
                                void cb_api_vmf_msg_receive_callback(vmf_msg_t * p_vmf_msg), /*!< INPUT rx callback or NULL */
                                signed32 callback_priority,                                  /*!< INPUT thread priority of rx callback function */
                                unsigned16 message_queue_size,                               /*!< INPUT queue size for receiving messages */
                                unsigned16 message_size )
{
    return nw_vmf_connect_result;
}

void set_nw_vmf_disconnect( vmf_ret_t param)
{
    result_nw_vmf_disconnect = param;
}

vmf_ret_t nw_vmf_disconnect( vmf_client_id_t vmf_client_id)
{
    return result_nw_vmf_disconnect;
}

void set_nw_vmf_de_register_msg_group_result(vmf_ret_t param)
{
    nw_vmf_de_register_msg_group_result = param;
}

vmf_ret_t nw_vmf_de_register_msg_group  (vmf_client_id_t vmf_client_id, /**<INPUT connection_id*/
                                        unsigned16 groups_num,          /**<INPUT number of groups in List*/
                                        unsigned8 * groupList)          /**<INPUT pointer to a list of message groups*/
{
    return nw_vmf_de_register_msg_group_result;
}

void set_nw_vmf_register_ext_most_link_result(vmf_ret_t param)
{
    nw_vmf_register_ext_most_link_result = param;
}

vmf_ret_t nw_vmf_register_ext_most_link(vmf_client_id_t vmf_client_id) /*!< INPUT client id */
{
    return nw_vmf_register_ext_most_link_result;
}

void set_nw_vmf_register_spy_result(vmf_ret_t param)
{
    nw_vmf_register_spy_result = param;
}

vmf_ret_t nw_vmf_register_spy(vmf_client_id_t vmf_client_id) /*!< INPUT client id */
{
    return nw_vmf_register_spy_result;
}

void set_nw_vmf_de_register_most_fblock_result(vmf_ret_t param)
{
    nw_vmf_de_register_most_fblock_result = param;    
}

vmf_ret_t nw_vmf_de_register_most_fblock(vmf_client_id_t vmf_client_id,     /**< INPUT connection client-id */
                                         unsigned8 fBlockId,                /**< INPUT FBlock ID */
                                         unsigned8 instId)                  /**< INPUT Instant ID */
{
    return nw_vmf_de_register_most_fblock_result;
}

void set_nw_vmf_de_register_most_shadow_result(vmf_ret_t  param)
{
    nw_vmf_de_register_most_shadow_result = param;    
}

vmf_ret_t nw_vmf_de_register_most_shadow(vmf_client_id_t vmf_client_id,     /**<INPUT connection client id*/
                                         unsigned8 fBlockId,                /**<INPUT FBlock ID*/
                                         unsigned8 instId)                  /**<INPUT Instant ID*/
{
    return nw_vmf_de_register_most_shadow_result;
}

void set_nw_vmf_register_most_fblock_result(vmf_ret_t param)
{
    nw_vmf_register_most_fblock_result = param;
}

vmf_ret_t nw_vmf_register_most_fblock(vmf_client_id_t vmf_client_id,     /**< INPUT connection client-id */
                                         unsigned8 fBlockId,                /**< INPUT FBlock ID */
                                         unsigned8 instId)                  /**< INPUT Instant ID */
{
    return nw_vmf_register_most_fblock_result;
}


void set_nw_vmf_register_most_shadow(vmf_ret_t param)
{
    nw_vmf_register_most_shadow_result = param;
}

vmf_ret_t nw_vmf_register_most_shadow  (vmf_client_id_t vmf_client_id,  /**< INPUT connection client-id */
                                        unsigned8 fBlockId,             /**< INPUT FBlock ID */
                                        unsigned8 instId,               /**< INPUT Instant ID */
                                        unsigned16 fcIds_num,           /**< INPUT number of function ID's in list */
                                        unsigned16 *funcIds)            /**< INPUT pointer to a list of function ID's*/
{
    return nw_vmf_register_most_shadow_result;
}


void set_nw_vmf_register_msg_group(vmf_ret_t param)
{
    nw_vmf_register_msg_group_result = param;
}

vmf_ret_t nw_vmf_register_msg_group (vmf_client_id_t vmf_client_id, /**<INPUT connection client id*/
                                     unsigned16 groups_num,         /**<INPUT number of groups in List*/
                                     unsigned8 * groupList)         /**<INPUT pointer ro a list of message groups*/
{
    return nw_vmf_register_msg_group_result;
}


void set_nw_vmf_send_most_async_result(vmf_ret_t param)
{
    nw_vmf_send_most_async_result = param;
}

vmf_ret_t nw_vmf_send_most_async      (vmf_client_id_t vmf_client_id,     /**<INPUT connection_id*/
                                       vmf_most_msg_t * p_vmf_msg)        /**<INPUT pointer to a MOST vmf_message*/
{
    return nw_vmf_send_most_async_result;
}

void set_nw_vmf_send_most_ctrl_result(vmf_ret_t param)
{
    nw_vmf_send_most_ctrl_result = param;
}

vmf_ret_t nw_vmf_send_most_ctrl(vmf_client_id_t vmf_client_id,     /**<INPUT connection_id*/
                               vmf_most_msg_t * p_vmf_msg)        /**<INPUT pointer to a MOST vmf_message*/
{
    return nw_vmf_send_most_ctrl_result;
}

void set_nw_vmf_send_basic(vmf_ret_t param)
{
    nw_vmf_send_basic_result = param;
}

vmf_ret_t nw_vmf_send_basic     (vmf_client_id_t vmf_client_id,     /**<INPUT connection_id*/
                                 vmf_basic_msg_t *p_vmf_msg)        /**<INPUT pointer to a basic vmf_message*/
{
    return nw_vmf_send_basic_result;
}

void set_nw_vmf_send_result(vmf_ret_t param)
{
    nw_vmf_send_result = param;
}

vmf_ret_t nw_vmf_send(vmf_client_id_t vmf_client_id,  /**<INPUT connection_id*/
                                 vmf_msg_t * p_vmf_msg)          /**<INPUT pointer to a vmf_message*/
{
    return nw_vmf_send_result;
}

void set_nw_vmf_receive_result(signed16 param)
{
    nw_vmf_receive_result = param;
}

signed16 nw_vmf_receive          (vmf_client_id_t vmf_client_id,    /**< INPUT connection_id*/
                                  vmf_msg_t * p_vmf_msg,            /**< OUTPUT pointer to a vmf_message*/
                                  unsigned16  vmf_msg_length)       /**< INPUT length of COMPLETE message buffer */
{
    return nw_vmf_receive_result;
}

void set_nw_vmf_timed_receive_result(signed16 param)
{
    nw_vmf_timed_receive_result = param;
}

signed16 nw_vmf_timed_receive    (vmf_client_id_t vmf_client_id,    /**< INPUT connection_id */
                                  vmf_msg_t * p_vmf_msg,            /**< OUTPUT pointer to a vmf_message */
                                  unsigned16  vmf_msg_length,       /**< INPUT length of COMPLETE message buffer */
								  unsigned16  ms_timeout) 			/**< INPUT message timeout in ms */
{
    return nw_vmf_timed_receive_result;
}

void set_wsastartupresult(int result)
{
    wsastartupresult = result;
}

int WSAStartup(int param0, int *param1)
{
    return wsastartupresult;
}

void set_result_listen(int param)
{
    listen_result = param;
}

int listen(int param0, int param1)
{
    return listen_result;
}

SOCKET accept(SOCKET param0, int * param1, int *param2)
{
    return result_accept;
}

void set_accept_result(SOCKET param)
{
    result_accept = param;
}

void set_send_result(SOCKET param)
{
    result_send = param;
}
extern SOCKET send( SOCKET my_sock, char * p_rpc_response, unsigned16 tx_buffer_len, int num )
{
    return result_send;
}

extern void set_socket(SOCKET param)
{
    result_socket = param;
}
extern SOCKET socket(int param0, int param1, int param2)
{
    return result_socket;
}
