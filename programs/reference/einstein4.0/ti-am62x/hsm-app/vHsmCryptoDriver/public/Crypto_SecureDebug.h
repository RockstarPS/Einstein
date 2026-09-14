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
 * \file Crypto_SecureDebug.h
 *
 * \brief
 * MAC generate header in M7
 *
 * \detailed description
 * Reference is taken from MP21 -
 * http://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=37502204&objAction=browse&viewType=1
 *
 * \version 1.0.01
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 | 30/Dec/'22 | svetcha  | 1061554 | AUTOSAR CRY Wrapper                   |
 *
 *
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Sree Divya Vetcha        | svetcha   | VTSC, Bengaluru, India
 *          Dhanalakshmi Kasimani    | dkasiman  | VTSC, Chennai, India
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Geetha A Krishna         | kgeethaa  | VTSC, Bengaluru, India
 ******************************************************************************/
#ifndef CRYPTO_SECUREDEBUG_H
#define CRYPTO_SECUREDEBUG_H 1
#define CRYPTO_SECUREDEBUG_ENABLED   1

#include "Std_Types.h"
#include "stub.h"

#if (CRYPTO_SECUREDEBUG_ENABLED == 1)

/*==[Macros]==================================================================*/


extern void SecureDebug_callback(Csm_ReturnType Result);

#define CRYPTO_HSM_CSM_SECUREDEBUG_CALLBACK_NOTIF        SecureDebug_callback

#define CRYPTO_HSM_CSM_SECUREDEBUG_SERVICE_FINISH_NOTIF

/*==[Types]===================================================================*/

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Declaration of functions with external linkage]==========================*/

/**
 *********************************************************************************************
 ** \fn Crypto_Hsm_SecureDebugInit
 **
 ** \brief 
 ** This function initializes the secure debug module. It has to be called before
 ** any services of the Secure debug are used.
 **
 ** \param [in] NONE
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void, CRY_CODE) Crypto_Hsm_SecureDebugInit(void);


/**
 *********************************************************************************************
 ** \fn Crypto_Hsm_CheckJtag_Password
 **
 ** \brief 
 ** This function checks the JTAG password got set already in Synchronous way
 **
 ** \param[in]      VerPtr     Pointer to keydata.
 ** \param[in/out]  VerLen     Pointer to Length that returns status
 **                            0 – if keys are not matching, key is registered, 
 **                                protection context is normal
 **                            1 – if no key is registered
 **                            2 – if key is registered and protection context is secure
 **                            16- if keys are matching and registered, protection context is 
 **                                 normal
 **                            18- if keys are matching and registered,  protection context is 
 **                                 secure
 ** 
 ** \retval   CSM_E_OK       Able to execute the checking of debug key without any issue AND
 **                          No sanity check failures
 ** \retval   CSM_E_NOT_OK   Sanity check fails OR some issue with getting the debug key
 ** \retval   CSM_E_BUSY     Module is Busy with other operation
 ********************************************************************************************/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_Hsm_CheckJtag_Password
        (
            P2VAR(uint8,  AUTOMATIC, CSM_APPL_DATA) VerPtr,
            P2VAR(uint8,  AUTOMATIC, CSM_APPL_DATA) VerLen
        );

/**
 *********************************************************************************************
 ** \fn Crypto_Hsm_SetJtag_Password
 **
 ** \brief 
 ** This function sets the JTAG password in  Asynchronous method by invoking the
 ** Cry_Hsm_SecureDebugMainFunction internally in CSM, so give the results in 
 ** callback; Sets the given data as JTAG password in HSM key slot
 **
 ** \param[in]      dataPtr     Contains the pointer to the data to be 
                                written as JTAG password
 ** \param[in]      dataLength  Length of data (Jtag Password is 16 bytes of length).
 ** 
 ** \retval   CSM_E_OK      If the update was successfully requested.
 ** \retval   CSM_E_NOT_OK  If the service has not been started or the
 **                         update function has been called more than
 **                         once.
 ** \retval   CSM_E_BUSY    If this service is already starting.
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType,CRY_CODE) Crypto_Hsm_SetJtag_Password
        (
            P2VAR(uint8,   AUTOMATIC, CSM_APPL_DATA) dataPtr,
            VAR(uint16,  AUTOMATIC) dataLen
        );

/******************************************************************************
 ** \fn Crypto_Hsm_SecureDebugCallback
 **
 ** This function gets invoked when gives data back to M7 core after crypto job
 ** completion 
 *****************************************************************************/        
FUNC(void, CRY_CODE) Crypto_Hsm_SecureDebugCallback(uint8 *p_resultBytesInSRAM_U8P, uint16 payload_size);  

/******************************************************************************
 ** \fn Crypto_Hsm_SecureDebugMainFunction
 **
 ** \brief 
 ** This function performs periodic tasks of the primitive that may be
 ** necessary (e.g. checking if a SHE command has to be sent or if a
 ** SHE command has finished). This function is called by a
 ** corresponding CSM main function
 **
 ** \param [in] NONE
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void,CRY_CODE) Crypto_Hsm_SecureDebugMainFunction
        (
                void
        );



#endif /* CRYPTO_SECUREDEBUG_ENABLED */

#endif /* CRYPTO_SECUREDEBUG_H */



