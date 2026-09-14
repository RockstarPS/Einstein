/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2024. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/

/******************************************************************************

File Name        :  SciDrv_Cfg.c
Module Short Name:  SciDrv_Cfg.c
VOBName          :
Author           :  sdv
Description      :  This file contains configurations needed for SciDrv module
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/
#ifndef SCIDRV_CFG_C
#define SCIDRV_CFG_C
/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "SciDrv_Cfg.h"
#include "SciDrv.h"
#include "DltExt.h"

/*****************************************************************************
 *                        Globally  accessed Variable Declarations            *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

const SSciDrvChnCfg SciDrvChnCfg[SCIDRV_MAX_CHANNELS] =
    {
        {
            MCU_UART0_BASE_ADDR,
            SCIDRV_INPUT_CLOCK_FREQ_HZ,
            DltExt_Uart_TxComplete,
            Client_PhyReceiveCallback,
            0,                           // UART HW Channel
            115200,                      // SCI Baud Rate in bps
            SCIDRV_TRANSFER_WIDTH_8BITS, // SCI Data Length
            SCIDRV_STOPBITS_1BIT,        // SCI No of Stops Bits Per Frame
            SCIDRV_PARITY_NONE,          // SCI Parity level
            SCIDRV_OPER_MODE_16X,        // SCI Operational mode
            SCIDRV_RXTRIGLVL_8,          // SCI Rx Trigger Level
            SCIDRV_TXTRIGLVL_32,         // SCI Tx Trigger Level
            FALSE                        // Hw Flow Control
        },
        {
            #ifdef MAIN_UART0_ENABLE
            UART0_BASE_ADDR,
            #else
            WKUP_UART0_BASE_ADDR,
            #endif
            SCIDRV_INPUT_CLOCK_FREQ_HZ,
            Client_PhyTransmitCallback,
            Lin_UartIf_RxIndication_0,
            1,                           // UART HW Channel
            115200,                       // SCI Baud Rate in bps
            SCIDRV_TRANSFER_WIDTH_8BITS, // SCI Data Length
            SCIDRV_STOPBITS_1BIT,        // SCI No of Stops Bits Per Frame
            SCIDRV_PARITY_NONE,          // SCI Parity level
            SCIDRV_OPER_MODE_16X,        // SCI Operational mode
            SCIDRV_RXTRIGLVL_1,          // SCI Rx Trigger Level
            SCIDRV_TXTRIGLVL_1,         // SCI Tx Trigger Level
            FALSE                        // Hw Flow Control
        }
      };

const SSciDrvCfg SciDrvCfg =
    {
        SCIDRV_MAX_CHANNELS,
        &SciDrvChnCfg[0],
};

/****************************************************************************
 *                                 PUBLIC                                    *
 *****************************************************************************/
const SSciDrvCfg *pSciDrvCfg = &SciDrvCfg;

extern void DltExt_Uart_TxComplete(ESciDrvChnResult result);

#ifdef CallBack

static volatile uint8 notification_complete = 0;
// Example client call backs
void Client_PhyTransmitCallback(ESciDrvChnResult TransmitResult)
{
    (void)TransmitResult;
    if(notification_complete < SCIDRV_UINT8_MAX)
    {
        notification_complete += 1U;
    }
}

void Client_PhyReceiveCallback(ESciDrvChnResult ReceiveResult, uint32 SciBytesReceived, uint32 SciExtraBytesReceived)
{
    (void)ReceiveResult;
    (void)SciBytesReceived;
    (void)SciExtraBytesReceived;
    if(notification_complete < SCIDRV_UINT8_MAX)
    {
        notification_complete += 1U;
    }
}

#endif /*CallBack*/
#endif /* SCIDRV_CFG */

/*****************************************************************************
 *     End of File
 *
 ******************************************************************************/
/****************************************************************************
 *   for each change to this file, be sure to record:                        *
 *      1.  who made the change and when the change was made                 *
 *      2.  why the change was made and the intended result                  *
 *   Following block needs to be repeated for each change                    *
 *****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 09-02-2024                                            */
/*Version           :                                                       */
/*By                : sdv                                                   */
/*Traceability      :                                                       */
/*Change Description: Proveout, Initial Version                             */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 29-02-2024                                 */
/*Version           :                                                       */
/*By                : sdv                                                   */
/*Traceability      :                                                       */
/*Change Description: Initial Version Platform Release                            */
/*--------------------------------------------------------------------------*/
