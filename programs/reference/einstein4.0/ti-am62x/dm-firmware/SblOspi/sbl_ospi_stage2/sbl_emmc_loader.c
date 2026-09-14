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
#include <stdint.h>
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
#include "smoldtb.h"
#ifdef KPI_GPIO
#include <drivers/gpio.h>
#include <drivers/pinmux.h>
#endif
#include "boot_kpi_r5_dm.h"
#include "dlt.h"
extern uint8_t eMMCReady;
#ifndef DM_WD_DISABLE
void InternalWatchdog_Service(void);
#endif


/* This start address and length depends upon the linker memory for second stage SBL.
 * It is necessary to change the below start address and length if in case the linker
 * memory region for second stage SBL is changed.
 */

#define BOOTLOADER_SECOND_STAGE_RESERVED_MEMORY_START       0x9CA00000
#define BOOTLOADER_SECOND_STAGE_RESERVED_MEMORY_LENGTH      0x1D00000

SemaphoreP_Object eMMC_sem;

/* This buffer needs to be defined for OSPI NOR boot in case of HS device for
 * image authentication.
 * The size of the buffer should be large enough to accomodate the appimage
 */
static uint8_t gGipAppimage[0x1E00000] __attribute__ ((section (".app_emmc_gip"), aligned (128)));
static uint8_t gLinuxBootInstance = CONFIG_BOOTLOADER_PRIMARY_LINUX_A;
#define CONFIG_MMCSD_SBL 0

/*  In this sample bootloader, we load appimages for RTOS/Baremetal and GIP at different offset
 *  i.e the appimage for GIP (for A53) and RTOS/Baremetal (for R5, MCU R5) is flashed at different offset in eMMC
 *
 *  Here at one flash offset, there is a multi-core .appimage that holds RPRC for MCU R5 and R5
 *  and another .appimage that holds the GIP binaries(ATF, OPTEE, A53-SPL) at another offset.
 *
 *  When flashing make sure to flash images to below offset using the flash tool.
 *
 *  RTOS/Baremetal appimage (for HSM) flash at offset 0x800000 of flash
 *  GIP appimage (for A53) flash at offset 0xC00000 of flash
 */

/* call this API to stop the booting process and spin, do that you can connect
 * debugger, load symbols and then make the 'loop' variable as 0 to continue execution
 * with debugger connected.
 */

/*
 * Function: AppEmmcLoader_driversOpen
 * -----------------------------------
 * Initializes and opens the MMCSD (eMMC) driver instance used by the bootloader.
 * Returns SystemP_SUCCESS if successful, or SystemP_FAILURE on failure.
 */
int32_t AppEmmcLoader_driversOpen()
{
    int32_t status = SystemP_SUCCESS;
    gMmcsdHandle[CONFIG_MMCSD_SBL] = NULL;

    gMmcsdHandle[CONFIG_MMCSD_SBL] = MMCSD_open(CONFIG_MMCSD_SBL, &gMmcsdParams[CONFIG_MMCSD_SBL]);
    if(NULL == gMmcsdHandle[CONFIG_MMCSD_SBL])
    {
        DebugP_logError("MMCSD open failed for instance !!!\r\n");
        status = SystemP_FAILURE;
    }

    return status;
}

/*
 * Function: AppEmmcLoader_driversClose
 * ------------------------------------
 * Closes and cleans up the MMCSD driver handle used for accessing the eMMC device.
 */
static void AppEmmcLoader_driversClose()
{
    SemaphoreP_pend(&eMMC_sem,SystemP_WAIT_FOREVER);
    MMCSD_close(gMmcsdHandle[CONFIG_MMCSD_SBL]);
    gMmcsdHandle[CONFIG_MMCSD_SBL] = NULL;
    SemaphoreP_post(&eMMC_sem);
}

/* Handle errors reported by the DTB parser. */
void dtb_on_error(const char* why)
{
    DebugP_logError("smol-dtb error: %s\r\n", why);
}

/* Allocate memory for the DTB parser and retain the pointer for cleanup. */
void* dtb_malloc(size_t length)
{
    return NULL;
}

/* Retrieve kernel boot parameters for the specified boot instance. */
const kernel_params_t *get_kernel_params(uint8_t boot_instance)
{
    for (size_t i = 0; i < sizeof(params_table) / sizeof(params_table[0]); i++)
    {
        if (params_table[i].boot_instance == boot_instance)
        {
            return &params_table[i];
        }
    }

    return NULL;
}

/* Function to patch the Device Tree Blob (DTB) loaded at address 0x82000000.
 * It locates the '/chosen/bootargs' property and writes a new Linux bootargs
 * string into it based on the current boot instance (A/B/Recovery).
 *
 * This is typically done to inform the Linux kernel about different boot
 * parameters depending on which image was selected by the bootloader.
 */
static int32_t AppEmmcLoader_PatchDtb(void)
{
    int32_t status = SystemP_SUCCESS;
    uintptr_t buffer = 0x82200000U;

    dtb_ops ops;

    ops.malloc = dtb_malloc;
    ops.on_error = dtb_on_error;

    char local_buf[1024];
    uint8_t kernel_param_idx = KERNEL_PARAM_INVALID;

    if (dtb_init(buffer, ops) == false)
    {
        DebugP_logError("S2 EMMC : DTB initialization failed\r\n");
        return SystemP_FAILURE;
    }

    dtb_node *node = dtb_find("/chosen");

    if (node == NULL)
    {
        DebugP_logError("S2 EMMC : Cannot find /chosen node\r\n");
        return SystemP_FAILURE;
    }

    dtb_prop *prop = dtb_find_prop(node, "bootargs");

    if (prop == NULL)
    {
        DebugP_logError("S2 EMMC : Cannot find prop bootargs\r\n");
        return SystemP_FAILURE;
    }

    const char *boot_args = dtb_read_prop_string(prop, 0);
    if (boot_args == NULL)
    {
        DebugP_logError("S2 EMMC : Cannot read bootargs\r\n");
        return SystemP_FAILURE;
    }

    #ifdef DEBUG_HEX_DUMP
        DebugP_log("HEX DUMP Before Updating: \r\n");
        for(uint32_t i = 0; i < strlen(boot_args); i++)
        {
            /* %02x prints the hex value. Look for '00' in the middle! */
            DebugP_log("%02x ", (uint8_t)boot_args[i]);
            if((i+1) % 16 == 0) DebugP_log("\r\n");
        }
    #endif
    size_t boot_args_len = strlen(boot_args);

    if (boot_args_len >= sizeof(local_buf))
    {
        DebugP_logError("S2 EMMC : bootargs too long\r\n");
        return SystemP_FAILURE;
    }

    memcpy(local_buf, boot_args, boot_args_len + 1U);

    if (gLinuxBootInstance == CONFIG_BOOTLOADER_PRIMARY_LINUX_A)
    {
        kernel_param_idx = KERNEL_PARAM_PRIMARY_A;
    }
    else if (gLinuxBootInstance == CONFIG_BOOTLOADER_PRIMARY_LINUX_B)
    {
        kernel_param_idx = KERNEL_PARAM_PRIMARY_B;
    }
    else if (gLinuxBootInstance == CONFIG_BOOTLOADER_RECOVERY_LINUX_A)
    {
        kernel_param_idx = KERNEL_PARAM_RECOVERY_A;
    }
    else if (gLinuxBootInstance == CONFIG_BOOTLOADER_RECOVERY_LINUX_B)
    {
        kernel_param_idx = KERNEL_PARAM_RECOVERY_B;
    }
    else
    {
        DebugP_logError("S2 EMMC : Invalid gLinuxBootInstance : %d\r\n", gLinuxBootInstance);

        DLT_LogMessage(DLT_LOG_FATAL, 0xF937, &gLinuxBootInstance, sizeof(gLinuxBootInstance), "Invalid gLinuxBootInstance");
        return SystemP_FAILURE;
    }

    const kernel_params_t *cfg = get_kernel_params(kernel_param_idx);

    if (cfg == NULL)
    {
        DebugP_logError("S2 EMMC : Invalid kernel parameter index %u\r\n", kernel_param_idx);
        return SystemP_FAILURE;
    }

    char *boot_mode = strstr(local_buf, "BOOT_MODE=");

    if (boot_mode != NULL)
    {
        memcpy(boot_mode + strlen("BOOT_MODE="), cfg->boot_mode, strlen(cfg->boot_mode));
    }

    uint32_t findPartitionNum = 0U;
    char *p = local_buf;

    while ((p = strstr(p, "/dev/mmcblk0p")) != NULL)
    {
        p += strlen("/dev/mmcblk0p");
        *p = cfg->partition_num;
        findPartitionNum++;
    }

    if (findPartitionNum == 0U)
    {
        DebugP_logError("S2 EMMC : Failed to parse MMC partition\r\n");
        return SystemP_FAILURE;
    }

    if (TRUE != dtb_write_prop_string(prop, local_buf, strlen(local_buf)))
    {
    DebugP_logError("S2 EMMC : Failed to write patched bootargs to DTB\r\n");
        return SystemP_FAILURE;
    }

    CacheP_wb((void *)buffer, 0x40000U, CacheP_TYPE_ALL);
    #ifdef DEBUG_HEX_DUMP
    dtb_node* node2 = dtb_find("/chosen");
    if (node2 != NULL)
    {
        dtb_prop* prop2 = dtb_find_prop(node2, "bootargs");
        char *boot_args2 = (char *) dtb_read_prop_string(prop2, 0);
        if (boot_args2)
    {
            DebugP_log("After PATCH - Length: %d, String: %s\r\n", strlen(boot_args2), boot_args2);
        }
        DebugP_log("HEX DUMP After Patch (First 128 bytes): \r\n");
        for(uint32_t i = 0; i < strlen(boot_args2); i++)
        {
            /* %02x prints the hex value. Look for '00' in the middle! */
            DebugP_log("%02x ", (uint8_t)boot_args2[i]);
            if((i+1) % 16 == 0) DebugP_log("\r\n");
        }
    }
    #endif
    return status;
}

/*
 * Function: AppNorLoader_driversClose_emmc
 * -----------------------------------
 * Closes and cleans up the previously opened Flash and OSPI driver handles
 * used for NOR flash access.
 */
static void AppNorLoader_driversClose_emmc()
{
    Flash_close(gFlashHandle[CONFIG_FLASH_SBL]);
    gFlashHandle[CONFIG_FLASH_SBL] = NULL;

    OSPI_close(gOspiHandle[CONFIG_OSPI_SBL]);
    gOspiHandle[CONFIG_OSPI_SBL] = NULL;
}

static void App_printBootloaderLogs_EMMC()
{

    /* Use CONFIG_UART_SBL (UART0) for SBL logs */
    DebugP_uartSetDrvIndex(CONFIG_UART_SBL);

    /* Print SBL log as Linux prints log to the same UART port */
    UART_flushTxFifo(gUartHandle[CONFIG_UART_SBL]);

    /* Restore CONFIG_UART_APP (WKUP_UART) for application logs */
    DebugP_uartSetDrvIndex(CONFIG_UART_APP);

    /* Deinitialise the flash and driver peripherial used by bootloader before starting other cores,
     * so that other systems can access and reinitialise it.
     */
    AppNorLoader_driversClose_emmc();
}

/*
 * Function to load and run the A53 core image from eMMC.
 * - Parses the multi-core appimage from eMMC.
 * - Patches the DTB with bootargs.
 * - Loads and runs the A53 core if present.
 * - Unlocks MMRs and enables clocks for MMCSD.
 * - Closes the bootloader handle at the end.
 */
int32_t App_loadAndRunImagesEmmc(Bootloader_LoadImageParams *bootLoadParams)
{
   int32_t status = SystemP_FAILURE;
    Bootloader_Config *bootConfig;

    if(bootLoadParams->bootHandle != NULL)
    {
        bootConfig = (Bootloader_Config *)bootLoadParams->bootHandle;
        bootConfig->coresPresentMap = 0;
        SemaphoreP_pend(&eMMC_sem,SystemP_WAIT_FOREVER);
        status = Bootloader_parseMultiCoreAppImage(bootLoadParams->bootHandle, &bootLoadParams->bootImageInfo);
        SemaphoreP_post(&eMMC_sem);

        if((SystemP_SUCCESS == status) && (TRUE == Bootloader_isCorePresent(bootLoadParams->bootHandle, CSL_CORE_ID_A53SS0_0)))
        {
        #ifndef DM_WD_DISABLE
        InternalWatchdog_Service();
        #endif
        #ifndef QNX_OS
        status = AppEmmcLoader_PatchDtb();
        if(status == SystemP_FAILURE)
        {
            DebugP_logError("S2 GIP : AppEmmcLoader_PatchDtb : Fail Status %d \r\n", status);
            DLT_LogMessage(DLT_LOG_FATAL, 0xF937, NULL, 0, "S2 PatchDtb failed");
        }
        #endif
            (&bootLoadParams->bootImageInfo)->cpuInfo[CSL_CORE_ID_A53SS0_0].clkHz = Bootloader_socCpuGetClkDefault(CSL_CORE_ID_A53SS0_0);
            Bootloader_profileAddCore(CSL_CORE_ID_A53SS0_0);
            SemaphoreP_pend(&eMMC_sem,SystemP_WAIT_FOREVER);
            status = Bootloader_loadCpu(bootLoadParams->bootHandle, &((&bootLoadParams->bootImageInfo)->cpuInfo[CSL_CORE_ID_A53SS0_0]));
            SemaphoreP_post(&eMMC_sem);

            if(status == SystemP_SUCCESS)
            {
        AppEmmcLoader_driversClose();
                SOC_moduleClockEnable(TISCI_DEV_MMCSD0, 0);
        App_printBootloaderLogs_EMMC();
        /* Unlock all the control MMRs. Linux/U-boot expects all the MMRs to be unlocked */
                SOC_unlockAllMMR();

                status += Bootloader_runCpu(bootLoadParams->bootHandle, &((&bootLoadParams->bootImageInfo)->cpuInfo[CSL_CORE_ID_A53SS0_0]));
            }

            BOOT_KPI_LOG(KPI_ID_SBL_S2_GIP_CORE_START,"GIP Core Start");

            if(status == SystemP_FAILURE)
            {
                Bootloader_powerOffCpu(bootLoadParams->bootHandle, &((&bootLoadParams->bootImageInfo)->cpuInfo[CSL_CORE_ID_A53SS0_0]));
            }
            else
            {
                eMMCReady = 1;
            }
        }
    }
    Bootloader_close(bootLoadParams->bootHandle);

    return status;
}

/**
 * @brief Load and run Linux image from eMMC for the given bootloader instance.
 *
 * This function initializes bootloader parameters, opens the bootloader for the specified
 * instance (e.g., primary or recovery bank), sets the scratch memory pointer, and triggers
 * image loading and CPU execution.
 *
 * @param inst Bootloader instance (e.g., CONFIG_BOOTLOADER_PRIMARY_LINUX_A)
 * @return int32_t SystemP_SUCCESS if booting was successful, otherwise SystemP_FAILURE.
 */
int32_t AppLoader_BootImage_Emmc(uint8_t inst)
{
    int32_t status = SystemP_FAILURE;

    Bootloader_LoadImageParams bootLinux;
    Bootloader_Params_init(&bootLinux.bootParams);
    Bootloader_BootImageInfo_init(&bootLinux.bootImageInfo);
    bootLinux.bootHandle = Bootloader_open(inst, &bootLinux.bootParams);

    if(bootLinux.bootHandle != NULL)
    {
        if(CONFIG_BOOTLOADER_PRIMARY_LINUX_A == inst || CONFIG_BOOTLOADER_PRIMARY_LINUX_B == inst || CONFIG_BOOTLOADER_RECOVERY_LINUX_A == inst || CONFIG_BOOTLOADER_RECOVERY_LINUX_B == inst)
        {
            ((Bootloader_Config *)bootLinux.bootHandle)->scratchMemPtr = gGipAppimage;
            gLinuxBootInstance = inst;
        }
        status = App_loadAndRunImagesEmmc(&bootLinux);
    }
    return status;
}

/**
 * @brief Loads and runs the Linux image from eMMC based on active bank and boot mode.
 *
 * This function initializes drivers, handles metadata, selects the appropriate image
 * from either the primary or recovery partition in eMMC, and attempts to boot Linux.
 */
static void AppEmmcLoader_LoadAndRunImagesFromEmmc(void)
{
    int32_t status = SystemP_FAILURE;

    Bootloader_openDma();

    Bootloader_ReservedMemInit(BOOTLOADER_SECOND_STAGE_RESERVED_MEMORY_START, \
                                BOOTLOADER_SECOND_STAGE_RESERVED_MEMORY_LENGTH);

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
            status = AppLoader_BootImage_Emmc(CONFIG_BOOTLOADER_PRIMARY_LINUX_A);
            if(status == SystemP_FAILURE)
            {
                DebugP_logError("S2 GIP : Booting Primary A : Fail Status %d \r\n", status);
                 DLT_LogMessage(DLT_LOG_FATAL, 0xF937, NULL, 0, "S2 GIP:Boot Primary A fail");
            }
        }
        else if(BANK_B == active_bank)
        {
            status = AppLoader_BootImage_Emmc(CONFIG_BOOTLOADER_PRIMARY_LINUX_B);
            if(status == SystemP_FAILURE)
            {
                DebugP_logError("S2 GIP : Booting Primary B : Fail Status %d \r\n", status);
                 DLT_LogMessage(DLT_LOG_FATAL, 0xF937, NULL, 0, "S2 GIP:Boot Primary B fail");
            }
        }
        else
        {
            status = SystemP_FAILURE;
        }
        #else
        status = AppLoader_BootImage_Emmc(CONFIG_BOOTLOADER_PRIMARY_LINUX_A);
        if(status == SystemP_FAILURE)
        {
            DebugP_logError("S2 GIP : Booting Primary A : Fail Status %d \r\n", status);
            DLT_LogMessage(DLT_LOG_FATAL, 0xF937, NULL, 0, "S2 GIP:Boot Primary A fail");
        }
        #endif
    }
    #ifdef ENABLE_RECOVERY
    else
    {
        DebugP_log("S2 : GIP R_A \r\n");
        DLT_LogMessage(DLT_LOG_INFO, 0xF937, NULL, 0, "S2 Booting recovery A GP");
        status = AppLoader_BootImage_Emmc(CONFIG_BOOTLOADER_RECOVERY_LINUX_A);
        if(status == SystemP_FAILURE)
        {
            DebugP_logError("S2 GIP : Booting Recovery A : Fail Status %d \r\n", status);
               DLT_LogMessage(DLT_LOG_ERROR, 0xF937, NULL, 0, "S2 GIP:Boot Recovery A fail");
        }

        if(SystemP_SUCCESS != status)
        {
            DebugP_log("S2 : GIP R_B \r\n");
            DLT_LogMessage(DLT_LOG_INFO, 0xF937, NULL, 0, "S2 Booting recovery B  GP");
            status = AppLoader_BootImage_Emmc(CONFIG_BOOTLOADER_RECOVERY_LINUX_B);
            if(status == SystemP_FAILURE)
            {
                DebugP_logError("S2 GIP : Booting Recovery B : Fail Status %d \r\n", status);
                 DLT_LogMessage(DLT_LOG_FATAL, 0xF937, NULL, 0, "S2 GIP:Boot Recovery B fail");
            }
        }
    }
    #endif

    #ifndef DM_WD_DISABLE
    InternalWatchdog_Service();
    #endif
    if(status == SystemP_SUCCESS)
    {
        #ifdef ENABLE_PROFILING
        DebugP_log("!!!!!!!! Linux Booted Successfully !!!!!!!!\r\n");
        DLT_LogMessage(DLT_LOG_INFO, 0xF937, NULL, 0, "S2 GP Booted Successfully");
        UART_flushTxFifo(gUartHandle[CONFIG_UART_SBL]);
        DebugP_uartSetDrvIndex(CONFIG_UART_APP);
        #endif
    }
    else
    {
        DebugP_logError("S2 EMMC : Linux Primary Chain failed\r\n");
        DebugP_logError("Enter into Recovery Mode\r\n");
        DebugP_logError("Rebooting.....\r\n");
        DLT_LogMessage(DLT_LOG_FATAL, 0xF937, NULL, 0, "S2 Enter into Recovery Mode");

        UART_flushTxFifo(gUartHandle[CONFIG_UART_SBL]);

        /* Boot into recovery */
        #ifdef ENABLE_RECOVERY
        status = setBootMode(BOOT_RECOVERY);
        #endif
        Bootloader_closeDma();
        OSPI_norFlashSWReset(gOspiHandle[CONFIG_OSPI_SBL]); /* Do SW Warm reset to OSPI before Reboot */
        AppEmmcLoader_driversClose();
        AppNorLoader_driversClose_emmc();
        board_reboot();
    }
    Bootloader_closeDma();
}

#ifdef KPI_GPIO
static Pinmux_PerCfg_t gPinMuxMainCfg[] = {
    {
        KPI_STAGE2_EMMC_GPIO_PIN_NAME,
                PIN_MODE(7) | ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END, PINMUX_END}
};
#endif

void sbl_emmc_loader_stage2_main(void * args)
{
    int32_t status = SystemP_FAILURE;
    #ifdef KPI_GPIO
    Pinmux_config(gPinMuxMainCfg, PINMUX_DOMAIN_ID_MAIN);
    GPIO_setDirMode(KPI_STAGE2_EMMC_GPIO_BASE, KPI_STAGE2_EMMC_GPIO_PINNUM, GPIO_DIRECTION_OUTPUT);
    GPIO_pinWriteHigh(KPI_STAGE2_EMMC_GPIO_BASE, KPI_STAGE2_EMMC_GPIO_PINNUM);
    #endif

    #ifdef ENABLE_PROFILING
    Bootloader_profileAddProfilePoint("eMMC LOADER THREAD");
    #endif
    #if defined(ENABLE_AB) || defined(ENABLE_RECOVERY)
    while(FALSE == isMetadataAvaiable())
    {
        DebugP_logError("META DATA NOT AVAILABLE\r\n");
    }
    #endif
    #ifndef DM_WD_DISABLE
    InternalWatchdog_Service();
    #endif

    SemaphoreP_pend(&eMMC_sem,SystemP_WAIT_FOREVER);
    if (gMmcsdHandle[CONFIG_MMCSD_SBL] == NULL)
    {
        EmmcDriverOpen();
    }
    SemaphoreP_post(&eMMC_sem);
    if(gMmcsdHandle[CONFIG_MMCSD_SBL] != NULL)
    {
        #ifdef ENABLE_PROFILING
        Bootloader_profileAddProfilePoint("AppEmmcLoader_driversOpen");
        #endif
        AppEmmcLoader_LoadAndRunImagesFromEmmc();
    }
    else
    {
        DebugP_logError("S2 AppEmmcLoader_driversOpen  :Failed status %d \r\n", status);
        DLT_LogMessage(DLT_LOG_FATAL, 0xF937, NULL, 0, "Could not open eMMC driver");
    }
    if (args==(void*)1) // if it is a thread
        vTaskDelete(NULL);
}
