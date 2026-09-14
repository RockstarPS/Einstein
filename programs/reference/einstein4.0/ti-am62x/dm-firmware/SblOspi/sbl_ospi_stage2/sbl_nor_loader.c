#include <stdlib.h>
#include <string.h>
#include <drivers/bootloader.h>
#include "ti_drivers_config.h"
#include "ti_drivers_open_close.h"
#include "ti_board_open_close.h"
#include "FreeRTOS.h"
#include "task.h"
#include "program_cfg.h"
#include "sbl_utils.h"
#ifdef KPI_GPIO
#include <drivers/gpio.h>
#include <drivers/pinmux.h>
#endif
#include "boot_kpi_r5_dm.h"
#include "dlt.h"

extern uint8_t NORReady;
#ifndef DM_WD_DISABLE
void InternalWatchdog_Service(void);
#endif


/* This buffer needs to be defined for OSPI NOR boot in case of HS device for
 * image authentication.
 * The size of the buffer should be large enough to accomodate the appimage
 */

static uint8_t gHsmAppimage[0x200000] __attribute__ ((section (".app_nor_hsm"), aligned (128)));
static uint8_t gMcuAppimage[0x800000] __attribute__ ((section (".app_nor_mcu"), aligned (128)));
static uint8_t gSBL_Stage1_Image[0x80000] __attribute__ ((aligned (128)));

Bootloader_LoadImageParams gbootArray[CONFIG_BOOTLOADER_NUM_INSTANCES];

#define CRC_FINAL_XOR_CRC32         ((uint32_t)0xFFFFFFFFUL)
#define CRC_INITIAL_VALUE32         ((uint32_t)0xFFFFFFFFUL)
#define CRC_BIT_SHIFT               8U

static const uint32_t Crc_Table32bit[256] =
{
    0x00000000uL, 0x77073096uL, 0xEE0E612CuL, 0x990951BAuL,
    0x076DC419uL, 0x706AF48FuL, 0xE963A535uL, 0x9E6495A3uL,
    0x0EDB8832uL, 0x79DCB8A4uL, 0xE0D5E91EuL, 0x97D2D988uL,
    0x09B64C2BuL, 0x7EB17CBDuL, 0xE7B82D07uL, 0x90BF1D91uL,
    0x1DB71064uL, 0x6AB020F2uL, 0xF3B97148uL, 0x84BE41DEuL,
    0x1ADAD47DuL, 0x6DDDE4EBuL, 0xF4D4B551uL, 0x83D385C7uL,
    0x136C9856uL, 0x646BA8C0uL, 0xFD62F97AuL, 0x8A65C9ECuL,
    0x14015C4FuL, 0x63066CD9uL, 0xFA0F3D63uL, 0x8D080DF5uL,
    0x3B6E20C8uL, 0x4C69105EuL, 0xD56041E4uL, 0xA2677172uL,
    0x3C03E4D1uL, 0x4B04D447uL, 0xD20D85FDuL, 0xA50AB56BuL,
    0x35B5A8FAuL, 0x42B2986CuL, 0xDBBBC9D6uL, 0xACBCF940uL,
    0x32D86CE3uL, 0x45DF5C75uL, 0xDCD60DCFuL, 0xABD13D59uL,
    0x26D930ACuL, 0x51DE003AuL, 0xC8D75180uL, 0xBFD06116uL,
    0x21B4F4B5uL, 0x56B3C423uL, 0xCFBA9599uL, 0xB8BDA50FuL,
    0x2802B89EuL, 0x5F058808uL, 0xC60CD9B2uL, 0xB10BE924uL,
    0x2F6F7C87uL, 0x58684C11uL, 0xC1611DABuL, 0xB6662D3DuL,
    0x76DC4190uL, 0x01DB7106uL, 0x98D220BCuL, 0xEFD5102AuL,
    0x71B18589uL, 0x06B6B51FuL, 0x9FBFE4A5uL, 0xE8B8D433uL,
    0x7807C9A2uL, 0x0F00F934uL, 0x9609A88EuL, 0xE10E9818uL,
    0x7F6A0DBBuL, 0x086D3D2DuL, 0x91646C97uL, 0xE6635C01uL,
    0x6B6B51F4uL, 0x1C6C6162uL, 0x856530D8uL, 0xF262004EuL,
    0x6C0695EDuL, 0x1B01A57BuL, 0x8208F4C1uL, 0xF50FC457uL,
    0x65B0D9C6uL, 0x12B7E950uL, 0x8BBEB8EAuL, 0xFCB9887CuL,
    0x62DD1DDFuL, 0x15DA2D49uL, 0x8CD37CF3uL, 0xFBD44C65uL,
    0x4DB26158uL, 0x3AB551CEuL, 0xA3BC0074uL, 0xD4BB30E2uL,
    0x4ADFA541uL, 0x3DD895D7uL, 0xA4D1C46DuL, 0xD3D6F4FBuL,
    0x4369E96AuL, 0x346ED9FCuL, 0xAD678846uL, 0xDA60B8D0uL,
    0x44042D73uL, 0x33031DE5uL, 0xAA0A4C5FuL, 0xDD0D7CC9uL,
    0x5005713CuL, 0x270241AAuL, 0xBE0B1010uL, 0xC90C2086uL,
    0x5768B525uL, 0x206F85B3uL, 0xB966D409uL, 0xCE61E49FuL,
    0x5EDEF90EuL, 0x29D9C998uL, 0xB0D09822uL, 0xC7D7A8B4uL,
    0x59B33D17uL, 0x2EB40D81uL, 0xB7BD5C3BuL, 0xC0BA6CADuL,
    0xEDB88320uL, 0x9ABFB3B6uL, 0x03B6E20CuL, 0x74B1D29AuL,
    0xEAD54739uL, 0x9DD277AFuL, 0x04DB2615uL, 0x73DC1683uL,
    0xE3630B12uL, 0x94643B84uL, 0x0D6D6A3EuL, 0x7A6A5AA8uL,
    0xE40ECF0BuL, 0x9309FF9DuL, 0x0A00AE27uL, 0x7D079EB1uL,
    0xF00F9344uL, 0x8708A3D2uL, 0x1E01F268uL, 0x6906C2FEuL,
    0xF762575DuL, 0x806567CBuL, 0x196C3671uL, 0x6E6B06E7uL,
    0xFED41B76uL, 0x89D32BE0uL, 0x10DA7A5AuL, 0x67DD4ACCuL,
    0xF9B9DF6FuL, 0x8EBEEFF9uL, 0x17B7BE43uL, 0x60B08ED5uL,
    0xD6D6A3E8uL, 0xA1D1937EuL, 0x38D8C2C4uL, 0x4FDFF252uL,
    0xD1BB67F1uL, 0xA6BC5767uL, 0x3FB506DDuL, 0x48B2364BuL,
    0xD80D2BDAuL, 0xAF0A1B4CuL, 0x36034AF6uL, 0x41047A60uL,
    0xDF60EFC3uL, 0xA867DF55uL, 0x316E8EEFuL, 0x4669BE79uL,
    0xCB61B38CuL, 0xBC66831AuL, 0x256FD2A0uL, 0x5268E236uL,
    0xCC0C7795uL, 0xBB0B4703uL, 0x220216B9uL, 0x5505262FuL,
    0xC5BA3BBEuL, 0xB2BD0B28uL, 0x2BB45A92uL, 0x5CB36A04uL,
    0xC2D7FFA7uL, 0xB5D0CF31uL, 0x2CD99E8BuL, 0x5BDEAE1DuL,
    0x9B64C2B0uL, 0xEC63F226uL, 0x756AA39CuL, 0x026D930AuL,
    0x9C0906A9uL, 0xEB0E363FuL, 0x72076785uL, 0x05005713uL,
    0x95BF4A82uL, 0xE2B87A14uL, 0x7BB12BAEuL, 0x0CB61B38uL,
    0x92D28E9BuL, 0xE5D5BE0DuL, 0x7CDCEFB7uL, 0x0BDBDF21uL,
    0x86D3D2D4uL, 0xF1D4E242uL, 0x68DDB3F8uL, 0x1FDA836EuL,
    0x81BE16CDuL, 0xF6B9265BuL, 0x6FB077E1uL, 0x18B74777uL,
    0x88085AE6uL, 0xFF0F6A70uL, 0x66063BCAuL, 0x11010B5CuL,
    0x8F659EFFuL, 0xF862AE69uL, 0x616BFFD3uL, 0x166CCF45uL,
    0xA00AE278uL, 0xD70DD2EEuL, 0x4E048354uL, 0x3903B3C2uL,
    0xA7672661uL, 0xD06016F7uL, 0x4969474DuL, 0x3E6E77DBuL,
    0xAED16A4AuL, 0xD9D65ADCuL, 0x40DF0B66uL, 0x37D83BF0uL,
    0xA9BCAE53uL, 0xDEBB9EC5uL, 0x47B2CF7FuL, 0x30B5FFE9uL,
    0xBDBDF21CuL, 0xCABAC28AuL, 0x53B39330uL, 0x24B4A3A6uL,
    0xBAD03605uL, 0xCDD70693uL, 0x54DE5729uL, 0x23D967BFuL,
    0xB3667A2EuL, 0xC4614AB8uL, 0x5D681B02uL, 0x2A6F2B94uL,
    0xB40BBE37uL, 0xC30C8EA1uL, 0x5A05DF1BuL, 0x2D02EF8DuL
};

/*============================================================================
**
** Function Name    :   CalculateCRC32
**
** Description      :   This function calculates and returns the 32 bit CRC
**                      (32 bit Ethernet IEEE-802 with 0x04C11DB7 polynomial) for the given number of data.
**
** Invocation       :   Whoever wants to calculate the 32 bit Ethernet IEEE-802 with 0x04C11DB7 polynomial CRC.
**
** Inputs           :   p_Crc_DataPtr_U8: Pointer to the data for which the CRC to be calculated
**                      p_Crc_Length_U32: Number of bytes to be taken for calculation.
**                      Crc_StartValue32: CRC Start value
** Outputs          :   Calculated 32 bit CRC value
**
**==========================================================================*/
uint32_t CalculateCRC32 ( const uint8_t *p_Crc_DataPtr_U8, uint32_t p_Crc_Length_U32, uint32_t p_Crc_StartValue_U32)
{
    uint32_t l_Crc_Value_U32 = p_Crc_StartValue_U32;
    if ( NULL != p_Crc_DataPtr_U8 )
    {
		const uint8_t *l_DataPtrAddr_U32 = p_Crc_DataPtr_U8;
		const uint8_t *l_EndDataPtrAddr_U32 = p_Crc_DataPtr_U8 + p_Crc_Length_U32;
        while ( l_DataPtrAddr_U32 < l_EndDataPtrAddr_U32 )
        {
            l_Crc_Value_U32 ^= ( uint32_t ) 0xFFUL & ( uint32_t ) *l_DataPtrAddr_U32;
            l_Crc_Value_U32 = ( l_Crc_Value_U32 >> ( CRC_BIT_SHIFT ) ) ^ ( Crc_Table32bit [ ( uint8_t ) ( l_Crc_Value_U32 )] );
            l_DataPtrAddr_U32++;
        }
    }
    return l_Crc_Value_U32;
}

static int32_t isStage1_OK(uint32_t index)
{
    int32_t status = SystemP_SUCCESS;
	//char SymbS1[2] = {'A','B'};

    //DebugP_log("Loading stage 1%c\r\n",SymbS1[index]);
    Flash_read(gFlashHandle[CONFIG_FLASH_SBL], 0x400000*index, gSBL_Stage1_Image, sizeof gSBL_Stage1_Image);

    uint32_t stage1CheckSum = ((uint32_t)gSBL_Stage1_Image[0+sizeof(gSBL_Stage1_Image)-4] << 24) |
                              ((uint32_t)gSBL_Stage1_Image[1+sizeof(gSBL_Stage1_Image)-4] << 16) |
                              ((uint32_t)gSBL_Stage1_Image[2+sizeof(gSBL_Stage1_Image)-4] << 8)  |
                              ((uint32_t)gSBL_Stage1_Image[3+sizeof(gSBL_Stage1_Image)-4]);
    //DebugP_log("stage1%c checkSum = 0x%08X (embedded)\r\n",SymbS1[index],stage1CheckSum);
    uint32_t stage1CalcCheckSum = CalculateCRC32(gSBL_Stage1_Image, sizeof(gSBL_Stage1_Image)-4, CRC_INITIAL_VALUE32) ^ CRC_FINAL_XOR_CRC32;
    //DebugP_log("stage1%c checkSum = 0x%08X (calculated)\r\n",SymbS1[index],stage1CalcCheckSum);

    if(stage1CheckSum == stage1CalcCheckSum)
    {
        status = SystemP_SUCCESS;
    }
    else
    {
        status = SystemP_FAILURE;
    }

    return status;

}

static void CopyS1Image(uint32_t srcIndex, uint32_t dstIndex)
{
	char SymbS1[2] = {'A','B'};
	int32_t status = SystemP_FAILURE;
	DebugP_log("NOR: restoring OSPI stage 1%c from 1%c !!!\r\n", SymbS1[dstIndex],SymbS1[srcIndex]);
	if (SystemP_SUCCESS == Flash_read(gFlashHandle[CONFIG_FLASH_SBL], 0x400000*srcIndex, gSBL_Stage1_Image, sizeof gSBL_Stage1_Image))
	{
		uint32_t stage1CheckSum = ((uint32_t)gSBL_Stage1_Image[0+sizeof(gSBL_Stage1_Image)-4] << 24) |
								  ((uint32_t)gSBL_Stage1_Image[1+sizeof(gSBL_Stage1_Image)-4] << 16) |
								  ((uint32_t)gSBL_Stage1_Image[2+sizeof(gSBL_Stage1_Image)-4] << 8)  |
								  ((uint32_t)gSBL_Stage1_Image[3+sizeof(gSBL_Stage1_Image)-4]);
		//DebugP_log("stage1%c checkSum = 0x%08X (embedded)\r\n",SymbS1[index],stage1CheckSum);
		uint32_t stage1CalcCheckSum = CalculateCRC32(gSBL_Stage1_Image, sizeof(gSBL_Stage1_Image)-4, CRC_INITIAL_VALUE32) ^ CRC_FINAL_XOR_CRC32;
		//DebugP_log("stage1%c checkSum = 0x%08X (calculated)\r\n",SymbS1[index],stage1CalcCheckSum);

		if(stage1CheckSum == stage1CalcCheckSum)
		{
			uint32_t addr,destaddr, blktoerase=0xFFFFFFFFul;
			destaddr = 0x400000*dstIndex;
			for (addr = destaddr; addr<destaddr+sizeof gSBL_Stage1_Image; addr+=1024)
			{
				uint32_t blockNum,pageNum;
				int32_t status_blk = Flash_offsetToBlkPage(gFlashHandle[CONFIG_FLASH_SBL], addr, &blockNum, &pageNum);
				if((status_blk == SystemP_SUCCESS)&&(blockNum!=blktoerase))
				{
					#ifndef DM_WD_DISABLE
					InternalWatchdog_Service();
					#endif
					blktoerase = blockNum;
					DebugP_log("NOR: erasing block %d\r\n", blktoerase);
					status = Flash_eraseBlk(gFlashHandle[CONFIG_FLASH_SBL], blktoerase);
					if (status != SystemP_SUCCESS)
					{
						DebugP_logError("NOR: erasing block %d failed !!!\r\n", blktoerase);
						break;
					}
				}
			}
			if (status == SystemP_SUCCESS)
			{
				#ifndef DM_WD_DISABLE
				InternalWatchdog_Service();
				#endif
				DebugP_log("NOR: writing S1%c\r\n", SymbS1[dstIndex]);
				if (SystemP_SUCCESS!=Flash_write(gFlashHandle[CONFIG_FLASH_SBL], 0x400000*dstIndex, gSBL_Stage1_Image, sizeof gSBL_Stage1_Image))
				{
					DebugP_logError("NOR: writing failed !!!\r\n");
				}
				#ifndef DM_WD_DISABLE
				InternalWatchdog_Service();
				#endif
			}
		}
		else
		{
			DebugP_logError("NOR: checksum for S1%c is wrong !!!\r\n",SymbS1[srcIndex]);
		}
	}
	else
	{
		DebugP_logError("NOR: error reading S1%c !!!\r\n",SymbS1[srcIndex]);
	}
}


/*
 * Function: sbl_stageOne_check
 * ----------------------------------
 * Checks the condition of SBL stage 1
 *
 * Returns:
 *  SystemP_SUCCESS on success
 *  SystemP_FAILURE otherwise.
 */
static int32_t sbl_stageOne_check(void)
{
    int32_t status = SystemP_SUCCESS;

    /* Read xSPI Boot parameter table for Read Index
    (0 - Load and Boot from 0x0 offset )
    (1 - Load and Boot from 0x400000 offset ) */
	uint32_t bootIndex = ReadActiveBootIndex();
	if (bootIndex<=1) // check for valid index
	{
		if( bootIndex == 1 )
		{
			DebugP_logError("NOR: OSPI stage 1A corrupted !!!\r\n");
			DLT_LogMessage(DLT_LOG_WARN, 0xF938, NULL, 0, "NOR: OSPI stage 1A corrupted");
			CopyS1Image(1,0);
		}
		else if(isStage1_OK(1) != SystemP_SUCCESS)
		{
			DebugP_logError("NOR: OSPI stage 1B corrupted !!!\r\n");
			DLT_LogMessage(DLT_LOG_WARN, 0xF938, NULL, 0, "NOR: OSPI stage 1B corrupted");
			CopyS1Image(0,1);
		}
	}
	else
	{  // unknown index, verify both copies
		DebugP_logError("NOR: OSPI stage 1 boot index unknown, please verify boot parameter table version!!!!!!\r\n");
		DLT_LogMessage(DLT_LOG_WARN, 0xF938, NULL, 0, "Stage 1 boot index unknown!");
		int32_t S1A_OK = isStage1_OK(0);
		int32_t S1B_OK = isStage1_OK(1);
		if (S1A_OK != S1B_OK)
		{
			// we know how to restore
			if (S1A_OK == SystemP_SUCCESS)
			{
				CopyS1Image(0,1);
			}
			else
			{
				CopyS1Image(1,0);
			}
		}
	}
    return status;
}

/*
 * Function: AppNorLoader_driversOpen
 * ----------------------------------
 * Initializes and opens the OSPI and Flash drivers used for NOR flash loading.
 *
 * Returns:
 *  SystemP_SUCCESS on successful initialization,
 *  SystemP_FAILURE otherwise.
 */
static int32_t AppNorLoader_driversOpen()
{
    int32_t status = SystemP_SUCCESS;

    gOspiHandle[CONFIG_OSPI_SBL] = NULL;

    gOspiHandle[CONFIG_OSPI_SBL] = OSPI_open(CONFIG_OSPI_SBL, &gOspiParams[CONFIG_OSPI_SBL]);
    if(NULL == gOspiHandle[CONFIG_OSPI_SBL])
    {
        DebugP_logError("NOR: OSPI open failed for instance %d !!!\r\n", CONFIG_OSPI_SBL);
        status = SystemP_FAILURE;
		DLT_LogMessage(DLT_LOG_FATAL, 0xF938, NULL, 0, "S2 NOR: OSPI open failed");
    }

    if(SystemP_SUCCESS == status)
    {
        gFlashConfig[CONFIG_FLASH_SBL].attrs->driverInstance = CONFIG_OSPI_SBL;

        gFlashHandle[CONFIG_FLASH_SBL] = Flash_open(CONFIG_FLASH_SBL, &gFlashParams[CONFIG_FLASH_SBL]);
        if(NULL == gFlashHandle[CONFIG_FLASH_SBL])
        {
            DebugP_logError("NOR: FLASH open failed for instance %d !!!\r\n", CONFIG_FLASH_SBL);
			DLT_LogMessage(DLT_LOG_FATAL, 0xF938, NULL, 0, "S2 NOR: Flash_open failed");
            status = SystemP_FAILURE;
        }
    }
    else
    {
        OSPI_close(gOspiHandle[CONFIG_OSPI_SBL]);
        gOspiHandle[CONFIG_OSPI_SBL] = NULL;        
    }

    return status;
}

/*
 * Function: AppNorLoader_driversClose
 * -----------------------------------
 * Closes and cleans up the previously opened Flash and OSPI driver handles
 * used for NOR flash access.
 */
static void AppNorLoader_driversClose()
{
    Flash_close(gFlashHandle[CONFIG_FLASH_SBL]);
    gFlashHandle[CONFIG_FLASH_SBL] = NULL;

    OSPI_close(gOspiHandle[CONFIG_OSPI_SBL]);
    gOspiHandle[CONFIG_OSPI_SBL] = NULL;
}

/**
 * @brief Load and run CPUs from a NOR-based appimage for HSM and MCU cores.
 *
 * This function parses the multicore appimage stored in NOR flash and attempts to load
 * and run supported cores (e.g., HSM  and MCU). If any step fails, the CPU is powered off.
 *
 * @param bootLoadParams Pointer to bootloader load parameters (handle, image info, etc.)
 * @return int32_t SystemP_SUCCESS if successful, otherwise SystemP_FAILURE.
 */
int32_t App_loadAndRunImages_Nor(Bootloader_LoadImageParams *bootLoadParams)
{
    int32_t status = SystemP_FAILURE;
    Bootloader_Config *bootConfig;

    if(bootLoadParams->bootHandle != NULL)
    {
        bootConfig = (Bootloader_Config *)bootLoadParams->bootHandle;
        bootConfig->coresPresentMap = 0;
        status = Bootloader_parseMultiCoreAppImage(bootLoadParams->bootHandle, &bootLoadParams->bootImageInfo);

        /* Load CPUs */
        if((status == SystemP_SUCCESS) && TRUE == Bootloader_isCorePresent(bootLoadParams->bootHandle, CSL_CORE_ID_HSM_M4FSS0_0))
        {
            (&bootLoadParams->bootImageInfo)->cpuInfo[CSL_CORE_ID_HSM_M4FSS0_0].clkHz = Bootloader_socCpuGetClkDefault(CSL_CORE_ID_HSM_M4FSS0_0);
            Bootloader_profileAddCore(CSL_CORE_ID_HSM_M4FSS0_0);
            status = Bootloader_loadCpu(bootLoadParams->bootHandle, &((&bootLoadParams->bootImageInfo)->cpuInfo[CSL_CORE_ID_HSM_M4FSS0_0]));
            if(status == SystemP_SUCCESS)
            {
                status += Bootloader_runCpu(bootLoadParams->bootHandle, &((&bootLoadParams->bootImageInfo)->cpuInfo[CSL_CORE_ID_HSM_M4FSS0_0]));
            }

            BOOT_KPI_LOG(KPI_ID_SBL_S2_HSM_CORE_START,"HSM Core Start");

            if(status == SystemP_FAILURE)
            {
                Bootloader_powerOffCpu(bootLoadParams->bootHandle, &((&bootLoadParams->bootImageInfo)->cpuInfo[CSL_CORE_ID_HSM_M4FSS0_0]));
            }
            Bootloader_close(bootLoadParams->bootHandle);

        }

        if((status == SystemP_SUCCESS) && Bootloader_isCorePresent(bootLoadParams->bootHandle, CSL_CORE_ID_MCU_R5FSS0_0))
        {
            if (!Bootloader_socIsMCUResetIsoEnabled())
            {
                (&bootLoadParams->bootImageInfo)->cpuInfo[CSL_CORE_ID_MCU_R5FSS0_0].clkHz = Bootloader_socCpuGetClkDefault(CSL_CORE_ID_MCU_R5FSS0_0);
                Bootloader_profileAddCore(CSL_CORE_ID_MCU_R5FSS0_0);
                status = Bootloader_loadCpu(bootLoadParams->bootHandle, &((&bootLoadParams->bootImageInfo)->cpuInfo[CSL_CORE_ID_MCU_R5FSS0_0]));
                if(status == SystemP_SUCCESS)
                {

                    status += Bootloader_runCpu(bootLoadParams->bootHandle, &((&bootLoadParams->bootImageInfo)->cpuInfo[CSL_CORE_ID_MCU_R5FSS0_0]));
                }

                BOOT_KPI_LOG(KPI_ID_SBL_S2_MCU_CORE_START,"MCU Core Start");

                if(status == SystemP_FAILURE)
                {
                    Bootloader_powerOffCpu(bootLoadParams->bootHandle, &((&bootLoadParams->bootImageInfo)->cpuInfo[CSL_CORE_ID_MCU_R5FSS0_0]));
                }
                Bootloader_close(bootLoadParams->bootHandle);

            }
        }
    }
    return status;
}

/**
 * @brief Bootloader function to load and run an image from NOR flash.
 *
 * This function initializes bootloader parameters, opens the bootloader instance for the given index,
 * assigns the correct application image to the bootloader handle based on the instance type (HSM or MCU),
 * and calls the function to load and run images from NOR flash.
 *
 * @param inst  Index of the bootloader instance (e.g., MCU_A, HSM_B, etc.)
 * @return int32_t Returns SystemP_SUCCESS on success, or SystemP_FAILURE on error.
 */
int32_t AppLoader_BootImage_Nor(uint8_t inst)
{
    
    int32_t status = SystemP_FAILURE;
    Bootloader_openDma();
    
    Bootloader_Params_init(&gbootArray[inst].bootParams);
    Bootloader_BootImageInfo_init(&gbootArray[inst].bootImageInfo);
    gbootArray[inst].bootHandle = Bootloader_open(inst, &gbootArray[inst].bootParams);
    if(gbootArray[inst].bootHandle != NULL)
    {
	    if(CONFIG_BOOTLOADER_HSM_A == inst || CONFIG_BOOTLOADER_HSM_B == inst || CONFIG_BOOTLOADER_HSM_RECOVERY_A == inst || CONFIG_BOOTLOADER_HSM_RECOVERY_B == inst)
	    {
		    ((Bootloader_Config *)gbootArray[inst].bootHandle)->scratchMemPtr = gHsmAppimage;
	    }
	    else if(CONFIG_BOOTLOADER_MCU_A == inst || CONFIG_BOOTLOADER_MCU_B == inst || CONFIG_BOOTLOADER_MCU_RECOVERY_A == inst || CONFIG_BOOTLOADER_MCU_RECOVERY_B == inst)
	    {
		    ((Bootloader_Config *)gbootArray[inst].bootHandle)->scratchMemPtr = gMcuAppimage;
	    }
	    status = App_loadAndRunImages_Nor(&gbootArray[inst]);
    }
    Bootloader_closeDma();

	#ifndef DM_WD_DISABLE
	InternalWatchdog_Service();
	#endif

    return status;
}

/**
 * @brief Main function to load and run HSM and MCU images from NOR flash based on boot mode and bank selection.
 *
 * This function initializes the necessary drivers, reads metadata to determine the active boot path,
 * selects the appropriate image to boot (Primary A/B or Recovery A/B), and handles error cases including
 * recovery boot and system reboot.
 */
static void AppNorLoader_LoadAndRunImagesFromNor(void)
{
    int32_t status = SystemP_FAILURE;
    
    status = AppNorLoader_driversOpen();
    
    if(status == SystemP_FAILURE)
    {
    	DebugP_logError("S2 AppNorLoader_driversOpen  :Failed status %d \r\n", status);
    }

    status = sbl_stageOne_check();
    if(SystemP_SUCCESS != status)
    {
        DebugP_log("sbl_stageOne_check failed status = 0x%x\r\n", status);
    }

    #if defined(ENABLE_AB) || defined(ENABLE_RECOVERY)
    status = loadMetadata();
    if(status != SystemP_SUCCESS)
    {
        DebugP_logError("Unable to load metadata \r\n");
        DLT_LogMessage(DLT_LOG_FATAL, 0xF938, NULL, 0, "S2 Unable to load metadata");
    }
    #endif
    #ifdef ENABLE_AB
    uint32_t active_bank = getActiveBank();
    #endif
    #ifdef ENABLE_RECOVERY
    uint32_t mode = getBootMode();
    #endif

	#ifndef DM_WD_DISABLE
	InternalWatchdog_Service();
	#endif

#ifdef ENABLE_HSM    // LOAD And RUN HSM Image
    #ifdef ENABLE_RECOVERY
    if(mode == BOOT_PRIMARY)
    #endif
    {
        #ifdef ENABLE_AB
        if(BANK_A == active_bank)
        {
			DLT_LogMessage(DLT_LOG_INFO, 0xF938, NULL, 0, "S2 HSM Booting Primary A");
			status = AppLoader_BootImage_Nor(CONFIG_BOOTLOADER_HSM_A);
            if(status == SystemP_FAILURE)
            {
            	DebugP_logError("S2 HSM : Booting Primary A : Fail Status %d \r\n", status);
				DLT_LogMessage(DLT_LOG_FATAL, 0xF938, NULL, 0, "S2 HSM Primary A Fail");
            }
        }
        else if(BANK_B == active_bank)
        {
            DebugP_log("S2 HSM : Booting Primary B\r\n");
			DLT_LogMessage(DLT_LOG_INFO, 0xF938, NULL, 0, "S2 HSM Booting Primary B");
			status = AppLoader_BootImage_Nor(CONFIG_BOOTLOADER_HSM_B);
            if(status == SystemP_FAILURE)
            {
            	DebugP_logError("S2 HSM : Booting Primary B : Fail Status %d \r\n", status);
				DLT_LogMessage(DLT_LOG_FATAL, 0xF938, NULL, 0, "S2 HSM Primary B Fail");
            }
        }
        else
        {
            status = SystemP_FAILURE;
        }
        #else
        status = AppLoader_BootImage_Nor(CONFIG_BOOTLOADER_HSM_A);
        if(status == SystemP_FAILURE)
        {
            DebugP_logError("S2 HSM : Booting Primary A : Fail Status %d \r\n", status);
            DLT_LogMessage(DLT_LOG_FATAL, 0xF938, NULL, 0, "S2 HSM Primary A Fail");
        }
        #endif
    }
    #ifdef ENABLE_RECOVERY
    else
    {
    	DebugP_log("S2 : HSM R_A \r\n");
		DLT_LogMessage(DLT_LOG_INFO, 0xF938, NULL, 0, "S2 HSM Booting Recovery A");
        status = AppLoader_BootImage_Nor(CONFIG_BOOTLOADER_HSM_RECOVERY_A);
        if(status == SystemP_FAILURE)
        {
            DebugP_logError("S2 HSM : Booting Recovery A : Fail Status %d \r\n", status);
			DLT_LogMessage(DLT_LOG_ERROR, 0xF938, NULL, 0, "S2 HSM Recovery A Fail");
        }

        if(SystemP_SUCCESS != status)
        {
            DebugP_log("S2 : HSM R_B \r\n");
			DLT_LogMessage(DLT_LOG_INFO, 0xF938, NULL, 0, "S2 HSM Booting Recovery B");
            status = AppLoader_BootImage_Nor(CONFIG_BOOTLOADER_HSM_RECOVERY_B);
            if(status == SystemP_FAILURE)
            {
            	DebugP_logError("S2 HSM : Booting Recovery B : Fail Status %d \r\n", status);
				DLT_LogMessage(DLT_LOG_FATAL, 0xF938, NULL, 0, "S2 HSM Recovery B Fail");
            }
        }
    }
    #endif

    if(status == SystemP_SUCCESS)
    {
        #ifdef ENABLE_PROFILING
        DebugP_log("!!!!!!!! HSM Booted Successfully !!!!!!!!\r\n");
        #endif
    }
    else
    {
        DebugP_logError("S2 HSM : HSM Primary Chain failed\r\n");
        DebugP_logError("Enter into Recovery Mode\r\n");
        DebugP_logError("Rebooting.....\r\n");

        UART_flushTxFifo(gUartHandle[CONFIG_UART_SBL]);

        /* Boot into recovery */
        #ifdef ENABLE_RECOVERY
        status = setBootMode(BOOT_RECOVERY);
        #endif
        Bootloader_closeDma();
        OSPI_norFlashSWReset(gOspiHandle[CONFIG_OSPI_SBL]); /* Do SW Warm reset to OSPI before Reboot */
        AppNorLoader_driversClose();
        board_reboot();
    }
#endif

	#ifndef DM_WD_DISABLE
	InternalWatchdog_Service();
	#endif
    
#ifdef ENABLE_VIP    // LOAD And RUN MCU Image
    #ifdef ENABLE_RECOVERY
    if(mode == BOOT_PRIMARY)
    #endif
    {
        #ifdef ENABLE_AB
        if(BANK_A == active_bank)
        {
			DLT_LogMessage(DLT_LOG_INFO, 0xF938, NULL, 0, "S2 MCU Booting Primary A");
            status = AppLoader_BootImage_Nor(CONFIG_BOOTLOADER_MCU_A);
            if(status == SystemP_FAILURE)
            {
            	DebugP_logError("S2 MCU : Booting Primary A : Fail Status %d \r\n", status);
				DLT_LogMessage(DLT_LOG_FATAL, 0xF938, NULL, 0, "S2 MCU Primary A Fail");
            }
        }
        else if(BANK_B == active_bank)
        {
			DLT_LogMessage(DLT_LOG_INFO, 0xF938, NULL, 0, "S2 MCU Booting Primary B");
            status = AppLoader_BootImage_Nor(CONFIG_BOOTLOADER_MCU_B);
            if(status == SystemP_FAILURE)
            {
            	DebugP_logError("S2 MCU : Booting Primary B : Fail Status %d \r\n", status);
				DLT_LogMessage(DLT_LOG_FATAL, 0xF938, NULL, 0, "S2 MCU Primary B Fail");
            }
        }
        else
        {
            status = SystemP_FAILURE;
        }
        #else
        DLT_LogMessage(DLT_LOG_INFO, 0xF938, NULL, 0, "S2 MCU Booting Primary A");
        status = AppLoader_BootImage_Nor(CONFIG_BOOTLOADER_MCU_A);
        if(status == SystemP_FAILURE)
        {
            DebugP_logError("S2 MCU : Booting Primary A : Fail Status %d \r\n", status);
            DLT_LogMessage(DLT_LOG_FATAL, 0xF938, NULL, 0, "S2 MCU Primary A Fail");
        }
        #endif
    }
    #ifdef ENABLE_RECOVERY
    else
    {
    	DebugP_log("S2 : BL R_A \r\n");
		DLT_LogMessage(DLT_LOG_INFO, 0xF938, NULL, 0, "S2 MCU Booting Recovery A");
        status = AppLoader_BootImage_Nor(CONFIG_BOOTLOADER_MCU_RECOVERY_A);
        if(status == SystemP_FAILURE)
        {
            DebugP_logError("S2 MCU : Booting Recovery A : Fail Status %d \r\n", status);
			DLT_LogMessage(DLT_LOG_ERROR, 0xF938, NULL, 0, "S2 MCU Recovery A Fail");
        }

        if(SystemP_SUCCESS != status)
        {
            DebugP_log("S2 : BL R_B \r\n");
			DLT_LogMessage(DLT_LOG_INFO, 0xF938, NULL, 0, "S2 MCU Booting Recovery B");
            status = AppLoader_BootImage_Nor(CONFIG_BOOTLOADER_MCU_RECOVERY_B);
            if(status == SystemP_FAILURE)
            {
            	DebugP_logError("S2 MCU : Booting Recovery B : Fail Status %d \r\n", status);
				DLT_LogMessage(DLT_LOG_FATAL, 0xF938, NULL, 0, "S2 MCU Recovery B Fail");
            }
        }
    }
    #endif

    if(status == SystemP_SUCCESS)
    {
        #ifdef ENABLE_PROFILING
        DebugP_log("!!!!!!!! MCU Booted Successfully !!!!!!!!\r\n");
        #endif
		DLT_LogMessage(DLT_LOG_INFO, 0xF938, NULL, 0, "S2 MCU Booting Success");
		NORReady=1;
    }
    else
    {
        /* Boot into recovery */
        #ifdef ENABLE_RECOVERY
        status = setBootMode(BOOT_RECOVERY);
        #endif
        Bootloader_closeDma();
        OSPI_norFlashSWReset(gOspiHandle[CONFIG_OSPI_SBL]); /* Do SW Warm reset to OSPI before Reboot */
        AppNorLoader_driversClose();
        board_reboot();
    }
	
	#ifndef DM_WD_DISABLE
	InternalWatchdog_Service();	
	#endif
    
    /* TODO : Commented since eMMC task error condition not able update in Metadata region (NOR) */
    // AppNorLoader_driversClose();
#endif
}

#ifdef KPI_GPIO
static Pinmux_PerCfg_t gPinMuxMainCfg[] = {
    {
        KPI_STAGE2_NOR_GPIO_PIN_NAME,
                PIN_MODE(7) | ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END, PINMUX_END}
};
#endif

void sbl_nor_loader_stage2_main(void * args)
{

    #ifdef KPI_GPIO
    Pinmux_config(gPinMuxMainCfg, PINMUX_DOMAIN_ID_MAIN);
    GPIO_setDirMode(KPI_STAGE2_NOR_GPIO_BASE, KPI_STAGE2_NOR_GPIO_PINNUM, GPIO_DIRECTION_OUTPUT);
    GPIO_pinWriteHigh(KPI_STAGE2_NOR_GPIO_BASE, KPI_STAGE2_NOR_GPIO_PINNUM);
    #endif

    int32_t status = SystemP_FAILURE;

    status = Bootloader_socIsSBLBoot();
	
	if(status  == SystemP_SUCCESS)
    {
        #ifdef ENABLE_PROFILING
        Bootloader_profileAddProfilePoint("NOR LOADER THREAD");
        #endif
        AppNorLoader_LoadAndRunImagesFromNor();
    }

    if (args==(void*)1) // if it is a thread
		vTaskDelete(NULL);
}
