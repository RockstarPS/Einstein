/*
 * Header file defining HSM related macro for AM62PX device.
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef HSM_CONFIG_H_
#define HSM_CONFIG_H_

/* SA3UL Context fetch Initiator ISC ID */
#define HSM_ISC_SA_CTXCACH_EXT_DMA_ID           (149U)

#define HSM_SA_ISC_CONTROL_NON_SECURE           (0x10CC0AU)
#define HSM_PRIV_ID                             (204U)
#define HSM_SRAM_START_ADDR                     (0x43C00000U)
#define HSM_SRAM_END_ADDR                       (0x43C3FFFFU)

#endif /* HSM_CONFIG_H_ */
