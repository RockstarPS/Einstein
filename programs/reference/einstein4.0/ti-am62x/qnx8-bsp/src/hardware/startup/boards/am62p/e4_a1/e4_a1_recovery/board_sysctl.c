/*
 * $QNXLicenseC:
 * Copyright 2020-2023 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You
 * may not reproduce, modify or distribute this software except in
 * compliance with the License. You may obtain a copy of the License
 * at: http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * This file may contain contributions from others, either as
 * contributors under the License or as licensors under other terms.
 * Please review this entire file for other proprietary rights or license
 * notices, as well as the QNX Development Suite License Guide at
 * http://licensing.qnx.com/license-guide/ for other information.
 * $
 */

#include <stdbool.h>
#include "startup.h"
#include "board.h"
#include "aarch64/aarch64_tlb.h"

/*
 * Enable/disable the various system controls.
 * This code is hardware dependant and may have to be changed
 * by end users.
 */

#define SDRAM_BASE_ADDR     (IDK_DDR0_BASE)
#ifndef STARTUP_SDRAM_SIZE
#define STARTUP_SDRAM_SIZE  (IDK_DDR0_SIZE)
#endif

static uint64_t aarch64_tlb_am62p[TLB_SIZE] __attribute__ ((aligned(64 * 1024)));

static aarch64_tlb_t board_tlb[] = {
    {
        .start = SDRAM_BASE_ADDR,
        .len   = STARTUP_SDRAM_SIZE,
        .attr  = (0x4 << 2),
    },
    {
        .start = -1, .len = -1, .attr = 0,
    },
};

void
board_mmu_enable(void)
{
    aarch64_setup_tlb(board_tlb, aarch64_tlb_am62p);
    aarch64_enable_mmu((uint64_t)aarch64_tlb_am62p);
}

void
board_mmu_disable(void)
{
    aarch64_disable_mmu();
}

void
board_alignment_check_enable(void)
{
    aarch64_alignment_check_enable();
}

void
board_alignment_check_disable(void)
{
    aarch64_alignment_check_disable();
}

void
board_dcache_enable(void)
{
    aarch64_dcache_enable();
}

void
board_dcache_disable(void)
{
    aarch64_dcache_disable();
}

void
board_icache_enable(void)
{
    aarch64_icache_enable();
}

void
board_icache_disable(void)
{
    aarch64_icache_disable();
}

void
board_enable_caches(void)
{
    board_icache_enable();
    board_dcache_enable();
}

void
board_disable_caches(void)
{
    board_icache_disable();
    board_dcache_disable();
}

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/branches/7.1.0/trunk/hardware/startup/boards/am62p/evm/board_sysctl.c $ $Rev: 988992 $")
#endif
