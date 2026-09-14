/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2024. Visteon Corporation owns all rights to
 this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right,
 under the copyright laws of the United States or those of any
 other country that may have jurisdiction, to protect this work
 as an unpublished work, in the event of an inadvertent or
 deliberate unauthorized publication. Visteon Corporation also
 reserves its rights under all copyright laws to protect this
 work as a published work, when appropriate. Those having access
 to this work may not copy it, use it, modify it or disclose the
 information contained in it without the written authorization
 of Visteon Corporation.
 * @endverbatim
 * @file        FltM_Soc.c
 * @details     <b> Fault Manager to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */
#ifndef  FLTM_SOC_C_
#define  FLTM_SOC_C_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Soc.h"

#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/* Maps Wkeup/Mcu ESM interrupt sources to fault types and categories */
const FltM_InterruptSourceMap FltM_InterruptSourceMap_Table_WKUP[FLTM_WKUP_ESM_INTERRUPT_MAX] =
{
    /* Each entry maps: {Error Type, Error Category} */
    {FLTM_ERR_ESM, FLTM_SOC_NONE}, /* ESM0_ESM_INT_CFG_LVL_0 = 0 */
    {FLTM_ERR_ESM, FLTM_SOC_NONE}, /* ESM0_ESM_INT_HI_LVL_0  = 1 */
    {FLTM_ERR_ESM, FLTM_SOC_NONE}, /* ESM0_ESM_INT_LOW_LVL_0  = 2 */
    {FLTM_ERR_CBASS, FLTM_SOC_NONE}, /* WKUP_CBASS0_DEFAULT_EXP_0  = 3 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* MCU_R5FSS0_CPU0_ECC_AGGR_0_CPU0_ECC_CORRECTED_LEVEL_0  = 4 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* MCU_R5FSS0_CPU0_ECC_AGGR_0_CPU0_ECC_UNCORRECTED_LEVEL_0 = 5 */
    {FLTM_ERR_GLUELOGIC, FLTM_SOC_NONE}, /* GLUELOGIC_EFUSE_SCAN_GLUE_CRC_ERR_0 = 6 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_0 = 7 */
    {FLTM_ERR_VTM, FLTM_SOC_NONE}, /* WKUP_VTM0_THERM_LVL_GT_TH1_INTR_0 = 8 */
    {FLTM_ERR_VTM, FLTM_SOC_NONE}, /* WKUP_VTM0_THERM_LVL_LT_TH0_INTR_0 = 9 */
    {FLTM_ERR_VTM, FLTM_SOC_NONE}, /* WKUP_VTM0_THERM_LVL_GT_TH2_INTR_0 = 10 */
    {FLTM_ERR_VTM, FLTM_SOC_CORRECTABLE}, /* WKUP_VTM0_CORR_LEVEL_0  = 11*/
    {FLTM_ERR_VTM, FLTM_SOC_UNCORRECTABLE}, /* WKUP_VTM0_UNCORR_LEVEL_0 = 12 */
    {FLTM_ERR_GLUELOGIC, FLTM_SOC_NONE}, /* GLUELOGIC_HFOSC0_CLKLOSS_GLUE_REF_CLK_LOSS_DETECT_OUT_0 = 13 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* MCU_ECC_AGGR0_CORR_LEVEL_0 = 14 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* MCU_ECC_AGGR0_UNCORR_LEVEL_0 = 15 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* MCU_MCAN0_MCANSS_ECC_CORR_LVL_INT_0 = 16 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* MCU_MCAN0_MCANSS_ECC_UNCORR_LVL_INT_0 = 17*/
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* MCU_MCAN1_MCANSS_ECC_CORR_LVL_INT_0 = 18 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* MCU_MCAN1_MCANSS_ECC_UNCORR_LVL_INT_0 = 19*/
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* WKUP_ECC_AGGR2_CORR_LEVEL_0 = 20 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* WKUP_ECC_AGGR2_UNCORR_LEVEL_0 = 21 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_1 = 22 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* WKUP_ECC_AGGR0_CORR_LEVEL_0 = 23 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* WKUP_ECC_AGGR0_UNCORR_LEVEL_0 = 24 */
    {FLTM_ERR_GLUELOGIC, FLTM_SOC_NONE}, /* GLUELOGIC_GLUE_EFC_ERROR_AGGREGATED_ERR_0 = 25 */
    {FLTM_ERR_GLUELOGIC, FLTM_SOC_NONE}, /* GLUELOGIC_MGASKET_INTR_GLUE_OUT_0 = 26 */
    {FLTM_ERR_GLUELOGIC, FLTM_SOC_NONE}, /* GLUELOGIC_SGASKET_INTR_GLUE_OUT_0 = 27 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* MCU_R5FSS0_COMMON0_ECC_DE_TO_ESM_0_0 = 28 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* MCU_R5FSS0_COMMON0_ECC_SE_TO_ESM_0_0 = 29 */
    {FLTM_ERR_MCU, FLTM_SOC_NONE}, /* MCU_R5FSS0_CORE0_CPU0_EXP_INTR_0 = 30 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_2 = 31 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* MCU_MSRAM_256K0_ECC_CORR_LEVEL_0 = 32 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* MCU_MSRAM_256K0_ECC_UNCORR_LEVEL_0 = 33 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* MCU_MSRAM_256K1_ECC_CORR_LEVEL_0 = 34 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* MCU_MSRAM_256K1_ECC_UNCORR_LEVEL_0 = 35 */
    {FLTM_ERR_DCC, FLTM_SOC_NONE}, /* MCU_DCC1_INTR_ERR_LEVEL_0 = 36 */
    {FLTM_ERR_DCC, FLTM_SOC_NONE}, /* MCU_DCC0_INTR_ERR_LEVEL_0 = 37 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* WKUP_ECC_AGGR1_CORR_LEVEL_0 = 38 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* WKUP_ECC_AGGR1_UNCORR_LEVEL_0 = 39 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* MCU_ECC_AGGR1_CORR_LEVEL_0 = 40 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* MCU_ECC_AGGR1_UNCORR_LEVEL_0 = 41 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* WKUP_PSRAMECC_8K0_ECC_CORR_LEVEL_0 = 42 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* WKUP_PSRAMECC_8K0_ECC_UNCORR_LEVEL_0 = 43 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_3 = 44 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_4 = 45 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_5 = 46 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_6 = 47 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_7 = 48 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_8 = 49 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_9 = 50 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD18_LOCKLOSS_IPCFG_0 = 51 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD16_LOCKLOSS_IPCFG_0 = 52 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD6_LOCKLOSS_IPCFG_0 = 53 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD0_LOCKLOSS_IPCFG_0 = 54 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD1_LOCKLOSS_IPCFG_0 = 55 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD2_LOCKLOSS_IPCFG_0 = 56 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD8_LOCKLOSS_IPCFG_0 = 57 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD12_LOCKLOSS_IPCFG_0 = 58 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD15_LOCKLOSS_IPCFG_0 = 59 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD5_LOCKLOSS_IPCFG_0 = 60 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_10 = 61 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD17_LOCKLOSS_IPCFG_0  = 62 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* MCU_PLLFRACF2_SSMOD0_LOCKLOSS_IPCFG_0  = 63 */
    {FLTM_ERR_POK, FLTM_SOC_NONE}, /* MCU_PRG_MCU_5POKS0_POK_PGOOD_OV_OUT_N_TO_ESM_0 = 64 */
    {FLTM_ERR_POK, FLTM_SOC_NONE}, /* MCU_PRG_MCU_5POKS0_POK_PGOOD_OV_OUT_N_TO_ESM_1 = 65 */
    {FLTM_ERR_POK, FLTM_SOC_NONE}, /* MCU_PRG_MCU_5POKS0_POK_PGOOD_OV_OUT_N_TO_ESM_2 = 66 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_11 = 67 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_12 = 68 */
    {FLTM_ERR_POK, FLTM_SOC_NONE}, /* MCU_PRG_MCU_5POKS0_POK_PGOOD_OV_OUT_N_TO_ESM_3 = 69 */
    {FLTM_ERR_POK, FLTM_SOC_NONE}, /* MCU_PRG_MCU_5POKS0_POK_PGOOD_OV_OUT_N_TO_ESM_4 = 70 */
    {FLTM_ERR_POK, FLTM_SOC_NONE}, /* MCU_PRG_MCU_5POKS0_POK_PGOOD_UV_OUT_N_TO_ESM_0 = 71 */
    {FLTM_ERR_POK, FLTM_SOC_NONE}, /* MCU_PRG_MCU_5POKS0_POK_PGOOD_UV_OUT_N_TO_ESM_1 = 72 */
    {FLTM_ERR_POK, FLTM_SOC_NONE}, /* MCU_PRG_MCU_5POKS0_POK_PGOOD_UV_OUT_N_TO_ESM_2 = 73 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_13 = 74 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_14 = 75 */
    {FLTM_ERR_POK, FLTM_SOC_NONE}, /* MCU_PRG_MCU_5POKS0_POK_PGOOD_UV_OUT_N_TO_ESM_3 = 76 */
    {FLTM_ERR_POK, FLTM_SOC_NONE}, /* MCU_PRG_MCU_5POKS0_POK_PGOOD_UV_OUT_N_TO_ESM_4 = 77 */
    {FLTM_ERR_POK, FLTM_SOC_NONE}, /* MCU_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_0 = 78 */
    {FLTM_ERR_POK, FLTM_SOC_NONE}, /* MCU_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_1 = 79 */
    {FLTM_ERR_POK, FLTM_SOC_NONE}, /* MCU_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_2 = 80 */
    {FLTM_ERR_POK, FLTM_SOC_NONE}, /* MCU_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_3 = 81 */
    {FLTM_ERR_POK, FLTM_SOC_NONE}, /* MCU_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_4 = 82 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_15 = 83 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_16 = 84 */
    {FLTM_ERR_RTI, FLTM_SOC_NONE}, /* MCU_RTI0_INTR_WWD_0 = 85*/
    {FLTM_ERR_RTI, FLTM_SOC_NONE}, /* WKUP_RTI0_INTR_WWD_0 = 86*/
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_17 = 87 */
    {FLTM_ERR_GPIOMUX, FLTM_SOC_NONE}, /* WKUP_MCU_GPIOMUX_INTROUTER0_OUTP_8 = 88 */
    {FLTM_ERR_GPIOMUX, FLTM_SOC_NONE}, /* WKUP_MCU_GPIOMUX_INTROUTER0_OUTP_9 = 89 */
    {FLTM_ERR_GPIOMUX, FLTM_SOC_NONE}, /* WKUP_MCU_GPIOMUX_INTROUTER0_OUTP_10 = 90 */
    {FLTM_ERR_GPIOMUX, FLTM_SOC_NONE}, /* WKUP_MCU_GPIOMUX_INTROUTER0_OUTP_11 = 91 */
};

/* Maps Main domain ESM interrupt sources to fault types and categories */
const FltM_InterruptSourceMap FltM_InterruptSourceMap_Table_MAIN[FLTM_ESM_INTERRUPT_MAX] =
{
    /* Each entry maps: {Error Type, Error Category} */
    {FLTM_ERR_CSIRX, FLTM_SOC_NONE}, /* CSI_RX_IF0_CSI_ERR_IRQ_0 = 0 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* ECC_AGGR0_UNCORR_LEVEL_0 = 1 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* ECC_AGGR0_CORR_LEVEL_0 = 2 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* CPSW0_ECC_SEC_PEND_0 = 3 */
    {FLTM_ERR_SMS, FLTM_SOC_NONE}, /* SMS0_RAT_0_EXP_INTR_0 = 4 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* MSRAM_64K0_ECC_CORR_LEVEL_0 = 5 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* MSRAM_64K0_ECC_UNCORR_LEVEL_0 = 6 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD17_LOCKLOSS_IPCFG_0 = 7 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* WKUP_PSRAMECC_8K0_ECC_CORR_LEVEL_0 = 8 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* DMASS0_ECC_AGGR_0_ECC_CORRECTED_ERR_LEVEL_0 = 9 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* DMASS0_ECC_AGGR_0_ECC_UNCORRECTED_ERR_LEVEL_0 = 10 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* FSS0_OSPI_0_OSPI_ECC_CORR_LVL_INTR_0 = 11 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* GICSS0_ECC_AGGR_CORR_LEVEL_0 = 12 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* WKUP_PSRAMECC_8K0_ECC_UNCORR_LEVEL_0 = 13 */
    {FLTM_ERR_SMS, FLTM_SOC_NONE}, /* SMS0_RAT_1_EXP_INTR_0 = 14 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* PDMA0_ECC_SEC_PEND_0 = 15 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* MCAN0_MCANSS_ECC_CORR_LVL_INT_0 = 16 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD5_LOCKLOSS_IPCFG_0 = 17 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_0 = 18 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD6_LOCKLOSS_IPCFG_0 = 19 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* WKUP_ECC_AGGR0_CORR_LEVEL_0 = 20 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* WKUP_ECC_AGGR0_UNCORR_LEVEL_0 = 21 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* PSC0_ECC_AGGR_0_FW_CH_BR_ECC_AGGR_CORR_LEVEL_0 = 22 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* PSC0_ECC_AGGR_0_FW_CH_BR_ECC_AGGR_UNCORR_LEVEL_0 = 23 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* A53SS0_ECC_ECCAGGR0_CORRECTED_ERR_LEVEL_0 = 24 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* A53SS0_ECC_ECCAGGR1_CORRECTED_ERR_LEVEL_0 = 25 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* A53SS0_ECC_ECCAGGR_COREPAC_CORRECTED_ERR_LEVEL_0 = 26 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD16_LOCKLOSS_IPCFG_0 = 27 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* PDMA1_ECC_SEC_PEND_0 = 28 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* PSRAMECC0_ECC_CORR_LEVEL_0 = 29 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* WKUP_R5FSS0_CORE0_ECC_CORRECTED_LEVEL_0 = 30 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_1 = 31 */
    {FLTM_ERR_USB, FLTM_SOC_NONE}, /* USB0_HOST_SYSTEM_ERROR_0 = 32 */
    {FLTM_ERR_USB, FLTM_SOC_NONE}, /* USB1_HOST_SYSTEM_ERROR_0 = 33 */
    {FLTM_ERR_MMCSD, FLTM_SOC_CORRECTABLE}, /* MMCSD2_EMMCSDSS_RXMEM_CORR_ERR_LVL_0 = 34 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* USB0_A_ECC_AGGR_CORRECTED_ERR_LEVEL_0 = 35 */
    {FLTM_ERR_MMCSD, FLTM_SOC_UNCORRECTABLE}, /* MMCSD2_EMMCSDSS_RXMEM_UNCORR_ERR_LVL_0 = 36 */
    {FLTM_ERR_WKUP_ESM0, FLTM_SOC_NONE}, /* WKUP_ESM0_ESM_INT_CFG_LVL_0  = 37 */
    {FLTM_ERR_WKUP_ESM0, FLTM_SOC_NONE}, /* WKUP_ESM0_ESM_INT_HI_LVL_0  = 38 */
    {FLTM_ERR_WKUP_ESM0, FLTM_SOC_NONE}, /* WKUP_ESM0_ESM_INT_LOW_LVL_0 = 39 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* WKUP_R5FSS0_COMMON0_ECC_DE_TO_ESM_0_0 = 40 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_2 = 41 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* WKUP_R5FSS0_COMMON0_ECC_SE_TO_ESM_0_0 = 42 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD18_LOCKLOSS_IPCFG_0 = 43 */
    {FLTM_ERR_PBIST, FLTM_SOC_NONE}, /* COMPUTE_CLUSTER0_PBIST_0_DFT_PBIST_SAFETY_ERROR_0 = 44 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* A53SS0_ECC_ECCAGGR2_CORRECTED_ERR_LEVEL_0 = 45 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* A53SS0_ECC_ECCAGGR2_UNCORRECTED_ERR_LEVEL_0 = 46 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* A53SS0_ECC_ECCAGGR3_CORRECTED_ERR_LEVEL_0 = 47 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* A53SS0_ECC_ECCAGGR3_UNCORRECTED_ERR_LEVEL_0 = 48 */
    {FLTM_ERR_MMCSD, FLTM_SOC_NONE}, /* MMCSD2_EMMCSDSS_TXMEM_CORR_ERR_LVL_0 = 49 */
    {FLTM_ERR_SMS, FLTM_SOC_NONE}, /* SMS0_DMTIMER_0_INTR_PEND_0 = 50 */
    {FLTM_ERR_SMS, FLTM_SOC_NONE}, /* SMS0_DMTIMER_1_INTR_PEND_0 = 51 */
    {FLTM_ERR_SMS, FLTM_SOC_NONE}, /* SMS0_DMTIMER_2_INTR_PEND_0 = 52 */
    {FLTM_ERR_SMS, FLTM_SOC_NONE}, /* SMS0_DMTIMER_3_INTR_PEND_0 = 53 */
    {FLTM_ERR_MMCSD, FLTM_SOC_CORRECTABLE}, /* MMCSD0_EMMCSDSS_RXMEM_CORR_ERR_LVL_0 = 54 */
    {FLTM_ERR_MMCSD, FLTM_SOC_UNCORRECTABLE}, /* MMCSD0_EMMCSDSS_RXMEM_UNCORR_ERR_LVL_0 = 55 */
    {FLTM_ERR_MMCSD, FLTM_SOC_CORRECTABLE}, /* MMCSD0_EMMCSDSS_TXMEM_CORR_ERR_LVL_0 = 56 */
    {FLTM_ERR_MMCSD, FLTM_SOC_UNCORRECTABLE}, /* MMCSD0_EMMCSDSS_TXMEM_UNCORR_ERR_LVL_0 = 57 */
    {FLTM_ERR_MMCSD, FLTM_SOC_CORRECTABLE}, /* MMCSD1_EMMCSDSS_RXMEM_CORR_ERR_LVL_0 = 58 */
    {FLTM_ERR_MMCSD, FLTM_SOC_UNCORRECTABLE}, /* MMCSD1_EMMCSDSS_RXMEM_UNCORR_ERR_LVL_0 = 59 */
    {FLTM_ERR_MMCSD, FLTM_SOC_CORRECTABLE}, /* MMCSD1_EMMCSDSS_TXMEM_CORR_ERR_LVL_0 = 60 */
    {FLTM_ERR_MMCSD, FLTM_SOC_UNCORRECTABLE}, /* MMCSD1_EMMCSDSS_TXMEM_UNCORR_ERR_LVL_0 = 61 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* DMASS1_ECC_AGGR_0_ECC_UNCORRECTED_ERR_LEVEL_0 = 62 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* DMASS1_ECC_AGGR_0_ECC_CORRECTED_ERR_LEVEL_0 = 63 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_3 = 64 */
    {FLTM_ERR_MMCSD, FLTM_SOC_UNCORRECTABLE}, /* MMCSD2_EMMCSDSS_TXMEM_UNCORR_ERR_LVL_0 = 65 */
    {FLTM_ERR_CSIRX, FLTM_SOC_NONE}, /* CSI_RX_IF0_CORR_LEVEL_0 = 66 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* CPSW0_ECC_DED_PEND_0 = 67 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* MCAN1_MCANSS_ECC_CORR_LVL_INT_0 = 68 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* MCAN1_MCANSS_ECC_UNCORR_LVL_INT_0 = 69 */
    {FLTM_ERR_CSIRX, FLTM_SOC_NONE}, /* CSI_RX_IF0_CSI_FATAL_0 = 70 */
    {FLTM_ERR_CSIRX, FLTM_SOC_NONE}, /* CSI_RX_IF0_CSI_NONFATAL_0 = 71 */
    {FLTM_ERR_CSIRX, FLTM_SOC_NONE}, /* CSI_RX_IF0_CSI_LEVEL_0 = 72 */
    {FLTM_ERR_DCC, FLTM_SOC_NONE}, /* DCC7_INTR_ERR_LEVEL_0 = 73 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* FSS0_OSPI_0_OSPI_ECC_UNCORR_LVL_INTR_0 = 74 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* GICSS0_ECC_AGGR_UNCORR_LEVEL_0 = 75 */
    {FLTM_ERR_PSC, FLTM_SOC_NONE}, /* PSC0_FW_0_FW_CH_BR_DEFAULT_EXP_0 = 76 */
    {FLTM_ERR_CSIRX, FLTM_SOC_UNCORRECTABLE}, /* CSI_RX_IF0_UNCORR_LEVEL_0 = 77 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* MCAN0_MCANSS_ECC_UNCORR_LVL_INT_0 = 78 */
    {FLTM_ERR_DCC, FLTM_SOC_NONE}, /* DCC6_INTR_ERR_LEVEL_0 = 79 */
    {FLTM_ERR_CBASS, FLTM_SOC_NONE}, /* CBASS_CENTRAL2_DEFAULT_EXP_0 = 80 */
    {FLTM_ERR_RTI, FLTM_SOC_NONE}, /* SMS0_RTI_1_WDG_INTR_0 = 81 */
    {FLTM_ERR_RTI, FLTM_SOC_NONE}, /* SMS0_RTI_1_WDG_INTR_1 = 82 */
    {FLTM_ERR_RTI, FLTM_SOC_NONE}, /* SMS0_RTI_1_WDG_INTR_2 = 83 */
    {FLTM_ERR_RTI, FLTM_SOC_NONE}, /* SMS0_RTI_1_WDG_INTR_3 = 84 */
    {FLTM_ERR_RTI, FLTM_SOC_NONE}, /* SMS0_RTI_1_WDG_INTR_4 = 85 */
    {FLTM_ERR_CBASS, FLTM_SOC_NONE}, /* CBASS0_DEFAULT_EXP_0 = 86 */
    {FLTM_ERR_RTI, FLTM_SOC_NONE}, /* SMS0_RTI_0_WDG_INTR_0 = 87 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* PDMA0_ECC_DED_PEND_0 = 88 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* PDMA1_ECC_DED_PEND_0 = 89 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* PSRAMECC0_ECC_UNCORR_LEVEL_0 = 90 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* WKUP_R5FSS0_CORE0_ECC_UNCORRECTED_LEVEL_0 = 91 */
    {FLTM_ERR_RTI, FLTM_SOC_NONE}, /* SMS0_RTI_0_WDG_INTR_1 = 92 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* A53SS0_ECC_ECCAGGR1_UNCORRECTED_ERR_LEVEL_0 = 93 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* A53SS0_ECC_ECCAGGR0_UNCORRECTED_ERR_LEVEL_0 = 94 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* A53SS0_ECC_ECCAGGR_COREPAC_UNCORRECTED_ERR_LEVEL_0 = 95 */
    {FLTM_ERR_RTI, FLTM_SOC_NONE}, /* SMS0_RTI_0_WDG_INTR_2 = 96 */
    {FLTM_ERR_RTI, FLTM_SOC_NONE}, /* SMS0_RTI_0_WDG_INTR_3 = 97 */
    {FLTM_ERR_DFTSS, FLTM_SOC_NONE}, /* DFTSS0_DFT_SAFETY_123_0 = 98 */
    {FLTM_ERR_DFTSS, FLTM_SOC_NONE}, /* DFTSS0_DFT_SAFETY_MULTI_0 = 99 */
    {FLTM_ERR_DFTSS, FLTM_SOC_NONE}, /* DFTSS0_DFT_SAFETY_ONE_0 = 100 */
    {FLTM_ERR_MCU, FLTM_SOC_NONE}, /* MCU_MCU0_VDD_CORE_GLDTC_STAT_THRESH_HI_FLAG_IPCFG_0 = 101 */
    {FLTM_ERR_MCU, FLTM_SOC_NONE}, /* MCU_MCU0_VDD_CORE_GLDTC_STAT_THRESH_LOW_FLAG_IPCFG_0 = 102 */
    {FLTM_ERR_RTI, FLTM_SOC_NONE}, /* SMS0_RTI_0_WDG_INTR_4 = 103 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* WKUP_ECC_AGGR1_CORR_LEVEL_0 = 104 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* WKUP_ECC_AGGR1_UNCORR_LEVEL_0 = 105 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_4 = 106 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_5 = 107 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* PSRAMECC1_ECC_CORR_LEVEL_0 = 108 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* PSRAMECC1_ECC_UNCORR_LEVEL_0 = 109 */
    {FLTM_ERR_CBASS, FLTM_SOC_NONE}, /* CBASS_IPCSS0_DEFAULT_EXP_0 = 110 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* USB0_A_ECC_AGGR_UNCORRECTED_ERR_LEVEL_0 = 111 */
    {FLTM_ERR_DCC, FLTM_SOC_NONE}, /* DCC0_INTR_ERR_LEVEL_0 = 112 */
    {FLTM_ERR_DCC, FLTM_SOC_NONE}, /* DCC1_INTR_ERR_LEVEL_0 = 113 */
    {FLTM_ERR_DCC, FLTM_SOC_NONE}, /* DCC2_INTR_ERR_LEVEL_0 = 114 */
    {FLTM_ERR_DCC, FLTM_SOC_NONE}, /* DCC3_INTR_ERR_LEVEL_0 = 115 */
    {FLTM_ERR_DCC, FLTM_SOC_NONE}, /* DCC4_INTR_ERR_LEVEL_0 = 116 */
    {FLTM_ERR_DCC, FLTM_SOC_NONE}, /* DCC5_INTR_ERR_LEVEL_0 = 117 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* SA3_SS0_DMSS_ECCAGGR_0_DMSS_ECC_DED_PEND_0 = 118 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* SA3_SS0_DMSS_ECCAGGR_0_DMSS_ECC_SEC_PEND_0 = 119 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* SA3_SS0_SA_UL_0_SA_UL_ECC_CORR_LEVEL_0 = 120 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* SA3_SS0_SA_UL_0_SA_UL_ECC_UNCORR_LEVEL_0 = 121 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_6 = 122 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_7 = 123 */
    {FLTM_ERR_WKUP_R5FSS, FLTM_SOC_NONE}, /* WKUP_R5FSS0_CORE0_EXP_INTR_0 = 124 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_8 = 125 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_9 = 126 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_10 = 127 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD0_LOCKLOSS_IPCFG_0 = 128 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD1_LOCKLOSS_IPCFG_0 = 129 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD2_LOCKLOSS_IPCFG_0 = 130 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD8_LOCKLOSS_IPCFG_0 = 131 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD12_LOCKLOSS_IPCFG_0 = 132 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* PLLFRACF2_SSMOD15_LOCKLOSS_IPCFG_0 = 133 */
    {FLTM_ERR_PLLFRACF2, FLTM_SOC_NONE}, /* MCU_PLLFRACF2_SSMOD0_LOCKLOSS_IPCFG_0 = 134 */
    {FLTM_ERR_GLUELOGIC, FLTM_SOC_NONE}, /* GLUELOGIC_HFOSC0_CLKLOSS_GLUE_REF_CLK_LOSS_DETECT_OUT_0 = 135 */
    {FLTM_ERR_VTM, FLTM_SOC_NONE}, /* WKUP_VTM0_THERM_LVL_LT_TH0_INTR_0 = 136 */
    {FLTM_ERR_VTM, FLTM_SOC_NONE}, /* WKUP_VTM0_THERM_LVL_GT_TH1_INTR_0 = 137 */
    {FLTM_ERR_VTM, FLTM_SOC_NONE}, /* WKUP_VTM0_THERM_LVL_GT_TH2_INTR_0 = 138 */
    {FLTM_ERR_VTM, FLTM_SOC_NONE}, /* WKUP_VTM0_CORR_LEVEL_0 = 139 */
    {FLTM_ERR_VTM, FLTM_SOC_NONE}, /* WKUP_VTM0_UNCORR_LEVEL_0 = 140 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* FSS0_FSAS_0_ECC_INTR_ERR_PEND_0 = 141 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* DSS_DSI0_ECC_INTR_UNCORR_LEVEL_SYS_0 = 142 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOOWN_11 = 143 */
    {FLTM_ERR_A53SS, FLTM_SOC_NONE}, /* A53SS0_EXTERRIRQ_0 = 144 */
    {FLTM_ERR_A53SS, FLTM_SOC_NONE}, /* A53SS0_INTERRIRQ_0 = 145 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* USB1_A_ECC_AGGR_CORRECTED_ERR_LEVEL_0 = 146 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* USB1_A_ECC_AGGR_UNCORRECTED_ERR_LEVEL_0 = 147 */
    {FLTM_ERR_PBIST, FLTM_SOC_NONE}, /* PBIST3_K3_PBIST_8C28P_4BIT_WRAP__DFT_PBIST_SAFETY_ERROR_0 = 148 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOOWN_12 = 149 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* SMS0_HSM_ECC_AGGR_0_ECC_CORRECTED_LEVEL_0 = 150 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* SMS0_HSM_ECC_AGGR_0_ECC_UNCORRECTED_LEVEL_0 = 151 */
    {FLTM_ERR_PBIST, FLTM_SOC_NONE}, /* MCU_PBIST0_DFT_PBIST_SAFETY_ERROR_0 = 152 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* SMS0_TIFS_ECC_AGGR_0_ECC_CORRECTED_LEVEL_0 = 153 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* SMS0_TIFS_ECC_AGGR_0_ECC_UNCORRECTED_LEVEL_0 = 154 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_13 = 155 */
    {FLTM_ERR_PBIST, FLTM_SOC_NONE}, /* GPU0_DFT_PBIST_SAFETY_ERROR_0 = 156 */
    {FLTM_ERR_PBIST, FLTM_SOC_NONE}, /* PBIST0_DFT_PBIST_SAFETY_ERROR_0 = 157 */
    {FLTM_ERR_PBIST, FLTM_SOC_NONE}, /* WKUP_PBIST0_DFT_PBIST_SAFETY_ERROR_0 = 158 */
    {FLTM_ERR_PBIST, FLTM_SOC_NONE}, /* WKUP_PBIST1_DFT_PBIST_SAFETY_ERROR_0 = 159 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_14 = 160 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_15 = 161 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_16 = 162 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_17 = 163 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_18 = 164 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_19 = 165 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_20 = 166 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_21 = 167 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_22 = 168 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_23 = 169 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_24 = 170 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_25 = 171 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_26 = 172 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_27 = 173 */
    {FLTM_ERR_ECC_1BIT, FLTM_SOC_CORRECTABLE}, /* DDR32SS0_DDRSS_DRAM_ECC_CORR_ERR_LVL_0 = 174 */
    {FLTM_ERR_ECC_2BIT, FLTM_SOC_UNCORRECTABLE}, /* DDR32SS0_DDRSS_DRAM_ECC_UNCORR_ERR_LVL_0 = 175 */
    {FLTM_ERR_DDR32SS, FLTM_SOC_NONE}, /* DDR32SS0_DDRSS_V2A_OTHER_ERR_LVL_0 = 176 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_28 = 177 */
    {FLTM_ERR_DSS, FLTM_SOC_NONE}, /* DSS_DSI0_DSI_0_SAFETY_ERROR_FATAL_INTR_0 = 178 */
    {FLTM_ERR_DSS, FLTM_SOC_NONE}, /* DSS_DSI0_DSI_0_SAFETY_ERROR_NONFATAL_INTR_0 = 179 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_29 = 180 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_30 = 181 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_31 = 182 */
    {FLTM_ERR_CBASS, FLTM_SOC_NONE}, /* WKUP_CBASS0_DEFAULT_EXP_0 = 183 */
    {FLTM_ERR_GPU, FLTM_SOC_NONE}, /* GPU0_GPU_SAFETY_IRQ_0 = 184 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_32 = 185 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_33 = 186 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_34 = 187 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_35 = 188 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_36 = 189 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_37 = 190 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_38 = 191 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_39 = 192 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_40 = 193 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_41 = 194 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_42 = 195 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_43 = 196 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_44 = 197 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_45 = 198 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_46 = 199 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_47 = 200 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_48 = 201 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_49 = 202 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_50 = 203 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_51 = 204 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_52 = 205 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_53 = 206 */
    {FLTM_ERR_PBIST, FLTM_SOC_NONE}, /* PBIST1_DFT_PBIST_SAFETY_ERROR_0 = 207 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_54 = 208 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_55 = 209 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_56 = 210 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_57 = 211 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_58 = 212 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_59 = 213 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_60 = 214 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_61 = 215 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_62 = 216 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_63 = 217 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_64 = 218 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_65 = 219 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_66 = 220 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_67 = 221 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_68 = 222 */
    {FLTM_ERR_DCC, FLTM_SOC_NONE}, /* DCC8_INTR_ERR_LEVEL_0 = 223 */
    {FLTM_ERR_RTI, FLTM_SOC_NONE}, /* RTI0_INTR_WWD_0 = 224 */
    {FLTM_ERR_RTI, FLTM_SOC_NONE}, /* RTI1_INTR_WWD_0 = 225 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_69 = 226 */
    {FLTM_ERR_RTI, FLTM_SOC_NONE}, /* WKUP_RTI0_INTR_WWD_0 = 227 */
    {FLTM_ERR_PBIST, FLTM_SOC_NONE}, /* PBIST0_DFT_PBIST_CPU_0 = 228 */
    {FLTM_ERR_PBIST, FLTM_SOC_NONE}, /* PBIST1_DFT_PBIST_CPU_0 = 229 */
    {FLTM_ERR_GICSS, FLTM_SOC_NONE}, /* GICSS0_AXIM_ERR_0 = 230 */
    {FLTM_ERR_GICSS, FLTM_SOC_NONE}, /* GICSS0_ECC_FATAL_0 = 231 */
    {FLTM_ERR_PBIST, FLTM_SOC_NONE}, /* PBIST3_K3_PBIST_8C28P_4BIT_WRAP__DFT_PBIST_CPU_0 = 232 */
    {FLTM_ERR_PBIST, FLTM_SOC_NONE}, /* WKUP_PBIST1_DFT_PBIST_CPU_0 = 233 */
    {FLTM_ERR_PBIST, FLTM_SOC_NONE}, /* WKUP_PBIST0_DFT_PBIST_CPU_0 = 234 */
    {FLTM_ERR_PBIST, FLTM_SOC_NONE}, /* MCU_PBIST0_DFT_PBIST_CPU_0 = 235 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_70 = 236 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_71 = 237 */
    {FLTM_ERR_PBIST, FLTM_SOC_NONE}, /* GPU0_DFT_PBIST_CPU_0 = 238 */
    {FLTM_ERR_UNKNOWN, FLTM_SOC_NONE}, /* UNKNOWN_72 = 239 */
    {FLTM_ERR_PBIST, FLTM_SOC_NONE}, /* COMPUTE_CLUSTER0_PBIST_0_DFT_PBIST_CPU_0 = 240 */
    {FLTM_ERR_RTI, FLTM_SOC_NONE}, /* RTI2_INTR_WWD_0 = 241 */
    {FLTM_ERR_RTI, FLTM_SOC_NONE}, /* RTI3_INTR_WWD_0 = 242 */
};


/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/
/* DPL interface function */
uint32  FLTM_EnableInterrupt(uint32 intNum);
uint32  FLTM_DisableInterrupt(uint32 intNum);
pSDL_DPL_HwipHandle FLTM_registerInterrupt(const SDL_DPL_HwipParams *pParams);
uint32 FLTM_deregisterInterrupt(pSDL_DPL_HwipHandle handle);
void FLTM_Clocksleep(uint32 sec);
void* FltM_addrTranslate(uint64 addr, uint32 size);

/*****************************************************************************
*                                 Static Variables                           *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable:                                                       *
* purpose           : Interface structure for SDL DPL functions              *
* critical section : No                                                      *
* unit             : N/A                                                    *
* resolution       : N/A                                                    *
******************************************************************************/
static SDL_DPL_Interface dpl_interface =
{
    .enableInterrupt = (pSDL_DPL_InterruptFunction) FLTM_EnableInterrupt,
    .disableInterrupt = (pSDL_DPL_InterruptFunction) FLTM_DisableInterrupt,
    .registerInterrupt = (pSDL_DPL_RegisterFunction) FLTM_registerInterrupt,
    .deregisterInterrupt = (pSDL_DPL_DeregisterFunction) FLTM_deregisterInterrupt,
    .delay = (pSDL_DPL_DelayFunction) FLTM_Clocksleep,
    .addrTranslate = (pSDL_DPL_AddrTranslateFunction) FltM_addrTranslate
};

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
/*****************************************************************************
*                               Functions                                    *
******************************************************************************/
/*============================================================================
**
** Function Name    :   FltM_Soc_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global
**                      and Static variables of this module.
**
** Invocation       :   FltM.c
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_Soc_Init(void)
{
    Std_ReturnType flRetVal = E_OK;
    uint8 flIndex = 0;
    uint32 flResult;
    uint32 flApparg;

    (void)SDL_DPL_init(&dpl_interface);

    for(flIndex = 0; flIndex < FLTM_ESM_INSTANCE_MAX; flIndex++)
    {
        flResult = SDL_ESM_init(FltM_ErrConfig[flIndex].Instance, &FltM_ErrConfig[flIndex].SDL_ESMConfig, FltM_ErrConfig[flIndex].SDL_ESM_applicationCallbackFun, &flApparg);
        if(flResult != 0u)
        {
            flRetVal = E_NOT_OK;
        }
    }
    #if(FLTM_PPU_ENABLE == STD_ON)
    /* Enable PPU Firewall */
    if(flRetVal == E_OK)
    {
        flRetVal = FltM_Ppu_Init();
    }
    #endif
    #if(FLTM_ECC_ENABLE == STD_ON)
    /* Enable ECC */
    if(flRetVal == E_OK)
    {
        flRetVal = FltM_ECC_Init_All();
    }
    #endif
    #if(FLTM_POK_ENABLE == STD_ON)
    /* Enable POK monitoring */
    if(flRetVal == E_OK)
    {
        FltM_POK_Init();
    }
    #endif
    #if(FLTM_OCOCLKDET_ENABLE == STD_ON)
    /* Enable Oscillator Clock Loss Detection */
    if(flRetVal == E_OK)
    {
        FltM_OscClkLossDetection_Enable();
    }
    #endif
    #if(FLTM_DCC_ENABLE == STD_ON)
    /* Enable DCC */
    if(flRetVal == E_OK)
    {
        flRetVal = FltM_Dcc_Init();
    }
    #endif
    #if(FLTM_FLSINTEGRITY_ENABLE == STD_ON)
    /* Enable Flash Integrity*/
    if(flRetVal == E_OK)
    {
        flRetVal = FltM_FlashIntegrity_Init();
    }
    #endif
    #if (FLTM_PERIODICREADBACK_ENABLE_DIO == STD_ON) || \
        (FLTM_PERIODICREADBACK_ENABLE_SPI == STD_ON) || \
        (FLTM_PERIODICREADBACK_ENABLE_GPT == STD_ON) || \
        (FLTM_PERIODICREADBACK_ENABLE_ETH == STD_ON) || \
        (FLTM_PERIODICREADBACK_ENABLE_ESM == STD_ON) || \
        (FLTM_PERIODICREADBACK_ENABLE_VIM == STD_ON) || \
        (FLTM_PERIODICREADBACK_ENABLE_DDR == STD_ON) || \
        (FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
    if(flRetVal == E_OK)
    {
        flRetVal = FltM_Soc_PeriodicReadBack_Init();
    }
    #endif
    return flRetVal;
}
/*============================================================================
**
** Function Name    :   FltM_Soc_MainFunction
**
** Visibility       :   Public
**
** Description      :   MainFunction Implementation .
**
** Invocation       :   FltM.c
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
Std_ReturnType FltM_Soc_MainFunction(void)
{

    Std_ReturnType retval = E_OK;
    #if(FLTM_DCC_ENABLE == STD_ON)
    static uint8 MainFuncCtr_dcc = 0;
    #endif
    #if(FLTM_ECC_ENABLE == STD_ON)
    static uint8 MainFuncCtr_ecc = 0;
    #endif
    #if(FLTM_PPU_ENABLE == STD_ON)
    static uint8 MainFuncCtr_ppu = 0;
    #endif
    static boolean fl_retval = FALSE;
    (void)fl_retval;

    #if(FLTM_DCC_ENABLE == STD_ON)
        /* Counter to track the periodicity of DCC */
        if(MainFuncCtr_dcc < 0xFFU)
        {
            MainFuncCtr_dcc++;
        }
        /* Limit reached? */
        if(MainFuncCtr_dcc == FLTM_DCC_READBACK_PERIODICITY)
        {
            /* Reset the counter */
            MainFuncCtr_dcc = 0;
            /* DCC Readback Verification */
            retval = FltM_DCC_ReadBack();
            /* Report Reset since the SM fails*/
            if(retval == E_NOT_OK)
            {
                /* Report Safe Action */
                // intSrc = 0xAAu as this a periodic check and not a failure from ESM
                FltM_ReportError(FLTM_ERR_CBK_WKUP_DOMIAN, FLTM_DCC_ERROR, 0xAAu);
            }
        }
    #endif /* #if(FLTM_DCC_ENABLE == STD_ON) */
    #if(FLTM_ECC_ENABLE == STD_ON)
        /* Counter to track the periodicity of ECC */
        MainFuncCtr_ecc++;
        /* Limit reached? */
        if(MainFuncCtr_ecc == FLTM_ECC_READBACK_PERIODICITY)
        {
            /* Reset the counter */
            MainFuncCtr_ecc = 0;
            /* ECC Readback Verification */
            retval = FltM_ECC_ReadBack();

            /* Report Reset since the SM fails*/
            if(retval == E_NOT_OK)
            {
                /* Report Safe Action */
                // intSrc = 0xAAu as this a periodic check and not a failure from ESM
                FltM_ReportError(FLTM_ERR_CBK_WKUP_DOMIAN, FLTM_ECC_ERROR, 0xAAu);
            }
        }
    #endif /* #if(FLTM_ECC_ENABLE == STD_ON) */
    #if(FLTM_PPU_ENABLE == STD_ON)
        /* Counter to track the periodicity of ECC */
        MainFuncCtr_ppu++;
        /* Limit reached? */
        if(MainFuncCtr_ppu == FLTM_PPU_READBACK_PERIODICITY)
        {
            /* Reset the counter */
            MainFuncCtr_ppu = 0;
            /* ECC Readback Verification */
            retval = FltM_PPU_ReadBack();

            /* Report Reset since the SM fails*/
            if(retval == E_NOT_OK)
            {
                /* Report Safe Action */
                // intSrc = 0xAAu as this a periodic check and not a failure from ESM
                FltM_ReportError(FLTM_ERR_CBK_WKUP_DOMIAN, FLTM_PPU_ERROR, 0xAAu);
            }
        }
    #endif /* #if(FLTM_PPU_ENABLE == STD_ON) */
    #if (FLTM_PERIODICREADBACK_ENABLE_DIO == STD_ON) || \
        (FLTM_PERIODICREADBACK_ENABLE_SPI == STD_ON) || \
        (FLTM_PERIODICREADBACK_ENABLE_GPT == STD_ON) || \
        (FLTM_PERIODICREADBACK_ENABLE_ETH == STD_ON) || \
        (FLTM_PERIODICREADBACK_ENABLE_ESM == STD_ON) || \
        (FLTM_PERIODICREADBACK_ENABLE_VIM == STD_ON) || \
        (FLTM_PERIODICREADBACK_ENABLE_DDR == STD_ON) || \
        (FLTM_PERIODICREADBACK_ENABLE_R5F == STD_ON)
        /* Advance one periodic static-register readback state per 10 ms call. */
        retval = FltM_Soc_Periodic_Reg_ReadBack();
        if(retval == E_NOT_OK)
        {
            /* 0xAAU identifies a periodic diagnostic rather than an ESM source. */
            FltM_ReportError(FLTM_ERR_CBK_WKUP_DOMIAN,
                             FLTM_PERIODIC_READBACK_ERROR,
                             0xAAU);
        }
    #endif
    #if (FLTM_FLSINTEGRITY_ENABLE == STD_ON) && (FLASH_INTEGRITY_CHECKSUMCALCULATE_TYPE == RUNNABLE_METHOD)
        if (fl_retval == FALSE)
        {
            fl_retval = FltM_FlashIntegrity();
        }
    #endif
    return retval;
}

/*****************************************************************************
*                             Interrupt Handlers                             *
******************************************************************************/

/*============================================================================
**
** Function Name    :   FltM_HiInterruptHandler
**
** Visibility       :   Public
**
** Description      :   Handles high priority ESM interrupts from the system
**                      and processes them through SDL ESM handler
**
** Invocation       :   Interrupt Service
**
** Inputs           :   arg - ESM instance identifier
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void FltM_HiInterruptHandler(uint8 arg)
{
    SDL_ESM_hiInterruptHandler((void*) (uint32) arg);

}

/*============================================================================
**
** Function Name    :   FltM_LowInterruptHandler
**
** Visibility       :   Public
**
** Description      :   Handles low priority ESM interrupts from the system
**                      and processes them through SDL ESM handler
**
** Invocation       :   Interrupt Service
**
** Inputs           :   arg - ESM instance identifier
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void FltM_LowInterruptHandler(uint8 arg)
{
    SDL_ESM_loInterruptHandler((void*) (uint32) arg);

}

/*============================================================================
**
** Function Name    :   FltM_CfgInterruptHandler
**
** Visibility       :   Public
**
** Description      :   Handles configuration related ESM interrupts from the
**                      system and processes them through SDL ESM handler
**
** Invocation       :   Interrupt Service
**
** Inputs           :   arg - ESM instance identifier
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void FltM_CfgInterruptHandler(uint8 arg)
{
    SDL_ESM_configInterruptHandler((void*) (uint32) arg);
}

//FltM Interface related APIs
/* These APIs are similar as TI SDL uses NORTOS and initialises the interrupt and we have used mos for the same. Since SDL_ESM files have dpl calls,
the bwlow APIs are implemented */

/*============================================================================
**
** Function Name    :   FLTM_EnableInterrupt
**
** Visibility       :   Private
**
** Description      :   Enables the specified ESM interrupt number
**
** Invocation       :   SDL DPL Interface
**
** Inputs           :   intNum - Interrupt number to enable
**
** Outputs          :   FLTM_PASS/FLTM_FAIL
**
** Critical Section :   No
**
**==========================================================================*/
uint32  FLTM_EnableInterrupt(uint32 intNum)
{
    uint32 flRetVal = FLTM_FAIL;
    if(intNum < FLTM_ESM_INTERRUPT_MAX)
    {
        flRetVal = FLTM_PASS;
    }

    return flRetVal;
}

/*============================================================================
**
** Function Name    :   FLTM_DisableInterrupt
**
** Visibility       :   Private
**
** Description      :   Disables the specified ESM interrupt number
**
** Invocation       :   SDL DPL Interface
**
** Inputs           :   intNum - Interrupt number to disable
**
** Outputs          :   FLTM_PASS/FLTM_FAIL
**
** Critical Section :   No
**
**==========================================================================*/
uint32  FLTM_DisableInterrupt(uint32 intNum)
{
    uint32 flRetVal = FLTM_FAIL;
    if(intNum < FLTM_ESM_INTERRUPT_MAX)
    {
        flRetVal = FLTM_PASS;
    }
    return flRetVal;
}

/*============================================================================
**
** Function Name    :   FLTM_registerInterrupt
**
** Visibility       :   Private
**
** Description      :   Registers an interrupt handler with the system
**
** Invocation       :   SDL DPL Interface
**
** Inputs           :   pParams - Pointer to interrupt parameters
**
** Outputs          :   Handle to registered interrupt
**
** Critical Section :   No
**
**==========================================================================*/
pSDL_DPL_HwipHandle FLTM_registerInterrupt(const SDL_DPL_HwipParams *pParams)
{
    pSDL_DPL_HwipHandle handle = NULL;
    if(pParams != NULL)
    {
        handle = NULL;
    }
    return handle;
}

/*============================================================================
**
** Function Name    :   FLTM_deregisterInterrupt
**
** Visibility       :   Private
**
** Description      :   Deregisters a previously registered interrupt handler
**
** Invocation       :   SDL DPL Interface
**
** Inputs           :   handle - Handle of interrupt to deregister
**
** Outputs          :   FLTM_PASS/FLTM_FAIL
**
** Critical Section :   No
**
**==========================================================================*/
uint32 FLTM_deregisterInterrupt(pSDL_DPL_HwipHandle handle)
{
    uint32 flRetVal = FLTM_FAIL;
    if(handle != NULL)
    {
        flRetVal = FLTM_PASS;
    }
    return flRetVal;
}

/*============================================================================
**
** Function Name    :   FLTM_Clocksleep
**
** Visibility       :   Private
**
** Description      :   Implements delay functionality in seconds
**
** Invocation       :   SDL DPL Interface
**
** Inputs           :   sec - Number of seconds to delay
**
** Outputs          :   None
**
** Critical Section :   No
**
**==========================================================================*/
void FLTM_Clocksleep(uint32 sec)
{
    (void)sec;
}

/*============================================================================
**
** Function Name    :   FltM_addrTranslate
**
** Visibility       :   Private
**
** Description      :   Translates 64-bit address to 32-bit address space
**
** Invocation       :   SDL DPL Interface
**
** Inputs           :   addr - 64-bit address to translate
**                      size - Size of memory region
**
** Outputs          :   Translated 32-bit address as void pointer
**
** Critical Section :   No
**
**==========================================================================*/
void* FltM_addrTranslate(uint64 addr, uint32 size)
{
    uint32_t transAddr = addr;
    return (void *)transAddr;
}

#define FLTM_SEC_CODE_STOP
#define FLTM_CORE_CONST_SEC_END
#define FLTM_CORE_DATA_SEC_END
#define FLTM_CORE_BSS_SEC_END

#include "MemMap.h"

#endif
/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/*----------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :22-Apr-2025
By                :RRAJAGO2
Traceability      :PE4TI29141-7898
Change Description:DCC Implementation
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              :20-May-2025
By                :KPALANIV
Traceability      :PE4TI29141-8297
Change Description:POK Implementation
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :02-Jun-2025
By                :RRAJAGO2
Traceability      :PE4TI29141-8501
Change Description:PPU Implementation
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :25-June-2025
By                :KPALANIV
Traceability      :PE4TI29141-8948
Change Description:POK init and ECC readback Implementation
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :5-Aug-2025
By                :KPORKODI
Traceability      :PE4TI29141-9645
Change Description:Flash Integrity Implementation
-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
Date              :13-Aug-2025
By                :RRAJAGO2
Traceability      :PE4TI29141-9628
Change Description:Clock Seedvalue calculation and update
-----------------------------------------------------------------------------*/
