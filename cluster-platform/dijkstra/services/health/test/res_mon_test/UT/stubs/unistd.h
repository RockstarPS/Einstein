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

#ifndef NULL
# define NULL _NULL
#endif


typedef int uid_t;
extern void sync(void);

extern int seteuid(uid_t __newuserid);

static char    *optarg;	
unsigned int sleep( unsigned period );

#endif

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/branches/7.0.0/trunk/lib/c/public/unistd.h $ $Rev: 842077 $")
#endif
