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

  \file                 nw_os_config.c
  \brief                Operating system abstraction layer - LINUX version

  \author               Joerg Merkle
  \author               Visteon Deutschland GmbH, Infotainment Software

  \compiler             gcc
  \target               any

  *****************************************************************************/
#define _NW_OS_CONFIG_C_

/* system includes */
#include "nw_os_config.h"

static void nw_os_set_normalized_timespec (struct timespec *ts, unsigned64 sec, unsigned64 nsec);

char        __progname[MAX_PROGNAME_LEN] = {"VMF"};
char        progname[MAX_PROGNAME_LEN] = {0};
unsigned32  ms_time_offset=0;

#define NW_VMF_SHM_IPC_ERROR(...)       (void)fprintf(ERROR_CHANNEL, "VMF_OS_CONFIG_WIN: "__VA_ARGS__); (void)fprintf(ERROR_CHANNEL, "\n");
#define NW_VMF_SHM_IPC_INFO(...)        // (void)fprintf(ERROR_CHANNEL, "VMF_OS_CONFIG_WIN: "__VA_ARGS__); (void)fprintf(ERROR_CHANNEL, "\n");
#define NW_VMF_SHM_IPC_INFO2(...)       (void)fprintf(ERROR_CHANNEL, "VMF_OS_CONFIG_WIN: "__VA_ARGS__); (void)fprintf(ERROR_CHANNEL, "\n");


/**************************************************************************//**
 *
 *   \def           unsigned64 nw_os_cfg_get_ns_time(void)
 *   \brief         Obtain os time in usecs.
 *
 *   \return        unsigned64 -- time in usecs.
 *
 ******************************************************************************/
unsigned64 nw_os_cfg_get_ns_time(void)
{
    struct timeval now;
    unsigned64      time_ns = 0;

    (void) gettimeofday(&now, NULL);
    time_ns = ((unsigned64)now.tv_sec * (unsigned64)1000000000L) + ((unsigned64)now.tv_usec * (unsigned64)1000);

    return time_ns;
}


/**************************************************************************//**
 *
 *   \def           unsigned64 nw_os_cfg_get_us_time(void)
 *   \brief         Obtain os time in usecs.
 *
 *   \return        unsigned64 -- time in usecs.
 *
 ******************************************************************************/
unsigned64 nw_os_cfg_get_us_time(void)
{
    struct timeval now;
    unsigned64      time_us = 0;

    (void) gettimeofday(&now, NULL);
    time_us = ((unsigned64)now.tv_sec * (unsigned64)1000000L) + (unsigned64)(now.tv_usec);

    return time_us;
}

/**************************************************************************//**
 *
 *   \def           unsigned32 nw_os_cfg_get_ms_time(void)
 *   \brief         Obtain os time in milli-secs.
 *
 *   \return        unsigned32 -- time in milli-secs.
 *
 ******************************************************************************/
unsigned32 nw_os_cfg_get_ms_time(void)
{
    return ((unsigned32)(nw_os_cfg_get_us_time()/1000L) + ms_time_offset);
}



/**************************************************************************//**
 *
 *   \def           unsigned32 nw_os_cfg_get_ms_time_raw(void)
 *   \brief         Obtain os time in milli-secs without time sync offset
 *
 *   \return        unsigned32 -- time in milli-secs.
 *
 ******************************************************************************/
unsigned32 nw_os_cfg_get_ms_time_raw(void)
{
    return ((unsigned32)(nw_os_cfg_get_us_time()/1000L));
}



/**************************************************************************//**
 *
 *   \def           unsigned32 nw_os_cfg_convert_clocks_to_ms_time(unsigned64 clocks)
 *   \brief         Convert system clocks to milli-secs.
 *
 *   \param[in]     unsigned64 clocks -- system clock
 *   \return        unsigned32        -- time in milli-secs.
 *
 ******************************************************************************/
unsigned32 nw_os_cfg_convert_clocks_to_ms_time(unsigned64 clocks)
{
    return ((unsigned32)(clocks));
}




/**************************************************************************//**
 *
 *   \def           nw_os_set_queue_size
 *   \brief         set domain socket rx queue size
 *
 *   \param[in]     void
 *   \return        true -- if OK
 *
 ******************************************************************************/
bool nw_os_set_queue_size(unsigned16 q_size)
{
    return true;
}




/**************************************************************************//**
 *
 *   \def           nw_os_set_normalized_timespec
 *   \brief         normalize the timespec struct
 *
 *   \param[in]     pointer to resulting timespec
 *   \param[in]     time in s
 *   \param[in]     time in ns
 *   \return        void
 *
 ******************************************************************************/
static void nw_os_set_normalized_timespec (struct timespec *ts, unsigned64 sec, unsigned64 nsec)
{
#ifndef NSEC_PER_SEC
#define NSEC_PER_SEC (1000000000L)
#endif
volatile unsigned64    mysec=sec;
volatile unsigned64    mynsec=nsec;

    while (mynsec >= NSEC_PER_SEC)
    {
        asm("nop");
        mynsec -= NSEC_PER_SEC;
        ++mysec;
    }
#if 0
    while (mynsec < 0)
    {
        mynsec += NSEC_PER_SEC;
        --mysec;
    }
#endif
    ts->tv_sec = (long)mysec;
    ts->tv_nsec =(long)mynsec;
}


void nw_sleep_us(int waitTime) {
    __int64 time1 = 0, time2 = 0, freq = 0;

    (void) QueryPerformanceCounter((LARGE_INTEGER *) &time1);
    (void) QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

    do {
        (void) QueryPerformanceCounter((LARGE_INTEGER *) &time2);
    } while((time2-time1) < waitTime);
}




/**************************************************************************//**
 *
 *   \def           nw_os_sem_timedwait
 *   \brief         wait for semaphore for nn miliseconds
 *                  see sem_timedwait()
 *   \param[in]     semaphore
 *   \param[in]     timeout in ms
 *   \return        0 if success
 *
 ******************************************************************************/
int nw_os_sem_timedwait(sem_t *sem,unsigned16 ms_time)
{
    struct timeval now;
    struct timespec ts_timeout;
    int s;

    if (0==ms_time)
    {
        ms_time=1;
    }

    /* semaphore with timeout */
    /* get current time */
    (void) gettimeofday(&now, NULL);

    /* add timeout to timespec */
    nw_os_set_normalized_timespec (&ts_timeout, (unsigned64)now.tv_sec, ((unsigned64)now.tv_usec * 1000) + ((unsigned64)ms_time * 1000000L));

    /* restart if interrupted by event */
    errno = 0;
    while ((s = sem_timedwait(sem, &ts_timeout)) == -1 && errno == EINTR)
    {
        nw_sleep_us(0);
    }

    return s;
}




/**************************************************************************//**
 *
 *   \def           nw_os_sem_wait
 *   \brief         wait for semaphore
 *                  see sem_wait()
 *   \param[in]     semaphore
 *   \param[in]     timeout in ms
 *   \return        0 if success
 *
 ******************************************************************************/
#ifdef NW_OS_ALLWAYS_USE_SEM_WAIT
int nw_os_sem_wait(sem_t *sem)
{
/* !! because sem_wait is not working well from inside shared_memory we use sem_timed_wait here !!*/
    errno = 0;
//    NW_VMF_SHM_IPC_ERROR("pid=%d, nw_os_sem_wait: Call nw_os_sem_timedwait",nw_os_getpid());
    while (nw_os_sem_timedwait(sem,500) != 0)
    {
        delay(0);
    }
//    NW_VMF_SHM_IPC_ERROR("pid=%d, nw_os_sem_wait: nw_os_sem_timedwait done",nw_os_getpid());
    return 0;
}
#endif


/**************************************************************************//**
 *
 *   \def           nw_os_sstrncpy()
 *   \brief         save sstrncpy -- avoids out of bound access of dest string 
 *                  and terminates dest always(!) with zero.
 *
 *   \param[in]     dest - pointer to destination buffer
 *   \param[in]     dest_size - size of destination buffer
 *   \param[in]     src - pointer to source buffer
 *   \return        none
 *
 ******************************************************************************/
void nw_os_sstrncpy(char *dest, const char *src, size_t dest_size)
{
    size_t length;
    size_t src_len;

    if (NULL == dest)
    {
        return;
    }
    if (NULL == src)
    {
        return;
    }

    src_len = strlen(src);

    /* will data fit into dest buffer ?*/
    if  (src_len < dest_size)
    {
        length = src_len;
    }
    else
    {
        length = dest_size - 1;
    }

    (void) strncpy(dest, src, length);
    dest[length] = 0;   /* always zero termination */

    return;
}


/**************************************************************************//**
 *
 *   \def           nw_os_smemcpy
 *   \brief         save memcpy
 *
 *   \param[in]     size in bytes
 *   \return        pointer to memory or null
 *
 ******************************************************************************/
void * nw_os_smemcpy(void *dest, size_t dest_len, void* src, size_t src_len)
{
    /* will data fit into dest buffer ?*/
    if (src_len > dest_len)
    {
        return NULL;
    }
    return memcpy(dest,src,src_len);
}

/**************************************************************************//**
 *
 *   \def           nw_os_malloc
 *   \brief         alloc alligned memory
 *
 *   \param[in]     size in bytes
 *   \return        pointer to memory or null
 *
 ******************************************************************************/
void * nw_os_malloc(size_t size)
{
    void * ret_mem_ptr=NULL;

    ret_mem_ptr = __mingw_aligned_malloc(size,sizeof(int *));
    return(ret_mem_ptr);
}


/**************************************************************************//**
 *
 *   \def           nw_os_free
 *   \brief         free allocated memory
 *
 *   \param[in]     size in bytes
 *   \return        pointer to memory or null
 *
 ******************************************************************************/
void nw_os_free(void *ptr)
{
    __mingw_aligned_free(ptr);
}




/**************************************************************************//**
 *
 *   Function Name: nw_os_set_thread_name()
 *
 *   Description:   set the tread name of the thread with the given if
 *
 *   Parameters:    thread handle
 *                  thread name         (input) pointer to thread name\n
 *
 *   Function Return value: - \return void
 *
 ******************************************************************************/
void nw_os_set_thread_name  (pthread_t th,char *thread_name)    /*!< INPUT pointer to thread name */
{
    #ifdef QNX
    #if (_NTO_VERSION >= 632)
    /* name the thread nw vmf NW_STAUS handler */
    if ( pthread_setname_np(th, "nw vmf-mi starter thread") != EOK)
    {
        /* do not report error */
    }
    #endif
    #endif

}

/**************************************************************************//**
 *
 *   Function Name: nw_os_set_current_thread_name()
 *
 *   Description:   set the tread name of the thread with the given if
 *
 *   Parameters:    thread handle
 *                  thread name         (input) pointer to thread name\n
 *
 *   Function Return value: - \return void
 *
 ******************************************************************************/
void nw_os_set_current_thread_name  (char *thread_name)    /*!< INPUT pointer to thread name */
{
 #ifdef PR_SET_NAME
 if (NULL != thread_name)
    {
        prctl(PR_SET_NAME, (unsigned long)thread_name,0,0,0);
    }
 #endif
}




/**************************************************************************//**
 *
 *   Function Name: nw_shm_create()
 *
 *   Description:   create a share memory with a given size
 *
 *   Parameters:    name of the shared memory
 *                  mode
 *                      O_APPEND
 *                      O_ASYNC
 *                      O_CLOEXEC
 *                      O_CREAT
 *                  size of the sharem memory in bytes
 *
 *   Function Return value: - On success, nw_shm_create() returns a nonnegative file descriptor
 *                            On error -1
 *
 ******************************************************************************/
int nw_shm_create(const char *object_name, mode_t mode,size_t len)
{
    HANDLE      shmid;
    DWORD       opt=0;
    int         ret_val = -1;

    if (NULL != object_name)
    {
        NW_VMF_SHM_IPC_INFO("nw_shm_create(%s,%04x)",object_name,oflag);
    }
    else
    {
        NW_VMF_SHM_IPC_INFO("nw_shm_create() name=NULL!!!");
    }

    opt = PAGE_READWRITE;

    /* create or open share memory */
    {
        NW_VMF_SHM_IPC_INFO("nw_shm_create(%s) call CreateFileMapping( %d bytes)",object_name,NW_MAX_SHM_SIZE);
        shmid = CreateFileMapping( (HANDLE) INVALID_HANDLE_VALUE, NULL,
                                   opt,                            /* PAGE_READWRITE | SEC_COMMIT, */
                                   (DWORD) 0,
                                   (DWORD) len,
                                   (LPCTSTR)object_name);
    }

    if (shmid != NULL)
    {
        ret_val = (int)shmid;
    }
    else
    {
        /* creation failed */
        NW_VMF_SHM_IPC_ERROR("nw_shm_create: CreateFileMapping failed");
        ret_val = -1;
    }
    return(ret_val);

}

/**************************************************************************//**
 *
 *   Function Name: nw_shm_open()
 *
 *   Description:   open a shared memory segment
 *
 *   Parameters:    name of the shared memory
 *
 *   Function Return value: - On success, nw_shm_open() returns a nonnegative file descriptor
 *                            On error -1
 *
 ******************************************************************************/
int nw_shm_open(const char *object_name)
{
    int fd = -1;

    fd = shm_open(object_name,O_RDWR,0);

    return fd;
}



/**************************************************************************//**
 *
 *   Function Name: shm_open()
 *
 *   Description:   emulation of POSIX function shm_open
 *
 *   Parameters:    name of the shared memory
 *                  oflag bitmask
 *                      O_RDONLY
 *                      O_RDWR
 *                      O_CREAT
 *                      O_EXCL
 *                      O_TRUNC
 *                  mode
 *                      O_APPEND
 *                      O_ASYNC
 *                      O_CLOEXEC
 *                      O_CREAT
 *
 *   Function Return value: - On success, shm_open() returns a nonnegative file descriptor
 *                            On error -1
 *
 ******************************************************************************/
int shm_open(const char *object_name, int oflag, mode_t mode)
{
    HANDLE      shmid;
    DWORD       opt=0;
    int         ret_val = -1;
    bool        do_create=false;

    if (NULL != object_name)
    {
        NW_VMF_SHM_IPC_INFO("shm_open(%s,%04x)",object_name,oflag);
    }
    else
    {
        NW_VMF_SHM_IPC_INFO("shm_open() name=NULL!!!");
    }

    if (oflag == O_RDONLY)
    {
        NW_VMF_SHM_IPC_INFO("shm_open(%s) - O_RDONLY",object_name);
    }
    if (oflag & O_RDWR)
    {
        NW_VMF_SHM_IPC_INFO("shm_open(%s) - O_RDWR",object_name);
    }
    opt = PAGE_READWRITE;


    if (oflag & O_CREAT)
    {
        do_create =  true;
        NW_VMF_SHM_IPC_INFO("shm_open(%s) - O_CREATE",object_name);
    }
    if (oflag & O_EXCL)
    {
        NW_VMF_SHM_IPC_INFO("shm_open(%s) - O_EXCL",object_name);
    }
    if (oflag & O_TRUNC)
    {
        NW_VMF_SHM_IPC_INFO("shm_open(%s) - O_TRUNC",object_name);
    }


    /* create or open share memory depending on O_CREAT*/
    if (do_create)
    {
        NW_VMF_SHM_IPC_INFO("shm_open(%s) call CreateFileMapping( %d bytes)",object_name,NW_MAX_SHM_SIZE);
        shmid = CreateFileMapping( (HANDLE) INVALID_HANDLE_VALUE, NULL,
                                   opt,                            /* PAGE_READWRITE | SEC_COMMIT, */
                                   (DWORD) 0,
                                   (DWORD) NW_MAX_SHM_SIZE,         /* sizeof(vmf_msg_queue_shm_t)+3, */
                                   (LPCTSTR)object_name);

    }
    else
    {
        NW_VMF_SHM_IPC_INFO("shm_open(%s) call OpenFileMapping()",object_name);
        shmid = OpenFileMapping ( FILE_MAP_WRITE | FILE_MAP_READ,true,(LPCTSTR)object_name);
    }

    if (shmid != NULL)
    {
        ret_val = (int)shmid;
    }
    else
    {
        /* creation failed */
        NW_VMF_SHM_IPC_ERROR("shm_open: CreateFileMapping failed");
        ret_val = -1;
    }
    return(ret_val);
}


/**************************************************************************//**
 *
 *   Function Name: mmap()
 *
 *   Description:   emulation of POSIX function mmap
 *
 *   Parameters:
 *
 *   Function Return value:   Upon successful completion, the mmap() function returns the address at which the mapping
 *                            MAP_FAILED (-1)- on error
 *
 ******************************************************************************/
void *mmap(void *addr, size_t len, int prot, int flags,int fildes, off_t off)
{
/*    map a view of the file mapped object */
    HANDLE  shmid;
    LPVOID  shm_bufferarea=NULL;

    NW_VMF_SHM_IPC_INFO("mmap: fd=%d",fildes);

    if (len > NW_MAX_SHM_SIZE)
    {
        NW_VMF_SHM_IPC_ERROR("mmap: failed len > NW_MAX_SHM_SIZE");
        return MAP_FAILED;
    }

    shmid = (HANDLE)fildes;
    shm_bufferarea = MapViewOfFile(shmid,
                                   FILE_MAP_WRITE | FILE_MAP_READ, // FILE_MAP_ALL_ACCESS,
                                   0, 0, len);

    if (shm_bufferarea == NULL)
    {
        NW_VMF_SHM_IPC_ERROR("mmap: MapViewOfFile(%d bytes) failed-error=%d",len,GetLastError());
    }
    return (void *)shm_bufferarea;
}


/**************************************************************************//**
 *
 *   Function Name: munmap()
 *
 *   Description:   emulation of POSIX function munmap
 *
 *   Parameters:
 *
 *   Function Return value:   Upon successful completion, the mmap() function returns the address at which the mapping
 *                            MAP_FAILED (-1)- on error
 *
 ******************************************************************************/
int munmap(void *addr, size_t len)
{
    BOOL    bret;
    int ret_val = 0;

    bret = UnmapViewOfFile(addr);
    if (0==bret)
    {
        /* UnmapViewOfFile failed */
        ret_val = -1;
    }

    return ret_val;
}


/**************************************************************************//**
 *
 *   Function Name: nw_shm_close()
 *
 *   Description:   close a shm file handle
 *
 *   Parameters:
 *
 *   Function Return value:  void
 *
 ******************************************************************************/
void nw_shm_close(int fd)
{
    (void) CloseHandle((HANDLE)fd);
}


/**************************************************************************//**
 *
 *   Function Name: shm_unlink()
 *
 *   Description:   emulation of POSIX function shm_unlink
 *
 *   Parameters:    name of the shared memory
 *
 *   Function Return value:   0 - on success
 *                           -1 - on error
 *
 ******************************************************************************/
int shm_unlink(const char *name)
{
    return 0;
}


/**************************************************************************//**
 *
 *   \def           ftruncate()
 *   \brief         windows simulation of ftruncate
 *
 *   \param[in]     handle to share mem
 *   \param[in]
 *   \return        NULL if error
 *
 ******************************************************************************/
int ftruncate (int fd, off_t length)
{


    int ret_val = 0;
/*
    errno_t w_ret=0;

    w_ret = _chsize_s(fd, (__int64)length);
    if (0 != w_ret)
    {
        ret_val = -1;
    }
*/
    return ret_val;
}



/**************************************************************************//**
 *
 *   Function Name: getpid()
 *
 *   Description:   emulation of LINUX function getpid
 *
 *   Parameters:    name of the shared memory
 *
 *   Function Return value:   0 - on success
 *                           -1 - on error
 *
 ******************************************************************************/
pid_t getpid(void)
{
    unsigned32 tid;

    tid = nw_os_getpid();
    return(tid);
}

unsigned32 nw_os_gettid(void)
{
    unsigned32 tid;

    tid = (unsigned32)GetCurrentThread();
    return(tid);
}

unsigned32 nw_os_getpid(void)
{
    unsigned32 new_pid;
#if 0
    unsigned32 tid;
    unsigned32 pid;

    pid = (unsigned32)GetCurrentProcessId();
    tid = (unsigned32)GetCurrentThread();

    // new_pid = (pid * 256) +  tid;
    new_pid = pid;

    NW_VMF_SHM_IPC_ERROR("nw_os_getpid(), pid=%d, tid=%d,newpid=%d",pid,tid,new_pid);
#else
    new_pid = (unsigned32)GetCurrentProcessId();
#endif
    return(new_pid);
}





/**************************************************************************//**
 *
 *   Function Name: timer_create()
 *
 *   Description:   emulation of ÜPSIX function timer_create
 *
 *   Parameters:
 *
 *   Function Return value:   (0) if OK
 *                            (-1)- on error
 *
 ******************************************************************************/
 int timer_create(clockid_t clockid, struct sigevent *sevp, timer_t *timerid)
{
    int         i_ret=-1;
    BOOL        ret_val=-1;
    HANDLE      htimer_h=NULL;

    NW_VMF_SHM_IPC_INFO("timer_create()");

    if (NULL == sevp->sigev_notify_function)
    {
        NW_VMF_SHM_IPC_ERROR("timer_create() cllback == NULL!");
        return -1;
    }

    ret_val = CreateTimerQueueTimer(&htimer_h,NULL, (void *)sevp->sigev_notify_function,sevp->sigev_value.sival_ptr,999999,0,0 );
    if (ret_val != 0)
    {
        /* OK */
        NW_VMF_SHM_IPC_INFO("timer_create() done");
        *timerid = (int)htimer_h;
        i_ret = 0;
    }
    else
    {
        NW_VMF_SHM_IPC_INFO("timer_create() CreateTimerQueueTimer() failed");
        i_ret = -1;
    }
    return i_ret;
}



/**************************************************************************//**
 *
 *   Function Name: timer_settime()
 *
 *   Description:   emulation of ÜPSIX function timer_settime
 *
 *   Parameters:
 *
 *   Function Return value:   (0) if OK
 *                            (-1)- on error
 *
 ******************************************************************************/
int timer_settime(timer_t timerid, int flags,
                         const struct itimerspec *new_value,
                         struct itimerspec * old_value)
{

    ULONG       ms_time=0;
    HANDLE      timer_h;
    BOOL        b_ret=false;
    int         i_ret = -1;

    timer_h = (HANDLE)timerid;
    ms_time = (new_value->it_value.tv_sec * 1000) + (new_value->it_value.tv_nsec / 1000000);

    NW_VMF_SHM_IPC_INFO("timer_settime() %ld ms",ms_time);


    b_ret = ChangeTimerQueueTimer(NULL, timer_h, ms_time,0);
    if (b_ret != 0)
    {
        /* OK */
        i_ret = 0;
    }
    else
    {
        NW_VMF_SHM_IPC_INFO("timer_settime() ChangeTimerQueueTimer() failed");
        i_ret = -1;
    }
    return i_ret;
}




/**************************************************************************//**
 *
 *   Function Name: timer_delete()
 *
 *   Description:   emulation of POSIX function timer_delete
 *
 *   Parameters:
 *
 *   Function Return value:   (0) if OK
 *                            (-1)- on error
 *
 ******************************************************************************/
int timer_delete(timer_t timerid)
{
    HANDLE      timer_h;
    BOOL        b_ret = 0;
    int         i_ret = -1;

    timer_h  = (HANDLE)timerid;

    b_ret = DeleteTimerQueueTimer(NULL, timer_h,NULL);
    if (b_ret != 0)
    {
        /* OK */
        i_ret = 0;
    }
    else
    {
        /* Error */
        /* ignore error */
        i_ret = 0;
    }

    return i_ret;
}


/**************************************************************************//**
 *
 *   Function Name: semaphore functions()
 *
 *   Description:   emulation of POSIX fsemaphore functions
 *
 *   Parameters:
 *
 *   Function Return value:   (0) if OK
 *                            (-1)- on error
 *
 ******************************************************************************/
int nw_sem_init (sem_t * sem, int pshared, unsigned int value)
{
    int ret_val=0;
    NW_VMF_SHM_IPC_INFO("nw_sem_init(%p)",sem);
    ret_val = sem_init ( sem, 0, value);
    NW_VMF_SHM_IPC_INFO("nw_sem_init(%p) done ret=%d",sem,ret_val);

    return ret_val;
}

#if 0
sem_t *nw_sem_open(const char *name, int oflag, ...)
{
    sem_t * ret_val=SEM_FAILED;

    NW_VMF_SHM_IPC_ERROR("nw_sem_open(%s) ret=%p",name,ret_val);
    ret_val = sem_open(name,oflag,0,0);

    NW_VMF_SHM_IPC_ERROR("nw_sem_open(%s) ret=%p done",name,ret_val);

    return ret_val;
}
#endif

int nw_sem_close(sem_t *sem)
{
    int ret_val=0;

    NW_VMF_SHM_IPC_ERROR("sem_close(%p)",sem);
    ret_val = sem_close(sem);
    NW_VMF_SHM_IPC_ERROR("sem_close(%p) done",sem);
    return ret_val;
}


int nw_sem_post(sem_t *sem)
{
    int ret_val=0;
    delay(0);
    NW_VMF_SHM_IPC_INFO("sem_post(%p)",sem);
    ret_val = sem_post(sem);
    NW_VMF_SHM_IPC_INFO("sem_post(%p) done ret = %d",sem,ret_val);
    return ret_val;
}


/**************************************************************************//**
 *
 *   Function Name: nw_get_app_name()
 *
 *   Description:   get the name of the executable
 *
 *   Parameters:    buffer, buffer-len
 *
 *   Function Return value: - 0 if OK else -1
 *
 ******************************************************************************/
int nw_get_app_name(char *buffer, int buffer_len)
{
    nw_os_sstrncpy(buffer, "VMF", buffer_len);
    return 0;
}



/**************************************************************************//**
 *
 *   Function Name: PathFindFileName()
 *
 *   Description:   emulation of Windows function PathFindFileName
 *
 *   Parameters:    file name with path
 *
 *   Function Return value: - \returnfile name without path or NULL
 *
 ******************************************************************************/
char * PathFindFileName(char *full_path)
{
    char    *ptr=NULL;
    char    *ptr_last=full_path;


    if (NULL == full_path)
    {
        return NULL;
    }

    ptr = strchr(full_path,'\\');
    ptr_last = ptr;


    while (ptr != NULL)
    {
        ptr_last = ptr+1;
        ptr = strchr(ptr_last,'\\');
    }

    return ptr_last;
}

/**************************************************************************//**
 *
 *   Function Name: nw_strncasecmp()
 *                  like strncmp but will ignore case
 *   Description:   wrapper for strncasecmp
 *
 *   Parameters:    buffer1, buffer2, buffer1-len
 *
 *   Function Return value: - 0 if identical
 *
 ******************************************************************************/
int nw_strncasecmp(const char *s1, const char *s2, size_t n)
{
    return (_strnicmp(s1,s2,n));
}

/**************************************************************************//**
 *
 *   Function Name: mkfifo()
 *
 *   Description:   wrapper for posix function mkfifo
 *
 *   Parameters:    buffer to fio-name, fifo mode
 *
 *   Function Return value: - 0 if ok
 *
 ******************************************************************************/
int         mkfifo(const char *pathname, mode_t mode)
{
        return 0;
}



/**************************************************************************//**
 *
 *   Function Name: nw_os_target_log_init()
 *                  
 *   Description:   initialize target logging, here: SYSLOG
 *
 *   Parameters:    init_string - here: SYSLOG name
 *
 *   Return value:  true / false
 *
 ******************************************************************************/
bool nw_os_target_log_init(const char *init_string)
{
    /* NOT SUPPORTED */
    return true;
}


/**************************************************************************//**
 *
 *   Function Name: nw_os_target_log_init()
 *                  
 *   Description:   write target logging, here: SYSLOG
 *
 *   Parameters:    severity    - 0 (high) ... 127 (low), here: mapped to SYSLOG levels.
 *                  log_message - buffer containing the message to be logged.
 *
 *   Return value:  true / false
 *
 ******************************************************************************/
bool nw_os_target_log(unsigned int severity, char *log_message)
{
    /* NOT SUPPORTED */
    return true;
}

#undef _NW_OS_CONFIG_C_
