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
*  PROJECT NAME :  VMF_TRACE_SERVER                                           *
*******************************************************************************
*  MODULE NAME  :  vmf_trace_server.h                                         *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :  13 July 2009                                               *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  definitions used by VMF_TRACE_SERVER                                       *
******************************************************************************/
#ifndef __VMF_TRACE_SERVER_H
#define __VMF_TRACE_SERVER_H

#include "intEvtDefs.h"
#include "nw_vmf_ipc.h"

/* Events for VMF_TRACE_OUT and VMF_TRACE_IN */
#define VMF_TRACE_MSG_TYPE_TEXT     0
#define VMF_TRACE_MSG_TYPE_HEX      1

/*! vmf_trace limits */
#define MAX_VMF_TRACE_PL_LEN        (250)
#define MAX_VMF_TRACE_TASK_NAME_LEN (50)
#define VMF_SHM_VALID_KEY           (0x55aa)
#define MIN_VMF_TRACE_TRID          (1)         /* TID 0 = for all TIDS */
#define MAX_VMF_TRACE_TRIDS         MAX_IPC_CHANNELS    // (50)
#define MAX_VMF_TRACE_HEX_LEN       (200/3)
#define MAX_TRACE_NAME_LEN          (10)

#define VMF_TRACE_WAIT_SOME_TIME    (20)        /* time in ms */
#define VMF_TRACE_WAIT_SHM_TIMEOUT  (60000)      /* SHM timeout in ms */

/*! vmf_trace defaults */
#define VMF_TRACE_DEF_SEVERITY_VMF  (VMF_TRACE_SEV_STD_ERROR)  /* default: for vmf  */
#define VMF_TRACE_DEF_SEVERITY      (VMF_TRACE_SEV_STD_ERROR)  /* default: show error messages only */
#define VMF_TRACE_DEF_GLOBAL_ACTIVE (true)                     /* default for global tracer switch  */
#define VMF_TRACE_DEF_TRID_ACTIVE   (true)                     /* default for trid trace switches   */
#define VMF_TRACE_DEF_STARTUP_Q     (true)                     /* default startup queue switch      */

#ifdef __WINDOWS__ 
#define VMF_TRACE_SEM               "vmf_trace_sem"
#define VMF_TRACE_SHM               "vmf_trace_shm"
#elif defined __ANDROID__
#define VMF_TRACE_SEM               "/dev/vmf_trace_sem"
#define VMF_TRACE_SHM               "/dev/vmf_trace_shm"
#elif defined INTEGRITY
#define VMF_TRACE_SEM               "/opt/viston/vmf_trace_sem"
#define VMF_TRACE_SHM               "/opt/viston/vmf_trace_shm"
#else
#define VMF_TRACE_SEM               "/vmf_trace_sem"
#define VMF_TRACE_SHM               "/vmf_trace_shm"
#endif

#define VMF_SHM_VERSION             0x0004

//VMF_TRACE_MSG_DELIMITER     "¦" (ASCII 0xA6)
#define VMF_TRACE_MSG_DELIMITER     "\xA6"
#define VMF_TRACE_MSG_DELIMITER_C   '\xA6'


#define VMF_TRACE_ERROR_PRINT(args...)      (void)fprintf(ERROR_CHANNEL,"error:");(void)fprintf(ERROR_CHANNEL,args);(void)fprintf(ERROR_CHANNEL,"\n");delay(100);
#define VMF_TRACE_INFO_PRINT(args...)       // (void)fprintf(ERROR_CHANNEL,"error:");(void)fprintf(ERROR_CHANNEL,args);(void)fprintf(ERROR_CHANNEL,"\n");delay(100);


#pragma pack(push,4)

/* trace message format */
/*  message example                                                                             */
/*  message format                                                                              */
/*  trid_name.task.scope:<message text >                                                        */
/*  nw.NW_NHI_Default.NHI:Rx grouId = 28, eventId = 200                                         */
/*  trid_name:  unique identifier of a task; range 00-ff                                        */
/*  task:       unique identifier of a task; range 00-ff                                        */
/*  scope:      error scope: example: NW_NHI_Default                                            */
/*  severit:    2 bytes hex digit;  range 00-ff;    00= highest severity (error)                */
/*  <message text>: maximum length 240 characters:                                              */

/*! vmf trace payload inside a vmf basic-messsage */
#define VMF_TRACE_PL_LAST_MSG 0xa1
#define VMF_TRACE_PL_MSG 0xa0
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


//#define GET_TPL_LEN(tpl)  ((sizeof(vmf_trace_pl_t)-MAX_VMF_TRACE_PL_LEN)+ (tpl)->tpl_len + 3)
#define GET_TPL_LEN(tpl)    (size_t)((sizeof(vmf_trace_pl_t)-MAX_VMF_TRACE_PL_LEN)+ (tpl)->tpl_len)


/*! VMF_TRACE_CTRL_REG_CLIENT - register a trace client */
typedef struct
{
    unsigned8           trid;                       /* trace id            */
    char                name[MAX_TRACE_NAME_LEN+1]; /* unique name of a trace task */
}vmf_trace_ctrl_reg_client_t;


/*! VMF_TRACE_CTRL_FILTER_SET, VMF_TRACE_CTRL_FILTER_RESP  - vmf trace ctrl - filter for severity */
typedef struct
{
    unsigned8           trid;                       /* trace id or 0x00 for all Trace-IDs */
    unsigned8           severity;                   /* trace only messages with a severity >=  */
    unsigned8           trace_active;               /* 0x01 if trace for this trace_trid is enabled */
    unsigned8           fill;                       /* fill byte */
    char                name[MAX_TRACE_NAME_LEN+1]; /* trid name of a trace task */
}vmf_trace_ctrl_filter_severity_t;


typedef vmf_trace_ctrl_filter_severity_t    vmf_trace_ctrl_filter_response_t;


/*! VMF_TRACE_CTRL_STARTUP_Q - enable or disable the startup queue */
#define STARTUP_Q_DIS 0x00
#define STARTUP_Q_ENA 0x01

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
    };
}vmf_trace_ctrl_pl_t;



/***********************************************/
/*                 shared memory               */
/***********************************************/

/*! vmf_trace task shared memory description */
typedef struct
{
    unsigned8           trace_active;               /* true if trace for this task is active */
    unsigned8           severity;                   /* messages with a severity-value equal or lower are traced */
    unsigned16          signals;                    /* used to signal events to the trace client */
    unsigned32          msg_num;                    /* message number  */
    char                name[MAX_TRACE_NAME_LEN+1]; /* unique name of a trace task */
}vmf_t_shm_task_t;


/*! vmf_trace shared memory description */
typedef struct
{
    unsigned16          valid;                      /* VMF_SHM_VALID_KEY if shared mem is valid */
    unsigned16          version;                    /* shared mem version */
    unsigned            gl_free_trid;               /* next free trace id - has to be unsigned because of atomic_add() */
    unsigned8           gl_trace_active;            /* true if trace is active */
    unsigned8           gl_trace_group;             /* Trace messages are send to this this event group  */
    unsigned8           gl_startup_q;               /* true if startup Q-ing is enabled */
    vmf_t_shm_task_t    task[MAX_VMF_TRACE_TRIDS+1];
}vmf_trace_shm_t;


#pragma pack(pop)


/* trace severities in ini file */
typedef struct
{
    unsigned8   severity;
    char        name[MAX_TRACE_NAME_LEN+1];
} vmf_ini_trace_severity_t;


#ifndef VMF_TRACE_SERVER_C
extern bool trace_sync;
#endif


/* Macros */
#define VMF_TRACE_SERVER_ERROR_PRINT(args...)              (void)fprintf(ERROR_CHANNEL,"Trace-Server Error: ");(void)fprintf(ERROR_CHANNEL,args);(void)fprintf(ERROR_CHANNEL,"\n");(void)fflush(ERROR_CHANNEL);
#define VMF_TRACE_SERVER_INFO_PRINT(args...)               // (void)fprintf(ERROR_CHANNEL,"Trace-Server Info : ");(void)fprintf(ERROR_CHANNEL,args);(void)fprintf(ERROR_CHANNEL,"\n");(void)fflush(ERROR_CHANNEL);
#define VMF_TRACE_SERVER_INFO_PRINT2(args...)              // (void)fprintf(ERROR_CHANNEL,"Trace-Server Info : ");(void)fprintf(ERROR_CHANNEL,args);(void)fprintf(ERROR_CHANNEL,"\n");(void)fflush(ERROR_CHANNEL);


/* function prototypes */
vmf_ret_t   vmf_trace_server_create_thread(void);
vmf_ret_t   vmf_trace_send_ctrl(vmf_client_id_t trace_cid,unsigned8 event,vmf_trace_ctrl_pl_t *pl,unsigned16 len);
vmf_ret_t   vmf_trace_set_def_severity(unsigned8 severity);
vmf_ret_t   vmf_trace_set_def_startup_queue(bool st_queue_enabled);
unsigned8   vmf_trace_server_startup_q_status(void);


#endif
