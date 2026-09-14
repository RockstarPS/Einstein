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
 * \file Cry_She_Random.h
 *
 * \brief
 * Random callback header in M7
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
#ifndef CRYPTO_RANDOM_H
#define CRYPTO_RANDOM_H 1
#define CRYPTO_RANDOM_ENABLED 1

/*==[Includes]================================================================*/

#if (CRYPTO_RANDOM_ENABLED == 1)

/*==[Macros]==================================================================*/


extern void Crypto_RandomCallbackNotification(Csm_ReturnType result);

/* Define Callback Notification functions for CSM */
#define CRYPTO_HSM_CSM_RANDOM_CALLBACK_NOTIFICATION        Crypto_RandomCallbackNotification
/* Define Service Finish Notification functions for CSM */
#define CRYPTO_HSM_CSM_RANDOM_SERVICE_FINISH_NOTIFICATION()

/*==[Types]===================================================================*/

typedef struct
{
  /* !LINKSTO CRYSHE_21, 1
   */
  uint8 priority;
}
Crypto_RandomConfigType;
/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Declaration of functions with external linkage]==========================*/

/**
 *********************************************************************************************
 ** \fn Crypto_She_RandomInit
 **
 ** \brief 
 ** This function initializes the Random module. It has to be called 
 ** from Crypto_Init and before any services of the random module are used.
 **
 ** \param [in] NONE
 ** 
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(void, CRY_CODE) Crypto_RandomInit(void);

/**
 *********************************************************************************************
 ** \fn Crypto_She_RandomSeedStart
 **
 ** \brief 
 ** 
 **
 ** \param [in] cfgPtr
 ** 
 ** This function returns Csm_ReturnType
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType, CRY_CODE)Crypto_RandomSeedStart(P2CONST(void, AUTOMATIC, CRY_APPL_DATA) cfgPtr);
/**
 *********************************************************************************************
 ** \fn Crypto_She_RandomSeedUpdate
 **
 ** \brief 
 ** 
 **
 ** \param [in] seedPtr
 ** \param [in] seedLength
 ** 
 ** This function returns Csm_ReturnType
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType, CRY_CODE)Crypto_RandomSeedUpdate(P2CONST(uint8, AUTOMATIC, CRY_APPL_DATA) seedPtr,
        uint32 seedLength);

/**
 *********************************************************************************************
 ** \fn Crypto_She_RandomSeedFinish
 **
 ** \brief 
 ** 
 **
 ** \param [in] NONE
 ** 
 ** This function returns Csm_ReturnType
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType, CRY_CODE) Crypto_RandomSeedFinish(void);

/**
 *********************************************************************************************
 ** \fn Crypto_She_RandomSeedStart
 **
 ** \brief 
 ** 
 **
 ** \param [in] cfgPtr
 ** 
 ** This function returns Csm_ReturnType
 **                 
 **
 ********************************************************************************************/
FUNC(void,CRY_CODE) Crypto_RandomSeedMainFunction(void);

/**
 *********************************************************************************************
 ** \fn Crypto_She_RandomMainFunction
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
FUNC(void, CRY_CODE) Crypto_RandomMainFunction(void);

/**
 *********************************************************************************************
 ** \fn Crypto_She_RandomGenerate
 **
 ** \brief 
 ** 
 **
 ** \param [in] cfgPtr
 ** \param [in] resultPtr
 ** \param [in] resultLength_U32
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType, CRY_CODE)Crypto_RandomGenerate(
        P2CONST(void, AUTOMATIC, CRY_APPL_DATA) cfgPtr,
        P2VAR(uint8, AUTOMATIC, CRY_APPL_DATA) resultPtr,
        uint32 resultLength_U32);

/**
 *********************************************************************************************
 ** \fn Crypto_She_RandGen4Dot3CSM
 **
 ** \brief 
 **
 **
 ** \param [in] cfgPtr
 ** \param [in] resultPtr
 ** \param [in] resultLength_U32
 ** 
 ** This function returns NONE
 **                 
 **
 ********************************************************************************************/
FUNC(Csm_ReturnType, CRY_CODE)Crypto_RandGen4Dot3CSM(
        P2CONST(void, AUTOMATIC, CRY_APPL_DATA) cfgPtr,
        P2VAR(uint8, AUTOMATIC, CRY_APPL_DATA) resultPtr,
        uint32 resultLength_U32);


/**
 *********************************************************************************************
 ** \fn Crypto_She_RandomGenerateMainFunction
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
FUNC(void, CRY_CODE) Crypto_RandomGenerateMainFunction(void);

FUNC(void, CRY_CODE) Crypto_RandomCancel(void);

FUNC(void, CRY_CODE) Crypto_RandomGen4dot3MainFunction(void);

#endif /* CRYPTO_RANDOM_ENABLED */

#endif /* #ifndef CRY_SHE_RANDOM_H */
