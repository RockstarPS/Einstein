/*
 * System Firmware Source File
 *
 * Board Configuration Data Structures
 *
 * Copyright (C) 2019-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */
#ifndef BOARDCFG_MACROS_H
#define BOARDCFG_MACROS_H

/** Length of the hash in bytes. We use SHA2-512 as the hash algorithm */
#define BOARDCFG_HASH_LEN_BYTES (64U)

/** Length of the initial vector used for security boardcfg encryption in bytes */
#define BOARDCFG_SEC_IV_LEN (16U)

/** Length of the string used for security boardcfg validation after decryption in bytes */
#define BOARDCFG_SEC_RS_LEN (32U)

/** Length of the boardcfg array for hosts that can be allowed to unlock the JTAG via TISCI API */
#define BOARDCFG_SEC_MAX_NUM_JTAG_UNLOCK_HOSTS (4U)

#define BOARDCFG_SECPROXY_SCALING_FACTOR_MASK                   (0x01U)
#define BOARDCFG_SECPROXY_SCALING_PROFILE_MASK                  (0x01U)
#define BOARDCFG_SECPROXY_DISABLE_MAIN_NAV_SECURE_PROXY_MASK    (0x01U)

#define BOARDCFG_DEBUG_TRACE_DST_ENABLES_MASK                   (0x0FU)
#define BOARDCFG_DEBUG_TRACE_SRC_ENABLES_MASK                   (0x3FU)

#define BOARDCFG_CONTROL_MAGIC_NUM                              (0xC1D3U)
#define BOARDCFG_SECPROXY_MAGIC_NUM                             (0x1207U)
#define BOARDCFG_MSMC_MAGIC_NUM                                 (0xA5C3U)
#define BOARDCFG_PROC_ACL_MAGIC_NUM                             (0xF1EAU)
#define BOARDCFG_HOST_HIERARCHY_MAGIC_NUM                       (0x8D27U)
#define BOARDCFG_DBG_CFG_MAGIC_NUM                              (0x020CU)
#define BOARDCFG_PMIC_CFG_MAGIC_NUM                             (0x3172U)
#define BOARDCFG_OTP_CFG_MAGIC_NUM                              (0x4081U)
#define BOARDCFG_DKEK_CFG_MAGIC_NUM                             (0x5170U)
#define BOARDCFG_SA2UL_CFG_MAGIC_NUM                            (0xB4FDU)
#define BOARDCFG_SA2UL_CFG_MAGIC_NUM_RSVD                       (0x23BEU)
#define BOARDCFG_SEC_DBG_CTRL_MAGIC_NUM                         (0x42AFU)
#define BOARDCFG_SEC_HANDOVER_CFG_MAGIC_NUM                     (0x608FU)

/*
 * NOTE: We are trying to assign the board configuration number with a pattern.
 * alternatively increment and decrement the digits in previous
 * board configuration macro. This should allow for 16 magic words
 * before needing to pick a new seed.
 * e.g. 0x3172U -> 0x4081U, 0x42AFU -> 0x33BEU
 */
#endif
