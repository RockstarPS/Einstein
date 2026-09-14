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
 *              File: Os_Hal_Interrupt_Lcfg.h
 *   Generation Time: 2020-04-08 11:31:55
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_HAL_INTERRUPT_LCFG_H)                                               /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_HAL_INTERRUPT_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Interrupt_Cfg.h"
# include "Os_Hal_Interrupt_Types.h"

/* Os kernel module dependencies */
# include "Os_Interrupt_Types.h"

/* Os hal dependencies */
# include "Os_Hal_Core_Types.h"


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

/*! HAL ISR configuration data: Bswc_App_Intrpt */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Bswc_App_Intrpt;

/*! HAL ISR configuration data: CanIsr_0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_0;

/*! HAL ISR configuration data: CanIsr_5 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_5;

/*! HAL ISR configuration data: Mcu_SyscNmiCsv_Cat1 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Mcu_SyscNmiCsv_Cat1;

/*! HAL ISR configuration data: OsIsr_60MHzFRT */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_60MHzFRT;

/*! HAL ISR configuration data: OsIsr_ADC_B0_ConversionDone */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_ADC_B0_ConversionDone;

/*! HAL ISR configuration data: OsIsr_ADC_B1_ConversionDone */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_ADC_B1_ConversionDone;

/*! HAL ISR configuration data: OsIsr_DMA_Ch0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_DMA_Ch0;

/*! HAL ISR configuration data: OsIsr_DMA_Ch12 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_DMA_Ch12;

/*! HAL ISR configuration data: OsIsr_DMA_Ch13 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_DMA_Ch13;

/*! HAL ISR configuration data: OsIsr_DMA_Ch14 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_DMA_Ch14;

/*! HAL ISR configuration data: OsIsr_DMA_Ch15 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_DMA_Ch15;

/*! HAL ISR configuration data: OsIsr_DMA_Error */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_DMA_Error;

/*! HAL ISR configuration data: OsIsr_ECC_BACKUP_CANFD_RAM_1_Bit_Error */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_ECC_BACKUP_CANFD_RAM_1_Bit_Error;

/*! HAL ISR configuration data: OsIsr_ECC_IRC_Vector_Address_RAM_1_Bit_Error */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_ECC_IRC_Vector_Address_RAM_1_Bit_Error;

/*! HAL ISR configuration data: OsIsr_ECC_SRAM_1_Bit_Error */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_ECC_SRAM_1_Bit_Error;

/*! HAL ISR configuration data: OsIsr_Ext_Int_0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_Ext_Int_0;

/*! HAL ISR configuration data: OsIsr_Ext_Int_6 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_Ext_Int_6;

/*! HAL ISR configuration data: OsIsr_FAN_SPD */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_FAN_SPD;

/*! HAL ISR configuration data: OsIsr_MFS_Error_Ch9 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_MFS_Error_Ch9;

/*! HAL ISR configuration data: OsIsr_MFS_Receive_Ch9 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_MFS_Receive_Ch9;

/*! HAL ISR configuration data: OsIsr_MFS_Transmit_Ch9 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_MFS_Transmit_Ch9;

/*! HAL ISR configuration data: OsIsr_RLT01_1us_1shot_delay */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_RLT01_1us_1shot_delay;

/*! HAL ISR configuration data: OsIsr_RTC */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_RTC;

/*! HAL ISR configuration data: OsIsr_SystemTimer */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_SystemTimer;

/*! HAL ISR configuration data: OsIsr_TmExt */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_TmExt;

/*! HAL ISR configuration data: OsIsr_Wdg_TO */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_Wdg_TO;

/*! HAL ISR configuration data: OsIsr_Wdg_Trg */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_OsIsr_Wdg_Trg;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_INTERRUPT_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Interrupt_Lcfg.h
 *********************************************************************************************************************/
