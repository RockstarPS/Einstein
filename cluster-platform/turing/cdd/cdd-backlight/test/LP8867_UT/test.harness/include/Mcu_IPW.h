/**
*   @file    Mcu_IPW.h
*   @implements Mcu_IPW.h_Artifact
*   @version 4.0.0
*
*   @brief   AUTOSAR Mcu - Midle layer interface for Higher layer.
*   @details File contains function prototypes used by HLD only.
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


#ifndef MCU_IPW_H
#define MCU_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_IPW_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Mcu_IPW_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
* signifcance and case sensitivity are supported for external identifers.
*
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_IPW_Types.h"
#include "Mcu_EnvCfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_IPW_VENDOR_ID                       43
/** @violates @ref Mcu_IPW_h_REF_2 MISRA 2004 Required Rule 1.4, The compiler/linker 
 *  shall be checked to ensure that 31 character */
#define MCU_IPW_AR_RELEASE_MAJOR_VERSION        4
/** @violates @ref Mcu_IPW_h_REF_2 MISRA 2004 Required Rule 1.4, The compiler/linker 
 *  shall be checked to ensure that 31 character */
#define MCU_IPW_AR_RELEASE_MINOR_VERSION        2
/** @violates @ref Mcu_IPW_h_REF_2 MISRA 2004 Required Rule 1.4, The compiler/linker 
 *  shall be checked to ensure that 31 character */
#define MCU_IPW_AR_RELEASE_REVISION_VERSION     2
#define MCU_IPW_SW_MAJOR_VERSION                4
#define MCU_IPW_SW_MINOR_VERSION                0
#define MCU_IPW_SW_PATCH_VERSION                0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/**
* @brief            The MCU module's implementer shall avoid the integration of incompatible files.
*/

/* Check if current file and Mcu_IPW_Types header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID != MCU_IPW_TYPES_VENDOR_ID)
    #error "Mcu_IPW.h and Mcu_IPW_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_IPW_Types header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION    != MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION    != MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION != MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.h and Mcu_IPW_Types.h are different"
#endif

/* Check if current file and Mcu_IPW_Types header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION != MCU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION != MCU_IPW_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION != MCU_IPW_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.h and Mcu_IPW_Types.h are different"
#endif

/* Check if current file and Mcu_EnvCfg header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID != MCU_SCFG_VENDOR_ID)
    #error "Mcu_IPW.h and Mcu_EnvCfg.h have different vendor ids"
#endif

/* Check if current file and Mcu_EnvCfg header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION    != MCU_SCFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION    != MCU_SCFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION != MCU_SCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.h and Mcu_EnvCfg.h are different"
#endif

/* Check if current file and Mcu_EnvCfg header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION != MCU_SCFG_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION != MCU_SCFG_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION != MCU_SCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.h and Mcu_EnvCfg.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
/** @violates @ref Mcu_IPW_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Mcu_MemMap.h"


FUNC( void, MCU_CODE) Mcu_Ipw_Init(P2CONST(Mcu_HwIPsConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pHwIPsConfigPtr);

#if (MCU_INIT_CLOCK == STD_ON)
FUNC( void, MCU_CODE) Mcu_Ipw_InitClock(P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pClockConfigPtr);
#endif /* (MCU_INIT_CLOCK == STD_ON) */

FUNC( Std_ReturnType, MCU_CODE) Mcu_Ipw_SetMode(P2CONST(Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pModeConfigPtr);

#if MCU_PERFORM_RESET_API == STD_ON
FUNC( void, MCU_CODE) Mcu_Ipw_PerformReset(P2CONST(Mcu_HwIPsConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pHwIPsConfigPtr);
#endif /* (MCU_PERFORM_RESET_API == STD_ON) */

FUNC( Mcu_ResetType, MCU_CODE) Mcu_Ipw_GetResetReason(VAR(void, AUTOMATIC));

FUNC( Mcu_RawResetType, MCU_CODE) Mcu_Ipw_GetResetRawValue(VAR(void, AUTOMATIC));


#if (MCU_GET_RAM_STATE_API == STD_ON)
FUNC ( Mcu_RamStateType, MCU_CODE) Mcu_Ipw_GetRamState(VAR(void, AUTOMATIC));
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */

#if (MCU_NO_PLL == STD_OFF)
FUNC( Mcu_PllStatusType, MCU_CODE) Mcu_Ipw_GetPllStatus( VAR( void, AUTOMATIC));
#endif /* (MCU_NO_PLL == STD_OFF) */

#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
FUNC( void, MCU_CODE) Mcu_Ipw_DistributePllClock(VAR(void, AUTOMATIC));
#endif /* (MCU_NO_PLL == STD_OFF) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#if (MCU_CLOCK_GATE_CONTROL == STD_ON)
FUNC( void, MCU_CODE) Mcu_Ipw_ClockGateControl(P2CONST(Mcu_ClockGateConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pClockGateConfigPtr);
#endif /* (MCU_CLOCK_GATE_CONTROL == STD_ON) */

#define MCU_STOP_SEC_CODE
/** @violates @ref Mcu_IPW_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* MCU_IPW_H */

/** @} */
