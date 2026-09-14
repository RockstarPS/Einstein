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
 *           Program: MSR_Jlr_SLP2
 *          Customer: Visteon Engineering Services Ltd
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: IMX8DualXPlus
 *    License Scope : The usage is restricted to CBD1800321_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Compiler_Cfg.h
 *   Generation Time: 2018-11-28 19:13:29
 *           Project: iMX8 - Version 1.0
 *          Delivery: CBD1800321_D00
 *      Tool Version: DaVinci Configurator (beta) 5.17.51 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

#if !defined (OS_COMPILER_CFG_H)                                                     /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_COMPILER_CFG_H

/**********************************************************************************************************************
 *  OS USER CALLOUT CODE SECTIONS
 *********************************************************************************************************************/

# define OS_BSW_TASK_CODE
# define OS_IRQSTEER_EXT_1_ISR_CODE
# define OS_IRQSTEER_EXT_4_ISR_CODE
# define OS_IRQSTEER_I2C0_ISR_CODE
# define OS_INITTASK_CODE
# define OS_OSTASK_ECUMEXT_CODE
# define OS_OSTASK_IOHWAB_CODE
# define OS_OSTASK_UCL_CODE


#endif /* OS_COMPILER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Compiler_Cfg.h
 *********************************************************************************************************************/
