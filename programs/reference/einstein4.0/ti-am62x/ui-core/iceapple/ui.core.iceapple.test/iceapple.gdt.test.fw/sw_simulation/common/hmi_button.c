/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2012. Visteon Corporation owns all rights to this work and
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
 ** Name:          hmi_button.c
 **
 ** Description:   Implements the button event configuration table and related
 **                button status check callback functions 
 **
 ** Organization:  GUI Software Section
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_BUTTON_C

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include <windows.h>
#include "hmi_button.h"
#include "dm_swch.h"



#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/

#define _BTN_EV(btn, ev) ((ev) | ((btn) << 8))
#define _SW_TO_MS(ms)	 ((ms)/SWITCH_MANAGER_PERIOD_RATE_IN_MS)

/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/
static BOOLEAN hmi_power_sw_active(void);
static BOOLEAN hmi_up_sw_active(void);
static BOOLEAN hmi_lt_sw_active(void);
static BOOLEAN hmi_rt_sw_active(void);
static BOOLEAN hmi_dn_sw_active(void);
static BOOLEAN hmi_enter_sw_active(void);
static BOOLEAN hmi_info_popup_sw_active(void);
static BOOLEAN hmi_ack_popup_sw_active(void);
static BOOLEAN hmi_keypad_popup_sw_active(void);
static BOOLEAN hmi_progress_popup_sw_active(void);
static BOOLEAN hmi_hard_wrng_sw_active(void);
static BOOLEAN hmi_soft_wrng_sw_active(void);
static BOOLEAN hmi_info_wrng_sw_active(void);
static BOOLEAN hmi_deactivate_wrng_sw_active(void);
static BOOLEAN hmi_zero_sw_active(void);
static BOOLEAN hmi_one_sw_active(void);
static BOOLEAN hmi_two_sw_active(void);
static BOOLEAN hmi_three_sw_active(void);
static BOOLEAN hmi_four_sw_active(void);
static BOOLEAN hmi_five_sw_active(void);
static BOOLEAN hmi_six_sw_active(void);
static BOOLEAN hmi_seven_sw_active(void);
static BOOLEAN hmi_eight_sw_active(void);
static BOOLEAN hmi_nine_sw_active(void);
static BOOLEAN hmi_menu_sw_active(void);
static BOOLEAN hmi_esc_sw_active(void);

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/
const SWITCH_EVENT_TABLE_ENTRY dm_switch_array[DM_SWITCH_NUM_ENTRY_IN_CFG_TBL] =
{
  {
    hmi_power_sw_active,                         /* switch_active(),   */
    1,                                           /* callback,          */
    1,                                           /* max_switch_events, */
    _BTN_EV(BTN_ID_POWER,BTN_EV_PRESS),          /* press_event,       */
    {									     
      {
        _SW_TO_MS(2000),                         /* held_time          */
        _BTN_EV(BTN_ID_POWER,BTN_EV_RELEASE),    /* rel_event          */
        _BTN_EV(BTN_ID_POWER,BTN_EV_HELD)        /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                            /* repeat_held_time   */
      _SW_TO_MS(200),                            /* repeat_time        */
      _BTN_EV(BTN_ID_POWER,BTN_EV_REPEAT)        /* repeat_event       */
    }
  },
  {
    hmi_up_sw_active,                            /* switch_active(),   */
    1,                                           /* callback,          */
    1,                                           /* max_switch_events, */
    _BTN_EV(BTN_ID_UP,BTN_EV_PRESS),             /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                         /* held_time          */
        _BTN_EV(BTN_ID_UP,BTN_EV_RELEASE),       /* rel_event          */
        _BTN_EV(BTN_ID_UP,BTN_EV_HELD)           /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                            /* repeat_held_time   */
      _SW_TO_MS(200),                            /* repeat_time        */
      _BTN_EV(BTN_ID_UP,BTN_EV_REPEAT)           /* repeat_event       */
    }
  },
  {
    hmi_dn_sw_active,                            /* switch_active(),   */
    1,                                           /* callback,          */
    1,                                           /* max_switch_events, */
    _BTN_EV(BTN_ID_DN,BTN_EV_PRESS),             /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                         /* held_time          */
        _BTN_EV(BTN_ID_DN,BTN_EV_RELEASE),       /* rel_event          */
        _BTN_EV(BTN_ID_DN,BTN_EV_HELD)           /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                            /* repeat_held_time   */
      _SW_TO_MS(200),                            /* repeat_time        */
      _BTN_EV(BTN_ID_DN,BTN_EV_REPEAT)           /* repeat_event       */
    }
  },
  {
    hmi_lt_sw_active,                            /* switch_active(),   */
    1,                                           /* callback,          */
    1,                                           /* max_switch_events, */
    _BTN_EV(BTN_ID_LT,BTN_EV_PRESS),             /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                         /* held_time          */
        _BTN_EV(BTN_ID_LT,BTN_EV_RELEASE),       /* rel_event          */
        _BTN_EV(BTN_ID_LT,BTN_EV_HELD)           /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                            /* repeat_held_time   */
      _SW_TO_MS(200),                            /* repeat_time        */
      _BTN_EV(BTN_ID_LT,BTN_EV_REPEAT)           /* repeat_event       */
    }
  },
  {
    hmi_rt_sw_active,                           /* switch_active(),   */
    1,                                          /* callback,          */
    1,                                          /* max_switch_events, */
    _BTN_EV(BTN_ID_RT,BTN_EV_PRESS),            /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                        /* held_time          */
        _BTN_EV(BTN_ID_RT,BTN_EV_RELEASE),      /* rel_event          */
        _BTN_EV(BTN_ID_RT,BTN_EV_HELD)          /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                           /* repeat_held_time   */
      _SW_TO_MS(200),                           /* repeat_time        */
      _BTN_EV(BTN_ID_RT,BTN_EV_REPEAT)          /* repeat_event       */
    }
  },
  {
    hmi_enter_sw_active,                        /* switch_active(),   */
    1,                                          /* callback,          */
    1,                                          /* max_switch_events, */
    _BTN_EV(BTN_ID_ENTER,BTN_EV_PRESS),         /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                        /* held_time          */
        _BTN_EV(BTN_ID_ENTER,BTN_EV_RELEASE),   /* rel_event          */
        _BTN_EV(BTN_ID_ENTER,BTN_EV_HELD)       /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                           /* repeat_held_time   */
      _SW_TO_MS(200),                           /* repeat_time        */
      _BTN_EV(BTN_ID_ENTER,BTN_EV_REPEAT)       /* repeat_event       */
    }
  },
  {
    hmi_info_popup_sw_active,                    /* switch_active(),   */
    1,                                           /* callback,          */
    1,                                           /* max_switch_events, */
    _BTN_EV(BTN_ID_INFO_POPUP,BTN_EV_PRESS),     /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                          /* held_time          */
        _BTN_EV(BTN_ID_INFO_POPUP,BTN_EV_RELEASE),/* rel_event          */
        _BTN_EV(BTN_ID_INFO_POPUP,BTN_EV_HELD)    /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                             /* repeat_held_time   */
      _SW_TO_MS(200),                             /* repeat_time        */
      _BTN_EV(BTN_ID_INFO_POPUP,BTN_EV_REPEAT)    /* repeat_event       */
    }
  },
  {
    hmi_ack_popup_sw_active,                     /* switch_active(),   */
    1,                                           /* callback,          */
    1,                                           /* max_switch_events, */
    _BTN_EV(BTN_ID_ACK_POPUP,BTN_EV_PRESS),      /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                          /* held_time          */
        _BTN_EV(BTN_ID_ACK_POPUP,BTN_EV_RELEASE), /* rel_event          */
        _BTN_EV(BTN_ID_ACK_POPUP,BTN_EV_HELD)     /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                             /* repeat_held_time   */
      _SW_TO_MS(200),                             /* repeat_time        */
      _BTN_EV(BTN_ID_ACK_POPUP,BTN_EV_REPEAT)     /* repeat_event       */
    }
  },
  {
    hmi_keypad_popup_sw_active,                   /* switch_active(),   */
    1,                                            /* callback,          */
    1,                                            /* max_switch_events, */
    _BTN_EV(BTN_ID_KEYPAD_POPUP,BTN_EV_PRESS),    /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                             /* held_time          */
        _BTN_EV(BTN_ID_KEYPAD_POPUP,BTN_EV_RELEASE), /* rel_event          */
        _BTN_EV(BTN_ID_KEYPAD_POPUP,BTN_EV_HELD)     /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                            /* repeat_held_time   */
      _SW_TO_MS(200),                            /* repeat_time        */
      _BTN_EV(BTN_ID_KEYPAD_POPUP,BTN_EV_REPEAT) /* repeat_event       */
    }
  },
  {
    hmi_progress_popup_sw_active,                  /* switch_active(),   */
    1,                                             /* callback,          */
    1,                                             /* max_switch_events, */
    _BTN_EV(BTN_ID_PROGRESS_POPUP,BTN_EV_PRESS),   /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                               /* held_time          */
        _BTN_EV(BTN_ID_PROGRESS_POPUP,BTN_EV_RELEASE), /* rel_event          */
        _BTN_EV(BTN_ID_PROGRESS_POPUP,BTN_EV_HELD)     /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                              /* repeat_held_time   */
      _SW_TO_MS(200),                              /* repeat_time        */
      _BTN_EV(BTN_ID_PROGRESS_POPUP,BTN_EV_REPEAT) /* repeat_event       */
    }
  },
  {
    hmi_hard_wrng_sw_active,                     /* switch_active(),   */
    1,                                           /* callback,          */
    1,                                           /* max_switch_events, */
    _BTN_EV(BTN_ID_HARD_WRNG,BTN_EV_PRESS),      /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                          /* held_time          */
        _BTN_EV(BTN_ID_HARD_WRNG,BTN_EV_RELEASE), /* rel_event          */
        _BTN_EV(BTN_ID_HARD_WRNG,BTN_EV_HELD)     /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                         /* repeat_held_time   */
      _SW_TO_MS(200),                         /* repeat_time        */
      _BTN_EV(BTN_ID_HARD_WRNG,BTN_EV_REPEAT) /* repeat_event       */
    }
  },
  {
    hmi_soft_wrng_sw_active,                     /* switch_active(),   */
    1,                                           /* callback,          */
    1,                                           /* max_switch_events, */
    _BTN_EV(BTN_ID_SOFT_WRNG,BTN_EV_PRESS),      /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                          /* held_time          */
        _BTN_EV(BTN_ID_SOFT_WRNG,BTN_EV_RELEASE), /* rel_event          */
        _BTN_EV(BTN_ID_SOFT_WRNG,BTN_EV_HELD)     /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                         /* repeat_held_time   */
      _SW_TO_MS(200),                         /* repeat_time        */
      _BTN_EV(BTN_ID_SOFT_WRNG,BTN_EV_REPEAT) /* repeat_event       */
    }
  },
  {
    hmi_info_wrng_sw_active,                     /* switch_active(),   */
    1,                                           /* callback,          */
    1,                                           /* max_switch_events, */
    _BTN_EV(BTN_ID_INFO_WRNG,BTN_EV_PRESS),      /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                          /* held_time          */
        _BTN_EV(BTN_ID_INFO_WRNG,BTN_EV_RELEASE), /* rel_event          */
        _BTN_EV(BTN_ID_INFO_WRNG,BTN_EV_HELD)     /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                         /* repeat_held_time   */
      _SW_TO_MS(200),                         /* repeat_time        */
      _BTN_EV(BTN_ID_INFO_WRNG,BTN_EV_REPEAT) /* repeat_event       */
    }
  },
  {
    hmi_deactivate_wrng_sw_active,                   /* switch_active(),   */
    1,                                               /* callback,          */
    1,                                               /* max_switch_events, */
    _BTN_EV(BTN_ID_DEACTIVATE_WRNG,BTN_EV_PRESS),    /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                                /* held_time          */
        _BTN_EV(BTN_ID_DEACTIVATE_WRNG,BTN_EV_RELEASE), /* rel_event          */
        _BTN_EV(BTN_ID_DEACTIVATE_WRNG,BTN_EV_HELD)     /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                               /* repeat_held_time   */
      _SW_TO_MS(200),                               /* repeat_time        */
      _BTN_EV(BTN_ID_DEACTIVATE_WRNG,BTN_EV_REPEAT) /* repeat_event       */
    }
  },
  {
    hmi_zero_sw_active,                       /* switch_active(),   */
    1,                                        /* callback,          */
    1,                                        /* max_switch_events, */
    _BTN_EV(BTN_ID_0,BTN_EV_PRESS),           /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                       /* held_time          */
        _BTN_EV(BTN_ID_0,BTN_EV_RELEASE),      /* rel_event          */
        _BTN_EV(BTN_ID_0,BTN_EV_HELD)          /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                         /* repeat_held_time   */
      _SW_TO_MS(200),                         /* repeat_time        */
      _BTN_EV(BTN_ID_0,BTN_EV_REPEAT)         /* repeat_event       */
    }
  },
  {
    hmi_one_sw_active,                        /* switch_active(),   */
    1,                                        /* callback,          */
    1,                                        /* max_switch_events, */
    _BTN_EV(BTN_ID_1,BTN_EV_PRESS),           /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                      /* held_time          */
        _BTN_EV(BTN_ID_1,BTN_EV_RELEASE),     /* rel_event          */
        _BTN_EV(BTN_ID_1,BTN_EV_HELD)         /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                         /* repeat_held_time   */
      _SW_TO_MS(200),                         /* repeat_time        */
      _BTN_EV(BTN_ID_1,BTN_EV_REPEAT)         /* repeat_event       */
    }
  },
  {
    hmi_two_sw_active,                       /* switch_active(),   */
    1,                                       /* callback,          */
    1,                                       /* max_switch_events, */
    _BTN_EV(BTN_ID_2,BTN_EV_PRESS),          /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                      /* held_time          */
        _BTN_EV(BTN_ID_2,BTN_EV_RELEASE),     /* rel_event          */
        _BTN_EV(BTN_ID_2,BTN_EV_HELD)         /* held_event         */
      }  
    },
    {
      _SW_TO_MS(200),                         /* repeat_held_time   */
      _SW_TO_MS(200),                         /* repeat_time        */
      _BTN_EV(BTN_ID_2,BTN_EV_REPEAT)         /* repeat_event       */
    }
  },
  {
    hmi_three_sw_active,                      /* switch_active(),   */
    1,                                        /* callback,          */
    1,                                        /* max_switch_events, */
    _BTN_EV(BTN_ID_3,BTN_EV_PRESS),           /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                      /* held_time          */
        _BTN_EV(BTN_ID_3,BTN_EV_RELEASE),     /* rel_event          */
        _BTN_EV(BTN_ID_3,BTN_EV_HELD)         /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                         /* repeat_held_time   */
      _SW_TO_MS(200),                         /* repeat_time        */
      _BTN_EV(BTN_ID_3,BTN_EV_REPEAT)         /* repeat_event       */
    }
  },
  {
    hmi_four_sw_active,                       /* switch_active(),   */
    1,                                        /* callback,          */
    1,                                        /* max_switch_events, */
    _BTN_EV(BTN_ID_4,BTN_EV_PRESS),           /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                      /* held_time          */
        _BTN_EV(BTN_ID_4,BTN_EV_RELEASE),     /* rel_event          */
        _BTN_EV(BTN_ID_4,BTN_EV_HELD)         /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                         /* repeat_held_time   */
      _SW_TO_MS(200),                         /* repeat_time        */
      _BTN_EV(BTN_ID_4,BTN_EV_REPEAT)         /* repeat_event       */
    }
  },
  {
    hmi_five_sw_active,                       /* switch_active(),   */
    1,                                        /* callback,          */
    1,                                        /* max_switch_events, */
    _BTN_EV(BTN_ID_5,BTN_EV_PRESS),           /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                       /* held_time          */
        _BTN_EV(BTN_ID_5,BTN_EV_RELEASE),      /* rel_event          */
        _BTN_EV(BTN_ID_5,BTN_EV_HELD)          /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                         /* repeat_held_time   */
      _SW_TO_MS(200),                         /* repeat_time        */
      _BTN_EV(BTN_ID_5,BTN_EV_REPEAT)         /* repeat_event       */
    }
  },
  {
    hmi_six_sw_active,                         /* switch_active(),   */
    1,                                         /* callback,          */
    1,                                         /* max_switch_events, */
    _BTN_EV(BTN_ID_6,BTN_EV_PRESS),            /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                       /* held_time          */
        _BTN_EV(BTN_ID_6,BTN_EV_RELEASE),      /* rel_event          */
        _BTN_EV(BTN_ID_6,BTN_EV_HELD)          /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                         /* repeat_held_time   */
      _SW_TO_MS(200),                         /* repeat_time        */
      _BTN_EV(BTN_ID_6,BTN_EV_REPEAT)         /* repeat_event       */
    }
  },
  {
    hmi_seven_sw_active,                      /* switch_active(),   */
    1,                                        /* callback,          */
    1,                                        /* max_switch_events, */
    _BTN_EV(BTN_ID_7,BTN_EV_PRESS),           /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                      /* held_time          */
        _BTN_EV(BTN_ID_7,BTN_EV_RELEASE),     /* rel_event          */
        _BTN_EV(BTN_ID_7,BTN_EV_HELD)         /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                         /* repeat_held_time   */
      _SW_TO_MS(200),                         /* repeat_time        */
      _BTN_EV(BTN_ID_7,BTN_EV_REPEAT)         /* repeat_event       */
    }
  },
  {
    hmi_eight_sw_active,                      /* switch_active(),   */
    1,                                        /* callback,          */
    1,                                        /* max_switch_events, */
    _BTN_EV(BTN_ID_8,BTN_EV_PRESS),           /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                      /* held_time          */
        _BTN_EV(BTN_ID_8,BTN_EV_RELEASE),     /* rel_event          */
        _BTN_EV(BTN_ID_8,BTN_EV_HELD)         /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                         /* repeat_held_time   */
      _SW_TO_MS(200),                         /* repeat_time        */
      _BTN_EV(BTN_ID_8,BTN_EV_REPEAT)         /* repeat_event       */
    }
  },
  {
    hmi_nine_sw_active,                       /* switch_active(),   */
    1,                                        /* callback,          */
    1,                                        /* max_switch_events, */
    _BTN_EV(BTN_ID_9,BTN_EV_PRESS),           /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                      /* held_time          */
        _BTN_EV(BTN_ID_9,BTN_EV_RELEASE),     /* rel_event          */
        _BTN_EV(BTN_ID_9,BTN_EV_HELD)         /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                         /* repeat_held_time   */
      _SW_TO_MS(200),                         /* repeat_time        */
      _BTN_EV(BTN_ID_9,BTN_EV_REPEAT)         /* repeat_event       */
    }
  },
	{
    hmi_menu_sw_active,                       /* switch_active(),   */
    1,                                        /* callback,          */
    1,                                        /* max_switch_events, */
    _BTN_EV(BTN_ID_MENU,BTN_EV_PRESS),        /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                      /* held_time          */
        _BTN_EV(BTN_ID_MENU, BTN_EV_RELEASE), /* rel_event          */
        _BTN_EV(BTN_ID_MENU, BTN_EV_HELD)     /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                     /* repeat_held_time   */
      _SW_TO_MS(200),                     /* repeat_held_time   */
      _BTN_EV(BTN_ID_MENU, BTN_EV_REPEAT) /* repeat_event       */
    }
  }
  ,
	{
    hmi_esc_sw_active,                     /* switch_active(),   */
    1,                                     /* callback,          */
    1,                                     /* max_switch_events, */
    _BTN_EV(BTN_ID_ESC,BTN_EV_PRESS),      /* press_event,       */
    {
      {
        _SW_TO_MS(2000),                    /* held_time          */
        _BTN_EV(BTN_ID_ESC, BTN_EV_RELEASE),/* rel_event          */
        _BTN_EV(BTN_ID_ESC, BTN_EV_HELD)    /* held_event         */
      }
    },
    {
      _SW_TO_MS(200),                      /* repeat_held_time   */
      _SW_TO_MS(200),                      /* repeat_held_time   */
      _BTN_EV(BTN_ID_ESC, BTN_EV_REPEAT)   /* repeat_event       */
    }
  }
};

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/

/****************************************************************************
Function Name        : hmi_power_sw_active
Description          : Returns the power button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_power_sw_active(void){
	SHORT ks = GetKeyState('P');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_up_sw_active
Description          : Returns the up button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_up_sw_active(void){
	SHORT ks = GetKeyState(VK_UP);
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_lt_sw_active
Description          : Returns the left button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_lt_sw_active(void){
	SHORT ks = GetKeyState(VK_LEFT);
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_rt_sw_active
Description          : Returns the right button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_rt_sw_active(void){
	SHORT ks = GetKeyState(VK_RIGHT);
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_dn_sw_active
Description          : Returns the down button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_dn_sw_active(void){
	SHORT ks = GetKeyState(VK_DOWN);
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_enter_sw_active
Description          : Returns the enter button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_enter_sw_active(void){
	SHORT ks = GetKeyState(VK_RETURN);
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_info_popup_sw_active
Description          : Returns the Character A button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_info_popup_sw_active(void){
	SHORT ks = GetKeyState('A');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_ack_popup_sw_active
Description          : Returns the Character S  button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_ack_popup_sw_active(void){
	SHORT ks = GetKeyState('S');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_keypad_popup_sw_active
Description          : Returns the Character D  button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_keypad_popup_sw_active(void){
	SHORT ks = GetKeyState('D');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_progress_popup_sw_active
Description          : Returns the Character F button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_progress_popup_sw_active(void){
	SHORT ks = GetKeyState('F');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_hard_wrng_sw_active
Description          : Returns the Character Q button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_hard_wrng_sw_active(void){
	SHORT ks = GetKeyState('Q');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_soft_wrng_sw_active
Description          : Returns the Character W button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_soft_wrng_sw_active(void){
	SHORT ks = GetKeyState('W');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_info_wrng_sw_active
Description          : Returns the Character E button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_info_wrng_sw_active(void){
	SHORT ks = GetKeyState('E');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_deactivate_wrng_sw_active
Description          : Returns the  Character R button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_deactivate_wrng_sw_active(void){
	SHORT ks = GetKeyState('R');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_zero_sw_active
Description          : Returns the number 0 button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_zero_sw_active(void)
{
	SHORT ks = GetKeyState('0');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_one_sw_active
Description          : Returns the number 1 button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_one_sw_active(void)
{
	SHORT ks = GetKeyState('1');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_two_sw_active
Description          : Returns the number 2 button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_two_sw_active(void)
{
	SHORT ks = GetKeyState('2');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_three_sw_active
Description          : Returns the number 3 button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_three_sw_active(void)
{
	SHORT ks = GetKeyState('3');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_four_sw_active
Description          : Returns the number 4 button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_four_sw_active(void)
{
	SHORT ks = GetKeyState('4');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_five_sw_active
Description          : Returns the number 5 button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_five_sw_active(void)
{
	SHORT ks = GetKeyState('5');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_six_sw_active
Description          : Returns the number 6 button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_six_sw_active(void)
{
	SHORT ks = GetKeyState('6');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_seven_sw_active
Description          : Returns the number 7 button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_seven_sw_active(void)
{
	SHORT ks = GetKeyState('7');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_eight_sw_active
Description          : Returns the number 8 button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_eight_sw_active(void)
{
	SHORT ks = GetKeyState('8');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_nine_sw_active
Description          : Returns the number 9 button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_nine_sw_active(void)
{
	SHORT ks = GetKeyState('9');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_menu_sw_active
Description          : Returns the character M button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_menu_sw_active(void){
	SHORT ks = GetKeyState('M');
	return(ks & 0x80);
}

/****************************************************************************
Function Name        : hmi_esc_sw_active
Description          : Returns the escape button status
Invocation           : Invoked by switch event manager
Return Value         : True if button pressed/FALSE if button released
Critical Section     : None
Parameters           : None
******************************************************************************/
static BOOLEAN hmi_esc_sw_active(void){
	SHORT ks = GetKeyState(VK_ESCAPE);
	return(ks & 0x80);
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
 ** CMS Rev 1.0      09-Mar-2015    EMANOJ1
 ** Creation.
 **==========================================================================*/
#ifdef  __cplusplus
}
#endif

