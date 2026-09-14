/*
 * System Firmware Source File
 *
 * OSAL Platform Configuration for AM62PX device
 *
 * Data version: 231011_130515
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */
#ifndef AM62PX_OSAL_PLATFORM_H
#define AM62PX_OSAL_PLATFORM_H

#include <hosts.h>
#include <dmsc_irq_map.h>
#include <sec_proxy_config_data.h>

/*
 * Defines for mcu_instance(sa3ss_am62a_main_0_sec_proxy_0) sec low:
 * sec_low_priority_rx
 */
#define SEC_PROXY_MCU_HSM_QUEUE_SEC_LOW_IRQ AM62PX_SA3_SS0_SEC_PROXY_0_SEC_LOW_PRIORITY_RX_THR_EVENT_IRQ
#define SEC_PROXY_MCU_HSM_QUEUE_SEC_LOW AM62PX_SA3_SS0_SEC_PROXY_0_RX_TIFS_HSM_SEC_LOW_PRIORITY_RX_THR015_CONF015

/** Boot Host: WKUP_0_R5_0: Cortex R5_0 context 0 on WKUP domain (BOOT) */
#define BOOT_NOTIFICATION_DEST_HOST_ID HOST_ID_WKUP_0_R5_0

/** Maximum number of Secure Proxy Instances */
#define DMSC_SEC_PROXY_INSTANCE_COUNT 0x00000002U

/** Maximum number of DMSC IRQs */
#define DMSC_MAX_INTERRUPTS 0x00F0U

/** Hardware queue Size */
#define HW_QUEUE_SIZE 0x0034U

/** High Priority Message Queue */
#define MEM_MSG_HI_QUEUE 0x0000U

/** Low Priority Message Queue */
#define MEM_MSG_LO_QUEUE 0x0001U

#endif /* AM62PX_OSAL_PLATFORM_H */
