/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2017. Visteon Corporation owns all rights to           *
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
 *  File Name         :  Dem_Cfg.c                                                *
 *  Module Short Name :  ErrMgr                                               *
 *  VOBName           :                                                       *
 *  Author            : msavariy                                              *
 *  Description       : This file contains the Diagnostics request and        *
 *                       response handling functionlities.                    *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 * ---------------------------------------------------------------------------*
 * Compiler Name    :  GHS                                                    *
 * Target Hardware  :                                                         *
 *                                                                            *
 ******************************************************************************/
#ifndef DEM_CFG_C
#define DEM_CFG_C

/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "Std_Types.h"
#include "Dem.h"
#include "NvM.h"
#include "SchM_Dem.h"
#include "Dem_Cfg.h"

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/

/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/

/*****************************************************************************
 *                                Globally  accessed Variable Declarations    *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

const Dem_Cfg_PrimaryMemEntryType Dem_MemoryEntryInit =
{ 0 };

const Dem_Cfg_UdsStatusDataType Dem_Cfg_StatusDataInit =
{ 0 };

const Dem_Cfg_OpCycleType Dem_Cfg_OpCycleInit =
{0};


Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_0;
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_1;
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_2;
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_3;
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_4;


Dem_Cfg_UdsStatusDataType Dem_Cfg_StatusData;
Dem_Cfg_OpCycleType Dem_Cfg_OpCycle;
Dem_Cfg_AdminDataType Dem_Cfg_AdminData;

const uint8* Dem_Cfg_MemPtr[Dem_Cfg_Mem_Total_Entry] =
{ 
  (uint8*) &Dem_Cfg_OpCycle, 
  (uint8*) &Dem_Cfg_StatusData, 
  (uint8*) &Dem_PrimaryEntry_0, 
  (uint8*) &Dem_PrimaryEntry_1, 
  (uint8*) &Dem_PrimaryEntry_2, 
  (uint8*) &Dem_PrimaryEntry_3,
  (uint8*) &Dem_PrimaryEntry_4
};

#if (DEM_USE_NVM == STD_ON) 
const Dem_Cfg_NvRamBlockIdType Dem_Cfg_Memory_BlockId[Dem_Cfg_Mem_Total_Entry] =
{
    NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemAdmin,
    NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemStatus,
    NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_000,
    NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_001,
    NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_002,
    NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_003,
    NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_004
};
#endif

const Dem_Cfg_OpCycleStateType Dem_Cfg_OpCycleState[Dem_Cfg_Num_Of_OpCycle] =
{
  { Dem_CfgDemOperationCycle_Ignition, 0, 1, 1}	
};

/*configured as per DTC Definition list */
const Dem_Cfg_EnableConditionGroupType Dem_Cfg_EnableConditionGroup[Dem_Cfg_Num_Of_EnConGroup] =
{
    /*Mask */
    { 0x0000 },
    { 0x0000 }
};

const Dem_Cfg_EnableConditionType Dem_Cfg_EnableCondition[Dem_Cfg_Num_Of_EnCon] =
{
    /*Status */
    { 1 },
    { 1 }
};

const Dem_Cfg_StorageConditionGroupType Dem_Cfg_StorageConditionGroup[Dem_Cfg_Num_Of_StrConGroup] =
{
    /*Mask */
    { 0x0000 },
    { 0x0000 }
};

const Dem_Cfg_StorageConditionType Dem_Cfg_StorageCondition[Dem_Cfg_Num_Of_StrCon] =
{
    /*Status */
    { 1 },
    { 1 }
};

//Dem Testing /*** Event  ***/

/***  DTC  ***/

const Dem_Cfg_DTCType Dem_Cfg_DTC[Dem_Cfg_Num_Of_DTC + 1] =
{
/* Index    Dtc Value                  DTC Attribute Ref                  Sess Ref   Severity   FunctionalUnit   */
   { /*     0 */ 0x00FFFFFFuL,   0u,0x07,0xE0, 255 },
   { /*     1 */ 0x00C1AA00uL,   1u,0x07,0xE0, 255 },
   { /*     2 */ 0x0092FD54uL,   2u,0x07,0xE0, 255 },
   { /*     3 */ 0x0092FEF0uL,   3u,0x07,0xE0, 255 },
   { /*     4 */ 0x0092FFF0uL,   4u,0x07,0xE0, 255 },
   { /*     5 */ 0x0096A000uL,   5u,0x07,0xE0, 255 }

};



const Dem_Cfg_DTCAttributesType Dem_Cfg_DTCAttributes[Dem_Cfg_Num_Of_DTC + 1] =
{
/* Index  AgingThershold  AgingOpCycleRef ExtDataRecordContainerRef FreezeFrameRecNumClassRef ImmediateNvStorageAllowed AgingAllowed ExtDataRecordSupported FreezeFrameRecordSupported WIR_Supported*/
    { /*     0 0x00FFFFFFuL */  255u,   Dem_CfgDemOperationCycle_Ignition,   3u,   0u,  FALSE,  FALSE,  FALSE,  FALSE, FALSE },
    { /*     1 0x00C1AA00uL */   40u,   Dem_CfgDemOperationCycle_Ignition,   2u,   0u,  TRUE,   TRUE,   TRUE,   FALSE, FALSE },
    { /*     2 0x0092FD54uL */   40u,   Dem_CfgDemOperationCycle_Ignition,   2u,   0u,  TRUE,   FALSE,   TRUE,   FALSE, TRUE  },
    { /*     3 0x0092FEF0uL */  255u,   Dem_CfgDemOperationCycle_Ignition,   2u,   0u,  TRUE,   FALSE,  TRUE,   FALSE, FALSE },
    { /*     4 0x0092FFF0uL */  255u,   Dem_CfgDemOperationCycle_Ignition,   2u,   0u,  TRUE,   FALSE,  TRUE,   FALSE, FALSE },
    { /*     5 0x0096A000uL */  255u,   Dem_CfgDemOperationCycle_Ignition,   2u,   0u,  TRUE,   FALSE,  TRUE,   FALSE, FALSE }
};


/*** Call Back To Get Fdc ***/

const Dem_Cfg_CallBackGetFdcType Dem_Cfg_CallBackGetFdc[Dem_Cfg_Num_Of_CBGetFdc] =
{

};

const Dem_Cfg_CBClearEventAllowedType Dem_Cfg_CBClearEvent[Dem_Cfg_Num_Of_CBClrEvtAlwd] =
{

};

const Dem_Cfg_ClientType Dem_Cfg_Client[Dem_Cfg_Num_Of_Clients] = 
{
    {DEM_CLIENT_USES_FULL_FUNCTIONALITY, DEM_DCM_CLIENT, FALSE},   //Reserved only for Dcm
	{DEM_CLIENT_ONLY_USES_EVENTOVERFLOW_INTERFACE, DEM_APP_CLIENT, FALSE}
};

/*** Event  ***/
const Dem_Cfg_EventParameterType Dem_Cfg_EventParameter[Dem_Cfg_Num_Of_Event] =
/* Index CB_InitMForE, Event ID, EventKind, FDCThershold, Debounce TabRef, OpCycleRef, DTC TabRef, EnCntgrpRef, StrCntgrpRef, CallBackGetFdc, Available Status, CBClearEventAllowed, Priority  */
{
    { /*  0 */  ((void *) 0), DemConf_DemEventParameter_INVALID,  DEM_CFG_EVENT_KIND_BSW,    255,    3u, Dem_CfgDemOperationCycle_Ignition,   0u,  DEM_DTC_ORIGIN_PRIMARY_MEMORY, 7u,   0u,   1,  1,   TRUE,  0  , 0},
    { /*  1 */  ((void *) 0), DemConf_DemEventParameter_DATA_BUS_DEFECT_CLASS,       DEM_CFG_EVENT_KIND_BSW,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   1u,   DEM_DTC_ORIGIN_PRIMARY_MEMORY,   0u,   0,  1,   TRUE,  2 ,0 },
    { /*  2 */  ((void *) 0), DemConf_DemEventParameter_IMMO_NO_BASIC_SETTING_CLASS, DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   2u,   DEM_DTC_ORIGIN_PRIMARY_MEMORY,   0u,   0,  1,   TRUE,  1,0  },
    { /*  3 */  ((void *) 0), DemConf_DemEventParameter_IMMO_ENGINE_ECU2_CLASS,      DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   3u,   DEM_DTC_ORIGIN_PRIMARY_MEMORY,   0u,   0,  1,   TRUE,  1,0  },
    { /*  4 */  ((void *) 0), DemConf_DemEventParameter_IMMO_ENGINE_ECU3_CLASS,      DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   4u,   DEM_DTC_ORIGIN_PRIMARY_MEMORY,   0u,   0,  1,   TRUE,  1,0  },
    { /*  5 */  ((void *) 0), DemConf_DemEventParameter_IMMO_DEVMODEACT_CLASS,       DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   5u,   DEM_DTC_ORIGIN_PRIMARY_MEMORY,   0u,   0,  1,   TRUE,  2,0 }
};

const Dem_Cfg_DebounceTableType Dem_Cfg_DebounceTable[Dem_Cfg_Num_Of_DebounceTable] =
{
	/* Index  F.Td    P.Td  FT.Td  PT.Td   Dec-Stp  Inc-Stp JmpUpVal JmpDwnVal  Algo  JmpUp Jmpdwn  Behavior*/
    { /* 0 */1, -1, 0,   0,   -1, 1, 1, 1, DEM_CFG_DEBOUNCETYPE_COUNTER, 1, 1, DEM_DEBOUNCE_FREEZE}
};

#if (DemMaxNumberFreezeFrameRecords > 0)

const DemDidClassType DemDidClass[DemMaxNumberFreezeFrameDID] =
/* Did, ExternalDataElementClassRef*/
{
    {0xFE00, 0x02},
    {0xFE01, 0x03},
    {0xFE02, 0x04},
    {0xFE03, 0x05},
    {0xFE04, 0x06}
};

const DemFreezeFrameClassType DemFreezeFrameClass[DemMaxNumberFreezeFrameRecords] =
/* NoOfDid, DidClassRef[DemMaxNumberFreezeFrameDIDPerFF]*/
{
    {0x01, {0x0, 0x0, 0x0, 0x0, 0x0}},
    {0x02, {0x1, 0x3, 0x0, 0x0, 0x0}},
    {0x05, {0x0, 0x1, 0x2, 0x3, 0x4}},
    {0x04, {0x2, 0x4, 0x0, 0x3, 0x0}}
};

const DemFreezeFrameRecordClassType DemFreezeFrameRecordClass[DemMaxNumberFreezeFrameRecords] =
/* Number, Trigger, Update, FreezeFrameClassRef*/
{
    {0x15, 0x0 /*Reserved*/, DEM_UPDATE_RECORD_YES, 0x0},
    {0x30, 0x0 /*Reserved*/, DEM_UPDATE_RECORD_YES, 0x1},
    {0x03, 0x0 /*Reserved*/, DEM_UPDATE_RECORD_YES, 0x2},
    {0x04, 0x0 /*Reserved*/, DEM_UPDATE_RECORD_YES, 0x3}
};

const DemFreezeFrameRecNumClassType DemFreezeFrameRecNumClass[DemMaxNumberFreezeFrameRecords] =
/* MaxNumberFreezeFrameRecords, FreezeFrameRecordClassRef[DemMaxNumberFreezeFrameRecords]*/
{
    {0x1, {0x0, 0x0, 0x0, 0x0}},
    {0x2, {0x0, 0x1, 0x0, 0x0}},
    {0x4, {0x0, 0x1, 0x2, 0x3}},
    {0x2, {0x2, 0x3, 0x0, 0x0}}
};

#endif


#if (DEM_NUM_OF_EXTENDEDRECORD > 0)
const DemExtDataRecordContainerType Dem_Cfg_ExtDataRecordContainer[DEM_NUM_OF_EXTENDEDRECORD_COMBINATION]=
{

    /* NoofExtdataRecord   DemExtendedDataRecordClassType Ref */
    {1,                     { 0 }}
};

const DemExtendedDataRecordClassType Dem_Cfg_ExtRecordParameter[DEM_NUM_OF_EXTENDEDRECORD]=
{
    /* DemExtDataRecordNumber   DemExtDataRecordTrigger    DemExtDataClassRef  DemExtDataRecordUpdate DemDataElementEnable */
    { 0x10,                 0x0/*Reserved*/, 0,  DEM_UPDATE_RECORD_YES, TRUE}
};

const DemExtendedDataClassType Dem_Cfg_ExtDataClass[DEM_NUM_OF_EXTENDEDRECORD] =
{
    {0, InternalDataElementClass}
};
const DemInternalDataElementClassType Dem_Cfg_InternalExtDataElement[DEM_NUM_OF_INTERNALRECORDDATA]=
{
    /*DemIntDataElementDataSize  DemInternalDataElement*/
    {0x2, DEM_EXTENDED_DATA_OCCCNTR}
};
#endif

#if ((DEM_NUM_OF_EXTENDEDRECORD > 0) || (DemMaxNumberFreezeFrameRecords > 0))
const DemExternalDataElementClassType Dem_Cfg_ExternalExtDataElement[DEM_NUM_OF_EXTERNALRECORDDATA]=
{
    /*DemDataElementDataSize  DemDataElementReadFnc*/
};
#endif
/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/

void Dem_EnterCriticalSection(void)
{
  SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_0();
}
void Dem_ExitCriticalSection(void)
{
  SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_0();
}

#if (DemDevErrorDetect == TRUE)
void Dem_Det_Error_register(uint8 p1, uint8 p2)
{
    Det_ReportError();
}
#endif

#endif
/*****************************************************************************
 *     End of File
 *
 *******************************************************************************/
/****************************************************************************
 *   for each change to this file, be sure to record:                        *
 *      1.  who made the change and when the change was made                 *
 *      2.  why the change was made and the intended result                  *
 *   Following block needs to be repeated for each change                    *
 *****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 15-Mar-2017                                            */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :                                                       */
/*Change Description: Data design And Framework , Initial Version */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 29-Aug-2020                                           */
/*Version           :                                                       */
/*By                : bbaskara                                              */
/*Traceability      : Rtc#1029668                                           */
/*Change Description: 0x19 0x06 service design changes                      */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 19-Sep-2020                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : Rtc#1046434                                           */
/*Change Description: 0x19 0x04 service design changes and defect fixes     */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 18-Jan-2022                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      : Rtc#1560389                                           */
/*Change Description: DCM and DEM Autosar 4.2.2 Migration                   */
/*--------------------------------------------------------------------------*/
