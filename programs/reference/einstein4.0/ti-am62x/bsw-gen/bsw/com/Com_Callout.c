/********************************************************************************************************************
 *                                   C O P Y R I G H T                                                               *
 *********************************************************************************************************************
 * Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
 *                                                                                                                   *
 * NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
 * Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
 * its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
 * or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
 * in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
 * rights under all copyright laws to protect this work as a published work, when appropriate.                       *
 * Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
 * without the written authorization of Visteon Corporation.                                                         *
 ********************************************************************************************************************/
/*!*****************************************************************************************************************
 *    @file Com_Callout.c
 *    @brief This file implements the I-Pdu callout function configured in the Com . This file implements the alive
 *    counter and checksum for FCAN messages
 ********************************************************************************************************************/
#include "Std_Types.h"
#include "Com_Callout.h"
#include "E2EXf_Cfg.h"
#include "Rte_CComAbsMdl_Type.h"
#include "ComAbsMdl.h"

/* Receive message callout function */
/*boolean ComRx_ABS0x102fCANCallout(PduIdType PduId, const PduInfoType *PduInfoPtr)
{
	uint8 ret = TRUE;
	uint8 E2EStatus = 1U;
	Can_IdType CanId = 0x102;
	E2EStatus = E2EXf_Inv_FirstTrans((Can_IdType)CanId, PduInfoPtr->SduDataPtr, (uint16 *)&(PduInfoPtr->SduLength), PduInfoPtr->SduDataPtr, (uint16)(PduInfoPtr->SduLength));

	if (E2E_E_OK != E2EStatus)
	{
		ret = FALSE;
	}
	return ret;
}
*/
/******************************************************************************
Function Name     : ABS_message_timeout_status

Description       : This function is to check the ABS message timeout status.

Invocation        : Invoked by fdtc.cfg

Parameters        : None

Return Value      : Pre condition satisfied status

Critical Section  : None
******************************************************************************/

void VehicleSpeed_timeout_status(boolean *p_ret_val_bool)
{
	uint8 fl_VehicleSpeed_status_U8 = 0;
	uint16 fl_VehicleSpeed_value_U16 = 0;
	CComAbsMdl_RxCan_GetSignalValue(eVehicleSpeedABSIn, (void *)&fl_VehicleSpeed_value_U16, &fl_VehicleSpeed_status_U8);
	if (fl_VehicleSpeed_status_U8 == FALSE)
	{
		*p_ret_val_bool = FALSE;
	}
}

void Airbag_timeout_status(boolean *p_ret_val_bool)
{
	uint8 fl_Airbag_status_U8 = 0;
	uint16 fl_Airbag_value_U16 = 0;
	CComAbsMdl_RxCan_GetSignalValue(eAirbagIn, (void *)&fl_Airbag_value_U16, &fl_Airbag_status_U8);
	if (fl_Airbag_status_U8 == FALSE)
	{
		*p_ret_val_bool = FALSE;
	}
}