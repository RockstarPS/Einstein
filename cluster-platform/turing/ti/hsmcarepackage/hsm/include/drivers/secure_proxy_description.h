/*
 * System Firmware Secure Proxy Data descriptions
 *
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file secure_proxy_description.h
 *
 * \brief Include file for Secure Proxy Data descriptions and initialization
 *	routine
 */

#ifndef SECPROXY_DESC_H
#define SECPROXY_DESC_H

#include <types/sbool.h>
#include <types/short_types.h>
#include <types/address_types.h>
#include <types/devgrps.h>
#include <secure_proxy.h>
#include "ring_accelerator.h"

/**
 * \brief Describes a Secure Proxy instance
 * \param baseaddr_cfg_rt - Base address of cfg_rt region
 *
 * \param baseaddr_cfg_scfg - Base address of cfg_scfg region
 *
 * \param baseaddr_src_target_data - Base address of src_target_data region
 *
 * \param sproxy_target_hl - Sproxy Target_H/L pointing to RA FIFO offset
 *	The config of the SecProxy is such that it is given only the number of
 *	rings it was allocated and will error any thread that tries to use
 *	beyond that count. For example: MCU Navss that count is 30 rings,
 *	starting at 256 by default. So when you move the target base and
 *	attempt to access ring 256, this is why it fails as 256 > 30. It will
 *	probably work if you allocate the first 30 rings for SecProxy usage
 *	instead of starting at ring 256. If the RTL config had defined the
 *	full set of rings as available, 286, then this would work. So, we
 *	provide this as an address based on SoC integration.
 *
 * \param sproxy_ring_index_base - Sproxy's ring ID configuration based on
 *	Target_L pointing to RA FIFO offset
 *
 * \param num_threads - Number of secure proxy threads
 *
 * \param ra_idx - Pointer to Ring accelerator used
 *	Index to \ref soc_ring_accelerator_instances
 *
 * \param buffer_idx - index to comm_memory_instances for the buffer to use
 *
 * \param buffer_neg_offset - Negative offset(in bytes) to identify the
 *	start address of backing memory used for this instance. This offset is
 *	relative to the end address of the memory region. The offset values are
 *	intended to be constant for an SoC configuration even the end address
 *	of the region varies.
 *
 * \param devgrp - sysfw devgrp that this instance belongs to
 */

struct secure_proxy {
	soc_phys_addr_t baseaddr_cfg_rt;
	soc_phys_addr_t baseaddr_cfg_scfg;
	soc_phys_addr_t baseaddr_src_target_data;
	soc_phys_addr_t sproxy_target_hl;
	u16		sproxy_ring_index_base;
	u16		sproxy_ring_index_max;
	u16		num_threads;
	u8		ra_idx;
	u8		buffer_idx;
	u32		buffer_neg_offset;
	devgrp_t	devgrp;
};
/** Num Secure Proxy instances */
extern const u8 soc_secure_proxy_instances_num;
/** Secure Proxy instances */
extern const struct secure_proxy soc_secure_proxy_instances[];

/**
 * \brief Describes the Secure proxy Reader (Rx) thread configuration
 * \param host_id - Host ID that will use this thread
 *
 * \param thread_id - Secure proxy thread ID
 *
 * \param evt_threshold - Event ID to generate for threshold event (optional)
 *
 * \param evt_error - Event ID to generate in case of thread error (optional)
 *
 * \param ring_config_instance_id - Which ring does this thread use?
 *	NOTE: There should be only a single Rx thread per ring,
 *	though multiple Tx threads may be associated with the same Rx
 *	thread's ring. This is an index into \ref soc_ring_configurations
 *
 * \param threshold -	Threshold for events (optional)
 *
 * \param secure_proxy_instance_id - Which secure proxy instance does this
 *	thread belong to? This is an index into \ref soc_secure_proxy_instances
 */
struct secure_proxy_rx_thread_config {
	u16	host_id;
	u16	thread_id;
	u16	evt_threshold;
	u16	evt_error;
	u16	ring_config_instance_id;
	u8	threshold;
	u8	secure_proxy_instance_id;
};
/** Num Rx threads to configure */
extern const u16 soc_secure_proxy_rx_configurations_num;
/** SoC configurations of Rx threads */
extern const struct secure_proxy_rx_thread_config
	soc_secure_proxy_rx_configurations[];

/**
 * \brief Describes the Secure proxy Writer (tx) thread configuration
 * \param host_id - Host ID that will use this thread
 *
 * \param thread_id - Secure proxy thread ID
 *
 * \param num_credits - The number of credits for Tx thread (aka max number of
 *	messages that can be send)
 *
 * \param threshold -	Threshold for events (optional)
 *
 * \param evt_threshold - Event ID to generate for threshold event (optional)
 *
 * \param evt_error - Event ID to generate in case of thread error (optional)
 *
 * \param rx_thread_instance_id - points to which rx thread configuration
 *	index does this transmit to. This is an index to
 *	\ref soc_secure_proxy_rx_configurations
 */
struct secure_proxy_tx_thread_config {
	u16	host_id;
	u16	thread_id;
	u8	num_credits;
	u8	threshold;
	u16	evt_threshold;
	u16	evt_error;
	u16	rx_thread_instance_id;
};
/** Num Tx threads to configure */
extern const u16 soc_secure_proxy_tx_configurations_num;
/** SoC configurations of Tx threads */
extern const struct secure_proxy_tx_thread_config
	soc_secure_proxy_tx_configurations[];

/** What Rx thread Configuration does the last ROM message appear on? */
extern const u16 soc_secure_proxy_rx_rom_config_idx;
/** The Tx thread ID to send notification on ROM secure proxy */
extern const u16 soc_rom_secure_proxy_tx_thread_id;
/** The ROM secure proxy to send notification on  */
extern const struct secure_proxy soc_rom_secure_proxy;

/**
 * \brief Wait for pending ROM message to be flushed
 *
 * Make sure that ROM acknowledgement message to be flushed out by bootloader
 *
 * \return 0 if all went fine, else return corresponding error
 * NOTE: On Error, It is possible that bootloader is hung, so progress
 * cannot be made.
 */
#ifdef CONFIG_SEC_PROXY
extern s32 sproxy_wait_for_rom_handoff(void);
#else
static inline s32 sproxy_wait_for_rom_handoff(void)
{
	return 0;
}
#endif

#ifdef CONFIG_OSAL_MSG_FORWARDING
extern const u16 soc_secure_proxy_tx_dm_config_idx;
extern const u16 soc_secure_proxy_rx_dm_config_idx;
#endif

#endif
