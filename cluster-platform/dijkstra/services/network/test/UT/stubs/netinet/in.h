
#ifndef _NETINET_IN_H_INCLUDED
#define	_NETINET_IN_H_INCLUDED

#include <sys/socket.h>

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
