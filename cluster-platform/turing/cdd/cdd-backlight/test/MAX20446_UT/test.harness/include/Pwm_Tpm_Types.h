/**
*   @file           Pwm_Tpm_Types.h
*   @version        4.0.0
*
*   @brief          AUTOSAR Pwm - Tpm data types header file.
*   @details        Tpm defines, types used by PWM driver.
*
*   @addtogroup     PWM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : PWM_FTM
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

#ifndef PWM_TPM_TYPES_H
#define PWM_TPM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_Tpm_Types_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. All header files are
* protected against multiple inclusions.
*
* @section Pwm_Tpm_Types_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/

/** @violates @ref Pwm_Tpm_Types_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "Pwm_Cfg.h"


/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Pwm_Tpm_Types.h
*/

#define PWM_TPM_TYPES_VENDOR_ID                       43
#define PWM_TPM_TYPES_MODULE_ID                       121
/* @violates @ref Pwm_Tpm_Types_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_TPM_TYPES_AR_RELEASE_MAJOR_VERSION        4
/* @violates @ref Pwm_Tpm_Types_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_TPM_TYPES_AR_RELEASE_MINOR_VERSION        2
/* @violates @ref Pwm_Tpm_Types_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_TPM_TYPES_AR_RELEASE_REVISION_VERSION     2
#define PWM_TPM_TYPES_SW_MAJOR_VERSION                4
#define PWM_TPM_TYPES_SW_MINOR_VERSION                0
#define PWM_TPM_TYPES_SW_PATCH_VERSION                0
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

/* Check if header file and Pwm_Cfg.h header file are of the same vendor */
#if (PWM_TPM_TYPES_VENDOR_ID != PWM_CFG_VENDOR_ID)
    #error "Pwm_Tpm_Types.h and Pwm_Cfg.h have different vendor ids"
#endif
/* Check if header file and Pwm_Cfg.h header file are of the same Autosar version */
#if ((PWM_TPM_TYPES_AR_RELEASE_MAJOR_VERSION    != PWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_TPM_TYPES_AR_RELEASE_MINOR_VERSION    != PWM_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_TPM_TYPES_AR_RELEASE_REVISION_VERSION != PWM_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Tpm_Types.h and Pwm_Cfg.h are different"
#endif
/* Check if header file and Pwm_Cfg.h header file are of the same software version */
#if ((PWM_TPM_TYPES_SW_MAJOR_VERSION != PWM_CFG_SW_MAJOR_VERSION) || \
     (PWM_TPM_TYPES_SW_MINOR_VERSION != PWM_CFG_SW_MINOR_VERSION) || \
     (PWM_TPM_TYPES_SW_PATCH_VERSION != PWM_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Tpm_Types.h and Pwm_Cfg.h are different"
#endif


/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/


/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/**
* @brief      Pwm signal alignment. This parameter is applied at a Pwm submodule level and is
*             available only for Tpm
* @details    This field will vary the alignment of the output signals for the specified channel
*             If the selected mode is PWM_EDGE_ALIGNED the signals will be aligned at the starting
*             edge of the Pwm period
*             If the selected mode is PWM_CENTER_ALIGNED the signals will be aligned around the
*             middle of the Pwm period.
*             The on-time and off-time will be divided such as the output signal will be symmetric
*             around the middle of the Pwm period.
*             Setting this option will allow only output A and B for a selected Tpm sub-module
*/
typedef enum
{
    /** @brief One signal is generated that is aligned at the starting edge of the Pwm period.
    This is the default generation mode */
    PWM_TPM_EDGE_ALIGNED = 0,
    /** @brief One signal is generated that is aligned around the middle of the Pwm period */
    PWM_TPM_CENTER_ALIGNED,
    /** @brief Two channels are combined into two signals with the same polarity but can be phase shifted from the master channel by a configurable deadtime; first channel defines the leading edge of the signal, second channel defines the trailing edge of the signal. */
    PWM_TPM_COMBINE_SYNCED,
    /** @brief Two channels are combined into two signals with the same polarity which can be phase shifted from the master channel by a configurable deadtime; first channel defines the leading edge of the signal, second channel defines the trailing edge of the signal. */
    PWM_TPM_COMBINE_COMPL
}Pwm_Tpm_AlignmentType;

/*===============================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/**
* @brief      Tpm HW channel type
*/
typedef uint8 Pwm_Tpm_ChannelType;

/**
* @brief      Tpm HW module type ID
*/
typedef uint8 Pwm_Tpm_ModuleType;


/**
* @brief      Tpm Defines of the Tpm hw modules
*/
#define PWM_TPM_0    ((Pwm_Tpm_ModuleType) 0)

/**
* @brief      Tpm Defines of the Tpm hw modules
*/
#define PWM_TPM_1    ((Pwm_Tpm_ModuleType) 1)

/**
* @brief      Tpm Channel notification state type ID
*/
typedef uint8 Pwm_Tpm_ChannelNotifType;


/**
* @brief      Tpm TOF IRQ state type ID
*/
typedef uint8 Pwm_Tpm_EdgeStateType;

/**
* @brief Tpm IP specific channel configuration structure type
*/
typedef struct
{
    /** @brief Pwm signal polarity:   High or low */
    CONST(Pwm_OutputStateType,     PWM_CONST) ePwmPolarity;
    /** @brief Pwm signal idle state: High or low */
    CONST(Pwm_OutputStateType,     PWM_CONST) ePwmIdleState;
    /** @brief Default value for duty cycle: [0-0x8000] (0-100%) */
    CONST(uint16,              PWM_CONST)    u16PwmDefaultDutyCycle;
    /** @brief Tpm channel id*/
    CONST(Pwm_Tpm_ChannelType, PWM_CONST)    nHwChannelId;
    /** @brief channel alignment type */
    CONST(Pwm_Tpm_AlignmentType, PWM_CONST)   eAlignment;

} Pwm_Tpm_ChannelConfigType;


/**
* @brief Tpm IP specific common to all Tpm channels configuration structure type
*/
typedef struct
{
    /** @brief configuration register value */
    CONST(uint32, PWM_CONST)    u32RegConf;
    /** @brief status and control register value */
    CONST(uint32, PWM_CONST)    u32RegSc;
#if (PWM_SET_CLOCK_MODE_API == STD_ON)
    /** @brief alternate status and control register value */
    CONST(uint32, PWM_CONST)    u32AlternateRegSc;
#endif
    /** @brief deadtime register value */
    CONST(uint32, PWM_CONST)    u32RegDeadtime;
    /** @brief channel combine register value */
    CONST(uint32, PWM_CONST)    u32RegCombine;
    /** @brief Id value of the configured TPM module */
    CONST(uint8, PWM_CONST)     u8TpmHwModuleId;
    /** @brief default period (mod) register value */
    CONST(uint32, PWM_CONST)    u32RegModVal;

} Pwm_Tpm_ModuleConfigType;


/**
* @brief      Tpm IP specific channels and module configuration structure type
*/
typedef struct
{
    /** @brief Number of Tpm channels in eacb module of the current the Pwm configuration */
    CONST(Pwm_Tpm_ChannelType,         PWM_CONST) nNumChannels;

    /** @brief Number of Tpm modules in the Pwm configuration */
    CONST(Pwm_Tpm_ModuleType,         PWM_CONST) nNumModules;


    /** @brief Pointer to the configured channels for Tpm */
    CONST(Pwm_Tpm_ChannelConfigType,   PWM_CONST) (*pChannelsConfig)[];

    /** @brief Pointer to the configured channels for the Tpm Module */
    CONST(Pwm_Tpm_ModuleConfigType,    PWM_CONST) (*pModulesConfig)[];
} Pwm_Tpm_IpConfigType;




/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/



/** @brief      Defines that specifies the Module types used in Pwm_Tpm_ModuleType type
*/
#define PWM_TPM_NO_EDGE                  ((Pwm_Tpm_EdgeStateType)0U)
#define PWM_TPM_CHF_IRQ_EDGE             ((Pwm_Tpm_EdgeStateType)1U)
#define PWM_TPM_TOF_IRQ_EDGE             ((Pwm_Tpm_EdgeStateType)2U)
#define PWM_TPM_TOF_IRQ_NO_EDGE_NOTIF    ((Pwm_Tpm_EdgeStateType)4U)
#define PWM_TPM_CHANNEL_NOT_USED         ((Pwm_Tpm_EdgeStateType)255U)



/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
*                                     FUNCTION PROTOTYPES
===============================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* PWM_TPM_TYPES_H */

/** @} */
