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

  Module:               expecco-vmg-gw.c
  Description:          vmf to expecco gw

  Project Scope:        R013

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Jochen Becker

  Compiler/Assembler:   Visual Studio
  Target Hardware:      Any

  *****************************************************************************/


/* includes */
#define VMF_REM_DEBUG
#include "unistd.h"
#include "nw_vmf_rem.h"

/* defines */
#define DIAG_STATUS     25
#define NETWORK_STATUS  26
#define POWER_IN        27
#define HMI_STATUS      28
#define REG_OPERATION   29
#define DAB_IN_GRP		20
#define DAB_STATUS		21
#define DAB_BASEBAND_IN	22
#define DAB_IN_EVT		1


#define RegOprComplete  1
#define DEFAULT_TARGET_IP	"192.168.5.1"
#define LOCAL_TCP_PORT		4711
#define LOCAL_TCP_ADDR		"127.0.0.1"
#define EXPECCO_HEADER_SIZE		4
#define MAX_EXPECCO_MSG_LEN	2000
#define MAX_EXPECCO_BUFFER_LEN	sizeof(VMF_VAR_MSG_TYP(MAX_EXPECCO_MSG_LEN))

#pragma pack(push,1)
typedef struct
{
	unsigned8 len_low;
	unsigned8 len_high;
	unsigned8 vmf_grp;
	unsigned8 vmf_evt;
	unsigned8 buf[MAX_EXPECCO_MSG_LEN];
}expecco_msg_t;
#pragma pack (pop)



/* global data */
//static unsigned8		msg_grp_list[] = { DAB_IN_GRP,DAB_STATUS,DAB_BASEBAND_IN};
static unsigned8		msg_grp_list[] = { 0,0,0,0,0,0,0,0,0,0};
static int				msg_grp_list_num = 0;
static bool				tcp_is_connected	= false;
static int				tcp_sock=0;							 /* Socket descriptor */
static bool				tcp_thread_running = false;
/* function prototypes */
static void				_nw_vmf_rem_debug_dsp_msg(vmf_msg_t *p_my_msg);
static bool				_tcp_send_packet(unsigned16 port,char *ip,unsigned16 data_len, unsigned8 *data);
static vmf_client_id_t	_nw_vmf_con_2_vmf(char *p_vmf_target_ip);
static bool				_tcp_connect(unsigned16 port,char *ip);
static void				_tcp_close(void);
static void	*			tcp_rx_thread_create(int sock);
static void	*			tcp_rx_thread(void * p_data);
static vmf_client_id_t	cid=0;
static void				hex_dump (char *name,unsigned8 *buffer,int len);
static int				recv_wait(SOCKET s,char  * buf,int len,int flags);
static bool				verbose = false;
static bool				b_ip = false;



/*************************************************************************//**
 *
 *   main
 *   NOTE: expecco vmf-gw main loop
 *   
 *
 *   \param[in] argc	
 *	 \param[in] argv	
 *   \return    0 if OK 
 *
 ******************************************************************************/
int main(int argc, _TCHAR* argv[])
{
char			vmf_target_ip[]={"255.255.255.255"};
int				opt;

#define GW_NAME			"VMF expeco gateway "
#define GW_VERSION		"1.3"
#define	GW_HELP_STRING	"\n" GW_NAME " version " GW_VERSION "\n"\
						"usage:   vmf_dab_gw -i <target ip> [-g <vmf message group>] \n"\
						"      -i  <target ip>        - set ip address of vmf target \n"\
						"      -g <vmf message group> - (optional) set dab debug message group (decimal)\n"\
						"example: expecco_gw -i 192.168.5.1 -g 16 -g 17\n"\
						"example: expecco_gw -i 192.168.5.1\n"

#define	GW_MSG_GRP_ERROR_STRING	"Please define at least one message group \n"
#define	GW_MSG_IP_ERROR_STRING	"Please define the target IP address \n"



    NW_REM_VMF_DEBUG_PRINTF("expecco_gw startet\n");

	if (argc < 2)
	{
	    NW_REM_VMF_DEBUG_PRINTF ("%s\n",GW_HELP_STRING);
	    return(0);      /* leave vmf */
	}

	while ((opt = getopt(argc, argv, "i:g:H")) != -1) 
    {
        switch (opt) 
        {
            case 'i':
            case 'I':
				// ip address of target
				strncpy(vmf_target_ip,optarg,sizeof(vmf_target_ip));
				b_ip = true;
			    NW_REM_VMF_DEBUG_PRINTF("expecco_gw: vmf_target_ip=%s\n",vmf_target_ip);
                break;
  
            case 'g':
            case 'G':
				// msg group
				if (msg_grp_list_num < sizeof(msg_grp_list))
				{
					msg_grp_list[msg_grp_list_num++] = (unsigned8)atoi(optarg);
				}
			    NW_REM_VMF_DEBUG_PRINTF("expecco_gw: msg_group=%i\n",atoi(optarg));
                break;

			case 'v':
			case 'V':
				verbose = true;
                break;
			
			case 'h':
			case 'H':
	           NW_REM_VMF_DEBUG_PRINTF ("%s\n",GW_HELP_STRING);
	           return(0);      /* leave vmf */
		}

	}

	if (0 == msg_grp_list_num)
	{
		NW_REM_VMF_DEBUG_PRINTF ("%s\n",GW_MSG_GRP_ERROR_STRING);
        NW_REM_VMF_DEBUG_PRINTF ("%s\n",GW_HELP_STRING);
        return(0);      /* leave vmf */
	}

	if (false == b_ip)
	{
		NW_REM_VMF_DEBUG_PRINTF ("%s\n",GW_MSG_IP_ERROR_STRING);
        NW_REM_VMF_DEBUG_PRINTF ("%s\n",GW_HELP_STRING);
        return(0);      /* leave vmf */
	}

	/* start rx thread */
	tcp_rx_thread_create(tcp_sock);


	/*  connect to vmf */
	cid = _nw_vmf_con_2_vmf(vmf_target_ip);
	if (cid <= 0)
	{
		return 1;
	}

	/* register some msg groups */ 
	if(nw_vmf_register_msg_group(cid,msg_grp_list_num,&msg_grp_list[0]) < 0)
    {
       NW_REM_VMF_DEBUG_PRINTF("Remote VMF client: Can not register VMF events\n");
       return 1;
    }
	
	/* main vmf-reception loop */
	while (true)
	{
		signed16									rec_num; 
		VMF_VAR_MSG_TYP(MAX_EXPECCO_MSG_LEN)		vmf_msg;
		expecco_msg_t expecco_msg;

		/* receive a vmf message */
		rec_num = nw_vmf_receive  (cid,(vmf_msg_t *)&vmf_msg,sizeof(vmf_msg));
		if (rec_num < 0)
		{
			/* nw_vmf_receive error */
			/* most likely the target was swotched off */
			/* so try to reconnect   */
			printf ("nw_vmf_receive() failed - try to reconnect to target\n");
			cid = _nw_vmf_con_2_vmf(vmf_target_ip);

			/* register some msg groups */ 
			if(nw_vmf_register_msg_group(cid,msg_grp_list_num,&msg_grp_list[0]) < 0)
			{
			   NW_REM_VMF_DEBUG_PRINTF("Remote VMF client: Can not register VMF events\n");
			   return 1;
			}

			continue;
		}
		else if (rec_num > 0)
		{
			/* display message */
//			_nw_vmf_rem_debug_dsp_msg(&vmf_msg);
//			if (DAB_IN_EVT == vmf_msg.vmf_basic_msg.msg_base.id.event)
			{
				/* send message to expecco */
				int msg_len;

				msg_len = vmf_msg.vmf_basic_msg.data.length + EXPECCO_HEADER_SIZE;
				
				expecco_msg.len_low  = msg_len % 256;
				expecco_msg.len_high = msg_len / 256;
				expecco_msg.vmf_grp  = vmf_msg.vmf_basic_msg.msg_base.id.group; 
				expecco_msg.vmf_evt  = vmf_msg.vmf_basic_msg.msg_base.id.event;
				memcpy (expecco_msg.buf,vmf_msg.vmf_basic_msg.data.pl,vmf_msg.vmf_basic_msg.data.length); 

				hex_dump("data to expecco",(unsigned8 *)&expecco_msg,msg_len);
//				fprintf (stderr,"main()-forward message to expecco\n");
				_tcp_send_packet(LOCAL_TCP_PORT,LOCAL_TCP_ADDR,msg_len,(unsigned8 *)&expecco_msg);
//				fprintf (stderr,"main()-forward message to expecco done\n");
			}
		}
		else
		{
			/* we received a zero byte message  - so wait some time before trying again */
			delay(10);
		}
	}

	// nw_vmf_close(cid);

	return 0;
}


/*************************************************************************//**
 *
 *   _tcp_send_packet
 *   NOTE: send a tcp packet to the expecco tcp-server
 *		   tcp connection will be established if needed
 *   
 *
 *   \param[in] port		- tcp port	
 *	 \param[in] ip			- tcp ip address as string	
 *	 \param[in] data_len	- size of data in bytes	
 *	 \param[in] data		- address of transmit data	
 *   \return    true if OK 
 *
 ******************************************************************************/
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
		fprintf(stderr,"_tcp_send_packet() failed - not connected\n");
	}

    /* Send the data to the server */
//	fprintf (stderr,"_tcp_send_packet(): send\n"); 
	tx_len = send(tcp_sock, data, data_len, 0);
//	fprintf (stderr,"_tcp_send_packet(): send done-tx_len=%d\n",tx_len); 
	if (tx_len == data_len)
	{
		b_ret=true;
	}
	else
	{
		_tcp_close();
		b_ret=false;
	}

	return b_ret;
}



/*************************************************************************//**
 *
 *   _tcp_connect
 *   NOTE: create a tcp connection to the expecco tcp-server
 *   
 *
 *   \param[in] port		- tcp port	
 *	 \param[in] ip			- tcp ip address as string	
 *   \return    true if OK 
 *
 ******************************************************************************/
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
//		fprintf(stderr,"_tcp_connect: error creating tcp-socket\n");
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
//		printf("_tcp_connect: connect() failed\n");
		_tcp_close();
		return false;
	}

	tcp_is_connected =  true;

	fprintf(stderr,"_tcp_connect: tcp-socket connected\n");

	return true;
}


/*************************************************************************//**
 *
 *   _tcp_close
 *   NOTE: close the tcp connection to expecco
 *   
 *
 *   \param[in] void	
 *   \return    void 
 *
 ******************************************************************************/
static void _tcp_close(void)
{
	closesocket(tcp_sock);
	tcp_is_connected =  false;
}




/*************************************************************************//**
 *
 *   _nw_vmf_rem_debug_dsp_msg
 *   NOTE: print the content of a vmf message on the console
 *   
 *
 *   \param[in] vmf_msg		- pointer to the vmf-massage union	
 *   \return    void 
 *
 ******************************************************************************/
static void _nw_vmf_rem_debug_dsp_msg(vmf_msg_t *p_my_msg)
{
	#define MAX_DEBUG_MSG_SIZE	400
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



/*************************************************************************//**
 *
 *   _nw_vmf_rem_debug_dsp_msg
 *   NOTE: print the content of a vmf message on the console
 *   
 *
 *   \param[in] vmf_msg		- pointer to the vmf-massage union	
 *   \return    void 
 *
 ******************************************************************************/
static vmf_client_id_t _nw_vmf_con_2_vmf(char *p_vmf_target_ip)
{
	/*  connect to vmf */
	vmf_client_id_t my_cid;

	printf("DAB-VMF-Gateway: try to connect to target = %s\n",p_vmf_target_ip);fflush(stdout);
	while (true)
	{
		my_cid = nw_vmf_connect(p_vmf_target_ip,NULL,0,VMF_CLIENT_QUEUE_SIZE_STANDARD,MAX_EXPECCO_BUFFER_LEN);
		if (my_cid <= 0)
		{
			/* we got an error */
			/* wait some time and try again */
//			NW_REM_VMF_DEBUG_PRINTF("Remote VMF client: nw_vmf_connect failed\n");
			delay(1000);
			printf(".");
			continue;
		}
		else
		{
			break;
		}
	}
	printf("DAB-VMF-Gateway: connected to target = %s, cid =%d\n",p_vmf_target_ip,my_cid);fflush(stdout);
	return my_cid;
}



/*************************************************************************//**
 *
 *   tcp_rx_thread_create
 *   NOTE: create the tcp receive thread
 *   
 *
 *   \param[in] void *		- pointer to the socket	
 *   \return    void *
 *
 ******************************************************************************/
static void * tcp_rx_thread_create(int sock)
{
	pthread_t	thread;
	int			iret;
	void *		fret=NULL;

//	fprintf(stderr,"tcp_rx_thread_create()\n");

	if (tcp_thread_running)
	{
		/* thread already started */
		return fret;
	}


	iret = pthread_create( &thread, NULL, tcp_rx_thread, (void*)&sock);
	if (0 == iret)
	{
		/* wait for thread */	
//		pthread_join( thread, NULL);
	}
	else
	{
		/* and error occured */
		fret = (void *)-1;
	}

//	fprintf(stderr,"tcp_rx_thread_create() done\n");
	return fret;
}


/*************************************************************************//**
 *
 *   tcp_rx_thread
 *   NOTE: tcp receive thread
 *   
 *
 *   \param[in] void *		- pointer to the socket	
 *   \return    void *
 *
 ******************************************************************************/
static void * tcp_rx_thread(void * p_data)
{
//	int				sock=0;
	int				num_bytes;
	VMF_VAR_BASIC_MSG_TYP(MAX_EXPECCO_MSG_LEN)		vmf_basic_msg;
//	vmf_basic_msg_t	vmf_basic_msg;
	vmf_ret_t		vmf_ret;
	expecco_msg_t	my_msg;

	tcp_thread_running = true;
	printf("tcp_rx_thread() started\n");

#if 1
	while (true)
	{
		/* connect to expecco */
		if (!tcp_is_connected)
		{
			if(!_tcp_connect(LOCAL_TCP_PORT,LOCAL_TCP_ADDR))
			{
				printf (".");
				delay(1000);
				continue;
			}
		}

		num_bytes = recv(tcp_sock,(unsigned8 *)&my_msg,sizeof(my_msg),0);
		if (num_bytes < 0)
		{
			printf("ERROR: tcp_rx_thread() - recv error d\n");
			
			/* try to re-establish the connection */
			_tcp_close();
			continue;
		}
		else if (num_bytes < EXPECCO_HEADER_SIZE)
		{	
			/* message to short !*/
			/*
			printf("tcp_rx_thread: message to short=%d - ignore\n",num_bytes);
			hex_dump("data from Expecco",(unsigned8 *)&my_msg,num_bytes); */
			delay(100);
			continue;
		}
		else
		{
//			printf("tcp_rx_thread: recv %d bytes\n",num_bytes);
			hex_dump("data from Expecco",(unsigned8 *)&my_msg,num_bytes);

			if (num_bytes <sizeof(vmf_basic_msg))
			{
				/* forward message to vmf */
				vmf_basic_msg.msg_base.id.group = my_msg.vmf_grp;
				vmf_basic_msg.msg_base.id.event = my_msg.vmf_evt;
				vmf_basic_msg.data.length =( my_msg.len_low + (my_msg.len_high*256))-EXPECCO_HEADER_SIZE;
				memcpy(vmf_basic_msg.data.pl,my_msg.buf,vmf_basic_msg.data.length);

//				printf("tcp_rx_thread: nw_vmf_send_basic()\n");
				vmf_ret = nw_vmf_send_basic(cid,(vmf_basic_msg_t *)&vmf_basic_msg);
//				printf("tcp_rx_thread: nw_vmf_send_basic() done\n");
				if (VMF_OK != vmf_ret)
				{
					printf("ERROR: tcp_rx_thread() - nw_vmf_send_basic failed er=%d\n",vmf_ret);
				}
			}
			else
			{
				printf("ERROR: tcp_rx_thread() - to much data - len=%d\n",num_bytes);
			}
		}
	}
#else
	while (true)
	{
		int i_ret;
		unsigned8 two_by[2];

		/* connect to expecco */
		if (!tcp_is_connected)
		{
			if(!_tcp_connect(LOCAL_TCP_PORT,LOCAL_TCP_ADDR))
			{
				printf (".");
				delay(1000);
				continue;
			}
		}


		/* read length ( first two byte in little endian) */
		i_ret = recv_wait(tcp_sock,(unsigned8 *)&two_by,sizeof(two_by),0);
		if (i_ret < 0)
		{
			printf("ERROR: tcp_rx_thread() - recv_wait error 1 - re-establish tcp connection\n");

			/* try to re-establish the connection */
			_tcp_close();
			continue;
		}
		else if (i_ret == sizeof(num_bytes))
		{
			/* get remaining bytes */						
			num_bytes = two_by[0] + (two_by[1]*256); 
			i_ret = recv_wait(tcp_sock,(unsigned8 *)&(my_msg.vmf_grp),num_bytes-sizeof(num_bytes),0);
			if (i_ret < 0)
			{
				printf("ERROR: tcp_rx_thread() - recv_wait error 2 - re-establish tcp connection\n");

				/* try to re-establish the connection */
				_tcp_close();
				continue;
			}

			hex_dump("data from Expecco",(unsigned8 *)&my_msg,num_bytes);

			if (num_bytes <sizeof(vmf_basic_msg))
			{
				/* forward message to vmf */
				vmf_basic_msg.msg_base.id.group = my_msg.vmf_grp;
				vmf_basic_msg.msg_base.id.event = my_msg.vmf_evt;
				vmf_basic_msg.data.length = num_bytes-EXPECCO_HEADER_SIZE;
				memcpy(vmf_basic_msg.data.pl,my_msg.buf,vmf_basic_msg.data.length);

				vmf_ret = nw_vmf_send_basic(cid,(vmf_basic_msg_t *)&vmf_basic_msg);
				if (VMF_OK != vmf_ret)
				{
					printf("ERROR: tcp_rx_thread() - nw_vmf_send_basic failed er=%d\n",vmf_ret);
				}
			}
			else
			{
				printf("ERROR: tcp_rx_thread() - to much data - len=%d\n",num_bytes);
				continue;
			}

		}
		else
		{
			/* got zero bytes */
			delay(10);
			continue;
		}
	}
#endif

	tcp_thread_running = false;

	return NULL;
}





/*************************************************************************//**
 *
 *   hex_dump
 *   NOTE: hex dump a buffer
 *   
 *
 *   \param[in] unsigned8 *		- pointer to bufer	
 *   \param[in] len				- length of bufer	
 *   \return    void 
 *
 ******************************************************************************/
static void hex_dump(char * name,unsigned8 *buffer,int len)
{
#define CPL 16
	static	b_in_use = false;
	int		i,j, ct;
	char	asci[2*CPL];

	if (buffer == NULL)
	{
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

	printf("%s",name);
	for (i=0,j=0; i<len; ++i) 
	{
		if ((i % CPL) == 0)
		{
			printf("    %s\n",asci);
			j=0;
		}
		asci[j]='.';
		asci[j+1]=0;

		ct = (int)buffer[i];
		printf("%02x ", ct);
		if ((ct > 0x1f) && (ct < 0x7f))
		{
			asci[j]=ct;
		}
		j+=1;
	}
	for (; j<CPL; ++j) 
	{
		printf("   ");
	}

	printf("    %s\n\n",asci);
	b_in_use = false;
}


/*************************************************************************//**
 *
 *   receives data on a socket till all data is received  \n
 *   NOTE: done because MSG_WAITALL is not supported on Windows
 *   
 *
 *   \param[in] SOCKET	 -- socket
 *   \param[in] buf		 -- buffer for rx data
 *   \param[in] len		 -- buffer len
 *   \param[in] flags	 -- rx flags
 *   \return    number of bytes or 0 or -1 
 *
 ******************************************************************************/
static int recv_wait(SOCKET s,char  * buf,int len,int flags)
{
	int num_bytes;
	unsigned16	all_bytes=0;

	while (all_bytes < len)
	{
		/* receive rpc_id */
		num_bytes = recv(s, &(buf[all_bytes]), len-all_bytes, 0);
		if (num_bytes > 0)
		{
			all_bytes+=num_bytes;			
		}
		else
		{
			return num_bytes;
		}
	}
	return all_bytes;
}
