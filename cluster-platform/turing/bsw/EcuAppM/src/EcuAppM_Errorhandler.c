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
/**************************************************************************************************************************
*                            				header files inclusion                                  											  *
***************************************************************************************************************************/
#include "EcuAppM.h"
#include "EcuAppM_Version.h"
#include "EcuAppM_Errorhandler.h"

/*************************************************************************************************************************
** Function Name     : FUNC(void, ECUAPPM_ERRORHANDLER_CODE)EcuAppM_ReportError(uint8 api_id,uint8 error_id)
**
** Description       : This function used to report the det error.
**
** Invocation        : This function should be invoked from the EcuAppM module.
**
** Parameters        : Apiid,Errorid
**
** Return Value      : None
**
** Critical Section  : None
***************************************************************************************************************************/
FUNC(void, ECUAPPM_ERRORHANDLER_CODE)EcuAppM_ReportError(uint8 Apiid,uint8 Errorid)
{
 (void)Apiid;
 (void)Errorid;
 
 /* Need to add report det error function call */
 //(void)Det_ReportError(ECUAPPM_MODULE_ID, ECUAPPM_INSTANCE_ID, ApiId, ErrorId);
}
/**************************************************************************************************************************
Date              : 21-11-23
CDSID             : akappa
Traceability      :
Change Description: Initial Version of EcuAppM_Errorhandler.c.
***************************************************************************************************************************/
/* End Of File */
