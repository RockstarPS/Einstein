/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2022] Visteon Corporation
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
 * \file Crypto_Cancel.c
 *
 * \details
 * Cry She cancel implementation for HSM from M7,
 * Reference is taken from MP21 -
 * http://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=37502204&objAction=browse&viewType=1
 *
 * \version 1.0.02
 * |Version | Date       | Author   | Task Id | Description                                |
 * |--------|------------|----------|---------|--------------------------------------------|
 * |1.00.00 | 30/Dec/'20 | svetcha  | 1061554 | AUTOSAR CRY Wrapper                        |
 * 
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Sree Divya Vetcha        | svetcha   | VTSC, Chennai, India
 *          Dhanalakshmi Kasimani    | dkasiman  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India        
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/

#ifndef CRYPTO_CANCEL_H
#define CRYPTO_CANCEL_H 1
#define CRYPTO_CANCEL_ENABLED 1


#include "Std_Types.h"
#include "vHsmCryptoManager.h"

/*==[Macros]==================================================================*/

/*==[Types]===================================================================*/

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Declaration of functions with external linkage]==========================*/

/**
 *********************************************************************************************
 ** \fn Crypto_She_CancelInit
 **
 ** \brief 
 ** 
 **
 ** \param [in] NONE
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void, CRY_CODE) Crypto_CancelInit(void);

/**
 *********************************************************************************************
 ** \fn Crypto_She_Cancel
 **
 ** \brief 
 ** 
 **
 ** \param [in] p_cancelJob_e
 ** 
 ** This function returns boolean
 **                 
 **
 ********************************************************************************************/
FUNC(boolean, CRY_CODE)Crypto_She_Cancel(te_canceljobid p_cancelJob_e);

/**
 *********************************************************************************************
 ** \fn Crypto_She_CancelCallback
 **
 ** \brief 
 ** 
 **
 ** \param [in] p_resultBytesInSRAM_U8P
 ** \param [in] payload_size
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void, CRY_CODE) Crypto_She_CancelCallback(uint8 *p_resultBytesInSRAM_U8P, uint16 payload_size);


/**
 *********************************************************************************************
 ** \fn Crypto_She_GetCancelIsComplete
 **
 ** \brief 
 ** 
 **
 ** \param [in] NONE
 ** 
 ** This function returns boolean
 **                 
 **
 ********************************************************************************************/
FUNC(boolean, CRY_CODE)Crypto_She_GetCancelIsComplete(void);

#endif /* CRYPTO_CANCEL_H */

