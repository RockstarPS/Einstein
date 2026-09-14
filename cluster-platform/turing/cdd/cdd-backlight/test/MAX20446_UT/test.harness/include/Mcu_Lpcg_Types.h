/**
*   @file    Mcu_Lpcg_Types.h
*   @version 4.0.0
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from IPV_CMU.
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


#ifndef MCU_LPCG_TYPES_H
#define MCU_LPCG_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_Scfw_Types_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_Cfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_LPCG_TYPES_VENDOR_ID                    43
#define MCU_LPCG_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define MCU_LPCG_TYPES_AR_RELEASE_MINOR_VERSION     2
#define MCU_LPCG_TYPES_AR_RELEASE_REVISION_VERSION  2
#define MCU_LPCG_TYPES_SW_MAJOR_VERSION             4
#define MCU_LPCG_TYPES_SW_MINOR_VERSION             0
#define MCU_LPCG_TYPES_SW_PATCH_VERSION             0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and PLLDIG header file are from the same vendor */
#if (MCU_LPCG_TYPES_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu_Lpcg_Types.h and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if source file and PLLDIG header file are of the same Autosar version */
#if ((MCU_LPCG_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_LPCG_TYPES_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_LPCG_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_Lpcg_Types.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and PLLDIG header file are of the same Software version */
#if ((MCU_LPCG_TYPES_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_LPCG_TYPES_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_LPCG_TYPES_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_Lpcg_Types.h and Mcu_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define LPCG_CLK_HWEN_MASK      (0x11111111U)
#define LPCG_CLK_SWEN_MASK      (0x22222222U)
#define LPCG_CLK_STOP_MASK      (0x00000000U)
#define LPCG_CLK_AUTOGATE_MASK  (0x33333333U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (MCU_CLOCK_GATE_CONTROL == STD_ON)
/**
* @brief   Definition of a resource's clock configuration
*
* @api
*/
typedef struct
{
    /**< @brief LPCG register address */
    VAR(uint32, MCU_VAR)  u32LpcgAddress;
    /**< @brief  LPCG register value*/
    VAR(uint32, MCU_VAR) u32LPcgValue;
} Mcu_Lpcg_ClockGateConfigType;
#endif /* MCU_CLOCK_GATE_CONTROL == STD_ON */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_LPCG_TYPES_H */

/** @} */

