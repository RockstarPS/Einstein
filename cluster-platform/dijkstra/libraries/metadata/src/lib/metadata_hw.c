
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "debug.h"
#include "metadata_hw.h"
#include "shared_mutex.h"
#include <unistd.h>

#ifdef METADATA_NOR
#include <sys/ioctl.h>
#include <mtd/mtd-user.h>
#endif
shared_mutex_t mutex = {0};
static uint8_t buffer[META_SIZE];

#ifdef METADATA_SWAP16
void Metadata_Swap16(uint8_t *buffer)
{
	int32_t idx;
	uint8_t temp;

	for(idx = 0; idx < META_SIZE; idx = idx + 2)
	{
		temp = buffer[idx];
		buffer[idx] = buffer[idx + 1];
		buffer[idx + 1] = temp;
	}
}
#endif

#ifdef METADATA_NOR
int32_t Metadata_EraseNOR(uint32_t offset, uint32_t fd)
{
	int32_t ret = EIO;
    struct erase_info 
	{
        uint32_t start;
        uint32_t length;
    } ei;
	struct mtd_info_user mtd;

	ret = ioctl(fd, MEMGETINFO, &mtd);
	if (ret < 0)
	{
		LOGE ("Get MTD flash device info failed %d : %s", errno, strerror(errno));
	}
	else
	{
		ei.start = offset;
		if(0 == (META_SIZE % mtd.erasesize))
		{
			ei.length = META_SIZE;
			ret = ioctl(fd, MEMERASE, &ei);
			if(ret < 0)
			{
				LOGE ("MTD Erase Failed %d : %s", errno, strerror(errno));
			}
		}
		else
		{
			LOGE ("MTD Block Size Ivalid %d, %d", offset, META_SIZE);
			ret = EIO;
		}
	}
	return ret;
}
#endif
int32_t Metadata_LoadWithOffset(SMetadata_t *pMetadata, uint32_t offset)
{
	int32_t ret = EIO;
	int32_t fd;
	int32_t bytes_read;
	off_t off;

	fd = open(META_DEV, O_RDONLY );

	if(fd >= 0)
	{
		off = lseek(fd , offset, SEEK_SET);
		if(offset == off)
		{
			memset(buffer, 0, META_SIZE);
			bytes_read = read(fd , buffer,  META_SIZE);
			if(bytes_read == META_SIZE)
			{
				ret = EOK;
				#ifdef METADATA_SWAP16
				Metadata_Swap16(buffer);
				#endif
				memcpy(pMetadata, buffer, sizeof(SMetadata_t));
				LOGI ( "Reading successful %s : %u", META_DEV, offset );
			}
			else
			{
				LOGE ( "Error Reading device %s : %u", META_DEV, offset );
			}
		}
		else
		{
			LOGE ( "Error Seeking device %s : %u", META_DEV, offset );
		}

		close(fd);
	}
	else
	{
		LOGE ( "Error opening device %s", META_DEV );
	}

	return ret;
}

int32_t Metadata_SaveWithOffset(SMetadata_t *pMetadata, uint32_t offset)
{
	int32_t ret = EIO;
	int32_t fd;
	int32_t bytes_written;
	off_t off;

	fd = open(META_DEV, O_WRONLY );

	if(fd >= 0)
	{
		off = lseek(fd , offset, SEEK_SET);
		if(offset == off)
		{
			memset(buffer, 0, META_SIZE);
			memcpy(buffer, pMetadata, sizeof(SMetadata_t));

			#ifdef METADATA_SWAP16
			Metadata_Swap16(buffer);
			#endif

			#ifdef METADATA_NOR
			ret = Metadata_EraseNOR(offset, fd);
			if(ret == EOK)
			#endif
			{
				bytes_written = write(fd , buffer,  META_SIZE);
				if(bytes_written == META_SIZE)
				{
					ret = EOK;
					/*The sync() function queues all the modified block buffers for writing*/
					sync();
					LOGI ( "Writing successful %s : %u", META_DEV, offset );
				}
				else
				{
					LOGE ( "Error Writing device %s : %u", META_DEV, offset );
				}
			}
		}
		else
		{
			LOGE ( "Error Seeking device %s : %u", META_DEV, offset );
		}

		close(fd);
	}
	else
	{
		LOGE ( "Error opening device %s", META_DEV );
	}

	return ret;
}

int32_t Metadata_Lock(void)
{
	uint32_t ret = EIO;

	if(NULL == mutex.ptr)
	{
		mutex = shared_mutex_init("/meta_shmem_mutex");
	}

	ret = pthread_mutex_lock(mutex.ptr);

	return ret;
}

int32_t Metadata_Unlock(void)
{
	uint32_t ret = EIO;

	if(NULL != mutex.ptr)
	{
		(void)pthread_mutex_unlock(mutex.ptr);
		(void)shared_mutex_destroy(mutex);
		mutex.ptr = NULL;
	}

	return ret;
}
