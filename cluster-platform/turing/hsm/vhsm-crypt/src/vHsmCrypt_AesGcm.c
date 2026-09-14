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
 * \file vHsmCrypt_AesGcm.c
 *
 * \brief
 * Visteon HSM Crypto AES Gcm Main Implementation File
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

#ifndef LOCAL
#define LOCAL static
#endif


#if (VHSMCRYPT_AES_GCM_ENABLED == STD_ON)
/******************************************************************************
 *  INTERNAL TYPES
 *****************************************************************************/
/**
 *  \enum te_AesGcm_StateType
 *  \brief Enumeration of general states of cry services.
 *
 *  \var te_AesGcm_StateType::e_AesEcb_Idle
 *  \brief The service is in Finished / Idle State.
 *
 *  \var te_AesGcm_StateType::e_AesEcb_Start
 *  \brief The service has been started.
 *
 *  \var te_AesGcm_StateType::e_AesEcb_Update
 *  \brief The service is in update state.
 *
 */
typedef enum
{
    e_AesGcm_Idle   = 0,
    e_AesGcm_Start  = 1,
    e_AesGcm_Update = 2,
} te_AesGcm_StateType;

/******************************************************************************
 *  INTERNAL VARIABLES
 *****************************************************************************/
LOCAL struct aes_ctx l_aesgcm_ctx_st = {0};
#ifdef AES_GCM_MULTIMODE
/**
 ******************************************************************************
 ** \var vHsmCrypt_CurrentGcmEncState_U8
 **
 ** \brief Tracks the current state of the ECB Encryption Engine.
 **
 *****************************************************************************/
LOCAL te_AesGcm_StateType vHsmCrypt_CurrentGcmEncState_U8 = e_AesGcm_Idle;

/**
 ******************************************************************************
 ** \var vHsmCrypt_CurrentGcmDecState_U8
 **
 ** \brief Tracks the current state of the ECB Decryption Engine.
 **
 *****************************************************************************/
LOCAL te_AesGcm_StateType vHsmCrypt_CurrentGcmDecState_U8 = e_AesGcm_Idle;
/**
 ******************************************************************************
 ** \var vHsmCrypt_CurrentGcmVerState_U8
 **
 ** \brief Tracks the current state of the ECB Verification Engine.
 **
 *****************************************************************************/
LOCAL te_AesGcm_StateType vHsmCrypt_CurrentGcmVerState_U8 = e_AesGcm_Idle;
#endif

/******************************************************************************
 *  PUBLIC FUNCTION IMPLEMENTATIONS
 *****************************************************************************/
#ifdef AES_GCM_MULTIMODE

FUNC(Std_ReturnType, CRYPT_CODE)vHsmCrypt_AesGcmEncryptStart(const uint8* const p_KeyPtr_pU8, const uint32 p_KeyLength_E,
                             const uint8* const p_IvPtr_pU8, const uint32 p_IvLength_U32)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_Retval_E;
    if ((NULL_PTR != p_KeyPtr_pU8) && (NULL_PTR != p_IvPtr_pU8) &&
        ((vHSMCRYPT_AES256KEY_SIZE == p_KeyLength_E) || (vHSMCRYPT_AES192KEY_SIZE == p_KeyLength_E) ||
         (vHSMCRYPT_AES128KEY_SIZE == p_KeyLength_E)) &&
        (e_AesGcm_Idle == vHsmCrypt_CurrentGcmEncState_U8))
    {
        (void)memset(&l_aesgcm_ctx_st,0x00,sizeof(l_aesgcm_ctx_st));
        (void)memcpy(l_aesgcm_ctx_st.key_1,p_KeyPtr_pU8,p_KeyLength_E);
        (void)memcpy(l_aesgcm_ctx_st.iv,p_IvPtr_pU8,p_IvLength_U32);
        l_aesgcm_ctx_st.op_key_size = AES_KEYLEN(p_KeyLength_E) | AES_OP_ENCRYPT;
        l_aesgcm_ctx_st.mode = AES_MODE_GCM;
        l_aesgcm_ctx_st.kek_options = 0;
        fl_Retval_E = aes_init(&l_aesgcm_ctx_st);
        if(EFTOK == fl_Retval_E)
        {
            vHsmCrypt_CurrentGcmEncState_U8 = e_AesGcm_Start;
            l_RetVal_e = E_OK;
        }
    }
    else
    {
        /* Do Nothing*/
    }
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmEncryptUpdate(const uint8* const p_AadPtr_pU8, const uint32 p_AadLength_U32,
                              const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32,
                              uint8* const p_OutMsgPtr_pU8)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_Retval_E;
    if ((NULL_PTR != p_AadPtr_pU8) && (NULL_PTR != p_MsgPtr_pU8) && (NULL_PTR != p_OutMsgPtr_pU8) &&
        ((e_AesGcm_Start == vHsmCrypt_CurrentGcmEncState_U8) || (e_AesGcm_Update == vHsmCrypt_CurrentGcmEncState_U8)))
    {
        fl_Retval_E = aes_update(&l_aesgcm_ctx_st,)
        vHsmCrypt_CurrentGcmEncState_U8 = e_AesGcm_Update;
        
        l_RetVal_e = E_OK;
    }
    else
    {
        /* Do Nothing */
    }
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmEncryptFinish(uint8* const p_OutMacPtr_pU8, const uint32 p_MacLength_U32)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    if ((e_AesGcm_Update == vHsmCrypt_CurrentGcmEncState_U8) && (NULL_PTR != p_OutMacPtr_pU8))
    {
        VHSMCRYPT_START_CRITICAL_SECTION();
        /* coverity[misra_c_2012_rule_2_2_violation] : FALSE */
        HsmCrpt_AesGcmEncryptFinish(p_OutMacPtr_pU8, p_MacLength_U32);
        vHsmCrypt_CurrentGcmEncState_U8 = e_AesGcm_Idle;
        VHSMCRYPT_STOP_CRITICAL_SECTION();
        l_RetVal_e = E_OK;
    }
    else
    {
        /* Do Nothing */
    }
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmEncryptCancel(void)
{
    VHSMCRYPT_START_CRITICAL_SECTION();
    vHsmCrypt_CurrentGcmEncState_U8 = e_AesGcm_Idle;
    VHSMCRYPT_STOP_CRITICAL_SECTION();
    return E_OK;
}
#endif

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmEncrypt(const uint8* const p_KeyPtr_pU8, const uint32 p_KeyLength_E,
                        const uint8* const p_IvPtr_pU8, const uint32 p_IvLength_U32, const uint8* const p_AadPtr_pU8,
                        const uint32 p_AadLength_U32, const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32,
                        uint8* const p_OutMsgPtr_pU8, uint32 * p_OutMsgLength_pU32, uint8* const p_OutMacPtr_pU8)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_E;
    uint8 i =0;
    const uint8 keyLength = p_KeyLength_E;
    if ((NULL != p_KeyPtr_pU8) && (NULL != p_IvPtr_pU8) && (NULL != p_AadPtr_pU8) && (NULL != p_MsgPtr_pU8) && (NULL != p_OutMacPtr_pU8) 
        && (NULL != p_OutMsgPtr_pU8) && (NULL != p_OutMsgLength_pU32) && ((vHSMCRYPT_AES256KEY_SIZE == p_KeyLength_E) || (vHSMCRYPT_AES192KEY_SIZE == p_KeyLength_E) ||
         (vHSMCRYPT_AES128KEY_SIZE == p_KeyLength_E)))
    {
        (void)memset(&l_aesgcm_ctx_st,0x00,sizeof(l_aesgcm_ctx_st));
        (void)memcpy(l_aesgcm_ctx_st.key_1,p_KeyPtr_pU8,keyLength);
        (void)memcpy(l_aesgcm_ctx_st.iv,p_IvPtr_pU8,p_IvLength_U32);
        l_aesgcm_ctx_st.op_key_size = AES_KEYLEN(keyLength) | AES_OP_ENCRYPT;
        l_aesgcm_ctx_st.mode = AES_MODE_GCM;
        l_aesgcm_ctx_st.kek_options = 0;
        fl_RetVal_E = aes_aenc_oneshot(&l_aesgcm_ctx_st,p_IvLength_U32,p_AadPtr_pU8,p_AadLength_U32,p_MsgPtr_pU8,p_MsgLength_U32,p_OutMsgPtr_pU8,p_OutMsgLength_pU32);
        if(EFTOK == fl_RetVal_E)
        {
#if 0
            for (i = 0; i < 4; ++i) 
            {
                gcmtag[i * 4 + 0] = (uint8)(l_aesgcm_ctx_st.tag[i] & 0xFF);        
                gcmtag[i * 4 + 1] = (uint8)((l_aesgcm_ctx_st.tag[i] >> 8) & 0xFF);
                gcmtag[i * 4 + 2] = (uint8)((l_aesgcm_ctx_st.tag[i] >> 16) & 0xFF);
                gcmtag[i * 4 + 3] = (uint8)((l_aesgcm_ctx_st.tag[i] >> 24) & 0xFF); 
            }
#endif
            (void)memcpy(p_OutMacPtr_pU8,&l_aesgcm_ctx_st.tag[0],16);
            TRACE_info("\r\n Tag");
            for(i=0;i<4;i++)
            {
                TRACE_info_arg_hsm(" ",l_aesgcm_ctx_st.tag[i]);
            }
            l_RetVal_e = E_OK;
        }
    }
    else
    {
        /* Do Nothing */
    }
    return l_RetVal_e;
}

#ifdef AES_GCM_MULTIMODE
FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmDecryptStart(const uint8* const p_DecrKeyPtr_pU8, const HsmCrpt_AesKeySizeType p_DecrKeyLength_E,
                             const uint8* const p_IvPtr_pU8, const uint32 p_IvLength_U32)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    if ((NULL_PTR != p_DecrKeyPtr_pU8) && (NULL_PTR != p_IvPtr_pU8) &&
        ((HSMCRPT_AES_AES128_KEYSIZE_BYTE == p_DecrKeyLength_E) ||
         (HSMCRPT_AES_AES192_KEYSIZE_BYTE == p_DecrKeyLength_E) ||
         (HSMCRPT_AES_AES256_KEYSIZE_BYTE == p_DecrKeyLength_E)) &&
        (e_AesGcm_Idle == vHsmCrypt_CurrentGcmDecState_U8))
    {
        VHSMCRYPT_START_CRITICAL_SECTION();
        HsmCrpt_AesGcmDecryptStart(p_DecrKeyPtr_pU8, p_DecrKeyLength_E, p_IvPtr_pU8, p_IvLength_U32);
        vHsmCrypt_CurrentGcmDecState_U8 = e_AesGcm_Start;
        VHSMCRYPT_STOP_CRITICAL_SECTION();
        l_RetVal_e = E_OK;
    }
    else
    {
        /* Do Nothing */
    }
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmDecryptUpdate(const uint8* const p_AadPtr_pU8, const uint32 p_AadLength_U32,
                              const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32,
                              uint8* const p_OutMsgPtr_pU8)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    if ((NULL_PTR != p_MsgPtr_pU8) && (NULL_PTR != p_AadPtr_pU8) && (NULL_PTR != p_MsgPtr_pU8) &&
        ((e_AesGcm_Start == vHsmCrypt_CurrentGcmDecState_U8) || (e_AesGcm_Update == vHsmCrypt_CurrentGcmDecState_U8)))
    {
        VHSMCRYPT_START_CRITICAL_SECTION();
        HsmCrpt_AesGcmDecryptUpdate(p_AadPtr_pU8, p_AadLength_U32, p_MsgPtr_pU8, p_MsgLength_U32, p_OutMsgPtr_pU8);
        vHsmCrypt_CurrentGcmDecState_U8 = e_AesGcm_Update;
        VHSMCRYPT_STOP_CRITICAL_SECTION();
        l_RetVal_e = E_OK;
    }
    else
    {
        /* Do Nothing */
    }
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmDecryptFinish(const uint8* const p_MacPtr_pU8, const uint32 p_MacLength_U32,
                              const uint32 p_MacBitLength_U32, uint8* const p_VerResultPtr_pU8)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    if (e_AesGcm_Update == vHsmCrypt_CurrentGcmDecState_U8)
    {
        VHSMCRYPT_START_CRITICAL_SECTION();
        /* coverity[misra_c_2012_rule_2_2_violation] : FALSE */
        HsmCrpt_AesGcmDecryptFinish(p_MacPtr_pU8, p_MacLength_U32, p_MacBitLength_U32, p_VerResultPtr_pU8);
        vHsmCrypt_CurrentGcmDecState_U8 = e_AesGcm_Idle;
        VHSMCRYPT_STOP_CRITICAL_SECTION();
        l_RetVal_e = E_OK;
    }
    else
    {
        /* Do Nothing */
    }
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmDecryptCancel(void)
{
    VHSMCRYPT_START_CRITICAL_SECTION();
    vHsmCrypt_CurrentGcmDecState_U8 = e_AesGcm_Idle;
    VHSMCRYPT_STOP_CRITICAL_SECTION();
    return E_OK;
}
#endif

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmDecrypt(const uint8* const p_KeyPtr_pU8, const uint8 p_KeyLength_E,
                        const uint8* const p_IvPtr_pU8, const uint32 p_IvLength_U32, const uint8* const p_AadPtr_pU8,
                        const uint32 p_AadLength_U32, const uint8* const p_OutMsgPtr_pU8, const uint32 p_MsgLength_U32,
                        uint8* p_MsgPtr_pU8, const uint8* const p_MacPtr_pU8, const uint32 p_MacLength_U32)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_E;
    uint32 outMsgLen = 0;
    const uint8 keyLength = p_KeyLength_E;
    if ((NULL != p_KeyPtr_pU8) && (NULL != p_IvPtr_pU8) && (NULL != p_AadPtr_pU8) && (NULL != p_MsgPtr_pU8) && (NULL != p_MacPtr_pU8) 
        && (NULL != p_OutMsgPtr_pU8) && ((vHSMCRYPT_AES256KEY_SIZE == p_KeyLength_E) || (vHSMCRYPT_AES192KEY_SIZE == p_KeyLength_E) ||
         (vHSMCRYPT_AES128KEY_SIZE == p_KeyLength_E)))
    {
        (void)memset(&l_aesgcm_ctx_st,0x00,sizeof(l_aesgcm_ctx_st));
        (void)memcpy(l_aesgcm_ctx_st.key_1,p_KeyPtr_pU8,keyLength);
        (void)memcpy(l_aesgcm_ctx_st.iv,p_IvPtr_pU8,p_IvLength_U32);
        l_aesgcm_ctx_st.op_key_size = AES_KEYLEN(keyLength) | AES_OP_DECRYPT;
        l_aesgcm_ctx_st.mode = AES_MODE_GCM;
        l_aesgcm_ctx_st.kek_options = 0;
        fl_RetVal_E = aes_aenc_oneshot(&l_aesgcm_ctx_st,p_IvLength_U32,p_AadPtr_pU8,p_AadLength_U32,p_OutMsgPtr_pU8,p_MsgLength_U32,p_MsgPtr_pU8,&outMsgLen);
        if(EFTOK == fl_RetVal_E)
        {
            if(0 == memcmp(p_MacPtr_pU8,(uint8*)l_aesgcm_ctx_st.tag,16))
            { 
                l_RetVal_e = E_OK;
            }
        }
    }
    else
    {
        /* Do Nothing */
    }
    return l_RetVal_e;
}

#if AES_GCM_MULTIMODE

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesGcmVerify(const uint8* const p_KeyPtr_pU8, const HsmCrpt_AesKeySizeType p_KeyLength_E,
                       const uint8* const p_IvPtr_pU8, const uint32 p_IvLength_U32, const uint8* const p_AadPtr_pU8,
                       const uint32 p_AadLength_U32, const uint8* const p_MsgPtr_pU8, const uint32 p_MsgLength_U32,
                       const uint8* const p_MacPtr_pU8, const uint32 p_MacLength_U32, const uint32 p_MacBitLength_U32,
                       uint8* const p_VerResultPtr_pU8)
{
    Std_ReturnType l_RetVal_e;
    l_RetVal_e = vHsmCrypt_AesGcmVerifyStart(p_KeyPtr_pU8, p_KeyLength_E, p_IvPtr_pU8, p_IvLength_U32);
    if (E_NOT_OK != l_RetVal_e)
    {
        l_RetVal_e = vHsmCrypt_AesGcmVerifyUpdate(p_AadPtr_pU8, p_AadLength_U32, p_MsgPtr_pU8, p_MsgLength_U32);
        if (E_NOT_OK != l_RetVal_e)
        {
            l_RetVal_e =
                vHsmCrypt_AesGcmVerifyFinish(p_MacPtr_pU8, p_MacLength_U32, p_MacBitLength_U32, p_VerResultPtr_pU8);
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }
    return l_RetVal_e;
}
#endif
#endif /* VHSMCRYPT_AES_ECB_ENABLED */

/*****************************************************************************
 Coverity violations and justifications
 *****************************************************************************/
/* module specific Coverity deviations:
 *
 * 1. unnecessary_header
 * Reason:     Memory Map Files are used to place code and variables in
 *             proper section maps.
 * Risk:       No functional risk.
 * Prevention: Not required.
 *
 */

/* EOF */
