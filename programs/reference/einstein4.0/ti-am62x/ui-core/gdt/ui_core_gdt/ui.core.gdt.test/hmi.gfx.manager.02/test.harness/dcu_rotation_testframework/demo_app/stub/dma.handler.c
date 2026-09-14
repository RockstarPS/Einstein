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
*  File Name         :  dma.handler.c                                        *
*  Module Short Name :  dma                                                  *
*  Description       :  This file contains a routine to interact with        *
*                       DAM driver and application.                          *
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
#ifndef DMA_HANDLER_C
#define DMA_HANDLER_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#ifndef SYSTEM_H
#include "system.h"
#endif
#ifndef DMA_HANDLER_H
#include "dma.handler.h"
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

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
typedef struct
{
    dma_callback_type callback;
    UINT8 channel_status_U8;
    UINT8 channel_error_U8;
} l_dma_handler_type;

static l_dma_handler_type l_dma_handler_parameter_SA[PS_DMA_CHANNELS_USED];
 
/*****************************************************************************
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
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
void DMA_Handler_Init(void)
{
  UINT8 fl_channel_U8;
  
  for(fl_channel_U8 = 0u; fl_channel_U8 < PS_DMA_CHANNELS_USED; \
      fl_channel_U8++)
  {
     /* Init all channels to IDLE state */
     l_dma_handler_parameter_SA[fl_channel_U8].channel_status_U8 = DMA_CH_IDLE;
     l_dma_handler_parameter_SA[fl_channel_U8].channel_error_U8 = FALSE;

     /* Rationale: It is required to assign a values to this function that will
     be used as callback the null pointer value indicates the function has not
     been initialized */
     l_dma_handler_parameter_SA[fl_channel_U8].callback = NULL_PTR;
  }
  DMA_Driver_Init();
}

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
void DMA_Handler_DeInit(void)
{
  UINT8 fl_channel_U8;

  for(fl_channel_U8 = 0u; fl_channel_U8 < PS_DMA_CHANNELS_USED; \
     fl_channel_U8++)
  {
     /* Init all channels to IDLE state */
     l_dma_handler_parameter_SA[fl_channel_U8].channel_status_U8 = DMA_CH_IDLE;
     l_dma_handler_parameter_SA[fl_channel_U8].channel_error_U8 = FALSE;

     /* Rationale: It is required to assign a values to this function that will 
     be used as callback the null pointer value indicates the function has not 
     been initialized */
     l_dma_handler_parameter_SA[fl_channel_U8].callback = NULL_PTR;
  }  
  DMA_Driver_DeInit();
}

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
**                                                  inputs for data transfer
**
** Outputs:          Return Error type if error present else return as No error
**
** Critical Section: None
**
**==========================================================================*/
UINT16 DMA_Handler_InitiateRequest(dma_handler_type *fl_dma_handler_struct)
{
  UINT16 fl_error_status_U16;

  fl_error_status_U16 = DMA_ERROR_CH_BUSY;
  if(fl_dma_handler_struct->dma_channel_num >= PS_DMA_CHANNELS_USED)
  {
     fl_error_status_U16 = DMA_ERROR_CH_NOT_VALID;
  }
  else
  {
     if ((l_dma_handler_parameter_SA[fl_dma_handler_struct->dma_channel_num].channel_status_U8) \
          == DMA_CH_IDLE)
     {
        l_dma_handler_parameter_SA[fl_dma_handler_struct->dma_channel_num].callback \
        = fl_dma_handler_struct->dma_callback;
        
        /* Move the Channel status to Busy prior to calling Driver Init */
        l_dma_handler_parameter_SA[fl_dma_handler_struct->dma_channel_num].channel_status_U8 \
        = DMA_CH_BUSY;
     
        /* DMA Start executing to transfer data */
        fl_error_status_U16 \
        = DMA_Driver_InitiateRequest(fl_dma_handler_struct->dma_channel_num, \
                          &fl_dma_handler_struct->dma_drv_channel_parameters);
     
        if ( (fl_error_status_U16 != DMA_NO_ERROR) \
             && (fl_error_status_U16 != DMA_ERROR_CH_BUSY))
        {
           /* Move to Idle state only if Driver cfg error occurs */
           l_dma_handler_parameter_SA[fl_dma_handler_struct->dma_channel_num].channel_status_U8 \
           = DMA_CH_IDLE; 
        }
     }
  }
  return(fl_error_status_U16);
}

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
UINT16 DMA_Handler_CancelRequest(dma_channel_num_type fl_sw_chan_num_E)
{
  UINT16 fl_error_status_U16;

  fl_error_status_U16 = DMA_NO_ERROR;
  if(fl_sw_chan_num_E >= PS_DMA_CHANNELS_USED)
  {
     fl_error_status_U16 = DMA_ERROR_CH_NOT_VALID;
  }
  else
  {                                                   
     if ((l_dma_handler_parameter_SA[fl_sw_chan_num_E].channel_status_U8) \
          == DMA_CH_BUSY)
     {
        fl_error_status_U16 = DMA_Driver_CancelRequest(fl_sw_chan_num_E);
        if (fl_error_status_U16 == DMA_NO_ERROR)
        {
           l_dma_handler_parameter_SA[fl_sw_chan_num_E].channel_status_U8 \
           = DMA_CH_IDLE;
           l_dma_handler_parameter_SA[fl_sw_chan_num_E].callback = NULL_PTR;
        }
     }
  }
  return(fl_error_status_U16);
}

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
UINT8 DMA_Handler_GetChannelStatus(dma_channel_num_type fl_sw_chan_num_E)
{
  UINT8 fl_ret_value_U8;
  
  fl_ret_value_U8 = DMA_CH_INVALID;
  if(fl_sw_chan_num_E < PS_DMA_CHANNELS_USED)
  {
     fl_ret_value_U8 = l_dma_handler_parameter_SA[fl_sw_chan_num_E].channel_status_U8;
  }    
  return(fl_ret_value_U8);
}

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
                            UINT8 fl_isr_type)
{
  dma_handler_app_resp_struct fl_app_resp_struct;
  UINT8 fl_error_channel_U8;
  UINT8 fl_channel_U8;

  if (fl_isr_type == DMA_COMPLETE_ISR)
  {
     if (fl_sw_chan_num_E < PS_DMA_CHANNELS_USED)
     { 
        /* Send Callback with Success status */
        (void)DMA_Driver_ChannelISR(fl_sw_chan_num_E,fl_isr_type);

        /* Channel status is moved to Idle */
        l_dma_handler_parameter_SA[fl_sw_chan_num_E].channel_status_U8 = DMA_CH_IDLE;

        if(l_dma_handler_parameter_SA[fl_sw_chan_num_E].callback != NULL_PTR)
        {
           /* Return Channel No with Success notification in callback */
           fl_app_resp_struct.fl_dma_channel_num_U8 = fl_sw_chan_num_E;
           fl_app_resp_struct.fl_dma_channel_status_U8 = DMA_SUCCESS;
           l_dma_handler_parameter_SA[fl_sw_chan_num_E].callback(&fl_app_resp_struct);
        }
     }
  }
  else
  {
      /* Send Callback with Failure status */
      /* Find the HW error channels to send callback */
      for(fl_channel_U8 = 0u; fl_channel_U8 < PS_DMA_CHANNELS_USED; \
          fl_channel_U8++)
      {
         fl_error_channel_U8 \
         = DMA_Driver_ChannelISR(fl_channel_U8,fl_isr_type);

         if (fl_error_channel_U8 != FALSE)
         {
            l_dma_handler_parameter_SA[fl_channel_U8].channel_error_U8 = TRUE;

            /* Channel status is moved to Idle */
            l_dma_handler_parameter_SA[fl_channel_U8].channel_status_U8 = DMA_CH_IDLE;

            if(l_dma_handler_parameter_SA[fl_channel_U8].callback != NULL_PTR)
            {
               fl_app_resp_struct.fl_dma_channel_num_U8 = fl_channel_U8;
               fl_app_resp_struct.fl_dma_channel_status_U8 = DMA_FAILURE;
               /* Return Channel No with Failure notification in callback */
               l_dma_handler_parameter_SA[fl_channel_U8].callback(&fl_app_resp_struct);
            }
         }
      }
  }
}

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
UINT8 DMA_Handler_CheckErrorStatus(dma_channel_num_type fl_sw_chan_num_E)
{
  UINT8 fl_ret_value_U8;
  
  fl_ret_value_U8 = l_dma_handler_parameter_SA[fl_sw_chan_num_E].channel_error_U8;
  l_dma_handler_parameter_SA[fl_sw_chan_num_E].channel_error_U8 = FALSE;
  return(fl_ret_value_U8);
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
Date               : 2-September-13
CDSID              : krohini
Traceability       : RTC - 80320
Change Description : Support provided to trigger next DMA request 
                     during the callback of current DMA channel execution.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 26-June-13
CDSID              : krohini
Traceability       : dma.handler_SDS.doc
Change Description : Initial version
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
