/**
*   @file    Mcu_Cfg.h
*   @implements Mcu_Cfg.h_Artifact
*   @version 4.0.0
*   @brief   AUTOSAR Mcu - Mcu configuration header file.
*   @details This file contains mcu configuration defines.
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


#ifndef MCU_CFG_H
#define MCU_CFG_H

#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_CFG_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_CFG_H_REF_2
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to braced initialiser,
* a constant, a parenthesised expression, a type qualifier, a storage class specifier, or
* a do-while-zero construct
*
* @section Mcu_CFG_H_REF_3
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function
*
* @section Mcu_CFG_H_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_CFG_H_REF_5
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' Mcu_MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_CFG_H_REF_6
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
#include "Mcal.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_CFG_VENDOR_ID                        43
/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define MCU_CFG_AR_RELEASE_MAJOR_VERSION         4
/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define MCU_CFG_AR_RELEASE_MINOR_VERSION         2
/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define MCU_CFG_AR_RELEASE_REVISION_VERSION      2
#define MCU_CFG_SW_MAJOR_VERSION                 4
#define MCU_CFG_SW_MINOR_VERSION                 0
#define MCU_CFG_SW_PATCH_VERSION                 0
#define MCU_MODULE_ID                            101

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcal header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_CFG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_CFG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_Cfg.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
                                           DEFINES AND MACROS
==================================================================================================*/
/**
* @brief      Specifies the InstanceId of this module instance.
*/
#define MCU_INSTANCE_ID                 ((uint8)0x0U)

/**
@{
* @brief            Service Ids for MCU APIs.
*/
#define MCU_INIT_ID                     ((uint8)0x00U)
#define MCU_INITRAMSECTION_ID           ((uint8)0x01U)
#define MCU_INITCLOCK_ID                ((uint8)0x02U)
#define MCU_DISTRIBUTEPLLCLOCK_ID       ((uint8)0x03U)
#define MCU_GETPLLSTATUS_ID             ((uint8)0x04U)
#define MCU_GETRESETREASON_ID           ((uint8)0x05U)
#define MCU_GETRESETRAWVALUE_ID         ((uint8)0x06U)
#define MCU_PERFORMRESET_ID             ((uint8)0x07U)
#define MCU_SETMODE_ID                  ((uint8)0x08U)
#define MCU_GETVERSIONINFO_ID           ((uint8)0x09U)
#define MCU_GETRAMSTATE_ID              ((uint8)0x0AU)

#define MCU_GETPOWERDOMAIN_ID           ((uint8)0x0BU)
#define MCU_GETPERIPHERALSTATE_ID       ((uint8)0x0CU)
#define MCU_GETSYSTEMSTATE_ID           ((uint8)0x0DU)
#define MCU_GETPOWERMODESTATE_ID        ((uint8)0x0EU)
#define MCU_GETMEMCONFIG_ID             ((uint8)0x13U)
#define MCU_GETMIDRSTRUCTURE_ID         ((uint8)0x14U)
#define MCU_SSCMGETSTATUS_ID            ((uint8)0x15U)
#define MCU_SSCMGETUOPS_ID              ((uint8)0x16U)
#define MCU_DISABLECMU_ID               ((uint8)0x17U)
#define MCU_EMIOSCONFIGUREGPREN_ID      ((uint8)0x18U)
#define MCU_CLOCKGATECONTROL_ID         ((uint8)0x19U)
/**@}*/

/**
@{
* @brief            Development error values are of type uint8.
*                   The following errors and exceptions shall be detectable by the MCU module depending on its
*                   build version (development/production mode).
* @implements       Mcu_ErrorCodes_define
*
*/
#define MCU_E_PARAM_CONFIG              ((uint8)0x0AU)
#define MCU_E_PARAM_CLOCK               ((uint8)0x0BU)
#define MCU_E_PARAM_MODE                ((uint8)0x0CU)
#define MCU_E_PARAM_RAMSECTION          ((uint8)0x0DU)
#define MCU_E_PLL_NOT_LOCKED            ((uint8)0x0EU)
#define MCU_E_UNINIT                    ((uint8)0x0FU)
#define MCU_E_PARAM_POINTER             ((uint8)0x10U)
#define MCU_E_INIT_FAILED               ((uint8)0x11U)
#define MCU_E_SWITCH_MODE_INVALID       ((uint8)0x12U)
#define MCU_E_ALLREADY_INITIALIZED      ((uint8)0x13U)
#define MCU_E_TRANSITION                ((uint8)0x20U)
#define MCU_E_EMIOS_DEACTIVATED         ((uint8)0x21U)
#define MCU_E_CMU_INDEX_OUT_OF_RANGE    ((uint8)0x22U)
/**@}*/

/**
* @brief            Pre-processor switch for enabling the development error detection and reporting to the DET.
*                   The detection of development errors is configurable (ON / OFF) at pre-compile time.
*/
#define MCU_DEV_ERROR_DETECT   (STD_ON)


/**
* @brief            Pre-processor switch to enable/disable the API to read out the modules version information.
*/
#define MCU_VERSION_INFO_API   (STD_OFF)


/**
* @brief            Pre-processor switch to enable/disable the API Mcu_GetRamState.
*/
#define MCU_GET_RAM_STATE_API   (STD_OFF)


/**
* @brief            If this parameter is set to FALSE, the clock initialization has to be disabled from the MCU driver.
*/
#define MCU_INIT_CLOCK   (STD_ON)


/**
* @brief            This parameter shall be set True, if the H/W does not have a PLL or the PLL circuitry is enabled after the power on without S/W intervention.
*/
#define MCU_NO_PLL   (STD_ON)

/**
* @brief            The function Mcu_PerformReset is only available if the runtime parameter McuPerformResetApi is set to TRUE.
*/
#define MCU_PERFORM_RESET_API   (STD_ON)

/**
* @brief            Support for Low Power mode.
*                   If this parameter has been configured to 'TRUE', the function 'Mcu_SetMode()' shall not be impacted and behave as specified.
* @requirements     PR-MCAL-3184
*/
#define MCU_ENTER_LOW_POWER_MODE   (STD_ON)

/**
* @brief            The user callout reset is/isn't available (STD_ON/STD_OFF) - called by MCU right before Mcu_PerformReset().
*/
#define MCU_RESET_CALLOUT_USED   (STD_OFF)


/**
* @brief            Enable the usage of Non-Autosar API Mcu_GetPeripheral_State() for getting infos about peripheral state from MC_ME module.
*/
#define MCU_GET_PERIPH_STATE_API   (STD_OFF)

/**
* @brief            Enable the usage of Non-Autosar API Mcu_GetSystem_State() for getting infos system platform configuration.
*/
#define MCU_GET_SYSTEM_STATE_API   (STD_OFF)

/**
* @brief            Enable the usage of Non-Autosar API Mcu_GetPowerMode_State() for getting infos system platform configuration.
*/
#define MCU_POWERMODE_STATE_API   (STD_OFF)

/**
* @brief            Enable the usage of Non-Autosar API Mcu_GetPowerDomain_Status. Get PMU state: operable or not.
*/
#define MCU_GET_POWER_DOMAIN_API   (STD_OFF)


/**
* @brief            Enable the usage of Non-Autosar API Mcu_SscmGetMemConfig(). Get SSCM_MEMCONFIG.
*/
#define MCU_GET_MEM_CONFIG_API   (STD_OFF)

/**
* @brief            Enable the usage of Non-Autosar API Mcu_SscmGetStatus(). Get SSCM_STATUS.
*/
#define MCU_SSCM_GET_STATUS_API   (STD_OFF)


/**
* @brief            Enable the usage of Non-Autosar API  Mcu_GetMidrStructure(). Returns .
*/
#define MCU_GET_MIDR_API    (STD_OFF)


/**
* @brief            Enable/Disable the API for reporting the Dem Error.
*/
#define MCU_DISABLE_DEM_REPORT_ERROR_STATUS     (STD_ON)


/**
* @brief           This define controls the availability of the Low Power Subsystem
*/
#define MCU_LPU_SUPPORT   (STD_OFF)

/**
* @brief            Maximum number of MCU Clock configurations.
*/
#define MCU_MAX_CLKCONFIGS   ((uint32)1U)


/**
* @brief            Maximum number of MCU Mode configurations.
*/
#define MCU_MAX_MODECONFIGS   ((uint32)2U)


/**
* @brief            Maximum number of MCU Ram configurations.
*/
#define MCU_MAX_RAMCONFIGS   ((uint32)1U)



/**
* @brief            Maximum number of MCU Clock Gate configurations.
*/
#define MCU_MAX_CLKGATECONFIGS   ((uint32)0U)
/**
* @brief            Enable/Disable the API for Control Clock gate (LPCG).
*/
#define MCU_CLOCK_GATE_CONTROL  (STD_OFF)

/**
* @brief            Post-build Support ON.
*/
#define MCU_PRECOMPILE_SUPPORT   (STD_OFF)


    
/**
* @brief            Post-Build structures from Mcu_PBcfg.c file.
*/
/** @violates @ref Mcu_CFG_H_REF_2 MISRA 2004 Required Rule 19.4, This is not a macro, it can not be included in () or {} */
#define MCU_CONF_PB \
 extern CONST(Mcu_ConfigType, MCU_CONST) Mcu_Config;

/**
* @brief  The function Mcu_GetResetRawValue shall return an implementation specific value which does
*         not correspond to a valid value of the reset status register and is not equal to 0 if this
*         function is called prior to calling of the function Mcu_Init, and if supported by the
*         hardware.
*
*/
#define MCU_RAW_RESET_DEFAULT      ((uint32)0xFFFFFFFFUL)

/**
* @brief Number of resource group using to manage enable/disable status of resource
*/
#define MCU_NO_RESOURCE_GROUP_U8    (17U)

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief            The Mcu_ModeType specifies the identification (ID) for a MCU mode, configured via configuration structure.
* @details          The type shall be uint8, uint16 or uint32.
*
* @implements     Mcu_ModeType_typedef
*
*/
//typedef uint32 Mcu_ModeType;


/**
* @brief            The Mcu_RamSectionType specifies the identification (ID) for a RAM section, configured via the configuration structure.
*                   The type shall be uint8, uint16 or uint32, based on best performance.
* @implements Mcu_RamSectionType_typedef
*/
//typedef uint32 Mcu_RamSectionType;

/**
* @brief            The Mcu_RamIndexType specifies the variable for indexing RAM sections.
*                   The type shall be uint8, uint16 or uint32, based on best performance.
*
*/
//typedef uint32 Mcu_RamIndexType;

/**
* @brief            The Mcu_RamSizeType specifies the RAM section size.
*                   The type shall be uint8, uint16 or uint32, based on best performance.
*
*/
//typedef uint32 Mcu_RamSizeType;

#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief          Defines the identification (ID) for clock setting configured via the configuration structure.
* @details        The type shall be uint8, uint16 or uint32, depending on uC platform.
*
* @implements Mcu_ClockType_typedef
*/
//typedef uint32 Mcu_ClockType;
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#if (MCU_CLOCK_GATE_CONTROL == STD_ON)
/**
* @brief          Defines the identification (ID) for clock gate setting configured via the configuration structure.
* @details        The type shall be uint8, uint16 or uint32, depending on uC platform.
*
*/
typedef uint32 Mcu_ClockGateType;
#endif /* (MCU_CLOCK_GATE_CONTROL == STD_ON) */


/**
* @brief            Definition of a RAM section within the configuration structure.
*                   The definitions for each RAM section within the structure Mcu_ConfigType shall contain:
*                   - RAM section base address
*                   - Section size
*                   - Data pre-setting to be initialized
*
*/

// typedef struct
// {
//     VAR( Mcu_RamSectionType, MCU_VAR) Mcu_RamSectorId;   /**< @brief The ID for Ram Sector configuration. */
//     VAR( uint8, MCU_VAR) (*Mcu_pu8RamBaseAddr)[1U];   /**< @brief RAM section base address. */
//     VAR( Mcu_RamSizeType, MCU_VAR) Mcu_RamSize;   /**< @brief RAM section size. */
//     VAR( uint8, MCU_VAR) Mcu_u8RamDefaultValue;   /**< @brief RAM default value for initialization. */
// } Mcu_RamConfigType;

/**
* @brief            The type Mcu_RawResetType specifies the reset reason in raw register format, read from a reset status register.
* @details          The type shall be uint8, uint16 or uint32 based on best performance.
*
* @implements Mcu_RawResetType_typedef
*
*/
typedef uint32 Mcu_RawResetType;   /**< @brief Destructive and Functional Reset Events Log. */

/**
* @brief            DEM error reporting configuration.
* @details          This structure contains information DEM error reporting
*/

typedef struct
{
    VAR( Mcal_DemErrorType, MCU_VAR) Mcu_E_ClockFailureCfg;
    VAR( Mcal_DemErrorType, MCU_VAR) Mcu_E_ScfwSetupFailureCfg;
    VAR( Mcal_DemErrorType, MCU_VAR) Mcu_E_ResourceNotAssigned;
    VAR( Mcal_DemErrorType, MCU_VAR) Mcu_E_ClockVerifyFailureCfg;
} Mcu_DemConfigType;

/*==================================================================================================
                                       CONSTANTS
==================================================================================================*/
/**
* @brief            Create defines with the IDs assigned to Mcu Clock configurations.
*                   These IDs will be transmitted as input parameters for Mcu_InitClock() API.
*/

/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define McuClockSettingConfig_0   ((Mcu_ClockType)0U)
/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define McuConf_McuClockSettingConfig_McuClockSettingConfig_0   ((Mcu_ClockType)0U)


/**
* @brief            Create defines with the IDs assigned to Mcu Mode configurations.
*                   These IDs will be transmitted as input parameters for Mcu_SetMode() API.
*/

/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define McuModeSettingConf_POWER_ON   ((Mcu_ModeType)0U)
/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define McuConf_McuModeSettingConf_McuModeSettingConf_POWER_ON   ((Mcu_ModeType)0U)

/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define McuModeSettingConf_LOW_POWER   ((Mcu_ModeType)1U)
/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define McuConf_McuModeSettingConf_McuModeSettingConf_LOW_POWER   ((Mcu_ModeType)1U)


/**
* @brief            Create defines with the IDs assigned to Mcu RAM Section configurations.
*                   These IDs will be transmitted as input parameters for Mcu_InitRamSection() API.
*/

/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define McuRamSectorSettingConf_0   ((Mcu_RamSectionType)0U)
/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define McuConf_McuRamSectorSettingConf_McuRamSectorSettingConf_0   ((Mcu_RamSectionType)0U)


/**
* @brief            Create defines with the IDs assigned to Mcu Reset reason configurations.
*                   These IDs will be transmitted as output parameters for Mcu_GetResetReason() API.
*/


/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define McuConf_McuResetReasonConf_MCU_POWER_ON_RESET   MCU_POWER_ON_RESET


/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define McuConf_McuResetReasonConf_MCU_WARM_RESET   MCU_WARM_RESET


/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define McuConf_McuResetReasonConf_MCU_SOFTWARE_RESET   MCU_SOFTWARE_RESET


/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define McuConf_McuResetReasonConf_MCU_WATCHDOG_RESET   MCU_WATCHDOG_RESET


/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define McuConf_McuResetReasonConf_MCU_LOCKUP_RESET   MCU_LOCKUP_RESET


/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define McuConf_McuResetReasonConf_MCU_TAMPER_RESET   MCU_TAMPER_RESET


/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define McuConf_McuResetReasonConf_MCU_TEMP_RESET   MCU_TEMP_RESET


/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define McuConf_McuResetReasonConf_MCU_LOW_VOLTAGE_RESET   MCU_LOW_VOLTAGE_RESET


/** @violates @ref Mcu_CFG_H_REF_4 MISRA 2004 Required Rule 1.4 */
#define McuConf_McuResetReasonConf_MCU_RESET_UNDEFINED   MCU_RESET_UNDEFINED


/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/**
* @brief          Lock status of the PLL.
* @details        This is a status value returned by the function Mcu_GettPllStatus
*                 of the MCU module.
*
* @implements     Mcu_PllStatusType_enumeration
*
*/
// typedef enum
// {
//     /**
//      * @brief   PLL is locked.
//      */
//     MCU_PLL_LOCKED = 0,
//     /**
//      * @brief   PLL is unlocked.
//      */
//     MCU_PLL_UNLOCKED,
//      /**
//      * @brief   PLL Status is unknown.
//      */
//     MCU_PLL_STATUS_UNDEFINED
// } Mcu_PllStatusType;

/**
* @brief            The type Mcu_ResetType, represents the different reset that a specified MCU can have.
* @details          The MCU module shall provide at least the values MCU_POWER_ON_RESET and MCU_RESET_UNDEFINED for the enumeration Mcu_ResetType.
*
* @implements Mcu_ResetType_enumeration
*/
// typedef enum
// {
//     MCU_POWER_ON_RESET =0,
//     MCU_JTAG_RESET,
//     MCU_SOFTWARE_RESET,
//     MCU_WATCHDOG_RESET,
//     MCU_LOCKUP_RESET,
//     MCU_SNVS_RESET,
//     MCU_TEMP_RESET,
//     MCU_MSI_RESET,
//     MCU_UECC_RESET,
//     MCU_SCFW_WDOG_RESET,
//     MCU_ROM_WDOG_RESET,
//     MCU_SECO_RESET,
//     MCU_SCFW_FAULT_RESET,
//     MCU_RESET_UNDEFINED
// } Mcu_ResetType;

#if (MCU_GET_RAM_STATE_API == STD_ON)
/**
* @brief            Ram State of the microcontroller.
* @details          This is the Ram State data type returned by the function Mcu_GetRamState() of the Mcu module.
* @implements       Mcu_RamStateType_enumeration
*/
typedef enum
{
    MCU_RAMSTATE_INVALID = 0U,   /**< @brief RAM content is not valid or unknown (default). */
    MCU_RAMSTATE_VALID   /**< @brief RAM content is valid. */

} Mcu_RamStateType;
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Mcu_CFG_H_REF_5 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include' Mcu_MemMap.h*/
/** @violates @ref Mcu_CFG_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"
/**
* @brief            Local copy of the pointer to the configuration data
*/
/** @violates @ref Mcu_CFG_H_REF_3 MISRA 2004 Required Rule 8.7, these object are used trough the entire MCU code*/
extern P2CONST(Mcu_DemConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_pDemCfgPtr;

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Mcu_CFG_H_REF_5 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include' Mcu_MemMap.h*/
/** @violates @ref Mcu_CFG_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"
#endif

#define MCU_START_SEC_CONST_UNSPECIFIED
/** @violates @ref Mcu_CFG_H_REF_5 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include' Mcu_MemMap.h*/
/** @violates @ref Mcu_CFG_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"


#define MCU_STOP_SEC_CONST_UNSPECIFIED
/** @violates @ref Mcu_CFG_H_REF_5 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include' Mcu_MemMap.h*/
/** @violates @ref Mcu_CFG_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONST_UNSPECIFIED
/** @violates @ref Mcu_CFG_H_REF_5 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include' Mcu_MemMap.h*/
/** @violates @ref Mcu_CFG_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"
extern CONST( Mcu_DemConfigType, MCU_CONST) Mcu_Dem_Config;

#define MCU_STOP_SEC_CONST_UNSPECIFIED
/** @violates @ref Mcu_CFG_H_REF_5 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include' Mcu_MemMap.h*/
/** @violates @ref Mcu_CFG_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* #ifndef MCU_CFG_H */

/** @} */

