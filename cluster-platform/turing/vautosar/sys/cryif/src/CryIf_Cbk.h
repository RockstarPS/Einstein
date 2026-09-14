/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2018. Visteon Corporation owns all rights to           *
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
/*****************************************************************************
* @ingroup Crypto Service Interface
* @file CryIf.h
* @brief CRYIF main layer which handles the Init, Mainfunctions and APIs for SWCs
* ****************************************************************************/

#ifndef CRYIF_CBK_H
#define CRYIF_CBK_H

//#include "CryIf.h"
#include "Csm_Types.h"

/*****************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
******************************************************************************/


void CryIf_CallbackNotification(Crypto_JobType * job, Std_ReturnType result);

#endif /* CRYIF_CBK_H */

/*****************************************************************************
 *  END OF FILE: CryIf_Cbk.h
******************************************************************************/
