/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2012. Visteon Corporation owns all rights to           *
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
*****************************************************************************/
/*****************************************************************************
*  File Name         :  SciDrv.h                                             *
*  Module Short Name :  Sci Driver                                           *
*  VOBName           :                                                       *
*  Author            : sdv                                                   *
*  Description       : This file contains the typedefs for SciDrv            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/

#ifndef SCIDRV_TYPES_H
#define SCIDRV_TYPES_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "Std_Types.h"
#include "Platform_Types.h"
#include <stdint.h>


/*******************************************************************************
*                                     SCI/UART Register Offset Address
*******************************************************************************/


#define UART_RHR                                                                                            ((uint32)0x0U)
#define UART_THR                                                                                            ((uint32)0x0U)
#define UART_IER_UART                                                                                       ((uint32)0x4U)
#define UART_IIR_UART                                                                                       ((uint32)0x8U)
#define UART_FCR                                                                                            ((uint32)0x8U)
#define UART_LCR                                                                                            ((uint32)0xcU)
#define UART_MCR                                                                                            ((uint32)0x10U)
#define UART_LSR_UART                                                                                       ((uint32)0x14U)
#define UART_MSR                                                                                            ((uint32)0x18U)
#define UART_SPR                                                                                            ((uint32)0x1cU)
#define UART_MDR1                                                                                           ((uint32)0x20U)
#define UART_MDR2                                                                                           ((uint32)0x24U)
#define UART_SFLSR                                                                                          ((uint32)0x28U)
#define UART_TXFLL                                                                                          ((uint32)0x28U)
#define UART_RESUME                                                                                         ((uint32)0x2cU)
#define UART_TXFLH                                                                                          ((uint32)0x2cU)
#define UART_SFREGL                                                                                         ((uint32)0x30U)
#define UART_RXFLL                                                                                          ((uint32)0x30U)
#define UART_SFREGH                                                                                         ((uint32)0x34U)
#define UART_RXFLH                                                                                          ((uint32)0x34U)
#define UART_BLR                                                                                            ((uint32)0x38U)
#define UART_ACREG                                                                                          ((uint32)0x3cU)
#define UART_SCR                                                                                            ((uint32)0x40U)
#define UART_SSR                                                                                            ((uint32)0x44U)
#define UART_EBLR                                                                                           ((uint32)0x48U)
#define UART_MVR                                                                                            ((uint32)0x50U)
#define UART_SYSC                                                                                           ((uint32)0x54U)
#define UART_SYSS                                                                                           ((uint32)0x58U)
#define UART_WER                                                                                            ((uint32)0x5cU)
#define UART_CFPS                                                                                           ((uint32)0x60U)
#define UART_RXFIFO_LVL                                                                                     ((uint32)0x64U)
#define UART_TXFIFO_LVL                                                                                     ((uint32)0x68U)
#define UART_IER2                                                                                           ((uint32)0x6cU)
#define UART_ISR2                                                                                           ((uint32)0x70U)
#define UART_FREQ_SEL                                                                                       ((uint32)0x74U)
#define UART_ABAUD_1ST_CHAR                                                                                 ((uint32)0x78U)
#define UART_BAUD_2ND_CHAR                                                                                  ((uint32)0x7cU)
#define UART_MDR3                                                                                           ((uint32)0x80U)
#define UART_TX_DMA_THRESHOLD                                                                               ((uint32)0x84U)
#define UART_MDR4                                                                                           ((uint32)0x88U)
#define UART_EFR2                                                                                           ((uint32)0x8cU)
#define UART_ECR                                                                                            ((uint32)0x90U)
#define UART_TIMEGUARD                                                                                      ((uint32)0x94U)
#define UART_TIMEOUTL                                                                                       ((uint32)0x98U)
#define UART_TIMEOUTH                                                                                       ((uint32)0x9cU)
#define UART_SCCR                                                                                           ((uint32)0xA0U)
#define UART_ERHR                                                                                           ((uint32)0xA4U)
#define UART_ETHR                                                                                           ((uint32)0xA4U)
#define UART_MAR                                                                                            ((uint32)0xA8h)
#define UART_MMR                                                                                            ((uint32)0xAcU)
#define UART_MBR                                                                                            ((uint32)0xb0U)
#define UART_DLL                                                                                            ((uint32)0x0U)
#define UART_IER_IRDA                                                                                       ((uint32)0x4U)
#define UART_IER_CIR                                                                                        ((uint32)0x4U)
#define UART_DLH                                                                                            ((uint32)0x4U)
#define UART_IIR_IRDA                                                                                       ((uint32)0x8U)
#define UART_IIR_CIR                                                                                        ((uint32)0x8U)
#define UART_EFR                                                                                            ((uint32)0x8U)
#define UART_XON1_ADDR1                                                                                     ((uint32)0x10U)
#define UART_LSR_IRDA                                                                                       ((uint32)0x14U)
#define UART_LSR_CIR                                                                                        ((uint32)0x14U)
#define UART_XON2_ADDR2                                                                                     ((uint32)0x14U)
#define UART_XOFF1                                                                                          ((uint32)0x18U)
#define UART_TCR                                                                                            ((uint32)0x18U)
#define UART_XOFF2                                                                                          ((uint32)0x1cU)
#define UART_TLR                                                                                            ((uint32)0x1cU)
#define UART_UASR                                                                                           ((uint32)0x38U)



/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/


/**
  * \brief Transmit Holding Register (UART_THR)
  */

#define UART_RHR_RHR_SHIFT                                                                                       ((uint32)0U)
#define UART_RHR_RHR_MASK                                                                                        ((uint32)0x000000ffU)

#define UART_RHR_RESERVED_24_SHIFT                                                                               ((uint32)8U)
#define UART_RHR_RESERVED_24_MASK                                                                                ((uint32)0xffffff00U)

/**
  * \brief Receiver Holding Register (UART_RHR)
  */

#define UART_THR_THR_SHIFT                                                                                       ((uint32)0U)
#define UART_THR_THR_MASK                                                                                        ((uint32)0x000000ffU)

#define UART_THR_RESERVED_24_SHIFT                                                                                ((uint32)8U)
#define UART_THR_RESERVED_24_MASK                                                                                 ((uint32)0xffffff00U)

/**
  * \brief  UART mode interrupt enable register (UART_IER_UART)
  */                                                                                                              
#define UART_IER_UART_RHR_IT_SHIFT                                                                                ((uint32)0U)
#define UART_IER_UART_RHR_IT_MASK                                                                                 ((uint32)0x00000001U)
#define UART_IER_UART_RHR_IT_RHR_IT_VALUE_1                                                                       ((uint32)1U)
#define UART_IER_UART_RHR_IT_RHR_IT_VALUE_0                                                                       ((uint32)0U)

#define UART_IER_UART_THR_IT_SHIFT                                                                                ((uint32)1U)
#define UART_IER_UART_THR_IT_MASK                                                                                 ((uint32)0x00000002U)
#define UART_IER_UART_THR_IT_THR_IT_VALUE_1                                                                       ((uint32)1U)
#define UART_IER_UART_THR_IT_THR_IT_VALUE_0                                                                       ((uint32)0U)

#define UART_IER_UART_LINE_STS_IT_SHIFT                                                                           ((uint32)2U)
#define UART_IER_UART_LINE_STS_IT_MASK                                                                            ((uint32)0x00000004U)
#define UART_IER_UART_LINE_STS_IT_LINE_STS_IT_U_VALUE_1                                                           ((uint32)1U)
#define UART_IER_UART_LINE_STS_IT_LINE_STS_IT_U_VALUE_0                                                           ((uint32)0U)

#define UART_IER_UART_MODEM_STS_IT_SHIFT                                                                          ((uint32)3U)
#define UART_IER_UART_MODEM_STS_IT_MASK                                                                           ((uint32)0x00000008U)
#define UART_IER_UART_MODEM_STS_IT_MODEM_STS_IT_VALUE_1                                                           ((uint32)1U)
#define UART_IER_UART_MODEM_STS_IT_MODEM_STS_IT_VALUE_0                                                           ((uint32)0U)

#define UART_IER_UART_SLEEP_MODE_SHIFT                                                                            ((uint32)4U)
#define UART_IER_UART_SLEEP_MODE_MASK                                                                             ((uint32)0x00000010U)
#define UART_IER_UART_SLEEP_MODE_SLEEP_MODE_VALUE_1                                                               ((uint32)1U)
#define UART_IER_UART_SLEEP_MODE_SLEEP_MODE_VALUE_0                                                               ((uint32)0U)

#define UART_IER_UART_XOFF_IT_SHIFT                                                                               ((uint32)5U)
#define UART_IER_UART_XOFF_IT_MASK                                                                                ((uint32)0x00000020U)
#define UART_IER_UART_XOFF_IT_XOFF_IT_VALUE_1                                                                     ((uint32)1U)
#define UART_IER_UART_XOFF_IT_XOFF_IT_VALUE_0                                                                     ((uint32)0U)

#define UART_IER_UART_RTS_IT_SHIFT                                                                                ((uint32)6U)
#define UART_IER_UART_RTS_IT_MASK                                                                                 ((uint32)0x00000040U)
#define UART_IER_UART_RTS_IT_RTS_IT_VALUE_1                                                                       ((uint32)1U)
#define UART_IER_UART_RTS_IT_RTS_IT_VALUE_0                                                                       ((uint32)0U)

#define UART_IER_UART_CTS_IT_SHIFT                                                                                ((uint32)7U)
#define UART_IER_UART_CTS_IT_MASK                                                                                 ((uint32)0x00000080U)
#define UART_IER_UART_CTS_IT_CTS_IT_VALUE_1                                                                       ((uint32)1U)
#define UART_IER_UART_CTS_IT_CTS_IT_VALUE_0                                                                       ((uint32)0U)

#define UART_IER_UART_RESERVED_SHIFT                                                                              ((uint32)8U)
#define UART_IER_UART_RESERVED_MASK                                                                               ((uint32)0xffffff00U)

/**
  * \brief  UART mode interrupt identification register (UART_IIR_UART)
  */

#define UART_IIR_UART_IT_PENDING_SHIFT                                                                            ((uint32)0U)
#define UART_IIR_UART_IT_PENDING_MASK                                                                             ((uint32)0x00000001U)
#define UART_IIR_UART_IT_PENDING_IT_PENDING_VALUE_0                                                               ((uint32)0U)
#define UART_IIR_UART_IT_PENDING_IT_PENDING_VALUE_1                                                               ((uint32)1U)

#define UART_IIR_UART_IT_TYPE_SHIFT                                                                               ((uint32)1U)
#define UART_IIR_UART_IT_TYPE_MASK                                                                                ((uint32)0x0000003eU)
#define UART_IIR_UART_IT_TYPE_IT_TYPE_VALUE_8                                                                     ((uint32)8U)
#define UART_IIR_UART_IT_TYPE_IT_TYPE_VALUE_6                                                                     ((uint32)6U)
#define UART_IIR_UART_IT_TYPE_IT_TYPE_VALUE_3                                                                     ((uint32)3U)
#define UART_IIR_UART_IT_TYPE_IT_TYPE_VALUE_10                                                                    ((uint32)16U)
#define UART_IIR_UART_IT_TYPE_IT_TYPE_VALUE_2                                                                     ((uint32)2U)
#define UART_IIR_UART_IT_TYPE_IT_TYPE_VALUE_1                                                                     ((uint32)1U)
#define UART_IIR_UART_IT_TYPE_IT_TYPE_VALUE_0                                                                     ((uint32)0U)

#define UART_IIR_UART_FCR_MIRROR_SHIFT                                                                            ((uint32)6U)
#define UART_IIR_UART_FCR_MIRROR_MASK                                                                             ((uint32)0x000000c0U)

#define UART_IIR_UART_RESERVED_24_SHIFT                                                                           ((uint32)8U)
#define UART_IIR_UART_RESERVED_24_MASK                                                                            ((uint32)0xffffff00U)

/**
  * \brief  FIFO control register (UART_FCR)
  */

#define UART_FCR_FIFO_EN_SHIFT                                                                               ((uint32)0U)
#define UART_FCR_FIFO_EN_MASK                                                                                ((uint32)0x00000001U)
#define UART_FCR_FIFO_EN_FIFO_EN_VALUE_1                                                                     ((uint32)1U)
#define UART_FCR_FIFO_EN_FIFO_EN_VALUE_0                                                                     ((uint32)0U)

#define UART_FCR_RX_FIFO_CLEAR_SHIFT                                                                         ((uint32)1U)
#define UART_FCR_RX_FIFO_CLEAR_MASK                                                                          ((uint32)0x00000002U)
#define UART_FCR_RX_FIFO_CLEAR_RX_FIFO_CLEAR_VALUE_1                                                         ((uint32)1U)
#define UART_FCR_RX_FIFO_CLEAR_RX_FIFO_CLEAR_VALUE_0                                                         ((uint32)0U)

#define UART_FCR_TX_FIFO_CLEAR_SHIFT                                                                         ((uint32)2U)
#define UART_FCR_TX_FIFO_CLEAR_MASK                                                                          ((uint32)0x00000004U)
#define UART_FCR_TX_FIFO_CLEAR_TX_FIFO_CLEAR_VALUE_1                                                         ((uint32)1U)
#define UART_FCR_TX_FIFO_CLEAR_TX_FIFO_CLEAR_VALUE_0                                                         ((uint32)0U)

#define UART_FCR_DMA_MODE_SHIFT                                                                              ((uint32)3U)
#define UART_FCR_DMA_MODE_MASK                                                                               ((uint32)0x00000008U)
#define UART_FCR_DMA_MODE_DMA_MODE_VALUE_1                                                                   ((uint32)1U)
#define UART_FCR_DMA_MODE_DMA_MODE_VALUE_0                                                                   ((uint32)0U)

#define UART_FCR_TX_FIFO_TRIG_SHIFT                                                                          ((uint32)4U)
#define UART_FCR_TX_FIFO_TRIG_MASK                                                                           ((uint32)0x00000030U)
#define UART_FCR_TX_FIFO_TRIG_VALUE_0                                                                        ((uint32)0U)
#define UART_FCR_TX_FIFO_TRIG_VALUE_1                                                                        ((uint32)1U)
#define UART_FCR_TX_FIFO_TRIG_VALUE_2                                                                        ((uint32)2U)
#define UART_FCR_TX_FIFO_TRIG_VALUE_3                                                                        ((uint32)3U)

#define UART_FCR_RX_FIFO_TRIG_SHIFT                                                                          ((uint32)6U)
#define UART_FCR_RX_FIFO_TRIG_MASK                                                                           ((uint32)0x000000c0U)
#define UART_FCR_RX_FIFO_TRIG_VALUE_0                                                                        ((uint32)0U)
#define UART_FCR_RX_FIFO_TRIG_VALUE_1                                                                        ((uint32)1U)
#define UART_FCR_RX_FIFO_TRIG_VALUE_2                                                                        ((uint32)2U)
#define UART_FCR_RX_FIFO_TRIG_VALUE_3                                                                        ((uint32)3U)

#define UART_FCR_RESERVED_24_SHIFT                                                                           ((uint32)8U)
#define UART_FCR_RESERVED_24_MASK                                                                            ((uint32)0xffffff00U)

/**
  * \brief  Line control register (UART_LCR)
  */

#define UART_LCR_CHAR_LENGTH_SHIFT                                                                           ((uint32)0U)
#define UART_LCR_CHAR_LENGTH_MASK                                                                            ((uint32)0x00000003U)
#define UART_LCR_CHAR_LENGTH_CHAR_LENGTH_VALUE_3                                                             ((uint32)3U)
#define UART_LCR_CHAR_LENGTH_CHAR_LENGTH_VALUE_2                                                             ((uint32)2U)
#define UART_LCR_CHAR_LENGTH_CHAR_LENGTH_VALUE_1                                                             ((uint32)1U)
#define UART_LCR_CHAR_LENGTH_CHAR_LENGTH_VALUE_0                                                             ((uint32)0U)

#define UART_LCR_NB_STOP_SHIFT                                                                               ((uint32)2U)
#define UART_LCR_NB_STOP_MASK                                                                                ((uint32)0x00000004U)
#define UART_LCR_NB_STOP_NB_STOP_VALUE_1                                                                     ((uint32)1U)
#define UART_LCR_NB_STOP_NB_STOP_VALUE_0                                                                     ((uint32)0U)

#define UART_LCR_PARITY_EN_SHIFT                                                                             ((uint32)3U)
#define UART_LCR_PARITY_EN_MASK                                                                              ((uint32)0x00000008U)
#define UART_LCR_PARITY_EN_PARITY_EN_VALUE_1                                                                 ((uint32)1U)
#define UART_LCR_PARITY_EN_PARITY_EN_VALUE_0                                                                 ((uint32)0U)

#define UART_LCR_PARITY_TYPE1_SHIFT                                                                          ((uint32)4U)
#define UART_LCR_PARITY_TYPE1_MASK                                                                           ((uint32)0x00000010U)
#define UART_LCR_PARITY_TYPE1_PARITY_TYPE1_VALUE_1                                                           ((uint32)1U)
#define UART_LCR_PARITY_TYPE1_PARITY_TYPE1_VALUE_0                                                           ((uint32)0U)

#define UART_LCR_PARITY_TYPE2_SHIFT                                                                          ((uint32)5U)
#define UART_LCR_PARITY_TYPE2_MASK                                                                           ((uint32)0x00000020U)

#define UART_LCR_BREAK_EN_SHIFT                                                                              ((uint32)6U)
#define UART_LCR_BREAK_EN_MASK                                                                               ((uint32)0x00000040U)
#define UART_LCR_BREAK_EN_BREAK_EN_VALUE_1                                                                   ((uint32)1U)
#define UART_LCR_BREAK_EN_BREAK_EN_VALUE_0                                                                   ((uint32)0U)

#define UART_LCR_DIV_EN_SHIFT                                                                                ((uint32)7U)
#define UART_LCR_DIV_EN_MASK                                                                                 ((uint32)0x00000080U)
#define UART_LCR_DIV_EN_DIV_EN_VALUE_0                                                                       ((uint32)0U)
#define UART_LCR_DIV_EN_DIV_EN_VALUE_1                                                                       ((uint32)1U)

#define UART_LCR_RESERVED_24_SHIFT                                                                           ((uint32)8U)
#define UART_LCR_RESERVED_24_MASK                                                                            ((uint32)0xffffff00U)

/**
  * \brief  Modem control register (UART_MCR)
  */

#define UART_MCR_LOOPBACK_EN_SHIFT                                                                           ((uint32)4U)
#define UART_MCR_LOOPBACK_EN_MASK                                                                            ((uint32)0x00000010U)
#define UART_MCR_LOOPBACK_EN_LOOPBACK_EN_VALUE_1                                                             ((uint32)1U)
#define UART_MCR_LOOPBACK_EN_LOOPBACK_EN_VALUE_0                                                             ((uint32)0U)

#define UART_MCR_XON_EN_SHIFT                                                                                ((uint32)5U)
#define UART_MCR_XON_EN_MASK                                                                                 ((uint32)0x00000020U)
#define UART_MCR_XON_EN_XON_EN_VALUE_1                                                                       ((uint32)1U)
#define UART_MCR_XON_EN_XON_EN_VALUE_0                                                                       ((uint32)0U)

#define UART_MCR_TCR_TLR_SHIFT                                                                               ((uint32)6U)
#define UART_MCR_TCR_TLR_MASK                                                                                ((uint32)0x00000040U)
#define UART_MCR_TCR_TLR_TCR_TLR_VALUE_1                                                                     ((uint32)1U)
#define UART_MCR_TCR_TLR_TCR_TLR_VALUE_0                                                                     ((uint32)0U)

#define UART_MCR_RESERVED_SHIFT                                                                              ((uint32)7U)
#define UART_MCR_RESERVED_MASK                                                                               ((uint32)0x00000080U)

#define UART_MCR_DTR_SHIFT                                                                                   ((uint32)0U)
#define UART_MCR_DTR_MASK                                                                                    ((uint32)0x00000001U)
#define UART_MCR_DTR_DTR_VALUE_1                                                                             ((uint32)1U)
#define UART_MCR_DTR_DTR_VALUE_0                                                                             ((uint32)0U)

#define UART_MCR_RTS_SHIFT                                                                                   ((uint32)1U)
#define UART_MCR_RTS_MASK                                                                                    ((uint32)0x00000002U)
#define UART_MCR_RTS_RTS_VALUE_1                                                                             ((uint32)1U)
#define UART_MCR_RTS_RTS_VALUE_0                                                                             ((uint32)0U)

#define UART_MCR_RI_STS_CH_SHIFT                                                                             ((uint32)2U)
#define UART_MCR_RI_STS_CH_MASK                                                                              ((uint32)0x00000004U)
#define UART_MCR_RI_STS_CH_RI_STS_CH_VALUE_1                                                                 ((uint32)1U)
#define UART_MCR_RI_STS_CH_RI_STS_CH_VALUE_0                                                                 ((uint32)0U)

#define UART_MCR_CD_STS_CH_SHIFT                                                                             ((uint32)3U)
#define UART_MCR_CD_STS_CH_MASK                                                                              ((uint32)0x00000008U)
#define UART_MCR_CD_STS_CH_CD_STS_CH_VALUE_1                                                                 ((uint32)1U)
#define UART_MCR_CD_STS_CH_CD_STS_CH_VALUE_0                                                                 ((uint32)0U)

#define UART_MCR_RESERVED_24_SHIFT                                                                           ((uint32)8U)
#define UART_MCR_RESERVED_24_MASK                                                                            ((uint32)0xffffff00U)

/**
  * \brief  UART mode line status register (UART_LSR_UART)
  */

#define UART_LSR_UART_RX_FIFO_E_SHIFT                                                                             ((uint32)0U)
#define UART_LSR_UART_RX_FIFO_E_MASK                                                                              ((uint32)0x00000001U)
#define UART_LSR_UART_RX_FIFO_E_RX_FIFO_E_VALUE_1                                                                 ((uint32)1U)
#define UART_LSR_UART_RX_FIFO_E_RX_FIFO_E_VALUE_0                                                                 ((uint32)0U)

#define UART_LSR_UART_RX_OE_SHIFT                                                                                 ((uint32)1U)
#define UART_LSR_UART_RX_OE_MASK                                                                                  ((uint32)0x00000002U)
#define UART_LSR_UART_RX_OE_RX_OE_VALUE_1                                                                         ((uint32)1U)
#define UART_LSR_UART_RX_OE_RX_OE_VALUE_0                                                                         ((uint32)0U)

#define UART_LSR_UART_RX_PE_SHIFT                                                                                 ((uint32)2U)
#define UART_LSR_UART_RX_PE_MASK                                                                                  ((uint32)0x00000004U)
#define UART_LSR_UART_RX_PE_RX_PE_VALUE_1                                                                         ((uint32)1U)
#define UART_LSR_UART_RX_PE_RX_PE_VALUE_0                                                                         ((uint32)0U)

#define UART_LSR_UART_RX_FE_SHIFT                                                                                 ((uint32)3U)
#define UART_LSR_UART_RX_FE_MASK                                                                                  ((uint32)0x00000008U)
#define UART_LSR_UART_RX_FE_RX_FE_VALUE_1                                                                         ((uint32)1U)
#define UART_LSR_UART_RX_FE_RX_FE_VALUE_0                                                                         ((uint32)0U)

#define UART_LSR_UART_RX_BI_SHIFT                                                                                 ((uint32)4U)
#define UART_LSR_UART_RX_BI_MASK                                                                                  ((uint32)0x00000010U)
#define UART_LSR_UART_RX_BI_RX_BI_VALUE_1                                                                         ((uint32)1U)
#define UART_LSR_UART_RX_BI_RX_BI_VALUE_0                                                                         ((uint32)0U)

#define UART_LSR_UART_TX_FIFO_E_SHIFT                                                                             ((uint32)5U)
#define UART_LSR_UART_TX_FIFO_E_MASK                                                                              ((uint32)0x00000020U)
#define UART_LSR_UART_TX_FIFO_E_TX_FIFO_E_VALUE_1                                                                 ((uint32)1U)
#define UART_LSR_UART_TX_FIFO_E_TX_FIFO_E_VALUE_0                                                                 ((uint32)0U)

#define UART_LSR_UART_TX_SR_E_SHIFT                                                                               ((uint32)6U)
#define UART_LSR_UART_TX_SR_E_MASK                                                                                ((uint32)0x00000040U)
#define UART_LSR_UART_TX_SR_E_TX_SR_E_VALUE_1                                                                     ((uint32)1U)
#define UART_LSR_UART_TX_SR_E_TX_SR_E_VALUE_0                                                                     ((uint32)0U)

#define UART_LSR_UART_RX_FIFO_STS_SHIFT                                                                           ((uint32)7U)
#define UART_LSR_UART_RX_FIFO_STS_MASK                                                                            ((uint32)0x00000080U)
#define UART_LSR_UART_RX_FIFO_STS_RX_FIFO_STS_VALUE_1                                                             ((uint32)1U)
#define UART_LSR_UART_RX_FIFO_STS_RX_FIFO_STS_VALUE_0                                                             ((uint32)0U)

#define UART_LSR_UART_RESERVED_24_SHIFT                                                                           ((uint32)8U)
#define UART_LSR_UART_RESERVED_24_MASK                                                                            ((uint32)0xffffff00U)


/**
  * \brief  Modem status register (UART_MSR)
  */

#define UART_MSR_CTS_STS_SHIFT                                                                               ((uint32)0U)
#define UART_MSR_CTS_STS_MASK                                                                                ((uint32)0x00000001U)
#define UART_MSR_CTS_STS_CTS_STS_VALUE_1                                                                     ((uint32)1U)

#define UART_MSR_DSR_STS_SHIFT                                                                               ((uint32)1U)
#define UART_MSR_DSR_STS_MASK                                                                                ((uint32)0x00000002U)
#define UART_MSR_DSR_STS_DSR_STS_VALUE_1                                                                     ((uint32)1U)

#define UART_MSR_RI_STS_SHIFT                                                                                ((uint32)2U)
#define UART_MSR_RI_STS_MASK                                                                                 ((uint32)0x00000004U)

#define UART_MSR_DCD_STS_SHIFT                                                                               ((uint32)3U)
#define UART_MSR_DCD_STS_MASK                                                                                ((uint32)0x00000008U)

#define UART_MSR_NCTS_STS_SHIFT                                                                              ((uint32)4U)
#define UART_MSR_NCTS_STS_MASK                                                                               ((uint32)0x00000010U)

#define UART_MSR_NDSR_STS_SHIFT                                                                              ((uint32)5U)
#define UART_MSR_NDSR_STS_MASK                                                                               ((uint32)0x00000020U)

#define UART_MSR_NRI_STS_SHIFT                                                                               ((uint32)6U)
#define UART_MSR_NRI_STS_MASK                                                                                ((uint32)0x00000040U)

#define UART_MSR_NCD_STS_SHIFT                                                                               ((uint32)7U)
#define UART_MSR_NCD_STS_MASK                                                                                ((uint32)0x00000080U)

#define UART_MSR_RESERVED_24_SHIFT                                                                           ((uint32)8U)
#define UART_MSR_RESERVED_24_MASK                                                                            ((uint32)0xffffff00U)

/**
  * \brief  Scratchpad register (UART_SPR)
  */

#define UART_SPR_SPR_WORD_SHIFT                                                                              ((uint32)0U)
#define UART_SPR_SPR_WORD_MASK                                                                               ((uint32)0x000000ffU)

#define UART_SPR_RESERVED_24_SHIFT                                                                           ((uint32)8U)
#define UART_SPR_RESERVED_24_MASK                                                                            ((uint32)0xffffff00U)

/**
  * \brief  Mode definition register 1 (UART_MDR1)
  */

#define UART_MDR1_MODE_SELECT_SHIFT                                                                          ((uint32)0U)
#define UART_MDR1_MODE_SELECT_MASK                                                                           ((uint32)0x00000007U)
#define UART_MDR1_MODE_SELECT_MODE_SELECT_VALUE_7                                                            ((uint32)7U)
#define UART_MDR1_MODE_SELECT_MODE_SELECT_VALUE_6                                                            ((uint32)6U)
#define UART_MDR1_MODE_SELECT_MODE_SELECT_VALUE_5                                                            ((uint32)5U)
#define UART_MDR1_MODE_SELECT_MODE_SELECT_VALUE_4                                                            ((uint32)4U)
#define UART_MDR1_MODE_SELECT_MODE_SELECT_VALUE_3                                                            ((uint32)3U)
#define UART_MDR1_MODE_SELECT_MODE_SELECT_VALUE_2                                                            ((uint32)2U)
#define UART_MDR1_MODE_SELECT_MODE_SELECT_VALUE_1                                                            ((uint32)1U)
#define UART_MDR1_MODE_SELECT_MODE_SELECT_VALUE_0                                                            ((uint32)0U)

#define UART_MDR1_IR_SLEEP_SHIFT                                                                             ((uint32)3U)
#define UART_MDR1_IR_SLEEP_MASK                                                                              ((uint32)0x00000008U)
#define UART_MDR1_IR_SLEEP_IR_SLEEP_VALUE_1                                                                  ((uint32)1U)
#define UART_MDR1_IR_SLEEP_IR_SLEEP_VALUE_0                                                                  ((uint32)0U)

#define UART_MDR1_SET_TXIR_SHIFT                                                                             ((uint32)4U)
#define UART_MDR1_SET_TXIR_MASK                                                                              ((uint32)0x00000010U)
#define UART_MDR1_SET_TXIR_SET_TXIR_VALUE_1                                                                  ((uint32)1U)
#define UART_MDR1_SET_TXIR_SET_TXIR_VALUE_0                                                                  ((uint32)0U)

#define UART_MDR1_SCT_SHIFT                                                                                  ((uint32)5U)
#define UART_MDR1_SCT_MASK                                                                                   ((uint32)0x00000020U)
#define UART_MDR1_SCT_SCT_VALUE_1                                                                            ((uint32)1U)
#define UART_MDR1_SCT_SCT_VALUE_0                                                                            ((uint32)0U)

#define UART_MDR1_SIP_MODE_SHIFT                                                                             ((uint32)6U)
#define UART_MDR1_SIP_MODE_MASK                                                                              ((uint32)0x00000040U)
#define UART_MDR1_SIP_MODE_SIP_MODE_VALUE_1                                                                  ((uint32)1U)
#define UART_MDR1_SIP_MODE_SIP_MODE_VALUE_0                                                                  ((uint32)0U)

#define UART_MDR1_FRAME_END_MODE_SHIFT                                                                       ((uint32)7U)
#define UART_MDR1_FRAME_END_MODE_MASK                                                                        ((uint32)0x00000080U)
#define UART_MDR1_FRAME_END_MODE_FRAME_END_MODE_VALUE_1                                                      ((uint32)1U)
#define UART_MDR1_FRAME_END_MODE_FRAME_END_MODE_VALUE_0                                                      ((uint32)0U)

#define UART_MDR1_RESERVED_24_SHIFT                                                                          ((uint32)8U)
#define UART_MDR1_RESERVED_24_MASK                                                                           ((uint32)0xffffff00U)

/**
  * \brief  Mode definition register 2 (UART_MDR2)
  */

#define UART_MDR2_IRTX_UNDERRUN_SHIFT                                                                        ((uint32)0U)
#define UART_MDR2_IRTX_UNDERRUN_MASK                                                                         ((uint32)0x00000001U)
#define UART_MDR2_IRTX_UNDERRUN_IRTX_UNDERRUN_VALUE_1                                                        ((uint32)1U)
#define UART_MDR2_IRTX_UNDERRUN_IRTX_UNDERRUN_VALUE_0                                                        ((uint32)0U)

#define UART_MDR2_STS_FIFO_TRIG_SHIFT                                                                        ((uint32)1U)
#define UART_MDR2_STS_FIFO_TRIG_MASK                                                                         ((uint32)0x00000006U)
#define UART_MDR2_STS_FIFO_TRIG_STS_FIFO_TRIG_VALUE_3                                                        ((uint32)3U)
#define UART_MDR2_STS_FIFO_TRIG_STS_FIFO_TRIG_VALUE_2                                                        ((uint32)2U)
#define UART_MDR2_STS_FIFO_TRIG_STS_FIFO_TRIG_VALUE_1                                                        ((uint32)1U)
#define UART_MDR2_STS_FIFO_TRIG_STS_FIFO_TRIG_VALUE_0                                                        ((uint32)0U)

#define UART_MDR2_UART_PULSE_SHIFT                                                                           ((uint32)3U)
#define UART_MDR2_UART_PULSE_MASK                                                                            ((uint32)0x00000008U)
#define UART_MDR2_UART_PULSE_UART_PULSE_VALUE_1                                                              ((uint32)1U)
#define UART_MDR2_UART_PULSE_UART_PULSE_VALUE_0                                                              ((uint32)0U)

#define UART_MDR2_CIR_PULSE_MODE_SHIFT                                                                       ((uint32)4U)
#define UART_MDR2_CIR_PULSE_MODE_MASK                                                                        ((uint32)0x00000030U)
#define UART_MDR2_CIR_PULSE_MODE_CIR_PULSE_MODE_VALUE_3                                                      ((uint32)3U)
#define UART_MDR2_CIR_PULSE_MODE_CIR_PULSE_MODE_VALUE_2                                                      ((uint32)2U)
#define UART_MDR2_CIR_PULSE_MODE_CIR_PULSE_MODE_VALUE_1                                                      ((uint32)1U)
#define UART_MDR2_CIR_PULSE_MODE_CIR_PULSE_MODE_VALUE_0                                                      ((uint32)0U)

#define UART_MDR2_IRRXINVERT_SHIFT                                                                           ((uint32)6U)
#define UART_MDR2_IRRXINVERT_MASK                                                                            ((uint32)0x00000040U)
#define UART_MDR2_IRRXINVERT_IRRXINVERT_VALUE_1                                                              ((uint32)1U)
#define UART_MDR2_IRRXINVERT_IRRXINVERT_VALUE_0                                                              ((uint32)0U)

#define UART_MDR2_SET_TXIR_ALT_SHIFT                                                                         ((uint32)7U)
#define UART_MDR2_SET_TXIR_ALT_MASK                                                                          ((uint32)0x00000080U)
#define UART_MDR2_SET_TXIR_ALT_SET_TXIR_ALT_VALUE_0                                                          ((uint32)0U)
#define UART_MDR2_SET_TXIR_ALT_SET_TXIR_ALT_VALUE_1                                                          ((uint32)1U)

#define UART_MDR2_RESERVED_24_SHIFT                                                                          ((uint32)8U)
#define UART_MDR2_RESERVED_24_MASK                                                                           ((uint32)0xffffff00U)

/**
  * \brief  Status FIFO line status register (UART_SFLSR)
  */

#define UART_SFLSR_RESERVED0_SHIFT                                                                           ((uint32)0U)
#define UART_SFLSR_RESERVED0_MASK                                                                            ((uint32)0x00000001U)

#define UART_SFLSR_CRC_ERROR_SHIFT                                                                           ((uint32)1U)
#define UART_SFLSR_CRC_ERROR_MASK                                                                            ((uint32)0x00000002U)
#define UART_SFLSR_CRC_ERROR_CRC_ERROR_VALUE_1                                                               ((uint32)1U)

#define UART_SFLSR_ABORT_DETECT_SHIFT                                                                        ((uint32)2U)
#define UART_SFLSR_ABORT_DETECT_MASK                                                                         ((uint32)0x00000004U)
#define UART_SFLSR_ABORT_DETECT_ABORT_DETECT_VALUE_1                                                         ((uint32)1U)

#define UART_SFLSR_FRAME_TOO_LONG_ERROR_SHIFT                                                                ((uint32)3U)
#define UART_SFLSR_FRAME_TOO_LONG_ERROR_MASK                                                                 ((uint32)0x00000008U)
#define UART_SFLSR_FRAME_TOO_LONG_ERROR_FRAME_TOO_LONG_ERROR_VALUE_1                                         ((uint32)1U)

#define UART_SFLSR_OE_ERROR_SHIFT                                                                            ((uint32)4U)
#define UART_SFLSR_OE_ERROR_MASK                                                                             ((uint32)0x00000010U)
#define UART_SFLSR_OE_ERROR_OE_ERROR_VALUE_1                                                                 ((uint32)1U)

#define UART_SFLSR_RESERVED5_SHIFT                                                                           ((uint32)5U)
#define UART_SFLSR_RESERVED5_MASK                                                                            ((uint32)0x000000e0U)

#define UART_SFLSR_RESERVED_24_SHIFT                                                                         ((uint32)8U)
#define UART_SFLSR_RESERVED_24_MASK                                                                          ((uint32)0xffffff00U)

/**
  * \brief  Transmit frame length register low (UART_TXFLL)
  */
#define UART_TXFLL_TXFLL_SHIFT                                                                               ((uint32)0U)
#define UART_TXFLL_TXFLL_MASK                                                                                ((uint32)0x000000ffU)

#define UART_TXFLL_RESERVED_24_SHIFT                                                                         ((uint32)8U)
#define UART_TXFLL_RESERVED_24_MASK                                                                          ((uint32)0xffffff00U)

/**
  * \brief  Resume halted operation register (UART_RESUME)
  */

#define UART_RESUME_RESUME_SHIFT                                                                             ((uint32)0U)
#define UART_RESUME_RESUME_MASK                                                                              ((uint32)0x000000ffU)

#define UART_RESUME_RESERVED_24_SHIFT                                                                        ((uint32)8U)
#define UART_RESUME_RESERVED_24_MASK                                                                         ((uint32)0xffffff00U)

/**
  * \brief  Transmit frame length register high (UART_TXFLH)
  */

#define UART_TXFLH_TXFLH_SHIFT                                                                               ((uint32)0U)
#define UART_TXFLH_TXFLH_MASK                                                                                ((uint32)0x0000001fU)

#define UART_TXFLH_RESERVED_SHIFT                                                                            ((uint32)5U)
#define UART_TXFLH_RESERVED_MASK                                                                             ((uint32)0x000000e0U)

#define UART_TXFLH_RESERVED_24_SHIFT                                                                         ((uint32)8U)
#define UART_TXFLH_RESERVED_24_MASK                                                                          ((uint32)0xffffff00U)

/**
  * \brief  Status FIFO register low (UART_SFREGL)
  */

#define UART_SFREGL_SFREGL_SHIFT                                                                             ((uint32)0U)
#define UART_SFREGL_SFREGL_MASK                                                                              ((uint32)0x000000ffU)

#define UART_SFREGL_RESERVED_24_SHIFT                                                                        ((uint32)8U)
#define UART_SFREGL_RESERVED_24_MASK                                                                         ((uint32)0xffffff00U)

/**
  * \brief  Received frame length register low (UART_RXFLL)
  */

#define UART_RXFLL_RXFLL_SHIFT                                                                               ((uint32)0U)
#define UART_RXFLL_RXFLL_MASK                                                                                ((uint32)0x000000ffU)

#define UART_RXFLL_RESERVED_24_SHIFT                                                                         ((uint32)8U)
#define UART_RXFLL_RESERVED_24_MASK                                                                          ((uint32)0xffffff00U)

/**
  * \brief  Status FIFO register high (UART_SFREGH)
  */

#define UART_SFREGH_SFREGH_SHIFT                                                                             ((uint32)0U)
#define UART_SFREGH_SFREGH_MASK                                                                              ((uint32)0x0000000fU)

#define UART_SFREGH_RESERVED_SHIFT                                                                           ((uint32)4U)
#define UART_SFREGH_RESERVED_MASK                                                                            ((uint32)0x000000f0U)

#define UART_SFREGH_RESERVED_24_SHIFT                                                                        ((uint32)8U)
#define UART_SFREGH_RESERVED_24_MASK                                                                         ((uint32)0xffffff00U)

/**
  * \brief  Received frame length register high (UART_RXFLH)
  */

#define UART_RXFLH_RXFLH_SHIFT                                                                               ((uint32)0U)
#define UART_RXFLH_RXFLH_MASK                                                                                ((uint32)0x0000000fU)

#define UART_RXFLH_RESERVED_SHIFT                                                                            ((uint32)4U)
#define UART_RXFLH_RESERVED_MASK                                                                             ((uint32)0x000000f0U)

#define UART_RXFLH_RESERVED_24_SHIFT                                                                         ((uint32)8U)
#define UART_RXFLH_RESERVED_24_MASK                                                                          ((uint32)0xffffff00U)

/**
  * \brief  BOF control register (UART_BLR)
  */

#define UART_BLR_RESERVED_SHIFT                                                                              ((uint32)0U)
#define UART_BLR_RESERVED_MASK                                                                               ((uint32)0x0000003fU)

#define UART_BLR_XBOF_TYPE_SHIFT                                                                             ((uint32)6U)
#define UART_BLR_XBOF_TYPE_MASK                                                                              ((uint32)0x00000040U)
#define UART_BLR_XBOF_TYPE_XBOF_TYPE_VALUE_1                                                                 ((uint32)1U)
#define UART_BLR_XBOF_TYPE_XBOF_TYPE_VALUE_0                                                                 ((uint32)0U)

#define UART_BLR_STS_FIFO_RESET_SHIFT                                                                        ((uint32)7U)
#define UART_BLR_STS_FIFO_RESET_MASK                                                                         ((uint32)0x00000080U)

#define UART_BLR_RESERVED_24_SHIFT                                                                           ((uint32)8U)
#define UART_BLR_RESERVED_24_MASK                                                                            ((uint32)0xffffff00U)

/**
  * \brief  Auxiliary control register (UART_ACREG)
  */

#define UART_ACREG_EOT_EN_SHIFT                                                                              ((uint32)0U)
#define UART_ACREG_EOT_EN_MASK                                                                               ((uint32)0x00000001U)

#define UART_ACREG_ABORT_EN_SHIFT                                                                            ((uint32)1U)
#define UART_ACREG_ABORT_EN_MASK                                                                             ((uint32)0x00000002U)

#define UART_ACREG_SCTX_EN_SHIFT                                                                             ((uint32)2U)
#define UART_ACREG_SCTX_EN_MASK                                                                              ((uint32)0x00000004U)

#define UART_ACREG_SEND_SIP_SHIFT                                                                            ((uint32)3U)
#define UART_ACREG_SEND_SIP_MASK                                                                             ((uint32)0x00000008U)
#define UART_ACREG_SEND_SIP_SEND_SIP_VALUE_1                                                                 ((uint32)1U)
#define UART_ACREG_SEND_SIP_SEND_SIP_VALUE_0                                                                 ((uint32)0U)

#define UART_ACREG_DIS_TX_UNDERRUN_SHIFT                                                                     ((uint32)4U)
#define UART_ACREG_DIS_TX_UNDERRUN_MASK                                                                      ((uint32)0x00000010U)
#define UART_ACREG_DIS_TX_UNDERRUN_DIS_TX_UNDERRUN_VALUE_1                                                   ((uint32)1U)
#define UART_ACREG_DIS_TX_UNDERRUN_DIS_TX_UNDERRUN_VALUE_0                                                   ((uint32)0U)

#define UART_ACREG_DIS_IR_RX_SHIFT                                                                           ((uint32)5U)
#define UART_ACREG_DIS_IR_RX_MASK                                                                            ((uint32)0x00000020U)
#define UART_ACREG_DIS_IR_RX_DIS_IR_RX_VALUE_1                                                               ((uint32)1U)
#define UART_ACREG_DIS_IR_RX_DIS_IR_RX_VALUE_0                                                               ((uint32)0U)

#define UART_ACREG_SD_MOD_SHIFT                                                                              ((uint32)6U)
#define UART_ACREG_SD_MOD_MASK                                                                               ((uint32)0x00000040U)
#define UART_ACREG_SD_MOD_SD_MOD_VALUE_1                                                                     ((uint32)1U)
#define UART_ACREG_SD_MOD_SD_MOD_VALUE_0                                                                     ((uint32)0U)

#define UART_ACREG_PULSE_TYPE_SHIFT                                                                          ((uint32)7U)
#define UART_ACREG_PULSE_TYPE_MASK                                                                           ((uint32)0x00000080U)
#define UART_ACREG_PULSE_TYPE_PULSE_TYPE_VALUE_1                                                             ((uint32)1U)
#define UART_ACREG_PULSE_TYPE_PULSE_TYPE_VALUE_0                                                             ((uint32)0U)

#define UART_ACREG_RESERVED_24_SHIFT                                                                         ((uint32)8U)
#define UART_ACREG_RESERVED_24_MASK                                                                          ((uint32)0xffffff00U)

/**
  * \brief  Supplementary control register (UART_SCR)
  */

#define UART_SCR_DMA_MODE_CTL_SHIFT                                                                          ((uint32)0U)
#define UART_SCR_DMA_MODE_CTL_MASK                                                                           ((uint32)0x00000001U)
#define UART_SCR_DMA_MODE_CTL_DMA_MODE_CTL_VALUE_1                                                           ((uint32)1U)
#define UART_SCR_DMA_MODE_CTL_DMA_MODE_CTL_VALUE_0                                                           ((uint32)0U)

#define UART_SCR_DMA_MODE_2_SHIFT                                                                            ((uint32)1U)
#define UART_SCR_DMA_MODE_2_MASK                                                                             ((uint32)0x00000006U)
#define UART_SCR_DMA_MODE_2_DMA_MODE_2_VALUE_3                                                               ((uint32)3U)
#define UART_SCR_DMA_MODE_2_DMA_MODE_2_VALUE_2                                                               ((uint32)2U)
#define UART_SCR_DMA_MODE_2_DMA_MODE_2_VALUE_1                                                               ((uint32)1U)
#define UART_SCR_DMA_MODE_2_DMA_MODE_2_VALUE_0                                                               ((uint32)0U)

#define UART_SCR_TX_EMPTY_CTL_IT_SHIFT                                                                       ((uint32)3U)
#define UART_SCR_TX_EMPTY_CTL_IT_MASK                                                                        ((uint32)0x00000008U)
#define UART_SCR_TX_EMPTY_CTL_IT_TX_EMPTY_CTL_IT_VALUE_1                                                     ((uint32)1U)
#define UART_SCR_TX_EMPTY_CTL_IT_TX_EMPTY_CTL_IT_VALUE_0                                                     ((uint32)0U)

#define UART_SCR_RX_CTS_DSR_WAKE_UP_ENABLE_SHIFT                                                             ((uint32)4U)
#define UART_SCR_RX_CTS_DSR_WAKE_UP_ENABLE_MASK                                                              ((uint32)0x00000010U)
#define UART_SCR_RX_CTS_DSR_WAKE_UP_ENABLE_RX_CTS_DSR_WAKE_UP_ENABLE_VALUE_1                                 ((uint32)1U)
#define UART_SCR_RX_CTS_DSR_WAKE_UP_ENABLE_RX_CTS_DSR_WAKE_UP_ENABLE_VALUE_0                                 ((uint32)0U)

#define UART_SCR_DSR_IT_SHIFT                                                                                ((uint32)5U)
#define UART_SCR_DSR_IT_MASK                                                                                 ((uint32)0x00000020U)
#define UART_SCR_DSR_IT_DSR_IT_VALUE_1                                                                       ((uint32)1U)
#define UART_SCR_DSR_IT_DSR_IT_VALUE_0                                                                       ((uint32)0U)

#define UART_SCR_TX_TRIG_GRANU1_SHIFT                                                                        ((uint32)6U)
#define UART_SCR_TX_TRIG_GRANU1_MASK                                                                         ((uint32)0x00000040U)
#define UART_SCR_TX_TRIG_GRANU1_TX_TRIG_GRANU1_VALUE_1                                                       ((uint32)1U)
#define UART_SCR_TX_TRIG_GRANU1_TX_TRIG_GRANU1_VALUE_0                                                       ((uint32)0U)

#define UART_SCR_RX_TRIG_GRANU1_SHIFT                                                                        ((uint32)7U)
#define UART_SCR_RX_TRIG_GRANU1_MASK                                                                         ((uint32)0x00000080U)
#define UART_SCR_RX_TRIG_GRANU1_RX_TRIG_GRANU1_VALUE_1                                                       ((uint32)1U)
#define UART_SCR_RX_TRIG_GRANU1_RX_TRIG_GRANU1_VALUE_0                                                       ((uint32)0U)

#define UART_SCR_RESERVED_24_SHIFT                                                                           ((uint32)8U)
#define UART_SCR_RESERVED_24_MASK                                                                            ((uint32)0xffffff00U)

/**
  * \brief  Supplementary status register (UART_SSR)
  */

#define UART_SSR_TX_FIFO_FULL_SHIFT                                                                          ((uint32)0U)
#define UART_SSR_TX_FIFO_FULL_MASK                                                                           ((uint32)0x00000001U)
#define UART_SSR_TX_FIFO_FULL_TX_FIFO_FULL_VALUE_1                                                           ((uint32)1U)
#define UART_SSR_TX_FIFO_FULL_TX_FIFO_FULL_VALUE_0                                                           ((uint32)0U)

#define UART_SSR_RX_CTS_DSR_WAKE_UP_STS_SHIFT                                                                ((uint32)1U)
#define UART_SSR_RX_CTS_DSR_WAKE_UP_STS_MASK                                                                 ((uint32)0x00000002U)
#define UART_SSR_RX_CTS_DSR_WAKE_UP_STS_RX_CTS_DSR_WAKE_UP_STS_VALUE_1                                       ((uint32)1U)
#define UART_SSR_RX_CTS_DSR_WAKE_UP_STS_RX_CTS_DSR_WAKE_UP_STS_VALUE_0                                       ((uint32)0U)

#define UART_SSR_RESERVED_SHIFT                                                                              ((uint32)3U)
#define UART_SSR_RESERVED_MASK                                                                               ((uint32)0x000000f8U)

#define UART_SSR_RESERVED_24_SHIFT                                                                           ((uint32)8U)
#define UART_SSR_RESERVED_24_MASK                                                                            ((uint32)0xffffff00U)

#define UART_SSR_DMA_COUNTER_RST_SHIFT                                                                       ((uint32)2U)
#define UART_SSR_DMA_COUNTER_RST_MASK                                                                        ((uint32)0x00000004U)
#define UART_SSR_DMA_COUNTER_RST_DMA_COUNTER_RST_VALUE_0                                                     ((uint32)0U)
#define UART_SSR_DMA_COUNTER_RST_DMA_COUNTER_RST_VALUE_1                                                     ((uint32)1U)

/**
  * \brief  BOF length register (UART_EBLR)
  */

#define UART_EBLR_EBLR_SHIFT                                                                                 ((uint32)0U)
#define UART_EBLR_EBLR_MASK                                                                                  ((uint32)0x000000ffU)

#define UART_EBLR_RESERVED_24_SHIFT                                                                          ((uint32)8U)
#define UART_EBLR_RESERVED_24_MASK                                                                           ((uint32)0xffffff00U)

/**
  * \brief  Module version register (UART_MVR)
  */

#define UART_MVR_MINOR_SHIFT                                                                                 ((uint32)0U)
#define UART_MVR_MINOR_MASK                                                                                  ((uint32)0x0000003fU)

#define UART_MVR_CUSTOM_SHIFT                                                                                ((uint32)6U)
#define UART_MVR_CUSTOM_MASK                                                                                 ((uint32)0x000000c0U)

#define UART_MVR_MAJOR_SHIFT                                                                                 ((uint32)8U)
#define UART_MVR_MAJOR_MASK                                                                                  ((uint32)0x00000700U)

#define UART_MVR_RTL_SHIFT                                                                                   ((uint32)11U)
#define UART_MVR_RTL_MASK                                                                                    ((uint32)0x0000f800U)

#define UART_MVR_FUNC_SHIFT                                                                                  ((uint32)16U)
#define UART_MVR_FUNC_MASK                                                                                   ((uint32)0x0fff0000U)

#define UART_MVR_RESERVED_SHIFT                                                                              ((uint32)28U)
#define UART_MVR_RESERVED_MASK                                                                               ((uint32)0x30000000U)

#define UART_MVR_SCHEME_SHIFT                                                                                ((uint32)30U)
#define UART_MVR_SCHEME_MASK                                                                                 ((uint32)0xc0000000U)

/**
  * \brief  System configuration register (UART_SYSC)
  */

#define UART_SYSC_AUTOIDLE_SHIFT                                                                             ((uint32)0U)
#define UART_SYSC_AUTOIDLE_MASK                                                                              ((uint32)0x00000001U)
#define UART_SYSC_AUTOIDLE_AUTOIDLE_VALUE_1                                                                  ((uint32)1U)
#define UART_SYSC_AUTOIDLE_AUTOIDLE_VALUE_0                                                                  ((uint32)0U)

#define UART_SYSC_SOFTRESET_SHIFT                                                                            ((uint32)1U)
#define UART_SYSC_SOFTRESET_MASK                                                                             ((uint32)0x00000002U)
#define UART_SYSC_SOFTRESET_SOFTRESET_VALUE_1                                                                ((uint32)1U)
#define UART_SYSC_SOFTRESET_SOFTRESET_VALUE_0                                                                ((uint32)0U)

#define UART_SYSC_ENAWAKEUP_SHIFT                                                                            ((uint32)2U)
#define UART_SYSC_ENAWAKEUP_MASK                                                                             ((uint32)0x00000004U)
#define UART_SYSC_ENAWAKEUP_ENAWAKEUP_VALUE_1                                                                ((uint32)1U)
#define UART_SYSC_ENAWAKEUP_ENAWAKEUP_VALUE_0                                                                ((uint32)0U)

#define UART_SYSC_IDLEMODE_SHIFT                                                                             ((uint32)3U)
#define UART_SYSC_IDLEMODE_MASK                                                                              ((uint32)0x00000018U)
#define UART_SYSC_IDLEMODE_IDLEMODE_VALUE_3                                                                  ((uint32)3U)
#define UART_SYSC_IDLEMODE_IDLEMODE_VALUE_2                                                                  ((uint32)2U)
#define UART_SYSC_IDLEMODE_IDLEMODE_VALUE_1                                                                  ((uint32)1U)
#define UART_SYSC_IDLEMODE_IDLEMODE_VALUE_0                                                                  ((uint32)0U)

#define UART_SYSC_RESERVED_SHIFT                                                                             ((uint32)5U)
#define UART_SYSC_RESERVED_MASK                                                                              ((uint32)0x000000e0U)

#define UART_SYSC_RESERVED_24_SHIFT                                                                          ((uint32)8U)
#define UART_SYSC_RESERVED_24_MASK                                                                           ((uint32)0xffffff00U)

/**
  * \brief  System status register (UART_SYSS)
  */

#define UART_SYSS_RESETDONE_SHIFT                                                                            ((uint32)0U)
#define UART_SYSS_RESETDONE_MASK                                                                             ((uint32)0x00000001U)
#define UART_SYSS_RESETDONE_RESETDONE_VALUE_1                                                                ((uint32)1U)
#define UART_SYSS_RESETDONE_RESETDONE_VALUE_0                                                                ((uint32)0U)

#define UART_SYSS_RESERVED_SHIFT                                                                             ((uint32)1U)
#define UART_SYSS_RESERVED_MASK                                                                              ((uint32)0x000000feU)

#define UART_SYSS_RESERVED_24_SHIFT                                                                          ((uint32)8U)
#define UART_SYSS_RESERVED_24_MASK                                                                           ((uint32)0xffffff00U)

/**
  * \brief  Wake-up enable registe (UART_WER)
  */                                                                         

#define UART_WER_EVENT_0_CTS_ACTIVITY_SHIFT                                                                  ((uint32)0U)
#define UART_WER_EVENT_0_CTS_ACTIVITY_MASK                                                                   ((uint32)0x00000001U)
#define UART_WER_EVENT_0_CTS_ACTIVITY_EVENT_0_CTS_ACTIVITY_VALUE_1                                           ((uint32)1U)
#define UART_WER_EVENT_0_CTS_ACTIVITY_EVENT_0_CTS_ACTIVITY_VALUE_0                                           ((uint32)0U)

#define UART_WER_EVENT_1_DSR_ACTIVITY_SHIFT                                                                  ((uint32)1U)
#define UART_WER_EVENT_1_DSR_ACTIVITY_MASK                                                                   ((uint32)0x00000002U)
#define UART_WER_EVENT_1_DSR_ACTIVITY_EVENT_1_DSR_ACTIVITY_VALUE_1                                           ((uint32)1U)
#define UART_WER_EVENT_1_DSR_ACTIVITY_EVENT_1_DSR_ACTIVITY_VALUE_0                                           ((uint32)0U)

#define UART_WER_EVENT_2_RI_ACTIVITY_SHIFT                                                                   ((uint32)2U)
#define UART_WER_EVENT_2_RI_ACTIVITY_MASK                                                                    ((uint32)0x00000004U)
#define UART_WER_EVENT_2_RI_ACTIVITY_EVENT_2_RI_ACTIVITY_VALUE_1                                             ((uint32)1U)
#define UART_WER_EVENT_2_RI_ACTIVITY_EVENT_2_RI_ACTIVITY_VALUE_0                                             ((uint32)0U)

#define UART_WER_EVENT_3_DCD_CD_ACTIVITY_SHIFT                                                               ((uint32)3U)
#define UART_WER_EVENT_3_DCD_CD_ACTIVITY_MASK                                                                ((uint32)0x00000008U)
#define UART_WER_EVENT_3_DCD_CD_ACTIVITY_EVENT_3_DCD_CD_ACTIVITY_VALUE_1                                     ((uint32)1U)
#define UART_WER_EVENT_3_DCD_CD_ACTIVITY_EVENT_3_DCD_CD_ACTIVITY_VALUE_0                                     ((uint32)0U)

#define UART_WER_EVENT_4_RX_ACTIVITY_SHIFT                                                                   ((uint32)4U)
#define UART_WER_EVENT_4_RX_ACTIVITY_MASK                                                                    ((uint32)0x00000010U)
#define UART_WER_EVENT_4_RX_ACTIVITY_EVENT_4_RX_ACTIVITY_VALUE_1                                             ((uint32)1U)
#define UART_WER_EVENT_4_RX_ACTIVITY_EVENT_4_RX_ACTIVITY_VALUE_0                                             ((uint32)0U)

#define UART_WER_EVENT_5_RHR_INTERRUPT_SHIFT                                                                 ((uint32)5U)
#define UART_WER_EVENT_5_RHR_INTERRUPT_MASK                                                                  ((uint32)0x00000020U)
#define UART_WER_EVENT_5_RHR_INTERRUPT_EVENT_5_RHR_INTERRUPT_VALUE_1                                         ((uint32)1U)
#define UART_WER_EVENT_5_RHR_INTERRUPT_EVENT_5_RHR_INTERRUPT_VALUE_0                                         ((uint32)0U)

#define UART_WER_EVENT_6_RECEIVER_LINE_STATUS_INTERRUPT_SHIFT                                                ((uint32)6U)
#define UART_WER_EVENT_6_RECEIVER_LINE_STATUS_INTERRUPT_MASK                                                 ((uint32)0x00000040U)
#define UART_WER_EVENT_6_RECEIVER_LINE_STATUS_INTERRUPT_EVENT_6_RECEIVER_LINE_STATUS_INTERRUPT_VALUE_1       ((uint32)1U)
#define UART_WER_EVENT_6_RECEIVER_LINE_STATUS_INTERRUPT_EVENT_6_RECEIVER_LINE_STATUS_INTERRUPT_VALUE_0       ((uint32)0U)

#define UART_WER_EVENT_7_TX_WAKEUP_EN_SHIFT                                                                  ((uint32)7U)
#define UART_WER_EVENT_7_TX_WAKEUP_EN_MASK                                                                   ((uint32)0x00000080U)
#define UART_WER_EVENT_7_TX_WAKEUP_EN_EVENT_7_TX_WAKEUP_EN_VALUE_0                                           ((uint32)0U)
#define UART_WER_EVENT_7_TX_WAKEUP_EN_EVENT_7_TX_WAKEUP_EN_VALUE_1                                           ((uint32)1U)

#define UART_WER_RESERVED_24_SHIFT                                                                           ((uint32)8U)
#define UART_WER_RESERVED_24_MASK                                                                            ((uint32)0xffffff00U)

/**
  * \brief  Carrier frequency prescaler register (UART_CFPS)
  */

#define UART_CFPS_CFPS_SHIFT                                                                                 ((uint32)0U)
#define UART_CFPS_CFPS_MASK                                                                                  ((uint32)0x000000ffU)

#define UART_CFPS_RESERVED_24_SHIFT                                                                          ((uint32)8U)
#define UART_CFPS_RESERVED_24_MASK                                                                           ((uint32)0xffffff00U)

/**
  * \brief  RX FIFO level register (UART_RXFIFO_LVL)
  */

#define UART_RXFIFO_LVL_RXFIFO_LVL_SHIFT                                                                     ((uint32)0U)
#define UART_RXFIFO_LVL_RXFIFO_LVL_MASK                                                                      ((uint32)0x000000ffU)

#define UART_RXFIFO_LVL_RESERVED24_SHIFT                                                                     ((uint32)8U)
#define UART_RXFIFO_LVL_RESERVED24_MASK                                                                      ((uint32)0xffffff00U)

/**
  * \brief  TX FIFO level register (UART_TXFIFO_LVL)
  */

#define UART_TXFIFO_LVL_TXFIFO_LVL_SHIFT                                                                     ((uint32)0U)
#define UART_TXFIFO_LVL_TXFIFO_LVL_MASK                                                                      ((uint32)0x000000ffU)

#define UART_TXFIFO_LVL_RESERVED24_SHIFT                                                                     ((uint32)8U)
#define UART_TXFIFO_LVL_RESERVED24_MASK                                                                      ((uint32)0xffffff00U)

/**
  * \brief  Interrupt enable register 2  (UART_IER2)
  */

#define UART_IER2_EN_RXFIFO_EMPTY_SHIFT                                                                      ((uint32)0U)
#define UART_IER2_EN_RXFIFO_EMPTY_MASK                                                                       ((uint32)0x00000001U)

#define UART_IER2_EN_TXFIFO_EMPTY_SHIFT                                                                      ((uint32)1U)
#define UART_IER2_EN_TXFIFO_EMPTY_MASK                                                                       ((uint32)0x00000002U)

#define UART_IER2_RESERVED_SHIFT                                                                             ((uint32)2U)
#define UART_IER2_RESERVED_MASK                                                                              ((uint32)0x000000fcU)

#define UART_IER2_RESERVED1_SHIFT                                                                            ((uint32)8U)
#define UART_IER2_RESERVED1_MASK                                                                             ((uint32)0xffffff00U)

/**
  * \brief  Interrupt status register 2  (UART_ISR2)
  */

#define UART_ISR2_RXFIFO_EMPTY_STS_SHIFT                                                                     ((uint32)0U)
#define UART_ISR2_RXFIFO_EMPTY_STS_MASK                                                                      ((uint32)0x00000001U)
#define UART_ISR2_RXFIFO_EMPTY_STS_RXFIFO_EMPTY_STS_VALUE_0                                                  ((uint32)0U)
#define UART_ISR2_RXFIFO_EMPTY_STS_RXFIFO_EMPTY_STS_VALUE_1                                                  ((uint32)1U)

#define UART_ISR2_TXFIFO_EMPTY_STS_SHIFT                                                                     ((uint32)1U)
#define UART_ISR2_TXFIFO_EMPTY_STS_MASK                                                                      ((uint32)0x00000002U)
#define UART_ISR2_TXFIFO_EMPTY_STS_TXFIFO_EMPTY_STS_VALUE_0                                                  ((uint32)0U)
#define UART_ISR2_TXFIFO_EMPTY_STS_TXFIFO_EMPTY_STS_VALUE_1                                                  ((uint32)1U)

#define UART_ISR2_RESERVED_SHIFT                                                                             ((uint32)2U)
#define UART_ISR2_RESERVED_MASK                                                                              ((uint32)0x000000fcU)

#define UART_ISR2_RESERVED1_SHIFT                                                                            ((uint32)8U)
#define UART_ISR2_RESERVED1_MASK                                                                             ((uint32)0xffffff00U)

/**
  * \brief  Sample per bit selector register  (UART_FREQ_SEL)
  */

#define UART_FREQ_SEL_FREQ_SEL_SHIFT                                                                         ((uint32)0U)
#define UART_FREQ_SEL_FREQ_SEL_MASK                                                                          ((uint32)0x000000ffU)

#define UART_FREQ_SEL_RESERVED2_SHIFT                                                                        ((uint32)8U)
#define UART_FREQ_SEL_RESERVED2_MASK                                                                         ((uint32)0xffffff00U)

/**
  * \brief   (UART_ABAUD_SEL)
  */

#define UART_ABAUD_1ST_CHAR_RESERVED_SHIFT                                                                   ((uint32)0U)
#define UART_ABAUD_1ST_CHAR_RESERVED_MASK                                                                    ((uint32)0xffffffffU)

/**
  * \brief   (UART_BAUD_SEL)
  */

#define UART_BAUD_2ND_CHAR_RESERVED_SHIFT                                                                    ((uint32)0U)
#define UART_BAUD_2ND_CHAR_RESERVED_MASK                                                                     ((uint32)0xffffffffU)

/**
  * \brief  Mode definition register 3  (UART_MDR3)
  */

#define UART_MDR3_DISABLE_CIR_RX_DEMOD_SHIFT                                                                 ((uint32)0U)
#define UART_MDR3_DISABLE_CIR_RX_DEMOD_MASK                                                                  ((uint32)0x00000001U)
#define UART_MDR3_DISABLE_CIR_RX_DEMOD_DISABLE_CIR_RX_DEMOD_VALUE_0                                          ((uint32)0U)
#define UART_MDR3_DISABLE_CIR_RX_DEMOD_DISABLE_CIR_RX_DEMOD_VALUE_1                                          ((uint32)1U)

#define UART_MDR3_NONDEFAULT_FREQ_SHIFT                                                                      ((uint32)1U)
#define UART_MDR3_NONDEFAULT_FREQ_MASK                                                                       ((uint32)0x00000002U)

#define UART_MDR3_SET_DMA_TX_THRESHOLD_SHIFT                                                                 ((uint32)2U)
#define UART_MDR3_SET_DMA_TX_THRESHOLD_MASK                                                                  ((uint32)0x00000004U)

#define UART_MDR3_DIR_POL_SHIFT                                                                              ((uint32)3U)
#define UART_MDR3_DIR_POL_MASK                                                                               ((uint32)0x00000008U)

#define UART_MDR3_DIR_EN_SHIFT                                                                               ((uint32)4U)
#define UART_MDR3_DIR_EN_MASK                                                                                ((uint32)0x00000010U)

#define UART_MDR3_RESERVED1_SHIFT                                                                            ((uint32)5U)
#define UART_MDR3_RESERVED1_MASK                                                                             ((uint32)0x000000e0U)

#define UART_MDR3_RESERVED2_SHIFT                                                                            ((uint32)8U)
#define UART_MDR3_RESERVED2_MASK                                                                             ((uint32)0xffffff00U)

/**
  * \brief  TX DMA threshold level register  (UART_TX_DMA_THRESHOLD)
  */

#define UART_TX_DMA_THRESHOLD_TX_DMA_THRESHOLD_SHIFT                                                         ((uint32)0U)
#define UART_TX_DMA_THRESHOLD_TX_DMA_THRESHOLD_MASK                                                          ((uint32)0x0000001fU)

#define UART_TX_DMA_THRESHOLD_RESERVED_SHIFT                                                                 ((uint32)5U)
#define UART_TX_DMA_THRESHOLD_RESERVED_MASK                                                                  ((uint32)0x000000e0U)

#define UART_TX_DMA_THRESHOLD_RESERVED1_SHIFT                                                                ((uint32)8U)
#define UART_TX_DMA_THRESHOLD_RESERVED1_MASK                                                                 ((uint32)0xffffff00U)

/**
  * \brief  Baud clock divisor LSB value register  (UART_DLL)
  */

#define UART_DLL_CLOCK_LSB_SHIFT                                                                             ((uint32)0U)
#define UART_DLL_CLOCK_LSB_MASK                                                                              ((uint32)0x000000ffU)

#define UART_DLL_RESERVED_SHIFT                                                                              ((uint32)8U)
#define UART_DLL_RESERVED_MASK                                                                               ((uint32)0xffffff00U)

/**
  * \brief  IrDA mode interrupt enable register  (UART_IER_IRDA)
  */

#define UART_IER_IRDA_RHR_IT_SHIFT                                                                           ((uint32)0U)
#define UART_IER_IRDA_RHR_IT_MASK                                                                            ((uint32)0x00000001U)
#define UART_IER_IRDA_RHR_IT_RHR_IT_VALUE_1                                                                  ((uint32)1U)
#define UART_IER_IRDA_RHR_IT_RHR_IT_VALUE_0                                                                  ((uint32)0U)

#define UART_IER_IRDA_THR_IT_SHIFT                                                                           ((uint32)1U)
#define UART_IER_IRDA_THR_IT_MASK                                                                            ((uint32)0x00000002U)
#define UART_IER_IRDA_THR_IT_THR_IT_VALUE_1                                                                  ((uint32)1U)
#define UART_IER_IRDA_THR_IT_THR_IT_VALUE_0                                                                  ((uint32)0U)

#define UART_IER_IRDA_LAST_RX_BYTE_IT_SHIFT                                                                  ((uint32)2U)
#define UART_IER_IRDA_LAST_RX_BYTE_IT_MASK                                                                   ((uint32)0x00000004U)
#define UART_IER_IRDA_LAST_RX_BYTE_IT_LAST_RX_BYTE_IT_VALUE_1                                                ((uint32)1U)
#define UART_IER_IRDA_LAST_RX_BYTE_IT_LAST_RX_BYTE_IT_VALUE_0                                                ((uint32)0U)

#define UART_IER_IRDA_RX_OVERRUN_IT_SHIFT                                                                    ((uint32)3U)
#define UART_IER_IRDA_RX_OVERRUN_IT_MASK                                                                     ((uint32)0x00000008U)
#define UART_IER_IRDA_RX_OVERRUN_IT_RX_OVERRUN_IT_VALUE_1                                                    ((uint32)1U)
#define UART_IER_IRDA_RX_OVERRUN_IT_RX_OVERRUN_IT_VALUE_0                                                    ((uint32)0U)

#define UART_IER_IRDA_STS_FIFO_TRIG_IT_SHIFT                                                                 ((uint32)4U)
#define UART_IER_IRDA_STS_FIFO_TRIG_IT_MASK                                                                  ((uint32)0x00000010U)
#define UART_IER_IRDA_STS_FIFO_TRIG_IT_STS_FIFO_TRIG_IT_VALUE_1                                              ((uint32)1U)
#define UART_IER_IRDA_STS_FIFO_TRIG_IT_STS_FIFO_TRIG_IT_VALUE_0                                              ((uint32)0U)

#define UART_IER_IRDA_TX_STATUS_IT_SHIFT                                                                     ((uint32)5U)
#define UART_IER_IRDA_TX_STATUS_IT_MASK                                                                      ((uint32)0x00000020U)
#define UART_IER_IRDA_TX_STATUS_IT_TX_STATUS_VALUE_1                                                         ((uint32)1U)
#define UART_IER_IRDA_TX_STATUS_IT_TX_STATUS_VALUE_0                                                         ((uint32)0U)

#define UART_IER_IRDA_LINE_STS_IT_SHIFT                                                                      ((uint32)6U)
#define UART_IER_IRDA_LINE_STS_IT_MASK                                                                       ((uint32)0x00000040U)
#define UART_IER_IRDA_LINE_STS_IT_LINE_STS_IT_U_VALUE_1                                                      ((uint32)1U)
#define UART_IER_IRDA_LINE_STS_IT_LINE_STS_IT_U_VALUE_0                                                      ((uint32)0U)

#define UART_IER_IRDA_EOF_IT_SHIFT                                                                           ((uint32)7U)
#define UART_IER_IRDA_EOF_IT_MASK                                                                            ((uint32)0x00000080U)
#define UART_IER_IRDA_EOF_IT_EOF_IT_U_VALUE_1                                                                ((uint32)1U)
#define UART_IER_IRDA_EOF_IT_EOF_IT_U_VALUE_0                                                                ((uint32)0U)

#define UART_IER_IRDA_RESERVED_SHIFT                                                                         ((uint32)8U)
#define UART_IER_IRDA_RESERVED_MASK                                                                          ((uint32)0xffffff00U)

/**
  * \brief  CIR mode interrupt enable register  (UART_IER_CIR)
  */

#define UART_IER_CIR_RHR_IT_SHIFT                                                                            ((uint32)0U)
#define UART_IER_CIR_RHR_IT_MASK                                                                             ((uint32)0x00000001U)
#define UART_IER_CIR_RHR_IT_RHR_IT_VALUE_1                                                                   ((uint32)1U)
#define UART_IER_CIR_RHR_IT_RHR_IT_VALUE_0                                                                   ((uint32)0U)

#define UART_IER_CIR_THR_IT_SHIFT                                                                            ((uint32)1U)
#define UART_IER_CIR_THR_IT_MASK                                                                             ((uint32)0x00000002U)
#define UART_IER_CIR_THR_IT_THR_IT_VALUE_1                                                                   ((uint32)1U)
#define UART_IER_CIR_THR_IT_THR_IT_VALUE_0                                                                   ((uint32)0U)

#define UART_IER_CIR_RX_STOP_IT_SHIFT                                                                        ((uint32)2U)
#define UART_IER_CIR_RX_STOP_IT_MASK                                                                         ((uint32)0x00000004U)
#define UART_IER_CIR_RX_STOP_IT_RX_STOP_IT_U_VALUE_1                                                         ((uint32)1U)
#define UART_IER_CIR_RX_STOP_IT_RX_STOP_IT_U_VALUE_0                                                         ((uint32)0U)

#define UART_IER_CIR_RX_OVERRUN_IT_SHIFT                                                                     ((uint32)3U)
#define UART_IER_CIR_RX_OVERRUN_IT_MASK                                                                      ((uint32)0x00000008U)
#define UART_IER_CIR_RX_OVERRUN_IT_RX_OVERRUN_IT_U_VALUE_1                                                   ((uint32)1U)
#define UART_IER_CIR_RX_OVERRUN_IT_RX_OVERRUN_IT_U_VALUE_0                                                   ((uint32)0U)

#define UART_IER_CIR_RESERVED_1_SHIFT                                                                        ((uint32)4U)
#define UART_IER_CIR_RESERVED_1_MASK                                                                         ((uint32)0x00000010U)

#define UART_IER_CIR_TX_STATUS_IT_SHIFT                                                                      ((uint32)5U)
#define UART_IER_CIR_TX_STATUS_IT_MASK                                                                       ((uint32)0x00000020U)
#define UART_IER_CIR_TX_STATUS_IT_TX_STATUS_IT_U_VALUE_1                                                     ((uint32)1U)
#define UART_IER_CIR_TX_STATUS_IT_TX_STATUS_IT_U_VALUE_0                                                     ((uint32)0U)

#define UART_IER_CIR_RESERVED_2_SHIFT                                                                        ((uint32)6U)
#define UART_IER_CIR_RESERVED_2_MASK                                                                         ((uint32)0x000000c0U)

#define UART_IER_CIR_RESERVED_3_SHIFT                                                                        ((uint32)8U)
#define UART_IER_CIR_RESERVED_3_MASK                                                                         ((uint32)0xffffff00U)

/**
  * \brief  Baud clock divisor MSB value register  (UART_DLH)
  */

#define UART_DLH_CLOCK_MSB_SHIFT                                                                             ((uint32)0U)
#define UART_DLH_CLOCK_MSB_MASK                                                                              ((uint32)0x0000003fU)

#define UART_DLH_RESERVED_SHIFT                                                                              ((uint32)6U)
#define UART_DLH_RESERVED_MASK                                                                               ((uint32)0xffffffc0U)

/**
  * \brief  IrDA mode interrupt identification register  (UART_IIR_IRDA)
  */

#define UART_IIR_IRDA_RHR_IT_SHIFT                                                                           ((uint32)0U)
#define UART_IIR_IRDA_RHR_IT_MASK                                                                            ((uint32)0x00000001U)
#define UART_IIR_IRDA_RHR_IT_RHR_IT_VALUE_1                                                                  ((uint32)1U)
#define UART_IIR_IRDA_RHR_IT_RHR_IT_VALUE_0                                                                  ((uint32)0U)

#define UART_IIR_IRDA_THR_IT_SHIFT                                                                           ((uint32)1U)
#define UART_IIR_IRDA_THR_IT_MASK                                                                            ((uint32)0x00000002U)
#define UART_IIR_IRDA_THR_IT_THR_IT_VALUE_1                                                                  ((uint32)1U)
#define UART_IIR_IRDA_THR_IT_THR_IT_VALUE_0                                                                  ((uint32)0U)

#define UART_IIR_IRDA_RX_FIFO_LAST_BYTE_IT_SHIFT                                                             ((uint32)2U)
#define UART_IIR_IRDA_RX_FIFO_LAST_BYTE_IT_MASK                                                              ((uint32)0x00000004U)
#define UART_IIR_IRDA_RX_FIFO_LAST_BYTE_IT_RX_FIFO_LAST_BYTE_IT_U_VALUE_1                                    ((uint32)1U)
#define UART_IIR_IRDA_RX_FIFO_LAST_BYTE_IT_RX_FIFO_LAST_BYTE_IT_U_VALUE_0                                    ((uint32)0U)

#define UART_IIR_IRDA_RX_OE_IT_SHIFT                                                                         ((uint32)3U)
#define UART_IIR_IRDA_RX_OE_IT_MASK                                                                          ((uint32)0x00000008U)
#define UART_IIR_IRDA_RX_OE_IT_RX_OE_IT_U_VALUE_1                                                            ((uint32)1U)
#define UART_IIR_IRDA_RX_OE_IT_RX_OE_IT_U_VALUE_0                                                            ((uint32)0U)

#define UART_IIR_IRDA_STS_FIFO_IT_SHIFT                                                                      ((uint32)4U)
#define UART_IIR_IRDA_STS_FIFO_IT_MASK                                                                       ((uint32)0x00000010U)
#define UART_IIR_IRDA_STS_FIFO_IT_STS_FIFO_IT_U_VALUE_1                                                      ((uint32)1U)
#define UART_IIR_IRDA_STS_FIFO_IT_STS_FIFO_IT_U_VALUE_0                                                      ((uint32)0U)

#define UART_IIR_IRDA_TX_STATUS_IT_SHIFT                                                                     ((uint32)5U)
#define UART_IIR_IRDA_TX_STATUS_IT_MASK                                                                      ((uint32)0x00000020U)
#define UART_IIR_IRDA_TX_STATUS_IT_TX_STATUS_IT_U_VALUE_1                                                    ((uint32)1U)
#define UART_IIR_IRDA_TX_STATUS_IT_TX_STATUS_IT_U_VALUE_0                                                    ((uint32)0U)

#define UART_IIR_IRDA_LINE_STS_IT_SHIFT                                                                      ((uint32)6U)
#define UART_IIR_IRDA_LINE_STS_IT_MASK                                                                       ((uint32)0x00000040U)
#define UART_IIR_IRDA_LINE_STS_IT_LINE_STS_IT_U_VALUE_1                                                      ((uint32)1U)
#define UART_IIR_IRDA_LINE_STS_IT_LINE_STS_IT_U_VALUE_0                                                      ((uint32)0U)

#define UART_IIR_IRDA_EOF_IT_SHIFT                                                                           ((uint32)7U)
#define UART_IIR_IRDA_EOF_IT_MASK                                                                            ((uint32)0x00000080U)
#define UART_IIR_IRDA_EOF_IT_EOF_IT_U_VALUE_1                                                                ((uint32)1U)
#define UART_IIR_IRDA_EOF_IT_EOF_IT_U_VALUE_0                                                                ((uint32)0U)

#define UART_IIR_IRDA_RESERVED_SHIFT                                                                         ((uint32)8U)
#define UART_IIR_IRDA_RESERVED_MASK                                                                          ((uint32)0xffffff00U)

/**
  * \brief  CIR mode interrupt identification register  (UART_IIR_CIR)
  */

#define UART_IIR_CIR_RHR_IT_SHIFT                                                                            ((uint32)0U)
#define UART_IIR_CIR_RHR_IT_MASK                                                                             ((uint32)0x00000001U)
#define UART_IIR_CIR_RHR_IT_RHR_IT_VALUE_1                                                                   ((uint32)1U)
#define UART_IIR_CIR_RHR_IT_RHR_IT_VALUE_0                                                                   ((uint32)0U)

#define UART_IIR_CIR_THR_IT_SHIFT                                                                            ((uint32)1U)
#define UART_IIR_CIR_THR_IT_MASK                                                                             ((uint32)0x00000002U)
#define UART_IIR_CIR_THR_IT_THR_IT_VALUE_1                                                                   ((uint32)1U)
#define UART_IIR_CIR_THR_IT_THR_IT_VALUE_0                                                                   ((uint32)0U)

#define UART_IIR_CIR_RX_STOP_IT_SHIFT                                                                        ((uint32)2U)
#define UART_IIR_CIR_RX_STOP_IT_MASK                                                                         ((uint32)0x00000004U)
#define UART_IIR_CIR_RX_STOP_IT_RX_STOP_IT_U_VALUE_1                                                         ((uint32)1U)
#define UART_IIR_CIR_RX_STOP_IT_RX_STOP_IT_U_VALUE_0                                                         ((uint32)0U)

#define UART_IIR_CIR_RX_OE_IT_SHIFT                                                                          ((uint32)3U)
#define UART_IIR_CIR_RX_OE_IT_MASK                                                                           ((uint32)0x00000008U)
#define UART_IIR_CIR_RX_OE_IT_RX_OE_IT_U_VALUE_1                                                             ((uint32)1U)
#define UART_IIR_CIR_RX_OE_IT_RX_OE_IT_U_VALUE_0                                                             ((uint32)0U)

#define UART_IIR_CIR_RESERVED_1_SHIFT                                                                        ((uint32)4U)
#define UART_IIR_CIR_RESERVED_1_MASK                                                                         ((uint32)0x00000010U)

#define UART_IIR_CIR_TX_STATUS_IT_SHIFT                                                                      ((uint32)5U)
#define UART_IIR_CIR_TX_STATUS_IT_MASK                                                                       ((uint32)0x00000020U)
#define UART_IIR_CIR_TX_STATUS_IT_TX_STATUS_IT_U_VALUE_1                                                     ((uint32)1U)
#define UART_IIR_CIR_TX_STATUS_IT_TX_STATUS_IT_U_VALUE_0                                                     ((uint32)0U)

#define UART_IIR_CIR_RESERVED_2_SHIFT                                                                        ((uint32)6U)
#define UART_IIR_CIR_RESERVED_2_MASK                                                                         ((uint32)0x000000c0U)

#define UART_IIR_CIR_RESERVED_SHIFT                                                                          ((uint32)8U)
#define UART_IIR_CIR_RESERVED_MASK                                                                           ((uint32)0xffffff00U)

/**
  * \brief  Enhanced feature register  (UART_EFR)
  */

#define UART_EFR_SW_FLOW_CONTROL_SHIFT                                                                       ((uint32)0U)
#define UART_EFR_SW_FLOW_CONTROL_MASK                                                                        ((uint32)0x0000000fU)
#define UART_EFR_SW_FLOW_CONTROL_SW_FLOW_CONTROL_U_VALUE_15                                                  ((uint32)15U)
#define UART_EFR_SW_FLOW_CONTROL_SW_FLOW_CONTROL_U_VALUE_14                                                  ((uint32)14U)
#define UART_EFR_SW_FLOW_CONTROL_SW_FLOW_CONTROL_U_VALUE_13                                                  ((uint32)13U)
#define UART_EFR_SW_FLOW_CONTROL_SW_FLOW_CONTROL_U_VALUE_12                                                  ((uint32)12U)
#define UART_EFR_SW_FLOW_CONTROL_SW_FLOW_CONTROL_U_VALUE_11                                                  ((uint32)11U)
#define UART_EFR_SW_FLOW_CONTROL_SW_FLOW_CONTROL_U_VALUE_10                                                  ((uint32)10U)
#define UART_EFR_SW_FLOW_CONTROL_SW_FLOW_CONTROL_U_VALUE_9                                                   ((uint32)9U)
#define UART_EFR_SW_FLOW_CONTROL_SW_FLOW_CONTROL_U_VALUE_8                                                   ((uint32)8U)
#define UART_EFR_SW_FLOW_CONTROL_SW_FLOW_CONTROL_U_VALUE_7                                                   ((uint32)7U)
#define UART_EFR_SW_FLOW_CONTROL_SW_FLOW_CONTROL_U_VALUE_6                                                   ((uint32)6U)
#define UART_EFR_SW_FLOW_CONTROL_SW_FLOW_CONTROL_U_VALUE_5                                                   ((uint32)5U)
#define UART_EFR_SW_FLOW_CONTROL_SW_FLOW_CONTROL_U_VALUE_4                                                   ((uint32)4U)
#define UART_EFR_SW_FLOW_CONTROL_SW_FLOW_CONTROL_U_VALUE_3                                                   ((uint32)3U)
#define UART_EFR_SW_FLOW_CONTROL_SW_FLOW_CONTROL_U_VALUE_2                                                   ((uint32)2U)
#define UART_EFR_SW_FLOW_CONTROL_SW_FLOW_CONTROL_U_VALUE_1                                                   ((uint32)1U)
#define UART_EFR_SW_FLOW_CONTROL_SW_FLOW_CONTROL_U_VALUE_0                                                   ((uint32)0U)

#define UART_EFR_HW_FLOW_CONTROL_SHIFT                                                                       ((uint32)6U)
#define UART_EFR_HW_FLOW_CONTROL_MASK                                                                        ((uint32)0x000000C0U)
#define UART_EFR_HW_NO_FLOW_CONTROL_VALUE                                                                    ((uint32)0U)
#define UART_EFR_HW_ENABLE_RTS_FLOW_CONTROL_VALUE                                                            ((uint32)1U)
#define UART_EFR_HW_ENALE_CTS_FLOW_CONTROL_VALUE                                                             ((uint32)2U)
#define UART_EFR_HW_ENABLE_RTS_CTS_FLOW_CONTROL_VALUE                                                        ((uint32)3U)

#define UART_EFR_ENHANCED_EN_SHIFT                                                                           ((uint32)4U)
#define UART_EFR_ENHANCED_EN_MASK                                                                            ((uint32)0x00000010U)
#define UART_EFR_ENHANCED_EN_ENHANCED_EN_U_VALUE_1                                                           ((uint32)1U)
#define UART_EFR_ENHANCED_EN_ENHANCED_EN_U_VALUE_0                                                           ((uint32)0U)

#define UART_EFR_SPECIAL_CHAR_DETECT_SHIFT                                                                   ((uint32)5U)
#define UART_EFR_SPECIAL_CHAR_DETECT_MASK                                                                    ((uint32)0x00000020U)
#define UART_EFR_SPECIAL_CHAR_DETECT_SPECIAL_CHAR_DETECT_U_VALUE_1                                           ((uint32)1U)
#define UART_EFR_SPECIAL_CHAR_DETECT_SPECIAL_CHAR_DETECT_U_VALUE_0                                           ((uint32)0U)

#define UART_EFR_AUTO_RTS_EN_SHIFT                                                                           ((uint32)6U)
#define UART_EFR_AUTO_RTS_EN_MASK                                                                            ((uint32)0x00000040U)
#define UART_EFR_AUTO_RTS_EN_AUTO_RTS_EN_U_VALUE_1                                                           ((uint32)1U)
#define UART_EFR_AUTO_RTS_EN_AUTO_RTS_EN_U_VALUE_0                                                           ((uint32)0U)

#define UART_EFR_AUTO_CTS_EN_SHIFT                                                                           ((uint32)7U)
#define UART_EFR_AUTO_CTS_EN_MASK                                                                            ((uint32)0x00000080U)
#define UART_EFR_AUTO_CTS_EN_AUTO_CTS_EN_U_VALUE_1                                                           ((uint32)1U)
#define UART_EFR_AUTO_CTS_EN_AUTO_CTS_EN_U_VALUE_0                                                           ((uint32)0U)

#define UART_EFR_RESERVED_SHIFT                                                                              ((uint32)8U)
#define UART_EFR_RESERVED_MASK                                                                               ((uint32)0xffffff00U)

/**
  * \brief  UART mode XON1 character, IrDA mode 
              ADDR1 address register  (UART_XON1_ADDR1)
  */

#define UART_XON1_ADDR1_XON_WORD1_SHIFT                                                                      ((uint32)0U)
#define UART_XON1_ADDR1_XON_WORD1_MASK                                                                       ((uint32)0x000000ffU)

#define UART_XON1_ADDR1_RESERVED_24_SHIFT                                                                    ((uint32)8U)
#define UART_XON1_ADDR1_RESERVED_24_MASK                                                                     ((uint32)0xffffff00U)

/**
  * \brief  IrDA mode line status register (UART_LSR_IRDA)
  */

#define UART_LSR_IRDA_RX_FIFO_E_SHIFT                                                                        ((uint32)0U)
#define UART_LSR_IRDA_RX_FIFO_E_MASK                                                                         ((uint32)0x00000001U)
#define UART_LSR_IRDA_RX_FIFO_E_RX_FIFO_E_VALUE_1                                                            ((uint32)1U)
#define UART_LSR_IRDA_RX_FIFO_E_RX_FIFO_E_VALUE_0                                                            ((uint32)0U)

#define UART_LSR_IRDA_STS_FIFO_E_SHIFT                                                                       ((uint32)1U)
#define UART_LSR_IRDA_STS_FIFO_E_MASK                                                                        ((uint32)0x00000002U)
#define UART_LSR_IRDA_STS_FIFO_E_STS_FIFO_E_VALUE_1                                                          ((uint32)1U)
#define UART_LSR_IRDA_STS_FIFO_E_STS_FIFO_E_VALUE_0                                                          ((uint32)0U)

#define UART_LSR_IRDA_CRC_SHIFT                                                                              ((uint32)2U)
#define UART_LSR_IRDA_CRC_MASK                                                                               ((uint32)0x00000004U)
#define UART_LSR_IRDA_CRC_CRC_VALUE_1                                                                        ((uint32)1U)
#define UART_LSR_IRDA_CRC_CRC_VALUE_0                                                                        ((uint32)0U)

#define UART_LSR_IRDA_ABORT_SHIFT                                                                            ((uint32)3U)
#define UART_LSR_IRDA_ABORT_MASK                                                                             ((uint32)0x00000008U)
#define UART_LSR_IRDA_ABORT_ABORT_VALUE_1                                                                    ((uint32)1U)
#define UART_LSR_IRDA_ABORT_ABORT_VALUE_0                                                                    ((uint32)0U)

#define UART_LSR_IRDA_FRAME_TOO_LONG_SHIFT                                                                   ((uint32)4U)
#define UART_LSR_IRDA_FRAME_TOO_LONG_MASK                                                                    ((uint32)0x00000010U)
#define UART_LSR_IRDA_FRAME_TOO_LONG_FRAME_TOO_LONG_VALUE_1                                                  ((uint32)1U)
#define UART_LSR_IRDA_FRAME_TOO_LONG_FRAME_TOO_LONG_VALUE_0                                                  ((uint32)0U)

#define UART_LSR_IRDA_RX_LAST_BYTE_SHIFT                                                                     ((uint32)5U)
#define UART_LSR_IRDA_RX_LAST_BYTE_MASK                                                                      ((uint32)0x00000020U)
#define UART_LSR_IRDA_RX_LAST_BYTE_RX_LAST_BYTE_VALUE_1                                                      ((uint32)1U)
#define UART_LSR_IRDA_RX_LAST_BYTE_RX_LAST_BYTE_VALUE_0                                                      ((uint32)0U)

#define UART_LSR_IRDA_STS_FIFO_FULL_SHIFT                                                                    ((uint32)6U)
#define UART_LSR_IRDA_STS_FIFO_FULL_MASK                                                                     ((uint32)0x00000040U)
#define UART_LSR_IRDA_STS_FIFO_FULL_STS_FIFO_FULL_VALUE_1                                                    ((uint32)1U)
#define UART_LSR_IRDA_STS_FIFO_FULL_STS_FIFO_FULL_VALUE_0                                                    ((uint32)0U)

#define UART_LSR_IRDA_THR_EMPTY_SHIFT                                                                        ((uint32)7U)
#define UART_LSR_IRDA_THR_EMPTY_MASK                                                                         ((uint32)0x00000080U)
#define UART_LSR_IRDA_THR_EMPTY_THR_EMPTY_VALUE_1                                                            ((uint32)1U)
#define UART_LSR_IRDA_THR_EMPTY_THR_EMPTY_VALUE_0                                                            ((uint32)0U)

#define UART_LSR_IRDA_RESERVED_24_SHIFT                                                                      ((uint32)8U)
#define UART_LSR_IRDA_RESERVED_24_MASK                                                                       ((uint32)0xffffff00U)

/**
  * \brief  CIR mode line status register (UART_LSR_CIR)
  */

#define UART_LSR_CIR_RX_FIFO_E_SHIFT                                                                         ((uint32)0U)
#define UART_LSR_CIR_RX_FIFO_E_MASK                                                                          ((uint32)0x00000001U)
#define UART_LSR_CIR_RX_FIFO_E_RX_FIFO_E_VALUE_1                                                             ((uint32)1U)
#define UART_LSR_CIR_RX_FIFO_E_RX_FIFO_E_VALUE_0                                                             ((uint32)0U)

#define UART_LSR_CIR_RESERVED_SHIFT                                                                          ((uint32)1U)
#define UART_LSR_CIR_RESERVED_MASK                                                                           ((uint32)0x0000001eU)

#define UART_LSR_CIR_RX_STOP_SHIFT                                                                           ((uint32)5U)
#define UART_LSR_CIR_RX_STOP_MASK                                                                            ((uint32)0x00000020U)
#define UART_LSR_CIR_RX_STOP_RX_STOP_VALUE_1                                                                 ((uint32)1U)
#define UART_LSR_CIR_RX_STOP_RX_STOP_VALUE_0                                                                 ((uint32)0U)

#define UART_LSR_CIR_RESERVED_1_SHIFT                                                                        ((uint32)6U)
#define UART_LSR_CIR_RESERVED_1_MASK                                                                         ((uint32)0x00000040U)

#define UART_LSR_CIR_THR_EMPTY_SHIFT                                                                         ((uint32)7U)
#define UART_LSR_CIR_THR_EMPTY_MASK                                                                          ((uint32)0x00000080U)
#define UART_LSR_CIR_THR_EMPTY_THR_EMPTY_VALUE_1                                                             ((uint32)1U)
#define UART_LSR_CIR_THR_EMPTY_THR_EMPTY_VALUE_0                                                             ((uint32)0U)

#define UART_LSR_CIR_RESERVED_24_SHIFT                                                                       ((uint32)8U)
#define UART_LSR_CIR_RESERVED_24_MASK                                                                        ((uint32)0xffffff00U)

/**
  * \brief  UART mode XON2 character, IrDA mode 
           ADDR2 address register (UART_XON2_ADDR2)
  */

#define UART_XON2_ADDR2_XON_WORD2_SHIFT                                                                      ((uint32)0U)
#define UART_XON2_ADDR2_XON_WORD2_MASK                                                                       ((uint32)0x000000ffU)

#define UART_XON2_ADDR2_RESERVED_24_SHIFT                                                                    ((uint32)8U)
#define UART_XON2_ADDR2_RESERVED_24_MASK                                                                     ((uint32)0xffffff00U)

/**
  * \brief  UART mode XOFF1 character (UART_XOFF1)
  */

#define UART_XOFF1_XOFF_WORD1_SHIFT                                                                          ((uint32)0U)
#define UART_XOFF1_XOFF_WORD1_MASK                                                                           ((uint32)0x000000ffU)

#define UART_XOFF1_RESERVED_24_SHIFT                                                                         ((uint32)8U)
#define UART_XOFF1_RESERVED_24_MASK                                                                          ((uint32)0xffffff00U)

/**
  * \brief  Transmission control register (UART_TCR)
  */

#define UART_TCR_RX_FIFO_TRIG_HALT_SHIFT                                                                     ((uint32)0U)
#define UART_TCR_RX_FIFO_TRIG_HALT_MASK                                                                      ((uint32)0x0000000fU)

#define UART_TCR_RX_FIFO_TRIG_START_SHIFT                                                                    ((uint32)4U)
#define UART_TCR_RX_FIFO_TRIG_START_MASK                                                                     ((uint32)0x000000f0U)

#define UART_TCR_RESERVED_24_SHIFT                                                                           ((uint32)8U)
#define UART_TCR_RESERVED_24_MASK                                                                            ((uint32)0xffffff00U)

/**
  * \brief  UART mode XOFF2 character (UART_XOFF2)
  */

#define UART_XOFF2_XOFF_WORD2_SHIFT                                                                          ((uint32)0U)
#define UART_XOFF2_XOFF_WORD2_MASK                                                                           ((uint32)0x000000ffU)

#define UART_XOFF2_RESERVED_24_SHIFT                                                                         ((uint32)8U)
#define UART_XOFF2_RESERVED_24_MASK                                                                          ((uint32)0xffffff00U)

/**
  * \brief  Trigger level register (UART_TLR)
  */
#define UART_TLR_TX_FIFO_TRIG_DMA_SHIFT                                                                      ((uint32)0U)
#define UART_TLR_TX_FIFO_TRIG_DMA_MASK                                                                       ((uint32)0x0000000fU)

#define UART_TLR_RX_FIFO_TRIG_DMA_SHIFT                                                                      ((uint32)4U)
#define UART_TLR_RX_FIFO_TRIG_DMA_MASK                                                                       ((uint32)0x000000f0U)

#define UART_TLR_RESERVED_24_SHIFT                                                                           ((uint32)8U)
#define UART_TLR_RESERVED_24_MASK                                                                            ((uint32)0xffffff00U)

/**
  * \brief  UART autobauding status register (UART_UASR)
  */

#define UART_UASR_SPEED_SHIFT                                                                                ((uint32)0U)
#define UART_UASR_SPEED_MASK                                                                                 ((uint32)0x0000001fU)
#define UART_UASR_SPEED_SPEED_VALUE_10                                                                       ((uint32)10U)
#define UART_UASR_SPEED_SPEED_VALUE_9                                                                        ((uint32)9U)
#define UART_UASR_SPEED_SPEED_VALUE_8                                                                        ((uint32)8U)
#define UART_UASR_SPEED_SPEED_VALUE_7                                                                        ((uint32)7U)
#define UART_UASR_SPEED_SPEED_VALUE_6                                                                        ((uint32)6U)
#define UART_UASR_SPEED_SPEED_VALUE_5                                                                        ((uint32)5U)
#define UART_UASR_SPEED_SPEED_VALUE_4                                                                        ((uint32)4U)
#define UART_UASR_SPEED_SPEED_VALUE_3                                                                        ((uint32)3U)
#define UART_UASR_SPEED_SPEED_VALUE_2                                                                        ((uint32)2U)
#define UART_UASR_SPEED_SPEED_VALUE_1                                                                        ((uint32)1U)
#define UART_UASR_SPEED_SPEED_VALUE_0                                                                        ((uint32)0U)

#define UART_UASR_BIT_BY_CHAR_SHIFT                                                                          ((uint32)5U)
#define UART_UASR_BIT_BY_CHAR_MASK                                                                           ((uint32)0x00000020U)
#define UART_UASR_BIT_BY_CHAR_BIT_BY_CHAR_U_VALUE_1                                                          ((uint32)1U)
#define UART_UASR_BIT_BY_CHAR_BIT_BY_CHAR_U_VALUE_0                                                          ((uint32)0U)

#define UART_UASR_PARITY_TYPE_SHIFT                                                                          ((uint32)6U)
#define UART_UASR_PARITY_TYPE_MASK                                                                           ((uint32)0x000000c0U)
#define UART_UASR_PARITY_TYPE_PARITY_TYPE_U_VALUE_3                                                          ((uint32)3U)
#define UART_UASR_PARITY_TYPE_PARITY_TYPE_U_VALUE_2                                                          ((uint32)2U)
#define UART_UASR_PARITY_TYPE_PARITY_TYPE_U_VALUE_1                                                          ((uint32)1U)
#define UART_UASR_PARITY_TYPE_PARITY_TYPE_U_VALUE_0                                                          ((uint32)0U)

#define UART_UASR_RESERVED_24_SHIFT                                                                          ((uint32)8U)
#define UART_UASR_RESERVED_24_MASK                                                                           ((uint32)0xffffff00U)


/*******************************************************************************
*                                    SCI/UART
*******************************************************************************/

#define MCU_UART0_BASE_ADDR											  (0x04a00000UL) /*Hw Channel No - 0*/
#define WKUP_UART0_BASE_ADDR										  (0x2b300000UL) /*Hw Channel No - 1*/
#define UART0_BASE_ADDR                           (0x02800000UL) /*Hw Channel No - 2*/
#define UART1_BASE_ADDR													  (0x02810000UL) /*Hw Channel No - 3*/
#define UART2_BASE_ADDR													  (0x02820000UL) /*Hw Channel No - 4*/
#define UART3_BASE_ADDR													  (0x02830000UL) /*Hw Channel No - 5*/
#define UART4_BASE_ADDR												    (0x02840000UL) /*Hw Channel No - 6*/
#define UART5_BASE_ADDR													  (0x02850000UL) /*Hw Channel No - 7*/
#define UART6_BASE_ADDR													  (0x02860000UL) /*Hw Channel No - 8*/



/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/



/*        SCI Channel Data Length            */

#define SCIDRV_TRANSFER_WIDTH_5BITS        (0u)
#define SCIDRV_TRANSFER_WIDTH_6BITS        (1u)
#define SCIDRV_TRANSFER_WIDTH_7BITS        (2u)
#define SCIDRV_TRANSFER_WIDTH_8BITS        (3u)

/*         SCI Channel Parity Setting         */

#define SCIDRV_PARITY_NONE                 (0x00u)
#define SCIDRV_PARITY_ODD                  (0x01u)
#define SCIDRV_PARITY_EVEN                 (0x03u)


/*        SCI Channel No of stop bits        */

#define SCIDRV_STOPBITS_1BIT               (0u)
#define SCIDRV_STOPBITS_2BIT               (1u)

/*        SCI Channel Rx Trigger Level       */

#define SCIDRV_RXTRIGLVL_1                (1U)
#define SCIDRV_RXTRIGLVL_8                (8U)
#define SCIDRV_RXTRIGLVL_16               (16U)
#define SCIDRV_RXTRIGLVL_56               (56U)
#define SCIDRV_RXTRIGLVL_60               (60U)

/*        SCI Channel Tx Trigger Level       */


#define SCIDRV_TXTRIGLVL_1                (1U)
#define SCIDRV_TXTRIGLVL_8                (8U)
#define SCIDRV_TXTRIGLVL_16               (16U)
#define SCIDRV_TXTRIGLVL_32               (32U)
#define SCIDRV_TXTRIGLVL_56               (56U)

/*         SCI Channel Operational Mode      */

#define SCIDRV_OPER_MODE_16X              (0U)
#define SCIDRV_OPER_MODE_13X              (3U)
#define SCIDRV_OPER_MODE_DISABLED         (7U)

/*         SCI Channel Transfer Mode         */

#define SCIDRV_CONFIG_MODE_POLLED       (0x00U)
#define SCIDRV_CONFIG_MODE_INTERRUPT    (0x01U)
#define SCIDRV_CONFIG_MODE_DMA          (0x02U)

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/* 
*   @brief Sci driver channel ID.
*/

typedef uint8  TSciDrvChn;

/*
*   @brief Enum holding the state of SCI driver.
*/

typedef enum  {
    // The SCI Driver is not initialized or not usable
    eSciDrvStatus_Uninit,
    // The SCI Driver is ready for use
    eSciDrvStatus_Ready,
    // Last Entry
    eSciDrvStatus_Last
} ESciDrvStatus;

/*
*    @brief Enum holding the status of SCI channel job.
*/

typedef enum  {
    // The last transfer on the SCI Channel has been finished successfully
    eSciDrvChnResult_Ok,
    // The SCI Driver is performing a transfer on the SCI Channel
    eSciDrvChnResult_Busy,
    // The last transfer on the SCI Channel has failed
    eSciDrvChnResult_Failed,
    // The last transfer on the SCI Channel has been cancelled by user
    eSciDrvChnResult_Cancelled,
    // Last Entry
    eSciDrvChnResult_Last
} ESciDrvChnResult;


/*   
*    @brief Enum holding the Async mode of SCI channel.
*/

typedef enum  {
    // The SCI driver will use polling mode to perform the Aysnc Transfer
    eSciDrvAsyncMode_Polling,
    // The SCI driver will use Interrupt to perform the Aysnc Transfer
    eSciDrvAsyncMode_Interrupt,
    // The SCI driver will use DMA to perform the Aysnc Transfer
    eSciDrvAsyncMode_Dma,
    // Last Entry
    eSciDrvAsyncMode_Last
} ESciDrvAsyncMode;

/*  
*    @brief Enum holding the Sync mode of SCI channel.
*/

typedef enum  {
    // The SCI driver will use polling mode to perform the Sync Transfer
    eSciDrvSyncMode_Polling,
    // Last Entry
    eSciDrvSyncMode_Last
} ESciDrvSyncMode;

/*    
*    @brief Enum holding the Direction of SCI channel.
*/

typedef enum  {
    // Receive direction
    eSciDrvDirection_Receive,
    // Transmit direction
    eSciDrvDirection_Transmit,
    // Last Entry
    eSciDrvDirection_Last
} ESciDrvDirection;

#endif /* SCIDRV_TYPES_H */

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
/*Date              : 10-02-2024                                            */
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