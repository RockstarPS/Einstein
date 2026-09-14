/***************************************************************************
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2025] Visteon Corporation
 *       All Rights Reserved.
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and
 *               intends to maintain it in confidence to preserve its trade
 *               secret status. Visteon Corporation reserves the right, under
 *               the copyright laws of the United States or those of any other
 *               country that may have jurisdiction, to protect this work as an
 *               unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves
 *               its rights under all copyright laws to protect this work as a
 *               published work, when appropriate. Those having access to this
 *               work may not copy it, use it, modify it, or disclose the
 *               information contained in it without the written authorization
 *               of Visteon Corporation.
 *
 * \file vHsmFWCfg.c
 *
 * \brief
 * HSM FireWall Configuration for AM62PX HSM M4F.
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 |            | kjohn    | xxxxxx  | Initial version                       |
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          krithik B John           | kjohn     | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/
#include "firewall.h"
#include "vHsmFWCfg.h"
#include "config.h"

#ifdef VHSMFW_ENABLE

struct fwl_multi_region_data_item vHsmFireWall_Cfg_stA[vHSMFIREWALLNUMBER] = {
	{
		.id = 641,
		.region_number = 0U,
		.control = 0x30A,
		.n_permission_regs = 3,
		.permission1 = ALL_RWCD,
		.permission2 = ALL_RWCD,
		.permission3 = ALL_RWCD,
		.start_address = 0x43C00000,
		.end_address = 0x43C2FFFF,
	},
	{
		.id = 641,
		.region_number = 1U,
		.control = 0xA,
		.n_permission_regs = 3,
		.permission1 = HSM_RWCD,
		.permission2 = HSM_RWCD,
		.permission3 = HSM_RWCD,
		.start_address = 0x43C10000,
		.end_address = 0x43C10FFF,
	},
	{
		.id = 641,
		.region_number = 2U,
		.control = 0xA,
		.n_permission_regs = 3,
		.permission1 = HSM_RWCD,
		.permission2 = HSM_RWCD,
		.permission3 = HSM_RWCD,
		.start_address = 0x43C11000,
		.end_address = 0x43C11FFF,
	},
	{
		.id = 641,
		.region_number = 3U,
		.control = 0xA,
		.n_permission_regs = 3,
		.permission1 = HSM_RWCD,
		.permission2 = HSM_RWCD,
		.permission3 = HSM_RWCD,
		.start_address = 0x43C00000,
		.end_address = 0x43C0FFFF,
	},
	{
		.id = 641,
		.region_number = 4U,
		.control = 0xA,
		.n_permission_regs = 3,
		.permission1 = HSM_RWCD,
		.permission2 = HSM_RWCD,
		.permission3 = HSM_RWCD,
		.start_address = 0x43C12000,
		.end_address = 0x43C1FFFF,
	},
	{
		.id = 641,
		.region_number = 5U,
		.control = 0xA,
		.n_permission_regs = 3,
		.permission1 = HSM_RWCD,
		.permission2 = MCU_0_R5_0_RWCD,
		.permission3 = ALL_READ,
		.start_address = 0x43C20000,
		.end_address = 0x43C21FFF,
	},
	{
		.id = 641,
		.region_number = 6U,
		.control = 0xA,
		.n_permission_regs = 3,
		.permission1 = HSM_RWCD,
		.permission2 = HSM_RWCD,
		.permission3 = HSM_RWCD,
		.start_address = 0x43C22000,
		.end_address = 0x43C2FFFF,
	},
	{
		.id = 642,
		.region_number = 0U,
		.control = 0x30A,
		.n_permission_regs = 3,
		.permission1 = ALL_RWCD,
		.permission2 = ALL_RWCD,
		.permission3 = ALL_RWCD,
		.start_address = 0x43C30000,
		.end_address = 0x43C3FFFF,
	},
	{
		.id = 642,
		.region_number = 1U,
		.control = 0xA,
		.n_permission_regs = 3,
		.permission1 = HSM_RWCD,
		.permission2 = MCU_0_R5_0_RWCD,
		.permission3 = HSM_RWCD,
		.start_address = 0x43C30000,
		.end_address = 0x43C30FFF,
	},
	{
		.id = 642,
		.region_number = 2U,
		.control = 0xA,
		.n_permission_regs = 3,
		.permission1 = HSM_RWCD,
		.permission2 = MCU_0_R5_0_RWCD,
		.permission3 = HSM_RWCD,
		.start_address = 0x43C31000,
		.end_address = 0x43C31FFF,
	},
	{
		.id = 642,
		.region_number = 3U,
		.control = 0xA,
		.n_permission_regs = 3,
		.permission1 = HSM_RWCD,
		.permission2 = HSM_RWCD,
		.permission3 = HSM_RWCD,
		.start_address = 0x43C32000,
		.end_address = 0x43C3FFFF,
	},
	{
		.id = 161,
		.region_number = 1U,
		.control = 0xA,
		.n_permission_regs = 1,
		.permission1 = HSM_RWCD,
		.permission2 = NO_RWCD,
		.permission3 = NO_RWCD,
		.start_address = 0x43600000,
		.end_address = 0x43605FFF,
	},
	{
		.id = 161,
		.region_number = 2U,
		.control = 0x20A,
		.n_permission_regs = 1,
		.permission1 = WKUP_0_R5_0_RWCD,
		.permission2 = NO_RWCD,
		.permission3 = NO_RWCD,
		.start_address = 0x43608000,
		.end_address = 0x43609FFF,
	},
	{
		.id = 161,
		.region_number = 3U,
		.control = 0x20A,
		.n_permission_regs = 1,
		.permission1 = A53_RWCD,
		.permission2 = NO_RWCD,
		.permission3 = NO_RWCD,
		.start_address = 0x4360A000,
		.end_address = 0x4360BFFF,
	},
	{
		.id = 161,
		.region_number = 4U,
		.control = 0x20A,
		.n_permission_regs = 1,
		.permission1 = MCU_0_R5_0_RWCD,
		.permission2 = NO_RWCD,
		.permission3 = NO_RWCD,
		.start_address = 0x4360C000,
		.end_address = 0x4360DFFF,
	},
	{
		.id = 2578,
		.region_number = 1U,
		.control = 0xA,
		.n_permission_regs = 1,
		.permission1 = HSM_RWCD,
		.permission2 = NO_RWCD,
		.permission3 = NO_RWCD,
		.start_address = 0x0000000004E00000,
		.end_address = 0x0000000004E00FFF,
	},
	{
		.id = 2578,
		.region_number = 2U,
		.control = 0xA,
		.n_permission_regs = 1,
		.permission1 = HSM_RWCD,
		.permission2 = NO_RWCD,
		.permission3 = NO_RWCD,
		.start_address = 0x0000000004E01000,
		.end_address = 0x0000000004E011FF,
	},
	{
		.id = 2578,
		.region_number = 3U,
		.control = 0xA,
		.n_permission_regs = 1,
		.permission1 = HSM_RWCD,
		.permission2 = NO_RWCD,
		.permission3 = NO_RWCD,
		.start_address = 0x0000000004E10000,
		.end_address = 0x0000000004E1007F,
	},
	{
		.id = 2578,
		.region_number = 4U,
		.control = 0xA,
		.n_permission_regs = 1,
		.permission1 = HSM_RWCD,
		.permission2 = NO_RWCD,
		.permission3 = NO_RWCD,
		.start_address = 0x0000000004E20000,
		.end_address = 0x0000000004E2FFFF,
	}	
};

#endif
/*EOF*/
