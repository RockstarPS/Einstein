/**
*   @file    Pwm_Pwm_Types.h
*   @version 4.0.0
*
*   @brief   AUTOSAR Pwm - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup PWM_MODULE
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

#ifndef PWM_PWM_TYPES_H
#define PWM_PWM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_Pwm_Types_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. All header files are
* protected against multiple inclusions.
*
* @section Pwm_Pwm_Types_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*/

/*===============================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
===============================================================================================*/
/** @violates @ref Pwm_Pwm_Types_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "Pwm_Cfg.h"


/*===============================================================================================
                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/

#define PWM_PWM_TYPES_VENDOR_ID                         43
#define PWM_PWM_TYPES_MODULE_ID                         121
/* @violates @ref Pwm_Pwm_Types_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_PWM_TYPES_AR_RELEASE_MAJOR_VERSION          4
/* @violates @ref Pwm_Pwm_Types_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_PWM_TYPES_AR_RELEASE_MINOR_VERSION          2
/* @violates @ref Pwm_Pwm_Types_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_PWM_TYPES_AR_RELEASE_REVISION_VERSION       2
/* @violates @ref Pwm_Pwm_Types_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_PWM_TYPES_SW_MAJOR_VERSION                  4
/* @violates @ref Pwm_Pwm_Types_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_PWM_TYPES_SW_MINOR_VERSION                  0
/* @violates @ref Pwm_Pwm_Types_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_PWM_TYPES_SW_PATCH_VERSION                  0


/*===============================================================================================
                                      FILE VERSION CHECKS
===============================================================================================*/

/* Check if header file and Pwm_Cfg.h header file are of the same vendor */
#if (PWM_PWM_TYPES_VENDOR_ID != PWM_CFG_VENDOR_ID)
    #error "Pwm_Pwm_Types.h and Pwm_Cfg.h have different vendor ids"
#endif
/* Check if header file and Pwm_Cfg.h header file are of the same Autosar version */
#if ((PWM_PWM_TYPES_AR_RELEASE_MAJOR_VERSION    != PWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_PWM_TYPES_AR_RELEASE_MINOR_VERSION    != PWM_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_PWM_TYPES_AR_RELEASE_REVISION_VERSION != PWM_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Pwm_Types.h and Pwm_Cfg.h are different"
#endif
/* Check if header file and Pwm_Cfg.h header file are of the same software version */
#if ((PWM_PWM_TYPES_SW_MAJOR_VERSION != PWM_CFG_SW_MAJOR_VERSION) || \
     (PWM_PWM_TYPES_SW_MINOR_VERSION != PWM_CFG_SW_MINOR_VERSION) || \
     (PWM_PWM_TYPES_SW_PATCH_VERSION != PWM_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Pwm_Types.h and Pwm_Cfg.h are different"
#endif

/*===============================================================================================
                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
                                       DEFINES AND MACROS
===============================================================================================*/

/*===============================================================================================
                                             ENUMS
===============================================================================================*/


/*===============================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/**
* @brief   Pwm HW channel id type, make sure it is the same type as Pwm_ChannelType
*
*/
typedef uint8 Pwm_HwChannelType;


/**
* @brief   Pwm unified channel control register value
*
*/
typedef uint32 Pwm_CtrlParamType;

/**
* @brief      Pwm HW channel type
*/
typedef uint8 Pwm_Pwm_ChannelType;


/**
* @brief Pwm IP specific channel configuration structure for the PWM functionality
*
*/
typedef struct
{
    /** @brief Pwm signal polarity:   High or low */
    CONST(Pwm_OutputStateType,      PWM_CONST) ePwmPolarity;
    /** @brief Pwm signal idle state: High or low */
    CONST(Pwm_OutputStateType,      PWM_CONST) ePwmIdleState;
    /** @brief Default value for duty cycle: [0-0x8000] (0-100%) */
    CONST(uint16,                   PWM_CONST) u16PwmDefaultDutyCycle;
    /** @brief Pwm channel id*/
    CONST(Pwm_Pwm_ChannelType,      PWM_CONST) nHwChannel;
    /** @brief default period (mod) register value */
    CONST(uint16,                   PWM_CONST) u16RegModVal;
    /** @brief control register value */
    CONST(Pwm_CtrlParamType,        PWM_CONST) u32ControlParam;

#if (PWM_SET_CLOCK_MODE_API == STD_ON)
    /** @brief alternate status and control register value */
    CONST(uint32,                   PWM_CONST) u32AlternateRegSc;
#endif
} Pwm_Pwm_ChannelConfigType;

/**
* @brief      Pwm IP specific channels and module configuration structure type
*/
typedef struct
{
    /** @brief Number of Pwm channels in eacb module of the current the Pwm configuration */
    CONST(Pwm_Pwm_ChannelType,        PWM_CONST) nNumChannels;

    /** @brief Pointer to the configured channels for Pwm */
    CONST(Pwm_Pwm_ChannelConfigType,  PWM_CONST) (*pChannelsConfig)[];
} Pwm_Pwm_IpConfigType;



/*===============================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* PWM_PWM_TYPES_H */

/** @} */
