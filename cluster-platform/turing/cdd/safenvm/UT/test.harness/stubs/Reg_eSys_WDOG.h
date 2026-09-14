/**
*   @file    Reg_eSys_WDOG.h
*   @version 4.0.0
*
*   @brief   AUTOSAR Wdg - Software Watchdog Timer (WDOG1) Registers
*   @details Contains information about the WDOG1's registers
*
*   @addtogroup  Wdg
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : SC
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

#ifndef REG_ESYS_WDOG_H
#define REG_ESYS_WDOG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_WDOG_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the contents 
* of a header file being included twice.
* Required by the Autosar specification.Needed for different code sections definition.
*
* @section Reg_eSys_WDOG_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
* @section Reg_eSys_WDOG_H_REF_3
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function. These objects are used in various parts of the code
*
* @section Reg_eSys_WDOG_H_REF_4
* Violates MISRA 2004 Advisory Rule 19.7, A function should be used in preference to a function-like macro
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Reg_eSys_WDOG_H_REF_1 MISRA 2004 Required Rule 19.15, The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for external identifiers.
*/
#include "Reg_eSys.h"
/*
* @violates @ref Reg_eSys_WDOG_H_REF_1 MISRA 2004 Required Rule 19.15, The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for external identifiers.
*/
/* #include "Reg_Macros.h" */
/*
* @violates @ref Reg_eSys_WDOG_H_REF_1 MISRA 2004 Required Rule 19.15, The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for external identifiers.
*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief  Parameters that shall be published within the driver header file and also in the 
* module's description file
*/
#define REG_ESYS_WDOG_VENDOR_ID                      43
/* @violates @ref Reg_eSys_WDOG_H_REF_2 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define REG_ESYS_WDOG_AR_RELEASE_MAJOR_VERSION       4
/* @violates @ref Reg_eSys_WDOG_H_REF_2 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define REG_ESYS_WDOG_AR_RELEASE_MINOR_VERSION       2
/* @violates @ref Reg_eSys_WDOG_H_REF_2 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters */
#define REG_ESYS_WDOG_AR_RELEASE_REVISION_VERSION    2
#define REG_ESYS_WDOG_SW_MAJOR_VERSION               4
#define REG_ESYS_WDOG_SW_MINOR_VERSION               0
#define REG_ESYS_WDOG_SW_PATCH_VERSION               0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Reg_eSys_WDOG.h and Reg_eSys.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((REG_ESYS_WDOG_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
     (REG_ESYS_WDOG_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))

    #error "AutoSar Version Numbers of Reg_eSys_WDOG.h and Reg_eSys.h are different"
#endif
#endif
/*==================================================================================================
*                                          GLOBAL CONSTANTS
==================================================================================================*/
/**
* @brief WDOG_CS register
*/

/**
* @brief This constant specifies the value of the WDOG_CS's register Wdg enable bit EN if disabled
*/
#define WDOG_ENABLED_U32                     (0x00000080UL)

/**
* @brief This constant specifies the value of the WDOG_CS's register reserved bit 13
*/
#define WDOG_RESERVED_BIT13_U32              (0x00002000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's Wdg enable bit EN if disabled
*/
#define WDOG_DISABLED_U32                    (0x00000000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's debug mode control bit DBG if enabled
*/
#define WDOG_STOP_IN_DEBUG_U32               (0x00000000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's debug mode control bit DBG if disabled
*/
#define WDOG_RUN_IN_DEBUG_U32                (0x00000004UL)

/**
* @brief This constant specifies the value of the WDOG_CS's stop mode control bit STOP if enabled
*/
#define WDOG_STOP_IN_HALT_U32                (0x00000000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's stop mode control bit STOP if disabled
*/
#define WDOG_RUN_IN_HALT_U32                 (0x00000001UL)

/**
* @brief This constant specifies the value of the WDOG_CS's mode control bit WAIT if enabled
*/
#define WDOG_STOP_IN_WAIT_U32                (0x00000000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's  mode control bit WAIT if disabled
*/
#define WDOG_RUN_IN_WAIT_U32                 (0x00000002UL)

/**
* @brief This constant specifies the value of the WDOG_CS's clock selection bit CLK if bus clk selected
*/
#define WDOG_BUS_CLK_U32                      (0x00000000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's clock selection bit CLK if lpo clk selected
*/
#define WDOG_LPO_CLK_U32                      (0x00000100UL)

/**
* @brief This constant specifies the value of the WDOG_CS's clock selection bit CLK if sosc selected
*/
#define WDOG_INT_CLK_U32                      (0x00000200UL)

/**
* @brief This constant specifies the value of the WDOG_CS's clock selection bit CLK if sirc selected
*/
#define WDOG_RRC_CLK_U32                      (0x00000300UL)

/**
* @brief This constant specifies the value of the WDOG_CS's interrupt bit INT if enabled
*/
#define WDOG_INTERRUPT_ENABLED_U32             (0x00000040UL)

/**
* @brief This constant specifies the value of the WDOG_CS's interrupt bit INT if disabled
*/
#define WDOG_INTERRUPT_DISABLED_U32            (0x00000000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's window mode bit WIN if enabled
*/
#define WDOG_TRIGGER_MODE_WINDOW_U32            (0x00008000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's window mode bit WIN if disabled
*/
#define WDOG_TRIGGER_MODE_REGULAR_U32           (0x00000000UL)

/**
* @brief  This constant specifies the value that clears the flag FLG of WDOG_CS register.
*/
#define WDOG_CLEAR_INT_FLAG_U32                  (0x00004000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's register prescaler enable bit PRES if enabled
*/
#define WDOG_PRES_ENABLED_U32                    (0x00001000UL)
/**
* @brief This constant specifies the value of the WDOG_CS's prescaler enable bit PRES if disabled
*/
#define WDOG_PRES_DISABLED_U32                   (0x00000000UL)
/**
* @brief This constant specifies the value of the WDOG_CS's register UPDATE bit if update is allowed
*/
#define WDOG_UPDATE_ENABLED_U32                  (0x00000020UL)
/**
* @brief This constant specifies the position of the WDOG_CS's register UPDATE
*/
#define WDOG_UPDATE_SHIFT_U8                     (0x05)

/**
* @brief This constant specifies the value of the WDOG_CS's register UPDATE bit if update is not allowed
*/
#define WDOG_UPDATE_DISABLED_U32                 (0x00000000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's register TST bit if the test mode is disabled
*/
#define WDOG_TEST_MODE_DISABLED_U32              (0x00000000UL)
/**
* @brief This constant specifies the value of the WDOG_CS's register TST bit if user mode selected
*/
#define WDOG_USER_MODE_ENABLED_U32               (0x00000008UL)
/**
* @brief This constant specifies the value of the WDOG_CS's register TST bit if the test mode is low
*/
#define WDOG_TEST_MODE_LOW_U32                   (0x00000010UL)
/**
* @brief This constant specifies the value of the WDOG_CS's register TST bit if the test mode is high
*/
#define WDOG_TEST_MODE_HIGH_U32                  (0x00000018UL)
/**
* @brief This constant specifies the value of the WDOG_CS's register RCS bit if the Wdog is updated successful
*/
#define WDOG_RCS_RECONFIGURATION_U32             (0x00000400UL)
/**
* @brief  This variable will indicate the Wdg Prescaler value
*/
#define WDG_PRESCALER_VALUE_U16                  ((uint16)256)
/**
* @brief  This variable will indicate the init value for the timeout and window period
*/
#define WDG_TICKS_INIT_VAL_U16                   ((uint16)0)
/**
* @brief  This variable will indicate the time-out value for waiting time
*/
#define WDOG_TIMEOUT_U32                         (0x10000000)
/**
* @brief This constant specifies the Watchdog Control and Status Register
* @violates @ref Reg_eSys_WDOG_H_REF_4 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define WDOG_CS_ADDR32(u8ModuleIdx)         (WDOG_aBASE_ADDR32[(u8ModuleIdx)] + (uint32)0x00UL)

/**
* @brief This constant specifies the Watchdog Counter Register
* @violates @ref Reg_eSys_WDOG_H_REF_4 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define WDOG_CNT_ADDR32(u8ModuleIdx)        (WDOG_aBASE_ADDR32[(u8ModuleIdx)] + (uint32)0x04UL)

/**
* @brief This constant specifies the Watchdog Timeout Value Register
* @violates @ref Reg_eSys_WDOG_H_REF_4 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define WDOG_TOVAL_ADDR32(u8ModuleIdx)      (WDOG_aBASE_ADDR32[(u8ModuleIdx)] + (uint32)0x08UL)

/**
* @brief This constant specifies the Watchdog Window Register
* @violates @ref Reg_eSys_WDOG_H_REF_4 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define WDOG_WIN_ADDR32(u8ModuleIdx)        (WDOG_aBASE_ADDR32[(u8ModuleIdx)] + (uint32)0x0CUL)

/**
* @brief This constant specifies the value of the unlock sequence
*/
#define WDOG_UNLOCK_SEQ_U32                  ((uint32)0xD928C520UL)
/**
* @brief This constant specifies the value of the sequence needed to refresh the watchdog
*/
#define WDOG_TRIGGER_SEQUENCE_U32            ((uint32)0xB480A602UL)
/**
* @brief This constant specifies the minimum value that will be set in the WDOG timeout register
*/
#define WDOG_MIN_VALUE_TIMEOUT_U32           ((uint32)0x100)

#ifdef __cplusplus
}
#endif

#endif  /* REG_ESYS_WDOG_H */

/** @} */
