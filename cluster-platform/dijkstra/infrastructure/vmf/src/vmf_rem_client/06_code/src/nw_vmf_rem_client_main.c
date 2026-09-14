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

  Module:               nw_vmf_rem_client_main.c
  Description:          test main() module for remote vmf client

  Project Scope:        Beethoven VM platform

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   Visual Studio
  Target Hardware:      Any

  *****************************************************************************/


#define VMF_REM_DEBUG

#define DIAG_STATUS     25
#define NETWORK_STATUS  26
#define POWER_IN        27
#define HMI_STATUS      28
#define REG_OPERATION   29

#define RegOprComplete  1



#include "nw_vmf_rem.h"

unsigned8 am_vmf_event_list[] = { DIAG_STATUS,
								  NETWORK_STATUS,
                                  POWER_IN,
								  HMI_STATUS};





int main(int argc, _TCHAR* argv[])
{
vmf_client_id_t cid=0;
vmf_client_id_t cid120=0;
signed16		rec_num; 
vmf_msg_t		vmf_msg;

    NW_REM_VMF_DEBUG_PRINTF("Remote VMF client: main startet!\n");

	/*  connect to client */

#if 0
	/* register some msg groups */ 
	if(nw_vmf_register_msg_group(cid,sizeof(am_vmf_event_list),&am_vmf_event_list[0]) < 0)
    {
       NW_REM_VMF_DEBUG_PRINTF("Remote VMF client: Can not register VMF events\n");
       return 1;
    }
#endif
/*
	if(nw_vmf_register_spy(cid) < 0)
    {
       NW_REM_VMF_DEBUG_PRINTF("Remote VMF client: Can not register as spy\n");
       return 1;
    }
    NW_REM_VMF_DEBUG_PRINTF("Remote VMF client: registered as spy!\n");
*/
//	cid120 = nw_vmf_connect("192.168.1.120",NULL,0,VMF_CLIENT_QUEUE_SIZE_STANDARD,VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD);
 while (1)
 {
	cid = nw_vmf_connect("192.168.1.10",NULL,0,VMF_CLIENT_QUEUE_SIZE_STANDARD,VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD);
	if (cid <= 0)
	{
		/* we got an error */
		NW_REM_VMF_DEBUG_PRINTF("Remote VMF client: nw_vmf_connect failed\n");
		Sleep(1000);
		break;
	}
	printf("connected() cid = %d\n",cid);fflush(stdout);

	while (1)
	{
#if 1
		/* register some msg groups */ 
		if(nw_vmf_register_msg_group(cid,sizeof(am_vmf_event_list),&am_vmf_event_list[0]) < 0)
		{
		   NW_REM_VMF_DEBUG_PRINTF("Remote VMF client: Can not register VMF events\n");
		   break;
		}


		NW_REM_VMF_DEBUG_PRINTF("Remote VMF client: connected!\n");

		/* receive a vmf message */
		rec_num = nw_vmf_receive  (cid,&vmf_msg,sizeof(vmf_msg));
        NW_REM_VMF_DEBUG_PRINTF("Remote VMF client: nw_vmf_receive() got %d bytes \n",rec_num);

        if (rec_num > 0)
		{
			/* display message */
			nw_vmf_rem_debug_dsp_msg(&vmf_msg);
		}
		else
		{
			break;
		}
#endif
		/* create a basic message */
        NW_REM_VMF_DEBUG_PRINTF("Remote VMF client: nw_vmf_send_basic() with cid %d \n",cid);
		vmf_msg.vmf_basic_msg.msg_base.id.group       = REG_OPERATION;
        vmf_msg.vmf_basic_msg.msg_base.id.event       = RegOprComplete;
        vmf_msg.vmf_basic_msg.data.pl[0]              = 1;
        vmf_msg.vmf_basic_msg.data.pl[1]              = 2;
        vmf_msg.vmf_basic_msg.data.pl[2]              = 3;
        vmf_msg.vmf_basic_msg.data.pl[3]              = 4;
        vmf_msg.vmf_basic_msg.data.length             = 4;
		nw_vmf_send_basic(cid,(vmf_basic_msg_t *)&vmf_msg);

//		nw_vmf_send_basic(cid120,(vmf_basic_msg_t *)&vmf_msg);
//		NW_REM_VMF_DEBUG_INFO("nw_vmf_send_basic() with %d payload bytes \n",vmf_msg.vmf_basic_msg.data.length)
#if 0
		/* create a most message */
        vmf_msg.vmf_most_msg.src_addr = 0x100;
        vmf_msg.vmf_most_msg.tgt_addr = 0x3c8;
        vmf_msg.vmf_most_msg.fblock_id = 0xca;
        vmf_msg.vmf_most_msg.inst_id = 0;
        vmf_msg.vmf_most_msg.func_id = 0x247;
        vmf_msg.vmf_most_msg.op_type = 0x0c;
        vmf_msg.vmf_most_msg.data.length = 0x04;
        vmf_msg.vmf_most_msg.data.pl[0]=1;
        vmf_msg.vmf_most_msg.data.pl[1]=2;
        vmf_msg.vmf_most_msg.data.pl[2]=3;
        vmf_msg.vmf_most_msg.data.pl[3]=4;
        nw_vmf_send_most_ctrl(cid,(vmf_most_msg_t *)&vmf_msg);

        vmf_msg.vmf_most_msg.data.pl[3]=5;
        nw_vmf_send_most_ctrl(cid,(vmf_most_msg_t *)&vmf_msg);
#endif
//		Sleep(1000);
	}
  nw_vmf_disconnect(cid);
  Sleep(1000);
 }

	return 0;
}


