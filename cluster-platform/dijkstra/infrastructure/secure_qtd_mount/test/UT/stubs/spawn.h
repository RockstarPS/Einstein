#ifndef _SPAWN_H_INCLUDED
#define _SPAWN_H_INCLUDED

#include <stdint.h>

typedef int pid_t;
typedef unsigned posix_spawn_file_actions_t;
typedef unsigned posix_spawnattr_t;

extern int posix_spawn( pid_t * pid,
                 const char * path,
                 const posix_spawn_file_actions_t *file_actions,
                 const posix_spawnattr_t * attrp,
                 char * const argv[],
                 char * const envp[] );

pid_t waitpid( pid_t pid,
               int * stat_loc,
               int options );

#endif