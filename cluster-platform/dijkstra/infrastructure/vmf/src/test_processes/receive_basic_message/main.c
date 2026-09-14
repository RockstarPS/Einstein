/*

 09.12.2010

 Receive basic messages thru VMF
 by J. Merkle

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <pthread.h>
#include <fcntl.h>
#include <time.h>

#include "types.h"
#include "nw_os_config.h"
#include "nw_vmf.h"

#include "nw_vmf_trace.h"


/* Enable output */
#define DEBUG_PRINT


/* defs and typedefs */
#define MAX_FAR_DATA_LEN    500
#define MAX_TEST_CNT        10000
#define VMF_TRID_NAME       "VMF test"
#define VMF_TASK_RECEIVER   "Receiver"


typedef struct
{
    unsigned8   message_group;
    unsigned16  message_count;
}options_t;


/* global data */
options_t           options;
unsigned8           vmf_trid;

/* function prototypes */
void vmf_receiver(unsigned8 my_message_group);
unsigned64 vmf_get_time_snapshot(void);
unsigned64 vmf_get_time_diff(unsigned64 start_time, unsigned64 stop_time);

bool get_options(int argc, char *argv[]);
void usage(void);



int main (int argc, char *argv[])
{
    vmf_ret_t   vmf_result;


    VMF_VAR_BASIC_MSG_TYP(10) msg;
    vmf_basic_msg_t *pmsg = (vmf_basic_msg_t *)&msg;


    if (false == get_options(argc,argv))
    {
        return -1;
    }




    /* Register for VMF Tracer */
    if (VMF_TRACE_REGISTER(&vmf_trid, VMF_TRID_NAME) < 0)
    {
        fprintf(stderr, "receive_basic_message: CANNOT CONNECT TO VMF TRACER!!!\n");
    }


    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO, VMF_TASK_RECEIVER, "main", "Options:");
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO, VMF_TASK_RECEIVER, "main", "   message group = %d", options.message_group);
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO, VMF_TASK_RECEIVER, "main", "   message count = %d", options.message_count);
/* jmerkle      printf("Options:\n"); */
/* jmerkle      printf("   message group = %d\n", options.message_group); */
/* jmerkle      printf("   message count = %d\n", options.message_count); */


    /* now receive message in forever */
    vmf_receiver(options.message_group);

    return 0;
}



/*****************************************************************************
 *
 *   Function Name: vmf_receiver(void)
 *
 *   Description:   start the vmf test receiver
 *
 *   Parameters:    void
 *
 *   Return :       void
 *
 ******************************************************************************/
void vmf_receiver(unsigned8 my_message_group)
{
    VMF_VAR_MSG_TYP(MAX_FAR_DATA_LEN)   my_msg;
    unsigned64          tx_time;
    unsigned64          rx_time;
    unsigned64          rx_tx_time_diff;
    unsigned32          my_trans_time[MAX_TEST_CNT];
    pid_t               pid;
    vmf_client_id_t     my_rx_id;
    vmf_ret_t           my_ret;
    unsigned16          my_len;
    unsigned16          test_cnt;
    char                myName[31];


    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO, VMF_TASK_RECEIVER, "vmf_receiver", "Start test-receiver.");
/* jmerkle      printf("Start test-receiver.\n"); */

    /* connect VMF */
    sprintf(myName,"receive_basic_message--%d",getpid());
    my_rx_id = nw_vmf_connect(myName, NULL, 0, 30, (MAX_FAR_DATA_LEN+50));
    if (my_rx_id < 0)
    {
        fprintf(stderr, "receive_basic_message: nw_vmf_connect() failed - error==%d",my_rx_id);
        return;
    }

    /* register message group */
    my_ret = nw_vmf_register_msg_group (my_rx_id, 1, &my_message_group);
    if (my_ret < 0)
    {
        VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR, VMF_TASK_RECEIVER, "vmf_receiver", "receive_basic_message: nw_vmf_register_msg_group() failed - error=%d\n",my_ret);
        return;
    }

    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO, VMF_TASK_RECEIVER, "vmf_receiver", "Test-receiver connected - start reception.");


    test_cnt =0;
    while (test_cnt < options.message_count)
    {
        display_priority("vor receive")
        my_len = nw_vmf_receive (my_rx_id, (vmf_msg_t*)&my_msg, (unsigned16)(MAX_FAR_DATA_LEN+50));
/* jmerkle          VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_17, VMF_TASK_RECEIVER, "vmf_receiver", "Message received."); */
        display_priority("nach receive")

        rx_time=vmf_get_time_snapshot();

        if (my_len == 0)
        {
            VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR_19, VMF_TASK_RECEIVER, "vmf_receiver", "receive message failed -- length==0\n");
        }
        else
        {
            switch (my_msg.vmf_basic_msg.msg_base.base.msg_type)
            {
                case MSG_TYPE_BASIC_MESSAGE:
                    memcpy(&tx_time, VMF_BASIC_MSG_PTR_TO_FAR_DATA(&my_msg), sizeof(unsigned64));
                    rx_tx_time_diff = vmf_get_time_diff(tx_time, rx_time);
                    my_trans_time[test_cnt] = rx_tx_time_diff;
                    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_1, VMF_TASK_RECEIVER, "vmf_receiver", "Basic message received. Transmission latency==%lld", rx_tx_time_diff);
                break;

                case MSG_TYPE_MOST_MESSAGE:
                    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_1, VMF_TASK_RECEIVER, "vmf_receiver", "received most message fblockId=%x,InstId=%x,FuncId=%x,OpType=%1x\n",
                                                                                                                my_msg.vmf_most_msg.fblock_id, my_msg.vmf_most_msg.inst_id,
                                                                                                                my_msg.vmf_most_msg.func_id, my_msg.vmf_most_msg.op_type);
                break;

                default:
                    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TASK_RECEIVER, "vmf_receiver", "Invalid message received! Data:");
                    VMF_TRACE_HEX(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TASK_RECEIVER, "vmf_receiver", 100, (unsigned8 *)&my_msg);
                break;
            }
        }

        test_cnt++;
    }



    delay (1000);
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO, VMF_TASK_RECEIVER, "vmf_receiver", "\nvmf_receiver: \n");
    for (test_cnt=0; test_cnt<options.message_count; test_cnt++)
    {
        VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO, VMF_TASK_RECEIVER,
            "vmf_receiver", "\tMsgID== %d \ttransfer-time== %d ns\n",(int)test_cnt ,(int)my_trans_time[test_cnt]);
    }
 
}


/*****************************************************************************
 *
 *   Function Name: vmf_get_time_snapshot(void)
 *
 *   Description:   get the system time
 *
 *   Parameters:
 *
 *   Function Return value: - void
 *
 ******************************************************************************/
unsigned64 vmf_get_time_snapshot(void)
{
#if 0
    return (unsigned64)(nw_os_cfg_get_ms_time());
#endif

    unsigned64      ret_val=0;
    struct timespec temp;
    unsigned64      time_ns;


    if (0 == clock_gettime(CLOCK_REALTIME, &temp))
    {
        time_ns = ((unsigned64)temp.tv_sec * (unsigned64)1000000000L) + (unsigned64)temp.tv_nsec;
        ret_val = time_ns;
    }
    else
    {
        /* error! */
        printf("vmf_get_time_snapshot: clock_gettime failed!!!\n");
    }

    return ret_val;

}


/*****************************************************************************
 *
 *   Function Name: vmf_get_time_diff()
 *   Description:   calculate time difference of two snapshots
 *
 *   Parameters:    - start time [ns]
 *                  - end time [ns]
 *   Return:          time difference is ns
 *
 ******************************************************************************/
unsigned64 vmf_get_time_diff(unsigned64 start_time, unsigned64 stop_time)
{
    unsigned64 diff_nsec;

    if (start_time < stop_time)
    {
        diff_nsec = stop_time - start_time;
    }
    else
    {
        diff_nsec = 0;
        VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR_19, VMF_TASK_RECEIVER, "vmf_get_time_diff", "start > stop !!!");
    }

    return diff_nsec;
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
        VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR, VMF_TASK_RECEIVER, "get_options", "NO parameters -- nothing done!");
        usage();
        return false;
    }

    /* initialize options */
    options.message_group = 0;
    options.message_count = 0;


    while ((c = getopt(argc, argv, "hg:n:")) != -1)
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

            /* number of messages (loop counter) */
            case 'n':
                options.message_count=strtoul(optarg, NULL, 0);
                if (options.message_count > MAX_TEST_CNT)
                {
                    options.message_count = MAX_TEST_CNT;
                }
            break;

            default :
                /* unknown option */
                VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TASK_RECEIVER, "get_options","%c is an unknown option!", c);
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

    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TASK_RECEIVER, "usage", "");
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TASK_RECEIVER, "usage", "");
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TASK_RECEIVER, "usage", "***************************************************************");
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TASK_RECEIVER, "usage", "** receive_basic_message process                               ");
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TASK_RECEIVER, "usage", "***************************************************************");
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TASK_RECEIVER, "usage", "**                                                             ");
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TASK_RECEIVER, "usage", "** usage: receive_basic_message [options]                      ");
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TASK_RECEIVER, "usage", "**     -h     this help                                        ");
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TASK_RECEIVER, "usage", "**     -g     message group                                    ");
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TASK_RECEIVER, "usage", "**     -n     message count                                    ");
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TASK_RECEIVER, "usage", "**                                                             ");
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TASK_RECEIVER, "usage", "***************************************************************");
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TASK_RECEIVER, "usage", "");
    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TASK_RECEIVER, "usage", "");

}




