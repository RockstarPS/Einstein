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

# ifndef UPD_UpdateMan_H
# define UPD_UpdateMan_H

# include "UPD.h"
# include "UPDi_Target.h"

//=====================================================================================================================
/* CONSTANTS & TYPES */
//=====================================================================================================================

//=====================================================================================================================
/* Update interface */
//=====================================================================================================================
Std_ReturnType UPDUpdateMan_StartUPDate(tUPDBank Bank);
Std_ReturnType UPDUpdateMan_Validate(void);
Std_ReturnType UPDUpdateMan_Activate(void);
Std_ReturnType UPDUpdateMan_Rollback(void);
Std_ReturnType UPDUpdateMan_Reset(void);
Std_ReturnType UPDUpdateMan_Commit(void);

void UPDUpdateMan_InspectBank(tUPDBank Bank);


//=====================================================================================================================
/* Health management interface */
//=====================================================================================================================
Std_ReturnType UPDUpdateMan_BootStatus(boolean BootSuccess);

//=====================================================================================================================
/* Management Interface */
//=====================================================================================================================
Std_ReturnType UPDUpdateMan_Init(void);
void 		   UPDUpdateMan_Task(void);
Std_ReturnType UPDUpdateMan_Serialize(tUPDStream *pStream);
Std_ReturnType UPDUpdateMan_Deserialize(tUPDStream *pStream);

//=====================================================================================================================
/* UPD CDD Internal */
//=====================================================================================================================
tUPDBank 	     UPDUpdateMan_GetUPDatedBank(void);
boolean 	     UPDUpdateMan_GetSlot(tUPDBank Bank);// // return FALSE => BANKA; TRUE=BANKB
tUPDUpdateState  UPDUpdateMan_GetUpdateState(void);

//=====================================================================================================================
/* Private */
//=====================================================================================================================
boolean UPDUpdateMan_IsActivatePossible(void);


# endif /*UPD_UpdateMan_H*/
