
#ifndef __IOCTL_H_INCLUDED
#define __IOCTL_H_INCLUDED

#include <sys/cdefs.h>
#include <sys/sockio.h>

#define IOCPARM_MASK    0x3fffu          /* parameter length, at most 14 bits */

#define IOCPARM_MAX     NBPG             /* max size of ioctl, mult. of NBPG */
#define IOC_VOID        0x00000000u      /* no parameters */
#define IOC_OUT         0x40000000u      /* copy out parameters */
#define IOC_IN          0x80000000u      /* copy in parameters */
#define IOC_INOUT       (IOC_IN|IOC_OUT)
#define IOC_DIRMASK     0xc0000000u      /* mask for IN/OUT/VOID */

#define _IOC(inout,group,num,len) \
        (int)((inout) | (((unsigned)(len) & IOCPARM_MASK) << 16) | ((unsigned)(group) << 8) | (unsigned)(num))
#define _IOW(g,n,t)     _IOC(IOC_IN,    (g), (n), sizeof(t))
#define _IOWR(g,n,t)    _IOC(IOC_INOUT, (g), (n), sizeof(t))

__BEGIN_DECLS

int     ioctl(int __fd, int __cmd, ...);

__END_DECLS

#endif

