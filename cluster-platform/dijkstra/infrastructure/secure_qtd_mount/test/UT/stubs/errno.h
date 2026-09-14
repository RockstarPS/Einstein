
#ifndef _ERRNO_H_INCLUDED
#define _ERRNO_H_INCLUDED
#define _ERRNO_H_DECLARED

extern int errno;
#ifndef errno
int *__get_errno_ptr(void) __attribute__((__const__));
# define errno (*__get_errno_ptr())
#endif

/* for c11 */
#ifdef __ERRNO_T
typedef __ERRNO_T errno_t;
#undef __ERRNO_T
#endif


// int *__get_errno_ptr(void) __attribute__((__const__));
// # define errno (*__get_errno_ptr())


/* --- Symbolic names of the error return conditions --- */

#define EOK              0  /* No error                                 */
#define EPERM            1  /* Operation not permitted                  */
#define ENOENT           2  /* No such file or directory                */
#define ESRCH            3  /* No such process                          */
#define EINTR            4  /* Interrupted function call                */
#define EIO              5  /* Input/output error                       */
#define ENXIO            6  /* No such device or address                */
#define E2BIG            7  /* Arg list too long                        */
#define ENOEXEC          8  /* Exec format error                        */
#define EBADF            9  /* Bad file descriptor                      */
#define ECHILD          10  /* No child processes                       */
#define EAGAIN          11  /* Resource temporarily unavailable         */
#define ENOMEM          12  /* Not enough memory                        */
#define EACCES          13  /* Permission denied                        */
#define EFAULT          14  /* Bad address                              */
#define ENOTBLK         15  /* Block device required                    */
#define EBUSY           16  /* Resource busy                            */
#define EEXIST          17  /* File exists                              */
#define EXDEV           18  /* Improper link                            */
#define ENODEV          19  /* No such device                           */
#define ENOTDIR         20  /* Not a directory                          */
#define EISDIR          21  /* Is a directory                           */
#define EINVAL          22  /* Invalid argument                         */
#define ENFILE          23  /* Too many open files in system            */
#define EMFILE          24  /* Too many open files                      */
#define ENOTTY          25  /* Inappropriate I/O control operation      */
#define ETXTBSY         26  /* Text file busy                           */
#define EFBIG           27  /* File too large                           */
#define ENOSPC          28  /* No space left on device                  */
#define ESPIPE          29  /* Invalid seek                             */
#define EROFS           30  /* Read-only file system                    */
#define EMLINK          31  /* Too many links                           */
#define EPIPE           32  /* Broken pipe                              */
#define EDOM            33  /* Domain error                             */
#define ERANGE          34  /* Result too large                         */
#define ENOMSG          35  /* No message of desired type               */
#define EIDRM           36  /* Identifier removed                       */
#define ECHRNG          37  /* Channel number out of range              */
#define EL2NSYNC        38  /* Level 2 not synchronized                 */
#define EL3HLT          39  /* Level 3 halted                           */
#define EL3RST          40  /* Level 3 reset                            */
#define ELNRNG          41  /* Link number out of range                 */
#define EUNATCH         42  /* Protocol driver not attached             */
#define ENOCSI          43  /* No CSI structure available               */
#define EL2HLT          44  /* Level 2 halted                           */
#define EDEADLK         45  /* Resource deadlock avoided                */
#define ENOLCK          46  /* No locks available                       */
#define ECANCELED       47  /* Operation canceled                       */
#define ENOTSUP         48  /* Not supported                            */

#endif
