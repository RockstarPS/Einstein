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
** Name:           warn_msgTask.c
**
** Description:
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**==========================================================================*/
#define warn_msgTask_C

/*==========================================================================*/
/*  I N C L U D E   F I L E S                                               */
/*==========================================================================*/
#include "system.h"
#include "warn_msgTask.h"
#include "warn_msgTask.cfg"

/*==========================================================================*/
/* I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S    */
/*==========================================================================*/


/*==========================================================================*/
/* I N T E R N A L   F U N C T I O N   P R O T O T Y P E S                  */
/*==========================================================================*/
static void msg_TaskInitialise(void);

/*==========================================================================*/
/* M E M O R Y   A L L O C A T I O N                                        */
/*==========================================================================*/
static UINT32 msgStatus;
static UINT32 msgStatusQualifier;

/*==========================================================================*/
/* E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S      */
/*==========================================================================*/
void hm_msg_KSColdInit(void)
/*============================================================================
**  Visibility:     Public (hm_msgTask.h)
**----------------------------------------------------------------------------
**  Description:    Initialisation of module following cold start. This function
**                  is normally called from the scheduler cold init list.
**
**  Parameters:     None.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 07/Apr/2010
**==========================================================================*/
{
  UINT8 inst = 0u;
  msg_ArbitratorInitialise();

#if (MSG_NUM_INSTANCES > 1)
  for( inst = 0u; inst < MSG_NUM_INSTANCES; inst++)
#endif
  {
    msg_SequencerInitialise(inst);
    msg_StoreInitialise(inst);
  }
  msg_TaskInitialise();
}


void hm_msg_KSWarmInit(void)
/*============================================================================
**  Visibility:     Public (hm_msgTask.h)
**----------------------------------------------------------------------------
**  Description:    Initialisation of module following warm start. This function
**                  is normally called from the scheduler warm init list.
**
**  Parameters:     None.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 07/Apr/2010
**==========================================================================*/
{
  /*--------------------------------------------------------------*/
  /* Configure the initialisation routines that are to be invoked */
  /* during warm init.                                            */
  /*--------------------------------------------------------------*/  
  
  MSG_WARM_INIT();
  
#ifdef MSG_WARM_INIT_SEQ
  {
    UINT8 inst = 0u;
#if (MSG_NUM_INSTANCES > 1)
    for( inst = 0u; inst < MSG_NUM_INSTANCES; inst++)  
#endif
    {		
      MSG_WARM_INIT_SEQ(inst);
    }
  }
#endif
}
void hm_msg_KSRRobin(void)
/*============================================================================
**  Visibility:     Public (hm_msgTask.h)
**----------------------------------------------------------------------------
**  Description:    Main module function.  This function is called by the
**                  scheduler round-robin task list.
**
**  Parameters:     None.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 07/Apr/2010
**==========================================================================*/
{
  UINT8 currentIgnitionState;
  UINT32 mcStatus;
  UINT8 inst = 0u;

  currentIgnitionState = MSG_GET_IGNITION_STATE();
  msg_ArbitratorUpdate(currentIgnitionState);

#if (MSG_NUM_INSTANCES > 1)
  for(inst = 0u; inst < MSG_NUM_INSTANCES; inst++)
#endif
  {
    msg_SequencerUpdate(currentIgnitionState,inst);		
#ifdef WARN_MSG_ENABLE_NEW_MESSAGE_SEQ_QUEUE_TIMEOUT
    msg_SequencerNewMsgQTimeoutUpdate(inst);
#endif
#ifdef MSG_OLD_WRNG_REPETITION
    msg_SequencerOldWrngRepUpdate(inst);
#endif
#ifdef MSG_ACK_WRNG_REPETITION
    msg_StorAckWrngRepUpdate(inst);
#endif
    /*--------------------------------------------------------------*/
    /* Process module status if this is required.                   */
    /*--------------------------------------------------------------*/
    if (0UL != msgStatusQualifier)
    {
#if MSG_NUM_INSTANCES > 1		
      (void)SIF_EXEC_INST(hm_msg_GetStatus, mcStatus, msgStatusQualifier,inst);
#else          
      (void)SIF_EXEC(hm_msg_GetStatus, mcStatus, msgStatusQualifier);
#endif
      if (mcStatus != msgStatus)
      {
        /*------------------------------------------------------*/
        /* Status has changed, so notify user...                */
        /*------------------------------------------------------*/
#if MSG_NUM_INSTANCES > 1	
        MSG_STATUS_CHANGE_INST(&mcStatus, msgStatusQualifier,inst);
#else          
        MSG_STATUS_CHANGE(&mcStatus, msgStatusQualifier);
#endif
      }
    }
  }
}


void hm_msg_KSSleep(void)
/*============================================================================
**  Visibility:     Public (hm_msgTask.h)
**----------------------------------------------------------------------------
**  Description:    Initialisation of module in preparation for sleep. Called
**                  from the scheduler sleep list
**
**  Parameters:     None.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 07/Apr/2010
**==========================================================================*/
{
  /*--------------------------------------------------------------*/
  /* Configure the initialisation routines that are to be invoked */
  /* during sleep init.                                           */
  /*--------------------------------------------------------------*/
  MSG_SLEEP_INIT();
}


void hm_msg_KSWakeup(void)
/*============================================================================
**  Visibility:     Public (hm_msgTask.h)
**----------------------------------------------------------------------------
**  Description:    Initialisation of module following wakeup. Called
**                  from the scheduler wakeup list
**
**  Parameters:     None.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 07/Apr/2010
**==========================================================================*/
{
  /*--------------------------------------------------------------*/
  /* Configure the initialisation routines that are to be invoked */
  /* during wake up init.                                         */
  /*--------------------------------------------------------------*/
  MSG_WAKEUP_INIT();
}


BOOLEAN hm_msg_KSNvRamCheck(void)
/*============================================================================
**  Visibility:     Public (hm_msgTask.h)
**----------------------------------------------------------------------------
**  Description:    Indicates whether the module RAM variables contain valid
**                  values. Called by the scheduler RAM check list
**
**  Parameters:     None.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 07/Apr/2010
**==========================================================================*/
{
  return(TRUE);
}

#if MSG_NUM_INSTANCES > 1
U32SIF_STANDARD_INTERFACE_MULTI_INST(hm_msg_GetStatus)
#else 
U32SIF_STANDARD_INTERFACE(hm_msg_GetStatus)
#endif
/*============================================================================
**  Visibility:     Public (hm_msgTask.h)
**----------------------------------------------------------------------------
**  Description:    Get message category status.  This is called by the message
**                  task whenever the message state is processed, but it can also
**                  be called by the application when a specific status needs
**                  to be checked.
**
**  Parameters:     *Data:      Returned Status
**                  Qualifier:  Qualification data (see warn_msgTask.h)
**                      B0..B7:     Module selection
**                      B8..B15     Options
**                      B16..B31:   Threshold.
**
**  Returns:        sif_OK (always)
**----------------------------------------------------------------------------
** Created: AFERRIS2 20/Oct/2010
**==========================================================================*/
{


#if (MSG_NUM_INSTANCES > 1)
  UINT8 inst = p_inst;
#else 
  UINT8 inst = 0u;
#endif

  UINT32 seqStatus = 0;
  UINT32 storStatus = 0;
  UINT32 qualifierValue;
  UINT32 Threshold;

  /*----------------------------------------------------------------------*/
  /* Get qualifier data (if valid).                                       */
  /*----------------------------------------------------------------------*/
  qualifierValue = SIF_GET_QUALIFIER();

  /*-----------------------------------------------------------------*/
  /* Latch data if requested, so that task can update status without */
  /* further notification.                                           */
  /*-----------------------------------------------------------------*/
  if (TESTBIT(qualifierValue, MSG_CATEGORY_LATCH_QUALIFIER))
  {
    qualifierValue = qualifierValue & (~(MSG_CATEGORY_LATCH_QUALIFIER)); /* ### QAC ERROR:3212 ### */
    msgStatusQualifier = qualifierValue;
  }
  /*----------------------------------------------------------------------*/
  /* Extract threshold from qualifier.                                    */
  /*----------------------------------------------------------------------*/
  Threshold = (qualifierValue >> (MSG_THRESHOLD_BITPOS));

  /*----------------------------------------------------------------------*/
  /* Only check if the caller has provided a valid pointer.               */
  /*----------------------------------------------------------------------*/
  if (SIF_ISVALID_DATA())
  {
    /*------------------------------------------------------------------*/
    /* Check SEQ categories...                                          */
    /*------------------------------------------------------------------*/
    if (TESTBIT(qualifierValue, MSG_SEQUENCER_CATEGORY))
    {
#if MSG_NUM_INSTANCES > 1
      seqStatus = seq_GetCategories(Threshold,inst);
#else
      seqStatus = seq_GetCategories(Threshold);
#endif		  
    }

    /*------------------------------------------------------------------*/
    /* Check STOR categories...                                         */
    /*------------------------------------------------------------------*/
    if (TESTBIT(qualifierValue, MSG_STORE_CATEGORY))
    {      
      storStatus = stor_GetCategories(Threshold,inst);
    }

    /*------------------------------------------------------------------*/
    /* Combine result and pass to caller.                               */
    /*------------------------------------------------------------------*/
    SIF_SET_DATA(seqStatus | storStatus);
  }

  return sif_OK;
}


static void msg_TaskInitialise(void)
/*============================================================================
**  Visibility:     Private
**----------------------------------------------------------------------------
**  Description:    Initialisation of this module.
**
**  Parameters:     None.
**
**  Returns:        None.
**----------------------------------------------------------------------------
** Created: AFERRIS2 20/Oct/2010
**==========================================================================*/
{
  msgStatus = 0UL;
  msgStatusQualifier = (MSG_CATEGORY_THRESHOLD(MSG_DEFAULT_MODULE_THRESHOLD) |
    MSG_DEFAULT_MODULE_SELECTION);
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
**  Date: 06/May/2010     by: AFERRIS2        Ref: None.
**  Change: 1.  Update task actions.
**          2. Add wakeup action.
**
**  Checks: COMPILER - NO WARNINGS       QAC - NO WARNINGS
*****************************************************************************/

/****************************************************************************
**  Date: 19/Oct/2010     by: AFERRIS2        Ref:
**  Change: 1.  Add standard interface to check active message categories.
**          2.  User-defined notification via MSG_STATUS_CHANGE() if any
**              change detected.
**  Checks: COMPILER - NO WARNINGS       QAC - 1 WARNING
*****************************************************************************/

/****************************************************************************
**  Date: 25/Aug/2013     by: vsarava2        Ref: RTC 91916
**  New warning Seq Q timeout implementation to support Honda requirements.
*****************************************************************************/

/****************************************************************************
**  Date: 27/Dec/2013     by: adevi           Ref: RTC 91917
**  Old & Ack warning repetition implementation to support Honda requirements.
*****************************************************************************/

/****************************************************************************
**  Date: 25/Jun/2014     by: adevi           Ref: Bug 196  , RTC 172041
**  Initialisation routines of warm, wake up and sleep init made configurable .
*****************************************************************************/

/****************************************************************************
**  Date: 29/Jun/2015     by: adevi        Ref: RTC 365702
**  Change: QAC warnings resolved for Honda THAA
*****************************************************************************/

/* end of file =============================================================*/
