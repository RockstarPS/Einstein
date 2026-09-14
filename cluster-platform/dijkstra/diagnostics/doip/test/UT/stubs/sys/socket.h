
#ifndef __SOCKET_H_INCLUDED
#define	__SOCKET_H_INCLUDED

/*
 * Definitions related to sockets: types, address families, options.
 */

#include <stdint.h>
#include <sys/cdefs.h>

#define F_GETFL         3   /*  Get file status flags   */
#define F_SETFL         4   /*  Set file status flags   */

#define O_NONBLOCK  000200  /*  Non-blocking I/O                */

/* --- Sockets --- */

/* non-blocking and interrupt i/o */
/*        EAGAIN           35        */    /* Resource temporarily unavailable */
/*        EWOULDBLOCK      35        */    /* Operation would block */
#define EWOULDBLOCK    EAGAIN              /* Operation would block */
#define EINPROGRESS       236              /* Operation now in progress */
#define EALREADY      237              /* Operation already in progress POSIX conformance */

/* ipc/network software -- argument errors */
#define ENOTSOCK        238                /* Socket operation on non-socket */
#define EDESTADDRREQ    239                /* Destination address required */
#define EMSGSIZE        240                /* Message too long */
#define EPROTOTYPE      241                /* Protocol wrong type for socket */
#define ENOPROTOOPT     242                /* Protocol not available */
#define EPROTONOSUPPORT 243                /* Protocol not configured or not supported */
#define ESOCKTNOSUPPORT 244                /* Socket type not supported */
#define EPFNOSUPPORT    246                /* Protocol family not supported */
#define EAFNOSUPPORT    247                /* Address family not supported by protocol family */
#define EADDRINUSE      248                /* Address already in use */
#define EADDRNOTAVAIL   249                /* Can't assign requested address */

/* ipc/network software -- operational errors */
#define ENETDOWN        250                /* Network is down */
#define ENETUNREACH     251                /* Network is unreachable */
#define ENETRESET       252                /* Network dropped connection on reset */
#define ECONNABORTED    253                /* Software caused connection abort */
#define ECONNRESET      254                /* Connection reset by peer */
#define ENOBUFS         255                /* No buffer space available */
#define EISCONN         256                /* Socket is already connected */
#define ENOTCONN        257                /* Socket is not connected */
#define ESHUTDOWN       258                /* Can't send after socket shutdown */
#define ETOOMANYREFS    259                /* Too many references: can't splice */
#define ETIMEDOUT       260                /* Connection timed out */
#define ECONNREFUSED    261                /* Connection refused */

/*
 * Data types.
 */
typedef uint32_t socklen_t;
typedef uint8_t sa_family_t;


/*
 * Socket types.
 */
#define	SOCK_DGRAM 2  /* datagram socket */

/*
 * Address families.
 */
#define	AF_INET  2   /* internetwork: UDP, TCP, etc. */

/*
 * Protocol families, same as address families for now.
 */
#define	PF_INET		AF_INET

/*
 * Socket types.
 */
#define	SOCK_STREAM	1		/* stream socket */
#define	SOCK_DGRAM	2		/* datagram socket */
#define	SOCK_RAW	3		/* raw-protocol interface */
#define	SOCK_RDM	4		/* reliably-delivered message */
#define	SOCK_SEQPACKET	5		/* sequenced packet stream */

/*
 * Option flags per-socket.
 */
#define	SO_DEBUG	0x0001		/* turn on debugging info recording */
#define	SO_ACCEPTCONN	0x0002		/* socket has had listen() */
#define	SO_REUSEADDR	0x0004		/* allow local address reuse */
#define	SO_KEEPALIVE	0x0008		/* keep connections alive */
#define	SO_DONTROUTE	0x0010		/* just use interface addresses */
#define	SO_BROADCAST	0x0020		/* permit sending of broadcast msgs */
#define	SO_USELOOPBACK	0x0040		/* bypass hardware when possible */
#define	SO_LINGER	0x0080		/* linger on close if data present */
#define	SO_OOBINLINE	0x0100		/* leave received OOB data in line */
#define	SO_REUSEPORT	0x0200		/* allow local address & port reuse */
#define	SO_TIMESTAMP	0x0400		/* timestamp received dgram traffic */
#define SO_BINDTODEVICE 0x0800		/* restrict traffic to an interface */

/*
 * Level number for (get/set)sockopt() to apply to socket itself.
 */
#define	SOL_SOCKET	0xffff		/* options for socket level */

/*
 * RFC 2553: protocol-independent placeholder for socket addresses
 */
#define _SS_MAXSIZE  128
#define _SS_ALIGNSIZE   (sizeof(long))
#define _SS_PAD1SIZE    (_SS_ALIGNSIZE - 2)
#define _SS_PAD2SIZE    (_SS_MAXSIZE - 2 - \
               _SS_PAD1SIZE - _SS_ALIGNSIZE)

#define	MSG_OOB		0x0001		/* process out-of-band data */
#define	MSG_PEEK	0x0002		/* peek at incoming message */
#define	MSG_DONTROUTE	0x0004		/* send without using routing tables */
#define	MSG_EOR		0x0008		/* data completes record */
#define	MSG_TRUNC	0x0010		/* data discarded before delivery */
#define	MSG_CTRUNC	0x0020		/* control data lost before delivery */
#define	MSG_WAITALL	0x0040		/* wait for full request or error */
#define	MSG_DONTWAIT	0x0080		/* this message should be nonblocking */
#define	MSG_BCAST	0x0100		/* this message was rcvd using link-level brdcst */
#define	MSG_MCAST	0x0200		/* this message was rcvd using link-level mcast */
#define	MSG_NOTIFICATION	0x0400	/* this message is a notification */
#define	MSG_NOSIGNAL	0x0800		/* do not generate SIGPIPE on EOF */


/*
 * Structure used by kernel to store most
 * addresses.
 */
struct sockaddr {
    uint8_t	sa_len;  /* total length */
    sa_family_t	sa_family; /* address family */
    char  sa_data[14];	/* actually longer; address value */
};

struct sockaddr_storage {
    uint8_t   ss_len;   /* address length */
    sa_family_t ss_family; /* address family */
    char   __ss_pad1[_SS_PAD1SIZE];
    long   __ss_align; /* force desired structure storage alignment */
    char   __ss_pad2[_SS_PAD2SIZE];
};

int	accept(int, struct sockaddr * __restrict, socklen_t * __restrict);
int	bind(int, const struct sockaddr *, socklen_t);
int	listen(int, int);
int	socket(int, int, int);
int	ioctl_socket(int, int, ...);
int	setsockopt(int, int, int, const void *, socklen_t);
ssize_t	recvfrom(int, void * __restrict, size_t, int,
	    struct sockaddr * __restrict, socklen_t * __restrict);
ssize_t	send(int, const void *, size_t, int);
ssize_t	recv(int, void *, size_t, int);
ssize_t	sendto(int, const void *,
	    size_t, int, const struct sockaddr *, socklen_t);

int fcntl(int __fildes, int __cmd, ...);

#endif /* !__SOCKET_H_INCLUDED */