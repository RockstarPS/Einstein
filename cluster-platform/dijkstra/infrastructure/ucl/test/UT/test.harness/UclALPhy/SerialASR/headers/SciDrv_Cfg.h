//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2016] Visteon Corporation
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
//
//---------------------------------------------------------------------------------------------------------------------

#ifndef SCIDRV_CFG_H
#define SCIDRV_CFG_H

// Macro Definitions

// SCI Channel Bit Endianess
#define cSCIDRV_LSB_FIRST                   (0u)
#define cSCIDRV_MSB_FIRST                   (1u)

// SCI Channel Data Format
#define cSCIDRV_NRZ                         (0u)
#define cSCIDRV_INRZ                        (1u)

// SCI Channel Data Length
#define cSCIDRV_TRANSFER_WIDTH_8BITS        (0u)
#define cSCIDRV_TRANSFER_WIDTH_5BITS        (1u)
#define cSCIDRV_TRANSFER_WIDTH_6BITS        (2u)
#define cSCIDRV_TRANSFER_WIDTH_7BITS        (3u)

// SCI Channel Parity Setting
#define cSCIDRV_PARITY_NONE                 (0u)
#define cSCIDRV_PARITY_ODD                  (1u)
#define cSCIDRV_PARITY_EVEN                 (2u)

// SCI Channel No of stop bits
#define cSCIDRV_STOPBITS_1BIT               (1u)
#define cSCIDRV_STOPBITS_2BIT               (2u)
#define cSCIDRV_STOPBITS_3BIT               (3u)
#define cSCIDRV_STOPBITS_4BIT               (4u)

// SCI Driver Maximum Channels
#define cSCIDRV_MAX_CHANNELS                (3u)

// SCI Driver Bus Clock Frequence in MHZ
#define cSCIDRV_BUS_CLOCK_FREQ_MHZ          (60u)

// SCI Channel Register Offset
#define cSCIDRV_CHN_OFFSET                  (0x400u)

typedef struct SSciDrvChnCfg_t {
    // Transmit Callback
    void (*pSciDrvTransmitNotificationCbk)(void);
    // Receive Callback
    void (*pSciDrvReceiveNotificationCbk)(void);
    // MFS Channel No : 0 -15
    uint8 SciDrvHwChnId;
    // Channel Baudrate
    uint32 SciDrvBaudRate;
    // Data Transfer Direction
    uint8 SciDrvBitEndianess;
    // Data Transfer Format
    uint8 SciDrvDataFormat;
    // Number of bits per frame
    uint8 SciDrvDataLength;
    // Channel Parity Setting
    uint8 SciDrvEnableParity;
    // No of Stops Bits Per Frame
    uint8 SciDrvStopBitsLength;
    // Receive DMA channel Id
    uint8 SciDrvReceiveDmaChnId;
    // Transmit DMA channel Id
    uint8 SciDrvTransmitDmaChnId;
} SSciDrvChnCfg;


typedef struct SSciDrvCfg_t {
    // No of configured SCI channels
    uint8 SciDrvMaxChn;
    // SCI Channel Configurations
    const SSciDrvChnCfg *pSciDrvChnCfg;
} SSciDrvCfg;

// Export the Configuration Structure
extern const SSciDrvCfg*	pSciDrvCfg;

// Client Callbacks
extern void Ipcl_PhyTransmitCallback(void);
extern void Ipcl_PhyReceiveCallback(void);

#endif
