/**
 * HSM Demo Config file (version: )
 *
 * Copyright (C) 2022-2024 Texas Instruments Incorporated - http://www.ti.com/
 *
 * This software is licensed under the  standard terms and conditions in the
 * Texas Instruments  Incorporated Technology and Software Publicly Available
 * Software License Agreement, a copy of which is included in the software
 * download.
 *
 * NOTICE: This file is auto-generated based on version numbers passed in
 * Makefile. Never edit this file by hand.
 */

#ifndef CONFIG_H
#define CONFIG_H


#define CONFIG_SOC_LD_SCRIPT "hsm_demo.ld"

#define CONFIG_LNK_UMEM_BASE (0x00000000)
#define CONFIG_LNK_UMEM_LEN (0x0010000)
#define CONFIG_LNK_DMEM0_BASE (0x0010000)
#define CONFIG_LNK_DMEM0_LEN (0x0005000)
#define CONFIG_LNK_DMEM1_BASE (0x00015000)
#define CONFIG_LNK_DMEM1_LEN (0x0000FFE0)
#define CONFIG_LNK_BIN_LEN (0x1F800)
#define CONFIG_OSAL_NORTOS (1U)
#define CONFIG_UNIT_TESTS (1U)
#define CONFIG_SEC_PROXY_ROM_HANDOFF_TIMEOUT (0xFFFFFFFFU)
#define CONFIG_ADDR_REMAP_OFFSET_SECURITY (0x60000000U)
#define CONFIG_SECURITY_SA2UL_CRYPTO_UNITTEST (1U)
#define CONFIG_SECURITY_SA2UL_SEC_CTX (1U)
#define CONFIG_SECURITY_DMA_PKTDMA (1U)
#define CONFIG_SECURITY_FIREWALL (1U)
#define CONFIG_SECURITY_FW_ISC_INIT_DEVGRP (0x1U)
#define CONFIG_SECURITY_FIREWALL_DMSC_MEM_USER_PRIV_SEP (1U)
#define CONFIG_SECURITY (1U)
#define CONFIG_SECURITY_ROM_FW_DATA_ADDR (0x0006BC00U)
#define CONFIG_SECURITY_DMA (1U)
#define CONFIG_SOC_AM62PX (1U)

#define CONFIG_SECURITY_SA2UL_TRNG (1U)

#define CONFIG_SOC_FOLDER_STRING "am62px"


#define CONFIG_RAT (1U)
#define CONFIG_SEC_PROXY (1U)
#define CONFIG_UART_16550 (0U)
#define CONFIG_TRACE (1U)
#define CONFIG_TRACE_UART (1U)
#define CONFIG_TRACE_BUFFER (1U)
#define CONFIG_TRACE_ITM (1U)
#define CONFIG_ITM (1U)
#define CONFIG_ISR (1U)
#define CONFIG_RAT_NUM_PRESERVE_ENTRIES (0x0U)

#define CONFIG_ARM (1U)


#define CONFIG_ADDR_REMAP_OFFSET (0x60000000U)

/* HSM OSPI ACCESS change this macros for OSPI NOR*/

#define OSPI_INPUT_CLKFRQ       166666666U
#define OSPI_INTERNUMBER        171u
#define OSPI_INTERENABLE        0
#define OSPI_INTERPRIORITY      4u
#define OSPI_BAUDRATEDIV        4u
#define OSPI_DACENABLE          1
#define OSPI_PHASEDELELE        1            


/*HSM WDG*/
#define HSMWDG_ENABLE            (1)
#define HSMWDG_RTIFREQUENCYCFG   (32557U) /*32KHz for HSM*/
#define HSMWDG_REACTIONCFG       (0xAU) /*Interrupt*/
#define HSMWDG_TIMEOUTCFG        (1000U) /*1 sec for HSM*/
#define HSMWDG_WINDOWSIZECFG     (0x00000005U) /*100% for HSM*/
#define HSMWDG_INTERRUPT
#define HSMWDG_PETCOUNTER        ((HSMWDG_TIMEOUTCFG*85U)/(1000U))
/*End HSM WDG*/

#define QUASI_SYNC_SUPPORT_ENABLE
#define HSMSTACKPROTECTION
#define CONFIG_SECURITY_BOOT_HSM_M4F (1U)
#define VHSMMPU_ENABLE
#define FAULTLOGGING
#define VHSMFW_ENABLE

#define VDLT_ENABLE

#define CONFIG_MPU_NUM_REGIONS (6)
#define CONFIG_RA_LIB (1U)

#define CONFIG_DMSC_IA (1U)
#define CONFIG_DMSC_IA_SHARED (1U)

#define CONFIG_DEVICE_TYPE_HS (1U)

#define CONFIG_SECURITY_SA2UL (1U)

#define CONFIG_SECURITY_SA2UL_PKA (1U)

#define CONFIG_SECURITY_SA2UL_PKA_FW_ROM_ADDR (0x0U)

#define CONFIG_SECURITY_ISC_CRED (1U)

#define CONFIG_SECURITY_KEYSTORE_SIZE (0x2000U)

#define CONFIG_SECURITY_SA2UL_PKA_FW_IMAGE_BUILD  (1U)

#define DEBUG_TRACE 

#endif /*CONFIG_H*/

