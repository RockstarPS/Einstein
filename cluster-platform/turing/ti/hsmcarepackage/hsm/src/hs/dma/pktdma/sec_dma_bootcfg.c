/*
 * System Firmware Source File
 *
 * Sec DMA SoC Data for AM62p device
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sec_dma_bootcfg.c
 *
 * \brief Secure dma manager SoC Data for AM62px device
 */

#include <sec_dma_bootcfg.h>

#define SA2UL_INGRESS_QNUM (1U)
#define SA2UL_UDMAP_TX_CHAN_NUM (1U)

/**
 * Boot configuration data which provides the allocation of DMA
 * resources for this module
 */
const struct sec_dma_bootcfg sec_dma_bootcfg_data = {
	.ra_id				= 0U,
	.proxy_id			= 0U,
	.psilcfg_id			= 0U,
	.udmap_id			= 0U,
	.sa2ul_id			= 0U,
	.proxy_chan			= 0U,
	.udmap_thread_id_base		= 0x3000U,
	.sa2ul_ingress_thread_id	= 0x74FCU + (SA2UL_INGRESS_QNUM),
	.sa2ul_egress_thread_id		= 0x74FCU + (2 * SA2UL_INGRESS_QNUM),
	.udmap_tx_chan			= SA2UL_UDMAP_TX_CHAN_NUM,
	.udmap_txc_fifo_depth		= 0U,
	.udmap_rx_chan			= { 2U,				     3U},
	.udmap_rx_flow			= 8U,
	.tx_qnum			= 8U,
	.txcq_qnum			= 8U,
	.rxfq_qnum			= 24U,
	.rxcq_qnum			= 24U,
	.ra_isc_id			= 0U,
	.ra_fwl_id			= 0U,
	.priority			= 0U,
	.qos				= 0U,
	.orderid			= 0U,
	.sched_priority			= 0U
};
