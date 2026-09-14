/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2010. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**============================================================================
**
** Name:           hmi_gfx_interface_dik.c
**
** Description:    This module handles the application graphics command request
**                 with a FIFO queue mechanism. The queue is to decouple the
**                 application graphics presentation from the graphics building
**                 which will be happening in a pre-emptable task DI Kernel
**                 graphics task. This file is specific to applications running
**                 on DI-Kernel.
**
** Organization:   Driver Information Software Section,
**                 Visteon
**
**============================================================================
**
**==========================================================================*/
#define HMI_GFX_INTERFACE_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_interface.h"
#if (NB_DYN_TEXTS+NB_DYNXY_TEXTS) > 0
   #include "hmi_language_interface.h"
#endif

/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/

/*
** Macros for incrementing the queue index in circular fashion.
*/
#define HMI_GRAPHICS_QUEUE_MAX_CHAR_MASK      (HMI_GFX_IF_QUEUE_SIZE-1)
#define HMI_MOVE_Q_INDEX(index)               (index ++); \
                                              (index &= HMI_GRAPHICS_QUEUE_MAX_CHAR_MASK)
#define HMI_MOVE_Q_INDEX_BY_VAL(index, val)   (index += val); \
                                              (index &= HMI_GRAPHICS_QUEUE_MAX_CHAR_MASK)

/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/

static BOOLEAN hmi_gfx_if_check_queue_space(GFX_IF_CMD_T p_cmd_id_Ux, GFX_TEXT_LENGTH_T p_strlen_Ux);

/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/

/*
** ROM table containing command size in bytes for the graphics
** commands defined by GFX_IF_CMD_T. Table entry shall be in the
** same order as the command entry in GFX_IF_CMD_T.
*/
static const UINT8 lc_gfx_if_command_size_U8A[] =
{
    (0),
    (1 + 2 + 4),    /* HMI_GFX_IF_SEND_EVENT        */
#if (NB_DYN_TEXTS+NB_DYNXY_TEXTS) > 0
    (1 + 2 + 1),    /* HMI_GFX_IF_SEND_TEXT_CMD     */
    (1 + 2 + 2),    /* HMI_GFX_IF_SEND_SID_CMD      */
#endif
#if HMI_GFX_IF_NEED_FADE_CMD > 0
    (1+2),          /* HMI_GFX_IF_FADE_IN_CMD       */
#endif
#if HMI_GFX_IF_NEED_VIDEO_IN_CMD > 0
    (1),            /* HMI_GFX_IF_VIDEO_ENABLE_CMD  */
    (1),            /* HMI_GFX_IF_VIDEO_DISABLE_CMD */
#endif
    (1),            /* HMI_GFX_IF_FLUSH_OUTPUT_CMD  */
    (1+1)           /* HMI_GFX_IF_FLUSH_INLINE_CMD  */
};

/*
** Command queue allocation and FIFO handling.
** l_gfx_if_command_queue_U8A    - command fifo queue
** l_gfx_if_queue_write_index_UX - points to the next free location to write.
** l_gfx_if_queue_read_index_UX  - points to the next read location
*/
static UINT8              l_gfx_if_command_queue_U8A[HMI_GFX_IF_QUEUE_SIZE];
static GFX_IF_CMD_INDEX_T l_gfx_if_queue_write_index_Ux;
static GFX_IF_CMD_INDEX_T l_gfx_if_queue_read_index_Ux;
static UINT8              l_gfx_if_update_pending_U8;
#if defined(WIN32) || defined(WINCE)
  static CRITICAL_SECTION l_tcritical_section;
#endif

/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

/*============================================================================
** Function Name:    hmi_gfx_if_initialize
** Visibility:       global
** Description:      Initialization function to initialize all variable
**                   maintained by Gfx interface component.
** Invocation:       Invoked by application when ever necessary.
** Inputs/Outputs:   p_cold_init_BOOL indicates the init type as Cold or Warm.
** Critical Section: None.
** Created:          03-Mar-2010 by EMANOJ1
** Created:          03-Mar-2010 by EMANOJ1
**==========================================================================*/
void hmi_gfx_if_initialize(UINT8 p_cold_init_BOOL)
{
#if defined(WIN32) || defined(WINCE)
   InitializeCriticalSection(&l_tcritical_section);
#endif
   l_gfx_if_queue_write_index_Ux = 0;
   l_gfx_if_queue_read_index_Ux  = 0;
   l_gfx_if_update_pending_U8    = FALSE;
}

/*============================================================================
** Function Name:    hmi_gfx_if_exit
** Visibility:       global
** Description:      Deletes all objects created
** Invocation:
** Inputs/Outputs:   None
** Critical Section: None.
** Created:          21-Mar-2011 by EMANOJ1
** Created:          21-Mar-2011 by EMANOJ1
**==========================================================================*/
void hmi_gfx_if_exit(void)
{
#if defined(WIN32) || defined(WINCE)
   DeleteCriticalSection(&l_tcritical_section);
#endif
}

#if HMI_GFX_IF_NEED_FADE_CMD > 0
/*============================================================================
** Function Name:    hmi_gfx_if_send_fade_cmd
** Visibility:       global
** Description:      Pushes the fade in command in to the queue if queue has
**                   space to hold the entire command.
** Invocation:       Invoked by application when ever necessary.
** Inputs/Outputs:   p_fadein_config_id_U16 - indicates the fadein profile ID
**                   which is used to select between different fade profiles
**                   (rate of change of fade, fade in/out etc..)
** Critical Section: None.
** Created:          03-Mar-2010 by EMANOJ1
** Created:          03-Mar-2010 by EMANOJ1
**==========================================================================*/
void hmi_gfx_if_send_fade_cmd(UINT16 p_fadein_config_id_U16)
{
   if(hmi_gfx_if_check_queue_space(HMI_GFX_IF_FADE_IN_CMD, 0) != FALSE)
   {
      l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = HMI_GFX_IF_FADE_IN_CMD;
      HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
      l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = (UINT8)(p_fadein_config_id_U16 >> 8);
      HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
      l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = (UINT8)(p_fadein_config_id_U16);
      HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
   }
}
#endif /* #if HMI_GFX_IF_NEED_FADE_CMD > 0 */

/*============================================================================
** Function Name:    hmi_gfx_if_send_data_cmd
** Visibility:       global
** Description:      Pushes the data value for the specified element in to the
**                   queue.
** Invocation:       Invoked by application when ever necessary.
** Inputs/Outputs:   p_element_id   - Indicates the ID of the element to which a
**                   a new data needs to be written.
**                   p_element_data - Indicates the data value to be set for the
**                   specified element ID.
** Critical Section: None.
** Created:          03-Mar-2010 by EMANOJ1
** Created:          03-Mar-2010 by EMANOJ1
**==========================================================================*/
void hmi_gfx_if_send_data_cmd(GFX_ELEMENT_ID_T p_element_id, SINT32 p_element_data)
{
   if(p_element_id < (NB_DYN_ELEMENTS+NB_ALL_DYN_XY_BITMAPS))
   {
      if(hmi_gfx_if_check_queue_space(HMI_GFX_IF_SEND_EVENT_CMD, 0) != FALSE)
      {
         l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = HMI_GFX_IF_SEND_EVENT_CMD;
         HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
         l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = (UINT8)((UINT32)p_element_id >> 8);
         HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
         l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = (p_element_id);
         HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
         l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = (UINT8)(p_element_data>>24);
         HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
         l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = (UINT8)(p_element_data>>16);
         HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
         l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = (UINT8)(p_element_data>>8);
         HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
         l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = (UINT8)(p_element_data);
         HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
      }
   }
}

#if (NB_DYN_TEXTS+NB_DYNXY_TEXTS) > 0
/*============================================================================
** Function Name:    hmi_gfx_if_send_text_cmd
** Visibility:       global
** Description:      Pushes the text string data value for the specified text
**                   element in to the queue.
** Invocation:       Invoked by application when ever necessary.
** Inputs/Outputs:   p_element_id   - Indicates the ID of the text element to
**                   which a new text string needs to be written.
**                   p_string       - Pointer to new text string.
** Critical Section: None.
** Created:          03-Mar-2010 by EMANOJ1
** Created:          03-Mar-2010 by EMANOJ1
**==========================================================================*/
void hmi_gfx_if_send_text_cmd(GFX_ELEMENT_ID_T p_element_id, GFX_CHAR const * p_string)
{
   if((p_string != NULL) && (p_element_id < (NB_DYN_ELEMENTS+NB_ALL_DYN_XY_BITMAPS)))
   {
      GFX_TEXT_LENGTH_T fl_strlen_Ut = (GFX_TEXT_LENGTH_T)HMI_STRLEN(p_string); /* Include the Null Termination Char also */;

      if(fl_strlen_Ut > (GFX_MAX_TEXT_LENGTH-1))
      {
         fl_strlen_Ut = (GFX_MAX_TEXT_LENGTH-1);
      }
   #if GFX_UNICODE_ENABLED
      if(hmi_gfx_if_check_queue_space(HMI_GFX_IF_SEND_TEXT_CMD, (fl_strlen_Ut<<1)) != FALSE)
   #else
      if(hmi_gfx_if_check_queue_space(HMI_GFX_IF_SEND_TEXT_CMD, fl_strlen_Ut) != FALSE)
   #endif
      {
         l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = HMI_GFX_IF_SEND_TEXT_CMD;
         HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
         l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] =  (UINT8)((UINT32)p_element_id >> 8);
         HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
         l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] =  (UINT8)(p_element_id & 0x00FF);
         HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
         l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] =  fl_strlen_Ut;
         HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);

         while(fl_strlen_Ut > 0)
         {
            fl_strlen_Ut--;
            l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = (UINT8)(*p_string);
         #if GFX_UNICODE_ENABLED
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
            l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = (UINT8)(*p_string >> 8);
         #endif
            p_string = &p_string[1];
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
         }
      }
   }
}

/*============================================================================
** Function Name:    hmi_gfx_if_send_sid_cmd
** Visibility:       global
** Description:      Pushes the text string data value for the specified text
**                   element in to the queue.
** Invocation:       Invoked by application when ever necessary.
** Inputs/Outputs:   p_element_id   - Indicates the ID of the text element to
**                   which a new text string needs to be written.
**                   p_string       - Pointer to new text string.
** Critical Section: None.
** Created:          03-Mar-2010 by EMANOJ1
** Created:          03-Mar-2010 by EMANOJ1
**==========================================================================*/
void hmi_gfx_if_send_sid_cmd(GFX_ELEMENT_ID_T p_element_id, LANG_SID_T p_sid_U32)
{
   UINT32 fl_temp_U32;
   if(p_element_id < (NB_DYN_ELEMENTS+NB_ALL_DYN_XY_BITMAPS))
   {
      if(hmi_gfx_if_check_queue_space(HMI_GFX_IF_SEND_SID_CMD, 0) != FALSE)
      {
         l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = HMI_GFX_IF_SEND_SID_CMD;
         HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
         l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] =  (UINT8)((UINT32)p_element_id >> 8);
         HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
         l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] =  (UINT8)(p_element_id & 0x00FF);
         HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
         l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] =  (UINT8)((UINT32)p_sid_U32 >> 16);     /* MSB */
         HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);

         fl_temp_U32 = (p_sid_U32 & 0x0ff00ul);
         fl_temp_U32 = (fl_temp_U32 >> 8);

         l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] =  (UINT8)(fl_temp_U32);         /* 2nd-MSB */
         HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
         l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] =  (UINT8)(p_sid_U32 & 0x00FF);  /* LSB */
         HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
      }
   }
}
#endif /* #if (NB_DYN_TEXTS+NB_DYNXY_TEXTS) > 0 */


/*============================================================================
** Function Name:    hmi_gfx_if_update_inline_cmd
** Visibility:       global
** Description:      Pushes the command to perform an inline screen building
**                   Normal update will cause the screen bulding to happen
**                   only at the end of the graphics task. So inline will be
**                   useful while implementing animations.
**                   Also triggers the graphics task
** Invocation:       Invoked by application when ever necessary.
** Inputs/Outputs:   p_postcopy_U8 - Specifies a post copy needs to be performed
**                   per layer after the screen is built. Post copy is to make
**                   a copy of the currenty built screen to the backbuffer, so
**                   that we could rework area's which needs an update. But while
**                   doing an animation it may not be necessary to perform the
**                   post copy as the next frame will be overwritting the screen
**                   content bacause it might be a completely different content.
**                   So by disabling post copy, we could save the time required
**                   for doing the post copy there by improve the animation speed.
**                   This flag is bit encoded. Bit0 maps to layer0, Bit1 - Layer1
**                   etc. If corresponding bit is set to 1, post copy is done for
**                   the layer otherwise not performed.
** Critical Section: None.
** Created:          03-Mar-2010 by EMANOJ1
** Created:          03-Mar-2010 by EMANOJ1
**==========================================================================*/
void hmi_gfx_if_update_inline_cmd(UINT8 p_precopy_U8)
{
   if(hmi_gfx_if_check_queue_space(HMI_GFX_IF_FLUSH_OUTPUT_CMD, 0) != FALSE)
   {
      l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = HMI_GFX_IF_FLUSH_INLINE_CMD;
      HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
      l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = p_precopy_U8;
      HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
   }
#if defined(WIN32) || defined(WINCE)
   EnterCriticalSection(&l_tcritical_section);
#endif
   l_gfx_if_update_pending_U8 = TRUE;
#if defined(WIN32) || defined(WINCE)
   LeaveCriticalSection(&l_tcritical_section);
#endif
}

/*============================================================================
** Function Name:    hmi_gfx_if_update_cmd
** Visibility:       global
** Description:      Pushes the command to perform a screen building
**                   Screen bulding will happen at the end of the graphics task
**                   whne it nuns for the next time.
**                   Also triggers the graphics task
** Invocation:       Invoked by application when ever necessary.
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          03-Mar-2010 by EMANOJ1
** Created:          03-Mar-2010 by EMANOJ1
**==========================================================================*/
void hmi_gfx_if_update_cmd(void)
{
   if(hmi_gfx_if_check_queue_space(HMI_GFX_IF_FLUSH_OUTPUT_CMD, 0) != FALSE)
   {
      l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = HMI_GFX_IF_FLUSH_OUTPUT_CMD;
      HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
   }
#if defined(WIN32) || defined(WINCE)
   EnterCriticalSection(&l_tcritical_section);
#endif
   l_gfx_if_update_pending_U8 = TRUE;
#if defined(WIN32) || defined(WINCE)
   LeaveCriticalSection(&l_tcritical_section);
#endif
}

/*============================================================================
** Function Name:    hmi_gfx_if_get_update_pending
** Visibility:       global
** Description:      Returns the update pending status and clears the internal
**                   flag.
** Invocation:       Invoked by application to know whether any update is
**                   pending so that graphics task could be triggered.
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          07-Mar-2010 by EMANOJ1
** Created:          07-Mar-2010 by EMANOJ1
**==========================================================================*/
UINT8 hmi_gfx_if_get_update_pending(void)
{
   UINT8 fl_gfx_if_update_pending_U8 = l_gfx_if_update_pending_U8;
#if defined(WIN32) || defined(WINCE)
   EnterCriticalSection(&l_tcritical_section);
#endif
   l_gfx_if_update_pending_U8 = FALSE;
#if defined(WIN32) || defined(WINCE)
   LeaveCriticalSection(&l_tcritical_section);
#endif
   return(fl_gfx_if_update_pending_U8);
}

#if HMI_GFX_IF_NEED_VIDEO_IN_CMD > 0
/*============================================================================
** Function Name:    hmi_gfx_if_enable_video_in_cmd
** Visibility:       global
** Description:      Pushes the command to perform video input enable
**                   command (only applicable to the yukawa platform).
** Invocation:       Invoked by application when ever necessary.
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          03-Mar-2010 by EMANOJ1
** Created:          03-Mar-2010 by EMANOJ1
**==========================================================================*/
void hmi_gfx_if_enable_video_in_cmd(void)
{
   if(hmi_gfx_if_check_queue_space(HMI_GFX_IF_VIDEO_ENABLE_CMD, 0) != FALSE)
   {
      l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = HMI_GFX_IF_VIDEO_ENABLE_CMD;
      HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
   }
}

/*============================================================================
** Function Name:    hmi_gfx_if_disable_video_in_cmd
** Visibility:       global
** Description:      Pushes the command to perform video input disable
**                   command (only applicable to the yukawa platform).
** Invocation:       Invoked by application when ever necessary.
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          03-Mar-2010 by EMANOJ1
** Created:          03-Mar-2010 by EMANOJ1
**==========================================================================*/
void hmi_gfx_if_disable_video_in_cmd(void)
{
   if(hmi_gfx_if_check_queue_space(HMI_GFX_IF_VIDEO_DISABLE_CMD, 0) != FALSE)
   {
      l_gfx_if_command_queue_U8A[l_gfx_if_queue_write_index_Ux] = HMI_GFX_IF_VIDEO_DISABLE_CMD;
      HMI_MOVE_Q_INDEX(l_gfx_if_queue_write_index_Ux);
   }
}
#endif /* #if HMI_GFX_IF_NEED_VIDEO_IN_CMD > 0 */

/*============================================================================
** Function Name:    hmi_gfx_if_check_queue_space
** Visibility:       static
** Description:      Checks whether the command can be accomodated in to the queue.
** Invocation:       Invoked internally.
** Inputs/Outputs:   p_cmd_id_Ux - command id for which space needs to be checked.
**                   p_strlen_Ux - indicates the length of string data in case of
**                                 HMI_GFX_IF_SEND_TEXT_CMD.
** Critical Section: None.
** Created:          03-Mar-2010 by EMANOJ1
** Created:          03-Mar-2010 by EMANOJ1
**==========================================================================*/
static BOOLEAN hmi_gfx_if_check_queue_space(GFX_IF_CMD_T p_cmd_id_Ux, GFX_TEXT_LENGTH_T p_strlen_Ux)
{
   UINT16 fl_space_U8;
   UINT8  fl_ret_value_U8 = FALSE;

   if(l_gfx_if_queue_read_index_Ux > l_gfx_if_queue_write_index_Ux)
   {
      fl_space_U8  = (l_gfx_if_queue_read_index_Ux - l_gfx_if_queue_write_index_Ux);
   }
   else
   {
      fl_space_U8  = (HMI_GFX_IF_QUEUE_SIZE - l_gfx_if_queue_write_index_Ux);
      fl_space_U8 += l_gfx_if_queue_read_index_Ux;
   }
   fl_space_U8++;

   if( fl_space_U8 >= (lc_gfx_if_command_size_U8A[p_cmd_id_Ux] + p_strlen_Ux))
   {
      fl_ret_value_U8 = TRUE;
   }

   return(fl_ret_value_U8);
}

/*============================================================================
** Function Name:    Graphics_Task
** Visibility:       global
** Description:      DI Kernel GT.
** Invocation:       Invoked by DIK.
** Inputs/Outputs:   None.
** Critical Section: None.
** Created:          03-Mar-2010 by EMANOJ1
** Created:          03-Mar-2010 by EMANOJ1
**==========================================================================*/
void Graphics_Task(void)
{
#if (NB_DYN_TEXTS+NB_DYNXY_TEXTS) > 0
   GFX_CHAR         * fl_ptr;
   GFX_CHAR           fl_text_A[GFX_MAX_TEXT_LENGTH];
   UINT8              fl_count1_U8;
   UINT8              fl_count2_U8;
#endif
#if HMI_GFX_IF_NEED_VIDEO_IN_CMD > 0
   UINT8              fl_video_en     = FALSE;
#endif

   UINT32             fl_data_U32;
   UINT8              fl_cmd_U8;
   UINT16             fl_object_U16;
   UINT8              fl_build_screen = FALSE;
   GFX_IF_CMD_INDEX_T fl_write_index_U8;

   fl_write_index_U8 = l_gfx_if_queue_write_index_Ux;

   while ((l_gfx_if_queue_read_index_Ux != fl_write_index_U8))
   {
      fl_cmd_U8 = l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux];

      HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);

      switch(fl_cmd_U8)
      {
         case HMI_GFX_IF_SEND_EVENT_CMD:
         {
            fl_object_U16 = (((UINT16)l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux]) << 8);
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
            fl_object_U16 |= (UINT16) l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux];
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
            fl_data_U32 = (((UINT32)l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux]) << 24);
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
            fl_data_U32 |= (((UINT32)l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux]) << 16);
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
            fl_data_U32 |= (((UINT32)l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux]) << 8);
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
            fl_data_U32 |= (UINT32) l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux];
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
            GfxManagerSendEvent((GFX_ELEMENT_ID_T)fl_object_U16, (SINT32)fl_data_U32);
         }
         break;
      #if (NB_DYN_TEXTS+NB_DYNXY_TEXTS) > 0
         case HMI_GFX_IF_SEND_TEXT_CMD:
         {
            fl_object_U16 = (((UINT16)l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux]) << 8);
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
            fl_object_U16 |= (UINT16) l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux];
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
            fl_count2_U8 = l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux];
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
            fl_ptr = &fl_text_A[0];
            for(fl_count1_U8 = 0; fl_count1_U8 < fl_count2_U8; fl_count1_U8++, fl_ptr++)
            {
               *fl_ptr  = l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux];
               HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
            #if GFX_UNICODE_ENABLED
               *fl_ptr += (l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux]<<8);
               HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
            #endif
            }
            if(*fl_ptr != 0)
            {
               *fl_ptr = 0;
            }
            GfxManagerSendText((GFX_ELEMENT_ID_T)fl_object_U16, &fl_text_A[0]);
         }
         break;
         case HMI_GFX_IF_SEND_SID_CMD:
         {
            /* Retrive the string from the SID Table */
            fl_object_U16 = (((UINT16)l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux]) << 8);
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
            fl_object_U16 |= (UINT16) l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux];
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
            fl_data_U32 = (((UINT32)l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux]) << 16);   /* MSB */
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
            fl_data_U32 |= (((UINT32)l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux]) << 8);   /* 2nd-MSB */
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
            fl_data_U32 |= (UINT32) l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux];
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
			GfxManagerSendText((GFX_ELEMENT_ID_T)fl_object_U16, hmi_language_if_get_string_ptr(fl_data_U32));
         }
         break;
      #endif
      #if HMI_GFX_IF_NEED_FADE_CMD > 0
         case HMI_GFX_IF_FADE_IN_CMD:
         {
            fl_object_U16 = (((UINT16)l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux]) << 8);
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
            fl_object_U16 |= (UINT16) l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux];
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
            GfxDriverSetFadeEffect(fl_object_U16);
         }
         break;
      #endif
      #if HMI_GFX_IF_NEED_VIDEO_IN_CMD > 0
         case HMI_GFX_IF_VIDEO_ENABLE_CMD:
         {
             fl_video_en = TRUE;
         }
         break;

         case HMI_GFX_IF_VIDEO_DISABLE_CMD:
         {
             GfxDriverDisableVideoInput();
         }
         break;
      #endif
         case HMI_GFX_IF_FLUSH_OUTPUT_CMD:
         {
            fl_build_screen = TRUE;
         }
         break;


         case HMI_GFX_IF_FLUSH_INLINE_CMD:
         {
         #if GFX_MANAGER_NEED_POST_COPY_USER_CONTROL > 0
            GfxManagerBuildScreen(l_gfx_if_command_queue_U8A[l_gfx_if_queue_read_index_Ux]);
         #else
            GfxManagerBuildScreen();
         #endif
            HMI_MOVE_Q_INDEX(l_gfx_if_queue_read_index_Ux);
         #if HMI_GFX_IF_NEED_VIDEO_IN_CMD > 0
            if(fl_video_en != FALSE)
            {
               GfxDriverEnableVideoInput();
               fl_video_en = FALSE;
            }
         #endif
            fl_build_screen = FALSE;
         }
         break;

         default:
         {
         }
         break;
      }
   }
   if(fl_build_screen != FALSE)
   {
   #if GFX_MANAGER_NEED_POST_COPY_USER_CONTROL > 0
      GfxManagerBuildScreen((UINT8)((1<<NB_LAYERS)-1));
   #else
      GfxManagerBuildScreen();
   #endif
   #if HMI_GFX_IF_NEED_VIDEO_IN_CMD > 0
      if(fl_video_en != FALSE)
      {
         GfxDriverEnableVideoInput();
      }
   #endif
   }
}

/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================
**
** Rev 1.3          28-Sep-2010    vsarava2
** Changed the SID command parameter data type from U16 to U32.
**
** Rev 1.2          16-Apr-2010    gyuvamat
** Fixed QAC warnings.
**
** Rev 1.1          28-Mar-2010    gramkuma
** Changed UINT16_T to UINT16 in function wchar_t * L(char * p_ascii_str_ptr)
**
** Rev 1.0          03-Mar-2010    EMANOJ1
** Leveraged from the V227 MC NA Instrument cluster program.
**==========================================================================*/

/* end of file =============================================================*/
