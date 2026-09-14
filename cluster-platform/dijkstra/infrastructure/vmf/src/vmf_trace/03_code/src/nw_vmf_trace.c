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
*  MODULE NAME  :  vmf_trace.c                                                *
*  AUTHOR NAME  :  jbecke30                                                   *
*******************************************************************************
*  MODULE DATE  :   13 July 2009                                              *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  VMF_TRACE                                                                  *
******************************************************************************/

/***************************************************************************

  Module:               nw_vmf_trace.c
  Description:          Main functions for the vmf trace lib

  Project Scope:        Fisker

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   gcc
  Target Hardware:      Any

  *****************************************************************************/
#define VMF_TRACE_C

#ifdef VMF_TRACE
#include "nw_os_config.h"
//#include "nw_vmf_debug.h"
#include "nw_vmf.h"
#include "nw_vmf_trace_server.h"
#include "nw_vmf_trace.h"


/* shared memory page */
NW_STATIC  vmf_trace_shm_t     *vmf_trace_shm=NULL;


/* local timeouts */
#define MAX_SHM_COUNT       100             /* max retries connecting to shm - value is not critical*/
#define VMF_TRACE_COL_TIME  100             /* collect time for vmf trace messages to server */

/* global variables */
NW_STATIC  vmf_client_id_t  vmf_trace_cid=0;

/* local functions */
static vmf_ret_t            vmf_trace_open_shm(void);
static unsigned32           getmypid(void);
static unsigned8            vmf_trace_get_trace_group(void);
static vmf_ret_t            vmf_trace_ctrl_reg_client(vmf_client_id_t trace_cid,unsigned8 trid,const char *trid_name);
static vmf_ret_t            vmf_trace_send_msg(vmf_client_id_t trace_cid,unsigned8 trid,unsigned8 event,unsigned8 severity,const char *msg);
static unsigned8            vmf_trace_get_trid(vmf_trace_shm_t* my_vmf_trace_shm,const char *trid_name);
NW_STATIC unsigned8         vmf_trace_get_name_trid(vmf_trace_shm_t* p_shm,const char *trid_name);
NW_STATIC vmf_ret_t         vmf_trace_store_trid_name(unsigned8 trid,const char* trid_name);
NW_STATIC vmf_ret_t         vmf_trace_send_filter(vmf_client_id_t cid,unsigned8 trid,vmf_trace_shm_t* p_shm);
static bool                 vmf_trace_wait_shm_valid(void);

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
        unsigned32 current_timeout = 0;
        /* open the shared memory page */
        /* wait until trace server is running */
        while(true)
        {
            ret_val = vmf_trace_open_shm();
            if (VMF_OK == ret_val)
            {
                /* open shm OK */
                VMF_TRACE_INFO_PRINT ("pid=%d,%s vmf_trace: vmf_trace_register vmf_trace_open_shm() OK\n",(int)getmypid(),trid_name);
                break;
            }
            /* an error occured - try again */
            if (current_timeout >= VMF_TRACE_WAIT_SHM_TIMEOUT)
            {
                /* abort */
                VMF_TRACE_ERROR_PRINT ("pid=%d,%s vmf_trace: vmf_trace_register() vmf_trace_open_shm failed after %dms\n",(int)getmypid(),trid_name,(int)current_timeout);
                return ret_val;
            }
            current_timeout += VMF_TRACE_WAIT_SOME_TIME;
            delay(VMF_TRACE_WAIT_SOME_TIME);
        }
        /* wait until shm is valid */
        if (!vmf_trace_wait_shm_valid())
        {
            return VMF_ERROR;
        }

        VMF_TRACE_INFO_PRINT ("pid=%d,%s vmf_trace: vmf_trace_register shm is valid !!\n",(int)getmypid(),trid_name);

        /* check if meanwhile another tread connected to vmf */
        if (vmf_trace_cid == 0)                 /* vmf_trace_cid is preinitialized to 0 */
        {
            /* connect to vmf server */
            ret_val = nw_vmf_connect("vmf_trace",NULL,VMF_TRACE_COL_TIME,0,0);
            if (ret_val < 0)
            {
                /* an error occured */
                VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: nw_vmf_connect failed, ret_val=%d\n",(int)getmypid(),ret_val);
                return ret_val;
            }
            else
            {
                VMF_TRACE_INFO_PRINT ("pid=%d,%s vmf_trace:vmf_trace_register() connected to vmf-server cid = %d\n",(int)getmypid(),trid_name,ret_val);
                vmf_trace_cid = ret_val;
            }
        }
        else
        {
            VMF_TRACE_INFO_PRINT ("pid=%d,%s vmf_trace:vmf_trace_register() already connected to vmf-server cid = %d\n",(int)getmypid(),trid_name,vmf_trace_cid);
        }
    }
#ifdef CHECK_SHM_AGAIN
    else
    {
        /* another thread may currently registering the shm */
        /* wait for shared memory pointer */
        unsigned16 cnt;

        for (cnt = 0;cnt < MAX_SHM_COUNT;cnt++)
        {
            if (NULL != vmf_trace_shm)
            {
                break;
            }
            delay(1);
        }
        if (cnt >= MAX_SHM_COUNT)
        {
            /* an error occured */
            VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: timeout waiting for shm\n",(int)getmypid());
            return VMF_ERROR;
        }
    }
#endif

    /* get a free trace id */
    *ptrid = vmf_trace_get_trid(vmf_trace_shm,trid_name);

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
 *   register a task with a unique trid-name at the vmf_trace server
 *   collector timeout can be set by using this API
 *   \param[out]    trid *              (output)pointer to trace ID (trid)
 *   \param[in]     trid_name           (input)unique name (trid name) (max 10 characters including zero)
 *   \param[in]     collector_timeout   (input) timeout for message collector in ms (or 0 if no collector)
 *   \return        vmf return type
 *
 ******************************************************************************/
vmf_ret_t vmf_trace_register_c(unsigned8 *ptrid,const char *trid_name,unsigned32 collector_timeout)
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
        unsigned32 current_timeout = 0;
        /* open the shared memory page */
        /* wait until trace server is running */
        while(true)
        {
            ret_val = vmf_trace_open_shm();
            if (VMF_OK == ret_val)
            {
                /* open shm OK */
                VMF_TRACE_INFO_PRINT ("pid=%d,%s vmf_trace: vmf_trace_register vmf_trace_open_shm() OK\n",(int)getmypid(),trid_name);
                break;
            }
            /* an error occured - try again */
            if (current_timeout >= VMF_TRACE_WAIT_SHM_TIMEOUT)
            {
                /* abort */
                VMF_TRACE_ERROR_PRINT ("pid=%d,%s vmf_trace: vmf_trace_register() vmf_trace_open_shm failed after %dms\n",(int)getmypid(),trid_name,(int)current_timeout);
                return ret_val;
            }
            current_timeout += VMF_TRACE_WAIT_SOME_TIME;
            delay(VMF_TRACE_WAIT_SOME_TIME);
        }
        /* wait until shm is valid */
        if (!vmf_trace_wait_shm_valid())
        {
            return VMF_ERROR;
        }
        VMF_TRACE_INFO_PRINT ("pid=%d,%s vmf_trace: vmf_trace_register shm is valid !!\n",(int)getmypid(),trid_name);

        /* check if meanwhile another tread connected to vmf */
        if (vmf_trace_cid == 0)                 /* vmf_trace_cid is preinitialized to 0 */
        {
            /* connect to vmf server */
            ret_val = nw_vmf_connect("vmf_trace",NULL,(signed32)collector_timeout,0,0);
            if (ret_val < 0)
            {
                /* an error occured */
                VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: nw_vmf_connect failed, ret_val=%d\n",(int)getmypid(),ret_val);
                return ret_val;
            }
            else
            {
                VMF_TRACE_INFO_PRINT ("pid=%d,%s vmf_trace:vmf_trace_register() connected to vmf-server cid = %d\n",(int)getmypid(),trid_name,ret_val);
                vmf_trace_cid = ret_val;
            }
        }
        else
        {
            VMF_TRACE_INFO_PRINT ("pid=%d,%s vmf_trace:vmf_trace_register() already connected to vmf-server cid = %d\n",(int)getmypid(),trid_name,vmf_trace_cid);
        }
    }
#ifdef CHECK_SHM_AGAIN
    else
    {
        /* another thread may currently registering the shm */
        /* wait for shared memory pointer */
        unsigned16 cnt;

        for (cnt = 0;cnt < MAX_SHM_COUNT;cnt++)
        {
            if (NULL != vmf_trace_shm)
            {
                break;
            }
            delay(1);
        }
        if (cnt >= MAX_SHM_COUNT)
        {
            /* an error occured */
            VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: timeout waiting for shm\n",(int)getmypid());
            return VMF_ERROR;
        }
    }
#endif

    /* get a free trace id */
    *ptrid = vmf_trace_get_trid(vmf_trace_shm,trid_name);
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
vmf_ret_t     vmf_trace_hex     (unsigned8 trid,unsigned8 severity,const char *task,const char *scope,unsigned8 len,const unsigned8 *data)
{
    char trace_msg[MAX_VMF_TRACE_PL_LEN+1];
    char msg[(MAX_VMF_TRACE_HEX_LEN *3)+1];
    char *t;
    unsigned16  uCnt;
    char *ptrid_name;

    vmf_ret_t   ret_val;

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

    if (0 == trid)
    {
        VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace_hex: trid = 0\n",(int)getmypid());
        return VMF_ERR_INVALID_ARG;
    }

    if (NULL == data)
    {
        VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace_hex: VMF_ERR_NULL_POINTER data = NULL\n",(int)getmypid());
        return VMF_ERR_NULL_POINTER;
    }

    if (NULL == vmf_trace_shm)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace_hex: VMF_ERR_NULL_POINTER vmf_trace_shm = NULL\n",(int)getmypid());
        return VMF_ERR_NULL_POINTER;
    }


    /* check if trace is allowed */
    if (vmf_trace_check_filter(trid,severity))
    {
        /* no trace*/
        return VMF_OK;
    }

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
    ptrid_name = vmf_trace_shm->task[trid].name;
    (void) snprintf(trace_msg,MAX_VMF_TRACE_PL_LEN,"%s%s%s%s%s%s%s",ptrid_name,VMF_TRACE_MSG_DELIMITER,task,VMF_TRACE_MSG_DELIMITER, scope,VMF_TRACE_MSG_DELIMITER,msg);
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
    /*int print_len;*/
    vmf_ret_t   ret_val=VMF_OK;
    char *ptrid_name;

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

    if (0 == trid)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace()-trid=0, task=%s, scope=%s, message=%s\n",(int)getmypid(),task,scope,message);
        return VMF_ERR_INVALID_ARG;
    }

    if (NULL == vmf_trace_shm)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: VMF_ERR_NULL_POINTER vmf_trace_shm = NULL - task=%s, scope=%s, message=%s\n",(int)getmypid(),task,scope,message);
        return VMF_ERR_NULL_POINTER;
    }

    /* check if trace is allowed */
    if (vmf_trace_check_filter(trid,severity))
    {
        /* no trace*/
        return VMF_OK;
    }

    /* get trid name */
    ptrid_name = vmf_trace_shm->task[trid].name;

    /* build trace message */
    (void)  snprintf(trace_msg,MAX_VMF_TRACE_PL_LEN,"%s%s%s%s%s%s%s",ptrid_name,VMF_TRACE_MSG_DELIMITER,task,VMF_TRACE_MSG_DELIMITER, scope,VMF_TRACE_MSG_DELIMITER,message);
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
    va_list     arglist;
    vmf_ret_t   vmf_ret;
    char msg[MAX_VMF_TRACE_PL_LEN+1];

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

    if (0 == trid)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace_printf: vmf_trace()-trid=0, task=%s, scope=%s\n",(int)getmypid(),task,scope);
        return VMF_ERR_INVALID_ARG;
    }

    if (NULL == format)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace_printf: VMF_ERR_NULL_POINTER format arg = NULL\n",(int)getmypid());
        return VMF_ERR_NULL_POINTER;
    }

    if (NULL == vmf_trace_shm)
    {
//        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace_printf: VMF_ERR_NULL_POINTER vmf_trace_shm = NULL - task=%s, scope=%s, message=%s\n",(int)getmypid(),task,scope,format);
        return VMF_ERR_NULL_POINTER;
    }

    /* check if trace is allowed */
    if (vmf_trace_check_filter(trid,severity))
    {
        /* no trace*/
        return VMF_OK;
    }

    va_start (arglist, format);
    (void) vsnprintf(msg, MAX_VMF_TRACE_PL_LEN, format, arglist);
    va_end (arglist);

    vmf_ret = vmf_trace(trid, severity, task, scope,msg);

    VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace_printf: message=%s\n",(int)getmypid(),msg);

    return vmf_ret;
}



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

    VMF_BASIC_MSG_GROUP_ID(&vmf_msg)    = VMF_TRACE_CTRL;
    VMF_BASIC_MSG_EVENT_ID(&vmf_msg)    = event;

    /* copy payload */
    vmf_msg.vmf_basic_msg.data.length = len;
    nw_os_smemcpy(vmf_msg.vmf_basic_msg.data.pl,sizeof(vmf_msg.vmf_basic_msg.data.pl),pl, vmf_msg.vmf_basic_msg.data.length);

    vmf_ret = nw_vmf_send_basic (trace_cid,(vmf_basic_msg_t*)&vmf_msg);
    if(vmf_ret < 0)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_send_ctrl-nw_vmf_send_basic failed - cid=%d\n",(int)getmypid(),trace_cid);
    }

    return vmf_ret;
}



/**************************************************************************//**
 *
 *   Function Name: vmf_trace_set_severity()
 *
 *   Description:   set the severity for a trace client
 *                  enable global trace, specific trace and startup queue
 *   Parameters:
 *
 *   \param[in]     trid        - trace id
 *   \param[in]     severity    - 0..255
 *   \return        vmf_ret_t
 ******************************************************************************/
vmf_ret_t vmf_trace_set_severity(unsigned8 trid,unsigned8 severity)
{
    vmf_ret_t   vmf_ret = VMF_ERROR;

    if (NULL == vmf_trace_shm)
    {
        /* shm not open - so try to open it */
        vmf_ret = vmf_trace_open_shm();
    }

    if (NULL != vmf_trace_shm)
    {
        /* the following write operations are atomic - so no need to use sem's */
        vmf_trace_shm->task[trid].severity = severity;      /* set severity */
        vmf_trace_shm->task[trid].trace_active = true;      /* enable trace for this trid */
        vmf_trace_shm->gl_trace_active = true;              /* enable global trace  */
        vmf_trace_shm->gl_startup_q = true;                 /* enable startup queue */
        vmf_ret = VMF_OK;

        (void)vmf_trace_send_filter(vmf_trace_cid,trid,vmf_trace_shm);
    }

    return (vmf_ret);
}



/******************************************************************************
        local functions
 ******************************************************************************/


 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_open_shm()
 *
 *   Description:   open the vmf_trace shared memory page
 *
 *   Parameters:
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
static vmf_ret_t vmf_trace_open_shm(void)
{
    int         fd=-1;
    void        *shm  = NULL;
    vmf_ret_t   ret_val= VMF_ERROR;
    unsigned16  cnt=0;
#ifndef UNIT_TEST
#if !defined (__WINDOWS__) && !defined (__ANDROID__) && !defined (INTEGRITY)
    sem_t *     sem = SEM_FAILED;
    unsigned16  timeout=0;
#endif /* __WINDOWS__ */


    /* vmf_trace_shm is pre-initialized to NULL */
    if (NULL != vmf_trace_shm)
    {
        /* another tread already mapped the shm */
        cnt++;  /* to prevebt warnig */
        VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_open_shm() shm already mapped 1\n",(int)getmypid());
        return VMF_OK;
    }
#if !defined (__WINDOWS__) && !defined (__ANDROID__) && !defined (INTEGRITY)
    /* try to open the trace server sem and wait until it is avail. */
    while (true)
    {
        sem = nw_sem_open(VMF_TRACE_SEM,0);        /* open sem */
        if (sem == SEM_FAILED)
        {
            /* error opening the sem - we will try again */
            timeout+=VMF_TRACE_WAIT_SOME_TIME;
            if (timeout > VMF_TRACE_WAIT_SHM_TIMEOUT)
            {
                VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_open_shm-sem_open failed after %dms\n",(int)getmypid(),timeout);
                return VMF_ERROR;
            }
            VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_open_shm() wait %dms\n",(int)getmypid(),VMF_TRACE_WAIT_SOME_TIME);
            delay(VMF_TRACE_WAIT_SOME_TIME);
        }
        else
        {
            /* open was OK */
            break;
        }
    }

    if (SEM_FAILED == sem)
    {
        /* vmf not running ?? */
        VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_open_shm-sem_open failed\n",(int)getmypid());
        return VMF_ERROR;
    }

    /* wait for shared mem */
    if (0 != sem_wait(sem))
    {
        /* sem_wait failed */
        VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_open_shm() - sem_wait() failed - errno=%d\n",(int)getmypid(),errno);
        return VMF_ERROR;
    }
#endif /* __WINDOWS__ */
#endif /* UNIT_TEST */

    /* check again if another thread mapped the shm */
    if (vmf_trace_shm != NULL)  /* vmf_trace_shm is pre-initialized to NULL */
    {
        /* another tread already mapped the shm - so nothing to do */
        VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_open_shm() shm already mapped 2\n",(int)getmypid());
        ret_val = VMF_OK;
    }
    else
    {
        /* open the shared memory */
        fd = nw_shm_open(VMF_TRACE_SHM);
        if (-1 == fd)
        {
            /* shm open failed */
            VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_open_shm-shm_open() failed\n",(int)getmypid());
            ret_val = VMF_ERROR;
        }
        else
        {
            /* shm is open */
            VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_open_shm() shm_open OK - fd=%d, cnt=%d\n",(int)getmypid(),(int)fd,cnt);

            shm = mmap(NULL, sizeof(vmf_trace_shm_t), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
            if (shm == (void*)MAP_FAILED)
            {
                /* Failed to access the memory */
                (void) nw_shm_close(fd);
                vmf_trace_shm = NULL;
                VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace:vmf_trace_open_shm-mmap failed\n",(int)getmypid());
                ret_val = VMF_ERROR;
            }
            else
            {
                /* check if mmap returned a NULL pointer */
                if (NULL == shm)
                {
                    VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace:vmf_trace_open_shm() mmap returned NULL pointer\n",(int)getmypid());
                    ret_val = VMF_ERROR;
                }
                else
                {
                    VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_open_shm() mmap OK\n",(int)getmypid());
                    vmf_trace_shm = (vmf_trace_shm_t*)shm;
                    ret_val = VMF_OK;
                }
            }
        }
    }

    /* release the sem */
#if !defined (__WINDOWS__) && !defined (__ANDROID__) && !defined (INTEGRITY)
    #ifndef UNIT_TEST
    if (-1 == sem_post(sem))
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace:vmf_trace_open_shm() sem_post failed\n",(int)getmypid());
    }
    else
    {
        VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_open_shm() sem_post() done!\n",(int)getmypid());
    }
    #endif
#endif
    return ret_val;
}


 /**************************************************************************//**
 *
 *   Function Name: getmypid()
 *
 *   Description:   get the pid
 *
 *   Parameters:
 *
 *   Function Return value: - \return void
 *
 ******************************************************************************/
static unsigned32 getmypid(void)
{
    static unsigned32 u32myPid = 0;

    if (0 == u32myPid )
    {
        u32myPid= nw_os_getpid();
    }

    return u32myPid;
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
bool vmf_trace_check_filter(unsigned8 trid,unsigned8 severity)
{

    if (NULL == vmf_trace_shm)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace:vmf_trace_check_filter: VMF_ERR_NULL_POINTER vmf_trace_shm = NULL\n",(int)getmypid());
        return true;
    }

    /* check if global trace is enabled */
    if (!vmf_trace_shm->gl_trace_active)
    {
        /* trace is disabled */
        VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_check_filter() global trace disabled\n",(int)getmypid());
        return true;
    }

    /* check if trace for this task is enabled */
    if (!vmf_trace_shm->task[trid].trace_active)
    {
        /* trace is disabled */
        VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_check_filter() local trace disabled\n",(int)getmypid());
        return true;
    }

    /* check if exactly  THIS severity is allowed (is bit 2^7 is set?)*/
    if (vmf_trace_shm->task[trid].severity & 0x80)
    {
        if ((severity | 0x80) == vmf_trace_shm->task[trid].severity)
        {
            /* allow exactly this severity */
            return false;   /* do not filter this message !*/
        }
        /* bit 2^7 set in shm-severity but wrong severity - so ignore */
        else
        {
            /* ignore THIS severity */
            VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_check_filter() THIS severity disabled\n",(int)getmypid());
            return true;
        }
    }

    /* check if message with this severity is ignored */
    if (severity > ((vmf_trace_shm->task[trid].severity) & 0x7f))
    {
        /* ignore this severity */
        VMF_TRACE_INFO_PRINT ("pid=%d vmf_trace:vmf_trace_check_filter() severity disabled severity=%d set-severity=%d\n",(int)getmypid(),severity,((vmf_trace_shm->task[trid].severity) & 0x7f));
        return true;
    }

    return false;   /* allow trace */
}


 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_get_trace_group()
 *
 *   Description:   get the trace group
 *
 *   Parameters:
 *
 *   \param[in]     void
 *   \return        unsigned8   trace group
 ******************************************************************************/
static unsigned8 vmf_trace_get_trace_group(void)
{
    /* get trace group from share memory  */
    return (vmf_trace_shm->gl_trace_group);
}




/**************************************************************************//**
 *
 *   Function Name: vmf_trace_wait_shm_valid()
 *
 *   Description:   wait util shm is valid
 *                  this function should return without looping because
 *                  the trace server is started with the VMF-server
 *   Parameters:
 *
 *   \param[in]     void
 *   \return        bool   true if shm is valid else false if shm not valid
 *                         within VMF_TRACE_WAIT_SHM_TIMEOUT
 ******************************************************************************/
static bool vmf_trace_wait_shm_valid(void)
{
    unsigned16  current_timeout=0;
    bool        b_ret=true;

    if (NULL == vmf_trace_shm)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_wait_shm_valid shm=NULL!!\n",(int)getmypid());
        return false;
    }

    /* check if shm is valid */
    while ((vmf_trace_shm->valid != VMF_SHM_VALID_KEY) && (true == b_ret))
    {
        delay(VMF_TRACE_WAIT_SOME_TIME);
        current_timeout += VMF_TRACE_WAIT_SOME_TIME;
        if (current_timeout >= VMF_TRACE_WAIT_SHM_TIMEOUT)
        {
            VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_wait_shm_valid timeout\n",(int)getmypid());
            b_ret = false;
        }
    }
    return b_ret;
}




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
static unsigned8 vmf_trace_get_trid(vmf_trace_shm_t* my_vmf_trace_shm,const char *trid_name)
{
    unsigned8 free_trid=VMF_TRACE_TRID_INVALID;

    /* search if a trace client with the same trid-name was already registered */
    if (NULL == my_vmf_trace_shm)
    {
        return VMF_TRACE_TRID_INVALID;
    }

    free_trid = vmf_trace_get_name_trid(my_vmf_trace_shm,trid_name);

    if (VMF_TRACE_TRID_INVALID == free_trid)
    {
        free_trid = (unsigned8)nw_atomic_add_value( &(my_vmf_trace_shm->gl_free_trid),1);
    }

    if (free_trid >= MAX_VMF_TRACE_TRIDS)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace:vmf_trace_get_trid() no free trid\n",(int)getmypid());
        free_trid=VMF_TRACE_TRID_INVALID;
    }

    return free_trid;
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
NW_STATIC vmf_ret_t vmf_trace_store_trid_name(unsigned8 trid,const char* trid_name)
{

    if (NULL == vmf_trace_shm)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace:vmf_trace_store_trid_name() VMF_ERR_NULL_POINTER vmf_trace_store_trid_name() vmf_trace_shm = NULL\n",(int)getmypid());
        return VMF_ERR_NULL_POINTER;
    }

    if (trid >= MAX_VMF_TRACE_TRIDS)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace:vmf_trace_store_trid_name() trid >=MAX_VMF_TRACE_TRIDS\n",(int)getmypid());
        return VMF_ERR_OUT_OF_RANGE;
    }

    /* argument check */
    if ((0 == trid) || (trid > vmf_trace_shm->gl_free_trid))
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: VMF_ERR_OUT_OF_RANGE vmf_trace_store_trid_name-shm free trid=%d\n",(int)getmypid(),vmf_trace_shm->gl_free_trid);
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: VMF_ERR_OUT_OF_RANGE vmf_trace_store_trid_name-trid=%d\n",(int)getmypid(),trid);
        return VMF_ERR_OUT_OF_RANGE;
    }

    if (NULL == trid_name)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: VMF_ERR_NULL_POINTER tridname=NULL\n",(int)getmypid());
        return VMF_ERR_NULL_POINTER;
    }

    nw_os_sstrncpy(vmf_trace_shm->task[trid].name, trid_name, MAX_TRACE_NAME_LEN);

    VMF_TRACE_INFO_PRINT ("vmf_trace_store_trid_name=%s, trid=%d\n",trid_name,trid);
    return (VMF_OK);
}




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


    pl.reg_client.trid = trid;
    nw_os_sstrncpy(pl.reg_client.name, trid_name, MAX_TRACE_NAME_LEN);

    vmf_ret = vmf_trace_send_ctrl(trace_cid,VMF_TRACE_CTRL_REG_CLIENT,&pl,sizeof(vmf_trace_ctrl_reg_client_t));
    return vmf_ret;
}


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

    if (NULL == vmf_trace_shm)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_send_msg-shm pointer = NULL!\n",(int)getmypid());
        return VMF_ERR_NULL_POINTER;
    }

    VMF_BASIC_MSG_GROUP_ID(&vmf_msg) = vmf_trace_get_trace_group();
    VMF_BASIC_MSG_EVENT_ID(&vmf_msg) = event;

    /* create payload */
    trace_pl.trid = trid;
    trace_pl.severity = severity;
    trace_pl.msg_time = vmf_trace_get_time_in_ms();
    trace_pl.sequence_type = VMF_TRACE_PL_LAST_MSG;
    trace_pl.fill = 0;  /* satisfy Coverity */

    /* inc message counter */
    trace_pl.num = (unsigned32)nw_atomic_add_value((unsigned *) &(vmf_trace_shm->task[trid].msg_num),1);

    /* copy trace message */
    if (NULL != msg)
    {
        trace_pl.tpl_len = strlen(msg);
        if (0x0a == msg[trace_pl.tpl_len-1])
        {
            trace_pl.tpl_len--;
        }
        nw_os_sstrncpy(trace_pl.tpl, msg, sizeof(trace_pl.tpl));
    }
    else
    {
        /* no message  */
        trace_pl.tpl_len = 0;
    }

    /* copy trace message to vmf payload */
    vmf_msg.vmf_basic_msg.data.length = GET_TPL_LEN(&trace_pl);
    nw_os_smemcpy(vmf_msg.vmf_basic_msg.data.pl,sizeof(vmf_msg.vmf_basic_msg.data.pl),&trace_pl, vmf_msg.vmf_basic_msg.data.length);

    vmf_ret = nw_vmf_send_basic (trace_cid,(vmf_basic_msg_t*)&vmf_msg);
    if(vmf_ret < 0)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_send_msg-nw_vmf_send_basic failed - error=%d, cid=%d\n",(int)getmypid(),vmf_ret,trace_cid);
    }

    return vmf_ret;
}



 /**************************************************************************//**
 *
 *   Function Name: vmf_trace_send_filter()
 *
 *   Description:   send a trace filters of a single trace client to the windows client
 *
 *   \param[in]     cid         vmf client id
 *   \param[in]     trid        trace trid
 *   \param[in]     p_shm       pointer to shared memory
 *
 *   Function Return value: - \return vmf_ret
 *
 ******************************************************************************/
NW_STATIC vmf_ret_t vmf_trace_send_filter(vmf_client_id_t cid,unsigned8 trid,vmf_trace_shm_t* p_shm)
{
    vmf_ret_t           vmf_ret=VMF_OK;

    {
        vmf_trace_ctrl_pl_t pl;
        unsigned16 len;

        pl.flt_response.severity    = p_shm->task[trid].severity;
        pl.flt_response.trid        = trid;
        pl.flt_response.trace_active= p_shm->task[trid].trace_active;
        nw_os_sstrncpy(pl.flt_response.name, p_shm->task[trid].name, MAX_TRACE_NAME_LEN);
        pl.flt_response.name[MAX_TRACE_NAME_LEN] = 0;   /* set string delimiter */
                                                        /* length of .name is MAX_TRACE_NAME_LEN+1 */
        len = sizeof(vmf_trace_ctrl_filter_response_t)- MAX_TRACE_NAME_LEN + strlen(pl.flt_response.name) +1;

        /* transfer this filter to the client */
        vmf_ret = vmf_trace_send_ctrl(cid,VMF_TRACE_CTRL_FILTER_RESP,&pl,len);
    }
    return vmf_ret;
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
NW_STATIC unsigned8 vmf_trace_get_name_trid(vmf_trace_shm_t* p_shm,const char *trid_name)
{
    unsigned16 cnt;
    unsigned8  trid;
    int        ret;

    if (NULL == p_shm)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_get_name_trid- p_shm=NULL\n",(int)getmypid());
        return VMF_TRACE_TRID_INVALID;
    }

    if (NULL == trid_name)
    {
        VMF_TRACE_ERROR_PRINT ("pid=%d vmf_trace: vmf_trace_get_name_trid- trid_name=NULL\n",(int)getmypid());
        return VMF_TRACE_TRID_INVALID;
    }

    trid = VMF_TRACE_TRID_INVALID;

    /* check if entry for this trid_name is present in persistent data */
    for (cnt=0; cnt<MAX_VMF_TRACE_TRIDS ;cnt++)
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
    return nw_os_cfg_get_ms_time();
}
#endif
