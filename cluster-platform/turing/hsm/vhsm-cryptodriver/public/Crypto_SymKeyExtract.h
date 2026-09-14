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
 * \file Crypto_SymKeyExtract.h
 *
 * \brief
 * Key extract header in M7
 *
 * \detailed description
 * Reference is taken from MP21 -
 * http://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=37502204&objAction=browse&viewType=1
 *
 * \version 1.0.01
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 30/Dec/'20 | bjayara2 | 1061554 | AUTOSAR CRY Wrapper                   |
 * |1.00.01 | 15/Jan/'21 | bjayara2 | 1174465 | Added Doxygen Support                 |
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Sree Divya Vetcha        | svetcha   | VTSC, Bengaluru, India
 *          Dhanalakshmi Kasimani    | dkasiman  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/
#ifndef CRYPTO_SYMKEYEXTRACT_H
#define CRYPTO_SYMKEYEXTRACT_H 1
#define CRYPTO_SYMKEYEXTRACT_ENABLED 1


#include "Std_Types.h"
#include "Csm_Types.h"


#if (CRYPTO_SYMKEYEXTRACT_ENABLED == 1)

/*==[Types]==================================================================*/

typedef struct
{
  /* !LINKSTO CRYSHE_21, 1
   */
  uint8 priority;
}
Crypto_SymKeyExtractConfigType;


/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Declaration of functions with external linkage]==========================*/

extern void Crypto_SymKeyExtractCallbackNotification(Csm_ReturnType result);



/* Define Callback Notification functions for CSM */
#define CRYPTO_CSM_SYMKEYEXTRACT_CALLBACK_NOTIF        Crypto_SymKeyExtractCallbackNotification
/* Define Service Finish Notification functions for CSM */
#define CRYPTO_CSM_SYMKEYEXTRACT_SERVICE_FINISH_NOTIF

FUNC(void, CRY_CODE) Crypto_SymKeyExtractInit(void);
/** \brief Start the key extraction service.
 **
 ** This function starts the SymKeyExtract service which will store
 ** key information in a provided key container and, if given actual key
 ** data to store will load the key into the HSM.
 **
 ** \param[in] cfgPtr      The service configuration.
 **
 ** \returns Error value.
 ** \retval   CSM_E_OK      If the service can be started.
 ** \retval   CSM_E_BUSY    If another instance of this service is
 **                         currently running.
 **/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_SymKeyExtractStart
(
  P2CONST(void,AUTOMATIC,CRY_APPL_DATA) cfgPtr
);

/** \brief Stream key data.
 **
 ** This function accepts key data which to store into the HSM.
 **
 ** \param[in] dataPtr Pointer to key data.
 ** \param[in] dataLength Length of key data.
 **
 ** \returns Error value.
 ** \retval   CSM_E_OK      If the update was successfully requested.
 ** \retval   CSM_E_NOT_OK  If the service has not been started or if the
 **                         key data exceeds 64 bytes.
 ** \retval   CSM_E_BUSY    If this service is already starting or updating.
 **/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_SymKeyExtractUpdate
(
  P2CONST(uint8,AUTOMATIC,CRY_APPL_DATA) dataPtr,
  uint32 dataLength
);

/** \brief  Finish extract key.
 **
 ** This function triggers the finishing of the key extraction. If
 ** the given key data is 16 bytes long, a plain key will be loaded
 ** (always into the RAM slot). If the given key data is 64 bytes
 ** long, a full key can be loaded into any slot. If the key data
 ** is one byte long, it is interpreted as a HSM key slot ID. For
 ** which a key container should be produced. If the key data has
 ** a different length, an error is returned.
 **
 ** After this service is finished, the provided key result container
 ** will hold information about the loaded key and can be used in
 ** en-/decryption or MAC generation/verification.
 **
 ** \param[out] keyPtr Pointer to the key result.
 **
 ** \returns  Error value.
 **
 ** \retval   CSM_E_OK      If the finish was successfully requested.
 ** \retval   CSM_E_NOT_OK  If the service has not been started or
 **                         if an invalid number of bytes has been
 **                         streamed.
 ** \retval   CSM_E_BUSY    If this service is already starting or updating.
 **/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_SymKeyExtractFinish
(
      VAR(uint8,            CRY_APPL_DATA) keyId
);

/**  \brief Perform primitive tasks.
 **
 ** This function performs periodic tasks of the primitive that may be
 ** necessary (e.g. checking if a HSM command has to be sent or if a
 ** HSM command has finished). This function is called by a
 ** corresponding CSM main function.
 **/
FUNC(void,CRY_CODE) Crypto_SymKeyExtractMainFunction(void);

FUNC(void, CRY_CODE) Crypto_SymKeyExtractCancel(void);



#endif /* #if (CRYPTO_SYMKEYEXTRACT_ENABLED == 1) */

#endif /* CRYPTO_SYMKEYEXTRACT_H */


