/*
 * Copyright (C) 2020-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sec_pktdma.c
 *
 * \brief DMA APIs for security module internal use
 * Uses PKT DMA for data transfer
 *
 */

#include <config.h>
#include <stddef.h>

#include <osal_hwi.h>

#include <sec_dma.h>
#include <socmem.h>
#include <masters.h>
#include <hosts.h>
#include <hosts_internal.h>
#include <psilcfg.h>
#include <cred.h>
#include "udmap.h"
#include "pktdma_ring.h"
#include "lib/bitops.h"
#include "trace.h"

#define SEC_DMA_RA_MODE             PKT_RING_MODE_EXPOSED
#define SEC_DMA_RA_ELSIZE_BYTES     8U
#define SEC_DMA_RA_ELSIZE           PKT_RING_ELSIZE_8
#define SEC_DMA_RA_NELEMS           8U
#define SEC_DMA_RA_MEM_SIZE         (SEC_DMA_RA_ELSIZE_BYTES * \
				     SEC_DMA_RA_NELEMS)

/**
 * Memory reserved for UDMA Tx descriptors and ring backing memory.
 *
 * \param descr Memory for 1 Tx descriptor
 * \param ra_mem Memory for ring accelerator backing memory (for 2 rings)
 */
static struct sec_dma_tx_mem {
	struct udmap_descr_host_full	descr;
	u8				ra_mem[2][SEC_DMA_RA_MEM_SIZE];
} sec_dma_tx_scratch_mem
__attribute__((__section__(".sec_dma_tx_scratch_mem"), aligned(16)));

/**
 * Memory reserved for UDMA Rx descriptors and ring backing memory.
 *
 * \param descr Memory for 1 Rx descriptor
 * \param ra_mem Memory for ring accelerator backing memory (for 2 rings)
 */
static struct sec_dma_rx_mem {
	struct udmap_descr_host_full	descr;
	u8				ra_mem[2][SEC_DMA_RA_MEM_SIZE];
} sec_dma_rx_scratch_mem
__attribute__((__section__(".sec_dma_rx_scratch_mem"), aligned(16)));

/**
 * State memory to track location (inptr/outptr) for exposed rings.  Names
 * mirror queue names in \ref sec_dma_bootcfg.
 *
 * \param tx_in_idx Element index for next insertion (push) into tx q.
 * \param txcq_out_idx Element index for next pop from tx cq
 * \param rxfq_in_idx Element index for next insertion (push) to rx fq
 * \param rxcq_out_idx Element index for next pop from rx cq
 */
struct sec_dma_ring_state {
	u16	tx_in_idx;
	u16	txcq_out_idx;
	u16	rxfq_in_idx;
	u16	rxcq_out_idx;
};

/**
 * Firewall ID and region info for setting up firewalls for Rx and Tx scratch
 * memories
 *
 * \param id Firewall ID
 * \param region Firewall region
 * \param addr Physical address of the region to be configured
 * \param creds Credentials of the master to be programmed in the firewall
 * \param fwl_perm value to be programmed into firewall permission registers.
 *                 This is another representation of the data in creds above.
 */
struct sec_dma_fwl_info {
	u16			id;
	u16			region;
	soc_phys_addr_t		addr;
	struct master_creds	creds;
	u32			fwl_perm;
};

/**
 * \brief Local state of secure DMA module
 *
 * \param initial_cfg Flag indicating if this module is in initial configuration
 *                    state
 * \param full_init_done Flag indicating if a full init of this module is done
 * \param dma_tdown_done flag indicating if dma is torn down successfully
 * \param available Flag indicating if this module is in use or not
 * \param bootcfg Boot configuration data pointer
 * \param rx_fwl_info Information required to setup firewalls for the rx
 *                    scratch memory region
 * \param tx_fwl_info Information required to setup firewalls for the tx
 *                    scratch memory region
 * \param exposed_ring_state structure to track state of the exposed ring
 *                           used for triggering pktdma
 */
static struct sec_pktdma_state {
	ftbool				init_done;
	ftbool				full_init_done;
	ftbool				dma_tdown_done;
	ftbool				available;
	const struct sec_dma_bootcfg	*bootcfg;
	struct sec_dma_fwl_info		rx_fwl_info;
	struct sec_dma_fwl_info		tx_fwl_info;
	struct sec_dma_ring_state	exposed_ring_state;
} sec_dma_st;

/**
 * Initial configuration for the sec_dma module
 */
extern const struct sec_dma_bootcfg sec_dma_inital_cfg;
/**
 * Runtime configuration for sec_dma module
 */
extern const struct sec_dma_bootcfg sec_dma_bootcfg_data;
/**
 *  TIFS ISC configuration for sec_dma module
 */
extern struct isc_region_info dmsc_isc_dma_config;

#ifdef CONFIG_SECURITY_FIREWALL

static fterr sec_dma_clear_creds(u16 ch, const struct sec_dma_fwl_info *info __attribute__((unused)))
{
	fterr ret = -EINVAL;

	const struct sec_dma_bootcfg *b = sec_dma_st.bootcfg;

	u32 regVal, discard_control_mask;


	regVal = 0;

	if (ft_is_true(cred_get_region(HOST_ID_TIFS, b->ra_isc_id, ch, &discard_control_mask))) {
		ret = cred_set_region(HOST_ID_TIFS, b->ra_isc_id,
				      ch,
				      regVal);
	}

	return ret;
}

/**
 * Function to set the firewall permissions for the memory region holding
 * dma Tx and Rx descriptors
 *
 * \param info Host credentials information - priv-id, priv and secure
 * \param enable Flag indicating whether the firewall region must be enabled
 *               or disabled.
 *
 * \return EFTOK if everything went well
 */

#endif

/**
 * Check and teardown (if enabled) the UDMAP Tx channel
 *
 * \return EFTOK if everything went well
 */
static fterr sec_dma_udmap_tx_tdown(void)
{
	const struct sec_dma_bootcfg *b = sec_dma_st.bootcfg;
	fterr ret;
	u8 enable;

	ret = udmap_txrt_get_enable(b->udmap_id, b->udmap_tx_chan,
				    &enable);
	if (ret == EFTOK) {
		if (enable != 0U) {
			ret = udmap_txrt_teardown(b->udmap_id,
						  b->udmap_tx_chan,
						  FT_TRUE);
		}
	}
	return ret;
}

/**
 * Configure the UDMAP Tx channel based on the current state and config
 * information.
 *
 * \return EFTOK if everything went well
 */
static fterr sec_dma_udmap_tx_config(void)
{
	const struct sec_dma_bootcfg *b = sec_dma_st.bootcfg;
	fterr ret = EFTOK;
	u32 descr_size;
	struct udmap_qos qos;

	descr_size = sizeof(struct udmap_descr_host_full);
	qos.priority = b->priority;
	qos.qos = b->qos;
	qos.orderid = b->orderid;
	qos.sched_priority = b->sched_priority;
	if (ret == EFTOK) {
		ret = udmap_txchan_setup_psil_pkt_mode(b->udmap_id,
						       b->udmap_tx_chan,
						       descr_size,
						       qos,
						       0U,
						       b->txcq_qnum,
						       b->udmap_txc_fifo_depth);
	}
	return ret;
}


/**
 * Check and teardown (if enabled) the UDMAP Rx channel
 *
 * \return EFTOK if everything went well
 */
static fterr sec_dma_udmap_rx_tdown(u32 idx)
{
	const struct sec_dma_bootcfg *b = sec_dma_st.bootcfg;
	fterr ret;
	u8 enable;

	ret = udmap_rxrt_get_enable(b->udmap_id, b->udmap_rx_chan[idx],
				    &enable);
	if (ret == EFTOK) {
		if (enable != 0U) {
			ret = udmap_rxrt_teardown(
				b->udmap_id,
				b->udmap_rx_chan[idx],
				FT_TRUE);
		}
	}
	return ret;
}

/**
 * Configure the UDMAP Rx channel based on the current state and config
 * information.
 *
 * \param idx Rx channel index. Sec DMA module uses 2 Rx channels for SA2UL.
 *
 * \return EFTOK if everything went well
 */
static fterr sec_dma_udmap_rx_config(u32 idx)
{
	const struct sec_dma_bootcfg *b = sec_dma_st.bootcfg;
	fterr ret = EFTOK;
	u32 descr_size;
	struct udmap_qos qos;

	descr_size = sizeof(struct udmap_descr_host_full);
	qos.priority = b->priority;
	qos.qos = b->qos;
	qos.orderid = b->orderid;
	qos.sched_priority = b->sched_priority;

	if (!ft_is_true(sec_dma_st.dma_tdown_done)) {
		/*
		 * Check if udmap rx channel is already enabled, if so, teardown
		 * the channel#define SMS_HSM_OWNED_RING_RANGE2_MAX 48U
		 */
		ret = sec_dma_udmap_rx_tdown(idx);
	}
	if (ret == EFTOK) {
		ret = udmap_rxchan_setup_psil_pkt_mode(b->udmap_id,
						       b->udmap_rx_chan[idx],
						       descr_size,
						       qos,
						       0U,
						       b->rxcq_qnum,
						       b->udmap_rx_flow, 1U);
	}
	return ret;
}

/**
 * Configure the UDMAP Rx flow based on the current state and config
 * information.
 *
 * \param via_sa2ul Flag indicating if the DMA is being set up for data
 *                  transfer through SA2UL or not.
 *
 * \return EFTOK if everything went well
 */
static fterr sec_dma_udmap_rx_flow_config(ftbool via_sa2ul)
{
	const struct sec_dma_bootcfg *b = sec_dma_st.bootcfg;
	fterr ret;
	u8 einfo_present, psinfo_present;

	if (ft_is_true(via_sa2ul)) {
		einfo_present = 1U;
		psinfo_present = 1U;
	} else {
		einfo_present = 0U;
		psinfo_present = 0U;
	}

	ret = udmap_rxflow_setup_simple(b->udmap_id, b->udmap_rx_flow,
					b->rxfq_qnum, b->rxcq_qnum,
					einfo_present, psinfo_present);

	return ret;
}

/**
 * Configure ring accelerator channel with base address and other configuration
 *
 * \return EFTOK if everything went well
 */
static fterr sec_dma_ring_config(void)
{
	struct pktdma_ring_config cfg;
	const struct sec_dma_bootcfg *b = sec_dma_st.bootcfg;
	soc_phys_addr_t buffer_baseaddr;
	fterr ret;

	cfg.ra_idx = b->ra_id;
	cfg.ring_index = b->tx_qnum;
	cfg.num_entries = SEC_DMA_RA_NELEMS;
	cfg.ring_mode = SEC_DMA_RA_MODE;
	cfg.elsize = SEC_DMA_RA_ELSIZE;

	buffer_baseaddr = sec_dma_st.tx_fwl_info.addr +
			  offsetof(struct sec_dma_tx_mem, ra_mem);

	ret = fterr_from_common(pkt_ring_setup_ring_ba(&cfg, buffer_baseaddr));

	if (ret == EFTOK) {
		buffer_baseaddr = sec_dma_st.rx_fwl_info.addr +
				  offsetof(struct sec_dma_rx_mem, ra_mem);
	}
	if (ret == EFTOK) {
		cfg.ring_index = b->rxfq_qnum;
		ret = fterr_from_common(pkt_ring_setup_ring_ba(&cfg, buffer_baseaddr));
	}
	if (ret == EFTOK) {
		sec_dma_st.exposed_ring_state.tx_in_idx = 0u;
		sec_dma_st.exposed_ring_state.txcq_out_idx = 0u;
		sec_dma_st.exposed_ring_state.rxfq_in_idx = 0u;
		sec_dma_st.exposed_ring_state.rxcq_out_idx = 0u;
	}
	return ret;
}


/**
 * Teardown psil thread pairing, this is only applicable for Tx threads
 *
 * \return EFTOK if everything went well
 */
static fterr sec_dma_teardown_psil_threads(void)
{
	fterr ret;
	const struct sec_dma_bootcfg *b = sec_dma_st.bootcfg;

	ret = psilcfg_teardown(b->psilcfg_id,
			       b->sa2ul_egress_thread_id);
	if (ret == EFTOK) {
		ret = psilcfg_teardown(b->psilcfg_id,
				       b->sa2ul_egress_thread_id + 1U);
	}
	return ret;
}

/**
 * Function to initialize and set all components required for DMA
 *
 * \param via_sa2ul Flag indicating if the DMA is being set up for data
 *                  transfer through SA2UL or not.
 *
 * \return EFTOK if everything went well
 */
static fterr sec_dma_setup(ftbool via_sa2ul __attribute__((unused)))
{
	fterr ret;
	const struct sec_dma_bootcfg *b = sec_dma_st.bootcfg;

	/*
	 * Configure Ring accelerator channels
	 */
	ret = sec_dma_ring_config();


	/*
	 * Setup UDMAP Tx channel
	 */
	if (ret == EFTOK) {
		ret = sec_dma_udmap_tx_config();
	}

	/*
	 * Setup UDMAP Rx channel
	 */
	if (ret == EFTOK) {
		ret = sec_dma_udmap_rx_config(0U);
		if (ret == EFTOK) {
			ret = sec_dma_udmap_rx_config(1U);
		}
	}

	/*
	 * Setup UDMAP Rx flow
	 */
	if (ret == EFTOK) {
		ret = sec_dma_udmap_rx_flow_config(FT_TRUE);
	}

	/*
	 * Enable UDMAP channels
	 */
	if (ret == EFTOK) {
		ret = udmap_rxrt_set_enable(
			b->udmap_id, b->udmap_rx_chan[0], 1U);
		if (ret == EFTOK) {
			ret = udmap_rxrt_set_enable(
				b->udmap_id, b->udmap_rx_chan[1], 1U);
		}
	}
	if (ret == EFTOK) {
		ret = udmap_txrt_set_enable(b->udmap_id, b->udmap_tx_chan, 1U);
	}


	if (ret == EFTOK) {
		sec_dma_st.dma_tdown_done = FT_FALSE;
	}
	return ret;
}

/**
 * Function to check for UDMAP errors
 *
 * \return EFTOK if there were no errors with UDMAP transfers
 */
static fterr sec_dma_check_for_udmap_errors(void)
{
	fterr ret;
	const struct sec_dma_bootcfg *b = sec_dma_st.bootcfg;
	u32 err0, err1, err2 = 0;

	ret = udmap_txrt_get_error(b->udmap_id, b->udmap_tx_chan, &err0);
	if (ret == EFTOK) {
		ret = udmap_rxrt_get_error(b->udmap_id,
					   b->udmap_rx_chan[0], &err1);
	}
	if (ret == EFTOK) {
		ret = udmap_rxrt_get_error(b->udmap_id,
					   b->udmap_rx_chan[1], &err2);
	}
	if (ret == EFTOK) {
		if ((err1 != 0U) || (err2 != 0U) || (err0 != 0)) {
			ret = -EFAIL;
		}
	}
	return ret;
}

fterr sec_dma_push_pkt(void)
{
	fterr ret;
	const struct sec_dma_bootcfg *b = sec_dma_st.bootcfg;

	struct sec_dma_ring_state *exp_state = &sec_dma_st.exposed_ring_state;
	s32 pkt_ring_ret;
	soc_phys_addr_t phys_addr;

	/*
	 * Push Rx descr to free queue
	 */
	phys_addr = sec_dma_st.rx_fwl_info.addr +
		    offsetof(struct sec_dma_rx_mem, descr);

	pkt_ring_ret = pkt_ring_push(b->ra_id,  b->rxfq_qnum,
				     &exp_state->rxfq_in_idx, phys_addr);
	ret = fterr_from_common(pkt_ring_ret);
	/*
	 * Push tx descr to tx-submit queue
	 */
	if (ret == EFTOK) {
		phys_addr = sec_dma_st.tx_fwl_info.addr  +
			    offsetof(struct sec_dma_tx_mem, descr);

		pkt_ring_ret = pkt_ring_push(b->ra_id, b->tx_qnum,
					     &exp_state->tx_in_idx, phys_addr);
		ret = fterr_from_common(pkt_ring_ret);
	}
	return ret;
}

fterr sec_dma_wait_for_pkt(u32 tmout_us)
{
	fterr ret;
	const struct sec_dma_bootcfg *b = sec_dma_st.bootcfg;
	struct sec_dma_ring_state *exp_state = &sec_dma_st.exposed_ring_state;
	s32 pkt_ring_ret;
	soc_phys_addr_t phys_addr;

	/*
	 * Wait for the packet to arrive at rx done queue
	 */
	ret = fterr_from_common(pkt_ring_wait_for_mesg(b->ra_id,b->rxcq_qnum,
						       tmout_us));
	if (ret == EFTOK) {
		pkt_ring_ret = pkt_ring_pop(b->ra_id, b->rxcq_qnum,
					    &exp_state->rxcq_out_idx, &phys_addr);
		ret = fterr_from_common(pkt_ring_ret);
	}
	if (ret == EFTOK) {
		ret = fterr_from_common(pkt_ring_wait_for_mesg(b->ra_id,
							       b->txcq_qnum,
							       tmout_us));
		if (ret == EFTOK) {
			pkt_ring_ret = pkt_ring_pop(b->ra_id, b->txcq_qnum,
						    &exp_state->txcq_out_idx,
						    &phys_addr);
			ret = fterr_from_common(pkt_ring_ret);
		}
	}
	ret = sec_dma_check_for_udmap_errors();
	
	return ret;
}

fterr sec_dma_init_with_initial_cfg(void)
{
	/*
	 * Pre-bootcfg data - must match ROM configuration
	 */
	sec_dma_st.bootcfg = &sec_dma_inital_cfg;
	sec_dma_st.init_done = FT_TRUE;
	sec_dma_st.full_init_done = FT_FALSE;
	sec_dma_st.available = FT_TRUE;
	/*
	 * ROM might not cleanup DMA resources when handing over to firmware
	 */
	sec_dma_st.dma_tdown_done = FT_FALSE;
	return EFTOK;
}

fterr sec_dma_init()
{
	fterr ret;

	/* init the data structures with the configuration used by ROM */
	ret = sec_dma_init_with_initial_cfg();

	sec_dma_st.rx_fwl_info.id= 641U;
	sec_dma_st.rx_fwl_info.region=1;

	sec_dma_st.tx_fwl_info.id=641U;
	sec_dma_st.tx_fwl_info.region=1; 

	if (ret == EFTOK) {
		ret = socmem_to_global((local_phys_addr_t)
				       &sec_dma_rx_scratch_mem,
				       &sec_dma_st.rx_fwl_info.addr);
	}

	if (ret == EFTOK) {
		ret = socmem_to_global((local_phys_addr_t)
				       &sec_dma_tx_scratch_mem,
				       &sec_dma_st.tx_fwl_info.addr);
	}


	return ret;
}

fterr sec_dma_reset(void)
{
	fterr ret = -EINVAL;
	u32 cpsr;
	const struct sec_dma_bootcfg *bootcfg = &sec_dma_bootcfg_data;

	/*
	 * Don't reset DMA if called while DMA is currently in use by other
	 * service, in case this comes from a pre-empted call. Also, don't
	 * allow use of DMA from pre-empted thread while in the midst of
	 * resetting.
	 */
	cpsr = osal_hwip_disable();
	if (ft_is_true(sec_dma_st.available)) {
		ret = EFTOK;
		sec_dma_st.available = FT_FALSE;
	}
	osal_hwip_restore(cpsr);

	/* Teardown old DMA channels before switching to new config */
	if (ret == EFTOK) {
		ret = sec_dma_teardown_psil_threads();
	}
	if (ret == EFTOK) {
		ret = sec_dma_udmap_tx_tdown();
	}
	if (ret == EFTOK) {
		ret = sec_dma_udmap_rx_tdown(0U);
	}
	if (ret == EFTOK) {
		ret = sec_dma_udmap_rx_tdown(1U);
	}

	if (ret == EFTOK) {
		sec_dma_st.full_init_done = FT_TRUE;
		sec_dma_st.dma_tdown_done = FT_TRUE;
		sec_dma_st.bootcfg = bootcfg;
	}

	/* DMA is available to access again */
	cpsr = osal_hwip_disable();
	sec_dma_st.available = FT_TRUE;
	osal_hwip_restore(cpsr);

	return ret;
}
extern const struct master_bootcfg_list master_list;

fterr sec_dma_grab(u8 read_host, u8 write_host,
		   ftbool via_sa2ul __attribute__((unused)),
		   local_phys_addr_t *tx_descr,
		   local_phys_addr_t *rx_descr)
{
	fterr ret = EFTOK;
	u32 cpsr;

#ifndef CONFIG_SECURITY_FIREWALL
	(void) read_host;
	(void) write_host;
#endif

	if (!ft_is_true(sec_dma_st.init_done)) {
		ret = -EINVAL;
	}

	if (ret == EFTOK) {
		ret = -EAGAIN;
		cpsr = osal_hwip_disable();
		if (ft_is_true(sec_dma_st.available)) {
			ret = EFTOK;
			sec_dma_st.available = FT_FALSE;
		}
		osal_hwip_restore(cpsr);
	}
#ifdef CONFIG_SECURITY_FIREWALL


	if (!ft_is_true(sec_dma_st.full_init_done)) {
		/*
		 * Get permissions for read_host
		 */
		masters_init(&master_list);
		if (ret == EFTOK) {
			ret = masters_get_host_attrs(
				HOST_ID_HSM,
				&sec_dma_st.tx_fwl_info.creds,
				&sec_dma_st.tx_fwl_info.fwl_perm);
		}

		/*
		 * Get permissions for write_host
		 */
		if (ret == EFTOK) {
			ret = masters_get_host_attrs(
				HOST_ID_HSM,
				&sec_dma_st.rx_fwl_info.creds,
				&sec_dma_st.rx_fwl_info.fwl_perm);
		}

	}
	
#endif

	if (ret == EFTOK) {
		ret = sec_dma_setup(FT_TRUE);
	}

	/*
	 * Enable DMA and create PSIL route if not already setup
	 */
	if (ret == EFTOK) {
		*tx_descr = (local_phys_addr_t)
			    &sec_dma_tx_scratch_mem.descr.base;
		*rx_descr = (local_phys_addr_t)
			    &sec_dma_rx_scratch_mem.descr.base;
	}
	return EFTOK;
}

fterr sec_dma_release(ftbool force_teardown)
{
	u32 cpsr;
	fterr ret = EFTOK;

#ifdef CONFIG_SECURITY_FIREWALL
	const struct sec_dma_bootcfg *b = sec_dma_st.bootcfg;
#endif

#ifdef CONFIG_SECURITY_FIREWALL
	/*
	 * Reset firewall for tx and rx descr region for TIFS only
	 */
	if (ft_is_true(sec_dma_st.full_init_done)) {
		if (ret == EFTOK) {
			ret = sec_dma_clear_creds(
				b->tx_qnum,
				&sec_dma_st.tx_fwl_info);
		}
		if (ret == EFTOK) {
			ret = sec_dma_clear_creds(
				b->rxfq_qnum,
				&sec_dma_st.rx_fwl_info);
		}
	}


#endif
	if (ret == EFTOK) {
		if (ft_is_true(force_teardown)) {
			/*
			 * Force a teardown next time
			 */
			sec_dma_st.dma_tdown_done = FT_FALSE;
		}
		cpsr = osal_hwip_disable();
		sec_dma_st.available = FT_TRUE;
		osal_hwip_restore(cpsr);
	}
	return ret;
}

fterr sec_dma_init_tx_descr(struct udmap_descr_host *txdescr,
			    soc_phys_addr_t from, u32 len,
			    ftbool einfo_present, u32 psdata_wcnt)
{
	fterr ret = EFTOK;
	const struct sec_dma_bootcfg *b = sec_dma_st.bootcfg;

	if (ret == EFTOK) {
		ret = udmap_pkt_descr_init_host_tx(txdescr, from, len,
						   einfo_present,
						   psdata_wcnt,
						   b->udmap_rx_flow,
						   b->txcq_qnum);
	}
	return ret;
}

fterr sec_dma_release_sa2ul_resources(void)
{
	return EFTOK;
}
