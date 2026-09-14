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
* File Name         :  LinSm_Cbk                                             *
* Module Short Name :  LinSm                                                 *
* Description       :  Callback Header file for LinSm component              *
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
#ifndef LINSM_CBK_H
#define LINSM_CBK_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "Std_Types.h"
#include "LinIf.h"
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/





/*============================================================================
** C A L L B A C K        F U N C T I O N S          D E C L A R A T I O N S
**==========================================================================*/

//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_ScheduleRequestConfirmation
/// @param NetworkHandleType network - Identification of the LIN channel.
///        LinIf_SchHandleType schedule_changed - Handle value to the new active Schedule table
/// @Description The LinIf module will call this callback when the new requested schedule table is active.
/// @return void.
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinSM_ScheduleRequestConfirmation(NetworkHandleType network, LinIf_SchHandleType schedule);
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_WakeUpConfirmation
/// @param NetworkHandleType network - Identification of the LIN channel.
///        success schedule_changed - True if wakeup was successfully sent, false otherwise
/// @Description The LinIf will call this callback when the wake up signal command is
///              sent not successfully/successfully on the network..
/// @return void.
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinSM_WakeUpConfirmation(NetworkHandleType network, boolean success);
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_GotoSleepConfirmation
/// @param network - Identification of the LIN channel
///        success - True if goto sleep was successfully sent, false otherwise
/// @Description The LinIf will call this callback when the go to sleep 
///              command is sent successfully or not sent successfully 
///              on the network..
/// @return void.
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinSM_GotoSleepConfirmation(NetworkHandleType network, boolean success);
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
**Date               : 05-Mar-2019
**CDSID              : BPANNEER
**Traceability       : RTC #1285296     
**Change Description : Initial Version
**============================================================================*/
#endif // LINSM_CBK_H
