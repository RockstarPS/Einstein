
#ifndef CHIMES_STUB_H
#define CHIMES_STUB_H

#include "mcasp.h"
#include "I2c.h"
#include "audio_sample.h"
// #include "Rte_Type.h"

extern void Play_Chimes(void);
Std_ReturnType Chimes_I2c_Transmit(uint8 *pTxBuf, uint8 *pRxBuf, uint8 TxLength, uint8 RxLength);
extern void TAS2505_AudioCodec_Init(void);
void mcasp_txcb(MCASP_Handle handle, MCASP_Transaction *transaction);

#endif
