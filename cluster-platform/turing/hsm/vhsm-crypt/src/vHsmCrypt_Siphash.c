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
 * \file vHsmCrypt_Siphash.c
 *
 * \brief
 * Visteon HSM SIPHASH 24 Main Implementation File
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *          Krithik B John           | kjohn     | VTSC, Bengaluru, India
 ******************************************************************************/

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "vHsmCrypt.h"
#include <Std_Types.h>
#include <string.h>
#include <vHsmCrypt_Cfg.h>

/******************************************************************************
 *  MACROS
 *****************************************************************************/
#define LOCAL static

#define SIPHASH_SIZE  (64)
#define HASHBYTE_SIZE (8)

#define ONEBYTE_SHIFT   (8)
#define TWOBYTE_SHIFT   (16)
#define THREEBYTE_SHIFT (24)
#define FOURBYTE_SHIFT  (32)
#define FIVEBYTE_SHIFT  (40)
#define SIXBYTE_SHIFT   (48)
#define SEVENBYTE_SHIFT (56)

#define SIPROUND_ROTLCONST1 (13)
#define SIPROUND_ROTLCONST2 (16)
#define SIPROUND_ROTLCONST3 (17)
#define SIPROUND_ROTLCONST4 (21)

#define SIPV0 (0x736f6d6570736575ULL)
#define SIPV1 (0x646f72616e646f6dULL)
#define SIPV2 (0x6c7967656e657261ULL)
#define SIPV3 (0x7465646279746573ULL)

#define MESSAGELEN_CHECK (7)
#define SIP_FINAL_CONST  (0xff)

#define C_ROUND (2)
#define D_ROUND (4)

#define HSMCRPT_SIPHASH_VERIFICATION_OK (0u)
#define HSMCRPT_SIPHASH_VERIFICATION_NOT_OK (1u)

#define VKMS_SIPHASH_KEYID (651u)

#if (VHSMCRYPT_SIPHASH_24_ENABLED == STD_ON)

LOCAL te_VKMS_ProvisionStateType te_VKMSprovision;
/******************************************************************************
 *  LOCAL FUNCTION DECLARATIONS
 *****************************************************************************/
LOCAL uint64 vHsmCrypt_siphash_24_rotate_left(uint64 p_Varrotate_U64, uint8 p_indices_U8);
LOCAL uint64 vHsmCrypt_siphash_24_u8to64_le(uint8* p_ptr_pU8);
LOCAL void   vHsmCrypt_siphash_24_u32to8_le(uint8* p_digestPtr_U8, uint64 p_digestVal_U64);
LOCAL void   vHsmCrypt_siphash_24_u64to8_le(uint8* p_digPtr_pU8, uint64 p_digVal_U64);
LOCAL void   vHsmCrypt_siphash_24_sipround(uint64* p_sipround_v0_u64, uint64* p_sipround_v1_u64,
                                           uint64* p_sipround_v2_u64, uint64* p_sipround_v3_u64);

/******************************************************************************
 *  LOCAL Function Implementations
 *****************************************************************************/
LOCAL uint64 vHsmCrypt_siphash_24_rotate_left(uint64 p_Varrotate_U64, uint8 p_indices_U8)
{
    return ((uint64)((p_Varrotate_U64) << (p_indices_U8)) | ((p_Varrotate_U64) >> (SIPHASH_SIZE - (p_indices_U8))));
}

LOCAL uint64 vHsmCrypt_siphash_24_u8to64_le(uint8* p_ptr_pU8)
{
    return (((uint64)((p_ptr_pU8)[0])) | ((uint64)((p_ptr_pU8)[1]) << ONEBYTE_SHIFT) |
            ((uint64)((p_ptr_pU8)[2]) << TWOBYTE_SHIFT) | ((uint64)((p_ptr_pU8)[3]) << THREEBYTE_SHIFT) |
            ((uint64)((p_ptr_pU8)[4]) << FOURBYTE_SHIFT) | ((uint64)((p_ptr_pU8)[5]) << FIVEBYTE_SHIFT) |
            ((uint64)((p_ptr_pU8)[6]) << SIXBYTE_SHIFT) | ((uint64)((p_ptr_pU8)[7]) << SEVENBYTE_SHIFT));
}
LOCAL void vHsmCrypt_siphash_24_u32to8_le(uint8* p_digestPtr_U8, uint64 p_digestVal_U64)
{
    p_digestPtr_U8[0] = (uint8)((p_digestVal_U64));
    p_digestPtr_U8[1] = (uint8)((p_digestVal_U64) >> ONEBYTE_SHIFT);
    p_digestPtr_U8[2] = (uint8)((p_digestVal_U64) >> TWOBYTE_SHIFT);
    p_digestPtr_U8[3] = (uint8)((p_digestVal_U64) >> THREEBYTE_SHIFT);
}
LOCAL void vHsmCrypt_siphash_24_u64to8_le(uint8* p_digPtr_pU8, uint64 p_digVal_U64)
{
    vHsmCrypt_siphash_24_u32to8_le((p_digPtr_pU8), (uint32)((p_digVal_U64)));
    vHsmCrypt_siphash_24_u32to8_le((p_digPtr_pU8) + 4u, (uint32)((p_digVal_U64) >> FOURBYTE_SHIFT));
}

LOCAL void vHsmCrypt_siphash_24_HALF_ROUND(uint64* var_v0_u64, uint64* var_v1_u64, uint64* var_v2_u64,
                                           uint64* var_v3_u64, uint8 rotate_ind1_u8, uint8 rotate_ind2_u8)
{
    *var_v0_u64 += *var_v1_u64;
    *var_v2_u64 += *var_v3_u64;
    *var_v1_u64 = (vHsmCrypt_siphash_24_rotate_left((*var_v1_u64), rotate_ind1_u8)) ^ (*var_v0_u64);
    *var_v3_u64 = (vHsmCrypt_siphash_24_rotate_left((*var_v3_u64), rotate_ind2_u8)) ^ (*var_v2_u64);
    *var_v0_u64 = vHsmCrypt_siphash_24_rotate_left((*var_v0_u64), FOURBYTE_SHIFT);
}

LOCAL void vHsmCrypt_siphash_24_sipround(uint64* p_sipround_v0_u64, uint64* p_sipround_v1_u64,
                                         uint64* p_sipround_v2_u64, uint64* p_sipround_v3_u64)
{
    vHsmCrypt_siphash_24_HALF_ROUND(p_sipround_v0_u64, p_sipround_v1_u64, p_sipround_v2_u64, p_sipround_v3_u64,
                                    SIPROUND_ROTLCONST1, SIPROUND_ROTLCONST2);
    vHsmCrypt_siphash_24_HALF_ROUND(p_sipround_v2_u64, p_sipround_v1_u64, p_sipround_v0_u64, p_sipround_v3_u64,
                                    SIPROUND_ROTLCONST3, SIPROUND_ROTLCONST4);
}

/******************************************************************************
 *  PUBLIC FUNCTION IMPLEMENTATIONS
 *****************************************************************************/
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_siphash24_Start(uint32 p_jobid_pU32)
{
    Std_ReturnType l_RetVal_E = E_OK;
    return l_RetVal_E;
}

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_siphash24_Finish(uint8* p_DigestPtr_pU8,uint32 p_DigestLength_U32)
{
    Std_ReturnType l_RetVal_E = E_OK;
    if((p_DigestPtr_pU8 != NULL) && (p_DigestLength_U32 != 0))
    {

    }
    else
    {
        l_RetVal_E = E_NOT_OK;
    }
    return l_RetVal_E;
}

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_siphash24(uint32 p_JobId_U32,uint8* p_MsgPtr_pU8, uint32 p_MsgLength_U32, uint8* p_DigestPtr_pU8,
                    uint32 p_DigestLength_U32)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    te_VKMS_ErrorType fl_KeyValid_e = VKMS_ERR_GENERAL;
    uint8 l_VKMSKey[16] = {0};
    uint16 l_VKMSKeylen_U16 = 16;
    te_VKMSprovision = vHsmVKMSKeyStore_GetProvisionState();
    fl_KeyValid_e = HSM_VKMS_getKey(VKMS_SIPHASH_KEYID,&l_VKMSKeylen_U16,&l_VKMSKey[0], 1);
    if ((NULL != p_MsgPtr_pU8) && (p_DigestLength_U32<=8u) &&(NULL != p_DigestPtr_pU8) && (e_VKMS_Provisioned_Normal == te_VKMSprovision) && (VKMS_ERR_NONE == fl_KeyValid_e))
    {
        if ((p_MsgPtr_pU8 >= CODEMEM_START_ADDR) && (p_MsgPtr_pU8 <= CODEMEM_END_ADDR))
        {
            l_RetVal_e = E_NOT_OK;
        }
        else
        {
            uint8* p_key_pU8 = &l_VKMSKey[0];
            uint8 l_cRounds;
            uint8 l_dRounds;
            uint8 l_MacOut_U8[8] = {0};
            uint64 l_sipv0_U64 = SIPV0;
            uint64 l_sipv1_U64 = SIPV1;
            uint64 l_sipv2_U64 = SIPV2;
            uint64 l_sipv3_U64 = SIPV3;
            uint64 l_sipk0_U64 = vHsmCrypt_siphash_24_u8to64_le(p_key_pU8);
            uint64 l_sipk1_U64 = vHsmCrypt_siphash_24_u8to64_le(p_key_pU8 + HASHBYTE_SIZE);
            uint64 l_sipm_U64;
            uint8* end_MsgPtr_pU8  = p_MsgPtr_pU8 + p_MsgLength_U32 - (p_MsgLength_U32 % sizeof(uint64));
            uint8  l_leftMsglen_U8 = p_MsgLength_U32 & MESSAGELEN_CHECK;
            uint64 l_sipb_U64      = ((uint64)p_MsgLength_U32) << SEVENBYTE_SHIFT;
            l_sipv3_U64 ^= l_sipk1_U64;
            l_sipv2_U64 ^= l_sipk0_U64;
            l_sipv1_U64 ^= l_sipk1_U64;
            l_sipv0_U64 ^= l_sipk0_U64;
            for (; p_MsgPtr_pU8 != end_MsgPtr_pU8; p_MsgPtr_pU8 += HASHBYTE_SIZE)
            {
                l_sipm_U64 = vHsmCrypt_siphash_24_u8to64_le(p_MsgPtr_pU8);
                l_sipv3_U64 ^= l_sipm_U64;
                for (l_cRounds = 0; l_cRounds < C_ROUND; ++l_cRounds)
                {
                    vHsmCrypt_siphash_24_sipround(&l_sipv0_U64, &l_sipv1_U64, &l_sipv2_U64, &l_sipv3_U64);
                }
                l_sipv0_U64 ^= l_sipm_U64;
            }
            if (l_leftMsglen_U8 > 0)
            {
                for (; l_leftMsglen_U8 > 0; l_leftMsglen_U8--)
                {
                    l_sipb_U64 |= (((uint64)p_MsgPtr_pU8[l_leftMsglen_U8 - 1]) << ((l_leftMsglen_U8 - 1) * 8));
                }
            }
            l_sipv3_U64 ^= l_sipb_U64;
            for (l_cRounds = 0; l_cRounds < C_ROUND; ++l_cRounds)
            {
                vHsmCrypt_siphash_24_sipround(&l_sipv0_U64, &l_sipv1_U64, &l_sipv2_U64, &l_sipv3_U64);
            }
            l_sipv0_U64 ^= l_sipb_U64;
            l_sipv2_U64 ^= SIP_FINAL_CONST;
            for (l_dRounds = 0; l_dRounds < D_ROUND; ++l_dRounds)
            {
                vHsmCrypt_siphash_24_sipround(&l_sipv0_U64, &l_sipv1_U64, &l_sipv2_U64, &l_sipv3_U64);
            }
            l_sipb_U64 = (l_sipv0_U64 ^ l_sipv1_U64) ^ (l_sipv2_U64 ^ l_sipv3_U64);
            vHsmCrypt_siphash_24_u64to8_le(l_MacOut_U8, l_sipb_U64);
            (void)memcpy(p_DigestPtr_pU8,l_MacOut_U8,p_DigestLength_U32);
            l_RetVal_e = E_OK;
        }
    }
    else
    {
        l_RetVal_e = E_NOT_OK;
    }
    return l_RetVal_e;
}
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_siphash24_MacVerify(uint32 p_keyId_U32,uint8* p_MsgPtr_pU8, uint32 p_MsgLength_U32, uint8* p_MacPtr_pU8,
                    uint32 p_MacLength_U32,uint8 * const  p_VerResultPtr_pU8)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    uint8 l_Macout_U8[8] = {0};
    uint8 l_MacVer_U8[8] = {0};
    if((NULL != p_MsgPtr_pU8) && (NULL != p_MacPtr_pU8) && (p_MsgLength_U32 != 0u) && (p_MacLength_U32 != 0u) && (p_MacLength_U32 <= 8u))
    {
        l_RetVal_E = vHsmCrypt_siphash24(1u,p_MsgPtr_pU8,p_MsgLength_U32,l_Macout_U8,8);
        if(E_OK ==l_RetVal_E)
        {
            (void)memcpy(l_MacVer_U8,p_MacPtr_pU8,p_MacLength_U32);
            if(0u == memcmp(l_MacVer_U8,l_Macout_U8,p_MacLength_U32))
            {
                l_RetVal_E = E_OK;
                *p_VerResultPtr_pU8 = HSMCRPT_SIPHASH_VERIFICATION_OK;
            }
            else
            {
                *p_VerResultPtr_pU8 = HSMCRPT_SIPHASH_VERIFICATION_NOT_OK;
            }
        }
        else
        {
            l_RetVal_E = E_NOT_OK;
        }
    }
    else
    {
        /*sanity check fails*/
    }
    return l_RetVal_E;

}
#endif /* VHSMCRYPT_SIPHASH_24_ENABLED */
