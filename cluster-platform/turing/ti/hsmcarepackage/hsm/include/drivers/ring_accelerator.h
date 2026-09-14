/*
 * System Firmware Ring Accelerator Library
 *
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file ring_accelerator.h
 *
 * \brief Include file for the description of Ring Accelerator and init
 *	function - private use of drivers
 */

#ifndef RING_ACCELERATOR_H
#define RING_ACCELERATOR_H

#include <config.h>
#include <types/sbool.h>
#include <types/short_types.h>
#include <types/address_types.h>
#include <types/devgrps.h>
#include <ringaccelerator.h>

/**
 * \brief Describes a Ring Accelerator Instance
 * \param baseaddr_cfg__cfg - Baseaddress of cfg_cfg region
 *
 * \param baseaddr_cfg__rt - Baseaddress of cfg_rt region
 *
 * \param num_rings - Number of supported rings (private)
 *
 * \param devgrp - sysfw devgrp that this instance belongs to
 *
 * This structure describes an instance of Ring accelerator in the SoC
 * Addresses provided here are physical addresses from the perspective
 * of SoC base address map.
 */
struct ring_accelerator {
	soc_phys_addr_t baseaddr_cfg__cfg;
	soc_phys_addr_t baseaddr_cfg__rt;
	u16		num_rings;
	devgrp_t	devgrp;
};

/** Instances of Ring Accelerators */
extern const struct ring_accelerator soc_ring_accelerator_instances[];
/** Num of Ring Accelerators */
extern const u8 soc_ring_accelerator_instances_num;

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
struct ring_config {
	u8	ra_idx;
	u8	buffer_idx;
	u16	ring_index;
	u16	num_entries;
	u8	ring_mode;
	u8	elsize;
	u32	buffer_neg_offset;
};

#define RING_MODE_EXPOSED_RING  0
#define RING_MODE_MESSAGE       1
#define RING_MODE_CREDENTIAL    2
#define RING_MODE_QUEUE         3

#define RING_ELSIZE_8           1
#define RING_ELSIZE_16          2
#define RING_ELSIZE_32          3
#define RING_ELSIZE_64          4
#define RING_ELSIZE_128         5
#define RING_ELSIZE_256         6

/** Ring configurations */
extern const struct ring_config soc_ring_configurations[];
/** Num Ring configurations */
extern const u16 soc_ring_configurations_num;

/**
 * \brief Configure a ring
 *
 * Configure a ring specific to a ring accelerator
 *
 * \param rconfig - Ring accelerator configuration
 *
 * \return 0 if all went fine, else return corresponding error
 */
#ifdef CONFIG_RA_LIB
extern s32 ralib_setup_ring(const struct ring_config *rconfig);
extern s32 ralib_setup_ring_ba(const struct ring_config *rconfig, soc_phys_addr_t base);
#else
static inline s32 ralib_setup_ring(const struct ring_config *rconfig)
{
	return 0;
}
static inline s32 ralib_setup_ring_ba(const struct ring_config *rconfig, soc_phys_addr_t base)
{
	return 0;
}
#endif
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
#ifdef CONFIG_RA_LIB
extern s32 ralib_wait_for_mesg(u8 ra_idx, u16 ring_index, u32 tmout_us);
#else
static inline s32 ralib_wait_for_mesg(u8 ra_idx, u16 ring_index, u32 tmout_us)
{
	return -EINVAL;
}
#endif
#endif
