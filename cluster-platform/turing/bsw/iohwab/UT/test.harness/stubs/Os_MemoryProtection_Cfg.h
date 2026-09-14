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
 *              File: Os_MemoryProtection_Cfg.h
 *   Generation Time: 2020-04-08 11:31:56
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_MEMORYPROTECTION_CFG_H)                                             /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_MEMORYPROTECTION_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether memory protection is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_MEMORY_PROTECTION                          (STD_ON)

/*! Defines whether access rights switching for applications is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_MEMORY_PROTECTION_FOR_APPLICATIONS         (STD_ON)

/*! Defines whether access rights switching for threads is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_MEMORY_PROTECTION_FOR_THREADS              (STD_OFF)

/*! Defines whether the OS has write access to OS data in privileged mode (STD_ON) or not (STD_OFF). */
# define OS_CFG_MEMORY_PROTECTION_FOR_TRUSTED              (STD_OFF)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_MEMORYPROTECTION_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_MemoryProtection_Cfg.h
 *********************************************************************************************************************/
