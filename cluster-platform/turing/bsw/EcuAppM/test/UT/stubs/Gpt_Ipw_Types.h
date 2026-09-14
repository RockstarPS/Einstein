/**
*   @file    Gpt_Ipw_Types.h
*   @version 4.0.0
*
*   @brief   AUTOSAR Gpt - Gpt driver header file.
*   @details GPT driver header file, containing variables, functions prototypes, data types and/or
*            defines and macros that:
*            - are Autosar independent.
*            - are platform dependent.
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Ftm
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : IMX8_MCAL_4_0_0_RTM_ASR_REL_4_2_REV_0002_20201231
*
*   Copyright 2006-2016 Freescale Semiconductor, Inc. 
*   Copyright 2017 - 2020 NXP
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

#ifndef GPT_IPW_TYPES_H
#define GPT_IPW_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
 #include "Gpt_Ftm_Types.h"
 #include "Gpt_Gpt_Types.h"
 #include "Gpt_Tpm_Types.h"
 #include "Gpt_LPit_Types.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define GPT_IPW_TYPES_VENDOR_ID                      43
#define GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION       2
#define GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION    2
#define GPT_IPW_TYPES_SW_MAJOR_VERSION               4
#define GPT_IPW_TYPES_SW_MINOR_VERSION               0
#define GPT_IPW_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


// #if (GPT_IPW_TYPES_VENDOR_ID != GPT_FTM_TYPES_VENDOR_ID)
//     #error "Gpt_Ipw_Types.h and Gpt_Ftm_Types.h have different vendor ids"
// #endif
// #if ((GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_FTM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
//      (GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION != GPT_FTM_TYPES_AR_RELEASE_MINOR_VERSION) || \
//      (GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION != GPT_FTM_TYPES_AR_RELEASE_REVISION_VERSION))
//     #error "AutoSar Version Numbers of Gpt_Ipw_Types.h and Gpt_Ftm_Types.h are different"
// #endif
// #if ((GPT_IPW_TYPES_SW_MAJOR_VERSION != GPT_FTM_TYPES_SW_MAJOR_VERSION) || \
//      (GPT_IPW_TYPES_SW_MINOR_VERSION != GPT_FTM_TYPES_SW_MINOR_VERSION) || \
//      (GPT_IPW_TYPES_SW_PATCH_VERSION != GPT_FTM_TYPES_SW_PATCH_VERSION))
//     #error "Software Version Numbers of Gpt_Ipw_Types.h and Gpt_Ftm_Types.h are different"
// #endif

//     /* Check if Gpt_Gpt_Types.h and Gpt_Ipw_Types.h file are of the same vendor */
// #if (GPT_IPW_TYPES_VENDOR_ID != GPT_GPT_TYPES_VENDOR_ID)
//     #error "Gpt_Ipw_Types.h and Gpt_Cfg.h have different vendor ids"
// #endif
//     /* Check if Gpt_Gpt_Types.h and Gpt_Ipw_Types.h file are of the same Autosar version */

// #if ((GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_GPT_TYPES_AR_RELEASE_MAJOR_VERSION) || \
//     (GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION != GPT_GPT_TYPES_AR_RELEASE_MINOR_VERSION) || \
//     (GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION != GPT_GPT_TYPES_AR_RELEASE_REVISION_VERSION))
// #error "AutoSar Version Numbers of Gpt_Cfg.h and Gpt_Ipw_Types.h are different"
// #endif

//     /* Check if Gpt_Ipw_Types.h and Gpt_Gpt_Types header file are of the same software version */
// #if ((GPT_IPW_TYPES_SW_MAJOR_VERSION != GPT_GPT_TYPES_SW_MAJOR_VERSION) || \
//      (GPT_IPW_TYPES_SW_MINOR_VERSION != GPT_GPT_TYPES_SW_MINOR_VERSION) || \
//      (GPT_IPW_TYPES_SW_PATCH_VERSION != GPT_GPT_TYPES_SW_PATCH_VERSION))
//     #error "Software Version Numbers of Gpt_Gpt_Types.h and Gpt_Ipw_Types.h are different"
// #endif

//     /* Check if Gpt_Tpm_Types.h and Gpt_Ipw_Types.h file are of the same vendor */
// #if (GPT_IPW_TYPES_VENDOR_ID != GPT_TPM_TYPES_VENDOR_ID)
//     #error "Gpt_Ipw_Types.h and Gpt_Tpm_Types.h have different vendor ids"
// #endif
//     /* Check if Gpt_Tpm_Types.h and Gpt_Ipw_Types.h file are of the same Autosar version */

// #if ((GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_TPM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
//     (GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION != GPT_TPM_TYPES_AR_RELEASE_MINOR_VERSION) || \
//     (GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION != GPT_TPM_TYPES_AR_RELEASE_REVISION_VERSION))
// #error "AutoSar Version Numbers of Gpt_Tpm_Types.h and Gpt_Ipw_Types.h are different"
// #endif

//     /* Check if Gpt_Ipw_Types.h and Gpt_Tpm_Types header file are of the same software version */
// #if ((GPT_IPW_TYPES_SW_MAJOR_VERSION != GPT_TPM_TYPES_SW_MAJOR_VERSION) || \
//      (GPT_IPW_TYPES_SW_MINOR_VERSION != GPT_TPM_TYPES_SW_MINOR_VERSION) || \
//      (GPT_IPW_TYPES_SW_PATCH_VERSION != GPT_TPM_TYPES_SW_PATCH_VERSION))
//     #error "Software Version Numbers of Gpt_Tpm_Types.h and Gpt_Ipw_Types.h are different"
// #endif

//     /* Check if Gpt_LPit_Types.h and Gpt_Ipw_Types.h file are of the same vendor */
// #if (GPT_IPW_TYPES_VENDOR_ID != GPT_LPIT_TYPES_VENDOR_ID)
//     #error "Gpt_Ipw_Types.h and Gpt_LPit_Types.h have different vendor ids"
// #endif
//     /* Check if Gpt_LPit_Types.h and Gpt_Ipw_Types.h file are of the same Autosar version */
//     #if ((GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_LPIT_TYPES_AR_RELEASE_MAJOR_VERSION) || \
//         (GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION != GPT_LPIT_TYPES_AR_RELEASE_MINOR_VERSION) || \
//         (GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION != GPT_LPIT_TYPES_AR_RELEASE_REVISION_VERSION))
//     #error "AutoSar Version Numbers of Gpt_LPit_Types.h and Gpt_Ipw_Types.h are different"
//     #endif
//     /* Check if Gpt_Ipw_Types.h and Gpt_LPit_Types header file are of the same software version */
// #if ((GPT_IPW_TYPES_SW_MAJOR_VERSION != GPT_LPIT_TYPES_SW_MAJOR_VERSION) || \
//      (GPT_IPW_TYPES_SW_MINOR_VERSION != GPT_LPIT_TYPES_SW_MINOR_VERSION) || \
//      (GPT_IPW_TYPES_SW_PATCH_VERSION != GPT_LPIT_TYPES_SW_PATCH_VERSION))
//     #error "Software Version Numbers of Gpt_LPit_Types.h and Gpt_Ipw_Types.h are different"
// #endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Symbolic name for FTM channel
*/
#define GPT_FTM_CHANNEL                 ((Gpt_ChannelIpType)0U)

/**
* @brief Symbolic name for GPT channel
*/
#define GPT_GPT_CHANNEL                 ((Gpt_ChannelIpType)1U)

/**
* @brief Symbolic name for GPT channel
*/
#define GPT_TPM_CHANNEL                 ((Gpt_ChannelIpType)2U)

/**
* @brief Symbolic name for GPT channel
*/
#define GPT_LPIT_CHANNEL                 ((Gpt_ChannelIpType)3U)

/**
* @{
* @brief          FTM channels defines
* @details        There are defines used for the FTM channel encoding -> channel_id
*
* @note           an FTM module generally has only 6 channels so by using this method
*                 there will be gaps of 2 channels between different FTM modules because
*                 [              5 bit  | 3 bit               ]
*                 [ module id: 31 ... 0 | channel id: 7 ... 0 ]
*/

/** @} */


/** FTM module and channel decoding */
#define GPT_FTM_0_CH_0    ((uint8)0x00)
#define GPT_FTM_0_CH_1    ((uint8)0x01)
#define GPT_FTM_0_CH_2    ((uint8)0x02)
#define GPT_FTM_0_CH_3    ((uint8)0x03)
#define GPT_FTM_0_CH_4    ((uint8)0x04)
#define GPT_FTM_0_CH_5    ((uint8)0x05)
#define GPT_FTM_0_CH_6    ((uint8)0x06)
#define GPT_FTM_0_CH_7    ((uint8)0x07)

#define GPT_FTM_1_CH_0    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x00))
#define GPT_FTM_1_CH_1    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x01))
#define GPT_FTM_1_CH_2    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x02))
#define GPT_FTM_1_CH_3    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x03))
#define GPT_FTM_1_CH_4    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x04))
#define GPT_FTM_1_CH_5    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x05))
#define GPT_FTM_1_CH_6    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x06))
#define GPT_FTM_1_CH_7    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x07))

/** GPT module and channel decoding */
#define GPT_GPT_0_CH_0    (0U)
#define GPT_GPT_0_CH_1    (1U)
#define GPT_GPT_0_CH_2    (2U)

#define GPT_GPT_1_CH_0    ((uint8)((uint8)(1U * GPT_GPT_CH_PER_MODULE) + (uint8)0x00))
#define GPT_GPT_1_CH_1    ((uint8)((uint8)(1U * GPT_GPT_CH_PER_MODULE) + (uint8)0x01))
#define GPT_GPT_1_CH_2    ((uint8)((uint8)(1U * GPT_GPT_CH_PER_MODULE) + (uint8)0x02))

#define GPT_GPT_2_CH_0    ((uint8)((uint8)(2U * GPT_GPT_CH_PER_MODULE) + (uint8)0x00))
#define GPT_GPT_2_CH_1    ((uint8)((uint8)(2U * GPT_GPT_CH_PER_MODULE) + (uint8)0x01))
#define GPT_GPT_2_CH_2    ((uint8)((uint8)(2U * GPT_GPT_CH_PER_MODULE) + (uint8)0x02))

#define GPT_GPT_3_CH_0    ((uint8)((uint8)(3U * GPT_GPT_CH_PER_MODULE) + (uint8)0x00))
#define GPT_GPT_3_CH_1    ((uint8)((uint8)(3U * GPT_GPT_CH_PER_MODULE) + (uint8)0x01))
#define GPT_GPT_3_CH_2    ((uint8)((uint8)(3U * GPT_GPT_CH_PER_MODULE) + (uint8)0x02))

#define GPT_GPT_4_CH_0    ((uint8)((uint8)(4U * GPT_GPT_CH_PER_MODULE) + (uint8)0x00))
#define GPT_GPT_4_CH_1    ((uint8)((uint8)(4U * GPT_GPT_CH_PER_MODULE) + (uint8)0x01))
#define GPT_GPT_4_CH_2    ((uint8)((uint8)(4U * GPT_GPT_CH_PER_MODULE) + (uint8)0x02))

#define GPT_GPT_5_CH_0    ((uint8)((uint8)(5U * GPT_GPT_CH_PER_MODULE) + (uint8)0x00))
#define GPT_GPT_5_CH_1    ((uint8)((uint8)(5U * GPT_GPT_CH_PER_MODULE) + (uint8)0x01))
#define GPT_GPT_5_CH_2    ((uint8)((uint8)(5U * GPT_GPT_CH_PER_MODULE) + (uint8)0x02))

#define GPT_GPT_6_CH_0    ((uint8)((uint8)(6U * GPT_GPT_CH_PER_MODULE) + (uint8)0x00))
#define GPT_GPT_6_CH_1    ((uint8)((uint8)(6U * GPT_GPT_CH_PER_MODULE) + (uint8)0x01))
#define GPT_GPT_6_CH_2    ((uint8)((uint8)(6U * GPT_GPT_CH_PER_MODULE) + (uint8)0x02))

#define GPT_GPT_7_CH_0    ((uint8)((uint8)(7U * GPT_GPT_CH_PER_MODULE) + (uint8)0x00))
#define GPT_GPT_7_CH_1    ((uint8)((uint8)(7U * GPT_GPT_CH_PER_MODULE) + (uint8)0x01))
#define GPT_GPT_7_CH_2    ((uint8)((uint8)(7U * GPT_GPT_CH_PER_MODULE) + (uint8)0x02))

#define GPT_GPT_8_CH_0    ((uint8)((uint8)(8U * GPT_GPT_CH_PER_MODULE) + (uint8)0x00))
#define GPT_GPT_8_CH_1    ((uint8)((uint8)(8U * GPT_GPT_CH_PER_MODULE) + (uint8)0x01))
#define GPT_GPT_8_CH_2    ((uint8)((uint8)(8U * GPT_GPT_CH_PER_MODULE) + (uint8)0x02))

#define GPT_GPT_9_CH_0    ((uint8)((uint8)(9U * GPT_GPT_CH_PER_MODULE) + (uint8)0x00))
#define GPT_GPT_9_CH_1    ((uint8)((uint8)(9U * GPT_GPT_CH_PER_MODULE) + (uint8)0x01))
#define GPT_GPT_9_CH_2    ((uint8)((uint8)(9U * GPT_GPT_CH_PER_MODULE) + (uint8)0x02))

#define GPT_GPT_10_CH_0    ((uint8)((uint8)(10U * GPT_GPT_CH_PER_MODULE) + (uint8)0x00))
#define GPT_GPT_10_CH_1    ((uint8)((uint8)(10U * GPT_GPT_CH_PER_MODULE) + (uint8)0x01))
#define GPT_GPT_10_CH_2    ((uint8)((uint8)(10U * GPT_GPT_CH_PER_MODULE) + (uint8)0x02))


/** TPM module and channel decoding */
#define GPT_TPM_0_CH_0    ((uint8)0x00)
#define GPT_TPM_0_CH_1    ((uint8)0x01)
#define GPT_TPM_0_CH_2    ((uint8)0x02)
#define GPT_TPM_0_CH_3    ((uint8)0x03)
#define GPT_TPM_0_CH_4    ((uint8)0x04)
#define GPT_TPM_0_CH_5    ((uint8)0x05)
#define GPT_TPM_0_CH_6    ((uint8)0x06)
#define GPT_TPM_0_CH_7    ((uint8)0x07)

#define GPT_TPM_1_CH_0    ((uint8)((uint8)(1U<<TPM_MOD_SHIFT) + (uint8)0x00))
#define GPT_TPM_1_CH_1    ((uint8)((uint8)(1U<<TPM_MOD_SHIFT) + (uint8)0x01))
#define GPT_TPM_1_CH_2    ((uint8)((uint8)(1U<<TPM_MOD_SHIFT) + (uint8)0x02))
#define GPT_TPM_1_CH_3    ((uint8)((uint8)(1U<<TPM_MOD_SHIFT) + (uint8)0x03))
#define GPT_TPM_1_CH_4    ((uint8)((uint8)(1U<<TPM_MOD_SHIFT) + (uint8)0x04))
#define GPT_TPM_1_CH_5    ((uint8)((uint8)(1U<<TPM_MOD_SHIFT) + (uint8)0x05))
#define GPT_TPM_1_CH_6    ((uint8)((uint8)(1U<<TPM_MOD_SHIFT) + (uint8)0x06))
#define GPT_TPM_1_CH_7    ((uint8)((uint8)(1U<<TPM_MOD_SHIFT) + (uint8)0x07))

/** LPIT module and channel decoding */
#define GPT_LPIT_0_CH_0   ((uint8)0x00)
#define GPT_LPIT_0_CH_1   ((uint8)0x01)
#define GPT_LPIT_0_CH_2   ((uint8)0x02)
#define GPT_LPIT_0_CH_3   ((uint8)0x03)

#define GPT_LPIT_1_CH_0   ((uint8)((uint8)(1U<<LPIT_MOD_SHIFT) + (uint8)0x00))
#define GPT_LPIT_1_CH_1   ((uint8)((uint8)(1U<<LPIT_MOD_SHIFT) + (uint8)0x01))
#define GPT_LPIT_1_CH_2   ((uint8)((uint8)(1U<<LPIT_MOD_SHIFT) + (uint8)0x02))
#define GPT_LPIT_1_CH_3   ((uint8)((uint8)(1U<<LPIT_MOD_SHIFT) + (uint8)0x03))

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief Gpt prescaler data type
*/
typedef uint8 Gpt_PrescalerType;

/**
* @brief Gpt prescaler32 data type
*/
typedef uint8 Gpt_PrescalerType32;

/**
* @brief Gpt clock source data type
*/
typedef uint8 Gpt_ClockSourceType;

/**
* @brief Gpt channel output compare operating mode data type
*/
typedef uint32 Gpt_ConnectOutputType;

/**
* @brief The IP type usef to implement Gpt channel (GPT or FTM)
*/
typedef uint8 Gpt_ChannelIpType;

/**
* @brief Gpt channel high level configuration structure
*/
typedef struct
{
    /** @brief The IP type usef to implement Gpt channel (GPT or FTM) */
    CONST(Gpt_ChannelIpType, GPT_CONST) nChannelIp;
    /** @brief Index in the IP specific configuration table */
    CONST(uint8, GPT_CONST) u8IdxChannelConfig;
} Gpt_IpChannelConfigType;

/**
* @brief Low level configuration for channel specific parameters
*/
typedef struct
{
    /** @brief The IP type usef to implement Gpt channel (GPT or FTM) */
    CONST(Gpt_ChannelIpType, GPT_CONST) nChannelIp;
    CONST(uint8, GPT_CONST) Gpt_u8HwModule;                     /**<@brief GPT hw module used */
} Gpt_HwPredefChannelConfigType;

/**
* @brief Combined GPT IP configuration structure
*/
typedef struct
{
    /** @brief Pointer to Ftm configuration structure */
    CONSTP2CONST(Gpt_Ftm_IpConfigType, GPT_CONST, GPT_APPL_CONST) pFtmIpConfig;
    /** @brief Pointer to Gpt configuration structure */
    CONSTP2CONST(Gpt_Gpt_IpConfigType, GPT_CONST, GPT_APPL_CONST) pGptIpConfig;
    /** @brief Pointer to Gpt configuration structure */
    CONSTP2CONST(Gpt_Tpm_IpConfigType, GPT_CONST, GPT_APPL_CONST) pTpmIpConfig;
    /** @brief Pointer to Gpt configuration structure */
    CONSTP2CONST(Gpt_LPit_IpConfigType, GPT_CONST, GPT_APPL_CONST) pLPitIpConfig;
    /** @brief Pointers to array containing IP type and index of each Gpt channel */
    CONST(Gpt_IpChannelConfigType, GPT_CONST) (*pIpChannelsConfig)[];
} Gpt_IpConfigType;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*GPT_IPW_TYPES_H*/

/** @} */
