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
** Name:           Securediagcdd_cfg$.c
**
** Description:    
**                 
**
**===================================================================================================================*/

#ifndef SECUREDIAGCDD_CFG_C
#define SECUREDIAGCDD_CFG_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/
#include "Mgrdiagcdd.h"
#include "Securediagcdd_cfg.h"
#include "osek.h"

/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S 
**====================================================================================================================*/
     

/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef MEET_TYPE2_SecurityAlgorithm

    /************************************************************************************
    * Type        : uint32                                                               
    * Name        : SeedSend_U32                                             
    * Description : variable to hold the Seed generated in level 1 or level 3 of                 
    *               MEET_TYPE2_SecurityAlgorithm as per SMRS                          
    *************************************************************************************/ 
    uint32 SeedSend_U32;  

    /************************************************************************************
    * Type        : uint32                                                               
    * Name        : Calculated_key_U32                                             
    * Description : variable to hold the calculated Key in level 1 or level 3 of                 
    *               MEET_TYPE2_SecurityAlgorithm as per SMRS                          
    *************************************************************************************/ 
    uint32 Calculated_key_U32;

#endif
#ifdef MEET_TYPE3_SecurityAlgorithm
    /************************************************************************************
    * Type        : uint32                                                               
    * Name        : SeedSend_U32                                             
    * Description : variable to hold the Seed generated in level 1 or level 3 of                 
    *               MEET_TYPE3_SecurityAlgorithm as per SMRS                          
    *************************************************************************************/ 
    uint32 SeedSend_U32;  
    uint8 l_security_unlock_status_U8;  

#endif
/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/

#ifdef MEET_TYPE1_SecurityAlgorithm
/*=====================================================================================================================
**
** Function Name    :  Name
**
** Visibility       :  Public/private 
**
** Description      :
**
** Invocation       :
**
** Inputs           :  Input arguments.
**
** Outputs          :  output arguments
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

#endif /*MEET_TYPE1_SecurityAlgorithm*/


#ifdef MEET_TYPE2_SecurityAlgorithm
/*=====================================================================================================================
**
** Function Name    :  GetLevelConstant_Type2Security
**
** Visibility       :  Public/private 
**
** Description      :   Get the predefined constant for Seed/Key calculation
**                      based on the requested security level.
**
** Invocation       :   Securediagcdd wrapper layer
**
** Inputs           :  eSecurityType2Levels
**
** Outputs          :  uint32 Constant values.
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
uint32 GetLevelConstant_Type2Security(eSecurityType2Levels level)
{
    uint32 fl_levelConstant = 0;
    
    if( Level1 == level)
    {
        fl_levelConstant = TYPE2_LEVEL1CONSTANT;
    }
    else if( Level3 == level)
    {
        fl_levelConstant = TYPE2_LEVEL3CONSTANT;
    }
    else
    {
        /*Do nothing*/
    }

   return (fl_levelConstant);
}

/*============================================================================
**
** Function Name    :   GetSeed_4bytes
**
** Visibility       :   Public
**
** Description      :   Get 4 bytes Seed -Visteon
**
** Invocation       :   Securediagcdd wrapper layer
**
** Inputs           :   Seed
**
** Outputs          :   4 bytes key
**
** Critical Section :   No
**
**==========================================================================*/
uint32 GetSeed_4bytes(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Seed)
{
    uint32 fl_key_U32 = 0;
    
    uint16 fl_seed_hi_U16;
    uint16 fl_seed_lo_U16;
    uint32 fl_seed_value_U32;
    uint32 fl_datamatrix_U32;
    

    (void)GetCounterValue(SystemTimer, &SeedSend_U32);
    fl_seed_hi_U16 = (uint16)SeedSend_U32;
    fl_seed_lo_U16 = (uint16)SeedSend_U32;

    fl_datamatrix_U32 = 0xFFFFFFFFuL;

    fl_seed_value_U32 = ((uint32)fl_seed_hi_U16<<16);
    fl_seed_value_U32 |= fl_seed_lo_U16;

    Seed[0] = (uint8) ((fl_seed_hi_U16 >>8u) & 0xFFu);
    Seed[1] = (uint8) (fl_seed_hi_U16 & 0xFFu);
    Seed[2] = (uint8) ((fl_seed_lo_U16 >>8u) & 0xFFu);
    Seed[3] = (uint8) (fl_seed_lo_U16 & 0xFFu);

    fl_key_U32 = fl_seed_value_U32 ^ fl_datamatrix_U32;
    
    return(fl_key_U32);
}

/*============================================================================
**
** Function Name    :   CompareKey4bytes
**
** Visibility       :   Public
**
** Description      :   Security Level3 Compare Seed -Visteon
**
** Invocation       :   Securediagcdd wrapper layer
**
** Inputs           :   Received Key & Calculated Key
**
** Outputs          :   Std_ReturnType
**
** Critical Section :  No
**
**==========================================================================*/
Std_ReturnType CompareKey4bytes(P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) Key, uint32 Calculated_key)
{
    Std_ReturnType Ret;
    
  
    if((Key[0] == (uint8) ((Calculated_key >> 24) & (uint8)0xFF)) &&
       (Key[1] == (uint8) ((Calculated_key >> 16) & (uint8)0xFF)) &&
       (Key[2] == (uint8) ((Calculated_key >> 8) & (uint8)0xFF)) &&
       (Key[3] == (uint8) (Calculated_key  & (uint8)0xFF)))
    {
        Ret = DCM_E_OK;
    }
    else
    {
        Ret = DCM_E_COMPARE_KEY_FAILED;
    }
    return Ret;
} 

#endif  /*MEET_TYPE2_SecurityAlgorithm*/

#ifdef MEET_TYPE3_SecurityAlgorithm
/*============================================================================
**
** Function Name    :   GetSeed_4bytes
**
** Visibility       :   Public
**
** Description      :   Get 4 bytes Seed - MMC OEM
**
** Invocation       :   Securediagcdd wrapper layer
**
** Inputs           :   Seed
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
void GetSeed_4bytes(P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) Seed)
{
    
    uint16 fl_seed_hi_U16;
    uint16 fl_seed_lo_U16;
    uint32 fl_seed_value_U32;
    

    (void)GetCounterValue(SystemTimer, &SeedSend_U32);
    if( SeedSend_U32 == 0)
    {
        SeedSend_U32 = 0x203478ACU;
    }
    else
    {
    }
    SeedSend_U32 ^= SeedSend_U32 << 5U;
    SeedSend_U32 ^= SeedSend_U32 >> 27U;
    SeedSend_U32 ^= SeedSend_U32 << 21U;

    fl_seed_hi_U16 = (uint16)SeedSend_U32;
    fl_seed_lo_U16 = (uint16)SeedSend_U32;


    fl_seed_value_U32 = ((uint32)fl_seed_hi_U16<<16);
    fl_seed_value_U32 |= fl_seed_lo_U16;

    Seed[0] = (uint8) ((fl_seed_hi_U16 >>8u) & 0xFFu);
    Seed[1] = (uint8) (fl_seed_hi_U16 & 0xFFu);
    Seed[2] = (uint8) ((fl_seed_lo_U16 >>8u) & 0xFFu);
    Seed[3] = (uint8) (fl_seed_lo_U16 & 0xFFu);

}
Std_ReturnType GetSecurity_Unlock_Status(void)
{
    return l_security_unlock_status_U8;
}
void SetSecurity_Unlock_Status(uint8 p_status_U8)
{
   l_security_unlock_status_U8 = p_status_U8;
}
#endif

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
** Date              :  06-Oct-2018
** CDSID             :  dkasiman
** Traceability      :  RTC: 1212264
** Change Description:  Seed value generation algorithm changed slightly to not have the alternate/repeated/cosecutive
                        /fixed pattern.
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
#endif /*SECUREDIAGCDD_CFG_C*/

