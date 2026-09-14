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
 * \file Crypto_MacVerify.h
 *
 * \brief
 * MAC Verify header in M7
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
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/
#ifndef CRYPTO_MACVERIFY_H
#define CRYPTO_MACVERIFY_H 1
#define CRYPTO_MACVERIFY_ENABLED 1

/*==[Includes]================================================================*/

/*!
 * \defgroup   header_files Dependancy_headers
 */
/*!
 * \brief        The module shall use **Crypto.h** data types.
 * \addtogroup  header_files
 */
#include "Crypto.h"

#if (CRYPTO_MACVERIFY_ENABLED == 1)

/*==[Macros]==================================================================*/

extern void Crypto_CMacVerify_callback(Csm_ReturnType result);
/* Define Callback Notification functions for CSM */
#define CRYPTO_CSM_MACVERIFY_CALLBACK_NOTIF        Crypto_CMacVerify_callback
/* Define Service Finish Notification functions for CSM */
#define CRYPTO_CSM_MACVERIFY_SERVICE_FINISH_NOTIF

typedef struct
{
  uint8 priority;
}
Crypto_She_MacVerifyConfigType;

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Declaration of functions with external linkage]==========================*/
FUNC(void, CRY_CODE) Crypto_SymMacVerInit(void);

/** \brief single call the MAC verification.
 **
 ** This function starts the MacVerify service.
 **
 ** \param[in]      cfgPtr  The service configuration.
 ** \param[in]      keyPtr  Pointer to the key to be used.
  ** \param[in]      dataPtr     Pointer to data.
 ** \param[in]      dataLength  Length of data.
  ** \param[in]      macPtr     A pointer to the start of an array
 **                            which will hold the MAC to verify.
 ** \param[in]      macLength  Length of the MAC to be verified.
 ** \param[out]     resultPtr  A pointer where the result of the MAC verify
 **                            computation shall be stored.
 **
 ** \returns  Error value.
 **
 ** \retval   CSM_E_OK      If the service can be started.
 ** \retval   CSM_E_NOT_OK  If the key or configuration are invalid.
 ** \retval   CSM_E_BUSY    If another instance of this service is already
 **                         running.
 **/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_She_MacVerify_S
(
                P2CONST(void,           AUTOMATIC, CRY_APPL_DATA) cfgPtr,
                P2CONST(Csm_SymKeyType, AUTOMATIC, CRY_APPL_DATA) keyPtr,
                P2CONST(uint8,  AUTOMATIC, CRY_APPL_DATA) dataPtr,
                VAR(uint32,            CRY_APPL_DATA) dataLength,
                P2CONST(uint8,                AUTOMATIC, CSM_APPL_DATA) macPtr,
                VAR(uint32,               AUTOMATIC               ) macLength,
                P2VAR(Csm_VerifyResultType, AUTOMATIC, CSM_APPL_DATA) resultPtr
);

/** \brief Start the MAC verification.
 **
 ** This function starts the MacVerify service.
 **
 ** \param[in]      cfgPtr  The service configuration.
 ** \param[in]      keyPtr  Pointer to the key to be used.
 **
 ** \returns  Error value.
 **
 ** \retval   CSM_E_OK      If the service can be started.
 ** \retval   CSM_E_NOT_OK  If the key or configuration are invalid.
 ** \retval   CSM_E_BUSY    If another instance of this service is already
 **                         running.
 **/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_MacVerifyStart
(
  P2CONST(void,           AUTOMATIC, CRY_APPL_DATA) cfgPtr,
  P2CONST(Csm_SymKeyType, AUTOMATIC, CRY_APPL_DATA) keyPtr
);

/** \brief Stream data.
 **
 ** This function streams data into the SHE. Since the SHE can only verify
 ** the MAC over a single block of data whose size must be known from the
 ** beginning, this function can only be called once.
 **
 ** \param[in]      dataPtr     Pointer to data.
 ** \param[in]      dataLength  Length of data.
 **
 ** \returns  Error value.
 **
 ** \retval   CSM_E_OK     If the update was successfully requested.
 ** \retval   CSM_E_NOT_OK If the service has not been started or the
 **                        update function has been called more than
 **                        once.
 ** \retval   CSM_E_BUSY   If this service is already starting.
 **/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_MacVerifyUpdate
(
  P2CONST(uint8,  AUTOMATIC, CRY_APPL_DATA) dataPtr,
      VAR(uint32,            CRY_APPL_DATA) dataLength
);

/** \brief  Finish MAC verification.
 **
 ** This function finishes the MAC verification.
 **
 ** \param[in]      macPtr     A pointer to the start of an array
 **                            which will hold the MAC to verify.
 ** \param[in]      macLength  Length of the MAC to be verified.
 ** \param[out]     resultPtr  A pointer where the result of the MAC verify
 **                            computation shall be stored.
 **
 ** \returns  Error value.
 **
 ** \retval   CSM_E_OK      If the finish was successfully requested.
 ** \retval   CSM_E_NOT_OK  If the service has not been started.
 ** \retval   CSM_E_BUSY    If this service is already starting or updating.
 **/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_MacVerifyFinish
(
  P2CONST(uint8,                AUTOMATIC, CSM_APPL_DATA) macPtr,
      VAR(uint32,               AUTOMATIC               ) macLength,
    P2VAR(Csm_VerifyResultType, AUTOMATIC, CSM_APPL_DATA) resultPtr
);

/**  \brief Perform primitive tasks.
 **
 ** This function performs periodic tasks of the primitive that may be
 ** necessary (e.g. checking if a SHE command has to be sent or if a
 ** SHE command has finished). This function is called by a
 ** corresponding CSM main function.
 **/
FUNC(void,CRY_CODE) Crypto_MacVerifyMainFunction
(
  void
);

/** \brief  Cancel a running encryption and free the SHE software lock.
 **/
FUNC(void, CRY_CODE) Crypto_SymMacVerCancel(void);


#endif /* #if (CRYPTO_MACVERIFY_ENABLED == 1) */

#endif /* #ifndef CRYPTO_MACVERIFY_H */
