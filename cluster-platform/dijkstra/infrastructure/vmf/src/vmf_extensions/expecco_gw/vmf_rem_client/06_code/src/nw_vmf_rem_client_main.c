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
#define DAB_IN_GRP		20
#define DAB_IN_EVT		1


#define RegOprComplete  1
#define DEFAULT_TARGET_IP	"192.168.5.1"
#define LOCAL_TCP_PORT		4711
#define LOCAL_TCP_ADDR		"127.0.0.1"

#include "nw_vmf_rem.h"


static unsigned8	am_vmf_event_list[] = { DAB_IN_GRP};
static bool			tcp_is_connected	= false;
static int			tcp_sock=0;							 /* Socket descriptor */

static void _nw_vmf_rem_debug_dsp_msg(vmf_msg_t *p_my_msg);
static bool _tcp_send_packet(unsigned16 port,char *ip,unsigned16 data_len, unsigned8 *data);
static bool _tcp_connect(unsigned16 port,char *ip);





int main(int argc, _TCHAR* argv[])
{
vmf_client_id_t cid=0;
char			vmf_target_ip[]={"255.255.255.255"};


    NW_REM_VMF_DEBUG_PRINTF("Remote VMF client: main startet!\n");

	if (argc > 1)
	{
		strncpy(vmf_target_ip,(const char*)argv[1],sizeof(vmf_target_ip));
	}
	else
	{
		strncpy(vmf_target_ip,DEFAULT_TARGET_IP,sizeof(vmf_target_ip));
	}

	/*  connect to client */
	cid = nw_vmf_connect(vmf_target_ip,NULL,0,VMF_CLIENT_QUEUE_SIZE_STANDARD,VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD);
	if (cid <= 0)
	{
		/* we got an error */
		NW_REM_VMF_DEBUG_PRINTF("Remote VMF client: nw_vmf_connect failed\n");
		return (1);
	}


	printf("DAB-VMF-Gateway: connected to target = %s, cid =%d\n",vmf_target_ip,cid);fflush(stdout);


	/* register some msg groups */ 
	if(nw_vmf_register_msg_group(cid,sizeof(am_vmf_event_list),&am_vmf_event_list[0]) < 0)
    {
       NW_REM_VMF_DEBUG_PRINTF("Remote VMF client: Can not register VMF events\n");
       return 1;
    }

	
	/* main reception loop */
	while (1)
	{
		signed16		rec_num; 
		vmf_msg_t		vmf_msg;

		/* receive a vmf message */
		rec_num = nw_vmf_receive  (cid,&vmf_msg,sizeof(vmf_msg));
		if (rec_num < 0)
		{
			/*nw_vmf_receive error */
			printf ("nw_vmf_receive() failed\n");
			break;
		}
		NW_REM_VMF_DEBUG_PRINTF("Remote VMF client: nw_vmf_receive() got %d bytes \n",rec_num);

        if (rec_num > 0)
		{
			/* display message */
			_nw_vmf_rem_debug_dsp_msg(&vmf_msg);
		}
		if (DAB_IN_EVT == vmf_msg.vmf_basic_msg.msg_base.id.event)
		{
			_tcp_send_packet(LOCAL_TCP_PORT,LOCAL_TCP_ADDR,vmf_msg.vmf_basic_msg.data.length,vmf_msg.vmf_basic_msg.data.pl);
		}
	}

	// nw_vmf_close(cid);

	return 0;
}


static bool _tcp_send_packet(unsigned16 port,char *ip,unsigned16 data_len, unsigned8 *data)
{
	unsigned int tx_len;
	bool		 b_ret = false;

	if (NULL == ip)
	{
		return false;
	}

	if (!tcp_is_connected)
	{
		if(!_tcp_connect(port,ip))
		{
			printf("failed to connect to server:%s:%d\n",ip,port);
			return false;
		}
	}

    /* Send the data to the server */
    tx_len = send(tcp_sock, data, data_len, 0);
	if (tx_len == data_len)
	{
		b_ret=true;
	}
	else
	{
		b_ret=false;
	}

	return b_ret;
}


static bool _tcp_connect(unsigned16 port,char *ip)
{
    struct sockaddr_in srv_addr;			/* server address */

	if (tcp_is_connected)
	{
		/* already connected */
		return true;
	}

	/* Create the TCP socket */
	tcp_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (tcp_sock < 0)
	{
		printf("_tcp_connect: error creating tcp-socket\n");
		return false;
	}

    /* ctrate the server address structure */
    memset(&srv_addr, 0, sizeof(srv_addr));				/* clear structure */
    srv_addr.sin_family			= AF_INET;				/* Internet address family */
    srv_addr.sin_addr.s_addr	= inet_addr(ip);	/* Server IP address */
    srv_addr.sin_port			= htons(port);			/* Server port */

    /* Establish connection to the tcp-server */
    if (connect(tcp_sock, (struct sockaddr *) &srv_addr, sizeof(srv_addr)) < 0)
	{
		printf("_tcp_connect: connect() failed\n");
		return false;
	}

	tcp_is_connected =  true;
	return true;
}



#define MAX_DEBUG_MSG_SIZE	400

static void _nw_vmf_rem_debug_dsp_msg(vmf_msg_t *p_my_msg)
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
