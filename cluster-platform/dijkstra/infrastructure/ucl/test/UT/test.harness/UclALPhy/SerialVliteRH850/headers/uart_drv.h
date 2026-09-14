#if 0
/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2004. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right            *
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
File Name         :  uart_drv.h
Module Short Name :  uart driver
VOBName           :  VW_IVI_MIB_REGIO_VIP_2020_BAP_DEV Workspace
Author            :  skumare1
Description       :  This file contains the VIP reflash code
Organization      :  Reflash Information Software Section,
                     Visteon Corporation
----------------------------------------------------------------------------
Target Processor  :  RH850 F1L
Compiler Name     :  Green Hills 6.1.6
******************************************************************************/
#endif

#if !defined (UART_DRIVER_H)
#define  UART_DRIVER_H		

/*****************************************************************************
*                                 System Includes                            *
******************************************************************************/

/*****************************************************************************
*                                 Project Includes                           *
******************************************************************************/
#include "uart_types.h"
					   
#if defined (__cplusplus)
extern "C" {
#endif

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
/*****************************************************************************
*                                 Constants   			                     *
******************************************************************************/
#define UART_DISABLE_TX_INTERRUPT_IPC	 	UART_RLIN32_DISABLE_TX_INTERRUPT
#define UART_DISABLE_RX_INTERRUPT_IPC		UART_RLIN32_DISABLE_RX_INTERRUPT
#define UART_CLEAR_TX_INTERRUPT_IPC			UART_RLIN32_CLEAR_TX_INTERRUPT
#define UART_CLEAR_RX_INTERRUPT_IPC			UART_RLIN32_CLEAR_RX_INTERRUPT
#define UART_CLEAR_RX_STATUS_INTERRUPT_IPC	UART_RLIN32_CLEAR_ST_INTERRUPT
#define UART_TX_PIN_DISABLE_IPC				UART_RLIN32_TX_PIN_DISABLE
#define UART_TX_PIN_ENABLE_IPC				UART_RLIN32_TX_PIN_ENABLE
#define UART_RX_PIN_DISABLE_IPC				UART_RLIN32_RX_PIN_DISABLE
#define UART_RX_PIN_ENABLE_IPC				UART_RLIN32_RX_PIN_ENABLE
#define UART_TX_REG_IPC 					UART_RLN32LUTDRL
#define UART_RX_REG_IPC 					UART_RLN32LURDRL

#define UART_RX_REG_U16_IPC 					UART_RLN32LURDR

#define UART_ICRLIN_TX_IPC					UART_ICRLIN32UR0
#define UART_ICRLIN_RX_IPC					UART_ICRLIN32UR1
#define UART_ICRLIN_ST_IPC					UART_ICRLIN32UR2
#define UART_RLN3nLUOER_IPC					UART_RLN32LUOER
#define UART_RLN3nLCUC_IPC					UART_RLN32LCUC
#define UART_RLN3nLMST_IPC					UART_RLN32LMST
#define UART_RLN3nLWBR_IPC					UART_RLN32LWBR
#define UART_RLN3nLBRP01_IPC				UART_RLN32LBRP01
#define UART_RLN3nLMD_IPC					UART_RLN32LMD
#define UART_RLN3nLBFC_IPC					UART_RLN32LBFC
#define UART_RLN3nLSC_IPC					UART_RLN32LSC
#define UART_RLN3nLEDE_IPC					UART_RLN32LEDE
#define UART_RLN3nLUOR1_IPC					UART_RLN32LUOR1
#define UART_RLN3nLST_IPC					UART_RLN32LST
#define UART_RLN3nLEST_IPC					UART_RLN32LEST

#define UART_BYTE_TX_WAIT_LOOP_CNT_IPC		((UART_U32_T)10 * 5000)//10ms
#define UART_BYTE_RX_WAIT_LOOP_CNT_IPC		((UART_U32_T)10 * 5000)//10ms
#define UART_RTS_ASSERT_WAIT_LOOP_CNT_IPC	((UART_U32_T)200 * 5000)//10ms
//#define UART_RTS_ASSERT_WAIT_LOOP_CNT_IPC	((UART_U32_T)100 * 5000)//10ms

#define HW_FLOW_CTRL_ENABLED

//#define FblServicewatchdog() {WDTA0WDTE.reg  = 0xAC;}

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, resolution, Valid Range and ValidityCheck *
******************************************************************************/


/*****************************************************************************
*                                 File Scope Prototypes                      *
******************************************************************************/

void  uart_driver_init(void);

UART_STATUS_T
uart_driver_transmit
(    
	UART_U8_T * data,
	UART_U16_T  length
);


UART_STATUS_T
uart_driver_receive
(
	UART_U8_T	 * data,
	UART_U16_T   * length,
	UART_U16_T     max_length
);


UART_BOOL_T uart_driver_is_byte_received(void);

void uart_driver_receive_enable(void);

void uart_driver_receive_disable(void);

void uart_driver_dma_config(UART_U8_T * data, UART_U16_T max_length);
void spi_driver_csih2_stop(void);

UART_U8_T uart_driver_event_for_ucl_update(void);
/*End of File*/
/*****************************************************************************
*   for each change to this file, be sure to record:                         *
*      1.  who made the change and when the change was made                  *
*      2.  why the change was made and the intended result                   *
*   Following block needs to be repeated for each change
******************************************************************************
*   Note: In the traceability column we need to trace back to the Design Doc.*
*   For the initial version it is traced to the Design Document section.     *
*   For further changes it shall trace to the source of the change which may *
*   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
*   other reason                                                             *
******************************************************************************/
/*---------------------------------------------------------------------------
Date              : 22-Mar-2019
CDSID             : skumare1
Traceability      : RTC_241148
Change Description: Initial version for Reflash code for VIP implementation
-----------------------------------------------------------------------------*/

#if defined (__cplusplus)
}
#endif

#endif
