/*
 * System Firmware Source File
 *
 * HSM integration data for AM62PX device.
 *
 * Data version: 231011_130515
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */
#ifndef SOC_AM62PX_HSM_DATA_H
#define SOC_AM62PX_HSM_DATA_H

#include <processors.h>

/**
 * HSM Processor name
 */
#define SOC_HSM_PROC_IDX PROC_ID_HSM0

/**
 * LPSC index for the HSM reset
 */
#define LPSC_MAIN_HSM 30
#define SOC_HSM_LPSC_IDX LPSC_MAIN_HSM

/**
 * Base address for the HSM WFI status
 */
#define HSM_WFI_BASE 0x43000000U

/**
 * Offset of the HSM WFI status MMR
 */
#define HSM_WFI_OFFSET 0x00018400U

/**
 * Bit mask for the HSM WFI status
 */
#define HSM_WFI_BIT_MASK 0x00000008U
/**
 * Bit shift for the HSM WFI status
 */
#define HSM_WFI_BIT_SHIFT 0x03U

/**
 * Firewall ID protecting the HSM secure proxy threads
 */
#define HSM_SEC_PROXY_TARGET_DATA_FWL_ID 161

#define MAIN_DEV_SA2_UL0 297U

#endif /* SOC_AM62PX_HSM_DATA_H */
