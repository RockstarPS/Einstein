/*
 * Helper data for user application configuration
 *
 * Copyright (C) 2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef USER_CORE_FULL
#define USER_CORE_FULL

#include <config.h>
#include <types/errno.h>
#include <types/short_types.h>
#include <hsm_core/hsm.h>

#define SYSFW_USER_MSG_FWD BIT2_SET(2)

#ifdef CONFIG_SYSFW_FRAMEWORK_BUILD
/**
 * \brief Call function for TIFS to handle user-space messages
 *
 * This call-out function allows the TIFS portion within the legacy SYSFW
 * architecture to handle the cases when a user message is sent on a secure
 * queue. This will be used only in the SYSFW builds to send the message to the
 * user thread.
 *
 * \param uhd User-owned isr data.
 *
 * \return Success if successful, failure otherwise
 */
s32 handle_user_msg();
#else
static inline s32 handle_user_msg()
{
	return SUCCESS;
}
#endif

extern const struct osal_queue_hwi_data osal_user_queue_hwi_list[];

extern const u32 osal_user_queue_hwi_list_size;

extern const struct osal_task_data osal_user_task_list[];

extern const u32 osal_user_task_list_size;

#endif /* USER_CORE_FULL */
