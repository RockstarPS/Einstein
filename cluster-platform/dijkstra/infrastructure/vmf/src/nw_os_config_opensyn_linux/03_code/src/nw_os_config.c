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
#include <sys/prctl.h>

#include "nw_os_config.h"

#define NW_VMF_OS_CONF_ERROR(...)       fprintf(stdout, "VMF_OS_CONFIG: "__VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");
#define NW_VMF_OS_CONF_INFO(...)        // fprintf(stdout, "VMF_OS_CONFIG: "__VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");
#define NW_VMF_OS_CONF_INFO2(...)       // fprintf(stdout, "VMF_OS_CONFIG: "__VA_ARGS__); fprintf(ERROR_CHANNEL, "\n");


char                progname[MAX_PROGNAME_LEN] = {0};
extern  char        *__progname;                                        /* name of the current running process - should work in QNX and Linux */
unsigned32          ms_time_offset=0;

#ifdef SET_WRITE_BUFFER_SIZE
static bool nw_os_set_writebuffer_size(void);
#endif
static void nw_os_set_normalized_timespec (struct timespec *ts, unsigned64 sec, unsigned64 nsec);


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
    struct timespec temp;
    unsigned64      time_ns = 0;

    if (0 == clock_gettime(CLOCK_MONOTONIC, &temp))
    {
        time_ns = ((unsigned64)temp.tv_sec * (unsigned64)1000000000L) + (unsigned64)(temp.tv_nsec);
    }
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
    struct timespec temp;
    unsigned64      time_us = 0;

    if (0 == clock_gettime(CLOCK_MONOTONIC, &temp))
    {
        time_us = ((unsigned64)temp.tv_sec * (unsigned64)1000000L) + (unsigned64)(temp.tv_nsec)/1000;
    }
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
    #define MAX_DOMAINSOCKET_Q_SIZE     500
    char    tmp[]="12345";
    FILE    *p_file;
    bool    b_ret = false;

    if (0 == q_size)
    {
        /* do not set queue size */
        return true;
    }

    #ifdef SET_WRITE_BUFFER_SIZE
    (void)nw_os_set_writebuffer_size();
    #endif
    p_file = fopen ("/proc/sys/net/unix/max_dgram_qlen","w");

    if (q_size > MAX_DOMAINSOCKET_Q_SIZE)
    {
        q_size = MAX_DOMAINSOCKET_Q_SIZE;
    }

    if (p_file != NULL)
    {
        sprintf(tmp,"%d",q_size);
        fputs (tmp,p_file);
        fclose (p_file);
        b_ret = true;
    }
    return b_ret;
}


#ifdef SET_WRITE_BUFFER_SIZE
/**************************************************************************//**
 *
 *   \def           nw_os_set_writebuffer_size
 *   \brief         set domain socket tx buffer size to
 *                  DOMAINSOCKET_WBUFF_SIZE
 *   \param[in]     void
 *   \return        true -- if OK
 *
 ******************************************************************************/
static bool nw_os_set_writebuffer_size(void)
{
   #define MAX_DOMAINSOCKET_WBUFF_SIZE     999999
   char    tmp[]="1234567";
    FILE    *p_file;
    bool    b_ret = false;
    unsigned32 wbuff_size = DOMAINSOCKET_WBUFF_SIZE;

    if (wbuff_size > MAX_DOMAINSOCKET_WBUFF_SIZE)
    {
        wbuff_size = MAX_DOMAINSOCKET_WBUFF_SIZE;
    }

    p_file = fopen ("/proc/sys/net/core/wmem_default","w");
    if (p_file != NULL)
    {
        sprintf(tmp,"%d",wbuff_size);
        fputs (tmp,p_file);
        fclose (p_file);
        b_ret = true;
    }
    return b_ret;
}
#endif


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
    struct timespec ts;
    int s;
    unsigned64  u64_s=0;
    unsigned64  u64_ns=0;

    if (0==ms_time)
    {
        ms_time=1;
    }

    /* semaphore with timeout */
    /* get current time */
    if (clock_gettime(CLOCK_REALTIME, &ts) == -1)
    {
        NW_VMF_OS_CONF_ERROR("nw_os_sem_timedwait: clock_gettime error\n");
        return -1;
    }
    u64_s =  (unsigned64)ts.tv_sec;
    u64_ns = (unsigned64)ts.tv_nsec;

    /* add timeout to timespec */
    nw_os_set_normalized_timespec (&ts, u64_s, u64_ns + ((unsigned64)ms_time * 1000000L));

    /* restart if interrupted by event */
    errno = 0;
    while ((s = sem_timedwait(sem, &ts)) == -1 && errno == EINTR)
    {
        nw_sleep_us(100);
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
    while (nw_os_sem_timedwait(sem,500) != 0)
    {
/*        nw_sleep_us(100);     */
    }
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
    int ret_val;
    void * ret_mem_ptr=NULL;

    ret_val = posix_memalign(&ret_mem_ptr,sizeof(void *), size);
    if (ret_val != 0 )
    {
        ret_mem_ptr = NULL;
    }
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
    free(ptr);
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
 *   Function Name: nw_os_getpid()
 *
 *   Description:   get the current pid
 *
 *   Parameters:    thread void
 *
 *   Function Return value: - pid
 *
 ******************************************************************************/
unsigned32 nw_os_getpid(void)
{
    return getpid();
}


/**************************************************************************//**
 *
 *   Function Name: nw_shm_create()
 *
 *   Description:   create a share memory segment with a given size
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
    int fd = -1;
    mode_t  mask;

    mask = umask(0);
    fd = shm_open(object_name,O_CREAT | O_RDWR, mode);
    (void)umask(mask);

    if (fd == -1)
    {
        /* error message */
    }
    else
    {
        /* Set the shared memory size */
        if ((ftruncate( fd, len)) < 0)
        {
            close(fd);
            fd=-1;
        }
    }
    return fd;
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

    fd = shm_open(object_name,O_RDWR, 0777);

    return fd;
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
    nw_os_sstrncpy(buffer,__progname,buffer_len);
    return 0;
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
    return (strncasecmp(s1,s2,n));
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
