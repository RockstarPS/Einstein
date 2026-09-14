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

#ifndef __DISPATCH_H_INCLUDED
#define __DISPATCH_H_INCLUDED

#ifndef __RESMGR_H_INCLUDED
# include <sys/resmgr.h>
#endif

#include <sys/siginfo.h>
# include <signal.h>

#define MSG_FLAG_ALLOC_PULSE	0x00000002
#define MSG_FLAG_SIDE_CHANNEL	0x00000200


typedef resmgr_context_t	message_context_t;

typedef struct  {
	int							rcvid;
	union {
		_msg_info		msginfo;
		siginfo_t				siginfo;
	} info;
	resmgr_iomsgs_t				*msg;
	void						*dpp;
	int							fd;
	unsigned					tid;
	unsigned					reserved;
	int							flags;
	int							reserved2[2];
	__FLEXARY(iov_t, iov); /* iov_t iov[] */
}_select_context;

typedef  _select_context	select_context_t;

typedef struct  {
	int							signo;
	union {
		_msg_info		msginfo;
		siginfo_t				siginfo;
	} info;
	resmgr_iomsgs_t				*msg;
	void 						*dpp;
	int							status;
	unsigned					tid;
	sigset_t					set;
	int							reserved2[2];
	__FLEXARY(iov_t, iov); /* iov_t iov[] */
}_sigwait_context;
typedef  _sigwait_context	sigwait_context_t;

typedef union {
	resmgr_context_t		resmgr_context;
	message_context_t		message_context;
	select_context_t		select_context;
	sigwait_context_t		sigwait_context;
} dispatch_context_t;

typedef struct{
	unsigned					flags;			/* Flags in RESMGR_FLAG_xxx set */
	unsigned					nparts_max;		/* Number of components to allocate for the IOV array */
	size_t						msg_max_size;	/* Minimum amount of room to reserve for receiving a message */
	int							(*other_func)(resmgr_context_t *, void *msg);  /* Function that's called for unhandled I/O message */
	unsigned					reserved[4];
} resmgr_attr_t;


dispatch_t				*dispatch_create(void);
dispatch_context_t 		*dispatch_block(dispatch_context_t *ctp);
int 					dispatch_handler(dispatch_context_t *ctp);
dispatch_context_t 		*dispatch_context_alloc(dispatch_t *dpp);
int resmgr_attach(dispatch_t *dpp, resmgr_attr_t *attr, const char *path,
				  const enum _file_type file_type, unsigned flags,
				  const resmgr_connect_funcs_t *connect_funcs,
				  const resmgr_io_funcs_t *io_funcs, RESMGR_HANDLE_T *handle);
int pulse_attach(dispatch_t *dpp, int flags, int code,
				 int (*func)(message_context_t *ctp, int code, unsigned flags, void *handle),
				 void *handle);				  
int message_connect(dispatch_t *dpp, int flags);	
int resmgr_detach(dispatch_t *dpp, int id, unsigned flags);
int dispatch_destroy(dispatch_t *dpp);
void dispatch_context_free(dispatch_context_t *ctp);
void					dispatch_unblock(dispatch_context_t *ctp);
			 
#endif

