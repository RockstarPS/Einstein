#ifndef _NET_IF_H_INCLUDED
#define _NET_IF_H_INCLUDED

#include <sys/socket.h>

typedef char *          caddr_t;

#define IF_NAMESIZE  16
#define	IFNAMSIZ     IF_NAMESIZE

#define	IFF_UP      0x00000001   /* interface is up */
#define	IFF_RUNNING 0x00000040   /* resources allocated */

/*
 * Interface request structure used for socket
 * ioctl's.  All interface ioctl's must have parameter
 * definitions which begin with ifr_name.  The
 * remainder may be interface specific.
 */
struct	ifreq {
	char	ifr_name[IFNAMSIZ];		/* if name, e.g. "en0" */
	union {
		struct	sockaddr ifru_addr;
		struct	sockaddr ifru_dstaddr;
		struct	sockaddr ifru_broadaddr;
		struct	sockaddr_storage ifru_space;
		int	ifru_flags;
		int	ifru_metric;
		int	ifru_mtu;
		int	ifru_dlt;
		unsigned int	ifru_value;
		void *	ifru_data;
		struct {
			uint32_t	b_buflen;
			void		*b_buf;
		} ifru_b;
	} ifr_ifru;
};

#define ifr_addr      ifr_ifru.ifru_addr	/* address */
#define ifr_dstaddr   ifr_ifru.ifru_dstaddr	/* other end of p-to-p link */
#define ifr_broadaddr ifr_ifru.ifru_broadaddr	/* broadcast address */
#define ifr_space     ifr_ifru.ifru_space	/* sockaddr_storage */
#define ifr_flags     ifr_ifru.ifru_flags	/* flags */
#define ifr_metric    ifr_ifru.ifru_metric	/* metric */
#define ifr_mtu       ifr_ifru.ifru_mtu	/* mtu */
#define ifr_dlt       ifr_ifru.ifru_dlt	/* data link type (DLT_*) */
#define ifr_value     ifr_ifru.ifru_value	/* generic value */
#define ifr_media     ifr_ifru.ifru_metric	/* media options (overload) */
#define ifr_data      ifr_ifru.ifru_data	/* for use by interface*/
#define	ifr_buf       ifr_ifru.ifru_b.b_buf	/* new interface ioctls */
#define	ifr_buflen    ifr_ifru.ifru_b.b_buflen

struct ifmediareq{
    char ifm_name[IFNAMSIZ];		/* if name, e.g. "en0" */
    int  ifm_current;			/* current media options */
    int  ifm_mask;			/* don't care mask */
    int  ifm_status;			/* media status */
    int  ifm_active;			/* active options */
    int  ifm_count;			/* # entries in ifm_ulist  array */
    int  *ifm_ulist;			/* media words */
};

struct ifaliasreq {
	char	ifra_name[IFNAMSIZ];		/* if name, e.g. "en0" */
	struct	sockaddr ifra_addr;
	struct	sockaddr ifra_dstaddr;
#define	ifra_broadaddr	ifra_dstaddr
	struct	sockaddr ifra_mask;
};

#endif /* !_NET_IF_H_INCLUDED */

