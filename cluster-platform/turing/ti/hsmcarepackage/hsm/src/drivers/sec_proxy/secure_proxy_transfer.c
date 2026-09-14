/*
 * System Firmware
 *
 * Secure Proxy Transfer APIs
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file secure_proxy_transfer.c
 *
 * \brief Secure Proxy Transfer APIs
 */

#include <lib/io_internal.h>
#include <lib/container_of.h>
#include <types/address_types.h>
#include <types/sbool.h>
#include "ring_accelerator.h"
#include "secure_proxy_description.h"
#include "secure_proxy_regs.h"

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Receive (Rx) Path Helper APIs
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 * \brief Map a physical address over to mapped_addr
 *
 * \param phy_addr Physical address
 *
 * \return Mapped address
 */
static inline mapped_addr_t spt_map_region(soc_phys_addr_t phy_addr)
{
	/**
	 * Physical address | mapped address | Size
	 * ----------------------------------------
	 * 0x00000000ULL    | 0x60000000UL   | 512MB
	 * 0x20000000ULL    | 0x80000000UL   | 512MB
	 * 0x40000000ULL    | 0xa0000000UL   | 512MB
	 * ~~~
	 *
	 * *NOTE*: This wont work for firewall setup and separated ops.
	 */

	/*
	 * Only modify addresses outside the range shown here, since SoCs
	 * with the SMS use addresses inside the range as local addresses.
	 */
	if ((soc_phys_low_u32(phy_addr) < (0x43700000U)) ||
	    (soc_phys_low_u32(phy_addr) >= (0x46000000U))) {
		return soc_phys_low_u32(phy_addr) + (0x60000000U);
	} else {
		/* Use unmodified address for SPROXY targets in local memory map */
		return soc_phys_low_u32(phy_addr);
	}
}

/**
 * \brief Unmap a physical address which was previously mapped
 *
 * \param phy_addr - physical address to unmap
 */
static inline void spt_unmap_region(soc_phys_addr_t phy_addr __attribute__(
					    (unused)))
{
	/* TBD - we need RAT if the mapping is not available */
	return;
}

/**
 * \brief Helper function to transfer a buffer to secure proxy memory
 *
 * \param is_tx STRUE for write operation, SFALSE for read operation
 *
 * \param thread_msg_addr - mapped_addr of a thread message area
 *
 * \param buff - pointer to the data buffer to transfer
 *
 * \param num_words - number of words to transfer
 */
static void sproxy_trans_a_message(sbool is_tx, mapped_addr_t thread_msg_addr,
				   u32 *buff,
				   u32 num_words)
{
	u32 i;
	u32 *tmp_buff = buff;
	mapped_addr_t msg_addr = thread_msg_addr;

	for (i = 0U; i < num_words; i++) {
		if (is_tx == STRUE) {
			writel(*tmp_buff, (local_phys_addr_t) msg_addr);
		} else {
			*tmp_buff = readl((local_phys_addr_t) msg_addr);
		}
		tmp_buff++;
		msg_addr += (mapped_addr_t) sizeof(u32);
	}
}

/**
 * \brief Generic helper to get the status register value of a sproxy thread
 *
 * \param sproxy - Pointer to Secure proxy instance
 *
 * \param thread_id - Secure proxy thread ID to read status of
 *
 * \return secure proxy thread's status register value
 */
static u32 sproxy_get_thread_status(const struct secure_proxy	*sproxy,
				    u16				thread_id)
{
	soc_phys_addr_t thread_base_stat_phy;
	mapped_addr_t thread_base_stat;
	u32 status;

	thread_base_stat_phy = sproxy->baseaddr_cfg_rt +
			       sec_proxy_rt_thread_status(thread_id);
	thread_base_stat = spt_map_region(thread_base_stat_phy);
	status = readl((local_phys_addr_t) thread_base_stat);
	spt_unmap_region(thread_base_stat_phy);

	return status;
}

/**
 * \brief Helper function to check to see if secure proxy thread has valid data
 *
 * \param rx_config_id - Rx thread config ID
 *
 * \param rx_thread_ret - If data is ready, then returns the pointer to thread
 *	config for the Rx thread
 *
 * \param sproxy_ret - If data is ready, then returns the pointer to the sproxy
 *	instance that the Rx thread points to.
 *
 * \return 0 if there is data to be read from the Rx thread pointed by the
 * rx thread config pointer. However, in case of bad pointers OR thread error
 * returns corresponding error value.
 */
static s32 sproxy_rx_is_ready(
	u16	rx_config_id,
	const struct secure_proxy_rx_thread_config
		**rx_thread_ret,
	const struct secure_proxy
		**sproxy_ret
	)
{
	s32 ret = SUCCESS;
	u32 status = 0U;
	u32 num_messages = 0U;
	const struct secure_proxy_rx_thread_config *rx_thread;
	const struct secure_proxy *sproxy;

	if (rx_config_id > soc_secure_proxy_rx_configurations_num) {
		ret = -EINVAL;
	}

	/* All struct validation was done at init and memory is safe */
	if (ret == SUCCESS) {
		rx_thread = &(soc_secure_proxy_rx_configurations[rx_config_id]);
		sproxy =
			&(soc_secure_proxy_instances
			  [rx_thread->secure_proxy_instance_id]);

		status = sproxy_get_thread_status(sproxy, rx_thread->thread_id);

		/* Check if we have an error and min 1 message to read */
		if ((status & SEC_PROXY_RT_THREAD_STATUS_ERROR_MASK) != 0U) {
			/* TBD: XXX: Report error info */
			ret = -EINVAL;
			/* TBD: XXX: Error recovery by write of 0 */
		} else {
			num_messages =
				(status &
				 SEC_PROXY_RT_THREAD_STATUS_CUR_CNT_MASK) >>
				SEC_PROXY_RT_THREAD_STATUS_CUR_CNT_SHIFT;
			if (num_messages == 0U) {
				ret = -EBUSY;
			}
		}
	}

	if (ret == SUCCESS) {
		*rx_thread_ret = rx_thread;
		*sproxy_ret = sproxy;
	}

	return ret;
}

/**
 * \brief Helper function to find a Host ID from a Tx Thread ID.
 *
 * The thread ID must be present in \ref soc_secure_proxy_tx_configurations.
 * But, we have to search for the tuple {rx_config_id, sender_thr_id}
 * That can only be unique given that Tx threads need to be associated
 * with a specific Rx thread, and RX_config_id is unique for all instances of
 * Rx_threads on all Sec proxies.
 *
 * \param rx_config_id - Rx Configuration ID
 *
 * \param sender_thr_id - Thread ID of the sender
 *
 * \param sender_host_id - Sender's Host ID is returned if a match is found
 *
 * \return 0 if a match is found, else return -EINVAL
 */
static s32 sproxy_search_host(u16 rx_config_id, u16 sender_thr_id,
			      u32 *sender_host_id)
{
	u16 i;
	s32 ret = -EINVAL;
	const struct secure_proxy_tx_thread_config *tx_threads;

	tx_threads = soc_secure_proxy_tx_configurations;

	/* XXX: Is there a better search algo we could do? hash? */
	for (i = 0U; i < soc_secure_proxy_tx_configurations_num; i++) {
		if ((tx_threads->thread_id == sender_thr_id) &&
		    (tx_threads->rx_thread_instance_id == rx_config_id)) {
			/* We have a match! */
			*sender_host_id = (u32) (tx_threads->host_id);
			ret = SUCCESS;
			/*
			 * XXX: XXX: XXX: XXX:
			 * IMPORTANT NOTE: WE DONOT BREAK here:
			 * This is a countermeasure implemented
			 * against timing attack.
			 * This is inefficient, however, required.
			 * XXX: XXX: XXX: XXX:
			 */
		}
		tx_threads++;
	}

	return ret;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Receive (Rx) Path visible APIs
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
s32 sproxy_msg_is_pending(u16 rx_config_id)
{
	s32 ret;
	const struct secure_proxy_rx_thread_config *rx_thread;
	const struct secure_proxy *sproxy;

	ret = sproxy_rx_is_ready(rx_config_id, &rx_thread, &sproxy);
	return ret;
}

void sproxy_msg_trans_raw(sbool is_tx, const struct secure_proxy *sproxy,
			  u16 thread_id, u32 *buf, u32 buf_num_words, u32 offset)
{
	soc_phys_addr_t phys_addr;
	mapped_addr_t mapped_addr;

	phys_addr = sproxy->baseaddr_src_target_data +
		    sec_proxy_target_message_start(thread_id);
	mapped_addr = spt_map_region(phys_addr);
	mapped_addr += (mapped_addr_t) (offset * (u32) sizeof(u32));

	sproxy_trans_a_message(is_tx, mapped_addr, buf, buf_num_words);

	spt_unmap_region(phys_addr);
}

s32 sproxy_msg_read_at_offset(u16 rx_config_id, u32 *rx_buff, u32 rx_num_words,
			      u32 offset)
{
	s32 ret = SUCCESS;
	const struct secure_proxy_rx_thread_config *rx_thread;
	const struct secure_proxy *sproxy;

	/* Don't bother to even attempt to read if too big */
	if ((rx_num_words + offset) > SEC_PROXY_TARGET_MESSAGE_NUM_WORDS) {
		ret = -EINVAL;
	}

	/* Is my buffer even valid */
	if (rx_buff == NULL) {
		ret = -EINVAL;
	}

	/* Read nothing? */
	if (rx_num_words == 0U) {
		ret = -EINVAL;
	}

	if (ret == SUCCESS) {
		ret = sproxy_rx_is_ready(rx_config_id, &rx_thread, &sproxy);
	}

	/* Okay, we now have a valid message to read */
	if (ret == SUCCESS) {
		sproxy_msg_trans_raw(SFALSE, sproxy, rx_thread->thread_id, rx_buff,
				     rx_num_words, offset);
	}

	return ret;
}

s32 sproxy_msg_read(u16 rx_config_id, u32 *rx_buff, u32 rx_num_words)
{
	return sproxy_msg_read_at_offset(rx_config_id, rx_buff, rx_num_words, 0U);
}

static s32 sproxy_msg_get_sender_thr_id(u16 rx_config_id, u16 *sender_thr_id)
{
	s32 ret = SUCCESS;
	soc_phys_addr_t thread_base_private_phy;
	mapped_addr_t thread_base_private;

	u32 private = 0U;
	const struct secure_proxy_rx_thread_config *rx_thread;
	const struct secure_proxy *sproxy;

	/* Is my return ptr even valid? */
	if (sender_thr_id == NULL) {
		ret = -EINVAL;
	}

	if (ret == SUCCESS) {
		ret = sproxy_rx_is_ready(rx_config_id, &rx_thread, &sproxy);
	}

	/* Okay, we now have a valid message to read */
	if (ret == SUCCESS) {
		thread_base_private_phy = sproxy->baseaddr_src_target_data +
					  sec_proxy_target_data_private(
			rx_thread->thread_id);
		thread_base_private = spt_map_region(thread_base_private_phy);

		private = readl((local_phys_addr_t) thread_base_private);

		spt_unmap_region(thread_base_private_phy);
		*sender_thr_id =
			(u16) ((private &
				SEC_PROXY_TARGET_DATA_PRIVATE_SRC_THR_MASK) >>
			       SEC_PROXY_TARGET_DATA_PRIVATE_SRC_THR_SHIFT);
	}

	return ret;
}

s32 sproxy_msg_get_sender_host_id(u16 rx_config_id, u32 *sender_host_id)
{
	s32 ret = SUCCESS;
	u16 sender_thr_id = 0U;

	/* Is my return ptr even valid? */
	if (sender_host_id == NULL) {
		ret = -EINVAL;
	}

	/* First see if we can find a thread */
	if (ret == SUCCESS) {
		ret = sproxy_msg_get_sender_thr_id(rx_config_id, &sender_thr_id);
	}

	if (ret == SUCCESS) {
		ret = sproxy_search_host(rx_config_id, sender_thr_id,
					 sender_host_id);
	}

	return ret;
}

s32 sproxy_msg_validate_host_id(u16 host_id)
{
	u16 i;
	s32 ret = -EINVAL;
	const struct secure_proxy_tx_thread_config *tx_threads;

	tx_threads = soc_secure_proxy_tx_configurations;

	/* XXX: Is there a better search algo we could do? */
	for (i = 0U; i < soc_secure_proxy_tx_configurations_num; i++) {
		if (host_id == tx_threads->host_id) {
			ret = SUCCESS;
		}
		/*
		 * XXX: XXX: XXX: XXX:
		 * IMPORTANT NOTE: WE DONOT BREAK here:
		 * This is a countermeasure implemented
		 * against timing attack.
		 * This is inefficient, however, required.
		 * XXX: XXX: XXX: XXX:
		 */
		tx_threads++;
	}
	return ret;
}

s32 sproxy_msg_ack(u16 rx_config_id)
{
	s32 ret = SUCCESS;
	const struct secure_proxy_rx_thread_config *rx_thread;
	const struct secure_proxy *sproxy;

	/* Dummy read value to pick the next available message */
	u32 last_word = 0x0;

	ret = sproxy_rx_is_ready(rx_config_id, &rx_thread, &sproxy);

	/* Okay, we now have a valid message to read */
	if (ret == SUCCESS) {
		/* Read to the last word to pick the next available message */
		sproxy_msg_trans_raw(SFALSE, sproxy, rx_thread->thread_id, &last_word,
				     1U, SEC_PROXY_TARGET_MESSAGE_NUM_WORDS);
		/*
		 * NOTE: There is no viable verification possible here with
		 * credit count either:
		 * (i) read credit_prior
		 * (ii) do_confirm_operation
		 * (iii) read credit_after
		 * credit_prior and credit_after can be the same given that
		 * an Tx Thread could have posted a new message between
		 * steps (ii) and (iii)
		 */
	}

	return ret;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Transmit (Tx) Path Helper APIs
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 * \brief Is the secure proxy thread ready to send data
 *
 * \param tx_config_id - Tx thread config ID
 *
 * \param tx_thread_ret - If data can be send, then returns the pointer to
 *	thread config for the Tx thread
 *
 * \param sproxy_ret - If data can be send, then returns the pointer to the
 *	sproxy instance that the Tx thread points to.
 *
 * \return 0 if there data can be send over the Tx thread pointed by the
 * tx thread config pointer. However, in case of bad pointers OR thread error
 * returns corresponding error value.
 */
static s32 sproxy_tx_is_ready(
	u16	tx_config_id,
	const struct secure_proxy_tx_thread_config
		**tx_thread_ret,
	const struct secure_proxy
		**sproxy_ret
	)
{
	s32 ret = SUCCESS;
	u32 status = 0U;
	u32 num_messages = 0U;
	const struct secure_proxy_tx_thread_config *tx_thread;
	const struct secure_proxy_rx_thread_config *rx_thread;
	const struct secure_proxy *sproxy;

	if (tx_config_id > soc_secure_proxy_tx_configurations_num) {
		ret = -EINVAL;
	}

	/* All struct validation was done at init and memory is safe */
	if (ret == SUCCESS) {
		tx_thread = &(soc_secure_proxy_tx_configurations[tx_config_id]);
		rx_thread =
			&(soc_secure_proxy_rx_configurations[tx_thread->
							     rx_thread_instance_id
			  ]);
		sproxy =
			&(soc_secure_proxy_instances
			  [rx_thread->secure_proxy_instance_id]);

		status = sproxy_get_thread_status(sproxy, tx_thread->thread_id);

		/* Check if we have an error and min 1 message slot avail */
		if ((status & SEC_PROXY_RT_THREAD_STATUS_ERROR_MASK) != 0U) {
			/* TBD: XXX: Report error info */
			ret = -EINVAL;
			/* TBD: XXX: Error recovery by write of 0 */
		} else {
			num_messages =
				(status &
				 SEC_PROXY_RT_THREAD_STATUS_CUR_CNT_MASK) >>
				SEC_PROXY_RT_THREAD_STATUS_CUR_CNT_SHIFT;
			if (num_messages == 0U) {
				ret = -EBUSY;
			}
		}
	}

	if (ret == SUCCESS) {
		*tx_thread_ret = tx_thread;
		*sproxy_ret = sproxy;
	}

	return ret;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Transmit (Tx) Path visible APIs
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
s32 sproxy_msg_can_send(u16 tx_config_id)
{
	s32 ret;
	const struct secure_proxy_tx_thread_config *tx_thread;
	const struct secure_proxy *sproxy;

	ret = sproxy_tx_is_ready(tx_config_id, &tx_thread, &sproxy);
	return ret;
}

s32 sproxy_msg_send_at_offset(u16 tx_config_id, u32 *tx_buff, u32 tx_num_words,
			      u32 offset)
{
	s32 ret = SUCCESS;
	const struct secure_proxy_tx_thread_config *tx_thread;
	const struct secure_proxy *sproxy;

	/* Don't bother to even attempt to write if too big */
	if ((tx_num_words + offset) > SEC_PROXY_TARGET_MESSAGE_NUM_WORDS) {
		ret = -EINVAL;
	}

	/* Is my buffer even valid */
	if (tx_buff == NULL) {
		ret = -EINVAL;
	}

	/* Send nothing? */
	if (tx_num_words == 0U) {
		ret = -EINVAL;
	}

	if (ret == SUCCESS) {
		ret = sproxy_tx_is_ready(tx_config_id, &tx_thread, &sproxy);
	}

	/* Okay, we now have a valid message to write */
	if (ret == SUCCESS) {
		sproxy_msg_trans_raw(STRUE, sproxy, tx_thread->thread_id, tx_buff,
				     tx_num_words, offset);
	}

	return ret;
}

s32 sproxy_msg_send(u16 tx_config_id, u32 *tx_buff, u32 tx_num_words)
{
	return sproxy_msg_send_at_offset(tx_config_id, tx_buff, tx_num_words, 0U);
}

s32 sproxy_msg_finish(u16 tx_config_id)
{
	s32 ret = SUCCESS;
	const struct secure_proxy_tx_thread_config *tx_thread;
	const struct secure_proxy *sproxy;

	/* Any transmit value to send out the message */
	u32 last_word = 0x0;

	ret = sproxy_tx_is_ready(tx_config_id, &tx_thread, &sproxy);

	/* Write to the last word to send out the message */
	if (ret == SUCCESS) {
		sproxy_msg_trans_raw(STRUE, sproxy, tx_thread->thread_id, &last_word,
				     1U, SEC_PROXY_TARGET_MESSAGE_NUM_WORDS);
		/*
		 * NOTE: There is no viable verification possible here with
		 * credit count either:
		 * (i) read credit_prior
		 * (ii) do_confirm_operation
		 * (iii) read credit_after
		 * credit_prior and credit_after can be the same given that
		 * an Rx Thread could have read the message between
		 * steps (ii) and (iii)
		 */
	}

	return ret;
}
