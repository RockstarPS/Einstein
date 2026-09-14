/**
*   @file    Soc_Ips.h
*   @version 4.0.0
*
*   @brief   AUTOSAR Base - IP module versions.
*   @details The IP modules versions used on ARM hardware platform and
*            IP specific defines
*
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : IMX8
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

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Soc_Ips_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused. The driver needs to use defines starting with letter E.
*/

#ifndef SOC_IPS_H
#define SOC_IPS_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file        Soc_Ips.h
* @brief Include platform types
* @violates @ref Soc_Ips_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Platform_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SOC_IPS_VENDOR_ID                    43
#define SOC_IPS_MODULE_ID                    0
#define SOC_IPS_AR_RELEASE_MAJOR_VERSION     4
#define SOC_IPS_AR_RELEASE_MINOR_VERSION     2
#define SOC_IPS_AR_RELEASE_REVISION_VERSION  2
#define SOC_IPS_SW_MAJOR_VERSION             4
#define SOC_IPS_SW_MINOR_VERSION             0
#define SOC_IPS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Platform_Types.h header file have same versions */
#if ((SOC_IPS_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
     (SOC_IPS_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Soc_Ips.h and Platform_Types.h are different"
#endif
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/
/**
* @brief PWM IP Version:  v06.00.00.02
* @details IMX8 Platform Defines/Configurations
*/
#define IPV_PWM                            (0x06000002U)

/**
@brief Number of SDMA controllers available
@details IMX8 Platform Defines/Configurations
*/
#define SDMA_NB_CONTROLLERS                (0x01U)
/**
* @brief Number of SDMA channels available
* @details IMX8 Platform Defines/Configurations
*/
#define DMA_NB_CHANNELS                    (0x20U)

/**
* @{
* @brief Defines which AutoSAR drivers use the common eDMA IP driver
*/
#define FLS_USE_DMA_LLD         (STD_ON)
#define SPI_USE_DMA_LLD         (STD_ON)
#define MCU_USE_DMA_LLD         (STD_ON)

/**
* @brief This is to fix the Errata ERR005829 FlexCAN: FlexCAN does not transmit a message that is enabled
* to be transmitted in a specific moment during the arbitration process,  Hence reserve 1st MB to be Inactive and
* updating twice the Code Section during the Transmission in the 1st MB.
* @details IMX6-A Platform specific Defines/Configurations for Errata:ERR005829
*/
#define ERR_IPV_FLEXCAN_ERR005829        (STD_ON)

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif


#endif /* #ifndef SOC_IPS_H*/

/** @} */
