#ifndef EepDriver_H
#define EepDriver_H

#include "MemIf_Types.h"

#define MAXIMUM_MEMMAP_SIZE   (80000) //MAXIMUM 10000 NVM blocks (if all blocks are redundant + algorithm header)

typedef struct {
   uint32 address;
   uint16 size;
} EepDataType;

typedef struct {
   uint32         entries;
   EepDataType info[MAXIMUM_MEMMAP_SIZE];
} EepContentType;


extern void Eep_Driver_Init(void);
extern void Eep_Driver_Free(void);
extern uint8 * Eep_Driver_getImage(void);
extern EepContentType * Eep_Driver_getMemMap(void);

#endif
