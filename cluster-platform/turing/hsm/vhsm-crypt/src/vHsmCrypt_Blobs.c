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
 * \file vHsmCrypt_Blobs.c
 *
 * \brief
 * Visteon HSM Crypto Blobs Implemetation File
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
 * 
 *****************************************************************************/
#include "vHsmCrypt.h"
#include "sa2ul_rng.h"
#include "tisci_dkek.h"
#include "sec_proxy_minimal.h"
#include "trace.h"
#include "osal_hwi.h"
#include "interrupt.h"
#include "dmsc_irq_map.h"

#define RANDOM_NUMBER_SIZE   (16u)
#define BLOB_KEY_SIZE        (32u)
#define BLOB_HEADER_SIZE     (0x30)
#define BLOB_MAX_SIZE        (0x400)
#define BLOB_HEADER_OFFSET   (0x30)
#define BLOB_TAG_OFFSET      (32)
#define IPC_DKEKINTERRUPT_IRQ               (NVIC_IRQ(HSM_SEC_PROXY_RX_IRQ))
#define EMPTY_FLASH_BYTE      (0x00)
#ifndef MSG_FLAG_AOP
#define MSG_FLAG_AOP    BIT(1)
#endif


#ifdef VHSMCRYPT_BLOBS_ENABLED 

static uint8 l_vHsmCryptRndm_U8A[32] = {0};

const uint8 l_const_BlobIV_U8A[12] = {
		0xca, 0xfe, 0xba, 0xbe, 0xfa, 0xce, 0xdb, 0xad, 0xde,
		0xca, 0xf8, 0x88
	};
const uint8 l_const_BlobAAD_U8A[20] = {
		0xfe, 0xed, 0xfa, 0xce, 0xde, 0xad, 0xbe, 0xef, 0xfe,
		0xed, 0xfa, 0xce, 0xde, 0xad, 0xbe, 0xef, 0xab, 0xad,
		0xda, 0xd2
	};

static uint8 l_vHsmCrypt_BlobDKEK_U8A[32] = {0};
static Std_ReturnType vHsmCrypt_BlobEncr_RndKey(uint8 * p_RndKey_pU8, uint8 * p_EncryptedKey_pU8);
static Std_ReturnType vHsmCrypt_BlobDecr_RndKey(uint8 * p_DecryptedKey_pU8, uint8 * p_RndomKey_pU8);

void vHsmCrypt_DKEK(void)
{
    struct tisci_msg_sa2ul_get_dkek_req vHsmDkek_st;
    struct tisci_msg_sa2ul_get_dkek_resp vHsmDkekres_st;
    s32 fl_retVal_E = SUCCESS;
    uint32 l_RetVal_E = 0;
    uint8 const vHsmDkek_label_Context[] = {0x62,0x6C,0x6F,0x62,0x64,0x6B,0x65,0x6B};
    vHsmDkek_st.hdr.flags = MSG_FLAG_AOP;
    vHsmDkek_st.hdr.seq = 0u;
    vHsmDkek_st.hdr.type = TISCI_MSG_SA2UL_GET_DKEK;
    vHsmDkek_st.sa2ul_instance = 0u;
    vHsmDkek_st.kdf_label_len = 4u;
    vHsmDkek_st.kdf_context_len = 4u;
    (void)memcpy(&vHsmDkek_st.kdf_label_and_context[0],&vHsmDkek_label_Context[0],sizeof(vHsmDkek_label_Context));
    l_RetVal_E = osal_hwip_disable_interrupt(IPC_DKEKINTERRUPT_IRQ);
    if(E_OK == l_RetVal_E)
    {
        fl_retVal_E = sproxy_send_msg(&vHsmDkek_st,sizeof(vHsmDkek_st),0x01);
        if(SUCCESS == fl_retVal_E)
        {
            fl_retVal_E = sproxy_receive_msg(&vHsmDkekres_st,sizeof(vHsmDkekres_st));
            if(SUCCESS == fl_retVal_E)
            {
                (void)memcpy(&l_vHsmCrypt_BlobDKEK_U8A[0],&vHsmDkekres_st.dkek,32);
            }
        }
        (void)osal_hwip_enable_interrupt(IPC_DKEKINTERRUPT_IRQ);
    }
    
}


void vHsmCrypt_BlobRandomKey(void)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    l_RetVal_E = vHsmCrypt_TrngRead(&l_vHsmCryptRndm_U8A[0],BLOB_KEY_SIZE);
    if(E_OK == l_RetVal_E)
    {
        
    }
}

static Std_ReturnType vHsmCrypt_BlobEncr_RndKey(uint8 * p_RndKey_pU8, uint8 * p_EncryptedKey_pU8)
{
    Std_ReturnType l_Retval_E = E_NOT_OK;
    uint32 l_encoutlen = 0;
    l_Retval_E = vHsmCrypt_AesEcbEncrypt(&l_vHsmCrypt_BlobDKEK_U8A[0],BLOB_KEY_SIZE,p_RndKey_pU8,BLOB_KEY_SIZE,p_EncryptedKey_pU8,&l_encoutlen);
    if((E_OK == l_Retval_E) && (BLOB_KEY_SIZE == l_encoutlen))
    {

    }
    else
    {
        l_Retval_E = E_NOT_OK;
    }
    return l_Retval_E;
}

static Std_ReturnType vHsmCrypt_BlobDecr_RndKey(uint8 * p_EncryptedKey_pU8, uint8 * p_RndomKey_pU8)
{
    Std_ReturnType l_Retval_E = E_NOT_OK;
    uint32 l_encoutlen = 0;
    l_Retval_E = vHsmCrypt_AesEcbDecrypt(&l_vHsmCrypt_BlobDKEK_U8A[0],BLOB_KEY_SIZE,p_EncryptedKey_pU8,BLOB_KEY_SIZE,p_RndomKey_pU8,&l_encoutlen);
    if((E_OK == l_Retval_E) && (BLOB_KEY_SIZE == l_encoutlen))
    {
        TRACE_info("\r\n Pass2");
    }
    else
    {
        l_Retval_E = E_NOT_OK;
    }
    return l_Retval_E;
    
}


FUNC(Std_ReturnType,CRYPT_CODE) vHsmCrypt_BlobEncapsulation(uint8 * p_Data_pU8, uint32 p_DataSize, uint8 * p_Blob_pU8, uint32 p_BlobSize)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    uint8 l_RndomKey_U8A[32] = {0};
    uint32 outlen = 0;
    if((NULL != p_Data_pU8) && (NULL != p_Blob_pU8) && ((p_DataSize + BLOB_HEADER_SIZE) <= p_BlobSize) && (p_DataSize < BLOB_MAX_SIZE))
    {
        vHsmCrypt_BlobRandomKey();
        (void)memcpy(&l_RndomKey_U8A[0],&l_vHsmCryptRndm_U8A[0],BLOB_KEY_SIZE);
        l_RetVal_E = vHsmCrypt_AesGcmEncrypt(&l_RndomKey_U8A[0],BLOB_KEY_SIZE,&l_const_BlobIV_U8A[0],sizeof(l_const_BlobIV_U8A),&l_const_BlobAAD_U8A[0],sizeof(l_const_BlobAAD_U8A),p_Data_pU8,p_DataSize,(p_Blob_pU8+BLOB_HEADER_OFFSET),&outlen,(p_Blob_pU8+BLOB_TAG_OFFSET));
        if(E_NOT_OK != l_RetVal_E)
        {
            l_RetVal_E = vHsmCrypt_BlobEncr_RndKey(&l_RndomKey_U8A[0],p_Blob_pU8);
        }
    }
    return l_RetVal_E;
}

FUNC(Std_ReturnType,CRYPT_CODE) vHsmCrypt_BlobDecapsulation(uint8 * p_Blob_pU8, uint32 p_BlobSize,uint8 * p_Data_pU8, uint32 p_DataSize)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    uint8 l_RndomKey_U8A[32] = {0};
    //uint8 i = 0;
    if((NULL != p_Data_pU8) && (NULL != p_Blob_pU8) && ((p_DataSize + BLOB_HEADER_SIZE) <= p_BlobSize) && (p_DataSize < BLOB_MAX_SIZE)) 
    {
        l_RetVal_E = vHsmCrypt_BlobDecr_RndKey(p_Blob_pU8,&l_RndomKey_U8A[0]);
        if(E_NOT_OK != l_RetVal_E)
        {
            l_RetVal_E = vHsmCrypt_AesGcmDecrypt(&l_RndomKey_U8A[0],BLOB_KEY_SIZE,&l_const_BlobIV_U8A[0],sizeof(l_const_BlobIV_U8A),&l_const_BlobAAD_U8A[0],sizeof(l_const_BlobAAD_U8A),p_Blob_pU8+BLOB_HEADER_OFFSET,p_DataSize,p_Data_pU8,p_Blob_pU8+BLOB_TAG_OFFSET,RANDOM_NUMBER_SIZE);
        }
        #if 0
        if(E_OK != l_RetVal_E)
        {
            for (i=0u; (i < p_BlobSize) && (p_Blob_pU8[i] == EMPTY_FLASH_BYTE); i++);
            if (i == p_BlobSize)
            {
                l_RetVal_E = EMPTY_BLOB;
            }
        }
        #endif
    }
    return l_RetVal_E;
}
#endif
/*EOF*/
