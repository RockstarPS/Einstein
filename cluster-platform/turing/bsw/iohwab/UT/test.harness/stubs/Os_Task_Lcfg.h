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
 *              File: Os_Task_Lcfg.h
 *   Generation Time: 2020-04-08 11:31:56
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_TASK_LCFG_H)                                                        /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_TASK_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Task_Types.h"

/* Os kernel module dependencies */
# include "Os_Ioc_Types.h"
# include "Os_Lcfg.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

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

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Task configuration data: AppTask_10msLP */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_AppTask_10msLP;

/*! Task configuration data: IdleTask_OsCore_Core0 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_IdleTask_OsCore_Core0;

/*! Task configuration data: OsTask_100ms */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_100ms;

/*! Task configuration data: OsTask_10msCAN */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_10msCAN;

/*! Task configuration data: OsTask_10msEcuM */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_10msEcuM;

/*! Task configuration data: OsTask_10ms_Wdg */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_10ms_Wdg;

/*! Task configuration data: OsTask_2ms */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_2ms;

/*! Task configuration data: OsTask_30ms */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_30ms;

/*! Task configuration data: OsTask_30msSnd */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_30msSnd;

/*! Task configuration data: OsTask_4ms_Ipcl */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_4ms_Ipcl;

/*! Task configuration data: OsTask_NvM_Stack */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_NvM_Stack;

/*! Task configuration data: OsTask_RteEvent */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_RteEvent;

/*! Task configuration data: OsTask_StackMesure */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_StackMesure;

/*! Task configuration data: StartupTwo */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_StartupTwo;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for tasks. */
extern CONSTP2CONST(Os_TaskConfigType, OS_CONST, OS_CONST) OsCfg_TaskRefs[OS_TASKID_COUNT + 1];

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TASK_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Task_Lcfg.h
 *********************************************************************************************************************/
