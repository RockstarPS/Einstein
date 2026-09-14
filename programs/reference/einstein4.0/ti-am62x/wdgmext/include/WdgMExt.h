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
 * @file WdgMExt.h
 * @brief WdgMExt main layer which handles the Init, Mainfunctions and APIs for SWCs
 * ****************************************************************************/
/*****************************************************************************
 *  Include Files                                                             *
 ******************************************************************************/
#include "PmicCdd.h"
#include <string.h>
#include "Std_Types.h"
#include "WdgIf_Types.h"
#define FLTM_LOG_SIZE 2u
#define OS_FLTMID_MAP_NUM 1u


#define FLTM_WDGM_PRE_RESET     (WDGM_ALIVE_FAIL)

void WdgmExt_SetTriggerCondition(uint8 DeviceIndex, uint16 Timeout);
void WdgmExt_SetMode(uint8 DeviceIndex, WdgIf_ModeType Mode);
void WdgmExt_LogPreReset(void);
void IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_10ms(void);
void IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_20ms(void);
void IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_30ms(void);
void IoHwAb_OsTask_SafeBsw_Task_10ms(void);
/*--------------------------------------------------------------------------------------------------------------------
Date              : 22/Aug/2025
By                : abasavar
Traceability      : PE4TI29141-9792
Change Description: WdgM Alive SuperVision Config
----------------------------------------------------------------------------------------------------------------------*/
/* end of file =============================================================*/