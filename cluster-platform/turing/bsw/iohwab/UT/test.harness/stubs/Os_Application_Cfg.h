/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR Renault SLP6 (MSR_Renault_SLP6)
 *          Customer: Visteon Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: S6J332EJB
 *    License Scope : The usage is restricted to CBD1700714_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Application_Cfg.h
 *   Generation Time: 2020-04-08 11:31:55
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_APPLICATION_CFG_H)                                                  /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_APPLICATION_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Number of application objects: OsApplication */
# define OS_CFG_NUM_APP_OSAPPLICATION_ALARMS             (1UL)
# define OS_CFG_NUM_APP_OSAPPLICATION_COUNTERS           (0UL)
# define OS_CFG_NUM_APP_OSAPPLICATION_HOOKS              (0UL)
# define OS_CFG_NUM_APP_OSAPPLICATION_ISRS               (0UL)
# define OS_CFG_NUM_APP_OSAPPLICATION_CAT1ISRS           (0UL)
# define OS_CFG_NUM_APP_OSAPPLICATION_SCHTS              (0UL)
# define OS_CFG_NUM_APP_OSAPPLICATION_TASKS              (0UL)
# define OS_CFG_NUM_APP_OSAPPLICATION_SERVICES           (0UL)

/* Number of application objects: SystemApplication_OsCore_Core0 */
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_ALARMS             (15UL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_COUNTERS           (1UL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_HOOKS              (0UL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_ISRS               (27UL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_CAT1ISRS           (1UL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_SCHTS              (1UL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_TASKS              (14UL)
# define OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE_CORE0_SERVICES           (0UL)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_APPLICATION_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Application_Cfg.h
 *********************************************************************************************************************/
