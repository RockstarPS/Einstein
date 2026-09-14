/*
 * $QNXLicenseC:
 * Copyright 2007, 2009, QNX Software Systems. All Rights Reserved.
 *
 * You must obtain a written license from and pay applicable license fees to QNX
 * Software Systems before you may reproduce, modify or distribute this software,
 * or any work that includes all or part of this software.   Free development
 * licenses are available for evaluation and non-commercial purposes.  For more
 * information visit http://licensing.qnx.com or email licensing@qnx.com.
 *
 * This file may contain contributions from others.  Please review this entire
 * file for other proprietary rights or license notices, as well as the QNX
 * Development Suite License Guide at http://licensing.qnx.com/license-guide/
 * for other information.
 * $
 */

#ifndef __RESMGR_H_INCLUDED
#define __RESMGR_H_INCLUDED

#include <sys/types.h>
# include <sys/iomsg.h>

#define _RESMGR_FLAG_FTYPEALL	0x0010	/* Matching all ftypes (for redirecting servers) */


typedef struct { 
		void *iov_base; 
		size_t iov_len;
}iov_t;


typedef struct{
}dispatch_t;


typedef struct{
}io_pulse_t;


typedef union {
	unsigned short				type;

	io_pulse_t					pulse;

	_io_connect			connect;
	io_open_t					open;
	io_unlink_t					unlink;
	io_mknod_t					mknod;
	io_readlink_t				readlink;
	io_link_t					link;
	_io_combine			combine;
	io_close_t					close;
	io_write_t					write;
	io_read_t					read;
	io_stat_t					stat;
	io_devctl_t					devctl;
	io_msg_t					msg;
} resmgr_iomsgs_t;


typedef struct {						/* _msg_info	_server_info */
	uint32_t					nd;			/*  client      server */
	uint32_t					srcnd;		/*  server      n/a */
	pid_t						pid;		/*	client		server */
	int32_t						tid;		/*	thread		n/a */
	int32_t						chid;		/*	server		server */
	int32_t						scoid;		/*	server		server */
	int32_t						coid;		/*	client		client */
	int16_t						priority;	/*	thread		n/a */
	int16_t						flags;		/*	n/a			client */
	ssize_t					msglen;		/*	msg			n/a */
	ssize_t					srcmsglen;	/*	thread		n/a */
	ssize_t					dstmsglen;	/*	thread		n/a */
	uint32_t					type_id;	/*  client		server channel */
	uint32_t					reserved;
}_msg_info;


typedef struct  {
	uint16_t					type;
	uint16_t					mode;
	uint32_t					hint;
}_xendian_context;

typedef struct  {
	size_t						length;
	_xendian_context		xendian;
	void						*data; /* general purpose */
}_extended_context;

typedef struct _resmgr_context {
	int							rcvid;
	_msg_info			info;
	resmgr_iomsgs_t				*msg;
	dispatch_t					*dpp;
	int							id;
	 _extended_context	*extra;
	size_t						msg_max_size;
	long						status;
	size_t						offset;
	size_t						size;
	__FLEXARY(iov_t, iov); /* iov_t iov[] */
} resmgr_context_t;

#ifndef RESMGR_HANDLE_T
# define RESMGR_HANDLE_T		void
#endif

typedef int(*_resmgr_func_t)(resmgr_context_t *ctp, resmgr_iomsgs_t *msg, void *ocb);

typedef struct _resmgr_connect_funcs {
	unsigned	nfuncs;
	int			(*open)(resmgr_context_t *ctp, io_open_t *msg, RESMGR_HANDLE_T *handle, void *extra);
	int			(*unlink)(resmgr_context_t *ctp, io_unlink_t *msg, RESMGR_HANDLE_T *handle, void *reserved);
	int			(*readlink)(resmgr_context_t *ctp, io_readlink_t *msg, RESMGR_HANDLE_T *handle, void *reserved);
} resmgr_connect_funcs_t;
#define _RESMGR_CONNECT_NFUNCS	((sizeof(resmgr_connect_funcs_t)-sizeof(unsigned))/sizeof(void *))
#define _RESMGR_DEFAULT			(int)((~0U ^ (~0U >> 1U)) | 1U)	/* Default action (usually return ENOSYS) */
                                                                   /*See _resmgr_complete_delayed_close(). */
#define _RESMGR_NPARTS(_num)	(-(_num))				/* Reply with this many parts from ctp->iov */
#define _RESMGR_ERRNO(_err)		(_err)					/* Reply with a short status containing an errno (can be EOK) */
#define _RESMGR_PTR(_h,_p,_n)	(SETIOV((_h)->iov+0,(_p),(_n)),_RESMGR_NPARTS(1))
#define _RESMGR_STATUS(_c,_s)	((_c)->status = (_s))
#ifndef RESMGR_OCB_T
# define RESMGR_OCB_T			void
#endif
/*
 * flags for resmgr_detach()
 */
#define _RESMGR_DETACH_ALL		0x0000	/* Detach the name from the namespace and invalidate all open bindings. */
#define _RESMGR_DETACH_PATHNAME	0x0001	/* Only detach the name from the namespace */
#define _RESMGR_DETACH_CLOSE	0x8000	/* Call close on bindings when detaching */
typedef struct _resmgr_io_funcs {
	unsigned	nfuncs;
	int			(*read)(resmgr_context_t *ctp, io_read_t *msg, RESMGR_OCB_T *ocb);
	int			(*write)(resmgr_context_t *ctp, io_write_t *msg, RESMGR_OCB_T *ocb);
	int			(*close_ocb)(resmgr_context_t *ctp, void *reserved, RESMGR_OCB_T *ocb);
	int			(*stat)(resmgr_context_t *ctp, io_stat_t *msg, RESMGR_OCB_T *ocb);
	int			(*devctl)(resmgr_context_t *ctp, io_devctl_t *msg, RESMGR_OCB_T *ocb);
	int			(*pathconf)(resmgr_context_t *ctp, io_pathconf_t *msg, RESMGR_OCB_T *ocb);
	int			(*msg)(resmgr_context_t *ctp, io_msg_t *msg, RESMGR_OCB_T *ocb);
	int			(*read64)(resmgr_context_t *ctp, io_read_t *msg, RESMGR_OCB_T *ocb);
	int			(*write64)(resmgr_context_t *ctp, io_write_t *msg, RESMGR_OCB_T *ocb);
} resmgr_io_funcs_t;
#define _RESMGR_IO_NFUNCS		((sizeof(resmgr_io_funcs_t)-sizeof(unsigned))/sizeof(void *))
extern ssize_t resmgr_msgread(resmgr_context_t *__ctp, void *__msg, size_t __size, size_t __offset);


#endif