/*
test of vmf_timed_receive
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
#define MAX_FAR_DATA_LEN        4062

#define VMF_TRID_NAME           "vmf_timed_receive"
#define VMF_TRACE_TASK          "test"
#define VMF_TRACE_TASK_RESULT   "Result"


#ifdef VMF_TRACE
    #define VMF_TRACE_ERROR(scope, args...) VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR, VMF_TRACE_TASK, scope, args);
    #define VMF_TRACE_INFO(args...)       VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_13, VMF_TRACE_TASK_RESULT, "result", args);
#else
    #define VMF_TRACE_ERROR(scope, args...) printf("vmf_listener: ERROR "); printf(scope), printf(" -- "); printf(args); printf("\n");
    #define VMF_TRACE_INFO(args...)       printf("vmf_listener: "); printf(args); printf("\n");
#endif


/* global data */
unsigned8           vmf_trid;

/* function prototypes */
void vmf_receiver(unsigned8 my_message_group);



int main (int argc, char *argv[])
{
    vmf_ret_t   vmf_result;


    VMF_VAR_BASIC_MSG_TYP(10) msg;
    vmf_basic_msg_t *pmsg = (vmf_basic_msg_t *)&msg;

    /* Register for VMF Tracer */
    if (VMF_TRACE_REGISTER(&vmf_trid, VMF_TRID_NAME) < 0)
    {
        fprintf(stderr, "vmf_timed_receive: CANNOT CONNECT TO VMF TRACER!!!\n");
    }

    delay(1000);

    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_10, VMF_TRACE_TASK, "main", "vmf_timed_receive test startet. PID==%d", getpid());


    /* now receive message in forever */
    vmf_receiver(111);


    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_10, VMF_TRACE_TASK, "main", "FINISHED!!!");
    printf("vmf_timed_receive main: FINISHED!\n");

    return 0;
}



/*****************************************************************************
 *
 *   Function Name: vmf_receiver(unsigned8 my_message_group)
 *
 *   Description:   start the vmf_timed_receive test
 *
 *   Parameters:    receiver message group
 *
 *   Return :       my_message_group - message to be registered at vmf
 *
 ******************************************************************************/
void vmf_receiver(unsigned8 my_message_group)
{
    VMF_VAR_MSG_TYP(MAX_FAR_DATA_LEN)   my_msg;
    vmf_client_id_t     my_rx_id;
    vmf_ret_t           my_ret;
    unsigned16          my_len;
    unsigned16          test_cnt;
    char                myName[31];


    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_20, VMF_TRACE_TASK, "vmf_timed_receive", "Start");

    /* connect VMF */
    sprintf(myName,"test_vmf_timed_receive");
    my_rx_id = nw_vmf_connect(myName, NULL, 0, 100, sizeof(my_msg));
    if (my_rx_id < 0)
    {
        VMF_TRACE_ERROR("vmf_receiver", "nw_vmf_connect() failed - error==%d",my_rx_id);
        return;
    }

    /* register message group */
    my_ret = nw_vmf_register_msg_group (my_rx_id, 1, &my_message_group);
    if (my_ret < 0)
    {
        VMF_TRACE_ERROR("vmf_receiver", "nw_vmf_register_msg_group() failed - error=%d\n",my_ret);
        return;
    }

    VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_20, VMF_TRACE_TASK, "vmf_receiver", "Test-receiver connected - start reception.");

    test_cnt =0;
    while (test_cnt < 10)
    {

        VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_20, VMF_TRACE_TASK, "vmf_receiver", "start vmf_timed_receive(500)");
        my_len = nw_vmf_timed_receive (my_rx_id, (vmf_msg_t*)&my_msg, sizeof(my_msg),500);

		if (my_len < 0)
		{
            VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_20, VMF_TRACE_TASK, "vmf_receiver", "vmf_timed_receive error = %d",my_len);
            delay(50); /* wait some ms to prevent CPU lock in case of error*/
		}
        else if(0 == my_len)
		{
            VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_20, VMF_TRACE_TASK, "vmf_receiver", "vmf_timed_receive timeout");
		}
        else
		{
            VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_20, VMF_TRACE_TASK, "vmf_receiver", "vmf_timed_receive received %d bytes of data",my_len);
		}
        test_cnt++;
   }
}

