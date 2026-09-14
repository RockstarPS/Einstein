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
/*                                                                            *
*******************************************************************************
*  PROJECT NAME :  VMF_TRACE                                                  *
*******************************************************************************
*  MODULE NAME  :  vmf_trace.h                                                *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :  13 July 2009                                              *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  types used by VMF_TRACE                                                    *
******************************************************************************/
#ifndef __VMF_TRACE_H
#define __VMF_TRACE_H


/* definitions */
#define VMF_TRACE_TRID_INVALID      (0)         /* TRID 0 = invalid vor single trid */
#define VMF_TRID_VMF                (1)         /* TRID 1 = VMF */
#define VMF_TRACE_GLOBAL_ACTIVE     (FALSE)
#define VMF_TRACE_DEF_SEVERITY      (19)        /* default severity */
#define VMF_TRACE_DEF_SEVERITY_VMF  (19)
#define VMF_TRACE_MSG_DELIMITER     "¦"
#define VMF_TRACE_PL_LAST_MSG       0xa1
#define VMF_TRACE_PL_MSG            0xa0

/* Events for VMF_TRACE_OUT and VMF_TRACE_IN */
#define VMF_TRACE_MSG_TYPE_TEXT     0
#define VMF_TRACE_MSG_TYPE_HEX      1
#define VMF_TRACE_MSG_TYPE_SHM      2

#define FREE_OFFSET                 2
#define GET_TPL_LEN(tpl)    (size_t)(sizeof(vmf_trace_pl_header_t) + (tpl)->tpl_len)
#define MAX_VMF_TRACE_CORE_TRIDS    30      /* trids per core */
#define MAX_VMF_TRACE_TRIDS         (2*MAX_VMF_TRACE_CORE_TRIDS)

#if ( VS_MICRO_CORE_M4 == VS_MICRO_CORE )
#define MIN_CORE_TRID               (MAX_VMF_TRACE_CORE_TRIDS+FREE_OFFSET)
#define MAX_CORE_TRID               (2*MAX_VMF_TRACE_CORE_TRIDS)
#else
#define MIN_CORE_TRID               (FREE_OFFSET)
#define MAX_CORE_TRID               (MAX_VMF_TRACE_CORE_TRIDS)
#endif



#define MAX_VMF_TRACE_PL_LEN        (250)
#define MAX_TRACE_NAME_LEN          (10)
#define MAX_TRACE_TASK_NAME_LEN     (30)
#define MAX_TRACE_SCOPE_LEN         (30)
#define MAX_TRACE_MSG_LEN           (MAX_VMF_TRACE_PL_LEN - (MAX_TRACE_NAME_LEN + MAX_TRACE_TASK_NAME_LEN + MAX_TRACE_SCOPE_LEN))
#define MAX_VMF_TRACE_HEX_LEN       (MAX_VMF_TRACE_PL_LEN/3)

#define VMF_SHM_VALID_KEY           (0x55aa)

/* trace macros */

#ifdef VMF_TRACE
    #define VMF_TRACE_REGISTER(handle,name)             vmf_trace_register(handle,name)
    #define VMF_TRACE_REGISTER_C(handle,name,time)      vmf_trace_register_c(handle,name,time)
    #define VMF_TRACE_REGISTER_Z(handle,name)           vmf_trace_register_c(handle,name,0)
    #define VMF_TRACE_PRINT(a,b,c,d,e)                  vmf_trace(a,b,c,d,e)
    #define VMF_TRACE_PRINTF(a,b,c,d,e,...)             vmf_trace_printf(a,b,c,d,e,##__VA_ARGS__)
    #define VMF_TRACE_HEX(a,b,c,d,e,f)                  vmf_trace_hex(a,b,c,d,e,f)
    #define VMF_TRACE_SET_SEVERITY(a,b)                 vmf_trace_set_severity(a,b)

#else
    #ifndef WIN32
        #define VMF_TRACE_REGISTER(a,b)                 (VMF_OK)
        #define VMF_TRACE_PRINT(a,b,c,d,e)
        #define VMF_TRACE_PRINTF(a,b,c,d,e,...)
        #define VMF_TRACE_HEX(a,b,c,d,e,f)
        #define VMF_TRACE_SET_SEVERITY(a,b)
    #else
        #define VMF_TRACE_REGISTER(a,b)                 (VMF_OK)
        #define VMF_TRACE_PRINT(a,b,c,d,e)
        #define VMF_TRACE_PRINTF(a,b,c,d,args...)
        #define VMF_TRACE_HEX(a,b,c,d,e,f)
        #define VMF_TRACE_SET_SEVERITY(a,b)
    #endif
#endif



/*! predefined severities */
#ifdef __cplusplus
typedef enum vmf_trace_severity_t
#else
enum
#endif
{
    /* errors */
    VMF_TRACE_SEVERITY_ERROR = 0,
    VMF_TRACE_SEVERITY_ERROR_1,
    VMF_TRACE_SEVERITY_ERROR_2,
    VMF_TRACE_SEVERITY_ERROR_3,
    VMF_TRACE_SEVERITY_ERROR_4,
    VMF_TRACE_SEVERITY_ERROR_5,
    VMF_TRACE_SEVERITY_ERROR_6,
    VMF_TRACE_SEVERITY_ERROR_7,
    VMF_TRACE_SEVERITY_ERROR_8,
    VMF_TRACE_SEVERITY_ERROR_9,
    VMF_TRACE_SEVERITY_ERROR_10,
    VMF_TRACE_SEVERITY_ERROR_11,
    VMF_TRACE_SEVERITY_ERROR_12,
    VMF_TRACE_SEVERITY_ERROR_13,
    VMF_TRACE_SEVERITY_ERROR_14,
    VMF_TRACE_SEVERITY_ERROR_15,
    VMF_TRACE_SEVERITY_ERROR_16,
    VMF_TRACE_SEVERITY_ERROR_17,
    VMF_TRACE_SEVERITY_ERROR_18,
    VMF_TRACE_SEVERITY_ERROR_19,

    /* warnings */
    VMF_TRACE_SEVERITY_WARNING = 30,
    VMF_TRACE_SEVERITY_WARNING_1,
    VMF_TRACE_SEVERITY_WARNING_2,
    VMF_TRACE_SEVERITY_WARNING_3,
    VMF_TRACE_SEVERITY_WARNING_4,
    VMF_TRACE_SEVERITY_WARNING_5,
    VMF_TRACE_SEVERITY_WARNING_6,
    VMF_TRACE_SEVERITY_WARNING_7,
    VMF_TRACE_SEVERITY_WARNING_8,
    VMF_TRACE_SEVERITY_WARNING_9,
    VMF_TRACE_SEVERITY_WARNING_10,
    VMF_TRACE_SEVERITY_WARNING_11,
    VMF_TRACE_SEVERITY_WARNING_12,
    VMF_TRACE_SEVERITY_WARNING_13,
    VMF_TRACE_SEVERITY_WARNING_14,
    VMF_TRACE_SEVERITY_WARNING_15,
    VMF_TRACE_SEVERITY_WARNING_16,
    VMF_TRACE_SEVERITY_WARNING_17,
    VMF_TRACE_SEVERITY_WARNING_18,
    VMF_TRACE_SEVERITY_WARNING_19,

    /* trace messages */
    VMF_TRACE_SEVERITY_INFO = 60,
    VMF_TRACE_SEVERITY_INFO_1,
    VMF_TRACE_SEVERITY_INFO_2,
    VMF_TRACE_SEVERITY_INFO_3,
    VMF_TRACE_SEVERITY_INFO_4,
    VMF_TRACE_SEVERITY_INFO_5,
    VMF_TRACE_SEVERITY_INFO_6,
    VMF_TRACE_SEVERITY_INFO_7,
    VMF_TRACE_SEVERITY_INFO_8,
    VMF_TRACE_SEVERITY_INFO_9,
    VMF_TRACE_SEVERITY_INFO_10,
    VMF_TRACE_SEVERITY_INFO_11,
    VMF_TRACE_SEVERITY_INFO_12,
    VMF_TRACE_SEVERITY_INFO_13,
    VMF_TRACE_SEVERITY_INFO_14,
    VMF_TRACE_SEVERITY_INFO_15,
    VMF_TRACE_SEVERITY_INFO_16,
    VMF_TRACE_SEVERITY_INFO_17,
    VMF_TRACE_SEVERITY_INFO_18,
    VMF_TRACE_SEVERITY_INFO_19,
    VMF_TRACE_SEVERITY_INFO_20
};


/* definition of standard severities that should be used */
#define VMF_TRACE_SEV_STD_ERROR     VMF_TRACE_SEVERITY_ERROR_19
#define VMF_TRACE_SEV_STD_WARNING   VMF_TRACE_SEVERITY_WARNING_19
#define VMF_TRACE_SEV_STD_INFO      VMF_TRACE_SEVERITY_INFO_19
#define VMF_TRACE_SEV_STD_HEX       VMF_TRACE_SEVERITY_INFO_20

#define VMF_TRACE_SEV_OTF_ERROR     VMF_TRACE_SEVERITY_ERROR_19
#define VMF_TRACE_SEV_OTF_WARNING   VMF_TRACE_SEVERITY_WARNING_19
#define VMF_TRACE_SEV_OTF_TRACE     VMF_TRACE_SEVERITY_INFO_19
#define VMF_TRACE_SEV_OTF_HEX       VMF_TRACE_SEVERITY_INFO_20



/*! vmf_trace shared memory description */
/*! vmf_trace task shared memory description */
typedef struct
{
    unsigned8           trace_active;               /* true if trace for this task is active */
    unsigned8           severity;                   /* messages with a severity-value equal or lower are traced */
    unsigned16          signals;                    /* used to signal events to the trace client */
    unsigned32          msg_num;                    /* message number  */
    char                name[MAX_TRACE_NAME_LEN+1]; /* unique name of a trace task */
}vmf_t_shm_task_t;

typedef struct
{
    unsigned16          valid;                      /* VMF_SHM_VALID_KEY if shared mem is valid */
    unsigned16          version;                    /* shared mem version */
 //   unsigned            gl_free_trid;               /* next free trace id - has to be unsigned because of atomic_add() */
    unsigned8           gl_trace_active;            /* true if trace is active */
    unsigned8           gl_trace_group;             /* Trace messages are send to this this event group  */
    unsigned8           gl_startup_q;               /* true if startup Q-ing is enabled */
    vmf_t_shm_task_t    task[MAX_VMF_TRACE_TRIDS+1];
}vmf_trace_shm_t;


/*! VMF_TRACE_CTRL_FILTER_SET, VMF_TRACE_CTRL_FILTER_RESP  - vmf trace ctrl - filter for severity */
typedef struct
{
    unsigned8           trid;                       /* trace id or 0x00 for all Trace-IDs */
    unsigned8           severity;                   /* trace only messages with a severity >=  */
    unsigned8           trace_active;               /* 0x01 if trace for this trace_trid is enabled */
    unsigned8           fill;                       /* fill byte */
    char                name[MAX_TRACE_NAME_LEN+1]; /* trid name of a trace task */
}vmf_trace_ctrl_filter_severity_t;


/*! VMF_TRACE_CTRL_REG_CLIENT - register a trace client */
typedef struct
{
    unsigned8           trid;                       /* trace id            */
    char                name[MAX_TRACE_NAME_LEN+1]; /* unique name of a trace task */
}vmf_trace_ctrl_reg_client_t;



typedef vmf_trace_ctrl_filter_severity_t    vmf_trace_ctrl_filter_response_t;

typedef struct
{
    unsigned8           enable;                     /* 0x00 if queue disabled  */
                                                    /* 0x01 if queue enabled   */
}vmf_trace_ctrl_startup_q_t;

/*! vmf trace ctrl payload inside a vmf basic-messsage */
typedef struct
{
    union
    {
        vmf_trace_ctrl_reg_client_t         reg_client;     /* VMF_TRACE_CTRL_REG_CLIENT */
        vmf_trace_ctrl_filter_severity_t    flt_severity;   /* VMF_TRACE_CTRL_SEVERITY_FILTER */
        vmf_trace_ctrl_filter_response_t    flt_response;   /* VMF_TRACE_CTRL_FILTER_RESP */
        vmf_trace_ctrl_startup_q_t          startup_q;      /* VMF_TRACE_CTRL_STARTUP_Q_SET and RESP   */
    }u;
}vmf_trace_ctrl_pl_t;

#pragma pack(push,1)
typedef struct
{
    unsigned8           trid;                       /* trace id  */
    unsigned8           severity;                   /* message severity 0 = highest */
    unsigned8           sequence_type;              /* 0xa1 if last message in this payload else 0xa0 */
    unsigned8           fill;                       /* fill byte */
    unsigned32          num;                        /* task message number starting at 0 */
    unsigned32          msg_time;                   /* msg time in ms */
    unsigned16          tpl_len;                    /* trace payload length */
    char                tpl[MAX_VMF_TRACE_PL_LEN];  /* trace payload */
}vmf_trace_pl_t;

typedef struct
{
    unsigned8           trid;                       /* trace id  */
    unsigned8           severity;                   /* message severity 0 = highest */
    unsigned8           sequence_type;              /* 0xa1 if last message in this payload else 0xa0 */
    unsigned8           fill;                       /* fill byte */
    unsigned32          num;                        /* task message number starting at 0 */
    unsigned32          msg_time;                   /* msg time in ms */
    unsigned16          tpl_len;                    /* trace payload length */
}vmf_trace_pl_header_t;


typedef struct
{
    unsigned8           trid;                       /* trace id  */
    unsigned8           severity;                   /* message severity 0 = highest */
    unsigned8           sequence_type;              /* 0xa1 if last message in this payload else 0xa0 */
    unsigned8           fill;                       /* fill byte */
    unsigned32          num;                        /* task message number starting at 0 */
    unsigned32          msg_time;                   /* msg time in ms */
    unsigned16          tpl_len;                    /* trace message length */
    char                name[MAX_TRACE_NAME_LEN+1]; /* trid name of a trace task */
    char                task[MAX_TRACE_TASK_NAME_LEN]; /* task name */
    char                scope[MAX_TRACE_SCOPE_LEN]; /* scope */
    char                msg[MAX_TRACE_MSG_LEN];     /* msg */
}vmf_trace_shm_pl_t;


typedef struct
{
    unsigned8           trid;                       /* trace id  */
    unsigned8           severity;                   /* message severity 0 = highest */
    unsigned8           sequence_type;              /* 0xa1 if last message in this payload else 0xa0 */
    unsigned8           fill;                       /* fill byte */
    unsigned32          num;                        /* task message number starting at 0 */
    unsigned32          msg_time;                   /* msg time in ms */
    unsigned16          tpl_len;                    /* trace message length */
    char                name[MAX_TRACE_NAME_LEN+1]; /* trid name of a trace task */
    char                task[MAX_TRACE_TASK_NAME_LEN]; /* task name */
    char                scope[MAX_TRACE_SCOPE_LEN]; /* scope */
}vmf_trace_shm_header_pl_t;



#pragma pack(pop)

/* Macros */

#ifdef UNIT_TEST
#define NW_STATIC
#else
#define NW_STATIC   static
#endif


/*! vmf-trace-framework function declaration */
void        vmf_trace_server_pre_init(void);
vmf_ret_t   vmf_trace_register    (unsigned8 *trid,const char *trid_name);
vmf_ret_t   vmf_trace_register_c  (unsigned8 *ptrid,const char *trid_name,unsigned32 collector_timeout);
vmf_ret_t   vmf_trace             (unsigned8 trid,unsigned8 severity,const char *task,const char *scope,const char *message);
vmf_ret_t   vmf_trace_printf      (unsigned8 trid,unsigned8 severity,const char *task,const char *scope,const char *__format, ... );
vmf_ret_t   vmf_trace_hex         (unsigned8 trid,unsigned8 severity,const char *task,const char *scope,unsigned8 len,const unsigned8 *data);
vmf_ret_t   vmf_trace_set_severity(unsigned8 trid,unsigned8 severity);
vmf_ret_t   vmf_trace_filter      (unsigned8 trid,unsigned8 severity, unsigned8 trace_active);
vmf_ret_t   vmf_trace_send_ctrl(vmf_client_id_t trace_cid,unsigned8 event,vmf_trace_ctrl_pl_t *pl,unsigned16 len);
BOOL        vmf_trace_check_filter(unsigned8 trid,unsigned8 severity);

unsigned32  vmf_trace_get_time_in_ms(void);



#endif


