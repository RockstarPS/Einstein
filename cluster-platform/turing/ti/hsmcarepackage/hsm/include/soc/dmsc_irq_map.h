/*
 * System Firmware Source File
 *
 * TIFS IRQ maps for AM62PX device
 *
 * Data version: 231011_130515
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */
#ifndef AM62PX_TIFS_IRQ_MAP_H
#define AM62PX_TIFS_IRQ_MAP_H

/** IRQ instances mapped via IA (2 entries) */
#define DMSC_1_IA_IRQ_INSTANCES (0x01U)

#define AM62PX_SA3_SS0_SEC_PROXY_0_SEC_LOW_PRIORITY_RX_THR_EVENT_IRQ (0x00DAU)
#define AM62PX_SA3_SS0_SEC_PROXY_0_SEC_LOW_PRIORITY_RX_THR_EVENT_CONF_1 (0x00U)

#define HSM_SEC_PROXY_RX_IRQ AM62PX_SA3_SS0_SEC_PROXY_0_SEC_LOW_PRIORITY_RX_THR_EVENT_IRQ


#endif /* AM62PX_TIFS_IRQ_MAP_H */
