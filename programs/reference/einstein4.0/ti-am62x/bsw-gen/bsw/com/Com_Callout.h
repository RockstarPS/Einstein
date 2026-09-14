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
 *    @file Com_Callout.h
 *    @ingroup Com Configuration
 *    @brief This is Com callout configuration header file. It contains definitions of callout
 *    configuration parameters for the Com module.
 *    Auto generated code in RSUNDAR5 at 2023-04-05 11:25:29.237384
 ********************************************************************************************************************/
#ifndef COM_CALLOUT_H
#define COM_CALLOUT_H

#include "Com_Types.h"

#define COM_START_SEC_CALLOUT_CODE
#include "MemMap.h"

/* Transmit message callout function */

/* Receive message callout function */
extern boolean ComRx_ABS0x102fCANCallout(PduIdType PduId, const PduInfoType *PduInfoPtr);
void VehicleSpeed_timeout_status(boolean *p_ret_val_bool);
void Airbag_timeout_status(boolean *p_ret_val_bool);

#define COM_START_SEC_CALLOUT_CODE
#include "MemMap.h"

#endif /* COM_CALLOUT_H */
/*******************************************************************************************************************
 *                                 END OF FILE                                                                      *
 ********************************************************************************************************************/
