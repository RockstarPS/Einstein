/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2010. Visteon Corporation owns all rights to           *
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

File Name        :  WarnMsg_Core_Observer_Notify_Status_Cb.h
Module Short Name:  MSG_AP
VOBName          :  sw_hmi_ss
Author           :  vrk
Description      :  VIP msg application and frame work.
Organization     :  Driver Information Software Section,
                    Visteon Corporation
******************************************************************************/

#ifndef WarnMsg_Core_Observer_Notify_Status_Cb_H
#define WarnMsg_Core_Observer_Notify_Status_Cb_H

/* Shared type includes */
#include "Rte_Type.h"
#include "warn_SIF.h"
#include "WarningCommonLogic_autogen.inc"

#if MSG_NUM_INSTANCES > 1
extern SIF_STATUS WarnMsg_Core_Observer_Notify_Status_Cb(uint16 *Data, WarningId Qualifier, uint8 inst);
#else
extern SIF_STATUS WarnMsg_Core_Observer_Notify_Status_Cb(uint16 *Data, WarningId Qualifier);
#endif
#endif
/****************************************************************************
Date              : 12-12-2024
CDSID             : vrk
Traceability      : TFDCX32348-61095
Change Description: Updated to support Multi-instance
 ******************************************************************************/ 
/*End of Revision History*/
/*
 * END OF FILE
 *
 * 
 */
