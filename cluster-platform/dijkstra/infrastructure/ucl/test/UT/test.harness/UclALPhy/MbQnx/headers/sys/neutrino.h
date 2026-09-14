/*
 * $QNXLicenseC:
 * Copyright 2007-2018, QNX Software Systems. All Rights Reserved.
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

#ifndef __PLATFORM_H_INCLUDED
# include <sys/platform.h>
#endif

/* We really don't need to include sys/types.h at all since nothing in neutrino.h
 * depends on it.  However, we did before so for backwards compatibility we must
 * continue to do so.
 */
 extern int ThreadCtl(int __cmd, void *__data);
 #define _NTO_TCTL_IO					14
#endif
