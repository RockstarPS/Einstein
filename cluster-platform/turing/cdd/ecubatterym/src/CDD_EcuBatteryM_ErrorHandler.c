//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2023] Visteon Corporation
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
#include "EcuBatteryM_Types.h"
#include "EcuBatteryM_Det.h"
#include "EcuBatteryM_Version.h"
//======================================================================================================================

/** \brief EcuBatteryM_ReportError
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
//======================================================================================================================
FUNC(void, ECUBATTERYM_CODE) EcuBatteryM_ReportError(
VAR(uint8, AUTOMATIC) ApiId,
VAR(uint8, AUTOMATIC) ErrorId) {
	/* DET error reporting */
#if ECUBATTERYM_DEV_ERROR_DETECT == STD_ON
	(void)Det_ReportError(ECUBATTERYM_MODULE_ID, ECUBATTERYM_INSTANCE_ID, ApiId, ErrorId);
#endif /* #if ECUBATTERYM_DEV_ERROR_DETECT == STD_ON */
}

/*==============================================================================================================================================
Date              	: 21-02-2025
CDSID             	: TGUNASEK
Traceability      	:
Change Description	: Initial Version.
================================================================================================================================================*/
