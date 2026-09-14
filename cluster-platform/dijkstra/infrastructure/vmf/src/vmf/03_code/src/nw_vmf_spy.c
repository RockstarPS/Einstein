/*****************************************************************************/
/* Copyright Statement                                                       */
/* CONFIDENTIAL - VISTEON CORPORATION                                        */
/* This is an unpublished work, which contains trade secrets, created in     */
/* 2002. Visteon Corporation owns all rights to this work and intends        */
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

  Module:             nw_vmf_spy.c
  Description:        spy for Visteon Message Framework
  Project Scope:
  Organization:       Joachim Becker
                      Visteon, TMS Software
  Version Control:
  Compiler/Assembler: gcc
  Target Hardware:    Any
  *****************************************************************************/
#include "nw_os_config.h"

/* application includes */
#include "nw_vmf.h"
#include "nw_vmf_cfg.h"
#include "nw_vmf_debug.h"
#include "nw_vmf_spy.h"


/* defines */
#define VMF_SPY_STACK_SIZE    VMF_NW_STACK_SIZE
#define VMF_SPY_THREAD_PRIO   (10)
#ifndef FOREVER
#define FOREVER (true)
#endif

#define MAX_SYSLOG_MSGLEN           400
#define VMF_SPY_PORT                514
#define VMF_SPY_CONNECT_RETRIES     100
#define VMF_SPY_TCP_SEND_RETRIES    20
#define VMF_SPY_UDP_SEND_RETRIES    20
#define VMF_SPY_DEFAULT_NETWORK     USE_TCPIP

#define USE_NOTHING             0
#define USE_UDP                 1
#define USE_TCPIP               2



/* error output */
#define VMF_SPY_ERROR_PRINT(args...)      NW_VMF_DEBUG_ERROR(args)


/* global variable */
static unsigned32           tspynow=0;
static unsigned8            tspyMsg=0;
static unsigned32           u32_most_msgs=0;
static unsigned32           u32_basic_msgs=0;
static vmf_client_id_t      vmf_cid;
static unsigned8            verbose=1;              /* verbosity               */


/* local functions */
static void         vmf_spy_dsp_msg             (vmf_msg_t *p_msg,unsigned32 u32MsgLen);
static void         vmf_spy_dsp_basic_msg       (vmf_msg_t *p_msg,unsigned32 u32MsgLen);
static void         vmf_spy_dsp_most_msg        (vmf_msg_t *p_msg,unsigned32 u32MsgLen);
static void         vmf_spy_dsp_ctrl_msg        (vmf_msg_t *p_msg,unsigned32 u32MsgLen);
static void         *vmf_spy_task               (void *pArg);
static bool         vmf_spy_write               (unsigned uPri,char *pstrMsg);
static bool         vmf_spy_connect_syslog      (int *iSock, struct sockaddr_in *rmtaddr);
static bool         vmf_spy_connect_tcp         (int *iSock, struct sockaddr_in *rmtaddr);
static unsigned32   vmf_get_time_in_ms          (unsigned64 clocks);
static vmf_ret_t    vmf_create_spy_connection   (void);

static bool         network_active=true;

static void my_HexDump          (char *pchDestBuffer,char *chPrefixText,char *chSufixText,unsigned16 u16DestBuffLen,unsigned8 *u8mem, unsigned length);
static void my_Hex16Dump        (char *pchDestBuffer,char *chPrefixText,char *chSufixText,unsigned16 u16DestBuffLen,unsigned16 *u16mem, unsigned length);
void set_my_priority            (unsigned8 priority);

#define WAIT_SOME_TIME          (20)           /* wait time in ms */

/*****************************************************************************
        vmf Spy
 ******************************************************************************/


/**************************************************************************//**
 *
 *   Function Name: vmf_get_time_in_ms(void)
 *
 *   Description:   get time in ms - input = clocks
 *
 *   Parameters:    clocks
 *
 *   Function Return value: - time in ms
 *
 ******************************************************************************/
static unsigned32 vmf_get_time_in_ms(unsigned64 clocks)
{
    return (nw_os_cfg_convert_clocks_to_ms_time(clocks));
}




/**************************************************************************//**
 *
 *   Function Name: vmf_create_spy_connection(void)
 *
 *   Description:   create a connection to the VMFServer
 *
 *   Parameters:    void
 *
 *   Function Return value: - handle or vmf-error - true if success
 *
 ******************************************************************************/
static vmf_ret_t vmf_create_spy_connection(void)
 {
    vmf_ret_t                   vmf_ret=VMF_OK;
    vmf_client_id_t             vmf_client_id;

    /*---------------------------------------------------
         register to the VMF server (via VMFClient)
      --------------------------------------------------- */


    /* connect to vmf-server via vmf-client lib */
    vmf_client_id = nw_vmf_connect( "vmf-spy",                               /* channel name or NULL  */
                                     NULL,                                   /* rx callback or NULL */
                                     0,                                      /* thread priority of rx callback function */
                                     VMF_SPY_QUEUE_SIZE,                     /* VMF queue size */
                                     VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD );   /* VMF message size */

    if (vmf_client_id < 0)
    {
        if (verbose > 5) VMF_SPY_ERROR_PRINT("vmf-spy: Can not connect to the vmf-server - error=%d\n",vmf_cid);
        return vmf_client_id;
    }

    /* register as a spy */
    vmf_ret = nw_vmf_register_spy(vmf_client_id);
    if (vmf_ret < 0)
    {
        if (verbose > 1) VMF_SPY_ERROR_PRINT("vmf-spy: nw_vmf_register_spy() failed\n");
        return vmf_ret;
    }

     return vmf_client_id;
 }




/**************************************************************************//**
 *
 *   Function Name: vmf_spy_task(uint32_T ulContext)
 *
 *   Description:   this task will handle the reception of VMF Events
 *
 *   Parameters:    task context
 *
 *   Function Return value: - void
 *
 ******************************************************************************/
static void *vmf_spy_task(void *pArg)
{
    char                        chTmp[50];
    vmf_client_id_t             vmf_client_id;

    /* set thread priority */
#ifdef CHANGE_SPY_PRIORITY
    set_my_priority(VMF_SPY_THREAD_PRIO);
#endif

    /* try to connect to vmf-server */
    while (FOREVER)
    {
        vmf_client_id = vmf_create_spy_connection();
        if (vmf_client_id < 0)
        {
            if (verbose > 3) VMF_SPY_ERROR_PRINT("vmf-spy: Can not register vmf connection\n");
            delay(WAIT_SOME_TIME);
        }
        else
        {
            break;
        }

    }

    /* send start message to syslog */
    tspynow = vmf_get_time_in_ms (nw_os_cfg_get_ms_time());
    sprintf (chTmp,"vmf-spy started");

    /* if we get an error here - the tcp stack isn't already running */
    /* so retry the write until the tcp-stack is up                  */
    while (false == vmf_spy_write((LOG_USER | LOG_NOTICE),chTmp))
    {
        delay(WAIT_SOME_TIME);   /* wait some time */
    }


    /* wait for vmf messages and send them to syslog */
    while (FOREVER)                     /* loop forever */
    {
        vmf_msg_t           vmf_msg;
        unsigned16          vmf_msg_len;


        vmf_msg_len = nw_vmf_receive (vmf_client_id,&vmf_msg,VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD);

        #ifdef VMF_ENABLE_MSG_CLK
            tspynow = vmf_get_time_in_ms (vmf_msg.vmf_most_msg.msg_base.base.msg_clk);
        #else
            tspynow = vmf_get_time_in_ms (nw_os_cfg_get_ms_time());
        #endif


        tspyMsg++;

        if(vmf_msg_len > 0)
        {
            /* send the message via syslog */
            vmf_spy_dsp_msg(&vmf_msg , vmf_msg_len);
        }
    }
    return NULL;            /* to prevent warning */
}



/**************************************************************************//**
 *
 *   Function Name: vmf_spy_create_thread
 *
 *   Description:   create spy thread
 *
 *
 *   Parameters:    void
 *
 *   Function Return value: return True or False.
 *
 ******************************************************************************/
bool vmf_spy_create_thread(void)
{
    pthread_t th;
    pthread_attr_t  attr;
    struct sched_param param;
    int iRet;
	char Thread_name[100];

    if (verbose > 5) VMF_SPY_ERROR_PRINT("bvm-profiler: vmf_spy_create_thread()\n");

    /* set thread stack */
    pthread_attr_init( &attr );

    /* set the attributes of the thread */
    (void)pthread_attr_setschedpolicy (&attr, SCHED_RR);
    param.sched_priority = VMF_SPY_THREAD_PRIO;

    #ifndef __ANDROID__
    iRet = pthread_attr_setstacksize  (&attr, VMF_SPY_STACK_SIZE);
    if (EOK != iRet)
    {
        VMF_SPY_ERROR_PRINT("vmf_spy_create_thread: pthread_attr_setstacksize() failed\n");
    }
    #endif

    (void)pthread_attr_setschedparam (&attr, &param );
    (void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );
#ifdef CHANGE_SPY_PRIORITY
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED );
#endif

    iRet = pthread_create (&th  ,&attr, vmf_spy_task, NULL);
    (void)pthread_attr_destroy(&attr);
    if (iRet)
    {
        if (verbose > 0) 
        {
            VMF_SPY_ERROR_PRINT("vmf_spy_create_thread: vmf_spy_create_thread() error errno = %d\n",iRet);
        }
        return false;
    }
    if (verbose > 2) 
    {
        VMF_SPY_ERROR_PRINT("vmf_spy_create_thread: vmf_spy_create_thread() OK\n");
    }
    
#if ((defined(__QNX__) && (_NTO_VERSION >= 632)) || defined(__LINUX__))		
    /* Name the vmf-spy thread */
	sprintf(Thread_name, "Vmf-Spy-%d", th);
	nw_os_set_thread_name(th, Thread_name);    
#endif

    return true;

}


/**************************************************************************//**
 *
 *   Function Name: set_my_priority
 *
 *   Description:   set the thread priority
 *
 *
 *   Parameters:    priority
 *
 *   Function Return value: void
 *
 ******************************************************************************/
void set_my_priority(unsigned8 priority)
{
    pthread_t thread_id = pthread_self ();
    int policy;
    struct sched_param params;

    pthread_getschedparam( thread_id, &policy, &params);
    params.sched_priority = priority;
    pthread_setschedparam( thread_id, policy, &params);
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
 *   Function Name: my_hexdump(void * Meme, unsigned Length)
 *
 *   Description:   create a ascii hex dump
 *
 *   Parameters:
 *
 *   Function Return value: - void
 *
 ******************************************************************************/
static void my_Hex16Dump(char *pchDestBuffer,char *pchPrefixText,char *pchSufixText,unsigned16 u16DestBuffLen,unsigned16 *u16mem, unsigned length)
{
    unsigned16  uCnt;
    bool        bCut=false;

    char *t = pchDestBuffer;

    if ((NULL == pchDestBuffer) | (NULL == pchPrefixText) | (NULL == pchSufixText))
    {
        return;
    }

    /* to speedup things a bit */
    if (length == 0)
    {
        sprintf(t, "%s %s", pchPrefixText,pchSufixText);
        return;
    }
    else if (length == 1)
    {
        sprintf(t, "%s %03x %s", pchPrefixText,u16mem[0],pchSufixText);
        return;
    }
    else if (length == 2)
    {
        sprintf(t, "%s %03x %03x %s", pchPrefixText,u16mem[0],u16mem[1],pchSufixText);
        return;
    }


    /* calculate the destination string length */
    uCnt = strlen(pchPrefixText) + strlen(pchSufixText) + (length*5);
    if (u16DestBuffLen < uCnt)
    {
        length = (u16DestBuffLen - (strlen(pchPrefixText) + strlen(pchSufixText)+10))/5;
        bCut = true;
    }

    t += sprintf(t, "%s ", pchPrefixText);

    for (uCnt = 0; uCnt < length; uCnt++)
    {
        t += sprintf(t, "%03x ", u16mem[uCnt]);
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
 *   Function Name: vmf_spy_dsp_most_msg()
 *
 *   Description:   send a decoded Most-Msg to syslog
 *
 *   Parameters:
 *
 *   Function Return value: - void
 *
 ******************************************************************************/
static void vmf_spy_dsp_most_msg(vmf_msg_t *pvmf_msg,unsigned32 u32MsgLen)
{
    unsigned16  u16SrcDevId=0;
    unsigned16  u16DestDevId=0;
    unsigned8   u8FblkkId=0;
    unsigned8   u8InstId=0;
    unsigned16  u16FktId=0;
    unsigned16  u16DataLen=0;
    unsigned8   u8opType=0;
    static char chTmpPrefix[300];
    static char chTmp[(3*MAX_DEBUG_MSG_SIZE)+10];   /* size of centr reg = 400 * 3 = 1200 + prexix text*/
    pid_t       pid;
    unsigned8   client_count=0;
    vmf_most_msg_t  *pmost_msg;
    chTmp[0]=0;

    pmost_msg = (vmf_most_msg_t*)pvmf_msg;

    pid =           pmost_msg->msg_base.base.pid;
    u8FblkkId =     pmost_msg->fblock_id;
    u8InstId  =     pmost_msg->inst_id;
    u8opType  =     pmost_msg->op_type;
    u16FktId  =     pmost_msg->func_id;
    u16SrcDevId =   pmost_msg->src_addr;
    u16DestDevId =  pmost_msg->tgt_addr;
    u16DataLen =    pmost_msg->data.length;

#ifdef VMF_DEBUG_INFOS
        client_count = pmost_msg->msg_base.base.client_count;        /* use client_count to store the number of receive clients */ 
#endif

    if (u16DataLen > MAX_DEBUG_MSG_SIZE)
    {
        u16DataLen = MAX_DEBUG_MSG_SIZE;
    }

    if (u16DataLen > 0)
    {
        snprintf(chTmpPrefix,sizeof(chTmpPrefix),"pid=%d ,clientnum=%d, SrcId=0x%04X ,TargetId=0x%04X ,FBlockId=0x%02X ,InstId=0x%02X ,FktId=0x%03X ,OpType=0x%01X ,len=%d ,data(HEX)={ ",\
                 pid,client_count,u16SrcDevId,u16DestDevId,u8FblkkId,u8InstId,u16FktId,u8opType,u16DataLen);
        my_HexDump(chTmp,chTmpPrefix," }", sizeof(chTmp),pmost_msg->data.pl, u16DataLen);
    }
    else
    {
        snprintf(chTmp,sizeof(chTmpPrefix),"pid=%d ,clientnum=%d, SrcId=0x%04X ,TargetId=0x%04X ,FBlockId=0x%02X ,InstId=0x%02X ,FktId=0x%03X ,OpType=0x%01X ,len=%d",\
                 pid,client_count,u16SrcDevId,u16DestDevId,u8FblkkId,u8InstId,u16FktId,u8opType,u16DataLen);
    }

    /* output the event to syslog */
    vmf_spy_write((LOG_USER | LOG_INFO),chTmp);

}

/**************************************************************************//**
 *
 *   Function Name: vmf_spy_dsp_basic_msg()
 *
 *   Description:   send a decoded basic-message to syslog
 *
 *   Parameters:
 *
 *   Function Return value: - void
 *
 ******************************************************************************/
static void vmf_spy_dsp_basic_msg(vmf_msg_t *pvmf_msg,unsigned32 u32MsgLen)
{
    static char chTmp[(MAX_DEBUG_MSG_SIZE*3)+10];
    static char chData[(MAX_DEBUG_MSG_SIZE*3)+10];
    unsigned8   u8MsgGrp=0;
    unsigned8   u8EvtId=0;
    unsigned16  u16DataLen=0;
    vmf_basic_msg_t *pbasic_msg;
    pid_t       pid;
    unsigned16  client_count=0;
    
    /* init */
    chData[0]=0;
    pbasic_msg  = (vmf_basic_msg_t*)pvmf_msg;
    pid         = pbasic_msg->msg_base.base.pid;
    u8MsgGrp    = pbasic_msg->msg_base.id.group;
    u8EvtId     = pbasic_msg->msg_base.id.event;
    u16DataLen  = pbasic_msg->data.length;



    client_count = pbasic_msg->msg_base.base.client_count;       /* use client_count to store the number of receive clients */ 

    if (u16DataLen > MAX_DEBUG_MSG_SIZE)
    {
        u16DataLen = MAX_DEBUG_MSG_SIZE;
    }

    if (u16DataLen > 0)
    {
        my_HexDump(chData,"","" ,sizeof(chData),pbasic_msg->data.pl, u16DataLen);
        snprintf(chTmp,sizeof(chTmp),"pid=%d ,clientnum=%d, MsgGrp=0x%02X ,MsgId=0x%02X ,len=%d ,data(HEX)={ %s }",\
             pid,client_count,u8MsgGrp,u8EvtId,u16DataLen,chData);
    }
    else
    {
        snprintf(chTmp,sizeof(chTmp),"pid=%d ,clientnum=%d, GrpId=0x%02X ,MsgId=0x%02X ,len=%d",\
             pid,client_count,u8MsgGrp,u8EvtId,u16DataLen);
    }

    /* output the msg to syslog */
    vmf_spy_write((LOG_USER | LOG_DEBUG),chTmp);


}



/**************************************************************************//**
 *
 *   Function Name: vmf_spy_dsp_ctrl_msg()
 *
 *   Description:   send a decoded control-message to syslog
 *
 *   Parameters:
 *
 *   Function Return value: - void
 *
 ******************************************************************************/
static void vmf_spy_dsp_ctrl_msg(vmf_msg_t *pvmf_msg,unsigned32 u32MsgLen)
{
    static  char chTmp[(MAX_DEBUG_MSG_SIZE*3)+10];
    static  char chTyp[(MAX_DEBUG_MSG_SIZE*3)+10];
    static  char chData[(MAX_DEBUG_MSG_SIZE*3)+10];

    vmf_basic_msg_t *pbasic_msg;
    pid_t       pid;
    msg_type_t msg_type;
    vmf_client_id_t cid;

    /* init */
    chTyp[0]=0;
    chTmp[0]=0;
    chData[0]=0;
    pbasic_msg  = (vmf_basic_msg_t*)pvmf_msg;
    pid         = pbasic_msg->msg_base.base.pid;
    cid         = pbasic_msg->msg_base.base.client_id;
    msg_type    = pbasic_msg->msg_base.base.msg_type;

    switch (msg_type)
    {
        case MSG_TYPE_CONNECT:
            snprintf(chTyp,sizeof(chTyp),"CONNECT");
        break;

        case MSG_TYPE_REGISTER_EXT_MOST_LINK:
            snprintf(chTyp,sizeof(chTyp),"REGISTER_EXT_MOST_LINK");
        break;

        case MSG_TYPE_REGISTER_MOST_FBLOCK:
            {
                snprintf(chTyp,sizeof(chTyp),"REGISTER_MOST_FBLOCK");
                snprintf(chData,sizeof(chData), "FbId=0x%02x, InstId=0x%02x",
                ((vmf_ctrl_msg_register_most_fblock_t*)pvmf_msg)->fBlockId,
                ((vmf_ctrl_msg_register_most_fblock_t*)pvmf_msg)->instId);
            }
        break;

        case MSG_TYPE_DE_REGISTER_MOST_FBLOCK:
            {
                snprintf(chTyp,sizeof(chTyp),"REGISTER_MOST_FBLOCK");
                snprintf(chData,sizeof(chData), "FbId=0x%02x, InstId=0x%02x",
                ((vmf_ctrl_msg_register_most_fblock_t*)pvmf_msg)->fBlockId,
                ((vmf_ctrl_msg_register_most_fblock_t*)pvmf_msg)->instId);
            }
        break;

        case MSG_TYPE_REGISTER_MOST_SHADOW:

            snprintf(chTyp, sizeof(chTyp),"REGISTER_MOST_SHADOW");
            snprintf(chTmp,sizeof(chTmp),"FbId=0x%02x, InstId=0x%02x, FktList (hex) = {",
                ((vmf_ctrl_msg_register_most_shadow_t*)pvmf_msg)->fBlockId,
                ((vmf_ctrl_msg_register_most_shadow_t*)pvmf_msg)->instId);

            my_Hex16Dump (chData,chTmp,"}",sizeof(chData),
                       ((vmf_ctrl_msg_register_most_shadow_t*)pvmf_msg)->funcIdList,
                       ((vmf_ctrl_msg_register_most_shadow_t*)pvmf_msg)->u16NumFKtIds);

        break;

        case MSG_TYPE_DE_REGISTER_MOST_SHADOW:
            snprintf(chTyp,sizeof(chTyp),"DE_REGISTER_MOST_SHADOW");
            snprintf(chData,sizeof(chData),"FbId=0x%02x, InstId=0x%02x",
                ((vmf_ctrl_msg_de_register_most_shadow_t*)pvmf_msg)->fBlockId,
                ((vmf_ctrl_msg_de_register_most_shadow_t*)pvmf_msg)->instId);
        break;

        case MSG_TYPE_REGISTER_MSG_GROUPS:
            snprintf(chTyp,sizeof(chTyp),"REGISTER_MSG_GROUPS");
            my_HexDump (chData,"MsgGroups (hex) =  {","}",sizeof(chData),
                       ((vmf_ctrl_msg_register_msg_group_t*)pvmf_msg)->groupList,
                       ((vmf_ctrl_msg_register_msg_group_t*)pvmf_msg)->groups_num);

        break;

        case MSG_TYPE_DE_REGISTER_MSG_GROUPS:
            snprintf(chTyp,sizeof(chTyp),"DE_REGISTER_MSG_GROUPS");
        break;

        case MSG_TYPE_START_RECEIVE:
            snprintf(chTyp,sizeof(chTyp),"START_RECEIVE");
        break;

        case MSG_TYPE_REGISTER_SPY:
            snprintf(chTyp,sizeof(chTyp),"REGISTER_SPY");
        break;

        default:
            snprintf(chTyp,sizeof(chTyp),"%d",msg_type);
        break;
    }


    /* generate complete output string */
    if (chData[0] != 0)
    {
        snprintf(chTmp,sizeof(chTmp),"pid=%d ,cid=%d ,msg-type=%s, data=%s",pid,cid,chTyp,chData);
    }
    else
    {
        snprintf(chTmp,sizeof(chTmp),"pid=%d ,cid=%d ,msg-type=%s",pid,cid,chTyp);
    }

    /* output the msg to syslog */
    vmf_spy_write((LOG_USER | LOG_NOTICE),chTmp);


}



/**************************************************************************//**
 *
 *   Function Name: vmf_spy_dsp_msg()
 *
 *   Description:   parse message for MOST or BASIC messages
 *                  then send messages to display functions
 *   Parameters:    vmf message, msg len
 *
 *   Function Return value: - void
 *
 ******************************************************************************/
static void vmf_spy_dsp_msg(vmf_msg_t *pvmf_msg,unsigned32 u32MsgLen)
{
    msg_type_t msg_type;

    if (0 == u32MsgLen)
    {
        /* empty msg */
        return;
    }

    if (NULL == pvmf_msg)
    {
        if (verbose > 0) VMF_SPY_ERROR_PRINT("nf_vmf_spy:vmf_spy_dsp_msg() pvmf_msg=NULL\n");
        return;
    }

    msg_type = pvmf_msg->vmf_most_msg.msg_base.base.msg_type;

    if( MSG_TYPE_MOST_MESSAGE == msg_type)
    {
        u32_most_msgs++;
        /* MOST msg */
        vmf_spy_dsp_most_msg(pvmf_msg,u32MsgLen);
    }
    else if (MSG_TYPE_BASIC_MESSAGE == msg_type)
    {
        u32_basic_msgs++;
        /* basic event */
        vmf_spy_dsp_basic_msg(pvmf_msg,u32MsgLen);
    }
    else
    {
        /* control message */
        vmf_spy_dsp_ctrl_msg(pvmf_msg,u32MsgLen);
    }

}




/*****************************************************************************
 *
 *   Function Name: vmf_spy_write(unsigned uPri,char *pstrMsg)
 *
 *   Description:   write message to socket via either TCP/IP or syslog
 *
 *   Parameters:    syslog - priotity, Message Buffer
 *
 *   Function Return value: - bool
 *
 ******************************************************************************/
static bool vmf_spy_write(unsigned uPri,char *pstrMsg)
{
    static int                  net_type = VMF_SPY_DEFAULT_NETWORK;
    char                        chSyslogMsg[MAX_SYSLOG_MSGLEN+20];
    char                        chSyslogMsgTcp[sizeof(chSyslogMsg)+1];
    int                         iLen;
    static bool                 bSockOpened=false;
    static int                  iSock;
    static struct sockaddr_in   rmtaddr;
    static unsigned16           msg_count=0;
    unsigned16                  error_count=0;
    int                         i;


    if (!network_active)
    {
        /* tcp-stack not active */
        return false;
    }

    if (!bSockOpened)
    {
        if (USE_TCPIP == net_type)
        {
            if (true == vmf_spy_connect_tcp(&iSock, &rmtaddr))
            {
                bSockOpened = true;
            }
            else
            {
                /* TCP/IP connection failed -- use syslog on UDP */
                net_type = USE_UDP;
            }
        }

        if (USE_UDP == net_type)
        {
            if(true == vmf_spy_connect_syslog(&iSock, &rmtaddr))
            {
                bSockOpened = true;
            }
            else
            {
                /* UDP connection failed -- don't connect any more */
                VMF_SPY_ERROR_PRINT("vmf-spy: deactivating vmf-spy because TCP/IP connection failed! \n");
                fflush(ERROR_CHANNEL);
                network_active=false;
                return false;
            }
        }
    }

    iLen = snprintf(chSyslogMsg, MAX_SYSLOG_MSGLEN, "<%d><SPY><%d><%dms> %s", uPri, msg_count, tspynow, pstrMsg);

    if (USE_TCPIP == net_type)
    {
        /* send via TCP/IP */
        iLen = sprintf(chSyslogMsgTcp, "%s~", chSyslogMsg);

        for (i=0;i<VMF_SPY_TCP_SEND_RETRIES;i++)
        {
            if (send(iSock, chSyslogMsgTcp, iLen,0) <= 0)
            {
                /* wait a bit before 2nd try */
                delay(100);

                if (send(iSock, chSyslogMsgTcp, iLen,0) <= 0)
                {
                    /* close socket before creating a new one */
                    closesocket(iSock);
                    delay(100);

                    /* there was an error - re-connect */
                    if (false == vmf_spy_connect_tcp(&iSock, &rmtaddr))
                    {
                        /* re-connect failed -- deactivate spy */
                        VMF_SPY_ERROR_PRINT("vmf-spy: deactivating vmf-spy because TCP/IP connection failed! \n");
                        fflush(ERROR_CHANNEL);
                        network_active=false;
                        return false;
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    else if (USE_UDP == net_type)
    {
        /* send via syslog */
        for (error_count=0;error_count<VMF_SPY_UDP_SEND_RETRIES;error_count++)
        {
            if (sendto(iSock, chSyslogMsg, iLen,0, (struct sockaddr *) &rmtaddr,(socklen_t)sizeof(rmtaddr)) <= 0)
            {
                /* there was an error - wait some time and try again */
                delay(WAIT_SOME_TIME);
            }
            else
            {
                break;
            }
        }

        if (VMF_SPY_UDP_SEND_RETRIES==error_count)
        {
            /* cannot send -- deactivate the spy */
            VMF_SPY_ERROR_PRINT("vmf-spy: deactivating vmf-spy because UDP is not running\n");
            fflush(ERROR_CHANNEL);
            network_active=false;
            return false;
        }

    }
    else
    {
        /* unknown net_type */
    }


    msg_count++;

    return true;
}



/*****************************************************************************
 *
 *   Function Name: int vmf_spy_connect_tcp(int *iSock, sockaddr_in *rmtaddr)
 *
 *   Description:   connect on TCP/IP
 *
 ******************************************************************************/
static bool vmf_spy_connect_tcp(int *iSock, struct sockaddr_in *rmtaddr)
{
    int  i;

    /* First try TCP/IP connection */
    for (i=0;i<VMF_SPY_CONNECT_RETRIES;i++)
    {
        *iSock = socket(AF_INET, SOCK_STREAM, 0);
        if (-1 != *iSock)
        {
            break;
        }
        delay(100);
    }

    if (VMF_SPY_CONNECT_RETRIES == i)
    {
        /* cannot open socket */
        VMF_SPY_ERROR_PRINT("vmf-spy: TCP/IP socket() failed...\n");
        return false;
    }

    rmtaddr->sin_family      = AF_INET;
    rmtaddr->sin_port        = htons(VMF_SPY_PORT);
    rmtaddr->sin_addr.s_addr = inet_addr(VMF_SPY_PROFILER_ADR);

    for (i=0;i<VMF_SPY_CONNECT_RETRIES;i++)
    {
        if (0 == connect(*iSock, (struct sockaddr *)rmtaddr, sizeof(struct sockaddr)))
        {
            break;
        }

        delay(100);
    }

    if (VMF_SPY_CONNECT_RETRIES == i)
    {
        /* cannot connect */
        /* VMF_SPY_ERROR_PRINT("vmf-spy: TCP/IP connect() failed...\n"); */
        return false;
    }

    /* VMF_SPY_ERROR_PRINT("vmf-spy: TCP/IP connect number connect tries == %d \n", i); */

    return true;
}

/*****************************************************************************
 *
 *   Function Name: int vmf_spy_connect_syslog(int net_type, int *iSock, sockaddr_in *rmtaddr)
 *
 *   Description:   connect syslog UDP
 *
 ******************************************************************************/
static bool vmf_spy_connect_syslog(int *iSock, struct sockaddr_in *rmtaddr)
{
    int flg;
    int i;

    /* use UDP syslog */
    for (i=0;i<VMF_SPY_CONNECT_RETRIES;i++)
    {
        *iSock = socket(AF_INET, SOCK_DGRAM, 0);
        if (-1 != *iSock)
        {
            break;
        }
        delay(100);
    }

    if (VMF_SPY_CONNECT_RETRIES == i)
    {
        /* cannot open socket */
        VMF_SPY_ERROR_PRINT("vmf-spy: UDP socket() failed...\n");
        return false;
    }

    /* allow broadcasts */
    flg=1;
    setsockopt(*iSock,SOL_SOCKET,SO_BROADCAST,&flg,sizeof(flg));

    /* do not allow routing by setting TTL to 1 */
    flg=1;
    setsockopt(*iSock,SOL_SOCKET,IP_MULTICAST_TTL,&flg,sizeof(flg));

    rmtaddr->sin_family      = AF_INET;
    rmtaddr->sin_port        = htons(VMF_SPY_PORT);
    rmtaddr->sin_addr.s_addr = inet_addr(VMF_SPY_BROADCAST_ADR);


    return true;
}



/*****************************************************************************
 *
 *   Function Name: MoccaSpyGetandClrMsgCount()
 *
 *   Description:   return the mocca and most message count
 *                  and delete the counter
 *   Parameters:    pointer to most and mocca message counts
 *
 *   Function Return value: - bool - false if invalid pointer
 *
 ******************************************************************************/
bool MoccaSpyGetAndClrMsgCount(unsigned32 *p32MOSTMsgs,unsigned32 *p32MOCCAMsgs)
{
    if ((NULL == p32MOSTMsgs) || (NULL == p32MOCCAMsgs))
    {
        /* invalid pointer */
        return false;
    }


    *p32MOSTMsgs=u32_most_msgs;
    u32_most_msgs=0;

    *p32MOCCAMsgs=u32_basic_msgs;
    u32_basic_msgs=0;


    return true;
}
