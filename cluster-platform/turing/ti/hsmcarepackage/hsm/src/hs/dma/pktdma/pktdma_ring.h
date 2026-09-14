/*
 * Copyright (C) 2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file pktdma_ring.h
 *
 * \brief Function prototypes from PKTDMA ring driver
 * This is a forked from the ring accelerator driver
 * as there are incompatible macro changes
 *
 */
#ifndef PKTDMA_RING_H
#define PKTDMA_RING_H
#include <types/sbool.h>
#include <types/short_types.h>
#include <types/address_types.h>

/*  PKT DMA rings only support one mode */
#define PKT_RING_MODE_EXPOSED (1U)
#define PKT_RING_ELSIZE_8     (1U)

/**
 * \brief Describes a Ring Accelerator Instance
 * \param baseaddr_cfg__cfg - Baseaddress of cfg_cfg region
 *
 * \param baseaddr_cfg__rt - Baseaddress of cfg_rt region
 *
 * \param num_rings - Number of supported rings (private)
 *
 * This structure describes an instance of Ring accelerator in the SoC
 * Addresses provided here are physical addresses from the perspective
 * of SoC base address map.
 */
struct pktdma_ring {
	soc_phys_addr_t baseaddr_cfg__cfg;
	soc_phys_addr_t baseaddr_cfg__rt;
	u16		num_rings;
};

/** Instances of Ring Accelerators */
extern const struct pktdma_ring soc_pktdma_ring_instances[];
/** Num of Ring Accelerators */
extern const u8 soc_pktdma_ring_instances_num;

/**
 * \brief Configuration information for a specific ring
 * \param ra_idx - points to the ring accelerator instance.
 *      Indexes to \ref soc_ring_accelerator_instances
 *
 * \param ring_index - Ring index (base 0) to configure
 *
 * \param num_entries - Number of entries for the ring
 *
 * \param ring_mode - Ring mode - one of RING_MODE* macros
 *
 * \param elsize - Element size - one of RING_ELSIZE_* macros
 *
 * \param buffer_idx - index to comm_memory_instances for the buffer to use
 *
 * \param buffer_neg_offset - Negative offset(in bytes) to identify the
 *	start address of backing memory used for this instance. This offset is
 *	relative to the end address of the memory region. The offset values are
 *	intended to be constant for an SoC configuration even the end address
 *	of the region varies.
 *
 * This provides the configuration of a single ring.
 */
struct pktdma_ring_config {
	u8	ra_idx;
	u8	buffer_idx;
	u16	ring_index;
	u16	num_entries;
	u8	ring_mode;
	u8	elsize;
	u32	buffer_neg_offset;
};

/**
 * \brief Configure a ring
 *
 * Configure a ring specific to a pktdma
 *
 * \param rconfig - Ring configuration
 *
 * \param base - base address for ring configuration
 *
 * \return 0 if all went fine, else return corresponding error
 */
s32 pkt_ring_setup_ring_ba(const struct pktdma_ring_config *rconfig, soc_phys_addr_t base);

/**
 * \brief Wait for ring occupancy to be > 0
 *
 * \param ra_idx - points to the ring accelerator instance
 *
 * \param ring_index - Ring index (base 0) to configure
 *
 * \param tmout_us - Timeout in microseconds
 *
 * \return 0 if all went fine, else return corresponding error
 */
s32 pkt_ring_wait_for_mesg(u8 ra_idx, u16 ring_index, u32 tmout_us);

/**
 * \brief Push single (TR or PKT) descriptor address to indirect exposed ring
 *	It is assumed this is only context pushing ring (single producer).
 *
 * \param ra_idx - index of ring accelerator instance
 *
 * \param ring_index - Ring index (base 0) to push
 *
 * \param elem_index - On input ptr to ring index to insert.  On output
 *	next ring index to be inserted.  Caller must save this value
 *      because some hardware doesn't save this state.
 *
 * \param data - physical address pointer to insert into ring
 *
 * \return 0 if all went fine, else return corresponding error
 */
s32 pkt_ring_push(u8 ra_idx, u16 ring_index, u16 *elem_index, soc_phys_addr_t data);

/**
 * \brief Pop single (TR or PKT) descriptor address from indirect exposed ring.
 *	It is assumed this is only context popping ring (single consumer).
 *
 * \param ra_idx - index of ring accelerator instance
 *
 * \param ring_index - Ring index (base 0) to push
 *
 * \param elem_index - On input ptr to ring index to read.  On output
 *	next ring index to be read.  Caller must save this value
 *      because some hardware doesn't save this state.
 *
 * \param data - pointer to physical address pointer popped from ring
 *	(functional return value)
 *
 * \return 0 if all went fine, else return corresponding error.  Note, if data
 *	is NULL ring is empty (not considered error)
 */
s32 pkt_ring_pop(u8 ra_idx, u16 ring_index, u16 *elem_index, soc_phys_addr_t *data);

#endif /* __PKTDMA_RING_H_ */
