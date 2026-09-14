
#ifndef __SOCKET_H_INCLUDED
#define	__SOCKET_H_INCLUDED

/* Duplicate info from sys/socket.h.  */
typedef unsigned int __socklen_t;

/* Type for length arguments in socket calls.  */
#ifndef __socklen_t_defined
typedef __socklen_t socklen_t;
# define __socklen_t_defined
#endif

/* POSIX.1g specifies this type name for the `sa_family' member.  */
typedef unsigned short int sa_family_t;

/* This macro is used to declare the initial common members
   of the data types used for socket addresses, `struct sockaddr',
   `struct sockaddr_in', `struct sockaddr_un', etc.  */

#define	__SOCKADDR_COMMON(sa_prefix) \
  sa_family_t sa_prefix##family

#define __SOCKADDR_COMMON_SIZE	(sizeof (unsigned short int))

/*
 * Definitions related to sockets: types, address families, options.
 */
/* Structure describing a generic socket address.  */
struct sockaddr
  {
    __SOCKADDR_COMMON (sa_);	/* Common data: address family and length.  */
    char sa_data[14];		/* Address data.  */
  };

/* Protocol families.  */
#define PF_INET		2	/* IP protocol family.  */

/* Address families.  */
#define AF_INET		PF_INET

/* Types of sockets.  */
enum __socket_type
{
  SOCK_STREAM = 1,		/* Sequenced, reliable, connection-based
				   byte streams.  */
#define SOCK_STREAM SOCK_STREAM
  SOCK_DGRAM = 2,		/* Connectionless, unreliable datagrams
				   of fixed maximum length.  */
#define SOCK_DGRAM SOCK_DGRAM
  SOCK_RAW = 3,			/* Raw protocol interface.  */
#define SOCK_RAW SOCK_RAW
  SOCK_RDM = 4,			/* Reliably-delivered messages.  */
#define SOCK_RDM SOCK_RDM
  SOCK_SEQPACKET = 5,		/* Sequenced, reliable, connection-based,
				   datagrams of fixed maximum length.  */
#define SOCK_SEQPACKET SOCK_SEQPACKET
  SOCK_DCCP = 6,		/* Datagram Congestion Control Protocol.  */
#define SOCK_DCCP SOCK_DCCP
  SOCK_PACKET = 10,		/* Linux specific way of getting packets
				   at the dev level.  For writing rarp and
				   other similar things on the user level. */
#define SOCK_PACKET SOCK_PACKET

  /* Flags to be ORed into the type parameter of socket and socketpair and
     used for the flags parameter of paccept.  */

  SOCK_CLOEXEC = 02000000,	/* Atomically set close-on-exec flag for the
				   new descriptor(s).  */
#define SOCK_CLOEXEC SOCK_CLOEXEC
  SOCK_NONBLOCK = 00004000	/* Atomically mark descriptor(s) as
				   non-blocking.  */
#define SOCK_NONBLOCK SOCK_NONBLOCK
};

#define SOL_SOCKET 1
#define SO_ACCEPTCONN 30
#define SO_BROADCAST 6
#define SO_DONTROUTE 5
#define SO_ERROR 4
#define SO_KEEPALIVE 9
#define SO_LINGER 13
#define SO_OOBINLINE 10
#define SO_RCVBUF 8
#define SO_RCVLOWAT 18
#define SO_RCVTIMEO 20
#define SO_REUSEADDR 2
#define SO_SNDBUF 7
#define SO_SNDLOWAT 19
#define SO_SNDTIMEO 21
#define SO_TYPE 3

# define __SOCKADDR_ARG		struct sockaddr *__restrict
# define __CONST_SOCKADDR_ARG	const struct sockaddr *

int socket (int __domain, int __type, int __protocol);
int bind (int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len);
int connect (int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len);
ssize_t send (int __fd, const void *__buf, size_t __n, int __flags);
ssize_t recv (int __fd, void *__buf, size_t __n, int __flags);
ssize_t sendto (int __fd, const void *__buf, size_t __n, int __flags, __CONST_SOCKADDR_ARG __addr, socklen_t __addr_len);
ssize_t recvfrom (int __fd, void *__restrict __buf, size_t __n, int __flags, __SOCKADDR_ARG __addr, socklen_t *__restrict __addr_len);

int getsockopt (int __fd, int __level, int __optname, void *__restrict __optval, socklen_t *__restrict __optlen);

int setsockopt (int __fd, int __level, int __optname, const void *__optval, socklen_t __optlen);
int listen (int __fd, int __n);
int accept (int __fd, __SOCKADDR_ARG __addr, socklen_t *__restrict __addr_len);

#endif /* !__SOCKET_H_INCLUDED */