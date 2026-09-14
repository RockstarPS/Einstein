/*=================================================================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2001. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**==================================================================================================================
**
** Name:           Securediagcdd.c
**
** Description:
**
**
**===================================================================================================================*/

#ifndef SECUREDIAGCDD_C
#define SECUREDIAGCDD_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/

#include "Mgrdiagcdd.h"
#include "Securediagcdd_cfg.h"

/*To avoid the coverity warning - unnecessary header file*/
#ifdef SECUREDIAG_HEADER_REQUIRED
#include "Securediagcdd.h"
#else
#endif

/*********************************************************************************
 *  MEET_TYPE1_SecurityAlgorithm or  MEET_TYPE2_SecurityAlgorithm
 *  -------------------------------------------------------------------------------
 *  Define this macro in config files based on the algorithm required
 *
 *  MEET_TYPE1_SecurityAlgorithm  - seed and key are two bytes
 *  MEET_TYPE2_SecurityAlgorithm  - seed and key are four bytes and two levels
 *                                  of security
 *        However, algorithms used for seed generation and Key calculation
 *  also differs for both the types.
 **********************************************************************************/

#ifdef MEET_TYPE1_SecurityAlgorithm
#define MEET_SECURITY_ENABLED
#elif defined(MEET_TYPE2_SecurityAlgorithm)
#define MEET_SECURITY_ENABLED
#elif defined(MEET_TYPE3_SecurityAlgorithm)
#define MEET_SECURITY_ENABLED
#else
#error : Securediagcdd.c Missing Security Algorithm Type in configuration.
#endif /*MEET_TYPE1_SecurityAlgorithm*/

#ifdef MEET_SECURITY_ENABLED
/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S
**====================================================================================================================*/

/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef MEET_TYPE1_SecurityAlgorithm
/************************************************************************************
 * Type        : uint8
 * Name        : XX1, XX2
 * Description : variables for MEET_TYPE1_SecurityAlgorithm as per SMRS
 *************************************************************************************/
uint8 XX1, XX2;

#elif defined(MEET_TYPE2_SecurityAlgorithm)

eSecurityType2Levels SecureLevel;

#elif defined(MEET_TYPE3_SecurityAlgorithm)
/************************************************************************************
 * Type        : uint8
 * Name        : l_seed_U8A
 * Description : Array  to store the seeds for MEET_TYPE3_SecurityAlgorithm.
 *************************************************************************************/
uint8 l_seed_U8A[4];
uint8 l_One_sec_Timer_Status_U8 = FALSE;
uint8 l_security_unlock_status = FALSE;
#else
#endif
/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/

/*=====================================================================================================================
**
** Function Name    :  SecurityGetSeed
**
** Visibility       :  Public/private
**
** Description      :  Generate Seed for MEET_TYPE1_SecurityAlgorithm
**
** Invocation       :  DCM Callout
**
** Inputs           :  OpStatus, Seed, ErrorCode
**
** Outputs          :  Std_ReturnType - DCM_E_OK, E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
#ifdef MEET_TYPE1_SecurityAlgorithm
FUNC(Std_ReturnType, CMeetCdd_CODE)CMeetCdd_SecurityGetSeed(UInt8 OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MEET_CDD_APPL_VAR) Seed, P2VAR(UInt8, AUTOMATIC, RTE_MEET_CDD_APPL_VAR) ErrorCode)
{

    *ErrorCode = DCM_E_OK;
    uint16 SeedSend1, SeedSend2, SeedSend;

    /*** Take  random value from Memory locations to calculate random Seed *************/
    uint16 *Pointer1 = (uint16 *)0x00011F20; /*0x000052F0;0x02001050;*/
    uint16 *Pointer2 = (uint16 *)0x000052F4; /*0x020014F0;*/
    uint16 *Pointer3 = (uint16 *)0x000052F8; /*0x020014C0;*/

    /**** Generate Random Seed ***************/
    SeedSend1 = (*Pointer1) ^ (*Pointer3);
    SeedSend2 = (*Pointer2) ^ (*Pointer3);
    SeedSend = SeedSend1 + SeedSend2;
    SeedSend ^= (uint16)0xA596u;

    /*Send Seed on Request */
    Seed[0] = (uint8)SeedSend >> 8;
    Seed[1] = (uint8)SeedSend & 0xFFu;

    /*** Take local copy for use */
    XX1 = Seed[0];
    XX2 = Seed[1];

    return DCM_E_OK;
}

/*============================================================================
**
** Function Name    :   SecurityCompareKey
**
** Visibility       :   Public
**
** Description      :   Compare Seed-Customer for MEET_TYPE1_SecurityAlgorithm
**
** Invocation       :   DCM Callout
**
** Inputs           :   Key, OpStatus, ErrorCode
**
** Outputs          :   Std_ReturnType - DCM_E_OK, E_NOT_OK
**
** Critical Section :  No
**
**==========================================================================*/
FUNC(Std_ReturnType, RTE_MEET_CDD_APPL_CODE) CMeetCdd_SecurityCompareKey(P2VAR(UInt8, AUTOMATIC, RTE_MEET_CDD_APPL_VAR) Key, UInt8 OpStatus, P2VAR(UInt8, AUTOMATIC, RTE_MEET_CDD_APPL_VAR) ErrorCode)
{
    Std_ReturnType Ret;
    *ErrorCode = DCM_E_OK;
    (void)OpStatus;

    uint8 YY1;
    uint8 YY2;

    /*Call Function to calculate key*/
    (void)SendKeyToCalculate(&YY1, &YY2);

    if ((Key[0] == YY1) && (Key[1] == YY2))
    {
        Ret = DCM_E_OK;
    }
    else
    {
        Ret = E_NOT_OK;
    }

    return Ret;
}

/*============================================================================
**
** Function Name    :   SendKeyToCalculate
**
** Visibility       :   private
**
** Description      :   Calculate Key for MEET_TYPE1_SecurityAlgorithm.
**
** Invocation       :   DCM Callout
**
** Inputs           :   YY1, YY2
**
** Outputs          :   Std_ReturnType - DCM_E_OK, E_NOT_OK
**
** Critical Section :  No
**
**==========================================================================*/

Std_ReturnType SendKeyToCalculate(P2VAR(UInt8, AUTOMATIC, RTE_MEETCDD_APPL_VAR) YY1, P2VAR(UInt8, AUTOMATIC, RTE_MEETCDD_APPL_VAR) YY2)
{

    /*Formula as per SMRS*/
    *YY1 = ((TYPE1SECURITY_FACTOR1 * XX1) + TYPE1SECURITY_OFFSET);
    *YY2 = ((TYPE1SECURITY_FACTOR2 * XX2) + TYPE1SECURITY_OFFSET);

    return (0);
}
#endif /*MEET_TYPE1_SecurityAlgorithm*/

#ifdef MEET_TYPE2_SecurityAlgorithm

/*============================================================================
**
** Function Name    :   DspSecLvl1GetSeedFnc
**
** Visibility       :   Public
**
** Description      :   Security Level1 generate Seed for MEET_TYPE2_SecurityAlgorithm
**
** Invocation       :   DCM Callout
**
** Inputs           :   OpStatus, Seed, ErrorCode
**
** Outputs          :   Std_ReturnType - DCM_E_OK, E_NOT_OK
**
** Critical Section :  No
**
**==========================================================================*/
FUNC(Std_ReturnType, CMeetCdd_CODE) CMeetCdd_DspSecLvl1GetSeedFnc(UInt8 OpStatus, P2VAR(UInt8, AUTOMATIC, RTE_MEETCDD_APPL_VAR) Seed, P2VAR(UInt8, AUTOMATIC, RTE_MEETCDD_APPL_VAR) ErrorCode)
{

    *ErrorCode = DCM_E_OK;
    (void)OpStatus;

    SecureLevel = Level1;
    Calculated_key_U32 = GetSeed_4bytes(Seed) + GetLevelConstant_Type2Security(SecureLevel);

    return DCM_E_OK;
}

/*============================================================================
**
** Function Name    :   DspSecLevel1CmpKeyFnc
**
** Visibility       :   Public
**
** Description      :   Security level1 Compare Seed-Customer for MEET_TYPE2_SecurityAlgorithm
**
** Invocation       :   DCM Callout
**
** Inputs           :   Key ,OpStatus
**
** Outputs          :   Std_ReturnType - DCM_E_OK, E_NOT_OK
**
** Critical Section :  No
**
**==========================================================================*/
FUNC(Std_ReturnType, CMeetCdd_CODE) CMeetCdd_DspSecLevel1CmpKeyFnc(P2CONST(UInt8, AUTOMATIC, RTE_MEETCDD_APPL_VAR) Key, UInt8 OpStatus, P2VAR(UInt8, AUTOMATIC, RTE_MEETCDD_APPL_VAR) ErrorCode)
{

    *ErrorCode = DCM_E_OK;
    // SecureLevel = Level1;
    (void)OpStatus;
    return (CompareKey4bytes(Key, Calculated_key_U32));
}

/*============================================================================
**
** Function Name    :   DspSecLvl3GetSeedFnc
**
** Visibility       :   Public
**
** Description      :   Security Level3 generate Seed for MEET_TYPE2_SecurityAlgorithm
**
** Invocation       :   DCM Callout
**
** Inputs           :   OpStatus, Seed, ErrorCode
**
** Outputs          :   Std_ReturnType - DCM_E_OK, E_NOT_OK
**
** Critical Section :  No
**
**==========================================================================*/
FUNC(Std_ReturnType, CMeetCdd_CODE) CMeetCdd_DspSecLvl3GetSeedFnc(UInt8 OpStatus, P2VAR(UInt8, AUTOMATIC, RTE_MEETCDD_APPL_VAR) Seed, P2VAR(UInt8, AUTOMATIC, RTE_MEETCDD_APPL_VAR) ErrorCode)
{

    *ErrorCode = DCM_E_OK;
    (void)OpStatus;

    SecureLevel = Level3;
    Calculated_key_U32 = GetSeed_4bytes(Seed) + GetLevelConstant_Type2Security(SecureLevel);

    return DCM_E_OK;
}

/*============================================================================
**
** Function Name    :   DspSecLevel3CmpKeyFnc
**
** Visibility       :   Public
**
** Description      :   Security level3 Compare Seed-Customer for MEET_TYPE2_SecurityAlgorithm
**
** Invocation       :   DCM Callout
**
** Inputs           :   Key ,OpStatus
**
** Outputs          :   Std_ReturnType - DCM_E_OK, E_NOT_OK
**
** Critical Section :  No
**
**==========================================================================*/
FUNC(Std_ReturnType, CMeetCdd_CODE) CMeetCdd_DspSecLevel3CmpKeyFnc(P2CONST(UInt8, AUTOMATIC, RTE_MEETCDD_APPL_VAR) Key, UInt8 OpStatus, P2VAR(UInt8, AUTOMATIC, RTE_MEETCDD_APPL_VAR) ErrorCode)
{
    *ErrorCode = DCM_E_OK;
    // SecureLevel = Level3;
    (void)OpStatus;

    return (CompareKey4bytes(Key, Calculated_key_U32));
}
#endif /*MEET_TYPE2_SecurityAlgorithm*/

#ifdef MEET_TYPE3_SecurityAlgorithm

/*============================================================================
**
** Function Name    :   CMeetCdd_SecurityGetSeed
**
** Visibility       :   Public
**
** Description      :   Generate Seed for MEET_TYPE3_SecurityAlgorithm
**
** Invocation       :   DCM Callout
**
** Inputs           :   OpStatus, Seed, ErrorCode
**
** Outputs          :   Std_ReturnType - DCM_E_OK, E_NOT_OK
**
** Critical Section :  No
**
**==========================================================================*/
FUNC(Std_ReturnType, CMeetCdd_CODE)CMeetCdd_SecurityGetSeed(UInt8 OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MEET_CDD_APPL_VAR) Seed, P2VAR(UInt8, AUTOMATIC, RTE_MEET_CDD_APPL_VAR) ErrorCode)
{

    *ErrorCode = DCM_E_OK;
    (void)OpStatus;
    if ((uint8)FALSE == GetSecurity_Unlock_Status())
    {
        GetSeed_4bytes(Seed);
        l_seed_U8A[0] = Seed[0];
        l_seed_U8A[1] = Seed[1];
        l_seed_U8A[2] = Seed[2];
        l_seed_U8A[3] = Seed[3];
    }
    else
    {
        l_seed_U8A[0] = 0;
        l_seed_U8A[1] = 0;
        l_seed_U8A[2] = 0;
        l_seed_U8A[3] = 0;

        Seed[0] = 0;
        Seed[1] = 0;
        Seed[2] = 0;
        Seed[3] = 0;
    }
    return DCM_E_OK;
}
/*============================================================================
**
** Function Name    :   SendKeyToCalculate
**
** Visibility       :   private
**
** Description      :   Calculate Key for MEET_TYPE3_SecurityAlgorithm.
**
** Invocation       :   DCM Callout
**
** Inputs           :   seeds
**
** Outputs          :   Calculated Keys,Std_ReturnType - DCM_E_OK, E_NOT_OK
**
** Critical Section :  No
**
**==========================================================================*/

Std_ReturnType SendKeyToCalculate(P2VAR(UInt8, AUTOMATIC, RTE_MEETCDD_APPL_VAR) p_calculated_key_U8A)
{
    p_calculated_key_U8A[0] = (uint8)(l_seed_U8A[0] ^ (((((l_seed_U8A[2] * 256U) + l_seed_U8A[1]) ^ TYPE3SECURITY_OFFSET) >> TYPE3SECURITY_FACTOR1) & 0x00FFU));
    p_calculated_key_U8A[1] = (uint8)(l_seed_U8A[1] ^ (((((l_seed_U8A[3] * 256U) + l_seed_U8A[0]) ^ TYPE3SECURITY_OFFSET) >> TYPE3SECURITY_FACTOR2) & 0x00FFU));
    p_calculated_key_U8A[2] = (uint8)(l_seed_U8A[2] ^ (((((l_seed_U8A[0] * 256U) + l_seed_U8A[3]) ^ TYPE3SECURITY_OFFSET) >> TYPE3SECURITY_FACTOR2) & 0x00FFU));
    p_calculated_key_U8A[3] = (uint8)(l_seed_U8A[3] ^ (((((l_seed_U8A[1] * 256U) + l_seed_U8A[2]) ^ TYPE3SECURITY_OFFSET) >> TYPE3SECURITY_FACTOR1) & 0x00FFU));
    return DCM_E_OK;
}

/*============================================================================
**
** Function Name    :   CMeetCdd_SecurityCompareKey
**
** Visibility       :   Public
**
** Description      :   Compare Seed-Customer for MEET_TYPE3_SecurityAlgorithm
**
** Invocation       :   DCM Callout
**
** Inputs           :   Key ,OpStatus
**
** Outputs          :   Std_ReturnType - DCM_E_OK, E_NOT_OK
**
** Critical Section :  No
**
**==========================================================================*/
FUNC(Std_ReturnType, RTE_MEET_CDD_APPL_CODE) CMeetCdd_SecurityCompareKey(P2VAR(UInt8, AUTOMATIC, RTE_MEET_CDD_APPL_VAR) Key, UInt8 OpStatus, P2VAR(UInt8, AUTOMATIC, RTE_MEET_CDD_APPL_VAR) ErrorCode)
{                                     
    Std_ReturnType Ret = E_NOT_OK;
    uint8 fl_Calculated_key_U8A[4];
    *ErrorCode = DCM_E_OK;
    (void)OpStatus;

    l_One_sec_Timer_Status_U8 = APP_SPEC_GET_TIMER_STATUS();

    if ((uint8)FALSE == l_One_sec_Timer_Status_U8)
    {

        /*Call Function to calculate key*/
        (void)SendKeyToCalculate(fl_Calculated_key_U8A);

        if ((Key[0] == fl_Calculated_key_U8A[0]) && (Key[1] == fl_Calculated_key_U8A[1]) && (Key[2] == fl_Calculated_key_U8A[2]) && (Key[3] == fl_Calculated_key_U8A[3]))
        {
            Ret = DCM_E_OK;
            SetSecurity_Unlock_Status((uint8)TRUE);
        }
        else
        {
            l_One_sec_Timer_Status_U8 = (uint8)TRUE;
            APP_SPEC_SET_TIMER_STATUS(l_One_sec_Timer_Status_U8);
            SetSecurity_Unlock_Status((uint8)FALSE);
            *ErrorCode = DCM_E_INVALIDKEY;
            Ret = E_NOT_OK;
        }
    }
    else
    {
        *ErrorCode = DCM_E_INVALIDKEY;
    }

    return Ret;
}
#endif
#endif /*MEET_SECURITY_ENABLED*/
/*=====================================================================================================================
**  for each change to this file, be sure to record:
**  1.  who made the change and when the change was made
**  2.  why the change was made and the intended result
**  Following block needs to be repeated for each change
**====================================================================================================================*/
/*=====================================================================================================================
**   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any
**   other reason
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation and error code for security compare key API.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/01/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 1380314
** Change Description:  Coverity/Misra fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  06-Nov-2018
** CDSID             :  dkasiman
** Traceability      :  RTC: 1247811
** Change Description:  For Type 3 algorithm, Errorcode 0x35 has been returned when invalid key received.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  06-Oct-2018
** CDSID             :  dkasiman
** Traceability      :  RTC: 1212263
** Change Description:  Seed value made as 0 when supplier session is unlocked.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  10-Aug-2018
** CDSID             :  dkasiman
** Traceability      :  RTC: 1148618/1148619
** Change Description:  One sec timer added for invalid key reception.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13-July-2018
** CDSID             :  dkasiman
** Traceability      :  RTC: 1148618/1148619
** Change Description:  return 0 modified as return DCM_E_OK.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  11-July-2018
** CDSID             :  dkasiman
** Traceability      :  RTC: 1148618/1148619
** Change Description:  Type3 security algorithm added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  19-Jun-2018
** CDSID             :  bbalan
** Traceability      :  RTC: 1129584
** Change Description:  1.Error code argument addition in interfaces as per CRE changes.
**                      2.MISRA warning fixes.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  07-Jun-2018
** CDSID             :  bbalan
** Traceability      :  RTC: 1129584
** Change Description:  MISRA warning fixes.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  01-Jun-2018
** CDSID             :  bbalan
** Traceability      :  RTC: 1129584
** Change Description:  Review comments fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16-May-2018
** CDSID             :  bbalan
** Traceability      :  RTC: 1117852
** Change Description:  Initial version - SecureDiagCdd Implementation for Turing Bookshelf.
**====================================================================================================================*/
#endif /*SECUREDIAGCDD_C */
