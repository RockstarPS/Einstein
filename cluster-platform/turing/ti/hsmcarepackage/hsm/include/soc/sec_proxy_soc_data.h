/*
 * System Firmware Source File
 *
 * SoC defines for secure proxy instances for AM62PX device
 *
 * Data version: 231011_130515
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */
#ifndef SOC_AM62PX_SPROXY_SOC_DATA_H
#define SOC_AM62PX_SPROXY_SOC_DATA_H


/** Number of Secure Proxy instances */
#define SOC_MAX_SEC_PROXY_INSTANCES (0x01U)
/*
 * AM62PX_SPROXY_IDX_SA3_SS0_SEC_PROXY_0: Secure proxy instance:
 * SA3_SS0_SEC_PROXY_0 linked to RA inst: SA3_SS0_RINGACC_0
 */
#define AM62PX_SPROXY_IDX_SA3_SS0_SEC_PROXY_0 (0x0U)

/** Secure Proxy instance used by ROM */
#define ROM_SEC_PROXY_IDX AM62PX_SPROXY_IDX_SA3_SS0_SEC_PROXY_0

#endif /* SOC_AM62PX_SPROXY_SOC_DATA_H */
