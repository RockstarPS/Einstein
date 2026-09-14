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
 * \file vHsmCrypt_AesCmac.c
 *
 * \brief
 * Visteon HSM Crypto AES CMAC Main Implementation File
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

#define BITSIZE  (8u)




/******************************************************************************
 *  INTERNAL TYPES
 *****************************************************************************/


LOCAL struct aes_ctx l_aescmac_ctx_st = {0};

/******************************************************************************
 *  INTERNAL VARIABLES
 *****************************************************************************/


/**
 ******************************************************************************
 ** \var vHsmCrypt_CurrentCmacCommonState_U8
 **
 ** \brief Tracks the current state of the CMAC Engine.
 **
 *****************************************************************************/



/******************************************************************************
 *  PUBLIC FUNCTION IMPLEMENTATIONS
 *****************************************************************************/

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesCmacGenerate(const uint8* const p_AesCmacKeysPtr_pS,const uint8 p_AesCmacKeyLength_pU8, const uint8* const p_MsgPtr_pU8,
                          const uint32 p_MsgLength_U32, uint8* const p_AesCmacGenPtr_pU8,
                          const uint32 p_AesCmacGenLength_U32)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_Retval_E;
    uint8 CmacKeyLength = 0;
    uint8 CmacLength = 0;
    if ((NULL_PTR != p_AesCmacKeysPtr_pS) && (NULL_PTR != p_MsgPtr_pU8) && (NULL_PTR != p_AesCmacGenPtr_pU8) &&
        (VHSMCRYPT_HALF_WORD_SIZE == p_AesCmacGenLength_U32) && ((vHSMCRYPT_AES256KEY_SIZE == p_AesCmacKeyLength_pU8) ||(vHSMCRYPT_AES192KEY_SIZE == p_AesCmacKeyLength_pU8) || (vHSMCRYPT_AES128KEY_SIZE == p_AesCmacKeyLength_pU8)  ))
    {
        CmacKeyLength = p_AesCmacKeyLength_pU8;
        (void)memcpy((uint8* )l_aescmac_ctx_st.key_1,p_AesCmacKeysPtr_pS,CmacKeyLength);
        l_aescmac_ctx_st.op_key_size = AES_KEYLEN(CmacKeyLength) | AES_OP_ENCRYPT;
        l_aescmac_ctx_st.mode = AES_MODE_CMAC;
        l_aescmac_ctx_st.kek_options = 0;
        fl_Retval_E = aes_mac_oneshot(&l_aescmac_ctx_st,p_MsgPtr_pU8,p_MsgLength_U32);
        if(EFTOK == fl_Retval_E)
        {
            CmacLength = p_AesCmacGenLength_U32;
            l_RetVal_e = E_OK;
            (void)memcpy(p_AesCmacGenPtr_pU8,(uint8 *)l_aescmac_ctx_st.tag,CmacLength);
        }
    }
    else
    {
        /* Do Nothing */
    }
    (void)memset(&l_aescmac_ctx_st,0x00,sizeof(l_aescmac_ctx_st));
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesCmacVerify(const uint8* const p_AesCmacKeysPtr_pS,const uint8 p_AesCmacKeyLength_pU8, const uint8* const p_MsgPtr_pU8,
                        const uint32 p_MsgLength_U32, const uint8* const p_AesCmacVerPtr_pU8,
                        const uint8 p_AesCmacVerBits_U8, uint32* const p_ResultPtr_pU32)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    uint8 fl_AesTag_U8A[32] = {0};
    uint32 i;
    if ((NULL_PTR != p_AesCmacKeysPtr_pS) && (NULL_PTR != p_MsgPtr_pU8) && (NULL_PTR != p_AesCmacVerPtr_pU8) && (NULL_PTR != p_ResultPtr_pU32) && ((p_AesCmacVerBits_U8 % BITSIZE) == 0))
    {
        l_RetVal_e = vHsmCrypt_AesCmacGenerate(p_AesCmacKeysPtr_pS,p_AesCmacKeyLength_pU8,p_MsgPtr_pU8,p_MsgLength_U32,&fl_AesTag_U8A[0],(p_AesCmacVerBits_U8 *BITSIZE));
        if(E_NOT_OK != l_RetVal_e)
        {
            for(i=0;i<p_AesCmacVerBits_U8*BITSIZE;i++)
            {
                if(fl_AesTag_U8A[i] != p_AesCmacVerPtr_pU8[i])
                {
                    l_RetVal_e = E_NOT_OK;
                    break;
                }
            }
            if(E_OK == l_RetVal_e)
            {
                *p_ResultPtr_pU32 = 0;
            }
            else
            {
                *p_ResultPtr_pU32 = 1;
            }
        }
    }
    else
    {
        /* Do Nothing */
    }
    return l_RetVal_e;
}


 /* VHSMCRYPT_AES_ECB_ENABLED */

/******************************************************************************
 *  REVISION HISTORY
 *  ---------------------------------------------------------------------------
 *  Refer to the module's public header file.
 *
 *  MODULE VERSION
 *  ---------------------------------------------------------------------------
 *  Refer to the VERSION INFORMATION SECTION in module's internal header file.
 ******************************************************************************/

/* EOF */
