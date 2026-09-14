
#ifndef __SOCKET_H_INCLUDED
#define	__SOCKET_H_INCLUDED

/*
 * Definitions related to sockets: types, address families, options.
 */

#include <stdint.h>
#include <sys/cdefs.h>

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
 * RFC 2553: protocol-independent placeholder for socket addresses
 */
#define _SS_MAXSIZE  128
#define _SS_ALIGNSIZE   (sizeof(long))
#define _SS_PAD1SIZE    (_SS_ALIGNSIZE - 2)
#define _SS_PAD2SIZE    (_SS_MAXSIZE - 2 - \
               _SS_PAD1SIZE - _SS_ALIGNSIZE)

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

__BEGIN_DECLS

int	socket(int, int, int);
int	ioctl_socket(int, int, ...);

__END_DECLS

#endif /* !__SOCKET_H_INCLUDED */