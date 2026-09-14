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

#ifndef __NEUTRINO_H_INCLUDED
#define __NEUTRINO_H_INCLUDED

#include <sys/types.h>
#include <sys/siginfo.h>
#include <time.h>

#define _NTO_TCTL_IO					14
#define bool_t bool
#define PROCMGR_AID_INTERRUPT 1
#define PROCMGR_AOP_ALLOW 2
#define PROCMGR_AID_MEM_PHYS 4
#define PROCMGR_AID_EOL 16

extern int ThreadCtl(int __cmd, void *__data);

extern int TimerCreate(clockid_t __id, const struct sigevent *__notify);
extern int TimerSettime(timer_t __id, int __flags, const struct _itimer *__itime, struct _itimer *__oitime);


#endif
