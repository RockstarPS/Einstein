#ifndef NVM_BLOCK_LENGTH_CALC_H
#define NVM_BLOCK_LENGTH_CALC_H

extern void BlockLengthCalc_Init(void);
extern void BlockLengthCalc_Add(uint32 Blocklen);
extern void BlockLengthCalc_Close(void);
#endif