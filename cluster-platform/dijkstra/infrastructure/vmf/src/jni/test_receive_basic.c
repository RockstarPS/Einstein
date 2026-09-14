/*
 Receive basic messages from VMF
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


/* defs and typedefs */
#define MAX_FAR_DATA_LEN    50
#define MAX_MSG_GROUPS      255

typedef struct
{
    unsigned8   message_group[MAX_MSG_GROUPS];
    unsigned8   message_group_count;
    unsigned16  receive_timeout_ms;
}options_t;


/* global data */
vmf_client_id_t     vmf_connection_handle;
options_t           options;


/* function prototypes */
bool get_options(int argc, char *argv[]);
void usage(void);


int main (int argc, char *argv[])
{
    vmf_ret_t   vmf_result;
    unsigned8   i;

    VMF_VAR_MSG_TYP(10) msg;
    vmf_msg_t *pmsg = (vmf_msg_t *)&msg;

    if (false == get_options(argc,argv))
    {
        return -1;
    }

    printf("\n\n");
    printf("receive_basic_message: options\n");
    printf("    message_group_count = %d\n", options.message_group_count);
    printf("    message_groups      = ");
    for (i=0;i<options.message_group_count;i++)
    {
        printf("%d ", options.message_group[i]);
    }
    printf("\n");
    printf("    receive_timeout_ms  = %d\n", options.receive_timeout_ms);
    printf("\n\n");

    vmf_connection_handle = nw_vmf_connect( "Receiver", 0, 0, VMF_CLIENT_QUEUE_SIZE_STANDARD, VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD);
    if (vmf_connection_handle < 0)
    {
        printf("receive_basic_message: connect failed --error %d\n",(int)vmf_connection_handle);
        return -1;
    }

    vmf_result = nw_vmf_register_msg_group (vmf_connection_handle, options.message_group_count, options.message_group);
    if (vmf_result < 0)
    {
        printf("receive_basic_message: Can not register msg-groups - error=%d\n",vmf_result);
        return -1;
    }

    while (1)
    {
        if (options.receive_timeout_ms > 0)
        {
            vmf_result = nw_vmf_timed_receive(vmf_connection_handle, pmsg, sizeof(msg), options.receive_timeout_ms);
        }
        else
        {
            vmf_result = nw_vmf_receive(vmf_connection_handle, pmsg, sizeof(msg));
        }

        if(vmf_result < 0)
        {
            printf("\nreceive_basic_message: receive message failed -- VMF error %d\n", (int)vmf_result);
        }
        else if (0 == vmf_result)
        {
            printf(".");
        }
        else
        {
            printf("\nreceive_basic_message: MESSAGE RECEIVED\n");
            printf("            MsgGroup: %d\n", pmsg->vmf_basic_msg.msg_base.id.group);
            printf("            MsgID   : %d\n", pmsg->vmf_basic_msg.msg_base.id.event);
            printf("            Data 0  : %d\n", pmsg->vmf_basic_msg.data.pl[0]);
            printf("            Data 1  : %d\n", pmsg->vmf_basic_msg.data.pl[1]);
            printf("            Data 2  : %d\n", pmsg->vmf_basic_msg.data.pl[2]);
            printf("            Data 3  : %d\n", pmsg->vmf_basic_msg.data.pl[3]);
        }
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

    if (1==argc)
    {
        /* call without any argument */
        fprintf(stderr, "receive_basic_message: no parameters -- nothing done! \n");
        usage();
        return false;
    }

    /* initialize options */
    options.message_group_count = 0;
    options.receive_timeout_ms = 0;


    while ((c = getopt(argc, argv, "hg:t:")) != -1)
    {
        switch (c)
        {
            case 'h':
                usage();
                return false;
            break;

            case 'g':
                options.message_group[options.message_group_count] = atoi(optarg);
                options.message_group_count++;
                
            break;
            
            case 't':
                options.receive_timeout_ms = atoi(optarg);
            break;

            default :
                /* unknown option */
                fprintf(stderr, "receive_basic_message: %c is an unknown option\n", c);
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
    printf("** receive_basic_message process                                  \n");
    printf("***************************************************************\n");
    printf("**                                                             \n");
    printf("** usage: receive_basic_message [options]                      \n");
    printf("**     -h     this help                                        \n");
    printf("**     -g     message group                                    \n");
    printf("**     -t     receive timeout [ms]                             \n");
    printf("**                                                             \n");
    printf("***************************************************************\n");
    printf("\n\n");
}



