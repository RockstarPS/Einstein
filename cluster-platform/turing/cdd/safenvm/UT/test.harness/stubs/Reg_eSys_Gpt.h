/**
*   @file           Reg_eSys_GPT.h
*   @version        4.0.0
*
*   @brief          AUTOSAR Mcl - GPT register and bitfield defines.
*   @details        GPT register and bitfield defines, used by driver that access the GPT resources.
*
*   @addtogroup     GPT_MODULE
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

#ifndef REG_ESYS_GPT_H
#define REG_ESYS_GPT_H

#ifdef __cplusplus
extern "C" {
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section [global]
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
* This violation is due to function like macro defined for register operations.
* Function like macro are used to reduce code complexity.
*
* @section Reg_eSys_GPT_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Reg_eSys_GPT_H_REF_2
* Violates MISRA 2004 Required Rule 8.12, Array size not defined
* This violation is  due to the fact that this file is shared by multiple drivers: GPT, PWM and ICU.
* The array size depends by the number of eTimer modules used by all drivers. The eTimer common component
* driver doesn't have yet its own plugin which could be used to generate the common parameters.
*
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/

#include "Reg_eSys.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file         Reg_eSys_Gpt.h
*/
#define REG_ESYS_GPT_VENDOR_ID                    43
#define REG_ESYS_GPT_MODULE_ID                    255

/* @violates @ref Reg_eSys_GPT_H_REF_1 Identifier clash. */
#define REG_ESYS_GPT_AR_RELEASE_MAJOR_VERSION     4
/* @violates @ref Reg_eSys_GPT_H_REF_1 Identifier clash. */
#define REG_ESYS_GPT_AR_RELEASE_MINOR_VERSION     2
/* @violates @ref Reg_eSys_GPT_H_REF_1 Identifier clash. */
#define REG_ESYS_GPT_AR_RELEASE_REVISION_VERSION  2
#define REG_ESYS_GPT_SW_MAJOR_VERSION             4
#define REG_ESYS_GPT_SW_MINOR_VERSION             0
#define REG_ESYS_GPT_SW_PATCH_VERSION             0
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Reg_eSys_Gpt.h file and Reg_eSys.h are of the same Autosar version */
    #if ((REG_ESYS_GPT_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_GPT_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Reg_eSys_Gpt.h and Reg_eSys.h are different"
    #endif
#endif

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/*==================================================================================================
*                                GLOBAL DEFINES & DECLARATIONS
==================================================================================================*/
#define MCL_START_SEC_CONST_32

/** @violates @ref Reg_eSys_GPT_H_REF_1 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"

/**
* @brief GPT base address array declaration
* @violates @ref Reg_eSys_GPT_H_REF_2 Array size not defined
*/
extern CONST(uint32, MCL_CONST) GPT_BASE_ADDR32[];

#define MCL_STOP_SEC_CONST_32

/** @violates @ref Reg_eSys_GPT_H_REF_1 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief GPT module decoding
*/
#define GPT_MODULE_INDEX_U8(ch)      ((uint8)((ch) / GPT_GPT_CH_PER_MODULE))
/**
* @brief GPT channel decoding
*/
#define GPT_CHANNEL_INDEX_U8(ch)     ((uint8)((ch) % GPT_GPT_CH_PER_MODULE))

/**
* @brief ICU module decoding
*/
#define ICU_GPT_MODULE_INDEX(ch)      ((uint8)((ch) / ICU_GPT_CH_PER_MODULE))
/**
* @brief ICU channel decoding
*/
#define ICU_GPT_CHANNEL_INDEX(ch)     ((uint8)((ch) % ICU_GPT_CH_PER_MODULE))

/**
* @{
* @brief GPT Module Registers - Channel specific registers.
*/
#define GPT_OCR_ADDR32(u8ModuleIdx, u8ChannelIdx)   (GPT_BASE_ADDR32[(u8ModuleIdx)] + ((uint32)((uint32)(u8ChannelIdx)<<(2UL)) + 0x10UL))
#define GPT_ICR_ADDR32(u8ModuleIdx, u8ChannelIdx)   (GPT_BASE_ADDR32[(u8ModuleIdx)] + ((uint32)((uint32)(u8ChannelIdx)<<(2UL)) + 0x1CUL))

/**
* @{
* @brief GPT Module Registers - Configuration registers.
*/
#define GPT_CR_ADDR32(u8ModuleIdx)                  (GPT_BASE_ADDR32[(u8ModuleIdx)])
#define GPT_PR_ADDR32(u8ModuleIdx)                  ((uint32)(GPT_BASE_ADDR32[(u8ModuleIdx)] + 0x04U))
#define GPT_SR_ADDR32(u8ModuleIdx)                  ((uint32)(GPT_BASE_ADDR32[(u8ModuleIdx)] + 0x08U))
#define GPT_IR_ADDR32(u8ModuleIdx)                  ((uint32)(GPT_BASE_ADDR32[(u8ModuleIdx)] + 0x0CU))
#define GPT_CNT_ADDR32(u8ModuleIdx)                 ((uint32)(GPT_BASE_ADDR32[(u8ModuleIdx)] + 0x24U))


/** MASK and SHIFT values for each register field */
/**
@{
* @brief GPTx_CR - Control Register - bitfield mask and shift defines.
*/

#define GPT_CR_FO3_MASK_U32         ((uint32)(BIT31))
#ifndef GPT_CR_FO3_SHIFT
#define GPT_CR_FO3_SHIFT            ((uint32)(31U))
#endif

#define GPT_CR_FO2_MASK_U32         ((uint32)(BIT30))
#ifndef GPT_CR_FO2_SHIFT
#define GPT_CR_FO2_SHIFT            ((uint32)(30U))
#endif

#define GPT_CR_FO1_MASK_U32         ((uint32)(BIT29))
#ifndef GPT_CR_FO1_SHIFT
#define GPT_CR_FO1_SHIFT            ((uint32)(29U))
#endif

#define GPT_CR_OM3_MASK_U32         ((uint32)(BIT28|BIT27|BIT26))
#ifndef GPT_CR_OM3_SHIFT
#define GPT_CR_OM3_SHIFT            ((uint32)(26U))
#endif

#define GPT_CR_OM2_MASK_U32         ((uint32)(BIT25|BIT24|BIT23))
#ifndef GPT_CR_OM2_SHIFT
#define GPT_CR_OM2_SHIFT            ((uint32)(23U))
#endif

#define GPT_CR_OM1_MASK_U32         ((uint32)(BIT22|BIT21|BIT20))
#ifndef GPT_CR_OM1_SHIFT
#define GPT_CR_OM1_SHIFT            ((uint32)(20U))
#endif

#define GPT_CR_IM2_MASK_U32         ((uint32)(BIT19|BIT18))
#ifndef GPT_CR_IM2_SHIFT
#define GPT_CR_IM2_SHIFT            ((uint32)(18U))
#endif

#define GPT_CR_IM1_MASK_U32         ((uint32)(BIT17|BIT16))
#ifndef GPT_CR_IM1_SHIFT
#define GPT_CR_IM1_SHIFT            ((uint32)(16U))
#endif

#define GPT_CR_SWR_MASK_U32         ((uint32)(BIT15))
#ifndef GPT_CR_SWR_SHIFT
#define GPT_CR_SWR_SHIFT            ((uint32)(15U))
#endif

#define GPT_CR_EN24M_MASK_U32       ((uint32)(BIT10))
#ifndef GPT_CR_EN24M_SHIFT
#define GPT_CR_EN24M_SHIFT          ((uint32)(10U))
#endif

#define GPT_CR_FRR_MASK_U32         ((uint32)(BIT9))
#ifndef GPT_CR_FRR_SHIFT
#define GPT_CR_FRR_SHIFT            ((uint32)(9U))
#endif

#define GPT_CR_CLKSRC_MASK_U32      ((uint32)(BIT8|BIT7|BIT6))
#ifndef GPT_CR_CLKSRC_SHIFT
#define GPT_CR_CLKSRC_SHIFT         ((uint32)(6U))
#endif

#define GPT_CR_STOPEN_MASK_U32      ((uint32)(BIT5))
#ifndef GPT_CR_STOPEN_SHIFT
#define GPT_CR_STOPEN_SHIFT         ((uint32)(5U))
#endif

#define GPT_CR_DOZEEN_MASK_U32      ((uint32)(BIT4))
#ifndef GPT_CR_DOZEEN_SHIFT
#define GPT_CR_DOZEEN_SHIFT         ((uint32)(4U))
#endif

#define GPT_CR_WAITEN_MASK_U32      ((uint32)(BIT3))
#ifndef GPT_CR_WAITEN_SHIFT
#define GPT_CR_WAITEN_SHIFT         ((uint32)(3U))
#endif

#define GPT_CR_DBGEN_MASK_U32       ((uint32)(BIT2))
#ifndef GPT_CR_DBGEN_SHIFT
#define GPT_CR_DBGEN_SHIFT          ((uint32)(2U))
#endif

#define GPT_CR_ENMOD_MASK_U32       ((uint32)(BIT1))
#ifndef GPT_CR_ENMOD_SHIFT
#define GPT_CR_ENMOD_SHIFT          ((uint32)(1U))
#endif

#define GPT_CR_EN_MASK_U32          ((uint32)(BIT0))
#ifndef GPT_CR_EN_SHIFT
#define GPT_CR_EN_SHIFT             ((uint32)(0U))
#endif

/**
@{
* @brief GPTx_PR - Prescaler Register - bitfield mask and shift defines.
*/
#define GPT_PR_PRESCALER_MASK_U32           ((uint32)(0x00000FFF))
#ifndef GPT_PR_PRESCALER_SHIFT
#define GPT_PR_PRESCALER_SHIFT              ((uint32)(0U))
#endif

#define GPT_PR_PRESCALER24M_MASK_U32        ((uint32)(0x0000F000))
#ifndef GPT_PR_PRESCALER24M_SHIFT
#define GPT_PR_PRESCALER24M_SHIFT           ((uint32)(12U))
#endif

/**
@{
* @brief GPTx_SR - Status Register - bitfield mask and shift defines.
*/
#define GPT_SR_ROV_MASK_U32           ((uint32)(BIT5))
#ifndef GPT_SR_ROV_SHIFT
#define GPT_SR_ROV_SHIFT              ((uint32)(5U))
#endif

#define GPT_SR_IF2_MASK_U32           ((uint32)(BIT4))
#ifndef GPT_SR_IF2_SHIFT
#define GPT_SR_IF2_SHIFT              ((uint32)(4U))
#endif

#define GPT_SR_IF1_MASK_U32           ((uint32)(BIT3))
#ifndef GPT_SR_IF1_SHIFT
#define GPT_SR_IF1_SHIFT              ((uint32)(3U))
#endif

#define GPT_SR_OF3_MASK_U32           ((uint32)(BIT2))
#ifndef GPT_SR_OF3_SHIFT
#define GPT_SR_OF3_SHIFT              ((uint32)(2U))
#endif

#define GPT_SR_OF2_MASK_U32           ((uint32)(BIT1))
#ifndef GPT_SR_OF2_SHIFT
#define GPT_SR_OF2_SHIFT              ((uint32)(1U))
#endif

#define GPT_SR_OF1_MASK_U32           ((uint32)(BIT0))
#ifndef GPT_SR_OF1_SHIFT
#define GPT_SR_OF1_SHIFT              ((uint32)(0U))
#endif

/**
@{
* @brief GPTx_IR - Status Register - bitfield mask and shift defines.
*/
#define GPT_IR_ROVIE_MASK_U32           ((uint32)(BIT5))
#ifndef GPT_IR_ROVIE_SHIFT
#define GPT_IR_ROVIE_SHIFT              ((uint32)(5U))
#endif

#define GPT_IR_IF2IE_MASK_U32           ((uint32)(BIT4))
#ifndef GPT_IR_IF2IE_SHIFT
#define GPT_IR_IF2IE_SHIFT              ((uint32)(4U))
#endif

#define GPT_IR_IF1IE_MASK_U32           ((uint32)(BIT3))
#ifndef GPT_IR_IF1IE_SHIFT
#define GPT_IR_IF1IE_SHIFT              ((uint32)(3U))
#endif

#define GPT_IR_OF3IE_MASK_U32           ((uint32)(BIT2))
#ifndef GPT_IR_OF3IE_SHIFT
#define GPT_IR_OF3IE_SHIFT              ((uint32)(2U))
#endif

#define GPT_IR_OF2IE_MASK_U32           ((uint32)(BIT1))
#ifndef GPT_IR_OF2IE_SHIFT
#define GPT_IR_OF2IE_SHIFT              ((uint32)(1U))
#endif

#define GPT_IR_OF1IE_MASK_U32           ((uint32)(BIT0))
#ifndef GPT_IR_OF1IE_SHIFT
#define GPT_IR_OF1IE_SHIFT              ((uint32)(0U))
#endif

/** Bitfield defines. */
/**
* @{
* @brief Gpt_CR - bitfield defines.
*/
#define GPT_CR_OM1_DISABLE_U32               ((uint32)(0U))
#define GPT_CR_OM1_TOGGLE_OUTPUT_U32         ((uint32)(1U) << GPT_CR_OM1_SHIFT)
#define GPT_CR_OM1_CLEAR_OUTPUT_U32          ((uint32)(2U) << GPT_CR_OM1_SHIFT)
#define GPT_CR_OM1_SET_OUTPUT_U32            ((uint32)(3U) << GPT_CR_OM1_SHIFT)

#define GPT_CR_FO1_DISABLE_U32               ((uint32)(0U)
#define GPT_CR_FO1_ENABLE_U32                ((uint32)(1U) << GPT_CR_FO1_SHIFT)
/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/



/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/*===============================================================================================
*                            STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
                                     FUNCTION PROTOTYPES
===============================================================================================*/

#ifdef __cplusplus
}
#endif



#endif /* REG_ESYS_GPT_H */

/** @} */
