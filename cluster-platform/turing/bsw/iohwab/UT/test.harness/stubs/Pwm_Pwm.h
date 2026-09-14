/**
*   @file    Pwm_Pwm.h
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

#ifndef PWM_PWM_H
#define PWM_PWM_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_Pwm_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Pwm_Pwm_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
*/

/*===============================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
===============================================================================================*/
#include "Pwm_Ipw_Types.h"



/*===============================================================================================
                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/

/**
* @{
*/
#define PWM_PWM_H_VENDOR_ID                           43
#define PWM_PWM_H_MODULE_ID                           121
/* @violates @ref Pwm_Pwm_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_PWM_H_AR_RELEASE_MAJOR_VERSION            4
/* @violates @ref Pwm_Pwm_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_PWM_H_AR_RELEASE_MINOR_VERSION            2
/* @violates @ref Pwm_Pwm_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_PWM_H_AR_RELEASE_REVISION_VERSION         2
#define PWM_PWM_H_SW_MAJOR_VERSION                    4
#define PWM_PWM_H_SW_MINOR_VERSION                    0
#define PWM_PWM_H_SW_PATCH_VERSION                    0
/** @} */

/*===============================================================================================
                                      FILE VERSION CHECKS
===============================================================================================*/
/* Check if source file and PWM header file are of the same vendor */
#if (PWM_PWM_H_VENDOR_ID != PWM_IPW_TYPES_VENDOR_ID)
    #error "Pwm_Pwm.h and Pwm_Ipw_Types.h have different vendor ids"
#endif

/* Check if source file and PWM header file are of the same Autosar version */
#if ((PWM_PWM_H_AR_RELEASE_MAJOR_VERSION    != PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_PWM_H_AR_RELEASE_MINOR_VERSION    != PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_PWM_H_AR_RELEASE_REVISION_VERSION != PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Pwm.h and Pwm_Ipw_Types.h are different"
#endif

/* Check if source file and PWM header file are of the same software version */
#if ((PWM_PWM_H_SW_MAJOR_VERSION != PWM_IPW_TYPES_SW_MAJOR_VERSION) || \
     (PWM_PWM_H_SW_MINOR_VERSION != PWM_IPW_TYPES_SW_MINOR_VERSION) || \
     (PWM_PWM_H_SW_PATCH_VERSION != PWM_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm_Pwm.h and Pwm_Ipw_Types.h are different"
#endif


/*===============================================================================================
                                           CONSTANTS
===============================================================================================*/


/*===============================================================================================
                                       DEFINES AND MACROS
===============================================================================================*/
/**
* @brief          Defines the value for 100% duty.
*/
#define PWM_PWM_DUTY_100   ((uint16)0x8000)

/**
* @brief          Defines the value for 0% duty.
*/
#define PWM_PWM_DUTY_0   ((uint16)0)

#if ((PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON) || (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_POWER_STATE_SUPPORTED == STD_ON))
/**
* @brief          Defines the value for the running state of each Pwm channel
*/
#define PWM_CHANNEL_RUNNING  ((uint8)1)

/**
* @brief          Defines the value for the idle state of each Pwm channel
*/
#define PWM_CHANNEL_IDLE  ((uint8)0)

/**
* @brief          Defines the value for the output forced state of each Pwm channel
*/
#define PWM_CHANNEL_OUTPUT_FORCED  ((uint8)2)

#endif

/*===============================================================================================
                                             ENUMS
===============================================================================================*/


/*===============================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/


/*===============================================================================================
                                     FUNCTION PROTOTYPES
===============================================================================================*/
#define PWM_START_SEC_CODE

/** @violates @ref Pwm_Pwm_H_REF_1 Repeated include files */
#include "Pwm_MemMap.h"

FUNC (void, PWM_CODE) Pwm_Pwm_Init
(
    CONSTP2CONST(Pwm_Pwm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pPwmIpConfig
);

#if (PWM_DE_INIT_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Pwm_DeInit
(
    CONSTP2CONST(Pwm_Pwm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pPwmIpConfig
);
#endif


#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Pwm_SetDutyCycle
(
    VAR         (uint8,                 AUTOMATIC)                 u8IdxChannelConfig,
    VAR         (uint16,                AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_Pwm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pPwmIpConfig
);
#endif

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Pwm_SetPeriodAndDuty
(
    VAR         (uint8,                 AUTOMATIC)                 u8IdxChannelConfig,
    VAR         (Pwm_PeriodType,        AUTOMATIC)                 nPeriod,
    VAR         (uint16,                AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_Pwm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pPwmIpConfig
);
#endif /* PWM_SET_PERIOD_AND_DUTY_API */


#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Pwm_SetOutputToIdle
(
    VAR         (uint8,                AUTOMATIC)                  u8IdxChannelConfig,
    CONSTP2CONST(Pwm_Pwm_IpConfigType, AUTOMATIC,  PWM_APPL_CONST) pPwmIpConfig
);
#endif /* ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_DE_INIT_API == STD_ON)) */


#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)

FUNC (void, PWM_CODE) Pwm_Pwm_DisableNotification
(
    VAR         (uint8,                AUTOMATIC)                    u8IdxChannelConfig,
    CONSTP2CONST(Pwm_Pwm_IpConfigType, AUTOMATIC,  PWM_APPL_CONST)   pPwmIpConfig
);

FUNC (void, PWM_CODE) Pwm_Pwm_EnableNotification
(
    VAR         (uint8,                   AUTOMATIC)                 u8IdxChannelConfig,
    VAR         (Pwm_EdgeNotificationType,AUTOMATIC)                 eNotification,
    CONSTP2CONST(Pwm_Pwm_IpConfigType,    AUTOMATIC, PWM_APPL_CONST) pPwmIpConfig
);
#endif /* (PWM_NOTIFICATION_SUPPORTED == STD_ON) */

#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
FUNC(uint16, PWM_CODE) Pwm_Pwm_GetChannelState
(
    VAR         (uint8,                   AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_Pwm_IpConfigType,    AUTOMATIC, PWM_APPL_CONST) pPwmIpConfig
);
#endif /* PWM_GET_CHANNEL_STATE_API */

#if (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Pwm_ForceOutputToZero
(
    VAR         (Pwm_ChannelType,           AUTOMATIC)                 u8IdxChannelConfig,
    VAR         (boolean,                   AUTOMATIC)                 bForce,
    CONSTP2CONST(Pwm_Pwm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pPwmIpConfig
);
#endif

#if (PWM_SET_CLOCK_MODE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Pwm_SetClockMode
(
    VAR         (Pwm_PrescalerType,        AUTOMATIC)                 ePrescaler,
    CONSTP2CONST(Pwm_Pwm_IpConfigType,     AUTOMATIC, PWM_APPL_CONST) pPwmIpConfig
);
#endif

#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
FUNC(Std_ReturnType, PWM_CODE) Pwm_Pwm_ValidateIdleState
(
    P2CONST(Pwm_Pwm_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) pPwmIpConfig
);
FUNC(void, PWM_CODE) Pwm_Pwm_SetPowerState
(
    P2CONST(Pwm_Pwm_IpConfigType,      AUTOMATIC, PWM_APPL_CONST)   pPwmIpConfig,
    VAR    (Pwm_PowerStateType,          AUTOMATIC)                 nPowerState
);
#endif

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
FUNC(void, PWM_CODE) Pwm_Pwm_ProcessCommonInterrupt
(
    VAR(Pwm_Pwm_ChannelType, AUTOMATIC) nHwChannel
);
#endif

#define PWM_STOP_SEC_CODE
/** @violates @ref Pwm_Pwm_H_REF_1 Repeated include files */
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif


#endif   /* PWM_PWM_H */
/** @} */
