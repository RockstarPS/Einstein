/*===================================================================================================================
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
**===================================================================================================================
**
** Name:           Securediagcdd_cfg$.h
**
** Description:    
**                
**
**====================================================================================================================*/
#ifndef SECUREDIAGCDD_CFG_H
#define SECUREDIAGCDD_CFG_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
 #include "Mgrdiagcdd_cfg.h"
/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
/*******************************************************************************
*  MEET_TYPE1_SecurityAlgorithm or  MEET_TYPE2_SecurityAlgorithm                
*  ----------------------------------------------------------------------------- 
*  Define this macro here based on the algorithm required                    
*                                                                            
*  MEET_TYPE1_SecurityAlgorithm  - seed and key are two bytes                 
*  MEET_TYPE2_SecurityAlgorithm  - seed and key are four bytes and two levels  
*                             of security                                      
*        However, algorithms used for seed generation and Key calculation      
*  also differs for both the types.                                            
******************************************************************************/
#define MEET_TYPE3_SecurityAlgorithm


/*****************************************************************************
*  SECUREDIAG_HEADER_REQUIRED                                                
*  --------------------------------------------------------------------------- 
*  Define this macro here if Securediagcdd.h is required for inclusion       
*                                                                            
*  If Securediag services are invoked through MeetCdd, this macro definition 
*  is required.                                                              
*                                                                            
*  If Securediag services are invoked through DCM (RTE)(i.e not via          
*  MeetCdd), this macro definition is not required.                          
******************************************************************************/
//#define SECUREDIAG_HEADER_REQUIRED
/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/




/*=====================================================================================================================
*  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**===================================================================================================================*/
#ifdef MEET_TYPE1_SecurityAlgorithm

    /************************************************************************************
    * Type        : uint8 CONST
    * Description : Constants required for MEET_TYPE1_SecurityAlgorithm
    *************************************************************************************/

    #define TYPE1SECURITY_FACTOR1 0x12U
    #define TYPE1SECURITY_FACTOR2 0x07U
    #define TYPE1SECURITY_OFFSET  0x08U

#elif defined(MEET_TYPE2_SecurityAlgorithm)

    /************************************************************************************
    * Type        : uint8 CONST
    * Description : Constants required for MEET_TYPE2_SecurityAlgorithm
    *************************************************************************************/
    
    #define TYPE2_LEVEL1CONSTANT 0xDU
    #define TYPE2_LEVEL3CONSTANT 0x56U
    
    /************************************************************************************
    * Type        : uint32                                                               
    * Name        : SeedSend_U32                                             
    * Description : variable to hold the Seed generated in level 1 or level 3 of                 
    *               MEET_TYPE2_SecurityAlgorithm as per SMRS                          
    *************************************************************************************/ 
    extern uint32 SeedSend_U32;  

    /************************************************************************************
    * Type        : uint32                                                               
    * Name        : Calculated_key_U32                                             
    * Description : variable to hold the calculated Key in level 1 or level 3 of                 
    *               MEET_TYPE2_SecurityAlgorithm as per SMRS                          
    *************************************************************************************/ 
     
    extern uint32 Calculated_key_U32;
     
    /************************************************************************************
    * Type        : enum variables
    * Description : Holds the level Constant values required for MEET_TYPE2_SecurityAlgorithm
    *************************************************************************************/

    typedef enum{
        Level1=0,
        Level3=1,
    }eSecurityType2Levels;
    
    /************************************************************************************
    * Type        : eSecurityType2Levels
    * Name        : SecureLevel
    * Description : To hold the securelevel in MEET_TYPE2_SecurityAlgorithm
    *************************************************************************************/
    extern eSecurityType2Levels SecureLevel; 

#elif defined(MEET_TYPE3_SecurityAlgorithm)
    #define TYPE3SECURITY_FACTOR1 0x03U
    #define TYPE3SECURITY_FACTOR2 0x05U
    #define TYPE3SECURITY_OFFSET  0x9A56U
#else
#endif
    
    




/*=====================================================================================================================
*   P U B L I C
**=====================================================================================================================*/

    /************************************************************************************
    * Define the required APIs in application modules.(configured in Dcm_Lcfg.h)
    * The below list is given for reference.
    *************************************************************************************/
/*
#ifdef MEET_TYPE1_SecurityAlgorithm
    extern FUNC(Std_ReturnType, RTE_MEET_CDD_APPL_CODE) SecurityGetSeed(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MEET_CDD_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_MEET_CDD_APPL_VAR) ErrorCode); 
    extern FUNC(Std_ReturnType, RTE_MEET_CDD_APPL_CODE) SecurityCompareKey(P2VAR(uint8, AUTOMATIC, RTE_MEET_CDD_APPL_VAR) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_MEET_CDD_APPL_VAR) ErrorCode);
   
#elif defined(MEET_TYPE2_SecurityAlgorithm)
    extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DspSecLvl1GetSeedFnc(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
    extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DspSecLevel1CmpKeyFnc(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Key, Dcm_OpStatusType OpStatus);
    extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DspSecLvl3GetSeedFnc(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode);
    extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DspSecLevel3CmpKeyFnc(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Key, Dcm_OpStatusType OpStatus);
#else
#endif
*/

#ifdef MEET_TYPE1_SecurityAlgorithm
    Std_ReturnType SendKeyToCalculate(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT)YY1,P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT)YY2);

#elif defined(MEET_TYPE2_SecurityAlgorithm)
    uint32 GetLevelConstant_Type2Security(eSecurityType2Levels level);
    uint32 GetSeed_4bytes(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Seed);
    Std_ReturnType CompareKey4bytes(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Key, uint32 Calculated_key);
#elif defined(MEET_TYPE3_SecurityAlgorithm)
    void GetSeed_4bytes(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Seed);
    Std_ReturnType SendKeyToCalculate(P2VAR(UInt8, AUTOMATIC, RTE_MEETCDD_APPL_VAR)p_calculated_key_U8A);
    Std_ReturnType GetSecurity_Unlock_Status(void);
    void SetSecurity_Unlock_Status(uint8 p_status_U8);

#else
#endif



/*======================================================================================================================
**  for each change to this file, be sure to record:
**  1.who made the change and when the change was made
**  2.why the change was made and the intended result
**  following block needs to be repeated for each change
**======================================================================================================================*/
/*   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.     
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  
**   other reason                                                             
**======================================================================================================================*/ 
/*=====================================================================================================================
** Date              :  06-Oct-2018
** CDSID             :  dkasiman
** Traceability      :  RTC: 1212263
** Change Description:  Interface provided to application to update the security unlock status when session time out.
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
** Change Description:  1. Variables l_SecLvl1_SeedSend_U32 and uint32 l_diag_calculated_key_U32 renamed as
**                      SeedSend_U32, Calculated_key_U32.
**                      2. MISRA warning fixes.
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
#endif //SECUREDIAGCDD_CFG_H



