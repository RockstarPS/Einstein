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
*  PROJECT NAME :          VMF_TRACE_SERVER                                   *
*******************************************************************************
*  MODULE NAME  :          nw_vmf_target_log.c                                *
*  AUTHOR NAME  :          Joerg Merkle -- jmerkle                            *
*******************************************************************************
*  MODULE DATE  :          February 2015                                      *
*******************************************************************************
*  MODULE DESCRIPTION  :   VMF_TRACE                                          *
*******************************************************************************
* Compiler/Assembler:      gcc                                                *
* Target Hardware:         Any                                                *
******************************************************************************/

#define _VMF_TARGET_LOG_C_

#include "nw_os_config.h"
#include "nw_vmf.h"
#include "nw_vmf_cfg.h"
#include "nw_vmf_trace_server.h"
#include "nw_vmf_trace.h"
#include "nw_vmf_ipc.h"
#include "nw_vmf_sysinfo.h"
#include "nw_vmf_debug.h"
#include "nw_vmf_target_log.h"



/**************************************************************************//**
 *
 *   Function Name: vmf_trace_target_log_init_trace()
 *
 *   Description:   initialize the target logging for VMF Trace (!) depending 
 *                  on the OS mechanism used.
 *
 *   Parameters:    void
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
vmf_ret_t vmf_target_log_init_trace(void)
{
    NW_COMPILER_MESSAGE("VMF_TARGET_LOGGING enabled!")
    
    nw_os_target_log_init("vmf_trace_server");
    
    return VMF_OK;
}


/**************************************************************************//**
 *
 *   Function Name: vmf_target_log_write_trace()
 *
 *   Description:   write to "local" log.
 *
 *   Parameters:    payload -- VMF message payload of VMF_TRACE_IN msg group.
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
vmf_ret_t vmf_target_log_write_trace(unsigned8 *payload)
{
    vmf_ret_t           vmf_ret = VMF_OK;
    vmf_trace_pl_t*     my_trace_content = (vmf_trace_pl_t*) payload;
    char                my_buffer[MAX_VMF_TRACE_PL_LEN];
    char                my_out_string[MAX_VMF_TRACE_PL_LEN + 20];
    unsigned16          i;

    if (NULL == payload)
    {
        return VMF_ERR_NULL_POINTER;
    }

    memset(my_buffer, 0, sizeof(my_buffer));
    nw_os_smemcpy(my_buffer, MAX_VMF_TRACE_PL_LEN, my_trace_content->tpl, my_trace_content->tpl_len);
    for (i=0; i<my_trace_content->tpl_len; i++)
    {
        if (VMF_TRACE_MSG_DELIMITER_C == my_buffer[i])
        {
            my_buffer[i] = '|';
        }
        else if (my_buffer[i] < 0x20)
        {
            my_buffer[i] = 0x20;
        }
    }

    snprintf(my_out_string, sizeof(my_out_string), "VMF Trace (%3d): %d|%s", my_trace_content->severity, my_trace_content->msg_time, my_buffer);

    if (false == nw_os_target_log(my_trace_content->severity, my_out_string))
    {
        vmf_ret = VMF_ERROR;
    }

    return vmf_ret;
}


#undef _VMF_TARGET_LOG_C_
