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

  Module:               nw_vmf_mi_main.c
  Description:          multi instance VMF extension - main app

  Project Scope:        multi platform

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   gcc
  Target Hardware:      Any

  *****************************************************************************/
#define VMF_MI_C

#include "nw_os_config.h"
#include "nw_config.h"

/* application includes */
#include "nw_vmf_types.h"
#include "nw_vmf_debug.h"
#include "nw_vmf_client.h"
#include "nw_vmf_cfg.h"           /* vmf cfg file */

#include "nw_vmf_trace.h"
#include "nw_vmf_ini_parser.h"
#include "nw_vmf_mi.h"
#ifdef VMF_ALLOW_COMPRESSION
#include "lzrw3.h"
#endif


extern char *__progname;

/* global data */
static vmf_mi_section_t     g_vmf_mi_sections[VMF_MI_MAX_SECTIONS];
static int                  g_num_sections=0;
static vmf_client_id_t      vmf_tx_cid=0;
static bool                 mi_enabled = false;
unsigned8                   vmf_mi_trid = 0;
#ifdef _LZRW3_H
__thread    unsigned8       *p_pack=NULL;
__thread    unsigned8       *p_unpack=NULL;
#endif

/* local functions */
static void        *nw_vmf_mi_starter_thread            (void *pNoArg);
static void         nw_vmf_mi_init_sections             (vmf_mi_section_t *sections, unsigned16 section_num);
static int          nw_vmf_mi_init                      (vmf_mi_section_t *vmf_mi_sections);
static vmf_ret_t    nw_vmf_mi_start_instances           (vmf_mi_section_t *vmf_mi_sections);
static void        *nw_vmf_mi_vmf_server_thread         (vmf_mi_section_t *p_ass_section);
static void        *nw_vmf_mi_tcp_server_thread         (vmf_mi_section_t *p_ass_section);
static vmf_error_t  vmf_mi_ipc_con_accept_sock          (vmf_mi_section_t *p_ass_section,SOCKET *p_connectedSocket,SOCKET p_bindSocket);
static unsigned16   vmf_mi_ipc_tcp_receive				(vmf_mi_section_t *p_ass_section,SOCKET connectedSocket,nw_vmf_mi_transfer_t *p_transfer_msg);
static vmf_ret_t vmf_mi_ipc_tcp_send(vmf_mi_section_t * p_ass_section,SOCKET txSocket,nw_vmf_mi_transfer_t *p_transfer_msg,unsigned16 transfer_msg_len);
//static vmf_ret_t    vmf_mi_ipc_tcp_send_keep_alive      (vmf_mi_section_t *p_ass_section,SOCKET txSocket);
static vmf_error_t  vmf_mi_ipc_connect_tx_sock          (vmf_mi_section_t *p_ass_section,SOCKET *p_txSocket);
static vmf_error_t  vmf_mi_ipc_create_and_bind_server_socket(vmf_mi_section_t * p_ass_section,int *p_rpc_srv_socket,unsigned16 port,unsigned16 ms_timeout);
static unsigned16   vmf_mi_decomp_lzrw3                 (unsigned8 *psrc, unsigned16 src_len, unsigned8 *pdest, unsigned16 dest_buff_len);
static unsigned16   vmf_mi_comp_lzrw3                   (unsigned8 *psrc, unsigned16 src_len, unsigned8 *pdest, unsigned16 dest_buff_len);

#ifdef VMF_MI_SET_SOCK_TIMEOUT
static vmf_error_t  vmf_mi_ipc_set_socket_timeout       (vmf_mi_section_t *p_ass_section,int mi_socket,unsigned16 ms_timeout) ;
#endif
static vmf_mi_num_dtype vmf_mi_get_num_dtype            (char *device_name);


/**************************************************************************//**
 *
 *   enable mi funcionality
 *
 *   \return        void
 *
 ******************************************************************************/
void nw_vmf_mi_enable_server(void)
{
    mi_enabled = true;
}

/**************************************************************************//**
 *
 *   return if mi funcionality is enabled
 *
 *   \return        true if mi enabled
 *
 ******************************************************************************/
bool nw_vmf_is_mi_enabled(void)
{
    return (mi_enabled);
}

/**************************************************************************//**
 *
 *   create vmf_mi starter thread
 *
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_mi_create_starter_thread(void)
{
    int iRet=0;
    pthread_t th;
    pthread_attr_t  attr;
    vmf_ret_t ret_val=VMF_ERROR;
	char Thread_name[100];

    /* check if mi enabled */
    if (false == mi_enabled)
    {
        ret_val = VMF_OK;
    }
	else
	{
		UNUSED_PARAM(vmf_mi_trid);
		if (VMF_TRACE_REGISTER(&vmf_mi_trid, VMF_TRACE_MI) < 0)
		{
			 VMF_MI_ERROR("nw_vmf_mi_starter_thread: CANNOT CONNECT TO VMF TRACER!!!");
		}

		VMF_MI_DEBUG_INFO(vmf_mi_trid,VMF_TRACE_GL_SCOPE,"nw_vmf_mi_create_starter_thread() mi enabled");

		/* set thread stack */
		(void) pthread_attr_init( &attr );

		#ifndef __ANDROID__
		if ( pthread_attr_setstacksize(&attr, VMF_MI_STACK_SIZE ) != 0 )
		{
			VMF_MI_DEBUG_ERROR(vmf_mi_trid,VMF_TRACE_GL_SCOPE,"nw_vmf_mi_create_starter_thread() - pthread_attr_setstacksize() failed");
		}
		#endif

		(void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );
		iRet = pthread_create (&th  , &attr, (void * (*)(void *))nw_vmf_mi_starter_thread, NULL);
		(void) pthread_attr_destroy(&attr);
		if (iRet)
		{
			VMF_MI_DEBUG_ERROR(vmf_mi_trid,VMF_TRACE_GL_SCOPE,"nw_vmf_mi_create_starter_thread() error! errno = %d",iRet);
		}
		else
		{
			ret_val = VMF_OK;
#if ((defined(__QNX__) && (_NTO_VERSION >= 632)) || defined(__LINUX__))
			sprintf(Thread_name, "Vmf-MI-Starter-%d", th);
			nw_os_set_thread_name(th,Thread_name);
#endif			
		}
	}

    return ret_val;
}




/**************************************************************************//**
 *
 *   create the tcp server thread
 *
 *   \param         pointer to associated section
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_mi_create_tcp_server_thread(vmf_mi_section_t *p_vmf_mi_section)
{
    int iRet=0;
    pthread_t th;
    pthread_attr_t  attr;
    vmf_ret_t ret_val=VMF_ERROR;

    /* argument check */
    if (NULL == p_vmf_mi_section)
    {
        ret_val = (VMF_ERR_NULL_POINTER);
    }
	else
	{
		/* set thread stack */
		(void) pthread_attr_init( &attr );

		#ifndef __ANDROID__
		if ( pthread_attr_setstacksize(&attr, VMF_MI_STACK_SIZE ) != 0 )
		{
			VMF_MI_ERROR("nw_vmf_mi_create_tcp_server_thread() - pthread_attr_setstacksize() failed");
		}
		#endif

		(void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );
		iRet = pthread_create (&th, &attr, (void * (*)(void *))nw_vmf_mi_tcp_server_thread, (void *)p_vmf_mi_section);
		(void) pthread_attr_destroy(&attr);
		if (iRet)
		{
			VMF_MI_ERROR("nw_vmf_mi_create_tcp_server_thread() error! errno = %d",iRet);
		}
		else
		{
			ret_val = VMF_OK;									
		}
	}

    return ret_val;
}


/**************************************************************************//**
 *
 *   create and start the tcp sender thread
 *
 *   \param         pointer to associated section
 *   \return        vmf_ret_t
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_mi_create_vmf_server_thread(vmf_mi_section_t *p_vmf_mi_section)
{
    int iRet=0;
    pthread_t th;
    pthread_attr_t  attr;
    vmf_ret_t ret_val;

    /* argument check */
    if (NULL == p_vmf_mi_section)
    {
        ret_val = (VMF_ERR_NULL_POINTER);
    }
	else
	{
		/* set thread stack */
		(void) pthread_attr_init( &attr );

		#ifndef __ANDROID__
		if ( pthread_attr_setstacksize(&attr, VMF_MI_STACK_SIZE ) != 0 )
		{
			VMF_MI_DEBUG_ERROR(vmf_mi_trid,VMF_TRACE_GL_SCOPE,"nw_vmf_mi_create_vmf_server_thread() - pthread_attr_setstacksize() failed");
		}
		#endif

		(void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );
		iRet = pthread_create (&th  , &attr, (void * (*)(void *))nw_vmf_mi_vmf_server_thread, (void*)p_vmf_mi_section);
		(void) pthread_attr_destroy(&attr);
		if (iRet)
		{
			VMF_MI_DEBUG_ERROR(vmf_mi_trid,VMF_TRACE_GL_SCOPE,"nw_vmf_mi_create_vmf_server_thread() error! errno = %d",iRet);
			ret_val = VMF_ERROR;
		}
		else
		{
			ret_val = VMF_OK;										
		}
	}

    return ret_val;
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_mi_starter_thread(void *pNoArg)
 *
 *   Description:   vmf mi starter thread
 *
 *   \param         ignore
 *   \return        NULL
 *
 ******************************************************************************/
static void *nw_vmf_mi_starter_thread(void *pNoArg)
{
    vmf_ret_t vmf_ret=VMF_ERROR;

    UNUSED_PARAM(pNoArg);

    nw_sleep_ms(VMF_MI_START_DELAY);

    VMF_MI_INFO("nw_vmf_mi_starter_thread\n");


    /* Register at VMF Tracer */
    if (VMF_TRACE_REGISTER(&vmf_mi_trid, VMF_TRACE_MI) < 0)
    {
         VMF_MI_ERROR("nw_vmf_mi_starter_thread: CANNOT CONNECT TO VMF TRACER!!!");
    }

    nw_os_set_current_thread_name("vmf_mi_starter");

    /* read ini file */
    g_num_sections = nw_vmf_mi_init(g_vmf_mi_sections);
    VMF_MI_DEBUG_INFO(vmf_mi_trid,VMF_TRACE_GL_SCOPE,"nw_vmf_mi_starter_thread number of sections=%d",g_num_sections);

    if (g_num_sections > 0)
    {
        vmf_ret = nw_vmf_mi_start_instances(g_vmf_mi_sections);
        if (vmf_ret != VMF_OK)
        {
            VMF_MI_DEBUG_ERROR(vmf_mi_trid,VMF_TRACE_GL_SCOPE,"nw_vmf_mi_start_instances() failed! error = %d",vmf_ret);
        }
    }
    else
    {
        VMF_MI_DEBUG_INFO(vmf_mi_trid,VMF_TRACE_GL_SCOPE,"nw_vmf_mi error interpreting ini file - no nw_vmf_mi instance started");
    }
    return NULL;
}



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_mi_start_instances(vmf_mi_section_t *vmf_mi_sections)
 *
 *   Description:   start all vmf-mi instances
 *
 *   \param         pointer to all sections
 *   \return        void
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_mi_start_instances(vmf_mi_section_t *vmf_mi_sections)
{
    unsigned16  cnt=0;
    vmf_ret_t   vmf_ret=VMF_ERROR;
    #ifdef __WINDOWS__
    WSADATA wsaData;
    (void)WSAStartup(MAKEWORD(2,2), &wsaData);
    #endif

    nw_assert(vmf_mi_sections != NULL);

    VMF_MI_DEBUG_INFO(vmf_mi_trid,VMF_TRACE_GL_SCOPE,"nw_vmf_mi_start_instances()");

    VMF_MI_INFO("nw_vmf_mi_start_instances()");
    while(true == vmf_mi_sections[cnt].in_use)
    {
        VMF_MI_INFO("nw_vmf_mi_start_instances() num_dtype=%d",vmf_mi_sections[cnt].num_dtype);
        switch(vmf_mi_sections[cnt].num_dtype)
        {
            case NDT_TCP:
#ifndef NO_SOCKETS
                vmf_ret = nw_vmf_mi_start_tcp_instance(vmf_mi_sections,cnt);
                if (vmf_ret != VMF_OK )
                {
                    VMF_MI_DEBUG_ERROR(vmf_mi_trid,VMF_TRACE_GL_SCOPE,"nw_vmf_mi_start_instances() section-name=%s failed",vmf_mi_sections[cnt].section_name);
                }
#endif
            break;

            case NDT_BLK:
            case NDT_CHAR:
            case NDT_VMQ:
            case NDT_FIFO:
                vmf_ret = nw_vmf_mi_start_dtf_instance(vmf_mi_sections,cnt);
                if (vmf_ret != VMF_OK )
                {
                    VMF_MI_DEBUG_ERROR(vmf_mi_trid,VMF_TRACE_GL_SCOPE,"nw_vmf_mi_start_instances() section-name=%s failed",vmf_mi_sections[cnt].section_name);
                }
            break;

            default:
                /* unknown type -ignore */
            break;
        }

        VMF_MI_INFO("nw_vmf_mi_start_instances() vmf_ret=%d, section_name=%s",vmf_ret,vmf_mi_sections[cnt].section_name);
        cnt++;
    }

    return vmf_ret;
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_mi_tcp_server_thread(uint32_T ulContext)
 *   Description:   tcp server thread
 *   Description:   this server is listening to a tcp port and will  forward
 *                  the received data to vmf
 *   \param         pointer to associated section
 *   \return        ignore
 *
 ******************************************************************************/
static void * nw_vmf_mi_tcp_server_thread(vmf_mi_section_t * p_ass_section)
{
    vmf_ret_t       ret_val=VMF_ERROR;
    unsigned8       my_section=0;
    char            Thread_name[200];
	pthread_t 		th;

    nw_assert(p_ass_section != NULL);
	
    if (NULL != p_ass_section)
    {
#if ((defined(__QNX__) && (_NTO_VERSION >= 632)) || defined(__LINUX__))
			th = pthread_self();	
			sprintf(Thread_name, "MI-VMF-TCP-%d-%s", th, p_ass_section->section_name);
			nw_os_set_thread_name(th,Thread_name);
#endif			
		/* Register at VMF Tracer */
		if (VMF_TRACE_REGISTER(&vmf_mi_trid, VMF_TRACE_MI) < 0)
		{
			VMF_MI_ERROR("nw_vmf_mi_starter_thread: CANNOT CONNECT TO VMF TRACER!!!");
		}
		else
		{
			VMF_MI_INFO("nw_vmf_mi_starter_thread: CONNECTed with VMF TRACER!!!");
		}

		VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_mi_tcp_server_thread(port=%d) created",p_ass_section->local_port);

		my_section = p_ass_section->this_section;
		if (0 == vmf_tx_cid)
		{
			/* connect to VMF */
			while(vmf_tx_cid == 0)
			{
				ret_val = nw_vmf_connect("vmf_mi_tcp_sender", NULL, 0, 0, 0);
				if (ret_val<=0)
				{
					nw_sleep_ms(WAIT_SOME_TIME*5);         /* wait for VMF */
				}
				else
				{
					/* store this cid as tx-cid*/
					vmf_tx_cid = ret_val;
				}
			}
			VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_mi_tcp_server_thread() connected to VMF cid=%d",ret_val);
			vmf_tx_cid = (vmf_client_id_t)ret_val;
		}
		else
		{
			VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_mi_tcp_server_thread() already connected to VMF - cid=%d",vmf_tx_cid);
		}
		VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_mi_tcp_server_thread() using cid=%d to tx data",vmf_tx_cid);

		/* start tcp listener now */
		{
			int mi_server_socket;
			int rc;
			vmf_ret_t       vmf_ret=VMF_ERROR;
			SOCKET          rpc_connected_socket;

			/* first bind socket */
			vmf_ret = vmf_mi_ipc_create_and_bind_server_socket(p_ass_section,&mi_server_socket,p_ass_section->local_port,VMF_MI_RX_TIMEOUT);
			if (vmf_ret == VMF_OK)
			{
				/* listen on socket */
				rc=listen(mi_server_socket,BACKLOG);
				if(SOCKET_ERROR==rc)
				{
					VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_mi_tcp_server_thread() listen failed");
					(void) closesocket(mi_server_socket);
				}
				else
				{
					while(VMF_OK==vmf_ret)
					{
						/* wait for new connection */
						vmf_ret = vmf_mi_ipc_con_accept_sock(p_ass_section,&rpc_connected_socket,mi_server_socket);
						if (VMF_OK == vmf_ret)
						{
							nw_vmf_mi_transfer_t    transfer_buffer;
							unsigned16  u_len=0;

							VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_mi_tcp_server_thread() connection accepted!");

							#ifdef VMF_MI_SET_SOCK_TIMEOUT
							(void)vmf_mi_ipc_set_socket_timeout(p_ass_section,rpc_connected_socket,VMF_MI_RX_TIMEOUT);
							#endif
							while(true)
							{
								/* receive tcp data  */
								u_len = vmf_mi_ipc_tcp_receive(p_ass_section,rpc_connected_socket,&transfer_buffer);
								if (u_len > 0)
								{
									/* we got message */
									/* forward it to vmf */
									vmf_ret = vmf_mi_vmf_sender(vmf_tx_cid,(vmf_msg_t*)&(transfer_buffer.vmf_msg),u_len,my_section);
								}
								else
								{
									(void) closesocket (rpc_connected_socket);
									break;
								}
							}
						}
						nw_sleep_ms(WAIT_SOME_TIME);
						VMF_MI_DEBUG_WARNING(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_mi_tcp_server_thread() vmf_mi_ipc_con_accept_sock failed");
					}
					
					(void) closesocket(mi_server_socket);
				}
			}
			else
			{
				VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_mi_tcp_server_thread() vmf_mi_ipc_create_and_bind_server_socket failed");
			}
		}
	}
	else
	{
        VMF_MI_ERROR("nw_vmf_mi_tcp_server_thread() p_ass_section=NULL");
	}

    return NULL;
}




/**************************************************************************//**
 *
 *   Function Name: nw_vmf_mi_vmf_connect(uint32_T ulContext)
 *   Description:   connect to vmf and register message groups
 *
 *   \param         pointer to associated section
 *   \return        void *
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_mi_vmf_connect(vmf_mi_section_t * p_ass_section)
{
    vmf_client_id_t cid=0;
    vmf_ret_t       ret_val=VMF_ERROR;

    /* connect to VMF */
    {
        char tmp[40];
        (void) snprintf(tmp,sizeof(tmp),"vmf-mi-%s",p_ass_section->section_name);

        while(ret_val <= 0)
        {
            ret_val = nw_vmf_connect(tmp, 0, 0, VMF_CLIENT_QUEUE_SIZE_STANDARD, VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD);
            if (ret_val<=0)
            {
                nw_sleep_ms(WAIT_SOME_TIME);         /* wait for VMF */
            }
        }
    }
    cid = (vmf_client_id_t)ret_val;
    VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_mi_vmf_connect() connected to VMF cid=%d",cid);

    /* register message groups for this section */
    VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_register_msg_group() num-groups=%d",p_ass_section->local_group_num);
    ret_val = nw_vmf_register_msg_group (cid, p_ass_section->local_group_num, p_ass_section->local_groups);
    if (ret_val != VMF_OK)
    {
        (void) nw_vmf_disconnect(cid);
        VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_mi_vmf_connect() nw_vmf_register_msg_group failed");
        cid = (vmf_client_id_t)VMF_ERROR;
    }

#if 0
    /* debug output */
    {
        int i;
        for (i=0;i<p_ass_section->local_group_num;i++)
        {
            VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_mi_vmf_connect() registered to msg-group %d",p_ass_section->local_groups[i]);
        }
    }
#endif

    return cid;
}


/**************************************************************************//**
 *
 *   Function Name: nw_vmf_mi_vmf_disconnect(uint32_T ulContext)
 *   Description:   disconnect from vmf
 *
 *   \param         pointer to associated section
 *   \return        void *
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_mi_vmf_disconnect(vmf_client_id_t vmf_client_id)
{
    if (vmf_tx_cid == vmf_client_id)
    {
        vmf_tx_cid = 0;
    }
    return nw_vmf_disconnect(vmf_client_id);
}



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_mi_vmf_server_thread(uint32_T ulContext)
 *   Description:   vmf server thread for MI connectivity
 *                  this thread will receive vmf messages and will forward them via tcp
 *
 *   \param         pointer to associated section
 *   \return        void *
 *
 ******************************************************************************/
static void * nw_vmf_mi_vmf_server_thread(vmf_mi_section_t * p_ass_section)
{
    vmf_ret_t       ret_val=VMF_ERROR;
    vmf_client_id_t my_rx_id=0;
    SOCKET          txSocket=-1;
    unsigned8       my_section=0;
    char            Thread_name[100];
    bool            allow_backfiring = false;
	pthread_t 		th;

    nw_assert(p_ass_section != NULL);

    if (NULL == p_ass_section)
    {
        VMF_MI_ERROR("p_ass_section=NULL");
        return NULL;
    }

#if ((defined(__QNX__) && (_NTO_VERSION >= 632)) || defined(__LINUX__))
			th = pthread_self();	
			sprintf(Thread_name, "MI-VMF-Server-%d-%s", th, p_ass_section->section_name);
			nw_os_set_thread_name(th,Thread_name);
#endif
    
    /* Register at VMF Tracer */
    if (VMF_TRACE_REGISTER(&vmf_mi_trid, VMF_TRACE_MI) < 0)
    {
         VMF_MI_ERROR("CANNOT CONNECT TO VMF TRACER!!!");
    }

    my_section = p_ass_section->this_section;
    if (p_ass_section->allow_backfire > 0)
    {
        /* allow backfiring */
        allow_backfiring = true;
    }

    VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_mi_vmf_server_thread() created\n");

    while(true)
    {
        /* connect to the tcp-server */
        ret_val = vmf_mi_ipc_connect_tx_sock(p_ass_section,&txSocket);
        if (ret_val != VMF_OK)
        {
            VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_connect_tx_sock() failed");
        }

        /* connect to vmf server and register msg groups  */
        if (0 == my_rx_id)
        {
            ret_val = nw_vmf_mi_vmf_connect(p_ass_section);
            if (ret_val <= 0)
            {
                /* invalid cid */
                VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_mi_vmf_connect() failed");
            }
            else
            {
                my_rx_id = ret_val;
            }
        }
        /* receive VMF messages and forward them to TCP */
        while(ret_val >= 0)
        {
            nw_vmf_mi_transfer_t    transfer_buffer;
            unsigned16              transfer_msg_len;
            transfer_buffer.token0 = VALID_TOKEN0;
            transfer_buffer.token1 = VALID_TOKEN1;

            VMF_MI_DEBUG_DEBUG(vmf_mi_trid,p_ass_section->section_name,VMF_TRACE_SEVERITY_INFO_10,"waiting for vmf message");
            ret_val = (vmf_ret_t)nw_vmf_timed_receive(my_rx_id, (vmf_msg_t *)&(transfer_buffer.vmf_msg),sizeof(transfer_buffer.vmf_msg),VMF_MI_KEEP_ALIVE_TIME);
            if (ret_val > 0)
            {
                VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"got vmf message with %d bytes",ret_val);
                /* only forward message if no backfireing */
                if ((transfer_buffer.vmf_msg.vmf_basic_msg.msg_base.base.vmf_mi_server_id != my_section) || (true == allow_backfiring))
                {
                    transfer_buffer.vmf_len = ret_val;
                    transfer_msg_len = NW_VMF_MI_GET_TRANSFER_MSG_LEN(transfer_buffer.vmf_len);
                    VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name, "transfer %d bytes via tcp", ret_val);
                    VMF_MI_DEBUG_HEX(vmf_mi_trid, p_ass_section->section_name, transfer_msg_len, (unsigned8 *)&transfer_buffer);
                    ret_val = vmf_mi_ipc_tcp_send(p_ass_section, txSocket, &transfer_buffer, transfer_msg_len);
                    if (ret_val != VMF_OK)
                    {
                        /* tcp error */
                        VMF_MI_DEBUG_DEBUG(vmf_mi_trid, p_ass_section->section_name, VMF_TRACE_SEVERITY_INFO_10, "tcp send failed (ret_val = %d)!", ret_val);
                        /* break; */
                    }
                }
                else
                {
                    VMF_MI_DEBUG_DEBUG(vmf_mi_trid,p_ass_section->section_name,VMF_TRACE_SEVERITY_INFO_19,"prevent backfiring - stored section = %d, mysection = %d",transfer_buffer.vmf_msg.vmf_basic_msg.msg_base.base.vmf_mi_server_id,my_section);
                    VMF_MI_DEBUG_HEX(vmf_mi_trid,p_ass_section->section_name,transfer_buffer.vmf_len,(unsigned8 *)&transfer_buffer);
                }
            }
            else if (ret_val == 0)
            {
                /* timeout */
                /* send keep alive */
                VMF_MI_DEBUG_DEBUG(vmf_mi_trid, p_ass_section->section_name, VMF_TRACE_SEVERITY_INFO_10, "timeout --> send keep alive.");
                transfer_buffer.vmf_len = 0;
                transfer_msg_len = NW_VMF_MI_GET_TRANSFER_MSG_LEN(0);
                ret_val = vmf_mi_ipc_tcp_send(p_ass_section, txSocket, &transfer_buffer, transfer_msg_len);
                if (ret_val != VMF_OK)
                {
                    /* tcp error */
                    VMF_MI_DEBUG_DEBUG(vmf_mi_trid, p_ass_section->section_name, VMF_TRACE_SEVERITY_INFO_10, "send keep alive failed (ret_val = %d)!", ret_val);
                    /* break; */
                }
            }
            else
            {
                /* vmf error */
                VMF_MI_DEBUG_WARNING(vmf_mi_trid,p_ass_section->section_name,"nw_vmf_receive returned %d",ret_val);
                nw_sleep_ms(WAIT_SOME_TIME);
            }
        }

        /* close all used recources */
        nw_sleep_ms(WAIT_SOME_TIME);
        if (txSocket >= 0)
        {
            /* close socket */
            (void)closesocket(txSocket);
            txSocket = -1;
        }
#if 1
        if (my_rx_id > 0)
        {
            /* close vmf connection */
            (void)nw_vmf_mi_vmf_disconnect(my_rx_id);
            my_rx_id = 0;
        }
#endif
    }
}





/**************************************************************************//**
 *
 *   vmf multi instance extension main function
 *   this function will read the configuration ini file and will start the
 *   corsponding number of instances
 *
 *   \param[in]     arc
 *   \param[in]     arv
 *   \return        0 if ok
 *
 ******************************************************************************/
static int nw_vmf_mi_init(vmf_mi_section_t *vmf_mi_sections)
{
    FILE *      stream=NULL;
    unsigned16  cnt;
    int         num_sections=0;
    int         sec_num=0;

    nw_assert(vmf_mi_sections != NULL);

    /* open ini file and read number of sections */
    stream = ini_parser_open(VMF_MI_INI_FILE);
    if (stream != NULL)
    {
		num_sections = ini_parser_get_num_sections(stream);
	}
	else
	{
        VMF_MI_DEBUG_ERROR(vmf_mi_trid,VMF_TRACE_GL_SCOPE,"error reading %s",VMF_MI_INI_FILE);
        VMF_MI_ERROR("nw_vmf_mi_init() error opening %s",VMF_MI_INI_FILE);
	}
	
	if(num_sections > 0)
	{
		VMF_MI_INFO("nw_vmf_mi_init() number of sections=%d",num_sections);

		/* init all sections */
		nw_vmf_mi_init_sections(vmf_mi_sections,num_sections);

		/* read all sections into section table */
		for (cnt=0,sec_num=0;cnt<num_sections;cnt++)
		{
			char *p_section_name;
			char *rp_section_name;
			char val[255];

			rp_section_name = ini_parse_get_section_name(stream,cnt);
			if (NULL != rp_section_name)
			{
				int ret_val=0;

				/* get section name */
				vmf_mi_sections[sec_num].section_name[0]=0;
				nw_os_sstrncpy(vmf_mi_sections[sec_num].section_name, rp_section_name, sizeof(vmf_mi_sections[sec_num].section_name));
				p_section_name = vmf_mi_sections[sec_num].section_name;

				/* get device type */
				ret_val = ini_parser_get_val(stream,p_section_name,KEY_DEVICE_TYPE,val,sizeof(val));
				if (ret_val > 0)
				{
					nw_os_sstrncpy(vmf_mi_sections[sec_num].device_type, val, sizeof(vmf_mi_sections[sec_num].device_type));
					VMF_MI_INFO("section[%s] - device_type=%s",p_section_name,vmf_mi_sections[sec_num].device_type);
				}
				else
				{
					vmf_mi_sections[sec_num].device_type[0]=0;
					VMF_MI_INFO("section[%s] - no device_type set",vmf_mi_sections[sec_num].section_name);
				}
				/* get numeric device type */
				vmf_mi_sections[sec_num].num_dtype =  vmf_mi_get_num_dtype(vmf_mi_sections[sec_num].device_type);
				VMF_MI_INFO("section[%s] number=%d, num_dtype = %d",p_section_name,cnt, vmf_mi_sections[sec_num].num_dtype);

				/* get compression type */
				ret_val = ini_parser_get_val(stream,p_section_name,KEY_COMPRESSION,val,sizeof(val));
				if (ret_val > 0)
				{
					vmf_mi_sections[sec_num].comp_type = (unsigned8)atoi(val);
					VMF_MI_INFO("section[%s] - compression_type=%d",p_section_name,vmf_mi_sections[sec_num].comp_type);
				}
				else
				{
					vmf_mi_sections[sec_num].comp_type = MI_NO_COMP;
				}
				VMF_MI_INFO("section[%s] - compression_type=%d",p_section_name,vmf_mi_sections[sec_num].comp_type);

				/* get allow backfire */
				ret_val = ini_parser_get_val(stream,p_section_name,KEY_ALLOW_BACKFIRE,val,sizeof(val));
				if (ret_val > 0)
				{
					vmf_mi_sections[sec_num].allow_backfire = 1;
					VMF_MI_INFO("section[%s] - allow_backfire=%d",p_section_name,vmf_mi_sections[sec_num].allow_backfire);
				}
				else
				{
					vmf_mi_sections[sec_num].allow_backfire = 0;
				}
				VMF_MI_INFO("section[%s] - allow_backfire=%d",p_section_name,vmf_mi_sections[sec_num].allow_backfire);

				/* load values related to selected communication type */
				switch (vmf_mi_sections[sec_num].num_dtype)
				{
					case NDT_TCP:
					{
						ret_val = nw_vmf_mi_dtype_tcp_readinit(stream, vmf_mi_sections,sec_num,p_section_name);
					}
					break;

					case NDT_FIFO:
						/* no break */
					case NDT_CHAR:
						/* no break */
					case NDT_VMQ:
						/* no break */
					case NDT_BLK:
					{
						ret_val = nw_vmf_mi_dtype_file_readinit(stream, vmf_mi_sections,sec_num,p_section_name);
					}
					break;
				}

				/* ignorer section if there was an error */
				if (ret_val != 0)
				{
					/* section without ports */
					/* do not store this section inside the section table */
					VMF_MI_INFO("section[%s] not plausible - ignore ",p_section_name);
					continue;
				}

				/* get groups */
				ret_val = ini_parser_get_val(stream,p_section_name,KEY_LOCAL_GROUPS,val,sizeof(val));
				if (ret_val > 0)
				{
					vmf_mi_sections[sec_num].local_group_num = ini_parser_get_byte_list(val,vmf_mi_sections[sec_num].local_groups,MAX_GROUP_NUM);
					VMF_MI_INFO("section[%s] - number of local_groups=%d",p_section_name,vmf_mi_sections[sec_num].local_group_num);
					if (vmf_mi_sections[sec_num].local_group_num > 0)
					{
						/* output groups */
						int     i;
						char    my_tmp[MAX_GROUP_NUM*5];

						my_tmp[0] = 0;
						for (i =0;i<vmf_mi_sections[sec_num].local_group_num;i++)
						{
							char    tmp2[19];
							int     bytes_written;
							bytes_written = snprintf(tmp2,sizeof(tmp2),"0x%02x ",vmf_mi_sections[sec_num].local_groups[i]);
							strncat(my_tmp,tmp2,bytes_written);
						}
						// VMF_MI_INFO("section[%s] - local_groups=%s",p_section_name,my_tmp);
					}
				}

				ret_val = ini_parser_get_val(stream,p_section_name,KEY_REMOTE_IP,val,sizeof(val));
				if (ret_val > 0)
				{
					nw_os_sstrncpy(vmf_mi_sections[sec_num].remote_ip, val, sizeof(vmf_mi_sections[sec_num].remote_ip));
					VMF_MI_INFO("section[%s] - remote_ip='%s'",p_section_name,vmf_mi_sections[sec_num].remote_ip);
				}
				vmf_mi_sections[sec_num].this_section = sec_num + 1;      /* store a section number */
				vmf_mi_sections[sec_num].in_use=true;
				sec_num++;
			}
		}
	}

    ini_parser_close(stream);

    return sec_num;
}





/******************************************************************************
 *      local functions
 ******************************************************************************/


/**************************************************************************//**
 *
 *   init all sections with default values
 *
 *   \param[in]     list of sections
 *   \param[in]     number of sections
 *   \return        void
 *
 ******************************************************************************/
static void nw_vmf_mi_init_sections(vmf_mi_section_t *sections, unsigned16 section_num)
{
    int cnt=0;

    nw_assert(sections != NULL);
    nw_assert(section_num != 0);

    for (cnt=0; cnt<section_num; cnt++)
    {
        sections[cnt].in_use = false;
        sections[cnt].local_port =0;
        sections[cnt].remote_port =0;
        sections[cnt].local_group_num = 0;
        sections[cnt].remote_ip[0]=0;
        sections[cnt].comp_type=MI_NO_COMP;
        sections[cnt].allow_backfire = 0;
    }
}


/******************************************************************************
 *      ipc functions
 ******************************************************************************/


/*************************************************************************//**
 *
 *   create the server socket and bind it to given port \n
 *   NOTE:
 *
 *
 *   \param[in]  *section -- section of this connection instance
 *   \param[in] *SOCKET   -- pointer to the rpc rx socket
 *   \param[in] *port     -- tcp port to listen on
 *   \return    vmf_error_t
 *
 ******************************************************************************/
static vmf_error_t vmf_mi_ipc_create_and_bind_server_socket(vmf_mi_section_t * p_ass_section,int *p_rpc_srv_socket,unsigned16 port,unsigned16 ms_timeout)
{
    #define WAIT_4_SOCKET       500         /* time in ms/10 */
    #define WAIT_MORE_4_SOCKET  0xffff      /* time in ms/500 */

    vmf_error_t         vmf_ret=VMF_ERROR;
    SOCKADDR_IN         addr = {0};               /* sockaddr */
    unsigned16          cnt;

    UNUSED_PARAM(ms_timeout);

    nw_assert(p_ass_section != NULL);
    nw_assert(p_rpc_srv_socket != NULL);

    /* wait some time to connect the socket if nw stack ist not running */
    for (cnt=0;cnt<WAIT_MORE_4_SOCKET;cnt++)
    {
        *p_rpc_srv_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (*p_rpc_srv_socket == INVALID_SOCKET)
        {
            if (cnt < WAIT_4_SOCKET)
            {
                nw_sleep_ms(10);
            }
            else
            {
                nw_sleep_ms(500);
            }
        }
        else
        {
            break;
        }
    }

    if (*p_rpc_srv_socket == INVALID_SOCKET)
    {
        VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_create_and_bind_server_socket() - Error at socket(): %d",WSAGetLastError());
    }
	else
    /* try to set REUSEADDR option to prevent bind error if port was used a short time ago */
    {
        int on=1;
        (void)setsockopt(*p_rpc_srv_socket, SOL_SOCKET,SO_REUSEADDR,(char *)&on,sizeof(on));
		
		// AF_INET is the Internet address family.
		addr.sin_family = AF_INET;

		// set local host
		addr.sin_addr.s_addr = htonl(INADDR_ANY);

		//bind to port number
		addr.sin_port = htons(port);

		/* bind the socket */
		if (bind(*p_rpc_srv_socket, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR)
		{
			VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_create_and_bind_server_socket() - bind() failed: %d", WSAGetLastError());
			vmf_ret = VMF_ERR_REM_SERVER_BIND_ERROR;
			(void) closesocket(*p_rpc_srv_socket);
		}
		else
		{
			vmf_ret = VMF_OK;
			VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_create_and_bind_server_socket() bindig port %d",port);	
		}
    }

    return vmf_ret;
}

#ifdef VMF_MI_SET_SOCK_TIMEOUT
/*************************************************************************//**
 *
 *   set a timeout on a socket \n
 *   NOTE:
 *
 *
 *   \param[in]  *section   -- section of this connection instance
 *   \param[in]  SOCKET     -- the socket
 *   \param[in]  timeout    -- timeout in ms
 *   \return     vmf_error_t
 *
 ******************************************************************************/
static vmf_error_t vmf_mi_ipc_set_socket_timeout(vmf_mi_section_t *p_ass_section,int mi_socket,unsigned16 ms_timeout)
{
    vmf_error_t     ret_val = VMF_ERROR;
    struct timeval  vmf_sock_timeout;

    nw_assert(p_ass_section != NULL);

    if (ms_timeout > 0)
    {
        vmf_sock_timeout.tv_sec  = (ms_timeout/1000);
        vmf_sock_timeout.tv_usec = (ms_timeout - vmf_sock_timeout.tv_sec*1000) * 1000;
        VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"socket %d timeout = ms_timeout=%d -- tv_sec=%d, tv_usec=%d\n", mi_socket,ms_timeout,(int)vmf_sock_timeout.tv_sec, (int)vmf_sock_timeout.tv_usec);

        if (setsockopt(mi_socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&vmf_sock_timeout,  sizeof(vmf_sock_timeout)))
        {
            VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"cannot set socket receive timeout on socket %d! ms_timeout=%d -- tv_sec=%d, tv_usec=%d\n", mi_socket, ms_timeout,(int)vmf_sock_timeout.tv_sec, (int)vmf_sock_timeout.tv_usec);
        }
        else
        {
            ret_val = VMF_OK;
        }
    }
    else
    {
        /* zero timeout means blocking */
        ret_val = VMF_OK;
    }
    return ret_val;
}
#endif

/*************************************************************************//**
 *
 *   accept tcp connection \n
 *   NOTE:
 *
 *
 *   \param[in] pointer to connected socket
 *   \param[in] listening socket
 *   \return    vmf_error_t
 *
 ******************************************************************************/
static vmf_error_t vmf_mi_ipc_con_accept_sock(vmf_mi_section_t * p_ass_section,SOCKET *p_connectedSocket,SOCKET p_bindSocket)
{
#ifndef NO_SOCKETS
    vmf_error_t vmf_ret=VMF_OK;

    /* wait to accept a connection - this function is blocking */
    *p_connectedSocket = accept(p_bindSocket,NULL,NULL);
    if(INVALID_SOCKET == *p_connectedSocket)
    {
        VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_con_accept_sock() - error: accept, error code: %d",WSAGetLastError());
        vmf_ret = VMF_ERROR;
    }
#endif
    return vmf_ret;
}


/*************************************************************************//**
 *
 *   listen on client port and forward messaged to VMF \n
 *   NOTE: reception is done in two steps - first the length is received then the data
 *
 *
 *   \param[in]     connecte socket
 *   \param[in\out] pointer of message buffer
 *   \param[in]     length of message buffer
 *   \return        size of message or 0
 *
 ******************************************************************************/
static unsigned16  vmf_mi_ipc_tcp_receive(vmf_mi_section_t * p_ass_section,SOCKET connectedSocket,nw_vmf_mi_transfer_t *p_transfer_msg)
{
    int num_bytes =0;
#ifndef NO_SOCKETS
    nw_assert(p_transfer_msg != NULL);
    nw_assert(p_ass_section != NULL);

    if (NULL == p_ass_section)
    {
        VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_tcp_receive() p_ass_section = NULL");
    }
	else
	{
		/* receive message */
		while(true)
		{
			size_t wanted_len=0;

			/* sync */
			VMF_MI_INFO("vmf_mi_ipc_tcp_receive() wait for sync");
			while(true)
			{
				/* sync token 0 */
				num_bytes = vmf_mi_recv_wait(connectedSocket, (char *)&(p_transfer_msg->token0), 1, 0);
				if (num_bytes < 1)
				{
					nw_sleep_ms(1);
					break;
				}
				if (VALID_TOKEN0 != p_transfer_msg->token0)
				{
					continue;
				}

				/* sync token 1 */
				num_bytes = vmf_mi_recv_wait(connectedSocket, (char *)&(p_transfer_msg->token1), 1, 0);
				if (num_bytes < 1)
				{
					nw_sleep_ms(1);
					break;
				}
				if (VALID_TOKEN1 != p_transfer_msg->token1)
				{
					continue;
				}
				else
				{
					break;
				}
			}
			VMF_MI_INFO("vmf_mi_ipc_tcp_receive() syncted");

			/* receive the length */
			wanted_len = sizeof(p_transfer_msg->vmf_len);   /* length of vmf-len */
			VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_tcp_receive() waiting for msg-len on socket %d",connectedSocket);
			VMF_MI_INFO("vmf_mi_ipc_tcp_receive received len=%d",wanted_len);

			num_bytes = vmf_mi_recv_wait(connectedSocket, (char *)&(p_transfer_msg->vmf_len), wanted_len, 0);
			if (wanted_len == num_bytes)
			{
				if (p_transfer_msg->vmf_len > 0)
				{
					/* received vmf-msg length */
					/* reveive remaining data = vmf_msg */
					VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_tcp_receive() waiting for %d bytes on socket %d",p_transfer_msg->vmf_len,connectedSocket);
					VMF_MI_INFO("vmf_mi_ipc_tcp_receive() waiting for %d bytes on socket %d",p_transfer_msg->vmf_len,connectedSocket);
					num_bytes = vmf_mi_recv_wait(connectedSocket, (char *)&(p_transfer_msg->vmf_msg), p_transfer_msg->vmf_len, 0);
					if (num_bytes != p_transfer_msg->vmf_len)
					{
						VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_tcp_receive() got invalid msg legth=%d wanted length=%d",num_bytes,p_transfer_msg->vmf_len);
						num_bytes = 0;
					}
					else
					{
						/* got message - so leave the loop */
						VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_tcp_receive() got msg with legth=%d",num_bytes);
						VMF_MI_DEBUG_HEX(vmf_mi_trid,p_ass_section->section_name,num_bytes,(unsigned8 *)&(p_transfer_msg->vmf_msg));
						break;
					}
				}
				else
				{
					VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_tcp_receive() got keep alive msg");
					VMF_MI_INFO("vmf_mi_ipc_tcp_receive() got keep alive msg");
					/* keep alive message */
					/* ignore */
				}
			}
			else if (num_bytes > 0)
			{
				VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_tcp_receive() got invalid msglegth=%d",num_bytes);
			}
			else
			{
				/* rx error - so leave the loop */
				VMF_MI_DEBUG_WARNING(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_tcp_receive() got zero msglength - timout? ret=%d, errno=%d",num_bytes,errno);
				break;
			}
		}
	}
#endif
    return num_bytes;
}


/*************************************************************************//**
 *
 *   send a buffer via tcp \n
 *   NOTE:
 *
 *   \param[in]     socket
 *   \param[in]     buffer address
 *   \param[in]     length of buffer
 *   \return        number of transfered bytes;
 *
 ******************************************************************************/
static vmf_ret_t vmf_mi_ipc_tcp_send(vmf_mi_section_t * p_ass_section,SOCKET txSocket,nw_vmf_mi_transfer_t *p_transfer_msg,unsigned16 transfer_msg_len)
{
    vmf_ret_t               vmf_ret = VMF_OK;
#ifndef NO_SOCKETS

    if (NULL == p_transfer_msg)
    {
        VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_tcp_send() p_transfer_msg = NULL");
        vmf_ret = VMF_ERR_NULL_POINTER;
    }
    else
    {
        int i_ret=0;

        VMF_MI_INFO("vmf_mi_ipc_tcp_send() send %d bytes",(int)transfer_msg_len);
        i_ret = send(txSocket,(const void *)p_transfer_msg,transfer_msg_len,0);
        if (i_ret == transfer_msg_len)
        {
            vmf_ret = VMF_OK;
        }
        else
        {
            vmf_ret = VMF_ERROR;
            VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_tcp_send() send() failed ret_val =%d, wanted len=%d",i_ret,(int)transfer_msg_len);
        }
    }
#endif
    return vmf_ret;
}


/*************************************************************************//**
 *
 *   send a keep alive message via tcp \n
 *   NOTE: a keep alive message has just 2 byte size and no data patt
 *
 *
 *   \param[in]     socket
 *   \return        number of transfered bytes;
 *
 ******************************************************************************/
#if 0
static vmf_ret_t  vmf_mi_ipc_tcp_send_keep_alive(vmf_mi_section_t * p_ass_section,SOCKET txSocket)
{
    unsigned8   buffer[NW_VMF_MI_GET_TRANSFER_MSG_LEN(0)+1] = {0};
    vmf_ret_t   ret_val;

    VMF_MI_DEBUG_DEBUG(vmf_mi_trid,p_ass_section->section_name,VMF_TRACE_SEVERITY_INFO_19,"vmf_mi_ipc_tcp_send_keep_alive()");

    ret_val = vmf_mi_ipc_tcp_send(p_ass_section,txSocket,(unsigned8 *)buffer,0);
    if (ret_val < 0)
    {
        VMF_MI_DEBUG_WARNING(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_tcp_send_keep_alive() vmf_mi_ipc_tcp_send() error");
    }
    return ret_val;
}
#endif



/*************************************************************************//**
 *
 *   connect to a tcp server\n
 *   NOTE:
 *
 *
 *   \param[out]    pointer to socket
 *   \param[in]     section with ip address of server
 *   \return        number of transfered bytes;
 *
 ******************************************************************************/
static vmf_error_t  vmf_mi_ipc_connect_tx_sock(vmf_mi_section_t *p_ass_section,SOCKET *p_txSocket)
{
    vmf_error_t vmf_ret = VMF_ERROR;
#ifndef NO_SOCKETS
    struct      hostent *hent = NULL;
    struct      sockaddr_in server = {0};
    int         ret_val=0;

    nw_assert(p_txSocket != NULL);
    nw_assert(p_ass_section != NULL);

    VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_connect_tx_sock() to %s",p_ass_section->remote_ip);


#ifdef INTEGRITY

    /* jmerkle 2017-03-22 -- According to Integrity Networking spec. the socket becomes invalid if connect() fails.  */

    ret_val = -1;
    while (ret_val != 0)
    {
        *p_txSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (*p_txSocket < 0)
        {
            /* error creating socket */
            VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_connect_tx_sock() socket()failed ");
            vmf_ret = VMF_ERROR;
        }
        else
        {
            hent = gethostbyname(p_ass_section->remote_ip);
            if (NULL == hent)
            {
                hent = gethostbyaddr(p_ass_section->remote_ip,4,AF_INET);
            }

            if (NULL == hent)
            {
                /* can not get host address */
                VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_connect_tx_sock() gethostbyname(%s) and gethostbyaddr() failed ",p_ass_section->remote_ip);
                vmf_ret = VMF_ERROR;
            }
            else
            {
                server.sin_family = AF_INET;
                server.sin_addr = *((struct in_addr *)hent->h_addr);
                server.sin_port = htons(p_ass_section->remote_port);
                memset(&(server.sin_zero), '\0', 8);
                vmf_ret = VMF_OK;
            }
        }

        /* wait for the coresponding tcp server */
        if (VMF_OK == vmf_ret)
        {
            ret_val = connect(*p_txSocket, (struct sockaddr*)&server, sizeof(server));
            if (ret_val != 0)
            {
                VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_connect_tx_sock() connect() ret_val=%d, errno=%d ", ret_val, errno);
                closesocket(*p_txSocket);
                nw_sleep_ms(WAIT_SOME_TIME);
            }
        }
    }

    VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_connect_tx_sock() connection established ");

#else

    *p_txSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (*p_txSocket < 0)
    {
        /* error creating socket */
        VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_connect_tx_sock() socket()failed ");
        vmf_ret = VMF_ERROR;
    }
    else
    {
        hent = gethostbyname(p_ass_section->remote_ip);
        if (NULL == hent)
        {
            hent = gethostbyaddr(p_ass_section->remote_ip,4,AF_INET);
        }

        if (NULL == hent)
        {
            /* can not get host address */
            VMF_MI_DEBUG_ERROR(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_connect_tx_sock() gethostbyname(%s) and gethostbyaddr() failed ",p_ass_section->remote_ip);
            vmf_ret = VMF_ERROR;
        }
        else
        {
            server.sin_family = AF_INET;
            server.sin_addr = *((struct in_addr *)hent->h_addr);
            server.sin_port = htons(p_ass_section->remote_port);
            memset(&(server.sin_zero), '\0', 8);
            vmf_ret = VMF_OK;
        }
    }

    /* wait for the coresponding tcp server */
    if (VMF_OK == vmf_ret)
    {
        ret_val = -1;
        while (ret_val != 0)
        {
            ret_val = connect(*p_txSocket, (struct sockaddr*)&server, sizeof(server));
            if (ret_val != 0)
            {
                VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_connect_tx_sock() connect() ret_val=%d, errno=%d ", ret_val, errno);
                nw_sleep_ms(WAIT_SOME_TIME);
            }
            /* Retry only if the connection is refused */
            if(ECONNREFUSED != errno)
            {
                break;
            }
        }
        VMF_MI_DEBUG_INFO(vmf_mi_trid,p_ass_section->section_name,"vmf_mi_ipc_connect_tx_sock() connection established ");
    }

#endif

#endif
    return vmf_ret;
}


/*************************************************************************//**
 *
 *   send a message to vmf\n
 *   NOTE: the section information is set inside the vmf-message struct
 *
 *
 *   \param[in]     cid
 *   \param[in]     pointe to vmf message
 *   \param[in]     length of vmf message
 *   \return        vmf_t
 *
 ******************************************************************************/
vmf_ret_t vmf_mi_vmf_sender (vmf_client_id_t vmf_client_id,  /**<INPUT connection_id*/
                             vmf_msg_t * p_vmf_msg,          /**<INPUT pointer to a vmf_message*/
                             unsigned16 len,                 /**<INPUT vmf msg len  */
                             unsigned8 section_num)          /**<INPUT section number */
{
    vmf_ret_t vmf_ret;

    nw_assert(p_vmf_msg != NULL);
    nw_assert(vmf_client_id > 0);
    nw_assert(section_num > 0);

    if (NULL == p_vmf_msg)
    {
        VMF_MI_ERROR("vmf_mi_vmf_sender() - argument error: NULL pointer\n");
        vmf_ret = (VMF_ERR_NULL_POINTER);
    }
    else if (vmf_client_id == 0)
    {
        VMF_MI_ERROR("vmf_mi_vmf_sender() - argument error: invalid client id\n");
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else if (section_num == 0)
    {
        VMF_MI_ERROR("vmf_mi_vmf_sender() - argument error: invalid section number \n");
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
    else if (len < sizeof(vmf_base_t))
    {
        VMF_MI_ERROR("vmf_mi_vmf_sender() - argument error: message to small = %d bytes\n",len);
        vmf_ret = (VMF_ERR_OUT_OF_RANGE);
    }
	else
	{
		/* prepare vmf-message header */
		p_vmf_msg->vmf_basic_msg.msg_base.base.co_msg_type = STD_VMF_MSG;
		p_vmf_msg->vmf_basic_msg.msg_base.base.vmf_mi_server_id = section_num;
		p_vmf_msg->vmf_basic_msg.msg_base.base.msg_clk = nw_os_cfg_get_ms_time();

		vmf_ret = nw_vmf_send_raw (vmf_client_id,(void *)p_vmf_msg,len);
	}

    return vmf_ret;
}

/*  helper functions */


/*************************************************************************//**
 *
 *   get the numeric device type from the device-name\n
 *   if the device name is invalid or unknown then the type is TCP
 *
 *   \param[in]     device name as char string
 *   \return        numeric device type
 *
 ******************************************************************************/
static vmf_mi_num_dtype vmf_mi_get_num_dtype(char *device_name)
{
    vmf_mi_num_dtype    dtype=NDT_DEFAULT;          /* tcp = default device type */

    /* argument check */
	if ((NULL != device_name) && (0 != strlen(device_name)))
	{
		/* ignore case of device-type */
		if ( 0 == nw_strncasecmp(VMF_MI_DTYPE_TCP,device_name,strlen(VMF_MI_DTYPE_TCP)))
		{
			dtype=NDT_TCP;
		}
		else if ( 0 == nw_strncasecmp(VMF_MI_DTYPE_VMQ,device_name,strlen(VMF_MI_DTYPE_VMQ)))
		{
			dtype=NDT_VMQ;
		}
		else if ( 0 == nw_strncasecmp(VMF_MI_DTYPE_BLK,device_name,strlen(VMF_MI_DTYPE_BLK)))
		{
			dtype=NDT_BLK;
		}
		else if ( 0 == nw_strncasecmp(VMF_MI_DTYPE_CHAR,device_name,strlen(VMF_MI_DTYPE_CHAR)))
		{
			dtype=NDT_CHAR;
		}
		else if ( 0 == nw_strncasecmp(VMF_MI_DTYPE_FIFO,device_name,strlen(VMF_MI_DTYPE_FIFO)))
		{
			dtype=NDT_FIFO;
		}
		else
		{
			dtype = NDT_DEFAULT;
		}
	}

    return dtype;
}


/**************************************************************************//**
 *
 *   Function Name: nw_mi_compress()
 *
 *   Description:   compress data
 *
 *   \param         compression type[input]
 *   \param         input buffer[input]
 *   \param         length of input data[input]
 *   \param         output buffer[output]
 *   \param         size of output buffer[input]
 *
 *   \return        length of comressed data or 0
 *
 ******************************************************************************/
unsigned16    nw_mi_compress(unsigned8 comp, unsigned8 *psrc, unsigned16 src_len, unsigned8 *pdest, unsigned16 dest_buff_len)
{
    unsigned16 dest_len=0;

    /* arguement check */
    if (NULL == psrc)
    {
        VMF_MI_ERROR("nw_mi_compress() - psrc = NULL");
    }
    else if (NULL == pdest)
    {
        VMF_MI_ERROR("nw_mi_compress() - pdest = NULL");
    }
    else if (0 == src_len)
    {
        VMF_MI_ERROR("nw_mi_compress() - src_len = 0");
    }
    else if (0 == dest_buff_len)
    {
        VMF_MI_ERROR("nw_mi_compress() - pdest_buff_len = 0");
    }
	else
	{
		switch(comp)
		{
			case MI_LZWR3:
				dest_len =  vmf_mi_comp_lzrw3(psrc, src_len, pdest, dest_buff_len);
			break;

			default:
				dest_len = 0;
			break;
		}
	}

    return dest_len;
}


/**************************************************************************//**
 *
 *   Function Name: nw_mi_decompress()
 *
 *   Description:   decompress data
 *
 *   \param         compression type[input]
 *   \param         input buffer[input]
 *   \param         length of input data[input]
 *   \param         output buffer[output]
 *   \param         size of output buffer[input]
 *
 *   \return        length of comressed data or 0
 *
 ******************************************************************************/
unsigned16    nw_mi_decompress(unsigned8 comp, unsigned8 *psrc, unsigned16 src_len, unsigned8 *pdest, unsigned16 dest_buff_len)
{
    unsigned16 dest_len=0;

    /* arguement check */
    if (NULL == psrc)
    {
        VMF_MI_ERROR("nw_mi_decompress() - psrc = NULL");
    }
    else if (NULL == pdest)
    {
        VMF_MI_ERROR("nw_mi_decompress() - pdest = NULL");
    }
    else if (0 == src_len)
    {
        VMF_MI_ERROR("nw_mi_decompress() - src_len = 0");
    }
    else if (dest_buff_len < src_len)
    {
        VMF_MI_ERROR("nw_mi_decompress() - dest_buff_len < src_len");
    }
	else
	{
		switch(comp)
		{
			case MI_LZWR3:
				dest_len =  vmf_mi_decomp_lzrw3(psrc, src_len, pdest, dest_buff_len);
			break;

			default:
				dest_len = 0;
			break;
		}
	}

    return dest_len;
}


/**************************************************************************//**
 *
 *   Function Name: decomp_lzrw3()
 *
 *   Description:   decompress lzrw3 compressed data
 *
 *   \param         input buffer[input]
 *   \param         length of input data[input]
 *   \param         output buffer[output]
 *   \param         size of output buffer[input]
 *
 *   \return        length of comressed data or 0
 *
 ******************************************************************************/
unsigned16 vmf_mi_decomp_lzrw3(unsigned8 *psrc, unsigned16 src_len, unsigned8 *pdest, unsigned16 dest_buff_len)
{
    unsigned32 l_st_buff_len=dest_buff_len;
#ifdef _LZRW3_H
    if (NULL == p_unpack)
    {
        struct compress_identity *p_identity;
        lzrw3_compress(COMPRESS_ACTION_IDENTITY,NULL,NULL,0,NULL,&p_identity);
        p_unpack = nw_os_malloc(p_identity->memory);
    }
    
	if (NULL == p_unpack)
    {
		l_st_buff_len = 0;
	}
	else
	{
		lzrw3_compress(COMPRESS_ACTION_DECOMPRESS,p_unpack,psrc, src_len,pdest,&l_st_buff_len);	
	}
#else
    UNUSED_PARAM(psrc);
    UNUSED_PARAM(src_len);
    UNUSED_PARAM(pdest);
#endif
    return l_st_buff_len;
}

/**************************************************************************//**
 *
 *   Function Name: comp_lzrw3()
 *
 *   Description:   compress data with lzrw3
 *
 *   \param         input buffer[input]
 *   \param         length of input data[input]
 *   \param         output buffer[output]
 *   \param         size of output buffer[input]
 *
 *   \return        length of comressed data or 0
 *
 ******************************************************************************/
unsigned16 vmf_mi_comp_lzrw3(unsigned8 *psrc, unsigned16 src_len, unsigned8 *pdest, unsigned16 dest_buff_len)
{
    unsigned32 l_st_buff_len=dest_buff_len;
#ifdef _LZRW3_H
    if (NULL == p_pack)
    {
        struct compress_identity *p_identity;

        lzrw3_compress(COMPRESS_ACTION_IDENTITY,NULL,NULL,0,NULL,&p_identity);
        p_pack = nw_os_malloc(p_identity->memory);
    }

	if (NULL == p_pack)
    {
		l_st_buff_len = 0;
	}
	else
	{
		lzrw3_compress(COMPRESS_ACTION_COMPRESS,p_pack,psrc, src_len,pdest,&l_st_buff_len);
	}
#else
    UNUSED_PARAM(psrc);
    UNUSED_PARAM(src_len);
    UNUSED_PARAM(pdest);
#endif
    return l_st_buff_len;
}


#undef VMF_MI_C




