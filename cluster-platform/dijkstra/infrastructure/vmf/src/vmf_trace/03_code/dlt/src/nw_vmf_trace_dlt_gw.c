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
*  MODULE NAME  :  vmf_trace_dlt_gw.c                                         *
*  AUTHOR NAME  :  Joachim Becker - jbecke30                                  *
*******************************************************************************
*  MODULE DATE  :   13 Oct 2013                                              *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  VMF_TRACE                                                                  *
******************************************************************************/

/***************************************************************************

  Module:               nw_vmf_trace_server.c
  Description:          vmf trace dlt gateway

  Project Scope:        VMF

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   gcc
  Target Hardware:      Any

  *****************************************************************************/
#define VMF_TRACE_DLT_GW_C
// #define SIMPLE_TEST

#define VMF_TRACE_ALLOW_PREREGISTER /* allow pre-registration of all clients */
#include "nw_os_config.h"
#include "nw_vmf.h"
#include "nw_vmf_cfg.h"             /* in 07_system */
#include "nw_vmf_trace_server.h"
#include "nw_vmf_trace.h"
#include "nw_vmf_ipc.h"
#include "nw_vmf_sysinfo.h"
#include "nw_vmf_debug.h"
#include "dlt.h"
#include "dlt_user.h"
#include "nw_vmf_trace_dlt_gw.h"

/* Macros */
#define DLT_GW_NAME             "vmf_trace_dlt_gw"
#define DLT_LIB                 "libdlt.so"
#define DLT_APP_ID              "VMF"                   /* max 4 characters */
#define DLT_APP_DESCRIPTION     "VMF-DLT-GW"
#define DLT_CONTEXTID           "TEST"                  /* max 4 characters */
#define DLT_CONTEX_DESCRIPTION  "DLT_CONTEX_DESCRIPTION"
#define DLT_VMF_REC_TIMEOUT     (500)                   /* rx timeout in ms*/
#define VMF_DLT_GW_MSG_SIZE     (600)
#define VMF_TRACE_DLT_GW        "vmf_dlt_gw"
#define CONTEXT_DEFAULT 		(0)
#define CONTEXT_VMF 			(1)
#define CONTEXT_MSG				(MAX_VMF_TRACE_TRIDS)


#define VMF_TRACE_GW_SCOPE      (char *)__PRETTY_FUNCTION__

#ifdef  VMF_TRACE
#define VMF_TRACE_GW_ERROR_PRINT( ...)      VMF_TRACE_PRINTF(vmf_dlt_trid, VMF_TRACE_SEVERITY_ERROR, "vmf_dlt_gw", VMF_TRACE_GW_SCOPE, __VA_ARGS__);
#define VMF_TRACE_GW_WARNING_PRINT( ...)    VMF_TRACE_PRINTF(vmf_dlt_trid, VMF_TRACE_SEVERITY_WARNING, "vmf_dlt_gw", VMF_TRACE_GW_SCOPE, __VA_ARGS__);
#define VMF_TRACE_GW_INFO_PRINT( ...)       VMF_TRACE_PRINTF(vmf_dlt_trid, VMF_TRACE_SEVERITY_INFO, "vmf_dlt_gw", VMF_TRACE_GW_SCOPE, __VA_ARGS__);
#else
#define VMF_TRACE_GW_ERROR_PRINT(args...)   {fprintf(ERROR_CHANNEL,"Error:  ");fprintf(ERROR_CHANNEL,args);fprintf(ERROR_CHANNEL,"\n");}
#define VMF_TRACE_GW_INFO_PRINT(args...)    {fprintf(ERROR_CHANNEL,"Info:   ");fprintf(ERROR_CHANNEL,args);fprintf(ERROR_CHANNEL,"\n");}
#define VMF_TRACE_GW_WARNING_PRINT(args...) {fprintf(ERROR_CHANNEL,"Warning:");fprintf(ERROR_CHANNEL,args);fprintf(ERROR_CHANNEL,"\n");}
#endif

#ifdef SIMPLE_TEST
#define VMF_TRACE_GW_INFO_PRINT2(args...)       {fprintf(ERROR_CHANNEL,"Info:   ");fprintf(ERROR_CHANNEL,args);fprintf(ERROR_CHANNEL,"\n");}
#else
#define VMF_TRACE_GW_INFO_PRINT2(args...)       // {fprintf(ERROR_CHANNEL,"Info:   ");fprintf(ERROR_CHANNEL,args);fprintf(ERROR_CHANNEL,"\n");}
#endif
#define VMF_TRACE_GW_ERROR_PRINT_C(args...)    	{fprintf(ERROR_CHANNEL,"ERROR:   ");fprintf(ERROR_CHANNEL,args);fprintf(ERROR_CHANNEL,"\n");}
#define VMF_TRACE_GW_INFO_PRINT_C(args...)    	{fprintf(ERROR_CHANNEL,"Info:   ");fprintf(ERROR_CHANNEL,args);fprintf(ERROR_CHANNEL,"\n");}
#define VMF_TRACE_GW_WARNING_PRINT_C(args...)   {fprintf(ERROR_CHANNEL,"Warning:");fprintf(ERROR_CHANNEL,args);fprintf(ERROR_CHANNEL,"\n");}

/* externals */
extern bool			enable_dlt_gw;

/* local variables */
static unsigned8    vmf_dlt_trid=0;
static void*        dlt_library=NULL;
static DltContext   dlt_context[MAX_VMF_TRACE_TRIDS+1];
static vmf_client_id_t vmf_cid=0;
static unsigned8	vmf_monitored_groups[MAX_GROUP_NUM];
static int			vmf_monitored_groups_num=0;



/* DLT lib function pointers */
static int          (*p_dlt_check_library_version)(const char * user_major_version, const char * user_minor_version)=NULL;
static int          (*p_dlt_register_app)(const char *appid, const char * description) = NULL;
static int          (*p_dlt_register_context)(DltContext *handle, const char *contextid, const char * description) = NULL;
static int          (*p_dlt_user_log_write_start_id)(DltContext *handle, DltContextData *log, DltLogLevelType loglevel, uint32_t messageid) = NULL;
static int          (*p_dlt_user_log_write_finish)(DltContextData *log) = NULL;
static int          (*p_dlt_unregister_context)(DltContext *handle)=NULL;
static int          (*p_dlt_unregister_app)(void)=NULL;
static int          (*p_dlt_user_log_write_int)(DltContextData *log, int data)=NULL;
static int          (*p_dlt_user_log_write_string)(DltContextData *log, const char *text)=NULL;
static int          (*p_dlt_free)(void)=NULL;



/* local functions */
static void             *vmf_trace_dlt_gw_task(void *pArg);
static DltLogLevelType  dlt_gw_severity(unsigned8 vmf_severity);
static vmf_ret_t        dlt_gw_send(unsigned8 trid, char *trace_msg, unsigned8 vmf_severity,int msg_num);
static vmf_ret_t        dlt_gw_trace_ctrl_parser(vmf_basic_msg_t *vmf_basic_msg);
static vmf_ret_t        dlt_gw_trace_msg(vmf_basic_msg_t *vmf_basic_msg);
static vmf_ret_t 		dlt_gw_trace_vmf_msg(vmf_basic_msg_t *vmf_basic_msg);

static void 			my_HexDump(char *pchDestBuffer,char *pchPrefixText,char *pchSufixText,unsigned16 u16DestBuffLen,unsigned8 *u8mem, unsigned length);
static int				vmf_dlt_early_register_contexts(void);


/**************************************************************************//**
 *
 *   Function Name: vmf_trace_dlt_gw_create_thread
 *
 *   Description:   create dlt-gw thread
 *
 *
 *   Parameters:    void
 *
 *   Function Return value: return True if OK or False.
 *
 ******************************************************************************/
bool vmf_trace_dlt_gw_create_thread(void)
{
#ifdef __LINUX__
    pthread_t th;
    pthread_attr_t  attr;
    struct sched_param param;
    int iRet;
	char Thread_name[100];
    
	if (false == enable_dlt_gw)
	{
		/* VMF-dlt gateway not enabled */
		return true;
	}
	
    /* register to trace server */
    if (VMF_TRACE_REGISTER(&vmf_dlt_trid, VMF_TRACE_DLT_GW) < 0)
    {
        fprintf(ERROR_CHANNEL,"vmf_trace_dlt_gw_create_thread: CANNOT CONNECT TO VMF TRACER!!!");
    }

    VMF_TRACE_GW_INFO_PRINT("vmf_trace_dlt_gw_create_thread() start");

    /* before starting the gw-thread try to load the dlt shared lib */
    dlerror();  /* clear all pending errors */                              
    dlt_library = dlopen(DLT_LIB, RTLD_LAZY);
    if (dlt_library == NULL) 
    {
        /* loading the library failed */
        VMF_TRACE_GW_ERROR_PRINT("loading dlt lib '%s' failed - error=%s - disabeling vmf-dlt gateway ",DLT_LIB,dlerror());
		enable_dlt_gw = false;
        return false;
    }

    
    /* set thread stack */
    pthread_attr_init( &attr );

    /* set the attributes of the thread */
    (void)pthread_attr_setschedpolicy (&attr, SCHED_RR);
    param.sched_priority = VMF_TRACE_SERVER_GW_PRIO;

    #ifndef __ANDROID__
    iRet = pthread_attr_setstacksize  (&attr, VMF_TRACE_SERVER_GW_STACK_SIZE);
    if (EOK != iRet)
    {
        VMF_TRACE_GW_ERROR_PRINT("vmf_trace_dlt_gw_create_thread: pthread_attr_setstacksize() failed");
    }
    #endif

    (void)pthread_attr_setschedparam (&attr, &param );
    (void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );

    iRet = pthread_create (&th  ,&attr, vmf_trace_dlt_gw_task, NULL);
    (void)pthread_attr_destroy(&attr);
    if (iRet)
    {
        VMF_TRACE_GW_ERROR_PRINT("vmf_trace_dlt_gw_create_thread: vmf_spy_create_thread() error errno = %d",iRet);
        return false;
    }
#if ((defined(__QNX__) && (_NTO_VERSION >= 632)) || defined(__LINUX__))		
    /* Name the vmf-Logger thread */
	sprintf(Thread_name, "%s-%d", DLT_GW_NAME, th);
	nw_os_set_thread_name(th, Thread_name);    
#endif
   
#endif  /* #ifdef __LINUX__ */ 
    return true;

}


#ifdef __LINUX__

/**************************************************************************//**
 *
 *   Function Name: vmf_trace_dlt_gw_task(void *not_used)
 *
 *   Description:   gateway vmf trace messages to dlt trace framework
 *
 *   Parameters:    unused
 *
 *   Function Return value: - void
 *
 ******************************************************************************/
static void *vmf_trace_dlt_gw_task(void *pArg)
{
    int                 dlt_error= 0;
    int                 num;
    unsigned8           nw_vmf_trace_group_list[] = {VMF_TRACE_CTRL,VMF_TRACE_IN};
    
    
    VMF_TRACE_GW_INFO_PRINT("vmf_trace_dlt_gw_task started");

    /* do some tests before we start */
    if (NULL==dlt_library)
    {
         VMF_TRACE_GW_ERROR_PRINT("vmf_trace_dlt_gw_task: dlt handle invalid");
         return NULL;
    }
    
    /* init */
    memset(&dlt_context,0,sizeof(dlt_context));
    
    /* set thread name for Linux */    
    nw_os_set_current_thread_name(DLT_GW_NAME);  
    
    /* get all needed dlt functions */
    /* shared lib was already opened in the thread starter */
    p_dlt_check_library_version     = dlsym(dlt_library,"dlt_check_library_version");
    p_dlt_register_app              = dlsym(dlt_library,"dlt_register_app");
    p_dlt_register_context          = dlsym(dlt_library,"dlt_register_context");
    p_dlt_user_log_write_start_id   = dlsym(dlt_library,"dlt_user_log_write_start_id");
    p_dlt_user_log_write_finish     = dlsym(dlt_library,"dlt_user_log_write_finish");
    p_dlt_unregister_context        = dlsym(dlt_library,"dlt_unregister_context");
    p_dlt_unregister_app            = dlsym(dlt_library,"dlt_unregister_app");
    p_dlt_user_log_write_string     = dlsym(dlt_library,"dlt_user_log_write_string");
    p_dlt_user_log_write_int        = dlsym(dlt_library,"dlt_user_log_write_int");
    p_dlt_free                      = dlsym(dlt_library,"dlt_free");


    /* check if all needed functions are present */
    if ((NULL == p_dlt_check_library_version)   ||
        (NULL == p_dlt_register_app)            ||
        (NULL == p_dlt_user_log_write_start_id) ||
        (NULL == p_dlt_user_log_write_finish)   ||
        (NULL == p_dlt_unregister_context)      ||
        (NULL == p_dlt_user_log_write_int)      ||
        (NULL == p_dlt_user_log_write_string)   ||
        (NULL == p_dlt_free)                    ||
        (NULL == p_dlt_register_context))
    {
        /* at least on function is not in the lib */
        VMF_TRACE_GW_ERROR_PRINT_C("vmf_trace_dlt_gw_task: function not found in dlt-lib - disabeling vmf-dlt gateway");
        return NULL;
    }
    
    /* register to dlt */
    if (dlt_error >= 0)
    {
        dlt_error = (*p_dlt_check_library_version)(_DLT_PACKAGE_MAJOR_VERSION, _DLT_PACKAGE_MINOR_VERSION);
        if (dlt_error<0)
        {
            /* invalid lib version */
            VMF_TRACE_GW_ERROR_PRINT_C("vmf_trace_dlt_gw_task: invalid dlt-lib version - disabeling vmf-dlt gateway");
			return NULL;
        }
        else
        {
            VMF_TRACE_GW_INFO_PRINT2("vmf_trace_dlt_gw_task: p_dlt_check_library_version() OK, dlt_error=%d",dlt_error);
        }
    }
    if (dlt_error >= 0)
    {
        dlt_error = (*p_dlt_register_app)( DLT_APP_ID, DLT_APP_DESCRIPTION);
        if (dlt_error<0)
        {
            /* error registering app */
            VMF_TRACE_GW_ERROR_PRINT("vmf_trace_dlt_gw_task: p_dlt_register_app failed");
        }
		else
		{
            VMF_TRACE_GW_INFO_PRINT2("vmf_trace_dlt_gw_task: p_dlt_register_app OK,dlt_id=%s",DLT_APP_ID);
		}
    }
	
#ifndef SIMPLE_TEST
    /* register to VMF */
	VMF_TRACE_GW_INFO_PRINT2("register to Tracer message group");
    vmf_cid = nw_vmf_connect("vmf_dlt_gw", NULL, 0, VMF_CLIENT_QUEUE_SIZE_BIG, VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD);
    if (vmf_cid < 0)
    {
        /* an error occured */
        VMF_TRACE_GW_ERROR_PRINT("vmf_trace_dlt_gw_task: nw_vmf_connect failed");
        dlt_error = -1;
    }
    /* register message groups */    
    if(nw_vmf_register_msg_group(vmf_cid,sizeof(nw_vmf_trace_group_list),&nw_vmf_trace_group_list[0]) < 0)
    {
        VMF_TRACE_GW_ERROR_PRINT("vmf_trace_dlt_gw_task: nw_vmf_register_msg_group() failed");
        dlt_error = -1;
    }

	VMF_TRACE_GW_INFO_PRINT2("register to %d vmf message groups %02x,%02x,%02x,%02x,...",vmf_monitored_groups_num,vmf_monitored_groups[0],vmf_monitored_groups[1],vmf_monitored_groups[2],vmf_monitored_groups[3]);
	/* register the groups to vmf */
	if (vmf_monitored_groups_num > 0)
	{
		if (nw_vmf_register_msg_group(vmf_cid,vmf_monitored_groups_num,vmf_monitored_groups) <0)
		{
			VMF_TRACE_GW_ERROR_PRINT("vmf_trace_dlt_gw_task: nw_vmf_register_msg_group() failed");
			dlt_error = -1;
		}
		vmf_monitored_groups_num=0;
	}

	/* early register of some contexts */
	dlt_error = vmf_dlt_early_register_contexts();

    /* receive trace messages and send them to dlt  */
    while(dlt_error>=0)
    {
        vmf_ret_t   vmf_ret;
        VMF_VAR_MSG_TYP(VMF_DLT_GW_MSG_SIZE)  vmf_msg;
        
        VMF_TRACE_GW_INFO_PRINT2("vmf_trace_dlt_gw_task: rx.loop: wait for rx");

        vmf_ret = nw_vmf_timed_receive(vmf_cid,(vmf_msg_t*)&vmf_msg,sizeof(vmf_msg),DLT_VMF_REC_TIMEOUT);
        if (vmf_ret > 0)
        {
            if (NW_VMF_MSG_GROUP((vmf_msg_t*)&vmf_msg)== VMF_TRACE_CTRL)
            {
				/* trace controll commands */
                VMF_TRACE_GW_INFO_PRINT2("vmf_trace_dlt_gw_task: rx.loop: msg-group=VMF_TRACE_CTRL");
                vmf_ret = dlt_gw_trace_ctrl_parser((vmf_basic_msg_t*)&(vmf_msg.vmf_basic_msg));
            }
            else if (NW_VMF_MSG_GROUP((vmf_msg_t*)&vmf_msg)== VMF_TRACE_IN)
            {
				/* trace messages */
                VMF_TRACE_GW_INFO_PRINT2("vmf_trace_dlt_gw_task: rx.loop: msg-group=VMF_TRACE_IN");
                vmf_ret = dlt_gw_trace_msg((vmf_basic_msg_t*)&(vmf_msg.vmf_basic_msg));
            }
			else
			{
				/* vmf messages that are monitored by DLT */
                VMF_TRACE_GW_INFO_PRINT2("vmf_trace_dlt_gw_task: rx.loop: trace vmf message");
				vmf_ret = dlt_gw_trace_vmf_msg((vmf_basic_msg_t*)&(vmf_msg.vmf_basic_msg));

			}
        }
        else if (vmf_ret < 0)
        {
            /* there was a receive error - wait some time and try again */
            delay(20);
        }
        else
        {
            /* there was a timeout - ignore */
        }
    }
   
#else    
    /* register test context */
    VMF_TRACE_GW_INFO_PRINT("vmf_trace_dlt_gw_task: simple-test");
    if (dlt_error >= 0)
    {
        dlt_error = (*p_dlt_register_context)(&(dlt_context[0]), DLT_CONTEXTID, DLT_CONTEX_DESCRIPTION);
        if (dlt_error<0)
        {
            /* error registering context  */
            VMF_TRACE_GW_ERROR_PRINT("vmf_trace_dlt_gw_task: p_dlt_register_context failed");
        }
    }

    if (dlt_error >= 0)
    {
        for(num=0;num<127;num++)
        {
            char    chtmp[100]={0};

            snprintf(chtmp,sizeof(chtmp),"test-trace message %d",num);
            (void)dlt_gw_send(0,chtmp,num,num);
        }
    }
	
	
#endif

    /* unregister from dlt */
    VMF_TRACE_GW_INFO_PRINT("vmf_trace_dlt_gw_task: unregister from dlt");
    for (num=0;num<MAX_VMF_TRACE_TRIDS;num++)
    {
        if (dlt_context[num].contextID[0] != 0)
        {
            (void)(*p_dlt_unregister_context)(&(dlt_context[num]));
        }
    }

    (void)(*p_dlt_unregister_app)();    
    (void)(*p_dlt_free)();
    #if 0   /* this will crash ???? */
    (void)dlclose(dlt_library);
    #endif
    VMF_TRACE_GW_INFO_PRINT("vmf_trace_dlt_gw_task: done");
    return NULL;
}


/**************************************************************************//**
 *
 *   Function Name: dlt_gw_trace_ctrl_parser(vmf_basic_msg_t)
 *
 *   Description:   parse a trace ctrl message
 *
 *   Parameters:    vmf basic message
 *
 *   Function Return value: - void
 *
 ******************************************************************************/
static vmf_ret_t dlt_gw_trace_ctrl_parser(vmf_basic_msg_t *vmf_basic_msg)
{
    vmf_ret_t vmf_ret = VMF_ERROR;
    vmf_trace_ctrl_pl_t *pctrl_pl=NULL;
    
    /* arg check */
    if (NULL == vmf_basic_msg)
    {
        return VMF_ERR_NULL_POINTER;
    }
    
    pctrl_pl = (vmf_trace_ctrl_pl_t*)NW_VMF_BASIC_MSG_DATA_PTR(vmf_basic_msg);
    switch (NW_VMF_BASIC_MSG_EVENT(vmf_basic_msg))
    {
        /* a trace clinet wants to register */
       case VMF_TRACE_CTRL_REG_CLIENT:
       {
			unsigned8 trid;
			int       dlt_error= 0;
			char *    cl_name=NULL;
			char      dlt_context_id[5]={0};

			trid = pctrl_pl->reg_client.trid;
			cl_name = pctrl_pl->reg_client.name;
			
			snprintf(dlt_context_id,sizeof(dlt_context_id),"%04d",trid); 
			
            if (dlt_context[trid].contextID[0] == 0)
			{
				VMF_TRACE_GW_INFO_PRINT("dlt_gw_trace_ctrl_parser: VMF_TRACE_CTRL_REG_CLIENT, dlt_context_id=%s,trid=%d, cl_name=%s",dlt_context_id,trid,cl_name);
				/* register context to dlt */
				dlt_error = (*p_dlt_register_context)(&(dlt_context[trid]), dlt_context_id, cl_name);
				if (dlt_error<0)
				{
					/* error registering context  */
					VMF_TRACE_GW_ERROR_PRINT("dlt_gw_trace_ctrl_parser: p_dlt_register_context %s failed",dlt_context_id);
				}
			}
			else
			{
				VMF_TRACE_GW_WARNING_PRINT("dlt_gw_trace_ctrl_parser: VMF_TRACE_CTRL_REG_CLIENT, dlt_context_id=%s,trid=%d, cl_name=%s already registered",dlt_context_id,trid,cl_name);
			}
       }
       break;

       default:
        /* ignore all other ctrl events */
       break;
    }
    
    return vmf_ret;
}

/**************************************************************************//**
 *
 *   Function Name: dlt_gw_trace_msg(vmf_basic_msg_t)
 *
 *   Description:   handle a vmf trace message
 *
 *   Parameters:    vmf basic message
 *
 *   Function Return value: - void
 *
 ******************************************************************************/
static vmf_ret_t dlt_gw_trace_msg(vmf_basic_msg_t *vmf_basic_msg)
{
    vmf_trace_pl_t      *p_trace_pl;
	char				*msg=NULL;
    vmf_ret_t			vmf_ret = VMF_ERROR;
	int		 			tpl_len=0;

    /* arg check */
    if (NULL == vmf_basic_msg)
    {
        return VMF_ERR_NULL_POINTER;
    }
    
    p_trace_pl = (vmf_trace_pl_t*)vmf_basic_msg->data.pl;
	tpl_len = p_trace_pl->tpl_len;

    VMF_TRACE_GW_INFO_PRINT2("dlt_gw_trace_msg: VMF_BASIC_MSG_LEN(vmf_basic_msg->data.length)=%d, VMF_DLT_GW_MSG_SIZE=%d",VMF_BASIC_MSG_LEN(vmf_basic_msg->data.length),VMF_DLT_GW_MSG_SIZE);

    /* there is no terminating zero at the end of the original trace message - so add */
    if (VMF_BASIC_MSG_LEN(vmf_basic_msg->data.length) < VMF_DLT_GW_MSG_SIZE)
    {
        /* add a string delimiter */
        p_trace_pl->tpl[tpl_len]=0;
    }

	/* remove some of the prefix text */
	{
		int cnt;
		int num=2;
		int len=0;
		
		msg = p_trace_pl->tpl;
		len = strlen(msg);
		for (cnt=0;cnt<len;cnt++)
		{
			if ((msg[cnt]==VMF_TRACE_MSG_DELIMITER_C))
			{
				num--;
				if (0 == num)
				{
					msg = &msg[cnt+1];
					break;
				}
			}
		}
	}
	vmf_ret = dlt_gw_send(p_trace_pl->trid, msg,p_trace_pl->severity,p_trace_pl->num);
    
    return vmf_ret;
}


/**************************************************************************//**
 *
 *   Function Name: dlt_gw_trace_vmf_msg(vmf_basic_msg_t)
 *
 *   Description:   trace a vmf message
 *
 *   Parameters:    vmf basic message
 *
 *   Function Return value: - void
 *
 ******************************************************************************/
static vmf_ret_t dlt_gw_trace_vmf_msg(vmf_basic_msg_t *vmf_basic_msg)
{
    vmf_ret_t vmf_ret = VMF_ERROR;
    static char chData[(MAX_DEBUG_MSG_SIZE*3)+10];
    static char chTmp[(MAX_DEBUG_MSG_SIZE*3)+100];
    unsigned8   u8MsgGrp=0;
    unsigned8   u8EvtId=0;
    unsigned16  u16DataLen=0;
    pid_t       pid;
	unsigned8   cid;
	int			debug_len=0;

    /* arg check */
    if (NULL == vmf_basic_msg)
    {
        return VMF_ERR_NULL_POINTER;
    }

	if (vmf_basic_msg->msg_base.base.msg_type != MSG_TYPE_BASIC_MESSAGE)
	{
		/* we only monitor basic messages */
		return VMF_OK;
	}

    chData[0]=0;
    pid         = vmf_basic_msg->msg_base.base.pid;
    cid         = vmf_basic_msg->msg_base.base.client_id;
    u8MsgGrp    = vmf_basic_msg->msg_base.id.group;
    u8EvtId     = vmf_basic_msg->msg_base.id.event;
    u16DataLen  = vmf_basic_msg->data.length;	
	
    if (u16DataLen > 0)
    {
        my_HexDump(chData,"","" ,sizeof(chData),vmf_basic_msg->data.pl, u16DataLen);
        snprintf(chTmp,sizeof(chTmp),"pid=%d ,cid=%d, MsgGrp=0x%02X ,MsgId=0x%02X ,len=%d ,data(HEX)={ %s }",\
             pid,cid,u8MsgGrp,u8EvtId,u16DataLen,chData);
    }
    else
    {
        snprintf(chTmp,sizeof(chTmp),"pid=%d ,cid=%d, MsgGrp=0x%02X ,MsgId=0x%02X ,len=%d",\
             pid,cid,u8MsgGrp,u8EvtId,u16DataLen);
    }
	debug_len = strlen(chTmp);
	
    VMF_TRACE_GW_INFO_PRINT2("dlt_gw_vmf_msg:   tpl='%s',len=%d",chTmp,debug_len);
    vmf_ret = dlt_gw_send(CONTEXT_MSG, chTmp,VMF_TRACE_SEVERITY_INFO_20,debug_len);
	
    return vmf_ret;
}

/**************************************************************************//**
 *
 *   Function Name: dlt_gw_send(void *not_used)
 *
 *   Description:   send a trace message to dlt
 *
 *   Parameters:    unused
 *
 *   Function Return value: - void
 *
 ******************************************************************************/
static vmf_ret_t dlt_gw_send(unsigned8 trid, char *trace_msg,unsigned8 vmf_severity,int msg_num)
{
    DltContextData  ContextData; 
    int             dlt_error= 0;
    DltLogLevelType dlt_log_level;
    vmf_ret_t       ret_val=VMF_OK;

	
    /* arg check */
    if (trid > MAX_VMF_TRACE_TRIDS)
    {
        VMF_TRACE_GW_ERROR_PRINT("dlt_gw_send: invalid trid = %d",trid);
        return VMF_ERROR;
    }
	else if (NULL == trace_msg)
	{
        VMF_TRACE_GW_ERROR_PRINT("dlt_gw_send: NULL pointer");
        return VMF_ERR_NULL_POINTER;
	}
    
    /* test if context already registered */
    if (0 == dlt_context[trid].contextID[0])
    {
        VMF_TRACE_GW_WARNING_PRINT("dlt_gw_send: context for trid %d not registerd - use default context",trid);
		trid = 0;
    }

	VMF_TRACE_GW_INFO_PRINT2("dlt_gw_send: send '%s' to dlt",trace_msg);

	
    /* convert severity */
    dlt_log_level = dlt_gw_severity(vmf_severity);
    
    dlt_error = (*p_dlt_user_log_write_start_id)(&(dlt_context[trid]),&ContextData,dlt_log_level,msg_num);
    if (dlt_error<0)
    {
        VMF_TRACE_GW_ERROR_PRINT("dlt_gw_send: p_dlt_user_log_write_start_id failed");
        ret_val = VMF_ERROR;
    }
    dlt_error = (*p_dlt_user_log_write_string)(&ContextData,trace_msg);
    if (dlt_error<0)
    {
        VMF_TRACE_GW_ERROR_PRINT("dlt_gw_send: p_dlt_user_log_write_string failed");
        ret_val = VMF_ERROR;
    }
    dlt_error = (*p_dlt_user_log_write_finish)(&ContextData); 
    if (dlt_error<0)
    {
        VMF_TRACE_GW_ERROR_PRINT("dlt_gw_send: p_dlt_user_log_write_finish failed");
        ret_val = VMF_ERROR;
     }

	VMF_TRACE_GW_INFO_PRINT2("dlt_gw_send: send done");

    return ret_val;
}

/**************************************************************************//**
 *
 *   Function Name: dlt_gw_severity(void *not_used)
 *
 *   Description:   convert VMF severity to dlt severity
 *
 *   Parameters:    VMF severity
 *
 *   Function Return value: dlt severoty
 *
 ******************************************************************************/
static DltLogLevelType  dlt_gw_severity(unsigned8 vmf_severity)
{
    DltLogLevelType dlt_ret = DLT_LOG_INFO;		// DLT_LOG_OFF; /* crash !! */
    
    if (vmf_severity <= VMF_TRACE_SEVERITY_ERROR_5)
    {
        dlt_ret = DLT_LOG_FATAL;
    }
    else if (vmf_severity < VMF_TRACE_SEVERITY_WARNING)
    {
        dlt_ret = DLT_LOG_ERROR;
    }
    else if (vmf_severity < VMF_TRACE_SEVERITY_INFO)
    {
        dlt_ret = DLT_LOG_WARN;
    }
    else if (vmf_severity <= VMF_TRACE_SEVERITY_INFO_20)
    {
        dlt_ret = DLT_LOG_INFO;
    }
    else if (vmf_severity <= 100)
    {
        dlt_ret = DLT_LOG_INFO;		//  DLT_LOG_DEBUG; /* crash !! */
    }
    else if (vmf_severity <= 127)
    {
        dlt_ret = DLT_LOG_INFO;		//  DLT_LOG_VERBOSE; /* crash */
    }
    else
    {
        dlt_ret = DLT_LOG_INFO;		//  DLT_LOG_OFF;	/* crash !! */
    }

	VMF_TRACE_GW_INFO_PRINT2("dlt_gw_severity: vmf-severity=%d, dlt-severity=%d",vmf_severity,dlt_ret);
	
    return dlt_ret;
}

/**************************************************************************//**
 *
 *   Function Name: nw_vmf_dlt_set_monitor_msg_grps(unsigned8 *groups,int groups_num)
 *
 *   Description:   set the vmf groups that are monitored by dlt
 *
 *   Parameters:    groupsm number of groups
 *
 *   Function Return value: vmf_ret_t
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_dlt_set_monitor_msg_grps(unsigned8 *groups,int groups_num)
{
	vmf_ret_t ret_val=VMF_OK;
	
	if (NULL == groups)
	{
		return VMF_ERR_NULL_POINTER;
	}

	/* store groups  */
	nw_os_smemcpy(vmf_monitored_groups,sizeof(vmf_monitored_groups),groups,groups_num);
	vmf_monitored_groups_num= groups_num;

	return ret_val;
}



/**************************************************************************//**
 *
 *   Function Name: my_hexdump(void * Meme, unsigned Length)
 *
 *   Description:   create a ascii hex dump
 *
 *   Parameters:
 *
 *   Function Return value: - void
 *
 ******************************************************************************/
static void my_HexDump(char *pchDestBuffer,char *pchPrefixText,char *pchSufixText,unsigned16 u16DestBuffLen,unsigned8 *u8mem, unsigned length)
{
    unsigned16  uCnt;
    bool        bCut=false;

    char *t = pchDestBuffer;

    if ((NULL == pchDestBuffer) | (NULL == pchPrefixText) | (NULL == pchSufixText))
    {
        return;
    }


    /* to speedup things */
    if (length == 0)
    {
        sprintf(t, "%s %s", pchPrefixText,pchSufixText);
        return;
    }
    else if (length == 1)
    {
        sprintf(t, "%s %02x %s", pchPrefixText,u8mem[0],pchSufixText);
        return;
    }
    else if (length == 2)
    {
        sprintf(t, "%s %02x %02x %s", pchPrefixText,u8mem[0],u8mem[1],pchSufixText);
        return;
    }



    /* calculate the destination string length */
    uCnt = strlen(pchPrefixText) + strlen(pchSufixText) + (length*3);
    if (u16DestBuffLen < uCnt)
    {
        length = (u16DestBuffLen - (strlen(pchPrefixText) + strlen(pchSufixText)+10))/3;
        bCut = true;
    }

    t += sprintf(t, "%s ", pchPrefixText);

    for (uCnt = 0; uCnt < length; uCnt++)
    {
        t += sprintf(t, "%02x ", u8mem[uCnt]);
    }
    if (bCut)
    {
        t += sprintf(t, "...");
    }
    else
    {
        t += sprintf(t, "%s", pchSufixText);
    }
}

/**************************************************************************//**
 *
 *   Function Name: vmf_dlt_early_register_contexts(void)
 *
 *   Description:   register some contexts early
 *
 *   Parameters:
 *
 *   Function Return value: - void
 *
 ******************************************************************************/
static int vmf_dlt_early_register_contexts(void)
{
    int             dlt_error= 0;
	{
		/* register default context */
		VMF_TRACE_GW_INFO_PRINT("vmf_trace_dlt_gw_task: p_dlt_register_context %d as %s",CONTEXT_DEFAULT,"VMF_DEFAULT");
		dlt_error = (*p_dlt_register_context)(&(dlt_context[CONTEXT_DEFAULT]), "DEF", "VMF_DEFAULT");
		if (dlt_error<0)
		{
			/* error registering app */
			VMF_TRACE_GW_ERROR_PRINT("vmf_trace_dlt_gw_task: p_dlt_register_context - register default context failed");
		}
		else
		{	/* these registrations are nice to have - we will go on if registration fails */
			VMF_TRACE_GW_INFO_PRINT("vmf_trace_dlt_gw_task: p_dlt_register_context %d as %s",vmf_dlt_trid,"dltg");
			if (vmf_dlt_trid != 0)
			{
				dlt_error = (*p_dlt_register_context)(&(dlt_context[vmf_dlt_trid]), "DLTG", "VMF-dlt gateway");
				if (dlt_error<0)
				{
					/* error registering app */
					VMF_TRACE_GW_WARNING_PRINT("vmf_trace_dlt_gw_task: p_dlt_register_context - register default context failed");
				}
			}
			VMF_TRACE_GW_INFO_PRINT("vmf_trace_dlt_gw_task: p_dlt_register_context %d as %s",1,"VMF-server");
			dlt_error = (*p_dlt_register_context)(&(dlt_context[CONTEXT_VMF]), "VMF", "VMF-server");
			if (dlt_error<0)
			{
				/* error registering app */
				VMF_TRACE_GW_WARNING_PRINT("vmf_trace_dlt_gw_task: p_dlt_register_context - register 'vmf' context failed");
			}

			VMF_TRACE_GW_INFO_PRINT("vmf_trace_dlt_gw_task: p_dlt_register_context %d as %s",CONTEXT_MSG,"MSG");
			dlt_error = (*p_dlt_register_context)(&(dlt_context[CONTEXT_MSG]), "MSG", "VMF-basic-message");
			if (dlt_error<0)
			{
				/* error registering app */
				VMF_TRACE_GW_WARNING_PRINT("vmf_trace_dlt_gw_task: p_dlt_register_context - register 'vmf' context failed");
			}
			
			
			dlt_error = 0;		/* ignore registration errors */
		}
		return dlt_error;
	}
	
	
}




#endif  /* #ifdef __LINUX__ */ 


