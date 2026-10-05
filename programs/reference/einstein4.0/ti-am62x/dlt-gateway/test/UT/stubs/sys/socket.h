
#ifndef __SOCKET_H_INCLUDED
#define	__SOCKET_H_INCLUDED

/*
 * Definitions related to sockets: types, address families, options.
 */

#include <stdint.h>
//#include <sys/cdefs.h>

/*
 * Data types.
 */
typedef uint32_t socklen_t;
typedef uint8_t sa_family_t;


/* For setsockopt(2) */
#define SOL_SOCKET	1

#define SO_DEBUG	1
#define SO_REUSEADDR	2
#define SO_TYPE		3
#define SO_ERROR	4
#define SO_DONTROUTE	5
#define SO_BROADCAST	6
#define SO_SNDBUF	7
#define SO_RCVBUF	8
#define SO_SNDBUFFORCE	32
#define SO_RCVBUFFORCE	33
#define SO_KEEPALIVE	9
#define SO_OOBINLINE	10
#define SO_NO_CHECK	11
#define SO_PRIORITY	12
#define SO_LINGER	13
#define SO_BSDCOMPAT	14
#define SO_REUSEPORT	15
#ifndef SO_PASSCRED /* powerpc only differs in these */
#define SO_PASSCRED	16
#define SO_PEERCRED	17
#define SO_RCVLOWAT	18
#define SO_SNDLOWAT	19
#define SO_RCVTIMEO_OLD	20
#define SO_SNDTIMEO_OLD	21
#endif

/*
 * Socket types.
 */
#define	SOCK_DGRAM 2  /* datagram socket */

#define SOCK_STREAM 1
/*
 * Address families.
 */
#define	AF_INET  2   /* internetwork: UDP, TCP, etc. */

/*
 * RFC 2553: protocol-independent placeholder for socket addresses
 */
#define _SS_MAXSIZE  128
#define _SS_ALIGNSIZE   (sizeof(long))
#define _SS_PAD1SIZE    (_SS_ALIGNSIZE - 2)
#define _SS_PAD2SIZE    (_SS_MAXSIZE - 2 - \
               _SS_PAD1SIZE - _SS_ALIGNSIZE)


#define MSG_NOSIGNAL 0x4000 /* Do not generate SIGPIPE.  */

//typedef long ssize_t;
//typedef long size_t;
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


int	socket(int, int, int);
int	ioctl_socket(int, int, ...);

extern int setsockopt (int __fd, int __level, int __optname,
       const void *__optval, socklen_t __optlen);

int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

int listen(int sockfd, int backlog);

int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

long send(int sockfd, const void *buf, long len, int flags);

#endif /* !__SOCKET_H_INCLUDED */