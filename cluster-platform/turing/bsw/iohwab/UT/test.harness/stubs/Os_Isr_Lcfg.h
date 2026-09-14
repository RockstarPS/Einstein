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
 *              File: Os_Isr_Lcfg.h
 *   Generation Time: 2020-04-08 11:31:56
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_ISR_LCFG_H)                                                         /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_ISR_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Isr_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"
# include "Os_Timer_Types.h"
# include "Os_XSignal_Types.h"

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

/*! ISR configuration data: Mcu_SyscNmiCsv_Cat1 */
extern CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_Mcu_SyscNmiCsv_Cat1;

/*! ISR configuration data: Bswc_App_Intrpt */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Bswc_App_Intrpt;

/*! ISR configuration data: CanIsr_0 */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_0;

/*! ISR configuration data: CanIsr_5 */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_5;

/*! ISR configuration data: OsIsr_60MHzFRT */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_60MHzFRT;

/*! ISR configuration data: OsIsr_ADC_B0_ConversionDone */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_ADC_B0_ConversionDone;

/*! ISR configuration data: OsIsr_ADC_B1_ConversionDone */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_ADC_B1_ConversionDone;

/*! ISR configuration data: OsIsr_DMA_Ch0 */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_DMA_Ch0;

/*! ISR configuration data: OsIsr_DMA_Ch12 */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_DMA_Ch12;

/*! ISR configuration data: OsIsr_DMA_Ch13 */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_DMA_Ch13;

/*! ISR configuration data: OsIsr_DMA_Ch14 */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_DMA_Ch14;

/*! ISR configuration data: OsIsr_DMA_Ch15 */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_DMA_Ch15;

/*! ISR configuration data: OsIsr_DMA_Error */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_DMA_Error;

/*! ISR configuration data: OsIsr_ECC_BACKUP_CANFD_RAM_1_Bit_Error */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_ECC_BACKUP_CANFD_RAM_1_Bit_Error;

/*! ISR configuration data: OsIsr_ECC_IRC_Vector_Address_RAM_1_Bit_Error */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_ECC_IRC_Vector_Address_RAM_1_Bit_Error;

/*! ISR configuration data: OsIsr_ECC_SRAM_1_Bit_Error */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_ECC_SRAM_1_Bit_Error;

/*! ISR configuration data: OsIsr_Ext_Int_0 */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_Ext_Int_0;

/*! ISR configuration data: OsIsr_Ext_Int_6 */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_Ext_Int_6;

/*! ISR configuration data: OsIsr_FAN_SPD */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_FAN_SPD;

/*! ISR configuration data: OsIsr_MFS_Error_Ch9 */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_MFS_Error_Ch9;

/*! ISR configuration data: OsIsr_MFS_Receive_Ch9 */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_MFS_Receive_Ch9;

/*! ISR configuration data: OsIsr_MFS_Transmit_Ch9 */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_MFS_Transmit_Ch9;

/*! ISR configuration data: OsIsr_RLT01_1us_1shot_delay */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_RLT01_1us_1shot_delay;

/*! ISR configuration data: OsIsr_RTC */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_RTC;

/*! ISR configuration data: OsIsr_SystemTimer */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_SystemTimer;

/*! ISR configuration data: OsIsr_TmExt */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_TmExt;

/*! ISR configuration data: OsIsr_Wdg_TO */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_Wdg_TO;

/*! ISR configuration data: OsIsr_Wdg_Trg */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_OsIsr_Wdg_Trg;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for category 2 ISRs. */
extern CONSTP2CONST(Os_IsrConfigType, OS_CONST, OS_CONST) OsCfg_IsrRefs[OS_ISRID_COUNT + 1];

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_ISR_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Isr_Lcfg.h
 *********************************************************************************************************************/
