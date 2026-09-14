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
 * \file vHsmCrypt_Utilities.c
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
#include "vHsmCrypt_Utilities.h"
#include "vHsmCrypt.h"


void Crypto_Uint8ToUint32(const uint8 *source, uint32 sourceLengthInBytes, uint32 *dest)
{
    uint32 i, t = 0;

    for (i=0; i< sourceLengthInBytes; i++)
    {
        t = (t << 8) | source[i];
        if ((i & 3) == 3) {
            *dest++ = t;
            t = 0;
        }
    }
    if ((i & 3) != 0)
    {
        *dest = t << ((4-(i&3)) << 3);
    }
    return;
}

void Crypto_Uint32ToUint8(const uint32 *src, uint32 sourceLengthInBytes, uint8 *dest)
{
    uint32 i, t;

    for (i=0; i< sourceLengthInBytes; i+=4)
    {
        t = *src++;
        *dest++ = t >> 24;
        *dest++ = t >> 16;
        *dest++ = t >> 8;
        *dest++ = t;
    }
    return;
}

void Crypto_Uint32ToBigInt(uint32 *source, uint32 sourceLengthInWords, uint32 *dest)
{
    uint32 i, t = 0, t2 = 0;
    t2 = sourceLengthInWords / 2;

    for(i=0;i<t2;i++)
    {
        t = source[i];
        source[i] = source[sourceLengthInWords - 1 - i];
        source[sourceLengthInWords - 1 - i] = t;
    }
    dest[0] = sourceLengthInWords;
    for(i=0; i < sourceLengthInWords; i++)
    {
        dest[1 + i] = source[i];
    }

    return;
}

void Crypto_bigIntToUint32(uint32 *source, uint32 sourceLengthInWords, uint32 *dest)
{
    uint32 i, t = 0, t2 = 0;
    t2 = (sourceLengthInWords / 2)+1;

    for(i=1; i<t2; i++)
    {
        t = source[i];
        source[i] = source[sourceLengthInWords-(i-1)];
        source[sourceLengthInWords-(i-1)] = t;
    }
    for(i=0; i < sourceLengthInWords; i++)
    {
        dest[i] = source[i+1];
    }

    return;
}
/*EOF*/
