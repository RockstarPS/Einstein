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

  Module:               nw_rem_vmf_debug.c.c
  Description:          remote vmf debug functions

  Project Scope:        Beethoven VM platform

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   Visual Studio
  Target Hardware:      Any

  *****************************************************************************/
/* application includes */
#include "nw_vmf_rem.h"					/* vmf cfg file */

#define MAX_DEBUG_MSG_SIZE	400

void nw_vmf_rem_debug_dsp_msg(vmf_msg_t *p_my_msg)
{
    char        buffer[MAX_DEBUG_MSG_SIZE+1];
    char *      p_buffer = buffer;
    unsigned16  i;
	char		prefix[] = {0};

	
	switch (p_my_msg->vmf_basic_msg.msg_base.base.msg_type)
    {

        case MSG_TYPE_BASIC_MESSAGE:
			p_buffer += sprintf(p_buffer, "Basic-message: group=0x%x,event=0x%x,data-len=0x%x"
                                ,p_my_msg->vmf_basic_msg.msg_base.id.group,p_my_msg->vmf_basic_msg.msg_base.id.event
                                ,p_my_msg->vmf_basic_msg.data.length);
            if (p_my_msg->vmf_basic_msg.data.length > 0)
            {
                p_buffer += sprintf(p_buffer, " data=");
                for (i = 0; ((i < p_my_msg->vmf_basic_msg.data.length) && (i<(MAX_DEBUG_MSG_SIZE/4))); i++)
                {
                    p_buffer += sprintf(p_buffer, "%02x ", p_my_msg->vmf_basic_msg.data.pl[i]);
                }
            }
           	NW_REM_VMF_DEBUG_INFO(buffer);
        break;

        case MSG_TYPE_MOST_MESSAGE:
			p_buffer += sprintf(p_buffer, "Most-message: FBlockId=0x%x,InstId=0x%x,FuncId=0x%x,OpType=0x%1x,data-len=0x%x"
                                , p_my_msg->vmf_most_msg.fblock_id,p_my_msg->vmf_most_msg.inst_id,
                                p_my_msg->vmf_most_msg.func_id,p_my_msg->vmf_most_msg.op_type, p_my_msg->vmf_most_msg.data.length);
			if ((p_my_msg->vmf_most_msg.data.length > 0) && (p_my_msg->vmf_most_msg.data.length < MAX_DEBUG_MSG_SIZE ))
            {
                p_buffer += sprintf(p_buffer, " data=");
                for (i = 0; ((i < p_my_msg->vmf_most_msg.data.length) && (i<(MAX_DEBUG_MSG_SIZE/4))); i++)
                {
                    p_buffer += sprintf(p_buffer, "%02x ", p_my_msg->vmf_most_msg.data.pl[i]);
                }
            }
           	NW_REM_VMF_DEBUG_INFO(buffer);
        break;

	}
}