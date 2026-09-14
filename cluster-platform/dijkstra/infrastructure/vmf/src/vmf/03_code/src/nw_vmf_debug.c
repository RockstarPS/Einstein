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

/*************************************************************************//**

  \file                 nw_vmf_debug.c
  \brief                vmf debug utilities

  \author               Joerg Merkle
  \author               Visteon Deutschland GmbH, Infotainment Software

  \compiler             gcc
  \target               any

  *****************************************************************************/
#define __NW_VMF_DEBUG_C__

/* system includes */
#include "os_types.h"
#include "nw_os_config.h"
#include "nw_vmf_cfg.h"

/* application includes */
#include "nw_vmf_types.h"
#include "nw_vmf_debug.h"


/* simple counter to see if all message coming through... */
unsigned16  syslog_count = 0;


/* function prototypes */
void nw_vmf_debug_register_most_shadow(vmf_ctrl_msg_register_most_shadow_t *reg_msg);

/*****************************************************************************
 *
 *   Function Name: nw_vmf_debug_msgs()
 *
 *   Description:   decode and print a VMF message
 *
 *   Parameters:    vmf_msg_t *p_my_msg - pointer to VMF message
 *
 *   Function Return value: - void
 *
 ******************************************************************************/
void nw_vmf_debug_msgs(char *prefix, pid_t pid, vmf_msg_t *p_my_msg)
{

    char        buffer[MAX_DEBUG_MSG_SIZE+1];
    char *      p_buffer = buffer;
    unsigned16  i;

    switch (p_my_msg->vmf_basic_msg.msg_base.base.msg_type)
    {

        case MSG_TYPE_BASIC_MESSAGE:
            p_buffer += sprintf(p_buffer, "%s time=%Lu pid=%d --> group=0x%x,event=0x%x,data-len=0x%x"
                                ,prefix ,p_my_msg->vmf_basic_msg.msg_base.base.msg_clk ,pid ,p_my_msg->vmf_basic_msg.msg_base.id.group,p_my_msg->vmf_basic_msg.msg_base.id.event
                                ,p_my_msg->vmf_basic_msg.data.length);
            if (p_my_msg->vmf_basic_msg.data.length > 0)
            {
                p_buffer += sprintf(p_buffer, " data=");
                for (i = 0; ((i < p_my_msg->vmf_basic_msg.data.length) && (i<(MAX_DEBUG_MSG_SIZE/4))); i++)
                {
                    p_buffer += sprintf(p_buffer, "%02x ", p_my_msg->vmf_basic_msg.data.pl[i]);
                }
                NW_VMF_DEBUG_INFO("%s",buffer);
            }
        break;

        case MSG_TYPE_MOST_MESSAGE:
            p_buffer += sprintf(p_buffer, "%s pid=%d --> FBlockId=0x%x,InstId=0x%x,FuncId=0x%x,OpType=0x%1x,data-len=0x%x"
                                ,prefix ,pid , p_my_msg->vmf_most_msg.fblock_id,p_my_msg->vmf_most_msg.inst_id,
                                p_my_msg->vmf_most_msg.func_id,p_my_msg->vmf_most_msg.op_type, p_my_msg->vmf_most_msg.data.length);
            if (p_my_msg->vmf_most_msg.data.length > 0)
            {
                p_buffer += sprintf(p_buffer, " data=");
                for (i = 0; ((i < p_my_msg->vmf_most_msg.data.length) && (i<(MAX_DEBUG_MSG_SIZE/4))); i++)
                {
                    p_buffer += sprintf(p_buffer, "%02x ", p_my_msg->vmf_most_msg.data.pl[i]);
                }
                NW_VMF_DEBUG_INFO("%s",buffer);
            }
        break;

        case MSG_TYPE_CONNECT:
            NW_VMF_DEBUG_INFO("%s pid=%d --> connect",prefix, pid);
        break;

        case MSG_TYPE_REGISTER_EXT_MOST_LINK:
            NW_VMF_DEBUG_INFO("%s pid=%d --> register external most link",prefix, pid);
        break;

        case MSG_TYPE_REGISTER_MOST_FBLOCK:
            NW_VMF_DEBUG_INFO("%s pid=%d --> register FBlock",prefix, pid);
        break;

        case MSG_TYPE_DE_REGISTER_MOST_FBLOCK:
            NW_VMF_DEBUG_INFO("%s pid=%d --> de-register FBlock",prefix, pid);
        break;

        case MSG_TYPE_REGISTER_MOST_SHADOW:
            NW_VMF_DEBUG_INFO("%s pid=%d --> register shadow",prefix, pid);
        break;

        case MSG_TYPE_DE_REGISTER_MOST_SHADOW:
            NW_VMF_DEBUG_INFO("%s pid=%d --> de-register shadow",prefix, pid);
        break;

        case MSG_TYPE_REGISTER_MSG_GROUPS:
            NW_VMF_DEBUG_INFO("%s pid=%d --> register msg groups",prefix, pid);
        break;

        case MSG_TYPE_DE_REGISTER_MSG_GROUPS:
            NW_VMF_DEBUG_INFO("%s pid=%d --> de-register msg groups",prefix, pid);
        break;

        case MSG_TYPE_START_RECEIVE:
            NW_VMF_DEBUG_INFO("%s pid=%d --> start receive",prefix, pid);
        break;

        case MSG_TYPE_REGISTER_SPY:
            NW_VMF_DEBUG_INFO("%s pid=%d --> register spy",prefix, pid);
        break;

        default:
            NW_VMF_DEBUG_INFO("%s pid=%d --> message type=%d",prefix, pid, p_my_msg->vmf_basic_msg.msg_base.base.msg_type);
        break;
    }
}


/*****************************************************************************
 *
 *   Function Name: nw_vmf_debug_register_most_shadow()
 *
 *   Description:   debug of a shadow registration
 *
 *   Parameters:    *reg_msg -- pointer to a shadow registration message.
 *
 *   Return value:  void
 *
 ******************************************************************************/
void nw_vmf_debug_register_most_shadow(vmf_ctrl_msg_register_most_shadow_t *reg_msg)
{

    if (NULL == reg_msg)
    {
        NW_VMF_DEBUG_INFO("nw_vmf_debug_register_most_shadow() -- reg_msg == NULL!!\n");
        return;
    }

    /* display struct */
    NW_VMF_DEBUG_INFO("base.msg_type =%d\n",reg_msg->base.msg_type);
    NW_VMF_DEBUG_INFO("base.pid =%d\n",reg_msg->base.pid);
    NW_VMF_DEBUG_INFO("base.client_id =%d\n",reg_msg->base.client_id);

    NW_VMF_DEBUG_INFO("fBlockId =%d\n",reg_msg->fBlockId);
    NW_VMF_DEBUG_INFO("instId =%d\n",reg_msg->instId);
    NW_VMF_DEBUG_INFO("u16NumFKtIds =%d\n",reg_msg->u16NumFKtIds);
}


/*************************************************************************//**
 *
 *   hex_dump
 *   NOTE: hex dump a buffer
 *   
 *
 *   \param[in] unsigned8 *     - pointer to bufer  
 *   \param[in] len             - length of bufer   
 *   \return    void 
 *
 ******************************************************************************/
void nw_con_HexDump(char * name,unsigned8 *buffer,int len)
{
#define CPL 16
    static  bool b_in_use = false;
    int     i,j, ct;
    char    asci[2*CPL+1];

    if (buffer == NULL)
    {
        (void) fprintf(ERROR_CHANNEL,"nw_con_HexDump - buffer == NULL\n");
        return;
    }

    while (b_in_use)
    {
        delay(1);
    }
    b_in_use = true;


    if (len <= 0) 
    {
        b_in_use = false;
        return;
    }

    (void) fprintf(ERROR_CHANNEL,"%s\n",name);
    for (i=0,j=0; i<len; ++i) 
    {
        asci[j]='.';
        asci[j+1]=0;

        ct = (int)buffer[i];
        (void) fprintf(ERROR_CHANNEL,"%02x ", ct);
        if ((ct > 0x1f) && (ct < 0x7f))
        {
            asci[j]=ct;
        }

        if ((((i+1) % CPL) == 0))
        {
            (void) fprintf(ERROR_CHANNEL,"    %s\n",asci);
            asci[0]=0;
            j=0;
        }
        else
        {
            j+=1;
        }
    }
    for (; j<CPL; ++j) 
    {
        (void) fprintf(ERROR_CHANNEL,"   ");
    }

    (void) fprintf(ERROR_CHANNEL,"    %s\n\n",asci);
    b_in_use = false;
}

ptrdiff_t check_used_stack (unsigned8 *stackbase)
{
    unsigned8       mystack_base;
    return (stackbase - &mystack_base);
}


#undef __NW_VMF_DEBUG_C__

