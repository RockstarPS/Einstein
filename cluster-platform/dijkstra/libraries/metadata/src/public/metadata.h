#ifndef METADATA_H
#define METADATA_H

#include <stdint.h>
#include "metadata_cfg.h"

#ifndef FALSE
	#define FALSE     (0U)
#endif
#ifndef TRUE
	#define TRUE      (1U)
#endif
#ifndef EOK
	#define EOK      (0U)
#endif

/**
 * @def META_HW_PART_NUM_SIZE
 * @brief size of the hardware part number string
 */
#define META_HW_PART_NUM_SIZE 								(16U)

/**
 * @def META_SW_PART_NUM_SIZE
 * @brief size of the software part number string
 */
#define META_SW_PART_NUM_SIZE 								(16U)

/**
 * @def META_IMG_NAME_SIZE
 * @brief size of the software image name string
 */
#define META_IMG_NAME_SIZE 									(64U)

/**
 * @def META_CHECKSUM_SIZE
 * @brief size of the metadata checksum
 */
#define META_CHECKSUM_SIZE 									(4U)

/**
 * @def META_PKG_SIGN_SIZE
 * @brief Update Package Signature
 */
#define META_PKG_SIGN_SIZE 									(256U)

/**
 * @def META_SWPART_CHKSUM_SIZE
 * @brief size of the SW partition checksum
 */
#define META_SWPART_CHKSUM_SIZE 						     (32U)

/**
 * @brief The list of boot status
 */
typedef uint8_t EBootStatus_t;
#define EBootStatus_Normal                                   (0x00)
#define EBootStatus_FOTA                                     (0xAA)
#define EBootStatus_Bootloader                               (0x55)

/**
 * @brief Update type of the partition
 */
typedef uint8_t EUpdateType_t;
#define EUpdateType_Single                                   (0U)
#define EUpdateType_AB                                       (1U)
#define EUpdateType_ABA                                      (2U)
#define EUpdateType_Last                                     (3U)

/**
 * @brief The list of the partitions
 */
typedef uint8_t EPartition_t;
#define EPartition_A                                        (0U)
#define EPartition_B                                        (1U)
#define EPartition_Inactive                                 (2U)
#define EPartition_Last                                     (3U)

typedef uint8_t ESwImageType_t;
#define ESwImageType_IFS                                    (0U)
#define ESwImageType_EFS                                    (1U)
#define ESwImageType_ETFS                                   (2U)
#define ESwImageType_QNX6FS                                 (3U)
#define ESwImageType_QTD                                    (4U)
#define ESwImageType_ISO                                    (5U)
#define ESwImageType_GZIP                                   (6U)
#define ESwImageType_BIN                                    (7U)
#define ESwImageType_PDX                                    (8U)
#define ESwImageType_VBF                                    (9U)
#define ESwImageType_SREC                                   (10U)
#define ESwImageType_HEX                                    (11U)
#define ESwImageType_Last                                   (12U)

/**
 * @brief The physical device types
 */

typedef uint8_t EDeviceType_t;
#define EDeviceType_NOR                                     (0U)
#define EDeviceType_EMMC                                    (1U)
#define EDeviceType_EEPROM                                  (2U)
#define EDeviceType_Last                                    (3U)

/**
 * @brief The statuses of the software partition
 */
typedef uint8_t ESwPartitionSts_t;
#define ESwPartitionSts_Invalid                             (0U)
#define ESwPartitionSts_Erased                              (1U)
#define ESwPartitionSts_Programmed                          (2U)
#define ESwPartitionSts_Verified                            (3U)
#define ESwPartitionSts_Last                                (4U)

/**
 * @struct SSwUpdateInfo
 * @brief the information related to each software update
 */
typedef struct __attribute__((__packed__)) SSwUpdateInfo
{
	/** Total number of FOTA updates attempted */
	uint32_t fotaUpdateTotal;
	/** Number of FOTA attempts succeeded */
	uint32_t fotaUpdateSuccess;
	/** Number of FOTA attempts failed */
	uint32_t fotaUpdateFail;
	/** Total number of Bootloader updates attempted */
	uint32_t blUpdateTotal;
	/** Number of Bootloader attempts succeeded */
	uint32_t blUpdateSuccess;
	/** Number of Bootloader attempts failed */
	uint32_t blUpdateFail;
	/** last Update pacakage signature. Same for FOTA and Bootloader update */
	uint8_t  lastUpdatePkgSign[META_PKG_SIGN_SIZE];
}SSwUpdateInfo_t;

/**
 * @struct SSwPartitionInfo
 * @brief the information related to each software partition
 */
typedef struct __attribute__((__packed__)) SSwVersion
{
	uint8_t major;
	uint8_t minor;
	uint8_t patch;
}SSwVersion_t;

/**
 * @struct SSwPartitionInfo
 * @brief the information related to each software partition
 */
typedef struct __attribute__((__packed__)) SSwPartitionInfo
{
	/** Device */
	EDeviceType_t deviceType;
	/** Device Physical Partition Id */
	uint8_t devicePhyPartId;
	/** Start Address of the partition */
	uint32_t startAddress;
	/** Length of the partition */
	uint32_t size;
	/** The checksum of the data in the partition */
	uint8_t checksum[META_SWPART_CHKSUM_SIZE];
	/** Version of software in the partition */
	SSwVersion_t version;
	/** Status of the partition */
	ESwPartitionSts_t status;
}SSwPartitionInfo_t;

/**
 * @struct SSwPartInfo
 * @brief the information related to each software part
 */
typedef struct __attribute__((__packed__)) SSwPartInfo
{
	/** Type */
	ESwImageType_t imageType;
	/** Software part ID */
	ESwPartId_t swPartId;
	/** Update ID */
	uint16_t updateId;
	/** Update Type */
	uint16_t updateType;
	/** Active partition */
	uint8_t activePartition;
	/** Software part number */
	uint8_t swPartNum[META_SW_PART_NUM_SIZE];
	/** Name */
	uint8_t imageName[META_IMG_NAME_SIZE];
	/** Partition information */
	SSwPartitionInfo_t partitionInfo[EPartition_Last];
}SSwPartInfo_t;

typedef struct __attribute__((__packed__)) SMetadata
{
	/** version of the metadata header */
	uint8_t version;
	/** Number of software parts */
	uint8_t numSwParts;
	/** Total software udpate count */
	uint16_t updateId;
	/** Boot status for recovery QNX */
	EBootStatus_t bootStatusFlag;
	/** Hardware part number */
	uint8_t hwPartNum[META_HW_PART_NUM_SIZE];
	/** Software partition information */
	SSwPartInfo_t swPart[META_SW_NUM_PARTS];
	/** Software update information */
	SSwUpdateInfo_t swUpdateInfo;
	/** VariantId */
	uint8_t variantId;	
	/** Metadata checksum */
	uint32_t checksum;
} SMetadata_t;

void Metadata_Init(void);
int32_t Metadata_GetInfo(SMetadata_t *pMetadata);
int32_t Metadata_GetBootStatusFlag(uint8_t *flag);
int32_t Metadata_SetBootStatusFlag(uint8_t  flag);
int32_t Metadata_GetActivePartition(uint16_t swPartId, EPartition_t *partition);
int32_t Metadata_SetActivePartition(uint16_t swPartId, EPartition_t  partition, uint8_t bIgnorePartitionSts);
int32_t Metadata_GetPartitionInfo(uint16_t swPartId, EPartition_t partitionType, SSwPartitionInfo_t *pPartitionInfo);
int32_t Metadata_SetPartitionInfo(uint16_t swPartId, EPartition_t partitionType, SSwPartitionInfo_t *pPartitionInfo);
int32_t Metadata_GetSwUpdateInfo(SSwUpdateInfo_t *pSwUpdateInfo);
int32_t Metadata_SetSwUpdateInfo(SSwUpdateInfo_t *pSwUpdateInfo);
int32_t Metadata_IncrementUpdateId(void);
int32_t Metadata_IncrementSwPartUpdateId(uint16_t swPartId);
int32_t Metadata_GetSwPartInfo(uint16_t swPartId, SSwPartInfo_t *pSwPartInfo);
int32_t Metadata_GetVariantID(uint8_t *flag);
int32_t Metadata_SetVariantID(uint8_t  flag);
#endif //METADATA_H
