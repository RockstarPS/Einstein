/*************************************************************************************************************************
*                                                                                                                         *
*              CONFIDENTIAL VISTEON CORPORATION                                                                           *
*                                                                                                                         *
* This is an unpublished work of authorship, which contains trade                                                         *
* secrets, created in 2023. Visteon Corporation owns all rights to                                                        *
* this work and intends to maintain it in confidence to preserve                                                          *
* its trade secret status. Visteon Corporation reserves the right,                                                        *
* under the copyright laws of the United States or those of any                                                           *
* other country that may have jurisdiction, to protect this work                                                          *
* as an unpublished work, in the event of an inadvertent or                                                               *
* deliberate unauthorized publication. Visteon Corporation also                                                           *
* reserves its rights under all copyright laws to protect this                                                            *
* work as a published work, when appropriate. Those having access                                                         *
* to this work may not copy it, use it, modify it or disclose the                                                         *
* information contained in it without the written authorization                                                           *
* of Visteon Corporation.                                                                                                 *
*                                                                                                                         *
**************************************************************************************************************************/

/**************************************************************************************************************************
*                            header files inclusion                                                                                *
***************************************************************************************************************************/
#include "EcuPowerM.h"
#include "EcuMExt.h"
#include "Dio.h"


/***************************************************************************************************************************
** Function Name     : uint8 Dio_IOPinInId_Read_HUD(uint8 *Data)
**
** Description       : This is the function for IOPIN read for HUD.
**
***************************************************************************************************************************/
FUNC(void, ECUPOWERM_CODE) EcuPowerM_UserCallback(	VAR(EcuPowerM_HardwareIdType, AUTOMATIC) hwid, VAR(uint8, AUTOMATIC) status)
{
	
}
/* End Of File */
