#ifndef __VMF_H
#define __VMF_H

typedef uint64_t 		unsigned64;
typedef int32_t 		signed32;
typedef uint32_t 		unsigned32;
typedef int16_t 		signed16;
typedef uint16_t 		unsigned16;
typedef int8_t 			signed8;
typedef uint8_t 		unsigned8;
typedef int16_t 		vmf_ret_t;
typedef int8_t 			vmf_client_id_t;
typedef unsigned8   	msg_type_t;
typedef unsigned32      vmf_pid_t;
typedef signed8         vmf_client_id_t;

#define MAX_VMF_DATA_LEN 8192
#define MAX_GROUP_NUM 250
#define VMF_CLIENT_QUEUE_SIZE_STANDARD 30
#define VMF_CLIENT_DATA_SIZE_STANDARD       ((unsigned16)600)
#define VMF_OK 0
#define VMF_BASIC_MSG_NEAR_DATA_LENGTH      0


typedef struct
{
    msg_type_t          msg_type;                   /* control, MOST or basic message */
    unsigned8           client_count;               /* for debugging use - currently number of message receivers */
    unsigned8           vmf_mi_server_id;           /* for debugging use - currently server ID for vmf-mi */
    unsigned8           co_msg_type;                /* collector message type - 0 if single message, 1 if multi message*/
    vmf_pid_t           pid;                        /* process id of client*/
    vmf_client_id_t     client_id;                  /* additional client identification */
    unsigned8           vmf_co_num_msgs;            /* number of collected  messages */
    unsigned8           vmf_co_curr_msg;            /* current co message */
    unsigned8           vmf_debug_85;
    unsigned64          msg_clk;                    /* message time in clocks */
}vmf_base_t;

/*! vmf-base */
typedef struct
{
    vmf_base_t          base;
    struct{
        unsigned8       group;                      /* message group */
        unsigned8       event;                      /* event of group */
    }id;
}vmf_msg_base_t;

#define VMF_VAR_MOST_MSG_TYP(VAR_DATA_LEN)                  \
struct                                                      \
{                                                           \
    vmf_msg_base_t      msg_base;                           \
    unsigned16          tgt_addr;                           \
    unsigned16          src_addr;                           \
    unsigned8           channel_flag;                       \
    unsigned8           fblock_id;                          \
    unsigned8           inst_id;                            \
    unsigned16          func_id;                            \
    unsigned8           op_type;                            \
    struct {                                                \
        unsigned16        length;                           \
        unsigned8         pl[(VAR_DATA_LEN)];               \
    }data;                                                  \
}

#define VMF_VAR_BASIC_MSG_TYP(VAR_DATA_LEN)                 \
struct                                                      \
{                                                           \
    vmf_msg_base_t      msg_base;                           \
    struct {                                                \
        unsigned16          length;                         \
        unsigned8           pl[(VAR_DATA_LEN + VMF_BASIC_MSG_NEAR_DATA_LENGTH)];             \
    }data;                                                  \
}

#define VMF_VAR_MSG_TYP(VAR_DATA_LEN)                       \
struct                                                      \
{                                                           \
    union {                                                 \
        VMF_VAR_MOST_MSG_TYP(VAR_DATA_LEN)   vmf_most_msg;  \
        VMF_VAR_BASIC_MSG_TYP(VAR_DATA_LEN)  vmf_basic_msg; \
    };                                                      \
}

typedef VMF_VAR_BASIC_MSG_TYP(VMF_CLIENT_DATA_SIZE_STANDARD) vmf_basic_msg_t;
typedef VMF_VAR_MSG_TYP(VMF_CLIENT_DATA_SIZE_STANDARD)       vmf_msg_t;



#define VMF_BASIC_MSG_GROUP_ID(msg)         (((vmf_basic_msg_t *)msg)->msg_base.id.group)
#define VMF_BASIC_MSG_EVENT_ID(msg)         (((vmf_basic_msg_t *)msg)->msg_base.id.event)

#define VMF_BASIC_MSG_PTR_TO_FAR_DATA(msg)  (&((vmf_basic_msg_t *)msg)->data.pl[VMF_BASIC_MSG_NEAR_DATA_LENGTH])


#define VMF_BASIC_MSG_SET_FAR_DATA_LENGTH(msg,len) \
    {\
        ((vmf_basic_msg_t *)msg)->data.length = len + VMF_BASIC_MSG_NEAR_DATA_LENGTH;\
    }
	
#define VMF_BASIC_MSG_RX_GET_FAR_DATA_LENGTH(target_size,msg) \
    {\
		target_size = (((vmf_basic_msg_t *)msg)->data.length) - VMF_BASIC_MSG_NEAR_DATA_LENGTH;\
	}

extern vmf_client_id_t nw_vmf_connect(const char *p_my_conn_string,
                                          void *vctrl,
                                          signed32 vmf_collector_timeout,
                                          unsigned16 message_queue_size,
                                          unsigned16 message_size);
extern vmf_ret_t nw_vmf_disconnect( vmf_client_id_t vmf_client_id);
extern vmf_ret_t nw_vmf_register_msg_group    (vmf_client_id_t vmf_client_id,unsigned16 groups_num,unsigned8 * groupList);
extern vmf_ret_t nw_vmf_send_basic      (vmf_client_id_t vmf_client_id,vmf_basic_msg_t * p_vmf_msg);
extern signed16  nw_vmf_timed_receive    (vmf_client_id_t vmf_client_id,vmf_msg_t * p_vmf_msg, unsigned16 vmf_buffer_length, unsigned16 ms_timeout);


#endif /* __VMF_H */