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
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_5;
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_6;
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_7;
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_8;
Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_9;



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
  (uint8*) &Dem_PrimaryEntry_4,
  (uint8*) &Dem_PrimaryEntry_5,
  (uint8*) &Dem_PrimaryEntry_6,
  (uint8*) &Dem_PrimaryEntry_7,
  (uint8*) &Dem_PrimaryEntry_8,
  (uint8*) &Dem_PrimaryEntry_9,  
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
  { Dem_CfgDemOperationCycle_Ignition, 0, 1, 0},
  { Dem_CfgDemOperationCycle_Aging, 0, 0, 0}
};

/*configured as per DTC Definition list */
const Dem_Cfg_EnableConditionGroupType Dem_Cfg_EnableConditionGroup[Dem_Cfg_Num_Of_EnConGroup] =
{
    /*Mask */
    { 0x0001 },  //Ignition
    { 0x0003 }   //Ignition , Startup
};

const Dem_Cfg_EnableConditionType Dem_Cfg_EnableCondition[Dem_Cfg_Num_Of_EnCon] =
{
    /*Status */
    { 1 },   //Ignition
    { 0 }    //Startup
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
            /*Index   Dtc Value        DTC Attribute Ref     Sess Ref         Severity   FunctionalUnit   */
        { /*  0  */ 0x00FFFFFFuL,    0u,                   0x07,            0xE0,      255 },          /* Reserved */
        { /*  1  */ 0x00900001uL,    1u,                   0x07,            0xE0,      255 },          /* Reserved */
        { /*  2  */ 0x0090F914uL,    2u,                   0x07,            0xE0,      255 },          /* DCC_FAIL */
        { /*  3  */ 0x0090F913uL,    3u,                   0x07,            0xE0,      255 },          /* ECC_FAULT */
        { /*  4  */ 0x0090F94FuL,    4u,                   0x07,            0xE0,      255 },          /* ECC_1BIT_ERROR */
        { /*  5  */ 0x0090F950uL,    5u,                   0x07,            0xE0,      255 },          /* ECC_2BIT_ERROR */
        { /*  6  */ 0x0090F915uL,    6u,                   0x07,            0xE0,      255 },          /* OCOC_FAIL */
        { /*  7  */ 0x0090F918uL,    7u,                   0x07,            0xE0,      255 },          /* POK_FAULT */
        { /*  8  */ 0x0090F920uL,    8u,                   0x07,            0xE0,      255 },          /* TIFS_SAFETY_CHECK_FWL_FAIL */
        { /*  9  */ 0x0090F70AuL,    9u,                   0x07,            0xE0,      255 },          /* BACKLIGHT_ERROR */
        { /* 10  */ 0x0090FC01uL,   10u,                   0x07,            0xE0,      255 },          /* POWER_ON_RESET */
        { /* 11  */ 0x0090F912uL,   11u,                   0x07,            0xE0,      255 },          /* POWER_SUPPLY_FAULT */
        { /* 12  */ 0x0090F93BuL,   12u,                   0x07,            0xE0,      255 },          /* EXT_WDG_RESET */
        { /* 13  */ 0x0090F93CuL,   13u,                   0x07,            0xE0,      255 },          /* EXT_WDG_COMM_ERROR */
        { /* 14  */ 0x0090F902uL,   14u,                   0x07,            0xE0,      255 },          /* WDGM_ALIVE_FAIL */
        { /* 15  */ 0x0090F951uL,   15u,                   0x07,            0xE0,      255 },          /* FLTM_PMIC_MAXRSTCOUNT_REACHED */
        { /* 16  */ 0x0090F941uL,   16u,                   0x07,            0xE0,      255 },          /* PMIC_ABIST_FAIL */
        { /* 17  */ 0x0090F94EuL,   17u,                   0x07,            0xE0,      255 },          /* FLTM_E_NVM_INTEGRITY_ERROR */
        { /* 18  */ 0x0090F945uL,   18u,                   0x07,            0xE0,      255 },          /* FLTM_BUCK1_OVUV */
        { /* 19  */ 0x0090F946uL,   19u,                   0x07,            0xE0,      255 },          /* FLTM_BUCK2_OVUV */
        { /* 20  */ 0x0090F947uL,   20u,                   0x07,            0xE0,      255 },          /* FLTM_BUCK3_OVUV */
        { /* 21  */ 0x0090F948uL,   21u,                   0x07,            0xE0,      255 },          /* FLTM_BUCK4_OVUV */
        { /* 22  */ 0x0090F949uL,   22u,                   0x07,            0xE0,      255 },          /* FLTM_LDO1_OVUV */
        { /* 23  */ 0x0090F94AuL,   23u,                   0x07,            0xE0,      255 },          /* FLTM_LDO2_OVUV */
        { /* 24  */ 0x0090F94BuL,   24u,                   0x07,            0xE0,      255 },          /* FLTM_LDO3_OVUV */
        { /* 25  */ 0x0090F94CuL,   25u,                   0x07,            0xE0,      255 },          /* FLTM_VVCA_OVUV */
        { /* 26  */ 0x0090F94DuL,   26u,                   0x07,            0xE0,      255 },          /* FLTM_VMON1_OVUV */
        { /* 27  */ 0x0090F91BuL,   27u,                   0x07,            0xE0,      255 },          /* FALSH_INTEGRITY_FAIL */
        { /* 28  */ 0x0090F940uL,   28u,                   0x07,            0xE0,      255 },          /* DMNMGR_GIPHEALTH_ERROR */
        { /* 29  */ 0x0090FC07uL,   29u,                   0x07,            0xE0,      255 },          /* SW_MAIN_WARMRSTz */
        { /* 30  */ 0x0090FAF8uL,   30u,                   0x07,            0xE0,      255 },          /* E_ARM_PREFETCH_ABORT_R5 */
        { /* 31  */ 0x0090FAF4uL,   31u,                   0x07,            0xE0,      255 },          /* E_ARM_DATA_ABORT */
        { /* 32  */ 0x0090FAF1uL,   32u,                   0x07,            0xE0,      255 },          /* E_ARM_UNDEFINED_INSTRUCTION */
        { /* 33  */ 0x0090FF07uL,   33u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_STATE */
        { /* 34  */ 0x0090FF02uL,   34u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_CALLLEVEL */
        { /* 35  */ 0x0090FF01uL,   35u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_ACCESS */
        { /* 36  */ 0x0090FF03uL,   36u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_ID */
        { /* 37  */ 0x0090FF04uL,   37u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_LIMIT */
        { /* 38  */ 0x0090FF05uL,   38u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_NOFUNC */
        { /* 39  */ 0x0090FF06uL,   39u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_RESOURCE */
        { /* 40  */ 0x0090FF08uL,   40u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_VALUE */
        { /* 41  */ 0x0090FF09uL,   41u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_SERVICEID */
        { /* 42  */ 0x0090FF0AuL,   42u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_ILLEGAL_ADDRESS */
        { /* 43  */ 0x0090FF0BuL,   43u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_MISSINGEND */
        { /* 44  */ 0x0090FF0CuL,   44u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_DISABLEDINT */
        { /* 45  */ 0x0090FF0DuL,   45u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_STACKFAULT */
        { /* 46  */ 0x0090FF0EuL,   46u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_PROTECTION_MEMORY */
        { /* 47  */ 0x0090FF0FuL,   47u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_PROTECTION_TIME */
        { /* 48  */ 0x0090FF10uL,   48u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_PROTECTION_ARRIVAL */
        { /* 49  */ 0x0090FF11uL,   49u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_PROTECTION_LOCKED */
        { /* 50  */ 0x0090FF12uL,   50u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_PROTECTION_EXCEPTION */
        { /* 51  */ 0x0090FF13uL,   51u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_INTERFERENCE_DEADLOCK */
        { /* 52  */ 0x0090FF14uL,   52u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_NESTING_DEADLOCK */
        { /* 53  */ 0x0090FF15uL,   53u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_SPINLOCK */
        { /* 54  */ 0x0090FF16uL,   54u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_CORE */
        { /* 55  */ 0x0090FF17uL,   55u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_PARAM_POINTER */
        { /* 56  */ 0x0090FF18uL,   56u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_SHUTDOWN */
        { /* 57  */ 0x0090FF19uL,   57u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_SYS_API_ERROR */
        { /* 58  */ 0x0090FF1AuL,   58u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_SYS_ASSERTION */
        { /* 59  */ 0x0090FF1BuL,   59u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_SYS_DISABLED */
        { /* 60  */ 0x0090FF1CuL,   60u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_SYS_NO_BARRIER_PARTICIPANT */
        { /* 61  */ 0x0090FF1DuL,   61u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY */
        { /* 62  */ 0x0090FF1EuL,   62u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_SYS_NO_NTFSTACK */
        { /* 63  */ 0x0090FF1FuL,   63u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_SYS_OVERFLOW */
        { /* 64  */ 0x0090FF20uL,   64u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_SYS_KILL_KERNEL_OBJ */
        { /* 65  */ 0x0090FF21uL,   65u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_SYS_NO_RESTARTTASK */
        { /* 66  */ 0x0090FF22uL,   66u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_SYS_CALL_NOT_ALLOWED */
        { /* 67  */ 0x0090FF23uL,   67u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_SYS_FUNCTION_UNAVAILABLE */
        { /* 68  */ 0x0090FF24uL,   68u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_SYS_PROTECTION_SYSCALL */
        { /* 69  */ 0x0090FF25uL,   69u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_SYS_PROTECTION_IRQ */
        { /* 70  */ 0x0090FF26uL,   70u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_SYS_OVERLOAD */
        { /* 71  */ 0x0090FF27uL,   71u,                   0x07,            0xE0,      255 },          /* FLTM_E_OS_SYS_CROSS_CORE_REQUESTED */
        { /* 72  */ 0x0090F901uL,   72u,                   0x07,            0xE0,      255 }           /* DET_ERROR */
};

const Dem_Cfg_DTCAttributesType Dem_Cfg_DTCAttributes[Dem_Cfg_Num_Of_DTC + 1] =
{
            /* Index, AgingThershold, AgingOpCycleRef, ExtDataRecordContainerRef, FreezeFrameRecNumClassRef, ImmediateNvStorageAllowed, AgingAllowed, ExtDataRecordSupported, FreezeFrameRecordSupported, WIR_Supported*/
        { /*  0  0x00FFFFFFuL */ 255u, Dem_CfgDemOperationCycle_Ignition, 3u, 0u, FALSE, FALSE, FALSE, FALSE, FALSE },     /* Reserved */
        { /*  1  0x00900001uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 2u, 0u, TRUE,  TRUE,  TRUE,  FALSE, FALSE },     /* Reserved */
        { /*  2  0x0090F914uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 2u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* DCC_FAIL */
        { /*  3  0x0090F913uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 2u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* ECC_FAULT */
        { /*  4  0x0090F94FuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* ECC_1BIT_ERROR */
        { /*  5  0x0090F950uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* ECC_2BIT_ERROR */
        { /*  6  0x0090F915uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 2u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* OCOC_FAIL */
        { /*  7  0x0090F918uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* POK_FAULT */
        { /*  8  0x0090F920uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* TIFS_SAFETY_CHECK_FWL_FAIL */
        { /*  9  0x0090F70AuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* BACKLIGHT_ERROR */
        { /* 10  0x0090FC01uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 2u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* POWER_ON_RESET */
        { /* 11  0x0090F912uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* POWER_SUPPLY_FAULT */
        { /* 12  0x0090F93BuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 2u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* EXT_WDG_RESET */
        { /* 13  0x0090F93CuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* EXT_WDG_COMM_ERROR */
        { /* 14  0x0090F902uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* WDGM_ALIVE_FAIL */
        { /* 15  0x0090F951uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_PMIC_MAXRSTCOUNT_REACHED */
        { /* 16  0x0090F941uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* PMIC_ABIST_FAIL */
        { /* 17  0x0090F94EuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_NVM_INTEGRITY_ERROR */
        { /* 18  0x0090F945uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_BUCK1_OVUV */
        { /* 19  0x0090F946uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_BUCK2_OVUV */
        { /* 20  0x0090F947uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_BUCK3_OVUV */
        { /* 21  0x0090F948uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_BUCK4_OVUV */
        { /* 22  0x0090F949uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_LDO1_OVUV */
        { /* 23  0x0090F94AuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_LDO2_OVUV */
        { /* 24  0x0090F94BuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_LDO3_OVUV */
        { /* 25  0x0090F94CuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_VVCA_OVUV */
        { /* 26  0x0090F94DuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_VMON1_OVUV */
        { /* 27  0x0090F91BuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FALSH_INTEGRITY_FAIL */
        { /* 28  0x0090F940uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* DMNMGR_GIPHEALTH_ERROR */
        { /* 29  0x0090FC07uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* SW_MAIN_WARMRSTz */
        { /* 30  0x0090FAF8uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* E_ARM_PREFETCH_ABORT_R5 */
        { /* 31  0x0090FAF4uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* E_ARM_DATA_ABORT */
        { /* 32  0x0090FAF1uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* E_ARM_UNDEFINED_INSTRUCTION */
        { /* 33  0x0090FF07uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_STATE */
        { /* 34  0x0090FF02uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_CALLLEVEL */
        { /* 35  0x0090FF01uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_ACCESS */
        { /* 36  0x0090FF03uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_ID */
        { /* 37  0x0090FF04uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_LIMIT */
        { /* 38  0x0090FF05uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_NOFUNC */
        { /* 39  0x0090FF06uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_RESOURCE */
        { /* 40  0x0090FF08uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_VALUE */
        { /* 41  0x0090FF09uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_SERVICEID */
        { /* 42  0x0090FF0AuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_ILLEGAL_ADDRESS */
        { /* 43  0x0090FF0BuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_MISSINGEND */
        { /* 44  0x0090FF0CuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_DISABLEDINT */
        { /* 45  0x0090FF0DuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_STACKFAULT */
        { /* 46  0x0090FF0EuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_PROTECTION_MEMORY */
        { /* 47  0x0090FF0FuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_PROTECTION_TIME */
        { /* 48  0x0090FF10uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_PROTECTION_ARRIVAL */
        { /* 49  0x0090FF11uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_PROTECTION_LOCKED */
        { /* 50  0x0090FF12uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_PROTECTION_EXCEPTION */
        { /* 51  0x0090FF13uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_INTERFERENCE_DEADLOCK */
        { /* 52  0x0090FF14uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_NESTING_DEADLOCK */
        { /* 53  0x0090FF15uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_SPINLOCK */
        { /* 54  0x0090FF16uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_CORE */
        { /* 55  0x0090FF17uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_PARAM_POINTER */
        { /* 56  0x0090FF18uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_SHUTDOWN */
        { /* 57  0x0090FF19uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_SYS_API_ERROR */
        { /* 58  0x0090FF1AuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_SYS_ASSERTION */
        { /* 59  0x0090FF1BuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_SYS_DISABLED */
        { /* 60  0x0090FF1CuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_SYS_NO_BARRIER_PARTICIPANT */
        { /* 61  0x0090FF1DuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY */
        { /* 62  0x0090FF1EuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_SYS_NO_NTFSTACK */
        { /* 63  0x0090FF1FuL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_SYS_OVERFLOW */
        { /* 64  0x0090FF20uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_SYS_KILL_KERNEL_OBJ */
        { /* 65  0x0090FF21uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_SYS_NO_RESTARTTASK */
        { /* 66  0x0090FF22uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_SYS_CALL_NOT_ALLOWED */
        { /* 67  0x0090FF23uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_SYS_FUNCTION_UNAVAILABLE */
        { /* 68  0x0090FF24uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_SYS_PROTECTION_SYSCALL */
        { /* 69  0x0090FF25uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_SYS_PROTECTION_IRQ */
        { /* 70  0x0090FF26uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_SYS_OVERLOAD */
        { /* 71  0x0090FF27uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  },     /* FLTM_E_OS_SYS_CROSS_CORE_REQUESTED */
        { /* 72  0x0090F901uL */ 10u, Dem_CfgDemOperationCycle_Ignition, 0u, 0u, TRUE,  TRUE, FALSE,  FALSE, FALSE  }      /* DET_ERROR */
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
    { /*  0 */  ((void *) 0), DemConf_DemEventParameter_INVALID,            DEM_CFG_EVENT_KIND_BSW,    255,    3u, Dem_CfgDemOperationCycle_Ignition,   0u,    0u,   7u,   0u,   1,  1,   TRUE,  0  },
    { /*  1 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter1, DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   1u,    1u,   0u,   0u,   0,  1,   TRUE,  1  },
    { /*  2 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter2, DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   2u,    1u,   0u,   0u,   0,  1,   TRUE,  2  },
    { /*  3 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter3, DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   3u,    1u,   0u,   0u,   0,  1,   TRUE,  3  },
    { /*  4 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter4, DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   4u,    1u,   0u,   0u,   0,  1,   TRUE,  4  },
    { /*  5 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter5, DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   5u,    1u,   0u,   0u,   0,  1,   TRUE,  5  },
    { /*  6 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter6, DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   6u,    1u,   0u,   0u,   0,  1,   TRUE,  6  },
    { /*  7 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter7, DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   7u,    1u,   0u,   0u,   0,  1,   TRUE,  7  },
    { /*  8 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter8, DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   8u,    1u,   0u,   0u,   0,  1,   TRUE,  8  },
    { /*  9 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter9, DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   9u,    1u,   0u,   0u,   0,  1,   TRUE,  9  },
    { /* 10 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter10,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   10u,   1u,   0u,   0u,   0,  1,   TRUE,  10  },
    { /* 11 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter11,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   11u,   1u,   0u,   0u,   0,  1,   TRUE,  11  },
    { /* 12 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter12,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   12u,   1u,   0u,   0u,   0,  1,   TRUE,  12  },
    { /* 13 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter13,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   13u,   1u,   0u,   0u,   0,  1,   TRUE,  13  },
    { /* 14 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter14,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   14u,   1u,   0u,   0u,   0,  1,   TRUE,  14  },
    { /* 15 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter15,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   15u,   1u,   0u,   0u,   0,  1,   TRUE,  15  },
    { /* 16 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter16,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   16u,   1u,   0u,   0u,   0,  1,   TRUE,  16  },
    { /* 17 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter17,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   17u,   1u,   0u,   0u,   0,  1,   TRUE,  17  },
    { /* 18 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter18,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   18u,   1u,   0u,   0u,   0,  1,   TRUE,  18  },
    { /* 19 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter19,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   19u,   1u,   0u,   0u,   0,  1,   TRUE,  19  },
    { /* 20 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter20,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   20u,   1u,   0u,   0u,   0,  1,   TRUE,  20  },
    { /* 21 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter21,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   21u,   1u,   0u,   0u,   0,  1,   TRUE,  21  },
    { /* 22 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter22,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   22u,   1u,   0u,   0u,   0,  1,   TRUE,  22  },
    { /* 23 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter23,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   23u,   1u,   0u,   0u,   0,  1,   TRUE,  23  },
    { /* 24 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter24,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   24u,   1u,   0u,   0u,   0,  1,   TRUE,  24  },
    { /* 25 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter25,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   25u,   1u,   0u,   0u,   0,  1,   TRUE,  25  },
    { /* 26 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter26,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   26u,   1u,   0u,   0u,   0,  1,   TRUE,  26  },
    { /* 27 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter27,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   27u,   1u,   0u,   0u,   0,  1,   TRUE,  27  },
    { /* 28 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter28,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   28u,   1u,   0u,   0u,   0,  1,   TRUE,  28  },
    { /* 29 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter29,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   29u,   1u,   0u,   0u,   0,  1,   TRUE,  29  },
    { /* 30 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter30,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   30u,   1u,   0u,   0u,   0,  1,   TRUE,  30  },
    { /* 31 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter31,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   31u,   1u,   0u,   0u,   0,  1,   TRUE,  31  },
    { /* 32 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter32,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   32u,   1u,   0u,   0u,   0,  1,   TRUE,  32  },
    { /* 33 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter33,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   33u,   1u,   0u,   0u,   0,  1,   TRUE,  33  },
    { /* 34 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter34,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   34u,   1u,   0u,   0u,   0,  1,   TRUE,  34  },
    { /* 35 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter35,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   35u,   1u,   0u,   0u,   0,  1,   TRUE,  35  },
    { /* 36 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter36,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   36u,   1u,   0u,   0u,   0,  1,   TRUE,  36  },
    { /* 37 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter37,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   37u,   1u,   0u,   0u,   0,  1,   TRUE,  37  },
    { /* 38 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter38,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   38u,   1u,   0u,   0u,   0,  1,   TRUE,  38  },
    { /* 39 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter39,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   39u,   1u,   0u,   0u,   0,  1,   TRUE,  39  },
    { /* 40 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter40,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   40u,   1u,   0u,   0u,   0,  1,   TRUE,  40  },
    { /* 41 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter41,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   41u,   1u,   0u,   0u,   0,  1,   TRUE,  41  },
    { /* 42 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter42,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   42u,   1u,   0u,   0u,   0,  1,   TRUE,  42  },
    { /* 43 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter43,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   43u,   1u,   0u,   0u,   0,  1,   TRUE,  43  },
    { /* 44 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter44,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   44u,   1u,   0u,   0u,   0,  1,   TRUE,  44  },
    { /* 45 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter45,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   45u,   1u,   0u,   0u,   0,  1,   TRUE,  45  },
    { /* 46 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter46,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   46u,   1u,   0u,   0u,   0,  1,   TRUE,  46  },
    { /* 47 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter47,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   47u,   1u,   0u,   0u,   0,  1,   TRUE,  47  },
    { /* 48 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter48,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   48u,   1u,   0u,   0u,   0,  1,   TRUE,  48  },
    { /* 49 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter49,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   49u,   1u,   0u,   0u,   0,  1,   TRUE,  49  },
    { /* 50 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter50,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   50u,   1u,   0u,   0u,   0,  1,   TRUE,  50  },
    { /* 51 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter51,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   51u,   1u,   0u,   0u,   0,  1,   TRUE,  51  },
    { /* 52 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter52,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   52u,   1u,   0u,   0u,   0,  1,   TRUE,  52  },
    { /* 53 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter53,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   53u,   1u,   0u,   0u,   0,  1,   TRUE,  53  },
    { /* 54 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter54,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   54u,   1u,   0u,   0u,   0,  1,   TRUE,  54  },
    { /* 55 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter55,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   55u,   1u,   0u,   0u,   0,  1,   TRUE,  55  },
    { /* 56 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter56,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   56u,   1u,   0u,   0u,   0,  1,   TRUE,  56  },
    { /* 57 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter57,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   57u,   1u,   0u,   0u,   0,  1,   TRUE,  57  },
    { /* 58 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter58,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   58u,   1u,   0u,   0u,   0,  1,   TRUE,  58  },
    { /* 59 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter59,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   59u,   1u,   0u,   0u,   0,  1,   TRUE,  59  },
    { /* 60 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter60,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   60u,   1u,   0u,   0u,   0,  1,   TRUE,  60  },
    { /* 61 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter61,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   61u,   1u,   0u,   0u,   0,  1,   TRUE,  61  },
    { /* 62 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter62,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   62u,   1u,   0u,   0u,   0,  1,   TRUE,  62  },
    { /* 63 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter63,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   63u,   1u,   0u,   0u,   0,  1,   TRUE,  63  },
    { /* 64 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter64,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   64u,   1u,   0u,   0u,   0,  1,   TRUE,  64  },
    { /* 65 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter65,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   65u,   1u,   0u,   0u,   0,  1,   TRUE,  65  },
    { /* 66 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter66,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   66u,   1u,   0u,   0u,   0,  1,   TRUE,  66  },
    { /* 67 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter67,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   67u,   1u,   0u,   0u,   0,  1,   TRUE,  67  },
    { /* 68 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter68,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   68u,   1u,   0u,   0u,   0,  1,   TRUE,  68  },
    { /* 69 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter69,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   69u,   1u,   0u,   0u,   0,  1,   TRUE,  69  },
    { /* 70 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter70,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   70u,   1u,   0u,   0u,   0,  1,   TRUE,  70  },
    { /* 71 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter71,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   71u,   1u,   0u,   0u,   0,  1,   TRUE,  71  },
    { /* 72 */  ((void *) 0), DemConf_DemEventParameter_DemEventParameter72,DEM_CFG_EVENT_KIND_SWC,    255,    0u, Dem_CfgDemOperationCycle_Ignition,   72u,   1u,   0u,   0u,   0,  1,   TRUE,  72  }
};

const Dem_Cfg_DebounceTableType Dem_Cfg_DebounceTable[Dem_Cfg_Num_Of_DebounceTable] =
{
	/* Index  F.Td    P.Td  FT.Td  PT.Td   Dec-Stp  Inc-Stp JmpUpVal JmpDwnVal  Algo  JmpUp Jmpdwn  Behavior*/
    { /* 0 */1, -1, 0,   0,   -1, 1, 1, 1, DEM_CFG_DEBOUNCETYPE_COUNTER, 1, 1, DEM_DEBOUNCE_FREEZE},
    { /* 1 */50, -50, 0,   0,   -1, 1, 1, 1, DEM_CFG_DEBOUNCETYPE_COUNTER, 1, 1, DEM_DEBOUNCE_FREEZE},
    { /* 2 */4, -4, 0,   0,   -1, 1, 1, 1, DEM_CFG_DEBOUNCETYPE_COUNTER, 1, 1, DEM_DEBOUNCE_FREEZE},
    { /* 3 */0, 0, 60,   -60,   -1, 1, 1, 1, DEM_CFG_DEBOUNCETYPE_TIMER, 1, 1, DEM_DEBOUNCE_FREEZE},
    { /* 4 */0, 0, 2,   -2,   -1, 1, 1, 1, DEM_CFG_DEBOUNCETYPE_TIMER, 1, 1, DEM_DEBOUNCE_RESET}
};

#if (DemMaxNumberFreezeFrameRecords > 0)

const DemDidClassType DemDidClass[DemMaxNumberFreezeFrameDID] =
/* Did, ExternalDataElementClassRef*/
{
    {0xFE00, 0x0},
    {0xFE01, 0x0},
    {0xFE02, 0x0},
    {0xFE03, 0x0},
    {0xFE04, 0x0}
};

const DemFreezeFrameClassType DemFreezeFrameClass[DemMaxNumberFreezeFrameRecords] =
/* NoOfDid, DidClassRef[DemMaxNumberFreezeFrameDIDPerFF]*/
{
    {0x01, {0x0, 0x0, 0x0, 0x0, 0x0}},
    {0x02, {0x1, 0x3, 0x0, 0x0, 0x0}},
    {0x05, {0x0, 0x1, 0x2, 0x3, 0x4}},
    {0x04, {0x2, 0x4, 0x0, 0x3, 0x0}}
};
#if(DemTypeofFreezeFrameRecordNumeration != DEM_FF_RECNUM_CALCULATED)
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
#endif


#if (DEM_NUM_OF_EXTENDEDRECORD > 0)
const DemExtDataRecordContainerType Dem_Cfg_ExtDataRecordContainer[DEM_NUM_OF_EXTENDEDRECORD_COMBINATION]=
{

    /* NoofExtdataRecord   DemExtendedDataRecordClassType Ref */
    {1,                     {0}}
};

const DemExtendedDataRecordClassType Dem_Cfg_ExtRecordParameter[DEM_NUM_OF_EXTENDEDRECORD]=
{
    /* DemExtDataRecordNumber   DemExtDataRecordTrigger    DemExtDataClassRef  DemExtDataRecordUpdate DemDataElementEnable */
    { 0x10,                 0x0/*Reserved*/, 0,  DEM_UPDATE_RECORD_YES, TRUE},
    { 0x10,                 0x0/*Reserved*/, 1,  DEM_UPDATE_RECORD_YES, TRUE}
};

const DemExtendedDataClassType Dem_Cfg_ExtDataClass[DEM_NUM_OF_EXTENDEDRECORD] =
{
    {0, InternalDataElementClass},
    {0, ExternalDataElementClass}
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
	 {0x8,   DemExt_Read41Data}
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
    //Det_ReportError();
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
