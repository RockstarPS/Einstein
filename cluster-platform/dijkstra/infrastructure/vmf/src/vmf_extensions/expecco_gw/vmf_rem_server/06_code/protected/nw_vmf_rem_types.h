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
*  MODULE NAME  :  nw_vmf_rem_client.h                                               *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   16th Feb 2009                                            *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  types used by the Visteon message framework                    *
******************************************************************************/
#ifndef VMF_REMOTE_CLIENT__H_
#define VMF_REMOTE_CLIENT__H_


#define VMF_REM_MAX_DATA_SIZE       (2000)          /* limit the maximum data size of a remote message */

#pragma pack(push,4)

/* enums */
/*! remote-vmf rpc identifier */
enum
{    
    VMF_RPC_FKT_CONNECT    =1,                  /* nw_vmf_connect */
    VMF_RPC_FKT_CONNECT_ASYNC,                  /* nw_vmf_connect_async */
    VMF_RPC_FKT_REGISTER_EXT_MOST_LINK,         /* nw_vmf_register_ext_most_link */
    VMF_RPC_FKT_REGISTER_SPY,                   /* nw_vmf_register_spy */
    VMF_RPC_FKT_REGISTER_MOST_FB,               /* nw_vmf_register_most_fblock */
    VMF_RPC_FKT_DEREGISTER_MOST_FB,             /* nw_vmf_de_register_most_fblock */
    VMF_RPC_FKT_REGISTER_MOST_SHAD,             /* nw_vmf_register_most_shadow */
    VMF_RPC_FKT_DEREGISTER_MOST_SHAD,           /* nw_vmf_deregister_most_shadow */
    VMF_RPC_FKT_REGISTER_MSG_GRP,               /* nw_vmf_register_msg_group */
    VMF_RPC_FKT_DEREGISTER_MSG_GRP,             /* nw_vmf_deregister_msg_group */
    VMF_RPC_FKT_SEND_MOST_ASYNC,                /* nw_vmf_send_most_async */
    VMF_RPC_FKT_SEND_MOST_CTRL,                 /* nw_vmf_send_most_ctrl */
    VMF_RPC_FKT_SEND_BASIC,                     /* nw_vmf_send_basic */
    VMF_RPC_FKT_SEND,                           /* nw_vmf_send */
    VMF_RPC_FKT_RECEIVE,                        /* nw_vmf_receive */
    VMF_RPC_FKT_TIMED_RECEIVE,                  /* nw_vmf_timed_receive */
    VMF_RPC_FKT_DISCONNECT                      /* nw_vmf_disconnect */

    #if 0 /* not fully implemented yet as of nw_43 */
    ,VMF_RPC_FKT_BLOCK_RECEIVE                   /* endless nw_vmf_receive */
    #endif    
};



/*! general vmf return type */
typedef unsigned8        rpc_id_type;


/*! endian save 16 bit type */
typedef struct
{
    union 
    {
        unsigned16        length;                    /* lenth if payload */
        struct
        {
            unsigned8    length_l;
            unsigned8    length_h;
        };
    };
}length16_t;




/******************************************************
*       remote-vmf-message type
*******************************************************/



/*! rpc data for nw_vmf_connect() */
typedef struct
{
    char                process_name[20];          /* process name */
    length16_t          message_queue_lenght;      /* no messages in msg queue */
    length16_t          message_queue_msg_size;    /* size of a message in message queue*/
}vmf_rpc_connect_t;


/*! rpc data for register_ext_most_link and register_spy */
typedef struct
{
    char                dummy;
}vmf_rpc_reg_t;



/*! rpc data for register_fblock, deregister_fblock and deregister_shadow */
typedef struct
{
    unsigned8           fBlockId;                /* FBlock ID */
    unsigned8           instId;                    /* Instant ID */
}vmf_rpc_reg_fblock_t;



/*! rpc data for register_shadow  */
typedef struct
{
    unsigned8           fBlockId;                    /* FBlock ID */
    unsigned8           instId;                        /* Instant ID */
    length16_t          fcIds_num;                    /* number of function ID's in list */
    length16_t          funcIds[1];                    /* function ID list */
}vmf_rpc_reg_shadow_t;



/*! rpc data for register_msg_group  and deregister_msg_group */
typedef struct
{
    unsigned8           grps_num;                    /* number of function groups in list */
    unsigned8           grps[1];                    /* groups list */
}vmf_rpc_reg_msg_group_t;



/*! rpc data for nw_vmf_send_most_async, nw_vmf_send_most_control */
typedef struct
{
    VMF_VAR_MOST_MSG_TYP(VMF_REM_MAX_DATA_SIZE)        vmf_most_msg;                /* vmf_message */
}vmf_rpc_send_most_t;



/*! rpc data for nw_vmf_send_basic_msg*/
typedef struct
{
    VMF_VAR_BASIC_MSG_TYP(VMF_REM_MAX_DATA_SIZE)        vmf_basic_msg;                /* vmf_message */
}vmf_rpc_send_basic_t;


/*! rpc data for nw_vmf_send_msg*/
typedef struct
{
    VMF_VAR_MSG_TYP(VMF_REM_MAX_DATA_SIZE)            vmf_msg;                    /* vmf_message */
}vmf_rpc_send_t;



/*! rpc data for nw_vmf_receive() */
typedef struct
{
    length16_t            vmf_msg_length;              /* max size of vmf message */
}vmf_rpc_receive_t;


/*! rpc data for nw_vmf_timed_receive() */
typedef struct
{
	length16_t            vmf_msg_length;              /* max size of vmf message */
	unsigned16			  timeout_ms;					/* timeout for timed receive */
}vmf_rpc_timed_receive_t;


/*! rpc message type */
#pragma pack(push,1)
typedef struct
{
    length16_t            msg_length;                    /* lenth of of total message (including msg_length)*/
    rpc_id_type         rpc_id;                        /* rpc function id */
    vmf_client_id_t     r_cid;                        /* remote client id */
    union 
    {
        vmf_rpc_connect_t           rpc_connect;            /* data for connect api */
        vmf_rpc_reg_t               rpc_reg_ext_most;        /* data for register.. apis */
        vmf_rpc_reg_fblock_t        rpc_reg_fblock;            /* data for register fblock */
        vmf_rpc_reg_shadow_t        rpc_reg_shadow;            /* data for register shadow */
        vmf_rpc_reg_msg_group_t     rpc_reg_group;            /* data for register msg group */
        vmf_rpc_send_most_t         rpc_send_most;            /* nw_vmf_send_most_...  */
        vmf_rpc_send_basic_t        rpc_send_basic;            /* nw_vmf_send_basic  */
        vmf_rpc_send_t              rpc_send;                /* nw_vmf_send  */
        vmf_rpc_receive_t           rpc_receive;            /* nw_vmf_receive  */
		vmf_rpc_timed_receive_t		rpc_timed_receive;		/* nw_vmf_timed_receive */
    };
}vmf_rpc_msg_t;
#pragma pack(pop)

/* size of vmf_rpc_msg_t header */
#define GET_VMF_RPC_HEADER_LENGTH   (sizeof(length16_t)+sizeof(rpc_id_type)+sizeof(vmf_client_id_t))

/*! rpc response type */
#pragma pack(push,1)
typedef struct
{
    length16_t          msg_length;                    /* length of payload */
    rpc_id_type         rpc_id;                        /* rpc function id */
    vmf_client_id_t     r_cid;                        /* remote client id */
    vmf_error_t         response;                    /* rpc response */
    VMF_VAR_MSG_TYP(0)  vmf_msg;                    /* received message (only used for nw_vmf_receive) */
}vmf_rpc_response_t;
#pragma pack(pop)



#pragma pack(pop)

#endif


