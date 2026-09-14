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

  Module:               nw_vmf_mi_file_types.c
  Description:          multi instance VMF extension 
                        implementation of ipc via tcp
                        supported device-types in .ini file = 
                        device_type=TCP                 ; TCP/IP
                        
  Project Scope:        multi platform

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Joachim Becker

  Compiler/Assembler:   gcc
  Target Hardware:      Any

  *****************************************************************************/
#define VMF_MI_TCP_C

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

  
  
extern unsigned8 vmf_mi_trid;  
  
  
 /**************************************************************************//**
 *
 *   get TCP related values from ini file
 *
 *   \param[in]     arc      
 *   \param[in]     arv      
 *   \return        0 if ok else -1
 *
 ******************************************************************************/
int nw_vmf_mi_dtype_tcp_readinit(FILE * stream, vmf_mi_section_t *vmf_mi_sections,int section_num,char *p_section_name)
{
    int ret_val=-1;
    int val_len = 0;
    char val[255];
    
    /* argument check */
    if (NULL==stream)
    {
        VMF_MI_DEBUG_ERROR(vmf_mi_trid, VMF_TRACE_MI_SCOPE, "nw_vmf_mi_dtype_tcp_readinit(): stream=NULL");
    }
    else if (NULL ==vmf_mi_sections)
    {
        VMF_MI_DEBUG_ERROR(vmf_mi_trid, VMF_TRACE_MI_SCOPE, "nw_vmf_mi_dtype_tcp_readinit(): vmf_mi_sections=NULL");
    }
    else if (NULL==p_section_name)
    {
        VMF_MI_DEBUG_ERROR(vmf_mi_trid, VMF_TRACE_MI_SCOPE, "nw_vmf_mi_dtype_tcp_readinit(): p_section_name=NULL");
    }
    else
    {
        /* get local port */
        val_len = ini_parser_get_val(stream,p_section_name,KEY_LOCAL_PORT,val,sizeof(val));
        if (val_len > 0)
        {
            vmf_mi_sections[section_num].local_port=atoi(val);   
            VMF_MI_DEBUG_INFO(vmf_mi_trid, VMF_TRACE_MI_SCOPE, "section[%s] - local_port=%d",p_section_name,vmf_mi_sections[section_num].local_port);
        }
        else
        {
            vmf_mi_sections[section_num].local_port=0;
        }
                
        /* get remote port */
        val_len = ini_parser_get_val(stream,p_section_name,KEY_REMOTE_PORT,val,sizeof(val));
        if (val_len > 0)
        {
            vmf_mi_sections[section_num].remote_port=atoi(val);
            VMF_MI_DEBUG_INFO(vmf_mi_trid, VMF_TRACE_MI_SCOPE, "section[%s] - remote_port=%d",p_section_name,vmf_mi_sections[section_num].remote_port);
        }

        val_len = ini_parser_get_val(stream,p_section_name,KEY_REMOTE_IP,val,sizeof(val));
        if (val_len > 0)
        {
            nw_os_sstrncpy(vmf_mi_sections[section_num].remote_ip, val, sizeof(vmf_mi_sections[section_num].remote_ip));
            VMF_MI_DEBUG_INFO(vmf_mi_trid, VMF_TRACE_MI_SCOPE, "section[%s] - remote_ip='%s'",p_section_name,vmf_mi_sections[section_num].remote_ip);
        }
        else
        {
            vmf_mi_sections[section_num].remote_ip[0]=0;
        }

        
        /* test plausibility */
        /* check if source or dest port was defined in ini file */
        ret_val = 0;
        if ((vmf_mi_sections[section_num].remote_port == 0) && (vmf_mi_sections[section_num].local_port == 0))
        {
            /* section without ports */
            /* do not store this section inside the section table */
            VMF_MI_DEBUG_ERROR(vmf_mi_trid, VMF_TRACE_MI_SCOPE, "TCP section[%s] without port - ignore ",p_section_name);
            ret_val = -1;
        }
        /* there has to be a remote-ip addr if remote port was set */
        else if ((vmf_mi_sections[section_num].remote_port != 0))
        {
            if (0 == vmf_mi_sections[section_num].remote_ip[0])
            {
                VMF_MI_DEBUG_ERROR(vmf_mi_trid, VMF_TRACE_MI_SCOPE, "TCP section[%s] remote IP-Addr missing ",p_section_name);
                ret_val = -1;
            }
        }
        else
        {
            VMF_MI_DEBUG_INFO(vmf_mi_trid, VMF_TRACE_MI_SCOPE, "section[%s] is plausible ",p_section_name);
        }
    }
                
    return ret_val;
}



/**************************************************************************//**
 *
 *   Function Name: nw_vmf_mi_start_instances(vmf_mi_section_t *vmf_mi_sections)
 *
 *   Description:   start all nedded vmf mi instances
 *
 *   \param         pointer to all sections, section number
 *   \return        void
 *
 ******************************************************************************/
vmf_ret_t nw_vmf_mi_start_tcp_instance(vmf_mi_section_t *vmf_mi_sections,int section_num)
{
    vmf_ret_t vmf_ret=VMF_ERROR;
    
    if (vmf_mi_sections[section_num].local_port != 0)
    {
        /* start a tcp listener on this port */
        VMF_MI_DEBUG_INFO(vmf_mi_trid,VMF_TRACE_MI_SCOPE,"create tcp-server thread %s",vmf_mi_sections[section_num].section_name);
        vmf_ret=nw_vmf_mi_create_tcp_server_thread(&vmf_mi_sections[section_num]);
    }

    if (vmf_mi_sections[section_num].remote_port != 0)
    {
        /* start a vmf server thread for this section  */
        VMF_MI_DEBUG_INFO(vmf_mi_trid,VMF_TRACE_MI_SCOPE,"create vmf-server thread %s",vmf_mi_sections[section_num].section_name);
        vmf_ret=nw_vmf_mi_create_vmf_server_thread(&vmf_mi_sections[section_num]);
    }

    return vmf_ret;
}



/*************************************************************************//**
 *
 *   receives data on a socket till all data is received  \n
 *   NOTE: done because MSG_WAITALL is not supported on Windows
 *   
 *
 *   \param[in] SOCKET   -- socket
 *   \param[in] buf      -- buffer for rx data
 *   \param[in] len      -- buffer len
 *   \param[in] flags    -- rx flags
 *   \return    number of bytes or 0 or -1 
 *
 ******************************************************************************/
int vmf_mi_recv_wait(SOCKET s,char  * buf,int len,int flags)
{
    int num_bytes;
    unsigned16  all_bytes=0;

    UNUSED_PARAM(flags);

    while (all_bytes < len)
    {
        /* receive rpc_id */
        num_bytes = recv(s, &(buf[all_bytes]), len-all_bytes, 0);
        if (num_bytes > 0)
        {
            all_bytes+=num_bytes;           
        }
        else if (num_bytes < 0)
        {
            if (errno != EAGAIN)
            {
                all_bytes = num_bytes;
                break;
            }
        }
        else
        {
            /* num_bytes = 0, socket closed */
            all_bytes = num_bytes;
            break;
        }
    }
#if 0
NW_REM_VMF_DEBUG_INFO("rem_vmf: recv_wait - receive %d bytes",all_bytes);
#endif
    return all_bytes;
}

