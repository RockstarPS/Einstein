//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2025] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
/*****************************************************************************
*  File Name         :  Chimes_Stub.c                                        *
*  Module Short Name :  stubs                                                *
*  Description       :  This file contains implementations of the Chimes POC *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  CLANG                                                  *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef CHIMES_STUB_C
#define CHIMES_STUB_C

#include "Chimes_Stub.h"
#include "I2c.h"
#include "audio_sample.h"


volatile uint8 dac_ack_ok = 0;
volatile uint8 Chimes_Tx_Complete = 0;
uint8 brk = 1;

Std_ReturnType Chimes_I2c_Transmit(uint8 *pTxBuf, uint8 *pRxBuf, uint8 TxLength, uint8 RxLength)
{
	Std_ReturnType RetVal = E_NOT_OK;

	dac_ack_ok = 0;

	RetVal = I2c_SetupEB(I2C_DAC, pTxBuf, pRxBuf, TxLength, RxLength, 0x18);

	if(E_OK == RetVal)
    {
        RetVal = I2c_SyncTransmit(I2C_DAC);
	}
	
	return RetVal;
}

uint8 TxBuffer[2];
uint8 RxBuffer[2];

#define TAS2505_WRITE_REG(reg, val) \
        TxBuffer[0] = (reg); \
        TxBuffer[1] = (val); \
        Chimes_I2c_Transmit(TxBuffer, NULL, 2, 0);

#define TAS2505_READ_REG(reg) \
        TxBuffer[0] = (reg); \
        RxBuffer[0] = 0xFF; \
        Chimes_I2c_Transmit(TxBuffer, RxBuffer, 1, 1);


static inline void TAS2505_DelayUs(uint32 count)
{
    /* count in microseconds; tuned for MCU speed (R5F @ 400 MHz ≈ 100 cycles/us) */
    volatile uint32 i;
    for(i = 0; i < (count * 100U); i++)
    {
        __asm__ volatile (" nop ");
    }
}

void TAS2505_AudioCodec_Init(void)
{
   /* --- Reset & rails --- */
    TAS2505_WRITE_REG(0x00, 0x00);   /* Page 0 */
    TAS2505_WRITE_REG(0x01, 0x01);   /* Soft reset */
    TAS2505_WRITE_REG(0x00, 0x01);   /* Page 1 */
    TAS2505_WRITE_REG(0x02, 0x00);   /* LDO 1.8V, level shifters ON */

    /* --- Back to Page 0: processing + clocks --- */
    TAS2505_WRITE_REG(0x00, 0x00);   /* Page 0 */
    TAS2505_WRITE_REG(0x3C, 0x01);   /* PRB1 */

    /* CLOCKING: BYPASS PLL, use MCASP BCLK directly */
    TAS2505_WRITE_REG(0x04, 0x07);   /* CODEC_CLKIN = BCLK */
    TAS2505_WRITE_REG(0x05, 0x91);   /* PLL OFF */
    TAS2505_WRITE_REG(0x06, 0x1C);
    TAS2505_WRITE_REG(0x07, 0x00);
    TAS2505_WRITE_REG(0x08, 0x00);

    /* SERIAL AUDIO IF: I2S slave, 16-bit word, std polarity */
    TAS2505_WRITE_REG(0x1B, 0x30);
    TAS2505_WRITE_REG(0x1C, 0x00);
    TAS2505_WRITE_REG(0x0B, 0x87);   /* I2S mode, slave */
    TAS2505_WRITE_REG(0x0C, 0x82);   /* 16-bit word */
    TAS2505_WRITE_REG(0x0D, 0x00);
    TAS2505_WRITE_REG(0x0E, 0x80);   /* I2S LR polarity */
    
    TAS2505_WRITE_REG(0x20, 0x00);

    /* ROUTING / MIXING: Left DAC from Left data; unmute path */
    TAS2505_WRITE_REG(0x3F, 0xB0);   /* (your path base) */
    TAS2505_WRITE_REG(0x40, 0x00);   /* no attenuation on left mix */
    TAS2505_WRITE_REG(0x41, 0x00);   /* volume (unmuted) */

    /* --- Power up DAC block & set gains --- */
    TAS2505_WRITE_REG(0x00, 0x01);   /* Page 1 */
    TAS2505_WRITE_REG(0x01, 0x10);   /* Power up DAC */
    TAS2505_WRITE_REG(0x03, 0x20);   /* High Performance Mode */
    TAS2505_WRITE_REG(0x2D, 0x02);
    TAS2505_WRITE_REG(0x2E, 0x3C);   //-30.1db previously 0 db
    TAS2505_WRITE_REG(0x30, 0x40);


    /* --- Optional readbacks --- */
    TAS2505_WRITE_REG(0x00, 0x00);   /* Page 0 */
    TAS2505_READ_REG(0x04);          /* expect 0x01 (BCLK as CODEC_CLKIN) */
    TAS2505_READ_REG(0x0B);          /* confirm I2S+slave */
    TAS2505_READ_REG(0x0C);          /* confirm 16-bit word */
	TAS2505_WRITE_REG(0x00, 0x01);   /* Page 1 */
	TAS2505_READ_REG(0x01);
    TAS2505_READ_REG(0x2D);
}


MCASP_Transaction txTxn;

void Play_Chimes(void)
{
	int32_t status = SystemP_SUCCESS;

    MCASP_Handle mcaspHandle;

    TAS2505_AudioCodec_Init();

    mcaspHandle = MCASP_getHandle(0);

    txTxn.buf = (void *)audio_sample;
    txTxn.count = audio_sample_size;
    txTxn.timeout = 0xFFFFFF;
    MCASP_submitTx(mcaspHandle, &txTxn);

    status = MCASP_startTransferTx(mcaspHandle);
    DebugP_assert(status == SystemP_SUCCESS);

	// while(Chimes_Tx_Complete == 0)
	// {
		
	// }

    // MCASP_stopTransferTx(mcaspHandle);
}


void mcasp_txcb(MCASP_Handle handle,
                          MCASP_Transaction *transaction)
{
    // Chimes_Tx_Complete = 1;
    (void)MCASP_stopTransferTx(handle);
}

#endif
