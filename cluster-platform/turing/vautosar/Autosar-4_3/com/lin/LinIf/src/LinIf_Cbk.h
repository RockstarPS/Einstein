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
* File Name         :  LinIf_Cbk                                              *
* Module Short Name :  LinIf                                                 *
* Description       :  Header file for LinIf component                      *
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
#ifndef LINIF_CBK_H
#define LINIF_CBK_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "Std_Types.h"
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/








/***********************************************************************************************************************
 *  LinIf_WakeupConfirmation()
 ********************************************************************************************************************
* Service name:LinIf_WakeupConfirmation 
* Syntax: void LinIf_WakeupConfirmation( EcuM_WakeupSourceType WakeupSource ) 
* Service ID[hex]:0x61 
* Sync/Async: Synchronous 
* Reentrancy:Reentrant 
* Parameters (in): WakeupSource Source device which initiated the wakeup event: LIN controller or LIN transceiver 
*  Parameters (inout): None 
* Parameters (out): None 
* Return value: None 
*  Description: The LIN Driver or LIN Transceiver Driver will call this function to report the wake up source after the successful wakeup detection during CheckWakeup or after power on by bus.
 */


void LinIf_WakeupConfirmation( EcuM_WakeupSourceType WakeupSource );
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
**Date               : 24-APRIL-2019
**CDSID              : MKANNAN2
**Traceability       : RTC 
**Change Description :  Global Declaration of call back function LinIf_WakeupConfirmation
**============================================================================
**============================================================================
**Date               : 05-Mar-2019
**CDSID              : BPANNEER
**Traceability       : RTC #1285296     
**Change Description : Initial Version
**============================================================================*/
#endif // LINIF_CBK_H
