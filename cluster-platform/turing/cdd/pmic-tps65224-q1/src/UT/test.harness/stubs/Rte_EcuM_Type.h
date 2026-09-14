/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_EcuM_Type.h
 *        Config:  iMX8.dpa
 *   ECU-Project:  METER
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700905 for Visteon Electronics Germany GmbH
 *
 *   Description:  Application types header file for SW-C <EcuM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_ECUM_TYPE_H
# define _RTE_ECUM_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef ECUM_BOOT_TARGET_APP
#   define ECUM_BOOT_TARGET_APP (0U)
#  endif

#  ifndef ECUM_BOOT_TARGET_OEM_BOOTLOADER
#   define ECUM_BOOT_TARGET_OEM_BOOTLOADER (1U)
#  endif

#  ifndef ECUM_BOOT_TARGET_SYS_BOOTLOADER
#   define ECUM_BOOT_TARGET_SYS_BOOTLOADER (2U)
#  endif

#  ifndef EcuMConf_EcuMResetMode_ECUM_RESET_MCU
#   define EcuMConf_EcuMResetMode_ECUM_RESET_MCU (0U)
#  endif

#  ifndef EcuMConf_EcuMResetMode_ECUM_RESET_WDG
#   define EcuMConf_EcuMResetMode_ECUM_RESET_WDG (1U)
#  endif

#  ifndef EcuMConf_EcuMResetMode_ECUM_RESET_IO
#   define EcuMConf_EcuMResetMode_ECUM_RESET_IO (2U)
#  endif

#  ifndef EcuMConf_EcuMResetMode_ECUM_RESET_WAKEUP
#   define EcuMConf_EcuMResetMode_ECUM_RESET_WAKEUP (3U)
#  endif

#  ifndef EcuMConf_EcuMSleepMode_EcuMSleepMode
#   define EcuMConf_EcuMSleepMode_EcuMSleepMode (0U)
#  endif

#  ifndef EcuMConf_EcuMShutdownCause_ECUM_CAUSE_UNKNOWN
#   define EcuMConf_EcuMShutdownCause_ECUM_CAUSE_UNKNOWN (0U)
#  endif

#  ifndef EcuMConf_EcuMShutdownCause_ECUM_CAUSE_ECU_STATE
#   define EcuMConf_EcuMShutdownCause_ECUM_CAUSE_ECU_STATE (1U)
#  endif

#  ifndef EcuMConf_EcuMShutdownCause_ECUM_CAUSE_WDGM
#   define EcuMConf_EcuMShutdownCause_ECUM_CAUSE_WDGM (2U)
#  endif

#  ifndef EcuMConf_EcuMShutdownCause_ECUM_CAUSE_DCM
#   define EcuMConf_EcuMShutdownCause_ECUM_CAUSE_DCM (3U)
#  endif

#  ifndef ECUM_STATE_SLEEP
#   define ECUM_STATE_SLEEP (80U)
#  endif

#  ifndef ECUM_STATE_OFF
#   define ECUM_STATE_OFF (128U)
#  endif

#  ifndef ECUM_STATE_RESET
#   define ECUM_STATE_RESET (144U)
#  endif

#  ifndef EcuMConf_EcuMFixedUserConfig_EcuMFixedUserConfig
#   define EcuMConf_EcuMFixedUserConfig_EcuMFixedUserConfig (0U)
#  endif

# endif /* RTE_CORE */


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_EcuM_Mode
#  define RTE_MODETYPE_EcuM_Mode
typedef uint8 Rte_ModeType_EcuM_Mode;
# endif

# ifndef RTE_MODE_EcuM_Mode_POST_RUN
#  define RTE_MODE_EcuM_Mode_POST_RUN (0U)
# endif
# ifndef RTE_MODE_EcuM_Mode_RUN
#  define RTE_MODE_EcuM_Mode_RUN (1U)
# endif
# ifndef RTE_MODE_EcuM_Mode_SHUTDOWN
#  define RTE_MODE_EcuM_Mode_SHUTDOWN (2U)
# endif
# ifndef RTE_MODE_EcuM_Mode_SLEEP
#  define RTE_MODE_EcuM_Mode_SLEEP (3U)
# endif
# ifndef RTE_MODE_EcuM_Mode_STARTUP
#  define RTE_MODE_EcuM_Mode_STARTUP (4U)
# endif
# ifndef RTE_MODE_EcuM_Mode_WAKE_SLEEP
#  define RTE_MODE_EcuM_Mode_WAKE_SLEEP (5U)
# endif
# ifndef RTE_TRANSITION_EcuM_Mode
#  define RTE_TRANSITION_EcuM_Mode (6U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_ECUM_TYPE_H */
