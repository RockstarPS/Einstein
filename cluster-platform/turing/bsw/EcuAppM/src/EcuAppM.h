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
#ifndef __ECUAPPM_H_
#define __ECUAPPM_H_
/**************************************************************************************************************************
*  											HEADER FILES INCLUSION												 		  *
***************************************************************************************************************************/
#include "Std_Types.h"
#include "EcuAppM_Defines.h"
#include "EcuAppM_Cfg.h"

/**************************************************************************************************************************
*  											CONSTANTS & TYPES												 		  	  *
***************************************************************************************************************************/



/**************************************************************************************************************************
*  											FUNCTION DECLARATIONS												 		  *
***************************************************************************************************************************/
extern FUNC(uint8, ECUAPPM_CODE) EcuAppM_GetApplicationSleepStatus(void);
extern FUNC(uint32, ECUAPPM_CODE) EcuAppM_GetWakeupEventStatus(void);
extern FUNC(void, ECUAPPM_CODE) EcuAppM_SetEcuAppMState(uint8 state);
extern FUNC(uint32, ECUAPPM_CODE) EcuAppM_GetWakeupSources(void);
extern FUNC(void, ECUAPPM_CODE) EcuAppM_SetWakeupSources(uint32 WakeupSource);
extern FUNC(void, ECUAPPM_CODE) EcuAppM_ClearWakeupSources(void);
extern FUNC(void, ECUAPPM_CODE) EcuAppM_Init(void);
extern FUNC(void, ECUAPPM_CODE) EcuAppM_MainFunction(void);

extern void EcuAppM_StateMachine_initialize(void);
extern void EcuAppM_StateMachine_step(void);
#endif 
/***************************************************************************************************************************
Date              : 18-09-23
CDSID             : akappa
Traceability      :
Change Description: Initial Version of EcuAppM.
***************************************************************************************************************************/
/**************************************************************************************************************************
Date              : 21-11-23
CDSID             : akappa
Traceability      :
Change Description: Modified according to the Autosar Memory mapping.
***************************************************************************************************************************/
/* End Of File */
