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
 *              File: Os_Hal_Context_Lcfg.h
 *   Generation Time: 2020-04-08 11:31:55
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_HAL_CONTEXT_LCFG_H)                                                 /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_HAL_CONTEXT_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Context_Types.h"

/* Os kernel module dependencies */
# include "Os_Core_Cfg.h"

/* Os hal dependencies */
# include "Os_Hal_Os_Types.h"


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

# define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore_Core0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore_Core0_Dyn;
/*! HAL dynamic hook FPU context data: Os_CoreInitHook_OsCore_Core0 */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_Os_CoreInitHook_OsCore_Core0_Dyn;

/*! HAL dynamic hook context data: StartupHook_OsCore_Core0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_StartupHook_OsCore_Core0_Dyn;
/*! HAL dynamic hook FPU context data: StartupHook_OsCore_Core0 */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_StartupHook_OsCore_Core0_Dyn;

/*! HAL dynamic hook context data: ShutdownHook_OsCore_Core0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ShutdownHook_OsCore_Core0_Dyn;
/*! HAL dynamic hook FPU context data: ShutdownHook_OsCore_Core0 */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_ShutdownHook_OsCore_Core0_Dyn;

/*! HAL dynamic hook context data: ErrorHook_OsCore_Core0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ErrorHook_OsCore_Core0_Dyn;
/*! HAL dynamic hook FPU context data: ErrorHook_OsCore_Core0 */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_ErrorHook_OsCore_Core0_Dyn;

/*! HAL dynamic hook context data: ProtectionHook_OsCore_Core0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ProtectionHook_OsCore_Core0_Dyn;
/*! HAL dynamic hook FPU context data: ProtectionHook_OsCore_Core0 */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_ProtectionHook_OsCore_Core0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_Core0_Isr_Level1_Dyn;
/*! HAL dynamic ISR2 level FPU context data: Level1 */
extern VAR(Os_Hal_ContextFpuContextType, OS_VAR_NOINIT) OsCfg_Hal_FpuContext_OsCore_Core0_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_Core0_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_Core0_Isr_Level3_Dyn;

/*! HAL dynamic ISR2 level context data: Level4 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_Core0_Isr_Level4_Dyn;

/*! HAL dynamic task context data: AppTask_10msLP */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_AppTask_10msLP_Dyn;


/*! HAL dynamic task context data: IdleTask_OsCore_Core0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore_Core0_Dyn;


/*! HAL dynamic task context data: OsTask_100ms */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_100ms_Dyn;


/*! HAL dynamic task context data: OsTask_10msCAN */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_10msCAN_Dyn;


/*! HAL dynamic task context data: OsTask_10msEcuM */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_10msEcuM_Dyn;


/*! HAL dynamic task context data: OsTask_10ms_Wdg */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_10ms_Wdg_Dyn;


/*! HAL dynamic task context data: OsTask_2ms */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_2ms_Dyn;


/*! HAL dynamic task context data: OsTask_30ms */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_30ms_Dyn;


/*! HAL dynamic task context data: OsTask_30msSnd */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_30msSnd_Dyn;


/*! HAL dynamic task context data: OsTask_4ms_Ipcl */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_4ms_Ipcl_Dyn;


/*! HAL dynamic task context data: OsTask_NvM_Stack */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_NvM_Stack_Dyn;


/*! HAL dynamic task context data: OsTask_RteEvent */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_RteEvent_Dyn;


/*! HAL dynamic task context data: OsTask_StackMesure */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_StackMesure_Dyn;


/*! HAL dynamic task context data: StartupTwo */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_StartupTwo_Dyn;


/*! HAL exception context data: OsCore_Core0 */
extern VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore_Core0_ExceptionContext;

# define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore_Core0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore_Core0;

/*! HAL hook context configuration data: StartupHook_OsCore_Core0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_StartupHook_OsCore_Core0;

/*! HAL hook context configuration data: ShutdownHook_OsCore_Core0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ShutdownHook_OsCore_Core0;

/*! HAL hook context configuration data: ErrorHook_OsCore_Core0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ErrorHook_OsCore_Core0;

/*! HAL hook context configuration data: ProtectionHook_OsCore_Core0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ProtectionHook_OsCore_Core0;

/*! HAL ISR2 context configuration data: Bswc_App_Intrpt */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Bswc_App_Intrpt;

/*! HAL ISR2 context configuration data: CanIsr_0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_0;

/*! HAL ISR2 context configuration data: CanIsr_5 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsr_5;

/*! HAL ISR2 context configuration data: OsIsr_60MHzFRT */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_60MHzFRT;

/*! HAL ISR2 context configuration data: OsIsr_ADC_B0_ConversionDone */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_ADC_B0_ConversionDone;

/*! HAL ISR2 context configuration data: OsIsr_ADC_B1_ConversionDone */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_ADC_B1_ConversionDone;

/*! HAL ISR2 context configuration data: OsIsr_DMA_Ch0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_DMA_Ch0;

/*! HAL ISR2 context configuration data: OsIsr_DMA_Ch12 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_DMA_Ch12;

/*! HAL ISR2 context configuration data: OsIsr_DMA_Ch13 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_DMA_Ch13;

/*! HAL ISR2 context configuration data: OsIsr_DMA_Ch14 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_DMA_Ch14;

/*! HAL ISR2 context configuration data: OsIsr_DMA_Ch15 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_DMA_Ch15;

/*! HAL ISR2 context configuration data: OsIsr_DMA_Error */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_DMA_Error;

/*! HAL ISR2 context configuration data: OsIsr_ECC_BACKUP_CANFD_RAM_1_Bit_Error */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_ECC_BACKUP_CANFD_RAM_1_Bit_Error;

/*! HAL ISR2 context configuration data: OsIsr_ECC_IRC_Vector_Address_RAM_1_Bit_Error */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_ECC_IRC_Vector_Address_RAM_1_Bit_Error;

/*! HAL ISR2 context configuration data: OsIsr_ECC_SRAM_1_Bit_Error */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_ECC_SRAM_1_Bit_Error;

/*! HAL ISR2 context configuration data: OsIsr_Ext_Int_0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_Ext_Int_0;

/*! HAL ISR2 context configuration data: OsIsr_Ext_Int_6 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_Ext_Int_6;

/*! HAL ISR2 context configuration data: OsIsr_FAN_SPD */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_FAN_SPD;

/*! HAL ISR2 context configuration data: OsIsr_MFS_Error_Ch9 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_MFS_Error_Ch9;

/*! HAL ISR2 context configuration data: OsIsr_MFS_Receive_Ch9 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_MFS_Receive_Ch9;

/*! HAL ISR2 context configuration data: OsIsr_MFS_Transmit_Ch9 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_MFS_Transmit_Ch9;

/*! HAL ISR2 context configuration data: OsIsr_RLT01_1us_1shot_delay */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_RLT01_1us_1shot_delay;

/*! HAL ISR2 context configuration data: OsIsr_RTC */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_RTC;

/*! HAL ISR2 context configuration data: OsIsr_SystemTimer */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_SystemTimer;

/*! HAL ISR2 context configuration data: OsIsr_TmExt */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_TmExt;

/*! HAL ISR2 context configuration data: OsIsr_Wdg_TO */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_Wdg_TO;

/*! HAL ISR2 context configuration data: OsIsr_Wdg_Trg */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsIsr_Wdg_Trg;

/*! HAL task context configuration data: AppTask_10msLP */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_AppTask_10msLP;

/*! HAL task context configuration data: IdleTask_OsCore_Core0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore_Core0;

/*! HAL task context configuration data: OsTask_100ms */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_100ms;

/*! HAL task context configuration data: OsTask_10msCAN */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_10msCAN;

/*! HAL task context configuration data: OsTask_10msEcuM */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_10msEcuM;

/*! HAL task context configuration data: OsTask_10ms_Wdg */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_10ms_Wdg;

/*! HAL task context configuration data: OsTask_2ms */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_2ms;

/*! HAL task context configuration data: OsTask_30ms */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_30ms;

/*! HAL task context configuration data: OsTask_30msSnd */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_30msSnd;

/*! HAL task context configuration data: OsTask_4ms_Ipcl */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_4ms_Ipcl;

/*! HAL task context configuration data: OsTask_NvM_Stack */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_NvM_Stack;

/*! HAL task context configuration data: OsTask_RteEvent */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_RteEvent;

/*! HAL task context configuration data: OsTask_StackMesure */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_StackMesure;

/*! HAL task context configuration data: StartupTwo */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_StartupTwo;

/*! HAL kernel stack configuration data: OsCore_Core0_Kernel */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore_Core0_Kernel;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for HAL exception context. */
extern CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1];

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_CONTEXT_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context_Lcfg.h
 *********************************************************************************************************************/
