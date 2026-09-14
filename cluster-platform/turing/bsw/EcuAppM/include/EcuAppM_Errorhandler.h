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
#ifndef __ECUAPPM_ERRORHANDLER_H_
#define __ECUAPPM_ERRORHANDLER_H_

/**************************************************************************************************************************
*                            				header files inclusion                                  											  *
***************************************************************************************************************************/
#include "EcuAppM_MemoryMap.h"


/**************************************************************************************************************************
*                         Function Declarations                              											  *
***************************************************************************************************************************/
extern FUNC(void, ECUAPPM_ERRORHANDLER_CODE)EcuAppM_ReportError(uint8 Apiid,uint8 Errorid);

#endif
/**************************************************************************************************************************
Date              : 21-11-23
CDSID             : akappa
Traceability      :
Change Description: Initial Version of EcuAppM_Errorhandler.h.
***************************************************************************************************************************/
/* End Of File */
