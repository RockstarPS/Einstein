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
 * \file vHsmCryptoJobHandler.c
 *
 * \brief
 * Visteon HSM Crypto Manager for Crypto Application support in M0P.
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 30/Jul/'24 | kjohn    | xxxxxx  | Initial version                       |
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          krithik B John           | kjohn     | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "vHsmIpc_Types.h"
#include "vHsmCryptoManager.h"
#include "vHsmIpcHostManager.h"

/******************************************************************************
 *  MACROS
 *****************************************************************************/
#ifndef LOCAL
#define LOCAL static
#endif /* LOCAL */


#define COMMAND_SUCCESS             ((uint8_t)1)
#define COMMAND_FAILURE             ((uint8_t)2)

#define ERASE_COMMAND               ((uint8_t)1)
#define START_REF_COMMAND           ((uint8_t)2)
#define UPDATE_REF_COMMAND          ((uint8_t)3)
#define FINISH_REF_COMMAND          ((uint8_t)4)
#define MAX_TIMEOUT_COUNTER         (50000u)
#define SIZE_OF_AES_KEY             ((uint8_t)16)

/******************************************************************************
 * Static type declarations
 *****************************************************************************/



/*****************************************************************************
 *  PUBLIC FUNCTION IMPLEMENTATIONS
 *****************************************************************************/
/**
 ******************************************************************************
 ** \fn Crypto_Dummy_Function
 **
 ** Dummy function for the unused Crypto jobs
 **
 ** This function returns None
 **
 ** \param [in] uint8_t* cryptodata_addr
 **             uint16_t payload_size
 *****************************************************************************/
FUNC (void, CRY_CODE) Crypto_Dummy_Function(uint8_t* cryptodata_addr,uint16_t payload_size)
{

}

/**
 ******************************************************************************
 ** \fn Command_Dummy_Function
 **
 ** Dummy function for the unused Command jobs
 **
 ** This function returns None
 **
 ** \param [in] uint8_t* commanddata_addr
 **             uint16_t payload_size
 *****************************************************************************/
FUNC (void, CRY_CODE) Command_Dummy_Function(uint8_t* commanddata_addr,uint16_t payload_size)
{

}
FUNC (void, CRY_CODE) IPC_Funct_Message0(uint8_t buffer_id, uint8_t* buffer_add,uint16_t payload_size)
{

}

FUNC (void, CRY_CODE) IPC_Funct_Message1(uint8_t buffer_id, uint8_t* buffer_add,uint16_t payload_size)
{

}
FUNC (void, CRY_CODE) IPC_Funct_Message2(uint8_t buffer_id, uint8_t* buffer_add,uint16_t payload_size)
{

}


FUNC(Std_ReturnType, CRY_CODE)vHsmKey_Store(uint8_t * p_key_pU8, uint16_t p_keySize)
{
    Std_ReturnType l_RetVal_E = E_NOT_OK;
    uint8_t l_CryptoData[32] = {0};
    ts_vHsm_Cryptodata l_vHsmKeySet_st;
    if((NULL != p_key_pU8) && ((32 == p_keySize) || (16 == p_keySize)))
    {
        l_vHsmKeySet_st.jobId_E = CID_3_ASYM_EXTRACT_FN;
        l_vHsmKeySet_st.KeyId_U8 = 10;
        l_vHsmKeySet_st.payLoadPtr_U8P = p_key_pU8;
        l_vHsmKeySet_st.payLoadSize = p_keySize;
        l_vHsmKeySet_st.priority_U8 = 0;
        l_RetVal_E = vHsmCrypto_Manager_SendData(l_vHsmKeySet_st);
        if(E_OK == l_RetVal_E)
        {
            printf(" Key Sent to Hsm for storing\n");
        }
        else
        {
            printf(" Key Sent Failed\n");
        }
    }
    return l_RetVal_E;
}



/* EOF */
