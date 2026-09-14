
/***************************************************/
/*                  Timer Interface                */
/***************************************************/
#define  HMI_POPUP_START_TIMER(timer_id, timeout, evt)  ( hmi_popup_core_support_timer_start((timer_id), (timeout), (evt)))
#define  HMI_POPUP_STOP_TIMER(timer_id)                 ( hmi_popup_core_support_timer_stop(timer_id))
#define  HMI_POPUP_CHECK_TIMER(timer_id)                ( hmi_popup_core_support_timer_check(timer_id))

#define  POPUP_TMR_RUNNING               ( HMI_TIMER_RUNNING)
#define  POPUP_TMR_EXPIRED               ( HMI_TIMER_EXPIRED)
#define  POPUP_TMR_CLEARED               ( HMI_TIMER_CLEAR)
#define  POPUP_MAX_TIMER                (0x0FFFF)

/***************************************************/
/*                 List of Timer id                 */
/***************************************************/

GUI_POPUP_LAYER0_TMR_ID,
GUI_POPUP_LAYER1_TMR_ID,

/***************************************************/
/*                 list of include files                */
/***************************************************/

hmi_timer_support.h
hmi_popup_screen.h
/***************************************************/
/*                  list of button ids               */
/***************************************************/
BTN_ID_ENTER  ,
BTN_ID_MAX  ,
BTN_ID_POWER  ,
KEYPAD_0_IN  ,
KEYPAD_1_IN  ,
KEYPAD_2_IN  ,
KEYPAD_3_IN  ,
KEYPAD_4_IN  ,
KEYPAD_5_IN  ,
KEYPAD_6_IN  ,
KEYPAD_7_IN  ,
KEYPAD_8_IN  ,
KEYPAD_9_IN  ,


