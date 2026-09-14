/*
 * $QNXLicenseC:
 * Copyright 2007, 2009, 2010, QNX Software Systems. All Rights Reserved.
 *
 * You must obtain a written license from and pay applicable license fees to QNX
 * Software Systems before you may reproduce, modify or distribute this software,
 * or any work that includes all or part of this software.   Free development
 * licenses are available for evaluation and non-commercial purposes.  For more
 * information visit http://licensing.qnx.com or email licensing@qnx.com.
 *
 * This file may contain contributions from others.  Please review this entire
 * file for other proprietary rights or license notices, as well as the QNX
 * Development Suite License Guide at http://licensing.qnx.com/license-guide/
 * for other information.
 * $
 */

#ifndef _UNISTD_H_INCLUDED
#define _UNISTD_H_INCLUDED
#define _UNISTD_H_DECLARED

#ifndef __PLATFORM_H_INCLUDED
#include <sys/platform.h>
#endif
#include <stdio.h>


#ifndef NULL
# define NULL _NULL
#endif
#if 0
#if defined(__SSIZE_T)
typedef __SSIZE_T   ssize_t;
#undef __SSIZE_T
#endif

#if defined(__SIZE_T)
typedef __SIZE_T    size_t;
#undef __SIZE_T
#endif

#if defined(__OFF_T)
typedef __OFF_T     off_t;
#undef __OFF_T
#endif

#if defined(__OFF64_T)
typedef __OFF64_T   off64_t;
#undef __OFF64_T
#endif

#if defined(__PID_T)
typedef __PID_T     pid_t;
#undef __PID_T
#endif

#if defined(__UID_T)
typedef __UID_T     uid_t;
#undef __UID_T
#endif

#if defined(__GID_T)
typedef __GID_T     gid_t;
#undef __GID_T
#endif
#endif
#if defined(__EXT_XOPEN_EX)

#if defined(__USECONDS_T)
typedef __USECONDS_T    useconds_t;
#undef __USECONDS_T
#endif

#endif

#ifndef _PROCESS_H_INCLUDED
#include <process.h>
#endif

/* Symbolic constants for the access() function */

#define R_OK    4       /*  Test for read permission    */
#define W_OK    2       /*  Test for write permission   */
#define X_OK    1       /*  Test for execute permission */
#define F_OK    0       /*  Test for existence of file  */

/* Symbolic constants for the lseek() function */

#ifndef _SEEKPOS_DEFINED_       /* If not already defined, define them  */
#define SEEK_SET    0           /* Seek relative to the start of file   */
#define SEEK_CUR    1           /* Seek relative to current position    */
#define SEEK_END    2           /* Seek relative to the end of the file */
#define _SEEKPOS_DEFINED_
#endif

/* Symbolic constants for stream I/O */

#define STDIN_FILENO    0
#define STDOUT_FILENO   1
#define STDERR_FILENO   2

/* Symbolic constants for lockf() function */

#define F_ULOCK 0      /* Unlock locked sections */
#define F_LOCK  1      /* Lock a section for exclusive use */
#define F_TLOCK 2      /* Test and lock a section for exclusive use */
#define F_TEST  3      /* Test a lock for locks by other processes */

/* Compile-time Symbolic Constants for Portability Specifications */

#undef _POSIX_VERSION
#undef _POSIX2_VERSION
#if   defined(__EXT_POSIX1_200112)
# define _POSIX_VERSION  200112L
# define _POSIX2_VERSION 200112L
#elif defined(__EXT_POSIX1_199506)
# define _POSIX_VERSION  199506L
# define _POSIX2_VERSION 199209L
#elif defined(__EXT_POSIX1_199309)
# define _POSIX_VERSION  199309L
# define _POSIX2_VERSION 199209L
#elif defined(__EXT_POSIX1_199009)
# define _POSIX_VERSION  199009L
# define _POSIX2_VERSION 1
#elif defined(__EXT_POSIX1_198808)
# define _POSIX_VERSION  198808L
# define _POSIX2_VERSION 1
#endif

#if defined(__EXT_POSIX1_199009)
# undef _POSIX_JOB_CONTROL
# define _POSIX_SAVED_IDS 1
#endif

#if defined(__EXT_POSIX1_199309)
# define    _POSIX_ASYNCHRONOUS_IO              _POSIX_VERSION
# define    _POSIX_FSYNC                        _POSIX_VERSION
# define    _POSIX_MAPPED_FILES                 _POSIX_VERSION
# define    _POSIX_MEMLOCK                      _POSIX_VERSION
# define    _POSIX_MEMLOCK_RANGE                _POSIX_VERSION
# define    _POSIX_MEMORY_PROTECTION            _POSIX_VERSION
# define    _POSIX_MESSAGE_PASSING              _POSIX_VERSION
# define    _POSIX_PRIORITIZED_IO               _POSIX_VERSION
# define    _POSIX_PRIORITY_SCHEDULING          _POSIX_VERSION
# define    _POSIX_REALTIME_SIGNALS             _POSIX_VERSION
# define    _POSIX_SEMAPHORES                   _POSIX_VERSION
# define    _POSIX_SHARED_MEMORY_OBJECTS        _POSIX_VERSION
# define    _POSIX_SYNCHRONIZED_IO              _POSIX_VERSION
# define    _POSIX_TIMERS                       _POSIX_VERSION
#endif

#if defined(__EXT_POSIX1_199506)
# define    _POSIX_THREADS                      _POSIX_VERSION
# define    _POSIX_THREAD_PRIO_INHERIT          _POSIX_VERSION
# define    _POSIX_THREAD_PRIO_PROTECT          _POSIX_VERSION
# define    _POSIX_THREAD_PRIORITY_SCHEDULING   _POSIX_VERSION
# define    _POSIX_THREAD_ATTR_STACKADDR        _POSIX_VERSION
# define    _POSIX_THREAD_SAFE_FUNCTIONS        _POSIX_VERSION
# define    _POSIX_THREAD_PROCESS_SHARED        _POSIX_VERSION
# define    _POSIX_THREAD_ATTR_STACKSIZE        _POSIX_VERSION
#endif

#if defined(__EXT_POSIX1_200112)
/* POSIX 1003.1d D14 */
# define  _POSIX_ADVISORY_INFO			_POSIX_VERSION
# define  _POSIX_CPUTIME			_POSIX_VERSION
# define _POSIX_SPAWN                           _POSIX_VERSION
# define _POSIX_SPORADIC_SERVER                 _POSIX_VERSION
# define _POSIX_THREAD_CPUTIME			_POSIX_VERSION
# define _POSIX_TIMEOUTS                        _POSIX_VERSION
# define _POSIX_THREAD_SPORADIC_SERVER          _POSIX_VERSION

/* POSIX 1003.1j D10 */
# define _POSIX_BARRIERS                        _POSIX_VERSION
# define _POSIX_CLOCK_SELECTION                 _POSIX_VERSION
# define _POSIX_MONOTONIC_CLOCK                 _POSIX_VERSION
# define _POSIX_READER_WRITER_LOCKS             _POSIX_VERSION
# define _POSIX_SPIN_LOCKS                      _POSIX_VERSION
# define _POSIX_TYPED_MEMORY_OBJECTS            _POSIX_VERSION

/* POSIX 1003.1q-2000 */
# define _POSIX_TRACE_EVENT_FILTER	(-1)
# define _POSIX_TRACE				(-1)
# define _POSIX_TRACE_INHERIT		(-1)
# define _POSIX_TRACE_LOG			(-1)
# define _POSIX_RAW_SOCKETS			_POSIX_VERSION
# undef _POSIX_IPV6

/* POSIX 1003.1-2001 states job control is mandatory */
# define _POSIX_JOB_CONTROL 1

/* POSIX 1003.1-2001 states regular expression handling is mandatory */
# define _POSIX_REGEXP 1

/* POSIX 1003.1-2001 states POSIX shell is mandatory */
# define _POSIX_SHELL 1

# if __INT_BITS__==32 && __LONG_BITS__==32 && __PTR_BITS__==32 && __OFF_BITS__==32
#  define _POSIX_V6_ILP32_OFF32   (1)
#  define _POSIX_V7_ILP32_OFF32   (1)
# else
#  define _POSIX_V6_ILP32_OFF32   (-1)
#  define _POSIX_V7_ILP32_OFF32   (-1)
# endif

# if __INT_BITS__==32 && __LONG_BITS__==32 && __PTR_BITS__==32 && __OFF_BITS__>=32
#  define _POSIX_V6_ILP32_OFFBIG  (1)
#  define _POSIX_V7_ILP32_OFFBIG  (1)
# else
#  define _POSIX_V6_ILP32_OFFBIG  (-1)
#  define _POSIX_V7_ILP32_OFFBIG  (-1)
# endif

# if __INT_BITS__==32 && __LONG_BITS__==64 && __PTR_BITS__==64 && __OFF_BITS__==64
#  define _POSIX_V6_LP64_OFF64    (1)
#  define _POSIX_V7_LP64_OFF64    (1)
# else
#  define _POSIX_V6_LP64_OFF64    (-1)
#  define _POSIX_V7_LP64_OFF64    (-1)
# endif

# if __INT_BITS__>=32 && __LONG_BITS__>=64 && __PTR_BITS__>=64 && __OFF_BITS__>=64
#  define  _POSIX_V6_LPBIG_OFFBIG (1)
#  define  _POSIX_V7_LPBIG_OFFBIG (1)
# else
#  define  _POSIX_V6_LPBIG_OFFBIG (-1)
#  define  _POSIX_V7_LPBIG_OFFBIG (-1)
# endif

#endif

#if defined(__EXT_POSIX2)
# define _POSIX2_C_VERSION   _POSIX2_VERSION
# define _POSIX2_C_BIND      _POSIX2_VERSION
# define _POSIX2_CHAR_TERM   _POSIX2_VERSION
# define _POSIX2_LOCALEDEF   _POSIX2_VERSION
# define _POSIX2_UPE         _POSIX2_VERSION
# define _POSIX2_FORT_RUN    _POSIX2_VERSION
# define _POSIX2_LOCALEDEF   _POSIX2_VERSION
# define _POSIX2_C_DEV       _POSIX2_VERSION
# define _POSIX2_SW_DEV      _POSIX2_VERSION
#endif

#if defined(__EXT_XOPEN_EX)
# define _XOPEN_VERSION         500
# define _XOPEN_XCU_VERSION       1
# define _XOPEN_XPG2              1
# define _XOPEN_XPG3              1
# define _XOPEN_XPG4              1
# define _XOPEN_UNIX              1
# define _XOPEN_CRYPT             1
# define _XOPEN_ENH_I18N          1
# define _XOPEN_LEGACY            1
# define _XOPEN_REALTIME          1
# define _XOPEN_REALTIME_THREADS  1
# define _XOPEN_SHM               1

# if __INT_BITS__==32 && __LONG_BITS__==32 && __PTR_BITS__==32 && __OFF_BITS__==32
#  define _XBS5_ILP32_OFF32       (1)
# else
#  define _XBS5_ILP32_OFF32       (-1)
# endif

# if __INT_BITS__==32 && __LONG_BITS__==32 && __PTR_BITS__==32 && __OFF_BITS__>=32
#  define _XBS5_ILP32_OFFBIG      (1)
# else
#  define _XBS5_ILP32_OFFBIG      (-1)
# endif

# if __INT_BITS__<64 && __LONG_BITS__==64 && __PTR_BITS__==64 && __OFF_BITS__==64
#  define _XBS5_LP64_OFF64        (1)
# else
#  define _XBS5_LP64_OFF64        (-1)
# endif

# if __INT_BITS__<64 && __LONG_BITS__>=64 && __PTR_BITS__>=64 && __OFF_BITS__>=64
#  define _XBS5_LPBIG_OFFBIG      (1)
# else
#  define _XBS5_LPBIG_OFFBIG      (-1)
# endif

#endif

#if defined(__EXT_QNX)
/* POSIX 1003.1d Draft 8 */
# define _POSIX_DEVICE_CONTROL       1
# define _POSIX_DEVCTL_DIRECTION     1
# define _POSIX_INTERRUPT_CONTROL    1
/* POSIX 1003.1j Draft 5 */
# undef _POSIX_PROCESS_SPIN_LOCKS
# undef _POSIX_THREAD_SPIN_LOCKS
# undef _POSIX_TYPED_MEMORY_ACCESS_MGMT
# undef _POSIX_SYNCHRONIZED_CLOCK
# define _POSIX_THREAD_ASYNC_ABORT   1
#endif

/* Execution-time Symbolic Constants for Portability Specifications */

#if defined(__EXT_POSIX1_199009)
# define _POSIX_CHOWN_RESTRICTED  1       /* restricted use of chown() */
# define _POSIX_NO_TRUNC          1       /* pathname components > NAME_MAX */
# define _POSIX_VDISABLE          0       /* terminal special chars can be disabled */
#endif

#if defined(__EXT_POSIX1_199309)
# define _POSIX_ASYNC_IO          1
# define _POSIX_PRIO_IO           1
# define _POSIX_SYNC_IO           1
#endif



   extern int   optind;        /*  index of current option being scanned */
   extern char *optarg;        /*  points to optional argument */

#if defined(__SLIB_DATA_INDIRECT) && !defined(opterr) && !defined(__SLIB)
   int *__get_opterr_ptr(void);
   #define opterr (*__get_opterr_ptr())
#else
   extern int   opterr;        /*  print|don't print error message */
#endif

#if defined(__SLIB_DATA_INDIRECT) && !defined(optopt) && !defined(__SLIB)
   int *__get_optopt_ptr(void);
   #define optopt (*__get_optopt_ptr())
#else
   extern int   optopt;        /*  offending letter when error detected */
#endif
#endif


# ifndef SETIOV
#  define SETIOV(__iov, __addr, __len)          \
    (((__iov)->iov_base = (void *)(__addr)),    \
     ((__iov)->iov_len = (__len)))
# endif
# ifndef GETIOVBASE
#  define GETIOVBASE(__iov)                     \
    ((__iov)->iov_base)
# endif
# ifndef GETIOVLEN
#  define GETIOVLEN(__iov)                      \
    ((__iov)->iov_len)
# endif



extern int close(int __fildes);
extern int rmdir(const char *__path);
extern unsigned sleep(unsigned __seconds);
extern int symlink(const char *__pname, const char *__slink);
extern void sync(void);
extern long sysconf(int __name);
extern int unlink(const char *__path);
extern ssize_t write(int __fildes, const void *__buf, size_t __len);

size_t strlcpy(char *__s1, const char *__s2, size_t __n);

#if defined(__EXT_POSIX2)
# if !defined(__EXT_UNIX_HIST)
extern int getopt(int __argc, char * const __argv[], const char * __optstring);
# endif
#endif

extern unsigned delay(unsigned int __milliseconds);

#if defined(__EXT_QNX)
struct sigevent;

extern ssize_t  _readx(int __fildes, void *__buffer, size_t __len, unsigned __xtype, void *__xdata, size_t __xdatalen);
extern int readblock(int __fd, size_t __blksize, unsigned __blk, int __numblks, void *__buff);
extern ssize_t  _writex(int __fildes, const void *__buffer, size_t __len, unsigned __xtype, void *__xdata, size_t __xdatalen);
extern int writeblock(int __fd, size_t __blksize, unsigned __blk, int __numblks, const void *__buff);
extern int readcond(int __fd, void *__buff, int __nbytes, int __min, int __time, int __timeout);
extern int ionotify(int __fd, int __action, int __flags, const struct sigevent *__event);
extern off_t ltrunc(int __fd, off_t __offset, int __whence) __ALIAS64("ltrunc64");

extern int _sopenfd(int __fd, int __oflag, int __sflag, int __xtype);
extern int sopenfd(int __fd, int __oflag, int __sflag);
extern int openfd(int __fd, int __oflag);
extern char *qnx_crypt(const char *__key, const char *__salt);
extern int flink(int __fd, const char *__path);
extern int getdomainname(char *__name, size_t __namelen);
extern int setdomainname(const char *__name, size_t __namelen);
extern int fdistrusted(int __fd);

#if defined(__SLIB_DATA_INDIRECT) && !defined(environ) && !defined(__SLIB)
    extern char **__get_environ_ptr(void);
    extern void __set_environ_ptr(char **__newptr);
    #define environ (__get_environ_ptr())
#else
    extern char **environ;   /*  pointer to environment table        */
#endif

#if defined(__SLIB_DATA_INDIRECT) && !defined(_connect_malloc) && !defined(__SLIB)
   char *__get_connect_malloc_ptr(void);
   #define _connect_malloc (*__get_connect_malloc_ptr())
#else
   extern char   _connect_malloc;   /*  connect malloc*/
#endif

#endif





