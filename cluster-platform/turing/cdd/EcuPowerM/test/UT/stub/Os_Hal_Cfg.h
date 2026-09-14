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
 *              File: Os_Hal_Cfg.h
 *   Generation Time: 2020-04-08 11:31:55
 *           Project: Turing - Version 1.0
 *          Delivery: CBD1700714_D02
 *      Tool Version: DaVinci Configurator  5.16.41 SP3
 *
 *
 *********************************************************************************************************************/

#if !defined (OS_HAL_CFG_H)                                                          /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_HAL_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! HAL configuration major version identification. */
# define OS_CFG_HAL_MAJOR_VERSION                (2U)

/*! HAL configuration minor version identification. */
# define OS_CFG_HAL_MINOR_VERSION                (15U)

/* ISR core and level definitions */
# define OS_ISR_BSWC_APP_INTRPT_CORE      (0)
# define OS_ISR_BSWC_APP_INTRPT_LEVEL     (31)
# define OS_ISR_CANISR_0_CORE      (0)
# define OS_ISR_CANISR_0_LEVEL     (31)
# define OS_ISR_CANISR_5_CORE      (0)
# define OS_ISR_CANISR_5_LEVEL     (31)
# define OS_ISR_MCU_SYSCNMICSV_CAT1_CORE      (0)
# define OS_ISR_MCU_SYSCNMICSV_CAT1_LEVEL     (4)
# define OS_ISR_OSISR_60MHZFRT_CORE      (0)
# define OS_ISR_OSISR_60MHZFRT_LEVEL     (31)
# define OS_ISR_OSISR_ADC_B0_CONVERSIONDONE_CORE      (0)
# define OS_ISR_OSISR_ADC_B0_CONVERSIONDONE_LEVEL     (31)
# define OS_ISR_OSISR_ADC_B1_CONVERSIONDONE_CORE      (0)
# define OS_ISR_OSISR_ADC_B1_CONVERSIONDONE_LEVEL     (31)
# define OS_ISR_OSISR_DMA_CH0_CORE      (0)
# define OS_ISR_OSISR_DMA_CH0_LEVEL     (31)
# define OS_ISR_OSISR_DMA_CH12_CORE      (0)
# define OS_ISR_OSISR_DMA_CH12_LEVEL     (31)
# define OS_ISR_OSISR_DMA_CH13_CORE      (0)
# define OS_ISR_OSISR_DMA_CH13_LEVEL     (31)
# define OS_ISR_OSISR_DMA_CH14_CORE      (0)
# define OS_ISR_OSISR_DMA_CH14_LEVEL     (31)
# define OS_ISR_OSISR_DMA_CH15_CORE      (0)
# define OS_ISR_OSISR_DMA_CH15_LEVEL     (31)
# define OS_ISR_OSISR_DMA_ERROR_CORE      (0)
# define OS_ISR_OSISR_DMA_ERROR_LEVEL     (31)
# define OS_ISR_OSISR_ECC_BACKUP_CANFD_RAM_1_BIT_ERROR_CORE      (0)
# define OS_ISR_OSISR_ECC_BACKUP_CANFD_RAM_1_BIT_ERROR_LEVEL     (31)
# define OS_ISR_OSISR_ECC_IRC_VECTOR_ADDRESS_RAM_1_BIT_ERROR_CORE      (0)
# define OS_ISR_OSISR_ECC_IRC_VECTOR_ADDRESS_RAM_1_BIT_ERROR_LEVEL     (31)
# define OS_ISR_OSISR_ECC_SRAM_1_BIT_ERROR_CORE      (0)
# define OS_ISR_OSISR_ECC_SRAM_1_BIT_ERROR_LEVEL     (31)
# define OS_ISR_OSISR_EXT_INT_0_CORE      (0)
# define OS_ISR_OSISR_EXT_INT_0_LEVEL     (31)
# define OS_ISR_OSISR_EXT_INT_6_CORE      (0)
# define OS_ISR_OSISR_EXT_INT_6_LEVEL     (31)
# define OS_ISR_OSISR_FAN_SPD_CORE      (0)
# define OS_ISR_OSISR_FAN_SPD_LEVEL     (31)
# define OS_ISR_OSISR_MFS_ERROR_CH9_CORE      (0)
# define OS_ISR_OSISR_MFS_ERROR_CH9_LEVEL     (31)
# define OS_ISR_OSISR_MFS_RECEIVE_CH9_CORE      (0)
# define OS_ISR_OSISR_MFS_RECEIVE_CH9_LEVEL     (31)
# define OS_ISR_OSISR_MFS_TRANSMIT_CH9_CORE      (0)
# define OS_ISR_OSISR_MFS_TRANSMIT_CH9_LEVEL     (31)
# define OS_ISR_OSISR_RLT01_1US_1SHOT_DELAY_CORE      (0)
# define OS_ISR_OSISR_RLT01_1US_1SHOT_DELAY_LEVEL     (28)
# define OS_ISR_OSISR_RTC_CORE      (0)
# define OS_ISR_OSISR_RTC_LEVEL     (31)
# define OS_ISR_OSISR_SYSTEMTIMER_CORE      (0)
# define OS_ISR_OSISR_SYSTEMTIMER_LEVEL     (5)
# define OS_ISR_OSISR_TMEXT_CORE      (0)
# define OS_ISR_OSISR_TMEXT_LEVEL     (31)
# define OS_ISR_OSISR_WDG_TO_CORE      (0)
# define OS_ISR_OSISR_WDG_TO_LEVEL     (23)
# define OS_ISR_OSISR_WDG_TRG_CORE      (0)
# define OS_ISR_OSISR_WDG_TRG_LEVEL     (23)

/* Hardware counter timing macros */






/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_HAL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Cfg.h
 *********************************************************************************************************************/
