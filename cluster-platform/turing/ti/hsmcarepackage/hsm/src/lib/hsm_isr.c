/*
 * { TBD/FIXME: module name}
 *
 * { TBD/FIXME: module description}
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <config.h>

#include <arch/interrupt.h>

#include <osal_hwi.h>
#include <osal_config.h>
#include <osal_halt.h>
#include <osal/user_core.h>
#include <msg/msg_private.h>
#include <msg/msg_check.h>
#include <msg/msg.h>

#include <types/array_size.h>
#include <types/errno.h>
#include <types/ftbool.h>
#include <lib/trace.h>

#include <tisci_provider/tisci.h>
#include <sec_proxy_transfer.h>
#include "secure_core_full.h"
#include <sec_proxy_minimal.h>
#include <sec_proxy.h>
#include <tisci_dkek.h>
#include <hsm_core/hsm.h>
#include <hsm_data.h>
#include <lib/trace.h>

/**
* Global Variables
*/
u8 DSMEK_STATE;
u8 l_dsmek[SA2UL_DSMEK_KEY_LEN];
u32 HSMintrupt_host;

#ifdef CONFIG_OSAL_MSG_FORWARDING
/**
 * \brief Set proper NAK flags and send an TISCI message.
 *
 * \param msg Buffer containing TISCI message.
 * \param size Size of above buffer in bytes.
 *
 * \return 0 on success error code otherwise.
 */
static s32 msg_error_nak_response(u32 *msg, u32 size, u8 host, sbool is_secure)
{
	s32 ret = SUCCESS;
	struct tisci_header *hdr = (struct tisci_header *) msg;
	struct msg_data md;

	if (hdr == NULL) {
		ret = -EINVAL;
	} else {
		if ((hdr->flags & TISCI_MSG_FLAG_AOP) != 0) {
			md.host = host;
			md.is_secure = is_secure;
			tisci_msg_clear_flags(hdr);
			tisci_msg_set_nak_resp(hdr);
		}
	}

	return ret;
}
#endif

/**
 * \brief handle the active TIFS event
 *
 * \param evt_data Data for the event to be processed
 *
 * \return HSM_SUCCESS if event processed successfully, otherwise HSM_FAILURE
 */
static s32 handle_tifs_event(struct hsm_evt_data *evt_data)
{
	s32 ret = HSM_FAILURE;

	if (evt_data->irq_handler != NULL) {
		/* Call the irq handler for the current event. */
		ret = evt_data->irq_handler(evt_data);
	}

	return ret;
}

/**
 * \brief Setup event processing for polled operation
 *
 * This function is invoked when HSM_isr is called in the thread context while
 * polling for events (interrupt for the event is not actively enabled). This
 * will attempt to check any pending interrupts from the list of interrupts
 * which TIFS manages.
 *
 * \return HSM_SUCCESS in case all pending interrupts successfully processed,
 * or no pending interruptd for TIFS. HSM_FAILURE if there is critical error
 * with processing a pending interrupt.
 */
static s32 set_polled_event_data(void)
{
	u32 i;
	u32 irq_num;
	s32 ret = HSM_SUCCESS;
	struct hsm_evt_data *evt_data = NULL;

	for (i = 0; i < hsm_evt_data_list_size && (ret == HSM_SUCCESS); i++) {
		evt_data = &hsm_evt_data_list[i];
		irq_num = evt_data->irq_num;

		/* Check if this irq is not active and currently pending. */
		if (!(ft_is_true(evt_data->active)) &&
		    (is_interrupt_pending(irq_num))) {
			evt_data->active = FT_TRUE;

			ret = handle_tifs_event(evt_data);

			if (ret == HSM_SUCCESS) {
				ret = osal_hwip_clear_interrupt(irq_num);
			}
			if (ret == SUCCESS) {
				ret = HSM_SUCCESS;
			} else {
				ret = HSM_FAILURE;
			}
		}
	}

	return ret;
}

/**
 * \brief Setup event processing for specific interrupt
 *
 * This function is invoked when HSM_isr is called in the interrupt context.
 * TIFS will process the active interrupt only.
 *
 * \param irq_num Active interrupt being taken by the CPU
 *
 * \return HSM_SUCCESS in case active interrupt successfully processed or
 * active interrupt not managed by TIFS. HSM_FAILURE if there is critical error
 * with processing the active interrupt.
 */
static s32 set_irq_event_data(u32 irq_num)
{
	u32 i;
	s32 ret = HSM_FAILURE;
	struct hsm_evt_data *evt_data = NULL;

	/*
	 * Search for the interrupt number within the list of internally
	 * recognized interrupts.
	 */
	for (i = 0; i < hsm_evt_data_list_size; i++) {
		if (irq_num == hsm_evt_data_list[i].irq_num) {
			ret = HSM_SUCCESS;
			evt_data = &hsm_evt_data_list[i];
			evt_data->active = FT_TRUE;
		}
	}

	/*
	 * If found, disable the interrupt request line to enable the event to
	 * be serviced. Call ISR handler for the event if it exists (currently
	 * only for secure proxy to drain to pop the message queue entry).
	 */
	if (ret == HSM_SUCCESS) {
		if (irq_num != 0) {
			ret = osal_hwip_disable_interrupt(irq_num);
		}

		if (ret == SUCCESS) {
			ret = handle_tifs_event(evt_data);
		} else {
			/* Should only get here in case osal fails.*/
			ret = HSM_FAILURE;
		}
	}
	return ret;
}

s32 HSM_isr(void)
{
	s32 ret = HSM_FAILURE;
	u32 irq_num = get_current_interrupt();

	if (irq_num != 0U) {
		/*
		 * HSM_isr called in handler mode. Use the active interrupt to
		 * set the event processing flags
		 */
		ret = set_irq_event_data(irq_num);
	} else {
		/*
		 * HSM_isr called in thread mode. Check which events are
		 * currently pending to process all in order.
		 */
		ret = set_polled_event_data();
	}

	return ret;
}

s32 sec_proxy_isr_handler(struct hsm_evt_data *evt_data)
{
	s32 ret = SUCCESS;
	struct tisci_msg_sa2ul_get_dkek_resp get_resp;
	u32 hw_host = 0U;
	TRACE_info("\r\nReceived interrupt on HSM RX....\n");
	memset(&get_resp, 0, sizeof(get_resp));
	ret = sproxy_receive_msg(&get_resp, sizeof(get_resp));

	/**
	 * check the ACK flag of the get_resp after message is received to conform ACK flag is set or not.
	 * if ACK flag is not set it should result in failure.
	*/
	if (ret != 0 || get_resp.hdr.flags == 0) {
		TRACE_info(" \r\nsproxy_receive_msg req fails \n");
		/*
		 * At this point secure proxy is broken or ftbool
		 * fault so halt
		 */
		osal_system_halt(ret);
	}
	/*
	 * Message received from TIFS to TIFS has host id of TIFS
	 */
	if (get_resp.hdr.host != HOST_ID_HSM) {
		hw_host = get_resp.hdr.host;
	} else {
		hw_host = HOST_ID_TIFS;
	}
	
	/*Check for the response from TIFS for DSMEK*/
	/*if recived save the Derived SMEK ,set the status and return */
	if((hw_host == HOST_ID_TIFS) && (get_resp.hdr.type == TISCI_MSG_SA2UL_GET_DSMEK))
	{
		DSMEK_STATE = 1 ;
		memcpy(&l_dsmek[0], get_resp.dkek, SA2UL_DSMEK_KEY_LEN);
	}

	if (ret == SUCCESS) {
		switch (hw_host) {

		case HOST_ID_WKUP_0_R5_0:
		    HSMintrupt_host = HOST_ID_WKUP_0_R5_0;
			TRACE_info("\r\nReceived message from WKUP_0_R5_0 core \n");
			TRACE_info("\r\nSend response to MAIN_0_R5_0");
			test_ipc_hsm_to_remote_core(TX_HSM_TO_WKUP_0_R5_0);
			break;


		case HOST_ID_MCU_0_R5_0:
		    HSMintrupt_host = HOST_ID_MCU_0_R5_0;
			TRACE_info("\r\nReceived message from MCU_R5 core \n");
			break;



		case HOST_ID_TIFS:
			TRACE_info("\r\nReceived message from TIFS core \n");
			break;

		case HOST_ID_DM:
			TRACE_info("\r\nReceived message from DM core \n");
			break;

		default:
			TRACE_info("\r\n Invalid host ID \n");
			osal_system_halt(ret);
		}
	}

	if (ret == SUCCESS) {
		ret = osal_hwip_enable_interrupt(evt_data->irq_num);
	} else {
		/*
		 * At this point secure proxy is broken or ftbool
		 * fault so halt
		 */
		osal_system_halt(ret);
	}

	if ((ret == SUCCESS)) {
		ret = HSM_SUCCESS;
	} else {
		ret = HSM_FAILURE;
	}

	return ret;
}

/*Function to return the status of the DSMEK along with DSMEK*/
u8 get_dsmek_status(u8* dsmek)
{
  if(1 == DSMEK_STATE) {
    memcpy(dsmek,l_dsmek,SA2UL_DSMEK_KEY_LEN);
  }

  return DSMEK_STATE;
}
