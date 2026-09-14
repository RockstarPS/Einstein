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
 *              File: Os_Trace_Lcfg.h
 *   Generation Time: 2020-04-08 11:31:56
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_TRACE_LCFG_H)                                                       /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_TRACE_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Trace_Types.h"

/* Os kernel module dependencies */

/* Os hal dependencies */

/* User file includes */
# include "DbgExt.h"


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

# define OS_START_SEC_PUBLIC_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define OS_STOP_SEC_PUBLIC_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Trace configuration data: AppTask_10msLP */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_AppTask_10msLP;

/*! Trace configuration data: IdleTask_OsCore_Core0 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_IdleTask_OsCore_Core0;

/*! Trace configuration data: OsTask_100ms */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsTask_100ms;

/*! Trace configuration data: OsTask_10msCAN */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsTask_10msCAN;

/*! Trace configuration data: OsTask_10msEcuM */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsTask_10msEcuM;

/*! Trace configuration data: OsTask_10ms_Wdg */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsTask_10ms_Wdg;

/*! Trace configuration data: OsTask_2ms */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsTask_2ms;

/*! Trace configuration data: OsTask_30ms */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsTask_30ms;

/*! Trace configuration data: OsTask_30msSnd */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsTask_30msSnd;

/*! Trace configuration data: OsTask_4ms_Ipcl */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsTask_4ms_Ipcl;

/*! Trace configuration data: OsTask_NvM_Stack */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsTask_NvM_Stack;

/*! Trace configuration data: OsTask_RteEvent */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsTask_RteEvent;

/*! Trace configuration data: OsTask_StackMesure */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsTask_StackMesure;

/*! Trace configuration data: StartupTwo */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_StartupTwo;

/*! Trace configuration data: Bswc_App_Intrpt */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_Bswc_App_Intrpt;

/*! Trace configuration data: CanIsr_0 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_CanIsr_0;

/*! Trace configuration data: CanIsr_5 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_CanIsr_5;

/*! Trace configuration data: OsIsr_60MHzFRT */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_60MHzFRT;

/*! Trace configuration data: OsIsr_ADC_B0_ConversionDone */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_ADC_B0_ConversionDone;

/*! Trace configuration data: OsIsr_ADC_B1_ConversionDone */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_ADC_B1_ConversionDone;

/*! Trace configuration data: OsIsr_DMA_Ch0 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_DMA_Ch0;

/*! Trace configuration data: OsIsr_DMA_Ch12 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_DMA_Ch12;

/*! Trace configuration data: OsIsr_DMA_Ch13 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_DMA_Ch13;

/*! Trace configuration data: OsIsr_DMA_Ch14 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_DMA_Ch14;

/*! Trace configuration data: OsIsr_DMA_Ch15 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_DMA_Ch15;

/*! Trace configuration data: OsIsr_DMA_Error */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_DMA_Error;

/*! Trace configuration data: OsIsr_ECC_BACKUP_CANFD_RAM_1_Bit_Error */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_ECC_BACKUP_CANFD_RAM_1_Bit_Error;

/*! Trace configuration data: OsIsr_ECC_IRC_Vector_Address_RAM_1_Bit_Error */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_ECC_IRC_Vector_Address_RAM_1_Bit_Error;

/*! Trace configuration data: OsIsr_ECC_SRAM_1_Bit_Error */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_ECC_SRAM_1_Bit_Error;

/*! Trace configuration data: OsIsr_Ext_Int_0 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_Ext_Int_0;

/*! Trace configuration data: OsIsr_Ext_Int_6 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_Ext_Int_6;

/*! Trace configuration data: OsIsr_FAN_SPD */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_FAN_SPD;

/*! Trace configuration data: OsIsr_MFS_Error_Ch9 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_MFS_Error_Ch9;

/*! Trace configuration data: OsIsr_MFS_Receive_Ch9 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_MFS_Receive_Ch9;

/*! Trace configuration data: OsIsr_MFS_Transmit_Ch9 */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_MFS_Transmit_Ch9;

/*! Trace configuration data: OsIsr_RLT01_1us_1shot_delay */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_RLT01_1us_1shot_delay;

/*! Trace configuration data: OsIsr_RTC */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_RTC;

/*! Trace configuration data: OsIsr_SystemTimer */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_SystemTimer;

/*! Trace configuration data: OsIsr_TmExt */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_TmExt;

/*! Trace configuration data: OsIsr_Wdg_TO */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_Wdg_TO;

/*! Trace configuration data: OsIsr_Wdg_Trg */
extern CONST(Os_TraceThreadConfigType, OS_CONST) OsCfg_Trace_OsIsr_Wdg_Trg;

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TRACE_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Trace_Lcfg.h
 *********************************************************************************************************************/
