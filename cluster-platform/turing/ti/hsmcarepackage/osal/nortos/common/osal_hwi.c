/*
 * System Firmware OSAL HWI layer
 *
 * OSAL HWI layer for generic peripheral interrupts
 *
 * Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <types/array_size.h>
#include <osal_hwi.h>
#include <lib/trace.h>

#include <osal_secure.h>
#include <hwip.h>

u32 osal_hwip_clear_interrupt(u32 irq_num)
{
	return hwip_clear_interrupt(irq_num);
}

u32 osal_hwip_disable_interrupt(u32 irq_num)
{
	return hwip_disable_interrupt(irq_num, NULL);
}

u32 osal_hwip_enable_interrupt(u32 irq_num)
{
	return hwip_enable_interrupt(irq_num, NULL);
}

u32 osal_hwip_disable(void)
{
	return hwip_disable();
}

void osal_hwip_restore(u32 key)
{
	hwip_restore(key);
	return;
}

#pragma CODE_SECTION(osal_hwip_enable, ".kernel_wrapper_funcs");
s32 osal_hwip_enable(u32 hwi_id)
{
	s32 ret;

	osal_enter_priv_mode();
	ret = hwip_enable_interrupt(hwi_id, NULL);
	osal_restore_priv_mode();

	return ret;
}
