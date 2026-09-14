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


//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================
#include "BacklightCdd_ErrorHandler.h"
#include "BacklightCdd_Version.h"

//======================================================================================================================
/** \brief BacklightCdd_ReportError
 **
 ** This function reports DET errors for Backlight CDD.
 **
 ** \param[in] ApiId   ID of API which causing DET error
 **            ErrorId ID mapped to current error
 ** \return   void
 **			   
 **      	  
 ** */
//======================================================================================================================

FUNC(void, CBacklightCdd_CODE) BacklightCdd_ReportError
(
  VAR(uint8, AUTOMATIC) ApiId,
  VAR(uint8, AUTOMATIC) ErrorId
)
{
	(void) ApiId;
	(void) ErrorId;

  #if (BACKLIGHTCDD_DEV_ERROR_DETECT == STD_ON)
    /* DET error reporting */
    (void)Det_ReportError((uint16)BACKLIGHTCDD_MODULE_ID, (uint8)BACKLIGHTCDD_INSTANCE_ID, (uint8)ApiId, (uint8)ErrorId);
#endif

}

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
