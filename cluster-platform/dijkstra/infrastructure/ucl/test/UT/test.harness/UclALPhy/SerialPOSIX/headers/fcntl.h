#ifndef _FCNTL_H_INCLUDED
#define _FCNTL_H_INCLUDED

/*
 *  File access modes.
 */

#define O_RDWR      000002  /*  Read-Write mode */

/*
 *  File status flags used for open() and fcntl().
 */
#define O_NONBLOCK  000200  /*  Non-blocking I/O                */

/*
 *  oflag values for open()
 */
#define O_NOCTTY    004000  /*  Don't assign a controlling terminal */

extern int open(const char *pathname, int flags); 
extern int close(int fd); 

#endif