/***************************************************************************/
/**
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2020] Visteon Corporation
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
 * \file Crypto_cfg.c
 *
 * \brief
 * Dispatch the crpto services in M7 from CSM
 *
 * \details description
 *  This file shall be dispatch the crypto job in M7, IT Receives the Crypto job request from CRYIF and depends on the job request passes the data to to CRY-SHE 
 *  and receiving back data from CRY-SHE and pass this data to CRYIF
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                           ...................|
 * |--------|------------|----------|---------|----------------------------------------------------------|
 * |1.00.00 | 23/Aug/'21 | mmarimu2 | 1431692 |Initial Dispatch crpto services implementation            |
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Malarvizhi Marimuthu     | mmarimu2  | VTSC, Chennai, India
 *          Baliga Baskaran          | bbaskara  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/
/*.......Include files.......*/
#include "Crypto_Cfg.h"
const Crypto_KeyType crypto_Key[TotalnoCryptoKey] =
 {
    /*    Ref     */
  {CryptoKeyID_RSA_Hash},           
  {CryptoKeyID_RSA_SignatureGen},   
  {CryptoKeyID_ECC256_SignatureVerify},
  {CryptoKeyID_SIPHASH_2_4_MACGEN},    
  {CryptoKeyID_SIPHASH_2_4_MACVerify},  
  {CryptoKeyID_RNG},        
  {CryptoKeyID_VKMS_handleDLC_start},     
  {CryptoKeyID_VKMS_handleDLC_finish}, 
  {CryptoKeyID_VKMS_getVerificationHash},
  {CryptoKeyID_VKMS_getIdentifyHash},
  {CryptoKeyID_VKMS_getPssHash},
  {CryptoKeyID_VKMS_MacGenerate},
  {CryptoKeyID_VKMS_VKMSKey1},
  {CryptoKeyID_VKMS_VKMSKey2},
  {CryptoKeyID_VKMS_getMetadata},
  {CryptoKeyID_VKMS_getstatus},
  {CryptoKeyID_VKMS_getTrainingCounter},
  {CryptoKeyID_VKMS_getVkmsVIN}
};


