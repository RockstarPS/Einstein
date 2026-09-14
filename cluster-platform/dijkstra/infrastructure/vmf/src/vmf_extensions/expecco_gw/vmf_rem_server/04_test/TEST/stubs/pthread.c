
#define _PTHREAD_C_

#include "nw_vmf_rem_server_unit_test.h"

static signed16 result_pthread_mutex_lock           = EOK;
static signed16 result_pthread_mutex_unlock         = EOK;
static int      result_pthread_attr_init            = EOK;
static int      result_pthread_attr_setdetachstate  = EOK;
static int      result_pthread_create               = EOK;
static int      result_pthread_attr_destroy         = EOK;
static int      result_pthread_attr_setstacklazy    = EOK;
static int      result_pthread_mutexattr_init       = EOK;
static int      result_pthread_mutexattr_settype    = 0;
static int      result_pthread_mutexattr_destroy    = EOK;
static int      result_pthread_mutex_init           = EOK;
static int      result_pthread_attr_setstacksize    = EOK;



void set_pthread_mutex_lock(signed16 param)
{
    result_pthread_mutex_lock = param;
}

signed16 pthread_mutex_lock( pthread_mutex_t* mutex )
{
    return result_pthread_mutex_lock;
}

void set_pthread_mutex_unlock(signed16 param)
{
    result_pthread_mutex_unlock = param;
}

signed16 pthread_mutex_unlock( pthread_mutex_t* mutex )
{
    return result_pthread_mutex_unlock;
}

void set_pthread_attr_init(int param)
{
    result_pthread_attr_init = param;
}

int pthread_attr_init( pthread_attr_t *attr )
{
    return result_pthread_attr_init;
}

void set_pthread_attr_setdetachstate(int param)
{
    result_pthread_attr_setdetachstate = param;
}

int pthread_attr_setdetachstate(pthread_attr_t* attr, int detachstate )
{
    return result_pthread_attr_setdetachstate;
}

void set_pthread_create(int param)
{
    result_pthread_create = param;
}

int pthread_create( pthread_t* thread, const pthread_attr_t* attr,void* (*start_routine)(void* ), void* arg )
{
    return result_pthread_create;
}

void set_pthread_attr_destroy(int param)
{
    result_pthread_attr_destroy = param;
}

int pthread_attr_destroy( pthread_attr_t * attr )
{
    return result_pthread_attr_destroy;
}

void set_pthread_attr_setstacklazy(int param)
{
    result_pthread_attr_setstacklazy = param;
}

int pthread_attr_setstacklazy(pthread_attr_t * a, int lazystack )
{
    return result_pthread_attr_setstacklazy;
}

void set_pthread_mutexattr_init(int param)
{
    result_pthread_mutexattr_init = param;
}

int pthread_mutexattr_init(const pthread_mutexattr_t* attr )
{
    return result_pthread_mutexattr_init;
}

void set_pthread_mutexattr_settype(int param)
{
    result_pthread_mutexattr_settype = param;
}

int pthread_mutexattr_settype(pthread_mutexattr_t * attr,int type )
{
    return result_pthread_mutexattr_settype;
}

void set_pthread_mutexattr_destroy(int param)
{
    result_pthread_mutexattr_destroy = param;
}

int pthread_mutexattr_destroy(pthread_mutexattr_t* attr )
{
    return result_pthread_mutexattr_destroy;
}

void set_pthread_mutex_init(int param)
{
    result_pthread_mutex_init = param;
}

int pthread_mutex_init(pthread_mutex_t* mutex,const pthread_mutexattr_t* attr )
{
    return result_pthread_mutex_init;
}

void set_pthread_attr_setstacksize(int param)
{
    result_pthread_attr_setstacksize = param;
}

int pthread_attr_setstacksize( pthread_attr_t * attr, size_t stacksize )
{
    return result_pthread_attr_setstacksize;
}

#undef _PTHREAD_C_
