#ifndef _UNISTD_H_INCLUDED
#define _UNISTD_H_DECLARED

//#ifndef __PLATFORM_H_INCLUDED
//#include <sys/platform.h>
//#endif

ssize_t read(int __fildes, void *__buffer, size_t __len);
ssize_t write(int __fildes, const void *__buf, size_t __len);


#endif