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
 *              File: Os_Stack_Lcfg.h
 *   Generation Time: 2020-04-08 11:31:56
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_STACK_LCFG_H)                                                       /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_STACK_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Stack_Cfg.h"
# include "Os_Stack_Types.h"

/* Os kernel module dependencies */
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

# define OS_START_SEC_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core error stack: OsCore_Core0_Error */
/* User: [ErrorHook_OsCore_Core0, OsCore_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Error_Dyn, OS_CFG_SIZE_OSCORE_CORE0_ERROR_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core init stack: OsCore_Core0_Init */
/* User: [OsCore_Core0, Os_CoreInitHook_OsCore_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Init_Dyn, OS_CFG_SIZE_OSCORE_CORE0_INIT_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* ISR core global stack: OsCore_Core0_Isr_Core */
/* User: [OsIsr_ADC_B0_ConversionDone, OsIsr_ECC_SRAM_1_Bit_Error, OsIsr_DMA_Ch12, OsIsr_DMA_Ch13, OsIsr_DMA_Ch14, Bswc_App_Intrpt, OsIsr_DMA_Ch15, OsIsr_DMA_Ch0, OsIsr_ADC_B1_ConversionDone, OsIsr_60MHzFRT, OsIsr_TmExt, OsIsr_Wdg_TO, OsIsr_ECC_IRC_Vector_Address_RAM_1_Bit_Error, OsIsr_Ext_Int_0, OsIsr_SystemTimer, OsIsr_MFS_Error_Ch9, OsIsr_Ext_Int_6, OsIsr_FAN_SPD, CanIsr_0, OsIsr_DMA_Error, CanIsr_5, OsIsr_ECC_BACKUP_CANFD_RAM_1_Bit_Error, OsIsr_RTC, OsIsr_MFS_Transmit_Ch9, OsIsr_MFS_Receive_Ch9, OsIsr_Wdg_Trg, OsIsr_RLT01_1us_1shot_delay] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE_CORE0_ISR_CORE_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core kernel stack: OsCore_Core0_Kernel */
/* User: [OsCore_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Kernel_Dyn, OS_CFG_SIZE_OSCORE_CORE0_KERNEL_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_PROTECTION_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core protection stack: OsCore_Core0_Protection */
/* User: [OsCore_Core0, ProtectionHook_OsCore_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Protection_Dyn, OS_CFG_SIZE_OSCORE_CORE0_PROTECTION_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_PROTECTION_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core shutdown stack: OsCore_Core0_Shutdown */
/* User: [OsCore_Core0, ShutdownHook_OsCore_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Shutdown_Dyn, OS_CFG_SIZE_OSCORE_CORE0_SHUTDOWN_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Core startup stack: OsCore_Core0_Startup */
/* User: [OsCore_Core0, StartupHook_OsCore_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Startup_Dyn, OS_CFG_SIZE_OSCORE_CORE0_STARTUP_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_STARTUP_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core0_Task_Prio0 */
/* User: [StartupTwo] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Task_Prio0_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO0_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core0_Task_Prio1 */
/* User: [OsTask_2ms] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Task_Prio1_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO1_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO1_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core0_Task_Prio3 */
/* User: [OsTask_30msSnd] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Task_Prio3_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO3_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO3_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core0_Task_Prio4 */
/* User: [OsTask_4ms_Ipcl] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Task_Prio4_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO4_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO4_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core0_Task_Prio5 */
/* User: [OsTask_100ms] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Task_Prio5_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO5_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core0_Task_Prio6 */
/* User: [AppTask_10msLP, OsTask_10ms_Wdg] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Task_Prio6_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO6_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO6_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core0_Task_Prio7 */
/* User: [OsTask_RteEvent, OsTask_StackMesure] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Task_Prio7_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO7_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO7_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSCORE_CORE0_TASK_PRIO9_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Shared Task stack: OsCore_Core0_Task_Prio9 */
/* User: [IdleTask_OsCore_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore_Core0_Task_Prio9_Dyn, OS_CFG_SIZE_OSCORE_CORE0_TASK_PRIO9_STACK);

# define OS_STOP_SEC_STACK_OSCORE_CORE0_TASK_PRIO9_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSTASK_10MSCAN_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Task stack: OsTask_10msCAN */
/* User: [OsTask_10msCAN] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_10msCAN_Dyn, OS_CFG_SIZE_OSTASK_10MSCAN_STACK);

# define OS_STOP_SEC_STACK_OSTASK_10MSCAN_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSTASK_10MSECUM_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Task stack: OsTask_10msEcuM */
/* User: [OsTask_10msEcuM] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_10msEcuM_Dyn, OS_CFG_SIZE_OSTASK_10MSECUM_STACK);

# define OS_STOP_SEC_STACK_OSTASK_10MSECUM_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSTASK_30MS_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Task stack: OsTask_30ms */
/* User: [OsTask_30ms] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_30ms_Dyn, OS_CFG_SIZE_OSTASK_30MS_STACK);

# define OS_STOP_SEC_STACK_OSTASK_30MS_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_STACK_OSTASK_NVM_STACK_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Task stack: OsTask_NvM_Stack */
/* User: [OsTask_NvM_Stack] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_NvM_Stack_Dyn, OS_CFG_SIZE_OSTASK_NVM_STACK_STACK);

# define OS_STOP_SEC_STACK_OSTASK_NVM_STACK_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Stack configuration data: OsCore_Core0_Error */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Error;

/*! Stack configuration data: OsCore_Core0_Init */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Init;

/*! Stack configuration data: OsCore_Core0_Isr_Core */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Isr_Core;

/*! Stack configuration data: OsCore_Core0_Kernel */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Kernel;

/*! Stack configuration data: OsCore_Core0_Protection */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Protection;

/*! Stack configuration data: OsCore_Core0_Shutdown */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Shutdown;

/*! Stack configuration data: OsCore_Core0_Startup */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Startup;

/*! Stack configuration data: OsCore_Core0_Task_Prio0 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Task_Prio0;

/*! Stack configuration data: OsCore_Core0_Task_Prio1 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Task_Prio1;

/*! Stack configuration data: OsCore_Core0_Task_Prio3 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Task_Prio3;

/*! Stack configuration data: OsCore_Core0_Task_Prio4 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Task_Prio4;

/*! Stack configuration data: OsCore_Core0_Task_Prio5 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Task_Prio5;

/*! Stack configuration data: OsCore_Core0_Task_Prio6 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Task_Prio6;

/*! Stack configuration data: OsCore_Core0_Task_Prio7 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Task_Prio7;

/*! Stack configuration data: OsCore_Core0_Task_Prio9 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore_Core0_Task_Prio9;

/*! Stack configuration data: OsTask_10msCAN */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_10msCAN;

/*! Stack configuration data: OsTask_10msEcuM */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_10msEcuM;

/*! Stack configuration data: OsTask_30ms */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_30ms;

/*! Stack configuration data: OsTask_NvM_Stack */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_NvM_Stack;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_STACK_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Lcfg.h
 *********************************************************************************************************************/
