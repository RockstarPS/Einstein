#include <errno.h>
#include <unistd.h>
#include "debug.h"
#include "metadata_hw.h"
#include "metadata.h"

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

#ifdef DEBUG_SLOG2
extern char *__progname;
slog2_buffer_set_config_t   slog2_config;
slog2_buffer_t              slog2_handle;
#endif

static uint32_t Metadata_GetSwPartIdx(SMetadata_t *pMetadata, ESwPartId_t swPartId);
static int32_t  Metadata_Load(SMetadata_t *pMetadata);
static int32_t  Metadata_Save(SMetadata_t *pMetadata);
static int32_t  Metadata_VerifyChecksum(SMetadata_t *pMetadata);
static int32_t  Metadata_UpdateChecksum(SMetadata_t *pMetadata);

void Metadata_Init(void)
{
#ifdef DEBUG_SLOG2
    /* Initialize slog2 */
    slog2_config.buffer_set_name = __progname;
    slog2_config.num_buffers = 1;
    slog2_config.verbosity_level = SLOG2_INFO;
    slog2_config.buffer_config[0U].buffer_name = "metadata";
    slog2_config.buffer_config[0U].num_pages = 8;

    if( 0 != slog2_register( &slog2_config, &slog2_handle, 0 ) )
    {
        LOGE ( "%s", "Error registering slogger2 buffer" );
    }
    LOGI ( "%s", "meta library load success" );
#endif
#ifdef DEBUG_SYSLOG
	openlog("metadata", 0, LOG_USER);
#endif
}

int32_t Metadata_GetInfo(SMetadata_t *pMetadata)
{
	int32_t ret = EIO;

	ret = Metadata_Lock();

	if(EOK == ret)
	{
		ret = Metadata_Load(pMetadata);
	}
	else
	{
		LOGE ( "Metadata_Lock failed %d", ret );
	}

	(void)Metadata_Unlock();

	return ret;
}

int32_t Metadata_GetBootStatusFlag(uint8_t *flag)
{
	SMetadata_t meta;
	int32_t ret = EIO;

	ret = Metadata_Lock();

	if(EOK == ret)
	{
		ret = Metadata_Load(&meta);
	}
	else
	{
		LOGE ( "Metadata_Lock failed %d", ret );
	}

	if(EOK == ret)
	{
		*flag = meta.bootStatusFlag;
	}

	(void)Metadata_Unlock();
	return ret;
}

int32_t Metadata_SetBootStatusFlag(uint8_t  flag)
{
	SMetadata_t meta;
	int32_t ret = EIO;

	ret = Metadata_Lock();

	if(EOK == ret)
	{
		ret = Metadata_Load(&meta);
	}
	else
	{
		LOGE ( "Metadata_Lock failed %d", ret );
	}

	if((EBootStatus_Normal != flag) && (EBootStatus_FOTA != flag) && (EBootStatus_Bootloader != flag))
	{
		LOGE ( "Invalid arg %d", flag );
		ret = EIO;
	}

	if(EOK == ret)
	{
		meta.bootStatusFlag = flag;
		ret = Metadata_Save(&meta);
	}

	(void)Metadata_Unlock();
	return ret;
}

int32_t Metadata_GetVariantID(uint8_t *flag)
{
	SMetadata_t meta;
	int32_t ret = EIO;

	ret = Metadata_Lock();

	if(EOK == ret)
	{
		ret = Metadata_Load(&meta);
	}
	else
	{
		LOGE ( "Metadata_Lock failed %d", ret );
	}

	if(EOK == ret)
	{
		*flag = meta.variantId;
	}

	(void)Metadata_Unlock();
	return ret;
}

int32_t Metadata_SetVariantID(uint8_t flag)
{
	SMetadata_t meta;
	int32_t ret = EIO;

	ret = Metadata_Lock();

	if(EOK == ret)
	{
		ret = Metadata_Load(&meta);
	}
	else
	{
		LOGE ( "Metadata_Lock failed %d", ret );
	}

	if((0 != flag) && (1 != flag) && (2 != flag))
	{
		LOGE ( "Invalid arg %d", flag );
		ret = EIO;
	}

	if(EOK == ret)
	{
		meta.variantId = flag;
		ret = Metadata_Save(&meta);
	}

	(void)Metadata_Unlock();
	return ret;
}
int32_t Metadata_GetActivePartition(uint16_t swPartId, uint8_t *partition)
{
	SMetadata_t meta;
	int32_t ret = EIO;
	uint32_t idx = ESwPartId_Last;

	ret = Metadata_Lock();

	if(EOK == ret)
	{
		ret = Metadata_Load(&meta);
	}
	else
	{
		LOGE ( "Metadata_Lock failed %d", ret );
	}

	if(EOK == ret)
	{
		idx = Metadata_GetSwPartIdx(&meta, swPartId);
	}

	if(idx < ESwPartId_Last)
	{
		if(meta.swPart[idx].activePartition == Partition_A)
		{
			*partition = EPartition_A;
			ret = EOK;
		}
		else if(meta.swPart[idx].activePartition == Partition_B)
		{
			*partition = EPartition_B;
			ret = EOK;
		}
		else
		{
			*partition = EPartition_Last;
			ret = EIO;
			LOGE ( "Invalid active partition value %d for swPartId %d", meta.swPart[idx].activePartition, swPartId );
		}
	}
	else
	{
		ret = EIO;
		LOGE ( "Invalid swPartId %d", swPartId );
	}

	(void)Metadata_Unlock();
	return ret;
}

int32_t Metadata_SetActivePartition(uint16_t swPartId, uint8_t partition, uint8_t bIgnorePartitionSts)
{
	SMetadata_t meta;
	int32_t ret = EIO;
	uint32_t idx = ESwPartId_Last;

	ret = Metadata_Lock();

	if(EOK == ret)
	{
		ret = Metadata_Load(&meta);
	}
	else
	{
		LOGE ( "Metadata_Lock failed %d", ret );
	}

	if(EOK == ret)
	{
		idx = Metadata_GetSwPartIdx(&meta, swPartId);
	}

	if(idx < ESwPartId_Last)
	{
		if (FALSE == bIgnorePartitionSts)
		{
			if (meta.swPart[idx].partitionInfo[partition].status != ESwPartitionSts_Verified)
			{
				ret = EIO;
				LOGE ( "Invalid status for partition : %d, swPartId : %d, status : %d", partition, swPartId,
						meta.swPart[idx].partitionInfo[partition].status);
			}
		}
		if(EOK == ret)
		{
			if(partition == EPartition_A)
			{
				meta.swPart[idx].activePartition = Partition_A;
				ret = EOK;
			}
			else if(partition == EPartition_B)
			{
				meta.swPart[idx].activePartition = Partition_B;
				ret = EOK;
			}
			else
			{
				ret = EIO;
				LOGE ( "Invalid active partition value %d for swPartId %d",	partition, swPartId );
			}
		}
	}
	else
	{
		ret = EIO;
		LOGE ( "Invalid swPartId %d", swPartId );
	}

	if( ret == EOK )
	{
		ret = Metadata_Save(&meta);
	}

	(void)Metadata_Unlock();
	return ret;
}

int32_t Metadata_IncrementUpdateId(void)
{
	SMetadata_t meta;
	int32_t ret = EIO;

	ret = Metadata_Lock();

	if(EOK == ret)
	{
		ret = Metadata_Load(&meta);
	}
	else
	{
		LOGE ( "Metadata_Lock failed %d", ret );
	}

	if(EOK == ret)
	{
		meta.updateId = meta.updateId + 1U;
		ret = Metadata_Save(&meta);
	}

	(void)Metadata_Unlock();
	return ret;
}

int32_t Metadata_IncrementSwPartUpdateId(uint16_t swPartId)
{
	SMetadata_t meta;
	int32_t ret = EIO;
	uint32_t idx = ESwPartId_Last;

	ret = Metadata_Lock();

	if(EOK == ret)
	{
		ret = Metadata_Load(&meta);
	}
	else
	{
		LOGE ( "Metadata_Lock failed %d", ret );
	}

	if(EOK == ret)
	{
		idx = Metadata_GetSwPartIdx(&meta, swPartId);
	}

	if(idx < ESwPartId_Last)
	{
		meta.swPart[idx].updateId = meta.swPart[idx].updateId + 1U;
	}
	else
	{
		ret = EIO;
		LOGE ( "Invalid swPartId %d", swPartId );
	}

	if( ret == EOK )
	{
		ret = Metadata_Save(&meta);
	}

	(void)Metadata_Unlock();
	return ret;
}

int32_t Metadata_GetPartitionInfo(uint16_t swPartId, EPartition_t partitionType, SSwPartitionInfo_t *pPartitionInfo)
{
	SMetadata_t meta;
	int32_t ret = EIO;
	uint32_t idx = ESwPartId_Last;

	ret = Metadata_Lock();

	if(EOK == ret)
	{
		ret = Metadata_Load(&meta);
	}
	else
	{
		LOGE ( "Metadata_Lock failed %d", ret );
	}

	if(EPartition_Last <= partitionType)
	{
		LOGE ( "Invalid arg partitionType %d", partitionType );
		ret = EIO;
	}

	if(EOK == ret)
	{
		idx = Metadata_GetSwPartIdx(&meta, swPartId);
	}

	if(idx < ESwPartId_Last)
	{
		memcpy(pPartitionInfo, &meta.swPart[idx].partitionInfo[partitionType], sizeof(SSwPartitionInfo_t));
	}
	else
	{
		ret = EIO;
		LOGE ( "Invalid swPartId %d", swPartId );
	}

	(void)Metadata_Unlock();
	return ret;
}

int32_t Metadata_SetPartitionInfo(uint16_t swPartId, EPartition_t partitionType, SSwPartitionInfo_t *pPartitionInfo)
{
	SMetadata_t meta;
	int32_t ret = EIO;
	uint32_t idx = ESwPartId_Last;

	ret = Metadata_Lock();

	if(EOK == ret)
	{
		ret = Metadata_Load(&meta);
	}
	else
	{
		LOGE ( "Metadata_Lock failed %d", ret );
	}

	if(EPartition_Last <= partitionType)
	{
		LOGE ( "Invalid arg partitionType %d", partitionType );
		ret = EIO;
	}
	if(NULL == pPartitionInfo)
	{
		LOGE ( "Invalid pPartitionInfo %d", partitionType );
		ret = EIO;
	}
	if(0 == pPartitionInfo->size)
	{
		LOGE ( "Invalid arg size %d", pPartitionInfo->size );
		ret = EIO;
	}
	if(EOK == ret)
	{
		idx = Metadata_GetSwPartIdx(&meta, swPartId);
	}

	if(idx < ESwPartId_Last)
	{
		if(meta.swPart[idx].partitionInfo[partitionType].startAddress != pPartitionInfo->startAddress)
		{
			LOGE ( "Cannot change startAddress %d", pPartitionInfo->startAddress );
			ret = EIO;
		}
		else
		{
			switch(pPartitionInfo->status)
			{
			case ESwPartitionSts_Programmed:
				if(ESwPartitionSts_Erased != meta.swPart[idx].partitionInfo[partitionType].status)
				{
					LOGE ( "Invalid status change %d -> %d", meta.swPart[idx].partitionInfo[partitionType].status, pPartitionInfo->status );
					ret = EIO;
				}
				break;
			case ESwPartitionSts_Verified:
				if((ESwPartitionSts_Programmed != meta.swPart[idx].partitionInfo[partitionType].status) &&
				   (ESwPartitionSts_Verified != meta.swPart[idx].partitionInfo[partitionType].status))
				{
					LOGE ( "Invalid status change %d -> %d", meta.swPart[idx].partitionInfo[partitionType].status, pPartitionInfo->status );
					ret = EIO;
				}
				break;
			case ESwPartitionSts_Invalid:
				break;
			case ESwPartitionSts_Erased:
				break;
			default:
				LOGE ( "Invalid status change %d -> %d", meta.swPart[idx].partitionInfo[partitionType].status, pPartitionInfo->status );
				ret = EIO;
				break;
			}
		}
	}
	else
	{
		ret = EIO;
		LOGE ( "Invalid swPartId %d", swPartId );
	}
	if( ret == EOK )
	{
		memcpy(&meta.swPart[idx].partitionInfo[partitionType], pPartitionInfo, sizeof(SSwPartitionInfo_t));
		ret = Metadata_Save(&meta);
	}

	(void)Metadata_Unlock();
	return ret;
}

int32_t Metadata_GetSwUpdateInfo(SSwUpdateInfo_t *pSwUpdateInfo)
{
	SMetadata_t meta;
	int32_t ret = EIO;

	ret = Metadata_Lock();

	if(EOK == ret)
	{
		ret = Metadata_Load(&meta);
	}
	else
	{
		LOGE ( "Metadata_Lock failed %d", ret );
	}

	if(EOK == ret)
	{
		memcpy(pSwUpdateInfo, &meta.swUpdateInfo, sizeof(SSwUpdateInfo_t));
	}

	(void)Metadata_Unlock();
	return ret;
}

int32_t Metadata_SetSwUpdateInfo(SSwUpdateInfo_t *pSwUpdateInfo)
{
	SMetadata_t meta;
	int32_t ret = EIO;

	ret = Metadata_Lock();

	if(EOK == ret)
	{
		ret = Metadata_Load(&meta);
	}
	else
	{
		LOGE ( "Metadata_Lock failed %d", ret );
	}

	if(EOK == ret)
	{
		memcpy(&meta.swUpdateInfo, pSwUpdateInfo, sizeof(SSwUpdateInfo_t));
		ret = Metadata_Save(&meta);
	}

	(void)Metadata_Unlock();
	return ret;
}

int32_t Metadata_GetSwPartInfo(uint16_t swPartId, SSwPartInfo_t *pSwPartInfo)
{
	SMetadata_t meta;
	int32_t ret = EIO;
	uint32_t idx = ESwPartId_Last;

	ret = Metadata_Lock();

	if(EOK == ret)
	{
		ret = Metadata_Load(&meta);
	}
	else
	{
		LOGE ( "Metadata_Lock failed %d", ret );
	}

	if(EOK == ret)
	{
		idx = Metadata_GetSwPartIdx(&meta, swPartId);
	}

	if(idx < ESwPartId_Last)
	{
		memcpy(pSwPartInfo, &meta.swPart[idx], sizeof(SSwPartInfo_t));
	}
	else
	{
		ret = EIO;
		LOGE ( "Invalid swPartId %d", swPartId );
	}

	(void)Metadata_Unlock();
	return ret;
}

static uint32_t Metadata_GetSwPartIdx(SMetadata_t *pMetadata, ESwPartId_t swPartId)
{
	uint32_t idx;

	for(idx = 0; idx < pMetadata->numSwParts; idx++)
	{
		if(pMetadata->swPart[idx].swPartId == swPartId)
		{
			break;
		}
	}
	return idx;
}

static int32_t Metadata_Load(SMetadata_t *pMetadata)
{
	int32_t ret = EIO;

	ret = Metadata_LoadWithOffset(pMetadata, META_A_OFFSET);
	if(EOK == ret)
	{
		ret = Metadata_VerifyChecksum(pMetadata);
	}

	if(EOK != ret)
	{
		LOGE ( "Checksum failed %s : %d", META_DEV, META_A_OFFSET );

		ret = Metadata_LoadWithOffset(pMetadata, META_B_OFFSET);
		if(EOK == ret)
		{
			ret = Metadata_VerifyChecksum(pMetadata);
		}
		if(EOK != ret)
		{
			LOGE ( "Checksum failed %s : %d", META_DEV, META_B_OFFSET );
		}
	}

	return ret;
}

static int32_t Metadata_Save(SMetadata_t *pMetadata)
{
	int32_t ret = EIO;

	if(EOK == Metadata_UpdateChecksum(pMetadata))
	{
		ret = Metadata_SaveWithOffset(pMetadata, META_A_OFFSET);
		if(EOK != ret)
		{
			LOGE ( "Metadata_SaveWithOffset failed %d", META_A_OFFSET );
		}

		ret = Metadata_SaveWithOffset(pMetadata, META_B_OFFSET);
		if(EOK != ret)
		{
			LOGE ( "Metadata_SaveWithOffset failed %d", META_B_OFFSET );
		}
	}
	else
	{
		LOGE ( "Error update checksum %s", META_DEV );
	}

	return ret;
}

static int32_t Metadata_VerifyChecksum(SMetadata_t *pMetadata)
{
	uint8_t *pData = (uint8_t *)pMetadata;
	uint32_t idx;
	uint32_t checksum = 0;
	uint32_t ret = EIO;

	for(idx = 0; idx < (sizeof(SMetadata_t) - META_CHECKSUM_SIZE); idx++)
	{
		checksum += pData[idx];
	}

	if(checksum == pMetadata->checksum)
	{
		ret = EOK;
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
