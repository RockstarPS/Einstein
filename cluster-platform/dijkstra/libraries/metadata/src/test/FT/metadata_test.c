#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include "debug.h"
#include "metadata.h"


static void dump_metadata(void)
{
	SMetadata_t meta;
	uint32_t idx, idx1;

	if(EOK == Metadata_GetInfo(&meta))
	{
		printf("Metadata_GetInfo - Pass\n");
	}
	else
	{
		printf("Metadata_GetInfo - Failed\n");
	}
	
	
	printf("version          : %d\n",     meta.version);
	printf("numSwParts       : %d\n",     meta.numSwParts);
	printf("updateId         : %d\n",     meta.updateId);
	printf("bootStatusFlag   : %d\n",     meta.bootStatusFlag);
	printf("variantId        : %d\n",     meta.variantId);
	printf("hwPartNum        : 0x");
	for(idx1 = 0; idx1 < META_HW_PART_NUM_SIZE; idx1++)
	{
		printf("%02x", meta.hwPartNum[idx1]);
	}
	printf("\n");
	printf("checksum         : 0x%08x\n", meta.checksum);
	printf("swUpdateInfo.fotaUpdateTotal                : 0x%08x\n", meta.swUpdateInfo.fotaUpdateTotal);
	printf("swUpdateInfo.fotaUpdateSuccess              : 0x%08x\n", meta.swUpdateInfo.fotaUpdateSuccess);
	printf("swUpdateInfo.fotaUpdateFail                 : 0x%08x\n", meta.swUpdateInfo.fotaUpdateFail);
	printf("swUpdateInfo.blUpdateTotal                  : 0x%08x\n", meta.swUpdateInfo.blUpdateTotal);
	printf("swUpdateInfo.blUpdateSuccess                : 0x%08x\n", meta.swUpdateInfo.blUpdateSuccess);
	printf("swUpdateInfo.blUpdateFail                   : 0x%08x\n", meta.swUpdateInfo.blUpdateFail);
	printf("swUpdateInfo.lastUpdatePkgSign              : 0x");
	for(idx1 = 0; idx1 < META_PKG_SIGN_SIZE; idx1++)
	{
		printf("%02x", meta.swUpdateInfo.lastUpdatePkgSign[idx1]);
	}
	printf("\n");

	for(idx = 0; idx < meta.numSwParts; idx++)
	{
		printf("SwPart %d : imageType         : %d\n",     idx, meta.swPart[idx].imageType);
		printf("SwPart %d : swPartId          : %d\n",     idx, meta.swPart[idx].swPartId);
		printf("SwPart %d : updateId          : %d\n",     idx, meta.swPart[idx].updateId);
		printf("SwPart %d : activePartition   : %d\n",     idx, meta.swPart[idx].activePartition);
		printf("SwPart %d : imageName         : %s\n",     idx, meta.swPart[idx].imageName);
		printf("SwPart %d : swPartNum         : 0x",       idx);
		for(idx1 = 0; idx1 < META_SW_PART_NUM_SIZE; idx1++)
		{
			printf("%02x", meta.swPart[idx].swPartNum[idx1]);
		}
		printf("\n");
		printf("SwPart %d : Partition A : deviceType           : %d\n",       idx, meta.swPart[idx].partitionInfo[EPartition_A].deviceType);
		printf("SwPart %d : Partition A : devicePhyPartId      : %d\n",       idx, meta.swPart[idx].partitionInfo[EPartition_A].devicePhyPartId);
		printf("SwPart %d : Partition A : startAddress         : 0x%08x\n",   idx, meta.swPart[idx].partitionInfo[EPartition_A].startAddress);
		printf("SwPart %d : Partition A : size                 : %d\n",       idx, meta.swPart[idx].partitionInfo[EPartition_A].size);
		printf("SwPart %d : Partition A : status               : %d\n",       idx, meta.swPart[idx].partitionInfo[EPartition_A].status);
		printf("SwPart %d : Partition A : version              : %d.%d.%d\n", idx, meta.swPart[idx].partitionInfo[EPartition_A].version.major,
		meta.swPart[idx].partitionInfo[EPartition_A].version.minor, meta.swPart[idx].partitionInfo[EPartition_A].version.patch);
		printf("SwPart %d : Partition A : checksum         : 0x", idx);
		for(idx1 = 0; idx1 < META_SWPART_CHKSUM_SIZE; idx1++)
		{
			printf("%02x", meta.swPart[idx].partitionInfo[EPartition_A].checksum[idx1]);
		}
		printf("\n");
		printf("SwPart %d : Partition B : deviceType           : %d\n",       idx, meta.swPart[idx].partitionInfo[EPartition_B].deviceType);
		printf("SwPart %d : Partition B : devicePhyPartId      : %d\n",       idx, meta.swPart[idx].partitionInfo[EPartition_B].devicePhyPartId);
		printf("SwPart %d : Partition B : startAddress         : 0x%08x\n",   idx, meta.swPart[idx].partitionInfo[EPartition_B].startAddress);
		printf("SwPart %d : Partition B : size                 : %d\n",       idx, meta.swPart[idx].partitionInfo[EPartition_B].size);
		printf("SwPart %d : Partition B : status               : %d\n",       idx, meta.swPart[idx].partitionInfo[EPartition_B].status);
		printf("SwPart %d : Partition B : version              : %d.%d.%d\n", idx, meta.swPart[idx].partitionInfo[EPartition_B].version.major,
		meta.swPart[idx].partitionInfo[EPartition_B].version.minor, meta.swPart[idx].partitionInfo[EPartition_B].version.patch);
		printf("SwPart %d : Partition B : checksum         : 0x", idx);
		for(idx1 = 0; idx1 < META_SWPART_CHKSUM_SIZE; idx1++)
		{
			printf("%02x", meta.swPart[idx].partitionInfo[EPartition_B].checksum[idx1]);
		}
		printf("\n");
		printf("SwPart %d : Partition Inactive : deviceType           : %d\n",       idx, meta.swPart[idx].partitionInfo[EPartition_Inactive].deviceType);
		printf("SwPart %d : Partition Inactive : devicePhyPartId      : %d\n",       idx, meta.swPart[idx].partitionInfo[EPartition_Inactive].devicePhyPartId);
		printf("SwPart %d : Partition Inactive : startAddress         : 0x%08x\n",   idx, meta.swPart[idx].partitionInfo[EPartition_Inactive].startAddress);
		printf("SwPart %d : Partition Inactive : size                 : %d\n",       idx, meta.swPart[idx].partitionInfo[EPartition_Inactive].size);
		printf("SwPart %d : Partition Inactive : status               : %d\n",       idx, meta.swPart[idx].partitionInfo[EPartition_Inactive].status);
		printf("SwPart %d : Partition Inactive : version              : %d.%d.%d\n", idx, meta.swPart[idx].partitionInfo[EPartition_Inactive].version.major,
		meta.swPart[idx].partitionInfo[EPartition_Inactive].version.minor, meta.swPart[idx].partitionInfo[EPartition_Inactive].version.patch);
		printf("SwPart %d : Partition Inactive : checksum         : 0x", idx);
		for(idx1 = 0; idx1 < META_SWPART_CHKSUM_SIZE; idx1++)
		{
			printf("%02x", meta.swPart[idx].partitionInfo[EPartition_Inactive].checksum[idx1]);
		}
		printf("\n");
	}
}

void increment_udpateId()
{
	int32_t ret = EOK;

	ret = Metadata_IncrementUpdateId();
	if(ret == EOK)
	{
		printf("SUCCESS: updatedId Incremented\n");
	}
	else
	{
		printf("ERROR : Metadata_IncrementUpdateId failed : %d\n", ret);
	}	
}

void increment_swPartUdpateId(uint8_t swPartId)
{
	int32_t ret = EOK;

	ret = Metadata_IncrementSwPartUpdateId(swPartId);
	if(ret == EOK)
	{
		printf("SUCCESS: Incremented udpatedId for SW part %u\n", swPartId);
	}
	else
	{
		printf("ERROR : Metadata_IncrementSwPartUpdateId failed : %d\n", ret);
	}	
}

void get_active_partition(uint8_t swPartId)
{
	int32_t ret = EOK;
	uint8_t partitionId = EPartition_Last;

	ret = Metadata_GetActivePartition(swPartId, &partitionId);
	if(ret == EOK)
	{
		printf("SUCCESS: Active Partition SW part %u is %u\n", swPartId, partitionId);
	}
	else
	{
		printf("ERROR : Metadata_GetActivePartition failed : %d\n", ret);
	}	
}

void set_active_partition(uint8_t swPartId, uint8_t partitionId)
{
	int32_t ret = EOK;
	
	ret = Metadata_SetActivePartition(swPartId, partitionId, TRUE);
	if(ret == EOK)
	{
		printf("SUCCESS: Active Partition set as %u for SW part %u\n", partitionId, swPartId);
	}
	else
	{
		printf("ERROR : Metadata_SetActivePartition failed : %d\n", ret);
	}	
}

void get_boot_status_flag()
{
	int32_t ret = EOK;
	uint8_t flag;

	ret = Metadata_GetBootStatusFlag(&flag);
	if(ret == EOK)
	{
		printf("SUCCESS: Boot Status Flag : %u\n", flag);
	}
	else
	{
		printf("ERROR : Metadata_GetBootStatusFlag failed : %d\n", ret);
	}	
}

void set_boot_status_flag(uint8_t flag)
{
	int32_t ret = EOK;
	
	ret = Metadata_SetBootStatusFlag(flag);
	if(ret == EOK)
	{
		printf("SUCCESS:  Boot Status Flag updated\n");
	}
	else
	{
		printf("ERROR : Metadata_SetBootStatusFlag failed : %d\n", ret);
	}	
}

void get_variantId_flag()
{
	int32_t ret = EOK;
	uint8_t flag;
	ret = Metadata_GetVariantID(&flag);
	if(ret == EOK)
	{
		printf("SUCCESS: variantId  Flag is: %u\n", flag);
	}
	else
	{
		printf("ERROR : Metadata_GetVariantID failed : %d\n", ret);
	}
}

void set_variantId_flag(uint8_t flag)
{
	int32_t ret = EOK;

	ret = Metadata_SetVariantID(flag);
	if(ret == EOK)
	{
		printf("SUCCESS: variantId Flag updated \n");
	}
	else
	{
		printf("ERROR : Metadata_SetVariantID failed : %d\n", ret);
	}
}

void get_partition_info(uint8_t swPartId, uint8_t partitionId)
{
	int32_t ret = EOK;
	SSwPartitionInfo_t PartitionInfo;
	
	ret = Metadata_GetPartitionInfo(swPartId, partitionId, &PartitionInfo);
	if(ret == EOK)
	{
		printf("SUCCESS: Metadata_GetPartitionInfo : Partition %u for SW part %u\n", partitionId, swPartId);
		printf("SwPart %d : Partition %d : deviceType           : %d\n",       swPartId, partitionId, PartitionInfo.deviceType);
		printf("SwPart %d : Partition %d : devicePhyPartId      : %d\n",       swPartId, partitionId, PartitionInfo.devicePhyPartId);
		printf("SwPart %d : Partition %d : startAddress         : 0x%08x\n",   swPartId, partitionId, PartitionInfo.startAddress);
		printf("SwPart %d : Partition %d : size                 : %d\n",       swPartId, partitionId, PartitionInfo.size);
		printf("SwPart %d : Partition %d : status               : %d\n",       swPartId, partitionId, PartitionInfo.status);
		printf("SwPart %d : Partition %d : version              : %d.%d.%d\n", swPartId, partitionId, PartitionInfo.version.major,
																			   PartitionInfo.version.minor, PartitionInfo.version.patch);
		printf("SwPart %d : Partition %d : checksum             : 0x",         swPartId, partitionId);
		for(uint32_t idx = 0; idx < META_SWPART_CHKSUM_SIZE; idx++)
		{
			printf("%02x", PartitionInfo.checksum[idx]);
		}
		printf("\n");
	}
	else
	{
		printf("ERROR : Metadata_GetPartitionInfo failed : %d\n", ret);
	}	
}

void set_partition_info(uint8_t swPartId, uint8_t partitionId, char *arglist)
{
	int32_t ret = EOK;
	SSwPartitionInfo_t PartitionInfo;
    uint32_t idx = 0;
    char * token = strtok(arglist, ",");

    while( token != NULL ) {
        printf( " %s\n", token );
        switch(idx)
        {
            case 0:
            PartitionInfo.startAddress = atoi(token);
            break;
            case 1:
            PartitionInfo.size = atoi(token);
            break;
            case 2:
		    for (size_t count = 0; count < META_SWPART_CHKSUM_SIZE; count++) {
				sscanf(&token[count*2], "%2hhx", &PartitionInfo.checksum[count]);
			}            
            break;
            case 3:
            PartitionInfo.version.major = atoi(token);
            break;
            case 4:
            PartitionInfo.version.minor = atoi(token);
            break;
            case 5:
            PartitionInfo.version.patch = atoi(token);
            break;
            case 6:
            PartitionInfo.status = atoi(token);
            break;
        }
        idx++;
        token = strtok(NULL, ",");
    }

	ret = Metadata_SetPartitionInfo(swPartId, partitionId, &PartitionInfo);
	if(ret == EOK)
	{
		printf("SUCCESS: Metadata_SetPartitionInfo\n");
	}
	else
	{
		printf("ERROR : Metadata_SetPartitionInfo failed : %d\n", ret);
	}
}

void get_swpart_info(uint8_t swPartId)
{
	int32_t ret = EOK;
	SSwPartInfo_t SwPartInfo;
	uint32_t idx1;
	
	ret = Metadata_GetSwPartInfo(swPartId, &SwPartInfo);
	if(ret == EOK)
	{
		printf("SUCCESS: Metadata_GetSwPartInfo : SW part %u\n", swPartId);
		printf("SwPart %d : imageType         : %d\n",     swPartId, SwPartInfo.imageType);
		printf("SwPart %d : swPartId          : %d\n",     swPartId, SwPartInfo.swPartId);
		printf("SwPart %d : updateId          : %d\n",     swPartId, SwPartInfo.updateId);
		printf("SwPart %d : activePartition   : %d\n",     swPartId, SwPartInfo.activePartition);
		printf("SwPart %d : imageName         : %s\n",     swPartId, SwPartInfo.imageName);
		printf("SwPart %d : swPartNum         : 0x",       swPartId);
		for(idx1 = 0; idx1 < META_SW_PART_NUM_SIZE; idx1++)
		{
			printf("%02x", SwPartInfo.swPartNum[idx1]);
		}
		printf("\n");
		printf("SwPart %d : Partition A : deviceType           : %d\n",       swPartId, SwPartInfo.partitionInfo[EPartition_A].deviceType);
		printf("SwPart %d : Partition A : devicePhyPartId      : %d\n",       swPartId, SwPartInfo.partitionInfo[EPartition_A].devicePhyPartId);
		printf("SwPart %d : Partition A : startAddress         : 0x%08x\n",   swPartId, SwPartInfo.partitionInfo[EPartition_A].startAddress);
		printf("SwPart %d : Partition A : size                 : %d\n",       swPartId, SwPartInfo.partitionInfo[EPartition_A].size);
		printf("SwPart %d : Partition A : status               : %d\n",       swPartId, SwPartInfo.partitionInfo[EPartition_A].status);
		printf("SwPart %d : Partition A : version              : %d.%d.%d\n", swPartId, SwPartInfo.partitionInfo[EPartition_A].version.major,
		SwPartInfo.partitionInfo[EPartition_A].version.minor, SwPartInfo.partitionInfo[EPartition_A].version.patch);
		printf("SwPart %d : Partition A : checksum         : 0x", swPartId);
		for(idx1 = 0; idx1 < META_SWPART_CHKSUM_SIZE; idx1++)
		{
			printf("%02x", SwPartInfo.partitionInfo[EPartition_A].checksum[idx1]);
		}
		printf("\n");
		printf("SwPart %d : Partition B : deviceType           : %d\n",       swPartId, SwPartInfo.partitionInfo[EPartition_B].deviceType);
		printf("SwPart %d : Partition B : devicePhyPartId      : %d\n",       swPartId, SwPartInfo.partitionInfo[EPartition_B].devicePhyPartId);
		printf("SwPart %d : Partition B : startAddress         : 0x%08x\n",   swPartId, SwPartInfo.partitionInfo[EPartition_B].startAddress);
		printf("SwPart %d : Partition B : size                 : %d\n",       swPartId, SwPartInfo.partitionInfo[EPartition_B].size);
		printf("SwPart %d : Partition B : status               : %d\n",       swPartId, SwPartInfo.partitionInfo[EPartition_B].status);
		printf("SwPart %d : Partition B : version              : %d.%d.%d\n", swPartId, SwPartInfo.partitionInfo[EPartition_B].version.major,
		SwPartInfo.partitionInfo[EPartition_B].version.minor, SwPartInfo.partitionInfo[EPartition_B].version.patch);
		printf("SwPart %d : Partition B : checksum         : 0x", swPartId);
		for(idx1 = 0; idx1 < META_SWPART_CHKSUM_SIZE; idx1++)
		{
			printf("%02x", SwPartInfo.partitionInfo[EPartition_B].checksum[idx1]);
		}
		printf("\n");
		printf("SwPart %d : Partition Inactive : deviceType           : %d\n",       swPartId, SwPartInfo.partitionInfo[EPartition_Inactive].deviceType);
		printf("SwPart %d : Partition Inactive : devicePhyPartId      : %d\n",       swPartId, SwPartInfo.partitionInfo[EPartition_Inactive].devicePhyPartId);
		printf("SwPart %d : Partition Inactive : startAddress         : 0x%08x\n",   swPartId, SwPartInfo.partitionInfo[EPartition_Inactive].startAddress);
		printf("SwPart %d : Partition Inactive : size                 : %d\n",       swPartId, SwPartInfo.partitionInfo[EPartition_Inactive].size);
		printf("SwPart %d : Partition Inactive : status               : %d\n",       swPartId, SwPartInfo.partitionInfo[EPartition_Inactive].status);
		printf("SwPart %d : Partition Inactive : version              : %d.%d.%d\n", swPartId, SwPartInfo.partitionInfo[EPartition_Inactive].version.major,
		SwPartInfo.partitionInfo[EPartition_Inactive].version.minor, SwPartInfo.partitionInfo[EPartition_Inactive].version.patch);
		printf("SwPart %d : Partition Inactive : checksum         : 0x", swPartId);
		for(idx1 = 0; idx1 < META_SWPART_CHKSUM_SIZE; idx1++)
		{
			printf("%02x", SwPartInfo.partitionInfo[EPartition_Inactive].checksum[idx1]);
		}
		printf("\n");
	}
	else
	{
		printf("ERROR : Metadata_GetSwPartInfo failed : %d\n", ret);
	}		
}

void set_swupdate_info(char *arglist)
{
	int32_t ret = EOK;
	SSwUpdateInfo_t SwUpdateInfo;
    uint32_t idx = 0;
    char * token = strtok(arglist, ",");

    while( token != NULL ) {
        printf( " %s\n", token );
        switch(idx)
        {
            case 0:
            SwUpdateInfo.fotaUpdateTotal = atoi(token);
            break;
            case 1:
            SwUpdateInfo.fotaUpdateSuccess = atoi(token);
            break;
            case 2:
            SwUpdateInfo.fotaUpdateFail = atoi(token);
            break;
            case 3:
            SwUpdateInfo.blUpdateTotal = atoi(token);
            break;
            case 4:
            SwUpdateInfo.blUpdateSuccess = atoi(token);
            break;
            case 5:
            SwUpdateInfo.blUpdateFail = atoi(token);
            break;
            case 6:
		    for (size_t count = 0; count < META_PKG_SIGN_SIZE; count++) {
				sscanf(&token[count*2], "%2hhx", &SwUpdateInfo.lastUpdatePkgSign[count]);
			}            
            break;
        }
        idx++;
        token = strtok(NULL, ",");
    }

	ret = Metadata_SetSwUpdateInfo(&SwUpdateInfo);
	if(ret == EOK)
	{
		printf("SUCCESS: Metadata_SetSwUpdateInfo\n");
	}
	else
	{
		printf("ERROR : Metadata_GetSwUpdateInfo failed : %d\n", ret);
	}
}

void get_swupdate_info()
{
	int32_t ret = EOK;
	SSwUpdateInfo_t SwUpdateInfo;
	uint32_t idx1;

	ret = Metadata_GetSwUpdateInfo(&SwUpdateInfo);
	if(ret == EOK)
	{
		printf("SUCCESS: Metadata_GetSwUpdateInfo\n");
		printf("swUpdateInfo.fotaUpdateTotal                : 0x%08x\n", SwUpdateInfo.fotaUpdateTotal);
		printf("swUpdateInfo.fotaUpdateSuccess              : 0x%08x\n", SwUpdateInfo.fotaUpdateSuccess);
		printf("swUpdateInfo.fotaUpdateFail                 : 0x%08x\n", SwUpdateInfo.fotaUpdateFail);
		printf("swUpdateInfo.blUpdateTotal                  : 0x%08x\n", SwUpdateInfo.blUpdateTotal);
		printf("swUpdateInfo.blUpdateSuccess                : 0x%08x\n", SwUpdateInfo.blUpdateSuccess);
		printf("swUpdateInfo.blUpdateFail                   : 0x%08x\n", SwUpdateInfo.blUpdateFail);
		printf("swUpdateInfo.lastUpdatePkgSign              : 0x");
		for(idx1 = 0; idx1 < META_PKG_SIGN_SIZE; idx1++)
		{
			printf("%02x", SwUpdateInfo.lastUpdatePkgSign[idx1]);
		}
		printf("\n");
	}
	else
	{
		printf("ERROR : Metadata_GetSwUpdateInfo failed : %d\n", ret);
	}	
}

void print_help(void)
{
    printf("Usage: metadata_test -c <cmd> -s <swPartId> -p <paritiionId> -f <bootStatusFlag> -l <arg list>");
    printf("\tList of commands\n");
    printf("\t\t0  - Dump metadata\n");
    printf("\t\t1  - Set Active Partition. valid -s and -p options are required\n");
    printf("\t\t2  - Get Active Partition. valid -s option is required\n");
    printf("\t\t3  - Increment UpdateId\n");
    printf("\t\t4  - Increment Sw Part UpdateId. valid -s option is required\n");
    printf("\t\t5  - Get boot status flag\n");
    printf("\t\t6  - Set boot status flag. valid -f option is required\n");
    printf("\t\t7  - Get SW Partition Info. valid -s and -p options are required\n");
    printf("\t\t8  - Get SW Part Info. valid -s option is required\n");
    printf("\t\t9  - Get SW Update Info\n");
    printf("\t\t10 - Set SW Update Info. valid -l option is required\n");
    printf("\t\t11 - Set SW Partition Info. valid -s, -p, -l options are required\n");
    printf("\t\t12  - Get variantId flag\n");
    printf("\t\t13  - Set variantId flag. valid -f option is required\n");
}

int32_t main(int32_t argc, char** argv) 
{
	int32_t c;
	int32_t cmd = -1;
	uint8_t swPartId = ESwPartId_Last;
	uint8_t partitionId = EPartition_Last;
	uint8_t flag = 0;
    char *arglist = NULL;
	
	Metadata_Init();
	
	while ((c = getopt (argc, argv, "c:s:p:f:l:h")) != -1)
	{
		switch(c)
		{
			case 'c':
				cmd = strtol(optarg, NULL, 10);
				break;
			case 's':
				swPartId = strtol(optarg, NULL, 10);
				break;
			case 'p':
				partitionId = strtol(optarg, NULL, 10);
				break;
			case 'f':
				flag = strtol(optarg, NULL, 10);
				break;
			case 'l':
				arglist = optarg;
				break;
			case 'h':
				print_help();
				exit(0);
				break;
		}
	}

	switch(cmd)
	{
		case 0:
			dump_metadata();
			break;
		case 1:
			set_active_partition(swPartId, partitionId);
			break;
		case 2:
			get_active_partition(swPartId);
			break;
		case 3:
			increment_udpateId();
			break;
		case 4:
			increment_swPartUdpateId(swPartId);
			break;
		case 5:
			get_boot_status_flag();
			break;
		case 6:
			set_boot_status_flag(flag);
			break;
		case 7:
			get_partition_info(swPartId, partitionId);
			break;
		case 8:
			get_swpart_info(swPartId);
			break;
		case 9:
			get_swupdate_info();
			break;
		case 10:
			set_swupdate_info(arglist);
			break;
   		case 11:
 			set_partition_info(swPartId, partitionId, arglist);
			break;    
		case 12:
			get_variantId_flag();
			break;
		case 13:
			set_variantId_flag(flag);
			break;
		default:
			break;
	}
	return EXIT_SUCCESS;
}
