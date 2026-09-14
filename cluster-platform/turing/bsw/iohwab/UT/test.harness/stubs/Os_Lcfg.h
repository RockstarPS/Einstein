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
 *              File: Os_Lcfg.h
 *   Generation Time: 2020-04-08 11:31:56
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_LCFG_H)                                                             /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Cfg.h"
# include "Os_Types.h"
# include "Os_Types_Lcfg.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Lcfg.h"

/* User file includes */


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

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_AppTask_10msLP_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  AppTask_10msLP()
 *********************************************************************************************************************/
extern FUNC(void, OS_APPTASK_10MSLP_CODE) Os_Task_AppTask_10msLP(void);

# define OS_STOP_SEC_AppTask_10msLP_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_OsTask_100ms_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  OsTask_100ms()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_100MS_CODE) Os_Task_OsTask_100ms(void);

# define OS_STOP_SEC_OsTask_100ms_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_OsTask_10msCAN_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  OsTask_10msCAN()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_10MSCAN_CODE) Os_Task_OsTask_10msCAN(void);

# define OS_STOP_SEC_OsTask_10msCAN_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_OsTask_10msEcuM_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  OsTask_10msEcuM()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_10MSECUM_CODE) Os_Task_OsTask_10msEcuM(void);

# define OS_STOP_SEC_OsTask_10msEcuM_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_OsTask_10ms_Wdg_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  OsTask_10ms_Wdg()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_10MS_WDG_CODE) Os_Task_OsTask_10ms_Wdg(void);

# define OS_STOP_SEC_OsTask_10ms_Wdg_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_OsTask_2ms_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  OsTask_2ms()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_2MS_CODE) Os_Task_OsTask_2ms(void);

# define OS_STOP_SEC_OsTask_2ms_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_OsTask_30ms_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  OsTask_30ms()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_30MS_CODE) Os_Task_OsTask_30ms(void);

# define OS_STOP_SEC_OsTask_30ms_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_OsTask_30msSnd_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  OsTask_30msSnd()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_30MSSND_CODE) Os_Task_OsTask_30msSnd(void);

# define OS_STOP_SEC_OsTask_30msSnd_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_OsTask_4ms_Ipcl_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  OsTask_4ms_Ipcl()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_4MS_IPCL_CODE) Os_Task_OsTask_4ms_Ipcl(void);

# define OS_STOP_SEC_OsTask_4ms_Ipcl_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_OsTask_NvM_Stack_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  OsTask_NvM_Stack()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_NVM_STACK_CODE) Os_Task_OsTask_NvM_Stack(void);

# define OS_STOP_SEC_OsTask_NvM_Stack_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_OsTask_RteEvent_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  OsTask_RteEvent()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_RTEEVENT_CODE) Os_Task_OsTask_RteEvent(void);

# define OS_STOP_SEC_OsTask_RteEvent_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_OsTask_StackMesure_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  OsTask_StackMesure()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_STACKMESURE_CODE) Os_Task_OsTask_StackMesure(void);

# define OS_STOP_SEC_OsTask_StackMesure_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_StartupTwo_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  StartupTwo()
 *********************************************************************************************************************/
extern FUNC(void, OS_STARTUPTWO_CODE) Os_Task_StartupTwo(void);

# define OS_STOP_SEC_StartupTwo_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Adc_IsrConversionDone_HwUnit0_Cat2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Adc_IsrConversionDone_HwUnit0_Cat2()
 *********************************************************************************************************************/
extern FUNC(void, OS_ADC_ISRCONVERSIONDONE_HWUNIT0_CAT2_CODE) Os_Isr_Adc_IsrConversionDone_HwUnit0_Cat2(void);

# define OS_STOP_SEC_Adc_IsrConversionDone_HwUnit0_Cat2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_Adc_IsrConversionDone_HwUnit1_Cat2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  Adc_IsrConversionDone_HwUnit1_Cat2()
 *********************************************************************************************************************/
extern FUNC(void, OS_ADC_ISRCONVERSIONDONE_HWUNIT1_CAT2_CODE) Os_Isr_Adc_IsrConversionDone_HwUnit1_Cat2(void);

# define OS_STOP_SEC_Adc_IsrConversionDone_HwUnit1_Cat2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CanIsr_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  CanIsr_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISR_0_CODE) Os_Isr_CanIsr_0(void);

# define OS_STOP_SEC_CanIsr_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_CanIsr_5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  CanIsr_5()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISR_5_CODE) Os_Isr_CanIsr_5(void);

# define OS_STOP_SEC_CanIsr_5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_ECC_BACKUP_CANFD_RAM_1_Bit_ISR_Vector_015_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  ECC_BACKUP_CANFD_RAM_1_Bit_ISR_Vector_015_CAT2()
 *********************************************************************************************************************/
extern FUNC(void, OS_ECC_BACKUP_CANFD_RAM_1_BIT_ISR_VECTOR_015_CAT2_CODE) Os_Isr_ECC_BACKUP_CANFD_RAM_1_Bit_ISR_Vector_015_CAT2(void);

# define OS_STOP_SEC_ECC_BACKUP_CANFD_RAM_1_Bit_ISR_Vector_015_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_ECC_IRC_Vector_Address_RAM_1_Bit_ISR_Vector_016_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  ECC_IRC_Vector_Address_RAM_1_Bit_ISR_Vector_016_CAT2()
 *********************************************************************************************************************/
extern FUNC(void, OS_ECC_IRC_VECTOR_ADDRESS_RAM_1_BIT_ISR_VECTOR_016_CAT2_CODE) Os_Isr_ECC_IRC_Vector_Address_RAM_1_Bit_ISR_Vector_016_CAT2(void);

# define OS_STOP_SEC_ECC_IRC_Vector_Address_RAM_1_Bit_ISR_Vector_016_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_ECC_SRAM_1_Bit_ISR_Vector_014_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  ECC_SRAM_1_Bit_ISR_Vector_014_CAT2()
 *********************************************************************************************************************/
extern FUNC(void, OS_ECC_SRAM_1_BIT_ISR_VECTOR_014_CAT2_CODE) Os_Isr_ECC_SRAM_1_Bit_ISR_Vector_014_CAT2(void);

# define OS_STOP_SEC_ECC_SRAM_1_Bit_ISR_Vector_014_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_GPT_ISR_Vector_153_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GPT_ISR_Vector_153_CAT2()
 *********************************************************************************************************************/
extern FUNC(void, OS_GPT_ISR_VECTOR_153_CAT2_CODE) Os_Isr_GPT_ISR_Vector_153_CAT2(void);

# define OS_STOP_SEC_GPT_ISR_Vector_153_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_GPT_ISR_Vector_160_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GPT_ISR_Vector_160_CAT2()
 *********************************************************************************************************************/
extern FUNC(void, OS_GPT_ISR_VECTOR_160_CAT2_CODE) Os_Isr_GPT_ISR_Vector_160_CAT2(void);

# define OS_STOP_SEC_GPT_ISR_Vector_160_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_GPT_ISR_Vector_161_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GPT_ISR_Vector_161_CAT2()
 *********************************************************************************************************************/
extern FUNC(void, OS_GPT_ISR_VECTOR_161_CAT2_CODE) Os_Isr_GPT_ISR_Vector_161_CAT2(void);

# define OS_STOP_SEC_GPT_ISR_Vector_161_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_GPT_ISR_Vector_176_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GPT_ISR_Vector_176_CAT2()
 *********************************************************************************************************************/
extern FUNC(void, OS_GPT_ISR_VECTOR_176_CAT2_CODE) Os_Isr_GPT_ISR_Vector_176_CAT2(void);

# define OS_STOP_SEC_GPT_ISR_Vector_176_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_GPT_ISR_Vector_178_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GPT_ISR_Vector_178_CAT2()
 *********************************************************************************************************************/
extern FUNC(void, OS_GPT_ISR_VECTOR_178_CAT2_CODE) Os_Isr_GPT_ISR_Vector_178_CAT2(void);

# define OS_STOP_SEC_GPT_ISR_Vector_178_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_GPT_ISR_Vector_180_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GPT_ISR_Vector_180_CAT2()
 *********************************************************************************************************************/
extern FUNC(void, OS_GPT_ISR_VECTOR_180_CAT2_CODE) Os_Isr_GPT_ISR_Vector_180_CAT2(void);

# define OS_STOP_SEC_GPT_ISR_Vector_180_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_ICU_ISR_Vector_192_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  ICU_ISR_Vector_192_CAT2()
 *********************************************************************************************************************/
extern FUNC(void, OS_ICU_ISR_VECTOR_192_CAT2_CODE) Os_Isr_ICU_ISR_Vector_192_CAT2(void);

# define OS_STOP_SEC_ICU_ISR_Vector_192_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_ICU_ISR_Vector_24_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  ICU_ISR_Vector_24_CAT2()
 *********************************************************************************************************************/
extern FUNC(void, OS_ICU_ISR_VECTOR_24_CAT2_CODE) Os_Isr_ICU_ISR_Vector_24_CAT2(void);

# define OS_STOP_SEC_ICU_ISR_Vector_24_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_ICU_ISR_Vector_30_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  ICU_ISR_Vector_30_CAT2()
 *********************************************************************************************************************/
extern FUNC(void, OS_ICU_ISR_VECTOR_30_CAT2_CODE) Os_Isr_ICU_ISR_Vector_30_CAT2(void);

# define OS_STOP_SEC_ICU_ISR_Vector_30_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_ISR_DMAC_Completion_ch_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  ISR_DMAC_Completion_ch_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_ISR_DMAC_COMPLETION_CH_0_CODE) Os_Isr_ISR_DMAC_Completion_ch_0(void);

# define OS_STOP_SEC_ISR_DMAC_Completion_ch_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_ISR_DMAC_Completion_ch_12_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  ISR_DMAC_Completion_ch_12()
 *********************************************************************************************************************/
extern FUNC(void, OS_ISR_DMAC_COMPLETION_CH_12_CODE) Os_Isr_ISR_DMAC_Completion_ch_12(void);

# define OS_STOP_SEC_ISR_DMAC_Completion_ch_12_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_ISR_DMAC_Completion_ch_13_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  ISR_DMAC_Completion_ch_13()
 *********************************************************************************************************************/
extern FUNC(void, OS_ISR_DMAC_COMPLETION_CH_13_CODE) Os_Isr_ISR_DMAC_Completion_ch_13(void);

# define OS_STOP_SEC_ISR_DMAC_Completion_ch_13_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_ISR_DMAC_Completion_ch_14_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  ISR_DMAC_Completion_ch_14()
 *********************************************************************************************************************/
extern FUNC(void, OS_ISR_DMAC_COMPLETION_CH_14_CODE) Os_Isr_ISR_DMAC_Completion_ch_14(void);

# define OS_STOP_SEC_ISR_DMAC_Completion_ch_14_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_ISR_DMAC_Completion_ch_15_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  ISR_DMAC_Completion_ch_15()
 *********************************************************************************************************************/
extern FUNC(void, OS_ISR_DMAC_COMPLETION_CH_15_CODE) Os_Isr_ISR_DMAC_Completion_ch_15(void);

# define OS_STOP_SEC_ISR_DMAC_Completion_ch_15_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_ISR_DMA_Error_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  ISR_DMA_Error()
 *********************************************************************************************************************/
extern FUNC(void, OS_ISR_DMA_ERROR_CODE) Os_Isr_ISR_DMA_Error(void);

# define OS_STOP_SEC_ISR_DMA_Error_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_ISR_MFS_Error_ch_9_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  ISR_MFS_Error_ch_9()
 *********************************************************************************************************************/
extern FUNC(void, OS_ISR_MFS_ERROR_CH_9_CODE) Os_Isr_ISR_MFS_Error_ch_9(void);

# define OS_STOP_SEC_ISR_MFS_Error_ch_9_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_ISR_MFS_Receive_ch_9_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  ISR_MFS_Receive_ch_9()
 *********************************************************************************************************************/
extern FUNC(void, OS_ISR_MFS_RECEIVE_CH_9_CODE) Os_Isr_ISR_MFS_Receive_ch_9(void);

# define OS_STOP_SEC_ISR_MFS_Receive_ch_9_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_ISR_MFS_Transmit_ch_9_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  ISR_MFS_Transmit_ch_9()
 *********************************************************************************************************************/
extern FUNC(void, OS_ISR_MFS_TRANSMIT_CH_9_CODE) Os_Isr_ISR_MFS_Transmit_ch_9(void);

# define OS_STOP_SEC_ISR_MFS_Transmit_ch_9_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_RTC_ISR_Vector_116_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  RTC_ISR_Vector_116_CAT2()
 *********************************************************************************************************************/
extern FUNC(void, OS_RTC_ISR_VECTOR_116_CAT2_CODE) Os_Isr_RTC_ISR_Vector_116_CAT2(void);

# define OS_STOP_SEC_RTC_ISR_Vector_116_CAT2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# define OS_START_SEC_SystemTimerIsr_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  SystemTimerIsr()
 *********************************************************************************************************************/
extern FUNC(void, OS_SYSTEMTIMERISR_CODE) Os_Isr_SystemTimerIsr(void);

# define OS_STOP_SEC_SystemTimerIsr_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#endif /* OS_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Lcfg.h
 *********************************************************************************************************************/
