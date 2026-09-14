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

#include <config.h>
#include <lib/io_internal.h>
#include <lib/container_of.h>
#include <types/address_types.h>
#include <sec_proxy_transfer.h>
#include "ring_accelerator.h"
#include "secure_proxy_description.h"
#include "secure_proxy_routing_description.h"

static s32 sproxy_conf_lookup(
	u16 host_id,
	const struct sproxy_host_tx_thread_data **
	tx_data)
{
	s32 res = SUCCESS;
	const struct sproxy_host_tx_thread_data *t;

	/* check valid range */
	if (host_id >= sproxy_route_data_count) {
		res = -EINVAL;
	}
	if (res == SUCCESS) {
		t = &(sproxy_route_data[host_id]);
	}
	if (res == SUCCESS) {
		*tx_data = t;
	}

	return res;
}

s32 sproxy_get_response_conf_id(u16 host_id, u16 *tx_config_id)
{
	s32 res = SUCCESS;
	const struct sproxy_host_tx_thread_data *t;

	res = sproxy_conf_lookup(host_id, &t);
	if (res == SUCCESS) {
		*tx_config_id = t->sproxy_resp_conf_id;
	}

	return res;
}

s32 sproxy_get_notify_conf_id(u16 host_id, u16 *tx_config_id)
{
	s32 res = SUCCESS;
	const struct sproxy_host_tx_thread_data *t;

	res = sproxy_conf_lookup(host_id, &t);
	if (res == SUCCESS) {
		*tx_config_id = t->sproxy_ntfy_conf_id;
	}

	return res;
}
