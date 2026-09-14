
#ifndef _ERRNO_H_INCLUDED
#define _ERRNO_H_INCLUDED
#define _ERRNO_H_DECLARED



int *__get_errno_ptr(void) __attribute__((__const__));
# define errno (*__get_errno_ptr())


#define	EOK				0
#define EINTR            4  /* Interrupted function call                */
#define EEXIST          17  /* File exists                              */

#endif
