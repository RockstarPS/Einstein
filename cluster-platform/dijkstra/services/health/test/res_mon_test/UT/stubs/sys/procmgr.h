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
extern int procmgr_daemon(int __status, unsigned __flags);
extern int procmgr_ability(pid_t __pid, unsigned __ability, ...);

#endif


