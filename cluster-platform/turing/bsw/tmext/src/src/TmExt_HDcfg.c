//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
/*!*************************************************************************************************
* @file TmExt_HCfg.c
* @brief Timer Extension wait time implementation in nanosecond.
***************************************************************************************************/
/**********************************************************************************************************************
*  Include Files                                                                                                      *
*********************************************************************************************************************/
#include "Rte_TmExt.h"
#include "TmExt_Cfg.h"
#include "TmExt_Timer.h"
#include "TmExt_Cfg.h"
#include "Gpt.h"
#include "Gpt_External.h"

#define TMEXT_CODE_SEC_START
#include "MemMap.h"

#define SIZE_OF_UINT16    65535u
/*!********************************************************************************************************************

 @fn        TmExt_BusyWait1ns

 @brief     This method is used to actively wait a predetermined time in nano seconds.
 @brief     Minimal waiting time is 1ns.
 @brief     Minimal increment of waiting time is 500 ns. Source execution takes approximately 1 us.
 @brief     Some taken measurements are listed below.
 @brief     time[ns]    cycles --> WaitingTimeMin/16
 @brief     2490        100
 @brief     3967,4      200
 @brief     5909,6      300
 @brief     7519,8      400
 @brief     9279,4      500
 @brief     10740,2     600

 @param[in] Time to wait in [ns]

 @return    None

**********************************************************************************************************************/
static TMExt_AdminDataType TMExt_AdminData;
void TmExt_BusyWait1ns(const uint16 WaitingTimeMin )
{
	volatile uint32  NbCycles = 0;
	TMExt_AdminData.TMExt_TmStartTime = TMEXT_GET_CURRENT_TIME_IN_US;
    TMExt_AdminData.TMExt_TmCurrentTime = 0;
    TMExt_AdminData.TMExt_TmElapsedTime = 0;
    
	if(WaitingTimeMin < SIZE_OF_UINT16)
	{
        NbCycles = (uint16)(WaitingTimeMin >> cTIMER_RESOLUTION_MIN);
	}
        
    while(TMExt_AdminData.TMExt_TmElapsedTime < NbCycles)
    {
        TMExt_AdminData.TMExt_TmCurrentTime = TMEXT_GET_CURRENT_TIME_IN_US;
        TMExt_AdminData.TMExt_TmElapsedTime = (TMExt_AdminData.TMExt_TmCurrentTime - TMExt_AdminData.TMExt_TmStartTime);
    }
}
#define TMEXT_CODE_SEC_END
#include "MemMap.h"
/*---------------------------------------------------------------------------
Date              : 11-May-2018
CDSID             : asivalin
Traceability      : RTC-1116694
Change Description: doxygen documentation.
Version           : 3:turing_bsw_tmext_0.2
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date              : 1-Mar-2023
CDSID             : gthanapp
Traceability      : RTC-1928662
Change Description: Misra and certc warning fix
Version           : turing_bsw_tmext_0.12
-----------------------------------------------------------------------------*/

