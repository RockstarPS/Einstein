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
 *           Program: MSR_Ford_SLP1 (MSR_Ford_SLP1)
 *          Customer: Visteon Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: S6J32GELTM
 *    License Scope : The usage is restricted to CBD1800851_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Ioc.h
 *   Generation Time: 2025-04-03 03:02:16
 *           Project: BMW - Version 1.0
 *          Delivery: CBD1800851_D01
 *      Tool Version: DaVinci Configurator (beta) 5.17.71 SP5
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

/**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] OS04010 - Invalid idle Task 
 * - [Reduced Severity due to User-Defined Parameter] /ActiveEcuC/Os/IdleTask_OsCore0[0:OsTaskPriority](value=0) does not match the expected value ' 4294967295' for /ActiveEcuC/Os/IdleTask_OsCore0.
 * Erroneous configuration elements:
 * /ActiveEcuC/Os/IdleTask_OsCore0[0:OsTaskPriority](value=0) (DefRef: /MICROSAR/Os/OsTask/OsTaskPriority)
 * 
 * [Warning] OS04010 - Invalid idle Task 
 * - [Reduced Severity due to User-Defined Parameter] /ActiveEcuC/Os/IdleTask_OsCore0[0:OsTaskType](value=BASIC) does not match the expected value 'AUTO' for /ActiveEcuC/Os/IdleTask_OsCore0.
 * Erroneous configuration elements:
 * /ActiveEcuC/Os/IdleTask_OsCore0[0:OsTaskType](value=BASIC) (DefRef: /MICROSAR/Os/OsTask/OsTaskType)
 *********************************************************************************************************************/
#ifndef IOC_H
# define IOC_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"
# include "vstdlib.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */

/* User file includes */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! IOC function return types */
# define IOC_E_OK                                ((Std_ReturnType)         0)
# define IOC_E_NOK                               ((Std_ReturnType)         1)
# define IOC_E_NO_DATA                           ((Std_ReturnType)       131)
# define IOC_E_LOST_DATA                         ((Std_ReturnType)        64)
# define IOC_E_LIMIT                             ((Std_ReturnType)       130)
# define IOC_E_CHANNEL                           ((Std_ReturnType) IOC_E_NOK)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* IOC_H */

/**********************************************************************************************************************
 *  END OF FILE: Ioc.h
 *********************************************************************************************************************/
