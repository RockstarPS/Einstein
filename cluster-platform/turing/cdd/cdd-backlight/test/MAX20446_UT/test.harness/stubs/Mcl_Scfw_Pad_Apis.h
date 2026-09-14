/**
*   @file    Mcl_Scfw_Pad_Apis.h
*   @version 4.0.0
*
*   @brief   AUTOSAR Mcl . Module for the Pad Control (PAD) service.
*   @details Pad configuration is managed by SC firmware. The Pad configuration
*   features supported by the SC firmware include:
*
*   - Configuring the Mux, input/output connection, and low-power Isolation
      Mode.
*   - Configuring the technology-specific Pad setting such as drive strength,
*     pullup/pulldown, etc.
*   - Configuring compensation for Pad Groups with dual voltage capability.
*
*   Pad functions fall into one of three categories. Generic functions are
*   common to all SoCs and all process technologies. SoC functions are raw
*   low-level functions. Technology-specific functions are specific to the
*   process technology.
*
*   The list of Pads is SoC specific.  Refer to the SoC [Pad List](@ref PADS)
*   for Valid Pad Values. Note that all Pads exist on a die but may or
*   may not be brought out by the specific package.  Mapping of Pads to
*   package pins/balls is documented in the associated Data Sheet. Some Pads
*   may not be brought out because the part (die+package) is defeatured and
*   some Pads may connect to the substRate in the package.
*
*   Some Pads (SCFW_P_COMP_*) that can be specified are not individual Pads
*   but are in fact Pad Groups. These Groups have additional configuration
*   that can be done using the sc_Pad_set_gp_28fdsoi_comp() function. More
*   info on these can be found in the associated Reference Manual.
*
*   Pads are managed as a Resource by the Resource Manager (RM).  They have
*   assigned owners and only the owners can Configure the Pads. Some of the
*   Pads are reserved for use by the SCFW itself and this can be overridden
*   with the implementation of board_Config_sc(). Additionally, Pads may
*   be assigned to various other partitions via the implementation of
*   board_system_Config().
*
*   Note Muxing two input Pads to the same IP functional signal will
*   result in undefined behavior.
*
*   @includedoc Pad/details.dox
*
*   @addtogroup MCL_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : eDMA
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

#ifndef MCL_SCFW_PAD_API_H
#define MCL_SCFW_PAD_API_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcl_Scfw_Types.h"
#include "Mcl_Scfw_Rm_Apis.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCFW_PAD_API_VENDOR_ID_H                    43
#define SCFW_PAD_API_AR_RELEASE_MAJOR_VERSION_H     4
#define SCFW_PAD_API_AR_RELEASE_MINOR_VERSION_H     2
#define SCFW_PAD_API_AR_RELEASE_REVISION_VERSION_H  2
#define SCFW_PAD_API_SW_MAJOR_VERSION_H             4
#define SCFW_PAD_API_SW_MINOR_VERSION_H             0
#define SCFW_PAD_API_SW_PATCH_VERSION_H             0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcl_Scfw_Types.h header file are of the same vendor */
#if (SCFW_PAD_API_VENDOR_ID_H != SCFW_TYPES_VENDOR_ID_H)
    #error "Mcl_Scfw_Pad_Apis.h and Mcl_Scfw_Types.h have different vendor id"
#endif
/* Check if current file and Mcl_Scfw_Types.h header file are of the same Software version */
#if ((SCFW_PAD_API_SW_MAJOR_VERSION_H != SCFW_TYPES_SW_MAJOR_VERSION_H ) || \
     (SCFW_PAD_API_SW_MINOR_VERSION_H != SCFW_TYPES_SW_MINOR_VERSION_H) || \
     (SCFW_PAD_API_SW_PATCH_VERSION_H != SCFW_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Mcl_Scfw_Pad_Apis.h and Mcl_Scfw_Types.h are different"
#endif
/* Check if current file and Dem header file are of the same Autosar version */
#if ((SCFW_PAD_API_AR_RELEASE_MAJOR_VERSION_H != SCFW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (SCFW_PAD_API_AR_RELEASE_MINOR_VERSION_H != SCFW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (SCFW_PAD_API_AR_RELEASE_REVISION_VERSION_H != SCFW_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Mcl_Scfw_Pad_Apis.h and Mcl_Scfw_Types.h are different"
#endif

/* Check if current file and Mcl_Scfw_Rm_Apis.h header file are of the same vendor */
#if (SCFW_PAD_API_VENDOR_ID_H != SCFW_RM_API_VENDOR_ID_H)
    #error "Mcl_Scfw_Pad_Apis.h and Mcl_Scfw_Rm_Apis.h have different vendor id"
#endif
/* Check if current file and Mcl_Scfw_Rm_Apis.h header file are of the same Software version */
#if ((SCFW_PAD_API_SW_MAJOR_VERSION_H != SCFW_RM_API_SW_MAJOR_VERSION_H ) || \
     (SCFW_PAD_API_SW_MINOR_VERSION_H != SCFW_RM_API_SW_MINOR_VERSION_H) || \
     (SCFW_PAD_API_SW_PATCH_VERSION_H != SCFW_RM_API_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Mcl_Scfw_Pad_Apis.h and Mcl_Scfw_Rm_Apis.h are different"
#endif
/* Check if current file and Dem header file are of the same Autosar version */
#if ((SCFW_PAD_API_AR_RELEASE_MAJOR_VERSION_H != SCFW_RM_API_AR_RELEASE_MAJOR_VERSION_H) || \
     (SCFW_PAD_API_AR_RELEASE_MINOR_VERSION_H != SCFW_RM_API_AR_RELEASE_MINOR_VERSION_H) || \
     (SCFW_PAD_API_AR_RELEASE_REVISION_VERSION_H != SCFW_RM_API_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Mcl_Scfw_Pad_Apis.h and Mcl_Scfw_Rm_Apis.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*!
 * @name Defines for Type widths
 */
/** @{ */
#define SCFW_PAD_MUX_W            3U    /*!< Width of Mux parameter */
/** @} */

/*!
 * @name Defines for Mcl_Scfw_PadConfigType
 */
/** @{ */
#define SCFW_PAD_CONFIG_NORMAL    0U    /*!< Normal */
#define SCFW_PAD_CONFIG_OD        1U    /*!< Open Drain */
#define SCFW_PAD_CONFIG_OD_IN     2U    /*!< Open Drain and input */
#define SCFW_PAD_CONFIG_OUT_IN    3U    /*!< Output and input */
/** @} */

/*!
 * @name Defines for Mcl_Scfw_PadIsoType
 */
/** @{ */
#define SCFW_PAD_ISO_OFF          0U    /*!< ISO latch is transparent */
#define SCFW_PAD_ISO_EARLY        1U    /*!< Follow EARLY_ISO */
#define SCFW_PAD_ISO_LATE         2U    /*!< Follow LATE_ISO */
#define SCFW_PAD_ISO_ON           3U    /*!< ISO latched Data is held */
/** @} */

/*!
 * @name Defines for Mcl_Scfw_PadWakeupType
 */
/** @{ */
#define SCFW_PAD_WAKEUP_OFF       0U    /*!< Off */
#define SCFW_PAD_WAKEUP_CLEAR     1U    /*!< Clears pending flag */
#define SCFW_PAD_WAKEUP_LOW_LVL   4U    /*!< Low level */
#define SCFW_PAD_WAKEUP_FALL_EDGE 5U    /*!< Falling edge */
#define SCFW_PAD_WAKEUP_RISE_EDGE 6U    /*!< Rising edge */
#define SCFW_PAD_WAKEUP_HIGH_LVL  7U    /*!< High-level */
/** @} */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*!
 * This Type is used to declare a Pad Config. It determines how the
 * output Data is driven, pull-up is controlled, and input signal is
 * connected. Normal and OD are typical and only connect the input
 * when the output is not driven.  The IN options are less common and
 * force an input connection even when driving the output.
 */
typedef uint8 Mcl_Scfw_PadConfigType;

/*!
 * This Type is used to declare a Pad low-power Isolation Config.
 * ISO_LATE is the most common setting. ISO_EARLY is only used when
 * an output Pad is directly determined by another input Pad. The
 * other two are only used when SW wants to directly control Isolation.
 */
typedef uint8 Mcl_Scfw_PadIsoType;

/*!
 * This Type is used to declare a Wakeup Mode of a Pad.
 */
typedef uint8 Mcl_Scfw_PadWakeupType;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


/*!
 * @name Generic Functions
 * @{
 */

/*!
 * This function Configures the Mux settings for a Pad. This includes
 * the signal Mux, Pad Config, and low-power Isolation Mode.
 *
 * @param[in]     Ipc         IPC handle
 * @param[in]     Pad         Pad to Configure
 * @param[in]     Mux         Mux setting
 * @param[in]     Config      Pad Config
 * @param[in]     Iso         low-power Isolation Mode
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 * Return errors:
 * - SCFW_PARM if arguments out of range or inValid,
 * - SCFW_ERR_NOACCESS if caller's partition is not the Pad owner
 *
 * Note Muxing two input Pads to the same IP functional signal will
 * result in undefined behavior.
 *
 * Refer to the SoC [Pad List](@ref PADS) for Valid Pad Values.
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_PadSetMux(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_PadType Pad,
    uint8 Mux, Mcl_Scfw_PadConfigType Config, Mcl_Scfw_PadIsoType Iso);


/*!
 * This function Configures the Mux settings for a Pad. This includes
 * the signal Mux, Pad Config, and low-power Isolation Mode.
 *
 * @param[in]     Ipc         IPC handle
 * @param[in]     Pad         Pad to Configure
 * @param[in]     Mux         Mux setting
 * @param[in]     Config      Pad Config
 * @param[in]     Iso         low-power Isolation Mode
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 * Return errors:
 * - SCFW_PARM if arguments out of range or inValid,
 * - SCFW_ERR_NOACCESS if caller's partition is not the Pad owner
 *
 * Note Muxing two input Pads to the same IP functional signal will
 * result in undefined behavior.
 *
 * Refer to the SoC [Pad List](@ref PADS) for Valid Pad Values.
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_PadGetMux(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_PadType Pad, uint8 *Mux,
    Mcl_Scfw_PadConfigType *Config, Mcl_Scfw_PadIsoType *Iso);
/*!
 * This function Configures the general purpose Pad control. This
 * is technology dependent and includes things like drive strength,
 * slew Rate, pull up/down, etc. Refer to the SoC Reference Manual
 * for bit field details.
 *
 * @param[in]     Ipc         IPC handle
 * @param[in]     Pad         Pad to Configure
 * @param[in]     Ctrl        control Value to set
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 * Return errors:
 * - SCFW_PARM if arguments out of range or inValid,
 * - SCFW_ERR_NOACCESS if caller's partition is not the Pad owner
 *
 * Refer to the SoC [Pad List](@ref PADS) for Valid Pad Values.
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_PadSetGp(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_PadType Pad, uint32 Ctrl);

/*!
 * This function gets the general purpose Pad control. This
 * is technology dependent and includes things like drive strength,
 * slew Rate, pull up/down, etc. Refer to the SoC Reference Manual
 * for bit field details.
 *
 * @param[in]     Ipc         IPC handle
 * @param[in]     Pad         Pad to query
 * @param[out]    Ctrl        pointer to return control Value
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 * Return errors:
 * - SCFW_PARM if arguments out of range or inValid,
 * - SCFW_ERR_NOACCESS if caller's partition is not the Pad owner
 *
 * Refer to the SoC [Pad List](@ref PADS) for Valid Pad Values.
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_PadGetGp(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_PadType Pad, uint32 *Ctrl);

/*!
 * This function Configures the Wakeup Mode of the Pad.
 *
 * @param[in]     Ipc         IPC handle
 * @param[in]     Pad         Pad to Configure
 * @param[in]     Wakeup      Wakeup to set
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 * Return errors:
 * - SCFW_PARM if arguments out of range or inValid,
 * - SCFW_ERR_NOACCESS if caller's partition is not the Pad owner
 *
 * Refer to the SoC [Pad List](@ref PADS) for Valid Pad Values.
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_PadSetWakeup(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_PadType Pad,
    Mcl_Scfw_PadWakeupType Wakeup);

/*!
 * This function gets the Wakeup Mode of a Pad.
 *
 * @param[in]     Ipc         IPC handle
 * @param[in]     Pad         Pad to query
 * @param[out]    Wakeup      pointer to return Wakeup
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 * Return errors:
 * - SCFW_PARM if arguments out of range or inValid,
 * - SCFW_ERR_NOACCESS if caller's partition is not the Pad owner
 *
 * Refer to the SoC [Pad List](@ref PADS) for Valid Pad Values.
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_PadGetWakeup(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_PadType Pad,
    Mcl_Scfw_PadWakeupType *Wakeup);
/*!
 * This function Configures a Pad.
 *
 * @param[in]     Ipc         IPC handle
 * @param[in]     Pad         Pad to Configure
 * @param[in]     Mux         Mux setting
 * @param[in]     Config      Pad Config
 * @param[in]     Iso         low-power Isolation Mode
 * @param[in]     Ctrl        control Value
 * @param[in]     Wakeup      Wakeup to set
 *
 * @see Mcl_Scfw_PadSetMux().
 * @see Mcl_Scfw_PadSetGp().
 *
 * Return errors:
 * - SCFW_PARM if arguments out of range or inValid,
 * - SCFW_ERR_NOACCESS if caller's partition is not the Pad owner
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 * Note Muxing two input Pads to the same IP functional signal will
 * result in undefined behavior.
 *
 * Refer to the SoC [Pad List](@ref PADS) for Valid Pad Values.
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_PadSetAll(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_PadType Pad, uint8 Mux,
    Mcl_Scfw_PadConfigType Config, Mcl_Scfw_PadIsoType Iso, uint32 Ctrl,
    Mcl_Scfw_PadWakeupType Wakeup);

/*!
 * This function gets a Pad's Config.
 *
 * @param[in]     Ipc         IPC handle
 * @param[in]     Pad         Pad to query
 * @param[out]    Mux         pointer to return Mux setting
 * @param[out]    Config      pointer to return Pad Config
 * @param[out]    Iso         pointer to return low-power Isolation Mode
 * @param[out]    Ctrl        pointer to return control Value
 * @param[out]    Wakeup      pointer to return Wakeup to set
 *
 * @see Mcl_Scfw_PadSetMux().
 * @see Mcl_Scfw_PadSetGp().
 *
 * Return errors:
 * - SCFW_PARM if arguments out of range or inValid,
 * - SCFW_ERR_NOACCESS if caller's partition is not the Pad owner
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 * Refer to the SoC [Pad List](@ref PADS) for Valid Pad Values.
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_PadGetAll(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_PadType Pad, uint8 *Mux,
    Mcl_Scfw_PadConfigType *Config, Mcl_Scfw_PadIsoType *Iso, uint32 *Ctrl,
    Mcl_Scfw_PadWakeupType *Wakeup);
    
/** @} */

/*!
 * @name SoC Specific Functions
 * @{
 */

/*!
 * This function Configures the settings for a Pad. This setting is SoC
 * specific.
 *
 * @param[in]     Ipc         IPC handle
 * @param[in]     Pad         Pad to Configure
 * @param[in]     Val         Value to set
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 * Return errors:
 * - SCFW_PARM if arguments out of range or inValid,
 * - SCFW_ERR_NOACCESS if caller's partition is not the Pad owner
 *
 * Refer to the SoC [Pad List](@ref PADS) for Valid Pad Values.
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_PadSet(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_PadType Pad, uint32 Val);

/*!
 * This function gets the settings for a Pad. This setting is SoC
 * specific.
 *
 * @param[in]     Ipc         IPC handle
 * @param[in]     Pad         Pad to query
 * @param[out]    Val         pointer to return setting
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 * Return errors:
 * - SCFW_PARM if arguments out of range or inValid,
 * - SCFW_ERR_NOACCESS if caller's partition is not the Pad owner
 *
 * Refer to the SoC [Pad List](@ref PADS) for Valid Pad Values.
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_PadGet(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_PadType Pad, uint32 *Val);

/*!
 * This function writes a configuration register. This setting is SoC
 * specific.
 *
 * @param[in]     Ipc         IPC handle
 * @param[in]     Pad         Pad to Configure
 * @param[in]     Val         Value to set
 *
 * Use to Configure various HSIC and NAND congiruation settings.
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 * Return errors:
 * - SCFW_PARM if arguments out of range or inValid,
 * - SCFW_ERR_NOACCESS if caller's partition is not the Pad owner
 *
 * Refer to the SoC [Pad List](@ref PADS) for Valid Pad Values.
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_PadConfig(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_PadType Pad, uint32 Val);
/** @} */

#ifdef __cplusplus
}
#endif
#endif /* MCL_SCFW_PAD_API_H */
/** @} */
