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
*  File Name         :  SciDrv_Irq.c                                                *
*  Module Short Name :  SciDrv                                               *
*  Description       :  This file contains implementations of the SCI Driver *
*                       Interrupt Service Routine                            *
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
#include "SciDrv.h"
#include "SciDrv_Irq.h"

/*****************************************************************************
*     Callback for Tansmit and Receive for MCU UART0 - Hw Channel ID - 0       *
******************************************************************************/
void MCU_IntrISR_UART0func(void)
{
    SciDrv_TxRxISRHandle(CH_ID_0);
}

/*****************************************************************************
*     Callback for Tansmit and Receive for WKUP UART0 - Hw Channel ID - 1      *
******************************************************************************/
void WKUP_IntrISR_UART0func(void)
{
    SciDrv_TxRxISRHandle(CH_ID_1);
}

/*****************************************************************************
*     Callback for Tansmit and Receive for MAIN UART0 - Hw Channel ID - 2      *
******************************************************************************/
void MAIN_IntrISR_UART0func(void)
{
    SciDrv_TxRxISRHandle(CH_ID_2);
}

/*****************************************************************************
*     Callback for Tansmit and Receive for MAIN UART1 - Hw Channel ID - 3      *
******************************************************************************/
void MAIN_IntrISR_UART1func(void)
{
    SciDrv_TxRxISRHandle(CH_ID_3);
}

/*****************************************************************************
*     Callback for Tansmit and Receive for MAIN UART2 - Hw Channel ID - 4      *
******************************************************************************/
void MAIN_IntrISR_UART2func(void)
{
    SciDrv_TxRxISRHandle(CH_ID_4);
}

/*****************************************************************************
*     Callback for Tansmit and Receive for MAIN UART3 - Hw Channel ID - 5      *
******************************************************************************/
void MAIN_IntrISR_UART3func(void)
{
    SciDrv_TxRxISRHandle(CH_ID_5);
}

/*****************************************************************************
*     Callback for Tansmit and Receive for MAIN UART4 - Hw Channel ID - 6      *
******************************************************************************/
void MAIN_IntrISR_UART4func(void)
{
    SciDrv_TxRxISRHandle(CH_ID_6);
}

/*****************************************************************************
*     Callback for Tansmit and Receive for MAIN UART5 - Hw Channel ID - 7      *
******************************************************************************/
void MAIN_IntrISR_UART5func(void)
{
    SciDrv_TxRxISRHandle(CH_ID_7);
}

/*****************************************************************************
*     Callback for Tansmit and Receive for MAIN UART6 - Hw Channel ID - 8      *
******************************************************************************/
void MAIN_IntrISR_UART6func(void)
{
    SciDrv_TxRxISRHandle(CH_ID_8);
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