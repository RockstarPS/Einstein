/**
*   @file    Gpt_LPit_Types.h
*   @version 4.0.0
*
*   @brief   AUTOSAR Gpt - LPIT driver header file.
*   @details LPIT driver defines which need to be exported to external application
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

#ifndef GPT_LPIT_TYPES_H
#define GPT_LPIT_TYPES_H

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
*
* @section GPT_LPIT_TYPES_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** @violates @ref GPT_LPIT_TYPES_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "Gpt_Cfg.h"
/** @violates @ref GPT_LPIT_TYPES_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "Gpt_EnvCfg.h"
#include "LPit_Common_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_LPit_Types.h
* @{
*/
#define GPT_LPIT_TYPES_VENDOR_ID                       43
#define GPT_LPIT_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define GPT_LPIT_TYPES_AR_RELEASE_MINOR_VERSION        2
#define GPT_LPIT_TYPES_AR_RELEASE_REVISION_VERSION     2
#define GPT_LPIT_TYPES_SW_MAJOR_VERSION                4
#define GPT_LPIT_TYPES_SW_MINOR_VERSION                0
#define GPT_LPIT_TYPES_SW_PATCH_VERSION                0
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if ( GPT_LPIT_TYPES_VENDOR_ID != GPT_VENDOR_ID_CFG)
    #error "Gpt_LPit_Types.h and Gpt_Cfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_LPIT_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (GPT_LPIT_TYPES_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
     (GPT_LPIT_TYPES_AR_RELEASE_REVISION_VERSION != GPT_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Gpt_LPit_Types.h and Gpt_Cfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_LPIT_TYPES_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION_CFG) || \
     (GPT_LPIT_TYPES_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION_CFG) || \
     (GPT_LPIT_TYPES_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION_CFG) )
    #error "Software Version Numbers of Gpt_LPit_Types.h and Gpt_Cfg.h are different"
#endif

#if ( GPT_LPIT_TYPES_VENDOR_ID!= GPT_ENVCFG_VENDOR_ID)
    #error "Gpt_LPit_Types.h and Gpt_EnvCfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_LPIT_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LPIT_TYPES_AR_RELEASE_MINOR_VERSION != GPT_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LPIT_TYPES_AR_RELEASE_REVISION_VERSION != GPT_ENVCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_LPit_Types.h and Gpt_EnvCfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_LPIT_TYPES_SW_MAJOR_VERSION != GPT_ENVCFG_SW_MAJOR_VERSION) || \
     (GPT_LPIT_TYPES_SW_MINOR_VERSION != GPT_ENVCFG_SW_MINOR_VERSION) || \
     (GPT_LPIT_TYPES_SW_PATCH_VERSION != GPT_ENVCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_LPit_Types.h and Gpt_EnvCfg.h are different"
#endif

    /* Check if the header files are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((GPT_LPIT_TYPES_AR_RELEASE_MAJOR_VERSION != LPIT_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION) || \
        (GPT_LPIT_TYPES_AR_RELEASE_MINOR_VERSION != LPIT_COMMON_TYPES_AR_RELEASE_MINOR_VERSION) \
        )
    #error "AutoSar Version Numbers of Gpt_LPit_Types.h and LPit_Common_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief LPIT channel data type
*/
typedef uint8 Gpt_LPit_ChannelType;

typedef struct
{
    uint8   u8LPitChannelId;
    boolean bChainMode;
    uint32  u32ChlCtrlVal;
} Gpt_LPit_ChannelConfigType;


typedef struct
{
    /* @brief number of modules in LPIT configuration structure */
    CONST(Gpt_LPit_ChannelType, GPT_CONST) nNumModules;
    /* @brief number of channels in LPIT configuration structure */
    CONST(Gpt_LPit_ChannelType, GPT_CONST) nNumChannels;
    /* @brief Index in Gpt_aHw2LogicChannelMap where LPIT channels start */
    CONST(Gpt_LPit_ChannelType, GPT_CONST) nLPitChannelsStartIdx;
    /* @brief pointer to LPIT global configuration */
    CONST(LPit_CommonConfigType, GPT_CONST) (*GptLPitGlobalConfiguration)[];
    /* @brief Array of configured LPIT channels */
    CONST(Gpt_LPit_ChannelConfigType, GPT_CONST) (*LPitChannels)[];
} Gpt_LPit_IpConfigType;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*GPT_LPIT_TYPES_H*/

/** @} */
