/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2025. Visteon Corporation owns all rights to
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
 * @file        Ecc_Cfg.h
 * @details     <b> Ecc to handle TI SDL - ESM </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */

 #ifndef  FLTM_SOC_ECC_CFG_H_
 #define  FLTM_SOC_ECC_CFG_H_

 /*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "sdl_ecc.h"
#include "sdl_types.h"
#include "sdl_r5_utils.h"
#include "sdl_esm.h"
#include "sdl_esm_priv.h"
#include "sdl_ecc_core.h"
#include "sdl_ecc_soc.h"

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
#define FLTM_ECC_ENABLE                                                STD_ON

#if(FLTM_ECC_ENABLE == STD_ON)

//#define ENABLE_COMPUTE_CLUSTER0_SAM62A_A53_512KB_WRAP_A53_DUAL_WRAP_CBA_WRAP_A53_DUAL_WRAP_CBA_COREPAC_ECC_AGGR_CORE0
// #define ENABLE_COMPUTE_CLUSTER0_SAM62A_A53_512KB_WRAP_A53_DUAL_WRAP_CBA_WRAP_A53_DUAL_WRAP_CBA_COREPAC_ECC_AGGR_CORE1
// #define ENABLE_COMPUTE_CLUSTER0_SAM62A_A53_512KB_WRAP_A53_DUAL_WRAP_CBA_WRAP_A53_DUAL_WRAP_CBA_COREPAC_ECC_AGGR_CORE2
// #define ENABLE_COMPUTE_CLUSTER0_SAM62A_A53_512KB_WRAP_A53_DUAL_WRAP_CBA_WRAP_A53_DUAL_WRAP_CBA_COREPAC_ECC_AGGR_CORE3
// #define ENABLE_COMPUTE_CLUSTER0_SAM62A_A53_512KB_WRAP_A53_DUAL_WRAP_CBA_WRAP_A53_DUAL_WRAP_CBA_COREPAC_ECC_AGGR_COREPAC
// #define ENABLE_CPSW0_CPSW_3GUSS_AM67_CORE_ECC_CPSW_ECC_AGGR
// #define ENABLE_CSI_RX_IF0_CSI_RX_IF_ECC_AGGR
// #define ENABLE_DMASS0_ECC_AGGR_0
// #define ENABLE_DMASS1_DMSS_CSI_AM62A_ECCAGGR
// #define ENABLE_DSS_DSI0_K3_DSS_DSI_DSI_TOP_ECC_AGGR_SYS
// #define ENABLE_FSS0_FSS_UL_OSPI0_OSPI_WRAP_ECC_AGGR
// #define ENABLE_GICSS0_GIC500SS_1_4_ECC_AGGR
// #define ENABLE_MCAN0_MCANSS_MSGMEM_WRAP_ECC_AGGR
// #define ENABLE_MCAN1_MCANSS_MSGMEM_WRAP_ECC_AGGR
// #define ENABLE_MCU_ECC_AGGR0
// #define ENABLE_MCU_ECC_AGGR1_SAM62A_MCU_PULSAR_UL_ECC_AGGR
// #define ENABLE_MCU_MCAN0_MCANSS_MSGMEM_WRAP_ECC_AGGR
#define ENABLE_MCU_MCAN1_MCANSS_MSGMEM_WRAP_ECC_AGGR
#define ENABLE_MCU_MSRAM_256K0_MSRAM32KX64E_ECC_AGGR
#define ENABLE_MCU_MSRAM_256K1_MSRAM32KX64E_ECC_AGGR
#define ENABLE_MCU_R5FSS0_PULSAR_ULS_CPU0_ECC_AGGR
// #define ENABLE_MMCSD0_EMMC8SS_16FFC_ECC_AGGR_RXMEM
// #define ENABLE_MMCSD0_EMMC8SS_16FFC_ECC_AGGR_TXMEM
// #define ENABLE_MMCSD1_EMMCSD4SS_ECC_AGGR_RXMEM
// #define ENABLE_MMCSD1_EMMCSD4SS_ECC_AGGR_TXMEM
// #define ENABLE_MMCSD2_EMMCSD4SS_ECC_AGGR_RXMEM
// #define ENABLE_MMCSD2_EMMCSD4SS_ECC_AGGR_TXMEM
// #define ENABLE_MSRAM_64K0_MSRAM2KX256E_ECC_AGGR
// #define ENABLE_PDMA0_SAM67_PDMA_SPI_ECCAGGR
// #define ENABLE_PDMA1_SAM62_PDMA_UART_ECCAGGR
// #define ENABLE_PSCSS0_SAM67_MAIN_PSC_WRAP_ECC_AGGR
// #define ENABLE_PSRAMECC0_PSRAM256X32E_ECC_AGGR
// #define ENABLE_PSRAMECC1_PSRAM256X32E_ECC_AGGR
// #define ENABLE_SA3_SS0_SA3SS_AM62A_SA_UL_ECC_AGGR
// #define ENABLE_USB0_USB2SS_16FFC_USB2SS_CORE_ECC_AGGR
// #define ENABLE_USB1_USB2SS_16FFC_USB2SS_CORE_ECC_AGGR
// #define ENABLE_WKUP_ECC_AGGR0
// #define ENABLE_WKUP_ECC_AGGR1
// #define ENABLE_WKUP_ECC_AGGR2
// #define ENABLE_WKUP_PSRAMECC_8K0_PSRAM8KX32E_ECC_AGGR
// #define ENABLE_WKUP_R5FSS0_PULSAR_UL_CPU0_ECC_AGGR
// #define ENABLE_WKUP_VTM0_K3VTM_N16FFC_ECCAGGR
// #define ENABLE_SAM67_SEC_HSM_ECC_AGGR
// #define ENABLE_SA3_SS0_SA3SS_AM62A_DMSS_ECCAGGR

#define NUM_ECC_AGGR_CONFIGS 4u

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/



/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/


/*****************************************************************************
*                               Functions                                    *
******************************************************************************/
#endif /*#if (FLTM_ECC_ENABLE == STD_ON)*/

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
Date              :  11-Mar-2025
By                :  kpalaniv
Traceability      :  PE4TI29141-6707
Change Description:  Initail configurations of ECC
-----------------------------------------------------------------------------*/
