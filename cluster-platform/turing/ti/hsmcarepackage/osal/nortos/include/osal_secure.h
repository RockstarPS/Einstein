/*
 * System Firmware OSAL Privilege Control Layer
 *
 * OSAL Core Privilege control
 *
 * Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include "config.h"

#ifdef CONFIG_SYSFW_FRAMEWORK_BUILD
/*
 * If user/priv separation is enforced, below functions are used to change
 * processor state between privileged and unpriviliged mode of execution.
 */

#include <ti/sysbios/hal/SysCall.h>

#ifdef CONFIG_TRACE_DEBUG_OSAL_CONTEXT_SWITCH
#include <lib/trace.h>

/* Provide a dummy function to work with macro definitions below */
static inline void nop()
{
}

#define osal_enter_priv_mode SysCall_enterPrivMode(); \
	bp_trace_core(TRACE_BP_ACTION_OSAL_CONTEXT_SWITCH, \
		      TRACE_BP_VAL_OSAL_CONTEXT_SWITCH_ENTER); \
	nop
#define osal_restore_priv_mode bp_trace_core(TRACE_BP_ACTION_OSAL_CONTEXT_SWITCH, \
					     TRACE_BP_VAL_OSAL_CONTEXT_SWITCH_RESTORE);	\
	SysCall_restorePrivMode
#define osal_enter_unpriv_mode bp_trace_core(TRACE_BP_ACTION_OSAL_CONTEXT_SWITCH, \
					     TRACE_BP_VAL_OSAL_CONTEXT_SWITCH_EXIT); \
	SysCall_enterUnprivMode
#else
#define osal_enter_priv_mode SysCall_enterPrivMode
#define osal_restore_priv_mode SysCall_restorePrivMode
#define osal_enter_unpriv_mode SysCall_enterUnprivMode
#endif

#else
/*
 * When user/privilige split is not enforced, all messages will be processed in
 * the secure context. Do not enable functions to enter/restore different
 * privilege levels.
 */
#define osal_enter_priv_mode()
#define osal_restore_priv_mode()
#define osal_enter_unpriv_mode()

#endif /* */
