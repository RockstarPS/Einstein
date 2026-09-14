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
 *              File: Os_Scheduler_Cfg.h
 *   Generation Time: 2020-04-08 11:31:56
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_SCHEDULER_CFG_H)                                                    /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_SCHEDULER_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines the number of all task queues. */
# define OS_CFG_NUM_TASKQUEUES                   (10UL)

/* Number of task queue activation slots: OsCore_Core0 */
# define OS_CFG_NUM_TASKQUEUE0_OSCORE_CORE0_SLOTS     (3UL)
# define OS_CFG_NUM_TASKQUEUE1_OSCORE_CORE0_SLOTS     (41UL)
# define OS_CFG_NUM_TASKQUEUE2_OSCORE_CORE0_SLOTS     (4UL)
# define OS_CFG_NUM_TASKQUEUE3_OSCORE_CORE0_SLOTS     (3UL)
# define OS_CFG_NUM_TASKQUEUE4_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE5_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE6_OSCORE_CORE0_SLOTS     (3UL)
# define OS_CFG_NUM_TASKQUEUE7_OSCORE_CORE0_SLOTS     (6UL)
# define OS_CFG_NUM_TASKQUEUE8_OSCORE_CORE0_SLOTS     (2UL)
# define OS_CFG_NUM_TASKQUEUE9_OSCORE_CORE0_SLOTS     (2UL)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_SCHEDULER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Scheduler_Cfg.h
 *********************************************************************************************************************/
