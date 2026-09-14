/*************************************************************************************************************************
*                                                                            											 *
*              CONFIDENTIAL VISTEON CORPORATION                              											 *
*                                                                            											 *
* This is an unpublished work of authorship, which contains trade            											 *
* secrets, created in 2023. Visteon Corporation owns all rights to           											 *
* this work and intends to maintain it in confidence to preserve             											 *
* its trade secret status. Visteon Corporation reserves the right,           											 *
* under the copyright laws of the United States or those of any              											 *
* other country that may have jurisdiction, to protect this work             											 *
* as an unpublished work, in the event of an inadvertent or                  											 *
* deliberate unauthorized publication. Visteon Corporation also              											 *
* reserves its rights under all copyright laws to protect this               											 *
* work as a published work, when appropriate. Those having access            											 *
* to this work may not copy it, use it, modify it or disclose the            											 *
* information contained in it without the written authorization              											 *
* of Visteon Corporation.                                                    											 *
*                                                                            											 *
**************************************************************************************************************************/
#ifndef __ECUAPPM_CMDPROCESSING_H_
#define __ECUAPPM_CMDPROCESSING_H_

/**************************************************************************************************************************
*  											HEADER FILES INCLUSION												 		  *
***************************************************************************************************************************/
#include "EcuAppM_Cfg.h"
#include "EcuAppM.h"
/**************************************************************************************************************************
*  											CONSTANTS & TYPES												 		  	  *
***************************************************************************************************************************/

uint8 EcuAppM_GroupStateChangeRequest(uint8 GroupId,uint8 GroupCmd);
uint8 EcuAppM_GroupStateChangeRequestProcessing(uint8 Groupid, uint8 GroupCmd);
uint8 EcuAppM_DispatchSafeGroupStateChangeRequest(uint8 Groupid, uint8 GroupCmd);
uint8 EcuAppM_SafeGroupStateChangeRequestProcessing(uint8 Groupid, uint8 GroupCmd);

#ifndef eCmpCmd_Init
#define eCmpCmd_Init		(0u)
#endif

# ifndef eCmpCmd_Activate
#define eCmpCmd_Activate (2u)
#endif

#ifndef eCmpCmd_DeActivate
#define eCmpCmd_DeActivate (3u)
#endif   

#endif 

/****************************************************************************************************************************
Date              : 18-09-23
CDSID             : akappa
Traceability      :
Change Description: Initial Version of EcuAppM_CmdProcessing.
*****************************************************************************************************************************/
/********************************************************************************************************************************************************
Date              : 05-09-23
CDSID             : akappa
Traceability      :
Change Description: implementation of safety group handling.
********************************************************************************************************************************************************/
/* End Of File */
