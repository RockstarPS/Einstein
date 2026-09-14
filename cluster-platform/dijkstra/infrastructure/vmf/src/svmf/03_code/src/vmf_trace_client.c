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
*  MODULE NAME  :  vmf_trace_client.c                                         *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :  31 March 2014                                              *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  vmf trace API                                                              *
******************************************************************************/
#define __VMF_TRACE_C
//#define CHECK_SHM_NULL

#include "vmf_app_util.h"
#include "vmf.h"
#include "vmf_ipc.h"
#include "vmf_client.h"
#include "vmf_trace.h"
#include "vmf_mqx_profiler.h"
#include "vmf_mcc.h"

#define VMF_TRACE_ERROR_PRINT(...)
#define VMF_TRACE_INFO_PRINT(...)
#define VMF_TRACE_WARNING_PRINT(...)

#define VMF_CLIENT_LOCK      {(void)vmf_mutex_lock(&vmf_tr_mux);}
#define VMF_CLIENT_UNLOCK    {(void)vmf_mutex_release(&vmf_tr_mux);}

int _sprintf(char *out, const char *format, ...);






/* module global variables */
static vmf_client_id_t  vmf_trace_cid=0;
static MUTEX_STRUCT     vmf_tr_mux;
static unsigned         gfree_trid=MIN_CORE_TRID;       /* next free trace id - has to be unsigned because of atomic_add() */


/* share memory */
#pragma language = extended
#pragma location = ".shared_ram"
#pragma segment  = ".shared_ram"
       vmf_trace_shm_t  vmf_trace_shm  @ ".shared_ram" ={0};
static vmf_trace_shm_t  *pvmf_trace_shm=&vmf_trace_shm;




/* local functions */
static unsigned8    vmf_trace_get_trid(vmf_trace_shm_t*,char *trid_name);
static vmf_ret_t    vmf_trace_init_shm(vmf_trace_shm_t* p_shm);
static vmf_ret_t    vmf_trace_ctrl_reg_client(vmf_client_id_t trace_cid,unsigned8 trid,const char *trid_name);
static vmf_ret_t    vmf_trace_send_msg(vmf_client_id_t trace_cid,unsigned8 trid,unsigned8 event,unsigned8 severity,const char *msg);
static vmf_ret_t    vmf_trace_store_trid_name(unsigned8 trid,const char* trid_name);
static unsigned8    vmf_trace_get_name_trid(vmf_trace_shm_t* p_shm,const char *trid_name);

static bool         vmf_trace_check_filter(unsigned8 trid,unsigned8 severity);
static BOOL         vmf_mutex_init(MUTEX_STRUCT *pmutex);
static BOOL         vmf_mutex_lock(MUTEX_STRUCT *pmutex);
static BOOL         vmf_mutex_release(MUTEX_STRUCT *pmutex);



/******************************************************************************/
/*                              global functions
/******************************************************************************/


/**************************************************************************//**
 *
 *   register a task with a unique trid-name at the vmf_trace server
 *
 *   \param[out]    trid *              (output)pointer to trace ID (trid)
 *   \param[in]     trid_name           (input)unique name (trid name) (max 10 characters including zero)
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t vmf_trace_register(unsigned8 *ptrid,const char *trid_name)
{
    vmf_ret_t ret_val = VMF_OK;

    /* argument check */
    if (NULL == ptrid)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_register ptrid=NULL",(int)getmypid());
        return VMF_ERR_NULL_POINTER;
    }
    if (NULL == trid_name)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_register trid_name=NULL",(int)getmypid());
        return VMF_ERR_NULL_POINTER;
    }
    VMF_TRACE_INFO_PRINT ("pid=%d,%s vmf_trace: vmf_trace_register()",(int)getmypid(),trid_name);

    /* check if connection to vmf server is already established */
    /* only a single connection to vmf-server is needed         */
    if (0 == vmf_trace_cid)          /* vmf_trace_cid is global */
    {
        /* init vmf_mcc */
#if ( VS_MICRO_CORE_M4 == VS_MICRO_CORE )
        vmf_mcc_init();
#endif
        /* init the shared memory */
        ret_val = vmf_trace_init_shm(&vmf_trace_shm);
        if (ret_val != VMF_OK)
        {
            /* an error occured */
            VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace_init_shm failed, ret_val=%d\n",(int)getmypid(),ret_val);
            return ret_val;
        }

        /* connect to vmf server */
        ret_val = nw_vmf_connect("vmf_trace",NULL,0,0,0);
        if (ret_val < 0)
        {
            /* an error occured */
            VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: nw_vmf_connect failed, ret_val=%d\n",(int)getmypid(),ret_val);
            return ret_val;
        }
        vmf_trace_cid = ret_val;
    }

    /* get a free trace id */
    *ptrid = vmf_trace_get_trid(pvmf_trace_shm,trid_name);
    if (VMF_TRACE_TRID_INVALID == *ptrid)
    {
            VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_get_trid failed\n",(int)getmypid());
            return VMF_ERROR;
    }

    VMF_TRACE_INFO_PRINT ("pid=%d,%s vmf_trace: trid=%d\n",(int)getmypid(),trid_name,*ptrid);

    ret_val = vmf_trace_store_trid_name(*ptrid,trid_name);
    if (VMF_OK != ret_val)
    {
        /* an error occured */
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_store_trid_name %s failed\n",(int)getmypid(),trid_name);
        return ret_val;
    }
    else
    {
        /* OK */
    }

    /* send registration to vmf_trace_server */
    ret_val = vmf_trace_ctrl_reg_client(vmf_trace_cid,*ptrid,trid_name);
    if (VMF_OK != ret_val)
    {
        /* an error occured */
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_send_ctrl failed err=%d\n",(int)getmypid(),ret_val);
        return ret_val;
    }
    return ret_val;
}


/**************************************************************************//**
 *
 *   sned hex trace data to trace framework
 *
 *   \param[in]     trid                Trace ID
 *   \param[in]     severity            trace message severity (0 = error)
 *   \param[in]     scope               scope name
 *   \param[in]     len                 length of hex data
 *   \param[in]     data                address of hex data
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t     vmf_trace_hex     (unsigned8 trid,unsigned8 severity,const char *task,const char *scope,unsigned8 len,unsigned8 *data)
{
    char trace_msg[MAX_VMF_TRACE_PL_LEN+1];
    char msg[(MAX_VMF_TRACE_HEX_LEN *3)+1];
    char *t;
    unsigned16  uCnt;
    char *ptrid_name;

    vmf_ret_t   ret_val;

    if (0 == trid)
    {
        return VMF_ERR_INVALID_ARG;
    }

    /* check if trace is allowed */
    if (vmf_trace_check_filter(trid,severity))
    {
        /* no trace*/
        return VMF_OK;
    }


    /* argument check */
    if ( NULL == task)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace_hex: vmf_trace() - pid=NULL\n",(int)getmypid());
        return VMF_ERR_INVALID_ARG;
    }

    if ( NULL == scope)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace_hex: vmf_trace() - scope=NULL\n",(int)getmypid());
        return VMF_ERR_INVALID_ARG;
    }


    if (NULL == data)
    {
        VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace_hex: VMF_ERR_NULL_POINTER data = NULL\n",(int)getmypid());
        return VMF_ERR_NULL_POINTER;
    }

#ifdef CHECK_SHM_NULL
    if (NULL == pvmf_trace_shm)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace_hex: VMF_ERR_NULL_POINTER vmf_trace_shm = NULL\n",(int)getmypid());
        return VMF_ERR_NULL_POINTER;
    }
#endif


    if (len > MAX_VMF_TRACE_HEX_LEN)
    {
        /* cut the length */
        len = MAX_VMF_TRACE_HEX_LEN;
    }

    /* send the trace message to the trace framework */

    /* build trace message */
    t = msg;
    for (uCnt = 0; uCnt < len; uCnt++)
    {
        t += snprintf(t,MAX_VMF_TRACE_HEX_LEN, "%02x ", data[uCnt]);
    }

    /* get trid name */
    ptrid_name = pvmf_trace_shm->task[trid].name;
    snprintf(trace_msg,MAX_VMF_TRACE_PL_LEN,"%s%s%s%s%s%s%s",ptrid_name,VMF_TRACE_MSG_DELIMITER,task,VMF_TRACE_MSG_DELIMITER, scope,VMF_TRACE_MSG_DELIMITER,msg);
    trace_msg[MAX_VMF_TRACE_PL_LEN]=0;      /* set delimiter */

    /* send the trace message to the trace framework */
    ret_val = vmf_trace_send_msg(vmf_trace_cid,trid,VMF_TRACE_MSG_TYPE_HEX,severity,trace_msg);
    if (VMF_OK != ret_val)
    {
        /* an error occured */
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_send_msg failed\n",(int)getmypid());
        return ret_val;
    }

    return ret_val;
}



/**************************************************************************//**
 *
 *   send trace message to trace framework
 *
 *   \param[in]     trid                Trace ID
 *   \param[in]     severity            trace message severity (0 = error)
 *   \param[in]     task                task name (this will be part of the tab name in the windows viewer)
 *   \param[in]     scope               scope name
 *   \param[in]     message             trace message
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t vmf_trace  (unsigned8 trid,unsigned8 severity,const char *task,const char *scope,const char *message)
{
    char trace_msg[MAX_VMF_TRACE_PL_LEN+1];
    vmf_ret_t   ret_val=VMF_OK;
    char *ptrid_name;

    if (0 == trid)
    {
        return VMF_ERR_INVALID_ARG;
    }

    /* check if trace is allowed */
    if (vmf_trace_check_filter(trid,severity))
    {
        /* no trace*/
        return VMF_OK;
    }

    /* argument check */
    if ( NULL == task)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace() - pid=NULL\n",(int)getmypid());
        return VMF_ERR_INVALID_ARG;
    }

    if ( NULL == scope)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace() - scope=NULL\n",(int)getmypid());
        return VMF_ERR_INVALID_ARG;
    }

    if ( NULL == message)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace() - message=NULL\n",(int)getmypid());
        return VMF_ERR_INVALID_ARG;
    }

#ifdef CHECK_SHM_NULL
    if (NULL == pvmf_trace_shm)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: VMF_ERR_NULL_POINTER vmf_trace_shm = NULL - task=%s, scope=%s, message=%s\n",(int)getmypid(),task,scope,message);
        return VMF_ERR_NULL_POINTER;
    }
#endif

    /* get trid name */
    ptrid_name = pvmf_trace_shm->task[trid].name;

    /* build trace message */
    snprintf(trace_msg,MAX_VMF_TRACE_PL_LEN,"%s%s%s%s%s%s%s",ptrid_name,VMF_TRACE_MSG_DELIMITER,task,VMF_TRACE_MSG_DELIMITER, scope,VMF_TRACE_MSG_DELIMITER,message);
    trace_msg[MAX_VMF_TRACE_PL_LEN]=0;      /* set delimiter */


    /* send the trace message to the trace framework */
    ret_val = vmf_trace_send_msg(vmf_trace_cid,trid,VMF_TRACE_MSG_TYPE_TEXT,severity,trace_msg);
    if (VMF_OK != ret_val)
    {
        /* an error occured */
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_send_msg failed\n",(int)getmypid());
        return ret_val;
    }

    return ret_val;
}

/**************************************************************************//**
 *
 *   send trace message to trace framework
 *   works like a printf
 *   \param[in]     trid                Trace ID
 *   \param[in]     severity            trace message severity (0 = error)
 *   \param[in]     task                task name (this will be part of the tab name in the windows viewer)
 *   \param[in]     scope               scope name
 *   \param[in]     message             trace message
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t   vmf_trace_printf  (unsigned8 trid,unsigned8 severity,const char *task,const char *scope,const char *format, ... )
{
    va_list             arglist;
    vmf_ret_t           vmf_ret;
    int                 msg_len;
    char                trace_msg[MAX_VMF_TRACE_PL_LEN+1];
    char                msg[MAX_VMF_TRACE_PL_LEN+1];
    char                *ptrid_name;
    vmf_mcc_msg_t       *pvmf_mcc_tx_msg;
    vmf_trace_shm_pl_t  *ptrace_shm_pl;
    vmf_msg_t           *pvmf_msg;

    if (0 == trid)
    {
        return VMF_ERR_INVALID_ARG;
    }

    /* check if trace is allowed */
    if (vmf_trace_check_filter(trid,severity))
    {
        /* no trace*/
        return VMF_OK;
    }

    /* argument check */
    if ( NULL == task)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace_printf: vmf_trace() - pid=NULL\n",(int)getmypid());
        return VMF_ERR_INVALID_ARG;
    }

    if ( NULL == scope)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace_printf: vmf_trace() - scope=NULL\n",(int)getmypid());
        return VMF_ERR_INVALID_ARG;
    }

    if (NULL == format)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace_printf: VMF_ERR_NULL_POINTER format arg = NULL\n",(int)getmypid());
        return VMF_ERR_NULL_POINTER;
    }

    va_start (arglist, format);
    msg_len = vsnprintf(msg, MAX_VMF_TRACE_PL_LEN, format, arglist);
    va_end (arglist);

#if ( VS_MICRO_CORE_M4 == VS_MICRO_CORE )
    vmf_ret = vmf_mcc_msg_pool_get(&pvmf_mcc_tx_msg);
    if (vmf_ret != VMF_OK)
    {
        /* no buffer available */
        return  vmf_ret;
    }
    ptrace_shm_pl = pvmf_mcc_tx_msg->vmf_msg.pl;

    /* create trace message */
    pvmf_msg = &(pvmf_mcc_tx_msg->vmf_msg);
    NW_VMF_BASIC_MSG_GROUP(pvmf_msg) = pvmf_trace_shm->gl_trace_group;
    NW_VMF_BASIC_MSG_EVENT(pvmf_msg) = VMF_TRACE_MSG_TYPE_SHM;

    memcpy(ptrace_shm_pl->name,pvmf_trace_shm->task[trid].name,MAX_TRACE_NAME_LEN);
    memcpy(ptrace_shm_pl->task,task,MAX_TRACE_TASK_NAME_LEN);
    memcpy(ptrace_shm_pl->scope,scope,MAX_TRACE_SCOPE_LEN);
    memcpy(ptrace_shm_pl->msg,msg,msg_len+1);
    ptrace_shm_pl->trid = trid;
    ptrace_shm_pl->severity = severity;
    ptrace_shm_pl->msg_time = vmf_trace_get_time_in_ms();
    ptrace_shm_pl->sequence_type = VMF_TRACE_PL_LAST_MSG;
    ptrace_shm_pl->tpl_len = msg_len+1;
    NW_VMF_BASIC_MSG_DATA_LENGTH(pvmf_msg) = sizeof(vmf_trace_shm_header_pl_t) + ptrace_shm_pl->tpl_len;


    /* atomic increment */
    VMF_CLIENT_LOCK
    ptrace_shm_pl->num = pvmf_trace_shm->task[trid].msg_num;
    pvmf_trace_shm->task[trid].msg_num+=1;
    VMF_CLIENT_UNLOCK
    vmf_ret = vmf_mcc_msg_q_put_msg(pvmf_mcc_tx_msg);

#else
    snprintf(trace_msg,MAX_VMF_TRACE_PL_LEN,"%s%s%s%s%s%s%s",pvmf_trace_shm->task[trid].name,VMF_TRACE_MSG_DELIMITER,task,VMF_TRACE_MSG_DELIMITER, scope,VMF_TRACE_MSG_DELIMITER,msg);
    /* send the trace message to the trace framework */
    vmf_ret = vmf_trace_send_msg(vmf_trace_cid,trid,VMF_TRACE_MSG_TYPE_TEXT,severity,trace_msg);
#endif


    if (VMF_OK != vmf_ret)
    {
        /* an error occured */
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace_send_msg failed\n",(int)getmypid());
    }
    else
    {
        VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace_send_msg: message=%s\n",(int)getmypid(),msg);
    }
    return vmf_ret;
}



/*******************************************************
 local functions
 *******************************************************/


/**************************************************************************//**
 *
 *   Function Name: vmf_trace_get_trid()
 *
 *   Description:   get a free trace signature
 *
 *   Parameters:
 *
 *   \return        unsigned8   free task id
 ******************************************************************************/
static unsigned8 vmf_trace_get_trid(vmf_trace_shm_t* vmf_trace_shm,const char *trid_name)
{
    unsigned8 lfree_trid=VMF_TRACE_TRID_INVALID;

/* search if a trace client with the same trid-name was already registered */

    if (NULL == vmf_trace_shm)
    {
        return VMF_TRACE_TRID_INVALID;
    }

    lfree_trid = vmf_trace_get_name_trid(vmf_trace_shm,trid_name);
    if (VMF_TRACE_TRID_INVALID == lfree_trid)
    {
        /* get a new trid for this connection name */
        VMF_CLIENT_LOCK
        lfree_trid = gfree_trid++;
        VMF_CLIENT_UNLOCK
    }

    if (gfree_trid >= MAX_CORE_TRID)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace:vmf_trace_get_trid() no free trid\n",(int)getmypid());
        gfree_trid = MAX_CORE_TRID;
        lfree_trid=VMF_TRACE_TRID_INVALID;
    }
    return lfree_trid;
}

 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_init_shm()
 *
 *   Description:   init the vmf_trace shared memory page
 *
 *   Parameters:
 *   \param[in]     p_shm                pointer to shared memory
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
static vmf_ret_t vmf_trace_init_shm(vmf_trace_shm_t* p_shm)
{
    unsigned8 cnt;

    if (NULL == p_shm)
    {
        return VMF_ERR_NULL_POINTER;
    }

    if ( p_shm->valid == VMF_SHM_VALID_KEY)
    {
        return VMF_OK;      /* already initialized */
    }

    if (FALSE == vmf_mutex_init(&vmf_tr_mux))
    {
        return VMF_ERR_MUX;
    }

    p_shm->valid=0;

    /* init the global shm */
    p_shm->gl_trace_active  = VMF_TRACE_GLOBAL_ACTIVE;
 //   p_shm->gl_startup_q     = vmf_trace_def_startup_q;

    p_shm->gl_trace_group   = VMF_TRACE_IN;     /* initial trace group */
    gfree_trid               = MIN_CORE_TRID;

    /* init the task shm */
    for (cnt=MIN_CORE_TRID; cnt<MAX_CORE_TRID ;cnt++)
    {
        p_shm->task[cnt].name[0]='\000';
        p_shm->task[cnt].trace_active = TRUE;  /* start with trace inactive */
        p_shm->task[cnt].severity = VMF_TRACE_DEF_SEVERITY;
        p_shm->task[cnt].signals = 0;
        p_shm->task[cnt].msg_num = 0;           /* clear the message counter */
    }

    /* pre-load for special clients */
    strncpy(p_shm->task[0].name,"init",MAX_TRACE_NAME_LEN);

    strncpy(p_shm->task[1].name,"vmf",MAX_TRACE_NAME_LEN);
    p_shm->task[1].severity = VMF_TRACE_DEF_SEVERITY_VMF;

    /* set chared memory to valid*/
    p_shm->valid = VMF_SHM_VALID_KEY;

    return VMF_OK;
}

 #if ( VS_MICRO_CORE_M4 == VS_MICRO_CORE )
/**************************************************************************//**
 *
 *   Function Name: vmf_trace_send_ctrl()
 *
 *   Description:   send a trace control message to trace server
 *                  M4 will send directly to vmf_mcc
 *   Parameters:
 *
 *   \param[in]     trace_cid   - trace client id
 *   \param[in]     event       - vmf event for VMF_TRACE_CTRL
 *   \param[in]     pl          - trace control payload
 *   \param[in]     len         - length of payload
 *   \return        vmf_ret_t    group
 ******************************************************************************/
vmf_ret_t vmf_trace_send_ctrl(vmf_client_id_t trace_cid,unsigned8 event,vmf_trace_ctrl_pl_t *pl,unsigned16 len)
{
    vmf_ret_t       vmf_ret = VMF_OK;
    vmf_mcc_msg_t   *vmf_mcc_tx_msg;
    vmf_msg_t       *pvmf_msg=NULL;

    VMF_VAR_MSG_TYP(sizeof(vmf_trace_ctrl_pl_t)) vmf_msg;

    /* argument check */
    if ( NULL == pl)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace_send_ctrl: pl=NULL\n",(int)getmypid());
        return VMF_ERR_INVALID_ARG;
    }
    else if (len > sizeof(vmf_trace_ctrl_pl_t))
    {
        return VMF_ERR_OUT_OF_RANGE;
    }

    /* get mcc buffer */
    vmf_ret = vmf_mcc_msg_pool_get(&vmf_mcc_tx_msg);
    if (vmf_mcc_tx_msg != NULL)
    {
        pvmf_msg = &vmf_mcc_tx_msg->vmf_msg;

        NW_VMF_BASIC_MSG_GROUP(pvmf_msg)    = VMF_TRACE_CTRL;
        NW_VMF_BASIC_MSG_EVENT(pvmf_msg)    = event;

        /* copy payload */
        NW_VMF_BASIC_MSG_DATA_LENGTH(pvmf_msg) = len;
        memcpy(NW_VMF_BASIC_MSG_DATA_PTR(pvmf_msg),pl, len);

        vmf_ret = vmf_mcc_msg_q_put_msg(vmf_mcc_tx_msg);
        if(vmf_ret < 0)
        {
            VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_send_ctrl-vmf_mcc_msg_q_put_msg failed - cid=%d\n",(int)getmypid(),trace_cid);
        }

    }
    else
    {
        /* ignore message */
        /* an error is logged in vmf_mcc_msg_pool_get() */
    }


    return vmf_ret;
}

#else
/**************************************************************************//**
 *
 *   Function Name: vmf_trace_send_ctrl()
 *
 *   Description:   send a trace control message to trace server
 *
 *   Parameters:
 *
 *   \param[in]     trace_cid   - trace client id
 *   \param[in]     event       - vmf event for VMF_TRACE_CTRL
 *   \param[in]     pl          - trace control payload
 *   \param[in]     len         - length of payload
 *   \return        vmf_ret_t    group
 ******************************************************************************/
vmf_ret_t vmf_trace_send_ctrl(vmf_client_id_t trace_cid,unsigned8 event,vmf_trace_ctrl_pl_t *pl,unsigned16 len)
{
    vmf_ret_t vmf_ret;

    VMF_VAR_MSG_TYP(sizeof(vmf_trace_ctrl_pl_t)) vmf_msg;

    /* argument check */
    if ( NULL == pl)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace_send_ctrl: pl=NULL\n",(int)getmypid());
        return VMF_ERR_INVALID_ARG;
    }
    else if (len > sizeof(vmf_trace_ctrl_pl_t))
    {
        return VMF_ERR_INVALID_ARG;
    }

    NW_VMF_BASIC_MSG_GROUP(&vmf_msg)    = VMF_TRACE_CTRL;
    NW_VMF_BASIC_MSG_EVENT(&vmf_msg)    = event;

    /* copy payload */
    NW_VMF_BASIC_MSG_DATA_LENGTH(&vmf_msg) = len;
    memcpy(NW_VMF_BASIC_MSG_DATA_PTR(&vmf_msg),pl, len);

    vmf_ret = nw_vmf_send_basic (trace_cid,(vmf_basic_msg_t*)&vmf_msg);
    if(vmf_ret < 0)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_send_ctrl-nw_vmf_send_basic failed - cid=%d\n",(int)getmypid(),trace_cid);
    }

    return vmf_ret;
}
#endif



 #if ( VS_MICRO_CORE_M4 == VS_MICRO_CORE )
/**************************************************************************//**
 *
 *   Function Name: vmf_trace_send_msg()
 *
 *   Description:   send a trace message as a VMF basic message
 *                  message is send directly to vmf_mcc
 *   Parameters:
 *
 *   \param[in]     trace_cid   - trace client id
 *   \param[in]     trid        - trace id
 *   \param[in]     event       - event
 *   \param[in]     severity    - severity 0 = highest
 *   \param[in]     msg         - zero terminated message string
 *
 *   \return        vmf_ret_t    group
 ******************************************************************************/
static vmf_ret_t vmf_trace_send_msg(vmf_client_id_t trace_cid,unsigned8 trid,unsigned8 event,unsigned8 severity,const char *msg)
{
    vmf_ret_t       vmf_ret=VMF_OK;
    vmf_msg_t       *pvmf_msg=NULL;
    vmf_mcc_msg_t   *vmf_mcc_tx_msg;
    vmf_trace_pl_t  trace_pl;

    vmf_ret = vmf_mcc_msg_pool_get(&vmf_mcc_tx_msg);
    if (vmf_mcc_tx_msg != NULL)
    {
        pvmf_msg = &vmf_mcc_tx_msg->vmf_msg;

        NW_VMF_BASIC_MSG_GROUP(pvmf_msg) = pvmf_trace_shm->gl_trace_group;
        NW_VMF_BASIC_MSG_EVENT(pvmf_msg) = event;

        /* create payload */
        trace_pl.trid = trid;
        trace_pl.severity = severity;
        trace_pl.msg_time = vmf_trace_get_time_in_ms();
        trace_pl.sequence_type = VMF_TRACE_PL_LAST_MSG;

        /* inc message counter */
        VMF_CLIENT_LOCK
        trace_pl.num = pvmf_trace_shm->task[trid].msg_num;
        pvmf_trace_shm->task[trid].msg_num+=1;
        VMF_CLIENT_UNLOCK

        /* copy trace message */
        if (NULL != msg)
        {
            trace_pl.tpl_len = strlen(msg);
            if (0x0a == msg[trace_pl.tpl_len-1])
            {
                trace_pl.tpl_len--;
            }
            strncpy(trace_pl.tpl,msg,trace_pl.tpl_len);
        }
        else
        {
            /* no message  */
            trace_pl.tpl_len = 0;
        }

        /* copy trace message to vmf payload */
        NW_VMF_BASIC_MSG_DATA_LENGTH(pvmf_msg) = GET_TPL_LEN(&trace_pl);
        memcpy(NW_VMF_BASIC_MSG_DATA_PTR(pvmf_msg),&trace_pl, NW_VMF_BASIC_MSG_DATA_LENGTH(pvmf_msg));
        vmf_ret = vmf_mcc_msg_q_put_msg(vmf_mcc_tx_msg);

        if(vmf_ret < 0)
        {
            VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_send_msg-vmf_mcc_msg_q_put_msg failed - cid=%d\n",(int)getmypid(),trace_cid);
        }
    }

    return vmf_ret;
}
#else
/**************************************************************************//**
 *
 *   Function Name: vmf_trace_send_msg()
 *
 *   Description:   send a trace message as a VMF basic message
 *
 *   Parameters:
 *
 *   \param[in]     trace_cid   - trace client id
 *   \param[in]     trid        - trace id
 *   \param[in]     event       - event
 *   \param[in]     severity    - severity 0 = highest
 *   \param[in]     msg         - zero terminated message string
 *
 *   \return        vmf_ret_t    group
 ******************************************************************************/
static vmf_ret_t vmf_trace_send_msg(vmf_client_id_t trace_cid,unsigned8 trid,unsigned8 event,unsigned8 severity,const char *msg)
{
    vmf_ret_t      vmf_ret;
    vmf_trace_pl_t trace_pl;

    VMF_VAR_MSG_TYP(sizeof(vmf_trace_pl_t)*3) vmf_msg;

#if 0
    if (NULL == pvmf_trace_shm)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_send_msg-shm pointer = NULL!\n",(int)getmypid());
        return VMF_ERR_NULL_POINTER;
    }
#endif

    NW_VMF_BASIC_MSG_GROUP(&vmf_msg) = pvmf_trace_shm->gl_trace_group;
    NW_VMF_BASIC_MSG_EVENT(&vmf_msg) = event;

    /* create payload */
    trace_pl.trid = trid;
    trace_pl.severity = severity;
    trace_pl.msg_time = vmf_trace_get_time_in_ms();
    trace_pl.sequence_type = VMF_TRACE_PL_LAST_MSG;

    /* inc message counter */
    VMF_CLIENT_LOCK
    trace_pl.num = pvmf_trace_shm->task[trid].msg_num;
    pvmf_trace_shm->task[trid].msg_num+=1;
    VMF_CLIENT_UNLOCK

    /* copy trace message */
    if (NULL != msg)
    {
        trace_pl.tpl_len = strlen(msg);
        if (0x0a == msg[trace_pl.tpl_len-1])
        {
            trace_pl.tpl_len--;
        }
        strncpy(trace_pl.tpl,msg,trace_pl.tpl_len);
    }
    else
    {
        /* no message  */
        trace_pl.tpl_len = 0;
    }

    /* copy trace message to vmf payload */
    NW_VMF_BASIC_MSG_DATA_LENGTH(&vmf_msg) = GET_TPL_LEN(&trace_pl);
    memcpy(NW_VMF_BASIC_MSG_DATA_PTR(&vmf_msg),&trace_pl, NW_VMF_BASIC_MSG_DATA_LENGTH(&vmf_msg));

    vmf_ret = nw_vmf_send_basic (trace_cid,(vmf_basic_msg_t*)&vmf_msg);
    if(vmf_ret < 0)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_send_msg-nw_vmf_send_basic failed - error=%d, cid=%d\n",(int)getmypid(),vmf_ret,trace_cid);
    }

    return vmf_ret;
}
#endif



/**************************************************************************//**
 *
 *   Function Name: vmf_trace_ctrl_reg_client()
 *
 *   Description:   send register client control message to trace server
 *
 *   Parameters:
 *
 *   \param[in]     trace_cid   - trace client id
 *   \param[in]     trid        - trace signature
 *   \param[in]     unique_name - unique name of the trace task
 *   \return        vmf_ret_t    group
 ******************************************************************************/
static vmf_ret_t vmf_trace_ctrl_reg_client(vmf_client_id_t trace_cid,unsigned8 trid,const char *trid_name)
{
    vmf_trace_ctrl_pl_t pl;
    vmf_ret_t           vmf_ret;

    VMF_TRACE_INFO_PRINT ("vmf_trace_ctrl_reg_client=%s, trid=%d\n",trid_name,trid);


    pl.u.reg_client.trid = trid;
    strncpy(pl.u.reg_client.name,trid_name,MAX_TRACE_NAME_LEN);
    pl.u.reg_client.name[MAX_TRACE_NAME_LEN]=0;

    vmf_ret = vmf_trace_send_ctrl(trace_cid,VMF_TRACE_CTRL_REG_CLIENT,&pl,sizeof(vmf_trace_ctrl_reg_client_t));
    return vmf_ret;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_trace_store_trid_name(char* name)
 *
 *   Description:   store the trid name in shm
 *
 *   Parameters:
 *
 *   \param[in]     trid    - trace id
 *   \return        vmf_ret_t
 ******************************************************************************/
static vmf_ret_t vmf_trace_store_trid_name(unsigned8 trid,const char* trid_name)
{

#if 0
    if (NULL == pvmf_trace_shm)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace:vmf_trace_store_trid_name() VMF_ERR_NULL_POINTER vmf_trace_store_trid_name() vmf_trace_shm = NULL\n",(int)getmypid());
        return VMF_ERR_NULL_POINTER;
    }
#endif

    if (trid >= MAX_CORE_TRID)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace:vmf_trace_store_trid_name() trid >=MAX_CORE_TRID\n",(int)getmypid());
        return VMF_ERR_OUT_OF_RANGE;
    }

    /* argument check */
    if ((0 == trid) || (trid > gfree_trid))
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: VMF_ERR_OUT_OF_RANGE vmf_trace_store_trid_name-shm free trid=%d\n",(int)getmypid(),free_trid);
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: VMF_ERR_OUT_OF_RANGE vmf_trace_store_trid_name-trid=%d\n",(int)getmypid(),trid);
        return VMF_ERR_OUT_OF_RANGE;
    }

    if (NULL == trid_name)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: VMF_ERR_NULL_POINTER tridname=NULL\n",(int)getmypid());
        return VMF_ERR_NULL_POINTER;
    }

    strncpy(pvmf_trace_shm->task[trid].name,trid_name,MAX_TRACE_NAME_LEN);

    VMF_TRACE_INFO_PRINT ("vmf_trace_store_trid_name=%s, trid=%d\n",trid_name,trid);
    return (VMF_OK);
}


/**************************************************************************//**
 *
 *   Function Name: vmf_trace_get_name_trid()
 *
 *   Description:   get the trid of a trid-name
 *
 *   Parameters:
 *
 *   \return        unsigned8    trid belonging to the trid-name or VMF_TRACE_TRID_INVALID
 ******************************************************************************/
static unsigned8 vmf_trace_get_name_trid(vmf_trace_shm_t* p_shm,const char *trid_name)
{
    unsigned16 cnt;
    unsigned8  trid=VMF_TRACE_TRID_INVALID;
    int        ret;

#if 0
    if (NULL == p_shm)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_get_name_trid- p_shm=NULL\n",(int)getmypid());
        return trid;
    }
#endif

    if (NULL == trid_name)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_get_name_trid- trid_name=NULL\n",(int)getmypid());
        return trid;
    }

    /* check if entry for this trid_name is present in persistent data */
    for (cnt=MIN_CORE_TRID; cnt<MAX_CORE_TRID ;cnt++)
    {
        /* precheck for speedup  */
        if ((p_shm->task[cnt].name[0] == trid_name[0]) &&
            (p_shm->task[cnt].name[1] == trid_name[1]))
        {
            /* compare*/
            ret = strncmp(p_shm->task[cnt].name,trid_name,MAX_TRACE_NAME_LEN);
            if (ret == 0)
            {
                /* found entry */
                /* copy persistent trid entry to shm */
                trid = cnt;
                break;
            }
        }
    }

    return trid;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_check_filter()
 *
 *   Description:   check if trace message is filtered
 *
 *   Parameters:
 *
 *   \param[in]     trid                trace signature
 *   \param[in]     severity            Message severity
 *   \return        bool                true if no trace
 *
 ******************************************************************************/
static BOOL vmf_trace_check_filter(unsigned8 trid,unsigned8 severity)
{
#ifdef CHECK_SHM_NULL
    if (NULL == pvmf_trace_shm)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace:vmf_trace_check_filter: VMF_ERR_NULL_POINTER vmf_trace_shm = NULL\n",(int)getmypid());
        return TRUE;
    }
#endif
    if (trid > MAX_CORE_TRID)
    {
        VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_check_filter() invalid trid=%d\n",(int)getmypid(),trid);
        return TRUE;
    }

    /* check if global trace is enabled */
    if (!pvmf_trace_shm->gl_trace_active)
    {
        /* trace is disabled */
        VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_check_filter() global trace disabled\n",(int)getmypid());
        return TRUE;
    }

    /* check if trace for this task is enabled */
    if (!pvmf_trace_shm->task[trid].trace_active)
    {
        /* trace is disabled */
        VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_check_filter() local trace disabled\n",(int)getmypid());
        return TRUE;
    }

    /* check if exactly  THIS severity is allowed (is bit 2^7 is set?)*/
    if (pvmf_trace_shm->task[trid].severity & 0x80)
    {
        if ((severity | 0x80) == pvmf_trace_shm->task[trid].severity)
        {
            /* allow exactly this severity */
            return FALSE;   /* do not filter this message !*/
        }
        /* bit 2^7 set in shm-severity but wrong severity - so ignore */
        else
        {
            /* ignore THIS severity */
            VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_check_filter() THIS severity disabled\n",(int)getmypid());
            return TRUE;
        }
    }

    /* check if message with this severity is ignored */
    if (severity > ((pvmf_trace_shm->task[trid].severity) & 0x7f))
    {
        /* ignore this severity */
        VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_check_filter() severity disabled severity=%d set-severity=%d\n",(int)getmypid(),severity,((vmf_trace_shm->task[trid].severity) & 0x7f));
        return TRUE;
    }

    return FALSE;   /* allow trace */
}



/*************************************************************************//**
 *
 *   init a mutex. \n
  *
 *   \param         pointer to mutex struct
 *   \return        true if OK
 *
 ******************************************************************************/
static BOOL vmf_mutex_init(MUTEX_STRUCT *pmutex)
{
            BOOL    bRet = TRUE;
    static  BOOL    inUse = FALSE;

    while(inUse)
    {
        nw_sleep_ms(0);
    }
    inUse = TRUE;

    if (_mutex_init(pmutex, NULL) != MQX_OK)
    {
        bRet = FALSE;
        VMF_TRACE_ERROR_PRINT("_mutex_init() failed");
    }

    inUse = FALSE;
    return bRet;
}


/*************************************************************************//**
 *
 *   lock a mutex. \n
  *
 *   \param         pointer to mutex struct
 *   \return        true if OK
 *
 ******************************************************************************/
static BOOL vmf_mutex_lock(MUTEX_STRUCT *pmutex)
{
    _mqx_uint ret_val;

    ret_val = _mutex_lock(pmutex);
    if (ret_val != MQX_EOK)
    {
        VMF_TRACE_ERROR_PRINT("_mutex_lock() failed, retval=%d",ret_val);
        return FALSE;
    }

    return TRUE;
}


/*************************************************************************//**
 *
 *   lock a mutex. \n
 *
 *   \param         pointer to mutex struct
 *   \return        true if OK
 *
 ******************************************************************************/
static BOOL vmf_mutex_release(MUTEX_STRUCT *pmutex)
{
    _mqx_uint ret_val;


    ret_val = _mutex_unlock(pmutex);
    if (ret_val != MQX_EOK)
    {
        VMF_TRACE_ERROR_PRINT("_mutex_unlock() failed, retval=%d",ret_val);
        return FALSE;
    }

    return TRUE;
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_filter()
 *
 *   Description:   set a client trace filter
 *
 *   Parameters:    pointer to shared mem
 *                  trid - trace id or 0 for all sigs
 *                  severity
 *                  trace_active -  0 if no trace message from this sig
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
vmf_ret_t vmf_trace_filter(unsigned8 trid,unsigned8 severity, unsigned8 trace_active)
{
    vmf_ret_t           vmf_ret=VMF_OK;
    vmf_trace_shm_t*    p_shm;

    p_shm = &vmf_trace_shm;

    if (trid > MAX_VMF_TRACE_TRIDS)
    {
        return VMF_ERR_OUT_OF_RANGE;
    }

    if (0 == trid)
    {
        /* set global filter - ignore severity */

        if (trace_active != 0)
        {
            p_shm->gl_trace_active = TRUE;
        }
        else
        {

            p_shm->gl_trace_active = FALSE;
        }
    }
    else
    {
        if (trace_active != 0)
        {
            p_shm->task[trid].trace_active = TRUE;      /* start with trace active */
        }
        else
        {
            p_shm->task[trid].trace_active = FALSE;     /* start with trace not active */
        }

        p_shm->task[trid].severity = severity;
    }

    return(vmf_ret);
}




/**************************************************************************//**
 *
 *   Function Name: vmf_trace_get_time_in_ms(void)
 *
 *   Description:   get time in ms
 *
 *   Parameters:    clocks
 *
 *   Function Return value: - time in ms
 *
 ******************************************************************************/
unsigned32 vmf_trace_get_time_in_ms(void)
{
    return nw_vmf_ipc_get_ms_time();
}



