/**
*   @file    Reg_eSys_Mu.h
*   @version 4.0.0
*
*   @brief   AUTOSAR Mcl - MU Registers and Macros Definitions.
*   @details MU Registers and Macros Definitions.
*
*   @addtogroup MU_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : eDMA
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : IMX8_MCAL_4_0_0_RTM_ASR_REL_4_2_REV_0002_20210812
*
*   Copyright 2006-2016 Freescale Semiconductor, Inc. 
*   Copyright 2017 - 2021 NXP
*   NXP Confidential. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

/**
@file        Reg_eSys_Mu.h
*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_MU_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Reg_eSys_MU_REF_2
*Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser,
*a constant, a parenthesised expression, a type qualifier, a storage class specifier, or a
*do-while-zero construct.
*This is used to abstract the export of configuration sets or for a function define.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars
* for identifiers.
*
*/


#ifndef REG_ESYS_MU_H
#define REG_ESYS_MU_H


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the
*            contents of a header file being included twice
*/
#include "Reg_eSys.h"
#include "StdRegMacros.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_Mu.h
* @requirements
*/
#define MU_VENDOR_ID_REG                       43
#define MU_AR_RELEASE_MAJOR_VERSION_REG        4
#define MU_AR_RELEASE_MINOR_VERSION_REG        2
#define MU_AR_RELEASE_REVISION_VERSION_REG     2
#define MU_SW_MAJOR_VERSION_REG                4
#define MU_SW_MINOR_VERSION_REG                0
#define MU_SW_PATCH_VERSION_REG                0


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Reg_eSys.h header file are of the same Autosar version */
    #if ((REG_ESYS_AR_RELEASE_MAJOR_VERSION != MU_AR_RELEASE_MAJOR_VERSION_REG) || \
         (REG_ESYS_AR_RELEASE_MINOR_VERSION != MU_AR_RELEASE_MINOR_VERSION_REG))
        #error "AutoSar Version Numbers of Reg_eSys.h and Reg_eSys_Mu.h are different"
    #endif
    /* Check if header file and StdRegMacros.h header file are of the same Autosar version */
    #if ((STDREGMACROS_AR_RELEASE_MAJOR_VERSION != MU_AR_RELEASE_MAJOR_VERSION_REG) || \
         (STDREGMACROS_AR_RELEASE_MINOR_VERSION != MU_AR_RELEASE_MINOR_VERSION_REG))
        #error "AutoSar Version Numbers of StdRegMacros.h and Reg_eSys_Mu.h are different"
    #endif
#endif
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/******* Define the address of MUs to interface with SCU from core M4-0, M4-1 core ***************************************/
#ifdef MU1_A_M4_0_BASEADDR
    #define MU1_A_M4_0              (MU1_A_M4_0_BASEADDR)
    #define MU1_A_M4_0_AVAILABLE    1U
#else
    #define MU1_A_M4_0_AVAILABLE    0U
#endif /* MU1_A_M4_0_BASE */

#ifdef MU1_A_M4_1_BASEADDR
    #define MU1_A_M4_1              (MU1_A_M4_1_BASEADDR)
    #define MU1_A_M4_1_AVAILABLE    1U
#else
    #define MU1_A_M4_1_AVAILABLE    0U
#endif /* MU1_A_M4_1_BASE */

#define MU_NB_INSTANCES             (MU1_A_M4_0_AVAILABLE + MU1_A_M4_1_AVAILABLE)

/**
* @brief Processor A/B Transmit Register 0 Offset
*/
#define MU_TR0_OFFSET_U32      ((uint32)0x00U)
/**
* @brief Processor A/B Transmit Register 1 Offset
*/
#define MU_TR1_OFFSET_U32      ((uint32)0x04U)
/**
* @brief Processor A/B Transmit Register 2 Offset
*/
#define MU_TR2_OFFSET_U32      ((uint32)0x08U)
/**
* @brief Processor A/B Transmit Register 3 Offset
*/
#define MU_TR3_OFFSET_U32      ((uint32)0x0CU)
/**
* @brief Processor A/B Receive Register 0 Offset
*/
#define MU_RR0_OFFSET_U32      ((uint32)0x10U)
/**
* @brief Processor A/B Receive Register 1 Offset
*/
#define MU_RR1_OFFSET_U32      ((uint32)0x14U)
/**
* @brief Processor A/B Receive Register 2 Offset
*/
#define MU_RR2_OFFSET_U32      ((uint32)0x18U)
/**
* @brief Processor A/B Receive Register 3 Offset
*/
#define MU_RR3_OFFSET_U32      ((uint32)0x1CU)
/**
* @brief Processor A/B Status Register Offset
*/
#define MU_SR_OFFSET_U32      ((uint32)0x20U)
/**
* @brief Processor A/B Control Register Offset
*/
#define MU_CR_OFFSET_U32      ((uint32)0x24U)

/**********************************************************
*         Define fields in the Control Register           *
***********************************************************/
/*********** Defines for both sides A and B ***************/
/**
* @brief Processor A/B General Purpose Interrupt Enable n (GIEn bits)
*/
#define MU_CR_GIEn_MASK        ((uint32)0xF0000000U)
#define MU_CR_GIEn_SHIFT       ((uint32)28U)

/**
* @brief Processor A/B Receive Interrupt Enable n (RIEn bits)
*/
#define MU_CR_RIEn_MASK        ((uint32)0x0F000000U)
#define MU_CR_RIEn_SHIFT       ((uint32)24U)

/**
* @brief Processor A/B Transmit Interrupt Enable n (TIEn bits)
*/
#define MU_CR_TIEn_MASK        ((uint32)0x00F00000U)
#define MU_CR_TIEn_SHIFT       ((uint32)20U)

/**
* @brief Processor A/B General Purpose Interrupt Request n (TIEn bits)
*/
#define MU_CR_GIRn_MASK             ((uint32)0x000F0000U)
#define MU_CR_GIRn_SHIFT            ((uint32)16U)
#define MU_ACR_GIR3_BIT_MASK_U32    (BIT16)
/**
* @brief Processor CR bits field
*/
#define MU_CR_Fn_MASK          ((uint32)0x00000007U)
#define MU_CR_Fn_SHIFT         ((uint32)0U)


/*********** Defines for A side ***************************/
/**
* @brief Processor B Reset De-assertion Interrupt Enable (BRDIE bit)
*/
#define MU_ACR_BRDIE_MASK        ((uint32)0x00000040U)
#define MU_ACR_BRDIE_SHIFT       ((uint32)6U)

/**
* @brief Processor A MU Reset (MUR bit)
*/
#define MU_ACR_MUR_MASK        ((uint32)0x00000020U)
#define MU_ACR_MUR_SHIFT       ((uint32)5U)

/**
* @brief Processor B Hardware Reset (BHR bit)
*/
#define MU_ACR_BHR_MASK        ((uint32)0x00000010U)
#define MU_ACR_BHR_SHIFT       ((uint32)4U)

/**
* @brief Processor A to Processor B Flag n. (ABFn bits)
*/
#define MU_ACR_ABFn_MASK        ((uint32)0x00000007U)
#define MU_ACR_ABFn_SHIFT       ((uint32)0U)

/*********** Defines for B side ***************************/
/**
* @brief Processor B Hardware Reset Mask. (HRM bit)
*/
#define MU_BCR_HRM_MASK        ((uint32)0x00000010U)
#define MU_BCR_HRM_SHIFT       ((uint32)4U)

/**
* @brief Processor B to Processor A Flag n. (BAFn bits)
*/
#define MU_BCR_ABFn_MASK        ((uint32)0x00000007U)
#define MU_BCR_ABFn_SHIFT       ((uint32)0U)

#define MUC_ACR_MASKS           ((uint32)(MU_CR_GIEn_MASK | MU_CR_RIEn_MASK | MU_CR_TIEn_MASK | MU_ACR_BRDIE_MASK | MU_ACR_MUR_MASK | MU_ACR_BHR_MASK | MU_ACR_ABFn_MASK))
#define MUC_BCR_MASKS           ((uint32)(MU_CR_GIEn_MASK | MU_CR_RIEn_MASK | MU_CR_TIEn_MASK | MU_BCR_HRM_MASK | MU_BCR_ABFn_MASK))
/**********************************************************
*         Define fields in the Status Register            *
***********************************************************/
/*********** Defines for both sides A and B ***************/
/**
* @brief Processor A/B General Interrupt Request n Pending (GIPn bits)
*/
#define MU_SR_GIPn_MASK        ((uint32)0xF0000000U)
#define MU_SR_GIPn_SHIFT       ((uint32)28U)

/**
* @brief Processor A/B Receive Register n Full (RFn bits)
*/
#define MU_SR_RFn_MASK        ((uint32)0x0F000000U)
#define MU_SR_RFn_SHIFT       ((uint32)24U)

/**
* @brief  Processor A/B Transmit Register n Empty (TEn bits)
*/
#define MU_SR_TEn_MASK        ((uint32)0x00F00000U)
#define MU_SR_TEn_SHIFT       ((uint32)20U)

/**
* @brief  Processor A/B Flags Update Pending. (FUP bit)
*/
#define MU_SR_FUP_MASK        ((uint32)0x00000100U)
#define MU_SR_FUP_SHIFT       ((uint32)8U)

/**
* @brief  Processor A/B-Side Event Pending (EP bit)
*/
#define MU_SR_EP_MASK        ((uint32)0x00000010U)
#define MU_SR_EP_SHIFT       ((uint32)4U)

/**
* @brief  Processor A/B-Side Event Pending (Fn bits)
*/
#define MU_SR_Fn_MASK        ((uint32)0x00000007U)
#define MU_SR_Fn_SHIFT       ((uint32)0U)

/*********** Defines for A side ***************************/
/**
* @brief  Processor B Reset De-asserted Interrupt Pending (BRDIP bit)
*/
#define MU_ASR_BRDIP_MASK        ((uint32)0x00000200U)
#define MU_ASR_BRDIP_SHIFT       ((uint32)9U)

/**
* @brief  Processor B-side Reset State (BRS bits)
*/
#define MU_ASR_BRS_MASK        ((uint32)0x00000080U)
#define MU_ASR_BRS_SHIFT       ((uint32)7U)

/*********** Defines for B side ***************************/
/**
* @brief  Processor A Reset State (ARS bit)
*/
#define MU_BSR_ARS_MASK        ((uint32)0x00000080U)
#define MU_BSR_ARS_SHIFT       ((uint32)7U)

/**
* @brief  Processor A Power Mode (APM bit)
*/
#define MU_BSR_APM_MASK        ((uint32)0x00000060U)
#define MU_BSR_APM_SHIFT       ((uint32)5U)

#define MUC_ASR_MASKS          ((uint32)(MU_SR_GIPn_MASK | MU_SR_RFn_MASK | MU_SR_TEn_MASK | MU_SR_FUP_MASK | MU_SR_EP_MASK | MU_SR_Fn_MASK | MU_ASR_BRDIP_MASK | MU_ASR_BRS_MASK))
#define MUC_BSR_MASKS          ((uint32)(MU_SR_GIPn_MASK | MU_SR_RFn_MASK | MU_SR_TEn_MASK | MU_SR_FUP_MASK | MU_SR_EP_MASK | MU_SR_Fn_MASK | MU_BSR_ARS_MASK | MU_BSR_APM_MASK))

/**
* @brief  Processor A/B-Side Receive Buffer Length
*/
#define MU_RR_COUNT            ((uint32)4U)
/**
* @brief  Processor A/B-Side Transmit Buffer Length
*/
#define MU_TR_COUNT            ((uint32)4U)

/* Macros relate to the Status Register for A side */
/** @violates @ref Reg_eSys_MU_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/** @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MU_ASR_GET_ALL(BaseAddr)        REG_READ32((uint32)(BaseAddr) + MU_SR_OFFSET_U32)
/** @violates @ref Reg_eSys_MU_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/** @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MU_ASR_GET_GIPn(BaseAddr)       (uint32)((uint32)(REG_READ32((uint32)(BaseAddr) + MU_SR_OFFSET_U32) & MU_SR_GIPn_MASK) >> MU_SR_GIPn_SHIFT)
/** @violates @ref Reg_eSys_MU_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/** @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MU_ASR_GET_RFn(BaseAddr)        (uint32)((uint32)(REG_READ32((uint32)(BaseAddr) + MU_SR_OFFSET_U32) & MU_SR_RFn_MASK) >> MU_SR_RFn_SHIFT)
/** @violates @ref Reg_eSys_MU_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/** @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MU_ASR_GET_TEn(BaseAddr)        (uint32)((uint32)(REG_READ32((uint32)(BaseAddr) + MU_SR_OFFSET_U32) & MU_SR_TEn_MASK) >> MU_SR_TEn_SHIFT)
/** @violates @ref Reg_eSys_MU_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/** @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MU_ASR_GET_FUP(BaseAddr)        (uint32)((uint32)(REG_READ32((uint32)(BaseAddr) + MU_SR_OFFSET_U32) & MU_SR_FUP_MASK) >> MU_SR_FUP_SHIFT)
/** @violates @ref Reg_eSys_MU_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/** @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MU_ASR_GET_EP(BaseAddr)         (uint32)((uint32)(REG_READ32((uint32)(BaseAddr) + MU_SR_OFFSET_U32) & MU_SR_EP_MASK) >> MU_SR_EP_SHIFT)
/** @violates @ref Reg_eSys_MU_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/** @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MU_ASR_GET_Fn(BaseAddr)         (uint32)((uint32)(REG_READ32((uint32)(BaseAddr) + MU_SR_OFFSET_U32) & MU_SR_Fn_MASK) >> MU_SR_Fn_SHIFT)
/** @violates @ref Reg_eSys_MU_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/** @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MU_ASR_GET_BRDIP(BaseAddr)      (uint32)((uint32)(REG_READ32((uint32)(BaseAddr) + MU_SR_OFFSET_U32) & MU_ASR_BRDIP_MASK) >> MU_ASR_BRDIP_SHIFT)
/** @violates @ref Reg_eSys_MU_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/** @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MU_ASR_GET_BRS(BaseAddr)        (uint32)((uint32)(REG_READ32((uint32)(BaseAddr) + MU_SR_OFFSET_U32) & MU_ASR_BRS_MASK) >> MU_ASR_BRS_SHIFT)

/* Macros relate to the Control Register for B side */
/** @violates @ref Reg_eSys_MU_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/** @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MU_BSR_GET_ALL(BaseAddr)        REG_READ32((uint32)(BaseAddr) + MU_SR_OFFSET_U32)
/** @violates @ref Reg_eSys_MU_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/** @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MU_BSR_GET_GIPn(BaseAddr)       (uint32)((uint32)(REG_READ32((uint32)(BaseAddr) + MU_SR_OFFSET_U32) & MU_SR_GIPn_MASK) >> MU_SR_GIPn_SHIFT)
/** @violates @ref Reg_eSys_MU_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/** @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MU_BSR_GET_RFn(BaseAddr)        (uint32)((uint32)(REG_READ32((uint32)(BaseAddr) + MU_SR_OFFSET_U32) & MU_SR_RFn_MASK) >> MU_SR_RFn_SHIFT)
/** @violates @ref Reg_eSys_MU_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/** @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MU_BSR_GET_TEn(BaseAddr)        (uint32)((uint32)(REG_READ32((uint32)(BaseAddr) + MU_SR_OFFSET_U32) & MU_SR_TEn_MASK) >> MU_SR_TEn_SHIFT)
/** @violates @ref Reg_eSys_MU_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/** @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MU_BSR_GET_FUP(BaseAddr)        (uint32)((uint32)(REG_READ32((uint32)(BaseAddr) + MU_SR_OFFSET_U32) & MU_SR_FUP_MASK) >> MU_SR_FUP_SHIFT)
/** @violates @ref Reg_eSys_MU_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/** @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MU_BSR_GET_EP(BaseAddr)         (uint32)((uint32)(REG_READ32((uint32)(BaseAddr) + MU_SR_OFFSET_U32) & MU_SR_EP_MASK) >> MU_SR_EP_SHIFT)
/** @violates @ref Reg_eSys_MU_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/** @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MU_BSR_GET_Fn(BaseAddr)         (uint32)((uint32)(REG_READ32((uint32)(BaseAddr) + MU_SR_OFFSET_U32) & MU_SR_Fn_MASK) >> MU_SR_Fn_SHIFT)
/** @violates @ref Reg_eSys_MU_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/** @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MU_BSR_GET_ARS(BaseAddr)        (uint32)((uint32)(REG_READ32((uint32)(BaseAddr) + MU_SR_OFFSET_U32) & MU_BSR_ARS_MASK) >> MU_BSR_ARS_SHIFT)
/** @violates @ref Reg_eSys_MU_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/** @violates @ref Reg_eSys_MU_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */
#define MU_BSR_GET_APM(BaseAddr)        (uint32)((uint32)(REG_READ32((uint32)(BaseAddr) + MU_SR_OFFSET_U32) & MU_BSR_APM_MASK) >> MU_BSR_APM_SHIFT)

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif


#endif /* REG_ESYS_MU_H */

/** @} */
