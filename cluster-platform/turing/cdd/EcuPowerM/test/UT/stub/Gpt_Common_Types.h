/**
*   @file    Gpt_Common_Types.h
*   @version 4.0.0
*
*   @brief   AUTOSAR Mcl - GPT driver header file.
*   @details GPT defines.
*
*   @addtogroup GPT_MODULE
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

#ifndef GPT_COMMON_TYPES_H
#define GPT_COMMON_TYPES_H
/**
*   @file    Gpt_Common_Types.h
*/
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section GPT_COMMON_TYPES_H_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
*/
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Gpt_Common_Types.h
* @brief          Source file version information
*
*/
#define GPT_COMMON_TYPES_VENDOR_ID                       43
/** @violates @ref GPT_COMMON_TYPES_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define GPT_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION        4
/** @violates @ref GPT_COMMON_TYPES_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define GPT_COMMON_TYPES_AR_RELEASE_MINOR_VERSION        2
/** @violates @ref GPT_COMMON_TYPES_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define GPT_COMMON_TYPES_AR_RELEASE_REVISION_VERSION     2
#define GPT_COMMON_TYPES_SW_MAJOR_VERSION                4
#define GPT_COMMON_TYPES_SW_MINOR_VERSION                0
#define GPT_COMMON_TYPES_SW_PATCH_VERSION                0
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief GPT 0
*/
#define GPT_0    ((uint8)0)
/**
* @brief GPT 1
*/
#define GPT_1    ((uint8)1)
/**
* @brief GPT 2
*/
#define GPT_2    ((uint8)2)
/**
* @brief GPT 3
*/
#define GPT_3    ((uint8)3)
/**
* @brief GPT 4
*/
#define GPT_4    ((uint8)4)

/**
* @brief GPT 0
*/
#define GPT_GPT_0    ((uint8)0)
#define ICU_GPT_0    ((uint8)0)
/**
* @brief GPT 1
*/
#define GPT_GPT_1    ((uint8)1)
#define ICU_GPT_1    ((uint8)1)
/**
* @brief GPT 2
*/
#define GPT_GPT_2    ((uint8)2)
#define ICU_GPT_2    ((uint8)2)
/**
* @brief GPT 3
*/
#define GPT_GPT_3    ((uint8)3)
#define ICU_GPT_3    ((uint8)3)
/**
* @brief GPT 4
*/
#define GPT_GPT_4    ((uint8)4)
#define ICU_GPT_4    ((uint8)4)
#define GPT_GPT_5    ((uint8)5)
#define GPT_GPT_6    ((uint8)6)
#define GPT_GPT_7    ((uint8)7)
#define GPT_GPT_8    ((uint8)8)
#define GPT_GPT_9    ((uint8)9)
#define GPT_GPT_10   ((uint8)10)

/*================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct
{
    CONST(uint8, MCL_CONST)  u8ModIdx;
    CONST(uint32, MCL_CONST) u32ControlValue;
    CONST(uint32, MCL_CONST) u32Prescaler;
    CONST(uint32, MCL_CONST) u32AltPrescaler;
} Gpt_CommonConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif

/** @} */
