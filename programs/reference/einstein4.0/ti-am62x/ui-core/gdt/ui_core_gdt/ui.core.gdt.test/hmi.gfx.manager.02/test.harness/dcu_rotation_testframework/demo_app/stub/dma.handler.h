/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
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
*  File Name         :  dma.handler.h                                        *
*  Module Short Name :  dma                                                  *
*  Description       :  This file contains DMA Handler prototypes            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Codewarrior                                            *
* Target Hardware  :  MPC56xxx Series of Microcontroller                     *
*                                                                            *
******************************************************************************/
#ifndef DMA_HANDLER_H
#define DMA_HANDLER_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#ifndef DMA_DRIVER_H
#include "dma.driver.h"
#endif

/*****************************************************************************
*                                 Global Macro Definitions                   *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/* DMA Callback Status */
#define DMA_FAILURE   0
#define DMA_SUCCESS   1

/* DMA ISR Type */
#define DMA_ERROR_ISR      1
#define DMA_COMPLETE_ISR   2

/* DMA Channel Status */
#define DMA_CH_IDLE   0
#define DMA_CH_BUSY   1

#define DMA_CH_INVALID   0xFF

/* DMA Error Type */
#define DMA_NO_ERROR                             0
#define DMA_ERROR_CH_BUSY                        BIT0
#define DMA_ERROR_CH_NOT_VALID                   BIT1
#define DMA_ERROR_CH_MAJ_LOOP_CFG                BIT2
#define DMA_ERROR_CH_MIN_LOOP_CFG                BIT3
#define DMA_ERROR_CH_SOFF_SIZE_CFG               BIT4
#define DMA_ERROR_CH_DOFF_SIZE_CFG               BIT5
#define DMA_ERROR_CH_SOURCE_MIN_LOOP_OFFSET_CFG  BIT6
#define DMA_ERROR_CH_DEST_MIN_LOOP_OFFSET_CFG    BIT7

/*****************************************************************************
*                                 Type Declaration                           *
*----------------------------------------------------------------------------*
* Decleration of type shall be accompanied by a comment that explains the    *
* purpose and usage of the type.                                             *
******************************************************************************/
typedef enum
{
    DMA_SW_CHANNEL0,
    DMA_SW_CHANNEL1,
    DMA_SW_CHANNEL2,
    DMA_SW_CHANNEL3,
    DMA_SW_CHANNEL4,
    DMA_SW_CHANNEL5,
    DMA_SW_CHANNEL6,
    DMA_SW_CHANNEL7,
    DMA_SW_CHANNEL8,
    DMA_SW_CHANNEL9,
    DMA_SW_CHANNEL10,
    DMA_SW_CHANNEL11,
    DMA_SW_CHANNEL12,
    DMA_SW_CHANNEL13,
    DMA_SW_CHANNEL14,
    DMA_SW_CHANNEL15
} dma_channel_num_type;

typedef struct
{
    dma_channel_num_type fl_dma_channel_num_U8;
    UINT8 fl_dma_channel_status_U8;
} dma_handler_app_resp_struct;

typedef void (*dma_callback_type)(dma_handler_app_resp_struct *fl_app_resp_struct);

typedef struct
{
    dma_drv_type dma_drv_channel_parameters;
    dma_channel_num_type dma_channel_num;
    dma_callback_type dma_callback;
} dma_handler_type;

/*****************************************************************************
*                                 Global Variable Declarations               *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Global Function Prototypes                 *
******************************************************************************/
/*============================================================================
**
** Function Name:    DMA_Handler_Init
**
** Visibility:       Public
**
** Description:      Initialize the DMA module
**
** Invocation:       Called during Init
**
** Inputs:           None
**
** Outputs:          None
**
** Critical Section: None
**
**==========================================================================*/
void DMA_Handler_Init(void);

/*============================================================================
**
** Function Name:    DMA_Handler_DeInit
**
** Visibility:       Public
**
** Description:      De-Initialize the DMA module
**
** Invocation:       Called during Power shutdown
**
** Inputs:           None
**
** Outputs:          None
**
** Critical Section: None
**
**==========================================================================*/
void DMA_Handler_DeInit(void);

/*============================================================================
**
** Function Name:    DMA_Handler_InitiateRequest
**
** Visibility:       Public
**
** Description:      Initiate Request to start data transfer
**
** Invocation:       Called by Apps
**
** Inputs:           dma_handler_type *fl_dma_handler_struct - Pass necessary 
**                                                   inputs for data transfer
**
** Outputs:          Return Error type if error present else return as No error
**
** Critical Section: None
**
**==========================================================================*/
UINT16 DMA_Handler_InitiateRequest(dma_handler_type *fl_dma_handler_struct);

/*============================================================================
**
** Function Name:    DMA_Handler_CancelRequest
**
** Visibility:       Public
**
** Description:      Cancel the execution of data transfer
**
** Invocation:       Called by Apps
**
** Inputs:           dma_channel_num_type fl_sw_chan_num_E - 
**                   Channel No (valid ranges 0 to 15)
**
** Outputs:          Return Error type if error present else return 
**                   as No error.
**
** Critical Section: None
**
**==========================================================================*/
UINT16 DMA_Handler_CancelRequest(dma_channel_num_type fl_sw_chan_num_E);

/*============================================================================
**
** Function Name:    DMA_Handler_GetChannelStatus
**
** Visibility:       Public
**
** Description:      Returns status of particular DMA Channel
**
** Invocation:       Called by Apps
**
** Inputs:           dma_channel_num_type fl_sw_chan_num_E - 
**                   Channel No (valid ranges 0 to 15)
**
** Outputs:          Return Channel status
**
** Critical Section: None
**
**==========================================================================*/
UINT8 DMA_Handler_GetChannelStatus(dma_channel_num_type fl_sw_chan_num_E);

/*============================================================================
**
** Function Name:    DMA_Handler_ChannelISR
**
** Visibility:       Public
**
** Description:      DMA Interrupt Handler
**
** Invocation:       Called by Interrupt vector
**
** Inputs:           dma_channel_num_type fl_sw_chan_num_E - Channel No 
**                   (valid ranges 0 to 15)
**                   UINT8 fl_isr_type - ISR type (DMA_ERROR_ISR 
**                   or DMA_COMPLETE_ISR)
**
** Outputs:          None
**
** Critical Section: None
**
**==========================================================================*/
void DMA_Handler_ChannelISR(dma_channel_num_type fl_sw_chan_num_E,\
                            UINT8 fl_isr_type);

/*============================================================================
**
** Function Name:    DMA_Handler_CheckErrorStatus
**
** Visibility:       Public
**
** Description:      Returns status of Error in a channel
**
** Invocation:       Called by Apps
**
** Inputs:           dma_channel_num_type fl_sw_chan_num_E - 
**                   Channel No (valid ranges 0 to 15)
**
** Outputs:          Return TRUE if error occurs for a given channel else FALSE
**
** Critical Section: None
**
**==========================================================================*/
UINT8 DMA_Handler_CheckErrorStatus(dma_channel_num_type fl_sw_chan_num_E);

#endif

/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*---------------------------------------------------------------------------
Date               : 26-June-13
CDSID              : krohini
Traceability       : dma.handler_SDS.doc
Change Description : Initial version
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
