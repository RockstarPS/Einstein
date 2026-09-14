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
 * \file vHsmCrypt_AesCbc.c
 *
 * \brief
 * Visteon HSM Crypto AES CBC Main Implementation File
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

#if (VHSMCRYPT_AES_CBC_ENABLED == STD_ON)
/******************************************************************************
 *  INTERNAL TYPES
 *****************************************************************************/
/**
 *  \enum te_AesCbc_StateType
 *  \brief Enumeration of general states of cry services.
 *
 *  \var te_AesCbc_StateType::e_AesCbc_Idle
 *  \brief The service is in Finished / Idle State.
 *
 *  \var te_AesCbc_StateType::e_AesCbc_Start
 *  \brief The service has been started.
 *
 *  \var te_AesCbc_StateType::e_AesCbc_Update
 *  \brief The service is in update state.
 *
 */
typedef enum
{
    e_AesCbc_Idle   = 0,
    e_AesCbc_Start  = 1,
    e_AesCbc_Update = 2,
} te_AesCbc_StateType;

/* AES CBC Context*/

LOCAL struct aes_ctx l_aescbcEnc_ctx_st = {0};
LOCAL struct aes_ctx l_aescbcDec_ctx_st = {0};

/******************************************************************************
 *  INTERNAL VARIABLES
 *****************************************************************************/


/**
 ******************************************************************************
 ** \var vHsmCrypt_CurrentCbcEncState_U8
 **
 ** \brief Tracks the current state of the CBC Encryption Engine.
 **
 *****************************************************************************/
LOCAL te_AesCbc_StateType vHsmCrypt_CurrentCbcEncState_U8 = e_AesCbc_Idle;

/**
 ******************************************************************************
 ** \var vHsmCrypt_CurrentCbcDecState_U8
 **
 ** \brief Tracks the current state of the CBC Decryption Engine.
 **
 *****************************************************************************/
LOCAL te_AesCbc_StateType vHsmCrypt_CurrentCbcDecState_U8 = e_AesCbc_Idle;



/******************************************************************************
 *  PUBLIC FUNCTION IMPLEMENTATIONS
 *****************************************************************************/

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesCbcEncryptStart(const uint8* p_KeyPtr_pU8, const uint8 p_KeyLength_E,
                             const uint8* p_InitialVectorPtr_pU8, const uint8 p_InitialVectorLength_E)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_E = EFTOK;
    const uint8 VecLength = p_InitialVectorLength_E;
    uint8 keyLength = p_KeyLength_E;
    if ((NULL_PTR != p_KeyPtr_pU8) &&
        ((vHSMCRYPT_AES128KEY_SIZE == p_KeyLength_E) || (vHSMCRYPT_AES192KEY_SIZE == p_KeyLength_E) ||
         (vHSMCRYPT_AES256KEY_SIZE == p_KeyLength_E)) &&
        (e_AesCbc_Idle == vHsmCrypt_CurrentCbcEncState_U8) && (p_InitialVectorPtr_pU8 != NULL_PTR) &&
        (vHSMCRYPT_AES128KEY_SIZE == p_InitialVectorLength_E))
    {
        (void)memcpy(l_aescbcEnc_ctx_st.iv,p_InitialVectorPtr_pU8,VecLength);
        (void)memcpy((uint8 *)l_aescbcEnc_ctx_st.key_1,p_KeyPtr_pU8,keyLength);
        l_aescbcEnc_ctx_st.op_key_size = AES_KEYLEN(keyLength) | AES_OP_ENCRYPT;
        l_aescbcEnc_ctx_st.mode = AES_MODE_CBC;
        fl_RetVal_E = aes_init(&l_aescbcEnc_ctx_st);
        if(fl_RetVal_E == EFTOK)
        {
            vHsmCrypt_CurrentCbcEncState_U8 = e_AesCbc_Start;
            l_RetVal_e = E_OK;
        }
    }
    else
    {
        /* Do Nothing */
    }
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesCbcEncryptUpdate(const uint8* p_PlainTextPtr_pU8, const uint32 p_TextLength_U32,
                              uint8* p_CipherTextPtr_pU8, uint32* p_CipherLengthPtr)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_E = EFTOK;
    if ((NULL_PTR != p_PlainTextPtr_pU8) && (NULL_PTR != p_CipherTextPtr_pU8) &&
        (0UL == (p_TextLength_U32 % VHSMCRYPT_HALF_WORD_SIZE)) &&
        ((e_AesCbc_Start == vHsmCrypt_CurrentCbcEncState_U8) || (e_AesCbc_Update == vHsmCrypt_CurrentCbcEncState_U8)))
    {
        fl_RetVal_E = aes_update(&l_aescbcEnc_ctx_st,p_PlainTextPtr_pU8,p_TextLength_U32,p_CipherTextPtr_pU8,p_CipherLengthPtr);
        if(EFTOK == fl_RetVal_E)
        {
            vHsmCrypt_CurrentCbcEncState_U8 = e_AesCbc_Update;
            l_RetVal_e = E_OK;
        }
    }
    else
    {
        /* Do Nothing */
    }
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_AesCbcEncryptFinish(uint8* p_CipherTextPtr_pU8, uint32* p_CipherLengthPtr)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_E;
    if ((e_AesCbc_Update == vHsmCrypt_CurrentCbcEncState_U8) && (NULL_PTR != p_CipherTextPtr_pU8) && (NULL_PTR != p_CipherLengthPtr))
    {
        fl_RetVal_E = aes_final(&l_aescbcEnc_ctx_st,p_CipherTextPtr_pU8,p_CipherLengthPtr);
        if(EFTOK == fl_RetVal_E)
        {
            vHsmCrypt_CurrentCbcEncState_U8 = e_AesCbc_Idle;
            l_RetVal_e = E_OK;
        }
    }
    else
    {
        /* Do Nothing */
    }
    (void)memset(&l_aescbcEnc_ctx_st,0x00,sizeof(l_aescbcEnc_ctx_st));
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_AesCbcEncryptCancel(void)
{
    vHsmCrypt_CurrentCbcEncState_U8 = e_AesCbc_Idle;
    (void)memset(&l_aescbcEnc_ctx_st,0x00,sizeof(l_aescbcEnc_ctx_st));
    return E_OK;
}

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesCbcEncrypt(const uint8* p_KeyPtr_pU8, const uint8 p_KeyLength_E,
                        const uint8* p_InitialVectorPtr_pU8, const uint8 p_InitialVectorLength_E,
                        const uint8* p_PlainTextPtr_pU8, const uint32 p_TextLength_U32, uint8* p_CipherTextPtr_pU8, uint32* p_CipherLengthPtr)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_E;
    const uint8 VecLength = p_InitialVectorLength_E;
    uint8 keyLength = p_KeyLength_E;
    if ((NULL_PTR != p_KeyPtr_pU8) &&
        ((vHSMCRYPT_AES128KEY_SIZE == p_KeyLength_E) || (vHSMCRYPT_AES192KEY_SIZE == p_KeyLength_E) ||
         (vHSMCRYPT_AES256KEY_SIZE == p_KeyLength_E)) && (p_InitialVectorPtr_pU8 != NULL_PTR) &&
        (vHSMCRYPT_AES128KEY_SIZE == p_InitialVectorLength_E) && (NULL_PTR != p_PlainTextPtr_pU8) && (NULL_PTR != p_CipherTextPtr_pU8) &&
        (0UL == (p_TextLength_U32 % VHSMCRYPT_HALF_WORD_SIZE)) && (NULL_PTR != p_CipherTextPtr_pU8) && (NULL_PTR != p_CipherLengthPtr) && (e_AesCbc_Idle == vHsmCrypt_CurrentCbcEncState_U8))
    {
        (void)memcpy(l_aescbcEnc_ctx_st.iv,p_InitialVectorPtr_pU8,VecLength);
        (void)memcpy((uint8 *)l_aescbcEnc_ctx_st.key_1,p_KeyPtr_pU8,keyLength);
        l_aescbcEnc_ctx_st.op_key_size = AES_KEYLEN(keyLength) | AES_OP_ENCRYPT;
        l_aescbcEnc_ctx_st.mode = AES_MODE_CBC;
        fl_RetVal_E = aes_oneshot(&l_aescbcEnc_ctx_st,p_PlainTextPtr_pU8,p_TextLength_U32,p_CipherTextPtr_pU8,p_CipherLengthPtr);
        if(EFTOK == fl_RetVal_E)
        {
            l_RetVal_e = E_OK;
        }
    }
    else
    {
        /* Do Nothing */
    }
    (void)memset(&l_aescbcEnc_ctx_st,0x00,sizeof(l_aescbcEnc_ctx_st));
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesCbcDecryptStart(const uint8* p_DecrKeyPtr_pU8, const uint8 p_DecrKeyLength_E,
                             const uint8* p_InitialVectorPtr_pU8, const uint8 p_InitialVectorLength_E)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_E;
    const uint8 VecLength = p_InitialVectorLength_E;
    uint8 keyLength = p_DecrKeyLength_E;
    if ((NULL_PTR != p_DecrKeyPtr_pU8) &&
        ((vHSMCRYPT_AES128KEY_SIZE == p_DecrKeyLength_E) ||
         (vHSMCRYPT_AES192KEY_SIZE == p_DecrKeyLength_E) ||
         (vHSMCRYPT_AES256KEY_SIZE == p_DecrKeyLength_E)) &&
        (e_AesCbc_Idle == vHsmCrypt_CurrentCbcDecState_U8) &&
        (vHSMCRYPT_AES128KEY_SIZE == p_InitialVectorLength_E))
    {
        (void)memcpy(l_aescbcDec_ctx_st.iv,p_InitialVectorPtr_pU8,VecLength);
        (void)memcpy((uint8 *)l_aescbcDec_ctx_st.key_1,p_DecrKeyPtr_pU8,keyLength);
        l_aescbcDec_ctx_st.op_key_size = AES_KEYLEN(keyLength )| AES_OP_DECRYPT;
        l_aescbcDec_ctx_st.mode = AES_MODE_CBC;
        fl_RetVal_E = aes_init(&l_aescbcDec_ctx_st);
        if( EFTOK == fl_RetVal_E)
        {
            vHsmCrypt_CurrentCbcDecState_U8 = e_AesCbc_Start;
            l_RetVal_e = E_OK;
        }
    }
    else
    {
        /* Do Nothing */
    }
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesCbcDecryptUpdate(const uint8* p_CipherTextPtr_pU8, const uint32 p_TextLength_U32,
                              uint8* p_PlainTextPtr_pU8, uint32* p_plainTextLengthPtr_pU32)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_E;
    if ((NULL_PTR != p_PlainTextPtr_pU8) && (NULL_PTR != p_CipherTextPtr_pU8) &&
        (0UL == (p_TextLength_U32 % VHSMCRYPT_HALF_WORD_SIZE)) &&
        ((e_AesCbc_Start == vHsmCrypt_CurrentCbcDecState_U8) || (e_AesCbc_Update == vHsmCrypt_CurrentCbcDecState_U8)))
    {  
        fl_RetVal_E = aes_update(&l_aescbcDec_ctx_st,p_CipherTextPtr_pU8,p_TextLength_U32,p_PlainTextPtr_pU8,p_plainTextLengthPtr_pU32);
        if(EFTOK == fl_RetVal_E)
        {
            vHsmCrypt_CurrentCbcDecState_U8 = e_AesCbc_Update;
            l_RetVal_e = E_OK;
        }
    }
    else
    {
        /* Do Nothing */
    }
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_AesCbcDecryptFinish(uint8* p_PlainTextPtr_pU8, uint32* p_plainTextLengthPtr_pU32)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_E;
    if ((e_AesCbc_Update == vHsmCrypt_CurrentCbcDecState_U8) && (NULL_PTR != p_PlainTextPtr_pU8) && (NULL_PTR != p_plainTextLengthPtr_pU32))
    {
        fl_RetVal_E = aes_final(&l_aescbcDec_ctx_st,p_PlainTextPtr_pU8,p_plainTextLengthPtr_pU32);
        if(EFTOK == fl_RetVal_E)
        {
            vHsmCrypt_CurrentCbcDecState_U8 = e_AesCbc_Idle;
            l_RetVal_e = E_OK;
        }
    }
    else
    {
        /* Do Nothing */
    }
    (void)memset(&l_aescbcDec_ctx_st,0x00,sizeof(l_aescbcDec_ctx_st));
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_AesCbcDecryptCancel(void)
{
    vHsmCrypt_CurrentCbcDecState_U8 = e_AesCbc_Idle;
    (void)memset(&l_aescbcDec_ctx_st,0x00,sizeof(l_aescbcDec_ctx_st));
    return E_OK;
}

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesCbcDecrypt(const uint8* p_DecrKeyPtr_pU8, const uint8  p_DecrKeyLength_E,
                        const uint8* p_InitialVectorPtr_pU8, const uint8  p_InitialVectorLength_E,
                        const uint8* p_CipherTextPtr_pU8, const uint32 p_TextLength_U32, uint8* p_PlainTextPtr_pU8, uint32* p_plainTextLengthPtr_pU32)
{
    Std_ReturnType l_RetVal_e;
    l_RetVal_e = vHsmCrypt_AesCbcDecryptStart(p_DecrKeyPtr_pU8, p_DecrKeyLength_E, p_InitialVectorPtr_pU8,
                                              p_InitialVectorLength_E);
    if (E_NOT_OK != l_RetVal_e)
    {
        l_RetVal_e = vHsmCrypt_AesCbcDecryptUpdate(p_CipherTextPtr_pU8, p_TextLength_U32, p_PlainTextPtr_pU8,p_plainTextLengthPtr_pU32);
        if (E_NOT_OK != l_RetVal_e)
        {
            l_RetVal_e = vHsmCrypt_AesCbcDecryptFinish(p_PlainTextPtr_pU8,p_plainTextLengthPtr_pU32);
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


#endif /* VHSMCRYPT_AES_CBC_ENABLED */


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
