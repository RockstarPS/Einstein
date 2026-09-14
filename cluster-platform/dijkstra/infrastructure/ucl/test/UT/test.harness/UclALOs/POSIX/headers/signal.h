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

#ifndef _SIGNAL_H_INCLUDED
#define _SIGNAL_H_INCLUDED
#define _SIGNAL_H_DECLARED

#include <sys/types.h>

#define SIGRTMIN    41
#define SIG_BLOCK   0

#define SIGEV_SIGNAL_32			1	/* notify, signo, value */
#define SIGEV_SIGNAL 		(SIGEV_SIGNAL_32)
#define SIGINT      2   /* interrupt */

extern int kill(pid_t __pid, int __signum);
extern int sigemptyset(sigset_t *__set);
extern int sigaddset(sigset_t *__set, int __signo);
extern int sigwait(const sigset_t *__set, int *__sig);
extern int pthread_sigmask(int __how, const sigset_t *__set, sigset_t *__oset);
#endif
