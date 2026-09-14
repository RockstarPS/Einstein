//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
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

/* double include prevention */
#ifndef COMMEXT_H
#define COMMEXT_H

#include "ComMExt_Cfg.h"
#include "ComM.h"
#include "ComM_EcuMBswM.h"
//#include "McuExt.h"
#include "Can_GeneralTypes.h"  /* MD_MSR_1.1 */

/**********************************************************************************************************************
 * Schedule network related BSW modules unsupported in DAVINCI
 *********************************************************************************************************************/
/* Local periodic task to schedule network related BSW modules unsupported in DAVINCI */
//extern void ComMExt_Local_MainFunction(void);
extern void ComMExt_Init(void);
extern FUNC(void, COM_CODE) Com_SetIpduGroup(Com_IpduGroupVector ipduGroupVector, Com_IpduGroupIdType ipduGroupId,
                                      boolean bitval);
extern FUNC(void, COM_CODE) Com_IpduGroupControl(Com_IpduGroupVector ipduGroupVector, boolean initialize);
extern FUNC(void, COM_CODE) Com_ClearIpduGroupVector(Com_IpduGroupVector ipduGroupVector);

typedef uint8 ComMExt_IpduGroupId;
extern Std_ReturnType ComMExt_PduGroupActivationStatus (ComMExt_IpduGroupId GroupId, boolean* IPdu_GrpActiveStatus);
extern FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_GetCurrentComMode(UInt8 Channel, P2VAR(UInt8, AUTOMATIC, RTE_COMMEXT_APPL_VAR) ComMode);
extern FUNC(void, ComMExt_CODE) ComMExt_Impl_MainFunction(void);
extern FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_ActivateSilentCommunication(UInt8 Channel);
extern FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_DeActivateSilentCommunication(UInt8 Channel);
extern FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_CommControlDeActivateRx(ComMExt_IpduGroupId GroupId);
extern FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_CommControlActivateRx(ComMExt_IpduGroupId GroupId);
extern FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_CommControlDeActivateTx(ComMExt_IpduGroupId GroupId);
extern FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_CommControlActivateTx(ComMExt_IpduGroupId GroupId);
extern FUNC(void, ComMExt_CODE) ComMExt_CAN_CommControlSetDone(boolean PduInitRequest);
extern FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_ReleaseCommunication(UInt8 Channel);
extern FUNC(Std_ReturnType, ComMExt_CODE) ComMExt_CAN_RequestCommunication(UInt8 Channel);
extern Std_ReturnType ComMExt_GetBusOffStatus(uint8 Channel, boolean* BusOffStatus);

#endif /*COMMEXT_H*/
/*---------------------------------------------------------------------------------------
REVISION HISTORY
-----------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------
Date              : 8/Nov/2024
By                : vtamilar
Traceability      : RTC #1179904
Change Description: Initial version.
-----------------------------------------------------------------------------------------*/
