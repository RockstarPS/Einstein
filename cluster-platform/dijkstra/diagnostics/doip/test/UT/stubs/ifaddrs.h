#ifndef	_IFADDRS_H_INCLUDED
#define	_IFADDRS_H_INCLUDED

#include <sys/socket.h>
#include <sys/types.h>

struct ifaddrs{
   struct ifaddrs  *ifa_next;
   char  *ifa_name;
   uint8_t  ifa_flags;
   struct sockaddr  *ifa_addr;
   struct sockaddr  *ifa_netmask;
   struct sockaddr  *ifa_dstaddr;
   void  *ifa_data;
};


int getifaddrs(struct ifaddrs **);

void freeifaddrs(struct ifaddrs *);


#endif /* !_IFADDRS_H_INCLUDED */
