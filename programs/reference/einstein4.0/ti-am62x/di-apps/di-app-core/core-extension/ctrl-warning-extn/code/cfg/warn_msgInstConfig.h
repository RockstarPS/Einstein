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
**==========================================================================*/

/*============================================================================
**
** Name:           hmi_msgInstConfig.inc
**
** Description:    This is for providing timer IDs to core for multiinstance and
                   single instance.Order of timers should not be changed.
				       Timers should be in the same order as in struct 
				       MSG_INST_TIMER_CONFIG_T.
**                  
** Organization:   Driver Information Software Section,
**                 Visteon
**
**============================================================================
**
**==========================================================================*/


#ifndef HMI_INST_MSG_CONFIG_INC                                                
#define HMI_INST_MSG_CONFIG_INC                                                
#include "Rte_WarnMsg_Core_TmrSupport_Type.h"    
                                           
MSG_INST_TIMER_CONFIG_T const hmi_msg_inst_config_table[MSG_NUM_INSTANCES] =          \
{ 
   {
      SEQ_DISPLAY_TIMER_ID,                                                  
      SEQ_HOLD_TIMER_ID,
      SEQ_CYCLE_TIMER_ID,
      SEQ_DISP_INDICATION_TIMER_ID,
      SEQ_ACK_AFT_MIN_TIMER_ID,
   #ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT 
      SEQ_1SEC_TIMER_ID,
   #endif
   #ifdef HMI_MSG_ENABLE_NEW_MESSAGE_SEQ_QUEUE_TIMEOUT
      SEQ_MSGQTIMEOUT_1SEC_TIMER_ID,
   #endif
   #ifdef MSG_OLD_WRNG_REPETITION 
      SEQ_OLD_WRNG_REP_1SEC_TIMER_ID,
   #endif
   #ifdef MSG_ACK_WRNG_REPETITION
      STOR_ACK_WRNG_REP_TIMER_ID,
   #endif
   }, 
   {
      HUD_SEQ_DISPLAY_TIMER_ID,                                                  
      HUD_SEQ_HOLD_TIMER_ID,
      HUD_SEQ_CYCLE_TIMER_ID,
      HUD_SEQ_DISP_INDICATION_TIMER_ID,
      HUD_SEQ_ACK_AFT_MIN_TIMER_ID,
   #ifdef MSG_CYCLE_OPTION_WITH_TIMEOUT 
      HUD_SEQ_1SEC_TIMER_ID,
   #endif
   #ifdef HMI_MSG_ENABLE_NEW_MESSAGE_SEQ_QUEUE_TIMEOUT
      HUD_SEQ_MSGQTIMEOUT_1SEC_TIMER_ID,
   #endif
   #ifdef MSG_OLD_WRNG_REPETITION 
      HUD_SEQ_OLD_WRNG_REP_1SEC_TIMER_ID,
   #endif
   #ifdef MSG_ACK_WRNG_REPETITION
      HUD_STOR_ACK_WRNG_REP_TIMER_ID,
   #endif
   }
   
};
#endif


