
/*
 *  iofunc.h    Non-portable low-level IO definitions
 *

 */

#ifndef __IOFUNC_H_INCLUDED
#define __IOFUNC_H_INCLUDED

#include <sys/types.h>
#include <sys/qnxtypes.h>

#define IOFUNC_ATTR_MTIME         0x00000001  /* File written -- mtime invalid */
#define IOFUNC_ATTR_ATIME         0x00000002  /* File read -- atime invalid */
#define IOFUNC_ATTR_CTIME         0x00000004  /* File info changed -- ctime invalid */

struct _iofunc_attr;
struct _iofunc_ocb;

#ifndef RESMGR_HANDLE_T
 #ifndef IOFUNC_ATTR_T
  #define RESMGR_HANDLE_T		struct _iofunc_attr
 #else
  #define RESMGR_HANDLE_T		IOFUNC_ATTR_T
 #endif
#endif

#ifndef RESMGR_OCB_T
 #ifndef IOFUNC_OCB_T
  #define RESMGR_OCB_T			struct _iofunc_ocb
 #else
  #define RESMGR_OCB_T			IOFUNC_OCB_T
 #endif
#endif

#include <sys/resmgr.h>

typedef struct _iofunc_attr {
    uint32_t                        flags;      /* Dirty and invalid flags */
    int32_t                         lock_tid;   /* Thread that has attr locked */
    uint16_t                        lock_count; /* Lock count (0 == unlocked) */
    uint16_t                        count;      /* File use count */
    uint16_t                        rcount;     /* File reader count */
    uint16_t                        wcount;     /* File writer count */
    uint16_t                        rlocks;     /* Number of read locks */
    uint16_t                        wlocks;     /* Number of write locks */
    off_t                           nbytes;     /* Always Number of bytes */
    ino_t                           inode;      /* mount point specific inode */
    uid_t                           uid;        /* User id */
    gid_t                           gid;        /* Group id */
    dev_t                           rdev;       /* dev num for CHR special, rdev num for NAME special */
	unsigned						mtime_ns;	/* modification time (nanosecond value) */
	unsigned						atime_ns;	/* access time (nanosecond value) */
	unsigned						ctime_ns;	/* change time (nanosecond value) */
} iofunc_attr_t;

#ifndef IOFUNC_ATTR_T
#define IOFUNC_ATTR_T               iofunc_attr_t
#endif

#define _IO_READ_GET_NBYTES(msg) ((msg)->i.nbytes)
#define _IO_WRITE_GET_NBYTES(msg) ((msg)->i.nbytes)

typedef struct _iofunc_ocb {
    IOFUNC_ATTR_T                   *attr;      /* Used to find iofunc_attr_t */
    int32_t                         ioflag;     /* open's oflag + 1 */
	 off_t                           offset;
    uint16_t                        sflag; 		/* share mode flags defined as SH_DENYxx */
    uint16_t                        flags;		/* flags defined as IOFUNC_OCB_xxx */
    void                            *reserved;
} iofunc_ocb_t;

#ifndef IOFUNC_OCB_T
#define IOFUNC_OCB_T                iofunc_ocb_t
#endif
typedef struct {
}_client_info;
void iofunc_func_init(unsigned __nconnect, resmgr_connect_funcs_t *__connect, unsigned __nio, resmgr_io_funcs_t *__io);
void iofunc_attr_init_sized(iofunc_attr_t *__attr, mode_t __mode, iofunc_attr_t *__dattr, _client_info *__info, size_t __size);
extern int iofunc_open_default(resmgr_context_t *__ctp, io_open_t *__msg, iofunc_attr_t *__attr, void *__extra);
extern int iofunc_read_verify(resmgr_context_t *__ctp, io_read_t *__msg, iofunc_ocb_t *__ocb, int *__nonblock);
extern int iofunc_write_verify(resmgr_context_t *__ctp, io_write_t *__msg, iofunc_ocb_t *__ocb, int *__nonblock);
extern int iofunc_devctl_verify(const resmgr_context_t * const ctp, const io_devctl_t * const msg, const iofunc_ocb_t * const ocb, const unsigned requested_checks );
extern int iofunc_devctl_default(resmgr_context_t *__ctp, io_devctl_t *__msg, iofunc_ocb_t *__ocb);



#define iofunc_attr_init(__attr, __mode, __dattr, __info)	(iofunc_attr_init_sized((__attr), (__mode), (__dattr), (__info), sizeof(iofunc_attr_t)))


#endif

