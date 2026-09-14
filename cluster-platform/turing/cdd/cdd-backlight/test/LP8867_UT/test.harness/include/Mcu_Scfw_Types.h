/**
*   @file    Mcu_Scfw_Types.h
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


#ifndef MCU_SCFW_TYPES_H
#define MCU_SCFW_TYPES_H


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
#include "Mcl_Scfw_Pm_Apis.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_SCFW_TYPES_VENDOR_ID                    43
#define MCU_SCFW_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define MCU_SCFW_TYPES_AR_RELEASE_MINOR_VERSION     2
#define MCU_SCFW_TYPES_AR_RELEASE_REVISION_VERSION  2
#define MCU_SCFW_TYPES_SW_MAJOR_VERSION             4
#define MCU_SCFW_TYPES_SW_MINOR_VERSION             0
#define MCU_SCFW_TYPES_SW_PATCH_VERSION             0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and PLLDIG header file are from the same vendor */
#if (MCU_SCFW_TYPES_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu_Scfw_Types.h and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if source file and PLLDIG header file are of the same Autosar version */
#if ((MCU_SCFW_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SCFW_TYPES_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SCFW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_Scfw_Types.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and PLLDIG header file are of the same Software version */
#if ((MCU_SCFW_TYPES_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_SCFW_TYPES_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_SCFW_TYPES_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_Scfw_Types.h and Mcu_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcl_Scfw_Pm_Apis header file are of the same version */
    #if ((MCU_SCFW_TYPES_AR_RELEASE_MAJOR_VERSION != SCFW_PM_API_AR_RELEASE_MAJOR_VERSION_H) || \
         (MCU_SCFW_TYPES_AR_RELEASE_MINOR_VERSION != SCFW_PM_API_AR_RELEASE_MINOR_VERSION_H) \
        )
        #error "AutoSar Version Numbers of Mcu_Scfw_Types.c and Mcl_Scfw_Pm_Apis.h are different"
    #endif
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
/**
* @brief            Power Modes encoding.
* @details          Supported power modes for SMC hw IP.
*/
typedef enum
{
    MCU_RUN_MODE = 1U,  /* @brief Normal Run Mode. */
    MCU_WAIT_MODE,      /* @brief Wait Mode. */
    MCU_STOP_MODE,      /* @brief Stop mode */
    MCU_VLPR_MODE,      /* @brief Very Low Power Run Mode. */
    MCU_VLPW_MODE,      /* @brief Very Low Power Wait Mode. */
    MCU_VLPS_MODE,      /* @brief Very Low Power Stop Mode. */
    MCU_LLS_MODE,       /* @brief Low Leakage Stop Mode. */
    MCU_VLLS_MODE       /* @brief Very Low Leakage Stop Mode. */
} Mcu_PowerModeType;

/**
* @brief            Reset Types encoding.
* @details          Supported reset types for SC IP.
*/
#define M4_RESET    ((Mcl_Scfw_PmResetType)0xFF)
typedef Mcl_Scfw_PmResetType Mcu_Scfw_ResetType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief   Definition of a resource mode configuration.
*
* @api
*/
typedef Mcl_Scfw_PmPowerModeType Mcu_Scfw_ResourceMode;

typedef uint32 Mcu_Scfw_ResourceId;

typedef struct
{
    /** ID of Resource from SCFW */
    VAR( Mcu_Scfw_ResourceId, MCU_VAR ) u32ResourceID;
    /** Power mode of Resource (POWER_OFF/POWER_ON/STBY/LP) */
    VAR( Mcu_Scfw_ResourceMode, MCU_VAR ) eResourceMode;
}Mcu_Scfw_ResourceConfigType;

/**
* @brief            Configuration of MC_RGM hw IP.
* @details          This data configuration is set at module initialization phase.
*/
typedef struct
{
    /**< @brief Pointer to Message Unit address */
    VAR( uint32, MCU_VAR ) MUAddr;
    /**< @brief Number of resource configured */
    VAR( uint16, MCU_VAR ) u16NoResourceConfigs;
    /**< @brief Pointer to resource configuration */
    P2CONST(Mcu_Scfw_ResourceConfigType, MCU_CONST, MCU_APPL_CONST ) pResourceInitConfig;
    /**< @brief Reset type control configuration */
    VAR(Mcu_Scfw_ResetType, MCU_VAR) Mcu_eResetType;
} Mcu_Scfw_ConfigType;

#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief   Definition of a resource's clock configuration
*
* @api
*/
typedef struct
{
    /**< @brief Resource's index */
    VAR(uint16, MCU_VAR)  u16RsrcId;
    /**< @brief Enable/Disable resource's clock */
    VAR(boolean, MCU_VAR) bClkEn;
    /**< @brief Clock's source */
    VAR(uint8, MCU_VAR)   u8ClkSrc;
    /**< @brief Clock's frequency */
    VAR(uint32, MCU_VAR)  u32ClkFreq;
} Mcu_Scfw_ClockConfigType;

#endif /* MCU_INIT_CLOCK == STD_ON */

/**
* @brief   Definition of a MCU mode section in the configuration structure.
* @details Specifies the system behaviour during the selected target mode.
*
*
* @api
*/
/** Power modes Configuration structure **/
typedef struct
{
    /**< @brief The ID for Power Mode configuration. */
    VAR( Mcu_ModeType, MCU_VAR ) Mcu_ModeConfigId;
    /**< @brief Power modes control configuration */
    VAR (Mcu_PowerModeType, MCU_VAR)  Mcu_ePowerMode;
    /**< @brief Stop Mode Option configuration */
    VAR(uint32, MCU_VAR)  Mcu_u32StopModeOption;
    /**< @brief Total of resources enabled */
    VAR( uint16, MCU_VAR ) Mcu_u16NoResourceConfigs;
    /**< @brief Pointer to mode configuration */
    P2CONST(Mcu_Scfw_ResourceConfigType, MCU_CONST, MCU_APPL_CONST ) Mcu_Scfw_pResourceConfig;
} Mcu_ModeConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_SCFW_TYPES_H */

/** @} */

