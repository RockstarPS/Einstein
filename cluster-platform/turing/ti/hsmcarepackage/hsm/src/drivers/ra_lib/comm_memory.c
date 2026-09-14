/*
 * System Firmware Secure Proxy Communication memory description
 *
 * Copyright (C) 2019-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <types/address_types.h>
#include <types/errno.h>
#include <comm_memory.h>
#include <comm_memory_soc.h>
#include <osal_halt.h>

struct comm_memory_current_usage_t {
	soc_phys_addr_t endaddr;
};

static struct comm_memory_current_usage_t comm_memory_current_usage[COMM_MEMORY_INSTANCE_COUNT] = { 0U };

soc_phys_addr_t comm_memory_base_addr(u8 memory_inst, u32 offset)
{
	const struct comm_memory_instance *comm;
	struct comm_memory_current_usage_t *current_comm;

	/* The following checks should NEVER FAIL.. But do a defensive check */
	if (memory_inst >= COMM_MEMORY_INSTANCE_COUNT) {
		osal_system_halt(-EINVAL);
	}
	comm = &(comm_memory_instances[memory_inst]);
	current_comm = &(comm_memory_current_usage[memory_inst]);
	if (offset >= comm->size) {
		osal_system_halt(-EINVAL);
	}

	if (current_comm->endaddr == 0U) {
		current_comm->endaddr = comm->default_endaddr;
	}

	return current_comm->endaddr - offset;
}

s32 comm_memory_get_usable_end_addr(u8 memory_inst, soc_phys_addr_t *addr)
{
	const struct comm_memory_instance *comm;
	struct comm_memory_current_usage_t *current_comm;
	s32 ret = SUCCESS;

	if (memory_inst >= COMM_MEMORY_INSTANCE_COUNT) {
		ret = -EINVAL;
	}
	if (addr == NULL) {
		ret = -EINVAL;
	}

	if (ret == SUCCESS) {
		comm = &(comm_memory_instances[memory_inst]);
		current_comm = &(comm_memory_current_usage[memory_inst]);

		if (current_comm->endaddr == 0U) {
			current_comm->endaddr = comm->default_endaddr;
		}
		*addr = current_comm->endaddr - comm->size - 1U;
	}
	return ret;
}

s32 comm_memory_set_end_addr(u8 memory_inst, u32 reduce_bytes_default)
{
	const struct comm_memory_instance *comm;
	struct comm_memory_current_usage_t *current_comm;
	s32 ret = SUCCESS;

	if (memory_inst >= COMM_MEMORY_INSTANCE_COUNT) {
		ret = -EINVAL;
	}
	if (ret == SUCCESS) {
		comm = &(comm_memory_instances[memory_inst]);
		current_comm = &(comm_memory_current_usage[memory_inst]);
		current_comm->endaddr = comm->default_endaddr - reduce_bytes_default;
	}
	return ret;
}
