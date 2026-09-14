/*

 12.03.2012

 VMF Trace Weird
 by J. Merkle

 Send chaotic VMF Tracer messages

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
#define VMF_TRID_NAME           "TraceWeird"
#define VMF_TRACE_TASK          "HollaDieWaldfee"

#define MY_TRACE_ERROR(scope, args...)   VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR, VMF_TRACE_TASK, scope, args);
#define MY_TRACE_PRINTF(scope,args...)   VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_13, VMF_TRACE_TASK, scope, args);

#define YOUR_TRACE_ERROR(task, args...)  VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR, task, "your scope", args);
#define YOUR_TRACE_PRINTF(task, args...) VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_13, task, "your scope", args);

#define MY_DELAY                1000


/* global data */
static unsigned8  vmf_trid;


int main (int argc, char *argv[])
{

    /* Register for VMF Tracer */
    if (VMF_TRACE_REGISTER(&vmf_trid, VMF_TRID_NAME) < 0)
    {
        fprintf(stderr, "Trace Weird: CANNOT CONNECT TO VMF TRACER!!!\n");
    }

    delay(1000);

    MY_TRACE_PRINTF("main", "VMF Trace Weird. PID==%d", getpid());

    while (1)
    {

        YOUR_TRACE_PRINTF("Message 1", "This is message 1");
        delay(MY_DELAY);
        YOUR_TRACE_ERROR("Error 1", "Error 1");
        delay(MY_DELAY);
        YOUR_TRACE_ERROR("Error 1", "Hello,");
        delay(MY_DELAY);
        YOUR_TRACE_PRINTF("Message 2", "This is message 2");
        delay(MY_DELAY);
        YOUR_TRACE_ERROR("Error 1", "this");
        delay(MY_DELAY);
        YOUR_TRACE_ERROR("Error 1", "an");
        delay(MY_DELAY);
        YOUR_TRACE_ERROR("Error 1", "error!!!");
        delay(MY_DELAY);
        YOUR_TRACE_PRINTF("Message 2", "This is message 2");
        delay(MY_DELAY);
        YOUR_TRACE_ERROR("Error 2", "Error 2");
        delay(MY_DELAY);
        YOUR_TRACE_PRINTF("Message 3", "This is message 3");
        delay(MY_DELAY);
        YOUR_TRACE_ERROR("Error 3", "Error 3");
        delay(MY_DELAY);
        YOUR_TRACE_PRINTF("Message 2", "This is message 2");
        delay(MY_DELAY);
        YOUR_TRACE_ERROR("Error 4", "Error 4");
        delay(MY_DELAY);
        YOUR_TRACE_PRINTF("Message 1", "This is message 1");
        delay(MY_DELAY);
        YOUR_TRACE_ERROR("Error 5", "Error 5");
        delay(MY_DELAY);
        YOUR_TRACE_PRINTF("Message 3", "This is message 3");
        delay(MY_DELAY);

    }

    MY_TRACE_PRINTF("main", "FINISHED!!!");

  	return 0;
}



