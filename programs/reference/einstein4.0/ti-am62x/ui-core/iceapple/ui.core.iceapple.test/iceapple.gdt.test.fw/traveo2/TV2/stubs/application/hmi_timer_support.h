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
** Name:           hmi_timer_support.h
**
** Description:    Public header file for timer_support functionality
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**==========================================================================*/
#ifndef HMI_TIMER_SUPPORT_H
#define HMI_TIMER_SUPPORT_H
#include "system.h"
#ifndef HMI_TIMER_SUPPORT_C
#define EXTERN  extern
#else
#define EXTERN
#endif

/*==========================================================================*/
/* P U B L I C M A C R O S / D E F I N I T I O N S							*/
/*==========================================================================*/

#define HMI_TIMER_CLEAR               ((UINT8)0x00)
#define HMI_TIMER_EXPIRED             ((UINT8)0x02)
#define HMI_TIMER_RUNNING             ((UINT8)0x80)
#define HMI_TIMER_NOT_RUNNING         HMI_TIMER_CLEAR

#define TIMER_CLEAR               ((UINT8)0x00)
#define TIMER_EXPIRED             ((UINT8)0x02)
#define TIMER_RUNNING             ((UINT8)0x80)
#define TIMER_NOT_RUNNING         TIMER_CLEAR


#define hmi_menu_start_KSWTIMER1	(1)
#define hmi_menu_start_KSWTIMER2	(2)
#define hmi_menu_start_KSWTIMER3	(3)
#define hmi_menu_start_KSWTIMER4	(4)
#define hmi_menu_start_KSWTIMER5	(5)



typedef enum
{
	GUI_POPUP_LAYER1_TMR_ID = 0,
	GUI_POPUP_LAYER2_TMR_ID,
	GUI_POPUP_LAYER3_TMR_ID,
	HMI_NO_OF_TIMERS
}TIMER_ID_TYPE;
typedef enum
{
	HMI_MENU_START_TIMER_ID = 0,
	HMI_MENU_STOP_TIMER_ID,
	HMI_MENU_OPEN_TIMER_ID,
	HMI_MENU_WAIT_TIMER_ID,
	HMI_NO_OF_MENU_TIMERS
}MENU_TIMER_ID_TYPE;

typedef enum
{
  WARNING_DISPLAY_TIMER_ID = 0,
  WARNING_HOLD_TIMER_ID,
  WARNING_CYCLE_TIMER_ID,
  WARNING_DISPLAYHOLD_TIMER_ID,
  WARNING_ACK_TIMER_ID,
  WARNING_SEQ_Q_TIMER_ID,
  WARNING_REDISPLAY_TIMER_ID,
  WARNING_DOOOR_FR_700MS_TIMER_ID,
  WARNING_DOOOR_FL_700MS_TIMER_ID,
  WARNING_DOOOR_RR_700MS_TIMER_ID,
  WARNING_DOOOR_RL_700MS_TIMER_ID,
  WARNING_DOOR_ANIM_TIMER_ID,
  HMI_NO_OF_WRN_TIMERS
}WARNING_TIMER_ID_TYPE;

typedef enum
{
  MODE_TRANS_ANIM_TIMER_ID = 0,
  HMI_NO_OF_TRANS_ANIM_TIMERS
}MODE_TRANS_TIMER_ID_TYPE;
/*==========================================================================*/
/* E X T E R N A L   F U N C T I O N   P R O T O T Y P E S                  */
/*==========================================================================*/
EXTERN void hmi_timer_support_task(void);
EXTERN void hmi_timer_support_init(void);
EXTERN void hmi_timer_support_start_timer(TIMER_ID_TYPE timer_id, UINT16 timeout_count, UINT16 p_evt_U16);
EXTERN void hmi_timer_support_clear_timer(TIMER_ID_TYPE timer_id);
EXTERN UINT8 hmi_timer_support_check_timer(TIMER_ID_TYPE timer_id);
EXTERN void hmi_menu_core_start_timer(UINT8 menu_id, UINT8 timer_id, UINT32 timeout_count);
EXTERN void hmi_menu_core_stop_timer(UINT8 menu_id, UINT8 timer_id);
EXTERN void hmi_wrn_ctrl_start_timer(WARNING_TIMER_ID_TYPE timer_id, UINT32 timeout_count);
EXTERN void hmi_wrn_ctrl_stop_timer(WARNING_TIMER_ID_TYPE timer_id );
EXTERN UINT8 hmi_wrn_ctrl_check_timer(WARNING_TIMER_ID_TYPE timer_id);
EXTERN void hmi_mode_trans_select_start_timer(MODE_TRANS_TIMER_ID_TYPE timer_id, UINT32 timeout_count);
EXTERN void hmi_mode_trans_select_stop_timer(MODE_TRANS_TIMER_ID_TYPE timer_id );
EXTERN UINT8 hmi_mode_trans_select_check_timer(MODE_TRANS_TIMER_ID_TYPE timer_id);
#undef EXTERN
#endif
/*==========================================================================*/
/* R E V I S I O N    N O T E S                                             */
/*==========================================================================*/
/* For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**==========================================================================*/

/****************************************************************************
**  Date  : 06/Apr/2016
**  by    : TZHANG8
    Ref   : None.
**  Change: Initial version.
**
*****************************************************************************/
/*---------------------------------------------------------------------------
Date              : 11-Sep-2019
By                : MVENKAT7
Traceability      : 590581: MY21 SU2 SVC Animation Requirement
Change Description: Added timer for GSI update in 15 cuts of 
          mode transitions animation
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 14-11-2019
By                : bhariha1
Traceability      : 629815
Change Description: Added timers for each door
-----------------------------------------------------------------------------*/
