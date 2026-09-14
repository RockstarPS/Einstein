#ifndef _SPAWN_H_INCLUDED
#define _SPAWN_H_INCLUDED

#include <stdint-gcc.h>
#include <sys/cdefs.h>

#ifndef __TYPES_H_INCLUDED
# include <sys/types.h>
#endif

#ifndef _SIGNAL_H_INCLUDED
# include <signal.h>
#endif

#define _Restrict __restrict

typedef uintptr_t posix_spawnattr_t;
typedef uintptr_t posix_spawn_file_actions_t;

extern int posix_spawn(
      pid_t *_Restrict                  __pid,
      const char *_Restrict             __path,
      const posix_spawn_file_actions_t * __file_actions,
      const posix_spawnattr_t *_Restrict __attrp,
      char * const                       __argv[_Restrict_arr],
      char * const                       __envp[_Restrict_arr] );
extern int posix_spawnp(
      pid_t *_Restrict                  __pid,
      const char *_Restrict             __file,
      const posix_spawn_file_actions_t * __file_actions,
      const posix_spawnattr_t *_Restrict __attrp,
      char * const                      __argv[_Restrict_arr],
      char * const                      __envp[_Restrict_arr] );


#endif
