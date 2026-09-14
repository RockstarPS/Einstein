//*****Automatically Generated From NvM Configurator Tool*****

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "Std_Types.h"
#include "Srec_Gen_Cfg.h"
#include "NvM_Cfg.h"
#include "NvM_PrivateCfg.h"
#include "NvM.h"

#include "Nvm_Writer.h"
#include "Fls_Simulator.h"
#include "Mem_Cfg.h"
#include "SrecMake.h"
#include "Nvm_BlockLengthCalc.h"


static void Gen_MemCpy(uint8* dest, uint8* src, uint32 len);

static void NvmW_Write(uint32 BlockId);

static void Write_Magic_Flag_variant_1 (void);

static void Write_FBL_Validity_Flag_variant_1 (void);

static void Write_FBL_Switch_RoleBackFlag_variant_1 (void);

static void Write_FBL_OTA_Magic_Flag_variant_1 (void);

static void Write_FBL_FOTA_Status_variant_1 (void);

static void Write_Chimes_variant_1 (void);

static void Write_Config_variant_1 (void);

static void Write_Diagnostics_variant_1 (void);

static void Write_EOL_variant_1 (void);

static void Write_FuelGauge_variant_1 (void);

static void Write_Illumination_variant_1 (void);

static void Write_IOD_variant_1 (void);

static void Write_Odometer_variant_1 (void);

static void Write_TripComputer_variant_1 (void);

static void Write_Personalization_variant_1 (void);

static void Write_Health_Management_variant_1 (void);

static void Write_Health_Management2_variant_1 (void);

static void Write_Cybersecurity_variant_1 (void);

static void Write_GaugeFuel_variant_1 (void);

static void Write_FOTA_Signature_variant_1 (void);

static void Write_vSwUpdM_Appl_UpdateState_variant_1 (void);

static void Write_vSwUpdM_Appl_PartitionStates_variant_1 (void);

static void Write_vSwUpdM_Appl_PartitionValidities_variant_1 (void);

static void Write_vSwUpdM_Appl_PartitionRevisions_variant_1 (void);

static void Write_vSwUpdM_Appl_ModuleStates_variant_1 (void);

static void Write_vSwUpdM_Appl_ModuleValidities_variant_1 (void);

static void Write_vSwUpdM_Appl_ModuleRevisions_variant_1 (void);

static void Write_vSwUpdM_Appl_RegionStates_variant_1 (void);

static void Write_vSwUpdM_Appl_RegionEraseAddresses_variant_1 (void);

static void Write_vSwUpdM_Appl_SegmentAttributes_variant_1 (void);

static void Write_vSwUpdM_Appl_SegmentWriteAddresses_variant_1 (void);

static void Write_vSwUpdM_Appl_SegmentCount_variant_1 (void);

static void Write_vSwUpdM_Appl_ResumeInfo_variant_1 (void);

static void Write_vSwUpdM_Appl_RegionPartitionId_variant_1 (void);

static void Write_vSwUpdM_Appl_SegmentPartitionId_variant_1 (void);

static void Write_vSwUpdM_Appl_DiffModuleStates_variant_1 (void);

static void Write_vSwUpdM_Appl_DiffModuleValidities_variant_1 (void);

static void Write_vSwUpdM_Appl_DiffRegionStates_variant_1 (void);

static void Write_vSwUpdM_Appl_DiffRegionEraseAddresses_variant_1 (void);

static void Write_vSwUpdM_Appl_DiffSegmentAttributes_variant_1 (void);

static void Write_vSwUpdM_Appl_DiffSegmentWriteAddresses_variant_1 (void);

static void Write_vSwUpdM_Appl_DiffSegmentCount_variant_1 (void);

static void Write_CddOsoh_NvMData_variant_1 (void);

static void Write_CddOsph_CddOsphChannel_00_variant_1 (void);

static void Write_CddOsph_CddOsphChannel_01_variant_1 (void);

extern NV_Data_Magic_Flag Rte_NvBlockSwComponentType_NVBlockDescriptor_Magic_Flag;

extern NV_Data_FBL_Validity_Flag Rte_NvBlockSwComponentType_NVBlockDescriptor_FBL_Validity_Flag;

extern NV_Data_FBL_Switch_RoleBackFlag Rte_NvBlockSwComponentType_NVBlockDescriptor_FBL_Switch_RoleBackFlag;

extern NV_Data_FBL_OTA_Magic_Flag Rte_NvBlockSwComponentType_NVBlockDescriptor_FBL_OTA_Magic_Flag;

extern NV_Data_FBL_FOTA_Status Rte_NvBlockSwComponentType_NVBlockDescriptor_FBL_FOTA_Status;

extern NV_Data_Chimes Rte_NvBlockSwComponentType_NVBlockDescriptor_Chimes;

extern NV_Data_Config Rte_NvBlockSwComponentType_NVBlockDescriptor_Config;

extern NV_Data_Diagnostics Rte_NvBlockSwComponentType_NVBlockDescriptor_Diagnostics;

extern NV_Data_EOL Rte_NvBlockSwComponentType_NVBlockDescriptor_EOL;

extern NV_Data_FuelGauge Rte_NvBlockSwComponentType_NVBlockDescriptor_FuelGauge;

extern NV_Data_Illumination Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination;

extern NV_Data_IOD Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD;

extern NV_Data_Odometer Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer;

extern NV_Data_TripComputer Rte_NvBlockSwComponentType_NVBlockDescriptor_TripComputer;

extern NV_Data_Personalization Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization;

extern NV_Data_Health_Management Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management;

extern NV_Data_Health_Management2 Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2;

extern NV_Data_Cybersecurity Rte_NvBlockSwComponentType_NVBlockDescriptor_Cybersecurity;

extern NV_Data_GaugeFuel Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeFuel;

extern NV_Data_FOTA_Signature Rte_NvBlockSwComponentType_NVBlockDescriptor_FOTA_Signature;

extern NV_Data_vSwUpdM_Appl_UpdateState Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_UpdateState;

extern NV_Data_vSwUpdM_Appl_PartitionStates Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_PartitionStates;

extern NV_Data_vSwUpdM_Appl_PartitionValidities Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_PartitionValidities;

extern NV_Data_vSwUpdM_Appl_PartitionRevisions Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_PartitionRevisions;

extern NV_Data_vSwUpdM_Appl_ModuleStates Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_ModuleStates;

extern NV_Data_vSwUpdM_Appl_ModuleValidities Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_ModuleValidities;

extern NV_Data_vSwUpdM_Appl_ModuleRevisions Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_ModuleRevisions;

extern NV_Data_vSwUpdM_Appl_RegionStates Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_RegionStates;

extern NV_Data_vSwUpdM_Appl_RegionEraseAddresses Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_RegionEraseAddresses;

extern NV_Data_vSwUpdM_Appl_SegmentAttributes Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_SegmentAttributes;

extern NV_Data_vSwUpdM_Appl_SegmentWriteAddresses Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_SegmentWriteAddresses;

extern NV_Data_vSwUpdM_Appl_SegmentCount Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_SegmentCount;

extern NV_Data_vSwUpdM_Appl_ResumeInfo Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_ResumeInfo;

extern NV_Data_vSwUpdM_Appl_RegionPartitionId Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_RegionPartitionId;

extern NV_Data_vSwUpdM_Appl_SegmentPartitionId Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_SegmentPartitionId;

extern NV_Data_vSwUpdM_Appl_DiffModuleStates Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffModuleStates;

extern NV_Data_vSwUpdM_Appl_DiffModuleValidities Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffModuleValidities;

extern NV_Data_vSwUpdM_Appl_DiffRegionStates Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffRegionStates;

extern NV_Data_vSwUpdM_Appl_DiffRegionEraseAddresses Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffRegionEraseAddresses;

extern NV_Data_vSwUpdM_Appl_DiffSegmentAttributes Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffSegmentAttributes;

extern NV_Data_vSwUpdM_Appl_DiffSegmentWriteAddresses Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffSegmentWriteAddresses;

extern NV_Data_vSwUpdM_Appl_DiffSegmentCount Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffSegmentCount;

extern NV_Data_CddOsoh_NvMData Rte_NvBlockSwComponentType_NVBlockDescriptor_CddOsoh_NvMData;

extern NV_Data_CddOsph_CddOsphChannel_00 Rte_NvBlockSwComponentType_NVBlockDescriptor_CddOsph_CddOsphChannel_00;

extern NV_Data_CddOsph_CddOsphChannel_01 Rte_NvBlockSwComponentType_NVBlockDescriptor_CddOsph_CddOsphChannel_01;

Std_ReturnType Rte_Write_NV_Data_Magic_Flag_Magic_flag (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Magic_Flag.Magic_flag, (data), sizeof(uint32));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_FBL_Validity_Flag_FBL_Validity_Flag (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_FBL_Validity_Flag.FBL_Validity_Flag, (data), sizeof(t_uint8_x_8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_FBL_Switch_RoleBackFlag_FBL_Switch_RoleBackFlag (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_FBL_Switch_RoleBackFlag.FBL_Switch_RoleBackFlag, (data), sizeof(t_uint8_x_2));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_FBL_OTA_Magic_Flag_FBL_OTA_Magic_Flag (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_FBL_OTA_Magic_Flag.FBL_OTA_Magic_Flag, (data), sizeof(t_uint8_x_8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_FBL_FOTA_Status_FBL_FOTA_Status (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_FBL_FOTA_Status.FBL_FOTA_Status, (data), sizeof(t_uint8_x_4));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Chimes_l_chime_Vol_NVM_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Chimes.l_chime_Vol_NVM_U8A, (data), sizeof(t_uint8_x_163));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Chimes_NVM_TickTockSpdHysteresis_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Chimes.NVM_TickTockSpdHysteresis_U8, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Chimes_NVM_TickTockSpdOffset_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Chimes.NVM_TickTockSpdOffset_U8, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Chimes_NVM_TickTockSpdThrshld_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Chimes.NVM_TickTockSpdThrshld_U8, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Chimes_Reserved_Chimes (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Chimes.Reserved_Chimes, (data), sizeof(t_uint8_x_4));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops, (data), sizeof(t_uint8_x_258));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops1_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops1_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops2_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops2_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops3_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops3_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops4_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops4_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops5_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops5_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops6_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops6_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops7_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops7_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops8_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops8_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops9_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops9_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops10_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops10_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops11_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops11_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops12_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops12_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops13_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops13_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops14_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops14_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops15_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops15_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops16_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops16_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops17_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops17_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops18_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops18_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops19_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops19_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops20_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops20_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops21_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops21_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops22_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops22_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops23_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops23_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops24_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops24_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops25_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops25_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops26_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops26_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops27_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops27_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops28_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops28_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops29_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops29_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops30_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops30_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops31_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops31_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_cf_vops32_programmed (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.cf_vops32_programmed, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Config_Reserved_Config (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Config.Reserved_Config, (data), sizeof(t_uint8_x_12));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Diagnostics_mfc (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Diagnostics.mfc, (data), sizeof(t_uint8_x_24));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Diagnostics_nvm_dtc_status (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Diagnostics.nvm_dtc_status, (data), sizeof(t_uint8_x_55));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Diagnostics_dtcodes_counters (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Diagnostics.dtcodes_counters, (data), sizeof(t_uint8_x_120));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Diagnostics_NVM_Orig_VIN_Data_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Diagnostics.NVM_Orig_VIN_Data_U8, (data), sizeof(t_uint8_x_24));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Diagnostics_NVM_VIN1_Data_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Diagnostics.NVM_VIN1_Data_U8, (data), sizeof(t_uint8_x_24));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Diagnostics_NVM_VIN2_Data_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Diagnostics.NVM_VIN2_Data_U8, (data), sizeof(t_uint8_x_24));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Diagnostics_NVM_VIN3_Data_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Diagnostics.NVM_VIN3_Data_U8, (data), sizeof(t_uint8_x_24));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Diagnostics_NVM_VIN4_Data_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Diagnostics.NVM_VIN4_Data_U8, (data), sizeof(t_uint8_x_24));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Diagnostics_NVM_VIN_Dummy_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Diagnostics.NVM_VIN_Dummy_U8, (data), sizeof(t_uint8_x_4));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Diagnostics_mfg_mode_flag (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Diagnostics.mfg_mode_flag, (data), sizeof(t_uint16_x_2));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Diagnostics_mfg_mode_enabled (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Diagnostics.mfg_mode_enabled, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Diagnostics_mfg_gauge_rd_motor_pos_reached (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Diagnostics.mfg_gauge_rd_motor_pos_reached, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Diagnostics_mfg_gauge_ptr_plmt_pos_read (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Diagnostics.mfg_gauge_ptr_plmt_pos_read, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Diagnostics_mfg_gauge_ptr_plmt_auth_read (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Diagnostics.mfg_gauge_ptr_plmt_auth_read, (data), sizeof(t_uint8_x_12));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Diagnostics_Reserved_Diagnostics (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Diagnostics.Reserved_Diagnostics, (data), sizeof(t_uint8_x_120));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_EOL_end_item_part_number_nvm (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_EOL.end_item_part_number_nvm, (data), sizeof(t_uint8_x_24));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_EOL_hardware_part_number (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_EOL.hardware_part_number, (data), sizeof(t_uint8_x_24));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_EOL_manufacturing_row (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_EOL.manufacturing_row, (data), sizeof(T_NVM_MANUFACT));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_EOL_ecu_serial_number (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_EOL.ecu_serial_number, (data), sizeof(t_uint8_x_16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_EOL_nos_msg_db_ver_num (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_EOL.nos_msg_db_ver_num, (data), sizeof(t_uint8_x_4));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_EOL_eprmjmp (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_EOL.eprmjmp, (data), sizeof(t_uint8_x_3));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_EOL_nvm_peo (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_EOL.nvm_peo, (data), sizeof(T_NVM_PEO));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_EOL_nvm_manufact_FESN (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_EOL.nvm_manufact_FESN, (data), sizeof(t_uint8_x_8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_EOL_Reserved_EOL (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_EOL.Reserved_EOL, (data), sizeof(T_NVM_PEO));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_FuelGauge_fuel03_fault_snapshot_A_NVM (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_FuelGauge.fuel03_fault_snapshot_A_NVM, (data), sizeof(t_uint8_x_163));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_FuelGauge_fuel03_next_fault_log_to_write_NVM (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_FuelGauge.fuel03_next_fault_log_to_write_NVM, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_FuelGauge_Reserved_FuelGague (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_FuelGauge.Reserved_FuelGague, (data), sizeof(t_uint8_x_8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_ILLUM_AMT_SHIFT_A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_ILLUM_AMT_SHIFT_A, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_ILLUM_AMT_SHIFT_B (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_ILLUM_AMT_SHIFT_B, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_ILLUM_AMT_SHIFT_CD (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_ILLUM_AMT_SHIFT_CD, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_ILLUM_AMT_SHIFT_CU (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_ILLUM_AMT_SHIFT_CU, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_ILLUM_HIGH_PWM (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_ILLUM_HIGH_PWM, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_ILLUM_LOW_PWM (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_ILLUM_LOW_PWM, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_ILLUM_WEIGHT_FACTOR (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_ILLUM_WEIGHT_FACTOR, (data), sizeof(t_uint16_x_18x6));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_ILLUM_GAUGE_EPRNDL_WEIGHT_FACTOR (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_ILLUM_GAUGE_EPRNDL_WEIGHT_FACTOR, (data), sizeof(t_uint16_x_18x6));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_LOW_PWM_GG (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_LOW_PWM_GG, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_HIGH_PWM_GG (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_HIGH_PWM_GG, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_GREEN_NIGHT (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_GREEN_NIGHT, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_GREEN_DAY (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_GREEN_DAY, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_BLUE_NIGHT (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_BLUE_NIGHT, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_BLUE_DAY (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_BLUE_DAY, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_RED_NIGHT (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_RED_NIGHT, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_RED_DAY (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_RED_DAY, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_AMBER_NIGHT (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_AMBER_NIGHT, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_AMBER_DAY (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_AMBER_DAY, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_ORANGE_NIGHT (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_ORANGE_NIGHT, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_ORANGE_DAY (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_ORANGE_DAY, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_ILLUM_EPRNDL_WHITE_PWM_MATCH (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_ILLUM_EPRNDL_WHITE_PWM_MATCH, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_ILLUM_GG_WHITE_PWM_MATCH (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_ILLUM_GG_WHITE_PWM_MATCH, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_ILLUM_ICE_BLUE_POINTER_PWM_MATCH (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_ILLUM_ICE_BLUE_POINTER_PWM_MATCH, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_ILLUM_BLUE_TT_PWM_MATCH (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_ILLUM_BLUE_TT_PWM_MATCH, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_ILLUM_GREEN_TT_PWM_MATCH (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_ILLUM_GREEN_TT_PWM_MATCH, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_ILLUM_RED_TT_PWM_MATCH (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_ILLUM_RED_TT_PWM_MATCH, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_ILLUM_AMBER_TT_PWM_MATCH (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_ILLUM_AMBER_TT_PWM_MATCH, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_DID_ILLUM_EPRNDL_ORANGE_PWM_MATCH (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.DID_ILLUM_EPRNDL_ORANGE_PWM_MATCH, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Illumination_Reserved_Illumination (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination.Reserved_Illumination, (data), sizeof(t_uint8_x_124));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_IOD_EngineHours_U32 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_IOD_EngineHours_U32, (data), sizeof(uint32));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_IOD_EngineIdleHours_U32 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_IOD_EngineIdleHours_U32, (data), sizeof(uint32));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_EH_MIN_ACCUM_SPD_U16 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_EH_MIN_ACCUM_SPD_U16, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_EIH_MIN_ACCUM_SPD_U16 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_EIH_MIN_ACCUM_SPD_U16, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_EIH_MAX_ACCUM_SPD_10 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_EIH_MAX_ACCUM_SPD_10, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_PD_DECAY_FALLING_HI_TORQ_100 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_PD_DECAY_FALLING_HI_TORQ_100, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_PD_DECAY_FALLING_LO_TORQ_100 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_PD_DECAY_FALLING_LO_TORQ_100, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_PD_DECAY_FALLING_SWITCHPOINT (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_PD_DECAY_FALLING_SWITCHPOINT, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_PD_DECAY_RISING_10 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_PD_DECAY_RISING_10, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_PD_LINEARITY_FACTOR_10 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_PD_LINEARITY_FACTOR_10, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_PD_MAX_POWER (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_PD_MAX_POWER, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_PD_PERCENT_FILL_CONVERSION_100 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_PD_PERCENT_FILL_CONVERSION_100, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_PD_POWER_CONVERSION (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_PD_POWER_CONVERSION, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_PD_POWER_MULTIPLIER_100 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_PD_POWER_MULTIPLIER_100, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_PD_PRPLWHL_TQ_LOW_LIMIT_100 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_PD_PRPLWHL_TQ_LOW_LIMIT_100, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_PD_TORQUE_MAX (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_PD_TORQUE_MAX, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_PD_REAR_AXEL_RATIO_100 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_PD_REAR_AXEL_RATIO_100, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_PD_WHEEL_RPM_CONVERSION_100 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_PD_WHEEL_RPM_CONVERSION_100, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_NVM_PD_WHL_TRQ_FILTER_10 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.NVM_PD_WHL_TRQ_FILTER_10, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_IOD_Reserved_IOD (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD.Reserved_IOD, (data), sizeof(t_uint8_x_8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Odometer_nvm_odo_data (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer.nvm_odo_data, (data), sizeof(t_uint32_x_20));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Odometer_NVM_ODO_Delta_Ref_U32 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer.NVM_ODO_Delta_Ref_U32, (data), sizeof(t_uint32_x_4));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Odometer_NVM_ODO_Exceed_Cntr_U16 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer.NVM_ODO_Exceed_Cntr_U16, (data), sizeof(t_uint16_x_2));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Odometer_NVM_ODO_Exceed_Value_U32 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer.NVM_ODO_Exceed_Value_U32, (data), sizeof(t_uint32_x_4));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Odometer_NVM_PcmOdoTripSync_BOOL (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer.NVM_PcmOdoTripSync_BOOL, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Odometer_Reserved_Odo (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer.Reserved_Odo, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_TripComputer_NVM_AFE_BIAS_FACTOR_U16 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_TripComputer.NVM_AFE_BIAS_FACTOR_U16, (data), sizeof(t_uint16_x_2));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_TripComputer_NVM_TC_CONFIG_BYTE1 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_TripComputer.NVM_TC_CONFIG_BYTE1, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_TripComputer_NVM_TC_CONFIG_BYTE4 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_TripComputer.NVM_TC_CONFIG_BYTE4, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_TripComputer_trip_nvm_variable (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_TripComputer.trip_nvm_variable, (data), sizeof(t_uint32_x_29));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_TripComputer_Reserved_TripComputer (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_TripComputer.Reserved_TripComputer, (data), sizeof(t_uint8_x_4));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_McDoNotDisturbStatus_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_McDoNotDisturbStatus_U8, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_Mc911AssistStatus_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_Mc911AssistStatus_U8, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_McVolumeLimitStatus_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_McVolumeLimitStatus_U8, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_McAdvancedTracStatus_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_McAdvancedTracStatus_U8, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_McSpeedLimiterStatus_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_McSpeedLimiterStatus_U8, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_McSpeedWarningStatus_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_McSpeedWarningStatus_U8, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemCurrentPers_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemCurrentPers_U8, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemIPCPersRecallCount_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemIPCPersRecallCount_U8, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemPrevFEGallon_BOOL (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemPrevFEGallon_BOOL, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemPrevAFEMetric_BOOL (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemPrevAFEMetric_BOOL, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemPrevLangBundle_U16 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemPrevLangBundle_U16, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemDistUnit_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemDistUnit_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemTempUnit_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemTempUnit_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemLangSelect_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemLangSelect_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemVopsProgSts_BOOL (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemVopsProgSts_BOOL, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_StoredLanguage_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_StoredLanguage_U8, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_nvm_savedmk_startodo_1 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.nvm_savedmk_startodo_1, (data), sizeof(t_uint32_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_nvm_savedmk_accumodo_1 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.nvm_savedmk_accumodo_1, (data), sizeof(t_uint32_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_nvm_savedmk_startodo_2 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.nvm_savedmk_startodo_2, (data), sizeof(uint32));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_nvm_savedmk_accumodo_2 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.nvm_savedmk_accumodo_2, (data), sizeof(uint32));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemInfochime_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemInfochime_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemparkslotchime_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemparkslotchime_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemTpmsUnit_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemTpmsUnit_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemRpaAdjVolchime_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemRpaAdjVolchime_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemFpaAdjVolchime_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemFpaAdjVolchime_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_BrakeCoachMCStatus_BOOL (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_BrakeCoachMCStatus_BOOL, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemIpc_Configured_BOOL (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemIpc_Configured_BOOL, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemMyView_IODigital_Speedo (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemMyView_IODigital_Speedo, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemMyView_IOTrip_1 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemMyView_IOTrip_1, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemMyView_IOTrip_2 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemMyView_IOTrip_2, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemMyView_IODAS (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemMyView_IODAS, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemMyView_IODFuelEconomy (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemMyView_IODFuelEconomy, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemMyView_IODEco_Coach (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemMyView_IODEco_Coach, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemMyView_IODev_Coaching (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemMyView_IODev_Coaching, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemMyView_IODCalm (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemMyView_IODCalm, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemTurnByTurn_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemTurnByTurn_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemSpeedoGaugeView_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemSpeedoGaugeView_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemTachometer_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemTachometer_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemPowerGauge_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemPowerGauge_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemOilTemp_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemOilTemp_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemLeftGauge_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemLeftGauge_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemRightGauge_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemRightGauge_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemCalmScreenIOD_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemCalmScreenIOD_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemTrip1IOD_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemTrip1IOD_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemTrip2IOD_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemTrip2IOD_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemThisTripIOD_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemThisTripIOD_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemFuelEconomyIOD_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemFuelEconomyIOD_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemElectEffIOD_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemElectEffIOD_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemEcoBehaviorIOD_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemEcoBehaviorIOD_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemEVCoachIOD_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemEVCoachIOD_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemAutoStartStopIOD_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemAutoStartStopIOD_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemSeatbeltStatusIOD_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemSeatbeltStatusIOD_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemTPMSIOD_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemTPMSIOD_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemEcoCoachIOD_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemEcoCoachIOD_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemActiveMediaIOD_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemActiveMediaIOD_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemNavCompassIOD_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemNavCompassIOD_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemAverageSpeedIOD_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemAverageSpeedIOD_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemBatteryChargeIOD_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemBatteryChargeIOD_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemClassicViewIOD_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemClassicViewIOD_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemMapIOD_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemMapIOD_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_TMKClockReference_U32 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_TMKClockReference_U32, (data), sizeof(uint32));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_TMKElapsedTMK_U16 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_TMKElapsedTMK_U16, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_TMKWarningTime_U16 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_TMKWarningTime_U16, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_TMK12HrIncrements_U16 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_TMK12HrIncrements_U16, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_TMKExpirationTime_U16 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_TMKExpirationTime_U16, (data), sizeof(uint16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemTMK_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemTMK_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_TrailerBlind_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_TrailerBlind_U8A, (data), sizeof(t_uint8_x_4));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemEcoCoachNormalConfig_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemEcoCoachNormalConfig_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemEcoCoachConserveConfig_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemEcoCoachConserveConfig_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemEDMEcoAdvicesConfig_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemEDMEcoAdvicesConfig_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemEcoCoachGoModeConfig_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemEcoCoachGoModeConfig_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhMemEcoCoachEcoModeConfig_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhMemEcoCoachEcoModeConfig_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhTC1OdometerConfig_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhTC1OdometerConfig_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhTC2OdometerConfig_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhTC2OdometerConfig_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhTC1TimerConfig_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhTC1TimerConfig_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhTC2TimerConfig_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhTC2TimerConfig_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhTC1ASConfig_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhTC1ASConfig_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhTC2ASConfig_U8A1 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhTC2ASConfig_U8A1, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhTC1AFEConfig_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhTC1AFEConfig_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhTC2AFEConfig_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhTC2AFEConfig_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhTC1IFEConfig_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhTC1IFEConfig_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhTC2IFEConfig_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhTC2IFEConfig_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhTC1DTEConfig_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhTC1DTEConfig_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhTC2DTEConfig_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhTC2DTEConfig_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhTC1AEConfig_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhTC1AEConfig_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_NVM_EnhTC2AEConfig_U8A (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.NVM_EnhTC2AEConfig_U8A, (data), sizeof(t_uint8_x_5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Personalization_Reserved_Personalization (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization.Reserved_Personalization, (data), sizeof(t_uint8_x_4));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management_NVM_HM_dummy (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management.NVM_HM_dummy, (data), sizeof(t_uint8_x_30));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management_NVM_HM_Ign_Counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management.NVM_HM_Ign_Counter, (data), sizeof(uint32));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management_NVM_HM_Reset_Counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management.NVM_HM_Reset_Counter, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management_Reserved_Health_Management (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management.Reserved_Health_Management, (data), sizeof(t_uint8_x_160));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_Data_Illegal_Mem_Addrs_Reset_Counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_Data_Illegal_Mem_Addrs_Reset_Counter, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_Data_Range_Failure_Reset_Counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_Data_Range_Failure_Reset_Counter, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_DivbyZero_Excptn_Reset_Counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_DivbyZero_Excptn_Reset_Counter, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_ECU_Ign_UpTime (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_ECU_Ign_UpTime, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_ECU_Intrnl_Temp (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_ECU_Intrnl_Temp, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_Extrnl_Bus_Msg_Fault_Counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_Extrnl_Bus_Msg_Fault_Counter, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_Failure_Code (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_Failure_Code, (data), sizeof(HM_Failure_Code_Type));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_Flash_Checksum_Fault_Counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_Flash_Checksum_Fault_Counter, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_Illegal_Opcode_Reset_Counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_Illegal_Opcode_Reset_Counter, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_Intrnl_Bus_Msg_Fault_Counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_Intrnl_Bus_Msg_Fault_Counter, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_MainECU_Voltage (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_MainECU_Voltage, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_NVM_Checksum_Fault_Counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_NVM_Checksum_Fault_Counter, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_Peripheral_Fault_Counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_Peripheral_Fault_Counter, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_Power_ON_Reset_Counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_Power_ON_Reset_Counter, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_RAM_Checksum_Fault_Counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_RAM_Checksum_Fault_Counter, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_Reset_Reason_Detected_counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_Reset_Reason_Detected_counter, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_Sensor_Failure_Counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_Sensor_Failure_Counter, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_Stack_Ovrflw_Reset_Counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_Stack_Ovrflw_Reset_Counter, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_NVM_HM_WDT_Reset_Counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.NVM_HM_WDT_Reset_Counter, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_HM_Latest_Resets (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.HM_Latest_Resets, (data), sizeof(t_uint8_x_18x5));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_HM_Forced_Reset_Counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.HM_Forced_Reset_Counter, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_HM_Ignition_Counter (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.HM_Ignition_Counter, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_HM_TempSensorFault_Counters (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.HM_TempSensorFault_Counters, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Health_Management2_Reserved_HM2 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2.Reserved_HM2, (data), sizeof(t_uint8_x_40));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Cybersecurity_SPID_Data_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Cybersecurity.SPID_Data_U8, (data), sizeof(t_uint8_x_40));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Cybersecurity_FESN_Data_U8 (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Cybersecurity.FESN_Data_U8, (data), sizeof(t_uint8_x_8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Cybersecurity_TimerTimeOut (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Cybersecurity.TimerTimeOut, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_Cybersecurity_Reserved_Cybersecurity (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_Cybersecurity.Reserved_Cybersecurity, (data), sizeof(t_uint8_x_7));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_GaugeFuel_CorrectionTableX_Gauge_Fuel (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeFuel.CorrectionTableX_Gauge_Fuel, (data), sizeof(t_uint16_x_24));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_GaugeFuel_CorrectionTableY_Gauge_Fuel (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeFuel.CorrectionTableY_Gauge_Fuel, (data), sizeof(t_uint16_x_24));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_GaugeFuel_MagneticOffset_Gauge_Fuel (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeFuel.MagneticOffset_Gauge_Fuel, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_GaugeFuel_OverdriveOffset_Gauge_Fuel (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeFuel.OverdriveOffset_Gauge_Fuel, (data), sizeof(t_uint16_x_2));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_GaugeFuel_HysteresisDir_Gauge_Fuel (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeFuel.HysteresisDir_Gauge_Fuel, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_GaugeFuel_HysteresisAngle_Gauge_Fuel (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeFuel.HysteresisAngle_Gauge_Fuel, (data), sizeof(t_uint16_x_2));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_GaugeFuel_ZeroSW_Gauge_Fuel (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeFuel.ZeroSW_Gauge_Fuel, (data), sizeof(t_uint16_x_2));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_GaugeFuel_SleepOffset_Gauge_Fuel (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeFuel.SleepOffset_Gauge_Fuel, (data), sizeof(t_uint16_x_2));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_GaugeFuel_Reserved_GaugeFuel (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeFuel.Reserved_GaugeFuel, (data), sizeof(t_uint8_x_12));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_FOTA_Signature_FOTA_Signature (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_FOTA_Signature.FOTA_Signature, (data), sizeof(t_uint8_x_300));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_UpdateState_NvM_vSwUpdM_Appl_UpdateState (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_UpdateState.NvM_vSwUpdM_Appl_UpdateState, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_PartitionStates_NvM_vSwUpdM_Appl_PartitionStates (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_PartitionStates.NvM_vSwUpdM_Appl_PartitionStates, (data), sizeof(t_uint8_x_3));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_PartitionValidities_NvM_vSwUpdM_Appl_PartitionValidities (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_PartitionValidities.NvM_vSwUpdM_Appl_PartitionValidities, (data), sizeof(t_uint8_x_3));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_PartitionRevisions_NvM_vSwUpdM_Appl_PartitionRevisions (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_PartitionRevisions.NvM_vSwUpdM_Appl_PartitionRevisions, (data), sizeof(t_uint32_x_3));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_ModuleStates_NvM_vSwUpdM_Appl_ModuleStates (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_ModuleStates.NvM_vSwUpdM_Appl_ModuleStates, (data), sizeof(t_uint8_x_3x10));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_ModuleValidities_NvM_vSwUpdM_Appl_ModuleValidities (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_ModuleValidities.NvM_vSwUpdM_Appl_ModuleValidities, (data), sizeof(t_uint8_x_3x10));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_ModuleRevisions_NvM_vSwUpdM_Appl_ModuleRevisions (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_ModuleRevisions.NvM_vSwUpdM_Appl_ModuleRevisions, (data), sizeof(t_uint32_x_3x10));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_RegionStates_NvM_vSwUpdM_Appl_RegionStates (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_RegionStates.NvM_vSwUpdM_Appl_RegionStates, (data), sizeof(t_uint8_x_3x1));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_RegionEraseAddresses_NvM_vSwUpdM_Appl_RegionEraseAddresses (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_RegionEraseAddresses.NvM_vSwUpdM_Appl_RegionEraseAddresses, (data), sizeof(uint32));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_SegmentAttributes_NvM_vSwUpdM_Appl_SegmentAttributes (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_SegmentAttributes.NvM_vSwUpdM_Appl_SegmentAttributes, (data), sizeof(t_vSwUpdM_Segment_Attributes_x_10x16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_SegmentWriteAddresses_NvM_vSwUpdM_Appl_SegmentWriteAddresses (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_SegmentWriteAddresses.NvM_vSwUpdM_Appl_SegmentWriteAddresses, (data), sizeof(t_uint32_x_10x41));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_SegmentCount_NvM_vSwUpdM_Appl_SegmentCount (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_SegmentCount.NvM_vSwUpdM_Appl_SegmentCount, (data), sizeof(t_uint32_x_10));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_ResumeInfo_NvM_vSwUpdM_Appl_ResumeInfo (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_ResumeInfo.NvM_vSwUpdM_Appl_ResumeInfo, (data), sizeof(vSwUpdM_ResumeInfo));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_RegionPartitionId_NvM_vSwUpdM_Appl_RegionPartitionId (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_RegionPartitionId.NvM_vSwUpdM_Appl_RegionPartitionId, (data), sizeof(uint32));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_SegmentPartitionId_NvM_vSwUpdM_Appl_SegmentPartitionId (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_SegmentPartitionId.NvM_vSwUpdM_Appl_SegmentPartitionId, (data), sizeof(uint32));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_DiffModuleStates_NvM_vSwUpdM_Appl_DiffModuleStates (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffModuleStates.NvM_vSwUpdM_Appl_DiffModuleStates, (data), sizeof(t_uint8_x_10));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_DiffModuleValidities_NvM_vSwUpdM_Appl_DiffModuleValidities (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffModuleValidities.NvM_vSwUpdM_Appl_DiffModuleValidities, (data), sizeof(t_uint8_x_10));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_DiffRegionStates_NvM_vSwUpdM_Appl_DiffRegionStates (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffRegionStates.NvM_vSwUpdM_Appl_DiffRegionStates, (data), sizeof(uint8));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_DiffRegionEraseAddresses_NvM_vSwUpdM_Appl_DiffRegionEraseAddresses (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffRegionEraseAddresses.NvM_vSwUpdM_Appl_DiffRegionEraseAddresses, (data), sizeof(uint32));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_DiffSegmentAttributes_NvM_vSwUpdM_Appl_DiffSegmentAttributes (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffSegmentAttributes.NvM_vSwUpdM_Appl_DiffSegmentAttributes, (data), sizeof(t_vSwUpdM_Segment_Attributes_x_10x16));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_DiffSegmentWriteAddresses_NvM_vSwUpdM_Appl_DiffSegmentWriteAddresses (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffSegmentWriteAddresses.NvM_vSwUpdM_Appl_DiffSegmentWriteAddresses, (data), sizeof(t_uint32_x_10x41));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_vSwUpdM_Appl_DiffSegmentCount_NvM_vSwUpdM_Appl_DiffSegmentCount (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffSegmentCount.NvM_vSwUpdM_Appl_DiffSegmentCount, (data), sizeof(t_uint32_x_10));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_CddOsoh_NvMData_CddOsoh_NvMData (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_CddOsoh_NvMData.CddOsoh_NvMData, (data), sizeof(CddOsoh_NvMDataType));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_CddOsph_CddOsphChannel_00_CddOsphChannel_00_MessageState (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_CddOsph_CddOsphChannel_00.CddOsphChannel_00_MessageState, (data), sizeof(CddOsph_MessageStateType));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_CddOsph_CddOsphChannel_00_CddOsphChannel_00_ChannelState (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_CddOsph_CddOsphChannel_00.CddOsphChannel_00_ChannelState, (data), sizeof(CddOsph_ChannelStateType));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_CddOsph_CddOsphChannel_01_CddOsphChannel_01_MessageState (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_CddOsph_CddOsphChannel_01.CddOsphChannel_01_MessageState, (data), sizeof(CddOsph_MessageStateType));
	return E_OK;
}

Std_ReturnType Rte_Write_NV_Data_CddOsph_CddOsphChannel_01_CddOsphChannel_01_ChannelState (uint8* data)
{
	Gen_MemCpy((uint8*) &Rte_NvBlockSwComponentType_NVBlockDescriptor_CddOsph_CddOsphChannel_01.CddOsphChannel_01_ChannelState, (data), sizeof(CddOsph_ChannelStateType));
	return E_OK;
}

uint32 Magic_flag_variant_1 = 0;

t_uint8_x_8 FBL_Validity_Flag_variant_1 = {0,0,0,0,0,0,0,0};

t_uint8_x_2 FBL_Switch_RoleBackFlag_variant_1 = {0,0};

t_uint8_x_8 FBL_OTA_Magic_Flag_variant_1 = {0,0,0,0,0,0,0,0};

t_uint8_x_4 FBL_FOTA_Status_variant_1 = {0,0,0,0};

t_uint8_x_163 l_chime_Vol_NVM_U8A_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint8 NVM_TickTockSpdHysteresis_U8_variant_1 = 1;

uint8 NVM_TickTockSpdOffset_U8_variant_1 = 8;

uint8 NVM_TickTockSpdThrshld_U8_variant_1 = 72;

t_uint8_x_4 Reserved_Chimes_variant_1 = {0,0,0,0};

t_uint8_x_258 cf_vops_variant_1 = {165,1,20,244,214,24,27,16,77,128,34,126,24,0,2,1,96,2,170,2,208,41,64,40,192,1,0,2,1,85,83,8,8,0,4,0,0,0,0,1,0,0,102,100,0,1,0,0,4,1,0,0,100,10,42,0,2,0,0,0,10,6,36,19,75,31,0,2,0,88,1,1,2,1,27,2,0,0,0,32,96,64,195,20,0,32,56,0,0,0,32,128,0,0,0,0,0,0,255,255,255,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,248,240,240,0,128,0,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint8 cf_vops1_programmed_variant_1 = 0;

uint8 cf_vops2_programmed_variant_1 = 0;

uint8 cf_vops3_programmed_variant_1 = 0;

uint8 cf_vops4_programmed_variant_1 = 0;

uint8 cf_vops5_programmed_variant_1 = 0;

uint8 cf_vops6_programmed_variant_1 = 0;

uint8 cf_vops7_programmed_variant_1 = 0;

uint8 cf_vops8_programmed_variant_1 = 0;

uint8 cf_vops9_programmed_variant_1 = 0;

uint8 cf_vops10_programmed_variant_1 = 0;

uint8 cf_vops11_programmed_variant_1 = 0;

uint8 cf_vops12_programmed_variant_1 = 0;

uint8 cf_vops13_programmed_variant_1 = 0;

uint8 cf_vops14_programmed_variant_1 = 0;

uint8 cf_vops15_programmed_variant_1 = 0;

uint8 cf_vops16_programmed_variant_1 = 0;

uint8 cf_vops17_programmed_variant_1 = 0;

uint8 cf_vops18_programmed_variant_1 = 0;

uint8 cf_vops19_programmed_variant_1 = 0;

uint8 cf_vops20_programmed_variant_1 = 0;

uint8 cf_vops21_programmed_variant_1 = 0;

uint8 cf_vops22_programmed_variant_1 = 0;

uint8 cf_vops23_programmed_variant_1 = 0;

uint8 cf_vops24_programmed_variant_1 = 0;

uint8 cf_vops25_programmed_variant_1 = 0;

uint8 cf_vops26_programmed_variant_1 = 0;

uint8 cf_vops27_programmed_variant_1 = 0;

uint8 cf_vops28_programmed_variant_1 = 0;

uint8 cf_vops29_programmed_variant_1 = 0;

uint8 cf_vops30_programmed_variant_1 = 0;

uint8 cf_vops31_programmed_variant_1 = 0;

uint8 cf_vops32_programmed_variant_1 = 0;

t_uint8_x_12 Reserved_Config_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0};

t_uint8_x_24 mfc_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

t_uint8_x_55 nvm_dtc_status_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

t_uint8_x_120 dtcodes_counters_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

t_uint8_x_24 NVM_Orig_VIN_Data_U8_variant_1 = {193,0,255,255,255,255,255,255,193,1,255,255,255,255,255,255,193,2,255,255,255,255,255,255};

t_uint8_x_24 NVM_VIN1_Data_U8_variant_1 = {193,0,255,255,255,255,255,255,193,1,255,255,255,255,255,255,193,2,255,255,255,255,255,255};

t_uint8_x_24 NVM_VIN2_Data_U8_variant_1 = {193,0,255,255,255,255,255,255,193,1,255,255,255,255,255,255,193,2,255,255,255,255,255,255};

t_uint8_x_24 NVM_VIN3_Data_U8_variant_1 = {193,0,255,255,255,255,255,255,193,1,255,255,255,255,255,255,193,2,255,255,255,255,255,255};

t_uint8_x_24 NVM_VIN4_Data_U8_variant_1 = {193,0,255,255,255,255,255,255,193,1,255,255,255,255,255,255,193,2,255,255,255,255,255,255};

t_uint8_x_4 NVM_VIN_Dummy_U8_variant_1 = {0,0,0,0};

t_uint16_x_2 mfg_mode_flag_variant_1 = {0,0};

uint8 mfg_mode_enabled_variant_1 = 0;

uint8 mfg_gauge_rd_motor_pos_reached_variant_1 = 0;

uint8 mfg_gauge_ptr_plmt_pos_read_variant_1 = 0;

t_uint8_x_12 mfg_gauge_ptr_plmt_auth_read_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0};

t_uint8_x_120 Reserved_Diagnostics_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

t_uint8_x_24 end_item_part_number_nvm_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

t_uint8_x_24 hardware_part_number_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

T_NVM_MANUFACT manufacturing_row_variant_1 = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

t_uint8_x_16 ecu_serial_number_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

t_uint8_x_4 nos_msg_db_ver_num_variant_1 = {0,0,0,0};

t_uint8_x_3 eprmjmp_variant_1 = {4,0,0};

T_NVM_PEO nvm_peo_variant_1 = {0,0,0,0,0,0,0,0,0,0,{0,0},{0,0},{0,0,0,0}};

t_uint8_x_8 nvm_manufact_FESN_variant_1 = {0,0,0,0,0,0,0,0};

T_NVM_PEO Reserved_EOL_variant_1 = {0,0,0,0,0,0,0,0,0,0,{0,0},{0,0},{0,0,0,0}};

t_uint8_x_163 fuel03_fault_snapshot_A_NVM_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint8 fuel03_next_fault_log_to_write_NVM_variant_1 = 0;

t_uint8_x_8 Reserved_FuelGague_variant_1 = {0,0,0,0,0,0,0,0};

uint8 DID_ILLUM_AMT_SHIFT_A_variant_1 = 1;

uint8 DID_ILLUM_AMT_SHIFT_B_variant_1 = 1;

uint8 DID_ILLUM_AMT_SHIFT_CD_variant_1 = 9;

uint8 DID_ILLUM_AMT_SHIFT_CU_variant_1 = 7;

uint16 DID_ILLUM_HIGH_PWM_variant_1 = 750;

uint16 DID_ILLUM_LOW_PWM_variant_1 = 4;

t_uint16_x_18x6 DID_ILLUM_WEIGHT_FACTOR_variant_1 = {{0,3,6,10,17,366},{3,5,10,15,23,366},{5,9,14,21,31,366},{10,14,21,30,42,366},{15,21,30,41,56,366},{23,31,42,56,74,366},{34,45,58,75,97,366},{49,63,80,101,127,366},{71,88,109,134,166,366},{101,122,148,179,216,366},{143,169,201,237,281,366},{201,234,271,315,366,366},{366,391,418,446,477,510},{418,447,479,512,548,586},{446,485,527,572,621,674},{477,526,580,639,704,775},{490,555,630,714,809,917},{510,586,674,775,891,1024}};

t_uint16_x_18x6 DID_ILLUM_GAUGE_EPRNDL_WEIGHT_FACTOR_variant_1 = {{0,19,43,75,119,335},{7,27,53,87,132,335},{16,37,64,100,147,335},{25,48,77,114,162,335},{36,60,90,129,178,335},{48,74,105,145,196,335},{61,89,122,164,215,335},{77,106,140,183,235,335},{94,124,161,204,257,335},{114,146,183,228,281,335},{136,169,208,254,307,335},{162,196,236,281,335,335},{335,361,389,419,451,486},{389,420,453,488,525,566},{419,459,503,551,602,658},{451,502,558,620,688,763},{464,533,611,699,799,911},{486,566,658,763,885,1024}};

uint16 DID_LOW_PWM_GG_variant_1 = 50;

uint16 DID_HIGH_PWM_GG_variant_1 = 1000;

uint16 DID_GREEN_NIGHT_variant_1 = 500;

uint16 DID_GREEN_DAY_variant_1 = 1000;

uint16 DID_BLUE_NIGHT_variant_1 = 400;

uint16 DID_BLUE_DAY_variant_1 = 1000;

uint16 DID_RED_NIGHT_variant_1 = 500;

uint16 DID_RED_DAY_variant_1 = 1000;

uint16 DID_AMBER_NIGHT_variant_1 = 500;

uint16 DID_AMBER_DAY_variant_1 = 1000;

uint16 DID_ORANGE_NIGHT_variant_1 = 300;

uint16 DID_ORANGE_DAY_variant_1 = 1000;

uint16 DID_ILLUM_EPRNDL_WHITE_PWM_MATCH_variant_1 = 1000;

uint16 DID_ILLUM_GG_WHITE_PWM_MATCH_variant_1 = 1000;

uint16 DID_ILLUM_ICE_BLUE_POINTER_PWM_MATCH_variant_1 = 1000;

uint16 DID_ILLUM_BLUE_TT_PWM_MATCH_variant_1 = 1000;

uint16 DID_ILLUM_GREEN_TT_PWM_MATCH_variant_1 = 1000;

uint16 DID_ILLUM_RED_TT_PWM_MATCH_variant_1 = 1000;

uint16 DID_ILLUM_AMBER_TT_PWM_MATCH_variant_1 = 1000;

uint16 DID_ILLUM_EPRNDL_ORANGE_PWM_MATCH_variant_1 = 1000;

t_uint8_x_124 Reserved_Illumination_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint32 NVM_IOD_EngineHours_U32_variant_1 = 0;

uint32 NVM_IOD_EngineIdleHours_U32_variant_1 = 0;

uint16 NVM_EH_MIN_ACCUM_SPD_U16_variant_1 = 100;

uint16 NVM_EIH_MIN_ACCUM_SPD_U16_variant_1 = 100;

uint8 NVM_EIH_MAX_ACCUM_SPD_10_variant_1 = 5;

uint8 NVM_PD_DECAY_FALLING_HI_TORQ_100_variant_1 = 60;

uint8 NVM_PD_DECAY_FALLING_LO_TORQ_100_variant_1 = 60;

uint16 NVM_PD_DECAY_FALLING_SWITCHPOINT_variant_1 = 500;

uint8 NVM_PD_DECAY_RISING_10_variant_1 = 10;

uint8 NVM_PD_LINEARITY_FACTOR_10_variant_1 = 6;

uint8 NVM_PD_MAX_POWER_variant_1 = 120;

uint8 NVM_PD_PERCENT_FILL_CONVERSION_100_variant_1 = 38;

uint16 NVM_PD_POWER_CONVERSION_variant_1 = 32000;

uint8 NVM_PD_POWER_MULTIPLIER_100_variant_1 = 100;

uint8 NVM_PD_PRPLWHL_TQ_LOW_LIMIT_100_variant_1 = 1;

uint16 NVM_PD_TORQUE_MAX_variant_1 = 4000;

uint16 NVM_PD_REAR_AXEL_RATIO_100_variant_1 = 373;

uint16 NVM_PD_WHEEL_RPM_CONVERSION_100_variant_1 = 664;

uint8 NVM_PD_WHL_TRQ_FILTER_10_variant_1 = 1;

t_uint8_x_8 Reserved_IOD_variant_1 = {1,1,1,1,1,1,1,1};

t_uint32_x_20 nvm_odo_data_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

t_uint32_x_4 NVM_ODO_Delta_Ref_U32_variant_1 = {0,0,0,0};

t_uint16_x_2 NVM_ODO_Exceed_Cntr_U16_variant_1 = {0,0};

t_uint32_x_4 NVM_ODO_Exceed_Value_U32_variant_1 = {0,0,0,0};

uint8 NVM_PcmOdoTripSync_BOOL_variant_1 = 0;

uint8 Reserved_Odo_variant_1 = 0;

t_uint16_x_2 NVM_AFE_BIAS_FACTOR_U16_variant_1 = {1000,1000};

uint8 NVM_TC_CONFIG_BYTE1_variant_1 = 0;

uint8 NVM_TC_CONFIG_BYTE4_variant_1 = 0;

t_uint32_x_29 trip_nvm_variable_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

t_uint8_x_4 Reserved_TripComputer_variant_1 = {0,0,0,0};

uint8 NVM_McDoNotDisturbStatus_U8_variant_1 = 0;

uint8 NVM_Mc911AssistStatus_U8_variant_1 = 0;

uint8 NVM_McVolumeLimitStatus_U8_variant_1 = 1;

uint8 NVM_McAdvancedTracStatus_U8_variant_1 = 0;

uint8 NVM_McSpeedLimiterStatus_U8_variant_1 = 4;

uint8 NVM_McSpeedWarningStatus_U8_variant_1 = 0;

uint8 NVM_EnhMemCurrentPers_U8_variant_1 = 0;

uint8 NVM_EnhMemIPCPersRecallCount_U8_variant_1 = 0;

uint8 NVM_EnhMemPrevFEGallon_BOOL_variant_1 = 0;

uint8 NVM_EnhMemPrevAFEMetric_BOOL_variant_1 = 0;

uint16 NVM_EnhMemPrevLangBundle_U16_variant_1 = 0;

t_uint8_x_5 NVM_EnhMemDistUnit_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemTempUnit_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemLangSelect_U8A_variant_1 = {3,3,3,3,3};

uint8 NVM_EnhMemVopsProgSts_BOOL_variant_1 = 0;

uint8 NVM_StoredLanguage_U8_variant_1 = 0;

t_uint32_x_5 nvm_savedmk_startodo_1_variant_1 = {0,0,0,0,0};

t_uint32_x_5 nvm_savedmk_accumodo_1_variant_1 = {0,0,0,0,0};

uint32 nvm_savedmk_startodo_2_variant_1 = 0;

uint32 nvm_savedmk_accumodo_2_variant_1 = 0;

t_uint8_x_5 NVM_EnhMemInfochime_U8A_variant_1 = {1,1,1,1,1};

t_uint8_x_5 NVM_EnhMemparkslotchime_U8A_variant_1 = {1,1,1,1,1};

t_uint8_x_5 NVM_EnhMemTpmsUnit_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemRpaAdjVolchime_U8A_variant_1 = {6,6,6,6,6};

t_uint8_x_5 NVM_EnhMemFpaAdjVolchime_U8A_variant_1 = {6,6,6,6,6};

uint8 NVM_BrakeCoachMCStatus_BOOL_variant_1 = 1;

uint8 NVM_EnhMemIpc_Configured_BOOL_variant_1 = 0;

uint8 NVM_EnhMemMyView_IODigital_Speedo_variant_1 = 1;

uint8 NVM_EnhMemMyView_IOTrip_1_variant_1 = 1;

uint8 NVM_EnhMemMyView_IOTrip_2_variant_1 = 0;

uint8 NVM_EnhMemMyView_IODAS_variant_1 = 1;

uint8 NVM_EnhMemMyView_IODFuelEconomy_variant_1 = 1;

uint8 NVM_EnhMemMyView_IODEco_Coach_variant_1 = 1;

uint8 NVM_EnhMemMyView_IODev_Coaching_variant_1 = 0;

uint8 NVM_EnhMemMyView_IODCalm_variant_1 = 1;

t_uint8_x_5 NVM_EnhMemTurnByTurn_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemSpeedoGaugeView_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemTachometer_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemPowerGauge_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemOilTemp_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemLeftGauge_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemRightGauge_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemCalmScreenIOD_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemTrip1IOD_U8A_variant_1 = {1,1,1,1,1};

t_uint8_x_5 NVM_EnhMemTrip2IOD_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemThisTripIOD_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemFuelEconomyIOD_U8A_variant_1 = {1,1,1,1,1};

t_uint8_x_5 NVM_EnhMemElectEffIOD_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemEcoBehaviorIOD_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemEVCoachIOD_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemAutoStartStopIOD_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemSeatbeltStatusIOD_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemTPMSIOD_U8A_variant_1 = {1,1,1,1,1};

t_uint8_x_5 NVM_EnhMemEcoCoachIOD_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemActiveMediaIOD_U8A_variant_1 = {1,1,1,1,1};

t_uint8_x_5 NVM_EnhMemNavCompassIOD_U8A_variant_1 = {1,1,1,1,1};

t_uint8_x_5 NVM_EnhMemAverageSpeedIOD_U8A_variant_1 = {1,1,1,1,1};

t_uint8_x_5 NVM_EnhMemBatteryChargeIOD_U8A_variant_1 = {1,1,1,1,1};

t_uint8_x_5 NVM_EnhMemClassicViewIOD_U8A_variant_1 = {1,1,1,1,1};

t_uint8_x_5 NVM_EnhMemMapIOD_U8A_variant_1 = {1,1,1,1,1};

uint32 NVM_TMKClockReference_U32_variant_1 = 0;

uint16 NVM_TMKElapsedTMK_U16_variant_1 = 0;

uint16 NVM_TMKWarningTime_U16_variant_1 = 3160;

uint16 NVM_TMK12HrIncrements_U16_variant_1 = 0;

uint16 NVM_TMKExpirationTime_U16_variant_1 = 3160;

t_uint8_x_5 NVM_EnhMemTMK_U8A_variant_1 = {3,3,3,3,3};

t_uint8_x_4 NVM_TrailerBlind_U8A_variant_1 = {0x7E,0x7E,0x7E,0x7E};

t_uint8_x_5 NVM_EnhMemEcoCoachNormalConfig_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemEcoCoachConserveConfig_U8A_variant_1 = {0x01,0x01,0x01,0x01,0x01};

t_uint8_x_5 NVM_EnhMemEDMEcoAdvicesConfig_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhMemEcoCoachGoModeConfig_U8A_variant_1 = {0x01,0x01,0x01,0x01,0x01};

t_uint8_x_5 NVM_EnhMemEcoCoachEcoModeConfig_U8A_variant_1 = {0x01,0x01,0x01,0x01,0x01};

t_uint8_x_5 NVM_EnhTC1OdometerConfig_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhTC2OdometerConfig_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhTC1TimerConfig_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhTC2TimerConfig_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhTC1ASConfig_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhTC2ASConfig_U8A1_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhTC1AFEConfig_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhTC2AFEConfig_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhTC1IFEConfig_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhTC2IFEConfig_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhTC1DTEConfig_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhTC2DTEConfig_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhTC1AEConfig_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_5 NVM_EnhTC2AEConfig_U8A_variant_1 = {0,0,0,0,0};

t_uint8_x_4 Reserved_Personalization_variant_1 = {0,0,0,0};

t_uint8_x_30 NVM_HM_dummy_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint32 NVM_HM_Ign_Counter_variant_1 = 0;

uint8 NVM_HM_Reset_Counter_variant_1 = 0;

t_uint8_x_160 Reserved_Health_Management_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint8 NVM_HM_Data_Illegal_Mem_Addrs_Reset_Counter_variant_1 = 0;

uint8 NVM_HM_Data_Range_Failure_Reset_Counter_variant_1 = 0;

uint8 NVM_HM_DivbyZero_Excptn_Reset_Counter_variant_1 = 0;

uint8 NVM_HM_ECU_Ign_UpTime_variant_1 = 0;

uint8 NVM_HM_ECU_Intrnl_Temp_variant_1 = 0;

uint8 NVM_HM_Extrnl_Bus_Msg_Fault_Counter_variant_1 = 0;

HM_Failure_Code_Type NVM_HM_Failure_Code_variant_1 = {0,0,{0,0,0,0},0};

uint8 NVM_HM_Flash_Checksum_Fault_Counter_variant_1 = 0;

uint8 NVM_HM_Illegal_Opcode_Reset_Counter_variant_1 = 0;

uint8 NVM_HM_Intrnl_Bus_Msg_Fault_Counter_variant_1 = 0;

uint8 NVM_HM_MainECU_Voltage_variant_1 = 0;

uint8 NVM_HM_NVM_Checksum_Fault_Counter_variant_1 = 0;

uint8 NVM_HM_Peripheral_Fault_Counter_variant_1 = 0;

uint8 NVM_HM_Power_ON_Reset_Counter_variant_1 = 0;

uint8 NVM_HM_RAM_Checksum_Fault_Counter_variant_1 = 0;

uint8 NVM_HM_Reset_Reason_Detected_counter_variant_1 = 0;

uint8 NVM_HM_Sensor_Failure_Counter_variant_1 = 0;

uint8 NVM_HM_Stack_Ovrflw_Reset_Counter_variant_1 = 0;

uint8 NVM_HM_WDT_Reset_Counter_variant_1 = 0;

t_uint8_x_18x5 HM_Latest_Resets_variant_1 = {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};

uint8 HM_Forced_Reset_Counter_variant_1 = 0;

uint8 HM_Ignition_Counter_variant_1 = 0;

uint8 HM_TempSensorFault_Counters_variant_1 = 0;

t_uint8_x_40 Reserved_HM2_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

t_uint8_x_40 SPID_Data_U8_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

t_uint8_x_8 FESN_Data_U8_variant_1 = {0,0,0,0,0,0,0,0};

uint8 TimerTimeOut_variant_1 = 0;

t_uint8_x_7 Reserved_Cybersecurity_variant_1 = {0,0,0,0,0,0,0};

t_uint16_x_24 CorrectionTableX_Gauge_Fuel_variant_1 = {0,64,768,1536,3072,6656,17920,32512,47360,61952,63488,64256,65408,65408,65408,0,0,0,0,0,0,0,0,0};

t_uint16_x_24 CorrectionTableY_Gauge_Fuel_variant_1 = {768,768,896,896,1280,2739,3993,6720,9433,12160,12544,12544,12544,12544,12544,0,0,0,0,0,0,0,0,0};

uint8 MagneticOffset_Gauge_Fuel_variant_1 = 0;

t_uint16_x_2 OverdriveOffset_Gauge_Fuel_variant_1 = {0,0};

uint8 HysteresisDir_Gauge_Fuel_variant_1 = 0;

t_uint16_x_2 HysteresisAngle_Gauge_Fuel_variant_1 = {0,0};

t_uint16_x_2 ZeroSW_Gauge_Fuel_variant_1 = {0,0};

t_uint16_x_2 SleepOffset_Gauge_Fuel_variant_1 = {0,0};

t_uint8_x_12 Reserved_GaugeFuel_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0};

t_uint8_x_300 FOTA_Signature_variant_1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint8 NvM_vSwUpdM_Appl_UpdateState_variant_1 = 0;

t_uint8_x_3 NvM_vSwUpdM_Appl_PartitionStates_variant_1 = {0,0,0};

t_uint8_x_3 NvM_vSwUpdM_Appl_PartitionValidities_variant_1 = {0,0,0};

t_uint32_x_3 NvM_vSwUpdM_Appl_PartitionRevisions_variant_1 = {0,0,0};

t_uint8_x_3x10 NvM_vSwUpdM_Appl_ModuleStates_variant_1 = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};

t_uint8_x_3x10 NvM_vSwUpdM_Appl_ModuleValidities_variant_1 = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};

t_uint32_x_3x10 NvM_vSwUpdM_Appl_ModuleRevisions_variant_1 = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};

t_uint8_x_3x1 NvM_vSwUpdM_Appl_RegionStates_variant_1 = {{0},{0},{0}};

uint32 NvM_vSwUpdM_Appl_RegionEraseAddresses_variant_1 = 0;

t_vSwUpdM_Segment_Attributes_x_10x16 NvM_vSwUpdM_Appl_SegmentAttributes_variant_1 = {{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}};

t_uint32_x_10x41 NvM_vSwUpdM_Appl_SegmentWriteAddresses_variant_1 = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

t_uint32_x_10 NvM_vSwUpdM_Appl_SegmentCount_variant_1 = {0,0,0,0,0,0,0,0,0,0};

vSwUpdM_ResumeInfo NvM_vSwUpdM_Appl_ResumeInfo_variant_1 = {0,0,0,0,0,0};

uint32 NvM_vSwUpdM_Appl_RegionPartitionId_variant_1 = 0;

uint32 NvM_vSwUpdM_Appl_SegmentPartitionId_variant_1 = 0;

t_uint8_x_10 NvM_vSwUpdM_Appl_DiffModuleStates_variant_1 = {0,0,0,0,0,0,0,0,0,0};

t_uint8_x_10 NvM_vSwUpdM_Appl_DiffModuleValidities_variant_1 = {0,0,0,0,0,0,0,0,0,0};

uint8 NvM_vSwUpdM_Appl_DiffRegionStates_variant_1 = 0;

uint32 NvM_vSwUpdM_Appl_DiffRegionEraseAddresses_variant_1 = 0;

t_vSwUpdM_Segment_Attributes_x_10x16 NvM_vSwUpdM_Appl_DiffSegmentAttributes_variant_1 = {{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}};

t_uint32_x_10x41 NvM_vSwUpdM_Appl_DiffSegmentWriteAddresses_variant_1 = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

t_uint32_x_10 NvM_vSwUpdM_Appl_DiffSegmentCount_variant_1 = {0,0,0,0,0,0,0,0,0,0};

CddOsoh_NvMDataType CddOsoh_NvMData_variant_1 = {0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

CddOsph_MessageStateType CddOsphChannel_00_MessageState_variant_1 = {{0,0,0},0,0,0,0,0,0};

CddOsph_ChannelStateType CddOsphChannel_00_ChannelState_variant_1 = {0,0};

CddOsph_MessageStateType CddOsphChannel_01_MessageState_variant_1 = {{0,0,0},0,0,0,0,0,0};

CddOsph_ChannelStateType CddOsphChannel_01_ChannelState_variant_1 = {0,0};

void Write_Magic_Flag_variant_1(void)
{
	Rte_Write_NV_Data_Magic_Flag_Magic_flag(&Magic_flag_variant_1);
}

void Write_FBL_Validity_Flag_variant_1(void)
{
	Rte_Write_NV_Data_FBL_Validity_Flag_FBL_Validity_Flag(&FBL_Validity_Flag_variant_1);
}

void Write_FBL_Switch_RoleBackFlag_variant_1(void)
{
	Rte_Write_NV_Data_FBL_Switch_RoleBackFlag_FBL_Switch_RoleBackFlag(&FBL_Switch_RoleBackFlag_variant_1);
}

void Write_FBL_OTA_Magic_Flag_variant_1(void)
{
	Rte_Write_NV_Data_FBL_OTA_Magic_Flag_FBL_OTA_Magic_Flag(&FBL_OTA_Magic_Flag_variant_1);
}

void Write_FBL_FOTA_Status_variant_1(void)
{
	Rte_Write_NV_Data_FBL_FOTA_Status_FBL_FOTA_Status(&FBL_FOTA_Status_variant_1);
}

void Write_Chimes_variant_1(void)
{
	Rte_Write_NV_Data_Chimes_l_chime_Vol_NVM_U8A(&l_chime_Vol_NVM_U8A_variant_1);
	Rte_Write_NV_Data_Chimes_NVM_TickTockSpdHysteresis_U8(&NVM_TickTockSpdHysteresis_U8_variant_1);
	Rte_Write_NV_Data_Chimes_NVM_TickTockSpdOffset_U8(&NVM_TickTockSpdOffset_U8_variant_1);
	Rte_Write_NV_Data_Chimes_NVM_TickTockSpdThrshld_U8(&NVM_TickTockSpdThrshld_U8_variant_1);
	Rte_Write_NV_Data_Chimes_Reserved_Chimes(&Reserved_Chimes_variant_1);
}

void Write_Config_variant_1(void)
{
	Rte_Write_NV_Data_Config_cf_vops(&cf_vops_variant_1);
	Rte_Write_NV_Data_Config_cf_vops1_programmed(&cf_vops1_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops2_programmed(&cf_vops2_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops3_programmed(&cf_vops3_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops4_programmed(&cf_vops4_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops5_programmed(&cf_vops5_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops6_programmed(&cf_vops6_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops7_programmed(&cf_vops7_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops8_programmed(&cf_vops8_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops9_programmed(&cf_vops9_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops10_programmed(&cf_vops10_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops11_programmed(&cf_vops11_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops12_programmed(&cf_vops12_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops13_programmed(&cf_vops13_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops14_programmed(&cf_vops14_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops15_programmed(&cf_vops15_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops16_programmed(&cf_vops16_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops17_programmed(&cf_vops17_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops18_programmed(&cf_vops18_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops19_programmed(&cf_vops19_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops20_programmed(&cf_vops20_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops21_programmed(&cf_vops21_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops22_programmed(&cf_vops22_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops23_programmed(&cf_vops23_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops24_programmed(&cf_vops24_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops25_programmed(&cf_vops25_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops26_programmed(&cf_vops26_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops27_programmed(&cf_vops27_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops28_programmed(&cf_vops28_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops29_programmed(&cf_vops29_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops30_programmed(&cf_vops30_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops31_programmed(&cf_vops31_programmed_variant_1);
	Rte_Write_NV_Data_Config_cf_vops32_programmed(&cf_vops32_programmed_variant_1);
	Rte_Write_NV_Data_Config_Reserved_Config(&Reserved_Config_variant_1);
}

void Write_Diagnostics_variant_1(void)
{
	Rte_Write_NV_Data_Diagnostics_mfc(&mfc_variant_1);
	Rte_Write_NV_Data_Diagnostics_nvm_dtc_status(&nvm_dtc_status_variant_1);
	Rte_Write_NV_Data_Diagnostics_dtcodes_counters(&dtcodes_counters_variant_1);
	Rte_Write_NV_Data_Diagnostics_NVM_Orig_VIN_Data_U8(&NVM_Orig_VIN_Data_U8_variant_1);
	Rte_Write_NV_Data_Diagnostics_NVM_VIN1_Data_U8(&NVM_VIN1_Data_U8_variant_1);
	Rte_Write_NV_Data_Diagnostics_NVM_VIN2_Data_U8(&NVM_VIN2_Data_U8_variant_1);
	Rte_Write_NV_Data_Diagnostics_NVM_VIN3_Data_U8(&NVM_VIN3_Data_U8_variant_1);
	Rte_Write_NV_Data_Diagnostics_NVM_VIN4_Data_U8(&NVM_VIN4_Data_U8_variant_1);
	Rte_Write_NV_Data_Diagnostics_NVM_VIN_Dummy_U8(&NVM_VIN_Dummy_U8_variant_1);
	Rte_Write_NV_Data_Diagnostics_mfg_mode_flag(&mfg_mode_flag_variant_1);
	Rte_Write_NV_Data_Diagnostics_mfg_mode_enabled(&mfg_mode_enabled_variant_1);
	Rte_Write_NV_Data_Diagnostics_mfg_gauge_rd_motor_pos_reached(&mfg_gauge_rd_motor_pos_reached_variant_1);
	Rte_Write_NV_Data_Diagnostics_mfg_gauge_ptr_plmt_pos_read(&mfg_gauge_ptr_plmt_pos_read_variant_1);
	Rte_Write_NV_Data_Diagnostics_mfg_gauge_ptr_plmt_auth_read(&mfg_gauge_ptr_plmt_auth_read_variant_1);
	Rte_Write_NV_Data_Diagnostics_Reserved_Diagnostics(&Reserved_Diagnostics_variant_1);
}

void Write_EOL_variant_1(void)
{
	Rte_Write_NV_Data_EOL_end_item_part_number_nvm(&end_item_part_number_nvm_variant_1);
	Rte_Write_NV_Data_EOL_hardware_part_number(&hardware_part_number_variant_1);
	Rte_Write_NV_Data_EOL_manufacturing_row(&manufacturing_row_variant_1);
	Rte_Write_NV_Data_EOL_ecu_serial_number(&ecu_serial_number_variant_1);
	Rte_Write_NV_Data_EOL_nos_msg_db_ver_num(&nos_msg_db_ver_num_variant_1);
	Rte_Write_NV_Data_EOL_eprmjmp(&eprmjmp_variant_1);
	Rte_Write_NV_Data_EOL_nvm_peo(&nvm_peo_variant_1);
	Rte_Write_NV_Data_EOL_nvm_manufact_FESN(&nvm_manufact_FESN_variant_1);
	Rte_Write_NV_Data_EOL_Reserved_EOL(&Reserved_EOL_variant_1);
}

void Write_FuelGauge_variant_1(void)
{
	Rte_Write_NV_Data_FuelGauge_fuel03_fault_snapshot_A_NVM(&fuel03_fault_snapshot_A_NVM_variant_1);
	Rte_Write_NV_Data_FuelGauge_fuel03_next_fault_log_to_write_NVM(&fuel03_next_fault_log_to_write_NVM_variant_1);
	Rte_Write_NV_Data_FuelGauge_Reserved_FuelGague(&Reserved_FuelGague_variant_1);
}

void Write_Illumination_variant_1(void)
{
	Rte_Write_NV_Data_Illumination_DID_ILLUM_AMT_SHIFT_A(&DID_ILLUM_AMT_SHIFT_A_variant_1);
	Rte_Write_NV_Data_Illumination_DID_ILLUM_AMT_SHIFT_B(&DID_ILLUM_AMT_SHIFT_B_variant_1);
	Rte_Write_NV_Data_Illumination_DID_ILLUM_AMT_SHIFT_CD(&DID_ILLUM_AMT_SHIFT_CD_variant_1);
	Rte_Write_NV_Data_Illumination_DID_ILLUM_AMT_SHIFT_CU(&DID_ILLUM_AMT_SHIFT_CU_variant_1);
	Rte_Write_NV_Data_Illumination_DID_ILLUM_HIGH_PWM(&DID_ILLUM_HIGH_PWM_variant_1);
	Rte_Write_NV_Data_Illumination_DID_ILLUM_LOW_PWM(&DID_ILLUM_LOW_PWM_variant_1);
	Rte_Write_NV_Data_Illumination_DID_ILLUM_WEIGHT_FACTOR(&DID_ILLUM_WEIGHT_FACTOR_variant_1);
	Rte_Write_NV_Data_Illumination_DID_ILLUM_GAUGE_EPRNDL_WEIGHT_FACTOR(&DID_ILLUM_GAUGE_EPRNDL_WEIGHT_FACTOR_variant_1);
	Rte_Write_NV_Data_Illumination_DID_LOW_PWM_GG(&DID_LOW_PWM_GG_variant_1);
	Rte_Write_NV_Data_Illumination_DID_HIGH_PWM_GG(&DID_HIGH_PWM_GG_variant_1);
	Rte_Write_NV_Data_Illumination_DID_GREEN_NIGHT(&DID_GREEN_NIGHT_variant_1);
	Rte_Write_NV_Data_Illumination_DID_GREEN_DAY(&DID_GREEN_DAY_variant_1);
	Rte_Write_NV_Data_Illumination_DID_BLUE_NIGHT(&DID_BLUE_NIGHT_variant_1);
	Rte_Write_NV_Data_Illumination_DID_BLUE_DAY(&DID_BLUE_DAY_variant_1);
	Rte_Write_NV_Data_Illumination_DID_RED_NIGHT(&DID_RED_NIGHT_variant_1);
	Rte_Write_NV_Data_Illumination_DID_RED_DAY(&DID_RED_DAY_variant_1);
	Rte_Write_NV_Data_Illumination_DID_AMBER_NIGHT(&DID_AMBER_NIGHT_variant_1);
	Rte_Write_NV_Data_Illumination_DID_AMBER_DAY(&DID_AMBER_DAY_variant_1);
	Rte_Write_NV_Data_Illumination_DID_ORANGE_NIGHT(&DID_ORANGE_NIGHT_variant_1);
	Rte_Write_NV_Data_Illumination_DID_ORANGE_DAY(&DID_ORANGE_DAY_variant_1);
	Rte_Write_NV_Data_Illumination_DID_ILLUM_EPRNDL_WHITE_PWM_MATCH(&DID_ILLUM_EPRNDL_WHITE_PWM_MATCH_variant_1);
	Rte_Write_NV_Data_Illumination_DID_ILLUM_GG_WHITE_PWM_MATCH(&DID_ILLUM_GG_WHITE_PWM_MATCH_variant_1);
	Rte_Write_NV_Data_Illumination_DID_ILLUM_ICE_BLUE_POINTER_PWM_MATCH(&DID_ILLUM_ICE_BLUE_POINTER_PWM_MATCH_variant_1);
	Rte_Write_NV_Data_Illumination_DID_ILLUM_BLUE_TT_PWM_MATCH(&DID_ILLUM_BLUE_TT_PWM_MATCH_variant_1);
	Rte_Write_NV_Data_Illumination_DID_ILLUM_GREEN_TT_PWM_MATCH(&DID_ILLUM_GREEN_TT_PWM_MATCH_variant_1);
	Rte_Write_NV_Data_Illumination_DID_ILLUM_RED_TT_PWM_MATCH(&DID_ILLUM_RED_TT_PWM_MATCH_variant_1);
	Rte_Write_NV_Data_Illumination_DID_ILLUM_AMBER_TT_PWM_MATCH(&DID_ILLUM_AMBER_TT_PWM_MATCH_variant_1);
	Rte_Write_NV_Data_Illumination_DID_ILLUM_EPRNDL_ORANGE_PWM_MATCH(&DID_ILLUM_EPRNDL_ORANGE_PWM_MATCH_variant_1);
	Rte_Write_NV_Data_Illumination_Reserved_Illumination(&Reserved_Illumination_variant_1);
}

void Write_IOD_variant_1(void)
{
	Rte_Write_NV_Data_IOD_NVM_IOD_EngineHours_U32(&NVM_IOD_EngineHours_U32_variant_1);
	Rte_Write_NV_Data_IOD_NVM_IOD_EngineIdleHours_U32(&NVM_IOD_EngineIdleHours_U32_variant_1);
	Rte_Write_NV_Data_IOD_NVM_EH_MIN_ACCUM_SPD_U16(&NVM_EH_MIN_ACCUM_SPD_U16_variant_1);
	Rte_Write_NV_Data_IOD_NVM_EIH_MIN_ACCUM_SPD_U16(&NVM_EIH_MIN_ACCUM_SPD_U16_variant_1);
	Rte_Write_NV_Data_IOD_NVM_EIH_MAX_ACCUM_SPD_10(&NVM_EIH_MAX_ACCUM_SPD_10_variant_1);
	Rte_Write_NV_Data_IOD_NVM_PD_DECAY_FALLING_HI_TORQ_100(&NVM_PD_DECAY_FALLING_HI_TORQ_100_variant_1);
	Rte_Write_NV_Data_IOD_NVM_PD_DECAY_FALLING_LO_TORQ_100(&NVM_PD_DECAY_FALLING_LO_TORQ_100_variant_1);
	Rte_Write_NV_Data_IOD_NVM_PD_DECAY_FALLING_SWITCHPOINT(&NVM_PD_DECAY_FALLING_SWITCHPOINT_variant_1);
	Rte_Write_NV_Data_IOD_NVM_PD_DECAY_RISING_10(&NVM_PD_DECAY_RISING_10_variant_1);
	Rte_Write_NV_Data_IOD_NVM_PD_LINEARITY_FACTOR_10(&NVM_PD_LINEARITY_FACTOR_10_variant_1);
	Rte_Write_NV_Data_IOD_NVM_PD_MAX_POWER(&NVM_PD_MAX_POWER_variant_1);
	Rte_Write_NV_Data_IOD_NVM_PD_PERCENT_FILL_CONVERSION_100(&NVM_PD_PERCENT_FILL_CONVERSION_100_variant_1);
	Rte_Write_NV_Data_IOD_NVM_PD_POWER_CONVERSION(&NVM_PD_POWER_CONVERSION_variant_1);
	Rte_Write_NV_Data_IOD_NVM_PD_POWER_MULTIPLIER_100(&NVM_PD_POWER_MULTIPLIER_100_variant_1);
	Rte_Write_NV_Data_IOD_NVM_PD_PRPLWHL_TQ_LOW_LIMIT_100(&NVM_PD_PRPLWHL_TQ_LOW_LIMIT_100_variant_1);
	Rte_Write_NV_Data_IOD_NVM_PD_TORQUE_MAX(&NVM_PD_TORQUE_MAX_variant_1);
	Rte_Write_NV_Data_IOD_NVM_PD_REAR_AXEL_RATIO_100(&NVM_PD_REAR_AXEL_RATIO_100_variant_1);
	Rte_Write_NV_Data_IOD_NVM_PD_WHEEL_RPM_CONVERSION_100(&NVM_PD_WHEEL_RPM_CONVERSION_100_variant_1);
	Rte_Write_NV_Data_IOD_NVM_PD_WHL_TRQ_FILTER_10(&NVM_PD_WHL_TRQ_FILTER_10_variant_1);
	Rte_Write_NV_Data_IOD_Reserved_IOD(&Reserved_IOD_variant_1);
}

void Write_Odometer_variant_1(void)
{
	Rte_Write_NV_Data_Odometer_nvm_odo_data(&nvm_odo_data_variant_1);
	Rte_Write_NV_Data_Odometer_NVM_ODO_Delta_Ref_U32(&NVM_ODO_Delta_Ref_U32_variant_1);
	Rte_Write_NV_Data_Odometer_NVM_ODO_Exceed_Cntr_U16(&NVM_ODO_Exceed_Cntr_U16_variant_1);
	Rte_Write_NV_Data_Odometer_NVM_ODO_Exceed_Value_U32(&NVM_ODO_Exceed_Value_U32_variant_1);
	Rte_Write_NV_Data_Odometer_NVM_PcmOdoTripSync_BOOL(&NVM_PcmOdoTripSync_BOOL_variant_1);
	Rte_Write_NV_Data_Odometer_Reserved_Odo(&Reserved_Odo_variant_1);
}

void Write_TripComputer_variant_1(void)
{
	Rte_Write_NV_Data_TripComputer_NVM_AFE_BIAS_FACTOR_U16(&NVM_AFE_BIAS_FACTOR_U16_variant_1);
	Rte_Write_NV_Data_TripComputer_NVM_TC_CONFIG_BYTE1(&NVM_TC_CONFIG_BYTE1_variant_1);
	Rte_Write_NV_Data_TripComputer_NVM_TC_CONFIG_BYTE4(&NVM_TC_CONFIG_BYTE4_variant_1);
	Rte_Write_NV_Data_TripComputer_trip_nvm_variable(&trip_nvm_variable_variant_1);
	Rte_Write_NV_Data_TripComputer_Reserved_TripComputer(&Reserved_TripComputer_variant_1);
}

void Write_Personalization_variant_1(void)
{
	Rte_Write_NV_Data_Personalization_NVM_McDoNotDisturbStatus_U8(&NVM_McDoNotDisturbStatus_U8_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_Mc911AssistStatus_U8(&NVM_Mc911AssistStatus_U8_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_McVolumeLimitStatus_U8(&NVM_McVolumeLimitStatus_U8_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_McAdvancedTracStatus_U8(&NVM_McAdvancedTracStatus_U8_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_McSpeedLimiterStatus_U8(&NVM_McSpeedLimiterStatus_U8_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_McSpeedWarningStatus_U8(&NVM_McSpeedWarningStatus_U8_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemCurrentPers_U8(&NVM_EnhMemCurrentPers_U8_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemIPCPersRecallCount_U8(&NVM_EnhMemIPCPersRecallCount_U8_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemPrevFEGallon_BOOL(&NVM_EnhMemPrevFEGallon_BOOL_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemPrevAFEMetric_BOOL(&NVM_EnhMemPrevAFEMetric_BOOL_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemPrevLangBundle_U16(&NVM_EnhMemPrevLangBundle_U16_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemDistUnit_U8A(&NVM_EnhMemDistUnit_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemTempUnit_U8A(&NVM_EnhMemTempUnit_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemLangSelect_U8A(&NVM_EnhMemLangSelect_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemVopsProgSts_BOOL(&NVM_EnhMemVopsProgSts_BOOL_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_StoredLanguage_U8(&NVM_StoredLanguage_U8_variant_1);
	Rte_Write_NV_Data_Personalization_nvm_savedmk_startodo_1(&nvm_savedmk_startodo_1_variant_1);
	Rte_Write_NV_Data_Personalization_nvm_savedmk_accumodo_1(&nvm_savedmk_accumodo_1_variant_1);
	Rte_Write_NV_Data_Personalization_nvm_savedmk_startodo_2(&nvm_savedmk_startodo_2_variant_1);
	Rte_Write_NV_Data_Personalization_nvm_savedmk_accumodo_2(&nvm_savedmk_accumodo_2_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemInfochime_U8A(&NVM_EnhMemInfochime_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemparkslotchime_U8A(&NVM_EnhMemparkslotchime_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemTpmsUnit_U8A(&NVM_EnhMemTpmsUnit_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemRpaAdjVolchime_U8A(&NVM_EnhMemRpaAdjVolchime_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemFpaAdjVolchime_U8A(&NVM_EnhMemFpaAdjVolchime_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_BrakeCoachMCStatus_BOOL(&NVM_BrakeCoachMCStatus_BOOL_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemIpc_Configured_BOOL(&NVM_EnhMemIpc_Configured_BOOL_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemMyView_IODigital_Speedo(&NVM_EnhMemMyView_IODigital_Speedo_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemMyView_IOTrip_1(&NVM_EnhMemMyView_IOTrip_1_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemMyView_IOTrip_2(&NVM_EnhMemMyView_IOTrip_2_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemMyView_IODAS(&NVM_EnhMemMyView_IODAS_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemMyView_IODFuelEconomy(&NVM_EnhMemMyView_IODFuelEconomy_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemMyView_IODEco_Coach(&NVM_EnhMemMyView_IODEco_Coach_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemMyView_IODev_Coaching(&NVM_EnhMemMyView_IODev_Coaching_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemMyView_IODCalm(&NVM_EnhMemMyView_IODCalm_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemTurnByTurn_U8A(&NVM_EnhMemTurnByTurn_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemSpeedoGaugeView_U8A(&NVM_EnhMemSpeedoGaugeView_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemTachometer_U8A(&NVM_EnhMemTachometer_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemPowerGauge_U8A(&NVM_EnhMemPowerGauge_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemOilTemp_U8A(&NVM_EnhMemOilTemp_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemLeftGauge_U8A(&NVM_EnhMemLeftGauge_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemRightGauge_U8A(&NVM_EnhMemRightGauge_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemCalmScreenIOD_U8A(&NVM_EnhMemCalmScreenIOD_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemTrip1IOD_U8A(&NVM_EnhMemTrip1IOD_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemTrip2IOD_U8A(&NVM_EnhMemTrip2IOD_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemThisTripIOD_U8A(&NVM_EnhMemThisTripIOD_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemFuelEconomyIOD_U8A(&NVM_EnhMemFuelEconomyIOD_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemElectEffIOD_U8A(&NVM_EnhMemElectEffIOD_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemEcoBehaviorIOD_U8A(&NVM_EnhMemEcoBehaviorIOD_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemEVCoachIOD_U8A(&NVM_EnhMemEVCoachIOD_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemAutoStartStopIOD_U8A(&NVM_EnhMemAutoStartStopIOD_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemSeatbeltStatusIOD_U8A(&NVM_EnhMemSeatbeltStatusIOD_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemTPMSIOD_U8A(&NVM_EnhMemTPMSIOD_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemEcoCoachIOD_U8A(&NVM_EnhMemEcoCoachIOD_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemActiveMediaIOD_U8A(&NVM_EnhMemActiveMediaIOD_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemNavCompassIOD_U8A(&NVM_EnhMemNavCompassIOD_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemAverageSpeedIOD_U8A(&NVM_EnhMemAverageSpeedIOD_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemBatteryChargeIOD_U8A(&NVM_EnhMemBatteryChargeIOD_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemClassicViewIOD_U8A(&NVM_EnhMemClassicViewIOD_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemMapIOD_U8A(&NVM_EnhMemMapIOD_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_TMKClockReference_U32(&NVM_TMKClockReference_U32_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_TMKElapsedTMK_U16(&NVM_TMKElapsedTMK_U16_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_TMKWarningTime_U16(&NVM_TMKWarningTime_U16_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_TMK12HrIncrements_U16(&NVM_TMK12HrIncrements_U16_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_TMKExpirationTime_U16(&NVM_TMKExpirationTime_U16_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemTMK_U8A(&NVM_EnhMemTMK_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_TrailerBlind_U8A(&NVM_TrailerBlind_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemEcoCoachNormalConfig_U8A(&NVM_EnhMemEcoCoachNormalConfig_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemEcoCoachConserveConfig_U8A(&NVM_EnhMemEcoCoachConserveConfig_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemEDMEcoAdvicesConfig_U8A(&NVM_EnhMemEDMEcoAdvicesConfig_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemEcoCoachGoModeConfig_U8A(&NVM_EnhMemEcoCoachGoModeConfig_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhMemEcoCoachEcoModeConfig_U8A(&NVM_EnhMemEcoCoachEcoModeConfig_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhTC1OdometerConfig_U8A(&NVM_EnhTC1OdometerConfig_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhTC2OdometerConfig_U8A(&NVM_EnhTC2OdometerConfig_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhTC1TimerConfig_U8A(&NVM_EnhTC1TimerConfig_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhTC2TimerConfig_U8A(&NVM_EnhTC2TimerConfig_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhTC1ASConfig_U8A(&NVM_EnhTC1ASConfig_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhTC2ASConfig_U8A1(&NVM_EnhTC2ASConfig_U8A1_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhTC1AFEConfig_U8A(&NVM_EnhTC1AFEConfig_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhTC2AFEConfig_U8A(&NVM_EnhTC2AFEConfig_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhTC1IFEConfig_U8A(&NVM_EnhTC1IFEConfig_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhTC2IFEConfig_U8A(&NVM_EnhTC2IFEConfig_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhTC1DTEConfig_U8A(&NVM_EnhTC1DTEConfig_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhTC2DTEConfig_U8A(&NVM_EnhTC2DTEConfig_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhTC1AEConfig_U8A(&NVM_EnhTC1AEConfig_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_NVM_EnhTC2AEConfig_U8A(&NVM_EnhTC2AEConfig_U8A_variant_1);
	Rte_Write_NV_Data_Personalization_Reserved_Personalization(&Reserved_Personalization_variant_1);
}

void Write_Health_Management_variant_1(void)
{
	Rte_Write_NV_Data_Health_Management_NVM_HM_dummy(&NVM_HM_dummy_variant_1);
	Rte_Write_NV_Data_Health_Management_NVM_HM_Ign_Counter(&NVM_HM_Ign_Counter_variant_1);
	Rte_Write_NV_Data_Health_Management_NVM_HM_Reset_Counter(&NVM_HM_Reset_Counter_variant_1);
	Rte_Write_NV_Data_Health_Management_Reserved_Health_Management(&Reserved_Health_Management_variant_1);
}

void Write_Health_Management2_variant_1(void)
{
	Rte_Write_NV_Data_Health_Management2_NVM_HM_Data_Illegal_Mem_Addrs_Reset_Counter(&NVM_HM_Data_Illegal_Mem_Addrs_Reset_Counter_variant_1);
	Rte_Write_NV_Data_Health_Management2_NVM_HM_Data_Range_Failure_Reset_Counter(&NVM_HM_Data_Range_Failure_Reset_Counter_variant_1);
	Rte_Write_NV_Data_Health_Management2_NVM_HM_DivbyZero_Excptn_Reset_Counter(&NVM_HM_DivbyZero_Excptn_Reset_Counter_variant_1);
	Rte_Write_NV_Data_Health_Management2_NVM_HM_ECU_Ign_UpTime(&NVM_HM_ECU_Ign_UpTime_variant_1);
	Rte_Write_NV_Data_Health_Management2_NVM_HM_ECU_Intrnl_Temp(&NVM_HM_ECU_Intrnl_Temp_variant_1);
	Rte_Write_NV_Data_Health_Management2_NVM_HM_Extrnl_Bus_Msg_Fault_Counter(&NVM_HM_Extrnl_Bus_Msg_Fault_Counter_variant_1);
	Rte_Write_NV_Data_Health_Management2_NVM_HM_Failure_Code(&NVM_HM_Failure_Code_variant_1);
	Rte_Write_NV_Data_Health_Management2_NVM_HM_Flash_Checksum_Fault_Counter(&NVM_HM_Flash_Checksum_Fault_Counter_variant_1);
	Rte_Write_NV_Data_Health_Management2_NVM_HM_Illegal_Opcode_Reset_Counter(&NVM_HM_Illegal_Opcode_Reset_Counter_variant_1);
	Rte_Write_NV_Data_Health_Management2_NVM_HM_Intrnl_Bus_Msg_Fault_Counter(&NVM_HM_Intrnl_Bus_Msg_Fault_Counter_variant_1);
	Rte_Write_NV_Data_Health_Management2_NVM_HM_MainECU_Voltage(&NVM_HM_MainECU_Voltage_variant_1);
	Rte_Write_NV_Data_Health_Management2_NVM_HM_NVM_Checksum_Fault_Counter(&NVM_HM_NVM_Checksum_Fault_Counter_variant_1);
	Rte_Write_NV_Data_Health_Management2_NVM_HM_Peripheral_Fault_Counter(&NVM_HM_Peripheral_Fault_Counter_variant_1);
	Rte_Write_NV_Data_Health_Management2_NVM_HM_Power_ON_Reset_Counter(&NVM_HM_Power_ON_Reset_Counter_variant_1);
	Rte_Write_NV_Data_Health_Management2_NVM_HM_RAM_Checksum_Fault_Counter(&NVM_HM_RAM_Checksum_Fault_Counter_variant_1);
	Rte_Write_NV_Data_Health_Management2_NVM_HM_Reset_Reason_Detected_counter(&NVM_HM_Reset_Reason_Detected_counter_variant_1);
	Rte_Write_NV_Data_Health_Management2_NVM_HM_Sensor_Failure_Counter(&NVM_HM_Sensor_Failure_Counter_variant_1);
	Rte_Write_NV_Data_Health_Management2_NVM_HM_Stack_Ovrflw_Reset_Counter(&NVM_HM_Stack_Ovrflw_Reset_Counter_variant_1);
	Rte_Write_NV_Data_Health_Management2_NVM_HM_WDT_Reset_Counter(&NVM_HM_WDT_Reset_Counter_variant_1);
	Rte_Write_NV_Data_Health_Management2_HM_Latest_Resets(&HM_Latest_Resets_variant_1);
	Rte_Write_NV_Data_Health_Management2_HM_Forced_Reset_Counter(&HM_Forced_Reset_Counter_variant_1);
	Rte_Write_NV_Data_Health_Management2_HM_Ignition_Counter(&HM_Ignition_Counter_variant_1);
	Rte_Write_NV_Data_Health_Management2_HM_TempSensorFault_Counters(&HM_TempSensorFault_Counters_variant_1);
	Rte_Write_NV_Data_Health_Management2_Reserved_HM2(&Reserved_HM2_variant_1);
}

void Write_Cybersecurity_variant_1(void)
{
	Rte_Write_NV_Data_Cybersecurity_SPID_Data_U8(&SPID_Data_U8_variant_1);
	Rte_Write_NV_Data_Cybersecurity_FESN_Data_U8(&FESN_Data_U8_variant_1);
	Rte_Write_NV_Data_Cybersecurity_TimerTimeOut(&TimerTimeOut_variant_1);
	Rte_Write_NV_Data_Cybersecurity_Reserved_Cybersecurity(&Reserved_Cybersecurity_variant_1);
}

void Write_GaugeFuel_variant_1(void)
{
	Rte_Write_NV_Data_GaugeFuel_CorrectionTableX_Gauge_Fuel(&CorrectionTableX_Gauge_Fuel_variant_1);
	Rte_Write_NV_Data_GaugeFuel_CorrectionTableY_Gauge_Fuel(&CorrectionTableY_Gauge_Fuel_variant_1);
	Rte_Write_NV_Data_GaugeFuel_MagneticOffset_Gauge_Fuel(&MagneticOffset_Gauge_Fuel_variant_1);
	Rte_Write_NV_Data_GaugeFuel_OverdriveOffset_Gauge_Fuel(&OverdriveOffset_Gauge_Fuel_variant_1);
	Rte_Write_NV_Data_GaugeFuel_HysteresisDir_Gauge_Fuel(&HysteresisDir_Gauge_Fuel_variant_1);
	Rte_Write_NV_Data_GaugeFuel_HysteresisAngle_Gauge_Fuel(&HysteresisAngle_Gauge_Fuel_variant_1);
	Rte_Write_NV_Data_GaugeFuel_ZeroSW_Gauge_Fuel(&ZeroSW_Gauge_Fuel_variant_1);
	Rte_Write_NV_Data_GaugeFuel_SleepOffset_Gauge_Fuel(&SleepOffset_Gauge_Fuel_variant_1);
	Rte_Write_NV_Data_GaugeFuel_Reserved_GaugeFuel(&Reserved_GaugeFuel_variant_1);
}

void Write_FOTA_Signature_variant_1(void)
{
	Rte_Write_NV_Data_FOTA_Signature_FOTA_Signature(&FOTA_Signature_variant_1);
}

void Write_vSwUpdM_Appl_UpdateState_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_UpdateState_NvM_vSwUpdM_Appl_UpdateState(&NvM_vSwUpdM_Appl_UpdateState_variant_1);
}

void Write_vSwUpdM_Appl_PartitionStates_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_PartitionStates_NvM_vSwUpdM_Appl_PartitionStates(&NvM_vSwUpdM_Appl_PartitionStates_variant_1);
}

void Write_vSwUpdM_Appl_PartitionValidities_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_PartitionValidities_NvM_vSwUpdM_Appl_PartitionValidities(&NvM_vSwUpdM_Appl_PartitionValidities_variant_1);
}

void Write_vSwUpdM_Appl_PartitionRevisions_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_PartitionRevisions_NvM_vSwUpdM_Appl_PartitionRevisions(&NvM_vSwUpdM_Appl_PartitionRevisions_variant_1);
}

void Write_vSwUpdM_Appl_ModuleStates_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_ModuleStates_NvM_vSwUpdM_Appl_ModuleStates(&NvM_vSwUpdM_Appl_ModuleStates_variant_1);
}

void Write_vSwUpdM_Appl_ModuleValidities_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_ModuleValidities_NvM_vSwUpdM_Appl_ModuleValidities(&NvM_vSwUpdM_Appl_ModuleValidities_variant_1);
}

void Write_vSwUpdM_Appl_ModuleRevisions_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_ModuleRevisions_NvM_vSwUpdM_Appl_ModuleRevisions(&NvM_vSwUpdM_Appl_ModuleRevisions_variant_1);
}

void Write_vSwUpdM_Appl_RegionStates_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_RegionStates_NvM_vSwUpdM_Appl_RegionStates(&NvM_vSwUpdM_Appl_RegionStates_variant_1);
}

void Write_vSwUpdM_Appl_RegionEraseAddresses_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_RegionEraseAddresses_NvM_vSwUpdM_Appl_RegionEraseAddresses(&NvM_vSwUpdM_Appl_RegionEraseAddresses_variant_1);
}

void Write_vSwUpdM_Appl_SegmentAttributes_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_SegmentAttributes_NvM_vSwUpdM_Appl_SegmentAttributes(&NvM_vSwUpdM_Appl_SegmentAttributes_variant_1);
}

void Write_vSwUpdM_Appl_SegmentWriteAddresses_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_SegmentWriteAddresses_NvM_vSwUpdM_Appl_SegmentWriteAddresses(&NvM_vSwUpdM_Appl_SegmentWriteAddresses_variant_1);
}

void Write_vSwUpdM_Appl_SegmentCount_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_SegmentCount_NvM_vSwUpdM_Appl_SegmentCount(&NvM_vSwUpdM_Appl_SegmentCount_variant_1);
}

void Write_vSwUpdM_Appl_ResumeInfo_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_ResumeInfo_NvM_vSwUpdM_Appl_ResumeInfo(&NvM_vSwUpdM_Appl_ResumeInfo_variant_1);
}

void Write_vSwUpdM_Appl_RegionPartitionId_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_RegionPartitionId_NvM_vSwUpdM_Appl_RegionPartitionId(&NvM_vSwUpdM_Appl_RegionPartitionId_variant_1);
}

void Write_vSwUpdM_Appl_SegmentPartitionId_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_SegmentPartitionId_NvM_vSwUpdM_Appl_SegmentPartitionId(&NvM_vSwUpdM_Appl_SegmentPartitionId_variant_1);
}

void Write_vSwUpdM_Appl_DiffModuleStates_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_DiffModuleStates_NvM_vSwUpdM_Appl_DiffModuleStates(&NvM_vSwUpdM_Appl_DiffModuleStates_variant_1);
}

void Write_vSwUpdM_Appl_DiffModuleValidities_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_DiffModuleValidities_NvM_vSwUpdM_Appl_DiffModuleValidities(&NvM_vSwUpdM_Appl_DiffModuleValidities_variant_1);
}

void Write_vSwUpdM_Appl_DiffRegionStates_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_DiffRegionStates_NvM_vSwUpdM_Appl_DiffRegionStates(&NvM_vSwUpdM_Appl_DiffRegionStates_variant_1);
}

void Write_vSwUpdM_Appl_DiffRegionEraseAddresses_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_DiffRegionEraseAddresses_NvM_vSwUpdM_Appl_DiffRegionEraseAddresses(&NvM_vSwUpdM_Appl_DiffRegionEraseAddresses_variant_1);
}

void Write_vSwUpdM_Appl_DiffSegmentAttributes_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_DiffSegmentAttributes_NvM_vSwUpdM_Appl_DiffSegmentAttributes(&NvM_vSwUpdM_Appl_DiffSegmentAttributes_variant_1);
}

void Write_vSwUpdM_Appl_DiffSegmentWriteAddresses_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_DiffSegmentWriteAddresses_NvM_vSwUpdM_Appl_DiffSegmentWriteAddresses(&NvM_vSwUpdM_Appl_DiffSegmentWriteAddresses_variant_1);
}

void Write_vSwUpdM_Appl_DiffSegmentCount_variant_1(void)
{
	Rte_Write_NV_Data_vSwUpdM_Appl_DiffSegmentCount_NvM_vSwUpdM_Appl_DiffSegmentCount(&NvM_vSwUpdM_Appl_DiffSegmentCount_variant_1);
}

void Write_CddOsoh_NvMData_variant_1(void)
{
	Rte_Write_NV_Data_CddOsoh_NvMData_CddOsoh_NvMData(&CddOsoh_NvMData_variant_1);
}

void Write_CddOsph_CddOsphChannel_00_variant_1(void)
{
	Rte_Write_NV_Data_CddOsph_CddOsphChannel_00_CddOsphChannel_00_MessageState(&CddOsphChannel_00_MessageState_variant_1);
	Rte_Write_NV_Data_CddOsph_CddOsphChannel_00_CddOsphChannel_00_ChannelState(&CddOsphChannel_00_ChannelState_variant_1);
}

void Write_CddOsph_CddOsphChannel_01_variant_1(void)
{
	Rte_Write_NV_Data_CddOsph_CddOsphChannel_01_CddOsphChannel_01_MessageState(&CddOsphChannel_01_MessageState_variant_1);
	Rte_Write_NV_Data_CddOsph_CddOsphChannel_01_CddOsphChannel_01_ChannelState(&CddOsphChannel_01_ChannelState_variant_1);
}

void Calc_BlockLength(void)
{
	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_Magic_Flag));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_FBL_Validity_Flag));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_FBL_Switch_RoleBackFlag));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_FBL_OTA_Magic_Flag));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_FBL_FOTA_Status));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_Chimes));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_Config));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_Diagnostics));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_EOL));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_FuelGauge));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_Illumination));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_IOD));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_TripComputer));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_Personalization));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_Health_Management2));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_Cybersecurity));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeFuel));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_FOTA_Signature));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_UpdateState));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_PartitionStates));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_PartitionValidities));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_PartitionRevisions));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_ModuleStates));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_ModuleValidities));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_ModuleRevisions));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_RegionStates));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_RegionEraseAddresses));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_SegmentAttributes));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_SegmentWriteAddresses));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_SegmentCount));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_ResumeInfo));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_RegionPartitionId));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_SegmentPartitionId));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffModuleStates));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffModuleValidities));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffRegionStates));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffRegionEraseAddresses));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffSegmentAttributes));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffSegmentWriteAddresses));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_vSwUpdM_Appl_DiffSegmentCount));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_CddOsoh_NvMData));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_CddOsph_CddOsphChannel_00));

	BlockLengthCalc_Add(sizeof(Rte_NvBlockSwComponentType_NVBlockDescriptor_CddOsph_CddOsphChannel_01));

}

void init_main(){
	NvM_Init();
	MEM1_Init();
	MEM_Init(NULL);

	Write_Magic_Flag_variant_1();
	Write_FBL_Validity_Flag_variant_1();
	Write_FBL_Switch_RoleBackFlag_variant_1();
	Write_FBL_OTA_Magic_Flag_variant_1();
	Write_FBL_FOTA_Status_variant_1();
	Write_Chimes_variant_1();
	Write_Config_variant_1();
	Write_Diagnostics_variant_1();
	Write_EOL_variant_1();
	Write_FuelGauge_variant_1();
	Write_Illumination_variant_1();
	Write_IOD_variant_1();
	Write_Odometer_variant_1();
	Write_TripComputer_variant_1();
	Write_Personalization_variant_1();
	Write_Health_Management_variant_1();
	Write_Health_Management2_variant_1();
	Write_Cybersecurity_variant_1();
	Write_GaugeFuel_variant_1();
	Write_FOTA_Signature_variant_1();
	Write_vSwUpdM_Appl_UpdateState_variant_1();
	Write_vSwUpdM_Appl_PartitionStates_variant_1();
	Write_vSwUpdM_Appl_PartitionValidities_variant_1();
	Write_vSwUpdM_Appl_PartitionRevisions_variant_1();
	Write_vSwUpdM_Appl_ModuleStates_variant_1();
	Write_vSwUpdM_Appl_ModuleValidities_variant_1();
	Write_vSwUpdM_Appl_ModuleRevisions_variant_1();
	Write_vSwUpdM_Appl_RegionStates_variant_1();
	Write_vSwUpdM_Appl_RegionEraseAddresses_variant_1();
	Write_vSwUpdM_Appl_SegmentAttributes_variant_1();
	Write_vSwUpdM_Appl_SegmentWriteAddresses_variant_1();
	Write_vSwUpdM_Appl_SegmentCount_variant_1();
	Write_vSwUpdM_Appl_ResumeInfo_variant_1();
	Write_vSwUpdM_Appl_RegionPartitionId_variant_1();
	Write_vSwUpdM_Appl_SegmentPartitionId_variant_1();
	Write_vSwUpdM_Appl_DiffModuleStates_variant_1();
	Write_vSwUpdM_Appl_DiffModuleValidities_variant_1();
	Write_vSwUpdM_Appl_DiffRegionStates_variant_1();
	Write_vSwUpdM_Appl_DiffRegionEraseAddresses_variant_1();
	Write_vSwUpdM_Appl_DiffSegmentAttributes_variant_1();
	Write_vSwUpdM_Appl_DiffSegmentWriteAddresses_variant_1();
	Write_vSwUpdM_Appl_DiffSegmentCount_variant_1();
	Write_CddOsoh_NvMData_variant_1();
	Write_CddOsph_CddOsphChannel_00_variant_1();
	Write_CddOsph_CddOsphChannel_01_variant_1();
	NvmW_Write(47);

srec_main(0);

}
static void NvmW_Write(uint32 BlockId)
{
	for(int i=2; i<BlockId; i++)	{
			uint8 result=0u;
			NvM_WriteBlock(i, NULL);
			do
		{
				NvM_MainFunction();
				MEM1_MainFunction();
				MEM_MainFunction();
				NvM_GetErrorStatus(i,&result);
		}while(result==2);
	}
}

static void Gen_MemCpy(uint8* dest, uint8* src, uint32 len)
{
	uint32 i;
	for(i=0; i<len;i++)
	{
		dest[i]=src[i];
	}
}

