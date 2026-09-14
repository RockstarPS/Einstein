/******************************************************************************
*                                                                             *
*                   CONFIDENTIAL - Visteon Automotive Systems                 *
*                                                                             *
*  This is an unpublished work, which is a trade secret, created in 2007.     *
*  Visteon Automotive Systems owns all rights to this work and intends to     *
*  maintain it in confidence to preserve its trade secret status.  Visteon    *
*  Automotive Systems reserves the right to protect this work as an           *
*  unpublished copyrighted work in the event of an inadvertent or deliberate  *
*  unauthorized publication.  Visteon Automotive Systems also reserves        *
*  its rights under the copyright laws to protect this work as a published    *
*  work.  Those having access to this work may not copy it, use it, or        *
*  disclose the information contained in it without the written authorization *
*  of Visteon Automotive Systems.                                             *
*                                                                             *
*******************************************************************************
*  PROJECT NAME :  VMF                                                        *
*******************************************************************************
*  MODULE NAME  :  vmf.h                                                *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   10th March 2008                                            *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  types used by the Visteon message framework                    *
******************************************************************************/
#ifndef __VMF_H
#define __VMF_H

#ifdef __cplusplus
extern "C" {
#endif



/* #ifndef OS_TYPES_H
//#include <os_types.h>
#endif */
//#include "nw_vmf_types.h"
//#include "nw_vmf_client.h"
typedef uint32_t unsigned32;
typedef int16_t      signed16;
typedef uint16_t     unsigned16;
typedef uint8_t      unsigned8;
typedef int8_t      signed8;
typedef uint64_t    unsigned64;
typedef int64_t    signed64;
typedef int32_t signed32;
enum
{
  VMF_OK                                     =  0   /* No error occurred, everything's OK */
};
typedef signed16        vmf_ret_t;
typedef signed8         vmf_client_id_t;            /* internal client id  (created by vmf-client) */
typedef unsigned8   msg_type_t;
typedef unsigned32      vmf_pid_t;
#define VMF_CLIENT_QUEUE_SIZE_STANDARD      ((unsigned16)30)
#define VMF_BASIC_MSG_NEAR_DATA_LENGTH      0
#define MAX_VMF_DATA_LEN                    ((unsigned16)8192)
#define MAX_VMF_MESSAGE_LEN                 ((unsigned16)8192)

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


typedef struct
{
    vmf_base_t          base;
    struct{
        unsigned8       group;                      /* message group */
        unsigned8       event;                      /* event of group */
    }id;
}vmf_msg_base_t;

#define VMF_VAR_BASIC_MSG_TYP(VAR_DATA_LEN)                 \
struct                                                      \
{                                                           \
    vmf_msg_base_t      msg_base;                           \
    struct {                                                \
        unsigned16          length;                         \
        unsigned8           pl[(VAR_DATA_LEN + VMF_BASIC_MSG_NEAR_DATA_LENGTH)];             \
    }data;                                                  \
}


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

#define VMF_VAR_MSG_TYP(VAR_DATA_LEN)                       \
struct                                                      \
{                                                           \
    union {                                                 \
        VMF_VAR_MOST_MSG_TYP(VAR_DATA_LEN)   vmf_most_msg;  \
        VMF_VAR_BASIC_MSG_TYP(VAR_DATA_LEN)  vmf_basic_msg; \
    };                                                      \
}

#define VMF_CLIENT_DATA_SIZE_STANDARD       ((unsigned16)200)

typedef VMF_VAR_BASIC_MSG_TYP(VMF_CLIENT_DATA_SIZE_STANDARD) vmf_basic_msg_std_t;
typedef vmf_basic_msg_std_t                                  vmf_basic_msg_t;

typedef VMF_VAR_MSG_TYP(VMF_CLIENT_DATA_SIZE_STANDARD)       vmf_msg_std_t;
typedef vmf_msg_std_t                                        vmf_msg_t;

vmf_client_id_t nw_vmf_connect(const char *p_my_conn_string,
                                          void *vctrl,
                                          signed32 vmf_collector_timeout,
                                          unsigned16 message_queue_size,
                                          unsigned16 message_size);
                                          
vmf_ret_t nw_vmf_disconnect( vmf_client_id_t vmf_client_id);

vmf_ret_t nw_vmf_send_basic      (vmf_client_id_t vmf_client_id,vmf_basic_msg_t * p_vmf_msg);

vmf_ret_t nw_vmf_register_msg_group    (vmf_client_id_t vmf_client_id,unsigned16 groups_num,unsigned8 * groupList);

signed16  nw_vmf_receive          (vmf_client_id_t vmf_client_id,vmf_msg_t * p_vmf_msg, unsigned16 vmf_buffer_length);

vmf_ret_t nw_vmf_de_register_msg_group (vmf_client_id_t vmf_client_id,unsigned16 groups_num,unsigned8 * groupList);

#define VMF_BASIC_MSG_PTR_TO_FAR_DATA(msg)  (&((vmf_basic_msg_t *)msg)->data.pl[VMF_BASIC_MSG_NEAR_DATA_LENGTH])
#define VMF_BASIC_MSG_SET_FAR_DATA_LENGTH(msg,len) \
    {\
        ((vmf_basic_msg_t *)msg)->data.length = len + VMF_BASIC_MSG_NEAR_DATA_LENGTH;\
    }

/*! \def VMF_BASIC_MSG_RX_GET_FAR_DATA_LENGTH
    Returns far data size in given parameter "target_size" */
#define VMF_BASIC_MSG_RX_GET_FAR_DATA_LENGTH(target_size,msg) \
    {\
        if((((vmf_basic_msg_t *)msg)->data.length) > VMF_BASIC_MSG_NEAR_DATA_LENGTH)\
        {\
            target_size = (((vmf_basic_msg_t *)msg)->data.length) - VMF_BASIC_MSG_NEAR_DATA_LENGTH;\
        }\
        else \
        {\
            target_size = 0;\
        }\
    }


#define VMF_BASIC_MSG_GROUP_ID(msg)         (((vmf_basic_msg_t *)msg)->msg_base.id.group)
#define VMF_BASIC_MSG_EVENT_ID(msg)         (((vmf_basic_msg_t *)msg)->msg_base.id.event)

#define VMF_BASIC_MSG_GROUP_ID(msg)         (((vmf_basic_msg_t *)msg)->msg_base.id.group)
#define VMF_BASIC_MSG_EVENT_ID(msg)         (((vmf_basic_msg_t *)msg)->msg_base.id.event)
//#include "nw_vmf_client_uties.h"
#ifdef VMF_TRACE
#include "nw_vmf_trace.h"
#endif
//#include "nw_vmf_timer.h"

#ifdef __cplusplus
}
#endif


#endif
