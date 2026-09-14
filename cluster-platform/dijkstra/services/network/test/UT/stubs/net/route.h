#ifndef _NET_ROUTE_H_INCLUDED
#define _NET_ROUTE_H_INCLUDED

#include <stdint.h>
#include <sys/socket.h>
#include <net/if.h>

struct ortentry {
	uint32_t rt_hash;		/* to speed lookups */
	struct	sockaddr rt_dst;	/* key */
	struct	sockaddr rt_gateway;	/* value */
	struct	sockaddr rt_netmask;	/* netmask */
	int16_t	rt_flags;		/* up/down?, host/net */
	int16_t	rt_refcnt;		/* # held references */
	uint32_t rt_use;		/* raw # packets forwarded */
	struct	ifnet *rt_ifp;		/* the answer: interface to use */
};

#endif /* !_NET_ROUTE_H_INCLUDED */
