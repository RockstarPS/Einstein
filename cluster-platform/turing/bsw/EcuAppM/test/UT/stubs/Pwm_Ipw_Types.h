/**
*   @file           Pwm_Ipw_Types.h
*   @version        4.0.0
*
*   @brief          AUTOSAR Pwm - PWM driver IPW header file.
*   @details        IPW defines, types used by PWM driver.
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



#ifndef PWM_IPW_TYPES_H
#define PWM_IPW_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_IPW_Types_H_REF_1
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*/
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pwm_Types.h"
#include "Pwm_Ftm_Types.h"
#include "Pwm_Pwm_Types.h"
#include "Pwm_Tpm_Types.h"


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Pwm_Ipw_Types.h
*/
#define PWM_IPW_TYPES_VENDOR_ID                         43
#define PWM_IPW_TYPES_MODULE_ID                         121
/* @violates @ref Pwm_IPW_Types_H_REF_1 Identifier exceeds 31 chars. */
#define PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION          4
/* @violates @ref Pwm_IPW_Types_H_REF_1 Identifier exceeds 31 chars. */
#define PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION          2
/* @violates @ref Pwm_IPW_Types_H_REF_1 Identifier exceeds 31 chars. */
#define PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION       2
#define PWM_IPW_TYPES_SW_MAJOR_VERSION                  4
#define PWM_IPW_TYPES_SW_MINOR_VERSION                  0
#define PWM_IPW_TYPES_SW_PATCH_VERSION                  0
/**@}*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if included Pwm_Ftm_Types.h header file has same vendor */
#if (PWM_IPW_TYPES_VENDOR_ID != PWM_FTM_TYPES_VENDOR_ID)
    #error "Pwm_Ipw_Types.h and Pwm_Ftm_Types.h have different vendor ids"
#endif

/* Check if included Pwm_Ftm_Types.h header file has same AUTOSAR version */
#if ((PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    !=  PWM_FTM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION    !=  PWM_FTM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION !=  PWM_FTM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ipw_Types.h and Pwm_Ftm_Types.h are different"
#endif

/* Check if included Pwm_Ftm_Types.h header file has same software version */
#if ((PWM_IPW_TYPES_SW_MAJOR_VERSION !=  PWM_FTM_TYPES_SW_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_SW_MINOR_VERSION !=  PWM_FTM_TYPES_SW_MINOR_VERSION) || \
     (PWM_IPW_TYPES_SW_PATCH_VERSION !=  PWM_FTM_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ipw_Types.h and Pwm_Ftm_Types.h are different"
#endif

/* Check if included Pwm_Pwm_Types.h header file has same vendor */
#if (PWM_IPW_TYPES_VENDOR_ID != PWM_PWM_TYPES_VENDOR_ID)
    #error "Pwm_Ipw_Types.h and Pwm_Pwm_Types.h have different vendor ids"
#endif

/* Check if included Pwm_Pwm_Types.h header file has same AUTOSAR version */
#if ((PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    !=  PWM_PWM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION    !=  PWM_PWM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION !=  PWM_PWM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ipw_Types.h and Pwm_Pwm_Types.h are different"
#endif

/* Check if included Pwm_Pwm_Types.h header file has same software version */
#if ((PWM_IPW_TYPES_SW_MAJOR_VERSION !=  PWM_PWM_TYPES_SW_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_SW_MINOR_VERSION !=  PWM_PWM_TYPES_SW_MINOR_VERSION) || \
     (PWM_IPW_TYPES_SW_PATCH_VERSION !=  PWM_PWM_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ipw_Types.h and Pwm_Pwm_Types.h are different"
#endif

/* Check if included Pwm_Tpm_Types.h header file has same vendor */
#if (PWM_IPW_TYPES_VENDOR_ID != PWM_TPM_TYPES_VENDOR_ID)
    #error "Pwm_Ipw_Types.h and Pwm_Tpm_Types.h have different vendor ids"
#endif

/* Check if included Pwm_Tpm_Types.h header file has same AUTOSAR version */
#if ((PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    !=  PWM_TPM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION    !=  PWM_TPM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION !=  PWM_TPM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ipw_Types.h and Pwm_Tpm_Types.h are different"
#endif

/* Check if included Pwm_Tpm_Types.h header file has same software version */
#if ((PWM_IPW_TYPES_SW_MAJOR_VERSION !=  PWM_TPM_TYPES_SW_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_SW_MINOR_VERSION !=  PWM_TPM_TYPES_SW_MINOR_VERSION) || \
     (PWM_IPW_TYPES_SW_PATCH_VERSION !=  PWM_TPM_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ipw_Types.h and Pwm_Tpm_Types.h are different"
#endif

/* Check if included Pwm_Types.h header file has same vendor */
#if (PWM_IPW_TYPES_VENDOR_ID != PWM_TYPES_VENDOR_ID)
    #error "Pwm_Ipw_Types.h and Pwm_Types.h have different vendor ids"
#endif

/* Check if included Pwm_Types.h header file has same AUTOSAR version */
#if ((PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    !=  PWM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION    !=  PWM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION !=  PWM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ipw_Types.h and Pwm_Types.h are different"
#endif

/* Check if included Pwm_Types.h header file has same software version */
#if ((PWM_IPW_TYPES_SW_MAJOR_VERSION !=  PWM_TYPES_SW_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_SW_MINOR_VERSION !=  PWM_TYPES_SW_MINOR_VERSION) || \
     (PWM_IPW_TYPES_SW_PATCH_VERSION !=  PWM_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ipw_Types.h and Pwm_Types.h are different"
#endif


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       PLATFORM SPECIFIC DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief Symbolic name for Ftm channels */
#define PWM_FTM_CHANNEL         ((Pwm_ChannelIpType)0)

/** @brief Symbolic name for Pwm channels */
#define PWM_PWM_CHANNEL         ((Pwm_ChannelIpType)1)

/** @brief Symbolic name for Tpm channels */
#define PWM_TPM_CHANNEL         ((Pwm_ChannelIpType)2)

/** @brief Duty cycle 50%*/
#define PWM_HALF_PERIOD_DUTY    ((uint16)0x4000U)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief      IP type used to implement a Pwm channel
*/
typedef uint8 Pwm_ChannelIpType;


/**
* @brief      Pwm channel high level configuration structure
*/
typedef struct
{
    /** @brief The IP used to implement this specific Pwm channel */
    CONST(Pwm_ChannelIpType,    PWM_CONST) nChannelIp;
    /** @brief Index in the IP specific configuration table */
    CONST(uint8,                PWM_CONST) u8IdxChannelConfig;
} Pwm_IpChannelConfigType;


/**
* @brief      Combined IP specific configuration structure
*/
typedef struct
{
    /** FTM IP configuration structure */
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  PWM_CONST, PWM_APPL_CONST) pFtmIpConfig;
    /** PWM IP configuration structure */
    CONSTP2CONST(Pwm_Pwm_IpConfigType,  PWM_CONST, PWM_APPL_CONST) pPwmIpConfig;
    /** TPM IP configuration structure */
    CONSTP2CONST(Pwm_Tpm_IpConfigType,  PWM_CONST, PWM_APPL_CONST) pTpmIpConfig;
    /** @brief Pointer to Array containing IP type and index in the IP configuration table for each Pwm channel */
    CONST       (Pwm_IpChannelConfigType,  PWM_CONST)              (*pIpChannelsConfig)[];
} Pwm_IpConfigType;


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif    /* PWM_IPW_TYPES_H */

/** @} */

