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
# ifndef UPD_ITargets_H
# define UPD_ITargets_H

# include "UPD_Types.h"
# include "UPDd_Types.h"

#ifdef __cplusplus
extern "C"
{
#endif
//=====================================================================================================================
//  Update interface
//=====================================================================================================================

tUPDiTargetState UPD_ITargets_GetTargetState(const char* TargetName, tUPDBank Bank);
Std_ReturnType   UPD_ITargets_GetHash(uint8_t TargetId, tUPDHashInfo* Hash);
const char*      UPD_ITargets_GetTargetNameById(uint8_t TargetId);
tUPDiTargetState UPD_ITargets_GetTargetStateById(uint8_t TargetId,tUPDBank Bank);
tUPDdManifest*   UPD_ITargets_GetManifestById(uint8_t TargetId, tUPDBank Bank);
uint8_t			 UPD_ITargetCount(void); /*get targetcount*/
Std_ReturnType   UPD_ITargets_VerifyTarget(uint8_t TargetId, tUPDHashInfo* Hash);

#ifdef __cplusplus
}
#endif

# endif /*UPD_ITargets_H*/


