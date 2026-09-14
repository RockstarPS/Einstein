/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2009. Visteon Corporation owns all rights to this work and
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
** Name:           warn_msgDefinition.c
**
** Description:    Application message definitions for the C520 cluster
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**==========================================================================*/
#define warn_msgDefinition_C

/*==========================================================================*/
/*  I N C L U D E   F I L E S                                               */
/*==========================================================================*/
#include "system.h"
#include "warn_msgDefinition.h"

/*==========================================================================*/
/* I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S    */
/*==========================================================================*/


/*==========================================================================*/
/* I N T E R N A L   F U N C T I O N   P R O T O T Y P E S                  */
/*==========================================================================*/


/*==========================================================================*/
/* M E M O R Y   A L L O C A T I O N                                        */
/*==========================================================================*/

const MSG_MESSAGE_STRUCT messageList[MSG_NUM_MESSAGES] =
{
	MSG_MESSAGE_LIST
};

UINT16 const hmi_msg_inst_config_count[MSG_NUM_INSTANCES] = { MSG_NUM_MSGS_LIST  };

/*==========================================================================*/
/* E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S      */
/*==========================================================================*/

UINT16 msg_DefinitionGetDisplayTimeout(eMessageIdentity aMessage)
/*============================================================================
**  Visibility:     Public (.h)
**----------------------------------------------------------------------------
**  Description:    Get message display timeout
**
**  Parameters:     ID of message
**
**  Returns:        timeout (in TIMER units)
**----------------------------------------------------------------------------
** Created: AFERRIS2 28/04/2011
**==========================================================================*/
{
    UINT16 ret_value = 0;
    if (aMessage < MSG_NUM_MESSAGES)
    {
        ret_value = messageList[aMessage].DisplayTimeout;
    }
    return ret_value;
}

/*==========================================================================*/
/* R E V I S I O N    N O T E S                                             */
/*==========================================================================*/
/* For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**==========================================================================*/

/****************************************************************************
**  Date  : 07/Apr/2010
**  by    : AFERRIS2
**  Ref   : None.
**  Change: Initial version.
**
*****************************************************************************/

/****************************************************************************
**  Date: 28/04/2011     by: AFERRIS2        Ref: DCR 2131
**  Change: Add public function msg_DefinitionGetDisplayTimeout()
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 03/05/2011     by: AFERRIS2        Ref:
**  Change: 1.  Fixed typo in msg_DefinitionGetDisplayTimeout()
**
**  Checks: COMPILER - NOT CHECKED       QAC - NOT CHECKED
*****************************************************************************/

/****************************************************************************
**  Date: 29/Jun/2015     by: adevi        Ref: RTC 365702
**  Change: QAC warnings resolved for Honda THAA
*****************************************************************************/

/* end of file =============================================================*/
