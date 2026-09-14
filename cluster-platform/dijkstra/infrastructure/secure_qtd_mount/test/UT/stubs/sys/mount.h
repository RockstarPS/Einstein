/*
 * $QNXLicenseC:
 * Copyright 2007, QNX Software Systems. All Rights Reserved.
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



/*
 *  sys/mount.h
 *

 */
#ifndef __MOUNT_H_INCLUDED
#define __MOUNT_H_INCLUDED

#include <devctl.h>

#define ST_RDONLY        0x01  /* rw read only */
#define ST_NOEXEC        0x02  /* rw can't exec from filesystem */
#define ST_NOSUID        0x04  /* rw don't honor setuid bits on fs */
#define ST_NOCREAT       0x08  /* rw don't allow creat on this fs */
#define ST_OFF32         0x10  /* rw Limit off_t to 32 bits */
#define ST_NOATIME       0x20  /* rw don't update times if only atime is dirty */
#define ST_RMVABLE       0x40  /* media is removeable */
#define ST_TRUSTED       0x80  /* filesystem is trusted */
#define ST_CONCURRENT   0x200  /* Concurrent access may be faster with multiple fd to one file */

/* These flags match with the iofunc mount flags and can be masked directly */
#define _MOUNT_READONLY	ST_RDONLY	/* read only */
#define _MOUNT_NOEXEC	ST_NOEXEC	/* can't exec from filesystem */
#define _MOUNT_NOSUID	ST_NOSUID	/* don't honor setuid bits on fs */
#define _MOUNT_NOCREAT	ST_NOCREAT	/* don't allow creat on this fs */
#define _MOUNT_OFF32	ST_OFF32	/* Limit off_t to 32 bits */
#define _MOUNT_NOATIME	ST_NOATIME	/* don't update times if only atime is dirty */
#define _MOUNT_TRUSTED	ST_TRUSTED	/* The mountpoint is trusted by the system */

/* These flags match with the RESMGR flags if you shift by 32 bits */
#define _MOUNT_BEFORE   0x00010000  /* call pathname attach with RESMGR_FLAG_BEFORE */
#define _MOUNT_AFTER    0x00020000  /* call pathname attach with RESMGR_FLAG_AFTER */
#define _MOUNT_OPAQUE   0x00040000  /* call pathname attach with RESMGR_FLAG_OPAQUE */

/* These flags are mount specific */
#define _MOUNT_UNMOUNT  0x00001000  /* Unmount this path */
#define _MOUNT_REMOUNT  0x00002000  /* This path is already mounted, perform an update */
#define _MOUNT_FORCE	0x00004000  /* Force an unmount or a remount change */
#define _MOUNT_ENUMERATE	0x00008000  /* Auto-detect on this device */
#define _MOUNT_IMPLIED	0x00080000  /* The mountpoint is unspecified by client */


#define _MFLAG_OCB      0x80000000  /* Attempt to open the device and send and ocb to server */
#define _MFLAG_SPEC     0x40000000  /* Send the special device string to the server */
#define _MFLAG_STRUCT   0x20000000  /* The data is not a string, but a structure and datalen is defined */

/* 
 If spec starts with a leading / then the device will be
 opened and an ocb send along with the mount request.

 If datalen is < 0 then it is assumed that data contains
 a null terminated string.
*/
#if defined(__QNX__)
int mount(const char *spec, const char *dir, int flags, const char *type, const void *data, int datalen);
#elif defined(__linux__)
int mount(const char *spec, const char *dir, int flags, const char *type, const void *data);
#endif
/*
 There are currently no flags defined for umount
*/
int umount(const char *dir, int flags);
int umount_typed(const char *dir, const char *type, int flags);



/*
 This is a helper routine for argument parsing
*/
#define _MOPTION_RDONLY		"ro"
#define _MOPTION_RDWR		"rw"
#define _MOPTION_EXEC		"exec"
#define _MOPTION_NOEXEC		"noexec"
#define _MOPTION_SUID		"suid"
#define _MOPTION_NOSUID		"nosuid"
#define _MOPTION_ATIME		"atime"
#define _MOPTION_NOATIME	"noatime"
#define _MOPTION_REMOUNT	"remount"
#define _MOPTION_ENUMERATE	"enumerate"
#define _MOPTION_BEFORE		"before"	
#define _MOPTION_AFTER		"after"
#define _MOPTION_OPAQUE		"opaque"
#define _MOPTION_NOSTAT		"nostat"	
#define MS_NOATIME			1
#define MS_RDONLY			1
char * mount_parse_generic_args(char *options, int *flags);

/*
 * Commonly used system mount strings
 */

#define NFS_FS_TYPE				"nfs"
#define CIFS_FS_TYPE			"cifs"
#define QNX6_FS_TYPE			"qnx6"
#define EXT2_FS_TYPE			"ext2"
#define DOS_FS_TYPE				"dos"
#define CD_FS_TYPE				"cd"
#define FLASH_FS_TYPE			"flash"

#endif

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/branches/7.1.0/trunk/lib/c/public/sys/mount.h $ $Rev: 868608 $")
#endif
