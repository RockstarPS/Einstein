#ifndef Eep24xxDriver_H
#define Eep24xxDriver_H

#include "MemIf_Types.h"

#define MAXIMUM_MEMMAP_SIZE   (80000) //MAXIMUM 10000 NVM blocks (if all blocks are redundant + algorithm header)

typedef struct {
   uint32 address;
   uint16 size;
} Eep24xxDataType;

typedef struct {
   uint32         entries;
   Eep24xxDataType info[MAXIMUM_MEMMAP_SIZE];
} Eep24xxContentType;


extern void Eep24xx_Driver_Init(void);
extern void Eep24xx_Driver_Free(void);
extern uint8 * Eep24xx_Driver_getImage(void);
extern Eep24xxContentType * Eep24xx_Driver_getMemMap(void);

#endif
