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
 *           Program: VAG AR4 (MSR_Vag_SLP5)
 *          Customer: Visteon Electronics Germany GmbH
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: iMX8QuadXPlus
 *    License Scope : The usage is restricted to CBD1700905_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Compiler_Cfg.h
 *   Generation Time: 2020-06-09 21:59:53
 *           Project: iMX8 - Version 1.0
 *          Delivery: CBD1700905_D00
 *      Tool Version: DaVinci Configurator (beta) 5.16.31 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

#if !defined (OS_COMPILER_CFG_H)                                                     /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_COMPILER_CFG_H

/**********************************************************************************************************************
 *  OS USER CALLOUT CODE SECTIONS
 *********************************************************************************************************************/

# define OS_IRQSTEER_EXT_1_ISR_CODE
# define OS_IRQSTEER_EXT_4_ISR_CODE
# define OS_IRQSTEER_I2C0_ISR_CODE
# define OS_INIT_TASK_CODE
# define OS_OSTASK_10MS_SWC_CODE
# define OS_OSTASK_20MS_SWC_CODE
# define OS_OSTASK_50MS_SWC_CODE
# define OS_OSTASK_BSWCTRL_10MS_CODE
# define OS_OSTASK_BSW_10MS_CODE
# define OS_OSTASK_CDD_10MS_CODE
# define OS_OSTASK_COMM1_10MS_CODE
# define OS_OSTASK_NVMSPEEDUP_10MS_CODE
# define OS_OSTASK_UCLPROXYEVENT_10MS_CODE
# define OS_OSTASK_UCL_10MS_CODE
# define OS_SAMPLETASK_CODE


#endif /* OS_COMPILER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Compiler_Cfg.h
 *********************************************************************************************************************/
