/*
 * Stub implementation for x86 simulation
 */

#include <stdint.h>

uint32_t HwiP_disable(void) {
    return 0;
}

uint32_t HwiP_disableFIQ(void) {
    return 0;
}

void HwiP_enable(void) {
}

void HwiP_enableFIQ(void) {
}

void HwiP_restore(uint32_t oldIntState) {
    (void)oldIntState;
}

void HwiP_enableVIC(void) {
}

void HwiP_disableVIC(void) {
}

uint32_t HwiP_getCPSR(void) {
    return 0;
}
