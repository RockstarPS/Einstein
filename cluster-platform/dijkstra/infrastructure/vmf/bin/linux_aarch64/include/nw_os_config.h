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
  \brief                Operating system abstraction layer

  \author               Joerg Merkle
  \author               Visteon Deutschland GmbH, Infotainment Software

  *****************************************************************************/
#ifndef __NW_OS_CONFIG__
#define __NW_OS_CONFIG__


/* POSIX includes */
#include <pthread.h>
#include <signal.h>

#include <sys/types.h>
#include <dirent.h>
#include <ctype.h>
#include <sched.h>
#include <syslog.h>

#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <sys/time.h>
#include <sys/prctl.h>
#include <fcntl.h>           /* For O_* constants */
#include <dlfcn.h>

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <semaphore.h>
#include <stdarg.h>

#include <sys/un.h>
#include <assert.h>

#include <limits.h>
#include <netdb.h>

#include <syslog.h>

/* OSAL */
#ifndef OS_TYPES_H
#include <os_types.h>
#endif

#ifdef ENABLE_OSAL_ASYNC
#include <os_event.h>
#endif /* ENABLE_OSAL_ASYNC */

/*! Macro to suppress Compiler warning of un-referenced variables */
#ifndef UNUSED_PARAM
#define UNUSED_PARAM(x) ((void)(x))
#endif


/*****************************************************************************/
/* constants                                                            */
/*****************************************************************************/
#ifndef __LINUX__
#define __LINUX__
#endif
#define VMF_OS_STRING               "VMF for Linux"
#define DOMAINSOCKET_WBUFF_SIZE     200000      /* size of domain socket tx buffer */

#define ERROR_CHANNEL       stdout

/*****************************************************************************/
/* Time functions                                                            */
/*****************************************************************************/
/* jmerkle  #define delay(t)    (void)(t) */
/* jmerkle  #define delay(ms)   usleep(ms*1000); */
#define delay(ms)           \
    if (ms == 0)            \
    {                       \
        (void) nw_sleep_us(20);         \
    }                       \
    else                    \
    {                       \
        (void) nw_sleep_us(ms*1000);    \
    }




#define NW_COMPILER_MESSAGE(msg)  DO_PRAGMA(message #msg)
#define DO_PRAGMA(x)              _Pragma(#x)
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

#ifdef __GNUC__
/*
    NW_COMPILER_MESSAGE("__sync functions used for atomic")
*/
    #define nw_atomic_add(loc,incr)        (void)__sync_fetch_and_add(loc,incr);
    #define nw_atomic_set_value(loc, val)  (void)__sync_lock_test_and_set(loc,val)
    #define nw_atomic_add_value(loc,incr)  __sync_fetch_and_add(loc,incr);          /* return = old value */
    #define nw_atomic_dec(loc)             __sync_sub_and_fetch(loc,1);             /* return = new value */
    #define nw_atomic_inc(loc)             __sync_add_and_fetch(loc,1);             /* return = new value */


#else
    NW_COMPILER_MESSAGE("__sync functions not supported - using replacement functions")


    #define nw_atomic_set_value(v, i) (*v = (i))
    #define nw_atomic_add(v, i) (void)atomic_add_value(v,i) // (*v += (i))

    static inline unsigned nw_atomic_add_value(volatile unsigned * loc, unsigned incr)
    {
        unsigned ret = 0;
        ret = *loc;
        *loc +=incr;
        return ret;
   }

   /* dec and return new value */
   static inline unsigned nw_atomic_dec(volatile unsigned * loc)
   {
        unsigned ret = 0;
        *loc -=1;
        ret = *loc;
        return ret;
   }

   /* dec and return new value */
   static inline unsigned nw_atomic_inc(volatile unsigned * loc)
   {
        unsigned ret = 0;
        *loc +=1;
        ret = *loc;
        return ret;
   }

#endif



/*****************************************************************************/
/* File/system functions                                                     */
/*****************************************************************************/
#define NW_SYS_REMOVE   "rm -f"             /* Linux system command to remove file */
#define NW_REMOVE       remove              /* Linux system command to remove file */
#define PATH_DELIMITER  "/"                 /* Linux path delimiter */

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
/* function prototypes                                                       */
/*****************************************************************************/
unsigned32  nw_os_getpid(void);
unsigned64  nw_os_cfg_get_ns_time(void);
unsigned64  nw_os_cfg_get_us_time(void);
unsigned32  nw_os_cfg_get_ms_time(void);
unsigned32  nw_os_cfg_get_ms_time_raw(void);
unsigned32  nw_os_cfg_convert_clocks_to_ms_time(unsigned64 clocks);
bool        nw_os_set_queue_size(unsigned16 q_size);
int         nw_os_sem_timedwait(sem_t *sem,unsigned16 ms_time);
void *      nw_os_malloc(size_t size);
void        nw_os_free(void *ptr);
void        nw_os_set_thread_name(pthread_t th,char *thread_name);
void        nw_os_set_current_thread_name (char *thread_name);
void        nw_os_sstrncpy(char *dest, const char *src, size_t dest_size);
void *      nw_os_smemcpy(void *dest, size_t dest_len, void* src, size_t src_len);
#define     nw_sleep_us(waitTime)  (void) usleep(waitTime)
#define     nw_sleep_ms(ms_time)   delay(ms_time)

#define     NW_OS_ALLWAYS_USE_SEM_WAIT
#ifdef      NW_OS_ALLWAYS_USE_SEM_WAIT
int         nw_os_sem_wait(sem_t *sem);
#else
    #define nw_os_sem_wait(sem) sem_wait(sem)
#endif
#define     nw_os_sem_trywait(sem)  sem_trywait(sem)
#define     nw_shm_close(fd)        (void) close(fd)

int         nw_shm_create(const char *object_name, mode_t mode,size_t len);
int         nw_shm_open(const char *object_name);
int         nw_get_app_name(char *buffer, int buffer_len);
int         nw_strncasecmp(const char *s1, const char *s2, size_t n);

bool        nw_os_target_log_init(const char *init_string);
bool        nw_os_target_log(unsigned int severity, char *log_message);

#endif /* __NW_OS_CONFIG__ */

