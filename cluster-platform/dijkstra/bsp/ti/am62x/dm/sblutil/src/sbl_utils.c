#include <stdint.h>
#include <stdlib.h>
#include "ti_drivers_config.h"
#include "ti_drivers_open_close.h"
#include "ti_board_open_close.h"
#include "metadata.h"
#include "program_cfg.h"
#include "sbl_utils.h"
#include "kernel/dpl/AddrTranslateP.h"

SMetadata_t *pMetadata = NULL;
#define Partition_A                                         (0xAAU)
#define Partition_B                                         (0x55U)
#define METADATA_BASE                                       (0xFC0000U)

#ifndef DM_WD_DISABLE
void InternalWatchdog_Service(void);
#endif

#ifndef SOC_SILICON_REVISION_1_3
#define SOC_SILICON_REVISION_1_3 0x13
#endif

uint8_t metadata_buffer[META_SIZE] __attribute__ ((section (".bss.meta"), aligned (128)));

int32_t loadMetadata(void)
{
    uint32_t checksum = 0;
    uint32_t idx;
    int32_t status = SystemP_FAILURE;

    if (NULL == pMetadata)
    {
        pMetadata = (SMetadata_t *)metadata_buffer;
        status = Flash_read(gFlashHandle[CONFIG_FLASH_SBL], METADATA_BASE + META_A_OFFSET, metadata_buffer, META_SIZE);
        CacheP_wb(metadata_buffer, 512, CacheP_TYPE_ALL);

        if(status == SystemP_SUCCESS)
        {
            checksum = 0;
            for(idx = 0; idx < (sizeof(SMetadata_t) - META_CHECKSUM_SIZE); idx++)
            {
                checksum += metadata_buffer[idx];
            }
            if(checksum == pMetadata->checksum)
            {
                DebugP_log("Metadata A OK\r\n");
            }
            else
            {
                status = SystemP_FAILURE;
            }
        }
        else
        {
            DebugP_logError("Metadata A read failed\r\n");
        }

        if(status == SystemP_FAILURE)
        {
            DebugP_logError("Metadata A checksum failed %d, %d\r\n", pMetadata->checksum, checksum);

            status = Flash_read(gFlashHandle[CONFIG_FLASH_SBL], METADATA_BASE + META_B_OFFSET, metadata_buffer, META_SIZE);
            CacheP_wb(metadata_buffer, 512, CacheP_TYPE_ALL);

            if(status == SystemP_SUCCESS)
            {
                checksum = 0;
                for(idx = 0; idx < (sizeof(SMetadata_t) - META_CHECKSUM_SIZE); idx++)
                {
                    checksum += metadata_buffer[idx];
                }

                if(checksum == pMetadata->checksum)
                {
                    DebugP_log("Metadata B OK\r\n");
                }
                else
                {
                    DebugP_logError("Metadata B checksum failed %d, %d\r\n", pMetadata->checksum, checksum);   
                    pMetadata = NULL;
                    status = SystemP_FAILURE;  
                }
            }
            else
            {
                pMetadata = NULL;
                DebugP_logError("Metadata B read failed\r\n");       
            }
        }
    }
    else
    {
        status = SystemP_SUCCESS;
    }

    return status;
}

int32_t saveMetadata(void)
{
    uint32_t checksum = 0;
    uint32_t idx;
    uint32_t blk, page;
    int32_t status = SystemP_FAILURE;

    if (NULL != pMetadata)
    {
		#ifndef DM_WD_DISABLE
		InternalWatchdog_Service();
		#endif
        checksum = 0;
        for(idx = 0; idx < (sizeof(SMetadata_t) - META_CHECKSUM_SIZE); idx++)
        {
            checksum += metadata_buffer[idx];
        }

        pMetadata->checksum = checksum;

        Flash_Attrs *flashAttrs = Flash_getAttrs(CONFIG_FLASH_SBL);
        if(flashAttrs != NULL)
        {
            uint32_t eraseBlockSize = flashAttrs->pageCount * flashAttrs->pageSize;
            uint32_t curOffset = METADATA_BASE + META_A_OFFSET;
            
            CacheP_wb(metadata_buffer, META_SIZE, CacheP_TYPE_ALL);

            while(curOffset < (METADATA_BASE + META_A_OFFSET + META_SIZE))
            {
                Flash_offsetToBlkPage(gFlashHandle[CONFIG_FLASH_SBL], curOffset, &blk, &page);
                Flash_eraseBlk(gFlashHandle[CONFIG_FLASH_SBL], blk);
                curOffset = curOffset + eraseBlockSize;
            }
            status = Flash_write(gFlashHandle[CONFIG_FLASH_SBL], METADATA_BASE + META_A_OFFSET, metadata_buffer, META_SIZE);

            if(SystemP_SUCCESS == status)
            {
				#ifndef DM_WD_DISABLE
				InternalWatchdog_Service();
				#endif
                curOffset = METADATA_BASE + META_B_OFFSET;

                while(curOffset < (METADATA_BASE + META_B_OFFSET + META_SIZE))
                {
                    Flash_offsetToBlkPage(gFlashHandle[CONFIG_FLASH_SBL], curOffset, &blk, &page);
                    Flash_eraseBlk(gFlashHandle[CONFIG_FLASH_SBL], blk);
                    curOffset = curOffset + eraseBlockSize;
                }
                status = Flash_write(gFlashHandle[CONFIG_FLASH_SBL], METADATA_BASE + META_B_OFFSET, metadata_buffer, META_SIZE);
            }
        }

		#ifndef DM_WD_DISABLE
		InternalWatchdog_Service();
		#endif
        if(status == SystemP_SUCCESS)
        {
            DebugP_log("Metadata Saved\r\n");
        }
        else
        {
            DebugP_logError("Metadata Save failed\r\n");
        }
    }

    return status;
}

uint8_t getActiveBank(void)
{
    uint8_t bank = BANK_A;

    if(SystemP_SUCCESS == loadMetadata())
    {
        if (Partition_A == pMetadata->swPart[ESwPartId_SBL].activePartition)
        {
            bank = BANK_A;
        }
        else if (Partition_B == pMetadata->swPart[ESwPartId_SBL].activePartition)
        {
            bank = BANK_B;
        }
        else
        {
            bank = BANK_INVALID;
        }
    }

    return bank;
}

uint8_t getBootMode(void)
{
    uint8_t mode = BOOT_PRIMARY;

    if(SystemP_SUCCESS == loadMetadata())
    {
        if (EBootStatus_Normal == pMetadata->bootStatusFlag)
        {
            mode = BOOT_PRIMARY;
        }
        else if (EBootStatus_Bootloader == pMetadata->bootStatusFlag)
        {
            mode = BOOT_RECOVERY;
        }
        else
        {
            mode = BOOT_PRIMARY;
        }
    }

    return mode;
}

uint8_t setBootMode(uint8_t flag)
{
    if(SystemP_SUCCESS == loadMetadata())
    {
        if (BOOT_PRIMARY == flag)
        {
            pMetadata->bootStatusFlag = EBootStatus_Normal;
        }
        else if (BOOT_RECOVERY == flag)
        {
            pMetadata->bootStatusFlag = EBootStatus_Bootloader;
        }
        else
        {
            pMetadata->bootStatusFlag = EBootStatus_Normal;
        }
        return saveMetadata();
    }
    return SystemP_FAILURE;
}

int32_t isMetadataAvaiable(void)
{
    if (NULL == pMetadata)
    {
        return FALSE;
    }
    return TRUE;
}

void board_reboot(void)
{
    SOC_generateSwWarmResetMcuDomain();
    while(1);
}

uint32_t ReadActiveBootIndex(void)
{
	uint32_t bootIndex = 0xFFFFFFFFul;
	uint32_t tableLength = CSL_REG16_RD(AddrTranslateP_getLocalAddr(0x43c4f298));
	uint32_t ROMVersion = CSL_REG32_RD(AddrTranslateP_getLocalAddr(0x4182FF80));
	//uint32_t ROMDate = CSL_REG32_RD(AddrTranslateP_getLocalAddr(0x4182FF84));
	//DebugP_log("0x%08X\r\n",ROMDate);
	if ((312==tableLength) && (ROMVersion == 0x00010000)) // A0 E4
	{
		bootIndex = CSL_REG32_RD(AddrTranslateP_getLocalAddr(0x43C4F3BCu));
	}
	else
	if( (316==tableLength) && (ROMVersion == 0x00010000)) // A1 E4
	{
		bootIndex = CSL_REG32_RD(AddrTranslateP_getLocalAddr(0x43C4F3C4u));
	}
	else  // return invalid index
	{
		bootIndex = 0xFFFFFFFFul;
	}
	return bootIndex;
}
