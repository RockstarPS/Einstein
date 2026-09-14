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



//#define PRINT_OPTIONS_ONLY


/* defs and typedefs */
#define MAX_FAR_DATA_LEN    50

typedef struct
{
    unsigned8   message_group;
    unsigned8   event;
    unsigned8   near_data[4];
    unsigned8   far_data_len;
    unsigned8   far_data[MAX_FAR_DATA_LEN];
}options_t;


/* global data */
vmf_client_id_t     vmf_connection_handle;
unsigned8           vmf_trace_trid=0;
options_t           options;


/* function prototypes */
bool get_options(int argc, char *argv[]);
void usage(void);


#define ERROR_CHANNEL   stderr
#define VMF_ERROR_PRINT(args...)   {fprintf(ERROR_CHANNEL,"Error:  ");fprintf(ERROR_CHANNEL,args);fprintf(ERROR_CHANNEL,"\n");}



int main (int argc, char *argv[])
{

    vmf_ret_t   vmf_result;

    VMF_VAR_BASIC_MSG_TYP(10) msg;
    vmf_basic_msg_t *pmsg = (vmf_basic_msg_t *)&msg;


    if (false == get_options(argc,argv))
    {
        return -1;
    }


    printf("\n\n");
    printf("send_basic_message: options\n");
    printf("    message_group = %d\n", options.message_group);
    printf("    event         = %d\n", options.event);
    printf("    near data     = %d %d %d %d\n", options.near_data[0], options.near_data[1], options.near_data[2], options.near_data[3]);
    printf("    far data len  = %d\n", options.far_data_len);
    printf("    far data      = %d %d %d %d %d ...\n", options.far_data[0], options.far_data[1], options.far_data[2], options.far_data[3], options.far_data[4]);
    printf("\n\n");

#ifdef PRINT_OPTIONS_ONLY
    return 0;
#endif

    vmf_connection_handle = nw_vmf_connect( "send_event", 0, 0, VMF_CLIENT_QUEUE_SIZE_STANDARD, VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD);
    if (vmf_connection_handle < 0)
    {
        printf("send_basic_message: connect failed --error %d\n",(int)vmf_connection_handle);
        return -1;
    }

    if (options.far_data_len > MAX_FAR_DATA_LEN)
    {
        printf("send_basic_message: far data len too big (-l) \n");
        return -1;
    }

    VMF_BASIC_MSG_GROUP_ID(pmsg)    = options.message_group;
    VMF_BASIC_MSG_EVENT_ID(pmsg)    = options.event;
    VMF_BASIC_MSG_NEAR_DATA_0(pmsg) = options.near_data[0];
    VMF_BASIC_MSG_NEAR_DATA_1(pmsg) = options.near_data[1];
    VMF_BASIC_MSG_NEAR_DATA_2(pmsg) = options.near_data[2];
    VMF_BASIC_MSG_NEAR_DATA_3(pmsg) = options.near_data[3];

    if (options.far_data_len > 0)
    {
        VMF_BASIC_MSG_SET_FAR_DATA_LENGTH(pmsg,options.far_data_len);
        memcpy(VMF_BASIC_MSG_PTR_TO_FAR_DATA(pmsg),(void *)options.far_data, options.far_data_len);
    }
    else
    {
        VMF_BASIC_MSG_SET_FAR_DATA_LENGTH(pmsg,0);
    }




    vmf_result = nw_vmf_send_basic (vmf_connection_handle,(vmf_basic_msg_t*)pmsg);
    if(VMF_OK != vmf_result)
    {
        printf("send_basic_message: send vmf basic message failed -- VMF error %d\n", (int)vmf_result);
    }
    else
    {
        printf("send_basic_message: send vmf basic message ok\n");
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
        fprintf(stderr, "send_basic_message: no parameters -- nothing done! \n");
        usage();
        return false;
    }

    /* initialize options */
    options.message_group = 0;
    options.event = 0;
    options.far_data_len = 0;


    while ((c = getopt(argc, argv, "hg:e:n:l:f:")) != -1)
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

            case 'e':
                options.event = atoi(optarg);
            break;
            
            case 'n':
                snprintf(buffer, 3, "%s", &optarg[0]);
                options.near_data[0] = atoi(buffer);

                snprintf(buffer, 3, "%s", &optarg[2]);
                options.near_data[1] = atoi(buffer);

                snprintf(buffer, 3, "%s", &optarg[4]);
                options.near_data[2] = atoi(buffer);

                snprintf(buffer, 3, "%s", &optarg[6]);
                options.near_data[3] = atoi(buffer);
            break;
            
            case 'l':
                options.far_data_len = atoi(optarg);
            break;
            
            case 'f':
                for (i=0; i<options.far_data_len; i++)
                {
                    snprintf(buffer, 3, "%s", &optarg[2*i]);
                    options.far_data[i] = atoi(buffer);
                }
            break;

            default :
                /* unknown option */
                fprintf(stderr, "send_basic_message: %c is an unknown option\n", c);
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
    printf("** send_basic_message process                                  \n");
    printf("***************************************************************\n");
    printf("**                                                             \n");
    printf("** usage: send_basic_message [options]                         \n");
    printf("**     -h     this help                                        \n");
    printf("**     -g     message group                                    \n");
    printf("**     -e     event                                            \n");
    printf("**     -n     near data, always 4byte, NO spaces               \n");
    printf("**     -l     length of far data                               \n");
    printf("**     -n     far data, requires option -l, NO spaces          \n");
    printf("**                                                             \n");
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

    /* before starting the gw-thread try to load the dlt shared lib */

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

    iRet = pthread_create (&th  ,&attr, vmf_receiver, NULL);
    (void)pthread_attr_destroy(&attr);
    if (iRet)
    {
        VMF_TRACE_GW_ERROR_PRINT("vmf_transceiver_create_thread: vmf_spy_create_thread() error errno = %d",iRet);
        return false;
    }

    /* set thread name for QNX */   
    #ifdef QNX
    #if (_NTO_VERSION >= 632)
    /* name the thread nw vmf-spy thread */
    if ( pthread_setname_np(th, DLT_GW_NAME) != EOK)
    {
        VMF_ERROR_PRINT("vmf_transceiver_create_thread: Unable to name nw vmf-spy thread!");
    }
    #endif
    #endif
 
    return true;

}



/**************************************************************************//**
 *
 *   Function Name: vmf_trace_dlt_gw_task(void *not_used)
 *
 *   Description:   VMF receiver thread
 *
 *   Parameters:    unused
 *
 *   Function Return value: - void *
 *
 ******************************************************************************/
static void *vmf_trace_dlt_gw_task(void *pArg)
{
    return NULL;
}

