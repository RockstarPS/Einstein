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
#define HMI_STEP_CLEAR                ((UINT32)0x00)

#define HTS_TO_SECONDS(x)             (((UINT16)x  * (UINT16)1000) / HMI_DISPLAY_REFRESH_RATE_IN_MS)
#define HTS_TO_MILLISECONDS(x)        (((UINT16)x                  / HMI_DISPLAY_REFRESH_RATE_IN_MS)

#define TIMEOUT_10MIN  (HTS_TO_SECONDS(600))
#define TIMEOUT_3SEC   (HTS_TO_SECONDS(3))
#define TIMEOUT_5SEC   (HTS_TO_SECONDS(5))
#define TIMEOUT_1SEC   (HTS_TO_SECONDS(1))
#define TIMEOUT_25SEC  (HTS_TO_SECONDS(25))


typedef enum
{
GUI_POPUP_LAYER0_TMR_ID,
GUI_POPUP_LAYER1_TMR_ID,
GUI_POPUP_LAYER5_TMR_ID,
GUI_POPUP_LAYER9_TMR_ID,
GUI_POPUP_LAYER10_TMR_ID,
GUI_POPUP_LAYER0_MIN_TMR_ID ,
GUI_POPUP_LAYER1_MIN_TMR_ID ,
GUI_POPUP_LAYER3_MIN_TMR_ID ,
GUI_POPUP_LAYER9_MIN_TMR_ID,
GUI_POPUP_ATE0_TMR_ID       ,                                 /*      POPUP_PROG_1_0                   */
GUI_POPUP_ATE1_TMR_ID       ,                                 /*      POPUP_KEYPAD_1_1                 */
GUI_POPUP_ATE2_TMR_ID       ,                                 /*      POPUP_ACK_1_3      */
GUI_POPUP_ATE3_TMR_ID       ,                                 /*      POPUP_PROG_5_2                   */
GUI_POPUP_ATE4_TMR_ID       ,                                 /*      POPUP_ACK_5_3      */
GUI_POPUP_ATE5_TMR_ID,                                         /*      POPUP_ACK_5_3      */
HMI_NO_OF_TIMERS
}TIMER_ID_TYPE;

/*==========================================================================*/
/* E X T E R N A L   F U N C T I O N   P R O T O T Y P E S                  */
/*==========================================================================*/

EXTERN void   hmi_timer_support_start_timer(TIMER_ID_TYPE timer_id, unsigned int timeout_count, unsigned short p_evt_U16);
EXTERN void   hmi_timer_support_clear_timer(TIMER_ID_TYPE timer_id);
EXTERN UINT8  hmi_timer_support_check_timer(TIMER_ID_TYPE timer_id);
EXTERN void   hmi_timer_support_task(void);
EXTERN unsigned int hmi_timer_support_get_active_step(unsigned int total_no_of_steps,TIMER_ID_TYPE timer_id);
EXTERN void   hmi_timer_support_coldinit(void);
EXTERN void   hmi_timer_support_warminit(void);
EXTERN void   hmi_timer_support_sleep(void);
EXTERN void   hmi_timer_support_wakeup(void);
void hmi_timer_support_expire(TIMER_ID_TYPE timer_id);

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
**  Date  : 05/08/2010
**  by    : RBHARAT2
    Ref   : None.
**  Change: Initial version.
**
*****************************************************************************/
/*---------------------------------------------------------------------------
Date              : 30-Sep-2010
CDSID             : SPANDIAN
Traceability      : HMI_MESSAGE_CORE_01_01.02.02
Change Description: timer added as per the New message core update
-----------------------------------------------------------------------------*/
/****************************************************************************
**  Date  : 15/10/2010
**  by    : spandian
    Ref   : CQ 91867
**  Change: New warning id configured for CTA warning Toggling. and Status size increased to UINT16
**
*****************************************************************************/
/****************************************************************************
Date         : 24-03-11
CDSID        : jpradeep
Traceability : Unsegmented progress bar implementation
Change       : The display update rate has  been set as 32ms which is
               earlier as 100
*****************************************************************************/
