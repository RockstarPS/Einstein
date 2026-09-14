/**
*   @file    Port_SCFW_Types.h
*   @version 4.0.0
*
*   @brief   AUTOSAR Port - SCFW IP driver exported structures.
*   @details Interface between the high level driver (Autosar dependent) and the low level driver(platform dependent).
*
*   @addtogroup Iomuxc
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : SCFW,GPIO
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

#ifndef PORT_SCFW_TYPES_H
#define PORT_SCFW_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_SCFW_H_REF_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include'.
*          MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*
* @section PORT_SCFW_H_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*          This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section PORT_SCFW_H_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external identifiers.
*          The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section PORT_SCFW_H_REF_4
*          Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form
*          of pointer. The violation is FALSE: the quantity is unsigned.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not
*          rely on the significance of more than 31 characters. The used compilers use more than
*          31 chars for identifiers.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcl_Scfw_Pad_Apis.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief current file vendor, Autosar and API version numbers
*       The integration of incompatible files shall be avoided.
*
*/
#define PORT_SCFW_VENDOR_ID_TYPES_H                     43
/**
* @violates @ref PORT_SCFW_H_REF_3 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*/
#define PORT_SCFW_AR_RELEASE_MAJOR_VERSION_TYPES_H      4
/**
* @violates @ref PORT_SCFW_H_REF_3 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*/
#define PORT_SCFW_AR_RELEASE_MINOR_VERSION_TYPES_H      2
/**
* @violates @ref PORT_SCFW_H_REF_3 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*/
#define PORT_SCFW_AR_RELEASE_REVISION_VERSION_TYPES_H   2
#define PORT_SCFW_SW_MAJOR_VERSION_TYPES_H              4
#define PORT_SCFW_SW_MINOR_VERSION_TYPES_H              0
#define PORT_SCFW_SW_PATCH_VERSION_TYPES_H              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Port_SCFW_Type.h and Mcl_Scfw_Pad_Apis.h are of the same Autosar version */
    #if ((PORT_SCFW_AR_RELEASE_MAJOR_VERSION_TYPES_H    != SCFW_PAD_API_AR_RELEASE_MAJOR_VERSION_H) || \
         (PORT_SCFW_AR_RELEASE_MINOR_VERSION_TYPES_H    != SCFW_PAD_API_AR_RELEASE_MINOR_VERSION_H))
       #error "AutoSar Version Numbers of Port_SCFW_Type.h and Mcl_Scfw_Pad_Apis.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief Possible output status of a port pin.
*/
#define PORT_PIN_LEVEL_LOW_U8         ((uint8)0)    /**< @brief Sets port pin in '0' logic. */
#define PORT_PIN_LEVEL_HIGH_U8        ((uint8)1)    /**< @brief Sets port pin in '1' logic. */
#define PORT_PIN_LEVEL_NOTCHANGED_U8  ((uint8)2)    /**< @brief No level changes for the port pin. */

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief Data type for the symbolic name of a port pin.
* @details Shall cover all available port pins. The type should be chosen for the specific MCU
*         platform (best performance).
* @implements Port_PinType_typedef
*/
typedef uint16 Port_PinType;
/**
* @brief Possible directions of a port pin.
* @implements Port_PinDirectionType_enumeration
*/
typedef enum
{
    PORT_PIN_IN = 0,
    PORT_PIN_OUT
} Port_PinDirectionType;

/**
* @brief Different port pin modes.
* @details A port pin shall be configurable with a number of port pin modes (type Port_PinModeType).
*        The type Port_PinModeType shall be used with the function call Port_SetPinMode
* @implements Port_PinModeType_typedef
*/
typedef uint8 Port_PinModeType;

/**
* @brief Data type for the number, mentioned in platform spec, of a port pin.
*        It is the same with the index of the PCR/MSCR register.
* @details Shall cover all available port pins.
* 
*/
typedef uint16 Port_InternalPinIdType;

/**
* @brief   Single pin configuration.
* @details This structure contains all configuration parameters of a single pin
*          identified by @p IOMUXCPin.
*
* @api
*/
typedef struct
{
    VAR(uint16, PORT_VAR)                       u16Pin;     /**< @brief Pin Defined . Gets from the configuration, helps to locate the address of the register.  */
    VAR(uint8, PORT_VAR)                        u8Mux;      /**< @brief Mux of pin */
    VAR(Mcl_Scfw_PadConfigType, PORT_VAR)              PadCfg;     /**< @brief Pad config */
    VAR(Mcl_Scfw_PadIsoType, PORT_VAR)                 PadIso;     /**< @brief Pad isolation */
    VAR(Mcl_Scfw_PadWakeupType, PORT_VAR)              PadWakeUp;  /**< @brief Pad Wakeup capability */
    VAR(uint32, PORT_VAR)                       u32PadCtl;  /**< @brief Pad Control Register value. Gets from the configuration. */
    VAR(Port_PinDirectionType, PORT_VAR)        ePDDir;     /**< @brief Pad Data Direction */
    VAR(uint8, PORT_VAR)                        u8PinLevel; /**< @brief Out put level. Gets from the configuration*/
    VAR(boolean, PORT_VAR)                      bGPIO;      /**< @brief GPIO initial mode*/ 
    VAR(boolean, PORT_VAR)                      bDC;        /**< @brief Direction Changable. Gets from the configuration*/
    VAR(boolean, PORT_VAR)                      bMC;        /**< @brief Mode Changable. Gets from the configuration*/
} Port_SCFW_PinConfigType;

typedef struct
{
    VAR(uint8, PORT_VAR)                        u8Mux;      /**< @brief Mux of pin */
    VAR(Mcl_Scfw_PadConfigType, PORT_VAR)              PadCfg;     /**< @brief Pad config */
    VAR(Mcl_Scfw_PadIsoType, PORT_VAR)                 PadIso;     /**< @brief Pad isolation */
    VAR(Mcl_Scfw_PadWakeupType, PORT_VAR)              PadWakeUp;  /**< @brief Pad Wakeup capability */
    VAR(uint32, PORT_VAR)                       u32PadCtl;  /**< @brief Pad Control Register value. Gets from the configuration. */
    VAR(Port_PinDirectionType, PORT_VAR)        ePDDir;     /**< @brief Pad Data Direction */
    VAR(uint8, PORT_VAR)                        u8PinLevel; /**< @brief Out put level. Gets from the configuration*/
} Port_SCFW_NotUsedPinConfigType;



#ifdef __cplusplus
}
#endif

#endif /* PORT_SCFW_TYPES_H */

/** @} */
