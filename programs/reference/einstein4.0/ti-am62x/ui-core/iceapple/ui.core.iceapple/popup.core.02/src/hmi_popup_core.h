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
** Name:            hmi_popup_core_02.h
**
** Description:    Header file for the popup core
**
** Organization:   Driver Information Software Section,
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_POPUP_CORE_02_H
#define HMI_POPUP_CORE_02_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/

/* Version check for popup core and popup core tool */
#define HMI_POPUP_CORE_MAJOR_VERSION	4
#define HMI_POPUP_CORE_MINOR_VERSION	13
#define HMI_POPUP_CORE_VERSION     ((HMI_POPUP_CORE_MAJOR_VERSION * 100) + HMI_POPUP_CORE_MINOR_VERSION)
#define HMI_POPUP_CORE_LABEL "POPUP_CORE_LABEL::rel-UI-CORE-ICEAPPLE-4.13"

#define POPUP_INFO            (0x01)
#define POPUP_KEYPAD          (0x02)
#define POPUP_PROGRESS        (0x03)
#define POPUP_ACK             (0x04)
#define LAST_POPUP_TYPE       (POPUP_ACK)

#define NO_GROUP_PRIORITY     (0x00)
#define GROUP_PRIORITY_1      (0x01)
#define GROUP_PRIORITY_2      (0x02)
#define GROUP_PRIORITY_3      (0x03)
#define GROUP_PRIORITY_4      (0x04)
#define GROUP_PRIORITY_5      (0x05)
#define GROUP_PRIORITY_6      (0x06)
#define GROUP_PRIORITY_7      (0x07)
#define GROUP_PRIORITY_8      (0x08)
#define GROUP_PRIORITY_9      (0x09)
#define GROUP_PRIORITY_10     (0x0a)
#define GROUP_PRIORITY_11     (0x0b)
#define GROUP_PRIORITY_12     (0x0c)
#define GROUP_PRIORITY_13     (0x0d)
#define GROUP_PRIORITY_14     (0x0e)
#define GROUP_PRIORITY_15     (0x0f)
#define LAST_GROUP_PRIORITY   (GROUP_PRIORITY_15)


#define RESTART_TIMER         (0x00)
#define ALLOW_TO_EXPIRE       (0x02)

#define NO_SELF_DEACTIVATION  (0x00)
#define SELF_DEACTIVATION     (0x01)

#define DEACTIVATION_DISABLED (0x00)
#define DEACTIVATION_ENABLED  (0x01)

#define ACTIVATE_POPUP(x)                   l_pp_id_sts_bit_U8[(x/(UINT8)8)]=((l_pp_id_sts_bit_U8[(x/(UINT8)8)]) | (UINT8)((UINT8)1<<(x%(UINT8)8)))
#define DEACTIVATE_POPUP(x)                 l_pp_id_sts_bit_U8[(x/(UINT8)8)]=((l_pp_id_sts_bit_U8[(x/(UINT8)8)]) & (UINT8)(~(((UINT8)1)<<(UINT8)(((UINT8)x)%((UINT8)8)))))
#define POPUP_ACTIVE(x)                     (((l_pp_id_sts_bit_U8[(x/(UINT8)8)]) & (UINT8)((UINT8)1<<(x%(UINT8)8))) == (UINT8)((UINT8)1<<(UINT8)(x%(UINT8)8)))
#define POPUP_ACTIVE_LSH(x)                 (((l_pp_id_lsh_sts_bit_U8[((x)/(UINT8)8)]) & (UINT8)((UINT8)1<<((x)%(UINT8)8))) == ((UINT8)1<<(UINT8)((x)%(UINT8)8)))
#define ACTIVATE_LSH_POPUP(x)               l_pp_id_lsh_sts_bit_U8[(x/(UINT8)8)]=((l_pp_id_lsh_sts_bit_U8[(x/(UINT8)8)]) | (UINT8)((UINT8)1<<(x%(UINT8)8)))
#define DEACTIVATE_LSH_POPUP(x)             l_pp_id_lsh_sts_bit_U8[(x/(UINT8)8)]=((l_pp_id_lsh_sts_bit_U8[(x/(UINT8)8)]) &(UINT8)(~(((UINT8)1)<<(UINT8)(((UINT8)x)%((UINT8)8)))))
#define POPUP_SELF_DEACTIVTION(x)           (lc_popup_config_table[x].self_deactivate_pp==(UINT8)SELF_DEACTIVATION)
#define LOW_PRIORITY_PP_SELF_DEACTIVTION(x) POPUP_SELF_DEACTIVTION(x)

#define ENABLE_TIMER_STATUS(x)              l_pp_id_tmr_bit_U8[(x/(UINT8)8)]=((l_pp_id_tmr_bit_U8[(x/(UINT8)8)]) | (UINT8)((UINT8)1<<(x%(UINT8)8)))
#define DISABLE_TIMER_STATUS(x)             l_pp_id_tmr_bit_U8[(x/(UINT8)8)]=((l_pp_id_tmr_bit_U8[(x/(UINT8)8)]) & (UINT8)(~(((UINT8)1)<<(UINT8)(((UINT8)x)%((UINT8)8)))))
#define IS_TIMER_STATUS_ENABLE(x)           (((l_pp_id_tmr_bit_U8[(x/(UINT8)8)]) & (UINT8)((UINT8)1<<(x%(UINT8)8))) == ((UINT8)1<<(x%(UINT8)8)))
#define SET_MIN_TIMER_DEACTIVATE_PENDING(x) l_min_tmr_bit_U8_ptr[(x/(UINT8)8)]=((l_min_tmr_bit_U8_ptr[(x/(UINT8)8)]) | (UINT8)((UINT8)1<<(x%(UINT8)8)))
#define CLEAR_MIN_TIMER_DEACTIVATE_PENDING(x) l_min_tmr_bit_U8_ptr[(x/(UINT8)8)]=((l_min_tmr_bit_U8_ptr[(x/(UINT8)8)]) & (UINT8)(~(((UINT8)1)<<(UINT8)(((UINT8)x)%((UINT8)8)))))
#define MIN_TIMER_DEACTIVATE_PENDING(x)     (((l_min_tmr_bit_U8_ptr[(x/(UINT8)8)]) & (UINT8)((UINT8)1<<(x%(UINT8)8))) == ((UINT8)1<<(x%(UINT8)8)))

#define TIMERTYPE_RESTART(x)                (lc_popup_config_table[x].timer==(UINT8)RESTART_TIMER)
#define TIMERTYPE_ALLOWTO_EXPIRE(x)         (lc_popup_config_table[x].timer==(UINT8)ALLOW_TO_EXPIRE)

#define DEACTIVATE_ACTIVE_PP(x)             (lc_popup_config_table[x].deactivate_active_pp==(UINT8)DEACTIVATION_ENABLED)
#define GROUP_PRIORITY(x)                   (lc_popup_config_table[x].group_priority)
#define LOGIC_STATE_ID(x)                   (lc_popup_config_table[x].lsh_id)
#define POPUP_TYPE(x)                       (lc_popup_config_table[x].type)

#define POUP_EVENT_HANDLER(x)               lc_popup_config_table[x].pp_evt_handler_ptr
#define POUP_FOCUS_HANDLER(x)               lc_popup_config_table[x].pp_focus_handler_ptr
#define POUP_PRESENT_HANDLER(x)             lc_popup_config_table[x].pp_present_handler_ptr
#define POUP_CORE_HANDLER(x)                lc_popup_config_table[x].pp_popup_handler_ptr
#define POPUP_MINIMUM_TIME(x)               lc_popup_config_table[x].min_timeout

#define MAX_GROUP_PRIORITY(x)               ((POPUP_ID)x->l_total_grp_priority_count)
#define POPUP_LAYER_START_INDEX(x)          ((POPUP_ID)(x->l_pp_start_index))
#define POPUP_LAYER_TOTALCOUNT(x)           ((POPUP_ID)(x->l_total_pp_count))

#define VALID_POPUP_TYPE(x)                 (POPUP_TYPE(x)<=LAST_POPUP_TYPE)
#define VALID_GROUP_PRIORITY(x,y)           (GROUP_PRIORITY(x)<=MAX_GROUP_PRIORITY(y))
#define MAX_LAYER_POPUP_ID(x)               ((POPUP_ID)(POPUP_LAYER_START_INDEX((x))+POPUP_LAYER_TOTALCOUNT((x))))
#define POPUP_ID_INDEX(x)                   (lc_popup_config_table[x].index)


#ifdef POPUP_TYPE_PROGRESSBAR
#define PROGRESSBAR_PP_MAXCOUNT(x)          (l_total_pp_type.l_progress_bar_pp_table_ptr[POPUP_ID_INDEX(x)].l_progress_max_count_U8)
#define PROGRESSBAR_PP_CURRENTCOUNT(x)      (*(l_total_pp_type.l_progress_bar_pp_table_ptr[POPUP_ID_INDEX(x)].l_progress_counter_U8))
#define PROGRESSBAR_PP_CNTR_REACH_MAXCNT(x) (PROGRESSBAR_PP_CURRENTCOUNT(x)>=PROGRESSBAR_PP_MAXCOUNT(x))
#define PROGRESSBAR_PP_INC_COUNT(x)         ((*(l_total_pp_type.l_progress_bar_pp_table_ptr[POPUP_ID_INDEX(x)].l_progress_counter_U8))++)
#define PROGRESSBAR_PP_INIT_CURRENTCOUNT(x) ((*(l_total_pp_type.l_progress_bar_pp_table_ptr[POPUP_ID_INDEX(x)].l_progress_counter_U8))=0)
#endif

#ifdef POPUP_TYPE_KEYPAD
#define KEYPAD_PP_TBL_PTR(x)                (&l_total_pp_type.l_keypad_entry_pp_table_ptr[POPUP_ID_INDEX(x)])
#define KEYPAD_PP_MAXTIMECOUNT(x)           ((lc_popup_config_table[x].layer_timeout/l_total_pp_type.l_keypad_entry_pp_table_ptr[POPUP_ID_INDEX(x)].l_multi_press_timeout))
#define KEYPAD_PP_MULTIPRESS_TIMEOUT(x)     (l_total_pp_type.l_keypad_entry_pp_table_ptr[POPUP_ID_INDEX(x)].l_multi_press_timeout)
#endif

#ifdef POPUP_TYPE_ACK
#define ACK_BTN_EVENT_PTR(x)                (&l_total_pp_type.l_ack_pp_table_ptr[POPUP_ID_INDEX(x)])->ack_btn_config->l_btn_ack_evt_U16
#define ACK_BTN_TYPE(x,y)                   (l_total_pp_type.l_ack_pp_table_ptr[POPUP_ID_INDEX(x)].ack_btn_config->l_btn_ack_evt_U16[y].l_btn_type_U8)
#define ACK_BTN_COUNT(x)                    (l_total_pp_type.l_ack_pp_table_ptr[POPUP_ID_INDEX(x)].ack_btn_config->l_btn_count_U8)
#define NACK_BTN_EVENT_PTR(x)               (&l_total_pp_type.l_ack_pp_table_ptr[POPUP_ID_INDEX(x)])->l_nack_btn_config->l_btn_nack_evt_U16
#define NACK_BTN_TYPE(x)                    (l_total_pp_type.l_ack_pp_table_ptr[POPUP_ID_INDEX(x)].l_nack_btn_type)
#define NACK_BTN_COUNT(x)                   (l_total_pp_type.l_ack_pp_table_ptr[POPUP_ID_INDEX(x)].l_nack_btn_config->l_btn_count_U8)
#endif

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/

typedef UINT8 POPUP_ID_T;



/* This is the type definition for the Popup Types */

/* 
   Bit 0-2 popup type
           001 INFO    
           010 KEYPAD  
           011 PROGRESS
           100 ACK     

   Bit 3-6 Group priority
           0000 NO_GROUP_PRIORITY
           0001 GROUP_PRIORITY_1
           0010 GROUP_PRIORITY_2
           0011 GROUP_PRIORITY_3
           ... 
           FFFF GROUP_PRIORITY_15
	 Bit 7   reserved
*/
typedef UINT8 POPUP_ID_ATTRIBUTE_T;

/* Popup type index
   The index will point to the popup type structure which will provide data of the popup id */
typedef UINT8 POPUP_ID_TYPEINDEX_T;

/* 
   Bit 0-1 This is the type defintion of the Timer type which will be considered when
           a popup is overriden by a popup of higher priority in the same layer

           Timer Type
           00 RESTART_TIMER       Restart the timer with timeout value when it is refocused
           01 ALLOW_TO_EXPIRE     Allow the timer to expire in the background 
	 Bit 2-3 reserved
   Bit 4   Deactivate the active popup in a layer
           DEACTIVATE_ACTIVE_POPUP
   Bit 5   All currently activated popup id with POPUP SELF DEACTIVATED config set in a group
           of a layer will get self deactivated if a same group priority popup activated 
           POPUP SELF DEACTIVATE 
	 Bit 6-7 reserved
*/
typedef UINT8 POPUP_ID_CONFIG_T;

typedef struct
{
   POPUP_ID_ATTRIBUTE_T   type:3;     /*Bit 0-2 */
   POPUP_ID_ATTRIBUTE_T   group_priority:4;

   POPUP_ID_TYPEINDEX_T   index;

	 POPUP_ID_CONFIG_T      timer:2;
	 POPUP_ID_CONFIG_T      self_deactivate_pp:1;
	 POPUP_ID_CONFIG_T      deactivate_active_pp:1;

   LSH_STATE_ID_T         lsh_id;

   UINT16                 min_timeout;
   UINT16                 timerid;    /* Timer id will give layer timer id or allow to expire timer id's if not restart timer */
   UINT16                 layer_timeout;    /* Timeout value in ms */

	 LSH_EVENT_HANDLER_T * pp_evt_handler_ptr;    
	 LSH_FOCUS_HANDLER_T * pp_focus_handler_ptr;  
	 LSH_PRESN_HANDLER_T * pp_present_handler_ptr;
	 POPUP_EVENT_HANDLER_T * pp_popup_handler_ptr;

}POPUP_CONFIG_T;

#ifdef POPUP_CORE_STATE_CALLBACK_HANDLER_DEFINED
typedef void (POPUP_NOTIFY_CB_POPUP_STATE_HANDLER_T) (POPUP_STATES);
#endif

/* L_LAYER0_GROUP_PRIORITY_COUNT is number of grouped priorities count in layer 0
   Queue size for each grouped priorities as follows,
   no of “No” + 1 (for all YES) in self deactivate pp id configuration for each group priority */

typedef struct
{
	POPUP_ID_T * queue;
  const POPUP_ID_T queue_size;
}LAYER_GROUP_PRIORITY_TYPE;


/*---------------------------------------------*/
#ifdef POPUP_TYPE_KEYPAD
/* Type definition for the Key Pad Entry Popups*/
typedef struct
{
    UINT16 l_btn_event_U16;
    UINT8 l_char_count_U8;
    const HMI_CHAR * l_char_array;
}KEYPAD_EVENT_TYPE;

typedef struct
{
    UINT8 l_btn_count_U8;
    const KEYPAD_EVENT_TYPE * l_keypad_evt_ptr;
}KEYPAD_CONFIG_TYPE;

typedef enum
{
    NUMERIC_ENTRY = 0,
    ALPHABET_ENTRY,
    ALPHA_NUMERIC_ENTRY,
    ENTRY_INVALID
}KEY_PAD_ENTRY_TYPE;

typedef struct
{
    UINT8 l_btn_count_U8;
    const UINT16 *l_btn_keypad_evt_U16;
}PP_BTN_EVENT_TYPE;

typedef struct
{
    KEY_PAD_ENTRY_TYPE pp_entry_type;                       /* Key Pad Type Numeric\ Alphabet, Alphanumeric                     */
    KEYPAD_CONFIG_TYPE const * config_type;                 /* Key Code Pad button Mapping Config                               */
    UINT8  l_max_char_U8;                                   /* Maximum no of character                                          */
    UINT16 l_multi_press_timeout;                           /* Multi press timer value                                          */
    const PP_BTN_EVENT_TYPE *l_ok_event;                 /* Event that is considered as the acceptance of the entered value  */
    const PP_BTN_EVENT_TYPE *l_delete_event;             /* Event that deletes the last entered character                    */
    const PP_BTN_EVENT_TYPE *l_clear_event;              /* Event that clear the all the entry                               */
    const PP_BTN_EVENT_TYPE *l_cancel_event;             /* Event that cancels the Entry                                     */
    POPUP_VALIDATE_HANDLER_T * pp_validation_handler_ptr;   /* Handler Function for the validation Handler                      */
    HMI_CHAR * l_entry_ptr;                                 /* Pointer to var that hold the entered character                   */
    UINT16   * l_multi_timer_counter;                       /* Pointer to hold the current multi press counter value            */
    UINT16   * l_multi_press_counter;                       /* Pointer to hold current pressed button to find multi press or not*/
    UINT16   * l_curr_multi_press_btn;                      /* Pointer to hold current pressed button to find multi press or not*/
}POPUP_KEYPADENTRY_TYPE;
#endif
/*---------------------------------------------*/

/*---------------------------------------------*/
#ifdef POPUP_TYPE_PROGRESSBAR
/* Type definition for the Progress bar Popups*/
/* From the progress bar popup configuration time(Popup Timeout) and Progress Bar Rate timout,  
max count will be calculated and available in auto generated code.
i.e.l_progress_max_count_U8=Popup Timeout/Progress Bar Rate timout in .dat file
If no layer time configured(i.e. "popup time out" is zero), the counter should keep on increase,
until application deactivate it */
typedef struct
{
    UINT8 l_progress_max_count_U8;                 /* l_progress_max_count_U8=Popup Timeout/Progress Bar Rate timout */
    UINT8 *l_progress_counter_U8;                 /* Counter to count the increment */
}POPUP_PROGRESSBAR_TYPE;
#endif
/*---------------------------------------------*/

/*---------------------------------------------*/
#ifdef POPUP_TYPE_ACK
/* Type definition for the ACK Popups*/
typedef struct
{
    UINT16  l_btn_event_U16;
    UINT8   l_btn_type_U8;
}ACK_EVENT_TYPE;

typedef struct
{
    UINT8 l_btn_count_U8;
    const ACK_EVENT_TYPE *l_btn_ack_evt_U16;
}ACK_CONFIG_TYPE;

typedef struct
{
    UINT8 l_btn_count_U8;
    const UINT16 *l_btn_nack_evt_U16;
}NACK_CONFIG_TYPE;

typedef enum
{
    PASSED,
    ABSORBED
}ACK_BTN_TYPE;

typedef struct
{
    const ACK_CONFIG_TYPE *ack_btn_config;          /* Configuration button ev of ack popup      */
    ACK_BTN_TYPE l_nack_btn_type;                   /* Passed or Absorbed type for nack          */
    const NACK_CONFIG_TYPE *l_nack_btn_config;      /* Configuration button ev of nack popup     */
}POPUP_ACK_TYPE;
#endif
/*---------------------------------------------*/

typedef struct
{
   UINT16 info_count_U8;
#ifdef POPUP_TYPE_KEYPAD
   UINT16 keypad_count_U8;
#endif
#ifdef POPUP_TYPE_PROGRESSBAR
   UINT16 progress_bar_count_U8;
#endif
#ifdef POPUP_TYPE_ACK
   UINT16 ack_count_U8;
   POPUP_ACK_TYPE const * l_ack_pp_table_ptr;
#endif
#ifdef POPUP_TYPE_PROGRESSBAR 
   POPUP_PROGRESSBAR_TYPE const * l_progress_bar_pp_table_ptr;
#endif
#ifdef POPUP_TYPE_KEYPAD
   POPUP_KEYPADENTRY_TYPE const * l_keypad_entry_pp_table_ptr;
#endif
#ifdef POPUP_CORE_STATE_CALLBACK_HANDLER_DEFINED
   POPUP_NOTIFY_CB_POPUP_STATE_HANDLER_T * pp_state_handler_ptr;
#endif
}POPUP_TOTAL_POPUPTYPE_COUNT_T;



/* Type definition to hold the Popup Layer information
** logic_state_priority 
** l_layer_index
** l_min_tmr_id                 -  minimum timer for a layer
** l_pp_start_index
** l_total_pp_count
** l_total_grp_priority_count
** l_total_pp_count_U8         -  Total no of Popups
** l_group_priority_table_ptr
** */
typedef struct
{
    UINT8 logic_state_priority;
    UINT8 l_layer_index;

    TIMER_ID_TYPE l_min_tmr_id;

    POPUP_ID_T l_pp_start_index;
    POPUP_ID_T l_total_pp_count;
    UINT8 l_total_grp_priority_count;
    LAYER_GROUP_PRIORITY_TYPE const ** const l_group_priority_table_ptr;

}POPUP_LAYER_TYPE;

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

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
** Core Rev #        Date         By
** Core Rev X.X      mm/dd/yy     CDSID
**
**============================================================================
** CMS Rev 1.2       20-JUN-13    NKRISHN9
** The lsh add state macro was used. so removed the existing interface.
**
** CMS Rev 1.1       21-DEC-12    NKRISHN9
** Complete support of popup 02 like ack, prog, keypad and info popup 
**
**
** CMS Rev 1.0       15-Jun-11    NKRISHN9
** Initial code version
**
**==========================================================================
** CMS Rev             08-Jan-14   adevi
** Introduced three compiler switches POPUP_TYPE_KEYPAD, POPUP_TYPE_PROGRESSBAR
** and POPUP_TYPE_ACK to isolate the code based on the pop up types configured.
**===========================================================================

**=============================================================================
** CMS Rev             12-Mar-14   adevi
** Peer review comments of ID74049 fixed. Error message & Tool version modified.
**=============================================================================

**=============================================================================
** CMS Rev             19-Mar-14   adevi
** Peer review comments of 74049 fixed. Removed #ifdef EVENT_HANDLER_NULL check.
**===========================================================================

**=============================================================================
** CMS Rev             28-Mar-14   adevi
** Bug Id 164 fixed. Tool version and core version modified.
**===========================================================================

**=============================================================================
** CMS Rev             02-Apr-14   adevi
** Tool and core version check method changed.
** New macro CORE_LABEL introduced with value 48.
**===========================================================================

**=============================================================================
** CMS Rev             01-Jul-14   adevi
** Tool and core version check method changed.
** New macro introduced for major and minor version check.
**===========================================================================

**=============================================================================
** CMS Rev             13-Feb-15   adevi
** Release Version incremented.
**=============================================================================
** CMS Rev             03-Jun-15   kkubendi
** Release Version incremented to 4.12.
**===========================================================================
**==========================================================================
** CMS Rev             9-Jul-15   adevi
** RTC 374473 - QAC 8.1.2 fixes.  Ref program HONDA THAA
**==========================================================================
** end of file =============================================================*/
#endif
