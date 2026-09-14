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

# ifndef UPD_IUpdate_H
# define UPD_IUpdate_H

# include "UPD_Types.h"

#ifdef __cplusplus
extern "C"
{
#endif
//=====================================================================================================================
//  Update interface
//=====================================================================================================================
Std_ReturnType     UPD_IUpdate_StartUPDate(tUPDBank Bank);
Std_ReturnType     UPD_IUpdate_Validate(void);
Std_ReturnType     UPD_IUpdate_Activate(void);
Std_ReturnType     UPD_IUpdate_Rollback(void);
Std_ReturnType     UPD_IUpdate_Terminate(void);
tUPDUpdateState    UPD_IUpdate_GetState(void);
Std_ReturnType     UPD_IUpdate_Commit(void); 
tUPDUpdateState    UPD_IUpdate_GetUpdateState(void);

//=====================================================================================================================
//  Health management interface
//=====================================================================================================================
Std_ReturnType     UPD_IUpdate_BootStatus(boolean BootSuccess);

#ifdef __cplusplus
}
#endif
#endif /*UPD_IUpdate_H*/
