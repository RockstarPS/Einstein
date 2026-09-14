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
 * \file vHsmCrypt_AesEcb.c
 *
 * \brief
 * Visteon HSM Crypto AES Ecb Main Implementation File
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

#if (VHSMCRYPT_AES_ECB_ENABLED == STD_ON)
/******************************************************************************
 *  INTERNAL TYPES
 *****************************************************************************/
/**
 *  \enum te_AesEcb_StateType
 *  \brief Enumeration of general states of cry services.
 *
 *  \var te_AesEcb_StateType::e_AesEcb_Idle
 *  \brief The service is in Finished / Idle State.
 *
 *  \var te_AesEcb_StateType::e_AesEcb_Start
 *  \brief The service has been started.
 *
 *  \var te_AesEcb_StateType::e_AesEcb_Update
 *  \brief The service is in update state.
 *
 */
typedef enum
{
    e_AesEcb_Idle   = 0,
    e_AesEcb_Start  = 1,
    e_AesEcb_Update = 2,
} te_AesEcb_StateType;

/* AES ECB Context*/

LOCAL struct aes_ctx l_aesecbEnc_ctx_st = {0};
LOCAL struct aes_ctx l_aesecbDec_ctx_st = {0};

/******************************************************************************
 *  INTERNAL VARIABLES
 *****************************************************************************/


/**
 ******************************************************************************
 ** \var vHsmCrypt_CurrentEcbEncState_U8
 **
 ** \brief Tracks the current state of the ECB Encryption Engine.
 **
 *****************************************************************************/
LOCAL te_AesEcb_StateType vHsmCrypt_CurrentEcbEncState_U8 = e_AesEcb_Idle;

/**
 ******************************************************************************
 ** \var vHsmCrypt_CurrentEcbDecState_U8
 **
 ** \brief Tracks the current state of the ECB Decryption Engine.
 **
 *****************************************************************************/
LOCAL te_AesEcb_StateType vHsmCrypt_CurrentEcbDecState_U8 = e_AesEcb_Idle;


/******************************************************************************
 *  PUBLIC FUNCTION IMPLEMENTATIONS
 *****************************************************************************/


FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesEcbEncryptStart(const uint8* const p_KeyPtr_pU8, const uint8 p_KeyLength_E)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_E;
    uint8 p_keyLength = 0;
    if ((NULL_PTR != p_KeyPtr_pU8) &&
        ((vHSMCRYPT_AES192KEY_SIZE == p_KeyLength_E) || (vHSMCRYPT_AES128KEY_SIZE == p_KeyLength_E) ||
         (vHSMCRYPT_AES256KEY_SIZE == p_KeyLength_E)) &&
        (e_AesEcb_Idle == vHsmCrypt_CurrentEcbEncState_U8))
    {
        p_keyLength = p_KeyLength_E;
        (void)memcpy((uint8 *)l_aesecbEnc_ctx_st.key_1,p_KeyPtr_pU8,p_keyLength);
        l_aesecbEnc_ctx_st.op_key_size = AES_KEYLEN(p_keyLength) | AES_OP_ENCRYPT;
        l_aesecbEnc_ctx_st.mode = AES_MODE_ECB;
        fl_RetVal_E = aes_init(&l_aesecbEnc_ctx_st);
        if(fl_RetVal_E == EFTOK)
        {
            vHsmCrypt_CurrentEcbEncState_U8 = e_AesEcb_Start;
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
vHsmCrypt_AesEcbEncryptUpdate(const uint8* const p_PlainTextPtr_pU8, const uint32 p_TextLength_U32,
                              uint8* const p_CipherTextPtr_pU8, uint32* p_CipherLengthPtr)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_E;
    if ((NULL_PTR != p_PlainTextPtr_pU8) && (NULL_PTR != p_CipherTextPtr_pU8) && (p_CipherLengthPtr != NULL_PTR) &&
        (0UL == (p_TextLength_U32 % VHSMCRYPT_HALF_WORD_SIZE)) &&
        ((e_AesEcb_Start == vHsmCrypt_CurrentEcbEncState_U8) || (e_AesEcb_Update == vHsmCrypt_CurrentEcbEncState_U8)))
    {
        fl_RetVal_E = aes_update(&l_aesecbEnc_ctx_st,p_PlainTextPtr_pU8,p_TextLength_U32,p_CipherTextPtr_pU8,p_CipherLengthPtr);
        if(EFTOK == fl_RetVal_E)
        {
            vHsmCrypt_CurrentEcbEncState_U8 = e_AesEcb_Update;
            l_RetVal_e = E_OK;
        }
    }
    else
    {
        /* Do Nothing */
    }
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_AesEcbEncryptFinish(uint8* p_CipherTextPtr_pU8, uint32* p_CipherLengthPtr)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_E;
    if ((e_AesEcb_Update == vHsmCrypt_CurrentEcbEncState_U8) && (NULL_PTR != p_CipherTextPtr_pU8) && (NULL_PTR != p_CipherLengthPtr))
    {
        fl_RetVal_E = aes_final(&l_aesecbEnc_ctx_st,p_CipherTextPtr_pU8,p_CipherLengthPtr);
        if(EFTOK == fl_RetVal_E)
        {
            vHsmCrypt_CurrentEcbEncState_U8 = e_AesEcb_Idle;
            l_RetVal_e = E_OK;
        }
    }
    else
    {
        /* Do Nothing */
    }
    (void)memset(&l_aesecbEnc_ctx_st,0x00,sizeof(l_aesecbEnc_ctx_st));
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_AesEcbEncryptCancel(void)
{
    vHsmCrypt_CurrentEcbEncState_U8 = e_AesEcb_Idle;
    (void)memset(&l_aesecbEnc_ctx_st,0x00,sizeof(l_aesecbEnc_ctx_st));
    return E_OK;
}

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesEcbEncrypt(const uint8* const p_KeyPtr_pU8, const uint8 p_KeyLength_E,
                        const uint8* const p_PlainTextPtr_pU8, const uint32 p_TextLength_U32,
                        uint8* const p_CipherTextPtr_pU8, uint32* p_CipherLengthPtr)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_E;
    uint8 p_keyLength = 0;
    if ((NULL_PTR != p_KeyPtr_pU8) &&
        ((vHSMCRYPT_AES256KEY_SIZE == p_KeyLength_E) || (vHSMCRYPT_AES192KEY_SIZE == p_KeyLength_E) ||
         (vHSMCRYPT_AES128KEY_SIZE == p_KeyLength_E)) && 
         (NULL_PTR != p_PlainTextPtr_pU8) && (NULL_PTR != p_CipherTextPtr_pU8) && (NULL_PTR != p_CipherLengthPtr) &&
        (0UL == (p_TextLength_U32 % VHSMCRYPT_HALF_WORD_SIZE)))     
    {
        p_keyLength = p_KeyLength_E;
        (void)memset(&l_aesecbEnc_ctx_st,0x00,sizeof(l_aesecbEnc_ctx_st));
        (void)memcpy((uint8 *)l_aesecbEnc_ctx_st.key_1,p_KeyPtr_pU8,p_keyLength);
        l_aesecbEnc_ctx_st.op_key_size = AES_KEYLEN(p_keyLength) | AES_OP_ENCRYPT;
        l_aesecbEnc_ctx_st.mode = AES_MODE_ECB;
        fl_RetVal_E =  aes_oneshot(&l_aesecbEnc_ctx_st,p_PlainTextPtr_pU8,p_TextLength_U32,p_CipherTextPtr_pU8,p_CipherLengthPtr);
        if(EFTOK == fl_RetVal_E)
        {
            l_RetVal_e = E_OK;
        }
    }
    else
    {
        /* Do Nothing */
    }   
    (void)memset(&l_aesecbEnc_ctx_st,0x00,sizeof(l_aesecbEnc_ctx_st));
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesEcbDecryptStart(const uint8* const p_DecrKeyPtr_pU8, const uint8 p_DecrKeyLength_E)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_E;
    uint8 p_keyLength = 0;
    if ((NULL_PTR != p_DecrKeyPtr_pU8) &&
        ((vHSMCRYPT_AES256KEY_SIZE == p_DecrKeyLength_E) ||
         (vHSMCRYPT_AES192KEY_SIZE == p_DecrKeyLength_E) ||
         (vHSMCRYPT_AES128KEY_SIZE == p_DecrKeyLength_E)) &&
        (e_AesEcb_Idle == vHsmCrypt_CurrentEcbDecState_U8))
    {
        p_keyLength = p_DecrKeyLength_E;
        (void)memcpy((uint8 *)l_aesecbDec_ctx_st.key_1,p_DecrKeyPtr_pU8,p_keyLength);
        l_aesecbDec_ctx_st.op_key_size = AES_KEYLEN(p_keyLength) | AES_OP_DECRYPT;
        l_aesecbDec_ctx_st.mode = AES_MODE_ECB;
        fl_RetVal_E = aes_init(&l_aesecbDec_ctx_st);
        if(EFTOK == fl_RetVal_E)
        {
            vHsmCrypt_CurrentEcbDecState_U8 = e_AesEcb_Start;
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
vHsmCrypt_AesEcbDecryptUpdate(const uint8* const p_CipherTextPtr_pU8, const uint32 p_TextLength_U32,
                              uint8* const p_PlainTextPtr_pU8, uint32* p_plainTextLengthPtr_pU32)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_E;
    if ((NULL_PTR != p_PlainTextPtr_pU8) && (NULL_PTR != p_CipherTextPtr_pU8) && (NULL_PTR != p_plainTextLengthPtr_pU32) &&
        (0UL == (p_TextLength_U32 % VHSMCRYPT_HALF_WORD_SIZE)) &&
        ((e_AesEcb_Start == vHsmCrypt_CurrentEcbDecState_U8) || (e_AesEcb_Update == vHsmCrypt_CurrentEcbDecState_U8)))
    {
        fl_RetVal_E = aes_update(&l_aesecbDec_ctx_st,p_CipherTextPtr_pU8,p_TextLength_U32,p_PlainTextPtr_pU8,p_plainTextLengthPtr_pU32);
        if(fl_RetVal_E == EFTOK)
        {
            vHsmCrypt_CurrentEcbDecState_U8 = e_AesEcb_Update;
            l_RetVal_e = E_OK;
        }
    }
    else
    {
        /* Do Nothing */
    }
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_AesEcbDecryptFinish(uint8* p_PlainTextPtr_pU8, uint32* p_plainTextLengthPtr_pU32)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_E;
    if ((e_AesEcb_Update == vHsmCrypt_CurrentEcbDecState_U8) && (NULL_PTR != p_PlainTextPtr_pU8) && (NULL_PTR != p_plainTextLengthPtr_pU32))
    {
        fl_RetVal_E = aes_final(&l_aesecbDec_ctx_st,p_PlainTextPtr_pU8,p_plainTextLengthPtr_pU32);
        if(EFTOK == fl_RetVal_E)
        {
            vHsmCrypt_CurrentEcbDecState_U8 = e_AesEcb_Idle;
            l_RetVal_e = E_OK;
        }
    }
    else
    {
        /* Do Nothing */
    }
    (void)memset(&l_aesecbDec_ctx_st,0x00,sizeof(l_aesecbDec_ctx_st));
    return l_RetVal_e;
}

FUNC(Std_ReturnType, CRYPT_CODE) vHsmCrypt_AesEcbDecryptCancel(void)
{
    vHsmCrypt_CurrentEcbDecState_U8 = e_AesEcb_Idle;
    (void)memset(&l_aesecbDec_ctx_st,0x00,sizeof(l_aesecbDec_ctx_st));
    return E_OK;        
}

FUNC(Std_ReturnType, CRYPT_CODE)
vHsmCrypt_AesEcbDecrypt(const uint8* const p_DecrKeyPtr_pU8, const uint8 p_DecrKeyLength_E,
                        const uint8* const p_CipherTextPtr_pU8, const uint32 p_TextLength_U32,
                        uint8* const p_PlainTextPtr_pU8, uint32* p_plainTextLengthPtr_pU32)
{
    Std_ReturnType l_RetVal_e = E_NOT_OK;
    fterr fl_RetVal_E;
    uint8 p_keyLength = 0;
    if(((vHSMCRYPT_AES256KEY_SIZE == p_DecrKeyLength_E) ||
       (vHSMCRYPT_AES192KEY_SIZE == p_DecrKeyLength_E) ||
       (vHSMCRYPT_AES128KEY_SIZE == p_DecrKeyLength_E)) && 
       (NULL_PTR != p_DecrKeyPtr_pU8) && (NULL_PTR != p_PlainTextPtr_pU8) && (NULL_PTR != p_plainTextLengthPtr_pU32) &&
       (NULL_PTR != p_CipherTextPtr_pU8) &&
       (0UL == (p_TextLength_U32 % VHSMCRYPT_HALF_WORD_SIZE)))
    {
        p_keyLength = p_DecrKeyLength_E;
        (void)memset(&l_aesecbDec_ctx_st,0x00,sizeof(l_aesecbDec_ctx_st));
        (void)memcpy((uint8 *)l_aesecbDec_ctx_st.key_1,p_DecrKeyPtr_pU8,p_keyLength);
        l_aesecbDec_ctx_st.op_key_size = AES_KEYLEN(p_keyLength) | AES_OP_DECRYPT;
        l_aesecbDec_ctx_st.mode = AES_MODE_ECB;
        fl_RetVal_E= aes_oneshot(&l_aesecbDec_ctx_st,p_CipherTextPtr_pU8,p_TextLength_U32,p_PlainTextPtr_pU8,p_plainTextLengthPtr_pU32);
        if(EFTOK == fl_RetVal_E)
        {
            l_RetVal_e = E_OK;
        }  
    }
    else
    {
        /* Do Nothing */
    } 
    (void)memset(&l_aesecbDec_ctx_st,0x00,sizeof(l_aesecbDec_ctx_st));       
    return l_RetVal_e;
}


#endif /* VHSMCRYPT_AES_ECB_ENABLED */


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
