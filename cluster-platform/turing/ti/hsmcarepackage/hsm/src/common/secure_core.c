/*
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <osal_config.h>
#include <osal/osal_core.h>
#include <osal_secure.h>
#include <sec_proxy_transfer.h>

struct osal_global_state {
	sbool	core_system_configured;
	u32	subsystem_status;
};

#pragma DATA_SECTION(osal_state,".data_user");
static struct osal_global_state osal_state = {
	.core_system_configured = SFALSE,
	.subsystem_status	= 0,
};

/**
 * \brief Set proper NAK flags and send an TISCI message.
 *
 * \param msg Buffer containing TISCI message.
 * \param size Size of above buffer in bytes.
 *
 * \return 0 on success error code otherwise.
 */
sbool osal_subsystem_check_init(u32 subsystem)
{
	sbool is_init = SFALSE;

	if ((osal_state.subsystem_status & subsystem) == subsystem) {
		is_init = STRUE;
	}

	return is_init;
}

sbool osal_core_is_configured(void)
{
	return osal_state.core_system_configured;
}

void osal_subsystem_set_init_core(u32 subsystem)
{
	osal_state.subsystem_status |= subsystem;
}

#pragma CODE_SECTION(osal_subsystem_set_init, ".kernel_wrapper_funcs");
void osal_subsystem_set_init(u32 subsystem)
{
	osal_enter_priv_mode();
	osal_subsystem_set_init_core(subsystem);
	osal_restore_priv_mode();
}

s32 osal_core_verify_host_id(u8 host_id)
{
	return sproxy_msg_validate_host_id(host_id);
}


s32 osal_core_post_config_init(void)
{
	s32 ret = SUCCESS;

	/* Mark the system as configured */
	osal_state.core_system_configured = STRUE;
	osal_subsystem_set_init_core(SUBSYSTEM_BP);

	return ret;
}
