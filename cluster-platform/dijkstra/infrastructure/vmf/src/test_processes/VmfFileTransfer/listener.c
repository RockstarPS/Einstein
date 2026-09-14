/*

 11.11.2015

 Lightweight File Transfer via VMF
 by J. Merkle

*/


#include <stdio.h>

#include "nw_os_config.h"
#include "nw_vmf.h"
#include "nw_vmf_trace.h"


/* defs and typedefs */
#define MAX_FAR_DATA_LEN        4062
#define MAX_FILE_NAME_SIZE      200


#define VMF_TRID_NAME           "VMF File Transfer"
#define VMF_TRACE_TASK          "Main"


#ifdef VMF_TRACE
    #define VMF_TRACE_ERROR(scope, args...) VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR, VMF_TRACE_TASK, scope, args); \
                                            printf("vmf_file_transfer: ERROR "); printf(scope), printf(" -- "); printf(args); printf("\n"); fflush(stdout);
                                            
    #define VMF_TRACE_INFO(args...)         VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_13, VMF_TRACE_TASK, "Info", args); \
                                            /*printf("vmf_file_transfer: "); printf(args); printf("\n"); fflush(stdout)*/;
                                            
#else
    #define VMF_TRACE_ERROR(scope, args...) printf("vmf_file_transfer: ERROR "); printf(scope), printf(" -- "); printf(args); printf("\n");
    #define VMF_TRACE_INFO(args...)         printf("vmf_file_transfer: "); printf(args); printf("\n");
#endif


typedef struct
{
    unsigned8   message_group;              /* VMF message group for all following events */
    unsigned8   start_event;                /* VMF event to initiate file transfer, contains file name */
    unsigned8   data_event;                 /* VMF event for data transfer */ 
    unsigned8   finished_event;             /* VMF event if finished or stop current transfer (close the file) */
    unsigned8   ack_event;                  /* VMF event to acknowledged receive events */
}options_t;


/* global data */
options_t           options;
unsigned8           vmf_trid;

/* function prototypes */
bool get_options(int argc, char *argv[]);
void usage(void);
vmf_ret_t process_file_transfer_events (vmf_basic_msg_t * vmf_basic_msg);
vmf_ret_t send_acknowledge_message(vmf_ret_t status);

VMF_VAR_MSG_TYP(MAX_FAR_DATA_LEN)   my_msg;
pid_t               pid;
vmf_client_id_t     my_rx_id;
vmf_ret_t           my_ret;
unsigned16          my_len;
char                myName[31];

char                file_name[MAX_FILE_NAME_SIZE] = {0};
FILE                *file_handle = NULL;

/*****************************************************************************
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
    VMF_TRACE_ERROR("usage", "** vmf_file_transfer process                                 **");
    VMF_TRACE_ERROR("usage", "***************************************************************");
    VMF_TRACE_ERROR("usage", "**                                                           **");
    VMF_TRACE_ERROR("usage", "** usage: vmf_receive [options]                              **");
    VMF_TRACE_ERROR("usage", "**     -h     this help                                      **");
    VMF_TRACE_ERROR("usage", "**     -g     message group                                  **");
    VMF_TRACE_ERROR("usage", "**     -s     start event                                    **");
    VMF_TRACE_ERROR("usage", "**     -d     data event                                     **");
    VMF_TRACE_ERROR("usage", "**     -f     finished event (or break)                      **");
    VMF_TRACE_ERROR("usage", "**     -a     ack event                                      **");
    VMF_TRACE_ERROR("usage", "**                                                           **");
    VMF_TRACE_ERROR("usage", "***************************************************************");
    VMF_TRACE_ERROR("usage", "** example:                                                  **");
    VMF_TRACE_ERROR("usage", "**     vmf_file_transfer -g 01 -s 9 -d 10 -a 11              **");
    VMF_TRACE_ERROR("usage", "***************************************************************");
}



/*****************************************************************************
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
    sprintf(myName,"VMF File Transfer");
    my_rx_id = nw_vmf_connect(myName, NULL, 0, 100, sizeof(my_msg));
    if (my_rx_id < 0)
    {
        VMF_TRACE_ERROR("vmf_file_transfer", "nw_vmf_connect() failed - error==%d",my_rx_id);
        return;
    }

    /* Register for VMF Tracer */
    if (VMF_TRACE_REGISTER(&vmf_trid, VMF_TRID_NAME) < 0)
    {
        fprintf(stderr, "vmf_file_transfer: CANNOT CONNECT TO VMF TRACER!!!\n");
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

    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_10, VMF_TRACE_TASK, "main", "VMF File Transfer startet. PID==%d", getpid());
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_10, VMF_TRACE_TASK, "main", "Options:");
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_10, VMF_TRACE_TASK, "main", "   message group   = %d", options.message_group);
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_10, VMF_TRACE_TASK, "main", "   start event     = %d", options.start_event);
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_10, VMF_TRACE_TASK, "main", "   data event      = %d", options.data_event);
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_10, VMF_TRACE_TASK, "main", "   finished event  = %d", options.finished_event);
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_10, VMF_TRACE_TASK, "main", "   ack event       = %d", options.ack_event);

    /* register message group */
    my_ret = nw_vmf_register_msg_group (my_rx_id, 1, (unsigned8 *) &(options.message_group));
    if (my_ret < 0)
    {
        VMF_TRACE_ERROR("vmf_file_transfer", "nw_vmf_register_msg_group() failed - error=%d\n",my_ret);
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
                        
                        if (options.message_group == my_msg.vmf_basic_msg.msg_base.id.group)
                        {
                            if (process_file_transfer_events( (vmf_basic_msg_t*) &my_msg.vmf_basic_msg) != VMF_OK)
                            {
                                VMF_TRACE_ERROR("vmf_file_transfer", "process file transfer message failed! \n");
                            }
                        }

                break;

                default:
                    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TRACE_TASK, "vmf_file_transfer", "Invalid message received! Data:");
                    VMF_TRACE_HEX(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TRACE_TASK, "vmf_file_transfer", 100, (unsigned8 *)&my_msg);
                break;
            }
        }
        else
        {
            VMF_TRACE_ERROR("vmf_file_transfer", "receive message failed -- ret_val == \n", my_len);
        }
    }

    return 0;
}



 /*****************************************************************************
 *
 *   Description:   process file transfer events
 *
 *   Parameters:    pointer to vmf basic msg
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
vmf_ret_t process_file_transfer_events (vmf_basic_msg_t * vmf_basic_msg)
{
    vmf_ret_t  vmf_ret = VMF_OK;
    vmf_ret_t  ack_ret;
    unsigned8  vmf_event = 0;
    unsigned16 my_length = 0;
    
    
    if (NULL == vmf_basic_msg)
    {
        return VMF_ERR_NULL_POINTER;
    }

    vmf_event = vmf_basic_msg->msg_base.id.event;

    if (vmf_event == options.start_event)
    {
        if (vmf_basic_msg->data.length > 0 && vmf_basic_msg->data.length < MAX_FILE_NAME_SIZE)
        {
            NW_MEMCOPY(file_name, vmf_basic_msg->data.pl, vmf_basic_msg->data.length);
            file_name[vmf_basic_msg->data.length] = 0;   /* ensure zero termination of file name */
            VMF_TRACE_INFO("start event received -- file name == %s", file_name);

            file_handle = fopen(file_name, "wb");
            if (file_handle != NULL)
            {
                ack_ret = send_acknowledge_message(VMF_OK);
                if (ack_ret != VMF_OK)
                {
                    VMF_TRACE_ERROR("process_file_transfer_events", "sending ack failed \n");
                }
            }
            else
            {
                (void) send_acknowledge_message(VMF_ERROR);
                VMF_TRACE_ERROR("process_file_transfer_events", "fopen failed \n");
            }
        }
        else
        {
            VMF_TRACE_ERROR("process_file_transfer_events", "File name too long! Maximum length = %d \n", sizeof(file_name));
        }
       
    }
    else if (vmf_event == options.data_event)
    {
        if (file_handle != NULL)
        {
            my_length = vmf_basic_msg->data.length;
            if (my_length == fwrite(vmf_basic_msg->data.pl, 1, my_length, file_handle))
            {
                ack_ret = send_acknowledge_message(VMF_OK);
                if (ack_ret != VMF_OK)
                {
                    VMF_TRACE_ERROR("process_file_transfer_events", "sending ack failed \n");
                }
            }
            else
            {
                (void) send_acknowledge_message(VMF_ERROR);
                VMF_TRACE_ERROR("process_file_transfer_events", "write to file failed! \n");
            }
        }
        else
        {
            VMF_TRACE_ERROR("process_file_transfer_events", "file not opened before!!! \n");
        }
    }
    else if (vmf_event == options.finished_event)
    {
        if (file_handle != NULL)
        {
            (void) fclose(file_handle);
        }
    }
    else if (vmf_event == options.ack_event)
    {
        /* don't care - we sent it. */
    }
    else
    {
        VMF_TRACE_ERROR("process_file_transfer_events", "UNKNOWN EVENT! vmf_event = %d \n", vmf_event);
    }
    
    return vmf_ret;
}



 /*****************************************************************************
 *
 *   Description:   send acknowledge message
 *
 *   Parameters:    status (e.g. VMF_OK, VMF_ERROR, ...)
 *
 *   Return value:  vmf_ret_t
 *
 ******************************************************************************/
vmf_ret_t send_acknowledge_message(vmf_ret_t status)
{
    vmf_ret_t ret_val;
    static VMF_VAR_BASIC_MSG_TYP(10)  ack_msg;
    
    ack_msg.msg_base.id.group = options.message_group;
    ack_msg.msg_base.id.event = options.ack_event;
    
    ack_msg.data.length = 1;
    ack_msg.data.pl[0] = status;
    
    ret_val = nw_vmf_send_basic(my_rx_id, (vmf_basic_msg_t*)&ack_msg);
    
    return ret_val;
}





 /*****************************************************************************
 *
 *   Description:   parse command line options
 *
 *   Parameters:    arc , argv
 *
 *   Return value:  true / false
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
    options.message_group = 0;
    options.start_event = 0;
    options.data_event = 0;
    options.finished_event = 0;
    options.ack_event = 0;
    


    while ((c = getopt(argc, argv, "hg:s:d:f:a:")) != -1)
    {
        switch (c)
        {
            case 'h':
                usage();
                return false;
            break;

            case 'g':
                options.message_group = atoi(optarg);
            break;

            case 's':
                options.start_event = atoi(optarg);
            break;
            
            case 'd':
                options.data_event = atoi(optarg);
            break;

            case 'f':
                options.finished_event = atoi(optarg);
            break;
            
            case 'a':
                options.ack_event = atoi(optarg);
            break;

            default :
                /* unknown option */
                VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TRACE_TASK, "get_options","%c is an unknown option!", c);
                usage();
                return false;
        }
    }


    if (0 == options.message_group)
    {
        VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TRACE_TASK, "get_options","Message group shouldn't be zero!", c);
        usage();
        return false;
    }

    if (0 == options.start_event)
    {
        VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TRACE_TASK, "get_options","Start event shouldn't be zero!", c);
        usage();
        return false;
    }

    if (0 == options.data_event)
    {
        VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TRACE_TASK, "get_options","Data event shouldn't be zero!", c);
        usage();
        return false;
    }

    if (0 == options.finished_event)
    {
        VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TRACE_TASK, "get_options","Finished event shouldn't be zero!", c);
        usage();
        return false;
    }

    if (0 == options.ack_event)
    {
        VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TRACE_TASK, "get_options","Ack event shouldn't be zero!", c);
        usage();
        return false;
    }

    return true;
}




