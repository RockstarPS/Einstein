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
//
// File generated automatically using Visteon WrnCtrl Configurator 1.0
// Date: Tue Nov 24 15:23:34 EET 2015
// User: YDOBREV
// Configuration: DIAGNOSTICS
// Comment:
//      Configuration for TA 1.4
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef WRNCTRL_CFG_H_
#define WRNCTRL_CFG_H_


//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================

#define eWrnId_NeutralTowEnabled      ((TWrnId)0)
#define eWrnId_NeutralTowDisabled      ((TWrnId)1)
#define eWrnId_DoorAjar      ((TWrnId)2)
#define eWrnId_CheckBrake      ((TWrnId)3)
#define eWrnId_LowTirePressure      ((TWrnId)4)
#define eWrnId_MyKeyActive      ((TWrnId)5)
#define eWrnId_SlowForHDC      ((TWrnId)6)
#define eWrnId_Overspeed      ((TWrnId)7)
#define eWrnId_Count      ((TWrnId)8)

#define cOBSERVER_ITERATOR_TIMEOUT       ((uint16)100)      // 30...2000, 100 is default
#define cOBSERVER_READY_TIMEOUT          ((uint16)1000)        // 100...5000, 1000 is default
#define cNEW_WRN_MIN_DSP_TIME            ((uint16)2000)		  // 100...65000, 2000 is default
#define cREPEAT_WRN_TIME                 ((uint32)600000)   			 // 100...4294967295, 600000 is default
#define cARBITRATION_SCHEMA_FORD                              // No value here

typedef struct SWrnDesc_t
{
    uint16   TempAlertTimeout;
    uint16   MainPriority;
    boolean  ManualAck;
    boolean  Repetitive;
    boolean  ActiveInStart;
} SWrnDesc;


//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

const SWrnDesc * WrnCtrl_GetWrnDescr( const TWrnId Id );

#endif //WRNCTRL_CFG_H_
