/*
 * Copyright (c) 2019 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * PROPRIETARY/CONFIDENTIAL
 *
 * This software is the confidential and proprietary information of
 * SAMSUNG ELECTRONICS ("Confidential Information").
 *
 * You shall not disclose such Confidential Information and shall use it
 * only in accordance with the terms of the license agreement
 * you entered into with SAMSUNG ELECTRONICS.
 *
 * SAMSUNG make no representations or warranties about the suitability of
 * the software, either express or implied, including but not limited to
 * the implied warranties of merchantability, fitness for a particular
 * purpose, or non-infringement. SAMSUNG shall not be liable for any
 * damages suffered by licensee as a result of using, modifying or
 * distributing this software or its derivatives.
 */

#ifndef ARCH_HELPER_H
#define ARCH_HELPER_H

#include <stdint.h>

void __wfi_workaround(void);
void __wfi_loop_workaround(void);
void __wfe_workaround(void);
void __sev(void);
void __isb(void);

void __dsb_ish(void);
void __dsb_ishst(void);
void __dmb_ish(void);
void __dmb_ishst(void);

void arch_local_irq_enable(void);
void arch_local_irq_disable(void);
void arch_local_fiq_enable(void);
void arch_local_fiq_disable(void);

void flush_dcache_range(void* addr, int size);
void clean_dcache_range(void* addr, int size);
void inv_dcache_range(void* addr, int size);
void clean_invalidate_dcache_range(void *start, void* end);

uint32_t core_read_mode(void);
uint8_t __get_cpuid(void);

#endif
