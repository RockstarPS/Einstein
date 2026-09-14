#ifndef __NW_OS_CONFIG__
#define __NW_OS_CONFIG__

    /* QNX includes */
#include <assert.h>
#include <dirent.h>
/* jmerkle  #include <dlfcn.h> */
#include <errno.h>
/* jmerkle  #include <fcntl.h> */
/* jmerkle  #include <semaphore.h> */
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
/* jmerkle  #include <sys/mman.h> */
/* jmerkle  #include <sys/stat.h> */
#include <sys/types.h>
/* jmerkle  #include <syslog.h> */
#include <time.h>
#include <unistd.h>
/* jmerkle  #include <sys/socket.h>  */
/* jmerkle  #include <netinet/in.h> */
/* jmerkle  #include <arpa/inet.h> */
#include <mqueue.h>



/* POSIX includes */
#if !defined( PTHREAD_H )
#include <pthread.h>
#endif

/* OSAL */
#ifndef OS_TYPES_H
#include <os_types.h>
#endif


#define NW_MEMCOPY(sink,source,length) 	memcpy(sink,source,length)
#define NW_GET_PID()					getpid()
#define NW_GET_CLOCK_CYCLES()			ClockCycles()

#endif /* __NW_OS_CONFIG__ */

