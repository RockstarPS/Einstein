/**
*   @file           Gpt_Ftm_Types.h
*   @version        4.0.0
*
*   @brief          AUTOSAR Gpt - Ftm data types header file.
*   @details        Ftm defines, types used by GPT driver.
*
*   @addtogroup     PWM_MODULE
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

#ifndef GPT_FTM_TYPES_H
#define GPT_FTM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*       Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*       on the significance of more than 31 characters. The used compilers use more than 31 chars
*       for identifiers
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
 #include "Ftm_Common_Types.h"

// #include "Reg_eSys_Ftm.h"

 #include "Gpt_EnvCfg.h"
 #include "Gpt_Cfg.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/

#define GPT_FTM_TYPES_VENDOR_ID                       43
#define GPT_FTM_TYPES_MODULE_ID                       100
#define GPT_FTM_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define GPT_FTM_TYPES_AR_RELEASE_MINOR_VERSION        2
#define GPT_FTM_TYPES_AR_RELEASE_REVISION_VERSION     2
#define GPT_FTM_TYPES_SW_MAJOR_VERSION                4
#define GPT_FTM_TYPES_SW_MINOR_VERSION                0
#define GPT_FTM_TYPES_SW_PATCH_VERSION                0

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
// #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
//     #if ((GPT_FTM_TYPES_AR_RELEASE_MAJOR_VERSION != FTM_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION) || \
//         (GPT_FTM_TYPES_AR_RELEASE_MINOR_VERSION != FTM_COMMON_TYPES_AR_RELEASE_MINOR_VERSION))
//     #error "AutoSar Version Numbers of Gpt_Ftm_Types.h and Ftm_Common_Types.h are different"
//     #endif
    
//     #if ((GPT_FTM_TYPES_AR_RELEASE_MAJOR_VERSION != REG_ESYS_FTM_AR_RELEASE_MAJOR_VERSION) || \
//         (GPT_FTM_TYPES_AR_RELEASE_MINOR_VERSION != REG_ESYS_FTM_AR_RELEASE_MINOR_VERSION))
//     #error "AutoSar Version Numbers of Gpt_Ftm_Types.h and Reg_eSys_Ftm.h are different"
//     #endif
// #endif

//     /* Check if Gpt_EnvCfg.h and Gpt_Ftm_Types.h file are of the same vendor */
// #if (GPT_FTM_TYPES_VENDOR_ID != GPT_ENVCFG_VENDOR_ID)
//     #error "Gpt_Ftm_Types.h and Gpt_EnvCfg.h have different vendor ids"
// #endif
//     /* Check if Gpt_EnvCfg.h and Gpt_Ftm_Types.h file are of the same Autosar version */
//     #if ((GPT_FTM_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
//         (GPT_FTM_TYPES_AR_RELEASE_MINOR_VERSION != GPT_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
//         (GPT_FTM_TYPES_AR_RELEASE_REVISION_VERSION != GPT_ENVCFG_AR_RELEASE_REVISION_VERSION))
//     #error "AutoSar Version Numbers of Gpt_EnvCfg.h and Gpt_Ftm_Types.h are different"
//     #endif
//     /* Check if Gpt_Ftm_Types.h and Gpt_EnvCfg header file are of the same software version */
// #if ((GPT_FTM_TYPES_SW_MAJOR_VERSION != GPT_ENVCFG_SW_MAJOR_VERSION) || \
//      (GPT_FTM_TYPES_SW_MINOR_VERSION != GPT_ENVCFG_SW_MINOR_VERSION) || \
//      (GPT_FTM_TYPES_SW_PATCH_VERSION != GPT_ENVCFG_SW_PATCH_VERSION))
//     #error "Software Version Numbers of Gpt_EnvCfg.h and Gpt_Ftm_Types.h are different"
// #endif

//     /* Check if Gpt_Cfg.h and Gpt_Ftm_Types.h file are of the same vendor */
// #if (GPT_FTM_TYPES_VENDOR_ID != GPT_VENDOR_ID_CFG)
//     #error "Gpt_Ftm_Types.h and Gpt_Cfg.h have different vendor ids"
// #endif
//     /* Check if Gpt_Cfg.h and Gpt_Ftm_Types.h file are of the same Autosar version */
//     #if ((GPT_FTM_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
//         (GPT_FTM_TYPES_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
//         (GPT_FTM_TYPES_AR_RELEASE_REVISION_VERSION != GPT_AR_RELEASE_REVISION_VERSION_CFG))
//     #error "AutoSar Version Numbers of Gpt_Cfg.h and Gpt_Ftm_Types.h are different"
//     #endif
//     /* Check if Gpt_Ftm_Types.h and Gpt_Cfg header file are of the same software version */
// #if ((GPT_FTM_TYPES_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION_CFG) || \
//      (GPT_FTM_TYPES_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION_CFG) || \
//      (GPT_FTM_TYPES_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION_CFG))
//     #error "Software Version Numbers of Gpt_Cfg.h and Gpt_Ftm_Types.h are different"
// #endif

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/*===============================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/**
* @brief FTM channel data type
*/
typedef uint8 Gpt_Ftm_ChannelType;

/**
* @brief FTM channel specific configuration data structure
*/
typedef struct
{
    uint8 u8FtmChannelId;
    uint32 u32FtmChannelTrigger;
    uint32 u32FtmChannelTriggerMask;
} Gpt_Ftm_ChannelConfigType;

/**
* @brief FTM specific configuration data structure
*/
typedef struct
{
    /* @brief number of modules in FTM configuration structure */
    CONST(Gpt_Ftm_ChannelType, GPT_CONST) nNumModules;
    /* @brief number of channels in FTM configuration structure */
    CONST(Gpt_Ftm_ChannelType, GPT_CONST) nNumChannels;
    /* @brief Index in Gpt_aHw2LogicChannelMap where FTM channels start */
    CONST(Gpt_Ftm_ChannelType, GPT_CONST) nFtmChannelsStartIdx;
    /* @brief pointer to FTM global configuration */
    CONST(Ftm_CommonConfigType, GPT_CONST) (*GptFtmGlobalConfiguration)[];
    /* @brief pointer to FTM modules trigger initialization setup  */
    CONST(uint32, GPT_CONST) (*u32InitTriggerEnable)[];
    /* @brief Array of configured FTM channels */
    CONST(Gpt_Ftm_ChannelConfigType, GPT_CONST) (*FtmChannels)[];
} Gpt_Ftm_IpConfigType;

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
*                                     FUNCTION PROTOTYPES
===============================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* GPT_FTM_TYPES_H */

/** @} */
