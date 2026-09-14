/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  SciDrv.c                                                *
*  Module Short Name :  SciDrv                                               *
*  Description       :  This file contains implementations of the SCI Driver *
*                       for AM62PX series microcontrollers.               *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Clang Compiler                                          *
* Target Hardware  :  AM62PX micro based Hardware Platform                *
*                                                                            *
******************************************************************************/



/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "Std_Types.h"
#include "SciDrv_Types.h"
#include "Os.h" /* For Enable/Disable Interrupts */
#include "SciDrv.h"
#include <string.h>
#if(DMA_PROVEOUT_ENABLED == STD_ON)
#include "SciDrv_Udma.h"
#include "SciDrv_Udma_Cfg.h"
#include <drivers/hw_include/hw_types.h>
#include <drivers/hw_include/csl_types.h>
#include <kernel/dpl/HwiP.h>
#endif


/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*Ring Buffer Configuration*/
#define SCI_RING_BUFFER_SIZE		    (1024)

/*Fifo Buffer Size*/
#define SCIDRV_FIFO_MAX_VAL             (64U)

/* FIFO Triggers Setting*/
#define SCIDRV_FIFO_CONFIG(txGra, rxGra, pTxTrig, pRxTrig, txClr, rxClr, dmaEnPath, \
                         dmaMode)                                               \
    (((uint32) ((txGra) & 0xFU) << (uint32)26U)    |                       \
     ((uint32) ((rxGra) & 0xFU) << (uint32)22U)    |                       \
     ((uint32) ((pTxTrig) & 0xFFU) << (uint32)14U)  |                       \
     ((uint32) ((pRxTrig) & 0xFFU) << (uint32)6U)   |                       \
     ((uint32) ((txClr) & 0x1U) << (uint32)5U)     |                       \
     ((uint32) ((rxClr) & 0x1U) << (uint32)4U)     |                       \
     ((uint32) ((dmaEnPath) & 0x1U) << (uint32)3U) |                       \
     (uint32) ((dmaMode) & 0x7U))

#define SCIDRV_FIFO_CONFIG_TXGRA          ((uint32) 0xFU << 26)
#define SCIDRV_FIFO_CONFIG_RXGRA          ((uint32) 0xFU << 22)
#define SCIDRV_FIFO_CONFIG_pTxTrig         ((uint32) 0xFFU << 14)
#define SCIDRV_FIFO_CONFIG_pRxTrig         ((uint32) 0xFFU << 6)
#define SCIDRV_FIFO_CONFIG_TXCLR          ((uint32) 0x1U << 5)
#define SCIDRV_FIFO_CONFIG_RXCLR          ((uint32) 0x1U << 4)
#define SCIDRV_FIFO_CONFIG_DMAENPATH      ((uint32) 0x1U << 3)
#define SCIDRV_FIFO_CONFIG_DMAMODE        ((uint32) 0x7U << 0)


/*Brake Control Bit -if set, forces the transmitter output to go low to alert the communication terminal
  Brate State */
#define SCIDRV_BREAK_COND_DISABLE         (UART_LCR_BREAK_EN_BREAK_EN_VALUE_0 \
                                            << UART_LCR_BREAK_EN_SHIFT)
#define SCIDRV_BREAK_COND_ENABLE          (UART_LCR_BREAK_EN_BREAK_EN_VALUE_1 \
                                            << UART_LCR_BREAK_EN_SHIFT)
/*Register Mode Configuration*/											
#define SCIDRV_REG_CONFIG_MODE_A          ((uint32) 0x0080)
#define SCIDRV_REG_CONFIG_MODE_B          ((uint32) 0x00BF)
#define SCIDRV_REG_OPERATIONAL_MODE       ((uint32) 0x007F)

/*SciDrv Interrupt Sources*/
#define SCIDRV_INTID_TX_THRES_REACH           (UART_IIR_UART_IT_TYPE_IT_TYPE_VALUE_1 \
                                             <<                               \
                                             UART_IIR_UART_IT_TYPE_SHIFT)
#define SCIDRV_INTID_RX_THRES_REACH           (UART_IIR_UART_IT_TYPE_IT_TYPE_VALUE_2 \
                                             <<                               \
                                             UART_IIR_UART_IT_TYPE_SHIFT)
#define SCIDRV_INTID_RX_LINE_STAT_ERROR       (UART_IIR_UART_IT_TYPE_IT_TYPE_VALUE_3 \
                                             <<                               \
                                             UART_IIR_UART_IT_TYPE_SHIFT)
#define SCIDRV_INTID_CHAR_TIMEOUT             (UART_IIR_UART_IT_TYPE_IT_TYPE_VALUE_6 \
                                             <<                               \
                                             UART_IIR_UART_IT_TYPE_SHIFT)

/*SciDrv Line Status Information*/

#define SCIDRV_FIFO_PE_FE_BI_DETECTED        (UART_LSR_UART_RX_FIFO_STS_MASK)
#define SCIDRV_BREAK_DETECTED_ERROR          (UART_LSR_UART_RX_BI_MASK)
#define SCIDRV_FRAMING_ERROR                 (UART_LSR_UART_RX_FE_MASK)
#define SCIDRV_PARITY_ERROR                  (UART_LSR_UART_RX_PE_MASK)
#define SCIDRV_OVERRUN_ERROR                 (UART_LSR_UART_RX_OE_MASK)

/*Values for enabling/disabling the interrupts of Scidrv*/
#define SCIDRV_INTR_LINE_STAT                 (UART_IER_UART_LINE_STS_IT_MASK)
#define SCIDRV_INTR_THR                       (UART_IER_UART_THR_IT_MASK)
#define SCIDRV_INTR_RHR_CTI                   (UART_IER_UART_RHR_IT_MASK)

#define SCIDRV_INTR2_RX_EMPTY                 (UART_IER2_EN_RXFIFO_EMPTY_MASK)
#define SCIDRV_INTR2_TX_EMPTY                 (UART_IER2_EN_TXFIFO_EMPTY_MASK)

/*Granuality Setting*/
#define SCIDRV_TRIG_LVL_GRANULARITY_4     ((uint32) 0x0000U)
#define SCIDRV_TRIG_LVL_GRANULARITY_1     ((uint32) 0x0001U)

//Disabling or Enabling sets DMA mode with FCR[3] or SCR[2:1] registers
#define SCIDRV_DMA_EN_PATH_FCR            (UART_SCR_DMA_MODE_CTL_DMA_MODE_CTL_VALUE_0)
#define SCIDRV_DMA_EN_PATH_SCR            (UART_SCR_DMA_MODE_CTL_DMA_MODE_CTL_VALUE_1)

//DMA modes if SCR[0] = 1
#define SCIDRV_DMA_MODE_0_ENABLE          (UART_SCR_DMA_MODE_2_DMA_MODE_2_VALUE_0)
#define SCIDRV_DMA_MODE_1_ENABLE          (UART_SCR_DMA_MODE_2_DMA_MODE_2_VALUE_1)
#define SCIDRV_DMA_MODE_2_ENABLE          (UART_SCR_DMA_MODE_2_DMA_MODE_2_VALUE_2)
#define SCIDRV_DMA_MODE_3_ENABLE          (UART_SCR_DMA_MODE_2_DMA_MODE_2_VALUE_3)

											
#define SCIDRV_ENTER_CRITICAL_SECTION()           SuspendAllInterrupts()
#define SCIDRV_EXIT_CRITICAL_SECTION()            ResumeAllInterrupts()

#if(DMA_PROVEOUT_ENABLED == STD_ON)
/* ---- UART DMA arming (TX) ---- */
#ifndef UART_IER_ERBI
#define UART_IER_ERBI           (1u << 0)   /* RX data available */
#define UART_IER_ETBEI          (1u << 1)   /* TX holding register empty */
#endif
#ifndef UART_LCR_ENH_MODE
#define UART_LCR_ENH_MODE       (0xBFu)     /* write this to LCR to access EFR */
#endif
#ifndef UART_EFR_ENHANCED_EN
#define UART_EFR_ENHANCED_EN    (1u << 4)   /* EFR[4] */
#endif
#ifndef UART_IER2_TX_DMA_EN
#define UART_IER2_TX_DMA_EN     (1u << 1)
#define UART_IER2_RX_DMA_EN     (1u << 0)
#endif

/* ---- UART DMA arming (TX) ---- */
#ifndef UART_IER_ERBI
#define UART_IER_ERBI           (1u << 0)   /* RX data available */
#define UART_IER_ETBEI          (1u << 1)   /* TX holding register empty */
#endif
#ifndef UART_LCR_ENH_MODE
#define UART_LCR_ENH_MODE       (0xBFu)     /* write this to LCR to access EFR */
#endif
#ifndef UART_EFR_ENHANCED_EN
#define UART_EFR_ENHANCED_EN    (1u << 4)   /* EFR[4] */
#endif
#ifndef UART_IER2_TX_DMA_EN
#define UART_IER2_TX_DMA_EN     (1u << 1)
#define UART_IER2_RX_DMA_EN     (1u << 0)
#endif

#endif
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
/* Ring Buffer Type */
typedef struct
{
    uint8 data[SCI_RING_BUFFER_SIZE]; /* Buffer to hold the data */
    uint16 read_index; /* Last read position */
    uint16 write_index; /* Last wrote position */
    uint16 fill_count; /* Number of bytes in the buffer */
} SSciDrvRingBuffer;


/* Defines channel data */
typedef struct
{
    uint32 SciTransmitSizeRemaining; /* TX data remaining in buffer */
    uint32 SciTransmitCount; /* No Of chars transmitted */
    uint32 SciReceiveLength; /* Rx Data Length requested by App  - readSizeRemaining*/
    uint32 SciBytesReceived; /* No Of Bytes Actually Received - readCount */
    uint32 SciExtraBytesReceived; /*No of Bytes more than expected SciReceiveLength passed by the application*/
    uint32 SciTxDataSent; /* Flag indicate all the data written to the TX FIFO*/
    uint16 SciReceiveTimeout; /*Timeout for ASync Receive*/
    uint8 *pSciTransmitBuffer; /* Tx Buffer Pointer */
    uint8 *pSciReceiveBuffer; /* Rx Buffer Pointer */
    ESciDrvChnResult SciTransmitStatus; /* ESciDrvChnResult */
    ESciDrvChnResult SciReceiveStatus; /* ESciDrvChnResult*/
    ESciDrvAsyncMode SciAsyncMode;
    ESciDrvSyncMode SciSyncMode;
    SSciDrvRingBuffer SciTxIB;
    SSciDrvRingBuffer SciRxIB;
} SSciDrvChnInfo;

/* Defines Hold Channel Mode*/
ESciDrvAsyncMode SciAsyncModeHold[SCIDRV_MAX_CHANNELS] = {eSciDrvAsyncMode_Last};
ESciDrvSyncMode SciSyncModeHold[SCIDRV_MAX_CHANNELS] = {eSciDrvSyncMode_Last}; 

/* Defines global driver data*/
typedef struct
{
    ESciDrvStatus State;
    const SSciDrvCfg *pSciDrvConfig;
} SSciDrvGlobal;

/*****************************************************************************
*                                Private Variables                         *
******************************************************************************/
static SSciDrvGlobal SciDrvGlobal =
                {
                                eSciDrvStatus_Uninit,
                                NULL
                };

static SSciDrvChnInfo SciDrvChnInfo[SCIDRV_MAX_CHANNELS];


/*****************************************************************************
*                            Private Functions                                  *
******************************************************************************/

static void SciDrv_InitChnInfo( TSciDrvChn SciDrvSwChn );
static Std_ReturnType SciDrv_HwChannelInit( const SSciDrvChnCfg *pChnCfg );
static Std_ReturnType SciDrv_HwChannelDeinit( const SSciDrvChnCfg *pChnCfg );
static Std_ReturnType SciDrv_HwFifoInit(const SSciDrvChnCfg *pChnCfg, TSciDrvChn SciDrvSwChn);
static Std_ReturnType SciDrv_HwFifoDeinit( const SSciDrvChnCfg *pChnCfg );
static Std_ReturnType SciDrv_HwPollingWriteFifo( TSciDrvChn SciDrvSwChn, const uint8 *pData, uint16 *pLength );
static Std_ReturnType SciDrv_HwPollingReadFifo( TSciDrvChn SciDrvSwChn, uint8 *pData, uint16 *pLength );
static Std_ReturnType SciDrv_HwEnableTransmitInterrupt( const SSciDrvChnCfg *pChnCfg );
static Std_ReturnType SciDrv_HwDisableTransmitInterrupt( const SSciDrvChnCfg *pChnCfg );
static Std_ReturnType SciDrv_HwEnableReceiveInterrupt( const SSciDrvChnCfg *pChnCfg );
static Std_ReturnType SciDrv_HwDisableReceiveInterrupt( const SSciDrvChnCfg *pChnCfg );
static uint32 SciDrv_HwInterruptWriteFifo( TSciDrvChn SciDrvSwChn, const uint8 *pData, uint32 pLength );
static Std_ReturnType SciDrv_HwInterruptReadFifo( TSciDrvChn SciDrvSwChn, uint8 *pData, uint16 *pLength );
static Std_ReturnType SciDrv_HwSyncTransmit( TSciDrvChn SciDrvSwChn, const uint8 *pBuffer, uint32 Length );
static Std_ReturnType SciDrv_HwSyncReceive(TSciDrvChn SciDrvSwChn, const uint8 *pBuffer, uint32 *pLength);
static Std_ReturnType SciDrv_HwCancelReceive( const SSciDrvChnCfg *pChnCfg );
static Std_ReturnType SciDrv_HwCancelTransmit( const SSciDrvChnCfg *pChnCfg );
static uint8 SciDrv_HwGetSwChnID( TSciDrvChn SciDrvHwChn );
static void SciDrv_ReceiveErrorRecovery( const SSciDrvChnCfg *pChnCfg );

#if(DMA_PROVEOUT_ENABLED == STD_ON)
static void SciDrv_RingBufferInit( SSciDrvRingBuffer *buffer );
static uint16 SciDrv_RingBufferWrite( SSciDrvRingBuffer *buffer, const uint8 *data, uint16 size );
static uint16 SciDrv_RingBufferRead( SSciDrvRingBuffer *buffer, uint8 *data, uint16 size );
static void UART_masterIsr(const void *arg);
static void SciDrv_UartDmaArmTx(uint8 swChannel);
#endif 

/*****************************************************************************
*                           Low driver Functions                                   *
******************************************************************************/

static void SciDrv_ResetModule(uint32 pRegBase);
static uint32 SciDrv_HwEnableEnhaceFunc (uint32 pRegBase);
static void SciDrv_HwModuleReset (uint32 pRegBase);
static Std_ReturnType SciDrv_HwInterruptEnable(uint32 pRegBase, uint32 pInterruptFlag);
static Std_ReturnType SciDrv_HwInterruptDisable(uint32 pRegBase, uint32 pInterruptFlag);
static void SciDrv_HwInterrupt2Enable(uint32 pRegBase, uint32 pInterruptFlag);
static void SciDrv_HwInterrupt2Disable(uint32 pRegBase, uint32 pInterruptFlag);
static void SciDrv_HwLineCharConfig (uint32 pRegBase, uint32 pLengthFlag, uint32 pParityFlag);
static uint32 SciDrv_HwOperatingModeSelect(uint32 pRegBase, uint32 pModeFlag);
static void SciDrv_HwBreakControl(uint32 pRegBase, uint32 pbreakState);
static uint32 SciDrv_HwEnableRegisterConfigMode(uint32 pRegBase, uint32 pRegisterModeFlag);
static uint32 SciDrv_ComputeDivisorValue(uint32 pModuleClk, uint32 pBaudRate, uint32 pModeFlag);
static uint32 SciDrv_DivideRoundCloset(uint32 pdivident, uint32 pdivisor);
static uint32 SciDrv_HwWriteDivisorLatch(uint32 pRegBase, uint32 pdivisorValue);
static void SciDrv_DisableDivisorLatch (uint32 pRegBase);
static uint32 SciDrv_HwFifoConfig(uint32 pRegBase, uint32 pFifoConfig);
static uint32 SciDrv_HwSubConfigTCRTLRModeEn(uint32 pRegBase);
static void SciDrv_HwFifoRegisterWrite(uint32 pRegBase, uint32 pFcrValue);
static void SciDrv_HwEnhanFuncBitValRestore(uint32 pRegBase, uint32 pEnhanFnBitVal);
static void SciDrv_HwTcrTlrBitValRestore(uint32 pRegBase, uint32 pTcrTlrBitVal);
static uint32 SciDrv_HwGetIntrIdentityStatus(uint32 pRegBase);
static void SciDrv_HwPutChar(uint32 pRegBase, uint8 pByteTx);
static uint32 SciDrv_HwReadLineStatus(uint32 pRegBase);
static void SciDrv_Write_Field32(uint32 pRegBase, uint32 pRegFieldMask, uint32 pRegFieldShift, uint32 pFieldValue);
static uint32 SciDrv_Read_Field32(uint32 pRegBase, uint32 pRegFieldMask, uint32 pRegFieldShift);
static void SciDrv_Write_Reg32(uint32 pRegBase, uint32 pValue);
static uint32 SciDrv_Read_Reg32(uint32 pRegBase);

#if(DMA_PROVEOUT_ENABLED == STD_ON)

static void UART_masterIsr(const void *arg)
{
    (void)arg;
    SciDrv_TxRxISRHandle(0);
}


/* ---- UART DMA arming (TX) ---- */
static void SciDrv_UartDmaArmTx(uint8 swChannel)
{
    const uint32 uartBase = pSciDrvCfg->pSciDrvChnCfg[swChannel].SciDrvBaseAddr;

    /* Do a quick FIFO clear + enable (safe if already done) */
    SciDrv_Write_Reg32(uartBase + UART_FCR, 0x00000006U); /* clear TX & RX FIFOs */
    SciDrv_Write_Reg32(uartBase + UART_FCR, 0x000000C2U); /* FIFOE=1, RX trig=1 */

    /* Enable UART DMA via IER2: [0]=RX_DMA_EN, [1]=TX_DMA_EN */
    {
        uint32 ier2 = SciDrv_Read_Reg32(uartBase + UART_IER2);
        ier2 |= 0x00000003U;
        SciDrv_Write_Reg32(uartBase + UART_IER2, ier2);
    }

    /* CRITICAL: Keep ETBEI (THR empty int) enabled � it gates TX DMA requests on AM62Px.
       Your header calls the IER register 'UART_IER_UART' (not UART_IER). */
    {
        uint32 ier = SciDrv_Read_Reg32(uartBase + UART_IER_UART);  /* correct offset macro name */
        ier |= UART_IER_UART_THR_IT_MASK;                          /* bit1 = 1 */
        SciDrv_Write_Reg32(uartBase + UART_IER_UART, ier);
    }

    /* If you later want to tune TX threshold by TLR, ensure TCR_TLR access is enabled first.
       We keep it simple and rely on TX_DMA_THRESHOLD (already set to 1). */
}
#endif


/*****************************************************************************
*                      Public Function Implementation                         *
******************************************************************************/

#if(DMA_PROVEOUT_ENABLED == STD_ON)
void SciDrv_DmaTxComplete(uint8 swChn)
{
    /* mark TX complete in your channel state */
    SciDrvChnInfo[swChn].SciTransmitCount = SciDrvChnInfo[swChn].SciTransmitSizeRemaining;
    SciDrvChnInfo[swChn].SciTransmitSizeRemaining = 0U;
    SciDrvChnInfo[swChn].SciTransmitStatus = eSciDrvChnResult_Ok;

    /* user callback if configured */
    if (SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[swChn].pSciDrvTransmitNotificationCbk != NULL_PTR)
    {
        SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[swChn].pSciDrvTransmitNotificationCbk(eSciDrvChnResult_Ok);
    }

}

void SciDrv_DmaRxComplete(uint8 swChn, uint32 bytes)
{
    SciDrvChnInfo[swChn].SciBytesReceived = bytes;
    SciDrvChnInfo[swChn].SciReceiveStatus = eSciDrvChnResult_Ok;

    if (SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[swChn].pSciDrvReceiveNotificationCbk != NULL_PTR) {
        uint32 exprxlength   = SciDrvChnInfo[swChn].SciReceiveLength;
        uint32 extra = (bytes > exprxlength) ? (bytes - exprxlength) : 0U;
        SciDrvChnInfo[swChn].SciExtraBytesReceived = extra;

        SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[swChn].pSciDrvReceiveNotificationCbk(
            SciDrvChnInfo[swChn].SciReceiveStatus,
            SciDrvChnInfo[swChn].SciBytesReceived,
            SciDrvChnInfo[swChn].SciExtraBytesReceived);
    }
}
#endif

/*============================================================================
**
** Function Name    :   SciDrv_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global
**                      and Static variables of this module.
**
** Invocation       :
**
** Inputs           :   SSciDrvCfg *pConfig - Pointer to a configuration type.
**
** Outputs          :   E_OK: If success.
**                      E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType SciDrv_Init( const SSciDrvCfg *pConfig )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    TSciDrvChn flSciDrvSwChn;

    // Validate arguments
    if (NULL != pConfig)
    {
        // Store configuration pointer
        SciDrvGlobal.pSciDrvConfig = pConfig;

        // Initialize Channel Info
        for (flSciDrvSwChn = 0; flSciDrvSwChn < SCIDRV_MAX_CHANNELS; flSciDrvSwChn++)
        {
            SciDrv_InitChnInfo( flSciDrvSwChn );
        }

        // Make SCI Driver Ready
        SciDrvGlobal.State = eSciDrvStatus_Ready;
		
        flRetVal = E_OK;
    }

    return flRetVal;

}

/*============================================================================
**
** Function Name    :   SciDrv_DeInit
**
** Visibility       :   Public
**
** Description      :   The DeInit function is called to initialise the Global
**                      and Static variables of this module to initial/ default values.
**
** Invocation       :
**
** Inputs           :   
**
** Outputs          :  
**
** Critical Section :
**
**==========================================================================*/
void SciDrv_DeInit( void )
{
    SciDrvGlobal.pSciDrvConfig = NULL;
    SciDrvGlobal.State = eSciDrvStatus_Uninit;
}

/*============================================================================
**
** Function Name    :   SciDrv_SetupEB
**
** Visibility       :   Public
**
** Description      :   This function setsups the SciDrv External Buffer.
**                      This will not trigger the transmission.
**
** Invocation       :   Application
**
** Inputs           :   TSciDrvChn SciDrvHwChn: SciDrv Hw channel number.
**                      ESciDrvDirection Direction: Direction of the channel.
**                      uint8* pBuffer: Buffer.
**                      uint32 Length: Transmisson Length or Receive Length (Depends on Direction)
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType SciDrv_SetupEB( TSciDrvChn SciDrvHwChn, ESciDrvDirection Direction, uint8 *pBuffer, uint32 Length )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    uint8 flSciDrvSwChn;

    flSciDrvSwChn = SciDrv_HwGetSwChnID(SciDrvHwChn);
    // Validate Arguments and State
    if ((flSciDrvSwChn < SCIDRV_MAX_CHANNELS) && (eSciDrvStatus_Ready == SciDrvGlobal.State) &&
                    (NULL != pBuffer) && (0U < Length) && (eSciDrvDirection_Last > Direction))
    {

        //Check if channel is busy
        SciDrvChnInfo[flSciDrvSwChn].SciReceiveLength = 0;
        SciDrvChnInfo[flSciDrvSwChn].pSciReceiveBuffer = NULL;
        SciDrvChnInfo[flSciDrvSwChn].SciTransmitCount = 0;
        SciDrvChnInfo[flSciDrvSwChn].pSciTransmitBuffer = NULL;
        if ((eSciDrvDirection_Receive == Direction) &&
                        (eSciDrvChnResult_Busy != SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus))
        {
            SciDrvChnInfo[flSciDrvSwChn].SciReceiveLength = Length;
            SciDrvChnInfo[flSciDrvSwChn].pSciReceiveBuffer = pBuffer;
        }
        else if ((eSciDrvDirection_Transmit == Direction) &&
                        (eSciDrvChnResult_Busy != SciDrvChnInfo[flSciDrvSwChn].SciTransmitStatus))
        {
            SciDrvChnInfo[flSciDrvSwChn].SciTransmitSizeRemaining = Length;
            SciDrvChnInfo[flSciDrvSwChn].pSciTransmitBuffer = pBuffer;
            flRetVal = E_OK;
        }
        else
        {
            flRetVal = E_NOT_OK;
        }
    }
    return flRetVal;
}

/*DMA mode is not supported as for now and WriteIB and ReadIB are supported only in DMA mode*/
#if(DMA_PROVEOUT_ENABLED == STD_ON)
/*============================================================================
**
** Function Name    :   SciDrv_WriteIB
**
** Visibility       :   Public
**
** Description      :   This function writes to the SciDrv Internal Buffer.
**                      This will not trigger the transmission.
**
** Invocation       :   Application
**
** Inputs           :   TSciDrvChn SciDrvHwChn: SciDrv Hw channel number.
**                      ESciDrvDirection Direction: Direction of the channel.
**                      uint8* pBuffer: Buffer.
**                      uint32 Length: Transmisson Length or Receive Length (Depends on Direction)
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType SciDrv_WriteIB( TSciDrvChn SciDrvHwChn, ESciDrvDirection Direction, uint8* pBuffer, uint32 Length )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    uint8 flSciDrvSwChn;

    flSciDrvSwChn = SciDrv_HwGetSwChnID(SciDrvHwChn);
    // Validate Arguments and State
    if ((flSciDrvSwChn < SCIDRV_MAX_CHANNELS) && (eSciDrvStatus_Ready == SciDrvGlobal.State) &&
                    (NULL != pBuffer) && (0 < Length) && (eSciDrvDirection_Last > Direction))
    {
      if (eSciDrvDirection_Transmit == Direction)
      {
          if ((uint16) Length== SciDrv_RingBufferWrite( &SciDrvChnInfo[flSciDrvSwChn].SciTxIB, pBuffer, (uint16) Length ))
          {
              flRetVal = E_OK;
          }
          else
          {
              flRetVal = E_NOT_OK;
          }
      }
    }
    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_ReadIB
**
** Visibility       :   Public
**
** Description      :   This function reads the SciDrv Internal Buffer.
**                      This will not trigger the transmission.
**
** Invocation       :   Application
**
** Inputs           :   TSciDrvChn SciDrvHwChn: SciDrv Hw channel number.
**                      ESciDrvDirection Direction: Direction of the channel.
**                      uint8* pBuffer: Buffer.
**                      uint32 Length: Transmisson Length or Receive Length (Depends on Direction)
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType SciDrv_ReadIB( TSciDrvChn SciDrvHwChn, ESciDrvDirection Direction, uint8* pBuffer, uint16 Length )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    uint8 flSciDrvSwChn;

    flSciDrvSwChn = SciDrv_HwGetSwChnID(SciDrvHwChn);
    // Validate Arguments and State
    if ((SCIDRV_MAX_CHANNELS > flSciDrvSwChn) && (eSciDrvStatus_Ready == SciDrvGlobal.State) &&
                    (NULL != pBuffer) && (0 < Length) && (eSciDrvDirection_Last > Direction))
    {
        flRetVal = E_OK;
    }

    if ((E_OK == flRetVal) && (eSciDrvDirection_Receive == Direction))
    {
        if (Length == SciDrv_RingBufferRead( &SciDrvChnInfo[flSciDrvSwChn].SciRxIB, pBuffer, Length ))
        {
            SCIDRV_ENTER_CRITICAL_SECTION();
            SciDrvChnInfo[flSciDrvSwChn].SciBytesReceived -= Length;
            SCIDRV_EXIT_CRITICAL_SECTION();
            flRetVal = E_OK;
        }
        else
        {
            flRetVal = E_NOT_OK;
        }
    }
    else
    {
        flRetVal = E_NOT_OK;
    }

    return flRetVal;
}
#endif

/*============================================================================
**
** Function Name    :   SciDrv_EnableChn
**
** Visibility       :   Public
**
** Description      :   This function Enables the Channel with SciDrv Configurations
**                      This will not trigger the transmission.
**
** Invocation       :   Application
**
** Inputs           :   TSciDrvChn SciDrvHwChn: Hw Channel that needs to be enabled
**
** Outputs          :  E_OK: If success.
**                     E_NOT_OK: If not success.
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType SciDrv_EnableChn( TSciDrvChn SciDrvHwChn )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    const SSciDrvChnCfg *pChnCfg = NULL;
    uint8 flSciDrvSwChn;

    flSciDrvSwChn = SciDrv_HwGetSwChnID(SciDrvHwChn);
    if(flSciDrvSwChn < SCIDRV_MAX_CHANNELS)
    {
      SciDrv_InitChnInfo( flSciDrvSwChn );
      SciDrvChnInfo[flSciDrvSwChn].SciAsyncMode = SciAsyncModeHold[flSciDrvSwChn];
      SciDrvChnInfo[flSciDrvSwChn].SciSyncMode = SciSyncModeHold[flSciDrvSwChn];
      // Validate Arguments and State
      if (SciDrvGlobal.State == eSciDrvStatus_Ready)
      {
          
          // Initialize and Enable Hardware Channel
          pChnCfg = &(SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[flSciDrvSwChn]);
          flRetVal = SciDrv_HwChannelInit( pChnCfg );
      }
      //Initialize Fifo Settings
      if (E_OK ==flRetVal)
      {
        (void)SciDrv_HwFifoInit (pChnCfg, flSciDrvSwChn);
      }
    }
	return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_AsyncTransmit
**
** Visibility       :   Public
**
** Description      :   This function triggers the asynchronous transmission.
**                      This will take the external buffers under this sequence already setup-ed.
**
** Invocation       :   Application.
**
** Inputs           :  TSciDrvChn SciDrvHwChn: The Hw channel number to be triggered.
**
** Outputs          :  E_OK: If tx/ accepted.
**                     E_NOT_OK: If tx not accepted.
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType SciDrv_ASyncTransmit(TSciDrvChn SciDrvHwChn)
{
    Std_ReturnType flRetVal = E_NOT_OK;
    const SSciDrvChnCfg *pChnCfg;
    uint8 flSciDrvSwChn;

    flSciDrvSwChn = SciDrv_HwGetSwChnID(SciDrvHwChn);

    /* Primary Boundary Check: All array accesses syntactically dominated */
    if ((SCIDRV_MAX_CHANNELS > flSciDrvSwChn) && 
        (eSciDrvStatus_Ready == SciDrvGlobal.State))
    {
        /* Check if Channel is busy Transmitting */
        if (eSciDrvChnResult_Busy != SciDrvChnInfo[flSciDrvSwChn].SciTransmitStatus)
        {
            /* Check the Async Mode Configured */
            if ((eSciDrvAsyncMode_Interrupt == SciDrvChnInfo[flSciDrvSwChn].SciAsyncMode) ||
                (eSciDrvAsyncMode_Dma == SciDrvChnInfo[flSciDrvSwChn].SciAsyncMode))
            {
                pChnCfg = &(SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[flSciDrvSwChn]);
                
                /* Make the channel busy */
                SciDrvChnInfo[flSciDrvSwChn].SciTransmitStatus = eSciDrvChnResult_Busy;
                SciDrvChnInfo[flSciDrvSwChn].SciTransmitCount = 0;

                if (eSciDrvAsyncMode_Interrupt == SciDrvChnInfo[flSciDrvSwChn].SciAsyncMode)
                {
                    SciDrvChnInfo[flSciDrvSwChn].SciTxDataSent = FALSE;
                    /* Interrupt Mode */
                    flRetVal = SciDrv_HwEnableTransmitInterrupt(pChnCfg);
                }
                else
                {
                    #if (DMA_PROVEOUT_ENABLED == STD_ON)
                    flRetVal = SciDrv_UdmaSubmitTx(flSciDrvSwChn,
                                                   SciDrvChnInfo[flSciDrvSwChn].pSciTransmitBuffer,
                                                   SciDrvChnInfo[flSciDrvSwChn].SciTransmitSizeRemaining);
                    #else
                    flRetVal = E_NOT_OK;
                    #endif
                }
            }
            else
            {
                /* Invalid Async Mode */
                flRetVal = E_NOT_OK;
            }
        }
        else
        {
            /* Channel is Busy */
            flRetVal = E_NOT_OK;
        }
    }
    else
    {
        /* Invalid Channel or Driver not Ready */
        flRetVal = E_NOT_OK;
    }

    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_ASyncReceive
**
** Visibility       :   Public
**
** Description      :   This function triggers the asynchronous Receiption.
**                      This will take the external buffers under this sequence already setup-ed.
**
** Invocation       :   Application.
**
** Inputs           :  TSciDrvChn SciDrvHwChn: The Hw channel number to be triggered.
**
** Outputs          :  E_OK: If rx/ accepted.
**                     E_NOT_OK: If rx not accepted.
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType SciDrv_ASyncReceive(TSciDrvChn SciDrvHwChn)
{
    Std_ReturnType flRetVal = E_NOT_OK;
    const SSciDrvChnCfg *pChnCfg = NULL;
    uint8 flSciDrvSwChn;

    flSciDrvSwChn = SciDrv_HwGetSwChnID(SciDrvHwChn);
    // Validate Arguments and State
    if(flSciDrvSwChn < SCIDRV_MAX_CHANNELS)
    {
      if(SciDrvGlobal.State == eSciDrvStatus_Ready)
      {
          flRetVal = E_OK;
      }

      //Check if Channel is busy receiving
      if ((E_OK == flRetVal) && (eSciDrvChnResult_Busy == SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus))
      {
          flRetVal = E_NOT_OK;
      }

      if(E_OK == flRetVal)
      {
        if ((eSciDrvAsyncMode_Interrupt == SciDrvChnInfo[flSciDrvSwChn].SciAsyncMode) ||
            (eSciDrvAsyncMode_Dma == SciDrvChnInfo[flSciDrvSwChn].SciAsyncMode))
        {
                pChnCfg = &(SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[flSciDrvSwChn]);

                // Make the channel busy
                SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus = eSciDrvChnResult_Busy;
                if (eSciDrvAsyncMode_Interrupt == SciDrvChnInfo[flSciDrvSwChn].SciAsyncMode)
                {
                    SciDrvChnInfo[flSciDrvSwChn].SciBytesReceived = 0;
                    flRetVal = SciDrv_HwEnableReceiveInterrupt(pChnCfg);
                    SciDrvChnInfo[flSciDrvSwChn].SciReceiveTimeout = SCIDRV_ASYNC_RECEIVE_TIMEOUT;
                }
                else
                {
                    /*Dma Mode - To do*/
                }
            }
        }
      }
    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_SetAsyncMode
**
** Visibility       :   Public
**
** Description      :   This function set the Asyncronous mode.
**                      The Asyncronpus modes are Interrupt and DMA.
**
** Invocation       :   Application.
**
** Inputs           :  TSciDrvChn SciDrvHwChn: The Hw channel number to be triggered.
**
** Outputs          :  E_OK: If rx/ accepted.
**                     E_NOT_OK: If rx not accepted.
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType SciDrv_SetAsyncMode( TSciDrvChn SciDrvHwChn, ESciDrvAsyncMode SciMode )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    uint8 flSciDrvSwChn;

    flSciDrvSwChn = SciDrv_HwGetSwChnID(SciDrvHwChn);
    /* Validate arguments and state; all array accesses occur within boundary check scope */
    if ((SCIDRV_MAX_CHANNELS > flSciDrvSwChn) && 
        (eSciDrvStatus_Ready == SciDrvGlobal.State) &&
        (eSciDrvAsyncMode_Last > SciMode))
    {
        /* Store the Async Mode - index usage syntactically dominated by boundary check */
        SciAsyncModeHold[flSciDrvSwChn] = SciMode;
        SciDrvChnInfo[flSciDrvSwChn].SciAsyncMode = SciMode;
        SciDrvChnInfo[flSciDrvSwChn].SciSyncMode = eSciDrvSyncMode_Last;
        
        flRetVal = E_OK;
        
        if (eSciDrvAsyncMode_Dma == SciMode)
        {
          #if (DMA_PROVEOUT_ENABLED == STD_ON)
            flRetVal = SciDrv_UdmaAttach(flSciDrvSwChn,
                            SCIDRV_UDMA_INST_ID,
                            SCIDRV_UART_TX_THREAD,
                            SCIDRV_UART_RX_THREAD);
          #else
            flRetVal = E_NOT_OK;
          #endif
        }
    }
    
    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_SyncTransmit
**
** Visibility       :   Public
**
** Description      :   This function triggers the synchronous transmission.
**                      This will take the external buffers under this sequence already setup-ed.
**
** Invocation       :   Application.
**
** Inputs           :  TSciDrvChn SciDrvHwChn: The Hw channel number to be triggered.
**
** Outputs          :  E_OK: If tx/ accepted.
**                     E_NOT_OK: If tx not accepted.
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType SciDrv_SyncTransmit( TSciDrvChn SciDrvHwChn )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    uint8 flSciDrvSwChn;

    flSciDrvSwChn = SciDrv_HwGetSwChnID(SciDrvHwChn);
    if(flSciDrvSwChn < SCIDRV_MAX_CHANNELS)
    
    {
      // Validate Arguments and State
      if (SciDrvGlobal.State == eSciDrvStatus_Ready)
      {
          flRetVal = E_OK;
      }

      //Check if Channel is busy transmitting
      if ((E_OK == flRetVal) && (eSciDrvChnResult_Busy == SciDrvChnInfo[flSciDrvSwChn].SciTransmitStatus))
      {
          flRetVal = E_NOT_OK;
      }

      //Check if Mode is supported
      if ((E_OK == flRetVal) && ((eSciDrvSyncMode_Polling != SciDrvChnInfo[flSciDrvSwChn].SciSyncMode)))

      {
          flRetVal = E_NOT_OK;
      }

      if (E_OK == flRetVal)
      {
          // Make the channel busy
          SciDrvChnInfo[flSciDrvSwChn].SciTransmitStatus = eSciDrvChnResult_Busy;

          flRetVal = SciDrv_HwSyncTransmit( flSciDrvSwChn,
                          SciDrvChnInfo[flSciDrvSwChn].pSciTransmitBuffer,
                          SciDrvChnInfo[flSciDrvSwChn].SciTransmitSizeRemaining );

          // Update Channel Status
          if (E_OK == flRetVal)
          {
              SciDrvChnInfo[flSciDrvSwChn].SciTransmitStatus = eSciDrvChnResult_Ok;
          }
          else
          {
              SciDrvChnInfo[flSciDrvSwChn].SciTransmitStatus = eSciDrvChnResult_Failed;
          }
      }
    }
    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_SyncReceive
**
** Visibility       :   Public
**
** Description      :   This function triggers the synchronous Receiption.
**                      This will take the external buffers under this sequence already setup-ed.
**
** Invocation       :   Application.
**
** Inputs           :  TSciDrvChn SciDrvHwChn: The Hw channel number to be triggered.
**
** Outputs          :  E_OK: If rx/ accepted.
**                     E_NOT_OK: If rx not accepted.
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType SciDrv_SyncReceive( TSciDrvChn SciDrvHwChn )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    uint32 flLength = 0;
    uint8 flSciDrvSwChn;

    flSciDrvSwChn = SciDrv_HwGetSwChnID(SciDrvHwChn);
    if(flSciDrvSwChn < SCIDRV_MAX_CHANNELS)
    {
      // Validate Arguments and State
      if (SciDrvGlobal.State == eSciDrvStatus_Ready)
      {
          flRetVal = E_OK;
      }

      //Check if Channel is busy transmitting
      if ((E_OK == flRetVal) && (eSciDrvChnResult_Busy == SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus))
      {
          flRetVal = E_NOT_OK;
      }

      //Check if Mode is supported
      if ((E_OK == flRetVal) && ((eSciDrvSyncMode_Polling != SciDrvChnInfo[flSciDrvSwChn].SciSyncMode)))
      {
          flRetVal = E_NOT_OK;
      }

      if (E_OK == flRetVal)
      {
          // Make the channel busy
          SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus = eSciDrvChnResult_Busy;
          SciDrvChnInfo[flSciDrvSwChn].SciBytesReceived = 0;

          flLength = SciDrvChnInfo[flSciDrvSwChn].SciReceiveLength;

          flRetVal = SciDrv_HwSyncReceive( flSciDrvSwChn,
                          SciDrvChnInfo[flSciDrvSwChn].pSciReceiveBuffer,
                          &flLength );

          // Update Channel Status
          if (E_OK == flRetVal)
          {
              SciDrvChnInfo[flSciDrvSwChn].SciBytesReceived = flLength;
              SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus = eSciDrvChnResult_Ok;
          }
          else
          {
              SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus = eSciDrvChnResult_Failed;
          }
      }
    }
    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_SetSyncMode
**
** Visibility       :   Public
**
** Description      :   This function set the syncronous mode.
**                      The Asyncronpus modes is polled.
**
** Invocation       :   Application.
**
** Inputs           :  TSciDrvChn SciDrvHwChn: The Hw channel number to be triggered.
**
** Outputs          :  E_OK: If rx/ accepted.
**                     E_NOT_OK: If rx not accepted.
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType SciDrv_SetSyncMode( TSciDrvChn SciDrvHwChn, ESciDrvSyncMode SciSyncMode )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    uint8 flSciDrvSwChn;

    flSciDrvSwChn = SciDrv_HwGetSwChnID(SciDrvHwChn);
    // Validate Arguments and State
    if ((SCIDRV_MAX_CHANNELS > flSciDrvSwChn) && (eSciDrvStatus_Ready == SciDrvGlobal.State) &&
                    (eSciDrvSyncMode_Last > SciSyncMode))
    {
        // Store the Sync Mode
        SciSyncModeHold[flSciDrvSwChn] = SciSyncMode;
        SciDrvChnInfo[flSciDrvSwChn].SciSyncMode = SciSyncMode;
        SciDrvChnInfo[flSciDrvSwChn].SciAsyncMode = eSciDrvAsyncMode_Last;
        flRetVal = E_OK;
    }

    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_GetStatus
**
** Visibility       :   Public
**
** Description      :   This function gives the Global Sci Driver. 
**
** Invocation       :   Application.
**
** Inputs           :   
**
** Outputs          :  eSciDrvStatus_Uninit - The SCI Driver is not initialized or not usable
**                     eSciDrvStatus_Ready - The SCI Driver is ready for use
**                     eSciDrvStatus_Last - Last Entry
**                    
**
** Critical Section :
**
**==========================================================================*/
ESciDrvStatus SciDrv_GetStatus( void )
{
    return SciDrvGlobal.State;
}

/*============================================================================
**
** Function Name    :   SciDrv_GetStatus
**
** Visibility       :   Public
**
** Description      :    This function gives the Channel status of
                        enabled Sci Driver Channel. 
**
** Invocation       :   Application.
**
** Inputs           :   TSciDrvChn SciDrvHwChn: Hw Channel ID.
**                      ESciDrvDirection Direction: Direction of the channel.
**                      uint32 *pLength: Received Bytes 
**
** Outputs          :  eSciDrvChnResult_Ok: The last transfer on the SCI Channel has been finished successfully
**                     eSciDrvChnResult_Busy: The SCI Driver is performing a transfer on the SCI Channel
**                     eSciDrvChnResult_Failed: The last transfer on the SCI Channel has failed
**                     eSciDrvChnResult_Cancelled: The last transfer on the SCI Channel has been cancelled by user  
**                     eSciDrvChnResult_Last: Last Entry
**
** Critical Section :
**
**==========================================================================*/
ESciDrvChnResult SciDrv_GetChnResult( TSciDrvChn SciDrvHwChn, ESciDrvDirection Direction, uint32 *pLength )
{
    ESciDrvChnResult flResult = eSciDrvChnResult_Failed;
    uint8 flSciDrvSwChn;

    flSciDrvSwChn = SciDrv_HwGetSwChnID(SciDrvHwChn);
    // Validate Arguments and State
    if ((SCIDRV_MAX_CHANNELS > flSciDrvSwChn) && (SciDrvGlobal.State == eSciDrvStatus_Ready) &&
                    (eSciDrvDirection_Last > Direction))
    {
        if (eSciDrvDirection_Transmit == Direction)
        {
            flResult = SciDrvChnInfo[flSciDrvSwChn].SciTransmitStatus;
        }
        else
        {
            flResult = SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus;

            if (NULL != pLength)
            {
                *pLength = SciDrvChnInfo[flSciDrvSwChn].SciBytesReceived;
            }
        }
    }

    return flResult;
}

/*============================================================================
**
** Function Name    :   SciDrv_DisableChn
**
** Visibility       :   Public
**
** Description      :   This function disables the Scidrv Channel.
**
** Invocation       :   Application.
**
** Inputs           :   TSciDrvChn SciDrvHwChn: Hw Channel ID.
**
** Outputs          :   E_OK: Channel disabled.
**                      E_NOT_OK: Channel is not disabled.
**
** Critical Section :
**
**==========================================================================*/

Std_ReturnType SciDrv_DisableChn( TSciDrvChn SciDrvHwChn )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    const SSciDrvChnCfg *pChnCfg = NULL;
    uint8 flSciDrvSwChn;

    flSciDrvSwChn = SciDrv_HwGetSwChnID(SciDrvHwChn);
    // Validate Arguments and State
    if ((SCIDRV_MAX_CHANNELS > flSciDrvSwChn) && (SciDrvGlobal.State == eSciDrvStatus_Ready))
    {
        // Deinitialize Hardware Channel
        pChnCfg = &(SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[flSciDrvSwChn]);

        flRetVal = SciDrv_HwChannelDeinit( pChnCfg );

        // Deinitialize Fifo
        if (E_OK == flRetVal)
        {
            flRetVal = SciDrv_HwFifoDeinit( pChnCfg );
        }
    }

    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_Cancel
**
** Visibility       :   Public
**
** Description      :   This function cancels transmission or receiption which not triggered yet.
**
** Invocation       :   Application.
**
** Inputs           :   TSciDrvChn SciDrvHwChn: Hw Channel ID.
**                      ESciDrvDirection Direction: Direction of the channel.
**
** Outputs          :   E_OK: Channel cancelled.
**                      E_NOT_OK: Channel is not cancelled.
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType SciDrv_Cancel( TSciDrvChn SciDrvHwChn, ESciDrvDirection Direction )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    const SSciDrvChnCfg *pChnCfg;
    uint8 flSciDrvSwChn;

    flSciDrvSwChn = SciDrv_HwGetSwChnID(SciDrvHwChn);
    // Validate Arguments and State
    if ((flSciDrvSwChn < SCIDRV_MAX_CHANNELS) && (SciDrvGlobal.State == eSciDrvStatus_Ready) &&
                    (eSciDrvDirection_Last > Direction))
    {
        pChnCfg = &(SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[flSciDrvSwChn]);

        if (eSciDrvDirection_Transmit == Direction)
        {
            if (eSciDrvChnResult_Busy == SciDrvChnInfo[flSciDrvSwChn].SciTransmitStatus)
            {
                flRetVal = SciDrv_HwCancelTransmit( pChnCfg );

                if (E_OK == flRetVal)
                {
                    // Set channel status as Cancelled
                    SciDrvChnInfo[flSciDrvSwChn].SciTransmitStatus = eSciDrvChnResult_Cancelled;
                }
            }
            else
            {
                // Transmit not active, return OK
                flRetVal = E_OK;
            }
        }
        else
        {
            if (eSciDrvChnResult_Busy == SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus)
            {
                flRetVal = SciDrv_HwCancelReceive( pChnCfg );

                if (E_OK == flRetVal)
                {
                    // Set channel status as Cancelled
                    SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus = eSciDrvChnResult_Cancelled;
                }
            }
            else
            {
                // Receive not active, return OK
                flRetVal = E_OK;
            }
        }
    }

    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_MainFunction
**
** Visibility       :   Public
**
** Description      :   This function is invoked periodically by the Os.
**                      This function process the pending receive
**                      according to the priority.
**
** Invocation       :   Os Scheduling.
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void SciDrv_MainFunction(void)
{
    uint8 flSciDrvSwChn;
    const SSciDrvChnCfg *pChnCfg;
    uint32 flCurrentTimeout;
    
    for(flSciDrvSwChn = 0; flSciDrvSwChn < SCIDRV_MAX_CHANNELS; flSciDrvSwChn++)
    {
        pChnCfg = &(SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[flSciDrvSwChn]);
        if(eSciDrvChnResult_Busy == SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus)
        {
            /* Capture current timeout value in local variable */
            flCurrentTimeout = SciDrvChnInfo[flSciDrvSwChn].SciReceiveTimeout;
            
            /* Check if timeout is greater than zero before decrementing */
            if (flCurrentTimeout > 0U)
            {
                /* Decrement the local copy */
                flCurrentTimeout--;
                
                /* Write the decremented value back to the struct */
                SciDrvChnInfo[flSciDrvSwChn].SciReceiveTimeout = flCurrentTimeout;
                
                /* Check if the timeout has just reached zero */
                if(flCurrentTimeout == 0U)
                {
                    SciDrvChnInfo[flSciDrvSwChn].SciExtraBytesReceived = 0U;
                    SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus = eSciDrvChnResult_Failed;
                    (void)SciDrv_HwDisableReceiveInterrupt(pChnCfg);
                    if (NULL != SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[flSciDrvSwChn].pSciDrvReceiveNotificationCbk)
                    {
                        (SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[flSciDrvSwChn].pSciDrvReceiveNotificationCbk)(SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus,
                                                       SciDrvChnInfo[flSciDrvSwChn].SciBytesReceived, SciDrvChnInfo[flSciDrvSwChn].SciExtraBytesReceived);
                    }
                }
            }
        }
    }
}
/*============================================================================
**
** Function Name    :   SciDrv_TxRxISRHandle
**
** Visibility       :   Public
**
** Description      :   This ISR is invoked whenever a transmission complete
**                      or reception is in progress.
**
** Invocation       :   Interrupt.
**
** Inputs           :   const TSciDrvChn SciDrvHwChn: Hw Channel ID
**
** Outputs          :   None
**
** Critical Section :   Yes
**
**==========================================================================*/
void SciDrv_TxRxISRHandle( const TSciDrvChn SciDrvHwChn )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    const SSciDrvChnCfg *pChnCfg;
    uint32 flIntType, flRegBase, flInt2Type, flLineStatus;
    uint32 flBytesReceived, flReceiveLength; /* Local variables for safe math */
    uint16 flBytesToRead;
    uint8 flSciDrvSwChn;
    flSciDrvSwChn = SciDrv_HwGetSwChnID(SciDrvHwChn);
    
    pChnCfg = &(SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[flSciDrvSwChn]);
    
    if (flSciDrvSwChn < SCIDRV_MAX_CHANNELS)
    {
        flRegBase = pChnCfg->SciDrvBaseAddr;
        
        if (0u != flRegBase)
        {
            flIntType = SciDrv_HwGetIntrIdentityStatus (flRegBase);
            if ((flIntType & SCIDRV_INTID_RX_THRES_REACH) == SCIDRV_INTID_RX_THRES_REACH)
            {
                if ((flIntType & SCIDRV_INTID_RX_LINE_STAT_ERROR) ==
                     SCIDRV_INTID_RX_LINE_STAT_ERROR)
                {
                    /*RX line Status Error*/
                    flLineStatus = SciDrv_HwReadLineStatus(flRegBase);
                    if (((flLineStatus & SCIDRV_FIFO_PE_FE_BI_DETECTED) == SCIDRV_FIFO_PE_FE_BI_DETECTED)
                        || ((flLineStatus & SCIDRV_OVERRUN_ERROR) == SCIDRV_OVERRUN_ERROR))

                    {
                        SciDrv_ReceiveErrorRecovery( pChnCfg );

                        if (eSciDrvChnResult_Busy == SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus)
                        {
                            SciDrvChnInfo[flSciDrvSwChn].SciBytesReceived = 0u;
                            SciDrvChnInfo[flSciDrvSwChn].SciExtraBytesReceived = 0u;
                            // Mark last operation as failed
                            SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus = eSciDrvChnResult_Failed;
                            if (NULL != SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[flSciDrvSwChn].pSciDrvReceiveNotificationCbk)
                            {
                               (SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[flSciDrvSwChn].pSciDrvReceiveNotificationCbk)(SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus,
                                                       SciDrvChnInfo[flSciDrvSwChn].SciBytesReceived, SciDrvChnInfo[flSciDrvSwChn].SciExtraBytesReceived);
                            }
                        }
                    }
                }
                else
                {
                    if ((flIntType & SCIDRV_INTID_CHAR_TIMEOUT) == SCIDRV_INTID_CHAR_TIMEOUT)
                    {
                        (void)SciDrv_HwDisableReceiveInterrupt(pChnCfg);
                    }
                    
                    flReceiveLength = SciDrvChnInfo[flSciDrvSwChn].SciReceiveLength;
                    if (flReceiveLength > 0U)
                    {
                        flBytesToRead = 0u;
                        flBytesReceived = SciDrvChnInfo[flSciDrvSwChn].SciBytesReceived;
                        
                        flRetVal = SciDrv_HwInterruptReadFifo( flSciDrvSwChn,
                                                    &SciDrvChnInfo[flSciDrvSwChn].pSciReceiveBuffer[flBytesReceived],
                                                    &flBytesToRead );
                        if (E_OK == flRetVal)
                        {
                            /* Safe Addition Check using local variables */
                            if (flBytesToRead <= (0xFFFFFFFFU - flBytesReceived))
                            {
                                flBytesReceived += (uint32)flBytesToRead;
                            }
                            else
                            {
                                flBytesReceived = 0xFFFFFFFFU;
                            }
                            /* Update struct with local value */
                            SciDrvChnInfo[flSciDrvSwChn].SciBytesReceived = flBytesReceived;
                        }
                    }
                    else
                    {
                        (void)SciDrv_HwDisableReceiveInterrupt(pChnCfg);
                    }
                    /*When there is no data in left in FIFO*/
                    if ((uint32) UART_LSR_UART_RX_FIFO_E_RX_FIFO_E_VALUE_0 ==
                        (SciDrv_Read_Reg32(flRegBase + UART_LSR_UART) &
                        UART_LSR_UART_RX_FIFO_E_MASK))
                    { 
                        flBytesReceived = SciDrvChnInfo[flSciDrvSwChn].SciBytesReceived;
                        flReceiveLength = SciDrvChnInfo[flSciDrvSwChn].SciReceiveLength;
                        
                        if(flBytesReceived < flReceiveLength)
                        {
                            (void)SciDrv_HwEnableReceiveInterrupt(pChnCfg);
                            SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus = eSciDrvChnResult_Busy;
                        }
                        /* Explicit check to prevent subtraction wraparound (Warning 154222) */
                        else if(flBytesReceived >= flReceiveLength)
                        {
                            /* Analyzer now sees that result cannot be negative */
                            SciDrvChnInfo[flSciDrvSwChn].SciExtraBytesReceived = flBytesReceived - flReceiveLength;
                            SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus = eSciDrvChnResult_Ok;
                            SciDrvChnInfo[flSciDrvSwChn].SciReceiveTimeout = SCIDRV_ASYNC_RECEIVE_TIMEOUT;
                            if (NULL != SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[flSciDrvSwChn].pSciDrvReceiveNotificationCbk)
                            {
                                (SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[flSciDrvSwChn].pSciDrvReceiveNotificationCbk)(SciDrvChnInfo[flSciDrvSwChn].SciReceiveStatus,
                                                   flBytesReceived, SciDrvChnInfo[flSciDrvSwChn].SciExtraBytesReceived);
                            }
                        }
                        else
                        {
                          /* Do Nothing */
                        }
                    }
                }
            }
            
            else if ((flIntType & SCIDRV_INTID_TX_THRES_REACH) == SCIDRV_INTID_TX_THRES_REACH)
            {
                if(SciDrvChnInfo[flSciDrvSwChn].SciTransmitSizeRemaining > 0U)
                {
                    SciDrvChnInfo[flSciDrvSwChn].SciTransmitSizeRemaining = SciDrv_HwInterruptWriteFifo(flSciDrvSwChn, &SciDrvChnInfo[flSciDrvSwChn].pSciTransmitBuffer[SciDrvChnInfo[flSciDrvSwChn].SciTransmitCount],
                                                                           SciDrvChnInfo[flSciDrvSwChn].SciTransmitSizeRemaining);
                    
                    if ((SciDrvChnInfo[flSciDrvSwChn].SciTransmitSizeRemaining) == 0U)
                    {
                        SciDrvChnInfo[flSciDrvSwChn].SciTxDataSent = TRUE;
                        (void)SciDrv_HwDisableTransmitInterrupt(pChnCfg);
                        SciDrv_HwInterrupt2Enable(flRegBase, SCIDRV_INTR2_TX_EMPTY);
                        SciDrvChnInfo[flSciDrvSwChn].SciTransmitStatus = eSciDrvChnResult_Ok;
                        if (NULL != SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[flSciDrvSwChn].pSciDrvTransmitNotificationCbk)
                        {
                            (SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[flSciDrvSwChn].pSciDrvTransmitNotificationCbk)(SciDrvChnInfo[flSciDrvSwChn].SciTransmitStatus);
                        }
                    }
                }
                else
                {
                    /*Disable Transmit Interrupt*/
                    (void)SciDrv_HwDisableTransmitInterrupt(pChnCfg);
                }
            }
            else
            {
                /*Do Nothing*/
            }
            if(SciDrvChnInfo[flSciDrvSwChn].SciTxDataSent == TRUE)
            {
                flInt2Type = SciDrv_Read_Reg32(flRegBase + UART_ISR2) &
                              (SCIDRV_INTR2_RX_EMPTY | SCIDRV_INTR2_TX_EMPTY);
                if((flInt2Type & SCIDRV_INTR2_TX_EMPTY) != 0U)
                {
                    SciDrv_HwInterrupt2Disable(flRegBase, SCIDRV_INTR2_TX_EMPTY);
                    SciDrvChnInfo[flSciDrvSwChn].SciTxDataSent = FALSE;
                }
            }
        }
    }
}


/*****************************************************************************
*                           Private Functions                                *
******************************************************************************/

/*============================================================================
**
** Function Name    :   SciDrv_InitChnInfo
**
** Visibility       :   Private
**
** Description      :   Initializing the SSciDrvChnInfo
**
** Invocation       :   Static
**
** Inputs           :   TSciDrvChn SciDrvSwChn: SciDrv Sw Channel Configured
**
** Outputs          :   None
**
** Critical Section :   
**
**==========================================================================*/
static void SciDrv_InitChnInfo( TSciDrvChn SciDrvSwChn )
{
    SciDrvChnInfo[SciDrvSwChn].SciTransmitSizeRemaining = 0u;
    SciDrvChnInfo[SciDrvSwChn].SciTransmitCount = 0u;
    SciDrvChnInfo[SciDrvSwChn].SciReceiveLength = 0u;
    SciDrvChnInfo[SciDrvSwChn].SciTxDataSent = FALSE;
    SciDrvChnInfo[SciDrvSwChn].pSciTransmitBuffer = NULL;
    SciDrvChnInfo[SciDrvSwChn].pSciReceiveBuffer = NULL;
    SciDrvChnInfo[SciDrvSwChn].SciTransmitStatus = eSciDrvChnResult_Ok;
    SciDrvChnInfo[SciDrvSwChn].SciReceiveStatus = eSciDrvChnResult_Ok;
    SciDrvChnInfo[SciDrvSwChn].SciAsyncMode = eSciDrvAsyncMode_Last;
    SciDrvChnInfo[SciDrvSwChn].SciSyncMode = eSciDrvSyncMode_Last;
  #if(DMA_PROVEOUT_ENABLED == STD_ON)
    SciDrv_RingBufferInit( &SciDrvChnInfo[SciDrvSwChn].SciTxIB );
    SciDrv_RingBufferInit( &SciDrvChnInfo[SciDrvSwChn].SciRxIB );
  #endif
	SciDrvChnInfo[SciDrvSwChn].SciBytesReceived = 0;

}

/*============================================================================
**
** Function Name    :   SciDrv_HwChannelInit
**
** Visibility       :   Private
**
** Description      :   Initializing the SciDrv Instance Configured
**
** Invocation       :   Static
**
** Inputs           :   SSciDrvChnCfg *pChnCfg: Configuration structure
**
** Outputs          :   E_OK: Configured
**                      E_OK_NOT: Not Configured
**
** Critical Section :   
**
**==========================================================================*/
static Std_ReturnType SciDrv_HwChannelInit ( const SSciDrvChnCfg *pChnCfg )
{
	Std_ReturnType flRetVal= E_NOT_OK;
	uint32 flRegBase, flInpClkFrq, flLengthFlag, flParityFlag, flDivisorValue;
	
	if (NULL_PTR != pChnCfg)
	{
		flRegBase = pChnCfg->SciDrvBaseAddr; 
		flInpClkFrq = pChnCfg->SciDrvInputClkFreq;
		
		if (0u != flRegBase)
		{
			/* Reset Module */
			SciDrv_ResetModule(flRegBase);
			
			//Calculate the Divisor Value 
			flDivisorValue = SciDrv_ComputeDivisorValue(flInpClkFrq, pChnCfg->SciDrvBaudRate, pChnCfg->SciDrvOperMode);
			
			(void)SciDrv_HwWriteDivisorLatch(flRegBase, flDivisorValue);

            
			(void)SciDrv_HwEnableRegisterConfigMode(flRegBase, SCIDRV_REG_CONFIG_MODE_B);
			
			//Configuring Line Characteristics
			flLengthFlag = ((uint32)pChnCfg->SciDrvDataLength << UART_LCR_CHAR_LENGTH_SHIFT);
            flLengthFlag |= ((uint32)pChnCfg->SciDrvStopBitsLength << UART_LCR_NB_STOP_SHIFT);
            flParityFlag = ((uint32)pChnCfg->SciDrvEnableParity << UART_LCR_PARITY_EN_SHIFT);
			SciDrv_HwLineCharConfig(flRegBase, flLengthFlag, flParityFlag);
			
            //Disable write access to Divisor Latches
			SciDrv_DisableDivisorLatch(flRegBase);
			
			//Disabling break Control
			SciDrv_HwBreakControl(flRegBase, SCIDRV_BREAK_COND_DISABLE);
			
			//Set UART Operational Mode
			(void)SciDrv_HwOperatingModeSelect(flRegBase, pChnCfg->SciDrvOperMode);
			
			//Hardware Control disable To Do
			flRetVal = E_OK;
			
		}
	}
	return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwChannelDeinit
**
** Visibility       :   Private
**
** Description      :   Deinitializing the SciDrv Instance Configured
**
** Invocation       :   Static
**
** Inputs           :   SSciDrvChnCfg *pChnCfg: Configuration structure
**
** Outputs          :   E_OK: Deinitialized
**                      E_OK_NOT: Not Deinitialized
**
** Critical Section :   
**
**==========================================================================*/
static Std_ReturnType SciDrv_HwChannelDeinit( const SSciDrvChnCfg *pChnCfg )
{
    Std_ReturnType flRetVal= E_NOT_OK;

    if (NULL_PTR != pChnCfg)
    {
        (void)SciDrv_HwInterruptDisable(pChnCfg->SciDrvBaseAddr, SCIDRV_INTR_RHR_CTI|SCIDRV_INTR_THR|SCIDRV_INTR_LINE_STAT);
        SciDrv_HwInterrupt2Disable(pChnCfg->SciDrvBaseAddr, SCIDRV_INTR2_TX_EMPTY);
        (void)SciDrv_HwOperatingModeSelect(pChnCfg->SciDrvBaseAddr, SCIDRV_OPER_MODE_DISABLED);
    	flRetVal = E_OK;
    }
    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwFifoInit
**
** Visibility       :   Private
**
** Description      :   Initializing and Configuring Fifo
**
** Invocation       :   Static
**
** Inputs           :   SSciDrvChnCfg *pChnCfg: Configuration structure
**                      TSciDrvChn SciDrvSwChn: SciDrv Sw Channel Configured 
**
** Outputs          :   E_OK: Initialized
**                      E_OK_NOT: Not Initialized
**
** Critical Section :   
**
**==========================================================================*/
static Std_ReturnType SciDrv_HwFifoInit(const SSciDrvChnCfg *pChnCfg, TSciDrvChn SciDrvSwChn)
{
    Std_ReturnType RetVal = E_NOT_OK;

    if (pChnCfg != NULL_PTR)
    {
        const uint32 RegBaseAddr = pChnCfg->SciDrvBaseAddr;
        uint32 FifoCfgVal;

        if (eSciDrvAsyncMode_Interrupt == SciDrvChnInfo[SciDrvSwChn].SciAsyncMode)
        {
            /* ---- Interrupt mode: FIFO enabled, DMA disabled (FCR path) ---- */
            FifoCfgVal = SCIDRV_FIFO_CONFIG(
                            (SCIDRV_TRIG_LVL_GRANULARITY_4),
                            (SCIDRV_TRIG_LVL_GRANULARITY_4),
                            (pChnCfg->SciDrvTxTrigLvl),
                            (pChnCfg->SciDrvRxTrigLvl),
                            (1U), (1U),
                            (SCIDRV_DMA_EN_PATH_FCR),         /* no SCR DMA */
                            (SCIDRV_DMA_MODE_0_ENABLE));
            (void)SciDrv_HwFifoConfig(RegBaseAddr, FifoCfgVal);
        }
        #if (DMA_PROVEOUT_ENABLED == STD_ON)
        else if(eSciDrvAsyncMode_Dma == SciDrvChnInfo[SciDrvSwChn].SciAsyncMode)
        {
            /* ---------------- DMA mode (SDK pattern) ----------------
               1) Reset FIFOs once (FCR = 0x06)
               2) Enable FIFO + DMA Mode-1 in FCR path value (we keep SCR path actually)
               3) Enable UART DMA through SCR bits (RXDMA_EN|TXDMA_EN)
               4) MDR1 = 0  (16x UART)
               5) TX_DMA_THRESHOLD = 1
               6) Keep ETBEI=1 (gates TX DMA requests)
            */

            /* 1) one-time FIFO reset (RX/TX clear) */
            SciDrv_Write_Reg32(RegBaseAddr + UART_FCR, 0x00000006U); /* RX/TX reset */  /* FCR offset from SciDrv_Types.h */

            /* 2) FIFO enable with 1-byte RX trig (0xC2 mirrors SDK’s bring-up) */
            SciDrv_Write_Reg32(RegBaseAddr + UART_FCR, 0x000000C2U); /* FIFOE=1, trig=1 */

            /* 3) SCR: enable RX/TX DMA (bits 0 and 1) */
            {
                uint32 scrVal = SciDrv_Read_Reg32(RegBaseAddr + UART_SCR);
                scrVal |= 0x00000003U;  /* RXDMA_EN | TXDMA_EN */
                SciDrv_Write_Reg32(RegBaseAddr + UART_SCR, scrVal);
            }

            /* 4) MDR1 = 0 (16x) */
            SciDrv_Write_Reg32(RegBaseAddr + UART_MDR1, 0x00000000U);

            /* 5) TX DMA threshold = 1 byte */
            SciDrv_Write_Reg32(RegBaseAddr + UART_TX_DMA_THRESHOLD, 0x00000001U); /* TX_DMA_THRESHOLD present in your header */

            /* 6) Make sure TX DMA gate stays open: ETBEI=1 and IER2 DMA enables.
                   This is done in helper below. */
            SciDrv_UartDmaArmTx((uint8)SciDrvSwChn);
        }
        #endif
        else
        {
          FifoCfgVal = SCIDRV_FIFO_CONFIG(SCIDRV_TRIG_LVL_GRANULARITY_4,
                        SCIDRV_TRIG_LVL_GRANULARITY_4,
                        pChnCfg->SciDrvTxTrigLvl,
                        pChnCfg->SciDrvRxTrigLvl,
                        1U,
                        1U,
                        SCIDRV_DMA_EN_PATH_FCR,
                        SCIDRV_DMA_MODE_1_ENABLE);

          /* Configuring the FIFO settings. */
          SciDrv_HwFifoConfig(RegBaseAddr, FifoCfgVal);
        }
        RetVal = E_OK;
    }
    return RetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwFifoDeinit
**
** Visibility       :   Private
**
** Description      :   Deinitializing and Configuring Fifo
**
** Invocation       :   Static
**
** Inputs           :   SSciDrvChnCfg *pChnCfg: Configuration structure 
**
** Outputs          :   E_OK: Deinitialized
**                      E_OK_NOT: Not Deinitialized
**
** Critical Section :   
**
**==========================================================================*/
static Std_ReturnType SciDrv_HwFifoDeinit( const SSciDrvChnCfg *pChnCfg )
{
	Std_ReturnType flRetVal= E_NOT_OK;
    uint32 flEnhanceBitVal;
    if(NULL != pChnCfg)
    {
	    flEnhanceBitVal = SciDrv_HwEnableEnhaceFunc(pChnCfg->SciDrvBaseAddr);
        SciDrv_Write_Field32(pChnCfg->SciDrvBaseAddr, UART_FCR_FIFO_EN_MASK, UART_FCR_FIFO_EN_SHIFT, UART_FCR_FIFO_EN_FIFO_EN_VALUE_0);
        SciDrv_HwEnhanFuncBitValRestore(pChnCfg->SciDrvBaseAddr,flEnhanceBitVal);
        flRetVal = E_OK;
    }
	return flRetVal;
}

/*DMA mode is not supported as for now and WriteIB and ReadIB are supported only in DMA mode*/
#if(DMA_PROVEOUT_ENABLED == STD_ON)
/*============================================================================
**
** Function Name    :   SciDrv_RingBufferInit
**
** Visibility       :   Private
**
** Description      :   Initializing RingBuffer
**
** Invocation       :   Static
**
** Inputs           :   SSciDrvRingBuffer *buffer: Ring Buffer Structure
**
** Outputs          :   
**
** Critical Section :   
**
**==========================================================================*/
static void SciDrv_RingBufferInit( SSciDrvRingBuffer *buffer )
{
    /* Initialize variables */
    buffer->read_index = 0;
    buffer->write_index = 0;
    buffer->fill_count = 0;
    (void) memset( buffer->data, 0x00, SCI_RING_BUFFER_SIZE );
}

/*============================================================================
**
** Function Name    :   SciDrv_RingBufferWrite
**
** Visibility       :   Private
**
** Description      :   Writing to RingBuffer
**
** Invocation       :   Static
**
** Inputs           :   SSciDrvRingBuffer *buffer: Ring Buffer Structure
**                      uint8 *data: Data to be written
**                      uint16 size: data size
**
** Outputs          :   Returns the written size
**
** Critical Section :   
**
**==========================================================================*/
static uint16 SciDrv_RingBufferWrite( SSciDrvRingBuffer *buffer, const uint8 *data, uint16 size )
{
    uint16 flIteration = 0;
    uint16 flWriteIndex = 0;

    SCIDRV_ENTER_CRITICAL_SECTION();

    /* Check if we have enough space */
    if (size < (SCI_RING_BUFFER_SIZE - buffer->fill_count))
    {
        flWriteIndex = buffer->write_index;
        /* Copy data */
        for (flIteration = 0u; flIteration < size; flIteration++)
        {
            buffer->data[flWriteIndex] = data[flIteration];
            flWriteIndex = (flWriteIndex + 1u) % SCI_RING_BUFFER_SIZE;
        }

        /* Update the fill count and write index */
        buffer->write_index = flWriteIndex;
        buffer->fill_count += size;
    }
    else
    {
        size = 0;
    }

    SCIDRV_EXIT_CRITICAL_SECTION();

    return size;
}

/*============================================================================
**
** Function Name    :   SciDrv_RingBufferRead
**
** Visibility       :   Private
**
** Description      :   Writing to RingBuffer
**
** Invocation       :   Static
**
** Inputs           :   SSciDrvRingBuffer *buffer: Ring Buffer Structure
**                      uint8 *data: Read data to 
**                      uint16 size: data size
**
** Outputs          :   Returns the raed size
**
** Critical Section :   
**
**==========================================================================*/
static uint16 SciDrv_RingBufferRead( SSciDrvRingBuffer *buffer, uint8 *data, uint16 size )
{
    uint16 flMsgLength = 0;
    uint16 flFillCount = 0;
    uint16 flIteration = 0;
    uint16 flReadIndex = 0;
 
    SCIDRV_ENTER_CRITICAL_SECTION();

    flFillCount = buffer->fill_count;

    /* Check if buffer is empty */
    if (flFillCount != 0u)
    {
        if (size < flFillCount)
        {
            flMsgLength = size;
        }
        else
        {
            flMsgLength = flFillCount;
        }

        flReadIndex = buffer->read_index;

        /* Copy data */
        for (flIteration = 0u; (flIteration < flMsgLength); flIteration++)
        {
            data[flIteration] = buffer->data[flReadIndex];
            flReadIndex = (flReadIndex + 1u) % SCI_RING_BUFFER_SIZE;
        }

        buffer->read_index = flReadIndex;
        buffer->fill_count -= flMsgLength;
    }

    SCIDRV_EXIT_CRITICAL_SECTION();

    return flMsgLength;
}
#endif

/*============================================================================
**
** Function Name    :   SciDrv_HwEnableTransmitInterrupt
**
** Visibility       :   Private
**
** Description      :   Enabling Transmit Interrupt
**
** Invocation       :   Static
**
** Inputs           :   const SSciDrvChnCfg *pChnCfg
**
** Outputs          :   E_OK: Enabled
**                      
**
** Critical Section :   
**
**==========================================================================*/
static Std_ReturnType SciDrv_HwEnableTransmitInterrupt( const SSciDrvChnCfg *pChnCfg )
{
	Std_ReturnType flRetVal= E_NOT_OK;
	uint32 flRegBase;
	
	flRegBase = pChnCfg->SciDrvBaseAddr;
	
	//Enable the transmit interrupt
	flRetVal = SciDrv_HwInterruptEnable(flRegBase, SCIDRV_INTR_THR);
    
	return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwDisableTransmitInterrupt
**
** Visibility       :   Private
**
** Description      :   Disabling Transmit Interrupt
**
** Invocation       :   Static
**
** Inputs           :   const SSciDrvChnCfg *pChnCfg
**
** Outputs          :   E_OK: Enabled
**                      
**
** Critical Section :   
**
**==========================================================================*/
static Std_ReturnType SciDrv_HwDisableTransmitInterrupt( const SSciDrvChnCfg *pChnCfg )
{
	Std_ReturnType flRetVal= E_NOT_OK;
	uint32 flRegBase;
	
	flRegBase = pChnCfg->SciDrvBaseAddr;
	
	//Enable the transmit interrupt
	flRetVal = SciDrv_HwInterruptDisable(flRegBase, SCIDRV_INTR_THR);
	
	return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwInterruptWriteFifo
**
** Visibility       :   Private
**
** Description      :   Fifo write in Interrupt Mode
**
** Invocation       :   Static
**
** Inputs           :   TSciDrvChn SciDrvSwChn: SciDrv Sw Channel 
**                      uint8 *pData: Data to write
**                      uint16 pLength: Length of the data to write 
**
** Outputs          :   Returns Length written
**                      
**
** Critical Section :   
**
**==========================================================================*/
static uint32 SciDrv_HwInterruptWriteFifo( TSciDrvChn SciDrvSwChn, const uint8 *pData, uint32 pLength )
{
    uint32 flBytesToTransfer, flBytesToTransferred;
    uint32 flTransmitCount; /* Local variable for safe increment */
    
    const SSciDrvChnCfg *pChnCfg;
    const uint8 *pCurrentData = pData;
    pChnCfg = &(SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[SciDrvSwChn]);
    
    flBytesToTransfer = pLength;
    if(flBytesToTransfer >= pChnCfg->SciDrvTxTrigLvl)
    {
        flBytesToTransfer = pChnCfg->SciDrvTxTrigLvl;
    }
    
    flBytesToTransferred = flBytesToTransfer;
    /* Send characters until FIFO threshold level or done. */
    while (flBytesToTransfer != 0U)
    {
        SciDrv_HwPutChar(pChnCfg->SciDrvBaseAddr, *pCurrentData);
        pCurrentData++;
        flBytesToTransfer--;
        
        /* Capture current count and perform safe increment */
        flTransmitCount = SciDrvChnInfo[SciDrvSwChn].SciTransmitCount;
        if (flTransmitCount < 0xFFFFFFFFU)
        {
            flTransmitCount++;
            SciDrvChnInfo[SciDrvSwChn].SciTransmitCount = flTransmitCount;
        }
    }
    
    return (pLength - flBytesToTransferred);
}

/*============================================================================
**
** Function Name    :   SciDrv_HwEnableReceiveInterrupt
**
** Visibility       :   Private
**
** Description      :   Enabling Receive Interrupt
**
** Invocation       :   Static
**
** Inputs           :   const SSciDrvChnCfg *pChnCfg
**
** Outputs          :   E_OK: Enabled
**                      
**
** Critical Section :   
**
**==========================================================================*/
static Std_ReturnType SciDrv_HwEnableReceiveInterrupt( const SSciDrvChnCfg *pChnCfg )
{
    Std_ReturnType flRetVal= E_NOT_OK;
	uint32 flRegBase;

	flRegBase = pChnCfg->SciDrvBaseAddr;
    
    //Enable the transmit interrupt
    flRetVal = SciDrv_HwInterruptEnable(flRegBase, (uint32) SCIDRV_INTR_RHR_CTI | SCIDRV_INTR_LINE_STAT);
    

    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwDisableReceiveInterrupt
**
** Visibility       :   Private
**
** Description      :   Disabling Receive Interrupt
**
** Invocation       :   Static
**
** Inputs           :   const SSciDrvChnCfg *pChnCfg: Configuratiom Structure
**
** Outputs          :   E_OK: Disabled
**                      
**
** Critical Section :   
**
**==========================================================================*/
static Std_ReturnType SciDrv_HwDisableReceiveInterrupt( const SSciDrvChnCfg *pChnCfg )
{
	Std_ReturnType flRetVal= E_OK;
	uint32 flRegBase;
	
	flRegBase = pChnCfg->SciDrvBaseAddr;
	
	//Enable the transmit interrupt
	(void)SciDrv_HwInterruptDisable(flRegBase, SCIDRV_INTR_RHR_CTI | SCIDRV_INTR_LINE_STAT);
	
	return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwInterruptReadFifo
**
** Visibility       :   Private
**
** Description      :   Fifo read in Interrupt Mode to check data availability in FIFO
**
** Invocation       :   Static
**
** Inputs           :   TSciDrvChn SciDrvSwChn: SciDrv Sw Channel 
**                      uint8 *pData: Data to read
**                      uint16 pLength: Length of the data to Read 
**
** Outputs          :   Returns Length written
**                      
**
** Critical Section :   
**
**==========================================================================*/
static Std_ReturnType SciDrv_HwInterruptReadFifo( TSciDrvChn SciDrvSwChn, uint8 *pData, uint16 *pLength )
{
   Std_ReturnType flRetVal= E_NOT_OK;
    uint16 flBytesToRead;
    uint16 flData;
    uint16 flInt;
    uint32 flRegBase, flLcrRegValue;
    const SSciDrvChnCfg *pChnCfg;

    pChnCfg = &(SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[SciDrvSwChn]);

    flRegBase = pChnCfg->SciDrvBaseAddr;
    
    if (0u != flRegBase)
    {
        // Find out the how much data available in the Fifo
        flBytesToRead = SciDrv_Read_Field32(flRegBase + UART_RXFIFO_LVL, UART_RXFIFO_LVL_RXFIFO_LVL_MASK, UART_RXFIFO_LVL_RXFIFO_LVL_SHIFT);
        /* Preserving the current value of LCR. */
        flLcrRegValue = SciDrv_Read_Reg32(flRegBase + UART_LCR);

        /* Switching to Register Operational Mode of operation. */
        SciDrv_Write_Reg32(flRegBase + UART_LCR, SciDrv_Read_Reg32(flRegBase + UART_LCR)
                                & 0x7FU);
                // Read data to Fifo
                for (flInt = 0; flInt < flBytesToRead; flInt++)
                {
                    flData = SciDrv_Read_Reg32(flRegBase + UART_RHR);
                    pData[flInt] = (uint8) flData;
                    
                }


        /* Restoring the value of LCR. */
        SciDrv_Write_Reg32(flRegBase + UART_LCR, flLcrRegValue);
        // Send back number of bytes actually read from the Fifo
        *pLength = flBytesToRead;

        flRetVal= E_OK;
    }

    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwSyncTransmit
**
** Visibility       :   Private
**
** Description      :   Transmit - Polling
**
** Invocation       :   Static
**
** Inputs           :   TSciDrvChn SciDrvSwChn: SciDrv Sw Channel 
**                      uint8 *pData: Data to write
**                      uint16 pLength: Length of the data to write 
**
** Outputs          :   E_OK: Success
**                      E_NOT_OK: Failed
**                      
**
** Critical Section :   
**
**==========================================================================*/
static Std_ReturnType SciDrv_HwSyncTransmit( TSciDrvChn SciDrvSwChn, const uint8 *pBuffer, uint32 Length )
{
    Std_ReturnType flRetVal = E_NOT_OK;
    uint16 flBytesToWrite;
    uint32 flRegBase;
    const SSciDrvChnCfg *pChnCfg;
    uint32 flTotalBytesSent = 0U;
    uint32 flTimeout = 0U;
    uint32 flLineStatus = 0U;
    
    pChnCfg = &(SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[SciDrvSwChn]);
    flRegBase = pChnCfg->SciDrvBaseAddr;

    if(0u != flRegBase)
    {
        while (flTotalBytesSent < Length)
        {
            flBytesToWrite = (uint16)(Length - flTotalBytesSent);
            flRetVal = SciDrv_HwPollingWriteFifo( SciDrvSwChn, &pBuffer[flTotalBytesSent], &flBytesToWrite );
            if (E_OK == flRetVal)
            {
                /* Use local variables for safe arithmetic */
                uint32 flLocalTotalBytesSent = flTotalBytesSent;
                uint32 flLocalBytesToWrite = (uint32)flBytesToWrite;
                
                /* Explicit overflow guard for Warning 71828 */
                if (flLocalBytesToWrite <= (0xFFFFFFFFU - flLocalTotalBytesSent))
                {
                    flLocalTotalBytesSent += flLocalBytesToWrite;
                    flTotalBytesSent = flLocalTotalBytesSent; /* Write back result */
                }
                else
                {
                    flRetVal = E_NOT_OK;
                    break;
                }
                
                flTimeout = SCIDRV_SYNC_TRANSMIT_TIMEOUT;

                // Wait for timeout
                while (flTimeout > 0U)
                {
                    flTimeout--;
                }
               
                flLineStatus = SciDrv_HwReadLineStatus(flRegBase);
                //Check for shift register and fifo - Is empty or Not
                if ((UART_LSR_UART_TX_FIFO_E_MASK | UART_LSR_UART_TX_SR_E_MASK) != (flLineStatus & (UART_LSR_UART_TX_FIFO_E_MASK | UART_LSR_UART_TX_SR_E_MASK)))
                {
                    flRetVal= E_NOT_OK;
                }
            }

        }
        
        
    }
    return flRetVal;
}
/*============================================================================
**
** Function Name    :   SciDrv_HwSyncReceive
**
** Visibility       :   Private
**
** Description      :   Receive - Polling
**
** Invocation       :   Static
**
** Inputs           :   TSciDrvChn SciDrvSwChn: SciDrv Sw Channel 
**                      uint8 *pData: Data to read
**                      uint16 pLength: Length of the data to read 
**
** Outputs          :   E_OK: Success
**                      E_NOT_OK: Failed
**                      
**
** Critical Section :   
**
**==========================================================================*/
static Std_ReturnType SciDrv_HwSyncReceive(TSciDrvChn SciDrvSwChn, const uint8 *pBuffer, uint32 *pLength)
{
    Std_ReturnType flRetVal= E_NOT_OK;
    uint16 flBytesToRead;
    uint32 flRegBase;
    const SSciDrvChnCfg *pChnCfg;

    pChnCfg = &(SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[SciDrvSwChn]);
    flRegBase = pChnCfg->SciDrvBaseAddr;

    if(0u != flRegBase)
    {
            flBytesToRead = *pLength;

            flRetVal= SciDrv_HwPollingReadFifo( SciDrvSwChn, pBuffer, &flBytesToRead );

            if (E_OK == flRetVal)
            { 
                *pLength = flBytesToRead;   
            }  
    }

    if (E_NOT_OK == flRetVal)
    {
        *pLength = 0;
    }
    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwPollingReadFifo
**
** Visibility       :   Private
**
** Description      :   Read Fifo - Polling and Interrupt
**
** Invocation       :   Static
**
** Inputs           :   TSciDrvChn SciDrvSwChn: SciDrv Sw Channel 
**                      uint8 *pData: Data to read
**                      uint16 pLength: Length of the data to read 
**
** Outputs          :   E_OK: Success
**                      E_NOT_OK: Failed
**                      
**
** Critical Section :   
**
**==========================================================================*/
static Std_ReturnType SciDrv_HwPollingReadFifo( TSciDrvChn SciDrvSwChn, uint8 *pData, uint16 *pLength )
{
    Std_ReturnType flRetVal= E_NOT_OK;
    uint16 flBytesToRead;
    uint16 flData;
    uint16 flInt;
    uint32 flRegBase, flLcrRegValue;
    const SSciDrvChnCfg *pChnCfg;

    pChnCfg = &(SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[SciDrvSwChn]);

    flRegBase = pChnCfg->SciDrvBaseAddr;
    
    if (0u != flRegBase)
    {
        // Find out the how much data available in the Fifo
        flBytesToRead = SciDrv_Read_Field32(flRegBase + UART_RXFIFO_LVL, UART_RXFIFO_LVL_RXFIFO_LVL_MASK, UART_RXFIFO_LVL_RXFIFO_LVL_SHIFT);
        // Find out how much we can read
        if (flBytesToRead > *pLength)
        {
            flBytesToRead = *pLength;
        }
        /* Preserving the current value of LCR. */
        flLcrRegValue = SciDrv_Read_Reg32(flRegBase + UART_LCR);

        /* Switching to Register Operational Mode of operation. */
        SciDrv_Write_Reg32(flRegBase + UART_LCR, SciDrv_Read_Reg32(flRegBase + UART_LCR)
                                & 0x7FU);
        if ((uint32) UART_LSR_UART_RX_FIFO_E_RX_FIFO_E_VALUE_0 !=
            (SciDrv_Read_Reg32(flRegBase + UART_LSR_UART) &
            UART_LSR_UART_RX_FIFO_E_MASK))
            {
                // Read data to Fifo
                for (flInt = 0; flInt < flBytesToRead; flInt++)
                {
                    flData = SciDrv_Read_Reg32(flRegBase + UART_RHR);
                    pData[flInt] = (uint8) flData;
                    
                }

            }

        /* Restoring the value of LCR. */
        SciDrv_Write_Reg32(flRegBase + UART_LCR, flLcrRegValue);
        // Send back number of bytes actually read from the Fifo
        *pLength = flBytesToRead;

        flRetVal= E_OK;
    }

    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwPollingWriteFifo
**
** Visibility       :   Private
**
** Description      :   Write Fifo - Polling
**
** Invocation       :   Static
**
** Inputs           :   TSciDrvChn SciDrvSwChn: SciDrv Sw Channel 
**                      uint8 *pData: Data to write
**                      uint16 pLength: Length of the data to write 
**
** Outputs          :   E_OK: Success
**                      E_NOT_OK: Failed
**                      
**
** Critical Section :   
**
**==========================================================================*/
static Std_ReturnType SciDrv_HwPollingWriteFifo( TSciDrvChn SciDrvSwChn, const uint8 *pData, uint16 *pLength )
{
    Std_ReturnType flRetVal= E_NOT_OK;
    uint32 flRegValue, flRegBase;
    uint16 flBytesToWrite;
    uint16 flData;
    uint16 flInt;
    const SSciDrvChnCfg *pChnCfg;

	pChnCfg = &(SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[SciDrvSwChn]);

    // Get the base register pointer
    flRegBase = pChnCfg->SciDrvBaseAddr;

    if (0u !=  flRegBase)
    {
        flRegValue = SciDrv_Read_Field32((flRegBase + UART_TXFIFO_LVL), UART_TXFIFO_LVL_TXFIFO_LVL_MASK, UART_TXFIFO_LVL_TXFIFO_LVL_SHIFT);

        // Find out the available space
        flBytesToWrite = (SCIDRV_FIFO_MAX_VAL - flRegValue);

        // Find out how much to write
        if (flBytesToWrite > *pLength)
        {
            flBytesToWrite = *pLength;
        }

        // Write data to Fifo
        for (flInt = 0; flInt < flBytesToWrite; flInt++)
        {
            flData = pData[flInt];
            SciDrv_Write_Reg32(flRegBase + UART_THR, (uint32) flData);
        }

        // Send back number of bytes actually written into Fifo
        *pLength = flBytesToWrite;

        flRetVal= E_OK;
    }

    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwCancelTransmit
**
** Visibility       :   Private
**
** Description      :   Cancelling Transmit
**
** Invocation       :   Static
**
** Inputs           :   const SSciDrvChnCfg *pChnCfg: SciDrv Hw Channel  
**
** Outputs          :   E_OK: Success
**                      
**
** Critical Section :   
**
**==========================================================================*/
static Std_ReturnType SciDrv_HwCancelTransmit( const SSciDrvChnCfg *pChnCfg )
{
    Std_ReturnType flRetVal = E_NOT_OK;

    // Disable Transmit Interrupt
    flRetVal = SciDrv_HwInterruptDisable(pChnCfg->SciDrvBaseAddr, SCIDRV_INTR_THR);
    
    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwCancelReceive
**
** Visibility       :   Private
**
** Description      :   Cancelling Receive
**
** Invocation       :   Static
**
** Inputs           :   const SSciDrvChnCfg *pChnCfg: SciDrv Hw Channel  
**
** Outputs          :   E_OK: Success
**                      
**
** Critical Section :   
**
**==========================================================================*/
static Std_ReturnType SciDrv_HwCancelReceive( const SSciDrvChnCfg *pChnCfg )
{
    Std_ReturnType flRetVal = E_NOT_OK;

    // Disable Transmit Interrupt
    flRetVal = SciDrv_HwInterruptDisable(pChnCfg->SciDrvBaseAddr, SCIDRV_INTR_RHR_CTI | SCIDRV_INTR_LINE_STAT);
    
    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwGetSwChnID
**
** Visibility       :   Private
**
** Description      :   Get the Sw ID for Hw Channel
**
** Invocation       :   Static
**
** Inputs           :   TSciDrvChn SciDrvHwChn: SciDrv Hw Channel  
**
** Outputs          :   SciDrvSwChn: Sw Channel
**                      
**
** Critical Section :   
**
**==========================================================================*/
static uint8 SciDrv_HwGetSwChnID( TSciDrvChn SciDrvHwChn )
{
    uint8 SciDrvSwChn;

    // Find the HW - SW Channel Mapping
    for (SciDrvSwChn = 0; SciDrvSwChn < SCIDRV_MAX_CHANNELS; SciDrvSwChn++)
    {
        if (SciDrvHwChn == SciDrvGlobal.pSciDrvConfig->pSciDrvChnCfg[SciDrvSwChn].SciDrvHwChnId)
        {
            break;
        }
    }
    return SciDrvSwChn;
}

/*============================================================================
**
** Function Name    :   SciDrv_ReceiveErrorRecovery
**
** Visibility       :   Private
**
** Description      :   Get the Sw ID for Hw Channel
**
** Invocation       :   Static
**
** Inputs           :   const SSciDrvChnCfg *pChnCfg: Configuration Structure  
**
** Outputs          :   None
**                      
**
** Critical Section :   
**
**==========================================================================*/
static void SciDrv_ReceiveErrorRecovery( const SSciDrvChnCfg *pChnCfg )
{
    uint32 flRegBase;
    uint32 flLcrRegValue;
    uint32 flDivLatchRegVal;
    uint32 flEnhanceBitVal;

    flRegBase = pChnCfg->SciDrvBaseAddr;

    if(0u != flRegBase)
    {
        (void)SciDrv_HwDisableReceiveInterrupt(pChnCfg);

        //Switching to Register Configuration Mose A of operation
        flLcrRegValue = SciDrv_HwEnableRegisterConfigMode(flRegBase, SCIDRV_REG_CONFIG_MODE_A);

        //Clearning the contects of Divisor Latch Register
        flDivLatchRegVal = SciDrv_HwWriteDivisorLatch(flRegBase, 0x0000u);

        //Set EFR[4] bit to 1
        flEnhanceBitVal = SciDrv_HwEnableEnhaceFunc(flRegBase);

        //Reseting the Receive Fifo
        SciDrv_Write_Field32(flRegBase + UART_FCR, UART_FCR_RX_FIFO_CLEAR_MASK, UART_FCR_RX_FIFO_CLEAR_SHIFT, UART_FCR_RX_FIFO_CLEAR_RX_FIFO_CLEAR_VALUE_1);

        //Restoring the EFR[4] bit 
        SciDrv_HwEnhanFuncBitValRestore(flRegBase, flEnhanceBitVal);

        //Restoring the Divisor Latch with original value
        (void)SciDrv_HwWriteDivisorLatch(flRegBase, flDivLatchRegVal);

        //Restoring LCR with its original value
        SciDrv_Write_Reg32(flRegBase + UART_LCR, flLcrRegValue);    
    }

}

/*****************************************************************************
*                            Low Level Driver Function                       *
******************************************************************************/
/*============================================================================
**
** Function Name    :   SciDrv_ResetModule
**
** Visibility       :   Private
**
** Description      :   This resets the SciDrv Module and other functionality not needed, before enabling the UART Channel.
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Regiater address of Enabled Channel
**
** Outputs          :   None
**
** Critical Section :   
**
**==========================================================================*/

static void SciDrv_ResetModule(uint32 pRegBase)
{
	uint32 flLineResetValue;
	uint32 flMcrResetValue;
	
	flLineResetValue = 0x00U;
	flMcrResetValue = 0U;
	
	/* Set the ENHANCEEN bit field */
    (void)SciDrv_HwEnableEnhaceFunc (pRegBase);
	
	/* Programming the Line Control Register(LCR). LCR[6] to zero to avoid UART breaks */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, flLineResetValue);
	
	/* Modem Control Reset */
	 (void)SciDrv_Write_Reg32(pRegBase + UART_MCR, flMcrResetValue);
	
	/* Disable all interrupts */
    (void)SciDrv_HwInterruptDisable(pRegBase, 0xFFU);
    (void)SciDrv_HwInterrupt2Disable(pRegBase, SCIDRV_INTR2_TX_EMPTY);

    /* Disable the module State */
    (void)SciDrv_HwOperatingModeSelect(pRegBase, SCIDRV_OPER_MODE_DISABLED);

    /* Reset Uart and setup hardware params */
    SciDrv_HwModuleReset(pRegBase);

}

/*============================================================================
**
** Function Name    :   SciDrv_HwEnableEnhaceFunc
**
** Visibility       :   Private
**
** Description      :   This enables the EFR Register.
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**
** Outputs          :   pEnhanceBitVal: Restored value of EFR before enabling EFR
**
** Critical Section :   
**
**==========================================================================*/

static uint32 SciDrv_HwEnableEnhaceFunc (uint32 pRegBase)
{
	uint32 flEnhanceBitVal;
    uint32 flRegValue;

    /* Enabling Configuration Mode B of operation. */
    flRegValue = SciDrv_HwEnableRegisterConfigMode(pRegBase, SCIDRV_REG_CONFIG_MODE_B);

    /* Collecting the current value of ENHANCEDEN bit of EFR. */
    flEnhanceBitVal = SciDrv_Read_Reg32(pRegBase + UART_EFR) & UART_EFR_ENHANCED_EN_MASK;

    /* Setting the ENHANCEDEN bit in EFR register. */
    SciDrv_Write_Field32(pRegBase + UART_EFR, UART_EFR_ENHANCED_EN_MASK, UART_EFR_ENHANCED_EN_SHIFT,
                  UART_EFR_ENHANCED_EN_ENHANCED_EN_U_VALUE_1);

    /* Programming LCR with the collected value. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, flRegValue);

    return flEnhanceBitVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwModuleReset
**
** Visibility       :   Private
**
** Description      :   This resets the SciDrv Module .
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**
** Outputs          :   
**
** Critical Section :   
**
**==========================================================================*/
static void SciDrv_HwModuleReset(uint32 pRegBase)
{
    /* Performing Software Reset of the module. */
    SciDrv_Write_Field32(pRegBase + UART_SYSC, UART_SYSC_SOFTRESET_MASK, UART_SYSC_SOFTRESET_SHIFT,
                  UART_SYSC_SOFTRESET_SOFTRESET_VALUE_1);

    /* Wait until the process of Module Reset is complete. */
    while (0U == SciDrv_Read_Field32(pRegBase + UART_SYSS, UART_SYSS_RESETDONE_MASK, UART_SYSS_RESETDONE_SHIFT))
    {
        /* Do nothing - Busy wait */
    }
}

/*============================================================================
**
** Function Name    :   SciDrv_HwInterruptEnable
**
** Visibility       :   Private
**
** Description      :   Hardware Interrupt Enable (UART_IER_UART).
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**                      uint32 pInterruptFlag: SCIDRV_INTR_LINE_STAT, SCIDRV_INTR_THR, SCIDRV_INTR_RHR
**
** Outputs          :   
**
** Critical Section :   
**
**==========================================================================*/
static Std_ReturnType SciDrv_HwInterruptEnable(uint32 pRegBase, uint32 pInterruptFlag)
{
	uint32 pEnhanFnBitVal = 0U;
    uint32 pLcrRegValue   = 0U;
    Std_ReturnType flRetVal;

    /* Switch to mode B only when the upper 4 bits of IER needs to be changed */
    if ((pInterruptFlag & 0xF0U) > 0U)
    {
        /* Preserving the current value of LCR. */
        pLcrRegValue = SciDrv_Read_Reg32(pRegBase + UART_LCR);
        /* Switching to Register Configuration Mode B. */
        SciDrv_Write_Reg32(pRegBase + UART_LCR, SCIDRV_REG_CONFIG_MODE_B & 0xFFU);

        /* Collecting the current value of EFR[4] and later setting it. */
        pEnhanFnBitVal = SciDrv_Read_Field32(pRegBase + UART_EFR, UART_EFR_ENHANCED_EN_MASK, UART_EFR_ENHANCED_EN_SHIFT);

        SciDrv_Write_Field32(pRegBase + UART_EFR, UART_EFR_ENHANCED_EN_MASK, UART_EFR_ENHANCED_EN_SHIFT,
                      UART_EFR_ENHANCED_EN_ENHANCED_EN_U_VALUE_1);

        /* Restoring the value of LCR. */
        SciDrv_Write_Reg32(pRegBase + UART_LCR, pLcrRegValue);

        /* Preserving the current value of LCR. */
        pLcrRegValue = SciDrv_Read_Reg32(pRegBase + UART_LCR);

        /* Switching to Register Operational Mode of operation. */
        SciDrv_Write_Reg32(pRegBase + UART_LCR, SciDrv_Read_Reg32(pRegBase + UART_LCR)
                                & 0x7FU);

        
		
        /* Programming the bits IER[7:4]. */
        SciDrv_Write_Reg32(pRegBase + UART_IER_UART, pInterruptFlag & 0xF0U);

        /* Restoring the value of LCR. */
        SciDrv_Write_Reg32(pRegBase + UART_LCR, pLcrRegValue);

        /* Preserving the current value of LCR. */
        pLcrRegValue = SciDrv_Read_Reg32(pRegBase + UART_LCR);
        /* Switching to Register Configuration Mode B. */
        SciDrv_Write_Reg32(pRegBase + UART_LCR, SCIDRV_REG_CONFIG_MODE_B & 0xFFU);

        /* Restoring the value of EFR[4] to its original value. */
        SciDrv_Write_Field32(pRegBase + UART_EFR, UART_EFR_ENHANCED_EN_MASK, UART_EFR_ENHANCED_EN_SHIFT, pEnhanFnBitVal);

        /* Restoring the value of LCR. */
        SciDrv_Write_Reg32(pRegBase + UART_LCR, pLcrRegValue);

       
    }

    /* Programming the bits IER[3:0]. */
    SciDrv_Write_Reg32(pRegBase + UART_IER_UART, SciDrv_Read_Reg32(pRegBase + UART_IER_UART) |
                (pInterruptFlag & 0x0FU));

    flRetVal= E_OK;

    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwInterruptDisable
**
** Visibility       :   Private
**
** Description      :   Hardware Interrupt Disable (UART_IER_UART).
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**                      uint32 pInterruptFlag: SCIDRV_INTR_LINE_STAT, SCIDRV_INTR_THR, SCIDRV_INTR_RHR
**
** Outputs          :   
**
** Critical Section :   
**
**==========================================================================*/
static Std_ReturnType SciDrv_HwInterruptDisable(uint32 pRegBase, uint32 pInterruptFlag)
{
	uint32 flEnhanceBitVal;
    uint32 flRegValue;
    Std_ReturnType flRetVal;

    /* Switch to mode B only when the upper 4 bits of IER needs to be changed */
    if((pInterruptFlag & 0xF0U) > 0U)
    {
        /* Preserving the current value of LCR. */
        flRegValue = SciDrv_Read_Reg32(pRegBase + UART_LCR);
        /* Switching to Register Configuration Mode B. */
        SciDrv_Write_Reg32(pRegBase + UART_LCR, SCIDRV_REG_CONFIG_MODE_B & 0xFFU);

        /* Collecting the current value of EFR[4] and later setting it. */
        flEnhanceBitVal = SciDrv_Read_Field32(pRegBase + UART_EFR, UART_EFR_ENHANCED_EN_MASK, UART_EFR_ENHANCED_EN_SHIFT);

        SciDrv_Write_Field32(pRegBase + UART_EFR, UART_EFR_ENHANCED_EN_MASK, UART_EFR_ENHANCED_EN_SHIFT,
                      UART_EFR_ENHANCED_EN_ENHANCED_EN_U_VALUE_1);

        /* Restoring the value of LCR. */
        SciDrv_Write_Reg32(pRegBase + UART_LCR, flRegValue);
    }

    /* Preserving the current value of LCR. */
    flRegValue = SciDrv_Read_Reg32(pRegBase + UART_LCR);

    /* Switching to Register Operational Mode of operation. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, SciDrv_Read_Reg32(pRegBase + UART_LCR)
                            & 0x7FU);

    SciDrv_Write_Reg32(pRegBase + UART_IER_UART, SciDrv_Read_Reg32(pRegBase + UART_IER_UART) &
                ~(pInterruptFlag & 0xFFU));

    /* Restoring the value of LCR. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, flRegValue);

    /* Switch to mode B only when the upper 4 bits of IER needs to be changed */
    if((pInterruptFlag & 0xF0U) > 0U)
    {
        /* Preserving the current value of LCR. */
        flRegValue = SciDrv_Read_Reg32(pRegBase + UART_LCR);
        /* Switching to Register Configuration Mode B. */
        SciDrv_Write_Reg32(pRegBase + UART_LCR, SCIDRV_REG_CONFIG_MODE_B & 0xFFU);

        /* Restoring the value of EFR[4] to its original value. */
        SciDrv_Write_Field32(pRegBase + UART_EFR, UART_EFR_ENHANCED_EN_MASK, UART_EFR_ENHANCED_EN_SHIFT, flEnhanceBitVal);

        /* Restoring the value of LCR. */
        SciDrv_Write_Reg32(pRegBase + UART_LCR, flRegValue);
    }

    flRetVal= E_OK;

    return flRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwInterrupt2Enable
**
** Visibility       :   Private
**
** Description      :   Hardware Interrupt2 Enable(UART_IER2) .
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**                      uint32 pInterruptFlag: SCIDRV_INTR2_RX_EMPTY, SCIDRV_INTR2_TX_EMPTY
**
** Outputs          :   
**
** Critical Section :   
**
**==========================================================================*/
static void SciDrv_HwInterrupt2Enable(uint32 pRegBase, uint32 pInterruptFlag)
{
	//IER[1:0]
	SciDrv_Write_Reg32(pRegBase + UART_IER2, SciDrv_Read_Reg32(pRegBase + UART_IER2) |
                (pInterruptFlag & 0x03U));
}

/*============================================================================
**
** Function Name    :   SciDrv_HwInterrupt2Disable
**
** Visibility       :   Private
**
** Description      :   Hardware Interrupt2 Enable(UART_IER2) .
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**                      uint32 pInterruptFlag: SCIDRV_INTR2_RX_EMPTY, SCIDRV_INTR2_TX_EMPTY
**
** Outputs          :   
**
** Critical Section :   
**
**==========================================================================*/
static void SciDrv_HwInterrupt2Disable(uint32 pRegBase, uint32 pInterruptFlag)
{
    SciDrv_Write_Reg32(pRegBase + UART_IER2, SciDrv_Read_Reg32(pRegBase + UART_IER2) &
                ~(pInterruptFlag & 0x3U));
}

/*============================================================================
**
** Function Name    :   SciDrv_HwLineCharConfig
**
** Visibility       :   Private
**
** Description      :   COnfiguration of Line Characteristics as per the configuration.
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**                      uint32 pLengthFlag: Length and StopBit
**                      uint32 pParityFlag: Parity 
**
** Outputs          :   
**
** Critical Section :   
**
**==========================================================================*/
static void SciDrv_HwLineCharConfig (uint32 pRegBase, uint32 pLengthFlag, uint32 pParityFlag)
 {
	uint32 flRegValue;

    flRegValue = SciDrv_Read_Reg32(pRegBase + UART_LCR);
	
    /* Clearing the CHAR_LENGTH and NB_STOP fields in LCR.*/
    flRegValue &= ~((uint32) UART_LCR_NB_STOP_MASK | (uint32) UART_LCR_CHAR_LENGTH_MASK);

    /* Setting Data Length and Parity in LCR */
    flRegValue |= pLengthFlag & (UART_LCR_NB_STOP_MASK |
                                  UART_LCR_CHAR_LENGTH_MASK);

    /* Clearing the PARITY_EN, PARITY_TYPE1 and PARITY_TYPE2 fields in LCR. */
    flRegValue &= ~((uint32) UART_LCR_PARITY_TYPE2_MASK |
                     (uint32) UART_LCR_PARITY_TYPE1_MASK |
                     (uint32) UART_LCR_PARITY_EN_MASK);

    /* Setting the PARITY_EN, PARITY_TYPE1 and PARITY_TYPE2 fields in LCR.*/
    flRegValue |= pParityFlag & (UART_LCR_PARITY_TYPE2_MASK |
                                 UART_LCR_PARITY_TYPE1_MASK |
                                 UART_LCR_PARITY_EN_MASK);
    SciDrv_Write_Reg32(pRegBase + UART_LCR, flRegValue); 	
 }
 
 /*============================================================================
**
** Function Name    :   SciDrv_HwOperatingModeSelect
**
** Visibility       :   Private
**
** Description      :   Configure the Operating Mode
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**                      uint32 pModeFlag: 16x, 13x, Disable
**
** Outputs          :   Restores the old value of UART_LCR before setting the operational mode.
**
** Critical Section :   
**
**==========================================================================*/
 static uint32 SciDrv_HwOperatingModeSelect(uint32 pRegBase, uint32 pModeFlag)
 {
	 uint32 flOperationalMode;

    flOperationalMode = SciDrv_Read_Reg32(pRegBase + UART_MDR1) & UART_MDR1_MODE_SELECT_MASK;

    /* Setting the MODESELECT field in MDR1. */
    SciDrv_Write_Field32(pRegBase + UART_MDR1, UART_MDR1_MODE_SELECT_MASK, UART_MDR1_MODE_SELECT_SHIFT,
                  pModeFlag >> UART_MDR1_MODE_SELECT_SHIFT);

    return flOperationalMode;
 }
 
 /*============================================================================
**
** Function Name    :   SciDrv_HwBreakControl
**
** Visibility       :   Private
**
** Description      :   Enable or Disable Break Control
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**                      uint32 pbreakState: SCIDRV_BREAK_COND_DISABLE, SCIDRV_BREAK_COND_ENABLE
**
** Outputs          :   
**
** Critical Section :   
**
**==========================================================================*/

 static void SciDrv_HwBreakControl(uint32 pRegBase, uint32 pbreakState)
 {
	 /* Setting the BREAK_EN bit in LCR. */
    SciDrv_Write_Field32(pRegBase + UART_LCR, UART_LCR_BREAK_EN_MASK, UART_LCR_BREAK_EN_SHIFT,
                  pbreakState >> UART_LCR_BREAK_EN_SHIFT);
 }
 
 /*============================================================================
**
** Function Name    :   SciDrv_HwEnableRegisterConfigMode
**
** Visibility       :   Private
**
** Description      :   Configure the Register Mode
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**                      uint32 SciDrv_HwEnableRegisterConfigMode: SCIDRV_REG_OPERATIONAL_MODE, SCIDRV_REG_CONFIG_MODE_A, SCIDRV_CONFIG_MODE_B
**
** Outputs          :   Restores the previous value of the UART_LCR Register. 
**
** Critical Section :   
**
**==========================================================================*/
 static uint32 SciDrv_HwEnableRegisterConfigMode(uint32 pRegBase, uint32 pRegisterModeFlag)
 {
	 uint32 flRegValue;
	 
	 /* Storing the current value of LCR. */
    flRegValue = SciDrv_Read_Reg32(pRegBase + UART_LCR);

    switch (pRegisterModeFlag)
    {
        case SCIDRV_REG_CONFIG_MODE_A:
			SciDrv_Write_Reg32(pRegBase + UART_LCR, pRegisterModeFlag & 0xFFU);
			break;
			
        case SCIDRV_REG_CONFIG_MODE_B:
            SciDrv_Write_Reg32(pRegBase + UART_LCR, pRegisterModeFlag & 0xFFU);
            break;

        case SCIDRV_REG_OPERATIONAL_MODE:
            SciDrv_Write_Reg32(pRegBase + UART_LCR, flRegValue & 0x7FU);
            break;

        default:
            break;
    }

    return flRegValue;
 }
 
/*============================================================================
**
** Function Name    :   SciDrv_ComputeDivisorValue
**
** Visibility       :   Private
**
** Description      :   Computing values for DLL and DLH based on BaudRate
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**                      uint32 pBaudRate: Configure BaudRate 
**                      uint32 pModeFlag: Configure Operational Mode 
**
** Outputs          :   
**
** Critical Section :   
**
**==========================================================================*/
static uint32 SciDrv_ComputeDivisorValue(uint32 pModuleClk, uint32 pBaudRate, uint32 pModeFlag)
{
	uint32 fldivisorValue = 0U;
    uint32 flModeFlagTemp = pModeFlag & UART_MDR1_MODE_SELECT_MASK;

    switch (flModeFlagTemp)
    {
        case SCIDRV_OPER_MODE_16X:
            fldivisorValue = SciDrv_DivideRoundCloset(pModuleClk, 16U * pBaudRate);
            break;

        case SCIDRV_OPER_MODE_13X:
            fldivisorValue = SciDrv_DivideRoundCloset(pModuleClk, 13U * pBaudRate);
            break;

        default:
            break;
    }

    return fldivisorValue;
}

/*============================================================================
**
** Function Name    :   SciDrv_DivideRoundCloset
**
** Visibility       :   Private
**
** Description      :   Calculation of Divisor Value
**
** Invocation       :   Static
**
** Inputs           :   uint32 pdivident: Module CLock
**                      uint32 pdivisor: BaudRate * Operation mode value (16 or 13)  
**
** Outputs          :   Returns Quotient
**
** Critical Section :   
**
**==========================================================================*/
static uint32 SciDrv_DivideRoundCloset(uint32 pdivident, uint32 pdivisor)
{
    return (pdivident/pdivisor);
}

/*============================================================================
**
** Function Name    :   SciDrv_HwWriteDivisorLatch
**
** Visibility       :   Private
**
** Description      :   Writing DLL and DLH value
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**                      uint32 pdivisorValue: Calculated value DLH and DLL in decimal  
**
** Outputs          :   Restores previous value of DLL and DLH
**
** Critical Section :   
**
**==========================================================================*/
static uint32 SciDrv_HwWriteDivisorLatch(uint32 pRegBase, uint32 pdivisorValue)
 {
	volatile uint32 flEnhanceBitVal;
    volatile uint32 flSleepBitVal;
    volatile uint32 flRegValue;
    volatile uint32 flOperationalMode;
    uint32          fldivRegVal;

    /* DLL and DLH registers are accessable in Register Configuration Mode B */
    flRegValue = SciDrv_HwEnableRegisterConfigMode(pRegBase, SCIDRV_REG_CONFIG_MODE_A);

    /* Collecting the current value of EFR[4] and later setting it. DLL and DLH can be accessed when EFR[4] is set */
    flEnhanceBitVal = SciDrv_Read_Field32(pRegBase + UART_EFR, UART_EFR_ENHANCED_EN_MASK, UART_EFR_ENHANCED_EN_SHIFT);
    SciDrv_Write_Field32(pRegBase + UART_EFR, UART_EFR_ENHANCED_EN_MASK, UART_EFR_ENHANCED_EN_SHIFT,
                  UART_EFR_ENHANCED_EN_ENHANCED_EN_U_VALUE_1);

    /* Restoring the value of LCR. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, flRegValue);

    /* Switching to Register Operational Mode and can access IER in Operational Mode */
    flRegValue = SciDrv_HwEnableRegisterConfigMode(pRegBase, SCIDRV_REG_OPERATIONAL_MODE);

    /*Collecting the current value of IER[4](SLEEPMODE bit) and later clearing it.*/
    flSleepBitVal = SciDrv_Read_Field32(pRegBase + UART_IER_UART, UART_IER_UART_SLEEP_MODE_MASK, UART_IER_UART_SLEEP_MODE_SHIFT);

    SciDrv_Write_Field32(pRegBase + UART_IER_UART, UART_IER_UART_SLEEP_MODE_MASK, UART_IER_UART_SLEEP_MODE_SHIFT, 0U);

    /* Restoring the value of LCR. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, flRegValue);

    /* Switching to Register Configuration Mode B. */
    flRegValue = SciDrv_HwEnableRegisterConfigMode(pRegBase, SCIDRV_REG_CONFIG_MODE_A);

    /* Collecting the current value of Divisor Latch Registers. */
    fldivRegVal  = SciDrv_Read_Reg32(pRegBase + UART_DLL) & 0xFFU;
    fldivRegVal |= (SciDrv_Read_Reg32(pRegBase + UART_DLH) & 0x3FU) << 8U;

    /* Switch the UART instance to Disabled state. */
    flOperationalMode = SciDrv_HwEnableRegisterConfigMode(pRegBase,
                                       (uint32) UART_MDR1_MODE_SELECT_MASK);

    /* Writing to Divisor Latch Low(DLL) register. */
    SciDrv_Write_Reg32(pRegBase + UART_DLL, pdivisorValue & 0x00FFU);

    /* Writing to Divisor Latch High(DLH) register. */
    SciDrv_Write_Reg32(pRegBase + UART_DLH, (pdivisorValue & 0x3F00U) >> 8U);

    /* Restoring the Operating Mode of UART. */
    (void) SciDrv_HwEnableRegisterConfigMode(pRegBase, flOperationalMode);

    /* Restoring the value of LCR. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, flRegValue);

    /* Switching to Register Operational Mode. */
    flRegValue = SciDrv_HwEnableRegisterConfigMode(pRegBase, SCIDRV_REG_OPERATIONAL_MODE);

    /* Restoring the value of IER[4] to its original value. */
    SciDrv_Write_Field32(pRegBase + UART_IER_UART, UART_IER_UART_SLEEP_MODE_MASK, UART_IER_UART_SLEEP_MODE_SHIFT, flSleepBitVal);

    /* Restoring the value of LCR. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, flRegValue);

    /* Switching to Register Configuration Mode B. */
    flRegValue = SciDrv_HwEnableRegisterConfigMode(pRegBase, SCIDRV_REG_CONFIG_MODE_B);

    /* Restoring the value of EFR[4] to its original value. */
    SciDrv_Write_Field32(pRegBase + UART_EFR, UART_EFR_ENHANCED_EN_MASK, UART_EFR_ENHANCED_EN_SHIFT, flEnhanceBitVal);

    /* Restoring the value of LCR Register. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, flRegValue);

    return fldivRegVal;
 }
 
/*============================================================================
**
** Function Name    :   SciDrv_DisableDivisorLatch
**
** Visibility       :   Private
**
** Description      :   Disabling DLL and DLH register
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**                      uint32 pdivisorValue: Calculated value DLH and DLL in decimal  
**
** Outputs          :   Restores previous value of DLL and DLH
**
** Critical Section :   
**
**==========================================================================*/
static void SciDrv_DisableDivisorLatch (uint32 pRegBase)
{
	 // Disabling the DIV_EN bit for normal operating Condition
	 SciDrv_Write_Field32(pRegBase + UART_LCR, UART_LCR_DIV_EN_MASK, UART_LCR_DIV_EN_SHIFT,
                  UART_LCR_DIV_EN_DIV_EN_VALUE_0);
 
}

/*============================================================================
**
** Function Name    :   SciDrv_HwFifoConfig
**
** Visibility       :   Private
**
** Description      :   Triggering Setting for Rx and Tx FIFO
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**                      uint32 pFifoConfig: Config values for FCR, SCR and TCR Register  
**
** Outputs          :   Returns FCR register value that needs to be set.
**
** Critical Section :   
**
**==========================================================================*/
static uint32 SciDrv_HwFifoConfig(uint32 pRegBase, uint32 pFifoConfig)
{
    uint32 flEnhanceBitVal;
    uint32 flTcrTlrBitVal;
    uint32 flTlrValue;
    uint32 flFcrValue = 0U;
    uint32 flTxGra = (pFifoConfig & SCIDRV_FIFO_CONFIG_TXGRA) >> 26U;
    uint32 flRxGra = (pFifoConfig & SCIDRV_FIFO_CONFIG_RXGRA) >> 22U;
    uint32 flTxTrig = (pFifoConfig & SCIDRV_FIFO_CONFIG_pTxTrig) >> 14U;
    uint32 flRxTrig = (pFifoConfig & SCIDRV_FIFO_CONFIG_pRxTrig) >> 6U;
    uint32 flTxClr = (pFifoConfig & SCIDRV_FIFO_CONFIG_TXCLR) >> 5U;
    uint32 flRxClr = (pFifoConfig & SCIDRV_FIFO_CONFIG_RXCLR) >> 4U;

    uint32 flDmaEnPath = (pFifoConfig & SCIDRV_FIFO_CONFIG_DMAENPATH) >> 3U;
    uint32 flDmaMode   = (pFifoConfig & SCIDRV_FIFO_CONFIG_DMAMODE);

    /* Setting the EFR[4] bit to 1. */
    flEnhanceBitVal = SciDrv_HwEnableEnhaceFunc(pRegBase);

    flTcrTlrBitVal = SciDrv_HwSubConfigTCRTLRModeEn(pRegBase);

    /* Enable FIFO */
    flFcrValue |= UART_FCR_FIFO_EN_MASK;

    /* Setting the Receiver FIFO trigger level. */
    if(SCIDRV_TRIG_LVL_GRANULARITY_1 != flRxGra)
    {
        /* Clearing the RxTrigGRANU1 bit in SCR. */
        SciDrv_Write_Field32(pRegBase + UART_SCR, UART_SCR_RX_TRIG_GRANU1_MASK, UART_SCR_RX_TRIG_GRANU1_SHIFT, 
                      UART_SCR_RX_TRIG_GRANU1_RX_TRIG_GRANU1_VALUE_0);

        /* Clearing the RX_FIFO_TRIG_DMA field of TLR register. */
        SciDrv_Write_Field32(pRegBase + UART_TLR, UART_TLR_RX_FIFO_TRIG_DMA_MASK, UART_TLR_RX_FIFO_TRIG_DMA_SHIFT,
                      0U);

        flFcrValue &= ~((uint32) UART_FCR_RX_FIFO_TRIG_MASK);

        /*
        ** Checking if 'flRxTrig' matches with the RX Trigger level values
        ** in FCR.
        */
        if(SCIDRV_RXTRIGLVL_8 == flRxTrig)
        {
            flFcrValue |= (UART_FCR_RX_FIFO_TRIG_VALUE_0 << UART_FCR_RX_FIFO_TRIG_SHIFT)& UART_FCR_RX_FIFO_TRIG_MASK;
        }
        else if (SCIDRV_RXTRIGLVL_16 == flRxTrig)
        {
            flFcrValue |= (UART_FCR_RX_FIFO_TRIG_VALUE_1 << UART_FCR_RX_FIFO_TRIG_SHIFT)& UART_FCR_RX_FIFO_TRIG_MASK;
        }
        else if (SCIDRV_RXTRIGLVL_56 == flRxTrig)
        {
            flFcrValue |= (UART_FCR_RX_FIFO_TRIG_VALUE_2 << UART_FCR_RX_FIFO_TRIG_SHIFT)& UART_FCR_RX_FIFO_TRIG_MASK;
        }
        else if (SCIDRV_RXTRIGLVL_60 == flRxTrig)
        {
            flFcrValue |= (UART_FCR_RX_FIFO_TRIG_VALUE_3 << UART_FCR_RX_FIFO_TRIG_SHIFT)& UART_FCR_RX_FIFO_TRIG_MASK;
        }
        else
        {
            /* RX Trigger level will be a multiple of 4. */
            /* Programming the RX_FIFO_TRIG_DMA field of TLR register. */
            SciDrv_Write_Field32(pRegBase + UART_TLR, UART_TLR_RX_FIFO_TRIG_DMA_MASK, UART_TLR_RX_FIFO_TRIG_DMA_SHIFT,
                          flRxTrig);
        }
    }
    else
    {
        /* 'RxTrig' now has the 6-bit RX Trigger level value. */

        flRxTrig &= 0x003FU;

        /* Collecting the bits flRxTrig[5:2]. */
        flTlrValue = (flRxTrig & 0x003CU) >> 2U;

        /* Collecting the bits flRxTrig[1:0] and writing to 'flFcrValue'. */
        flFcrValue |= (flRxTrig & 0x0003U) << UART_FCR_RX_FIFO_TRIG_SHIFT;

        /* Setting the RxTrigGRANU1 bit of SCR register. */
        SciDrv_Write_Field32(pRegBase + UART_SCR, UART_SCR_RX_TRIG_GRANU1_MASK, UART_SCR_RX_TRIG_GRANU1_SHIFT,
                      UART_SCR_RX_TRIG_GRANU1_RX_TRIG_GRANU1_VALUE_1);

        /* Programming the RX_FIFO_TRIG_DMA field of TLR register. */
        SciDrv_Write_Field32(pRegBase + UART_TLR, UART_TLR_RX_FIFO_TRIG_DMA_MASK, UART_TLR_RX_FIFO_TRIG_DMA_SHIFT, flTlrValue);
    }

    /* Setting the Transmitter FIFO trigger level. */
    if(SCIDRV_TRIG_LVL_GRANULARITY_1 != flTxGra)
    {
        /* Clearing the TxTrigGRANU1 bit in SCR. */
        SciDrv_Write_Field32(pRegBase + UART_SCR, UART_SCR_TX_TRIG_GRANU1_MASK, UART_SCR_TX_TRIG_GRANU1_SHIFT,
                      UART_SCR_TX_TRIG_GRANU1_TX_TRIG_GRANU1_VALUE_0);

        /* Clearing the TX_FIFO_TRIG_DMA field of TLR register. */
        SciDrv_Write_Field32(pRegBase + UART_TLR, UART_TLR_TX_FIFO_TRIG_DMA_MASK, UART_TLR_TX_FIFO_TRIG_DMA_SHIFT,
                      0U);

        flFcrValue &= ~((uint32) UART_FCR_TX_FIFO_TRIG_MASK);

        /*
        ** Checking if 'flTxTrig' matches with the TX Trigger level values
        ** in FCR.
        */
        if(SCIDRV_TXTRIGLVL_8 == flTxTrig)
        {
            flFcrValue |= (UART_FCR_TX_FIFO_TRIG_VALUE_0 << UART_FCR_TX_FIFO_TRIG_SHIFT)& UART_FCR_TX_FIFO_TRIG_MASK;
        }
        else if (SCIDRV_TXTRIGLVL_16 == flTxTrig)
        {
            flFcrValue |= (UART_FCR_TX_FIFO_TRIG_VALUE_1 << UART_FCR_TX_FIFO_TRIG_SHIFT)& UART_FCR_TX_FIFO_TRIG_MASK;
        }
        else if (SCIDRV_TXTRIGLVL_32 == flTxTrig)
        {
            flFcrValue |= (UART_FCR_TX_FIFO_TRIG_VALUE_2 << UART_FCR_TX_FIFO_TRIG_SHIFT)& UART_FCR_TX_FIFO_TRIG_MASK;
        }
        else if (SCIDRV_TXTRIGLVL_56 == flTxTrig)
        {
            flFcrValue |= (UART_FCR_TX_FIFO_TRIG_VALUE_3 << UART_FCR_TX_FIFO_TRIG_SHIFT)& UART_FCR_TX_FIFO_TRIG_MASK;
        }
        else
        {
            /* TX Trigger level will be a multiple of 4. */
            /* Programming the TX_FIFO_TRIG_DMA field of TLR register. */
            SciDrv_Write_Field32(pRegBase + UART_TLR, UART_TLR_TX_FIFO_TRIG_DMA_MASK, UART_TLR_TX_FIFO_TRIG_DMA_SHIFT,
                          flTxTrig);
        }
    }
    else
    {
        /* 'flTxTrig' now has the 6-bit TX Trigger level value. */

        flTxTrig &= 0x003FU;

        /* Collecting the bits flTxTrig[5:2]. */
        flTlrValue = (flTxTrig & 0x003CU) >> 2U;

        /* Collecting the bits TxTrig[1:0] and writing to 'flFcrValue'. */
        flFcrValue |= (flTxTrig & 0x0003U) << UART_FCR_TX_FIFO_TRIG_SHIFT;

        /* Setting the TxTrigGRANU1 bit of SCR register. */
        SciDrv_Write_Field32(pRegBase + UART_SCR, UART_SCR_TX_TRIG_GRANU1_MASK, UART_SCR_TX_TRIG_GRANU1_SHIFT,
                      UART_SCR_TX_TRIG_GRANU1_TX_TRIG_GRANU1_VALUE_1);

        /* Programming the TX_FIFO_TRIG_DMA field of TLR register. */
        SciDrv_Write_Field32(pRegBase + UART_TLR, UART_TLR_TX_FIFO_TRIG_DMA_MASK, UART_TLR_TX_FIFO_TRIG_DMA_SHIFT, flTlrValue);
    }

    if(SCIDRV_DMA_EN_PATH_FCR == flDmaEnPath)
    {
        /* Configuring the UART DMA Mode through FCR register. */
        SciDrv_Write_Field32(pRegBase + UART_SCR, UART_SCR_DMA_MODE_CTL_MASK, UART_SCR_DMA_MODE_CTL_SHIFT,
                      UART_SCR_DMA_MODE_CTL_DMA_MODE_CTL_VALUE_0);

        flDmaMode &= 0x1U;

        /* Clearing the bit corresponding to the DMA_MODE in 'flFcrValue'. */
        flFcrValue &= ~((uint32) UART_FCR_DMA_MODE_MASK);

        /* Setting the DMA Mode of operation. */
        flFcrValue |= flDmaMode << UART_FCR_DMA_MODE_SHIFT;
    }
    else
    {
        flDmaMode &= 0x3U;

        /* Configuring the UART DMA Mode through SCR register. */
        SciDrv_Write_Field32(pRegBase + UART_SCR, UART_SCR_DMA_MODE_CTL_MASK, UART_SCR_DMA_MODE_CTL_SHIFT,
                      UART_SCR_DMA_MODE_CTL_DMA_MODE_CTL_VALUE_1);

        /* Programming the DMAMODE2 field in SCR. */
        SciDrv_Write_Field32(pRegBase + UART_SCR, UART_SCR_DMA_MODE_2_MASK, UART_SCR_DMA_MODE_2_SHIFT, flDmaMode);
    }

    /* Programming the bits which clear the RX and TX FIFOs. */
    flFcrValue |= flRxClr << UART_FCR_RX_FIFO_CLEAR_SHIFT;
    flFcrValue |= flTxClr << UART_FCR_TX_FIFO_CLEAR_SHIFT;

    /* Writing 'flFcrValue' to the FIFO Control Register(FCR). */
    SciDrv_HwFifoRegisterWrite(pRegBase, flFcrValue);

    /* Restoring the value of TCRTLR bit in MCR. */
    SciDrv_HwTcrTlrBitValRestore(pRegBase, flTcrTlrBitVal);

    /* Restoring the value of EFR[4] to the original value. */
    SciDrv_HwEnhanFuncBitValRestore(pRegBase, flEnhanceBitVal);

    return flFcrValue;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwSubConfigTCRTLRModeEn
**
** Visibility       :   Private
**
** Description      :   Enabling TLR and TCR bit in MCR Register
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel 
**
** Outputs          :   Restores the previos value of MCR Register
**
** Critical Section :   
**
**==========================================================================*/
static uint32 SciDrv_HwSubConfigTCRTLRModeEn(uint32 pRegBase)
{
	uint32 flEnhanceBitVal;
    uint32 flTcrTlrValue;
    uint32 flLcrRegValue;

    /* Switching to Register Configuration Mode B. */
    flLcrRegValue = SciDrv_HwEnableRegisterConfigMode(pRegBase, SCIDRV_REG_CONFIG_MODE_B);

    /* Collecting the current value of EFR[4] and later setting it. */
    flEnhanceBitVal = SciDrv_Read_Field32(pRegBase + UART_EFR, UART_EFR_ENHANCED_EN_MASK, UART_EFR_ENHANCED_EN_SHIFT);

    SciDrv_Write_Field32(pRegBase + UART_EFR, UART_EFR_ENHANCED_EN_MASK, UART_EFR_ENHANCED_EN_SHIFT,
                  UART_EFR_ENHANCED_EN_ENHANCED_EN_U_VALUE_1);

    /* Restoring the value of LCR. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, flLcrRegValue);

    /* Switching to Register Configuration Mode A. */
    flLcrRegValue = SciDrv_HwEnableRegisterConfigMode(pRegBase, SCIDRV_REG_CONFIG_MODE_A);

    /* Collecting the bit value of MCR[6]. */
    flTcrTlrValue = SciDrv_Read_Reg32(pRegBase + UART_MCR) & UART_MCR_TCR_TLR_MASK;

    /* Setting the TCRTLR bit in Modem Control Register(MCR). */
    SciDrv_Write_Field32(pRegBase + UART_MCR, UART_MCR_TCR_TLR_MASK, UART_MCR_TCR_TLR_SHIFT,
                  UART_MCR_TCR_TLR_TCR_TLR_VALUE_1);

    /* Restoring the value of LCR. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, flLcrRegValue);

    /* Switching to Register Configuration Mode B. */
    flLcrRegValue = SciDrv_HwEnableRegisterConfigMode(pRegBase, SCIDRV_REG_CONFIG_MODE_B);

    /* Restoring the value of EFR[4] to its original value. */
    SciDrv_Write_Field32(pRegBase + UART_EFR, UART_EFR_ENHANCED_EN_MASK, UART_EFR_ENHANCED_EN_SHIFT, flEnhanceBitVal);

    /* Restoring the value of LCR. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, flLcrRegValue);

    return flTcrTlrValue;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwFifoRegisterWrite
**
** Visibility       :   Private
**
** Description      :   Writing the UART_FCR Register
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**                      uint32 pFcrValue: FCR Register Value  
**
** Outputs          :   
**
** Critical Section :   
**
**==========================================================================*/
static void SciDrv_HwFifoRegisterWrite(uint32 pRegBase, uint32 pFcrValue)
{
	uint32 flDivLatchRegVal;
    uint32 flEnhanFnBitVal;
    uint32 flLcrRegValue;

    /* Switching to Register Configuration Mode A of operation. */
    flLcrRegValue = SciDrv_HwEnableRegisterConfigMode(pRegBase, SCIDRV_REG_CONFIG_MODE_A);

    /* Clearing the contents of Divisor Latch Registers. */
    flDivLatchRegVal = SciDrv_HwWriteDivisorLatch(pRegBase, 0x0000U);

    /* Set the EFR[4] bit to 1. */
    flEnhanFnBitVal = SciDrv_HwEnableEnhaceFunc(pRegBase);

    /* Writing the 'pFcrValue' to the FCR register. */
    SciDrv_Write_Reg32(pRegBase + UART_FCR, pFcrValue);

    /* Restoring the value of EFR[4] to its original value. */
    SciDrv_HwEnhanFuncBitValRestore(pRegBase, flEnhanFnBitVal);

    /* Programming the Divisor Latch Registers with the collected value. */
    (void) SciDrv_HwWriteDivisorLatch(pRegBase, flDivLatchRegVal);

    /* Reinstating LCR with its original value. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, flLcrRegValue);
}

/*============================================================================
**
** Function Name    :   SciDrv_HwTcrTlrBitValRestore
**
** Visibility       :   Private
**
** Description      :   Restoring TCR and TLR 
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel 
**                      uint32 pTcrTlrBitVal: Value of TCR and TLR that to be restored
** Outputs          :  
**
** Critical Section :   
**
**==========================================================================*/
static void SciDrv_HwTcrTlrBitValRestore(uint32 pRegBase, uint32 pTcrTlrBitVal)
{
	uint32 flEnhanFnBitVal;
    uint32 flLcrRegValue;

    /* Switching to Register Configuration Mode B. */
    flLcrRegValue = SciDrv_HwEnableRegisterConfigMode(pRegBase, SCIDRV_REG_CONFIG_MODE_B);

    /* Collecting the current value of EFR[4] and later setting it. */
    flEnhanFnBitVal = SciDrv_Read_Field32(pRegBase + UART_EFR, UART_EFR_ENHANCED_EN_MASK, UART_EFR_ENHANCED_EN_SHIFT);

    SciDrv_Write_Field32(pRegBase + UART_EFR, UART_EFR_ENHANCED_EN_MASK, UART_EFR_ENHANCED_EN_SHIFT,
                  UART_EFR_ENHANCED_EN_ENHANCED_EN_U_VALUE_1);

    /* Restoring the value of LCR. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, flLcrRegValue);

    /* Switching to Configuration Mode A of operation. */
    flLcrRegValue = SciDrv_HwEnableRegisterConfigMode(pRegBase, SCIDRV_REG_CONFIG_MODE_A);

    /* Programming MCR[6] with the corresponding bit value in 'tcrTlrBitVal'. */
    SciDrv_Write_Field32(pRegBase + UART_MCR, UART_MCR_TCR_TLR_MASK, UART_MCR_TCR_TLR_SHIFT, pTcrTlrBitVal);

    /* Restoring the value of LCR. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, flLcrRegValue);

    /* Switching to Register Configuration Mode B. */
    flLcrRegValue = SciDrv_HwEnableRegisterConfigMode(pRegBase, SCIDRV_REG_CONFIG_MODE_B);

    /* Restoring the value of EFR[4] to its original value. */
    SciDrv_Write_Field32(pRegBase + UART_EFR, UART_EFR_ENHANCED_EN_MASK, UART_EFR_ENHANCED_EN_SHIFT, flEnhanFnBitVal);

    /* Restoring the value of LCR. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, flLcrRegValue);
}

/*============================================================================
**
** Function Name    :   SciDrv_HwEnhanFuncBitValRestore
**
** Visibility       :   Private
**
** Description      :   Restoring EFR Register 
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel 
**                      uint32 pEnhanFnBitVal: Value of EFR that to be restored
** Outputs          :  
**
** Critical Section :   
**
**==========================================================================*/
static void SciDrv_HwEnhanFuncBitValRestore(uint32 pRegBase, uint32 pEnhanFnBitVal)
{
    uint32 flLcrRegValue;

    /* Enabling Configuration Mode B of operation. */
    flLcrRegValue = SciDrv_HwEnableRegisterConfigMode(pRegBase, SCIDRV_REG_CONFIG_MODE_B);

    /* Restoring the value of EFR[4]. */
    SciDrv_Write_Field32(pRegBase + UART_EFR, UART_EFR_ENHANCED_EN_MASK, UART_EFR_ENHANCED_EN_SHIFT,
                  pEnhanFnBitVal >> UART_EFR_ENHANCED_EN_SHIFT);

    /* Programming LCR with the collected value. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, flLcrRegValue);
}

/*============================================================================
**
** Function Name    :   SciDrv_HwGetIntrIdentityStatus
**
** Visibility       :   Private
**
** Description      :   Interrupt Identification
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel 
**                      
** Outputs          :  Returns the Interrupt that is occured
**
** Critical Section :   
**
**==========================================================================*/
static uint32 SciDrv_HwGetIntrIdentityStatus(uint32 pRegBase)
{
	uint32 flLcrRegValue = 0U;
    uint32 flRegValue      = 0U;

    /* Preserving the current value of LCR. */
    flLcrRegValue = SciDrv_Read_Reg32(pRegBase + UART_LCR);

    /* Switching to Register Operational Mode of operation. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, SciDrv_Read_Reg32(pRegBase + UART_LCR)
                            & 0x7FU);

    flRegValue = SciDrv_Read_Reg32(pRegBase + UART_IIR_UART) & UART_IIR_UART_IT_TYPE_MASK;

    /* Restoring the value of LCR. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, flLcrRegValue);

    return flRegValue;
}

/*============================================================================
**
** Function Name    :   SciDrv_HwPutChar
**
** Visibility       :   Private
**
** Description      :   Writting Bytes to Tx FIFO
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**                      uint8 pByteTx: Data  
**                      
** Outputs          :  
**
** Critical Section :   
**
**==========================================================================*/
static void SciDrv_HwPutChar(uint32 pRegBase, uint8 pByteTx)
{
    /* Write the byte to the Transmit Holding Register(or TX FIFO). */
    SciDrv_Write_Reg32(pRegBase + UART_THR, (uint32) pByteTx);
}



/*============================================================================
**
** Function Name    :   SciDrv_HwReadLineStatus
**
** Visibility       :   Private
**
** Description      :   Gets the Line Status
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**                      
** Outputs          :  Returns the Rx and Tx line status
**
** Critical Section :   
**
**==========================================================================*/
static uint32 SciDrv_HwReadLineStatus(uint32 pRegBase)
{
    uint32 pLcrRegValue = 0U;
    uint32 pRetVal      = 0U;

    /* Preserving the current value of LCR. */
    pLcrRegValue = SciDrv_Read_Reg32(pRegBase + UART_LCR);

    /* Switching to Register Operational Mode of operation. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, SciDrv_Read_Reg32(pRegBase + UART_LCR)
                            & 0x7FU);

    pRetVal = SciDrv_Read_Reg32(pRegBase + UART_LSR_UART);

    /* Restoring the value of LCR. */
    SciDrv_Write_Reg32(pRegBase + UART_LCR, pLcrRegValue);

    return pRetVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_Write_Field32
**
** Visibility       :   Private
**
** Description      :   This function reads a 32 bit register, modifies specific set of
**                      bits and writes back to the register.
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**                      uint32 pRegFieldmask: Bit mask value
**                      uint32 pRegFieldShift: Bit shift value
**                      uint32 pFieldValu: Value to be written
**                      
** Outputs          :  Returns the Rx and Tx line status
**
** Critical Section :   
**
**==========================================================================*/
static void SciDrv_Write_Field32(uint32 pRegBase, uint32 pRegFieldMask, uint32 pRegFieldShift, uint32 pFieldValue)
{
    volatile uint32 *regPtr = (volatile uint32 *)pRegBase;
    uint32 flRegVal = *regPtr;

    flRegVal &= (~pRegFieldMask);
    flRegVal |= (pFieldValue << pRegFieldShift) & pRegFieldMask;

    *regPtr = flRegVal;
    return;
}

/*============================================================================
**
** Function Name    :   SciDrv_Read_Field32
**
** Visibility       :   Private
**
** Description      :   This function reads a 32 bit register, masks specific set of bits
**                      and the left shifted value.
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**                      uint32 pRegFieldmask: Bit mask value
**                      uint32 pRegFieldShift: Bit shift value
**                      
** Outputs          :  Returns bit field value
**
** Critical Section :   
**
**==========================================================================*/
static uint32 SciDrv_Read_Field32(uint32 pRegBase, uint32 pRegFieldMask, uint32 pRegFieldShift)
{
    volatile uint32 *regPtr = (volatile uint32 *)pRegBase;
    uint32 flRegVal = *regPtr;

    flRegVal = (flRegVal & pRegFieldMask) >> pRegFieldShift;
    return flRegVal;
}

/*============================================================================
**
** Function Name    :   SciDrv_Write_Reg32
**
** Visibility       :   Private
**
** Description      :   This function writes a 32-bit value to a hardware register.
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Register address of Enabled Channel
**                      
** Outputs          :  
**
** Critical Section :   
**
**==========================================================================*/
static void SciDrv_Write_Reg32(uint32 pRegBase, uint32 pValue)
{
    volatile uint32 *regPtr = (volatile uint32 *)pRegBase;
    *regPtr = pValue;
}

/*============================================================================
**
** Function Name    :   SciDrv_Read_Reg32
**
** Visibility       :   Private
**
** Description      :   This function reads a 32-bit value from a hardware register
**                      and returns the value.
**
** Invocation       :   Static
**
** Inputs           :   uint32 pRegBase: Address of the mapped regsiter
**                      
** Outputs          :   Returns the register value
**
** Critical Section :   
**
**==========================================================================*/
static uint32 SciDrv_Read_Reg32(uint32 pRegBase)
{
    volatile uint32 *regPtr = (volatile uint32 *)pRegBase;  // No extra cast needed
    uint32 flRegVal = *regPtr;
    return flRegVal;
}


/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 15-02-2024                                            */
/*Version           :                                                       */
/*By                : sdv                                                   */
/*Traceability      :                                                       */
/*Change Description: Proveout, Initial Version                             */
/*--------------------------------------------------------------------------*/

/**-------------------------------------------------------------------------*/
/*Date              : 26-02-2024                                            */
/*Version           :                                                       */
/*By                : sdv                                                   */
/*Traceability      :                                                       */
/*Change Description: Initial Version Platform Release                       */
/*--------------------------------------------------------------------------*/