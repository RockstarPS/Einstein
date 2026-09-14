/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

/*
 *	POSIX Standard: 5.6 File Characteristics	<sys/stat.h>
 */

#ifndef	_SYS_STAT_H
#define	_SYS_STAT_H	1



// #define __U32_TYPE		unsigned int
// #define __MODE_T_TYPE		__U32_TYPE
// /* No need to mark the typedef with __extension__.   */
// # define __STD_TYPE		typedef
// __STD_TYPE __MODE_T_TYPE __mode_t;	/* Type of file attribute bitmasks.  */

#define	__S_IFMT	0170000	/* These bits determine file type.  */
#define	__S_ISTYPE(mode, mask)	(((mode) & __S_IFMT) == (mask))
#define	__S_IFDIR	0040000	/* Directory.  */
#define	S_ISDIR(mode)	 __S_ISTYPE((mode), __S_IFDIR)
struct stat
{
   unsigned int st_mode;	
};

extern int stat (const char *__restrict __file,
		 struct stat *__restrict __buf);

#endif