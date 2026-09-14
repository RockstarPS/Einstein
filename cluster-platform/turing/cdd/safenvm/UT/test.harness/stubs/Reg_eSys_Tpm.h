/**
*   @file           Reg_eSys_FTM.h
*   @version        4.0.0
*
*   @brief          AUTOSAR Mcl - FTM register and bitfield defines.
*   @details        FTM register and bitfield defines, used by driver that access the FTM resources.
*
*   @addtogroup     FTM_MODULE
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

#ifndef REG_ESYS_TPM_H
#define REG_ESYS_TPM_H

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
* @section Reg_eSys_TPM_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Reg_eSys_TPM_H_REF_2
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
* @file         Reg_eSys_Tpm.h
*/
#define REG_ESYS_TPM_VENDOR_ID                    43
#define REG_ESYS_TPM_MODULE_ID                    255

/* @violates @ref Reg_eSys_TPM_H_REF_1 Identifier clash. */
#define REG_ESYS_TPM_AR_RELEASE_MAJOR_VERSION     4
/* @violates @ref Reg_eSys_TPM_H_REF_1 Identifier clash. */
#define REG_ESYS_TPM_AR_RELEASE_MINOR_VERSION     2
/* @violates @ref Reg_eSys_TPM_H_REF_1 Identifier clash. */
#define REG_ESYS_TPM_AR_RELEASE_REVISION_VERSION  2
#define REG_ESYS_TPM_SW_MAJOR_VERSION             4
#define REG_ESYS_TPM_SW_MINOR_VERSION             0
#define REG_ESYS_TPM_SW_PATCH_VERSION             0
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Reg_eSys_Tpm.h file and Reg_eSys.h are of the same Autosar version */
    #if ((REG_ESYS_TPM_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_TPM_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Reg_eSys_Ftm.h and Reg_eSys.h are different"
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

/** @violates @ref Reg_eSys_TPM_H_REF_1 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"
/**
* @brief TPM base address array declaration
* @violates @ref Reg_eSys_TPM_H_REF_2 Array size not defined
*/
extern CONST(uint32, MCL_CONST) TPM_BASE_ADDR32[];

#define MCL_STOP_SEC_CONST_32

/** @violates @ref Reg_eSys_TPM_H_REF_1 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief TPM module decoding
*/

#define TPM_MODULE_INDEX_U8(ch)      ((uint8)((ch) / TPM_CH_PER_MODULE))
/**
* @brief TPM channel decoding
*/
#define TPM_CHANNEL_INDEX_U8(ch)     ((uint8)((ch) % TPM_CH_PER_MODULE))


/**
* @{
* @brief TPM Module Registers - Channel specific registers.
*/
#define TPM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx) (TPM_BASE_ADDR32[(u8ModuleIdx)] + ((uint32)((uint32)(u8ChannelIdx)<<(3UL)) + 0x20UL))
#define TPM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx)  (TPM_BASE_ADDR32[(u8ModuleIdx)] + ((uint32)((uint32)(u8ChannelIdx)<<(3UL)) + 0x24UL))


/**
* @{
* @brief TPM Module Registers - Configuration registers.
*/
#define TPM_VERID_ADDR32(u8ModuleIdx)                               (TPM_BASE_ADDR32[(u8ModuleIdx)])
#define TPM_PARAM_ADDR32(u8ModuleIdx)                               (TPM_BASE_ADDR32[(u8ModuleIdx)] + 0x4CUL)
#define TPM_GLOBAL_ADDR32(u8ModuleIdx)                              (TPM_BASE_ADDR32[(u8ModuleIdx)] + 0x8CUL)
#define TPM_SC_ADDR32(u8ModuleIdx)                                  (TPM_BASE_ADDR32[(u8ModuleIdx)] + 0x10UL)
#define TPM_CNT_ADDR32(u8ModuleIdx)                                 (TPM_BASE_ADDR32[(u8ModuleIdx)] + 0x14UL)
#define TPM_MOD_ADDR32(u8ModuleIdx)                                 (TPM_BASE_ADDR32[(u8ModuleIdx)] + 0x18UL)
#define TPM_STATUS_ADDR32(u8ModuleIdx)                              (TPM_BASE_ADDR32[(u8ModuleIdx)] + 0x1CUL)
#define TPM_COMBINE_ADDR32(u8ModuleIdx)                             (TPM_BASE_ADDR32[(u8ModuleIdx)] + 0x64UL)
#define TPM_TRIG_ADDR32(u8ModuleIdx)                                (TPM_BASE_ADDR32[(u8ModuleIdx)] + 0x6CUL)
#define TPM_POL_ADDR32(u8ModuleIdx)                                 (TPM_BASE_ADDR32[(u8ModuleIdx)] + 0x70UL)
#define TPM_FILTER_ADDR32(u8ModuleIdx)                              (TPM_BASE_ADDR32[(u8ModuleIdx)] + 0x78UL)
#define TPM_QDCTRL_ADDR32(u8ModuleIdx)                              (TPM_BASE_ADDR32[(u8ModuleIdx)] + 0x80UL)
#define TPM_CONF_ADDR32(u8ModuleIdx)                                (TPM_BASE_ADDR32[(u8ModuleIdx)] + 0x84UL)

/** MASK and SHIFT values for each register field */
/**
@{
* @brief TPMx_GLOBAL - Status And Control Register - bitfield mask and shift defines.
*/
#define TPM_GLOBAL_RST_MASK_U32                 ((uint32)(BIT1))
#ifndef TPM_GLOBAL_RST_SHIFT
#define TPM_GLOBAL_RST_SHIFT                    ((uint32)(1U))
#endif
/**
@{
* @brief TPMx_SC - Status And Control Register - bitfield mask and shift defines.
*/
#define TPM_SC_TOF_MASK_U32                 ((uint32)(BIT7))
#ifndef TPM_SC_TOF_SHIFT
#define TPM_SC_TOF_SHIFT                    ((uint32)(7U))
#endif

#define TPM_SC_TOIE_MASK_U32                ((uint32)(BIT6))
#ifndef TPM_SC_TOIE_SHIFT
#define TPM_SC_TOIE_SHIFT                   ((uint32)(6U))
#endif

#define TPM_SC_CPWMS_MASK_U32               ((uint32)(BIT5))
#ifndef TPM_SC_CPWMS_SHIFT
#define TPM_SC_CPWMS_SHIFT                  ((uint32)(5U))
#endif

#define TPM_SC_CMOD_MASK_U32                ((uint32)(BIT4|BIT3))
#ifndef TPM_SC_CMOD_SHIFT
#define TPM_SC_CMOD_SHIFT                   ((uint32)(3U))
#endif

#define TPM_SC_DMA_MASK_U32                 ((uint32)(BIT8))
#ifndef TPM_SC_DMA_SHIFT
#define TPM_SC_DMA_SHIFT                    ((uint32)(8U))
#endif

#define TPM_SC_PS_MASK_U32                  ((uint32)(BIT2|BIT1|BIT0))

/**
@{
* @brief TPMx_CNT - Counter Value - bitfield mask and shift defines.
*/

#define TPM_CNT_COUNT_MASK_U32              ((uint32)(0xFFFFFFFFU))
#define TPM_CNT_COUNT_MASK_SHIFT            ((uint32)(0U))
#define TPM_CNT_COUNT_MAX_VALUE             ((uint32)(0xFFFFFFFF))

/**
* @{
* @brief TPMx_MOD - Modulo Register - bitfield mask and shift defines.
*/

#define TPM_MOD_MOD_MASK_U32                ((uint32)(0xFFFFFFFF))
#define TPM_MOD_MOD_MASK_SHIFT              ((uint32)(0U))
#define TPM_MOD_MOD_MAX_VALUE               ((uint32)(0xFFFFFFFFU))
/**
* @{
* @brief TPMx_CnSC - Channel Status And Control Register - bitfield mask and shift defines.
*/
#define TPM_CSC_CHF_MASK_U32               ((uint32)(BIT7))
#define TPM_CSC_CHF_SHIFT                  ((uint32)(7U))

#define TPM_CSC_CHIE_MASK_U32              ((uint32)(BIT6))
#define TPM_CSC_CHIE_SHIFT                 ((uint32)(6U))

#define TPM_CSC_MSB_MASK_U32               ((uint32)(BIT5))
#define TPM_CSC_MSB_SHIFT                  ((uint32)(5U))

#define TPM_CSC_MSA_MASK_U32               ((uint32)(BIT4))
#define TPM_CSC_MSA_SHIFT                  ((uint32)(4U))

#define TPM_CSC_ELSB_MASK_U32              ((uint32)(BIT3))
#define TPM_CSC_ELSB_SHIFT                 ((uint32)(3U))

#define TPM_CSC_ELSA_MASK_U32              ((uint32)(BIT2))
#define TPM_CSC_ELSA_SHIFT                 ((uint32)(2U))

#define TPM_CSC_DMA_MASK_U32               ((uint32)(BIT0))
#define TPM_CSC_DMA_SHIFT                  ((uint32)(0U))

/**
@{
* @brief TPMx_CnV - Channel Value - bitfield mask and shift defines.
*/
#define TPM_CV_VAL_MASK_U32                  ((uint32)(0xFFFFFFFFU))

/**
@{
* @brief TPMx_STATUS - Capture and Compare Status Register - bitfield mask and shift defines.
*/

#define TPM_STATUS_TOF_MASK_U32            ((uint32)(BIT8))
#ifndef TPM_STATUS_TOF_SHIFT
#define TPM_STATUS_TOF_SHIFT               ((uint32)(8U))
#endif

#define TPM_STATUS_CH5F_MASK_U32            ((uint32)(BIT5))
#ifndef TPM_STATUS_CH5F_SHIFT
#define TPM_STATUS_CH5F_SHIFT               ((uint32)(5U))
#endif

#define TPM_STATUS_CH4F_MASK_U32            ((uint32)(BIT4))
#ifndef TPM_STATUS_CH4F_SHIFT
#define TPM_STATUS_CH4F_SHIFT               ((uint32)(4U))
#endif

#define TPM_STATUS_CH3F_MASK_U32            ((uint32)(BIT3))
#ifndef TPM_STATUS_CH3F_SHIFT
#define TPM_STATUS_CH3F_SHIFT               ((uint32)(3U))
#endif

#define TPM_STATUS_CH2F_MASK_U32            ((uint32)(BIT2))
#ifndef TPM_STATUS_CH2F_SHIFT
#define TPM_STATUS_CH2F_SHIFT               ((uint32)(2U))
#endif

#define TPM_STATUS_CH1F_MASK_U32            ((uint32)(BIT1))
#ifndef TPM_STATUS_CH1F_SHIFT
#define TPM_STATUS_CH1F_SHIFT               ((uint32)(1U))
#endif

#define _STATUS_CH0F_MASK_U32            ((uint32)(BIT0))

/**
@{
* @brief TPMx_COMBINE - Function For Linked Channels - bitfield mask and shift defines.
*/
#define TPM_COMBINE_COMBINE2_MASK_U32   ((uint32)(BIT16))
#ifndef TPM_COMBINE_COMBINE2_SHIFT
#define TPM_COMBINE_COMBINE2_SHIFT      ((uint32)(16U))
#endif

#define TPM_COMBINE_COMSWAP2_MASK_U32    ((uint32)(BIT17))
#ifndef TPM_COMBINE_COMSWAP2_SHIFT
#define TPM_COMBINE_COMSWAP2_SHIFT       ((uint32)(17U))
#endif

#define TPM_COMBINE_COMBINE1_MASK_U32   ((uint32)(BIT8))
#ifndef TPM_COMBINE_COMBINE1_SHIFT
#define TPM_COMBINE_COMBINE1_SHIFT      ((uint32)(8U))
#endif

#define TPM_COMBINE_COMSWAP1_MASK_U32    ((uint32)(BIT9))
#ifndef TPM_COMBINE_COMSWAP1_SHIFT
#define TPM_COMBINE_COMSWAP1_SHIFT       ((uint32)(9U))
#endif

#define TPM_COMBINE_COMBINE0_MASK_U32   ((uint32)(BIT0))

#define TPM_COMBINE_COMSWAP0_MASK_U32    ((uint32)(BIT1))
#ifndef TPM_COMBINE_COMSWAP0_SHIFT
#define TPM_COMBINE_COMSWAP0_SHIFT       ((uint32)(1U))
#endif

/**
@{
* @brief TPMx_TRIG - TPM Channal Trigger - bitfield mask and shift defines.
*/
#define TPM_TRIG_TRIG5_MASK_U32                  ((uint32)(BIT5))
#ifndef TPM_TRIG_TRIG5_SHIFT
#define TPM_TRIG_TRIG5_SHIFT                     ((uint32)(5U))
#endif

#define TPM_TRIG_TRIG4_MASK_U32                  ((uint32)(BIT4))
#ifndef TPM_TRIG_TRIG4_SHIFT
#define TPM_TRIG_TRIG4_SHIFT                     ((uint32)(4U))
#endif

#define TPM_TRIG_TRIG3_MASK_U32                  ((uint32)(BIT3))
#ifndef TPM_TRIG_TRIG3_SHIFT
#define TPM_TRIG_TRIG3_SHIFT                     ((uint32)(3U))
#endif

#define TPM_TRIG_TRIG2_MASK_U32                  ((uint32)(BIT2))
#ifndef TPM_TRIG_TRIG2_SHIFT
#define TPM_TRIG_TRIG2_SHIFT                     ((uint32)(2U))
#endif

#define TPM_TRIG_TRIG1_MASK_U32                  ((uint32)(BIT1))
#ifndef TPM_TRIG_TRIG1_SHIFT
#define TPM_TRIG_TRIG1_SHIFT                     ((uint32)(1U))
#endif

#define TPM_TRIG_TRIG0_MASK_U32                  ((uint32)(BIT0))

/**
@{
* @brief TPMx_POL - Channels Polarity - bitfield mask and shift defines.
*/

#define TPM_POL_POL5_MASK_U32               ((uint32)(BIT5))
#ifndef TPM_POL_POL5_SHIFT
#define TPM_POL_POL5_SHIFT                  ((uint32)(5U))
#endif

#define TPM_POL_POL4_MASK_U32               ((uint32)(BIT4))
#ifndef TPM_POL_POL4_SHIFT
#define TPM_POL_POL4_SHIFT                  ((uint32)(4U))
#endif

#define TPM_POL_POL3_MASK_U32               ((uint32)(BIT3))
#ifndef TPM_POL_POL3_SHIFT
#define TPM_POL_POL3_SHIFT                  ((uint32)(3U))
#endif

#define TPM_POL_POL2_MASK_U32               ((uint32)(BIT2))
#ifndef TPM_POL_POL2_SHIFT
#define TPM_POL_POL2_SHIFT                  ((uint32)(2U))
#endif

#define TPM_POL_POL1_MASK_U32               ((uint32)(BIT1))
#ifndef TPM_POL_POL1_SHIFT
#define TPM_POL_POL1_SHIFT                  ((uint32)(1U))
#endif

#define TPM_POL_POL0_MASK_U32               ((uint32)(BIT0))

/**
@{
* @brief TPMx_FILTER - Input Capture Filter Control - bitfield mask and shift defines.
*/

#define TPM_FILTER_CH5FVAL_MASK_U32                 ((uint32)(BIT23|BIT22|BIT21|BIT20))
#ifndef TPM_FILTER_CH5FVAL_SHIFT
#define TPM_FILTER_CH5FVAL_SHIFT                    ((uint32)(20U))
#endif

#define TPM_FILTER_CH4FVAL_MASK_U32                 ((uint32)(BIT19|BIT18|BIT17|BIT16))
#ifndef TPM_FILTER_CH4FVAL_SHIFT
#define TPM_FILTER_CH4FVAL_SHIFT                    ((uint32)(16U))
#endif

#define TPM_FILTER_CH3FVAL_MASK_U32                 ((uint32)(BIT15|BIT14|BIT13|BIT12))
#ifndef TPM_FILTER_CH3FVAL_SHIFT
#define TPM_FILTER_CH3FVAL_SHIFT                    ((uint32)(12U))
#endif

#define TPM_FILTER_CH2FVAL_MASK_U32                 ((uint32)(BIT11|BIT10|BIT9|BIT8))
#ifndef TPM_FILTER_CH2FVAL_SHIFT
#define TPM_FILTER_CH2FVAL_SHIFT                    ((uint32)(8U))
#endif

#define TPM_FILTER_CH1FVAL_MASK_U32                 ((uint32)(BIT7|BIT6|BIT5|BIT4))
#ifndef TPM_FILTER_CH1FVAL_SHIFT
#define TPM_FILTER_CH1FVAL_SHIFT                    ((uint32)(4U))
#endif

#define TPM_FILTER_CH0FVAL_MASK_U32                 ((uint32)(BIT3|BIT2|BIT1|BIT0))
#ifndef TPM_FILTER_CH0FVAL_SHIFT
#define TPM_FILTER_CH0FVAL_SHIFT                    ((uint32)(0U))
#endif


#define TPM_FILTER_CHxFVAL_SHIFT(u8ChannelIdx)      ((uint32)((u8ChannelIdx) << 2UL))
#define TPM_FILTER_CHxFVAL_MASK_U32(u8ChannelIdx)   (TPM_FILTER_CH0FVAL_MASK_U32 << \
                                                    TPM_FILTER_CHxFVAL_SHIFT(u8ChannelIdx))
/**
@{
* @brief TPMx_QDCTRL - Quadrature Decoder Control And Status - bitfield mask and shift defines.
*/

#define TPM_QDCTRL_QUADMODE_MASK_U32         ((uint32)(BIT3))
#ifndef TPM_QDCTRL_QUADMODE_SHIFT
#define TPM_QDCTRL_QUADMODE_SHIFT            ((uint32)(3U))
#endif

#define TPM_QDCTRL_QUADIR_MASK_U32           ((uint32)(BIT2))
#ifndef TPM_QDCTRL_QUADIR_SHIFT
#define TPM_QDCTRL_QUADIR_SHIFT              ((uint32)(2U))
#endif

#define TPM_QDCTRL_TOFDIR_MASK_U32           ((uint32)(BIT1))
#ifndef TPM_QDCTRL_TOFDIR_SHIFT
#define TPM_QDCTRL_TOFDIR_SHIFT              ((uint32)(1U))
#endif

#define TPM_QDCTRL_QUADEN_MASK_U32           ((uint32)(BIT0))

/**
@{
* @brief TPMx_CONF - Configuration - bitfield mask and shift defines.
*/

#define TPM_CONF_TRGSEL_MASK_U32            ((uint32)(BIT27|BIT26|BIT25|BIT24))
#ifndef TPM_CONF_TRGSEL_SHIFT
#define TPM_CONF_TRGSEL_SHIFT               ((uint32)(24U))
#endif

#define TPM_CONF_TRGSRC_MASK_U32            ((uint32)(BIT23))
#ifndef TPM_CONF_TRGSRC_SHIFT
#define TPM_CONF_TRGSRC_SHIFT               ((uint32)(23U))
#endif

#define TPM_CONF_TRGPOL_MASK_U32            ((uint32)(BIT22))
#ifndef TPM_CONF_TRGPOL_SHIFT
#define TPM_CONF_TRGPOL_SHIFT               ((uint32)(22U))
#endif

#define TPM_CONF_CPOT_MASK_U32              ((uint32)(BIT19))
#ifndef TPM_CONF_CPOT_SHIFT
#define TPM_CONF_CPOT_SHIFT                 ((uint32)(19U))
#endif

#define TPM_CONF_CROT_MASK_U32              ((uint32)(BIT18))
#ifndef TPM_CONF_CROT_SHIFT
#define TPM_CONF_CROT_SHIFT                 ((uint32)(18U))
#endif

#define TPM_CONF_CSOO_MASK_U32              ((uint32)(BIT17))
#ifndef TPM_CONF_CSOO_SHIFT
#define TPM_CONF_CSOO_SHIFT                 ((uint32)(17U))
#endif

#define TPM_CONF_CSOT_MASK_U32              ((uint32)(BIT16))
#ifndef TPM_CONF_CSOT_SHIFT
#define TPM_CONF_CSOT_SHIFT                 ((uint32)(16U))
#endif

#define TPM_CONF_GTBEEN_MASK_U32            ((uint32)(BIT9))
#ifndef TPM_CONF_GTBEEN_SHIFT
#define TPM_CONF_GTBEEN_SHIFT               ((uint32)(9U))
#endif

#define TPM_CONF_GTBSYNC_MASK_U32           ((uint32)(BIT8))
#ifndef TPM_CONF_GTBSYNC_SHIFT
#define TPM_CONF_GTBSYNC_SHIFT              ((uint32)(8U))
#endif

#define TPM_CONF_DBGMODE_MASK_U32           ((uint32)(BIT7|BIT6))
#ifndef TPM_CONF_DBGMODE_SHIFT
#define TPM_CONF_DBGMODE_SHIFT              ((uint32)(6U))
#endif

#define TPM_CONF_DOZEEN_MASK_U32            ((uint32)(BIT5))
#ifndef TPM_CONF_DOZEEN_SHIFT
#define TPM_CONF_DOZEEN_SHIFT               ((uint32)(5U))
#endif

/** Bitfield defines. */
/**
* @{
* @brief TPMx_GLOBAL - bitfield defines.
*/
#define TPM_GLOBAL_RST_NO_RESET_U32         ((uint32)(0U))
#define TPM_GLOBAL_RST_RESET_U32            ((uint32)(1U) << TPM_GLOBAL_RST_SHIFT)
/**
* @{
* @brief TPMx_CnSC - bitfield defines.
*/

#define TPM_CSC_CHF_NO_EVENT_U32         ((uint32)(0U))
#define TPM_CSC_CHF_EVENT_OCCURED_U32    ((uint32)(1U) << TPM_CSC_CHF_SHIFT)
#define TPM_CSC_CHIE_DISABLE_U32         ((uint32)(0U))
#define TPM_CSC_CHIE_ENABLE_U32          ((uint32)(1U) << TPM_CSC_CHIE_SHIFT )

#define TPM_CSC_MSX_PWMFORM_U32          ((uint32)(1U) << TPM_CSC_MSB_SHIFT )

#define TPM_CSC_ELSX_PWMFORM_U32         ((uint32)(1U) << TPM_CSC_ELSB_SHIFT )


#define TPM_CSC_DMA_DISABLE_U32          ((uint32)(0U))
#define TPM_CSC_DMA_ENABLE_U32           ((uint32)(1U))

/**
* @{
* @brief TPMx_SC - bitfield defines.
*/

#define TPM_SC_TOF_NO_OVF_U32                ((uint32)(0U))
#define TPM_SC_TOF_OVF_U32                   ((uint32)(1U) << TPM_SC_TOF_SHIFT)
#define TPM_SC_TOIE_DISABLE_U32              ((uint32)(0U))
#define TPM_SC_TOIE_ENABLE_U32               ((uint32)(1U) << TPM_SC_TOIE_SHIFT)
#define TPM_SC_CPWMS_UP_COUNTING_U32         ((uint32)(0U) << TPM_SC_CPWMS_SHIFT)
#define TPM_SC_CPWMS_UP_DOWN_COUNTING_U32    ((uint32)(1U) << TPM_SC_CPWMS_SHIFT)
#define TPM_SC_DMA_DISABLE_U32               ((uint32)(0U) << TPM_SC_DMA_SHIFT)
#define TPM_SC_DMA_ENABLE_U32                ((uint32)(1U) << TPM_SC_DMA_SHIFT)

#define TPM_SC_CMOD_DISABLE_COUNTER_U32                 ((uint32)(0U) << TPM_SC_CMOD_SHIFT)
#define TPM_SC_CMOD_MODULE_CLK_U32                       ((uint32)(1U) << TPM_SC_CMOD_SHIFT)
#define TPM_SC_CMOD_EXTERNAL_CLK_U32                     ((uint32)(2U) << TPM_SC_CMOD_SHIFT)
#define TPM_SC_CMOD_INC_RISING_EDGE_EXT_TRIGGER_U32     ((uint32)(3U) << TPM_SC_CMOD_SHIFT)
#define TPM_SC_PS_DIV1_U32                   ((uint32)(0U))
#define TPM_SC_PS_DIV2_U32                   ((uint32)(1U))
#define TPM_SC_PS_DIV4_U32                   ((uint32)(2U))
#define TPM_SC_PS_DIV8_U32                   ((uint32)(3U))
#define TPM_SC_PS_DIV16_U32                  ((uint32)(4U))
#define TPM_SC_PS_DIV32_U32                  ((uint32)(5U))
#define TPM_SC_PS_DIV64_U32                  ((uint32)(6U))
#define TPM_SC_PS_DIV128_U32                 ((uint32)(7U))

/**
* @{
* @brief TPMx_STATUS - bitfield defines.
*/
#define TPM_STATUS_CH0F_NO_EVENT_U32          ((uint32)(0U))
#define TPM_STATUS_CH0F_EVENT_OCCURED_U32     ((uint32)(1U) << TPM_STATUS_CH0F_SHIFT)
#define TPM_STATUS_CH1F_NO_EVENT_U32          ((uint32)(0U))
#define TPM_STATUS_CH1F_EVENT_OCCURED_U32     ((uint32)(1U) << TPM_STATUS_CH1F_SHIFT)
#define TPM_STATUS_CH2F_NO_EVENT_U32          ((uint32)(0U))
#define TPM_STATUS_CH2F_EVENT_OCCURED_U32     ((uint32)(1U) << TPM_STATUS_CH2F_SHIFT)
#define TPM_STATUS_CH3F_NO_EVENT_U32          ((uint32)(0U))
#define TPM_STATUS_CH3F_EVENT_OCCURED_U32     ((uint32)(1U) << TPM_STATUS_CH3F_SHIFT)
#define TPM_STATUS_CH4F_NO_EVENT_U32          ((uint32)(0U))
#define TPM_STATUS_CH4F_EVENT_OCCURED_U32     ((uint32)(1U) << TPM_STATUS_CH4F_SHIFT)
#define TPM_STATUS_CH5F_NO_EVENT_U32          ((uint32)(0U))
#define TPM_STATUS_CH5F_EVENT_OCCURED_U32     ((uint32)(1U) << TPM_STATUS_CH5F_SHIFT)
#define TPM_STATUS_TOF_NO_OVF_U32             ((uint32)(0U))
#define TPM_STATUS_TOF_OVF_U32                ((uint32)(1U) << TPM_STATUS_TOF_SHIFT)

/**
* @{
* @brief TPMx_COMBINE - bitfield defines.
*/
#define TPM_COMBINE_COMBINE0_DISABLE_U32     ((uint32)(0U))
#define TPM_COMBINE_COMBINE0_ENABLE_U32      ((uint32)(1U))
#define TPM_COMBINE_COMSWAP0_DISABLE_U32     ((uint32)(0U))
#define TPM_COMBINE_COMSWAP0_ENABLE_U32      ((uint32)(1U) << TPM_COMBINE_COMSWAP0_SHIFT)

#define TPM_COMBINE_COMBINE1_DISABLE_U32     ((uint32)(0U))
#define TPM_COMBINE_COMBINE1_ENABLE_U32      ((uint32)(1U) << TPM_COMBINE_COMBINE1_SHIFT)
#define TPM_COMBINE_COMSWAP1_DISABLE_U32     ((uint32)(0U))
#define TPM_COMBINE_COMSWAP1_ENABLE_U32      ((uint32)(1U) << TPM_COMBINE_COMSWAP1_SHIFT)

#define TPM_COMBINE_COMBINE2_DISABLE_U32     ((uint32)(0U))
#define TPM_COMBINE_COMBINE2_ENABLE_U32      ((uint32)(1U) << TPM_COMBINE_COMBINE2_SHIFT)
#define TPM_COMBINE_COMSWAP2_DISABLE_U32     ((uint32)(0U))
#define TPM_COMBINE_COMSWAP2_ENABLE_U32      ((uint32)(1U) << TPM_COMBINE_COMSWAP2_SHIFT)

#define TPM_COMBINE_COMBINEx_SHIFT(u8ChannelIdx)        (uint32)(((u8ChannelIdx / 2U) * 8U) + 0U)
#define TPM_COMBINE_COMBINEx_MASK_U32(u8ChannelIdx)     ((uint32)(BIT0 << TPM_COMBINE_COMBINEx_SHIFT(u8ChannelIdx)))
#define TPM_COMBINE_COMSWAPx_SHIFT(u8ChannelIdx)        (uint32)(((u8ChannelIdx / 2U) * 8U) + 0U)
#define TPM_COMBINE_COMSWAPx_MASK_U32(u8ChannelIdx)     ((uint32)(BIT1 << TPM_COMBINE_COMBINEx_SHIFT(u8ChannelIdx)))


/**
* @{
* @brief TPMx_TRIG - bitfield defines.
*/

#define TPM_TRIG_TRIG0_NO_TRIGGER_U32       ((uint32)(0U))
#define TPM_TRIG_TRIG0_TRIGGER_U32          ((uint32)(1U))

#define TPM_TRIG_TRIG1_NO_TRIGGER_U32       ((uint32)(0U))
#define TPM_TRIG_TRIG1_TRIGGER_U32          ((uint32)(1U) << TPM_TRIG_TRIG1_SHIFT)

#define TPM_TRIG_TRIG2_NO_TRIGGER_U32       ((uint32)(0U))
#define TPM_TRIG_TRIG2_TRIGGER_U32          ((uint32)(1U) << TPM_TRIG_TRIG2_SHIFT)

#define TPM_TRIG_TRIG3_NO_TRIGGER_U32       ((uint32)(0U))
#define TPM_TRIG_TRIG3_TRIGGER_U32          ((uint32)(1U) << TPM_TRIG_TRIG3_SHIFT)

#define TPM_TRIG_TRIG4_NO_TRIGGER_U32       ((uint32)(0U))
#define TPM_TRIG_TRIG4_TRIGGER_U32          ((uint32)(1U) << TPM_TRIG_TRIG4_SHIFT)

#define TPM_TRIG_TRIG5_NO_TRIGGER_U32       ((uint32)(0U))
#define TPM_TRIG_TRIG5_TRIGGER_U32          ((uint32)(1U) << TPM_TRIG_TRIG5_SHIFT)

/**
* @{
* @brief TPMx_POL - bitfield defines.
*/
#define TPM_POL_POL5_LOW_U32            ((uint32)(1U) << TPM_POL_POL5_SHIFT)
#define TPM_POL_POL5_HIGH_U32           ((uint32)(0U))
#define TPM_POL_POL4_LOW_U32            ((uint32)(1U) << TPM_POL_POL4_SHIFT)
#define TPM_POL_POL4_HIGH_U32           ((uint32)(0U))
#define TPM_POL_POL3_LOW_U32            ((uint32)(1U) << TPM_POL_POL3_SHIFT)
#define TPM_POL_POL3_HIGH_U32           ((uint32)(0U))
#define TPM_POL_POL2_LOW_U32            ((uint32)(1U) << TPM_POL_POL2_SHIFT)
#define TPM_POL_POL2_HIGH_U32           ((uint32)(0U))
#define TPM_POL_POL1_LOW_U32            ((uint32)(1U) << TPM_POL_POL1_SHIFT)
#define TPM_POL_POL1_HIGH_U32           ((uint32)(0U))
#define TPM_POL_POL0_LOW_U32            ((uint32)(1U))
#define TPM_POL_POL0_HIGH_U32           ((uint32)(0U))

/**
* @{
* @brief TPMx_QDCTRL - bitfield defines.
*/

#define TPM_QDCTRL_QUADIR_DECREMENT_U32     ((uint32)(0U))
#define TPM_QDCTRL_QUADIR_INCREMENT_U32     ((uint32)(1U) << TPM_QDCTRL_QUADIR_SHIFT)

#define TPM_QDCTRL_TOFDIR_BOTTOM_U32        ((uint32)(0U))
#define TPM_QDCTRL_TOFDIR_TOP_U32           ((uint32)(1U) << TPM_QDCTRL_TOFDIR_SHIFT)

#define TPM_QDCTRL_QUADMODE_PHASE_U32                   ((uint32)(0U))
#define TPM_QDCTRL_QUADMODE_COUNT_AND_DIRECTION_U32     ((uint32)(1U) << TPM_QDCTRL_QUADMODE_SHIFT)

#define TPM_QDCTRL_QUADEN_DISABLE_U32       ((uint32)(0U))
#define TPM_QDCTRL_QUADEN_ENABLE_U32        ((uint32)(1U))

/**
* @{
* @brief TPMx_CONF - bitfield defines.
*/

#define TPM_CONF_DOZEEN_PAUSE_DOZE_U32            (((uint32)(1U)) << TPM_CONF_DOZEEN_SHIFT)
#define TPM_CONF_DOZEEN_CONTINUES_DOZE_U32        ((uint32)(0U))

#define TPM_CONF_DBGMODE_CONTINUES_DEBUG_U32       (((uint32)(3U)) << TPM_CONF_DBGMODE_SHIFT)
#define TPM_CONF_DBGMODE_PAUSE_DEBUG_U32           ((uint32)(0U))

#define TPM_CONF_GTBSYNC_SYNCHRONIZATION_ENABLE_U32       (((uint32)(1U)) << TPM_CONF_GTBSYNC_SHIFT)
#define TPM_CONF_GTBSYNC_SYNCHRONIZATION_DISABLE_U32       ((uint32)(0U))

#define TPM_CONF_GTBEEN_USE_EXTERNALLY_U32       (((uint32)(1U)) << TPM_CONF_GTBEEN_SHIFT)
#define TPM_CONF_GTBEEN_USE_INTERNALLY_U32       ((uint32)(0U))

#define TPM_CONF_CSOT_INC_RISING_EDGE_U32       (((uint32)(1U)) << TPM_CONF_CSOT_SHIFT)
#define TPM_CONF_CSOT_INC_IMMEDIATELY_U32       ((uint32)(0U))

#define TPM_CONF_CSOO_STOP_AFTER_OVF_U32            (((uint32)(1U)) << TPM_CONF_CSOO_SHIFT)
#define TPM_CONF_CSOO_CONTINUSE_AFTER_OVF_U32       ((uint32)(0U))

#define TPM_CONF_CROT_RELOAD_U32            (((uint32)(1U)) << TPM_CONF_CROT_SHIFT)
#define TPM_CONF_CROT_NO_RELOAD_U32         ((uint32)(0U))

#define TPM_CONF_CPOT_ENABLE_PAUSE_U32            (((uint32)(1U)) << TPM_CONF_CPOT_SHIFT)
#define TPM_CONF_CPOT_DISABLE_PAUSE_U32         ((uint32)(0U))

#define TPM_CONF_TRGPOL_ACTIVE_LOW_U32              (((uint32)(1U)) << TPM_CONF_TRGPOL_SHIFT)
#define TPM_CONF_TRGPOL_ACTIVE_HIGH_U32             ((uint32)(0U))

#define TPM_CONF_TRGSRC_TRGSEL_INTERNAL_U32         (((uint32)(1U)) << TPM_CONF_TRGSRC_SHIFT)
#define TPM_CONF_TRGSRC_TRGSEL_EXTERNAL_U32         ((uint32)(0U))

#define TPM_CONF_BDGMODE_MASK_U32           ((uint32)(BIT7|BIT6))
#ifndef TPM_CONF_BDGMODE_SHIFT
#define TPM_CONF_BDGMODE_SHIFT              ((uint32)(6U))
#endif


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



#endif /* REG_ESYS_TPM_H */

/** @} */
