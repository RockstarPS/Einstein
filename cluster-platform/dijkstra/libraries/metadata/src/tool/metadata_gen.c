#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "public/metadata.h"

/**
 * @def Partition_A
 * @brief Active partition Value for partition A
 */
#define Partition_A                                         (0xAAU)

/**
 * @def Partition_B
 * @brief Active partition Value for partition B
 */
#define Partition_B                                         (0x55U)

typedef struct __attribute__((__packed__)) metadata_cfg
{
	ESwImageType_t imageType;
	ESwPartId_t swPartId;
	uint8_t swPartNum[META_SW_PART_NUM_SIZE];
	char *imageName;
    EUpdateType_t updateType;
	EDeviceType_t deviceTypeA;
	uint8_t devicePhyPartIdA;
	uint32_t startAddressPartitionA;
	EDeviceType_t deviceTypeB;
	uint8_t devicePhyPartIdB;
	uint32_t startAddressPartitionB;
	EDeviceType_t deviceTypeInactive;
	uint8_t devicePhyPartIdInactive;
	uint32_t startAddressPartitionInactive;
	uint32_t size;
	uint8_t vMajor;
	uint8_t vMinor;
	uint8_t vPatch;
} metadata_cfg_t;

metadata_cfg_t metadata_cfg[ESwPartId_Last] = { METADATA_CFG };

static int32_t sha256_file(char *name, uint8_t *hash)
{
	uint32_t ret = EOK;
	char cmd[256U];
	char buffer[64];
	FILE *fp;
	
	memset(cmd, 0, 256U);
	snprintf(cmd, 256U, "sha256sum %s", name);
	
	fp = popen(cmd, "r");
	if(NULL != fp)
	{
		if(fscanf(fp, "%64s", buffer) == 1)
		{
			printf("SHA256 of %s is %s\n", name, buffer);
		    for (size_t count = 0; count < META_SWPART_CHKSUM_SIZE; count++) {
				sscanf(&buffer[count*2], "%2hhx", &hash[count]);
			}
			printf("SHA256 verify : 0x");
			for(size_t idx1 = 0; idx1 < META_SWPART_CHKSUM_SIZE; idx1++)
			{
				printf("%02x", hash[idx1]);
			}
			printf("\n");
		}
		pclose(fp);
	}

	return ret;
}

static int32_t Metadata_UpdateChecksum(SMetadata_t *pMetadata)
{
	uint8_t *pData = (uint8_t *)pMetadata;
	uint32_t idx;
	uint32_t checksum = 0;
	uint32_t ret = EOK;

	for(idx = 0; idx < (sizeof(SMetadata_t) - META_CHECKSUM_SIZE); idx++)
	{
		checksum += pData[idx];
	}

	pMetadata->checksum = checksum;

	return ret;
}

static int32_t Metadata_Save(SMetadata_t *pMetadata, uint32_t offset)
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
			if(EOK == Metadata_UpdateChecksum(pMetadata))
			{
				bytes_written = write(fd , pMetadata,  sizeof(SMetadata_t));
				if(bytes_written == sizeof(SMetadata_t))
				{
					ret = EOK;
					printf ( "Writing successful %s : %u\n", META_DEV, offset );
				}
				else
				{
					printf ( "Error Writing device %s : %u\n", META_DEV, offset );
				}
			}
			else
			{
				printf ( "Error update checksum %s : %u\n", META_DEV, offset );
			}
		}
		else
		{
			printf ( "Error Seeking device %s : %u\n", META_DEV, offset );
		}

		close(fd);
	}
	else
	{
		printf ( "Error opening device %s\n", META_DEV );
	}

	return ret;
}

int32_t Metadata_CreateBin(SMetadata_t *pMetadata)
{
	int32_t ret = EIO;
	int32_t fd;

	fd = open(META_DEV, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );
	ftruncate(fd, (META_SIZE * 2U));
	close(fd);

	ret = Metadata_Save(pMetadata, META_A_OFFSET);
	if(EOK != ret)
	{
		printf("Error writing file at offset %u\n", META_A_OFFSET);
	}
	
	ret = Metadata_Save(pMetadata, META_B_OFFSET);
	if(EOK != ret)
	{
		printf("Error writing file at offset %u\n", META_B_OFFSET);
	}

	return ret;
}

static int32_t Metadata_UpdateHash(uint8_t *IsoSign)
{
   int32_t ret = EOK;
   FILE *fd;
   uint8_t buff[512] ={0};
   uint8_t* ptr;
   unsigned int* dst;
   fd = fopen(  "GP-sign-rsa.txt", "r" );
   if(fd != NULL)
   {     
     fread(buff, (META_PKG_SIGN_SIZE * 2), 1, fd);    
     ptr = &buff[0];   
     for (size_t count = 0; count < META_PKG_SIGN_SIZE; count++) 
     {
        sscanf((const char*)ptr, "%2hhx",&IsoSign[count]);
        ptr += 2;
     }     
  	fclose(fd);
   }
  	return ret;
}

int main(void) {
	SMetadata_t meta;
	int32_t ret;
	uint32_t idx;

	meta.version = 2;
	meta.numSwParts = META_SW_NUM_PARTS;
	meta.updateId = 0;
	meta.bootStatusFlag = EBootStatus_Normal;
	meta.variantId = META_VARIANT_ID;
	memset(meta.hwPartNum, 0, META_HW_PART_NUM_SIZE);
	meta.swUpdateInfo.fotaUpdateTotal = 0;
	meta.swUpdateInfo.fotaUpdateFail = 0;
	meta.swUpdateInfo.fotaUpdateSuccess = 0;
	meta.swUpdateInfo.blUpdateTotal = 0;
	meta.swUpdateInfo.blUpdateFail = 0;
	meta.swUpdateInfo.blUpdateSuccess = 0;
	memset(meta.swUpdateInfo.lastUpdatePkgSign, 0, META_PKG_SIGN_SIZE);
  Metadata_UpdateHash(&meta.swUpdateInfo.lastUpdatePkgSign[0]);

	for(idx = 0; idx < META_SW_NUM_PARTS; idx++)
	{
		meta.swPart[idx].imageType = metadata_cfg[idx].imageType;
		meta.swPart[idx].swPartId = metadata_cfg[idx].swPartId;
		meta.swPart[idx].updateId = 0U;
		meta.swPart[idx].updateType = metadata_cfg[idx].updateType;
		meta.swPart[idx].activePartition = Partition_A;
		memset(meta.swPart[idx].swPartNum, 0, META_SW_PART_NUM_SIZE);
		memcpy(meta.swPart[idx].swPartNum, metadata_cfg[idx].swPartNum, META_SW_PART_NUM_SIZE);
		memset(meta.swPart[idx].imageName, 0, META_IMG_NAME_SIZE);
		strncpy((char*)meta.swPart[idx].imageName, metadata_cfg[idx].imageName, (META_IMG_NAME_SIZE - 1U));

		meta.swPart[idx].partitionInfo[EPartition_A].deviceType = metadata_cfg[idx].deviceTypeA;
		meta.swPart[idx].partitionInfo[EPartition_A].devicePhyPartId = metadata_cfg[idx].devicePhyPartIdA;
		meta.swPart[idx].partitionInfo[EPartition_A].startAddress = metadata_cfg[idx].startAddressPartitionA;
		meta.swPart[idx].partitionInfo[EPartition_A].size = metadata_cfg[idx].size;
		meta.swPart[idx].partitionInfo[EPartition_A].status = ESwPartitionSts_Verified;
		meta.swPart[idx].partitionInfo[EPartition_A].version.major = metadata_cfg[idx].vMajor;
		meta.swPart[idx].partitionInfo[EPartition_A].version.minor = metadata_cfg[idx].vMinor;
		meta.swPart[idx].partitionInfo[EPartition_A].version.patch = metadata_cfg[idx].vPatch;
		sha256_file(meta.swPart[idx].imageName, meta.swPart[idx].partitionInfo[EPartition_A].checksum);

		meta.swPart[idx].partitionInfo[EPartition_B].deviceType = metadata_cfg[idx].deviceTypeB;
		meta.swPart[idx].partitionInfo[EPartition_B].devicePhyPartId = metadata_cfg[idx].devicePhyPartIdB;
		meta.swPart[idx].partitionInfo[EPartition_B].startAddress = metadata_cfg[idx].startAddressPartitionB;
		meta.swPart[idx].partitionInfo[EPartition_B].size = metadata_cfg[idx].size;
		meta.swPart[idx].partitionInfo[EPartition_B].status = ESwPartitionSts_Verified;
		meta.swPart[idx].partitionInfo[EPartition_B].version.major = metadata_cfg[idx].vMajor;
		meta.swPart[idx].partitionInfo[EPartition_B].version.minor = metadata_cfg[idx].vMinor;
		meta.swPart[idx].partitionInfo[EPartition_B].version.patch = metadata_cfg[idx].vPatch;
		sha256_file(meta.swPart[idx].imageName, meta.swPart[idx].partitionInfo[EPartition_B].checksum);

		meta.swPart[idx].partitionInfo[EPartition_Inactive].deviceType = metadata_cfg[idx].deviceTypeInactive;
		meta.swPart[idx].partitionInfo[EPartition_Inactive].devicePhyPartId = metadata_cfg[idx].devicePhyPartIdInactive;
		meta.swPart[idx].partitionInfo[EPartition_Inactive].startAddress = metadata_cfg[idx].startAddressPartitionInactive;
		meta.swPart[idx].partitionInfo[EPartition_Inactive].size = metadata_cfg[idx].size;
		meta.swPart[idx].partitionInfo[EPartition_Inactive].status = ESwPartitionSts_Verified;
		meta.swPart[idx].partitionInfo[EPartition_Inactive].version.major = metadata_cfg[idx].vMajor;
		meta.swPart[idx].partitionInfo[EPartition_Inactive].version.minor = metadata_cfg[idx].vMinor;
		meta.swPart[idx].partitionInfo[EPartition_Inactive].version.patch = metadata_cfg[idx].vPatch;
		sha256_file(meta.swPart[idx].imageName, meta.swPart[idx].partitionInfo[EPartition_Inactive].checksum);
	}
				
	ret = Metadata_CreateBin(&meta);

	if(ret == EOK)
	{
		printf ( "Meta binary created %s\n", META_DEV );
	}
	return EXIT_SUCCESS;
}
