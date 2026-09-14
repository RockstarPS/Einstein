/*
 * System Firmware Security Management
 *
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sa2ul_sec_ctx_bootcfg.h
 *
 * \brief Boot configuration data for SA2UL context module
 */

#ifndef SA2UL_SEC_CTX_BOOTCFG_H
#define SA2UL_SEC_CTX_BOOTCFG_H

#include <types/fterr.h>
#include <types/ftbool.h>
#include <types/short_types.h>
#include <types/address_types.h>

/**
 * Maximum length of one security context
 */
#define SA2UL_SEC_CTX_LEN                (256U)

/**
 * Overall size of memory allocated to security context
 *
 * Keep this aligned to 4K to setup firewalls
 */
#define SA2UL_SEC_CTX_MEM_SIZE           (4096U)

/**
 * Number of security contexts available to callers
 */
#define SA2UL_SEC_CTX_NUM  (SA2UL_SEC_CTX_MEM_SIZE / SA2UL_SEC_CTX_LEN)

/**
 * \brief Ownership information for security contexts
 *
 * \param sa2ul_ctx_dma_privid PrivID set to sa2ul ctx dma Initiator
 *
 * \param owners Owners for each context slots
 */
struct sa2ul_ctx_bootcfg {
	u16	sa2ul_ctx_dma_privid;
	u8	owners[SA2UL_SEC_CTX_NUM];
};
#endif
