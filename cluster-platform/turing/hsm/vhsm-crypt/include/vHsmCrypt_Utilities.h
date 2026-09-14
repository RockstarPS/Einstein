/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2024] Visteon Corporation
 *       All Rights Reserved.
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and
 *               intends to maintain it in confidence to preserve its trade
 *               secret status. Visteon Corporation reserves the right, under
 *               the copyright laws of the United States or those of any other
 *               country that may have jurisdiction, to protect this work as an
 *               unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves
 *               its rights under all copyright laws to protect this work as a
 *               published work, when appropriate. Those having access to this
 *               work may not copy it, use it, modify it, or disclose the
 *               information contained in it without the written authorization
 *               of Visteon Corporation.
 *
 * \file vHsmCrypt_Utilities.h
 *
 * \brief
 * Visteon HSM Crypto utilities
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *          Krithik B John           | kjohn     | VTSC, Bengaluru, India
 ******************************************************************************/
#include "Std_Types.h"

void Crypto_Uint8ToUint32(const uint8 *source, uint32 sourceLengthInBytes, uint32 *dest);
void Crypto_Uint32ToUint8(const uint32 *src, uint32 sourceLengthInBytes, uint8 *dest);
void Crypto_Uint32ToBigInt(uint32 *source, uint32 sourceLengthInWords, uint32 *dest);
void Crypto_bigIntToUint32(uint32 *source, uint32 sourceLengthInWords, uint32 *dest);

#define AES_KEYLEN(x)  ((x-8)/(4))
#define vHSMCRYPT_AES256KEY_SIZE   (32u)
#define vHSMCRYPT_AES192KEY_SIZE   (24u)
#define vHSMCRYPT_AES128KEY_SIZE   (16u)

/*EOF*/
