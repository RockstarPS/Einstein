#include <stdint.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debug.h"
#include "shared_mutex.h"

#ifndef EOK
#define EOK 0
#endif

shared_mutex_t shared_mutex_init(char *name)
{
	int32_t ret = EOK;
	shared_mutex_t mutex = {NULL, 0, NULL, 0};
	errno = 0;
	pthread_mutex_t *mutex_ptr = NULL;

	// Open existing shared memory object, or create one.
	// Two separate calls are needed here, to mark fact of creation
	// for later initialization of pthread mutex.
	mutex.shm_fd = shm_open(name, O_RDWR, 0660);
	if (errno == ENOENT)
	{
		mutex.shm_fd = shm_open(name, O_RDWR|O_CREAT, 0660);
		mutex.created = 1;
	}
	if (mutex.shm_fd == -1) {
		LOGE("shm_open : %s",strerror(errno));
		ret = EIO;
	}

	// Truncate shared memory segment so it would contain
	// pthread_mutex_t.
	if(EOK == ret)
	{
		if (ftruncate(mutex.shm_fd, sizeof(pthread_mutex_t)) != 0)
		{
			LOGE("ftruncate : %s",strerror(errno));
			ret = EIO;
		}
	}
	if(EOK == ret)
	{
		// Map pthread mutex into the shared memory.
		void *addr = mmap(NULL, sizeof(pthread_mutex_t), PROT_READ|PROT_WRITE,
						MAP_SHARED, mutex.shm_fd, 0);
		if (addr == MAP_FAILED)
		{
			LOGE("mmap : %s",strerror(errno));
			ret = EIO;
		}
		mutex_ptr = (pthread_mutex_t *)addr;
	}
	if(EOK == ret)
	{
		// If shared memory was just initialized -
		// initialize the mutex as well.
		if (mutex.created)
		{
			pthread_mutexattr_t attr;
			if (pthread_mutexattr_init(&attr))
			{
				LOGE("pthread_mutexattr_init : %s",strerror(errno));
				ret = EIO;
			}
			if (pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED))
			{
				LOGE("pthread_mutexattr_setpshared : %s",strerror(errno));
				ret = EIO;
			}
			if (pthread_mutex_init(mutex_ptr, &attr))
			{
				LOGE("pthread_mutex_init : %s",strerror(errno));
				ret = EIO;
			}
		}
	}

	if(EOK == ret)
	{
		mutex.name = (char *)malloc(NAME_MAX+1);
		if (mutex.name != NULL)
		{
			strcpy(mutex.name, name);
			mutex.ptr = mutex_ptr;
		}
		else
		{
			ret = EIO;
		}
	}

	if(EOK != ret)
	{
		(void)munmap((void *)mutex_ptr, sizeof(pthread_mutex_t));
		(void)close(mutex.shm_fd);
		mutex.shm_fd = 0;
	}

	return mutex;
}

int32_t shared_mutex_destroy(shared_mutex_t mutex)
{
	int32_t ret = EOK;

	if ((errno = pthread_mutex_destroy(mutex.ptr)))
	{
		LOGE("pthread_mutex_destroy : %s",strerror(errno));
		ret = EIO;
	}
	if(EOK == ret)
	{
		if (munmap((void *)mutex.ptr, sizeof(pthread_mutex_t)))
		{
			LOGE("munmap : %s",strerror(errno));
			ret = EIO;
		}
	}
	mutex.ptr = NULL;
	if(EOK == ret)
	{
		if (close(mutex.shm_fd))
		{
			LOGE("close : %s",strerror(errno));
			ret = EIO;
		}
	}
	mutex.shm_fd = 0;
	if(EOK == ret)
	{
		if (shm_unlink(mutex.name))
		{
			LOGE("shm_unlink : %s",strerror(errno));
			ret = EIO;
		}
	}
	free(mutex.name);
	return ret;
}
