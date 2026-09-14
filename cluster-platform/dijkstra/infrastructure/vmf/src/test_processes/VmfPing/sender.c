/*
 VMF Ping
 Sends basic messages thru VMF
 by J. Merkle
*/


#include "nw_os_config.h"
#include "nw_vmf.h"
#include "nw_vmf_trace.h"

#ifdef PRINT_BUILD_TIME
#include "build_time.h"
#endif


/* defs and typedefs */
#define MAX_FAR_DATA_LEN        8192
#define TEST_COUNT_HYST         0

#ifdef __QNX__
    #define MAX_TEST_CNT            15000 + TEST_COUNT_HYST
#else
    #define MAX_TEST_CNT            65000 + TEST_COUNT_HYST
#endif

#define VMF_TRID_NAME           "VMF-Ping"
#define VMF_TRACE_TASK          "Sender"
#define VMF_TRACE_TASK_RESULT   "Result"


#ifdef VMF_TRACE
    #define VMF_PING_ERROR(scope, args...)      VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR, VMF_TRACE_TASK, scope, args);
    #define VMF_PING_RESULT(args...)            VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_13, VMF_TRACE_TASK_RESULT, "result", args);
    #define VMF_PING_INFO_HI(scope, args...)    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_10, VMF_TRACE_TASK, scope, args);
    #define VMF_PING_INFO_LO(scope, args...)    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_20, VMF_TRACE_TASK, scope, args);
#else
    #define VMF_PING_ERROR(scope, args...)      printf("vmf_sender: ERROR   "); printf(scope), printf(" -- "); printf(args); printf("\n");
    #define VMF_PING_RESULT(args...)            printf("vmf_sender: "); printf(args); printf("\n");
    #define VMF_PING_INFO_HI(scope, args...)    /* printf("vmf_sender: INFO_HI "); printf(scope), printf(" -- "); printf(args); printf("\n"); */
    #define VMF_PING_INFO_LO(scope, args...)    /* printf("vmf_sender: INFO_LO "); printf(scope), printf(" -- "); printf(args); printf("\n"); */
#endif


typedef struct
{
    unsigned8   index;
    unsigned8   wait;
    unsigned8   message_group;
    unsigned8   event;
    unsigned8   near_data[4];
    unsigned16  far_data_len;
    unsigned8   far_data[MAX_FAR_DATA_LEN];
    bool        send_time_snap;
    unsigned16  message_count;
    unsigned16  message_delay;
}options_t;


/* global data */
char                myName[31];
vmf_client_id_t     vmf_connection_handle = -1;
unsigned8           vmf_trid;
options_t           options;


/* function prototypes */
unsigned64 vmf_get_time_snapshot(void);
bool get_options(int argc, char *argv[]);
void usage(void);


void vmf_sender (void);



int main (int argc, char *argv[])
{
    unsigned8 i;

#ifdef PRINT_BUILD_TIME
    printf("vmf_sender: Build Time: %s\n", build_time);
#endif

    sprintf(myName,"VMF Ping Sender %d", options.index);
    while (vmf_connection_handle < 0)
    {
        vmf_connection_handle = nw_vmf_connect(myName, 0, 0, VMF_CLIENT_QUEUE_SIZE_STANDARD, VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD);
        if (vmf_connection_handle < 0)
        {
            //VMF_PING_ERROR("vmf_sender", "nw_vmf_connect() failed - error==%d", vmf_connection_handle);
            delay(100);
        }
    }

    /* Register for VMF Tracer */
    if (VMF_TRACE_REGISTER(&vmf_trid, VMF_TRID_NAME) < 0)
    {
        fprintf(stderr, "vmf_sender: CANNOT CONNECT TO VMF TRACER!!!\n");
    }

    if (false == get_options(argc,argv))
    {
        VMF_PING_ERROR("main", "Error while reading command line options. Exit now!");
        return -1;
    }

    VMF_PING_INFO_HI("main", "VMF Ping sender startet. PID==%d", getpid());

    VMF_PING_INFO_HI("main", "Options:");
    VMF_PING_INFO_HI("main", "    wait          = %d\n", options.wait);
    VMF_PING_INFO_HI("main", "    message_group = %d\n", options.message_group);
    VMF_PING_INFO_HI("main", "    event         = %d\n", options.event);
    VMF_PING_INFO_HI("main", "    near data     = %d %d %d %d\n", options.near_data[0], options.near_data[1], options.near_data[2], options.near_data[3]);
    VMF_PING_INFO_HI("main", "    far data len  = %d\n", options.far_data_len);
    VMF_PING_INFO_HI("main", "    far data      = %d %d %d %d %d ...\n", options.far_data[0], options.far_data[1], options.far_data[2], options.far_data[3], options.far_data[4]);

    if (true == options.send_time_snap)
    {
        VMF_PING_INFO_HI("main", "    use time snap = true\n");
    }
    else
    {
        VMF_PING_INFO_HI("main", "    use time snap = false\n");
    }

    VMF_PING_INFO_HI("main", "   message count = %d", options.message_count);
    VMF_PING_INFO_HI("main", "   message delay = %d", options.message_delay);

    delay(2000);

    for (i=0; i<options.wait; i++)
    {
        VMF_PING_INFO_HI("main", " *** %d seconds till start! *** ", (options.wait-i));
        delay(1000);
    }


    /* start the sender */
    vmf_sender();


    VMF_PING_INFO_HI("main", "FINISHED!!!");

    return 0;
}



/*****************************************************************************
 *
 *   Function Name: vmf_sender(void)
 *
 *   Description:   start the vmf test sender
 *
 *   Parameters:    void
 *
 *   Return :       void
 *
 ******************************************************************************/
void vmf_sender(void)
{

    vmf_ret_t                   vmf_result;
    VMF_VAR_BASIC_MSG_TYP(MAX_FAR_DATA_LEN)   msg;
    vmf_basic_msg_t             *pmsg = (vmf_basic_msg_t *)&msg;
    unsigned64                  tx_time_snap;
    unsigned16                  i;
    unsigned16                  tx_count = 0;
    unsigned64                  start_time_snap;
    unsigned64                  end_time_snap;
    unsigned64                  total_duration;
    unsigned32                  thruput;	
	unsigned32 					print_len;

    if (options.far_data_len > MAX_FAR_DATA_LEN)
    {
        VMF_PING_ERROR("vmf_sender", "far data len too big! Allowed max. == %d", (int)MAX_FAR_DATA_LEN);
        return;
    }

    VMF_BASIC_MSG_GROUP_ID(pmsg)    = options.message_group;
    VMF_BASIC_MSG_EVENT_ID(pmsg)    = options.event;
    pmsg->data.pl[0] = options.near_data[0];
    pmsg->data.pl[1] = options.near_data[1];
    pmsg->data.pl[2] = options.near_data[2];
    pmsg->data.pl[3] = options.near_data[3];
	
    if (options.far_data_len > 0)
    {
        VMF_BASIC_MSG_SET_FAR_DATA_LENGTH(pmsg,options.far_data_len);
		memcpy((unsigned8*)VMF_BASIC_MSG_PTR_TO_FAR_DATA(pmsg),(void *)options.far_data, options.far_data_len);
//        pmsg->data.length = options.far_data_len + 4;
//        memcpy(&(pmsg->data.pl[4]),(void *)options.far_data, options.far_data_len);
    }
    else
    {
        VMF_BASIC_MSG_SET_FAR_DATA_LENGTH(pmsg,0);
    }

    start_time_snap = vmf_get_time_snapshot();

    for (i=0; i<options.message_count; i++)
    {

        if (true == options.send_time_snap)
        {
            tx_time_snap = vmf_get_time_snapshot();

            if (options.far_data_len < 8)
            {
                VMF_BASIC_MSG_SET_FAR_DATA_LENGTH(pmsg,8);
            }

            memcpy(VMF_BASIC_MSG_PTR_TO_FAR_DATA(pmsg),(void *)&tx_time_snap, sizeof(unsigned64));

            pmsg->data.pl[0] = (i & 0xFF00) >> 8;
            pmsg->data.pl[1] = (i & 0x00FF);

        }

/* jmerkle          printf("vmf_sender: tx-len==%d\n",msg.data.length); */
        vmf_result = nw_vmf_send_basic (vmf_connection_handle,(vmf_basic_msg_t*)pmsg);
        if(VMF_OK != vmf_result)
        {
            VMF_PING_ERROR("vmf_sender", "send vmf basic message failed -- VMF error %d\n", vmf_result);
            printf("vmf_sender: send vmf basic message failed -- VMF error %d\n", vmf_result);
        }
        else
        {
            tx_count = (VMF_BASIC_MSG_NEAR_DATA_0(pmsg) << 8) + VMF_BASIC_MSG_NEAR_DATA_1(pmsg);
            VMF_PING_INFO_LO("vmf_sender", "send vmf basic message ok -- count==%d", VMF_BASIC_MSG_NEAR_DATA_1(pmsg));
        }

        delay(options.message_delay);

    }

    end_time_snap = vmf_get_time_snapshot();
    total_duration = end_time_snap - start_time_snap;
    thruput = (unsigned32)((float)(options.message_count * VMF_BASIC_MSG_ALL_DATA_LENGTH(pmsg)) / (float)((float)total_duration / 1000000000));


    if (total_duration > 1000000)
    {
        total_duration = total_duration / 1000000;
        VMF_PING_RESULT("\tTotalTime == %ld ms",(unsigned32)total_duration);
    }
    else if (total_duration > 1000)
    {
        total_duration = total_duration / 1000;
        VMF_PING_RESULT("\tTotalTime == %ld us",(unsigned32)total_duration);
    }
    else /* ns */
    {
        total_duration = total_duration / 1;
        VMF_PING_RESULT("\tTotalTime == %ld ns",(unsigned32)total_duration);
    }

    VMF_PING_RESULT("\tThroughput (data rate!) == %ld byte/s",(unsigned32)thruput);
	print_len = (options.far_data_len > 50) ? 50 : options.far_data_len;
	printf("#############################################\n");
	printf("VMF_Sender: %d Msgs Sent with \nGID = %d \nEID = %d\nLength = %d(%d)\nData = ", i, options.message_group, options.event, options.far_data_len, print_len);
	for(i = 0; i< print_len; i++)
	{
		printf("%0x ", options.far_data[i]);
	}
	printf("\n");
	printf("VMF_Sender %d Exiting...\n", options.index);
	printf("#############################################\n");

    nw_vmf_disconnect(vmf_connection_handle);


    return;
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
    options.index = 0;
    options.message_group = 10;
    options.event = 20;
    options.far_data_len = 0;
    options.send_time_snap = false;
    options.message_count = 10;
    options.message_delay = 100;
    options.wait = 0;

    if (1==argc)
    {
        /* call without any argument */
        VMF_PING_ERROR("get_options", "NO command line parameters -- using defaults! Try '-h' for more info.");
        return true;
    }

    while ((c = getopt(argc, argv, "hi:g:e:n:l:f:tc:d:w:")) != -1)
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
                    //snprintf(buffer, 3, "%s", &optarg[2*i]);
					//options.far_data[i] = atoi(buffer);
					sscanf(&optarg[2*i], "%2hhx", &options.far_data[i]);
                }
            break;

            case 't':
                /* put time into far data */
                options.send_time_snap = true;
            break;

            /* number of messages (loop counter) */
            case 'c':
                options.message_count=strtoul(optarg, NULL, 0) + TEST_COUNT_HYST;
                if (options.message_count > MAX_TEST_CNT)
                {
                    options.message_count = MAX_TEST_CNT;
                }
            break;

            /* message delay */
            case 'd':
                options.message_delay=strtoul(optarg, NULL, 0);
            break;

            case 'w':
                options.wait = atoi(optarg);
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
    printf("** vmf_sender process                                                 **\n");
    printf("************************************************************************\n");
    printf("**                                                                    **\n");
    printf("** usage: vmf_sender [options]                                        **\n");
    printf("**                                                                    **\n");
    printf("**     Opt.   Description                                    Default  **\n");
    printf("**     -h     this help                                               **\n");
    printf("**     -i     listener index                                 %d       **\n", options.index);
    printf("**     -g     message group                                  %d       **\n", options.message_group);
    printf("**     -e     event                                          %d       **\n", options.event);
    printf("**     -n     near data, always 4byte, NO spaces             -        **\n");
    printf("**     -l     length of far data                             %d       **\n", options.far_data_len);
    printf("**     -f     far data, requires option -l, NO spaces        -        **\n");
    printf("**     -t     put time snapshot into far data (8 bytes)      false    **\n");
    printf("**     -c     message count                                  %d       **\n", options.message_count);
    printf("**     -d     message delay [ms]                             %d       **\n", options.message_delay);
    printf("**     -w     wait (before sending) [s]                      %d       **\n", options.wait);
    printf("**                                                                    **\n");
    printf("************************************************************************\n");
}

