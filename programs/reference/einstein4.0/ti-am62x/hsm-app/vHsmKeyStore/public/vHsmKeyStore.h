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
 * \file vHsmKeyStore.h
 *
 * \brief
 * Visteon HSM Key Store for symmetric and assymetric keys for TI AM62Px Header File
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 *          Krithik B John           | kjohn     | VTSC, Chennai, India
 ******************************************************************************/
#include "Std_Types.h"
#include "string.h"

/**
 *********************************************************************************************
 ** \fn        vHsmKeyStore_SetKey
 **
 ** \brief     Set the Key to given Key Slot.
 **
 ** \details   Function will Set given key material to key Slot.
 **
 ** \param[in] keyId         KeyId of the key.
 ** \param[in] key           Pointer to the key material.
 ** \param[in] keysize       Size of the key.
 **
 ** \return    Std_ReturnType
 **            E_OK      - Key set successfull.
 **            E_NOT_OK  - Key set Failed.
 **
 *********************************************************************************************
 */
Std_ReturnType vHsmKeyStore_SetKey(uint32 keyId, uint8 * key, uint16 keysize);
/**
 *********************************************************************************************
 ** \fn        vHsmKeyStore_MainFunction
 **
 ** \brief     Key Store MainFunction .
 **
 ** \details   Maintains the overall state of key Handling
 **
 ** \param none
 **
 ** \return none
 **
 *********************************************************************************************
 */
void vHsmKeyStore_MainFunction(void);
/**
 *********************************************************************************************
 ** \fn        vHsmKeyStore_GetKey
 **
 ** \brief     Get the Key Elelment .
 **
 ** \details   Function will get  key material from key Slot.
 **
 ** \param[in] keyId         KeyId of the key.
 ** \param[in] keyelementId  Key element ID
 ** \param[out] key          Pointer for storing the key material.
 ** \param[inout] keysize    Size of the key.
 **
 ** \return    Std_ReturnType
 **            E_OK      - Key Get successfull.
 **            E_NOT_OK  - Key Get Failed.
 **
 *********************************************************************************************
 */
Std_ReturnType vHsmKeyStore_GetKey(uint32 keyId, uint32 keyelementId ,uint8 * key, uint16 *keysize);
/**
 *********************************************************************************************
 ** \fn        vHsmKeyStore_Init
 **
 ** \brief     Initializes the Key handling.
 **
 ** \details   Function will copy all key materials from NOR to RAM for processing
 **
 ** \param none
 **
 ** \return none
 **
 *********************************************************************************************
 */
void vHsmKeyStore_Init(void);
/**
 *********************************************************************************************
 ** \fn        vHsmKeyStore_CertInit
 **
 ** \brief     Initializes the Certificate handling.
 **
 ** \details   Function will copy all Certificate materials from NOR to RAM for processing
 **
 ** \param none
 **
 ** \return none
 **
 *********************************************************************************************
 */
void vHsmKeyStore_CertInit(void);
/**
 *********************************************************************************************
 ** \fn        vHsmKeyStore_KeyCopy
 **
 ** \brief     Copy given key to target key slot.
 **
 ** \details   Function will copy given key material to given target key slot.
 **
 ** \param[in] keyId         KeyId of the key to be copied.
 ** \param[in] TargetId      Target KeyID.
 ** \param[in] KeyElementId  KeyElement to be copied.
 **
 ** \return    Std_ReturnType
 **            E_OK      - Key copy successfull.
 **            E_NOT_OK  - Key Copy Failed.
 **
 *********************************************************************************************
 */
Std_ReturnType vHsmKeyStore_KeyCopy(uint8 keyId, uint8 TargetId, uint32 KeyElementId);

/*EOF*/
