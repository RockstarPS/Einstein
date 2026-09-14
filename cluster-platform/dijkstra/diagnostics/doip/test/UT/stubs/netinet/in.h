
#ifndef _NETINET_IN_H_INCLUDED
#define	_NETINET_IN_H_INCLUDED

#include <sys/socket.h>
#include <net/netbyte.h>

/*
 * Protocols
 */
#define	IPPROTO_IP		0		/* dummy for IP */
#define	IPPROTO_HOPOPTS		0		/* IP6 hop-by-hop options */
#define	IPPROTO_ICMP		1		/* control message protocol */
#define	IPPROTO_IGMP		2		/* group mgmt protocol */
#define	IPPROTO_GGP		3		/* gateway^2 (deprecated) */
#define	IPPROTO_IPV4		4 		/* IP header */
#define	IPPROTO_IPIP		4		/* IP inside IP */
#define	IPPROTO_TCP		6		/* tcp */
#define	IPPROTO_EGP		8		/* exterior gateway protocol */
#define	IPPROTO_PUP		12		/* pup */
#define	IPPROTO_UDP		17		/* user datagram protocol */
#define	IPPROTO_IDP		22		/* xns idp */
#define	IPPROTO_TP		29 		/* tp-4 w/ class negotiation */
#define	IPPROTO_IPV6		41		/* IP6 header */
#define	IPPROTO_ROUTING		43		/* IP6 routing header */
#define	IPPROTO_FRAGMENT	44		/* IP6 fragmentation header */
#define	IPPROTO_RSVP		46		/* resource reservation */
#define	IPPROTO_GRE		47		/* GRE encaps RFC 1701 */
#define	IPPROTO_ESP		50 		/* encap. security payload */
#define	IPPROTO_AH		51 		/* authentication header */
#define	IPPROTO_MOBILE		55		/* IP Mobility RFC 2004 */
#define	IPPROTO_IPV6_ICMP	58		/* IPv6 ICMP */
#define	IPPROTO_ICMPV6		58		/* ICMP6 */
#define	IPPROTO_NONE		59		/* IP6 no next header */
#define	IPPROTO_DSTOPTS		60		/* IP6 destination option */
#define	IPPROTO_EON		80		/* ISO cnlp */
#define	IPPROTO_ETHERIP		97		/* Ethernet-in-IP */
#define	IPPROTO_ENCAP		98		/* encapsulation header */
#define	IPPROTO_PIM		103		/* Protocol indep. multicast */
#define	IPPROTO_QNET		106		/* qnet protocol */
#define	IPPROTO_IPCOMP		108		/* IP Payload Comp. Protocol */
#define	IPPROTO_VRRP		112		/* VRRP RFC 2338 */
#define	IPPROTO_CARP		112		/* Common Address Resolution Protocol */
#define	IPPROTO_SCTP		132		/* SCTP RFC 2960 */
#define	IPPROTO_RAW		255		/* raw IP packet */
#define	IPPROTO_MAX		256

/* last return value of *_input(), meaning "all job for this pkt is done".  */
#define	IPPROTO_DONE		257

/* sysctl placeholder for (FAST_)IPSEC */
#define CTL_IPPROTO_IPSEC	258

/* only used internally, so can be outside the range of valid IP protocols. */
#define	IPPROTO_DIVERT		259		/* divert pseudo-protocol */

#ifdef _KERNEL
#define	__IPADDR(x)	((uint32_t) htonl((uint32_t)(x)))
#else
#define	__IPADDR(x)	((uint32_t)(x))
#endif

#define	INADDR_ANY		__IPADDR(0x00000000)
#define	INADDR_LOOPBACK		__IPADDR(0x7f000001)
#define	INADDR_BROADCAST	__IPADDR(0xffffffff)	/* must be masked */
#define	INADDR_NONE		__IPADDR(0xffffffff)	/* -1 return */

/*
 * Internet address (a structure for historical reasons)
 */
struct in_addr {
   uint32_t s_addr;
} __attribute__((__packed__));

/*
 * Socket address, internet style.
 */
struct sockaddr_in {
	uint8_t		sin_len;
	sa_family_t	sin_family;
	uint16_t	sin_port;
	struct in_addr	sin_addr;
	int8_t		sin_zero[8];
};

#endif /* !_NETINET_IN_H_INCLUDED */
