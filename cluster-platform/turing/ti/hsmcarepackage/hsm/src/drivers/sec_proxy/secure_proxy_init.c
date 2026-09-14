/*
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */


/**
 * \file secure_proxy_init.c
 *
 * \brief Initialization logic for Secure proxy and threads
 */


#include "config.h"
#include "io_internal.h"
#include "devgrps.h"
#include "ring_accelerator.h"
#include "secure_proxy_description.h"
#include "secure_proxy_regs.h"
#include <comm_memory.h>
/**
 * \brief Map a physical address over to mapped_addr
 *
 * \param phy_addr Physical address
 *
 * \return Mapped address
 */
static mapped_addr_t sp_map_region(soc_phys_addr_t phy_addr)
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
static void sp_unmap_region(soc_phys_addr_t phy_addr __attribute__((unused)))
{
	/* TBD - we need RAT if the mapping is not available */
	return;
}

/**
 * \brief Configure Secure Proxy instances
 *
 * \param sproxy Pointer to secure proxy instance
 *
 * \return 0 if all instances are successfully configured, else return
 * corresponding error.
 */
static s32 sproxy_configure_instance(const struct secure_proxy *sproxy)
{
	mapped_addr_t mapped_scfg_addr;
	soc_phys_addr_t buffer_baseaddr;
	u32 buffer_low;
	u32 buffer_high;
	u32 target_low;
	u32 target_high;
	s32 ret = SUCCESS;

	if (sproxy == NULL) {
		ret = -EINVAL;
	}

	if (ret == SUCCESS) {
		buffer_baseaddr = comm_memory_base_addr(sproxy->buffer_idx, sproxy->buffer_neg_offset);
		buffer_low = soc_phys_low_u32(buffer_baseaddr);
		buffer_high = soc_phys_high_u32(buffer_baseaddr);
		target_low = soc_phys_low_u32(sproxy->sproxy_target_hl);
		target_high = soc_phys_high_u32(sproxy->sproxy_target_hl);
		mapped_scfg_addr = sp_map_region(sproxy->baseaddr_cfg_scfg);
		/* TBD: Potential error handling */

		ret = writel_verified(
			buffer_low, mapped_scfg_addr + SEC_PROXY_SCFG_BUFFER_L);
		if (ret == SUCCESS) {
			ret = writel_verified(
				buffer_high, mapped_scfg_addr +
				SEC_PROXY_SCFG_BUFFER_H);
		}
		if (ret == SUCCESS) {
			ret = writel_verified(
				target_low, mapped_scfg_addr +
				SEC_PROXY_SCFG_TARGET_L);
		}
		if (ret == SUCCESS) {
			ret = writel_verified(
				target_high, mapped_scfg_addr +
				SEC_PROXY_SCFG_TARGET_H);
		}

		sp_unmap_region(sproxy->baseaddr_cfg_scfg);
	}

	return ret;
}

/**
 * \brief Helper function to configure a single thread
 *
 * \param scfg_addr scfg - base address of secure proxy (mapped addr)
 *
 * \param rt_addr - RT address of secure proxy (mapped addr)
 *
 * \param thread_id - Secure proxy thread ID
 *
 * \param target_ring_id - Ring ID to be used by secure proxy - this is a
 *	relative ID from the base ID supported by secure proxy.
 *
 * \param num_msgs_for_thread - What is the credit to be given to a Tx thread?
 *
 * \param is_rx	- 0 if a Rx thread, else 1.
 *
 * \param dest_thread_id - If this a Tx thread, then the corresponding Rx
 *	thread ID.
 *
 * \param threshold - What is the threshold to generate events
 *
 * \param evt_error - event to generate in case of a thread error
 *
 * \param evt_threshold - event to generate when threshold is reached.
 *
 * \return 0 if the thread configuration goes good, else corresponding error.
 */
static s32 sproxy_setup_thread(soc_phys_addr_t scfg_addr,
			       soc_phys_addr_t rt_addr, u16 thread_id,
			       u16 target_ring_id,
			       u8 num_msgs_for_thread, u8 is_rx,
			       u16 dest_thread_id,
			       u8 threshold, u16 evt_error,
			       u16 evt_threshold)
{
	soc_phys_addr_t thread_base_ctl_phy, thread_base_dst_phy;
	soc_phys_addr_t thread_base_evt_phy, thread_base_thr_phy;
	mapped_addr_t thread_base_ctl, thread_base_dst;
	mapped_addr_t thread_base_evt, thread_base_thr;
	u32 ctl, dst, evt, thr;
	s32 ret = SUCCESS;

	thread_base_ctl_phy = scfg_addr + sec_proxy_scfg_thread_ctl(thread_id);
	thread_base_dst_phy = scfg_addr + sec_proxy_scfg_thread_dst(thread_id);
	thread_base_evt_phy = scfg_addr + sec_proxy_scfg_thread_evt_map(
		thread_id);
	thread_base_thr_phy = rt_addr + sec_proxy_rt_thread_thr(thread_id);

	if (is_rx != 0x0U) {
		ctl = (u32) (((u32) 0x1U) << SEC_PROXY_SCFG_THREAD_CTL_DIR_SHIFT);
		ctl |= (u32) (((u32) 0x0U) << SEC_PROXY_SCFG_THREAD_CTL_MAX_CNT_SHIFT);
	} else {
		ctl = (((u32) 0x0U) << SEC_PROXY_SCFG_THREAD_CTL_DIR_SHIFT);
		ctl |= ((u32) (((u32) num_msgs_for_thread) << SEC_PROXY_SCFG_THREAD_CTL_MAX_CNT_SHIFT)) & SEC_PROXY_SCFG_THREAD_CTL_MAX_CNT_MASK;
	}

	ctl |=
		((((u32) target_ring_id) <<
		  SEC_PROXY_SCFG_THREAD_CTL_QUEUE_SHIFT) &
		 SEC_PROXY_SCFG_THREAD_CTL_QUEUE_MASK);

	thread_base_ctl = sp_map_region(thread_base_ctl_phy);
	ret = writel_verified(ctl, (local_phys_addr_t) thread_base_ctl);
	sp_unmap_region(thread_base_ctl_phy);

	/* Destination thread has no meaning for Rx */
	if ((ret == SUCCESS) && (is_rx == 0U)) {
		dst = (((u32) dest_thread_id) <<
		       SEC_PROXY_SCFG_THREAD_DST_THREAD_SHIFT) &
		      SEC_PROXY_SCFG_THREAD_DST_THREAD_MASK;

		thread_base_dst = sp_map_region(thread_base_dst_phy);

		ret = writel_verified(dst, (local_phys_addr_t) thread_base_dst);

		sp_unmap_region(thread_base_dst_phy);
	}

	if (ret == SUCCESS) {
		thr = (((u32) threshold) <<
		       SEC_PROXY_RT_THREAD_THR_THR_CNT_SHIFT) &
		      SEC_PROXY_RT_THREAD_THR_THR_CNT_MASK;

		thread_base_thr = sp_map_region(thread_base_thr_phy);

		ret = writel_verified(thr, (local_phys_addr_t) thread_base_thr);

		sp_unmap_region(thread_base_thr_phy);
	}

	if (ret == SUCCESS) {
		evt = (((u32) evt_error) <<
		       SEC_PROXY_SCFG_THREAD_EVT_MAP_ERR_EVT_SHIFT) &
		      SEC_PROXY_SCFG_THREAD_EVT_MAP_ERR_EVT_MASK;
		evt |= (((u32) evt_threshold) <<
			SEC_PROXY_SCFG_THREAD_EVT_MAP_THR_EVT_SHIFT) &
		       SEC_PROXY_SCFG_THREAD_EVT_MAP_THR_EVT_MASK;

		thread_base_evt = sp_map_region(thread_base_evt_phy);

		ret = writel_verified(evt, (local_phys_addr_t) thread_base_evt);

		sp_unmap_region(thread_base_evt_phy);
	}

	return ret;
}

/**
 * \brief Configure a Rx thread
 *
 * \param rx_thread - pointer to a Rx thread config structure
 *
 * \return 0 if all configuration went fine, else return corresponding error.
 */
static s32 sproxy_configure_rx_thread(
	const struct secure_proxy_rx_thread_config *rx_thread)
{
	u16 target_ring_id;
	const struct secure_proxy *sproxy;
	const struct ring_config *rconfig;
	s32 ret = SUCCESS;

	if (rx_thread->secure_proxy_instance_id >
	    soc_secure_proxy_instances_num) {
		ret = -EINVAL;
	}
	if (ret == SUCCESS) {
		sproxy =
			&(soc_secure_proxy_instances[rx_thread->
						     secure_proxy_instance_id]);
	}

	if ((ret == SUCCESS) && (rx_thread->thread_id > sproxy->num_threads)) {
		ret = -EINVAL;
	}

	if ((ret == SUCCESS) && (rx_thread->ring_config_instance_id >
				 soc_ring_configurations_num)) {
		ret = -EINVAL;
	}
	if (ret == SUCCESS) {
		rconfig =
			&(soc_ring_configurations[rx_thread->
						  ring_config_instance_id]);

		if ((rconfig->ring_index < sproxy->sproxy_ring_index_base) ||
		    (rconfig->ring_index > sproxy->sproxy_ring_index_max)) {
			ret = -EINVAL;
		}
	}

	if (ret == SUCCESS) {
		/* Find relative index for secure proxy's view of Ring ID */
		target_ring_id = rconfig->ring_index -
				 sproxy->sproxy_ring_index_base;

		ret = sproxy_setup_thread(sproxy->baseaddr_cfg_scfg,
					  sproxy->baseaddr_cfg_rt,
					  rx_thread->thread_id,
					  target_ring_id,
					  0U, 1U, 0U, rx_thread->threshold,
					  rx_thread->evt_error,
					  rx_thread->evt_threshold);
	}
	return ret;
}

/**
 * \brief Configure a Tx thread
 *
 * \param tx_thread - pointer to a Tx thread config structure
 *
 * \return 0 if all configuration went fine, else return corresponding error.
 */
static s32 sproxy_configure_tx_thread(
	const struct secure_proxy_tx_thread_config *tx_thread)
{
	u16 target_ring_id;
	const struct secure_proxy_rx_thread_config *rx_thread;
	const struct secure_proxy *sproxy;
	const struct ring_config *rconfig;
	s32 ret = SUCCESS;

	if (tx_thread->rx_thread_instance_id >
	    soc_secure_proxy_rx_configurations_num) {
		ret = -EINVAL;
	}

	if (ret == SUCCESS) {
		rx_thread =
			&(soc_secure_proxy_rx_configurations[tx_thread->
							     rx_thread_instance_id
			  ]);
	}

	if ((ret == SUCCESS) && (rx_thread->secure_proxy_instance_id >
				 soc_secure_proxy_instances_num)) {
		ret = -EINVAL;
	}
	if (ret == SUCCESS) {
		sproxy =
			&(soc_secure_proxy_instances[rx_thread->
						     secure_proxy_instance_id]);
	}

	if ((ret == SUCCESS) && (rx_thread->thread_id > sproxy->num_threads)) {
		ret = -EINVAL;
	}

	if ((ret == SUCCESS) && (tx_thread->thread_id > sproxy->num_threads)) {
		ret = -EINVAL;
	}

	if ((ret == SUCCESS) && (tx_thread->thread_id == rx_thread->thread_id)) {
		ret = -EINVAL;
	}

	if ((ret == SUCCESS) && (rx_thread->ring_config_instance_id >
				 soc_ring_configurations_num)) {
		ret = -EINVAL;
	}
	if (ret == SUCCESS) {
		rconfig =
			&(soc_ring_configurations[rx_thread->
						  ring_config_instance_id]);

		if ((rconfig->ring_index < sproxy->sproxy_ring_index_base) ||
		    (rconfig->ring_index > sproxy->sproxy_ring_index_max)) {
			ret = -EINVAL;
		}
	}

	if (ret == SUCCESS) {
		/* Find relative index for secure proxy's view of Ring ID */
		target_ring_id = rconfig->ring_index -
				 sproxy->sproxy_ring_index_base;

		ret = sproxy_setup_thread(sproxy->baseaddr_cfg_scfg,
					  sproxy->baseaddr_cfg_rt,
					  tx_thread->thread_id,
					  target_ring_id,
					  tx_thread->num_credits, 0U,
					  rx_thread->thread_id,
					  tx_thread->threshold,
					  tx_thread->evt_error,
					  tx_thread->evt_threshold);
	}


	return ret;
}

/**
 * \brief Configure the core secure proxy IP
 *
 * \param devgrp - devgrp to initialize
 *
 * \return 0 if all instances of secure proxies are configured, else return
 * corresponding error
 */
static s32 sproxy_init_instance(devgrp_t devgrp)
{
	s32 ret = SUCCESS;
	const struct secure_proxy *sproxy = NULL;

	sproxy = &(soc_secure_proxy_instances[0]);

	if (is_devgrp(sproxy->devgrp, devgrp) == SUCCESS) {
		sproxy = &(soc_secure_proxy_instances[0]);
	}

	ret = sproxy_configure_instance(sproxy);

	return ret;
}

static s32 sproxy_check_rx_thread_devgrp(u16 rx_thread_id, devgrp_t devgrp)
{
	const struct secure_proxy_rx_thread_config *rx_thread = NULL;
	const struct secure_proxy *sproxy = NULL;
	u8 sproxy_inst_id = 0U;
	s32 ret = SUCCESS;

	if (rx_thread_id >= soc_secure_proxy_rx_configurations_num) {
		ret = -EINVAL;
	}
	if (ret == SUCCESS) {
		rx_thread = &(soc_secure_proxy_rx_configurations[rx_thread_id]);
		sproxy_inst_id = rx_thread->secure_proxy_instance_id;
	}
	if ((ret == SUCCESS) && (sproxy_inst_id >= soc_secure_proxy_instances_num)) {
		ret = -EINVAL;
	}

	if (ret == SUCCESS) {
		sproxy = &(soc_secure_proxy_instances[sproxy_inst_id]);
		ret = is_devgrp(sproxy->devgrp, devgrp);
	}

	return ret;
}

/**
 * \brief Configure all Secure proxy Rx threads
 *
 * \param devgrp - devgrp to initialize
 *
 * \return 0 if all instances of Rx secure proxy threads are configured,
 * else return corresponding error
 */
static s32 sproxy_init_rx_threads(devgrp_t devgrp)
{
	u16 i;
	s32 ret = SUCCESS;
	const struct secure_proxy_rx_thread_config *rx_thread = NULL;

	/* First Initialize Secure Proxy Instances */
	for (i = 0U; i < soc_secure_proxy_rx_configurations_num; i++) {
		if (sproxy_check_rx_thread_devgrp(i, devgrp) == SUCCESS) {
			rx_thread = &(soc_secure_proxy_rx_configurations[i]);
			ret = sproxy_configure_rx_thread(rx_thread);
		}
		if (ret != SUCCESS) {
			break;
		}
	}

	return ret;
}

/**
 * \brief Configure all Secure proxy Tx threads
 *
 * \param devgrp - devgrp to initialize
 *
 * \return 0 if all instances of Tx secure proxy threads are configured,
 * else return corresponding error.
 * On error, zero up to N-1 proxies may be configured. Proxy config error
 * is presumed to be fatal so partial configuration is allowed.
 */
static s32 sproxy_init_tx_threads(devgrp_t devgrp)
{
	u16 i, rx_thr_id;
	s32 ret = SUCCESS;
	const struct secure_proxy_tx_thread_config *tx_thread = NULL;

	/* First Initialize Secure Proxy Instances */
	for (i = 0U; i < soc_secure_proxy_tx_configurations_num; i++) {
		tx_thread = &(soc_secure_proxy_tx_configurations[i]);
		rx_thr_id = tx_thread->rx_thread_instance_id;

		if (sproxy_check_rx_thread_devgrp(rx_thr_id, devgrp) == SUCCESS) {
			ret = sproxy_configure_tx_thread(tx_thread);
		}
		if (ret != SUCCESS) {
			break;
		}
	}

	return ret;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Sproxy init's  Visible APIs
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
s32 sproxy_init(void)
{
	s32 ret = SUCCESS;
	devgrp_t devgrp = DEVGRP_HSM;

	ret = sproxy_init_instance(devgrp);
	if (ret == SUCCESS) {
		ret = sproxy_init_rx_threads(devgrp);
	}
	if (ret == SUCCESS) {
		ret = sproxy_init_tx_threads(devgrp);
	}
	return ret;
}
