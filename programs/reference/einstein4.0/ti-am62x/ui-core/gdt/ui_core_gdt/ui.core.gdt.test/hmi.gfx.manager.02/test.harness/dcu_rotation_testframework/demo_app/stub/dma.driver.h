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
*  File Name         :  dma.driver.h                                         *
*  Module Short Name :  dma                                                  *
*  Description       :  This file contains DMA driver prototypes             *
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
#ifndef DMA_DRIVER_H
#define DMA_DRIVER_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#ifndef DMA_DRIVER_CFG
#include "dma.driver.cfg"
#endif

/*****************************************************************************
*                                 Global Macro Definitions                   *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define DMA_MAXIMUM_SUPPORTED_CHANNELS  16

#if (PS_DMA_CHANNELS_USED > 16)
#error Maximum DMA Channels configuration supported is 16
#endif

/* DMA requesting module and DMACHMUX source number */
#define DMA_SR_DSPI0_TX       1
#define DMA_SR_DSPI0_RX       2
#define DMA_SR_DSPI1_TX       3
#define DMA_SR_DSPI1_RX       4
#define DMA_SR_DSPI2_TX       5
#define DMA_SR_DSPI2_RX       6

#define DMA_SR_I2C0_TX        7
#define DMA_SR_I2C0_RX        8
#define DMA_SR_I2C1_TX        9
#define DMA_SR_I2C1_RX        10
#define DMA_SR_I2C2_TX        11
#define DMA_SR_I2C2_RX        12
#define DMA_SR_I2C3_TX        13
#define DMA_SR_I2C3_RX        14

#define DMA_SR_eMIOS0_FG_F9   15
#define DMA_SR_eMIOS0_FG_F11  16
#define DMA_SR_eMIOS0_FG_F13  17
#define DMA_SR_eMIOS0_FG_F15  18
#define DMA_SR_eMIOS0_FG_F17  19
#define DMA_SR_eMIOS0_FG_F19  20
#define DMA_SR_eMIOS0_FG_F21  21
#define DMA_SR_eMIOS1_FG_F9   22
#define DMA_SR_eMIOS1_FG_F11  23
#define DMA_SR_eMIOS1_FG_F13  24
#define DMA_SR_eMIOS1_FG_F15  25
#define DMA_SR_eMIOS1_FG_F17  26
#define DMA_SR_eMIOS1_FG_F19  27
#define DMA_SR_eMIOS1_FG_F21  28

#define DMA_SR_LIN_A_Rx_FIFO  31
#define DMA_SR_LIN_A_Tx_FIFO  32
#define DMA_SR_LIN_B_Rx_FIFO  33
#define DMA_SR_LIN_B_Tx_FIFO  34
#define DMA_SR_LIN_C_Rx_FIFO  35
#define DMA_SR_LIN_C_Tx_FIFO  36
#define DMA_SR_LIN_D_Rx_FIFO  37
#define DMA_SR_LIN_D_Tx_FIFO  38

#define DMA_SR_DRAMC          39
#define DMA_SR_QuadSPI_RX     40

#define DMA_SR_SGM_CH0        43
#define DMA_SR_SGM_CH1        44
#define DMA_SR_SGM_CH2        45
#define DMA_SR_SGM_CH3        46

#define DMA_SR_ADC            51

#define DMA_SR_RLE_Tx_FIFO    53
#define DMA_SR_RLE_Rx_FIFO    54

#define DMA_SR_ALWAYS_ENB_0   56
#define DMA_SR_ALWAYS_ENB_1   57
#define DMA_SR_ALWAYS_ENB_2   58
#define DMA_SR_ALWAYS_ENB_3   59
#define DMA_SR_ALWAYS_ENB_4   60
#define DMA_SR_ALWAYS_ENB_5   61
#define DMA_SR_ALWAYS_ENB_6   62
#define DMA_SR_ALWAYS_ENB_7   63

/* DMA ISR Type */
#define DMA_ERROR_ISR      1
#define DMA_COMPLETE_ISR   2

/* DMA Driver Error Type */
#define DMA_DRV_NO_ERROR                             0
#define DMA_DRV_ERROR_CH_BUSY                        BIT0
#define DMA_DRV_ERROR_CH_NOT_VALID                   BIT1
#define DMA_DRV_ERROR_CH_MAJ_LOOP_CFG                BIT2
#define DMA_DRV_ERROR_CH_MIN_LOOP_CFG                BIT3
#define DMA_DRV_ERROR_CH_SOFF_SIZE_CFG               BIT4
#define DMA_DRV_ERROR_CH_DOFF_SIZE_CFG               BIT5
#define DMA_DRV_ERROR_CH_SOURCE_MIN_LOOP_OFFSET_CFG  BIT6
#define DMA_DRV_ERROR_CH_DEST_MIN_LOOP_OFFSET_CFG    BIT7

/*****************************************************************************
*                                 Type Declaration                           *
*----------------------------------------------------------------------------*
* Declaration of type shall be accompanied by a comment that explains the    *
* purpose and usage of the type.                                             *
******************************************************************************/
typedef enum
{
    DMA_MUX_HW_REQUEST,
    DMA_MUX_ALWAYS_ENB_REQUEST,
    DMA_SW_REQUEST
} dma_drv_source_type;

typedef enum
{
    SIZE_1BYTE,
    SIZE_2BYTE,
    SIZE_4BYTE,
    SIZE_8BYTE,
    SIZE_16BYTE,
    SIZE_32BYTE
} dma_drv_size_type;

typedef struct
{
    UINT32 source_address_U32;                /* Source Address */
    UINT32 destination_address_U32;           /* Dest Address */
    UINT32 minor_loop_count_U32;              /* NBytes */
    UINT32 last_source_adjustment_U32;        /* Last Source Adjustment */
    UINT32 last_dest_adjustment_U32;          /* Last Dest Adjustment */
    UINT32 minor_loop_offset_U32;             /* Minor loop offset */
    UINT16 source_offset_U16;                 /* Source Offset */
    UINT16 destination_offset_U16;            /* Dest Offset */
    UINT16 major_loop_count_U16;              /* Major loop count */
    UINT16 source_number_U16;                 /* DMA Mux Source Number */
    dma_drv_source_type source_request_type_E;/* Channel Service request type */
    dma_drv_size_type source_size_E;          /* Source Size */
    dma_drv_size_type destination_size_E;     /* Dest Size */
    UINT8 minor_loop_offset_src_U8;           /* Enable/Disable Minor loop offset for Source */
    UINT8 minor_loop_offset_dest_U8;          /* Enable/Disable Minor loop offset for Dest */
    UINT8 bandwidth_ctrl_U8;                  /* Bandwidth control */
    UINT8 disable_hw_request_U8;              /* 1 - Disable HW Request when the outer major loop is complete, otherwise 0 */
    UINT8 enable_completion_isr_U8;           /* 1 - Enable outer major loop interrupt, 0 - Disable outer major loop interrupt */
} dma_drv_type;

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
** Function Name:    DMA_Driver_Init
**
** Visibility:       Public
**
** Description:      Initialize the DMA module
**
** Invocation:       Called by DMA Handler
**
** Inputs:           None
**
** Outputs:          None
**
** Critical Section: None
**
**==========================================================================*/
void DMA_Driver_Init(void);

/*============================================================================
**
** Function Name:    DMA_Driver_DeInit
**
** Visibility:       Public
**
** Description:      De-Initialize the DMA module
**
** Invocation:       Called by DMA Handler
**
** Inputs:           None
**
** Outputs:          None
**
** Critical Section: None
**
**==========================================================================*/
void DMA_Driver_DeInit(void);

/*============================================================================
**
** Function Name:    DMA_Driver_InitiateRequest
**
** Visibility:       Public
**
** Description:      Initiate Request to start data transfer
**
** Invocation:       Called by DMA Handler
**
** Inputs:           UINT8 fl_sw_chan_num_U8 - Channel No (valid ranges 0 to 15)
**                   dma_drv_type *fl_drv_parameters - Pass necessary 
**                                             inputs for data transfer
**
** Outputs:          Return Error type if error present else return as No error.
**
** Critical Section: None
**
**==========================================================================*/
UINT16 DMA_Driver_InitiateRequest(UINT8 fl_sw_chan_num_U8, \
                                  dma_drv_type *fl_drv_parameters);

/*============================================================================
**
** Function Name:    DMA_Driver_CancelRequest
**
** Visibility:       Public
**
** Description:      Cancel the execution of data transfer
**
** Invocation:       Called by DMA Handler
**
** Inputs:           UINT8 fl_sw_chan_num_U8 - Channel No (valid ranges 0 to 15)
**
** Outputs:          Return Error type if error present else return as No error.
**
** Critical Section: None
**
**==========================================================================*/
UINT16 DMA_Driver_CancelRequest(UINT8 fl_sw_chan_num_U8);

/*============================================================================
**
** Function Name:    DMA_Driver_ChannelISR
**
** Visibility:       Public
**
** Description:      DMA Drvier ISR
**
** Invocation:       Called by DMA Handler
**
** Inputs:           UINT8 fl_sw_chan_num_U8 - Channel No(valid ranges 0 to 15)
**                   UINT8 fl_isr_type - ISR type 
**                   (DMA_ERROR_ISR or DMA_COMPLETE_ISR)
**
** Outputs:          Returns Error channel number if DMA_ERROR_ISR detected
**
** Critical Section: None
**
**==========================================================================*/
UINT8 DMA_Driver_ChannelISR(UINT8 fl_sw_chan_num_U8,UINT8 fl_isr_type);

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
Traceability       : dma.driver.mpc56xx_SDS.doc
Change Description : Initial version
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
