/*
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sa2ul_soc_data.c
 *
 * \brief SoC Data for SA2UL module
 */

#include "ftbool.h"
#include "sa2ul.h"
#include "master_ids.h"
#include "hosts.h"
#include "hosts_internal.h"

struct sa2ul sa2ul_socdata = {
	.num_instances	= 1U,
	.base_addr	= { 0x40900000ULL },
	.pka_region	= 3U,
};
