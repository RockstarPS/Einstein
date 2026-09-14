/*
 Send a basic message thru VMF
 by J. Merkle
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>

#include "types.h"
#include "nw_vmf.h"

#ifndef __WINDOWS__
#include <termios.h>            
#endif


/* defs and typedefs */
#define VMF_ERROR_PRINT(args...)   {fprintf(ERROR_CHANNEL,"Error:  ");fprintf(ERROR_CHANNEL,args);fprintf(ERROR_CHANNEL,"\n");}
#define VMF_INFO_PRINT(args...)    {fprintf(ERROR_CHANNEL,"Info :  ");fprintf(ERROR_CHANNEL,args);fprintf(ERROR_CHANNEL,"\n");}
#define VMF_INFO2_PRINT(args...)    // {fprintf(ERROR_CHANNEL,"Info :  ");fprintf(ERROR_CHANNEL,args);fprintf(ERROR_CHANNEL,"\n");}

typedef struct
{
	unsigned8	rx_msg_grp;
    unsigned8   message_group;
    unsigned8   event;
    unsigned8   data[4];
    unsigned8   data_len;
}options_t;


/* global data */
vmf_client_id_t     vmf_connection_handle=0;
unsigned8           vmf_trace_trid=0;
options_t           options={0};


/* function prototypes */
static void *vmf_trace_dlt_gw_thread(void *pArg);
bool get_options(int argc, char *argv[]);
void usage(void);
bool vmf_transceiver_create_thread(void);



/**************************************************************************//**
 *
 *   Function Name: main()
 *
 *   Description:   main function
 *
 *   Parameters:    argc, argv
 *
 *   Function Return value: -1 if error else 0
 *
 ******************************************************************************/
int main (int argc, char *argv[])
{

    vmf_ret_t   vmf_result;

    VMF_VAR_BASIC_MSG_TYP(10) msg;
    vmf_basic_msg_t *pmsg = (vmf_basic_msg_t *)&msg;


    if (false == get_options(argc,argv))
    {
        return -1;
    }

	VMF_INFO_PRINT("----------------------------------") 
	VMF_INFO_PRINT("enter 's' to send a message to vmf") 
	VMF_INFO_PRINT("enter 'q' to quit the program") 
	VMF_INFO_PRINT("----------------------------------") 

	
#ifdef PRINT_OPTIONS_ONLY
    return 0;
#endif

	VMF_INFO2_PRINT("main() connect to VMF");

	/* wait for a vmf connection */
	while(true)
	{
		vmf_connection_handle = nw_vmf_connect( "transceiver", 0, 0, VMF_CLIENT_QUEUE_SIZE_STANDARD, VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD);
		if (vmf_connection_handle < 0)
		{
			VMF_ERROR_PRINT("send_basic_message: connect failed --error %d\n",(int)vmf_connection_handle);
			return -1;
		}
		else
		{
			/* connected */
			break;
		}
		nw_sleep_ms(100);
	}

	/* start rx thread */
	VMF_INFO2_PRINT("main() start rx thread");
	vmf_transceiver_create_thread();
	
    NW_VMF_BASIC_MSG_GROUP(pmsg)   	 	= options.message_group;
    NW_VMF_BASIC_MSG_EVENT(pmsg)    	= options.event;
    NW_VMF_BASIC_MSG_DATA_PTR(pmsg)[0]	= options.data[0];
    NW_VMF_BASIC_MSG_DATA_PTR(pmsg)[1]	= options.data[1];
    NW_VMF_BASIC_MSG_DATA_PTR(pmsg)[2]	= options.data[2];
    NW_VMF_BASIC_MSG_DATA_PTR(pmsg)[3]	= options.data[3];
	NW_VMF_BASIC_MSG_DATA_LENGTH(pmsg)  = options.data_len;
	

	/* waiting for a key press */
	while(true)
	{
		int in_c;
#ifndef __WINDOWS__
		static struct termios org_conf;
		static struct termios new_conf;
		/* store original config */
		(void)tcgetattr( STDIN_FILENO, &org_conf);
		new_conf = org_conf;
		new_conf.c_lflag &= ~(ICANON); 		/* unbuffered input */
		// new_conf.c_lflag &= ~(ECHO); 		/* no input echo */  // !! terminal session will not recover Linux bug ?? !!
		tcsetattr( STDIN_FILENO, TCSANOW, &new_conf);
#endif		
		
		in_c = fgetc(stdin);
		switch (in_c)
		{
			case 's':
			case 'S':
			{
				vmf_result = nw_vmf_send_basic (vmf_connection_handle,(vmf_basic_msg_t*)pmsg);
				if(VMF_OK != vmf_result)
				{
					VMF_ERROR_PRINT("send_basic_message: send vmf basic message failed -- VMF error %d\n", (int)vmf_result);
				}
				else
				{
					/*  no code */
				}
			}
			break;
			
			case 'q':
			case 'Q':
#ifndef __WINDOWS__
				tcsetattr( STDIN_FILENO, TCSANOW, &org_conf);
#endif
				delay(100);
				return 0;
			break;
		}
		
		if ((in_c == 's') && (in_c == 'S'))
		nw_sleep_ms(100);
	}
	
  	return 0;
}



 /*****************************************************************************
 *
 *   Function Name: get_options(int argc, char *argv[])
 *
 *   Description:   parse command line options
 *
 *   Parameters:    arc , argv
 *
 *   Return value:  void
 *
 ******************************************************************************/
bool get_options(int argc, char *argv[])
{
    int c;
    int i;
    char buffer[3];
	int	curr_data=0;

    /* set default options */
	options.rx_msg_grp = 0;
    options.message_group = 1;
    options.event = 2;
    options.data_len = 4;
	options.data[0]=4;
	options.data[1]=3;
	options.data[2]=2;
	options.data[3]=1;

    while ((c = getopt(argc, argv, "?hg:e:d:")) != -1)
    {
        switch (c)
        {
            case 'h':
			case '?':
                usage();
                return false;
            break;

            case 'g':
                options.message_group = atoi(optarg);
            break;

            case 'e':
                options.event = atoi(optarg);
            break;
            
            case 'd':
				if (curr_data < sizeof(options.data))
				{
					options.data[curr_data++] = atoi(optarg);
					options.data_len = curr_data;
				}
            break;

            default :
                /* unknown option */
                fprintf(stderr, "%c is an unknown option\n", c);
                usage();
                return false;
        }
    }
    return true;
}


/*****************************************************************************
 *
 *   Function Name: usage()
 *
 *   Description:   print usage message to console (stderr)
 *
 *   Parameters:
 *
 *   Return value:  void
 *
 ******************************************************************************/
void usage(void)
{
    printf("\n\n");
    printf("***************************************************************\n");
    printf("** vmf sender and receiver process                              \n");
    printf("***************************************************************\n");
    printf("**                                                             \n");
    printf("** usage: vmf_transceiver [options]                            \n");
    printf("**     -h     this help                                        \n");
    printf("**     -g     message group  [default = 1]                     \n");
    printf("**     -e     event          [default = 2]                     \n");
    printf("**     -d     data 			 [default data: 4,3,2,1] 		   \n");
    printf("** example:                                                    \n");
    printf("** ./vmf_transceiver -e1 -g2 -d1 -d2 -d3 -d4                   \n");
    printf("***************************************************************\n");
    printf("\n\n");
}



/**************************************************************************//**
 *
 *   Function Name: vmf_transceiver_create_thread
 *
 *   Description:   create the VMF receiver thread
 *
 *
 *   Parameters:    void
 *
 *   Function Return value: return True if OK or False.
 *
 ******************************************************************************/
bool vmf_transceiver_create_thread(void)
{
    pthread_t th;
    pthread_attr_t  attr;
    struct sched_param param;
    int iRet;

	VMF_INFO2_PRINT("vmf_transceiver_create_thread");
	
    /* set thread stack */
    pthread_attr_init( &attr );

    /* set the attributes of the thread */
    (void)pthread_attr_setschedpolicy (&attr, SCHED_RR);
    param.sched_priority = 10;

    #ifndef __ANDROID__
    iRet = pthread_attr_setstacksize  (&attr, 32*1024);
    if (EOK != iRet)
    {
        VMF_ERROR_PRINT("vmf_transceiver_create_thread: pthread_attr_setstacksize() failed");
    }
    #endif

    (void)pthread_attr_setschedparam (&attr, &param );
    (void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );

    iRet = pthread_create (&th  ,&attr, vmf_trace_dlt_gw_thread, NULL);
    (void)pthread_attr_destroy(&attr);
    if (iRet)
    {
        VMF_ERROR_PRINT("vmf_transceiver_create_thread: vmf_spy_create_thread() error errno = %d",iRet);
        return false;
    }

    /* set thread name for QNX */    
    #if (_NTO_VERSION >= 632)
    /* name the thread nw vmf-spy thread */
    if ( pthread_setname_np(th, DLT_GW_NAME) != EOK)
    {
        VMF_ERROR_PRINT("vmf_transceiver_create_thread: Unable to name nw vmf-spy thread!");
    }
    #endif
 
    return true;

}



/**************************************************************************//**
 *
 *   Function Name: vmf_trace_dlt_gw_thread(void *not_used)
 *
 *   Description:   VMF receiver thread
 *
 *   Parameters:    unused
 *
 *   Function Return value: - void *
 *
 ******************************************************************************/
static void *vmf_trace_dlt_gw_thread(void *pArg)
{
	unsigned8	groups[]={options.message_group,options.message_group+1};	// <= we will receive our own messages 
	vmf_ret_t	ret_val=VMF_ERROR;
	
	/* wait for VMF connection */
	VMF_INFO2_PRINT("vmf_trace_dlt_gw_task started");
	while (0 == vmf_connection_handle)
	{
		nw_sleep_ms(100);
	}
	VMF_INFO2_PRINT("vmf_trace_dlt_gw_task VMF connected");

	/* register to message group */
	ret_val = nw_vmf_register_msg_group(vmf_connection_handle, sizeof(groups), groups);
	if (ret_val != VMF_OK)
	{
		VMF_ERROR_PRINT("vmf_trace_dlt_gw_task nw_vmf_register_msg_group failed");
		return NULL;
	}
	
	/* wait for a VMF message */
	while(true)
	{
		vmf_msg_t vmf_msg;
		ret_val = nw_vmf_receive(vmf_connection_handle,&vmf_msg,sizeof(vmf_msg));
		if (ret_val > 0)
		{
			unsigned8 	event=0;
			unsigned8 	group=0;
			int 		data_len=0;
			unsigned8*	p_data=NULL;
			int 		num;
				
			/* this shows how to get the data */
			if (MSG_TYPE_BASIC_MESSAGE == NW_VMF_MSG_TYPE(&vmf_msg))
			{
				event 	 = NW_VMF_MSG_EVENT(&vmf_msg);
				group 	 = NW_VMF_MSG_GROUP(&vmf_msg);
				data_len = NW_VMF_MSG_DATA_LENGTH(&vmf_msg);
				p_data	 = NW_VMF_MSG_DATA_PTR(&vmf_msg);
				
				fprintf(ERROR_CHANNEL," received vmf-message: group=%d, event=%d - ",group,event);
				for (num=0; num<data_len; num++)
				{
					fprintf(ERROR_CHANNEL,"data[%d]=0x%02x ",num,p_data[num]);
				}
				fprintf(ERROR_CHANNEL,"\n");
			}
			else
			{
				/* ignore other message types */
			}
		}
		else
		{
			/* we received an ivalid message - wait some time and try again */
			nw_sleep_ms(1);
		}
	}	
	
    return NULL;
}





