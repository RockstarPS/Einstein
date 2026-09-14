/*
 * $QNXLicenseC:
 * Copyright 2007, QNX Software Systems. All Rights Reserved.
 * 
 * You must obtain a written license from and pay applicable license fees to QNX 
 * Software Systems before you may reproduce, modify or distribute this software, 
 * or any work that includes all or part of this software.   Free development 
 * licenses are available for evaluation and non-commercial purposes.  For more 
 * information visit http://licensing.qnx.com or email licensing@qnx.com.
 *  
 * This file may contain contributions from others.  Please review this entire 
 * file for other proprietary rights or license notices, as well as the QNX 
 * Development Suite License Guide at http://licensing.qnx.com/license-guide/ 
 * for other information.
 * $
 */



/*
 *  termios.h   Terminal I/O system types
 *

 */
#ifndef _TERMIOS_H_INCLUDED
#define _TERMIOS_H_INCLUDED

#define NCCS    40

typedef unsigned char   cc_t;
typedef long            speed_t;
typedef unsigned long   tcflag_t;
typedef unsigned long   _Uint32t;

struct termios {
    tcflag_t        c_iflag;    /* Input Modes */
    tcflag_t        c_oflag;    /* Ouput modes */
    tcflag_t        c_cflag;    /* Control Modes */
    tcflag_t        c_lflag;    /* Local Modes */
    cc_t            c_cc[NCCS]; /* Control Characters */
	_Uint32t		reserved[3];
    speed_t         c_ispeed;   /* Input Baud rate */
    speed_t         c_ospeed;   /* Output baud rate */
};
/*
 * Input modes
 */

#define IGNPAR      0x00000004//

/*
 * Ouput Modes
 */

/*
 * Control Modes
 */

#define IHFLOW      0x00000001//
#define OHFLOW      0x00000002//
#define CS8               0x30//
#define CREAD       0x00000080//
#define CLOCAL      0x00000800//

/*
 * Local Modes
 */


/*
 * Special Control Character indices into c_cc[]
 */


#define VMIN    16//
#define VTIME   17//


/*
 * Pre-Defined Baud rates used by cfgetospeed(), etc.
 */


/*
 * Optional Actions for tcsetattr()
 */

#define TCSANOW     0x0001//


/*
 * queue_selectors for tcflush()
 */

#define TCIFLUSH    0x0000//


/*
 * Actions for tcflow()
 */

/*
 *  POSIX 1003.1 Prototypes.
 */
extern int     cfsetispeed(struct termios * __termios_p, speed_t __speed);//
extern int     cfsetospeed(struct termios * __termios_p, speed_t __speed);//
extern int     tcflush(int __fildes, int __queue_selector);//
extern int     tcgetattr(int __fildes, struct termios * __termios_p);//
extern int     tcsetattr(int __fildes, int __opt_act, const struct termios * __termios_p);//
#endif
