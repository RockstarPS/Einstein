#ifndef _HW_INOUT_INCLUDED
#define _HW_INOUT_INCLUDED

#include <stdint.h>

uint32_t in32(uintptr_t __addr);
void out32(uintptr_t __addr, uint32_t __data);
uint64_t ClockCycles (void);

#endif

