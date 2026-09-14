//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2017] Visteon Corporation
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
#ifndef ECUMEXT_H
#define ECUMEXT_H

#include "Rte_Type.h"
#include "PmicCdd.h"
//----------------------------------------------------------------------------------------------------------------------
// Included files
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Constant data
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported type
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported data
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
// Constant exported data
//----------------------------------------------------------------------------------------------------------------------
#define PMIC_WKUP_MMR_SRC_REG_ADDR  (0x43018178U)
#define PMIC_MCU_MMR_SRC_REG_ADDR   (0x04518178U) //#issue Review Problem ID NA: Conversion performed between a pointer to an object 'uint32*' and an integer type 'unsigned int'
//----------------------------------------------------------------------------------------------------------------------
// Exported Macros
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// Exported functions
//----------------------------------------------------------------------------------------------------------------------
void EcuMExt_MainFunction( void );
void EcuMExt_DeActivateAll(void);
FUNC(void, ECUM_CODE) EcuM_AL_DriverRestartList(void);
void EcuM_CheckRamHash(void);
void EcuM_StartOS(AppModeType appMode);
void NvM_MultiBlockJobEndNotification(uint8 ServiceId, NvM_RequestResultType JobResult);
extern void EcuMExt_PowerFaultIntDetected (void);
extern boolean EcuMExt_GetNvmReadAllStatus(void);
extern Std_ReturnType EcumExt_IsResetPath(void);
extern boolean Get_NvMReadAllResult(void);
extern Std_ReturnType EcuMExt_ReleaseRUN(EcuM_UserType user);
extern Std_ReturnType EcuMExt_RequestRUN(EcuM_UserType user);
extern void EcuMExt_PmicCdd_CheckWakeup(void);
extern void TmExt_Init( void );
extern void BswFitCdd_Init(void);
extern void CanTrcv_Tja1145ATK_Init(void);
extern void Lin_DrvTest(void);
extern void EcumExt_SafeNvM_TriggerDataCompare(void);
extern Std_ReturnType EcuMExt_CustomCommandCallout(uint8 channel, uint16 * value, uint8 * error);
extern Std_ReturnType OsTrustedCall_IoHwAb_SetOutputPin(IoHwAb_DOutSignalIdType Arg1,boolean Arg2,IoHwAb_ErrorType* Arg3);
#endif  // ECUMEXT_H
