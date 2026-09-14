/*
 * System Firmware OSAL Clock layer
 *
 * OSAL Core clock layer
 *
 * Copyright (C) 2017-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include "osal_clock.h"
#include "osal_secure.h"

#pragma CODE_SECTION(osal_delay, ".kernel_wrapper_funcs");
void osal_delay(u64 usecs)
{
	osal_enter_priv_mode();
	osal_delay_core(usecs);
	osal_restore_priv_mode();
}

#pragma CODE_SECTION(osal_timestamp32, ".kernel_wrapper_funcs");
u32 osal_timestamp32(void)
{
	u32 ret;

	osal_enter_priv_mode();
	ret = osal_timestamp32_core();
	osal_restore_priv_mode();
	return ret;
}

#pragma CODE_SECTION(osal_timestamp64, ".kernel_wrapper_funcs");
u64 osal_timestamp64(void)
{
	u64 ret;

	osal_enter_priv_mode();
	ret = osal_timestamp64_core();
	osal_restore_priv_mode();
	return ret;
}
