/*
 Echo basic messages from VMF
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
    bool        print_message;
}options_t;


/* global data */
vmf_client_id_t     vmf_connection_handle=-1;
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
    printf("echo_basic_message: options\n");
    printf("    message_group_count = %d\n", options.message_group_count);
    printf("    message_groups      = ");
    for (i=0;i<options.message_group_count;i++)
    {
        printf("%d ", options.message_group[i]);
    }
    printf("\n\n");

    while (vmf_connection_handle <= 0)
    {
        vmf_connection_handle = nw_vmf_connect( "Echo", 0, 0, VMF_CLIENT_QUEUE_SIZE_STANDARD, VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD);
        if (vmf_connection_handle <= 0)
        {
            printf("echo_basic_message: connect failed --error %d\n",(int)vmf_connection_handle);
            delay(50);
        }
    }
    printf("echo_basic_message: connected to vmf (cid == %d)\n", vmf_connection_handle);

    vmf_result = nw_vmf_register_msg_group (vmf_connection_handle, options.message_group_count, options.message_group);
    if (vmf_result < 0)
    {
        printf("echo_basic_message: Can not register msg-groups - error=%d\n",vmf_result);
        return -1;
    }

    while (1)
    {
        vmf_result = nw_vmf_receive(vmf_connection_handle, pmsg, sizeof(msg));
        if(vmf_result < 0)
        {
            printf("\necho_basic_message: receive message failed -- VMF error %d\n", (int)vmf_result);
        }
        else if (0 == vmf_result)
        {
            /* do nothing! */
        }
        else
        {

            if (255 == msg.vmf_basic_msg.msg_base.id.event)
            {
                break;
            }

            if (true == options.print_message)
            {
                printf("\necho_basic_message: MESSAGE RECEIVED\n");
                printf("            MsgGroup: %d\n", pmsg->vmf_basic_msg.msg_base.id.group);
                printf("            MsgID   : %d\n", pmsg->vmf_basic_msg.msg_base.id.event);
                printf("            Data 0  : %d\n", pmsg->vmf_basic_msg.data.pl[0]);
                printf("            Data 1  : %d\n", pmsg->vmf_basic_msg.data.pl[1]);
                printf("            Data 2  : %d\n", pmsg->vmf_basic_msg.data.pl[2]);
                printf("            Data 3  : %d\n", pmsg->vmf_basic_msg.data.pl[3]);
            }

            /* increment msg group to avoid back-firing */
            msg.vmf_basic_msg.msg_base.id.group++;
            nw_vmf_send_basic(vmf_connection_handle, (vmf_basic_msg_t *)pmsg);
        }
    }

    nw_vmf_de_register_msg_group(vmf_connection_handle, options.message_group_count, options.message_group);
    nw_vmf_disconnect(vmf_connection_handle);

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
        fprintf(stderr, "echo_basic_message: no parameters -- nothing done! \n");
        usage();
        return false;
    }

    /* initialize options */
    options.message_group_count = 0;
    options.print_message = false;

    while ((c = getopt(argc, argv, "hpg:")) != -1)
    {
        switch (c)
        {
            case 'h':
                usage();
                return false;
            break;

            case 'p':
                options.print_message = true;
            break;

            case 'g':
                options.message_group[options.message_group_count] = atoi(optarg);
                options.message_group_count++;
            break;

            default :
                /* unknown option */
                fprintf(stderr, "echo_basic_message: %c is an unknown option\n", c);
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
    printf("** echo_basic_message process                                  \n");
    printf("***************************************************************\n");
    printf("**                                                             \n");
    printf("** usage: echo_basic_message [options]                         \n");
    printf("**     -h     this help                                        \n");
    printf("**     -p     print received message                           \n");
    printf("**     -g     message group to receive                         \n");
    printf("**                                                             \n");
    printf("***************************************************************\n");
    printf("\n\n");
}



