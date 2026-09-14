/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2023. Visteon Corporation owns all rights to           *
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

#include "UPD_IBootControl.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include "metadata.h"
#ifdef __cplusplus
}
#endif

//=====================================================================================================================
//  Boot control interface
//=====================================================================================================================
boolean ActiveSlot = FALSE;
Std_ReturnType UPD_IBootControl_SetBootSlot(boolean _ActiveSlot)
{
	ActiveSlot = _ActiveSlot;
	return E_OK;
}
Std_ReturnType UPD_IBootControl_SetAppValidity(boolean isValid)
{
	return E_OK;
}
Std_ReturnType     UPD_IBootControl_GetBootSlot(boolean* pActiveSlot, boolean* pExpectedSlot)
{

	//read from meta data, if B is active then pExpectedSlot is A pActiveSlot =B
	// if A is active then pExpectedSlot is B pActiveSlot A
	
	uint8 currentPartition=0xFF;
	
	Metadata_GetActivePartition(ESwPartId_SBL, &currentPartition);
	if(currentPartition == EPartition_A)
	{
		*pActiveSlot = EPartition_A;
		*pExpectedSlot= EPartition_B ;
	}
	else if(currentPartition == EPartition_B)
	{
		*pActiveSlot =EPartition_B ;
		*pExpectedSlot=  EPartition_A;
	}
	else
	{

	}
	return E_OK;
}


