#ifndef __VMF_H
#define __VMF_H

#include <stdint.h>

#define MAX_VMF_DATA_LEN 64
#define VMF_CLIENT_QUEUE_SIZE_BIG 64
#define VMF_OK 0

typedef int vmf_client_id_t;
typedef int vmf_ret_t;

typedef struct                   
{                        
    uint8_t grp_id;      
    uint8_t evt_id;      
    uint8_t payload[MAX_VMF_DATA_LEN];
    uint32_t payload_len;
} vmf_basic_msg_t;

typedef vmf_basic_msg_t vmf_msg_t;


#define VMF_VAR_BASIC_MSG_TYP(LEN) vmf_basic_msg_t

#define VMF_BASIC_MSG_GROUP_ID(msg)         (((vmf_basic_msg_t *)msg)->grp_id)
#define VMF_BASIC_MSG_EVENT_ID(msg)         (((vmf_basic_msg_t *)msg)->evt_id)
#define VMF_BASIC_MSG_PTR_TO_FAR_DATA(msg)  (&((vmf_basic_msg_t *)msg)->payload[MAX_VMF_DATA_LEN])


#define VMF_BASIC_MSG_RX_GET_FAR_DATA_LENGTH(target_size,msg) \
target_size = (((vmf_basic_msg_t *)msg)->payload_len)


#define VMF_BASIC_MSG_SET_FAR_DATA_LENGTH(msg,len) ((vmf_basic_msg_t *)msg)->payload_len = len

vmf_client_id_t nw_vmf_connect(const char *p_my_conn_string,
                               void *vctrl,
                               int32_t vmf_collector_timeout,
                               uint16_t message_queue_size,
                               uint16_t message_size);
                               
vmf_ret_t nw_vmf_disconnect( vmf_client_id_t vmf_client_id);

int16_t nw_vmf_receive(vmf_client_id_t vmf_client_id, vmf_msg_t * p_vmf_msg, uint16_t vmf_buffer_length);

vmf_ret_t nw_vmf_register_msg_group(vmf_client_id_t vmf_client_id, uint16_t groups_num, uint8_t * groupList);

vmf_ret_t nw_vmf_send_basic(vmf_client_id_t vmf_client_id, vmf_basic_msg_t * p_vmf_msg);

#endif
