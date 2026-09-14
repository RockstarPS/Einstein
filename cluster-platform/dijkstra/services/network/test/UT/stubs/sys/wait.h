#ifndef	_SYS_WAIT_H
#define	_SYS_WAIT_H	1

#include <sys/cdefs.h>
#include <sys/types.h>
#include <stdint.h>
#include <stub_unistd.h>

#define WIFEXITED(__status)		(((__status) & 0x7f) == 0)

__BEGIN_DECLS

extern pid_t wait(int *__stat_loc);
extern pid_t waitpid(pid_t __pid, int *__stat_loc, int __options);

__END_DECLS

#endif /* sys/wait.h  */
