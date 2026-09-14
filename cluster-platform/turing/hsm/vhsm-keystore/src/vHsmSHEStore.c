/***************************************************************************
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
 * \file vHsmSHEStore.c
 *
 * \brief
 * Visteon HSM Key Store for SHE keys TI AM62Px 
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Sree Divya Vetcha        | svetcha   | VTSC, Bengaluru, India
 *          Krithik B John           | kjohn     | VTSC, Bengaluru, India
 ******************************************************************************/
#include "Std_Types.h"
#include "vHsmCrypt.h"

#define SHE_CONTAINER_LEN  64u
#define SHE_RAMKEY_SIZE    16u
#define SHE_M1_OFFSET      0u
#define SHE_M1_SIZE        16u
#define SHE_M2_OFFSET      16u
#define SHE_M2_SIZE        32u
#define SHE_M3_OFFSET      48u
#define SHE_M3_SIZE        16u
#define SHE_AUTHID_OFFSET  15u

/*Constants used in SHE*/
const uint8 c_vHsmSHE_KeyUpdateEnc_C_U8A[16]={0x01,0x01,0x53,0x48,0x45,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xb0};
const uint8 c_vHsmSHE_KeyUpdateMac_C_U8A[16]={0x01,0x02,0x53,0x48,0x45,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xb0};
const uint8 c_vHsmSHE_DefaultAuthKey_C_U8A[16] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

typedef struct
{
    uint32 counter; /*counter for Key*/
    uint8 keyId; /*KeyId*/
    uint8 flag; /*Key flag*/
    uint8 authId; /*Authentication KeyId*/
    uint8 key[SHE_RAMKEY_SIZE]; /*Key payload*/
}ts_vHsmSHEKey;


typedef enum
{
    e_SHEIdle = 0,
    e_SHEProcessing = 1,
}te_vHsmSHEState;

/*Local Variables*/
static uint8 l_keySlot_U8;
static te_vHsmSHEState l_vHsmSHEstate_e;
static uint8 l_vHsmSHE_M1M2M3_U8A[SHE_CONTAINER_LEN] = {0};
static uint8 l_Ram_PlainKey_U8A[16] = {0};
static ts_vHsmSHEKey l_CurrentKey_st = {0};
static ts_vHsmSHEKey * l_StoredAuthkey_st = NULL;
static ts_vHsmSHEKey * l_Storedkey_st = NULL;
static uint8 l_vHsmSHE_KeyDeriveKey_U8A[16] = {0};

void vHsmSHEStore_Init(void)
{
    l_keySlot_U8 = 0u;
    l_vHsmSHEstate_e = e_SHEIdle;
}

Std_ReturnType vHsmSHE_SetKeySlot(uint8 keySlot)
{
    Std_ReturnType retVal = E_NOT_OK;
    if(keySlot ) /*check key slot in SHE*/
    {
        l_keySlot_U8 = keySlot;
        retVal = E_OK;
    }
    return retVal;
}
Std_ReturnType vHsmSHE_Download(const uint8 * container_pU8, uint16 payload_size) /* M1|M2|M3 */
{
    Std_ReturnType retVal = E_NOT_OK;
    uint8 derivedKeyK1_U8A[16] = {0};
    uint8 derivedKeyK2_U8A[16] = {0};
    uint32 cmacVerPtr_p8 = 0u;
    uint8 UidWildcard_U8A[15] = {0};
    uint8 IVCbcDecrypt_U8A[16] ={0};
    uint8 M2Decrypted_U8A[32] = {0};
    uint32 M2size_U32 = SHE_M2_SIZE;
    if((NULL != container_pU8) && (SHE_CONTAINER_LEN >= payload_size) && (e_SHEIdle == l_vHsmSHEstate_e)) /*Sanity checking*/
    {
        if(SHE_RAMKEY_SIZE == payload_size)
        {
            (void)memcpy(&l_Ram_PlainKey_U8A[0],SHE_RAMKEY_SIZE);
            retVal = E_OK;
        }
        else
        {
            l_vHsmSHEstate_e = e_SHEProcessing;
            (void)memcpy(&l_vHsmSHE_M1M2M3_U8A[0],container_pU8,SHE_CONTAINER_LEN);
            l_CurrentKey_st.authId = l_vHsmSHE_M1M2M3_U8A[SHE_AUTHID_OFFSET] & 0x0Fu; /*Auth ID decode*/
            l_CurrentKey_st.keyId = (l_vHsmSHE_M1M2M3_U8A[SHE_AUTHID_OFFSET] >> 4u) & 0x0Fu; /*decode New KeyId*/
            l_StoredAuthkey_st = vHsmSHEGetKey(l_CurrentKey_st.authId);
            if(NULL == l_StoredAuthkey_st)
            {
                (void)memcpy(&l_StoredAuthkey_st->key[0],&c_vHsmSHE_DefaultAuthKey_C_U8A[0],SHE_RAMKEY_SIZE);
                #if 0
                if(l_CurrentKey_st.authId == l_CurrentKey_st.keyId)
                {

                }
                else
                {
                    /*Log Error*/
                }
                #endif
            }
            /*find K2*/
            retVal = vHsmSHE_KeyDerive(&l_StoredAuthkey_st->key[0],&c_vHsmSHE_KeyUpdateMac_C_U8A[0],&derivedKeyK2_U8A[0]);
            if(E_OK == retVal)
            {
                /*verify M3*/
                retVal = vHsmCrypt_AesCmacVerify(&derivedKeyK2_U8A[0],SHE_RAMKEY_SIZE,&l_vHsmSHE_M1M2M3_U8A[0],(SHE_M1_SIZE+SHE_M2_SIZE),&l_vHsmSHE_M1M2M3_U8A[SHE_M3_OFFSET],128u,&cmacVerPtr_p8);
                if((E_OK == retVal) && (0u == cmacVerPtr_p8))
                {
                    l_Storedkey_st = vHsmSHEGetKey(l_CurrentKey_st.keyId);
                    if(NULL == l_Storedkey_st)
                    {
                        l_Storedkey_st->flag = 0x0u;
                    }
                    if(0 == memcmp(&l_vHsmSHE_M1M2M3_U8A[0],&UidWildcard_U8A[0],15u))
                    {
                        if((l_Storedkey_st->flag & 0x1u) == 0x01u)
                        {
                            retVal = ERC_KEY_UPDATE_ERROR;
                        }
                    }
                    else
                    {
                        /*Read UID and match it with that on DLC*/
                        if(UID matches)
                        {

                        }
                        else
                        {
                            retVal = ERC_KEY_UPDATE_ERROR;
                        }

                    }
                }

            }
            if(E_OK == retVal)
            {
                /*find K1*/
                retVal = vHsmSHE_KeyDerive(&l_StoredAuthkey_st->key[0],&c_vHsmSHE_KeyUpdateEnc_C_U8A[0],&derivedKeyK1_U8A[0]);
                if(E_OK == retVal)
                {
                    retVal = vHsmCrypt_AesCbcDecrypt(&derivedKeyK1_U8A[0],SHE_RAMKEY_SIZE,&IVCbcDecrypt_U8A[0],SHE_RAMKEY_SIZE,&l_vHsmSHE_M1M2M3_U8A[SHE_M2_OFFSET],SHE_M2_SIZE,&M2Decrypted_U8A[0],&M2size_U32);
                    if(E_OK == retVal)
                    {
                        l_CurrentKey_st.flag = (M2Decrypted_U8A[4u] >> 7u) & (cByte1);
                        l_CurrentKey_st.flag |= (((M2Decrypted_U8A[3u]) & (cByte0F)) << 1u);
                        l_CurrentKey_st.counter = ((M2Decrypted_U8A[3u] >> 4u) & (cByte0F));
                        l_CurrentKey_st.counter |= ((M2Decrypted_U8A[0u]) << 20u);
                        l_CurrentKey_st.counter |= ((M2Decrypted_U8A[1u]) << 12u);
                        l_CurrentKey_st.counter |= ((M2Decrypted_U8A[2u]) << 4u);
                        if(l_CurrentKey_st.counter > l_Storedkey_st->counter)
                        {
                            /*state mahcine to write*/
                        }
                        else
                        {
                            retVal = ERC_KEY_UPDATE_ERROR;
                        }
                    }
                    else
                    {
                        retVal = ERC_KEY_UPDATE_ERROR;
                    }
                }
            }
            
            if()/*check write protection of the slot from memory or const*/
            {

            }
            else
            {
                retVal = /*ERC_WRITE_PROTECTED*/
            }
            if(retVal != E_NOT_OK)
            {
                l_vHsmSHEstate_e = e_SHEIdle;
            }
        }
    }
    return retVal;
}

ts_vHsmSHEKey * vHsmSHEGetKey(uint8 keyId)
{
    return NULL;
}

Std_ReturnType vHsmSHE_KeyDerive(const uint8 * AuthKey_pU8, const uint8* Const_pU8,uint8 * Derivedkey_pU8)
{
    Std_ReturnType retVal = E_NOT_OK;
    if((NULL != AuthKey_pU8) && (NULL != Const_pU8) && (NULL != Derivedkey_pU8))
    {
        (void)memset(&l_vHsmSHE_KeyDeriveKey_U8A[0],0x00u,SHE_RAMKEY_SIZE);
        retVal = vHsmSHE_MPCompression(AuthKey_pU8,Derivedkey_pU8);
        if(E_OK == retVal)
        {
            (void)memcpy(&l_vHsmSHE_KeyDeriveKey_U8A[0],Derivedkey_pU8,SHE_RAMKEY_SIZE);
            retVal = vHsmSHE_MPCompression(Const_pU8,Derivedkey_pU8);
        }
    }
    return retVal;
}

Std_ReturnType vHsmSHE_MPCompression(const uint8 * Key_pU8,uint8 * CompKey_pU8)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 Index_U8 = 0u;
    uint32 DerivationLeng_U32 = 16u;
    uint8 DerivedKey_U8A[16] = {0};
    if((Key_pU8 != NULL) && (CompKey_pU8 != NULL))
    {
        RetVal = vHsmCrypt_AesEcbEncrypt(&l_vHsmSHE_KeyDeriveKey_U8A[0],SHE_RAMKEY_SIZE,Key_pU8,SHE_RAMKEY_SIZE,&DerivedKey_U8A[0],&DerivationLeng_U32);
        if(E_OK == RetVal)
        {
            for(Index_U8 = 0u;Index_U8<SHE_RAMKEY_SIZE;Index_U8++)
            {
                DerivedKey_U8A[Index_U8] = DerivedKey_U8A[Index_U8] ^ Key_pU8[Index_U8];
                CompKey_pU8[Index_U8] = CompKey_pU8[Index_U8] ^ DerivedKey_U8A[Index_U8];
            }
        }
    }
    return RetVal;
}
/*EOF*/