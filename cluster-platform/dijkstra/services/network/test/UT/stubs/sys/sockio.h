
#ifndef	__SOCKIO_H_INCLUDED
#define	__SOCKIO_H_INCLUDED

#include <sys/ioctl.h>

#define	SIOCIFCREATE	 _IOW('i', 122, struct ifreq)	/* create clone if */
#define	SIOCIFDESTROY	 _IOW('i', 121, struct ifreq)	/* destroy clone if */

#define	SIOCGIFMEDIA	_IOWR('i', 54, struct ifmediareq) /* get net media */
#define	SIOCGIFFLAGS	_IOWR('i', 17, struct ifreq)	/* get ifnet flags */

#define	SIOCSIFADDR	 _IOW('i', 12, struct ifreq)	/* set ifnet address */
#define	SIOCGIFADDR	_IOWR('i', 33, struct ifreq)	/* get ifnet address */

#define	SIOCSIFFLAGS	 _IOW('i', 16, struct ifreq)	/* set ifnet flags */
#define	SIOCGIFFLAGS	_IOWR('i', 17, struct ifreq)	/* get ifnet flags */

#define	SIOCSIFNETMASK	 _IOW('i', 22, struct ifreq)	/* set net addr mask */

#define	SIOCSIFBRDADDR	 _IOW('i', 19, struct ifreq)	/* set broadcast addr */

#define SIOCSETVLANPRIO  _IOW('i', 143, struct ifreq)
#define SIOCGETVLANPRIO _IOWR('i', 144, struct ifreq)   /* get VLAN priority */

#define	SIOCSIFGENERIC	 _IOW('i', 57, struct ifreq)	/* generic IF set op */
#define	SIOCGIFGENERIC	_IOWR('i', 58, struct ifreq)	/* generic IF get op */

#define	SIOCDELRT	 _IOW('r', 11, struct ortentry)	/* delete route */

#endif /* !__SOCKIO_H_INCLUDED */
