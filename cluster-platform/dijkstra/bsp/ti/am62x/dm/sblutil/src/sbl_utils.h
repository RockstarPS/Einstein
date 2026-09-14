#ifndef __SBL_UTILS_H__
#define __SBL_UTILS_H__

#include <stdint.h>
#include "metadata.h"

uint8_t getBootMode(void);
uint8_t setBootMode(uint8_t flag);
uint8_t getActiveBank(void);
int32_t loadMetadata(void);
int32_t isMetadataAvaiable(void);
int32_t read_nor(uint8_t *dest, uintptr_t src, uint32_t len);
uint32_t ReadActiveBootIndex(void);
void board_reboot(void);
#endif
