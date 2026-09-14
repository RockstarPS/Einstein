/*
 * { TBD/FIXME: module name}
 *
 * { TBD/FIXME: module description}
 *
 * Copyright (C) 2020-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <config.h>

#include <osal_config.h>
#include <msg/msg_private.h>
#include <msg/msg_check.h>
#include <msg/msg.h>
#include <osal/osal_core.h>

#include <hosts_internal.h>

#include <types/array_size.h>
#include <types/errno.h>
#include <types/ftbool.h>
#include <lib/trace.h>

#include <tisci_provider/tisci.h>
#include <sec_proxy_transfer.h>

#include <sec_isr_handler.h>

#include <hsm_core/hsm.h>
#include <hsm_data.h>
#include "sec_proxy.h"


//static s32 secure_process_msg(u32 *msg_recv, struct msg_data *md);
s32 HSM_process()
{
	u32 i;
	s32 ret = HSM_SUCCESS;
	struct hsm_evt_data *evt_data;

	/*
	 * Search for the interrupt number within the list of internally
	 * recognized interrupts. If found, we look for a handler to call. If
	 * nothing is found, we still treat as a successful call.
	 */
	for (i = 0; (i < hsm_evt_data_list_size) && (ret == HSM_SUCCESS); i++) {
		if (ft_is_true(hsm_evt_data_list[i].active)) {
			evt_data = &hsm_evt_data_list[i];

			/*
			 * Clear active data before processing. This prevents
			 * race condition in case HSM_isr is called in
			 * interrupt mode. Polled mode operation should not
			 * experience race condition as process handler will
			 * complete before next HSM_isr call.
			 */
			evt_data->active = FT_FALSE;
			ret = evt_data->proc_handler(evt_data);
		}
	}

	return ret;
}

s32 sec_proxy_process_handler(struct hsm_evt_data *evt_data)
{
	s32 ret = SUCCESS;

	if(HOST_ID_WKUP_0_R5_0 == HSMintrupt_host)
	{
		TRACE_info("\r\nSend response to wAKEUP");
		test_ipc_hsm_to_remote_core(HOST_ID_WKUP_0_R5_0);
	}
	if(TX_HSM_TO_MCU_0_R5 == HSMintrupt_host)
	{
		TRACE_info("\r\nSend response to MCU_R5");
		test_ipc_hsm_to_remote_core(TX_HSM_TO_MCU_0_R5);
	}
	
#if 0
	sbool finished = STRUE;
	struct msg_data *md;

#ifdef CONFIG_OSAL_MSG_FORWARDING
	struct msg_fwd_info fmsg_info;
#endif
	struct hsm_queue_evt_data *msg_data = &evt_data->int_data.msg_data;

	md = msg_data->secure_msg_data;

	/* If the message is for TIFS, process with appropriate handler */
#ifdef CONFIG_OSAL_MSG_FORWARDING
	fmsg_info.msg = msg_data->hw_msg_buffer;
	check_fwd_msg(&fmsg_info, md);

	if (fmsg_info.msg_fwd == STRUE) {
		/*
		 * If the message must be forwarded to DM, indicate that the
		 * message has not finished processing and should not be marked
		 * as completed (i.e. do NOT re-enable the interrupt for the
		 * queue)
		 */
		finished = SFALSE;
		ret = secure_process_fwd_msg(&fmsg_info, md);
	} else {
		/*
		 * Process the message. This could be a message
		 * natively-received over the secure queue, or a response from
		 * the DM. Either way will represent a completion of the message
		 * send flow for this message, so the interrupt can be
		 * re-enabled.
		 */
		finished = STRUE;
		if (fmsg_info.msg_resp == STRUE) {
			ret = secure_process_fwd_resp(&fmsg_info, md);
		}

		if ((ret == SUCCESS) && (fmsg_info.msg_local == STRUE)) {
			ret = secure_process_msg(fmsg_info.msg, md);
		}
		if (ret != SUCCESS) {
			ret = tisci_common_process_response(msg_data->hw_msg_buffer,
							    ret,
								);
		}
	}
#else
	ret = secure_process_msg(msg_data->hw_msg_buffer, md);

	if (ret != SUCCESS) {
		ret = tisci_common_process_response(msg_data->hw_msg_buffer,
						    ret
						    );
	}
#endif

	if ((ret == SUCCESS) && (finished == STRUE)) {
		md->is_pending = SFALSE;
		ret = osal_hwip_enable_interrupt(md->irq_num);
	}
	/*
	 * If the received message was processed and responded to
	 * successfully (whether ACK or NAK), it is a success condition.
	 *
	 * Otherwise, some critical error in the secure proxy
	 * communication channel occurred return a failure.
	 */
	if (ret == SUCCESS) {
		ret = HSM_SUCCESS;
	} else {
		ret = HSM_FAILURE;
	}
#endif
	return ret;
}

#if 0
static s32 secure_process_msg(u32 *msg_recv, struct msg_data *md)
{
	s32 ret = SUCCESS;
	struct tisci_header *hdr = (struct tisci_header *) msg_recv;
	struct tisci_client *client;

	ret = tisci_secure_lookup_client(hdr->type, &client);

#ifdef CONFIG_HSM_FRAMEWORK_BUILD
	/* In this case, we will process user messages in the secure task */
	if ((ret != SUCCESS) && (client == NULL)) {
		ret = tisci_user_lookup_client(hdr->type, &client);
	}
#endif
	/*
	 * Ensure that we are not in preconfiguration state in which
	 * case only messages with the TISCI_CLIENT_FLAG_PRECONFIG
	 * flag are allowed to be processed.
	 */
	if (ret == SUCCESS) {
		if (osal_core_is_configured() == SFALSE) {
			if ((client->flags & TISCI_CLIENT_FLAG_PRECONFIG) == 0u) {
				client = NULL;
				ret = -EINVAL;
			}
		} else {
			if ((osal_subsystem_check_init(client->subsystem) == SFALSE) &&
			    (client->flags & TISCI_CLIENT_FLAG_PRECONFIG) == 0u) {
				client = NULL;
				ret = -EINVAL;
			}
		}
	}

	if (ret == SUCCESS) {
		/*
		 * We do not use this return value as client handler
		 * makes the decision on how to respond to an error.
		 */
		(void) client->handler(msg_recv, md);
	}

	return ret;
}
#endif
s32 sec_int_process_handler(struct hsm_evt_data *evt_data)
{
	u32 i;
	struct sec_isr_data **dlist = (struct sec_isr_data **) sec_isr_data_list;

	/*
	 * Iterate through the list and service all semaphores with
	 * non-zero count
	 */
	for (i = 0U; i < sec_isr_data_list_count; i++) {
		if (dlist[i]->irq_num == evt_data->irq_num) {
			dlist[i]->func(dlist[i]);
			(void) osal_hwip_enable_interrupt(evt_data->irq_num);
		}
	}

	/*
	 * No return status from the sec peripheral handler - set return success
	 * unconditionally.
	 */
	return HSM_SUCCESS;
}
