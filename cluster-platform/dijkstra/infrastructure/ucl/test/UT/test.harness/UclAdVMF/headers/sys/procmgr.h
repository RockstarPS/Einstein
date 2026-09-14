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
 *  sys/procmgr.h
 *

 */
#ifndef __PROCMGR_H_INCLUDED
#define __PROCMGR_H_INCLUDED
#include <sys/types.h>
#define PROCMGR_DAEMON_NOCLOSE			0x00000002
#define PROCMGR_DAEMON_NODEVNULL		0x00000004
#define PROCMGR_ADN_NONROOT				0x20000000u
#define PROCMGR_AOP_DENY				0x00010000u
#define PROCMGR_AID_PATHSPACE			5u		/* SR: none */
#define PROCMGR_AID_MASK				0xffffu
#define PROCMGR_AID_EOL					PROCMGR_AID_MASK
#define PROCMGR_AOP_ALLOW				0x00020000u

#define PROCMGR_AID_IO					31u		/* SR: level */
#define PROCMGR_AID_MEM_PHYS			16u		/* SR: paddr */

#define PROCMGR_AOP_LOCK				0x00080000u

#define EOK              0  /* No error                                 */

extern int procmgr_daemon(int __status, unsigned __flags);
extern int procmgr_ability(pid_t __pid, unsigned __ability, ...);

extern int errno;
//#ifndef errno
int *__get_errno_ptr(void) __attribute__((__const__));
# define errno (*__get_errno_ptr())
//#endif

#endif


