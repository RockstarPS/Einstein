/**
*   @file    Mcu_Lpcg.h
*   @version 4.0.0
*
*   @brief   AUTOSAR Mcu - Low level header file for MCU driver.
*   @details This file contains declarations of the low level functions defined for MCU driver.
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

#ifndef MCU_LPCG_H
#define MCU_LPCG_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_SCFW_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_SCFW_H_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register
* operations. Function like macros are used to reduce code complexity.
*
* @section Mcu_SCFW_H_REF_3
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31
* characters.
*
* @section Mcu_SCFW_H_REF_4
* Violates MISRA 2004 Required Rule  5.1, Identifier exceeds 31 characters
*
* @section Mcu_LPCG_H_REF_5
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
* signifcance and case sensitivity are supported for external identifers.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @violates @ref Mcu_SCFW_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu.h"
/**
* @violates @ref Mcu_SCFW_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_LPCG_VENDOR_ID                      43
/* @violates @ref Mcu_SCFW_H_REF_4 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
/* @violates @ref Mcu_LPCG_H_REF_5 MISRA 2004 Required Rule 1.4, The compiler/linker
 * shall be checked to ensure that 31 character */
#define MCU_LPCG_AR_RELEASE_MAJOR_VERSION       4
/* @violates @ref Mcu_SCFW_H_REF_4 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
/* @violates @ref Mcu_LPCG_H_REF_5 MISRA 2004 Required Rule 1.4, The compiler/linker
 * shall be checked to ensure that 31 character */
#define MCU_LPCG_AR_RELEASE_MINOR_VERSION       2
/* @violates @ref Mcu_SCFW_H_REF_4 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
/* @violates @ref Mcu_LPCG_H_REF_5 MISRA 2004 Required Rule 1.4, The compiler/linker
 * shall be checked to ensure that 31 character */
#define MCU_LPCG_AR_RELEASE_REVISION_VERSION    2
#define MCU_LPCG_SW_MAJOR_VERSION               4
#define MCU_LPCG_SW_MINOR_VERSION               0
#define MCU_LPCG_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu header file are from the same vendor */
#if (MCU_LPCG_VENDOR_ID != MCU_VENDOR_ID)
    #error "Mcu_Lpcg.h and Mcu.h have different vendor ids"
#endif
/* Check if source file and Mcu header file are of the same Autosar version */
#if ((MCU_LPCG_AR_RELEASE_MAJOR_VERSION != MCU_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_LPCG_AR_RELEASE_MINOR_VERSION != MCU_AR_RELEASE_MINOR_VERSION) || \
     (MCU_LPCG_AR_RELEASE_REVISION_VERSION != MCU_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_Lpcg.h and Mcu.h are different"
#endif
/* Check if source file and Mcu header file are of the same Software version */
#if ((MCU_LPCG_SW_MAJOR_VERSION != MCU_SW_MAJOR_VERSION) || \
     (MCU_LPCG_SW_MINOR_VERSION != MCU_SW_MINOR_VERSION) || \
     (MCU_LPCG_SW_PATCH_VERSION != MCU_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_Lpcg.h and Mcu.h are different"
#endif

/* Check if current file and Mcal header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_LPCG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_LPCG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_Lpcg.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define MCU_START_SEC_CODE
/*
* @violates @ref Mcu_SCFW_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"

#if (MCU_CLOCK_GATE_CONTROL == STD_ON)
extern FUNC (void, MCU_CODE) Mcu_Lpcg_ClockGateControl(P2CONST(Mcu_ClockGateConfigType, AUTOMATIC, MCU_APPL_CONST) Lpcg_pClockGateConfigPtr);
#endif /* MCU_CLOCK_GATE_CONTROL == STD_ON */

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_SCFW_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* MCU_LPCG_H */
