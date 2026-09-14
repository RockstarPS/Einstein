/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2026. Visteon Corporation owns all rights to
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
 * @file        FltM_Soc_Periodic_ReadBack_Cfg.c
 * @details     Configuration source file for Periodic Readback
 *              implementation for AM62P SoC Registers
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : TI AM62Px SOC
 *
 * @copyright   Visteon (c) 2026
 *
 */
#ifndef  FLTM_SOC_PER_RDBK_CFG_C
#define  FLTM_SOC_PER_RDBK_CFG_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Soc_Periodic_ReadBack_Cfg.h"


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

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/


/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/* -------------------------------------------------
 * DIO channels to be monitored
 * ------------------------------------------------- */
#if(FLTM_PERIODICREADBACK_ENABLE_DIO == STD_ON)
const Dio_ChannelType FltM_PeriodicReadBack_DioChannelList [FLTM_PERIODICREADBACK_DIO_NUM_CHANNELS] =
{
    /* PMIC_INT: PMIC nINT service input on MCU_GPIO0_0. */
    DioConf_DioChannel_CAN_TRCV_MCU_MCAN_0,
    /* CONFIG_GPIO0: PMIC watchdog trigger output on MCU_GPIO0_19. */
    DioConf_DioChannel_MCU_GPIO0_B01_Ch19,
    /* DO_SOC_PWR_LATCH: SoC power hold/latch output on GPIO1_5. */
    DioConf_DioChannel_Main_GPIO1_Channel_5,
    /* DO_EN_5V: 5-V power-sequence output on MCU_GPIO0_7. */
    DioConf_DioChannel_MCU_GPIO0_B01_Ch7,
    /* DO_3V3_DISP: display 3.3-V enable output on MCU_GPIO0_22. */
    DioConf_DioChannel_MCU_GPIO0_B01_Ch22,
    /* DO_TFT_BL_EN: TFT backlight enable output on MCU_GPIO0_23. */
    DioConf_DioChannel_MCU_GPIO0_B01_Ch23,
    /* DI_BL_FAULT: backlight fault input on GPIO0_53. */
    DioConf_DioChannel_Main_GPIO0_Channel_53,
    /* DI_IGN_MON: ignition monitor input on GPIO0_90. */
    DioConf_DioChannel_Main_GPIO0_Channel_90
};
#endif /* FLTM_PERIODICREADBACK_ENABLE_DIO */

/* -------------------------------------------------
 * SPI HW units to be monitored
 * ------------------------------------------------- */
#if(FLTM_PERIODICREADBACK_ENABLE_SPI == STD_ON)
const Spi_HWUnitType FltM_PeriodicReadBack_SpiHwUnitList [FLTM_PERIODICREADBACK_SPI_NUM_HWUNITS] =
{
    SPI_UNIT_MCSPI0,
    SPI_UNIT_MCSPI1
};
#endif /* FLTM_PERIODICREADBACK_ENABLE_SPI */

/* -------------------------------------------------
 * GPT channels to be monitored
 * ------------------------------------------------- */
#if(FLTM_PERIODICREADBACK_ENABLE_GPT == STD_ON)
const Gpt_ChannelType FltM_PeriodicReadBack_GptChannelList [FLTM_PERIODICREADBACK_GPT_NUM_CHANNELS] =
{
    GptConf_GptChannelConfiguration_GptChannelConfiguration_AdcTimer
};
#endif /* FLTM_PERIODICREADBACK_ENABLE_GPT */

/* -------------------------------------------------
 * ETH controllers to be monitored
 * ------------------------------------------------- */
#if(FLTM_PERIODICREADBACK_ENABLE_ETH == STD_ON)
const uint8 FltM_PeriodicReadBack_EthCtrlList [FLTM_PERIODICREADBACK_ETH_NUM_CONTROLLERS] =
{
    ETH_CTRL_ID_0
};
#endif /* FLTM_PERIODICREADBACK_ENABLE_ETH */

/* -------------------------------------------------
 * ESM Instances to be monitored
 * ------------------------------------------------- */
#if(FLTM_PERIODICREADBACK_ENABLE_ESM == STD_ON)
const SDL_ESM_Inst FltM_PeriodicReadBack_EsmInstanceList [FLTM_PERIODICREADBACK_ESM_NUM_INSTANCES] =
{
    SDL_ESM_INST_WKUP_ESM0,
    SDL_ESM_INST_MAIN_ESM0
};
#endif /* FLTM_PERIODICREADBACK_ENABLE_ESM */


/* -------------------------------------------------
 * DDRSS register offsets to be monitored
 * ------------------------------------------------- */
#if(FLTM_PERIODICREADBACK_ENABLE_DDR == STD_ON)
const uint32 FltM_PeriodicReadBack_DdrOffsetList [FLTM_PERIODICREADBACK_DDR_NUM_REGISTERS] =
{
    0x004U   /* SS_CTL_REG */,
    0x020U   /* V2A_CTL_REG */,
    0x024U   /* V2A_R1_MAT_REG */,
    0x028U   /* V2A_R2_MAT_REG */,
    0x02CU   /* V2A_R3_MAT_REG */,
    0x030U   /* V2A_LPT_DEF_PRI_MAP_REG */,
    0x034U   /* V2A_LPT_R1_PRI_MAP_REG */,
    0x038U   /* V2A_LPT_R2_PRI_MAP_REG */,
    0x03CU   /* V2A_LPT_R3_PRI_MAP_REG */,
    0x04CU   /* V2A_HPT_DEF_PRI_MAP_REG */,
    0x050U   /* V2A_HPT_R1_PRI_MAP_REG */,
    0x054U   /* V2A_HPT_R2_PRI_MAP_REG */,
    0x058U   /* V2A_HPT_R3_PRI_MAP_REG */,
    0x05CU   /* V2A_OLD_CMD_PR_REG */,
    0x068U   /* V2A_LEAKY_THRESH_REG */,
    0x06CU   /* V2A_DRAIN_THRESH_REG */,
    0x09CU   /* V2A_BUS_TO */,
    0x120U   /* ECC_CTRL_REG */,
    0x124U   /* ECC_RID_INDX_REG */,
    0x128U   /* ECC_RID_VAL_REG */,
    0x130U   /* ECC_R0_STR_ADDR_REG */,
    0x134U   /* ECC_R0_END_ADDR_REG */,
    0x138U   /* ECC_R1_STR_ADDR_REG */,
    0x13CU   /* ECC_R1_END_ADDR_REG */,
    0x140U   /* ECC_R2_STR_ADDR_REG */,
    0x144U   /* ECC_R2_END_ADDR_REG */,
    0x184U   /* PHY_TEST_CTRL1_REG */,
    0x188U   /* PHY_TEST_CTRL2_REG */,
    0x18CU   /* PHY_TEST_CTRL3_REG */,
    0x190U   /* PHY_TEST_CTRL4_REG */,
    0x194U   /* PHY_TEST_CTRL5_REG */,
    0x198U   /* PHY_TEST_CTRL6_REG */,
    0x19CU   /* PHY_TEST_CTRL7_REG */,
    0x1A0U   /* PHY_TEST_CTRL8_REG */,
    0x1A4U   /* PHY_TEST_CTRL9_REG */,
    0x1A8U   /* PHY_TEST_CTRL10_REG */,
    0x1ACU   /* PHY_TEST_CTRL11_REG */,
    0x1B0U   /* PHY_TEST_CTRL12_REG */,
};
#endif /* FLTM_PERIODICREADBACK_ENABLE_DDR */

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
Date              :10-Apr-2026
By                :RRAJAGO2
Traceability      :BMIC29130-42359
Change Description:Periodic Readback implementation for static Registers
-----------------------------------------------------------------------------*/
