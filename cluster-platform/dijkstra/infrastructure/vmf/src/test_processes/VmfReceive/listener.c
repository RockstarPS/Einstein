/*

 09.12.2010

 Receive basic messages thru VMF
 by J. Merkle

*/


#include "nw_os_config.h"
#include "nw_vmf.h"
#include "nw_vmf_trace.h"


/* defs and typedefs */
#define MAX_FAR_DATA_LEN        4062


#define VMF_TRID_NAME           "VMF Receive"
#define VMF_TRACE_TASK          "Main"


#ifdef VMF_TRACE
    #define VMF_TRACE_ERROR(scope, args...) VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR, VMF_TRACE_TASK, scope, args); \
                                            printf("vmf_receiver: ERROR "); printf(scope), printf(" -- "); printf(args); printf("\n"); fflush(stdout);
                                            
    #define VMF_TRACE_INFO(args...)         VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_13, VMF_TRACE_TASK, "Info", args); \
                                            printf("vmf_receiver: "); printf(args); printf("\n"); fflush(stdout);
                                            
#else
    #define VMF_TRACE_ERROR(scope, args...) printf("vmf_receiver: ERROR "); printf(scope), printf(" -- "); printf(args); printf("\n");
    #define VMF_TRACE_INFO(args...)         printf("vmf_receiver: "); printf(args); printf("\n");
#endif


typedef struct
{
    unsigned8   message_groups[100];
    unsigned8   message_group_count;
}options_t;


/* global data */
options_t           options;
unsigned8           vmf_trid;

/* function prototypes */
bool get_options(int argc, char *argv[]);
void usage(void);


VMF_VAR_MSG_TYP(MAX_FAR_DATA_LEN)   my_msg;
pid_t               pid;
vmf_client_id_t     my_rx_id;
vmf_ret_t           my_ret;
unsigned16          my_len;
char                myName[31];



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
    VMF_TRACE_ERROR("usage", "***************************************************************");
    VMF_TRACE_ERROR("usage", "** vmf_listener process                                      **");
    VMF_TRACE_ERROR("usage", "***************************************************************");
    VMF_TRACE_ERROR("usage", "**                                                           **");
    VMF_TRACE_ERROR("usage", "** usage: vmf_receive [options]                              **");
    VMF_TRACE_ERROR("usage", "**     -h     this help                                      **");
    VMF_TRACE_ERROR("usage", "**     -g     message group (multiple times possible!)       **");
    VMF_TRACE_ERROR("usage", "**                                                           **");
    VMF_TRACE_ERROR("usage", "***************************************************************");
    VMF_TRACE_ERROR("usage", "** example:                                                  **");
    VMF_TRACE_ERROR("usage", "**     vmf_receive -g 01 -g 02 -g 03                         **");
    VMF_TRACE_ERROR("usage", "***************************************************************");
}



/*****************************************************************************
 *
 *   Function Name: main
 *
 *   Description:   Entry point.
 *
 *   Parameters:    Command line options as described above...
 *
 *   Return value:  0
 *
 ******************************************************************************/
int main (int argc, char *argv[])
{
    vmf_ret_t   vmf_result;
    unsigned8   i;


    /* connect VMF */
    sprintf(myName,"VMF Ping Listener");
    my_rx_id = nw_vmf_connect(myName, NULL, 0, 100, sizeof(my_msg));
    if (my_rx_id < 0)
    {
        VMF_TRACE_ERROR("vmf_receiver", "nw_vmf_connect() failed - error==%d",my_rx_id);
        return;
    }

    /* Register for VMF Tracer */
    if (VMF_TRACE_REGISTER(&vmf_trid, VMF_TRID_NAME) < 0)
    {
        fprintf(stderr, "vmf_listener: CANNOT CONNECT TO VMF TRACER!!!\n");
        fflush(stderr);
    }
    else
    {
        fprintf(stdout, "\n\n\nSET VMF TRACER SEVERITY FOR 'VMF Ping' to <=73 !!!\n\n\n");
        fflush(stdout);
    }

    if (false == get_options(argc,argv))
    {
        return -1;
    }

    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_10, VMF_TRACE_TASK, "main", "VMF Receive startet. PID==%d", getpid());
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_10, VMF_TRACE_TASK, "main", "Options:");
    
    for (i=0;i<options.message_group_count;i++)
    {
        VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_10, VMF_TRACE_TASK, "main", "   message group   = %d", options.message_groups[i]);
    }


    /* register message group */
    my_ret = nw_vmf_register_msg_group (my_rx_id, options.message_group_count, (unsigned8 *) &(options.message_groups));
    if (my_ret < 0)
    {
        VMF_TRACE_ERROR("vmf_receiver", "nw_vmf_register_msg_group() failed - error=%d\n",my_ret);
        return;
    }


    while (1)
    {
        my_len = nw_vmf_receive (my_rx_id, (vmf_msg_t*)&my_msg, sizeof(my_msg));
        if (my_len > 0)
        {
            switch (my_msg.vmf_basic_msg.msg_base.base.msg_type)
            {
                case MSG_TYPE_BASIC_MESSAGE:
                    VMF_TRACE_INFO("Basic message received: msg-group==%d msg-event==%d payload.len==%d"
                        ,my_msg.vmf_basic_msg.msg_base.id.group, my_msg.vmf_basic_msg.msg_base.id.event, my_msg.vmf_basic_msg.data.length);

                break;

                default:
                    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TRACE_TASK, "vmf_receiver", "Invalid message received! Data:");
                    VMF_TRACE_HEX(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TRACE_TASK, "vmf_receiver", 100, (unsigned8 *)&my_msg);
                break;
            }
        }
        else
        {
            VMF_TRACE_ERROR("vmf_receiver", "receive message failed -- ret_val == \n", my_len);
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
        VMF_TRACE_ERROR("get_options", "NO parameters -- nothing done!");
        usage();
        return false;
    }

    /* initialize options */
    options.message_group_count = 0;


    while ((c = getopt(argc, argv, "hi:g:c:st")) != -1)
    {
        switch (c)
        {
            case 'h':
                usage();
                return false;
            break;

            case 'g':
                options.message_groups[options.message_group_count] = atoi(optarg);
                options.message_group_count++;
            break;

            default :
                /* unknown option */
                VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TRACE_TASK, "get_options","%c is an unknown option!", c);
                usage();
                return false;
        }
    }
    return true;
}




