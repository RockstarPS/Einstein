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
*  MODULE DATE  :   23 April 2013                                              *
*******************************************************************************
*  MODULE DESCRIPTION  :                                                      *
*  VMF_TRACE                                                                  *
******************************************************************************/

/***************************************************************************

  Module:               nw_vmf_tardis.c
  Description:          implementation of target discovery protocol

  Project Scope:        

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   gcc
  Target Hardware:      Any

  *****************************************************************************/
#ifdef VMF_TARDIS
#define _VMF_TARDIS_C

#include "nw_os_config.h"
#include "nw_vmf_cfg.h"           /* vmf cfg file */
#include "nw_vmf_types.h" 
#include "nw_vmf_debug.h"
#include "nw_vmf_tardis.h"        
#include "nw_vmf_controller.h"        
#include "nw_vmf_trace_server.h"

#if 0
#define FULL_DEBUG
#endif

#ifdef FULL_DEBUG
#define MY_TRACE(arg...)        fprintf(ERROR_CHANNEL,arg);fprintf(ERROR_CHANNEL,"\n");fflush(ERROR_CHANNEL)
#define MY_TRACE2(arg...)       fprintf(ERROR_CHANNEL,arg);fprintf(ERROR_CHANNEL,"\n");fflush(ERROR_CHANNEL)
#define MY_ERROR(arg...)        fprintf(ERROR_CHANNEL,arg);fprintf(ERROR_CHANNEL,"\n") ;fflush(ERROR_CHANNEL)
#else
#define MY_TRACE(arg...) 
#define MY_TRACE2(arg...)           
#define MY_ERROR(arg...)        /*fprintf(ERROR_CHANNEL,arg);fprintf(ERROR_CHANNEL,"\n");fflush(ERROR_CHANNEL)*/
#endif


/* module global variables */
static SOCKET       udp_sock=0;

/* external data */
extern char         tardis_name[];
extern unsigned16   tardis_category;
extern char         tardis_broadcast_addr[];

/* local functions */
static void         *vmf_tardis_thread(void *pArg);
static void         vmf_tardis_parse_msg(unsigned8 *pbuff,int buff_size);
static vmf_ret_t    vmf_tardis_parse_time_request(unsigned8 *pbuff,int msg_len);
static vmf_ret_t    vmf_tardis_parse_name_request(unsigned8 *pbuff,int msg_len);
static vmf_ret_t    vmf_tardis_parse_sysinfo_request(unsigned8 *pbuff,int msg_len);
static vmf_ret_t    vmf_tardis_parse_name_response(unsigned8 *pbuff,int msg_len);
static vmf_ret_t    vmf_tardis_send_name_response(unsigned16 port);
static vmf_ret_t    vmf_tardis_send_time_response(unsigned16 port);
static vmf_ret_t    vmf_tardis_send_sysinfo_response(unsigned16 port);
static vmf_ret_t    vmf_tardis_send_msg(unsigned8 *pbuff,int msg_len,unsigned16 port);


/*************************************************************************//**
 *
 *   create the tardis thread  \n
 *   NOTE: this thread will act as the tardis UDP server
 *   
 *
 *   \param[in] void      -- void
 *   \return    vmf_ret_t 
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_create_tardis_thread (void)
{
#ifndef DISABLE_TARDIS
    pthread_t       th;
    pthread_attr_t  attr;
    int             iRet;
	char Thread_name[100];
    
    MY_TRACE("nw_vmf_create_tardis_thread()");
    
    (void)pthread_attr_init(&attr);
    (void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );
    
    /* set the thread stack size*/
    #ifndef __ANDROID__
    iRet = pthread_attr_setstacksize  (&attr, VMF_NW_STACK_SIZE);
    if (EOK != iRet)
    {
        MY_ERROR("rem_vmf: nw_vmf_create_sysinfo_thread() - pthread_attr_setstacksize() failed: %d", iRet);
    }
    #endif

    iRet = pthread_create (&th  , &attr, vmf_tardis_thread, NULL);
    (void)pthread_attr_destroy(&attr);
    if (iRet)
    {
        MY_ERROR("rem_vmf: nw_vmf_create_sysinfo_thread() - pthread_create() failed: %d", iRet);
        return VMF_ERROR;
    }
    
#if ((defined(__QNX__) && (_NTO_VERSION >= 632)) || defined(__LINUX__))		
    /* Name the vmf-Logger thread */
	sprintf(Thread_name, "Vmf-Tardis-%d", th);
	nw_os_set_thread_name(th, Thread_name);    
#endif

#endif    
    return VMF_OK;
}


/*************************************************************************//**
 *
 *   vmf tardis thread \n
 *   NOTE: this function will never return
 *   
 *
 *   \param[in] void *     -- not used
 *   \return    void *     -- not used
 *
 ******************************************************************************/
static void *vmf_tardis_thread(void *pArg)
{
    unsigned8           buf[VMF_TARDIS_BUF_LEN];
    SOCKADDR_IN         addr;               /* sockaddr */
    SOCKADDR_IN         addr_cp;            /* sockaddr of counterpart */
    int                 result=0;
    socklen_t           addr_cp_len = sizeof(SOCKADDR_IN);
    
    MY_TRACE("vmf_tardis_thread() thread started");

    UNUSED_PARAM(pArg);

    #ifdef __WINDOWS__
    {
        WSADATA      wsaData;
        result = WSAStartup(MAKEWORD(2,2), &wsaData);
        if (result != 0)
        {
            MY_ERROR("vmf_tardis_thread(): WSAStartup failed: %d", result);
            return NULL;
        }
    }
    #endif
    
    /* try to create the socket */
    MY_TRACE("vmf_tardis_thread() create socket");
    while (true)
    {
        udp_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (udp_sock != -1)
        {
            /* got a socket */
            break;
        }
        delay(100);    /* wait some time and try again */
    }
    MY_TRACE("vmf_tardis_thread() create socket done");

    
    /* try to set REUSEADDR option to prevent bind error if port was used a short time ago */
    {
        int on=1;
        (void)setsockopt(udp_sock, SOL_SOCKET,SO_REUSEADDR,(char *)&on,sizeof(on));
    }
    
    /* send name response to inform tools and other vmf targets that this vmf was started  to all tool port */
    {
        int i;
        (void)vmf_tardis_send_name_response(VMF_TARDIS_PORT);           /* send to other vmf targets*/

        /* send to tools */
        for (i=0; i<VMF_TL_TARDIS_PORT_NUM; i++)
        {
            (void)vmf_tardis_send_name_response(VMF_TL_TARDIS_PORT+i);   
        }
    }


    /* set up the socket address */
    memset((char *) &addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(VMF_TARDIS_PORT);

    /* bind socket to port */
    result = bind(udp_sock, (SOCKADDR*)&addr, sizeof(addr));
    if (result != 0)
    {
        MY_ERROR("vmf_tardis_thread(): bind failed");
        (void) closesocket(udp_sock);
    }
    else
    {
        /* reception loop */
        while (true)
        {
            result = recvfrom(udp_sock, (void *)buf, sizeof(buf), 0, (SOCKADDR*)&addr_cp, &addr_cp_len);
            if (result > 0)
            {
                vmf_tardis_parse_msg(buf,result);
            }
            else
            {
                /* wait some time and try again to receive */
                delay(50);
            }
        }
    }
    
    return NULL;
}


/*************************************************************************//**
 *
 *   parse the tardis message buffer \n
 *   
 *   
 *
 *   \param[in] pbuff    -- message buffer
 *   \param[in] msg_len  -- size of message
 *   \return    void 
 *
 ******************************************************************************/
static void vmf_tardis_parse_msg(unsigned8 *pbuff,int msg_len)
{
    /* test if valid  direction byte */
    switch (pbuff[VMF_TARDIS_OS_DIR])
    {
        case VMF_TARDIS_DIR_TAR2TOOL:
            return;             /* ignore message */
        /* break; --> unreachable! */    
        
        case VMF_TARDIS_DIR_TAR2TAR:
        break;

        case VMF_TARDIS_DIR_TOOL2AR:
        break;

        case VMF_TARDIS_DIR_TOOL2TOOL:
            return;             /* ignore message */
        /* break; --> unreachable! */    
        
        default:
            /* invalid direction byte */
            MY_TRACE("vmf_tardis_parse_msg() invalid direction byte");
            #ifdef FULL_DEBUG
            nw_con_HexDump("invalid direction byte ",pbuff,msg_len);
            #endif
            return;
        /* break; --> unreachable! */    
    }

    /* handle the commands */
    switch (pbuff[VMF_TARDIS_OS_CMD])
    {
        case VMF_TARDIS_NAME_REQUEST:
            (void) vmf_tardis_parse_name_request(pbuff,msg_len);
        break;
    
        case VMF_TARDIS_NAME_RESPONSE:
            (void) vmf_tardis_parse_name_response(pbuff,msg_len);
        break;

        case VMF_TARDIS_TIME_REQUEST:
            (void) vmf_tardis_parse_time_request(pbuff,msg_len);
        break;

        case VMF_TARDIS_SYSINFO_REQUEST:
            (void) vmf_tardis_parse_sysinfo_request(pbuff,msg_len);
        break;

        case VMF_TARDIS_SYSINFO_RESPONSE:
            /* ignore */
        break;
        
        default:
            /* invalid command byte */
            MY_TRACE("vmf_tardis_parse_msg() invalid command byte");
            #ifdef FULL_DEBUG
            nw_con_HexDump("invalid command byte ",pbuff,msg_len);
            #endif
            return;
        /* break; --> unreachable! */    
    }
}


/*************************************************************************//**
 *
 *   handle VMF_TARDIS_NAME_REQUEST \n
 *   
 *   
 *
 *   \param[in] port  -- UDP port of message requester
 *   \return    vmf_ret type 
 *
 ******************************************************************************/
static vmf_ret_t  vmf_tardis_send_name_response(unsigned16 port)
{
    unsigned8   buff[VMF_TARDIS_BUF_LEN];
    vmf_ret_t   vmf_ret=VMF_OK;
    int         buff_index = VMF_TARDIS_OS_DIR;
    
    MY_TRACE("vmf_tardis_send_name_response() to port %d",port);
    MY_TRACE("vmf_tardis_send_name_response() tardis_name=%s",tardis_name);
    

    /* create name response message */
    memset((char *) &buff, 0, sizeof(buff));
    buff[buff_index++] = VMF_TARDIS_DIR_TAR2TOOL;       
    buff[buff_index++] = VMF_TARDIS_NAME_RESPONSE;
    if (tardis_category != VMF_TARDIS_TC_INVALID)
    {
        /* use command line category */
        buff[buff_index++] = tardis_category;              /* target category */
        MY_TRACE("vmf_tardis_send_name_response() tardis_category=%d",tardis_category);
    }
    else
    {
        buff[buff_index++] = VMF_TARDIS_TC_HU;             /* target class */
    }
    
    buff[buff_index++] = (unsigned8)strlen(tardis_name);   /* name length */

    /* copy name */
    memcpy(&(buff[buff_index]),tardis_name,strlen(tardis_name));
    buff_index+=(strlen(tardis_name));
    
    /* send message */
    vmf_ret = vmf_tardis_send_msg(buff,buff_index,port);
    
    return vmf_ret;
}

/*************************************************************************//**
 *
 *   send VMF_TARDIS_TIME_RESPONSE message\n
 *   send time response message to the given port
 *   
 *
 *   \param[in] port  -- UDP port of message requester
 *   \return    vmf_ret type 
 *
 ******************************************************************************/
static vmf_ret_t  vmf_tardis_send_time_response(unsigned16 port)
{
    unsigned32  current_time=0;
    unsigned8   buff[VMF_TARDIS_BUF_LEN];
    vmf_ret_t   vmf_ret=VMF_OK;
    int         buff_index = VMF_TARDIS_OS_DIR;
    
    MY_TRACE("vmf_tardis_send_time_reponse() to port %d",port);
    

    /* create vmf_tardis_send_time_reponse message */
    memset((char *) &buff, 0, sizeof(buff));
    buff[buff_index++] = VMF_TARDIS_DIR_TAR2TAR;       
    buff[buff_index++] = VMF_TARDIS_TIME_RESPONSE;
    
    /* time in big endian */
    current_time = nw_os_cfg_get_ms_time();
    buff[buff_index++] = (current_time >> 24) & 0xff;
    buff[buff_index++] = (current_time >> 16) & 0xff;
    buff[buff_index++] = (current_time >> 8) & 0xff;
    buff[buff_index++] = (current_time >> 0) & 0xff;
    
    /* send message */
    vmf_ret = vmf_tardis_send_msg(buff,buff_index,port);
    
    return vmf_ret;
}

/*************************************************************************//**
 *
 *   send VMF_TARDIS_SYSINFO_RESPONSE message\n
 *   send response message to the given port
 *   
 *   
 *
 *   \param[in] port  -- UDP port of message requester
 *   \return    vmf_ret type 
 *
 ******************************************************************************/
static vmf_ret_t  vmf_tardis_send_sysinfo_response(unsigned16 port)
{
    vmf_ctrl_vmf_info_t     vmf_info;
    unsigned8               buff[VMF_TARDIS_BUF_LEN];
    vmf_ret_t               vmf_ret=VMF_OK;
    int                     buff_index = VMF_TARDIS_OS_DIR;
    
    MY_TRACE("vmf_tardis_send_sysinfo_response() to port %d",port);

    /* create name response message */
    memset((char *) &buff, 0, sizeof(buff));
    buff[buff_index++] = VMF_TARDIS_DIR_TAR2TOOL;       
    buff[buff_index++] = VMF_TARDIS_SYSINFO_RESPONSE;

    /* create sysinfo struct and copy to tx buffer */
    vmf_ret = nw_vmf_ctrl_create_vmf_info_response(&vmf_info);
    
    nw_os_smemcpy((void *)&buff[buff_index], sizeof(buff), (void*) &vmf_info, sizeof(vmf_info));
    buff_index+=sizeof(vmf_info);
    
    /* add status of startup queue */
    buff[buff_index++] = vmf_trace_server_startup_q_status();
    
    /* send message */
    vmf_ret = vmf_tardis_send_msg(buff,buff_index,port);
    
    return vmf_ret;
}



/*************************************************************************//**
 *
 *   handle VMF_TARDIS_NAME_RESPONSE \n
 *   
 *   
 *
 *   \param[in] pbuff    -- message buffer
 *   \param[in] msg_len  -- size of message
 *   \return    void 
 *
 ******************************************************************************/
static vmf_ret_t  vmf_tardis_parse_name_response(unsigned8 *pbuff,int msg_len)
{
    vmf_ret_t vmf_ret=VMF_OK;

    MY_TRACE("vmf_tardis_parse_name_response()");

    #ifdef FULL_DEBUG
    nw_con_HexDump("vmf_tardis_parse_name_response",pbuff,msg_len);
    #else
    UNUSED_PARAM(pbuff);
    UNUSED_PARAM(msg_len);
    #endif

    return vmf_ret;
}


/*************************************************************************//**
 *
 *   handle VMF_TARDIS_SYSINFOREQUEST \n
 *   
 *   
 *
 *   \param[in] pbuff    -- message buffer
 *   \param[in] msg_len  -- size of message
 *   \return    void 
 *
 ******************************************************************************/
static vmf_ret_t  vmf_tardis_parse_sysinfo_request(unsigned8 *pbuff,int msg_len)
{
    vmf_ret_t vmf_ret=VMF_OK;
    unsigned16 port=0;

    MY_TRACE("vmf_tardis_parse_sysinfo_request()");

    if (msg_len > (VMF_TARDIS_OS_PL))
    {
        port = pbuff[VMF_TARDIS_OS_PH] * 256 + pbuff[VMF_TARDIS_OS_PL];
    }
    if (port == 0)
    {
        MY_TRACE("vmf_tardis_parse_sysinfo_request() Error: port=0");
    }
    else
    {
        vmf_ret = vmf_tardis_send_sysinfo_response(port);
    }
    
    return vmf_ret;
}



/*************************************************************************//**
 *
 *   handle VMF_TARDIS_TIME_REQUEST \n
 *   
 *   
 *
 *   \param[in] pbuff    -- message buffer
 *   \param[in] msg_len  -- size of message
 *   \return    void 
 *
 ******************************************************************************/
static vmf_ret_t  vmf_tardis_parse_time_request(unsigned8 *pbuff,int msg_len)
{
    vmf_ret_t vmf_ret=VMF_OK;
    unsigned16 port=0;

    MY_TRACE("vmf_tardis_parse_time_request()");

    if (msg_len > (VMF_TARDIS_OS_PL))
    {
        port = pbuff[VMF_TARDIS_OS_PH] * 256 + pbuff[VMF_TARDIS_OS_PL];
    }
    if (port == 0)
    {
        MY_TRACE("vmf_tardis_parse_time_request() Error: port=0");
    }
    else
    {
        vmf_ret = vmf_tardis_send_time_response(port);
    }
    
    return vmf_ret;
}


/*************************************************************************//**
 *
 *   handle VMF_TARDIS_NAME_REQUEST \n
 *   
 *   
 *
 *   \param[in] pbuff    -- message buffer
 *   \param[in] msg_len  -- size of message
 *   \return    void 
 *
 ******************************************************************************/
static vmf_ret_t  vmf_tardis_parse_name_request(unsigned8 *pbuff,int msg_len)
{
    vmf_ret_t vmf_ret=VMF_OK;
    unsigned16 port=0;

    MY_TRACE("vmf_tardis_parse_name_request()");

    if (msg_len > (VMF_TARDIS_OS_PL))
    {
        port = pbuff[VMF_TARDIS_OS_PH] * 256 + pbuff[VMF_TARDIS_OS_PL];
    }
    if (port == 0)
    {
        MY_TRACE("vmf_tardis_parse_name_request() Error: port=0");
    }
    else
    {
        vmf_ret = vmf_tardis_send_name_response(port);
    }
    
    return vmf_ret;
}



/*************************************************************************//**
 *
 *   send a tardis message via UDP \n
 *   
 *   
 *
 *   \param[in] pbuff    -- message buffer
 *   \param[in] msg_len  -- size of message
 *   \return    void 
 *
 ******************************************************************************/
static vmf_ret_t  vmf_tardis_send_msg(unsigned8 *pbuff,int msg_len, unsigned16 port)
{
    static SOCKADDR_IN  addr_cp;            /* sockaddr of counterpart */
    static bool         socket_connected=false;
    static SOCKET       udp_tx_sock=0;
    vmf_ret_t           vmf_ret = VMF_ERROR;
    int                 ret_val;
    int                 flg;
    
    MY_TRACE("vmf_tardis_send_msg()");
    if (false == socket_connected)
    {
        /* create a dedicated transmission socket */
        udp_tx_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (-1 == udp_tx_sock)
        {
            /* error creating socket */
            MY_ERROR("vmf_tardis_send_msg() error creating socket");
            return vmf_ret;
        }

        /* allow broadcasts */
        flg=1;
        (void)setsockopt(udp_tx_sock,SOL_SOCKET,SO_BROADCAST,(const void *)&flg,(socklen_t)sizeof(flg));

        socket_connected = true;
    }

    /* set up the destination address */
    memset((char *) &addr_cp, 0, sizeof(addr_cp));
    addr_cp.sin_family      = AF_INET;
    addr_cp.sin_port        = htons(port);
    addr_cp.sin_addr.s_addr = inet_addr(tardis_broadcast_addr);
    
    /* send the message */
    ret_val = sendto(udp_tx_sock, (const void *)pbuff, msg_len,0, (SOCKADDR*) &addr_cp,(socklen_t)sizeof(addr_cp));
    if (ret_val == msg_len)
    {
        MY_TRACE("vmf_tardis_send_msg() sendto %d bytes OK",ret_val);
        #ifdef FULL_DEBUG
        nw_con_HexDump("vmf_tardis_send_msg",pbuff,msg_len);
        #endif
        vmf_ret = VMF_OK;
    }
    else
    {
        MY_ERROR("vmf_tardis_send_msg() sendto failed() - function returned %d",ret_val);
    }
    
    return vmf_ret;
}
#endif

