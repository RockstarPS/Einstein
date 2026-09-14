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

  Module:               vmf.h
  Description:          header file for vmf
  Project Scope:        leopard-e

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Joachim Becker

  Compiler/Assembler:   iar
  Target Hardware:      leopard-e

  *****************************************************************************/

#ifndef __VMF_H__
#define __VMF_H__

#define VMF_TRACE
#define VMF
#define SVMF_VERSION        0x0100

#include "vmf_os_config.h"
#include "intEvtDefs.h"

#define VMF_TRACE_M4WAIT4BUFFER
#define VMF_TRACE_M4WAIT_COUNT  (20)
#define VMF_TRACE_M4WAIT_TIME   (1)         /* wait time -total max time is VMF_TRACE_M4WAIT_TIME * VMF_TRACE_M4WAIT_COUNT */
#define WAIT_SOME_TIME          (10)        /* uncritical waiting time in ms */


/* vmf sizes */
#define VMF_PL_LEN_STD              (400)
#define VMF_PL_LEN_MAX              (400)
#define VMF_PL_LEN_MIN              (1)
#define MAX_VMF_DATA_LEN            VMF_PL_LEN_MAX
#define MAX_GROUP_NUM               (20)
#define MAX_CTRL_CONN_PL_LEN        VMF_PL_LEN_STD
#define VMF_IPC_QUEUE_SIZE_SERVER   (20)
#define VMF_CLIENT_DATA_SIZE_BIG    VMF_PL_LEN_MAX
#define VMF_CLIENT_QUEUE_SIZE_STANDARD (20)

/*! Handle definitions */
#define BROADCAST                   250
#define VMF_HANDLE_INVALID          0x7F
#define VMF_HANDLE_BROADCAST        0x7A
#define VMF_BROADCAST_GROUP         BROADCAST


/* enums */
enum VMF_MSG_T
{
    SVMF_BASIC_MSG              = 0x20,                 /* small basic message */
    VMF_CTRL_MSG                = 0x21                  /* control message     */
};

enum SVMF_CTRL_MSG_T
{
    VMF_CTRL_CONNECT              = 3,                  /* connect     */
    VMF_CTRL_REGISTER_MSG_GRP     = 9,                  /* register msg groups  */
    VMF_CTRL_DEREGISTER_MSG_GRP   = 10,                 /* de-register msg groups  */
    VMF_CTRL_REGISTER_SPY         = 12,                 /* regsiter the spy */
    VMF_CTRL_DISCONNECT           = 13,                 /* discconnect     */
};


enum
{
    /* general */
    VMF_OK                                      =  0,   /* No error occurred, everything's OK */
    VMF_ERROR                                   = -1,   /* general error */

    /* memory errors */
    VMF_ERR_OUT_OF_MEMORY                       = -5,    /* out of memory */
    VMF_ERR_BUFFER_TO_SMALL                     = -6,    /* data will not fit into buffer */
    VMF_ERR_TO_MUCH_DATA                        = -7,    /* tx data exceed allowed size */
    VMF_ERR_SHM                                 = -8,    /* shared memory error */
    VMF_ERR_TIMEOUT                             = -9,    /* timeout error */


    /* argument, parameter, ... errors */
    VMF_ERR_INVALID_ARG                         = -10,   /* invalid argument */
    VMF_ERR_OUT_OF_RANGE                        = -11,   /* argument out of range */
    VMF_ERR_NULL_POINTER                        = -12,   /* invalid pointer */
    VMF_ERR_INVALID_EVENT                       = -13,   /* invalid vmf-events */
    VMF_ERR_INVALID_GROUP                       = -14,   /* invalid vmf-group */

    /* MOST errors */
    VMF_ERR_FBLOCK_INSTID_PAIR_ALREADY_EXIST    = -20,   /* Inst-Id / FBlock-Id pair already exist  */
    VMF_ERR_EXT_MOST_LINK_ALREADY_EXIST         = -21,   /* MOST link does already exist  */

    /* IPC errors */
    VMF_ERR_INVALID_VMF_HANDLE                  = -30,   /* channel handle is invalid */
    VMF_ERR_OUT_OF_IPC_CHANNELS                 = -31,   /* number IPC channels > MAX_IPC_CHANNELS */
    VMF_ERR_IPC_SEND                            = -32,   /* error at sending on IPC */
    VMF_ERR_IPC_RECEIVE                         = -33,   /* error at receiving on IPC */
    VMF_ERR_IPC_MUTEX                           = -34,   /* error at (un-)locking the IPC mutex */
    VMF_ERR_IPC_MSG_SIZE_TO_SMALL               = -35,   /* message size in queue smaller than minimum VMF message size */
    VMF_ERR_IPC_NOTIFY                          = -36,   /* error setting notify to queue */

    /* router errors */
    VMF_ERR_ROUTER_INIT_FAILED                  = -40,   /* initialization of router failed */
    VMF_ERR_ROUTER_UNKNOWN_MESSAGE              = -41,   /* unknown message type received */
    VMF_ERR_ROUTER_CLIENT_CONNECT_FAILED        = -42,   /* connection to client failed */
    VMF_ERR_ROUTER_SENDER_HANDLE_NOT_FOUND      = -43,   /* handle of client that has sent not found */
    VMF_ERR_ROUTER_SEND_FAILED                  = -44,   /* sending failed */
    VMF_ERR_ROUTER_REGISTRATION_FAILED          = -45,   /* error at a registration for the client */
    VMF_ERR_ROUTER_START_RECEIVE_FAILED         = -46,   /* error if start receive failed */
    VMF_ERR_ROUTER_DB_ERROR                     = -47,   /* router db returned an error */
    VMF_ERR_ROUTER_REGISTER_SPY_FAILED          = -48,   /* error at the registration of the spy */
    VMF_ERR_ROUTER_INVALID_FB                   = -49,   /* invalid FBlock */
    VMF_ERR_ROUTER_INVALID_INST_ID              = -50,   /* invalid Inst Id */
    VMF_ERR_ROUTER_MOST_REP_MSG_INV_TGT_ADDR    = -51,   /* invalid target address of a MOST report msg */

    VMF_ERR_SHM_IPC_SEM                         = -54,   /* error init sem */
    VMF_ERR_SHM_IPC_NO_DATA                     = -55,   /* no more data in pool or queue */
    VMF_ERR_SHM_IPC_QUEUE_FULL                  = -56,   /* queue is full */
    VMF_ERR_SHM_IPC_EAGAIN                      = -57,   /* function currently not possible - try again */
    VMF_ERR_SHM_IPC_SHM_INVALID                 = -58,   /* SHM invalid (not mapped?) */
    VMF_ERR_SHM_IPC_SHM_TIMEOUT                 = -59,   /* SHM nat valid within timeout time */

    /* remote VMF errors */
    VMF_ERR_NOT_SUPPORTED                       = -60,   /* function currently not supported */
    VMF_ERR_INVALID_RPC_ID                      = -61,   /* invalid rpc id */
    VMF_ERR_REM_SERVER_BIND_ERROR               = -62,   /* bind failed */
    VMF_ERR_REM_SOCK_INVALID                    = -63,   /* invalid socket */
    VMF_ERR_REM_MUTEX_INIT                      = -64,   /* error init mutex */

    /* VMF-timer errors */
    VMF_TIMER_ERR_TIMEOUT                       = -70,   /* timeout waiting for free timer */
    VMF_ERR_MUX                                 = -71,   /* mutex error */
    VMF_ERR_NO_FREE_TIMER                       = -72,   /* no timer available */
    VMF_ERR_TIMER_INVALID                       = -73,   /* invalid timer */

    /* VMF client, message collector */
    VMF_ERR_NO_CO_MSG                           = -80,   /* this message can not be collected */
    VMF_ERR_CO_BUFFER                           = -81,   /* message will not fit into co buffer*/
    VMF_ERR_INVALID_CID                         = -82,   /* invalid client id */
    VMF_ERR_NO_MORE_DATA                        = -83,   /* no more data */
    VMF_ERR_INVALID_VERSION                     = -84,   /* invalid persistent version */
    VMF_ERR_INVALID_P2P_CID                     = -85,   /* the cid can not be used for P2P functions */
    /* insert new error types above !*/
    VMF_LAST                                    = -255   /* last error in list - ignore!*/
};


//#define HANDLE_INVALID      (0)
//typedef int                 HANDLE;

/* message types */
typedef unsigned8       vmf_event_t;
typedef unsigned8       vmf_group_t;
typedef unsigned8       vmf_cid_t;
typedef vmf_cid_t       vmf_client_id_t;        /* for compatibility with old code */
typedef unsigned16      vmf_pid_t;
typedef vmf_pid_t       pid_t;

typedef signed16        vmf_ret_t;
typedef signed8         vmf_handle_t;

/*! \struct VMF_VAR_BASIC_MSG_TYP for small systems
 *   vmf variable size base message */
#define ctrl_type   event
 #pragma pack(push,4)
#define VMF_VAR_MSG_TYP(VAR_DATA_LEN)                                                   \
struct                                                                                  \
{                                                                                       \
    unsigned8           msg_type;               /* control or basic message */          \
    vmf_event_t         event;                  /* message event or  ctrl-id*/          \
    vmf_group_t         group;                  /* message group            */          \
    vmf_cid_t           cid;                    /* client id                */          \
/* 32bit boundary */                                                                    \
    vmf_pid_t           pid;                    /* process id               */          \
    unsigned16          msg_time;               /* bit 0-15 of message time in ms   */  \
                                                /* time in little endian    */          \
/* 32bit boundary */                                                                    \
    unsigned8           msg_time_hh;            /* bit 16-23 of message time in ms  */  \
    unsigned8           client_count;           /* for debugging use        */          \
                                                                                        \
    unsigned16          pl_len;                 /* pl length in little endian */        \
/* 32bit boundary */                                                                    \
    unsigned8           pl[(VAR_DATA_LEN)];                                             \
}
#pragma pack(pop)

#define VMF_VAR_BASIC_MSG_TYP(VAR_DATA_LEN) VMF_VAR_MSG_TYP(VAR_DATA_LEN)

/* pre define vmf message types */
typedef VMF_VAR_MSG_TYP(VMF_PL_LEN_MAX)         vmf_msg_max_t;
typedef VMF_VAR_MSG_TYP(VMF_PL_LEN_MIN)         vmf_msg_min_t;
typedef VMF_VAR_MSG_TYP(VMF_PL_LEN_STD)         vmf_msg_std_t;
typedef vmf_msg_std_t                           vmf_msg_t;
typedef vmf_msg_std_t                           svmf_msg_t;
typedef vmf_msg_std_t                           vmf_basic_msg_t;

#define VMF_MSG_LEN(pl_len)                     (sizeof(VMF_VAR_MSG_TYP(VMF_PL_LEN_MIN))+pl_len)
#define VMF_STD_MSG_LEN                         (sizeof(vmf_msg_std_t))
#define VMF_MAX_MSG_LEN                         (sizeof(vmf_msg_max_t))
#define VMF_HEADER_LEN                          (VMF_STD_MSG_LEN - VMF_PL_LEN_STD)                  /* handle alignment */




/* VMF access macros  */
/* MACROS without cast - these MACROS will only work with VMF_BASIC messages */
#define NW_VMF_BASIC_MSG_GROUP(msg)         ((msg)->group)
#define NW_VMF_BASIC_MSG_EVENT(msg)         ((msg)->event)
#define NW_VMF_BASIC_MSG_TYPE(msg)          ((msg)->msg_type)
#define NW_VMF_BASIC_MSG_DATA_LENGTH(msg)   ((msg)->pl_len)
#define NW_VMF_BASIC_MSG_DATA_PTR(msg)      (&(msg)->pl[0])

/*  old MACROS for compatibility reasons  */
#define NW_VMF_MSG_EVENT(msg)               NW_VMF_BASIC_MSG_EVENT(msg)
#define NW_VMF_MSG_GROUP(msg)               NW_VMF_BASIC_MSG_GROUP(msg)
#define NW_VMF_MSG_TYPE(msg)                NW_VMF_BASIC_MSG_TYPE(msg)
#define NW_VMF_MSG_DATA_LENGTH(msg)         NW_VMF_BASIC_MSG_DATA_LENGTH(msg)
#define NW_VMF_MSG_DATA_PTR(msg)            NW_VMF_BASIC_MSG_DATA_PTR(msg)



/* function prototypes */
#define nw_vmf_send_basic           nw_vmf_send

vmf_cid_t nw_vmf_connect            (const char *p_my_conn_string,      /*!< INPUT channel name or NULL  */
                                    void *ctrl,                         /*!< INPUT pointer to ctrl struct or NULL */
                                    signed32 vmf_collector_timeout,     /*!< INPUT vmf collector timeout or 0 */
                                    unsigned16 message_queue_size,      /*!< INPUT queue size for receiving messages */
                                    unsigned16 message_size );          /*!< INPUT message size for the queue */

vmf_ret_t nw_vmf_disconnect         (vmf_cid_t vmf_client_id);          /*!< INPUT client id */

vmf_ret_t nw_vmf_register_msg_group (vmf_cid_t vmf_client_id,           /**< INPUT connection client id*/
                                    unsigned16 groups_num,              /**< INPUT number of groups in List*/
                                    unsigned8 * groupList);             /**< INPUT pointer ro a list of message groups*/

vmf_ret_t nw_vmf_de_register_msg_group (vmf_cid_t vmf_client_id,        /**< INPUT connection client id*/
                                    unsigned16 groups_num,              /**< INPUT number of groups in List*/
                                    unsigned8 * groupList);             /**< INPUT pointer ro a list of message groups*/

vmf_ret_t nw_vmf_send               (vmf_cid_t vmf_client_id,           /**< INPUT connection_id*/
                                    vmf_msg_t *p_vmf_msg);              /**< INPUT pointer to a vmf_message*/

vmf_ret_t nw_vmf_send_raw           (vmf_client_id_t vmf_trace_tx_cid,  /**< INPUT connection_id*/
                                     void * pbuffer,unsigned16 len);    /**< INPUT pointer to a message*/

signed16 nw_vmf_receive             (vmf_cid_t vmf_client_id,           /**< INPUT connection_id*/
                                    vmf_msg_t * p_vmf_msg,              /**< OUTPUT pointer to a vmf_message*/
                                    unsigned16  rx_buffer_length);      /**< INPUT length of COMPLETE message buffer */

signed16 nw_vmf_timed_receive       (vmf_cid_t vmf_client_id,           /**< INPUT connection_id */
                                    vmf_msg_t * p_vmf_msg,              /**< OUTPUT pointer to a vmf_message */
                                    unsigned16  rx_buffer_length,       /**< INPUT length of reception buffer */
                                    unsigned16  ms_timeout);            /**< INPUT message timeout in ms */
#endif
#include "vmf_trace.h"



  
