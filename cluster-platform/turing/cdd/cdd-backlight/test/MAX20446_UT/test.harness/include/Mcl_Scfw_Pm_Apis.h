/**
*   @file    Mcl_Scfw_Pm_Apis.h
*   @version 4.0.0
*
*   @brief   AUTOSAR Mcl . Module for the Power Management (PM) service.
*   @details Header file containing the public API for the System Controller (SC)
*   Power Management (PM) function. This includes functions for power state
*   control, clock control, reset control, and wake-up event control.
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

#ifndef MCL_SCFW_PM_API_H
#define MCL_SCFW_PM_API_H

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
#include "Mcl_Scfw_Rm_Apis.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCFW_PM_API_VENDOR_ID_H                    43
#define SCFW_PM_API_AR_RELEASE_MAJOR_VERSION_H     4
#define SCFW_PM_API_AR_RELEASE_MINOR_VERSION_H     2
#define SCFW_PM_API_AR_RELEASE_REVISION_VERSION_H  2
#define SCFW_PM_API_SW_MAJOR_VERSION_H             4
#define SCFW_PM_API_SW_MINOR_VERSION_H             0
#define SCFW_PM_API_SW_PATCH_VERSION_H             0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcl_Scfw_Rm_Apis.h header file are of the same vendor */
#if (SCFW_PM_API_VENDOR_ID_H != SCFW_RM_API_VENDOR_ID_H)
    #error "Mcl_Scfw_Pm_Apis.h and Mcl_Scfw_Rm_Apis.h have different vendor id"
#endif
/* Check if current file and Mcl_Scfw_Rm_Apis.h header file are of the same Software version */
#if ((SCFW_PM_API_SW_MAJOR_VERSION_H != SCFW_RM_API_SW_MAJOR_VERSION_H ) || \
     (SCFW_PM_API_SW_MINOR_VERSION_H != SCFW_RM_API_SW_MINOR_VERSION_H) || \
     (SCFW_PM_API_SW_PATCH_VERSION_H != SCFW_RM_API_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Mcl_Scfw_Pm_Apis.h and Mcl_Scfw_Rm_Apis.h are different"
#endif
/* Check if current file and Dem header file are of the same Autosar version */
#if ((SCFW_PM_API_AR_RELEASE_MAJOR_VERSION_H != SCFW_RM_API_AR_RELEASE_MAJOR_VERSION_H) || \
     (SCFW_PM_API_AR_RELEASE_MINOR_VERSION_H != SCFW_RM_API_AR_RELEASE_MINOR_VERSION_H) || \
     (SCFW_PM_API_AR_RELEASE_REVISION_VERSION_H != SCFW_RM_API_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Mcl_Scfw_Pm_Apis.h and Mcl_Scfw_Rm_Apis.h are different"
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
#define SCFW_PM_POWER_MODE_W      2U      /*!< Width of Mcl_Scfw_PmPowerModeType */
#define SCFW_PM_CLOCK_MODE_W      3U      /*!< Width of Mcl_Scfw_PmClockMode */
#define SCFW_PM_RESET_TYPE_W      2U      /*!< Width of Mcl_Scfw_PmResetType */
#define SCFW_PM_RESET_REASON_W    4U      /*!< Width of Mcl_Scfw_PmResetReasonType */
/** @} */

/*!
 * @name Defines for clock indexes (Mcl_Scfw_PmClkType)
 */

/*!
 * @name Defines for ALL parameters
 */
/** @{ */
#define SCFW_PM_CLK_ALL   ((Mcl_Scfw_PmClkType) UINT8_MAX)   /*!< All clocks */
/** @} */

/*!
 * @name Defines for Mcl_Scfw_PmPowerModeType
 */
/** @{ */
#define SCFW_PM_PW_MODE_OFF       0U      /*!< Power off */
#define SCFW_PM_PW_MODE_STBY      1U      /*!< Power in standby */
#define SCFW_PM_PW_MODE_LP        2U      /*!< Power in low-power */
#define SCFW_PM_PW_MODE_ON        3U      /*!< Power on */
/** @} */

/*!
 * @name Defines for Mcl_Scfw_PmClkType
 */
/** @{ */
#define SCFW_PM_CLK_SLV_BUS       0U      /*!< Slave bus clock */
#define SCFW_PM_CLK_MST_BUS       1U      /*!< Master bus clock */
#define SCFW_PM_CLK_PER           2U      /*!< Peripheral clock */
#define SCFW_PM_CLK_PHY           3U      /*!< Phy clock */
#define SCFW_PM_CLK_MISC          4U      /*!< Misc clock */
#define SCFW_PM_CLK_MISC0         0U      /*!< Misc 0 clock */
#define SCFW_PM_CLK_MISC1         1U      /*!< Misc 1 clock */
#define SCFW_PM_CLK_MISC2         2U      /*!< Misc 2 clock */
#define SCFW_PM_CLK_MISC3         3U      /*!< Misc 3 clock */
#define SCFW_PM_CLK_MISC4         4U      /*!< Misc 4 clock */
#define SCFW_PM_CLK_CPU           2U      /*!< CPU clock */
#define SCFW_PM_CLK_PLL           4U      /*!< PLL */
#define SCFW_PM_CLK_BYPASS        4U      /*!< Bypass clock */
/** @} */

/*!
 * @name Defines for Mcl_Scfw_PmResetType
 */
/** @{ */
#define SCFW_PM_RESET_TYPE_COLD          0U    /*!< Cold reset */
#define SCFW_PM_RESET_TYPE_WARM          1U    /*!< Warm reset */
#define SCFW_PM_RESET_TYPE_BOARD         2U    /*!< Board reset */
/** @} */

/*!
 * @name Defines for Mcl_Scfw_PmResetReasonType
 */
/** @{ */
#define SCFW_PM_RESET_REASON_POR         0U    /*!< Power on reset */
#define SCFW_PM_RESET_REASON_JTAG        1U    /*!< JTAG reset */
#define SCFW_PM_RESET_REASON_SW          2U    /*!< Software reset */
#define SCFW_PM_RESET_REASON_WDOG        3U    /*!< Partition watchdog reset */
#define SCFW_PM_RESET_REASON_LOCKUP      4U    /*!< SCU Lockup reset */
#define SCFW_PM_RESET_REASON_SNVS        5U    /*!< SNVS reset */
#define SCFW_PM_RESET_REASON_TEMP        6U    /*!< Temp panic reset */
#define SCFW_PM_RESET_REASON_MSI         7U    /*!< MSI reset */
#define SCFW_PM_RESET_REASON_UECC        8U    /*!< ECC reset */
#define SCFW_PM_RESET_REASON_SCFW_WDOG   9U    /*!< SCFW watchdog reset */
#define SCFW_PM_RESET_REASON_ROM_WDOG    10U   /*!< SCU ROM watchdog reset */
#define SCFW_PM_RESET_REASON_SECO        11U   /*!< SECO reset */
#define SCFW_PM_RESET_REASON_SCFW_FAULT  12U   /*!< SCFW fault reset */
#define SCFW_PM_RESET_REASON_V2X_DEBUG   13U   /*!< V2X debug switch */
/** @} */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*!
 * This Type is used to declare a power Mode. Note Resources only use
 * SCFW_PM_PW_MODE_OFF and SCFW_PM_PW_MODE_ON. The other Modes are used only
 * as system power Modes.
 */
typedef uint8 Mcl_Scfw_PmPowerModeType;

/*!
 * This Type is used to declare a clock.
 */
typedef uint8 Mcl_Scfw_PmClkType;

/*!
 * This Type is used to declare clock Rates.
 */
typedef uint32 Mcl_Scfw_PmClockRateType;

/*!
 * This Type is used to declare a desired reset Type.
 */
typedef uint8 Mcl_Scfw_PmResetType;

/*!
 * This Type is used to declare a Reason for a reset.
 */
typedef uint8 Mcl_Scfw_PmResetReasonType;

/*!
 * This Type is used to declare the clock parent.
 */
typedef uint8 Mcl_Scfw_PmClkParentType;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/* Functions */

/*!
 * @name Power Functions
 * @{
 */

/*!
 * This function sets the power Mode of a Resource.
 *
 * @param[in]     Ipc         IPC handle
 * @param[in]     Resource    ID of the Resource
 * @param[in]     Mode        power Mode to apply
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 * Return errors:
 * - SCFW_ERR_PARM if inValid Resource or Mode,
 * - SCFW_ERR_PARM if Resource is the MU used to make the call,
 * - SCFW_ERR_NOACCESS if caller's partition is not the Resource owner
 *   or parent of the owner
 *
 * Resources must be at SCFW_PM_PW_MODE_LP Mode or higher to access them,
 * otherwise the master will get a bus error or hang.
 *
 * Note some Resources are still not accessible even when powered up if bus
 * transActions go through a fabric not powered up. Examples of this are
 * Resources in display and caPture subsystems which require the display
 * controller or the imaging subsystem to be powered up first.
 *
 * Note that Resources are Grouped into power domains by the underlying
 * hardware. If any Resource in the domain is on, the entire power domain
 * will be on. Other power domains required to access the Resource will
 * also be turned on. Bus clocks required to access the peripheral will be
 * turned on. Refer to the SoC RM for more info on power domains and access
 * infrastructure (bus fabrics, clock domains, etc.).
 *
 * When the Resource transitions to the SCFW_PM_PW_MODE_OFF, all of the settings,
 * including clock Rate, will be lost; immaterial of the state of other
 * Resources in the same power domain.
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_PmSetResourcePowerMode(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_RsrcType Resource,
    Mcl_Scfw_PmPowerModeType Mode);
/** @} */

/*!
 * @name Clock/PLL Functions
 * @{
 */

/*!
 * This function gets the Rate of a Resource's clock/PLL.
 *
 * @param[in]      Ipc         IPC handle
 * @param[in]      Resource    ID of the Resource
 * @param[in]      Clk         clock/PLL to affect
 * @param[out]     Rate        pointer to return rate
 *
 * Note the actual Rate is returned in \a Rate.
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 * Return errors:
 * - SCFW_ERR_PARM if inValid Resource or clock/PLL,
 * - SCFW_ERR_NOACCESS if caller's partition is not the Resource owner
 *   or parent of the owner,
 * - SCFW_ERR_UNAVAILABLE if clock/PLL not applicable to this Resource,
 * - SCFW_ERR_LOCKED if Rate Locked (usually because shared clock/PLL)
 *
 * Refer to the [Clock List](@ref CLOCKS) for Valid clock/PLL Values.
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_PmGetClockRate(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_RsrcType Resource, Mcl_Scfw_PmClkType Clk,
    Mcl_Scfw_PmClockRateType *Rate);
 /*!
 * This function sets the Rate of a Resource's clock/PLL.
 *
 * @param[in]      Ipc         IPC handle
 * @param[in]      Resource    ID of the Resource
 * @param[in]      Clk         clock/PLL to affect
 * @param[in,out]  Rate        pointer to Rate
 *
 * Note the actual Rate is returned in \a Rate.
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 * Return errors:
 * - SCFW_ERR_PARM if inValid Resource or clock/PLL,
 * - SCFW_ERR_NOACCESS if caller's partition is not the Resource owner
 *   or parent of the owner,
 * - SCFW_ERR_UNAVAILABLE if clock/PLL not applicable to this Resource,
 * - SCFW_ERR_LOCKED if Rate Locked (usually because shared clock/PLL)
 *
 * Refer to the [Clock List](@ref CLOCKS) for Valid clock/PLL Values.
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_PmSetClockRate(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_RsrcType Resource,
    Mcl_Scfw_PmClkType Clk, Mcl_Scfw_PmClockRateType *Rate);
/*!
 * This function Enables/disables a Resource's clock.
 *
 * @param[in]     Ipc         IPC handle
 * @param[in]     Resource    ID of the Resource
 * @param[in]     Clk         clock to affect
 * @param[in]     Enable      Enable if SCFW_TRUE; otherwise disabled
 * @param[in]     Autog       HW auto clock gating
 *
 * If \a Resource is SCFW_R_ALL then all Resources owned will be affected.
 * No error will be returned.
 *
 * If \a Clk is SCFW_PM_CLK_ALL, then an error will be returned if any
 * of the available clocks returns an error.
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 * Return errors:
 * - SCFW_ERR_PARM if inValid Resource or clock,
 * - SCFW_ERR_NOACCESS if caller's partition is not the Resource owner
 *   or parent (with Grant) of the owner,
 * - SCFW_ERR_UNAVAILABLE if clock not applicable to this Resource
 * - SCFW_ERR_NOPOWER if Resource not powered
 *
 * Refer to the [Clock List](@ref CLOCKS) for Valid clock Values.
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_PmClockEnable(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_RsrcType Resource,
    Mcl_Scfw_PmClkType Clk, Mcl_Scfw_BoolType Enable, Mcl_Scfw_BoolType Autog);

/** @} */

/*!
 * @name Reset Functions
 * @{
 */

/*!
 * This function is used to reset the system. Only the owner of the
 * SCFW_R_SYSTEM Resource or a partition with access Permissions to
 * SCFW_R_SYSTEM can do this.
 *
 * @param[in]     Ipc         IPC handle
 * @param[in]     Type        reset Type
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 *
 * Return errors:
 * - SCFW_ERR_PARM if inValid Type,
 * - SCFW_ERR_NOACCESS if caller cannot access SCFW_R_SYSTEM
 *
 * If this function returns, then the reset did not occur due to an
 * inValid parameter.
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_PmReset(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_PmResetType Type);

/*!
 * This function gets a caller's reset Reason.
 *
 * @param[in]     Ipc         IPC handle
 * @param[out]    Reason      pointer to return the reset Reason
 *
 * This function returns the Reason a partition was reset. If the Reason
 * is POR, then the system reset Reason will be returned.
 *
 * Note depending on the connection of the WDOG_OUT signal and the OTP
 * programming of the PMIC, some resets may trigger a system POR
 * and the original Reason will be lost.
 *
 * @return Returns an error code (SCFW_ERR_NONE = success).
 */
FUNC(Mcl_Scfw_ErrType, MCL_CODE) Mcl_Scfw_PmResetReasons(Mcl_Scfw_IpcType Ipc, Mcl_Scfw_PmResetReasonType *Reason);

/** @} */

#ifdef __cplusplus
}
#endif
#endif /* SCFW_PM_API_H */
/** @} */
