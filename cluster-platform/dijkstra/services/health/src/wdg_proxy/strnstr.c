/*-
 * Copyright (c) 2001 Mike Barcroft <mike@FreeBSD.org>
 * Copyright (c) 1990, 1993
 *  The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#if defined(LIBC_SCCS) && !defined(lint)
    static char sccsid[] = "@(#)strstr.c	8.1 (Berkeley) 6/4/93";
#endif /* LIBC_SCCS and not lint */
#include <sys/cdefs.h>

#include <string.h>
#include "strnstr.h"

/*
 * Find the first occurrence of find in s, where the search is limited to the
 * first slen characters of s.
 */
/* coverity[MISRA C-2012 Directive 8.7 violation] : FALSE */
char *strnstr ( const char *s, const char *find, size_t slen )
{
    char c = '\0';
    char sc = '\0';
    size_t len;
    char *l_ret_cp = NULL;
    /* coverity[MISRA C-2012 Directive 4.6 violation] : FALSE */
    static int ret;
    ret = 0;
    /* coverity[MISRA C-2012 Directive 13.3 17.8 violation] : FALSE */
    if ( ( c = *find++ ) != '\0' )
    {
        len = strlen ( find );

        do
        {
            do
            {
    /* coverity[MISRA C-2012 Directive 13.4 violation] : FALSE */
                sc = *s++;
                if ( ( slen-- < 1U ) || ( sc == '\0' ) )
                {
                    ret = -1;
                    break;
                }
            }
            while ( sc != c );

            if ( ( ret == -1 ) || ( len > slen ) )
            {
                ret = -1;
                break;
            }
        }
        while ( strncmp ( s, find, len ) != 0 );
/* coverity[MISRA C-2012 Directive 17.8 violation] : FALSE */
        s--;
    }

    if ( ret == 0 )
    {
/* coverity[MISRA C-2012 Directive 11.8 violation] : FALSE */
        l_ret_cp = ( char * ) s;
    }
    else
    {
        l_ret_cp = NULL;
    }

    return l_ret_cp;
}
