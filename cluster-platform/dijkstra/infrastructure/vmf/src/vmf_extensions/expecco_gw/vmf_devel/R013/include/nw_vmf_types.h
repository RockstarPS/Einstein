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
*  MODULE NAME  :  vmf_types.h                                                *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   5th March 2008                                            *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  types used by the Visteon message framework                    *
******************************************************************************/
#ifndef VMF_TYPES__H_
#define VMF_TYPES__H_

#include "os_types.h"
#include "nw_os_config.h"

#ifndef WIN32
#include "nw_config.h"
#endif

#ifdef __NW_VMF_ROUTING_DB_OPTION_UNIT_TEST 
#include "nw_config.h"
#endif

#ifndef __WINDOWS__
#ifdef WIN32
#pragma warning( disable : 4116)
#endif
#endif

#define VMF_TRUE                            (true)
#define VMF_FALSE                           (false)


/*! VMF Limits */
#define MIN_VMF_MESSAGE_LEN                 ((unsigned16)sizeof(VMF_VAR_MSG_TYP(0)))
#define MAX_VMF_MESSAGE_LEN                 ((unsigned16)sizeof(VMF_VAR_MSG_TYP(MAX_VMF_DATA_LEN)))
#define MIN_VMF_BASIC_MESSAGE_LEN           ((unsigned16)sizeof(VMF_BASIC_MSG_LEN(0)))
#define MAX_VMF_BASIC_MESSAGE_LEN           ((unsigned16)sizeof(VMF_VAR_BASIC_MSG_TYP(MAX_VMF_DATA_LEN)))


/*! Handle definitions */
#define VMF_HANDLE_INVALID                  0x7F
#define VMF_HANDLE_BROADCAST                0x7A
#define VMF_BROADCAST_GROUP                 BROADCAST

/*! VMF message queue defaults */
/*! number of msgs in queue*/
#define VMF_CLIENT_DATA_SIZE_BIG            MAX_VMF_DATA_LEN

/*! size of complete messages */
#define VMF_CLIENT_QUEUE_MSG_SIZE_SMALL     ((unsigned16)sizeof(VMF_VAR_MSG_TYP(VMF_CLIENT_DATA_SIZE_SMALL)))
#define VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD  ((unsigned16)sizeof(VMF_VAR_MSG_TYP(VMF_CLIENT_DATA_SIZE_STANDARD)))
#define VMF_CLIENT_QUEUE_MSG_SIZE_BIG       ((unsigned16)sizeof(VMF_VAR_MSG_TYP(VMF_CLIENT_DATA_SIZE_BIG)))

/* helper macros */
#define     VMF_LEN_OFFSET              offsetof(vmf_basic_msg_t,data.length)
#define     VMF_PL_OFFSET               offsetof(vmf_basic_msg_t,data.pl)
#define     VMF_BASIC_MSG_LEN(pl_len)   (VMF_PL_OFFSET + pl_len)        /* real size of basic message */
#define     VMF_ALIGN4(len)             (((len +3) >> 2)<<2)            /* allign to four */                  
#define     VMF_BASIC_MSG_HEADER_SIZE   (sizeof(VMF_VAR_BASIC_MSG_TYP(0))-VMF_BASIC_MSG_NEAR_DATA_LENGTH)
//#define     VMF_BASIC_MSG_HEADER_SIZE   VMF_BASIC_MSG_LEN(0)

#pragma pack(push,4)


/* enums */
/*! error identifier */
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
	VMF_ERR_INVALID_EVENT						= -13,	 /* invalid vmf-events */
	VMF_ERR_INVALID_GROUP						= -14,	 /* invalid vmf-group */
    
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
/*! general vmf error type */
typedef signed16        vmf_error_t;


/*! message-header identifier */
enum
{
    MSG_TYPE_INVALID                            = 0,    /* invalid message type */
    MSG_TYPE_MOST_MESSAGE                       = 1,    /* MOST message type */
    MSG_TYPE_BASIC_MESSAGE                      = 2,    /* BASIC message type */
    MSG_TYPE_CONNECT                            = 3,    /* type for vmf_connect() */
    MSG_TYPE_REGISTER_EXT_MOST_LINK             = 4,    /* type for vmf_register_ext_most_link() */
    MSG_TYPE_REGISTER_MOST_FBLOCK               = 5,    /* type for vmf_register_most_fblock() */
    MSG_TYPE_DE_REGISTER_MOST_FBLOCK            = 6,    /* type for vmf_de_register_most_fblock() */
    MSG_TYPE_REGISTER_MOST_SHADOW               = 7,    /* type for vmf_register_most_shadow() */
    MSG_TYPE_DE_REGISTER_MOST_SHADOW            = 8,    /* type for vmf_de_register_most_shadow() */
    MSG_TYPE_REGISTER_MSG_GROUPS                = 9,    /* type for vmf_register_msg_group() */
    MSG_TYPE_DE_REGISTER_MSG_GROUPS             =10,    /* type for vmf_de_register_msg_group() */
    MSG_TYPE_START_RECEIVE                      =11,    /* inform server that a receiver is started */
    MSG_TYPE_REGISTER_SPY                       =12,    /* type for vmf_register_spy */
    MSG_TYPE_DISCONNECT                         =13,    /* type for vmf_disconnect() (internal network use only !!) */
    MSG_TYPE_REGISTER_TRACE_SERVER              =14,    /* type for vmf_register_trace_server */
    MSG_TYPE_BASIC_EMBEDDED_MESSAGE             =15,    /* vmf message embedded in payload of a basic message */ 
    MSG_TYPE_P2P_BASIC_MESSAGE                  =16,    /* BASIC message used for p2p connections */
    MSG_TYPE_SHM_REQUEST                        =17     /* client request via shm */
};
/*! type for message-header identifier */
typedef unsigned8   msg_type_t;

/*! message-header identifier */
enum
{
    CHANNEL_TYPE_MOST_ASYNC                      = 0,    /* (MOST high) */
    CHANNEL_TYPE_MOST_CTRL                               /* (MOST control message ) */
};
/*! type of message-header identifier */
typedef unsigned8 channel_flag_t;


/*! general vmf return type */
typedef signed16        vmf_ret_t;


/******************************************************
*       basic types
*******************************************************/

/*! vmf handle type */
typedef signed8         vmf_handle_t;

/* ipc-type definitions */
typedef signed8         vmf_client_id_t;            /* internal client id  (created by vmf-client) */


/* message types for co_msg_type in vmf_base_t */
enum
{
    STD_VMF_MSG = 0,                                /* standard message */
    COL_VMF_MSG = 1,                                /* collected message */
    COL_VMF_MSG_SPY = 2                             /* collected message send to spy */
};

/*! ctrl message base */
typedef struct
{
    msg_type_t          msg_type;                   /* control, MOST or basic message */
    unsigned8           client_count;               /* for debugging use - currently number of message receivers */
    unsigned8           vmf_mi_server_id;           /* for debugging use - currently server ID for vmf-mi */
    unsigned8           co_msg_type;                /* collector message type - 0 if single message, 1 if multi message*/
    pid_t               pid;                        /* process id of client*/
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



/******************************************************
*       control message types
*******************************************************/

/*! \struct vmf_ctrl_msg_connect_t
 *   ctrl message type for connect */
typedef struct
{
    vmf_base_t          base;
    unsigned8           pl_len;
    char                pl_data[MAX_CTRL_CONN_PL_LEN+1];
}vmf_ctrl_msg_connect_t;


/*! \struct vmf_ctrl_msg_start_receive_t
 *   ctrl message type - start receive */
typedef struct
{
    vmf_base_t          base;
}vmf_ctrl_msg_start_receive_t;



/*! \struct vmf_ctrl_msg_register_ext_most_link_t
 *   vmf register_ext_most_link msg type */
typedef struct
{
    vmf_base_t          base;
}vmf_ctrl_msg_register_ext_most_link_t;



/*! \struct vmf_ctrl_msg_register_spy_t
 *   vmf register_spy msg type */
typedef struct
{
    vmf_base_t          base;
}vmf_ctrl_msg_register_spy_t;


/*! \struct vmf_ctrl_msg_register_trace_server_t
 *   vmf register_trace_server msg type */
typedef struct
{
    vmf_base_t          base;
}vmf_ctrl_msg_register_trace_server_t;


/*! \struct vmf_ctrl_msg_register_most_fblock_t
*    vmf register_most_fblock msg type */
typedef struct
{
    vmf_base_t          base;
    unsigned8           fBlockId;
    unsigned8           instId;
}vmf_ctrl_msg_register_most_fblock_t;


/*! \struct vmf_ctrl_msg_de_register_most_fblock_t
*    vmf de_register_most_fblock msg type */
typedef struct
{
    vmf_base_t          base;
    unsigned8           fBlockId;
    unsigned8           instId;
}vmf_ctrl_msg_de_register_most_fblock_t;


/*! \struct vmf_ctrl_msg_register_most_shadow_t
 *   vmf_register_most_shadow type */
#define VMF_VAR_CTRL_MSG_REGISTER_MOST_SHADOW_TYP(VAR_DATA_LEN) \
struct                                                          \
{                                                               \
    vmf_base_t          base;                                   \
    unsigned8           fBlockId;                               \
    unsigned8           instId;                                 \
    unsigned16          u16NumFKtIds;                           \
    unsigned16          funcIdList[VAR_DATA_LEN];               \
}
typedef VMF_VAR_CTRL_MSG_REGISTER_MOST_SHADOW_TYP(MAX_NUM_FKT_IDS)  vmf_ctrl_msg_register_most_shadow_t;


/*! \struct vmf_ctrl_msg_de_register_most_shadow_t
 *   vmf_de_register_most_shadow type */
typedef struct
{
    vmf_base_t          base;
    unsigned8           fBlockId;
    unsigned8           instId;
}vmf_ctrl_msg_de_register_most_shadow_t;


/*! \struct vmf_ctrl_msg_register_msg_group_t
 *   vmf_register_msg_group type */
#define VMF_VAR_CTRL_MSG_REGISTER_MSG_GROUP_TYP(VAR_DATA_LEN)   \
struct                                                          \
{                                                               \
    vmf_base_t          base;                                   \
    unsigned16          groups_num;                             \
    unsigned8           groupList[VAR_DATA_LEN];                \
}
typedef VMF_VAR_CTRL_MSG_REGISTER_MSG_GROUP_TYP(MAX_GROUP_NUM)  vmf_ctrl_msg_register_msg_group_t;



/******************************************************
*       event-message types
*******************************************************/

/*! \struct vmf_event_data_t
    vmf event data base type */
typedef struct
{
    unsigned16          length;                     /* payload lenth */
    unsigned8           pl[VMF_BASIC_MSG_NEAR_DATA_LENGTH]; /* payload (formerly near data) */
}vmf_event_data_t;


/*! \struct vmf_evt_reg_opr_add_comp_t
 *   event group=REG_OPERATION, event-id=RegOprAddComp */
typedef struct
{
    vmf_msg_base_t      msg_base;
    struct
    {
        unsigned16          length;
    unsigned8           data0;              /* not needed  */
    unsigned8           fblock_id;          /* fblock ID   */
    unsigned8           inst_id;            /* instance ID */
    unsigned8           data3;              /* not needed  */
    }data;
}vmf_evt_reg_opr_add_comp_t;


/*! \struct vmf_evt_most_mod_com_disconnect_t
 *   event group=NETWORK_STATUS, event-id=MstModComDisConnect */
typedef struct
{
    vmf_msg_base_t      msg_base;
    vmf_event_data_t    data;
}vmf_evt_most_mod_com_disconnect_t;

/*! \struct vmf_evt_near
    definition of near event */
typedef struct
{
    vmf_msg_base_t      msg_base;
    vmf_event_data_t    data;
}vmf_evt_near;


/*! \struct vmf_evt_msg_t
 *   event message */
typedef struct
{
    union
    {
        vmf_evt_reg_opr_add_comp_t          reg_opr_add_com;
        vmf_evt_most_mod_com_disconnect_t   most_mod_com_disconnect;
        vmf_evt_near                        near_data;
    };
}vmf_evt_msg_t;



/******************************************************
*       vmf-message type
*******************************************************/

/*! \struct VMF_VAR_MOST_MSG_TYP
 *   vmf variable size MOST message */
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

/*! \struct VMF_VAR_BASIC_MSG_TYP
 *   vmf variable size base message */
#define VMF_VAR_BASIC_MSG_TYP(VAR_DATA_LEN)                 \
struct                                                      \
{                                                           \
    vmf_msg_base_t      msg_base;                           \
    struct {                                                \
        unsigned16          length;                         \
        unsigned8           pl[(VAR_DATA_LEN + VMF_BASIC_MSG_NEAR_DATA_LENGTH)];             \
    }data;                                                  \
}

/*! \struct VMF_VAR_MSG_TYP
 *   vmf variabe size message */
#define VMF_VAR_MSG_TYP(VAR_DATA_LEN)                       \
struct                                                      \
{                                                           \
    union {                                                 \
        VMF_VAR_MOST_MSG_TYP(VAR_DATA_LEN)   vmf_most_msg;  \
        VMF_VAR_BASIC_MSG_TYP(VAR_DATA_LEN)  vmf_basic_msg; \
    };                                                      \
}


/*! standard sized general VMF message type */
typedef VMF_VAR_MSG_TYP(VMF_CLIENT_DATA_SIZE_SMALL)          vmf_msg_small_t;
typedef VMF_VAR_MSG_TYP(VMF_CLIENT_DATA_SIZE_STANDARD)       vmf_msg_std_t;
typedef VMF_VAR_MSG_TYP(VMF_CLIENT_DATA_SIZE_BIG)            vmf_msg_big_t;
typedef vmf_msg_std_t                                        vmf_msg_t;

/*! standard sized VMF MOST message type */
typedef VMF_VAR_MOST_MSG_TYP(VMF_CLIENT_DATA_SIZE_SMALL)     vmf_most_msg_small_t;
typedef VMF_VAR_MOST_MSG_TYP(VMF_CLIENT_DATA_SIZE_STANDARD)  vmf_most_msg_std_t;
typedef VMF_VAR_MOST_MSG_TYP(VMF_CLIENT_DATA_SIZE_BIG)       vmf_most_msg_big_t;
typedef vmf_most_msg_std_t                                   vmf_most_msg_t;

/*! standard sized VMF basic message type */
typedef VMF_VAR_BASIC_MSG_TYP(VMF_CLIENT_DATA_SIZE_SMALL)    vmf_basic_msg_small_t;
typedef VMF_VAR_BASIC_MSG_TYP(VMF_CLIENT_DATA_SIZE_STANDARD) vmf_basic_msg_std_t;
typedef VMF_VAR_BASIC_MSG_TYP(VMF_CLIENT_DATA_SIZE_BIG)      vmf_basic_msg_big_t;
typedef vmf_basic_msg_std_t                                  vmf_basic_msg_t;

#pragma pack(pop)

#endif /* VMF_TYPES__H_ */
