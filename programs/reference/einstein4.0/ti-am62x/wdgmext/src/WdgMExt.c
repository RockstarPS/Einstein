/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2018. Visteon Corporation owns all rights to           *
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
/*!*************************************************************************** 
 * @ingroup
 * @file WdgMExt.c
 * @brief SafeBsw main layer which handles the Init, Mainfunctions and APIs for SWCs
 * ****************************************************************************/
/*****************************************************************************
 *  Include Files                                                             *
 ******************************************************************************/
#include "Std_Types.h"
#include "WdgM.h"
#include "WdgMExt.h"
#include "PmicCdd.h"

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
void WdgmExt_LogPreReset(void)
{
    /* Keep it tiny and deterministic */
    uint8 logData[5] = {0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu};
    WdgM_GlobalStatusType fl_GlobalStatus = WDGM_GLOBAL_STATUS_DEACTIVATED;

    (void)WdgM_GetGlobalStatus(&fl_GlobalStatus);

    logData[0] = (uint8)fl_GlobalStatus;            /* global status */

    (void)FltM_ReportFault(FLTM_WDGM_PRE_RESET, FLTM_ACTIVE, logData, 5u);
}

/*============================================================================
**
** Function Name    :   WdgmExt_SetTriggerCondition
**
** Visibility       :   Public
**
** Description      :   Setting up a watchdog timer trigger condition. 
**
** Inputs           :	uint8 DeviceIndex - Device Index
**                      uint16 Timeout - Timeout to trigger the watchdog
**
** Outputs          :	None
**
** Critical Section :
**
**==========================================================================*/
void WdgmExt_SetTriggerCondition(uint8 DeviceIndex, uint16 Timeout)
{
static uint8 s_loggedOnce = 0u;

    if ((Timeout == 0u) && (s_loggedOnce == 0u))
    {
        s_loggedOnce = 1u;          /* guard against repeated calls */
        WdgmExt_LogPreReset();      /* snapshot BEFORE we actually stop servicing */
    }

    /* Always delegate to the real device */
    PmicCdd_WdgSetTriggerCondition(DeviceIndex, Timeout);
}

/*============================================================================
**
** Function Name    :   WdgmExt_SetMode
**
** Visibility       :   Public
**
** Description      :   Setting up a watchdog timer mode.
**
** Invocation       :   WdgIf
**
** Inputs           :  WdgIf_ModeType WdgMode - Mode of the watchdog
**
** Outputs          :  STD_OK - Success
**                     STD_NOT_OK - Failure
**
** Critical Section :  No
**
**==========================================================================*/
void WdgmExt_SetMode(uint8 DeviceIndex, WdgIf_ModeType Mode)
{
    (void)DeviceIndex;
    (void)PmicCdd_WdgSetMode(Mode);
}


/*============================================================================
**
** Function Name    :   OsTask_SafeBsw_WdgM_CheckPoint_10ms
**
** Visibility       :   Public
**
** Description      :   For Watchdog manager monitoring  of the safety-critical task OsTask_SafeBsw_WdgM_CheckPoint_10ms periodically 
**
** Invocation       :   Called from OsTask_WdgMngt in Rte_OsApplication_Trusted.c.
**
** Inputs           :	None
**
** Outputs          :	None
**
** Critical Section :
**
**==========================================================================*/
void IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_10ms(void)
{
    (void)WdgM_CheckpointReached(0,0);
}
/*============================================================================
**
** Function Name    :   OsTask_SafeBsw_WdgM_CheckPoint_20ms
**
** Visibility       :   Public
**
** Description      :   For Watchdog manager monitoring  of the safety-critical task OsTask_SafeBsw_WdgM_CheckPoint_20ms periodically 
**
** Invocation       :   Called from OsTask_SafeBsw in Rte_OsApplication_Trusted.c.
**
** Inputs           :	None
**
** Outputs          :	None
**
** Critical Section :
**
**==========================================================================*/
void IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_20ms(void)
{
    (void)WdgM_CheckpointReached(0u, 1u);
}
/*============================================================================
**
** Function Name    :   OsTask_SafeBsw_WdgM_CheckPoint_30ms
**
** Visibility       :   Public
**
** Description      :   For Watchdog manager monitoring  of the safety-critical task OsTask_SafeBsw_WdgM_CheckPoint_30ms periodically 
**
** Invocation       :   Called from OsTask_SafeApp in Rte_OsApplication_Trusted.c.
**
** Inputs           :	None
**
** Outputs          :	None
**
** Critical Section :
**
**==========================================================================*/
void IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_30ms(void)
{
    (void)WdgM_CheckpointReached(0u,2u);
}

 /*============================================================================
**
** Function Name    :   OsTask_SafeBsw_WdgM_CheckPoint_30ms
**
** Visibility       :   Public
**
** Description      :   For Watchdog manager monitoring  of the safety-critical task OsTask_SafeBsw_WdgM_CheckPoint_10ms periodically 
**
** Invocation       :   Called from OsTask_SafeApp in Rte_OsApplication_Trusted.c.
**
** Inputs           :	None
**
** Outputs          :	None
**
** Critical Section :
**
**==========================================================================*/
void IoHwAb_OsTask_SafeBsw_Task_10ms(void)
{
    (void)WdgM_CheckpointReached(0u,3u);
}
/*--------------------------------------------------------------------------------------------------------------------
Date              : 22/Aug/2025
By                : abasavar
Traceability      : PE4TI29141-9792
Change Description: WdgM Alive SuperVision Config
----------------------------------------------------------------------------------------------------------------------*/
/* end of file =============================================================*/
