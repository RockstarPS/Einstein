/*
 VMF Ping
 Receives basic messages thru VMF and collects results
 by J. Merkle
*/

#include "nw_os_config.h"
#include "nw_vmf.h"
#include "nw_vmf_trace.h"


#ifdef PRINT_BUILD_TIME
#include "build_time.h"
#endif


/* defs and typedefs */
#define MAX_FAR_DATA_LEN            8192

#ifdef __QNX__
    #define MAX_TEST_CNT            15000
#else
    #define MAX_TEST_CNT            65000
#endif

#define VMF_TRID_NAME               "VMF-Ping"
#define VMF_TRACE_TASK              "Listener"
#define VMF_TRACE_TASK_RESULT       "Result"

#ifdef AUTOMATED_BENCHMARK
    #define VMF_PING_ERROR(scope, args...)      printf("vmf_listener: ERROR  "); printf(scope), printf(" -- "); printf(args); printf("\n");
    #define VMF_PING_RESULT(args...)            printf("vmf_listener: "); printf(args); printf("\n");
    #define VMF_PING_INFO_HI(scope, args...)    
    #define VMF_PING_INFO_LO(scope, args...)    
#else
    #ifdef VMF_TRACE
        #define VMF_PING_ERROR(scope, args...)      VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR, VMF_TRACE_TASK, scope, args);
        #define VMF_PING_RESULT(args...)            VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_13, VMF_TRACE_TASK_RESULT, "result", args);
        #define VMF_PING_INFO_HI(scope, args...)    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_10, VMF_TRACE_TASK, scope, args);
        #define VMF_PING_INFO_LO(scope, args...)    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_20, VMF_TRACE_TASK, scope, args);
    #else
        #define VMF_PING_ERROR(scope, args...)      printf("vmf_listener: ERROR   "); printf(scope), printf(" -- "); printf(args); printf("\n");
        #define VMF_PING_RESULT(args...)            printf("vmf_listener: "); printf(args); printf("\n");
        #define VMF_PING_INFO_HI(scope, args...)    /* printf("vmf_listener: INFO_HI "); printf(scope), printf(" -- "); printf(args); printf("\n"); */
        #define VMF_PING_INFO_LO(scope, args...)    /* printf("vmf_listener: INFO_LO "); printf(scope), printf(" -- "); printf(args); printf("\n"); */
    #endif
#endif

typedef struct
{
    unsigned8   index;
    unsigned8   message_group;
    unsigned16  message_count;
    bool        suppress_result;
    bool        evaluate_time_diff;
}options_t;


/* global data */
options_t           options;

char                myName[31];
vmf_client_id_t     vmf_connection_id = -1;

unsigned8           vmf_trid;

/* function prototypes */
void vmf_receiver(unsigned8 my_message_group);
unsigned64 vmf_get_time_snapshot(void);
unsigned64 vmf_get_time_diff(unsigned64 start_time, unsigned64 stop_time);
bool get_options(int argc, char *argv[]);
void usage(void);

#if DISPLAY_PRIO__QNX_ONLY
void display_priority(char * prefix);
#endif



int main (int argc, char *argv[])
{
    vmf_ret_t   vmf_result;


    VMF_VAR_BASIC_MSG_TYP(10) msg;
    vmf_basic_msg_t *pmsg = (vmf_basic_msg_t *)&msg;

#ifdef PRINT_BUILD_TIME
    printf("vmf_listener: Build Time: %s\n", build_time);
#endif

    /* connect VMF */
    sprintf(myName,"VMF Ping Listener %d", options.index);

    while (vmf_connection_id < 0)
    {
        vmf_connection_id = nw_vmf_connect(myName, NULL, 0, 100, MAX_FAR_DATA_LEN);
        if (vmf_connection_id < 0)
        {
            //printf("vmf_receiver", "nw_vmf_connect() failed - error==%d",vmf_connection_id);
            delay(100);
        }

    }

    /* Register for VMF Tracer */
    if (VMF_TRACE_REGISTER(&vmf_trid, VMF_TRID_NAME) < 0)
    {
        fprintf(stderr, "vmf_listener: CANNOT CONNECT TO VMF TRACER!!!\n");
    }
#ifndef AUTOMATED_BENCHMARK
    else
    {
        fprintf(stdout, "\n\n\nSET VMF TRACER SEVERITY FOR 'VMF Ping' to <=73 !!!\n\n\n");
    }
#endif

    if (false == get_options(argc,argv))
    {
        VMF_PING_ERROR("main", "Error while reading command line options. Exit now!");
        return -1;
    }

    delay(1000);

    VMF_PING_INFO_HI("main", "VMF Ping listener startet. PID==%d", getpid());

    VMF_PING_INFO_HI("main", "Options:");
    VMF_PING_INFO_HI("main", "   listener index  = %d", options.index);
    VMF_PING_INFO_HI("main", "   message group   = %d", options.message_group);
    VMF_PING_INFO_HI("main", "   message count   = %d", options.message_count);

    if (true == options.suppress_result)
    {
        VMF_PING_INFO_HI("main", "   suppress result = true");
    }
    else
    {
        VMF_PING_INFO_HI("main", "   suppress result = false");
    }

    /* now receive message in forever */
    vmf_receiver(options.message_group);

    VMF_PING_INFO_HI("main", "FINISHED!!!");

    return 0;
}



/*****************************************************************************
 *
 *   Function Name: vmf_receiver(unsigned8 my_message_group)
 *
 *   Description:   start the vmf test receiver
 *
 *   Parameters:    void
 *
 *   Return :       my_message_group - message to be registered at vmf
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
    vmf_ret_t           my_ret;
    unsigned16          my_len;
    unsigned16          test_cnt;
    unsigned16          tx_count[MAX_TEST_CNT];
	unsigned32 			print_len;
	unsigned16			i;

    VMF_PING_INFO_LO("vmf_receiver", "Start test-receiver.");


    /* register message group */
    my_ret = nw_vmf_register_msg_group (vmf_connection_id, 1, &my_message_group);
    if (my_ret < 0)
    {
        VMF_PING_ERROR("vmf_receiver", "nw_vmf_register_msg_group() failed - error=%d\n",my_ret);
        return;
    }

    VMF_PING_INFO_LO("vmf_receiver", "Test-receiver connected - start reception.");


    test_cnt =0;
    while (test_cnt < options.message_count)
    {

#if DISPLAY_PRIO__QNX_ONLY
        display_priority("vor receive");
        my_len = nw_vmf_receive (vmf_connection_id, (vmf_msg_t*)&my_msg, sizeof(my_msg));
        display_priority("nach receive");
#else
        my_len = nw_vmf_receive (vmf_connection_id, (vmf_msg_t*)&my_msg, sizeof(my_msg));
#endif

        VMF_PING_INFO_LO("vmf_receiver", "vmf_receive() returned with %d.", my_len);

        if (VMF_OK != nw_vmf_connection_state( vmf_connection_id)) 
        {
            printf("nw_vmf_connection_state() failed\n");
        }

        rx_time=vmf_get_time_snapshot();
        VMF_TRACE_HEX(vmf_trid, 100, VMF_TRACE_TASK, "rx_time", sizeof(rx_time), (unsigned8 *)&rx_time);

        if (my_len == 0)
        {
            VMF_PING_ERROR("vmf_receiver", "receive message failed -- length==0\n");
        }
        else
        {
            switch (my_msg.vmf_basic_msg.msg_base.base.msg_type)
            {
                case MSG_TYPE_BASIC_MESSAGE:
                    if (true == options.evaluate_time_diff)
                    {
                        memcpy(&tx_time, &(my_msg.vmf_basic_msg.data.pl[4]) , sizeof(unsigned64));
                        // memcpy(&tx_time, VMF_BASIC_MSG_PTR_TO_FAR_DATA(&my_msg), sizeof(unsigned64));
                        rx_tx_time_diff = vmf_get_time_diff(tx_time, rx_time);
                        my_trans_time[test_cnt] = rx_tx_time_diff;
                    }
                    tx_count[test_cnt] = (my_msg.vmf_basic_msg.data.pl[0] << 8) + my_msg.vmf_basic_msg.data.pl[1];
                    VMF_PING_INFO_LO("vmf_receiver", "Basic message received. \tRxCount== %d \tTxCount== %d \tTransTime== %d ns",(int)test_cnt, (int)tx_count[test_cnt], (int)my_trans_time[test_cnt]);
                    VMF_PING_INFO_LO("vmf_receiver", "Basic message received. payload.len==%d", my_msg.vmf_basic_msg.data.length);
                    VMF_TRACE_HEX(vmf_trid, 100, VMF_TRACE_TASK, "vmf_receiver", my_msg.vmf_basic_msg.data.length, (unsigned8 *)&my_msg.vmf_basic_msg.data.pl);

                break;

                case MSG_TYPE_MOST_MESSAGE:
                    VMF_PING_INFO_LO("vmf_receiver", "received most message fblockId=%x,InstId=%x,FuncId=%x,OpType=%1x\n",
                                        my_msg.vmf_most_msg.fblock_id, my_msg.vmf_most_msg.inst_id, my_msg.vmf_most_msg.func_id, my_msg.vmf_most_msg.op_type);
                break;

                default:
                    VMF_PING_INFO_HI("vmf_receiver", "Invalid message received! Data:");
                    VMF_TRACE_HEX(vmf_trid, VMF_TRACE_SEVERITY_WARNING_10, VMF_TRACE_TASK, "vmf_receiver", 100, (unsigned8 *)&my_msg);
                break;
            }
        }

        test_cnt++;
    }
	print_len = (my_msg.vmf_basic_msg.data.length > 50) ? 50 : my_msg.vmf_basic_msg.data.length;	
	printf("VMF_Receiver%d Received %d Messages of \nGID = %d \nEID = %d \nLength = %d(%d) \nPayload = ", options.index, test_cnt, my_msg.vmf_basic_msg.msg_base.id.group, my_msg.vmf_basic_msg.msg_base.id.event, my_msg.vmf_basic_msg.data.length, print_len);
	for(i = 0; i< print_len; i++)
	{
		printf("%0x ", my_msg.vmf_basic_msg.data.pl[i]);
	}
	printf("\n");
	printf("Exiting VMF_Receiver %d ...\n", options.index);
    /* send results? */
    if (false == options.suppress_result)
    {
        delay (4000 + (2 * (options.message_count * options.index)));

        printf("vmf_listener: ID==%d -- start transmission to tracer\n", (int)options.index);
        for (test_cnt=0; test_cnt<options.message_count; test_cnt++)
        {
            delay(10);
/* jmerkle              printf("\tRxCount== %d \tTxCount== %d \tTransTime== %d ns\n",(int)test_cnt, (int)tx_count[test_cnt], (int)my_trans_time[test_cnt]); */

            if (true == options.evaluate_time_diff)
            {
                VMF_PING_RESULT("\tRxCount== %d \tTxCount== %d \tTransTime== %d ns",(int)test_cnt, (int)tx_count[test_cnt], (int)my_trans_time[test_cnt]);
            }
            else
            {
                VMF_PING_RESULT("\tRxCount== %d \tTxCount== %d ",(int)test_cnt, (int)tx_count[test_cnt]);
            }

        }
    }


    /* Always perform check for lost messages! */
    for (test_cnt=0; test_cnt<options.message_count; test_cnt++)
    {
        if (test_cnt != tx_count[test_cnt])
        {
            VMF_PING_ERROR("vmf_receiver", "MESSAGES LOST!!!! RxCount== %d -- TxCount== %d",(int)test_cnt, (int)tx_count[test_cnt]);
        }
    }


    delay (5);

    nw_vmf_disconnect(vmf_connection_id);

    delay (1);

}


/*****************************************************************************
 *
 *   Function Name: vmf_get_time_snapshot(void)
 *
 *   Description:   get the system time
 *
 *   Parameters:
 *
 *   Function Return value: actual time [ns] (from 1970)
 *
 ******************************************************************************/
unsigned64 vmf_get_time_snapshot(void)
{
    unsigned64      ret_val=0;
    struct timespec temp;
    unsigned64      time_ns;

#ifdef __WINDOWS__

    ret_val = nw_os_cfg_get_ns_time();

#else
    if (0 == clock_gettime(CLOCK_REALTIME, &temp))
    {
        time_ns = ((unsigned64)temp.tv_sec * (unsigned64)1000000000L) + (unsigned64)temp.tv_nsec;
        ret_val = time_ns;
    }
    else
    {
        /* error! */
        VMF_PING_ERROR("vmf_get_time_snapshot", "clock_gettime() failed!!!\n");
    }
#endif
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

    if (start_time <= stop_time)
    {
        diff_nsec = stop_time - start_time;
    }
    else
    {
        diff_nsec = 0;
        VMF_PING_ERROR("vmf_get_time_diff", "start > stop !!!");
        VMF_TRACE_HEX(vmf_trid, 100, VMF_TRACE_TASK, "start_time", sizeof(start_time), (unsigned8 *)&start_time);
        VMF_TRACE_HEX(vmf_trid, 100, VMF_TRACE_TASK, "stop_time", sizeof(stop_time), (unsigned8 *)&stop_time);
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

    /* initialize options */
    options.index= 0;
    options.message_group = 10;
    options.message_count = 10;
    options.suppress_result = false;
    options.evaluate_time_diff = false;

    if (1==argc)
    {
        /* call without any argument */
        VMF_PING_ERROR("get_options", "NO command line parameters -- using defaults! Try '-h' for more info.");
        return true;
    }

    while ((c = getopt(argc, argv, "hi:g:c:st")) != -1)
    {
        switch (c)
        {
            case 'h':
                usage();
                return false;
            break;

            case 'i':
                options.index = atoi(optarg);
            break;

            case 'g':
                options.message_group = atoi(optarg);
            break;

            /* number of messages (loop counter) */
            case 'c':
                options.message_count=strtoul(optarg, NULL, 0);
                if (options.message_count > MAX_TEST_CNT)
                {
                    options.message_count = MAX_TEST_CNT;
                }
            break;

            case 's':
                options.suppress_result = true;
            break;

            case 't':
                options.evaluate_time_diff = true;
            break;

            default :
                /* unknown option */
                VMF_PING_INFO_HI("get_options","%c is an unknown option!", c);
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
    printf("************************************************************************\n");
    printf("** vmf_listener process                                               **\n");
    printf("************************************************************************\n");
    printf("**                                                                    **\n");
    printf("** usage: vmf_listener [options]                                      **\n");
    printf("**                                                                    **\n");
    printf("**     Opt.   Description                                    Default  **\n");
    printf("**     -h     this help                                               **\n");
    printf("**     -i     listener index (if more than 1 listener)       %d       **\n", options.index);
    printf("**     -g     message group                                  %d       **\n", options.message_group);
    printf("**     -c     message count                                  %d       **\n", options.message_count);
    printf("**     -s     suppress results                               false    **\n");
    printf("**     -t     evaluate time diff per message                 false    **\n");
    printf("**                                                                    **\n");
    printf("************************************************************************\n");
}

#if DISPLAY_PRIO__QNX_ONLY
void display_priority(char * prefix)
{
    struct sched_param  task_priority;
    int                 policy;
//  struct sched_param  param;

    if (EOK == pthread_getschedparam( pthread_self(),
                                      &policy,
                                      &task_priority))
    {
        printf("%s, priority = %d, %d\n",prefix,task_priority.sched_priority,task_priority.sched_curpriority);
    }

//  sched_getparam( 0,&param);

}

#endif
