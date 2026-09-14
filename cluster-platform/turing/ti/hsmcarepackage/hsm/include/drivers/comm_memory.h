/*
 * System Firmware Secure Proxy Communication memory description
 *
 * Copyright (C) 2019-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file comm_memory.h
 *
 * \brief Include file for Secure Proxy Communication memory description
 *	routine
 */

#ifndef COMM_MEMORY_H
#define COMM_MEMORY_H

#include <types/short_types.h>
#include <types/address_types.h>

/**
 * \brief Communication Memory instance definition
 * \param default_endaddr - Default end address for buffer memory
 * \param size - Size allocated for the memory
 */
struct comm_memory_instance {
	soc_phys_addr_t default_endaddr;
	u32		size;
};

/** Communication memory instances */
extern const struct comm_memory_instance comm_memory_instances[];

/**
 * \brief Retrieve the address from a communication memory instance
 *
 * \param memory_inst SoC specific memory instance ID which indexes into
 *	comm_memory_instances
 * \param offset Negative offset from end of memory in bytes.
 *
 * \return Absolute address at SOC level within the region pointed to by
 * memory_inst
 */
soc_phys_addr_t comm_memory_base_addr(u8 memory_inst, u32 offset);

/**
 * \brief Lower the end address of the communication memory
 *
 * \param memory_inst SoC specific memory instance ID which indexes into
 *	comm_memory_instances
 * \param reduce_bytes_default How many bytes to drop from default end of
 *	memory
 *
 * \return SUCCESS in case of successful reduction of memory. returns
 *  -EINVAL in case of invalid instance
 */
s32 comm_memory_set_end_addr(u8 memory_inst, u32 reduce_bytes_default);

/**
 * \brief Get usable end address of the memory instance
 *
 * \param memory_inst SoC specific memory instance ID which indexes into
 *	comm_memory_instances
 * \param addr Return actual absolute address at SOC level within the
 * region pointed to by memory_inst
 *
 * \return SUCCESS in case of valid address, -EINVAL in case of bad pointer
 * or invalid instance
 */
s32 comm_memory_get_usable_end_addr(u8 memory_inst, soc_phys_addr_t *addr);

#endif  /* COMM_MEMORY_H */
