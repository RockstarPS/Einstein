/*

 14.07.2011

 VMF Trace Ping
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


/* defs and typedefs */
#define MAX_TEST_CNT            65000
#define VMF_TRID_NAME           "Trace-Ping"
#define VMF_TRACE_TASK          "pingeling"
#define VMF_TRACE_TASK_RESULT   "pingpong"


#ifdef VMF_TRACE
    #define MY_TRACE_ERROR(scope, args...) VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR, VMF_TRACE_TASK, scope, args);
    #define MY_TRACE_PRINTF(scope,args...) VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_13, VMF_TRACE_TASK_RESULT, scope, args);
#else
    #define MY_TRACE_ERROR(scope, args...) printf("vmf_listener: ERROR "); printf(scope), printf(" -- "); printf(args); printf("\n");
    #define MY_TRACE_PRINTF(scope,args...) printf("vmf_listener: INFO  "); printf(scope), printf(" -- "); printf(args); printf("\n");
#endif


typedef struct
{
    unsigned16  message_count;
    unsigned16  delay_ms;
    unsigned8   wait_s;
}options_t;


/* global data */
options_t           options;
unsigned8           vmf_trid;

/* function prototypes */
void vmf_trace_ping(void);
unsigned64 vmf_get_time_snapshot(void);
unsigned64 vmf_get_time_diff(unsigned64 start_time, unsigned64 stop_time);
bool get_options(int argc, char *argv[]);
void usage(void);



int main (int argc, char *argv[])
{
    unsigned8 i;

    if (false == get_options(argc,argv))
    {
        return -1;
    }

    /* Register for VMF Tracer */
    if (VMF_TRACE_REGISTER(&vmf_trid, VMF_TRID_NAME) < 0)
    {
        fprintf(stderr, "vmf_trace_ping: CANNOT CONNECT TO VMF TRACER!!!\n");
    }
    else
    {
        fprintf(stdout, "\n\n\nSET VMF TRACER SEVERITY FOR 'VMF Ping' to <=73 !!!\n\n\n");
    }

    delay(1000);

    MY_TRACE_PRINTF("main", "VMF Trace Ping. PID==%d", getpid());

    MY_TRACE_PRINTF("main", "Options:");
    MY_TRACE_PRINTF("main", "   message count = %d", options.message_count);
    MY_TRACE_PRINTF("main", "   delay [ms]    = %d", options.delay_ms);
    MY_TRACE_PRINTF("main", "   wait [s]      = %d", options.wait_s);
    

    for (i=options.wait_s; i>0; i--)
    {
        MY_TRACE_PRINTF("main", "%d seconds till start!", i);
        delay(1000);
    }

    vmf_trace_ping();

    MY_TRACE_PRINTF("main", "FINISHED!!!");
    printf("vmf_trace_ping main: FINISHED!\n");

  	return 0;
}



/*****************************************************************************
 *
 *   Function Name: vmf_trace_ping()
 *
 *   Description:   start the trace pinger
 *
 *   Parameters:    void
 *
 *   Return :       void
 *
 ******************************************************************************/
void vmf_trace_ping(void)
{
    unsigned64  my_time;
    unsigned16  test_cnt;

    for (test_cnt=0; test_cnt<options.message_count; test_cnt++)
    {
        my_time = vmf_get_time_snapshot();
        MY_TRACE_PRINTF("vmf_trace_ping", "HelloWorld -- time == %lld -- count == %d", my_time, (int)test_cnt);
        delay(options.delay_ms);
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
 *   Function Return value: actual time [ns] (from 1970)
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
        MY_TRACE_ERROR("vmf_get_time_snapshot", "clock_gettime() failed!!!\n");
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
        MY_TRACE_ERROR("vmf_get_time_diff", "start > stop !!!");
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

    if (1==argc)
    {
        /* call without any argument */
        MY_TRACE_ERROR("get_options", "NO parameters -- nothing done!");
        usage();
        return false;
    }

    /* initialize options */
    options.message_count = 0;
    options.delay_ms = 0;
    options.wait_s = 0;

    while ((c = getopt(argc, argv, "hc:d:w:")) != -1)
    {
        switch (c)
        {
            case 'h':
                usage();
                return false;
            break;

            /* number of messages (loop counter) */
            case 'c':
                options.message_count=strtoul(optarg, NULL, 0);
                if (options.message_count > MAX_TEST_CNT)
                {
                    options.message_count = MAX_TEST_CNT;
                }
            break;

            /* delay ms*/
            case 'd':
                options.delay_ms = atoi(optarg);
            break;

            /* wait s*/
            case 'w':
                options.wait_s = atoi(optarg);
            break;

            default :
                /* unknown option */
                MY_TRACE_PRINTF("get_options","%c is an unknown option!", c);
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
    printf("***************************************************************\n");
    printf("** VMF Trace Pinger                                          **\n");
    printf("***************************************************************\n");
    printf("**                                                           **\n");
    printf("** usage: vmf_trace_ping [options]                           **\n");
    printf("**     -h     this help                                      **\n");
    printf("**     -c     message count                                  **\n");
    printf("**     -d     delay between messages [ms]                    **\n");
    printf("**     -w     wait before run [s]                            **\n");
    printf("**                                                           **\n");
    printf("***************************************************************\n");
}



