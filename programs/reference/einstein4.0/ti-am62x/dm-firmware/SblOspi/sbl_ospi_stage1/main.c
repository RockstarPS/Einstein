/*
 *  Copyright (C) 2023 Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include "ti_drivers_config.h"
#include "ti_drivers_open_close.h"
#include "ti_board_open_close.h"
#include <drivers/device_manager/sciclient.h>
#include <drivers/bootloader.h>
#include <drivers/pinmux.h>
#include <drivers/gtc.h>
#include <drivers/gtc/v0/cslr_gtc.h>
#include <sdl/include/sdl_types.h>
#include <sdl/dpl/sdl_dpl.h>
#include <sdl/sdl_pbist.h>
#include <sdl/sdl_lbist.h>
#include "program_cfg.h"
#include "sbl_utils.h"
#include "boot_kpi_r5_dm.h"
#include "wd.h"
#ifdef KPI_GPIO    /*  Include GPIO header files for KPI Integration only if KPI_GPIO is defined */
#include <drivers/gpio.h>
#endif

/*  In this sample bootloader, we load appimages for RTOS/Baremetal and Linux at different offset
    i.e the appimage for Linux (for A53) and RTOS/Baremetal (for R5, MCU R5) is flashed at different offset in flash

    Here at one flash offset, there is a multi-core .appimage that holds RPRC for MCU R5 and R5
    and another .appimage that holds the linux binaries(ATF, OPTEE, A53-SPL) at another offset.

    When flashing make sure to flash images to below offset using the flash tool.

    RTOS/Baremetal appimage (MCU R5 cores) flash at offset 0x100000 of flash
    Linux appimage (for A53) flash at offset 0xC00000 of flash
*/

/*
 * Timeout for the PBIST/LBIST completion
 */
#define SDL_BIST_MAX_TIMEOUT_VALUE       (10000000u)

/* Enable/Disable MCU LBIST on SBL */
#define ENABLE_MCU_LBIST                 (0u)

/* This buffer needs to be defined for OSPI nand boot in case of HS device for
   image authentication
   The size of the buffer should be large enough to accomodate the appimage */
uint8_t gAppimage[0x800000] __attribute__ ((section (".bss.app"), aligned (128)));

/* call this API to stop the booting process and spin, do that you can connect
 * debugger, load symbols and then make the 'loop' variable as 0 to continue execution
 * with debugger connected.
 */
void loop_forever()
{
    volatile uint32_t loop = 1;
    while(loop)
        ;
}

static void closeAllDrivers(void)
{
    Bootloader_closeDma();
    Board_driversClose();
    Drivers_close();
    Dpl_deinit();
    Board_deinit();
    System_deinit();
    OSPI_norFlashSWReset(gOspiHandle[CONFIG_OSPI_SBL]); /* Do SW Warm reset to OSPI before Reboot */
    board_reboot();
}

/**
 * @brief   Load and start the current core (self) image from a multi-core application image.
 *
 * @param   bootLoadParams   Pointer to Bootloader_LoadImageParams structure, which contains
 *                           handles and image information.
 *
 * @return  SystemP_SUCCESS  if image parsing and loading succeeded,
 *          SystemP_FAILURE  otherwise.
 */
int32_t App_loadSelfcoreImage(Bootloader_LoadImageParams *bootLoadParams)
{
	int32_t status = SystemP_FAILURE;

    if(bootLoadParams->bootHandle != NULL)
    {
        status = Bootloader_parseMultiCoreAppImage(bootLoadParams->bootHandle, &bootLoadParams->bootImageInfo);

        if(status == SystemP_SUCCESS)
        {
            (&bootLoadParams->bootImageInfo)->cpuInfo[CSL_CORE_ID_WKUP_R5FSS0_0].clkHz = Bootloader_socCpuGetClkDefault(CSL_CORE_ID_WKUP_R5FSS0_0);
            Bootloader_profileAddCore(CSL_CORE_ID_WKUP_R5FSS0_0);
            status = Bootloader_loadSelfCpu(bootLoadParams->bootHandle, &((&bootLoadParams->bootImageInfo)->cpuInfo[CSL_CORE_ID_WKUP_R5FSS0_0]));
        }
    }

    return status;
}

/**
 * @brief   Open and initialize the board-level flash driver.
 *
 * This function opens the flash device defined by CONFIG_FLASH_SBL using
 * the parameters specified in gFlashParams[]. The handle is stored in gFlashHandle[].
 *
 * @return  SystemP_SUCCESS  if flash opened successfully,
 *          SystemP_FAILURE  otherwise.
 */
int32_t App_boardDriversOpen()
{
    int32_t status = SystemP_SUCCESS;

    gFlashHandle[CONFIG_FLASH_SBL] = Flash_open(CONFIG_FLASH_SBL, &gFlashParams[CONFIG_FLASH_SBL]);
    if(NULL == gFlashHandle[CONFIG_FLASH_SBL])
    {
        DebugP_logError("FLASH open failed for instance %d !!!\r\n", CONFIG_FLASH_SBL);
        status = SystemP_FAILURE;
    }

    return status;
}

/**
 * @brief   Opens essential peripheral drivers required by the bootloader.
 *
 * This function opens OSPI and UART drivers using their respective
 * configurations. Handles are stored in global arrays for later use.
 * Errors are logged if initialization fails.
 */
void App_driversOpen()
{
    gOspiHandle[CONFIG_OSPI_SBL] = OSPI_open(CONFIG_OSPI_SBL, &gOspiParams[CONFIG_OSPI_SBL]);
    if(NULL == gOspiHandle[CONFIG_OSPI_SBL])
    {
        DebugP_logError("OSPI open failed for instance %d !!!\r\n", CONFIG_OSPI_SBL);
    }

    gUartHandle[CONFIG_UART_SBL] = UART_open(CONFIG_UART_SBL, &gUartParams[CONFIG_UART_SBL]);
    if(NULL == gUartHandle[CONFIG_UART_SBL])
    {
        DebugP_logError("UART open failed for instance %d !!!\r\n", CONFIG_UART_SBL);
    }
}

int32_t App_waitForMcuPbist()
{
    int32_t status = SystemP_FAILURE;
    int32_t timeoutCount = 0;

    if (!Bootloader_socIsMCUResetIsoEnabled())
    {
        /* wait for the PBIST to be completed */
        while(timeoutCount < SDL_BIST_MAX_TIMEOUT_VALUE)
        {
            if(PBIST_DONE == SDL_SBL_PBIST_checkDone(SDL_PBIST_INST_MCU))
            {
                status = SystemP_SUCCESS;
                break;
            }
            timeoutCount++;
        }
    }
    else
    {
        status = SystemP_SUCCESS;
    }

    return status;
}


int32_t App_startMcuLbist()
{
    int32_t status = SystemP_FAILURE;

    /* Start LBIST if MCU reset isolation is not enabled */
    if (!Bootloader_socIsMCUResetIsoEnabled())
    {
        if (SDL_LBIST_selfTest(LBIST_MCU_R5F, SDL_LBIST_TEST) == SDL_PASS)
        {
            status = SystemP_SUCCESS;
        }
    }
    else
    {
        status = SystemP_SUCCESS;
    }
    return status;
}

int32_t App_waitForMcuLbist()
{
    int32_t status = SystemP_FAILURE;
    int32_t timeoutCount = 0;

    if (!Bootloader_socIsMCUResetIsoEnabled())
    {
        /* wait for the LBIST to be completed */
        while(timeoutCount < SDL_BIST_MAX_TIMEOUT_VALUE)
        {
            if(LBIST_DONE == SDL_LBIST_checkDone(LBIST_MCU_R5F))
            {
                status = SystemP_SUCCESS;
                break;
            }
            timeoutCount++;
        }

        if (status == SystemP_SUCCESS)
        {
            status = SDL_LBIST_selfTest(LBIST_MCU_R5F, SDL_LBIST_TEST_RELEASE);
            timeoutCount = 0;
            while(timeoutCount < SDL_BIST_MAX_TIMEOUT_VALUE)
            {
                if(LBIST_DONE == SDL_LBIST_checkDone(LBIST_MCU_R5F))
                {
                    status = SystemP_SUCCESS;
                    break;
                }
                timeoutCount++;
            }
        }
    }
    else
    {
        status = SystemP_SUCCESS;
    }

    return status;
}

/**
 * @brief Boots and loads the Stage 2 image from the specified bootloader instance.
 *
 * This function opens the bootloader for the specified boot media (given by `part`),
 * sets up the memory buffer for loading, loads the self-core image, and then closes
 * the bootloader handle. Used in multi-stage booting where the first stage bootloader
 * (SBL Stage 1) loads a second-stage image (SBL Stage 2).
 *
 * @param part Bootloader instance ID (e.g., CONFIG_BOOTLOADER_SBL_STAGE2_A).
 *
 * @return SystemP_SUCCESS on successful image load,
 *         SystemP_FAILURE otherwise.
 */
int32_t App_BootSBLStage2(int32_t part)
{
    int32_t status = SystemP_FAILURE;

    Bootloader_LoadImageParams bootDM;

    Bootloader_Params_init(&bootDM.bootParams);
    Bootloader_BootImageInfo_init(&bootDM.bootImageInfo);

    bootDM.bootHandle = Bootloader_open(part, &bootDM.bootParams);

    if(bootDM.bootHandle != NULL)
    {
        ((Bootloader_Config *)bootDM.bootHandle)->scratchMemPtr = gAppimage;

        #ifdef ENABLE_PROFILING
        Bootloader_profileAddProfilePoint("Loading SelfcoreImage...");
        #endif
        status = App_loadSelfcoreImage(&bootDM);
        if(SystemP_SUCCESS != status)
        {
            DebugP_logError("SBL stage 2 laoding failed!!\r\n");
        }

        #ifdef ENABLE_PROFILING
        Bootloader_profileAddProfilePoint("SelfcoreImage Load Done...");
        #endif

        #ifdef ENABLE_PROFILING
	    Bootloader_profileUpdateAppimageSize(Bootloader_getMulticoreImageSize(bootHandleDM));
        #endif 

         Bootloader_close(bootDM.bootHandle);
    }
    return status;
}


#ifdef KPI_GPIO
static Pinmux_PerCfg_t gPinMuxMainCfg[] = {
    {
        KPI_STAGE1_GPIO_PIN_NAME,
        PIN_MODE(7) | ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END, PINMUX_END}
};
#endif


static void ClearGTC(void)
{
    uint32_t value;

	// disable GTC
    value = HW_RD_REG32(CSL_WKUP_GTC0_GTC_CFG1_BASE+CSL_GTC_CFG1_CNTCR);
    HW_WR_REG32(CSL_WKUP_GTC0_GTC_CFG1_BASE+CSL_GTC_CFG1_CNTCR, value & (~(CSL_GTC_CFG1_CNTCR_EN_MASK | CSL_GTC_CFG1_CNTCR_HDBG_MASK)));

	// wait for disabled GTC
	while (HW_RD_REG32(CSL_WKUP_GTC0_GTC_CFG1_BASE+CSL_GTC_CFG1_CNTCR) & CSL_GTC_CFG1_CNTCR_EN_MASK);

	// clear GTC
	HW_WR_REG32(CSL_WKUP_GTC0_GTC_CFG1_BASE + CSL_GTC_CFG1_CNTCV_LO,0);
	HW_WR_REG32(CSL_WKUP_GTC0_GTC_CFG1_BASE + CSL_GTC_CFG1_CNTCV_HI,0);

	// reenable
    HW_WR_REG32(CSL_WKUP_GTC0_GTC_CFG1_BASE+CSL_GTC_CFG1_CNTCR, value);
}

int main()
{
    int32_t status;

    #ifdef KPI_GPIO
    Pinmux_config(gPinMuxMainCfg, PINMUX_DOMAIN_ID_MAIN);
    GPIO_setDirMode(KPI_STAGE1_GPIO_BASE, KPI_STAGE1_GPIO_PINNUM, GPIO_DIRECTION_OUTPUT);
    GPIO_pinWriteHigh(KPI_STAGE1_GPIO_BASE, KPI_STAGE1_GPIO_PINNUM);
    #endif

    Bootloader_profileReset();

    status = Bootloader_socWaitForFWBoot();
    DebugP_assertNoLog(status == SystemP_SUCCESS);


    System_init();
	ClearGTC();
	
	#ifndef DM_WD_DISABLE
	InternalWatchdog_Enable();
	#endif
    Module_clockSBLEnable();
    Module_clockSBLSetFrequency();

    BOOT_KPI_CLEAR();
    BOOT_KPI_LOG(KPI_ID_SBL_S1_START, "S1_START"); // log not possible before System_init()

    status = Bootloader_socOpenFirewalls();
    DebugP_assertNoLog(status == SystemP_SUCCESS);
    
    #ifdef ENABLE_PROFILING
    Bootloader_profileAddProfilePoint("System_init");
    #endif

    /* wait for PBIST completion */
    status = App_waitForMcuPbist();
    DebugP_assertNoLog(status == SystemP_SUCCESS);
    #ifdef ENABLE_PROFILING
    Bootloader_profileAddProfilePoint("App_waitForMcuPbist");
    #endif

    #if (ENABLE_MCU_LBIST == 1u)
    /* start MCU LBIST*/
    status = App_startMcuLbist();
    #endif
    Board_init();
    #ifdef ENABLE_PROFILING
    Bootloader_profileAddProfilePoint("Board_init");
    #endif
	
    Drivers_open();
    #ifdef ENABLE_PROFILING
    Bootloader_profileAddProfilePoint("Drivers_open");
    #endif
	
    App_driversOpen();
    #ifdef ENABLE_PROFILING
    Bootloader_profileAddProfilePoint("SBL Drivers_open");
    #endif

	#ifndef DM_WD_DISABLE
	InternalWatchdog_PrintResetStatus();
	#endif

    status = Board_driversOpen();
    DebugP_assert(status == SystemP_SUCCESS);
    #ifdef ENABLE_PROFILING
    Bootloader_profileAddProfilePoint("Board_driversOpen");
    #endif

    status = App_boardDriversOpen();
    DebugP_assert(status == SystemP_SUCCESS);
    #ifdef ENABLE_PROFILING
    Bootloader_profileAddProfilePoint("SBL Board_driversOpen");
    #endif

    if(SystemP_SUCCESS == status)
    {

        Bootloader_openDma();

		#ifdef RTI_WDT_TEST
		InternalWatchdog_Test();
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

        #ifdef ENABLE_RECOVERY
        if(mode == BOOT_PRIMARY)
        #endif
        {
            #ifdef ENABLE_AB
            if(BANK_A == active_bank)
            {
                status  = App_BootSBLStage2(CONFIG_BOOTLOADER_SBL_STAGE2_A);
                if(status == SystemP_FAILURE)
            	{
            	    DebugP_logError("S1 : Stage 2 Primary A : Fail Status %d \r\n", status);
            	}
            }
            else if(BANK_B == active_bank)
            {
                DebugP_log("S1 : Stage 2 P_B\r\n");
                status  = App_BootSBLStage2(CONFIG_BOOTLOADER_SBL_STAGE2_B);
                if(status == SystemP_FAILURE)
            	{
            	    DebugP_logError("S1 : Stage 2 Primary B : Fail Status : Fail Status %d \r\n", status);
            	}
            }
            else
            {
                DebugP_logError("S1 : Update Proper bank 0x%x \r\n", active_bank);
                status = SystemP_FAILURE;
            }

            if(status == SystemP_FAILURE)
            {
                DebugP_logError("S1 : Stage 2 Primary Chain failed\r\n");
                DebugP_logError("Enter into Recovery Mode\r\n");
        		DebugP_logError("Rebooting.....\r\n");

                UART_flushTxFifo(gUartHandle[CONFIG_UART_SBL]);

                /* Boot into recovery */
                status = setBootMode(BOOT_RECOVERY);
                if(status == SystemP_FAILURE)
                {
                    DebugP_logError("S1 : Error to set Boot Mode Fail Status %d \r\n", status);
                }
                closeAllDrivers();
            }
            #else
            status  = App_BootSBLStage2(CONFIG_BOOTLOADER_SBL_STAGE2_A);
            if(status == SystemP_FAILURE)
            {
                DebugP_logError("S1 : Stage 2 Primary A : Fail Status %d \r\n", status);
            }
            #endif
        }
        #ifdef ENABLE_RECOVERY
        else
        {
            DebugP_log("S1 : Stage 2 R_A\r\n");
            status  = App_BootSBLStage2(CONFIG_BOOTLOADER_SBL_STAGE2_RECOVERY_A);
            if(status == SystemP_FAILURE)
            {
                DebugP_logError("S1 : Stage 2 Recovery A : Fail Status : Fail Status %d \r\n", status);
            }

            if(status == SystemP_FAILURE)
            {
                DebugP_log("S1 : Stage 2 R_B\r\n");
                status  = App_BootSBLStage2(CONFIG_BOOTLOADER_SBL_STAGE2_RECOVERY_B);
                if(status == SystemP_FAILURE)
            	{
            	    DebugP_logError("S1 : Stage 2 Recovery B : Fail Status : Fail Status %d \r\n", status);
            	}
            }
        }
        #endif

        #ifdef ENABLE_PROFILING
        Bootloader_profileUpdateMediaAndClk(BOOTLOADER_MEDIA_FLASH, OSPI_getInputClk(gOspiHandle[CONFIG_OSPI_SBL]));
        #endif
		
        #if (ENABLE_MCU_LBIST == 1u)
        /* wait for LBIST completion */
        status = App_waitForMcuLbist();
        #ifdef ENABLE_PROFILING
        Bootloader_profileAddProfilePoint("App_waitForMcuLbist");
        #endif
        #endif

		#ifndef DM_WD_DISABLE
		InternalWatchdog_Service();
		#endif

	    if(SystemP_SUCCESS == status)
	    {      
		    /* Print SBL log as Linux prints log to the same UART port */
	        #ifdef ENABLE_PROFILING
		    Bootloader_profilePrintProfileLog();
		    DebugP_log("Image loading done, switching to application ...\r\n");
		    DebugP_log("Starting 2nd stage bootloader\r\n");
            #endif
	    }
    }

    if(status != SystemP_SUCCESS )
    {
        DebugP_logError("SBL stage 1 failed!!\r\n");
    }
	
    UART_flushTxFifo(gUartHandle[CONFIG_UART_SBL]);

    Bootloader_closeDma();
    Board_driversClose();
    Drivers_close();

    /* Call DPL deinit to close the tick timer and disable interrupts before jumping to Stage2*/
    Dpl_deinit();

    #ifdef KPI_GPIO
    GPIO_pinWriteLow(KPI_STAGE1_GPIO_BASE, KPI_STAGE1_GPIO_PINNUM);
    #endif
    Bootloader_socWriteSBLBootMagicNum();

	BOOT_KPI_LOG(KPI_ID_SBL_S1_END, "S1_END");
    Bootloader_JumpSelfCpu();

    Board_deinit();
    System_deinit();

    return 0;
}
