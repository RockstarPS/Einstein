/*
 * System Firmware Source File
 *
 * SoC configs for secure proxy for AM62PX device
 *
 * Data version: 231011_130515
 *
 * Copyright (C) 2024 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <lib/io.h>
#include <lib/container_of.h>
#include <types/errno.h>
#include <types/short_types.h>
#include <comm_memory_soc.h>
#include <hosts.h>
#include <sec_proxy_config_data.h>
#include <ring_acel_config_data.h>

#include "ring_accelerator.h"
#include "secure_proxy_description.h"
#include "sec_proxy_soc_data.h"
#include "ring_acel_soc_data.h"

/** SAFE_EVENT Does NOT generate an IRQ or an event onto ETL */
#define SOC_SAFE_EVENT (0xFFFFU)


const u16 soc_secure_proxy_tx_configurations_num = SOC_MAX_SPT_TX_CONFIG_INSTANCES;


const struct secure_proxy_tx_thread_config soc_secure_proxy_tx_configurations[SOC_MAX_SPT_TX_CONFIG_INSTANCES] = {
	[AM62PX_MCU_SA3_SS0_SEC_PROXY_0_TX_HSM_LOW_PRIORITY_THR002_CONF026] =			{
		.host_id		= HOST_ID_HSM,
		.thread_id		= 2U,
		.num_credits		= 8U,
		.threshold		= 1U,
		.evt_threshold		= SOC_SAFE_EVENT,
		.evt_error		= SOC_SAFE_EVENT,
		.rx_thread_instance_id	= AM62PX_MCU_SA3_SS0_SEC_PROXY_0_RX_MAIN_0_R5_0_HSM_SEC_LOW_PRIORITY_RX_THR013_CONF018,
	},
	[AM62PX_MCU_SA3_SS0_SEC_PROXY_0_TX_MAIN_0_R5_HSM_SEC_HSM_RESPONSE_TX_THR012_CONF027] =	{
		.host_id		= HOST_ID_WKUP_0_R5_0,
		.thread_id		= 8U,
		.num_credits		= 8U,
		.threshold		= 1U,
		.evt_threshold		= SOC_SAFE_EVENT,
		.evt_error		= SOC_SAFE_EVENT,
		.rx_thread_instance_id	= AM62PX_MCU_SA3_SS0_SEC_PROXY_0_RX_HSM_RESPONSE_THR000_CONF017,
	},
	[AM62PX_MCU_SA3_SS0_SEC_PROXY_0_TX_MPU_0_A72_HSM_SEC_HSM_RESPONSE_TX_THR010_CONF028] =	{
		.host_id		= HOST_ID_A53_0,
		.thread_id		= 10U,
		.num_credits		= 8U,
		.threshold		= 1U,
		.evt_threshold		= SOC_SAFE_EVENT,
		.evt_error		= SOC_SAFE_EVENT,
		.rx_thread_instance_id	= AM62PX_MCU_SA3_SS0_SEC_PROXY_0_RX_HSM_RESPONSE_THR000_CONF017,
	},
	[AM62PX_MCU_SA3_SS0_SEC_PROXY_0_TX_HSM_LOW_PRIORITY_THR003_CONF029] =			{
		.host_id		= HOST_ID_HSM,
		.thread_id		= 3U,
		.num_credits		= 8U,
		.threshold		= 1U,
		.evt_threshold		= SOC_SAFE_EVENT,
		.evt_error		= SOC_SAFE_EVENT,
		.rx_thread_instance_id	= AM62PX_MCU_SA3_SS0_SEC_PROXY_0_RX_MCU_0_A72_0_HSM_SEC_LOW_PRIORITY_RX_THR011_CONF019,
	},
	[AM62PX_MCU_SA3_SS0_SEC_PROXY_0_TX_HSM_LOW_PRIORITY_THR002_CONF030] =			{
		.host_id		= HOST_ID_HSM,
		.thread_id		= 4U,
		.num_credits		= 8U,
		.threshold		= 1U,
		.evt_threshold		= SOC_SAFE_EVENT,
		.evt_error		= SOC_SAFE_EVENT,
		.rx_thread_instance_id	= AM62PX_MCU_SA3_SS0_SEC_PROXY_0_RX_MCU_0_R5_0_HSM_SEC_LOW_PRIORITY_RX_THR013_CONF018,
	},
	[AM62PX_MCU_SA3_SS0_SEC_PROXY_0_TX_MCU_0_R5_HSM_SEC_HSM_RESPONSE_TX_THR012_CONF031] =	{
		.host_id		= HOST_ID_MCU_0_R5_0,
		.thread_id		= 12U,
		.num_credits		= 8U,
		.threshold		= 1U,
		.evt_threshold		= SOC_SAFE_EVENT,
		.evt_error		= SOC_SAFE_EVENT,
		.rx_thread_instance_id	= AM62PX_MCU_SA3_SS0_SEC_PROXY_0_RX_HSM_RESPONSE_THR000_CONF017,
	},
};

const u16 soc_secure_proxy_rx_configurations_num = SOC_MAX_SPT_RX_CONFIG_INSTANCES;

const struct secure_proxy_rx_thread_config soc_secure_proxy_rx_configurations[SOC_MAX_SPT_RX_CONFIG_INSTANCES] = {
	[AM62PX_MCU_SA3_SS0_SEC_PROXY_0_RX_HSM_RESPONSE_THR000_CONF017] =					  {
		.host_id			= HOST_ID_HSM,
		.thread_id			= 0U,
		.threshold			= 1U,
		.evt_threshold			= 0x0002,
		.evt_error			= 0x0000,
		.secure_proxy_instance_id	= AM62PX_SPROXY_IDX_SA3_SS0_SEC_PROXY_0,
		.ring_config_instance_id	= AM62PX_SA3_SS0_RINGACC_0_RING_0005_CONF_017,
	},
	[AM62PX_MCU_SA3_SS0_SEC_PROXY_0_RX_MAIN_0_R5_0_HSM_SEC_LOW_PRIORITY_RX_THR013_CONF018] =			  {
		.host_id			= HOST_ID_WKUP_0_R5_0,
		.thread_id			= 9U,
		.threshold			= 1U,
		.evt_threshold			= SOC_SAFE_EVENT,
		.evt_error			= SOC_SAFE_EVENT,
		.secure_proxy_instance_id	= AM62PX_SPROXY_IDX_SA3_SS0_SEC_PROXY_0,
		.ring_config_instance_id	= AM62PX_SA3_SS0_RINGACC_0_RING_0004_CONF_018,
	},
	[AM62PX_MCU_SA3_SS0_SEC_PROXY_0_RX_MCU_0_A72_0_HSM_SEC_LOW_PRIORITY_RX_THR011_CONF019] =		  {
		.host_id			= HOST_ID_A53_0,
		.thread_id			= 11U,
		.threshold			= 1U,
		.evt_threshold			= SOC_SAFE_EVENT,
		.evt_error			= SOC_SAFE_EVENT,
		.secure_proxy_instance_id	= AM62PX_SPROXY_IDX_SA3_SS0_SEC_PROXY_0,
		.ring_config_instance_id	= AM62PX_SA3_SS0_RINGACC_0_RING_0004_CONF_019,
	},
	[AM62PX_MCU_SA3_SS0_SEC_PROXY_0_RX_MCU_0_R5_0_HSM_SEC_LOW_PRIORITY_RX_THR013_CONF018] =			  {
		.host_id			= HOST_ID_MCU_0_R5_0,
		.thread_id			= 13U,
		.threshold			= 1U,
		.evt_threshold			= SOC_SAFE_EVENT,
		.evt_error			= SOC_SAFE_EVENT,
		.secure_proxy_instance_id	= AM62PX_SPROXY_IDX_SA3_SS0_SEC_PROXY_0,
		.ring_config_instance_id	= AM62PX_SA3_SS0_RINGACC_0_RING_0004_CONF_020,
	},
};
