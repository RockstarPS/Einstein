/*
 * $QNXtpLicenseC:
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
 
/*
 * Copyright (c) 1994-2000 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
 *
 */
 
#ifndef _STRING_H_INCLUDED
#define _STRING_H_INCLUDED
#define _STRING_H_DECLARED


#include <sys/stat.h>

#ifndef __cplusplus
#define NULL ((void *)0)
#else   /* C++ */
#define NULL 0
#endif  /* C++ */


#ifndef __SIZE_TYPE__
#define __SIZE_TYPE__ long unsigned int
#endif
#if !(defined (__GNUG__) && defined (size_t))
typedef __SIZE_TYPE__ size_t;
#endif

extern char *strsep (char **__restrict __stringp,
		     const char *__restrict __delim);

 
#endif