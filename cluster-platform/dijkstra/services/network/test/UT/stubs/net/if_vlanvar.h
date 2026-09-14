#ifndef _NET_IF_VLANVAR_H_INCLUDED
#define	_NET_IF_VLANVAR_H_INCLUDED

#include <stdint.h>
#include <sys/sockio.h>

#define	SIOCSETVLAN	SIOCSIFGENERIC
#define	SIOCGETVLAN	SIOCGIFGENERIC

/* Configuration structure for SIOCSETVLAN and SIOCGETVLAN ioctls. */
struct vlanreq {
	char		vlr_parent[IFNAMSIZ];
	unsigned short	vlr_tag;
};

#endif	/* !_NET_IF_VLANVAR_H_INCLUDED */

