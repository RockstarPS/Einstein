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

#ifndef ECUMEXT_CFG_H
#define ECUMEXT_CFG_H

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


//----------------------------------------------------------------------------------------------------------------------
// Exported Macros
//----------------------------------------------------------------------------------------------------------------------
#define ECUMEXT_ENTER_CRITICAL_SECTION()           SuspendAllInterrupts()
#define ECUMEXT_EXIT_CRITICAL_SECTION()            ResumeAllInterrupts()

#define EARLY_WAKEUP_MAGIC_NUMBER    ((uint32)0x34A95EB3)
#define NORMAL_WAKEUP_MAGIC_NUMBER   ((uint32)0x37765EF6)
#define MCU_NORMAL_WAKEUP_ID    29

//----------------------------------------------------------------------------------------------------------------------
// Exported functions
//----------------------------------------------------------------------------------------------------------------------
//extern VCONST Mcu_ConfigType* pMcuModuleConfiguration; 
//extern VCONST Pwm_ConfigType* pPwmChannelConfigSet;

extern void InitEcuMZero( void );
	
	
#endif  // ECUMEXT_CFG_H

//======================================================================================================================
// FILE END
//======================================================================================================================
