/*
 * System Firmware NAVSS UDMAP Library
 *
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file udmap.h
 *
 * \brief Include file for the description of UDMAP
 *	  private use of drivers
 */

#ifndef UDMAP_H
#define UDMAP_H

#include <types/fterr.h>
#include <types/ftbool.h>
#include <types/short_types.h>
#include <types/address_types.h>

/**
 * \brief Describes a Ring Accelerator Instance
 * \param cfg_tchanrt - Base address for Tx channel RT region
 *
 * \param cfg_tchan - Base address for Tx channel CFG region
 *
 * \param cfg_rchan - Base address for Rx channel CFG region
 *
 * \param cfg_gcfg - Base address for GCFG region
 *
 * \param cfg_rchanrt - Base address for Rx channel RT region
 *
 * \param cfg_rflow - Base address for Rx flow region
 *
 * \param num_tx_chans - Number of Tx channels
 *
 * \param num_rx_chans - Number of Rx channels
 *
 * \param num_rx_flows - Number of Rx flows
 *
 * This structure describes an instance of udmap in the SoC.
 * Addresses provided here are physical addresses from the perspective
 * of SoC base address map.
 */
struct udmap {
	soc_phys_addr_t cfg_tchanrt;
	soc_phys_addr_t cfg_tchan;
	soc_phys_addr_t cfg_rchan;
	soc_phys_addr_t cfg_gcfg;
	soc_phys_addr_t cfg_rchanrt;
	soc_phys_addr_t cfg_rflow;
	u16		num_tx_chans;
	u16		num_rx_chans;
	u16		num_rx_flows;
};

/** Instances of UDMAP */
extern const struct udmap soc_udmap_instances[];
/** Num of UDMAP */
extern const u8 soc_udmap_instances_num;

/**
 * \brief Priority and QoS information for UDMA channels
 *
 * \param priority - 3-bit 'priority' value output with each memory transaction
 *                   on the soc interconnect
 * \param qos      - 3-bit 'qos' value output with each memory transaction
 *                   on the soc interconnect
 * \param orderid  - 4-bit 'orderid' value output with each memory transaction
 *                   on the soc interconnect
 * \param sched_priority  - Scheduling priority of this channel within UDMA IP
 */
struct udmap_qos {
	u8	priority;
	u8	qos;
	u8	orderid;
	u8	sched_priority;
};

#define UDMAP_SCHED_HIGH_PRIORITY         (0U)
#define UDMAP_SCHED_MEDIUM_HIGH_PRIORITY  (1U)
#define UDMAP_SCHED_MEDIUM_LOW_PRIORITY   (2U)
#define UDMAP_SCHED_LOW_PRIORITY          (3U)

/**
 * \brief helper function to do the configuration of a udmap rx channel
 *        for packet based transfer type over PSIL
 *
 * \param id - UDMAP instance (ID) number
 *
 * \param chan - UDMA channel number to be configured
 *
 * \param descr_size - Size of descriptors used for this channel in bytes
 *
 * \param qos - Channel quality-of-service params
 *
 * \param thread_id - Thread ID using in PSIL messages
 *
 * \param rxcq_qnum - Completion queue number
 *
 * \param flowid_start - Starting index of rx flows associated with this rx
 *                     channel
 * \param flowid_count - Number of rx flows associated with this rx channel
 *
 * The helper function does expect caller to do all required authentication
 * mapping from physical address to virtual address, etc.
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr udmap_rxchan_setup_psil_pkt_mode(u16 id, u16 chan, u32 descr_size, struct udmap_qos qos, u16 thread_id, u16 rxcq_qnum, u16 flowid_start, u16 flowid_count);
/**
 * \brief helper function to do the configuration of a udmap tx channel
 *        for packet based transfer type over PSIL
 *
 * \param id - UDMAP instance (ID) number
 *
 * \param chan - UDMA channel number to be configured
 *
 * \param descr_size - Size of descriptors used for this channel in bytes
 *
 * \param qos - Channel quality-of-service params
 *
 * \param thread_id - Thread ID where the packet is sent to
 *
 * \param txcq_qnum - Completion queue number
 *
 * \param fifo_depth - FIFO depth in bytes for the channel
 *
 * The helper function does expect caller to do all required authentication
 * mapping from physical address to virtual address, etc.
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr udmap_txchan_setup_psil_pkt_mode(u16 id, u16 chan, u32 descr_size, struct udmap_qos qos, u16 thread_id, u16 txcq_qnum, u16 fifo_depth);

/**
 * \brief helper function to do set the enable bit for a udmap tx channel
 *
 * \param id - UDMAP instance (ID) number
 *
 * \param chan - UDMA channel number to be configured
 *
 * \param enable - Value to set to the enable bit
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr udmap_txrt_set_enable(u16 id, u16 chan, u8 enable);

/**
 * \brief helper function to do teardown a udmap tx channel
 *
 * \param id - UDMAP instance (ID) number
 *
 * \param chan - UDMA channel number to be configured
 *
 * \param force - Force a teardown
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr udmap_txrt_teardown(u16 id, u16 chan, ftbool force);

/**
 * \brief helper function to do get the enable bit for a udmap tx channel
 *
 * \param id - UDMAP instance (ID) number
 *
 * \param chan - UDMA channel number to be configured
 *
 * \param enable - Value of the enable bit (returned)
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr udmap_txrt_get_enable(u16 id, u16 chan, u8 *enable);

/**
 * \brief helper function to do get the Tx RT error bit
 *
 * \param id - UDMAP instance (ID) number
 *
 * \param chan - UDMA channel number to be configured
 *
 * \param err - Value of the err bit (returned)
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr udmap_txrt_get_error(u16 id, u16 chan, u32 *err);

/**
 * \brief helper function to do get the Rx RT error bit
 *
 * \param id - UDMAP instance (ID) number
 *
 * \param chan - UDMA channel number to be configured
 *
 * \param err - Value of the err bit (returned)
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr udmap_rxrt_get_error(u16 id, u16 chan, u32 *err);

/**
 * \brief helper function to do set the enable bit for a udmap rx channel
 *
 * \param id - UDMAP instance (ID) number
 *
 * \param chan - UDMA channel number to be configured
 *
 * \param enable - Value to set to the enable bit
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr udmap_rxrt_set_enable(u16 id, u16 chan, u8 enable);

/**
 * \brief helper function to do teardown a udmap rx channel
 *
 * \param id - UDMAP instance (ID) number
 *
 * \param chan - UDMA channel number to be configured
 *
 * \param force - Force a teardown
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr udmap_rxrt_teardown(u16 id, u16 chan, ftbool force);

/**
 * \brief helper function to do get the enable bit for a udmap rx channel
 *
 * \param id - UDMAP instance (ID) number
 *
 * \param chan - UDMA channel number to be configured
 *
 * \param enable - Value of the enable bit (returned)
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr udmap_rxrt_get_enable(u16 id, u16 chan, u8 *enable);

/**
 * \brief helper function to setup a simple configuration on a rx flow
 *
 * \param id - UDMAP instance (ID) number
 *
 * \param chan - UDMA channel number to be configured
 *
 * \param free_qnum - Queue (ring) that contains free buffers
 *
 * \param dest_qnum - Queue (ring) where rx packets are pushed after transfer
 *                    complete
 *
 * \param einfo_present - Set to 1 if extended info is present in incoming
 *                        packets
 * \param psinfo_present - Set to 1 if protocol-specific info is present in
 *                         incoming packets
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr udmap_rxflow_setup_simple(u16 id, u16 chan, u16 free_qnum, u16 dest_qnum, u8 einfo_present, u8 psinfo_present);

#endif
