/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
* File Name         :  LinSm_Types                                           *
* Module Short Name :  LinSM                                                 *
* Description       :  Header file for LinSM component                       *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :  Turing A                                               *
*                                                                            *
*****************************************************************************/
#ifndef LINSM_TYPES_H
#define LINSM_TYPES_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "Std_Types.h"
#include "LinIf_Types.h"

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/

typedef uint8 LinSm_SchHandleType;

typedef enum {
	LINSM_UNINIT,
	LIN_SM_INIT,
	LINSM_NO_COM,
	LINSM_FULL_COM
}LinSM_StatusType;

typedef struct 
{
    LinSM_StatusType Channel_Status; /* Individual Status of Each Channels */
    uint16 ScheduleRequestTimerCount; /* Current Ticks executed data of each Channel  */
    uint16 GoToSleepTimerCount; /* GotoSleep Timer Count */
    uint16 WakeUpTimerCount; /* WakeUp Timer Count */
    LinSm_SchHandleType CurrentScheduleRequest; /* Current Schedule Request */
    LinSm_SchHandleType NewScheduleRequest; /* New Schedule Request */
}LinSM_ChannelDataType;

/*-----------[LinSMSchedule]--------------------------------------------------*/

/* Stores the configuration data of a LinSMSchedule object.
 * See item LINSM146_Conf. */
typedef struct
{
    /* LinIf schedule table identifier.
     * The value of the LinSMScheduleIndex shall be the same
     * as the value from the LinIf. */
    const LinIf_SchHandleType LinSMScheduleIndex;
}
LinSM_ScheduleType;


/*-----------[LinSMChannel]---------------------------------------------------*/

/* Stores the configuration data of a LinSMChannel object.
 * See item LINSM142_Conf. */
typedef struct
{
    /* Timeout in milliseconds for the goto sleep and wakeup calls to LinIf. */
    uint16  LinSMConfirmationTimeout;

    boolean LinSMSleepSupport;

    /* Selects STANDBY (true) or SLEEP (false) transceiver mode when
     * entering LINSM_NO_COM. */
    boolean LinSMTransceiverPassiveMode;

    /* Unique handle to identify one certain LIN network.
     * The network index may be used directly to the LinIf module APIs. */
    uint16  LinSMComMNetworkHandleRef;

    /* List of LinSMSchedule objects assigned to this channel. */
    const LinSM_ScheduleType *LinSMSchedules;

    /* Number of LinSMSchedule (size of the array LinSMSchedule) */
    const uint8 LinSMSchedule_Cnt;
}
LinSM_ChannelType;


/*-----------[LinSM_ConfigType]-----------------------------------------------*/

/* Configuration of the LinSm module */
typedef struct
{
    /* Array of setup LinSMChannel objects */
    const LinSM_ChannelType *LinSMChannels;

}LinSM_ConfigType;

#endif // LINIF_TYPES_H
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
**============================================================================
**Date               : 15/APR/2020
**CDSID              : BPANDURA
**Traceability       : #724726 #835035 #835036 #835037 #724728     
**Change Description : Initial Version
**============================================================================

**============================================================================
**Date               : 05-Mar-2019
**CDSID              : BPANNEER
**Traceability       : RTC #1285296     
**Change Description : Initial Version
**============================================================================*/

