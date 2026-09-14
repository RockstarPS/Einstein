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

#ifndef UPD_IBootControl_H
#define UPD_IBootControl_H

#include "UPD.h"

//=====================================================================================================================
//  Boot control interface
//=====================================================================================================================
Std_ReturnType     UPD_IBootControl_SetBootSlot(boolean ActiveSlot); // FALSE = BANKA; TRUE=BANKB
Std_ReturnType     UPD_IBootControl_GetBootSlot(boolean* pActiveSlot, boolean* pExpectedSlot); // FALSE = BANKA; TRUE=BANKB
Std_ReturnType     UPD_IBootControl_SetAppValidity(boolean isValid); // FALSE = BANKA; TRUE=BANKB


#endif /*UPD_IBootControl_H*/
