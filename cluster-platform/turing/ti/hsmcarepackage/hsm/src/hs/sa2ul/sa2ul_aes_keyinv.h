/*
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef SA2UL_AES_KEYINV_H_
#define SA2UL_AES_KEYINV_H_

#include <types/short_types.h>
#include <types/ftbool.h>

/**
 * \brief Invert AES key needed by SA2UL for decryption
 *
 * \param invKey     Output inverted key, little-endian u32 array
 * \param cipherKey  Input key, little-endian u32 array
 * \param keyBits    Key size in bits
 * \param cmEnable   AES counter measure enabled
 */
void sa2ul_aes_invkey(u32 invKey[], u32 cipherKey[], s32 keyBits, ftbool cmEnable);

#endif /* SA2UL_AES_KEYINV_H_ */
