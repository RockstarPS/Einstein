/*
 * System Firmware Source File
 *
 * DMSC Tx Routing Data for AM62PX device
 *
 * Data version: 231011_130515
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <lib/io.h>
#include <lib/container_of.h>
#include <types/short_types.h>
#include <hosts.h>
#include <sec_proxy_config_data.h>

#include "secure_proxy_routing_description.h"

/** Maximum Host Entries */
#define AM62PX_CONFIG_MAX (0xFFU)

const u16 sproxy_route_data_count = AM62PX_CONFIG_MAX;

const struct sproxy_host_tx_thread_data sproxy_route_data[AM62PX_CONFIG_MAX] = {
	/*
	 * Secure Host HSM[253]
	 */
	[HOST_ID_HSM] =		{
		.sproxy_resp_conf_id	= AM62PX_MCU_SA3_SS0_SEC_PROXY_0_TX_HSM_LOW_PRIORITY_THR002_CONF026,
		.sproxy_ntfy_conf_id	= AM62PX_MCU_SA3_SS0_SEC_PROXY_0_TX_HSM_LOW_PRIORITY_THR002_CONF026,
	},
};
