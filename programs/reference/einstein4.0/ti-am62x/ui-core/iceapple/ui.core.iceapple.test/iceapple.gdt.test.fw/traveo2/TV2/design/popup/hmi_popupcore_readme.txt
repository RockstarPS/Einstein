
/***************************************************/
/*                  Timer Interface                */
/***************************************************/
#define  HMI_POPUP_START_TIMER(timer_id, timeout, evt)  ( hmi_timer_support_start_timer((timer_id), (timeout), (evt)))
#define  HMI_POPUP_STOP_TIMER(timer_id)                 ( hmi_timer_support_clear_timer(timer_id))
#define  HMI_POPUP_CHECK_TIMER(timer_id)                ( hmi_timer_support_check_timer(timer_id))

#define  POPUP_TMR_RUNNING               ( HMI_TIMER_RUNNING)
#define  POPUP_TMR_EXPIRED               ( HMI_TIMER_EXPIRED)
#define  POPUP_TMR_CLEARED               ( HMI_TIMER_CLEAR)
#define  POPUP_MAX_TIMER                (HMI_NO_OF_TIMERS)

/***************************************************/
/*                 List of Timer id                 */
/***************************************************/

GUI_POPUP_LAYER1_TMR_ID,

/***************************************************/
/*                 list of include files                */
/***************************************************/

hmi_logic_state_handler.h
hmi_timer_support.h
/***************************************************/
/*                  list of button ids               */
/***************************************************/


