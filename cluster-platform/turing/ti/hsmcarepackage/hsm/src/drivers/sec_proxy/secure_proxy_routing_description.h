/*
 * System Firmware DMSC Secure Proxy Routing Data
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef SEC_PROXY_ROUTING_DESCRIPTION
#define SEC_PROXY_ROUTING_DESCRIPTION

/**
 * \brief Single entry in mapping table for host ID to secure proxy TX IDs
 *
 * \param sproxy_resp_conf_id Secure proxy config ID for response TX thread
 * \param sproxy_ntfy_conf_id Secure proxy config ID for notification TX thread
 */
struct sproxy_host_tx_thread_data {
	u16	sproxy_resp_conf_id;
	u16	sproxy_ntfy_conf_id;
};

extern const u16 sproxy_route_data_count;

/**
 * List of secure proxy host data based off host ID index
 */
extern const struct sproxy_host_tx_thread_data sproxy_route_data[];

#endif /* SEC_PROXY_ROUTING_DESCRIPTION */
