/*
 * System Firmware Source File
 *
 * Sec DMA SoC Data for AM62p device
 *
 * Copyright (C) 2022-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sec_dma_soc_data.c
 *
 * \brief Secure dma manager SoC Data for AM62px device
 */

#include <sec_dma_bootcfg.h>

#define SA2UL_INGRESS_QNUM (1U)
#define SA2UL_UDMAP_TX_CHAN_NUM (1U)

/**
 * The initial DMA configuration must match DMSC ROM usage of DMA to
 * keep things simple. The DMSC firmware assumes that firewalls
 * for these rings and channels are open by DMSC ROM.
 */
const struct sec_dma_bootcfg sec_dma_inital_cfg = {
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


#if defined(CONFIG_SECURITY_FIREWALL) || defined(CONFIG_LPM_FS_STUB)

/* DMSS MMR space start address */
#define PKTDMA_MMR_START_ADDR (0x44800000U)

/* DMSS MMR spce end address */
#define PKTDMA_MMR_END_ADDR   (0x44FFFFFFU)

/* ISC control world to enable region to
 * configure secure outgoing with dmsc privID
 */
#define DMSC_ISC_CONTROL_SECURE (0xACA0AU)

struct isc_region_info dmsc_isc_dma_config = {
	.isc_id		= 34U,
	.region		= 0U,
	.control[0] = DMSC_ISC_CONTROL_SECURE,
	.control[1] = 0,
	.start_address	= PKTDMA_MMR_START_ADDR,
	.end_address	= PKTDMA_MMR_END_ADDR
};

#endif
