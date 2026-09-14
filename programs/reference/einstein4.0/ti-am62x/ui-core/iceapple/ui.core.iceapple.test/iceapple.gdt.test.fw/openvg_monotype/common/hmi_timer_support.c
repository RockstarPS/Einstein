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
 ** Name:          hmi_timer_support.c
 **
 ** Description:   Implements the screen logic and presentation for opening 
 **                screen 
 **
 ** Organization:  GUI Software Section
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_TIMER_SUPPORT_C

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/

#include "hmi_timer_support.h"

#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/

/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/
WPARAM WindowsTimer[HMI_NO_OF_TIMERS];

/****************************************************************************
Function Name        : timer_support_wint_proc
Description          : Notifies Windows timer expiry
Invocation           : invoked by windows main function
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
VOID CALLBACK hmi_timer_support_proc(_In_  HWND hwnd, _In_  UINT uMsg, _In_  UINT_PTR idEvent, _In_  DWORD dwTime){
  UINT8 i;
  for(i = 0; i < HMI_NO_OF_TIMERS; i++)
  {
    if(idEvent == WindowsTimer[i])
    {
      WindowsTimer[i] = 0;
      KillTimer(NULL,idEvent);
    }
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
 ** CMS Rev 1.0      09-Mar-2015    EMANOJ1
 ** Creation.
 **==========================================================================*/
#ifdef  __cplusplus
}
#endif