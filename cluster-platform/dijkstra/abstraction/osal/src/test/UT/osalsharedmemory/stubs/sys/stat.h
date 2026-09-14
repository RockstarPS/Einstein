#ifndef _SYS_STAT_H
#define _SYS_STAT_H

#include <sys/types.h>

#ifndef __struct_stat_defined
#define __struct_stat_defined(__st_off_t, __st_time_t)			     \
{ _dev_t	st_dev; 	/* Equivalent to drive number 0=A 1=B ... */ \
  _ino_t	st_ino; 	/* Always zero ? */			     \
  _mode_t	st_mode;	/* See above constants */		     \
   short 	st_nlink;	/* Number of links. */			     \
   short 	st_uid; 	/* User: Maybe significant on NT ? */	     \
   short 	st_gid; 	/* Group: Ditto */			     \
  _dev_t	st_rdev;	/* Seems useless (not even filled in) */     \
  __st_off_t	st_size;	/* File size in bytes */		     \
  __st_time_t	st_atime;	/* Access time (always 00:00 on FAT) */	     \
  __st_time_t	st_mtime;	/* Modified time */			     \
  __st_time_t	st_ctime;	/* Creation time */			     \
}

struct stat __struct_stat_defined( _off_t, time_t );

_CRTIMP __cdecl __MINGW_NOTHROW  int fstat (int, struct stat *);

#endif
#endif