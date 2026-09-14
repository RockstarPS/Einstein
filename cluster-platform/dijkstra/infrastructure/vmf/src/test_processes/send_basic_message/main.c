/*
 Send a basic message thru VMF
 by J. Merkle
*/



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
//#include <sys/neutrino.h>
//#include <sys/syspage.h>
#include <sys/stat.h>
#include <sys/mman.h>
//#include <sys/netmgr.h>
#include <pthread.h>
#include <fcntl.h>

/* jmerkle  #include <sys/time.h> */
#include <time.h>
 
#include "types.h"
#include "nw_os_config.h"
#include "nw_vmf.h"


/* OSAL Includes */
//#include "os_types.h"
//#include "os_if.h"
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>


//#define PRINT_OPTIONS_ONLY


/* defs and typedefs */
#define MAX_FAR_DATA_LEN    500

typedef struct
{
    unsigned8   message_group;
    unsigned8   event;
    unsigned8   near_data[4];
    unsigned8   far_data_len;
    unsigned8   far_data[MAX_FAR_DATA_LEN];
    bool        send_time_snap;
    unsigned16  message_count;
    unsigned16  message_delay;
}options_t;


/* global data */
vmf_client_id_t     vmf_connection_handle;
options_t           options;


/* function prototypes */
unsigned64 vmf_get_time_snapshot(void);
bool get_options(int argc, char *argv[]);
void usage(void);





int main (int argc, char *argv[])
{

    vmf_ret_t   vmf_result;

    VMF_VAR_BASIC_MSG_TYP(20) msg;
    vmf_basic_msg_t *pmsg = (vmf_basic_msg_t *)&msg;
    
    unsigned64 tx_time_snap;
    unsigned16 i;


    if (false == get_options(argc,argv))
    {
        return -1;
    }


    printf("\n\n");
    printf("send_basic_message: options\n");
    printf("My PID==%d\n",getpid());
    printf("Options\n");
    printf("    message_group = %d\n", options.message_group);
    printf("    event         = %d\n", options.event);
    printf("    near data     = %d %d %d %d\n", options.near_data[0], options.near_data[1], options.near_data[2], options.near_data[3]);
    printf("    far data len  = %d\n", options.far_data_len);
    printf("    far data      = %d %d %d %d %d ...\n", options.far_data[0], options.far_data[1], options.far_data[2], options.far_data[3], options.far_data[4]);

    if (true == options.send_time_snap)
    {
        printf("    use time snap = true\n");
    }
    else
    {
        printf("    use time snap = false\n");
    }

    printf("    message count = %d\n", options.message_count);
    printf("    message delay = %d\n", options.message_delay);
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


    for (i=0; i<options.message_count; i++)
    {

        if (true == options.send_time_snap)
        {
            tx_time_snap = vmf_get_time_snapshot();
            VMF_BASIC_MSG_SET_FAR_DATA_LENGTH(pmsg,8);
            memcpy(VMF_BASIC_MSG_PTR_TO_FAR_DATA(pmsg),(void *)&tx_time_snap, sizeof(unsigned64));
        }

        vmf_result = nw_vmf_send_basic (vmf_connection_handle,(vmf_basic_msg_t*)pmsg);
        if(VMF_OK != vmf_result)
        {
            printf("send_basic_message: send vmf basic message failed -- VMF error %d\n", (int)vmf_result);
        }
        else
        {
/* jmerkle              printf("send_basic_message: send vmf basic message ok\n"); */
        }

        if (options.message_delay > 0)
        {
            delay(options.message_delay);
        }

    }

  	return 0;
}



/*****************************************************************************
 *
 *   Function Name: nw_vmf_get_time_snapshot(void)
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


#if 0
    struct timespec temp2;
    unsigned64      sec_ns;

    struct timeval  temp_tv;
    struct timeval  temp2_tv;

    unsigned64      start;
    unsigned64      end;
#endif

#if 0

    /* USE #include <time.h> !!!!*/

    if (0 == clock_gettime(CLOCK_REALTIME, &temp))
    {
        printf("vmf_get_time_snapshot: secs==%d -- nsec==%d\n",(int)temp.tv_sec, (int)temp.tv_nsec);
    }

    delay(10);

    if (0 == clock_gettime(CLOCK_REALTIME, &temp2))
    {
        printf("vmf_get_time_snapshot: secs==%d -- nsec==%d\n",(int)temp2.tv_sec, (int)temp2.tv_nsec);
    }


    start = ((unsigned64)temp.tv_sec * (unsigned64)1000000000L) + (unsigned64)temp.tv_nsec;
    end   = ((unsigned64)temp2.tv_sec * (unsigned64)1000000000L) + (unsigned64)temp2.tv_nsec;
    printf("vmf_get_time_snapshot: start==%ld -- end==%ld\n",(long)start, (long)end);

    time_ns = end - start;

    printf("vmf_get_time_snapshot: time==%ld\n",(long)time_ns);
#endif

#if 0

    /* USE #include <sys/time.h> !!!!*/

    if (0 == gettimeofday(&temp_tv, NULL))
    {
        printf("vmf_get_time_snapshot: secs==%d -- usec==%d\n",(int)temp_tv.tv_sec, (int)temp_tv.tv_usec);
    }

    delay(10);
    
    if (0 == gettimeofday(&temp2_tv, NULL))
    {
        printf("vmf_get_time_snapshot: secs==%d -- usec==%d\n",(int)temp2_tv.tv_sec, (int)temp2_tv.tv_usec);
    }


    start = ((unsigned64)temp_tv.tv_sec * (unsigned64)1000000L) + (unsigned64)temp_tv.tv_usec;
    end   = ((unsigned64)temp2_tv.tv_sec * (unsigned64)1000000L) + (unsigned64)temp2_tv.tv_usec;
    printf("vmf_get_time_snapshot: start==%ld -- end==%ld\n",(long)start, (long)end);

    time_ns = end - start;
    
    printf("vmf_get_time_snapshot: time==%ld\n",(long)time_ns);
#endif


    return (unsigned64)ret_val;
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
        fprintf(stderr, "send_basic_message: no parameters -- nothing done! \n", c);
        usage();
        return false;
    }

    /* initialize options */
    options.message_group = 0;
    options.event = 0;
    options.far_data_len = 0;
    options.send_time_snap = false;
    options.message_count = 1;
    options.message_delay = 100;


    while ((c = getopt(argc, argv, "hg:e:n:l:f:tc:d:")) != -1)
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
                snprintf(buffer, 3, &optarg[0]);
                options.near_data[0] = atoi(buffer);

                snprintf(buffer, 3, &optarg[2]);
                options.near_data[1] = atoi(buffer);

                snprintf(buffer, 3, &optarg[4]);
                options.near_data[2] = atoi(buffer);

                snprintf(buffer, 3, &optarg[6]);
                options.near_data[3] = atoi(buffer);
            break;
            
            case 'l':
                options.far_data_len = atoi(optarg);
            break;
            
            case 'f':
                for (i=0; i<options.far_data_len; i++)
                {
                    snprintf(buffer, 3, &optarg[2*i]);
                    options.far_data[i] = atoi(buffer);
                }
            break;

            case 't':
                /* put time into far data */
                options.send_time_snap = true;
            break;

            /* number of messages (loop counter) */
            case 'c':
                options.message_count=strtoul(optarg, NULL, 0);
            break;

            /* message delay */
            case 'd':
                options.message_delay=strtoul(optarg, NULL, 0);
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
    printf("************************************************************************\n");
    printf("** send_basic_message process                                           \n");
    printf("************************************************************************\n");
    printf("**                                                                      \n");
    printf("** usage: send_basic_message [options]                                  \n");
    printf("**                                                                      \n");
    printf("**     Opt.   Description                                    Default    \n");
    printf("**     -h     this help                                                 \n");
    printf("**     -g     message group                                  0          \n");
    printf("**     -e     event                                          0          \n");
    printf("**     -n     near data, always 4byte, NO spaces             -          \n");
    printf("**     -l     length of far data                             0          \n");
    printf("**     -f     far data, requires option -l, NO spaces        -          \n");
    printf("**     -t     put time snapshot into far data (8 bytes)      false      \n");
    printf("**     -c     message count                                  1          \n");
    printf("**     -d     message delay [ms]                             100        \n");
    printf("**                                                                      \n");
    printf("************************************************************************\n");
    printf("\n\n");
}



