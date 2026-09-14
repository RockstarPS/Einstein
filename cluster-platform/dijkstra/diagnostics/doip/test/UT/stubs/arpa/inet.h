

#ifndef _ARPA_INET_H_INCLUDED
#define	_ARPA_INET_H_INCLUDED

#include <netinet/in.h>
#include <sys/types.h>


struct in_addr inet_makeaddr(uint32_t, uint32_t);

uint32_t  inet_addr(const char *);

char   *inet_ntoa(struct in_addr);
int    inet_aton(const char *, struct in_addr *);


#endif /* _ARPA_INET_H_INCLUDED */
