/**
*   @file    Mcu_IPW_Types.h
*   @version 4.0.0
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from IPW.
*   @details Public data types exported outside of the Mcu driver.
*
*   @addtogroup MCU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : SCFW
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


#ifndef MCU_IPW_TYPES_H
#define MCU_IPW_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_IPW_Types_h_REF_1
* Violates MISRA 2004 Required Rule 20.2, The names of standard macros, objects and
* functions shall not be reused
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_Cfg.h"
#include "Mcu_Scfw_Types.h"
#include "Mcu_Lpcg_Types.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcu_IPW_Types.h
* @requirements   BSW00374, BSW00379, BSW00318
*/
#define MCU_IPW_TYPES_VENDOR_ID                       43
#define MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION        2
#define MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION     2
#define MCU_IPW_TYPES_SW_MAJOR_VERSION                4
#define MCU_IPW_TYPES_SW_MINOR_VERSION                0
#define MCU_IPW_TYPES_SW_PATCH_VERSION                0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/**
* @brief            The MCU module's implementer shall avoid the integration of incompatible files.
*/

/* Check if current file and Mcu_Cfg.h header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_Cfg.h have different vendor ids"
#endif

/* Check if current file and Mcu_Cfg.h header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_Cfg.h are different"
#endif

/* Check if current file and Mcu_Cfg.h header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and Mcu_Scfw_Types.h header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_SCFW_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_Scfw_Types.h have different vendor ids"
#endif

/* Check if source file and Mcu_Scfw_Types.h header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_SCFW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_SCFW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_SCFW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_Scfw_Types.h are different"
#endif

/* Check if source file and Mcu_Scfw_Types.h header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_SCFW_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_SCFW_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_SCFW_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_Scfw_Types.h are different"
#endif

/* Check if source file and Mcu_Lpcg_Types.h header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_LPCG_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_Lpcg_Types.h have different vendor ids"
#endif

/* Check if source file and Mcu_Lpcg_Types.h header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_LPCG_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_LPCG_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_LPCG_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_Lpcg_Types.h are different"
#endif

/* Check if source file and Mcu_Lpcg_Types.h header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_LPCG_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_LPCG_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_LPCG_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_Lpcg_Types.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief        Mcu_ClockNotificationType
* @details      Clock failure notification.
*               Enable/disable clock failure interrupt generated by the MCU.
*/
typedef enum
{
    MCU_CLK_NOTIF_DIS = 0x5AU,   /**< @brief Disable clock notification. */
    MCU_CLK_NOTIF_EN = 0xA5U  /**< @brief Enable clock notification. */

} Mcu_ClockNotificationType;
#endif /* (MCU_INIT_CLOCK == STD_ON) */

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief            Mcu driver configuration structure.
* @details         Configuration for System Controller Firmware (SCFW) module.
*                   Used by "Mcu_ConfigType" structure.
*
*/
typedef struct
{
    P2CONST( Mcu_Scfw_ConfigType, MCU_CONST, MCU_APPL_CONST) Scfw_pConfig;
} Mcu_HwIPsConfigType;

#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            Definition of a Clock configuration.
* @details          This configuration is transmitted as parameter to Mcu_Ipw_InitClock() API.
*                   Used by "Mcu_ConfigType" structure.
*
* @note             The structure Mcu_ConfigType shall provide a configurable (enable/ disable)
*                   clock failure notification if the MCU provides an interrupt for such detection.
*
*/
typedef struct
{
    /**< @brief The ID for Clock configuration. */
    VAR(Mcu_ClockType, MCU_VAR) Mcu_ClkConfigId;
    /**< @brief Total of resources to configure the clock. */
    VAR(uint16, MCU_VAR) Mcu_u16NoResourceConfigs;
    /**< @brief Pointer to clock configuration. */
    P2CONST(Mcu_Scfw_ClockConfigType, MCU_CONST, MCU_APPL_CONST) Mcu_Scfw_pClockConfig;
} Mcu_ClockConfigType;

#endif /* (MCU_INIT_CLOCK == STD_ON) */

#if (MCU_CLOCK_GATE_CONTROL == STD_ON)
/**
* @brief            Definition of a Clock gate configuration.
* @details          This configuration is transmitted as parameter to Mcu_Ipw_ClockGateControl() API.
*                   Used by "Mcu_ConfigType" structure.
*
* @note             The structure Mcu_ConfigType shall provide a configurable to control 
*                   clock gate.
*
*/
typedef struct
{
    /**< @brief The ID for Clock Gate configuration. */
    VAR(Mcu_ClockType, MCU_VAR) Mcu_ClkGateConfigId;
    /**< @brief Total of resources to configure the clock. */
    VAR(uint16, MCU_VAR) Mcu_u16NoResourceConfigs;
    /**< @brief Pointer to clock gate configuration. */
    P2CONST(Mcu_Lpcg_ClockGateConfigType, MCU_CONST, MCU_APPL_CONST) Mcu_Lpcg_pClockGateConfig;
} Mcu_ClockGateConfigType;

#endif /* (MCU_CLOCK_GATE_CONTROL == STD_ON) */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_IPW_TYPES_H */


/** @} */
