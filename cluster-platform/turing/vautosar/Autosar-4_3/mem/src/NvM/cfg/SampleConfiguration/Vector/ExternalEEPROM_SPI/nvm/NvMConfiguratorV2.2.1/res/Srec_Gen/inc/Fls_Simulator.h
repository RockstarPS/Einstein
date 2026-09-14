#ifndef FLS_SIMULATOR_H
#define FLS_SIMULATOR_H

#define MAXIMUM_MEMMAP_SIZE   (80000) //MAXIMUM 10000 NVM blocks (if all blocks are redundant + algorithm header)

typedef struct {
   uint32 address;
   uint16 size;
} memMapInfoType;

typedef struct {
   uint32         entries;
   memMapInfoType info[MAXIMUM_MEMMAP_SIZE];
} memMapDflashType;

extern void Fls_Driver_Init(void);
extern void Fls_Driver_Free(void);
extern uint8 * Fls_Driver_getImage(void);
extern memMapDflashType * Fls_Driver_getMemMap(void);

#endif /* FLS_SIMULATOR_H */


