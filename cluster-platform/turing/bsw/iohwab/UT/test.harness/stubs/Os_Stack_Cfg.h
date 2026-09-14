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
 *              File: Os_Stack_Cfg.h
 *   Generation Time: 2020-04-08 11:31:56
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_STACK_CFG_H)                                                        /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_STACK_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether stack monitoring is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_STACKMONITORING                  (STD_ON)

/*! Defines whether stack measurement is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_STACKMEASUREMENT                 (STD_ON)

/* Configured stack sizes (Total: 27648 Byte) */
# define OS_CFG_SIZE_OSCORE_CORE0_ERROR_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_INIT_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_ISR_CORE_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_KERNEL_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_PROTECTION_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_SHUTDOWN_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_STARTUP_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO0_STACK     (2048UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO1_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO3_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO4_STACK     (2048UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO5_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO6_STACK     (2048UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO7_STACK     (1024UL)
# define OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO9_STACK     (1024UL)
# define OS_CFG_SIZE_OSTASK_10MSCAN_STACK     (2048UL)
# define OS_CFG_SIZE_OSTASK_10MSECUM_STACK     (4096UL)
# define OS_CFG_SIZE_OSTASK_30MS_STACK     (1024UL)
# define OS_CFG_SIZE_OSTASK_NVM_STACK_STACK     (2048UL)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_STACK_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Cfg.h
 *********************************************************************************************************************/
