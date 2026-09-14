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
 * \file vHsmCrypt_Random.c
 *
 * \brief
 * Visteon HSM Random Number Generate for TI AM62PX
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *          Krithik B John           | kjohn     | VTSC, Chennai, India
 ******************************************************************************/
#include "vHsmCrypt.h"
#include "sa2ul_rng.h"

#define FULLRNGLENG   (16u)
#define DOUBLERNGLENG (32u)

#if(VHSMCRYPT_TRNG_ENABLED == STD_ON)
void vHsmTrng_Init(void)
{
    uint32 fl_RetVal_E;
    fl_RetVal_E = sa2ul_rng_init();
    if (EFTOK == fl_RetVal_E) 
    {
        fl_RetVal_E = sa2ul_rng_setup(SA2UL_INSTANCE_TIFS_TRNG, SA2UL_TRNG_MODE_NO_DRBG);
    }
    if(EFTOK == fl_RetVal_E)
    {
        TRACE_info("\r\n RNG init done");
    }
}

FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_TrngRead(uint8* const p_DstPtr_pU8, const uint8 p_SizeByte_U8)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_E = EFTOK;
    if ((NULL_PTR != p_DstPtr_pU8) && (0UL != p_SizeByte_U8))
    {
        fl_RetVal_E = sa2ul_rng_read(SA2UL_INSTANCE_TIFS_TRNG,(uint32 *)p_DstPtr_pU8);
        if((FULLRNGLENG < p_SizeByte_U8) && (DOUBLERNGLENG >= p_SizeByte_U8) && (EFTOK == fl_RetVal_E))
        {
            fl_RetVal_E = sa2ul_rng_read(SA2UL_INSTANCE_TIFS_TRNG,(uint32*)(p_DstPtr_pU8+FULLRNGLENG));
        }
        if(EFTOK == fl_RetVal_E)
        {
            l_RetVal_e = E_OK;
        }
    }
    else
    {
        /* Do nothing */
    }
    return l_RetVal_e;
}

#endif
/*EOF*/
