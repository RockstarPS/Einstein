#ifndef _PTHREAD_H_INCLUDED
#define _PTHREAD_H_INCLUDED

#define __progname wdg_client
#define F_OK    0       /*  Test for existence of file  */
//extern int access(const char *__path, int __mode);
int pthread_setname_np(int thr, const char *name);
int gettid(void);

#endif
