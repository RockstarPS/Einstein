/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2024 by Visteon Corporation.       All rights reserved.         
*                                                                                                                    
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                   
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve              
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States     
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,             
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its       
* rights under all copyright laws to protect this work as a published work, when appropriate.                        
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it   
* without the written authorization of Visteon Corporation.                                                          
********************************************************************************************************************/

/*******************************************************************************************************************
*    @file Dem_Cfg.h
*    @ingroup Dem Configuration
*    @brief This is Dem Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the Dem module.
*    Auto generated code in vAUTOSAR TOOL by PTHANDA1 at 2024-12-03 11:57:18.601310700
********************************************************************************************************************/

#ifndef DEM_CFG_H
#define DEM_CFG_H

/******************************************************************************
*                            Include files                                    *
******************************************************************************/
#include "Std_Types.h"
#include "Dem_Types.h"
#include "Rte_Dem_Type.h"

/*****************************************************************************
*  						 	 Version Information                             *
******************************************************************************/
/* Software Version */
#define DEM_CFG_SW_MAJOR_VERSION                            0U
#define DEM_CFG_SW_MINOR_VERSION                            0U
#define DEM_CFG_SW_PATCH_VERSION                            2U
/* Autosar Release */
#define DEM_CFG_AR_RELEASE_MAJOR_VERSION                    4U
#define DEM_CFG_AR_RELEASE_MINOR_VERSION                    3U
#define DEM_CFG_AR_RELEASE_REVISION_VERSION                 1U
/******************************************************************************
*                                 Macro Definitions                           *
*-----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the        *
* purpose of the macro.                                                       *
******************************************************************************/

#define Dem_Cfg_Num_Of_CBGetFdc                             2U
#define Dem_Cfg_Num_Of_OpCycle                              2U

#define Dem_Cfg_Num_Of_CBClrEvtAlwd                         1U

#define Dem_Cfg_Num_Of_CBDTCChange                          1U

#define Dem_Cfg_Num_Of_EnCon                                1U

#define Dem_Cfg_Num_Of_StrCon                               2U

#define Dem_Cfg_Num_Of_EnConGroup                           2U
		
#define Dem_Cfg_Num_Of_StrConGroup                          2U

#define Dem_Cfg_Num_Of_DTC                                  25U
#define Dem_Cfg_Num_Of_Event                                (Dem_Cfg_Num_Of_DTC+1)

#define Dem_Cfg_Num_Of_DebounceTable                        1U

/***  DEM NVM   ***/

#define Dem_Cfg_Mem_Entry_Start                             0U
#define Dem_Cfg_Mem_Admin_Index                             0U
#define Dem_Cfg_Mem_Status_Index                            0U
#define Dem_Cfg_Mem_Primary_Entry_Start                     0U
#define Dem_Cfg_Mem_Total_Primary_Entry                     25U
#define Dem_Cfg_Mem_Primary_Entry_Stop                      (Dem_Cfg_Mem_Total_Primary_Entry + 2)
#define Dem_Cfg_Mem_Total_Entry                             (Dem_Cfg_Mem_Total_Primary_Entry + 2)
#define DEM_USE_NVM                                         STD_OFF

/*
 * DEM => DCM
 */

#define DemTriggerDcmReports                                STD_ON
#define SeveritySuppotEnabled                               STD_OFF
#define SessionRefSupportEnabled                            STD_ON
#define ImmediateAgingAllowedSupported                      STD_ON
#define Priority_Supported                                  STD_ON

/*************  Dem_General Configuration ************************************/

/***  DemClearDTCBehavior ***/
#define DEM_CLRRESP_NONVOLATILE_FINISH                      FALSE
#define DEM_CLRRESP_NONVOLATILE_TRIGGER                     FALSE
#define DEM_CLRRESP_VOLATILE                                TRUE

#define DemDevErrorDetect                                   TRUE
#define DemDevAdditionalCoverityChecks                      TRUE


#define DemDtcStatusAvailabilityMask_Def                    0x09
#define DemDtcStatusAvailabilityMask_Fota                   0x00
#define DemDtcStatusAvailabilityMask                        0x09

#if (SeveritySuppotEnabled == STD_ON)
#define DemDTCSeverityMask                                  0x00
#endif

#define DemMaxNumberFreezeFrameRecords                      0x00
#if (DemMaxNumberFreezeFrameRecords > 0)
#define DemMaxLengthFreezeFrameData                         0x00
#define DemMaxNumberFreezeFrameDIDPerFF                     0x04
#define DemMaxNumberFreezeFrameDID                          0x04
#endif
		
#define DEM_NUM_OF_EXTENDEDRECORD                           0

#if (DEM_NUM_OF_EXTENDEDRECORD > 0)
#define DEM_MAX_LENGTH_OF_EXTENDEDRECORD                    0
#define DEM_MAX_NUM_OF_EXT_DATA_RECORD                      0
#define DEM_NUM_OF_EXTENDEDRECORD_COMBINATION               0
#define DEM_NUM_OF_INTERNALRECORDDATA                       0
#define DEM_CFG_EXTRECDATA_COUNTER_2BYTES                   STD_OFF
#define DEM_CFG_EXTRECDATA_EVENT_2BYTES                     STD_OFF
#endif

#if ((DEM_NUM_OF_EXTENDEDRECORD > 0) || (DemMaxNumberFreezeFrameRecords > 0))
#define DEM_NUM_OF_EXTERNALRECORDDATA                       0
#endif

#define DemEventMemoryEntryStorageTrigger                   DEM_TRIGGER_ON_TEST_FAILED

#define DemStatusBitHandlingTestFailedSinceLastClear        DEM_STATUS_BIT_NORMAL


#define DEM_OCCURRENCE_COUNTER_THRESHOLD                    255U

#if (Dem_Cfg_Num_Of_OpCycle > 16)
#error Max Number of Dem_Cfg_Num_Of_OpCycle exceeded !
#endif

#ifdef DEM_CFG_SUPPORT_EVENTAVAILABLE
#undef DEM_CFG_SUPPORT_EVENTAVAILABLE
#endif
#define DEM_CFG_SUPPORT_EVENTAVAILABLE                      FALSE

/*
 *  Dem Operation Cycle ID's
 */
#define Dem_CfgDemOperationCycle_Ignition                          0U
#define Dem_CfgDemOperationCycle_Power                             1U

//MACRO FOR dtc NUMBER DEFINITION
#define DTC_NUMBER_ALL_DTC                                  (0x00FFFFFFUL)
#define DTC_NUMBER_00900051                                 (0x00900051UL)
#define DTC_NUMBER_00900155                                 (0x00900155UL)
#define DTC_NUMBER_00900152                                 (0x00900152UL)
#define DTC_NUMBER_00900255                                 (0x00900255UL)
#define DTC_NUMBER_00900252                                 (0x00900252UL)
#define DTC_NUMBER_00900355                                 (0x00900355UL)
#define DTC_NUMBER_00900352                                 (0x00900352UL)
#define DTC_NUMBER_00900555                                 (0x00900555UL)
#define DTC_NUMBER_00900552                                 (0x00900552UL)
#define DTC_NUMBER_00900855                                 (0x00900855UL)
#define DTC_NUMBER_00900852                                 (0x00900852UL)
#define DTC_NUMBER_00901055                                 (0x00901055UL)
#define DTC_NUMBER_00901052                                 (0x00901052UL)
#define DTC_NUMBER_00902055                                 (0x00902055UL)
#define DTC_NUMBER_00902052                                 (0x00902052UL)
#define DTC_NUMBER_00904055                                 (0x00904055UL)
#define DTC_NUMBER_00904052                                 (0x00904052UL)
#define DTC_NUMBER_00900955                                 (0x00900955UL)
#define DTC_NUMBER_00900952                                 (0x00900952UL)
#define DTC_NUMBER_00909055                                 (0x00909055UL)
#define DTC_NUMBER_00909052                                 (0x00909052UL)
#define DTC_NUMBER_00A80000                                 (0x00A80000UL)
#define DTC_NUMBER_00A80100                                 (0x00A80100UL)
#define DTC_NUMBER_00909355                                 (0x00909355UL)
#define DTC_NUMBER_00909352                                 (0x00909352UL)


/*  Event IDs [symbolic name value] - sorted by name.
    See Dem_Cfg_EventTable[] for this list sorted by Ids.  */ 
/*MACRO FOR dtc NUMBER DEFINITION*/
#define DemConf_DemEventParameter_INVALID                   0U
#define DTC_NUMBER_00900051_EventParameter                  1U
#define DTC_NUMBER_00900155_EventParameter                  2U
#define DTC_NUMBER_00900152_EventParameter                  3U
#define DTC_NUMBER_00900255_EventParameter                  4U
#define DTC_NUMBER_00900252_EventParameter                  5U
#define DTC_NUMBER_00900355_EventParameter                  6U
#define DTC_NUMBER_00900352_EventParameter                  7U
#define DTC_NUMBER_00900555_EventParameter                  8U
#define DTC_NUMBER_00900552_EventParameter                  9U
#define DTC_NUMBER_00900855_EventParameter                  10U
#define DTC_NUMBER_00900852_EventParameter                  11U
#define DTC_NUMBER_00901055_EventParameter                  12U
#define DTC_NUMBER_00901052_EventParameter                  13U
#define DTC_NUMBER_00902055_EventParameter                  14U
#define DTC_NUMBER_00902052_EventParameter                  15U
#define DTC_NUMBER_00904055_EventParameter                  16U
#define DTC_NUMBER_00904052_EventParameter                  17U
#define DTC_NUMBER_00900955_EventParameter                  18U
#define DTC_NUMBER_00900952_EventParameter                  19U
#define DTC_NUMBER_00909055_EventParameter                  20U
#define DTC_NUMBER_00909052_EventParameter                  21U
#define DTC_NUMBER_00A80000_EventParameter                  22U
#define DTC_NUMBER_00A80100_EventParameter                  23U
#define DTC_NUMBER_00909355_EventParameter                  24U
#define DTC_NUMBER_00909352_EventParameter                  25U



#define Dem_DTCAttributesRef_INVALID                        0U
#define DIAG_SESSION_FOTA                       (0x42)
/******************************************************************************
*                                 Type Declarations                           *
******************************************************************************/

/******************************************************************************
*                                Globally  accessed Variable Declarations     *
*-----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info    *
* about the variable.                                                         *
* purpose, critical section, unit, and resolution                             *
******************************************************************************/

typedef struct
{
  uint32 TimeStamp;
  uint16 EventId;
  uint16 AgingCounter;
  uint16 OccurrenceCounter;
  uint16 FirstFailedCount;
  uint16 LastFailedCount;
#if (DemMaxNumberFreezeFrameRecords >0)
  uint8 SnapshotData[DemMaxNumberFreezeFrameRecords][DemMaxLengthFreezeFrameData];
  uint8 SnahpshotHeader;
#endif
#if (DEM_NUM_OF_EXTENDEDRECORD > 0)
  uint8 ExtendedDataRecord[DEM_NUM_OF_EXTENDEDRECORD][DEM_MAX_LENGTH_OF_EXTENDEDRECORD+1U]; /*Added 1 so index 0 will point to update status*/
#endif
} Dem_Cfg_PrimaryMemEntryType;

typedef struct
{
  uint16 FirstFailedEvent;
  uint16 FirstConfirmedEvent;
  uint16 RecentFailedEvent;
  uint16 RecentConfirmedEvent;
  uint8 EventStatus[Dem_Cfg_Num_Of_Event];
} Dem_Cfg_UdsStatusDataType;

typedef struct 
{
  uint16 ImplementationVersion;
  uint16 ConfigurationId;
  uint16 CycleCounter[ 2];
  uint8  MemoryOverflow; 
}Dem_Cfg_AdminDataType;

typedef struct
{
  uint16 Counter[Dem_Cfg_Num_Of_OpCycle];
  uint8 MagicFlag;
} Dem_Cfg_OpCycleType;

typedef struct
{
  uint8 Id;
  uint8 Type;
  boolean AutoStart;
  boolean AutoStop;
} Dem_Cfg_OpCycleStateType;

typedef struct
{
  boolean Status;
} Dem_Cfg_EnableConditionType;

typedef struct
{
  uint16 Mask;
} Dem_Cfg_EnableConditionGroupType;

typedef struct
{
  boolean Status;
} Dem_Cfg_StorageConditionType;

typedef struct
{
  uint16 Mask;
} Dem_Cfg_StorageConditionGroupType;

/*typedef struct
 {
 uint16 Number;
 } Dem_Cfg_NvRamBlockIdType;*/

typedef uint16 Dem_Cfg_NvRamBlockIdType;

typedef struct
{
  uint32 Value;
  uint8 AttrbsRef;
  #if (SessionRefSupportEnabled == STD_ON)
  	uint8 Sess_Ref;
  #endif
  #if (SeveritySuppotEnabled == STD_ON)
  	Dem_DTCSeverityType Severity;
  	uint8 DTCFunctionalUnit; 
  #endif
} Dem_Cfg_DTCType;

typedef struct
{
  uint8 AgingThershold;
  uint8 AgingOpCycleRef;
  uint8 ExtDataRecordContainerRef;
  uint8 FreezeFrameRecNumClassRef;
  boolean ImmediateNvStorageAllowed;
  boolean AgingAllowed;
  boolean ExtDataRecordSupported; /* Enable - TRUE, Disable - False */
  boolean FreezeFrameRecordSupported; /* Enable - TRUE, Disable - False */
  #if (ImmediateAgingAllowedSupported == STD_ON)
  boolean ImmediateAgingAllowed;
  #endif
  boolean WIR_Supported;/* Enable - TRUE, Disable - False */
} Dem_Cfg_DTCAttributesType;

typedef struct
{
  Std_ReturnType (*DemCallbackGetFdc)(sint8* Fdc);
}Dem_Cfg_CallBackGetFdcType;

typedef struct
{
  Std_ReturnType (*CBClearEventAllowedFunc)(boolean* ClearEventAllowed);
}Dem_Cfg_CBClearEventAllowedType;

typedef struct
{
  Std_ReturnType (*DtcChangeCallback_Func)(uint32 DTC,Dem_UdsStatusByteType DTCStatusOld,Dem_UdsStatusByteType DTCStatusNew);
}Dem_Cfg_CallBackDTCChange;

typedef struct
{
  Std_ReturnType (*DemCallbackInitMForE)(Dem_InitMonitorReasonType Reason);
  Dem_EventIdType Id;
  uint8 EventKind;
  uint8 FailureCycleCounterThershold;
  uint8 DebounceTableRef;
  uint8 OpCycleRef;
  uint8 DTCTableRef;
  uint8 EnableConditionGroupRef;
  uint8 StorageConditionGroupRef;
  uint8 CallBackGetFdcRef;
  uint8 CBClearEventAllowed;
  uint8 DtcChangeCallbackRef;
  boolean AvailableStatus;
  #if(Priority_Supported== STD_ON)
  uint8  Priority;
  #endif
} Dem_Cfg_EventParameterType;

typedef struct
{
  sint16 FailedThershold;
  sint16 PassedThershold;
  sint16 FailedTimeThershold;
  sint16 PassedTimeThershold;
  sint8 DecStepSize;
  sint8 IncStepSize;
  sint8 JumpUpValue;
  sint8 JumpDownValue;
  uint8 AlgoClass;
  boolean JumpUp;
  boolean JumpDown;
  boolean behavior;
} Dem_Cfg_DebounceTableType;

#if (DemMaxNumberFreezeFrameRecords > 0)

typedef struct
{
  uint16 Did;
  uint8 ExternalDataElementClassRef;
}DemDidClassType;

typedef struct
{
  uint8 NoOfDid;
  uint8 DidClassRef[DemMaxNumberFreezeFrameDIDPerFF];
}DemFreezeFrameClassType;

typedef struct
{
  uint8 Number;
  uint8 Trigger;
  uint8 Update;
  uint8 FreezeFrameClassRef;
}DemFreezeFrameRecordClassType;

typedef struct
{
  uint8 MaxNumberFreezeFrameRecords;
  uint8 FreezeFrameRecordClassRef[DemMaxNumberFreezeFrameRecords];
}DemFreezeFrameRecNumClassType;

#endif


#if ((DEM_NUM_OF_EXTENDEDRECORD > 0) || (DemMaxNumberFreezeFrameRecords > 0))

typedef enum
{
    DEM_UPDATE_RECORD_NO, DEM_UPDATE_RECORD_YES,
} DemExtendedDataRecordUpdateType;
#endif

#if (DEM_NUM_OF_EXTENDEDRECORD > 0)
typedef enum
{
    InternalDataElementClass, ExternalDataElementClass,
} DemDataType;

typedef enum
{
   	DEM_EXTENDED_DATA_INIT = 0x0,
   	DEM_EXTENDED_DTC_PRIORITY = 0x1,
   	DEM_EXTENDED_DATA_OCCCNTR = 0x1,
   	DEM_EXTENDED_DATA_AGINGCNTR = 0x2,
   	DEM_EXTENDED_DATA_CYCLES_SINCE_LAST_FAILED = 0x4,
   	DEM_EXTENDED_DATA_CYCLES_SINCE_FIRST_FAILED = 0x8,
   	DEM_EXTENDED_DATA_CYCLES_SINCE_FIRST_FAILED_EVENT = 0x10,
   	DEM_EXTENDED_DATA_CYCLES_SINCE_FIRST_CONFIRMED_EVENT = 0x20,
   	DEM_EXTENDED_DATA_RECENT_FAILED_EVENT = 0x40,
   	RECENT_CONFIRMED_EVENT = 0x80,
   	DEM_EXTENDED_DATA_OPERATION_CYCLES_COUNTER = 0x100,
   	DEM_EXTENDED_DATA_FDC = 0x200
} DemIntDataElementType;

typedef struct
{
    uint8 DemExtendedDataRecordNumber;
    uint8 DemExtendedDataRecordTrigger; /*DEM_TRIGGER_ON_CONFIRMED = 0x03, DEM_TRIGGER_ON_FDC_THRESHOLD =0x01,
     DEM_TRIGGER_ON_MIRROR =0x5, DEM_TRIGGER_ON_PASSED =0x4,
     DEM_TRIGGER_ON_PENDING,0x2,DEM_TRIGGER_ON_TEST_FAILED =0x0*/
    uint8 DemExtendedDataClassRef;
    DemExtendedDataRecordUpdateType DemExtendedDataRecordUpdate;
    boolean DemDataElementEnable; /* Enable - TRUE, Disable - False */
} DemExtendedDataRecordClassType;

typedef struct
{
    uint8 NoOfExtdataRecord;
    uint8 DemExtendedDataRecordClassTypeRef[DEM_MAX_NUM_OF_EXT_DATA_RECORD];
} DemExtDataRecordContainerType;

typedef struct
{
    uint8 DemDataElementRef;
    DemDataType DemDataElementType;
} DemExtendedDataClassType;

typedef struct
{
    uint8 DemIntDataElementDataSize;
    DemIntDataElementType DemInternalDataElement;
} DemInternalDataElementClassType;
#endif

#if ((DEM_NUM_OF_EXTENDEDRECORD > 0) || (DemMaxNumberFreezeFrameRecords > 0))
typedef struct
{
  uint8 DemDataElementDataSize;
  Std_ReturnType (*DemDataElementReadFnc)(Dem_EventIdType Event, uint8 *ExternalDataRecord);
} DemExternalDataElementClassType;
#endif

extern const Dem_Cfg_UdsStatusDataType Dem_Cfg_StatusDataInit;
extern const Dem_Cfg_OpCycleType Dem_Cfg_OpCycleInit;
extern const Dem_Cfg_PrimaryMemEntryType Dem_MemoryEntryInit;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_0;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_1;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_2;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_3;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_4;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_5;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_6;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_7;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_8;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_9;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_10;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_11;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_12;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_13;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_14;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_15;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_16;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_17;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_18;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_19;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_20;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_21;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_22;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_23;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_24;


extern const uint8* Dem_Cfg_MemPtr[Dem_Cfg_Mem_Total_Entry];
#if (DEM_USE_NVM == STD_ON) 
extern const Dem_Cfg_NvRamBlockIdType Dem_Cfg_Memory_BlockId[Dem_Cfg_Mem_Total_Entry];
#endif

extern Dem_Cfg_UdsStatusDataType Dem_Cfg_StatusData;
extern Dem_Cfg_AdminDataType Dem_Cfg_AdminData;
extern Dem_Cfg_OpCycleType Dem_Cfg_OpCycle;

extern const Dem_Cfg_OpCycleStateType Dem_Cfg_OpCycleState[Dem_Cfg_Num_Of_OpCycle];

extern const Dem_Cfg_EnableConditionType Dem_Cfg_EnableCondition[Dem_Cfg_Num_Of_EnCon];
extern const Dem_Cfg_StorageConditionType Dem_Cfg_StorageCondition[Dem_Cfg_Num_Of_StrCon];

extern const Dem_Cfg_EnableConditionGroupType Dem_Cfg_EnableConditionGroup[Dem_Cfg_Num_Of_EnConGroup];
extern const Dem_Cfg_StorageConditionGroupType Dem_Cfg_StorageConditionGroup[Dem_Cfg_Num_Of_StrConGroup];

/***  DTC  ***/
extern const Dem_Cfg_DTCType Dem_Cfg_DTC[Dem_Cfg_Num_Of_DTC + 1];
extern const Dem_Cfg_DTCAttributesType Dem_Cfg_DTCAttributes[Dem_Cfg_Num_Of_DTC + 1];

/*** Event  ***/
extern const Dem_Cfg_CallBackGetFdcType Dem_Cfg_CallBackGetFdc[Dem_Cfg_Num_Of_CBGetFdc];
extern const Dem_Cfg_EventParameterType Dem_Cfg_EventParameter[Dem_Cfg_Num_Of_Event];
extern const Dem_Cfg_DebounceTableType Dem_Cfg_DebounceTable[Dem_Cfg_Num_Of_DebounceTable];

extern const Dem_Cfg_CBClearEventAllowedType Dem_Cfg_CBClearEvent[Dem_Cfg_Num_Of_CBClrEvtAlwd];

extern const Dem_Cfg_CallBackDTCChange Dem_Cfg_DtcChangeCallback[Dem_Cfg_Num_Of_CBDTCChange];

#if (DemMaxNumberFreezeFrameRecords > 0)

extern const DemDidClassType DemDidClass[DemMaxNumberFreezeFrameDID];
extern const DemFreezeFrameClassType DemFreezeFrameClass[DemMaxNumberFreezeFrameRecords];
extern const DemFreezeFrameRecordClassType DemFreezeFrameRecordClass[DemMaxNumberFreezeFrameRecords];
extern const DemFreezeFrameRecNumClassType DemFreezeFrameRecNumClass[DemMaxNumberFreezeFrameRecords];

#endif

#if (DEM_NUM_OF_EXTENDEDRECORD > 0)
extern const DemExtDataRecordContainerType Dem_Cfg_ExtDataRecordContainer[DEM_NUM_OF_EXTENDEDRECORD_COMBINATION];
extern const DemExtendedDataRecordClassType Dem_Cfg_ExtRecordParameter[DEM_NUM_OF_EXTENDEDRECORD];
extern const DemExtendedDataClassType Dem_Cfg_ExtDataClass[DEM_NUM_OF_EXTENDEDRECORD];
extern const DemInternalDataElementClassType Dem_Cfg_InternalExtDataElement[DEM_NUM_OF_INTERNALRECORDDATA];
#endif
#if ((DEM_NUM_OF_EXTENDEDRECORD > 0) || (DemMaxNumberFreezeFrameRecords > 0))
extern const DemExternalDataElementClassType Dem_Cfg_ExternalExtDataElement[DEM_NUM_OF_EXTERNALRECORDDATA];
#endif
/******************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/******************************************************************************
 *                   Functions                                                *
 ******************************************************************************/

extern void Dem_EnterCriticalSection(void);
extern void Dem_ExitCriticalSection(void);
#if (DemDevErrorDetect == TRUE)
extern void Dem_Det_Error_register(uint8 p1, uint8 p2);
#endif

#endif /* DEM_CFG_H */

/*****************************************************************************
 *   For each change to this file, be sure to record:                        *
 *      1.  who made the change and when the change was made.                *
 *      2.  why the change was made and the intended result.                 *
 *   Following block needs to be repeated for each change                    *
 *****************************************************************************/

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

