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

#pragma GCC diagnostic ignored "-Wpragmas"

/* Windows includes */
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif
#include <windows.h>

/* POSIX includes */
#include <pthread.h>
#include <signal.h>

#include <sys/types.h>
#include <dirent.h>
#include <ctype.h>
#include <sched.h>

#include <unistd.h>
#include <sys/stat.h>        /* For mode constants */
#include <sys/time.h>
#include <fcntl.h>           /* For O_* constants */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <semaphore.h>
#include <stdarg.h>

#include <assert.h>

#include <limits.h>

#include <windows.h>
#include <process.h>
#include <malloc.h>
#include <getopt.h>

/* OSAL */
#ifndef OS_TYPES_H
#include <os_types.h>
#endif

#ifdef ENABLE_OSAL_ASYNC
#include <os_event.h>
#endif /* ENABLE_OSAL_ASYNC */

#include "nw_config.h"


/*! Macro to suppress Compiler warning of un-referenced variables */
#ifndef UNUSED_PARAM
#define UNUSED_PARAM(x) ((void)(x))
#endif

/*****************************************************************************/
/* constants                                                            */
/*****************************************************************************/
#ifndef __WINDOWS__
#define __WINDOWS__
#endif
#undef WIN32
#define VMF_OS_STRING               "vmf for Windows"
//#define VMF_PROJECT_STRING          "WINDOWS"
#define DOMAINSOCKET_WBUFF_SIZE     200000      /* size of domain socket tx buffer */

#define ERROR_CHANNEL               stdout

/*****************************************************************************/
/* Time functions                                                            */
/*****************************************************************************/
#define delay(ms)   (void) Sleep(ms)




#define NW_COMPILER_MESSAGE(msg)  DO_PRAGMA(message #msg)
#define DO_PRAGMA(x)              _Pragma(#x)
#ifndef nw_assert
    #define nw_assert(x)              /* assert(x) */
#endif



/*****************************************************************************/
/* Memory functions                                                          */
/*****************************************************************************/
#define NW_MEMCOPY(sink,source,length) memcpy(sink,source,length)


/*****************************************************************************/
/* atomic functions                                                          */
/*****************************************************************************/
// #define nw_atomic_add(loc,incr)        (void)__sync_fetch_and_add(loc,incr);
//#define nw_atomic_set_value(loc, val)  (void)__sync_lock_test_and_set(loc,val)
//#define nw_atomic_add_value(loc,incr)  __sync_fetch_and_add(loc,incr);          /* return = old value */
//#define nw_atomic_dec(loc)             InterlockedDecrement(loc);             /* return = new value */
//#define nw_atomic_inc(loc)             InterlockedIncrement(loc);             /* return = new value */

 /* return = new value */
static inline int32_t nw_atomic_inc(unsigned *p_location)
{
    return InterlockedIncrement((LPLONG)p_location);
}

/* return = new value */
static inline int32_t nw_atomic_dec(unsigned *p_location)
{
    return InterlockedDecrement((LPLONG)p_location);
}

/* return = old value */
static inline unsigned nw_atomic_add_value(unsigned *p_location, unsigned amount)
{
    unsigned cnt;
    unsigned result = 0;

    for (cnt=0; cnt<amount; cnt++)
    {
        result = nw_atomic_inc(p_location); /* return = new value */
    }
    return (unsigned)(result-amount);
}





/*****************************************************************************/
/* File/system functions                                                     */
/*****************************************************************************/
#define NW_SYS_REMOVE   "del /F /Q "            /* Windows system command to remove file */
#define NW_REMOVE     remove               /* Linux system command to remove file */
#define PATH_DELIMITER  "\\"                /* QNX path delimiter */

#ifndef PATH_MAX
#define PATH_MAX 512
#endif

#ifndef MAP_FAILED
#define MAP_FAILED (void*)(-1)
#endif

#define MAX_PROGNAME_LEN            40

#ifndef PROT_READ
#define PROT_READ   0x1     /* page can be read */
#define PROT_WRITE  0x2     /* page can be written */
#define PROT_EXEC   0x4     /* page can be executed */
#define PROT_SEM    0x8     /* page may be used for atomic ops */
#define PROT_NONE   0x0     /* page can not be accessed */
#define PROT_GROWSDOWN  0x01000000  /* mprotect flag: extend change to start of growsdown vma */
#define PROT_GROWSUP    0x02000000  /* mprotect flag: extend change to end of growsup vma */

#define MAP_SHARED  0x01        /* Share changes */
#define MAP_PRIVATE 0x02        /* Changes are private */
#define MAP_TYPE    0x0f        /* Mask for type of mapping */
#define MAP_FIXED   0x10        /* Interpret addr exactly */
#define MAP_ANONYMOUS   0x20        /* don't use a file */
#ifdef CONFIG_MMAP_ALLOW_UNINITIALIZED
# define MAP_UNINITIALIZED 0x4000000    /* For anonymous mmap, memory could be uninitialized */
#else
# define MAP_UNINITIALIZED 0x0      /* Don't support this flag */
#endif
#endif

#ifndef SEM_FAILED
#define SEM_FAILED      ((sem_t *) 0)
#endif

#define timer_t     UINT_PTR
#define clockid_t   int
#define __time_t    int
union sigval
{                /* Data passed with notification */
   int     sival_int;         /* Integer value */
   void   *sival_ptr;         /* Pointer value */
};

struct sigevent
{
   int          sigev_notify; /* Notification method */
   int          sigev_signo;  /* Notification signal */
   union sigval sigev_value;  /* Data passed with
                                 notification */
   void       (*sigev_notify_function) (union sigval);
                              /* Function used for thread
                                 notification (SIGEV_THREAD) */
   void        *sigev_notify_attributes;
                              /* Attributes for notification thread
                                 (SIGEV_THREAD) */
   pid_t        sigev_notify_thread_id;
                              /* ID of thread to signal (SIGEV_THREAD_ID) */
};


enum
{
    SIGEV_SIGNAL = 0,     /* Notify via signal.  */
    # define SIGEV_SIGNAL   SIGEV_SIGNAL
    SIGEV_NONE,           /* Other notification: meaningless.  */
    # define SIGEV_NONE SIGEV_NONE
    SIGEV_THREAD,         /* Deliver via thread creation.  */
    # define SIGEV_THREAD   SIGEV_THREAD

    SIGEV_THREAD_ID = 4       /* Send signal to specific thread.  */
    #define SIGEV_THREAD_ID SIGEV_THREAD_ID
};
#define CLOCK_REALTIME 0


#ifndef HAVE_STRUCT_TIMESPEC
#define HAVE_STRUCT_TIMESPEC
struct timespec
{
    __time_t tv_sec;        /* Seconds.  */
    long int tv_nsec;       /* Nanoseconds.  */
};
#endif /* HAVE_STRUCT_TIMESPEC */


#ifdef NEED_STRUCT_I_TIMERSPEC
struct itimerspec
{
    struct timespec it_interval;
    struct timespec it_value;
};
#endif /* NEED_STRUCT_I_TIMERSPEC */


/* Socket definitions */
#define BACKLOG             (20)
#ifndef EWOULDBLOCK
#define EWOULDBLOCK         WSAEWOULDBLOCK
#endif
typedef int socklen_t;

/*****************************************************************************/
/*  MACROS                                                           */
/*****************************************************************************/

/* semaphore MACROS */
//#define nw_sem_init         sem_init

#define nw_sem_destroy      sem_destroy
#define nw_sem_unlink       sem_unlink
#define nw_sem_wait         sem_wait
#define nw_sem_timedwait    sem_timedwait
#define nw_sem_trywait      sem_trywait
#define nw_sem_getvalue     sem_getvalue

/* share memory */
#ifndef O_RDONLY
#define O_RDONLY        0x0
#endif
#ifndef O_RDWR
#define O_RDWR          0x2
#endif
#if 0
#ifndef O_CREATE
#define O_CREATE        0x40
#endif
#endif
#ifndef O_TRUNC
#define O_TRUNC         0x200
#endif
#ifndef O_EXCL
#define O_EXCL          0x2
#endif
#define NW_MAX_SHM_SIZE    5000000L

/*****************************************************************************/
/* function prototypes                                                       */
/*****************************************************************************/
unsigned32  nw_os_gettid(void);
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
void        nw_sleep_us(int waitTime);
#define     nw_sleep_ms(ms_time) (void) Sleep(ms_time)

#define     NW_OS_ALLWAYS_USE_SEM_WAIT
#ifdef      NW_OS_ALLWAYS_USE_SEM_WAIT
int         nw_os_sem_wait(sem_t *sem);
#else
    #define nw_os_sem_wait(sem) sem_wait(sem)
#endif
#define     nw_os_sem_trywait(sem)  sem_trywait(sem)
sem_t       *nw_sem_open (const char *name, int oflag, ...);
int         nw_sem_init (sem_t * sem, int pshared, unsigned int value);
int         nw_sem_close(sem_t *sem);
int         nw_sem_post(sem_t *sem);


/* posix functions */
int         shm_open(const char *name, int oflag, mode_t mode);
int         shm_unlink(const char *name);
pid_t       getpid(void);
void        *mmap(void *addr, size_t len, int prot, int flags,int fildes, _off_t off);
int         munmap(void *addr, size_t len);
void        nw_shm_close(int fd);

int         timer_create(clockid_t clockid, struct sigevent *sevp,timer_t *timerid);
int         timer_settime(timer_t timerid, int flags,const struct itimerspec *new_value,struct itimerspec * old_value);
int         timer_delete(timer_t timerid);
int         nw_shm_create(const char *object_name, mode_t mode,size_t len);
int         nw_shm_open(const char *object_name);
char        *PathFindFileName(char *full_path);
int         nw_get_app_name(char *buffer, int buffer_len);
int         nw_strncasecmp(const char *s1, const char *s2, size_t n);
int         mkfifo(const char *pathname, mode_t mode);

bool        nw_os_target_log_init(const char *init_string);
bool        nw_os_target_log(unsigned int severity, char *log_message);

#ifndef FTRUNCATE_DEFINED
#define FTRUNCATE_DEFINED
int ftruncate(int, _off_t);
__CRT_INLINE int ftruncate(int __fd, _off_t __length)
{
  return _chsize (__fd, __length);
}
#endif
#endif /* __NW_OS_CONFIG__ */

