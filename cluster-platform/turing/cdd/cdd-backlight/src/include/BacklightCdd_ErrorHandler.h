//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2026] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef BACKLIGHTCDD_DET_H
#define BACKLIGHTCDD_DET_H

//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================
#include "CDD_Backlight_Cfg.h"

#if (BACKLIGHTCDD_DEV_ERROR_DETECT == STD_ON)
#include <Det.h>
#endif /* #if BACKLIGHTCDD_DEV_ERROR_DETECT == STD_ON */

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/** \brief EcuPowerM_ReportError
 **
 ** This function reports an error to the error handler
 ** and optionally to the DET.
 **
 ** \param [in] ApiId   Id of the service that detected the error.
 ** \param [in] ErrorId Id of the error that was detected.
 **
 ** \return     None.
 **
 ** */
extern FUNC(void, CBacklightCdd_CODE) BacklightCdd_ReportError
(
  VAR(uint8, AUTOMATIC) ApiId,
  VAR(uint8, AUTOMATIC) ErrorId
);



#endif //__BACKLIGHTCDD_DET_H__

/**********************************************************************************************************************************************
*                                 END OF FILE                                                                      
***********************************************************************************************************************************************/

/*---------------------------------------------------------------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------------------------------*/
/*==============================================================================================================================================
Date              	: 03-12-25
CDSID             	: yviswana
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
/*==============================================================================================================================================
Date              	: 03-17-26
CDSID             	: bmahesan
Traceability      	: ASCDD-241
Change Description	: Updated Version for MAX20446B/LP8867.
================================================================================================================================================*/
/*==============================================================================================================================================
Date              	: 04-07-26
CDSID             	: mmahend2
Traceability      	: ASCDD-106
Change Description	: Fixed KW warnings.
================================================================================================================================================*/


