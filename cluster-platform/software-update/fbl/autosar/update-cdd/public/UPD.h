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

#ifndef UPD_H
#define UPD_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "UPD_Types.h"

//=====================================================================================================================
//  Management functions
//=====================================================================================================================
Std_ReturnType UPD_Init(void);
Std_ReturnType UPD_Task(void);
boolean        UPD_IsBusy(void);
tUPDWorkload   UPD_GetWorkload(void);

Std_ReturnType UPD_Suspend(void);
Std_ReturnType UPD_Deserialize(tUPDStream* pStream);
Std_ReturnType UPD_Serialize(tUPDStream* pStream);

#ifdef __cplusplus
}
#endif
#endif /*UPD_H*/
