/*
 * TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 * Copyright (C) 2017-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/*
 * --------------------------------------------------------------------------
 *
 *   Module        : firmware_eip29t2 (Custom)
 *   Version       : 2.1.0 (Custom)
 *   Configuration : t2-ram (Custom)
 *
 *   Date          : 2015-Jul-06
 *
 * Copyright (c) 2004-2015 INSIDE Secure B.V. All Rights Reserved
 *
 * This confidential and proprietary software may be used only as authorized
 * by a licensing agreement from INSIDE Secure.
 *
 * The entire notice above must be reproduced on all authorized copies that
 * may only be made to the extent permitted by a licensing agreement from
 * INSIDE Secure.
 *
 * For more information or support, please go to our online support system at
 * https://essoemsupport.insidesecure.com.
 * In case you do not have an account for this system, please send an e-mail
 * to ESSEmbeddedHW-Support.com.
 * --------------------------------------------------------------------------
 */

/**
 * \file eip29t2_firmware.h
 *
 * \brief  Firmware for eip29t2 (PKA) H/W accelerator
 */

#ifndef EIP29T2_FIRMWARE_H_
#define EIP29T2_FIRMWARE_H_

#include <types/short_types.h>
#include <config.h>

/**
 * Length of the firmware binary in words
 */
#define EIP29T2_FW_IMAGE_LEN_WORDS  2711

/**
 * PKA firmware data
 */
#ifdef CONFIG_SECURITY_SA2UL_PKA_FW_IMAGE_BUILD
extern const u32 eip29t2_fw_image[EIP29T2_FW_IMAGE_LEN_WORDS];
#else
const u32 *eip29t2_fw_image;
#endif

#endif /* EIP29T2_FIRMWARE_H_ */
