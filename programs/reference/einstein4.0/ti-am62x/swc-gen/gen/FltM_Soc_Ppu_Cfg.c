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
 * @file        FltM_Ppu_Cfg.c
 * @details     <b> Peripheral Firewall Configuration </b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2025
 *
 */
#ifndef  PPU_CFG_C_
#define  PPU_CFG_C_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "FltM_Soc_Ppu_Cfg.h"
#include "FltM_Soc_Ppu.h"

#define FLTM_SEC_CODE_START
#define FLTM_CORE_CONST_SEC_START
#define FLTM_CORE_DATA_SEC_START
#define FLTM_CORE_BSS_SEC_START

#include "MemMap.h"

#if(FLTM_PPU_ENABLE == STD_ON)
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
const FltM_Ppu_ConfigType Ppu_Config[PPU_INSTANCE_CONFIGURED] =
{
#if 0
	/* FWL ID 35 - BGND Region */
	{
		/* Index */
		0,
		/* fwl_id */
		CSL_STD_FW_MCU_GPIO0_MEM_ID,
		/* region_id */
		0,
		/* n_permission_regs */
		3,
		/* control */
		FLTM_FIREWALL_BGND,
		/* permissions_0 */
		FLTM_PPU_FULL_ACCESS_TO_ALL,
		/* permissions_1 */
		FLTM_PPU_FULL_ACCESS_TO_ALL,
		/* permissions_2 */
		FLTM_PPU_FULL_ACCESS_TO_ALL,
		/* start_address */
		FLTM_BGND_ADDR_START,
		/* end_address */
		FLTM_BGND_ADDR_END,
	},
	/* FWL ID 35 - MCU_GPIO0 */
	{
		/* Index */
		1,
		/* fwl_id */
		CSL_STD_FW_MCU_GPIO0_MEM_ID,
		/* region_id */
		1,
		/* n_permission_regs */
		3,
		/* control */
		FLTM_FIREWALL_FGND,
		/* permissions_0 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* permissions_1 */
		FLTM_PPU_READ_ACCESS_TO_ALL,
		/* permissions_2 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* start_address */
		CSL_STD_FW_MCU_GPIO0_MEM_START,
		/* end_address */
		CSL_STD_FW_MCU_GPIO0_MEM_END,
	},
	/* FWL ID 33 - BGND Region */
	{
		/* Index */
		2,
		/* fwl_id */
		CSL_STD_FW_DCC0_CFG_ID,
		/* region */
		1,
		/* n_permission_regs */
		3,
		/* control */
		FLTM_FIREWALL_BGND,
		/* permissions_0 */
		FLTM_PPU_FULL_ACCESS_TO_ALL,
		/* permissions_1 */
		FLTM_PPU_FULL_ACCESS_TO_ALL,
		/* permissions_2 */
		FLTM_PPU_FULL_ACCESS_TO_ALL,
		/* start_address */
		FLTM_BGND_ADDR_START,
		/* end_address */
		FLTM_BGND_ADDR_END,
	},
#endif
	/* FWL ID 33 - DCC0 */
	{
		/* Index */
		3,
		/* fwl_id */
		CSL_STD_FW_DCC0_CFG_ID,
		/* region */
		3,
		/* n_permission_regs */
		3,
		/* control */
		FLTM_FIREWALL_FGND,
		/* permissions_0 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* permissions_1 */
		FLTM_PPU_READ_ACCESS_TO_ALL,
		/* permissions_2 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* start_address */
		CSL_STD_FW_DCC0_CFG_START,
		/* end_address */
		CSL_STD_FW_DCC0_CFG_END,
	},
	/* FWL ID 33 - DCC1 */
	{
		/* Index */
		4,
		/* fwl_id */
		CSL_STD_FW_DCC1_CFG_ID,
		/* region */
		4,
		/* n_permission_regs */
		3,
		/* control */
		FLTM_FIREWALL_FGND,
		/* permissions_0 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* permissions_1 */
		FLTM_PPU_READ_ACCESS_TO_ALL,
		/* permissions_2 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* start_address */
		CSL_STD_FW_DCC1_CFG_START,
		/* end_address */
		CSL_STD_FW_DCC1_CFG_END,
	},
	/* FWL ID 33 - DCC2 */
	{
		/* Index */
		5,
		/* fwl_id */
		CSL_STD_FW_DCC2_CFG_ID,
		/* region */
		5,
		/* n_permission_regs */
		3,
		/* control */
		FLTM_FIREWALL_FGND,
		/* permissions_0 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* permissions_1 */
		FLTM_PPU_READ_ACCESS_TO_ALL,
		/* permissions_2 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* start_address */
		CSL_STD_FW_DCC2_CFG_START,
		/* end_address */
		CSL_STD_FW_DCC2_CFG_END,
	},
	/* FWL ID 33 - DCC3 */
	{
		/* Index */
		6,
		/* fwl_id */
		CSL_STD_FW_DCC3_CFG_ID,
		/* region */
		6,
		/* n_permission_regs */
		3,
		/* control */
		FLTM_FIREWALL_FGND,
		/* permissions_0 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* permissions_1 */
		FLTM_PPU_READ_ACCESS_TO_ALL,
		/* permissions_2 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* start_address */
		CSL_STD_FW_DCC3_CFG_START,
		/* end_address */
		CSL_STD_FW_DCC3_CFG_END,
	},
	/* FWL ID 33 - DCC4*/
	{
		/* Index */
		7,
		/* fwl_id */
		CSL_STD_FW_DCC4_CFG_ID,
		/* region */
		7,
		/* n_permission_regs */
		3,
		/* control */
		FLTM_FIREWALL_FGND,
		/* permissions_0 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* permissions_1 */
		FLTM_PPU_READ_ACCESS_TO_ALL,
		/* permissions_2 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* start_address */
		CSL_STD_FW_DCC4_CFG_START,
		/* end_address */
		CSL_STD_FW_DCC4_CFG_END,
	},
	/* FWL ID 33 - DCC5 */
	{
		/* Index */
		8,
		/* fwl_id */
		CSL_STD_FW_DCC5_CFG_ID,
		/* region */
		8,
		/* n_permission_regs */
		3,
		/* control */
		FLTM_FIREWALL_FGND,
		/* permissions_0 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* permissions_1 */
		FLTM_PPU_READ_ACCESS_TO_ALL,
		/* permissions_2 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* start_address */
		CSL_STD_FW_DCC5_CFG_START,
		/* end_address */
		CSL_STD_FW_DCC5_CFG_END,
	},
	/* FWL ID 33 - DCC6 */
	{
		/* Index */
		9,
		/* fwl_id */
		CSL_STD_FW_DCC6_CFG_ID,
		/* region */
		9,
		/* n_permission_regs */
		3,
		/* control */
		FLTM_FIREWALL_FGND,
		/* permissions_0 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* permissions_1 */
		FLTM_PPU_READ_ACCESS_TO_ALL,
		/* permissions_2 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* start_address */
		CSL_STD_FW_DCC6_CFG_START,
		/* end_address */
		CSL_STD_FW_DCC6_CFG_END,
	},
	/* FWL ID 33 - DCC7 */
	{
		/* Index */
		10,
		/* fwl_id */
		CSL_STD_FW_DCC7_CFG_ID,
		/* region */
		10,
		/* n_permission_regs */
		3,
		/* control */
		FLTM_FIREWALL_FGND,
		/* permissions_0 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* permissions_1 */
		FLTM_PPU_READ_ACCESS_TO_ALL,
		/* permissions_2 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* start_address */
		CSL_STD_FW_DCC7_CFG_START,
		/* end_address */
		CSL_STD_FW_DCC7_CFG_END,
	},
	/* FWL ID 33 - DCC8 */
	{
		/* Index */
		11,
		/* fwl_id */
		CSL_STD_FW_DCC8_CFG_ID,
		/* region */
		11,
		/* n_permission_regs */
		3,
		/* control */
		FLTM_FIREWALL_FGND,
		/* permissions_0 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* permissions_1 */
		FLTM_PPU_READ_ACCESS_TO_ALL,
		/* permissions_2 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* start_address */
		CSL_STD_FW_DCC8_CFG_START,
		/* end_address */
		CSL_STD_FW_DCC8_CFG_END,
	},
	/* FWL ID 36 - BGND Region */
	{
		/* Index */
		12,
		/* fwl_id */
		CSL_STD_FW_MCU_DCC0_CFG_ID,
		/* region */
		0,
		/* n_permission_regs */
		3,
		/* control */
		FLTM_FIREWALL_BGND,
		/* permissions_0 */
		FLTM_PPU_FULL_ACCESS_TO_ALL,
		/* permissions_1 */
		FLTM_PPU_FULL_ACCESS_TO_ALL,
		/* permissions_2 */
		FLTM_PPU_FULL_ACCESS_TO_ALL,
		/* start_address */
		FLTM_BGND_ADDR_START,
		/* end_address */
		FLTM_BGND_ADDR_END,
	},
	/* FWL ID 36 - MCU_DCC0 */
	{
		/* Index */
		13,
		/* fwl_id */
		CSL_STD_FW_MCU_DCC0_CFG_ID,
		/* region */
		1,
		/* n_permission_regs */
		3,
		/* control */
		FLTM_FIREWALL_FGND,
		/* permissions_0 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* permissions_1 */
		FLTM_PPU_READ_ACCESS_TO_ALL,
		/* permissions_2 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* start_address */
		CSL_STD_FW_MCU_DCC0_CFG_START,
		/* end_address */
		CSL_STD_FW_MCU_DCC0_CFG_END,
	},
	/* FWL ID 36 - MCU_DCC1 */
	{
		/* Index */
		14,
		/* fwl_id */
		CSL_STD_FW_MCU_DCC1_CFG_ID,
		/* region */
		2,
		/* n_permission_regs */
		3,
		/* control */
		FLTM_FIREWALL_FGND,
		/* permissions_0 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* permissions_1 */
		FLTM_PPU_READ_ACCESS_TO_ALL,
		/* permissions_2 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* start_address */
		CSL_STD_FW_MCU_DCC1_CFG_START,
		/* end_address */
		CSL_STD_FW_MCU_DCC1_CFG_END,
	},
#if 0
	/* FWL ID 36 - MCU_ECC_AGGR0 */
	{
		/* Index */
		15,
		/* fwl_id */
		CSL_STD_FW_MCU_ECC_AGGR0_REGS_ID,
		/* region */
		2,
		/* n_permission_regs */
		3,
		/* control */
		FLTM_FIREWALL_FGND,
		/* permissions_0 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* permissions_1 */
		FLTM_PPU_READ_ACCESS_TO_ALL,
		/* permissions_2 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* start_address */
		CSL_STD_FW_MCU_ECC_AGGR0_REGS_ECC_AGGR_START,
		/* end_address */
		CSL_STD_FW_MCU_ECC_AGGR0_REGS_ECC_AGGR_END,
	},
	/* FWL ID 36 - MCU_ECC_AGGR1 */
	{
		/* Index */
		16,
		/* fwl_id */
		CSL_STD_FW_MCU_ECC_AGGR1_REGS_ID,
		/* region */
		2,
		/* n_permission_regs */
		3,
		/* control */
		FLTM_FIREWALL_FGND,
		/* permissions_0 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* permissions_1 */
		FLTM_PPU_READ_ACCESS_TO_ALL,
		/* permissions_2 */
		FLTM_PPU_ALL_ACCESS_TO_MCU,
		/* start_address */
		CSL_STD_FW_MCU_ECC_AGGR1_REGS_ECC_AGGR_START,
		/* end_address */
		CSL_STD_FW_MCU_ECC_AGGR1_REGS_ECC_AGGR_END,
	},
#endif
};

#endif /* #if(FLTM_PPU_ENABLE == STD_ON) */

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
Date              :  28-May-2025
By                :  rrajago2
Traceability      :  
Change Description:  Initil configuration of PPU Firewall -----------------------------------------------------------------------------*/
