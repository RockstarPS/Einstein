

#ifndef __IOMSG_H_INCLUDED
#define __IOMSG_H_INCLUDED

#include <stdint.h>
#include <sys/types.h>
#include <sys/platform.h>
#include <sys/stat.h>
#include <sys/ftype.h>


/***********************************************************************
 * IO message types which are pathname based                           *
 ***********************************************************************/
 enum _msg_bases {
	_IO_BASE = 0x100,
	_IO_MAX = 0x1FF
};

 enum _io__Uint16types {
	_IO_CONNECT = _IO_BASE,
	_IO_READ,
	_IO_WRITE,
	_IO_RSVD_CLOSE_OCB,		/* Place holder in jump table */
	_IO_STAT,
	_IO_NOTIFY,
	_IO_DEVCTL,
	_IO_RSVD_UNBLOCK,		/* Place holder in jump table */
	_IO_PATHCONF,
	_IO_LSEEK,
	_IO_CHMOD,
	_IO_CHOWN,
	_IO_UTIME,
	_IO_OPENFD,
	_IO_FDINFO,
	_IO_LOCK,
	_IO_SPACE,
	_IO_SHUTDOWN,
	_IO_MMAP,
	_IO_MSG,
	_IO_RSVD,
	_IO_DUP,
	_IO_CLOSE,
	_IO_RSVD_LOCK_OCB,		/* Place holder in jump table */
	_IO_RSVD_UNLOCK_OCB,	/* Place holder in jump table */
	_IO_SYNC,
	_IO_POWER,
	_IO_ACL,
	_IO_RSVD_PAUSE,			/* Place holder in jump table */
	_IO_RSVD_UNPAUSE,		/* Place holder in jump table */
	_IO_READ64,
	_IO_WRITE64,
	_IO_NOTIFY64,
	_IO_UTIME64,
};
 
 enum _io_msg_xtypes {
	_IO_XTYPE_NONE,
	_IO_XTYPE_READCOND,
	_IO_XTYPE_MQUEUE,
	_IO_XTYPE_TCPIP,
	_IO_XTYPE_TCPIP_MSG,
	_IO_XTYPE_OFFSET,
	_IO_XTYPE_REGISTRY,
	_IO_XTYPE_TCPIP_MSG2,
	_IO_XTYPE_TCPIP_MMSG,
	_IO_XTYPE_READDIR,
	_IO_XTYPE_MASK =			0x000000ff,

	/*
	 * The _IO_XFLAG_DIR_EXTRA_HINT flag is only valid when
	 * reading from a directory. The filesystem should normally
	 * return extra directory information when it is easy to get.
	 * If this flag is set, it is a hint to the filesystem
	 * to try harder (possibly causing media lookups) to return
	 * the extra information. The most common use would be to
	 * return _DTYPE_LSTAT information.
	 */
	_IO_XFLAG_DIR_EXTRA_HINT =	0x00000100,

	_IO_XFLAG_NONBLOCK =		0x00004000,
	_IO_XFLAG_BLOCK =			0x00008000,
	/* Upper 16 bits are for use by the specific xtype */

	/* only valid when reading from a directory */
	_IO_XFLAG_DIR_STAT_FORM_UNSET    = 0x00000000,
	_IO_XFLAG_DIR_STAT_FORM_T32_2001 = 0x00010000,
	_IO_XFLAG_DIR_STAT_FORM_T32_2008 = 0x00020000,
	_IO_XFLAG_DIR_STAT_FORM_T64_2008 = 0x00030000,
	_IO_XFLAG_DIR_STAT_FORM_MASK     = 0x000f0000,
};

/*
 * Message of _IO_CONNECT
 */
typedef struct {
	uint16_t				type;
	uint16_t				subtype;		/* _IO_CONNECT_? */
	uint32_t				file_type;		/* _FTYPE_? in sys/ftype.h */
	uint16_t				reply_max;
	uint16_t				entry_max;
	uint32_t				key;
	uint32_t				handle;
	uint32_t				ioflag;			/* O_? in fcntl.h & _IO_FLAG_? */
	uint32_t				mode;			/* S_IF? in sys/stat.h */
	uint16_t				sflag;			/* SH_? in share.h */
	uint16_t				access;			/* S_I in sys/stat.h */
	uint16_t				zero;
	uint16_t				path_len;
	uint8_t					eflag;			/* _IO_CONNECT_EFLAG_? */
	uint8_t					extra_type;		/* _IO_CONNECT_EXTRA_? */
	uint16_t				extra_len;
	__FLEXARY(char, path); /* path_len, null, extra_len */
}_io_connect;

/* struct _io_connect subtype */
typedef enum  {
	_IO_CONNECT_COMBINE,		/* Combine with IO msg */
	_IO_CONNECT_COMBINE_CLOSE,	/* Combine with IO msg and always close */
		_IO_CONNECT_OPEN,
		_IO_CONNECT_UNLINK,
		_IO_CONNECT_RENAME,
		_IO_CONNECT_MKNOD,
		_IO_CONNECT_READLINK,
		_IO_CONNECT_LINK,
		_IO_CONNECT_RSVD_UNBLOCK,	/* Place holder in jump table */
		_IO_CONNECT_MOUNT
		  }_io_connect_subtypes;

/* struct _io_connect ioflag (non-masked values match O_? in fcntl.h) */
#define _IO_FLAG_RD					0x00000001  /* read permission */
#define _IO_FLAG_WR					0x00000002  /* write permission */
#define _IO_FLAG_EX					0x00000004  /* exec permission */
#define _IO_FLAG_MASK				0x00000007  /* permission mask */

/* struct _io_connect eflag */
#define _IO_CONNECT_EFLAG_DIR		0x01	/* Path referenced a directory    */
#define _IO_CONNECT_EFLAG_DOT		0x02	/* Last component was . or ..     */
#define _IO_CONNECT_EFLAG_DOTDOT	0x04	/* Last component was ..          */

/*
 * return status from connect (These are continuation cases that
 * always negative (RET_FLAG is set). To avoid conflicting io msgs
 * must never return a negative status
 */
#define _IO_CONNECT_RET_UMASK		0x00020000	/* umask field in link reply is valid */
#define _IO_CONNECT_RET_NOCTTY		0x00040000	/* No controlling terminal defined  */
#define _IO_CONNECT_RET_CHROOT		0x00080000	/* chroot_len field in link reply is valid */
#define _IO_CONNECT_RET_MSG			0x00100000	/* Connect to server and send new message */

#define _IO_CONNECT_RET_TYPE_MASK	0x0001e000	/* Mask for returned file type */
#define _IO_CONNECT_RET_FTYPE		0x00008000	/* File type was matched, _io_connect_ftype_reply expected */
#define _IO_CONNECT_RET_LINK		0x00010000  /* Not fully resolved, follow link */

#define _IO_CONNECT_RET_FLAG		0x80000000	/* Must be set to signify connect is returning */

#define _IO_SET_CONNECT_RET(_c, _s)	_RESMGR_STATUS(_c, ((long)_IO_CONNECT_RET_FLAG | (long)(_s)))		/* Sets the connect return code */

/* _io_connect reply redirecting resolution to other entries */
typedef struct  {
	uint32_t					reserved1;
    uint32_t                    file_type;      /*_FTYPE_? in sys/ftype.h */
	uint8_t						eflag;          /* _IO_CONNECT_EFLAG_? */
	uint8_t						reserved2[1];
	uint16_t					chroot_len;		/* len of chroot in returned path*/
	uint32_t					umask;			/* S_IF? in sys/stat.h */
	uint16_t					nentries;		/* If zero, path is a symbolic link */
	uint16_t					path_len;       /* len includs null, if zero, path is null terminated */
	/*
	  struct _io_connect_entry	server[nentries];
	  char						path[path_len];
	  or
	  struct _server_info32			info;
	  io_?_t						msg;
	*/
}_io_connect_link_reply;

/* _io_connect reply indicating a change/reply of a certain ftype and errno */
typedef struct  {
	uint16_t                                        status;                 /* Typically an errno */
	uint16_t                                        reserved;
	uint32_t                                        file_type;              /* _FTYPE_? in sys/ftype.h */
}_io_connect_ftype_reply;

/* used in _io_connect_link_reply */
typedef struct  {
	uint32_t						nd;
	int32_t							pid;
	int32_t							chid;
	uint32_t						handle;
	uint32_t						key;
	uint32_t						file_type;
	uint16_t						prefix_len;
	uint16_t						zero[3];
}_io_connect_entry;

typedef union {
	 _io_connect					connect;
	 _io_connect_link_reply		link_reply;
	 _io_connect_ftype_reply		ftype_reply;
} io_open_t;


typedef union {
	 _io_connect					connect;
	 _io_connect_link_reply		link_reply;
	 _io_connect_ftype_reply		ftype_reply;
} io_unlink_t;



typedef union {
	 _io_connect					connect;
	 _io_connect_link_reply		link_reply;
	 _io_connect_ftype_reply		ftype_reply;
} io_mknod_t;


typedef union {
	 _io_connect					connect;
	 _io_connect_link_reply		link_reply;
	 _io_connect_ftype_reply		ftype_reply;
} io_readlink_t;


typedef union {
	 _io_connect					connect;
	 _io_connect_link_reply		link_reply;
	 _io_connect_ftype_reply		ftype_reply;
} io_link_t;

struct _io_resmgr_link_extra {
	uint32_t							nd;
	int32_t								pid;
	int32_t								chid;
	uint32_t							handle;
	uint32_t							flags;			/* Members from the PATHMGR_FLAG_xxx set */
	uint32_t							file_type;		/* Value from the _FTYPE_xxx set */
	uint32_t							reserved[2];
};


/***********************************************************************
 * IO message types which are fd based                                 *
 ***********************************************************************/

/*
 * Common header for combining io messages
 */
typedef struct  {
	uint16_t					type;
	uint16_t					combine_len;
}_io_combine;

#define _IO_COMBINE_FLAG		0x8000u		/* Ored with combine len to cause combine */


/*
 * Message of _IO_CLOSE
 */
typedef struct  {
	uint16_t					type;
	uint16_t					combine_len;
}_io_close;

typedef union {
	_io_close			i;
} io_close_t;

/*
 * Message of _IO_WRITE
 */
typedef struct  {
	/* NOTE: fields of _io_write and _io_write64 are intended to overlap.
	 * The structures must be the same size.  Don't modify one without modifying the other!
	 */
	uint16_t					type;
	uint16_t					combine_len;
	uint32_t					nbytes;
	uint32_t					xtype;
	uint32_t					zero;
	/*	unsigned char				data[nbytes];	*/
}_io_write;

typedef struct  {
	/* NOTE: fields of _io_write and _io_write64 are intended to overlap.
	 * The structures must be the same size.  Don't modify one without modifying the other!
	 */
	uint16_t					type;
	uint16_t					combine_len;
	uint32_t					nbytes;
	uint32_t					xtype;
	uint32_t					nbytes_hi;
	/*	unsigned char				data[nbytes];	*/
}_io_write64;


typedef union {
	 _io_write			i;
	 _io_write64			i64;
	/*	nbytes is returned with MsgReply */
} io_write_t;

#define _IO_SET_WRITE_NBYTES(_c, _s)	_RESMGR_STATUS(_c, _s)

/*
 * Message of _IO_READ[64]
 */
typedef struct  {
	/* NOTE: fields of _io_read and _io_read64 are intended to overlap.
	 * The structures must be the same size.  Don't modify one without modifying the other!
	 */
	uint16_t					type;
	uint16_t					combine_len;
	uint32_t					nbytes;
	uint32_t					xtype;
	uint32_t					zero;
}_io_read;

typedef struct  {
	/* NOTE: fields of _io_read and _io_read64 are intended to overlap.
	 * The structures must be the same size.  Don't modify one without modifying the other!
	 */
	uint16_t					type;
	uint16_t					combine_len;
	uint32_t					nbytes;
	uint32_t					xtype;
	uint32_t					nbytes_hi;
}_io_read64;

typedef union {
	 _io_read				i;
	 _io_read64			i64;
	/*	unsigned char				data[nbytes];	*/
	/*	nbytes is returned with MsgReply */
} io_read_t;

#define _IO_SET_READ_NBYTES(_c, _s)	_RESMGR_STATUS(_c, _s)

/*
 * Message of _IO_STAT
 */
typedef struct  {
	uint16_t					type;
	uint16_t					combine_len;
	union {
		uint32_t				zero;
		uint32_t				format;
	};
}_io_stat;

typedef struct{
}stat;

typedef union {
	 _io_stat				i;
	 stat					o;
} io_stat_t;


/*  Flags for calling iofunc_devctl_verify() that indicate what type of 
	validation needs to be performed.  These can be OR'd together.  See also
	the function header for iofunc_devctl_verify().

	The _IO_DEVCTL_VERIFY_ACC_xxx flags are used to perform user/group level
	permission checks.  These are used to what should be used when the
	iofunc_check_access function is called.  The _IO_DEVCTL_VERIFY_ACC_ISUID 
	and _IO_DEVCTL_VERIFY_ACC_ISGID flags are mutually exclusive.
*/
#define _IO_DEVCTL_VERIFY_LEN     		0x00000001U  /* Deprecated - The encoded length should match the message .nbytes field
                             		                    .nbytes could be wrong - Use instead _IO_DEVCTL_VERIFY_MSG_LEN */
#define _IO_DEVCTL_VERIFY_DIR     		0x00000002U  /* The ioflags should match the encoded direction value */
#define _IO_DEVCTL_VERIFY_PRIV    		0x00000004U  /* Only privileged users can perform this devctl */
#define _IO_DEVCTL_VERIFY_OCB_READ		0x00000008U  /* OCB must have read access */
#define _IO_DEVCTL_VERIFY_OCB_WRITE		0x00000010U  /* OCB must have write access */
#define _IO_DEVCTL_VERIFY_ACC_ISUID		0x00000020U  /* effective user ID must matches ocb->attr->uid */
#define _IO_DEVCTL_VERIFY_ACC_ISGID		0x00000040U  /* effective group ID or supplementary group IDs matches ocb->attr->gid */
#define _IO_DEVCTL_VERIFY_ACC_IREAD		0x00000080U  /* must have READ access specified by ocb->attr->mode */
#define _IO_DEVCTL_VERIFY_ACC_IWRITE	0x00000100U  /* must have WRITE access specified by ocb->attr->mode */
#define _IO_DEVCTL_VERIFY_ACC_IEXEC		0x00000200U  /* must have EXEC access specified by ocb->attr->mode */
#define _IO_DEVCTL_VERIFY_MSG_LEN  		0x00000400U  /* must have received enough data to cover the encoded length  */

/*  This is a mask of all user/group permission checks for 
	iofunc_devctl_verify().  Since the _IO_DEVCTL_VERIFY_ACC_ISGID and
	_IO_DEVCTL_VERIFY_ACC_ISUID bits are mutually exclusive, this cannot be
	passed directly into iofunc_devctl_verify().
*/
#define _IO_DEVCTL_VERIFY_ACC_MASK		0x000003E0U  /* mask of all _IO_DEVCTL_VERIFY_ACC_xxx bits */


/*
 * Message of _IO_DEVCTL
 */
typedef struct  {
	uint16_t					type;
	uint16_t					combine_len;
	int32_t						dcmd;
	uint32_t					nbytes;
	int32_t						zero;
	/*	char						data[nbytes]; */
}_io_devctl;

typedef struct  {
	uint32_t					zero;
	int32_t						ret_val;
	uint32_t					nbytes;
	int32_t						zero2;
	/*	char						data[nbytes]; */
}_io_devctl_reply;

typedef union {
	 _io_devctl			i;
	 _io_devctl_reply		o;
} io_devctl_t;


/*
 * Message of _IO_PATHCONF
 */
typedef struct  {
	uint16_t					type;
	uint16_t					combine_len;
	short						name;
	uint16_t					zero;
}_io_pathconf;

typedef union {
	 _io_pathconf			i;
	/*	value is returned with MsgReply */
} io_pathconf_t;

#define _IO_SET_PATHCONF_VALUE(_c, _s)	_RESMGR_STATUS(_c, _s)


/*
 * Message of _IO_MSG
 */
typedef struct  {
	uint16_t					type;
	uint16_t					combine_len;
	uint16_t					mgrid;		/* manager id (sys/iomgr.h) */
	uint16_t					subtype;	/* manager specific subtype */
}_io_msg;

typedef union {
	 _io_msg				i;
} io_msg_t;

#endif

