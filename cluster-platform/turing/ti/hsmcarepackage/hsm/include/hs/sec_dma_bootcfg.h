/*
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sec_dma_bootcfg.h
 *
 * \brief DMA APIs for security module internal use
 *
 */
#ifndef SEC_DMA_BOOTCFG_H_
#define SEC_DMA_BOOTCFG_H_

#include <types/ftbool.h>
#include <types/short_types.h>

/**
 * \brief Secure DMA module boot configuration
 *
 * \param ra_id RA instance number
 * \param proxy_id Proxy instance number
 * \param psilcfg_id PSILCFG instance number
 * \param udmap_id UDMAP instance number
 * \param sa2ul_id SA2UL instance number
 * \param proxy_chan Proxy chanel number to use
 * \param udmap_thread_id_base Base thread ID for UDMAP channels
 * \param sa2ul_ingress_thread_id Base thread ID for SA2UL ingress
 * \param sa2ul_egress_thread_id Base thread ID for SA2UL egress
 * \param udmap_tx_chan UDMAP Tx channel number allocated to this module
 * \param udmap_txc_fifo_depth Fifo depth for the tx channel
 * \param udmap_rx_chan UDMAP Rx channel numbers allocated to this module
 * \param udmap_rx_flow UDMAP Rx flow number allocated to this module
 * \param tx_qnum Ring (queue) number for Tx submit to UDMAP (must be same as
 *                udmap_tx_chan)
 * \param txcq_qnum Ring (queue) number for Tx completion
 * \param rxfq_qnum Ring (queue) number for Rx free descriptors
 * \param rxcq_qnum Ring (queue) number for Rx completion descriptors
 * \param ra_isc_id ISC ID for the ring accelerator ISC instance
 * \param ra_fwl_id Firewall ID of the channelized firewall that protects the
 *                  ring accelerator target data
 * \param priority - 3-bit 'priority' value output with each memory transaction
 *                   on the soc interconnect
 * \param qos      - 3-bit 'qos' value output with each memory transaction
 *                   on the soc interconnect
 * \param orderid  - 4-bit 'orderid' value output with each memory transaction
 *                   on the soc interconnect
 * \param sched_priority  - Scheduling priority of this channel within UDMA IP
 */
struct sec_dma_bootcfg {
	u8	ra_id;
	u8	proxy_id;
	u8	psilcfg_id;
	u8	udmap_id;
	u8	sa2ul_id;
	u16	proxy_chan;
	u16	udmap_thread_id_base;
	u16	sa2ul_ingress_thread_id;
	u16	sa2ul_egress_thread_id;
	u16	udmap_tx_chan;
	u16	udmap_txc_fifo_depth;
	u16	udmap_rx_chan[2];
	u16	udmap_rx_flow;
	u16	tx_qnum;
	u16	txcq_qnum;
	u16	rxfq_qnum;
	u16	rxcq_qnum;
	u16	ra_isc_id;
	u16	ra_fwl_id;
	u8	priority;
	u8	qos;
	u8	orderid;
	u8	sched_priority;
} __attribute__((packed));

#endif /* SEC_DMA_BOOTCFG_H_ */
