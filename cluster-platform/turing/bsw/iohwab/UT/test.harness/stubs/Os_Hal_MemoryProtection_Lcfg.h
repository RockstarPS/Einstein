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
 *              File: Os_Hal_MemoryProtection_Lcfg.h
 *   Generation Time: 2020-04-08 11:31:55
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_HAL_MEMORYPROTECTION_LCFG_H)                                        /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_HAL_MEMORYPROTECTION_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_MemoryProtection_Types.h"

/* Os kernel module dependencies */

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

/* Start/end address label declarations */
extern uint8 _OS_OsApplication_VAR_ALL_START[]; /* PRQA S 3684 */ /* MD_Os_3684_LinkerSymbol */
extern uint8 _OS_SystemApplication_OsCore_Core0_VAR_ALL_START[]; /* PRQA S 3684 */ /* MD_Os_3684_LinkerSymbol */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL memory protection configuration data: OsCore_Core0 */
extern CONST(Os_Hal_MpCoreConfigType, OS_CONST) OsCfg_Hal_Mp_OsCore_Core0;

/*! HAL memory protection configuration data: OsApplication */
extern CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_OsApplication;

/*! HAL memory protection configuration data: SystemApplication_OsCore_Core0 */
extern CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_SystemApplication_OsCore_Core0;

/*! HAL memory protection configuration data: Bswc_App_Intrpt */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Bswc_App_Intrpt;

/*! HAL memory protection configuration data: CanIsr_0 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CanIsr_0;

/*! HAL memory protection configuration data: CanIsr_5 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CanIsr_5;

/*! HAL memory protection configuration data: OsIsr_60MHzFRT */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_60MHzFRT;

/*! HAL memory protection configuration data: OsIsr_ADC_B0_ConversionDone */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_ADC_B0_ConversionDone;

/*! HAL memory protection configuration data: OsIsr_ADC_B1_ConversionDone */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_ADC_B1_ConversionDone;

/*! HAL memory protection configuration data: OsIsr_DMA_Ch0 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_DMA_Ch0;

/*! HAL memory protection configuration data: OsIsr_DMA_Ch12 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_DMA_Ch12;

/*! HAL memory protection configuration data: OsIsr_DMA_Ch13 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_DMA_Ch13;

/*! HAL memory protection configuration data: OsIsr_DMA_Ch14 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_DMA_Ch14;

/*! HAL memory protection configuration data: OsIsr_DMA_Ch15 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_DMA_Ch15;

/*! HAL memory protection configuration data: OsIsr_DMA_Error */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_DMA_Error;

/*! HAL memory protection configuration data: OsIsr_ECC_BACKUP_CANFD_RAM_1_Bit_Error */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_ECC_BACKUP_CANFD_RAM_1_Bit_Error;

/*! HAL memory protection configuration data: OsIsr_ECC_IRC_Vector_Address_RAM_1_Bit_Error */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_ECC_IRC_Vector_Address_RAM_1_Bit_Error;

/*! HAL memory protection configuration data: OsIsr_ECC_SRAM_1_Bit_Error */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_ECC_SRAM_1_Bit_Error;

/*! HAL memory protection configuration data: OsIsr_Ext_Int_0 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_Ext_Int_0;

/*! HAL memory protection configuration data: OsIsr_Ext_Int_6 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_Ext_Int_6;

/*! HAL memory protection configuration data: OsIsr_FAN_SPD */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_FAN_SPD;

/*! HAL memory protection configuration data: OsIsr_MFS_Error_Ch9 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_MFS_Error_Ch9;

/*! HAL memory protection configuration data: OsIsr_MFS_Receive_Ch9 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_MFS_Receive_Ch9;

/*! HAL memory protection configuration data: OsIsr_MFS_Transmit_Ch9 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_MFS_Transmit_Ch9;

/*! HAL memory protection configuration data: OsIsr_RLT01_1us_1shot_delay */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_RLT01_1us_1shot_delay;

/*! HAL memory protection configuration data: OsIsr_RTC */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_RTC;

/*! HAL memory protection configuration data: OsIsr_SystemTimer */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_SystemTimer;

/*! HAL memory protection configuration data: OsIsr_TmExt */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_TmExt;

/*! HAL memory protection configuration data: OsIsr_Wdg_TO */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_Wdg_TO;

/*! HAL memory protection configuration data: OsIsr_Wdg_Trg */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsIsr_Wdg_Trg;

/*! HAL memory protection configuration data: AppTask_10msLP */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_AppTask_10msLP;

/*! HAL memory protection configuration data: IdleTask_OsCore_Core0 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_IdleTask_OsCore_Core0;

/*! HAL memory protection configuration data: OsTask_100ms */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsTask_100ms;

/*! HAL memory protection configuration data: OsTask_10msCAN */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsTask_10msCAN;

/*! HAL memory protection configuration data: OsTask_10msEcuM */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsTask_10msEcuM;

/*! HAL memory protection configuration data: OsTask_10ms_Wdg */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsTask_10ms_Wdg;

/*! HAL memory protection configuration data: OsTask_2ms */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsTask_2ms;

/*! HAL memory protection configuration data: OsTask_30ms */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsTask_30ms;

/*! HAL memory protection configuration data: OsTask_30msSnd */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsTask_30msSnd;

/*! HAL memory protection configuration data: OsTask_4ms_Ipcl */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsTask_4ms_Ipcl;

/*! HAL memory protection configuration data: OsTask_NvM_Stack */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsTask_NvM_Stack;

/*! HAL memory protection configuration data: OsTask_RteEvent */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsTask_RteEvent;

/*! HAL memory protection configuration data: OsTask_StackMesure */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_OsTask_StackMesure;

/*! HAL memory protection configuration data: StartupTwo */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_StartupTwo;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL memory protection configuration data: SystemMpu */
extern CONST(Os_Hal_MpSystemConfigType, OS_CONST) OsCfg_Hal_Mp_SystemMpu;

/*! HAL memory protection configuration data: EmptyThread */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EmptyThread;

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_MEMORYPROTECTION_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_MemoryProtection_Lcfg.h
 *********************************************************************************************************************/
