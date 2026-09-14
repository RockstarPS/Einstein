/*

 Testprocess used for GCOV testing.
 by J. Merkle

*/

#include "nw_os_config.h"
#include "nw_vmf.h"
#include "nw_vmf_trace.h"

/* defs and typedefs */
#define MAX_DATA_LEN            4062

#define VMF_TRID_NAME           "VMF GCOV"
#define VMF_TRACE_TASK          "gcov"

#ifdef VMF_TRACE
    #define VMF_TRACE_ERROR(scope, args...) VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR, VMF_TRACE_TASK, scope, args);
    #define VMF_TRACE_INFO(args...)        VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_13, VMF_TRACE_TASK, "Wow!", args);
#else
    #define VMF_TRACE_ERROR(scope, args...) printf("vmf_gcov ERROR "); printf(scope), printf(" -- "); printf(args); printf("\n");
    #define VMF_TRACE_INFO(args...)        printf("vmf_gcov: "); printf(args); printf("\n");
#endif

typedef struct
{
    unsigned8   message_group;
}options_t;


/* global data */
options_t                       options;
vmf_client_id_t                 vmf_cid;
unsigned8                       vmf_trid;
VMF_VAR_MSG_TYP(MAX_DATA_LEN)   rx_msg;
VMF_VAR_BASIC_MSG_TYP(0)        tx_basic_msg;
vmf_basic_msg_t                 *p_tx_basic_msg = (vmf_basic_msg_t *)&tx_basic_msg;
unsigned8                       i;

/* function prototypes */
bool get_options(int argc, char *argv[]);
bool send_control_message(unsigned8 control_event);
void usage(void);


int main (int argc, char *argv[])
{
    vmf_ret_t   vmf_result;
    vmf_ret_t   my_ret;
    char        connection_name[31];
    
    if (false == get_options(argc,argv))
    {
        return -1;
    }

    /* connect VMF */
    sprintf(connection_name,"VMF-GCOV");
    vmf_cid = nw_vmf_connect(connection_name, NULL, 0, 10, sizeof(rx_msg));
    if (vmf_cid < 0)
    {
        fprintf(stderr, "vmf_gcov: vmf connect failed!!!\n");
    }

    /* register message group */
    my_ret = nw_vmf_register_msg_group (vmf_cid, 1, &options.message_group);
    if (my_ret < 0)
    {
        fprintf(stderr, "vmf_gcov: register msg groups failed!!!\n");
    }
    
    /* register as spy */
    my_ret = nw_vmf_register_spy(vmf_cid);
    if (my_ret < 0)
    {
        fprintf(stderr, "vmf_gcov: register spy failed!!!\n");
    }

    /* Register for VMF Tracer */
    if (VMF_TRACE_REGISTER(&vmf_trid, VMF_TRID_NAME) < 0)
    {
        fprintf(stderr, "vmf_gcov: CANNOT CONNECT TO VMF TRACER!!!\n");
    }
    
    /* Set my own severity */
    VMF_TRACE_SET_SEVERITY(vmf_trid, 100);


    /* Enable Tracer */
    if (false == send_control_message(VMF_TRACE_CTRL_FILTER_REQ))
    {
        fprintf(stderr, "vmf_gcov: send filter request failed!");
    }
    if (false == send_control_message(VMF_TRACE_CTRL_PERSISTENT))
    {
        fprintf(stderr, "vmf_gcov: send save persistent failed!");
    }
    if (false == send_control_message(VMF_TRACE_CTRL_CONNECTION_NAMES))
    {
        fprintf(stderr, "vmf_gcov: send request connection names failed!");
    }

    /* TODO: Add more control messages... */
    
    

    /* Receiving 5 messages is enough for the coverage test */
    for (i=0; i<5; i++)
    {
        my_ret = nw_vmf_receive (vmf_cid, (vmf_msg_t*)&rx_msg, sizeof(rx_msg));

        if (my_ret == 0)
        {
            VMF_TRACE_ERROR("vmf_receiver", "receive message failed -- length==0\n");
        }
        else
        {
            VMF_TRACE_INFO("message received");
        }
    }

    nw_vmf_de_register_msg_group(vmf_cid, 1, &options.message_group);
    nw_vmf_disconnect(vmf_cid);

    VMF_TRACE_INFO("FINISHED!!!");

    return 0;
}


bool send_control_message(unsigned8 control_event)
{
    bool        ret_val = true;
    vmf_ret_t   vmf_result;
    
    NW_VMF_BASIC_MSG_GROUP(p_tx_basic_msg) = VMF_TRACE_CTRL;
    NW_VMF_BASIC_MSG_EVENT(p_tx_basic_msg) = control_event;
    NW_VMF_BASIC_MSG_DATA_LENGTH(p_tx_basic_msg) = 0;

    vmf_result = nw_vmf_send_basic (vmf_cid,(vmf_basic_msg_t*)p_tx_basic_msg);
    if(VMF_OK != vmf_result)
    {
        ret_val = false;
    }

    return ret_val;
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
    options.message_group = 0;


    while ((c = getopt(argc, argv, "hi:g:c:st")) != -1)
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


            default :
                /* unknown option */
                VMF_TRACE_INFO("%c is an unknown option!", c);
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
    VMF_TRACE_ERROR("usage", "***************************************************************");
    VMF_TRACE_ERROR("usage", "** vmf_listener process                                      **");
    VMF_TRACE_ERROR("usage", "***************************************************************");
    VMF_TRACE_ERROR("usage", "**                                                           **");
    VMF_TRACE_ERROR("usage", "** usage: vmf_listener [options]                             **");
    VMF_TRACE_ERROR("usage", "**     -h     this help                                      **");
    VMF_TRACE_ERROR("usage", "**     -g     message group                                  **");
    VMF_TRACE_ERROR("usage", "**                                                           **");
    VMF_TRACE_ERROR("usage", "***************************************************************");
}


