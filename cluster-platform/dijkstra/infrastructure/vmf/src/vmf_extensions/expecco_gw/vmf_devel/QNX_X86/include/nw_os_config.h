/*****************************************************************************/
/* Copyright Statement                                                       */
/* CONFIDENTIAL - VISTEON CORPORATION                                        */
/* This is an unpublished work, which contains trade secrets, created in     */
/* 2008. Visteon Corporation owns all rights to this work and intends        */
/* to maintain it in confidence to preserve its trade secret status. Visteon */
/* Corporation reserves the right, under the copyright laws of the United    */
/* States or those of any other country that may have jurisdiction, to       */
/* protect this work as an unpublished copyright work in the event of an     */
/* inadvertent or deliberate unauthorized publication. Visteon Corporation   */
/* also reserves its rights under the copyright laws to protect this work    */
/* as a published work, when appropriate. Those having access to this work   */
/* may not copy it, use it or disclose the information contained in it       */
/* without the written authorization of Visteon Corporation.                 */
/*****************************************************************************/

/*************************************************************************//**

  \file                 nw_os_config.h
  \brief                Operating system abstraction layer QNX version

  \author               Joerg Merkle, Joachim Becker  30 May 2012
  \author               Visteon Deutschland GmbH, Infotainment Software

  *****************************************************************************/
#ifndef __NW_OS_CONFIG__
#define __NW_OS_CONFIG__


#include <sys/neutrino.h>
#include <inttypes.h>
#include <atomic.h>

/* POSIX includes */
#include <pthread.h>
#include  <signal.h>

#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <sys/time.h>
#include <sys/debug.h>

#include <dirent.h>
#include <fcntl.h>           /* For O_* constants */
#include <syslog.h>
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <semaphore.h>
#include <stdarg.h>

#include <sched.h>
#include <sys/un.h>
#include <assert.h>
#include <limits.h>
#include <netdb.h>

/* OSAL */
#ifndef OS_TYPES_H
#include <os_types.h>
#endif

#ifdef ENABLE_OSAL_ASYNC
#include <os_event.h>
#include <os_if.h>
#endif /* ENABLE_OSAL_ASYNC */


/* external functions (not defined in atomic.h!) */
extern unsigned atomic_add_value(volatile unsigned *__loc, unsigned __incr);
extern unsigned atomic_sub_value(volatile unsigned *__loc, unsigned __decr);
extern void atomic_sub(volatile unsigned *__loc, unsigned __decr);
extern void atomic_add(volatile unsigned *__loc, unsigned __incr);


/*****************************************************************************/
/* constants                                                            */
/*****************************************************************************/
#ifndef __QNX__
#define __QNX__
#endif
#define VMF_OS_STRING               "vmf for qnx"
#define VMF_PROJECT_STRING          "NISSAN"
#define DOMAINSOCKET_WBUFF_SIZE     200000      /* size of domain socket tx buffer */

#define ERROR_CHANNEL       stdout


/*****************************************************************************/
/* Time functions                                                            */
/*****************************************************************************/
#define delay(ms)           \
    if (ms == 0)            \
    {                       \
        nw_sleep_us(20);         \
    }                       \
    else                    \
    {                       \
        nw_sleep_us(ms*1000);    \
    }


#define NW_COMPILER_MESSAGE(msg)  DO_PRAGMA(message #msg)
#ifdef DC15
#define DO_PRAGMA(x)              /* will cause compiler warnings, which are treated as errors */
#else
#define DO_PRAGMA(x)              _Pragma(#x)
#endif
#ifndef nw_assert
    #define nw_assert(x)              /* assert(x) */
#endif

#define MAX_PROGNAME_LEN            40

/*****************************************************************************/
/* Windsock wrapper                                                         */
/*****************************************************************************/
#define WSAStartup(...)     (0)
#define WSACleanup(...)
#define WSAGetLastError()   errno
#define SOCKADDR_IN         struct sockaddr_in
#define SOCKADDR            struct sockaddr
#define SOCKET              int
#define SOCKET_ERROR        (-1)
#define INVALID_SOCKET      (-1)
#define closesocket(s)      close(s)
#define BACKLOG             (20)
#define _TCHAR              char


/*****************************************************************************/
/* Memory functions                                                          */
/*****************************************************************************/
#define NW_MEMCOPY(sink,source,length) memcpy(sink,source,length)


/*****************************************************************************/
/* atomic functions                                                          */
/*****************************************************************************/

    #define nw_atomic_add(loc,incr)             atomic_add(loc,incr) 
    #define nw_atomic_set_value(loc, val)       atomic_set_value(loc, val)
    #define nw_atomic_add_value(loc,incr)       atomic_add_value(loc,incr)          /* return = old value */
    #define nw_atomic_dec(loc)                  atomic_sub_value(loc,1)             /* return = new value */
    #define nw_atomic_inc(loc)                  atomic_add_value(loc,1)              /* return = new value */


/*****************************************************************************/
/* File/system functions                                                     */
/*****************************************************************************/
#define NW_SYS_REMOVE   "rm -f"            	/* QNX system command to remove file */
#define NW_REMOVE       remove             	/* QNX system command to remove file */
#define PATH_DELIMITER	"/"					/* QNX path delimiter */


#ifndef PATH_MAX
#define PATH_MAX 512
#endif

/*****************************************************************************/
/* function MACROS                                                           */
/*****************************************************************************/

/* semaphore MACROS */
#define nw_sem_open         sem_open
#define nw_sem_close        sem_close
#define nw_sem_init         sem_init
#define nw_sem_destroy      sem_destroy
#define nw_sem_unlink       sem_unlink
#define nw_sem_wait         sem_wait
#define nw_sem_timedwait    sem_timedwait
#define nw_sem_trywait      sem_trywait
#define nw_sem_post         sem_post
#define nw_sem_getvalue     sem_getvalue


/*****************************************************************************/
/* functions prototypes                                                    */
/*****************************************************************************/
unsigned32  nw_os_getpid(void);
unsigned32  nw_os_cfg_get_ms_time(void);
unsigned32  nw_os_cfg_convert_clocks_to_ms_time(unsigned64 clocks);
unsigned64  nw_os_cfg_get_us_time(void);
unsigned64  nw_os_cfg_get_ns_time(void);
bool        nw_os_set_queue_size(unsigned16 q_size);
int         nw_os_sem_timedwait(sem_t *sem,unsigned16 ms_time);
void *      nw_os_malloc(size_t size);
void        nw_os_free(void *ptr);
void        nw_os_set_thread_name(pthread_t th,char *thread_name);
void        nw_os_set_current_thread_name (char *thread_name);
void *      nw_os_smemcpy(void *dest, size_t dest_len, void* src, size_t src_len);
#define     nw_sleep_us(waitTime) usleep(waitTime)
#define     nw_sleep_ms(ms_time)  delay(ms_time)


#define     NW_OS_ALLWAYS_USE_SEM_WAIT
#ifdef      NW_OS_ALLWAYS_USE_SEM_WAIT
int         nw_os_sem_wait(sem_t *sem);
#else
    #define nw_os_sem_wait(sem) sem_wait(sem) 
#endif
#define     nw_os_sem_trywait(sem)  sem_trywait(sem)
#define     nw_shm_close(fd)        close(fd)

int         nw_shm_create(const char *object_name, mode_t mode,size_t len);
int         nw_shm_open(const char *object_name);
int         nw_get_app_name(char *buffer, int buffer_len);
int         nw_strncasecmp(const char *s1, const char *s2, size_t n);

#endif /* __NW_OS_CONFIG__ */

