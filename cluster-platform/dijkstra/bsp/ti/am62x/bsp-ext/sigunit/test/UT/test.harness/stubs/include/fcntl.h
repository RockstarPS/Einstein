/*
 * $QNXLicenseC:
 * Copyright 2007, 2009, QNX Software Systems. All Rights Reserved.
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

#ifndef _FCNTL_H_INCLUDED
#define _FCNTL_H_INCLUDED
#define _FCNTL_H_DECLARED

#include <sys/types.h>
#include <sys/platform.h>
#include <unistd.h>
#include <sys/stat.h>


/*
 *  Flag values accessible to both open() and fcntl()
 *  (The first three can only be set by open)
 */

/*
 *  File access modes.
 */

#define O_RDONLY    000000  /*  Read-only mode  */
#define O_WRONLY    000001  /*  Write-only mode */
#define O_RDWR      000002  /*  Read-Write mode */
#define O_EXEC      000003  /*  Will be executing the file */

/*
 *  Mask for file access modes.
 */

#define O_ACCMODE   000007

/*
 *  File status flags used for open() and fcntl().
 */

#define O_NONBLOCK  000200  /*  Non-blocking I/O                */
#define O_APPEND    000010  /*  Append (writes guaranteed at the end)   */

#ifndef O_NDELAY
#define O_NDELAY O_NONBLOCK
#endif

#if defined(_QNX_SOURCE) || (_POSIX_C_SOURCE+0 >= 199309) || (!defined(NO_EXT_KEYS) && !defined(_POSIX_C_SOURCE))
#define O_DSYNC     000020  /*  Data integrity synch    */
#define O_RSYNC     000100  /*  Data integrity synch    */
#define O_SYNC      000040  /*  File integrity synch    */
#endif

/*
 *  oflag values for open()
 */

#define O_CREAT     000400  /*  Opens with file create      */
#define O_TRUNC     001000  /*  Open with truncation        */
#define O_EXCL      002000  /*  Exclusive open          */
#define O_NOCTTY    004000  /*  Don't assign a controlling terminal */
#define O_NOFOLLOW  010000  /*  If last path element is a symlink, don't follow it */

#define O_TEXT      000000  /*  Text file   (DOS thing)     */
#define O_BINARY    000000  /*  Binary file (DOS thing)     */
#define O_CLOEXEC   020000  /*  File descriptor will be close-on-exec */
#define O_REALIDS   040000  /*  Use real uid/gid for permision checking */
#define O_LARGEFILE 0100000 /*  Largest off_t can be 64 bits */
#define O_ASYNC     0200000 /*  Set async i/o               */
#define O_NOSYMLINK 0400000 /*  If any path element is a symlink, don't follow it */
#define O_ANON		01000000 /* Anonymous shared-memory objects */
#define O_PERMCHECK	02000000 /* Open is really just doing access(), ignore some errors, and auto-close the fd*/

/*
 * Mask of flags that can be set with fcntl()
 */
#define O_SETFLAG   (O_NONBLOCK|O_APPEND|O_DSYNC|O_RSYNC|O_SYNC|O_LARGEFILE)

/*
 *  fcntl() requests
 */

#define F_DUPFD         0   /*  Duplicate file descriptor   */
#define F_GETFD         1   /*  Get file descriptor flags   */
#define F_SETFD         2   /*  Set file descriptor flags   */
#define F_GETFL         3   /*  Get file status flags   */
#define F_SETFL         4   /*  Set file status flags   */
#define F_DUPFD_CLOEXEC 5   /*  Duplicate file descriptor, set FD_CLOEXEC flag */

#define F_CHKFL     8       /*              */
#define F_ISSTREAM  13      /*              */
#define F_PRIV      15      /*              */
#define F_NPRIV     16      /*              */
#define F_QUOTACTL  17      /*              */
#define F_BLOCKS    18      /*              */
#define F_BLKSIZE   19      /*              */

#define F_RSETLK    20      /*              */
#define F_RGETLK    21      /*              */
#define F_RSETLKW   22      /*              */

#define F_GETOWN    35  /* get SIGIO/SIGURG proc/pgrp */
#define F_SETOWN    36  /* set SIGIO/SIGURG proc/pgrp */

/*
 *  File descriptor flags used for fcntl()
 */

#define FD_CLOEXEC  0x01    /*  Close on exec       */

/*
 *  l_type values for record locking with fcntl()
 */

#define F_RDLCK     1       /*  Shared or read lock     */
#define F_WRLCK     2       /*  Exclusive or write lock */
#define F_UNLCK     3       /*  Unlock          */

/*
 * operation values to use with flock()
 */
#define   LOCK_SH   0x1    /* Shared lock */
#define   LOCK_EX   0x2    /* Exclusive lock */
#define   LOCK_NB   0x4    /* Don't block when locking */
#define   LOCK_UN   0x8    /* Unlock */
#endif



#include <_pack64.h>




#include <_packpop.h>



/*
 *  POSIX 1003.1 Prototypes.
 */



extern int open(const char *__path, int __oflag, ...);
extern int creat(const char *__path, mode_t __mode);
extern int fcntl(int __fildes, int __cmd, ...);


extern int set_lowest_fd(int __fd);

struct _io_connect_entry;

extern int _connect_entry(int __base, const char *__path, mode_t __mode, unsigned __oflag, unsigned __sflag, unsigned __subtype, unsigned __ctrl_flags, unsigned __access, unsigned __file_type, unsigned __extra_type, unsigned __extra_len, const void *__extra, unsigned __response_len, void *__response, int *__status, struct _io_connect_entry *__entry, int __enoretry);

extern int _connect_fd(int __base, const char *__path, mode_t __mode, unsigned __oflag, unsigned __sflag, unsigned __subtype, unsigned __ctrl_flags, unsigned __access, unsigned __file_type, unsigned __extra_type, unsigned __extra_len, const void *__extra, unsigned __response_len, void *__response, int *__status, int *fd_len, void *fd_array);

extern int _connect(int __base, const char *__path, mode_t __mode, unsigned __oflag, unsigned __sflag, unsigned __subtype, unsigned __ctrl_flags, unsigned __access, unsigned __file_type, unsigned __extra_type, unsigned __extra_len, const void *__extra, unsigned __response_len, void *__response, int *__status);

extern int _connect_combine(const char *__path, mode_t __mode, unsigned __oflag, unsigned __sflag, unsigned __ctrl_flags, unsigned __file_type, unsigned __extra_len, void *__extra, unsigned __response_len, void *__response);

extern int _connect_object(const char *__name, const char *__prefix, mode_t __mode, int __oflag, unsigned __file_type, unsigned __extra_type, unsigned __extra_len, const void *__extra);

extern int _unlink_object(const char *__name, const char *__prefix, unsigned __file_type);



