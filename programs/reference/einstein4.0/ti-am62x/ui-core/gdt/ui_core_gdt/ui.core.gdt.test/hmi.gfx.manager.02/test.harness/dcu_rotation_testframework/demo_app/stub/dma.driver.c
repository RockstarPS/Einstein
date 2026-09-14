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
*  File Name         :  dma.driver                                           *
*  Module Short Name :  dma                                                  *
*  Description       :  This file contains DMA driver routines               *
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
#ifndef DMA_DRIVER_C
#define DMA_DRIVER_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#ifndef SYSTEM_H
#include "system.h"
#endif
#ifndef MCU_PREG_H
#include "mcu_preg.h"
#endif
#ifndef DMA_DRIVER_H
#include "dma.driver.h"
#endif

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef struct
{
    UINT8 hw_channel_U8;
    UINT8 priority_U8;
}dma_drv_const_type;

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
static const dma_drv_const_type l_dma_drv_parameters_SA[PS_DMA_CHANNELS_USED] \
                                = {DMA_CH_PARAMETERS};

/*****************************************************************************
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
******************************************************************************/
static void DMA_Driver_InitChannel(UINT8 fl_hw_chan_num_U8);
static UINT16 DMA_Driver_ValidateRequest(dma_drv_type *fl_drv_parameters);

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
void DMA_Driver_Init(void)
{
  UINT8 fl_channel_U8;
  
  EDMA.CDNE.R = 64u;     /* Clear all Done bits */
  EDMA.CERQ.R = 64u;     /* Clear all enable request bits */
  EDMA.CINT.R = 64u;     /* Clear all interrupt request bits */
  EDMA.CERR.R = 64u;     /* Clear all error indication bits */
  EDMA.CEEI.R = 64u;     /* Clear all enable error interrupts */

  EDMA.CR.R = 0x00000000u;   /* Enable fixed priority arbitration for 
                               channel selection */
  EDMA.INTL.R = 0x00u;       /* Clear interrupt request for all channels */
  EDMA.CR.B.EMLM = 1u;       /* Enable minor loop mapping */
    #ifdef GFX_MGR02_FARADAY
    EDMA.CR.B.GRP0PRI = 0;
    EDMA.CR.B.GRP1PRI = 1;
    #endif
  for(fl_channel_U8 = 0u; fl_channel_U8 < PS_DMA_CHANNELS_USED; \
      fl_channel_U8++)
  {
     EDMA.CPR[l_dma_drv_parameters_SA[fl_channel_U8].hw_channel_U8].R \
     = l_dma_drv_parameters_SA[fl_channel_U8].priority_U8;
  }
}

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
void DMA_Driver_DeInit(void)
{
  UINT8 fl_channel_U8;
  
  EDMA.CDNE.R = 64u;     /* Clear all Done bits */
  EDMA.CERQ.R = 64u;     /* Clear all enable request bits */
  EDMA.CINT.R = 64u;     /* Clear all interrupt request bits */
  EDMA.CERR.R = 64u;     /* Clear all error indication bits */
  EDMA.CEEI.R = 64u;     /* Clear all enable error interrupts */

  EDMA.CR.R = 0x00000000u;
  EDMA.INTL.R = 0x00u;       /* Clear interrupt request for all channels */

  for(fl_channel_U8 = 0u; fl_channel_U8 < PS_DMA_CHANNELS_USED; \
      fl_channel_U8++)
  {
     DMAMUX.CHCONFIG[l_dma_drv_parameters_SA[fl_channel_U8].hw_channel_U8].B.ENBL = 0u;
     DMAMUX.CHCONFIG[l_dma_drv_parameters_SA[fl_channel_U8].hw_channel_U8].B.SOURCE = 0u;
  }
}

/*============================================================================
**
** Function Name:    DMA_Driver_InitChannel
**
** Visibility:       Private
**
** Description:      Initialize particular DMA Channel
**
** Invocation:       Called by DMA_Driver_InitiateRequest
**
** Inputs:           UINT8 fl_hw_chan_num_U8 - Channel No (valid ranges 0 to 15)
**
** Outputs:          None
**
** Critical Section: None
**
**==========================================================================*/
static void DMA_Driver_InitChannel(UINT8 fl_hw_chan_num_U8)
{
  EDMA.TCD[fl_hw_chan_num_U8].SSIZE = 0u;
  EDMA.TCD[fl_hw_chan_num_U8].DSIZE = 0u;
  EDMA.TCD[fl_hw_chan_num_U8].DMOD = 0u;
  EDMA.TCD[fl_hw_chan_num_U8].SMOD = 0u;
  EDMA.TCD[fl_hw_chan_num_U8].INT_HALF = 0u;
  EDMA.TCD[fl_hw_chan_num_U8].CITERE_LINK = 0u;
  EDMA.TCD[fl_hw_chan_num_U8].BITERE_LINK = 0u;
  EDMA.TCD[fl_hw_chan_num_U8].MAJORE_LINK = 0u;
  EDMA.TCD[fl_hw_chan_num_U8].MAJORLINKCH = 0u;
  EDMA.TCD[fl_hw_chan_num_U8].E_SG = 0u;
  EDMA.TCD[fl_hw_chan_num_U8].BWC = 0u;
  EDMA.TCD[fl_hw_chan_num_U8].START = 0u;
  EDMA.TCD[fl_hw_chan_num_U8].DONE = 0u;
  EDMA.TCD[fl_hw_chan_num_U8].ACTIVE = 0u;
  EDMA.TCD[fl_hw_chan_num_U8].NBYTESu.B.SMLOE = 0u;
  EDMA.TCD[fl_hw_chan_num_U8].NBYTESu.B.DMLOE = 0u;

  EDMA.TCD[fl_hw_chan_num_U8].CITERE_LINK = 0u;
  EDMA.TCD[fl_hw_chan_num_U8].BITERE_LINK = 0u;
  EDMA.TCD[fl_hw_chan_num_U8].MAJORE_LINK = 0u;
  EDMA.TCD[fl_hw_chan_num_U8].E_SG = 0u;

  DMAMUX.CHCONFIG[fl_hw_chan_num_U8].B.ENBL = 0u;
  DMAMUX.CHCONFIG[fl_hw_chan_num_U8].B.SOURCE = 0u;
  EDMA.SEEI.R = fl_hw_chan_num_U8;
}

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
                                  dma_drv_type *fl_drv_parameters)
{
  UINT16 fl_error_status_U16;
  UINT8 fl_save_int_status_U8;
  UINT8 fl_hw_channel_num_U8;

  fl_error_status_U16 = DMA_DRV_NO_ERROR;
  fl_error_status_U16 = DMA_Driver_ValidateRequest(fl_drv_parameters);

  if (fl_error_status_U16 == DMA_DRV_NO_ERROR)
  {
     fl_hw_channel_num_U8 \
     = l_dma_drv_parameters_SA[fl_sw_chan_num_U8].hw_channel_U8;

     DMA_Driver_InitChannel(fl_hw_channel_num_U8);

     EDMA.TCD[fl_hw_channel_num_U8].SADDR \
     = fl_drv_parameters->source_address_U32;

     EDMA.TCD[fl_hw_channel_num_U8].SSIZE \
     = fl_drv_parameters->source_size_E;

     EDMA.TCD[fl_hw_channel_num_U8].SOFF \
     = (SINT16)fl_drv_parameters->source_offset_U16;

     EDMA.TCD[fl_hw_channel_num_U8].DADDR \
     = fl_drv_parameters->destination_address_U32;

     EDMA.TCD[fl_hw_channel_num_U8].DSIZE \
     = fl_drv_parameters->destination_size_E;

     EDMA.TCD[fl_hw_channel_num_U8].DOFF \
     = (SINT16)fl_drv_parameters->destination_offset_U16;

     EDMA.TCD[fl_hw_channel_num_U8].BITER \
     = fl_drv_parameters->major_loop_count_U16;

     EDMA.TCD[fl_hw_channel_num_U8].CITER \
     = fl_drv_parameters->major_loop_count_U16;

     EDMA.TCD[fl_hw_channel_num_U8].SLAST \
     = (SINT32)fl_drv_parameters->last_source_adjustment_U32;

     EDMA.TCD[fl_hw_channel_num_U8].DLAST_SGA \
     = (SINT32)fl_drv_parameters->last_dest_adjustment_U32;

     EDMA.TCD[fl_hw_channel_num_U8].NBYTESu.B.SMLOE \
     = fl_drv_parameters->minor_loop_offset_src_U8;

     EDMA.TCD[fl_hw_channel_num_U8].NBYTESu.B.DMLOE \
     = fl_drv_parameters->minor_loop_offset_dest_U8;
     
     EDMA.TCD[fl_hw_channel_num_U8].BWC = fl_drv_parameters->bandwidth_ctrl_U8;

     if ((fl_drv_parameters->minor_loop_offset_src_U8 != 0) \
           || (fl_drv_parameters->minor_loop_offset_dest_U8 !=0))
     {
        EDMA.TCD[fl_hw_channel_num_U8].NBYTESu.B.MLOFF \
          = fl_drv_parameters->minor_loop_offset_U32;
     }
     else
     {
        EDMA.TCD[fl_hw_channel_num_U8].NBYTESu.B.MLOFF \
         = (fl_drv_parameters->minor_loop_count_U32 >> 10);
     }
     EDMA.TCD[fl_hw_channel_num_U8].NBYTESu.B.NBYTES \
         = fl_drv_parameters->minor_loop_count_U32;
     
     if (fl_drv_parameters->disable_hw_request_U8 == 1)
     {
        EDMA.TCD[fl_hw_channel_num_U8].D_REQ = 1u;
     }
     else
     {
        EDMA.TCD[fl_hw_channel_num_U8].D_REQ = 0u;
     }
     
     EDMA.CINT.R = fl_hw_channel_num_U8;
     if (fl_drv_parameters->enable_completion_isr_U8 == 1)
     {
        EDMA.TCD[fl_hw_channel_num_U8].INT_MAJ = 1u;
     }
     else
     {
        EDMA.TCD[fl_hw_channel_num_U8].INT_MAJ = 0u;
     }

     if (fl_drv_parameters->source_request_type_E != DMA_SW_REQUEST)
     {
	#ifdef GFX_MGR02_FARADAY
        DMAMUX.CHCONFIG[ fl_hw_channel_num_U8 ].R = (0x80 | fl_drv_parameters->source_number_U16);
	#else
        DMAMUX.CHCONFIG[fl_hw_channel_num_U8].B.ENBL = 1u;
        DMAMUX.CHCONFIG[fl_hw_channel_num_U8].B.SOURCE \
          = fl_drv_parameters->source_number_U16;
    #endif  
        EDMA.SERQ.R = fl_hw_channel_num_U8;
        //EDMA.SSRT.R = fl_hw_channel_num_U8;
     }
     else
     {
        EDMA.SSRT.R = fl_hw_channel_num_U8;
     }
  }
  return(fl_error_status_U16);
}

/*============================================================================
**
** Function Name:    DMA_Driver_ValidateRequest
**
** Visibility:       Private
**
** Description:      Check for configuration error
**
** Invocation:       Called by DMA_Driver_InitiateRequest
**
** Inputs:           dma_drv_type *fl_drv_parameters - Pass necessary 
**                                            inputs for data transfer
**
** Outputs:          Return UINT8
**
** Critical Section: None
**
**==========================================================================*/
static UINT16 DMA_Driver_ValidateRequest(dma_drv_type *fl_drv_parameters)
{
  UINT16 fl_error_status_U16;
  UINT8 fl_source_byte_size_U8;
  UINT8 fl_dest_byte_size_U8;

  fl_error_status_U16 = DMA_DRV_NO_ERROR;  
  if ((fl_drv_parameters->major_loop_count_U16) == 0)
  {
     /* Major loop cfg should not be zero, atleast it should be 1 */
     fl_error_status_U16 = DMA_DRV_ERROR_CH_MAJ_LOOP_CFG; 
  }
  else 
  {
     if (fl_drv_parameters->source_request_type_E == DMA_SW_REQUEST)
     {
        if ((fl_drv_parameters->major_loop_count_U16) != 1)
        {
           /* SW request completes on minor loop completion hence major loop 
              should be 1 to get the completion ISR for each SW request*/
           fl_error_status_U16 = DMA_DRV_ERROR_CH_MAJ_LOOP_CFG;
        }
     }
     
     fl_source_byte_size_U8 \
     = (UINT8)(0x01 << fl_drv_parameters->source_size_E);

     fl_dest_byte_size_U8 \
     = (UINT8)(0x01 << fl_drv_parameters->destination_size_E);

     /* Minor loop offset should be multiples of Source size byte */
     if(fl_drv_parameters->minor_loop_offset_src_U8 != 0)
     {
        if(fl_drv_parameters->minor_loop_offset_U32 != 0 )
        { 
           if((fl_drv_parameters->minor_loop_offset_U32 % fl_source_byte_size_U8)\
               != 0)
           {
              fl_error_status_U16 |= DMA_DRV_ERROR_CH_SOURCE_MIN_LOOP_OFFSET_CFG;
           }
        }
     }
     
     /* Minor loop offset should be multiples of Dest size byte */
     if(fl_drv_parameters->minor_loop_offset_dest_U8 != 0)
     {
        if(fl_drv_parameters->minor_loop_offset_U32 != 0 )
        { 
           if((fl_drv_parameters->minor_loop_offset_U32 % fl_dest_byte_size_U8)\
              != 0)
           {
               fl_error_status_U16 |= DMA_DRV_ERROR_CH_DEST_MIN_LOOP_OFFSET_CFG;
           }
        }
     }
     
     /* Minor loop count should be multiples of Source size byte and destination 
        size byte */
     if (((fl_drv_parameters->minor_loop_count_U32 % fl_source_byte_size_U8)!= 0)\
          || ((fl_drv_parameters->minor_loop_count_U32 % fl_dest_byte_size_U8)!= 0))
     {
        fl_error_status_U16 |= DMA_DRV_ERROR_CH_MIN_LOOP_CFG;
     }

     /* Source offset should be multiples of Source size byte */
     if(fl_drv_parameters->source_offset_U16 != 0 )
     {
        if((fl_drv_parameters->source_offset_U16 % fl_source_byte_size_U8)!= 0)
        {
           fl_error_status_U16 |= DMA_DRV_ERROR_CH_SOFF_SIZE_CFG;
        }
     }

     /* Dest offset should be multiples of Dest size byte */
     if(fl_drv_parameters->destination_offset_U16 != 0 )
     {
        if((fl_drv_parameters->destination_offset_U16 % fl_dest_byte_size_U8)\
           != 0)
        {
           fl_error_status_U16 |= DMA_DRV_ERROR_CH_DOFF_SIZE_CFG;
        }
     }
  }
  return(fl_error_status_U16);
}

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
UINT16 DMA_Driver_CancelRequest(UINT8 fl_sw_chan_num_U8)
{
  UINT16 fl_error_status_U16;
  
  fl_error_status_U16 = DMA_DRV_NO_ERROR;
  EDMA.CERQ.R \
  = l_dma_drv_parameters_SA[fl_sw_chan_num_U8].hw_channel_U8;

  EDMA.CR.B.CX = 1;
  
  if (EDMA.CR.B.CX == 1)
  {
     fl_error_status_U16 = DMA_DRV_ERROR_CH_BUSY;
  }
  return(fl_error_status_U16);
}

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
** Inputs:           UINT8 fl_sw_chan_num_U8 - Channel No (valid ranges 0 to 15)
**                   UINT8 fl_isr_type - ISR type 
**                   (DMA_ERROR_ISR or DMA_COMPLETE_ISR)
**
** Outputs:          Returns Error channel number if DMA_ERROR_ISR detected
**
** Critical Section: None
**
**==========================================================================*/
UINT8 DMA_Driver_ChannelISR(UINT8 fl_sw_chan_num_U8,UINT8 fl_isr_type)
{
  UINT16 fl_channel_bit_U16;
  UINT8 fl_channel_U8;
  UINT8 fl_hw_channel_num_U8;
  UINT8 fl_error_channel_U8;
  
  fl_error_channel_U8 = FALSE;
  fl_hw_channel_num_U8 \
   = l_dma_drv_parameters_SA[fl_sw_chan_num_U8].hw_channel_U8;

  if (fl_isr_type == DMA_COMPLETE_ISR)
  {  
     EDMA.CDNE.R = fl_hw_channel_num_U8;
     EDMA.CERQ.R = fl_hw_channel_num_U8;
     EDMA.CINT.R = fl_hw_channel_num_U8;
     EDMA.CEEI.R = fl_hw_channel_num_U8;
     DMAMUX.CHCONFIG[fl_hw_channel_num_U8].B.ENBL = 0u;
  }
  else
  {
     fl_channel_bit_U16 = (UINT16)(0x01 << fl_hw_channel_num_U8); 
     if ((EDMA.ERRL.R & fl_channel_bit_U16) == fl_channel_bit_U16)
     {
        fl_error_channel_U8 = TRUE;
        EDMA.CDNE.R = fl_hw_channel_num_U8;
        EDMA.CERQ.R = fl_hw_channel_num_U8;
        EDMA.CINT.R = fl_hw_channel_num_U8;
        EDMA.CEEI.R = fl_hw_channel_num_U8;
        DMAMUX.CHCONFIG[fl_hw_channel_num_U8].B.ENBL = 0u;
        EDMA.CERR.R = fl_hw_channel_num_U8;
     }
  }
  return(fl_error_channel_U8);
}

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
Date               : 24-July-13
CDSID              : krohini
Traceability       : dma.driver.mpc56xx_SDS.doc
Change Description : Updated review comments
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 26-June-13
CDSID              : krohini
Traceability       : dma.driver.mpc56xx_SDS.doc
Change Description : Initial version
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
